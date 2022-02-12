unsigned char SROMbyReadEmbedded(void __iomem *dwIoBase, unsigned char byContntOffset)
{
unsigned short wDelay, wNoACK;
unsigned char byWait;
unsigned char byData;
unsigned char byOrg;
byData = 0xFF;
VNSvInPortB(dwIoBase + MAC_REG_I2MCFG, &byOrg);
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, (byOrg & (~I2MCFG_NORETRY)));
for (wNoACK = 0; wNoACK < W_MAX_I2CRETRY; wNoACK++) {
VNSvOutPortB(dwIoBase + MAC_REG_I2MTGID, EEP_I2C_DEV_ID);
VNSvOutPortB(dwIoBase + MAC_REG_I2MTGAD, byContntOffset);
VNSvOutPortB(dwIoBase + MAC_REG_I2MCSR, I2MCSR_EEMR);
for (wDelay = 0; wDelay < W_MAX_TIMEOUT; wDelay++) {
VNSvInPortB(dwIoBase + MAC_REG_I2MCSR, &byWait);
if (byWait & (I2MCSR_DONE | I2MCSR_NACK))
break;
PCAvDelayByIO(CB_DELAY_LOOP_WAIT);
}
if ((wDelay < W_MAX_TIMEOUT) &&
(!(byWait & I2MCSR_NACK))) {
break;
}
}
VNSvInPortB(dwIoBase + MAC_REG_I2MDIPT, &byData);
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, byOrg);
return byData;
}
bool SROMbWriteEmbedded(void __iomem *dwIoBase, unsigned char byContntOffset, unsigned char byData)
{
unsigned short wDelay, wNoACK;
unsigned char byWait;
unsigned char byOrg;
VNSvInPortB(dwIoBase + MAC_REG_I2MCFG, &byOrg);
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, (byOrg & (~I2MCFG_NORETRY)));
for (wNoACK = 0; wNoACK < W_MAX_I2CRETRY; wNoACK++) {
VNSvOutPortB(dwIoBase + MAC_REG_I2MTGID, EEP_I2C_DEV_ID);
VNSvOutPortB(dwIoBase + MAC_REG_I2MTGAD, byContntOffset);
VNSvOutPortB(dwIoBase + MAC_REG_I2MDOPT, byData);
VNSvOutPortB(dwIoBase + MAC_REG_I2MCSR, I2MCSR_EEMW);
for (wDelay = 0; wDelay < W_MAX_TIMEOUT; wDelay++) {
VNSvInPortB(dwIoBase + MAC_REG_I2MCSR, &byWait);
if (byWait & (I2MCSR_DONE | I2MCSR_NACK))
break;
PCAvDelayByIO(CB_DELAY_LOOP_WAIT);
}
if ((wDelay < W_MAX_TIMEOUT) &&
(!(byWait & I2MCSR_NACK))) {
break;
}
}
if (wNoACK == W_MAX_I2CRETRY) {
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, byOrg);
return false;
}
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, byOrg);
return true;
}
void SROMvRegBitsOn(void __iomem *dwIoBase, unsigned char byContntOffset, unsigned char byBits)
{
unsigned char byOrgData;
byOrgData = SROMbyReadEmbedded(dwIoBase, byContntOffset);
SROMbWriteEmbedded(dwIoBase, byContntOffset, (unsigned char)(byOrgData | byBits));
}
void SROMvRegBitsOff(void __iomem *dwIoBase, unsigned char byContntOffset, unsigned char byBits)
{
unsigned char byOrgData;
byOrgData = SROMbyReadEmbedded(dwIoBase, byContntOffset);
SROMbWriteEmbedded(dwIoBase, byContntOffset, (unsigned char)(byOrgData & (~byBits)));
}
bool SROMbIsRegBitsOn(void __iomem *dwIoBase, unsigned char byContntOffset, unsigned char byTestBits)
{
unsigned char byOrgData;
byOrgData = SROMbyReadEmbedded(dwIoBase, byContntOffset);
return (byOrgData & byTestBits) == byTestBits;
}
bool SROMbIsRegBitsOff(void __iomem *dwIoBase, unsigned char byContntOffset, unsigned char byTestBits)
{
unsigned char byOrgData;
byOrgData = SROMbyReadEmbedded(dwIoBase, byContntOffset);
return !(byOrgData & byTestBits);
}
void SROMvReadAllContents(void __iomem *dwIoBase, unsigned char *pbyEepromRegs)
{
int ii;
for (ii = 0; ii < EEP_MAX_CONTEXT_SIZE; ii++) {
*pbyEepromRegs = SROMbyReadEmbedded(dwIoBase, (unsigned char)ii);
pbyEepromRegs++;
}
}
void SROMvWriteAllContents(void __iomem *dwIoBase, unsigned char *pbyEepromRegs)
{
int ii;
for (ii = 0; ii < EEP_MAX_CONTEXT_SIZE; ii++) {
SROMbWriteEmbedded(dwIoBase, (unsigned char)ii, *pbyEepromRegs);
pbyEepromRegs++;
}
}
void SROMvReadEtherAddress(void __iomem *dwIoBase, unsigned char *pbyEtherAddress)
{
unsigned char ii;
for (ii = 0; ii < ETH_ALEN; ii++) {
*pbyEtherAddress = SROMbyReadEmbedded(dwIoBase, ii);
pbyEtherAddress++;
}
}
void SROMvWriteEtherAddress(void __iomem *dwIoBase, unsigned char *pbyEtherAddress)
{
unsigned char ii;
for (ii = 0; ii < ETH_ALEN; ii++) {
SROMbWriteEmbedded(dwIoBase, ii, *pbyEtherAddress);
pbyEtherAddress++;
}
}
void SROMvReadSubSysVenId(void __iomem *dwIoBase, unsigned long *pdwSubSysVenId)
{
unsigned char *pbyData;
pbyData = (unsigned char *)pdwSubSysVenId;
*pbyData = SROMbyReadEmbedded(dwIoBase, 6);
*(pbyData+1) = SROMbyReadEmbedded(dwIoBase, 7);
*(pbyData+2) = SROMbyReadEmbedded(dwIoBase, 8);
*(pbyData+3) = SROMbyReadEmbedded(dwIoBase, 9);
}
bool SROMbAutoLoad(void __iomem *dwIoBase)
{
unsigned char byWait;
int ii;
unsigned char byOrg;
VNSvInPortB(dwIoBase + MAC_REG_I2MCFG, &byOrg);
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, (byOrg | I2MCFG_NORETRY));
MACvRegBitsOn(dwIoBase, MAC_REG_I2MCSR, I2MCSR_AUTOLD);
for (ii = 0; ii < EEP_MAX_CONTEXT_SIZE; ii++) {
MACvTimer0MicroSDelay(dwIoBase, CB_EEPROM_READBYTE_WAIT);
VNSvInPortB(dwIoBase + MAC_REG_I2MCSR, &byWait);
if (!(byWait & I2MCSR_AUTOLD))
break;
}
VNSvOutPortB(dwIoBase + MAC_REG_I2MCFG, byOrg);
if (ii == EEP_MAX_CONTEXT_SIZE)
return false;
return true;
}
