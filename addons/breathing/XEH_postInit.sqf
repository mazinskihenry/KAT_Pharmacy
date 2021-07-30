#include "script_component.hpp"

["treatmentPulseoximeter", {_this call FUNC(treatmentAdvanced_pulseoximeterLocal)}] call CBA_fnc_addEventHandler;
["treatmentChestSeal", {_this call FUNC(treatmentAdvanced_chestSealLocal)}] call CBA_fnc_addEventHandler;
["handleBreathing", {_this call FUNC(handleBreathing)}] call CBA_fnc_addEventHandler;
["treatmentHemopneumothorax", {_this call FUNC(treatmentAdvanced_hemopneumothoraxLocal)}] call CBA_fnc_addEventHandler;
["treatmentTensionpneumothorax", {_this call FUNC(treatmentAdvanced_tensionpneumothoraxLocal)}] call CBA_fnc_addEventHandler;
