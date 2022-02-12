static unsigned int sdhci_cns3xxx_get_max_clk(struct sdhci_host *host)
{
return 150000000;
}
static void sdhci_cns3xxx_set_clock(struct sdhci_host *host, unsigned int clock)
{
struct device *dev = mmc_dev(host->mmc);
int div = 1;
u16 clk;
unsigned long timeout;
if (clock == host->clock)
return;
sdhci_writew(host, 0, SDHCI_CLOCK_CONTROL);
if (clock == 0)
goto out;
while (host->max_clk / div > clock) {
if (div < 4)
div += 1;
else if (div < 256)
div *= 2;
else
break;
}
dev_dbg(dev, "desired SD clock: %d, actual: %d\n",
clock, host->max_clk / div);
if (div != 3)
div >>= 1;
clk = div << SDHCI_DIVIDER_SHIFT;
clk |= SDHCI_CLOCK_INT_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
timeout = 20;
while (!((clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL))
& SDHCI_CLOCK_INT_STABLE)) {
if (timeout == 0) {
dev_warn(dev, "clock is unstable");
break;
}
timeout--;
mdelay(1);
}
clk |= SDHCI_CLOCK_CARD_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
out:
host->clock = clock;
}
static int __devinit sdhci_cns3xxx_probe(struct platform_device *pdev)
{
return sdhci_pltfm_register(pdev, &sdhci_cns3xxx_pdata);
}
static int __devexit sdhci_cns3xxx_remove(struct platform_device *pdev)
{
return sdhci_pltfm_unregister(pdev);
}
