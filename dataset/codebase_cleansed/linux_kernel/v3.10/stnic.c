static inline void
STNIC_DELAY (void)
{
vword trash;
trash = *(vword *) 0xa0000000;
trash = *(vword *) 0xa0000000;
trash = *(vword *) 0xa0000000;
}
static inline byte
STNIC_READ (int reg)
{
byte val;
val = (*(vhalf *) (PA_83902 + ((reg) << 1)) >> 8) & 0xff;
STNIC_DELAY ();
return val;
}
static inline void
STNIC_WRITE (int reg, byte val)
{
*(vhalf *) (PA_83902 + ((reg) << 1)) = ((half) (val) << 8);
STNIC_DELAY ();
}
static int __init stnic_probe(void)
{
struct net_device *dev;
int i, err;
if (! MACH_SE)
return -ENODEV;
dev = alloc_ei_netdev();
if (!dev)
return -ENOMEM;
#ifdef CONFIG_SH_STANDARD_BIOS
sh_bios_get_node_addr (stnic_eadr);
#endif
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = stnic_eadr[i];
dev->base_addr = 0x1000;
dev->irq = IRQ_STNIC;
dev->netdev_ops = &ei_netdev_ops;
err = request_irq (dev->irq, ei_interrupt, 0, DRV_NAME, dev);
if (err) {
printk (KERN_EMERG " unable to get IRQ %d.\n", dev->irq);
free_netdev(dev);
return err;
}
ei_status.name = dev->name;
ei_status.word16 = 1;
#ifdef __LITTLE_ENDIAN__
ei_status.bigendian = 0;
#else
ei_status.bigendian = 1;
#endif
ei_status.tx_start_page = START_PG;
ei_status.rx_start_page = START_PG + TX_PAGES;
ei_status.stop_page = STOP_PG;
ei_status.reset_8390 = &stnic_reset;
ei_status.get_8390_hdr = &stnic_get_hdr;
ei_status.block_input = &stnic_block_input;
ei_status.block_output = &stnic_block_output;
stnic_init (dev);
err = register_netdev(dev);
if (err) {
free_irq(dev->irq, dev);
free_netdev(dev);
return err;
}
stnic_dev = dev;
printk (KERN_INFO "NS ST-NIC 83902A\n");
return 0;
}
static void
stnic_reset (struct net_device *dev)
{
*(vhalf *) PA_83902_RST = 0;
udelay (5);
if (ei_debug > 1)
printk (KERN_WARNING "8390 reset done (%ld).\n", jiffies);
*(vhalf *) PA_83902_RST = ~0;
udelay (5);
}
static void
stnic_get_hdr (struct net_device *dev, struct e8390_pkt_hdr *hdr,
int ring_page)
{
half buf[2];
STNIC_WRITE (PG0_RSAR0, 0);
STNIC_WRITE (PG0_RSAR1, ring_page);
STNIC_WRITE (PG0_RBCR0, 4);
STNIC_WRITE (PG0_RBCR1, 0);
STNIC_WRITE (STNIC_CR, CR_RRD | CR_PG0 | CR_STA);
buf[0] = *(vhalf *) PA_83902_IF;
STNIC_DELAY ();
buf[1] = *(vhalf *) PA_83902_IF;
STNIC_DELAY ();
hdr->next = buf[0] >> 8;
hdr->status = buf[0] & 0xff;
#ifdef __LITTLE_ENDIAN__
hdr->count = buf[1];
#else
hdr->count = ((buf[1] >> 8) & 0xff) | (buf[1] << 8);
#endif
if (ei_debug > 1)
printk (KERN_DEBUG "ring %x status %02x next %02x count %04x.\n",
ring_page, hdr->status, hdr->next, hdr->count);
STNIC_WRITE (STNIC_CR, CR_RDMA | CR_PG0 | CR_STA);
}
static void
stnic_block_input (struct net_device *dev, int length, struct sk_buff *skb,
int offset)
{
char *buf = skb->data;
half val;
STNIC_WRITE (PG0_RSAR0, offset & 0xff);
STNIC_WRITE (PG0_RSAR1, offset >> 8);
STNIC_WRITE (PG0_RBCR0, length & 0xff);
STNIC_WRITE (PG0_RBCR1, length >> 8);
STNIC_WRITE (STNIC_CR, CR_RRD | CR_PG0 | CR_STA);
if (length & 1)
length++;
while (length > 0)
{
val = *(vhalf *) PA_83902_IF;
#ifdef __LITTLE_ENDIAN__
*buf++ = val & 0xff;
*buf++ = val >> 8;
#else
*buf++ = val >> 8;
*buf++ = val & 0xff;
#endif
STNIC_DELAY ();
length -= sizeof (half);
}
STNIC_WRITE (STNIC_CR, CR_RDMA | CR_PG0 | CR_STA);
}
static void
stnic_block_output (struct net_device *dev, int length,
const unsigned char *buf, int output_page)
{
STNIC_WRITE (PG0_RBCR0, 1);
STNIC_WRITE (STNIC_CR, CR_RRD | CR_PG0 | CR_STA);
STNIC_DELAY ();
STNIC_WRITE (PG0_RBCR0, length & 0xff);
STNIC_WRITE (PG0_RBCR1, length >> 8);
STNIC_WRITE (PG0_RSAR0, 0);
STNIC_WRITE (PG0_RSAR1, output_page);
STNIC_WRITE (STNIC_CR, CR_RWR | CR_PG0 | CR_STA);
if (length & 1)
length++;
while (length > 0)
{
#ifdef __LITTLE_ENDIAN__
*(vhalf *) PA_83902_IF = ((half) buf[1] << 8) | buf[0];
#else
*(vhalf *) PA_83902_IF = ((half) buf[0] << 8) | buf[1];
#endif
STNIC_DELAY ();
buf += sizeof (half);
length -= sizeof (half);
}
STNIC_WRITE (STNIC_CR, CR_RDMA | CR_PG0 | CR_STA);
}
static void
stnic_init (struct net_device *dev)
{
stnic_reset (dev);
NS8390_init (dev, 0);
}
static void __exit stnic_cleanup(void)
{
unregister_netdev(stnic_dev);
free_irq(stnic_dev->irq, stnic_dev);
free_netdev(stnic_dev);
}
