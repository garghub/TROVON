static u32 InitSDRAMRegisters(volatile STG4000REG __iomem *pSTGReg,
u32 dwSubSysID, u32 dwRevID)
{
u32 adwSDRAMArgCfg0[] = { 0xa0, 0x80, 0xa0, 0xa0, 0xa0 };
u32 adwSDRAMCfg1[] = { 0x8732, 0x8732, 0xa732, 0xa732, 0x8732 };
u32 adwSDRAMCfg2[] = { 0x87d2, 0x87d2, 0xa7d2, 0x87d2, 0xa7d2 };
u32 adwSDRAMRsh[] = { 36, 39, 40 };
u32 adwChipSpeed[] = { 110, 120, 125 };
u32 dwMemTypeIdx;
u32 dwChipSpeedIdx;
dwMemTypeIdx = (dwSubSysID & 0x70) >> 4;
dwChipSpeedIdx = (dwSubSysID & 0x180) >> 7;
if (dwMemTypeIdx > 4 || dwChipSpeedIdx > 2)
return 0;
STG_WRITE_REG(SDRAMArbiterConf, adwSDRAMArgCfg0[dwMemTypeIdx]);
if (dwRevID < 5) {
STG_WRITE_REG(SDRAMConf0, 0x49A1);
STG_WRITE_REG(SDRAMConf1, adwSDRAMCfg1[dwMemTypeIdx]);
} else {
STG_WRITE_REG(SDRAMConf0, 0x4DF1);
STG_WRITE_REG(SDRAMConf1, adwSDRAMCfg2[dwMemTypeIdx]);
}
STG_WRITE_REG(SDRAMConf2, 0x31);
STG_WRITE_REG(SDRAMRefresh, adwSDRAMRsh[dwChipSpeedIdx]);
return adwChipSpeed[dwChipSpeedIdx] * 10000;
}
u32 ProgramClock(u32 refClock,
u32 coreClock,
u32 * FOut, u32 * ROut, u32 * POut)
{
u32 R = 0, F = 0, OD = 0, ODIndex = 0;
u32 ulBestR = 0, ulBestF = 0, ulBestOD = 0;
u32 ulBestVCO = 0, ulBestClk = 0, ulBestScore = 0;
u32 ulScore, ulPhaseScore, ulVcoScore;
u32 ulTmp = 0, ulVCO;
u32 ulScaleClockReq, ulMinClock, ulMaxClock;
u32 ODValues[] = { 1, 2, 0 };
coreClock *= 100;
refClock *= 1000;
ulMinClock = coreClock - (coreClock >> 8);
ulMaxClock = coreClock + (coreClock >> 8);
ulScaleClockReq = coreClock >> STG4K3_PLL_SCALER;
for (ODIndex = 0; ODIndex < 3; ODIndex++) {
OD = ODValues[ODIndex];
R = STG4K3_PLL_MIN_R;
while (R <= STG4K3_PLL_MAX_R) {
ulTmp = R * (ulScaleClockReq << OD);
F = (u32)(ulTmp / (refClock >> STG4K3_PLL_SCALER));
if (F > STG4K3_PLL_MIN_F)
F--;
while ((F >= STG4K3_PLL_MIN_F) &&
(F <= STG4K3_PLL_MAX_F)) {
ulVCO = refClock / R;
ulVCO = F * ulVCO;
if ((ulVCO >= STG4K3_PLL_MINR_VCO) &&
((ulVCO <= STG4K3_PLL_MAXR_VCO) ||
((coreClock > STG4K3_PLL_MAXR_VCO)
&& (ulVCO <= STG4K3_PLL_MAX_VCO)))) {
ulTmp = (ulVCO >> OD);
if ((ulTmp >= ulMinClock)
&& (ulTmp <= ulMaxClock)) {
ulPhaseScore = (((refClock / R) - (refClock / STG4K3_PLL_MAX_R))) / ((refClock - (refClock / STG4K3_PLL_MAX_R)) >> 10);
ulVcoScore = ((ulVCO - STG4K3_PLL_MINR_VCO)) / ((STG4K3_PLL_MAXR_VCO - STG4K3_PLL_MINR_VCO) >> 10);
ulScore = ulPhaseScore + ulVcoScore;
if (!ulBestScore) {
ulBestVCO = ulVCO;
ulBestOD = OD;
ulBestF = F;
ulBestR = R;
ulBestClk = ulTmp;
ulBestScore =
ulScore;
}
if ((ulScore >= ulBestScore) && (OD > 0)) {
ulBestVCO = ulVCO;
ulBestOD = OD;
ulBestF = F;
ulBestR = R;
ulBestClk = ulTmp;
ulBestScore =
ulScore;
}
}
}
F++;
}
R++;
}
}
if (ulBestScore) {
*ROut = ulBestR;
*FOut = ulBestF;
if ((ulBestOD == 2) || (ulBestOD == 3)) {
*POut = 3;
} else
*POut = ulBestOD;
}
return (ulBestClk);
}
int SetCoreClockPLL(volatile STG4000REG __iomem *pSTGReg, struct pci_dev *pDev)
{
u32 F, R, P;
u16 core_pll = 0, sub;
u32 ulCoreClock;
u32 tmp;
u32 ulChipSpeed;
STG_WRITE_REG(IntMask, 0xFFFF);
tmp = STG_READ_REG(Thread0Enable);
CLEAR_BIT(0);
STG_WRITE_REG(Thread0Enable, tmp);
tmp = STG_READ_REG(Thread1Enable);
CLEAR_BIT(0);
STG_WRITE_REG(Thread1Enable, tmp);
STG_WRITE_REG(SoftwareReset,
PMX2_SOFTRESET_REG_RST | PMX2_SOFTRESET_ROM_RST);
STG_WRITE_REG(SoftwareReset,
PMX2_SOFTRESET_REG_RST | PMX2_SOFTRESET_TA_RST |
PMX2_SOFTRESET_ROM_RST);
STG_WRITE_REG(TAConfiguration, 0);
STG_WRITE_REG(SoftwareReset,
PMX2_SOFTRESET_REG_RST | PMX2_SOFTRESET_ROM_RST);
STG_WRITE_REG(SoftwareReset,
PMX2_SOFTRESET_REG_RST | PMX2_SOFTRESET_TA_RST |
PMX2_SOFTRESET_ROM_RST);
pci_read_config_word(pDev, PCI_CONFIG_SUBSYS_ID, &sub);
ulChipSpeed = InitSDRAMRegisters(pSTGReg, (u32)sub,
(u32)pDev->revision);
if (ulChipSpeed == 0)
return -EINVAL;
ulCoreClock = ProgramClock(REF_FREQ, CORE_PLL_FREQ, &F, &R, &P);
core_pll |= ((P) | ((F - 2) << 2) | ((R - 2) << 11));
tmp = ((CORE_PLL_MODE_REG_0_7 << 8) | (core_pll & 0x00FF));
pci_write_config_word(pDev, CorePllControl, tmp);
OS_DELAY(1000000);
tmp |= SET_BIT(14);
pci_write_config_word(pDev, CorePllControl, tmp);
OS_DELAY(1000000);
tmp =
((CORE_PLL_MODE_REG_8_15 << 8) | ((core_pll & 0xFF00) >> 8));
pci_write_config_word(pDev, CorePllControl, tmp);
OS_DELAY(1000000);
tmp |= SET_BIT(14);
pci_write_config_word(pDev, CorePllControl, tmp);
OS_DELAY(1000000);
STG_WRITE_REG(SoftwareReset, PMX2_SOFTRESET_ALL);
#if 0
tmp = ((STG_READ_REG(Thread0Enable)) | SET_BIT(0));
STG_WRITE_REG(Thread0Enable, tmp);
tmp = ((STG_READ_REG(Thread1Enable)) | SET_BIT(0));
STG_WRITE_REG(Thread1Enable, tmp);
#endif
return 0;
}
