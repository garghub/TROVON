static u8 peak_pci_read_reg(const struct sja1000_priv *priv, int port)
{
return readb(priv->reg_base + (port << 2));
}
static void peak_pci_write_reg(const struct sja1000_priv *priv,
int port, u8 val)
{
writeb(val, priv->reg_base + (port << 2));
}
static void peak_pci_post_irq(const struct sja1000_priv *priv)
{
struct peak_pci_chan *chan = priv->priv;
u16 icr;
icr = readw(chan->cfg_base + PITA_ICR);
if (icr & chan->icr_mask)
writew(chan->icr_mask, chan->cfg_base + PITA_ICR);
}
static int __devinit peak_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct sja1000_priv *priv;
struct peak_pci_chan *chan;
struct net_device *dev;
void __iomem *cfg_base, *reg_base;
u16 sub_sys_id, icr;
int i, err, channels;
err = pci_enable_device(pdev);
if (err)
return err;
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto failure_disable_pci;
err = pci_read_config_word(pdev, 0x2e, &sub_sys_id);
if (err)
goto failure_release_regions;
dev_dbg(&pdev->dev, "probing device %04x:%04x:%04x\n",
pdev->vendor, pdev->device, sub_sys_id);
err = pci_write_config_word(pdev, 0x44, 0);
if (err)
goto failure_release_regions;
if (sub_sys_id >= 12)
channels = 4;
else if (sub_sys_id >= 10)
channels = 3;
else if (sub_sys_id >= 4)
channels = 2;
else
channels = 1;
cfg_base = pci_iomap(pdev, 0, PEAK_PCI_CFG_SIZE);
if (!cfg_base) {
dev_err(&pdev->dev, "failed to map PCI resource #0\n");
goto failure_release_regions;
}
reg_base = pci_iomap(pdev, 1, PEAK_PCI_CHAN_SIZE * channels);
if (!reg_base) {
dev_err(&pdev->dev, "failed to map PCI resource #1\n");
goto failure_unmap_cfg_base;
}
writew(0x0005, cfg_base + PITA_GPIOICR + 2);
writeb(0x00, cfg_base + PITA_GPIOICR);
writeb(0x05, cfg_base + PITA_MISC + 3);
mdelay(5);
writeb(0x04, cfg_base + PITA_MISC + 3);
icr = readw(cfg_base + PITA_ICR + 2);
for (i = 0; i < channels; i++) {
dev = alloc_sja1000dev(sizeof(struct peak_pci_chan));
if (!dev) {
err = -ENOMEM;
goto failure_remove_channels;
}
priv = netdev_priv(dev);
chan = priv->priv;
chan->cfg_base = cfg_base;
priv->reg_base = reg_base + i * PEAK_PCI_CHAN_SIZE;
priv->read_reg = peak_pci_read_reg;
priv->write_reg = peak_pci_write_reg;
priv->post_irq = peak_pci_post_irq;
priv->can.clock.freq = PEAK_PCI_CAN_CLOCK;
priv->ocr = PEAK_PCI_OCR;
priv->cdr = PEAK_PCI_CDR;
if (channels == 1 || i > 0)
priv->cdr |= CDR_CLK_OFF;
priv->irq_flags = IRQF_SHARED;
dev->irq = pdev->irq;
chan->icr_mask = peak_pci_icr_masks[i];
icr |= chan->icr_mask;
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "failed to register device\n");
free_sja1000dev(dev);
goto failure_remove_channels;
}
chan->prev_dev = pci_get_drvdata(pdev);
pci_set_drvdata(pdev, dev);
dev_info(&pdev->dev,
"%s at reg_base=0x%p cfg_base=0x%p irq=%d\n",
dev->name, priv->reg_base, chan->cfg_base, dev->irq);
}
writew(icr, cfg_base + PITA_ICR + 2);
return 0;
failure_remove_channels:
writew(0x0, cfg_base + PITA_ICR + 2);
for (dev = pci_get_drvdata(pdev); dev; dev = chan->prev_dev) {
unregister_sja1000dev(dev);
free_sja1000dev(dev);
priv = netdev_priv(dev);
chan = priv->priv;
}
pci_iounmap(pdev, reg_base);
failure_unmap_cfg_base:
pci_iounmap(pdev, cfg_base);
failure_release_regions:
pci_release_regions(pdev);
failure_disable_pci:
pci_disable_device(pdev);
return err;
}
static void __devexit peak_pci_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct sja1000_priv *priv = netdev_priv(dev);
struct peak_pci_chan *chan = priv->priv;
void __iomem *cfg_base = chan->cfg_base;
void __iomem *reg_base = priv->reg_base;
writew(0x0, cfg_base + PITA_ICR + 2);
while (1) {
dev_info(&pdev->dev, "removing device %s\n", dev->name);
unregister_sja1000dev(dev);
free_sja1000dev(dev);
dev = chan->prev_dev;
if (!dev)
break;
priv = netdev_priv(dev);
chan = priv->priv;
}
pci_iounmap(pdev, reg_base);
pci_iounmap(pdev, cfg_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __init peak_pci_init(void)
{
return pci_register_driver(&peak_pci_driver);
}
static void __exit peak_pci_exit(void)
{
pci_unregister_driver(&peak_pci_driver);
}
