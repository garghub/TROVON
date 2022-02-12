static int exynos_ppmu_find_ppmu_id(struct devfreq_event_dev *edev)
{
int i;
for (i = 0; i < ARRAY_SIZE(ppmu_events); i++)
if (!strcmp(edev->desc->name, ppmu_events[i].name))
return ppmu_events[i].id;
return -EINVAL;
}
static int exynos_ppmu_disable(struct devfreq_event_dev *edev)
{
struct exynos_ppmu *info = devfreq_event_get_drvdata(edev);
u32 pmnc;
__raw_writel(PPMU_CCNT_MASK |
PPMU_PMCNT0_MASK |
PPMU_PMCNT1_MASK |
PPMU_PMCNT2_MASK |
PPMU_PMCNT3_MASK,
info->ppmu.base + PPMU_CNTENC);
pmnc = __raw_readl(info->ppmu.base + PPMU_PMNC);
pmnc &= ~PPMU_PMNC_ENABLE_MASK;
__raw_writel(pmnc, info->ppmu.base + PPMU_PMNC);
return 0;
}
static int exynos_ppmu_set_event(struct devfreq_event_dev *edev)
{
struct exynos_ppmu *info = devfreq_event_get_drvdata(edev);
int id = exynos_ppmu_find_ppmu_id(edev);
u32 pmnc, cntens;
if (id < 0)
return id;
cntens = __raw_readl(info->ppmu.base + PPMU_CNTENS);
cntens |= (PPMU_CCNT_MASK | (PPMU_ENABLE << id));
__raw_writel(cntens, info->ppmu.base + PPMU_CNTENS);
__raw_writel(PPMU_RO_DATA_CNT | PPMU_WO_DATA_CNT,
info->ppmu.base + PPMU_BEVTxSEL(id));
pmnc = __raw_readl(info->ppmu.base + PPMU_PMNC);
pmnc &= ~(PPMU_PMNC_ENABLE_MASK
| PPMU_PMNC_COUNTER_RESET_MASK
| PPMU_PMNC_CC_RESET_MASK);
pmnc |= (PPMU_ENABLE << PPMU_PMNC_ENABLE_SHIFT);
pmnc |= (PPMU_ENABLE << PPMU_PMNC_COUNTER_RESET_SHIFT);
pmnc |= (PPMU_ENABLE << PPMU_PMNC_CC_RESET_SHIFT);
__raw_writel(pmnc, info->ppmu.base + PPMU_PMNC);
return 0;
}
static int exynos_ppmu_get_event(struct devfreq_event_dev *edev,
struct devfreq_event_data *edata)
{
struct exynos_ppmu *info = devfreq_event_get_drvdata(edev);
int id = exynos_ppmu_find_ppmu_id(edev);
u32 pmnc, cntenc;
if (id < 0)
return -EINVAL;
pmnc = __raw_readl(info->ppmu.base + PPMU_PMNC);
pmnc &= ~PPMU_PMNC_ENABLE_MASK;
__raw_writel(pmnc, info->ppmu.base + PPMU_PMNC);
edata->total_count = __raw_readl(info->ppmu.base + PPMU_CCNT);
switch (id) {
case PPMU_PMNCNT0:
case PPMU_PMNCNT1:
case PPMU_PMNCNT2:
edata->load_count
= __raw_readl(info->ppmu.base + PPMU_PMNCT(id));
break;
case PPMU_PMNCNT3:
edata->load_count =
((__raw_readl(info->ppmu.base + PPMU_PMCNT3_HIGH) << 8)
| __raw_readl(info->ppmu.base + PPMU_PMCNT3_LOW));
break;
default:
return -EINVAL;
}
cntenc = __raw_readl(info->ppmu.base + PPMU_CNTENC);
cntenc |= (PPMU_CCNT_MASK | (PPMU_ENABLE << id));
__raw_writel(cntenc, info->ppmu.base + PPMU_CNTENC);
dev_dbg(&edev->dev, "%s (event: %ld/%ld)\n", edev->desc->name,
edata->load_count, edata->total_count);
return 0;
}
static int exynos_ppmu_v2_disable(struct devfreq_event_dev *edev)
{
struct exynos_ppmu *info = devfreq_event_get_drvdata(edev);
u32 pmnc, clear;
clear = (PPMU_CCNT_MASK | PPMU_PMCNT0_MASK | PPMU_PMCNT1_MASK
| PPMU_PMCNT2_MASK | PPMU_PMCNT3_MASK);
__raw_writel(clear, info->ppmu.base + PPMU_V2_FLAG);
__raw_writel(clear, info->ppmu.base + PPMU_V2_INTENC);
__raw_writel(clear, info->ppmu.base + PPMU_V2_CNTENC);
__raw_writel(clear, info->ppmu.base + PPMU_V2_CNT_RESET);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CIG_CFG0);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CIG_CFG1);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CIG_CFG2);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CIG_RESULT);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CNT_AUTO);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CH_EV0_TYPE);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CH_EV1_TYPE);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CH_EV2_TYPE);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_CH_EV3_TYPE);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_SM_ID_V);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_SM_ID_A);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_SM_OTHERS_V);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_SM_OTHERS_A);
__raw_writel(0x0, info->ppmu.base + PPMU_V2_INTERRUPT_RESET);
pmnc = __raw_readl(info->ppmu.base + PPMU_V2_PMNC);
pmnc &= ~PPMU_PMNC_ENABLE_MASK;
__raw_writel(pmnc, info->ppmu.base + PPMU_V2_PMNC);
return 0;
}
static int exynos_ppmu_v2_set_event(struct devfreq_event_dev *edev)
{
struct exynos_ppmu *info = devfreq_event_get_drvdata(edev);
int id = exynos_ppmu_find_ppmu_id(edev);
u32 pmnc, cntens;
cntens = __raw_readl(info->ppmu.base + PPMU_V2_CNTENS);
cntens |= (PPMU_CCNT_MASK | (PPMU_ENABLE << id));
__raw_writel(cntens, info->ppmu.base + PPMU_V2_CNTENS);
switch (id) {
case PPMU_PMNCNT0:
case PPMU_PMNCNT1:
case PPMU_PMNCNT2:
__raw_writel(PPMU_V2_RO_DATA_CNT | PPMU_V2_WO_DATA_CNT,
info->ppmu.base + PPMU_V2_CH_EVx_TYPE(id));
break;
case PPMU_PMNCNT3:
__raw_writel(PPMU_V2_EVT3_RW_DATA_CNT,
info->ppmu.base + PPMU_V2_CH_EVx_TYPE(id));
break;
}
pmnc = __raw_readl(info->ppmu.base + PPMU_V2_PMNC);
pmnc &= ~(PPMU_PMNC_ENABLE_MASK
| PPMU_PMNC_COUNTER_RESET_MASK
| PPMU_PMNC_CC_RESET_MASK
| PPMU_PMNC_CC_DIVIDER_MASK
| PPMU_V2_PMNC_START_MODE_MASK);
pmnc |= (PPMU_ENABLE << PPMU_PMNC_ENABLE_SHIFT);
pmnc |= (PPMU_ENABLE << PPMU_PMNC_COUNTER_RESET_SHIFT);
pmnc |= (PPMU_ENABLE << PPMU_PMNC_CC_RESET_SHIFT);
pmnc |= (PPMU_V2_MODE_MANUAL << PPMU_V2_PMNC_START_MODE_SHIFT);
__raw_writel(pmnc, info->ppmu.base + PPMU_V2_PMNC);
return 0;
}
static int exynos_ppmu_v2_get_event(struct devfreq_event_dev *edev,
struct devfreq_event_data *edata)
{
struct exynos_ppmu *info = devfreq_event_get_drvdata(edev);
int id = exynos_ppmu_find_ppmu_id(edev);
u32 pmnc, cntenc;
u32 pmcnt_high, pmcnt_low;
u64 load_count = 0;
pmnc = __raw_readl(info->ppmu.base + PPMU_V2_PMNC);
pmnc &= ~PPMU_PMNC_ENABLE_MASK;
__raw_writel(pmnc, info->ppmu.base + PPMU_V2_PMNC);
edata->total_count = __raw_readl(info->ppmu.base + PPMU_V2_CCNT);
switch (id) {
case PPMU_PMNCNT0:
case PPMU_PMNCNT1:
case PPMU_PMNCNT2:
load_count = __raw_readl(info->ppmu.base + PPMU_V2_PMNCT(id));
break;
case PPMU_PMNCNT3:
pmcnt_high = __raw_readl(info->ppmu.base + PPMU_V2_PMCNT3_HIGH);
pmcnt_low = __raw_readl(info->ppmu.base + PPMU_V2_PMCNT3_LOW);
load_count = ((u64)((pmcnt_high & 0xff)) << 32)
+ (u64)pmcnt_low;
break;
}
edata->load_count = load_count;
cntenc = __raw_readl(info->ppmu.base + PPMU_V2_CNTENC);
cntenc |= (PPMU_CCNT_MASK | (PPMU_ENABLE << id));
__raw_writel(cntenc, info->ppmu.base + PPMU_V2_CNTENC);
dev_dbg(&edev->dev, "%25s (load: %ld / %ld)\n", edev->desc->name,
edata->load_count, edata->total_count);
return 0;
}
static struct devfreq_event_ops *exynos_bus_get_ops(struct device_node *np)
{
const struct of_device_id *match;
match = of_match_node(exynos_ppmu_id_match, np);
return (struct devfreq_event_ops *)match->data;
}
static int of_get_devfreq_events(struct device_node *np,
struct exynos_ppmu *info)
{
struct devfreq_event_desc *desc;
struct devfreq_event_ops *event_ops;
struct device *dev = info->dev;
struct device_node *events_np, *node;
int i, j, count;
events_np = of_get_child_by_name(np, "events");
if (!events_np) {
dev_err(dev,
"failed to get child node of devfreq-event devices\n");
return -EINVAL;
}
event_ops = exynos_bus_get_ops(np);
count = of_get_child_count(events_np);
desc = devm_kzalloc(dev, sizeof(*desc) * count, GFP_KERNEL);
if (!desc)
return -ENOMEM;
info->num_events = count;
j = 0;
for_each_child_of_node(events_np, node) {
for (i = 0; i < ARRAY_SIZE(ppmu_events); i++) {
if (!ppmu_events[i].name)
continue;
if (!of_node_cmp(node->name, ppmu_events[i].name))
break;
}
if (i == ARRAY_SIZE(ppmu_events)) {
dev_warn(dev,
"don't know how to configure events : %s\n",
node->name);
continue;
}
desc[j].ops = event_ops;
desc[j].driver_data = info;
of_property_read_string(node, "event-name", &desc[j].name);
j++;
of_node_put(node);
}
info->desc = desc;
of_node_put(events_np);
return 0;
}
static int exynos_ppmu_parse_dt(struct exynos_ppmu *info)
{
struct device *dev = info->dev;
struct device_node *np = dev->of_node;
int ret = 0;
if (!np) {
dev_err(dev, "failed to find devicetree node\n");
return -EINVAL;
}
info->ppmu.base = of_iomap(np, 0);
if (IS_ERR_OR_NULL(info->ppmu.base)) {
dev_err(dev, "failed to map memory region\n");
return -ENOMEM;
}
info->ppmu.clk = devm_clk_get(dev, "ppmu");
if (IS_ERR(info->ppmu.clk)) {
info->ppmu.clk = NULL;
dev_warn(dev, "cannot get PPMU clock\n");
}
ret = of_get_devfreq_events(np, info);
if (ret < 0) {
dev_err(dev, "failed to parse exynos ppmu dt node\n");
goto err;
}
return 0;
err:
iounmap(info->ppmu.base);
return ret;
}
static int exynos_ppmu_probe(struct platform_device *pdev)
{
struct exynos_ppmu *info;
struct devfreq_event_dev **edev;
struct devfreq_event_desc *desc;
int i, ret = 0, size;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
mutex_init(&info->lock);
info->dev = &pdev->dev;
ret = exynos_ppmu_parse_dt(info);
if (ret < 0) {
dev_err(&pdev->dev,
"failed to parse devicetree for resource\n");
return ret;
}
desc = info->desc;
size = sizeof(struct devfreq_event_dev *) * info->num_events;
info->edev = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!info->edev) {
dev_err(&pdev->dev,
"failed to allocate memory devfreq-event devices\n");
return -ENOMEM;
}
edev = info->edev;
platform_set_drvdata(pdev, info);
for (i = 0; i < info->num_events; i++) {
edev[i] = devm_devfreq_event_add_edev(&pdev->dev, &desc[i]);
if (IS_ERR(edev[i])) {
ret = PTR_ERR(edev[i]);
dev_err(&pdev->dev,
"failed to add devfreq-event device\n");
goto err;
}
}
clk_prepare_enable(info->ppmu.clk);
return 0;
err:
iounmap(info->ppmu.base);
return ret;
}
static int exynos_ppmu_remove(struct platform_device *pdev)
{
struct exynos_ppmu *info = platform_get_drvdata(pdev);
clk_disable_unprepare(info->ppmu.clk);
iounmap(info->ppmu.base);
return 0;
}
