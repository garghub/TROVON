static int __init w83977af_init(void)
{
int i;
IRDA_DEBUG(0, "%s()\n", __func__ );
for (i=0; i < ARRAY_SIZE(dev_self) && io[i] < 2000; i++) {
if (w83977af_open(i, io[i], irq[i], dma[i]) == 0)
return 0;
}
return -ENODEV;
}
static void __exit w83977af_cleanup(void)
{
int i;
IRDA_DEBUG(4, "%s()\n", __func__ );
for (i=0; i < ARRAY_SIZE(dev_self); i++) {
if (dev_self[i])
w83977af_close(dev_self[i]);
}
}
static int w83977af_open(int i, unsigned int iobase, unsigned int irq,
unsigned int dma)
{
struct net_device *dev;
struct w83977af_ir *self;
int err;
IRDA_DEBUG(0, "%s()\n", __func__ );
if (!request_region(iobase, CHIP_IO_EXTENT, driver_name)) {
IRDA_DEBUG(0, "%s(), can't get iobase of 0x%03x\n",
__func__ , iobase);
return -ENODEV;
}
if (w83977af_probe(iobase, irq, dma) == -1) {
err = -1;
goto err_out;
}
dev = alloc_irdadev(sizeof(struct w83977af_ir));
if (dev == NULL) {
printk( KERN_ERR "IrDA: Can't allocate memory for "
"IrDA control block!\n");
err = -ENOMEM;
goto err_out;
}
self = netdev_priv(dev);
spin_lock_init(&self->lock);
self->io.fir_base = iobase;
self->io.irq = irq;
self->io.fir_ext = CHIP_IO_EXTENT;
self->io.dma = dma;
self->io.fifo_size = 32;
irda_init_max_qos_capabilies(&self->qos);
self->qos.baud_rate.bits = IR_9600|IR_19200|IR_38400|IR_57600|
IR_115200|IR_576000|IR_1152000|(IR_4000000 << 8);
self->qos.min_turn_time.bits = qos_mtt_bits;
irda_qos_bits_to_value(&self->qos);
self->rx_buff.truesize = 14384;
self->tx_buff.truesize = 4000;
self->rx_buff.head =
dma_alloc_coherent(NULL, self->rx_buff.truesize,
&self->rx_buff_dma, GFP_KERNEL | __GFP_ZERO);
if (self->rx_buff.head == NULL) {
err = -ENOMEM;
goto err_out1;
}
self->tx_buff.head =
dma_alloc_coherent(NULL, self->tx_buff.truesize,
&self->tx_buff_dma, GFP_KERNEL | __GFP_ZERO);
if (self->tx_buff.head == NULL) {
err = -ENOMEM;
goto err_out2;
}
self->rx_buff.in_frame = FALSE;
self->rx_buff.state = OUTSIDE_FRAME;
self->tx_buff.data = self->tx_buff.head;
self->rx_buff.data = self->rx_buff.head;
self->netdev = dev;
dev->netdev_ops = &w83977_netdev_ops;
err = register_netdev(dev);
if (err) {
IRDA_ERROR("%s(), register_netdevice() failed!\n", __func__);
goto err_out3;
}
IRDA_MESSAGE("IrDA: Registered device %s\n", dev->name);
dev_self[i] = self;
return 0;
err_out3:
dma_free_coherent(NULL, self->tx_buff.truesize,
self->tx_buff.head, self->tx_buff_dma);
err_out2:
dma_free_coherent(NULL, self->rx_buff.truesize,
self->rx_buff.head, self->rx_buff_dma);
err_out1:
free_netdev(dev);
err_out:
release_region(iobase, CHIP_IO_EXTENT);
return err;
}
static int w83977af_close(struct w83977af_ir *self)
{
int iobase;
IRDA_DEBUG(0, "%s()\n", __func__ );
iobase = self->io.fir_base;
#ifdef CONFIG_USE_W977_PNP
w977_efm_enter(efio);
w977_select_device(W977_DEVICE_IR, efio);
w977_write_reg(0x30, 0x00, efio);
w977_efm_exit(efio);
#endif
unregister_netdev(self->netdev);
IRDA_DEBUG(0 , "%s(), Releasing Region %03x\n",
__func__ , self->io.fir_base);
release_region(self->io.fir_base, self->io.fir_ext);
if (self->tx_buff.head)
dma_free_coherent(NULL, self->tx_buff.truesize,
self->tx_buff.head, self->tx_buff_dma);
if (self->rx_buff.head)
dma_free_coherent(NULL, self->rx_buff.truesize,
self->rx_buff.head, self->rx_buff_dma);
free_netdev(self->netdev);
return 0;
}
static int w83977af_probe(int iobase, int irq, int dma)
{
int version;
int i;
for (i=0; i < 2; i++) {
IRDA_DEBUG( 0, "%s()\n", __func__ );
#ifdef CONFIG_USE_W977_PNP
w977_efm_enter(efbase[i]);
w977_select_device(W977_DEVICE_IR, efbase[i]);
w977_write_reg(0x60, (iobase >> 8) & 0xff, efbase[i]);
w977_write_reg(0x61, (iobase) & 0xff, efbase[i]);
w977_write_reg(0x70, irq, efbase[i]);
#ifdef CONFIG_ARCH_NETWINDER
w977_write_reg(0x74, dma+1, efbase[i]);
#else
w977_write_reg(0x74, dma, efbase[i]);
#endif
w977_write_reg(0x75, 0x04, efbase[i]);
w977_write_reg(0xf0, APEDCRC|ENBNKSEL, efbase[i]);
w977_write_reg(0x30, 0x01, efbase[i]);
w977_efm_exit(efbase[i]);
#endif
switch_bank(iobase, SET2);
outb(iobase+2, 0x00);
switch_bank(iobase, SET0);
outb(HCR_EN_IRQ, iobase+HCR);
switch_bank(iobase, SET2);
outb(inb(iobase+ADCR1) | ADCR1_ADV_SL, iobase+ADCR1);
switch_bank(iobase, SET0);
outb(HCR_SIR, iobase+HCR);
switch_bank(iobase, SET3);
version = inb(iobase+AUID);
if (0x10 == (version & 0xf0)) {
efio = efbase[i];
switch_bank(iobase, SET2);
outb(ADCR2_RXFS32|ADCR2_TXFS32, iobase+ADCR2);
switch_bank(iobase, SET0);
outb(UFR_RXTL|UFR_TXTL|UFR_TXF_RST|UFR_RXF_RST|
UFR_EN_FIFO,iobase+UFR);
switch_bank(iobase, SET4);
outb(2048 & 0xff, iobase+6);
outb((2048 >> 8) & 0x1f, iobase+7);
switch_bank(iobase, SET7);
outb(0x40, iobase+7);
IRDA_MESSAGE("W83977AF (IR) driver loaded. "
"Version: 0x%02x\n", version);
return 0;
} else {
IRDA_DEBUG( 0, "%s(), Wrong chip version", __func__ );
}
}
return -1;
}
static void w83977af_change_speed(struct w83977af_ir *self, __u32 speed)
{
int ir_mode = HCR_SIR;
int iobase;
__u8 set;
iobase = self->io.fir_base;
self->io.speed = speed;
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
outb(0, iobase+ICR);
switch_bank(iobase, SET2);
outb(0x00, iobase+ABHL);
switch (speed) {
case 9600: outb(0x0c, iobase+ABLL); break;
case 19200: outb(0x06, iobase+ABLL); break;
case 38400: outb(0x03, iobase+ABLL); break;
case 57600: outb(0x02, iobase+ABLL); break;
case 115200: outb(0x01, iobase+ABLL); break;
case 576000:
ir_mode = HCR_MIR_576;
IRDA_DEBUG(0, "%s(), handling baud of 576000\n", __func__ );
break;
case 1152000:
ir_mode = HCR_MIR_1152;
IRDA_DEBUG(0, "%s(), handling baud of 1152000\n", __func__ );
break;
case 4000000:
ir_mode = HCR_FIR;
IRDA_DEBUG(0, "%s(), handling baud of 4000000\n", __func__ );
break;
default:
ir_mode = HCR_FIR;
IRDA_DEBUG(0, "%s(), unknown baud rate of %d\n", __func__ , speed);
break;
}
switch_bank(iobase, SET0);
outb(ir_mode, iobase+HCR);
switch_bank(iobase, SET2);
outb(ADCR2_RXFS32|ADCR2_TXFS32, iobase+ADCR2);
switch_bank(iobase, SET0);
outb(0x00, iobase+UFR);
outb(UFR_EN_FIFO, iobase+UFR);
outb(0xa7, iobase+UFR);
netif_wake_queue(self->netdev);
switch_bank(iobase, SET0);
if (speed > PIO_MAX_SPEED) {
outb(ICR_EFSFI, iobase+ICR);
w83977af_dma_receive(self);
} else
outb(ICR_ERBRI, iobase+ICR);
outb(set, iobase+SSR);
}
static netdev_tx_t w83977af_hard_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct w83977af_ir *self;
__s32 speed;
int iobase;
__u8 set;
int mtt;
self = netdev_priv(dev);
iobase = self->io.fir_base;
IRDA_DEBUG(4, "%s(%ld), skb->len=%d\n", __func__ , jiffies,
(int) skb->len);
netif_stop_queue(dev);
speed = irda_get_next_speed(skb);
if ((speed != self->io.speed) && (speed != -1)) {
if (!skb->len) {
w83977af_change_speed(self, speed);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
} else
self->new_speed = speed;
}
set = inb(iobase+SSR);
if (self->io.speed > PIO_MAX_SPEED) {
self->tx_buff.data = self->tx_buff.head;
skb_copy_from_linear_data(skb, self->tx_buff.data, skb->len);
self->tx_buff.len = skb->len;
mtt = irda_get_mtt(skb);
IRDA_DEBUG(4, "%s(%ld), mtt=%d\n", __func__ , jiffies, mtt);
if (mtt)
udelay(mtt);
switch_bank(iobase, SET0);
outb(ICR_EDMAI, iobase+ICR);
w83977af_dma_write(self, iobase);
} else {
self->tx_buff.data = self->tx_buff.head;
self->tx_buff.len = async_wrap_skb(skb, self->tx_buff.data,
self->tx_buff.truesize);
switch_bank(iobase, SET0);
outb(ICR_ETXTHI, iobase+ICR);
}
dev_kfree_skb(skb);
outb(set, iobase+SSR);
return NETDEV_TX_OK;
}
static void w83977af_dma_write(struct w83977af_ir *self, int iobase)
{
__u8 set;
#ifdef CONFIG_NETWINDER_TX_DMA_PROBLEMS
unsigned long flags;
__u8 hcr;
#endif
IRDA_DEBUG(4, "%s(), len=%d\n", __func__ , self->tx_buff.len);
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
outb(inb(iobase+HCR) & ~HCR_EN_DMA, iobase+HCR);
switch_bank(iobase, SET2);
outb(ADCR1_D_CHSW|ADCR1_ADV_SL, iobase+ADCR1);
#ifdef CONFIG_NETWINDER_TX_DMA_PROBLEMS
spin_lock_irqsave(&self->lock, flags);
disable_dma(self->io.dma);
clear_dma_ff(self->io.dma);
set_dma_mode(self->io.dma, DMA_MODE_READ);
set_dma_addr(self->io.dma, self->tx_buff_dma);
set_dma_count(self->io.dma, self->tx_buff.len);
#else
irda_setup_dma(self->io.dma, self->tx_buff_dma, self->tx_buff.len,
DMA_MODE_WRITE);
#endif
self->io.direction = IO_XMIT;
switch_bank(iobase, SET0);
#ifdef CONFIG_NETWINDER_TX_DMA_PROBLEMS
hcr = inb(iobase+HCR);
outb(hcr | HCR_EN_DMA, iobase+HCR);
enable_dma(self->io.dma);
spin_unlock_irqrestore(&self->lock, flags);
#else
outb(inb(iobase+HCR) | HCR_EN_DMA | HCR_TX_WT, iobase+HCR);
#endif
outb(set, iobase+SSR);
}
static int w83977af_pio_write(int iobase, __u8 *buf, int len, int fifo_size)
{
int actual = 0;
__u8 set;
IRDA_DEBUG(4, "%s()\n", __func__ );
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
if (!(inb_p(iobase+USR) & USR_TSRE)) {
IRDA_DEBUG(4,
"%s(), warning, FIFO not empty yet!\n", __func__ );
fifo_size -= 17;
IRDA_DEBUG(4, "%s(), %d bytes left in tx fifo\n",
__func__ , fifo_size);
}
while ((fifo_size-- > 0) && (actual < len)) {
outb(buf[actual++], iobase+TBR);
}
IRDA_DEBUG(4, "%s(), fifo_size %d ; %d sent of %d\n",
__func__ , fifo_size, actual, len);
outb(set, iobase+SSR);
return actual;
}
static void w83977af_dma_xmit_complete(struct w83977af_ir *self)
{
int iobase;
__u8 set;
IRDA_DEBUG(4, "%s(%ld)\n", __func__ , jiffies);
IRDA_ASSERT(self != NULL, return;);
iobase = self->io.fir_base;
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
outb(inb(iobase+HCR) & ~HCR_EN_DMA, iobase+HCR);
if (inb(iobase+AUDR) & AUDR_UNDR) {
IRDA_DEBUG(0, "%s(), Transmit underrun!\n", __func__ );
self->netdev->stats.tx_errors++;
self->netdev->stats.tx_fifo_errors++;
outb(AUDR_UNDR, iobase+AUDR);
} else
self->netdev->stats.tx_packets++;
if (self->new_speed) {
w83977af_change_speed(self, self->new_speed);
self->new_speed = 0;
}
netif_wake_queue(self->netdev);
outb(set, iobase+SSR);
}
static int w83977af_dma_receive(struct w83977af_ir *self)
{
int iobase;
__u8 set;
#ifdef CONFIG_NETWINDER_RX_DMA_PROBLEMS
unsigned long flags;
__u8 hcr;
#endif
IRDA_ASSERT(self != NULL, return -1;);
IRDA_DEBUG(4, "%s\n", __func__ );
iobase= self->io.fir_base;
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
outb(inb(iobase+HCR) & ~HCR_EN_DMA, iobase+HCR);
switch_bank(iobase, SET2);
outb((inb(iobase+ADCR1) & ~ADCR1_D_CHSW)|ADCR1_ADV_SL,
iobase+ADCR1);
self->io.direction = IO_RECV;
self->rx_buff.data = self->rx_buff.head;
#ifdef CONFIG_NETWINDER_RX_DMA_PROBLEMS
spin_lock_irqsave(&self->lock, flags);
disable_dma(self->io.dma);
clear_dma_ff(self->io.dma);
set_dma_mode(self->io.dma, DMA_MODE_READ);
set_dma_addr(self->io.dma, self->rx_buff_dma);
set_dma_count(self->io.dma, self->rx_buff.truesize);
#else
irda_setup_dma(self->io.dma, self->rx_buff_dma, self->rx_buff.truesize,
DMA_MODE_READ);
#endif
switch_bank(iobase, SET0);
outb(UFR_RXTL|UFR_TXTL|UFR_RXF_RST|UFR_EN_FIFO, iobase+UFR);
self->st_fifo.len = self->st_fifo.tail = self->st_fifo.head = 0;
switch_bank(iobase, SET0);
#ifdef CONFIG_NETWINDER_RX_DMA_PROBLEMS
hcr = inb(iobase+HCR);
outb(hcr | HCR_EN_DMA, iobase+HCR);
enable_dma(self->io.dma);
spin_unlock_irqrestore(&self->lock, flags);
#else
outb(inb(iobase+HCR) | HCR_EN_DMA, iobase+HCR);
#endif
outb(set, iobase+SSR);
return 0;
}
static int w83977af_dma_receive_complete(struct w83977af_ir *self)
{
struct sk_buff *skb;
struct st_fifo *st_fifo;
int len;
int iobase;
__u8 set;
__u8 status;
IRDA_DEBUG(4, "%s\n", __func__ );
st_fifo = &self->st_fifo;
iobase = self->io.fir_base;
set = inb(iobase+SSR);
iobase = self->io.fir_base;
switch_bank(iobase, SET5);
while ((status = inb(iobase+FS_FO)) & FS_FO_FSFDR) {
st_fifo->entries[st_fifo->tail].status = status;
st_fifo->entries[st_fifo->tail].len = inb(iobase+RFLFL);
st_fifo->entries[st_fifo->tail].len |= inb(iobase+RFLFH) << 8;
st_fifo->tail++;
st_fifo->len++;
}
while (st_fifo->len) {
status = st_fifo->entries[st_fifo->head].status;
len = st_fifo->entries[st_fifo->head].len;
st_fifo->head++;
st_fifo->len--;
if (status & FS_FO_ERR_MSK) {
if (status & FS_FO_LST_FR) {
self->netdev->stats.rx_errors += len;
} else {
self->netdev->stats.rx_errors++;
self->rx_buff.data += len;
if (status & FS_FO_MX_LEX)
self->netdev->stats.rx_length_errors++;
if (status & FS_FO_PHY_ERR)
self->netdev->stats.rx_frame_errors++;
if (status & FS_FO_CRC_ERR)
self->netdev->stats.rx_crc_errors++;
}
if (status & FS_FO_RX_OV)
self->netdev->stats.rx_fifo_errors++;
if (status & FS_FO_FSF_OV)
self->netdev->stats.rx_fifo_errors++;
} else {
switch_bank(iobase, SET0);
if (inb(iobase+USR) & USR_RDR) {
udelay(80);
}
skb = dev_alloc_skb(len+1);
if (skb == NULL) {
printk(KERN_INFO
"%s(), memory squeeze, dropping frame.\n", __func__);
outb(set, iobase+SSR);
return FALSE;
}
skb_reserve(skb, 1);
if (self->io.speed < 4000000) {
skb_put(skb, len-2);
skb_copy_to_linear_data(skb,
self->rx_buff.data,
len - 2);
} else {
skb_put(skb, len-4);
skb_copy_to_linear_data(skb,
self->rx_buff.data,
len - 4);
}
self->rx_buff.data += len;
self->netdev->stats.rx_packets++;
skb->dev = self->netdev;
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
netif_rx(skb);
}
}
outb(set, iobase+SSR);
return TRUE;
}
static void w83977af_pio_receive(struct w83977af_ir *self)
{
__u8 byte = 0x00;
int iobase;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
iobase = self->io.fir_base;
do {
byte = inb(iobase+RBR);
async_unwrap_char(self->netdev, &self->netdev->stats, &self->rx_buff,
byte);
} while (inb(iobase+USR) & USR_RDR);
}
static __u8 w83977af_sir_interrupt(struct w83977af_ir *self, int isr)
{
int actual;
__u8 new_icr = 0;
__u8 set;
int iobase;
IRDA_DEBUG(4, "%s(), isr=%#x\n", __func__ , isr);
iobase = self->io.fir_base;
if (isr & ISR_TXTH_I) {
actual = w83977af_pio_write(self->io.fir_base,
self->tx_buff.data,
self->tx_buff.len,
self->io.fifo_size);
self->tx_buff.data += actual;
self->tx_buff.len -= actual;
self->io.direction = IO_XMIT;
if (self->tx_buff.len > 0) {
new_icr |= ICR_ETXTHI;
} else {
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
outb(AUDR_SFEND, iobase+AUDR);
outb(set, iobase+SSR);
self->netdev->stats.tx_packets++;
netif_wake_queue(self->netdev);
new_icr |= ICR_ETBREI;
}
}
if (isr & ISR_TXEMP_I) {
if (self->new_speed) {
IRDA_DEBUG(2,
"%s(), Changing speed!\n", __func__ );
w83977af_change_speed(self, self->new_speed);
self->new_speed = 0;
}
self->io.direction = IO_RECV;
new_icr |= ICR_ERBRI;
}
if (isr & ISR_RXTH_I) {
w83977af_pio_receive(self);
new_icr |= ICR_ERBRI;
}
return new_icr;
}
static __u8 w83977af_fir_interrupt(struct w83977af_ir *self, int isr)
{
__u8 new_icr = 0;
__u8 set;
int iobase;
iobase = self->io.fir_base;
set = inb(iobase+SSR);
if (isr & (ISR_FEND_I|ISR_FSF_I)) {
if (w83977af_dma_receive_complete(self)) {
new_icr |= ICR_EFSFI;
} else {
switch_bank(iobase, SET4);
outb(0x01, iobase+TMRL);
outb(0x00, iobase+TMRH);
outb(IR_MSL_EN_TMR, iobase+IR_MSL);
new_icr |= ICR_ETMRI;
}
}
if (isr & ISR_TMR_I) {
switch_bank(iobase, SET4);
outb(0, iobase+IR_MSL);
if (self->io.direction == IO_XMIT) {
w83977af_dma_write(self, iobase);
new_icr |= ICR_EDMAI;
} else {
w83977af_dma_receive_complete(self);
new_icr |= ICR_EFSFI;
}
}
if (isr & ISR_DMA_I) {
w83977af_dma_xmit_complete(self);
w83977af_dma_receive(self);
new_icr = ICR_EFSFI;
}
outb(set, iobase+SSR);
return new_icr;
}
static irqreturn_t w83977af_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct w83977af_ir *self;
__u8 set, icr, isr;
int iobase;
self = netdev_priv(dev);
iobase = self->io.fir_base;
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
icr = inb(iobase+ICR);
isr = inb(iobase+ISR) & icr;
outb(0, iobase+ICR);
if (isr) {
if (self->io.speed > PIO_MAX_SPEED )
icr = w83977af_fir_interrupt(self, isr);
else
icr = w83977af_sir_interrupt(self, isr);
}
outb(icr, iobase+ICR);
outb(set, iobase+SSR);
return IRQ_RETVAL(isr);
}
static int w83977af_is_receiving(struct w83977af_ir *self)
{
int status = FALSE;
int iobase;
__u8 set;
IRDA_ASSERT(self != NULL, return FALSE;);
if (self->io.speed > 115200) {
iobase = self->io.fir_base;
set = inb(iobase+SSR);
switch_bank(iobase, SET2);
if ((inb(iobase+RXFDTH) & 0x3f) != 0) {
status = TRUE;
}
outb(set, iobase+SSR);
} else
status = (self->rx_buff.state != OUTSIDE_FRAME);
return status;
}
static int w83977af_net_open(struct net_device *dev)
{
struct w83977af_ir *self;
int iobase;
char hwname[32];
__u8 set;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(dev != NULL, return -1;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return 0;);
iobase = self->io.fir_base;
if (request_irq(self->io.irq, w83977af_interrupt, 0, dev->name,
(void *) dev)) {
return -EAGAIN;
}
if (request_dma(self->io.dma, dev->name)) {
free_irq(self->io.irq, dev);
return -EAGAIN;
}
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
if (self->io.speed > 115200) {
outb(ICR_EFSFI, iobase+ICR);
w83977af_dma_receive(self);
} else
outb(ICR_ERBRI, iobase+ICR);
outb(set, iobase+SSR);
netif_start_queue(dev);
sprintf(hwname, "w83977af @ 0x%03x", self->io.fir_base);
self->irlap = irlap_open(dev, &self->qos, hwname);
return 0;
}
static int w83977af_net_close(struct net_device *dev)
{
struct w83977af_ir *self;
int iobase;
__u8 set;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(dev != NULL, return -1;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return 0;);
iobase = self->io.fir_base;
netif_stop_queue(dev);
if (self->irlap)
irlap_close(self->irlap);
self->irlap = NULL;
disable_dma(self->io.dma);
set = inb(iobase+SSR);
switch_bank(iobase, SET0);
outb(0, iobase+ICR);
free_irq(self->io.irq, dev);
free_dma(self->io.dma);
outb(set, iobase+SSR);
return 0;
}
static int w83977af_net_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct if_irda_req *irq = (struct if_irda_req *) rq;
struct w83977af_ir *self;
unsigned long flags;
int ret = 0;
IRDA_ASSERT(dev != NULL, return -1;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return -1;);
IRDA_DEBUG(2, "%s(), %s, (cmd=0x%X)\n", __func__ , dev->name, cmd);
spin_lock_irqsave(&self->lock, flags);
switch (cmd) {
case SIOCSBANDWIDTH:
if (!capable(CAP_NET_ADMIN)) {
ret = -EPERM;
goto out;
}
w83977af_change_speed(self, irq->ifr_baudrate);
break;
case SIOCSMEDIABUSY:
if (!capable(CAP_NET_ADMIN)) {
ret = -EPERM;
goto out;
}
irda_device_set_media_busy(self->netdev, TRUE);
break;
case SIOCGRECEIVING:
irq->ifr_receiving = w83977af_is_receiving(self);
break;
default:
ret = -EOPNOTSUPP;
}
out:
spin_unlock_irqrestore(&self->lock, flags);
return ret;
}
