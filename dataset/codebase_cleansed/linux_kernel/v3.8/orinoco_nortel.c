static int orinoco_nortel_cor_reset(struct orinoco_private *priv)
{
struct orinoco_pci_card *card = priv->card;
iowrite16(8, card->bridge_io + 2);
ioread16(card->attr_io + COR_OFFSET);
iowrite16(0x80, card->attr_io + COR_OFFSET);
mdelay(1);
iowrite16(0, card->attr_io + COR_OFFSET);
iowrite16(0, card->attr_io + COR_OFFSET);
mdelay(1);
iowrite16(COR_VALUE, card->attr_io + COR_OFFSET);
iowrite16(COR_VALUE, card->attr_io + COR_OFFSET);
mdelay(1);
iowrite16(0x228, card->bridge_io + 2);
return 0;
}
static int orinoco_nortel_hw_init(struct orinoco_pci_card *card)
{
int i;
u32 reg;
if (ioread16(card->bridge_io) & 1) {
printk(KERN_ERR PFX "brg1 answer1 wrong\n");
return -EBUSY;
}
iowrite16(0x118, card->bridge_io + 2);
iowrite16(0x108, card->bridge_io + 2);
mdelay(30);
iowrite16(0x8, card->bridge_io + 2);
for (i = 0; i < 30; i++) {
mdelay(30);
if (ioread16(card->bridge_io) & 0x10)
break;
}
if (i == 30) {
printk(KERN_ERR PFX "brg1 timed out\n");
return -EBUSY;
}
if (ioread16(card->attr_io + COR_OFFSET) & 1) {
printk(KERN_ERR PFX "brg2 answer1 wrong\n");
return -EBUSY;
}
if (ioread16(card->attr_io + COR_OFFSET + 2) & 1) {
printk(KERN_ERR PFX "brg2 answer2 wrong\n");
return -EBUSY;
}
if (ioread16(card->attr_io + COR_OFFSET + 4) & 1) {
printk(KERN_ERR PFX "brg2 answer3 wrong\n");
return -EBUSY;
}
iowrite16(COR_VALUE, card->attr_io + COR_OFFSET);
mdelay(1);
reg = ioread16(card->attr_io + COR_OFFSET);
if (reg != COR_VALUE) {
printk(KERN_ERR PFX "Error setting COR value (reg=%x)\n",
reg);
return -EBUSY;
}
iowrite16(1, card->bridge_io + 10);
return 0;
}
static int orinoco_nortel_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err;
struct orinoco_private *priv;
struct orinoco_pci_card *card;
void __iomem *hermes_io, *bridge_io, *attr_io;
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
bridge_io = pci_iomap(pdev, 0, 0);
if (!bridge_io) {
printk(KERN_ERR PFX "Cannot map bridge registers\n");
err = -EIO;
goto fail_map_bridge;
}
attr_io = pci_iomap(pdev, 1, 0);
if (!attr_io) {
printk(KERN_ERR PFX "Cannot map PCMCIA attributes\n");
err = -EIO;
goto fail_map_attr;
}
hermes_io = pci_iomap(pdev, 2, 0);
if (!hermes_io) {
printk(KERN_ERR PFX "Cannot map chipset registers\n");
err = -EIO;
goto fail_map_hermes;
}
priv = alloc_orinocodev(sizeof(*card), &pdev->dev,
orinoco_nortel_cor_reset, NULL);
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
err = orinoco_nortel_hw_init(card);
if (err) {
printk(KERN_ERR PFX "Hardware initialization failed\n");
goto fail;
}
err = orinoco_nortel_cor_reset(priv);
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
goto fail;
}
pci_set_drvdata(pdev, priv);
return 0;
fail:
free_irq(pdev->irq, priv);
fail_irq:
pci_set_drvdata(pdev, NULL);
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
static void orinoco_nortel_remove_one(struct pci_dev *pdev)
{
struct orinoco_private *priv = pci_get_drvdata(pdev);
struct orinoco_pci_card *card = priv->card;
iowrite16(0, card->bridge_io + 10);
orinoco_if_del(priv);
free_irq(pdev->irq, priv);
pci_set_drvdata(pdev, NULL);
free_orinocodev(priv);
pci_iounmap(pdev, priv->hw.iobase);
pci_iounmap(pdev, card->attr_io);
pci_iounmap(pdev, card->bridge_io);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init orinoco_nortel_init(void)
{
printk(KERN_DEBUG "%s\n", version);
return pci_register_driver(&orinoco_nortel_driver);
}
static void __exit orinoco_nortel_exit(void)
{
pci_unregister_driver(&orinoco_nortel_driver);
}
