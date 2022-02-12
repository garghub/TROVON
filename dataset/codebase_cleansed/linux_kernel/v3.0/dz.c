static inline struct dz_port *to_dport(struct uart_port *uport)
{
return container_of(uport, struct dz_port, port);
}
static u16 dz_in(struct dz_port *dport, unsigned offset)
{
void __iomem *addr = dport->port.membase + offset;
return readw(addr);
}
static void dz_out(struct dz_port *dport, unsigned offset, u16 value)
{
void __iomem *addr = dport->port.membase + offset;
writew(value, addr);
}
static void dz_stop_tx(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
u16 tmp, mask = 1 << dport->port.line;
tmp = dz_in(dport, DZ_TCR);
tmp &= ~mask;
dz_out(dport, DZ_TCR, tmp);
}
static void dz_start_tx(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
u16 tmp, mask = 1 << dport->port.line;
tmp = dz_in(dport, DZ_TCR);
tmp |= mask;
dz_out(dport, DZ_TCR, tmp);
}
static void dz_stop_rx(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
dport->cflag &= ~DZ_RXENAB;
dz_out(dport, DZ_LPR, dport->cflag);
}
static void dz_enable_ms(struct uart_port *uport)
{
}
static inline void dz_receive_chars(struct dz_mux *mux)
{
struct uart_port *uport;
struct dz_port *dport = &mux->dport[0];
struct tty_struct *tty = NULL;
struct uart_icount *icount;
int lines_rx[DZ_NB_PORT] = { [0 ... DZ_NB_PORT - 1] = 0 };
unsigned char ch, flag;
u16 status;
int i;
while ((status = dz_in(dport, DZ_RBUF)) & DZ_DVAL) {
dport = &mux->dport[LINE(status)];
uport = &dport->port;
tty = uport->state->port.tty;
ch = UCHAR(status);
flag = TTY_NORMAL;
icount = &uport->icount;
icount->rx++;
if (unlikely(status & (DZ_OERR | DZ_FERR | DZ_PERR))) {
if (!ch) {
status |= (status & DZ_FERR) >>
(ffs(DZ_FERR) - ffs(DZ_BREAK));
status &= ~DZ_FERR;
}
if (status & DZ_BREAK) {
icount->brk++;
if (uart_handle_break(uport))
continue;
} else if (status & DZ_FERR)
icount->frame++;
else if (status & DZ_PERR)
icount->parity++;
if (status & DZ_OERR)
icount->overrun++;
status &= uport->read_status_mask;
if (status & DZ_BREAK)
flag = TTY_BREAK;
else if (status & DZ_FERR)
flag = TTY_FRAME;
else if (status & DZ_PERR)
flag = TTY_PARITY;
}
if (uart_handle_sysrq_char(uport, ch))
continue;
uart_insert_char(uport, status, DZ_OERR, ch, flag);
lines_rx[LINE(status)] = 1;
}
for (i = 0; i < DZ_NB_PORT; i++)
if (lines_rx[i])
tty_flip_buffer_push(mux->dport[i].port.state->port.tty);
}
static inline void dz_transmit_chars(struct dz_mux *mux)
{
struct dz_port *dport = &mux->dport[0];
struct circ_buf *xmit;
unsigned char tmp;
u16 status;
status = dz_in(dport, DZ_CSR);
dport = &mux->dport[LINE(status)];
xmit = &dport->port.state->xmit;
if (dport->port.x_char) {
dz_out(dport, DZ_TDR, dport->port.x_char);
dport->port.icount.tx++;
dport->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&dport->port)) {
spin_lock(&dport->port.lock);
dz_stop_tx(&dport->port);
spin_unlock(&dport->port.lock);
return;
}
tmp = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) & (DZ_XMIT_SIZE - 1);
dz_out(dport, DZ_TDR, tmp);
dport->port.icount.tx++;
if (uart_circ_chars_pending(xmit) < DZ_WAKEUP_CHARS)
uart_write_wakeup(&dport->port);
if (uart_circ_empty(xmit)) {
spin_lock(&dport->port.lock);
dz_stop_tx(&dport->port);
spin_unlock(&dport->port.lock);
}
}
static inline void check_modem_status(struct dz_port *dport)
{
u16 status;
if (dport->port.line != DZ_MODEM)
return;
status = dz_in(dport, DZ_MSR);
if (status)
dport->port.icount.dsr++;
}
static irqreturn_t dz_interrupt(int irq, void *dev_id)
{
struct dz_mux *mux = dev_id;
struct dz_port *dport = &mux->dport[0];
u16 status;
status = dz_in(dport, DZ_CSR);
if ((status & (DZ_RDONE | DZ_RIE)) == (DZ_RDONE | DZ_RIE))
dz_receive_chars(mux);
if ((status & (DZ_TRDY | DZ_TIE)) == (DZ_TRDY | DZ_TIE))
dz_transmit_chars(mux);
return IRQ_HANDLED;
}
static unsigned int dz_get_mctrl(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
unsigned int mctrl = TIOCM_CAR | TIOCM_DSR | TIOCM_CTS;
if (dport->port.line == DZ_MODEM) {
if (dz_in(dport, DZ_MSR) & DZ_MODEM_DSR)
mctrl &= ~TIOCM_DSR;
}
return mctrl;
}
static void dz_set_mctrl(struct uart_port *uport, unsigned int mctrl)
{
struct dz_port *dport = to_dport(uport);
u16 tmp;
if (dport->port.line == DZ_MODEM) {
tmp = dz_in(dport, DZ_TCR);
if (mctrl & TIOCM_DTR)
tmp &= ~DZ_MODEM_DTR;
else
tmp |= DZ_MODEM_DTR;
dz_out(dport, DZ_TCR, tmp);
}
}
static int dz_startup(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
struct dz_mux *mux = dport->mux;
unsigned long flags;
int irq_guard;
int ret;
u16 tmp;
irq_guard = atomic_add_return(1, &mux->irq_guard);
if (irq_guard != 1)
return 0;
ret = request_irq(dport->port.irq, dz_interrupt,
IRQF_SHARED, "dz", mux);
if (ret) {
atomic_add(-1, &mux->irq_guard);
printk(KERN_ERR "dz: Cannot get IRQ %d!\n", dport->port.irq);
return ret;
}
spin_lock_irqsave(&dport->port.lock, flags);
tmp = dz_in(dport, DZ_CSR);
tmp |= DZ_RIE | DZ_TIE;
dz_out(dport, DZ_CSR, tmp);
spin_unlock_irqrestore(&dport->port.lock, flags);
return 0;
}
static void dz_shutdown(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
struct dz_mux *mux = dport->mux;
unsigned long flags;
int irq_guard;
u16 tmp;
spin_lock_irqsave(&dport->port.lock, flags);
dz_stop_tx(&dport->port);
spin_unlock_irqrestore(&dport->port.lock, flags);
irq_guard = atomic_add_return(-1, &mux->irq_guard);
if (!irq_guard) {
tmp = dz_in(dport, DZ_CSR);
tmp &= ~(DZ_RIE | DZ_TIE);
dz_out(dport, DZ_CSR, tmp);
free_irq(dport->port.irq, mux);
}
}
static unsigned int dz_tx_empty(struct uart_port *uport)
{
struct dz_port *dport = to_dport(uport);
unsigned short tmp, mask = 1 << dport->port.line;
tmp = dz_in(dport, DZ_TCR);
tmp &= mask;
return tmp ? 0 : TIOCSER_TEMT;
}
static void dz_break_ctl(struct uart_port *uport, int break_state)
{
struct dz_port *dport = to_dport(uport);
unsigned long flags;
unsigned short tmp, mask = 1 << dport->port.line;
spin_lock_irqsave(&uport->lock, flags);
tmp = dz_in(dport, DZ_TCR);
if (break_state)
tmp |= mask;
else
tmp &= ~mask;
dz_out(dport, DZ_TCR, tmp);
spin_unlock_irqrestore(&uport->lock, flags);
}
static int dz_encode_baud_rate(unsigned int baud)
{
switch (baud) {
case 50:
return DZ_B50;
case 75:
return DZ_B75;
case 110:
return DZ_B110;
case 134:
return DZ_B134;
case 150:
return DZ_B150;
case 300:
return DZ_B300;
case 600:
return DZ_B600;
case 1200:
return DZ_B1200;
case 1800:
return DZ_B1800;
case 2000:
return DZ_B2000;
case 2400:
return DZ_B2400;
case 3600:
return DZ_B3600;
case 4800:
return DZ_B4800;
case 7200:
return DZ_B7200;
case 9600:
return DZ_B9600;
default:
return -1;
}
}
static void dz_reset(struct dz_port *dport)
{
struct dz_mux *mux = dport->mux;
if (mux->initialised)
return;
dz_out(dport, DZ_CSR, DZ_CLR);
while (dz_in(dport, DZ_CSR) & DZ_CLR);
iob();
dz_out(dport, DZ_CSR, DZ_MSE);
mux->initialised = 1;
}
static void dz_set_termios(struct uart_port *uport, struct ktermios *termios,
struct ktermios *old_termios)
{
struct dz_port *dport = to_dport(uport);
unsigned long flags;
unsigned int cflag, baud;
int bflag;
cflag = dport->port.line;
switch (termios->c_cflag & CSIZE) {
case CS5:
cflag |= DZ_CS5;
break;
case CS6:
cflag |= DZ_CS6;
break;
case CS7:
cflag |= DZ_CS7;
break;
case CS8:
default:
cflag |= DZ_CS8;
}
if (termios->c_cflag & CSTOPB)
cflag |= DZ_CSTOPB;
if (termios->c_cflag & PARENB)
cflag |= DZ_PARENB;
if (termios->c_cflag & PARODD)
cflag |= DZ_PARODD;
baud = uart_get_baud_rate(uport, termios, old_termios, 50, 9600);
bflag = dz_encode_baud_rate(baud);
if (bflag < 0) {
baud = uart_get_baud_rate(uport, old_termios, NULL, 50, 9600);
bflag = dz_encode_baud_rate(baud);
if (bflag < 0) {
baud = 9600;
bflag = DZ_B9600;
}
tty_termios_encode_baud_rate(termios, baud, baud);
}
cflag |= bflag;
if (termios->c_cflag & CREAD)
cflag |= DZ_RXENAB;
spin_lock_irqsave(&dport->port.lock, flags);
uart_update_timeout(uport, termios->c_cflag, baud);
dz_out(dport, DZ_LPR, cflag);
dport->cflag = cflag;
dport->port.read_status_mask = DZ_OERR;
if (termios->c_iflag & INPCK)
dport->port.read_status_mask |= DZ_FERR | DZ_PERR;
if (termios->c_iflag & (BRKINT | PARMRK))
dport->port.read_status_mask |= DZ_BREAK;
uport->ignore_status_mask = 0;
if ((termios->c_iflag & (IGNPAR | IGNBRK)) == (IGNPAR | IGNBRK))
dport->port.ignore_status_mask |= DZ_OERR;
if (termios->c_iflag & IGNPAR)
dport->port.ignore_status_mask |= DZ_FERR | DZ_PERR;
if (termios->c_iflag & IGNBRK)
dport->port.ignore_status_mask |= DZ_BREAK;
spin_unlock_irqrestore(&dport->port.lock, flags);
}
static void dz_pm(struct uart_port *uport, unsigned int state,
unsigned int oldstate)
{
struct dz_port *dport = to_dport(uport);
unsigned long flags;
spin_lock_irqsave(&dport->port.lock, flags);
if (state < 3)
dz_start_tx(&dport->port);
else
dz_stop_tx(&dport->port);
spin_unlock_irqrestore(&dport->port.lock, flags);
}
static const char *dz_type(struct uart_port *uport)
{
return "DZ";
}
static void dz_release_port(struct uart_port *uport)
{
struct dz_mux *mux = to_dport(uport)->mux;
int map_guard;
iounmap(uport->membase);
uport->membase = NULL;
map_guard = atomic_add_return(-1, &mux->map_guard);
if (!map_guard)
release_mem_region(uport->mapbase, dec_kn_slot_size);
}
static int dz_map_port(struct uart_port *uport)
{
if (!uport->membase)
uport->membase = ioremap_nocache(uport->mapbase,
dec_kn_slot_size);
if (!uport->membase) {
printk(KERN_ERR "dz: Cannot map MMIO\n");
return -ENOMEM;
}
return 0;
}
static int dz_request_port(struct uart_port *uport)
{
struct dz_mux *mux = to_dport(uport)->mux;
int map_guard;
int ret;
map_guard = atomic_add_return(1, &mux->map_guard);
if (map_guard == 1) {
if (!request_mem_region(uport->mapbase, dec_kn_slot_size,
"dz")) {
atomic_add(-1, &mux->map_guard);
printk(KERN_ERR
"dz: Unable to reserve MMIO resource\n");
return -EBUSY;
}
}
ret = dz_map_port(uport);
if (ret) {
map_guard = atomic_add_return(-1, &mux->map_guard);
if (!map_guard)
release_mem_region(uport->mapbase, dec_kn_slot_size);
return ret;
}
return 0;
}
static void dz_config_port(struct uart_port *uport, int flags)
{
struct dz_port *dport = to_dport(uport);
if (flags & UART_CONFIG_TYPE) {
if (dz_request_port(uport))
return;
uport->type = PORT_DZ;
dz_reset(dport);
}
}
static int dz_verify_port(struct uart_port *uport, struct serial_struct *ser)
{
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_DZ)
ret = -EINVAL;
if (ser->irq != uport->irq)
ret = -EINVAL;
return ret;
}
static void __init dz_init_ports(void)
{
static int first = 1;
unsigned long base;
int line;
if (!first)
return;
first = 0;
if (mips_machtype == MACH_DS23100 || mips_machtype == MACH_DS5100)
base = dec_kn_slot_base + KN01_DZ11;
else
base = dec_kn_slot_base + KN02_DZ11;
for (line = 0; line < DZ_NB_PORT; line++) {
struct dz_port *dport = &dz_mux.dport[line];
struct uart_port *uport = &dport->port;
dport->mux = &dz_mux;
uport->irq = dec_interrupt[DEC_IRQ_DZ11];
uport->fifosize = 1;
uport->iotype = UPIO_MEM;
uport->flags = UPF_BOOT_AUTOCONF;
uport->ops = &dz_ops;
uport->line = line;
uport->mapbase = base;
}
}
static void dz_console_putchar(struct uart_port *uport, int ch)
{
struct dz_port *dport = to_dport(uport);
unsigned long flags;
unsigned short csr, tcr, trdy, mask;
int loops = 10000;
spin_lock_irqsave(&dport->port.lock, flags);
csr = dz_in(dport, DZ_CSR);
dz_out(dport, DZ_CSR, csr & ~DZ_TIE);
tcr = dz_in(dport, DZ_TCR);
tcr |= 1 << dport->port.line;
mask = tcr;
dz_out(dport, DZ_TCR, mask);
iob();
spin_unlock_irqrestore(&dport->port.lock, flags);
do {
trdy = dz_in(dport, DZ_CSR);
if (!(trdy & DZ_TRDY))
continue;
trdy = (trdy & DZ_TLINE) >> 8;
if (trdy == dport->port.line)
break;
mask &= ~(1 << trdy);
dz_out(dport, DZ_TCR, mask);
iob();
udelay(2);
} while (--loops);
if (loops)
dz_out(dport, DZ_TDR, ch);
dz_out(dport, DZ_TCR, tcr);
dz_out(dport, DZ_CSR, csr);
}
static void dz_console_print(struct console *co,
const char *str,
unsigned int count)
{
struct dz_port *dport = &dz_mux.dport[co->index];
#ifdef DEBUG_DZ
prom_printf((char *) str);
#endif
uart_console_write(&dport->port, str, count, dz_console_putchar);
}
static int __init dz_console_setup(struct console *co, char *options)
{
struct dz_port *dport = &dz_mux.dport[co->index];
struct uart_port *uport = &dport->port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
int ret;
ret = dz_map_port(uport);
if (ret)
return ret;
spin_lock_init(&dport->port.lock);
dz_reset(dport);
dz_pm(uport, 0, -1);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&dport->port, co, baud, parity, bits, flow);
}
static int __init dz_serial_console_init(void)
{
if (!IOASIC) {
dz_init_ports();
register_console(&dz_console);
return 0;
} else
return -ENXIO;
}
static int __init dz_init(void)
{
int ret, i;
if (IOASIC)
return -ENXIO;
printk("%s%s\n", dz_name, dz_version);
dz_init_ports();
ret = uart_register_driver(&dz_reg);
if (ret)
return ret;
for (i = 0; i < DZ_NB_PORT; i++)
uart_add_one_port(&dz_reg, &dz_mux.dport[i].port);
return 0;
}
