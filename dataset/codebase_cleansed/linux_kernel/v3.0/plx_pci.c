static u8 plx_pci_read_reg(const struct sja1000_priv *priv, int port)
{
return ioread8(priv->reg_base + port);
}
static void plx_pci_write_reg(const struct sja1000_priv *priv, int port, u8 val)
{
iowrite8(val, priv->reg_base + port);
}
static inline int plx_pci_check_sja1000(const struct sja1000_priv *priv)
{
int flag = 0;
if ((priv->read_reg(priv, REG_CR) & REG_CR_BASICCAN_INITIAL_MASK) ==
REG_CR_BASICCAN_INITIAL &&
(priv->read_reg(priv, REG_SR) == REG_SR_BASICCAN_INITIAL) &&
(priv->read_reg(priv, REG_IR) == REG_IR_BASICCAN_INITIAL))
flag = 1;
priv->write_reg(priv, REG_CDR, CDR_PELICAN);
if (priv->read_reg(priv, REG_MOD) == REG_MOD_PELICAN_INITIAL &&
priv->read_reg(priv, REG_SR) == REG_SR_PELICAN_INITIAL &&
priv->read_reg(priv, REG_IR) == REG_IR_PELICAN_INITIAL)
return flag;
return 0;
}
static void plx_pci_reset_common(struct pci_dev *pdev)
{
struct plx_pci_card *card = pci_get_drvdata(pdev);
u32 cntrl;
cntrl = ioread32(card->conf_addr + PLX_CNTRL);
cntrl |= PLX_PCI_RESET;
iowrite32(cntrl, card->conf_addr + PLX_CNTRL);
udelay(100);
cntrl ^= PLX_PCI_RESET;
iowrite32(cntrl, card->conf_addr + PLX_CNTRL);
}
static void plx9056_pci_reset_common(struct pci_dev *pdev)
{
struct plx_pci_card *card = pci_get_drvdata(pdev);
u32 cntrl;
cntrl = ioread32(card->conf_addr + PLX9056_CNTRL);
cntrl |= PLX_PCI_RESET;
iowrite32(cntrl, card->conf_addr + PLX9056_CNTRL);
udelay(100);
cntrl ^= PLX_PCI_RESET;
iowrite32(cntrl, card->conf_addr + PLX9056_CNTRL);
cntrl |= PLX9056_PCI_RCR;
iowrite32(cntrl, card->conf_addr + PLX9056_CNTRL);
mdelay(10);
cntrl ^= PLX9056_PCI_RCR;
iowrite32(cntrl, card->conf_addr + PLX9056_CNTRL);
}
static void plx_pci_reset_marathon(struct pci_dev *pdev)
{
void __iomem *reset_addr;
int i;
static const int reset_bar[2] = {3, 5};
plx_pci_reset_common(pdev);
for (i = 0; i < 2; i++) {
reset_addr = pci_iomap(pdev, reset_bar[i], 0);
if (!reset_addr) {
dev_err(&pdev->dev, "Failed to remap reset "
"space %d (BAR%d)\n", i, reset_bar[i]);
} else {
iowrite8(0x1, reset_addr);
udelay(100);
pci_iounmap(pdev, reset_addr);
}
}
}
static void plx_pci_del_card(struct pci_dev *pdev)
{
struct plx_pci_card *card = pci_get_drvdata(pdev);
struct net_device *dev;
struct sja1000_priv *priv;
int i = 0;
for (i = 0; i < card->channels; i++) {
dev = card->net_dev[i];
if (!dev)
continue;
dev_info(&pdev->dev, "Removing %s\n", dev->name);
unregister_sja1000dev(dev);
priv = netdev_priv(dev);
if (priv->reg_base)
pci_iounmap(pdev, priv->reg_base);
free_sja1000dev(dev);
}
card->reset_func(pdev);
if (pdev->device != PCI_DEVICE_ID_PLX_9056)
iowrite32(0x0, card->conf_addr + PLX_INTCSR);
else
iowrite32(0x0, card->conf_addr + PLX9056_INTCSR);
if (card->conf_addr)
pci_iounmap(pdev, card->conf_addr);
kfree(card);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __devinit plx_pci_add_card(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct sja1000_priv *priv;
struct net_device *dev;
struct plx_pci_card *card;
struct plx_pci_card_info *ci;
int err, i;
u32 val;
void __iomem *addr;
ci = (struct plx_pci_card_info *)ent->driver_data;
if (pci_enable_device(pdev) < 0) {
dev_err(&pdev->dev, "Failed to enable PCI device\n");
return -ENODEV;
}
dev_info(&pdev->dev, "Detected \"%s\" card at slot #%i\n",
ci->name, PCI_SLOT(pdev->devfn));
card = kzalloc(sizeof(*card), GFP_KERNEL);
if (!card) {
dev_err(&pdev->dev, "Unable to allocate memory\n");
pci_disable_device(pdev);
return -ENOMEM;
}
pci_set_drvdata(pdev, card);
card->channels = 0;
addr = pci_iomap(pdev, ci->conf_map.bar, ci->conf_map.size);
if (!addr) {
err = -ENOMEM;
dev_err(&pdev->dev, "Failed to remap configuration space "
"(BAR%d)\n", ci->conf_map.bar);
goto failure_cleanup;
}
card->conf_addr = addr + ci->conf_map.offset;
ci->reset_func(pdev);
card->reset_func = ci->reset_func;
for (i = 0; i < ci->channel_count; i++) {
struct plx_pci_channel_map *cm = &ci->chan_map_tbl[i];
dev = alloc_sja1000dev(0);
if (!dev) {
err = -ENOMEM;
goto failure_cleanup;
}
card->net_dev[i] = dev;
priv = netdev_priv(dev);
priv->priv = card;
priv->irq_flags = IRQF_SHARED;
dev->irq = pdev->irq;
addr = pci_iomap(pdev, cm->bar, cm->size);
if (!addr) {
err = -ENOMEM;
dev_err(&pdev->dev, "Failed to remap BAR%d\n", cm->bar);
goto failure_cleanup;
}
priv->reg_base = addr + cm->offset;
priv->read_reg = plx_pci_read_reg;
priv->write_reg = plx_pci_write_reg;
if (plx_pci_check_sja1000(priv)) {
priv->can.clock.freq = ci->can_clock;
priv->ocr = ci->ocr;
priv->cdr = ci->cdr;
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "Registering device failed "
"(err=%d)\n", err);
free_sja1000dev(dev);
goto failure_cleanup;
}
card->channels++;
dev_info(&pdev->dev, "Channel #%d at 0x%p, irq %d "
"registered as %s\n", i + 1, priv->reg_base,
dev->irq, dev->name);
} else {
dev_err(&pdev->dev, "Channel #%d not detected\n",
i + 1);
free_sja1000dev(dev);
}
}
if (!card->channels) {
err = -ENODEV;
goto failure_cleanup;
}
if (pdev->device != PCI_DEVICE_ID_PLX_9056) {
val = ioread32(card->conf_addr + PLX_INTCSR);
if (pdev->subsystem_vendor == PCI_VENDOR_ID_ESDGMBH)
val |= PLX_LINT1_EN | PLX_PCI_INT_EN;
else
val |= PLX_LINT1_EN | PLX_LINT2_EN | PLX_PCI_INT_EN;
iowrite32(val, card->conf_addr + PLX_INTCSR);
} else {
iowrite32(PLX9056_LINTI | PLX9056_PCI_INT_EN,
card->conf_addr + PLX9056_INTCSR);
}
return 0;
failure_cleanup:
dev_err(&pdev->dev, "Error: %d. Cleaning Up.\n", err);
plx_pci_del_card(pdev);
return err;
}
static int __init plx_pci_init(void)
{
return pci_register_driver(&plx_pci_driver);
}
static void __exit plx_pci_exit(void)
{
pci_unregister_driver(&plx_pci_driver);
}
