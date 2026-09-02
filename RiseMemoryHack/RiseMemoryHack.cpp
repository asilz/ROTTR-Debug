#include <Windows.h>
#include <stdio.h>
#include <inttypes.h>
#include <atomic>
#include <string>
#include <string_view>
#include <vector>
#include "Gui.h"
#include "imgui.h"

struct InstanceHandle {
    unsigned long long m_instanceComponentID;
};

struct PlacementHashKey {
    unsigned long long m_keyValue;
};

struct PlacementPath {
    uint64_t data[0x4];
};

struct CullingPolytope {
    uint64_t data[0x9];
};

struct BasicCullingVolume {
    uint32_t data[0x18];
};

struct Vector {
    float a[4];
};

struct DrawableInfo {
    uint32_t data[0x28];
};

struct Scalar {
    float a[4];
};

struct Vector2 {
    float x;
    float y;
    float z;
    float w;
};

struct Vector3 {
    float x;
    float y;
    float z;
    float w;
};

struct Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct SceneEntity;
struct SceneLight;

template <typename T>
struct Smoother {
    T m_startValue;
    T m_targetValue;
    int m_easeType;
    float m_t;
    float m_duration;
    float m_durationRcp;
    bool m_wasResetBeforeUpdate;
};

template <typename Key, typename Value> 
struct HashMap {
    uint64_t data[0x5];
};

template <typename T>
struct Array {
    unsigned int size;
    unsigned int capacity;
    T* data;
};



template <typename T>
struct AllocationT {
    T* m_pBuffer;
    unsigned int m_capacity;
    unsigned int m_size;
};

template <typename T>
struct CullingArray {
    AllocationT<T> m_allocation;
};

template <typename T>
struct AtomicTransientArray {
    CullingArray<T>* m_threadLocalArrays;
    unsigned int m_size;
};

struct CullingPlane {
    Vector4 m_planeEq;
};

struct OcclusionTree {
    uint64_t data[0x18];
};

struct TransientHeapAllocator {
    uint64_t data[0x9];
};

struct SceneGlobalJobState {
    uint64_t data[0xe];
};

struct CullingFrustum {
    struct Vector3 m_eye;
    struct CullingAllocator* m_pAlloc;
    bool m_perspective;
    struct CullingArray<CullingPlane> m_planes;
    struct CullingArray<Vector3> m_vertices;
};



struct Color {
    struct Vector4 m_rgba;
};

struct Quat {
    float x;
    float y;
    float z;
    float w;
};

struct Matrix {
    Vector4 col[4];
};

struct GraphicsOverrideSet {
    uint64_t data[513];
};

struct NonLinearHeightFogData {
    uint64_t data[71];
};

struct RenderViewport {
    uint32_t data[88];
};

struct SubFrameRect {
    float x;
    float y;
    float width;
    float height;
};

struct CameraDepthOfField {
    struct InstanceHandle targetInstance;
    int targetSegmentID;
    float targetDistance;
    float nearBlurStrength;
    float nearBlurDistance;
    float nearDepthOfField;
    float farBlurStrength;
    float farBlurDistance;
    float farDepthOfField;
    float fadeWeight;
};

struct ViewPlanes {
    struct Vector4 viewPlanes[5];
};

struct CameraBlurVignette {
    float innerRadius;
    float outerRadius;
    float strength;
    float fadeWeight;
};

struct CameraColorVignette {
    struct Color innerColor;
    struct Color outerColor;
    struct Vector2 centerPoint;
    float innerRadius;
    float outerRadius;
    float fadeWeight;
    char field6_0x3c;
    char field7_0x3d;
    char field8_0x3e;
    char field9_0x3f;
};

struct Camera {
    struct Matrix transform;
    struct Matrix invTransform;
    struct Vector3 position;
    struct Vector3 orientationOffset;
    struct Quat orientation;
    float fov;
    float dist;
    float aspect;
    float lagZ;
    struct ViewPlanes viewPlanes;
    bool firstTimeThrough;
    bool wasCutDetectedDuringLastProcess;
    struct CameraDepthOfField depthOfField;
    struct CameraBlurVignette blurVignette;
    long long _padding_;
    struct CameraColorVignette colorVignette;
};

struct Screen {
    struct RenderViewport vp;
    struct SubFrameRect rect;
    float aspectRatioBias;
    float fovBias;
    float aperature;
    char field5_0x17c;
    char field6_0x17d;
    char field7_0x17e;
    char field8_0x17f;
    struct Vector3 ambientColor;
    struct Vector3 secondAmbientColor;
    struct Vector3 irradianceCoefficients[10];
    struct Vector3 rimColor;
    struct Vector4 rimDistances;
    struct Vector4 rimPowerVals;
    char fog[0x18]; // struct RenderFogParams fog;
    struct NonLinearHeightFogData nlhFog;
    float nlhDistFogUnusedWeight;
    float nlhHeightFogUnusedWeight;
    bool active;
    bool enableScreenShake;
    char field21_0x4ca;
    char field22_0x4cb;
    char field23_0x4cc;
    char field24_0x4cd;
    char field25_0x4ce;
    char field26_0x4cf;
    struct Camera camera;
    struct CameraComponent* cameraComponent;
    struct CameraShake* screenShake;
    struct ScreenRenderMgr* screenRenderMgr;
    char field31_0x688;
    char field32_0x689;
    char field33_0x68a;
    char field34_0x68b;
    char field35_0x68c;
    char field36_0x68d;
    char field37_0x68e;
    char field38_0x68f;
    struct Matrix lastProjectionMatrix;
    struct GraphicsOverrideSet graphicsOverrides;
    char field41_0x16d8;
    char field42_0x16d9;
    char field43_0x16da;
    char field44_0x16db;
    char field45_0x16dc;
    char field46_0x16dd;
    char field47_0x16de;
    char field48_0x16df;
};

typedef enum ScreenID {
    kScreen_FullScreen = 0,
    kScreen_2x2_UpperLeft = 1,
    kScreen_2x2_UpperRight = 2,
    kScreen_2x2_LowerLeft = 3,
    kScreen_2x2_LowerRight = 4,
    kScreen_1x2_Left = 5,
    kScreen_1x2_Right = 6,
    kScreen_2x1_Top = 7,
    kScreen_2x1_Bottom = 8,
    kScreen_Total = 9,
    kScreen_Invalid = 10,
    kScreen_Current = 4294967295
} ScreenID;

struct CamTransitionParams {
    int transitionParamType;
    float fTransitionTime;
    float fTransitionAngVel;
    float fTransitionDistVel;
    int easeType;
    int panSyncType;
    int tiltSyncType;
    bool matchEffects : 1;
    float fCutThreshold_PanRad;
    float fCutThreshold_TiltRad;
    float fCutThreshold_DistanceSq;
    float fCustomPanRad;
    float fCustomTiltRad;
};

struct CameraStackElement {
    uint32_t smoother[7];
    bool m_contributingToBlend;
    bool m_deleteControllerWhenDone;
    char field3_0x1e;
    char field4_0x1f;
    struct ICameraController* m_controller;
    char field6_0x28;
    char field7_0x29;
    char field8_0x2a;
    char field9_0x2b;
    char field10_0x2c;
    char field11_0x2d;
    char field12_0x2e;
    char field13_0x2f;
    struct Camera m_camera;
    int m_resourceID;
    bool m_simulate;
    char field17_0x1d5;
    char field18_0x1d6;
    char field19_0x1d7;
    char field20_0x1d8;
    char field21_0x1d9;
    char field22_0x1da;
    char field23_0x1db;
    char field24_0x1dc;
    char field25_0x1dd;
    char field26_0x1de;
    char field27_0x1df;
};

struct CameraStack {
    long long _padding_0;
    long long _padding_1;
    int goingTo;
    bool m_bInstantCameraChangeDetectedThisFrame;
};

typedef enum EnumAllowClimbCamScriptingFromSC {
    kAllowed = 0,
    kAllowed_Unchanged = 1,
    kDenied = 2,
    kDenied_Unchanged = 3
} EnumAllowClimbCamScriptingFromSC;

struct CameraShakeScale {
    uint32_t val[3];
};

