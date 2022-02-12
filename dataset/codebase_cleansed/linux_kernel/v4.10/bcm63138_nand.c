static bool bcm63138_nand_intc_ack(struct brcmnand_soc *soc)
{
struct bcm63138_nand_soc *priv =
container_of(soc, struct bcm63138_nand_soc, soc);
void __iomem *mmio = priv->base + BCM63138_NAND_INT_STATUS;
u32 val = brcmnand_readl(mmio);
if (val & BCM63138_CTLRDY) {
brcmnand_writel(val & ~BCM63138_CTLRDY, mmio);
return true;
}
return false;
}
static void bcm63138_nand_intc_set(struct brcmnand_soc *soc, bool en)
{
struct bcm63138_nand_soc *priv =
container_of(soc, struct bcm63138_nand_soc, soc);
void __iomem *mmio = priv->base + BCM63138_NAND_INT_EN;
u32 val = brcmnand_readl(mmio);
if (en)
val |= BCM63138_CTLRDY;
else
val &= ~BCM63138_CTLRDY;
brcmnand_writel(val, mmio);
}
static int bcm63138_nand_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct bcm63138_nand_soc *priv;
struct brcmnand_soc *soc;
struct resource *res;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
soc = &priv->soc;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand-int-base");
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
soc->ctlrdy_ack = bcm63138_nand_intc_ack;
soc->ctlrdy_set_enabled = bcm63138_nand_intc_set;
return brcmnand_probe(pdev, soc);
}
