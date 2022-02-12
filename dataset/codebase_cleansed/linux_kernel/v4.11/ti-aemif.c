static int aemif_calc_rate(struct platform_device *pdev, int wanted,
unsigned long clk, int max)
{
int result;
result = DIV_ROUND_UP((wanted * clk), NSEC_PER_MSEC) - 1;
dev_dbg(&pdev->dev, "%s: result %d from %ld, %d\n", __func__, result,
clk, wanted);
if (result < 0)
result = 0;
else if (result > max)
result = -EINVAL;
return result;
}
static int aemif_config_abus(struct platform_device *pdev, int csnum)
{
struct aemif_device *aemif = platform_get_drvdata(pdev);
struct aemif_cs_data *data = &aemif->cs_data[csnum];
int ta, rhold, rstrobe, rsetup, whold, wstrobe, wsetup;
unsigned long clk_rate = aemif->clk_rate;
unsigned offset;
u32 set, val;
offset = A1CR_OFFSET + (data->cs - aemif->cs_offset) * 4;
ta = aemif_calc_rate(pdev, data->ta, clk_rate, TA_MAX);
rhold = aemif_calc_rate(pdev, data->rhold, clk_rate, RHOLD_MAX);
rstrobe = aemif_calc_rate(pdev, data->rstrobe, clk_rate, RSTROBE_MAX);
rsetup = aemif_calc_rate(pdev, data->rsetup, clk_rate, RSETUP_MAX);
whold = aemif_calc_rate(pdev, data->whold, clk_rate, WHOLD_MAX);
wstrobe = aemif_calc_rate(pdev, data->wstrobe, clk_rate, WSTROBE_MAX);
wsetup = aemif_calc_rate(pdev, data->wsetup, clk_rate, WSETUP_MAX);
if (ta < 0 || rhold < 0 || rstrobe < 0 || rsetup < 0 ||
whold < 0 || wstrobe < 0 || wsetup < 0) {
dev_err(&pdev->dev, "%s: cannot get suitable timings\n",
__func__);
return -EINVAL;
}
set = TA(ta) | RHOLD(rhold) | RSTROBE(rstrobe) | RSETUP(rsetup) |
WHOLD(whold) | WSTROBE(wstrobe) | WSETUP(wsetup);
set |= (data->asize & ACR_ASIZE_MASK);
if (data->enable_ew)
set |= ACR_EW_MASK;
if (data->enable_ss)
set |= ACR_SS_MASK;
val = readl(aemif->base + offset);
val &= ~CONFIG_MASK;
val |= set;
writel(val, aemif->base + offset);
return 0;
}
static inline int aemif_cycles_to_nsec(int val, unsigned long clk_rate)
{
return ((val + 1) * NSEC_PER_MSEC) / clk_rate;
}
static void aemif_get_hw_params(struct platform_device *pdev, int csnum)
{
struct aemif_device *aemif = platform_get_drvdata(pdev);
struct aemif_cs_data *data = &aemif->cs_data[csnum];
unsigned long clk_rate = aemif->clk_rate;
u32 val, offset;
offset = A1CR_OFFSET + (data->cs - aemif->cs_offset) * 4;
val = readl(aemif->base + offset);
data->ta = aemif_cycles_to_nsec(TA_VAL(val), clk_rate);
data->rhold = aemif_cycles_to_nsec(RHOLD_VAL(val), clk_rate);
data->rstrobe = aemif_cycles_to_nsec(RSTROBE_VAL(val), clk_rate);
data->rsetup = aemif_cycles_to_nsec(RSETUP_VAL(val), clk_rate);
data->whold = aemif_cycles_to_nsec(WHOLD_VAL(val), clk_rate);
data->wstrobe = aemif_cycles_to_nsec(WSTROBE_VAL(val), clk_rate);
data->wsetup = aemif_cycles_to_nsec(WSETUP_VAL(val), clk_rate);
data->enable_ew = EW_VAL(val);
data->enable_ss = SS_VAL(val);
data->asize = val & ASIZE_MAX;
}
static int of_aemif_parse_abus_config(struct platform_device *pdev,
struct device_node *np)
{
struct aemif_device *aemif = platform_get_drvdata(pdev);
struct aemif_cs_data *data;
u32 cs;
u32 val;
if (of_property_read_u32(np, "ti,cs-chipselect", &cs)) {
dev_dbg(&pdev->dev, "cs property is required");
return -EINVAL;
}
if (cs - aemif->cs_offset >= NUM_CS || cs < aemif->cs_offset) {
dev_dbg(&pdev->dev, "cs number is incorrect %d", cs);
return -EINVAL;
}
if (aemif->num_cs >= NUM_CS) {
dev_dbg(&pdev->dev, "cs count is more than %d", NUM_CS);
return -EINVAL;
}
data = &aemif->cs_data[aemif->num_cs];
data->cs = cs;
aemif_get_hw_params(pdev, aemif->num_cs++);
if (!of_property_read_u32(np, "ti,cs-min-turnaround-ns", &val))
data->ta = val;
if (!of_property_read_u32(np, "ti,cs-read-hold-ns", &val))
data->rhold = val;
if (!of_property_read_u32(np, "ti,cs-read-strobe-ns", &val))
data->rstrobe = val;
if (!of_property_read_u32(np, "ti,cs-read-setup-ns", &val))
data->rsetup = val;
if (!of_property_read_u32(np, "ti,cs-write-hold-ns", &val))
data->whold = val;
if (!of_property_read_u32(np, "ti,cs-write-strobe-ns", &val))
data->wstrobe = val;
if (!of_property_read_u32(np, "ti,cs-write-setup-ns", &val))
data->wsetup = val;
if (!of_property_read_u32(np, "ti,cs-bus-width", &val))
if (val == 16)
data->asize = 1;
data->enable_ew = of_property_read_bool(np, "ti,cs-extended-wait-mode");
data->enable_ss = of_property_read_bool(np, "ti,cs-select-strobe-mode");
return 0;
}
static int aemif_probe(struct platform_device *pdev)
{
int i;
int ret = -ENODEV;
struct resource *res;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *child_np;
struct aemif_device *aemif;
struct aemif_platform_data *pdata;
struct of_dev_auxdata *dev_lookup;
if (np == NULL)
return 0;
aemif = devm_kzalloc(dev, sizeof(*aemif), GFP_KERNEL);
if (!aemif)
return -ENOMEM;
pdata = dev_get_platdata(&pdev->dev);
dev_lookup = pdata ? pdata->dev_lookup : NULL;
platform_set_drvdata(pdev, aemif);
aemif->clk = devm_clk_get(dev, NULL);
if (IS_ERR(aemif->clk)) {
dev_err(dev, "cannot get clock 'aemif'\n");
return PTR_ERR(aemif->clk);
}
clk_prepare_enable(aemif->clk);
aemif->clk_rate = clk_get_rate(aemif->clk) / MSEC_PER_SEC;
if (of_device_is_compatible(np, "ti,da850-aemif"))
aemif->cs_offset = 2;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
aemif->base = devm_ioremap_resource(dev, res);
if (IS_ERR(aemif->base)) {
ret = PTR_ERR(aemif->base);
goto error;
}
for_each_available_child_of_node(np, child_np) {
ret = of_aemif_parse_abus_config(pdev, child_np);
if (ret < 0)
goto error;
}
for (i = 0; i < aemif->num_cs; i++) {
ret = aemif_config_abus(pdev, i);
if (ret < 0) {
dev_err(dev, "Error configuring chip select %d\n",
aemif->cs_data[i].cs);
goto error;
}
}
for_each_available_child_of_node(np, child_np) {
ret = of_platform_populate(child_np, NULL, dev_lookup, dev);
if (ret < 0)
goto error;
}
return 0;
error:
clk_disable_unprepare(aemif->clk);
return ret;
}
static int aemif_remove(struct platform_device *pdev)
{
struct aemif_device *aemif = platform_get_drvdata(pdev);
clk_disable_unprepare(aemif->clk);
return 0;
}