struct SCCameraSuggestion {
    struct CameraShakeScale shakeScale;
    unsigned int resourceID;
    unsigned int shakeID;
    float time;
    signed char easeType;
    float activationDelay;
    float shakeDelay;
    bool doChooseClosestResourceWithCollision;
    bool doChooseClosestResourceWithoutCollision;
    int chooseClosestResourceSegmentIndex;
    unsigned int resourceID_option1_chooseClosest;
    unsigned int resourceID_option2_chooseClosest;
    unsigned int resourceID_option3_chooseClosest;
    unsigned int resourceID_option4_chooseClosest;
    float outTime;
    int outEaseType;
    signed char outSyncTypeYaw;
    signed char outSyncTypePitch;
    signed char outPauseOtherCameraProcessing;
    signed char syncTypeYaw;
    signed char syncTypePitch;
    bool syncEffects : 1;
    bool matchDefaultStackDolly : 1;
    bool matchDefaultStackTruckHoriz : 1;
    bool pauseOtherCameraProcessing : 1;
    bool override :1;
    bool isParent : 1;
    enum EnumAllowClimbCamScriptingFromSC allowClimbSplineCamScripting;
};

struct SCDelayedActivation {
    unsigned int resourceID;
    float time;
    int easeType;
    signed char syncTypeYaw;
    signed char syncTypePitch;
    bool syncEffects : 1;
    bool matchDefaultStackDolly : 1;
    bool matchDefaultStackTruckHoriz : 1;
    bool pauseOtherCameraProcessing : 1;
};

struct CameraComponent {
    long long _padding_0;
    long long _padding_1;
    long long _padding_2;
    long long _padding_3;
    struct Camera m_renderCamera;
    struct Camera m_camera;
    struct Camera m_oldCamera;
    struct Camera m_overrideRenderCamera;
    struct Camera m_overrideCamera;
    struct Camera m_oldOverrideCamera;
    float m_overrideBlendValue;
    float m_oldOverrideBlendValue;
    struct CameraShake* m_pCameraShake;
    unsigned int m_scCameraShakeID;
    int m_scCameraShakeIndex;
    float m_componentBlendWeight;
    bool m_isActive;
    unsigned long long m_instanceID;
    long long _padding_4;
    struct ViewPlanes m_viewPlanes;
    int m_screenID;
    struct CameraComponent* m_dtpComponent;
    struct CameraComponent* m_dtpDefault;
    bool m_ownInputController;
    struct Controller* m_inputController;
    long long _padding_5;
    struct CameraStackElement m_baseCameraElement;
    struct CameraStack m_defaultCameraStack;
    struct CameraStack m_stateControlStack;
    struct CameraStack m_combatStack;
    struct CameraStack m_overrideStack;
    struct CameraStack m_cineStack;
    struct CameraStack m_debugStack;
    int m_stateControlStack_specialOverridenCameraID;
    struct SCCameraSuggestion m_SavedSCSuggestion;
    enum EnumAllowClimbCamScriptingFromSC m_allowClimbSplineCamScripting;
    int m_SCDebounceCounter;
    bool m_activationDelayed;
    float m_activationDelay;
    struct SCDelayedActivation m_delayedObject;
    bool m_handleTeleport;
    bool m_isOverrideActive;
    bool m_isCineOverrideActive;
    bool m_isCineOrBoneCamOverrideActive;
    bool m_isStateControlStackBlockedByMarkup;
    bool m_componentBlockInputPitch;
    bool m_componentBlockInputYaw;
    bool m_componentBlockInputPan;
    bool m_componentBlockInputTilt;
    bool m_bContinueInterruptedOrbitPitch;
    float m_fContinueInterruptedOrbitPitchTarget;
    float m_fContinueInterruptedOrbitPitchTime;
    int m_nContinueInterruptedOrbitPitchEaseType;
    bool m_bContinueInterruptedOrbitYaw;
    float m_fContinueInterruptedOrbitYawTarget;
    float m_fContinueInterruptedOrbitYawTime;
    int m_nContinueInterruptedOrbitYawEaseType;
    struct ICameraController* m_pDelayedResetCineController;
    struct CamTransitionParams m_DelayedResetCineControllerTrans_Params;
    bool m_bHasDelayedCombatControllerTrans;
    bool m_DelayedCombatControllerTrans_OutgoingPauseSimulation;
    struct CamTransitionParams m_DelayedCombatControllerTrans_Params;
    unsigned int m_DelayedCombatControllerTrans_CameraID;
    long long _padding_6;
    struct Vector3 m_DelayedCombatControllerTrans_FocusPos;
    bool m_bHasDelayedOverrideControllerTrans;
    struct CamTransitionParams m_DelayedOverrideControllerTrans_Params;
    unsigned int m_DelayedOverrideControllerTrans_CameraID;
    bool m_bDelayedOverrideControllerTrans_ResetToDefaults;
    short _padding_7;
    struct Vector2 m_reticleOffset;
    uint64_t hashmap[5]; //struct HashMap<int, int> m_replacementResourceIDMap;
    bool m_bFXUnderWaterActive;
};


struct GameRender {
    long long _padding_;
    long long _padding__;
    struct Screen m_screens[9];
    enum ScreenID m_currentScreen;
    float m_fFrameTime;
    unsigned int m_frameIndexPrevMatrixUpdate;
    struct ReflectionRender* m_reflectionRender;
    struct SSSRender* m_sssRender;
    unsigned int m_reloadTexturesWidgetId;
    struct CubeReflRender* m_cubereflRender;
    struct CubeAmbiRender* m_cubeambiRender;
    int m_eventCallbackID;
};

typedef enum TimeDilationType {
    TimeDilationType_Debug = 0,
    TimeDilationType_Pause = 1,
    TimeDilationType_UI = 2,
    TimeDilationType_Cinematic = 3,
    TimeDilationType_MiniCinematic = 4,
    TimeDilationType_ISS = 5,
    TimeDilationType_Script = 6,
    TimeDilationType_StateControl = 7,
    TimeDilationType_HunterSense = 8,
    TimeDilationType_Default = 9,
    TimeDilationType_Num_Types = 10
} TimeDilationType;

struct TimeDilation {
    float m_fTimeDilationWorld;
    float m_fTimeDilationWithPlayer;
};

struct TimeDilationRequest {
    enum TimeDilationType m_priority;
    struct TimeDilation m_data;
    bool m_bForceActive;
    bool m_bRequestIsDirty;
    float m_fStartRampTime;
    float m_fRampTime;
    float m_fActivateTime;
};

struct Euler {
    float data[4];
};

struct CineCameraData {
    int nCameraChannel;
    char field1_0x4;
    char field2_0x5;
    char field3_0x6;
    char field4_0x7;
    char field5_0x8;
    char field6_0x9;
    char field7_0xa;
    char field8_0xb;
    char field9_0xc;
    char field10_0xd;
    char field11_0xe;
    char field12_0xf;
    struct Euler vCameraEndRots;
    struct Vector3 vCameraEndPos;
    float fCameraEndFOV;
    char field16_0x34;
    char field17_0x35;
    char field18_0x36;
    char field19_0x37;
    char field20_0x38;
    char field21_0x39;
    char field22_0x3a;
    char field23_0x3b;
    char field24_0x3c;
    char field25_0x3d;
    char field26_0x3e;
    char field27_0x3f;
};

struct GlobalEnum {
    int data;
};


