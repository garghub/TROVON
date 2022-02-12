static void rockchip_dfi_start_hardware_counter(struct devfreq_event_dev *edev)
{
struct rockchip_dfi *info = devfreq_event_get_drvdata(edev);
void __iomem *dfi_regs = info->regs;
u32 val;
u32 ddr_type;
regmap_read(info->regmap_pmu, PMUGRF_OS_REG2, &val);
ddr_type = (val >> DDRTYPE_SHIFT) & DDRTYPE_MASK;
writel_relaxed(CLR_DDRMON_CTRL, dfi_regs + DDRMON_CTRL);
if (ddr_type == LPDDR3)
writel_relaxed(LPDDR3_EN, dfi_regs + DDRMON_CTRL);
else if (ddr_type == LPDDR4)
writel_relaxed(LPDDR4_EN, dfi_regs + DDRMON_CTRL);
writel_relaxed(SOFTWARE_EN, dfi_regs + DDRMON_CTRL);
}
static void rockchip_dfi_stop_hardware_counter(struct devfreq_event_dev *edev)
{
struct rockchip_dfi *info = devfreq_event_get_drvdata(edev);
void __iomem *dfi_regs = info->regs;
writel_relaxed(SOFTWARE_DIS, dfi_regs + DDRMON_CTRL);
}
static int rockchip_dfi_get_busier_ch(struct devfreq_event_dev *edev)
{
struct rockchip_dfi *info = devfreq_event_get_drvdata(edev);
u32 tmp, max = 0;
u32 i, busier_ch = 0;
void __iomem *dfi_regs = info->regs;
rockchip_dfi_stop_hardware_counter(edev);
for (i = 0; i < RK3399_DMC_NUM_CH; i++) {
info->ch_usage[i].access = readl_relaxed(dfi_regs +
DDRMON_CH0_DFI_ACCESS_NUM + i * 20) * 4;
info->ch_usage[i].total = readl_relaxed(dfi_regs +
DDRMON_CH0_COUNT_NUM + i * 20);
tmp = info->ch_usage[i].access;
if (tmp > max) {
busier_ch = i;
max = tmp;
}
}
rockchip_dfi_start_hardware_counter(edev);
return busier_ch;
}
static int rockchip_dfi_disable(struct devfreq_event_dev *edev)
{
struct rockchip_dfi *info = devfreq_event_get_drvdata(edev);
rockchip_dfi_stop_hardware_counter(edev);
clk_disable_unprepare(info->clk);
return 0;
}
static int rockchip_dfi_enable(struct devfreq_event_dev *edev)
{
struct rockchip_dfi *info = devfreq_event_get_drvdata(edev);
int ret;
ret = clk_prepare_enable(info->clk);
if (ret) {
dev_err(&edev->dev, "failed to enable dfi clk: %d\n", ret);
return ret;
}
rockchip_dfi_start_hardware_counter(edev);
return 0;
}
static int rockchip_dfi_set_event(struct devfreq_event_dev *edev)
{
return 0;
}
static int rockchip_dfi_get_event(struct devfreq_event_dev *edev,
struct devfreq_event_data *edata)
{
struct rockchip_dfi *info = devfreq_event_get_drvdata(edev);
int busier_ch;
busier_ch = rockchip_dfi_get_busier_ch(edev);
edata->load_count = info->ch_usage[busier_ch].access;
edata->total_count = info->ch_usage[busier_ch].total;
return 0;
}
static int rockchip_dfi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rockchip_dfi *data;
struct resource *res;
struct devfreq_event_desc *desc;
struct device_node *np = pdev->dev.of_node, *node;
data = devm_kzalloc(dev, sizeof(struct rockchip_dfi), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->regs))
return PTR_ERR(data->regs);
data->clk = devm_clk_get(dev, "pclk_ddr_mon");
if (IS_ERR(data->clk)) {
dev_err(dev, "Cannot get the clk dmc_clk\n");
return PTR_ERR(data->clk);
};
node = of_parse_phandle(np, "rockchip,pmu", 0);
if (node) {
data->regmap_pmu = syscon_node_to_regmap(node);
if (IS_ERR(data->regmap_pmu))
return PTR_ERR(data->regmap_pmu);
}
data->dev = dev;
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
desc->ops = &rockchip_dfi_ops;
desc->driver_data = data;
desc->name = np->name;
data->desc = desc;
data->edev = devm_devfreq_event_add_edev(&pdev->dev, desc);
if (IS_ERR(data->edev)) {
dev_err(&pdev->dev,
"failed to add devfreq-event device\n");
return PTR_ERR(data->edev);
}
platform_set_drvdata(pdev, data);
return 0;
}
