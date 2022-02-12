static u8 sja1000_ofp_read_reg(const struct sja1000_priv *priv, int reg)
{
return in_8(priv->reg_base + reg);
}
static void sja1000_ofp_write_reg(const struct sja1000_priv *priv,
int reg, u8 val)
{
out_8(priv->reg_base + reg, val);
}
static int __devexit sja1000_ofp_remove(struct platform_device *ofdev)
{
struct net_device *dev = dev_get_drvdata(&ofdev->dev);
struct sja1000_priv *priv = netdev_priv(dev);
struct device_node *np = ofdev->dev.of_node;
struct resource res;
dev_set_drvdata(&ofdev->dev, NULL);
unregister_sja1000dev(dev);
free_sja1000dev(dev);
iounmap(priv->reg_base);
irq_dispose_mapping(dev->irq);
of_address_to_resource(np, 0, &res);
release_mem_region(res.start, resource_size(&res));
return 0;
}
static int __devinit sja1000_ofp_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct net_device *dev;
struct sja1000_priv *priv;
struct resource res;
const u32 *prop;
int err, irq, res_size, prop_size;
void __iomem *base;
err = of_address_to_resource(np, 0, &res);
if (err) {
dev_err(&ofdev->dev, "invalid address\n");
return err;
}
res_size = resource_size(&res);
if (!request_mem_region(res.start, res_size, DRV_NAME)) {
dev_err(&ofdev->dev, "couldn't request %pR\n", &res);
return -EBUSY;
}
base = ioremap_nocache(res.start, res_size);
if (!base) {
dev_err(&ofdev->dev, "couldn't ioremap %pR\n", &res);
err = -ENOMEM;
goto exit_release_mem;
}
irq = irq_of_parse_and_map(np, 0);
if (irq == NO_IRQ) {
dev_err(&ofdev->dev, "no irq found\n");
err = -ENODEV;
goto exit_unmap_mem;
}
dev = alloc_sja1000dev(0);
if (!dev) {
err = -ENOMEM;
goto exit_dispose_irq;
}
priv = netdev_priv(dev);
priv->read_reg = sja1000_ofp_read_reg;
priv->write_reg = sja1000_ofp_write_reg;
prop = of_get_property(np, "nxp,external-clock-frequency", &prop_size);
if (prop && (prop_size == sizeof(u32)))
priv->can.clock.freq = *prop / 2;
else
priv->can.clock.freq = SJA1000_OFP_CAN_CLOCK;
prop = of_get_property(np, "nxp,tx-output-mode", &prop_size);
if (prop && (prop_size == sizeof(u32)))
priv->ocr |= *prop & OCR_MODE_MASK;
else
priv->ocr |= OCR_MODE_NORMAL;
prop = of_get_property(np, "nxp,tx-output-config", &prop_size);
if (prop && (prop_size == sizeof(u32)))
priv->ocr |= (*prop << OCR_TX_SHIFT) & OCR_TX_MASK;
else
priv->ocr |= OCR_TX0_PULLDOWN;
prop = of_get_property(np, "nxp,clock-out-frequency", &prop_size);
if (prop && (prop_size == sizeof(u32)) && *prop) {
u32 divider = priv->can.clock.freq * 2 / *prop;
if (divider > 1)
priv->cdr |= divider / 2 - 1;
else
priv->cdr |= CDR_CLKOUT_MASK;
} else {
priv->cdr |= CDR_CLK_OFF;
}
prop = of_get_property(np, "nxp,no-comparator-bypass", NULL);
if (!prop)
priv->cdr |= CDR_CBP;
priv->irq_flags = IRQF_SHARED;
priv->reg_base = base;
dev->irq = irq;
dev_info(&ofdev->dev,
"reg_base=0x%p irq=%d clock=%d ocr=0x%02x cdr=0x%02x\n",
priv->reg_base, dev->irq, priv->can.clock.freq,
priv->ocr, priv->cdr);
dev_set_drvdata(&ofdev->dev, dev);
SET_NETDEV_DEV(dev, &ofdev->dev);
err = register_sja1000dev(dev);
if (err) {
dev_err(&ofdev->dev, "registering %s failed (err=%d)\n",
DRV_NAME, err);
goto exit_free_sja1000;
}
return 0;
exit_free_sja1000:
free_sja1000dev(dev);
exit_dispose_irq:
irq_dispose_mapping(irq);
exit_unmap_mem:
iounmap(base);
exit_release_mem:
release_mem_region(res.start, res_size);
return err;
}
static int __init sja1000_ofp_init(void)
{
return platform_driver_register(&sja1000_ofp_driver);
}
static void __exit sja1000_ofp_exit(void)
{
return platform_driver_unregister(&sja1000_ofp_driver);
}
