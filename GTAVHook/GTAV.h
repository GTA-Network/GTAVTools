/*****************************************************************************\

Copyright (C) 2013, GTA-Network Team <contact at gta-network dot net>

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

\*****************************************************************************/

#ifndef GTAV_H
#define GTAV_H

#include "Achievments_MP.h"
#include "Input.h"
#include "Network.h"
#include "Ped.h"
#include "Tasks.h"

typedef unsigned int u32; typedef int i32;
typedef unsigned short u16; typedef short i16;
typedef unsigned char u8; typedef char i8, ch; typedef wchar_t wch;
typedef float f32; typedef double f64;
typedef bool b8; typedef unsigned int b32;
typedef void * ptr; typedef unsigned char BYTE;

template <typename T>
inline T *ptr_cast(u32 value) {
	return *reinterpret_cast<T **>(&value);
}

inline ptr ptr_cast(u32 value){
	return *reinterpret_cast<ptr*>(&value);
}

template <class T>
inline T* ptr_cast(ptr value){
	return reinterpret_cast<T*>(value);
}


#ifndef NULL
#define NULL (0)
#endif

class CGTAVSpace {
private:
	unsigned						uiVersion;
	CGTAVSpace_Input				*pInput;
	CGTAVSpace_Network				*pNetwork;
	CGTAVSpace_Ped					*pPed;
	CGTAVSpace_Achievments_MP		*pAchievments;
	CGTAVSpace_Tasks				*pTasks;

	void							InitialiseSubClasses()
	{
		pInput = new CGTAVSpace_Input;
		pNetwork = new CGTAVSpace_Network;
		pPed = new CGTAVSpace_Ped;
		pAchievments = new CGTAVSpace_Achievments_MP;
		pTasks = new CGTAVSpace_Tasks;
	}

public:

	CGTAVSpace() { InitialiseSubClasses(); }
	~CGTAVSpace() {
		/* */
	};

	enum eVersion
	{
		VERSION_BETA,		// 1
		VERSION_X360,		// 2
		VERSION_PS3,		// 3
		VERSION_PC,			// 4
		VERSION_ORBIS,		// 5
		VERSION_NONFINAL	// 6
	};
	eVersion	GetVersion(BYTE byteVersion) { return (eVersion) byteVersion; }
	void		SetVersion(unsigned uiVersionEAX) { uiVersion = uiVersionEAX; }

	CGTAVSpace_Input				*Input() { return pInput; }
	CGTAVSpace_Network				*Network() { return pNetwork; }
	CGTAVSpace_Ped					*Ped() { return pPed; }
	CGTAVSpace_Achievments_MP		*AchievmentsMP() { return pAchievments; }
	CGTAVSpace_Tasks				*Tasks() { return pTasks; }

	enum eVVehicleTypes
	{
		BICYCLE,	// 0
		CAR,		// 1
		QUADBIKE,	// 2
		BIKE,		// 3
		BOAT,		// 4
		TRAIN,		// 5
		HELI,		// 6
		PLANE,		// 7
		AUTOGYRO,	// 8
		SUBMARINE,	// 9
		TRAILER,	// 10
		BLIMP		// 11
	};

	enum eVBlips {
		BLIP_OTHPLAYER,
		BLIP_PROPCAT,
		BLIP_PLAYER,
		BLIP_DEST,
		BLIP_COP,
		BLIP_PICK,
		BLIP_GALLERY,
		BLIP_ENEMY,
		BLIP_CAR,
		BLIP_PICK_OBJ,
		BLIP_CONT,
		BLIP_FRIEND,
		BLIP_TREV,
		BLIP_MICHAEL,
		BLIP_FRANKLIN
	};

	enum eVMapTypes {
		MAP_VISLOW,
		MAP_VISHIGH,
		MAP_GOLF,
		MAP_INTERIOR,
		MAP_CANSTARTMISS,
		MAP_CANDROPPOI,
		MAP_CANZOOM,
		MAP_WAYPOINT,
		MAP_CANWARP
	};

	enum eVPedModels {
		GTAV_MP_PLAYER
	};

	enum eVStreamerPrioritys {
		PRIO_LOWEST,
		PRIO_BELOW_NORMAL,
		PRIO_NORMAL,
		PRIO_IDLE,
		PRIO_ABOVE_NORMAL,
		PRIO_HIGHEST
	};

	enum eVMovementModeUnholsterData {
		UNHOLSTER_UNARMED,
		UNHOLSTER_2H_MELEE,
		UNHOLSTER_1H,
		UNHOLSTER_2H,
		UNHOLSTER_MINIGUN,
		UNHOLSTER_UNARMED_STEALTH,
		UNHOLSTER_2H_MELEE_STEALTH,
		UNHOLSTER_1H_STEALTH,
		UNHOLSTER_2H_STEALTH
	};

	enum eVMovementModes {
		DEFAULT_ACTION,
		MP_FEMALE_ACTION,
		MICHAEL_ACTION,
		FRANKLIN_ACTION,
		TREVOR_ACTION
	};

	enum eVWeapons {
		WEAPON_UNARMED,
		WEAPON_GRENADE,
		WEAPON_SMOKEGRENADE,
		WEAPON_STICKYBOMB,
		WEAPON_MOLOTOV,
		WEAPON_LOUDHAILER,
		WEAPON_KNIFE,
		WEAPON_NIGHTSTICK,
		WEAPON_HAMMER,
		WEAPON_CROWBAR,
		WEAPON_FLARE,
		WEAPON_BAT,
		WEAPON_GOLFCLUB,
		WEAPON_PISTOL,
		WEAPON_COMBATPISTOL,
		WEAPON_PISTOL50,
		WEAPON_APPISTOL,
		WEAPON_MICROSMG,
		WEAPON_RUBBERGUN,
		WEAPON_STUNGUN,
		WEAPON_SMG,
		WEAPON_ASSAULTSMG,
		WEAPON_ASSAULTRIFLE,
		WEAPON_CARBINERIFLE,
		WEAPON_HEAVYRIFLE,
		WEAPON_ADVANCEDRIFLE,
		WEAPON_MG,
		WEAPON_COMBATMG,
		WEAPON_ASSAULTMG,
		WEAPON_PUMPSHOTGUN,
		WEAPON_SAWNOFFSHOTGUN,
		WEAPON_BULLPUPSHOTGUN,
		WEAPON_ASSAULTSHOTGUN,
		WEAPON_SNIPERRIFLE,
		WEAPON_ASSAULTSNIPER,
		WEAPON_PROGRAMMABLEAR,
		WEAPON_HEAVYSNIPER,
		WEAPON_GRENADELAUNCHER,
		WEAPON_MINIGUN
	};

