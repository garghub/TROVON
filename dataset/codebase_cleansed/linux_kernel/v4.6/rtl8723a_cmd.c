static u8 _is_fw_read_cmd_down(struct rtw_adapter *padapter, u8 msgbox_num)
{
u8 read_down = false;
int retry_cnts = 100;
u8 valid;
do {
valid = rtl8723au_read8(padapter, REG_HMETFR) & BIT(msgbox_num);
if (0 == valid)
read_down = true;
} while ((!read_down) && (retry_cnts--));
return read_down;
}
int FillH2CCmd(struct rtw_adapter *padapter, u8 ElementID, u32 CmdLen,
u8 *pCmdBuffer)
{
u8 bcmd_down = false;
s32 retry_cnts = 100;
u8 h2c_box_num;
u32 msgbox_addr;
u32 msgbox_ex_addr;
struct hal_data_8723a *pHalData;
u32 h2c_cmd = 0;
u16 h2c_cmd_ex = 0;
int ret = _FAIL;
padapter = GET_PRIMARY_ADAPTER(padapter);
pHalData = GET_HAL_DATA(padapter);
mutex_lock(&adapter_to_dvobj(padapter)->h2c_fwcmd_mutex);
if (!pCmdBuffer)
goto exit;
if (CmdLen > RTL92C_MAX_CMD_LEN)
goto exit;
if (padapter->bSurpriseRemoved == true)
goto exit;
do {
h2c_box_num = pHalData->LastHMEBoxNum;
if (!_is_fw_read_cmd_down(padapter, h2c_box_num)) {
DBG_8723A(" fw read cmd failed...\n");
goto exit;
}
if (CmdLen <= 3) {
memcpy((u8 *)(&h2c_cmd)+1, pCmdBuffer, CmdLen);
} else {
memcpy((u8 *)(&h2c_cmd_ex), pCmdBuffer, EX_MESSAGE_BOX_SIZE);
memcpy((u8 *)(&h2c_cmd)+1, pCmdBuffer+2, (CmdLen-EX_MESSAGE_BOX_SIZE));
*(u8 *)(&h2c_cmd) |= BIT(7);
}
*(u8 *)(&h2c_cmd) |= ElementID;
if (h2c_cmd & BIT(7)) {
msgbox_ex_addr = REG_HMEBOX_EXT_0 + (h2c_box_num * EX_MESSAGE_BOX_SIZE);
h2c_cmd_ex = le16_to_cpu(h2c_cmd_ex);
rtl8723au_write16(padapter, msgbox_ex_addr, h2c_cmd_ex);
}
msgbox_addr = REG_HMEBOX_0 + (h2c_box_num * MESSAGE_BOX_SIZE);
h2c_cmd = le32_to_cpu(h2c_cmd);
rtl8723au_write32(padapter, msgbox_addr, h2c_cmd);
bcmd_down = true;
pHalData->LastHMEBoxNum = (h2c_box_num+1) % RTL92C_MAX_H2C_BOX_NUMS;
} while ((!bcmd_down) && (retry_cnts--));
ret = _SUCCESS;
exit:
mutex_unlock(&adapter_to_dvobj(padapter)->h2c_fwcmd_mutex);
return ret;
}
int rtl8723a_set_rssi_cmd(struct rtw_adapter *padapter, u32 param)
{
__le32 cmd = cpu_to_le32(param);
FillH2CCmd(padapter, RSSI_SETTING_EID, 3, (void *)&cmd);
return _SUCCESS;
}
int rtl8723a_set_raid_cmd(struct rtw_adapter *padapter, u32 mask, u8 arg)
{
u8 buf[5];
memset(buf, 0, 5);
put_unaligned_le32(mask, buf);
buf[4] = arg;
FillH2CCmd(padapter, MACID_CONFIG_EID, 5, buf);
return _SUCCESS;
}
void rtl8723a_add_rateatid(struct rtw_adapter *pAdapter, u32 bitmap, u8 arg, u8 rssi_level)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
u8 macid = arg & 0x1f;
u32 raid = bitmap & 0xf0000000;
bitmap &= 0x0fffffff;
if (rssi_level != DM_RATR_STA_INIT)
bitmap = ODM_Get_Rate_Bitmap23a(pHalData, macid, bitmap,
rssi_level);
bitmap |= raid;
rtl8723a_set_raid_cmd(pAdapter, bitmap, arg);
}
void rtl8723a_set_FwPwrMode_cmd(struct rtw_adapter *padapter, u8 Mode)
{
struct setpwrmode_parm H2CSetPwrMode;
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
DBG_8723A("%s: Mode =%d SmartPS =%d UAPSD =%d BcnMode = 0x%02x\n", __func__,
Mode, pwrpriv->smart_ps, padapter->registrypriv.uapsd_enable, pwrpriv->bcn_ant_mode);
if (Mode != PS_MODE_ACTIVE && pHalData->rf_type != RF_2T2R)
ODM_RF_Saving23a(&pHalData->odmpriv, true);
H2CSetPwrMode.Mode = Mode;
H2CSetPwrMode.SmartPS = pwrpriv->smart_ps;
H2CSetPwrMode.AwakeInterval = 1;
H2CSetPwrMode.bAllQueueUAPSD = padapter->registrypriv.uapsd_enable;
H2CSetPwrMode.BcnAntMode = pwrpriv->bcn_ant_mode;
FillH2CCmd(padapter, SET_PWRMODE_EID, sizeof(H2CSetPwrMode), (u8 *)&H2CSetPwrMode);
}
static void
ConstructBeacon(struct rtw_adapter *padapter, u8 *pframe, u32 *pLength)
{
struct ieee80211_mgmt *mgmt;
u32 rate_len, pktlen;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
struct wlan_bssid_ex *cur_network = &pmlmeinfo->network;
u8 bc_addr[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
mgmt = (struct ieee80211_mgmt *)pframe;
mgmt->frame_control =
cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_BEACON);
ether_addr_copy(mgmt->da, bc_addr);
ether_addr_copy(mgmt->sa, myid(&padapter->eeprompriv));
ether_addr_copy(mgmt->bssid, get_my_bssid23a(cur_network));
mgmt->seq_ctrl = 0;
put_unaligned_le16(cur_network->beacon_interval,
&mgmt->u.beacon.beacon_int);
put_unaligned_le16(cur_network->capability,
&mgmt->u.beacon.capab_info);
pframe = mgmt->u.beacon.variable;
pktlen = offsetof(struct ieee80211_mgmt, u.beacon.variable);
if ((pmlmeinfo->state&0x03) == MSR_AP) {
pktlen += cur_network->IELength;
memcpy(pframe, cur_network->IEs, pktlen);
goto _ConstructBeacon;
}
pframe = rtw_set_ie23a(pframe, WLAN_EID_SSID,
cur_network->Ssid.ssid_len,
cur_network->Ssid.ssid, &pktlen);
rate_len = rtw_get_rateset_len23a(cur_network->SupportedRates);
pframe = rtw_set_ie23a(pframe, WLAN_EID_SUPP_RATES, ((rate_len > 8) ?
8 : rate_len), cur_network->SupportedRates, &pktlen);
pframe = rtw_set_ie23a(pframe, WLAN_EID_DS_PARAMS, 1, (unsigned char *)
&cur_network->DSConfig, &pktlen);
if ((pmlmeinfo->state&0x03) == MSR_ADHOC) {
u32 ATIMWindow;
ATIMWindow = 0;
pframe = rtw_set_ie23a(pframe, WLAN_EID_IBSS_PARAMS, 2,
(unsigned char *)&ATIMWindow, &pktlen);
}
if (rate_len > 8)
pframe = rtw_set_ie23a(pframe, WLAN_EID_EXT_SUPP_RATES,
(rate_len - 8),
(cur_network->SupportedRates + 8),
&pktlen);
_ConstructBeacon:
if ((pktlen + TXDESC_SIZE) > 512) {
DBG_8723A("beacon frame too large\n");
return;
}
*pLength = pktlen;
}
static void ConstructPSPoll(struct rtw_adapter *padapter,
u8 *pframe, u32 *pLength)
{
struct ieee80211_hdr *pwlanhdr;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
pwlanhdr = (struct ieee80211_hdr *)pframe;
pwlanhdr->frame_control =
cpu_to_le16(IEEE80211_FTYPE_CTL | IEEE80211_STYPE_PSPOLL);
pwlanhdr->frame_control |= cpu_to_le16(IEEE80211_FCTL_PM);
pwlanhdr->duration_id = cpu_to_le16(pmlmeinfo->aid | 0xc000);
memcpy(pwlanhdr->addr1, get_my_bssid23a(&pmlmeinfo->network), ETH_ALEN);
memcpy(pwlanhdr->addr2, myid(&padapter->eeprompriv), ETH_ALEN);
*pLength = 16;
}
static void
ConstructNullFunctionData(struct rtw_adapter *padapter, u8 *pframe,
u32 *pLength, u8 *StaAddr, u8 bQoS, u8 AC,
u8 bEosp, u8 bForcePowerSave)
{
struct ieee80211_hdr *pwlanhdr;
u32 pktlen;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct wlan_network *cur_network = &pmlmepriv->cur_network;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
pwlanhdr = (struct ieee80211_hdr *)pframe;
pwlanhdr->frame_control = 0;
pwlanhdr->seq_ctrl = 0;
if (bForcePowerSave)
pwlanhdr->frame_control |= cpu_to_le16(IEEE80211_FCTL_PM);
switch (cur_network->network.ifmode) {
case NL80211_IFTYPE_P2P_CLIENT:
case NL80211_IFTYPE_STATION:
pwlanhdr->frame_control |= cpu_to_le16(IEEE80211_FCTL_TODS);
memcpy(pwlanhdr->addr1,
get_my_bssid23a(&pmlmeinfo->network), ETH_ALEN);
memcpy(pwlanhdr->addr2, myid(&padapter->eeprompriv),
ETH_ALEN);
memcpy(pwlanhdr->addr3, StaAddr, ETH_ALEN);
break;
case NL80211_IFTYPE_P2P_GO:
case NL80211_IFTYPE_AP:
pwlanhdr->frame_control |= cpu_to_le16(IEEE80211_FCTL_FROMDS);
memcpy(pwlanhdr->addr1, StaAddr, ETH_ALEN);
memcpy(pwlanhdr->addr2,
get_my_bssid23a(&pmlmeinfo->network), ETH_ALEN);
memcpy(pwlanhdr->addr3, myid(&padapter->eeprompriv),
ETH_ALEN);
break;
case NL80211_IFTYPE_ADHOC:
default:
memcpy(pwlanhdr->addr1, StaAddr, ETH_ALEN);
memcpy(pwlanhdr->addr2, myid(&padapter->eeprompriv), ETH_ALEN);
memcpy(pwlanhdr->addr3,
get_my_bssid23a(&pmlmeinfo->network), ETH_ALEN);
break;
}
if (bQoS == true) {
struct ieee80211_qos_hdr *qoshdr;
qoshdr = (struct ieee80211_qos_hdr *)pframe;
qoshdr->frame_control |=
cpu_to_le16(IEEE80211_FTYPE_DATA |
IEEE80211_STYPE_QOS_NULLFUNC);
qoshdr->qos_ctrl = cpu_to_le16(AC & IEEE80211_QOS_CTL_TID_MASK);
if (bEosp)
qoshdr->qos_ctrl |= cpu_to_le16(IEEE80211_QOS_CTL_EOSP);
pktlen = sizeof(struct ieee80211_qos_hdr);
} else {
pwlanhdr->frame_control |=
cpu_to_le16(IEEE80211_FTYPE_DATA |
IEEE80211_STYPE_NULLFUNC);
pktlen = sizeof(struct ieee80211_hdr_3addr);
}
*pLength = pktlen;
}
static void ConstructProbeRsp(struct rtw_adapter *padapter, u8 *pframe,
u32 *pLength, u8 *StaAddr, bool bHideSSID)
{
struct ieee80211_mgmt *mgmt;
u8 *mac, *bssid;
u32 pktlen;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
struct wlan_bssid_ex *cur_network = &pmlmeinfo->network;
mgmt = (struct ieee80211_mgmt *)pframe;
mac = myid(&padapter->eeprompriv);
bssid = cur_network->MacAddress;
mgmt->frame_control =
cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_PROBE_RESP);
mgmt->seq_ctrl = 0;
memcpy(mgmt->da, StaAddr, ETH_ALEN);
memcpy(mgmt->sa, mac, ETH_ALEN);
memcpy(mgmt->bssid, bssid, ETH_ALEN);
put_unaligned_le64(cur_network->tsf,
&mgmt->u.probe_resp.timestamp);
put_unaligned_le16(cur_network->beacon_interval,
&mgmt->u.probe_resp.beacon_int);
put_unaligned_le16(cur_network->capability,
&mgmt->u.probe_resp.capab_info);
pktlen = offsetof(struct ieee80211_mgmt, u.probe_resp.variable);
if (cur_network->IELength > MAX_IE_SZ)
return;
memcpy(mgmt->u.probe_resp.variable, cur_network->IEs,
cur_network->IELength);
pktlen += (cur_network->IELength);
*pLength = pktlen;
}
static void SetFwRsvdPagePkt(struct rtw_adapter *padapter, bool bDLFinished)
{
struct hal_data_8723a *pHalData;
struct xmit_frame *pmgntframe;
struct pkt_attrib *pattrib;
struct xmit_priv *pxmitpriv;
struct mlme_ext_priv *pmlmeext;
struct mlme_ext_info *pmlmeinfo;
u32 BeaconLength = 0, ProbeRspLength = 0, PSPollLength;
u32 NullDataLength, QosNullLength, BTQosNullLength;
u8 *ReservedPagePacket;
u8 PageNum, PageNeed, TxDescLen;
u16 BufIndex;
u32 TotalPacketLen;
struct rsvdpage_loc RsvdPageLoc;
DBG_8723A("%s\n", __func__);
ReservedPagePacket = kzalloc(1000, GFP_KERNEL);
if (ReservedPagePacket == NULL) {
DBG_8723A("%s: alloc ReservedPagePacket fail!\n", __func__);
return;
}
pHalData = GET_HAL_DATA(padapter);
pxmitpriv = &padapter->xmitpriv;
pmlmeext = &padapter->mlmeextpriv;
pmlmeinfo = &pmlmeext->mlmext_info;
TxDescLen = TXDESC_SIZE;
PageNum = 0;
BufIndex = TXDESC_OFFSET;
ConstructBeacon(padapter, &ReservedPagePacket[BufIndex], &BeaconLength);
PageNeed = (u8)PageNum_128(TxDescLen + BeaconLength);
if (PageNeed == 1)
PageNeed += 1;
PageNum += PageNeed;
pHalData->FwRsvdPageStartOffset = PageNum;
BufIndex += PageNeed*128;
RsvdPageLoc.LocPsPoll = PageNum;
ConstructPSPoll(padapter, &ReservedPagePacket[BufIndex], &PSPollLength);
rtl8723a_fill_fake_txdesc(padapter, &ReservedPagePacket[BufIndex-TxDescLen], PSPollLength, true, false);
PageNeed = (u8)PageNum_128(TxDescLen + PSPollLength);
PageNum += PageNeed;
BufIndex += PageNeed*128;
RsvdPageLoc.LocNullData = PageNum;
ConstructNullFunctionData(padapter, &ReservedPagePacket[BufIndex],
&NullDataLength,
get_my_bssid23a(&pmlmeinfo->network),
false, 0, 0, false);
rtl8723a_fill_fake_txdesc(padapter,
&ReservedPagePacket[BufIndex-TxDescLen],
NullDataLength, false, false);
PageNeed = (u8)PageNum_128(TxDescLen + NullDataLength);
PageNum += PageNeed;
BufIndex += PageNeed*128;
RsvdPageLoc.LocProbeRsp = PageNum;
ConstructProbeRsp(
padapter,
&ReservedPagePacket[BufIndex],
&ProbeRspLength,
get_my_bssid23a(&pmlmeinfo->network),
false);
rtl8723a_fill_fake_txdesc(padapter, &ReservedPagePacket[BufIndex-TxDescLen], ProbeRspLength, false, false);
PageNeed = (u8)PageNum_128(TxDescLen + ProbeRspLength);
PageNum += PageNeed;
BufIndex += PageNeed*128;
RsvdPageLoc.LocQosNull = PageNum;
ConstructNullFunctionData(
padapter,
&ReservedPagePacket[BufIndex],
&QosNullLength,
get_my_bssid23a(&pmlmeinfo->network),
true, 0, 0, false);
rtl8723a_fill_fake_txdesc(padapter, &ReservedPagePacket[BufIndex-TxDescLen], QosNullLength, false, false);
PageNeed = (u8)PageNum_128(TxDescLen + QosNullLength);
PageNum += PageNeed;
BufIndex += PageNeed*128;
RsvdPageLoc.LocBTQosNull = PageNum;
ConstructNullFunctionData(
padapter,
&ReservedPagePacket[BufIndex],
&BTQosNullLength,
get_my_bssid23a(&pmlmeinfo->network),
true, 0, 0, false);
rtl8723a_fill_fake_txdesc(padapter, &ReservedPagePacket[BufIndex-TxDescLen], BTQosNullLength, false, true);
TotalPacketLen = BufIndex + BTQosNullLength;
pmgntframe = alloc_mgtxmitframe23a(pxmitpriv);
if (pmgntframe == NULL)
goto exit;
pattrib = &pmgntframe->attrib;
update_mgntframe_attrib23a(padapter, pattrib);
pattrib->qsel = 0x10;
pattrib->pktlen = pattrib->last_txcmdsz = TotalPacketLen - TXDESC_OFFSET;
memcpy(pmgntframe->buf_addr, ReservedPagePacket, TotalPacketLen);
rtl8723au_mgnt_xmit(padapter, pmgntframe);
DBG_8723A("%s: Set RSVD page location to Fw\n", __func__);
FillH2CCmd(padapter, RSVD_PAGE_EID, sizeof(RsvdPageLoc), (u8 *)&RsvdPageLoc);
exit:
kfree(ReservedPagePacket);
}
void rtl8723a_set_FwJoinBssReport_cmd(struct rtw_adapter *padapter, u8 mstatus)
{
struct joinbssrpt_parm JoinBssRptParm;
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
DBG_8723A("%s mstatus(%x)\n", __func__, mstatus);
if (mstatus == 1) {
bool bRecover = false;
u8 v8;
rtl8723au_write16(padapter, REG_BCN_PSR_RPT,
0xC000|pmlmeinfo->aid);
v8 = rtl8723au_read8(padapter, REG_CR+1);
v8 |= BIT(0);
rtl8723au_write8(padapter, REG_CR+1, v8);
SetBcnCtrlReg23a(padapter, BIT(4), BIT(3));
if (pHalData->RegFwHwTxQCtrl & BIT(6))
bRecover = true;
rtl8723au_write8(padapter, REG_FWHW_TXQ_CTRL + 2,
pHalData->RegFwHwTxQCtrl & ~BIT(6));
pHalData->RegFwHwTxQCtrl &= ~BIT(6);
SetFwRsvdPagePkt(padapter, 0);
SetBcnCtrlReg23a(padapter, BIT(3), BIT(4));
if (bRecover) {
rtl8723au_write8(padapter, REG_FWHW_TXQ_CTRL + 2,
pHalData->RegFwHwTxQCtrl | BIT(6));
pHalData->RegFwHwTxQCtrl |= BIT(6);
}
v8 = rtl8723au_read8(padapter, REG_CR+1);
v8 &= ~BIT(0);
rtl8723au_write8(padapter, REG_CR+1, v8);
}
JoinBssRptParm.OpMode = mstatus;
FillH2CCmd(padapter, JOINBSS_RPT_EID, sizeof(JoinBssRptParm), (u8 *)&JoinBssRptParm);
}
static void SetFwRsvdPagePkt_BTCoex(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData;
struct xmit_frame *pmgntframe;
struct pkt_attrib *pattrib;
struct xmit_priv *pxmitpriv;
struct mlme_ext_priv *pmlmeext;
struct mlme_ext_info *pmlmeinfo;
u8 fakemac[6] = {0x00, 0xe0, 0x4c, 0x00, 0x00, 0x00};
u32 NullDataLength, BTQosNullLength;
u8 *ReservedPagePacket;
u8 PageNum, PageNeed, TxDescLen;
u16 BufIndex;
u32 TotalPacketLen;
struct rsvdpage_loc RsvdPageLoc;
DBG_8723A("+%s\n", __func__);
ReservedPagePacket = kzalloc(1024, GFP_KERNEL);
if (ReservedPagePacket == NULL) {
DBG_8723A("%s: alloc ReservedPagePacket fail!\n", __func__);
return;
}
pHalData = GET_HAL_DATA(padapter);
pxmitpriv = &padapter->xmitpriv;
pmlmeext = &padapter->mlmeextpriv;
pmlmeinfo = &pmlmeext->mlmext_info;
TxDescLen = TXDESC_SIZE;
PageNum = 0;
BufIndex = TXDESC_OFFSET;
PageNeed = 3;
PageNum += PageNeed;
pHalData->FwRsvdPageStartOffset = PageNum;
BufIndex += PageNeed*128;
RsvdPageLoc.LocNullData = PageNum;
ConstructNullFunctionData(
padapter,
&ReservedPagePacket[BufIndex],
&NullDataLength,
fakemac,
false, 0, 0, false);
rtl8723a_fill_fake_txdesc(padapter, &ReservedPagePacket[BufIndex-TxDescLen], NullDataLength, false, false);
PageNeed = (u8)PageNum_128(TxDescLen + NullDataLength);
PageNum += PageNeed;
BufIndex += PageNeed*128;
RsvdPageLoc.LocBTQosNull = PageNum;
ConstructNullFunctionData(
padapter,
&ReservedPagePacket[BufIndex],
&BTQosNullLength,
fakemac,
true, 0, 0, false);
rtl8723a_fill_fake_txdesc(padapter, &ReservedPagePacket[BufIndex-TxDescLen], BTQosNullLength, false, true);
TotalPacketLen = BufIndex + BTQosNullLength;
pmgntframe = alloc_mgtxmitframe23a(pxmitpriv);
if (pmgntframe == NULL)
goto exit;
pattrib = &pmgntframe->attrib;
update_mgntframe_attrib23a(padapter, pattrib);
pattrib->qsel = 0x10;
pattrib->pktlen = pattrib->last_txcmdsz = TotalPacketLen - TXDESC_OFFSET;
memcpy(pmgntframe->buf_addr, ReservedPagePacket, TotalPacketLen);
rtl8723au_mgnt_xmit(padapter, pmgntframe);
DBG_8723A("%s: Set RSVD page location to Fw\n", __func__);
FillH2CCmd(padapter, RSVD_PAGE_EID, sizeof(RsvdPageLoc), (u8 *)&RsvdPageLoc);
exit:
kfree(ReservedPagePacket);
}
void rtl8723a_set_BTCoex_AP_mode_FwRsvdPkt_cmd(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData;
u8 bRecover = false;
DBG_8723A("+%s\n", __func__);
pHalData = GET_HAL_DATA(padapter);
if (pHalData->RegFwHwTxQCtrl & BIT(6))
bRecover = true;
pHalData->RegFwHwTxQCtrl &= ~BIT(6);
rtl8723au_write8(padapter, REG_FWHW_TXQ_CTRL + 2,
pHalData->RegFwHwTxQCtrl);
SetFwRsvdPagePkt_BTCoex(padapter);
if (bRecover) {
pHalData->RegFwHwTxQCtrl |= BIT(6);
rtl8723au_write8(padapter, REG_FWHW_TXQ_CTRL + 2,
pHalData->RegFwHwTxQCtrl);
}
}
