static void cleanup_card(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA32_NIC_OFFSET;
release_region(ioaddr, ULTRA32_IO_EXTENT);
iounmap(ei_status.mem);
}
struct net_device * __init ultra32_probe(int unit)
{
struct net_device *dev;
int base;
int irq;
int err = -ENODEV;
if (!EISA_bus)
return ERR_PTR(-ENODEV);
dev = alloc_ei_netdev();
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
}
irq = dev->irq;
for (base = 0x1000 + ULTRA32_BASE; base < 0x9000; base += 0x1000) {
if (ultra32_probe1(dev, base) == 0)
break;
dev->irq = irq;
}
if (base >= 0x9000)
goto out;
err = register_netdev(dev);
if (err)
goto out1;
return dev;
out1:
cleanup_card(dev);
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init ultra32_probe1(struct net_device *dev, int ioaddr)
{
int i, edge, media, retval;
int checksum = 0;
const char *model_name;
static unsigned version_printed;
unsigned char idreg;
unsigned char reg4;
const char *ifmap[] = {"UTP No Link", "", "UTP/AUI", "UTP/BNC"};
if (!request_region(ioaddr, ULTRA32_IO_EXTENT, DRV_NAME))
return -EBUSY;
if (inb(ioaddr + ULTRA32_IDPORT) == 0xff ||
inl(ioaddr + ULTRA32_IDPORT) != ULTRA32_ID) {
retval = -ENODEV;
goto out;
}
media = inb(ioaddr + ULTRA32_CFG7) & 0x03;
edge = inb(ioaddr + ULTRA32_CFG5) & 0x08;
printk("SMC Ultra32 in EISA Slot %d, Media: %s, %s IRQs.\n",
ioaddr >> 12, ifmap[media],
(edge ? "Edge Triggered" : "Level Sensitive"));
idreg = inb(ioaddr + 7);
reg4 = inb(ioaddr + 4) & 0x7f;
if ((idreg & 0xf0) != 0x20) {
retval = -ENODEV;
goto out;
}
outb(reg4, ioaddr + 4);
for (i = 0; i < 8; i++)
checksum += inb(ioaddr + 8 + i);
if ((checksum & 0xff) != 0xff) {
retval = -ENODEV;
goto out;
}
if (ei_debug && version_printed++ == 0)
printk(version);
model_name = "SMC Ultra32";
for (i = 0; i < 6; i++)
dev->dev_addr[i] = inb(ioaddr + 8 + i);
printk("%s: %s at 0x%X, %pM",
dev->name, model_name, ioaddr, dev->dev_addr);
outb(0x80 | reg4, ioaddr + 4);
outb(0x80 | inb(ioaddr + 0x0c), ioaddr + 0x0c);
outb(0x00, ioaddr + 0x0b);
outb(reg4, ioaddr + 4);
if ((inb(ioaddr + ULTRA32_CFG5) & 0x40) == 0) {
printk("\nsmc-ultra32: Card RAM is disabled! "
"Run EISA config utility.\n");
retval = -ENODEV;
goto out;
}
if ((inb(ioaddr + ULTRA32_CFG2) & 0x04) == 0)
printk("\nsmc-ultra32: Ignoring Bus-Master enable bit. "
"Run EISA config utility.\n");
if (dev->irq < 2) {
unsigned char irqmap[] = {0, 9, 3, 5, 7, 10, 11, 15};
int irq = irqmap[inb(ioaddr + ULTRA32_CFG5) & 0x07];
if (irq == 0) {
printk(", failed to detect IRQ line.\n");
retval = -EAGAIN;
goto out;
}
dev->irq = irq;
}
dev->base_addr = ioaddr + ULTRA32_NIC_OFFSET;
ei_status.reg0 = inb(ioaddr + ULTRA32_CFG3) & 0xfc;
dev->mem_start = 0xc0000 + ((ei_status.reg0 & 0x7c) << 11);
ei_status.name = model_name;
ei_status.word16 = 1;
ei_status.tx_start_page = 0;
ei_status.rx_start_page = TX_PAGES;
ei_status.stop_page = 128;
ei_status.mem = ioremap(dev->mem_start, 0x2000);
if (!ei_status.mem) {
printk(", failed to ioremap.\n");
retval = -ENOMEM;
goto out;
}
dev->mem_end = dev->mem_start + 0x1fff;
printk(", IRQ %d, 32KB memory, 8KB window at 0x%lx-0x%lx.\n",
dev->irq, dev->mem_start, dev->mem_end);
ei_status.block_input = &ultra32_block_input;
ei_status.block_output = &ultra32_block_output;
ei_status.get_8390_hdr = &ultra32_get_8390_hdr;
ei_status.reset_8390 = &ultra32_reset_8390;
dev->netdev_ops = &ultra32_netdev_ops;
NS8390_init(dev, 0);
return 0;
out:
release_region(ioaddr, ULTRA32_IO_EXTENT);
return retval;
}
static int ultra32_open(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA32_NIC_OFFSET;
int irq_flags = (inb(ioaddr + ULTRA32_CFG5) & 0x08) ? 0 : IRQF_SHARED;
int retval;
retval = request_irq(dev->irq, ei_interrupt, irq_flags, dev->name, dev);
if (retval)
return retval;
outb(ULTRA32_MEMENB, ioaddr);
outb(0x80, ioaddr + ULTRA32_CFG6);
outb(0x84, ioaddr + 5);
outb(0x01, ioaddr + 6);
outb_p(E8390_NODMA+E8390_PAGE0, dev->base_addr);
outb(0xff, dev->base_addr + EN0_ERWCNT);
ei_open(dev);
return 0;
}
static int ultra32_close(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA32_NIC_OFFSET;
netif_stop_queue(dev);
if (ei_debug > 1)
printk("%s: Shutting down ethercard.\n", dev->name);
outb(0x00, ioaddr + ULTRA32_CFG6);
outb(0x00, ioaddr + 6);
free_irq(dev->irq, dev);
NS8390_init(dev, 0);
return 0;
}
static void ultra32_reset_8390(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA32_NIC_OFFSET;
outb(ULTRA32_RESET, ioaddr);
if (ei_debug > 1) printk("resetting Ultra32, t=%ld...", jiffies);
ei_status.txing = 0;
outb(ULTRA32_MEMENB, ioaddr);
outb(0x80, ioaddr + ULTRA32_CFG6);
outb(0x84, ioaddr + 5);
outb(0x01, ioaddr + 6);
if (ei_debug > 1) printk("reset done\n");
}
static void ultra32_get_8390_hdr(struct net_device *dev,
struct e8390_pkt_hdr *hdr,
int ring_page)
{
void __iomem *hdr_start = ei_status.mem + ((ring_page & 0x1f) << 8);
unsigned int RamReg = dev->base_addr - ULTRA32_NIC_OFFSET + ULTRA32_CFG3;
outb(ei_status.reg0 | ((ring_page & 0x60) >> 5), RamReg);
#ifdef __BIG_ENDIAN
memcpy_fromio(hdr, hdr_start, sizeof(struct e8390_pkt_hdr));
hdr->count = le16_to_cpu(hdr->count);
#else
((unsigned int*)hdr)[0] = readl(hdr_start);
#endif
}
static void ultra32_block_input(struct net_device *dev,
int count,
struct sk_buff *skb,
int ring_offset)
{
void __iomem *xfer_start = ei_status.mem + (ring_offset & 0x1fff);
unsigned int RamReg = dev->base_addr - ULTRA32_NIC_OFFSET + ULTRA32_CFG3;
if ((ring_offset & ~0x1fff) != ((ring_offset + count - 1) & ~0x1fff)) {
int semi_count = 8192 - (ring_offset & 0x1FFF);
memcpy_fromio(skb->data, xfer_start, semi_count);
count -= semi_count;
if (ring_offset < 96*256) {
ring_offset += semi_count;
outb(ei_status.reg0 | ((ring_offset & 0x6000) >> 13), RamReg);
memcpy_fromio(skb->data + semi_count, ei_status.mem, count);
} else {
outb(ei_status.reg0, RamReg);
memcpy_fromio(skb->data + semi_count, ei_status.mem + TX_PAGES * 256, count);
}
} else {
memcpy_fromio(skb->data, xfer_start, count);
}
}
static void ultra32_block_output(struct net_device *dev,
int count,
const unsigned char *buf,
int start_page)
{
void __iomem *xfer_start = ei_status.mem + (start_page<<8);
unsigned int RamReg = dev->base_addr - ULTRA32_NIC_OFFSET + ULTRA32_CFG3;
outb(ei_status.reg0, RamReg);
memcpy_toio(xfer_start, buf, count);
}
int __init init_module(void)
{
int this_dev, found = 0;
for (this_dev = 0; this_dev < MAX_ULTRA32_CARDS; this_dev++) {
struct net_device *dev = ultra32_probe(-1);
if (IS_ERR(dev))
break;
dev_ultra[found++] = dev;
}
if (found)
return 0;
printk(KERN_WARNING "smc-ultra32.c: No SMC Ultra32 found.\n");
return -ENXIO;
}
void __exit cleanup_module(void)
{
int this_dev;
for (this_dev = 0; this_dev < MAX_ULTRA32_CARDS; this_dev++) {
struct net_device *dev = dev_ultra[this_dev];
if (dev) {
unregister_netdev(dev);
cleanup_card(dev);
free_netdev(dev);
}
}
}
