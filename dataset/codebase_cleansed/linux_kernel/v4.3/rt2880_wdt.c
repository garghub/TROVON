static inline void rt_wdt_w32(unsigned reg, u32 val)
{
iowrite32(val, rt288x_wdt_base + reg);
}
static inline u32 rt_wdt_r32(unsigned reg)
{
return ioread32(rt288x_wdt_base + reg);
}
static int rt288x_wdt_ping(struct watchdog_device *w)
{
rt_wdt_w32(TIMER_REG_TMR1LOAD, w->timeout * rt288x_wdt_freq);
return 0;
}
static int rt288x_wdt_start(struct watchdog_device *w)
{
u32 t;
t = rt_wdt_r32(TIMER_REG_TMR1CTL);
t &= ~(TMR1CTL_MODE_MASK << TMR1CTL_MODE_SHIFT |
TMR1CTL_PRESCALE_MASK);
t |= (TMR1CTL_MODE_WDT << TMR1CTL_MODE_SHIFT |
TMR1CTL_PRESCALE_65536);
rt_wdt_w32(TIMER_REG_TMR1CTL, t);
rt288x_wdt_ping(w);
t = rt_wdt_r32(TIMER_REG_TMR1CTL);
t |= TMR1CTL_ENABLE;
rt_wdt_w32(TIMER_REG_TMR1CTL, t);
return 0;
}
static int rt288x_wdt_stop(struct watchdog_device *w)
{
u32 t;
rt288x_wdt_ping(w);
t = rt_wdt_r32(TIMER_REG_TMR1CTL);
t &= ~TMR1CTL_ENABLE;
rt_wdt_w32(TIMER_REG_TMR1CTL, t);
return 0;
}
static int rt288x_wdt_set_timeout(struct watchdog_device *w, unsigned int t)
{
w->timeout = t;
rt288x_wdt_ping(w);
return 0;
}
static int rt288x_wdt_bootcause(void)
{
if (rt_sysc_r32(SYSC_RSTSTAT) & WDT_RST_CAUSE)
return WDIOF_CARDRESET;
return 0;
}
static int rt288x_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rt288x_wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rt288x_wdt_base))
return PTR_ERR(rt288x_wdt_base);
rt288x_wdt_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(rt288x_wdt_clk))
return PTR_ERR(rt288x_wdt_clk);
rt288x_wdt_reset = devm_reset_control_get(&pdev->dev, NULL);
if (!IS_ERR(rt288x_wdt_reset))
reset_control_deassert(rt288x_wdt_reset);
rt288x_wdt_freq = clk_get_rate(rt288x_wdt_clk) / RALINK_WDT_PRESCALE;
rt288x_wdt_dev.dev = &pdev->dev;
rt288x_wdt_dev.bootstatus = rt288x_wdt_bootcause();
rt288x_wdt_dev.max_timeout = (0xfffful / rt288x_wdt_freq);
rt288x_wdt_dev.parent = &pdev->dev;
watchdog_init_timeout(&rt288x_wdt_dev, rt288x_wdt_dev.max_timeout,
&pdev->dev);
watchdog_set_nowayout(&rt288x_wdt_dev, nowayout);
ret = watchdog_register_device(&rt288x_wdt_dev);
if (!ret)
dev_info(&pdev->dev, "Initialized\n");
return 0;
}
static int rt288x_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&rt288x_wdt_dev);
return 0;
}
static void rt288x_wdt_shutdown(struct platform_device *pdev)
{
rt288x_wdt_stop(&rt288x_wdt_dev);
}
