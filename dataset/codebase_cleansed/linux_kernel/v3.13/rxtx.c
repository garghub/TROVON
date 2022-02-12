static void *s_vGetFreeContext(struct vnt_private *pDevice)
{
struct vnt_usb_send_context *pContext = NULL;
struct vnt_usb_send_context *pReturnContext = NULL;
int ii;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"GetFreeContext()\n");
for (ii = 0; ii < pDevice->cbTD; ii++) {
if (!pDevice->apTD[ii])
return NULL;
pContext = pDevice->apTD[ii];
if (pContext->bBoolInUse == false) {
pContext->bBoolInUse = true;
memset(pContext->Data, 0, MAX_TOTAL_SIZE_WITH_ALL_HEADERS);
pReturnContext = pContext;
break;
}
}
if ( ii == pDevice->cbTD ) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"No Free Tx Context\n");
}
return (void *) pReturnContext;
}
static void s_vSaveTxPktInfo(struct vnt_private *pDevice, u8 byPktNum,
u8 *pbyDestAddr, u16 wPktLength, u16 wFIFOCtl)
{
PSStatCounter pStatistic = &pDevice->scStatistic;
if (is_broadcast_ether_addr(pbyDestAddr))
pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni = TX_PKT_BROAD;
else if (is_multicast_ether_addr(pbyDestAddr))
pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni = TX_PKT_MULTI;
else
pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni = TX_PKT_UNI;
pStatistic->abyTxPktInfo[byPktNum].wLength = wPktLength;
pStatistic->abyTxPktInfo[byPktNum].wFIFOCtl = wFIFOCtl;
memcpy(pStatistic->abyTxPktInfo[byPktNum].abyDestAddr,
pbyDestAddr,
ETH_ALEN);
}
static void s_vFillTxKey(struct vnt_private *pDevice,
struct vnt_tx_fifo_head *fifo_head, u8 *pbyIVHead,
PSKeyItem pTransmitKey, u8 *pbyHdrBuf, u16 wPayloadLen,
struct vnt_mic_hdr *mic_hdr)
{
u8 *pbyBuf = (u8 *)&fifo_head->adwTxKey[0];
u32 *pdwIV = (u32 *)pbyIVHead;
u32 *pdwExtIV = (u32 *)((u8 *)pbyIVHead + 4);
struct ieee80211_hdr *pMACHeader = (struct ieee80211_hdr *)pbyHdrBuf;
u32 dwRevIVCounter;
if (pTransmitKey == NULL)
return;
dwRevIVCounter = cpu_to_le32(pDevice->dwIVCounter);
*pdwIV = pDevice->dwIVCounter;
pDevice->byKeyIndex = pTransmitKey->dwKeyIndex & 0xf;
switch (pTransmitKey->byCipherSuite) {
case KEY_CTL_WEP:
if (pTransmitKey->uKeyLength == WLAN_WEP232_KEYLEN) {
memcpy(pDevice->abyPRNG, (u8 *)&dwRevIVCounter, 3);
memcpy(pDevice->abyPRNG + 3, pTransmitKey->abyKey,
pTransmitKey->uKeyLength);
} else {
memcpy(pbyBuf, (u8 *)&dwRevIVCounter, 3);
memcpy(pbyBuf + 3, pTransmitKey->abyKey,
pTransmitKey->uKeyLength);
if (pTransmitKey->uKeyLength == WLAN_WEP40_KEYLEN) {
memcpy(pbyBuf+8, (u8 *)&dwRevIVCounter, 3);
memcpy(pbyBuf+11, pTransmitKey->abyKey,
pTransmitKey->uKeyLength);
}
memcpy(pDevice->abyPRNG, pbyBuf, 16);
}
*pdwIV &= WEP_IV_MASK;
*pdwIV |= (u32)pDevice->byKeyIndex << 30;
*pdwIV = cpu_to_le32(*pdwIV);
pDevice->dwIVCounter++;
if (pDevice->dwIVCounter > WEP_IV_MASK)
pDevice->dwIVCounter = 0;
break;
case KEY_CTL_TKIP:
pTransmitKey->wTSC15_0++;
if (pTransmitKey->wTSC15_0 == 0)
pTransmitKey->dwTSC47_16++;
TKIPvMixKey(pTransmitKey->abyKey, pDevice->abyCurrentNetAddr,
pTransmitKey->wTSC15_0, pTransmitKey->dwTSC47_16,
pDevice->abyPRNG);
memcpy(pbyBuf, pDevice->abyPRNG, 16);
memcpy(pdwIV, pDevice->abyPRNG, 3);
*(pbyIVHead+3) = (u8)(((pDevice->byKeyIndex << 6) &
0xc0) | 0x20);
*pdwExtIV = cpu_to_le32(pTransmitKey->dwTSC47_16);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"vFillTxKey()---- pdwExtIV: %x\n", *pdwExtIV);
break;
case KEY_CTL_CCMP:
pTransmitKey->wTSC15_0++;
if (pTransmitKey->wTSC15_0 == 0)
pTransmitKey->dwTSC47_16++;
memcpy(pbyBuf, pTransmitKey->abyKey, 16);
*pdwIV = 0;
*(pbyIVHead+3) = (u8)(((pDevice->byKeyIndex << 6) &
0xc0) | 0x20);
*pdwIV |= cpu_to_le16((u16)(pTransmitKey->wTSC15_0));
*pdwExtIV = cpu_to_le32(pTransmitKey->dwTSC47_16);
if (!mic_hdr)
return;
mic_hdr->id = 0x59;
mic_hdr->payload_len = cpu_to_be16(wPayloadLen);
memcpy(mic_hdr->mic_addr2, pMACHeader->addr2, ETH_ALEN);
mic_hdr->tsc_47_16 = cpu_to_be32(pTransmitKey->dwTSC47_16);
mic_hdr->tsc_15_0 = cpu_to_be16(pTransmitKey->wTSC15_0);
if (pDevice->bLongHeader)
mic_hdr->hlen = cpu_to_be16(28);
else
mic_hdr->hlen = cpu_to_be16(22);
memcpy(mic_hdr->addr1, pMACHeader->addr1, ETH_ALEN);
memcpy(mic_hdr->addr2, pMACHeader->addr2, ETH_ALEN);
memcpy(mic_hdr->addr3, pMACHeader->addr3, ETH_ALEN);
mic_hdr->frame_control = cpu_to_le16(pMACHeader->frame_control
& 0xc78f);
mic_hdr->seq_ctrl = cpu_to_le16(pMACHeader->seq_ctrl & 0xf);
if (pDevice->bLongHeader)
memcpy(mic_hdr->addr4, pMACHeader->addr4, ETH_ALEN);
}
}
static void s_vSWencryption(struct vnt_private *pDevice,
PSKeyItem pTransmitKey, u8 *pbyPayloadHead, u16 wPayloadSize)
{
u32 cbICVlen = 4;
u32 dwICV = 0xffffffff;
u32 *pdwICV;
if (pTransmitKey == NULL)
return;
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
dwICV = CRCdwGetCrc32Ex(pbyPayloadHead, wPayloadSize, dwICV);
pdwICV = (u32 *)(pbyPayloadHead + wPayloadSize);
*pdwICV = cpu_to_le32(~dwICV);
rc4_init(&pDevice->SBox, pDevice->abyPRNG, pTransmitKey->uKeyLength + 3);
rc4_encrypt(&pDevice->SBox, pbyPayloadHead, pbyPayloadHead, wPayloadSize+cbICVlen);
} else if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
dwICV = CRCdwGetCrc32Ex(pbyPayloadHead, wPayloadSize, dwICV);
pdwICV = (u32 *)(pbyPayloadHead + wPayloadSize);
*pdwICV = cpu_to_le32(~dwICV);
rc4_init(&pDevice->SBox, pDevice->abyPRNG, TKIP_KEY_LEN);
rc4_encrypt(&pDevice->SBox, pbyPayloadHead, pbyPayloadHead, wPayloadSize+cbICVlen);
}
}
static u16 vnt_time_stamp_off(struct vnt_private *priv, u16 rate)
{
return cpu_to_le16(wTimeStampOff[priv->byPreambleType % 2]
[rate % MAX_RATE]);
}
static u32 s_uGetTxRsvTime(struct vnt_private *pDevice, u8 byPktType,
u32 cbFrameLength, u16 wRate, int bNeedAck)
{
u32 uDataTime, uAckTime;
uDataTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, cbFrameLength, wRate);
if (byPktType == PK_TYPE_11B) {
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, (u16)pDevice->byTopCCKBasicRate);
} else {
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, (u16)pDevice->byTopOFDMBasicRate);
}
if (bNeedAck) {
return (uDataTime + pDevice->uSIFS + uAckTime);
}
else {
return uDataTime;
}
}
static u16 vnt_rxtx_rsvtime_le16(struct vnt_private *priv, u8 pkt_type,
u32 frame_length, u16 rate, int need_ack)
{
return cpu_to_le16((u16)s_uGetTxRsvTime(priv, pkt_type,
frame_length, rate, need_ack));
}
static u16 s_uGetRTSCTSRsvTime(struct vnt_private *pDevice,
u8 byRTSRsvType, u8 byPktType, u32 cbFrameLength, u16 wCurrentRate)
{
u32 uRrvTime, uRTSTime, uCTSTime, uAckTime, uDataTime;
uRrvTime = uRTSTime = uCTSTime = uAckTime = uDataTime = 0;
uDataTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, cbFrameLength, wCurrentRate);
if (byRTSRsvType == 0) {
uRTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 20, pDevice->byTopCCKBasicRate);
uCTSTime = uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
}
else if (byRTSRsvType == 1){
uRTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 20, pDevice->byTopCCKBasicRate);
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
}
else if (byRTSRsvType == 2) {
uRTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 20, pDevice->byTopOFDMBasicRate);
uCTSTime = uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
}
else if (byRTSRsvType == 3) {
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
uRrvTime = uCTSTime + uAckTime + uDataTime + 2*pDevice->uSIFS;
return uRrvTime;
}
uRrvTime = uRTSTime + uCTSTime + uAckTime + uDataTime + 3*pDevice->uSIFS;
return cpu_to_le16((u16)uRrvTime);
}
static u16 s_uGetDataDuration(struct vnt_private *pDevice,
u8 byPktType, int bNeedAck)
{
u32 uAckTime = 0;
if (bNeedAck) {
if (byPktType == PK_TYPE_11B)
uAckTime = BBuGetFrameTime(pDevice->byPreambleType,
byPktType, 14, pDevice->byTopCCKBasicRate);
else
uAckTime = BBuGetFrameTime(pDevice->byPreambleType,
byPktType, 14, pDevice->byTopOFDMBasicRate);
return cpu_to_le16((u16)(pDevice->uSIFS + uAckTime));
}
return 0;
}
static u16 s_uGetRTSCTSDuration(struct vnt_private *pDevice, u8 byDurType,
u32 cbFrameLength, u8 byPktType, u16 wRate, int bNeedAck,
u8 byFBOption)
{
u32 uCTSTime = 0, uDurTime = 0;
switch (byDurType) {
case RTSDUR_BB:
case RTSDUR_BA:
case RTSDUR_BA_F0:
case RTSDUR_BA_F1:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType,
14, pDevice->byTopCCKBasicRate);
uDurTime = uCTSTime + 2 * pDevice->uSIFS +
s_uGetTxRsvTime(pDevice, byPktType,
cbFrameLength, wRate, bNeedAck);
break;
case RTSDUR_AA:
case RTSDUR_AA_F0:
case RTSDUR_AA_F1:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType,
14, pDevice->byTopOFDMBasicRate);
uDurTime = uCTSTime + 2 * pDevice->uSIFS +
s_uGetTxRsvTime(pDevice, byPktType,
cbFrameLength, wRate, bNeedAck);
break;
case CTSDUR_BA:
case CTSDUR_BA_F0:
case CTSDUR_BA_F1:
uDurTime = pDevice->uSIFS + s_uGetTxRsvTime(pDevice,
byPktType, cbFrameLength, wRate, bNeedAck);
break;
default:
break;
}
return cpu_to_le16((u16)uDurTime);
}
static u16 vnt_rxtx_datahead_g(struct vnt_private *priv, u8 pkt_type, u16 rate,
struct vnt_tx_datahead_g *buf, u32 frame_len, int need_ack)
{
BBvCalculateParameter(priv, frame_len, rate, pkt_type, &buf->a);
BBvCalculateParameter(priv, frame_len, priv->byTopCCKBasicRate,
PK_TYPE_11B, &buf->b);
buf->wDuration_a = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wDuration_b = s_uGetDataDuration(priv, PK_TYPE_11B, need_ack);
buf->wTimeStampOff_a = vnt_time_stamp_off(priv, rate);
buf->wTimeStampOff_b = vnt_time_stamp_off(priv,
priv->byTopCCKBasicRate);
return buf->wDuration_a;
}
static u16 vnt_rxtx_datahead_g_fb(struct vnt_private *priv, u8 pkt_type,
u16 rate, struct vnt_tx_datahead_g_fb *buf,
u32 frame_len, int need_ack)
{
BBvCalculateParameter(priv, frame_len, rate, pkt_type, &buf->a);
BBvCalculateParameter(priv, frame_len, priv->byTopCCKBasicRate,
PK_TYPE_11B, &buf->b);
buf->wDuration_a = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wDuration_b = s_uGetDataDuration(priv, PK_TYPE_11B, need_ack);
buf->wDuration_a_f0 = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wDuration_a_f1 = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wTimeStampOff_a = vnt_time_stamp_off(priv, rate);
buf->wTimeStampOff_b = vnt_time_stamp_off(priv,
priv->byTopCCKBasicRate);
return buf->wDuration_a;
}
static u16 vnt_rxtx_datahead_a_fb(struct vnt_private *priv, u8 pkt_type,
u16 rate, struct vnt_tx_datahead_a_fb *buf,
u32 frame_len, int need_ack)
{
BBvCalculateParameter(priv, frame_len, rate, pkt_type, &buf->a);
buf->wDuration = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wDuration_f0 = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wDuration_f1 = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wTimeStampOff = vnt_time_stamp_off(priv, rate);
return buf->wDuration;
}
static u16 vnt_rxtx_datahead_ab(struct vnt_private *priv, u8 pkt_type,
u16 rate, struct vnt_tx_datahead_ab *buf,
u32 frame_len, int need_ack)
{
BBvCalculateParameter(priv, frame_len, rate, pkt_type, &buf->ab);
buf->wDuration = s_uGetDataDuration(priv, pkt_type, need_ack);
buf->wTimeStampOff = vnt_time_stamp_off(priv, rate);
return buf->wDuration;
}
static int vnt_fill_ieee80211_rts(struct vnt_private *priv,
struct ieee80211_rts *rts, struct ethhdr *eth_hdr,
u16 duration)
{
rts->duration = duration;
rts->frame_control = TYPE_CTL_RTS;
if (priv->eOPMode == OP_MODE_ADHOC || priv->eOPMode == OP_MODE_AP)
memcpy(rts->ra, eth_hdr->h_dest, ETH_ALEN);
else
memcpy(rts->ra, priv->abyBSSID, ETH_ALEN);
if (priv->eOPMode == OP_MODE_AP)
memcpy(rts->ta, priv->abyBSSID, ETH_ALEN);
else
memcpy(rts->ta, eth_hdr->h_source, ETH_ALEN);
return 0;
}
static u16 vnt_rxtx_rts_g_head(struct vnt_private *priv,
struct vnt_rts_g *buf, struct ethhdr *eth_hdr,
u8 pkt_type, u32 frame_len, int need_ack,
u16 current_rate, u8 fb_option)
{
u16 rts_frame_len = 20;
BBvCalculateParameter(priv, rts_frame_len, priv->byTopCCKBasicRate,
PK_TYPE_11B, &buf->b);
BBvCalculateParameter(priv, rts_frame_len,
priv->byTopOFDMBasicRate, pkt_type, &buf->a);
buf->wDuration_bb = s_uGetRTSCTSDuration(priv, RTSDUR_BB, frame_len,
PK_TYPE_11B, priv->byTopCCKBasicRate, need_ack, fb_option);
buf->wDuration_aa = s_uGetRTSCTSDuration(priv, RTSDUR_AA, frame_len,
pkt_type, current_rate, need_ack, fb_option);
buf->wDuration_ba = s_uGetRTSCTSDuration(priv, RTSDUR_BA, frame_len,
pkt_type, current_rate, need_ack, fb_option);
vnt_fill_ieee80211_rts(priv, &buf->data, eth_hdr, buf->wDuration_aa);
return vnt_rxtx_datahead_g(priv, pkt_type, current_rate,
&buf->data_head, frame_len, need_ack);
}
static u16 vnt_rxtx_rts_g_fb_head(struct vnt_private *priv,
struct vnt_rts_g_fb *buf, struct ethhdr *eth_hdr,
u8 pkt_type, u32 frame_len, int need_ack,
u16 current_rate, u8 fb_option)
{
u16 rts_frame_len = 20;
BBvCalculateParameter(priv, rts_frame_len, priv->byTopCCKBasicRate,
PK_TYPE_11B, &buf->b);
BBvCalculateParameter(priv, rts_frame_len,
priv->byTopOFDMBasicRate, pkt_type, &buf->a);
buf->wDuration_bb = s_uGetRTSCTSDuration(priv, RTSDUR_BB, frame_len,
PK_TYPE_11B, priv->byTopCCKBasicRate, need_ack, fb_option);
buf->wDuration_aa = s_uGetRTSCTSDuration(priv, RTSDUR_AA, frame_len,
pkt_type, current_rate, need_ack, fb_option);
buf->wDuration_ba = s_uGetRTSCTSDuration(priv, RTSDUR_BA, frame_len,
pkt_type, current_rate, need_ack, fb_option);
buf->wRTSDuration_ba_f0 = s_uGetRTSCTSDuration(priv, RTSDUR_BA_F0,
frame_len, pkt_type, priv->tx_rate_fb0, need_ack, fb_option);
buf->wRTSDuration_aa_f0 = s_uGetRTSCTSDuration(priv, RTSDUR_AA_F0,
frame_len, pkt_type, priv->tx_rate_fb0, need_ack, fb_option);
buf->wRTSDuration_ba_f1 = s_uGetRTSCTSDuration(priv, RTSDUR_BA_F1,
frame_len, pkt_type, priv->tx_rate_fb1, need_ack, fb_option);
buf->wRTSDuration_aa_f1 = s_uGetRTSCTSDuration(priv, RTSDUR_AA_F1,
frame_len, pkt_type, priv->tx_rate_fb1, need_ack, fb_option);
vnt_fill_ieee80211_rts(priv, &buf->data, eth_hdr, buf->wDuration_aa);
return vnt_rxtx_datahead_g_fb(priv, pkt_type, current_rate,
&buf->data_head, frame_len, need_ack);
}
static u16 vnt_rxtx_rts_ab_head(struct vnt_private *priv,
struct vnt_rts_ab *buf, struct ethhdr *eth_hdr,
u8 pkt_type, u32 frame_len, int need_ack,
u16 current_rate, u8 fb_option)
{
u16 rts_frame_len = 20;
BBvCalculateParameter(priv, rts_frame_len,
priv->byTopOFDMBasicRate, pkt_type, &buf->ab);
buf->wDuration = s_uGetRTSCTSDuration(priv, RTSDUR_AA, frame_len,
pkt_type, current_rate, need_ack, fb_option);
vnt_fill_ieee80211_rts(priv, &buf->data, eth_hdr, buf->wDuration);
return vnt_rxtx_datahead_ab(priv, pkt_type, current_rate,
&buf->data_head, frame_len, need_ack);
}
static u16 vnt_rxtx_rts_a_fb_head(struct vnt_private *priv,
struct vnt_rts_a_fb *buf, struct ethhdr *eth_hdr,
u8 pkt_type, u32 frame_len, int need_ack,
u16 current_rate, u8 fb_option)
{
u16 rts_frame_len = 20;
BBvCalculateParameter(priv, rts_frame_len,
priv->byTopOFDMBasicRate, pkt_type, &buf->a);
buf->wDuration = s_uGetRTSCTSDuration(priv, RTSDUR_AA, frame_len,
pkt_type, current_rate, need_ack, fb_option);
buf->wRTSDuration_f0 = s_uGetRTSCTSDuration(priv, RTSDUR_AA_F0,
frame_len, pkt_type, priv->tx_rate_fb0, need_ack, fb_option);
buf->wRTSDuration_f1 = s_uGetRTSCTSDuration(priv, RTSDUR_AA_F1,
frame_len, pkt_type, priv->tx_rate_fb1, need_ack, fb_option);
vnt_fill_ieee80211_rts(priv, &buf->data, eth_hdr, buf->wDuration);
return vnt_rxtx_datahead_a_fb(priv, pkt_type, current_rate,
&buf->data_head, frame_len, need_ack);
}
static u16 s_vFillRTSHead(struct vnt_private *pDevice, u8 byPktType,
union vnt_tx_data_head *head, u32 cbFrameLength, int bNeedAck,
struct ethhdr *psEthHeader, u16 wCurrentRate, u8 byFBOption)
{
if (!head)
return 0;
switch (byPktType) {
case PK_TYPE_11GB:
case PK_TYPE_11GA:
if (byFBOption == AUTO_FB_NONE)
return vnt_rxtx_rts_g_head(pDevice, &head->rts_g,
psEthHeader, byPktType, cbFrameLength,
bNeedAck, wCurrentRate, byFBOption);
else
return vnt_rxtx_rts_g_fb_head(pDevice, &head->rts_g_fb,
psEthHeader, byPktType, cbFrameLength,
bNeedAck, wCurrentRate, byFBOption);
break;
case PK_TYPE_11A:
if (byFBOption) {
return vnt_rxtx_rts_a_fb_head(pDevice, &head->rts_a_fb,
psEthHeader, byPktType, cbFrameLength,
bNeedAck, wCurrentRate, byFBOption);
break;
}
case PK_TYPE_11B:
return vnt_rxtx_rts_ab_head(pDevice, &head->rts_ab,
psEthHeader, byPktType, cbFrameLength,
bNeedAck, wCurrentRate, byFBOption);
}
return 0;
}
static u16 s_vFillCTSHead(struct vnt_private *pDevice, u32 uDMAIdx,
u8 byPktType, union vnt_tx_data_head *head, u32 cbFrameLength,
int bNeedAck, u16 wCurrentRate, u8 byFBOption)
{
u32 uCTSFrameLen = 14;
if (!head)
return 0;
if (byFBOption != AUTO_FB_NONE) {
struct vnt_cts_fb *pBuf = &head->cts_g_fb;
BBvCalculateParameter(pDevice, uCTSFrameLen,
pDevice->byTopCCKBasicRate, PK_TYPE_11B, &pBuf->b);
pBuf->wDuration_ba = s_uGetRTSCTSDuration(pDevice, CTSDUR_BA,
cbFrameLength, byPktType,
wCurrentRate, bNeedAck, byFBOption);
pBuf->wCTSDuration_ba_f0 = s_uGetRTSCTSDuration(pDevice,
CTSDUR_BA_F0, cbFrameLength, byPktType,
pDevice->tx_rate_fb0, bNeedAck, byFBOption);
pBuf->wCTSDuration_ba_f1 = s_uGetRTSCTSDuration(pDevice,
CTSDUR_BA_F1, cbFrameLength, byPktType,
pDevice->tx_rate_fb1, bNeedAck, byFBOption);
pBuf->data.duration = pBuf->wDuration_ba;
pBuf->data.frame_control = TYPE_CTL_CTS;
memcpy(pBuf->data.ra, pDevice->abyCurrentNetAddr, ETH_ALEN);
return vnt_rxtx_datahead_g_fb(pDevice, byPktType, wCurrentRate,
&pBuf->data_head, cbFrameLength, bNeedAck);
} else {
struct vnt_cts *pBuf = &head->cts_g;
BBvCalculateParameter(pDevice, uCTSFrameLen,
pDevice->byTopCCKBasicRate, PK_TYPE_11B, &pBuf->b);
pBuf->wDuration_ba = s_uGetRTSCTSDuration(pDevice,
CTSDUR_BA, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, byFBOption);
pBuf->data.duration = pBuf->wDuration_ba;
pBuf->data.frame_control = TYPE_CTL_CTS;
memcpy(pBuf->data.ra, pDevice->abyCurrentNetAddr, ETH_ALEN);
return vnt_rxtx_datahead_g(pDevice, byPktType, wCurrentRate,
&pBuf->data_head, cbFrameLength, bNeedAck);
}
return 0;
}
static u16 s_vGenerateTxParameter(struct vnt_private *pDevice,
u8 byPktType, u16 wCurrentRate, struct vnt_tx_buffer *tx_buffer,
struct vnt_mic_hdr **mic_hdr, u32 need_mic, u32 cbFrameSize,
int bNeedACK, u32 uDMAIdx, struct ethhdr *psEthHeader, bool need_rts)
{
struct vnt_tx_fifo_head *pFifoHead = &tx_buffer->fifo_head;
union vnt_tx_data_head *head = NULL;
u32 cbMACHdLen = WLAN_HDR_ADDR3_LEN;
u16 wFifoCtl;
u8 byFBOption = AUTO_FB_NONE;
pFifoHead->wReserved = wCurrentRate;
wFifoCtl = pFifoHead->wFIFOCtl;
if (wFifoCtl & FIFOCTL_AUTO_FB_0)
byFBOption = AUTO_FB_0;
else if (wFifoCtl & FIFOCTL_AUTO_FB_1)
byFBOption = AUTO_FB_1;
if (!pFifoHead)
return 0;
if (pDevice->bLongHeader)
cbMACHdLen = WLAN_HDR_ADDR3_LEN + 6;
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if (need_rts) {
struct vnt_rrv_time_rts *pBuf =
&tx_buffer->tx_head.tx_rts.rts;
pBuf->wRTSTxRrvTime_aa = s_uGetRTSCTSRsvTime(pDevice, 2,
byPktType, cbFrameSize, wCurrentRate);
pBuf->wRTSTxRrvTime_ba = s_uGetRTSCTSRsvTime(pDevice, 1,
byPktType, cbFrameSize, wCurrentRate);
pBuf->wRTSTxRrvTime_bb = s_uGetRTSCTSRsvTime(pDevice, 0,
byPktType, cbFrameSize, wCurrentRate);
pBuf->wTxRrvTime_a = vnt_rxtx_rsvtime_le16(pDevice,
byPktType, cbFrameSize, wCurrentRate, bNeedACK);
pBuf->wTxRrvTime_b = vnt_rxtx_rsvtime_le16(pDevice,
PK_TYPE_11B, cbFrameSize,
pDevice->byTopCCKBasicRate, bNeedACK);
if (need_mic) {
*mic_hdr = &tx_buffer->
tx_head.tx_rts.tx.mic.hdr;
head = &tx_buffer->tx_head.tx_rts.tx.mic.head;
} else {
head = &tx_buffer->tx_head.tx_rts.tx.head;
}
return s_vFillRTSHead(pDevice, byPktType, head,
cbFrameSize, bNeedACK, psEthHeader,
wCurrentRate, byFBOption);
} else {
struct vnt_rrv_time_cts *pBuf = &tx_buffer->
tx_head.tx_cts.cts;
pBuf->wTxRrvTime_a = vnt_rxtx_rsvtime_le16(pDevice,
byPktType, cbFrameSize, wCurrentRate, bNeedACK);
pBuf->wTxRrvTime_b = vnt_rxtx_rsvtime_le16(pDevice,
PK_TYPE_11B, cbFrameSize,
pDevice->byTopCCKBasicRate, bNeedACK);
pBuf->wCTSTxRrvTime_ba = s_uGetRTSCTSRsvTime(pDevice, 3,
byPktType, cbFrameSize, wCurrentRate);
if (need_mic) {
*mic_hdr = &tx_buffer->
tx_head.tx_cts.tx.mic.hdr;
head = &tx_buffer->tx_head.tx_cts.tx.mic.head;
} else {
head = &tx_buffer->tx_head.tx_cts.tx.head;
}
return s_vFillCTSHead(pDevice, uDMAIdx, byPktType,
head, cbFrameSize, bNeedACK, wCurrentRate,
byFBOption);
}
} else if (byPktType == PK_TYPE_11A) {
if (need_mic) {
*mic_hdr = &tx_buffer->tx_head.tx_ab.tx.mic.hdr;
head = &tx_buffer->tx_head.tx_ab.tx.mic.head;
} else {
head = &tx_buffer->tx_head.tx_ab.tx.head;
}
if (need_rts) {
struct vnt_rrv_time_ab *pBuf = &tx_buffer->
tx_head.tx_ab.ab;
pBuf->wRTSTxRrvTime = s_uGetRTSCTSRsvTime(pDevice, 2,
byPktType, cbFrameSize, wCurrentRate);
pBuf->wTxRrvTime = vnt_rxtx_rsvtime_le16(pDevice,
byPktType, cbFrameSize, wCurrentRate, bNeedACK);
return s_vFillRTSHead(pDevice, byPktType, head,
cbFrameSize, bNeedACK, psEthHeader,
wCurrentRate, byFBOption);
} else {
struct vnt_rrv_time_ab *pBuf = &tx_buffer->
tx_head.tx_ab.ab;
pBuf->wTxRrvTime = vnt_rxtx_rsvtime_le16(pDevice,
PK_TYPE_11A, cbFrameSize,
wCurrentRate, bNeedACK);
return vnt_rxtx_datahead_a_fb(pDevice, byPktType,
wCurrentRate, &head->data_head_a_fb,
cbFrameSize, bNeedACK);
}
} else if (byPktType == PK_TYPE_11B) {
if (need_mic) {
*mic_hdr = &tx_buffer->tx_head.tx_ab.tx.mic.hdr;
head = &tx_buffer->tx_head.tx_ab.tx.mic.head;
} else {
head = &tx_buffer->tx_head.tx_ab.tx.head;
}
if (need_rts) {
struct vnt_rrv_time_ab *pBuf = &tx_buffer->
tx_head.tx_ab.ab;
pBuf->wRTSTxRrvTime = s_uGetRTSCTSRsvTime(pDevice, 0,
byPktType, cbFrameSize, wCurrentRate);
pBuf->wTxRrvTime = vnt_rxtx_rsvtime_le16(pDevice,
PK_TYPE_11B, cbFrameSize, wCurrentRate,
bNeedACK);
return s_vFillRTSHead(pDevice, byPktType, head,
cbFrameSize,
bNeedACK, psEthHeader, wCurrentRate, byFBOption);
} else {
struct vnt_rrv_time_ab *pBuf = &tx_buffer->
tx_head.tx_ab.ab;
pBuf->wTxRrvTime = vnt_rxtx_rsvtime_le16(pDevice,
PK_TYPE_11B, cbFrameSize,
wCurrentRate, bNeedACK);
return vnt_rxtx_datahead_ab(pDevice, byPktType,
wCurrentRate, &head->data_head_ab,
cbFrameSize, bNeedACK);
}
}
return 0;
}
static int s_bPacketToWirelessUsb(struct vnt_private *pDevice, u8 byPktType,
struct vnt_tx_buffer *tx_buffer, int bNeedEncryption,
u32 uSkbPacketLen, u32 uDMAIdx, struct ethhdr *psEthHeader,
u8 *pPacket, PSKeyItem pTransmitKey, u32 uNodeIndex, u16 wCurrentRate,
u32 *pcbHeaderLen, u32 *pcbTotalLen)
{
struct vnt_tx_fifo_head *pTxBufHead = &tx_buffer->fifo_head;
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u32 cbFrameSize, cbFrameBodySize;
u32 cb802_1_H_len;
u32 cbIVlen = 0, cbICVlen = 0, cbMIClen = 0, cbMACHdLen = 0;
u32 cbFCSlen = 4, cbMICHDR = 0;
int bNeedACK;
bool bRTS = false;
u8 *pbyType, *pbyMacHdr, *pbyIVHead, *pbyPayloadHead, *pbyTxBufferAddr;
u8 abySNAP_RFC1042[ETH_ALEN] = {0xAA, 0xAA, 0x03, 0x00, 0x00, 0x00};
u8 abySNAP_Bridgetunnel[ETH_ALEN]
= {0xAA, 0xAA, 0x03, 0x00, 0x00, 0xF8};
u32 uDuration;
u32 cbHeaderLength = 0, uPadding = 0;
struct vnt_mic_hdr *pMICHDR;
u8 byFBOption = AUTO_FB_NONE, byFragType;
u16 wTxBufSize;
u32 dwMICKey0, dwMICKey1, dwMIC_Priority;
u32 *pdwMIC_L, *pdwMIC_R;
int bSoftWEP = false;
pMICHDR = NULL;
if (bNeedEncryption && pTransmitKey->pvKeyTable) {
if (((PSKeyTable)pTransmitKey->pvKeyTable)->bSoftWEP == true)
bSoftWEP = true;
}
if (ntohs(psEthHeader->h_proto) > ETH_DATA_LEN) {
if (pDevice->dwDiagRefCount == 0) {
cb802_1_H_len = 8;
} else {
cb802_1_H_len = 2;
}
} else {
cb802_1_H_len = 0;
}
cbFrameBodySize = uSkbPacketLen - ETH_HLEN + cb802_1_H_len;
pTxBufHead->wFIFOCtl |= (u16)(byPktType<<8);
if (pDevice->dwDiagRefCount != 0) {
bNeedACK = false;
pTxBufHead->wFIFOCtl = pTxBufHead->wFIFOCtl & (~FIFOCTL_NEEDACK);
} else {
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
if (is_multicast_ether_addr(psEthHeader->h_dest)) {
bNeedACK = false;
pTxBufHead->wFIFOCtl =
pTxBufHead->wFIFOCtl & (~FIFOCTL_NEEDACK);
} else {
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
}
}
else {
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
}
}
pTxBufHead->wTimeStamp = DEFAULT_MSDU_LIFETIME_RES_64us;
if (pDevice->bLongHeader)
pTxBufHead->wFIFOCtl |= FIFOCTL_LHEAD;
if (pDevice->bLongHeader) {
cbMACHdLen = WLAN_HDR_ADDR3_LEN + 6;
} else {
cbMACHdLen = WLAN_HDR_ADDR3_LEN;
}
pTxBufHead->wFragCtl |= (u16)(cbMACHdLen << 10);
if (pDevice->bGrpAckPolicy == true) {
pTxBufHead->wFIFOCtl |= FIFOCTL_GRPACK;
}
if (wCurrentRate >= RATE_18M) {
if (pDevice->byAutoFBCtrl == AUTO_FB_0) {
pTxBufHead->wFIFOCtl |= FIFOCTL_AUTO_FB_0;
pDevice->tx_rate_fb0 =
wFB_Opt0[FB_RATE0][wCurrentRate - RATE_18M];
pDevice->tx_rate_fb1 =
wFB_Opt0[FB_RATE1][wCurrentRate - RATE_18M];
byFBOption = AUTO_FB_0;
} else if (pDevice->byAutoFBCtrl == AUTO_FB_1) {
pTxBufHead->wFIFOCtl |= FIFOCTL_AUTO_FB_1;
pDevice->tx_rate_fb0 =
wFB_Opt1[FB_RATE0][wCurrentRate - RATE_18M];
pDevice->tx_rate_fb1 =
wFB_Opt1[FB_RATE1][wCurrentRate - RATE_18M];
byFBOption = AUTO_FB_1;
}
}
if (bSoftWEP != true) {
if ((bNeedEncryption) && (pTransmitKey != NULL)) {
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
pTxBufHead->wFragCtl |= FRAGCTL_LEGACY;
}
if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Tx Set wFragCtl == FRAGCTL_TKIP\n");
pTxBufHead->wFragCtl |= FRAGCTL_TKIP;
}
else if (pTransmitKey->byCipherSuite == KEY_CTL_CCMP) {
pTxBufHead->wFragCtl |= FRAGCTL_AES;
}
}
}
if ((bNeedEncryption) && (pTransmitKey != NULL)) {
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
cbIVlen = 4;
cbICVlen = 4;
}
else if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
cbIVlen = 8;
cbMIClen = 8;
cbICVlen = 4;
}
if (pTransmitKey->byCipherSuite == KEY_CTL_CCMP) {
cbIVlen = 8;
cbICVlen = 8;
cbMICHDR = sizeof(struct vnt_mic_hdr);
}
if (bSoftWEP == false) {
uPadding = 4 - (cbMACHdLen%4);
uPadding %= 4;
}
}
cbFrameSize = cbMACHdLen + cbIVlen + (cbFrameBodySize + cbMIClen) + cbICVlen + cbFCSlen;
if ( (bNeedACK == false) ||(cbFrameSize < pDevice->wRTSThreshold) ) {
bRTS = false;
} else {
bRTS = true;
pTxBufHead->wFIFOCtl |= (FIFOCTL_RTS | FIFOCTL_LRETRY);
}
pbyTxBufferAddr = (u8 *) &(pTxBufHead->adwTxKey[0]);
wTxBufSize = sizeof(struct vnt_tx_fifo_head);
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if (byFBOption == AUTO_FB_NONE) {
if (bRTS == true) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_rts) +
cbMICHDR + sizeof(struct vnt_rts_g);
}
else {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_cts) +
cbMICHDR + sizeof(struct vnt_cts);
}
} else {
if (bRTS == true) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_rts) +
cbMICHDR + sizeof(struct vnt_rts_g_fb);
}
else if (bRTS == false) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_cts) +
cbMICHDR + sizeof(struct vnt_cts_fb);
}
}
}
else {
if (byFBOption == AUTO_FB_NONE) {
if (bRTS == true) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_ab) +
cbMICHDR + sizeof(struct vnt_rts_ab);
}
else if (bRTS == false) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_ab) +
cbMICHDR + sizeof(struct vnt_tx_datahead_ab);
}
} else {
if (bRTS == true) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_ab) +
cbMICHDR + sizeof(struct vnt_rts_a_fb);
}
else if (bRTS == false) {
cbHeaderLength = wTxBufSize + sizeof(struct vnt_rrv_time_ab) +
cbMICHDR + sizeof(struct vnt_tx_datahead_a_fb);
}
}
}
pbyMacHdr = (u8 *)(pbyTxBufferAddr + cbHeaderLength);
pbyIVHead = (u8 *)(pbyMacHdr + cbMACHdLen + uPadding);
pbyPayloadHead = (u8 *)(pbyMacHdr + cbMACHdLen + uPadding + cbIVlen);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"No Fragmentation...\n");
byFragType = FRAGCTL_NONFRAG;
uDuration = s_vGenerateTxParameter(pDevice, byPktType, wCurrentRate,
tx_buffer, &pMICHDR, cbMICHDR,
cbFrameSize, bNeedACK, uDMAIdx, psEthHeader, bRTS);
s_vGenerateMACHeader(pDevice, pbyMacHdr, (u16)uDuration, psEthHeader, bNeedEncryption,
byFragType, uDMAIdx, 0);
if (bNeedEncryption == true) {
s_vFillTxKey(pDevice, pTxBufHead, pbyIVHead, pTransmitKey,
pbyMacHdr, (u16)cbFrameBodySize, pMICHDR);
if (pDevice->bEnableHostWEP) {
pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16 = pTransmitKey->dwTSC47_16;
pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0 = pTransmitKey->wTSC15_0;
}
}
if (ntohs(psEthHeader->h_proto) > ETH_DATA_LEN) {
if (pDevice->dwDiagRefCount == 0) {
if ((psEthHeader->h_proto == cpu_to_be16(ETH_P_IPX)) ||
(psEthHeader->h_proto == cpu_to_le16(0xF380))) {
memcpy((u8 *) (pbyPayloadHead),
abySNAP_Bridgetunnel, 6);
} else {
memcpy((u8 *) (pbyPayloadHead), &abySNAP_RFC1042[0], 6);
}
pbyType = (u8 *) (pbyPayloadHead + 6);
memcpy(pbyType, &(psEthHeader->h_proto), sizeof(u16));
} else {
memcpy((u8 *) (pbyPayloadHead), &(psEthHeader->h_proto), sizeof(u16));
}
}
if (pPacket != NULL) {
memcpy((pbyPayloadHead + cb802_1_H_len),
(pPacket + ETH_HLEN),
uSkbPacketLen - ETH_HLEN
);
} else {
memcpy((pbyPayloadHead + cb802_1_H_len), ((u8 *)psEthHeader) + ETH_HLEN, uSkbPacketLen - ETH_HLEN);
}
if ((bNeedEncryption == true) && (pTransmitKey != NULL) && (pTransmitKey->byCipherSuite == KEY_CTL_TKIP)) {
if (pDevice->vnt_mgmt.eAuthenMode == WMAC_AUTH_WPANONE) {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[16]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[20]);
}
else if ((pTransmitKey->dwKeyIndex & AUTHENTICATOR_KEY) != 0) {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[16]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[20]);
}
else {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[24]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[28]);
}
MIC_vInit(dwMICKey0, dwMICKey1);
MIC_vAppend((u8 *)&(psEthHeader->h_dest[0]), 12);
dwMIC_Priority = 0;
MIC_vAppend((u8 *)&dwMIC_Priority, 4);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"MIC KEY: %X, %X\n",
dwMICKey0, dwMICKey1);
MIC_vAppend(pbyPayloadHead, cbFrameBodySize);
pdwMIC_L = (u32 *)(pbyPayloadHead + cbFrameBodySize);
pdwMIC_R = (u32 *)(pbyPayloadHead + cbFrameBodySize + 4);
MIC_vGetMIC(pdwMIC_L, pdwMIC_R);
MIC_vUnInit();
if (pDevice->bTxMICFail == true) {
*pdwMIC_L = 0;
*pdwMIC_R = 0;
pDevice->bTxMICFail = false;
}
}
if (bSoftWEP == true) {
s_vSWencryption(pDevice, pTransmitKey, (pbyPayloadHead), (u16)(cbFrameBodySize + cbMIClen));
} else if ( ((pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled) && (bNeedEncryption == true)) ||
((pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) && (bNeedEncryption == true)) ||
((pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) && (bNeedEncryption == true)) ) {
cbFrameSize -= cbICVlen;
}
cbFrameSize -= cbFCSlen;
*pcbHeaderLen = cbHeaderLength;
*pcbTotalLen = cbHeaderLength + cbFrameSize ;
pTxBufHead->wFragCtl |= (u16)byFragType;
return true;
}
static void s_vGenerateMACHeader(struct vnt_private *pDevice,
u8 *pbyBufferAddr, u16 wDuration, struct ethhdr *psEthHeader,
int bNeedEncrypt, u16 wFragType, u32 uDMAIdx, u32 uFragIdx)
{
struct ieee80211_hdr *pMACHeader = (struct ieee80211_hdr *)pbyBufferAddr;
pMACHeader->frame_control = TYPE_802_11_DATA;
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pMACHeader->addr1[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr2[0]), &(pDevice->abyBSSID[0]), ETH_ALEN);
memcpy(&(pMACHeader->addr3[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
pMACHeader->frame_control |= FC_FROMDS;
} else {
if (pDevice->eOPMode == OP_MODE_ADHOC) {
memcpy(&(pMACHeader->addr1[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr2[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr3[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
} else {
memcpy(&(pMACHeader->addr3[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr2[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr1[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
pMACHeader->frame_control |= FC_TODS;
}
}
if (bNeedEncrypt)
pMACHeader->frame_control |= cpu_to_le16((u16)WLAN_SET_FC_ISWEP(1));
pMACHeader->duration_id = cpu_to_le16(wDuration);
if (pDevice->bLongHeader) {
PWLAN_80211HDR_A4 pMACA4Header = (PWLAN_80211HDR_A4) pbyBufferAddr;
pMACHeader->frame_control |= (FC_TODS | FC_FROMDS);
memcpy(pMACA4Header->abyAddr4, pDevice->abyBSSID, WLAN_ADDR_LEN);
}
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pMACHeader->seq_ctrl |= cpu_to_le16((u16)uFragIdx);
if ((wFragType == FRAGCTL_ENDFRAG) || (wFragType == FRAGCTL_NONFRAG)) {
pDevice->wSeqCounter++;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
}
if ((wFragType == FRAGCTL_STAFRAG) || (wFragType == FRAGCTL_MIDFRAG)) {
pMACHeader->frame_control |= FC_MOREFRAG;
}
}
CMD_STATUS csMgmt_xmit(struct vnt_private *pDevice,
struct vnt_tx_mgmt *pPacket)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
struct vnt_tx_buffer *pTX_Buffer;
struct vnt_usb_send_context *pContext;
struct vnt_tx_fifo_head *pTxBufHead;
struct ieee80211_hdr *pMACHeader;
struct ethhdr sEthHeader;
u8 byPktType, *pbyTxBufferAddr;
struct vnt_mic_hdr *pMICHDR = NULL;
u32 uDuration, cbReqCount, cbHeaderSize, cbFrameBodySize, cbFrameSize;
int bNeedACK, bIsPSPOLL = false;
u32 cbIVlen = 0, cbICVlen = 0, cbMIClen = 0, cbFCSlen = 4;
u32 uPadding = 0;
u16 wTxBufSize;
u32 cbMacHdLen;
u16 wCurrentRate = RATE_1M;
pContext = (struct vnt_usb_send_context *)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ManagementSend TX...NO CONTEXT!\n");
return CMD_STATUS_RESOURCES;
}
pTX_Buffer = (struct vnt_tx_buffer *)&pContext->Data[0];
cbFrameBodySize = pPacket->cbPayloadLen;
pTxBufHead = &pTX_Buffer->fifo_head;
pbyTxBufferAddr = (u8 *)&pTxBufHead->adwTxKey[0];
wTxBufSize = sizeof(struct vnt_tx_fifo_head);
if (pDevice->byBBType == BB_TYPE_11A) {
wCurrentRate = RATE_6M;
byPktType = PK_TYPE_11A;
} else {
wCurrentRate = RATE_1M;
byPktType = PK_TYPE_11B;
}
if (pMgmt->eScanState != WMAC_NO_SCANNING) {
RFbSetPower(pDevice, wCurrentRate, pDevice->byCurrentCh);
} else {
RFbSetPower(pDevice, wCurrentRate, pMgmt->uCurrChannel);
}
pDevice->wCurrentRate = wCurrentRate;
if (byPktType == PK_TYPE_11A) {
pTxBufHead->wFIFOCtl = 0;
}
else if (byPktType == PK_TYPE_11B) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11B;
}
else if (byPktType == PK_TYPE_11GB) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GB;
}
else if (byPktType == PK_TYPE_11GA) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GA;
}
pTxBufHead->wFIFOCtl |= FIFOCTL_TMOEN;
pTxBufHead->wTimeStamp = cpu_to_le16(DEFAULT_MGN_LIFETIME_RES_64us);
if (is_multicast_ether_addr(pPacket->p80211Header->sA3.abyAddr1)) {
bNeedACK = false;
}
else {
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
};
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) ||
(pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) ) {
pTxBufHead->wFIFOCtl |= FIFOCTL_LRETRY;
}
pTxBufHead->wFIFOCtl |= (FIFOCTL_GENINT | FIFOCTL_ISDMA0);
if ((pPacket->p80211Header->sA4.wFrameCtl & TYPE_SUBTYPE_MASK) == TYPE_CTL_PSPOLL) {
bIsPSPOLL = true;
cbMacHdLen = WLAN_HDR_ADDR2_LEN;
} else {
cbMacHdLen = WLAN_HDR_ADDR3_LEN;
}
pTxBufHead->wFragCtl |= cpu_to_le16((u16)(cbMacHdLen << 10));
pDevice->bAES = false;
if (WLAN_GET_FC_ISWEP(pPacket->p80211Header->sA4.wFrameCtl) != 0) {
if (pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled) {
cbIVlen = 4;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_LEGACY;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
cbIVlen = 8;
cbMIClen = 8;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_TKIP;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
cbIVlen = 8;
cbICVlen = 8;
pTxBufHead->wFragCtl |= FRAGCTL_AES;
pDevice->bAES = true;
}
uPadding = 4 - (cbMacHdLen%4);
uPadding %= 4;
}
cbFrameSize = cbMacHdLen + cbFrameBodySize + cbIVlen + cbMIClen + cbICVlen + cbFCSlen;
if (pDevice->bGrpAckPolicy == true) {
pTxBufHead->wFIFOCtl |= FIFOCTL_GRPACK;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
cbHeaderSize = wTxBufSize + sizeof(struct vnt_rrv_time_cts) +
sizeof(struct vnt_cts);
}
else {
cbHeaderSize = wTxBufSize + sizeof(struct vnt_rrv_time_ab) +
sizeof(struct vnt_tx_datahead_ab);
}
memcpy(&(sEthHeader.h_dest[0]),
&(pPacket->p80211Header->sA3.abyAddr1[0]),
ETH_ALEN);
memcpy(&(sEthHeader.h_source[0]),
&(pPacket->p80211Header->sA3.abyAddr2[0]),
ETH_ALEN);
pTxBufHead->wFragCtl |= (u16)FRAGCTL_NONFRAG;
uDuration = s_vGenerateTxParameter(pDevice, byPktType, wCurrentRate,
pTX_Buffer, &pMICHDR, 0,
cbFrameSize, bNeedACK, TYPE_TXDMA0, &sEthHeader, false);
pMACHeader = (struct ieee80211_hdr *) (pbyTxBufferAddr + cbHeaderSize);
cbReqCount = cbHeaderSize + cbMacHdLen + uPadding + cbIVlen + cbFrameBodySize;
if (WLAN_GET_FC_ISWEP(pPacket->p80211Header->sA4.wFrameCtl) != 0) {
u8 * pbyIVHead;
u8 * pbyPayloadHead;
u8 * pbyBSSID;
PSKeyItem pTransmitKey = NULL;
pbyIVHead = (u8 *)(pbyTxBufferAddr + cbHeaderSize + cbMacHdLen + uPadding);
pbyPayloadHead = (u8 *)(pbyTxBufferAddr + cbHeaderSize + cbMacHdLen + uPadding + cbIVlen);
do {
if ((pDevice->eOPMode == OP_MODE_INFRASTRUCTURE) &&
(pDevice->bLinkPass == true)) {
pbyBSSID = pDevice->abyBSSID;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == false) {
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Get GTK.\n");
break;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Get PTK.\n");
break;
}
}
pbyBSSID = pDevice->abyBroadcastAddr;
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"KEY is NULL. OP Mode[%d]\n", pDevice->eOPMode);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Get GTK.\n");
}
} while(false);
s_vFillTxKey(pDevice, pTxBufHead, pbyIVHead, pTransmitKey,
(u8 *)pMACHeader, (u16)cbFrameBodySize, NULL);
memcpy(pMACHeader, pPacket->p80211Header, cbMacHdLen);
memcpy(pbyPayloadHead, ((u8 *)(pPacket->p80211Header) + cbMacHdLen),
cbFrameBodySize);
}
else {
memcpy(pMACHeader, pPacket->p80211Header, pPacket->cbMPDULen);
}
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pDevice->wSeqCounter++ ;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
if (bIsPSPOLL) {
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
struct vnt_tx_datahead_g *data_head = &pTX_Buffer->tx_head.
tx_cts.tx.head.cts_g.data_head;
data_head->wDuration_a =
cpu_to_le16(pPacket->p80211Header->sA2.wDurationID);
data_head->wDuration_b =
cpu_to_le16(pPacket->p80211Header->sA2.wDurationID);
} else {
struct vnt_tx_datahead_ab *data_head = &pTX_Buffer->tx_head.
tx_ab.tx.head.data_head_ab;
data_head->wDuration =
cpu_to_le16(pPacket->p80211Header->sA2.wDurationID);
}
}
pTX_Buffer->wTxByteCount = cpu_to_le16((u16)(cbReqCount));
pTX_Buffer->byPKTNO = (u8) (((wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->byType = 0x00;
pContext->pPacket = NULL;
pContext->Type = CONTEXT_MGMT_PACKET;
pContext->uBufLen = (u16)cbReqCount + 4;
if (WLAN_GET_FC_TODS(pMACHeader->frame_control) == 0) {
s_vSaveTxPktInfo(pDevice, (u8)(pTX_Buffer->byPKTNO & 0x0F),
&pMACHeader->addr1[0], (u16)cbFrameSize,
pTxBufHead->wFIFOCtl);
}
else {
s_vSaveTxPktInfo(pDevice, (u8)(pTX_Buffer->byPKTNO & 0x0F),
&pMACHeader->addr3[0], (u16)cbFrameSize,
pTxBufHead->wFIFOCtl);
}
PIPEnsSendBulkOut(pDevice,pContext);
return CMD_STATUS_PENDING;
}
CMD_STATUS csBeacon_xmit(struct vnt_private *pDevice,
struct vnt_tx_mgmt *pPacket)
{
struct vnt_beacon_buffer *pTX_Buffer;
u32 cbFrameSize = pPacket->cbMPDULen + WLAN_FCS_LEN;
u32 cbHeaderSize = 0;
u16 wTxBufSize = sizeof(STxShortBufHead);
PSTxShortBufHead pTxBufHead;
struct ieee80211_hdr *pMACHeader;
struct vnt_tx_datahead_ab *pTxDataHead;
u16 wCurrentRate;
u32 cbFrameBodySize;
u32 cbReqCount;
u8 *pbyTxBufferAddr;
struct vnt_usb_send_context *pContext;
CMD_STATUS status;
pContext = (struct vnt_usb_send_context *)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
status = CMD_STATUS_RESOURCES;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ManagementSend TX...NO CONTEXT!\n");
return status ;
}
pTX_Buffer = (struct vnt_beacon_buffer *)&pContext->Data[0];
pbyTxBufferAddr = (u8 *)&(pTX_Buffer->wFIFOCtl);
cbFrameBodySize = pPacket->cbPayloadLen;
pTxBufHead = (PSTxShortBufHead) pbyTxBufferAddr;
wTxBufSize = sizeof(STxShortBufHead);
if (pDevice->byBBType == BB_TYPE_11A) {
wCurrentRate = RATE_6M;
pTxDataHead = (struct vnt_tx_datahead_ab *)
(pbyTxBufferAddr + wTxBufSize);
BBvCalculateParameter(pDevice, cbFrameSize, wCurrentRate, PK_TYPE_11A,
&pTxDataHead->ab);
pTxDataHead->wDuration = s_uGetDataDuration(pDevice,
PK_TYPE_11A, false);
pTxDataHead->wTimeStampOff = vnt_time_stamp_off(pDevice, wCurrentRate);
cbHeaderSize = wTxBufSize + sizeof(struct vnt_tx_datahead_ab);
} else {
wCurrentRate = RATE_1M;
pTxBufHead->wFIFOCtl |= FIFOCTL_11B;
pTxDataHead = (struct vnt_tx_datahead_ab *)
(pbyTxBufferAddr + wTxBufSize);
BBvCalculateParameter(pDevice, cbFrameSize, wCurrentRate, PK_TYPE_11B,
&pTxDataHead->ab);
pTxDataHead->wDuration = s_uGetDataDuration(pDevice,
PK_TYPE_11B, false);
pTxDataHead->wTimeStampOff = vnt_time_stamp_off(pDevice, wCurrentRate);
cbHeaderSize = wTxBufSize + sizeof(struct vnt_tx_datahead_ab);
}
pMACHeader = (struct ieee80211_hdr *)(pbyTxBufferAddr + cbHeaderSize);
memcpy(pMACHeader, pPacket->p80211Header, pPacket->cbMPDULen);
pMACHeader->duration_id = 0;
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pDevice->wSeqCounter++ ;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
cbReqCount = cbHeaderSize + WLAN_HDR_ADDR3_LEN + cbFrameBodySize;
pTX_Buffer->wTxByteCount = (u16)cbReqCount;
pTX_Buffer->byPKTNO = (u8) (((wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->byType = 0x01;
pContext->pPacket = NULL;
pContext->Type = CONTEXT_MGMT_PACKET;
pContext->uBufLen = (u16)cbReqCount + 4;
PIPEnsSendBulkOut(pDevice,pContext);
return CMD_STATUS_PENDING;
}
void vDMA0_tx_80211(struct vnt_private *pDevice, struct sk_buff *skb)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
struct vnt_tx_buffer *pTX_Buffer;
struct vnt_tx_fifo_head *pTxBufHead;
u8 byPktType;
u8 *pbyTxBufferAddr;
u32 uDuration, cbReqCount;
struct ieee80211_hdr *pMACHeader;
u32 cbHeaderSize, cbFrameBodySize;
int bNeedACK, bIsPSPOLL = false;
u32 cbFrameSize;
u32 cbIVlen = 0, cbICVlen = 0, cbMIClen = 0, cbFCSlen = 4;
u32 uPadding = 0;
u32 cbMICHDR = 0, uLength = 0;
u32 dwMICKey0, dwMICKey1;
u32 dwMIC_Priority;
u32 *pdwMIC_L, *pdwMIC_R;
u16 wTxBufSize;
u32 cbMacHdLen;
struct ethhdr sEthHeader;
struct vnt_mic_hdr *pMICHDR;
u32 wCurrentRate = RATE_1M;
PUWLAN_80211HDR p80211Header;
u32 uNodeIndex = 0;
int bNodeExist = false;
SKeyItem STempKey;
PSKeyItem pTransmitKey = NULL;
u8 *pbyIVHead, *pbyPayloadHead, *pbyMacHdr;
u32 cbExtSuppRate = 0;
struct vnt_usb_send_context *pContext;
pMICHDR = NULL;
if(skb->len <= WLAN_HDR_ADDR3_LEN) {
cbFrameBodySize = 0;
}
else {
cbFrameBodySize = skb->len - WLAN_HDR_ADDR3_LEN;
}
p80211Header = (PUWLAN_80211HDR)skb->data;
pContext = (struct vnt_usb_send_context *)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"DMA0 TX...NO CONTEXT!\n");
dev_kfree_skb_irq(skb);
return ;
}
pTX_Buffer = (struct vnt_tx_buffer *)&pContext->Data[0];
pTxBufHead = &pTX_Buffer->fifo_head;
pbyTxBufferAddr = (u8 *)&pTxBufHead->adwTxKey[0];
wTxBufSize = sizeof(struct vnt_tx_fifo_head);
if (pDevice->byBBType == BB_TYPE_11A) {
wCurrentRate = RATE_6M;
byPktType = PK_TYPE_11A;
} else {
wCurrentRate = RATE_1M;
byPktType = PK_TYPE_11B;
}
if (pMgmt->eScanState != WMAC_NO_SCANNING) {
RFbSetPower(pDevice, wCurrentRate, pDevice->byCurrentCh);
} else {
RFbSetPower(pDevice, wCurrentRate, pMgmt->uCurrChannel);
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"vDMA0_tx_80211: p80211Header->sA3.wFrameCtl = %x \n", p80211Header->sA3.wFrameCtl);
if (byPktType == PK_TYPE_11A) {
pTxBufHead->wFIFOCtl = 0;
}
else if (byPktType == PK_TYPE_11B) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11B;
}
else if (byPktType == PK_TYPE_11GB) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GB;
}
else if (byPktType == PK_TYPE_11GA) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GA;
}
pTxBufHead->wFIFOCtl |= FIFOCTL_TMOEN;
pTxBufHead->wTimeStamp = cpu_to_le16(DEFAULT_MGN_LIFETIME_RES_64us);
if (is_multicast_ether_addr(p80211Header->sA3.abyAddr1)) {
bNeedACK = false;
if (pDevice->bEnableHostWEP) {
uNodeIndex = 0;
bNodeExist = true;
}
}
else {
if (pDevice->bEnableHostWEP) {
if (BSSbIsSTAInNodeDB(pDevice, (u8 *)(p80211Header->sA3.abyAddr1), &uNodeIndex))
bNodeExist = true;
}
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
};
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) ||
(pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) ) {
pTxBufHead->wFIFOCtl |= FIFOCTL_LRETRY;
}
pTxBufHead->wFIFOCtl |= (FIFOCTL_GENINT | FIFOCTL_ISDMA0);
if ((p80211Header->sA4.wFrameCtl & TYPE_SUBTYPE_MASK) == TYPE_CTL_PSPOLL) {
bIsPSPOLL = true;
cbMacHdLen = WLAN_HDR_ADDR2_LEN;
} else {
cbMacHdLen = WLAN_HDR_ADDR3_LEN;
}
if (WLAN_GET_FC_FSTYPE(p80211Header->sA4.wFrameCtl) == WLAN_FSTYPE_ASSOCRESP) {
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len != 0) {
cbExtSuppRate += ((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len + WLAN_IEHDR_LEN;
}
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len != 0) {
cbExtSuppRate += ((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len + WLAN_IEHDR_LEN;
}
if (cbExtSuppRate >0) {
cbFrameBodySize = WLAN_ASSOCRESP_OFF_SUPP_RATES;
}
}
pTxBufHead->wFragCtl |= cpu_to_le16((u16)cbMacHdLen << 10);
pDevice->bAES = false;
if (WLAN_GET_FC_ISWEP(p80211Header->sA4.wFrameCtl) != 0) {
if (pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled) {
cbIVlen = 4;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_LEGACY;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
cbIVlen = 8;
cbMIClen = 8;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_TKIP;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
cbIVlen = 8;
cbICVlen = 8;
cbMICHDR = sizeof(struct vnt_mic_hdr);
pTxBufHead->wFragCtl |= FRAGCTL_AES;
pDevice->bAES = true;
}
uPadding = 4 - (cbMacHdLen%4);
uPadding %= 4;
}
cbFrameSize = cbMacHdLen + cbFrameBodySize + cbIVlen + cbMIClen + cbICVlen + cbFCSlen + cbExtSuppRate;
if (pDevice->bGrpAckPolicy == true) {
pTxBufHead->wFIFOCtl |= FIFOCTL_GRPACK;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
cbHeaderSize = wTxBufSize + sizeof(struct vnt_rrv_time_cts) + cbMICHDR +
sizeof(struct vnt_cts);
}
else {
cbHeaderSize = wTxBufSize + sizeof(struct vnt_rrv_time_ab) + cbMICHDR +
sizeof(struct vnt_tx_datahead_ab);
}
memcpy(&(sEthHeader.h_dest[0]),
&(p80211Header->sA3.abyAddr1[0]),
ETH_ALEN);
memcpy(&(sEthHeader.h_source[0]),
&(p80211Header->sA3.abyAddr2[0]),
ETH_ALEN);
pTxBufHead->wFragCtl |= (u16)FRAGCTL_NONFRAG;
uDuration = s_vGenerateTxParameter(pDevice, byPktType, wCurrentRate,
pTX_Buffer, &pMICHDR, cbMICHDR,
cbFrameSize, bNeedACK, TYPE_TXDMA0, &sEthHeader, false);
pMACHeader = (struct ieee80211_hdr *) (pbyTxBufferAddr + cbHeaderSize);
cbReqCount = cbHeaderSize + cbMacHdLen + uPadding + cbIVlen + (cbFrameBodySize + cbMIClen) + cbExtSuppRate;
pbyMacHdr = (u8 *)(pbyTxBufferAddr + cbHeaderSize);
pbyPayloadHead = (u8 *)(pbyMacHdr + cbMacHdLen + uPadding + cbIVlen);
pbyIVHead = (u8 *)(pbyMacHdr + cbMacHdLen + uPadding);
memcpy(pbyMacHdr, skb->data, cbMacHdLen);
pMACHeader->frame_control &= cpu_to_le16(0xfffc);
memcpy(pbyPayloadHead, (skb->data + cbMacHdLen), cbFrameBodySize);
if (WLAN_GET_FC_FSTYPE(p80211Header->sA4.wFrameCtl) == WLAN_FSTYPE_ASSOCRESP) {
if (cbExtSuppRate != 0) {
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len != 0)
memcpy((pbyPayloadHead + cbFrameBodySize),
pMgmt->abyCurrSuppRates,
((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len + WLAN_IEHDR_LEN
);
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len != 0)
memcpy((pbyPayloadHead + cbFrameBodySize) + ((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len + WLAN_IEHDR_LEN,
pMgmt->abyCurrExtSuppRates,
((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len + WLAN_IEHDR_LEN
);
}
}
if (WLAN_GET_FC_ISWEP(p80211Header->sA4.wFrameCtl) != 0) {
if (pDevice->bEnableHostWEP) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
if ((pTransmitKey != NULL) && (pTransmitKey->byCipherSuite == KEY_CTL_TKIP)) {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[16]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[20]);
MIC_vInit(dwMICKey0, dwMICKey1);
MIC_vAppend((u8 *)&(sEthHeader.h_dest[0]), 12);
dwMIC_Priority = 0;
MIC_vAppend((u8 *)&dwMIC_Priority, 4);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"DMA0_tx_8021:MIC KEY:"\
" %X, %X\n", dwMICKey0, dwMICKey1);
uLength = cbHeaderSize + cbMacHdLen + uPadding + cbIVlen;
MIC_vAppend((pbyTxBufferAddr + uLength), cbFrameBodySize);
pdwMIC_L = (u32 *)(pbyTxBufferAddr + uLength + cbFrameBodySize);
pdwMIC_R = (u32 *)(pbyTxBufferAddr + uLength + cbFrameBodySize + 4);
MIC_vGetMIC(pdwMIC_L, pdwMIC_R);
MIC_vUnInit();
if (pDevice->bTxMICFail == true) {
*pdwMIC_L = 0;
*pdwMIC_R = 0;
pDevice->bTxMICFail = false;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"uLength: %d, %d\n", uLength, cbFrameBodySize);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"cbReqCount:%d, %d, %d, %d\n", cbReqCount, cbHeaderSize, uPadding, cbIVlen);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"MIC:%x, %x\n",
*pdwMIC_L, *pdwMIC_R);
}
s_vFillTxKey(pDevice, pTxBufHead, pbyIVHead, pTransmitKey,
pbyMacHdr, (u16)cbFrameBodySize, pMICHDR);
if (pDevice->bEnableHostWEP) {
pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16 = pTransmitKey->dwTSC47_16;
pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0 = pTransmitKey->wTSC15_0;
}
if ((pDevice->byLocalID <= REV_ID_VT3253_A1)) {
s_vSWencryption(pDevice, pTransmitKey, pbyPayloadHead, (u16)(cbFrameBodySize + cbMIClen));
}
}
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pDevice->wSeqCounter++ ;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
if (bIsPSPOLL) {
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
struct vnt_tx_datahead_g *data_head = &pTX_Buffer->tx_head.
tx_cts.tx.head.cts_g.data_head;
data_head->wDuration_a =
cpu_to_le16(p80211Header->sA2.wDurationID);
data_head->wDuration_b =
cpu_to_le16(p80211Header->sA2.wDurationID);
} else {
struct vnt_tx_datahead_ab *data_head = &pTX_Buffer->tx_head.
tx_ab.tx.head.data_head_ab;
data_head->wDuration =
cpu_to_le16(p80211Header->sA2.wDurationID);
}
}
pTX_Buffer->wTxByteCount = cpu_to_le16((u16)(cbReqCount));
pTX_Buffer->byPKTNO = (u8) (((wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->byType = 0x00;
pContext->pPacket = skb;
pContext->Type = CONTEXT_MGMT_PACKET;
pContext->uBufLen = (u16)cbReqCount + 4;
if (WLAN_GET_FC_TODS(pMACHeader->frame_control) == 0) {
s_vSaveTxPktInfo(pDevice, (u8)(pTX_Buffer->byPKTNO & 0x0F),
&pMACHeader->addr1[0], (u16)cbFrameSize,
pTxBufHead->wFIFOCtl);
}
else {
s_vSaveTxPktInfo(pDevice, (u8)(pTX_Buffer->byPKTNO & 0x0F),
&pMACHeader->addr3[0], (u16)cbFrameSize,
pTxBufHead->wFIFOCtl);
}
PIPEnsSendBulkOut(pDevice,pContext);
return ;
}
int nsDMA_tx_packet(struct vnt_private *pDevice,
u32 uDMAIdx, struct sk_buff *skb)
{
struct net_device_stats *pStats = &pDevice->stats;
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
struct vnt_tx_buffer *pTX_Buffer;
u32 BytesToWrite = 0, uHeaderLen = 0;
u32 uNodeIndex = 0;
u8 byMask[8] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
u16 wAID;
u8 byPktType;
int bNeedEncryption = false;
PSKeyItem pTransmitKey = NULL;
SKeyItem STempKey;
int ii;
int bTKIP_UseGTK = false;
int bNeedDeAuth = false;
u8 *pbyBSSID;
int bNodeExist = false;
struct vnt_usb_send_context *pContext;
bool fConvertedPacket;
u32 status;
u16 wKeepRate = pDevice->wCurrentRate;
int bTxeapol_key = false;
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
if (pDevice->uAssocCount == 0) {
dev_kfree_skb_irq(skb);
return 0;
}
if (is_multicast_ether_addr((u8 *)(skb->data))) {
uNodeIndex = 0;
bNodeExist = true;
if (pMgmt->sNodeDBTable[0].bPSEnable) {
skb_queue_tail(&(pMgmt->sNodeDBTable[0].sTxPSQueue), skb);
pMgmt->sNodeDBTable[0].wEnQueueCnt++;
pMgmt->abyPSTxMap[0] |= byMask[0];
return 0;
}
if (pDevice->byBBType != BB_TYPE_11A)
pDevice->wCurrentRate = RATE_2M;
else
pDevice->wCurrentRate = RATE_24M;
pDevice->byPreambleType = PREAMBLE_SHORT;
}else {
if (BSSbIsSTAInNodeDB(pDevice, (u8 *)(skb->data), &uNodeIndex)) {
if (pMgmt->sNodeDBTable[uNodeIndex].bPSEnable) {
skb_queue_tail(&pMgmt->sNodeDBTable[uNodeIndex].sTxPSQueue, skb);
pMgmt->sNodeDBTable[uNodeIndex].wEnQueueCnt++;
wAID = pMgmt->sNodeDBTable[uNodeIndex].wAID;
pMgmt->abyPSTxMap[wAID >> 3] |= byMask[wAID & 7];
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Set:pMgmt->abyPSTxMap[%d]= %d\n",
(wAID >> 3), pMgmt->abyPSTxMap[wAID >> 3]);
return 0;
}
pDevice->wCurrentRate = pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}else {
pDevice->byPreambleType = PREAMBLE_LONG;
}
bNodeExist = true;
}
}
if (bNodeExist == false) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Unknown STA not found in node DB \n");
dev_kfree_skb_irq(skb);
return 0;
}
}
pContext = (struct vnt_usb_send_context *)s_vGetFreeContext(pDevice);
if (pContext == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG" pContext == NULL\n");
dev_kfree_skb_irq(skb);
return STATUS_RESOURCES;
}
memcpy(pDevice->sTxEthHeader.h_dest, (u8 *)(skb->data), ETH_HLEN);
{
u8 Protocol_Version;
u8 Packet_Type;
u8 Descriptor_type;
u16 Key_info;
Protocol_Version = skb->data[ETH_HLEN];
Packet_Type = skb->data[ETH_HLEN+1];
Descriptor_type = skb->data[ETH_HLEN+1+1+2];
Key_info = (skb->data[ETH_HLEN+1+1+2+1] << 8)|(skb->data[ETH_HLEN+1+1+2+2]);
if (pDevice->sTxEthHeader.h_proto == cpu_to_be16(ETH_P_PAE)) {
if (((Protocol_Version == 1) || (Protocol_Version == 2)) &&
(Packet_Type == 3)) {
bTxeapol_key = true;
if(!(Key_info & BIT3) &&
(Key_info & BIT8) && (Key_info & BIT9)) {
if(Descriptor_type==254) {
pDevice->fWPA_Authened = true;
PRINT_K("WPA ");
}
else {
pDevice->fWPA_Authened = true;
PRINT_K("WPA2(re-keying) ");
}
PRINT_K("Authentication completed!!\n");
}
else if((Key_info & BIT3) && (Descriptor_type==2) &&
(Key_info & BIT8) && (Key_info & BIT9)) {
pDevice->fWPA_Authened = true;
PRINT_K("WPA2 Authentication completed!!\n");
}
}
}
}
if (pDevice->bEncryptionEnable == true) {
bNeedEncryption = true;
do {
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_STA) &&
(pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
pbyBSSID = pDevice->abyBSSID;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == false) {
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == true) {
bTKIP_UseGTK = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get GTK.\n");
break;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get PTK.\n");
break;
}
}else if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
pbyBSSID = pDevice->sTxEthHeader.h_dest;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"IBSS Serach Key: \n");
for (ii = 0; ii< 6; ii++)
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"%x \n", *(pbyBSSID+ii));
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"\n");
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == true)
break;
}
pbyBSSID = pDevice->abyBroadcastAddr;
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"IBSS and KEY is NULL. [%d]\n", pMgmt->eCurrMode);
}
else
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"NOT IBSS and KEY is NULL. [%d]\n", pMgmt->eCurrMode);
} else {
bTKIP_UseGTK = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get GTK.\n");
}
} while(false);
}
if (pDevice->bEnableHostWEP) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"acdma0: STA index %d\n", uNodeIndex);
if (pDevice->bEncryptionEnable == true) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
}
byPktType = (u8)pDevice->byPacketType;
if (pDevice->bFixRate) {
if (pDevice->byBBType == BB_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M) {
pDevice->wCurrentRate = RATE_11M;
} else {
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
} else {
if ((pDevice->byBBType == BB_TYPE_11A) &&
(pDevice->uConnectionRate <= RATE_6M)) {
pDevice->wCurrentRate = RATE_6M;
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
}
}
else {
if (pDevice->eOPMode == OP_MODE_ADHOC) {
if (is_multicast_ether_addr(pDevice->sTxEthHeader.h_dest)) {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[0].wTxDataRate;
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
if (BSSbIsSTAInNodeDB(pDevice, &(pDevice->sTxEthHeader.h_dest[0]), &uNodeIndex)) {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
pDevice->byPreambleType = PREAMBLE_LONG;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Found Node Index is [%d] Tx Data Rate:[%d]\n",uNodeIndex, pDevice->wCurrentRate);
}
else {
if (pDevice->byBBType != BB_TYPE_11A)
pDevice->wCurrentRate = RATE_2M;
else
pDevice->wCurrentRate = RATE_24M;
pDevice->byPreambleType = PREAMBLE_SHORT;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Not Found Node use highest basic Rate.....\n");
}
}
}
if (pDevice->eOPMode == OP_MODE_INFRASTRUCTURE) {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[0].wTxDataRate;
}
}
if (pDevice->sTxEthHeader.h_proto == cpu_to_be16(ETH_P_PAE)) {
if (pDevice->byBBType != BB_TYPE_11A) {
pDevice->wCurrentRate = RATE_1M;
pDevice->byACKRate = RATE_1M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
} else {
pDevice->wCurrentRate = RATE_6M;
pDevice->byACKRate = RATE_6M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
}
}
DBG_PRT(MSG_LEVEL_DEBUG,
KERN_INFO "dma_tx: pDevice->wCurrentRate = %d\n",
pDevice->wCurrentRate);
if (wKeepRate != pDevice->wCurrentRate) {
bScheduleCommand((void *) pDevice, WLAN_CMD_SETPOWER, NULL);
}
if (pDevice->wCurrentRate <= RATE_11M) {
byPktType = PK_TYPE_11B;
}
if (bNeedEncryption == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ntohs Pkt Type=%04x\n", ntohs(pDevice->sTxEthHeader.h_proto));
if ((pDevice->sTxEthHeader.h_proto) == cpu_to_be16(ETH_P_PAE)) {
bNeedEncryption = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Pkt Type=%04x\n", (pDevice->sTxEthHeader.h_proto));
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_STA) && (pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
if (pTransmitKey == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Don't Find TX KEY\n");
}
else {
if (bTKIP_UseGTK == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"error: KEY is GTK!!~~\n");
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Find PTK [%X]\n",
pTransmitKey->dwKeyIndex);
bNeedEncryption = true;
}
}
}
if (pDevice->bEnableHostWEP) {
if ((uNodeIndex != 0) &&
(pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex & PAIRWISE_KEY)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Find PTK [%X]\n",
pTransmitKey->dwKeyIndex);
bNeedEncryption = true;
}
}
}
else {
if (pTransmitKey == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"return no tx key\n");
pContext->bBoolInUse = false;
dev_kfree_skb_irq(skb);
pStats->tx_dropped++;
return STATUS_FAILURE;
}
}
}
pTX_Buffer = (struct vnt_tx_buffer *)&pContext->Data[0];
fConvertedPacket = s_bPacketToWirelessUsb(pDevice, byPktType,
pTX_Buffer, bNeedEncryption,
skb->len, uDMAIdx, &pDevice->sTxEthHeader,
(u8 *)skb->data, pTransmitKey, uNodeIndex,
pDevice->wCurrentRate,
&uHeaderLen, &BytesToWrite
);
if (fConvertedPacket == false) {
pContext->bBoolInUse = false;
dev_kfree_skb_irq(skb);
return STATUS_FAILURE;
}
if ( pDevice->bEnablePSMode == true ) {
if ( !pDevice->bPSModeTxBurst ) {
bScheduleCommand((void *) pDevice,
WLAN_CMD_MAC_DISPOWERSAVING,
NULL);
pDevice->bPSModeTxBurst = true;
}
}
pTX_Buffer->byPKTNO = (u8) (((pDevice->wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->wTxByteCount = (u16)BytesToWrite;
pContext->pPacket = skb;
pContext->Type = CONTEXT_DATA_PACKET;
pContext->uBufLen = (u16)BytesToWrite + 4 ;
s_vSaveTxPktInfo(pDevice, (u8)(pTX_Buffer->byPKTNO & 0x0F),
&pContext->sEthHeader.h_dest[0],
(u16)(BytesToWrite-uHeaderLen),
pTX_Buffer->fifo_head.wFIFOCtl);
status = PIPEnsSendBulkOut(pDevice,pContext);
if (bNeedDeAuth == true) {
u16 wReason = WLAN_MGMT_REASON_MIC_FAILURE;
bScheduleCommand((void *) pDevice, WLAN_CMD_DEAUTH, (u8 *) &wReason);
}
if(status!=STATUS_PENDING) {
pContext->bBoolInUse = false;
dev_kfree_skb_irq(skb);
return STATUS_FAILURE;
}
else
return 0;
}
int bRelayPacketSend(struct vnt_private *pDevice, u8 *pbySkbData, u32 uDataLen,
u32 uNodeIndex)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
struct vnt_tx_buffer *pTX_Buffer;
u32 BytesToWrite = 0, uHeaderLen = 0;
u8 byPktType = PK_TYPE_11B;
int bNeedEncryption = false;
SKeyItem STempKey;
PSKeyItem pTransmitKey = NULL;
u8 *pbyBSSID;
struct vnt_usb_send_context *pContext;
u8 byPktTyp;
int fConvertedPacket;
u32 status;
u16 wKeepRate = pDevice->wCurrentRate;
pContext = (struct vnt_usb_send_context *)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
return false;
}
memcpy(pDevice->sTxEthHeader.h_dest, (u8 *)pbySkbData, ETH_HLEN);
if (pDevice->bEncryptionEnable == true) {
bNeedEncryption = true;
pbyBSSID = pDevice->abyBroadcastAddr;
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"KEY is NULL. [%d]\n", pMgmt->eCurrMode);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get GTK.\n");
}
}
if (pDevice->bEnableHostWEP) {
if (uNodeIndex < MAX_NODE_NUM + 1) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
}
if ( bNeedEncryption && (pTransmitKey == NULL) ) {
pContext->bBoolInUse = false;
return false;
}
byPktTyp = (u8)pDevice->byPacketType;
if (pDevice->bFixRate) {
if (pDevice->byBBType == BB_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M) {
pDevice->wCurrentRate = RATE_11M;
} else {
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
} else {
if ((pDevice->byBBType == BB_TYPE_11A) &&
(pDevice->uConnectionRate <= RATE_6M)) {
pDevice->wCurrentRate = RATE_6M;
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
}
}
else {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
}
if (wKeepRate != pDevice->wCurrentRate) {
bScheduleCommand((void *) pDevice, WLAN_CMD_SETPOWER, NULL);
}
if (pDevice->wCurrentRate <= RATE_11M)
byPktType = PK_TYPE_11B;
BytesToWrite = uDataLen + ETH_FCS_LEN;
pTX_Buffer = (struct vnt_tx_buffer *)&pContext->Data[0];
fConvertedPacket = s_bPacketToWirelessUsb(pDevice, byPktType,
pTX_Buffer, bNeedEncryption,
uDataLen, TYPE_AC0DMA, &pDevice->sTxEthHeader,
pbySkbData, pTransmitKey, uNodeIndex,
pDevice->wCurrentRate,
&uHeaderLen, &BytesToWrite
);
if (fConvertedPacket == false) {
pContext->bBoolInUse = false;
return false;
}
pTX_Buffer->byPKTNO = (u8) (((pDevice->wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->wTxByteCount = (u16)BytesToWrite;
pContext->pPacket = NULL;
pContext->Type = CONTEXT_DATA_PACKET;
pContext->uBufLen = (u16)BytesToWrite + 4 ;
s_vSaveTxPktInfo(pDevice, (u8)(pTX_Buffer->byPKTNO & 0x0F),
&pContext->sEthHeader.h_dest[0],
(u16)(BytesToWrite - uHeaderLen),
pTX_Buffer->fifo_head.wFIFOCtl);
status = PIPEnsSendBulkOut(pDevice,pContext);
return true;
}
