static int __init init_reg_offset(struct net_device *dev,unsigned long base_addr)
{
struct ei_device *ei_local = netdev_priv(dev);
int i;
unsigned char bus_width;
bus_width = *(volatile unsigned char *)ABWCR;
bus_width &= 1 << ((base_addr >> 21) & 7);
for (i = 0; i < ARRAY_SIZE(reg_offset); i++)
if (bus_width == 0)
reg_offset[i] = i * 2 + 1;
else
reg_offset[i] = i;
ei_local->reg_offset = reg_offset;
return 0;
}
static inline int init_dev(struct net_device *dev)
{
if (h8300_ne_count < ARRAY_SIZE(h8300_ne_base)) {
dev->base_addr = h8300_ne_base[h8300_ne_count];
dev->irq = h8300_ne_irq[h8300_ne_count];
h8300_ne_count++;
return 0;
} else
return -ENODEV;
}
static int __init do_ne_probe(struct net_device *dev)
{
unsigned int base_addr = dev->base_addr;
if (base_addr > 0x1ff)
return ne_probe1(dev, base_addr);
else if (base_addr != 0)
return -ENXIO;
return -ENODEV;
}
static void cleanup_card(struct net_device *dev)
{
free_irq(dev->irq, dev);
release_region(dev->base_addr, NE_IO_EXTENT);
}
struct net_device * __init ne_probe(int unit)
{
struct net_device *dev = ____alloc_ei_netdev(0);
int err;
if (!dev)
return ERR_PTR(-ENOMEM);
if (init_dev(dev))
return ERR_PTR(-ENODEV);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
err = init_reg_offset(dev, dev->base_addr);
if (err)
goto out;
err = do_ne_probe(dev);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init ne_probe1(struct net_device *dev, int ioaddr)
{
int i;
unsigned char SA_prom[16];
int wordlength = 2;
const char *name = NULL;
int start_page, stop_page;
int reg0, ret;
static unsigned version_printed;
struct ei_device *ei_local = netdev_priv(dev);
unsigned char bus_width;
if (!request_region(ioaddr, NE_IO_EXTENT, DRV_NAME))
return -EBUSY;
reg0 = inb_p(ioaddr);
if (reg0 == 0xFF) {
ret = -ENODEV;
goto err_out;
}
{
int regd;
outb_p(E8390_NODMA+E8390_PAGE1+E8390_STOP, ioaddr + E8390_CMD);
regd = inb_p(ioaddr + EI_SHIFT(0x0d));
outb_p(0xff, ioaddr + EI_SHIFT(0x0d));
outb_p(E8390_NODMA+E8390_PAGE0, ioaddr + E8390_CMD);
inb_p(ioaddr + EN0_COUNTER0);
if (inb_p(ioaddr + EN0_COUNTER0) != 0) {
outb_p(reg0, ioaddr + EI_SHIFT(0));
outb_p(regd, ioaddr + EI_SHIFT(0x0d));
ret = -ENODEV;
goto err_out;
}
}
if (ei_debug && version_printed++ == 0)
printk(KERN_INFO "%s", version1);
printk(KERN_INFO "NE*000 ethercard probe at %08x:", ioaddr);
{
struct {unsigned char value, offset; } program_seq[] =
{
{E8390_NODMA+E8390_PAGE0+E8390_STOP, E8390_CMD},
{0x48, EN0_DCFG},
{0x00, EN0_RCNTLO},
{0x00, EN0_RCNTHI},
{0x00, EN0_IMR},
{0xFF, EN0_ISR},
{E8390_RXOFF, EN0_RXCR},
{E8390_TXOFF, EN0_TXCR},
{32, EN0_RCNTLO},
{0x00, EN0_RCNTHI},
{0x00, EN0_RSARLO},
{0x00, EN0_RSARHI},
{E8390_RREAD+E8390_START, E8390_CMD},
};
for (i = 0; i < ARRAY_SIZE(program_seq); i++)
outb_p(program_seq[i].value, ioaddr + program_seq[i].offset);
}
bus_width = *(volatile unsigned char *)ABWCR;
bus_width &= 1 << ((ioaddr >> 21) & 7);
ei_status.word16 = (bus_width == 0);
for(i = 0; i < 16 ; i++) {
SA_prom[i] = inb_p(ioaddr + NE_DATAPORT);
inb_p(ioaddr + NE_DATAPORT);
}
start_page = NESM_START_PG;
stop_page = NESM_STOP_PG;
if (bus_width)
wordlength = 1;
else
outb_p(0x49, ioaddr + EN0_DCFG);
name = (wordlength == 2) ? "NE2000" : "NE1000";
if (! dev->irq) {
printk(" failed to detect IRQ line.\n");
ret = -EAGAIN;
goto err_out;
}
ret = request_irq(dev->irq, __ei_interrupt, 0, name, dev);
if (ret) {
printk (" unable to get IRQ %d (errno=%d).\n", dev->irq, ret);
goto err_out;
}
dev->base_addr = ioaddr;
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = SA_prom[i];
printk(" %pM\n", dev->dev_addr);
printk("%s: %s found at %#x, using IRQ %d.\n",
dev->name, name, ioaddr, dev->irq);
ei_status.name = name;
ei_status.tx_start_page = start_page;
ei_status.stop_page = stop_page;
ei_status.word16 = (wordlength == 2);
ei_status.rx_start_page = start_page + TX_PAGES;
#ifdef PACKETBUF_MEMSIZE
ei_status.stop_page = ei_status.tx_start_page + PACKETBUF_MEMSIZE;
#endif
ei_status.reset_8390 = &ne_reset_8390;
ei_status.block_input = &ne_block_input;
ei_status.block_output = &ne_block_output;
ei_status.get_8390_hdr = &ne_get_8390_hdr;
ei_status.priv = 0;
dev->netdev_ops = &ne_netdev_ops;
__NS8390_init(dev, 0);
ret = register_netdev(dev);
if (ret)
goto out_irq;
return 0;
out_irq:
free_irq(dev->irq, dev);
err_out:
release_region(ioaddr, NE_IO_EXTENT);
return ret;
}
static int ne_open(struct net_device *dev)
{
__ei_open(dev);
return 0;
}
static int ne_close(struct net_device *dev)
{
if (ei_debug > 1)
printk(KERN_DEBUG "%s: Shutting down ethercard.\n", dev->name);
__ei_close(dev);
return 0;
}
static void ne_reset_8390(struct net_device *dev)
{
unsigned long reset_start_time = jiffies;
struct ei_device *ei_local = netdev_priv(dev);
if (ei_debug > 1)
printk(KERN_DEBUG "resetting the 8390 t=%ld...", jiffies);
outb(inb(NE_BASE + NE_RESET), NE_BASE + NE_RESET);
ei_status.txing = 0;
ei_status.dmaing = 0;
while ((inb_p(NE_BASE+EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies, reset_start_time + 2*HZ/100)) {
printk(KERN_WARNING "%s: ne_reset_8390() did not complete.\n", dev->name);
break;
}
outb_p(ENISR_RESET, NE_BASE + EN0_ISR);
}
static void ne_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
struct ei_device *ei_local = netdev_priv(dev);
if (ei_status.dmaing)
{
printk(KERN_EMERG "%s: DMAing conflict in ne_get_8390_hdr "
"[DMAstat:%d][irqlock:%d].\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, NE_BASE + NE_CMD);
outb_p(sizeof(struct e8390_pkt_hdr), NE_BASE + EN0_RCNTLO);
outb_p(0, NE_BASE + EN0_RCNTHI);
outb_p(0, NE_BASE + EN0_RSARLO);
outb_p(ring_page, NE_BASE + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, NE_BASE + NE_CMD);
if (ei_status.word16) {
int len;
unsigned short *p = (unsigned short *)hdr;
for (len = sizeof(struct e8390_pkt_hdr)>>1; len > 0; len--)
*p++ = inw(NE_BASE + NE_DATAPORT);
} else
insb(NE_BASE + NE_DATAPORT, hdr, sizeof(struct e8390_pkt_hdr));
outb_p(ENISR_RDC, NE_BASE + EN0_ISR);
ei_status.dmaing &= ~0x01;
le16_to_cpus(&hdr->count);
}
static void ne_block_input(struct net_device *dev, int count, struct sk_buff *skb, int ring_offset)
{
struct ei_device *ei_local = netdev_priv(dev);
#ifdef NE_SANITY_CHECK
int xfer_count = count;
#endif
char *buf = skb->data;
if (ei_status.dmaing)
{
printk(KERN_EMERG "%s: DMAing conflict in ne_block_input "
"[DMAstat:%d][irqlock:%d].\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, NE_BASE + NE_CMD);
outb_p(count & 0xff, NE_BASE + EN0_RCNTLO);
outb_p(count >> 8, NE_BASE + EN0_RCNTHI);
outb_p(ring_offset & 0xff, NE_BASE + EN0_RSARLO);
outb_p(ring_offset >> 8, NE_BASE + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, NE_BASE + NE_CMD);
if (ei_status.word16)
{
int len;
unsigned short *p = (unsigned short *)buf;
for (len = count>>1; len > 0; len--)
*p++ = inw(NE_BASE + NE_DATAPORT);
if (count & 0x01)
{
buf[count-1] = inb(NE_BASE + NE_DATAPORT);
#ifdef NE_SANITY_CHECK
xfer_count++;
#endif
}
} else {
insb(NE_BASE + NE_DATAPORT, buf, count);
}
#ifdef NE_SANITY_CHECK
if (ei_debug > 1)
{
int addr, tries = 20;
do {
int high = inb_p(NE_BASE + EN0_RSARHI);
int low = inb_p(NE_BASE + EN0_RSARLO);
addr = (high << 8) + low;
if (((ring_offset + xfer_count) & 0xff) == low)
break;
} while (--tries > 0);
if (tries <= 0)
printk(KERN_WARNING "%s: RX transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
dev->name, ring_offset + xfer_count, addr);
}
#endif
outb_p(ENISR_RDC, NE_BASE + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne_block_output(struct net_device *dev, int count,
const unsigned char *buf, const int start_page)
{
struct ei_device *ei_local = netdev_priv(dev);
unsigned long dma_start;
#ifdef NE_SANITY_CHECK
int retries = 0;
#endif
if (ei_status.word16 && (count & 0x01))
count++;
if (ei_status.dmaing)
{
printk(KERN_EMERG "%s: DMAing conflict in ne_block_output."
"[DMAstat:%d][irqlock:%d]\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_PAGE0+E8390_START+E8390_NODMA, NE_BASE + NE_CMD);
#ifdef NE_SANITY_CHECK
retry:
#endif
#ifdef NE8390_RW_BUGFIX
outb_p(0x42, NE_BASE + EN0_RCNTLO);
outb_p(0x00, NE_BASE + EN0_RCNTHI);
outb_p(0x42, NE_BASE + EN0_RSARLO);
outb_p(0x00, NE_BASE + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, NE_BASE + NE_CMD);
udelay(6);
#endif
outb_p(ENISR_RDC, NE_BASE + EN0_ISR);
outb_p(count & 0xff, NE_BASE + EN0_RCNTLO);
outb_p(count >> 8, NE_BASE + EN0_RCNTHI);
outb_p(0x00, NE_BASE + EN0_RSARLO);
outb_p(start_page, NE_BASE + EN0_RSARHI);
outb_p(E8390_RWRITE+E8390_START, NE_BASE + NE_CMD);
if (ei_status.word16) {
int len;
unsigned short *p = (unsigned short *)buf;
for (len = count>>1; len > 0; len--)
outw(*p++, NE_BASE + NE_DATAPORT);
} else {
outsb(NE_BASE + NE_DATAPORT, buf, count);
}
dma_start = jiffies;
#ifdef NE_SANITY_CHECK
if (ei_debug > 1)
{
int addr, tries = 20;
do {
int high = inb_p(NE_BASE + EN0_RSARHI);
int low = inb_p(NE_BASE + EN0_RSARLO);
addr = (high << 8) + low;
if ((start_page << 8) + count == addr)
break;
} while (--tries > 0);
if (tries <= 0)
{
printk(KERN_WARNING "%s: Tx packet transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
dev->name, (start_page << 8) + count, addr);
if (retries++ == 0)
goto retry;
}
}
#endif
while ((inb_p(NE_BASE + EN0_ISR) & ENISR_RDC) == 0)
if (time_after(jiffies, dma_start + 2*HZ/100)) {
printk(KERN_WARNING "%s: timeout waiting for Tx RDC.\n", dev->name);
ne_reset_8390(dev);
__NS8390_init(dev,1);
break;
}
outb_p(ENISR_RDC, NE_BASE + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
int init_module(void)
{
int this_dev, found = 0;
int err;
for (this_dev = 0; this_dev < MAX_NE_CARDS; this_dev++) {
struct net_device *dev = ____alloc_ei_netdev(0);
if (!dev)
break;
if (io[this_dev]) {
dev->irq = irq[this_dev];
dev->mem_end = bad[this_dev];
dev->base_addr = io[this_dev];
} else {
dev->base_addr = h8300_ne_base[this_dev];
dev->irq = h8300_ne_irq[this_dev];
}
err = init_reg_offset(dev, dev->base_addr);
if (!err) {
if (do_ne_probe(dev) == 0) {
dev_ne[found++] = dev;
continue;
}
}
free_netdev(dev);
if (found)
break;
if (io[this_dev] != 0)
printk(KERN_WARNING "ne.c: No NE*000 card found at i/o = %#x\n", dev->base_addr);
else
printk(KERN_NOTICE "ne.c: You must supply \"io=0xNNN\" value(s) for ISA cards.\n");
return -ENXIO;
}
if (found)
return 0;
return -ENODEV;
}
void cleanup_module(void)
{
int this_dev;
for (this_dev = 0; this_dev < MAX_NE_CARDS; this_dev++) {
struct net_device *dev = dev_ne[this_dev];
if (dev) {
unregister_netdev(dev);
cleanup_card(dev);
free_netdev(dev);
}
}
}
