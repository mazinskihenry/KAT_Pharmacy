class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;
    class ACE_bloodIV;

    class kat_bloodIV_O: ACE_bloodIV {
        displayName = CSTRING(BloodIV_O);
    };
    class kat_bloodIV_A: ACE_bloodIV {
        displayName = CSTRING(BloodIV_A);
    };
    class kat_bloodIV_B: ACE_bloodIV {
        displayName = CSTRING(BloodIV_B);
    };
    class kat_bloodIV_AB: ACE_bloodIV {
        displayName = CSTRING(BloodIV_AB);
    };
    class ACE_bloodIV_500;
    class kat_bloodIV_O_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_O_500);
    };
    class kat_bloodIV_A_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_A_500);
    };
    class kat_bloodIV_B_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_B_500);
    };
    class kat_bloodIV_AB_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_AB_500);
    };
    class ACE_bloodIV_250;
    class kat_bloodIV_O_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_O_250);
    };
    class kat_bloodIV_A_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_A_250);
    };
    class kat_bloodIV_B_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_B_250);
    };
    class kat_bloodIV_AB_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_AB_250);
    };
    class kat_PainkillerItem: ACE_ItemCore {
        scope = 1; // no mistake, just a placeholder, cause ACE can't handle magazines. DO NOT USE!
        author = "Katalam";
        displayName = CSTRING(Painkillers_Box_Display);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0;
        };
    };
	class kat_AED: ACE_ItemCore {
        scope = 2;
		author = "Katalam";
        displayName = "$STR_KAT_circulation_AED_DISPLAYNAME";
        picture = QPATHTOF(ui\defib.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
        descriptionShort = "$STR_KAT_circulation_AED_DESCRIPTION";
        descriptionUse = "$STR_KAT_circulation_AED_DESCRIPTION";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 30;
        };
	};
    class kat_X_AED: kat_AED {
        scope = 2;
        displayName = CSTRING(X_Display);
        picture = QPATHTOF(ui\x-series.paa);
        model = QPATHTOF(models\aedx\aedx.p3d);
        descriptionShort = CSTRING(X_Desc);
        descriptionUse = CSTRING(X_Desc);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 40;
        };
    };
    class kat_crossPanel: ACE_ItemCore {
        scope = 2;
        author = "Katalam";
        displayName = CSTRING(crosspanel);
        descriptionShort = CSTRING(desc_crosspanel);
        picture = QPATHTOF(ui\crosspanel.paa);
        icon = "";
        mapSize = 0.034;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.1;
        };
    };	
    class kat_IV_20: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(kat_IV_20_Display);
        picture = QPATHTOF(ui\icon_IV_20.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(IV_DescShort);
        descriptionUse = CSTRING(IV_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_IV_16: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(kat_IV_16_Display);
        picture = QPATHTOF(ui\icon_IV_16.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(IV_DescShort);
        descriptionUse = CSTRING(IV_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_IO_45: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(kat_IO_45_Display);
        picture = QPATHTOF(ui\icon_IO_45.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(IO_DescShort);
        descriptionUse = CSTRING(IO_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_carbonate: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(Carbonate_Box_Display);
        picture = QPATHTOF(ui\icon_Carbonate.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(Carbonate_DescShort);
        descriptionUse = CSTRING(Carbonate_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_amiodarone: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(Amiodarone_Box_Display);
        picture = QPATHTOF(ui\icon_Amiodarone.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(Amiodarone_DescShort);
        descriptionUse = CSTRING(Amiodarone_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_lidocaine: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(Lidocaine_Box_Display);
        picture = QPATHTOF(ui\icon_Lidocaine.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(Lidocane_DescShort);
        descriptionUse = CSTRING(Lidocane_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_naloxone: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(Naloxone_Box_Display);
        picture = QPATHTOF(ui\icon_Naloxone.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(Naloxone_DescShort);
        descriptionUse = CSTRING(Naloxone_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_atropine: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(Atropine_Box_Display);
        picture = QPATHTOF(ui\icon_Atropine.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(Atropine_DescShort);
        descriptionUse = CSTRING(Atropine_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_TXA: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(TXA_Box_Display);
        picture = QPATHTOF(ui\icon_TXA.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(TXA_DescShort);
        descriptionUse = CSTRING(TXA_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
    class kat_Ondansetron: ACE_ItemCore {
        scope = 2;
        displayName = CSTRING(Ondansetron_Box_Display);
        picture = QPATHTOF(ui\icon_Ondansetron.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
        descriptionShort = CSTRING(Ondansetron_DescShort);
        descriptionUse = CSTRING(Ondansetron_DescUse);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        }; 
    };
};
