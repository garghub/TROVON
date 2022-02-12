static void simtec_audio_startup_lrroute(void)
{
unsigned int tmp;
unsigned long flags;
local_irq_save(flags);
tmp = __raw_readb(BAST_VA_CTRL1);
tmp &= ~BAST_CPLD_CTRL1_LRMASK;
tmp |= BAST_CPLD_CTRL1_LRCDAC;
__raw_writeb(tmp, BAST_VA_CTRL1);
local_irq_restore(flags);
}
int __init simtec_audio_add(const char *name, bool has_lr_routing,
struct s3c24xx_audio_simtec_pdata *spd)
{
if (!name)
name = "tlv320aic23";
snprintf(our_name, sizeof(our_name)-1, "s3c24xx-simtec-%s", name);
if (spd)
simtec_audio_platdata = *spd;
if (has_lr_routing)
simtec_audio_platdata.startup = simtec_audio_startup_lrroute;
platform_device_register(&s3c_device_iis);
platform_device_register(&simtec_audio_dev);
return 0;
}
