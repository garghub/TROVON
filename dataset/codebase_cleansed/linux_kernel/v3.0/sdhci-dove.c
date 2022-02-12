static u16 sdhci_dove_readw(struct sdhci_host *host, int reg)
{
u16 ret;
switch (reg) {
case SDHCI_HOST_VERSION:
case SDHCI_SLOT_INT_STATUS:
return 0;
default:
ret = readw(host->ioaddr + reg);
}
return ret;
}
static u32 sdhci_dove_readl(struct sdhci_host *host, int reg)
{
u32 ret;
switch (reg) {
case SDHCI_CAPABILITIES:
ret = readl(host->ioaddr + reg);
ret &= ~SDHCI_CAN_VDD_300;
break;
default:
ret = readl(host->ioaddr + reg);
}
return ret;
}
