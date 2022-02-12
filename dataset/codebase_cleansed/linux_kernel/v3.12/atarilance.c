static void *slow_memcpy( void *dst, const void *src, size_t len )
{ char *cto = dst;
const char *cfrom = src;
while( len-- ) {
*cto++ = *cfrom++;
MFPDELAY();
}
return dst;
}
struct net_device * __init atarilance_probe(int unit)
{
int i;
static int found;
struct net_device *dev;
int err = -ENODEV;
if (!MACH_IS_ATARI || found)
return ERR_PTR(-ENODEV);
dev = alloc_etherdev(sizeof(struct lance_private));
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
}
for( i = 0; i < N_LANCE_ADDR; ++i ) {
if (lance_probe1( dev, &lance_addr_list[i] )) {
found = 1;
err = register_netdev(dev);
if (!err)
return dev;
free_irq(dev->irq, dev);
break;
}
}
free_netdev(dev);
return ERR_PTR(err);
}
static noinline int __init addr_accessible(volatile void *regp, int wordflag,
int writeflag)
{
int ret;
unsigned long flags;
long *vbr, save_berr;
local_irq_save(flags);
__asm__ __volatile__ ( "movec %/vbr,%0" : "=r" (vbr) : );
save_berr = vbr[2];
__asm__ __volatile__
( "movel %/sp,%/d1\n\t"
"movel #Lberr,%2@\n\t"
"moveq #0,%0\n\t"
"tstl %3\n\t"
"bne 1f\n\t"
"moveb %1@,%/d0\n\t"
"nop \n\t"
"bra 2f\n"
"1: movew %1@,%/d0\n\t"
"nop \n"
"2: tstl %4\n\t"
"beq 2f\n\t"
"tstl %3\n\t"
"bne 1f\n\t"
"clrb %1@\n\t"
"nop \n\t"
"moveb %/d0,%1@\n\t"
"nop \n\t"
"bra 2f\n"
"1: clrw %1@\n\t"
"nop \n\t"
"movew %/d0,%1@\n\t"
"nop \n"
"2: moveq #1,%0\n"
"Lberr: movel %/d1,%/sp"
: "=&d" (ret)
: "a" (regp), "a" (&vbr[2]), "rm" (wordflag), "rm" (writeflag)
: "d0", "d1", "memory"
);
vbr[2] = save_berr;
local_irq_restore(flags);
return ret;
}
static unsigned long __init lance_probe1( struct net_device *dev,
struct lance_addr *init_rec )
{
volatile unsigned short *memaddr =
(volatile unsigned short *)init_rec->memaddr;
volatile unsigned short *ioaddr =
(volatile unsigned short *)init_rec->ioaddr;
struct lance_private *lp;
struct lance_ioreg *IO;
int i;
static int did_version;
unsigned short save1, save2;
PROBE_PRINT(( "Probing for Lance card at mem %#lx io %#lx\n",
(long)memaddr, (long)ioaddr ));
PROBE_PRINT(( "lance_probe1: testing memory to be accessible\n" ));
if (!addr_accessible( memaddr, 1, 1 )) goto probe_fail;
PROBE_PRINT(( "lance_probe1: testing memory to be writable (1)\n" ));
save1 = *memaddr;
*memaddr = 0x0001;
if (*memaddr != 0x0001) goto probe_fail;
PROBE_PRINT(( "lance_probe1: testing memory to be writable (2)\n" ));
*memaddr = 0x0000;
if (*memaddr != 0x0000) goto probe_fail;
*memaddr = save1;
PROBE_PRINT(( "lance_probe1: testing ioport to be accessible\n" ));
if (!addr_accessible( ioaddr, 1, 1 )) goto probe_fail;
PROBE_PRINT(( "lance_probe1: testing ioport to be writeable\n" ));
save2 = ioaddr[1];
ioaddr[1] = 0x0001;
if (ioaddr[1] != 0x0001) goto probe_fail;
PROBE_PRINT(( "lance_probe1: testing CSR0 register function (1)\n" ));
save1 = ioaddr[0];
ioaddr[1] = CSR0;
ioaddr[0] = CSR0_INIT | CSR0_STOP;
if (ioaddr[0] != CSR0_STOP) {
ioaddr[0] = save1;
ioaddr[1] = save2;
goto probe_fail;
}
PROBE_PRINT(( "lance_probe1: testing CSR0 register function (2)\n" ));
ioaddr[0] = CSR0_STOP;
if (ioaddr[0] != CSR0_STOP) {
ioaddr[0] = save1;
ioaddr[1] = save2;
goto probe_fail;
}
PROBE_PRINT(( "lance_probe1: Lance card detected\n" ));
goto probe_ok;
probe_fail:
return 0;
probe_ok:
lp = netdev_priv(dev);
MEM = (struct lance_memory *)memaddr;
IO = lp->iobase = (struct lance_ioreg *)ioaddr;
dev->base_addr = (unsigned long)ioaddr;
lp->memcpy_f = init_rec->slow_flag ? slow_memcpy : memcpy;
REGA( CSR0 ) = CSR0_STOP;
if (addr_accessible( &(IO->eeprom), 0, 0 )) {
i = IO->mem;
lp->cardtype = PAM_CARD;
}
else if (*RIEBL_MAGIC_ADDR == RIEBL_MAGIC) {
lp->cardtype = NEW_RIEBL;
}
else
lp->cardtype = OLD_RIEBL;
if (lp->cardtype == PAM_CARD ||
memaddr == (unsigned short *)0xffe00000) {
if (request_irq(IRQ_AUTO_5, lance_interrupt, IRQ_TYPE_PRIO,
"PAM,Riebl-ST Ethernet", dev)) {
printk( "Lance: request for irq %d failed\n", IRQ_AUTO_5 );
return 0;
}
dev->irq = IRQ_AUTO_5;
}
else {
unsigned int irq = atari_register_vme_int();
if (!irq) {
printk( "Lance: request for VME interrupt failed\n" );
return 0;
}
if (request_irq(irq, lance_interrupt, IRQ_TYPE_PRIO,
"Riebl-VME Ethernet", dev)) {
printk( "Lance: request for irq %u failed\n", irq );
return 0;
}
dev->irq = irq;
}
printk("%s: %s at io %#lx, mem %#lx, irq %d%s, hwaddr ",
dev->name, lance_names[lp->cardtype],
(unsigned long)ioaddr,
(unsigned long)memaddr,
dev->irq,
init_rec->slow_flag ? " (slow memcpy)" : "" );
switch( lp->cardtype ) {
case OLD_RIEBL:
memcpy( dev->dev_addr, OldRieblDefHwaddr, 6 );
break;
case NEW_RIEBL:
lp->memcpy_f( dev->dev_addr, RIEBL_HWADDR_ADDR, 6 );
break;
case PAM_CARD:
i = IO->eeprom;
for( i = 0; i < 6; ++i )
dev->dev_addr[i] =
((((unsigned short *)MEM)[i*2] & 0x0f) << 4) |
((((unsigned short *)MEM)[i*2+1] & 0x0f));
i = IO->mem;
break;
}
printk("%pM\n", dev->dev_addr);
if (lp->cardtype == OLD_RIEBL) {
printk( "%s: Warning: This is a default ethernet address!\n",
dev->name );
printk( " Use \"ifconfig hw ether ...\" to set the address.\n" );
}
spin_lock_init(&lp->devlock);
MEM->init.mode = 0x0000;
for( i = 0; i < 6; i++ )
MEM->init.hwaddr[i] = dev->dev_addr[i^1];
MEM->init.filter[0] = 0x00000000;
MEM->init.filter[1] = 0x00000000;
MEM->init.rx_ring.adr_lo = offsetof( struct lance_memory, rx_head );
MEM->init.rx_ring.adr_hi = 0;
MEM->init.rx_ring.len = RX_RING_LEN_BITS;
MEM->init.tx_ring.adr_lo = offsetof( struct lance_memory, tx_head );
MEM->init.tx_ring.adr_hi = 0;
MEM->init.tx_ring.len = TX_RING_LEN_BITS;
if (lp->cardtype == PAM_CARD)
IO->ivec = IRQ_SOURCE_TO_VECTOR(dev->irq);
else
*RIEBL_IVEC_ADDR = IRQ_SOURCE_TO_VECTOR(dev->irq);
if (did_version++ == 0)
DPRINTK( 1, ( version ));
dev->netdev_ops = &lance_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
return 1;
}
static int lance_open( struct net_device *dev )
{
struct lance_private *lp = netdev_priv(dev);
struct lance_ioreg *IO = lp->iobase;
int i;
DPRINTK( 2, ( "%s: lance_open()\n", dev->name ));
lance_init_ring(dev);
REGA( CSR3 ) = CSR3_BSWP | (lp->cardtype == PAM_CARD ? CSR3_ACON : 0);
REGA( CSR2 ) = 0;
REGA( CSR1 ) = 0;
REGA( CSR0 ) = CSR0_INIT;
i = 1000000;
while (--i > 0)
if (DREG & CSR0_IDON)
break;
if (i <= 0 || (DREG & CSR0_ERR)) {
DPRINTK( 2, ( "lance_open(): opening %s failed, i=%d, csr0=%04x\n",
dev->name, i, DREG ));
DREG = CSR0_STOP;
return -EIO;
}
DREG = CSR0_IDON;
DREG = CSR0_STRT;
DREG = CSR0_INEA;
netif_start_queue (dev);
DPRINTK( 2, ( "%s: LANCE is open, csr0 %04x\n", dev->name, DREG ));
return 0;
}
static void lance_init_ring( struct net_device *dev )
{
struct lance_private *lp = netdev_priv(dev);
int i;
unsigned offset;
lp->tx_full = 0;
lp->cur_rx = lp->cur_tx = 0;
lp->dirty_tx = 0;
offset = offsetof( struct lance_memory, packet_area );
#define CHECK_OFFSET(o) \
do { \
if (lp->cardtype == OLD_RIEBL || lp->cardtype == NEW_RIEBL) { \
if (((o) < RIEBL_RSVD_START) ? (o)+PKT_BUF_SZ > RIEBL_RSVD_START \
: (o) < RIEBL_RSVD_END) \
(o) = RIEBL_RSVD_END; \
} \
} while(0)
for( i = 0; i < TX_RING_SIZE; i++ ) {
CHECK_OFFSET(offset);
MEM->tx_head[i].base = offset;
MEM->tx_head[i].flag = TMD1_OWN_HOST;
MEM->tx_head[i].base_hi = 0;
MEM->tx_head[i].length = 0;
MEM->tx_head[i].misc = 0;
offset += PKT_BUF_SZ;
}
for( i = 0; i < RX_RING_SIZE; i++ ) {
CHECK_OFFSET(offset);
MEM->rx_head[i].base = offset;
MEM->rx_head[i].flag = TMD1_OWN_CHIP;
MEM->rx_head[i].base_hi = 0;
MEM->rx_head[i].buf_length = -PKT_BUF_SZ;
MEM->rx_head[i].msg_length = 0;
offset += PKT_BUF_SZ;
}
}
static void lance_tx_timeout (struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
struct lance_ioreg *IO = lp->iobase;
AREG = CSR0;
DPRINTK( 1, ( "%s: transmit timed out, status %04x, resetting.\n",
dev->name, DREG ));
DREG = CSR0_STOP;
REGA( CSR3 ) = CSR3_BSWP | (lp->cardtype == PAM_CARD ? CSR3_ACON : 0);
dev->stats.tx_errors++;
#ifndef final_version
{ int i;
DPRINTK( 2, ( "Ring data: dirty_tx %d cur_tx %d%s cur_rx %d\n",
lp->dirty_tx, lp->cur_tx,
lp->tx_full ? " (full)" : "",
lp->cur_rx ));
for( i = 0 ; i < RX_RING_SIZE; i++ )
DPRINTK( 2, ( "rx #%d: base=%04x blen=%04x mlen=%04x\n",
i, MEM->rx_head[i].base,
-MEM->rx_head[i].buf_length,
MEM->rx_head[i].msg_length ));
for( i = 0 ; i < TX_RING_SIZE; i++ )
DPRINTK( 2, ( "tx #%d: base=%04x len=%04x misc=%04x\n",
i, MEM->tx_head[i].base,
-MEM->tx_head[i].length,
MEM->tx_head[i].misc ));
}
#endif
lance_init_ring(dev);
REGA( CSR0 ) = CSR0_INEA | CSR0_INIT | CSR0_STRT;
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
static int lance_start_xmit( struct sk_buff *skb, struct net_device *dev )
{
struct lance_private *lp = netdev_priv(dev);
struct lance_ioreg *IO = lp->iobase;
int entry, len;
struct lance_tx_head *head;
unsigned long flags;
DPRINTK( 2, ( "%s: lance_start_xmit() called, csr0 %4.4x.\n",
dev->name, DREG ));
len = skb->len;
if (len < ETH_ZLEN)
len = ETH_ZLEN;
else if (lp->cardtype == PAM_CARD && (len & 1))
++len;
if (len > skb->len) {
if (skb_padto(skb, len))
return NETDEV_TX_OK;
}
netif_stop_queue (dev);
if (lance_debug >= 3) {
printk( "%s: TX pkt type 0x%04x from %pM to %pM"
" data at 0x%08x len %d\n",
dev->name, ((u_short *)skb->data)[6],
&skb->data[6], skb->data,
(int)skb->data, (int)skb->len );
}
spin_lock_irqsave (&lp->devlock, flags);
entry = lp->cur_tx & TX_RING_MOD_MASK;
head = &(MEM->tx_head[entry]);
head->length = -len;
head->misc = 0;
lp->memcpy_f( PKTBUF_ADDR(head), (void *)skb->data, skb->len );
head->flag = TMD1_OWN_CHIP | TMD1_ENP | TMD1_STP;
dev->stats.tx_bytes += skb->len;
dev_kfree_skb( skb );
lp->cur_tx++;
while( lp->cur_tx >= TX_RING_SIZE && lp->dirty_tx >= TX_RING_SIZE ) {
lp->cur_tx -= TX_RING_SIZE;
lp->dirty_tx -= TX_RING_SIZE;
}
DREG = CSR0_INEA | CSR0_TDMD;
if ((MEM->tx_head[(entry+1) & TX_RING_MOD_MASK].flag & TMD1_OWN) ==
TMD1_OWN_HOST)
netif_start_queue (dev);
else
lp->tx_full = 1;
spin_unlock_irqrestore (&lp->devlock, flags);
return NETDEV_TX_OK;
}
static irqreturn_t lance_interrupt( int irq, void *dev_id )
{
struct net_device *dev = dev_id;
struct lance_private *lp;
struct lance_ioreg *IO;
int csr0, boguscnt = 10;
int handled = 0;
if (dev == NULL) {
DPRINTK( 1, ( "lance_interrupt(): interrupt for unknown device.\n" ));
return IRQ_NONE;
}
lp = netdev_priv(dev);
IO = lp->iobase;
spin_lock (&lp->devlock);
AREG = CSR0;
while( ((csr0 = DREG) & (CSR0_ERR | CSR0_TINT | CSR0_RINT)) &&
--boguscnt >= 0) {
handled = 1;
DREG = csr0 & ~(CSR0_INIT | CSR0_STRT | CSR0_STOP |
CSR0_TDMD | CSR0_INEA);
DPRINTK( 2, ( "%s: interrupt csr0=%04x new csr=%04x.\n",
dev->name, csr0, DREG ));
if (csr0 & CSR0_RINT)
lance_rx( dev );
if (csr0 & CSR0_TINT) {
int dirty_tx = lp->dirty_tx;
while( dirty_tx < lp->cur_tx) {
int entry = dirty_tx & TX_RING_MOD_MASK;
int status = MEM->tx_head[entry].flag;
if (status & TMD1_OWN_CHIP)
break;
MEM->tx_head[entry].flag = 0;
if (status & TMD1_ERR) {
int err_status = MEM->tx_head[entry].misc;
dev->stats.tx_errors++;
if (err_status & TMD3_RTRY) dev->stats.tx_aborted_errors++;
if (err_status & TMD3_LCAR) dev->stats.tx_carrier_errors++;
if (err_status & TMD3_LCOL) dev->stats.tx_window_errors++;
if (err_status & TMD3_UFLO) {
dev->stats.tx_fifo_errors++;
DPRINTK( 1, ( "%s: Tx FIFO error! Status %04x\n",
dev->name, csr0 ));
DREG = CSR0_STRT;
}
} else {
if (status & (TMD1_MORE | TMD1_ONE | TMD1_DEF))
dev->stats.collisions++;
dev->stats.tx_packets++;
}
dirty_tx++;
}
#ifndef final_version
if (lp->cur_tx - dirty_tx >= TX_RING_SIZE) {
DPRINTK( 0, ( "out-of-sync dirty pointer,"
" %d vs. %d, full=%ld.\n",
dirty_tx, lp->cur_tx, lp->tx_full ));
dirty_tx += TX_RING_SIZE;
}
#endif
if (lp->tx_full && (netif_queue_stopped(dev)) &&
dirty_tx > lp->cur_tx - TX_RING_SIZE + 2) {
lp->tx_full = 0;
netif_wake_queue (dev);
}
lp->dirty_tx = dirty_tx;
}
if (csr0 & CSR0_BABL) dev->stats.tx_errors++;
if (csr0 & CSR0_MISS) dev->stats.rx_errors++;
if (csr0 & CSR0_MERR) {
DPRINTK( 1, ( "%s: Bus master arbitration failure (?!?), "
"status %04x.\n", dev->name, csr0 ));
DREG = CSR0_STRT;
}
}
DREG = CSR0_BABL | CSR0_CERR | CSR0_MISS | CSR0_MERR |
CSR0_IDON | CSR0_INEA;
DPRINTK( 2, ( "%s: exiting interrupt, csr0=%#04x.\n",
dev->name, DREG ));
spin_unlock (&lp->devlock);
return IRQ_RETVAL(handled);
}
static int lance_rx( struct net_device *dev )
{
struct lance_private *lp = netdev_priv(dev);
int entry = lp->cur_rx & RX_RING_MOD_MASK;
int i;
DPRINTK( 2, ( "%s: rx int, flag=%04x\n", dev->name,
MEM->rx_head[entry].flag ));
while( (MEM->rx_head[entry].flag & RMD1_OWN) == RMD1_OWN_HOST ) {
struct lance_rx_head *head = &(MEM->rx_head[entry]);
int status = head->flag;
if (status != (RMD1_ENP|RMD1_STP)) {
if (status & RMD1_ENP)
dev->stats.rx_errors++;
if (status & RMD1_FRAM) dev->stats.rx_frame_errors++;
if (status & RMD1_OFLO) dev->stats.rx_over_errors++;
if (status & RMD1_CRC) dev->stats.rx_crc_errors++;
if (status & RMD1_BUFF) dev->stats.rx_fifo_errors++;
head->flag &= (RMD1_ENP|RMD1_STP);
} else {
short pkt_len = head->msg_length & 0xfff;
struct sk_buff *skb;
if (pkt_len < 60) {
printk( "%s: Runt packet!\n", dev->name );
dev->stats.rx_errors++;
}
else {
skb = netdev_alloc_skb(dev, pkt_len + 2);
if (skb == NULL) {
for( i = 0; i < RX_RING_SIZE; i++ )
if (MEM->rx_head[(entry+i) & RX_RING_MOD_MASK].flag &
RMD1_OWN_CHIP)
break;
if (i > RX_RING_SIZE - 2) {
dev->stats.rx_dropped++;
head->flag |= RMD1_OWN_CHIP;
lp->cur_rx++;
}
break;
}
if (lance_debug >= 3) {
u_char *data = PKTBUF_ADDR(head);
printk(KERN_DEBUG "%s: RX pkt type 0x%04x from %pM to %pM "
"data %02x %02x %02x %02x %02x %02x %02x %02x "
"len %d\n",
dev->name, ((u_short *)data)[6],
&data[6], data,
data[15], data[16], data[17], data[18],
data[19], data[20], data[21], data[22],
pkt_len);
}
skb_reserve( skb, 2 );
skb_put( skb, pkt_len );
lp->memcpy_f( skb->data, PKTBUF_ADDR(head), pkt_len );
skb->protocol = eth_type_trans( skb, dev );
netif_rx( skb );
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
}
head->flag |= RMD1_OWN_CHIP;
entry = (++lp->cur_rx) & RX_RING_MOD_MASK;
}
lp->cur_rx &= RX_RING_MOD_MASK;
return 0;
}
static int lance_close( struct net_device *dev )
{
struct lance_private *lp = netdev_priv(dev);
struct lance_ioreg *IO = lp->iobase;
netif_stop_queue (dev);
AREG = CSR0;
DPRINTK( 2, ( "%s: Shutting down ethercard, status was %2.2x.\n",
dev->name, DREG ));
DREG = CSR0_STOP;
return 0;
}
static void set_multicast_list( struct net_device *dev )
{
struct lance_private *lp = netdev_priv(dev);
struct lance_ioreg *IO = lp->iobase;
if (netif_running(dev))
return;
DREG = CSR0_STOP;
if (dev->flags & IFF_PROMISC) {
DPRINTK( 2, ( "%s: Promiscuous mode enabled.\n", dev->name ));
REGA( CSR15 ) = 0x8000;
} else {
short multicast_table[4];
int num_addrs = netdev_mc_count(dev);
int i;
memset( multicast_table, (num_addrs == 0) ? 0 : -1,
sizeof(multicast_table) );
for( i = 0; i < 4; i++ )
REGA( CSR8+i ) = multicast_table[i];
REGA( CSR15 ) = 0;
}
REGA( CSR3 ) = CSR3_BSWP | (lp->cardtype == PAM_CARD ? CSR3_ACON : 0);
REGA( CSR0 ) = CSR0_IDON | CSR0_INEA | CSR0_STRT;
}
static int lance_set_mac_address( struct net_device *dev, void *addr )
{
struct lance_private *lp = netdev_priv(dev);
struct sockaddr *saddr = addr;
int i;
if (lp->cardtype != OLD_RIEBL && lp->cardtype != NEW_RIEBL)
return -EOPNOTSUPP;
if (netif_running(dev)) {
DPRINTK( 1, ( "%s: hwaddr can be set only while card isn't open.\n",
dev->name ));
return -EIO;
}
memcpy( dev->dev_addr, saddr->sa_data, dev->addr_len );
for( i = 0; i < 6; i++ )
MEM->init.hwaddr[i] = dev->dev_addr[i^1];
lp->memcpy_f( RIEBL_HWADDR_ADDR, dev->dev_addr, 6 );
*RIEBL_MAGIC_ADDR = RIEBL_MAGIC;
return 0;
}
static int __init atarilance_module_init(void)
{
atarilance_dev = atarilance_probe(-1);
return PTR_ERR_OR_ZERO(atarilance_dev);
}
static void __exit atarilance_module_exit(void)
{
unregister_netdev(atarilance_dev);
free_irq(atarilance_dev->irq, atarilance_dev);
free_netdev(atarilance_dev);
}
