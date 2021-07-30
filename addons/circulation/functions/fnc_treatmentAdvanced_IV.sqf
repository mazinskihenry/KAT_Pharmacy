#include "script_component.hpp"
/*
 * Author: Katalam
 * Handle the IV for the patient with blood types. Have to be local to avoid effect on all clients.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Successful <BOOLEAN>
 *
 * Example:
 * ['Blood_IV_A', cursorTarget] call kat_circulation_fnc_treatmentAdvanced_IV
 *
 * Public: No
 */

params ["_className", "_target"];

//unit, adjustment, time
private _volume = getNumber (configFile >> "ACE_Medical_Advanced" >> "Treatment" >> "IV" >> _className >> "volume");

private _hradjustpositive = (_volume / 4);
private _hradjust = -(_hradjustpositive);

_target setVariable ["KAT_medical_wrongBloodAdjust", _hradjustpositive, true];

[_target, _className, 120, 1200, -20, 0, 0] call ace_medical_status_fnc_addMedicationAdjustment;

//todo tod?
private _a = (_target getVariable [QGVAR(IV_counts), 0]) + 1;
_target setVariable [QGVAR(IV_counts), _a, true]
