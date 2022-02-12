void rtw_odm_dbg_comp_msg(void *sel, struct adapter *adapter)
{
u64 dbg_comp;
int i;
rtw_hal_get_def_var(adapter, HW_DEF_ODM_DBG_FLAG, &dbg_comp);
DBG_871X_SEL_NL(sel, "odm.DebugComponents = 0x%016llx\n", dbg_comp);
for (i = 0; i < RTW_ODM_COMP_MAX; i++) {
if (odm_comp_str[i])
DBG_871X_SEL_NL(sel, "%cBIT%-2d %s\n",
(BIT0 << i) & dbg_comp ? '+' : ' ',
i, odm_comp_str[i]);
}
}
inline void rtw_odm_dbg_comp_set(struct adapter *adapter, u64 comps)
{
rtw_hal_set_def_var(adapter, HW_DEF_ODM_DBG_FLAG, &comps);
}
void rtw_odm_dbg_level_msg(void *sel, struct adapter *adapter)
{
u32 dbg_level;
int i;
rtw_hal_get_def_var(adapter, HW_DEF_ODM_DBG_LEVEL, &dbg_level);
DBG_871X_SEL_NL(sel, "odm.DebugLevel = %u\n", dbg_level);
for (i = 0; i < RTW_ODM_DBG_LEVEL_NUM; i++) {
if (odm_dbg_level_str[i])
DBG_871X_SEL_NL(sel, "%u %s\n", i, odm_dbg_level_str[i]);
}
}
inline void rtw_odm_dbg_level_set(struct adapter *adapter, u32 level)
{
rtw_hal_set_def_var(adapter, HW_DEF_ODM_DBG_LEVEL, &level);
}
void rtw_odm_ability_msg(void *sel, struct adapter *adapter)
{
u32 ability = 0;
int i;
rtw_hal_get_hwreg(adapter, HW_VAR_DM_FLAG, (u8 *)&ability);
DBG_871X_SEL_NL(sel, "odm.SupportAbility = 0x%08x\n", ability);
for (i = 0; i < RTW_ODM_ABILITY_MAX; i++) {
if (odm_ability_str[i])
DBG_871X_SEL_NL(sel, "%cBIT%-2d %s\n",
(BIT0 << i) & ability ? '+' : ' ', i,
odm_ability_str[i]);
}
}
inline void rtw_odm_ability_set(struct adapter *adapter, u32 ability)
{
rtw_hal_set_hwreg(adapter, HW_VAR_DM_FLAG, (u8 *)&ability);
}
void rtw_odm_adaptivity_parm_msg(void *sel, struct adapter *adapter)
{
struct hal_com_data *pHalData = GET_HAL_DATA(adapter);
DM_ODM_T *odm = &pHalData->odmpriv;
DBG_871X_SEL_NL(sel, "%10s %16s %8s %10s %11s %14s\n"
, "TH_L2H_ini", "TH_EDCCA_HL_diff", "IGI_Base", "ForceEDCCA", "AdapEn_RSSI", "IGI_LowerBound");
DBG_871X_SEL_NL(sel, "0x%-8x %-16d 0x%-6x %-10d %-11u %-14u\n"
, (u8)odm->TH_L2H_ini
, odm->TH_EDCCA_HL_diff
, odm->IGI_Base
, odm->ForceEDCCA
, odm->AdapEn_RSSI
, odm->IGI_LowerBound
);
}
void rtw_odm_adaptivity_parm_set(struct adapter *adapter, s8 TH_L2H_ini, s8 TH_EDCCA_HL_diff,
s8 IGI_Base, bool ForceEDCCA, u8 AdapEn_RSSI, u8 IGI_LowerBound)
{
struct hal_com_data *pHalData = GET_HAL_DATA(adapter);
DM_ODM_T *odm = &pHalData->odmpriv;
odm->TH_L2H_ini = TH_L2H_ini;
odm->TH_EDCCA_HL_diff = TH_EDCCA_HL_diff;
odm->IGI_Base = IGI_Base;
odm->ForceEDCCA = ForceEDCCA;
odm->AdapEn_RSSI = AdapEn_RSSI;
odm->IGI_LowerBound = IGI_LowerBound;
}
void rtw_odm_get_perpkt_rssi(void *sel, struct adapter *adapter)
{
struct hal_com_data *hal_data = GET_HAL_DATA(adapter);
DM_ODM_T *odm = &(hal_data->odmpriv);
DBG_871X_SEL_NL(sel, "RxRate = %s, RSSI_A = %d(%%), RSSI_B = %d(%%)\n",
HDATA_RATE(odm->RxRate), odm->RSSI_A, odm->RSSI_B);
}
