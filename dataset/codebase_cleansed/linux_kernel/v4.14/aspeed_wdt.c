static struct aspeed_wdt *to_aspeed_wdt(struct watchdog_device *wdd)
{
return container_of(wdd, struct aspeed_wdt, wdd);
}
static void aspeed_wdt_enable(struct aspeed_wdt *wdt, int count)
{
wdt->ctrl |= WDT_CTRL_ENABLE;
writel(0, wdt->base + WDT_CTRL);
writel(count, wdt->base + WDT_RELOAD_VALUE);
writel(WDT_RESTART_MAGIC, wdt->base + WDT_RESTART);
writel(wdt->ctrl, wdt->base + WDT_CTRL);
}
static int aspeed_wdt_start(struct watchdog_device *wdd)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
aspeed_wdt_enable(wdt, wdd->timeout * WDT_RATE_1MHZ);
return 0;
}
static int aspeed_wdt_stop(struct watchdog_device *wdd)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
wdt->ctrl &= ~WDT_CTRL_ENABLE;
writel(wdt->ctrl, wdt->base + WDT_CTRL);
return 0;
}
static int aspeed_wdt_ping(struct watchdog_device *wdd)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
writel(WDT_RESTART_MAGIC, wdt->base + WDT_RESTART);
return 0;
}
static int aspeed_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
u32 actual;
wdd->timeout = timeout;
actual = min(timeout, wdd->max_hw_heartbeat_ms * 1000);
writel(actual * WDT_RATE_1MHZ, wdt->base + WDT_RELOAD_VALUE);
writel(WDT_RESTART_MAGIC, wdt->base + WDT_RESTART);
return 0;
}
static int aspeed_wdt_restart(struct watchdog_device *wdd,
unsigned long action, void *data)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
aspeed_wdt_enable(wdt, 128 * WDT_RATE_1MHZ / 1000);
mdelay(1000);
return 0;
}
static int aspeed_wdt_probe(struct platform_device *pdev)
{
const struct aspeed_wdt_config *config;
const struct of_device_id *ofdid;
struct aspeed_wdt *wdt;
struct resource *res;
struct device_node *np;
const char *reset_type;
u32 duration;
int ret;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
wdt->wdd.info = &aspeed_wdt_info;
wdt->wdd.ops = &aspeed_wdt_ops;
wdt->wdd.max_hw_heartbeat_ms = WDT_MAX_TIMEOUT_MS;
wdt->wdd.parent = &pdev->dev;
wdt->wdd.timeout = WDT_DEFAULT_TIMEOUT;
watchdog_init_timeout(&wdt->wdd, 0, &pdev->dev);
np = pdev->dev.of_node;
ofdid = of_match_node(aspeed_wdt_of_table, np);
if (!ofdid)
return -EINVAL;
config = ofdid->data;
wdt->ctrl = WDT_CTRL_1MHZ_CLK;
ret = of_property_read_string(np, "aspeed,reset-type", &reset_type);
if (ret) {
wdt->ctrl |= WDT_CTRL_RESET_MODE_SOC | WDT_CTRL_RESET_SYSTEM;
} else {
if (!strcmp(reset_type, "cpu"))
wdt->ctrl |= WDT_CTRL_RESET_MODE_ARM_CPU;
else if (!strcmp(reset_type, "soc"))
wdt->ctrl |= WDT_CTRL_RESET_MODE_SOC;
else if (!strcmp(reset_type, "system"))
wdt->ctrl |= WDT_CTRL_RESET_SYSTEM;
else if (strcmp(reset_type, "none"))
return -EINVAL;
}
if (of_property_read_bool(np, "aspeed,external-signal"))
wdt->ctrl |= WDT_CTRL_WDT_EXT;
writel(wdt->ctrl, wdt->base + WDT_CTRL);
if (readl(wdt->base + WDT_CTRL) & WDT_CTRL_ENABLE) {
aspeed_wdt_start(&wdt->wdd);
set_bit(WDOG_HW_RUNNING, &wdt->wdd.status);
}
if (of_device_is_compatible(np, "aspeed,ast2500-wdt")) {
u32 reg = readl(wdt->base + WDT_RESET_WIDTH);
reg &= config->ext_pulse_width_mask;
if (of_property_read_bool(np, "aspeed,ext-push-pull"))
reg |= WDT_PUSH_PULL_MAGIC;
else
reg |= WDT_OPEN_DRAIN_MAGIC;
writel(reg, wdt->base + WDT_RESET_WIDTH);
reg &= config->ext_pulse_width_mask;
if (of_property_read_bool(np, "aspeed,ext-active-high"))
reg |= WDT_ACTIVE_HIGH_MAGIC;
else
reg |= WDT_ACTIVE_LOW_MAGIC;
writel(reg, wdt->base + WDT_RESET_WIDTH);
}
if (!of_property_read_u32(np, "aspeed,ext-pulse-duration", &duration)) {
u32 max_duration = config->ext_pulse_width_mask + 1;
if (duration == 0 || duration > max_duration) {
dev_err(&pdev->dev, "Invalid pulse duration: %uus\n",
duration);
duration = max(1U, min(max_duration, duration));
dev_info(&pdev->dev, "Pulse duration set to %uus\n",
duration);
}
writel(duration - 1, wdt->base + WDT_RESET_WIDTH);
}
ret = devm_watchdog_register_device(&pdev->dev, &wdt->wdd);
if (ret) {
dev_err(&pdev->dev, "failed to register\n");
return ret;
}
return 0;
}
