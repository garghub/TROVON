void ODM_StopAntennaSwitchDm(PDM_ODM_T pDM_Odm)
{
pDM_Odm->SupportAbility &= ~ODM_BB_ANT_DIV;
ODM_RT_TRACE(
pDM_Odm,
ODM_COMP_ANT_DIV,
ODM_DBG_LOUD,
("STOP Antenna Diversity\n")
);
}
void ODM_SetAntConfig(PDM_ODM_T pDM_Odm, u8 antSetting)
{
if (antSetting == 0)
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000000);
else if (antSetting == 1)
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
}
void ODM_SwAntDivRestAfterLink(PDM_ODM_T pDM_Odm)
{
pSWAT_T pDM_SWAT_Table = &pDM_Odm->DM_SWAT_Table;
pFAT_T pDM_FatTable = &pDM_Odm->DM_FatTable;
u32 i;
pDM_Odm->RSSI_test = false;
pDM_SWAT_Table->try_flag = 0xff;
pDM_SWAT_Table->RSSI_Trying = 0;
pDM_SWAT_Table->Double_chk_flag = 0;
pDM_FatTable->RxIdleAnt = MAIN_ANT;
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
pDM_FatTable->MainAnt_Sum[i] = 0;
pDM_FatTable->AuxAnt_Sum[i] = 0;
pDM_FatTable->MainAnt_Cnt[i] = 0;
pDM_FatTable->AuxAnt_Cnt[i] = 0;
}
}
