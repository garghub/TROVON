static inline void ether3_outb(int v, const void __iomem *r)
{
writeb(v, r);
udelay(1);
}
static inline void ether3_outw(int v, const void __iomem *r)
{
writew(v, r);
udelay(1);
}
static int
ether3_setbuffer(struct net_device *dev, buffer_rw_t read, int start)
{
int timeout = 1000;
ether3_outw(priv(dev)->regs.config1 | CFG1_LOCBUFMEM, REG_CONFIG1);
ether3_outw(priv(dev)->regs.command | CMD_FIFOWRITE, REG_COMMAND);
while ((ether3_inw(REG_STATUS) & STAT_FIFOEMPTY) == 0) {
if (!timeout--) {
printk("%s: setbuffer broken\n", dev->name);
priv(dev)->broken = 1;
return 1;
}
udelay(1);
}
if (read == buffer_read) {
ether3_outw(start, REG_DMAADDR);
ether3_outw(priv(dev)->regs.command | CMD_FIFOREAD, REG_COMMAND);
} else {
ether3_outw(priv(dev)->regs.command | CMD_FIFOWRITE, REG_COMMAND);
ether3_outw(start, REG_DMAADDR);
}
return 0;
}
static void ether3_ledoff(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
ether3_outw(priv(dev)->regs.config2 |= CFG2_CTRLO, REG_CONFIG2);
}
static inline void ether3_ledon(struct net_device *dev)
{
del_timer(&priv(dev)->timer);
priv(dev)->timer.expires = jiffies + HZ / 50;
priv(dev)->timer.data = (unsigned long)dev;
priv(dev)->timer.function = ether3_ledoff;
add_timer(&priv(dev)->timer);
if (priv(dev)->regs.config2 & CFG2_CTRLO)
ether3_outw(priv(dev)->regs.config2 &= ~CFG2_CTRLO, REG_CONFIG2);
}
static int __devinit
ether3_addr(char *addr, struct expansion_card *ec)
{
struct in_chunk_dir cd;
char *s;
if (ecard_readchunk(&cd, ec, 0xf5, 0) && (s = strchr(cd.d.string, '('))) {
int i;
for (i = 0; i<6; i++) {
addr[i] = simple_strtoul(s + 1, &s, 0x10);
if (*s != (i==5?')' : ':' ))
break;
}
if (i == 6)
return 0;
}
printk(KERN_ERR "ether3: Couldn't read a valid MAC address from card.\n");
return -ENODEV;
}
static int __devinit
ether3_ramtest(struct net_device *dev, unsigned char byte)
{
unsigned char *buffer = kmalloc(RX_END, GFP_KERNEL);
int i,ret = 0;
int max_errors = 4;
int bad = -1;
if (!buffer)
return 1;
memset(buffer, byte, RX_END);
ether3_setbuffer(dev, buffer_write, 0);
ether3_writebuffer(dev, buffer, TX_END);
ether3_setbuffer(dev, buffer_write, RX_START);
ether3_writebuffer(dev, buffer + RX_START, RX_LEN);
memset(buffer, byte ^ 0xff, RX_END);
ether3_setbuffer(dev, buffer_read, 0);
ether3_readbuffer(dev, buffer, TX_END);
ether3_setbuffer(dev, buffer_read, RX_START);
ether3_readbuffer(dev, buffer + RX_START, RX_LEN);
for (i = 0; i < RX_END; i++) {
if (buffer[i] != byte) {
if (max_errors > 0 && bad != buffer[i]) {
printk("%s: RAM failed with (%02X instead of %02X) at 0x%04X",
dev->name, buffer[i], byte, i);
ret = 2;
max_errors--;
bad = i;
}
} else {
if (bad != -1) {
if (bad != i - 1)
printk(" - 0x%04X\n", i - 1);
printk("\n");
bad = -1;
}
}
}
if (bad != -1)
printk(" - 0xffff\n");
kfree(buffer);
return ret;
}
static int __devinit ether3_init_2(struct net_device *dev)
{
int i;
priv(dev)->regs.config1 = CFG1_RECVCOMPSTAT0|CFG1_DMABURST8;
priv(dev)->regs.config2 = CFG2_CTRLO|CFG2_RECVCRC|CFG2_ERRENCRC;
priv(dev)->regs.command = 0;
ether3_outw(priv(dev)->regs.config1 | CFG1_BUFSELSTAT0, REG_CONFIG1);
for (i = 0; i < 6; i++)
ether3_outb(dev->dev_addr[i], REG_BUFWIN);
if (dev->flags & IFF_PROMISC)
priv(dev)->regs.config1 |= CFG1_RECVPROMISC;
else if (dev->flags & IFF_MULTICAST)
priv(dev)->regs.config1 |= CFG1_RECVSPECBRMULTI;
else
priv(dev)->regs.config1 |= CFG1_RECVSPECBROAD;
ether3_outw(priv(dev)->regs.config1 | CFG1_TRANSEND, REG_CONFIG1);
ether3_outw((TX_END>>8) - 1, REG_BUFWIN);
ether3_outw(priv(dev)->rx_head, REG_RECVPTR);
ether3_outw(0, REG_TRANSMITPTR);
ether3_outw(priv(dev)->rx_head >> 8, REG_RECVEND);
ether3_outw(priv(dev)->regs.config2, REG_CONFIG2);
ether3_outw(priv(dev)->regs.config1 | CFG1_LOCBUFMEM, REG_CONFIG1);
ether3_outw(priv(dev)->regs.command, REG_COMMAND);
i = ether3_ramtest(dev, 0x5A);
if(i)
return i;
i = ether3_ramtest(dev, 0x1E);
if(i)
return i;
ether3_setbuffer(dev, buffer_write, 0);
ether3_writelong(dev, 0);
return 0;
}
static void
ether3_init_for_open(struct net_device *dev)
{
int i;
ether3_outw(CFG2_RESET, REG_CONFIG2);
udelay(4);
priv(dev)->regs.command = 0;
ether3_outw(CMD_RXOFF|CMD_TXOFF, REG_COMMAND);
while (ether3_inw(REG_STATUS) & (STAT_RXON|STAT_TXON))
barrier();
ether3_outw(priv(dev)->regs.config1 | CFG1_BUFSELSTAT0, REG_CONFIG1);
for (i = 0; i < 6; i++)
ether3_outb(dev->dev_addr[i], REG_BUFWIN);
priv(dev)->tx_head = 0;
priv(dev)->tx_tail = 0;
priv(dev)->regs.config2 |= CFG2_CTRLO;
priv(dev)->rx_head = RX_START;
ether3_outw(priv(dev)->regs.config1 | CFG1_TRANSEND, REG_CONFIG1);
ether3_outw((TX_END>>8) - 1, REG_BUFWIN);
ether3_outw(priv(dev)->rx_head, REG_RECVPTR);
ether3_outw(priv(dev)->rx_head >> 8, REG_RECVEND);
ether3_outw(0, REG_TRANSMITPTR);
ether3_outw(priv(dev)->regs.config2, REG_CONFIG2);
ether3_outw(priv(dev)->regs.config1 | CFG1_LOCBUFMEM, REG_CONFIG1);
ether3_setbuffer(dev, buffer_write, 0);
ether3_writelong(dev, 0);
priv(dev)->regs.command = CMD_ENINTRX | CMD_ENINTTX;
ether3_outw(priv(dev)->regs.command | CMD_RXON, REG_COMMAND);
}
static inline int
ether3_probe_bus_8(struct net_device *dev, int val)
{
int write_low, write_high, read_low, read_high;
write_low = val & 255;
write_high = val >> 8;
printk(KERN_DEBUG "ether3_probe: write8 [%02X:%02X]", write_high, write_low);
ether3_outb(write_low, REG_RECVPTR);
ether3_outb(write_high, REG_RECVPTR + 4);
read_low = ether3_inb(REG_RECVPTR);
read_high = ether3_inb(REG_RECVPTR + 4);
printk(", read8 [%02X:%02X]\n", read_high, read_low);
return read_low == write_low && read_high == write_high;
}
static inline int
ether3_probe_bus_16(struct net_device *dev, int val)
{
int read_val;
ether3_outw(val, REG_RECVPTR);
read_val = ether3_inw(REG_RECVPTR);
printk(KERN_DEBUG "ether3_probe: write16 [%04X], read16 [%04X]\n", val, read_val);
return read_val == val;
}
static int
ether3_open(struct net_device *dev)
{
if (!is_valid_ether_addr(dev->dev_addr)) {
printk(KERN_WARNING "%s: invalid ethernet MAC address\n",
dev->name);
return -EINVAL;
}
if (request_irq(dev->irq, ether3_interrupt, 0, "ether3", dev))
return -EAGAIN;
ether3_init_for_open(dev);
netif_start_queue(dev);
return 0;
}
static int
ether3_close(struct net_device *dev)
{
netif_stop_queue(dev);
disable_irq(dev->irq);
ether3_outw(CMD_RXOFF|CMD_TXOFF, REG_COMMAND);
priv(dev)->regs.command = 0;
while (ether3_inw(REG_STATUS) & (STAT_RXON|STAT_TXON))
barrier();
ether3_outb(0x80, REG_CONFIG2 + 4);
ether3_outw(0, REG_COMMAND);
free_irq(dev->irq, dev);
return 0;
}
static void ether3_setmulticastlist(struct net_device *dev)
{
priv(dev)->regs.config1 &= ~CFG1_RECVPROMISC;
if (dev->flags & IFF_PROMISC) {
priv(dev)->regs.config1 |= CFG1_RECVPROMISC;
} else if (dev->flags & IFF_ALLMULTI || !netdev_mc_empty(dev)) {
priv(dev)->regs.config1 |= CFG1_RECVSPECBRMULTI;
} else
priv(dev)->regs.config1 |= CFG1_RECVSPECBROAD;
ether3_outw(priv(dev)->regs.config1 | CFG1_LOCBUFMEM, REG_CONFIG1);
}
static void ether3_timeout(struct net_device *dev)
{
unsigned long flags;
del_timer(&priv(dev)->timer);
local_irq_save(flags);
printk(KERN_ERR "%s: transmit timed out, network cable problem?\n", dev->name);
printk(KERN_ERR "%s: state: { status=%04X cfg1=%04X cfg2=%04X }\n", dev->name,
ether3_inw(REG_STATUS), ether3_inw(REG_CONFIG1), ether3_inw(REG_CONFIG2));
printk(KERN_ERR "%s: { rpr=%04X rea=%04X tpr=%04X }\n", dev->name,
ether3_inw(REG_RECVPTR), ether3_inw(REG_RECVEND), ether3_inw(REG_TRANSMITPTR));
printk(KERN_ERR "%s: tx head=%X tx tail=%X\n", dev->name,
priv(dev)->tx_head, priv(dev)->tx_tail);
ether3_setbuffer(dev, buffer_read, priv(dev)->tx_tail);
printk(KERN_ERR "%s: packet status = %08X\n", dev->name, ether3_readlong(dev));
local_irq_restore(flags);
priv(dev)->regs.config2 |= CFG2_CTRLO;
dev->stats.tx_errors += 1;
ether3_outw(priv(dev)->regs.config2, REG_CONFIG2);
priv(dev)->tx_head = priv(dev)->tx_tail = 0;
netif_wake_queue(dev);
}
static int
ether3_sendpacket(struct sk_buff *skb, struct net_device *dev)
{
unsigned long flags;
unsigned int length = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
unsigned int ptr, next_ptr;
if (priv(dev)->broken) {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
netif_start_queue(dev);
return NETDEV_TX_OK;
}
length = (length + 1) & ~1;
if (length != skb->len) {
if (skb_padto(skb, length))
goto out;
}
next_ptr = (priv(dev)->tx_head + 1) & 15;
local_irq_save(flags);
if (priv(dev)->tx_tail == next_ptr) {
local_irq_restore(flags);
return NETDEV_TX_BUSY;
}
ptr = 0x600 * priv(dev)->tx_head;
priv(dev)->tx_head = next_ptr;
next_ptr *= 0x600;
#define TXHDR_FLAGS (TXHDR_TRANSMIT|TXHDR_CHAINCONTINUE|TXHDR_DATAFOLLOWS|TXHDR_ENSUCCESS)
ether3_setbuffer(dev, buffer_write, next_ptr);
ether3_writelong(dev, 0);
ether3_setbuffer(dev, buffer_write, ptr);
ether3_writelong(dev, 0);
ether3_writebuffer(dev, skb->data, length);
ether3_writeword(dev, htons(next_ptr));
ether3_writeword(dev, TXHDR_CHAINCONTINUE >> 16);
ether3_setbuffer(dev, buffer_write, ptr);
ether3_writeword(dev, htons((ptr + length + 4)));
ether3_writeword(dev, TXHDR_FLAGS >> 16);
ether3_ledon(dev);
if (!(ether3_inw(REG_STATUS) & STAT_TXON)) {
ether3_outw(ptr, REG_TRANSMITPTR);
ether3_outw(priv(dev)->regs.command | CMD_TXON, REG_COMMAND);
}
next_ptr = (priv(dev)->tx_head + 1) & 15;
local_irq_restore(flags);
dev_kfree_skb(skb);
if (priv(dev)->tx_tail == next_ptr)
netif_stop_queue(dev);
out:
return NETDEV_TX_OK;
}
static irqreturn_t
ether3_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
unsigned int status, handled = IRQ_NONE;
#if NET_DEBUG > 1
if(net_debug & DEBUG_INT)
printk("eth3irq: %d ", irq);
#endif
status = ether3_inw(REG_STATUS);
if (status & STAT_INTRX) {
ether3_outw(CMD_ACKINTRX | priv(dev)->regs.command, REG_COMMAND);
ether3_rx(dev, 12);
handled = IRQ_HANDLED;
}
if (status & STAT_INTTX) {
ether3_outw(CMD_ACKINTTX | priv(dev)->regs.command, REG_COMMAND);
ether3_tx(dev);
handled = IRQ_HANDLED;
}
#if NET_DEBUG > 1
if(net_debug & DEBUG_INT)
printk("done\n");
#endif
return handled;
}
static int ether3_rx(struct net_device *dev, unsigned int maxcnt)
{
unsigned int next_ptr = priv(dev)->rx_head, received = 0;
ether3_ledon(dev);
do {
unsigned int this_ptr, status;
unsigned char addrs[16];
{
unsigned int temp_ptr;
ether3_setbuffer(dev, buffer_read, next_ptr);
temp_ptr = ether3_readword(dev);
status = ether3_readword(dev);
if ((status & (RXSTAT_DONE | RXHDR_CHAINCONTINUE | RXHDR_RECEIVE)) !=
(RXSTAT_DONE | RXHDR_CHAINCONTINUE) || !temp_ptr)
break;
this_ptr = next_ptr + 4;
next_ptr = ntohs(temp_ptr);
}
ether3_setbuffer(dev, buffer_read, this_ptr);
ether3_readbuffer(dev, addrs+2, 12);
if (next_ptr < RX_START || next_ptr >= RX_END) {
int i;
printk("%s: bad next pointer @%04X: ", dev->name, priv(dev)->rx_head);
printk("%02X %02X %02X %02X ", next_ptr >> 8, next_ptr & 255, status & 255, status >> 8);
for (i = 2; i < 14; i++)
printk("%02X ", addrs[i]);
printk("\n");
next_ptr = priv(dev)->rx_head;
break;
}
if (!(*(unsigned long *)&dev->dev_addr[0] ^ *(unsigned long *)&addrs[2+6]) &&
!(*(unsigned short *)&dev->dev_addr[4] ^ *(unsigned short *)&addrs[2+10])) {
maxcnt ++;
ether3_outw(next_ptr >> 8, REG_RECVEND);
} else
if (!(status & (RXSTAT_OVERSIZE|RXSTAT_CRCERROR|RXSTAT_DRIBBLEERROR|RXSTAT_SHORTPACKET))) {
unsigned int length = next_ptr - this_ptr;
struct sk_buff *skb;
if (next_ptr <= this_ptr)
length += RX_END - RX_START;
skb = netdev_alloc_skb(dev, length + 2);
if (skb) {
unsigned char *buf;
skb_reserve(skb, 2);
buf = skb_put(skb, length);
ether3_readbuffer(dev, buf + 12, length - 12);
ether3_outw(next_ptr >> 8, REG_RECVEND);
*(unsigned short *)(buf + 0) = *(unsigned short *)(addrs + 2);
*(unsigned long *)(buf + 2) = *(unsigned long *)(addrs + 4);
*(unsigned long *)(buf + 6) = *(unsigned long *)(addrs + 8);
*(unsigned short *)(buf + 10) = *(unsigned short *)(addrs + 12);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
received ++;
} else
goto dropping;
} else {
struct net_device_stats *stats = &dev->stats;
ether3_outw(next_ptr >> 8, REG_RECVEND);
if (status & RXSTAT_OVERSIZE) stats->rx_over_errors ++;
if (status & RXSTAT_CRCERROR) stats->rx_crc_errors ++;
if (status & RXSTAT_DRIBBLEERROR) stats->rx_fifo_errors ++;
if (status & RXSTAT_SHORTPACKET) stats->rx_length_errors ++;
stats->rx_errors++;
}
}
while (-- maxcnt);
done:
dev->stats.rx_packets += received;
priv(dev)->rx_head = next_ptr;
if (!(ether3_inw(REG_STATUS) & STAT_RXON)) {
dev->stats.rx_dropped++;
ether3_outw(next_ptr, REG_RECVPTR);
ether3_outw(priv(dev)->regs.command | CMD_RXON, REG_COMMAND);
}
return maxcnt;
dropping:{
static unsigned long last_warned;
ether3_outw(next_ptr >> 8, REG_RECVEND);
if (time_after(jiffies, last_warned + 10 * HZ)) {
last_warned = jiffies;
printk("%s: memory squeeze, dropping packet.\n", dev->name);
}
dev->stats.rx_dropped++;
goto done;
}
}
static void ether3_tx(struct net_device *dev)
{
unsigned int tx_tail = priv(dev)->tx_tail;
int max_work = 14;
do {
unsigned long status;
ether3_setbuffer(dev, buffer_read, tx_tail * 0x600);
status = ether3_readlong(dev);
if ((status & (TXSTAT_DONE | TXHDR_TRANSMIT)) !=
(TXSTAT_DONE | TXHDR_TRANSMIT))
break;
if (!(status & (TXSTAT_BABBLED | TXSTAT_16COLLISIONS)))
dev->stats.tx_packets++;
else {
dev->stats.tx_errors++;
if (status & TXSTAT_16COLLISIONS)
dev->stats.collisions += 16;
if (status & TXSTAT_BABBLED)
dev->stats.tx_fifo_errors++;
}
tx_tail = (tx_tail + 1) & 15;
} while (--max_work);
if (priv(dev)->tx_tail != tx_tail) {
priv(dev)->tx_tail = tx_tail;
netif_wake_queue(dev);
}
}
static void __devinit ether3_banner(void)
{
static unsigned version_printed = 0;
if (net_debug && version_printed++ == 0)
printk(KERN_INFO "%s", version);
}
static int __devinit
ether3_probe(struct expansion_card *ec, const struct ecard_id *id)
{
const struct ether3_data *data = id->data;
struct net_device *dev;
int bus_type, ret;
ether3_banner();
ret = ecard_request_resources(ec);
if (ret)
goto out;
dev = alloc_etherdev(sizeof(struct dev_priv));
if (!dev) {
ret = -ENOMEM;
goto release;
}
SET_NETDEV_DEV(dev, &ec->dev);
priv(dev)->base = ecardm_iomap(ec, ECARD_RES_MEMC, 0, 0);
if (!priv(dev)->base) {
ret = -ENOMEM;
goto free;
}
ec->irqaddr = priv(dev)->base + data->base_offset;
ec->irqmask = 0xf0;
priv(dev)->seeq = priv(dev)->base + data->base_offset;
dev->irq = ec->irq;
ether3_addr(dev->dev_addr, ec);
init_timer(&priv(dev)->timer);
ether3_outb(0x80, REG_CONFIG2 + 4);
bus_type = BUS_UNKNOWN;
udelay(4);
if (ether3_probe_bus_8(dev, 0x100) &&
ether3_probe_bus_8(dev, 0x201))
bus_type = BUS_8;
if (bus_type == BUS_UNKNOWN &&
ether3_probe_bus_16(dev, 0x101) &&
ether3_probe_bus_16(dev, 0x201))
bus_type = BUS_16;
switch (bus_type) {
case BUS_UNKNOWN:
printk(KERN_ERR "%s: unable to identify bus width\n", dev->name);
ret = -ENODEV;
goto free;
case BUS_8:
printk(KERN_ERR "%s: %s found, but is an unsupported "
"8-bit card\n", dev->name, data->name);
ret = -ENODEV;
goto free;
default:
break;
}
if (ether3_init_2(dev)) {
ret = -ENODEV;
goto free;
}
dev->netdev_ops = &ether3_netdev_ops;
dev->watchdog_timeo = 5 * HZ / 100;
ret = register_netdev(dev);
if (ret)
goto free;
printk("%s: %s in slot %d, %pM\n",
dev->name, data->name, ec->slot_no, dev->dev_addr);
ecard_set_drvdata(ec, dev);
return 0;
free:
free_netdev(dev);
release:
ecard_release_resources(ec);
out:
return ret;
}
static void __devexit ether3_remove(struct expansion_card *ec)
{
struct net_device *dev = ecard_get_drvdata(ec);
ecard_set_drvdata(ec, NULL);
unregister_netdev(dev);
free_netdev(dev);
ecard_release_resources(ec);
}
static int __init ether3_init(void)
{
return ecard_register_driver(&ether3_driver);
}
static void __exit ether3_exit(void)
{
ecard_remove_driver(&ether3_driver);
}
