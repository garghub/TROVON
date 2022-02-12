static void pc300_set_iface(port_t *port)
{
card_t *card = port->card;
u32 __iomem * init_ctrl = &card->plxbase->init_ctrl;
u16 msci = get_msci(port);
u8 rxs = port->rxs & CLK_BRG_MASK;
u8 txs = port->txs & CLK_BRG_MASK;
sca_out(EXS_TES1, (port->chan ? MSCI1_OFFSET : MSCI0_OFFSET) + EXS,
port->card);
switch(port->settings.clock_type) {
case CLOCK_INT:
rxs |= CLK_BRG;
txs |= CLK_PIN_OUT | CLK_TX_RXCLK;
break;
case CLOCK_TXINT:
rxs |= CLK_LINE;
txs |= CLK_PIN_OUT | CLK_BRG;
break;
case CLOCK_TXFROMRX:
rxs |= CLK_LINE;
txs |= CLK_PIN_OUT | CLK_TX_RXCLK;
break;
default:
rxs |= CLK_LINE;
txs |= CLK_PIN_OUT | CLK_LINE;
break;
}
port->rxs = rxs;
port->txs = txs;
sca_out(rxs, msci + RXS, card);
sca_out(txs, msci + TXS, card);
sca_set_port(port);
if (port->card->type == PC300_RSV) {
if (port->iface == IF_IFACE_V35)
writel(card->init_ctrl_value |
PC300_CHMEDIA_MASK(port->chan), init_ctrl);
else
writel(card->init_ctrl_value &
~PC300_CHMEDIA_MASK(port->chan), init_ctrl);
}
}
static int pc300_open(struct net_device *dev)
{
port_t *port = dev_to_port(dev);
int result = hdlc_open(dev);
if (result)
return result;
sca_open(dev);
pc300_set_iface(port);
return 0;
}
static int pc300_close(struct net_device *dev)
{
sca_close(dev);
hdlc_close(dev);
return 0;
}
static int pc300_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
const size_t size = sizeof(sync_serial_settings);
sync_serial_settings new_line;
sync_serial_settings __user *line = ifr->ifr_settings.ifs_ifsu.sync;
int new_type;
port_t *port = dev_to_port(dev);
#ifdef DEBUG_RINGS
if (cmd == SIOCDEVPRIVATE) {
sca_dump_rings(dev);
return 0;
}
#endif
if (cmd != SIOCWANDEV)
return hdlc_ioctl(dev, ifr, cmd);
if (ifr->ifr_settings.type == IF_GET_IFACE) {
ifr->ifr_settings.type = port->iface;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
if (copy_to_user(line, &port->settings, size))
return -EFAULT;
return 0;
}
if (port->card->type == PC300_X21 &&
(ifr->ifr_settings.type == IF_IFACE_SYNC_SERIAL ||
ifr->ifr_settings.type == IF_IFACE_X21))
new_type = IF_IFACE_X21;
else if (port->card->type == PC300_RSV &&
(ifr->ifr_settings.type == IF_IFACE_SYNC_SERIAL ||
ifr->ifr_settings.type == IF_IFACE_V35))
new_type = IF_IFACE_V35;
else if (port->card->type == PC300_RSV &&
ifr->ifr_settings.type == IF_IFACE_V24)
new_type = IF_IFACE_V24;
else
return hdlc_ioctl(dev, ifr, cmd);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user(&new_line, line, size))
return -EFAULT;
if (new_line.clock_type != CLOCK_EXT &&
new_line.clock_type != CLOCK_TXFROMRX &&
new_line.clock_type != CLOCK_INT &&
new_line.clock_type != CLOCK_TXINT)
return -EINVAL;
if (new_line.loopback != 0 && new_line.loopback != 1)
return -EINVAL;
memcpy(&port->settings, &new_line, size);
port->iface = new_type;
pc300_set_iface(port);
return 0;
}
static void pc300_pci_remove_one(struct pci_dev *pdev)
{
int i;
card_t *card = pci_get_drvdata(pdev);
for (i = 0; i < 2; i++)
if (card->ports[i].card)
unregister_hdlc_device(card->ports[i].netdev);
if (card->irq)
free_irq(card->irq, card);
if (card->rambase)
iounmap(card->rambase);
if (card->scabase)
iounmap(card->scabase);
if (card->plxbase)
iounmap(card->plxbase);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
if (card->ports[0].netdev)
free_netdev(card->ports[0].netdev);
if (card->ports[1].netdev)
free_netdev(card->ports[1].netdev);
kfree(card);
}
static int __devinit pc300_pci_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
card_t *card;
u32 __iomem *p;
int i;
u32 ramsize;
u32 ramphys;
u32 scaphys;
u32 plxphys;
i = pci_enable_device(pdev);
if (i)
return i;
i = pci_request_regions(pdev, "PC300");
if (i) {
pci_disable_device(pdev);
return i;
}
card = kzalloc(sizeof(card_t), GFP_KERNEL);
if (card == NULL) {
pci_release_regions(pdev);
pci_disable_device(pdev);
return -ENOBUFS;
}
pci_set_drvdata(pdev, card);
if (pci_resource_len(pdev, 0) != PC300_PLX_SIZE ||
pci_resource_len(pdev, 2) != PC300_SCA_SIZE ||
pci_resource_len(pdev, 3) < 16384) {
pr_err("invalid card EEPROM parameters\n");
pc300_pci_remove_one(pdev);
return -EFAULT;
}
plxphys = pci_resource_start(pdev, 0) & PCI_BASE_ADDRESS_MEM_MASK;
card->plxbase = ioremap(plxphys, PC300_PLX_SIZE);
scaphys = pci_resource_start(pdev, 2) & PCI_BASE_ADDRESS_MEM_MASK;
card->scabase = ioremap(scaphys, PC300_SCA_SIZE);
ramphys = pci_resource_start(pdev, 3) & PCI_BASE_ADDRESS_MEM_MASK;
card->rambase = pci_ioremap_bar(pdev, 3);
if (card->plxbase == NULL ||
card->scabase == NULL ||
card->rambase == NULL) {
pr_err("ioremap() failed\n");
pc300_pci_remove_one(pdev);
}
pci_write_config_dword(pdev, PCI_BASE_ADDRESS_0, scaphys);
card->init_ctrl_value = readl(&((plx9050 __iomem *)card->scabase)->init_ctrl);
pci_write_config_dword(pdev, PCI_BASE_ADDRESS_0, plxphys);
if (pdev->device == PCI_DEVICE_ID_PC300_TE_1 ||
pdev->device == PCI_DEVICE_ID_PC300_TE_2)
card->type = PC300_TE;
else if (card->init_ctrl_value & PC300_CTYPE_MASK)
card->type = PC300_X21;
else
card->type = PC300_RSV;
if (pdev->device == PCI_DEVICE_ID_PC300_RX_1 ||
pdev->device == PCI_DEVICE_ID_PC300_TE_1)
card->n_ports = 1;
else
card->n_ports = 2;
for (i = 0; i < card->n_ports; i++)
if (!(card->ports[i].netdev = alloc_hdlcdev(&card->ports[i]))) {
pr_err("unable to allocate memory\n");
pc300_pci_remove_one(pdev);
return -ENOMEM;
}
p = &card->plxbase->init_ctrl;
writel(card->init_ctrl_value | 0x40000000, p);
readl(p);
udelay(1);
writel(card->init_ctrl_value, p);
readl(p);
udelay(1);
writel(card->init_ctrl_value | 0x20000000, p);
readl(p);
udelay(1);
writel(card->init_ctrl_value, p);
readl(p);
udelay(1);
ramsize = sca_detect_ram(card, card->rambase,
pci_resource_len(pdev, 3));
if (use_crystal_clock)
card->init_ctrl_value &= ~PC300_CLKSEL_MASK;
else
card->init_ctrl_value |= PC300_CLKSEL_MASK;
writel(card->init_ctrl_value, &card->plxbase->init_ctrl);
i = ramsize / (card->n_ports * (sizeof(pkt_desc) + HDLC_MAX_MRU));
card->tx_ring_buffers = min(i / 2, MAX_TX_BUFFERS);
card->rx_ring_buffers = i - card->tx_ring_buffers;
card->buff_offset = card->n_ports * sizeof(pkt_desc) *
(card->tx_ring_buffers + card->rx_ring_buffers);
pr_info("PC300/%s, %u KB RAM at 0x%x, IRQ%u, using %u TX + %u RX packets rings\n",
card->type == PC300_X21 ? "X21" :
card->type == PC300_TE ? "TE" : "RSV",
ramsize / 1024, ramphys, pdev->irq,
card->tx_ring_buffers, card->rx_ring_buffers);
if (card->tx_ring_buffers < 1) {
pr_err("RAM test failed\n");
pc300_pci_remove_one(pdev);
return -EFAULT;
}
writew(0x0041, &card->plxbase->intr_ctrl_stat);
if (request_irq(pdev->irq, sca_intr, IRQF_SHARED, "pc300", card)) {
pr_warn("could not allocate IRQ%d\n", pdev->irq);
pc300_pci_remove_one(pdev);
return -EBUSY;
}
card->irq = pdev->irq;
sca_init(card, 0);
sca_out(0x10, BTCR, card);
for (i = 0; i < card->n_ports; i++) {
port_t *port = &card->ports[i];
struct net_device *dev = port->netdev;
hdlc_device *hdlc = dev_to_hdlc(dev);
port->chan = i;
spin_lock_init(&port->lock);
dev->irq = card->irq;
dev->mem_start = ramphys;
dev->mem_end = ramphys + ramsize - 1;
dev->tx_queue_len = 50;
dev->netdev_ops = &pc300_ops;
hdlc->attach = sca_attach;
hdlc->xmit = sca_xmit;
port->settings.clock_type = CLOCK_EXT;
port->card = card;
if (card->type == PC300_X21)
port->iface = IF_IFACE_X21;
else
port->iface = IF_IFACE_V35;
sca_init_port(port);
if (register_hdlc_device(dev)) {
pr_err("unable to register hdlc device\n");
port->card = NULL;
pc300_pci_remove_one(pdev);
return -ENOBUFS;
}
netdev_info(dev, "PC300 channel %d\n", port->chan);
}
return 0;
}
static int __init pc300_init_module(void)
{
if (pci_clock_freq < 1000000 || pci_clock_freq > 80000000) {
pr_err("Invalid PCI clock frequency\n");
return -EINVAL;
}
if (use_crystal_clock != 0 && use_crystal_clock != 1) {
pr_err("Invalid 'use_crystal_clock' value\n");
return -EINVAL;
}
CLOCK_BASE = use_crystal_clock ? 24576000 : pci_clock_freq;
return pci_register_driver(&pc300_pci_driver);
}
static void __exit pc300_cleanup_module(void)
{
pci_unregister_driver(&pc300_pci_driver);
}
