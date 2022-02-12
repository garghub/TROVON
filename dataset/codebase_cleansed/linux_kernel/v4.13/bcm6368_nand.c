static bool bcm6368_nand_intc_ack(struct brcmnand_soc *soc)
{
struct bcm6368_nand_soc *priv =
container_of(soc, struct bcm6368_nand_soc, soc);
void __iomem *mmio = priv->base + BCM6368_NAND_INT;
u32 val = brcmnand_readl(mmio);
if (val & (BCM6368_CTRL_READY << BCM6368_NAND_STATUS_SHIFT)) {
val &= ~BCM6368_NAND_STATUS_MASK;
val |= BCM6368_CTRL_READY << BCM6368_NAND_STATUS_SHIFT;
brcmnand_writel(val, mmio);
return true;
}
return false;
}
static void bcm6368_nand_intc_set(struct brcmnand_soc *soc, bool en)
{
struct bcm6368_nand_soc *priv =
container_of(soc, struct bcm6368_nand_soc, soc);
void __iomem *mmio = priv->base + BCM6368_NAND_INT;
u32 val = brcmnand_readl(mmio);
val &= ~BCM6368_NAND_STATUS_MASK;
if (en)
val |= BCM6368_CTRL_READY << BCM6368_NAND_ENABLE_SHIFT;
else
val &= ~(BCM6368_CTRL_READY << BCM6368_NAND_ENABLE_SHIFT);
brcmnand_writel(val, mmio);
}
static int bcm6368_nand_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct bcm6368_nand_soc *priv;
struct brcmnand_soc *soc;
struct resource *res;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
soc = &priv->soc;
res = platform_get_resource_byname(pdev,
IORESOURCE_MEM, "nand-int-base");
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
soc->ctlrdy_ack = bcm6368_nand_intc_ack;
soc->ctlrdy_set_enabled = bcm6368_nand_intc_set;
brcmnand_writel(0, priv->base + BCM6368_NAND_INT);
brcmnand_writel(BCM6368_NAND_STATUS_MASK,
priv->base + BCM6368_NAND_INT);
return brcmnand_probe(pdev, soc);
}
