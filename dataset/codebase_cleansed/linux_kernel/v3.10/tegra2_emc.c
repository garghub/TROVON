static inline void emc_writel(u32 val, unsigned long addr)
{
writel(val, emc_regbase + addr);
}
static inline u32 emc_readl(unsigned long addr)
{
return readl(emc_regbase + addr);
}
long tegra_emc_round_rate(unsigned long rate)
{
struct tegra_emc_pdata *pdata;
int i;
int best = -1;
unsigned long distance = ULONG_MAX;
if (!emc_pdev)
return -EINVAL;
pdata = emc_pdev->dev.platform_data;
pr_debug("%s: %lu\n", __func__, rate);
rate = rate / 2 / 1000;
for (i = 0; i < pdata->num_tables; i++) {
if (pdata->tables[i].rate >= rate &&
(pdata->tables[i].rate - rate) < distance) {
distance = pdata->tables[i].rate - rate;
best = i;
}
}
if (best < 0)
return -EINVAL;
pr_debug("%s: using %lu\n", __func__, pdata->tables[best].rate);
return pdata->tables[best].rate * 2 * 1000;
}
int tegra_emc_set_rate(unsigned long rate)
{
struct tegra_emc_pdata *pdata;
int i;
int j;
if (!emc_pdev)
return -EINVAL;
pdata = emc_pdev->dev.platform_data;
rate = rate / 2 / 1000;
for (i = 0; i < pdata->num_tables; i++)
if (pdata->tables[i].rate == rate)
break;
if (i >= pdata->num_tables)
return -EINVAL;
pr_debug("%s: setting to %lu\n", __func__, rate);
for (j = 0; j < TEGRA_EMC_NUM_REGS; j++)
emc_writel(pdata->tables[i].regs[j], emc_reg_addr[j]);
emc_readl(pdata->tables[i].regs[TEGRA_EMC_NUM_REGS - 1]);
return 0;
}
static struct device_node *tegra_emc_ramcode_devnode(struct device_node *np)
{
struct device_node *iter;
u32 reg;
for_each_child_of_node(np, iter) {
if (of_property_read_u32(np, "nvidia,ram-code", &reg))
continue;
if (reg == tegra_bct_strapping)
return of_node_get(iter);
}
return NULL;
}
static struct tegra_emc_pdata *tegra_emc_dt_parse_pdata(
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *tnp, *iter;
struct tegra_emc_pdata *pdata;
int ret, i, num_tables;
if (!np)
return NULL;
if (of_find_property(np, "nvidia,use-ram-code", NULL)) {
tnp = tegra_emc_ramcode_devnode(np);
if (!tnp)
dev_warn(&pdev->dev,
"can't find emc table for ram-code 0x%02x\n",
tegra_bct_strapping);
} else
tnp = of_node_get(np);
if (!tnp)
return NULL;
num_tables = 0;
for_each_child_of_node(tnp, iter)
if (of_device_is_compatible(iter, "nvidia,tegra20-emc-table"))
num_tables++;
if (!num_tables) {
pdata = NULL;
goto out;
}
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
pdata->tables = devm_kzalloc(&pdev->dev,
sizeof(*pdata->tables) * num_tables,
GFP_KERNEL);
i = 0;
for_each_child_of_node(tnp, iter) {
u32 prop;
ret = of_property_read_u32(iter, "clock-frequency", &prop);
if (ret) {
dev_err(&pdev->dev, "no clock-frequency in %s\n",
iter->full_name);
continue;
}
pdata->tables[i].rate = prop;
ret = of_property_read_u32_array(iter, "nvidia,emc-registers",
pdata->tables[i].regs,
TEGRA_EMC_NUM_REGS);
if (ret) {
dev_err(&pdev->dev,
"malformed emc-registers property in %s\n",
iter->full_name);
continue;
}
i++;
}
pdata->num_tables = i;
out:
of_node_put(tnp);
return pdata;
}
static struct tegra_emc_pdata *tegra_emc_dt_parse_pdata(
struct platform_device *pdev)
{
return NULL;
}
static struct tegra_emc_pdata *tegra_emc_fill_pdata(struct platform_device *pdev)
{
struct clk *c = clk_get_sys(NULL, "emc");
struct tegra_emc_pdata *pdata;
unsigned long khz;
int i;
WARN_ON(pdev->dev.platform_data);
BUG_ON(IS_ERR(c));
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
pdata->tables = devm_kzalloc(&pdev->dev, sizeof(*pdata->tables),
GFP_KERNEL);
pdata->tables[0].rate = clk_get_rate(c) / 2 / 1000;
for (i = 0; i < TEGRA_EMC_NUM_REGS; i++)
pdata->tables[0].regs[i] = emc_readl(emc_reg_addr[i]);
pdata->num_tables = 1;
khz = pdata->tables[0].rate;
dev_info(&pdev->dev, "no tables provided, using %ld kHz emc, "
"%ld kHz mem\n", khz * 2, khz);
return pdata;
}
static int tegra_emc_probe(struct platform_device *pdev)
{
struct tegra_emc_pdata *pdata;
struct resource *res;
if (!emc_enable) {
dev_err(&pdev->dev, "disabled per module parameter\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
emc_regbase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(emc_regbase))
return PTR_ERR(emc_regbase);
pdata = pdev->dev.platform_data;
if (!pdata)
pdata = tegra_emc_dt_parse_pdata(pdev);
if (!pdata)
pdata = tegra_emc_fill_pdata(pdev);
pdev->dev.platform_data = pdata;
emc_pdev = pdev;
return 0;
}
static int __init tegra_emc_init(void)
{
return platform_driver_register(&tegra_emc_driver);
}
