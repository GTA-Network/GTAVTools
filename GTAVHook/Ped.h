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

class CGTAVSpace_Ped {
public:

	enum eVPedPersonalities {
		Default,
		MICHAEL,
		FRANKLIN,
		TREVOR,
		Streamed_Male,
		Streamed_Male_Gang,
		Default_Female,
		Streamed_Female,
		Biker,
		Female_Biker,
		MP_F_Freemode,
		Vagos,
		Female_Vagos,
		Family,
		Female_Family,
		Marabunte,
		Female_Marabunte,
		Ballas,
		Female_Ballas,
		Weicheng,
		Female_Weicheng,
		SECURITY,
		MERRYWEATHER,
		ARMY,
		swat,
		Animal,
		ANIMAL_BIG,
		Fish,
		Rat,
		rottweiler,
		COUGAR,
		GULL,
		Mission,
		HILLBILLY,
		police,
		POLICE_FEMALE,
		PrisonGuard,
		Prisoner,
		Shark,
		CONSTRUCTION,
		BumsMale,
		BumsFemale,
		MethHead,
		MuscleMan,
		MuscleWoman,
		Hookers,
		FitnessMale,
		FitnessFemale,
		ServiceMales,
		ServiceFemales,
		Trucker,
		LifeguardFemale,
		CriminalMale,
		CriminalFemale,
		GeneralMale,
		GeneralFemale,
		SaltonMale,
		SaltonFemale,
		YoungPoorWoman,
		YoungPoorMan,
		YoungAverageToughWoman,
		YoungAverageToughMan,
		YoungAverageWeakWoman,
		YoungAverageWeakMan,
		YoungRichWoman,
		YoungRichMan,
		MediumPoorWoman,
		MediumPoorMan,
		MediumAverageWoman,
		MediumAverageMan,
		MediumRichWoman,
		MediumRichMan,
		OldPoorWoman,
		OldPoorMan,
		OldMediumWoman,
		OldMediumMan,
		OldRichWoman,
		OldRichMan,
		CULT
	};

	enum eVPedVariations {
		PED_MICHAEL_HAIR_000_1 = 1,
		PED_MICHAEL_HAIR_000_2 = 2,
		PED_MICHAEL_HAIR_002_1 = 3

		// To be continued..
	};
	enum eVPedCapsules {
		CAPSULE_STANDARD_MALE,
		CAPSULE_STANDARD_PLAYER_MALE,
		CAPSULE_LARGE_MALE,
		CAPSULE_STANDARD_FEMALE,
		CAPSULE_STANDARD_PLAYER_FEMALE,
		CAPSULE_BOAR,
		CAPSULE_chimp,
		CAPSULE_DEER,
		CAPSULE_COW,
		CAPSULE_COYOTE,
		CAPSULE_dog,
		CAPSULE_retriever,
		CAPSULE_GULL,
		CAPSULE_hen,
		CAPSULE_Fish,
		CAPSULE_mountainlion,
		CAPSULE_PIG,
		CAPSULE_PIGEON,
		CAPSULE_RAT,
		CAPSULE_SHARK
	};

	enum eVPedComponentSets {
		COMPONENTS_PLAYER,
		COMPONENTS_STANDARD_PED,
		COMPONENTS_HIPPIE,
		COMPONENTS_HEN,
		COMPONENTS_ANIMAL
	};

	enum eVPedHealths {
		HEALTH_Strong,
		HEALTH_Average,
		HEALTH_Weak,
		HEALTH_Animal,
		HEALTH_Armour,
		HEALTH_GULL,
		HEALTH_Fish,
		HEALTH_Rat,
		HEALTH_Shark
	};

	enum eVPedIKs {
		STANDARD_PED_IK,
		NO_IK
	};

	enum eVPedIKSettingsInfos {
		ikSolverTypeArm,
		ikSolverTypeBodyLook,
		ikSolverTypeBodyRecoil,
		ikSolverTypeHead,
		ikSolverTypeLeg,
		ikSolverTypeTorso,
		ikSolverTypeTorsoReact,
		ikSolverTypeTorsoVehicle,
		ikSolverTypeRootSlopeFixup
	};

	enum eVPedPerceptionInfo {
		DEFAULT_PERCEPTION,
		BARNYARD_PERCEPTION,
		BIRD_PERCEPTION,
		SHARK_PERCEPTION,
		FISH_PERCEPTION
	};

	enum eVEntityTypes {
		TYPE_ARMY,
		TYPE_ANIMAL,
		TYPE_SWAT,
		TYPE_MISSION,
		TYPE_SPECIAL,
		TYPE_PROSTITUTE,
		TYPE_CRIMINAL,
		TYPE_FIREMAN,
		TYPE_MEDIC,
		TYPE_DEALER,
		TYPE_GANG_PUERTO_RICAN,
		TYPE_GANG_CHINESE_JAPANESE,
		TYPE_GANG_KOREAN,
		TYPE_GANG_AFRICAN_AMERICAN,
		TYPE_GANG_JAMAICAN,
		TYPE_GANG_IRISH,
		TYPE_GANG_RUSSIAN_2,
		TYPE_GANG_RUSSIAN,
		TYPE_GANG_ITALIAN,
		TYPE_GANG_BIKER_2,
		TYPE_GANG_BIKER_1,
		TYPE_GANG_ALBANIAN,
		TYPE_CIVFEMALE,
		TYPE_PLAYER_2, // trevor(the orange one)
		TYPE_NETWORK_PLAYER, // multiplayer(the yellow one)
		TYPE_PLAYER_1, // franklin(the green one)
		TYPE_PLAYER_0, // michael(the blue one)
	};

	enum eVGangs {
		GANG_YOU_DROP_WEAPON,
		GANG_WEAPON_WARNING,
		GANG_WATCH_THIS_GUY_SOLO,
		GANG_WATCH_THIS_GUY_RESP,
		GANG_WATCH_THIS_GUY,
		GANG_INTERVENE,
		GANG_FIGHT_CHEER,
		GANG_DODGE_WARNING,
		GANG_CHASE,
		GANG_BUMP,
		GANG_ATTACK_WARNING,
		GANG_ASK_PLAYER_LEAVE
	};
};