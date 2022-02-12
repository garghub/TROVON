static __init int pm_simtec_init(void)
{
unsigned long gstatus4;
if (!machine_is_bast() && !machine_is_vr1000() &&
!machine_is_anubis() && !machine_is_osiris() &&
!machine_is_aml_m5900())
return 0;
printk(KERN_INFO "Simtec Board Power Manangement" COPYRIGHT "\n");
gstatus4 = (__raw_readl(S3C2410_BANKCON7) & 0x3) << 30;
gstatus4 |= (__raw_readl(S3C2410_BANKCON6) & 0x3) << 28;
gstatus4 |= (__raw_readl(S3C2410_BANKSIZE) & S3C2410_BANKSIZE_MASK);
__raw_writel(gstatus4, S3C2410_GSTATUS4);
return s3c_pm_init();
}
