struct net_device * __init ni5010_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct ni5010_local));
int *port;
int err = 0;
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
io = dev->base_addr;
irq = dev->irq;
}
PRINTK2((KERN_DEBUG "%s: Entering ni5010_probe\n", dev->name));
if (io > 0x1ff) {
err = ni5010_probe1(dev, io);
} else if (io != 0) {
err = -ENXIO;
} else {
#ifdef FULL_IODETECT
for (io=0x200; io<0x400 && ni5010_probe1(dev, io) ; io+=0x20)
;
if (io == 0x400)
err = -ENODEV;
#else
for (port = ports; *port && ni5010_probe1(dev, *port); port++)
;
if (!*port)
err = -ENODEV;
#endif
}
if (err)
goto out;
err = register_netdev(dev);
if (err)
goto out1;
return dev;
out1:
release_region(dev->base_addr, NI5010_IO_EXTENT);
out:
free_netdev(dev);
return ERR_PTR(err);
}
static inline int rd_port(int ioaddr)
{
inb(IE_RBUF);
return inb(IE_SAPROM);
}
static void __init trigger_irq(int ioaddr)
{
outb(0x00, EDLC_RESET);
outb(0x00, IE_RESET);
outb(0x00, EDLC_XMASK);
outb(0x00, EDLC_RMASK);
outb(0xff, EDLC_XCLR);
outb(0xff, EDLC_RCLR);
outb(XMD_IG_PAR | XMD_T_MODE | XMD_LBC, EDLC_XMODE);
outb(RMD_BROADCAST, EDLC_RMODE);
outb(XM_ALL, EDLC_XMASK);
udelay(50);
outb(MM_EN_XMT|MM_MUX, IE_MMODE);
}
static int __init ni5010_probe1(struct net_device *dev, int ioaddr)
{
static unsigned version_printed;
struct ni5010_local *lp;
int i;
unsigned int data = 0;
int boguscount = 40;
int err = -ENODEV;
dev->base_addr = ioaddr;
dev->irq = irq;
if (!request_region(ioaddr, NI5010_IO_EXTENT, boardname))
return -EBUSY;
PRINTK2((KERN_DEBUG "%s: entering ni5010_probe1(%#3x)\n",
dev->name, ioaddr));
if (inb(ioaddr+0) == 0xff)
goto out;
while ( (rd_port(ioaddr) & rd_port(ioaddr) & rd_port(ioaddr) &
rd_port(ioaddr) & rd_port(ioaddr) & rd_port(ioaddr)) != 0xff)
{
if (boguscount-- == 0)
goto out;
}
PRINTK2((KERN_DEBUG "%s: I/O #1 passed!\n", dev->name));
for (i=0; i<32; i++)
if ( (data = rd_port(ioaddr)) != 0xff) break;
if (data==0xff)
goto out;
PRINTK2((KERN_DEBUG "%s: I/O #2 passed!\n", dev->name));
if ((data != SA_ADDR0) || (rd_port(ioaddr) != SA_ADDR1) ||
(rd_port(ioaddr) != SA_ADDR2))
goto out;
for (i=0; i<4; i++)
rd_port(ioaddr);
if ( (rd_port(ioaddr) != NI5010_MAGICVAL1) ||
(rd_port(ioaddr) != NI5010_MAGICVAL2) )
goto out;
PRINTK2((KERN_DEBUG "%s: I/O #3 passed!\n", dev->name));
if (NI5010_DEBUG && version_printed++ == 0)
printk(KERN_INFO "%s", version);
printk("NI5010 ethercard probe at 0x%x: ", ioaddr);
dev->base_addr = ioaddr;
for (i=0; i<6; i++) {
outw(i, IE_GP);
dev->dev_addr[i] = inb(IE_SAPROM);
}
printk("%pM ", dev->dev_addr);
PRINTK2((KERN_DEBUG "%s: I/O #4 passed!\n", dev->name));
#ifdef JUMPERED_INTERRUPTS
if (dev->irq == 0xff)
;
else if (dev->irq < 2) {
unsigned long irq_mask;
PRINTK2((KERN_DEBUG "%s: I/O #5 passed!\n", dev->name));
irq_mask = probe_irq_on();
trigger_irq(ioaddr);
mdelay(20);
dev->irq = probe_irq_off(irq_mask);
PRINTK2((KERN_DEBUG "%s: I/O #6 passed!\n", dev->name));
if (dev->irq == 0) {
err = -EAGAIN;
printk(KERN_WARNING "%s: no IRQ found!\n", dev->name);
goto out;
}
PRINTK2((KERN_DEBUG "%s: I/O #7 passed!\n", dev->name));
} else if (dev->irq == 2) {
dev->irq = 9;
}
#endif
PRINTK2((KERN_DEBUG "%s: I/O #9 passed!\n", dev->name));
lp = netdev_priv(dev);
spin_lock_init(&lp->lock);
PRINTK2((KERN_DEBUG "%s: I/O #10 passed!\n", dev->name));
if (!bufsize_rcv) {
outb(1, IE_MMODE);
outw(0, IE_GP);
outb(0, IE_RBUF);
for (i = 1; i < 0xff; i++) {
outw(i << 8, IE_GP);
outb(i, IE_RBUF);
outw(0x0, IE_GP);
data = inb(IE_RBUF);
if (data == i) break;
}
bufsize_rcv = i << 8;
outw(0, IE_GP);
outb(0, IE_RBUF);
}
printk("-> bufsize rcv/xmt=%d/%d\n", bufsize_rcv, NI5010_BUFSIZE);
dev->netdev_ops = &ni5010_netdev_ops;
dev->watchdog_timeo = HZ/20;
dev->flags &= ~IFF_MULTICAST;
outb(0, EDLC_RMASK);
outb(0, EDLC_XMASK);
outb(0xff, EDLC_RCLR);
outb(0xff, EDLC_XCLR);
printk(KERN_INFO "%s: NI5010 found at 0x%x, using IRQ %d", dev->name, ioaddr, dev->irq);
if (dev->dma)
printk(" & DMA %d", dev->dma);
printk(".\n");
return 0;
out:
release_region(dev->base_addr, NI5010_IO_EXTENT);
return err;
}
static int ni5010_open(struct net_device *dev)
{
int ioaddr = dev->base_addr;
int i;
PRINTK2((KERN_DEBUG "%s: entering ni5010_open()\n", dev->name));
if (request_irq(dev->irq, ni5010_interrupt, 0, boardname, dev)) {
printk(KERN_WARNING "%s: Cannot get irq %#2x\n", dev->name, dev->irq);
return -EAGAIN;
}
PRINTK3((KERN_DEBUG "%s: passed open() #1\n", dev->name));
#ifdef JUMPERED_DMA
if (request_dma(dev->dma, cardname)) {
printk(KERN_WARNING "%s: Cannot get dma %#2x\n", dev->name, dev->dma);
free_irq(dev->irq, NULL);
return -EAGAIN;
}
#endif
PRINTK3((KERN_DEBUG "%s: passed open() #2\n", dev->name));
outb(RS_RESET, EDLC_RESET);
outb(0, IE_RESET);
outb(XMD_LBC, EDLC_XMODE);
PRINTK3((KERN_DEBUG "%s: passed open() #3\n", dev->name));
for(i = 0;i < 6; i++) {
outb(dev->dev_addr[i], EDLC_ADDR + i);
}
PRINTK3((KERN_DEBUG "%s: Initialising ni5010\n", dev->name));
outb(0, EDLC_XMASK);
outb(XMD_IG_PAR | XMD_T_MODE | XMD_LBC, EDLC_XMODE);
outb(0xff, EDLC_XCLR);
outb(RMD_BROADCAST, EDLC_RMODE);
reset_receiver(dev);
outb(0, EDLC_RESET);
netif_start_queue(dev);
if (NI5010_DEBUG) ni5010_show_registers(dev);
PRINTK((KERN_DEBUG "%s: open successful\n", dev->name));
return 0;
}
static void reset_receiver(struct net_device *dev)
{
int ioaddr = dev->base_addr;
PRINTK3((KERN_DEBUG "%s: resetting receiver\n", dev->name));
outw(0, IE_GP);
outb(0xff, EDLC_RCLR);
outb(0, IE_MMODE);
outb(MM_EN_RCV, IE_MMODE);
outb(0xff, EDLC_RMASK);
}
static void ni5010_timeout(struct net_device *dev)
{
printk(KERN_WARNING "%s: transmit timed out, %s?\n", dev->name,
tx_done(dev) ? "IRQ conflict" : "network cable problem");
chipset_init(dev, 1);
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
static int ni5010_send_packet(struct sk_buff *skb, struct net_device *dev)
{
int length = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
PRINTK2((KERN_DEBUG "%s: entering ni5010_send_packet\n", dev->name));
netif_stop_queue(dev);
hardware_send_packet(dev, (unsigned char *)skb->data, skb->len, length-skb->len);
dev_kfree_skb (skb);
return NETDEV_TX_OK;
}
static irqreturn_t ni5010_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct ni5010_local *lp;
int ioaddr, status;
int xmit_was_error = 0;
PRINTK2((KERN_DEBUG "%s: entering ni5010_interrupt\n", dev->name));
ioaddr = dev->base_addr;
lp = netdev_priv(dev);
spin_lock(&lp->lock);
status = inb(IE_ISTAT);
PRINTK3((KERN_DEBUG "%s: IE_ISTAT = %#02x\n", dev->name, status));
if ((status & IS_R_INT) == 0) ni5010_rx(dev);
if ((status & IS_X_INT) == 0) {
xmit_was_error = process_xmt_interrupt(dev);
}
if ((status & IS_DMA_INT) == 0) {
PRINTK((KERN_DEBUG "%s: DMA complete (?)\n", dev->name));
outb(0, IE_DMA_RST);
}
if (!xmit_was_error)
reset_receiver(dev);
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
static void dump_packet(void *buf, int len)
{
int i;
printk(KERN_DEBUG "Packet length = %#4x\n", len);
for (i = 0; i < len; i++){
if (i % 16 == 0) printk(KERN_DEBUG "%#4.4x", i);
if (i % 2 == 0) printk(" ");
printk("%2.2x", ((unsigned char *)buf)[i]);
if (i % 16 == 15) printk("\n");
}
printk("\n");
}
static void ni5010_rx(struct net_device *dev)
{
int ioaddr = dev->base_addr;
unsigned char rcv_stat;
struct sk_buff *skb;
int i_pkt_size;
PRINTK2((KERN_DEBUG "%s: entering ni5010_rx()\n", dev->name));
rcv_stat = inb(EDLC_RSTAT);
PRINTK3((KERN_DEBUG "%s: EDLC_RSTAT = %#2x\n", dev->name, rcv_stat));
if ( (rcv_stat & RS_VALID_BITS) != RS_PKT_OK) {
PRINTK((KERN_INFO "%s: receive error.\n", dev->name));
dev->stats.rx_errors++;
if (rcv_stat & RS_RUNT) dev->stats.rx_length_errors++;
if (rcv_stat & RS_ALIGN) dev->stats.rx_frame_errors++;
if (rcv_stat & RS_CRC_ERR) dev->stats.rx_crc_errors++;
if (rcv_stat & RS_OFLW) dev->stats.rx_fifo_errors++;
outb(0xff, EDLC_RCLR);
return;
}
outb(0xff, EDLC_RCLR);
i_pkt_size = inw(IE_RCNT);
if (i_pkt_size > ETH_FRAME_LEN || i_pkt_size < 10 ) {
PRINTK((KERN_DEBUG "%s: Packet size error, packet size = %#4.4x\n",
dev->name, i_pkt_size));
dev->stats.rx_errors++;
dev->stats.rx_length_errors++;
return;
}
skb = netdev_alloc_skb(dev, i_pkt_size + 3);
if (skb == NULL) {
printk(KERN_WARNING "%s: Memory squeeze, dropping packet.\n", dev->name);
dev->stats.rx_dropped++;
return;
}
skb_reserve(skb, 2);
outb(MM_MUX, IE_MMODE);
outw(0, IE_GP);
insb(IE_RBUF, skb_put(skb, i_pkt_size), i_pkt_size);
if (NI5010_DEBUG >= 4)
dump_packet(skb->data, skb->len);
skb->protocol = eth_type_trans(skb,dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += i_pkt_size;
PRINTK2((KERN_DEBUG "%s: Received packet, size=%#4.4x\n",
dev->name, i_pkt_size));
}
static int process_xmt_interrupt(struct net_device *dev)
{
struct ni5010_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
int xmit_stat;
PRINTK2((KERN_DEBUG "%s: entering process_xmt_interrupt\n", dev->name));
xmit_stat = inb(EDLC_XSTAT);
PRINTK3((KERN_DEBUG "%s: EDLC_XSTAT = %2.2x\n", dev->name, xmit_stat));
outb(0, EDLC_XMASK);
outb(0xff, EDLC_XCLR);
if (xmit_stat & XS_COLL){
PRINTK((KERN_DEBUG "%s: collision detected, retransmitting\n",
dev->name));
outw(NI5010_BUFSIZE - lp->o_pkt_size, IE_GP);
outb(MM_EN_XMT | MM_MUX, IE_MMODE);
outb(XM_ALL, EDLC_XMASK);
dev->stats.collisions++;
return 1;
}
dev->stats.tx_packets++;
dev->stats.tx_bytes += lp->o_pkt_size;
netif_wake_queue(dev);
PRINTK2((KERN_DEBUG "%s: sent packet, size=%#4.4x\n",
dev->name, lp->o_pkt_size));
return 0;
}
static int ni5010_close(struct net_device *dev)
{
int ioaddr = dev->base_addr;
PRINTK2((KERN_DEBUG "%s: entering ni5010_close\n", dev->name));
#ifdef JUMPERED_INTERRUPTS
free_irq(dev->irq, NULL);
#endif
outb(0, IE_MMODE);
outb(RS_RESET, EDLC_RESET);
netif_stop_queue(dev);
PRINTK((KERN_DEBUG "%s: %s closed down\n", dev->name, boardname));
return 0;
}
static void ni5010_set_multicast_list(struct net_device *dev)
{
short ioaddr = dev->base_addr;
PRINTK2((KERN_DEBUG "%s: entering set_multicast_list\n", dev->name));
if (dev->flags & IFF_PROMISC || dev->flags & IFF_ALLMULTI ||
!netdev_mc_empty(dev)) {
outb(RMD_PROMISC, EDLC_RMODE);
PRINTK((KERN_DEBUG "%s: Entering promiscuous mode\n", dev->name));
} else {
PRINTK((KERN_DEBUG "%s: Entering broadcast mode\n", dev->name));
outb(RMD_BROADCAST, EDLC_RMODE);
}
}
static void hardware_send_packet(struct net_device *dev, char *buf, int length, int pad)
{
struct ni5010_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
unsigned long flags;
unsigned int buf_offs;
PRINTK2((KERN_DEBUG "%s: entering hardware_send_packet\n", dev->name));
if (length > ETH_FRAME_LEN) {
PRINTK((KERN_WARNING "%s: packet too large, not possible\n",
dev->name));
return;
}
if (NI5010_DEBUG) ni5010_show_registers(dev);
if (inb(IE_ISTAT) & IS_EN_XMT) {
PRINTK((KERN_WARNING "%s: sending packet while already transmitting, not possible\n",
dev->name));
return;
}
if (NI5010_DEBUG > 3) dump_packet(buf, length);
buf_offs = NI5010_BUFSIZE - length - pad;
spin_lock_irqsave(&lp->lock, flags);
lp->o_pkt_size = length + pad;
outb(0, EDLC_RMASK);
outb(0, IE_MMODE);
outb(0xff, EDLC_RCLR);
outw(buf_offs, IE_GP);
outsb(IE_XBUF, buf, length);
while(pad--)
outb(0, IE_XBUF);
outw(buf_offs, IE_GP);
outb(MM_EN_XMT | MM_MUX, IE_MMODE);
outb(XM_ALL, EDLC_XMASK);
spin_unlock_irqrestore(&lp->lock, flags);
netif_wake_queue(dev);
if (NI5010_DEBUG) ni5010_show_registers(dev);
}
static void chipset_init(struct net_device *dev, int startp)
{
PRINTK3((KERN_DEBUG "%s: doing NOTHING in chipset_init\n", dev->name));
}
static void ni5010_show_registers(struct net_device *dev)
{
int ioaddr = dev->base_addr;
PRINTK3((KERN_DEBUG "%s: XSTAT %#2.2x\n", dev->name, inb(EDLC_XSTAT)));
PRINTK3((KERN_DEBUG "%s: XMASK %#2.2x\n", dev->name, inb(EDLC_XMASK)));
PRINTK3((KERN_DEBUG "%s: RSTAT %#2.2x\n", dev->name, inb(EDLC_RSTAT)));
PRINTK3((KERN_DEBUG "%s: RMASK %#2.2x\n", dev->name, inb(EDLC_RMASK)));
PRINTK3((KERN_DEBUG "%s: RMODE %#2.2x\n", dev->name, inb(EDLC_RMODE)));
PRINTK3((KERN_DEBUG "%s: XMODE %#2.2x\n", dev->name, inb(EDLC_XMODE)));
PRINTK3((KERN_DEBUG "%s: ISTAT %#2.2x\n", dev->name, inb(IE_ISTAT)));
}
static int __init ni5010_init_module(void)
{
PRINTK2((KERN_DEBUG "%s: entering init_module\n", boardname));
if (io <= 0){
printk(KERN_WARNING "%s: Autoprobing for modules is hazardous, trying anyway..\n", boardname);
}
PRINTK2((KERN_DEBUG "%s: init_module irq=%#2x, io=%#3x\n", boardname, irq, io));
dev_ni5010 = ni5010_probe(-1);
if (IS_ERR(dev_ni5010))
return PTR_ERR(dev_ni5010);
return 0;
}
static void __exit ni5010_cleanup_module(void)
{
PRINTK2((KERN_DEBUG "%s: entering cleanup_module\n", boardname));
unregister_netdev(dev_ni5010);
release_region(dev_ni5010->base_addr, NI5010_IO_EXTENT);
free_netdev(dev_ni5010);
}