struct CinematicHandlerImpl {
    char field0_0x0;
    char field1_0x1;
    char field2_0x2;
    char field3_0x3;
    char field4_0x4;
    char field5_0x5;
    char field6_0x6;
    char field7_0x7;
    char field8_0x8;
    char field9_0x9;
    char field10_0xa;
    char field11_0xb;
    char field12_0xc;
    char field13_0xd;
    char field14_0xe;
    char field15_0xf;
    unsigned char* mEERingBuffer;
    int mEERingBufferSize;
    int mEERingBufferMask;
    int mEERingBufferPlayOffset;
    int mEERingBufferWriteOffsetLowerLimit;
    int mEERingBufferWriteOffsetUpperLimit;
    int mMainUnitID;
    int mHeaderUnitID;
    char field24_0x34;
    char field25_0x35;
    char field26_0x36;
    char field27_0x37;
    char* mDebugCineName;
    int mFrame;
    int mFrameCount;
    float mFramePosition;
    int mFrameSize;
    bool mFirstFrame;
    char field34_0x51;
    char field35_0x52;
    char field36_0x53;
    float mTimeIn;
    int mTransitionIn;
    struct CamTransitionParams mTransitionOutParams;
    float mCinematicDilation;
    int mAnchorCount;
    struct Anchor* mAnchorTable;
    int mSkeletonCount;
    char field44_0xa4;
    char field45_0xa5;
    char field46_0xa6;
    char field47_0xa7;
    struct Skeleton* mSkeletonTable;
    int mCameraCount;
    char field50_0xb4;
    char field51_0xb5;
    char field52_0xb6;
    char field53_0xb7;
    char field54_0xb8;
    char field55_0xb9;
    char field56_0xba;
    char field57_0xbb;
    char field58_0xbc;
    char field59_0xbd;
    char field60_0xbe;
    char field61_0xbf;
    struct CineCameraData mCameraData[8];
    int mCurrentCameraChannel;
    char field64_0x2c4;
    char field65_0x2c5;
    char field66_0x2c6;
    char field67_0x2c7;
    unsigned long long mCameraComponentOwnerHandle;
    struct DummyCameraController* mCameraController;
    unsigned int mCameraCutCount;
    char field71_0x2dc;
    char field72_0x2dd;
    char field73_0x2de;
    char field74_0x2df;
    unsigned int* mCameraCutTable;
    int mTriggerCount;
    int mTriggerUnitID;
    struct Trigger* mTriggerTable;
    float mFov;
    char field80_0x2fc;
    char field81_0x2fd;
    char field82_0x2fe;
    char field83_0x2ff;
    struct Matrix mCinematicToUnitTransform;
    bool mIsCinematicToUnitTransformIdentity;
    char field86_0x341;
    char field87_0x342;
    char field88_0x343;
    int mHeaderSize;
    bool mHeaderValid;
    char field91_0x349;
    char field92_0x34a;
    char field93_0x34b;
    int mFloatChannelCount;
    struct FloatChannel* mFloatChannelTable;
    float m_oldFullMediaTime;
    float mInterFrameWeight;
    bool m_inCameraCut;
    char field99_0x361;
    char field100_0x362;
    char field101_0x363;
    unsigned int m_inRunningShotCount;
    bool mIsRunning;
    char field104_0x369;
    char field105_0x36a;
    char field106_0x36b;
    int mCameraUnitId;
    bool m_cameraControl;
    bool m_restorePositionsPlayer;
    bool m_restorePositionsNonPlayer;
    bool m_blendOut;
    bool m_restorePreCinePlayerHealth;
    char field113_0x375;
    char field114_0x376;
    char field115_0x377;
    int m_nPreCinePlayerHealth;
    int m_endTriggerID;
    float m_blendInterpTime;
    float m_blendStartTime;
    bool m_useOverridePlayerPosOnExit;
    char field121_0x389;
    char field122_0x38a;
    char field123_0x38b;
    char field124_0x38c;
    char field125_0x38d;
    char field126_0x38e;
    char field127_0x38f;
    struct Vector3 m_overridePlayerPos;
    struct Vector3 m_overridePlayerRot;
    struct Vector3 m_vPlayerExitVel;
    bool m_clearPlayerMarkupAndJumpTarget;
    bool m_allowManualCineCameraReset;
    bool m_allowManualCineCamResetAfterCancel;
    bool m_allowTriggerProcessing;
    bool m_changeInventoryState;
    bool m_resetInventoryStateBeforeBlendingOut;
    bool m_bHidingCorpses;
    char field138_0x3c7;
    struct GlobalEnum m_cineActorNotifyStartEvent;
    struct GlobalEnum m_cineActorNotifyLastCameraCutEvent;
    struct GlobalEnum m_cineActorNotifyEndEvent;
    enum InventoryCineActorEndState m_InventoryCineActorEndState;
    enum Cine_CinematicLightMode m_cineLightMode;
    enum Cine_GameplayLightMode m_gameplayLightMode;
    enum VideoSyncStates m_syncWithVideoState;
    char field146_0x3e4;
    char field147_0x3e5;
    char field148_0x3e6;
    char field149_0x3e7;
    unsigned char* m_pBufferPointer;
    int m_postHeaderOffset;
    char field152_0x3f4;
    char field153_0x3f5;
    char field154_0x3f6;
    char field155_0x3f7;
    struct IScene* m_scene;
    int m_loopStart;
    int m_loopEnd;
    struct SeekCineChannelInfo* m_loopStartChannelInfo;
    float m_lastMediaTime;
    float m_lastDilationTime;
    float m_lastRawMediaTime;
    bool m_initialized;
    bool m_bBlockCameraWaterChecks;
    char field165_0x41e;
    char field166_0x41f;
    struct GlobalAnimObject* m_globalAnimObject;
    struct SmoothFunction* m_smoothFunction;
    struct LocalIDResolver* m_localIDResolver;
    bool m_bHasSubtitleOverride;
    bool m_reducedBackbuffer;
    char field172_0x43a;
    char field173_0x43b;
    char field174_0x43c;
    char field175_0x43d;
    char field176_0x43e;
    char field177_0x43f;
    char m_shotChangedCallbacks[16]; // struct Array<CallbackBase0P<void>_*> m_shotChangedCallbacks;
    char m_doneOrSkipCallbacks[16]; // struct Array<CallbackBase0P<void>_*> m_doneOrSkipCallbacks;
    bool m_IsExecutingShotChangedCallbacks;
    bool m_IsExecutingDoneOrSkipCallbacks;
    char field182_0x462;
    char field183_0x463;
    char field184_0x464;
    char field185_0x465;
    char field186_0x466;
    char field187_0x467;
    char field188_0x468;
    char field189_0x469;
    char field190_0x46a;
    char field191_0x46b;
    char field192_0x46c;
    char field193_0x46d;
    char field194_0x46e;
    char field195_0x46f;
};

struct THAlloc {
    uint64_t data[0x3];
};

struct SceneJobManager {
    uint64_t data[0xD];
};

struct Prepared {
    uint64_t data[0xA];
};

struct CullingAABB {
    struct Vector3 m_center;
    struct Vector3 m_extents;
};

struct SceneStaticMesh;
struct SceneSubCell;
struct SceneDynamicPortal;
struct SceneCellGroup;
struct SceneCell {
    struct StaticLightFrustums {
        union StaticLightFrustums_u_24 {
            struct StaticLightFrustums_u_24_s_0 {
                unsigned int lastStaticOcclusionTree : 24;
                enum IntersectionResult singleSubCellTestResult :8;
            };
            struct StaticLightFrustums_u_24_s_0 _s_0;
            unsigned int bitfield;
        };

