struct net_device * __init ewrk3_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct ewrk3_private));
int err;
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
}
err = ewrk3_probe1(dev, dev->base_addr, dev->irq);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init ewrk3_probe1(struct net_device *dev, u_long iobase, int irq)
{
int err;
dev->base_addr = iobase;
dev->irq = irq;
err = isa_probe(dev, iobase);
if (err != 0)
err = eisa_probe(dev, iobase);
if (err)
return err;
err = register_netdev(dev);
if (err)
release_region(dev->base_addr, EWRK3_TOTAL_SIZE);
return err;
}
static int __init
ewrk3_hw_init(struct net_device *dev, u_long iobase)
{
struct ewrk3_private *lp;
int i, status = 0;
u_long mem_start, shmem_length;
u_char cr, cmr, icr, nicsr, lemac, hard_strapped = 0;
u_char eeprom_image[EEPROM_MAX], chksum, eisa_cr = 0;
if (iobase > 0x400)
eisa_cr = inb(EISA_CR);
INIT_EWRK3;
nicsr = inb(EWRK3_CSR);
icr = inb(EWRK3_ICR);
icr &= 0x70;
outb(icr, EWRK3_ICR);
if (nicsr != (CSR_TXD | CSR_RXD))
return -ENXIO;
for (chksum = 0, i = 0; i < EEPROM_MAX; i += 2) {
union {
short val;
char c[2];
} tmp;
tmp.val = (short) Read_EEPROM(iobase, (i >> 1));
eeprom_image[i] = tmp.c[0];
eeprom_image[i + 1] = tmp.c[1];
chksum += eeprom_image[i] + eeprom_image[i + 1];
}
if (chksum != 0) {
printk("%s: Device has a bad on-board EEPROM.\n", dev->name);
return -ENXIO;
}
EthwrkSignature(name, eeprom_image);
if (*name == '\0')
return -ENXIO;
dev->base_addr = iobase;
if (iobase > 0x400) {
outb(eisa_cr, EISA_CR);
}
lemac = eeprom_image[EEPROM_CHIPVER];
cmr = inb(EWRK3_CMR);
if (((lemac == LeMAC) && ((cmr & CMR_NO_EEPROM) != CMR_NO_EEPROM)) ||
((lemac == LeMAC2) && !(cmr & CMR_HS))) {
printk("%s: %s at %#4lx", dev->name, name, iobase);
hard_strapped = 1;
} else if ((iobase & 0x0fff) == EWRK3_EISA_IO_PORTS) {
printk("%s: %s at %#4lx (EISA slot %ld)",
dev->name, name, iobase, ((iobase >> 12) & 0x0f));
} else {
printk("%s: %s at %#4lx", dev->name, name, iobase);
}
printk(", h/w address ");
if (lemac != LeMAC2)
DevicePresent(iobase);
status = get_hw_addr(dev, eeprom_image, lemac);
printk("%pM\n", dev->dev_addr);
if (status) {
printk(" which has an EEPROM CRC error.\n");
return -ENXIO;
}
if (lemac == LeMAC2) {
cmr &= ~(CMR_RA | CMR_WB | CMR_LINK | CMR_POLARITY | CMR_0WS);
if (eeprom_image[EEPROM_MISC0] & READ_AHEAD)
cmr |= CMR_RA;
if (eeprom_image[EEPROM_MISC0] & WRITE_BEHIND)
cmr |= CMR_WB;
if (eeprom_image[EEPROM_NETMAN0] & NETMAN_POL)
cmr |= CMR_POLARITY;
if (eeprom_image[EEPROM_NETMAN0] & NETMAN_LINK)
cmr |= CMR_LINK;
if (eeprom_image[EEPROM_MISC0] & _0WS_ENA)
cmr |= CMR_0WS;
}
if (eeprom_image[EEPROM_SETUP] & SETUP_DRAM)
cmr |= CMR_DRAM;
outb(cmr, EWRK3_CMR);
cr = inb(EWRK3_CR);
cr |= eeprom_image[EEPROM_SETUP] & SETUP_APD;
if (cr & SETUP_APD)
cr |= eeprom_image[EEPROM_SETUP] & SETUP_PS;
cr |= eeprom_image[EEPROM_MISC0] & FAST_BUS;
cr |= eeprom_image[EEPROM_MISC0] & ENA_16;
outb(cr, EWRK3_CR);
mem_start = inb(EWRK3_MBR);
shmem_length = 0;
if (mem_start != 0) {
if ((mem_start >= 0x0a) && (mem_start <= 0x0f)) {
mem_start *= SHMEM_64K;
shmem_length = SHMEM_64K;
} else if ((mem_start >= 0x14) && (mem_start <= 0x1f)) {
mem_start *= SHMEM_32K;
shmem_length = SHMEM_32K;
} else if ((mem_start >= 0x40) && (mem_start <= 0xff)) {
mem_start = mem_start * SHMEM_2K + 0x80000;
shmem_length = SHMEM_2K;
} else {
return -ENXIO;
}
}
if (hard_strapped) {
printk(" is hard strapped.\n");
} else if (mem_start) {
printk(" has a %dk RAM window", (int) (shmem_length >> 10));
printk(" at 0x%.5lx", mem_start);
} else {
printk(" is in I/O only mode");
}
lp = netdev_priv(dev);
lp->shmem_base = mem_start;
lp->shmem = ioremap(mem_start, shmem_length);
if (!lp->shmem)
return -ENOMEM;
lp->shmem_length = shmem_length;
lp->lemac = lemac;
lp->hard_strapped = hard_strapped;
lp->led_mask = CR_LED;
spin_lock_init(&lp->hw_lock);
lp->mPage = 64;
if (cmr & CMR_DRAM)
lp->mPage <<= 1;
sprintf(lp->adapter_name, "%s (%s)", name, dev->name);
lp->irq_mask = ICR_TNEM | ICR_TXDM | ICR_RNEM | ICR_RXDM;
if (!hard_strapped) {
icr |= ICR_IE;
outb(icr, EWRK3_ICR);
dev->dma = 0;
if (dev->irq < 2) {
#ifndef MODULE
u_char irqnum;
unsigned long irq_mask;
irq_mask = probe_irq_on();
icr |= ICR_TNEM;
outb(1, EWRK3_TDQ);
outb(icr, EWRK3_ICR);
irqnum = irq[((icr & IRQ_SEL) >> 4)];
mdelay(20);
dev->irq = probe_irq_off(irq_mask);
if ((dev->irq) && (irqnum == dev->irq)) {
printk(" and uses IRQ%d.\n", dev->irq);
} else {
if (!dev->irq) {
printk(" and failed to detect IRQ line.\n");
} else if ((irqnum == 1) && (lemac == LeMAC2)) {
printk(" and an illegal IRQ line detected.\n");
} else {
printk(", but incorrect IRQ line detected.\n");
}
iounmap(lp->shmem);
return -ENXIO;
}
DISABLE_IRQs;
#endif
} else {
printk(" and requires IRQ%d.\n", dev->irq);
}
}
if (ewrk3_debug > 1) {
printk(version);
}
dev->netdev_ops = &ewrk3_netdev_ops;
if (lp->adapter_name[4] == '3')
SET_ETHTOOL_OPS(dev, &ethtool_ops_203);
else
SET_ETHTOOL_OPS(dev, &ethtool_ops);
dev->watchdog_timeo = QUEUE_PKT_TIMEOUT;
dev->mem_start = 0;
return 0;
}
static int ewrk3_open(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int status = 0;
u_char icr, csr;
STOP_EWRK3;
if (!lp->hard_strapped) {
if (request_irq(dev->irq, (void *) ewrk3_interrupt, 0, "ewrk3", dev)) {
printk("ewrk3_open(): Requested IRQ%d is busy\n", dev->irq);
status = -EAGAIN;
} else {
ewrk3_init(dev);
if (ewrk3_debug > 1) {
printk("%s: ewrk3 open with irq %d\n", dev->name, dev->irq);
printk(" physical address: %pM\n", dev->dev_addr);
if (lp->shmem_length == 0) {
printk(" no shared memory, I/O only mode\n");
} else {
printk(" start of shared memory: 0x%08lx\n", lp->shmem_base);
printk(" window length: 0x%04lx\n", lp->shmem_length);
}
printk(" # of DRAMS: %d\n", ((inb(EWRK3_CMR) & 0x02) ? 2 : 1));
printk(" csr: 0x%02x\n", inb(EWRK3_CSR));
printk(" cr: 0x%02x\n", inb(EWRK3_CR));
printk(" icr: 0x%02x\n", inb(EWRK3_ICR));
printk(" cmr: 0x%02x\n", inb(EWRK3_CMR));
printk(" fmqc: 0x%02x\n", inb(EWRK3_FMQC));
}
netif_start_queue(dev);
icr = inb(EWRK3_ICR);
ENABLE_IRQs;
}
} else {
printk(KERN_ERR "%s: ewrk3 available for hard strapped set up only.\n", dev->name);
printk(KERN_ERR " Run the 'ewrk3setup' utility or remove the hard straps.\n");
return -EINVAL;
}
return status;
}
static void ewrk3_init(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_char csr, page;
u_long iobase = dev->base_addr;
int i;
set_multicast_list(dev);
for (i=0; i<ETH_ALEN; i++)
outb(dev->dev_addr[i], EWRK3_PAR0 + i);
while (inb(EWRK3_TQ));
while (inb(EWRK3_TDQ));
while (inb(EWRK3_RQ));
while (inb(EWRK3_FMQ));
for (page = 1; page < lp->mPage; page++) {
outb(page, EWRK3_FMQ);
}
START_EWRK3;
}
static void ewrk3_timeout(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_char icr, csr;
u_long iobase = dev->base_addr;
if (!lp->hard_strapped)
{
printk(KERN_WARNING"%s: transmit timed/locked out, status %04x, resetting.\n",
dev->name, inb(EWRK3_CSR));
DISABLE_IRQs;
STOP_EWRK3;
ewrk3_init(dev);
ENABLE_IRQs;
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
}
static netdev_tx_t ewrk3_queue_pkt(struct sk_buff *skb, struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
void __iomem *buf = NULL;
u_char icr;
u_char page;
spin_lock_irq (&lp->hw_lock);
DISABLE_IRQs;
if (inb (EWRK3_FMQC) == 0) {
printk (KERN_WARNING "%s: ewrk3_queue_pkt(): No free resources...\n",
dev->name);
printk (KERN_WARNING "%s: ewrk3_queue_pkt(): CSR: %02x ICR: %02x FMQC: %02x\n",
dev->name, inb (EWRK3_CSR), inb (EWRK3_ICR),
inb (EWRK3_FMQC));
goto err_out;
}
if ((page = inb (EWRK3_FMQ)) >= lp->mPage) {
printk ("ewrk3_queue_pkt(): Invalid free memory page (%d).\n",
(u_char) page);
goto err_out;
}
if (lp->shmem_length == IO_ONLY) {
outb (page, EWRK3_IOPR);
} else if (lp->shmem_length == SHMEM_2K) {
buf = lp->shmem;
outb (page, EWRK3_MPR);
} else if (lp->shmem_length == SHMEM_32K) {
buf = (((short) page << 11) & 0x7800) + lp->shmem;
outb ((page >> 4), EWRK3_MPR);
} else if (lp->shmem_length == SHMEM_64K) {
buf = (((short) page << 11) & 0xf800) + lp->shmem;
outb ((page >> 5), EWRK3_MPR);
} else {
printk (KERN_ERR "%s: Oops - your private data area is hosed!\n",
dev->name);
BUG ();
}
if (lp->shmem_length == IO_ONLY) {
int i;
u_char *p = skb->data;
outb ((char) (TCR_QMODE | TCR_PAD | TCR_IFC), EWRK3_DATA);
outb ((char) (skb->len & 0xff), EWRK3_DATA);
outb ((char) ((skb->len >> 8) & 0xff), EWRK3_DATA);
outb ((char) 0x04, EWRK3_DATA);
for (i = 0; i < skb->len; i++) {
outb (*p++, EWRK3_DATA);
}
outb (page, EWRK3_TQ);
} else {
writeb ((char) (TCR_QMODE | TCR_PAD | TCR_IFC), buf);
buf += 1;
writeb ((char) (skb->len & 0xff), buf);
buf += 1;
if (lp->txc) {
writeb(((skb->len >> 8) & 0xff) | XCT, buf);
buf += 1;
writeb (0x04, buf);
buf += 1;
writeb (0x00, (buf + skb->len));
memcpy_toio (buf, skb->data, PRELOAD);
outb (page, EWRK3_TQ);
memcpy_toio (buf + PRELOAD,
skb->data + PRELOAD,
skb->len - PRELOAD);
writeb (0xff, (buf + skb->len));
} else {
writeb ((skb->len >> 8) & 0xff, buf);
buf += 1;
writeb (0x04, buf);
buf += 1;
memcpy_toio (buf, skb->data, skb->len);
outb (page, EWRK3_TQ);
}
}
ENABLE_IRQs;
spin_unlock_irq (&lp->hw_lock);
dev->stats.tx_bytes += skb->len;
dev_kfree_skb (skb);
if (inb (EWRK3_FMQC) == 0)
netif_stop_queue (dev);
return NETDEV_TX_OK;
err_out:
ENABLE_IRQs;
spin_unlock_irq (&lp->hw_lock);
return NETDEV_TX_BUSY;
}
static irqreturn_t ewrk3_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct ewrk3_private *lp;
u_long iobase;
u_char icr, cr, csr;
lp = netdev_priv(dev);
iobase = dev->base_addr;
csr = inb(EWRK3_CSR);
spin_lock(&lp->hw_lock);
DISABLE_IRQs;
cr = inb(EWRK3_CR);
cr |= lp->led_mask;
outb(cr, EWRK3_CR);
if (csr & CSR_RNE)
ewrk3_rx(dev);
if (csr & CSR_TNE)
ewrk3_tx(dev);
if (inb(EWRK3_FMQC)) {
lp->irq_mask |= ICR_TXDM | ICR_RXDM;
csr &= ~(CSR_TXD | CSR_RXD);
outb(csr, EWRK3_CSR);
netif_wake_queue(dev);
} else {
lp->irq_mask &= ~(ICR_TXDM | ICR_RXDM);
}
cr &= ~(lp->led_mask);
outb(cr, EWRK3_CR);
ENABLE_IRQs;
spin_unlock(&lp->hw_lock);
return IRQ_HANDLED;
}
static int ewrk3_rx(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int i, status = 0;
u_char page;
void __iomem *buf = NULL;
while (inb(EWRK3_RQC) && !status) {
if ((page = inb(EWRK3_RQ)) < lp->mPage) {
if (lp->shmem_length == IO_ONLY) {
outb(page, EWRK3_IOPR);
} else if (lp->shmem_length == SHMEM_2K) {
buf = lp->shmem;
outb(page, EWRK3_MPR);
} else if (lp->shmem_length == SHMEM_32K) {
buf = (((short) page << 11) & 0x7800) + lp->shmem;
outb((page >> 4), EWRK3_MPR);
} else if (lp->shmem_length == SHMEM_64K) {
buf = (((short) page << 11) & 0xf800) + lp->shmem;
outb((page >> 5), EWRK3_MPR);
} else {
status = -1;
printk("%s: Oops - your private data area is hosed!\n", dev->name);
}
if (!status) {
char rx_status;
int pkt_len;
if (lp->shmem_length == IO_ONLY) {
rx_status = inb(EWRK3_DATA);
pkt_len = inb(EWRK3_DATA);
pkt_len |= ((u_short) inb(EWRK3_DATA) << 8);
} else {
rx_status = readb(buf);
buf += 1;
pkt_len = readw(buf);
buf += 3;
}
if (!(rx_status & R_ROK)) {
dev->stats.rx_errors++;
if (rx_status & R_DBE)
dev->stats.rx_frame_errors++;
if (rx_status & R_CRC)
dev->stats.rx_crc_errors++;
if (rx_status & R_PLL)
dev->stats.rx_fifo_errors++;
} else {
struct sk_buff *skb;
if ((skb = dev_alloc_skb(pkt_len + 2)) != NULL) {
unsigned char *p;
skb_reserve(skb, 2);
p = skb_put(skb, pkt_len);
if (lp->shmem_length == IO_ONLY) {
*p = inb(EWRK3_DATA);
for (i = 0; i < pkt_len; i++) {
*p++ = inb(EWRK3_DATA);
}
} else {
memcpy_fromio(p, buf, pkt_len);
}
for (i = 1; i < EWRK3_PKT_STAT_SZ - 1; i++) {
if (pkt_len < i * EWRK3_PKT_BIN_SZ) {
lp->pktStats.bins[i]++;
i = EWRK3_PKT_STAT_SZ;
}
}
p = skb->data;
if (p[0] & 0x01) {
if ((*(s16 *) & p[0] == -1) && (*(s16 *) & p[2] == -1) && (*(s16 *) & p[4] == -1)) {
lp->pktStats.broadcast++;
} else {
lp->pktStats.multicast++;
}
} else if ((*(s16 *) & p[0] == *(s16 *) & dev->dev_addr[0]) &&
(*(s16 *) & p[2] == *(s16 *) & dev->dev_addr[2]) &&
(*(s16 *) & p[4] == *(s16 *) & dev->dev_addr[4])) {
lp->pktStats.unicast++;
}
lp->pktStats.bins[0]++;
if (lp->pktStats.bins[0] == 0) {
memset(&lp->pktStats, 0, sizeof(lp->pktStats));
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
} else {
printk("%s: Insufficient memory; nuking packet.\n", dev->name);
dev->stats.rx_dropped++;
break;
}
}
}
outb(page, EWRK3_FMQ);
} else {
printk("ewrk3_rx(): Illegal page number, page %d\n", page);
printk("ewrk3_rx(): CSR: %02x ICR: %02x FMQC: %02x\n", inb(EWRK3_CSR), inb(EWRK3_ICR), inb(EWRK3_FMQC));
}
}
return status;
}
static int ewrk3_tx(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
u_char tx_status;
while ((tx_status = inb(EWRK3_TDQ)) > 0) {
if (tx_status & T_VSTS) {
if (tx_status & T_TXE) {
dev->stats.tx_errors++;
if (tx_status & T_NCL)
dev->stats.tx_carrier_errors++;
if (tx_status & T_LCL)
dev->stats.tx_window_errors++;
if (tx_status & T_CTU) {
if ((tx_status & T_COLL) ^ T_XUR) {
lp->pktStats.tx_underruns++;
} else {
lp->pktStats.excessive_underruns++;
}
} else if (tx_status & T_COLL) {
if ((tx_status & T_COLL) ^ T_XCOLL) {
dev->stats.collisions++;
} else {
lp->pktStats.excessive_collisions++;
}
}
} else {
dev->stats.tx_packets++;
}
}
}
return 0;
}
static int ewrk3_close(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
u_char icr, csr;
netif_stop_queue(dev);
if (ewrk3_debug > 1) {
printk("%s: Shutting down ethercard, status was %2.2x.\n",
dev->name, inb(EWRK3_CSR));
}
DISABLE_IRQs;
STOP_EWRK3;
while (inb(EWRK3_TQ));
while (inb(EWRK3_TDQ));
while (inb(EWRK3_RQ));
if (!lp->hard_strapped) {
free_irq(dev->irq, dev);
}
return 0;
}
static void set_multicast_list(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
u_char csr;
csr = inb(EWRK3_CSR);
if (lp->shmem_length == IO_ONLY) {
lp->mctbl = NULL;
} else {
lp->mctbl = lp->shmem + PAGE0_HTE;
}
csr &= ~(CSR_PME | CSR_MCE);
if (dev->flags & IFF_PROMISC) {
csr |= CSR_PME;
outb(csr, EWRK3_CSR);
} else {
SetMulticastFilter(dev);
csr |= CSR_MCE;
outb(csr, EWRK3_CSR);
}
}
static void SetMulticastFilter(struct net_device *dev)
{
struct ewrk3_private *lp = netdev_priv(dev);
struct netdev_hw_addr *ha;
u_long iobase = dev->base_addr;
int i;
char *addrs, bit, byte;
short __iomem *p = lp->mctbl;
u16 hashcode;
u32 crc;
spin_lock_irq(&lp->hw_lock);
if (lp->shmem_length == IO_ONLY) {
outb(0, EWRK3_IOPR);
outw(PAGE0_HTE, EWRK3_PIR1);
} else {
outb(0, EWRK3_MPR);
}
if (dev->flags & IFF_ALLMULTI) {
for (i = 0; i < (HASH_TABLE_LEN >> 3); i++) {
if (lp->shmem_length == IO_ONLY) {
outb(0xff, EWRK3_DATA);
} else {
writew(0xffff, p);
p++;
i++;
}
}
} else {
if (lp->shmem_length == IO_ONLY) {
for (i = 0; i < (HASH_TABLE_LEN >> 4) - 1; i++) {
outb(0x00, EWRK3_DATA);
}
outb(0x80, EWRK3_DATA);
i++;
for (; i < (HASH_TABLE_LEN >> 3); i++) {
outb(0x00, EWRK3_DATA);
}
} else {
memset_io(lp->mctbl, 0, HASH_TABLE_LEN >> 3);
writeb(0x80, lp->mctbl + (HASH_TABLE_LEN >> 4) - 1);
}
netdev_for_each_mc_addr(ha, dev) {
addrs = ha->addr;
if ((*addrs & 0x01) == 1) {
crc = ether_crc_le(ETH_ALEN, addrs);
hashcode = crc & ((1 << 9) - 1);
byte = hashcode >> 3;
bit = 1 << (hashcode & 0x07);
if (lp->shmem_length == IO_ONLY) {
u_char tmp;
outw(PAGE0_HTE + byte, EWRK3_PIR1);
tmp = inb(EWRK3_DATA);
tmp |= bit;
outw(PAGE0_HTE + byte, EWRK3_PIR1);
outb(tmp, EWRK3_DATA);
} else {
writeb(readb(lp->mctbl + byte) | bit, lp->mctbl + byte);
}
}
}
}
spin_unlock_irq(&lp->hw_lock);
}
static int __init isa_probe(struct net_device *dev, u_long ioaddr)
{
int i = num_ewrks3s, maxSlots;
int ret = -ENODEV;
u_long iobase;
if (ioaddr >= 0x400)
goto out;
if (ioaddr == 0) {
iobase = EWRK3_IO_BASE;
maxSlots = 24;
} else {
iobase = ioaddr;
maxSlots = i + 1;
}
for (; (i < maxSlots) && (dev != NULL);
iobase += EWRK3_IOP_INC, i++)
{
if (request_region(iobase, EWRK3_TOTAL_SIZE, DRV_NAME)) {
if (DevicePresent(iobase) == 0) {
int irq = dev->irq;
ret = ewrk3_hw_init(dev, iobase);
if (!ret)
break;
dev->irq = irq;
}
release_region(iobase, EWRK3_TOTAL_SIZE);
}
}
out:
return ret;
}
static int __init eisa_probe(struct net_device *dev, u_long ioaddr)
{
int i, maxSlots;
u_long iobase;
int ret = -ENODEV;
if (ioaddr < 0x1000)
goto out;
iobase = ioaddr;
i = (ioaddr >> 12);
maxSlots = i + 1;
for (i = 1; (i < maxSlots) && (dev != NULL); i++, iobase += EISA_SLOT_INC) {
if (EISA_signature(name, EISA_ID) == 0) {
if (request_region(iobase, EWRK3_TOTAL_SIZE, DRV_NAME) &&
DevicePresent(iobase) == 0) {
int irq = dev->irq;
ret = ewrk3_hw_init(dev, iobase);
if (!ret)
break;
dev->irq = irq;
}
release_region(iobase, EWRK3_TOTAL_SIZE);
}
}
out:
return ret;
}
static int Read_EEPROM(u_long iobase, u_char eaddr)
{
int i;
outb((eaddr & 0x3f), EWRK3_PIR1);
outb(EEPROM_RD, EWRK3_IOPR);
for (i = 0; i < 5000; i++)
inb(EWRK3_CSR);
return inw(EWRK3_EPROM1);
}
static int Write_EEPROM(short data, u_long iobase, u_char eaddr)
{
int i;
outb(EEPROM_WR_EN, EWRK3_IOPR);
for (i = 0; i < 5000; i++)
inb(EWRK3_CSR);
outw(data, EWRK3_EPROM1);
outb((eaddr & 0x3f), EWRK3_PIR1);
outb(EEPROM_WR, EWRK3_IOPR);
for (i = 0; i < 75000; i++)
inb(EWRK3_CSR);
outb(EEPROM_WR_DIS, EWRK3_IOPR);
for (i = 0; i < 5000; i++)
inb(EWRK3_CSR);
return 0;
}
static void __init EthwrkSignature(char *name, char *eeprom_image)
{
int i;
char *signatures[] = EWRK3_SIGNATURE;
for (i=0; *signatures[i] != '\0'; i++)
if( !strncmp(eeprom_image+EEPROM_PNAME7, signatures[i], strlen(signatures[i])) )
break;
if (*signatures[i] != '\0') {
memcpy(name, eeprom_image+EEPROM_PNAME7, EWRK3_STRLEN);
name[EWRK3_STRLEN] = '\0';
} else
name[0] = '\0';
}
static int __init DevicePresent(u_long iobase)
{
union {
struct {
u32 a;
u32 b;
} llsig;
char Sig[sizeof(u32) << 1];
}
dev;
short sigLength;
char data;
int i, j, status = 0;
dev.llsig.a = ETH_PROM_SIG;
dev.llsig.b = ETH_PROM_SIG;
sigLength = sizeof(u32) << 1;
for (i = 0, j = 0; j < sigLength && i < PROBE_LENGTH + sigLength - 1; i++) {
data = inb(EWRK3_APROM);
if (dev.Sig[j] == data) {
j++;
} else {
if (data == dev.Sig[0]) {
j = 1;
} else {
j = 0;
}
}
}
if (j != sigLength) {
status = -ENODEV;
}
return status;
}
static u_char __init get_hw_addr(struct net_device *dev, u_char * eeprom_image, char chipType)
{
int i, j, k;
u_short chksum;
u_char crc, lfsr, sd, status = 0;
u_long iobase = dev->base_addr;
u16 tmp;
if (chipType == LeMAC2) {
for (crc = 0x6a, j = 0; j < ETH_ALEN; j++) {
sd = dev->dev_addr[j] = eeprom_image[EEPROM_PADDR0 + j];
outb(dev->dev_addr[j], EWRK3_PAR0 + j);
for (k = 0; k < 8; k++, sd >>= 1) {
lfsr = ((((crc & 0x02) >> 1) ^ (crc & 0x01)) ^ (sd & 0x01)) << 7;
crc = (crc >> 1) + lfsr;
}
}
if (crc != eeprom_image[EEPROM_PA_CRC])
status = -1;
} else {
for (i = 0, k = 0; i < ETH_ALEN;) {
k <<= 1;
if (k > 0xffff)
k -= 0xffff;
k += (u_char) (tmp = inb(EWRK3_APROM));
dev->dev_addr[i] = (u_char) tmp;
outb(dev->dev_addr[i], EWRK3_PAR0 + i);
i++;
k += (u_short) ((tmp = inb(EWRK3_APROM)) << 8);
dev->dev_addr[i] = (u_char) tmp;
outb(dev->dev_addr[i], EWRK3_PAR0 + i);
i++;
if (k > 0xffff)
k -= 0xffff;
}
if (k == 0xffff)
k = 0;
chksum = inb(EWRK3_APROM);
chksum |= (inb(EWRK3_APROM) << 8);
if (k != chksum)
status = -1;
}
return status;
}
static int __init EISA_signature(char *name, s32 eisa_id)
{
u_long i;
char *signatures[] = EWRK3_SIGNATURE;
char ManCode[EWRK3_STRLEN];
union {
s32 ID;
char Id[4];
} Eisa;
int status = 0;
*name = '\0';
for (i = 0; i < 4; i++) {
Eisa.Id[i] = inb(eisa_id + i);
}
ManCode[0] = (((Eisa.Id[0] >> 2) & 0x1f) + 0x40);
ManCode[1] = (((Eisa.Id[1] & 0xe0) >> 5) + ((Eisa.Id[0] & 0x03) << 3) + 0x40);
ManCode[2] = (((Eisa.Id[2] >> 4) & 0x0f) + 0x30);
ManCode[3] = ((Eisa.Id[2] & 0x0f) + 0x30);
ManCode[4] = (((Eisa.Id[3] >> 4) & 0x0f) + 0x30);
ManCode[5] = '\0';
for (i = 0; (*signatures[i] != '\0') && (*name == '\0'); i++) {
if (strstr(ManCode, signatures[i]) != NULL) {
strcpy(name, ManCode);
status = 1;
}
}
return status;
}
static void ewrk3_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
int fwrev = Read_EEPROM(dev->base_addr, EEPROM_REVLVL);
strcpy(info->driver, DRV_NAME);
strcpy(info->version, DRV_VERSION);
sprintf(info->fw_version, "%d", fwrev);
strcpy(info->bus_info, "N/A");
info->eedump_len = EEPROM_MAX;
}
static int ewrk3_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct ewrk3_private *lp = netdev_priv(dev);
unsigned long iobase = dev->base_addr;
u8 cr = inb(EWRK3_CR);
switch (lp->adapter_name[4]) {
case '3':
ecmd->supported = SUPPORTED_BNC;
ecmd->port = PORT_BNC;
break;
case '4':
ecmd->supported = SUPPORTED_TP;
ecmd->port = PORT_TP;
break;
case '5':
ecmd->supported = SUPPORTED_TP | SUPPORTED_BNC | SUPPORTED_AUI;
ecmd->autoneg = !(cr & CR_APD);
if (!ecmd->autoneg)
ecmd->port = (cr & CR_PSEL) ? PORT_BNC : PORT_TP;
break;
}
ecmd->supported |= SUPPORTED_10baseT_Half;
ethtool_cmd_speed_set(ecmd, SPEED_10);
ecmd->duplex = DUPLEX_HALF;
return 0;
}
static int ewrk3_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct ewrk3_private *lp = netdev_priv(dev);
unsigned long iobase = dev->base_addr;
unsigned long flags;
u8 cr;
if (lp->adapter_name[4] != '5')
return -EOPNOTSUPP;
if (ecmd->speed != SPEED_10)
return -EINVAL;
if (ecmd->port != PORT_TP && ecmd->port != PORT_BNC)
return -EINVAL;
if (ecmd->transceiver != XCVR_INTERNAL)
return -EINVAL;
if (ecmd->duplex != DUPLEX_HALF)
return -EINVAL;
if (ecmd->phy_address != 0)
return -EINVAL;
spin_lock_irqsave(&lp->hw_lock, flags);
cr = inb(EWRK3_CR);
if (ecmd->autoneg) {
cr &= ~CR_APD;
} else {
cr |= CR_APD;
if (ecmd->port == PORT_TP)
cr &= ~CR_PSEL;
else
cr |= CR_PSEL;
}
outb(cr, EWRK3_CR);
spin_unlock_irqrestore(&lp->hw_lock, flags);
return 0;
}
static u32 ewrk3_get_link(struct net_device *dev)
{
unsigned long iobase = dev->base_addr;
u8 cmr = inb(EWRK3_CMR);
return !(cmr & CMR_LINK);
}
static int ewrk3_set_phys_id(struct net_device *dev,
enum ethtool_phys_id_state state)
{
struct ewrk3_private *lp = netdev_priv(dev);
unsigned long iobase = dev->base_addr;
u8 cr;
spin_lock_irq(&lp->hw_lock);
switch (state) {
case ETHTOOL_ID_ACTIVE:
lp->led_mask = 0;
spin_unlock_irq(&lp->hw_lock);
return 2;
case ETHTOOL_ID_ON:
cr = inb(EWRK3_CR);
outb(cr | CR_LED, EWRK3_CR);
break;
case ETHTOOL_ID_OFF:
cr = inb(EWRK3_CR);
outb(cr & ~CR_LED, EWRK3_CR);
break;
case ETHTOOL_ID_INACTIVE:
lp->led_mask = CR_LED;
cr = inb(EWRK3_CR);
outb(cr & ~CR_LED, EWRK3_CR);
}
spin_unlock_irq(&lp->hw_lock);
return 0;
}
static int ewrk3_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct ewrk3_private *lp = netdev_priv(dev);
struct ewrk3_ioctl *ioc = (struct ewrk3_ioctl *) &rq->ifr_ifru;
u_long iobase = dev->base_addr;
int i, j, status = 0;
u_char csr;
unsigned long flags;
union ewrk3_addr {
u_char addr[HASH_TABLE_LEN * ETH_ALEN];
u_short val[(HASH_TABLE_LEN * ETH_ALEN) >> 1];
};
union ewrk3_addr *tmp;
if (cmd != EWRK3IOCTL)
return -EOPNOTSUPP;
tmp = kmalloc(sizeof(union ewrk3_addr), GFP_KERNEL);
if(tmp==NULL)
return -ENOMEM;
switch (ioc->cmd) {
case EWRK3_GET_HWADDR:
for (i = 0; i < ETH_ALEN; i++) {
tmp->addr[i] = dev->dev_addr[i];
}
ioc->len = ETH_ALEN;
if (copy_to_user(ioc->data, tmp->addr, ioc->len))
status = -EFAULT;
break;
case EWRK3_SET_HWADDR:
if (capable(CAP_NET_ADMIN)) {
spin_lock_irqsave(&lp->hw_lock, flags);
csr = inb(EWRK3_CSR);
csr |= (CSR_TXD | CSR_RXD);
outb(csr, EWRK3_CSR);
spin_unlock_irqrestore(&lp->hw_lock, flags);
if (copy_from_user(tmp->addr, ioc->data, ETH_ALEN)) {
status = -EFAULT;
break;
}
spin_lock_irqsave(&lp->hw_lock, flags);
for (i = 0; i < ETH_ALEN; i++) {
dev->dev_addr[i] = tmp->addr[i];
outb(tmp->addr[i], EWRK3_PAR0 + i);
}
csr = inb(EWRK3_CSR);
csr &= ~(CSR_TXD | CSR_RXD);
outb(csr, EWRK3_CSR);
spin_unlock_irqrestore(&lp->hw_lock, flags);
} else {
status = -EPERM;
}
break;
case EWRK3_SET_PROM:
if (capable(CAP_NET_ADMIN)) {
spin_lock_irqsave(&lp->hw_lock, flags);
csr = inb(EWRK3_CSR);
csr |= CSR_PME;
csr &= ~CSR_MCE;
outb(csr, EWRK3_CSR);
spin_unlock_irqrestore(&lp->hw_lock, flags);
} else {
status = -EPERM;
}
break;
case EWRK3_CLR_PROM:
if (capable(CAP_NET_ADMIN)) {
spin_lock_irqsave(&lp->hw_lock, flags);
csr = inb(EWRK3_CSR);
csr &= ~CSR_PME;
outb(csr, EWRK3_CSR);
spin_unlock_irqrestore(&lp->hw_lock, flags);
} else {
status = -EPERM;
}
break;
case EWRK3_GET_MCA:
spin_lock_irqsave(&lp->hw_lock, flags);
if (lp->shmem_length == IO_ONLY) {
outb(0, EWRK3_IOPR);
outw(PAGE0_HTE, EWRK3_PIR1);
for (i = 0; i < (HASH_TABLE_LEN >> 3); i++) {
tmp->addr[i] = inb(EWRK3_DATA);
}
} else {
outb(0, EWRK3_MPR);
memcpy_fromio(tmp->addr, lp->shmem + PAGE0_HTE, (HASH_TABLE_LEN >> 3));
}
spin_unlock_irqrestore(&lp->hw_lock, flags);
ioc->len = (HASH_TABLE_LEN >> 3);
if (copy_to_user(ioc->data, tmp->addr, ioc->len))
status = -EFAULT;
break;
case EWRK3_SET_MCA:
if (capable(CAP_NET_ADMIN)) {
if (ioc->len > HASH_TABLE_LEN) {
status = -EINVAL;
break;
}
if (copy_from_user(tmp->addr, ioc->data, ETH_ALEN * ioc->len)) {
status = -EFAULT;
break;
}
set_multicast_list(dev);
} else {
status = -EPERM;
}
break;
case EWRK3_CLR_MCA:
if (capable(CAP_NET_ADMIN)) {
set_multicast_list(dev);
} else {
status = -EPERM;
}
break;
case EWRK3_MCA_EN:
if (capable(CAP_NET_ADMIN)) {
spin_lock_irqsave(&lp->hw_lock, flags);
csr = inb(EWRK3_CSR);
csr |= CSR_MCE;
csr &= ~CSR_PME;
outb(csr, EWRK3_CSR);
spin_unlock_irqrestore(&lp->hw_lock, flags);
} else {
status = -EPERM;
}
break;
case EWRK3_GET_STATS: {
struct ewrk3_stats *tmp_stats =
kmalloc(sizeof(lp->pktStats), GFP_KERNEL);
if (!tmp_stats) {
status = -ENOMEM;
break;
}
spin_lock_irqsave(&lp->hw_lock, flags);
memcpy(tmp_stats, &lp->pktStats, sizeof(lp->pktStats));
spin_unlock_irqrestore(&lp->hw_lock, flags);
ioc->len = sizeof(lp->pktStats);
if (copy_to_user(ioc->data, tmp_stats, sizeof(lp->pktStats)))
status = -EFAULT;
kfree(tmp_stats);
break;
}
case EWRK3_CLR_STATS:
if (capable(CAP_NET_ADMIN)) {
spin_lock_irqsave(&lp->hw_lock, flags);
memset(&lp->pktStats, 0, sizeof(lp->pktStats));
spin_unlock_irqrestore(&lp->hw_lock,flags);
} else {
status = -EPERM;
}
break;
case EWRK3_GET_CSR:
tmp->addr[0] = inb(EWRK3_CSR);
ioc->len = 1;
if (copy_to_user(ioc->data, tmp->addr, ioc->len))
status = -EFAULT;
break;
case EWRK3_SET_CSR:
if (capable(CAP_NET_ADMIN)) {
if (copy_from_user(tmp->addr, ioc->data, 1)) {
status = -EFAULT;
break;
}
outb(tmp->addr[0], EWRK3_CSR);
} else {
status = -EPERM;
}
break;
case EWRK3_GET_EEPROM:
if (capable(CAP_NET_ADMIN)) {
for (i = 0; i < (EEPROM_MAX >> 1); i++) {
tmp->val[i] = (short) Read_EEPROM(iobase, i);
}
i = EEPROM_MAX;
tmp->addr[i++] = inb(EWRK3_CMR);
for (j = 0; j < ETH_ALEN; j++) {
tmp->addr[i++] = inb(EWRK3_PAR0 + j);
}
ioc->len = EEPROM_MAX + 1 + ETH_ALEN;
if (copy_to_user(ioc->data, tmp->addr, ioc->len))
status = -EFAULT;
} else {
status = -EPERM;
}
break;
case EWRK3_SET_EEPROM:
if (capable(CAP_NET_ADMIN)) {
if (copy_from_user(tmp->addr, ioc->data, EEPROM_MAX)) {
status = -EFAULT;
break;
}
for (i = 0; i < (EEPROM_MAX >> 1); i++) {
Write_EEPROM(tmp->val[i], iobase, i);
}
} else {
status = -EPERM;
}
break;
case EWRK3_GET_CMR:
tmp->addr[0] = inb(EWRK3_CMR);
ioc->len = 1;
if (copy_to_user(ioc->data, tmp->addr, ioc->len))
status = -EFAULT;
break;
case EWRK3_SET_TX_CUT_THRU:
if (capable(CAP_NET_ADMIN)) {
lp->txc = 1;
} else {
status = -EPERM;
}
break;
case EWRK3_CLR_TX_CUT_THRU:
if (capable(CAP_NET_ADMIN)) {
lp->txc = 0;
} else {
status = -EPERM;
}
break;
default:
status = -EOPNOTSUPP;
}
kfree(tmp);
return status;
}
static __exit void ewrk3_exit_module(void)
{
int i;
for( i=0; i<ndevs; i++ ) {
struct net_device *dev = ewrk3_devs[i];
struct ewrk3_private *lp = netdev_priv(dev);
ewrk3_devs[i] = NULL;
unregister_netdev(dev);
release_region(dev->base_addr, EWRK3_TOTAL_SIZE);
iounmap(lp->shmem);
free_netdev(dev);
}
}
static __init int ewrk3_init_module(void)
{
int i=0;
while( io[i] && irq[i] ) {
struct net_device *dev
= alloc_etherdev(sizeof(struct ewrk3_private));
if (!dev)
break;
if (ewrk3_probe1(dev, io[i], irq[i]) != 0) {
free_netdev(dev);
break;
}
ewrk3_devs[ndevs++] = dev;
i++;
}
return ndevs ? 0 : -EIO;
}
