#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Checks if an IO can be applied to the patient.
 *
 * Arguments:
 * 0: Medic (not used) <OBJECT>
 * 1: Patient <OBJECT>
 * 2: Body Part <STRING>
 *
 * Return Value:
 * Can Splint <BOOL>
 *
 * Example:
 * [player, cursorObject, "LeftLeg"] call ace_medical_treatment_fnc_canSplint
 *
 * Public: No
 */

params ["", "_patient", "_bodyPart"];

private _temp = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"];
private _fracture = _patient getVariable ["ace_medical_fractures", DEFAULT_FRACTURE_VALUES];

private _partIndex = _temp find toLower _bodyPart;
private _return = true;

private _left = _fracture select 3;

if ((_fracture select _partIndex) != 0) then {
	_return = false;
};

if (_patient getVariable [QGVAR(IVplaced), true] == true) then {
	_return = false;
};

_return