static inline unsigned int serial_in(struct uart_hsu_port *up, int offset)
{
unsigned int val;
if (offset > UART_MSR) {
offset <<= 2;
val = readl(up->port.membase + offset);
} else
val = (unsigned int)readb(up->port.membase + offset);
return val;
}
static inline void serial_out(struct uart_hsu_port *up, int offset, int value)
{
if (offset > UART_MSR) {
offset <<= 2;
writel(value, up->port.membase + offset);
} else {
unsigned char val = value & 0xff;
writeb(val, up->port.membase + offset);
}
}
static ssize_t port_show_regs(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct uart_hsu_port *up = file->private_data;
char *buf;
u32 len = 0;
ssize_t ret;
buf = kzalloc(HSU_REGS_BUFSIZE, GFP_KERNEL);
if (!buf)
return 0;
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"MFD HSU port[%d] regs:\n", up->index);
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"=================================\n");
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"IER: \t\t0x%08x\n", serial_in(up, UART_IER));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"IIR: \t\t0x%08x\n", serial_in(up, UART_IIR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"LCR: \t\t0x%08x\n", serial_in(up, UART_LCR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"MCR: \t\t0x%08x\n", serial_in(up, UART_MCR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"LSR: \t\t0x%08x\n", serial_in(up, UART_LSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"MSR: \t\t0x%08x\n", serial_in(up, UART_MSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"FOR: \t\t0x%08x\n", serial_in(up, UART_FOR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"PS: \t\t0x%08x\n", serial_in(up, UART_PS));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"MUL: \t\t0x%08x\n", serial_in(up, UART_MUL));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"DIV: \t\t0x%08x\n", serial_in(up, UART_DIV));
if (len > HSU_REGS_BUFSIZE)
len = HSU_REGS_BUFSIZE;
ret = simple_read_from_buffer(user_buf, count, ppos, buf, len);
kfree(buf);
return ret;
}
static ssize_t dma_show_regs(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct hsu_dma_chan *chan = file->private_data;
char *buf;
u32 len = 0;
ssize_t ret;
buf = kzalloc(HSU_REGS_BUFSIZE, GFP_KERNEL);
if (!buf)
return 0;
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"MFD HSU DMA channel [%d] regs:\n", chan->id);
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"=================================\n");
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"CR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_CR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"DCR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_DCR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"BSR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_BSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"MOTSR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_MOTSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0SAR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D0SAR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0TSR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D0TSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0SAR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D1SAR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0TSR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D1TSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0SAR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D2SAR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0TSR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D2TSR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0SAR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D3SAR));
len += snprintf(buf + len, HSU_REGS_BUFSIZE - len,
"D0TSR: \t\t0x%08x\n", chan_readl(chan, HSU_CH_D3TSR));
if (len > HSU_REGS_BUFSIZE)
len = HSU_REGS_BUFSIZE;
ret = simple_read_from_buffer(user_buf, count, ppos, buf, len);
kfree(buf);
return ret;
}
static int hsu_debugfs_init(struct hsu_port *hsu)
{
int i;
char name[32];
hsu->debugfs = debugfs_create_dir("hsu", NULL);
if (!hsu->debugfs)
return -ENOMEM;
for (i = 0; i < 3; i++) {
snprintf(name, sizeof(name), "port_%d_regs", i);
debugfs_create_file(name, S_IFREG | S_IRUGO,
hsu->debugfs, (void *)(&hsu->port[i]), &port_regs_ops);
}
for (i = 0; i < 6; i++) {
snprintf(name, sizeof(name), "dma_chan_%d_regs", i);
debugfs_create_file(name, S_IFREG | S_IRUGO,
hsu->debugfs, (void *)&hsu->chans[i], &dma_regs_ops);
}
return 0;
}
static void hsu_debugfs_remove(struct hsu_port *hsu)
{
if (hsu->debugfs)
debugfs_remove_recursive(hsu->debugfs);
}
static inline int hsu_debugfs_init(struct hsu_port *hsu)
{
return 0;
}
static inline void hsu_debugfs_remove(struct hsu_port *hsu)
{
}
static void serial_hsu_enable_ms(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
}
void hsu_dma_tx(struct uart_hsu_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
struct hsu_dma_buffer *dbuf = &up->txbuf;
int count;
if (up->dma_tx_on)
return;
xmit->tail += dbuf->ofs;
xmit->tail &= UART_XMIT_SIZE - 1;
up->port.icount.tx += dbuf->ofs;
dbuf->ofs = 0;
chan_writel(up->txc, HSU_CH_CR, 0x0);
if (!uart_circ_empty(xmit) && !uart_tx_stopped(&up->port)) {
dma_sync_single_for_device(up->port.dev,
dbuf->dma_addr,
dbuf->dma_size,
DMA_TO_DEVICE);
count = CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE);
dbuf->ofs = count;
chan_writel(up->txc, HSU_CH_D0SAR, dbuf->dma_addr + xmit->tail);
chan_writel(up->txc, HSU_CH_D0TSR, count);
chan_writel(up->txc, HSU_CH_DCR, 0x1
| (0x1 << 8)
| (0x1 << 16)
| (0x1 << 24));
up->dma_tx_on = 1;
chan_writel(up->txc, HSU_CH_CR, 0x1);
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
}
void hsu_dma_start_rx_chan(struct hsu_dma_chan *rxc, struct hsu_dma_buffer *dbuf)
{
dbuf->ofs = 0;
chan_writel(rxc, HSU_CH_BSR, 32);
chan_writel(rxc, HSU_CH_MOTSR, 4);
chan_writel(rxc, HSU_CH_D0SAR, dbuf->dma_addr);
chan_writel(rxc, HSU_CH_D0TSR, dbuf->dma_size);
chan_writel(rxc, HSU_CH_DCR, 0x1 | (0x1 << 8)
| (0x1 << 16)
| (0x1 << 24)
);
chan_writel(rxc, HSU_CH_CR, 0x3);
}
static void serial_hsu_start_tx(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
if (up->use_dma) {
hsu_dma_tx(up);
} else if (!(up->ier & UART_IER_THRI)) {
up->ier |= UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
}
static void serial_hsu_stop_tx(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
struct hsu_dma_chan *txc = up->txc;
if (up->use_dma)
chan_writel(txc, HSU_CH_CR, 0x0);
else if (up->ier & UART_IER_THRI) {
up->ier &= ~UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
}
void hsu_dma_rx(struct uart_hsu_port *up, u32 int_sts)
{
struct hsu_dma_buffer *dbuf = &up->rxbuf;
struct hsu_dma_chan *chan = up->rxc;
struct uart_port *port = &up->port;
struct tty_struct *tty = port->state->port.tty;
int count;
if (!tty)
return;
if (int_sts & 0xf00)
udelay(2);
chan_writel(chan, HSU_CH_CR, 0x0);
count = chan_readl(chan, HSU_CH_D0SAR) - dbuf->dma_addr;
if (!count) {
chan_writel(chan, HSU_CH_CR, 0x3);
return;
}
dma_sync_single_for_cpu(port->dev, dbuf->dma_addr,
dbuf->dma_size, DMA_FROM_DEVICE);
tty_insert_flip_string(tty, dbuf->buf, count);
port->icount.rx += count;
dma_sync_single_for_device(up->port.dev, dbuf->dma_addr,
dbuf->dma_size, DMA_FROM_DEVICE);
chan_writel(chan, HSU_CH_D0SAR, dbuf->dma_addr);
chan_writel(chan, HSU_CH_D0TSR, dbuf->dma_size);
chan_writel(chan, HSU_CH_DCR, 0x1
| (0x1 << 8)
| (0x1 << 16)
| (0x1 << 24)
);
tty_flip_buffer_push(tty);
chan_writel(chan, HSU_CH_CR, 0x3);
}
static void serial_hsu_stop_rx(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
struct hsu_dma_chan *chan = up->rxc;
if (up->use_dma)
chan_writel(chan, HSU_CH_CR, 0x2);
else {
up->ier &= ~UART_IER_RLSI;
up->port.read_status_mask &= ~UART_LSR_DR;
serial_out(up, UART_IER, up->ier);
}
}
static inline void receive_chars(struct uart_hsu_port *up, int *status)
{
struct tty_struct *tty = up->port.state->port.tty;
unsigned int ch, flag;
unsigned int max_count = 256;
if (!tty)
return;
do {
ch = serial_in(up, UART_RX);
flag = TTY_NORMAL;
up->port.icount.rx++;
if (unlikely(*status & (UART_LSR_BI | UART_LSR_PE |
UART_LSR_FE | UART_LSR_OE))) {
dev_warn(up->dev, "We really rush into ERR/BI case"
"status = 0x%02x", *status);
if (*status & UART_LSR_BI) {
*status &= ~(UART_LSR_FE | UART_LSR_PE);
up->port.icount.brk++;
if (uart_handle_break(&up->port))
goto ignore_char;
} else if (*status & UART_LSR_PE)
up->port.icount.parity++;
else if (*status & UART_LSR_FE)
up->port.icount.frame++;
if (*status & UART_LSR_OE)
up->port.icount.overrun++;
*status &= up->port.read_status_mask;
#ifdef CONFIG_SERIAL_MFD_HSU_CONSOLE
if (up->port.cons &&
up->port.cons->index == up->port.line) {
*status |= up->lsr_break_flag;
up->lsr_break_flag = 0;
}
#endif
if (*status & UART_LSR_BI) {
flag = TTY_BREAK;
} else if (*status & UART_LSR_PE)
flag = TTY_PARITY;
else if (*status & UART_LSR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&up->port, ch))
goto ignore_char;
uart_insert_char(&up->port, *status, UART_LSR_OE, ch, flag);
ignore_char:
*status = serial_in(up, UART_LSR);
} while ((*status & UART_LSR_DR) && max_count--);
tty_flip_buffer_push(tty);
}
static void transmit_chars(struct uart_hsu_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
int count;
if (up->port.x_char) {
serial_out(up, UART_TX, up->port.x_char);
up->port.icount.tx++;
up->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&up->port)) {
serial_hsu_stop_tx(&up->port);
return;
}
count = up->port.fifosize / 2;
do {
serial_out(up, UART_TX, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
if (uart_circ_empty(xmit))
serial_hsu_stop_tx(&up->port);
}
static inline void check_modem_status(struct uart_hsu_port *up)
{
int status;
status = serial_in(up, UART_MSR);
if ((status & UART_MSR_ANY_DELTA) == 0)
return;
if (status & UART_MSR_TERI)
up->port.icount.rng++;
if (status & UART_MSR_DDSR)
up->port.icount.dsr++;
if (status & UART_MSR_DDCD)
uart_handle_dcd_change(&up->port, status & UART_MSR_DCD);
if (status & UART_MSR_DCTS)
uart_handle_cts_change(&up->port, status & UART_MSR_CTS);
wake_up_interruptible(&up->port.state->port.delta_msr_wait);
}
static irqreturn_t port_irq(int irq, void *dev_id)
{
struct uart_hsu_port *up = dev_id;
unsigned int iir, lsr;
unsigned long flags;
if (unlikely(!up->running))
return IRQ_NONE;
spin_lock_irqsave(&up->port.lock, flags);
if (up->use_dma) {
lsr = serial_in(up, UART_LSR);
if (unlikely(lsr & (UART_LSR_BI | UART_LSR_PE |
UART_LSR_FE | UART_LSR_OE)))
dev_warn(up->dev,
"Got lsr irq while using DMA, lsr = 0x%2x\n",
lsr);
check_modem_status(up);
spin_unlock_irqrestore(&up->port.lock, flags);
return IRQ_HANDLED;
}
iir = serial_in(up, UART_IIR);
if (iir & UART_IIR_NO_INT) {
spin_unlock_irqrestore(&up->port.lock, flags);
return IRQ_NONE;
}
lsr = serial_in(up, UART_LSR);
if (lsr & UART_LSR_DR)
receive_chars(up, &lsr);
check_modem_status(up);
if (lsr & UART_LSR_THRE)
transmit_chars(up);
spin_unlock_irqrestore(&up->port.lock, flags);
return IRQ_HANDLED;
}
static inline void dma_chan_irq(struct hsu_dma_chan *chan)
{
struct uart_hsu_port *up = chan->uport;
unsigned long flags;
u32 int_sts;
spin_lock_irqsave(&up->port.lock, flags);
if (!up->use_dma || !up->running)
goto exit;
int_sts = chan_readl(chan, HSU_CH_SR);
if (chan->dirt == DMA_FROM_DEVICE)
hsu_dma_rx(up, int_sts);
if (chan->dirt == DMA_TO_DEVICE) {
chan_writel(chan, HSU_CH_CR, 0x0);
up->dma_tx_on = 0;
hsu_dma_tx(up);
}
exit:
spin_unlock_irqrestore(&up->port.lock, flags);
return;
}
static irqreturn_t dma_irq(int irq, void *dev_id)
{
struct hsu_port *hsu = dev_id;
u32 int_sts, i;
int_sts = mfd_readl(hsu, HSU_GBL_DMAISR);
for (i = 0; i < 6; i++) {
if (int_sts & 0x1)
dma_chan_irq(&hsu->chans[i]);
int_sts >>= 1;
}
return IRQ_HANDLED;
}
static unsigned int serial_hsu_tx_empty(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned long flags;
unsigned int ret;
spin_lock_irqsave(&up->port.lock, flags);
ret = serial_in(up, UART_LSR) & UART_LSR_TEMT ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
return ret;
}
static unsigned int serial_hsu_get_mctrl(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned char status;
unsigned int ret;
status = serial_in(up, UART_MSR);
ret = 0;
if (status & UART_MSR_DCD)
ret |= TIOCM_CAR;
if (status & UART_MSR_RI)
ret |= TIOCM_RNG;
if (status & UART_MSR_DSR)
ret |= TIOCM_DSR;
if (status & UART_MSR_CTS)
ret |= TIOCM_CTS;
return ret;
}
static void serial_hsu_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned char mcr = 0;
if (mctrl & TIOCM_RTS)
mcr |= UART_MCR_RTS;
if (mctrl & TIOCM_DTR)
mcr |= UART_MCR_DTR;
if (mctrl & TIOCM_OUT1)
mcr |= UART_MCR_OUT1;
if (mctrl & TIOCM_OUT2)
mcr |= UART_MCR_OUT2;
if (mctrl & TIOCM_LOOP)
mcr |= UART_MCR_LOOP;
mcr |= up->mcr;
serial_out(up, UART_MCR, mcr);
}
static void serial_hsu_break_ctl(struct uart_port *port, int break_state)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
up->lcr |= UART_LCR_SBC;
else
up->lcr &= ~UART_LCR_SBC;
serial_out(up, UART_LCR, up->lcr);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int serial_hsu_startup(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned long flags;
pm_runtime_get_sync(up->dev);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_out(up, UART_FCR, 0);
(void) serial_in(up, UART_LSR);
(void) serial_in(up, UART_RX);
(void) serial_in(up, UART_IIR);
(void) serial_in(up, UART_MSR);
serial_out(up, UART_LCR, UART_LCR_WLEN8);
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl |= TIOCM_OUT2;
serial_hsu_set_mctrl(&up->port, up->port.mctrl);
if (!up->use_dma)
up->ier = UART_IER_RLSI | UART_IER_RDI | UART_IER_RTOIE;
else
up->ier = 0;
serial_out(up, UART_IER, up->ier);
spin_unlock_irqrestore(&up->port.lock, flags);
if (up->use_dma) {
struct hsu_dma_buffer *dbuf;
struct circ_buf *xmit = &port->state->xmit;
up->dma_tx_on = 0;
dbuf = &up->rxbuf;
dbuf->buf = kzalloc(HSU_DMA_BUF_SIZE, GFP_KERNEL);
if (!dbuf->buf) {
up->use_dma = 0;
goto exit;
}
dbuf->dma_addr = dma_map_single(port->dev,
dbuf->buf,
HSU_DMA_BUF_SIZE,
DMA_FROM_DEVICE);
dbuf->dma_size = HSU_DMA_BUF_SIZE;
hsu_dma_start_rx_chan(up->rxc, dbuf);
dbuf = &up->txbuf;
dbuf->buf = xmit->buf;
dbuf->dma_addr = dma_map_single(port->dev,
dbuf->buf,
UART_XMIT_SIZE,
DMA_TO_DEVICE);
dbuf->dma_size = UART_XMIT_SIZE;
chan_writel(up->txc, HSU_CH_BSR, 32);
chan_writel(up->txc, HSU_CH_MOTSR, 4);
dbuf->ofs = 0;
}
exit:
(void) serial_in(up, UART_LSR);
(void) serial_in(up, UART_RX);
(void) serial_in(up, UART_IIR);
(void) serial_in(up, UART_MSR);
up->running = 1;
return 0;
}
static void serial_hsu_shutdown(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned long flags;
up->ier = 0;
serial_out(up, UART_IER, 0);
up->running = 0;
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl &= ~TIOCM_OUT2;
serial_hsu_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
serial_out(up, UART_LCR, serial_in(up, UART_LCR) & ~UART_LCR_SBC);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR |
UART_FCR_CLEAR_XMIT);
serial_out(up, UART_FCR, 0);
pm_runtime_put(up->dev);
}
static void
serial_hsu_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
unsigned char cval, fcr = 0;
unsigned long flags;
unsigned int baud, quot;
u32 ps, mul;
switch (termios->c_cflag & CSIZE) {
case CS5:
cval = UART_LCR_WLEN5;
break;
case CS6:
cval = UART_LCR_WLEN6;
break;
case CS7:
cval = UART_LCR_WLEN7;
break;
default:
case CS8:
cval = UART_LCR_WLEN8;
break;
}
termios->c_cflag &= ~CMSPAR;
if (termios->c_cflag & CSTOPB)
cval |= UART_LCR_STOP;
if (termios->c_cflag & PARENB)
cval |= UART_LCR_PARITY;
if (!(termios->c_cflag & PARODD))
cval |= UART_LCR_EPAR;
baud = uart_get_baud_rate(port, termios, old, 0, 4000000);
quot = 1;
ps = 0x10;
mul = 0x3600;
switch (baud) {
case 3500000:
mul = 0x3345;
ps = 0xC;
break;
case 1843200:
mul = 0x2400;
break;
case 3000000:
case 2500000:
case 2000000:
case 1500000:
case 1000000:
case 500000:
mul = baud / 500000 * 0x9C4;
break;
default:
quot = 0;
}
if (!quot)
quot = uart_get_divisor(port, baud);
if ((up->port.uartclk / quot) < (2400 * 16))
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_HSU_64_1B;
else if ((up->port.uartclk / quot) < (230400 * 16))
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_HSU_64_16B;
else
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_HSU_64_32B;
fcr |= UART_FCR_HSU_64B_FIFO;
spin_lock_irqsave(&up->port.lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
up->port.read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (termios->c_iflag & INPCK)
up->port.read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (termios->c_iflag & (BRKINT | PARMRK))
up->port.read_status_mask |= UART_LSR_BI;
up->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (termios->c_iflag & IGNBRK) {
up->port.ignore_status_mask |= UART_LSR_BI;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_OE;
}
if ((termios->c_cflag & CREAD) == 0)
up->port.ignore_status_mask |= UART_LSR_DR;
up->ier &= ~UART_IER_MSI;
if (UART_ENABLE_MS(&up->port, termios->c_cflag))
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
if (termios->c_cflag & CRTSCTS)
up->mcr |= UART_MCR_AFE | UART_MCR_RTS;
else
up->mcr &= ~UART_MCR_AFE;
serial_out(up, UART_LCR, cval | UART_LCR_DLAB);
serial_out(up, UART_DLL, quot & 0xff);
serial_out(up, UART_DLM, quot >> 8);
serial_out(up, UART_LCR, cval);
serial_out(up, UART_MUL, mul);
serial_out(up, UART_PS, ps);
up->lcr = cval;
serial_hsu_set_mctrl(&up->port, up->port.mctrl);
serial_out(up, UART_FCR, fcr);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
serial_hsu_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
}
static void serial_hsu_release_port(struct uart_port *port)
{
}
static int serial_hsu_request_port(struct uart_port *port)
{
return 0;
}
static void serial_hsu_config_port(struct uart_port *port, int flags)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
up->port.type = PORT_MFD;
}
static int
serial_hsu_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static const char *
serial_hsu_type(struct uart_port *port)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
return up->name;
}
static inline void wait_for_xmitr(struct uart_hsu_port *up)
{
unsigned int status, tmout = 1000;
do {
status = serial_in(up, UART_LSR);
if (status & UART_LSR_BI)
up->lsr_break_flag = UART_LSR_BI;
if (--tmout == 0)
break;
udelay(1);
} while (!(status & BOTH_EMPTY));
if (up->port.flags & UPF_CONS_FLOW) {
tmout = 1000000;
while (--tmout &&
((serial_in(up, UART_MSR) & UART_MSR_CTS) == 0))
udelay(1);
}
}
static void serial_hsu_console_putchar(struct uart_port *port, int ch)
{
struct uart_hsu_port *up =
container_of(port, struct uart_hsu_port, port);
wait_for_xmitr(up);
serial_out(up, UART_TX, ch);
}
static void
serial_hsu_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_hsu_port *up = serial_hsu_ports[co->index];
unsigned long flags;
unsigned int ier;
int locked = 1;
local_irq_save(flags);
if (up->port.sysrq)
locked = 0;
else if (oops_in_progress) {
locked = spin_trylock(&up->port.lock);
} else
spin_lock(&up->port.lock);
ier = serial_in(up, UART_IER);
serial_out(up, UART_IER, 0);
uart_console_write(&up->port, s, count, serial_hsu_console_putchar);
wait_for_xmitr(up);
serial_out(up, UART_IER, ier);
if (locked)
spin_unlock(&up->port.lock);
local_irq_restore(flags);
}
static int __init
serial_hsu_console_setup(struct console *co, char *options)
{
struct uart_hsu_port *up;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index == -1 || co->index >= serial_hsu_reg.nr)
co->index = 0;
up = serial_hsu_ports[co->index];
if (!up)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&up->port, co, baud, parity, bits, flow);
}
static int serial_hsu_suspend(struct pci_dev *pdev, pm_message_t state)
{
void *priv = pci_get_drvdata(pdev);
struct uart_hsu_port *up;
if (priv && (pdev->device != 0x081E)) {
up = priv;
uart_suspend_port(&serial_hsu_reg, &up->port);
}
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int serial_hsu_resume(struct pci_dev *pdev)
{
void *priv = pci_get_drvdata(pdev);
struct uart_hsu_port *up;
int ret;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret)
dev_warn(&pdev->dev,
"HSU: can't re-enable device, try to continue\n");
if (priv && (pdev->device != 0x081E)) {
up = priv;
uart_resume_port(&serial_hsu_reg, &up->port);
}
return 0;
}
static int serial_hsu_runtime_idle(struct device *dev)
{
int err;
err = pm_schedule_suspend(dev, 500);
if (err)
return -EBUSY;
return 0;
}
static int serial_hsu_runtime_suspend(struct device *dev)
{
return 0;
}
static int serial_hsu_runtime_resume(struct device *dev)
{
return 0;
}
static int serial_hsu_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct uart_hsu_port *uport;
int index, ret;
printk(KERN_INFO "HSU: found PCI Serial controller(ID: %04x:%04x)\n",
pdev->vendor, pdev->device);
switch (pdev->device) {
case 0x081B:
index = 0;
break;
case 0x081C:
index = 1;
break;
case 0x081D:
index = 2;
break;
case 0x081E:
index = 3;
break;
default:
dev_err(&pdev->dev, "HSU: out of index!");
return -ENODEV;
}
ret = pci_enable_device(pdev);
if (ret)
return ret;
if (index == 3) {
ret = request_irq(pdev->irq, dma_irq, 0, "hsu_dma", phsu);
if (ret) {
dev_err(&pdev->dev, "can not get IRQ\n");
goto err_disable;
}
pci_set_drvdata(pdev, phsu);
} else {
uport = &phsu->port[index];
uport->port.irq = pdev->irq;
uport->port.dev = &pdev->dev;
uport->dev = &pdev->dev;
ret = request_irq(pdev->irq, port_irq, 0, uport->name, uport);
if (ret) {
dev_err(&pdev->dev, "can not get IRQ\n");
goto err_disable;
}
uart_add_one_port(&serial_hsu_reg, &uport->port);
pci_set_drvdata(pdev, uport);
}
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_allow(&pdev->dev);
return 0;
err_disable:
pci_disable_device(pdev);
return ret;
}
static void hsu_global_init(void)
{
struct hsu_port *hsu;
struct uart_hsu_port *uport;
struct hsu_dma_chan *dchan;
int i, ret;
hsu = kzalloc(sizeof(struct hsu_port), GFP_KERNEL);
if (!hsu)
return;
hsu->paddr = 0xffa28000;
hsu->iolen = 0x1000;
if (!(request_mem_region(hsu->paddr, hsu->iolen, "HSU global")))
pr_warning("HSU: error in request mem region\n");
hsu->reg = ioremap_nocache((unsigned long)hsu->paddr, hsu->iolen);
if (!hsu->reg) {
pr_err("HSU: error in ioremap\n");
ret = -ENOMEM;
goto err_free_region;
}
uport = hsu->port;
for (i = 0; i < 3; i++) {
uport->port.type = PORT_MFD;
uport->port.iotype = UPIO_MEM;
uport->port.mapbase = (resource_size_t)hsu->paddr
+ HSU_PORT_REG_OFFSET
+ i * HSU_PORT_REG_LENGTH;
uport->port.membase = hsu->reg + HSU_PORT_REG_OFFSET
+ i * HSU_PORT_REG_LENGTH;
sprintf(uport->name, "hsu_port%d", i);
uport->port.fifosize = 64;
uport->port.ops = &serial_hsu_pops;
uport->port.line = i;
uport->port.flags = UPF_IOREMAP;
uport->port.uartclk = 115200 * 24 * 16;
uport->running = 0;
uport->txc = &hsu->chans[i * 2];
uport->rxc = &hsu->chans[i * 2 + 1];
serial_hsu_ports[i] = uport;
uport->index = i;
if (hsu_dma_enable & (1<<i))
uport->use_dma = 1;
else
uport->use_dma = 0;
uport++;
}
dchan = hsu->chans;
for (i = 0; i < 6; i++) {
dchan->id = i;
dchan->dirt = (i & 0x1) ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
dchan->uport = &hsu->port[i/2];
dchan->reg = hsu->reg + HSU_DMA_CHANS_REG_OFFSET +
i * HSU_DMA_CHANS_REG_LENGTH;
dchan++;
}
phsu = hsu;
hsu_debugfs_init(hsu);
return;
err_free_region:
release_mem_region(hsu->paddr, hsu->iolen);
kfree(hsu);
return;
}
static void serial_hsu_remove(struct pci_dev *pdev)
{
void *priv = pci_get_drvdata(pdev);
struct uart_hsu_port *up;
if (!priv)
return;
pm_runtime_forbid(&pdev->dev);
pm_runtime_get_noresume(&pdev->dev);
if (pdev->device != 0x081E) {
up = priv;
uart_remove_one_port(&serial_hsu_reg, &up->port);
}
pci_set_drvdata(pdev, NULL);
free_irq(pdev->irq, priv);
pci_disable_device(pdev);
}
static int __init hsu_pci_init(void)
{
int ret;
hsu_global_init();
ret = uart_register_driver(&serial_hsu_reg);
if (ret)
return ret;
return pci_register_driver(&hsu_pci_driver);
}
static void __exit hsu_pci_exit(void)
{
pci_unregister_driver(&hsu_pci_driver);
uart_unregister_driver(&serial_hsu_reg);
hsu_debugfs_remove(phsu);
kfree(phsu);
}
