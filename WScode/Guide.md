NXP i.MX RT700 워치 애플리케이션 개발 가이드라인

1. 개요 (Overview)

본 문서는 NXP i.MX RT700 기반의 워치 애플리케이션 개발을 위한 프로젝트 구조, 협업 프로세스 및 아키텍처 원칙을 정의합니다.
GUI Guider가 자동 생성하는 코드와 개발자가 작성하는 비즈니스 로직을 철저히 분리하여, 유지보수성을 높이고 Git 충돌을 최소화하는 것을 목표로 합니다.

📌 핵심 원칙

충돌 방지 (No Conflict): generated/ 폴더와 custom//source/ 폴더를 엄격히 분리합니다.

계층형 아키텍처 (Layered Arch): UI, Logic, HAL, Hardware 계층을 명확히 구분합니다.

Headless 검증 (Test-First): UI 없이 하드웨어 드라이버를 먼저 검증할 수 있는 환경을 구축합니다.

2. 폴더 구조 및 역할 (Directory Structure)

프로젝트는 Generated(자동 생성) 영역과 User Code(개발자 작성) 영역으로 엄격히 구분됩니다.

RT700_watch_project/
├── generated/          # [수정 금지] GUI Guider 자동 생성 파일 (UI Layout, Assets)
│                       # ⚠️ 경고: 이곳의 파일을 수정하면 다음 코드 생성 시 덮어씌워집니다.
├── custom/             # [UI 연결] UI 이벤트 콜백 및 "Glue Code"
│                       # generated와 source 사이의 다리 역할을 합니다.
├── source/             # [핵심 로직] 애플리케이션 비즈니스 로직 및 Main Entry
│   ├── app/            # 워치 앱 기능 구현 (WatchFace, Pedometer, Notification 등)
│   ├── hal/            # [공유] 하드웨어 추상화 계층 (Sensor, PMIC, BLE wrapper)
│   ├── model/          # 데이터 구조체 및 상태 관리 (Data Model)
│   ├── test/           # [검증] UI 없는 하드웨어 단위 테스트 코드 (Headless Test)
│   └── main.c          # FreeRTOS Task 초기화 및 스케줄러 시작
├── board/              # [HW 설정] Pin Mux, Clock, Peripherals (Config Tools 생성)
├── sdk/                # NXP MCUXpresso SDK (수정 금지)
└── doc/                # 프로젝트 문서 및 설계도


3. 소프트웨어 아키텍처 (Architecture)

3.1 RTOS Task 설계

반응성을 보장하기 위해 각 태스크의 우선순위를 엄격하게 관리합니다.

Task Name

Priority

역할 및 특징

Input Task

High (5)

터치스크린, 물리 버튼 입력 감지 및 시스템 이벤트 발신

Logic Task

Low/High (4)

센서 데이터 처리, 비즈니스 로직 수행

GUI Task

Mid (3)

LVGL 렌더링 루프 (lv_task_handler), VGLite(GPU) 가속 연동

3.2 메모리 배치 전략 (Memory Map)

RT700의 이기종 메모리 구조를 활용하여 성능을 최적화합니다.

Internal SRAM (30%): Frame Buffer (빠른 화면 갱신을 위해 필수)

External Flash (60%): UI Assets (이미지, 폰트 등 대용량 데이터)

ITCM / Flash (10%): Code (성능이 중요한 코드는 ITCM 복사)

3.3 계층 간 데이터 흐름

[데이터 흐름 규칙]: 상위 계층은 하위 계층을 호출할 수 있지만, 역방향 호출은 금지됩니다.

Presentation (UI): generated/ (View) ↔ custom/ (Controller)

Application (Logic): source/app/ (Logic) ↔ source/model/ (Data)

Abstraction (HAL): source/hal/ (Hardware Interface)

Hardware (BSP): board/, sdk/

4. R&R 및 개발 워크플로우

🎨 UI 개발자 (GUI Designer)

Primary Tool: NXP GUI Guider

역할: 화면 배치, 위젯 속성 정의, 인터랙션 설계.

작업 수칙:

이벤트 발생 시 로직 코드를 툴 안에 직접 작성하지 않습니다.

반드시 Custom 함수 호출(OnMainBtnClicked())만 설정합니다.

생성된 코드를 generated/ 폴더에 커밋합니다.

💻 로직 개발자 (Firmware Engineer)

Primary Tool: Visual Studio Code (or MCUXpresso IDE)

역할: 기능 구현, 데이터 처리, 하드웨어 제어.

작업 수칙:

custom/custom.c에서 UI 콜백 함수를 구현합니다.

source/app/ 내부에 비즈니스 로직을 작성합니다.

Thread-Safe: UI 갱신 시 반드시 Message Queue 등을 사용하여 GUI Task로 데이터를 전달합니다.

🧪 시뮬레이션 전략 (HAL Mocking)

PC 시뮬레이터와 타겟 보드 간의 하드웨어 차이를 극복하기 위해 HAL Mocking을 사용합니다.

PC 시뮬레이터: HAL_Sensor_Read()가 가짜(Mock) 데이터를 반환.

타겟 하드웨어: HAL_Sensor_Read()가 실제 레지스터(I2C 등)를 읽음.

[코드 예시: source/hal/hal_sensor.c]

float HAL_Sensor_ReadHeartRate(void) {
    #ifdef SIMULATOR
        // [PC] 랜덤 값 반환 (Mocking)
        return 70 + (rand() % 20);
    #else
        // [Target] 실제 하드웨어 제어
        return I2C_Read_HRM_Sensor();
    #endif
}


🔄 Git 형상 관리 및 충돌 해결

generated/ 폴더에서 충돌(Conflict)이 발생할 경우, 절대 텍스트 에디터로 수정하지 마십시오.

동료의 최신 .guider 프로젝트 파일을 Pull 받습니다.

GUI Guider 툴을 열고 프로젝트를 로드합니다.

"Generate Code" 버튼을 눌러 파일을 덮어씌웁니다 (재생성).

변경된 내용을 커밋합니다.

5. Headless 검증 모드 (Test-First)

UI 개발이 완료되기 전에 하드웨어 드라이버를 검증하기 위한 모드입니다.

구현 방법

main.c의 #define HEADLESS_TEST 매크로를 통해 모드를 전환합니다.

[코드 예시: source/main.c]

// #define HEADLESS_TEST  // 이 줄을 주석 해제하면 테스트 모드 진입

void main(void) {
    BOARD_Init();
    
    #ifdef HEADLESS_TEST
        // UI 초기화 건너뛰고 테스트 태스크 실행 (UART로 결과 출력)
        xTaskCreate(Test_Task, "Test_Task", ...);
    #else
        // 정상적인 UI 애플리케이션 실행
        App_CreateGuiTask();
        App_CreateLogicTask();
    #endif

    vTaskStartScheduler();
}


Document Version: 1.3