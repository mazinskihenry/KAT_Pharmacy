#include "script_component.hpp"
/*
 * Author: Kygan
 * Re-adds the AED X to the player's inventory
 * Note: Patient may not be local
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: Patient <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorObject, "LeftLeg"] call kat_circulation_fnc_returnAED_X;
 *
 * Public: No
 */

params ["_player", "_patient"];
private _output = localize LSTRING(X_Action_Remove);
private _AEDvehicle = _patient getVariable [QGVAR(AEDvehicle), false];

if (_AEDvehicle == true) then {
	_patient setVariable ['kat_AEDvehicle', true, true];
};

_patient setVariable [QGVAR(X), false, true];
_player setVariable [QGVAR(use), false, true];
_player setVariable [QGVAR(returnedAED), true, true];
[_output, 1.5, _player] call ace_common_fnc_displayTextStructured;

[_player, "kat_X_AED"] call ace_common_fnc_addToInventory;

true;
