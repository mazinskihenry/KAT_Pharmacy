class ACE_Medical_Treatment_Actions {
    class BasicBandage;
    class FieldDressing;
    class ApplyTourniquet;
    class RemoveTourniquet;
    class Morphine;
    class CheckPulse;
    class CPR;

    class Painkillers: Morphine {
        displayName = CSTRING(Inject_Box_Painkillers);
        displayNameProgress = CSTRING(Using);
        allowedSelections[] = {"Head"};
        items[] = {};
        callbackSuccess = QUOTE([ARR_5('kat_Painkiller', _medic, _patient, _bodyPart, 'Painkillers')] call FUNC(removeItemfromMag); [_patient] call FUNC(wrongBloodTreatment););
        condition = "[_medic, 'kat_Painkiller'] call ace_common_fnc_hasMagazine || [_patient, 'kat_Painkiller'] call ace_common_fnc_hasMagazine";
        litter[] = {};
        icon = QPATHTOF(ui\icon_painkillers_action.paa);
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
    };
    class Carbonate: Morphine {
        displayName = CSTRING(Take_Carbonate);
        displayNameProgress = CSTRING(Using);
        category = "medication";
        treatmentLocations = 0;
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        medicRequired = 0;
        treatmentTime = 5;
        items[] = {"kat_carbonate"};
        condition = QUOTE(!([_patient] call ace_common_fnc_isAwake));
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Carbonate')] call FUNC(treatmentAdvanced_Carbonate));
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "";
        animationPatientUnconsciousExcludeOn[] = {""};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class Amiodarone: Carbonate {
        displayName = CSTRING(Take_Amiodarone);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = 1;
        treatmentTime = 5;
        items[] = {"kat_amiodarone"};
        condition = QUOTE(!([_patient] call ace_common_fnc_isAwake)) && QUOTE(_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Amiodarone')] call FUNC(treatmentAdvanced_Generic));
    };
    class Lidocaine: Carbonate {
        displayName = CSTRING(Take_Lidocaine);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = 1;
        treatmentTime = 5;
        items[] = {"kat_lidocaine"};
        condition = QUOTE(!([_patient] call ace_common_fnc_isAwake)) && QUOTE(_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Lidocaine')] call FUNC(treatmentAdvanced_Generic));
    };
    class Naloxone: Carbonate {
        displayName = CSTRING(Take_Naloxone);
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        medicRequired = 1;
        treatmentTime = 5;
        items[] = {"kat_naloxone"};
        condition = "";
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Lidocane')] call FUNC(treatmentAdvanced_Naloxone));
    };
    class Atropine: Carbonate {
        displayName = CSTRING(Take_Atropine);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = 1;
        treatmentTime = 5;
        items[] = {"kat_atropine"};
        condition = QUOTE(_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Atropine')] call FUNC(treatmentAdvanced_Atropine));
    };
    class TXA: Carbonate {
        displayName = CSTRING(Take_TXA);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = 1;
        treatmentTime = 5;
        items[] = {"kat_TXA"};
        condition = QUOTE(_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_2(_player, _patient)] call FUNC(treatmentAdvanced_TXA));
    };
    class Ondansetron: Carbonate {
        displayName = CSTRING(Take_Ondansetron);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = 1;
        treatmentTime = 5;
        items[] = {"kat_Ondansetron"};
        condition = QUOTE(_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_2(_player, _patient)] call FUNC(treatmentAdvanced_Ondansetron));
    };
    class CheckDogtags: CheckPulse {
        displayName = CSTRING(DogTag);
        displayNameProgress = CSTRING(DogTag_Action);
        treatmentTime = 2;
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 1;
        callbackSuccess = "[_medic, _patient] call ace_dogtags_fnc_checkDogtag";
        condition = "true";
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
    };
    class CheckBloodPressure: CheckPulse { // Remove the ability to check blood pressure at the head
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
    };
    class CheckRhythm: CheckPulse { 
        displayName = CSTRING(Check_Rhythm);
        displayNameProgress = CSTRING(Checking_Rhythm);
        allowedSelections[] = {"Body"};
        treatmentTime = 3;
        items[] = {};
        condition = QUOTE(_patient getVariable [ARR_2(QQGVAR(X), true)]) || "kat_circulation_fnc_AEDStationCondition";
        patientStateCondition = 0;
        callbackStart = QFUNC(AEDanalyze);
        callbackSuccess = "";
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
    };

    class ApplyIV: ApplyTourniquet {
        displayName = CSTRING(Apply_IV_20);
        displayNameProgress = CSTRING(Applying_IV);
        category = "advanced";
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        items[] = {"kat_IV_20"};
        condition = QUOTE(!(_patient getVariable [ARR_2(QQGVAR(IVplaced), false)]));
        treatmentTime = 7;
        callbackSuccess = QFUNC(applyIV);
        litter[] = {};
    };

    class ApplyIV_16: ApplyIV {
        displayName = CSTRING(Apply_IV_16);
        items[] = {"kat_IV_16"};
        treatmentTime = 14;
    };

    class ApplyIO_45: ApplyIV {
        displayName = CSTRING(Apply_IO_45);
        displayNameProgress = CSTRING(Applying_IO);
        items[] = {"kat_IO_45"};
        condition = QFUNC(checkIO);
        treatmentTime = 14;
    };

    class RemoveIV: ApplyTourniquet {
        displayName = CSTRING(Remove_IV);
        displayNameProgress = CSTRING(Removing_IV);
        items[] = {};
        condition = QFUNC(removeIV);
        callbackSuccess = QFUNC(retrieveIV);
    };

    #include "Blood_Medical.hpp"
    
    class Defibrillator: CPR {
        displayName = CSTRING(Defib_Action_Use);
        displayNameProgress = "$STR_KAT_circulation_AED_PROGRESS";
        icon = QPATHTOF(ui\defib.paa);
        items[] = {"kat_AED"};
        treatmentTime = 10;
        callbackStart = "call ace_medical_treatment_fnc_cprStart; _patient setVariable ['kat_AEDinUse', true, true];";
        callbackProgress = "call ace_medical_treatment_fnc_cprProgress; call kat_circulation_fnc_AED_sound;";
        callbackSuccess = "[_medic, _patient, 'AED'] call kat_circulation_fnc_AEDSuccess; _patient setVariable ['kat_AEDinUse', false, true];";
        callbackFailure = "call ace_medical_treatment_fnc_cprFailure; _medic setVariable ['kat_soundplayed', false, true]; _patient setVariable ['kat_AEDinUse', false, true];";
        animationMedic = "AinvPknlMstpSnonWnonDr_medic0";
        treatmentLocations = "GVAR(useLocation_AED)";
        medicRequired = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
    };
    class Defibrillator_station: Defibrillator {
        displayName = CSTRING(DefibS_Action_Use);
        items[] = {};
        callbackSuccess = "[_medic, _patient, 'AED-Station'] call kat_circulation_fnc_AEDSuccess; _patient setVariable ['kat_AEDinUse', false, true];";
        condition = "kat_circulation_fnc_AEDStationCondition";
        treatmentLocations = 0;
    };
    
    class Defibrillator_AED_X: Defibrillator {
        displayName = CSTRING(AED_X_Action_Use);
        displayNameProgress = CSTRING(AED_X_Action_Progress);
        items[] = {"kat_X_AED"};
        callbackSuccess = "[_medic, _patient, 'AED-X'] call kat_circulation_fnc_AEDSuccess; _patient setVariable ['kat_AEDinUse', false, true];";
        //condition = QUOTE((_patient getVariable [ARR_2(QQGVAR(X), false)]) || [ARR_2(_medic, 'kat_AED')] call ace_common_fnc_hasItem || [ARR_2(_medic, 'kat_X_AED')] call ace_common_fnc_hasItem);
        condition = "kat_circulation_fnc_AEDXCondition";
        medicRequired = QGVAR(medLvl_AED_X);
        icon = QPATHTOF(ui\X_Series-Device_W.paa);
    };
    
    class X_Defibrillator_AED_X: Defibrillator_AED_X {
        displayName = CSTRING(X_Action_Use);
        displayNameProgress = CSTRING(X_Action_Progress);
        items[] = {"kat_X_AED"};
        condition = QUOTE(!(_patient getVariable [ARR_2(QQGVAR(X), false)]));
        consumeItem = 0;
        medicRequired = QGVAR(medLvl_AED_X);
        callbackProgress = "";
        callbackStart = "";
        callbackFailure = "";
        callbackSuccess = QFUNC(treatmentAdvanced_X);
        icon = QPATHTOF(ui\X_Series-Device_W.paa);
    };

    class Remove_X_Defibrillator: Defibrillator_AED_X {
        displayName = CSTRING(X_Action_Remove);
        displayNameProgress = CSTRING(X_Remove_Action_Progress);
        items[] = {};
        condition = QUOTE(_patient getVariable [ARR_2(QQGVAR(X), true)]);
        treatmentTime = 5;
        medicRequired = 0;
        callbackProgress = "";
        callbackStart = "";
        callbackFailure = "";
        callbackSuccess = QUOTE([ARR_2(_medic, _patient)] call FUNC(returnAED_X));
        icon = QPATHTOF(ui\X_Series-Device_W.paa);
    };
    class Defibrillator_AED_X_vehicle: Defibrillator {
        displayName = CSTRING(AED_X_Action_Use_Vehicle);
        displayNameProgress = CSTRING(AED_X_Action_Progress);
        items[] = {};
        callbackSuccess = "[_medic, _patient, 'AED-X'] call kat_circulation_fnc_AEDSuccess; _patient setVariable ['kat_AEDinUse', false, true]";
        //condition = QUOTE((_patient getVariable [ARR_2(QQGVAR(X), false)]) || [ARR_2(_medic, 'kat_AED')] call ace_common_fnc_hasItem || [ARR_2(_medic, 'kat_X_AED')] call ace_common_fnc_hasItem);
        condition = QFUNC(vehicleCheck);
        medicRequired = QGVAR(medLvl_AED_X);
        icon = QPATHTOF(ui\X_Series-Device_W.paa);
    };
    
    class X_Defibrillator_AED_X_vehicle: Defibrillator_AED_X_vehicle {
        displayName = CSTRING(X_Action_Use_Vehicle);
        displayNameProgress = CSTRING(X_Action_Progress);
        items[] = {};
        condition = QUOTE(!(_patient getVariable [ARR_2(QQGVAR(X), false)])) && QFUNC(vehicleCheck);
        consumeItem = 1;
        medicRequired = QGVAR(medLvl_AED_X);
        callbackProgress = "";
        callbackStart = "";
        callbackFailure = "";
        callbackSuccess = QFUNC(treatmentAdvanced_X);
        icon = QPATHTOF(ui\X_Series-Device_W.paa);
    };

    class Remove_X_Defibrillator_vehicle: Defibrillator_AED_X_vehicle {
        displayName = CSTRING(X_Action_Remove_Vehicle);
        displayNameProgress = CSTRING(X_Remove_Action_Progress);
        items[] = {};
        condition = QUOTE(_patient getVariable [ARR_2(QQGVAR(AEDvehicle), true)]);
        treatmentTime = 5;
        medicRequired = 0;
        callbackProgress = "";
        callbackStart = "";
        callbackFailure = "";
        callbackSuccess = QUOTE([ARR_2(_medic, _patient)] call FUNC(returnAED_X));
        icon = QPATHTOF(ui\X_Series-Device_W.paa);
    };
};
