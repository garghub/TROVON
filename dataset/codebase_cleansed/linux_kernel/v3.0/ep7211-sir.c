static int __init ep7211_sir_init(void)
{
return irda_register_dongle(&ep7211);
}
static void __exit ep7211_sir_cleanup(void)
{
irda_unregister_dongle(&ep7211);
}
static int ep7211_open(struct sir_dev *dev)
{
unsigned int syscon;
syscon = clps_readl(SYSCON1);
syscon |= SYSCON1_SIREN;
clps_writel(syscon, SYSCON1);
return 0;
}
static int ep7211_close(struct sir_dev *dev)
{
unsigned int syscon;
syscon = clps_readl(SYSCON1);
syscon &= ~SYSCON1_SIREN;
clps_writel(syscon, SYSCON1);
return 0;
}
static int ep7211_change_speed(struct sir_dev *dev, unsigned speed)
{
return 0;
}
static int ep7211_reset(struct sir_dev *dev)
{
return 0;
}
