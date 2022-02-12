static int __devinit hydra_init_one(struct zorro_dev *z,
const struct zorro_device_id *ent)
{
int err;
if (!request_mem_region(z->resource.start, 0x10000, "Hydra"))
return -EBUSY;
if ((err = hydra_init(z))) {
release_mem_region(z->resource.start, 0x10000);
return -EBUSY;
}
return 0;
}
static int __devinit hydra_init(struct zorro_dev *z)
{
struct net_device *dev;
unsigned long board = ZTWO_VADDR(z->resource.start);
unsigned long ioaddr = board+HYDRA_NIC_BASE;
const char name[] = "NE2000";
int start_page, stop_page;
int j;
int err;
static u32 hydra_offsets[16] = {
0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e,
0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
};
dev = ____alloc_ei_netdev(0);
if (!dev)
return -ENOMEM;
for(j = 0; j < ETHER_ADDR_LEN; j++)
dev->dev_addr[j] = *((u8 *)(board + HYDRA_ADDRPROM + 2*j));
z_writeb(0x4b, ioaddr + NE_EN0_DCFG);
start_page = NESM_START_PG;
stop_page = NESM_STOP_PG;
dev->base_addr = ioaddr;
dev->irq = IRQ_AMIGA_PORTS;
if (request_irq(IRQ_AMIGA_PORTS, __ei_interrupt, IRQF_SHARED, "Hydra Ethernet",
dev)) {
free_netdev(dev);
return -EAGAIN;
}
ei_status.name = name;
ei_status.tx_start_page = start_page;
ei_status.stop_page = stop_page;
ei_status.word16 = 1;
ei_status.bigendian = 1;
ei_status.rx_start_page = start_page + TX_PAGES;
ei_status.reset_8390 = hydra_reset_8390;
ei_status.block_input = hydra_block_input;
ei_status.block_output = hydra_block_output;
ei_status.get_8390_hdr = hydra_get_8390_hdr;
ei_status.reg_offset = hydra_offsets;
dev->netdev_ops = &hydra_netdev_ops;
__NS8390_init(dev, 0);
err = register_netdev(dev);
if (err) {
free_irq(IRQ_AMIGA_PORTS, dev);
free_netdev(dev);
return err;
}
zorro_set_drvdata(z, dev);
pr_info("%s: Hydra at %pR, address %pM (hydra.c " HYDRA_VERSION ")\n",
dev->name, &z->resource, dev->dev_addr);
return 0;
}
static int hydra_open(struct net_device *dev)
{
__ei_open(dev);
return 0;
}
static int hydra_close(struct net_device *dev)
{
if (ei_debug > 1)
printk(KERN_DEBUG "%s: Shutting down ethercard.\n", dev->name);
__ei_close(dev);
return 0;
}
static void hydra_reset_8390(struct net_device *dev)
{
printk(KERN_INFO "Hydra hw reset not there\n");
}
static void hydra_get_8390_hdr(struct net_device *dev,
struct e8390_pkt_hdr *hdr, int ring_page)
{
int nic_base = dev->base_addr;
short *ptrs;
unsigned long hdr_start= (nic_base-HYDRA_NIC_BASE) +
((ring_page - NESM_START_PG)<<8);
ptrs = (short *)hdr;
*(ptrs++) = z_readw(hdr_start);
*((short *)hdr) = WORDSWAP(*((short *)hdr));
hdr_start += 2;
*(ptrs++) = z_readw(hdr_start);
*((short *)hdr+1) = WORDSWAP(*((short *)hdr+1));
}
static void hydra_block_input(struct net_device *dev, int count,
struct sk_buff *skb, int ring_offset)
{
unsigned long nic_base = dev->base_addr;
unsigned long mem_base = nic_base - HYDRA_NIC_BASE;
unsigned long xfer_start = mem_base + ring_offset - (NESM_START_PG<<8);
if (count&1)
count++;
if (xfer_start+count > mem_base + (NESM_STOP_PG<<8)) {
int semi_count = (mem_base + (NESM_STOP_PG<<8)) - xfer_start;
z_memcpy_fromio(skb->data,xfer_start,semi_count);
count -= semi_count;
z_memcpy_fromio(skb->data+semi_count, mem_base, count);
} else
z_memcpy_fromio(skb->data, xfer_start,count);
}
static void hydra_block_output(struct net_device *dev, int count,
const unsigned char *buf, int start_page)
{
unsigned long nic_base = dev->base_addr;
unsigned long mem_base = nic_base - HYDRA_NIC_BASE;
if (count&1)
count++;
z_memcpy_toio(mem_base+((start_page - NESM_START_PG)<<8), buf, count);
}
static void __devexit hydra_remove_one(struct zorro_dev *z)
{
struct net_device *dev = zorro_get_drvdata(z);
unregister_netdev(dev);
free_irq(IRQ_AMIGA_PORTS, dev);
release_mem_region(ZTWO_PADDR(dev->base_addr)-HYDRA_NIC_BASE, 0x10000);
free_netdev(dev);
}
static int __init hydra_init_module(void)
{
return zorro_register_driver(&hydra_driver);
}
static void __exit hydra_cleanup_module(void)
{
zorro_unregister_driver(&hydra_driver);
}