	enum eVExplosions {
		EXP_TAG_GRENADE,
		EXP_TAG_GRENADELAUNCHER,
		EXP_TAG_STICKYBOMB,
		EXP_TAG_MOLOTOV,
		EXP_TAG_ROCKET,
		EXP_TAG_TANKSHELL,
		EXP_TAG_HI_OCTANE,
		EXP_TAG_CAR,
		EXP_TAG_PLANE,
		EXP_TAG_PETROL_PUMP,
		EXP_TAG_BIKE,
		EXP_TAG_DIR_STEAM,
		EXP_TAG_DIR_FLAME,
		EXP_TAG_DIR_WATER_HYDRANT,
		EXP_TAG_DIR_GAS_CANISTER,
		EXP_TAG_BOAT,
		EXP_TAG_SHIP_DESTROY,
		EXP_TAG_TRUCK,
		EXP_TAG_BULLET,
		EXP_TAG_SMOKEGRENADELAUNCHER,
		EXP_TAG_SMOKEGRENADE,
		EXP_TAG_BZGAS,
		EXP_TAG_FLARE,
		EXP_TAG_GAS_CANISTER,
		EXP_TAG_EXTINGUISHER,
		EXP_TAG_PROGRAMMABLEAR,
		EXP_TAG_TRAIN,
		EXP_TAG_BARREL,
		EXP_TAG_PROPANE,
		EXP_TAG_BLIMP,
		EXP_TAG_DIR_FLAME_EXPLODE,
		EXP_TAG_TANKER,
		EXP_TAG_PLANE_ROCKET,
		EXP_TAG_VEHICLE_BULLET,
		EXP_TAG_GAS_TANK
	};

	enum eVMaps {
		GTA5,
		TESTBED,
		VFX_TEST,
		NM_TEST,
		NETTESTBED,
		ANIM_TEST,
		CPTESTBED,
		TOOLS_TEST,
		WATERBED,
		GFX_TEST
	};

	enum eVMotionTaskData {
		PED_ON_FOOT,
		PED_IN_WATER,
		BIRD_ON_FOOT,
		FLIGHTLESS_BIRD,
		HORSE_ON_FOOT,
		ROTTWEILER_ON_FOOT,
		RETRIEVER_ON_FOOT,
		BOAR_ON_FOOT,
		COW_ON_FOOT,
		COUGAR_ON_FOOT,
		COYOTE_ON_FOOT,
		PIG_ON_FOOT,
		RAT_ON_FOOT,
		FISH_IN_WATER,
		DEER_ON_FOOT
	};
	
	enum eVNavi {
		SECTORS_PER_NAVMESH = 3,
		SECTORS_PER_NAVNODES = 12,
		NAVMESH_LOAD_DISTANCE = 212,
		RELATIVE_THREAD_PRIORITY = 8,
		MAX_NUM_NAVMESHES_IN_ANY_LEVEL = 10099,
		MAX_NUM_AUDMESHES_IN_ANY_LEVEL = 1000,
		MAX_NUM_NAVNODES_IN_ANY_LEVEL = 400,
		MAX_NUM_DYNAMIC_NAVMESH_TYPES = 40
	};

	enum eVBrawlingStyles {
		BS_MICHAEL,
		BS_TREVOR,
		BS_FRANKLIN,
		BS_AI,
		BS_ANIMAL,
		BS_DOG,
		BS_COUGAR
	};

