static inline u32 NE_PTR(u32 addr)
{
if (addr & 1)
return addr - 1 + NE2000_ODDOFFSET;
return addr;
}
static inline u32 NE_DATA_PTR(u32 addr)
{
return addr;
}
void ei_outb(u32 val, u32 addr)
{
NE2000_BYTE *rp;
rp = (NE2000_BYTE *) NE_PTR(addr);
*rp = RSWAP(val);
}
u8 ei_inb(u32 addr)
{
NE2000_BYTE *rp, val;
rp = (NE2000_BYTE *) NE_PTR(addr);
val = *rp;
return (u8) (RSWAP(val) & 0xff);
}
void ei_insb(u32 addr, void *vbuf, int len)
{
NE2000_BYTE *rp, val;
u8 *buf;
buf = (u8 *) vbuf;
rp = (NE2000_BYTE *) NE_DATA_PTR(addr);
for (; (len > 0); len--) {
val = *rp;
*buf++ = RSWAP(val);
}
}
void ei_insw(u32 addr, void *vbuf, int len)
{
volatile u16 *rp;
u16 w, *buf;
buf = (u16 *) vbuf;
rp = (volatile u16 *) NE_DATA_PTR(addr);
for (; (len > 0); len--) {
w = *rp;
*buf++ = BSWAP(w);
}
}
void ei_outsb(u32 addr, const void *vbuf, int len)
{
NE2000_BYTE *rp, val;
u8 *buf;
buf = (u8 *) vbuf;
rp = (NE2000_BYTE *) NE_DATA_PTR(addr);
for (; (len > 0); len--) {
val = *buf++;
*rp = RSWAP(val);
}
}
void ei_outsw(u32 addr, const void *vbuf, int len)
{
volatile u16 *rp;
u16 w, *buf;
buf = (u16 *) vbuf;
rp = (volatile u16 *) NE_DATA_PTR(addr);
for (; (len > 0); len--) {
w = *buf++;
*rp = BSWAP(w);
}
}
static void mcf8390_reset_8390(struct net_device *dev)
{
unsigned long reset_start_time = jiffies;
u32 addr = dev->base_addr;
struct ei_device *ei_local = netdev_priv(dev);
netif_dbg(ei_local, hw, dev, "resetting the 8390 t=%ld...\n", jiffies);
ei_outb(ei_inb(addr + NE_RESET), addr + NE_RESET);
ei_status.txing = 0;
ei_status.dmaing = 0;
while ((ei_inb(addr + NE_EN0_ISR) & ENISR_RESET) == 0) {
if (time_after(jiffies, reset_start_time + 2 * HZ / 100)) {
netdev_warn(dev, "%s: did not complete\n", __func__);
break;
}
}
ei_outb(ENISR_RESET, addr + NE_EN0_ISR);
}
static void mcf8390_dmaing_err(const char *func, struct net_device *dev,
struct ei_device *ei_local)
{
netdev_err(dev, "%s: DMAing conflict [DMAstat:%d][irqlock:%d]\n",
func, ei_local->dmaing, ei_local->irqlock);
}
static void mcf8390_get_8390_hdr(struct net_device *dev,
struct e8390_pkt_hdr *hdr, int ring_page)
{
struct ei_device *ei_local = netdev_priv(dev);
u32 addr = dev->base_addr;
if (ei_local->dmaing) {
mcf8390_dmaing_err(__func__, dev, ei_local);
return;
}
ei_local->dmaing |= 0x01;
ei_outb(E8390_NODMA + E8390_PAGE0 + E8390_START, addr + NE_CMD);
ei_outb(ENISR_RDC, addr + NE_EN0_ISR);
ei_outb(sizeof(struct e8390_pkt_hdr), addr + NE_EN0_RCNTLO);
ei_outb(0, addr + NE_EN0_RCNTHI);
ei_outb(0, addr + NE_EN0_RSARLO);
ei_outb(ring_page, addr + NE_EN0_RSARHI);
ei_outb(E8390_RREAD + E8390_START, addr + NE_CMD);
ei_insw(addr + NE_DATAPORT, hdr, sizeof(struct e8390_pkt_hdr) >> 1);
outb(ENISR_RDC, addr + NE_EN0_ISR);
ei_local->dmaing &= ~0x01;
hdr->count = cpu_to_le16(hdr->count);
}
static void mcf8390_block_input(struct net_device *dev, int count,
struct sk_buff *skb, int ring_offset)
{
struct ei_device *ei_local = netdev_priv(dev);
u32 addr = dev->base_addr;
char *buf = skb->data;
if (ei_local->dmaing) {
mcf8390_dmaing_err(__func__, dev, ei_local);
return;
}
ei_local->dmaing |= 0x01;
ei_outb(E8390_NODMA + E8390_PAGE0 + E8390_START, addr + NE_CMD);
ei_outb(ENISR_RDC, addr + NE_EN0_ISR);
ei_outb(count & 0xff, addr + NE_EN0_RCNTLO);
ei_outb(count >> 8, addr + NE_EN0_RCNTHI);
ei_outb(ring_offset & 0xff, addr + NE_EN0_RSARLO);
ei_outb(ring_offset >> 8, addr + NE_EN0_RSARHI);
ei_outb(E8390_RREAD + E8390_START, addr + NE_CMD);
ei_insw(addr + NE_DATAPORT, buf, count >> 1);
if (count & 1)
buf[count - 1] = ei_inb(addr + NE_DATAPORT);
ei_outb(ENISR_RDC, addr + NE_EN0_ISR);
ei_local->dmaing &= ~0x01;
}
static void mcf8390_block_output(struct net_device *dev, int count,
const unsigned char *buf,
const int start_page)
{
struct ei_device *ei_local = netdev_priv(dev);
u32 addr = dev->base_addr;
unsigned long dma_start;
if (count & 0x1)
count++;
if (ei_local->dmaing) {
mcf8390_dmaing_err(__func__, dev, ei_local);
return;
}
ei_local->dmaing |= 0x01;
ei_outb(E8390_PAGE0 + E8390_START + E8390_NODMA, addr + NE_CMD);
ei_outb(ENISR_RDC, addr + NE_EN0_ISR);
ei_outb(count & 0xff, addr + NE_EN0_RCNTLO);
ei_outb(count >> 8, addr + NE_EN0_RCNTHI);
ei_outb(0x00, addr + NE_EN0_RSARLO);
ei_outb(start_page, addr + NE_EN0_RSARHI);
ei_outb(E8390_RWRITE + E8390_START, addr + NE_CMD);
ei_outsw(addr + NE_DATAPORT, buf, count >> 1);
dma_start = jiffies;
while ((ei_inb(addr + NE_EN0_ISR) & ENISR_RDC) == 0) {
if (time_after(jiffies, dma_start + 2 * HZ / 100)) {
netdev_warn(dev, "timeout waiting for Tx RDC\n");
mcf8390_reset_8390(dev);
__NS8390_init(dev, 1);
break;
}
}
ei_outb(ENISR_RDC, addr + NE_EN0_ISR);
ei_local->dmaing &= ~0x01;
}
static int mcf8390_init(struct net_device *dev)
{
static u32 offsets[] = {
0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
};
struct ei_device *ei_local = netdev_priv(dev);
unsigned char SA_prom[32];
u32 addr = dev->base_addr;
int start_page, stop_page;
int i, ret;
mcf8390_reset_8390(dev);
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
for (i = 0; i < ARRAY_SIZE(program_seq); i++) {
ei_outb(program_seq[i].value,
addr + program_seq[i].offset);
}
}
for (i = 0; i < 16; i++) {
SA_prom[i] = ei_inb(addr + NE_DATAPORT);
ei_inb(addr + NE_DATAPORT);
}
ei_outb(0x49, addr + NE_EN0_DCFG);
start_page = NESM_START_PG;
stop_page = NESM_STOP_PG;
ret = request_irq(dev->irq, __ei_interrupt, 0, dev->name, dev);
if (ret)
return ret;
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = SA_prom[i];
netdev_dbg(dev, "Found ethernet address: %pM\n", dev->dev_addr);
ei_local->name = "mcf8390";
ei_local->tx_start_page = start_page;
ei_local->stop_page = stop_page;
ei_local->word16 = 1;
ei_local->rx_start_page = start_page + TX_PAGES;
ei_local->reset_8390 = mcf8390_reset_8390;
ei_local->block_input = mcf8390_block_input;
ei_local->block_output = mcf8390_block_output;
ei_local->get_8390_hdr = mcf8390_get_8390_hdr;
ei_local->reg_offset = offsets;
dev->netdev_ops = &mcf8390_netdev_ops;
__NS8390_init(dev, 0);
ret = register_netdev(dev);
if (ret) {
free_irq(dev->irq, dev);
return ret;
}
netdev_info(dev, "addr=0x%08x irq=%d, Ethernet Address %pM\n",
addr, dev->irq, dev->dev_addr);
return 0;
}
static int mcf8390_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct ei_device *ei_local;
struct resource *mem, *irq;
resource_size_t msize;
int ret;
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (irq == NULL) {
dev_err(&pdev->dev, "no IRQ specified?\n");
return -ENXIO;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem == NULL) {
dev_err(&pdev->dev, "no memory address specified?\n");
return -ENXIO;
}
msize = resource_size(mem);
if (!request_mem_region(mem->start, msize, pdev->name))
return -EBUSY;
dev = ____alloc_ei_netdev(0);
if (dev == NULL) {
release_mem_region(mem->start, msize);
return -ENOMEM;
}
SET_NETDEV_DEV(dev, &pdev->dev);
platform_set_drvdata(pdev, dev);
ei_local = netdev_priv(dev);
ei_local->msg_enable = mcf8390_msg_enable;
dev->irq = irq->start;
dev->base_addr = mem->start;
ret = mcf8390_init(dev);
if (ret) {
release_mem_region(mem->start, msize);
free_netdev(dev);
return ret;
}
return 0;
}
static int mcf8390_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct resource *mem;
unregister_netdev(dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem)
release_mem_region(mem->start, resource_size(mem));
free_netdev(dev);
return 0;
}
