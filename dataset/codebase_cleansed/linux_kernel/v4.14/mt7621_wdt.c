static inline void rt_wdt_w32(unsigned reg, u32 val)
{
iowrite32(val, mt7621_wdt_base + reg);
}
static inline u32 rt_wdt_r32(unsigned reg)
{
return ioread32(mt7621_wdt_base + reg);
}
static int mt7621_wdt_ping(struct watchdog_device *w)
{
rt_wdt_w32(TIMER_REG_TMRSTAT, TMR1CTL_RESTART);
return 0;
}
static int mt7621_wdt_set_timeout(struct watchdog_device *w, unsigned int t)
{
w->timeout = t;
rt_wdt_w32(TIMER_REG_TMR1LOAD, t * 1000);
mt7621_wdt_ping(w);
return 0;
}
static int mt7621_wdt_start(struct watchdog_device *w)
{
u32 t;
rt_wdt_w32(TIMER_REG_TMR1CTL, 1000 << TMR1CTL_PRESCALE_SHIFT);
mt7621_wdt_set_timeout(w, w->timeout);
t = rt_wdt_r32(TIMER_REG_TMR1CTL);
t |= TMR1CTL_ENABLE;
rt_wdt_w32(TIMER_REG_TMR1CTL, t);
return 0;
}
static int mt7621_wdt_stop(struct watchdog_device *w)
{
u32 t;
mt7621_wdt_ping(w);
t = rt_wdt_r32(TIMER_REG_TMR1CTL);
t &= ~TMR1CTL_ENABLE;
rt_wdt_w32(TIMER_REG_TMR1CTL, t);
return 0;
}
static int mt7621_wdt_bootcause(void)
{
if (rt_sysc_r32(SYSC_RSTSTAT) & WDT_RST_CAUSE)
return WDIOF_CARDRESET;
return 0;
}
static int mt7621_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mt7621_wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mt7621_wdt_base))
return PTR_ERR(mt7621_wdt_base);
mt7621_wdt_reset = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (!IS_ERR(mt7621_wdt_reset))
reset_control_deassert(mt7621_wdt_reset);
mt7621_wdt_dev.bootstatus = mt7621_wdt_bootcause();
watchdog_init_timeout(&mt7621_wdt_dev, mt7621_wdt_dev.max_timeout,
&pdev->dev);
watchdog_set_nowayout(&mt7621_wdt_dev, nowayout);
ret = watchdog_register_device(&mt7621_wdt_dev);
return 0;
}
static int mt7621_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&mt7621_wdt_dev);
return 0;
}
static void mt7621_wdt_shutdown(struct platform_device *pdev)
{
mt7621_wdt_stop(&mt7621_wdt_dev);
}
