#include "script_component.hpp"
/*
 * Author: 2LT.Mazinski
 * Checks for Accuvacs in vehicle inventories and allows them to be used on patients both in and around the vehicle.
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

params ["_medic", "_patient"];

private _return = false;
private _checkArray = _patient nearEntities 5;
private _inventory = [];

{
    _inventory = itemCargo _x;

    if (_x isKindOf "LandVehicle" || _x isKindOf "Helicopter") then {
	    {
			if (_x == "kat_accuvac") then {
				_return = true;
			};
		} forEach _inventory;
	};
} forEach _checkArray;

_return