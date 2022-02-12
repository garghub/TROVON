static void da850_sata_init(struct device *dev, void __iomem *pwrdn_reg,
void __iomem *ahci_base, u32 mpy)
{
unsigned int val;
val = readl(pwrdn_reg);
val &= ~BIT(0);
writel(val, pwrdn_reg);
val = SATA_PHY_MPY(mpy) | SATA_PHY_LOS(1) | SATA_PHY_RXCDR(4) |
SATA_PHY_RXEQ(1) | SATA_PHY_TXSWING(3) | SATA_PHY_ENPLL(1);
writel(val, ahci_base + SATA_P0PHYCR_REG);
}
static u32 ahci_da850_calculate_mpy(unsigned long refclk_rate)
{
u32 pll_output = 1500000000, needed;
WARN((refclk_rate % 10) != 0, "refclk must be divisible by 10");
needed = pll_output / (refclk_rate / 10);
switch (needed) {
case 50:
return 0x1;
case 60:
return 0x2;
case 80:
return 0x4;
case 100:
return 0x5;
case 120:
return 0x6;
case 125:
return 0x7;
case 150:
return 0x8;
case 200:
return 0x9;
case 250:
return 0xa;
default:
return 0;
}
}
static int ahci_da850_softreset(struct ata_link *link,
unsigned int *class, unsigned long deadline)
{
int pmp, ret;
pmp = sata_srst_pmp(link);
ret = ahci_do_softreset(link, class, pmp, deadline, ahci_check_ready);
if (pmp && ret == -EBUSY)
return ahci_do_softreset(link, class, 0,
deadline, ahci_check_ready);
return ret;
}
static int ahci_da850_hardreset(struct ata_link *link,
unsigned int *class, unsigned long deadline)
{
int ret, retry = HARDRESET_RETRIES;
bool online;
do {
ret = ahci_do_hardreset(link, class, deadline, &online);
if (online)
return ret;
} while (retry--);
return ret;
}
static int ahci_da850_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
void __iomem *pwrdn_reg;
struct resource *res;
struct clk *clk;
u32 mpy;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
if (!hpriv->clks[0]) {
clk = clk_get(dev, "fck");
if (IS_ERR(clk))
return PTR_ERR(clk);
hpriv->clks[0] = clk;
}
if (!hpriv->clks[1]) {
clk = clk_get(dev, "refclk");
if (IS_ERR(clk)) {
dev_err(dev, "unable to obtain the reference clock");
return -ENODEV;
}
hpriv->clks[1] = clk;
}
mpy = ahci_da850_calculate_mpy(clk_get_rate(hpriv->clks[1]));
if (mpy == 0) {
dev_err(dev, "invalid REFCLK multiplier value: 0x%x", mpy);
return -EINVAL;
}
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
rc = -ENODEV;
goto disable_resources;
}
pwrdn_reg = devm_ioremap(dev, res->start, resource_size(res));
if (!pwrdn_reg) {
rc = -ENOMEM;
goto disable_resources;
}
da850_sata_init(dev, pwrdn_reg, hpriv->mmio, mpy);
rc = ahci_platform_init_host(pdev, hpriv, &ahci_da850_port_info,
&ahci_platform_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