	enum eVPools {
		AnimatedBuilding, // Size: 210
		AttachmentExtension, // Size: 290
		BlendshapeStore, // Size: 75
		Building, // Size: 28500
		carrec, // Size: 3700
		CBoatChaseDirector, // Size: 4
		CVehicleCombatAvoidanceArea, // Size: 5
		CCargen, // Size: 750
		CCargenForScenarios, // Size: 150
		CCombatDirector, // Size: 5
		CCombatInfo, // Size: 16
		CCombatSituation, // Size: 6
		CCoverFinder, // Size: 40
		CDefaultCrimeInfo, // Size: 13
		CTacticalAnalysis, // Size: 3
		AnimStore, // Size: 9750
		CGameScriptResource, // Size: 1500
		ClothStore, // Size: 60
		CombatMeleeManager_Groups, // Size: 3
		CombatMountedManager_Attacks, // Size: 1
		CompEntity, // Size: 39
		CPrioritizedClipSetBucked, // Size: 22
		CPrioritizedClipSetRequest, // Size: 106
		CRoadBlock, // Size: 3
		CStuntJump, // Size: 64
		CScenarioInfo, // Size: 64
		CScenarioPointExtraData, // Size: 220
		CutsceneStore, // Size: 400
		CScriptEntityExtension, // Size: 150
		CVehicleChaseDirector, // Size: 4
		CVehicleClipRequestHelper, // Size: 45
		CPathNodeRouteSearchHelper, // Size: 119
		CGrabHelper, // Size: 8
		CGpsNumNodesStored, // Size: 1024
		CClimbHandHoldDetected, // Size: 16
		CAmbientLookAt, // Size: 40
		DrawableStore, // Size: 50000
		DummyObject, // Size: 8000
		DwdStore, // Size: 10650
		EntityBatch, // Size: 5000
		GrassBatch, // Size: 5000
		ExprDictStore, // Size: 190
		FrameFilterStore, // Size: 14
		FragmentStore, // Size: 4255
		GamePlayerBroadcastDataHandler_Remote, // Size: 500
		InteriorInst, // Size: 80
		InteriorProxy, // Size: 475
		IplStore, // Size: 3000
		MaxLoadedInfo, // Size: 6000
		MaxLoadRequestedInfo, // Size: 3000
		ActiveLoadedInfo, // Size: 3000
		ActivePersistentLoadedInfo, // Size: 1439
		KnownRefs, // Size: 11500
		LightEntity, // Size: 2000
		MapDataLoadedNode, // Size: 566
		MapDataStore, // Size: 4300
		MapTypesStore, // Size: 800
		MetaDataStore, // Size: 1551
		NavMeshes, // Size: 10100
		NetworkDefStore, // Size: 118
		NetworkCewDataMgr, // Size: 16
		Object, // Size: 800
		OcclusionInteriorInfo, // Size: 50
		OcclusionPortalEntity, // Size: 163
		OcclusionPortalInfo, // Size: 250
		Peds, // Size: 110
		ScenarioPedsMultiplier, // Size: 100
		AmbientPedsMultiplier, // Size: 100
		MaxTotalPeds, // Size: 100
		CWeapon, // Size: 117
		phInstGTA, // Size: 2214
		PhysicsBounds, // Size: 1450
		CPickup, // Size: 73
		CPickupPlacement, // Size: 280
		CPickupPlacementCustomScriptData, // Size: 60
		CRegenerationInfo, // Size: 56
		PedMemoryMultiplier, // Size: 500
		PedsForVehicles, // Size: 75
		PortalInst, // Size: 95
		PoseMatcherStore, // Size: 20
		PMStore, // Size: 100
		PtFxSortedEntity, // Size: 30
		PtFxAssetStore, // Size: 250
		QuadTreeNodes, // Size: 1310
		ScaleformStore, // Size: 642
		ScaleformMgrArray, // Size: 40
		ScriptStore, // Size: 780
		StaticBounds, // Size: 10520
		tcBox, // Size: 1300
		TrafficLightInfos, // Size: 84
		TxdStore, // Size: 27300
		Vehicles, // Size: 148
		VehicleAmbientDensityMultiplier, // Size: 100
		VehicleMemoryMultiplier, // Size: 300
		VehicleParkedDensityMultiplier, // Size: 100
		VehicleStreamRequest, // Size: 30
		VehicleStreamRender, // Size: 35
		VehicleStruct, // Size: 53
		VehicleUpperLimit, // Size: 60
		VehicleUpperLimitMP, // Size: 20
		VehicleKeyholeShapeInnerThickness, // Size: 50
		VehicleKeyholeShapeOuterThickness, // Size: 60
		VehicleKeyholeShapeInnerRadius, // Size: 50
		VehicleKeyholdShapeOuterRadius, // Size: 165
		VehicleKeyholdSideWallThickness, // Size: 60
		VehicleMaxCreationDistance, // Size: 225
		VehicleMaxCreationDistanceOffscreen, // Size: 50
		VehicleCullRange, // Size: 251
		VehicleCullRangeOffScreen, // Size: 100
		DensityBasedRemovalRateScale, // Size: 36
		DensityBasedRemovalTargetHeadroom, // Size: 10
		VehicleSpacing_0, // Size: 1
		VehicleSpacing_1, // Size: 172
		VehicleSpacing_2, // Size: 150
		VehicleSpacing_3, // Size: 129
		VehicleSpacing_4, // Size: 110
		VehicleSpacing_5, // Size: 88
		VehicleSpcaing_6, // Size: 55
		VehicleSpacing_7, // Size: 52
		VehicleSpacing_8, // Size: 45
		VehicleSpacing_9, // Size: 40
		VehicleSpacing_10, // Size: 34
		VehicleSpacing_11, // Size: 27
		VehicleSpacing_12, // Size: 22
		VehicleSpacing_13, // Size: 20
		VehicleSpcaing_14, // Size: 19
		VehicleSpacing_15, // Size: 18
		PlayersRoadScanDistance, // Size: 300
		PlayerRoadDensityInc_0, // Size: 0
		PlayerRoadDensityInc_1, // Size: 0
		PlayerRoadDensityInc_2, // Size: 0
		PlayerRoadDensityInc_3, // Size: 0
		PlayerRoadDensityInc_4, // Size: 0
		PlayerRoadDensityInc_5, // Size: 0
		PlayerRoadDensityInc_6, // Size: 0
		PlayerRoadDensityInc_7, // Size: 0
		PlayerRoadDensityInc_8, // Size: 0
		PlayerRoadDensityInc_9, // Size: 0
		PlayerRoadDensityInc_10, // Size: 0
		PlayerRoadDensityInc_11, // Size: 0
		PlayerRoadDensityInc_12, // Size: 0
		PlayerRoadDensityInc_13, // Size: 0
		PlayerRoadDensityInc_14, // Size: 0
		PlayerRoadDensityInc_15, // Size: 0
		NonPlayerRoadDensityDec_1, // Size: 0
		NonPlayerRoadDensityDec_2, // Size: 0
		NonPlayerRoadDensityDec_3, // Size: 1
		NonPlayerRoadDensityDec_4, // Size: 1
		NonPlayerRoadDensityDec_5, // Size: 1
		NonPlayerRoadDensityDec_6, // Size: 1
		NonPlayerRoadDensityDec_7, // Size: 2
		NonPlayerRoadDensityDec_8, // Size: 2
		NonPlayerRoadDensityDec_9, // Size: 2
		NonPlayerRoadDensityDec_10, // Size: 2
		NonPlayerRoadDensityDec_11, // Size: 2
		NonPlayerRoadDensityDec_12, // Size: 3
		NonPlayerRoadDensityDec_13, // Size: 3
		NonPlayerRoadDensityDec_14, // Size: 3
		NonPlayerRoadDensityDec_15, // Size: 3
		VehiclePopulationFrameRate, // Size: 25
		VehiclePopulationCyclesPerFrame, // Size: 1
		wptrec, // Size: 768
		fwLodNode, // Size: 12500
		CTask, // Size: 1450
		CEvent, // Size: 500
		CMoveObject, // Size: 112
		CMoveAnimatedBuilding, // Size: 161
		atDScriptObjectNode, // Size: 450
		fwDynamicArchetypeComponent, // Size: 6830
		fwDynamicEntityComponent, // Size: 1000
		fwEntityContainer, // Size: 615
		fwMatrixTransform, // Size: 1536
		fwQuaternionTransform, // Size: 12958
		fwSimpleTransform, // Size: 30720
		ScenarioCarGensPerRegion, // Size: 80
		ScenarioPointsAndEdgesPerRegion, // Size: 1000
		ScenarioPoint, // Size: 900
		ScenarioPointEntity, // Size: 350
		ScenarioPointWorld, // Size: 1400
		MaxNonRegionScenarioPointSpatialObjects, // Size: 900
		ObjectIntelligence, // Size: 37
		VehicleScenarioAttractors, // Size: 64
		AircraftFlames, // Size: 34
		CScenarioPointChainUseInfo, // Size: 76
		CScenarioClusterSpawnedTrackingData, // Size: 190
		CSPClusterFSMWrapper, // Size: 192
		fwArchetypePooledMap, // Size: 36497
		CTaskConversationHelper, // Size: 4
		SyncedScenes, // Size: 10
		CPropManagementHelper, // Size: 77
		ActionTable_Definitions, // Size: 271
		ActionTable_Results, // Size: 426
		ActionTable_Impulses, // Size: 20
		ActionTable_Interrelations, // Size: 60
		ActionTable_Homings, // Size: 156
		ActionTable_Damages, // Size: 21
		ActionTable_StrikeBones, // Size: 15
		ActionTable_Rumbles, // Size: 5
		ActionTable_Branches, // Size: 15
		ActionTable_StealthKills, // Size: 10
		ActionTable_Vfx, // Size: 30
		ActionTable_FacialAnimSets, // Size: 5
		NetworkEntityAreas, // Size: 64
		NavMeshRoute // Size: 113
	};

