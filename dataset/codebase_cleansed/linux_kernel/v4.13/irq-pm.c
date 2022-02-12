static int s3c64xx_irq_pm_suspend(void)
{
struct irq_grp_save *grp = eint_grp_save;
int i;
S3C_PMDBG("%s: suspending IRQs\n", __func__);
s3c_pm_do_save(irq_save, ARRAY_SIZE(irq_save));
for (i = 0; i < SERIAL_SAMSUNG_UARTS; i++)
irq_uart_mask[i] = __raw_readl(S3C_VA_UARTx(i) + S3C64XX_UINTM);
for (i = 0; i < ARRAY_SIZE(eint_grp_save); i++, grp++) {
grp->con = __raw_readl(S3C64XX_EINT12CON + (i * 4));
grp->mask = __raw_readl(S3C64XX_EINT12MASK + (i * 4));
grp->fltcon = __raw_readl(S3C64XX_EINT12FLTCON + (i * 4));
}
return 0;
}
static void s3c64xx_irq_pm_resume(void)
{
struct irq_grp_save *grp = eint_grp_save;
int i;
S3C_PMDBG("%s: resuming IRQs\n", __func__);
s3c_pm_do_restore(irq_save, ARRAY_SIZE(irq_save));
for (i = 0; i < SERIAL_SAMSUNG_UARTS; i++)
__raw_writel(irq_uart_mask[i], S3C_VA_UARTx(i) + S3C64XX_UINTM);
for (i = 0; i < ARRAY_SIZE(eint_grp_save); i++, grp++) {
__raw_writel(grp->con, S3C64XX_EINT12CON + (i * 4));
__raw_writel(grp->mask, S3C64XX_EINT12MASK + (i * 4));
__raw_writel(grp->fltcon, S3C64XX_EINT12FLTCON + (i * 4));
}
S3C_PMDBG("%s: IRQ configuration restored\n", __func__);
}
static __init int s3c64xx_syscore_init(void)
{
if (of_have_populated_dt() || !soc_is_s3c64xx())
return 0;
register_syscore_ops(&s3c64xx_irq_syscore_ops);
return 0;
}
