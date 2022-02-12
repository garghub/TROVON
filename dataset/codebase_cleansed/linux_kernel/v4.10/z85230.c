static inline int z8530_read_port(unsigned long p)
{
u8 r=inb(Z8530_PORT_OF(p));
if(p&Z8530_PORT_SLEEP)
udelay(5);
return r;
}
static inline void z8530_write_port(unsigned long p, u8 d)
{
outb(d,Z8530_PORT_OF(p));
if(p&Z8530_PORT_SLEEP)
udelay(5);
}
static inline u8 read_zsreg(struct z8530_channel *c, u8 reg)
{
if(reg)
z8530_write_port(c->ctrlio, reg);
return z8530_read_port(c->ctrlio);
}
static inline u8 read_zsdata(struct z8530_channel *c)
{
u8 r;
r=z8530_read_port(c->dataio);
return r;
}
static inline void write_zsreg(struct z8530_channel *c, u8 reg, u8 val)
{
if(reg)
z8530_write_port(c->ctrlio, reg);
z8530_write_port(c->ctrlio, val);
}
static inline void write_zsctrl(struct z8530_channel *c, u8 val)
{
z8530_write_port(c->ctrlio, val);
}
static inline void write_zsdata(struct z8530_channel *c, u8 val)
{
z8530_write_port(c->dataio, val);
}
static void z8530_flush_fifo(struct z8530_channel *c)
{
read_zsreg(c, R1);
read_zsreg(c, R1);
read_zsreg(c, R1);
read_zsreg(c, R1);
if(c->dev->type==Z85230)
{
read_zsreg(c, R1);
read_zsreg(c, R1);
read_zsreg(c, R1);
read_zsreg(c, R1);
}
}
static void z8530_rtsdtr(struct z8530_channel *c, int set)
{
if (set)
c->regs[5] |= (RTS | DTR);
else
c->regs[5] &= ~(RTS | DTR);
write_zsreg(c, R5, c->regs[5]);
}
static void z8530_rx(struct z8530_channel *c)
{
u8 ch,stat;
while(1)
{
if(!(read_zsreg(c, R0)&1))
break;
ch=read_zsdata(c);
stat=read_zsreg(c, R1);
if(c->count < c->max)
{
*c->dptr++=ch;
c->count++;
}
if(stat&END_FR)
{
if(stat&(Rx_OVR|CRC_ERR))
{
if(c->skb)
c->dptr=c->skb->data;
c->count=0;
if(stat&Rx_OVR)
{
pr_warn("%s: overrun\n", c->dev->name);
c->rx_overrun++;
}
if(stat&CRC_ERR)
{
c->rx_crc_err++;
}
}
else
{
z8530_rx_done(c);
write_zsctrl(c, RES_Rx_CRC);
}
}
}
write_zsctrl(c, ERR_RES);
write_zsctrl(c, RES_H_IUS);
}
static void z8530_tx(struct z8530_channel *c)
{
while(c->txcount) {
if(!(read_zsreg(c, R0)&4))
return;
c->txcount--;
write_zsreg(c, R8, *c->tx_ptr++);
write_zsctrl(c, RES_H_IUS);
if(c->txcount==0)
{
write_zsctrl(c, RES_EOM_L);
write_zsreg(c, R10, c->regs[10]&~ABUNDER);
}
}
write_zsctrl(c, RES_Tx_P);
z8530_tx_done(c);
write_zsctrl(c, RES_H_IUS);
}
static void z8530_status(struct z8530_channel *chan)
{
u8 status, altered;
status = read_zsreg(chan, R0);
altered = chan->status ^ status;
chan->status = status;
if (status & TxEOM) {
chan->netdevice->stats.tx_fifo_errors++;
write_zsctrl(chan, ERR_RES);
z8530_tx_done(chan);
}
if (altered & chan->dcdcheck)
{
if (status & chan->dcdcheck) {
pr_info("%s: DCD raised\n", chan->dev->name);
write_zsreg(chan, R3, chan->regs[3] | RxENABLE);
if (chan->netdevice)
netif_carrier_on(chan->netdevice);
} else {
pr_info("%s: DCD lost\n", chan->dev->name);
write_zsreg(chan, R3, chan->regs[3] & ~RxENABLE);
z8530_flush_fifo(chan);
if (chan->netdevice)
netif_carrier_off(chan->netdevice);
}
}
write_zsctrl(chan, RES_EXT_INT);
write_zsctrl(chan, RES_H_IUS);
}
static void z8530_dma_rx(struct z8530_channel *chan)
{
if(chan->rxdma_on)
{
u8 status;
read_zsreg(chan, R7);
read_zsreg(chan, R6);
status=read_zsreg(chan, R1);
if(status&END_FR)
{
z8530_rx_done(chan);
}
write_zsctrl(chan, ERR_RES);
write_zsctrl(chan, RES_H_IUS);
}
else
{
z8530_rx(chan);
}
}
static void z8530_dma_tx(struct z8530_channel *chan)
{
if(!chan->dma_tx)
{
pr_warn("Hey who turned the DMA off?\n");
z8530_tx(chan);
return;
}
pr_err("DMA tx - bogus event!\n");
z8530_tx(chan);
}
static void z8530_dma_status(struct z8530_channel *chan)
{
u8 status, altered;
status=read_zsreg(chan, R0);
altered=chan->status^status;
chan->status=status;
if(chan->dma_tx)
{
if(status&TxEOM)
{
unsigned long flags;
flags=claim_dma_lock();
disable_dma(chan->txdma);
clear_dma_ff(chan->txdma);
chan->txdma_on=0;
release_dma_lock(flags);
z8530_tx_done(chan);
}
}
if (altered & chan->dcdcheck)
{
if (status & chan->dcdcheck) {
pr_info("%s: DCD raised\n", chan->dev->name);
write_zsreg(chan, R3, chan->regs[3] | RxENABLE);
if (chan->netdevice)
netif_carrier_on(chan->netdevice);
} else {
pr_info("%s: DCD lost\n", chan->dev->name);
write_zsreg(chan, R3, chan->regs[3] & ~RxENABLE);
z8530_flush_fifo(chan);
if (chan->netdevice)
netif_carrier_off(chan->netdevice);
}
}
write_zsctrl(chan, RES_EXT_INT);
write_zsctrl(chan, RES_H_IUS);
}
static void z8530_rx_clear(struct z8530_channel *c)
{
u8 stat;
read_zsdata(c);
stat=read_zsreg(c, R1);
if(stat&END_FR)
write_zsctrl(c, RES_Rx_CRC);
write_zsctrl(c, ERR_RES);
write_zsctrl(c, RES_H_IUS);
}
static void z8530_tx_clear(struct z8530_channel *c)
{
write_zsctrl(c, RES_Tx_P);
write_zsctrl(c, RES_H_IUS);
}
static void z8530_status_clear(struct z8530_channel *chan)
{
u8 status=read_zsreg(chan, R0);
if(status&TxEOM)
write_zsctrl(chan, ERR_RES);
write_zsctrl(chan, RES_EXT_INT);
write_zsctrl(chan, RES_H_IUS);
}
irqreturn_t z8530_interrupt(int irq, void *dev_id)
{
struct z8530_dev *dev=dev_id;
u8 uninitialized_var(intr);
static volatile int locker=0;
int work=0;
struct z8530_irqhandler *irqs;
if(locker)
{
pr_err("IRQ re-enter\n");
return IRQ_NONE;
}
locker=1;
spin_lock(&dev->lock);
while(++work<5000)
{
intr = read_zsreg(&dev->chanA, R3);
if(!(intr & (CHARxIP|CHATxIP|CHAEXT|CHBRxIP|CHBTxIP|CHBEXT)))
break;
irqs=dev->chanA.irqs;
if(intr & (CHARxIP|CHATxIP|CHAEXT))
{
if(intr&CHARxIP)
irqs->rx(&dev->chanA);
if(intr&CHATxIP)
irqs->tx(&dev->chanA);
if(intr&CHAEXT)
irqs->status(&dev->chanA);
}
irqs=dev->chanB.irqs;
if(intr & (CHBRxIP|CHBTxIP|CHBEXT))
{
if(intr&CHBRxIP)
irqs->rx(&dev->chanB);
if(intr&CHBTxIP)
irqs->tx(&dev->chanB);
if(intr&CHBEXT)
irqs->status(&dev->chanB);
}
}
spin_unlock(&dev->lock);
if(work==5000)
pr_err("%s: interrupt jammed - abort(0x%X)!\n",
dev->name, intr);
locker=0;
return IRQ_HANDLED;
}
int z8530_sync_open(struct net_device *dev, struct z8530_channel *c)
{
unsigned long flags;
spin_lock_irqsave(c->lock, flags);
c->sync = 1;
c->mtu = dev->mtu+64;
c->count = 0;
c->skb = NULL;
c->skb2 = NULL;
c->irqs = &z8530_sync;
z8530_rx_done(c);
z8530_rx_done(c);
z8530_rtsdtr(c,1);
c->dma_tx = 0;
c->regs[R1]|=TxINT_ENAB;
write_zsreg(c, R1, c->regs[R1]);
write_zsreg(c, R3, c->regs[R3]|RxENABLE);
spin_unlock_irqrestore(c->lock, flags);
return 0;
}
int z8530_sync_close(struct net_device *dev, struct z8530_channel *c)
{
u8 chk;
unsigned long flags;
spin_lock_irqsave(c->lock, flags);
c->irqs = &z8530_nop;
c->max = 0;
c->sync = 0;
chk=read_zsreg(c,R0);
write_zsreg(c, R3, c->regs[R3]);
z8530_rtsdtr(c,0);
spin_unlock_irqrestore(c->lock, flags);
return 0;
}
int z8530_sync_dma_open(struct net_device *dev, struct z8530_channel *c)
{
unsigned long cflags, dflags;
c->sync = 1;
c->mtu = dev->mtu+64;
c->count = 0;
c->skb = NULL;
c->skb2 = NULL;
c->rxdma_on = 0;
c->txdma_on = 0;
if(c->mtu > PAGE_SIZE/2)
return -EMSGSIZE;
c->rx_buf[0]=(void *)get_zeroed_page(GFP_KERNEL|GFP_DMA);
if(c->rx_buf[0]==NULL)
return -ENOBUFS;
c->rx_buf[1]=c->rx_buf[0]+PAGE_SIZE/2;
c->tx_dma_buf[0]=(void *)get_zeroed_page(GFP_KERNEL|GFP_DMA);
if(c->tx_dma_buf[0]==NULL)
{
free_page((unsigned long)c->rx_buf[0]);
c->rx_buf[0]=NULL;
return -ENOBUFS;
}
c->tx_dma_buf[1]=c->tx_dma_buf[0]+PAGE_SIZE/2;
c->tx_dma_used=0;
c->dma_tx = 1;
c->dma_num=0;
c->dma_ready=1;
spin_lock_irqsave(c->lock, cflags);
c->regs[R14]|= DTRREQ;
write_zsreg(c, R14, c->regs[R14]);
c->regs[R1]&= ~TxINT_ENAB;
write_zsreg(c, R1, c->regs[R1]);
c->regs[R1]|= WT_FN_RDYFN;
c->regs[R1]|= WT_RDY_RT;
c->regs[R1]|= INT_ERR_Rx;
c->regs[R1]&= ~TxINT_ENAB;
write_zsreg(c, R1, c->regs[R1]);
c->regs[R1]|= WT_RDY_ENAB;
write_zsreg(c, R1, c->regs[R1]);
dflags=claim_dma_lock();
disable_dma(c->rxdma);
clear_dma_ff(c->rxdma);
set_dma_mode(c->rxdma, DMA_MODE_READ|0x10);
set_dma_addr(c->rxdma, virt_to_bus(c->rx_buf[0]));
set_dma_count(c->rxdma, c->mtu);
enable_dma(c->rxdma);
disable_dma(c->txdma);
clear_dma_ff(c->txdma);
set_dma_mode(c->txdma, DMA_MODE_WRITE);
disable_dma(c->txdma);
release_dma_lock(dflags);
c->rxdma_on = 1;
c->txdma_on = 1;
c->tx_dma_used = 1;
c->irqs = &z8530_dma_sync;
z8530_rtsdtr(c,1);
write_zsreg(c, R3, c->regs[R3]|RxENABLE);
spin_unlock_irqrestore(c->lock, cflags);
return 0;
}
int z8530_sync_dma_close(struct net_device *dev, struct z8530_channel *c)
{
u8 chk;
unsigned long flags;
c->irqs = &z8530_nop;
c->max = 0;
c->sync = 0;
flags=claim_dma_lock();
disable_dma(c->rxdma);
clear_dma_ff(c->rxdma);
c->rxdma_on = 0;
disable_dma(c->txdma);
clear_dma_ff(c->txdma);
release_dma_lock(flags);
c->txdma_on = 0;
c->tx_dma_used = 0;
spin_lock_irqsave(c->lock, flags);
c->regs[R1]&= ~WT_RDY_ENAB;
write_zsreg(c, R1, c->regs[R1]);
c->regs[R1]&= ~(WT_RDY_RT|WT_FN_RDYFN|INT_ERR_Rx);
c->regs[R1]|= INT_ALL_Rx;
write_zsreg(c, R1, c->regs[R1]);
c->regs[R14]&= ~DTRREQ;
write_zsreg(c, R14, c->regs[R14]);
if(c->rx_buf[0])
{
free_page((unsigned long)c->rx_buf[0]);
c->rx_buf[0]=NULL;
}
if(c->tx_dma_buf[0])
{
free_page((unsigned long)c->tx_dma_buf[0]);
c->tx_dma_buf[0]=NULL;
}
chk=read_zsreg(c,R0);
write_zsreg(c, R3, c->regs[R3]);
z8530_rtsdtr(c,0);
spin_unlock_irqrestore(c->lock, flags);
return 0;
}
int z8530_sync_txdma_open(struct net_device *dev, struct z8530_channel *c)
{
unsigned long cflags, dflags;
printk("Opening sync interface for TX-DMA\n");
c->sync = 1;
c->mtu = dev->mtu+64;
c->count = 0;
c->skb = NULL;
c->skb2 = NULL;
if(c->mtu > PAGE_SIZE/2)
return -EMSGSIZE;
c->tx_dma_buf[0]=(void *)get_zeroed_page(GFP_KERNEL|GFP_DMA);
if(c->tx_dma_buf[0]==NULL)
return -ENOBUFS;
c->tx_dma_buf[1] = c->tx_dma_buf[0] + PAGE_SIZE/2;
spin_lock_irqsave(c->lock, cflags);
z8530_rx_done(c);
z8530_rx_done(c);
c->rxdma_on = 0;
c->txdma_on = 0;
c->tx_dma_used=0;
c->dma_num=0;
c->dma_ready=1;
c->dma_tx = 1;
c->regs[R14]|= DTRREQ;
write_zsreg(c, R14, c->regs[R14]);
c->regs[R1]&= ~TxINT_ENAB;
write_zsreg(c, R1, c->regs[R1]);
dflags = claim_dma_lock();
disable_dma(c->txdma);
clear_dma_ff(c->txdma);
set_dma_mode(c->txdma, DMA_MODE_WRITE);
disable_dma(c->txdma);
release_dma_lock(dflags);
c->rxdma_on = 0;
c->txdma_on = 1;
c->tx_dma_used = 1;
c->irqs = &z8530_txdma_sync;
z8530_rtsdtr(c,1);
write_zsreg(c, R3, c->regs[R3]|RxENABLE);
spin_unlock_irqrestore(c->lock, cflags);
return 0;
}
int z8530_sync_txdma_close(struct net_device *dev, struct z8530_channel *c)
{
unsigned long dflags, cflags;
u8 chk;
spin_lock_irqsave(c->lock, cflags);
c->irqs = &z8530_nop;
c->max = 0;
c->sync = 0;
dflags = claim_dma_lock();
disable_dma(c->txdma);
clear_dma_ff(c->txdma);
c->txdma_on = 0;
c->tx_dma_used = 0;
release_dma_lock(dflags);
c->regs[R1]&= ~WT_RDY_ENAB;
write_zsreg(c, R1, c->regs[R1]);
c->regs[R1]&= ~(WT_RDY_RT|WT_FN_RDYFN|INT_ERR_Rx);
c->regs[R1]|= INT_ALL_Rx;
write_zsreg(c, R1, c->regs[R1]);
c->regs[R14]&= ~DTRREQ;
write_zsreg(c, R14, c->regs[R14]);
if(c->tx_dma_buf[0])
{
free_page((unsigned long)c->tx_dma_buf[0]);
c->tx_dma_buf[0]=NULL;
}
chk=read_zsreg(c,R0);
write_zsreg(c, R3, c->regs[R3]);
z8530_rtsdtr(c,0);
spin_unlock_irqrestore(c->lock, cflags);
return 0;
}
void z8530_describe(struct z8530_dev *dev, char *mapping, unsigned long io)
{
pr_info("%s: %s found at %s 0x%lX, IRQ %d\n",
dev->name,
z8530_type_name[dev->type],
mapping,
Z8530_PORT_OF(io),
dev->irq);
}
static inline int do_z8530_init(struct z8530_dev *dev)
{
dev->chanA.irqs=&z8530_nop;
dev->chanB.irqs=&z8530_nop;
dev->chanA.dcdcheck=DCD;
dev->chanB.dcdcheck=DCD;
write_zsreg(&dev->chanA, R9, 0xC0);
udelay(200);
write_zsreg(&dev->chanA, R12, 0xAA);
if(read_zsreg(&dev->chanA, R12)!=0xAA)
return -ENODEV;
write_zsreg(&dev->chanA, R12, 0x55);
if(read_zsreg(&dev->chanA, R12)!=0x55)
return -ENODEV;
dev->type=Z8530;
write_zsreg(&dev->chanA, R15, 0x01);
if(read_zsreg(&dev->chanA, R15)==0x01)
{
write_zsreg(&dev->chanA, R8, 0);
if(read_zsreg(&dev->chanA, R0)&Tx_BUF_EMP)
dev->type = Z85230;
else
dev->type = Z85C30;
}
write_zsreg(&dev->chanA, R15, 0);
memcpy(dev->chanA.regs, reg_init, 16);
memcpy(dev->chanB.regs, reg_init ,16);
return 0;
}
int z8530_init(struct z8530_dev *dev)
{
unsigned long flags;
int ret;
spin_lock_init(&dev->lock);
dev->chanA.lock = &dev->lock;
dev->chanB.lock = &dev->lock;
spin_lock_irqsave(&dev->lock, flags);
ret = do_z8530_init(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return ret;
}
int z8530_shutdown(struct z8530_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
dev->chanA.irqs=&z8530_nop;
dev->chanB.irqs=&z8530_nop;
write_zsreg(&dev->chanA, R9, 0xC0);
udelay(100);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
int z8530_channel_load(struct z8530_channel *c, u8 *rtable)
{
unsigned long flags;
spin_lock_irqsave(c->lock, flags);
while(*rtable!=255)
{
int reg=*rtable++;
if(reg>0x0F)
write_zsreg(c, R15, c->regs[15]|1);
write_zsreg(c, reg&0x0F, *rtable);
if(reg>0x0F)
write_zsreg(c, R15, c->regs[15]&~1);
c->regs[reg]=*rtable++;
}
c->rx_function=z8530_null_rx;
c->skb=NULL;
c->tx_skb=NULL;
c->tx_next_skb=NULL;
c->mtu=1500;
c->max=0;
c->count=0;
c->status=read_zsreg(c, R0);
c->sync=1;
write_zsreg(c, R3, c->regs[R3]|RxENABLE);
spin_unlock_irqrestore(c->lock, flags);
return 0;
}
static void z8530_tx_begin(struct z8530_channel *c)
{
unsigned long flags;
if(c->tx_skb)
return;
c->tx_skb=c->tx_next_skb;
c->tx_next_skb=NULL;
c->tx_ptr=c->tx_next_ptr;
if(c->tx_skb==NULL)
{
if(c->dma_tx)
{
flags=claim_dma_lock();
disable_dma(c->txdma);
if (get_dma_residue(c->txdma))
{
c->netdevice->stats.tx_dropped++;
c->netdevice->stats.tx_fifo_errors++;
}
release_dma_lock(flags);
}
c->txcount=0;
}
else
{
c->txcount=c->tx_skb->len;
if(c->dma_tx)
{
flags=claim_dma_lock();
disable_dma(c->txdma);
if(c->dev->type!=Z85230)
{
write_zsctrl(c, RES_Tx_CRC);
write_zsctrl(c, RES_EOM_L);
}
write_zsreg(c, R10, c->regs[10]&~ABUNDER);
clear_dma_ff(c->txdma);
set_dma_addr(c->txdma, virt_to_bus(c->tx_ptr));
set_dma_count(c->txdma, c->txcount);
enable_dma(c->txdma);
release_dma_lock(flags);
write_zsctrl(c, RES_EOM_L);
write_zsreg(c, R5, c->regs[R5]|TxENAB);
}
else
{
write_zsreg(c, R10, c->regs[10]);
write_zsctrl(c, RES_Tx_CRC);
while(c->txcount && (read_zsreg(c,R0)&Tx_BUF_EMP))
{
write_zsreg(c, R8, *c->tx_ptr++);
c->txcount--;
}
}
}
netif_wake_queue(c->netdevice);
}
static void z8530_tx_done(struct z8530_channel *c)
{
struct sk_buff *skb;
if (c->tx_skb == NULL)
return;
skb = c->tx_skb;
c->tx_skb = NULL;
z8530_tx_begin(c);
c->netdevice->stats.tx_packets++;
c->netdevice->stats.tx_bytes += skb->len;
dev_kfree_skb_irq(skb);
}
void z8530_null_rx(struct z8530_channel *c, struct sk_buff *skb)
{
dev_kfree_skb_any(skb);
}
static void z8530_rx_done(struct z8530_channel *c)
{
struct sk_buff *skb;
int ct;
if(c->rxdma_on)
{
int ready=c->dma_ready;
unsigned char *rxb=c->rx_buf[c->dma_num];
unsigned long flags;
flags=claim_dma_lock();
disable_dma(c->rxdma);
clear_dma_ff(c->rxdma);
c->rxdma_on=0;
ct=c->mtu-get_dma_residue(c->rxdma);
if(ct<0)
ct=2;
c->dma_ready=0;
if(ready)
{
c->dma_num^=1;
set_dma_mode(c->rxdma, DMA_MODE_READ|0x10);
set_dma_addr(c->rxdma, virt_to_bus(c->rx_buf[c->dma_num]));
set_dma_count(c->rxdma, c->mtu);
c->rxdma_on = 1;
enable_dma(c->rxdma);
write_zsreg(c, R0, RES_Rx_CRC);
}
else
netdev_warn(c->netdevice, "DMA flip overrun!\n");
release_dma_lock(flags);
skb = dev_alloc_skb(ct);
if (skb == NULL) {
c->netdevice->stats.rx_dropped++;
netdev_warn(c->netdevice, "Memory squeeze\n");
} else {
skb_put(skb, ct);
skb_copy_to_linear_data(skb, rxb, ct);
c->netdevice->stats.rx_packets++;
c->netdevice->stats.rx_bytes += ct;
}
c->dma_ready = 1;
} else {
RT_LOCK;
skb = c->skb;
ct=c->count;
c->skb = c->skb2;
c->count = 0;
c->max = c->mtu;
if (c->skb) {
c->dptr = c->skb->data;
c->max = c->mtu;
} else {
c->count = 0;
c->max = 0;
}
RT_UNLOCK;
c->skb2 = dev_alloc_skb(c->mtu);
if (c->skb2 == NULL)
netdev_warn(c->netdevice, "memory squeeze\n");
else
skb_put(c->skb2, c->mtu);
c->netdevice->stats.rx_packets++;
c->netdevice->stats.rx_bytes += ct;
}
if (skb) {
skb_trim(skb, ct);
c->rx_function(c, skb);
} else {
c->netdevice->stats.rx_dropped++;
netdev_err(c->netdevice, "Lost a frame\n");
}
}
static inline int spans_boundary(struct sk_buff *skb)
{
unsigned long a=(unsigned long)skb->data;
a^=(a+skb->len);
if(a&0x00010000)
return 1;
return 0;
}
netdev_tx_t z8530_queue_xmit(struct z8530_channel *c, struct sk_buff *skb)
{
unsigned long flags;
netif_stop_queue(c->netdevice);
if(c->tx_next_skb)
return NETDEV_TX_BUSY;
if(c->dma_tx && ((unsigned long)(virt_to_bus(skb->data+skb->len))>=16*1024*1024 || spans_boundary(skb)))
{
c->tx_next_ptr=c->tx_dma_buf[c->tx_dma_used];
c->tx_dma_used^=1;
skb_copy_from_linear_data(skb, c->tx_next_ptr, skb->len);
}
else
c->tx_next_ptr=skb->data;
RT_LOCK;
c->tx_next_skb=skb;
RT_UNLOCK;
spin_lock_irqsave(c->lock, flags);
z8530_tx_begin(c);
spin_unlock_irqrestore(c->lock, flags);
return NETDEV_TX_OK;
}
static int __init z85230_init_driver(void)
{
printk(banner);
return 0;
}
static void __exit z85230_cleanup_driver(void)
{
}
