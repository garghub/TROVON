static inline u32 zx2967_wdt_readl(struct zx2967_wdt *wdt, u16 reg)
{
return readl_relaxed(wdt->reg_base + reg);
}
static inline void zx2967_wdt_writel(struct zx2967_wdt *wdt, u16 reg, u32 val)
{
writel_relaxed(val | ZX2967_WDT_WRITEKEY, wdt->reg_base + reg);
}
static void zx2967_wdt_refresh(struct zx2967_wdt *wdt)
{
u32 val;
val = zx2967_wdt_readl(wdt, ZX2967_WDT_REFRESH_REG);
val ^= ZX2967_WDT_REFRESH_MASK;
zx2967_wdt_writel(wdt, ZX2967_WDT_REFRESH_REG,
val & ZX2967_WDT_VAL_MASK);
}
static int
zx2967_wdt_set_timeout(struct watchdog_device *wdd, unsigned int timeout)
{
struct zx2967_wdt *wdt = watchdog_get_drvdata(wdd);
unsigned int divisor = ZX2967_WDT_DIV_DEFAULT;
u32 count;
count = timeout * ZX2967_WDT_CLK_FREQ;
if (count > divisor * ZX2967_WDT_MAX_COUNT)
divisor = DIV_ROUND_UP(count, ZX2967_WDT_MAX_COUNT);
count = DIV_ROUND_UP(count, divisor);
zx2967_wdt_writel(wdt, ZX2967_WDT_CFG_REG,
ZX2967_WDT_CFG_DIV(divisor) & ZX2967_WDT_VAL_MASK);
zx2967_wdt_writel(wdt, ZX2967_WDT_LOAD_REG,
count & ZX2967_WDT_VAL_MASK);
zx2967_wdt_refresh(wdt);
wdd->timeout = (count * divisor) / ZX2967_WDT_CLK_FREQ;
return 0;
}
static void __zx2967_wdt_start(struct zx2967_wdt *wdt)
{
u32 val;
val = zx2967_wdt_readl(wdt, ZX2967_WDT_START_REG);
val |= ZX2967_WDT_START_EN;
zx2967_wdt_writel(wdt, ZX2967_WDT_START_REG,
val & ZX2967_WDT_VAL_MASK);
}
static void __zx2967_wdt_stop(struct zx2967_wdt *wdt)
{
u32 val;
val = zx2967_wdt_readl(wdt, ZX2967_WDT_START_REG);
val &= ~ZX2967_WDT_START_EN;
zx2967_wdt_writel(wdt, ZX2967_WDT_START_REG,
val & ZX2967_WDT_VAL_MASK);
}
static int zx2967_wdt_start(struct watchdog_device *wdd)
{
struct zx2967_wdt *wdt = watchdog_get_drvdata(wdd);
zx2967_wdt_set_timeout(wdd, wdd->timeout);
__zx2967_wdt_start(wdt);
return 0;
}
static int zx2967_wdt_stop(struct watchdog_device *wdd)
{
struct zx2967_wdt *wdt = watchdog_get_drvdata(wdd);
__zx2967_wdt_stop(wdt);
return 0;
}
static int zx2967_wdt_keepalive(struct watchdog_device *wdd)
{
struct zx2967_wdt *wdt = watchdog_get_drvdata(wdd);
zx2967_wdt_refresh(wdt);
return 0;
}
static void zx2967_wdt_reset_sysctrl(struct device *dev)
{
int ret;
void __iomem *regmap;
unsigned int offset, mask, config;
struct of_phandle_args out_args;
ret = of_parse_phandle_with_fixed_args(dev->of_node,
"zte,wdt-reset-sysctrl", 3, 0, &out_args);
if (ret)
return;
offset = out_args.args[0];
config = out_args.args[1];
mask = out_args.args[2];
regmap = syscon_node_to_regmap(out_args.np);
if (IS_ERR(regmap)) {
of_node_put(out_args.np);
return;
}
regmap_update_bits(regmap, offset, mask, config);
of_node_put(out_args.np);
}
static int zx2967_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct zx2967_wdt *wdt;
struct resource *base;
int ret;
struct reset_control *rstc;
wdt = devm_kzalloc(dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
platform_set_drvdata(pdev, wdt);
wdt->wdt_device.info = &zx2967_wdt_ident;
wdt->wdt_device.ops = &zx2967_wdt_ops;
wdt->wdt_device.timeout = ZX2967_WDT_DEFAULT_TIMEOUT;
wdt->wdt_device.max_timeout = ZX2967_WDT_MAX_TIMEOUT;
wdt->wdt_device.min_timeout = ZX2967_WDT_MIN_TIMEOUT;
wdt->wdt_device.parent = &pdev->dev;
base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->reg_base = devm_ioremap_resource(dev, base);
if (IS_ERR(wdt->reg_base))
return PTR_ERR(wdt->reg_base);
zx2967_wdt_reset_sysctrl(dev);
wdt->clock = devm_clk_get(dev, NULL);
if (IS_ERR(wdt->clock)) {
dev_err(dev, "failed to find watchdog clock source\n");
return PTR_ERR(wdt->clock);
}
ret = clk_prepare_enable(wdt->clock);
if (ret < 0) {
dev_err(dev, "failed to enable clock\n");
return ret;
}
clk_set_rate(wdt->clock, ZX2967_WDT_CLK_FREQ);
rstc = devm_reset_control_get_exclusive(dev, NULL);
if (IS_ERR(rstc)) {
dev_err(dev, "failed to get rstc");
ret = PTR_ERR(rstc);
goto err;
}
reset_control_assert(rstc);
reset_control_deassert(rstc);
watchdog_set_drvdata(&wdt->wdt_device, wdt);
watchdog_init_timeout(&wdt->wdt_device,
ZX2967_WDT_DEFAULT_TIMEOUT, dev);
watchdog_set_nowayout(&wdt->wdt_device, WATCHDOG_NOWAYOUT);
ret = watchdog_register_device(&wdt->wdt_device);
if (ret)
goto err;
dev_info(dev, "watchdog enabled (timeout=%d sec, nowayout=%d)",
wdt->wdt_device.timeout, WATCHDOG_NOWAYOUT);
return 0;
err:
clk_disable_unprepare(wdt->clock);
return ret;
}
static int zx2967_wdt_remove(struct platform_device *pdev)
{
struct zx2967_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdt_device);
clk_disable_unprepare(wdt->clock);
return 0;
}
