int s3c_irq_wake(struct irq_data *data, unsigned int state)
{
unsigned long irqbit = 1 << (data->irq - IRQ_EINT0);
if (!(s3c_irqwake_intallow & irqbit))
return -ENOENT;
printk(KERN_INFO "wake %s for irq %d\n",
state ? "enabled" : "disabled", data->irq);
if (!state)
s3c_irqwake_intmask |= irqbit;
else
s3c_irqwake_intmask &= ~irqbit;
return 0;
}
int s3c24xx_irq_suspend(void)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(save_extint); i++)
save_extint[i] = __raw_readl(S3C24XX_EXTINT0 + (i*4));
for (i = 0; i < ARRAY_SIZE(save_eintflt); i++)
save_eintflt[i] = __raw_readl(S3C24XX_EINFLT0 + (i*4));
s3c_pm_do_save(irq_save, ARRAY_SIZE(irq_save));
save_eintmask = __raw_readl(S3C24XX_EINTMASK);
return 0;
}
void s3c24xx_irq_resume(void)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(save_extint); i++)
__raw_writel(save_extint[i], S3C24XX_EXTINT0 + (i*4));
for (i = 0; i < ARRAY_SIZE(save_eintflt); i++)
__raw_writel(save_eintflt[i], S3C24XX_EINFLT0 + (i*4));
s3c_pm_do_restore(irq_save, ARRAY_SIZE(irq_save));
__raw_writel(save_eintmask, S3C24XX_EINTMASK);
}
