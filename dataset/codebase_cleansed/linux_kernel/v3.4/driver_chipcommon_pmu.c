static u32 bcma_chipco_pll_read(struct bcma_drv_cc *cc, u32 offset)
{
bcma_cc_write32(cc, BCMA_CC_PLLCTL_ADDR, offset);
bcma_cc_read32(cc, BCMA_CC_PLLCTL_ADDR);
return bcma_cc_read32(cc, BCMA_CC_PLLCTL_DATA);
}
void bcma_chipco_pll_write(struct bcma_drv_cc *cc, u32 offset, u32 value)
{
bcma_cc_write32(cc, BCMA_CC_PLLCTL_ADDR, offset);
bcma_cc_read32(cc, BCMA_CC_PLLCTL_ADDR);
bcma_cc_write32(cc, BCMA_CC_PLLCTL_DATA, value);
}
void bcma_chipco_pll_maskset(struct bcma_drv_cc *cc, u32 offset, u32 mask,
u32 set)
{
bcma_cc_write32(cc, BCMA_CC_PLLCTL_ADDR, offset);
bcma_cc_read32(cc, BCMA_CC_PLLCTL_ADDR);
bcma_cc_maskset32(cc, BCMA_CC_PLLCTL_DATA, mask, set);
}
void bcma_chipco_chipctl_maskset(struct bcma_drv_cc *cc,
u32 offset, u32 mask, u32 set)
{
bcma_cc_write32(cc, BCMA_CC_CHIPCTL_ADDR, offset);
bcma_cc_read32(cc, BCMA_CC_CHIPCTL_ADDR);
bcma_cc_maskset32(cc, BCMA_CC_CHIPCTL_DATA, mask, set);
}
void bcma_chipco_regctl_maskset(struct bcma_drv_cc *cc, u32 offset, u32 mask,
u32 set)
{
bcma_cc_write32(cc, BCMA_CC_REGCTL_ADDR, offset);
bcma_cc_read32(cc, BCMA_CC_REGCTL_ADDR);
bcma_cc_maskset32(cc, BCMA_CC_REGCTL_DATA, mask, set);
}
static void bcma_pmu_pll_init(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
switch (bus->chipinfo.id) {
case 0x4313:
case 0x4331:
case 43224:
case 43225:
break;
default:
pr_err("PLL init unknown for device 0x%04X\n",
bus->chipinfo.id);
}
}
static void bcma_pmu_resources_init(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
u32 min_msk = 0, max_msk = 0;
switch (bus->chipinfo.id) {
case 0x4313:
min_msk = 0x200D;
max_msk = 0xFFFF;
break;
case 0x4331:
case 43224:
case 43225:
break;
default:
pr_err("PMU resource config unknown for device 0x%04X\n",
bus->chipinfo.id);
}
if (min_msk)
bcma_cc_write32(cc, BCMA_CC_PMU_MINRES_MSK, min_msk);
if (max_msk)
bcma_cc_write32(cc, BCMA_CC_PMU_MAXRES_MSK, max_msk);
}
void bcma_pmu_swreg_init(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
switch (bus->chipinfo.id) {
case 0x4313:
case 0x4331:
case 43224:
case 43225:
break;
default:
pr_err("PMU switch/regulators init unknown for device "
"0x%04X\n", bus->chipinfo.id);
}
}
void bcma_chipco_bcm4331_ext_pa_lines_ctl(struct bcma_drv_cc *cc, bool enable)
{
struct bcma_bus *bus = cc->core->bus;
u32 val;
val = bcma_cc_read32(cc, BCMA_CC_CHIPCTL);
if (enable) {
val |= BCMA_CHIPCTL_4331_EXTPA_EN;
if (bus->chipinfo.pkg == 9 || bus->chipinfo.pkg == 11)
val |= BCMA_CHIPCTL_4331_EXTPA_ON_GPIO2_5;
} else {
val &= ~BCMA_CHIPCTL_4331_EXTPA_EN;
val &= ~BCMA_CHIPCTL_4331_EXTPA_ON_GPIO2_5;
}
bcma_cc_write32(cc, BCMA_CC_CHIPCTL, val);
}
void bcma_pmu_workarounds(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
switch (bus->chipinfo.id) {
case 0x4313:
bcma_chipco_chipctl_maskset(cc, 0, ~0, 0x7);
break;
case 0x4331:
break;
case 43224:
if (bus->chipinfo.rev == 0) {
pr_err("Workarounds for 43224 rev 0 not fully "
"implemented\n");
bcma_chipco_chipctl_maskset(cc, 0, ~0, 0x00F000F0);
} else {
bcma_chipco_chipctl_maskset(cc, 0, ~0, 0xF0);
}
break;
case 43225:
break;
default:
pr_err("Workarounds unknown for device 0x%04X\n",
bus->chipinfo.id);
}
}
void bcma_pmu_init(struct bcma_drv_cc *cc)
{
u32 pmucap;
pmucap = bcma_cc_read32(cc, BCMA_CC_PMU_CAP);
cc->pmu.rev = (pmucap & BCMA_CC_PMU_CAP_REVISION);
pr_debug("Found rev %u PMU (capabilities 0x%08X)\n", cc->pmu.rev,
pmucap);
if (cc->pmu.rev == 1)
bcma_cc_mask32(cc, BCMA_CC_PMU_CTL,
~BCMA_CC_PMU_CTL_NOILPONW);
else
bcma_cc_set32(cc, BCMA_CC_PMU_CTL,
BCMA_CC_PMU_CTL_NOILPONW);
if (cc->core->id.id == 0x4329 && cc->core->id.rev == 2)
pr_err("Fix for 4329b0 bad LPOM state not implemented!\n");
bcma_pmu_pll_init(cc);
bcma_pmu_resources_init(cc);
bcma_pmu_swreg_init(cc);
bcma_pmu_workarounds(cc);
}
u32 bcma_pmu_alp_clock(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
switch (bus->chipinfo.id) {
case 0x4716:
case 0x4748:
case 47162:
case 0x4313:
case 0x5357:
case 0x4749:
case 53572:
return 20000 * 1000;
case 0x5356:
case 0x5300:
return 25000 * 1000;
default:
pr_warn("No ALP clock specified for %04X device, "
"pmu rev. %d, using default %d Hz\n",
bus->chipinfo.id, cc->pmu.rev, BCMA_CC_PMU_ALP_CLOCK);
}
return BCMA_CC_PMU_ALP_CLOCK;
}
static u32 bcma_pmu_clock(struct bcma_drv_cc *cc, u32 pll0, u32 m)
{
u32 tmp, div, ndiv, p1, p2, fc;
struct bcma_bus *bus = cc->core->bus;
BUG_ON((pll0 & 3) || (pll0 > BCMA_CC_PMU4716_MAINPLL_PLL0));
BUG_ON(!m || m > 4);
if (bus->chipinfo.id == 0x5357 || bus->chipinfo.id == 0x4749) {
tmp = bcma_cc_read32(cc, BCMA_CC_CHIPSTAT);
if (tmp & 0x40000)
return 133 * 1000000;
}
tmp = bcma_chipco_pll_read(cc, pll0 + BCMA_CC_PPL_P1P2_OFF);
p1 = (tmp & BCMA_CC_PPL_P1_MASK) >> BCMA_CC_PPL_P1_SHIFT;
p2 = (tmp & BCMA_CC_PPL_P2_MASK) >> BCMA_CC_PPL_P2_SHIFT;
tmp = bcma_chipco_pll_read(cc, pll0 + BCMA_CC_PPL_M14_OFF);
div = (tmp >> ((m - 1) * BCMA_CC_PPL_MDIV_WIDTH)) &
BCMA_CC_PPL_MDIV_MASK;
tmp = bcma_chipco_pll_read(cc, pll0 + BCMA_CC_PPL_NM5_OFF);
ndiv = (tmp & BCMA_CC_PPL_NDIV_MASK) >> BCMA_CC_PPL_NDIV_SHIFT;
fc = bcma_pmu_alp_clock(cc) / 1000000;
fc = (p1 * ndiv * fc) / p2;
return (fc / div) * 1000000;
}
u32 bcma_pmu_get_clockcontrol(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
switch (bus->chipinfo.id) {
case 0x4716:
case 0x4748:
case 47162:
return bcma_pmu_clock(cc, BCMA_CC_PMU4716_MAINPLL_PLL0,
BCMA_CC_PMU5_MAINPLL_SSB);
case 0x5356:
return bcma_pmu_clock(cc, BCMA_CC_PMU5356_MAINPLL_PLL0,
BCMA_CC_PMU5_MAINPLL_SSB);
case 0x5357:
case 0x4749:
return bcma_pmu_clock(cc, BCMA_CC_PMU5357_MAINPLL_PLL0,
BCMA_CC_PMU5_MAINPLL_SSB);
case 0x5300:
return bcma_pmu_clock(cc, BCMA_CC_PMU4706_MAINPLL_PLL0,
BCMA_CC_PMU5_MAINPLL_SSB);
case 53572:
return 75000000;
default:
pr_warn("No backplane clock specified for %04X device, "
"pmu rev. %d, using default %d Hz\n",
bus->chipinfo.id, cc->pmu.rev, BCMA_CC_PMU_HT_CLOCK);
}
return BCMA_CC_PMU_HT_CLOCK;
}
u32 bcma_pmu_get_clockcpu(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
if (bus->chipinfo.id == 53572)
return 300000000;
if (cc->pmu.rev >= 5) {
u32 pll;
switch (bus->chipinfo.id) {
case 0x5356:
pll = BCMA_CC_PMU5356_MAINPLL_PLL0;
break;
case 0x5357:
case 0x4749:
pll = BCMA_CC_PMU5357_MAINPLL_PLL0;
break;
default:
pll = BCMA_CC_PMU4716_MAINPLL_PLL0;
break;
}
return bcma_pmu_clock(cc, pll, BCMA_CC_PMU5_MAINPLL_CPU);
}
return bcma_pmu_get_clockcontrol(cc);
}
