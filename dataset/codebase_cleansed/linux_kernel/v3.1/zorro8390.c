static void zorro8390_reset_8390(struct net_device *dev)
{
unsigned long reset_start_time = jiffies;
if (ei_debug > 1)
netdev_dbg(dev, "resetting - t=%ld...\n", jiffies);
z_writeb(z_readb(NE_BASE + NE_RESET), NE_BASE + NE_RESET);
ei_status.txing = 0;
ei_status.dmaing = 0;
while ((z_readb(NE_BASE + NE_EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies, reset_start_time + 2 * HZ / 100)) {
netdev_warn(dev, "%s: did not complete\n", __func__);
break;
}
z_writeb(ENISR_RESET, NE_BASE + NE_EN0_ISR);
}
static void zorro8390_get_8390_hdr(struct net_device *dev,
struct e8390_pkt_hdr *hdr, int ring_page)
{
int nic_base = dev->base_addr;
int cnt;
short *ptrs;
if (ei_status.dmaing) {
netdev_err(dev, "%s: DMAing conflict [DMAstat:%d][irqlock:%d]\n",
__func__, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
z_writeb(E8390_NODMA + E8390_PAGE0 + E8390_START, nic_base + NE_CMD);
z_writeb(ENISR_RDC, nic_base + NE_EN0_ISR);
z_writeb(sizeof(struct e8390_pkt_hdr), nic_base + NE_EN0_RCNTLO);
z_writeb(0, nic_base + NE_EN0_RCNTHI);
z_writeb(0, nic_base + NE_EN0_RSARLO);
z_writeb(ring_page, nic_base + NE_EN0_RSARHI);
z_writeb(E8390_RREAD+E8390_START, nic_base + NE_CMD);
ptrs = (short *)hdr;
for (cnt = 0; cnt < sizeof(struct e8390_pkt_hdr) >> 1; cnt++)
*ptrs++ = z_readw(NE_BASE + NE_DATAPORT);
z_writeb(ENISR_RDC, nic_base + NE_EN0_ISR);
hdr->count = WORDSWAP(hdr->count);
ei_status.dmaing &= ~0x01;
}
static void zorro8390_block_input(struct net_device *dev, int count,
struct sk_buff *skb, int ring_offset)
{
int nic_base = dev->base_addr;
char *buf = skb->data;
short *ptrs;
int cnt;
if (ei_status.dmaing) {
netdev_err(dev, "%s: DMAing conflict [DMAstat:%d][irqlock:%d]\n",
__func__, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
z_writeb(E8390_NODMA + E8390_PAGE0 + E8390_START, nic_base + NE_CMD);
z_writeb(ENISR_RDC, nic_base + NE_EN0_ISR);
z_writeb(count & 0xff, nic_base + NE_EN0_RCNTLO);
z_writeb(count >> 8, nic_base + NE_EN0_RCNTHI);
z_writeb(ring_offset & 0xff, nic_base + NE_EN0_RSARLO);
z_writeb(ring_offset >> 8, nic_base + NE_EN0_RSARHI);
z_writeb(E8390_RREAD+E8390_START, nic_base + NE_CMD);
ptrs = (short *)buf;
for (cnt = 0; cnt < count >> 1; cnt++)
*ptrs++ = z_readw(NE_BASE + NE_DATAPORT);
if (count & 0x01)
buf[count - 1] = z_readb(NE_BASE + NE_DATAPORT);
z_writeb(ENISR_RDC, nic_base + NE_EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void zorro8390_block_output(struct net_device *dev, int count,
const unsigned char *buf,
const int start_page)
{
int nic_base = NE_BASE;
unsigned long dma_start;
short *ptrs;
int cnt;
if (count & 0x01)
count++;
if (ei_status.dmaing) {
netdev_err(dev, "%s: DMAing conflict [DMAstat:%d][irqlock:%d]\n",
__func__, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
z_writeb(E8390_PAGE0+E8390_START+E8390_NODMA, nic_base + NE_CMD);
z_writeb(ENISR_RDC, nic_base + NE_EN0_ISR);
z_writeb(count & 0xff, nic_base + NE_EN0_RCNTLO);
z_writeb(count >> 8, nic_base + NE_EN0_RCNTHI);
z_writeb(0x00, nic_base + NE_EN0_RSARLO);
z_writeb(start_page, nic_base + NE_EN0_RSARHI);
z_writeb(E8390_RWRITE + E8390_START, nic_base + NE_CMD);
ptrs = (short *)buf;
for (cnt = 0; cnt < count >> 1; cnt++)
z_writew(*ptrs++, NE_BASE + NE_DATAPORT);
dma_start = jiffies;
while ((z_readb(NE_BASE + NE_EN0_ISR) & ENISR_RDC) == 0)
if (time_after(jiffies, dma_start + 2 * HZ / 100)) {
netdev_err(dev, "timeout waiting for Tx RDC\n");
zorro8390_reset_8390(dev);
__NS8390_init(dev, 1);
break;
}
z_writeb(ENISR_RDC, nic_base + NE_EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static int zorro8390_open(struct net_device *dev)
{
__ei_open(dev);
return 0;
}
static int zorro8390_close(struct net_device *dev)
{
if (ei_debug > 1)
netdev_dbg(dev, "Shutting down ethercard\n");
__ei_close(dev);
return 0;
}
static void __devexit zorro8390_remove_one(struct zorro_dev *z)
{
struct net_device *dev = zorro_get_drvdata(z);
unregister_netdev(dev);
free_irq(IRQ_AMIGA_PORTS, dev);
release_mem_region(ZTWO_PADDR(dev->base_addr), NE_IO_EXTENT * 2);
free_netdev(dev);
}
static int __devinit zorro8390_init(struct net_device *dev,
unsigned long board, const char *name,
unsigned long ioaddr)
{
int i;
int err;
unsigned char SA_prom[32];
int start_page, stop_page;
static u32 zorro8390_offsets[16] = {
0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e,
0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
};
{
unsigned long reset_start_time = jiffies;
z_writeb(z_readb(ioaddr + NE_RESET), ioaddr + NE_RESET);
while ((z_readb(ioaddr + NE_EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies,
reset_start_time + 2 * HZ / 100)) {
netdev_warn(dev, "not found (no reset ack)\n");
return -ENODEV;
}
z_writeb(0xff, ioaddr + NE_EN0_ISR);
}
{
static const struct {
u32 value;
u32 offset;
} program_seq[] = {
{E8390_NODMA + E8390_PAGE0 + E8390_STOP, NE_CMD},
{0x48, NE_EN0_DCFG},
{0x00, NE_EN0_RCNTLO},
{0x00, NE_EN0_RCNTHI},
{0x00, NE_EN0_IMR},
{0xFF, NE_EN0_ISR},
{E8390_RXOFF, NE_EN0_RXCR},
{E8390_TXOFF, NE_EN0_TXCR},
{32, NE_EN0_RCNTLO},
{0x00, NE_EN0_RCNTHI},
{0x00, NE_EN0_RSARLO},
{0x00, NE_EN0_RSARHI},
{E8390_RREAD + E8390_START, NE_CMD},
};
for (i = 0; i < ARRAY_SIZE(program_seq); i++)
z_writeb(program_seq[i].value,
ioaddr + program_seq[i].offset);
}
for (i = 0; i < 16; i++) {
SA_prom[i] = z_readb(ioaddr + NE_DATAPORT);
(void)z_readb(ioaddr + NE_DATAPORT);
}
z_writeb(0x49, ioaddr + NE_EN0_DCFG);
start_page = NESM_START_PG;
stop_page = NESM_STOP_PG;
dev->base_addr = ioaddr;
dev->irq = IRQ_AMIGA_PORTS;
i = request_irq(IRQ_AMIGA_PORTS, __ei_interrupt,
IRQF_SHARED, DRV_NAME, dev);
if (i)
return i;
for (i = 0; i < ETHER_ADDR_LEN; i++)
dev->dev_addr[i] = SA_prom[i];
pr_debug("Found ethernet address: %pM\n", dev->dev_addr);
ei_status.name = name;
ei_status.tx_start_page = start_page;
ei_status.stop_page = stop_page;
ei_status.word16 = 1;
ei_status.rx_start_page = start_page + TX_PAGES;
ei_status.reset_8390 = zorro8390_reset_8390;
ei_status.block_input = zorro8390_block_input;
ei_status.block_output = zorro8390_block_output;
ei_status.get_8390_hdr = zorro8390_get_8390_hdr;
ei_status.reg_offset = zorro8390_offsets;
dev->netdev_ops = &zorro8390_netdev_ops;
__NS8390_init(dev, 0);
err = register_netdev(dev);
if (err) {
free_irq(IRQ_AMIGA_PORTS, dev);
return err;
}
netdev_info(dev, "%s at 0x%08lx, Ethernet Address %pM\n",
name, board, dev->dev_addr);
return 0;
}
static int __devinit zorro8390_init_one(struct zorro_dev *z,
const struct zorro_device_id *ent)
{
struct net_device *dev;
unsigned long board, ioaddr;
int err, i;
for (i = ARRAY_SIZE(cards) - 1; i >= 0; i--)
if (z->id == cards[i].id)
break;
if (i < 0)
return -ENODEV;
board = z->resource.start;
ioaddr = board + cards[i].offset;
dev = ____alloc_ei_netdev(0);
if (!dev)
return -ENOMEM;
if (!request_mem_region(ioaddr, NE_IO_EXTENT * 2, DRV_NAME)) {
free_netdev(dev);
return -EBUSY;
}
err = zorro8390_init(dev, board, cards[i].name, ZTWO_VADDR(ioaddr));
if (err) {
release_mem_region(ioaddr, NE_IO_EXTENT * 2);
free_netdev(dev);
return err;
}
zorro_set_drvdata(z, dev);
return 0;
}
static int __init zorro8390_init_module(void)
{
return zorro_register_driver(&zorro8390_driver);
}
static void __exit zorro8390_cleanup_module(void)
{
zorro_unregister_driver(&zorro8390_driver);
}
