static int __init do_hpp_probe(struct net_device *dev)
{
int i;
int base_addr = dev->base_addr;
int irq = dev->irq;
if (base_addr > 0x1ff)
return hpp_probe1(dev, base_addr);
else if (base_addr != 0)
return -ENXIO;
for (i = 0; hpplus_portlist[i]; i++) {
if (hpp_probe1(dev, hpplus_portlist[i]) == 0)
return 0;
dev->irq = irq;
}
return -ENODEV;
}
struct net_device * __init hp_plus_probe(int unit)
{
struct net_device *dev = alloc_eip_netdev();
int err;
if (!dev)
return ERR_PTR(-ENOMEM);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
err = do_hpp_probe(dev);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init hpp_probe1(struct net_device *dev, int ioaddr)
{
int i, retval;
unsigned char checksum = 0;
const char name[] = "HP-PC-LAN+";
int mem_start;
static unsigned version_printed;
if (!request_region(ioaddr, HP_IO_EXTENT, DRV_NAME))
return -EBUSY;
if (inw(ioaddr + HP_ID) != 0x4850 ||
(inw(ioaddr + HP_PAGING) & 0xfff0) != 0x5300) {
retval = -ENODEV;
goto out;
}
if (ei_debug && version_printed++ == 0)
printk(version);
printk("%s: %s at %#3x, ", dev->name, name, ioaddr);
outw(MAC_Page, ioaddr + HP_PAGING);
for(i = 0; i < ETH_ALEN; i++) {
unsigned char inval = inb(ioaddr + 8 + i);
dev->dev_addr[i] = inval;
checksum += inval;
}
checksum += inb(ioaddr + 14);
printk("%pM", dev->dev_addr);
if (checksum != 0xff) {
printk(" bad checksum %2.2x.\n", checksum);
retval = -ENODEV;
goto out;
} else {
outw(ID_Page, ioaddr + HP_PAGING);
printk(" ID %4.4x", inw(ioaddr + 12));
}
outw(HW_Page, ioaddr + HP_PAGING);
{
int irq = inb(ioaddr + 13) & 0x0f;
int option = inw(ioaddr + HPP_OPTION);
dev->irq = irq;
if (option & MemEnable) {
mem_start = inw(ioaddr + 9) << 8;
printk(", IRQ %d, memory address %#x.\n", irq, mem_start);
} else {
mem_start = 0;
printk(", IRQ %d, programmed-I/O mode.\n", irq);
}
}
outw((HP_START_PG + TX_PAGES/2) | ((HP_STOP_PG - 1) << 8), ioaddr + 14);
dev->base_addr = ioaddr + NIC_OFFSET;
dev->netdev_ops = &hpp_netdev_ops;
ei_status.name = name;
ei_status.word16 = 0;
ei_status.tx_start_page = HP_START_PG;
ei_status.rx_start_page = HP_START_PG + TX_PAGES/2;
ei_status.stop_page = HP_STOP_PG;
ei_status.reset_8390 = &hpp_reset_8390;
ei_status.block_input = &hpp_io_block_input;
ei_status.block_output = &hpp_io_block_output;
ei_status.get_8390_hdr = &hpp_io_get_8390_hdr;
if (mem_start) {
ei_status.block_input = &hpp_mem_block_input;
ei_status.block_output = &hpp_mem_block_output;
ei_status.get_8390_hdr = &hpp_mem_get_8390_hdr;
dev->mem_start = mem_start;
ei_status.mem = ioremap(mem_start,
(HP_STOP_PG - HP_START_PG)*256);
if (!ei_status.mem) {
retval = -ENOMEM;
goto out;
}
ei_status.rmem_start = dev->mem_start + TX_PAGES/2*256;
dev->mem_end = ei_status.rmem_end
= dev->mem_start + (HP_STOP_PG - HP_START_PG)*256;
}
outw(Perf_Page, ioaddr + HP_PAGING);
NS8390p_init(dev, 0);
outw(inw(ioaddr + HPP_OPTION) & ~EnableIRQ, ioaddr + HPP_OPTION);
retval = register_netdev(dev);
if (retval)
goto out1;
return 0;
out1:
iounmap(ei_status.mem);
out:
release_region(ioaddr, HP_IO_EXTENT);
return retval;
}
static int
hpp_open(struct net_device *dev)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
int option_reg;
int retval;
if ((retval = request_irq(dev->irq, eip_interrupt, 0, dev->name, dev))) {
return retval;
}
option_reg = inw(ioaddr + HPP_OPTION);
outw(option_reg & ~(NICReset + ChipReset), ioaddr + HPP_OPTION);
udelay(5);
outw(option_reg | (EnableIRQ + NICReset + ChipReset), ioaddr + HPP_OPTION);
outw(HW_Page, ioaddr + HP_PAGING);
outw((HP_START_PG + TX_PAGES/2) | ((HP_STOP_PG - 1) << 8), ioaddr + 14);
outw(Perf_Page, ioaddr + HP_PAGING);
return eip_open(dev);
}
static int
hpp_close(struct net_device *dev)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
int option_reg = inw(ioaddr + HPP_OPTION);
free_irq(dev->irq, dev);
eip_close(dev);
outw((option_reg & ~EnableIRQ) | MemDisable | NICReset | ChipReset,
ioaddr + HPP_OPTION);
return 0;
}
static void
hpp_reset_8390(struct net_device *dev)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
int option_reg = inw(ioaddr + HPP_OPTION);
if (ei_debug > 1) printk("resetting the 8390 time=%ld...", jiffies);
outw(option_reg & ~(NICReset + ChipReset), ioaddr + HPP_OPTION);
udelay(5);
ei_status.txing = 0;
outw(option_reg | (EnableIRQ + NICReset + ChipReset), ioaddr + HPP_OPTION);
udelay(5);
if ((inb_p(ioaddr+NIC_OFFSET+EN0_ISR) & ENISR_RESET) == 0)
printk("%s: hp_reset_8390() did not complete.\n", dev->name);
if (ei_debug > 1) printk("8390 reset done (%ld).", jiffies);
}
static void
hpp_io_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
outw((ring_page<<8), ioaddr + HPP_IN_ADDR);
insw(ioaddr + HP_DATAPORT, hdr, sizeof(struct e8390_pkt_hdr)>>1);
}
static void
hpp_io_block_input(struct net_device *dev, int count, struct sk_buff *skb, int ring_offset)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
char *buf = skb->data;
outw(ring_offset, ioaddr + HPP_IN_ADDR);
insw(ioaddr + HP_DATAPORT, buf, count>>1);
if (count & 0x01)
buf[count-1] = inw(ioaddr + HP_DATAPORT);
}
static void
hpp_mem_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
int option_reg = inw(ioaddr + HPP_OPTION);
outw((ring_page<<8), ioaddr + HPP_IN_ADDR);
outw(option_reg & ~(MemDisable + BootROMEnb), ioaddr + HPP_OPTION);
memcpy_fromio(hdr, ei_status.mem, sizeof(struct e8390_pkt_hdr));
outw(option_reg, ioaddr + HPP_OPTION);
hdr->count = (le16_to_cpu(hdr->count) + 3) & ~3;
}
static void
hpp_mem_block_input(struct net_device *dev, int count, struct sk_buff *skb, int ring_offset)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
int option_reg = inw(ioaddr + HPP_OPTION);
outw(ring_offset, ioaddr + HPP_IN_ADDR);
outw(option_reg & ~(MemDisable + BootROMEnb), ioaddr + HPP_OPTION);
memcpy_fromio(skb->data, ei_status.mem, count);
outw(option_reg, ioaddr + HPP_OPTION);
}
static void
hpp_io_block_output(struct net_device *dev, int count,
const unsigned char *buf, int start_page)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
outw(start_page << 8, ioaddr + HPP_OUT_ADDR);
outsl(ioaddr + HP_DATAPORT, buf, (count+3)>>2);
}
static void
hpp_mem_block_output(struct net_device *dev, int count,
const unsigned char *buf, int start_page)
{
int ioaddr = dev->base_addr - NIC_OFFSET;
int option_reg = inw(ioaddr + HPP_OPTION);
outw(start_page << 8, ioaddr + HPP_OUT_ADDR);
outw(option_reg & ~(MemDisable + BootROMEnb), ioaddr + HPP_OPTION);
memcpy_toio(ei_status.mem, buf, (count + 3) & ~3);
outw(option_reg, ioaddr + HPP_OPTION);
}
int __init
init_module(void)
{
struct net_device *dev;
int this_dev, found = 0;
for (this_dev = 0; this_dev < MAX_HPP_CARDS; this_dev++) {
if (io[this_dev] == 0) {
if (this_dev != 0) break;
printk(KERN_NOTICE "hp-plus.c: Presently autoprobing (not recommended) for a single card.\n");
}
dev = alloc_eip_netdev();
if (!dev)
break;
dev->irq = irq[this_dev];
dev->base_addr = io[this_dev];
if (do_hpp_probe(dev) == 0) {
dev_hpp[found++] = dev;
continue;
}
free_netdev(dev);
printk(KERN_WARNING "hp-plus.c: No HP-Plus card found (i/o = 0x%x).\n", io[this_dev]);
break;
}
if (found)
return 0;
return -ENXIO;
}
static void cleanup_card(struct net_device *dev)
{
iounmap(ei_status.mem);
release_region(dev->base_addr - NIC_OFFSET, HP_IO_EXTENT);
}
void __exit
cleanup_module(void)
{
int this_dev;
for (this_dev = 0; this_dev < MAX_HPP_CARDS; this_dev++) {
struct net_device *dev = dev_hpp[this_dev];
if (dev) {
unregister_netdev(dev);
cleanup_card(dev);
free_netdev(dev);
}
}
}
