static int __init ali_ircc_init(void)
{
ali_chip_t *chip;
chipio_t info;
int ret;
int cfg, cfg_base;
int reg, revision;
int i = 0;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
ret = platform_driver_register(&ali_ircc_driver);
if (ret) {
IRDA_ERROR("%s, Can't register driver!\n",
ALI_IRCC_DRIVER_NAME);
return ret;
}
ret = -ENODEV;
for (chip= chips; chip->name; chip++, i++)
{
IRDA_DEBUG(2, "%s(), Probing for %s ...\n", __func__, chip->name);
for (cfg=0; cfg<2; cfg++)
{
cfg_base = chip->cfg[cfg];
if (!cfg_base)
continue;
memset(&info, 0, sizeof(chipio_t));
info.cfg_base = cfg_base;
info.fir_base = io[i];
info.dma = dma[i];
info.irq = irq[i];
outb(chip->entr1, cfg_base);
outb(chip->entr2, cfg_base);
outb(0x07, cfg_base);
outb(0x05, cfg_base+1);
outb(chip->cid_index, cfg_base);
reg = inb(cfg_base+1);
if (reg == chip->cid_value)
{
IRDA_DEBUG(2, "%s(), Chip found at 0x%03x\n", __func__, cfg_base);
outb(0x1F, cfg_base);
revision = inb(cfg_base+1);
IRDA_DEBUG(2, "%s(), Found %s chip, revision=%d\n", __func__,
chip->name, revision);
if (io[i] < 2000)
{
chip->init(chip, &info);
}
else
{
chip->probe(chip, &info);
}
if (ali_ircc_open(i, &info) == 0)
ret = 0;
i++;
}
else
{
IRDA_DEBUG(2, "%s(), No %s chip at 0x%03x\n", __func__, chip->name, cfg_base);
}
outb(0xbb, cfg_base);
}
}
IRDA_DEBUG(2, "%s(), ----------------- End -----------------\n", __func__);
if (ret)
platform_driver_unregister(&ali_ircc_driver);
return ret;
}
static void __exit ali_ircc_cleanup(void)
{
int i;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
for (i=0; i < ARRAY_SIZE(dev_self); i++) {
if (dev_self[i])
ali_ircc_close(dev_self[i]);
}
platform_driver_unregister(&ali_ircc_driver);
IRDA_DEBUG(2, "%s(), ----------------- End -----------------\n", __func__);
}
static int ali_ircc_open(int i, chipio_t *info)
{
struct net_device *dev;
struct ali_ircc_cb *self;
int dongle_id;
int err;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
if (i >= ARRAY_SIZE(dev_self)) {
IRDA_ERROR("%s(), maximum number of supported chips reached!\n",
__func__);
return -ENOMEM;
}
if ((ali_ircc_setup(info)) == -1)
return -1;
dev = alloc_irdadev(sizeof(*self));
if (dev == NULL) {
IRDA_ERROR("%s(), can't allocate memory for control block!\n",
__func__);
return -ENOMEM;
}
self = netdev_priv(dev);
self->netdev = dev;
spin_lock_init(&self->lock);
dev_self[i] = self;
self->index = i;
self->io.cfg_base = info->cfg_base;
self->io.fir_base = info->fir_base;
self->io.sir_base = info->sir_base;
self->io.irq = info->irq;
self->io.fir_ext = CHIP_IO_EXTENT;
self->io.dma = info->dma;
self->io.fifo_size = 16;
if (!request_region(self->io.fir_base, self->io.fir_ext,
ALI_IRCC_DRIVER_NAME)) {
IRDA_WARNING("%s(), can't get iobase of 0x%03x\n", __func__,
self->io.fir_base);
err = -ENODEV;
goto err_out1;
}
irda_init_max_qos_capabilies(&self->qos);
self->qos.baud_rate.bits = IR_9600|IR_19200|IR_38400|IR_57600|
IR_115200|IR_576000|IR_1152000|(IR_4000000 << 8);
self->qos.min_turn_time.bits = qos_mtt_bits;
irda_qos_bits_to_value(&self->qos);
self->rx_buff.truesize = 14384;
self->tx_buff.truesize = 14384;
self->rx_buff.head =
dma_alloc_coherent(NULL, self->rx_buff.truesize,
&self->rx_buff_dma, GFP_KERNEL);
if (self->rx_buff.head == NULL) {
err = -ENOMEM;
goto err_out2;
}
memset(self->rx_buff.head, 0, self->rx_buff.truesize);
self->tx_buff.head =
dma_alloc_coherent(NULL, self->tx_buff.truesize,
&self->tx_buff_dma, GFP_KERNEL);
if (self->tx_buff.head == NULL) {
err = -ENOMEM;
goto err_out3;
}
memset(self->tx_buff.head, 0, self->tx_buff.truesize);
self->rx_buff.in_frame = FALSE;
self->rx_buff.state = OUTSIDE_FRAME;
self->tx_buff.data = self->tx_buff.head;
self->rx_buff.data = self->rx_buff.head;
self->tx_fifo.len = self->tx_fifo.ptr = self->tx_fifo.free = 0;
self->tx_fifo.tail = self->tx_buff.head;
dev->netdev_ops = &ali_ircc_sir_ops;
err = register_netdev(dev);
if (err) {
IRDA_ERROR("%s(), register_netdev() failed!\n", __func__);
goto err_out4;
}
IRDA_MESSAGE("IrDA: Registered device %s\n", dev->name);
dongle_id = ali_ircc_read_dongle_id(i, info);
IRDA_MESSAGE("%s(), %s, Found dongle: %s\n", __func__,
ALI_IRCC_DRIVER_NAME, dongle_types[dongle_id]);
self->io.dongle_id = dongle_id;
IRDA_DEBUG(2, "%s(), ----------------- End -----------------\n", __func__);
return 0;
err_out4:
dma_free_coherent(NULL, self->tx_buff.truesize,
self->tx_buff.head, self->tx_buff_dma);
err_out3:
dma_free_coherent(NULL, self->rx_buff.truesize,
self->rx_buff.head, self->rx_buff_dma);
err_out2:
release_region(self->io.fir_base, self->io.fir_ext);
err_out1:
dev_self[i] = NULL;
free_netdev(dev);
return err;
}
static int __exit ali_ircc_close(struct ali_ircc_cb *self)
{
int iobase;
IRDA_DEBUG(4, "%s(), ---------------- Start ----------------\n", __func__);
IRDA_ASSERT(self != NULL, return -1;);
iobase = self->io.fir_base;
unregister_netdev(self->netdev);
IRDA_DEBUG(4, "%s(), Releasing Region %03x\n", __func__, self->io.fir_base);
release_region(self->io.fir_base, self->io.fir_ext);
if (self->tx_buff.head)
dma_free_coherent(NULL, self->tx_buff.truesize,
self->tx_buff.head, self->tx_buff_dma);
if (self->rx_buff.head)
dma_free_coherent(NULL, self->rx_buff.truesize,
self->rx_buff.head, self->rx_buff_dma);
dev_self[self->index] = NULL;
free_netdev(self->netdev);
IRDA_DEBUG(2, "%s(), ----------------- End -----------------\n", __func__);
return 0;
}
static int ali_ircc_init_43(ali_chip_t *chip, chipio_t *info)
{
return 0;
}
static int ali_ircc_init_53(ali_chip_t *chip, chipio_t *info)
{
return 0;
}
static int ali_ircc_probe_53(ali_chip_t *chip, chipio_t *info)
{
int cfg_base = info->cfg_base;
int hi, low, reg;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
outb(chip->entr1, cfg_base);
outb(chip->entr2, cfg_base);
outb(0x07, cfg_base);
outb(0x05, cfg_base+1);
outb(0x60, cfg_base);
hi = inb(cfg_base+1);
outb(0x61, cfg_base);
low = inb(cfg_base+1);
info->fir_base = (hi<<8) + low;
info->sir_base = info->fir_base;
IRDA_DEBUG(2, "%s(), probing fir_base=0x%03x\n", __func__, info->fir_base);
outb(0x70, cfg_base);
reg = inb(cfg_base+1);
info->irq = reg & 0x0f;
IRDA_DEBUG(2, "%s(), probing irq=%d\n", __func__, info->irq);
outb(0x74, cfg_base);
reg = inb(cfg_base+1);
info->dma = reg & 0x07;
if(info->dma == 0x04)
IRDA_WARNING("%s(), No DMA channel assigned !\n", __func__);
else
IRDA_DEBUG(2, "%s(), probing dma=%d\n", __func__, info->dma);
outb(0x30, cfg_base);
reg = inb(cfg_base+1);
info->enabled = (reg & 0x80) && (reg & 0x01);
IRDA_DEBUG(2, "%s(), probing enabled=%d\n", __func__, info->enabled);
outb(0x22, cfg_base);
reg = inb(cfg_base+1);
info->suspended = (reg & 0x20);
IRDA_DEBUG(2, "%s(), probing suspended=%d\n", __func__, info->suspended);
outb(0xbb, cfg_base);
IRDA_DEBUG(2, "%s(), ----------------- End -----------------\n", __func__);
return 0;
}
static int ali_ircc_setup(chipio_t *info)
{
unsigned char tmp;
int version;
int iobase = info->fir_base;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
SIR2FIR(iobase);
outb(0x40, iobase+FIR_MCR);
switch_bank(iobase, BANK3);
version = inb(iobase+FIR_ID_VR);
if(version != 0x00)
{
IRDA_ERROR("%s, Wrong chip version %02x\n",
ALI_IRCC_DRIVER_NAME, version);
return -1;
}
switch_bank(iobase, BANK1);
outb(RX_FIFO_Threshold, iobase+FIR_FIFO_TR);
outb(RX_DMA_Threshold, iobase+FIR_DMA_TR);
switch_bank(iobase, BANK2);
outb(inb(iobase+FIR_IRDA_CR) | IRDA_CR_CRC, iobase+FIR_IRDA_CR);
switch_bank(iobase, BANK0);
tmp = inb(iobase+FIR_LCR_B);
tmp &=~0x20;
tmp |= 0x80;
tmp &= 0xbf;
outb(tmp, iobase+FIR_LCR_B);
outb(0x00, iobase+FIR_IER);
FIR2SIR(iobase);
IRDA_MESSAGE("%s, driver loaded (Benjamin Kong)\n",
ALI_IRCC_DRIVER_NAME);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__);
return 0;
}
static int ali_ircc_read_dongle_id (int i, chipio_t *info)
{
int dongle_id, reg;
int cfg_base = info->cfg_base;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
outb(chips[i].entr1, cfg_base);
outb(chips[i].entr2, cfg_base);
outb(0x07, cfg_base);
outb(0x05, cfg_base+1);
outb(0xf0, cfg_base);
reg = inb(cfg_base+1);
dongle_id = ((reg>>6)&0x02) | ((reg>>5)&0x01);
IRDA_DEBUG(2, "%s(), probing dongle_id=%d, dongle_types=%s\n", __func__,
dongle_id, dongle_types[dongle_id]);
outb(0xbb, cfg_base);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__);
return dongle_id;
}
static irqreturn_t ali_ircc_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct ali_ircc_cb *self;
int ret;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
self = netdev_priv(dev);
spin_lock(&self->lock);
if (self->io.speed > 115200)
ret = ali_ircc_fir_interrupt(self);
else
ret = ali_ircc_sir_interrupt(self);
spin_unlock(&self->lock);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__);
return ret;
}
static irqreturn_t ali_ircc_fir_interrupt(struct ali_ircc_cb *self)
{
__u8 eir, OldMessageCount;
int iobase, tmp;
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__);
iobase = self->io.fir_base;
switch_bank(iobase, BANK0);
self->InterruptID = inb(iobase+FIR_IIR);
self->BusStatus = inb(iobase+FIR_BSR);
OldMessageCount = (self->LineStatus + 1) & 0x07;
self->LineStatus = inb(iobase+FIR_LSR);
eir = self->InterruptID & self->ier;
IRDA_DEBUG(1, "%s(), self->InterruptID = %x\n", __func__,self->InterruptID);
IRDA_DEBUG(1, "%s(), self->LineStatus = %x\n", __func__,self->LineStatus);
IRDA_DEBUG(1, "%s(), self->ier = %x\n", __func__,self->ier);
IRDA_DEBUG(1, "%s(), eir = %x\n", __func__,eir);
SetCOMInterrupts(self, FALSE);
if (eir & IIR_EOM)
{
if (self->io.direction == IO_XMIT)
{
IRDA_DEBUG(1, "%s(), ******* IIR_EOM (Tx) *******\n", __func__);
if(ali_ircc_dma_xmit_complete(self))
{
if (irda_device_txqueue_empty(self->netdev))
{
ali_ircc_dma_receive(self);
self->ier = IER_EOM;
}
}
else
{
self->ier = IER_EOM;
}
}
else
{
IRDA_DEBUG(1, "%s(), ******* IIR_EOM (Rx) *******\n", __func__);
if(OldMessageCount > ((self->LineStatus+1) & 0x07))
{
self->rcvFramesOverflow = TRUE;
IRDA_DEBUG(1, "%s(), ******* self->rcvFramesOverflow = TRUE ********\n", __func__);
}
if (ali_ircc_dma_receive_complete(self))
{
IRDA_DEBUG(1, "%s(), ******* receive complete ********\n", __func__);
self->ier = IER_EOM;
}
else
{
IRDA_DEBUG(1, "%s(), ******* Not receive complete ********\n", __func__);
self->ier = IER_EOM | IER_TIMER;
}
}
}
else if (eir & IIR_TIMER)
{
if(OldMessageCount > ((self->LineStatus+1) & 0x07))
{
self->rcvFramesOverflow = TRUE;
IRDA_DEBUG(1, "%s(), ******* self->rcvFramesOverflow = TRUE *******\n", __func__);
}
switch_bank(iobase, BANK1);
tmp = inb(iobase+FIR_CR);
outb( tmp& ~CR_TIMER_EN, iobase+FIR_CR);
if (self->io.direction == IO_XMIT)
{
ali_ircc_dma_xmit(self);
self->ier = IER_EOM;
}
else
{
if(ali_ircc_dma_receive_complete(self))
{
self->ier = IER_EOM;
}
else
{
self->ier = IER_EOM | IER_TIMER;
}
}
}
SetCOMInterrupts(self, TRUE);
IRDA_DEBUG(1, "%s(), ----------------- End ---------------\n", __func__);
return IRQ_RETVAL(eir);
}
static irqreturn_t ali_ircc_sir_interrupt(struct ali_ircc_cb *self)
{
int iobase;
int iir, lsr;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
iobase = self->io.sir_base;
iir = inb(iobase+UART_IIR) & UART_IIR_ID;
if (iir) {
lsr = inb(iobase+UART_LSR);
IRDA_DEBUG(4, "%s(), iir=%02x, lsr=%02x, iobase=%#x\n", __func__,
iir, lsr, iobase);
switch (iir)
{
case UART_IIR_RLSI:
IRDA_DEBUG(2, "%s(), RLSI\n", __func__);
break;
case UART_IIR_RDI:
ali_ircc_sir_receive(self);
break;
case UART_IIR_THRI:
if (lsr & UART_LSR_THRE)
{
ali_ircc_sir_write_wakeup(self);
}
break;
default:
IRDA_DEBUG(0, "%s(), unhandled IIR=%#x\n", __func__, iir);
break;
}
}
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__);
return IRQ_RETVAL(iir);
}
static void ali_ircc_sir_receive(struct ali_ircc_cb *self)
{
int boguscount = 0;
int iobase;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__);
IRDA_ASSERT(self != NULL, return;);
iobase = self->io.sir_base;
do {
async_unwrap_char(self->netdev, &self->netdev->stats, &self->rx_buff,
inb(iobase+UART_RX));
if (boguscount++ > 32) {
IRDA_DEBUG(2,"%s(), breaking!\n", __func__);
break;
}
} while (inb(iobase+UART_LSR) & UART_LSR_DR);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
}
static void ali_ircc_sir_write_wakeup(struct ali_ircc_cb *self)
{
int actual = 0;
int iobase;
IRDA_ASSERT(self != NULL, return;);
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__ );
iobase = self->io.sir_base;
if (self->tx_buff.len > 0)
{
actual = ali_ircc_sir_write(iobase, self->io.fifo_size,
self->tx_buff.data, self->tx_buff.len);
self->tx_buff.data += actual;
self->tx_buff.len -= actual;
}
else
{
if (self->new_speed)
{
while(!(inb(iobase+UART_LSR) & UART_LSR_TEMT))
IRDA_DEBUG(1, "%s(), UART_LSR_THRE\n", __func__ );
IRDA_DEBUG(1, "%s(), Changing speed! self->new_speed = %d\n", __func__ , self->new_speed);
ali_ircc_change_speed(self, self->new_speed);
self->new_speed = 0;
if (self->io.speed > 115200)
{
IRDA_DEBUG(2, "%s(), ali_ircc_change_speed from UART_LSR_TEMT\n", __func__ );
self->ier = IER_EOM;
return;
}
}
else
{
netif_wake_queue(self->netdev);
}
self->netdev->stats.tx_packets++;
outb(UART_IER_RDI, iobase+UART_IER);
}
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
}
static void ali_ircc_change_speed(struct ali_ircc_cb *self, __u32 baud)
{
struct net_device *dev = self->netdev;
int iobase;
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_DEBUG(2, "%s(), setting speed = %d\n", __func__ , baud);
iobase = self->io.fir_base;
SetCOMInterrupts(self, FALSE);
if (baud > 115200)
{
ali_ircc_fir_change_speed(self, baud);
dev->netdev_ops = &ali_ircc_fir_ops;
self->ier = IER_EOM;
ali_ircc_dma_receive(self);
}
else
{
ali_ircc_sir_change_speed(self, baud);
dev->netdev_ops = &ali_ircc_sir_ops;
}
SetCOMInterrupts(self, TRUE);
netif_wake_queue(self->netdev);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
}
static void ali_ircc_fir_change_speed(struct ali_ircc_cb *priv, __u32 baud)
{
int iobase;
struct ali_ircc_cb *self = (struct ali_ircc_cb *) priv;
struct net_device *dev;
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
dev = self->netdev;
iobase = self->io.fir_base;
IRDA_DEBUG(1, "%s(), self->io.speed = %d, change to speed = %d\n", __func__ ,self->io.speed,baud);
if(self->io.speed <=115200)
{
SIR2FIR(iobase);
}
self->io.speed = baud;
ali_ircc_change_dongle_speed(self, baud);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
}
static void ali_ircc_sir_change_speed(struct ali_ircc_cb *priv, __u32 speed)
{
struct ali_ircc_cb *self = (struct ali_ircc_cb *) priv;
unsigned long flags;
int iobase;
int fcr;
int lcr;
int divisor;
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_DEBUG(1, "%s(), Setting speed to: %d\n", __func__ , speed);
IRDA_ASSERT(self != NULL, return;);
iobase = self->io.sir_base;
if(self->io.speed >115200)
{
ali_ircc_change_dongle_speed(self, speed);
FIR2SIR(iobase);
}
inb(iobase+UART_LSR);
inb(iobase+UART_SCR);
self->io.speed = speed;
spin_lock_irqsave(&self->lock, flags);
divisor = 115200/speed;
fcr = UART_FCR_ENABLE_FIFO;
if (self->io.speed < 38400)
fcr |= UART_FCR_TRIGGER_1;
else
fcr |= UART_FCR_TRIGGER_14;
lcr = UART_LCR_WLEN8;
outb(UART_LCR_DLAB | lcr, iobase+UART_LCR);
outb(divisor & 0xff, iobase+UART_DLL);
outb(divisor >> 8, iobase+UART_DLM);
outb(lcr, iobase+UART_LCR);
outb(fcr, iobase+UART_FCR);
outb((UART_MCR_DTR | UART_MCR_RTS | UART_MCR_OUT2), iobase+UART_MCR);
spin_unlock_irqrestore(&self->lock, flags);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
}
static void ali_ircc_change_dongle_speed(struct ali_ircc_cb *priv, int speed)
{
struct ali_ircc_cb *self = (struct ali_ircc_cb *) priv;
int iobase,dongle_id;
int tmp = 0;
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__ );
iobase = self->io.fir_base;
dongle_id = self->io.dongle_id;
IRDA_DEBUG(1, "%s(), Set Speed for %s , Speed = %d\n", __func__ , dongle_types[dongle_id], speed);
switch_bank(iobase, BANK2);
tmp = inb(iobase+FIR_IRDA_CR);
if(dongle_id == 0)
{
if(speed == 4000000)
{
tmp &= ~IRDA_CR_HDLC;
tmp |= IRDA_CR_CRC;
switch_bank(iobase, BANK2);
outb(tmp, iobase+FIR_IRDA_CR);
tmp &= ~0x09;
tmp |= 0x02;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
tmp &= ~0x01;
tmp |= 0x0a;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
tmp |= 0x0b;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
tmp &= ~0x08;
tmp |= 0x03;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
tmp &= ~0x09;
tmp |= 0x02;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
outb(tmp & ~0x02, iobase+FIR_IRDA_CR);
}
else
{
if (speed==1152000)
{
tmp |= 0xA0;
}
else
{
tmp &=~0x80;
tmp |= 0x20;
}
tmp |= IRDA_CR_CRC;
switch_bank(iobase, BANK2);
outb(tmp, iobase+FIR_IRDA_CR);
tmp &= ~0x09;
tmp |= 0x02;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
tmp &= ~0x01;
tmp |= 0x0a;
outb(tmp, iobase+FIR_IRDA_CR);
tmp &= ~0x09;
tmp |= 0x02;
outb(tmp, iobase+FIR_IRDA_CR);
udelay(2);
outb(tmp & ~0x02, iobase+FIR_IRDA_CR);
}
}
else if (dongle_id == 1)
{
switch(speed)
{
case 4000000:
tmp &= ~IRDA_CR_HDLC;
break;
case 1152000:
tmp |= 0xA0;
break;
case 576000:
tmp &=~0x80;
tmp |= 0x20;
break;
}
tmp |= IRDA_CR_CRC;
switch_bank(iobase, BANK2);
outb(tmp, iobase+FIR_IRDA_CR);
}
else
{
if(speed <= 115200)
{
tmp &= ~IRDA_CR_FIR_SIN;
switch_bank(iobase, BANK2);
outb(tmp, iobase+FIR_IRDA_CR);
}
else
{
switch(speed)
{
case 4000000:
tmp &= ~IRDA_CR_HDLC;
break;
case 1152000:
tmp |= 0xA0;
break;
case 576000:
tmp &=~0x80;
tmp |= 0x20;
break;
}
tmp |= IRDA_CR_CRC;
tmp |= IRDA_CR_FIR_SIN;
switch_bank(iobase, BANK2);
outb(tmp, iobase+FIR_IRDA_CR);
}
}
switch_bank(iobase, BANK0);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
}
static int ali_ircc_sir_write(int iobase, int fifo_size, __u8 *buf, int len)
{
int actual = 0;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__ );
if (!(inb(iobase+UART_LSR) & UART_LSR_THRE)) {
IRDA_DEBUG(0, "%s(), failed, fifo not empty!\n", __func__ );
return 0;
}
while ((fifo_size-- > 0) && (actual < len)) {
outb(buf[actual], iobase+UART_TX);
actual++;
}
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
return actual;
}
static int ali_ircc_net_open(struct net_device *dev)
{
struct ali_ircc_cb *self;
int iobase;
char hwname[32];
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_ASSERT(dev != NULL, return -1;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return 0;);
iobase = self->io.fir_base;
if (request_irq(self->io.irq, ali_ircc_interrupt, 0, dev->name, dev))
{
IRDA_WARNING("%s, unable to allocate irq=%d\n",
ALI_IRCC_DRIVER_NAME,
self->io.irq);
return -EAGAIN;
}
if (request_dma(self->io.dma, dev->name)) {
IRDA_WARNING("%s, unable to allocate dma=%d\n",
ALI_IRCC_DRIVER_NAME,
self->io.dma);
free_irq(self->io.irq, self);
return -EAGAIN;
}
outb(UART_IER_RDI , iobase+UART_IER);
netif_start_queue(dev);
sprintf(hwname, "ALI-FIR @ 0x%03x", self->io.fir_base);
self->irlap = irlap_open(dev, &self->qos, hwname);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
return 0;
}
static int ali_ircc_net_close(struct net_device *dev)
{
struct ali_ircc_cb *self;
IRDA_DEBUG(4, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_ASSERT(dev != NULL, return -1;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return 0;);
netif_stop_queue(dev);
if (self->irlap)
irlap_close(self->irlap);
self->irlap = NULL;
disable_dma(self->io.dma);
SetCOMInterrupts(self, FALSE);
free_irq(self->io.irq, dev);
free_dma(self->io.dma);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
return 0;
}
static netdev_tx_t ali_ircc_fir_hard_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ali_ircc_cb *self;
unsigned long flags;
int iobase;
__u32 speed;
int mtt, diff;
IRDA_DEBUG(1, "%s(), ---------------- Start -----------------\n", __func__ );
self = netdev_priv(dev);
iobase = self->io.fir_base;
netif_stop_queue(dev);
spin_lock_irqsave(&self->lock, flags);
speed = irda_get_next_speed(skb);
if ((speed != self->io.speed) && (speed != -1)) {
if (!skb->len) {
ali_ircc_change_speed(self, speed);
dev->trans_start = jiffies;
spin_unlock_irqrestore(&self->lock, flags);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
} else
self->new_speed = speed;
}
self->tx_fifo.queue[self->tx_fifo.free].start = self->tx_fifo.tail;
self->tx_fifo.queue[self->tx_fifo.free].len = skb->len;
self->tx_fifo.tail += skb->len;
dev->stats.tx_bytes += skb->len;
skb_copy_from_linear_data(skb, self->tx_fifo.queue[self->tx_fifo.free].start,
skb->len);
self->tx_fifo.len++;
self->tx_fifo.free++;
if (self->tx_fifo.len == 1)
{
mtt = irda_get_mtt(skb);
if (mtt)
{
do_gettimeofday(&self->now);
diff = self->now.tv_usec - self->stamp.tv_usec;
IRDA_DEBUG(1, "%s(), ******* diff = %d *******\n", __func__ , diff);
if (diff < 0)
diff += 1000000;
if (mtt > diff)
{
mtt -= diff;
if (mtt > 500)
{
mtt = (mtt+250) / 500;
IRDA_DEBUG(1, "%s(), ************** mtt = %d ***********\n", __func__ , mtt);
if (mtt == 1)
{
switch_bank(iobase, BANK1);
outb(TIMER_IIR_500, iobase+FIR_TIMER_IIR);
}
else if (mtt == 2)
{
switch_bank(iobase, BANK1);
outb(TIMER_IIR_1ms, iobase+FIR_TIMER_IIR);
}
else
{
switch_bank(iobase, BANK1);
outb(TIMER_IIR_2ms, iobase+FIR_TIMER_IIR);
}
outb(inb(iobase+FIR_CR) | CR_TIMER_EN, iobase+FIR_CR);
self->io.direction = IO_XMIT;
self->ier = IER_TIMER;
SetCOMInterrupts(self, TRUE);
goto out;
}
else
udelay(mtt);
}
}
self->ier = IER_EOM;
SetCOMInterrupts(self, TRUE);
ali_ircc_dma_xmit(self);
}
out:
if (self->tx_fifo.free < MAX_TX_WINDOW)
netif_wake_queue(self->netdev);
switch_bank(iobase, BANK0);
dev->trans_start = jiffies;
spin_unlock_irqrestore(&self->lock, flags);
dev_kfree_skb(skb);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
return NETDEV_TX_OK;
}
static void ali_ircc_dma_xmit(struct ali_ircc_cb *self)
{
int iobase, tmp;
unsigned char FIFO_OPTI, Hi, Lo;
IRDA_DEBUG(1, "%s(), ---------------- Start -----------------\n", __func__ );
iobase = self->io.fir_base;
if(self->tx_fifo.queue[self->tx_fifo.ptr].len < TX_FIFO_Threshold)
FIFO_OPTI = self->tx_fifo.queue[self->tx_fifo.ptr].len-1;
else
FIFO_OPTI = TX_FIFO_Threshold;
switch_bank(iobase, BANK1);
outb(inb(iobase+FIR_CR) & ~CR_DMA_EN, iobase+FIR_CR);
self->io.direction = IO_XMIT;
irda_setup_dma(self->io.dma,
((u8 *)self->tx_fifo.queue[self->tx_fifo.ptr].start -
self->tx_buff.head) + self->tx_buff_dma,
self->tx_fifo.queue[self->tx_fifo.ptr].len,
DMA_TX_MODE);
switch_bank(iobase, BANK0);
outb(LCR_A_FIFO_RESET, iobase+FIR_LCR_A);
if (self->fifo_opti_buf!=FIFO_OPTI)
{
switch_bank(iobase, BANK1);
outb(FIFO_OPTI, iobase+FIR_FIFO_TR) ;
self->fifo_opti_buf=FIFO_OPTI;
}
switch_bank(iobase, BANK1);
outb(TX_DMA_Threshold, iobase+FIR_DMA_TR);
Hi = (self->tx_fifo.queue[self->tx_fifo.ptr].len >> 8) & 0x0f;
Lo = self->tx_fifo.queue[self->tx_fifo.ptr].len & 0xff;
switch_bank(iobase, BANK2);
outb(Hi, iobase+FIR_TX_DSR_HI);
outb(Lo, iobase+FIR_TX_DSR_LO);
switch_bank(iobase, BANK0);
tmp = inb(iobase+FIR_LCR_B);
tmp &= ~0x20;
outb(((unsigned char)(tmp & 0x3f) | LCR_B_TX_MODE) & ~LCR_B_BW, iobase+FIR_LCR_B);
IRDA_DEBUG(1, "%s(), *** Change to TX mode: FIR_LCR_B = 0x%x ***\n", __func__ , inb(iobase+FIR_LCR_B));
outb(0, iobase+FIR_LSR);
switch_bank(iobase, BANK1);
outb(inb(iobase+FIR_CR) | CR_DMA_EN | CR_DMA_BURST, iobase+FIR_CR);
switch_bank(iobase, BANK0);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
}
static int ali_ircc_dma_xmit_complete(struct ali_ircc_cb *self)
{
int iobase;
int ret = TRUE;
IRDA_DEBUG(1, "%s(), ---------------- Start -----------------\n", __func__ );
iobase = self->io.fir_base;
switch_bank(iobase, BANK1);
outb(inb(iobase+FIR_CR) & ~CR_DMA_EN, iobase+FIR_CR);
switch_bank(iobase, BANK0);
if((inb(iobase+FIR_LSR) & LSR_FRAME_ABORT) == LSR_FRAME_ABORT)
{
IRDA_ERROR("%s(), ********* LSR_FRAME_ABORT *********\n", __func__);
self->netdev->stats.tx_errors++;
self->netdev->stats.tx_fifo_errors++;
}
else
{
self->netdev->stats.tx_packets++;
}
if (self->new_speed)
{
ali_ircc_change_speed(self, self->new_speed);
self->new_speed = 0;
}
self->tx_fifo.ptr++;
self->tx_fifo.len--;
if (self->tx_fifo.len)
{
ali_ircc_dma_xmit(self);
ret = FALSE;
}
else
{
self->tx_fifo.len = self->tx_fifo.ptr = self->tx_fifo.free = 0;
self->tx_fifo.tail = self->tx_buff.head;
}
if (self->tx_fifo.free < MAX_TX_WINDOW) {
netif_wake_queue(self->netdev);
}
switch_bank(iobase, BANK0);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
return ret;
}
static int ali_ircc_dma_receive(struct ali_ircc_cb *self)
{
int iobase, tmp;
IRDA_DEBUG(1, "%s(), ---------------- Start -----------------\n", __func__ );
iobase = self->io.fir_base;
self->tx_fifo.len = self->tx_fifo.ptr = self->tx_fifo.free = 0;
self->tx_fifo.tail = self->tx_buff.head;
switch_bank(iobase, BANK1);
outb(inb(iobase+FIR_CR) & ~CR_DMA_EN, iobase+FIR_CR);
switch_bank(iobase, BANK0);
outb(0x07, iobase+FIR_LSR);
self->rcvFramesOverflow = FALSE;
self->LineStatus = inb(iobase+FIR_LSR) ;
self->io.direction = IO_RECV;
self->rx_buff.data = self->rx_buff.head;
outb(LCR_A_FIFO_RESET, iobase+FIR_LCR_A);
self->st_fifo.len = self->st_fifo.pending_bytes = 0;
self->st_fifo.tail = self->st_fifo.head = 0;
irda_setup_dma(self->io.dma, self->rx_buff_dma, self->rx_buff.truesize,
DMA_RX_MODE);
tmp = inb(iobase+FIR_LCR_B);
outb((unsigned char)(tmp &0x3f) | LCR_B_RX_MODE | LCR_B_BW , iobase + FIR_LCR_B);
IRDA_DEBUG(1, "%s(), *** Change To RX mode: FIR_LCR_B = 0x%x ***\n", __func__ , inb(iobase+FIR_LCR_B));
switch_bank(iobase, BANK1);
outb(RX_FIFO_Threshold, iobase+FIR_FIFO_TR);
outb(RX_DMA_Threshold, iobase+FIR_DMA_TR);
outb(CR_DMA_EN | CR_DMA_BURST, iobase+FIR_CR);
switch_bank(iobase, BANK0);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
return 0;
}
static int ali_ircc_dma_receive_complete(struct ali_ircc_cb *self)
{
struct st_fifo *st_fifo;
struct sk_buff *skb;
__u8 status, MessageCount;
int len, i, iobase, val;
IRDA_DEBUG(1, "%s(), ---------------- Start -----------------\n", __func__ );
st_fifo = &self->st_fifo;
iobase = self->io.fir_base;
switch_bank(iobase, BANK0);
MessageCount = inb(iobase+ FIR_LSR)&0x07;
if (MessageCount > 0)
IRDA_DEBUG(0, "%s(), Message count = %d,\n", __func__ , MessageCount);
for (i=0; i<=MessageCount; i++)
{
switch_bank(iobase, BANK0);
status = inb(iobase+FIR_LSR);
switch_bank(iobase, BANK2);
len = inb(iobase+FIR_RX_DSR_HI) & 0x0f;
len = len << 8;
len |= inb(iobase+FIR_RX_DSR_LO);
IRDA_DEBUG(1, "%s(), RX Length = 0x%.2x,\n", __func__ , len);
IRDA_DEBUG(1, "%s(), RX Status = 0x%.2x,\n", __func__ , status);
if (st_fifo->tail >= MAX_RX_WINDOW) {
IRDA_DEBUG(0, "%s(), window is full!\n", __func__ );
continue;
}
st_fifo->entries[st_fifo->tail].status = status;
st_fifo->entries[st_fifo->tail].len = len;
st_fifo->pending_bytes += len;
st_fifo->tail++;
st_fifo->len++;
}
for (i=0; i<=MessageCount; i++)
{
status = st_fifo->entries[st_fifo->head].status;
len = st_fifo->entries[st_fifo->head].len;
st_fifo->pending_bytes -= len;
st_fifo->head++;
st_fifo->len--;
if ((status & 0xd8) || self->rcvFramesOverflow || (len==0))
{
IRDA_DEBUG(0,"%s(), ************* RX Errors ************\n", __func__ );
self->netdev->stats.rx_errors++;
self->rx_buff.data += len;
if (status & LSR_FIFO_UR)
{
self->netdev->stats.rx_frame_errors++;
IRDA_DEBUG(0,"%s(), ************* FIFO Errors ************\n", __func__ );
}
if (status & LSR_FRAME_ERROR)
{
self->netdev->stats.rx_frame_errors++;
IRDA_DEBUG(0,"%s(), ************* FRAME Errors ************\n", __func__ );
}
if (status & LSR_CRC_ERROR)
{
self->netdev->stats.rx_crc_errors++;
IRDA_DEBUG(0,"%s(), ************* CRC Errors ************\n", __func__ );
}
if(self->rcvFramesOverflow)
{
self->netdev->stats.rx_frame_errors++;
IRDA_DEBUG(0,"%s(), ************* Overran DMA buffer ************\n", __func__ );
}
if(len == 0)
{
self->netdev->stats.rx_frame_errors++;
IRDA_DEBUG(0,"%s(), ********** Receive Frame Size = 0 *********\n", __func__ );
}
}
else
{
if (st_fifo->pending_bytes < 32)
{
switch_bank(iobase, BANK0);
val = inb(iobase+FIR_BSR);
if ((val& BSR_FIFO_NOT_EMPTY)== 0x80)
{
IRDA_DEBUG(0, "%s(), ************* BSR_FIFO_NOT_EMPTY ************\n", __func__ );
st_fifo->head--;
st_fifo->len++;
st_fifo->pending_bytes += len;
st_fifo->entries[st_fifo->head].status = status;
st_fifo->entries[st_fifo->head].len = len;
switch_bank(iobase, BANK1);
outb(TIMER_IIR_500, iobase+FIR_TIMER_IIR);
outb(inb(iobase+FIR_CR) | CR_TIMER_EN, iobase+FIR_CR);
return FALSE;
}
}
do_gettimeofday(&self->stamp);
skb = dev_alloc_skb(len+1);
if (skb == NULL)
{
IRDA_WARNING("%s(), memory squeeze, "
"dropping frame.\n",
__func__);
self->netdev->stats.rx_dropped++;
return FALSE;
}
skb_reserve(skb, 1);
skb_put(skb, len);
skb_copy_to_linear_data(skb, self->rx_buff.data, len);
self->rx_buff.data += len;
self->netdev->stats.rx_bytes += len;
self->netdev->stats.rx_packets++;
skb->dev = self->netdev;
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
netif_rx(skb);
}
}
switch_bank(iobase, BANK0);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
return TRUE;
}
static netdev_tx_t ali_ircc_sir_hard_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ali_ircc_cb *self;
unsigned long flags;
int iobase;
__u32 speed;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_ASSERT(dev != NULL, return NETDEV_TX_OK;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return NETDEV_TX_OK;);
iobase = self->io.sir_base;
netif_stop_queue(dev);
spin_lock_irqsave(&self->lock, flags);
speed = irda_get_next_speed(skb);
if ((speed != self->io.speed) && (speed != -1)) {
if (!skb->len) {
ali_ircc_change_speed(self, speed);
dev->trans_start = jiffies;
spin_unlock_irqrestore(&self->lock, flags);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
} else
self->new_speed = speed;
}
self->tx_buff.data = self->tx_buff.head;
self->tx_buff.len = async_wrap_skb(skb, self->tx_buff.data,
self->tx_buff.truesize);
self->netdev->stats.tx_bytes += self->tx_buff.len;
outb(UART_IER_THRI, iobase+UART_IER);
dev->trans_start = jiffies;
spin_unlock_irqrestore(&self->lock, flags);
dev_kfree_skb(skb);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
return NETDEV_TX_OK;
}
static int ali_ircc_net_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct if_irda_req *irq = (struct if_irda_req *) rq;
struct ali_ircc_cb *self;
unsigned long flags;
int ret = 0;
IRDA_DEBUG(2, "%s(), ---------------- Start ----------------\n", __func__ );
IRDA_ASSERT(dev != NULL, return -1;);
self = netdev_priv(dev);
IRDA_ASSERT(self != NULL, return -1;);
IRDA_DEBUG(2, "%s(), %s, (cmd=0x%X)\n", __func__ , dev->name, cmd);
switch (cmd) {
case SIOCSBANDWIDTH:
IRDA_DEBUG(1, "%s(), SIOCSBANDWIDTH\n", __func__ );
if (!in_interrupt() && !capable(CAP_NET_ADMIN))
return -EPERM;
spin_lock_irqsave(&self->lock, flags);
ali_ircc_change_speed(self, irq->ifr_baudrate);
spin_unlock_irqrestore(&self->lock, flags);
break;
case SIOCSMEDIABUSY:
IRDA_DEBUG(1, "%s(), SIOCSMEDIABUSY\n", __func__ );
if (!capable(CAP_NET_ADMIN))
return -EPERM;
irda_device_set_media_busy(self->netdev, TRUE);
break;
case SIOCGRECEIVING:
IRDA_DEBUG(2, "%s(), SIOCGRECEIVING\n", __func__ );
irq->ifr_receiving = ali_ircc_is_receiving(self);
break;
default:
ret = -EOPNOTSUPP;
}
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
return ret;
}
static int ali_ircc_is_receiving(struct ali_ircc_cb *self)
{
unsigned long flags;
int status = FALSE;
int iobase;
IRDA_DEBUG(2, "%s(), ---------------- Start -----------------\n", __func__ );
IRDA_ASSERT(self != NULL, return FALSE;);
spin_lock_irqsave(&self->lock, flags);
if (self->io.speed > 115200)
{
iobase = self->io.fir_base;
switch_bank(iobase, BANK1);
if((inb(iobase+FIR_FIFO_FR) & 0x3f) != 0)
{
IRDA_DEBUG(1, "%s(), We are receiving something\n", __func__ );
status = TRUE;
}
switch_bank(iobase, BANK0);
}
else
{
status = (self->rx_buff.state != OUTSIDE_FRAME);
}
spin_unlock_irqrestore(&self->lock, flags);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
return status;
}
static int ali_ircc_suspend(struct platform_device *dev, pm_message_t state)
{
struct ali_ircc_cb *self = platform_get_drvdata(dev);
IRDA_MESSAGE("%s, Suspending\n", ALI_IRCC_DRIVER_NAME);
if (self->io.suspended)
return 0;
ali_ircc_net_close(self->netdev);
self->io.suspended = 1;
return 0;
}
static int ali_ircc_resume(struct platform_device *dev)
{
struct ali_ircc_cb *self = platform_get_drvdata(dev);
if (!self->io.suspended)
return 0;
ali_ircc_net_open(self->netdev);
IRDA_MESSAGE("%s, Waking up\n", ALI_IRCC_DRIVER_NAME);
self->io.suspended = 0;
return 0;
}
static void SetCOMInterrupts(struct ali_ircc_cb *self , unsigned char enable)
{
unsigned char newMask;
int iobase = self->io.fir_base;
IRDA_DEBUG(2, "%s(), -------- Start -------- ( Enable = %d )\n", __func__ , enable);
if (enable){
if (self->io.direction == IO_XMIT)
{
if (self->io.speed > 115200)
{
newMask = self->ier;
}
else
{
newMask = UART_IER_THRI | UART_IER_RDI;
}
}
else {
if (self->io.speed > 115200)
{
newMask = self->ier;
}
else
{
newMask = UART_IER_RDI;
}
}
}
else
{
newMask = 0x00;
}
if (self->io.speed > 115200)
{
switch_bank(iobase, BANK0);
outb(newMask, iobase+FIR_IER);
}
else
outb(newMask, iobase+UART_IER);
IRDA_DEBUG(2, "%s(), ----------------- End ------------------\n", __func__ );
}
static void SIR2FIR(int iobase)
{
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__ );
outb(0x28, iobase+UART_MCR);
outb(0x68, iobase+UART_MCR);
outb(0x88, iobase+UART_MCR);
outb(0x60, iobase+FIR_MCR);
outb(0x20, iobase+FIR_MCR);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
}
static void FIR2SIR(int iobase)
{
unsigned char val;
IRDA_DEBUG(1, "%s(), ---------------- Start ----------------\n", __func__ );
outb(0x20, iobase+FIR_MCR);
outb(0x00, iobase+UART_IER);
outb(0xA0, iobase+FIR_MCR);
outb(0x00, iobase+UART_FCR);
outb(0x07, iobase+UART_FCR);
val = inb(iobase+UART_RX);
val = inb(iobase+UART_LSR);
val = inb(iobase+UART_MSR);
IRDA_DEBUG(1, "%s(), ----------------- End ------------------\n", __func__ );
}
