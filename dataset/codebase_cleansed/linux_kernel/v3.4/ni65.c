static void ni65_set_performance(struct priv *p)
{
writereg(CSR0_STOP | CSR0_CLRALL,CSR0);
if( !(cards[p->cardno].config & 0x02) )
return;
outw(80,PORT+L_ADDRREG);
if(inw(PORT+L_ADDRREG) != 80)
return;
writereg( (csr80 & 0x3fff) ,80);
outw(0,PORT+L_ADDRREG);
outw((short)isa0,PORT+L_BUSIF);
outw(1,PORT+L_ADDRREG);
outw((short)isa1,PORT+L_BUSIF);
outw(CSR0,PORT+L_ADDRREG);
}
static int ni65_open(struct net_device *dev)
{
struct priv *p = dev->ml_priv;
int irqval = request_irq(dev->irq, ni65_interrupt,0,
cards[p->cardno].cardname,dev);
if (irqval) {
printk(KERN_ERR "%s: unable to get IRQ %d (irqval=%d).\n",
dev->name,dev->irq, irqval);
return -EAGAIN;
}
if(ni65_lance_reinit(dev))
{
netif_start_queue(dev);
return 0;
}
else
{
free_irq(dev->irq,dev);
return -EAGAIN;
}
}
static int ni65_close(struct net_device *dev)
{
struct priv *p = dev->ml_priv;
netif_stop_queue(dev);
outw(inw(PORT+L_RESET),PORT+L_RESET);
#ifdef XMT_VIA_SKB
{
int i;
for(i=0;i<TMDNUM;i++)
{
if(p->tmd_skb[i]) {
dev_kfree_skb(p->tmd_skb[i]);
p->tmd_skb[i] = NULL;
}
}
}
#endif
free_irq(dev->irq,dev);
return 0;
}
static void cleanup_card(struct net_device *dev)
{
struct priv *p = dev->ml_priv;
disable_dma(dev->dma);
free_dma(dev->dma);
release_region(dev->base_addr, cards[p->cardno].total_size);
ni65_free_buffer(p);
}
struct net_device * __init ni65_probe(int unit)
{
struct net_device *dev = alloc_etherdev(0);
static const int ports[] = { 0x360, 0x300, 0x320, 0x340, 0 };
const int *port;
int err = 0;
if (!dev)
return ERR_PTR(-ENOMEM);
if (unit >= 0) {
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
irq = dev->irq;
dma = dev->dma;
} else {
dev->base_addr = io;
}
if (dev->base_addr > 0x1ff) {
err = ni65_probe1(dev, dev->base_addr);
} else if (dev->base_addr > 0) {
err = -ENXIO;
} else {
for (port = ports; *port && ni65_probe1(dev, *port); port++)
;
if (!*port)
err = -ENODEV;
}
if (err)
goto out;
err = register_netdev(dev);
if (err)
goto out1;
return dev;
out1:
cleanup_card(dev);
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init ni65_probe1(struct net_device *dev,int ioaddr)
{
int i,j;
struct priv *p;
unsigned long flags;
dev->irq = irq;
dev->dma = dma;
for(i=0;i<NUM_CARDS;i++) {
if(!request_region(ioaddr, cards[i].total_size, cards[i].cardname))
continue;
if(cards[i].id_offset >= 0) {
if(inb(ioaddr+cards[i].id_offset+0) != cards[i].id0 ||
inb(ioaddr+cards[i].id_offset+1) != cards[i].id1) {
release_region(ioaddr, cards[i].total_size);
continue;
}
}
if(cards[i].vendor_id) {
for(j=0;j<3;j++)
if(inb(ioaddr+cards[i].addr_offset+j) != cards[i].vendor_id[j]) {
release_region(ioaddr, cards[i].total_size);
continue;
}
}
break;
}
if(i == NUM_CARDS)
return -ENODEV;
for(j=0;j<6;j++)
dev->dev_addr[j] = inb(ioaddr+cards[i].addr_offset+j);
if( (j=ni65_alloc_buffer(dev)) < 0) {
release_region(ioaddr, cards[i].total_size);
return j;
}
p = dev->ml_priv;
p->cmdr_addr = ioaddr + cards[i].cmd_offset;
p->cardno = i;
spin_lock_init(&p->ring_lock);
printk(KERN_INFO "%s: %s found at %#3x, ", dev->name, cards[p->cardno].cardname , ioaddr);
outw(inw(PORT+L_RESET),PORT+L_RESET);
if( (j=readreg(CSR0)) != 0x4) {
printk("failed.\n");
printk(KERN_ERR "%s: Can't RESET card: %04x\n", dev->name, j);
ni65_free_buffer(p);
release_region(ioaddr, cards[p->cardno].total_size);
return -EAGAIN;
}
outw(88,PORT+L_ADDRREG);
if(inw(PORT+L_ADDRREG) == 88) {
unsigned long v;
v = inw(PORT+L_DATAREG);
v <<= 16;
outw(89,PORT+L_ADDRREG);
v |= inw(PORT+L_DATAREG);
printk("Version %#08lx, ",v);
p->features = INIT_RING_BEFORE_START;
}
else {
printk("ancient LANCE, ");
p->features = 0x0;
}
if(test_bit(0,&cards[i].config)) {
dev->irq = irqtab[(inw(ioaddr+L_CONFIG)>>2)&3];
dev->dma = dmatab[inw(ioaddr+L_CONFIG)&3];
printk("IRQ %d (from card), DMA %d (from card).\n",dev->irq,dev->dma);
}
else {
if(dev->dma == 0) {
unsigned long dma_channels =
((inb(DMA1_STAT_REG) >> 4) & 0x0f)
| (inb(DMA2_STAT_REG) & 0xf0);
for(i=1;i<5;i++) {
int dma = dmatab[i];
if(test_bit(dma,&dma_channels) || request_dma(dma,"ni6510"))
continue;
flags=claim_dma_lock();
disable_dma(dma);
set_dma_mode(dma,DMA_MODE_CASCADE);
enable_dma(dma);
release_dma_lock(flags);
ni65_init_lance(p,dev->dev_addr,0,0);
flags=claim_dma_lock();
disable_dma(dma);
free_dma(dma);
release_dma_lock(flags);
if(readreg(CSR0) & CSR0_IDON)
break;
}
if(i == 5) {
printk("failed.\n");
printk(KERN_ERR "%s: Can't detect DMA channel!\n", dev->name);
ni65_free_buffer(p);
release_region(ioaddr, cards[p->cardno].total_size);
return -EAGAIN;
}
dev->dma = dmatab[i];
printk("DMA %d (autodetected), ",dev->dma);
}
else
printk("DMA %d (assigned), ",dev->dma);
if(dev->irq < 2)
{
unsigned long irq_mask;
ni65_init_lance(p,dev->dev_addr,0,0);
irq_mask = probe_irq_on();
writereg(CSR0_INIT|CSR0_INEA,CSR0);
msleep(20);
dev->irq = probe_irq_off(irq_mask);
if(!dev->irq)
{
printk("Failed to detect IRQ line!\n");
ni65_free_buffer(p);
release_region(ioaddr, cards[p->cardno].total_size);
return -EAGAIN;
}
printk("IRQ %d (autodetected).\n",dev->irq);
}
else
printk("IRQ %d (assigned).\n",dev->irq);
}
if(request_dma(dev->dma, cards[p->cardno].cardname ) != 0)
{
printk(KERN_ERR "%s: Can't request dma-channel %d\n",dev->name,(int) dev->dma);
ni65_free_buffer(p);
release_region(ioaddr, cards[p->cardno].total_size);
return -EAGAIN;
}
dev->base_addr = ioaddr;
dev->netdev_ops = &ni65_netdev_ops;
dev->watchdog_timeo = HZ/2;
return 0;
}
static void ni65_init_lance(struct priv *p,unsigned char *daddr,int filter,int mode)
{
int i;
u32 pib;
writereg(CSR0_CLRALL|CSR0_STOP,CSR0);
for(i=0;i<6;i++)
p->ib.eaddr[i] = daddr[i];
for(i=0;i<8;i++)
p->ib.filter[i] = filter;
p->ib.mode = mode;
p->ib.trp = (u32) isa_virt_to_bus(p->tmdhead) | TMDNUMMASK;
p->ib.rrp = (u32) isa_virt_to_bus(p->rmdhead) | RMDNUMMASK;
writereg(0,CSR3);
pib = (u32) isa_virt_to_bus(&p->ib);
writereg(pib & 0xffff,CSR1);
writereg(pib >> 16,CSR2);
writereg(CSR0_INIT,CSR0);
for(i=0;i<32;i++)
{
mdelay(4);
if(inw(PORT+L_DATAREG) & (CSR0_IDON | CSR0_MERR) )
break;
}
}
static void *ni65_alloc_mem(struct net_device *dev,char *what,int size,int type)
{
struct sk_buff *skb=NULL;
unsigned char *ptr;
void *ret;
if(type) {
ret = skb = alloc_skb(2+16+size,GFP_KERNEL|GFP_DMA);
if(!skb) {
printk(KERN_WARNING "%s: unable to allocate %s memory.\n",dev->name,what);
return NULL;
}
skb_reserve(skb,2+16);
skb_put(skb,R_BUF_SIZE);
ptr = skb->data;
}
else {
ret = ptr = kmalloc(T_BUF_SIZE,GFP_KERNEL | GFP_DMA);
if(!ret)
return NULL;
}
if( (u32) virt_to_phys(ptr+size) > 0x1000000) {
printk(KERN_WARNING "%s: unable to allocate %s memory in lower 16MB!\n",dev->name,what);
if(type)
kfree_skb(skb);
else
kfree(ptr);
return NULL;
}
return ret;
}
static int ni65_alloc_buffer(struct net_device *dev)
{
unsigned char *ptr;
struct priv *p;
int i;
ptr = ni65_alloc_mem(dev,"BUFFER",sizeof(struct priv)+8,0);
if(!ptr)
return -ENOMEM;
p = dev->ml_priv = (struct priv *) (((unsigned long) ptr + 7) & ~0x7);
memset((char *)p, 0, sizeof(struct priv));
p->self = ptr;
for(i=0;i<TMDNUM;i++)
{
#ifdef XMT_VIA_SKB
p->tmd_skb[i] = NULL;
#endif
p->tmdbounce[i] = ni65_alloc_mem(dev,"XMIT",T_BUF_SIZE,0);
if(!p->tmdbounce[i]) {
ni65_free_buffer(p);
return -ENOMEM;
}
}
for(i=0;i<RMDNUM;i++)
{
#ifdef RCV_VIA_SKB
p->recv_skb[i] = ni65_alloc_mem(dev,"RECV",R_BUF_SIZE,1);
if(!p->recv_skb[i]) {
ni65_free_buffer(p);
return -ENOMEM;
}
#else
p->recvbounce[i] = ni65_alloc_mem(dev,"RECV",R_BUF_SIZE,0);
if(!p->recvbounce[i]) {
ni65_free_buffer(p);
return -ENOMEM;
}
#endif
}
return 0;
}
static void ni65_free_buffer(struct priv *p)
{
int i;
if(!p)
return;
for(i=0;i<TMDNUM;i++) {
kfree(p->tmdbounce[i]);
#ifdef XMT_VIA_SKB
if(p->tmd_skb[i])
dev_kfree_skb(p->tmd_skb[i]);
#endif
}
for(i=0;i<RMDNUM;i++)
{
#ifdef RCV_VIA_SKB
if(p->recv_skb[i])
dev_kfree_skb(p->recv_skb[i]);
#else
kfree(p->recvbounce[i]);
#endif
}
kfree(p->self);
}
static void ni65_stop_start(struct net_device *dev,struct priv *p)
{
int csr0 = CSR0_INEA;
writedatareg(CSR0_STOP);
if(debuglevel > 1)
printk(KERN_DEBUG "ni65_stop_start\n");
if(p->features & INIT_RING_BEFORE_START) {
int i;
#ifdef XMT_VIA_SKB
struct sk_buff *skb_save[TMDNUM];
#endif
unsigned long buffer[TMDNUM];
short blen[TMDNUM];
if(p->xmit_queued) {
while(1) {
if((p->tmdhead[p->tmdlast].u.s.status & XMIT_OWN))
break;
p->tmdlast = (p->tmdlast + 1) & (TMDNUM-1);
if(p->tmdlast == p->tmdnum)
break;
}
}
for(i=0;i<TMDNUM;i++) {
struct tmd *tmdp = p->tmdhead + i;
#ifdef XMT_VIA_SKB
skb_save[i] = p->tmd_skb[i];
#endif
buffer[i] = (u32) isa_bus_to_virt(tmdp->u.buffer);
blen[i] = tmdp->blen;
tmdp->u.s.status = 0x0;
}
for(i=0;i<RMDNUM;i++) {
struct rmd *rmdp = p->rmdhead + i;
rmdp->u.s.status = RCV_OWN;
}
p->tmdnum = p->xmit_queued = 0;
writedatareg(CSR0_STRT | csr0);
for(i=0;i<TMDNUM;i++) {
int num = (i + p->tmdlast) & (TMDNUM-1);
p->tmdhead[i].u.buffer = (u32) isa_virt_to_bus((char *)buffer[num]);
p->tmdhead[i].blen = blen[num];
if(p->tmdhead[i].u.s.status & XMIT_OWN) {
p->tmdnum = (p->tmdnum + 1) & (TMDNUM-1);
p->xmit_queued = 1;
writedatareg(CSR0_TDMD | CSR0_INEA | csr0);
}
#ifdef XMT_VIA_SKB
p->tmd_skb[i] = skb_save[num];
#endif
}
p->rmdnum = p->tmdlast = 0;
if(!p->lock)
if (p->tmdnum || !p->xmit_queued)
netif_wake_queue(dev);
dev->trans_start = jiffies;
}
else
writedatareg(CSR0_STRT | csr0);
}
static int ni65_lance_reinit(struct net_device *dev)
{
int i;
struct priv *p = dev->ml_priv;
unsigned long flags;
p->lock = 0;
p->xmit_queued = 0;
flags=claim_dma_lock();
disable_dma(dev->dma);
set_dma_mode(dev->dma,DMA_MODE_CASCADE);
enable_dma(dev->dma);
release_dma_lock(flags);
outw(inw(PORT+L_RESET),PORT+L_RESET);
if( (i=readreg(CSR0) ) != 0x4)
{
printk(KERN_ERR "%s: can't RESET %s card: %04x\n",dev->name,
cards[p->cardno].cardname,(int) i);
flags=claim_dma_lock();
disable_dma(dev->dma);
release_dma_lock(flags);
return 0;
}
p->rmdnum = p->tmdnum = p->tmdlast = p->tmdbouncenum = 0;
for(i=0;i<TMDNUM;i++)
{
struct tmd *tmdp = p->tmdhead + i;
#ifdef XMT_VIA_SKB
if(p->tmd_skb[i]) {
dev_kfree_skb(p->tmd_skb[i]);
p->tmd_skb[i] = NULL;
}
#endif
tmdp->u.buffer = 0x0;
tmdp->u.s.status = XMIT_START | XMIT_END;
tmdp->blen = tmdp->status2 = 0;
}
for(i=0;i<RMDNUM;i++)
{
struct rmd *rmdp = p->rmdhead + i;
#ifdef RCV_VIA_SKB
rmdp->u.buffer = (u32) isa_virt_to_bus(p->recv_skb[i]->data);
#else
rmdp->u.buffer = (u32) isa_virt_to_bus(p->recvbounce[i]);
#endif
rmdp->blen = -(R_BUF_SIZE-8);
rmdp->mlen = 0;
rmdp->u.s.status = RCV_OWN;
}
if(dev->flags & IFF_PROMISC)
ni65_init_lance(p,dev->dev_addr,0x00,M_PROM);
else if (netdev_mc_count(dev) || dev->flags & IFF_ALLMULTI)
ni65_init_lance(p,dev->dev_addr,0xff,0x0);
else
ni65_init_lance(p,dev->dev_addr,0x00,0x00);
if(inw(PORT+L_DATAREG) & CSR0_IDON) {
ni65_set_performance(p);
writedatareg(CSR0_CLRALL | CSR0_INEA | CSR0_STRT);
return 1;
}
printk(KERN_ERR "%s: can't init lance, status: %04x\n",dev->name,(int) inw(PORT+L_DATAREG));
flags=claim_dma_lock();
disable_dma(dev->dma);
release_dma_lock(flags);
return 0;
}
static irqreturn_t ni65_interrupt(int irq, void * dev_id)
{
int csr0 = 0;
struct net_device *dev = dev_id;
struct priv *p;
int bcnt = 32;
p = dev->ml_priv;
spin_lock(&p->ring_lock);
while(--bcnt) {
csr0 = inw(PORT+L_DATAREG);
#if 0
writedatareg( (csr0 & CSR0_CLRALL) );
#else
writedatareg( (csr0 & CSR0_CLRALL) | CSR0_INEA );
#endif
if(!(csr0 & (CSR0_ERR | CSR0_RINT | CSR0_TINT)))
break;
if(csr0 & CSR0_RINT)
ni65_recv_intr(dev,csr0);
if(csr0 & CSR0_TINT)
ni65_xmit_intr(dev,csr0);
if(csr0 & CSR0_ERR)
{
if(debuglevel > 1)
printk(KERN_ERR "%s: general error: %04x.\n",dev->name,csr0);
if(csr0 & CSR0_BABL)
dev->stats.tx_errors++;
if(csr0 & CSR0_MISS) {
int i;
for(i=0;i<RMDNUM;i++)
printk("%02x ",p->rmdhead[i].u.s.status);
printk("\n");
dev->stats.rx_errors++;
}
if(csr0 & CSR0_MERR) {
if(debuglevel > 1)
printk(KERN_ERR "%s: Ooops .. memory error: %04x.\n",dev->name,csr0);
ni65_stop_start(dev,p);
}
}
}
#ifdef RCV_PARANOIA_CHECK
{
int j;
for(j=0;j<RMDNUM;j++)
{
int i, num2;
for(i=RMDNUM-1;i>0;i--) {
num2 = (p->rmdnum + i) & (RMDNUM-1);
if(!(p->rmdhead[num2].u.s.status & RCV_OWN))
break;
}
if(i) {
int k, num1;
for(k=0;k<RMDNUM;k++) {
num1 = (p->rmdnum + k) & (RMDNUM-1);
if(!(p->rmdhead[num1].u.s.status & RCV_OWN))
break;
}
if(!k)
break;
if(debuglevel > 0)
{
char buf[256],*buf1;
buf1 = buf;
for(k=0;k<RMDNUM;k++) {
sprintf(buf1,"%02x ",(p->rmdhead[k].u.s.status));
buf1 += 3;
}
*buf1 = 0;
printk(KERN_ERR "%s: Ooops, receive ring corrupted %2d %2d | %s\n",dev->name,p->rmdnum,i,buf);
}
p->rmdnum = num1;
ni65_recv_intr(dev,csr0);
if((p->rmdhead[num2].u.s.status & RCV_OWN))
break;
}
else
break;
}
}
#endif
if( (csr0 & (CSR0_RXON | CSR0_TXON)) != (CSR0_RXON | CSR0_TXON) ) {
printk(KERN_DEBUG "%s: RX or TX was offline -> restart\n",dev->name);
ni65_stop_start(dev,p);
}
else
writedatareg(CSR0_INEA);
spin_unlock(&p->ring_lock);
return IRQ_HANDLED;
}
static void ni65_xmit_intr(struct net_device *dev,int csr0)
{
struct priv *p = dev->ml_priv;
while(p->xmit_queued)
{
struct tmd *tmdp = p->tmdhead + p->tmdlast;
int tmdstat = tmdp->u.s.status;
if(tmdstat & XMIT_OWN)
break;
if(tmdstat & XMIT_ERR)
{
#if 0
if(tmdp->status2 & XMIT_TDRMASK && debuglevel > 3)
printk(KERN_ERR "%s: tdr-problems (e.g. no resistor)\n",dev->name);
#endif
if(tmdp->status2 & XMIT_RTRY)
dev->stats.tx_aborted_errors++;
if(tmdp->status2 & XMIT_LCAR)
dev->stats.tx_carrier_errors++;
if(tmdp->status2 & (XMIT_BUFF | XMIT_UFLO )) {
dev->stats.tx_fifo_errors++;
if(debuglevel > 0)
printk(KERN_ERR "%s: Xmit FIFO/BUFF error\n",dev->name);
if(p->features & INIT_RING_BEFORE_START) {
tmdp->u.s.status = XMIT_OWN | XMIT_START | XMIT_END;
ni65_stop_start(dev,p);
break;
}
else
ni65_stop_start(dev,p);
}
if(debuglevel > 2)
printk(KERN_ERR "%s: xmit-error: %04x %02x-%04x\n",dev->name,csr0,(int) tmdstat,(int) tmdp->status2);
if(!(csr0 & CSR0_BABL))
dev->stats.tx_errors++;
tmdp->status2 = 0;
}
else {
dev->stats.tx_bytes -= (short)(tmdp->blen);
dev->stats.tx_packets++;
}
#ifdef XMT_VIA_SKB
if(p->tmd_skb[p->tmdlast]) {
dev_kfree_skb_irq(p->tmd_skb[p->tmdlast]);
p->tmd_skb[p->tmdlast] = NULL;
}
#endif
p->tmdlast = (p->tmdlast + 1) & (TMDNUM-1);
if(p->tmdlast == p->tmdnum)
p->xmit_queued = 0;
}
netif_wake_queue(dev);
}
static void ni65_recv_intr(struct net_device *dev,int csr0)
{
struct rmd *rmdp;
int rmdstat,len;
int cnt=0;
struct priv *p = dev->ml_priv;
rmdp = p->rmdhead + p->rmdnum;
while(!( (rmdstat = rmdp->u.s.status) & RCV_OWN))
{
cnt++;
if( (rmdstat & (RCV_START | RCV_END | RCV_ERR)) != (RCV_START | RCV_END) )
{
if(!(rmdstat & RCV_ERR)) {
if(rmdstat & RCV_START)
{
dev->stats.rx_length_errors++;
printk(KERN_ERR "%s: recv, packet too long: %d\n",dev->name,rmdp->mlen & 0x0fff);
}
}
else {
if(debuglevel > 2)
printk(KERN_ERR "%s: receive-error: %04x, lance-status: %04x/%04x\n",
dev->name,(int) rmdstat,csr0,(int) inw(PORT+L_DATAREG) );
if(rmdstat & RCV_FRAM)
dev->stats.rx_frame_errors++;
if(rmdstat & RCV_OFLO)
dev->stats.rx_over_errors++;
if(rmdstat & RCV_CRC)
dev->stats.rx_crc_errors++;
if(rmdstat & RCV_BUF_ERR)
dev->stats.rx_fifo_errors++;
}
if(!(csr0 & CSR0_MISS))
dev->stats.rx_errors++;
}
else if( (len = (rmdp->mlen & 0x0fff) - 4) >= 60)
{
#ifdef RCV_VIA_SKB
struct sk_buff *skb = alloc_skb(R_BUF_SIZE+2+16,GFP_ATOMIC);
if (skb)
skb_reserve(skb,16);
#else
struct sk_buff *skb = netdev_alloc_skb(dev, len + 2);
#endif
if(skb)
{
skb_reserve(skb,2);
#ifdef RCV_VIA_SKB
if( (unsigned long) (skb->data + R_BUF_SIZE) > 0x1000000) {
skb_put(skb,len);
skb_copy_to_linear_data(skb, (unsigned char *)(p->recv_skb[p->rmdnum]->data),len);
}
else {
struct sk_buff *skb1 = p->recv_skb[p->rmdnum];
skb_put(skb,R_BUF_SIZE);
p->recv_skb[p->rmdnum] = skb;
rmdp->u.buffer = (u32) isa_virt_to_bus(skb->data);
skb = skb1;
skb_trim(skb,len);
}
#else
skb_put(skb,len);
skb_copy_to_linear_data(skb, (unsigned char *) p->recvbounce[p->rmdnum],len);
#endif
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
skb->protocol=eth_type_trans(skb,dev);
netif_rx(skb);
}
else
{
printk(KERN_ERR "%s: can't alloc new sk_buff\n",dev->name);
dev->stats.rx_dropped++;
}
}
else {
printk(KERN_INFO "%s: received runt packet\n",dev->name);
dev->stats.rx_errors++;
}
rmdp->blen = -(R_BUF_SIZE-8);
rmdp->mlen = 0;
rmdp->u.s.status = RCV_OWN;
p->rmdnum = (p->rmdnum + 1) & (RMDNUM-1);
rmdp = p->rmdhead + p->rmdnum;
}
}
static void ni65_timeout(struct net_device *dev)
{
int i;
struct priv *p = dev->ml_priv;
printk(KERN_ERR "%s: xmitter timed out, try to restart!\n",dev->name);
for(i=0;i<TMDNUM;i++)
printk("%02x ",p->tmdhead[i].u.s.status);
printk("\n");
ni65_lance_reinit(dev);
dev->trans_start = jiffies;
netif_wake_queue(dev);
}
static netdev_tx_t ni65_send_packet(struct sk_buff *skb,
struct net_device *dev)
{
struct priv *p = dev->ml_priv;
netif_stop_queue(dev);
if (test_and_set_bit(0, (void*)&p->lock)) {
printk(KERN_ERR "%s: Queue was locked.\n", dev->name);
return NETDEV_TX_BUSY;
}
{
short len = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
struct tmd *tmdp;
unsigned long flags;
#ifdef XMT_VIA_SKB
if( (unsigned long) (skb->data + skb->len) > 0x1000000) {
#endif
skb_copy_from_linear_data(skb, p->tmdbounce[p->tmdbouncenum],
skb->len > T_BUF_SIZE ? T_BUF_SIZE :
skb->len);
if (len > skb->len)
memset((char *)p->tmdbounce[p->tmdbouncenum]+skb->len, 0, len-skb->len);
dev_kfree_skb (skb);
spin_lock_irqsave(&p->ring_lock, flags);
tmdp = p->tmdhead + p->tmdnum;
tmdp->u.buffer = (u32) isa_virt_to_bus(p->tmdbounce[p->tmdbouncenum]);
p->tmdbouncenum = (p->tmdbouncenum + 1) & (TMDNUM - 1);
#ifdef XMT_VIA_SKB
}
else {
spin_lock_irqsave(&p->ring_lock, flags);
tmdp = p->tmdhead + p->tmdnum;
tmdp->u.buffer = (u32) isa_virt_to_bus(skb->data);
p->tmd_skb[p->tmdnum] = skb;
}
#endif
tmdp->blen = -len;
tmdp->u.s.status = XMIT_OWN | XMIT_START | XMIT_END;
writedatareg(CSR0_TDMD | CSR0_INEA);
p->xmit_queued = 1;
p->tmdnum = (p->tmdnum + 1) & (TMDNUM-1);
if(p->tmdnum != p->tmdlast)
netif_wake_queue(dev);
p->lock = 0;
spin_unlock_irqrestore(&p->ring_lock, flags);
}
return NETDEV_TX_OK;
}
static void set_multicast_list(struct net_device *dev)
{
if(!ni65_lance_reinit(dev))
printk(KERN_ERR "%s: Can't switch card into MC mode!\n",dev->name);
netif_wake_queue(dev);
}
int __init init_module(void)
{
dev_ni65 = ni65_probe(-1);
return IS_ERR(dev_ni65) ? PTR_ERR(dev_ni65) : 0;
}
void __exit cleanup_module(void)
{
unregister_netdev(dev_ni65);
cleanup_card(dev_ni65);
free_netdev(dev_ni65);
}