        struct SceneLight* pLight;
        struct Array<void *> occlusionTrees; //struct Array<cdc::SceneRCPtr<cdc::OcclusionTree>_> occlusionTrees;
        union StaticLightFrustums_u_24 field2_0x18;
        int _padding_;
        struct Array<SceneSubCell *> partiallyHitSubCells;
        struct Array<SceneSubCell *> fullyHitSubCells;
    };
    long long _padding_0;
    long long _padding_1;
    long long _padding_2;
    long long _padding_3;
    long long _padding_4;
    long long _padding_5;
    long long _padding_6;
    long long _padding_7;
    long long _padding_8;
    long long _padding_9;
    long long _padding_10;
    long long _padding_11;
    long long _padding_12;
    long long _padding_13;
    struct SceneCell* m_pParentCell;
    struct SceneSubCell* m_pSubCells;
    unsigned short m_numSubCells;
    unsigned int m_uniqueId;
    unsigned int m_cellIndex;
    int _padding_14;
    struct Array<SceneCellGroup *> m_childCellGroups;
    struct Array<SceneCell::StaticLightFrustums> m_staticLights;
    struct Array<SceneLight *> m_staticLightPtrs;
    struct CullingAABB m_bbox;
    bool m_hasBBox;
    struct ScenePortal* m_pPortals;
    unsigned int m_numPortals;
    struct SceneCell** m_ppOmniPortalsToCells;
    unsigned int m_numOmniPortals;
    int _padding_15;
    struct Array<SceneDynamicPortal *> m_dynamicPortals;
    struct Array<SceneCell *> m_dynamicOnmiPortals;
    struct Array<ScenePortal *> m_portalsToThisCell;
    struct Array<SceneCell *> m_omniPortalsToThisCell;
    enum CellTraversalType m_traversalType;
    enum CellTraversalType m_cachedTraversalType;
    struct Vector3 m_cachedEye;
    float m_maxVisibleDistance;
    float m_passThroughDistance;
    struct CellData* m_pCellData;
    struct CellStreamData* m_pStreamData;
    struct RenderModelInstance* m_pCellMeshRMI;
    void* m_pUserData; //struct RCPtr<cdc::RCObject> m_pUserData;
    char* m_pName;
    unsigned int m_traverseLock;
    unsigned int m_lastProcessed;
    unsigned int m_lastVisibile;
    int _padding_16;
    struct Array<SceneLight *> m_lights;
    struct CullingArray<SceneLight *> m_visibleLights;
    struct CullingArray<CullingFrustum> m_viewFrustums;
    struct OcclusionTree* m_pOcclusionTree;
    long long _padding_17;
    struct Vector3 m_occlusionTreeEyeCache;
    struct SceneLight* m_pLastProcessedLight;
    bool m_visited;
    bool m_onStack : 1;
    bool m_readdOccluders : 1;
    bool m_hasStreamedOccluders : 1;
};
struct SceneCellGroup {
    char field0_0x0;
    char field1_0x1;
    char field2_0x2;
    char field3_0x3;
    char field4_0x4;
    char field5_0x5;
    char field6_0x6;
    char field7_0x7;
    char field8_0x8;
    char field9_0x9;
    char field10_0xa;
    char field11_0xb;
    char field12_0xc;
    char field13_0xd;
    char field14_0xe;
    char field15_0xf;
    char field16_0x10;
    char field17_0x11;
    char field18_0x12;
    char field19_0x13;
    char field20_0x14;
    char field21_0x15;
    char field22_0x16;
    char field23_0x17;
    char field24_0x18;
    char field25_0x19;
    char field26_0x1a;
    char field27_0x1b;
    char field28_0x1c;
    char field29_0x1d;
    char field30_0x1e;
    char field31_0x1f;
    char field32_0x20;
    char field33_0x21;
    char field34_0x22;
    char field35_0x23;
    char field36_0x24;
    char field37_0x25;
    char field38_0x26;
    char field39_0x27;
    char field40_0x28;
    char field41_0x29;
    char field42_0x2a;
    char field43_0x2b;
    char field44_0x2c;
    char field45_0x2d;
    char field46_0x2e;
    char field47_0x2f;
    char field48_0x30;
    char field49_0x31;
    char field50_0x32;
    char field51_0x33;
    char field52_0x34;
    char field53_0x35;
    char field54_0x36;
    char field55_0x37;
    char field56_0x38;
    char field57_0x39;
    char field58_0x3a;
    char field59_0x3b;
    char field60_0x3c;
    char field61_0x3d;
    char field62_0x3e;
    char field63_0x3f;
    char field64_0x40;
    char field65_0x41;
    char field66_0x42;
    char field67_0x43;
    char field68_0x44;
    char field69_0x45;
    char field70_0x46;
    char field71_0x47;
    char field72_0x48;
    char field73_0x49;
    char field74_0x4a;
    char field75_0x4b;
    char field76_0x4c;
    char field77_0x4d;
    char field78_0x4e;
    char field79_0x4f;
    char field80_0x50;
    char field81_0x51;
    char field82_0x52;
    char field83_0x53;
    char field84_0x54;
    char field85_0x55;
    char field86_0x56;
    char field87_0x57;
    char field88_0x58;
    char field89_0x59;
    char field90_0x5a;
    char field91_0x5b;
    char field92_0x5c;
    char field93_0x5d;
    char field94_0x5e;
    char field95_0x5f;
    char field96_0x60;
    char field97_0x61;
    char field98_0x62;
    char field99_0x63;
    char field100_0x64;
    char field101_0x65;
    char field102_0x66;
    char field103_0x67;
    char field104_0x68;
    char field105_0x69;
    char field106_0x6a;
    char field107_0x6b;
    char field108_0x6c;
    char field109_0x6d;
    char field110_0x6e;
    char field111_0x6f;
    struct Scene* m_pScene;
    struct Array<SceneCell *> m_cells;
    struct SceneCell* m_pParentCell;
    unsigned int m_numSubCells;
    char field116_0x94;
    char field117_0x95;
    char field118_0x96;
    char field119_0x97;
    char field120_0x98;
    char field121_0x99;
    char field122_0x9a;
    char field123_0x9b;
    char field124_0x9c;
    char field125_0x9d;
    char field126_0x9e;
    char field127_0x9f;
    struct BasicCullingVolume m_volume;
    struct CellGroupData* m_pCellGroupData;
    void* m_pUserData; //struct RCPtr<cdc::RCObject> m_pUserData;
    struct Vector3 m_translation;
    char* m_pName;
    float* m_pIrradianceCoefficients;
    float* m_pIrradianceScale;
    char field135_0x138;
    char field136_0x139;
    char field137_0x13a;
    char field138_0x13b;
    char field139_0x13c;
    char field140_0x13d;
    char field141_0x13e;
    char field142_0x13f;
};




