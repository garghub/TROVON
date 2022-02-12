static void hp6x0_apm_get_power_status(struct apm_power_info *info)
{
int battery, backup, charging, percentage;
u8 pgdr;
battery = adc_single(ADC_CHANNEL_BATTERY);
backup = adc_single(ADC_CHANNEL_BACKUP);
charging = adc_single(ADC_CHANNEL_CHARGE);
percentage = 100 * (battery - HP680_BATTERY_MIN) /
(HP680_BATTERY_MAX - HP680_BATTERY_MIN);
info->battery_life = percentage;
info->units = 0;
info->time = (2 * battery);
info->ac_line_status = (battery > HP680_BATTERY_AC_ON) ?
APM_AC_ONLINE : APM_AC_OFFLINE;
pgdr = __raw_readb(PGDR);
if (pgdr & PGDR_MAIN_BATTERY_OUT) {
info->battery_status = APM_BATTERY_STATUS_NOT_PRESENT;
info->battery_flag = 0x80;
} else if (charging < 8) {
info->battery_status = APM_BATTERY_STATUS_CHARGING;
info->battery_flag = 0x08;
info->ac_line_status = 0x01;
} else if (percentage <= APM_CRITICAL) {
info->battery_status = APM_BATTERY_STATUS_CRITICAL;
info->battery_flag = 0x04;
} else if (percentage <= APM_LOW) {
info->battery_status = APM_BATTERY_STATUS_LOW;
info->battery_flag = 0x02;
} else {
info->battery_status = APM_BATTERY_STATUS_HIGH;
info->battery_flag = 0x01;
}
}
static irqreturn_t hp6x0_apm_interrupt(int irq, void *dev)
{
if (!APM_DISABLED)
apm_queue_event(APM_USER_SUSPEND);
return IRQ_HANDLED;
}
static int __init hp6x0_apm_init(void)
{
int ret;
ret = request_irq(HP680_BTN_IRQ, hp6x0_apm_interrupt,
IRQF_DISABLED, MODNAME, NULL);
if (unlikely(ret < 0)) {
printk(KERN_ERR MODNAME ": IRQ %d request failed\n",
HP680_BTN_IRQ);
return ret;
}
apm_get_power_status = hp6x0_apm_get_power_status;
return ret;
}
static void __exit hp6x0_apm_exit(void)
{
free_irq(HP680_BTN_IRQ, 0);
}
