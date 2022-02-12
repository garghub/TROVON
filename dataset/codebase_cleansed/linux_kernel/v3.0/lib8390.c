static int __ei_open(struct net_device *dev)
{
unsigned long flags;
struct ei_device *ei_local = netdev_priv(dev);
if (dev->watchdog_timeo <= 0)
dev->watchdog_timeo = TX_TIMEOUT;
spin_lock_irqsave(&ei_local->page_lock, flags);
__NS8390_init(dev, 1);
netif_start_queue(dev);
spin_unlock_irqrestore(&ei_local->page_lock, flags);
ei_local->irqlock = 0;
return 0;
}
static int __ei_close(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&ei_local->page_lock, flags);
__NS8390_init(dev, 0);
spin_unlock_irqrestore(&ei_local->page_lock, flags);
netif_stop_queue(dev);
return 0;
}
static void __ei_tx_timeout(struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
int txsr, isr, tickssofar = jiffies - dev_trans_start(dev);
unsigned long flags;
dev->stats.tx_errors++;
spin_lock_irqsave(&ei_local->page_lock, flags);
txsr = ei_inb(e8390_base+EN0_TSR);
isr = ei_inb(e8390_base+EN0_ISR);
spin_unlock_irqrestore(&ei_local->page_lock, flags);
printk(KERN_DEBUG "%s: Tx timed out, %s TSR=%#2x, ISR=%#2x, t=%d.\n",
dev->name, (txsr & ENTSR_ABT) ? "excess collisions." :
(isr) ? "lost interrupt?" : "cable problem?", txsr, isr, tickssofar);
if (!isr && !dev->stats.tx_packets)
{
ei_local->interface_num ^= 1;
}
disable_irq_nosync_lockdep(dev->irq);
spin_lock(&ei_local->page_lock);
ei_reset_8390(dev);
__NS8390_init(dev, 1);
spin_unlock(&ei_local->page_lock);
enable_irq_lockdep(dev->irq);
netif_wake_queue(dev);
}
static netdev_tx_t __ei_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
int send_length = skb->len, output_page;
unsigned long flags;
char buf[ETH_ZLEN];
char *data = skb->data;
if (skb->len < ETH_ZLEN) {
memset(buf, 0, ETH_ZLEN);
memcpy(buf, data, skb->len);
send_length = ETH_ZLEN;
data = buf;
}
spin_lock_irqsave(&ei_local->page_lock, flags);
ei_outb_p(0x00, e8390_base + EN0_IMR);
spin_unlock_irqrestore(&ei_local->page_lock, flags);
disable_irq_nosync_lockdep_irqsave(dev->irq, &flags);
spin_lock(&ei_local->page_lock);
ei_local->irqlock = 1;
if (ei_local->tx1 == 0)
{
output_page = ei_local->tx_start_page;
ei_local->tx1 = send_length;
if (ei_debug && ei_local->tx2 > 0)
printk(KERN_DEBUG "%s: idle transmitter tx2=%d, lasttx=%d, txing=%d.\n",
dev->name, ei_local->tx2, ei_local->lasttx, ei_local->txing);
}
else if (ei_local->tx2 == 0)
{
output_page = ei_local->tx_start_page + TX_PAGES/2;
ei_local->tx2 = send_length;
if (ei_debug && ei_local->tx1 > 0)
printk(KERN_DEBUG "%s: idle transmitter, tx1=%d, lasttx=%d, txing=%d.\n",
dev->name, ei_local->tx1, ei_local->lasttx, ei_local->txing);
}
else
{
if (ei_debug)
printk(KERN_DEBUG "%s: No Tx buffers free! tx1=%d tx2=%d last=%d\n",
dev->name, ei_local->tx1, ei_local->tx2, ei_local->lasttx);
ei_local->irqlock = 0;
netif_stop_queue(dev);
ei_outb_p(ENISR_ALL, e8390_base + EN0_IMR);
spin_unlock(&ei_local->page_lock);
enable_irq_lockdep_irqrestore(dev->irq, &flags);
dev->stats.tx_errors++;
return NETDEV_TX_BUSY;
}
ei_block_output(dev, send_length, data, output_page);
if (! ei_local->txing)
{
ei_local->txing = 1;
NS8390_trigger_send(dev, send_length, output_page);
if (output_page == ei_local->tx_start_page)
{
ei_local->tx1 = -1;
ei_local->lasttx = -1;
}
else
{
ei_local->tx2 = -1;
ei_local->lasttx = -2;
}
}
else ei_local->txqueue++;
if (ei_local->tx1 && ei_local->tx2)
netif_stop_queue(dev);
else
netif_start_queue(dev);
ei_local->irqlock = 0;
ei_outb_p(ENISR_ALL, e8390_base + EN0_IMR);
spin_unlock(&ei_local->page_lock);
enable_irq_lockdep_irqrestore(dev->irq, &flags);
dev_kfree_skb (skb);
dev->stats.tx_bytes += send_length;
return NETDEV_TX_OK;
}
static irqreturn_t __ei_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
unsigned long e8390_base = dev->base_addr;
int interrupts, nr_serviced = 0;
struct ei_device *ei_local = netdev_priv(dev);
spin_lock(&ei_local->page_lock);
if (ei_local->irqlock)
{
printk("%s: Interrupted while interrupts are masked!"
" isr=%#2x imr=%#2x.\n",
dev->name, ei_inb_p(e8390_base + EN0_ISR),
ei_inb_p(e8390_base + EN0_IMR));
spin_unlock(&ei_local->page_lock);
return IRQ_NONE;
}
ei_outb_p(E8390_NODMA+E8390_PAGE0, e8390_base + E8390_CMD);
if (ei_debug > 3)
printk(KERN_DEBUG "%s: interrupt(isr=%#2.2x).\n", dev->name,
ei_inb_p(e8390_base + EN0_ISR));
while ((interrupts = ei_inb_p(e8390_base + EN0_ISR)) != 0 &&
++nr_serviced < MAX_SERVICE)
{
if (!netif_running(dev)) {
printk(KERN_WARNING "%s: interrupt from stopped card\n", dev->name);
ei_outb_p(interrupts, e8390_base + EN0_ISR);
interrupts = 0;
break;
}
if (interrupts & ENISR_OVER)
ei_rx_overrun(dev);
else if (interrupts & (ENISR_RX+ENISR_RX_ERR))
{
ei_receive(dev);
}
if (interrupts & ENISR_TX)
ei_tx_intr(dev);
else if (interrupts & ENISR_TX_ERR)
ei_tx_err(dev);
if (interrupts & ENISR_COUNTERS)
{
dev->stats.rx_frame_errors += ei_inb_p(e8390_base + EN0_COUNTER0);
dev->stats.rx_crc_errors += ei_inb_p(e8390_base + EN0_COUNTER1);
dev->stats.rx_missed_errors+= ei_inb_p(e8390_base + EN0_COUNTER2);
ei_outb_p(ENISR_COUNTERS, e8390_base + EN0_ISR);
}
if (interrupts & ENISR_RDC)
{
ei_outb_p(ENISR_RDC, e8390_base + EN0_ISR);
}
ei_outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, e8390_base + E8390_CMD);
}
if (interrupts && ei_debug)
{
ei_outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, e8390_base + E8390_CMD);
if (nr_serviced >= MAX_SERVICE)
{
if(interrupts!=0xFF)
printk(KERN_WARNING "%s: Too much work at interrupt, status %#2.2x\n",
dev->name, interrupts);
ei_outb_p(ENISR_ALL, e8390_base + EN0_ISR);
} else {
printk(KERN_WARNING "%s: unknown interrupt %#2x\n", dev->name, interrupts);
ei_outb_p(0xff, e8390_base + EN0_ISR);
}
}
spin_unlock(&ei_local->page_lock);
return IRQ_RETVAL(nr_serviced > 0);
}
static void __ei_poll(struct net_device *dev)
{
disable_irq(dev->irq);
__ei_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static void ei_tx_err(struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local __maybe_unused = netdev_priv(dev);
unsigned char txsr = ei_inb_p(e8390_base+EN0_TSR);
unsigned char tx_was_aborted = txsr & (ENTSR_ABT+ENTSR_FU);
#ifdef VERBOSE_ERROR_DUMP
printk(KERN_DEBUG "%s: transmitter error (%#2x): ", dev->name, txsr);
if (txsr & ENTSR_ABT)
printk("excess-collisions ");
if (txsr & ENTSR_ND)
printk("non-deferral ");
if (txsr & ENTSR_CRS)
printk("lost-carrier ");
if (txsr & ENTSR_FU)
printk("FIFO-underrun ");
if (txsr & ENTSR_CDH)
printk("lost-heartbeat ");
printk("\n");
#endif
ei_outb_p(ENISR_TX_ERR, e8390_base + EN0_ISR);
if (tx_was_aborted)
ei_tx_intr(dev);
else
{
dev->stats.tx_errors++;
if (txsr & ENTSR_CRS) dev->stats.tx_carrier_errors++;
if (txsr & ENTSR_CDH) dev->stats.tx_heartbeat_errors++;
if (txsr & ENTSR_OWC) dev->stats.tx_window_errors++;
}
}
static void ei_tx_intr(struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
int status = ei_inb(e8390_base + EN0_TSR);
ei_outb_p(ENISR_TX, e8390_base + EN0_ISR);
ei_local->txqueue--;
if (ei_local->tx1 < 0)
{
if (ei_local->lasttx != 1 && ei_local->lasttx != -1)
printk(KERN_ERR "%s: bogus last_tx_buffer %d, tx1=%d.\n",
ei_local->name, ei_local->lasttx, ei_local->tx1);
ei_local->tx1 = 0;
if (ei_local->tx2 > 0)
{
ei_local->txing = 1;
NS8390_trigger_send(dev, ei_local->tx2, ei_local->tx_start_page + 6);
dev->trans_start = jiffies;
ei_local->tx2 = -1,
ei_local->lasttx = 2;
}
else ei_local->lasttx = 20, ei_local->txing = 0;
}
else if (ei_local->tx2 < 0)
{
if (ei_local->lasttx != 2 && ei_local->lasttx != -2)
printk("%s: bogus last_tx_buffer %d, tx2=%d.\n",
ei_local->name, ei_local->lasttx, ei_local->tx2);
ei_local->tx2 = 0;
if (ei_local->tx1 > 0)
{
ei_local->txing = 1;
NS8390_trigger_send(dev, ei_local->tx1, ei_local->tx_start_page);
dev->trans_start = jiffies;
ei_local->tx1 = -1;
ei_local->lasttx = 1;
}
else
ei_local->lasttx = 10, ei_local->txing = 0;
}
if (status & ENTSR_COL)
dev->stats.collisions++;
if (status & ENTSR_PTX)
dev->stats.tx_packets++;
else
{
dev->stats.tx_errors++;
if (status & ENTSR_ABT)
{
dev->stats.tx_aborted_errors++;
dev->stats.collisions += 16;
}
if (status & ENTSR_CRS)
dev->stats.tx_carrier_errors++;
if (status & ENTSR_FU)
dev->stats.tx_fifo_errors++;
if (status & ENTSR_CDH)
dev->stats.tx_heartbeat_errors++;
if (status & ENTSR_OWC)
dev->stats.tx_window_errors++;
}
netif_wake_queue(dev);
}
static void ei_receive(struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
unsigned char rxing_page, this_frame, next_frame;
unsigned short current_offset;
int rx_pkt_count = 0;
struct e8390_pkt_hdr rx_frame;
int num_rx_pages = ei_local->stop_page-ei_local->rx_start_page;
while (++rx_pkt_count < 10)
{
int pkt_len, pkt_stat;
ei_outb_p(E8390_NODMA+E8390_PAGE1, e8390_base + E8390_CMD);
rxing_page = ei_inb_p(e8390_base + EN1_CURPAG);
ei_outb_p(E8390_NODMA+E8390_PAGE0, e8390_base + E8390_CMD);
this_frame = ei_inb_p(e8390_base + EN0_BOUNDARY) + 1;
if (this_frame >= ei_local->stop_page)
this_frame = ei_local->rx_start_page;
if (ei_debug > 0 && this_frame != ei_local->current_page && (this_frame!=0x0 || rxing_page!=0xFF))
printk(KERN_ERR "%s: mismatched read page pointers %2x vs %2x.\n",
dev->name, this_frame, ei_local->current_page);
if (this_frame == rxing_page)
break;
current_offset = this_frame << 8;
ei_get_8390_hdr(dev, &rx_frame, this_frame);
pkt_len = rx_frame.count - sizeof(struct e8390_pkt_hdr);
pkt_stat = rx_frame.status;
next_frame = this_frame + 1 + ((pkt_len+4)>>8);
if (rx_frame.next != next_frame &&
rx_frame.next != next_frame + 1 &&
rx_frame.next != next_frame - num_rx_pages &&
rx_frame.next != next_frame + 1 - num_rx_pages) {
ei_local->current_page = rxing_page;
ei_outb(ei_local->current_page-1, e8390_base+EN0_BOUNDARY);
dev->stats.rx_errors++;
continue;
}
if (pkt_len < 60 || pkt_len > 1518)
{
if (ei_debug)
printk(KERN_DEBUG "%s: bogus packet size: %d, status=%#2x nxpg=%#2x.\n",
dev->name, rx_frame.count, rx_frame.status,
rx_frame.next);
dev->stats.rx_errors++;
dev->stats.rx_length_errors++;
}
else if ((pkt_stat & 0x0F) == ENRSR_RXOK)
{
struct sk_buff *skb;
skb = dev_alloc_skb(pkt_len+2);
if (skb == NULL)
{
if (ei_debug > 1)
printk(KERN_DEBUG "%s: Couldn't allocate a sk_buff of size %d.\n",
dev->name, pkt_len);
dev->stats.rx_dropped++;
break;
}
else
{
skb_reserve(skb,2);
skb_put(skb, pkt_len);
ei_block_input(dev, pkt_len, skb, current_offset + sizeof(rx_frame));
skb->protocol=eth_type_trans(skb,dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
if (pkt_stat & ENRSR_PHY)
dev->stats.multicast++;
}
}
else
{
if (ei_debug)
printk(KERN_DEBUG "%s: bogus packet: status=%#2x nxpg=%#2x size=%d\n",
dev->name, rx_frame.status, rx_frame.next,
rx_frame.count);
dev->stats.rx_errors++;
if (pkt_stat & ENRSR_FO)
dev->stats.rx_fifo_errors++;
}
next_frame = rx_frame.next;
if (next_frame >= ei_local->stop_page) {
printk("%s: next frame inconsistency, %#2x\n", dev->name,
next_frame);
next_frame = ei_local->rx_start_page;
}
ei_local->current_page = next_frame;
ei_outb_p(next_frame-1, e8390_base+EN0_BOUNDARY);
}
ei_outb_p(ENISR_RX+ENISR_RX_ERR, e8390_base+EN0_ISR);
}
static void ei_rx_overrun(struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
unsigned char was_txing, must_resend = 0;
struct ei_device *ei_local __maybe_unused = netdev_priv(dev);
was_txing = ei_inb_p(e8390_base+E8390_CMD) & E8390_TRANS;
ei_outb_p(E8390_NODMA+E8390_PAGE0+E8390_STOP, e8390_base+E8390_CMD);
if (ei_debug > 1)
printk(KERN_DEBUG "%s: Receiver overrun.\n", dev->name);
dev->stats.rx_over_errors++;
mdelay(10);
ei_outb_p(0x00, e8390_base+EN0_RCNTLO);
ei_outb_p(0x00, e8390_base+EN0_RCNTHI);
if (was_txing)
{
unsigned char tx_completed = ei_inb_p(e8390_base+EN0_ISR) & (ENISR_TX+ENISR_TX_ERR);
if (!tx_completed)
must_resend = 1;
}
ei_outb_p(E8390_TXOFF, e8390_base + EN0_TXCR);
ei_outb_p(E8390_NODMA + E8390_PAGE0 + E8390_START, e8390_base + E8390_CMD);
ei_receive(dev);
ei_outb_p(ENISR_OVER, e8390_base+EN0_ISR);
ei_outb_p(E8390_TXCONFIG, e8390_base + EN0_TXCR);
if (must_resend)
ei_outb_p(E8390_NODMA + E8390_PAGE0 + E8390_START + E8390_TRANS, e8390_base + E8390_CMD);
}
static struct net_device_stats *__ei_get_stats(struct net_device *dev)
{
unsigned long ioaddr = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
unsigned long flags;
if (!netif_running(dev))
return &dev->stats;
spin_lock_irqsave(&ei_local->page_lock,flags);
dev->stats.rx_frame_errors += ei_inb_p(ioaddr + EN0_COUNTER0);
dev->stats.rx_crc_errors += ei_inb_p(ioaddr + EN0_COUNTER1);
dev->stats.rx_missed_errors+= ei_inb_p(ioaddr + EN0_COUNTER2);
spin_unlock_irqrestore(&ei_local->page_lock, flags);
return &dev->stats;
}
static inline void make_mc_bits(u8 *bits, struct net_device *dev)
{
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, dev) {
u32 crc = ether_crc(ETH_ALEN, ha->addr);
bits[crc>>29] |= (1<<((crc>>26)&7));
}
}
static void do_set_multicast_list(struct net_device *dev)
{
unsigned long e8390_base = dev->base_addr;
int i;
struct ei_device *ei_local = netdev_priv(dev);
if (!(dev->flags&(IFF_PROMISC|IFF_ALLMULTI)))
{
memset(ei_local->mcfilter, 0, 8);
if (!netdev_mc_empty(dev))
make_mc_bits(ei_local->mcfilter, dev);
}
else
memset(ei_local->mcfilter, 0xFF, 8);
if (netif_running(dev))
ei_outb_p(E8390_RXCONFIG, e8390_base + EN0_RXCR);
ei_outb_p(E8390_NODMA + E8390_PAGE1, e8390_base + E8390_CMD);
for(i = 0; i < 8; i++)
{
ei_outb_p(ei_local->mcfilter[i], e8390_base + EN1_MULT_SHIFT(i));
#ifndef BUG_83C690
if(ei_inb_p(e8390_base + EN1_MULT_SHIFT(i))!=ei_local->mcfilter[i])
printk(KERN_ERR "Multicast filter read/write mismap %d\n",i);
#endif
}
ei_outb_p(E8390_NODMA + E8390_PAGE0, e8390_base + E8390_CMD);
if(dev->flags&IFF_PROMISC)
ei_outb_p(E8390_RXCONFIG | 0x18, e8390_base + EN0_RXCR);
else if (dev->flags & IFF_ALLMULTI || !netdev_mc_empty(dev))
ei_outb_p(E8390_RXCONFIG | 0x08, e8390_base + EN0_RXCR);
else
ei_outb_p(E8390_RXCONFIG, e8390_base + EN0_RXCR);
}
static void __ei_set_multicast_list(struct net_device *dev)
{
unsigned long flags;
struct ei_device *ei_local = netdev_priv(dev);
spin_lock_irqsave(&ei_local->page_lock, flags);
do_set_multicast_list(dev);
spin_unlock_irqrestore(&ei_local->page_lock, flags);
}
static void ethdev_setup(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
if (ei_debug > 1)
printk(version);
ether_setup(dev);
spin_lock_init(&ei_local->page_lock);
}
static struct net_device *____alloc_ei_netdev(int size)
{
return alloc_netdev(sizeof(struct ei_device) + size, "eth%d",
ethdev_setup);
}
static void __NS8390_init(struct net_device *dev, int startp)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
int i;
int endcfg = ei_local->word16
? (0x48 | ENDCFG_WTS | (ei_local->bigendian ? ENDCFG_BOS : 0))
: 0x48;
if(sizeof(struct e8390_pkt_hdr)!=4)
panic("8390.c: header struct mispacked\n");
ei_outb_p(E8390_NODMA+E8390_PAGE0+E8390_STOP, e8390_base+E8390_CMD);
ei_outb_p(endcfg, e8390_base + EN0_DCFG);
ei_outb_p(0x00, e8390_base + EN0_RCNTLO);
ei_outb_p(0x00, e8390_base + EN0_RCNTHI);
ei_outb_p(E8390_RXOFF, e8390_base + EN0_RXCR);
ei_outb_p(E8390_TXOFF, e8390_base + EN0_TXCR);
ei_outb_p(ei_local->tx_start_page, e8390_base + EN0_TPSR);
ei_local->tx1 = ei_local->tx2 = 0;
ei_outb_p(ei_local->rx_start_page, e8390_base + EN0_STARTPG);
ei_outb_p(ei_local->stop_page-1, e8390_base + EN0_BOUNDARY);
ei_local->current_page = ei_local->rx_start_page;
ei_outb_p(ei_local->stop_page, e8390_base + EN0_STOPPG);
ei_outb_p(0xFF, e8390_base + EN0_ISR);
ei_outb_p(0x00, e8390_base + EN0_IMR);
ei_outb_p(E8390_NODMA + E8390_PAGE1 + E8390_STOP, e8390_base+E8390_CMD);
for(i = 0; i < 6; i++)
{
ei_outb_p(dev->dev_addr[i], e8390_base + EN1_PHYS_SHIFT(i));
if (ei_debug > 1 && ei_inb_p(e8390_base + EN1_PHYS_SHIFT(i))!=dev->dev_addr[i])
printk(KERN_ERR "Hw. address read/write mismap %d\n",i);
}
ei_outb_p(ei_local->rx_start_page, e8390_base + EN1_CURPAG);
ei_outb_p(E8390_NODMA+E8390_PAGE0+E8390_STOP, e8390_base+E8390_CMD);
ei_local->tx1 = ei_local->tx2 = 0;
ei_local->txing = 0;
if (startp)
{
ei_outb_p(0xff, e8390_base + EN0_ISR);
ei_outb_p(ENISR_ALL, e8390_base + EN0_IMR);
ei_outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, e8390_base+E8390_CMD);
ei_outb_p(E8390_TXCONFIG, e8390_base + EN0_TXCR);
ei_outb_p(E8390_RXCONFIG, e8390_base + EN0_RXCR);
do_set_multicast_list(dev);
}
}
static void NS8390_trigger_send(struct net_device *dev, unsigned int length,
int start_page)
{
unsigned long e8390_base = dev->base_addr;
struct ei_device *ei_local __attribute((unused)) = netdev_priv(dev);
ei_outb_p(E8390_NODMA+E8390_PAGE0, e8390_base+E8390_CMD);
if (ei_inb_p(e8390_base + E8390_CMD) & E8390_TRANS)
{
printk(KERN_WARNING "%s: trigger_send() called with the transmitter busy.\n",
dev->name);
return;
}
ei_outb_p(length & 0xff, e8390_base + EN0_TCNTLO);
ei_outb_p(length >> 8, e8390_base + EN0_TCNTHI);
ei_outb_p(start_page, e8390_base + EN0_TPSR);
ei_outb_p(E8390_NODMA+E8390_TRANS+E8390_START, e8390_base+E8390_CMD);
}
