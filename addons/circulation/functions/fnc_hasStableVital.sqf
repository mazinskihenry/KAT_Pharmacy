#include "script_component.hpp"
/*
 * Author: Ruthberg
 * Check if a unit has stable vitals (required to become conscious)
 *
 * Arguments:
 * 0: The patient <OBJECT>
 *
 * Return Value:
 * Has stable vitals <BOOL>
 *
 * Example:
 * [player] call ace_medical_status_fnc_hasStableVitals
 *
 * Public: No
 */

params ["_unit"];

if (GET_BLOOD_VOLUME(_unit) < BLOOD_VOLUME_CLASS_2_HEMORRHAGE) exitWith { false };
if IN_CRDC_ARRST(_unit) exitWith { false };

private _bloodPressure = GET_BLOOD_PRESSURE(_unit);
_bloodPressure params ["_bloodPressureL", "_bloodPressureH"];
if (_bloodPressureL < 70 || {_bloodPressureH < 90}) exitWith { false };

private _heartRate = GET_HEART_RATE(_unit);
if (_heartRate < 70) exitWith { false };

true