	enum eVPADStates {
		PAD_RSTICK_DOWN,
		PAD_RSTICK_UP,
		PAD_RSTICK_LEFT,
		PAD_DPAD_NONE,
		PAD_DPAD_UPDOWN,
		PAD_DPAD_ALL,
		PAD_LSTICK_DOWN,
		PAD_LSTICK_UP,
		PAD_LSTICk_LEFT,
		PAD_DPAD_DOWN,
		PAD_DPAD_UP,
		PAD_LSTICK_ALL,
		PAD_DPAD_LEFT,
		PAD_DPAD_RIGHT,
		PAD_RSTICK_ALL,
		PAD_RSTICK_NONE,
		PAD_LSTICK_RIGHT,
		PAD_RSTICK_ROTATE,
		PAD_LSTICK_NONE,
		PAD_RSTICK_UPDOWN,
		PAD_LSTICK_UPDOWN,
		PAD_LSTICK_ROTATE,
		PAD_DPAD_LEFTRIGHT,
		PAD_RSTICK_LEFTRIGHT,
		PAD_RSTICK_RIGHT,
		PAD_LSTICK_LEFTRIGHT
	};

	enum eVMenuIDs {
		MENU_UNIQUE_ID_SETTINGS_CAMERA,
		MENU_UNIQUE_ID_HOME_NEWSWIRE,
		MENU_UNIQUE_ID_CUTSCENE_EMPTY,
		MENU_UNIQUE_ID_REPLAY_RANDOM,
		MENU_UNIQUE_ID_SETTINGS_SIXAXIS,
		MENU_UNIQUE_ID_INCEPT_TRIGGER,
		MENU_UNIQUE_ID_BETTING_LOBBYLIST,
		MENU_UNIQUE_ID_BETTING_INFOLIST,
		MENU_UNIQUE_ID_BETTING,
		MENU_UNIQUE_ID_HEADER_BETTING,
		MENU_UNIQUE_ID_RACE_LOBBYLIST,
		MENU_UNIQUE_ID_RACE_INFOLIST,
		MENU_UNIQUE_ID_RACE_INFO,
		MENU_UNIQUE_ID_HEADER_RACE,
		MENU_UNIQUE_ID_CREW_REQUEST,
		MENU_UNIQUE_ID_HOME_OPEN_JOBS,
		MENU_UNIQUE_ID_CREW_LEADERBOARDS,
		MENU_UNIQUE_ID_CORONA_INVITE_LAST_JOB_PLAYERS,
		MENU_UNIQUE_ID_CORONA_INVITE_MATCHED_PLAYERS,
		MENU_UNIQUE_ID_HEADER_CORONA_INVITE_LAST_JOB_PLAYERS,
		MENU_UNIQUE_ID_HEADER_CORONA_INVITE_MATCHED_PLAYERS,
		MENU_UNIQUE_ID_CORONA_JOINED_LIST,
		MENU_UNIQUE_ID_CORONA_INVITE_LIST,
		MENU_UNIQUE_ID_CORONA_DETAILS_LIST,
		MENU_UNIQUE_ID_CORONA_SETTINGS_LIST,
		MENU_UNIQUE_ID_HEADER_JOINING_SCREEN,
		MENU_UNIQUE_ID_SETTINGS_FACEBOOK,
		MENU_UNIQUE_ID_CORONA_INVITE_CREWS,
		MENU_UNIQUE_ID_CORONA_INVITE_FRIENDS,
		MENU_UNIQUE_ID_CORONA_INVITE_PLAYERS,
		MENU_UNIQUE_ID_CORONA_JOINED_PLAYERS,
		MENU_UNIQUE_ID_HEADER_CORONA_INVITE_CREWS,
		MENU_UNIQUE_ID_HEADER_CORONA_INVITE_FRIENDS,
		MENU_UNIQUE_ID_HEADER_CORONA_INVITE_PLAYERS,
		MENU_UNIQUE_ID_HEADER_CORONA_JOINED_PLAYERS,
		MENU_UNIQUE_ID_HEADER_CORONA_LOBBY,
		MENU_UNIQUE_ID_HEADER_CORONA,
		MENU_UNIQUE_ID_LOBBY_LIST_ITEM,
		MENU_UNIQUE_ID_LOBBY_LIST,
		MENU_UNIQUE_ID_HEADER_TEXT_SELECTION,
		MENU_UNIQUE_ID_BRIGHTNESS_CALIBRATION,
		MENU_UNIQUE_ID_GALLERY_OPTIONS_LIST,
		MENU_UNIQUE_ID_GALLERY_OPTIONS,
		MENU_UNIQUE_ID_SETTINGS_FEED,
		MENU_UNIQUE_ID_HEADER_EMPTY,
		MENU_UNIQUE_ID_HOME_DIALOG,
		MENU_UNIQUE_ID_TEAM_SELECT,
		MENU_UNIQUE_ID_FRIENDS_MP,
		MENU_UNIQUE_ID_FRIENDS_OPTIONS_LIST,
		MENU_UNIQUE_ID_CREW_OPTIONS_LIST,
		MENU_UNIQUE_ID_CREW_OPTIONS,
		MENU_UNIQUE_ID_PARTY_OPTIONS_LIST,
		MENU_UNIQUE_ID_PARTY_OPTIONS,
		MENU_UNIQUE_ID_PLAYERS_OPTIONS_LIST,
		MENU_UNIQUE_ID_PLAYERS_OPTIONS,
		MENU_UNIQUE_ID_PLAYERS_LIST,
		MENU_UNIQUE_ID_CREATION_LIFESTYLE_LIST,
		MENU_UNIQUE_ID_CREATION_HERITAGE_LIST,
		MENU_UNIQUE_ID_CREW,
		MENU_UNIQUE_ID_REPLAY_MISSION_ACTIVITY,
		MENU_UNIQUE_ID_REPLAY_MISSION_LIST,
		MENU_UNIQUE_ID_REPLAY_MISSION,
		MENU_UNIQUE_ID_PARTY_LIST,
		MENU_UNIQUE_ID_CREATION_YOU,
		MENU_UNIQUE_ID_CREATION_LIFESTYLE,
		MENU_UNIQUE_ID_CREATION_HERITAGE,
		MENU_UNIQUE_ID_HEADER_MP_CHARACTER_CREATION,
		MENU_UNIQUE_ID_HEADER_MP_CHARACTER_SELECT,
		MENU_UNIQUE_ID_FRIENDS_OPTIONS,
		MENU_UNIQUE_ID_FRIENDS_LIST,
		MENU_UNIQUE_ID_MISSION_CREATOR_STAT,
		MENU_UNIQUE_ID_MISSION_CREATOR_LISTITEM,
		MENU_UNIQUE_ID_MISSION_CREATOR_CATEGORY,
		MENU_UNIQUE_ID_CREW_LIST,
		MENU_UNIQUE_ID_CREW_INVITES,
		MENU_UNIQUE_ID_CREW_FRIENDS,
		MENU_UNIQUE_ID_CREW_ROCKSTAR,
		MENU_UNIQUE_ID_CREW_MINE,
		MENU_UNIQUE_ID_STATS_LISTITEM,
		MENU_UNIQUE_ID_SPECTATOR,
		MENU_UNIQUE_ID_CREWS_CARD,
		MENU_UNIQUE_ID_CREWS_FILTER,
		MENU_UNIQUE_ID_CREWS_CATEGORY,
		MENU_UNIQUE_ID_MAP_LEGEND,
		MENU_UNIQUE_ID_SAVE_GAME_LIST,
		MENU_UNIQUE_ID_SETTINGS_LIST,
		MENU_UNIQUE_ID_STATS_CATEGORY,
		MENU_UNIQUE_ID_PLACEHOLDER,
		MENU_UNIQUE_ID_LOBBY,
		MENU_UNIQUE_ID_PARTY,
		MENU_UNIQUE_ID_HEADER_LOBBY,
		MENU_UNIQUE_ID_HEADER_PRE_LOBBY,
		MENU_UNIQUE_ID_LEAVE_GAME,
		MENU_UNIQUE_ID_GAME_MP,
		MENU_UNIQUE_ID_MISSION_CREATOR,
		MENU_UNIQUE_ID_HEADER_MY_MP,
		MENU_UNIQUE_ID_HEADER_MULTIPLAYER,
		MENU_UNIQUE_ID_MP_CHAR_5,
		MENU_UNIQUE_ID_MP_CHAR_4,
		MENU_UNIQUE_ID_MP_CHAR_3,
		MENU_UNIQUE_ID_MP_CHAR_2,
		MENU_UNIQUE_ID_MP_CHAR_1,
		MENU_UNIQUE_ID_FREEMODE,
		MENU_UNIQUE_ID_GALLERY_ITEM,
		MENU_UNIQUE_ID_SETTINGS_SAVEGAME,
		MENU_UNIQUE_ID_CREWS,
		MENU_UNIQUE_ID_HOME,
		MENU_UNIQUE_ID_HEADER_SAVE_GAME,
		MENU_UNIQUE_ID_HEADER,
		MENU_UNIQUE_ID_SAVE_GAME,
		MENU_UNIQUE_ID_LOAD_GAME,
		MENU_UNIQUE_ID_NEW_GAME,
		MENU_UNIQUE_ID_SETTINGS_CONTROLS,
		MENU_UNIQUE_ID_SETTINGS_DISPLAY,
		MENU_UNIQUE_ID_SETTINGS_AUDIO,
		MENU_UNIQUE_ID_HOME_FEED,
		MENU_UNIQUE_ID_HOME_BRIEF,
		MENU_UNIQUE_ID_HOME_HELP,
		MENU_UNIQUE_ID_STORE,
		MENU_UNIQUE_ID_CORONA_INVITE,
		MENU_UNIQUE_ID_CORONA_SETTINGS,
		MENU_UNIQUE_ID_HOME_MISSION,
		MENU_UNIQUE_ID_LOST,
		MENU_UNIQUE_ID_COPS,
		MENU_UNIQUE_ID_VAGOS,
		MENU_UNIQUE_ID_AVAILABLE,
		MENU_UNIQUE_ID_STATS,
		MENU_UNIQUE_ID_MEDALS,
		MENU_UNIQUE_ID_WEAPONS,
		MENU_UNIQUE_ID_PLAYERS,
		MENU_UNIQUE_ID_SETTINGS,
		MENU_UNIQUE_ID_GAME,
		MENU_UNIQUE_ID_SOCIALCLUB,
		MENU_UNIQUE_ID_GALLERY,
		MENU_UNIQUE_ID_FRIENDS,
		MENU_UNIQUE_ID_INFO,
		MENU_UNIQUE_ID_START,
		MENU_UNIQUE_ID_MAP,
		MENU_UNIQUE_ID_INVALID,
	};

