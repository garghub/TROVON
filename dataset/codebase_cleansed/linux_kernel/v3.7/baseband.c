static
void
s_vChangeAntenna (
PSDevice pDevice
)
{
#ifdef PLICE_DEBUG
#endif
if ( pDevice->dwRxAntennaSel == 0) {
pDevice->dwRxAntennaSel=1;
if (pDevice->bTxRxAntInv == true)
BBvSetRxAntennaMode(pDevice->PortOffset, ANT_A);
else
BBvSetRxAntennaMode(pDevice->PortOffset, ANT_B);
} else {
pDevice->dwRxAntennaSel=0;
if (pDevice->bTxRxAntInv == true)
BBvSetRxAntennaMode(pDevice->PortOffset, ANT_B);
else
BBvSetRxAntennaMode(pDevice->PortOffset, ANT_A);
}
if ( pDevice->dwTxAntennaSel == 0) {
pDevice->dwTxAntennaSel=1;
BBvSetTxAntennaMode(pDevice->PortOffset, ANT_B);
} else {
pDevice->dwTxAntennaSel=0;
BBvSetTxAntennaMode(pDevice->PortOffset, ANT_A);
}
}
unsigned int
BBuGetFrameTime (
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
uRate = (unsigned int) awcFrameTime[uRateIdx];
if (uRateIdx <= 3) {
if (byPreambleType == 1) {
uPreamble = 96;
} else {
uPreamble = 192;
}
uFrameTime = (cbFrameLength * 80) / uRate;
uTmp = (uFrameTime * uRate) / 80;
if (cbFrameLength != uTmp) {
uFrameTime ++;
}
return (uPreamble + uFrameTime);
}
else {
uFrameTime = (cbFrameLength * 8 + 22) / uRate;
uTmp = ((uFrameTime * uRate) - 22) / 8;
if(cbFrameLength != uTmp) {
uFrameTime ++;
}
uFrameTime = uFrameTime * 4;
if(byPktType != PK_TYPE_11A) {
uFrameTime += 6;
}
return (20 + uFrameTime);
}
}
void
BBvCalculateParameter (
PSDevice pDevice,
unsigned int cbFrameLength,
unsigned short wRate,
unsigned char byPacketType,
unsigned short *pwPhyLen,
unsigned char *pbyPhySrv,
unsigned char *pbyPhySgn
)
{
unsigned int cbBitCount;
unsigned int cbUsCount = 0;
unsigned int cbTmp;
bool bExtBit;
unsigned char byPreambleType = pDevice->byPreambleType;
bool bCCK = pDevice->bCCK;
cbBitCount = cbFrameLength * 8;
bExtBit = false;
switch (wRate) {
case RATE_1M :
cbUsCount = cbBitCount;
*pbyPhySgn = 0x00;
break;
case RATE_2M :
cbUsCount = cbBitCount / 2;
if (byPreambleType == 1)
*pbyPhySgn = 0x09;
else
*pbyPhySgn = 0x01;
break;
case RATE_5M :
if (bCCK == false)
cbBitCount ++;
cbUsCount = (cbBitCount * 10) / 55;
cbTmp = (cbUsCount * 55) / 10;
if (cbTmp != cbBitCount)
cbUsCount ++;
if (byPreambleType == 1)
*pbyPhySgn = 0x0a;
else
*pbyPhySgn = 0x02;
break;
case RATE_11M :
if (bCCK == false)
cbBitCount ++;
cbUsCount = cbBitCount / 11;
cbTmp = cbUsCount * 11;
if (cbTmp != cbBitCount) {
cbUsCount ++;
if ((cbBitCount - cbTmp) <= 3)
bExtBit = true;
}
if (byPreambleType == 1)
*pbyPhySgn = 0x0b;
else
*pbyPhySgn = 0x03;
break;
case RATE_6M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9B;
}
else {
*pbyPhySgn = 0x8B;
}
break;
case RATE_9M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9F;
}
else {
*pbyPhySgn = 0x8F;
}
break;
case RATE_12M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9A;
}
else {
*pbyPhySgn = 0x8A;
}
break;
case RATE_18M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9E;
}
else {
*pbyPhySgn = 0x8E;
}
break;
case RATE_24M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x99;
}
else {
*pbyPhySgn = 0x89;
}
break;
case RATE_36M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9D;
}
else {
*pbyPhySgn = 0x8D;
}
break;
case RATE_48M :
if(byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x98;
}
else {
*pbyPhySgn = 0x88;
}
break;
case RATE_54M :
if (byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9C;
}
else {
*pbyPhySgn = 0x8C;
}
break;
default :
if (byPacketType == PK_TYPE_11A) {
*pbyPhySgn = 0x9C;
}
else {
*pbyPhySgn = 0x8C;
}
break;
}
if (byPacketType == PK_TYPE_11B) {
*pbyPhySrv = 0x00;
if (bExtBit)
*pbyPhySrv = *pbyPhySrv | 0x80;
*pwPhyLen = (unsigned short)cbUsCount;
}
else {
*pbyPhySrv = 0x00;
*pwPhyLen = (unsigned short)cbFrameLength;
}
}
bool BBbReadEmbedded (unsigned long dwIoBase, unsigned char byBBAddr, unsigned char *pbyData)
{
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
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO" DBG_PORT80(0x30)\n");
return false;
}
return true;
}
bool BBbWriteEmbedded (unsigned long dwIoBase, unsigned char byBBAddr, unsigned char byData)
{
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
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO" DBG_PORT80(0x31)\n");
return false;
}
return true;
}
bool BBbIsRegBitsOn (unsigned long dwIoBase, unsigned char byBBAddr, unsigned char byTestBits)
{
unsigned char byOrgData;
BBbReadEmbedded(dwIoBase, byBBAddr, &byOrgData);
return (byOrgData & byTestBits) == byTestBits;
}
bool BBbIsRegBitsOff (unsigned long dwIoBase, unsigned char byBBAddr, unsigned char byTestBits)
{
unsigned char byOrgData;
BBbReadEmbedded(dwIoBase, byBBAddr, &byOrgData);
return (byOrgData & byTestBits) == 0;
}
bool BBbVT3253Init (PSDevice pDevice)
{
bool bResult = true;
int ii;
unsigned long dwIoBase = pDevice->PortOffset;
unsigned char byRFType = pDevice->byRFType;
unsigned char byLocalID = pDevice->byLocalID;
if (byRFType == RF_RFMD2959) {
if (byLocalID <= REV_ID_VT3253_A1) {
for (ii = 0; ii < CB_VT3253_INIT_FOR_RFMD; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253InitTab_RFMD[ii][0],byVT3253InitTab_RFMD[ii][1]);
}
} else {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_RFMD; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_RFMD[ii][0],byVT3253B0_RFMD[ii][1]);
}
for (ii = 0; ii < CB_VT3253B0_AGC_FOR_RFMD2959; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AGC4_RFMD2959[ii][0],byVT3253B0_AGC4_RFMD2959[ii][1]);
}
VNSvOutPortD(dwIoBase + MAC_REG_ITRTMSET, 0x23);
MACvRegBitsOn(dwIoBase, MAC_REG_PAPEDELAY, BIT0);
}
pDevice->abyBBVGA[0] = 0x18;
pDevice->abyBBVGA[1] = 0x0A;
pDevice->abyBBVGA[2] = 0x0;
pDevice->abyBBVGA[3] = 0x0;
pDevice->ldBmThreshold[0] = -70;
pDevice->ldBmThreshold[1] = -50;
pDevice->ldBmThreshold[2] = 0;
pDevice->ldBmThreshold[3] = 0;
} else if ((byRFType == RF_AIROHA) || (byRFType == RF_AL2230S) ) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_AIROHA2230; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AIROHA2230[ii][0],byVT3253B0_AIROHA2230[ii][1]);
}
for (ii = 0; ii < CB_VT3253B0_AGC; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AGC[ii][0],byVT3253B0_AGC[ii][1]);
}
pDevice->abyBBVGA[0] = 0x1C;
pDevice->abyBBVGA[1] = 0x10;
pDevice->abyBBVGA[2] = 0x0;
pDevice->abyBBVGA[3] = 0x0;
pDevice->ldBmThreshold[0] = -70;
pDevice->ldBmThreshold[1] = -48;
pDevice->ldBmThreshold[2] = 0;
pDevice->ldBmThreshold[3] = 0;
} else if (byRFType == RF_UW2451) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_UW2451; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_UW2451[ii][0],byVT3253B0_UW2451[ii][1]);
}
for (ii = 0; ii < CB_VT3253B0_AGC; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AGC[ii][0],byVT3253B0_AGC[ii][1]);
}
VNSvOutPortB(dwIoBase + MAC_REG_ITRTMSET, 0x23);
MACvRegBitsOn(dwIoBase, MAC_REG_PAPEDELAY, BIT0);
pDevice->abyBBVGA[0] = 0x14;
pDevice->abyBBVGA[1] = 0x0A;
pDevice->abyBBVGA[2] = 0x0;
pDevice->abyBBVGA[3] = 0x0;
pDevice->ldBmThreshold[0] = -60;
pDevice->ldBmThreshold[1] = -50;
pDevice->ldBmThreshold[2] = 0;
pDevice->ldBmThreshold[3] = 0;
} else if (byRFType == RF_UW2452) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_UW2451; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_UW2451[ii][0],byVT3253B0_UW2451[ii][1]);
}
bResult &= BBbWriteEmbedded(dwIoBase,0xd7,0x06);
bResult &= BBbWriteEmbedded(dwIoBase,0x90,0x20);
bResult &= BBbWriteEmbedded(dwIoBase,0x97,0xeb);
bResult &= BBbWriteEmbedded(dwIoBase,0xa6,0x00);
bResult &= BBbWriteEmbedded(dwIoBase,0xa8,0x30);
bResult &= BBbWriteEmbedded(dwIoBase,0xb0,0x58);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AGC[ii][0],byVT3253B0_AGC[ii][1]);
}
pDevice->abyBBVGA[0] = 0x14;
pDevice->abyBBVGA[1] = 0x0A;
pDevice->abyBBVGA[2] = 0x0;
pDevice->abyBBVGA[3] = 0x0;
pDevice->ldBmThreshold[0] = -60;
pDevice->ldBmThreshold[1] = -50;
pDevice->ldBmThreshold[2] = 0;
pDevice->ldBmThreshold[3] = 0;
} else if (byRFType == RF_VT3226) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_AIROHA2230; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AIROHA2230[ii][0],byVT3253B0_AIROHA2230[ii][1]);
}
for (ii = 0; ii < CB_VT3253B0_AGC; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AGC[ii][0],byVT3253B0_AGC[ii][1]);
}
pDevice->abyBBVGA[0] = 0x1C;
pDevice->abyBBVGA[1] = 0x10;
pDevice->abyBBVGA[2] = 0x0;
pDevice->abyBBVGA[3] = 0x0;
pDevice->ldBmThreshold[0] = -70;
pDevice->ldBmThreshold[1] = -48;
pDevice->ldBmThreshold[2] = 0;
pDevice->ldBmThreshold[3] = 0;
MACvSetRFLE_LatchBase(dwIoBase);
} else if (byRFType == RF_AIROHA7230) {
for (ii = 0; ii < CB_VT3253B0_INIT_FOR_AIROHA2230; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AIROHA2230[ii][0],byVT3253B0_AIROHA2230[ii][1]);
}
bResult &= BBbWriteEmbedded(dwIoBase,0xd7,0x06);
for (ii = 0; ii < CB_VT3253B0_AGC; ii++) {
bResult &= BBbWriteEmbedded(dwIoBase,byVT3253B0_AGC[ii][0],byVT3253B0_AGC[ii][1]);
}
pDevice->abyBBVGA[0] = 0x1C;
pDevice->abyBBVGA[1] = 0x10;
pDevice->abyBBVGA[2] = 0x0;
pDevice->abyBBVGA[3] = 0x0;
pDevice->ldBmThreshold[0] = -70;
pDevice->ldBmThreshold[1] = -48;
pDevice->ldBmThreshold[2] = 0;
pDevice->ldBmThreshold[3] = 0;
} else {
pDevice->bUpdateBBVGA = false;
pDevice->abyBBVGA[0] = 0x1C;
}
if (byLocalID > REV_ID_VT3253_A1) {
BBbWriteEmbedded(dwIoBase, 0x04, 0x7F);
BBbWriteEmbedded(dwIoBase, 0x0D, 0x01);
}
return bResult;
}
void BBvReadAllRegs (unsigned long dwIoBase, unsigned char *pbyBBRegs)
{
int ii;
unsigned char byBase = 1;
for (ii = 0; ii < BB_MAX_CONTEXT_SIZE; ii++) {
BBbReadEmbedded(dwIoBase, (unsigned char)(ii*byBase), pbyBBRegs);
pbyBBRegs += byBase;
}
}
void BBvLoopbackOn (PSDevice pDevice)
{
unsigned char byData;
unsigned long dwIoBase = pDevice->PortOffset;
BBbReadEmbedded(dwIoBase, 0xC9, &pDevice->byBBCRc9);
BBbWriteEmbedded(dwIoBase, 0xC9, 0);
BBbReadEmbedded(dwIoBase, 0x4D, &pDevice->byBBCR4d);
BBbWriteEmbedded(dwIoBase, 0x4D, 0x90);
BBbReadEmbedded(dwIoBase, 0x88, &pDevice->byBBCR88);
if (pDevice->uConnectionRate <= RATE_11M) {
BBbReadEmbedded(dwIoBase, 0x21, &byData);
BBbWriteEmbedded(dwIoBase, 0x21, (unsigned char)(byData | 0x01));
BBbWriteEmbedded(dwIoBase, 0x9A, 0);
BBbWriteEmbedded(dwIoBase, 0x88, 0x02);
}
else {
BBbReadEmbedded(dwIoBase, 0x9A, &byData);
BBbWriteEmbedded(dwIoBase, 0x9A, (unsigned char)(byData | 0x01));
BBbWriteEmbedded(dwIoBase, 0x21, 0);
BBbWriteEmbedded(dwIoBase, 0x88, 0x03);
}
BBbWriteEmbedded(dwIoBase, 0x0E, 0);
BBbReadEmbedded(pDevice->PortOffset, 0x09, &pDevice->byBBCR09);
BBbWriteEmbedded(pDevice->PortOffset, 0x09, (unsigned char)(pDevice->byBBCR09 & 0xDE));
}
void BBvLoopbackOff (PSDevice pDevice)
{
unsigned char byData;
unsigned long dwIoBase = pDevice->PortOffset;
BBbWriteEmbedded(dwIoBase, 0xC9, pDevice->byBBCRc9);
BBbWriteEmbedded(dwIoBase, 0x88, pDevice->byBBCR88);
BBbWriteEmbedded(dwIoBase, 0x09, pDevice->byBBCR09);
BBbWriteEmbedded(dwIoBase, 0x4D, pDevice->byBBCR4d);
if (pDevice->uConnectionRate <= RATE_11M) {
BBbReadEmbedded(dwIoBase, 0x21, &byData);
BBbWriteEmbedded(dwIoBase, 0x21, (unsigned char)(byData & 0xFE));
}
else {
BBbReadEmbedded(dwIoBase, 0x9A, &byData);
BBbWriteEmbedded(dwIoBase, 0x9A, (unsigned char)(byData & 0xFE));
}
BBbReadEmbedded(dwIoBase, 0x0E, &byData);
BBbWriteEmbedded(dwIoBase, 0x0E, (unsigned char)(byData | 0x80));
}
void
BBvSetShortSlotTime (PSDevice pDevice)
{
unsigned char byBBRxConf=0;
unsigned char byBBVGA=0;
BBbReadEmbedded(pDevice->PortOffset, 0x0A, &byBBRxConf);
if (pDevice->bShortSlotTime) {
byBBRxConf &= 0xDF;
} else {
byBBRxConf |= 0x20;
}
BBbReadEmbedded(pDevice->PortOffset, 0xE7, &byBBVGA);
if (byBBVGA == pDevice->abyBBVGA[0]) {
byBBRxConf |= 0x20;
}
BBbWriteEmbedded(pDevice->PortOffset, 0x0A, byBBRxConf);
}
void BBvSetVGAGainOffset(PSDevice pDevice, unsigned char byData)
{
unsigned char byBBRxConf=0;
BBbWriteEmbedded(pDevice->PortOffset, 0xE7, byData);
BBbReadEmbedded(pDevice->PortOffset, 0x0A, &byBBRxConf);
if (byData == pDevice->abyBBVGA[0]) {
byBBRxConf |= 0x20;
} else if (pDevice->bShortSlotTime) {
byBBRxConf &= 0xDF;
} else {
byBBRxConf |= 0x20;
}
pDevice->byBBVGACurrent = byData;
BBbWriteEmbedded(pDevice->PortOffset, 0x0A, byBBRxConf);
}
void
BBvSoftwareReset (unsigned long dwIoBase)
{
BBbWriteEmbedded(dwIoBase, 0x50, 0x40);
BBbWriteEmbedded(dwIoBase, 0x50, 0);
BBbWriteEmbedded(dwIoBase, 0x9C, 0x01);
BBbWriteEmbedded(dwIoBase, 0x9C, 0);
}
void
BBvPowerSaveModeON (unsigned long dwIoBase)
{
unsigned char byOrgData;
BBbReadEmbedded(dwIoBase, 0x0D, &byOrgData);
byOrgData |= BIT0;
BBbWriteEmbedded(dwIoBase, 0x0D, byOrgData);
}
void
BBvPowerSaveModeOFF (unsigned long dwIoBase)
{
unsigned char byOrgData;
BBbReadEmbedded(dwIoBase, 0x0D, &byOrgData);
byOrgData &= ~(BIT0);
BBbWriteEmbedded(dwIoBase, 0x0D, byOrgData);
}
void
BBvSetTxAntennaMode (unsigned long dwIoBase, unsigned char byAntennaMode)
{
unsigned char byBBTxConf;
#ifdef PLICE_DEBUG
#endif
BBbReadEmbedded(dwIoBase, 0x09, &byBBTxConf);
if (byAntennaMode == ANT_DIVERSITY) {
byBBTxConf |= 0x02;
} else if (byAntennaMode == ANT_A) {
byBBTxConf &= 0xF9;
} else if (byAntennaMode == ANT_B) {
#ifdef PLICE_DEBUG
#endif
byBBTxConf &= 0xFD;
byBBTxConf |= 0x04;
}
BBbWriteEmbedded(dwIoBase, 0x09, byBBTxConf);
}
void
BBvSetRxAntennaMode (unsigned long dwIoBase, unsigned char byAntennaMode)
{
unsigned char byBBRxConf;
BBbReadEmbedded(dwIoBase, 0x0A, &byBBRxConf);
if (byAntennaMode == ANT_DIVERSITY) {
byBBRxConf |= 0x01;
} else if (byAntennaMode == ANT_A) {
byBBRxConf &= 0xFC;
} else if (byAntennaMode == ANT_B) {
byBBRxConf &= 0xFE;
byBBRxConf |= 0x02;
}
BBbWriteEmbedded(dwIoBase, 0x0A, byBBRxConf);
}
void
BBvSetDeepSleep (unsigned long dwIoBase, unsigned char byLocalID)
{
BBbWriteEmbedded(dwIoBase, 0x0C, 0x17);
BBbWriteEmbedded(dwIoBase, 0x0D, 0xB9);
}
void
BBvExitDeepSleep (unsigned long dwIoBase, unsigned char byLocalID)
{
BBbWriteEmbedded(dwIoBase, 0x0C, 0x00);
BBbWriteEmbedded(dwIoBase, 0x0D, 0x01);
}
static
unsigned long
s_ulGetRatio (PSDevice pDevice)
{
unsigned long ulRatio = 0;
unsigned long ulMaxPacket;
unsigned long ulPacketNum;
ulMaxPacket = pDevice->uNumSQ3[RATE_54M];
if ( pDevice->uNumSQ3[RATE_54M] != 0 ) {
ulPacketNum = pDevice->uNumSQ3[RATE_54M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_54M;
}
if ( pDevice->uNumSQ3[RATE_48M] > ulMaxPacket ) {
ulPacketNum = pDevice->uNumSQ3[RATE_54M] + pDevice->uNumSQ3[RATE_48M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_48M;
ulMaxPacket = pDevice->uNumSQ3[RATE_48M];
}
if ( pDevice->uNumSQ3[RATE_36M] > ulMaxPacket ) {
ulPacketNum = pDevice->uNumSQ3[RATE_54M] + pDevice->uNumSQ3[RATE_48M] +
pDevice->uNumSQ3[RATE_36M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_36M;
ulMaxPacket = pDevice->uNumSQ3[RATE_36M];
}
if ( pDevice->uNumSQ3[RATE_24M] > ulMaxPacket ) {
ulPacketNum = pDevice->uNumSQ3[RATE_54M] + pDevice->uNumSQ3[RATE_48M] +
pDevice->uNumSQ3[RATE_36M] + pDevice->uNumSQ3[RATE_24M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_24M;
ulMaxPacket = pDevice->uNumSQ3[RATE_24M];
}
if ( pDevice->uNumSQ3[RATE_18M] > ulMaxPacket ) {
ulPacketNum = pDevice->uNumSQ3[RATE_54M] + pDevice->uNumSQ3[RATE_48M] +
pDevice->uNumSQ3[RATE_36M] + pDevice->uNumSQ3[RATE_24M] +
pDevice->uNumSQ3[RATE_18M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_18M;
ulMaxPacket = pDevice->uNumSQ3[RATE_18M];
}
if ( pDevice->uNumSQ3[RATE_12M] > ulMaxPacket ) {
ulPacketNum = pDevice->uNumSQ3[RATE_54M] + pDevice->uNumSQ3[RATE_48M] +
pDevice->uNumSQ3[RATE_36M] + pDevice->uNumSQ3[RATE_24M] +
pDevice->uNumSQ3[RATE_18M] + pDevice->uNumSQ3[RATE_12M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_12M;
ulMaxPacket = pDevice->uNumSQ3[RATE_12M];
}
if ( pDevice->uNumSQ3[RATE_11M] > ulMaxPacket ) {
ulPacketNum = pDevice->uDiversityCnt - pDevice->uNumSQ3[RATE_1M] -
pDevice->uNumSQ3[RATE_2M] - pDevice->uNumSQ3[RATE_5M] -
pDevice->uNumSQ3[RATE_6M] - pDevice->uNumSQ3[RATE_9M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_11M;
ulMaxPacket = pDevice->uNumSQ3[RATE_11M];
}
if ( pDevice->uNumSQ3[RATE_9M] > ulMaxPacket ) {
ulPacketNum = pDevice->uDiversityCnt - pDevice->uNumSQ3[RATE_1M] -
pDevice->uNumSQ3[RATE_2M] - pDevice->uNumSQ3[RATE_5M] -
pDevice->uNumSQ3[RATE_6M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_9M;
ulMaxPacket = pDevice->uNumSQ3[RATE_9M];
}
if ( pDevice->uNumSQ3[RATE_6M] > ulMaxPacket ) {
ulPacketNum = pDevice->uDiversityCnt - pDevice->uNumSQ3[RATE_1M] -
pDevice->uNumSQ3[RATE_2M] - pDevice->uNumSQ3[RATE_5M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_6M;
ulMaxPacket = pDevice->uNumSQ3[RATE_6M];
}
if ( pDevice->uNumSQ3[RATE_5M] > ulMaxPacket ) {
ulPacketNum = pDevice->uDiversityCnt - pDevice->uNumSQ3[RATE_1M] -
pDevice->uNumSQ3[RATE_2M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_55M;
ulMaxPacket = pDevice->uNumSQ3[RATE_5M];
}
if ( pDevice->uNumSQ3[RATE_2M] > ulMaxPacket ) {
ulPacketNum = pDevice->uDiversityCnt - pDevice->uNumSQ3[RATE_1M];
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_2M;
ulMaxPacket = pDevice->uNumSQ3[RATE_2M];
}
if ( pDevice->uNumSQ3[RATE_1M] > ulMaxPacket ) {
ulPacketNum = pDevice->uDiversityCnt;
ulRatio = (ulPacketNum * 1000 / pDevice->uDiversityCnt);
ulRatio += TOP_RATE_1M;
}
return ulRatio;
}
void
BBvClearAntDivSQ3Value (PSDevice pDevice)
{
unsigned int ii;
pDevice->uDiversityCnt = 0;
for (ii = 0; ii < MAX_RATE; ii++) {
pDevice->uNumSQ3[ii] = 0;
}
}
void
BBvAntennaDiversity (PSDevice pDevice, unsigned char byRxRate, unsigned char bySQ3)
{
if ((byRxRate >= MAX_RATE) || (pDevice->wAntDiversityMaxRate >= MAX_RATE)) {
return;
}
pDevice->uDiversityCnt++;
pDevice->uNumSQ3[byRxRate]++;
if (pDevice->byAntennaState == 0) {
if (pDevice->uDiversityCnt > pDevice->ulDiversityNValue) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ulDiversityNValue=[%d],54M-[%d]\n",
(int)pDevice->ulDiversityNValue, (int)pDevice->uNumSQ3[(int)pDevice->wAntDiversityMaxRate]);
if (pDevice->uNumSQ3[pDevice->wAntDiversityMaxRate] < pDevice->uDiversityCnt/2) {
pDevice->ulRatio_State0 = s_ulGetRatio(pDevice);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"SQ3_State0, rate = [%08x]\n", (int)pDevice->ulRatio_State0);
if ( pDevice->byTMax == 0 )
return;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"1.[%08x], uNumSQ3[%d]=%d, %d\n",
(int)pDevice->ulRatio_State0, (int)pDevice->wAntDiversityMaxRate,
(int)pDevice->uNumSQ3[(int)pDevice->wAntDiversityMaxRate], (int)pDevice->uDiversityCnt);
#ifdef PLICE_DEBUG
#endif
s_vChangeAntenna(pDevice);
pDevice->byAntennaState = 1;
del_timer(&pDevice->TimerSQ3Tmax3);
del_timer(&pDevice->TimerSQ3Tmax2);
pDevice->TimerSQ3Tmax1.expires = RUN_AT(pDevice->byTMax * HZ);
add_timer(&pDevice->TimerSQ3Tmax1);
} else {
pDevice->TimerSQ3Tmax3.expires = RUN_AT(pDevice->byTMax3 * HZ);
add_timer(&pDevice->TimerSQ3Tmax3);
}
BBvClearAntDivSQ3Value(pDevice);
}
} else {
if (pDevice->uDiversityCnt > pDevice->ulDiversityMValue) {
del_timer(&pDevice->TimerSQ3Tmax1);
pDevice->ulRatio_State1 = s_ulGetRatio(pDevice);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"RX:SQ3_State1, rate0 = %08x,rate1 = %08x\n",
(int)pDevice->ulRatio_State0,(int)pDevice->ulRatio_State1);
if (pDevice->ulRatio_State1 < pDevice->ulRatio_State0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"2.[%08x][%08x], uNumSQ3[%d]=%d, %d\n",
(int)pDevice->ulRatio_State0, (int)pDevice->ulRatio_State1,
(int)pDevice->wAntDiversityMaxRate,
(int)pDevice->uNumSQ3[(int)pDevice->wAntDiversityMaxRate], (int)pDevice->uDiversityCnt);
#ifdef PLICE_DEBUG
#endif
s_vChangeAntenna(pDevice);
pDevice->TimerSQ3Tmax3.expires = RUN_AT(pDevice->byTMax3 * HZ);
pDevice->TimerSQ3Tmax2.expires = RUN_AT(pDevice->byTMax2 * HZ);
add_timer(&pDevice->TimerSQ3Tmax3);
add_timer(&pDevice->TimerSQ3Tmax2);
}
pDevice->byAntennaState = 0;
BBvClearAntDivSQ3Value(pDevice);
}
}
}
void
TimerSQ3CallBack (
void *hDeviceContext
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"TimerSQ3CallBack...");
spin_lock_irq(&pDevice->lock);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"3.[%08x][%08x], %d\n",(int)pDevice->ulRatio_State0, (int)pDevice->ulRatio_State1, (int)pDevice->uDiversityCnt);
#ifdef PLICE_DEBUG
#endif
s_vChangeAntenna(pDevice);
pDevice->byAntennaState = 0;
BBvClearAntDivSQ3Value(pDevice);
pDevice->TimerSQ3Tmax3.expires = RUN_AT(pDevice->byTMax3 * HZ);
pDevice->TimerSQ3Tmax2.expires = RUN_AT(pDevice->byTMax2 * HZ);
add_timer(&pDevice->TimerSQ3Tmax3);
add_timer(&pDevice->TimerSQ3Tmax2);
spin_unlock_irq(&pDevice->lock);
return;
}
void
TimerState1CallBack (
void *hDeviceContext
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"TimerState1CallBack...");
spin_lock_irq(&pDevice->lock);
if (pDevice->uDiversityCnt < pDevice->ulDiversityMValue/100) {
#ifdef PLICE_DEBUG
#endif
s_vChangeAntenna(pDevice);
pDevice->TimerSQ3Tmax3.expires = RUN_AT(pDevice->byTMax3 * HZ);
pDevice->TimerSQ3Tmax2.expires = RUN_AT(pDevice->byTMax2 * HZ);
add_timer(&pDevice->TimerSQ3Tmax3);
add_timer(&pDevice->TimerSQ3Tmax2);
} else {
pDevice->ulRatio_State1 = s_ulGetRatio(pDevice);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"SQ3_State1, rate0 = %08x,rate1 = %08x\n",
(int)pDevice->ulRatio_State0,(int)pDevice->ulRatio_State1);
if ( pDevice->ulRatio_State1 < pDevice->ulRatio_State0 ) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"2.[%08x][%08x], uNumSQ3[%d]=%d, %d\n",
(int)pDevice->ulRatio_State0, (int)pDevice->ulRatio_State1,
(int)pDevice->wAntDiversityMaxRate,
(int)pDevice->uNumSQ3[(int)pDevice->wAntDiversityMaxRate], (int)pDevice->uDiversityCnt);
#ifdef PLICE_DEBUG
#endif
s_vChangeAntenna(pDevice);
pDevice->TimerSQ3Tmax3.expires = RUN_AT(pDevice->byTMax3 * HZ);
pDevice->TimerSQ3Tmax2.expires = RUN_AT(pDevice->byTMax2 * HZ);
add_timer(&pDevice->TimerSQ3Tmax3);
add_timer(&pDevice->TimerSQ3Tmax2);
}
}
pDevice->byAntennaState = 0;
BBvClearAntDivSQ3Value(pDevice);
spin_unlock_irq(&pDevice->lock);
return;
}
