static bool
ai_buscore_setup(struct si_info *sii, struct bcma_device *cc)
{
if (cc->bus->nr_cores == 0)
return false;
sii->pub.ccrev = cc->id.rev;
sii->chipst = bcma_read32(cc, CHIPCREGOFFS(chipstatus));
sii->pub.cccaps = bcma_read32(cc, CHIPCREGOFFS(capabilities));
if (ai_get_cccaps(&sii->pub) & CC_CAP_PMU) {
sii->pub.pmucaps = bcma_read32(cc,
CHIPCREGOFFS(pmucapabilities));
sii->pub.pmurev = sii->pub.pmucaps & PCAP_REV_MASK;
}
return true;
}
static struct si_info *ai_doattach(struct si_info *sii,
struct bcma_bus *pbus)
{
struct si_pub *sih = &sii->pub;
struct bcma_device *cc;
sii->icbus = pbus;
sii->pcibus = pbus->host_pci;
cc = pbus->drv_cc.core;
sih->chip = pbus->chipinfo.id;
sih->chiprev = pbus->chipinfo.rev;
sih->chippkg = pbus->chipinfo.pkg;
sih->boardvendor = pbus->boardinfo.vendor;
sih->boardtype = pbus->boardinfo.type;
if (!ai_buscore_setup(sii, cc))
goto exit;
bcma_write32(cc, CHIPCREGOFFS(gpiopullup), 0);
bcma_write32(cc, CHIPCREGOFFS(gpiopulldown), 0);
if (ai_get_cccaps(sih) & CC_CAP_PMU) {
(void)si_pmu_measure_alpclk(sih);
}
return sii;
exit:
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
sii = container_of(sih, struct si_info, pub);
if (sii == NULL)
return;
kfree(sii);
}
uint ai_cc_reg(struct si_pub *sih, uint regoff, u32 mask, u32 val)
{
struct bcma_device *cc;
u32 w;
struct si_info *sii;
sii = container_of(sih, struct si_info, pub);
cc = sii->icbus->drv_cc.core;
if (mask || val)
bcma_maskset32(cc, regoff, ~mask, val);
w = bcma_read32(cc, regoff);
return w;
}
static uint ai_slowclk_src(struct si_pub *sih, struct bcma_device *cc)
{
return SCC_SS_XTAL;
}
static uint ai_slowclk_freq(struct si_pub *sih, bool max_freq,
struct bcma_device *cc)
{
uint div;
div = bcma_read32(cc, CHIPCREGOFFS(system_clk_ctl));
div = 4 * ((div >> SYCC_CD_SHIFT) + 1);
return max_freq ? XTALMAXFREQ : (XTALMINFREQ / div);
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
ai_slowclk_freq(sih, false, cc);
pll_on_delay = ((slowmaxfreq * pll_delay) + 999999) / 1000000;
fref_sel_delay = ((slowmaxfreq * FREF_DELAY) + 999999) / 1000000;
bcma_write32(cc, CHIPCREGOFFS(pll_on_delay), pll_on_delay);
bcma_write32(cc, CHIPCREGOFFS(fref_sel_delay), fref_sel_delay);
}
void ai_clkctl_init(struct si_pub *sih)
{
struct si_info *sii = container_of(sih, struct si_info, pub);
struct bcma_device *cc;
if (!(ai_get_cccaps(sih) & CC_CAP_PWR_CTL))
return;
cc = sii->icbus->drv_cc.core;
if (cc == NULL)
return;
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
sii = container_of(sih, struct si_info, pub);
if (ai_get_cccaps(sih) & CC_CAP_PMU) {
fpdelay = si_pmu_fast_pwrup_delay(sih);
return fpdelay;
}
if (!(ai_get_cccaps(sih) & CC_CAP_PWR_CTL))
return 0;
fpdelay = 0;
cc = sii->icbus->drv_cc.core;
if (cc) {
slowminfreq = ai_slowclk_freq(sih, false, cc);
fpdelay = (((bcma_read32(cc, CHIPCREGOFFS(pll_on_delay)) + 2)
* 1000000) + (slowminfreq - 1)) / slowminfreq;
}
return fpdelay;
}
bool ai_clkctl_cc(struct si_pub *sih, enum bcma_clkmode mode)
{
struct si_info *sii;
struct bcma_device *cc;
sii = container_of(sih, struct si_info, pub);
cc = sii->icbus->drv_cc.core;
bcma_core_set_clockmode(cc, mode);
return mode == BCMA_CLKMODE_FAST;
}
void ai_pci_up(struct si_pub *sih)
{
struct si_info *sii;
sii = container_of(sih, struct si_info, pub);
if (sii->icbus->hosttype == BCMA_HOSTTYPE_PCI)
bcma_core_pci_extend_L1timer(&sii->icbus->drv_pci, true);
}
void ai_pci_down(struct si_pub *sih)
{
struct si_info *sii;
sii = container_of(sih, struct si_info, pub);
if (sii->icbus->hosttype == BCMA_HOSTTYPE_PCI)
bcma_core_pci_extend_L1timer(&sii->icbus->drv_pci, false);
}
void ai_epa_4313war(struct si_pub *sih)
{
struct si_info *sii = container_of(sih, struct si_info, pub);
struct bcma_device *cc;
cc = sii->icbus->drv_cc.core;
bcma_set32(cc, CHIPCREGOFFS(gpiocontrol), GPIO_CTRL_EPA_EN_MASK);
}
bool ai_deviceremoved(struct si_pub *sih)
{
u32 w;
struct si_info *sii;
sii = container_of(sih, struct si_info, pub);
if (sii->icbus->hosttype != BCMA_HOSTTYPE_PCI)
return false;
pci_read_config_dword(sii->pcibus, PCI_VENDOR_ID, &w);
if ((w & 0xFFFF) != PCI_VENDOR_ID_BROADCOM)
return true;
return false;
}
