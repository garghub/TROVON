int vlv2_plat_set_clock_freq(int clk_num, int freq_type)
{
void __iomem *addr;
if (clk_num < 0 || clk_num >= MAX_CLK_COUNT) {
pr_err("Clock number out of range (%d)\n", clk_num);
return -EINVAL;
}
if (freq_type != CLK_FREQ_TYPE_XTAL &&
freq_type != CLK_FREQ_TYPE_PLL) {
pr_err("wrong clock type\n");
return -EINVAL;
}
if (!pmc_base) {
pr_err("memio map is not set\n");
return -EINVAL;
}
addr = pmc_base + PLT_CLK_CTL_OFFSET(clk_num);
mutex_lock(&clk_mutex);
writel(REG_SET_FIELD(readl(addr), CLK_FREQ_TYPE, freq_type), addr);
mutex_unlock(&clk_mutex);
return 0;
}
int vlv2_plat_get_clock_freq(int clk_num)
{
u32 ret;
if (clk_num < 0 || clk_num >= MAX_CLK_COUNT) {
pr_err("Clock number out of range (%d)\n", clk_num);
return -EINVAL;
}
if (!pmc_base) {
pr_err("memio map is not set\n");
return -EINVAL;
}
mutex_lock(&clk_mutex);
ret = REG_GET_FIELD(readl(pmc_base + PLT_CLK_CTL_OFFSET(clk_num)),
CLK_FREQ_TYPE);
mutex_unlock(&clk_mutex);
return ret;
}
int vlv2_plat_configure_clock(int clk_num, u32 conf)
{
void __iomem *addr;
if (clk_num < 0 || clk_num >= MAX_CLK_COUNT) {
pr_err("Clock number out of range (%d)\n", clk_num);
return -EINVAL;
}
if (conf != CLK_CONFG_D3_GATED &&
conf != CLK_CONFG_FORCE_ON &&
conf != CLK_CONFG_FORCE_OFF) {
pr_err("Invalid clock configuration requested\n");
return -EINVAL;
}
if (!pmc_base) {
pr_err("memio map is not set\n");
return -EINVAL;
}
addr = pmc_base + PLT_CLK_CTL_OFFSET(clk_num);
mutex_lock(&clk_mutex);
writel(REG_SET_FIELD(readl(addr), CLK_CONFG, conf), addr);
mutex_unlock(&clk_mutex);
return 0;
}
int vlv2_plat_get_clock_status(int clk_num)
{
int ret;
if (clk_num < 0 || clk_num >= MAX_CLK_COUNT) {
pr_err("Clock number out of range (%d)\n", clk_num);
return -EINVAL;
}
if (!pmc_base) {
pr_err("memio map is not set\n");
return -EINVAL;
}
mutex_lock(&clk_mutex);
ret = (int)REG_GET_FIELD(readl(pmc_base + PLT_CLK_CTL_OFFSET(clk_num)),
CLK_CONFG);
mutex_unlock(&clk_mutex);
return ret;
}
static int vlv2_plat_clk_probe(struct platform_device *pdev)
{
int i = 0;
pmc_base = ioremap_nocache(VLV2_PMC_CLK_BASE_ADDRESS, PMC_MAP_SIZE);
if (!pmc_base) {
dev_err(&pdev->dev, "I/O memory remapping failed\n");
return -ENOMEM;
}
for (i = 0; i < MAX_CLK_COUNT; i++)
vlv2_plat_configure_clock(i, CLK_CONFG_FORCE_OFF);
dev_info(&pdev->dev, "vlv2_plat_clk initialized\n");
return 0;
}
static int vlv2_resume(struct device *device)
{
int i;
for (i = 0; i < MAX_CLK_COUNT; i++)
vlv2_plat_configure_clock(i, CLK_CONFG_FORCE_OFF);
return 0;
}
static int vlv2_suspend(struct device *device)
{
return 0;
}
static int __init vlv2_plat_clk_init(void)
{
return platform_driver_register(&vlv2_plat_clk_driver);
}
