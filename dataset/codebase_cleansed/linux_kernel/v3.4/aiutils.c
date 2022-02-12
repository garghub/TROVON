static bool ai_ispcie(struct si_info *sii)
{
u8 cap_ptr;
cap_ptr =
pcicore_find_pci_capability(sii->pcibus, PCI_CAP_ID_EXP, NULL,
NULL);
if (!cap_ptr)
return false;
return true;
}
static bool ai_buscore_prep(struct si_info *sii)
{
if (!ai_ispcie(sii))
ai_clkctl_xtal(&sii->pub, XTAL | PLL, ON);
return true;
}
static bool
ai_buscore_setup(struct si_info *sii, struct bcma_device *cc)
{
struct bcma_device *pci = NULL;
struct bcma_device *pcie = NULL;
struct bcma_device *core;
if (cc->bus->nr_cores == 0)
return false;
sii->pub.ccrev = cc->id.rev;
if (ai_get_ccrev(&sii->pub) >= 11)
sii->chipst = bcma_read32(cc, CHIPCREGOFFS(chipstatus));
sii->pub.cccaps = bcma_read32(cc, CHIPCREGOFFS(capabilities));
if (ai_get_cccaps(&sii->pub) & CC_CAP_PMU) {
sii->pub.pmucaps = bcma_read32(cc,
CHIPCREGOFFS(pmucapabilities));
sii->pub.pmurev = sii->pub.pmucaps & PCAP_REV_MASK;
}
list_for_each_entry(core, &cc->bus->cores, list) {
uint cid, crev;
cid = core->id.id;
crev = core->id.rev;
if (cid == PCI_CORE_ID) {
pci = core;
} else if (cid == PCIE_CORE_ID) {
pcie = core;
}
}
if (pci && pcie) {
if (ai_ispcie(sii))
pci = NULL;
else
pcie = NULL;
}
if (pci) {
sii->buscore = pci;
} else if (pcie) {
sii->buscore = pcie;
}
if (!sii->pch) {
sii->pch = pcicore_init(&sii->pub, sii->icbus->drv_pci.core);
if (sii->pch == NULL)
return false;
}
if (ai_pci_fixcfg(&sii->pub))
return false;
return true;
}
static __used void ai_nvram_process(struct si_info *sii)
{
uint w = 0;
pci_read_config_dword(sii->pcibus, PCI_SUBSYSTEM_VENDOR_ID, &w);
sii->pub.boardvendor = w & 0xffff;
sii->pub.boardtype = (w >> 16) & 0xffff;
}
static struct si_info *ai_doattach(struct si_info *sii,
struct bcma_bus *pbus)
{
struct si_pub *sih = &sii->pub;
u32 w, savewin;
struct bcma_device *cc;
uint socitype;
savewin = 0;
sii->icbus = pbus;
sii->pcibus = pbus->host_pci;
cc = pbus->drv_cc.core;
if (!ai_buscore_prep(sii))
return NULL;
w = bcma_read32(cc, CHIPCREGOFFS(chipid));
socitype = (w & CID_TYPE_MASK) >> CID_TYPE_SHIFT;
sih->chip = w & CID_ID_MASK;
sih->chiprev = (w & CID_REV_MASK) >> CID_REV_SHIFT;
sih->chippkg = (w & CID_PKG_MASK) >> CID_PKG_SHIFT;
if (socitype != SOCI_AI)
return NULL;
SI_MSG("Found chip type AI (0x%08x)\n", w);
if (!ai_buscore_setup(sii, cc))
goto exit;
if (srom_var_init(&sii->pub))
goto exit;
ai_nvram_process(sii);
bcma_write32(cc, CHIPCREGOFFS(gpiopullup), 0);
bcma_write32(cc, CHIPCREGOFFS(gpiopulldown), 0);
if (ai_get_cccaps(sih) & CC_CAP_PMU) {
si_pmu_init(sih);
(void)si_pmu_measure_alpclk(sih);
si_pmu_res_init(sih);
}
w = getintvar(sih, BRCMS_SROM_LEDDC);
if (w == 0)
w = DEFAULT_GPIOTIMERVAL;
ai_cc_reg(sih, offsetof(struct chipcregs, gpiotimerval),
~0, w);
if (PCIE(sih))
pcicore_attach(sii->pch, SI_DOATTACH);
if (ai_get_chip_id(sih) == BCM43224_CHIP_ID) {
if (ai_get_chiprev(sih) == 0) {
SI_MSG("Applying 43224A0 WARs\n");
ai_cc_reg(sih, offsetof(struct chipcregs, chipcontrol),
CCTRL43224_GPIO_TOGGLE,
CCTRL43224_GPIO_TOGGLE);
si_pmu_chipcontrol(sih, 0, CCTRL_43224A0_12MA_LED_DRIVE,
CCTRL_43224A0_12MA_LED_DRIVE);
}
if (ai_get_chiprev(sih) >= 1) {
SI_MSG("Applying 43224B0+ WARs\n");
si_pmu_chipcontrol(sih, 0, CCTRL_43224B0_12MA_LED_DRIVE,
CCTRL_43224B0_12MA_LED_DRIVE);
}
}
if (ai_get_chip_id(sih) == BCM4313_CHIP_ID) {
SI_MSG("Applying 4313 WARs\n");
si_pmu_chipcontrol(sih, 0, CCTRL_4313_12MA_LED_DRIVE,
CCTRL_4313_12MA_LED_DRIVE);
}
return sii;
exit:
if (sii->pch)
pcicore_deinit(sii->pch);
sii->pch = NULL;
return NULL;
}
struct si_pub *
ai_attach(struct bcma_bus *pbus)
{
struct si_info *sii;
sii = kzalloc(sizeof(struct si_info), GFP_ATOMIC);
if (sii == NULL)
return NULL;
if (ai_doattach(sii, pbus) == NULL) {
kfree(sii);
return NULL;
}
return (struct si_pub *) sii;
}
void ai_detach(struct si_pub *sih)
{
struct si_info *sii;
struct si_pub *si_local = NULL;
memcpy(&si_local, &sih, sizeof(struct si_pub **));
sii = (struct si_info *)sih;
if (sii == NULL)
return;
if (sii->pch)
pcicore_deinit(sii->pch);
sii->pch = NULL;
srom_free_vars(sih);
kfree(sii);
}
struct bcma_device *ai_findcore(struct si_pub *sih, u16 coreid, u16 coreunit)
{
struct bcma_device *core;
struct si_info *sii;
uint found;
sii = (struct si_info *)sih;
found = 0;
list_for_each_entry(core, &sii->icbus->cores, list)
if (core->id.id == coreid) {
if (found == coreunit)
return core;
found++;
}
return NULL;
}
uint ai_cc_reg(struct si_pub *sih, uint regoff, u32 mask, u32 val)
{
struct bcma_device *cc;
u32 w;
struct si_info *sii;
sii = (struct si_info *)sih;
cc = sii->icbus->drv_cc.core;
if (mask || val) {
bcma_maskset32(cc, regoff, ~mask, val);
}
w = bcma_read32(cc, regoff);
return w;
}
static uint ai_slowclk_src(struct si_pub *sih, struct bcma_device *cc)
{
struct si_info *sii;
u32 val;
sii = (struct si_info *)sih;
if (ai_get_ccrev(&sii->pub) < 6) {
pci_read_config_dword(sii->pcibus, PCI_GPIO_OUT,
&val);
if (val & PCI_CFG_GPIO_SCS)
return SCC_SS_PCI;
return SCC_SS_XTAL;
} else if (ai_get_ccrev(&sii->pub) < 10) {
return bcma_read32(cc, CHIPCREGOFFS(slow_clk_ctl)) &
SCC_SS_MASK;
} else
return SCC_SS_XTAL;
}
static uint ai_slowclk_freq(struct si_pub *sih, bool max_freq,
struct bcma_device *cc)
{
u32 slowclk;
uint div;
slowclk = ai_slowclk_src(sih, cc);
if (ai_get_ccrev(sih) < 6) {
if (slowclk == SCC_SS_PCI)
return max_freq ? (PCIMAXFREQ / 64)
: (PCIMINFREQ / 64);
else
return max_freq ? (XTALMAXFREQ / 32)
: (XTALMINFREQ / 32);
} else if (ai_get_ccrev(sih) < 10) {
div = 4 *
(((bcma_read32(cc, CHIPCREGOFFS(slow_clk_ctl)) &
SCC_CD_MASK) >> SCC_CD_SHIFT) + 1);
if (slowclk == SCC_SS_LPO)
return max_freq ? LPOMAXFREQ : LPOMINFREQ;
else if (slowclk == SCC_SS_XTAL)
return max_freq ? (XTALMAXFREQ / div)
: (XTALMINFREQ / div);
else if (slowclk == SCC_SS_PCI)
return max_freq ? (PCIMAXFREQ / div)
: (PCIMINFREQ / div);
} else {
div = bcma_read32(cc, CHIPCREGOFFS(system_clk_ctl));
div = 4 * ((div >> SYCC_CD_SHIFT) + 1);
return max_freq ? XTALMAXFREQ : (XTALMINFREQ / div);
}
return 0;
}
static void
ai_clkctl_setdelay(struct si_pub *sih, struct bcma_device *cc)
{
uint slowmaxfreq, pll_delay, slowclk;
uint pll_on_delay, fref_sel_delay;
pll_delay = PLL_DELAY;
slowclk = ai_slowclk_src(sih, cc);
if (slowclk != SCC_SS_XTAL)
pll_delay += XTAL_ON_DELAY;
slowmaxfreq =
ai_slowclk_freq(sih,
(ai_get_ccrev(sih) >= 10) ? false : true, cc);
pll_on_delay = ((slowmaxfreq * pll_delay) + 999999) / 1000000;
fref_sel_delay = ((slowmaxfreq * FREF_DELAY) + 999999) / 1000000;
bcma_write32(cc, CHIPCREGOFFS(pll_on_delay), pll_on_delay);
bcma_write32(cc, CHIPCREGOFFS(fref_sel_delay), fref_sel_delay);
}
void ai_clkctl_init(struct si_pub *sih)
{
struct bcma_device *cc;
if (!(ai_get_cccaps(sih) & CC_CAP_PWR_CTL))
return;
cc = ai_findcore(sih, BCMA_CORE_CHIPCOMMON, 0);
if (cc == NULL)
return;
if (ai_get_ccrev(sih) >= 10)
bcma_maskset32(cc, CHIPCREGOFFS(system_clk_ctl), SYCC_CD_MASK,
(ILP_DIV_1MHZ << SYCC_CD_SHIFT));
ai_clkctl_setdelay(sih, cc);
}
u16 ai_clkctl_fast_pwrup_delay(struct si_pub *sih)
{
struct si_info *sii;
struct bcma_device *cc;
uint slowminfreq;
u16 fpdelay;
sii = (struct si_info *)sih;
if (ai_get_cccaps(sih) & CC_CAP_PMU) {
fpdelay = si_pmu_fast_pwrup_delay(sih);
return fpdelay;
}
if (!(ai_get_cccaps(sih) & CC_CAP_PWR_CTL))
return 0;
fpdelay = 0;
cc = ai_findcore(sih, CC_CORE_ID, 0);
if (cc) {
slowminfreq = ai_slowclk_freq(sih, false, cc);
fpdelay = (((bcma_read32(cc, CHIPCREGOFFS(pll_on_delay)) + 2)
* 1000000) + (slowminfreq - 1)) / slowminfreq;
}
return fpdelay;
}
int ai_clkctl_xtal(struct si_pub *sih, uint what, bool on)
{
struct si_info *sii;
u32 in, out, outen;
sii = (struct si_info *)sih;
if (PCIE(sih))
return -1;
pci_read_config_dword(sii->pcibus, PCI_GPIO_IN, &in);
pci_read_config_dword(sii->pcibus, PCI_GPIO_OUT, &out);
pci_read_config_dword(sii->pcibus, PCI_GPIO_OUTEN, &outen);
if (on && (in & PCI_CFG_GPIO_XTAL))
return 0;
if (what & XTAL)
outen |= PCI_CFG_GPIO_XTAL;
if (what & PLL)
outen |= PCI_CFG_GPIO_PLL;
if (on) {
if (what & XTAL) {
out |= PCI_CFG_GPIO_XTAL;
if (what & PLL)
out |= PCI_CFG_GPIO_PLL;
pci_write_config_dword(sii->pcibus,
PCI_GPIO_OUT, out);
pci_write_config_dword(sii->pcibus,
PCI_GPIO_OUTEN, outen);
udelay(XTAL_ON_DELAY);
}
if (what & PLL) {
out &= ~PCI_CFG_GPIO_PLL;
pci_write_config_dword(sii->pcibus,
PCI_GPIO_OUT, out);
mdelay(2);
}
} else {
if (what & XTAL)
out &= ~PCI_CFG_GPIO_XTAL;
if (what & PLL)
out |= PCI_CFG_GPIO_PLL;
pci_write_config_dword(sii->pcibus,
PCI_GPIO_OUT, out);
pci_write_config_dword(sii->pcibus,
PCI_GPIO_OUTEN, outen);
}
return 0;
}
static bool _ai_clkctl_cc(struct si_info *sii, uint mode)
{
struct bcma_device *cc;
u32 scc;
if (ai_get_ccrev(&sii->pub) < 6)
return false;
cc = ai_findcore(&sii->pub, BCMA_CORE_CHIPCOMMON, 0);
if (!(ai_get_cccaps(&sii->pub) & CC_CAP_PWR_CTL) &&
(ai_get_ccrev(&sii->pub) < 20))
return mode == CLK_FAST;
switch (mode) {
case CLK_FAST:
if (ai_get_ccrev(&sii->pub) < 10) {
ai_clkctl_xtal(&sii->pub, XTAL, ON);
bcma_maskset32(cc, CHIPCREGOFFS(slow_clk_ctl),
(SCC_XC | SCC_FS | SCC_IP), SCC_IP);
} else if (ai_get_ccrev(&sii->pub) < 20) {
bcma_set32(cc, CHIPCREGOFFS(system_clk_ctl), SYCC_HR);
} else {
bcma_set32(cc, CHIPCREGOFFS(clk_ctl_st), CCS_FORCEHT);
}
if (ai_get_cccaps(&sii->pub) & CC_CAP_PMU) {
u32 htavail = CCS_HTAVAIL;
SPINWAIT(((bcma_read32(cc, CHIPCREGOFFS(clk_ctl_st)) &
htavail) == 0), PMU_MAX_TRANSITION_DLY);
} else {
udelay(PLL_DELAY);
}
break;
case CLK_DYNAMIC:
if (ai_get_ccrev(&sii->pub) < 10) {
scc = bcma_read32(cc, CHIPCREGOFFS(slow_clk_ctl));
scc &= ~(SCC_FS | SCC_IP | SCC_XC);
if ((scc & SCC_SS_MASK) != SCC_SS_XTAL)
scc |= SCC_XC;
bcma_write32(cc, CHIPCREGOFFS(slow_clk_ctl), scc);
if (scc & SCC_XC)
ai_clkctl_xtal(&sii->pub, XTAL, OFF);
} else if (ai_get_ccrev(&sii->pub) < 20) {
bcma_mask32(cc, CHIPCREGOFFS(system_clk_ctl), ~SYCC_HR);
} else {
bcma_mask32(cc, CHIPCREGOFFS(clk_ctl_st), ~CCS_FORCEHT);
}
break;
default:
break;
}
return mode == CLK_FAST;
}
bool ai_clkctl_cc(struct si_pub *sih, uint mode)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (ai_get_ccrev(sih) < 6)
return false;
if (PCI_FORCEHT(sih))
return mode == CLK_FAST;
return _ai_clkctl_cc(sii, mode);
}
void ai_pci_up(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (PCI_FORCEHT(sih))
_ai_clkctl_cc(sii, CLK_FAST);
if (PCIE(sih))
pcicore_up(sii->pch, SI_PCIUP);
}
void ai_pci_sleep(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
pcicore_sleep(sii->pch);
}
void ai_pci_down(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (PCI_FORCEHT(sih))
_ai_clkctl_cc(sii, CLK_DYNAMIC);
pcicore_down(sii->pch, SI_PCIDOWN);
}
void ai_pci_setup(struct si_pub *sih, uint coremask)
{
struct si_info *sii;
u32 w;
sii = (struct si_info *)sih;
if (PCIE(sih) || (PCI(sih) && (ai_get_buscorerev(sih) >= 6))) {
pci_read_config_dword(sii->pcibus, PCI_INT_MASK, &w);
w |= (coremask << PCI_SBIM_SHIFT);
pci_write_config_dword(sii->pcibus, PCI_INT_MASK, w);
}
if (PCI(sih)) {
pcicore_pci_setup(sii->pch);
}
}
int ai_pci_fixcfg(struct si_pub *sih)
{
struct si_info *sii = (struct si_info *)sih;
pcicore_fixcfg(sii->pch);
pcicore_hwup(sii->pch);
return 0;
}
u32 ai_gpiocontrol(struct si_pub *sih, u32 mask, u32 val, u8 priority)
{
uint regoff;
regoff = offsetof(struct chipcregs, gpiocontrol);
return ai_cc_reg(sih, regoff, mask, val);
}
void ai_chipcontrl_epa4331(struct si_pub *sih, bool on)
{
struct bcma_device *cc;
u32 val;
cc = ai_findcore(sih, CC_CORE_ID, 0);
if (on) {
if (ai_get_chippkg(sih) == 9 || ai_get_chippkg(sih) == 0xb)
bcma_set32(cc, CHIPCREGOFFS(chipcontrol),
CCTRL4331_EXTPA_EN |
CCTRL4331_EXTPA_ON_GPIO2_5);
else
bcma_set32(cc, CHIPCREGOFFS(chipcontrol),
CCTRL4331_EXTPA_EN);
} else {
val &= ~(CCTRL4331_EXTPA_EN | CCTRL4331_EXTPA_ON_GPIO2_5);
bcma_mask32(cc, CHIPCREGOFFS(chipcontrol),
~(CCTRL4331_EXTPA_EN | CCTRL4331_EXTPA_ON_GPIO2_5));
}
}
void ai_epa_4313war(struct si_pub *sih)
{
struct bcma_device *cc;
cc = ai_findcore(sih, CC_CORE_ID, 0);
bcma_set32(cc, CHIPCREGOFFS(gpiocontrol), GPIO_CTRL_EPA_EN_MASK);
}
bool ai_deviceremoved(struct si_pub *sih)
{
u32 w;
struct si_info *sii;
sii = (struct si_info *)sih;
pci_read_config_dword(sii->pcibus, PCI_VENDOR_ID, &w);
if ((w & 0xFFFF) != PCI_VENDOR_ID_BROADCOM)
return true;
return false;
}
bool ai_is_sprom_available(struct si_pub *sih)
{
struct si_info *sii = (struct si_info *)sih;
if (ai_get_ccrev(sih) >= 31) {
struct bcma_device *cc;
u32 sromctrl;
if ((ai_get_cccaps(sih) & CC_CAP_SROM) == 0)
return false;
cc = ai_findcore(sih, BCMA_CORE_CHIPCOMMON, 0);
sromctrl = bcma_read32(cc, CHIPCREGOFFS(sromcontrol));
return sromctrl & SRC_PRESENT;
}
switch (ai_get_chip_id(sih)) {
case BCM4313_CHIP_ID:
return (sii->chipst & CST4313_SPROM_PRESENT) != 0;
default:
return true;
}
}
bool ai_is_otp_disabled(struct si_pub *sih)
{
struct si_info *sii = (struct si_info *)sih;
switch (ai_get_chip_id(sih)) {
case BCM4313_CHIP_ID:
return (sii->chipst & CST4313_OTP_PRESENT) == 0;
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
default:
return false;
}
}
uint ai_get_buscoretype(struct si_pub *sih)
{
struct si_info *sii = (struct si_info *)sih;
return sii->buscore->id.id;
}
uint ai_get_buscorerev(struct si_pub *sih)
{
struct si_info *sii = (struct si_info *)sih;
return sii->buscore->id.rev;
}
