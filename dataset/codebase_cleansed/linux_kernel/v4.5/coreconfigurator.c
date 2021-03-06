static inline u16 get_beacon_period(u8 *data)
{
u16 bcn_per;
bcn_per = data[0];
bcn_per |= (data[1] << 8);
return bcn_per;
}
static inline u32 get_beacon_timestamp_lo(u8 *data)
{
u32 time_stamp = 0;
u32 index = MAC_HDR_LEN;
time_stamp |= data[index++];
time_stamp |= (data[index++] << 8);
time_stamp |= (data[index++] << 16);
time_stamp |= (data[index] << 24);
return time_stamp;
}
static inline u32 get_beacon_timestamp_hi(u8 *data)
{
u32 time_stamp = 0;
u32 index = (MAC_HDR_LEN + 4);
time_stamp |= data[index++];
time_stamp |= (data[index++] << 8);
time_stamp |= (data[index++] << 16);
time_stamp |= (data[index] << 24);
return time_stamp;
}
static inline enum sub_frame_type get_sub_type(u8 *header)
{
return ((enum sub_frame_type)(header[0] & 0xFC));
}
static inline u8 get_to_ds(u8 *header)
{
return (header[1] & 0x01);
}
static inline u8 get_from_ds(u8 *header)
{
return ((header[1] & 0x02) >> 1);
}
static inline void get_address1(u8 *pu8msa, u8 *addr)
{
memcpy(addr, pu8msa + 4, 6);
}
static inline void get_address2(u8 *pu8msa, u8 *addr)
{
memcpy(addr, pu8msa + 10, 6);
}
static inline void get_address3(u8 *pu8msa, u8 *addr)
{
memcpy(addr, pu8msa + 16, 6);
}
static inline void get_BSSID(u8 *data, u8 *bssid)
{
if (get_from_ds(data) == 1)
get_address2(data, bssid);
else if (get_to_ds(data) == 1)
get_address1(data, bssid);
else
get_address3(data, bssid);
}
static inline void get_ssid(u8 *data, u8 *ssid, u8 *p_ssid_len)
{
u8 len = 0;
u8 i = 0;
u8 j = 0;
len = data[MAC_HDR_LEN + TIME_STAMP_LEN + BEACON_INTERVAL_LEN +
CAP_INFO_LEN + 1];
j = MAC_HDR_LEN + TIME_STAMP_LEN + BEACON_INTERVAL_LEN +
CAP_INFO_LEN + 2;
if (len >= MAX_SSID_LEN)
len = 0;
for (i = 0; i < len; i++, j++)
ssid[i] = data[j];
ssid[len] = '\0';
*p_ssid_len = len;
}
static inline u16 get_cap_info(u8 *data)
{
u16 cap_info = 0;
u16 index = MAC_HDR_LEN;
enum sub_frame_type st;
st = get_sub_type(data);
if ((st == BEACON) || (st == PROBE_RSP))
index += TIME_STAMP_LEN + BEACON_INTERVAL_LEN;
cap_info = data[index];
cap_info |= (data[index + 1] << 8);
return cap_info;
}
static inline u16 get_assoc_resp_cap_info(u8 *data)
{
u16 cap_info;
cap_info = data[0];
cap_info |= (data[1] << 8);
return cap_info;
}
static inline u16 get_asoc_status(u8 *data)
{
u16 asoc_status;
asoc_status = data[3];
asoc_status = (asoc_status << 8) | data[2];
return asoc_status;
}
static inline u16 get_asoc_id(u8 *data)
{
u16 asoc_id;
asoc_id = data[4];
asoc_id |= (data[5] << 8);
return asoc_id;
}
static u8 *get_tim_elm(u8 *pu8msa, u16 u16RxLen, u16 u16TagParamOffset)
{
u16 u16index;
u16index = u16TagParamOffset;
while (u16index < (u16RxLen - FCS_LEN)) {
if (pu8msa[u16index] == ITIM)
return &pu8msa[u16index];
u16index += (IE_HDR_LEN + pu8msa[u16index + 1]);
}
return NULL;
}
static u8 get_current_channel_802_11n(u8 *pu8msa, u16 u16RxLen)
{
u16 index;
index = TAG_PARAM_OFFSET;
while (index < (u16RxLen - FCS_LEN)) {
if (pu8msa[index] == IDSPARMS)
return pu8msa[index + 2];
index += pu8msa[index + 1] + IE_HDR_LEN;
}
return 0;
}
s32 wilc_parse_network_info(u8 *pu8MsgBuffer, tstrNetworkInfo **ppstrNetworkInfo)
{
tstrNetworkInfo *pstrNetworkInfo = NULL;
u8 u8MsgType = 0;
u8 u8MsgID = 0;
u16 u16MsgLen = 0;
u16 u16WidID = (u16)WID_NIL;
u16 u16WidLen = 0;
u8 *pu8WidVal = NULL;
u8MsgType = pu8MsgBuffer[0];
if ('N' != u8MsgType) {
PRINT_ER("Received Message format incorrect.\n");
return -EFAULT;
}
u8MsgID = pu8MsgBuffer[1];
u16MsgLen = MAKE_WORD16(pu8MsgBuffer[2], pu8MsgBuffer[3]);
u16WidID = MAKE_WORD16(pu8MsgBuffer[4], pu8MsgBuffer[5]);
u16WidLen = MAKE_WORD16(pu8MsgBuffer[6], pu8MsgBuffer[7]);
pu8WidVal = &pu8MsgBuffer[8];
{
u8 *pu8msa = NULL;
u16 u16RxLen = 0;
u8 *pu8TimElm = NULL;
u8 *pu8IEs = NULL;
u16 u16IEsLen = 0;
u8 u8index = 0;
u32 u32Tsf_Lo;
u32 u32Tsf_Hi;
pstrNetworkInfo = kzalloc(sizeof(tstrNetworkInfo), GFP_KERNEL);
if (!pstrNetworkInfo)
return -ENOMEM;
pstrNetworkInfo->s8rssi = pu8WidVal[0];
pu8msa = &pu8WidVal[1];
u16RxLen = u16WidLen - 1;
pstrNetworkInfo->u16CapInfo = get_cap_info(pu8msa);
pstrNetworkInfo->u32Tsf = get_beacon_timestamp_lo(pu8msa);
PRINT_D(CORECONFIG_DBG, "TSF :%x\n", pstrNetworkInfo->u32Tsf);
u32Tsf_Lo = get_beacon_timestamp_lo(pu8msa);
u32Tsf_Hi = get_beacon_timestamp_hi(pu8msa);
pstrNetworkInfo->u64Tsf = u32Tsf_Lo | ((u64)u32Tsf_Hi << 32);
get_ssid(pu8msa, pstrNetworkInfo->au8ssid, &pstrNetworkInfo->u8SsidLen);
get_BSSID(pu8msa, pstrNetworkInfo->au8bssid);
pstrNetworkInfo->u8channel = get_current_channel_802_11n(pu8msa,
u16RxLen + FCS_LEN);
u8index = MAC_HDR_LEN + TIME_STAMP_LEN;
pstrNetworkInfo->u16BeaconPeriod = get_beacon_period(pu8msa + u8index);
u8index += BEACON_INTERVAL_LEN + CAP_INFO_LEN;
pu8TimElm = get_tim_elm(pu8msa, u16RxLen + FCS_LEN, u8index);
if (pu8TimElm)
pstrNetworkInfo->u8DtimPeriod = pu8TimElm[3];
pu8IEs = &pu8msa[MAC_HDR_LEN + TIME_STAMP_LEN + BEACON_INTERVAL_LEN + CAP_INFO_LEN];
u16IEsLen = u16RxLen - (MAC_HDR_LEN + TIME_STAMP_LEN + BEACON_INTERVAL_LEN + CAP_INFO_LEN);
if (u16IEsLen > 0) {
pstrNetworkInfo->pu8IEs = kmemdup(pu8IEs, u16IEsLen,
GFP_KERNEL);
if (!pstrNetworkInfo->pu8IEs)
return -ENOMEM;
}
pstrNetworkInfo->u16IEsLen = u16IEsLen;
}
*ppstrNetworkInfo = pstrNetworkInfo;
return 0;
}
s32 wilc_dealloc_network_info(tstrNetworkInfo *pstrNetworkInfo)
{
s32 s32Error = 0;
if (pstrNetworkInfo) {
if (pstrNetworkInfo->pu8IEs) {
kfree(pstrNetworkInfo->pu8IEs);
pstrNetworkInfo->pu8IEs = NULL;
} else {
s32Error = -EFAULT;
}
kfree(pstrNetworkInfo);
pstrNetworkInfo = NULL;
} else {
s32Error = -EFAULT;
}
return s32Error;
}
s32 wilc_parse_assoc_resp_info(u8 *pu8Buffer, u32 u32BufferLen,
tstrConnectRespInfo **ppstrConnectRespInfo)
{
s32 s32Error = 0;
tstrConnectRespInfo *pstrConnectRespInfo = NULL;
u16 u16AssocRespLen = 0;
u8 *pu8IEs = NULL;
u16 u16IEsLen = 0;
pstrConnectRespInfo = kzalloc(sizeof(tstrConnectRespInfo), GFP_KERNEL);
if (!pstrConnectRespInfo)
return -ENOMEM;
u16AssocRespLen = (u16)u32BufferLen;
pstrConnectRespInfo->u16ConnectStatus = get_asoc_status(pu8Buffer);
if (pstrConnectRespInfo->u16ConnectStatus == SUCCESSFUL_STATUSCODE) {
pstrConnectRespInfo->u16capability = get_assoc_resp_cap_info(pu8Buffer);
pstrConnectRespInfo->u16AssocID = get_asoc_id(pu8Buffer);
pu8IEs = &pu8Buffer[CAP_INFO_LEN + STATUS_CODE_LEN + AID_LEN];
u16IEsLen = u16AssocRespLen - (CAP_INFO_LEN + STATUS_CODE_LEN + AID_LEN);
pstrConnectRespInfo->pu8RespIEs = kmemdup(pu8IEs, u16IEsLen, GFP_KERNEL);
if (!pstrConnectRespInfo->pu8RespIEs)
return -ENOMEM;
pstrConnectRespInfo->u16RespIEsLen = u16IEsLen;
}
*ppstrConnectRespInfo = pstrConnectRespInfo;
return s32Error;
}
s32 wilc_dealloc_assoc_resp_info(tstrConnectRespInfo *pstrConnectRespInfo)
{
s32 s32Error = 0;
if (pstrConnectRespInfo) {
if (pstrConnectRespInfo->pu8RespIEs) {
kfree(pstrConnectRespInfo->pu8RespIEs);
pstrConnectRespInfo->pu8RespIEs = NULL;
} else {
s32Error = -EFAULT;
}
kfree(pstrConnectRespInfo);
pstrConnectRespInfo = NULL;
} else {
s32Error = -EFAULT;
}
return s32Error;
}
s32 wilc_send_config_pkt(struct wilc *wilc, u8 mode, struct wid *wids,
u32 count, u32 drv)
{
s32 counter = 0, ret = 0;
if (mode == GET_CFG) {
for (counter = 0; counter < count; counter++) {
PRINT_INFO(CORECONFIG_DBG, "Sending CFG packet [%d][%d]\n", !counter,
(counter == count - 1));
if (!wilc_wlan_cfg_get(wilc, !counter,
wids[counter].id,
(counter == count - 1),
drv)) {
ret = -ETIMEDOUT;
printk("[Sendconfigpkt]Get Timed out\n");
break;
}
}
counter = 0;
for (counter = 0; counter < count; counter++) {
wids[counter].size = wilc_wlan_cfg_get_val(
wids[counter].id,
wids[counter].val,
wids[counter].size);
}
} else if (mode == SET_CFG) {
for (counter = 0; counter < count; counter++) {
PRINT_D(CORECONFIG_DBG, "Sending config SET PACKET WID:%x\n", wids[counter].id);
if (!wilc_wlan_cfg_set(wilc, !counter,
wids[counter].id,
wids[counter].val,
wids[counter].size,
(counter == count - 1),
drv)) {
ret = -ETIMEDOUT;
printk("[Sendconfigpkt]Set Timed out\n");
break;
}
}
}
return ret;
}
