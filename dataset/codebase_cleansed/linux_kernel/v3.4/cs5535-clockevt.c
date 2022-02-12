static void disable_timer(struct cs5535_mfgpt_timer *timer)
{
cs5535_mfgpt_write(timer, MFGPT_REG_SETUP,
(uint16_t) ~MFGPT_SETUP_CNTEN | MFGPT_SETUP_CMP1 |
MFGPT_SETUP_CMP2);
}
static void start_timer(struct cs5535_mfgpt_timer *timer, uint16_t delta)
{
cs5535_mfgpt_write(timer, MFGPT_REG_CMP2, delta);
cs5535_mfgpt_write(timer, MFGPT_REG_COUNTER, 0);
cs5535_mfgpt_write(timer, MFGPT_REG_SETUP,
MFGPT_SETUP_CNTEN | MFGPT_SETUP_CMP2);
}
static void mfgpt_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
disable_timer(cs5535_event_clock);
if (mode == CLOCK_EVT_MODE_PERIODIC)
start_timer(cs5535_event_clock, MFGPT_PERIODIC);
cs5535_tick_mode = mode;
}
static int mfgpt_next_event(unsigned long delta, struct clock_event_device *evt)
{
start_timer(cs5535_event_clock, delta);
return 0;
}
static irqreturn_t mfgpt_tick(int irq, void *dev_id)
{
uint16_t val = cs5535_mfgpt_read(cs5535_event_clock, MFGPT_REG_SETUP);
if (!(val & (MFGPT_SETUP_SETUP | MFGPT_SETUP_CMP2 | MFGPT_SETUP_CMP1)))
return IRQ_NONE;
disable_timer(cs5535_event_clock);
if (cs5535_tick_mode == CLOCK_EVT_MODE_SHUTDOWN)
return IRQ_HANDLED;
cs5535_mfgpt_write(cs5535_event_clock, MFGPT_REG_COUNTER, 0);
if (cs5535_tick_mode == CLOCK_EVT_MODE_PERIODIC)
cs5535_mfgpt_write(cs5535_event_clock, MFGPT_REG_SETUP,
MFGPT_SETUP_CNTEN | MFGPT_SETUP_CMP2);
cs5535_clockevent.event_handler(&cs5535_clockevent);
return IRQ_HANDLED;
}
static int __init cs5535_mfgpt_init(void)
{
struct cs5535_mfgpt_timer *timer;
int ret;
uint16_t val;
timer = cs5535_mfgpt_alloc_timer(MFGPT_TIMER_ANY, MFGPT_DOMAIN_WORKING);
if (!timer) {
printk(KERN_ERR DRV_NAME ": Could not allocate MFPGT timer\n");
return -ENODEV;
}
cs5535_event_clock = timer;
if (cs5535_mfgpt_setup_irq(timer, MFGPT_CMP2, &timer_irq)) {
printk(KERN_ERR DRV_NAME ": Could not set up IRQ %d\n",
timer_irq);
goto err_timer;
}
ret = setup_irq(timer_irq, &mfgptirq);
if (ret) {
printk(KERN_ERR DRV_NAME ": Unable to set up the interrupt.\n");
goto err_irq;
}
val = MFGPT_SCALE | (3 << 8);
cs5535_mfgpt_write(cs5535_event_clock, MFGPT_REG_SETUP, val);
cs5535_clockevent.mult = div_sc(MFGPT_HZ, NSEC_PER_SEC,
cs5535_clockevent.shift);
cs5535_clockevent.min_delta_ns = clockevent_delta2ns(0xF,
&cs5535_clockevent);
cs5535_clockevent.max_delta_ns = clockevent_delta2ns(0xFFFE,
&cs5535_clockevent);
printk(KERN_INFO DRV_NAME
": Registering MFGPT timer as a clock event, using IRQ %d\n",
timer_irq);
clockevents_register_device(&cs5535_clockevent);
return 0;
err_irq:
cs5535_mfgpt_release_irq(cs5535_event_clock, MFGPT_CMP2, &timer_irq);
err_timer:
cs5535_mfgpt_free_timer(cs5535_event_clock);
printk(KERN_ERR DRV_NAME ": Unable to set up the MFGPT clock source\n");
return -EIO;
}
