static inline unsigned int s3c2410wdt_max_timeout(struct clk *clock)
{
unsigned long freq = clk_get_rate(clock);
return S3C2410_WTCNT_MAXCNT / (freq / (S3C2410_WTCON_PRESCALE_MAX + 1)
/ S3C2410_WTCON_MAXDIV);
}
static inline struct s3c2410_wdt *freq_to_wdt(struct notifier_block *nb)
{
return container_of(nb, struct s3c2410_wdt, freq_transition);
}
static int s3c2410wdt_mask_and_disable_reset(struct s3c2410_wdt *wdt, bool mask)
{
int ret;
u32 mask_val = 1 << wdt->drv_data->mask_bit;
u32 val = 0;
if (!(wdt->drv_data->quirks & QUIRK_HAS_PMU_CONFIG))
return 0;
if (mask)
val = mask_val;
ret = regmap_update_bits(wdt->pmureg,
wdt->drv_data->disable_reg,
mask_val, val);
if (ret < 0)
goto error;
ret = regmap_update_bits(wdt->pmureg,
wdt->drv_data->mask_reset_reg,
mask_val, val);
error:
if (ret < 0)
dev_err(wdt->dev, "failed to update reg(%d)\n", ret);
return ret;
}
static int s3c2410wdt_keepalive(struct watchdog_device *wdd)
{
struct s3c2410_wdt *wdt = watchdog_get_drvdata(wdd);
spin_lock(&wdt->lock);
writel(wdt->count, wdt->reg_base + S3C2410_WTCNT);
spin_unlock(&wdt->lock);
return 0;
}
static void __s3c2410wdt_stop(struct s3c2410_wdt *wdt)
{
unsigned long wtcon;
wtcon = readl(wdt->reg_base + S3C2410_WTCON);
wtcon &= ~(S3C2410_WTCON_ENABLE | S3C2410_WTCON_RSTEN);
writel(wtcon, wdt->reg_base + S3C2410_WTCON);
}
static int s3c2410wdt_stop(struct watchdog_device *wdd)
{
struct s3c2410_wdt *wdt = watchdog_get_drvdata(wdd);
spin_lock(&wdt->lock);
__s3c2410wdt_stop(wdt);
spin_unlock(&wdt->lock);
return 0;
}
static int s3c2410wdt_start(struct watchdog_device *wdd)
{
unsigned long wtcon;
struct s3c2410_wdt *wdt = watchdog_get_drvdata(wdd);
spin_lock(&wdt->lock);
__s3c2410wdt_stop(wdt);
wtcon = readl(wdt->reg_base + S3C2410_WTCON);
wtcon |= S3C2410_WTCON_ENABLE | S3C2410_WTCON_DIV128;
if (soft_noboot) {
wtcon |= S3C2410_WTCON_INTEN;
wtcon &= ~S3C2410_WTCON_RSTEN;
} else {
wtcon &= ~S3C2410_WTCON_INTEN;
wtcon |= S3C2410_WTCON_RSTEN;
}
dev_dbg(wdt->dev, "Starting watchdog: count=0x%08x, wtcon=%08lx\n",
wdt->count, wtcon);
writel(wdt->count, wdt->reg_base + S3C2410_WTDAT);
writel(wdt->count, wdt->reg_base + S3C2410_WTCNT);
writel(wtcon, wdt->reg_base + S3C2410_WTCON);
spin_unlock(&wdt->lock);
return 0;
}
static inline int s3c2410wdt_is_running(struct s3c2410_wdt *wdt)
{
return readl(wdt->reg_base + S3C2410_WTCON) & S3C2410_WTCON_ENABLE;
}
static int s3c2410wdt_set_heartbeat(struct watchdog_device *wdd,
unsigned int timeout)
{
struct s3c2410_wdt *wdt = watchdog_get_drvdata(wdd);
unsigned long freq = clk_get_rate(wdt->clock);
unsigned int count;
unsigned int divisor = 1;
unsigned long wtcon;
if (timeout < 1)
return -EINVAL;
freq = DIV_ROUND_UP(freq, 128);
count = timeout * freq;
dev_dbg(wdt->dev, "Heartbeat: count=%d, timeout=%d, freq=%lu\n",
count, timeout, freq);
if (count >= 0x10000) {
divisor = DIV_ROUND_UP(count, 0xffff);
if (divisor > 0x100) {
dev_err(wdt->dev, "timeout %d too big\n", timeout);
return -EINVAL;
}
}
dev_dbg(wdt->dev, "Heartbeat: timeout=%d, divisor=%d, count=%d (%08x)\n",
timeout, divisor, count, DIV_ROUND_UP(count, divisor));
count = DIV_ROUND_UP(count, divisor);
wdt->count = count;
wtcon = readl(wdt->reg_base + S3C2410_WTCON);
wtcon &= ~S3C2410_WTCON_PRESCALE_MASK;
wtcon |= S3C2410_WTCON_PRESCALE(divisor-1);
writel(count, wdt->reg_base + S3C2410_WTDAT);
writel(wtcon, wdt->reg_base + S3C2410_WTCON);
wdd->timeout = (count * divisor) / freq;
return 0;
}
static int s3c2410wdt_restart(struct watchdog_device *wdd, unsigned long action,
void *data)
{
struct s3c2410_wdt *wdt = watchdog_get_drvdata(wdd);
void __iomem *wdt_base = wdt->reg_base;
writel(0, wdt_base + S3C2410_WTCON);
writel(0x80, wdt_base + S3C2410_WTCNT);
writel(0x80, wdt_base + S3C2410_WTDAT);
writel(S3C2410_WTCON_ENABLE | S3C2410_WTCON_DIV16 |
S3C2410_WTCON_RSTEN | S3C2410_WTCON_PRESCALE(0x20),
wdt_base + S3C2410_WTCON);
mdelay(500);
return 0;
}
static irqreturn_t s3c2410wdt_irq(int irqno, void *param)
{
struct s3c2410_wdt *wdt = platform_get_drvdata(param);
dev_info(wdt->dev, "watchdog timer expired (irq)\n");
s3c2410wdt_keepalive(&wdt->wdt_device);
if (wdt->drv_data->quirks & QUIRK_HAS_WTCLRINT_REG)
writel(0x1, wdt->reg_base + S3C2410_WTCLRINT);
return IRQ_HANDLED;
}
static int s3c2410wdt_cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
int ret;
struct s3c2410_wdt *wdt = freq_to_wdt(nb);
if (!s3c2410wdt_is_running(wdt))
goto done;
if (val == CPUFREQ_PRECHANGE) {
s3c2410wdt_keepalive(&wdt->wdt_device);
} else if (val == CPUFREQ_POSTCHANGE) {
s3c2410wdt_stop(&wdt->wdt_device);
ret = s3c2410wdt_set_heartbeat(&wdt->wdt_device,
wdt->wdt_device.timeout);
if (ret >= 0)
s3c2410wdt_start(&wdt->wdt_device);
else
goto err;
}
done:
return 0;
err:
dev_err(wdt->dev, "cannot set new value for timeout %d\n",
wdt->wdt_device.timeout);
return ret;
}
static inline int s3c2410wdt_cpufreq_register(struct s3c2410_wdt *wdt)
{
wdt->freq_transition.notifier_call = s3c2410wdt_cpufreq_transition;
return cpufreq_register_notifier(&wdt->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline void s3c2410wdt_cpufreq_deregister(struct s3c2410_wdt *wdt)
{
wdt->freq_transition.notifier_call = s3c2410wdt_cpufreq_transition;
cpufreq_unregister_notifier(&wdt->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline int s3c2410wdt_cpufreq_register(struct s3c2410_wdt *wdt)
{
return 0;
}
static inline void s3c2410wdt_cpufreq_deregister(struct s3c2410_wdt *wdt)
{
}
static inline unsigned int s3c2410wdt_get_bootstatus(struct s3c2410_wdt *wdt)
{
unsigned int rst_stat;
int ret;
if (!(wdt->drv_data->quirks & QUIRK_HAS_RST_STAT))
return 0;
ret = regmap_read(wdt->pmureg, wdt->drv_data->rst_stat_reg, &rst_stat);
if (ret)
dev_warn(wdt->dev, "Couldn't get RST_STAT register\n");
else if (rst_stat & BIT(wdt->drv_data->rst_stat_bit))
return WDIOF_CARDRESET;
return 0;
}
static inline const struct s3c2410_wdt_variant *
s3c2410_get_wdt_drv_data(struct platform_device *pdev)
{
const struct s3c2410_wdt_variant *variant;
variant = of_device_get_match_data(&pdev->dev);
if (!variant) {
variant = (struct s3c2410_wdt_variant *)
platform_get_device_id(pdev)->driver_data;
}
return variant;
}
static int s3c2410wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct s3c2410_wdt *wdt;
struct resource *wdt_mem;
struct resource *wdt_irq;
unsigned int wtcon;
int started = 0;
int ret;
wdt = devm_kzalloc(dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->dev = dev;
spin_lock_init(&wdt->lock);
wdt->wdt_device = s3c2410_wdd;
wdt->drv_data = s3c2410_get_wdt_drv_data(pdev);
if (wdt->drv_data->quirks & QUIRKS_HAVE_PMUREG) {
wdt->pmureg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,syscon-phandle");
if (IS_ERR(wdt->pmureg)) {
dev_err(dev, "syscon regmap lookup failed.\n");
return PTR_ERR(wdt->pmureg);
}
}
wdt_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (wdt_irq == NULL) {
dev_err(dev, "no irq resource specified\n");
ret = -ENOENT;
goto err;
}
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->reg_base = devm_ioremap_resource(dev, wdt_mem);
if (IS_ERR(wdt->reg_base)) {
ret = PTR_ERR(wdt->reg_base);
goto err;
}
wdt->clock = devm_clk_get(dev, "watchdog");
if (IS_ERR(wdt->clock)) {
dev_err(dev, "failed to find watchdog clock source\n");
ret = PTR_ERR(wdt->clock);
goto err;
}
ret = clk_prepare_enable(wdt->clock);
if (ret < 0) {
dev_err(dev, "failed to enable clock\n");
return ret;
}
wdt->wdt_device.min_timeout = 1;
wdt->wdt_device.max_timeout = s3c2410wdt_max_timeout(wdt->clock);
ret = s3c2410wdt_cpufreq_register(wdt);
if (ret < 0) {
dev_err(dev, "failed to register cpufreq\n");
goto err_clk;
}
watchdog_set_drvdata(&wdt->wdt_device, wdt);
watchdog_init_timeout(&wdt->wdt_device, tmr_margin, dev);
ret = s3c2410wdt_set_heartbeat(&wdt->wdt_device,
wdt->wdt_device.timeout);
if (ret) {
started = s3c2410wdt_set_heartbeat(&wdt->wdt_device,
S3C2410_WATCHDOG_DEFAULT_TIME);
if (started == 0)
dev_info(dev,
"tmr_margin value out of range, default %d used\n",
S3C2410_WATCHDOG_DEFAULT_TIME);
else
dev_info(dev, "default timer value is out of range, cannot start\n");
}
ret = devm_request_irq(dev, wdt_irq->start, s3c2410wdt_irq, 0,
pdev->name, pdev);
if (ret != 0) {
dev_err(dev, "failed to install irq (%d)\n", ret);
goto err_cpufreq;
}
watchdog_set_nowayout(&wdt->wdt_device, nowayout);
watchdog_set_restart_priority(&wdt->wdt_device, 128);
wdt->wdt_device.bootstatus = s3c2410wdt_get_bootstatus(wdt);
wdt->wdt_device.parent = dev;
ret = watchdog_register_device(&wdt->wdt_device);
if (ret) {
dev_err(dev, "cannot register watchdog (%d)\n", ret);
goto err_cpufreq;
}
ret = s3c2410wdt_mask_and_disable_reset(wdt, false);
if (ret < 0)
goto err_unregister;
if (tmr_atboot && started == 0) {
dev_info(dev, "starting watchdog timer\n");
s3c2410wdt_start(&wdt->wdt_device);
} else if (!tmr_atboot) {
s3c2410wdt_stop(&wdt->wdt_device);
}
platform_set_drvdata(pdev, wdt);
wtcon = readl(wdt->reg_base + S3C2410_WTCON);
dev_info(dev, "watchdog %sactive, reset %sabled, irq %sabled\n",
(wtcon & S3C2410_WTCON_ENABLE) ? "" : "in",
(wtcon & S3C2410_WTCON_RSTEN) ? "en" : "dis",
(wtcon & S3C2410_WTCON_INTEN) ? "en" : "dis");
return 0;
err_unregister:
watchdog_unregister_device(&wdt->wdt_device);
err_cpufreq:
s3c2410wdt_cpufreq_deregister(wdt);
err_clk:
clk_disable_unprepare(wdt->clock);
err:
return ret;
}
static int s3c2410wdt_remove(struct platform_device *dev)
{
int ret;
struct s3c2410_wdt *wdt = platform_get_drvdata(dev);
ret = s3c2410wdt_mask_and_disable_reset(wdt, true);
if (ret < 0)
return ret;
watchdog_unregister_device(&wdt->wdt_device);
s3c2410wdt_cpufreq_deregister(wdt);
clk_disable_unprepare(wdt->clock);
return 0;
}
static void s3c2410wdt_shutdown(struct platform_device *dev)
{
struct s3c2410_wdt *wdt = platform_get_drvdata(dev);
s3c2410wdt_mask_and_disable_reset(wdt, true);
s3c2410wdt_stop(&wdt->wdt_device);
}
static int s3c2410wdt_suspend(struct device *dev)
{
int ret;
struct s3c2410_wdt *wdt = dev_get_drvdata(dev);
wdt->wtcon_save = readl(wdt->reg_base + S3C2410_WTCON);
wdt->wtdat_save = readl(wdt->reg_base + S3C2410_WTDAT);
ret = s3c2410wdt_mask_and_disable_reset(wdt, true);
if (ret < 0)
return ret;
s3c2410wdt_stop(&wdt->wdt_device);
return 0;
}
static int s3c2410wdt_resume(struct device *dev)
{
int ret;
struct s3c2410_wdt *wdt = dev_get_drvdata(dev);
writel(wdt->wtdat_save, wdt->reg_base + S3C2410_WTDAT);
writel(wdt->wtdat_save, wdt->reg_base + S3C2410_WTCNT);
writel(wdt->wtcon_save, wdt->reg_base + S3C2410_WTCON);
ret = s3c2410wdt_mask_and_disable_reset(wdt, false);
if (ret < 0)
return ret;
dev_info(dev, "watchdog %sabled\n",
(wdt->wtcon_save & S3C2410_WTCON_ENABLE) ? "en" : "dis");
return 0;
}
