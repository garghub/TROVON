static int b53_srab_request_grant(struct b53_device *dev)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
u32 ctrls;
int i;
ctrls = readl(regs + B53_SRAB_CTRLS);
ctrls |= B53_SRAB_CTRLS_RCAREQ;
writel(ctrls, regs + B53_SRAB_CTRLS);
for (i = 0; i < 20; i++) {
ctrls = readl(regs + B53_SRAB_CTRLS);
if (ctrls & B53_SRAB_CTRLS_RCAGNT)
break;
usleep_range(10, 100);
}
if (WARN_ON(i == 5))
return -EIO;
return 0;
}
static void b53_srab_release_grant(struct b53_device *dev)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
u32 ctrls;
ctrls = readl(regs + B53_SRAB_CTRLS);
ctrls &= ~B53_SRAB_CTRLS_RCAREQ;
writel(ctrls, regs + B53_SRAB_CTRLS);
}
static int b53_srab_op(struct b53_device *dev, u8 page, u8 reg, u32 op)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int i;
u32 cmdstat;
cmdstat = (page << B53_SRAB_CMDSTAT_PAGE) |
(reg << B53_SRAB_CMDSTAT_REG) |
B53_SRAB_CMDSTAT_GORDYN |
op;
writel(cmdstat, regs + B53_SRAB_CMDSTAT);
for (i = 0; i < 5; ++i) {
cmdstat = readl(regs + B53_SRAB_CMDSTAT);
if (!(cmdstat & B53_SRAB_CMDSTAT_GORDYN))
break;
usleep_range(10, 100);
}
if (WARN_ON(i == 5))
return -EIO;
return 0;
}
static int b53_srab_read8(struct b53_device *dev, u8 page, u8 reg, u8 *val)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
ret = b53_srab_op(dev, page, reg, 0);
if (ret)
goto err;
*val = readl(regs + B53_SRAB_RD_L) & 0xff;
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_read16(struct b53_device *dev, u8 page, u8 reg, u16 *val)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
ret = b53_srab_op(dev, page, reg, 0);
if (ret)
goto err;
*val = readl(regs + B53_SRAB_RD_L) & 0xffff;
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_read32(struct b53_device *dev, u8 page, u8 reg, u32 *val)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
ret = b53_srab_op(dev, page, reg, 0);
if (ret)
goto err;
*val = readl(regs + B53_SRAB_RD_L);
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_read48(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
ret = b53_srab_op(dev, page, reg, 0);
if (ret)
goto err;
*val = readl(regs + B53_SRAB_RD_L);
*val += ((u64)readl(regs + B53_SRAB_RD_H) & 0xffff) << 32;
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_read64(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
ret = b53_srab_op(dev, page, reg, 0);
if (ret)
goto err;
*val = readl(regs + B53_SRAB_RD_L);
*val += (u64)readl(regs + B53_SRAB_RD_H) << 32;
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_write8(struct b53_device *dev, u8 page, u8 reg, u8 value)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
writel(value, regs + B53_SRAB_WD_L);
ret = b53_srab_op(dev, page, reg, B53_SRAB_CMDSTAT_WRITE);
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_write16(struct b53_device *dev, u8 page, u8 reg,
u16 value)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
writel(value, regs + B53_SRAB_WD_L);
ret = b53_srab_op(dev, page, reg, B53_SRAB_CMDSTAT_WRITE);
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_write32(struct b53_device *dev, u8 page, u8 reg,
u32 value)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
writel(value, regs + B53_SRAB_WD_L);
ret = b53_srab_op(dev, page, reg, B53_SRAB_CMDSTAT_WRITE);
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_write48(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
writel((u32)value, regs + B53_SRAB_WD_L);
writel((u16)(value >> 32), regs + B53_SRAB_WD_H);
ret = b53_srab_op(dev, page, reg, B53_SRAB_CMDSTAT_WRITE);
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_write64(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
struct b53_srab_priv *priv = dev->priv;
u8 __iomem *regs = priv->regs;
int ret = 0;
ret = b53_srab_request_grant(dev);
if (ret)
goto err;
writel((u32)value, regs + B53_SRAB_WD_L);
writel((u32)(value >> 32), regs + B53_SRAB_WD_H);
ret = b53_srab_op(dev, page, reg, B53_SRAB_CMDSTAT_WRITE);
err:
b53_srab_release_grant(dev);
return ret;
}
static int b53_srab_probe(struct platform_device *pdev)
{
struct b53_platform_data *pdata = pdev->dev.platform_data;
struct device_node *dn = pdev->dev.of_node;
const struct of_device_id *of_id = NULL;
struct b53_srab_priv *priv;
struct b53_device *dev;
struct resource *r;
if (dn)
of_id = of_match_node(b53_srab_of_match, dn);
if (of_id) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->chip_id = (u32)(unsigned long)of_id->data;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->regs))
return -ENOMEM;
dev = b53_switch_alloc(&pdev->dev, &b53_srab_ops, priv);
if (!dev)
return -ENOMEM;
if (pdata)
dev->pdata = pdata;
platform_set_drvdata(pdev, dev);
return b53_switch_register(dev);
}
static int b53_srab_remove(struct platform_device *pdev)
{
struct b53_device *dev = platform_get_drvdata(pdev);
if (dev)
b53_switch_remove(dev);
return 0;
}
