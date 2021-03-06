static irqreturn_t omap2_gp_timer_interrupt(int irq, void *dev_id)
{
struct omap_dm_timer *gpt = (struct omap_dm_timer *)dev_id;
struct clock_event_device *evt = &clockevent_gpt;
omap_dm_timer_write_status(gpt, OMAP_TIMER_INT_OVERFLOW);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int omap2_gp_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
omap_dm_timer_set_load_start(gptimer, 0, 0xffffffff - cycles);
return 0;
}
static void omap2_gp_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
u32 period;
omap_dm_timer_stop(gptimer);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
period = clk_get_rate(omap_dm_timer_get_fclk(gptimer)) / HZ;
period -= 1;
omap_dm_timer_set_load_start(gptimer, 1, 0xffffffff - period);
break;
case CLOCK_EVT_MODE_ONESHOT:
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
break;
}
}
int __init omap2_gp_clockevent_set_gptimer(u8 id)
{
if (id < 1 || id > MAX_GPTIMER_ID)
return -EINVAL;
BUG_ON(inited);
gptimer_id = id;
return 0;
}
static void __init omap2_gp_clockevent_init(void)
{
u32 tick_rate;
int src;
char clockevent_hwmod_name[8];
inited = 1;
sprintf(clockevent_hwmod_name, "timer%d", gptimer_id);
omap_hwmod_setup_one(clockevent_hwmod_name);
gptimer = omap_dm_timer_request_specific(gptimer_id);
BUG_ON(gptimer == NULL);
gptimer_wakeup = gptimer;
#if defined(CONFIG_OMAP_32K_TIMER)
src = OMAP_TIMER_SRC_32_KHZ;
#else
src = OMAP_TIMER_SRC_SYS_CLK;
WARN(gptimer_id == 12, "WARNING: GPTIMER12 can only use the "
"secure 32KiHz clock source\n");
#endif
if (gptimer_id != 12)
WARN(IS_ERR_VALUE(omap_dm_timer_set_source(gptimer, src)),
"timer-gp: omap_dm_timer_set_source() failed\n");
tick_rate = clk_get_rate(omap_dm_timer_get_fclk(gptimer));
pr_info("OMAP clockevent source: GPTIMER%d at %u Hz\n",
gptimer_id, tick_rate);
omap2_gp_timer_irq.dev_id = (void *)gptimer;
setup_irq(omap_dm_timer_get_irq(gptimer), &omap2_gp_timer_irq);
omap_dm_timer_set_int_enable(gptimer, OMAP_TIMER_INT_OVERFLOW);
clockevent_gpt.mult = div_sc(tick_rate, NSEC_PER_SEC,
clockevent_gpt.shift);
clockevent_gpt.max_delta_ns =
clockevent_delta2ns(0xffffffff, &clockevent_gpt);
clockevent_gpt.min_delta_ns =
clockevent_delta2ns(3, &clockevent_gpt);
clockevent_gpt.cpumask = cpumask_of(0);
clockevents_register_device(&clockevent_gpt);
}
static void __init omap2_gp_clocksource_init(void)
{
omap_init_clocksource_32k();
}
static cycle_t clocksource_read_cycles(struct clocksource *cs)
{
return (cycle_t)omap_dm_timer_read_counter(gpt_clocksource);
}
static void notrace dmtimer_update_sched_clock(void)
{
u32 cyc;
cyc = omap_dm_timer_read_counter(gpt_clocksource);
update_sched_clock(&cd, cyc, (u32)~0);
}
static void __init omap2_gp_clocksource_init(void)
{
static struct omap_dm_timer *gpt;
u32 tick_rate;
static char err1[] __initdata = KERN_ERR
"%s: failed to request dm-timer\n";
static char err2[] __initdata = KERN_ERR
"%s: can't register clocksource!\n";
gpt = omap_dm_timer_request();
if (!gpt)
printk(err1, clocksource_gpt.name);
gpt_clocksource = gpt;
omap_dm_timer_set_source(gpt, OMAP_TIMER_SRC_SYS_CLK);
tick_rate = clk_get_rate(omap_dm_timer_get_fclk(gpt));
omap_dm_timer_set_load_start(gpt, 1, 0);
init_sched_clock(&cd, dmtimer_update_sched_clock, 32, tick_rate);
if (clocksource_register_hz(&clocksource_gpt, tick_rate))
printk(err2, clocksource_gpt.name);
}
static void __init omap2_gp_timer_init(void)
{
#ifdef CONFIG_LOCAL_TIMERS
if (cpu_is_omap44xx()) {
twd_base = ioremap(OMAP44XX_LOCAL_TWD_BASE, SZ_256);
BUG_ON(!twd_base);
}
#endif
omap_dm_timer_init();
omap2_gp_clockevent_init();
omap2_gp_clocksource_init();
}
