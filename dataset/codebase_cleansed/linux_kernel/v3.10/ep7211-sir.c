static int clps711x_dongle_open(struct sir_dev *dev)
{
unsigned int syscon;
syscon = clps_readl(SYSCON1);
syscon |= SYSCON1_SIREN;
clps_writel(syscon, SYSCON1);
return 0;
}
static int clps711x_dongle_close(struct sir_dev *dev)
{
unsigned int syscon;
syscon = clps_readl(SYSCON1);
syscon &= ~SYSCON1_SIREN;
clps_writel(syscon, SYSCON1);
return 0;
}
static int clps711x_sir_probe(struct platform_device *pdev)
{
return irda_register_dongle(&clps711x_dongle);
}
static int clps711x_sir_remove(struct platform_device *pdev)
{
return irda_unregister_dongle(&clps711x_dongle);
}
