#include "script_component.hpp"

class CfgPatches {
    class ADDON    {
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        units[] = {
            kat_PainkillerItem,
            kat_X_AEDItem,
            kat_bloodBankCrate
        };
        weapons[] = {
            kat_Painkiller,
            kat_bloodIV_O,
            kat_bloodIV_A,
            kat_bloodIV_B,
            kat_bloodIV_AB,
            kat_bloodIV_O_500,
            kat_bloodIV_A_500,
            kat_bloodIV_B_500,
            kat_bloodIV_AB_500,
            kat_bloodIV_O_250,
            kat_bloodIV_A_250,
            kat_bloodIV_B_250,
            kat_bloodIV_AB_250,
            kat_PainkillerItem,
            kat_X_AED,
            kat_crossPanel,
            kat_IV_20,
            kat_IV_16,
            kat_IO_45,
            kat_carbonate,
            kat_amiodarone,
            kat_lidocane,
            kat_naloxone,
            kat_atropine
        };
        magazines[] = { };
        requiredAddons[] = {
            "ace_medical",
            "ace_medical_ai",
            "ace_medical_blood",
            "ace_medical_damage",
            "ace_medical_engine",
            "ace_medical_feedback",
            "ace_medical_gui",
            "ace_medical_statemachine",
            "ace_medical_status",
            "ace_medical_treatment",
            "ace_medical_vitals",
            "ace_dogtags",
            "cba_settings",
            "kat_main"
        };
        author = "Katalam";
        authors[] = {"Katalam", "2LT.Mazinski"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgSounds.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "ACE_Medical_Treatment.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"
#include "ACE_Medical_Advanced.hpp"
#include "ui\CrossPanel_Dialog.hpp"
