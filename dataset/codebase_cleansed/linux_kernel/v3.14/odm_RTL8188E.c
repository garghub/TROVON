void ODM_DIG_LowerBound_88E(struct odm_dm_struct *dm_odm)
{
struct rtw_dig *pDM_DigTable = &dm_odm->DM_DigTable;
if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) {
pDM_DigTable->rx_gain_range_min = (u8) pDM_DigTable->AntDiv_RSSI_max;
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("ODM_DIG_LowerBound_88E(): pDM_DigTable->AntDiv_RSSI_max=%d\n", pDM_DigTable->AntDiv_RSSI_max));
}
}
static void odm_RX_HWAntDivInit(struct odm_dm_struct *dm_odm)
{
struct adapter *adapter = dm_odm->Adapter;
u32 value32;
if (*(dm_odm->mp_mode) == 1) {
dm_odm->AntDivType = CGCS_RX_SW_ANTDIV;
PHY_SetBBReg(adapter, ODM_REG_IGI_A_11N, BIT7, 0);
PHY_SetBBReg(adapter, ODM_REG_LNA_SWITCH_11N, BIT31, 1);
return;
}
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("odm_RX_HWAntDivInit()\n"));
value32 = PHY_QueryBBReg(adapter, ODM_REG_ANTSEL_PIN_11N, bMaskDWord);
PHY_SetBBReg(adapter, ODM_REG_ANTSEL_PIN_11N, bMaskDWord, value32|(BIT23|BIT25));
PHY_SetBBReg(adapter, ODM_REG_PIN_CTRL_11N, BIT9|BIT8, 0);
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT10, 0);
PHY_SetBBReg(adapter, ODM_REG_LNA_SWITCH_11N, BIT22, 1);
PHY_SetBBReg(adapter, ODM_REG_LNA_SWITCH_11N, BIT31, 1);
PHY_SetBBReg(adapter, ODM_REG_ANTDIV_PARA1_11N, bMaskDWord, 0x000000a0);
PHY_SetBBReg(adapter, ODM_REG_BB_PWR_SAV4_11N, BIT7, 1);
PHY_SetBBReg(adapter, ODM_REG_CCK_ANTDIV_PARA2_11N, BIT4, 1);
ODM_UpdateRxIdleAnt_88E(dm_odm, MAIN_ANT);
PHY_SetBBReg(adapter, ODM_REG_ANT_MAPPING1_11N, 0xFFFF, 0x0201);
}
static void odm_TRX_HWAntDivInit(struct odm_dm_struct *dm_odm)
{
struct adapter *adapter = dm_odm->Adapter;
u32 value32;
if (*(dm_odm->mp_mode) == 1) {
dm_odm->AntDivType = CGCS_RX_SW_ANTDIV;
PHY_SetBBReg(adapter, ODM_REG_IGI_A_11N, BIT7, 0);
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT5|BIT4|BIT3, 0);
return;
}
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("odm_TRX_HWAntDivInit()\n"));
value32 = PHY_QueryBBReg(adapter, ODM_REG_ANTSEL_PIN_11N, bMaskDWord);
PHY_SetBBReg(adapter, ODM_REG_ANTSEL_PIN_11N, bMaskDWord, value32|(BIT23|BIT25));
PHY_SetBBReg(adapter, ODM_REG_PIN_CTRL_11N, BIT9|BIT8, 0);
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT10, 0);
PHY_SetBBReg(adapter, ODM_REG_LNA_SWITCH_11N, BIT22, 0);
PHY_SetBBReg(adapter, ODM_REG_LNA_SWITCH_11N, BIT31, 1);
PHY_SetBBReg(adapter, ODM_REG_ANTDIV_PARA1_11N, bMaskDWord, 0x000000a0);
PHY_SetBBReg(adapter, ODM_REG_BB_PWR_SAV4_11N, BIT7, 1);
PHY_SetBBReg(adapter, ODM_REG_CCK_ANTDIV_PARA2_11N, BIT4, 1);
PHY_SetBBReg(adapter, ODM_REG_TX_ANT_CTRL_11N, BIT21, 0);
ODM_UpdateRxIdleAnt_88E(dm_odm, MAIN_ANT);
if (!dm_odm->bIsMPChip) {
PHY_SetBBReg(adapter, ODM_REG_RX_DEFUALT_A_11N, BIT10|BIT9|BIT8, 1);
PHY_SetBBReg(adapter, ODM_REG_RX_DEFUALT_A_11N, BIT13|BIT12|BIT11, 2);
} else {
PHY_SetBBReg(adapter, ODM_REG_ANT_MAPPING1_11N, bMaskDWord, 0x0201);
}
}
static void odm_FastAntTrainingInit(struct odm_dm_struct *dm_odm)
{
struct adapter *adapter = dm_odm->Adapter;
u32 value32, i;
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
u32 AntCombination = 2;
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("odm_FastAntTrainingInit()\n"));
if (*(dm_odm->mp_mode) == 1) {
ODM_RT_TRACE(dm_odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("dm_odm->AntDivType: %d\n", dm_odm->AntDivType));
return;
}
for (i = 0; i < 6; i++) {
dm_fat_tbl->Bssid[i] = 0;
dm_fat_tbl->antSumRSSI[i] = 0;
dm_fat_tbl->antRSSIcnt[i] = 0;
dm_fat_tbl->antAveRSSI[i] = 0;
}
dm_fat_tbl->TrainIdx = 0;
dm_fat_tbl->FAT_State = FAT_NORMAL_STATE;
value32 = PHY_QueryBBReg(adapter, 0x4c, bMaskDWord);
PHY_SetBBReg(adapter, 0x4c, bMaskDWord, value32|(BIT23|BIT25));
value32 = PHY_QueryBBReg(adapter, 0x7B4, bMaskDWord);
PHY_SetBBReg(adapter, 0x7b4, bMaskDWord, value32|(BIT16|BIT17));
PHY_SetBBReg(adapter, 0x7b4, 0xFFFF, 0);
PHY_SetBBReg(adapter, 0x7b0, bMaskDWord, 0);
PHY_SetBBReg(adapter, 0x870, BIT9|BIT8, 0);
PHY_SetBBReg(adapter, 0x864, BIT10, 0);
PHY_SetBBReg(adapter, 0xb2c, BIT22, 0);
PHY_SetBBReg(adapter, 0xb2c, BIT31, 1);
PHY_SetBBReg(adapter, 0xca4, bMaskDWord, 0x000000a0);
if (AntCombination == 2) {
if (!dm_odm->bIsMPChip) {
PHY_SetBBReg(adapter, 0x858, BIT10|BIT9|BIT8, 1);
PHY_SetBBReg(adapter, 0x858, BIT13|BIT12|BIT11, 2);
} else {
PHY_SetBBReg(adapter, 0x914, bMaskByte0, 1);
PHY_SetBBReg(adapter, 0x914, bMaskByte1, 2);
}
} else if (AntCombination == 7) {
if (!dm_odm->bIsMPChip) {
PHY_SetBBReg(adapter, 0x858, BIT10|BIT9|BIT8, 0);
PHY_SetBBReg(adapter, 0x858, BIT13|BIT12|BIT11, 1);
PHY_SetBBReg(adapter, 0x878, BIT16, 0);
PHY_SetBBReg(adapter, 0x858, BIT15|BIT14, 2);
PHY_SetBBReg(adapter, 0x878, BIT19|BIT18|BIT17, 3);
PHY_SetBBReg(adapter, 0x878, BIT22|BIT21|BIT20, 4);
PHY_SetBBReg(adapter, 0x878, BIT25|BIT24|BIT23, 5);
PHY_SetBBReg(adapter, 0x878, BIT28|BIT27|BIT26, 6);
PHY_SetBBReg(adapter, 0x878, BIT31|BIT30|BIT29, 7);
} else {
PHY_SetBBReg(adapter, 0x914, bMaskByte0, 0);
PHY_SetBBReg(adapter, 0x914, bMaskByte1, 1);
PHY_SetBBReg(adapter, 0x914, bMaskByte2, 2);
PHY_SetBBReg(adapter, 0x914, bMaskByte3, 3);
PHY_SetBBReg(adapter, 0x918, bMaskByte0, 4);
PHY_SetBBReg(adapter, 0x918, bMaskByte1, 5);
PHY_SetBBReg(adapter, 0x918, bMaskByte2, 6);
PHY_SetBBReg(adapter, 0x918, bMaskByte3, 7);
}
}
PHY_SetBBReg(adapter, 0x80c, BIT21, 1);
PHY_SetBBReg(adapter, 0x864, BIT5|BIT4|BIT3, 0);
PHY_SetBBReg(adapter, 0x864, BIT8|BIT7|BIT6, 1);
PHY_SetBBReg(adapter, 0x864, BIT2|BIT1|BIT0, (AntCombination-1));
PHY_SetBBReg(adapter, 0xc50, BIT7, 1);
}
void ODM_AntennaDiversityInit_88E(struct odm_dm_struct *dm_odm)
{
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("dm_odm->AntDivType=%d\n", dm_odm->AntDivType));
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("dm_odm->bIsMPChip=%s\n", (dm_odm->bIsMPChip ? "true" : "false")));
if (dm_odm->AntDivType == CGCS_RX_HW_ANTDIV)
odm_RX_HWAntDivInit(dm_odm);
else if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV)
odm_TRX_HWAntDivInit(dm_odm);
else if (dm_odm->AntDivType == CG_TRX_SMART_ANTDIV)
odm_FastAntTrainingInit(dm_odm);
}
void ODM_UpdateRxIdleAnt_88E(struct odm_dm_struct *dm_odm, u8 Ant)
{
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
struct adapter *adapter = dm_odm->Adapter;
u32 DefaultAnt, OptionalAnt;
if (dm_fat_tbl->RxIdleAnt != Ant) {
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Need to Update Rx Idle Ant\n"));
if (Ant == MAIN_ANT) {
DefaultAnt = (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) ? MAIN_ANT_CG_TRX : MAIN_ANT_CGCS_RX;
OptionalAnt = (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) ? AUX_ANT_CG_TRX : AUX_ANT_CGCS_RX;
} else {
DefaultAnt = (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) ? AUX_ANT_CG_TRX : AUX_ANT_CGCS_RX;
OptionalAnt = (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) ? MAIN_ANT_CG_TRX : MAIN_ANT_CGCS_RX;
}
if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) {
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT5|BIT4|BIT3, DefaultAnt);
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT8|BIT7|BIT6, OptionalAnt);
PHY_SetBBReg(adapter, ODM_REG_ANTSEL_CTRL_11N, BIT14|BIT13|BIT12, DefaultAnt);
PHY_SetBBReg(adapter, ODM_REG_RESP_TX_11N, BIT6|BIT7, DefaultAnt);
} else if (dm_odm->AntDivType == CGCS_RX_HW_ANTDIV) {
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT5|BIT4|BIT3, DefaultAnt);
PHY_SetBBReg(adapter, ODM_REG_RX_ANT_CTRL_11N, BIT8|BIT7|BIT6, OptionalAnt);
}
}
dm_fat_tbl->RxIdleAnt = Ant;
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("RxIdleAnt=%s\n", (Ant == MAIN_ANT) ? "MAIN_ANT" : "AUX_ANT"));
pr_info("RxIdleAnt=%s\n", (Ant == MAIN_ANT) ? "MAIN_ANT" : "AUX_ANT");
}
static void odm_UpdateTxAnt_88E(struct odm_dm_struct *dm_odm, u8 Ant, u32 MacId)
{
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
u8 TargetAnt;
if (Ant == MAIN_ANT)
TargetAnt = MAIN_ANT_CG_TRX;
else
TargetAnt = AUX_ANT_CG_TRX;
dm_fat_tbl->antsel_a[MacId] = TargetAnt&BIT0;
dm_fat_tbl->antsel_b[MacId] = (TargetAnt&BIT1)>>1;
dm_fat_tbl->antsel_c[MacId] = (TargetAnt&BIT2)>>2;
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("Tx from TxInfo, TargetAnt=%s\n",
(Ant == MAIN_ANT) ? "MAIN_ANT" : "AUX_ANT"));
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("antsel_tr_mux=3'b%d%d%d\n",
dm_fat_tbl->antsel_c[MacId], dm_fat_tbl->antsel_b[MacId], dm_fat_tbl->antsel_a[MacId]));
}
void ODM_SetTxAntByTxInfo_88E(struct odm_dm_struct *dm_odm, u8 *pDesc, u8 macId)
{
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
if ((dm_odm->AntDivType == CG_TRX_HW_ANTDIV) || (dm_odm->AntDivType == CG_TRX_SMART_ANTDIV)) {
SET_TX_DESC_ANTSEL_A_88E(pDesc, dm_fat_tbl->antsel_a[macId]);
SET_TX_DESC_ANTSEL_B_88E(pDesc, dm_fat_tbl->antsel_b[macId]);
SET_TX_DESC_ANTSEL_C_88E(pDesc, dm_fat_tbl->antsel_c[macId]);
}
}
void ODM_AntselStatistics_88E(struct odm_dm_struct *dm_odm, u8 antsel_tr_mux, u32 MacId, u8 RxPWDBAll)
{
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV) {
if (antsel_tr_mux == MAIN_ANT_CG_TRX) {
dm_fat_tbl->MainAnt_Sum[MacId] += RxPWDBAll;
dm_fat_tbl->MainAnt_Cnt[MacId]++;
} else {
dm_fat_tbl->AuxAnt_Sum[MacId] += RxPWDBAll;
dm_fat_tbl->AuxAnt_Cnt[MacId]++;
}
} else if (dm_odm->AntDivType == CGCS_RX_HW_ANTDIV) {
if (antsel_tr_mux == MAIN_ANT_CGCS_RX) {
dm_fat_tbl->MainAnt_Sum[MacId] += RxPWDBAll;
dm_fat_tbl->MainAnt_Cnt[MacId]++;
} else {
dm_fat_tbl->AuxAnt_Sum[MacId] += RxPWDBAll;
dm_fat_tbl->AuxAnt_Cnt[MacId]++;
}
}
}
static void odm_HWAntDiv(struct odm_dm_struct *dm_odm)
{
u32 i, MinRSSI = 0xFF, AntDivMaxRSSI = 0, MaxRSSI = 0, LocalMinRSSI, LocalMaxRSSI;
u32 Main_RSSI, Aux_RSSI;
u8 RxIdleAnt = 0, TargetAnt = 7;
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
struct rtw_dig *pDM_DigTable = &dm_odm->DM_DigTable;
struct sta_info *pEntry;
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
pEntry = dm_odm->pODM_StaInfo[i];
if (IS_STA_VALID(pEntry)) {
Main_RSSI = (dm_fat_tbl->MainAnt_Cnt[i] != 0) ? (dm_fat_tbl->MainAnt_Sum[i]/dm_fat_tbl->MainAnt_Cnt[i]) : 0;
Aux_RSSI = (dm_fat_tbl->AuxAnt_Cnt[i] != 0) ? (dm_fat_tbl->AuxAnt_Sum[i]/dm_fat_tbl->AuxAnt_Cnt[i]) : 0;
TargetAnt = (Main_RSSI >= Aux_RSSI) ? MAIN_ANT : AUX_ANT;
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("MacID=%d, MainAnt_Sum=%d, MainAnt_Cnt=%d\n",
i, dm_fat_tbl->MainAnt_Sum[i],
dm_fat_tbl->MainAnt_Cnt[i]));
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("MacID=%d, AuxAnt_Sum=%d, AuxAnt_Cnt=%d\n",
i, dm_fat_tbl->AuxAnt_Sum[i], dm_fat_tbl->AuxAnt_Cnt[i]));
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("MacID=%d, Main_RSSI= %d, Aux_RSSI= %d\n",
i, Main_RSSI, Aux_RSSI));
LocalMaxRSSI = (Main_RSSI > Aux_RSSI) ? Main_RSSI : Aux_RSSI;
if ((LocalMaxRSSI > AntDivMaxRSSI) && (LocalMaxRSSI < 40))
AntDivMaxRSSI = LocalMaxRSSI;
if (LocalMaxRSSI > MaxRSSI)
MaxRSSI = LocalMaxRSSI;
if ((dm_fat_tbl->RxIdleAnt == MAIN_ANT) && (Main_RSSI == 0))
Main_RSSI = Aux_RSSI;
else if ((dm_fat_tbl->RxIdleAnt == AUX_ANT) && (Aux_RSSI == 0))
Aux_RSSI = Main_RSSI;
LocalMinRSSI = (Main_RSSI > Aux_RSSI) ? Aux_RSSI : Main_RSSI;
if (LocalMinRSSI < MinRSSI) {
MinRSSI = LocalMinRSSI;
RxIdleAnt = TargetAnt;
}
if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV)
odm_UpdateTxAnt_88E(dm_odm, TargetAnt, i);
}
dm_fat_tbl->MainAnt_Sum[i] = 0;
dm_fat_tbl->AuxAnt_Sum[i] = 0;
dm_fat_tbl->MainAnt_Cnt[i] = 0;
dm_fat_tbl->AuxAnt_Cnt[i] = 0;
}
ODM_UpdateRxIdleAnt_88E(dm_odm, RxIdleAnt);
pDM_DigTable->AntDiv_RSSI_max = AntDivMaxRSSI;
pDM_DigTable->RSSI_max = MaxRSSI;
}
void ODM_AntennaDiversity_88E(struct odm_dm_struct *dm_odm)
{
struct fast_ant_train *dm_fat_tbl = &dm_odm->DM_FatTable;
struct adapter *adapter = dm_odm->Adapter;
if (!(dm_odm->SupportAbility & ODM_BB_ANT_DIV))
return;
if (!dm_odm->bLinked) {
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("ODM_AntennaDiversity_88E(): No Link.\n"));
if (dm_fat_tbl->bBecomeLinked) {
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Need to Turn off HW AntDiv\n"));
PHY_SetBBReg(adapter, ODM_REG_IGI_A_11N, BIT7, 0);
PHY_SetBBReg(adapter, ODM_REG_CCK_ANTDIV_PARA1_11N, BIT15, 0);
if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV)
PHY_SetBBReg(adapter, ODM_REG_TX_ANT_CTRL_11N, BIT21, 0);
dm_fat_tbl->bBecomeLinked = dm_odm->bLinked;
}
return;
} else {
if (!dm_fat_tbl->bBecomeLinked) {
ODM_RT_TRACE(dm_odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Need to Turn on HW AntDiv\n"));
PHY_SetBBReg(adapter, ODM_REG_IGI_A_11N, BIT7, 1);
PHY_SetBBReg(adapter, ODM_REG_CCK_ANTDIV_PARA1_11N, BIT15, 1);
if (dm_odm->AntDivType == CG_TRX_HW_ANTDIV)
PHY_SetBBReg(adapter, ODM_REG_TX_ANT_CTRL_11N, BIT21, 1);
dm_fat_tbl->bBecomeLinked = dm_odm->bLinked;
}
}
if ((dm_odm->AntDivType == CG_TRX_HW_ANTDIV) || (dm_odm->AntDivType == CGCS_RX_HW_ANTDIV))
odm_HWAntDiv(dm_odm);
}
void odm_PrimaryCCA_Init(struct odm_dm_struct *dm_odm)
{
struct dyn_primary_cca *PrimaryCCA = &(dm_odm->DM_PriCCA);
PrimaryCCA->DupRTS_flag = 0;
PrimaryCCA->intf_flag = 0;
PrimaryCCA->intf_type = 0;
PrimaryCCA->Monitor_flag = 0;
PrimaryCCA->PriCCA_flag = 0;
}
bool ODM_DynamicPrimaryCCA_DupRTS(struct odm_dm_struct *dm_odm)
{
struct dyn_primary_cca *PrimaryCCA = &(dm_odm->DM_PriCCA);
return PrimaryCCA->DupRTS_flag;
}
void odm_DynamicPrimaryCCA(struct odm_dm_struct *dm_odm)
{
return;
}
