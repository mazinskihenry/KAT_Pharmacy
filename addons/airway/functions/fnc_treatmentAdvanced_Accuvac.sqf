#include "script_component.hpp"
/*
 * Author: Katalam
 * Airway Management for occluding
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 *
 * Return Value:
 * Succesful treatment started <BOOL>
 *
 * Example:
 * [player, cursorTarget] call kat_airway_fnc_treatmentAdvanced_accuvac;
 *
 * Public: Yes
 */

params ["_caller", "_target"];

if !(_target getVariable ["KAT_medical_airwayOccluded", false]) exitWith {
    private _output = localize LSTRING(Accuvac_NA);
    [_output, 1.5, _caller] call ace_common_fnc_displayTextStructured;
};

if (local _target) then {
    ["treatmentAccuvac", [_target, "Accuvac"]] call CBA_fnc_localEvent;
} else {
    ["treatmentAccuvac", [_target, "Accuvac"], _target] call CBA_fnc_targetEvent;
};

true;
