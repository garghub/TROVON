static int dove_mpp_ctrl_get(unsigned pid, unsigned long *config)
{
return default_mpp_ctrl_get(mpp_base, pid, config);
}
static int dove_mpp_ctrl_set(unsigned pid, unsigned long config)
{
return default_mpp_ctrl_set(mpp_base, pid, config);
}
static int dove_pmu_mpp_ctrl_get(unsigned pid, unsigned long *config)
{
unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
unsigned long pmu = readl(mpp_base + PMU_MPP_GENERAL_CTRL);
unsigned long func;
if ((pmu & BIT(pid)) == 0)
return default_mpp_ctrl_get(mpp_base, pid, config);
func = readl(pmu_base + PMU_SIGNAL_SELECT_0 + off);
*config = (func >> shift) & MVEBU_MPP_MASK;
*config |= CONFIG_PMU;
return 0;
}
static int dove_pmu_mpp_ctrl_set(unsigned pid, unsigned long config)
{
unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
unsigned long pmu = readl(mpp_base + PMU_MPP_GENERAL_CTRL);
unsigned long func;
if ((config & CONFIG_PMU) == 0) {
writel(pmu & ~BIT(pid), mpp_base + PMU_MPP_GENERAL_CTRL);
return default_mpp_ctrl_set(mpp_base, pid, config);
}
writel(pmu | BIT(pid), mpp_base + PMU_MPP_GENERAL_CTRL);
func = readl(pmu_base + PMU_SIGNAL_SELECT_0 + off);
func &= ~(MVEBU_MPP_MASK << shift);
func |= (config & MVEBU_MPP_MASK) << shift;
writel(func, pmu_base + PMU_SIGNAL_SELECT_0 + off);
return 0;
}
static int dove_mpp4_ctrl_get(unsigned pid, unsigned long *config)
{
unsigned long mpp4 = readl(mpp4_base);
unsigned long mask;
switch (pid) {
case 24:
mask = CAM_GPIO_SEL;
break;
case 40:
mask = SD0_GPIO_SEL;
break;
case 46:
mask = SD1_GPIO_SEL;
break;
case 58:
mask = SPI_GPIO_SEL;
break;
case 62:
mask = UART1_GPIO_SEL;
break;
default:
return -EINVAL;
}
*config = ((mpp4 & mask) != 0);
return 0;
}
static int dove_mpp4_ctrl_set(unsigned pid, unsigned long config)
{
unsigned long mpp4 = readl(mpp4_base);
unsigned long mask;
switch (pid) {
case 24:
mask = CAM_GPIO_SEL;
break;
case 40:
mask = SD0_GPIO_SEL;
break;
case 46:
mask = SD1_GPIO_SEL;
break;
case 58:
mask = SPI_GPIO_SEL;
break;
case 62:
mask = UART1_GPIO_SEL;
break;
default:
return -EINVAL;
}
mpp4 &= ~mask;
if (config)
mpp4 |= mask;
writel(mpp4, mpp4_base);
return 0;
}
static int dove_nand_ctrl_get(unsigned pid, unsigned long *config)
{
unsigned int gmpp;
regmap_read(gconfmap, MPP_GENERAL_CONFIG, &gmpp);
*config = ((gmpp & NAND_GPIO_EN) != 0);
return 0;
}
static int dove_nand_ctrl_set(unsigned pid, unsigned long config)
{
regmap_update_bits(gconfmap, MPP_GENERAL_CONFIG,
NAND_GPIO_EN,
(config) ? NAND_GPIO_EN : 0);
return 0;
}
static int dove_audio0_ctrl_get(unsigned pid, unsigned long *config)
{
unsigned long pmu = readl(mpp_base + PMU_MPP_GENERAL_CTRL);
*config = ((pmu & AU0_AC97_SEL) != 0);
return 0;
}
static int dove_audio0_ctrl_set(unsigned pid, unsigned long config)
{
unsigned long pmu = readl(mpp_base + PMU_MPP_GENERAL_CTRL);
pmu &= ~AU0_AC97_SEL;
if (config)
pmu |= AU0_AC97_SEL;
writel(pmu, mpp_base + PMU_MPP_GENERAL_CTRL);
return 0;
}
static int dove_audio1_ctrl_get(unsigned pid, unsigned long *config)
{
unsigned int mpp4 = readl(mpp4_base);
unsigned int sspc1;
unsigned int gmpp;
unsigned int gcfg2;
regmap_read(gconfmap, SSP_CTRL_STATUS_1, &sspc1);
regmap_read(gconfmap, MPP_GENERAL_CONFIG, &gmpp);
regmap_read(gconfmap, GLOBAL_CONFIG_2, &gcfg2);
*config = 0;
if (mpp4 & AU1_GPIO_SEL)
*config |= BIT(3);
if (sspc1 & SSP_ON_AU1)
*config |= BIT(2);
if (gmpp & AU1_SPDIFO_GPIO_EN)
*config |= BIT(1);
if (gcfg2 & TWSI_OPTION3_GPIO)
*config |= BIT(0);
if ((*config & BIT(3)) == 0)
*config &= ~(BIT(2) | BIT(0));
if ((*config & BIT(1)) == 0)
*config &= ~BIT(0);
return 0;
}
static int dove_audio1_ctrl_set(unsigned pid, unsigned long config)
{
unsigned int mpp4 = readl(mpp4_base);
mpp4 &= ~AU1_GPIO_SEL;
if (config & BIT(3))
mpp4 |= AU1_GPIO_SEL;
writel(mpp4, mpp4_base);
regmap_update_bits(gconfmap, SSP_CTRL_STATUS_1,
SSP_ON_AU1,
(config & BIT(2)) ? SSP_ON_AU1 : 0);
regmap_update_bits(gconfmap, MPP_GENERAL_CONFIG,
AU1_SPDIFO_GPIO_EN,
(config & BIT(1)) ? AU1_SPDIFO_GPIO_EN : 0);
regmap_update_bits(gconfmap, GLOBAL_CONFIG_2,
TWSI_OPTION3_GPIO,
(config & BIT(0)) ? TWSI_OPTION3_GPIO : 0);
return 0;
}
static int dove_audio1_ctrl_gpio_req(unsigned pid)
{
unsigned long config;
dove_audio1_ctrl_get(pid, &config);
switch (config) {
case 0x02:
case 0x0e:
if (pid >= 56)
return 0;
return -ENOTSUPP;
case 0x08:
case 0x0b:
if (pid <= 55)
return 0;
return -ENOTSUPP;
case 0x0a:
return 0;
}
return -ENOTSUPP;
}
static int dove_audio1_ctrl_gpio_dir(unsigned pid, bool input)
{
if (pid < 52 || pid > 57)
return -ENOTSUPP;
return 0;
}
static int dove_twsi_ctrl_get(unsigned pid, unsigned long *config)
{
unsigned int gcfg1;
unsigned int gcfg2;
regmap_read(gconfmap, GLOBAL_CONFIG_1, &gcfg1);
regmap_read(gconfmap, GLOBAL_CONFIG_2, &gcfg2);
*config = 0;
if (gcfg1 & TWSI_ENABLE_OPTION1)
*config = 1;
else if (gcfg2 & TWSI_ENABLE_OPTION2)
*config = 2;
else if (gcfg2 & TWSI_ENABLE_OPTION3)
*config = 3;
return 0;
}
static int dove_twsi_ctrl_set(unsigned pid, unsigned long config)
{
unsigned int gcfg1 = 0;
unsigned int gcfg2 = 0;
switch (config) {
case 1:
gcfg1 = TWSI_ENABLE_OPTION1;
break;
case 2:
gcfg2 = TWSI_ENABLE_OPTION2;
break;
case 3:
gcfg2 = TWSI_ENABLE_OPTION3;
break;
}
regmap_update_bits(gconfmap, GLOBAL_CONFIG_1,
TWSI_ENABLE_OPTION1,
gcfg1);
regmap_update_bits(gconfmap, GLOBAL_CONFIG_2,
TWSI_ENABLE_OPTION2 | TWSI_ENABLE_OPTION3,
gcfg2);
return 0;
}
static int dove_pinctrl_probe(struct platform_device *pdev)
{
struct resource *res, *mpp_res;
struct resource fb_res;
const struct of_device_id *match =
of_match_device(dove_pinctrl_of_match, &pdev->dev);
pdev->dev.platform_data = (void *)match->data;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Unable to get pdma clock");
return PTR_ERR(clk);
}
clk_prepare_enable(clk);
mpp_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mpp_base = devm_ioremap_resource(&pdev->dev, mpp_res);
if (IS_ERR(mpp_base))
return PTR_ERR(mpp_base);
memcpy(&fb_res, mpp_res, sizeof(struct resource));
fb_res.start = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_warn(&pdev->dev, "falling back to hardcoded MPP4 resource\n");
adjust_resource(&fb_res,
(mpp_res->start & INT_REGS_MASK) + MPP4_REGS_OFFS, 0x4);
res = &fb_res;
}
mpp4_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mpp4_base))
return PTR_ERR(mpp4_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
if (!res) {
dev_warn(&pdev->dev, "falling back to hardcoded PMU resource\n");
adjust_resource(&fb_res,
(mpp_res->start & INT_REGS_MASK) + PMU_REGS_OFFS, 0x8);
res = &fb_res;
}
pmu_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmu_base))
return PTR_ERR(pmu_base);
gconfmap = syscon_regmap_lookup_by_compatible("marvell,dove-global-config");
if (IS_ERR(gconfmap)) {
void __iomem *gc_base;
dev_warn(&pdev->dev, "falling back to hardcoded global registers\n");
adjust_resource(&fb_res,
(mpp_res->start & INT_REGS_MASK) + GC_REGS_OFFS, 0x14);
gc_base = devm_ioremap_resource(&pdev->dev, &fb_res);
if (IS_ERR(gc_base))
return PTR_ERR(gc_base);
gconfmap = devm_regmap_init_mmio(&pdev->dev,
gc_base, &gc_regmap_config);
if (IS_ERR(gconfmap))
return PTR_ERR(gconfmap);
}
if (fb_res.start)
dev_warn(&pdev->dev, FW_BUG "Missing pinctrl regs in DTB. Please update your firmware.\n");
return mvebu_pinctrl_probe(pdev);
}
static int dove_pinctrl_remove(struct platform_device *pdev)
{
if (!IS_ERR(clk))
clk_disable_unprepare(clk);
return 0;
}