	enum eVScriptVMNatives {
		SET_PLAYER_ARMOUR,
		SET_PLAYER_HEALTH,
		REMOVE_SAVING,
		SET_DISPLAY_CONFIG,
		SET_MINIMAP_VISIBLE_STATE,
		SET_HELPTEXT_HEIGHT,
		SET_IMPORTANT_PARAMS,
		REMOVE_HUD_ITEM,
		MULTIPLAYER_IS_ACTIVE,
		FLASH_HEALTH_BAR,
		SET_CHARACTER_COLOUR,
		SET_ABILITY_BAR,
		FLASH_ABILITY_BAR,
		BLINK_ABILITY_BAR,
		SET_AIR_BAR,
		OVERRIDE_COMPONENT_POSITION,
		SHOW_STALL_WARNIG,
		TOGGLE_COMPONENT,
		FLASH_MINIMAP,
		GET_ASSET_ARRAY,
		REGISTER_HEALTH_ARMOUR,
		REGISTER_MAP_LAYER,
		STOP_BLIP_FLASHING,
		START_BLIP_FLASHING,
		SHOW_AIRCRAFT_COMPONENTS,
		GOLF_LINK,
		SHUTDOWN_MOVIE,
		SET_DATA_SLOT_EMPTY,
		SET_INPUT_EVENT_CROSS,
		SET_INPUT_EVENT_CIRCLE,
		GET_CURRENT_COLOUMN,
		SET_INPUT_EVENT,
		GET_CURRENT_SELECTION,
		HIDE_BUTTONS,
		HAS_NO_MEMBERS,
		STOP_FLASHING_WANTED_OVERLAY,
		FLASH_WANTED_OVERLAY,
		IS_WAYPOIT_SET,
		GET_CURRENT_END_INDEX,
		GET_CURRENT_START_INDEX,
		SET_INPUT_EVENT_TRIANGLE,
		FADE_TO_BLACK,
		HIGHLIGHT_ITEM,
		SET_ANALOG_STICK_INPUT,
		TXT_ALREADY_LOADED,
		RESTART_MOVIE,
		PAUSE_MENU_SP_CONTENT,
		SET_COLUMN_TITLE,
		SET_SAVING_TEXT,
		REMOVE_STREAM_COMPONENT,
		SET_STREAM_COMPONENT,
		SET_COMPONENT_VALUES,
		SET_COMPONENT_POSITION,
		SELECT_RADIO_STATION,
		SET_PLAYER_WEAPON_WHEEL,
		SET_POITER,
		START_CROSSFADE,
		SET_STATS_VISIBILITY,
		PM_RANGE,
		PM_ACCURACY,
		PM_FIRERATE,
		PM_DAMAGE,
		SET_STATS_LABLES_AND_VALUES,
		SET_ATTACHMENTS,
		NO_ATTACHMENST,
		GET_CURRENT_WEAPON_WHEEL_HASH,
		SET_WEAPON_WHEEL_ACTIVE,
		UNLOAD_WEAPON_WHEEL_STATS,
		UNLOAD_WEAPON_WHEEL,
		SET_RETICLE_VISIBLE,
		SHOW_HITMARKER,
		SET_SATNAV_DIRECTION,
		HIDE_SATNAV,
		HIDE_DEPTH,
		SET_SATNAV_DISTANCE,
		SET_SATNAV_AREA,
		SET_DEPTH,
		SHOW_DEPTH,
		SET_BACKGROUND_COLOURS,
		DRAW_INSTRUCTIONAL_BUTTONS,
		SET_DATA_SLOT,
		SET_CLEAR_SPACE,
		DISPLAY_DATA_SLOT,
		SET_STATUS_COLOURS,
		STORE_FREE_PRICE, // maybe at the hair cut studio

