static unsigned int serial_in(struct uart_sunsu_port *up, int offset)
{
offset <<= up->port.regshift;
switch (up->port.iotype) {
case UPIO_HUB6:
outb(up->port.hub6 - 1 + offset, up->port.iobase);
return inb(up->port.iobase + 1);
case UPIO_MEM:
return readb(up->port.membase + offset);
default:
return inb(up->port.iobase + offset);
}
}
static void serial_out(struct uart_sunsu_port *up, int offset, int value)
{
#ifndef CONFIG_SPARC64
if (offset == UART_MCR)
value |= UART_MCR_OUT2;
#endif
offset <<= up->port.regshift;
switch (up->port.iotype) {
case UPIO_HUB6:
outb(up->port.hub6 - 1 + offset, up->port.iobase);
outb(value, up->port.iobase + 1);
break;
case UPIO_MEM:
writeb(value, up->port.membase + offset);
break;
default:
outb(value, up->port.iobase + offset);
}
}
static void serial_icr_write(struct uart_sunsu_port *up, int offset, int value)
{
serial_out(up, UART_SCR, offset);
serial_out(up, UART_ICR, value);
}
static int __enable_rsa(struct uart_sunsu_port *up)
{
unsigned char mode;
int result;
mode = serial_inp(up, UART_RSA_MSR);
result = mode & UART_RSA_MSR_FIFO;
if (!result) {
serial_outp(up, UART_RSA_MSR, mode | UART_RSA_MSR_FIFO);
mode = serial_inp(up, UART_RSA_MSR);
result = mode & UART_RSA_MSR_FIFO;
}
if (result)
up->port.uartclk = SERIAL_RSA_BAUD_BASE * 16;
return result;
}
static void enable_rsa(struct uart_sunsu_port *up)
{
if (up->port.type == PORT_RSA) {
if (up->port.uartclk != SERIAL_RSA_BAUD_BASE * 16) {
spin_lock_irq(&up->port.lock);
__enable_rsa(up);
spin_unlock_irq(&up->port.lock);
}
if (up->port.uartclk == SERIAL_RSA_BAUD_BASE * 16)
serial_outp(up, UART_RSA_FRR, 0);
}
}
static void disable_rsa(struct uart_sunsu_port *up)
{
unsigned char mode;
int result;
if (up->port.type == PORT_RSA &&
up->port.uartclk == SERIAL_RSA_BAUD_BASE * 16) {
spin_lock_irq(&up->port.lock);
mode = serial_inp(up, UART_RSA_MSR);
result = !(mode & UART_RSA_MSR_FIFO);
if (!result) {
serial_outp(up, UART_RSA_MSR, mode & ~UART_RSA_MSR_FIFO);
mode = serial_inp(up, UART_RSA_MSR);
result = !(mode & UART_RSA_MSR_FIFO);
}
if (result)
up->port.uartclk = SERIAL_RSA_BAUD_BASE_LO * 16;
spin_unlock_irq(&up->port.lock);
}
}
static inline void __stop_tx(struct uart_sunsu_port *p)
{
if (p->ier & UART_IER_THRI) {
p->ier &= ~UART_IER_THRI;
serial_out(p, UART_IER, p->ier);
}
}
static void sunsu_stop_tx(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
__stop_tx(up);
if (up->port.type == PORT_16C950) {
up->acr |= UART_ACR_TXDIS;
serial_icr_write(up, UART_ACR, up->acr);
}
}
static void sunsu_start_tx(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
if (!(up->ier & UART_IER_THRI)) {
up->ier |= UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
if (up->port.type == PORT_16C950 && up->acr & UART_ACR_TXDIS) {
up->acr &= ~UART_ACR_TXDIS;
serial_icr_write(up, UART_ACR, up->acr);
}
}
static void sunsu_stop_rx(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
up->ier &= ~UART_IER_RLSI;
up->port.read_status_mask &= ~UART_LSR_DR;
serial_out(up, UART_IER, up->ier);
}
static void sunsu_enable_ms(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
receive_chars(struct uart_sunsu_port *up, unsigned char *status)
{
struct tty_port *port = &up->port.state->port;
unsigned char ch, flag;
int max_count = 256;
int saw_console_brk = 0;
do {
ch = serial_inp(up, UART_RX);
flag = TTY_NORMAL;
up->port.icount.rx++;
if (unlikely(*status & (UART_LSR_BI | UART_LSR_PE |
UART_LSR_FE | UART_LSR_OE))) {
if (*status & UART_LSR_BI) {
*status &= ~(UART_LSR_FE | UART_LSR_PE);
up->port.icount.brk++;
if (up->port.cons != NULL &&
up->port.line == up->port.cons->index)
saw_console_brk = 1;
if (uart_handle_break(&up->port))
goto ignore_char;
} else if (*status & UART_LSR_PE)
up->port.icount.parity++;
else if (*status & UART_LSR_FE)
up->port.icount.frame++;
if (*status & UART_LSR_OE)
up->port.icount.overrun++;
*status &= up->port.read_status_mask;
if (up->port.cons != NULL &&
up->port.line == up->port.cons->index) {
*status |= up->lsr_break_flag;
up->lsr_break_flag = 0;
}
if (*status & UART_LSR_BI) {
flag = TTY_BREAK;
} else if (*status & UART_LSR_PE)
flag = TTY_PARITY;
else if (*status & UART_LSR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&up->port, ch))
goto ignore_char;
if ((*status & up->port.ignore_status_mask) == 0)
tty_insert_flip_char(port, ch, flag);
if (*status & UART_LSR_OE)
tty_insert_flip_char(port, 0, TTY_OVERRUN);
ignore_char:
*status = serial_inp(up, UART_LSR);
} while ((*status & UART_LSR_DR) && (max_count-- > 0));
if (saw_console_brk)
sun_do_break();
}
static void transmit_chars(struct uart_sunsu_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
int count;
if (up->port.x_char) {
serial_outp(up, UART_TX, up->port.x_char);
up->port.icount.tx++;
up->port.x_char = 0;
return;
}
if (uart_tx_stopped(&up->port)) {
sunsu_stop_tx(&up->port);
return;
}
if (uart_circ_empty(xmit)) {
__stop_tx(up);
return;
}
count = up->port.fifosize;
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
__stop_tx(up);
}
static void check_modem_status(struct uart_sunsu_port *up)
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
static irqreturn_t sunsu_serial_interrupt(int irq, void *dev_id)
{
struct uart_sunsu_port *up = dev_id;
unsigned long flags;
unsigned char status;
spin_lock_irqsave(&up->port.lock, flags);
do {
status = serial_inp(up, UART_LSR);
if (status & UART_LSR_DR)
receive_chars(up, &status);
check_modem_status(up);
if (status & UART_LSR_THRE)
transmit_chars(up);
spin_unlock_irqrestore(&up->port.lock, flags);
tty_flip_buffer_push(&up->port.state->port);
spin_lock_irqsave(&up->port.lock, flags);
} while (!(serial_in(up, UART_IIR) & UART_IIR_NO_INT));
spin_unlock_irqrestore(&up->port.lock, flags);
return IRQ_HANDLED;
}
static void sunsu_change_mouse_baud(struct uart_sunsu_port *up)
{
unsigned int cur_cflag = up->cflag;
int quot, new_baud;
up->cflag &= ~CBAUD;
up->cflag |= suncore_mouse_baud_cflag_next(cur_cflag, &new_baud);
quot = up->port.uartclk / (16 * new_baud);
sunsu_change_speed(&up->port, up->cflag, 0, quot);
}
static void receive_kbd_ms_chars(struct uart_sunsu_port *up, int is_break)
{
do {
unsigned char ch = serial_inp(up, UART_RX);
if (up->su_type == SU_PORT_KBD) {
#ifdef CONFIG_SERIO
serio_interrupt(&up->serio, ch, 0);
#endif
} else if (up->su_type == SU_PORT_MS) {
int ret = suncore_mouse_baud_detection(ch, is_break);
switch (ret) {
case 2:
sunsu_change_mouse_baud(up);
case 1:
break;
case 0:
#ifdef CONFIG_SERIO
serio_interrupt(&up->serio, ch, 0);
#endif
break;
};
}
} while (serial_in(up, UART_LSR) & UART_LSR_DR);
}
static irqreturn_t sunsu_kbd_ms_interrupt(int irq, void *dev_id)
{
struct uart_sunsu_port *up = dev_id;
if (!(serial_in(up, UART_IIR) & UART_IIR_NO_INT)) {
unsigned char status = serial_inp(up, UART_LSR);
if ((status & UART_LSR_DR) || (status & UART_LSR_BI))
receive_kbd_ms_chars(up, (status & UART_LSR_BI) != 0);
}
return IRQ_HANDLED;
}
static unsigned int sunsu_tx_empty(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
unsigned long flags;
unsigned int ret;
spin_lock_irqsave(&up->port.lock, flags);
ret = serial_in(up, UART_LSR) & UART_LSR_TEMT ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
return ret;
}
static unsigned int sunsu_get_mctrl(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
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
static void sunsu_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
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
serial_out(up, UART_MCR, mcr);
}
static void sunsu_break_ctl(struct uart_port *port, int break_state)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
up->lcr |= UART_LCR_SBC;
else
up->lcr &= ~UART_LCR_SBC;
serial_out(up, UART_LCR, up->lcr);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int sunsu_startup(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
unsigned long flags;
int retval;
if (up->port.type == PORT_16C950) {
up->acr = 0;
serial_outp(up, UART_LCR, 0xBF);
serial_outp(up, UART_EFR, UART_EFR_ECB);
serial_outp(up, UART_IER, 0);
serial_outp(up, UART_LCR, 0);
serial_icr_write(up, UART_CSR, 0);
serial_outp(up, UART_LCR, 0xBF);
serial_outp(up, UART_EFR, UART_EFR_ECB);
serial_outp(up, UART_LCR, 0);
}
#ifdef CONFIG_SERIAL_8250_RSA
enable_rsa(up);
#endif
if (uart_config[up->port.type].flags & UART_CLEAR_FIFO) {
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_outp(up, UART_FCR, 0);
}
(void) serial_inp(up, UART_LSR);
(void) serial_inp(up, UART_RX);
(void) serial_inp(up, UART_IIR);
(void) serial_inp(up, UART_MSR);
if (!(up->port.flags & UPF_BUGGY_UART) &&
(serial_inp(up, UART_LSR) == 0xff)) {
printk("ttyS%d: LSR safety check engaged!\n", up->port.line);
return -ENODEV;
}
if (up->su_type != SU_PORT_PORT) {
retval = request_irq(up->port.irq, sunsu_kbd_ms_interrupt,
IRQF_SHARED, su_typev[up->su_type], up);
} else {
retval = request_irq(up->port.irq, sunsu_serial_interrupt,
IRQF_SHARED, su_typev[up->su_type], up);
}
if (retval) {
printk("su: Cannot register IRQ %d\n", up->port.irq);
return retval;
}
serial_outp(up, UART_LCR, UART_LCR_WLEN8);
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl |= TIOCM_OUT2;
sunsu_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
up->ier = UART_IER_RLSI | UART_IER_RDI;
serial_outp(up, UART_IER, up->ier);
if (up->port.flags & UPF_FOURPORT) {
unsigned int icp;
icp = (up->port.iobase & 0xfe0) | 0x01f;
outb_p(0x80, icp);
(void) inb_p(icp);
}
(void) serial_inp(up, UART_LSR);
(void) serial_inp(up, UART_RX);
(void) serial_inp(up, UART_IIR);
(void) serial_inp(up, UART_MSR);
return 0;
}
static void sunsu_shutdown(struct uart_port *port)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
unsigned long flags;
up->ier = 0;
serial_outp(up, UART_IER, 0);
spin_lock_irqsave(&up->port.lock, flags);
if (up->port.flags & UPF_FOURPORT) {
inb((up->port.iobase & 0xfe0) | 0x1f);
up->port.mctrl |= TIOCM_OUT1;
} else
up->port.mctrl &= ~TIOCM_OUT2;
sunsu_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
serial_out(up, UART_LCR, serial_inp(up, UART_LCR) & ~UART_LCR_SBC);
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR |
UART_FCR_CLEAR_XMIT);
serial_outp(up, UART_FCR, 0);
#ifdef CONFIG_SERIAL_8250_RSA
disable_rsa(up);
#endif
(void) serial_in(up, UART_RX);
free_irq(up->port.irq, up);
}
static void
sunsu_change_speed(struct uart_port *port, unsigned int cflag,
unsigned int iflag, unsigned int quot)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
unsigned char cval, fcr = 0;
unsigned long flags;
switch (cflag & CSIZE) {
case CS5:
cval = 0x00;
break;
case CS6:
cval = 0x01;
break;
case CS7:
cval = 0x02;
break;
default:
case CS8:
cval = 0x03;
break;
}
if (cflag & CSTOPB)
cval |= 0x04;
if (cflag & PARENB)
cval |= UART_LCR_PARITY;
if (!(cflag & PARODD))
cval |= UART_LCR_EPAR;
#ifdef CMSPAR
if (cflag & CMSPAR)
cval |= UART_LCR_SPAR;
#endif
if ((quot & 0xff) == 0 && up->port.type == PORT_16C950 &&
up->rev == 0x5201)
quot ++;
if (uart_config[up->port.type].flags & UART_USE_FIFO) {
if ((up->port.uartclk / quot) < (2400 * 16))
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_TRIGGER_1;
#ifdef CONFIG_SERIAL_8250_RSA
else if (up->port.type == PORT_RSA)
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_TRIGGER_14;
#endif
else
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_TRIGGER_8;
}
if (up->port.type == PORT_16750)
fcr |= UART_FCR7_64BYTE;
spin_lock_irqsave(&up->port.lock, flags);
uart_update_timeout(port, cflag, (port->uartclk / (16 * quot)));
up->port.read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (iflag & INPCK)
up->port.read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (iflag & (BRKINT | PARMRK))
up->port.read_status_mask |= UART_LSR_BI;
up->port.ignore_status_mask = 0;
if (iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (iflag & IGNBRK) {
up->port.ignore_status_mask |= UART_LSR_BI;
if (iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_OE;
}
if ((cflag & CREAD) == 0)
up->port.ignore_status_mask |= UART_LSR_DR;
up->ier &= ~UART_IER_MSI;
if (UART_ENABLE_MS(&up->port, cflag))
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
if (uart_config[up->port.type].flags & UART_STARTECH) {
serial_outp(up, UART_LCR, 0xBF);
serial_outp(up, UART_EFR, cflag & CRTSCTS ? UART_EFR_CTS :0);
}
serial_outp(up, UART_LCR, cval | UART_LCR_DLAB);
serial_outp(up, UART_DLL, quot & 0xff);
serial_outp(up, UART_DLM, quot >> 8);
if (up->port.type == PORT_16750)
serial_outp(up, UART_FCR, fcr);
serial_outp(up, UART_LCR, cval);
up->lcr = cval;
if (up->port.type != PORT_16750) {
if (fcr & UART_FCR_ENABLE_FIFO) {
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO);
}
serial_outp(up, UART_FCR, fcr);
}
up->cflag = cflag;
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
sunsu_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud, quot;
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
quot = uart_get_divisor(port, baud);
sunsu_change_speed(port, termios->c_cflag, termios->c_iflag, quot);
}
static void sunsu_release_port(struct uart_port *port)
{
}
static int sunsu_request_port(struct uart_port *port)
{
return 0;
}
static void sunsu_config_port(struct uart_port *port, int flags)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *) port;
if (flags & UART_CONFIG_TYPE) {
port->type = up->type_probed;
}
}
static int
sunsu_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static const char *
sunsu_type(struct uart_port *port)
{
int type = port->type;
if (type >= ARRAY_SIZE(uart_config))
type = 0;
return uart_config[type].name;
}
static int sunsu_serio_write(struct serio *serio, unsigned char ch)
{
struct uart_sunsu_port *up = serio->port_data;
unsigned long flags;
int lsr;
spin_lock_irqsave(&sunsu_serio_lock, flags);
do {
lsr = serial_in(up, UART_LSR);
} while (!(lsr & UART_LSR_THRE));
serial_out(up, UART_TX, ch);
spin_unlock_irqrestore(&sunsu_serio_lock, flags);
return 0;
}
static int sunsu_serio_open(struct serio *serio)
{
struct uart_sunsu_port *up = serio->port_data;
unsigned long flags;
int ret;
spin_lock_irqsave(&sunsu_serio_lock, flags);
if (!up->serio_open) {
up->serio_open = 1;
ret = 0;
} else
ret = -EBUSY;
spin_unlock_irqrestore(&sunsu_serio_lock, flags);
return ret;
}
static void sunsu_serio_close(struct serio *serio)
{
struct uart_sunsu_port *up = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&sunsu_serio_lock, flags);
up->serio_open = 0;
spin_unlock_irqrestore(&sunsu_serio_lock, flags);
}
static void sunsu_autoconfig(struct uart_sunsu_port *up)
{
unsigned char status1, status2, scratch, scratch2, scratch3;
unsigned char save_lcr, save_mcr;
unsigned long flags;
if (up->su_type == SU_PORT_NONE)
return;
up->type_probed = PORT_UNKNOWN;
up->port.iotype = UPIO_MEM;
spin_lock_irqsave(&up->port.lock, flags);
if (!(up->port.flags & UPF_BUGGY_UART)) {
scratch = serial_inp(up, UART_IER);
serial_outp(up, UART_IER, 0);
#ifdef __i386__
outb(0xff, 0x080);
#endif
scratch2 = serial_inp(up, UART_IER);
serial_outp(up, UART_IER, 0x0f);
#ifdef __i386__
outb(0, 0x080);
#endif
scratch3 = serial_inp(up, UART_IER);
serial_outp(up, UART_IER, scratch);
if (scratch2 != 0 || scratch3 != 0x0F)
goto out;
}
save_mcr = serial_in(up, UART_MCR);
save_lcr = serial_in(up, UART_LCR);
if (!(up->port.flags & UPF_SKIP_TEST)) {
serial_outp(up, UART_MCR, UART_MCR_LOOP | 0x0A);
status1 = serial_inp(up, UART_MSR) & 0xF0;
serial_outp(up, UART_MCR, save_mcr);
if (status1 != 0x90)
goto out;
}
serial_outp(up, UART_LCR, 0xBF);
serial_outp(up, UART_EFR, 0);
serial_outp(up, UART_LCR, 0);
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO);
scratch = serial_in(up, UART_IIR) >> 6;
switch (scratch) {
case 0:
up->port.type = PORT_16450;
break;
case 1:
up->port.type = PORT_UNKNOWN;
break;
case 2:
up->port.type = PORT_16550;
break;
case 3:
up->port.type = PORT_16550A;
break;
}
if (up->port.type == PORT_16550A) {
serial_outp(up, UART_LCR, UART_LCR_DLAB);
if (serial_in(up, UART_EFR) == 0) {
up->port.type = PORT_16650;
} else {
serial_outp(up, UART_LCR, 0xBF);
if (serial_in(up, UART_EFR) == 0)
up->port.type = PORT_16650V2;
}
}
if (up->port.type == PORT_16550A) {
serial_outp(up, UART_LCR, save_lcr | UART_LCR_DLAB);
serial_outp(up, UART_FCR,
UART_FCR_ENABLE_FIFO | UART_FCR7_64BYTE);
scratch = serial_in(up, UART_IIR) >> 5;
if (scratch == 7) {
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_outp(up, UART_LCR, 0);
serial_outp(up, UART_FCR,
UART_FCR_ENABLE_FIFO | UART_FCR7_64BYTE);
scratch = serial_in(up, UART_IIR) >> 5;
if (scratch == 6)
up->port.type = PORT_16750;
}
serial_outp(up, UART_FCR, UART_FCR_ENABLE_FIFO);
}
serial_outp(up, UART_LCR, save_lcr);
if (up->port.type == PORT_16450) {
scratch = serial_in(up, UART_SCR);
serial_outp(up, UART_SCR, 0xa5);
status1 = serial_in(up, UART_SCR);
serial_outp(up, UART_SCR, 0x5a);
status2 = serial_in(up, UART_SCR);
serial_outp(up, UART_SCR, scratch);
if ((status1 != 0xa5) || (status2 != 0x5a))
up->port.type = PORT_8250;
}
up->port.fifosize = uart_config[up->port.type].dfl_xmit_fifo_size;
if (up->port.type == PORT_UNKNOWN)
goto out;
up->type_probed = up->port.type;
#ifdef CONFIG_SERIAL_8250_RSA
if (up->port.type == PORT_RSA)
serial_outp(up, UART_RSA_FRR, 0);
#endif
serial_outp(up, UART_MCR, save_mcr);
serial_outp(up, UART_FCR, (UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR |
UART_FCR_CLEAR_XMIT));
serial_outp(up, UART_FCR, 0);
(void)serial_in(up, UART_RX);
serial_outp(up, UART_IER, 0);
out:
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int sunsu_kbd_ms_init(struct uart_sunsu_port *up)
{
int quot, baud;
#ifdef CONFIG_SERIO
struct serio *serio;
#endif
if (up->su_type == SU_PORT_KBD) {
up->cflag = B1200 | CS8 | CLOCAL | CREAD;
baud = 1200;
} else {
up->cflag = B4800 | CS8 | CLOCAL | CREAD;
baud = 4800;
}
quot = up->port.uartclk / (16 * baud);
sunsu_autoconfig(up);
if (up->port.type == PORT_UNKNOWN)
return -ENODEV;
printk("%s: %s port at %llx, irq %u\n",
up->port.dev->of_node->full_name,
(up->su_type == SU_PORT_KBD) ? "Keyboard" : "Mouse",
(unsigned long long) up->port.mapbase,
up->port.irq);
#ifdef CONFIG_SERIO
serio = &up->serio;
serio->port_data = up;
serio->id.type = SERIO_RS232;
if (up->su_type == SU_PORT_KBD) {
serio->id.proto = SERIO_SUNKBD;
strlcpy(serio->name, "sukbd", sizeof(serio->name));
} else {
serio->id.proto = SERIO_SUN;
serio->id.extra = 1;
strlcpy(serio->name, "sums", sizeof(serio->name));
}
strlcpy(serio->phys,
(!(up->port.line & 1) ? "su/serio0" : "su/serio1"),
sizeof(serio->phys));
serio->write = sunsu_serio_write;
serio->open = sunsu_serio_open;
serio->close = sunsu_serio_close;
serio->dev.parent = up->port.dev;
serio_register_port(serio);
#endif
sunsu_change_speed(&up->port, up->cflag, 0, quot);
sunsu_startup(&up->port);
return 0;
}
static __inline__ void wait_for_xmitr(struct uart_sunsu_port *up)
{
unsigned int status, tmout = 10000;
do {
status = serial_in(up, UART_LSR);
if (status & UART_LSR_BI)
up->lsr_break_flag = UART_LSR_BI;
if (--tmout == 0)
break;
udelay(1);
} while ((status & BOTH_EMPTY) != BOTH_EMPTY);
if (up->port.flags & UPF_CONS_FLOW) {
tmout = 1000000;
while (--tmout &&
((serial_in(up, UART_MSR) & UART_MSR_CTS) == 0))
udelay(1);
}
}
static void sunsu_console_putchar(struct uart_port *port, int ch)
{
struct uart_sunsu_port *up = (struct uart_sunsu_port *)port;
wait_for_xmitr(up);
serial_out(up, UART_TX, ch);
}
static void sunsu_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_sunsu_port *up = &sunsu_ports[co->index];
unsigned long flags;
unsigned int ier;
int locked = 1;
local_irq_save(flags);
if (up->port.sysrq) {
locked = 0;
} else if (oops_in_progress) {
locked = spin_trylock(&up->port.lock);
} else
spin_lock(&up->port.lock);
ier = serial_in(up, UART_IER);
serial_out(up, UART_IER, 0);
uart_console_write(&up->port, s, count, sunsu_console_putchar);
wait_for_xmitr(up);
serial_out(up, UART_IER, ier);
if (locked)
spin_unlock(&up->port.lock);
local_irq_restore(flags);
}
static int __init sunsu_console_setup(struct console *co, char *options)
{
static struct ktermios dummy;
struct ktermios termios;
struct uart_port *port;
printk("Console: ttyS%d (SU)\n",
(sunsu_reg.minor - 64) + co->index);
if (co->index > nr_inst)
return -ENODEV;
port = &sunsu_ports[co->index].port;
spin_lock_init(&port->lock);
sunserial_console_termios(co, port->dev->of_node);
memset(&termios, 0, sizeof(struct ktermios));
termios.c_cflag = co->cflag;
port->mctrl |= TIOCM_DTR;
port->ops->set_termios(port, &termios, &dummy);
return 0;
}
static inline struct console *SUNSU_CONSOLE(void)
{
return &sunsu_console;
}
static enum su_type su_get_type(struct device_node *dp)
{
struct device_node *ap = of_find_node_by_path("/aliases");
if (ap) {
const char *keyb = of_get_property(ap, "keyboard", NULL);
const char *ms = of_get_property(ap, "mouse", NULL);
if (keyb) {
if (dp == of_find_node_by_path(keyb))
return SU_PORT_KBD;
}
if (ms) {
if (dp == of_find_node_by_path(ms))
return SU_PORT_MS;
}
}
return SU_PORT_PORT;
}
static int su_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct uart_sunsu_port *up;
struct resource *rp;
enum su_type type;
bool ignore_line;
int err;
type = su_get_type(dp);
if (type == SU_PORT_PORT) {
if (nr_inst >= UART_NR)
return -EINVAL;
up = &sunsu_ports[nr_inst];
} else {
up = kzalloc(sizeof(*up), GFP_KERNEL);
if (!up)
return -ENOMEM;
}
up->port.line = nr_inst;
spin_lock_init(&up->port.lock);
up->su_type = type;
rp = &op->resource[0];
up->port.mapbase = rp->start;
up->reg_size = resource_size(rp);
up->port.membase = of_ioremap(rp, 0, up->reg_size, "su");
if (!up->port.membase) {
if (type != SU_PORT_PORT)
kfree(up);
return -ENOMEM;
}
up->port.irq = op->archdata.irqs[0];
up->port.dev = &op->dev;
up->port.type = PORT_UNKNOWN;
up->port.uartclk = (SU_BASE_BAUD * 16);
err = 0;
if (up->su_type == SU_PORT_KBD || up->su_type == SU_PORT_MS) {
err = sunsu_kbd_ms_init(up);
if (err) {
of_iounmap(&op->resource[0],
up->port.membase, up->reg_size);
kfree(up);
return err;
}
platform_set_drvdata(op, up);
nr_inst++;
return 0;
}
up->port.flags |= UPF_BOOT_AUTOCONF;
sunsu_autoconfig(up);
err = -ENODEV;
if (up->port.type == PORT_UNKNOWN)
goto out_unmap;
up->port.ops = &sunsu_pops;
ignore_line = false;
if (!strcmp(dp->name, "rsc-console") ||
!strcmp(dp->name, "lom-console"))
ignore_line = true;
sunserial_console_match(SUNSU_CONSOLE(), dp,
&sunsu_reg, up->port.line,
ignore_line);
err = uart_add_one_port(&sunsu_reg, &up->port);
if (err)
goto out_unmap;
platform_set_drvdata(op, up);
nr_inst++;
return 0;
out_unmap:
of_iounmap(&op->resource[0], up->port.membase, up->reg_size);
return err;
}
static int su_remove(struct platform_device *op)
{
struct uart_sunsu_port *up = platform_get_drvdata(op);
bool kbdms = false;
if (up->su_type == SU_PORT_MS ||
up->su_type == SU_PORT_KBD)
kbdms = true;
if (kbdms) {
#ifdef CONFIG_SERIO
serio_unregister_port(&up->serio);
#endif
} else if (up->port.type != PORT_UNKNOWN)
uart_remove_one_port(&sunsu_reg, &up->port);
if (up->port.membase)
of_iounmap(&op->resource[0], up->port.membase, up->reg_size);
if (kbdms)
kfree(up);
return 0;
}
static int __init sunsu_init(void)
{
struct device_node *dp;
int err;
int num_uart = 0;
for_each_node_by_name(dp, "su") {
if (su_get_type(dp) == SU_PORT_PORT)
num_uart++;
}
for_each_node_by_name(dp, "su_pnp") {
if (su_get_type(dp) == SU_PORT_PORT)
num_uart++;
}
for_each_node_by_name(dp, "serial") {
if (of_device_is_compatible(dp, "su")) {
if (su_get_type(dp) == SU_PORT_PORT)
num_uart++;
}
}
for_each_node_by_type(dp, "serial") {
if (of_device_is_compatible(dp, "su")) {
if (su_get_type(dp) == SU_PORT_PORT)
num_uart++;
}
}
if (num_uart) {
err = sunserial_register_minors(&sunsu_reg, num_uart);
if (err)
return err;
}
err = platform_driver_register(&su_driver);
if (err && num_uart)
sunserial_unregister_minors(&sunsu_reg, num_uart);
return err;
}
static void __exit sunsu_exit(void)
{
platform_driver_unregister(&su_driver);
if (sunsu_reg.nr)
sunserial_unregister_minors(&sunsu_reg, sunsu_reg.nr);
}