struct Scene {
    char field0_0x0;
    char field1_0x1;
    char field2_0x2;
    char field3_0x3;
    char field4_0x4;
    char field5_0x5;
    char field6_0x6;
    char field7_0x7;
    char field8_0x8;
    char field9_0x9;
    char field10_0xa;
    char field11_0xb;
    char field12_0xc;
    char field13_0xd;
    char field14_0xe;
    char field15_0xf;
    char field16_0x10;
    char field17_0x11;
    char field18_0x12;
    char field19_0x13;
    char field20_0x14;
    char field21_0x15;
    char field22_0x16;
    char field23_0x17;
    char field24_0x18;
    char field25_0x19;
    char field26_0x1a;
    char field27_0x1b;
    char field28_0x1c;
    char field29_0x1d;
    char field30_0x1e;
    char field31_0x1f;
    char field32_0x20;
    char field33_0x21;
    char field34_0x22;
    char field35_0x23;
    char field36_0x24;
    char field37_0x25;
    char field38_0x26;
    char field39_0x27;
    char field40_0x28;
    char field41_0x29;
    char field42_0x2a;
    char field43_0x2b;
    char field44_0x2c;
    char field45_0x2d;
    char field46_0x2e;
    char field47_0x2f;
    char field48_0x30;
    char field49_0x31;
    char field50_0x32;
    char field51_0x33;
    char field52_0x34;
    char field53_0x35;
    char field54_0x36;
    char field55_0x37;
    char field56_0x38;
    char field57_0x39;
    char field58_0x3a;
    char field59_0x3b;
    char field60_0x3c;
    char field61_0x3d;
    char field62_0x3e;
    char field63_0x3f;
    struct RenderDevice* m_pRenderDevice;
    struct TransientHeapAllocator m_transientHeap;
    struct THAlloc m_thAlloc;
    struct THAlloc m_thAllocRenderDeviceHeap;
    struct SceneJobManager m_jobManager;
    struct JobChain* m_pPreProcessJobChain;
    bool m_isPreProcessChainStarted;
    char field71_0x131;
    char field72_0x132;
    char field73_0x133;
    char field74_0x134;
    char field75_0x135;
    char field76_0x136;
    char field77_0x137;
    struct Array<SceneCellGroup *> m_cellGroups;
    char m_idDatabase[0x10]; // struct ArrayMap<unsigned_int, void_*> m_idDatabase;
    struct ISceneTerrainCallback* m_pTerrainCallback;
    struct SceneCellGroup* m_pCameraCellGroup;
    struct SceneCell* m_pLastCameraCell;
    float m_cameraQuerySphereRadius;
    char field84_0x174;
    char field85_0x175;
    char field86_0x176;
    char field87_0x177;
    struct Array<SceneEntity *> m_entities;
    struct Array<SceneLight *> m_lights;
    struct Array<SceneLight *> m_removedLights;
    char field91_0x1a8;
    char field92_0x1a9;
    char field93_0x1aa;
    char field94_0x1ab;
    char field95_0x1ac;
    char field96_0x1ad;
    char field97_0x1ae;
    char field98_0x1af;
    struct Vector3 m_staticMeshTranslation;
    struct Array<SceneStaticMesh *> m_staticMeshes;
    struct Array<SceneStaticMesh *> m_removedStaticMeshes;
    struct Array<SceneStaticMesh *> m_partiallyIntersectingStaticMeshes;
    unsigned int m_numStaticMeshes;
    bool m_patchOutputIndexGrass;
    char field105_0x1f5;
    char field106_0x1f6;
    char field107_0x1f7;
    uint64_t m_newStaticMeshes[2]; // struct Array<cdc::Pair<cdc::SceneStaticMesh_*, unsigned_int>_> m_newStaticMeshes;
    struct Array<SceneSubCell *> m_subCellDeleteList;
    char field110_0x218;
    char field111_0x219;
    char field112_0x21a;
    char field113_0x21b;
    char field114_0x21c;
    char field115_0x21d;
    char field116_0x21e;
    char field117_0x21f;
    struct RenderViewport m_viewport;
    struct CullingFrustum m_viewFrustum;
    struct Prepared m_preparedViewFrustum;
    unsigned int m_globalLightMask;
    unsigned int m_globalLightCondition;
    unsigned int m_globalLightConditionResult;
    unsigned int m_globalRenderCondition;
    unsigned int m_globalRenderConditionResult;
    char field126_0x424;
    char field127_0x425;
    char field128_0x426;
    char field129_0x427;
    void* m_pendingPortals; // struct SList<cdc::Pair<char_const_*, cdc::Array<cdc::Scene::PendingPortal>_>_> m_pendingPortals;
    bool m_flushScheduled;
    char field132_0x431;
    char field133_0x432;
    char field134_0x433;
    char field135_0x434;
    char field136_0x435;
    char field137_0x436;
    char field138_0x437;
    struct SceneLight* m_pFirstFlushLight;
    struct SceneLight* m_pLastFlushLight;
    struct SceneEntity* m_pFirstUpdateIrradianceEntity;
    struct SceneEntity* m_pLastUpdateIrradianceEntity;
    struct Array<SceneEntity *> m_frustumCullingEntities;
    struct SceneLight* m_pCurrentSun;
    bool m_isInRender;
    char field146_0x471;
    char field147_0x472;
    char field148_0x473;
    char field149_0x474;
    char field150_0x475;
    char field151_0x476;
    char field152_0x477;
    struct RenderState* m_pRenderState;
    struct SceneGlobalJobState m_globalJobState;
    struct AtomicTransientArray<SceneEntity *> m_callbackEntities;
    struct AtomicTransientArray<SceneEntity *> m_activeSingleCoreEntities;
    struct AtomicTransientArray<SceneEntity *> m_activePreProcessEntities;
    struct AtomicTransientArray<SceneEntity *> m_activeEntityJobChainEntities;
    struct AtomicTransientArray<SceneEntity *> m_entityResetList;
    struct AtomicTransientArray<SceneLight *> m_visibleLights;
    bool m_usePartition;
    char field162_0x551;
    char field163_0x552;
    char field164_0x553;
    char field165_0x554;
    char field166_0x555;
    char field167_0x556;
    char field168_0x557;
    char field169_0x558;
    char field170_0x559;
    char field171_0x55a;
    char field172_0x55b;
    char field173_0x55c;
    char field174_0x55d;
    char field175_0x55e;
    char field176_0x55f;
    struct CullingPlane m_partitionPlane;
    struct DataPerScene* m_pDataPerScene;
    unsigned int m_currentScene;
    unsigned int m_currentRenderFrame;
    unsigned int m_currentFrame;
    char field182_0x584;
    char field183_0x585;
    char field184_0x586;
    char field185_0x587;
    unsigned long long m_uniqueValue;
    struct Prepared m_frustumBuffer[16];
    struct OcclusionTree m_occlusionTreeBuffer[16];
    bool m_multicoreUpdatesEnabled;
    char field190_0x1691;
    char field191_0x1692;
    char field192_0x1693;
    char field193_0x1694;
    char field194_0x1695;
    char field195_0x1696;
    char field196_0x1697;
    void* m_pUserData; // struct RCPtr<cdc::RCObject> m_pUserData;
    struct LightFrameData* m_pEntityLightFrameDataBuckets[1249];
    char field199_0x3da8;
    char field200_0x3da9;
    char field201_0x3daa;
    char field202_0x3dab;
    char field203_0x3dac;
    char field204_0x3dad;
    char field205_0x3dae;
    char field206_0x3daf;
};



struct SceneEntity {
    char field0_0x0;
    char field1_0x1;
    char field2_0x2;
    char field3_0x3;
    char field4_0x4;
    char field5_0x5;
    char field6_0x6;
    char field7_0x7;
    char field8_0x8;
    char field9_0x9;
    char field10_0xa;
    char field11_0xb;
    char field12_0xc;
    char field13_0xd;
    char field14_0xe;
    char field15_0xf;
    char field16_0x10;
    char field17_0x11;
    char field18_0x12;
    char field19_0x13;
    char field20_0x14;
    char field21_0x15;
    char field22_0x16;
    char field23_0x17;
    char field24_0x18;
    char field25_0x19;
    char field26_0x1a;
    char field27_0x1b;
    char field28_0x1c;
    char field29_0x1d;
    char field30_0x1e;
    char field31_0x1f;
    char field32_0x20;
    char field33_0x21;
    char field34_0x22;
    char field35_0x23;
    char field36_0x24;
    char field37_0x25;
    char field38_0x26;
    char field39_0x27;
    char field40_0x28;
    char field41_0x29;
    char field42_0x2a;
    char field43_0x2b;
    char field44_0x2c;
    char field45_0x2d;
    char field46_0x2e;
    char field47_0x2f;
    char field48_0x30;
    char field49_0x31;
    char field50_0x32;
    char field51_0x33;
    char field52_0x34;
    char field53_0x35;
    char field54_0x36;
    char field55_0x37;
    char field56_0x38;
    char field57_0x39;
    char field58_0x3a;
    char field59_0x3b;
    char field60_0x3c;
    char field61_0x3d;
    char field62_0x3e;
    char field63_0x3f;
    struct Scene* m_pScene;
    int m_entityIndex;
    char field66_0x4c;
    char field67_0x4d;
    char field68_0x4e;
    char field69_0x4f;
    char* m_pName;
    bool m_isLight;
    bool m_cleanedUp;
    char field73_0x5a;
    char field74_0x5b;
    char field75_0x5c;
    char field76_0x5d;
    char field77_0x5e;
    char field78_0x5f;
    struct ISceneEntity* m_pISceneEntity;
    char field80_0x68;
    char field81_0x69;
    char field82_0x6a;
    char field83_0x6b;
    char field84_0x6c;
    char field85_0x6d;
    char field86_0x6e;
    char field87_0x6f;
    struct Matrix m_matrix;
    enum MoveState m_moveState;
    bool m_enabled;
    char field91_0xb5;
    char field92_0xb6;
    char field93_0xb7;
    unsigned int m_entityFlags;
    char field95_0xbc;
    char field96_0xbd;
    char field97_0xbe;
    char field98_0xbf;
    struct IDrawable* m_pDrawable;
    struct SceneCellGroup* m_pCellGroup;
    struct SceneCell* m_pOverrideCell;
    struct Array< SceneSubCell *> m_subCellsContainingDrawable;
    void* m_pUserData;
    struct BasicCullingVolume m_localVolume;
    struct DrawableInfo m_drawableInfo;
    struct Vector m_bspCache;
    enum LODDistanceMethod m_lodDistanceMethod;
    int m_perFrameFlags;
    struct AtomicTransientArray<SceneLight *> m_visibleLights;
    struct AtomicTransientArray<SceneLight *> m_shadowLights;
    char field111_0x228;
    char field112_0x229;
    char field113_0x22a;
    char field114_0x22b;
    char field115_0x22c;
    char field116_0x22d;
    char field117_0x22e;
    char field118_0x22f;
    struct Scalar m_lodDistance;
    struct Array<SceneLight *> m_visibleStaticLights;
    unsigned long long m_lastStaticLightValue;
    bool m_drawableIntersectsStaticLightVolume;
    bool m_drawableVisibleForCurrentStaticLight;
    char field124_0x25a;
    char field125_0x25b;
    char field126_0x25c;
    char field127_0x25d;
    char field128_0x25e;
    char field129_0x25f;
    struct IrradianceCache* m_pIrradianceCache;
    char field131_0x268;
    char field132_0x269;
    char field133_0x26a;
    char field134_0x26b;
    char field135_0x26c;
    char field136_0x26d;
    char field137_0x26e;
    char field138_0x26f;
};

