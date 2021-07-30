class ACE_Medical_Treatment {
	class IV {
		class BloodIV_O {
			volume = 1000;
			ratio[] = {"Plasma", 1};
		};
		class BloodIV_A: BloodIV_O {};
		class BloodIV_B: BloodIV_O {};
		class BloodIV_AB: BloodIV_O {};
		
		class BloodIV_O_500 {
			volume = 500;
			ratio[] = {"Plasma", 1};
		};
		class BloodIV_A_500: BloodIV_O_500 {};
		class BloodIV_B_500: BloodIV_O_500 {};
		class BloodIV_AB_500: BloodIV_O_500 {};
		
		class BloodIV_O_250 {
			volume = 250;
			ratio[] = {"Plasma", 1};
		};
		class BloodIV_A_250: BloodIV_O_250 {};
		class BloodIV_B_250: BloodIV_O_250 {};
		class BloodIV_AB_250: BloodIV_O_250 {};
	};
	class Medication {
		class Carbonate {
			painReduce = 0;
            hrIncreaseLow[] = {5, 10};
            hrIncreaseNormal[] = {10, 15};
            hrIncreaseHigh[] = {15, 20};
            timeInSystem = 30;
            timeTillMaxEffect = 2;
            maxDose = 10;
            incompatibleMedication[] = {};
            viscosityChange = 0;
		};
		class Amiodarone {
			painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 600;
            timeTillMaxEffect = 2;
            maxDose = 4;
            incompatibleMedication[] = {};
            viscosityChange = 0;
		};
		class Lidocane {
			painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 240;
            timeTillMaxEffect = 2;
            maxDose = 8;
            incompatibleMedication[] = {};
            viscosityChange = 0;
		};
		class Atropine {
			painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 120;
            timeTillMaxEffect = 15;
            maxDose = 8;
            incompatibleMedication[] = {};
            viscosityChange = 0;
		};
		class TXA {
			painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 120;
            timeTillMaxEffect = 15;
            maxDose = 8;
            incompatibleMedication[] = {};
            viscosityChange = 0;
		};
	};
};
