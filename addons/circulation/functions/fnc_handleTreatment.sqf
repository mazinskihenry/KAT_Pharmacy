#include "script_component.hpp"
/*
 * Author: Katalam
 * Handle the treatment for the patient cause calling two functions in one action isn't allowed.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Successful <BOOLEAN>
 *
 * Example:
 * [player, cursorTarget, 'hand_l', 'BloodIV_A', 'BloodIV_A'] call kat_circulation_fnc_handleTreatment;
 *
 * Public: No
 */

params ["_player", "_target", "_bodyPart", "_className", "_item"];

private _return = false;
_item = "kat_" + _className;

[_player, _target, _bodyPart, _className, objNull, _item] call ace_medical_treatment_fnc_ivBag;

if ([_target, _className] call FUNC(compatible)) exitWith {};

[_className, _target] call FUNC(treatmentAdvanced_IV);

_return = true;
_return
