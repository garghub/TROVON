static int __init ultramca_probe(struct device *gen_dev)
{
unsigned short ioaddr;
struct net_device *dev;
unsigned char reg4, num_pages;
struct mca_device *mca_dev = to_mca_device(gen_dev);
char slot = mca_dev->slot;
unsigned char pos2 = 0xff, pos3 = 0xff, pos4 = 0xff, pos5 = 0xff;
int i, rc;
int adapter = mca_dev->index;
int tbase = 0;
int tirq = 0;
int base_addr = ultra_io[ultra_found];
int irq = ultra_irq[ultra_found];
if (base_addr || irq) {
printk(KERN_INFO "Probing for SMC MCA adapter");
if (base_addr) {
printk(KERN_INFO " at I/O address 0x%04x%c",
base_addr, irq ? ' ' : '\n');
}
if (irq) {
printk(KERN_INFO "using irq %d\n", irq);
}
}
tirq = 0;
tbase = 0;
pos2 = mca_device_read_stored_pos(mca_dev, 2);
pos3 = mca_device_read_stored_pos(mca_dev, 3);
pos4 = mca_device_read_stored_pos(mca_dev, 4);
pos5 = mca_device_read_stored_pos(mca_dev, 5);
switch (mca_dev->index) {
case _61c8_SMC_Ethercard_PLUS_Elite_A_BNC_AUI_WD8013EP_A:
case _61c9_SMC_Ethercard_PLUS_Elite_A_UTP_AUI_WD8013EP_A:
case _efd4_IBM_PS2_Adapter_A_for_Ethernet_UTP_AUI_WD8013WP_A:
case _efd5_IBM_PS2_Adapter_A_for_Ethernet_BNC_AUI_WD8013WP_A:
{
tbase = addr_table[(pos2 & 0xf0) >> 4].base_addr;
tirq = irq_table[(pos5 & 0xc) >> 2].new_irq;
break;
}
case _6fc0_WD_Ethercard_PLUS_A_WD8003E_A_OR_WD8003ET_A:
case _6fc1_WD_Starcard_PLUS_A_WD8003ST_A:
case _6fc2_WD_Ethercard_PLUS_10T_A_WD8003W_A:
case _efe5_IBM_PS2_Adapter_A_for_Ethernet:
{
tbase = ((pos2 & 0x0fe) * 0x10);
tirq = irq_table[(pos5 & 3)].old_irq;
break;
}
}
if(!tirq || !tbase ||
(irq && irq != tirq) ||
(base_addr && tbase != base_addr))
return -ENXIO;
dev = alloc_ei_netdev();
if(!dev)
return -ENODEV;
SET_NETDEV_DEV(dev, gen_dev);
mca_device_set_name(mca_dev, smc_mca_adapter_names[adapter]);
mca_device_set_claim(mca_dev, 1);
printk(KERN_INFO "smc_mca: %s found in slot %d\n",
smc_mca_adapter_names[adapter], slot + 1);
ultra_found++;
dev->base_addr = ioaddr = mca_device_transform_ioport(mca_dev, tbase);
dev->irq = mca_device_transform_irq(mca_dev, tirq);
dev->mem_start = 0;
num_pages = 40;
switch (adapter) {
case _61c8_SMC_Ethercard_PLUS_Elite_A_BNC_AUI_WD8013EP_A:
case _61c9_SMC_Ethercard_PLUS_Elite_A_UTP_AUI_WD8013EP_A:
{
for (i = 0; i < 16; i++) {
if (mem_table[i].mem_index == (pos3 & ~MEM_MASK)) {
dev->mem_start = (unsigned long)
mca_device_transform_memory(mca_dev, (void *)mem_table[i].mem_start);
num_pages = mem_table[i].num_pages;
}
}
break;
}
case _6fc0_WD_Ethercard_PLUS_A_WD8003E_A_OR_WD8003ET_A:
case _6fc1_WD_Starcard_PLUS_A_WD8003ST_A:
case _6fc2_WD_Ethercard_PLUS_10T_A_WD8003W_A:
case _efe5_IBM_PS2_Adapter_A_for_Ethernet:
{
dev->mem_start = (unsigned long)
mca_device_transform_memory(mca_dev, (void *)((pos3 & 0xfc) * 0x1000));
num_pages = 0x40;
break;
}
case _efd4_IBM_PS2_Adapter_A_for_Ethernet_UTP_AUI_WD8013WP_A:
case _efd5_IBM_PS2_Adapter_A_for_Ethernet_BNC_AUI_WD8013WP_A:
{
dev->mem_start = (unsigned long)
mca_device_transform_memory(mca_dev, (void *)(0xc0000 + (0x2000 * (pos3 & 0xf))));
num_pages = 0x20 + (2 * (pos3 & 0x10));
break;
}
}
if (dev->mem_start == 0) {
rc = -ENODEV;
goto err_unclaim;
}
if (!request_region(ioaddr, ULTRA_IO_EXTENT, DRV_NAME)) {
rc = -ENODEV;
goto err_unclaim;
}
reg4 = inb(ioaddr + 4) & 0x7f;
outb(reg4, ioaddr + 4);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = inb(ioaddr + 8 + i);
printk(KERN_INFO "smc_mca[%d]: Parameters: %#3x, %pM",
slot + 1, ioaddr, dev->dev_addr);
outb(0x80 | reg4, ioaddr + 4);
outb(0x80 | inb(ioaddr + 0x0c), ioaddr + 0x0c);
outb(reg4, ioaddr + 4);
dev_set_drvdata(gen_dev, dev);
dev->base_addr = ioaddr + ULTRA_NIC_OFFSET;
ei_status.name = "SMC Ultra MCA";
ei_status.word16 = 1;
ei_status.tx_start_page = START_PG;
ei_status.rx_start_page = START_PG + TX_PAGES;
ei_status.stop_page = num_pages;
ei_status.mem = ioremap(dev->mem_start, (ei_status.stop_page - START_PG) * 256);
if (!ei_status.mem) {
rc = -ENOMEM;
goto err_release_region;
}
dev->mem_end = dev->mem_start + (ei_status.stop_page - START_PG) * 256;
printk(", IRQ %d memory %#lx-%#lx.\n",
dev->irq, dev->mem_start, dev->mem_end - 1);
ei_status.reset_8390 = &ultramca_reset_8390;
ei_status.block_input = &ultramca_block_input;
ei_status.block_output = &ultramca_block_output;
ei_status.get_8390_hdr = &ultramca_get_8390_hdr;
ei_status.priv = slot;
dev->netdev_ops = &ultramca_netdev_ops;
NS8390_init(dev, 0);
rc = register_netdev(dev);
if (rc)
goto err_unmap;
return 0;
err_unmap:
iounmap(ei_status.mem);
err_release_region:
release_region(ioaddr, ULTRA_IO_EXTENT);
err_unclaim:
mca_device_set_claim(mca_dev, 0);
free_netdev(dev);
return rc;
}
static int ultramca_open(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA_NIC_OFFSET;
int retval;
if ((retval = request_irq(dev->irq, ei_interrupt, 0, dev->name, dev)))
return retval;
outb(ULTRA_MEMENB, ioaddr);
outb(0x80, ioaddr + 5);
outb(0x01, ioaddr + 6);
outb(0x04, ioaddr + 5);
ei_open(dev);
return 0;
}
static void ultramca_reset_8390(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA_NIC_OFFSET;
outb(ULTRA_RESET, ioaddr);
if (ei_debug > 1)
printk("resetting Ultra, t=%ld...", jiffies);
ei_status.txing = 0;
outb(0x80, ioaddr + 5);
outb(0x01, ioaddr + 6);
if (ei_debug > 1)
printk("reset done\n");
}
static void ultramca_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
void __iomem *hdr_start = ei_status.mem + ((ring_page - START_PG) << 8);
#ifdef notdef
memcpy_fromio(hdr, hdr_start, sizeof(struct e8390_pkt_hdr));
#else
((unsigned int*)hdr)[0] = readl(hdr_start);
#endif
}
static void ultramca_block_input(struct net_device *dev, int count, struct sk_buff *skb, int ring_offset)
{
void __iomem *xfer_start = ei_status.mem + ring_offset - START_PG * 256;
if (ring_offset + count > ei_status.stop_page * 256) {
int semi_count = ei_status.stop_page * 256 - ring_offset;
memcpy_fromio(skb->data, xfer_start, semi_count);
count -= semi_count;
memcpy_fromio(skb->data + semi_count, ei_status.mem + TX_PAGES * 256, count);
} else {
memcpy_fromio(skb->data, xfer_start, count);
}
}
static void ultramca_block_output(struct net_device *dev, int count, const unsigned char *buf,
int start_page)
{
void __iomem *shmem = ei_status.mem + ((start_page - START_PG) << 8);
memcpy_toio(shmem, buf, count);
}
static int ultramca_close_card(struct net_device *dev)
{
int ioaddr = dev->base_addr - ULTRA_NIC_OFFSET;
netif_stop_queue(dev);
if (ei_debug > 1)
printk("%s: Shutting down ethercard.\n", dev->name);
outb(0x00, ioaddr + 6);
free_irq(dev->irq, dev);
NS8390_init(dev, 0);
return 0;
}
static int ultramca_remove(struct device *gen_dev)
{
struct mca_device *mca_dev = to_mca_device(gen_dev);
struct net_device *dev = dev_get_drvdata(gen_dev);
if (dev) {
int ioaddr = dev->base_addr - ULTRA_NIC_OFFSET;
unregister_netdev(dev);
mca_device_set_claim(mca_dev, 0);
release_region(ioaddr, ULTRA_IO_EXTENT);
iounmap(ei_status.mem);
free_netdev(dev);
}
return 0;
}
static int __init ultramca_init_module(void)
{
if(!MCA_bus)
return -ENXIO;
mca_register_driver(&ultra_driver);
return ultra_found ? 0 : -ENXIO;
}
static void __exit ultramca_cleanup_module(void)
{
mca_unregister_driver(&ultra_driver);
}
