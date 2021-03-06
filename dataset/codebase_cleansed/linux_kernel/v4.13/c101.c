static inline u8 sca_get_page(card_t *card)
{
return card->page;
}
static inline void openwin(card_t *card, u8 page)
{
card->page = page;
writeb(page, card->win0base + C101_PAGE);
}
static inline void set_carrier(port_t *port)
{
if (!(sca_in(MSCI1_OFFSET + ST3, port) & ST3_DCD))
netif_carrier_on(port_to_dev(port));
else
netif_carrier_off(port_to_dev(port));
}
static void sca_msci_intr(port_t *port)
{
u8 stat = sca_in(MSCI0_OFFSET + ST1, port);
sca_out(stat & (ST1_UDRN | ST1_CDCD), MSCI0_OFFSET + ST1, port);
if (stat & ST1_UDRN) {
port_to_dev(port)->stats.tx_errors++;
port_to_dev(port)->stats.tx_fifo_errors++;
}
stat = sca_in(MSCI1_OFFSET + ST1, port);
sca_out(stat & ST1_CDCD, MSCI1_OFFSET + ST1, port);
if (stat & ST1_CDCD)
set_carrier(port);
}
static void c101_set_iface(port_t *port)
{
u8 rxs = port->rxs & CLK_BRG_MASK;
u8 txs = port->txs & CLK_BRG_MASK;
switch(port->settings.clock_type) {
case CLOCK_INT:
rxs |= CLK_BRG_RX;
txs |= CLK_RXCLK_TX;
break;
case CLOCK_TXINT:
rxs |= CLK_LINE_RX;
txs |= CLK_BRG_TX;
break;
case CLOCK_TXFROMRX:
rxs |= CLK_LINE_RX;
txs |= CLK_RXCLK_TX;
break;
default:
rxs |= CLK_LINE_RX;
txs |= CLK_LINE_TX;
}
port->rxs = rxs;
port->txs = txs;
sca_out(rxs, MSCI1_OFFSET + RXS, port);
sca_out(txs, MSCI1_OFFSET + TXS, port);
sca_set_port(port);
}
static int c101_open(struct net_device *dev)
{
port_t *port = dev_to_port(dev);
int result;
result = hdlc_open(dev);
if (result)
return result;
writeb(1, port->win0base + C101_DTR);
sca_out(0, MSCI1_OFFSET + CTL, port);
sca_open(dev);
sca_out(IE1_UDRN, MSCI0_OFFSET + IE1, port);
sca_out(IE0_TXINT, MSCI0_OFFSET + IE0, port);
set_carrier(port);
sca_out(IE1_CDCD, MSCI1_OFFSET + IE1, port);
sca_out(IE0_RXINTA, MSCI1_OFFSET + IE0, port);
sca_out(0x48, IER0, port);
c101_set_iface(port);
return 0;
}
static int c101_close(struct net_device *dev)
{
port_t *port = dev_to_port(dev);
sca_close(dev);
writeb(0, port->win0base + C101_DTR);
sca_out(CTL_NORTS, MSCI1_OFFSET + CTL, port);
hdlc_close(dev);
return 0;
}
static int c101_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
const size_t size = sizeof(sync_serial_settings);
sync_serial_settings new_line;
sync_serial_settings __user *line = ifr->ifr_settings.ifs_ifsu.sync;
port_t *port = dev_to_port(dev);
#ifdef DEBUG_RINGS
if (cmd == SIOCDEVPRIVATE) {
sca_dump_rings(dev);
printk(KERN_DEBUG "MSCI1: ST: %02x %02x %02x %02x\n",
sca_in(MSCI1_OFFSET + ST0, port),
sca_in(MSCI1_OFFSET + ST1, port),
sca_in(MSCI1_OFFSET + ST2, port),
sca_in(MSCI1_OFFSET + ST3, port));
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
c101_set_iface(port);
return 0;
default:
return hdlc_ioctl(dev, ifr, cmd);
}
}
static void c101_destroy_card(card_t *card)
{
readb(card->win0base + C101_PAGE);
if (card->irq)
free_irq(card->irq, card);
if (card->win0base) {
iounmap(card->win0base);
release_mem_region(card->phy_winbase, C101_MAPPED_RAM_SIZE);
}
free_netdev(card->dev);
kfree(card);
}
static int __init c101_run(unsigned long irq, unsigned long winbase)
{
struct net_device *dev;
hdlc_device *hdlc;
card_t *card;
int result;
if (irq<3 || irq>15 || irq == 6) {
pr_err("invalid IRQ value\n");
return -ENODEV;
}
if (winbase < 0xC0000 || winbase > 0xDFFFF || (winbase & 0x3FFF) !=0) {
pr_err("invalid RAM value\n");
return -ENODEV;
}
card = kzalloc(sizeof(card_t), GFP_KERNEL);
if (card == NULL)
return -ENOBUFS;
card->dev = alloc_hdlcdev(card);
if (!card->dev) {
pr_err("unable to allocate memory\n");
kfree(card);
return -ENOBUFS;
}
if (request_irq(irq, sca_intr, 0, devname, card)) {
pr_err("could not allocate IRQ\n");
c101_destroy_card(card);
return -EBUSY;
}
card->irq = irq;
if (!request_mem_region(winbase, C101_MAPPED_RAM_SIZE, devname)) {
pr_err("could not request RAM window\n");
c101_destroy_card(card);
return -EBUSY;
}
card->phy_winbase = winbase;
card->win0base = ioremap(winbase, C101_MAPPED_RAM_SIZE);
if (!card->win0base) {
pr_err("could not map I/O address\n");
c101_destroy_card(card);
return -EFAULT;
}
card->tx_ring_buffers = TX_RING_BUFFERS;
card->rx_ring_buffers = RX_RING_BUFFERS;
card->buff_offset = C101_WINDOW_SIZE;
readb(card->win0base + C101_PAGE);
udelay(100);
writeb(0, card->win0base + C101_PAGE);
writeb(0, card->win0base + C101_DTR);
sca_init(card, 0);
dev = port_to_dev(card);
hdlc = dev_to_hdlc(dev);
spin_lock_init(&card->lock);
dev->irq = irq;
dev->mem_start = winbase;
dev->mem_end = winbase + C101_MAPPED_RAM_SIZE - 1;
dev->tx_queue_len = 50;
dev->netdev_ops = &c101_ops;
hdlc->attach = sca_attach;
hdlc->xmit = sca_xmit;
card->settings.clock_type = CLOCK_EXT;
result = register_hdlc_device(dev);
if (result) {
pr_warn("unable to register hdlc device\n");
c101_destroy_card(card);
return result;
}
sca_init_port(card);
set_carrier(card);
netdev_info(dev, "Moxa C101 on IRQ%u, using %u TX + %u RX packets rings\n",
card->irq, card->tx_ring_buffers, card->rx_ring_buffers);
*new_card = card;
new_card = &card->next_card;
return 0;
}
static int __init c101_init(void)
{
if (hw == NULL) {
#ifdef MODULE
pr_info("no card initialized\n");
#endif
return -EINVAL;
}
pr_info("%s\n", version);
do {
unsigned long irq, ram;
irq = simple_strtoul(hw, &hw, 0);
if (*hw++ != ',')
break;
ram = simple_strtoul(hw, &hw, 0);
if (*hw == ':' || *hw == '\x0')
c101_run(irq, ram);
if (*hw == '\x0')
return first_card ? 0 : -EINVAL;
}while(*hw++ == ':');
pr_err("invalid hardware parameters\n");
return first_card ? 0 : -EINVAL;
}
static void __exit c101_cleanup(void)
{
card_t *card = first_card;
while (card) {
card_t *ptr = card;
card = card->next_card;
unregister_hdlc_device(port_to_dev(ptr));
c101_destroy_card(ptr);
}
}
