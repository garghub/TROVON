static int netmos_parallel_init(struct pci_dev *dev, struct parport_pc_pci *par,
int autoirq, int autodma)
{
if (dev->device == PCI_DEVICE_ID_NETMOS_9835 &&
dev->subsystem_vendor == PCI_VENDOR_ID_IBM &&
dev->subsystem_device == 0x0299)
return -ENODEV;
if (dev->device == PCI_DEVICE_ID_NETMOS_9912) {
par->numports = 1;
} else {
par->numports = (dev->subsystem_device & 0xf0) >> 4;
if (par->numports > ARRAY_SIZE(par->addr))
par->numports = ARRAY_SIZE(par->addr);
}
return 0;
}
static int serial_register(struct pci_dev *dev, const struct pci_device_id *id)
{
struct parport_serial_private *priv = pci_get_drvdata (dev);
struct pciserial_board *board;
struct serial_private *serial;
board = &pci_parport_serial_boards[id->driver_data];
if (board->num_ports == 0)
return 0;
serial = pciserial_init_ports(dev, board);
if (IS_ERR(serial))
return PTR_ERR(serial);
priv->serial = serial;
return 0;
}
static int parport_register(struct pci_dev *dev, const struct pci_device_id *id)
{
struct parport_pc_pci *card;
struct parport_serial_private *priv = pci_get_drvdata (dev);
int n, success = 0;
priv->par = cards[id->driver_data];
card = &priv->par;
if (card->preinit_hook &&
card->preinit_hook (dev, card, PARPORT_IRQ_NONE, PARPORT_DMA_NONE))
return -ENODEV;
for (n = 0; n < card->numports; n++) {
struct parport *port;
int lo = card->addr[n].lo;
int hi = card->addr[n].hi;
unsigned long io_lo, io_hi;
int irq;
if (priv->num_par == ARRAY_SIZE (priv->port)) {
printk (KERN_WARNING
"parport_serial: %s: only %zu parallel ports "
"supported (%d reported)\n", pci_name (dev),
ARRAY_SIZE(priv->port), card->numports);
break;
}
io_lo = pci_resource_start (dev, lo);
io_hi = 0;
if ((hi >= 0) && (hi <= 6))
io_hi = pci_resource_start (dev, hi);
else if (hi > 6)
io_lo += hi;
irq = dev->irq;
if (irq == IRQ_NONE) {
dev_dbg(&dev->dev,
"PCI parallel port detected: I/O at %#lx(%#lx)\n",
io_lo, io_hi);
irq = PARPORT_IRQ_NONE;
} else {
dev_dbg(&dev->dev,
"PCI parallel port detected: I/O at %#lx(%#lx), IRQ %d\n",
io_lo, io_hi, irq);
}
port = parport_pc_probe_port (io_lo, io_hi, irq,
PARPORT_DMA_NONE, &dev->dev, IRQF_SHARED);
if (port) {
priv->port[priv->num_par++] = port;
success = 1;
}
}
if (card->postinit_hook)
card->postinit_hook (dev, card, !success);
return 0;
}
static int parport_serial_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct parport_serial_private *priv;
int err;
priv = kzalloc (sizeof *priv, GFP_KERNEL);
if (!priv)
return -ENOMEM;
pci_set_drvdata (dev, priv);
err = pci_enable_device (dev);
if (err) {
kfree (priv);
return err;
}
if (parport_register (dev, id)) {
kfree (priv);
return -ENODEV;
}
if (serial_register (dev, id)) {
int i;
for (i = 0; i < priv->num_par; i++)
parport_pc_unregister_port (priv->port[i]);
kfree (priv);
return -ENODEV;
}
return 0;
}
static void parport_serial_pci_remove(struct pci_dev *dev)
{
struct parport_serial_private *priv = pci_get_drvdata (dev);
int i;
if (priv->serial)
pciserial_remove_ports(priv->serial);
for (i = 0; i < priv->num_par; i++)
parport_pc_unregister_port (priv->port[i]);
kfree (priv);
return;
}
static int parport_serial_pci_suspend(struct pci_dev *dev, pm_message_t state)
{
struct parport_serial_private *priv = pci_get_drvdata(dev);
if (priv->serial)
pciserial_suspend_ports(priv->serial);
pci_save_state(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
return 0;
}
static int parport_serial_pci_resume(struct pci_dev *dev)
{
struct parport_serial_private *priv = pci_get_drvdata(dev);
int err;
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
err = pci_enable_device(dev);
if (err) {
printk(KERN_ERR "parport_serial: %s: error enabling "
"device for resume (%d)\n", pci_name(dev), err);
return err;
}
if (priv->serial)
pciserial_resume_ports(priv->serial);
return 0;
}
static int __init parport_serial_init (void)
{
return pci_register_driver (&parport_serial_pci_driver);
}
static void __exit parport_serial_exit (void)
{
pci_unregister_driver (&parport_serial_pci_driver);
return;
}