struct SceneLight {
    struct SceneEntity sceneEntity;
    char field624_0x270;
    char field625_0x271;
    char field626_0x272;
    char field627_0x273;
    char field628_0x274;
    char field629_0x275;
    char field630_0x276;
    char field631_0x277;
    int m_lightIndex;
    int m_shadowLightIndex;
    int m_dynamicLightIndex;
    char field635_0x284;
    char field636_0x285;
    char field637_0x286;
    char field638_0x287;
    struct ILightResource* m_pResource;
    struct IRenderLight* m_pRenderLight;
    bool m_castsShadows;
    bool m_viewIndependentShadowCulling;
    bool m_cullShadow;
    bool m_cullObjects;
    bool m_isIndirectLit;
    bool m_enablePortalCulling;
    bool m_isUnitInterpolatedTransform;
    bool m_padding[1];
    unsigned int m_lightMask;
    unsigned int m_shadowMask;
    float m_range;
    float m_penumbra;
    float m_shadowFadeDistance;
    float m_shadowCullDistance;
    unsigned char m_defaults;
    char field656_0x2b9;
    char field657_0x2ba;
    char field658_0x2bb;
    char field659_0x2bc;
    char field660_0x2bd;
    char field661_0x2be;
    char field662_0x2bf;
    struct Array<SceneCell *> m_cellsContainingLight;
    struct SceneCell* m_pTiedCell;
    enum Boundary m_lightBoundary;
    char field666_0x2dc;
    char field667_0x2dd;
    char field668_0x2de;
    char field669_0x2df;
    unsigned int* m_pLightBoundaryCells;
    unsigned int m_numLightBoundaryCells;
    unsigned int m_lightType;
    float m_radiusValue;
    float m_nearRadius;
    bool m_shadowCastingStaticRender;
    bool m_shadowCastingStaticTraversal;
    bool m_useViewIndependentShadowCulling;
    char field678_0x2fb;
    char field679_0x2fc;
    char field680_0x2fd;
    char field681_0x2fe;
    char field682_0x2ff;
    struct Color m_diffuseColor;
    float m_intensity;
    char field685_0x314;
    char field686_0x315;
    char field687_0x316;
    char field688_0x317;
    char field689_0x318;
    char field690_0x319;
    char field691_0x31a;
    char field692_0x31b;
    char field693_0x31c;
    char field694_0x31d;
    char field695_0x31e;
    char field696_0x31f;
    struct BasicCullingVolume m_lightVolume;
    struct SceneCell* m_pCellContainingOrigin;
    struct SceneCell* m_alternateCells[1];
    unsigned int m_lastLightFrameIndex;
    unsigned int m_lastRenderDeviceFramePrepared;
    struct BasicCullingVolume* m_pFrameLightVolume;
    struct CullingPolytope m_shadowVolume;
    char field704_0x3e8;
    char field705_0x3e9;
    char field706_0x3ea;
    char field707_0x3eb;
    char field708_0x3ec;
    char field709_0x3ed;
    char field710_0x3ee;
    char field711_0x3ef;
    struct Prepared m_preparedTransformedShadowVolume;
    struct Prepared m_preparedShadowVolume;
    struct StaticCullingPolytope* m_pStaticShadowVolume;
    char field715_0x498;
    char field716_0x499;
    char field717_0x49a;
    char field718_0x49b;
    char field719_0x49c;
    char field720_0x49d;
    char field721_0x49e;
    char field722_0x49f;
    struct Vector3 m_preparedShadowTranslation;
    struct Vector3 m_cachedStaticShadowVolumeTranslation;
    struct StaticCullingPolytope* m_pCachedStaticShadowVolume;
    unsigned long long m_lightCheckValue;
    bool m_lightActive;
    bool m_shadowCastingRender;
    bool m_shadowCastingTraversal;
    bool m_inUpdateList;
    int m_perFrameLightFlags;
    unsigned int m_lightApproved;
    unsigned int m_activeLightMask;
    unsigned int m_activeShadowMask;
    char field735_0x4e4;
    char field736_0x4e5;
    char field737_0x4e6;
    char field738_0x4e7;
    struct AtomicTransientArray<SceneEntity *> m_litEntities;
    unsigned long long m_lastUniqueValue;
    struct Array<SceneEntity *> m_visibleStaticEntities;
    struct Array<SceneStaticMesh *> m_visibleStaticMeshes;
    struct SceneLight* m_pNextFlushLight;
    char field744_0x528;
    char field745_0x529;
    char field746_0x52a;
    char field747_0x52b;
    char field748_0x52c;
    char field749_0x52d;
    char field750_0x52e;
    char field751_0x52f;
};

struct UnitLightGroup {
    unsigned short m_unit;
    unsigned short m_unitLightGroupIdx;
};

struct LightTemplateData {
    bool m_scriptDisabled;
    bool m_enableLightCulling;
    bool m_invertedLightCulling;
    float m_cullLightDistance;
    float m_cullLightFadeDistance;
    int m_lightType;
    int m_lightComplexity;
    float m_range;
    float m_lightIntensity;
    unsigned char m_lightColorR;
    unsigned char m_lightColorG;
    unsigned char m_lightColorB;
    int m_probeModul;
    float m_probePriority;
    unsigned short m_scriptLightGroup;
    struct UnitLightGroup m_unitLightGroup;
    float m_rangeScale;
    float m_rangeScale_scripted;
    bool m_activeInGameplay : 1;
    bool m_activeInCinematics : 1;
    bool m_activeForMainPass : 1;
    bool m_activeForReflection : 1;
    bool m_activeForCapturing : 1;
    signed char __bitfieldpadding16 : 3;
    bool m_inExteriorCell;
    bool m_disablePortalCulling;
    float m_umbra;
    float m_penumbra;
    float m_nearRadius;
    bool m_doIndirect;
    float m_indirectStrength;
    float m_indirectIntensity;
    int m_indirectLightType;
    float m_boxLightStartX;
    float m_boxLightFalloffX;
    float m_boxLightStartY;
    float m_boxLightFalloffY;
    float m_boxLightStartZ;
    float m_boxLightFalloffZ;
    float m_relReflCubeCenterX;
    float m_relReflCubeCenterY;
    float m_relReflCubeCenterZ;
    bool m_relReflEnableColisionProxy;
    float m_relReflCollisionBoxCenterX;
    float m_relReflCollisionBoxCenterY;
    float m_relReflCollisionBoxCenterZ;
    float m_relReflCollisionBoxDimX;
    float m_relReflCollisionBoxDimY;
    float m_relReflCollisionBoxDimZ;
    int m_fireLightFlameScale;
    int m_fireLightMaskScale;
    float m_fireLightBurnSpeed;
    float m_fireLightCurrentBurn;
    bool m_cheapWetLight;
    float m_wetCubeMapIntensity;
    float m_wetDarkLightIntensity;
    unsigned char* m_attenuation;
    float m_specularStrength;
    float m_lambertWeight;
    float m_halfLambertWeight;
    float m_ambientWeight;
    float m_minShadowSpecular;
    bool m_enableVariation;
    bool m_randomStartVariation;
    float m_intensityVariationSpeed;
    unsigned char* m_intensityVariation;
    bool m_enableModulationTexture;
    struct TextureMap* m_modulationTexture;
    float m_texScale;
    float m_texRotation;
    float m_texXScroll;
    float m_texYScroll;
    bool m_shadowEnabled;
    bool m_shadowIncreaseResolution;
    bool m_enablePerInstanceShadowBias;
    float m_shadowConstBias;
    float m_shadowSlopeBias;
    float m_shadowDistanceBias;
    int m_shadowMapSize;
    bool m_isReceiverFocus;
    bool m_isSoftshadow;
    float m_softShadowRadius;
    int m_softShadowNumSamples;
    float m_softShadowDepthBias;
    float m_softShadowExponent;
    bool m_volumetricLightEnabled;
    bool m_volumetricLightIntensityCorrellated;
    float m_volumetricLightIntensity;
    float m_volumetricLightScatterFactor;
    int m_volumetricLightSamples;
    int m_volumetricLightSamples2;
    bool m_volumetricLightUseScatteringAmount;
    bool m_volumetricLightParamOverride;
    unsigned char m_volumetricLightColorR;
    unsigned char m_volumetricLightColorG;
    unsigned char m_volumetricLightColorB;
    unsigned char* m_volumetricLightAttenuation;
    bool m_volumetricLightParamSpotOverride;
    float m_volumetricLightUmbra;
    float m_volumetricLightPenumbra;
    bool m_viewIndependentShadowCulling;
    bool m_enableShadowLOD;
    float m_shadowLODDist1;
    float m_shadowLODDist2;
    float m_shadowLODDist3;
    bool m_enableAutomaticShadowLOD;
    float m_automaticShadowLODMultiplier;
    bool m_enableAutoLightConversion;
    float m_conversionDistance;
    bool m_enableShadowDistanceCulling;
    float m_shadowFadeDistance;
    float m_shadowCullDistance;
    bool m_affectsPlayer : 1;
    bool m_affectsIntros : 1;
    bool m_affectsBGObjects : 1;
    bool m_affectsTerrain : 1;
    bool m_affectsGroup1 : 1;
    bool m_affectsGroup2 : 1;
    bool m_affectsGroup3 : 1;
    bool m_affectsGroup4 : 1;
    bool m_affectsCineGroup1 : 1;
    bool m_affectsCineGroup2 : 1;
    bool m_affectsCineGroup3 : 1;
    bool m_affectsCineGroup4 : 1;
    bool m_affectsCineGroup5 : 1;
    bool m_affectsCineGroup6 : 1;
    bool m_affectsCineGroup7 : 1;
    bool m_affectsCineGroup8 : 1;
    bool m_affectsWater : 1;
    bool m_affectsFX : 1;
    signed char __bitfieldpadding137 : 6;
    signed char m_onlyAffects;
    unsigned int* m_affectsCells;
    unsigned int m_affectsCellsCount;
    bool m_shadowAffectsPlayer : 1;
    bool m_shadowAffectsIntros : 1;
    bool m_shadowAffectsBGObjects : 1;
    bool m_shadowAffectsTerrain : 1;
    bool m_shadowAffectsGroup1 : 1;
    bool m_shadowAffectsGroup2 : 1;
    bool m_shadowAffectsGroup3 : 1;
    bool m_shadowAffectsGroup4 : 1;
    bool m_shadowAffectsCineGroup1 : 1;
    bool m_shadowAffectsCineGroup2 : 1;
    bool m_shadowAffectsCineGroup3 : 1;
    bool m_shadowAffectsCineGroup4 : 1;
    bool m_shadowAffectsCineGroup5 : 1;
    bool m_shadowAffectsCineGroup6 : 1;
    bool m_shadowAffectsCineGroup7 : 1;
    bool m_shadowAffectsCineGroup8 : 1;
    bool m_animEnabled;
    float m_animParamsPosX[4];
    float m_animParamsPosY[4];
    float m_animParamsPosZ[4];
    float m_animParamsDirX[4];
    float m_animParamsDirY[4];
    float m_animParamsDirZ[4];
    float m_originalIntensity;
    unsigned char m_originalColorR;
    unsigned char m_originalColorG;
    unsigned char m_originalColorB;
    float m_originalRangeScale;
};

