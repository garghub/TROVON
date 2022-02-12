static
void
s_vChangeAntenna(
struct vnt_private *priv
)
{
if (priv->dwRxAntennaSel == 0) {
priv->dwRxAntennaSel = 1;
if (priv->bTxRxAntInv == true)
BBvSetRxAntennaMode(priv, ANT_A);
else
BBvSetRxAntennaMode(priv, ANT_B);
} else {
priv->dwRxAntennaSel = 0;
if (priv->bTxRxAntInv == true)
BBvSetRxAntennaMode(priv, ANT_B);
else
BBvSetRxAntennaMode(priv, ANT_A);
}
if (priv->dwTxAntennaSel == 0) {
priv->dwTxAntennaSel = 1;
BBvSetTxAntennaMode(priv, ANT_B);
} else {
priv->dwTxAntennaSel = 0;
BBvSetTxAntennaMode(priv, ANT_A);
}
}
unsigned int
BBuGetFrameTime(
unsigned char byPreambleType,
unsigned char byPktType,
unsigned int cbFrameLength,
unsigned short wRate
)
{
unsigned int uFrameTime;
unsigned int uPreamble;
unsigned int uTmp;
unsigned int uRateIdx = (unsigned int) wRate;
unsigned int uRate = 0;
if (uRateIdx > RATE_54M) {
ASSERT(0);
return 0;
}
uRate = (unsigned int)awcFrameTime[uRateIdx];
if (uRateIdx <= 3) {
if (byPreambleType == 1)
uPreamble = 96;
else
uPreamble = 192;
uFrameTime = (cbFrameLength * 80) / uRate;
uTmp = (uFrameTime * uRate) / 80;
if (cbFrameLength != uTmp)
uFrameTime++;
return uPreamble + uFrameTime;
}
uFrameTime = (cbFrameLength * 8 + 22) / uRate;
uTmp = ((uFrameTime * uRate) - 22) / 8;
if (cbFrameLength != uTmp)
uFrameTime++;
uFrameTime = uFrameTime * 4;
if (byPktType != PK_TYPE_11A)
uFrameTime += 6;
return 20 + uFrameTime;
}
void vnt_get_phy_field(struct vnt_private *priv, u32 frame_length,
u16 tx_rate, u8 pkt_type, struct vnt_phy_field *phy)
{
u32 bit_count;
u32 count = 0;
u32 tmp;
int ext_bit;
u8 preamble_type = priv->byPreambleType;
bit_count = frame_length * 8;
ext_bit = false;
switch (tx_rate) {
case RATE_1M:
count = bit_count;
phy->signal = 0x00;
break;
case RATE_2M:
count = bit_count / 2;
if (preamble_type == 1)
phy->signal = 0x09;
else
phy->signal = 0x01;
break;
case RATE_5M:
count = (bit_count * 10) / 55;
tmp = (count * 55) / 10;
if (tmp != bit_count)
count++;
if (preamble_type == 1)
phy->signal = 0x0a;
else
phy->signal = 0x02;
break;
case RATE_11M:
count = bit_count / 11;
tmp = count * 11;
if (tmp != bit_count) {
count++;
if ((bit_count - tmp) <= 3)
ext_bit = true;
}
if (preamble_type == 1)
phy->signal = 0x0b;
else
phy->signal = 0x03;
break;
case RATE_6M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9b;
else
phy->signal = 0x8b;
break;
case RATE_9M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9f;
else
phy->signal = 0x8f;
break;
case RATE_12M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9a;
else
phy->signal = 0x8a;
break;
case RATE_18M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9e;
else
phy->signal = 0x8e;
break;
case RATE_24M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x99;
else
phy->signal = 0x89;
break;
case RATE_36M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9d;
else
phy->signal = 0x8d;
break;
case RATE_48M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x98;
else
phy->signal = 0x88;
break;
case RATE_54M:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9c;
else
phy->signal = 0x8c;
break;
default:
if (pkt_type == PK_TYPE_11A)
phy->signal = 0x9c;
else
phy->signal = 0x8c;
break;
}
if (pkt_type == PK_TYPE_11B) {
phy->service = 0x00;
if (ext_bit)
phy->service |= 0x80;
phy->len = cpu_to_le16((u16)count);
} else {
phy->service = 0x00;
phy->len = cpu_to_le16((u16)frame_length);
}
}
bool BBbReadEmbedded(struct vnt_private *priv,
unsigned char byBBAddr, unsigned char *pbyData)
{
void __iomem *dwIoBase = priv->PortOffset;
unsigned short ww;
unsigned char byValue;
VNSvOutPortB(dwIoBase + MAC_REG_BBREGADR, byBBAddr);
MACvRegBitsOn(dwIoBase, MAC_REG_BBREGCTL, BBREGCTL_REGR);
for (ww = 0; ww < W_MAX_TIMEOUT; ww++) {
VNSvInPortB(dwIoBase + MAC_REG_BBREGCTL, &byValue);
if (byValue & BBREGCTL_DONE)
break;
}
VNSvInPortB(dwIoBase + MAC_REG_BBREGDATA, pbyData);
if (ww == W_MAX_TIMEOUT) {
DBG_PORT80(0x30);
pr_debug(" DBG_PORT80(0x30)\n");
return false;
}
return true;
}
bool BBbWriteEmbedded(struct vnt_private *priv,
unsigned char byBBAddr, unsigned char byData)
{
void __iomem *dwIoBase = priv->PortOffset;
unsigned short ww;
unsigned char byValue;
VNSvOutPortB(dwIoBase + MAC_REG_BBREGADR, byBBAddr);
VNSvOutPortB(dwIoBase + MAC_REG_BBREGDATA, byData);
MACvRegBitsOn(dwIoBase, MAC_REG_BBREGCTL, BBREGCTL_REGW);
for (ww = 0; ww < W_MAX_TIMEOUT; ww++) {
VNSvInPortB(dwIoBase + MAC_REG_BBREGCTL, &byValue);
if (byValue & BBREGCTL_DONE)
break;
}
if (ww == W_MAX_TIMEOUT) {
DBG_PORT80(0x31);
pr_debug(" DBG_PORT80(0x31)\n");
return false;
}
return true;
}
bool BBbVT3253Init(struct vnt_private *priv)
{
bool bResult = true;
int ii;
void __iomem *dwIoBase = priv->PortOffset;
unsigned char byRFType = priv->byRFType;
unsigned char byLocalID = priv->byLocalID;
if (byRFType == RF_RFMD2959) {
if (byLocalID <= REV_ID_VT3253_A1) {
for (ii = 0; ii < CB_VT3253_INIT_FOR_RFMD; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253InitTab_RFMD[ii][0], byVT3253InitTab_RFMD[ii][1]);
} else {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_RFMD; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_RFMD[ii][0], byVT3253B0_RFMD[ii][1]);
for (ii = 0; ii < CB_VT3253B0_AGC_FOR_RFMD2959; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AGC4_RFMD2959[ii][0], byVT3253B0_AGC4_RFMD2959[ii][1]);
VNSvOutPortD(dwIoBase + MAC_REG_ITRTMSET, 0x23);
MACvRegBitsOn(dwIoBase, MAC_REG_PAPEDELAY, BIT(0));
}
priv->abyBBVGA[0] = 0x18;
priv->abyBBVGA[1] = 0x0A;
priv->abyBBVGA[2] = 0x0;
priv->abyBBVGA[3] = 0x0;
priv->ldBmThreshold[0] = -70;
priv->ldBmThreshold[1] = -50;
priv->ldBmThreshold[2] = 0;
priv->ldBmThreshold[3] = 0;
} else if ((byRFType == RF_AIROHA) || (byRFType == RF_AL2230S)) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_AIROHA2230; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AIROHA2230[ii][0], byVT3253B0_AIROHA2230[ii][1]);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AGC[ii][0], byVT3253B0_AGC[ii][1]);
priv->abyBBVGA[0] = 0x1C;
priv->abyBBVGA[1] = 0x10;
priv->abyBBVGA[2] = 0x0;
priv->abyBBVGA[3] = 0x0;
priv->ldBmThreshold[0] = -70;
priv->ldBmThreshold[1] = -48;
priv->ldBmThreshold[2] = 0;
priv->ldBmThreshold[3] = 0;
} else if (byRFType == RF_UW2451) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_UW2451; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_UW2451[ii][0], byVT3253B0_UW2451[ii][1]);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AGC[ii][0], byVT3253B0_AGC[ii][1]);
VNSvOutPortB(dwIoBase + MAC_REG_ITRTMSET, 0x23);
MACvRegBitsOn(dwIoBase, MAC_REG_PAPEDELAY, BIT(0));
priv->abyBBVGA[0] = 0x14;
priv->abyBBVGA[1] = 0x0A;
priv->abyBBVGA[2] = 0x0;
priv->abyBBVGA[3] = 0x0;
priv->ldBmThreshold[0] = -60;
priv->ldBmThreshold[1] = -50;
priv->ldBmThreshold[2] = 0;
priv->ldBmThreshold[3] = 0;
} else if (byRFType == RF_UW2452) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_UW2451; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_UW2451[ii][0], byVT3253B0_UW2451[ii][1]);
bResult &= BBbWriteEmbedded(priv, 0xd7, 0x06);
bResult &= BBbWriteEmbedded(priv, 0x90, 0x20);
bResult &= BBbWriteEmbedded(priv, 0x97, 0xeb);
bResult &= BBbWriteEmbedded(priv, 0xa6, 0x00);
bResult &= BBbWriteEmbedded(priv, 0xa8, 0x30);
bResult &= BBbWriteEmbedded(priv, 0xb0, 0x58);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AGC[ii][0], byVT3253B0_AGC[ii][1]);
priv->abyBBVGA[0] = 0x14;
priv->abyBBVGA[1] = 0x0A;
priv->abyBBVGA[2] = 0x0;
priv->abyBBVGA[3] = 0x0;
priv->ldBmThreshold[0] = -60;
priv->ldBmThreshold[1] = -50;
priv->ldBmThreshold[2] = 0;
priv->ldBmThreshold[3] = 0;
} else if (byRFType == RF_VT3226) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_AIROHA2230; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AIROHA2230[ii][0], byVT3253B0_AIROHA2230[ii][1]);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AGC[ii][0], byVT3253B0_AGC[ii][1]);
priv->abyBBVGA[0] = 0x1C;
priv->abyBBVGA[1] = 0x10;
priv->abyBBVGA[2] = 0x0;
priv->abyBBVGA[3] = 0x0;
priv->ldBmThreshold[0] = -70;
priv->ldBmThreshold[1] = -48;
priv->ldBmThreshold[2] = 0;
priv->ldBmThreshold[3] = 0;
MACvSetRFLE_LatchBase(dwIoBase);
} else if (byRFType == RF_AIROHA7230) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_AIROHA2230; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AIROHA2230[ii][0], byVT3253B0_AIROHA2230[ii][1]);
bResult &= BBbWriteEmbedded(priv, 0xd7, 0x06);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++)
bResult &= BBbWriteEmbedded(priv, byVT3253B0_AGC[ii][0], byVT3253B0_AGC[ii][1]);
priv->abyBBVGA[0] = 0x1C;
priv->abyBBVGA[1] = 0x10;
priv->abyBBVGA[2] = 0x0;
priv->abyBBVGA[3] = 0x0;
priv->ldBmThreshold[0] = -70;
priv->ldBmThreshold[1] = -48;
priv->ldBmThreshold[2] = 0;
priv->ldBmThreshold[3] = 0;
} else {
priv->bUpdateBBVGA = false;
priv->abyBBVGA[0] = 0x1C;
}
if (byLocalID > REV_ID_VT3253_A1) {
BBbWriteEmbedded(priv, 0x04, 0x7F);
BBbWriteEmbedded(priv, 0x0D, 0x01);
}
return bResult;
}
void
BBvSetShortSlotTime(struct vnt_private *priv)
{
unsigned char byBBRxConf = 0;
unsigned char byBBVGA = 0;
BBbReadEmbedded(priv, 0x0A, &byBBRxConf);
if (priv->bShortSlotTime)
byBBRxConf &= 0xDF;
else
byBBRxConf |= 0x20;
BBbReadEmbedded(priv, 0xE7, &byBBVGA);
if (byBBVGA == priv->abyBBVGA[0])
byBBRxConf |= 0x20;
BBbWriteEmbedded(priv, 0x0A, byBBRxConf);
}
void BBvSetVGAGainOffset(struct vnt_private *priv, unsigned char byData)
{
unsigned char byBBRxConf = 0;
BBbWriteEmbedded(priv, 0xE7, byData);
BBbReadEmbedded(priv, 0x0A, &byBBRxConf);
if (byData == priv->abyBBVGA[0])
byBBRxConf |= 0x20;
else if (priv->bShortSlotTime)
byBBRxConf &= 0xDF;
else
byBBRxConf |= 0x20;
priv->byBBVGACurrent = byData;
BBbWriteEmbedded(priv, 0x0A, byBBRxConf);
}
void
BBvSoftwareReset(struct vnt_private *priv)
{
BBbWriteEmbedded(priv, 0x50, 0x40);
BBbWriteEmbedded(priv, 0x50, 0);
BBbWriteEmbedded(priv, 0x9C, 0x01);
BBbWriteEmbedded(priv, 0x9C, 0);
}
void
BBvPowerSaveModeON(struct vnt_private *priv)
{
unsigned char byOrgData;
BBbReadEmbedded(priv, 0x0D, &byOrgData);
byOrgData |= BIT(0);
BBbWriteEmbedded(priv, 0x0D, byOrgData);
}
void
BBvPowerSaveModeOFF(struct vnt_private *priv)
{
unsigned char byOrgData;
BBbReadEmbedded(priv, 0x0D, &byOrgData);
byOrgData &= ~(BIT(0));
BBbWriteEmbedded(priv, 0x0D, byOrgData);
}
void
BBvSetTxAntennaMode(struct vnt_private *priv, unsigned char byAntennaMode)
{
unsigned char byBBTxConf;
BBbReadEmbedded(priv, 0x09, &byBBTxConf);
if (byAntennaMode == ANT_DIVERSITY) {
byBBTxConf |= 0x02;
} else if (byAntennaMode == ANT_A) {
byBBTxConf &= 0xF9;
} else if (byAntennaMode == ANT_B) {
byBBTxConf &= 0xFD;
byBBTxConf |= 0x04;
}
BBbWriteEmbedded(priv, 0x09, byBBTxConf);
}
void
BBvSetRxAntennaMode(struct vnt_private *priv, unsigned char byAntennaMode)
{
unsigned char byBBRxConf;
BBbReadEmbedded(priv, 0x0A, &byBBRxConf);
if (byAntennaMode == ANT_DIVERSITY) {
byBBRxConf |= 0x01;
} else if (byAntennaMode == ANT_A) {
byBBRxConf &= 0xFC;
} else if (byAntennaMode == ANT_B) {
byBBRxConf &= 0xFE;
byBBRxConf |= 0x02;
}
BBbWriteEmbedded(priv, 0x0A, byBBRxConf);
}
void
BBvSetDeepSleep(struct vnt_private *priv, unsigned char byLocalID)
{
BBbWriteEmbedded(priv, 0x0C, 0x17);
BBbWriteEmbedded(priv, 0x0D, 0xB9);
}
void
BBvExitDeepSleep(struct vnt_private *priv, unsigned char byLocalID)
{
BBbWriteEmbedded(priv, 0x0C, 0x00);
BBbWriteEmbedded(priv, 0x0D, 0x01);
}
static
unsigned long
s_ulGetRatio(struct vnt_private *priv)
{
unsigned long ulRatio = 0;
unsigned long ulMaxPacket;
unsigned long ulPacketNum;
ulMaxPacket = priv->uNumSQ3[RATE_54M];
if (priv->uNumSQ3[RATE_54M] != 0) {
ulPacketNum = priv->uNumSQ3[RATE_54M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_54M;
}
if (priv->uNumSQ3[RATE_48M] > ulMaxPacket) {
ulPacketNum = priv->uNumSQ3[RATE_54M] + priv->uNumSQ3[RATE_48M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_48M;
ulMaxPacket = priv->uNumSQ3[RATE_48M];
}
if (priv->uNumSQ3[RATE_36M] > ulMaxPacket) {
ulPacketNum = priv->uNumSQ3[RATE_54M] + priv->uNumSQ3[RATE_48M] +
priv->uNumSQ3[RATE_36M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_36M;
ulMaxPacket = priv->uNumSQ3[RATE_36M];
}
if (priv->uNumSQ3[RATE_24M] > ulMaxPacket) {
ulPacketNum = priv->uNumSQ3[RATE_54M] + priv->uNumSQ3[RATE_48M] +
priv->uNumSQ3[RATE_36M] + priv->uNumSQ3[RATE_24M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_24M;
ulMaxPacket = priv->uNumSQ3[RATE_24M];
}
if (priv->uNumSQ3[RATE_18M] > ulMaxPacket) {
ulPacketNum = priv->uNumSQ3[RATE_54M] + priv->uNumSQ3[RATE_48M] +
priv->uNumSQ3[RATE_36M] + priv->uNumSQ3[RATE_24M] +
priv->uNumSQ3[RATE_18M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_18M;
ulMaxPacket = priv->uNumSQ3[RATE_18M];
}
if (priv->uNumSQ3[RATE_12M] > ulMaxPacket) {
ulPacketNum = priv->uNumSQ3[RATE_54M] + priv->uNumSQ3[RATE_48M] +
priv->uNumSQ3[RATE_36M] + priv->uNumSQ3[RATE_24M] +
priv->uNumSQ3[RATE_18M] + priv->uNumSQ3[RATE_12M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_12M;
ulMaxPacket = priv->uNumSQ3[RATE_12M];
}
if (priv->uNumSQ3[RATE_11M] > ulMaxPacket) {
ulPacketNum = priv->uDiversityCnt - priv->uNumSQ3[RATE_1M] -
priv->uNumSQ3[RATE_2M] - priv->uNumSQ3[RATE_5M] -
priv->uNumSQ3[RATE_6M] - priv->uNumSQ3[RATE_9M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_11M;
ulMaxPacket = priv->uNumSQ3[RATE_11M];
}
if (priv->uNumSQ3[RATE_9M] > ulMaxPacket) {
ulPacketNum = priv->uDiversityCnt - priv->uNumSQ3[RATE_1M] -
priv->uNumSQ3[RATE_2M] - priv->uNumSQ3[RATE_5M] -
priv->uNumSQ3[RATE_6M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_9M;
ulMaxPacket = priv->uNumSQ3[RATE_9M];
}
if (priv->uNumSQ3[RATE_6M] > ulMaxPacket) {
ulPacketNum = priv->uDiversityCnt - priv->uNumSQ3[RATE_1M] -
priv->uNumSQ3[RATE_2M] - priv->uNumSQ3[RATE_5M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_6M;
ulMaxPacket = priv->uNumSQ3[RATE_6M];
}
if (priv->uNumSQ3[RATE_5M] > ulMaxPacket) {
ulPacketNum = priv->uDiversityCnt - priv->uNumSQ3[RATE_1M] -
priv->uNumSQ3[RATE_2M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_55M;
ulMaxPacket = priv->uNumSQ3[RATE_5M];
}
if (priv->uNumSQ3[RATE_2M] > ulMaxPacket) {
ulPacketNum = priv->uDiversityCnt - priv->uNumSQ3[RATE_1M];
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_2M;
ulMaxPacket = priv->uNumSQ3[RATE_2M];
}
if (priv->uNumSQ3[RATE_1M] > ulMaxPacket) {
ulPacketNum = priv->uDiversityCnt;
ulRatio = (ulPacketNum * 1000 / priv->uDiversityCnt);
ulRatio += TOP_RATE_1M;
}
return ulRatio;
}
void
BBvClearAntDivSQ3Value(struct vnt_private *priv)
{
unsigned int ii;
priv->uDiversityCnt = 0;
for (ii = 0; ii < MAX_RATE; ii++)
priv->uNumSQ3[ii] = 0;
}
void BBvAntennaDiversity(struct vnt_private *priv,
unsigned char byRxRate, unsigned char bySQ3)
{
if ((byRxRate >= MAX_RATE) || (priv->wAntDiversityMaxRate >= MAX_RATE))
return;
priv->uDiversityCnt++;
priv->uNumSQ3[byRxRate]++;
if (priv->byAntennaState == 0) {
if (priv->uDiversityCnt > priv->ulDiversityNValue) {
pr_debug("ulDiversityNValue=[%d],54M-[%d]\n",
(int)priv->ulDiversityNValue,
(int)priv->uNumSQ3[(int)priv->wAntDiversityMaxRate]);
if (priv->uNumSQ3[priv->wAntDiversityMaxRate] < priv->uDiversityCnt/2) {
priv->ulRatio_State0 = s_ulGetRatio(priv);
pr_debug("SQ3_State0, rate = [%08x]\n",
(int)priv->ulRatio_State0);
if (priv->byTMax == 0)
return;
pr_debug("1.[%08x], uNumSQ3[%d]=%d, %d\n",
(int)priv->ulRatio_State0,
(int)priv->wAntDiversityMaxRate,
(int)priv->uNumSQ3[(int)priv->wAntDiversityMaxRate],
(int)priv->uDiversityCnt);
s_vChangeAntenna(priv);
priv->byAntennaState = 1;
del_timer(&priv->TimerSQ3Tmax3);
del_timer(&priv->TimerSQ3Tmax2);
priv->TimerSQ3Tmax1.expires = RUN_AT(priv->byTMax * HZ);
add_timer(&priv->TimerSQ3Tmax1);
} else {
priv->TimerSQ3Tmax3.expires = RUN_AT(priv->byTMax3 * HZ);
add_timer(&priv->TimerSQ3Tmax3);
}
BBvClearAntDivSQ3Value(priv);
}
} else {
if (priv->uDiversityCnt > priv->ulDiversityMValue) {
del_timer(&priv->TimerSQ3Tmax1);
priv->ulRatio_State1 = s_ulGetRatio(priv);
pr_debug("RX:SQ3_State1, rate0 = %08x,rate1 = %08x\n",
(int)priv->ulRatio_State0,
(int)priv->ulRatio_State1);
if (priv->ulRatio_State1 < priv->ulRatio_State0) {
pr_debug("2.[%08x][%08x], uNumSQ3[%d]=%d, %d\n",
(int)priv->ulRatio_State0,
(int)priv->ulRatio_State1,
(int)priv->wAntDiversityMaxRate,
(int)priv->uNumSQ3[(int)priv->wAntDiversityMaxRate],
(int)priv->uDiversityCnt);
s_vChangeAntenna(priv);
priv->TimerSQ3Tmax3.expires = RUN_AT(priv->byTMax3 * HZ);
priv->TimerSQ3Tmax2.expires = RUN_AT(priv->byTMax2 * HZ);
add_timer(&priv->TimerSQ3Tmax3);
add_timer(&priv->TimerSQ3Tmax2);
}
priv->byAntennaState = 0;
BBvClearAntDivSQ3Value(priv);
}
}
}
void
TimerSQ3CallBack(
unsigned long data
)
{
struct vnt_private *priv = (struct vnt_private *)data;
unsigned long flags;
pr_debug("TimerSQ3CallBack...\n");
spin_lock_irqsave(&priv->lock, flags);
pr_debug("3.[%08x][%08x], %d\n",
(int)priv->ulRatio_State0, (int)priv->ulRatio_State1,
(int)priv->uDiversityCnt);
s_vChangeAntenna(priv);
priv->byAntennaState = 0;
BBvClearAntDivSQ3Value(priv);
priv->TimerSQ3Tmax3.expires = RUN_AT(priv->byTMax3 * HZ);
priv->TimerSQ3Tmax2.expires = RUN_AT(priv->byTMax2 * HZ);
add_timer(&priv->TimerSQ3Tmax3);
add_timer(&priv->TimerSQ3Tmax2);
spin_unlock_irqrestore(&priv->lock, flags);
}
void
TimerState1CallBack(
unsigned long data
)
{
struct vnt_private *priv = (struct vnt_private *)data;
unsigned long flags;
pr_debug("TimerState1CallBack...\n");
spin_lock_irqsave(&priv->lock, flags);
if (priv->uDiversityCnt < priv->ulDiversityMValue/100) {
s_vChangeAntenna(priv);
priv->TimerSQ3Tmax3.expires = RUN_AT(priv->byTMax3 * HZ);
priv->TimerSQ3Tmax2.expires = RUN_AT(priv->byTMax2 * HZ);
add_timer(&priv->TimerSQ3Tmax3);
add_timer(&priv->TimerSQ3Tmax2);
} else {
priv->ulRatio_State1 = s_ulGetRatio(priv);
pr_debug("SQ3_State1, rate0 = %08x,rate1 = %08x\n",
(int)priv->ulRatio_State0,
(int)priv->ulRatio_State1);
if (priv->ulRatio_State1 < priv->ulRatio_State0) {
pr_debug("2.[%08x][%08x], uNumSQ3[%d]=%d, %d\n",
(int)priv->ulRatio_State0,
(int)priv->ulRatio_State1,
(int)priv->wAntDiversityMaxRate,
(int)priv->uNumSQ3[(int)priv->wAntDiversityMaxRate],
(int)priv->uDiversityCnt);
s_vChangeAntenna(priv);
priv->TimerSQ3Tmax3.expires = RUN_AT(priv->byTMax3 * HZ);
priv->TimerSQ3Tmax2.expires = RUN_AT(priv->byTMax2 * HZ);
add_timer(&priv->TimerSQ3Tmax3);
add_timer(&priv->TimerSQ3Tmax2);
}
}
priv->byAntennaState = 0;
BBvClearAntDivSQ3Value(priv);
spin_unlock_irqrestore(&priv->lock, flags);
}
