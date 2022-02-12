static void stmmac_timer_handler(void *data)
{
struct net_device *dev = (struct net_device *)data;
stmmac_schedule(dev);
}
static void stmmac_rtc_start(unsigned int new_freq)
{
rtc_irq_set_freq(stmmac_rtc, &stmmac_task, new_freq);
rtc_irq_set_state(stmmac_rtc, &stmmac_task, 1);
}
static void stmmac_rtc_stop(void)
{
rtc_irq_set_state(stmmac_rtc, &stmmac_task, 0);
}
int stmmac_open_ext_timer(struct net_device *dev, struct stmmac_timer *tm)
{
stmmac_task.private_data = dev;
stmmac_task.func = stmmac_timer_handler;
stmmac_rtc = rtc_class_open(CONFIG_RTC_HCTOSYS_DEVICE);
if (stmmac_rtc == NULL) {
pr_err("open rtc device failed\n");
return -ENODEV;
}
rtc_irq_register(stmmac_rtc, &stmmac_task);
if ((rtc_irq_set_freq(stmmac_rtc, &stmmac_task, tm->freq) < 0)) {
pr_err("set periodic failed\n");
rtc_irq_unregister(stmmac_rtc, &stmmac_task);
rtc_class_close(stmmac_rtc);
return -1;
}
STMMAC_TIMER_MSG(CONFIG_RTC_HCTOSYS_DEVICE, tm->freq);
tm->timer_start = stmmac_rtc_start;
tm->timer_stop = stmmac_rtc_stop;
return 0;
}
int stmmac_close_ext_timer(void)
{
rtc_irq_set_state(stmmac_rtc, &stmmac_task, 0);
rtc_irq_unregister(stmmac_rtc, &stmmac_task);
rtc_class_close(stmmac_rtc);
return 0;
}
static void stmmac_tmu_start(unsigned int new_freq)
{
clk_set_rate(timer_clock, new_freq);
clk_enable(timer_clock);
}
static void stmmac_tmu_stop(void)
{
clk_disable(timer_clock);
}
int stmmac_open_ext_timer(struct net_device *dev, struct stmmac_timer *tm)
{
timer_clock = clk_get(NULL, TMU_CHANNEL);
if (timer_clock == NULL)
return -1;
if (tmu2_register_user(stmmac_timer_handler, (void *)dev) < 0) {
timer_clock = NULL;
return -1;
}
STMMAC_TIMER_MSG("TMU2", tm->freq);
tm->timer_start = stmmac_tmu_start;
tm->timer_stop = stmmac_tmu_stop;
return 0;
}
int stmmac_close_ext_timer(void)
{
clk_disable(timer_clock);
tmu2_unregister_user();
clk_put(timer_clock);
return 0;
}
