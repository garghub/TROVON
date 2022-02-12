int s3c_irq_wake(struct irq_data *data, unsigned int state)
{
unsigned long irqbit;
unsigned int irq_rtc_tic, irq_rtc_alarm;
#ifdef CONFIG_ARCH_EXYNOS
if (soc_is_exynos5250()) {
irq_rtc_tic = EXYNOS5_IRQ_RTC_TIC;
irq_rtc_alarm = EXYNOS5_IRQ_RTC_ALARM;
} else {
irq_rtc_tic = EXYNOS4_IRQ_RTC_TIC;
irq_rtc_alarm = EXYNOS4_IRQ_RTC_ALARM;
}
#else
irq_rtc_tic = IRQ_RTC_TIC;
irq_rtc_alarm = IRQ_RTC_ALARM;
#endif
if (data->irq == irq_rtc_tic || data->irq == irq_rtc_alarm) {
irqbit = 1 << (data->irq + 1 - irq_rtc_alarm);
if (!state)
s3c_irqwake_intmask |= irqbit;
else
s3c_irqwake_intmask &= ~irqbit;
} else {
return -ENOENT;
}
return 0;
}
int s3c24xx_irq_suspend(void)
{
s3c_pm_do_save(eint_save, ARRAY_SIZE(eint_save));
return 0;
}
void s3c24xx_irq_resume(void)
{
s3c_pm_do_restore(eint_save, ARRAY_SIZE(eint_save));
}
