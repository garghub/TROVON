static void st_wdog_setup(struct st_wdog *st_wdog, bool enable)
{
if (st_wdog->syscfg->reset_type_reg)
regmap_update_bits(st_wdog->regmap,
st_wdog->syscfg->reset_type_reg,
st_wdog->syscfg->reset_type_mask,
st_wdog->warm_reset);
regmap_update_bits(st_wdog->regmap,
st_wdog->syscfg->enable_reg,
st_wdog->syscfg->enable_mask,
enable ? 0 : st_wdog->syscfg->enable_mask);
}
static void st_wdog_load_timer(struct st_wdog *st_wdog, unsigned int timeout)
{
unsigned long clkrate = st_wdog->clkrate;
writel_relaxed(timeout * clkrate, st_wdog->base + LPC_LPA_LSB_OFF);
writel_relaxed(1, st_wdog->base + LPC_LPA_START_OFF);
}
static int st_wdog_start(struct watchdog_device *wdd)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(wdd);
writel_relaxed(1, st_wdog->base + LPC_WDT_OFF);
return 0;
}
static int st_wdog_stop(struct watchdog_device *wdd)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(wdd);
writel_relaxed(0, st_wdog->base + LPC_WDT_OFF);
return 0;
}
static int st_wdog_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(wdd);
wdd->timeout = timeout;
st_wdog_load_timer(st_wdog, timeout);
return 0;
}
static int st_wdog_keepalive(struct watchdog_device *wdd)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(wdd);
st_wdog_load_timer(st_wdog, wdd->timeout);
return 0;
}
static int st_wdog_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device_node *np = pdev->dev.of_node;
struct st_wdog *st_wdog;
struct regmap *regmap;
struct resource *res;
struct clk *clk;
void __iomem *base;
uint32_t mode;
int ret;
ret = of_property_read_u32(np, "st,lpc-mode", &mode);
if (ret) {
dev_err(&pdev->dev, "An LPC mode must be provided\n");
return -EINVAL;
}
if (mode != ST_LPC_MODE_WDT)
return -ENODEV;
st_wdog = devm_kzalloc(&pdev->dev, sizeof(*st_wdog), GFP_KERNEL);
if (!st_wdog)
return -ENOMEM;
match = of_match_device(st_wdog_match, &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Couldn't match device\n");
return -ENODEV;
}
st_wdog->syscfg = (struct st_wdog_syscfg *)match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(regmap)) {
dev_err(&pdev->dev, "No syscfg phandle specified\n");
return PTR_ERR(regmap);
}
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Unable to request clock\n");
return PTR_ERR(clk);
}
st_wdog->dev = &pdev->dev;
st_wdog->base = base;
st_wdog->clk = clk;
st_wdog->regmap = regmap;
st_wdog->warm_reset = of_property_read_bool(np, "st,warm_reset");
st_wdog->clkrate = clk_get_rate(st_wdog->clk);
if (!st_wdog->clkrate) {
dev_err(&pdev->dev, "Unable to fetch clock rate\n");
return -EINVAL;
}
st_wdog_dev.max_timeout = 0xFFFFFFFF / st_wdog->clkrate;
st_wdog_dev.parent = &pdev->dev;
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable clock\n");
return ret;
}
watchdog_set_drvdata(&st_wdog_dev, st_wdog);
watchdog_set_nowayout(&st_wdog_dev, WATCHDOG_NOWAYOUT);
ret = watchdog_init_timeout(&st_wdog_dev, 0, &pdev->dev);
if (ret) {
dev_err(&pdev->dev, "Unable to initialise watchdog timeout\n");
clk_disable_unprepare(clk);
return ret;
}
ret = watchdog_register_device(&st_wdog_dev);
if (ret) {
dev_err(&pdev->dev, "Unable to register watchdog\n");
clk_disable_unprepare(clk);
return ret;
}
st_wdog_setup(st_wdog, true);
dev_info(&pdev->dev, "LPC Watchdog driver registered, reset type is %s",
st_wdog->warm_reset ? "warm" : "cold");
return ret;
}
static int st_wdog_remove(struct platform_device *pdev)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(&st_wdog_dev);
st_wdog_setup(st_wdog, false);
watchdog_unregister_device(&st_wdog_dev);
clk_disable_unprepare(st_wdog->clk);
return 0;
}
static int st_wdog_suspend(struct device *dev)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(&st_wdog_dev);
if (watchdog_active(&st_wdog_dev))
st_wdog_stop(&st_wdog_dev);
st_wdog_setup(st_wdog, false);
clk_disable(st_wdog->clk);
return 0;
}
static int st_wdog_resume(struct device *dev)
{
struct st_wdog *st_wdog = watchdog_get_drvdata(&st_wdog_dev);
int ret;
ret = clk_enable(st_wdog->clk);
if (ret) {
dev_err(dev, "Unable to re-enable clock\n");
watchdog_unregister_device(&st_wdog_dev);
clk_unprepare(st_wdog->clk);
return ret;
}
st_wdog_setup(st_wdog, true);
if (watchdog_active(&st_wdog_dev)) {
st_wdog_load_timer(st_wdog, st_wdog_dev.timeout);
st_wdog_start(&st_wdog_dev);
}
return 0;
}
