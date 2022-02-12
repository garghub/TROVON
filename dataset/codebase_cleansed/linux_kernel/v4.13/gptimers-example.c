static irqreturn_t gptimer_example_irq(int irq, void *dev_id)
{
struct gptimer_data *data = dev_id;
if (!get_gptimer_intr(TIMER5_id))
return IRQ_NONE;
data->width = get_gptimer_pwidth(TIMER5_id);
data->period = get_gptimer_period(TIMER5_id);
clear_gptimer_intr(TIMER5_id);
return IRQ_HANDLED;
}
static int __init gptimer_example_init(void)
{
int ret;
ret = peripheral_request(P_TMR5, DRIVER_NAME);
if (ret) {
printk(KERN_NOTICE DRIVER_NAME ": peripheral request failed\n");
return ret;
}
ret = request_irq(SAMPLE_IRQ_TIMER, gptimer_example_irq,
IRQF_SHARED, DRIVER_NAME, &data);
if (ret) {
printk(KERN_NOTICE DRIVER_NAME ": IRQ request failed\n");
peripheral_free(P_TMR5);
return ret;
}
set_gptimer_config(TIMER5_id,
WDTH_CAP | PULSE_HI | PERIOD_CNT | IRQ_ENA);
enable_gptimers(TIMER5bit);
return 0;
}
static void __exit gptimer_example_exit(void)
{
disable_gptimers(TIMER5bit);
free_irq(SAMPLE_IRQ_TIMER, &data);
peripheral_free(P_TMR5);
}
