void *pcicore_init(si_t *sih, void *pdev, void *regs)
{
pcicore_info_t *pi;
pi = kzalloc(sizeof(pcicore_info_t), GFP_ATOMIC);
if (pi == NULL) {
PCI_ERROR(("pci_attach: malloc failed!\n"));
return NULL;
}
pi->sih = sih;
pi->dev = pdev;
if (sih->buscoretype == PCIE_CORE_ID) {
u8 cap_ptr;
pi->regs.pcieregs = (sbpcieregs_t *) regs;
cap_ptr = pcicore_find_pci_capability(pi->dev, PCI_CAP_ID_EXP,
NULL, NULL);
pi->pciecap_lcreg_offset = cap_ptr + PCIE_CAP_LINKCTRL_OFFSET;
} else
pi->regs.pciregs = (struct sbpciregs *) regs;
return pi;
}
void pcicore_deinit(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
if (pi == NULL)
return;
kfree(pi);
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
if (cap_id != req_cap_id) {
goto end;
}
if ((buf != NULL) && (buflen != NULL)) {
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
uint
pcie_readreg(sbpcieregs_t *pcieregs, uint addrtype,
uint offset)
{
uint retval = 0xFFFFFFFF;
switch (addrtype) {
case PCIE_CONFIGREGS:
W_REG((&pcieregs->configaddr), offset);
(void)R_REG((&pcieregs->configaddr));
retval = R_REG(&(pcieregs->configdata));
break;
case PCIE_PCIEREGS:
W_REG(&(pcieregs->pcieindaddr), offset);
(void)R_REG((&pcieregs->pcieindaddr));
retval = R_REG(&(pcieregs->pcieinddata));
break;
default:
break;
}
return retval;
}
uint
pcie_writereg(sbpcieregs_t *pcieregs, uint addrtype,
uint offset, uint val)
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
static bool pcie_mdiosetblock(pcicore_info_t *pi, uint blk)
{
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
uint mdiodata, i = 0;
uint pcie_serdes_spinwait = 200;
mdiodata =
MDIODATA_START | MDIODATA_WRITE | (MDIODATA_DEV_ADDR <<
MDIODATA_DEVADDR_SHF) |
(MDIODATA_BLK_ADDR << MDIODATA_REGADDR_SHF) | MDIODATA_TA | (blk <<
4);
W_REG(&pcieregs->mdiodata, mdiodata);
PR28829_DELAY();
while (i < pcie_serdes_spinwait) {
if (R_REG(&(pcieregs->mdiocontrol)) &
MDIOCTL_ACCESS_DONE) {
break;
}
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
pcie_mdioop(pcicore_info_t *pi, uint physmedia, uint regaddr, bool write,
uint *val)
{
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
uint mdiodata;
uint i = 0;
uint pcie_serdes_spinwait = 10;
W_REG((&pcieregs->mdiocontrol),
MDIOCTL_PREAM_EN | MDIOCTL_DIVISOR_VAL);
if (pi->sih->buscorerev >= 10) {
if (!pcie_mdiosetblock(pi, physmedia))
return 1;
mdiodata = (MDIODATA_DEV_ADDR << MDIODATA_DEVADDR_SHF) |
(regaddr << MDIODATA_REGADDR_SHF);
pcie_serdes_spinwait *= 20;
} else {
mdiodata = (physmedia << MDIODATA_DEVADDR_SHF_OLD) |
(regaddr << MDIODATA_REGADDR_SHF_OLD);
}
if (!write)
mdiodata |= (MDIODATA_START | MDIODATA_READ | MDIODATA_TA);
else
mdiodata |=
(MDIODATA_START | MDIODATA_WRITE | MDIODATA_TA | *val);
W_REG(&pcieregs->mdiodata, mdiodata);
PR28829_DELAY();
while (i < pcie_serdes_spinwait) {
if (R_REG(&(pcieregs->mdiocontrol)) &
MDIOCTL_ACCESS_DONE) {
if (!write) {
PR28829_DELAY();
*val =
(R_REG(&(pcieregs->mdiodata)) &
MDIODATA_MASK);
}
W_REG((&pcieregs->mdiocontrol), 0);
return 0;
}
udelay(1000);
i++;
}
PCI_ERROR(("pcie_mdioop: timed out op: %d\n", write));
W_REG((&pcieregs->mdiocontrol), 0);
return 1;
}
static int
pcie_mdioread(pcicore_info_t *pi, uint physmedia, uint regaddr, uint *regval)
{
return pcie_mdioop(pi, physmedia, regaddr, false, regval);
}
static int
pcie_mdiowrite(pcicore_info_t *pi, uint physmedia, uint regaddr, uint val)
{
return pcie_mdioop(pi, physmedia, regaddr, true, &val);
}
u8 pcie_clkreq(void *pch, u32 mask, u32 val)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
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
static void pcie_extendL1timer(pcicore_info_t *pi, bool extend)
{
u32 w;
si_t *sih = pi->sih;
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
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
static void pcie_clkreq_upd(pcicore_info_t *pi, uint state)
{
si_t *sih = pi->sih;
switch (state) {
case SI_DOATTACH:
if (PCIE_ASPM(sih))
pcie_clkreq((void *)pi, 1, 0);
break;
case SI_PCIDOWN:
if (sih->buscorerev == 6) {
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_addr), ~0,
0);
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
offsetof(chipcregs_t, chipcontrol_addr), ~0,
0);
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_data),
~0x40, 0x40);
} else if (PCIE_ASPM(sih)) {
pcie_clkreq((void *)pi, 1, 0);
}
break;
default:
break;
}
}
static void pcie_war_polarity(pcicore_info_t *pi)
{
u32 w;
if (pi->pcie_polarity != 0)
return;
w = pcie_readreg(pi->regs.pcieregs, PCIE_PCIEREGS,
PCIE_PLP_STATUSREG);
if ((w & PCIE_PLP_POLARITYINV_STAT) == 0)
pi->pcie_polarity = (SERDES_RX_CTRL_FORCE);
else
pi->pcie_polarity =
(SERDES_RX_CTRL_FORCE | SERDES_RX_CTRL_POLARITY);
}
static void pcie_war_aspm_clkreq(pcicore_info_t *pi)
{
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
si_t *sih = pi->sih;
u16 val16, *reg16;
u32 w;
if (!PCIE_ASPM(sih))
return;
if (!ISSIM_ENAB(sih)) {
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
pci_read_config_dword(pi->dev, pi->pciecap_lcreg_offset,
&w);
w &= ~PCIE_ASPM_ENAB;
w |= pi->pcie_war_aspm_ovr;
pci_write_config_dword(pi->dev,
pi->pciecap_lcreg_offset, w);
}
reg16 = &pcieregs->sprom[SRSH_CLKREQ_OFFSET_REV5];
val16 = R_REG(reg16);
if (pi->pcie_war_aspm_ovr != PCIE_ASPM_DISAB) {
val16 |= SRSH_CLKREQ_ENB;
pi->pcie_pr42767 = true;
} else
val16 &= ~SRSH_CLKREQ_ENB;
W_REG(reg16, val16);
}
static void pcie_war_serdes(pcicore_info_t *pi)
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
static void pcie_misc_config_fixup(pcicore_info_t *pi)
{
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
u16 val16, *reg16;
reg16 = &pcieregs->sprom[SRSH_PCIE_MISC_CONFIG];
val16 = R_REG(reg16);
if ((val16 & SRSH_L23READY_EXIT_NOPERST) == 0) {
val16 |= SRSH_L23READY_EXIT_NOPERST;
W_REG(reg16, val16);
}
}
static void pcie_war_noplldown(pcicore_info_t *pi)
{
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
u16 *reg16;
ai_corereg(pi->sih, SI_CC_IDX, offsetof(chipcregs_t, chipcontrol),
CHIPCTRL_4321_PLL_DOWN, CHIPCTRL_4321_PLL_DOWN);
reg16 = &pcieregs->sprom[SRSH_BD_OFFSET];
W_REG(reg16, 0);
}
static void pcie_war_pci_setup(pcicore_info_t *pi)
{
si_t *sih = pi->sih;
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
u32 w;
if ((sih->buscorerev == 0) || (sih->buscorerev == 1)) {
w = pcie_readreg(pcieregs, PCIE_PCIEREGS,
PCIE_TLP_WORKAROUNDSREG);
w |= 0x8;
pcie_writereg(pcieregs, PCIE_PCIEREGS,
PCIE_TLP_WORKAROUNDSREG, w);
}
if (sih->buscorerev == 1) {
w = pcie_readreg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_LCREG);
w |= (0x40);
pcie_writereg(pcieregs, PCIE_PCIEREGS, PCIE_DLLP_LCREG, w);
}
if (sih->buscorerev == 0) {
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_TIMER1, 0x8128);
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_CDR, 0x0100);
pcie_mdiowrite(pi, MDIODATA_DEV_RX, SERDES_RX_CDRBW, 0x1466);
} else if (PCIE_ASPM(sih)) {
w = pcie_readreg(pcieregs, PCIE_PCIEREGS,
PCIE_DLLP_PMTHRESHREG);
w &= ~(PCIE_L1THRESHOLDTIME_MASK);
w |= (PCIE_L1THRESHOLD_WARVAL << PCIE_L1THRESHOLDTIME_SHIFT);
pcie_writereg(pcieregs, PCIE_PCIEREGS,
PCIE_DLLP_PMTHRESHREG, w);
pcie_war_serdes(pi);
pcie_war_aspm_clkreq(pi);
} else if (pi->sih->buscorerev == 7)
pcie_war_noplldown(pi);
if (pi->sih->buscorerev >= 6)
pcie_misc_config_fixup(pi);
}
void pcie_war_ovr_aspm_update(void *pch, u8 aspm)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
if (!PCIE_ASPM(pi->sih))
return;
if (aspm > PCIE_ASPM_ENAB)
return;
pi->pcie_war_aspm_ovr = aspm;
pcie_war_aspm_clkreq(pi);
}
void pcicore_attach(void *pch, char *pvars, int state)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
si_t *sih = pi->sih;
if (PCIE_ASPM(sih)) {
if ((u32) getintvar(pvars, "boardflags2") & BFL2_PCIEWAR_OVR) {
pi->pcie_war_aspm_ovr = PCIE_ASPM_DISAB;
} else {
pi->pcie_war_aspm_ovr = PCIE_ASPM_ENAB;
}
}
pcie_war_polarity(pi);
pcie_war_serdes(pi);
pcie_war_aspm_clkreq(pi);
pcie_clkreq_upd(pi, state);
}
void pcicore_hwup(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
if (!pi || !PCIE_PUB(pi->sih))
return;
pcie_war_pci_setup(pi);
}
void pcicore_up(void *pch, int state)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
if (!pi || !PCIE_PUB(pi->sih))
return;
pcie_extendL1timer(pi, true);
pcie_clkreq_upd(pi, state);
}
void pcicore_sleep(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
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
pcicore_info_t *pi = (pcicore_info_t *) pch;
if (!pi || !PCIE_PUB(pi->sih))
return;
pcie_clkreq_upd(pi, state);
pcie_extendL1timer(pi, false);
}
bool pcicore_pmecap_fast(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
u8 cap_ptr;
u32 pmecap;
cap_ptr = pcicore_find_pci_capability(pi->dev, PCI_CAP_ID_PM, NULL,
NULL);
if (!cap_ptr)
return false;
pci_read_config_dword(pi->dev, cap_ptr, &pmecap);
return (pmecap & (PCI_PM_CAP_PME_MASK << 16)) != 0;
}
static bool pcicore_pmecap(pcicore_info_t *pi)
{
u8 cap_ptr;
u32 pmecap;
if (!pi->pmecap_offset) {
cap_ptr = pcicore_find_pci_capability(pi->dev,
PCI_CAP_ID_PM,
NULL, NULL);
if (!cap_ptr)
return false;
pi->pmecap_offset = cap_ptr;
pci_read_config_dword(pi->dev, pi->pmecap_offset,
&pmecap);
pi->pmecap = (pmecap & (PCI_PM_CAP_PME_MASK << 16)) != 0;
}
return pi->pmecap;
}
void pcicore_pmeen(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
u32 w;
if (!pcicore_pmecap(pi))
return;
pci_read_config_dword(pi->dev, pi->pmecap_offset + PCI_PM_CTRL,
&w);
w |= (PCI_PM_CTRL_PME_ENABLE);
pci_write_config_dword(pi->dev,
pi->pmecap_offset + PCI_PM_CTRL, w);
}
bool pcicore_pmestat(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
u32 w;
if (!pcicore_pmecap(pi))
return false;
pci_read_config_dword(pi->dev, pi->pmecap_offset + PCI_PM_CTRL,
&w);
return (w & PCI_PM_CTRL_PME_STATUS) == PCI_PM_CTRL_PME_STATUS;
}
void pcicore_pmeclr(void *pch)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
u32 w;
if (!pcicore_pmecap(pi))
return;
pci_read_config_dword(pi->dev, pi->pmecap_offset + PCI_PM_CTRL,
&w);
PCI_ERROR(("pcicore_pci_pmeclr PMECSR : 0x%x\n", w));
w &= ~(PCI_PM_CTRL_PME_ENABLE);
pci_write_config_dword(pi->dev,
pi->pmecap_offset + PCI_PM_CTRL, w);
}
u32 pcie_lcreg(void *pch, u32 mask, u32 val)
{
pcicore_info_t *pi = (pcicore_info_t *) pch;
u8 offset;
u32 tmpval;
offset = pi->pciecap_lcreg_offset;
if (!offset)
return 0;
if (mask)
pci_write_config_dword(pi->dev, offset, val);
pci_read_config_dword(pi->dev, offset, &tmpval);
return tmpval;
}
u32
pcicore_pciereg(void *pch, u32 offset, u32 mask, u32 val, uint type)
{
u32 reg_val = 0;
pcicore_info_t *pi = (pcicore_info_t *) pch;
sbpcieregs_t *pcieregs = pi->regs.pcieregs;
if (mask) {
PCI_ERROR(("PCIEREG: 0x%x writeval 0x%x\n", offset, val));
pcie_writereg(pcieregs, type, offset, val);
}
if (pi->sih->buscorerev <= 5 && offset == PCIE_DLLP_PCIE11
&& type == PCIE_PCIEREGS)
return reg_val;
reg_val = pcie_readreg(pcieregs, type, offset);
PCI_ERROR(("PCIEREG: 0x%x readval is 0x%x\n", offset, reg_val));
return reg_val;
}
u32
pcicore_pcieserdesreg(void *pch, u32 mdioslave, u32 offset, u32 mask,
u32 val)
{
u32 reg_val = 0;
pcicore_info_t *pi = (pcicore_info_t *) pch;
if (mask) {
PCI_ERROR(("PCIEMDIOREG: 0x%x writeval 0x%x\n", offset, val));
pcie_mdiowrite(pi, mdioslave, offset, val);
}
if (pcie_mdioread(pi, mdioslave, offset, &reg_val))
reg_val = 0xFFFFFFFF;
PCI_ERROR(("PCIEMDIOREG: dev 0x%x offset 0x%x read 0x%x\n", mdioslave,
offset, reg_val));
return reg_val;
}
