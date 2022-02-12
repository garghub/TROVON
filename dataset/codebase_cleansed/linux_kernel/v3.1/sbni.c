static inline int __init
sbni_isa_probe( struct net_device *dev )
{
if( dev->base_addr > 0x1ff &&
request_region( dev->base_addr, SBNI_IO_EXTENT, dev->name ) &&
sbni_probe1( dev, dev->base_addr, dev->irq ) )
return 0;
else {
pr_err("base address 0x%lx is busy, or adapter is malfunctional!\n",
dev->base_addr);
return -ENODEV;
}
}
static void __init sbni_devsetup(struct net_device *dev)
{
ether_setup( dev );
dev->netdev_ops = &sbni_netdev_ops;
}
int __init sbni_probe(int unit)
{
struct net_device *dev;
int err;
dev = alloc_netdev(sizeof(struct net_local), "sbni", sbni_devsetup);
if (!dev)
return -ENOMEM;
dev->netdev_ops = &sbni_netdev_ops;
sprintf(dev->name, "sbni%d", unit);
netdev_boot_setup_check(dev);
err = sbni_init(dev);
if (err) {
free_netdev(dev);
return err;
}
err = register_netdev(dev);
if (err) {
release_region( dev->base_addr, SBNI_IO_EXTENT );
free_netdev(dev);
return err;
}
pr_info_once("%s", version);
return 0;
}
static int __init sbni_init(struct net_device *dev)
{
int i;
if( dev->base_addr )
return sbni_isa_probe( dev );
if( io[ num ] != -1 )
dev->base_addr = io[ num ],
dev->irq = irq[ num ];
else if( scandone || io[ 0 ] != -1 )
return -ENODEV;
if( dev->base_addr )
return sbni_isa_probe( dev );
if( !skip_pci_probe && !sbni_pci_probe( dev ) )
return 0;
if( io[ num ] == -1 ) {
scandone = 1;
if( num > 0 )
return -ENODEV;
}
for( i = 0; netcard_portlist[ i ]; ++i ) {
int ioaddr = netcard_portlist[ i ];
if( request_region( ioaddr, SBNI_IO_EXTENT, dev->name ) &&
sbni_probe1( dev, ioaddr, 0 ))
return 0;
}
return -ENODEV;
}
static int __init
sbni_pci_probe( struct net_device *dev )
{
struct pci_dev *pdev = NULL;
while( (pdev = pci_get_class( PCI_CLASS_NETWORK_OTHER << 8, pdev ))
!= NULL ) {
int pci_irq_line;
unsigned long pci_ioaddr;
if( pdev->vendor != SBNI_PCI_VENDOR &&
pdev->device != SBNI_PCI_DEVICE )
continue;
pci_ioaddr = pci_resource_start( pdev, 0 );
pci_irq_line = pdev->irq;
if( !request_region( pci_ioaddr, SBNI_IO_EXTENT, dev->name ) ) {
if (pdev->subsystem_device != 2)
continue;
if (!request_region(pci_ioaddr += 4, SBNI_IO_EXTENT,
dev->name ) )
continue;
}
if (pci_irq_line <= 0 || pci_irq_line >= nr_irqs)
pr_warn(
"WARNING: The PCI BIOS assigned this PCI card to IRQ %d, which is unlikely to work!.\n"
"You should use the PCI BIOS setup to assign a valid IRQ line.\n",
pci_irq_line );
if( (pci_ioaddr & 7) == 0 && pci_enable_device( pdev ) ) {
release_region( pci_ioaddr, SBNI_IO_EXTENT );
pci_dev_put( pdev );
return -EIO;
}
if( sbni_probe1( dev, pci_ioaddr, pci_irq_line ) ) {
SET_NETDEV_DEV(dev, &pdev->dev);
pci_dev_put( pdev );
return 0;
}
}
return -ENODEV;
}
static struct net_device * __init
sbni_probe1( struct net_device *dev, unsigned long ioaddr, int irq )
{
struct net_local *nl;
if( sbni_card_probe( ioaddr ) ) {
release_region( ioaddr, SBNI_IO_EXTENT );
return NULL;
}
outb( 0, ioaddr + CSR0 );
if( irq < 2 ) {
unsigned long irq_mask;
irq_mask = probe_irq_on();
outb( EN_INT | TR_REQ, ioaddr + CSR0 );
outb( PR_RES, ioaddr + CSR1 );
mdelay(50);
irq = probe_irq_off(irq_mask);
outb( 0, ioaddr + CSR0 );
if( !irq ) {
pr_err("%s: can't detect device irq!\n", dev->name);
release_region( ioaddr, SBNI_IO_EXTENT );
return NULL;
}
} else if( irq == 2 )
irq = 9;
dev->irq = irq;
dev->base_addr = ioaddr;
nl = netdev_priv(dev);
if( !nl ) {
pr_err("%s: unable to get memory!\n", dev->name);
release_region( ioaddr, SBNI_IO_EXTENT );
return NULL;
}
memset( nl, 0, sizeof(struct net_local) );
spin_lock_init( &nl->lock );
*(__be16 *)dev->dev_addr = htons( 0x00ff );
*(__be32 *)(dev->dev_addr + 2) = htonl( 0x01000000 |
((mac[num] ?
mac[num] :
(u32)((long)netdev_priv(dev))) & 0x00ffffff));
nl->maxframe = DEFAULT_FRAME_LEN;
nl->csr1.rate = baud[ num ];
if( (nl->cur_rxl_index = rxl[ num ]) == -1 )
nl->cur_rxl_index = DEF_RXL,
nl->delta_rxl = DEF_RXL_DELTA;
else
nl->delta_rxl = 0;
nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index ];
if( inb( ioaddr + CSR0 ) & 0x01 )
nl->state |= FL_SLOW_MODE;
pr_notice("%s: ioaddr %#lx, irq %d, MAC: 00:ff:01:%02x:%02x:%02x\n",
dev->name, dev->base_addr, dev->irq,
((u8 *)dev->dev_addr)[3],
((u8 *)dev->dev_addr)[4],
((u8 *)dev->dev_addr)[5]);
pr_notice("%s: speed %d",
dev->name,
((nl->state & FL_SLOW_MODE) ? 500000 : 2000000)
/ (1 << nl->csr1.rate));
if( nl->delta_rxl == 0 )
pr_cont(", receive level 0x%x (fixed)\n", nl->cur_rxl_index);
else
pr_cont(", receive level (auto)\n");
#ifdef CONFIG_SBNI_MULTILINE
nl->master = dev;
nl->link = NULL;
#endif
sbni_cards[ num++ ] = dev;
return dev;
}
static netdev_tx_t
sbni_start_xmit( struct sk_buff *skb, struct net_device *dev )
{
struct net_device *p;
netif_stop_queue( dev );
for( p = dev; p; ) {
struct net_local *nl = netdev_priv(p);
spin_lock( &nl->lock );
if( nl->tx_buf_p || (nl->state & FL_LINE_DOWN) ) {
p = nl->link;
spin_unlock( &nl->lock );
} else {
prepare_to_send( skb, p );
spin_unlock( &nl->lock );
netif_start_queue( dev );
return NETDEV_TX_OK;
}
}
return NETDEV_TX_BUSY;
}
static netdev_tx_t
sbni_start_xmit( struct sk_buff *skb, struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
netif_stop_queue( dev );
spin_lock( &nl->lock );
prepare_to_send( skb, dev );
spin_unlock( &nl->lock );
return NETDEV_TX_OK;
}
static irqreturn_t
sbni_interrupt( int irq, void *dev_id )
{
struct net_device *dev = dev_id;
struct net_local *nl = netdev_priv(dev);
int repeat;
spin_lock( &nl->lock );
if( nl->second )
spin_lock(&NET_LOCAL_LOCK(nl->second));
do {
repeat = 0;
if( inb( dev->base_addr + CSR0 ) & (RC_RDY | TR_RDY) )
handle_channel( dev ),
repeat = 1;
if( nl->second &&
(inb( nl->second->base_addr+CSR0 ) & (RC_RDY | TR_RDY)) )
handle_channel( nl->second ),
repeat = 1;
} while( repeat );
if( nl->second )
spin_unlock(&NET_LOCAL_LOCK(nl->second));
spin_unlock( &nl->lock );
return IRQ_HANDLED;
}
static void
handle_channel( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
unsigned long ioaddr = dev->base_addr;
int req_ans;
unsigned char csr0;
#ifdef CONFIG_SBNI_MULTILINE
if( nl->state & FL_SLAVE )
spin_lock(&NET_LOCAL_LOCK(nl->master));
#endif
outb( (inb( ioaddr + CSR0 ) & ~EN_INT) | TR_REQ, ioaddr + CSR0 );
nl->timer_ticks = CHANGE_LEVEL_START_TICKS;
for(;;) {
csr0 = inb( ioaddr + CSR0 );
if( ( csr0 & (RC_RDY | TR_RDY) ) == 0 )
break;
req_ans = !(nl->state & FL_PREV_OK);
if( csr0 & RC_RDY )
req_ans = recv_frame( dev );
csr0 = inb( ioaddr + CSR0 );
if( !(csr0 & TR_RDY) || (csr0 & RC_RDY) )
netdev_err(dev, "internal error!\n");
if( req_ans || nl->tx_frameno != 0 )
send_frame( dev );
else
outb( inb( ioaddr + CSR0 ) & ~TR_REQ, ioaddr + CSR0 );
}
outb( inb( ioaddr + CSR0 ) | EN_INT, ioaddr + CSR0 );
#ifdef CONFIG_SBNI_MULTILINE
if( nl->state & FL_SLAVE )
spin_unlock(&NET_LOCAL_LOCK(nl->master));
#endif
}
static int
recv_frame( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
unsigned long ioaddr = dev->base_addr;
u32 crc = CRC32_INITIAL;
unsigned framelen = 0, frameno, ack;
unsigned is_first, frame_ok = 0;
if( check_fhdr( ioaddr, &framelen, &frameno, &ack, &is_first, &crc ) ) {
frame_ok = framelen > 4
? upload_data( dev, framelen, frameno, is_first, crc )
: skip_tail( ioaddr, framelen, crc );
if( frame_ok )
interpret_ack( dev, ack );
}
outb( inb( ioaddr + CSR0 ) ^ CT_ZER, ioaddr + CSR0 );
if( frame_ok ) {
nl->state |= FL_PREV_OK;
if( framelen > 4 )
nl->in_stats.all_rx_number++;
} else
nl->state &= ~FL_PREV_OK,
change_level( dev ),
nl->in_stats.all_rx_number++,
nl->in_stats.bad_rx_number++;
return !frame_ok || framelen > 4;
}
static void
send_frame( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
u32 crc = CRC32_INITIAL;
if( nl->state & FL_NEED_RESEND ) {
if( nl->trans_errors ) {
--nl->trans_errors;
if( nl->framelen != 0 )
nl->in_stats.resend_tx_number++;
} else {
#ifdef CONFIG_SBNI_MULTILINE
if( (nl->state & FL_SLAVE) || nl->link )
#endif
nl->state |= FL_LINE_DOWN;
drop_xmit_queue( dev );
goto do_send;
}
} else
nl->trans_errors = TR_ERROR_COUNT;
send_frame_header( dev, &crc );
nl->state |= FL_NEED_RESEND;
if( nl->framelen ) {
download_data( dev, &crc );
nl->in_stats.all_tx_number++;
nl->state |= FL_WAIT_ACK;
}
outsb( dev->base_addr + DAT, (u8 *)&crc, sizeof crc );
do_send:
outb( inb( dev->base_addr + CSR0 ) & ~TR_REQ, dev->base_addr + CSR0 );
if( nl->tx_frameno )
outb( inb( dev->base_addr + CSR0 ) | TR_REQ,
dev->base_addr + CSR0 );
}
static void
download_data( struct net_device *dev, u32 *crc_p )
{
struct net_local *nl = netdev_priv(dev);
struct sk_buff *skb = nl->tx_buf_p;
unsigned len = min_t(unsigned int, skb->len - nl->outpos, nl->framelen);
outsb( dev->base_addr + DAT, skb->data + nl->outpos, len );
*crc_p = calc_crc32( *crc_p, skb->data + nl->outpos, len );
for( len = nl->framelen - len; len--; )
outb( 0, dev->base_addr + DAT ),
*crc_p = CRC32( 0, *crc_p );
}
static int
upload_data( struct net_device *dev, unsigned framelen, unsigned frameno,
unsigned is_first, u32 crc )
{
struct net_local *nl = netdev_priv(dev);
int frame_ok;
if( is_first )
nl->wait_frameno = frameno,
nl->inppos = 0;
if( nl->wait_frameno == frameno ) {
if( nl->inppos + framelen <= ETHER_MAX_LEN )
frame_ok = append_frame_to_pkt( dev, framelen, crc );
else if( (frame_ok = skip_tail( dev->base_addr, framelen, crc ))
!= 0 )
nl->wait_frameno = 0,
nl->inppos = 0,
#ifdef CONFIG_SBNI_MULTILINE
nl->master->stats.rx_errors++,
nl->master->stats.rx_missed_errors++;
#else
dev->stats.rx_errors++,
dev->stats.rx_missed_errors++;
#endif
} else
frame_ok = skip_tail( dev->base_addr, framelen, crc );
if( is_first && !frame_ok )
nl->wait_frameno = 0,
#ifdef CONFIG_SBNI_MULTILINE
nl->master->stats.rx_errors++,
nl->master->stats.rx_crc_errors++;
#else
dev->stats.rx_errors++,
dev->stats.rx_crc_errors++;
#endif
return frame_ok;
}
static inline void
send_complete( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
#ifdef CONFIG_SBNI_MULTILINE
nl->master->stats.tx_packets++;
nl->master->stats.tx_bytes += nl->tx_buf_p->len;
#else
dev->stats.tx_packets++;
dev->stats.tx_bytes += nl->tx_buf_p->len;
#endif
dev_kfree_skb_irq( nl->tx_buf_p );
nl->tx_buf_p = NULL;
nl->outpos = 0;
nl->state &= ~(FL_WAIT_ACK | FL_NEED_RESEND);
nl->framelen = 0;
}
static void
interpret_ack( struct net_device *dev, unsigned ack )
{
struct net_local *nl = netdev_priv(dev);
if( ack == FRAME_SENT_OK ) {
nl->state &= ~FL_NEED_RESEND;
if( nl->state & FL_WAIT_ACK ) {
nl->outpos += nl->framelen;
if( --nl->tx_frameno )
nl->framelen = min_t(unsigned int,
nl->maxframe,
nl->tx_buf_p->len - nl->outpos);
else
send_complete( dev ),
#ifdef CONFIG_SBNI_MULTILINE
netif_wake_queue( nl->master );
#else
netif_wake_queue( dev );
#endif
}
}
nl->state &= ~FL_WAIT_ACK;
}
static int
append_frame_to_pkt( struct net_device *dev, unsigned framelen, u32 crc )
{
struct net_local *nl = netdev_priv(dev);
u8 *p;
if( nl->inppos + framelen > ETHER_MAX_LEN )
return 0;
if( !nl->rx_buf_p && !(nl->rx_buf_p = get_rx_buf( dev )) )
return 0;
p = nl->rx_buf_p->data + nl->inppos;
insb( dev->base_addr + DAT, p, framelen );
if( calc_crc32( crc, p, framelen ) != CRC32_REMAINDER )
return 0;
nl->inppos += framelen - 4;
if( --nl->wait_frameno == 0 )
indicate_pkt( dev );
return 1;
}
static void
prepare_to_send( struct sk_buff *skb, struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
unsigned int len;
if( nl->tx_buf_p )
netdev_err(dev, "memory leak!\n");
nl->outpos = 0;
nl->state &= ~(FL_WAIT_ACK | FL_NEED_RESEND);
len = skb->len;
if( len < SBNI_MIN_LEN )
len = SBNI_MIN_LEN;
nl->tx_buf_p = skb;
nl->tx_frameno = DIV_ROUND_UP(len, nl->maxframe);
nl->framelen = len < nl->maxframe ? len : nl->maxframe;
outb( inb( dev->base_addr + CSR0 ) | TR_REQ, dev->base_addr + CSR0 );
#ifdef CONFIG_SBNI_MULTILINE
nl->master->trans_start = jiffies;
#else
dev->trans_start = jiffies;
#endif
}
static void
drop_xmit_queue( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
if( nl->tx_buf_p )
dev_kfree_skb_any( nl->tx_buf_p ),
nl->tx_buf_p = NULL,
#ifdef CONFIG_SBNI_MULTILINE
nl->master->stats.tx_errors++,
nl->master->stats.tx_carrier_errors++;
#else
dev->stats.tx_errors++,
dev->stats.tx_carrier_errors++;
#endif
nl->tx_frameno = 0;
nl->framelen = 0;
nl->outpos = 0;
nl->state &= ~(FL_WAIT_ACK | FL_NEED_RESEND);
#ifdef CONFIG_SBNI_MULTILINE
netif_start_queue( nl->master );
nl->master->trans_start = jiffies;
#else
netif_start_queue( dev );
dev->trans_start = jiffies;
#endif
}
static void
send_frame_header( struct net_device *dev, u32 *crc_p )
{
struct net_local *nl = netdev_priv(dev);
u32 crc = *crc_p;
u32 len_field = nl->framelen + 6;
u8 value;
if( nl->state & FL_NEED_RESEND )
len_field |= FRAME_RETRY;
if( nl->outpos == 0 )
len_field |= FRAME_FIRST;
len_field |= (nl->state & FL_PREV_OK) ? FRAME_SENT_OK : FRAME_SENT_BAD;
outb( SBNI_SIG, dev->base_addr + DAT );
value = (u8) len_field;
outb( value, dev->base_addr + DAT );
crc = CRC32( value, crc );
value = (u8) (len_field >> 8);
outb( value, dev->base_addr + DAT );
crc = CRC32( value, crc );
outb( nl->tx_frameno, dev->base_addr + DAT );
crc = CRC32( nl->tx_frameno, crc );
outb( 0, dev->base_addr + DAT );
crc = CRC32( 0, crc );
*crc_p = crc;
}
static int
skip_tail( unsigned int ioaddr, unsigned int tail_len, u32 crc )
{
while( tail_len-- )
crc = CRC32( inb( ioaddr + DAT ), crc );
return crc == CRC32_REMAINDER;
}
static int
check_fhdr( u32 ioaddr, u32 *framelen, u32 *frameno, u32 *ack,
u32 *is_first, u32 *crc_p )
{
u32 crc = *crc_p;
u8 value;
if( inb( ioaddr + DAT ) != SBNI_SIG )
return 0;
value = inb( ioaddr + DAT );
*framelen = (u32)value;
crc = CRC32( value, crc );
value = inb( ioaddr + DAT );
*framelen |= ((u32)value) << 8;
crc = CRC32( value, crc );
*ack = *framelen & FRAME_ACK_MASK;
*is_first = (*framelen & FRAME_FIRST) != 0;
if( (*framelen &= FRAME_LEN_MASK) < 6 ||
*framelen > SBNI_MAX_FRAME - 3 )
return 0;
value = inb( ioaddr + DAT );
*frameno = (u32)value;
crc = CRC32( value, crc );
crc = CRC32( inb( ioaddr + DAT ), crc );
*framelen -= 2;
*crc_p = crc;
return 1;
}
static struct sk_buff *
get_rx_buf( struct net_device *dev )
{
struct sk_buff *skb = dev_alloc_skb( ETHER_MAX_LEN + 2 );
if( !skb )
return NULL;
skb_reserve( skb, 2 );
return skb;
}
static void
indicate_pkt( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
struct sk_buff *skb = nl->rx_buf_p;
skb_put( skb, nl->inppos );
#ifdef CONFIG_SBNI_MULTILINE
skb->protocol = eth_type_trans( skb, nl->master );
netif_rx( skb );
++nl->master->stats.rx_packets;
nl->master->stats.rx_bytes += nl->inppos;
#else
skb->protocol = eth_type_trans( skb, dev );
netif_rx( skb );
++dev->stats.rx_packets;
dev->stats.rx_bytes += nl->inppos;
#endif
nl->rx_buf_p = NULL;
}
static void
sbni_watchdog( unsigned long arg )
{
struct net_device *dev = (struct net_device *) arg;
struct net_local *nl = netdev_priv(dev);
struct timer_list *w = &nl->watchdog;
unsigned long flags;
unsigned char csr0;
spin_lock_irqsave( &nl->lock, flags );
csr0 = inb( dev->base_addr + CSR0 );
if( csr0 & RC_CHK ) {
if( nl->timer_ticks ) {
if( csr0 & (RC_RDY | BU_EMP) )
nl->timer_ticks--;
} else {
nl->in_stats.timeout_number++;
if( nl->delta_rxl )
timeout_change_level( dev );
outb( *(u_char *)&nl->csr1 | PR_RES,
dev->base_addr + CSR1 );
csr0 = inb( dev->base_addr + CSR0 );
}
} else
nl->state &= ~FL_LINE_DOWN;
outb( csr0 | RC_CHK, dev->base_addr + CSR0 );
init_timer( w );
w->expires = jiffies + SBNI_TIMEOUT;
w->data = arg;
w->function = sbni_watchdog;
add_timer( w );
spin_unlock_irqrestore( &nl->lock, flags );
}
static void
card_start( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
nl->timer_ticks = CHANGE_LEVEL_START_TICKS;
nl->state &= ~(FL_WAIT_ACK | FL_NEED_RESEND);
nl->state |= FL_PREV_OK;
nl->inppos = nl->outpos = 0;
nl->wait_frameno = 0;
nl->tx_frameno = 0;
nl->framelen = 0;
outb( *(u_char *)&nl->csr1 | PR_RES, dev->base_addr + CSR1 );
outb( EN_INT, dev->base_addr + CSR0 );
}
static void
change_level( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
if( nl->delta_rxl == 0 )
return;
if( nl->cur_rxl_index == 0 )
nl->delta_rxl = 1;
else if( nl->cur_rxl_index == 15 )
nl->delta_rxl = -1;
else if( nl->cur_rxl_rcvd < nl->prev_rxl_rcvd )
nl->delta_rxl = -nl->delta_rxl;
nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index += nl->delta_rxl ];
inb( dev->base_addr + CSR0 );
outb( *(u8 *)&nl->csr1, dev->base_addr + CSR1 );
nl->prev_rxl_rcvd = nl->cur_rxl_rcvd;
nl->cur_rxl_rcvd = 0;
}
static void
timeout_change_level( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
nl->cur_rxl_index = timeout_rxl_tab[ nl->timeout_rxl ];
if( ++nl->timeout_rxl >= 4 )
nl->timeout_rxl = 0;
nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index ];
inb( dev->base_addr + CSR0 );
outb( *(unsigned char *)&nl->csr1, dev->base_addr + CSR1 );
nl->prev_rxl_rcvd = nl->cur_rxl_rcvd;
nl->cur_rxl_rcvd = 0;
}
static int
sbni_open( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
struct timer_list *w = &nl->watchdog;
if( dev->base_addr < 0x400 ) {
struct net_device **p = sbni_cards;
for( ; *p && p < sbni_cards + SBNI_MAX_NUM_CARDS; ++p )
if( (*p)->irq == dev->irq &&
((*p)->base_addr == dev->base_addr + 4 ||
(*p)->base_addr == dev->base_addr - 4) &&
(*p)->flags & IFF_UP ) {
((struct net_local *) (netdev_priv(*p)))
->second = dev;
netdev_notice(dev, "using shared irq with %s\n",
(*p)->name);
nl->state |= FL_SECONDARY;
goto handler_attached;
}
}
if( request_irq(dev->irq, sbni_interrupt, IRQF_SHARED, dev->name, dev) ) {
netdev_err(dev, "unable to get IRQ %d\n", dev->irq);
return -EAGAIN;
}
handler_attached:
spin_lock( &nl->lock );
memset( &dev->stats, 0, sizeof(struct net_device_stats) );
memset( &nl->in_stats, 0, sizeof(struct sbni_in_stats) );
card_start( dev );
netif_start_queue( dev );
init_timer( w );
w->expires = jiffies + SBNI_TIMEOUT;
w->data = (unsigned long) dev;
w->function = sbni_watchdog;
add_timer( w );
spin_unlock( &nl->lock );
return 0;
}
static int
sbni_close( struct net_device *dev )
{
struct net_local *nl = netdev_priv(dev);
if( nl->second && nl->second->flags & IFF_UP ) {
netdev_notice(dev, "Secondary channel (%s) is active!\n",
nl->second->name);
return -EBUSY;
}
#ifdef CONFIG_SBNI_MULTILINE
if( nl->state & FL_SLAVE )
emancipate( dev );
else
while( nl->link )
emancipate( nl->link );
#endif
spin_lock( &nl->lock );
nl->second = NULL;
drop_xmit_queue( dev );
netif_stop_queue( dev );
del_timer( &nl->watchdog );
outb( 0, dev->base_addr + CSR0 );
if( !(nl->state & FL_SECONDARY) )
free_irq( dev->irq, dev );
nl->state &= FL_SECONDARY;
spin_unlock( &nl->lock );
return 0;
}
static int
sbni_card_probe( unsigned long ioaddr )
{
unsigned char csr0;
csr0 = inb( ioaddr + CSR0 );
if( csr0 != 0xff && csr0 != 0x00 ) {
csr0 &= ~EN_INT;
if( csr0 & BU_EMP )
csr0 |= EN_INT;
if( VALID_DECODER & (1 << (csr0 >> 4)) )
return 0;
}
return -ENODEV;
}
static int
sbni_ioctl( struct net_device *dev, struct ifreq *ifr, int cmd )
{
struct net_local *nl = netdev_priv(dev);
struct sbni_flags flags;
int error = 0;
#ifdef CONFIG_SBNI_MULTILINE
struct net_device *slave_dev;
char slave_name[ 8 ];
#endif
switch( cmd ) {
case SIOCDEVGETINSTATS :
if (copy_to_user( ifr->ifr_data, &nl->in_stats,
sizeof(struct sbni_in_stats) ))
error = -EFAULT;
break;
case SIOCDEVRESINSTATS :
if (!capable(CAP_NET_ADMIN))
return -EPERM;
memset( &nl->in_stats, 0, sizeof(struct sbni_in_stats) );
break;
case SIOCDEVGHWSTATE :
flags.mac_addr = *(u32 *)(dev->dev_addr + 3);
flags.rate = nl->csr1.rate;
flags.slow_mode = (nl->state & FL_SLOW_MODE) != 0;
flags.rxl = nl->cur_rxl_index;
flags.fixed_rxl = nl->delta_rxl == 0;
if (copy_to_user( ifr->ifr_data, &flags, sizeof flags ))
error = -EFAULT;
break;
case SIOCDEVSHWSTATE :
if (!capable(CAP_NET_ADMIN))
return -EPERM;
spin_lock( &nl->lock );
flags = *(struct sbni_flags*) &ifr->ifr_ifru;
if( flags.fixed_rxl )
nl->delta_rxl = 0,
nl->cur_rxl_index = flags.rxl;
else
nl->delta_rxl = DEF_RXL_DELTA,
nl->cur_rxl_index = DEF_RXL;
nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index ];
nl->csr1.rate = flags.rate;
outb( *(u8 *)&nl->csr1 | PR_RES, dev->base_addr + CSR1 );
spin_unlock( &nl->lock );
break;
#ifdef CONFIG_SBNI_MULTILINE
case SIOCDEVENSLAVE :
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user( slave_name, ifr->ifr_data, sizeof slave_name ))
return -EFAULT;
slave_dev = dev_get_by_name(&init_net, slave_name );
if( !slave_dev || !(slave_dev->flags & IFF_UP) ) {
netdev_err(dev, "trying to enslave non-active device %s\n",
slave_name);
return -EPERM;
}
return enslave( dev, slave_dev );
case SIOCDEVEMANSIPATE :
if (!capable(CAP_NET_ADMIN))
return -EPERM;
return emancipate( dev );
#endif
default :
return -EOPNOTSUPP;
}
return error;
}
static int
enslave( struct net_device *dev, struct net_device *slave_dev )
{
struct net_local *nl = netdev_priv(dev);
struct net_local *snl = netdev_priv(slave_dev);
if( nl->state & FL_SLAVE )
return -EBUSY;
if( snl->state & FL_SLAVE )
return -EBUSY;
spin_lock( &nl->lock );
spin_lock( &snl->lock );
snl->link = nl->link;
nl->link = slave_dev;
snl->master = dev;
snl->state |= FL_SLAVE;
memset( &slave_dev->stats, 0, sizeof(struct net_device_stats) );
netif_stop_queue( slave_dev );
netif_wake_queue( dev );
spin_unlock( &snl->lock );
spin_unlock( &nl->lock );
netdev_notice(dev, "slave device (%s) attached\n", slave_dev->name);
return 0;
}
static int
emancipate( struct net_device *dev )
{
struct net_local *snl = netdev_priv(dev);
struct net_device *p = snl->master;
struct net_local *nl = netdev_priv(p);
if( !(snl->state & FL_SLAVE) )
return -EINVAL;
spin_lock( &nl->lock );
spin_lock( &snl->lock );
drop_xmit_queue( dev );
for(;;) {
struct net_local *t = netdev_priv(p);
if( t->link == dev ) {
t->link = snl->link;
break;
}
p = t->link;
}
snl->link = NULL;
snl->master = dev;
snl->state &= ~FL_SLAVE;
netif_start_queue( dev );
spin_unlock( &snl->lock );
spin_unlock( &nl->lock );
dev_put( dev );
return 0;
}
static void
set_multicast_list( struct net_device *dev )
{
return;
}
int __init init_module( void )
{
struct net_device *dev;
int err;
while( num < SBNI_MAX_NUM_CARDS ) {
dev = alloc_netdev(sizeof(struct net_local),
"sbni%d", sbni_devsetup);
if( !dev)
break;
sprintf( dev->name, "sbni%d", num );
err = sbni_init(dev);
if (err) {
free_netdev(dev);
break;
}
if( register_netdev( dev ) ) {
release_region( dev->base_addr, SBNI_IO_EXTENT );
free_netdev( dev );
break;
}
}
return *sbni_cards ? 0 : -ENODEV;
}
void
cleanup_module(void)
{
int i;
for (i = 0; i < SBNI_MAX_NUM_CARDS; ++i) {
struct net_device *dev = sbni_cards[i];
if (dev != NULL) {
unregister_netdev(dev);
release_region(dev->base_addr, SBNI_IO_EXTENT);
free_netdev(dev);
}
}
}
static int __init
sbni_setup( char *p )
{
int n, parm;
if( *p++ != '(' )
goto bad_param;
for( n = 0, parm = 0; *p && n < 8; ) {
(*dest[ parm ])[ n ] = simple_strtol( p, &p, 0 );
if( !*p || *p == ')' )
return 1;
if( *p == ';' )
++p, ++n, parm = 0;
else if( *p++ != ',' )
break;
else
if( ++parm >= 5 )
break;
}
bad_param:
pr_err("Error in sbni kernel parameter!\n");
return 0;
}
static u32
calc_crc32( u32 crc, u8 *p, u32 len )
{
register u32 _crc;
_crc = crc;
__asm__ __volatile__ (
"xorl %%ebx, %%ebx\n"
"movl %2, %%esi\n"
"movl %3, %%ecx\n"
"movl $crc32tab, %%edi\n"
"shrl $2, %%ecx\n"
"jz 1f\n"
".align 4\n"
"0:\n"
"movb %%al, %%bl\n"
"movl (%%esi), %%edx\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"shrl $8, %%edx\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"shrl $8, %%edx\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"movb %%dh, %%dl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb %%dl, %%bl\n"
"addl $4, %%esi\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"decl %%ecx\n"
"jnz 0b\n"
"1:\n"
"movl %3, %%ecx\n"
"andl $3, %%ecx\n"
"jz 2f\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb (%%esi), %%bl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"decl %%ecx\n"
"jz 2f\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb 1(%%esi), %%bl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"decl %%ecx\n"
"jz 2f\n"
"movb %%al, %%bl\n"
"shrl $8, %%eax\n"
"xorb 2(%%esi), %%bl\n"
"xorl (%%edi,%%ebx,4), %%eax\n"
"2:\n"
: "=a" (_crc)
: "0" (_crc), "g" (p), "g" (len)
: "bx", "cx", "dx", "si", "di"
);
return _crc;
}
static u32
calc_crc32( u32 crc, u8 *p, u32 len )
{
while( len-- )
crc = CRC32( *p++, crc );
return crc;
}
