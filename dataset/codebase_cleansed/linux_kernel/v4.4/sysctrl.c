void ltq_pmu_enable(unsigned int module)
{
int retry = 1000000;
spin_lock(&g_pmu_lock);
pmu_w32(pmu_r32(PMU_PWDCR) & ~module, PMU_PWDCR);
do {} while (--retry && (pmu_r32(PMU_PWDSR) & module));
spin_unlock(&g_pmu_lock);
if (!retry)
panic("activating PMU module failed!");
}
void ltq_pmu_disable(unsigned int module)
{
int retry = 1000000;
spin_lock(&g_pmu_lock);
pmu_w32(pmu_r32(PMU_PWDCR) | module, PMU_PWDCR);
do {} while (--retry && (!(pmu_r32(PMU_PWDSR) & module)));
spin_unlock(&g_pmu_lock);
if (!retry)
pr_warn("deactivating PMU module failed!");
}
static int cgu_enable(struct clk *clk)
{
ltq_cgu_w32(ltq_cgu_r32(ifccr) | clk->bits, ifccr);
return 0;
}
static void cgu_disable(struct clk *clk)
{
ltq_cgu_w32(ltq_cgu_r32(ifccr) & ~clk->bits, ifccr);
}
static int pmu_enable(struct clk *clk)
{
int retry = 1000000;
if (of_machine_is_compatible("lantiq,ar10")
|| of_machine_is_compatible("lantiq,grx390")) {
pmu_w32(clk->bits, PWDCR_EN_XRX(clk->module));
do {} while (--retry &&
(!(pmu_r32(PWDSR_XRX(clk->module)) & clk->bits)));
} else {
spin_lock(&g_pmu_lock);
pmu_w32(pmu_r32(PWDCR(clk->module)) & ~clk->bits,
PWDCR(clk->module));
do {} while (--retry &&
(pmu_r32(PWDSR(clk->module)) & clk->bits));
spin_unlock(&g_pmu_lock);
}
if (!retry)
panic("activating PMU module failed!");
return 0;
}
static void pmu_disable(struct clk *clk)
{
int retry = 1000000;
if (of_machine_is_compatible("lantiq,ar10")
|| of_machine_is_compatible("lantiq,grx390")) {
pmu_w32(clk->bits, PWDCR_DIS_XRX(clk->module));
do {} while (--retry &&
(pmu_r32(PWDSR_XRX(clk->module)) & clk->bits));
} else {
spin_lock(&g_pmu_lock);
pmu_w32(pmu_r32(PWDCR(clk->module)) | clk->bits,
PWDCR(clk->module));
do {} while (--retry &&
(!(pmu_r32(PWDSR(clk->module)) & clk->bits)));
spin_unlock(&g_pmu_lock);
}
if (!retry)
pr_warn("deactivating PMU module failed!");
}
static int pci_enable(struct clk *clk)
{
unsigned int val = ltq_cgu_r32(ifccr);
if (of_machine_is_compatible("lantiq,ar9") ||
of_machine_is_compatible("lantiq,vr9")) {
val &= ~0x1f00000;
if (clk->rate == CLOCK_33M)
val |= 0xe00000;
else
val |= 0x700000;
} else {
val &= ~0xf00000;
if (clk->rate == CLOCK_33M)
val |= 0x800000;
else
val |= 0x400000;
}
ltq_cgu_w32(val, ifccr);
pmu_enable(clk);
return 0;
}
static int pci_ext_enable(struct clk *clk)
{
ltq_cgu_w32(ltq_cgu_r32(ifccr) & ~(1 << 16), ifccr);
ltq_cgu_w32((1 << 30), pcicr);
return 0;
}
static void pci_ext_disable(struct clk *clk)
{
ltq_cgu_w32(ltq_cgu_r32(ifccr) | (1 << 16), ifccr);
ltq_cgu_w32((1 << 31) | (1 << 30), pcicr);
}
static void xbar_fpi_burst_disable(void)
{
u32 reg;
reg = xbar_r32(XBAR_ALWAYS_LAST);
reg &= ~XBAR_FPI_BURST_EN;
xbar_w32(reg, XBAR_ALWAYS_LAST);
}
static int clkout_enable(struct clk *clk)
{
int i;
for (i = 0; i < 4; i++) {
if (clk->rates[i] == clk->rate) {
int shift = 14 - (2 * clk->module);
int enable = 7 - clk->module;
unsigned int val = ltq_cgu_r32(ifccr);
val &= ~(3 << shift);
val |= i << shift;
val |= enable;
ltq_cgu_w32(val, ifccr);
return 0;
}
}
return -1;
}
static void clkdev_add_pmu(const char *dev, const char *con, bool deactivate,
unsigned int module, unsigned int bits)
{
struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
clk->cl.dev_id = dev;
clk->cl.con_id = con;
clk->cl.clk = clk;
clk->enable = pmu_enable;
clk->disable = pmu_disable;
clk->module = module;
clk->bits = bits;
if (deactivate) {
pmu_disable(clk);
}
clkdev_add(&clk->cl);
}
static void clkdev_add_cgu(const char *dev, const char *con,
unsigned int bits)
{
struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
clk->cl.dev_id = dev;
clk->cl.con_id = con;
clk->cl.clk = clk;
clk->enable = cgu_enable;
clk->disable = cgu_disable;
clk->bits = bits;
clkdev_add(&clk->cl);
}
static void clkdev_add_pci(void)
{
struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
struct clk *clk_ext = kzalloc(sizeof(struct clk), GFP_KERNEL);
clk->cl.dev_id = "17000000.pci";
clk->cl.con_id = NULL;
clk->cl.clk = clk;
clk->rate = CLOCK_33M;
clk->rates = valid_pci_rates;
clk->enable = pci_enable;
clk->disable = pmu_disable;
clk->module = 0;
clk->bits = PMU_PCI;
clkdev_add(&clk->cl);
clk_ext->cl.dev_id = "17000000.pci";
clk_ext->cl.con_id = "external";
clk_ext->cl.clk = clk_ext;
clk_ext->enable = pci_ext_enable;
clk_ext->disable = pci_ext_disable;
clkdev_add(&clk_ext->cl);
}
static void clkdev_add_clkout(void)
{
int i;
for (i = 0; i < 4; i++) {
struct clk *clk;
char *name;
name = kzalloc(sizeof("clkout0"), GFP_KERNEL);
sprintf(name, "clkout%d", i);
clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
clk->cl.dev_id = "1f103000.cgu";
clk->cl.con_id = name;
clk->cl.clk = clk;
clk->rate = 0;
clk->rates = valid_clkout_rates[i];
clk->enable = clkout_enable;
clk->module = i;
clkdev_add(&clk->cl);
}
}
void __init ltq_soc_init(void)
{
struct resource res_pmu, res_cgu, res_ebu;
struct device_node *np_pmu =
of_find_compatible_node(NULL, NULL, "lantiq,pmu-xway");
struct device_node *np_cgu =
of_find_compatible_node(NULL, NULL, "lantiq,cgu-xway");
struct device_node *np_ebu =
of_find_compatible_node(NULL, NULL, "lantiq,ebu-xway");
if (!np_pmu || !np_cgu || !np_ebu)
panic("Failed to load core nodes from devicetree");
if (of_address_to_resource(np_pmu, 0, &res_pmu) ||
of_address_to_resource(np_cgu, 0, &res_cgu) ||
of_address_to_resource(np_ebu, 0, &res_ebu))
panic("Failed to get core resources");
if (!request_mem_region(res_pmu.start, resource_size(&res_pmu),
res_pmu.name) ||
!request_mem_region(res_cgu.start, resource_size(&res_cgu),
res_cgu.name) ||
!request_mem_region(res_ebu.start, resource_size(&res_ebu),
res_ebu.name))
pr_err("Failed to request core resources");
pmu_membase = ioremap_nocache(res_pmu.start, resource_size(&res_pmu));
ltq_cgu_membase = ioremap_nocache(res_cgu.start,
resource_size(&res_cgu));
ltq_ebu_membase = ioremap_nocache(res_ebu.start,
resource_size(&res_ebu));
if (!pmu_membase || !ltq_cgu_membase || !ltq_ebu_membase)
panic("Failed to remap core resources");
if (of_machine_is_compatible("lantiq,vr9")) {
struct resource res_xbar;
struct device_node *np_xbar =
of_find_compatible_node(NULL, NULL,
"lantiq,xbar-xway");
if (!np_xbar)
panic("Failed to load xbar nodes from devicetree");
if (of_address_to_resource(np_pmu, 0, &res_xbar))
panic("Failed to get xbar resources");
if (request_mem_region(res_xbar.start, resource_size(&res_xbar),
res_xbar.name) < 0)
panic("Failed to get xbar resources");
ltq_xbar_membase = ioremap_nocache(res_xbar.start,
resource_size(&res_xbar));
if (!ltq_xbar_membase)
panic("Failed to remap xbar resources");
}
ltq_ebu_w32(ltq_ebu_r32(LTQ_EBU_BUSCON0) & ~EBU_WRDIS, LTQ_EBU_BUSCON0);
clkdev_add_pmu("10000000.fpi", NULL, 0, 0, PMU_FPI);
clkdev_add_pmu("1e100400.serial", NULL, 0, 0, PMU_ASC0);
clkdev_add_pmu("1e100a00.gptu", NULL, 1, 0, PMU_GPT);
clkdev_add_pmu("1e100bb0.stp", NULL, 1, 0, PMU_STP);
clkdev_add_pmu("1e104100.dma", NULL, 1, 0, PMU_DMA);
clkdev_add_pmu("1e100800.spi", NULL, 1, 0, PMU_SPI);
clkdev_add_pmu("1e105300.ebu", NULL, 0, 0, PMU_EBU);
clkdev_add_clkout();
if (of_machine_is_compatible("lantiq,vr9")) {
ifccr = CGU_IFCCR_VR9;
pcicr = CGU_PCICR_VR9;
} else {
clkdev_add_pmu("1e180000.etop", NULL, 1, 0, PMU_PPE);
}
if (!of_machine_is_compatible("lantiq,ase")) {
clkdev_add_pmu("1e100c00.serial", NULL, 0, 0, PMU_ASC1);
clkdev_add_pci();
}
if (of_machine_is_compatible("lantiq,grx390") ||
of_machine_is_compatible("lantiq,ar10")) {
clkdev_add_pmu("1e101000.usb", "phy", 1, 2, PMU_ANALOG_USB0_P);
clkdev_add_pmu("1e106000.usb", "phy", 1, 2, PMU_ANALOG_USB1_P);
clkdev_add_pmu("1d900000.pcie", "phy", 1, 2, PMU_ANALOG_PCIE0_P);
clkdev_add_pmu("1d900000.pcie", "msi", 1, 1, PMU1_PCIE_MSI);
clkdev_add_pmu("1d900000.pcie", "pdi", 1, 1, PMU1_PCIE_PDI);
clkdev_add_pmu("1d900000.pcie", "ctl", 1, 1, PMU1_PCIE_CTL);
clkdev_add_pmu("19000000.pcie", "phy", 1, 2, PMU_ANALOG_PCIE1_P);
clkdev_add_pmu("19000000.pcie", "msi", 1, 1, PMU1_PCIE1_MSI);
clkdev_add_pmu("19000000.pcie", "pdi", 1, 1, PMU1_PCIE1_PDI);
clkdev_add_pmu("19000000.pcie", "ctl", 1, 1, PMU1_PCIE1_CTL);
}
if (of_machine_is_compatible("lantiq,ase")) {
if (ltq_cgu_r32(CGU_SYS) & (1 << 5))
clkdev_add_static(CLOCK_266M, CLOCK_133M,
CLOCK_133M, CLOCK_266M);
else
clkdev_add_static(CLOCK_133M, CLOCK_133M,
CLOCK_133M, CLOCK_133M);
clkdev_add_pmu("1e101000.usb", "ctl", 1, 0, PMU_USB0);
clkdev_add_pmu("1e101000.usb", "phy", 1, 0, PMU_USB0_P);
clkdev_add_pmu("1e180000.etop", "ppe", 1, 0, PMU_PPE);
clkdev_add_cgu("1e180000.etop", "ephycgu", CGU_EPHY);
clkdev_add_pmu("1e180000.etop", "ephy", 1, 0, PMU_EPHY);
clkdev_add_pmu("1e103000.sdio", NULL, 1, 0, PMU_ASE_SDIO);
clkdev_add_pmu("1e116000.mei", "dfe", 1, 0, PMU_DFE);
} else if (of_machine_is_compatible("lantiq,grx390")) {
clkdev_add_static(ltq_grx390_cpu_hz(), ltq_grx390_fpi_hz(),
ltq_grx390_fpi_hz(), ltq_grx390_pp32_hz());
clkdev_add_pmu("1e101000.usb", "ctl", 1, 0, PMU_USB0);
clkdev_add_pmu("1e106000.usb", "ctl", 1, 0, PMU_USB1);
clkdev_add_pmu("1a800000.pcie", "phy", 1, 2, PMU_ANALOG_PCIE2_P);
clkdev_add_pmu("1a800000.pcie", "msi", 1, 1, PMU1_PCIE2_MSI);
clkdev_add_pmu("1a800000.pcie", "pdi", 1, 1, PMU1_PCIE2_PDI);
clkdev_add_pmu("1a800000.pcie", "ctl", 1, 1, PMU1_PCIE2_CTL);
clkdev_add_pmu("1e108000.eth", NULL, 1, 0, PMU_SWITCH | PMU_PPE_DP);
clkdev_add_pmu("1da00000.usif", "NULL", 1, 0, PMU_USIF);
clkdev_add_pmu("1e103100.deu", NULL, 1, 0, PMU_DEU);
} else if (of_machine_is_compatible("lantiq,ar10")) {
clkdev_add_static(ltq_ar10_cpu_hz(), ltq_ar10_fpi_hz(),
ltq_ar10_fpi_hz(), ltq_ar10_pp32_hz());
clkdev_add_pmu("1e101000.usb", "ctl", 1, 0, PMU_USB0);
clkdev_add_pmu("1e106000.usb", "ctl", 1, 0, PMU_USB1);
clkdev_add_pmu("1e108000.eth", NULL, 1, 0, PMU_SWITCH |
PMU_PPE_DP | PMU_PPE_TC);
clkdev_add_pmu("1da00000.usif", "NULL", 1, 0, PMU_USIF);
clkdev_add_pmu("1f203000.rcu", "gphy", 1, 0, PMU_GPHY);
clkdev_add_pmu("1e103100.deu", NULL, 1, 0, PMU_DEU);
clkdev_add_pmu("1e116000.mei", "afe", 1, 2, PMU_ANALOG_DSL_AFE);
clkdev_add_pmu("1e116000.mei", "dfe", 1, 0, PMU_DFE);
} else if (of_machine_is_compatible("lantiq,vr9")) {
clkdev_add_static(ltq_vr9_cpu_hz(), ltq_vr9_fpi_hz(),
ltq_vr9_fpi_hz(), ltq_vr9_pp32_hz());
clkdev_add_pmu("1e101000.usb", "phy", 1, 0, PMU_USB0_P);
clkdev_add_pmu("1e101000.usb", "ctl", 1, 0, PMU_USB0 | PMU_AHBM);
clkdev_add_pmu("1e106000.usb", "phy", 1, 0, PMU_USB1_P);
clkdev_add_pmu("1e106000.usb", "ctl", 1, 0, PMU_USB1 | PMU_AHBM);
clkdev_add_pmu("1d900000.pcie", "phy", 1, 1, PMU1_PCIE_PHY);
clkdev_add_pmu("1d900000.pcie", "bus", 1, 0, PMU_PCIE_CLK);
clkdev_add_pmu("1d900000.pcie", "msi", 1, 1, PMU1_PCIE_MSI);
clkdev_add_pmu("1d900000.pcie", "pdi", 1, 1, PMU1_PCIE_PDI);
clkdev_add_pmu("1d900000.pcie", "ctl", 1, 1, PMU1_PCIE_CTL);
clkdev_add_pmu(NULL, "ahb", 1, 0, PMU_AHBM | PMU_AHBS);
clkdev_add_pmu("1da00000.usif", "NULL", 1, 0, PMU_USIF);
clkdev_add_pmu("1e108000.eth", NULL, 1, 0,
PMU_SWITCH | PMU_PPE_DPLUS | PMU_PPE_DPLUM |
PMU_PPE_EMA | PMU_PPE_TC | PMU_PPE_SLL01 |
PMU_PPE_QSB | PMU_PPE_TOP);
clkdev_add_pmu("1f203000.rcu", "gphy", 1, 0, PMU_GPHY);
clkdev_add_pmu("1e103000.sdio", NULL, 1, 0, PMU_SDIO);
clkdev_add_pmu("1e103100.deu", NULL, 1, 0, PMU_DEU);
clkdev_add_pmu("1e116000.mei", "dfe", 1, 0, PMU_DFE);
} else if (of_machine_is_compatible("lantiq,ar9")) {
clkdev_add_static(ltq_ar9_cpu_hz(), ltq_ar9_fpi_hz(),
ltq_ar9_fpi_hz(), CLOCK_250M);
clkdev_add_pmu("1e101000.usb", "ctl", 1, 0, PMU_USB0);
clkdev_add_pmu("1e101000.usb", "phy", 1, 0, PMU_USB0_P);
clkdev_add_pmu("1e106000.usb", "ctl", 1, 0, PMU_USB1);
clkdev_add_pmu("1e106000.usb", "phy", 1, 0, PMU_USB1_P);
clkdev_add_pmu("1e180000.etop", "switch", 1, 0, PMU_SWITCH);
clkdev_add_pmu("1e103000.sdio", NULL, 1, 0, PMU_SDIO);
clkdev_add_pmu("1e103100.deu", NULL, 1, 0, PMU_DEU);
clkdev_add_pmu("1e116000.mei", "dfe", 1, 0, PMU_DFE);
clkdev_add_pmu("1e100400.serial", NULL, 1, 0, PMU_ASC0);
} else {
clkdev_add_static(ltq_danube_cpu_hz(), ltq_danube_fpi_hz(),
ltq_danube_fpi_hz(), ltq_danube_pp32_hz());
clkdev_add_pmu("1e101000.usb", "ctl", 1, 0, PMU_USB0);
clkdev_add_pmu("1e101000.usb", "phy", 1, 0, PMU_USB0_P);
clkdev_add_pmu("1e103000.sdio", NULL, 1, 0, PMU_SDIO);
clkdev_add_pmu("1e103100.deu", NULL, 1, 0, PMU_DEU);
clkdev_add_pmu("1e116000.mei", "dfe", 1, 0, PMU_DFE);
clkdev_add_pmu("1e100400.serial", NULL, 1, 0, PMU_ASC0);
}
if (of_machine_is_compatible("lantiq,vr9"))
xbar_fpi_burst_disable();
}
