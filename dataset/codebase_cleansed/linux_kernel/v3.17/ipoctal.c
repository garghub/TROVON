static int ipoctal_port_activate(struct tty_port *port, struct tty_struct *tty)
{
struct ipoctal_channel *channel;
channel = dev_get_drvdata(tty->dev);
iowrite8(CR_ENABLE_RX, &channel->regs->w.cr);
channel->rx_enable = 1;
return 0;
}
static int ipoctal_open(struct tty_struct *tty, struct file *file)
{
struct ipoctal_channel *channel;
channel = dev_get_drvdata(tty->dev);
tty->driver_data = channel;
return tty_port_open(&channel->tty_port, tty, file);
}
static void ipoctal_reset_stats(struct ipoctal_stats *stats)
{
stats->tx = 0;
stats->rx = 0;
stats->rcv_break = 0;
stats->framing_err = 0;
stats->overrun_err = 0;
stats->parity_err = 0;
}
static void ipoctal_free_channel(struct ipoctal_channel *channel)
{
ipoctal_reset_stats(&channel->stats);
channel->pointer_read = 0;
channel->pointer_write = 0;
channel->nb_bytes = 0;
}
static void ipoctal_close(struct tty_struct *tty, struct file *filp)
{
struct ipoctal_channel *channel = tty->driver_data;
tty_port_close(&channel->tty_port, tty, filp);
ipoctal_free_channel(channel);
}
static int ipoctal_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct ipoctal_channel *channel = tty->driver_data;
icount->cts = 0;
icount->dsr = 0;
icount->rng = 0;
icount->dcd = 0;
icount->rx = channel->stats.rx;
icount->tx = channel->stats.tx;
icount->frame = channel->stats.framing_err;
icount->parity = channel->stats.parity_err;
icount->brk = channel->stats.rcv_break;
return 0;
}
static void ipoctal_irq_rx(struct ipoctal_channel *channel, u8 sr)
{
struct tty_port *port = &channel->tty_port;
unsigned char value;
unsigned char flag;
u8 isr;
do {
value = ioread8(&channel->regs->r.rhr);
flag = TTY_NORMAL;
if (sr & SR_ERROR) {
iowrite8(CR_CMD_RESET_ERR_STATUS, &channel->regs->w.cr);
if (sr & SR_OVERRUN_ERROR) {
channel->stats.overrun_err++;
tty_insert_flip_char(port, 0, TTY_OVERRUN);
}
if (sr & SR_PARITY_ERROR) {
channel->stats.parity_err++;
flag = TTY_PARITY;
}
if (sr & SR_FRAMING_ERROR) {
channel->stats.framing_err++;
flag = TTY_FRAME;
}
if (sr & SR_RECEIVED_BREAK) {
iowrite8(CR_CMD_RESET_BREAK_CHANGE, &channel->regs->w.cr);
channel->stats.rcv_break++;
flag = TTY_BREAK;
}
}
tty_insert_flip_char(port, value, flag);
isr = ioread8(&channel->block_regs->r.isr);
sr = ioread8(&channel->regs->r.sr);
} while (isr & channel->isr_rx_rdy_mask);
tty_flip_buffer_push(port);
}
static void ipoctal_irq_tx(struct ipoctal_channel *channel)
{
unsigned char value;
unsigned int *pointer_write = &channel->pointer_write;
if (channel->nb_bytes == 0)
return;
spin_lock(&channel->lock);
value = channel->tty_port.xmit_buf[*pointer_write];
iowrite8(value, &channel->regs->w.thr);
channel->stats.tx++;
(*pointer_write)++;
*pointer_write = *pointer_write % PAGE_SIZE;
channel->nb_bytes--;
spin_unlock(&channel->lock);
}
static void ipoctal_irq_channel(struct ipoctal_channel *channel)
{
u8 isr, sr;
isr = ioread8(&channel->block_regs->r.isr);
sr = ioread8(&channel->regs->r.sr);
if ((sr & SR_TX_EMPTY) && (channel->nb_bytes == 0)) {
iowrite8(CR_DISABLE_TX, &channel->regs->w.cr);
if (channel->board_id == IPACK1_DEVICE_ID_SBS_OCTAL_485) {
iowrite8(CR_CMD_NEGATE_RTSN, &channel->regs->w.cr);
iowrite8(CR_ENABLE_RX, &channel->regs->w.cr);
channel->rx_enable = 1;
}
}
if ((isr & channel->isr_rx_rdy_mask) && (sr & SR_RX_READY))
ipoctal_irq_rx(channel, sr);
if ((isr & channel->isr_tx_rdy_mask) && (sr & SR_TX_READY))
ipoctal_irq_tx(channel);
}
static irqreturn_t ipoctal_irq_handler(void *arg)
{
unsigned int i;
struct ipoctal *ipoctal = (struct ipoctal *) arg;
readw(ipoctal->int_space + ACK_INT_REQ0);
readw(ipoctal->int_space + ACK_INT_REQ1);
for (i = 0; i < NR_CHANNELS; i++)
ipoctal_irq_channel(&ipoctal->channel[i]);
return IRQ_HANDLED;
}
static int ipoctal_inst_slot(struct ipoctal *ipoctal, unsigned int bus_nr,
unsigned int slot)
{
int res;
int i;
struct tty_driver *tty;
char name[20];
struct ipoctal_channel *channel;
struct ipack_region *region;
void __iomem *addr;
union scc2698_channel __iomem *chan_regs;
union scc2698_block __iomem *block_regs;
ipoctal->board_id = ipoctal->dev->id_device;
region = &ipoctal->dev->region[IPACK_IO_SPACE];
addr = devm_ioremap_nocache(&ipoctal->dev->dev,
region->start, region->size);
if (!addr) {
dev_err(&ipoctal->dev->dev,
"Unable to map slot [%d:%d] IO space!\n",
bus_nr, slot);
return -EADDRNOTAVAIL;
}
chan_regs =
(union scc2698_channel __iomem *) addr;
block_regs =
(union scc2698_block __iomem *) addr;
region = &ipoctal->dev->region[IPACK_INT_SPACE];
ipoctal->int_space =
devm_ioremap_nocache(&ipoctal->dev->dev,
region->start, region->size);
if (!ipoctal->int_space) {
dev_err(&ipoctal->dev->dev,
"Unable to map slot [%d:%d] INT space!\n",
bus_nr, slot);
return -EADDRNOTAVAIL;
}
region = &ipoctal->dev->region[IPACK_MEM8_SPACE];
ipoctal->mem8_space =
devm_ioremap_nocache(&ipoctal->dev->dev,
region->start, 0x8000);
if (!ipoctal->mem8_space) {
dev_err(&ipoctal->dev->dev,
"Unable to map slot [%d:%d] MEM8 space!\n",
bus_nr, slot);
return -EADDRNOTAVAIL;
}
for (i = 0; i < NR_CHANNELS ; i++) {
struct ipoctal_channel *channel = &ipoctal->channel[i];
channel->regs = chan_regs + i;
channel->block_regs = block_regs + (i >> 1);
channel->board_id = ipoctal->board_id;
if (i & 1) {
channel->isr_tx_rdy_mask = ISR_TxRDY_B;
channel->isr_rx_rdy_mask = ISR_RxRDY_FFULL_B;
} else {
channel->isr_tx_rdy_mask = ISR_TxRDY_A;
channel->isr_rx_rdy_mask = ISR_RxRDY_FFULL_A;
}
iowrite8(CR_DISABLE_RX | CR_DISABLE_TX, &channel->regs->w.cr);
channel->rx_enable = 0;
iowrite8(CR_CMD_RESET_RX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_TX, &channel->regs->w.cr);
iowrite8(MR1_CHRL_8_BITS | MR1_ERROR_CHAR | MR1_RxINT_RxRDY,
&channel->regs->w.mr);
iowrite8(0, &channel->regs->w.mr);
iowrite8(TX_CLK_9600 | RX_CLK_9600, &channel->regs->w.csr);
}
for (i = 0; i < IP_OCTAL_NB_BLOCKS; i++) {
iowrite8(ACR_BRG_SET2, &block_regs[i].w.acr);
iowrite8(OPCR_MPP_OUTPUT | OPCR_MPOa_RTSN | OPCR_MPOb_RTSN,
&block_regs[i].w.opcr);
iowrite8(IMR_TxRDY_A | IMR_RxRDY_FFULL_A | IMR_DELTA_BREAK_A |
IMR_TxRDY_B | IMR_RxRDY_FFULL_B | IMR_DELTA_BREAK_B,
&block_regs[i].w.imr);
}
iowrite8(1, ipoctal->mem8_space + 1);
tty = alloc_tty_driver(NR_CHANNELS);
if (!tty)
return -ENOMEM;
tty->owner = THIS_MODULE;
tty->driver_name = KBUILD_MODNAME;
sprintf(name, KBUILD_MODNAME ".%d.%d.", bus_nr, slot);
tty->name = name;
tty->major = 0;
tty->minor_start = 0;
tty->type = TTY_DRIVER_TYPE_SERIAL;
tty->subtype = SERIAL_TYPE_NORMAL;
tty->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty->init_termios = tty_std_termios;
tty->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL | CLOCAL;
tty->init_termios.c_ispeed = 9600;
tty->init_termios.c_ospeed = 9600;
tty_set_operations(tty, &ipoctal_fops);
res = tty_register_driver(tty);
if (res) {
dev_err(&ipoctal->dev->dev, "Can't register tty driver.\n");
put_tty_driver(tty);
return res;
}
ipoctal->tty_drv = tty;
for (i = 0; i < NR_CHANNELS; i++) {
struct device *tty_dev;
channel = &ipoctal->channel[i];
tty_port_init(&channel->tty_port);
tty_port_alloc_xmit_buf(&channel->tty_port);
channel->tty_port.ops = &ipoctal_tty_port_ops;
ipoctal_reset_stats(&channel->stats);
channel->nb_bytes = 0;
spin_lock_init(&channel->lock);
channel->pointer_read = 0;
channel->pointer_write = 0;
tty_dev = tty_port_register_device(&channel->tty_port, tty, i, NULL);
if (IS_ERR(tty_dev)) {
dev_err(&ipoctal->dev->dev, "Failed to register tty device.\n");
tty_port_destroy(&channel->tty_port);
continue;
}
dev_set_drvdata(tty_dev, channel);
}
ipoctal->dev->bus->ops->request_irq(ipoctal->dev,
ipoctal_irq_handler, ipoctal);
return 0;
}
static inline int ipoctal_copy_write_buffer(struct ipoctal_channel *channel,
const unsigned char *buf,
int count)
{
unsigned long flags;
int i;
unsigned int *pointer_read = &channel->pointer_read;
for (i = 0; i < count; i++) {
if (i <= (PAGE_SIZE - channel->nb_bytes)) {
spin_lock_irqsave(&channel->lock, flags);
channel->tty_port.xmit_buf[*pointer_read] = buf[i];
*pointer_read = (*pointer_read + 1) % PAGE_SIZE;
channel->nb_bytes++;
spin_unlock_irqrestore(&channel->lock, flags);
} else {
break;
}
}
return i;
}
static int ipoctal_write_tty(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct ipoctal_channel *channel = tty->driver_data;
unsigned int char_copied;
char_copied = ipoctal_copy_write_buffer(channel, buf, count);
if (channel->board_id == IPACK1_DEVICE_ID_SBS_OCTAL_485) {
iowrite8(CR_DISABLE_RX, &channel->regs->w.cr);
channel->rx_enable = 0;
iowrite8(CR_CMD_ASSERT_RTSN, &channel->regs->w.cr);
}
iowrite8(CR_ENABLE_TX, &channel->regs->w.cr);
return char_copied;
}
static int ipoctal_write_room(struct tty_struct *tty)
{
struct ipoctal_channel *channel = tty->driver_data;
return PAGE_SIZE - channel->nb_bytes;
}
static int ipoctal_chars_in_buffer(struct tty_struct *tty)
{
struct ipoctal_channel *channel = tty->driver_data;
return channel->nb_bytes;
}
static void ipoctal_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
unsigned int cflag;
unsigned char mr1 = 0;
unsigned char mr2 = 0;
unsigned char csr = 0;
struct ipoctal_channel *channel = tty->driver_data;
speed_t baud;
cflag = tty->termios.c_cflag;
iowrite8(CR_DISABLE_RX | CR_DISABLE_TX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_RX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_TX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_ERR_STATUS, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_MR, &channel->regs->w.cr);
switch (cflag & CSIZE) {
case CS6:
mr1 |= MR1_CHRL_6_BITS;
break;
case CS7:
mr1 |= MR1_CHRL_7_BITS;
break;
case CS8:
default:
mr1 |= MR1_CHRL_8_BITS;
tty->termios.c_cflag = (cflag & ~CSIZE) | CS8;
break;
}
if (cflag & PARENB)
if (cflag & PARODD)
mr1 |= MR1_PARITY_ON | MR1_PARITY_ODD;
else
mr1 |= MR1_PARITY_ON | MR1_PARITY_EVEN;
else
mr1 |= MR1_PARITY_OFF;
tty->termios.c_cflag &= ~CMSPAR;
if (cflag & CSTOPB)
mr2 |= MR2_STOP_BITS_LENGTH_2;
else
mr2 |= MR2_STOP_BITS_LENGTH_1;
switch (channel->board_id) {
case IPACK1_DEVICE_ID_SBS_OCTAL_232:
if (cflag & CRTSCTS) {
mr1 |= MR1_RxRTS_CONTROL_ON;
mr2 |= MR2_TxRTS_CONTROL_OFF | MR2_CTS_ENABLE_TX_ON;
} else {
mr1 |= MR1_RxRTS_CONTROL_OFF;
mr2 |= MR2_TxRTS_CONTROL_OFF | MR2_CTS_ENABLE_TX_OFF;
}
break;
case IPACK1_DEVICE_ID_SBS_OCTAL_422:
mr1 |= MR1_RxRTS_CONTROL_OFF;
mr2 |= MR2_TxRTS_CONTROL_OFF | MR2_CTS_ENABLE_TX_OFF;
break;
case IPACK1_DEVICE_ID_SBS_OCTAL_485:
mr1 |= MR1_RxRTS_CONTROL_OFF;
mr2 |= MR2_TxRTS_CONTROL_ON | MR2_CTS_ENABLE_TX_OFF;
break;
default:
return;
break;
}
baud = tty_get_baud_rate(tty);
tty_termios_encode_baud_rate(&tty->termios, baud, baud);
switch (baud) {
case 75:
csr |= TX_CLK_75 | RX_CLK_75;
break;
case 110:
csr |= TX_CLK_110 | RX_CLK_110;
break;
case 150:
csr |= TX_CLK_150 | RX_CLK_150;
break;
case 300:
csr |= TX_CLK_300 | RX_CLK_300;
break;
case 600:
csr |= TX_CLK_600 | RX_CLK_600;
break;
case 1200:
csr |= TX_CLK_1200 | RX_CLK_1200;
break;
case 1800:
csr |= TX_CLK_1800 | RX_CLK_1800;
break;
case 2000:
csr |= TX_CLK_2000 | RX_CLK_2000;
break;
case 2400:
csr |= TX_CLK_2400 | RX_CLK_2400;
break;
case 4800:
csr |= TX_CLK_4800 | RX_CLK_4800;
break;
case 9600:
csr |= TX_CLK_9600 | RX_CLK_9600;
break;
case 19200:
csr |= TX_CLK_19200 | RX_CLK_19200;
break;
case 38400:
default:
csr |= TX_CLK_38400 | RX_CLK_38400;
tty_termios_encode_baud_rate(&tty->termios, 38400, 38400);
break;
}
mr1 |= MR1_ERROR_CHAR;
mr1 |= MR1_RxINT_RxRDY;
iowrite8(mr1, &channel->regs->w.mr);
iowrite8(mr2, &channel->regs->w.mr);
iowrite8(csr, &channel->regs->w.csr);
if (channel->rx_enable)
iowrite8(CR_ENABLE_RX, &channel->regs->w.cr);
}
static void ipoctal_hangup(struct tty_struct *tty)
{
unsigned long flags;
struct ipoctal_channel *channel = tty->driver_data;
if (channel == NULL)
return;
spin_lock_irqsave(&channel->lock, flags);
channel->nb_bytes = 0;
channel->pointer_read = 0;
channel->pointer_write = 0;
spin_unlock_irqrestore(&channel->lock, flags);
tty_port_hangup(&channel->tty_port);
iowrite8(CR_DISABLE_RX | CR_DISABLE_TX, &channel->regs->w.cr);
channel->rx_enable = 0;
iowrite8(CR_CMD_RESET_RX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_TX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_ERR_STATUS, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_MR, &channel->regs->w.cr);
clear_bit(ASYNCB_INITIALIZED, &channel->tty_port.flags);
wake_up_interruptible(&channel->tty_port.open_wait);
}
static void ipoctal_shutdown(struct tty_struct *tty)
{
struct ipoctal_channel *channel = tty->driver_data;
if (channel == NULL)
return;
iowrite8(CR_DISABLE_RX | CR_DISABLE_TX, &channel->regs->w.cr);
channel->rx_enable = 0;
iowrite8(CR_CMD_RESET_RX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_TX, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_ERR_STATUS, &channel->regs->w.cr);
iowrite8(CR_CMD_RESET_MR, &channel->regs->w.cr);
clear_bit(ASYNCB_INITIALIZED, &channel->tty_port.flags);
}
static int ipoctal_probe(struct ipack_device *dev)
{
int res;
struct ipoctal *ipoctal;
ipoctal = kzalloc(sizeof(struct ipoctal), GFP_KERNEL);
if (ipoctal == NULL)
return -ENOMEM;
ipoctal->dev = dev;
res = ipoctal_inst_slot(ipoctal, dev->bus->bus_nr, dev->slot);
if (res)
goto out_uninst;
dev_set_drvdata(&dev->dev, ipoctal);
return 0;
out_uninst:
kfree(ipoctal);
return res;
}
static void __ipoctal_remove(struct ipoctal *ipoctal)
{
int i;
ipoctal->dev->bus->ops->free_irq(ipoctal->dev);
for (i = 0; i < NR_CHANNELS; i++) {
struct ipoctal_channel *channel = &ipoctal->channel[i];
tty_unregister_device(ipoctal->tty_drv, i);
tty_port_free_xmit_buf(&channel->tty_port);
tty_port_destroy(&channel->tty_port);
}
tty_unregister_driver(ipoctal->tty_drv);
put_tty_driver(ipoctal->tty_drv);
kfree(ipoctal);
}
static void ipoctal_remove(struct ipack_device *idev)
{
__ipoctal_remove(dev_get_drvdata(&idev->dev));
}
static int __init ipoctal_init(void)
{
return ipack_driver_register(&driver, THIS_MODULE, KBUILD_MODNAME);
}
static void __exit ipoctal_exit(void)
{
ipack_driver_unregister(&driver);
}
