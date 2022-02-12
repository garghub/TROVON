static u8 ems_pci_v1_readb(struct ems_pci_card *card, unsigned int port)
{
return readb(card->base_addr + (port * 4));
}
static u8 ems_pci_v1_read_reg(const struct sja1000_priv *priv, int port)
{
return readb(priv->reg_base + (port * 4));
}
static void ems_pci_v1_write_reg(const struct sja1000_priv *priv,
int port, u8 val)
{
writeb(val, priv->reg_base + (port * 4));
}
static void ems_pci_v1_post_irq(const struct sja1000_priv *priv)
{
struct ems_pci_card *card = (struct ems_pci_card *)priv->priv;
writel(PITA2_ICR_INT0_EN | PITA2_ICR_INT0,
card->conf_addr + PITA2_ICR);
}
static u8 ems_pci_v2_read_reg(const struct sja1000_priv *priv, int port)
{
return readb(priv->reg_base + port);
}
static void ems_pci_v2_write_reg(const struct sja1000_priv *priv,
int port, u8 val)
{
writeb(val, priv->reg_base + port);
}
static void ems_pci_v2_post_irq(const struct sja1000_priv *priv)
{
struct ems_pci_card *card = (struct ems_pci_card *)priv->priv;
writel(PLX_ICSR_ENA_CLR, card->conf_addr + PLX_ICSR);
}
static inline int ems_pci_check_chan(const struct sja1000_priv *priv)
{
unsigned char res;
priv->write_reg(priv, REG_MOD, 1);
priv->write_reg(priv, REG_CDR, CDR_PELICAN);
res = priv->read_reg(priv, REG_CDR);
if (res == CDR_PELICAN)
return 1;
return 0;
}
static void ems_pci_del_card(struct pci_dev *pdev)
{
struct ems_pci_card *card = pci_get_drvdata(pdev);
struct net_device *dev;
int i = 0;
for (i = 0; i < card->channels; i++) {
dev = card->net_dev[i];
if (!dev)
continue;
dev_info(&pdev->dev, "Removing %s.\n", dev->name);
unregister_sja1000dev(dev);
free_sja1000dev(dev);
}
if (card->base_addr != NULL)
pci_iounmap(card->pci_dev, card->base_addr);
if (card->conf_addr != NULL)
pci_iounmap(card->pci_dev, card->conf_addr);
kfree(card);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static void ems_pci_card_reset(struct ems_pci_card *card)
{
writeb(0, card->base_addr);
}
static int ems_pci_add_card(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct sja1000_priv *priv;
struct net_device *dev;
struct ems_pci_card *card;
int max_chan, conf_size, base_bar;
int err, i;
if (pci_enable_device(pdev) < 0) {
dev_err(&pdev->dev, "Enabling PCI device failed\n");
return -ENODEV;
}
card = kzalloc(sizeof(struct ems_pci_card), GFP_KERNEL);
if (card == NULL) {
pci_disable_device(pdev);
return -ENOMEM;
}
pci_set_drvdata(pdev, card);
card->pci_dev = pdev;
card->channels = 0;
if (pdev->vendor == PCI_VENDOR_ID_PLX) {
card->version = 2;
max_chan = EMS_PCI_V2_MAX_CHAN;
base_bar = EMS_PCI_V2_BASE_BAR;
conf_size = EMS_PCI_V2_CONF_SIZE;
} else {
card->version = 1;
max_chan = EMS_PCI_V1_MAX_CHAN;
base_bar = EMS_PCI_V1_BASE_BAR;
conf_size = EMS_PCI_V1_CONF_SIZE;
}
card->conf_addr = pci_iomap(pdev, 0, conf_size);
if (card->conf_addr == NULL) {
err = -ENOMEM;
goto failure_cleanup;
}
card->base_addr = pci_iomap(pdev, base_bar, EMS_PCI_BASE_SIZE);
if (card->base_addr == NULL) {
err = -ENOMEM;
goto failure_cleanup;
}
if (card->version == 1) {
writel(PITA2_MISC_CONFIG, card->conf_addr + PITA2_MISC);
if (ems_pci_v1_readb(card, 0) != 0x55 ||
ems_pci_v1_readb(card, 1) != 0xAA ||
ems_pci_v1_readb(card, 2) != 0x01 ||
ems_pci_v1_readb(card, 3) != 0xCB ||
ems_pci_v1_readb(card, 4) != 0x11) {
dev_err(&pdev->dev,
"Not EMS Dr. Thomas Wuensche interface\n");
err = -ENODEV;
goto failure_cleanup;
}
}
ems_pci_card_reset(card);
for (i = 0; i < max_chan; i++) {
dev = alloc_sja1000dev(0);
if (dev == NULL) {
err = -ENOMEM;
goto failure_cleanup;
}
card->net_dev[i] = dev;
priv = netdev_priv(dev);
priv->priv = card;
priv->irq_flags = IRQF_SHARED;
dev->irq = pdev->irq;
priv->reg_base = card->base_addr + EMS_PCI_CAN_BASE_OFFSET
+ (i * EMS_PCI_CAN_CTRL_SIZE);
if (card->version == 1) {
priv->read_reg = ems_pci_v1_read_reg;
priv->write_reg = ems_pci_v1_write_reg;
priv->post_irq = ems_pci_v1_post_irq;
} else {
priv->read_reg = ems_pci_v2_read_reg;
priv->write_reg = ems_pci_v2_write_reg;
priv->post_irq = ems_pci_v2_post_irq;
}
if (ems_pci_check_chan(priv)) {
priv->can.clock.freq = EMS_PCI_CAN_CLOCK;
priv->ocr = EMS_PCI_OCR;
priv->cdr = EMS_PCI_CDR;
SET_NETDEV_DEV(dev, &pdev->dev);
if (card->version == 1)
writel(PITA2_ICR_INT0_EN | PITA2_ICR_INT0,
card->conf_addr + PITA2_ICR);
else
writel(PLX_ICSR_ENA_CLR,
card->conf_addr + PLX_ICSR);
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "Registering device failed "
"(err=%d)\n", err);
free_sja1000dev(dev);
goto failure_cleanup;
}
card->channels++;
dev_info(&pdev->dev, "Channel #%d at 0x%p, irq %d\n",
i + 1, priv->reg_base, dev->irq);
} else {
free_sja1000dev(dev);
}
}
return 0;
failure_cleanup:
dev_err(&pdev->dev, "Error: %d. Cleaning Up.\n", err);
ems_pci_del_card(pdev);
return err;
}
