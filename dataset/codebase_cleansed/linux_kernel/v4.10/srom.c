unsigned char SROMbyReadEmbedded(void __iomem *iobase,
unsigned char byContntOffset)
{
unsigned short wDelay, wNoACK;
unsigned char byWait;
unsigned char byData;
unsigned char byOrg;
byData = 0xFF;
VNSvInPortB(iobase + MAC_REG_I2MCFG, &byOrg);
VNSvOutPortB(iobase + MAC_REG_I2MCFG, (byOrg & (~I2MCFG_NORETRY)));
for (wNoACK = 0; wNoACK < W_MAX_I2CRETRY; wNoACK++) {
VNSvOutPortB(iobase + MAC_REG_I2MTGID, EEP_I2C_DEV_ID);
VNSvOutPortB(iobase + MAC_REG_I2MTGAD, byContntOffset);
VNSvOutPortB(iobase + MAC_REG_I2MCSR, I2MCSR_EEMR);
for (wDelay = 0; wDelay < W_MAX_TIMEOUT; wDelay++) {
VNSvInPortB(iobase + MAC_REG_I2MCSR, &byWait);
if (byWait & (I2MCSR_DONE | I2MCSR_NACK))
break;
PCAvDelayByIO(CB_DELAY_LOOP_WAIT);
}
if ((wDelay < W_MAX_TIMEOUT) &&
(!(byWait & I2MCSR_NACK))) {
break;
}
}
VNSvInPortB(iobase + MAC_REG_I2MDIPT, &byData);
VNSvOutPortB(iobase + MAC_REG_I2MCFG, byOrg);
return byData;
}
void SROMvReadAllContents(void __iomem *iobase, unsigned char *pbyEepromRegs)
{
int ii;
for (ii = 0; ii < EEP_MAX_CONTEXT_SIZE; ii++) {
*pbyEepromRegs = SROMbyReadEmbedded(iobase,
(unsigned char)ii);
pbyEepromRegs++;
}
}
void SROMvReadEtherAddress(void __iomem *iobase,
unsigned char *pbyEtherAddress)
{
unsigned char ii;
for (ii = 0; ii < ETH_ALEN; ii++) {
*pbyEtherAddress = SROMbyReadEmbedded(iobase, ii);
pbyEtherAddress++;
}
}
