static int orinoco_plx_cor_reset(struct orinoco_private *priv)
{
struct hermes *hw = &priv->hw;
struct orinoco_pci_card *card = priv->card;
unsigned long timeout;
u16 reg;
iowrite8(COR_VALUE | COR_RESET, card->attr_io + COR_OFFSET);
mdelay(1);
iowrite8(COR_VALUE, card->attr_io + COR_OFFSET);
mdelay(1);
timeout = jiffies + msecs_to_jiffies(PLX_RESET_TIME);
reg = hermes_read_regn(hw, CMD);
while (time_before(jiffies, timeout) && (reg & HERMES_CMD_BUSY)) {
mdelay(1);
reg = hermes_read_regn(hw, CMD);
}
if (reg & HERMES_CMD_BUSY) {
printk(KERN_ERR PFX "Busy timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int orinoco_plx_hw_init(struct orinoco_pci_card *card)
{
int i;
u32 csr_reg;
static const u8 cis_magic[] = {
0x01, 0x03, 0x00, 0x00, 0xff, 0x17, 0x04, 0x67
};
printk(KERN_DEBUG PFX "CIS: ");
for (i = 0; i < 16; i++)
printk("%02X:", ioread8(card->attr_io + (i << 1)));
printk("\n");
for (i = 0; i < sizeof(cis_magic); i++) {
if (cis_magic[i] != ioread8(card->attr_io + (i << 1))) {
printk(KERN_ERR PFX "The CIS value of Prism2 PC "
"card is unexpected\n");
return -ENODEV;
}
}
csr_reg = ioread32(card->bridge_io + PLX_INTCSR);
if (!(csr_reg & PLX_INTCSR_INTEN)) {
csr_reg |= PLX_INTCSR_INTEN;
iowrite32(csr_reg, card->bridge_io + PLX_INTCSR);
csr_reg = ioread32(card->bridge_io + PLX_INTCSR);
if (!(csr_reg & PLX_INTCSR_INTEN)) {
printk(KERN_ERR PFX "Cannot enable interrupts\n");
return -EIO;
}
}
return 0;
}
static int orinoco_plx_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err;
struct orinoco_private *priv;
struct orinoco_pci_card *card;
void __iomem *hermes_io, *attr_io, *bridge_io;
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR PFX "Cannot enable PCI device\n");
return err;
}
err = pci_request_regions(pdev, DRIVER_NAME);
if (err) {
printk(KERN_ERR PFX "Cannot obtain PCI resources\n");
goto fail_resources;
}
bridge_io = pci_iomap(pdev, 1, 0);
if (!bridge_io) {
printk(KERN_ERR PFX "Cannot map bridge registers\n");
err = -EIO;
goto fail_map_bridge;
}
attr_io = pci_iomap(pdev, 2, 0);
if (!attr_io) {
printk(KERN_ERR PFX "Cannot map PCMCIA attributes\n");
err = -EIO;
goto fail_map_attr;
}
hermes_io = pci_iomap(pdev, 3, 0);
if (!hermes_io) {
printk(KERN_ERR PFX "Cannot map chipset registers\n");
err = -EIO;
goto fail_map_hermes;
}
priv = alloc_orinocodev(sizeof(*card), &pdev->dev,
orinoco_plx_cor_reset, NULL);
if (!priv) {
printk(KERN_ERR PFX "Cannot allocate network device\n");
err = -ENOMEM;
goto fail_alloc;
}
card = priv->card;
card->bridge_io = bridge_io;
card->attr_io = attr_io;
hermes_struct_init(&priv->hw, hermes_io, HERMES_16BIT_REGSPACING);
err = request_irq(pdev->irq, orinoco_interrupt, IRQF_SHARED,
DRIVER_NAME, priv);
if (err) {
printk(KERN_ERR PFX "Cannot allocate IRQ %d\n", pdev->irq);
err = -EBUSY;
goto fail_irq;
}
err = orinoco_plx_hw_init(card);
if (err) {
printk(KERN_ERR PFX "Hardware initialization failed\n");
goto fail;
}
err = orinoco_plx_cor_reset(priv);
if (err) {
printk(KERN_ERR PFX "Initial reset failed\n");
goto fail;
}
err = orinoco_init(priv);
if (err) {
printk(KERN_ERR PFX "orinoco_init() failed\n");
goto fail;
}
err = orinoco_if_add(priv, 0, 0, NULL);
if (err) {
printk(KERN_ERR PFX "orinoco_if_add() failed\n");
goto fail_wiphy;
}
pci_set_drvdata(pdev, priv);
return 0;
fail_wiphy:
wiphy_unregister(priv_to_wiphy(priv));
fail:
free_irq(pdev->irq, priv);
fail_irq:
free_orinocodev(priv);
fail_alloc:
pci_iounmap(pdev, hermes_io);
fail_map_hermes:
pci_iounmap(pdev, attr_io);
fail_map_attr:
pci_iounmap(pdev, bridge_io);
fail_map_bridge:
pci_release_regions(pdev);
fail_resources:
pci_disable_device(pdev);
return err;
}
static void orinoco_plx_remove_one(struct pci_dev *pdev)
{
struct orinoco_private *priv = pci_get_drvdata(pdev);
struct orinoco_pci_card *card = priv->card;
orinoco_if_del(priv);
wiphy_unregister(priv_to_wiphy(priv));
free_irq(pdev->irq, priv);
free_orinocodev(priv);
pci_iounmap(pdev, priv->hw.iobase);
pci_iounmap(pdev, card->attr_io);
pci_iounmap(pdev, card->bridge_io);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init orinoco_plx_init(void)
{
printk(KERN_DEBUG "%s\n", version);
return pci_register_driver(&orinoco_plx_driver);
}
static void __exit orinoco_plx_exit(void)
{
pci_unregister_driver(&orinoco_plx_driver);
}
