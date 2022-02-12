void *pcicore_init(struct si_pub *sih, void *pdev, void *regs)
{
struct pcicore_info *pi;
pi = kzalloc(sizeof(struct pcicore_info), GFP_ATOMIC);
if (pi == NULL) {
PCI_ERROR(("pci_attach: malloc failed!\n"));
return NULL;
}
pi->sih = sih;
pi->dev = pdev;
if (sih->buscoretype == PCIE_CORE_ID) {
u8 cap_ptr;
pi->regs.pcieregs = regs;
cap_ptr = pcicore_find_pci_capability(pi->dev, PCI_CAP_ID_EXP,
NULL, NULL);
pi->pciecap_lcreg_offset = cap_ptr + PCIE_CAP_LINKCTRL_OFFSET;
} else
pi->regs.pciregs = regs;
return pi;
}
void pcicore_deinit(void *pch)
{
kfree(pch);
}
u8
pcicore_find_pci_capability(void *dev, u8 req_cap_id,
unsigned char *buf, u32 *buflen)
{
u8 cap_id;
u8 cap_ptr = 0;
u32 bufsize;
u8 byte_val;
pci_read_config_byte(dev, PCI_HEADER_TYPE, &byte_val);
if ((byte_val & 0x7f) != PCI_HEADER_TYPE_NORMAL)
goto end;
pci_read_config_byte(dev, PCI_STATUS, &byte_val);
if (!(byte_val & PCI_STATUS_CAP_LIST))
goto end;
pci_read_config_byte(dev, PCI_CAPABILITY_LIST, &cap_ptr);
if (cap_ptr == 0x00)
goto end;
pci_read_config_byte(dev, cap_ptr, &cap_id);
while (cap_id != req_cap_id) {
pci_read_config_byte(dev, cap_ptr + 1, &cap_ptr);
if (cap_ptr == 0x00)
break;
pci_read_config_byte(dev, cap_ptr, &cap_id);
}
if (cap_id != req_cap_id)
goto end;
if (buf != NULL && buflen != NULL) {
u8 cap_data;
bufsize = *buflen;
if (!bufsize)
goto end;
*buflen = 0;
cap_data = cap_ptr + 2;
if ((bufsize + cap_data) > PCI_SZPCR)
bufsize = PCI_SZPCR - cap_data;
*buflen = bufsize;
while (bufsize--) {
pci_read_config_byte(dev, cap_data, buf);
cap_data++;
buf++;
}
}
end:
return cap_ptr;
}
static uint
pcie_readreg(struct sbpcieregs *pcieregs, uint addrtype, uint offset)
{
uint retval = 0xFFFFFFFF;
switch (addrtype) {
case PCIE_CONFIGREGS:
W_REG(&pcieregs->configaddr, offset);
(void)R_REG((&pcieregs->configaddr));
retval = R_REG(&pcieregs->configdata);
break;
case PCIE_PCIEREGS:
W_REG(&pcieregs->pcieindaddr, offset);
(void)R_REG(&pcieregs->pcieindaddr);
retval = R_REG(&pcieregs->pcieinddata);
break;
}
return retval;
}
static uint
pcie_writereg(struct sbpcieregs *pcieregs, uint addrtype, uint offset, uint val)
{
switch (addrtype) {
case PCIE_CONFIGREGS:
W_REG((&pcieregs->configaddr), offset);
W_REG((&pcieregs->configdata), val);
break;
case PCIE_PCIEREGS:
W_REG((&pcieregs->pcieindaddr), offset);
W_REG((&pcieregs->pcieinddata), val);
break;
default:
break;
}
return 0;
}
static bool pcie_mdiosetblock(struct pcicore_info *pi, uint blk)
{
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
uint mdiodata, i = 0;
uint pcie_serdes_spinwait = 200;
mdiodata = (MDIODATA_START | MDIODATA_WRITE | MDIODATA_TA |
(MDIODATA_DEV_ADDR << MDIODATA_DEVADDR_SHF) |
(MDIODATA_BLK_ADDR << MDIODATA_REGADDR_SHF) |
(blk << 4));
W_REG(&pcieregs->mdiodata, mdiodata);
PR28829_DELAY();
while (i < pcie_serdes_spinwait) {
if (R_REG(&pcieregs->mdiocontrol) & MDIOCTL_ACCESS_DONE)
break;
udelay(1000);
i++;
}
if (i >= pcie_serdes_spinwait) {
PCI_ERROR(("pcie_mdiosetblock: timed out\n"));
return false;
}
return true;
}
static int
pcie_mdioop(struct pcicore_info *pi, uint physmedia, uint regaddr, bool write,
uint *val)
{
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
uint mdiodata;
uint i = 0;
uint pcie_serdes_spinwait = 10;
W_REG(&pcieregs->mdiocontrol, MDIOCTL_PREAM_EN | MDIOCTL_DIVISOR_VAL);
if (pi->sih->buscorerev >= 10) {
if (!pcie_mdiosetblock(pi, physmedia))
return 1;
mdiodata = ((MDIODATA_DEV_ADDR << MDIODATA_DEVADDR_SHF) |
(regaddr << MDIODATA_REGADDR_SHF));
pcie_serdes_spinwait *= 20;
} else {
mdiodata = ((physmedia << MDIODATA_DEVADDR_SHF_OLD) |
(regaddr << MDIODATA_REGADDR_SHF_OLD));
}
if (!write)
mdiodata |= (MDIODATA_START | MDIODATA_READ | MDIODATA_TA);
else
mdiodata |= (MDIODATA_START | MDIODATA_WRITE | MDIODATA_TA |
*val);
W_REG(&pcieregs->mdiodata, mdiodata);
PR28829_DELAY();
while (i < pcie_serdes_spinwait) {
if (R_REG(&pcieregs->mdiocontrol) & MDIOCTL_ACCESS_DONE) {
if (!write) {
PR28829_DELAY();
*val = (R_REG(&pcieregs->mdiodata) &
MDIODATA_MASK);
}
W_REG(&pcieregs->mdiocontrol, 0);
return 0;
}
udelay(1000);
i++;
}
PCI_ERROR(("pcie_mdioop: timed out op: %d\n", write));
W_REG(&pcieregs->mdiocontrol, 0);
return 1;
}
static int
pcie_mdioread(struct pcicore_info *pi, uint physmedia, uint regaddr,
uint *regval)
{
return pcie_mdioop(pi, physmedia, regaddr, false, regval);
}
static int
pcie_mdiowrite(struct pcicore_info *pi, uint physmedia, uint regaddr, uint val)
{
return pcie_mdioop(pi, physmedia, regaddr, true, &val);
}
static u8 pcie_clkreq(void *pch, u32 mask, u32 val)
{
struct pcicore_info *pi = pch;
u32 reg_val;
u8 offset;
offset = pi->pciecap_lcreg_offset;
if (!offset)
return 0;
pci_read_config_dword(pi->dev, offset, &reg_val);
if (mask) {
if (val)
reg_val |= PCIE_CLKREQ_ENAB;
else
reg_val &= ~PCIE_CLKREQ_ENAB;
pci_write_config_dword(pi->dev, offset, reg_val);
pci_read_config_dword(pi->dev, offset, &reg_val);
}
if (reg_val & PCIE_CLKREQ_ENAB)
return 1;
else
return 0;
}
static void pcie_extendL1timer(struct pcicore_info *pi, bool extend)
{
u32 w;
struct si_pub *sih = pi->sih;
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
if (!PCIE_PUB(sih) || sih->buscorerev < 7)
return;
w = pcie_readreg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_PMTHRESHREG);
if (extend)
w |= PCIE_ASPMTIMER_EXTEND;
else
w &= ~PCIE_ASPMTIMER_EXTEND;
pcie_writereg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_PMTHRESHREG, w);
w = pcie_readreg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_PMTHRESHREG);
}
static void pcie_clkreq_upd(struct pcicore_info *pi, uint state)
{
struct si_pub *sih = pi->sih;
switch (state) {
case SI_DOATTACH:
if (PCIE_ASPM(sih))
pcie_clkreq((void *)pi, 1, 0);
break;
case SI_PCIDOWN:
if (sih->buscorerev == 6) {
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_addr),
~0, 0);
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_data),
~0x40, 0);
} else if (pi->pcie_pr42767) {
pcie_clkreq((void *)pi, 1, 1);
}
break;
case SI_PCIUP:
if (sih->buscorerev == 6) {
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_addr),
~0, 0);
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_data),
~0x40, 0x40);
} else if (PCIE_ASPM(sih)) {
pcie_clkreq((void *)pi, 1, 0);
}
break;
}
}
static void pcie_war_polarity(struct pcicore_info *pi)
{
u32 w;
if (pi->pcie_polarity != 0)
return;
w = pcie_readreg(pi->regs.pcieregs, PCIE_PCIEREGS, PCIE_PLP_STATUSREG);
if ((w & PCIE_PLP_POLARITYINV_STAT) == 0)
pi->pcie_polarity = SERDES_RX_CTRL_FORCE;
else
pi->pcie_polarity = (SERDES_RX_CTRL_FORCE |
SERDES_RX_CTRL_POLARITY);
}
static void pcie_war_aspm_clkreq(struct pcicore_info *pi)
{
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
struct si_pub *sih = pi->sih;
u16 val16, *reg16;
u32 w;
if (!PCIE_ASPM(sih))
return;
reg16 = &pcieregs->sprom[SRSH_ASPM_OFFSET];
val16 = R_REG(reg16);
val16 &= ~SRSH_ASPM_ENB;
if (pi->pcie_war_aspm_ovr == PCIE_ASPM_ENAB)
val16 |= SRSH_ASPM_ENB;
else if (pi->pcie_war_aspm_ovr == PCIE_ASPM_L1_ENAB)
val16 |= SRSH_ASPM_L1_ENB;
else if (pi->pcie_war_aspm_ovr == PCIE_ASPM_L0s_ENAB)
val16 |= SRSH_ASPM_L0s_ENB;
W_REG(reg16, val16);
pci_read_config_dword(pi->dev, pi->pciecap_lcreg_offset, &w);
w &= ~PCIE_ASPM_ENAB;
w |= pi->pcie_war_aspm_ovr;
pci_write_config_dword(pi->dev, pi->pciecap_lcreg_offset, w);
reg16 = &pcieregs->sprom[SRSH_CLKREQ_OFFSET_REV5];
val16 = R_REG(reg16);
if (pi->pcie_war_aspm_ovr != PCIE_ASPM_DISAB) {
val16 |= SRSH_CLKREQ_ENB;
pi->pcie_pr42767 = true;
} else
val16 &= ~SRSH_CLKREQ_ENB;
W_REG(reg16, val16);
}
static void pcie_war_serdes(struct pcicore_info *pi)
{
u32 w = 0;
if (pi->pcie_polarity != 0)
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_CTRL,
pi->pcie_polarity);
pcie_mdioread(pi, MDIODATA_DEV_PLL, SERDES_PLL_CTRL, &w);
if (w & PLL_CTRL_FREQDET_EN) {
w &= ~PLL_CTRL_FREQDET_EN;
pcie_mdiowrite(pi, MDIODATA_DEV_PLL, SERDES_PLL_CTRL, w);
}
}
static void pcie_misc_config_fixup(struct pcicore_info *pi)
{
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
u16 val16, *reg16;
reg16 = &pcieregs->sprom[SRSH_PCIE_MISC_CONFIG];
val16 = R_REG(reg16);
if ((val16 & SRSH_L23READY_EXIT_NOPERST) == 0) {
val16 |= SRSH_L23READY_EXIT_NOPERST;
W_REG(reg16, val16);
}
}
static void pcie_war_noplldown(struct pcicore_info *pi)
{
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
u16 *reg16;
ai_corereg(pi->sih, SI_CC_IDX, offsetof(chipcregs_t, chipcontrol),
CHIPCTRL_4321_PLL_DOWN, CHIPCTRL_4321_PLL_DOWN);
reg16 = &pcieregs->sprom[SRSH_BD_OFFSET];
W_REG(reg16, 0);
}
static void pcie_war_pci_setup(struct pcicore_info *pi)
{
struct si_pub *sih = pi->sih;
struct sbpcieregs *pcieregs = pi->regs.pcieregs;
u32 w;
if (sih->buscorerev == 0 || sih->buscorerev == 1) {
w = pcie_readreg(pcieregs, PCIE_PCIEREGS,
PCIE_TLP_WORKAROUNDSREG);
w |= 0x8;
pcie_writereg(pcieregs, PCIE_PCIEREGS,
PCIE_TLP_WORKAROUNDSREG, w);
}
if (sih->buscorerev == 1) {
w = pcie_readreg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_LCREG);
w |= 0x40;
pcie_writereg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_LCREG, w);
}
if (sih->buscorerev == 0) {
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_TIMER1, 0x8128);
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_CDR, 0x0100);
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_CDRBW, 0x1466);
} else if (PCIE_ASPM(sih)) {
w = pcie_readreg(pcieregs, PCIE_PCIEREGS,
PCIE_DLLP_PMTHRESHREG);
w &= ~PCIE_L1THRESHOLDTIME_MASK;
w |= PCIE_L1THRESHOLD_WARVAL << PCIE_L1THRESHOLDTIME_SHIFT;
pcie_writereg(pcieregs, PCIE_PCIEREGS,
PCIE_DLLP_PMTHRESHREG, w);
pcie_war_serdes(pi);
pcie_war_aspm_clkreq(pi);
} else if (pi->sih->buscorerev == 7)
pcie_war_noplldown(pi);
if (pi->sih->buscorerev >= 6)
pcie_misc_config_fixup(pi);
}
void pcicore_attach(void *pch, char *pvars, int state)
{
struct pcicore_info *pi = pch;
struct si_pub *sih = pi->sih;
if (PCIE_ASPM(sih)) {
if ((u32)getintvar(pvars, "boardflags2") & BFL2_PCIEWAR_OVR)
pi->pcie_war_aspm_ovr = PCIE_ASPM_DISAB;
else
pi->pcie_war_aspm_ovr = PCIE_ASPM_ENAB;
}
pcie_war_polarity(pi);
pcie_war_serdes(pi);
pcie_war_aspm_clkreq(pi);
pcie_clkreq_upd(pi, state);
}
void pcicore_hwup(void *pch)
{
struct pcicore_info *pi = pch;
if (!pi || !PCIE_PUB(pi->sih))
return;
pcie_war_pci_setup(pi);
}
void pcicore_up(void *pch, int state)
{
struct pcicore_info *pi = pch;
if (!pi || !PCIE_PUB(pi->sih))
return;
pcie_extendL1timer(pi, true);
pcie_clkreq_upd(pi, state);
}
void pcicore_sleep(void *pch)
{
struct pcicore_info *pi = pch;
u32 w;
if (!pi || !PCIE_ASPM(pi->sih))
return;
pci_read_config_dword(pi->dev, pi->pciecap_lcreg_offset, &w);
w &= ~PCIE_CAP_LCREG_ASPML1;
pci_write_config_dword(pi->dev, pi->pciecap_lcreg_offset, w);
pi->pcie_pr42767 = false;
}
void pcicore_down(void *pch, int state)
{
struct pcicore_info *pi = pch;
if (!pi || !PCIE_PUB(pi->sih))
return;
pcie_clkreq_upd(pi, state);
pcie_extendL1timer(pi, false);
}
void pcicore_fixcfg(void *pch, void *regs)
{
struct pcicore_info *pi = pch;
struct si_info *sii = SI_INFO(pi->sih);
struct sbpciregs *pciregs = regs;
struct sbpcieregs *pcieregs = regs;
u16 val16, *reg16 = NULL;
uint pciidx;
if (sii->pub.buscoretype == PCIE_CORE_ID)
reg16 = &pcieregs->sprom[SRSH_PI_OFFSET];
else if (sii->pub.buscoretype == PCI_CORE_ID)
reg16 = &pciregs->sprom[SRSH_PI_OFFSET];
pciidx = ai_coreidx(&sii->pub);
val16 = R_REG(reg16);
if (((val16 & SRSH_PI_MASK) >> SRSH_PI_SHIFT) != (u16)pciidx) {
val16 = (u16)(pciidx << SRSH_PI_SHIFT) |
(val16 & ~SRSH_PI_MASK);
W_REG(reg16, val16);
}
}
void pcicore_pci_setup(void *pch, void *regs)
{
struct pcicore_info *pi = pch;
struct sbpciregs *pciregs = regs;
u32 w;
OR_REG(&pciregs->sbtopci2, SBTOPCI_PREF | SBTOPCI_BURST);
if (SI_INFO(pi->sih)->pub.buscorerev >= 11) {
OR_REG(&pciregs->sbtopci2, SBTOPCI_RC_READMULTI);
w = R_REG(&pciregs->clkrun);
W_REG(&pciregs->clkrun, w | PCI_CLKRUN_DSBL);
w = R_REG(&pciregs->clkrun);
}
}
