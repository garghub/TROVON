static __inline__ u8 sca_get_page(card_t *card)
{
return inb(card->io + N2_PSR) & PSR_PAGEBITS;
}
static __inline__ void openwin(card_t *card, u8 page)
{
u8 psr = inb(card->io + N2_PSR);
outb((psr & ~PSR_PAGEBITS) | page, card->io + N2_PSR);
}
static void n2_set_iface(port_t *port)
{
card_t *card = port->card;
int io = card->io;
u8 mcr = inb(io + N2_MCR);
u8 msci = get_msci(port);
u8 rxs = port->rxs & CLK_BRG_MASK;
u8 txs = port->txs & CLK_BRG_MASK;
switch(port->settings.clock_type) {
case CLOCK_INT:
mcr |= port->phy_node ? CLOCK_OUT_PORT1 : CLOCK_OUT_PORT0;
rxs |= CLK_BRG_RX;
txs |= CLK_RXCLK_TX;
break;
case CLOCK_TXINT:
mcr |= port->phy_node ? CLOCK_OUT_PORT1 : CLOCK_OUT_PORT0;
rxs |= CLK_LINE_RX;
txs |= CLK_BRG_TX;
break;
case CLOCK_TXFROMRX:
mcr |= port->phy_node ? CLOCK_OUT_PORT1 : CLOCK_OUT_PORT0;
rxs |= CLK_LINE_RX;
txs |= CLK_RXCLK_TX;
break;
default:
mcr &= port->phy_node ? ~CLOCK_OUT_PORT1 : ~CLOCK_OUT_PORT0;
rxs |= CLK_LINE_RX;
txs |= CLK_LINE_TX;
}
outb(mcr, io + N2_MCR);
port->rxs = rxs;
port->txs = txs;
sca_out(rxs, msci + RXS, card);
sca_out(txs, msci + TXS, card);
sca_set_port(port);
}
static int n2_open(struct net_device *dev)
{
port_t *port = dev_to_port(dev);
int io = port->card->io;
u8 mcr = inb(io + N2_MCR) | (port->phy_node ? TX422_PORT1:TX422_PORT0);
int result;
result = hdlc_open(dev);
if (result)
return result;
mcr &= port->phy_node ? ~DTR_PORT1 : ~DTR_PORT0;
outb(mcr, io + N2_MCR);
outb(inb(io + N2_PCR) | PCR_ENWIN, io + N2_PCR);
outb(inb(io + N2_PSR) | PSR_DMAEN, io + N2_PSR);
sca_open(dev);
n2_set_iface(port);
return 0;
}
static int n2_close(struct net_device *dev)
{
port_t *port = dev_to_port(dev);
int io = port->card->io;
u8 mcr = inb(io+N2_MCR) | (port->phy_node ? TX422_PORT1 : TX422_PORT0);
sca_close(dev);
mcr |= port->phy_node ? DTR_PORT1 : DTR_PORT0;
outb(mcr, io + N2_MCR);
hdlc_close(dev);
return 0;
}
static int n2_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
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
ifr->ifr_settings.type = IF_IFACE_SYNC_SERIAL;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
if (copy_to_user(line, &port->settings, size))
return -EFAULT;
return 0;
case IF_IFACE_SYNC_SERIAL:
if(!capable(CAP_NET_ADMIN))
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
n2_set_iface(port);
return 0;
default:
return hdlc_ioctl(dev, ifr, cmd);
}
}
static void n2_destroy_card(card_t *card)
{
int cnt;
for (cnt = 0; cnt < 2; cnt++)
if (card->ports[cnt].card) {
struct net_device *dev = port_to_dev(&card->ports[cnt]);
unregister_hdlc_device(dev);
}
if (card->irq)
free_irq(card->irq, card);
if (card->winbase) {
iounmap(card->winbase);
release_mem_region(card->phy_winbase, USE_WINDOWSIZE);
}
if (card->io)
release_region(card->io, N2_IOPORTS);
if (card->ports[0].dev)
free_netdev(card->ports[0].dev);
if (card->ports[1].dev)
free_netdev(card->ports[1].dev);
kfree(card);
}
static int __init n2_run(unsigned long io, unsigned long irq,
unsigned long winbase, long valid0, long valid1)
{
card_t *card;
u8 cnt, pcr;
int i;
if (io < 0x200 || io > 0x3FF || (io % N2_IOPORTS) != 0) {
pr_err("invalid I/O port value\n");
return -ENODEV;
}
if (irq < 3 || irq > 15 || irq == 6) {
pr_err("invalid IRQ value\n");
return -ENODEV;
}
if (winbase < 0xA0000 || winbase > 0xFFFFF || (winbase & 0xFFF) != 0) {
pr_err("invalid RAM value\n");
return -ENODEV;
}
card = kzalloc(sizeof(card_t), GFP_KERNEL);
if (card == NULL)
return -ENOBUFS;
card->ports[0].dev = alloc_hdlcdev(&card->ports[0]);
card->ports[1].dev = alloc_hdlcdev(&card->ports[1]);
if (!card->ports[0].dev || !card->ports[1].dev) {
pr_err("unable to allocate memory\n");
n2_destroy_card(card);
return -ENOMEM;
}
if (!request_region(io, N2_IOPORTS, devname)) {
pr_err("I/O port region in use\n");
n2_destroy_card(card);
return -EBUSY;
}
card->io = io;
if (request_irq(irq, sca_intr, 0, devname, card)) {
pr_err("could not allocate IRQ\n");
n2_destroy_card(card);
return -EBUSY;
}
card->irq = irq;
if (!request_mem_region(winbase, USE_WINDOWSIZE, devname)) {
pr_err("could not request RAM window\n");
n2_destroy_card(card);
return -EBUSY;
}
card->phy_winbase = winbase;
card->winbase = ioremap(winbase, USE_WINDOWSIZE);
if (!card->winbase) {
pr_err("ioremap() failed\n");
n2_destroy_card(card);
return -EFAULT;
}
outb(0, io + N2_PCR);
outb(winbase >> 12, io + N2_BAR);
switch (USE_WINDOWSIZE) {
case 16384:
outb(WIN16K, io + N2_PSR);
break;
case 32768:
outb(WIN32K, io + N2_PSR);
break;
case 65536:
outb(WIN64K, io + N2_PSR);
break;
default:
pr_err("invalid window size\n");
n2_destroy_card(card);
return -ENODEV;
}
pcr = PCR_ENWIN | PCR_VPM | (USE_BUS16BITS ? PCR_BUS16 : 0);
outb(pcr, io + N2_PCR);
card->ram_size = sca_detect_ram(card, card->winbase, MAX_RAM_SIZE);
i = card->ram_size / ((valid0 + valid1) * (sizeof(pkt_desc) +
HDLC_MAX_MRU));
card->tx_ring_buffers = min(i / 2, MAX_TX_BUFFERS);
card->rx_ring_buffers = i - card->tx_ring_buffers;
card->buff_offset = (valid0 + valid1) * sizeof(pkt_desc) *
(card->tx_ring_buffers + card->rx_ring_buffers);
pr_info("RISCom/N2 %u KB RAM, IRQ%u, using %u TX + %u RX packets rings\n",
card->ram_size / 1024, card->irq,
card->tx_ring_buffers, card->rx_ring_buffers);
if (card->tx_ring_buffers < 1) {
pr_err("RAM test failed\n");
n2_destroy_card(card);
return -EIO;
}
pcr |= PCR_RUNSCA;
outb(pcr, io + N2_PCR);
outb(0, io + N2_MCR);
sca_init(card, 0);
for (cnt = 0; cnt < 2; cnt++) {
port_t *port = &card->ports[cnt];
struct net_device *dev = port_to_dev(port);
hdlc_device *hdlc = dev_to_hdlc(dev);
if ((cnt == 0 && !valid0) || (cnt == 1 && !valid1))
continue;
port->phy_node = cnt;
port->valid = 1;
if ((cnt == 1) && valid0)
port->log_node = 1;
spin_lock_init(&port->lock);
dev->irq = irq;
dev->mem_start = winbase;
dev->mem_end = winbase + USE_WINDOWSIZE - 1;
dev->tx_queue_len = 50;
dev->netdev_ops = &n2_ops;
hdlc->attach = sca_attach;
hdlc->xmit = sca_xmit;
port->settings.clock_type = CLOCK_EXT;
port->card = card;
if (register_hdlc_device(dev)) {
pr_warn("unable to register hdlc device\n");
port->card = NULL;
n2_destroy_card(card);
return -ENOBUFS;
}
sca_init_port(port);
netdev_info(dev, "RISCom/N2 node %d\n", port->phy_node);
}
*new_card = card;
new_card = &card->next_card;
return 0;
}
static int __init n2_init(void)
{
if (hw==NULL) {
#ifdef MODULE
pr_info("no card initialized\n");
#endif
return -EINVAL;
}
pr_info("%s\n", version);
do {
unsigned long io, irq, ram;
long valid[2] = { 0, 0 };
io = simple_strtoul(hw, &hw, 0);
if (*hw++ != ',')
break;
irq = simple_strtoul(hw, &hw, 0);
if (*hw++ != ',')
break;
ram = simple_strtoul(hw, &hw, 0);
if (*hw++ != ',')
break;
while(1) {
if (*hw == '0' && !valid[0])
valid[0] = 1;
else if (*hw == '1' && !valid[1])
valid[1] = 1;
else
break;
hw++;
}
if (!valid[0] && !valid[1])
break;
if (*hw == ':' || *hw == '\x0')
n2_run(io, irq, ram, valid[0], valid[1]);
if (*hw == '\x0')
return first_card ? 0 : -EINVAL;
}while(*hw++ == ':');
pr_err("invalid hardware parameters\n");
return first_card ? 0 : -EINVAL;
}
static void __exit n2_cleanup(void)
{
card_t *card = first_card;
while (card) {
card_t *ptr = card;
card = card->next_card;
n2_destroy_card(ptr);
}
}
