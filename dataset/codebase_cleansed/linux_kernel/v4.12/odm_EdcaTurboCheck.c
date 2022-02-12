void ODM_EdcaTurboInit(void *pDM_VOID)
{
PDM_ODM_T pDM_Odm = (PDM_ODM_T)pDM_VOID;
struct adapter *Adapter = pDM_Odm->Adapter;
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = false;
pDM_Odm->DM_EDCA_Table.bIsCurRDLState = false;
Adapter->recvpriv.bIsAnyNonBEPkts = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD,
("Orginial VO PARAM: 0x%x\n",
rtw_read32(pDM_Odm->Adapter, ODM_EDCA_VO_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD,
("Orginial VI PARAM: 0x%x\n",
rtw_read32(pDM_Odm->Adapter, ODM_EDCA_VI_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD,
("Orginial BE PARAM: 0x%x\n",
rtw_read32(pDM_Odm->Adapter, ODM_EDCA_BE_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD,
("Orginial BK PARAM: 0x%x\n",
rtw_read32(pDM_Odm->Adapter, ODM_EDCA_BK_PARAM)));
}
void odm_EdcaTurboCheck(void *pDM_VOID)
{
PDM_ODM_T pDM_Odm = (PDM_ODM_T)pDM_VOID;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD,
("odm_EdcaTurboCheck ========================>\n"));
if (!(pDM_Odm->SupportAbility & ODM_MAC_EDCA_TURBO))
return;
odm_EdcaTurboCheckCE(pDM_Odm);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD,
("<========================odm_EdcaTurboCheck\n"));
}
void odm_EdcaTurboCheckCE(void *pDM_VOID)
{
PDM_ODM_T pDM_Odm = (PDM_ODM_T)pDM_VOID;
struct adapter *Adapter = pDM_Odm->Adapter;
struct dvobj_priv *pdvobjpriv = adapter_to_dvobj(Adapter);
struct recv_priv *precvpriv = &(Adapter->recvpriv);
struct registry_priv *pregpriv = &Adapter->registrypriv;
struct mlme_ext_priv *pmlmeext = &(Adapter->mlmeextpriv);
struct mlme_ext_info *pmlmeinfo = &(pmlmeext->mlmext_info);
u32 EDCA_BE_UL = 0x5ea42b;
u32 EDCA_BE_DL = 0x5ea42b;
u32 iot_peer = 0;
u8 wirelessmode = 0xFF;
u32 trafficIndex;
u32 edca_param;
u64 cur_tx_bytes = 0;
u64 cur_rx_bytes = 0;
u8 bbtchange = false;
u8 biasonrx = false;
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
if (!pDM_Odm->bLinked) {
precvpriv->bIsAnyNonBEPkts = false;
return;
}
if ((pregpriv->wifi_spec == 1)) {
precvpriv->bIsAnyNonBEPkts = false;
return;
}
if (pDM_Odm->pwirelessmode)
wirelessmode = *(pDM_Odm->pwirelessmode);
iot_peer = pmlmeinfo->assoc_AP_vendor;
if (iot_peer >= HT_IOT_PEER_MAX) {
precvpriv->bIsAnyNonBEPkts = false;
return;
}
if ((bbtchange) || (!precvpriv->bIsAnyNonBEPkts)) {
cur_tx_bytes = pdvobjpriv->traffic_stat.cur_tx_bytes;
cur_rx_bytes = pdvobjpriv->traffic_stat.cur_rx_bytes;
if (biasonrx) {
if (cur_tx_bytes > (cur_rx_bytes << 2)) {
trafficIndex = UP_LINK;
} else {
trafficIndex = DOWN_LINK;
}
} else {
if (cur_rx_bytes > (cur_tx_bytes << 2)) {
trafficIndex = DOWN_LINK;
} else {
trafficIndex = UP_LINK;
}
}
if ((iot_peer == HT_IOT_PEER_CISCO) &&
(wirelessmode == ODM_WM_N24G)) {
EDCA_BE_DL = edca_setting_DL[iot_peer];
EDCA_BE_UL = edca_setting_UL[iot_peer];
} else if ((iot_peer == HT_IOT_PEER_CISCO) &&
((wirelessmode == ODM_WM_G) ||
(wirelessmode == (ODM_WM_B | ODM_WM_G)) ||
(wirelessmode == ODM_WM_A) ||
(wirelessmode == ODM_WM_B))) {
EDCA_BE_DL = edca_setting_DL_GMode[iot_peer];
} else if ((iot_peer == HT_IOT_PEER_AIRGO) &&
((wirelessmode == ODM_WM_G) ||
(wirelessmode == ODM_WM_A))) {
EDCA_BE_DL = 0xa630;
} else if (iot_peer == HT_IOT_PEER_MARVELL) {
EDCA_BE_DL = edca_setting_DL[iot_peer];
EDCA_BE_UL = edca_setting_UL[iot_peer];
} else if (iot_peer == HT_IOT_PEER_ATHEROS) {
EDCA_BE_DL = edca_setting_DL[iot_peer];
}
if (trafficIndex == DOWN_LINK)
edca_param = EDCA_BE_DL;
else
edca_param = EDCA_BE_UL;
rtw_write32(Adapter, REG_EDCA_BE_PARAM, edca_param);
pDM_Odm->DM_EDCA_Table.prv_traffic_idx = trafficIndex;
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = true;
} else {
if (pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA) {
rtw_write32(Adapter, REG_EDCA_BE_PARAM, pHalData->AcParam_BE);
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = false;
}
}
}
