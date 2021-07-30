#include "script_component.hpp"
/*
 * Author: Katalam
 * Turns the head of the patient for airway management without items
 *
 * Arguments:
 * 0: Soldier <OBJECT>
 * 1: Patient <OBJECT>
 *
 * Return Value:
 * Succesful treatment <BOOL>
 *
 * Example:
 * [player, cursorTarget] call kat_airway_fnc_treatmentAdvanced_turnaroundHead;
 *
 * Public: No
 */

params ["_player", "_target"];

if !(_target getVariable ["KAT_medical_airwayOccluded", false]) exitWith {
    private _output = localize LSTRING(Airway_NA);
    [_output, 2, _player] call ace_common_fnc_displayTextStructured;
    false;
};

// TO-DO: head turning animation

private _output = localize LSTRING(turnaround_info);
[_output, 1.5, _player] call ace_common_fnc_displayTextStructured;

if (random 100 < GVAR(probability_headturning)) then {
    _target setVariable ["KAT_medical_airwayOccluded", false, true];
};

true;
