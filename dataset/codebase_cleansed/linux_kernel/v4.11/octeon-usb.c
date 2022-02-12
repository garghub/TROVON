static int dwc3_octeon_config_power(struct device *dev, u64 base)
{
#define UCTL_HOST_CFG 0xe0
union cvm_usbdrd_uctl_host_cfg uctl_host_cfg;
union cvmx_gpio_bit_cfgx gpio_bit;
uint32_t gpio_pwr[3];
int gpio, len, power_active_low;
struct device_node *node = dev->of_node;
int index = (base >> 24) & 1;
if (of_find_property(node, "power", &len) != NULL) {
if (len == 12) {
of_property_read_u32_array(node, "power", gpio_pwr, 3);
power_active_low = gpio_pwr[2] & 0x01;
gpio = gpio_pwr[1];
} else if (len == 8) {
of_property_read_u32_array(node, "power", gpio_pwr, 2);
power_active_low = 0;
gpio = gpio_pwr[1];
} else {
dev_err(dev, "dwc3 controller clock init failure.\n");
return -EINVAL;
}
if ((OCTEON_IS_MODEL(OCTEON_CN73XX) ||
OCTEON_IS_MODEL(OCTEON_CNF75XX))
&& gpio <= 31) {
gpio_bit.u64 = cvmx_read_csr(CVMX_GPIO_BIT_CFGX(gpio));
gpio_bit.s.tx_oe = 1;
gpio_bit.cn73xx.output_sel = (index == 0 ? 0x14 : 0x15);
cvmx_write_csr(CVMX_GPIO_BIT_CFGX(gpio), gpio_bit.u64);
} else if (gpio <= 15) {
gpio_bit.u64 = cvmx_read_csr(CVMX_GPIO_BIT_CFGX(gpio));
gpio_bit.s.tx_oe = 1;
gpio_bit.cn70xx.output_sel = (index == 0 ? 0x14 : 0x19);
cvmx_write_csr(CVMX_GPIO_BIT_CFGX(gpio), gpio_bit.u64);
} else {
gpio_bit.u64 = cvmx_read_csr(CVMX_GPIO_XBIT_CFGX(gpio));
gpio_bit.s.tx_oe = 1;
gpio_bit.cn70xx.output_sel = (index == 0 ? 0x14 : 0x19);
cvmx_write_csr(CVMX_GPIO_XBIT_CFGX(gpio), gpio_bit.u64);
}
uctl_host_cfg.u64 = cvmx_read_csr(base + UCTL_HOST_CFG);
uctl_host_cfg.s.ppc_en = 1;
uctl_host_cfg.s.ppc_active_high_en = !power_active_low;
cvmx_write_csr(base + UCTL_HOST_CFG, uctl_host_cfg.u64);
} else {
uctl_host_cfg.u64 = cvmx_read_csr(base + UCTL_HOST_CFG);
uctl_host_cfg.s.ppc_en = 0;
uctl_host_cfg.s.ppc_active_high_en = 0;
cvmx_write_csr(base + UCTL_HOST_CFG, uctl_host_cfg.u64);
dev_warn(dev, "dwc3 controller clock init failure.\n");
}
return 0;
}
static int dwc3_octeon_clocks_start(struct device *dev, u64 base)
{
union cvm_usbdrd_uctl_ctl uctl_ctl;
int ref_clk_sel = 2;
u64 div;
u32 clock_rate;
int mpll_mul;
int i;
u64 h_clk_rate;
u64 uctl_ctl_reg = base;
if (dev->of_node) {
const char *ss_clock_type;
const char *hs_clock_type;
i = of_property_read_u32(dev->of_node,
"refclk-frequency", &clock_rate);
if (i) {
pr_err("No UCTL \"refclk-frequency\"\n");
return -EINVAL;
}
i = of_property_read_string(dev->of_node,
"refclk-type-ss", &ss_clock_type);
if (i) {
pr_err("No UCTL \"refclk-type-ss\"\n");
return -EINVAL;
}
i = of_property_read_string(dev->of_node,
"refclk-type-hs", &hs_clock_type);
if (i) {
pr_err("No UCTL \"refclk-type-hs\"\n");
return -EINVAL;
}
if (strcmp("dlmc_ref_clk0", ss_clock_type) == 0) {
if (strcmp(hs_clock_type, "dlmc_ref_clk0") == 0)
ref_clk_sel = 0;
else if (strcmp(hs_clock_type, "pll_ref_clk") == 0)
ref_clk_sel = 2;
else
pr_err("Invalid HS clock type %s, using pll_ref_clk instead\n",
hs_clock_type);
} else if (strcmp(ss_clock_type, "dlmc_ref_clk1") == 0) {
if (strcmp(hs_clock_type, "dlmc_ref_clk1") == 0)
ref_clk_sel = 1;
else if (strcmp(hs_clock_type, "pll_ref_clk") == 0)
ref_clk_sel = 3;
else {
pr_err("Invalid HS clock type %s, using pll_ref_clk instead\n",
hs_clock_type);
ref_clk_sel = 3;
}
} else
pr_err("Invalid SS clock type %s, using dlmc_ref_clk0 instead\n",
ss_clock_type);
if ((ref_clk_sel == 0 || ref_clk_sel == 1) &&
(clock_rate != 100000000))
pr_err("Invalid UCTL clock rate of %u, using 100000000 instead\n",
clock_rate);
} else {
pr_err("No USB UCTL device node\n");
return -EINVAL;
}
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.uphy_rst = 1;
uctl_ctl.s.uahc_rst = 1;
uctl_ctl.s.uctl_rst = 1;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.h_clkdiv_rst = 1;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
for (div = 0; div < OCTEON_H_CLKDIV_SEL; div++) {
h_clk_rate = octeon_get_io_clock_rate() / clk_div[div];
if (h_clk_rate <= OCTEON_MAX_H_CLK_RATE &&
h_clk_rate >= OCTEON_MIN_H_CLK_RATE)
break;
}
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.h_clkdiv_sel = div;
uctl_ctl.s.h_clk_en = 1;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
if ((div != uctl_ctl.s.h_clkdiv_sel) || (!uctl_ctl.s.h_clk_en)) {
dev_err(dev, "dwc3 controller clock init failure.\n");
return -EINVAL;
}
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.h_clkdiv_rst = 0;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.ref_clk_sel = ref_clk_sel;
uctl_ctl.s.ref_clk_fsel = 0x07;
uctl_ctl.s.ref_clk_div2 = 0;
switch (clock_rate) {
default:
dev_err(dev, "Invalid ref_clk %u, using 100000000 instead\n",
clock_rate);
case 100000000:
mpll_mul = 0x19;
if (ref_clk_sel < 2)
uctl_ctl.s.ref_clk_fsel = 0x27;
break;
case 50000000:
mpll_mul = 0x32;
break;
case 125000000:
mpll_mul = 0x28;
break;
}
uctl_ctl.s.mpll_multiplier = mpll_mul;
uctl_ctl.s.ssc_en = 1;
uctl_ctl.s.ref_ssp_en = 1;
uctl_ctl.s.hs_power_en = 1;
uctl_ctl.s.ss_power_en = 1;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
udelay(10);
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.uctl_rst = 0;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
udelay(10);
if (dwc3_octeon_config_power(dev, base)) {
dev_err(dev, "Error configuring power.\n");
return -EINVAL;
}
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.uahc_rst = 0;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
udelay(10);
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.csclk_en = 1;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
uctl_ctl.s.drd_mode = 0;
cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
return 0;
}
static void __init dwc3_octeon_set_endian_mode(u64 base)
{
#define UCTL_SHIM_CFG 0xe8
union cvm_usbdrd_uctl_shim_cfg shim_cfg;
shim_cfg.u64 = cvmx_read_csr(base + UCTL_SHIM_CFG);
#ifdef __BIG_ENDIAN
shim_cfg.s.dma_endian_mode = 1;
shim_cfg.s.csr_endian_mode = 1;
#else
shim_cfg.s.dma_endian_mode = 0;
shim_cfg.s.csr_endian_mode = 0;
#endif
cvmx_write_csr(base + UCTL_SHIM_CFG, shim_cfg.u64);
}
static void __init dwc3_octeon_phy_reset(u64 base)
{
union cvm_usbdrd_uctl_ctl uctl_ctl;
int index = (base >> 24) & 1;
uctl_ctl.u64 = cvmx_read_csr(CVMX_USBDRDX_UCTL_CTL(index));
uctl_ctl.s.uphy_rst = 0;
cvmx_write_csr(CVMX_USBDRDX_UCTL_CTL(index), uctl_ctl.u64);
}
static int __init dwc3_octeon_device_init(void)
{
const char compat_node_name[] = "cavium,octeon-7130-usb-uctl";
struct platform_device *pdev;
struct device_node *node;
struct resource *res;
void __iomem *base;
node = NULL;
do {
node = of_find_node_by_name(node, "uctl");
if (!node)
return -ENODEV;
if (of_device_is_compatible(node, compat_node_name)) {
pdev = of_find_device_by_node(node);
if (!pdev)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No memory resources\n");
return -ENXIO;
}
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
mutex_lock(&dwc3_octeon_clocks_mutex);
dwc3_octeon_clocks_start(&pdev->dev, (u64)base);
dwc3_octeon_set_endian_mode((u64)base);
dwc3_octeon_phy_reset((u64)base);
dev_info(&pdev->dev, "clocks initialized.\n");
mutex_unlock(&dwc3_octeon_clocks_mutex);
devm_iounmap(&pdev->dev, base);
devm_release_mem_region(&pdev->dev, res->start,
resource_size(res));
}
} while (node != NULL);
return 0;
}
