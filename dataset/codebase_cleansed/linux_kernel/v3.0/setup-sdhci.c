void s3c2416_setup_sdhci_cfg_card(struct platform_device *dev,
void __iomem *r,
struct mmc_ios *ios,
struct mmc_card *card)
{
u32 ctrl2, ctrl3;
ctrl2 = __raw_readl(r + S3C_SDHCI_CONTROL2);
ctrl2 &= S3C_SDHCI_CTRL2_SELBASECLK_MASK;
ctrl2 |= (S3C64XX_SDHCI_CTRL2_ENSTAASYNCCLR |
S3C64XX_SDHCI_CTRL2_ENCMDCNFMSK |
S3C_SDHCI_CTRL2_ENFBCLKRX |
S3C_SDHCI_CTRL2_DFCNT_NONE |
S3C_SDHCI_CTRL2_ENCLKOUTHOLD);
if (ios->clock < 25 * 1000000)
ctrl3 = (S3C_SDHCI_CTRL3_FCSEL3 |
S3C_SDHCI_CTRL3_FCSEL2 |
S3C_SDHCI_CTRL3_FCSEL1 |
S3C_SDHCI_CTRL3_FCSEL0);
else
ctrl3 = (S3C_SDHCI_CTRL3_FCSEL1 | S3C_SDHCI_CTRL3_FCSEL0);
__raw_writel(ctrl2, r + S3C_SDHCI_CONTROL2);
__raw_writel(ctrl3, r + S3C_SDHCI_CONTROL3);
}