		// Ui menu selector ADD_COLUMN,
		REMOVE_COLUMN,
		STORE_NO_CONTENT,

		DISPLAY_ERROR_MESSAGE,
		SET_LANGUAGES,
		SET_CONTEXT_SLOT,
		SHOW_CONTEXT_MENU,
		CONTROLLER_LABLES,
		SET_CONTROL_LABLS,
		INIT_COLUMN_SCROLL,
		UPDATE_SLOT,
		BEGI_RESTART_PAUSE_MENU,
		SET_HEADING_DETAILS,
		SET_CHAR_IMG,
		SET_CREW_IMG,
		SET_ALL_HIGHLIGHTS,
		SET_MENU_HEADER_TEXT_BY_INDEX,
		SET_MENU_ITEM_COLOUR,
		SET_DIMMABLE,
		BUILD_MENU_GFX_FILES,
		BUILD_MENU,
		SHOW_HEADIG_DETAILS,
		SET_HEADER_TITLE,
		LOAD_CHILD_PAGE,
		SET_CONTENT_SCALED,
		MENU_SHIFT_DEPTH,
		SET_TITLE,
		SET_COLUMN_HIGHLIGHT,
		SET_COLUMN_FOCUS,
		SHOW_COLUMN,
		SET_COLUMN_SCROLL,
		SHOW_WARNING_MESSAGE,
		SCROLL_POLICY_TEXT,

		// To be continued 
		// .rdata:82019224 00000026 C SET_WELCOME_FALLBACK_IMAGE_VISIBILITY
	};

	enum eVDelays {
		FEED_DELAY_1HOUR,
		FEED_DELAY_30MIN,
		FEED_DELAY_15MIN,
		FEED_DELAY_4MIN,
		FEED_DELAY_10MIN,
		FEED_DELAY_5MIN,
		FEED_DELAY_3MIN,
		FEED_DELAY_2MIN,
		FEED_DELAY_1MIN,
		FEED_NO_DELAY
	};

	enum eVPCards {
		PCARD_SEND_INVT_TITLE,
		PCARD_ONLINE_OTHER,
		PCARD_ONLINE_SP,
		PCARD_ONLINE_MP,
		PCARD_ONLINE_SES,
		PCARD_NEVER_PLAYED_SP,
		PCARD_JOIN_CREW,
		PCARD_UPDATE_SC,
		PCARD_JOIN_SC,
		PCARD_INVITE_CREW_ALT,
		PCARD_INVITE_CREW,
		PCARD_NO_CREW,
		PCARD_CREW_INVITE,
		PCARD_SYNCING_STATS,
		PCARD_NEVER_PLAYED_MP,
		PCARD_SYNC_ERROR,
		PCARD_SEND_INVT_TEXT
	};

	enum eVErrors {
		ERROR_NO_SC,
		ERROR_UPDATE_SC,
		ERROR_GAL_HDR,
		ERROR_EMPTY_,
		ERROR_EMPTY_TITLE,
		ERROR_PROFANITY_HEADER,
		ERROR_FAILEDPROFANITY,
		ERROR_DEL_HDR,
		ERROR_DELTE,
		ERROR_PROFILESETTIGNS_FACEBOOK,
		ERROR_FB_HEADER,
		ERROR_FACEBOOK,
	};

	enum eVCorona {
		CORONA_INVITE_LAST_JOB_PLAYERS,
		CORONA_INVITE_MATCHED_PLAYERS,
		CORONA_INVITE_JOINED,
		CORONA_INVITE_PLAYERS,
		CORONA_INVITE_FRIENDS,
		CORONA_INVITE_CREWS
	};

	enum eVPoliceScanner {
		SUSPECT_IN_CUSTODY,
		SUSPECT_DOWN,
		POLICE_SCANNER_CONJUNCTIVES_FOR,
		INSTRUCTIONS_DISPATH_TO,
		POLICE_CAR_NUMBER,
		POLICE_CAR_NAME,
		POLICE_SCANNER_RANDOM_CHAT,
		POLICE_SCANNER_A,
		POLICE_SCANNER_IN,
		POLICE_SCANNER_ON_SHORT,
		POLICE_SCANNER_ON_FOOT,
		POLICE_SCANNER_LAST_SEEN,
		POLICE_SCANNER_SUSPECT,
		POLICE_SCANNER_NEAR_DIR_PERCENTs,
		POLICE_SCANNER_CONJUNCTIVES_NEAR,
		POLICE_SCANNER_CONJUNCTIVES_AT,
		NORTH_OF_UHM,
		EAST_OF_UHM,
		SOUTH_OF_UHM,
		WEST_OF_UHM,
		POLICE_SCANNER_IN_DIRECTION,
		IN_CENTRAL,
		NORTHERN,
		EASTERN,
		SOUTHERN,
		WESTERN,
		NORTH,
		EAST,
		SOUTH,
		WEST,
		PERCENTDOT2i_SCANNER_VOICE_PARAMS,
		POLICE_SCANNER_COLOUR_FUCKED,
		CRIME_AMBIENT_MEDICAL_EVENT,
		CRIME_AMBIENT_FIRE,
		POLICE_SCANNER_ASSISTANCE_REQUIRED_ASSISTANCE_REQUIRED,
	};

