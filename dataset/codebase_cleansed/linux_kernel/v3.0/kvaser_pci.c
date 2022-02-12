static u8 kvaser_pci_read_reg(const struct sja1000_priv *priv, int port)
{
return ioread8(priv->reg_base + port);
}
static void kvaser_pci_write_reg(const struct sja1000_priv *priv,
int port, u8 val)
{
iowrite8(val, priv->reg_base + port);
}
static void kvaser_pci_disable_irq(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct kvaser_pci *board = priv->priv;
u32 intcsr;
intcsr = ioread32(board->conf_addr + S5920_INTCSR);
intcsr &= ~INTCSR_ADDON_INTENABLE_M;
iowrite32(intcsr, board->conf_addr + S5920_INTCSR);
}
static void kvaser_pci_enable_irq(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct kvaser_pci *board = priv->priv;
u32 tmp_en_io;
tmp_en_io = ioread32(board->conf_addr + S5920_INTCSR);
tmp_en_io |= INTCSR_ADDON_INTENABLE_M;
iowrite32(tmp_en_io, board->conf_addr + S5920_INTCSR);
}
static int number_of_sja1000_chip(void __iomem *base_addr)
{
u8 status;
int i;
for (i = 0; i < MAX_NO_OF_CHANNELS; i++) {
iowrite8(MOD_RM, base_addr +
(i * KVASER_PCI_PORT_BYTES) + REG_MOD);
status = ioread8(base_addr +
(i * KVASER_PCI_PORT_BYTES) + REG_MOD);
if (!(status & MOD_RM))
break;
}
return i;
}
static void kvaser_pci_del_chan(struct net_device *dev)
{
struct sja1000_priv *priv;
struct kvaser_pci *board;
int i;
if (!dev)
return;
priv = netdev_priv(dev);
board = priv->priv;
if (!board)
return;
dev_info(&board->pci_dev->dev, "Removing device %s\n",
dev->name);
kvaser_pci_disable_irq(dev);
for (i = 0; i < board->no_channels - 1; i++) {
if (board->slave_dev[i]) {
dev_info(&board->pci_dev->dev, "Removing device %s\n",
board->slave_dev[i]->name);
unregister_sja1000dev(board->slave_dev[i]);
free_sja1000dev(board->slave_dev[i]);
}
}
unregister_sja1000dev(dev);
pci_iounmap(board->pci_dev, priv->reg_base);
pci_iounmap(board->pci_dev, board->conf_addr);
pci_iounmap(board->pci_dev, board->res_addr);
free_sja1000dev(dev);
}
static int kvaser_pci_add_chan(struct pci_dev *pdev, int channel,
struct net_device **master_dev,
void __iomem *conf_addr,
void __iomem *res_addr,
void __iomem *base_addr)
{
struct net_device *dev;
struct sja1000_priv *priv;
struct kvaser_pci *board;
int err, init_step;
dev = alloc_sja1000dev(sizeof(struct kvaser_pci));
if (dev == NULL)
return -ENOMEM;
priv = netdev_priv(dev);
board = priv->priv;
board->pci_dev = pdev;
board->channel = channel;
board->conf_addr = conf_addr;
board->res_addr = res_addr;
if (channel == 0) {
board->xilinx_ver =
ioread8(board->res_addr + XILINX_VERINT) >> 4;
init_step = 2;
iowrite32(0x80808080UL, board->conf_addr + S5920_PTCR);
kvaser_pci_enable_irq(dev);
} else {
struct sja1000_priv *master_priv = netdev_priv(*master_dev);
struct kvaser_pci *master_board = master_priv->priv;
master_board->slave_dev[channel - 1] = dev;
master_board->no_channels = channel + 1;
board->xilinx_ver = master_board->xilinx_ver;
}
priv->reg_base = base_addr + channel * KVASER_PCI_PORT_BYTES;
priv->read_reg = kvaser_pci_read_reg;
priv->write_reg = kvaser_pci_write_reg;
priv->can.clock.freq = KVASER_PCI_CAN_CLOCK;
priv->ocr = KVASER_PCI_OCR;
priv->cdr = KVASER_PCI_CDR;
priv->irq_flags = IRQF_SHARED;
dev->irq = pdev->irq;
init_step = 4;
dev_info(&pdev->dev, "reg_base=%p conf_addr=%p irq=%d\n",
priv->reg_base, board->conf_addr, dev->irq);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "Registering device failed (err=%d)\n",
err);
goto failure;
}
if (channel == 0)
*master_dev = dev;
return 0;
failure:
kvaser_pci_del_chan(dev);
return err;
}
static int __devinit kvaser_pci_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err;
struct net_device *master_dev = NULL;
struct sja1000_priv *priv;
struct kvaser_pci *board;
int no_channels;
void __iomem *base_addr = NULL;
void __iomem *conf_addr = NULL;
void __iomem *res_addr = NULL;
int i;
dev_info(&pdev->dev, "initializing device %04x:%04x\n",
pdev->vendor, pdev->device);
err = pci_enable_device(pdev);
if (err)
goto failure;
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto failure_release_pci;
conf_addr = pci_iomap(pdev, 0, PCI_CONFIG_PORT_SIZE);
if (conf_addr == NULL) {
err = -ENODEV;
goto failure_release_regions;
}
res_addr = pci_iomap(pdev, 2, PCI_PORT_XILINX_SIZE);
if (res_addr == NULL) {
err = -ENOMEM;
goto failure_iounmap;
}
base_addr = pci_iomap(pdev, 1, PCI_PORT_SIZE);
if (base_addr == NULL) {
err = -ENOMEM;
goto failure_iounmap;
}
no_channels = number_of_sja1000_chip(base_addr);
if (no_channels == 0) {
err = -ENOMEM;
goto failure_iounmap;
}
for (i = 0; i < no_channels; i++) {
err = kvaser_pci_add_chan(pdev, i, &master_dev,
conf_addr, res_addr,
base_addr);
if (err)
goto failure_cleanup;
}
priv = netdev_priv(master_dev);
board = priv->priv;
dev_info(&pdev->dev, "xilinx version=%d number of channels=%d\n",
board->xilinx_ver, board->no_channels);
pci_set_drvdata(pdev, master_dev);
return 0;
failure_cleanup:
kvaser_pci_del_chan(master_dev);
failure_iounmap:
if (conf_addr != NULL)
pci_iounmap(pdev, conf_addr);
if (res_addr != NULL)
pci_iounmap(pdev, res_addr);
if (base_addr != NULL)
pci_iounmap(pdev, base_addr);
failure_release_regions:
pci_release_regions(pdev);
failure_release_pci:
pci_disable_device(pdev);
failure:
return err;
}
static void __devexit kvaser_pci_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
kvaser_pci_del_chan(dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __init kvaser_pci_init(void)
{
return pci_register_driver(&kvaser_pci_driver);
}
static void __exit kvaser_pci_exit(void)
{
pci_unregister_driver(&kvaser_pci_driver);
}
