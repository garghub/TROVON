INLINE u8 ascii_hex_to_dec(u8 num)
{
if ((num >= '0') && (num <= '9'))
return (num - '0');
else if ((num >= 'A') && (num <= 'F'))
return (10 + (num - 'A'));
else if ((num >= 'a') && (num <= 'f'))
return (10 + (num - 'a'));
return INVALID;
}
INLINE u8 get_hex_char(u8 inp)
{
u8 *d2htab = "0123456789ABCDEF";
return d2htab[inp & 0xF];
}
INLINE u16 extract_mac_addr(char *str, u8 *buff)
{
*buff = 0;
while (*str != '\0') {
if ((*str == ':') || (*str == '-'))
*(++buff) = 0;
else
*buff = (*buff << 4) + ascii_hex_to_dec(*str);
str++;
}
return MAC_ADDR_LEN;
}
INLINE void create_mac_addr(u8 *str, u8 *buff)
{
u32 i = 0;
u32 j = 0;
for (i = 0; i < MAC_ADDR_LEN; i++) {
str[j++] = get_hex_char((u8)((buff[i] >> 4) & 0x0F));
str[j++] = get_hex_char((u8)(buff[i] & 0x0F));
str[j++] = ':';
}
str[--j] = '\0';
}
INLINE u8 conv_ip_to_int(u8 *ips, u32 *ipn)
{
u8 i = 0;
u8 ipb = 0;
*ipn = 0;
while (ips[i] != '\0') {
if (ips[i] == '.') {
*ipn = ((*ipn) << 8) | ipb;
ipb = 0;
} else {
ipb = ipb * 10 + ascii_hex_to_dec(ips[i]);
}
i++;
}
*ipn = ((*ipn) << 8) | ipb;
return 0;
}
INLINE u8 conv_int_to_ip(u8 *ips, u32 ipn)
{
u8 i = 0;
u8 ipb = 0;
u8 cnt = 0;
u8 ipbsize = 0;
for (cnt = 4; cnt > 0; cnt--) {
ipb = (ipn >> (8 * (cnt - 1))) & 0xFF;
if (ipb >= 100)
ipbsize = 2;
else if (ipb >= 10)
ipbsize = 1;
else
ipbsize = 0;
switch (ipbsize) {
case 2:
ips[i++] = get_hex_char(ipb / 100);
ipb %= 100;
case 1:
ips[i++] = get_hex_char(ipb / 10);
ipb %= 10;
default:
ips[i++] = get_hex_char(ipb);
}
if (cnt > 1)
ips[i++] = '.';
}
ips[i] = '\0';
return i;
}
INLINE tenuWIDtype get_wid_type(u32 wid_num)
{
if ((wid_num == WID_BSSID) ||
(wid_num == WID_MAC_ADDR) ||
(wid_num == WID_IP_ADDRESS) ||
(wid_num == WID_HUT_DEST_ADDR)) {
return WID_ADR;
}
if ((WID_1X_SERV_ADDR == wid_num) ||
(WID_STACK_IP_ADDR == wid_num) ||
(WID_STACK_NETMASK_ADDR == wid_num)) {
return WID_IP;
}
if (wid_num < 0x1000)
return WID_CHAR;
else if (wid_num < 0x2000)
return WID_SHORT;
else if (wid_num < 0x3000)
return WID_INT;
else if (wid_num < 0x4000)
return WID_STR;
else if (wid_num < 0x5000)
return WID_BIN_DATA;
return WID_UNDEF;
}
INLINE u16 get_beacon_period(u8 *data)
{
u16 bcn_per = 0;
bcn_per = data[0];
bcn_per |= (data[1] << 8);
return bcn_per;
}
INLINE u32 get_beacon_timestamp_lo(u8 *data)
{
u32 time_stamp = 0;
u32 index = MAC_HDR_LEN;
time_stamp |= data[index++];
time_stamp |= (data[index++] << 8);
time_stamp |= (data[index++] << 16);
time_stamp |= (data[index] << 24);
return time_stamp;
}
INLINE u32 get_beacon_timestamp_hi(u8 *data)
{
u32 time_stamp = 0;
u32 index = (MAC_HDR_LEN + 4);
time_stamp |= data[index++];
time_stamp |= (data[index++] << 8);
time_stamp |= (data[index++] << 16);
time_stamp |= (data[index] << 24);
return time_stamp;
}
INLINE tenuBasicFrmType get_type(u8 *header)
{
return ((tenuBasicFrmType)(header[0] & 0x0C));
}
INLINE tenuFrmSubtype get_sub_type(u8 *header)
{
return ((tenuFrmSubtype)(header[0] & 0xFC));
}
INLINE u8 get_to_ds(u8 *header)
{
return (header[1] & 0x01);
}
INLINE u8 get_from_ds(u8 *header)
{
return ((header[1] & 0x02) >> 1);
}
INLINE void get_address1(u8 *pu8msa, u8 *addr)
{
WILC_memcpy(addr, pu8msa + 4, 6);
}
INLINE void get_address2(u8 *pu8msa, u8 *addr)
{
WILC_memcpy(addr, pu8msa + 10, 6);
}
INLINE void get_address3(u8 *pu8msa, u8 *addr)
{
WILC_memcpy(addr, pu8msa + 16, 6);
}
INLINE void get_BSSID(u8 *data, u8 *bssid)
{
if (get_from_ds(data) == 1)
get_address2(data, bssid);
else if (get_to_ds(data) == 1)
get_address1(data, bssid);
else
get_address3(data, bssid);
}
INLINE void get_ssid(u8 *data, u8 *ssid, u8 *p_ssid_len)
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
INLINE u16 get_cap_info(u8 *data)
{
u16 cap_info = 0;
u16 index = MAC_HDR_LEN;
tenuFrmSubtype st = BEACON;
st = get_sub_type(data);
if ((st == BEACON) || (st == PROBE_RSP))
index += TIME_STAMP_LEN + BEACON_INTERVAL_LEN;
cap_info = data[index];
cap_info |= (data[index + 1] << 8);
return cap_info;
}
INLINE u16 get_assoc_resp_cap_info(u8 *data)
{
u16 cap_info = 0;
cap_info = data[0];
cap_info |= (data[1] << 8);
return cap_info;
}
INLINE u16 get_asoc_status(u8 *data)
{
u16 asoc_status = 0;
asoc_status = data[3];
asoc_status = (asoc_status << 8) | data[2];
return asoc_status;
}
INLINE u16 get_asoc_id(u8 *data)
{
u16 asoc_id = 0;
asoc_id = data[4];
asoc_id |= (data[5] << 8);
return asoc_id;
}
s32 CoreConfiguratorInit(void)
{
s32 s32Error = WILC_SUCCESS;
PRINT_D(CORECONFIG_DBG, "CoreConfiguratorInit()\n");
sema_init(&SemHandleSendPkt, 1);
sema_init(&SemHandlePktResp, 0);
gps8ConfigPacket = (s8 *)WILC_MALLOC(MAX_PACKET_BUFF_SIZE);
if (gps8ConfigPacket == NULL) {
PRINT_ER("failed in gps8ConfigPacket allocation\n");
s32Error = WILC_NO_MEM;
goto _fail_;
}
WILC_memset((void *)gps8ConfigPacket, 0, MAX_PACKET_BUFF_SIZE);
WILC_memset((void *)(&gstrConfigPktInfo), 0, sizeof(tstrConfigPktInfo));
_fail_:
return s32Error;
}
u8 *get_tim_elm(u8 *pu8msa, u16 u16RxLen, u16 u16TagParamOffset)
{
u16 u16index = 0;
u16index = u16TagParamOffset;
while (u16index < (u16RxLen - FCS_LEN)) {
if (pu8msa[u16index] == ITIM) {
return &pu8msa[u16index];
} else {
u16index += (IE_HDR_LEN + pu8msa[u16index + 1]);
}
}
return 0;
}
u8 get_current_channel_802_11n(u8 *pu8msa, u16 u16RxLen)
{
u16 index;
index = TAG_PARAM_OFFSET;
while (index < (u16RxLen - FCS_LEN)) {
if (pu8msa[index] == IDSPARMS)
return pu8msa[index + 2];
else
index += pu8msa[index + 1] + IE_HDR_LEN;
}
return 0;
}
u8 get_current_channel(u8 *pu8msa, u16 u16RxLen)
{
#ifdef PHY_802_11n
#ifdef FIVE_GHZ_BAND
return (get_rf_channel() + 1);
#else
return get_current_channel_802_11n(pu8msa, u16RxLen);
#endif
#else
return 0;
#endif
}
s32 ParseNetworkInfo(u8 *pu8MsgBuffer, tstrNetworkInfo **ppstrNetworkInfo)
{
s32 s32Error = WILC_SUCCESS;
tstrNetworkInfo *pstrNetworkInfo = NULL;
u8 u8MsgType = 0;
u8 u8MsgID = 0;
u16 u16MsgLen = 0;
u16 u16WidID = (u16)WID_NIL;
u16 u16WidLen = 0;
u8 *pu8WidVal = 0;
u8MsgType = pu8MsgBuffer[0];
if ('N' != u8MsgType) {
PRINT_ER("Received Message format incorrect.\n");
WILC_ERRORREPORT(s32Error, WILC_FAIL);
}
u8MsgID = pu8MsgBuffer[1];
u16MsgLen = MAKE_WORD16(pu8MsgBuffer[2], pu8MsgBuffer[3]);
u16WidID = MAKE_WORD16(pu8MsgBuffer[4], pu8MsgBuffer[5]);
u16WidLen = MAKE_WORD16(pu8MsgBuffer[6], pu8MsgBuffer[7]);
pu8WidVal = &pu8MsgBuffer[8];
{
u8 *pu8msa = 0;
u16 u16RxLen = 0;
u8 *pu8TimElm = 0;
u8 *pu8IEs = 0;
u16 u16IEsLen = 0;
u8 u8index = 0;
u32 u32Tsf_Lo;
u32 u32Tsf_Hi;
pstrNetworkInfo = (tstrNetworkInfo *)WILC_MALLOC(sizeof(tstrNetworkInfo));
WILC_memset((void *)(pstrNetworkInfo), 0, sizeof(tstrNetworkInfo));
pstrNetworkInfo->s8rssi = pu8WidVal[0];
pu8msa = &pu8WidVal[1];
u16RxLen = u16WidLen - 1;
pstrNetworkInfo->u16CapInfo = get_cap_info(pu8msa);
#ifdef WILC_P2P
pstrNetworkInfo->u32Tsf = get_beacon_timestamp_lo(pu8msa);
PRINT_D(CORECONFIG_DBG, "TSF :%x\n", pstrNetworkInfo->u32Tsf);
#endif
u32Tsf_Lo = get_beacon_timestamp_lo(pu8msa);
u32Tsf_Hi = get_beacon_timestamp_hi(pu8msa);
pstrNetworkInfo->u64Tsf = u32Tsf_Lo | ((u64)u32Tsf_Hi << 32);
get_ssid(pu8msa, pstrNetworkInfo->au8ssid, &(pstrNetworkInfo->u8SsidLen));
get_BSSID(pu8msa, pstrNetworkInfo->au8bssid);
pstrNetworkInfo->u8channel = get_current_channel(pu8msa, (u16RxLen + FCS_LEN));
u8index = (MAC_HDR_LEN + TIME_STAMP_LEN);
pstrNetworkInfo->u16BeaconPeriod = get_beacon_period(pu8msa + u8index);
u8index += BEACON_INTERVAL_LEN + CAP_INFO_LEN;
pu8TimElm = get_tim_elm(pu8msa, (u16RxLen + FCS_LEN), u8index);
if (pu8TimElm != 0) {
pstrNetworkInfo->u8DtimPeriod = pu8TimElm[3];
}
pu8IEs = &pu8msa[MAC_HDR_LEN + TIME_STAMP_LEN + BEACON_INTERVAL_LEN + CAP_INFO_LEN];
u16IEsLen = u16RxLen - (MAC_HDR_LEN + TIME_STAMP_LEN + BEACON_INTERVAL_LEN + CAP_INFO_LEN);
if (u16IEsLen > 0) {
pstrNetworkInfo->pu8IEs = (u8 *)WILC_MALLOC(u16IEsLen);
WILC_memset((void *)(pstrNetworkInfo->pu8IEs), 0, u16IEsLen);
WILC_memcpy(pstrNetworkInfo->pu8IEs, pu8IEs, u16IEsLen);
}
pstrNetworkInfo->u16IEsLen = u16IEsLen;
}
*ppstrNetworkInfo = pstrNetworkInfo;
ERRORHANDLER:
return s32Error;
}
s32 DeallocateNetworkInfo(tstrNetworkInfo *pstrNetworkInfo)
{
s32 s32Error = WILC_SUCCESS;
if (pstrNetworkInfo != NULL) {
if (pstrNetworkInfo->pu8IEs != NULL) {
WILC_FREE(pstrNetworkInfo->pu8IEs);
pstrNetworkInfo->pu8IEs = NULL;
} else {
s32Error = WILC_FAIL;
}
WILC_FREE(pstrNetworkInfo);
pstrNetworkInfo = NULL;
} else {
s32Error = WILC_FAIL;
}
return s32Error;
}
s32 ParseAssocRespInfo(u8 *pu8Buffer, u32 u32BufferLen,
tstrConnectRespInfo **ppstrConnectRespInfo)
{
s32 s32Error = WILC_SUCCESS;
tstrConnectRespInfo *pstrConnectRespInfo = NULL;
u16 u16AssocRespLen = 0;
u8 *pu8IEs = 0;
u16 u16IEsLen = 0;
pstrConnectRespInfo = (tstrConnectRespInfo *)WILC_MALLOC(sizeof(tstrConnectRespInfo));
WILC_memset((void *)(pstrConnectRespInfo), 0, sizeof(tstrConnectRespInfo));
u16AssocRespLen = (u16)u32BufferLen;
pstrConnectRespInfo->u16ConnectStatus = get_asoc_status(pu8Buffer);
if (pstrConnectRespInfo->u16ConnectStatus == SUCCESSFUL_STATUSCODE) {
pstrConnectRespInfo->u16capability = get_assoc_resp_cap_info(pu8Buffer);
pstrConnectRespInfo->u16AssocID = get_asoc_id(pu8Buffer);
pu8IEs = &pu8Buffer[CAP_INFO_LEN + STATUS_CODE_LEN + AID_LEN];
u16IEsLen = u16AssocRespLen - (CAP_INFO_LEN + STATUS_CODE_LEN + AID_LEN);
pstrConnectRespInfo->pu8RespIEs = (u8 *)WILC_MALLOC(u16IEsLen);
WILC_memset((void *)(pstrConnectRespInfo->pu8RespIEs), 0, u16IEsLen);
WILC_memcpy(pstrConnectRespInfo->pu8RespIEs, pu8IEs, u16IEsLen);
pstrConnectRespInfo->u16RespIEsLen = u16IEsLen;
}
*ppstrConnectRespInfo = pstrConnectRespInfo;
return s32Error;
}
s32 DeallocateAssocRespInfo(tstrConnectRespInfo *pstrConnectRespInfo)
{
s32 s32Error = WILC_SUCCESS;
if (pstrConnectRespInfo != NULL) {
if (pstrConnectRespInfo->pu8RespIEs != NULL) {
WILC_FREE(pstrConnectRespInfo->pu8RespIEs);
pstrConnectRespInfo->pu8RespIEs = NULL;
} else {
s32Error = WILC_FAIL;
}
WILC_FREE(pstrConnectRespInfo);
pstrConnectRespInfo = NULL;
} else {
s32Error = WILC_FAIL;
}
return s32Error;
}
s32 ParseSurveyResults(u8 ppu8RcvdSiteSurveyResults[][MAX_SURVEY_RESULT_FRAG_SIZE],
wid_site_survey_reslts_s **ppstrSurveyResults,
u32 *pu32SurveyResultsCount)
{
s32 s32Error = WILC_SUCCESS;
wid_site_survey_reslts_s *pstrSurveyResults = NULL;
u32 u32SurveyResultsCount = 0;
u32 u32SurveyBytesLength = 0;
u8 *pu8BufferPtr;
u32 u32RcvdSurveyResultsNum = 2;
u8 u8ReadSurveyResFragNum;
u32 i;
u32 j;
for (i = 0; i < u32RcvdSurveyResultsNum; i++) {
u32SurveyBytesLength = ppu8RcvdSiteSurveyResults[i][0];
for (j = 0; j < u32SurveyBytesLength; j += SURVEY_RESULT_LENGTH) {
u32SurveyResultsCount++;
}
}
pstrSurveyResults = (wid_site_survey_reslts_s *)WILC_MALLOC(u32SurveyResultsCount * sizeof(wid_site_survey_reslts_s));
if (pstrSurveyResults == NULL) {
u32SurveyResultsCount = 0;
WILC_ERRORREPORT(s32Error, WILC_NO_MEM);
}
WILC_memset((void *)(pstrSurveyResults), 0, u32SurveyResultsCount * sizeof(wid_site_survey_reslts_s));
u32SurveyResultsCount = 0;
for (i = 0; i < u32RcvdSurveyResultsNum; i++) {
pu8BufferPtr = ppu8RcvdSiteSurveyResults[i];
u32SurveyBytesLength = pu8BufferPtr[0];
u8ReadSurveyResFragNum = pu8BufferPtr[1];
pu8BufferPtr += 2;
for (j = 0; j < u32SurveyBytesLength; j += SURVEY_RESULT_LENGTH) {
WILC_memcpy(&pstrSurveyResults[u32SurveyResultsCount], pu8BufferPtr, SURVEY_RESULT_LENGTH);
pu8BufferPtr += SURVEY_RESULT_LENGTH;
u32SurveyResultsCount++;
}
}
ERRORHANDLER:
*ppstrSurveyResults = pstrSurveyResults;
*pu32SurveyResultsCount = u32SurveyResultsCount;
return s32Error;
}
s32 DeallocateSurveyResults(wid_site_survey_reslts_s *pstrSurveyResults)
{
s32 s32Error = WILC_SUCCESS;
if (pstrSurveyResults != NULL) {
WILC_FREE(pstrSurveyResults);
}
return s32Error;
}
void ProcessCharWid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, s8 *ps8WidVal)
{
u8 *pu8val = (u8 *)ps8WidVal;
u8 u8val = 0;
s32 s32PktLen = *ps32PktLen;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set CHAR val 0x%x ,NULL structure\n", u8val);
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid >> 8) & 0xFF;
if (g_oper_mode == SET_CFG) {
u8val = *pu8val;
pcPacket[s32PktLen++] = sizeof(u8);
pcPacket[s32PktLen++] = u8val;
}
*ps32PktLen = s32PktLen;
}
void ProcessShortWid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, s8 *ps8WidVal)
{
u16 *pu16val = (u16 *)ps8WidVal;
u16 u16val = 0;
s32 s32PktLen = *ps32PktLen;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set SHORT val 0x%x ,NULL structure\n", u16val);
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)((pstrWID->u16WIDid >> 8) & 0xFF);
if (g_oper_mode == SET_CFG) {
u16val = *pu16val;
pcPacket[s32PktLen++] = sizeof(u16);
pcPacket[s32PktLen++] = (u8)(u16val & 0xFF);
pcPacket[s32PktLen++] = (u8)((u16val >> 8) & 0xFF);
}
*ps32PktLen = s32PktLen;
}
void ProcessIntWid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, s8 *ps8WidVal)
{
u32 *pu32val = (u32 *)ps8WidVal;
u32 u32val = 0;
s32 s32PktLen = *ps32PktLen;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set INT val 0x%x , NULL structure\n", u32val);
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)((pstrWID->u16WIDid >> 8) & 0xFF);
if (g_oper_mode == SET_CFG) {
u32val = *pu32val;
pcPacket[s32PktLen++] = sizeof(u32);
pcPacket[s32PktLen++] = (u8)(u32val & 0xFF);
pcPacket[s32PktLen++] = (u8)((u32val >> 8) & 0xFF);
pcPacket[s32PktLen++] = (u8)((u32val >> 16) & 0xFF);
pcPacket[s32PktLen++] = (u8)((u32val >> 24) & 0xFF);
}
*ps32PktLen = s32PktLen;
}
void ProcessIPwid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, u8 *pu8ip)
{
u32 u32val = 0;
s32 s32PktLen = *ps32PktLen;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set IP Addr , NULL structure\n");
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)((pstrWID->u16WIDid >> 8) & 0xFF);
if (g_oper_mode == SET_CFG) {
pcPacket[s32PktLen++] = sizeof(u32);
conv_ip_to_int(pu8ip, &u32val);
pcPacket[s32PktLen++] = (u8)(u32val & 0xFF);
pcPacket[s32PktLen++] = (u8)((u32val >> 8) & 0xFF);
pcPacket[s32PktLen++] = (u8)((u32val >> 16) & 0xFF);
pcPacket[s32PktLen++] = (u8)((u32val >> 24) & 0xFF);
}
*ps32PktLen = s32PktLen;
}
void ProcessStrWid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, u8 *pu8val, s32 s32ValueSize)
{
u16 u16MsgLen = 0;
u16 idx = 0;
s32 s32PktLen = *ps32PktLen;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set STR val, NULL structure\n");
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)((pstrWID->u16WIDid >> 8) & 0xFF);
if (g_oper_mode == SET_CFG) {
u16MsgLen = (u16)s32ValueSize;
pcPacket[s32PktLen++] = (u8)u16MsgLen;
for (idx = 0; idx < u16MsgLen; idx++)
pcPacket[s32PktLen++] = pu8val[idx];
}
*ps32PktLen = s32PktLen;
}
void ProcessAdrWid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, u8 *pu8val)
{
u16 u16MsgLen = 0;
s32 s32PktLen = *ps32PktLen;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set Addr WID, NULL structure\n");
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)((pstrWID->u16WIDid >> 8) & 0xFF);
if (g_oper_mode == SET_CFG) {
u16MsgLen = MAC_ADDR_LEN;
pcPacket[s32PktLen++] = (u8)u16MsgLen;
extract_mac_addr(pu8val, pcPacket + s32PktLen);
s32PktLen += u16MsgLen;
}
*ps32PktLen = s32PktLen;
}
void ProcessBinWid(char *pcPacket, s32 *ps32PktLen,
tstrWID *pstrWID, u8 *pu8val, s32 s32ValueSize)
{
u16 u16MsgLen = 0;
u16 idx = 0;
s32 s32PktLen = *ps32PktLen;
u8 u8checksum = 0;
if (pstrWID == NULL) {
PRINT_WRN(CORECONFIG_DBG, "Can't set BIN val, NULL structure\n");
return;
}
pcPacket[s32PktLen++] = (u8)(pstrWID->u16WIDid & 0xFF);
pcPacket[s32PktLen++] = (u8)((pstrWID->u16WIDid >> 8) & 0xFF);
if (g_oper_mode == SET_CFG) {
u16MsgLen = (u16)s32ValueSize;
pcPacket[s32PktLen++] = (u8)(u16MsgLen & 0xFF);
pcPacket[s32PktLen++] = (u8)((u16MsgLen >> 8) & 0xFF);
for (idx = 0; idx < u16MsgLen; idx++)
pcPacket[s32PktLen++] = pu8val[idx];
for (idx = 0; idx < u16MsgLen; idx++)
u8checksum += pcPacket[MSG_HEADER_LEN + idx + 4];
pcPacket[s32PktLen++] = u8checksum;
}
*ps32PktLen = s32PktLen;
}
s32 further_process_response(u8 *resp,
u16 u16WIDid,
u16 cfg_len,
bool process_wid_num,
u32 cnt,
tstrWID *pstrWIDresult)
{
u32 retval = 0;
u32 idx = 0;
u8 cfg_chr = 0;
u16 cfg_sht = 0;
u32 cfg_int = 0;
u8 cfg_str[256] = {0};
tenuWIDtype enuWIDtype = WID_UNDEF;
if (process_wid_num) {
enuWIDtype = get_wid_type(g_wid_num);
} else {
enuWIDtype = gastrWIDs[cnt].enuWIDtype;
}
switch (enuWIDtype) {
case WID_CHAR:
cfg_chr = resp[idx];
*(pstrWIDresult->ps8WidVal) = cfg_chr;
break;
case WID_SHORT:
{
u16 *pu16val = (u16 *)(pstrWIDresult->ps8WidVal);
cfg_sht = MAKE_WORD16(resp[idx], resp[idx + 1]);
*pu16val = cfg_sht;
break;
}
case WID_INT:
{
u32 *pu32val = (u32 *)(pstrWIDresult->ps8WidVal);
cfg_int = MAKE_WORD32(
MAKE_WORD16(resp[idx], resp[idx + 1]),
MAKE_WORD16(resp[idx + 2], resp[idx + 3])
);
*pu32val = cfg_int;
break;
}
case WID_STR:
WILC_memcpy(cfg_str, resp + idx, cfg_len);
if (process_wid_num) {
} else {
}
if (pstrWIDresult->s32ValueSize >= cfg_len) {
WILC_memcpy(pstrWIDresult->ps8WidVal, cfg_str, cfg_len);
pstrWIDresult->s32ValueSize = cfg_len;
} else {
PRINT_ER("allocated WID buffer length is smaller than the received WID Length\n");
retval = -2;
}
break;
case WID_ADR:
create_mac_addr(cfg_str, resp + idx);
WILC_strncpy(pstrWIDresult->ps8WidVal, cfg_str, WILC_strlen(cfg_str));
pstrWIDresult->ps8WidVal[WILC_strlen(cfg_str)] = '\0';
if (process_wid_num) {
} else {
}
break;
case WID_IP:
cfg_int = MAKE_WORD32(
MAKE_WORD16(resp[idx], resp[idx + 1]),
MAKE_WORD16(resp[idx + 2], resp[idx + 3])
);
conv_int_to_ip(cfg_str, cfg_int);
if (process_wid_num) {
} else {
}
break;
case WID_BIN_DATA:
if (pstrWIDresult->s32ValueSize >= cfg_len) {
WILC_memcpy(pstrWIDresult->ps8WidVal, resp + idx, cfg_len);
pstrWIDresult->s32ValueSize = cfg_len;
} else {
PRINT_ER("Allocated WID buffer length is smaller than the received WID Length Err(%d)\n", retval);
retval = -2;
}
break;
default:
PRINT_ER("ERROR: Check config database: Error(%d)\n", retval);
retval = -2;
break;
}
return retval;
}
s32 ParseResponse(u8 *resp, tstrWID *pstrWIDcfgResult)
{
u16 u16RespLen = 0;
u16 u16WIDid = 0;
u16 cfg_len = 0;
tenuWIDtype enuWIDtype = WID_UNDEF;
bool num_wid_processed = false;
u32 cnt = 0;
u32 idx = 0;
u32 ResCnt = 0;
if (RESP_MSG_TYPE != resp[0]) {
PRINT_INFO(CORECONFIG_DBG, "Received Message format incorrect.\n");
return -1;
}
u16RespLen = MAKE_WORD16(resp[2], resp[3]);
Res_Len = u16RespLen;
for (idx = MSG_HEADER_LEN; idx < u16RespLen; ) {
u16WIDid = MAKE_WORD16(resp[idx], resp[idx + 1]);
cfg_len = resp[idx + 2];
enuWIDtype = get_wid_type(u16WIDid);
if (WID_BIN_DATA == enuWIDtype) {
cfg_len |= ((u16)resp[idx + 3] << 8) & 0xFF00;
idx++;
}
idx += 3;
if ((u16WIDid == g_wid_num) && (!num_wid_processed)) {
num_wid_processed = true;
if (-2 == further_process_response(&resp[idx], u16WIDid, cfg_len, true, 0, &pstrWIDcfgResult[ResCnt])) {
return -2;
}
ResCnt++;
} else {
for (cnt = 0; cnt < g_num_total_switches; cnt++) {
if (gastrWIDs[cnt].u16WIDid == u16WIDid) {
if (-2 == further_process_response(&resp[idx], u16WIDid, cfg_len, false, cnt,
&pstrWIDcfgResult[ResCnt])) {
return -2;
}
ResCnt++;
}
}
}
idx += cfg_len;
if (WID_BIN_DATA == enuWIDtype) {
idx++;
}
}
return 0;
}
s32 ParseWriteResponse(u8 *pu8RespBuffer)
{
s32 s32Error = WILC_FAIL;
u16 u16RespLen = 0;
u16 u16WIDtype = (u16)WID_NIL;
if (RESP_MSG_TYPE != pu8RespBuffer[0]) {
PRINT_ER("Received Message format incorrect.\n");
return WILC_FAIL;
}
u16RespLen = MAKE_WORD16(pu8RespBuffer[2], pu8RespBuffer[3]);
u16WIDtype = MAKE_WORD16(pu8RespBuffer[4], pu8RespBuffer[5]);
if ((u16WIDtype == WID_STATUS) &&
(pu8RespBuffer[6] == 1) &&
(pu8RespBuffer[7] == WRITE_RESP_SUCCESS)) {
s32Error = WRITE_RESP_SUCCESS;
return s32Error;
}
s32Error = WILC_FAIL;
return s32Error;
}
s32 CreatePacketHeader(char *pcpacket, s32 *ps32PacketLength)
{
s32 s32Error = WILC_SUCCESS;
u16 u16MsgLen = (u16)(*ps32PacketLength);
u16 u16MsgInd = 0;
if (g_oper_mode == SET_CFG)
pcpacket[u16MsgInd++] = WRITE_MSG_TYPE;
else
pcpacket[u16MsgInd++] = QUERY_MSG_TYPE;
pcpacket[u16MsgInd++] = g_seqno++;
pcpacket[u16MsgInd++] = (u8)(u16MsgLen & 0xFF);
pcpacket[u16MsgInd++] = (u8)((u16MsgLen >> 8) & 0xFF);
*ps32PacketLength = u16MsgLen;
return s32Error;
}
s32 CreateConfigPacket(s8 *ps8packet, s32 *ps32PacketLength,
tstrWID *pstrWIDs, u32 u32WIDsCount)
{
s32 s32Error = WILC_SUCCESS;
u32 u32idx = 0;
*ps32PacketLength = MSG_HEADER_LEN;
for (u32idx = 0; u32idx < u32WIDsCount; u32idx++) {
switch (pstrWIDs[u32idx].enuWIDtype) {
case WID_CHAR:
ProcessCharWid(ps8packet, ps32PacketLength, &pstrWIDs[u32idx],
pstrWIDs[u32idx].ps8WidVal);
break;
case WID_SHORT:
ProcessShortWid(ps8packet, ps32PacketLength, &pstrWIDs[u32idx],
pstrWIDs[u32idx].ps8WidVal);
break;
case WID_INT:
ProcessIntWid(ps8packet, ps32PacketLength, &pstrWIDs[u32idx],
pstrWIDs[u32idx].ps8WidVal);
break;
case WID_STR:
ProcessStrWid(ps8packet, ps32PacketLength, &pstrWIDs[u32idx],
pstrWIDs[u32idx].ps8WidVal, pstrWIDs[u32idx].s32ValueSize);
break;
case WID_IP:
ProcessIPwid(ps8packet, ps32PacketLength, &pstrWIDs[u32idx],
pstrWIDs[u32idx].ps8WidVal);
break;
case WID_BIN_DATA:
ProcessBinWid(ps8packet, ps32PacketLength, &pstrWIDs[u32idx],
pstrWIDs[u32idx].ps8WidVal, pstrWIDs[u32idx].s32ValueSize);
break;
default:
PRINT_ER("ERROR: Check Config database\n");
}
}
CreatePacketHeader(ps8packet, ps32PacketLength);
return s32Error;
}
s32 ConfigWaitResponse(char *pcRespBuffer, s32 s32MaxRespBuffLen, s32 *ps32BytesRead,
bool bRespRequired)
{
s32 s32Error = WILC_SUCCESS;
if (gstrConfigPktInfo.bRespRequired) {
down(&SemHandlePktResp);
*ps32BytesRead = gstrConfigPktInfo.s32BytesRead;
}
WILC_memset((void *)(&gstrConfigPktInfo), 0, sizeof(tstrConfigPktInfo));
return s32Error;
}
s32 SendConfigPkt(u8 u8Mode, tstrWID *pstrWIDs,
u32 u32WIDsCount, bool bRespRequired, u32 drvHandler)
{
s32 s32Error = WILC_SUCCESS;
s32 err = WILC_SUCCESS;
s32 s32ConfigPacketLen = 0;
s32 s32RcvdRespLen = 0;
down(&SemHandleSendPkt);
g_oper_mode = u8Mode;
WILC_memset((void *)gps8ConfigPacket, 0, MAX_PACKET_BUFF_SIZE);
if (CreateConfigPacket(gps8ConfigPacket, &s32ConfigPacketLen, pstrWIDs, u32WIDsCount) != WILC_SUCCESS) {
s32Error = WILC_FAIL;
goto End_ConfigPkt;
}
gstrConfigPktInfo.pcRespBuffer = gps8ConfigPacket;
gstrConfigPktInfo.s32MaxRespBuffLen = MAX_PACKET_BUFF_SIZE;
PRINT_INFO(CORECONFIG_DBG, "GLOBAL =bRespRequired =%d\n", bRespRequired);
gstrConfigPktInfo.bRespRequired = bRespRequired;
s32Error = SendRawPacket(gps8ConfigPacket, s32ConfigPacketLen);
if (s32Error != WILC_SUCCESS) {
goto End_ConfigPkt;
}
WILC_memset((void *)gps8ConfigPacket, 0, MAX_PACKET_BUFF_SIZE);
ConfigWaitResponse(gps8ConfigPacket, MAX_PACKET_BUFF_SIZE, &s32RcvdRespLen, bRespRequired);
if (bRespRequired) {
if (g_oper_mode == GET_CFG) {
#if 1
err = ParseResponse(gps8ConfigPacket, pstrWIDs);
if (err != 0) {
s32Error = WILC_FAIL;
goto End_ConfigPkt;
} else {
s32Error = WILC_SUCCESS;
}
#endif
} else {
err = ParseWriteResponse(gps8ConfigPacket);
if (err != WRITE_RESP_SUCCESS) {
s32Error = WILC_FAIL;
goto End_ConfigPkt;
} else {
s32Error = WILC_SUCCESS;
}
}
}
End_ConfigPkt:
up(&SemHandleSendPkt);
return s32Error;
}
s32 ConfigProvideResponse(char *pcRespBuffer, s32 s32RespLen)
{
s32 s32Error = WILC_SUCCESS;
if (gstrConfigPktInfo.bRespRequired) {
if (s32RespLen <= gstrConfigPktInfo.s32MaxRespBuffLen) {
WILC_memcpy(gstrConfigPktInfo.pcRespBuffer, pcRespBuffer, s32RespLen);
gstrConfigPktInfo.s32BytesRead = s32RespLen;
} else {
WILC_memcpy(gstrConfigPktInfo.pcRespBuffer, pcRespBuffer, gstrConfigPktInfo.s32MaxRespBuffLen);
gstrConfigPktInfo.s32BytesRead = gstrConfigPktInfo.s32MaxRespBuffLen;
PRINT_ER("BusProvideResponse() Response greater than the prepared Buffer Size\n");
}
up(&SemHandlePktResp);
}
return s32Error;
}
s32 ConfigPktReceived(u8 *pu8RxPacket, s32 s32RxPacketLen)
{
s32 s32Error = WILC_SUCCESS;
u8 u8MsgType = 0;
u8MsgType = pu8RxPacket[0];
switch (u8MsgType) {
case 'R':
ConfigProvideResponse(pu8RxPacket, s32RxPacketLen);
break;
case 'N':
PRINT_INFO(CORECONFIG_DBG, "NetworkInfo packet received\n");
NetworkInfoReceived(pu8RxPacket, s32RxPacketLen);
break;
case 'I':
GnrlAsyncInfoReceived(pu8RxPacket, s32RxPacketLen);
break;
case 'S':
host_int_ScanCompleteReceived(pu8RxPacket, s32RxPacketLen);
break;
default:
PRINT_ER("ConfigPktReceived(): invalid received msg type at the Core Configurator\n");
break;
}
return s32Error;
}
s32 CoreConfiguratorDeInit(void)
{
s32 s32Error = WILC_SUCCESS;
PRINT_D(CORECONFIG_DBG, "CoreConfiguratorDeInit()\n");
if (gps8ConfigPacket != NULL) {
WILC_FREE(gps8ConfigPacket);
gps8ConfigPacket = NULL;
}
return s32Error;
}
s32 SendConfigPkt(u8 u8Mode, tstrWID *pstrWIDs,
u32 u32WIDsCount, bool bRespRequired, u32 drvHandler)
{
s32 counter = 0, ret = 0;
if (gpstrWlanOps == NULL) {
PRINT_D(CORECONFIG_DBG, "Net Dev is still not initialized\n");
return 1;
} else {
PRINT_D(CORECONFIG_DBG, "Net Dev is initialized\n");
}
if (gpstrWlanOps->wlan_cfg_set == NULL ||
gpstrWlanOps->wlan_cfg_get == NULL) {
PRINT_D(CORECONFIG_DBG, "Set and Get is still not initialized\n");
return 1;
} else {
PRINT_D(CORECONFIG_DBG, "SET is initialized\n");
}
if (u8Mode == GET_CFG) {
for (counter = 0; counter < u32WIDsCount; counter++) {
PRINT_INFO(CORECONFIG_DBG, "Sending CFG packet [%d][%d]\n", !counter,
(counter == u32WIDsCount - 1));
if (!gpstrWlanOps->wlan_cfg_get(!counter,
pstrWIDs[counter].u16WIDid,
(counter == u32WIDsCount - 1), drvHandler)) {
ret = -1;
printk("[Sendconfigpkt]Get Timed out\n");
break;
}
}
counter = 0;
for (counter = 0; counter < u32WIDsCount; counter++) {
pstrWIDs[counter].s32ValueSize = gpstrWlanOps->wlan_cfg_get_value(
pstrWIDs[counter].u16WIDid,
pstrWIDs[counter].ps8WidVal, pstrWIDs[counter].s32ValueSize);
}
} else if (u8Mode == SET_CFG) {
for (counter = 0; counter < u32WIDsCount; counter++) {
PRINT_D(CORECONFIG_DBG, "Sending config SET PACKET WID:%x\n", pstrWIDs[counter].u16WIDid);
if (!gpstrWlanOps->wlan_cfg_set(!counter,
pstrWIDs[counter].u16WIDid, pstrWIDs[counter].ps8WidVal,
pstrWIDs[counter].s32ValueSize,
(counter == u32WIDsCount - 1), drvHandler)) {
ret = -1;
printk("[Sendconfigpkt]Set Timed out\n");
break;
}
}
}
return ret;
}
