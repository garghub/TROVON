static int __init ne3210_eisa_probe (struct device *device)
{
unsigned long ioaddr, phys_mem;
int i, retval, port_index;
struct eisa_device *edev = to_eisa_device (device);
struct net_device *dev;
if (!(dev = alloc_ei_netdev ())) {
printk ("ne3210.c: unable to allocate memory for dev!\n");
return -ENOMEM;
}
SET_NETDEV_DEV(dev, device);
dev_set_drvdata(device, dev);
ioaddr = edev->base_addr;
if (!request_region(ioaddr, NE3210_IO_EXTENT, DRV_NAME)) {
retval = -EBUSY;
goto out;
}
if (!request_region(ioaddr + NE3210_CFG1,
NE3210_CFG_EXTENT, DRV_NAME)) {
retval = -EBUSY;
goto out1;
}
#if NE3210_DEBUG & NE3210_D_PROBE
printk("ne3210-debug: probe at %#x, ID %s\n", ioaddr, edev->id.sig);
printk("ne3210-debug: config regs: %#x %#x\n",
inb(ioaddr + NE3210_CFG1), inb(ioaddr + NE3210_CFG2));
#endif
port_index = inb(ioaddr + NE3210_CFG2) >> 6;
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = inb(ioaddr + NE3210_SA_PROM + i);
printk("ne3210.c: NE3210 in EISA slot %d, media: %s, addr: %pM.\n",
edev->slot, ifmap[port_index], dev->dev_addr);
dev->irq = irq_map[(inb(ioaddr + NE3210_CFG2) >> 3) & 0x07];
printk("ne3210.c: using IRQ %d, ", dev->irq);
retval = request_irq(dev->irq, ei_interrupt, 0, DRV_NAME, dev);
if (retval) {
printk (" unable to get IRQ %d.\n", dev->irq);
goto out2;
}
phys_mem = shmem_map[inb(ioaddr + NE3210_CFG2) & 0x07] * 0x1000;
if (phys_mem > 1024*1024) {
if (phys_mem < virt_to_phys(high_memory)) {
printk(KERN_CRIT "ne3210.c: Card RAM overlaps with normal memory!!!\n");
printk(KERN_CRIT "ne3210.c: Use EISA SCU to set card memory below 1MB,\n");
printk(KERN_CRIT "ne3210.c: or to an address above 0x%llx.\n",
(u64)virt_to_phys(high_memory));
printk(KERN_CRIT "ne3210.c: Driver NOT installed.\n");
retval = -EINVAL;
goto out3;
}
}
if (!request_mem_region (phys_mem, NE3210_STOP_PG*0x100, DRV_NAME)) {
printk ("ne3210.c: Unable to request shared memory at physical address %#lx\n",
phys_mem);
goto out3;
}
printk("%dkB memory at physical address %#lx\n",
NE3210_STOP_PG/4, phys_mem);
ei_status.mem = ioremap(phys_mem, NE3210_STOP_PG*0x100);
if (!ei_status.mem) {
printk(KERN_ERR "ne3210.c: Unable to remap card memory !!\n");
printk(KERN_ERR "ne3210.c: Driver NOT installed.\n");
retval = -EAGAIN;
goto out4;
}
printk("ne3210.c: remapped %dkB card memory to virtual address %p\n",
NE3210_STOP_PG/4, ei_status.mem);
dev->mem_start = (unsigned long)ei_status.mem;
dev->mem_end = dev->mem_start + (NE3210_STOP_PG - NE3210_START_PG)*256;
dev->base_addr = ioaddr;
ei_status.name = "NE3210";
ei_status.tx_start_page = NE3210_START_PG;
ei_status.rx_start_page = NE3210_START_PG + TX_PAGES;
ei_status.stop_page = NE3210_STOP_PG;
ei_status.word16 = 1;
ei_status.priv = phys_mem;
if (ei_debug > 0)
printk("ne3210 loaded.\n");
ei_status.reset_8390 = &ne3210_reset_8390;
ei_status.block_input = &ne3210_block_input;
ei_status.block_output = &ne3210_block_output;
ei_status.get_8390_hdr = &ne3210_get_8390_hdr;
dev->netdev_ops = &ei_netdev_ops;
dev->if_port = ifmap_val[port_index];
if ((retval = register_netdev (dev)))
goto out5;
NS8390_init(dev, 0);
return 0;
out5:
iounmap(ei_status.mem);
out4:
release_mem_region (phys_mem, NE3210_STOP_PG*0x100);
out3:
free_irq (dev->irq, dev);
out2:
release_region (ioaddr + NE3210_CFG1, NE3210_CFG_EXTENT);
out1:
release_region (ioaddr, NE3210_IO_EXTENT);
out:
free_netdev (dev);
return retval;
}
static int ne3210_eisa_remove(struct device *device)
{
struct net_device *dev = dev_get_drvdata(device);
unsigned long ioaddr = to_eisa_device (device)->base_addr;
unregister_netdev (dev);
iounmap(ei_status.mem);
release_mem_region (ei_status.priv, NE3210_STOP_PG*0x100);
free_irq (dev->irq, dev);
release_region (ioaddr + NE3210_CFG1, NE3210_CFG_EXTENT);
release_region (ioaddr, NE3210_IO_EXTENT);
free_netdev (dev);
return 0;
}
static void ne3210_reset_8390(struct net_device *dev)
{
unsigned short ioaddr = dev->base_addr;
outb(0x04, ioaddr + NE3210_RESET_PORT);
if (ei_debug > 1) printk("%s: resetting the NE3210...", dev->name);
mdelay(2);
ei_status.txing = 0;
outb(0x01, ioaddr + NE3210_RESET_PORT);
if (ei_debug > 1) printk("reset done\n");
}
static void
ne3210_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
void __iomem *hdr_start = ei_status.mem + ((ring_page - NE3210_START_PG)<<8);
memcpy_fromio(hdr, hdr_start, sizeof(struct e8390_pkt_hdr));
hdr->count = (hdr->count + 3) & ~3;
}
static void ne3210_block_input(struct net_device *dev, int count, struct sk_buff *skb,
int ring_offset)
{
void __iomem *start = ei_status.mem + ring_offset - NE3210_START_PG*256;
if (ring_offset + count > NE3210_STOP_PG*256) {
int semi_count = NE3210_STOP_PG*256 - ring_offset;
memcpy_fromio(skb->data, start, semi_count);
count -= semi_count;
memcpy_fromio(skb->data + semi_count,
ei_status.mem + TX_PAGES*256, count);
} else {
memcpy_fromio(skb->data, start, count);
}
}
static void ne3210_block_output(struct net_device *dev, int count,
const unsigned char *buf, int start_page)
{
void __iomem *shmem = ei_status.mem + ((start_page - NE3210_START_PG)<<8);
count = (count + 3) & ~3;
memcpy_toio(shmem, buf, count);
}
static int ne3210_init(void)
{
return eisa_driver_register (&ne3210_eisa_driver);
}
static void ne3210_cleanup(void)
{
eisa_driver_unregister (&ne3210_eisa_driver);
}
