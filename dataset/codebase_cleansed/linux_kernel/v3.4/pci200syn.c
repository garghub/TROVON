static inline void new_memcpy_toio(char __iomem *dest, char *src, int length)
{
int len;
do {
len = length > 256 ? 256 : length;
memcpy_toio(dest, src, len);
dest += len;
src += len;
length -= len;
readb(dest);
} while (len);
}
static void pci200_set_iface(port_t *port)
{
card_t *card = port->card;
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
}
static int pci200_open(struct net_device *dev)
{
port_t *port = dev_to_port(dev);
int result = hdlc_open(dev);
if (result)
return result;
sca_open(dev);
pci200_set_iface(port);
sca_flush(port->card);
return 0;
}
static int pci200_close(struct net_device *dev)
{
sca_close(dev);
sca_flush(dev_to_port(dev)->card);
hdlc_close(dev);
return 0;
}
static int pci200_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
const size_t size = sizeof(sync_serial_settings);
sync_serial_settings new_line;
sync_serial_settings __user *line = ifr->ifr_settings.ifs_ifsu.sync;
port_t *port = dev_to_port(dev);
#ifdef DEBUG_RINGS
if (cmd == SIOCDEVPRIVATE) {
sca_dump_rings(dev);
return 0;
}
#endif
if (cmd != SIOCWANDEV)
return hdlc_ioctl(dev, ifr, cmd);
switch(ifr->ifr_settings.type) {
case IF_GET_IFACE:
ifr->ifr_settings.type = IF_IFACE_V35;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
if (copy_to_user(line, &port->settings, size))
return -EFAULT;
return 0;
case IF_IFACE_V35:
case IF_IFACE_SYNC_SERIAL:
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
pci200_set_iface(port);
sca_flush(port->card);
return 0;
default:
return hdlc_ioctl(dev, ifr, cmd);
}
}
static void pci200_pci_remove_one(struct pci_dev *pdev)
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
static int __devinit pci200_pci_init_one(struct pci_dev *pdev,
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
i = pci_request_regions(pdev, "PCI200SYN");
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
card->ports[0].netdev = alloc_hdlcdev(&card->ports[0]);
card->ports[1].netdev = alloc_hdlcdev(&card->ports[1]);
if (!card->ports[0].netdev || !card->ports[1].netdev) {
pr_err("unable to allocate memory\n");
pci200_pci_remove_one(pdev);
return -ENOMEM;
}
if (pci_resource_len(pdev, 0) != PCI200SYN_PLX_SIZE ||
pci_resource_len(pdev, 2) != PCI200SYN_SCA_SIZE ||
pci_resource_len(pdev, 3) < 16384) {
pr_err("invalid card EEPROM parameters\n");
pci200_pci_remove_one(pdev);
return -EFAULT;
}
plxphys = pci_resource_start(pdev,0) & PCI_BASE_ADDRESS_MEM_MASK;
card->plxbase = ioremap(plxphys, PCI200SYN_PLX_SIZE);
scaphys = pci_resource_start(pdev,2) & PCI_BASE_ADDRESS_MEM_MASK;
card->scabase = ioremap(scaphys, PCI200SYN_SCA_SIZE);
ramphys = pci_resource_start(pdev,3) & PCI_BASE_ADDRESS_MEM_MASK;
card->rambase = pci_ioremap_bar(pdev, 3);
if (card->plxbase == NULL ||
card->scabase == NULL ||
card->rambase == NULL) {
pr_err("ioremap() failed\n");
pci200_pci_remove_one(pdev);
return -EFAULT;
}
p = &card->plxbase->init_ctrl;
writel(readl(p) | 0x40000000, p);
readl(p);
udelay(1);
writel(readl(p) & ~0x40000000, p);
readl(p);
udelay(1);
ramsize = sca_detect_ram(card, card->rambase,
pci_resource_len(pdev, 3));
i = ramsize / (2 * (sizeof(pkt_desc) + HDLC_MAX_MRU));
card->tx_ring_buffers = min(i / 2, MAX_TX_BUFFERS);
card->rx_ring_buffers = i - card->tx_ring_buffers;
card->buff_offset = 2 * sizeof(pkt_desc) * (card->tx_ring_buffers +
card->rx_ring_buffers);
pr_info("%u KB RAM at 0x%x, IRQ%u, using %u TX + %u RX packets rings\n",
ramsize / 1024, ramphys,
pdev->irq, card->tx_ring_buffers, card->rx_ring_buffers);
if (card->tx_ring_buffers < 1) {
pr_err("RAM test failed\n");
pci200_pci_remove_one(pdev);
return -EFAULT;
}
p = &card->plxbase->intr_ctrl_stat;
writew(readw(p) | 0x0040, p);
if (request_irq(pdev->irq, sca_intr, IRQF_SHARED, "pci200syn", card)) {
pr_warn("could not allocate IRQ%d\n", pdev->irq);
pci200_pci_remove_one(pdev);
return -EBUSY;
}
card->irq = pdev->irq;
sca_init(card, 0);
for (i = 0; i < 2; i++) {
port_t *port = &card->ports[i];
struct net_device *dev = port->netdev;
hdlc_device *hdlc = dev_to_hdlc(dev);
port->chan = i;
spin_lock_init(&port->lock);
dev->irq = card->irq;
dev->mem_start = ramphys;
dev->mem_end = ramphys + ramsize - 1;
dev->tx_queue_len = 50;
dev->netdev_ops = &pci200_ops;
hdlc->attach = sca_attach;
hdlc->xmit = sca_xmit;
port->settings.clock_type = CLOCK_EXT;
port->card = card;
sca_init_port(port);
if (register_hdlc_device(dev)) {
pr_err("unable to register hdlc device\n");
port->card = NULL;
pci200_pci_remove_one(pdev);
return -ENOBUFS;
}
netdev_info(dev, "PCI200SYN channel %d\n", port->chan);
}
sca_flush(card);
return 0;
}
static int __init pci200_init_module(void)
{
if (pci_clock_freq < 1000000 || pci_clock_freq > 80000000) {
pr_err("Invalid PCI clock frequency\n");
return -EINVAL;
}
return pci_register_driver(&pci200_pci_driver);
}
static void __exit pci200_cleanup_module(void)
{
pci_unregister_driver(&pci200_pci_driver);
}