	enum eVEVents {
		CEventShockingCarChase,
		CEventShockingCarCrash,
		CEventShockingBicycleCrash,
		CEventShockingCarPileUp,
		CEventShockingCarOnCar,
		CEventShockingDangerousAnimal,
		CEventShockingDeadBody,
		CEventShockingDrivingOnPavement,
		CEventShockingBicycleOnPavement,
		CEventShockingEngineRevved,
		CEventShockingExplosion,
		CEventShockingFire,
		CEventShockingGunFight,
		CEventShockingGunshotFired,
		CEventShockingHelicopterOverhead,
		CEventShockingParachuterOverhead,
		CEventShockingHornSounded,
		CEventShockingInjuredPed,
		CEventShockingInDangerousVehicle,
		CEventShockingMadDriver,
		CEventShockingMadDriverExtreme,
		CEventShockingMadDriverBicycle,
		CEventShockingMugging,
		CEventShockingPedKnockedIntoByPlayer,
		CEventShockingPedRunOver,
		CEventShockingPedShot,
		CEventShockingPlaneFlyby,
		CEventShockingPotentialBlast,
		CEventShockingPropertyDamage,
		CEventShockingRunningPed,
		CEventShockingRunningStampede,
		CEventShockingSeenCarStolen,
		CEventShockingSeenConfrontation,
		CEventShockingSeenGangFight,
		CEventShockingSeenInsult,
		CEventShockingSeenMeleeAction,
		CEventShockingSeenNiceCar,
		CEventShockingSeenPedKilled,
		CEventShockingSiren,
		CEventShockingCarAlarm,
		CEventShockingStudioBomb,
		CEventShockingVehicleTowed,
		CEventShockingWeaponThreat,
		CEventShockingVisibleWeapon,
		CEventShockingWeirdPed,
		CEventShockingWeirdPedApproaching,
		CEventShockingNonViolentWeaponAimedAt
	};

	enum eVDTs {
		DT_ArmyVehicle,
		DT_PoliceBoat,
		DT_SwatHelicopter,
		DT_Gangs,
		DT_PoliceAutomobileWaitCruising,
		DT_PoliceAutomobileWaitPulledOver,
		DT_PoliceRoadBlock,
		DT_PoliceVehicleRequest,
		DT_PoliceRiders,
		DT_AmbulanceDepartment,
		DT_SwatAutomobile,
		DT_FireDepartment,
		DT_PoliceHelicopter,
		DT_PoliceAutomobile,
		DT_Invalid
	};

	enum eVCopSees {
		COP_SEES_WEAPON,
		COP_SEES_GUN,
		COP_SEES_MINI_GUN,
		COP_SEES_GRENADE,
		COP_SEES_GRENADE_LAUNCHER,
		COP_SEES_ROCKET_LAUNCHER
	};

	enum eVCMS {
		CSM_ST_CLOUDS_DITHER2_LINEAR,
		CSM_ST_CLOUDS_BOX4x4,
		CSM_ST_CLOUDS_BOX3x3,
		CSM_ST_CLOUDS_TWOTAP,
		CSM_ST_CLOUDS_LINEAR,
		CSM_ST_CLOUDS_SIMPLE,
		CSM_ST_HIGHRES_BOX4x4,
		CSM_ST_SOFT16,
		CSM_ST_DITHER16,
		CSM_ST_DITHER4,
		CSM_ST_CUBIC,
		CSM_ST_DITHER2_LINEAR,
		CSM_ST_BOX4x4,
		CSM_ST_BOX3x3,
		CSM_ST_TWOTAP,
		CSM_ST_LINEAR,
		CSM_ST_POINT
	};

	enum eVDLs {
		DL_BEGIN_DRAW,
		DL_DEBUG,
		DL_MIRROR_REFLECTION,
		DL_RAIN_COLLISION_MAP,
		DL_RAIN_UPDATE,
		DL_PLAYER_SETTINGS,
		DL_PED_DAMAGE_GEN,
		DL_CLOUD_GEN,
		DL_HEIGHT_MAP,
		DL_PREAMBLE,
		DL_FRONTEND,
		DL_HUD,
		DL_PHONE,
		DL_SEETHROUGH_MAP,
		DL_REFLECTION_MAP,
		DL_WATER_SURFACE,
		DL_TREE,
		DL_SCRIPT,
		DL_TIMEBARS,
		DL_PRE_RENDER_VP,
		DL_RADAR,
		DL_LIGHTING
	};

	enum eVSGStates {
		SG_RPT_SAVES,
		SG_PH_SV_CL_FL,
		SG_PH_LD_CL_FL,
		SG_PH_LS_CL_FL,
		SG_DEL_C_FAIL,
		SG_DEL_FAIL,
		SG_ALD_DAM,
		SG_ALD_SIGN_AGN,
		SG_ALD_SIGNIN,
		SG_VERS_ERR,
		SG_FILENAME_DUP,
		SG_FILENAME_ERR,
		SG_TOOMANYFILES,
		SG_SAVEOVR_SURE,
		SG_SAVE_OVRWRT,
		SG_SAVE_OVRWRT2,
		SG_LOAD_OVRWRT,
		SG_AUTO_OFF,
		SG_AUTOOFF_SURE,
		SG_AUTO_FAILED,
		SG_AUTO_SL_OVR,
		SG_AUTO_SL_OVR2,
		SG_DEV_REM,
		SG_CHKLOAD_FAIL,
		SG_BUFFSIZE_DIF,
		SG_NOT_CREATOR,
		SG_BGNLOAD_FAIL,
		SG_CHKTIME_FAIL,
		SG_BGNTIME_FAIL,
		SG_CHKSAVE_FAIL,
		SG_ENUM_FAILED,
		SG_DEL_LST_FAIL,
		SG_SPCHK_FAILED,
		SG_DEV_SEL_FAIL,
		SG_NO_SPCE_360,
		SG_SPACE_360,
		SG_SEL_DEV_AGN,
		SG_DEVICE_REM,
		SG_DEV_REM_AUTO,
		SG_SGN_SV_RPT_A,
		SG_SIGNIN_AGN,
		SG_SIGNIN_ATSV,
		SG_SGN_SV_RPT,
		SG_SIGNIN_SV,
		SG_SIGNIN
	};

