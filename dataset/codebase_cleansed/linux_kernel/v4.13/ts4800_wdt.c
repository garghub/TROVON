static void ts4800_write_feed(struct ts4800_wdt *wdt, u32 val)
{
regmap_write(wdt->regmap, wdt->feed_offset, val);
}
static int ts4800_wdt_start(struct watchdog_device *wdd)
{
struct ts4800_wdt *wdt = watchdog_get_drvdata(wdd);
ts4800_write_feed(wdt, wdt->feed_val);
return 0;
}
static int ts4800_wdt_stop(struct watchdog_device *wdd)
{
struct ts4800_wdt *wdt = watchdog_get_drvdata(wdd);
ts4800_write_feed(wdt, TS4800_WDT_DISABLE);
return 0;
}
static int ts4800_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct ts4800_wdt *wdt = watchdog_get_drvdata(wdd);
int i;
for (i = 0; i < MAX_TIMEOUT_INDEX; i++) {
if (ts4800_wdt_map[i].timeout >= timeout)
break;
}
wdd->timeout = ts4800_wdt_map[i].timeout;
wdt->feed_val = ts4800_wdt_map[i].regval;
return 0;
}
static int ts4800_wdt_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *syscon_np;
struct watchdog_device *wdd;
struct ts4800_wdt *wdt;
u32 reg;
int ret;
syscon_np = of_parse_phandle(np, "syscon", 0);
if (!syscon_np) {
dev_err(&pdev->dev, "no syscon property\n");
return -ENODEV;
}
ret = of_property_read_u32_index(np, "syscon", 1, &reg);
if (ret < 0) {
dev_err(&pdev->dev, "no offset in syscon\n");
return ret;
}
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->feed_offset = reg;
wdt->regmap = syscon_node_to_regmap(syscon_np);
if (IS_ERR(wdt->regmap)) {
dev_err(&pdev->dev, "cannot get parent's regmap\n");
return PTR_ERR(wdt->regmap);
}
wdd = &wdt->wdd;
wdd->parent = &pdev->dev;
wdd->info = &ts4800_wdt_info;
wdd->ops = &ts4800_wdt_ops;
wdd->min_timeout = ts4800_wdt_map[0].timeout;
wdd->max_timeout = ts4800_wdt_map[MAX_TIMEOUT_INDEX].timeout;
watchdog_set_drvdata(wdd, wdt);
watchdog_set_nowayout(wdd, nowayout);
watchdog_init_timeout(wdd, 0, &pdev->dev);
if (!wdd->timeout)
wdd->timeout = wdd->max_timeout;
ts4800_wdt_set_timeout(wdd, wdd->timeout);
ts4800_wdt_stop(wdd);
ret = watchdog_register_device(wdd);
if (ret) {
dev_err(&pdev->dev,
"failed to register watchdog device\n");
return ret;
}
platform_set_drvdata(pdev, wdt);
dev_info(&pdev->dev,
"initialized (timeout = %d sec, nowayout = %d)\n",
wdd->timeout, nowayout);
return 0;
}
static int ts4800_wdt_remove(struct platform_device *pdev)
{
struct ts4800_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdd);
return 0;
}
