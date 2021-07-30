#include "script_component.hpp"
/*
 * Author: Katalam
 * docks a pulseoximeter on the patient
 * Main function
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorTarget] call kat_breathing_fnc_treatmentAdvanced_chestSealLocal;
 *
 * Public: No
 */

params ["_player", "_target"];

_target setVariable ["KAT_medical_pneumothorax", false, true];

[_target, "activity", LSTRING(pneumothorax), [[_player] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;

if (random 100 <= GVAR(hemopneumothoraxChance)) then {
	_unit setVariable ["KAT_medical_hemopneumothorax", true, true];
};
