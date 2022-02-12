static void dm_InitGPIOSetting(struct adapter *Adapter)
{
u8 tmp1byte;
tmp1byte = usb_read8(Adapter, REG_GPIO_MUXCFG);
tmp1byte &= (GPIOSEL_GPIO | ~GPIOSEL_ENBT);
usb_write8(Adapter, REG_GPIO_MUXCFG, tmp1byte);
}
static void Init_ODM_ComInfo_88E(struct adapter *Adapter)
{
struct hal_data_8188e *hal_data = Adapter->HalData;
struct dm_priv *pdmpriv = &hal_data->dmpriv;
struct odm_dm_struct *dm_odm = &(hal_data->odmpriv);
memset(dm_odm, 0, sizeof(*dm_odm));
dm_odm->Adapter = Adapter;
dm_odm->SupportPlatform = ODM_CE;
dm_odm->SupportICType = ODM_RTL8188E;
dm_odm->CutVersion = ODM_CUT_A;
dm_odm->bIsMPChip = hal_data->VersionID.ChipType == NORMAL_CHIP;
dm_odm->PatchID = hal_data->CustomerID;
dm_odm->bWIFITest = Adapter->registrypriv.wifi_spec;
dm_odm->AntDivType = hal_data->TRxAntDivType;
dm_odm->BbSwingIdxOfdm = 12;
dm_odm->BbSwingIdxOfdmCurrent = 12;
dm_odm->BbSwingFlagOfdm = false;
pdmpriv->InitODMFlag = ODM_RF_CALIBRATION |
ODM_RF_TX_PWR_TRACK;
dm_odm->SupportAbility = pdmpriv->InitODMFlag;
}
static void Update_ODM_ComInfo_88E(struct adapter *Adapter)
{
struct mlme_ext_priv *pmlmeext = &Adapter->mlmeextpriv;
struct mlme_priv *pmlmepriv = &Adapter->mlmepriv;
struct pwrctrl_priv *pwrctrlpriv = &Adapter->pwrctrlpriv;
struct hal_data_8188e *hal_data = Adapter->HalData;
struct odm_dm_struct *dm_odm = &(hal_data->odmpriv);
struct dm_priv *pdmpriv = &hal_data->dmpriv;
int i;
pdmpriv->InitODMFlag = ODM_BB_DIG |
ODM_BB_RA_MASK |
ODM_BB_DYNAMIC_TXPWR |
ODM_BB_FA_CNT |
ODM_BB_RSSI_MONITOR |
ODM_BB_CCK_PD |
ODM_BB_PWR_SAVE |
ODM_MAC_EDCA_TURBO |
ODM_RF_CALIBRATION |
ODM_RF_TX_PWR_TRACK;
if (hal_data->AntDivCfg)
pdmpriv->InitODMFlag |= ODM_BB_ANT_DIV;
if (Adapter->registrypriv.mp_mode == 1) {
pdmpriv->InitODMFlag = ODM_RF_CALIBRATION |
ODM_RF_TX_PWR_TRACK;
}
dm_odm->SupportAbility = pdmpriv->InitODMFlag;
dm_odm->pNumTxBytesUnicast = &Adapter->xmitpriv.tx_bytes;
dm_odm->pNumRxBytesUnicast = &Adapter->recvpriv.rx_bytes;
dm_odm->pWirelessMode = &pmlmeext->cur_wireless_mode;
dm_odm->pSecChOffset = &hal_data->nCur40MhzPrimeSC;
dm_odm->pSecurity = (u8 *)&Adapter->securitypriv.dot11PrivacyAlgrthm;
dm_odm->pBandWidth = (u8 *)&hal_data->CurrentChannelBW;
dm_odm->pChannel = &hal_data->CurrentChannel;
dm_odm->pbNet_closed = (bool *)&Adapter->net_closed;
dm_odm->mp_mode = &Adapter->registrypriv.mp_mode;
dm_odm->pbScanInProcess = (bool *)&pmlmepriv->bScanInProcess;
dm_odm->pbPowerSaving = (bool *)&pwrctrlpriv->bpower_saving;
dm_odm->AntDivType = hal_data->TRxAntDivType;
dm_odm->BbSwingIdxOfdm = 12;
dm_odm->BbSwingIdxOfdmCurrent = 12;
dm_odm->BbSwingFlagOfdm = false;
for (i = 0; i < NUM_STA; i++)
ODM_CmnInfoPtrArrayHook(dm_odm, ODM_CMNINFO_STA_STATUS, i, NULL);
}
void rtl8188e_InitHalDm(struct adapter *Adapter)
{
struct dm_priv *pdmpriv = &Adapter->HalData->dmpriv;
struct odm_dm_struct *dm_odm = &(Adapter->HalData->odmpriv);
dm_InitGPIOSetting(Adapter);
pdmpriv->DM_Type = DM_Type_ByDriver;
pdmpriv->DMFlag = DYNAMIC_FUNC_DISABLE;
Update_ODM_ComInfo_88E(Adapter);
ODM_DMInit(dm_odm);
}
void rtw_hal_dm_watchdog(struct adapter *Adapter)
{
u8 hw_init_completed = false;
struct mlme_priv *pmlmepriv = NULL;
u8 bLinked = false;
hw_init_completed = Adapter->hw_init_completed;
if (!hw_init_completed)
goto skip_dm;
pmlmepriv = &Adapter->mlmepriv;
if ((check_fwstate(pmlmepriv, WIFI_AP_STATE)) ||
(check_fwstate(pmlmepriv, WIFI_ADHOC_STATE |
WIFI_ADHOC_MASTER_STATE))) {
if (Adapter->stapriv.asoc_sta_count > 2)
bLinked = true;
} else {
if (check_fwstate(pmlmepriv, _FW_LINKED))
bLinked = true;
}
Adapter->HalData->odmpriv.bLinked = bLinked;
ODM_DMWatchdog(&Adapter->HalData->odmpriv);
skip_dm:
return;
}
void rtw_hal_dm_init(struct adapter *Adapter)
{
struct dm_priv *pdmpriv = &Adapter->HalData->dmpriv;
struct odm_dm_struct *podmpriv = &Adapter->HalData->odmpriv;
memset(pdmpriv, 0, sizeof(struct dm_priv));
Init_ODM_ComInfo_88E(Adapter);
ODM_InitDebugSetting(podmpriv);
}
void rtw_hal_antdiv_rssi_compared(struct adapter *Adapter, struct wlan_bssid_ex *dst, struct wlan_bssid_ex *src)
{
if (0 != Adapter->HalData->AntDivCfg) {
if (dst->Rssi >= src->Rssi) {
src->Rssi = dst->Rssi;
src->PhyInfo.Optimum_antenna = dst->PhyInfo.Optimum_antenna;
}
}
}
u8 rtw_hal_antdiv_before_linked(struct adapter *Adapter)
{
struct odm_dm_struct *dm_odm = &Adapter->HalData->odmpriv;
struct sw_ant_switch *dm_swat_tbl = &dm_odm->DM_SWAT_Table;
struct mlme_priv *pmlmepriv = &(Adapter->mlmepriv);
if (Adapter->HalData->AntDivCfg == 0)
return false;
if (check_fwstate(pmlmepriv, _FW_LINKED))
return false;
if (dm_swat_tbl->SWAS_NoLink_State == 0) {
dm_swat_tbl->SWAS_NoLink_State = 1;
dm_swat_tbl->CurAntenna = (dm_swat_tbl->CurAntenna == Antenna_A) ? Antenna_B : Antenna_A;
rtw_antenna_select_cmd(Adapter, dm_swat_tbl->CurAntenna, false);
return true;
} else {
dm_swat_tbl->SWAS_NoLink_State = 0;
return false;
}
}
