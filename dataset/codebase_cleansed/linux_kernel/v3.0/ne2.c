static void __init dlink_put_eeprom(unsigned char value, unsigned int addr)
{
int z;
unsigned char v1, v2;
outb(value, addr + 0x1e);
for (z = 0; z < 2; z++) {
do {
v1 = inb(addr + 0x1e);
v2 = inb(addr + 0x1e);
}
while (!((v1 ^ v2) & 0x80));
}
}
static void __init dlink_send_eeprom_bit(unsigned int bit, unsigned int addr)
{
bit = bit << 1;
dlink_put_eeprom(0x09 | bit, addr);
dlink_put_eeprom(0x0d | bit, addr);
dlink_put_eeprom(0x0d | bit, addr);
dlink_put_eeprom(0x09 | bit, addr);
}
static void __init dlink_send_eeprom_word(unsigned int value, unsigned int len, unsigned int addr)
{
int z;
value = value << (16 - len);
for (z = 0; z < len; z++) {
dlink_send_eeprom_bit((value & 0x8000) >> 15, addr);
value = value << 1;
}
}
static unsigned int __init dlink_get_eeprom(unsigned int eeaddr, unsigned int addr)
{
int z;
unsigned int value = 0;
dlink_put_eeprom(0x01, addr);
dlink_put_eeprom(0x09, addr);
dlink_send_eeprom_word(0x0180 | (eeaddr & 0x3f), 9, addr);
for (z = 0; z < 16; z++) {
dlink_send_eeprom_bit(0, addr);
value = (value << 1) | (inb(addr + 0x1e) & 0x01);
}
return value;
}
static int __init do_ne2_probe(struct net_device *dev)
{
static int current_mca_slot = -1;
int i;
int adapter_found = 0;
for(i = 0; (ne2_adapters[i].name != NULL) && !adapter_found; i++) {
current_mca_slot =
mca_find_unused_adapter(ne2_adapters[i].id, 0);
if((current_mca_slot != MCA_NOTFOUND) && !adapter_found) {
int res;
mca_set_adapter_name(current_mca_slot,
ne2_adapters[i].name);
mca_mark_as_used(current_mca_slot);
res = ne2_probe1(dev, current_mca_slot);
if (res)
mca_mark_as_unused(current_mca_slot);
return res;
}
}
return -ENODEV;
}
struct net_device * __init ne2_probe(int unit)
{
struct net_device *dev = alloc_eip_netdev();
int err;
if (!dev)
return ERR_PTR(-ENOMEM);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
err = do_ne2_probe(dev);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int ne2_procinfo(char *buf, int slot, struct net_device *dev)
{
int len=0;
len += sprintf(buf+len, "The NE/2 Ethernet Adapter\n" );
len += sprintf(buf+len, "Driver written by Wim Dumon ");
len += sprintf(buf+len, "<wimpie@kotnet.org>\n");
len += sprintf(buf+len, "Modified by ");
len += sprintf(buf+len, "David Weinehall <tao@acc.umu.se>\n");
len += sprintf(buf+len, "and by Magnus Jonsson <bigfoot@acc.umu.se>\n");
len += sprintf(buf+len, "Based on the original NE2000 drivers\n" );
len += sprintf(buf+len, "Base IO: %#x\n", (unsigned int)dev->base_addr);
len += sprintf(buf+len, "IRQ : %d\n", dev->irq);
len += sprintf(buf+len, "HW addr : %pM\n", dev->dev_addr);
return len;
}
static int __init ne2_probe1(struct net_device *dev, int slot)
{
int i, base_addr, irq, retval;
unsigned char POS;
unsigned char SA_prom[32];
const char *name = "NE/2";
int start_page, stop_page;
static unsigned version_printed;
if (ei_debug && version_printed++ == 0)
printk(version);
printk("NE/2 ethercard found in slot %d:", slot);
POS = mca_read_stored_pos(slot, 2);
if(!(POS % 2)) {
printk(" disabled.\n");
return -ENODEV;
}
if (mca_read_stored_pos(slot, 0) == 0xea) {
base_addr = dlink_addresses[(POS >> 5) & 0x03];
irq = dlink_irqs[(POS >> 2) & 0x07];
}
else {
i = (POS & 0xE)>>1;
base_addr = addresses[i - 1];
irq = irqs[(POS & 0x60)>>5];
}
if (!request_region(base_addr, NE_IO_EXTENT, DRV_NAME))
return -EBUSY;
#ifdef DEBUG
printk("POS info : pos 2 = %#x ; base = %#x ; irq = %ld\n", POS,
base_addr, irq);
#endif
#ifndef CRYNWR_WAY
for (i=0; i<8; i++)
outb(0x0, base_addr + NE_RESET);
inb(base_addr + NE_RESET);
outb(0x21, base_addr + NE_CMD);
if (inb(base_addr + NE_CMD) != 0x21) {
printk("NE/2 adapter not responding\n");
retval = -ENODEV;
goto out;
}
#else
{
unsigned long reset_start_time = jiffies;
outb(inb(base_addr + NE_RESET), base_addr + NE_RESET);
while ((inb_p(base_addr + EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies, reset_start_time + 2*HZ/100)) {
printk(" not found (no reset ack).\n");
retval = -ENODEV;
goto out;
}
outb_p(0xff, base_addr + EN0_ISR);
}
#endif
{
struct {
unsigned char value, offset;
} program_seq[] = {
{E8390_NODMA+E8390_PAGE0+E8390_STOP, E8390_CMD},
{0x49, EN0_DCFG},
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
outb_p(program_seq[i].value, base_addr +
program_seq[i].offset);
}
for(i = 0; i < 6 ; i+=1) {
SA_prom[i] = inb(base_addr + NE_DATAPORT);
}
if (mca_read_stored_pos(slot, 0) == 0xea) {
unsigned int v;
for (i = 0; i < 3; i++) {
v = dlink_get_eeprom(i, base_addr);
SA_prom[(i << 1) ] = v & 0xff;
SA_prom[(i << 1) + 1] = (v >> 8) & 0xff;
}
}
start_page = NESM_START_PG;
stop_page = NESM_STOP_PG;
dev->irq=irq;
retval = request_irq(dev->irq, eip_interrupt, 0, DRV_NAME, dev);
if (retval) {
printk (" unable to get IRQ %d (irqval=%d).\n",
dev->irq, retval);
goto out;
}
dev->base_addr = base_addr;
for(i = 0; i < ETHER_ADDR_LEN; i++)
dev->dev_addr[i] = SA_prom[i];
printk(" %pM\n", dev->dev_addr);
printk("%s: %s found at %#x, using IRQ %d.\n",
dev->name, name, base_addr, dev->irq);
mca_set_adapter_procfn(slot, (MCA_ProcFn) ne2_procinfo, dev);
ei_status.name = name;
ei_status.tx_start_page = start_page;
ei_status.stop_page = stop_page;
ei_status.word16 = (2 == 2);
ei_status.rx_start_page = start_page + TX_PAGES;
#ifdef PACKETBUF_MEMSIZE
ei_status.stop_page = ei_status.tx_start_page + PACKETBUF_MEMSIZE;
#endif
ei_status.reset_8390 = &ne_reset_8390;
ei_status.block_input = &ne_block_input;
ei_status.block_output = &ne_block_output;
ei_status.get_8390_hdr = &ne_get_8390_hdr;
ei_status.priv = slot;
dev->netdev_ops = &eip_netdev_ops;
NS8390p_init(dev, 0);
retval = register_netdev(dev);
if (retval)
goto out1;
return 0;
out1:
mca_set_adapter_procfn( ei_status.priv, NULL, NULL);
free_irq(dev->irq, dev);
out:
release_region(base_addr, NE_IO_EXTENT);
return retval;
}
static void ne_reset_8390(struct net_device *dev)
{
unsigned long reset_start_time = jiffies;
if (ei_debug > 1)
printk("resetting the 8390 t=%ld...", jiffies);
outb(inb(NE_BASE + NE_RESET), NE_BASE + NE_RESET);
ei_status.txing = 0;
ei_status.dmaing = 0;
while ((inb_p(NE_BASE+EN0_ISR) & ENISR_RESET) == 0)
if (time_after(jiffies, reset_start_time + 2*HZ/100)) {
printk("%s: ne_reset_8390() did not complete.\n",
dev->name);
break;
}
outb_p(ENISR_RESET, NE_BASE + EN0_ISR);
}
static void ne_get_8390_hdr(struct net_device *dev, struct e8390_pkt_hdr *hdr,
int ring_page)
{
int nic_base = dev->base_addr;
if (ei_status.dmaing) {
printk("%s: DMAing conflict in ne_get_8390_hdr "
"[DMAstat:%d][irqlock:%d].\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base+ NE_CMD);
outb_p(sizeof(struct e8390_pkt_hdr), nic_base + EN0_RCNTLO);
outb_p(0, nic_base + EN0_RCNTHI);
outb_p(0, nic_base + EN0_RSARLO);
outb_p(ring_page, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + NE_CMD);
if (ei_status.word16)
insw(NE_BASE + NE_DATAPORT, hdr,
sizeof(struct e8390_pkt_hdr)>>1);
else
insb(NE_BASE + NE_DATAPORT, hdr,
sizeof(struct e8390_pkt_hdr));
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne_block_input(struct net_device *dev, int count, struct sk_buff *skb,
int ring_offset)
{
#ifdef NE_SANITY_CHECK
int xfer_count = count;
#endif
int nic_base = dev->base_addr;
char *buf = skb->data;
if (ei_status.dmaing) {
printk("%s: DMAing conflict in ne_block_input "
"[DMAstat:%d][irqlock:%d].\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base+ NE_CMD);
outb_p(count & 0xff, nic_base + EN0_RCNTLO);
outb_p(count >> 8, nic_base + EN0_RCNTHI);
outb_p(ring_offset & 0xff, nic_base + EN0_RSARLO);
outb_p(ring_offset >> 8, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + NE_CMD);
if (ei_status.word16) {
insw(NE_BASE + NE_DATAPORT,buf,count>>1);
if (count & 0x01) {
buf[count-1] = inb(NE_BASE + NE_DATAPORT);
#ifdef NE_SANITY_CHECK
xfer_count++;
#endif
}
} else {
insb(NE_BASE + NE_DATAPORT, buf, count);
}
#ifdef NE_SANITY_CHECK
if (ei_debug > 1) {
int addr, tries = 20;
do {
int high = inb_p(nic_base + EN0_RSARHI);
int low = inb_p(nic_base + EN0_RSARLO);
addr = (high << 8) + low;
if (((ring_offset + xfer_count) & 0xff) == low)
break;
} while (--tries > 0);
if (tries <= 0)
printk("%s: RX transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
dev->name, ring_offset + xfer_count, addr);
}
#endif
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void ne_block_output(struct net_device *dev, int count,
const unsigned char *buf, const int start_page)
{
int nic_base = NE_BASE;
unsigned long dma_start;
#ifdef NE_SANITY_CHECK
int retries = 0;
#endif
if (ei_status.word16 && (count & 0x01))
count++;
if (ei_status.dmaing) {
printk("%s: DMAing conflict in ne_block_output."
"[DMAstat:%d][irqlock:%d]\n",
dev->name, ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_PAGE0+E8390_START+E8390_NODMA, nic_base + NE_CMD);
#ifdef NE_SANITY_CHECK
retry:
#endif
#ifdef NE8390_RW_BUGFIX
outb_p(0x42, nic_base + EN0_RCNTLO);
outb_p(0x00, nic_base + EN0_RCNTHI);
outb_p(0x42, nic_base + EN0_RSARLO);
outb_p(0x00, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + NE_CMD);
SLOW_DOWN_IO;
SLOW_DOWN_IO;
SLOW_DOWN_IO;
#endif
outb_p(ENISR_RDC, nic_base + EN0_ISR);
outb_p(count & 0xff, nic_base + EN0_RCNTLO);
outb_p(count >> 8, nic_base + EN0_RCNTHI);
outb_p(0x00, nic_base + EN0_RSARLO);
outb_p(start_page, nic_base + EN0_RSARHI);
outb_p(E8390_RWRITE+E8390_START, nic_base + NE_CMD);
if (ei_status.word16) {
outsw(NE_BASE + NE_DATAPORT, buf, count>>1);
} else {
outsb(NE_BASE + NE_DATAPORT, buf, count);
}
dma_start = jiffies;
#ifdef NE_SANITY_CHECK
if (ei_debug > 1) {
int addr, tries = 20;
do {
int high = inb_p(nic_base + EN0_RSARHI);
int low = inb_p(nic_base + EN0_RSARLO);
addr = (high << 8) + low;
if ((start_page << 8) + count == addr)
break;
} while (--tries > 0);
if (tries <= 0) {
printk("%s: Tx packet transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
dev->name, (start_page << 8) + count, addr);
if (retries++ == 0)
goto retry;
}
}
#endif
while ((inb_p(nic_base + EN0_ISR) & ENISR_RDC) == 0)
if (time_after(jiffies, dma_start + 2*HZ/100)) {
printk("%s: timeout waiting for Tx RDC.\n", dev->name);
ne_reset_8390(dev);
NS8390p_init(dev, 1);
break;
}
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
int __init init_module(void)
{
struct net_device *dev;
int this_dev, found = 0;
for (this_dev = 0; this_dev < MAX_NE_CARDS; this_dev++) {
dev = alloc_eip_netdev();
if (!dev)
break;
dev->irq = irq[this_dev];
dev->mem_end = bad[this_dev];
dev->base_addr = io[this_dev];
if (do_ne2_probe(dev) == 0) {
dev_ne[found++] = dev;
continue;
}
free_netdev(dev);
break;
}
if (found)
return 0;
printk(KERN_WARNING "ne2.c: No NE/2 card found\n");
return -ENXIO;
}
static void cleanup_card(struct net_device *dev)
{
mca_mark_as_unused(ei_status.priv);
mca_set_adapter_procfn( ei_status.priv, NULL, NULL);
free_irq(dev->irq, dev);
release_region(dev->base_addr, NE_IO_EXTENT);
}
void __exit cleanup_module(void)
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
