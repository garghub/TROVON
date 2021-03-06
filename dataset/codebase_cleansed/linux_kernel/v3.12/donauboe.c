static int
toshoboe_checkfcs (unsigned char *buf, int len)
{
int i;
union
{
__u16 value;
__u8 bytes[2];
}
fcs;
fcs.value = INIT_FCS;
for (i = 0; i < len; ++i)
fcs.value = irda_fcs (fcs.value, *(buf++));
return fcs.value == GOOD_FCS;
}
static void
_dumpbufs (unsigned char *data, int len, char tete)
{
int i,j;
char head=tete;
for (i=0;i<len;i+=16) {
for (j=0;j<16 && i+j<len;j++) { sprintf(&dump[3*j],"%02x.",data[i+j]); }
dump [3*j]=0;
IRDA_DEBUG (2, "%c%s\n",head , dump);
head='+';
}
}
static void
toshoboe_dumpregs (struct toshoboe_cb *self)
{
__u32 ringbase;
IRDA_DEBUG (4, "%s()\n", __func__);
ringbase = INB (OBOE_RING_BASE0) << 10;
ringbase |= INB (OBOE_RING_BASE1) << 18;
ringbase |= INB (OBOE_RING_BASE2) << 26;
printk (KERN_ERR DRIVER_NAME ": Register dump:\n");
printk (KERN_ERR "Interrupts: Tx:%d Rx:%d TxUnder:%d RxOver:%d Sip:%d\n",
self->int_tx, self->int_rx, self->int_txunder, self->int_rxover,
self->int_sip);
printk (KERN_ERR "RX %02x TX %02x RingBase %08x\n",
INB (OBOE_RXSLOT), INB (OBOE_TXSLOT), ringbase);
printk (KERN_ERR "RING_SIZE %02x IER %02x ISR %02x\n",
INB (OBOE_RING_SIZE), INB (OBOE_IER), INB (OBOE_ISR));
printk (KERN_ERR "CONFIG1 %02x STATUS %02x\n",
INB (OBOE_CONFIG1), INB (OBOE_STATUS));
printk (KERN_ERR "CONFIG0 %02x%02x ENABLE %02x%02x\n",
INB (OBOE_CONFIG0H), INB (OBOE_CONFIG0L),
INB (OBOE_ENABLEH), INB (OBOE_ENABLEL));
printk (KERN_ERR "NEW_PCONFIG %02x%02x CURR_PCONFIG %02x%02x\n",
INB (OBOE_NEW_PCONFIGH), INB (OBOE_NEW_PCONFIGL),
INB (OBOE_CURR_PCONFIGH), INB (OBOE_CURR_PCONFIGL));
printk (KERN_ERR "MAXLEN %02x%02x RXCOUNT %02x%02x\n",
INB (OBOE_MAXLENH), INB (OBOE_MAXLENL),
INB (OBOE_RXCOUNTL), INB (OBOE_RXCOUNTH));
if (self->ring)
{
int i;
ringbase = virt_to_bus (self->ring);
printk (KERN_ERR "Ring at %08x:\n", ringbase);
printk (KERN_ERR "RX:");
for (i = 0; i < RX_SLOTS; ++i)
printk (" (%d,%02x)",self->ring->rx[i].len,self->ring->rx[i].control);
printk ("\n");
printk (KERN_ERR "TX:");
for (i = 0; i < RX_SLOTS; ++i)
printk (" (%d,%02x)",self->ring->tx[i].len,self->ring->tx[i].control);
printk ("\n");
}
}
static void
toshoboe_disablebm (struct toshoboe_cb *self)
{
__u8 command;
IRDA_DEBUG (4, "%s()\n", __func__);
pci_read_config_byte (self->pdev, PCI_COMMAND, &command);
command &= ~PCI_COMMAND_MASTER;
pci_write_config_byte (self->pdev, PCI_COMMAND, command);
}
static void
toshoboe_stopchip (struct toshoboe_cb *self)
{
IRDA_DEBUG (4, "%s()\n", __func__);
OUTB (0x0, OBOE_IER);
OUTB (CONFIG0H_DMA_OFF, OBOE_CONFIG0H);
OUTB (0x00, OBOE_ENABLEH);
OUTB (0x3f, OBOE_RING_BASE2);
OUTB (0xff, OBOE_RING_BASE1);
OUTB (0xff, OBOE_RING_BASE0);
OUTB (RX_LEN >> 8, OBOE_MAXLENH);
OUTB (RX_LEN & 0xff, OBOE_MAXLENL);
OUTB (0xff, OBOE_ISR);
OUTB (OBOE_ENABLEH_PHYANDCLOCK, OBOE_ENABLEH);
OUTB (OBOE_CONFIG1_OFF, OBOE_CONFIG1);
toshoboe_disablebm (self);
}
static void
toshoboe_start_DMA (struct toshoboe_cb *self, int opts)
{
OUTB (0x0, OBOE_ENABLEH);
OUTB (CONFIG0H_DMA_ON | opts, OBOE_CONFIG0H);
OUTB (OBOE_ENABLEH_PHYANDCLOCK, OBOE_ENABLEH);
PROMPT;
}
static void
toshoboe_setbaud (struct toshoboe_cb *self)
{
__u16 pconfig = 0;
__u8 config0l = 0;
IRDA_DEBUG (2, "%s(%d/%d)\n", __func__, self->speed, self->io.speed);
switch (self->speed)
{
case 2400:
case 4800:
case 9600:
case 19200:
case 38400:
case 57600:
case 115200:
#ifdef USE_MIR
case 1152000:
#endif
case 4000000:
break;
default:
printk (KERN_ERR DRIVER_NAME ": switch to unsupported baudrate %d\n",
self->speed);
return;
}
switch (self->speed)
{
case 2400:
pconfig |= 47 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
case 4800:
pconfig |= 23 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
case 9600:
pconfig |= 11 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
case 19200:
pconfig |= 5 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
case 38400:
pconfig |= 2 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
case 57600:
pconfig |= 1 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
case 115200:
pconfig |= 0 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 25 << OBOE_PCONFIG_WIDTHSHIFT;
break;
default:
OUTB (RX_LEN >> 8, OBOE_MAXLENH);
OUTB (RX_LEN & 0xff, OBOE_MAXLENL);
break;
}
switch (self->speed)
{
case 2400:
case 4800:
case 9600:
case 19200:
case 38400:
case 57600:
case 115200:
config0l = OBOE_CONFIG0L_ENSIR;
if (self->async)
{
OUTB (0x01, OBOE_MAXLENH);
OUTB (0x01, OBOE_MAXLENL);
OUTB (0x00, OBOE_MAXLENH);
}
else
{
config0l |= OBOE_CONFIG0L_ENSIRF;
OUTB (RX_LEN >> 8, OBOE_MAXLENH);
OUTB (RX_LEN & 0xff, OBOE_MAXLENL);
}
break;
#ifdef USE_MIR
case 1152000:
pconfig |= 0 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 8 << OBOE_PCONFIG_WIDTHSHIFT;
pconfig |= 1 << OBOE_PCONFIG_PREAMBLESHIFT;
config0l = OBOE_CONFIG0L_CRC16 | OBOE_CONFIG0L_ENMIR;
break;
#endif
case 4000000:
pconfig |= 0 << OBOE_PCONFIG_BAUDSHIFT;
pconfig |= 15 << OBOE_PCONFIG_PREAMBLESHIFT;
config0l = OBOE_CONFIG0L_ENFIR;
break;
}
OUTBP (pconfig >> 8, OBOE_NEW_PCONFIGH);
OUTB (pconfig & 0xff, OBOE_NEW_PCONFIGL);
OUTB (config0l, OBOE_CONFIG0L);
OUTB (0x0, OBOE_ENABLEH);
OUTB (OBOE_ENABLEH_PHYANDCLOCK, OBOE_ENABLEH);
PROMPT;
self->new_speed = 0;
self->io.speed = self->speed;
}
static void
toshoboe_enablebm (struct toshoboe_cb *self)
{
IRDA_DEBUG (4, "%s()\n", __func__);
pci_set_master (self->pdev);
}
static void
toshoboe_initring (struct toshoboe_cb *self)
{
int i;
IRDA_DEBUG (4, "%s()\n", __func__);
for (i = 0; i < TX_SLOTS; ++i)
{
self->ring->tx[i].len = 0;
self->ring->tx[i].control = 0x00;
self->ring->tx[i].address = virt_to_bus (self->tx_bufs[i]);
}
for (i = 0; i < RX_SLOTS; ++i)
{
self->ring->rx[i].len = RX_LEN;
self->ring->rx[i].len = 0;
self->ring->rx[i].address = virt_to_bus (self->rx_bufs[i]);
self->ring->rx[i].control = OBOE_CTL_RX_HW_OWNS;
}
}
static void
toshoboe_resetptrs (struct toshoboe_cb *self)
{
OUTB (0x0, OBOE_ENABLEH);
OUTBP (CONFIG0H_DMA_OFF, OBOE_CONFIG0H);
OUTB (OBOE_ENABLEH_PHYANDCLOCK, OBOE_ENABLEH);
self->rxs = inb_p (OBOE_RXSLOT) & OBOE_SLOT_MASK;
self->txs = inb_p (OBOE_TXSLOT) & OBOE_SLOT_MASK;
}
static void
toshoboe_initptrs (struct toshoboe_cb *self)
{
toshoboe_resetptrs (self);
OUTB (0x0, OBOE_ENABLEH);
OUTB (CONFIG0H_DMA_ON, OBOE_CONFIG0H);
OUTB (OBOE_ENABLEH_PHYANDCLOCK, OBOE_ENABLEH);
self->txpending = 0;
}
static void
toshoboe_startchip (struct toshoboe_cb *self)
{
__u32 physaddr;
IRDA_DEBUG (4, "%s()\n", __func__);
toshoboe_initring (self);
toshoboe_enablebm (self);
OUTBP (OBOE_CONFIG1_RESET, OBOE_CONFIG1);
OUTBP (OBOE_CONFIG1_ON, OBOE_CONFIG1);
OUTB (0, OBOE_ENABLEH);
OUTB (RING_SIZE, OBOE_RING_SIZE);
OUTB (0xff, OBOE_ISR);
OUTB (OBOE_INT_TXDONE | OBOE_INT_RXDONE |
OBOE_INT_TXUNDER | OBOE_INT_RXOVER | OBOE_INT_SIP , OBOE_IER);
OUTB (0xff, OBOE_ISR);
OUTB (RX_LEN >> 8, OBOE_MAXLENH);
OUTB (RX_LEN & 0xff, OBOE_MAXLENL);
OUTB (CONFIG0H_DMA_OFF, OBOE_CONFIG0H);
physaddr = virt_to_bus (self->ring);
IRDA_ASSERT ((physaddr & 0x3ff) == 0,
printk (KERN_ERR DRIVER_NAME "ring not correctly aligned\n");
return;);
OUTB ((physaddr >> 10) & 0xff, OBOE_RING_BASE0);
OUTB ((physaddr >> 18) & 0xff, OBOE_RING_BASE1);
OUTB ((physaddr >> 26) & 0x3f, OBOE_RING_BASE2);
OUTB (CONFIG0H_DMA_ON, OBOE_CONFIG0H);
OUTB (OBOE_ENABLEH_PHYANDCLOCK, OBOE_ENABLEH);
self->speed = 9600;
toshoboe_setbaud (self);
toshoboe_initptrs (self);
}
static void
toshoboe_isntstuck (struct toshoboe_cb *self)
{
}
static void
toshoboe_checkstuck (struct toshoboe_cb *self)
{
unsigned long flags;
if (0)
{
spin_lock_irqsave(&self->spinlock, flags);
printk (KERN_ERR DRIVER_NAME ": Resetting chip\n");
toshoboe_stopchip (self);
toshoboe_startchip (self);
spin_unlock_irqrestore(&self->spinlock, flags);
}
}
static int
toshoboe_makemttpacket (struct toshoboe_cb *self, void *buf, int mtt)
{
int xbofs;
xbofs = ((int) (mtt/100)) * (int) (self->speed);
xbofs=xbofs/80000;
xbofs++;
IRDA_DEBUG (2, DRIVER_NAME
": generated mtt of %d bytes for %d us at %d baud\n"
, xbofs,mtt,self->speed);
if (xbofs > TX_LEN)
{
printk (KERN_ERR DRIVER_NAME ": wanted %d bytes MTT but TX_LEN is %d\n",
xbofs, TX_LEN);
xbofs = TX_LEN;
}
memset (buf, XBOF, xbofs);
return xbofs;
}
static void
toshoboe_dumptx (struct toshoboe_cb *self)
{
int i;
PROBE_DEBUG(KERN_WARNING "TX:");
for (i = 0; i < RX_SLOTS; ++i)
PROBE_DEBUG(" (%d,%02x)",self->ring->tx[i].len,self->ring->tx[i].control);
PROBE_DEBUG(" [%d]\n",self->speed);
}
static void
toshoboe_dumprx (struct toshoboe_cb *self, int score)
{
int i;
PROBE_DEBUG(" %d\nRX:",score);
for (i = 0; i < RX_SLOTS; ++i)
PROBE_DEBUG(" (%d,%02x)",self->ring->rx[i].len,self->ring->rx[i].control);
PROBE_DEBUG("\n");
}
static inline int
stuff_byte (__u8 byte, __u8 * buf)
{
switch (byte)
{
case BOF:
case EOF:
case CE:
buf[0] = CE;
buf[1] = byte ^ IRDA_TRANS;
return 2;
default:
buf[0] = byte;
return 1;
}
}
static irqreturn_t
toshoboe_probeinterrupt (int irq, void *dev_id)
{
struct toshoboe_cb *self = dev_id;
__u8 irqstat;
irqstat = INB (OBOE_ISR);
if (!(irqstat & OBOE_INT_MASK))
return IRQ_NONE;
OUTB (irqstat, OBOE_ISR);
if (irqstat & OBOE_INT_TXDONE)
{
int txp;
self->int_tx++;
PROBE_DEBUG("T");
txp = INB (OBOE_TXSLOT) & OBOE_SLOT_MASK;
if (self->ring->tx[txp].control & OBOE_CTL_TX_HW_OWNS)
{
self->int_tx+=100;
PROBE_DEBUG("S");
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX | OBOE_CONFIG0H_LOOP);
}
}
if (irqstat & OBOE_INT_RXDONE) {
self->int_rx++;
PROBE_DEBUG("R"); }
if (irqstat & OBOE_INT_TXUNDER) {
self->int_txunder++;
PROBE_DEBUG("U"); }
if (irqstat & OBOE_INT_RXOVER) {
self->int_rxover++;
PROBE_DEBUG("O"); }
if (irqstat & OBOE_INT_SIP) {
self->int_sip++;
PROBE_DEBUG("I"); }
return IRQ_HANDLED;
}
static int
toshoboe_maketestpacket (unsigned char *buf, int badcrc, int fir)
{
int i;
int len = 0;
union
{
__u16 value;
__u8 bytes[2];
}
fcs;
if (fir)
{
memset (buf, 0, TT_LEN);
return TT_LEN;
}
fcs.value = INIT_FCS;
memset (buf, XBOF, 10);
len += 10;
buf[len++] = BOF;
for (i = 0; i < TT_LEN; ++i)
{
len += stuff_byte (i, buf + len);
fcs.value = irda_fcs (fcs.value, i);
}
len += stuff_byte (fcs.bytes[0] ^ badcrc, buf + len);
len += stuff_byte (fcs.bytes[1] ^ badcrc, buf + len);
buf[len++] = EOF;
len++;
return len;
}
static int
toshoboe_probefail (struct toshoboe_cb *self, char *msg)
{
printk (KERN_ERR DRIVER_NAME "probe(%d) failed %s\n",self-> speed, msg);
toshoboe_dumpregs (self);
toshoboe_stopchip (self);
free_irq (self->io.irq, (void *) self);
return 0;
}
static int
toshoboe_numvalidrcvs (struct toshoboe_cb *self)
{
int i, ret = 0;
for (i = 0; i < RX_SLOTS; ++i)
if ((self->ring->rx[i].control & 0xe0) == 0)
ret++;
return ret;
}
static int
toshoboe_numrcvs (struct toshoboe_cb *self)
{
int i, ret = 0;
for (i = 0; i < RX_SLOTS; ++i)
if (!(self->ring->rx[i].control & OBOE_CTL_RX_HW_OWNS))
ret++;
return ret;
}
static int
toshoboe_probe (struct toshoboe_cb *self)
{
int i, j, n;
#ifdef USE_MIR
static const int bauds[] = { 9600, 115200, 4000000, 1152000 };
#else
static const int bauds[] = { 9600, 115200, 4000000 };
#endif
unsigned long flags;
IRDA_DEBUG (4, "%s()\n", __func__);
if (request_irq (self->io.irq, toshoboe_probeinterrupt,
self->io.irqflags, "toshoboe", (void *) self))
{
printk (KERN_ERR DRIVER_NAME ": probe failed to allocate irq %d\n",
self->io.irq);
return 0;
}
for (j = 0; j < ARRAY_SIZE(bauds); ++j)
{
int fir = (j > 1);
toshoboe_stopchip (self);
spin_lock_irqsave(&self->spinlock, flags);
toshoboe_startchip (self);
self->int_rx = self->int_tx = 0;
self->speed = bauds[j];
toshoboe_setbaud (self);
toshoboe_initptrs (self);
spin_unlock_irqrestore(&self->spinlock, flags);
self->ring->tx[self->txs].control =
(fir) ? OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX
: OBOE_CTL_TX_HW_OWNS ;
self->ring->tx[self->txs].len =
toshoboe_maketestpacket (self->tx_bufs[self->txs], 0, fir);
self->txs++;
self->txs %= TX_SLOTS;
self->ring->tx[self->txs].control =
(fir) ? OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_SIP
: OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX ;
self->ring->tx[self->txs].len =
toshoboe_maketestpacket (self->tx_bufs[self->txs], 0, fir);
self->txs++;
self->txs %= TX_SLOTS;
self->ring->tx[self->txs].control =
(fir) ? OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX
: OBOE_CTL_TX_HW_OWNS ;
self->ring->tx[self->txs].len =
toshoboe_maketestpacket (self->tx_bufs[self->txs], 0, fir);
self->txs++;
self->txs %= TX_SLOTS;
self->ring->tx[self->txs].control =
(fir) ? OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX
| OBOE_CTL_TX_SIP | OBOE_CTL_TX_BAD_CRC
: OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX ;
self->ring->tx[self->txs].len =
toshoboe_maketestpacket (self->tx_bufs[self->txs], 0, fir);
self->txs++;
self->txs %= TX_SLOTS;
toshoboe_dumptx (self);
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX | OBOE_CONFIG0H_LOOP);
i = 0;
n = fir ? 1 : 4;
while (toshoboe_numvalidrcvs (self) != n)
{
if (i > 4800)
return toshoboe_probefail (self, "filter test");
udelay ((9600*(TT_LEN+16))/self->speed);
i++;
}
n = fir ? 203 : 102;
while ((toshoboe_numrcvs(self) != self->int_rx) || (self->int_tx != n))
{
if (i > 4800)
return toshoboe_probefail (self, "interrupt test");
udelay ((9600*(TT_LEN+16))/self->speed);
i++;
}
toshoboe_dumprx (self,i);
}
toshoboe_stopchip (self);
self->int_rx = self->int_tx = 0;
spin_lock_irqsave(&self->spinlock, flags);
toshoboe_startchip (self);
spin_unlock_irqrestore(&self->spinlock, flags);
self->async = 1;
self->speed = 115200;
toshoboe_setbaud (self);
self->ring->tx[self->txs].control =
OBOE_CTL_TX_RTCENTX | OBOE_CTL_TX_HW_OWNS;
self->ring->tx[self->txs].len = 4;
((unsigned char *) self->tx_bufs[self->txs])[0] = 'f';
((unsigned char *) self->tx_bufs[self->txs])[1] = 'i';
((unsigned char *) self->tx_bufs[self->txs])[2] = 's';
((unsigned char *) self->tx_bufs[self->txs])[3] = 'h';
toshoboe_dumptx (self);
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX | OBOE_CONFIG0H_LOOP);
i = 0;
while (toshoboe_numvalidrcvs (self) != 4)
{
if (i > 100)
return toshoboe_probefail (self, "Async test");
udelay (100);
i++;
}
while ((toshoboe_numrcvs (self) != self->int_rx) || (self->int_tx != 1))
{
if (i > 100)
return toshoboe_probefail (self, "Async interrupt test");
udelay (100);
i++;
}
toshoboe_dumprx (self,i);
self->async = 0;
self->speed = 9600;
toshoboe_setbaud (self);
toshoboe_stopchip (self);
free_irq (self->io.irq, (void *) self);
printk (KERN_WARNING DRIVER_NAME ": Self test passed ok\n");
return 1;
}
static netdev_tx_t
toshoboe_hard_xmit (struct sk_buff *skb, struct net_device *dev)
{
struct toshoboe_cb *self;
__s32 speed;
int mtt, len, ctl;
unsigned long flags;
struct irda_skb_cb *cb = (struct irda_skb_cb *) skb->cb;
self = netdev_priv(dev);
IRDA_ASSERT (self != NULL, return NETDEV_TX_OK; );
IRDA_DEBUG (1, "%s.tx:%x(%x)%x\n", __func__
,skb->len,self->txpending,INB (OBOE_ENABLEH));
if (!cb->magic) {
IRDA_DEBUG (2, "%s.Not IrLAP:%x\n", __func__, cb->magic);
#ifdef DUMP_PACKETS
_dumpbufs(skb->data,skb->len,'>');
#endif
}
if (self->new_speed)
return NETDEV_TX_BUSY;
if (self->stopped)
return NETDEV_TX_BUSY;
toshoboe_checkstuck (self);
speed=irda_get_next_speed(skb);
if ((speed != self->io.speed) && (speed != -1))
{
spin_lock_irqsave(&self->spinlock, flags);
if (self->txpending || skb->len)
{
self->new_speed = speed;
IRDA_DEBUG (1, "%s: Queued TxDone scheduled speed change %d\n" ,
__func__, speed);
if (!skb->len)
{
spin_unlock_irqrestore(&self->spinlock, flags);
dev_kfree_skb (skb);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
spin_unlock_irqrestore(&self->spinlock, flags);
}
else
{
self->speed = speed;
toshoboe_setbaud (self);
spin_unlock_irqrestore(&self->spinlock, flags);
dev_kfree_skb (skb);
return NETDEV_TX_OK;
}
}
if ((mtt = irda_get_mtt(skb)))
{
spin_lock_irqsave(&self->spinlock, flags);
if (self->txpending)
{
spin_unlock_irqrestore(&self->spinlock, flags);
return NETDEV_TX_BUSY;
}
mtt = toshoboe_makemttpacket (self, self->tx_bufs[self->txs], mtt);
IRDA_DEBUG (1, "%s.mtt:%x(%x)%d\n", __func__
,skb->len,mtt,self->txpending);
if (mtt)
{
self->ring->tx[self->txs].len = mtt & 0xfff;
ctl = OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX;
if (INB (OBOE_ENABLEH) & OBOE_ENABLEH_FIRON)
{
ctl |= OBOE_CTL_TX_BAD_CRC | OBOE_CTL_TX_SIP ;
}
#ifdef USE_MIR
else if (INB (OBOE_ENABLEH) & OBOE_ENABLEH_MIRON)
{
ctl |= OBOE_CTL_TX_BAD_CRC;
}
#endif
self->ring->tx[self->txs].control = ctl;
OUTB (0x0, OBOE_ENABLEH);
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX | OBOE_CONFIG0H_LOOP);
self->txpending++;
self->txs++;
self->txs %= TX_SLOTS;
}
else
{
printk(KERN_ERR DRIVER_NAME ": problem with mtt packet - ignored\n");
}
spin_unlock_irqrestore(&self->spinlock, flags);
}
#ifdef DUMP_PACKETS
dumpbufs(skb->data,skb->len,'>');
#endif
spin_lock_irqsave(&self->spinlock, flags);
if (self->ring->tx[self->txs].control & OBOE_CTL_TX_HW_OWNS)
{
IRDA_DEBUG (0, "%s.ful:%x(%x)%x\n", __func__
,skb->len, self->ring->tx[self->txs].control, self->txpending);
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX);
spin_unlock_irqrestore(&self->spinlock, flags);
return NETDEV_TX_BUSY;
}
if (INB (OBOE_ENABLEH) & OBOE_ENABLEH_SIRON)
{
len = async_wrap_skb (skb, self->tx_bufs[self->txs], TX_BUF_SZ);
}
else
{
len = skb->len;
skb_copy_from_linear_data(skb, self->tx_bufs[self->txs], len);
}
self->ring->tx[self->txs].len = len & 0x0fff;
ctl = OBOE_CTL_TX_HW_OWNS | OBOE_CTL_TX_RTCENTX;
if (INB (OBOE_ENABLEH) & OBOE_ENABLEH_FIRON)
{
ctl |= OBOE_CTL_TX_SIP ;
}
self->ring->tx[self->txs].control = ctl;
if (!self->txpending)
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX);
self->txpending++;
self->txs++;
self->txs %= TX_SLOTS;
spin_unlock_irqrestore(&self->spinlock, flags);
dev_kfree_skb (skb);
return NETDEV_TX_OK;
}
static irqreturn_t
toshoboe_interrupt (int irq, void *dev_id)
{
struct toshoboe_cb *self = dev_id;
__u8 irqstat;
struct sk_buff *skb = NULL;
irqstat = INB (OBOE_ISR);
if (!(irqstat & OBOE_INT_MASK))
return IRQ_NONE;
OUTB (irqstat, OBOE_ISR);
toshoboe_isntstuck (self);
if (irqstat & OBOE_INT_TXDONE)
{
int txp, txpc;
int i;
txp = self->txpending;
self->txpending = 0;
for (i = 0; i < TX_SLOTS; ++i)
{
if (self->ring->tx[i].control & OBOE_CTL_TX_HW_OWNS)
self->txpending++;
}
IRDA_DEBUG (1, "%s.txd(%x)%x/%x\n", __func__
,irqstat,txp,self->txpending);
txp = INB (OBOE_TXSLOT) & OBOE_SLOT_MASK;
if (self->ring->tx[txp].control & OBOE_CTL_TX_HW_OWNS)
{
txpc = txp;
#ifdef OPTIMIZE_TX
while (self->ring->tx[txpc].control & OBOE_CTL_TX_HW_OWNS)
{
txp = txpc;
txpc++;
txpc %= TX_SLOTS;
self->netdev->stats.tx_packets++;
if (self->ring->tx[txpc].control & OBOE_CTL_TX_HW_OWNS)
self->ring->tx[txp].control &= ~OBOE_CTL_TX_RTCENTX;
}
self->netdev->stats.tx_packets--;
#else
self->netdev->stats.tx_packets++;
#endif
toshoboe_start_DMA(self, OBOE_CONFIG0H_ENTX);
}
if ((!self->txpending) && (self->new_speed))
{
self->speed = self->new_speed;
IRDA_DEBUG (1, "%s: Executed TxDone scheduled speed change %d\n",
__func__, self->speed);
toshoboe_setbaud (self);
}
if (!self->new_speed)
netif_wake_queue(self->netdev);
}
if (irqstat & OBOE_INT_RXDONE)
{
while (!(self->ring->rx[self->rxs].control & OBOE_CTL_RX_HW_OWNS))
{
int len = self->ring->rx[self->rxs].len;
skb = NULL;
IRDA_DEBUG (3, "%s.rcv:%x(%x)\n", __func__
,len,self->ring->rx[self->rxs].control);
#ifdef DUMP_PACKETS
dumpbufs(self->rx_bufs[self->rxs],len,'<');
#endif
if (self->ring->rx[self->rxs].control == 0)
{
__u8 enable = INB (OBOE_ENABLEH);
if (enable & OBOE_ENABLEH_SIRON)
{
if (!toshoboe_checkfcs (self->rx_bufs[self->rxs], len))
len = 0;
if (len > 1)
len -= 2;
else
len = 0;
IRDA_DEBUG (1, "%s.SIR:%x(%x)\n", __func__, len,enable);
}
#ifdef USE_MIR
else if (enable & OBOE_ENABLEH_MIRON)
{
if (len > 1)
len -= 2;
else
len = 0;
IRDA_DEBUG (2, "%s.MIR:%x(%x)\n", __func__, len,enable);
}
#endif
else if (enable & OBOE_ENABLEH_FIRON)
{
if (len > 3)
len -= 4;
else
len = 0;
IRDA_DEBUG (1, "%s.FIR:%x(%x)\n", __func__, len,enable);
}
else
IRDA_DEBUG (0, "%s.?IR:%x(%x)\n", __func__, len,enable);
if (len)
{
skb = dev_alloc_skb (len + 1);
if (skb)
{
skb_reserve (skb, 1);
skb_put (skb, len);
skb_copy_to_linear_data(skb, self->rx_bufs[self->rxs],
len);
self->netdev->stats.rx_packets++;
skb->dev = self->netdev;
skb_reset_mac_header(skb);
skb->protocol = htons (ETH_P_IRDA);
}
else
{
printk (KERN_INFO
"%s(), memory squeeze, dropping frame.\n",
__func__);
}
}
}
else
{
IRDA_DEBUG (0, "%s.err:%x(%x)\n", __func__
,len,self->ring->rx[self->rxs].control);
}
self->ring->rx[self->rxs].len = 0x0;
self->ring->rx[self->rxs].control = OBOE_CTL_RX_HW_OWNS;
self->rxs++;
self->rxs %= RX_SLOTS;
if (skb)
netif_rx (skb);
}
}
if (irqstat & OBOE_INT_TXUNDER)
{
printk (KERN_WARNING DRIVER_NAME ": tx fifo underflow\n");
}
if (irqstat & OBOE_INT_RXOVER)
{
printk (KERN_WARNING DRIVER_NAME ": rx fifo overflow\n");
}
if (irqstat & OBOE_INT_SIP)
{
self->int_sip++;
IRDA_DEBUG (1, "%s.sip:%x(%x)%x\n", __func__
,self->int_sip,irqstat,self->txpending);
}
return IRQ_HANDLED;
}
static int
toshoboe_net_open (struct net_device *dev)
{
struct toshoboe_cb *self;
unsigned long flags;
int rc;
IRDA_DEBUG (4, "%s()\n", __func__);
self = netdev_priv(dev);
if (self->async)
return -EBUSY;
if (self->stopped)
return 0;
rc = request_irq (self->io.irq, toshoboe_interrupt,
IRQF_SHARED | IRQF_DISABLED, dev->name, self);
if (rc)
return rc;
spin_lock_irqsave(&self->spinlock, flags);
toshoboe_startchip (self);
spin_unlock_irqrestore(&self->spinlock, flags);
netif_start_queue(dev);
self->irlap = irlap_open (dev, &self->qos, driver_name);
self->irdad = 1;
return 0;
}
static int
toshoboe_net_close (struct net_device *dev)
{
struct toshoboe_cb *self;
IRDA_DEBUG (4, "%s()\n", __func__);
IRDA_ASSERT (dev != NULL, return -1; );
self = netdev_priv(dev);
netif_stop_queue(dev);
if (self->irlap)
irlap_close (self->irlap);
self->irlap = NULL;
self->irdad = 0;
free_irq (self->io.irq, (void *) self);
if (!self->stopped)
{
toshoboe_stopchip (self);
}
return 0;
}
static int
toshoboe_net_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
struct if_irda_req *irq = (struct if_irda_req *) rq;
struct toshoboe_cb *self;
unsigned long flags;
int ret = 0;
IRDA_ASSERT (dev != NULL, return -1; );
self = netdev_priv(dev);
IRDA_ASSERT (self != NULL, return -1; );
IRDA_DEBUG (5, "%s(), %s, (cmd=0x%X)\n", __func__, dev->name, cmd);
spin_lock_irqsave(&self->spinlock, flags);
switch (cmd)
{
case SIOCSBANDWIDTH:
IRDA_DEBUG (1, "%s(BANDWIDTH), %s, (%X/%ld\n", __func__
,dev->name, INB (OBOE_STATUS), irq->ifr_baudrate );
if (!in_interrupt () && !capable (CAP_NET_ADMIN)) {
ret = -EPERM;
goto out;
}
self->new_speed = irq->ifr_baudrate;
break;
case SIOCSMEDIABUSY:
IRDA_DEBUG (1, "%s(MEDIABUSY), %s, (%X/%x)\n", __func__
,dev->name, INB (OBOE_STATUS), capable (CAP_NET_ADMIN) );
if (!capable (CAP_NET_ADMIN)) {
ret = -EPERM;
goto out;
}
irda_device_set_media_busy (self->netdev, TRUE);
break;
case SIOCGRECEIVING:
irq->ifr_receiving = (INB (OBOE_STATUS) & OBOE_STATUS_RXBUSY) ? 1 : 0;
IRDA_DEBUG (3, "%s(RECEIVING), %s, (%X/%x)\n", __func__
,dev->name, INB (OBOE_STATUS), irq->ifr_receiving );
break;
default:
IRDA_DEBUG (1, "%s(?), %s, (cmd=0x%X)\n", __func__, dev->name, cmd);
ret = -EOPNOTSUPP;
}
out:
spin_unlock_irqrestore(&self->spinlock, flags);
return ret;
}
static void
toshoboe_close (struct pci_dev *pci_dev)
{
int i;
struct toshoboe_cb *self = pci_get_drvdata(pci_dev);
IRDA_DEBUG (4, "%s()\n", __func__);
IRDA_ASSERT (self != NULL, return; );
if (!self->stopped)
{
toshoboe_stopchip (self);
}
release_region (self->io.fir_base, self->io.fir_ext);
for (i = 0; i < TX_SLOTS; ++i)
{
kfree (self->tx_bufs[i]);
self->tx_bufs[i] = NULL;
}
for (i = 0; i < RX_SLOTS; ++i)
{
kfree (self->rx_bufs[i]);
self->rx_bufs[i] = NULL;
}
unregister_netdev(self->netdev);
kfree (self->ringbuf);
self->ringbuf = NULL;
self->ring = NULL;
free_netdev(self->netdev);
}
static int
toshoboe_open (struct pci_dev *pci_dev, const struct pci_device_id *pdid)
{
struct toshoboe_cb *self;
struct net_device *dev;
int i = 0;
int ok = 0;
int err;
IRDA_DEBUG (4, "%s()\n", __func__);
if ((err=pci_enable_device(pci_dev)))
return err;
dev = alloc_irdadev(sizeof (struct toshoboe_cb));
if (dev == NULL)
{
printk (KERN_ERR DRIVER_NAME ": can't allocate memory for "
"IrDA control block\n");
return -ENOMEM;
}
self = netdev_priv(dev);
self->netdev = dev;
self->pdev = pci_dev;
self->base = pci_resource_start(pci_dev,0);
self->io.fir_base = self->base;
self->io.fir_ext = OBOE_IO_EXTENT;
self->io.irq = pci_dev->irq;
self->io.irqflags = IRQF_SHARED | IRQF_DISABLED;
self->speed = self->io.speed = 9600;
self->async = 0;
if (NULL==request_region (self->io.fir_base, self->io.fir_ext, driver_name))
{
printk (KERN_ERR DRIVER_NAME ": can't get iobase of 0x%03x\n"
,self->io.fir_base);
err = -EBUSY;
goto freeself;
}
spin_lock_init(&self->spinlock);
irda_init_max_qos_capabilies (&self->qos);
self->qos.baud_rate.bits = 0;
if (max_baud >= 2400)
self->qos.baud_rate.bits |= IR_2400;
if (max_baud >= 9600)
self->qos.baud_rate.bits |= IR_9600;
if (max_baud >= 19200)
self->qos.baud_rate.bits |= IR_19200;
if (max_baud >= 115200)
self->qos.baud_rate.bits |= IR_115200;
#ifdef USE_MIR
if (max_baud >= 1152000)
{
self->qos.baud_rate.bits |= IR_1152000;
}
#endif
if (max_baud >= 4000000)
{
self->qos.baud_rate.bits |= (IR_4000000 << 8);
}
self->qos.min_turn_time.bits = 0xff;
irda_qos_bits_to_value (&self->qos);
self->ringbuf = kmalloc(OBOE_RING_LEN << 1, GFP_KERNEL);
if (!self->ringbuf)
{
err = -ENOMEM;
goto freeregion;
}
#if (BITS_PER_LONG == 64)
#error broken on 64-bit: casts pointer to 32-bit, and then back to pointer.
#endif
{
unsigned long addr;
addr = (__u32) self->ringbuf;
addr &= ~(OBOE_RING_LEN - 1);
addr += OBOE_RING_LEN;
self->ring = (struct OboeRing *) addr;
}
memset (self->ring, 0, OBOE_RING_LEN);
self->io.mem_base = (__u32) self->ring;
ok = 1;
for (i = 0; i < TX_SLOTS; ++i)
{
self->tx_bufs[i] = kmalloc (TX_BUF_SZ, GFP_KERNEL);
if (!self->tx_bufs[i])
ok = 0;
}
for (i = 0; i < RX_SLOTS; ++i)
{
self->rx_bufs[i] = kmalloc (RX_BUF_SZ, GFP_KERNEL);
if (!self->rx_bufs[i])
ok = 0;
}
if (!ok)
{
err = -ENOMEM;
goto freebufs;
}
#ifdef USE_PROBE
if (do_probe)
if (!toshoboe_probe (self))
{
err = -ENODEV;
goto freebufs;
}
#endif
SET_NETDEV_DEV(dev, &pci_dev->dev);
dev->netdev_ops = &toshoboe_netdev_ops;
err = register_netdev(dev);
if (err)
{
printk (KERN_ERR DRIVER_NAME ": register_netdev() failed\n");
err = -ENOMEM;
goto freebufs;
}
printk (KERN_INFO "IrDA: Registered device %s\n", dev->name);
pci_set_drvdata(pci_dev,self);
printk (KERN_INFO DRIVER_NAME ": Using multiple tasks\n");
return 0;
freebufs:
for (i = 0; i < TX_SLOTS; ++i)
kfree (self->tx_bufs[i]);
for (i = 0; i < RX_SLOTS; ++i)
kfree (self->rx_bufs[i]);
kfree(self->ringbuf);
freeregion:
release_region (self->io.fir_base, self->io.fir_ext);
freeself:
free_netdev(dev);
return err;
}
static int
toshoboe_gotosleep (struct pci_dev *pci_dev, pm_message_t crap)
{
struct toshoboe_cb *self = pci_get_drvdata(pci_dev);
unsigned long flags;
int i = 10;
IRDA_DEBUG (4, "%s()\n", __func__);
if (!self || self->stopped)
return 0;
if ((!self->irdad) && (!self->async))
return 0;
while ((i--) && (self->txpending))
msleep(10);
spin_lock_irqsave(&self->spinlock, flags);
toshoboe_stopchip (self);
self->stopped = 1;
self->txpending = 0;
spin_unlock_irqrestore(&self->spinlock, flags);
return 0;
}
static int
toshoboe_wakeup (struct pci_dev *pci_dev)
{
struct toshoboe_cb *self = pci_get_drvdata(pci_dev);
unsigned long flags;
IRDA_DEBUG (4, "%s()\n", __func__);
if (!self || !self->stopped)
return 0;
if ((!self->irdad) && (!self->async))
return 0;
spin_lock_irqsave(&self->spinlock, flags);
toshoboe_startchip (self);
self->stopped = 0;
netif_wake_queue(self->netdev);
spin_unlock_irqrestore(&self->spinlock, flags);
return 0;
}
static int __init
donauboe_init (void)
{
return pci_register_driver(&donauboe_pci_driver);
}
static void __exit
donauboe_cleanup (void)
{
pci_unregister_driver(&donauboe_pci_driver);
}
