static u8 tscan1_read(const struct sja1000_priv *priv, int reg)
{
return inb((unsigned long)priv->reg_base + reg);
}
static void tscan1_write(const struct sja1000_priv *priv, int reg, u8 val)
{
outb(val, (unsigned long)priv->reg_base + reg);
}
static int __devinit tscan1_probe(struct device *dev, unsigned id)
{
struct net_device *netdev;
struct sja1000_priv *priv;
unsigned long pld_base, sja1000_base;
int irq, i;
pld_base = TSCAN1_PLD_ADDRESS + id * TSCAN1_PLD_SIZE;
if (!request_region(pld_base, TSCAN1_PLD_SIZE, dev_name(dev)))
return -EBUSY;
if (inb(pld_base + TSCAN1_ID1) != TSCAN1_ID1_VALUE ||
inb(pld_base + TSCAN1_ID2) != TSCAN1_ID2_VALUE) {
release_region(pld_base, TSCAN1_PLD_SIZE);
return -ENODEV;
}
switch (inb(pld_base + TSCAN1_JUMPERS) & (TSCAN1_JP4 | TSCAN1_JP5)) {
case TSCAN1_JP4:
irq = 6;
break;
case TSCAN1_JP5:
irq = 7;
break;
case TSCAN1_JP4 | TSCAN1_JP5:
irq = 5;
break;
default:
dev_err(dev, "invalid JP4:JP5 setting (no IRQ)\n");
release_region(pld_base, TSCAN1_PLD_SIZE);
return -EINVAL;
}
netdev = alloc_sja1000dev(0);
if (!netdev) {
release_region(pld_base, TSCAN1_PLD_SIZE);
return -ENOMEM;
}
dev_set_drvdata(dev, netdev);
SET_NETDEV_DEV(netdev, dev);
netdev->base_addr = pld_base;
netdev->irq = irq;
priv = netdev_priv(netdev);
priv->read_reg = tscan1_read;
priv->write_reg = tscan1_write;
priv->can.clock.freq = TSCAN1_SJA1000_XTAL / 2;
priv->cdr = CDR_CBP | CDR_CLK_OFF;
priv->ocr = OCR_TX0_PUSHPULL;
for (i = 0; i < ARRAY_SIZE(tscan1_sja1000_addresses); i++) {
sja1000_base = tscan1_sja1000_addresses[i];
if (!request_region(sja1000_base, TSCAN1_SJA1000_SIZE,
dev_name(dev)))
continue;
outb(TSCAN1_MODE_ENABLE | i, pld_base + TSCAN1_MODE);
priv->reg_base = (void __iomem *)sja1000_base;
if (!register_sja1000dev(netdev)) {
outb(0, pld_base + TSCAN1_LED);
netdev_info(netdev, "TS-CAN1 at 0x%lx 0x%lx irq %d\n",
pld_base, sja1000_base, irq);
return 0;
}
outb(0, pld_base + TSCAN1_MODE);
release_region(sja1000_base, TSCAN1_SJA1000_SIZE);
}
dev_err(dev, "failed to assign SJA1000 IO address\n");
dev_set_drvdata(dev, NULL);
free_sja1000dev(netdev);
release_region(pld_base, TSCAN1_PLD_SIZE);
return -ENXIO;
}
static int __devexit tscan1_remove(struct device *dev, unsigned id )
{
struct net_device *netdev;
struct sja1000_priv *priv;
unsigned long pld_base, sja1000_base;
netdev = dev_get_drvdata(dev);
unregister_sja1000dev(netdev);
dev_set_drvdata(dev, NULL);
priv = netdev_priv(netdev);
pld_base = netdev->base_addr;
sja1000_base = (unsigned long)priv->reg_base;
outb(0, pld_base + TSCAN1_MODE);
release_region(sja1000_base, TSCAN1_SJA1000_SIZE);
release_region(pld_base, TSCAN1_PLD_SIZE);
free_sja1000dev(netdev);
return 0;
}
static int __init tscan1_init(void)
{
return isa_register_driver(&tscan1_isa_driver, TSCAN1_MAXDEV);
}
static void __exit tscan1_exit(void)
{
isa_unregister_driver(&tscan1_isa_driver);
}
