static int orinoco_pci_cor_reset(struct orinoco_private *priv)
{
struct hermes *hw = &priv->hw;
unsigned long timeout;
u16 reg;
hermes_write_regn(hw, PCI_COR, HERMES_PCI_COR_MASK);
mdelay(HERMES_PCI_COR_ONT);
hermes_write_regn(hw, PCI_COR, 0x0000);
mdelay(HERMES_PCI_COR_OFFT);
timeout = jiffies + (HERMES_PCI_COR_BUSYT * HZ / 1000);
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
static int orinoco_pci_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err;
struct orinoco_private *priv;
struct orinoco_pci_card *card;
void __iomem *hermes_io;
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
hermes_io = pci_iomap(pdev, 0, 0);
if (!hermes_io) {
printk(KERN_ERR PFX "Cannot remap chipset registers\n");
err = -EIO;
goto fail_map_hermes;
}
priv = alloc_orinocodev(sizeof(*card), &pdev->dev,
orinoco_pci_cor_reset, NULL);
if (!priv) {
printk(KERN_ERR PFX "Cannot allocate network device\n");
err = -ENOMEM;
goto fail_alloc;
}
card = priv->card;
hermes_struct_init(&priv->hw, hermes_io, HERMES_32BIT_REGSPACING);
err = request_irq(pdev->irq, orinoco_interrupt, IRQF_SHARED,
DRIVER_NAME, priv);
if (err) {
printk(KERN_ERR PFX "Cannot allocate IRQ %d\n", pdev->irq);
err = -EBUSY;
goto fail_irq;
}
err = orinoco_pci_cor_reset(priv);
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
free_orinocodev(priv);
fail_alloc:
pci_iounmap(pdev, hermes_io);
fail_map_hermes:
pci_release_regions(pdev);
fail_resources:
pci_disable_device(pdev);
return err;
}
static void orinoco_pci_remove_one(struct pci_dev *pdev)
{
struct orinoco_private *priv = pci_get_drvdata(pdev);
orinoco_if_del(priv);
free_irq(pdev->irq, priv);
free_orinocodev(priv);
pci_iounmap(pdev, priv->hw.iobase);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init orinoco_pci_init(void)
{
printk(KERN_DEBUG "%s\n", version);
return pci_register_driver(&orinoco_pci_driver);
}
static void __exit orinoco_pci_exit(void)
{
pci_unregister_driver(&orinoco_pci_driver);
}