typedef SceneLight ISceneLight;

struct LightInstance {
    struct Matrix m_transform;
    struct Matrix m_attachTransform;
    char* m_debugName;
    int m_uniqueID;
    unsigned int m_lightId;
    ISceneLight* m_pSceneLight;
    struct StreamUnit* m_pStreamUnit;
    bool m_bIsDynamic;
    int m_tiedCellID;
    bool m_enableParentAttach;
    struct PlacementPath m_parentPlacement;
    unsigned int m_parentMarkerAttach;
    struct LightTemplateData m_data;
};

struct LightEntry {
    unsigned long long m_pParent;
    struct LightInstance* m_pInstance;
    struct PlacementHashKey m_hashKey;
    unsigned int m_flags;
};  

struct ScriptLightGroupParams {
    struct Smoother<float> m_groupIntensityScale;
    struct Smoother<float> m_groupRangeScale;
    struct Smoother<float> m_groupFader;
    bool m_groupEnabled;
    bool m_inExclusiveMode;
};

struct LightManager {
    struct HashMap<PlacementHashKey, unsigned __int64> m_lightMap;
    struct Array<LightEntry> m_lights;
    struct ILightNotifier* m_pFirstNotifier;
    struct ILightNotifier* m_pLastNotifier;
    struct ILightConverter* m_pFirstConverter;
    struct ILightConverter* m_pLastConverter;
    struct ScriptLightGroupParams m_scriptLightGroupParams[20];
    unsigned int m_exclusiveScriptLightGroupCount;
    void* m_unitLightGroups; // struct SList<cdc::LightManager::UnitLightGroupParams> m_unitLightGroups;
    unsigned int m_exclusiveUnitLightGroupCount;
    struct ISceneLight* m_pActiveSunLight;
    struct ISunLightInterpolationCallback* s_pSunLightInterpolationCallback;
    bool m_hadExclusiveGroups;
    bool m_shouldUpdateLightGroups;
};

static constexpr Matrix identity_matrix = { 
.col = {
    {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f},
    {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f},
    {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f},
    {.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f}
}};


struct NsGameGlobalsBase;
struct PauseQueue;
struct TimeDilationManager;

static const uintptr_t PauseQueue_offset = 0x3aec618;
static const uintptr_t TimeDilationManager_offset = 0x3b14850;
static const uintptr_t GameTracker_offset = 0x3b10a20;
static const uintptr_t GameTrackerCinematicHandler_offset = GameTracker_offset + 0x118;
static const uintptr_t GlobalScene_offset = 0x3ae7598;
static const uintptr_t LightManager_offset = 0x3aec5f0;
static const uintptr_t PlayerPos_offset = 0x16c5b60;
static const uintptr_t StreamTracker_offset = 0x3af5470;

static const uintptr_t _PauseQueueCB_offset = 0x4af240;
static const uintptr_t PauseGame_offset = 0x2190b0;
static const uintptr_t StartPauseGameWorld_offset = 0x906520;
static const uintptr_t EndPauseGameWorld_offset = 0x8f4eb0;
static const uintptr_t NotifyListeners_offset = 0x43a050;
static const uintptr_t CancelRequest_offset = 0x4b6a00;
static const uintptr_t Request_offset = 0x4c8c40;
static const uintptr_t CinematicHandlerCreate_offset = 0x17a170;
static const uintptr_t AddLight_offset = 0x420000;
static const uintptr_t RemoveLight_offset = 0x448980;

typedef void(__cdecl* _PauseQueueCB_t)(unsigned int param_1, int param_2);
typedef void(__thiscall* PauseGame_t)(NsGameGlobalsBase* this_, bool param_1);
typedef void(__cdecl* StartPauseGameWorld_t)(int param_1);
typedef void(__cdecl* EndPauseGameWorld_t)(int param_1);
typedef void(__thiscall* NotifyListeners_t)(PauseQueue* this_, unsigned int param_1, int param_2, char* param_3);
typedef void(__thiscall* Request_t)(TimeDilationManager* this_, TimeDilationRequest* param_1);
typedef void(__thiscall* CancelRequest_t)(TimeDilationManager* this_, TimeDilationType param_1, char *param_2);
typedef LightEntry* (__thiscall* AddLight_t)(LightManager* this_, LightInstance* param_1, PlacementHashKey param_2);
typedef CinematicHandlerImpl* (__cdecl* CinematicHandlerCreate_t)(void);
typedef void(__thiscall* RemoveLight_t)(LightManager* this_, PlacementHashKey param_1);

