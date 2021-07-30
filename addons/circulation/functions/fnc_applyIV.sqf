#include "script_component.hpp"
/*
 * Author: 2LT.Mazinski
 * Opens an IV/IO on a patient and changes the patient's flow variable
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 * 2: Body Part <STRING>
 * 3: Treatment (not used) <STRING>
 * 4: Item User (not used) <OBJECT>
 * 5: Used Item <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorObject, "LeftLeg", "", objNull, "kat_IV_20"] call kat_circulation_fnc_applyIV;
 *
 * Public: No
 */

params ["_medic", "_patient", "_bodyPart", "", "", "_usedItem"];

_patient setVariable [QGVAR(usedIV), _usedItem, true];
_patient setVariable [QGVAR(IVplaced), true, true];

private _heartRate = _patient getVariable ["ace_medical_heartRate", 80];

switch (_bodyPart) do {
	case "leftarm": {_patient setVariable [QGVAR(IVsite), 2];
	};
	case "rightarm": {_patient setVariable [QGVAR(IVsite), 3];
	};
	case "leftleg": {_patient setVariable [QGVAR(IVsite), 4];
	};
	case "rightleg": {_patient setVariable [QGVAR(IVsite), 5];
	};
};

if (_patient getVariable ["ACE_isUnconscious", false]) then {
	switch (_usedItem) do {
		case "kat_IV_20": {_patient setVariable [QGVAR(flowRate), 0.7, true];
		[_patient, "activity", LSTRING(iv_log), [[_medic] call ace_common_fnc_getName, "20g IV"]] call ace_medical_treatment_fnc_addToLog;
		};
		case "kat_IV_16": {_patient setVariable [QGVAR(flowRate), 1, true];
		[_patient, "activity", LSTRING(iv_log), [[_medic] call ace_common_fnc_getName, "16g IV"]] call ace_medical_treatment_fnc_addToLog;
		};
		case "kat_IO_45": {_patient setVariable [QGVAR(flowRate), 2.5, true];
		[_patient, "activity", LSTRING(iv_log), [[_medic] call ace_common_fnc_getName, "45mm IO"]] call ace_medical_treatment_fnc_addToLog;
		};
	};
} else {
	switch (_usedItem) do {
		case "kat_IV_20": {_patient setVariable [QGVAR(flowRate), 0.8, true];
		[_patient, "activity", LSTRING(iv_log), [[_medic] call ace_common_fnc_getName, "20g IV"]] call ace_medical_treatment_fnc_addToLog;
		};
		case "kat_IV_16": {_patient setVariable [QGVAR(flowRate), 1.5, true];
		[_patient, "activity", LSTRING(iv_log), [[_medic] call ace_common_fnc_getName, "16g IV"]] call ace_medical_treatment_fnc_addToLog;
		};
		case "kat_IO_45": {_patient setVariable [QGVAR(flowRate), 2.5, true];
		[_patient, "activity", LSTRING(iv_log), [[_medic] call ace_common_fnc_getName, "45mm IO"]] call ace_medical_treatment_fnc_addToLog;
		[_patient, 0.7] call ace_medical_status_fnc_adjustPainLevel;
		};
	};
};

[_patient, _usedItem] call ace_medical_treatment_fnc_addToTriageCard;

if (_usedItem != "kat_IO_45") then {
	[{
	    params ["_args", "_idPFH"];
	    _args params ["_patient", "_bodyPart"];

	    private _alive = alive _patient;
	    private _IVstatus = _patient getVariable[QGVAR(IVplaced), false];
	    if ((!_alive) || (!_IVstatus)) exitWith {
	        [_idPFH] call CBA_fnc_removePerFrameHandler;        
			_patient setVariable [QGVAR(usedIV), "", true];
			_patient setVariable [QGVAR(IVplaced), false, true];
			_patient setVariable [QGVAR(flowRate), 0, true];
			_patient setVariable [QGVAR(IV_counts), 0, true];
			_patient setVariable [QGVAR(IVsite), 0, true];
	    };

		private _heartRate = _patient getVariable ["ace_medical_heartRate", 80];
		private _rateMultiplyer = 50;

		if (_heartRate < 120) then {
			_rateMultiplyer = 50;
		} else {
			_heartRate = 120;
		};

		if (_patient getVariable [QGVAR(usedIV), ""] isEqualTo "kat_IV_20") then {
			_patient setVariable [QGVAR(flowRate), 0.6 * (_heartRate / _rateMultiplyer), true]
		} else {
			_patient setVariable [QGVAR(flowRate), 0.8 * (_heartRate / _rateMultiplyer), true]
		};

		if ([_patient, _bodyPart] call ace_medical_treatment_fnc_hasTourniquetAppliedTo) then {
			_patient setVariable [QGVAR(flowRate), 0, true]
		};
	}, 2, [_patient, _bodyPart]] call CBA_fnc_addPerFrameHandler;
};