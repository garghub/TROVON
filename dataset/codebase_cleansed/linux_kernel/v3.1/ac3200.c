static int __init do_ac3200_probe(struct net_device *dev)
{
unsigned short ioaddr = dev->base_addr;
int irq = dev->irq;
int mem_start = dev->mem_start;
if (ioaddr > 0x1ff)
return ac_probe1(ioaddr, dev);
else if (ioaddr > 0)
return -ENXIO;
if ( ! EISA_bus)
return -ENXIO;
for (ioaddr = 0x1000; ioaddr < 0x9000; ioaddr += 0x1000) {
if (ac_probe1(ioaddr, dev) == 0)
return 0;
dev->irq = irq;
dev->mem_start = mem_start;
}
return -ENODEV;
}
struct net_device * __init ac3200_probe(int unit)
{
struct net_device *dev = alloc_ei_netdev();
int err;
if (!dev)
return ERR_PTR(-ENOMEM);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
err = do_ac3200_probe(dev);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init ac_probe1(int ioaddr, struct net_device *dev)
{
int i, retval;
if (!request_region(ioaddr, AC_IO_EXTENT, DRV_NAME))
return -EBUSY;
if (inb_p(ioaddr + AC_ID_PORT) == 0xff) {
retval = -ENODEV;
goto out;
}
if (inl(ioaddr + AC_ID_PORT) != AC_EISA_ID) {
retval = -ENODEV;
goto out;
}
#ifndef final_version
printk(KERN_DEBUG "AC3200 ethercard configuration register is %#02x,"
" EISA ID %02x %02x %02x %02x.\n", inb(ioaddr + AC_CONFIG),
inb(ioaddr + AC_ID_PORT + 0), inb(ioaddr + AC_ID_PORT + 1),
inb(ioaddr + AC_ID_PORT + 2), inb(ioaddr + AC_ID_PORT + 3));
#endif
for (i = 0; i < 6; i++)
dev->dev_addr[i] = inb(ioaddr + AC_SA_PROM + i);
printk(KERN_DEBUG "AC3200 in EISA slot %d, node %pM",
ioaddr/0x1000, dev->dev_addr);
#if 0
if (inb(ioaddr + AC_SA_PROM + 0) != AC_ADDR0
|| inb(ioaddr + AC_SA_PROM + 1) != AC_ADDR1
|| inb(ioaddr + AC_SA_PROM + 2) != AC_ADDR2 ) {
printk(", not found (invalid prefix).\n");
retval = -ENODEV;
goto out;
}
#endif
if (dev->irq == 0) {
dev->irq = config2irq(inb(ioaddr + AC_CONFIG));
printk(", using");
} else {
dev->irq = irq_canonicalize(dev->irq);
printk(", assigning");
}
retval = request_irq(dev->irq, ei_interrupt, 0, DRV_NAME, dev);
if (retval) {
printk (" nothing! Unable to get IRQ %d.\n", dev->irq);
goto out;
}
printk(" IRQ %d, %s port\n", dev->irq, port_name[dev->if_port]);
dev->base_addr = ioaddr;
#ifdef notyet
if (dev->mem_start) {
for (i = 0; i < 7; i++)
if (addrmap[i] == dev->mem_start)
break;
if (i >= 7)
i = 0;
outb((inb(ioaddr + AC_CONFIG) & ~7) | i, ioaddr + AC_CONFIG);
}
#endif
dev->if_port = inb(ioaddr + AC_CONFIG) >> 6;
dev->mem_start = config2mem(inb(ioaddr + AC_CONFIG));
printk("%s: AC3200 at %#3x with %dkB memory at physical address %#lx.\n",
dev->name, ioaddr, AC_STOP_PG/4, dev->mem_start);
ei_status.mem = ioremap(dev->mem_start, AC_STOP_PG*0x100);
if (!ei_status.mem) {
printk(KERN_ERR "ac3200.c: Unable to remap card memory above 1MB !!\n");
printk(KERN_ERR "ac3200.c: Try using EISA SCU to set memory below 1MB.\n");
printk(KERN_ERR "ac3200.c: Driver NOT installed.\n");
retval = -EINVAL;
goto out1;
}
printk("ac3200.c: remapped %dkB card memory to virtual address %p\n",
AC_STOP_PG/4, ei_status.mem);
dev->mem_start = (unsigned long)ei_status.mem;
dev->mem_end = dev->mem_start + (AC_STOP_PG - AC_START_PG)*256;
ei_status.name = "AC3200";
ei_status.tx_start_page = AC_START_PG;
ei_status.rx_start_page = AC_START_PG + TX_PAGES;
ei_status.stop_page = AC_STOP_PG;
ei_status.word16 = 1;
if (ei_debug > 0)
printk(version);
ei_status.reset_8390 = &ac_reset_8390;
ei_status.block_input = &ac_block_input;
ei_status.block_output = &ac_block_output;
ei_status.get_8390_hdr = &ac_get_8390_hdr;
dev->netdev_ops = &ac_netdev_ops;
NS8390_init(dev, 0);
retval = register_netdev(dev);
if (retval)
goto out2;
return 0;
out2:
if (ei_status.reg0)
iounmap(ei_status.mem);
out1:
free_irq(dev->irq, dev);
out:
release_region(ioaddr, AC_IO_EXTENT);
return retval;
}
static int ac_open(struct net_device *dev)
{
#ifdef notyet
int ioaddr = dev->base_addr;
#endif
ei_open(dev);
return 0;
}
static void ac_reset_8390(struct net_device *dev)
{
ushort ioaddr = dev->base_addr;
outb(AC_RESET, ioaddr + AC_RESET_PORT);
if (ei_debug > 1) printk("resetting AC3200, t=%ld...", jiffies);
ei_status.txing = 0;
outb(AC_ENABLE, ioaddr + AC_RESET_PORT);
if (ei_debug > 1) printk("reset done\n");
}
static void
ac_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
void __iomem *hdr_start = ei_status.mem + ((ring_page - AC_START_PG)<<8);
memcpy_fromio(hdr, hdr_start, sizeof(struct e8390_pkt_hdr));
}
static void ac_block_input(struct net_device *dev, int count, struct sk_buff *skb,
int ring_offset)
{
void __iomem *start = ei_status.mem + ring_offset - AC_START_PG*256;
if (ring_offset + count > AC_STOP_PG*256) {
int semi_count = AC_STOP_PG*256 - ring_offset;
memcpy_fromio(skb->data, start, semi_count);
count -= semi_count;
memcpy_fromio(skb->data + semi_count,
ei_status.mem + TX_PAGES*256, count);
} else {
memcpy_fromio(skb->data, start, count);
}
}
static void ac_block_output(struct net_device *dev, int count,
const unsigned char *buf, int start_page)
{
void __iomem *shmem = ei_status.mem + ((start_page - AC_START_PG)<<8);
memcpy_toio(shmem, buf, count);
}
static int ac_close_card(struct net_device *dev)
{
if (ei_debug > 1)
printk("%s: Shutting down ethercard.\n", dev->name);
#ifdef notyet
outb(0x00, ioaddr + 6);
free_irq(dev->irq, dev);
#endif
ei_close(dev);
return 0;
}
static int __init ac3200_module_init(void)
{
struct net_device *dev;
int this_dev, found = 0;
for (this_dev = 0; this_dev < MAX_AC32_CARDS; this_dev++) {
if (io[this_dev] == 0 && this_dev != 0)
break;
dev = alloc_ei_netdev();
if (!dev)
break;
dev->irq = irq[this_dev];
dev->base_addr = io[this_dev];
dev->mem_start = mem[this_dev];
if (do_ac3200_probe(dev) == 0) {
dev_ac32[found++] = dev;
continue;
}
free_netdev(dev);
printk(KERN_WARNING "ac3200.c: No ac3200 card found (i/o = 0x%x).\n", io[this_dev]);
break;
}
if (found)
return 0;
return -ENXIO;
}
static void cleanup_card(struct net_device *dev)
{
free_irq(dev->irq, dev);
release_region(dev->base_addr, AC_IO_EXTENT);
iounmap(ei_status.mem);
}
static void __exit ac3200_module_exit(void)
{
int this_dev;
for (this_dev = 0; this_dev < MAX_AC32_CARDS; this_dev++) {
struct net_device *dev = dev_ac32[this_dev];
if (dev) {
unregister_netdev(dev);
cleanup_card(dev);
free_netdev(dev);
}
}
}