static constexpr uint8_t lightInstance_buf[] = {0x8C,0x08,0x4C,0xBF,0xB0,0x3C,0x00,0x3F,0xF7,0xC2,0xAC,0x3E,0x00,0x00,0x00,0x00,0x94,0xDD,0x04,0x3F,0x06,0x90,0x5A,0x3F,0xA8,0x30,0x2A,0xBD,0x00,0x00,0x00,0x00,0x4D,0x27,0x9E,0xBE,0x01,0x6B,0x11,0x3E,0x5A,0xC0,0x70,0xBF,0x00,0x00,0x00,0x00,0x1B,0xB7,0x12,0x47,0x00,0xDE,0x8A,0x46,0x20,0xD2,0xB0,0x46,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0xB8,0x01,0x41,0x0D,0x43,0x02,0x00,0x00,0x57,0x0D,0x04,0x00,0xFF,0xFF,0xFF,0xFF,0xB0,0xE9,0x8D,0x01,0x43,0x02,0x00,0x00,0x70,0x54,0x17,0x08,0xF7,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x1C,0x46,0x00,0x00,0x7A,0x44,0x05,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x80,0x89,0x44,0x0A,0xD7,0x23,0x3C,0x62,0xA5,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x4C,0x04,0x65,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x16,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x12,0x18,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x96,0x43,0x00,0x00,0x96,0x43,0x00,0x00,0x96,0x43,0x00,0x00,0x96,0x43,0x00,0x00,0x96,0x43,0x00,0x00,0x96,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x42,0x00,0x00,0xC8,0x42,0x00,0x00,0xC8,0x42,0x32,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x48,0x59,0x3C,0x0D,0x43,0x02,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x80,0x75,0x0A,0x43,0x02,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x37,0xCD,0xCC,0x0C,0x40,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0x40,0x03,0x00,0x00,0x00,0x0A,0xD7,0xA3,0xBC,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0xCD,0xCC,0xCC,0x3D,0x08,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x01,0x62,0xA5,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x88,0x40,0x0D,0x43,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0xFA,0x44,0x00,0x00,0x7A,0x45,0x00,0x00,0xFA,0x45,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x40,0x1C,0x45,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0xD7,0x23,0x3C,0x62,0xA5,0xFF,0x00,0x00,0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0xB6,0x71,0x5D,0xBF,0x2C,0x96,0xF8,0xBE,0x15,0x97,0x01,0xBE,0x00,0x00,0x00,0x00,0x68,0x4D,0xF2,0xBE,0xE6,0xA9,0x34,0x3F,0x55,0xFA,0x06,0x3F,0x00,0x00,0x00,0x00,0x27,0xAF,0x2A,0xBE,0x13,0x17,0x04,0x3F,0x34,0x19,0x57,0xBF,0x00,0x00,0x00,0x00,0x3B,0xD3,0x13,0x47,0x51,0x4D,0x8B,0x46};



#define PAUSE_FLAG_PAUSE (1)

void injected_thread() {
    bool paused = false;

    HMODULE module_handle = GetModuleHandle(NULL);
    _PauseQueueCB_t _PauseQueueCB_ptr = (_PauseQueueCB_t)(_PauseQueueCB_offset + (uintptr_t)module_handle);
    PauseGame_t PauseGame_ptr = (PauseGame_t)(PauseGame_offset + (uintptr_t)module_handle);
    StartPauseGameWorld_t StartPauseGameWorld_ptr = (StartPauseGameWorld_t)(StartPauseGameWorld_offset + (uintptr_t)module_handle);
    EndPauseGameWorld_t EndPauseGameWorld_ptr = (EndPauseGameWorld_t)(EndPauseGameWorld_offset + (uintptr_t)module_handle);
    NotifyListeners_t NotifyListeners_ptr = (NotifyListeners_t)(NotifyListeners_offset + (uintptr_t)module_handle);
    Request_t Request_ptr = (Request_t)(Request_offset + (uintptr_t)module_handle);
    CancelRequest_t CancelRequest_ptr = (CancelRequest_t)(CancelRequest_offset + (uintptr_t)module_handle);
    CinematicHandlerCreate_t CinematicHandlerCreate_ptr = (CinematicHandlerCreate_t)(CinematicHandlerCreate_offset + (uintptr_t)module_handle);
    AddLight_t AddLight_ptr = (AddLight_t)(AddLight_offset + (uintptr_t)module_handle);
    RemoveLight_t RemoveLight_ptr = (RemoveLight_t)(RemoveLight_offset + (uintptr_t)module_handle);


    struct PauseQueue* pause_queue = (struct PauseQueue* )(PauseQueue_offset + (uintptr_t)module_handle);
    struct TimeDilationManager* dilation_manager = (struct TimeDilationManager*)(TimeDilationManager_offset + (uintptr_t)module_handle);

    TimeDilationRequest request = { .m_priority = TimeDilationType_Pause, .m_data = {.m_fTimeDilationWorld = 1.0f, .m_fTimeDilationWithPlayer = 1.0f},.m_bForceActive = true, .m_bRequestIsDirty = true, .m_fStartRampTime = 0.0f, .m_fRampTime = 0.0f,.m_fActivateTime = -1.0f };

    Scene *global_scene = *((Scene**)(GlobalScene_offset + (uintptr_t)module_handle));
    LightManager *lightManager = *((LightManager**)(LightManager_offset + (uintptr_t)module_handle));
    Vector3 *playerPos = (Vector3*)(PlayerPos_offset + (uintptr_t)module_handle);
    StreamUnit* streamUnit = (StreamUnit*)(StreamTracker_offset + (uintptr_t)module_handle);

    std::vector<LightInstance*> lights(lightManager->m_lights.size);
    std::vector<PlacementHashKey> keys(lightManager->m_lights.size);
    Vector3 captured_player_pos = *playerPos;
    
    

    GUI::Init();
    while (1) {
        //printf("visible light count = %u\n", global_scene->m_visibleLights.m_size);
        //fflush(stdout);
        if (GUI::StartFrame()) {
            break;
        }

        if (ImGui::Button("Capture Lights")) {
            lights.clear();
            keys.clear();
            for (unsigned int i = 0; i < lightManager->m_lights.size; ++i) {
                lights.push_back(lightManager->m_lights.data[i].m_pInstance);
                keys.push_back(lightManager->m_lights.data[i].m_hashKey);
            }
            while (lightManager->m_lights.size > 0) {
                RemoveLight_ptr(lightManager, lightManager->m_lights.data[0].m_hashKey);
            }
        }
        if (ImGui::Button("Delete Lights")) {
            while (lightManager->m_lights.size > 0) {
                RemoveLight_ptr(lightManager, lightManager->m_lights.data[0].m_hashKey);
            }
        }

        if (ImGui::Button("Spawn Light")) {
            //LightInstance *instance = new LightInstance();
            //memcpy(instance, lightManager->m_lights.data[0].m_pInstance, sizeof(*instance));
            //instance->m_transform.col[3].x = playerPos->x;
            //instance->m_transform.col[3].y = playerPos->y;
            //instance->m_transform.col[3].z = playerPos->z;
            //
            //PlacementHashKey key = { .m_keyValue = (uintptr_t)instance };
            for (unsigned int i = 0; i < lights.size(); ++i) {
                if (lights[i] != nullptr) {
                    AddLight_ptr(lightManager, lights[i], keys[i]);
                }
            }
        }

        
        
        ImGui::InputFloat3("player position", (float*)(playerPos), "%.3f", ImGuiInputTextFlags_ReadOnly);
        for (unsigned int i = 0; i < lightManager->m_lights.size; ++i) {
            if (lightManager->m_lights.data[i].m_pInstance->m_pSceneLight == nullptr) {
                continue;
            }
            ImGui::PushID(i);
            if (ImGui::TreeNode("Light")) {
                ImGui::DragFloat4("col0", (float*)(&lightManager->m_lights.data[i].m_pInstance->m_transform.col[0]));
                ImGui::DragFloat4("col1", (float*)(&lightManager->m_lights.data[i].m_pInstance->m_transform.col[1]));
                ImGui::DragFloat4("col2", (float*)(&lightManager->m_lights.data[i].m_pInstance->m_transform.col[2]));
                ImGui::DragFloat4("col3", (float*)(&lightManager->m_lights.data[i].m_pInstance->m_transform.col[3]));
                ImGui::TreePop();
            }
            ImGui::PopID();
        }
                
                // _PauseQueueCB_ptr(0b1111110, 2);
                // Request_ptr(dilation_manager, &request);
                // *((CinematicHandlerImpl **)(GameTrackerCinematicHandler_offset + (uintptr_t)module_handle)) = CinematicHandlerCreate_ptr();
                // _PauseQueueCB_ptr(0x1, 2);
                // CancelRequest_ptr(dilation_manager, TimeDilationType_Pause, nullptr);

        GUI::EndFrame();
               
    }

    GUI::Destroy();

}



BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)injected_thread, NULL, 0, NULL);
	}

	return true;
}