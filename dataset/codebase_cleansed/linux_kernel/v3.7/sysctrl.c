void ltq_pmu_enable(unsigned int module)
{
int err = 1000000;
pmu_w32(pmu_r32(PMU_PWDCR) & ~module, PMU_PWDCR);
do {} while (--err && (pmu_r32(PMU_PWDSR) & module));
if (!err)
panic("activating PMU module failed!");
}
void ltq_pmu_disable(unsigned int module)
{
pmu_w32(pmu_r32(PMU_PWDCR) | module, PMU_PWDCR);
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
pmu_w32(pmu_r32(PWDCR(clk->module)) & ~clk->bits,
PWDCR(clk->module));
do {} while (--retry && (pmu_r32(PWDSR(clk->module)) & clk->bits));
if (!retry)
panic("activating PMU module failed!\n");
return 0;
}
static void pmu_disable(struct clk *clk)
{
pmu_w32(pmu_r32(PWDCR(clk->module)) | clk->bits,
PWDCR(clk->module));
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
static void clkdev_add_pmu(const char *dev, const char *con,
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
panic("Failed to load core nodess from devicetree");
if (of_address_to_resource(np_pmu, 0, &res_pmu) ||
of_address_to_resource(np_cgu, 0, &res_cgu) ||
of_address_to_resource(np_ebu, 0, &res_ebu))
panic("Failed to get core resources");
if ((request_mem_region(res_pmu.start, resource_size(&res_pmu),
res_pmu.name) < 0) ||
(request_mem_region(res_cgu.start, resource_size(&res_cgu),
res_cgu.name) < 0) ||
(request_mem_region(res_ebu.start, resource_size(&res_ebu),
res_ebu.name) < 0))
pr_err("Failed to request core reources");
pmu_membase = ioremap_nocache(res_pmu.start, resource_size(&res_pmu));
ltq_cgu_membase = ioremap_nocache(res_cgu.start,
resource_size(&res_cgu));
ltq_ebu_membase = ioremap_nocache(res_ebu.start,
resource_size(&res_ebu));
if (!pmu_membase || !ltq_cgu_membase || !ltq_ebu_membase)
panic("Failed to remap core resources");
ltq_ebu_w32(ltq_ebu_r32(LTQ_EBU_BUSCON0) & ~EBU_WRDIS, LTQ_EBU_BUSCON0);
clkdev_add_pmu("10000000.fpi", NULL, 0, PMU_FPI);
clkdev_add_pmu("1e100400.serial", NULL, 0, PMU_ASC0);
clkdev_add_pmu("1e100a00.gptu", NULL, 0, PMU_GPT);
clkdev_add_pmu("1e100bb0.stp", NULL, 0, PMU_STP);
clkdev_add_pmu("1e104100.dma", NULL, 0, PMU_DMA);
clkdev_add_pmu("1e100800.spi", NULL, 0, PMU_SPI);
clkdev_add_pmu("1e105300.ebu", NULL, 0, PMU_EBU);
clkdev_add_clkout();
if (of_machine_is_compatible("lantiq,vr9")) {
ifccr = CGU_IFCCR_VR9;
pcicr = CGU_PCICR_VR9;
} else {
clkdev_add_pmu("1e180000.etop", NULL, 0, PMU_PPE);
}
if (!of_machine_is_compatible("lantiq,ase")) {
clkdev_add_pmu("1e100c00.serial", NULL, 0, PMU_ASC1);
clkdev_add_pci();
}
if (of_machine_is_compatible("lantiq,ase")) {
if (ltq_cgu_r32(CGU_SYS) & (1 << 5))
clkdev_add_static(CLOCK_266M, CLOCK_133M, CLOCK_133M);
else
clkdev_add_static(CLOCK_133M, CLOCK_133M, CLOCK_133M);
clkdev_add_cgu("1e180000.etop", "ephycgu", CGU_EPHY),
clkdev_add_pmu("1e180000.etop", "ephy", 0, PMU_EPHY);
} else if (of_machine_is_compatible("lantiq,vr9")) {
clkdev_add_static(ltq_vr9_cpu_hz(), ltq_vr9_fpi_hz(),
ltq_vr9_fpi_hz());
clkdev_add_pmu("1d900000.pcie", "phy", 1, PMU1_PCIE_PHY);
clkdev_add_pmu("1d900000.pcie", "bus", 0, PMU_PCIE_CLK);
clkdev_add_pmu("1d900000.pcie", "msi", 1, PMU1_PCIE_MSI);
clkdev_add_pmu("1d900000.pcie", "pdi", 1, PMU1_PCIE_PDI);
clkdev_add_pmu("1d900000.pcie", "ctl", 1, PMU1_PCIE_CTL);
clkdev_add_pmu("1d900000.pcie", "ahb", 0, PMU_AHBM | PMU_AHBS);
} else if (of_machine_is_compatible("lantiq,ar9")) {
clkdev_add_static(ltq_ar9_cpu_hz(), ltq_ar9_fpi_hz(),
ltq_ar9_fpi_hz());
clkdev_add_pmu("1e180000.etop", "switch", 0, PMU_SWITCH);
} else {
clkdev_add_static(ltq_danube_cpu_hz(), ltq_danube_fpi_hz(),
ltq_danube_fpi_hz());
}
}