	enum eVBasicPedTasks {
		GC_COMBAT_TASK,
		GC_LOCAL_PLAYER,
		GC_SITTING,
		GC_WALKING,
		GC_VEHICLE_PASSENGER,
		GC_VEHICLE_DRIVER,
		GC_OBJECT_RIGHT_HAND,
		GC_OBJECT_LEFT_HAND,
		GC_CONVERSATION_HANGOUT, GC_CONVERSATION_PHONE,
		GC_DEFAULT
	};

	enum eVGameEvents {
		START_PROJECTILE_EVENT,
		SET_LOOK_AT_ENTITY,
		SET_TASK_VEHICLE_TEMP_ACTION,
		REQUEST_CONTROL_EVENT,
		GIVE_CONTROL_EVENT,
		WEAPON_DAMAGE_EVENT,
		REQUEST_PICKUP_EVENT,
		GAME_CLOCK_EVENT,
		GAME_WEATHER_EVENT,
		RESPAWN_PLAYER_PED_EVENT,
		GIVE_WEAPON_EVENT,
		REMOVE_WEAPON_EVENT,
		REMOVE_ALL_WEAPONS_EVENT,
		VEHICLE_COMPONENT_CONTROL_EVENT,
		REQUEST_FIRE_EVENT,
		CONFIRM_FIRE_EVENT,
		ALTER_WANTED_LEVEL_EVENT,
		CHANGE_RADIO_STATION_EVENT,
		RAGDOLL_REQUEST_EVENT,
		PLAYER_TAUNT_EVENT,
		PLAYER_CARD_STAT_EVENT,
		PED_CONVERSATION_LINE_EVENT,
		DOOR_BREAK_EVENT, SCRIPTED_GAME_EVENT,
		REMOTE_SCRIPT_LEAVE_EVENT,
		MARK_AS_NO_LONGER_NEEDED_EVENT,
		SCRIPT_WORLD_STATE_EVENT,
		INCIDENT_ENTITY_EVENT,
		CLEAR_AREA_EVENT,
		REQUEST_NETWORK_SYNCED_SCENE_EVENT,
		START_NETWORK_SYNCED_SCENE_EVENT,
		STOP_NETWORK_SYNCED_SCENE_EVENT,
		UPDATE_NETWORK_SYNCED_SCENE_EVENT,
		GIVE_PED_SCRIPTED_TASK_EVENT,
		CLEAR_PED_TASKS_EVENT,
		START_NETWORK_PED_ARREST_EVENT,
		START_NETWORK_PED_UNCUFF_EVENT,
		NETWORK_CAR_HORN_EVENT,
		NETWORK_ENTITY_AREA_STATUS_EVENT,
		NETWORK_GARAGE_OCCUPIED_STATUS_EVENT,
		SCRIPT_ENTITY_STATE_CHANGE_EVENT,
		PLAY_SOUND_EVENT,
		STOP_SOUND_EVENT,
		BANK_REQUEST_EVENT,
		REQUEST_DOOR_EVENT,
		NETWORK_TRAIN_REQUEST_EVENT,
		NETWORK_TRAIN_REPORT_EVENT,
		MODIFY_VEHICLE_LOCK_WORLD_STATE_DATA_EVENT,
		NETWORK_INCREMENT_STAT_EVENT,
		REQUEST_PHONE_EXPLOSION_EVENT,
		REQUEST_RADIO_STATION_DATA_EVENT,
		KICK_VOTES_EVENT,
		NETWORK_GIVE_PICKUP_REWARD_EVENT,
		NETWORK_CRC_HASH_CHECK_EVENT,
		BLOW_UP_VEHICLE_EVENT,
		NETWORK_SPECIAL_FIRE_EQUIPPED_WEAPON,
		NETWORK_RESPONDED_TO_THREAD_EVENT,
		DESTROYING_EVENT,
		REMOTE_SCRIPT_INFO_EVENT,
		CONVERT_TO_SCRIPT_ENTITY_EVENT,
		SCRIPT_DATA_VERIFY_EVENT,
		REQUEST_MAP_PICKUP_EVENT,
		GIVE_PED_SEQUENCE_TASK_EVENT,
		EXPLOSION_EVENT,
		GIVE_PICKUP_REWARDS_EVENT,
		MODIFY_VEHICLE_LOCK_WORD_STATE_DATA_EVENT,
		NETWORK_BANK_REQUEST_EVENT,
		NETWORK_STOP_SOUND_EVENT,
		NETWORK_PLAY_SOUND_EVENT,
		NETWORK_SOUND_CAR_HORN_EVENT,
		NETWORK_START_PED_UNCUFF_EVENT,
		NETWORK_START_PED_ARREST_EVENT,
		NETWORK_CLEAR_PED_TASKS_EVENT,
		NETWORK_STOP_SYNCED_SCENE_EVENT,
		NETWORK_UPDATE_SYNCED_SCENE_EVENT,
		NETWORK_START_SYNCED_SCENE_EVENT,
		NETWORK_REQUEST_SYNCED_SCENE_EVENT,
		WEATHER_EVENT,
		CLOCK_EVENT,
		SCRIPT_ARRAY_DATA_VERIFY_EVENT
	};

	enum eVSupportedFormats {
		GSM,
		SD2,
		MPG4,
		MP4,
		MP2,
		MPEG,
		VFW,
		AVI,
		MOV,
		MP3,
		ULW,
		SND,
		AIFC,
		AIFF,
		AIF,
		WAV,
		BIK
	};

	enum eVThreads {
		THREAD_VOICECHAT_WORKER, // [RAGE] VoiceChat Worker
		THREAD_NETPOOL_1, // [RAGE] netThreadPool 1
		THREAD_NETPOOL_2, // [RAGE] netThreadPool 2
		THREAD_NETTCP_WORKER, // [RAGE] netTcp Worker 
		THREAD_ACHIEVEMENT_WORKER, // [RAGE] rlAchievement Worker 
		THREAD_RENDERTHREAD, // [RAGE] RenderThread 
		THREAD_DVDREADER, // [RAGE] DVD Reader 
		THREAD_HDDREADER, // [RAGE] HDD Reader 
		THREAD_DVDSTREAMER, // [RAGE] DVD Streamer 
		THREAD_HDDSTREAMER // [RAGE] HDD Streamer
	};
};

#endif