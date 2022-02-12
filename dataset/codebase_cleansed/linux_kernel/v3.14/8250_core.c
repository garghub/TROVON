static int serial_index(struct uart_port *port)
{
return (serial8250_reg.minor - 64) + port->line;
}
static int default_serial_dl_read(struct uart_8250_port *up)
{
return serial_in(up, UART_DLL) | serial_in(up, UART_DLM) << 8;
}
static void default_serial_dl_write(struct uart_8250_port *up, int value)
{
serial_out(up, UART_DLL, value & 0xff);
serial_out(up, UART_DLM, value >> 8 & 0xff);
}
static unsigned int au_serial_in(struct uart_port *p, int offset)
{
offset = au_io_in_map[offset] << p->regshift;
return __raw_readl(p->membase + offset);
}
static void au_serial_out(struct uart_port *p, int offset, int value)
{
offset = au_io_out_map[offset] << p->regshift;
__raw_writel(value, p->membase + offset);
}
static int au_serial_dl_read(struct uart_8250_port *up)
{
return __raw_readl(up->port.membase + 0x28);
}
static void au_serial_dl_write(struct uart_8250_port *up, int value)
{
__raw_writel(value, up->port.membase + 0x28);
}
static unsigned int hub6_serial_in(struct uart_port *p, int offset)
{
offset = offset << p->regshift;
outb(p->hub6 - 1 + offset, p->iobase);
return inb(p->iobase + 1);
}
static void hub6_serial_out(struct uart_port *p, int offset, int value)
{
offset = offset << p->regshift;
outb(p->hub6 - 1 + offset, p->iobase);
outb(value, p->iobase + 1);
}
static unsigned int mem_serial_in(struct uart_port *p, int offset)
{
offset = offset << p->regshift;
return readb(p->membase + offset);
}
static void mem_serial_out(struct uart_port *p, int offset, int value)
{
offset = offset << p->regshift;
writeb(value, p->membase + offset);
}
static void mem32_serial_out(struct uart_port *p, int offset, int value)
{
offset = offset << p->regshift;
writel(value, p->membase + offset);
}
static unsigned int mem32_serial_in(struct uart_port *p, int offset)
{
offset = offset << p->regshift;
return readl(p->membase + offset);
}
static unsigned int io_serial_in(struct uart_port *p, int offset)
{
offset = offset << p->regshift;
return inb(p->iobase + offset);
}
static void io_serial_out(struct uart_port *p, int offset, int value)
{
offset = offset << p->regshift;
outb(value, p->iobase + offset);
}
static void set_io_from_upio(struct uart_port *p)
{
struct uart_8250_port *up =
container_of(p, struct uart_8250_port, port);
up->dl_read = default_serial_dl_read;
up->dl_write = default_serial_dl_write;
switch (p->iotype) {
case UPIO_HUB6:
p->serial_in = hub6_serial_in;
p->serial_out = hub6_serial_out;
break;
case UPIO_MEM:
p->serial_in = mem_serial_in;
p->serial_out = mem_serial_out;
break;
case UPIO_MEM32:
p->serial_in = mem32_serial_in;
p->serial_out = mem32_serial_out;
break;
#if defined(CONFIG_MIPS_ALCHEMY) || defined(CONFIG_SERIAL_8250_RT288X)
case UPIO_AU:
p->serial_in = au_serial_in;
p->serial_out = au_serial_out;
up->dl_read = au_serial_dl_read;
up->dl_write = au_serial_dl_write;
break;
#endif
default:
p->serial_in = io_serial_in;
p->serial_out = io_serial_out;
break;
}
up->cur_iotype = p->iotype;
p->handle_irq = serial8250_default_handle_irq;
}
static void
serial_port_out_sync(struct uart_port *p, int offset, int value)
{
switch (p->iotype) {
case UPIO_MEM:
case UPIO_MEM32:
case UPIO_AU:
p->serial_out(p, offset, value);
p->serial_in(p, UART_LCR);
break;
default:
p->serial_out(p, offset, value);
}
}
static void serial_icr_write(struct uart_8250_port *up, int offset, int value)
{
serial_out(up, UART_SCR, offset);
serial_out(up, UART_ICR, value);
}
static unsigned int serial_icr_read(struct uart_8250_port *up, int offset)
{
unsigned int value;
serial_icr_write(up, UART_ACR, up->acr | UART_ACR_ICRRD);
serial_out(up, UART_SCR, offset);
value = serial_in(up, UART_ICR);
serial_icr_write(up, UART_ACR, up->acr);
return value;
}
static void serial8250_clear_fifos(struct uart_8250_port *p)
{
if (p->capabilities & UART_CAP_FIFO) {
serial_out(p, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_out(p, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_out(p, UART_FCR, 0);
}
}
void serial8250_clear_and_reinit_fifos(struct uart_8250_port *p)
{
unsigned char fcr;
serial8250_clear_fifos(p);
fcr = uart_config[p->port.type].fcr;
serial_out(p, UART_FCR, fcr);
}
static void serial8250_set_sleep(struct uart_8250_port *p, int sleep)
{
if ((p->port.type == PORT_XR17V35X) ||
(p->port.type == PORT_XR17D15X)) {
serial_out(p, UART_EXAR_SLEEP, 0xff);
return;
}
if (p->capabilities & UART_CAP_SLEEP) {
if (p->capabilities & UART_CAP_EFR) {
serial_out(p, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(p, UART_EFR, UART_EFR_ECB);
serial_out(p, UART_LCR, 0);
}
serial_out(p, UART_IER, sleep ? UART_IERX_SLEEP : 0);
if (p->capabilities & UART_CAP_EFR) {
serial_out(p, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(p, UART_EFR, 0);
serial_out(p, UART_LCR, 0);
}
}
}
static int __enable_rsa(struct uart_8250_port *up)
{
unsigned char mode;
int result;
mode = serial_in(up, UART_RSA_MSR);
result = mode & UART_RSA_MSR_FIFO;
if (!result) {
serial_out(up, UART_RSA_MSR, mode | UART_RSA_MSR_FIFO);
mode = serial_in(up, UART_RSA_MSR);
result = mode & UART_RSA_MSR_FIFO;
}
if (result)
up->port.uartclk = SERIAL_RSA_BAUD_BASE * 16;
return result;
}
static void enable_rsa(struct uart_8250_port *up)
{
if (up->port.type == PORT_RSA) {
if (up->port.uartclk != SERIAL_RSA_BAUD_BASE * 16) {
spin_lock_irq(&up->port.lock);
__enable_rsa(up);
spin_unlock_irq(&up->port.lock);
}
if (up->port.uartclk == SERIAL_RSA_BAUD_BASE * 16)
serial_out(up, UART_RSA_FRR, 0);
}
}
static void disable_rsa(struct uart_8250_port *up)
{
unsigned char mode;
int result;
if (up->port.type == PORT_RSA &&
up->port.uartclk == SERIAL_RSA_BAUD_BASE * 16) {
spin_lock_irq(&up->port.lock);
mode = serial_in(up, UART_RSA_MSR);
result = !(mode & UART_RSA_MSR_FIFO);
if (!result) {
serial_out(up, UART_RSA_MSR, mode & ~UART_RSA_MSR_FIFO);
mode = serial_in(up, UART_RSA_MSR);
result = !(mode & UART_RSA_MSR_FIFO);
}
if (result)
up->port.uartclk = SERIAL_RSA_BAUD_BASE_LO * 16;
spin_unlock_irq(&up->port.lock);
}
}
static int size_fifo(struct uart_8250_port *up)
{
unsigned char old_fcr, old_mcr, old_lcr;
unsigned short old_dl;
int count;
old_lcr = serial_in(up, UART_LCR);
serial_out(up, UART_LCR, 0);
old_fcr = serial_in(up, UART_FCR);
old_mcr = serial_in(up, UART_MCR);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_out(up, UART_MCR, UART_MCR_LOOP);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
old_dl = serial_dl_read(up);
serial_dl_write(up, 0x0001);
serial_out(up, UART_LCR, 0x03);
for (count = 0; count < 256; count++)
serial_out(up, UART_TX, count);
mdelay(20);
for (count = 0; (serial_in(up, UART_LSR) & UART_LSR_DR) &&
(count < 256); count++)
serial_in(up, UART_RX);
serial_out(up, UART_FCR, old_fcr);
serial_out(up, UART_MCR, old_mcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_dl_write(up, old_dl);
serial_out(up, UART_LCR, old_lcr);
return count;
}
static unsigned int autoconfig_read_divisor_id(struct uart_8250_port *p)
{
unsigned char old_dll, old_dlm, old_lcr;
unsigned int id;
old_lcr = serial_in(p, UART_LCR);
serial_out(p, UART_LCR, UART_LCR_CONF_MODE_A);
old_dll = serial_in(p, UART_DLL);
old_dlm = serial_in(p, UART_DLM);
serial_out(p, UART_DLL, 0);
serial_out(p, UART_DLM, 0);
id = serial_in(p, UART_DLL) | serial_in(p, UART_DLM) << 8;
serial_out(p, UART_DLL, old_dll);
serial_out(p, UART_DLM, old_dlm);
serial_out(p, UART_LCR, old_lcr);
return id;
}
static void autoconfig_has_efr(struct uart_8250_port *up)
{
unsigned int id1, id2, id3, rev;
up->capabilities |= UART_CAP_EFR | UART_CAP_SLEEP;
up->acr = 0;
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, UART_EFR_ECB);
serial_out(up, UART_LCR, 0x00);
id1 = serial_icr_read(up, UART_ID1);
id2 = serial_icr_read(up, UART_ID2);
id3 = serial_icr_read(up, UART_ID3);
rev = serial_icr_read(up, UART_REV);
DEBUG_AUTOCONF("950id=%02x:%02x:%02x:%02x ", id1, id2, id3, rev);
if (id1 == 0x16 && id2 == 0xC9 &&
(id3 == 0x50 || id3 == 0x52 || id3 == 0x54)) {
up->port.type = PORT_16C950;
if (id3 == 0x52 && rev == 0x01)
up->bugs |= UART_BUG_QUOT;
return;
}
id1 = autoconfig_read_divisor_id(up);
DEBUG_AUTOCONF("850id=%04x ", id1);
id2 = id1 >> 8;
if (id2 == 0x10 || id2 == 0x12 || id2 == 0x14) {
up->port.type = PORT_16850;
return;
}
if (size_fifo(up) == 64)
up->port.type = PORT_16654;
else
up->port.type = PORT_16650V2;
}
static void autoconfig_8250(struct uart_8250_port *up)
{
unsigned char scratch, status1, status2;
up->port.type = PORT_8250;
scratch = serial_in(up, UART_SCR);
serial_out(up, UART_SCR, 0xa5);
status1 = serial_in(up, UART_SCR);
serial_out(up, UART_SCR, 0x5a);
status2 = serial_in(up, UART_SCR);
serial_out(up, UART_SCR, scratch);
if (status1 == 0xa5 && status2 == 0x5a)
up->port.type = PORT_16450;
}
static int broken_efr(struct uart_8250_port *up)
{
if (autoconfig_read_divisor_id(up) == 0x0201 && size_fifo(up) == 16)
return 1;
return 0;
}
static inline int ns16550a_goto_highspeed(struct uart_8250_port *up)
{
unsigned char status;
status = serial_in(up, 0x04);
#define PRESL(x) ((x) & 0x30)
if (PRESL(status) == 0x10) {
return 0;
} else {
status &= ~0xB0;
status |= 0x10;
serial_out(up, 0x04, status);
}
return 1;
}
static void autoconfig_16550a(struct uart_8250_port *up)
{
unsigned char status1, status2;
unsigned int iersave;
up->port.type = PORT_16550A;
up->capabilities |= UART_CAP_FIFO;
if (up->port.flags & UPF_EXAR_EFR) {
status1 = serial_in(up, UART_EXAR_DVID);
if (status1 == 0x82 || status1 == 0x84 || status1 == 0x88) {
DEBUG_AUTOCONF("Exar XR17V35x ");
up->port.type = PORT_XR17V35X;
up->capabilities |= UART_CAP_AFE | UART_CAP_EFR |
UART_CAP_SLEEP;
return;
}
}
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
if (serial_in(up, UART_EFR) == 0) {
serial_out(up, UART_EFR, 0xA8);
if (serial_in(up, UART_EFR) != 0) {
DEBUG_AUTOCONF("EFRv1 ");
up->port.type = PORT_16650;
up->capabilities |= UART_CAP_EFR | UART_CAP_SLEEP;
} else {
DEBUG_AUTOCONF("Motorola 8xxx DUART ");
}
serial_out(up, UART_EFR, 0);
return;
}
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
if (serial_in(up, UART_EFR) == 0 && !broken_efr(up)) {
DEBUG_AUTOCONF("EFRv2 ");
autoconfig_has_efr(up);
return;
}
serial_out(up, UART_LCR, 0);
status1 = serial_in(up, UART_MCR);
serial_out(up, UART_LCR, 0xE0);
status2 = serial_in(up, 0x02);
if (!((status2 ^ status1) & UART_MCR_LOOP)) {
serial_out(up, UART_LCR, 0);
serial_out(up, UART_MCR, status1 ^ UART_MCR_LOOP);
serial_out(up, UART_LCR, 0xE0);
status2 = serial_in(up, 0x02);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_MCR, status1);
if ((status2 ^ status1) & UART_MCR_LOOP) {
unsigned short quot;
serial_out(up, UART_LCR, 0xE0);
quot = serial_dl_read(up);
quot <<= 3;
if (ns16550a_goto_highspeed(up))
serial_dl_write(up, quot);
serial_out(up, UART_LCR, 0);
up->port.uartclk = 921600*16;
up->port.type = PORT_NS16550A;
up->capabilities |= UART_NATSEMI;
return;
}
}
serial_out(up, UART_LCR, 0);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO | UART_FCR7_64BYTE);
status1 = serial_in(up, UART_IIR) >> 5;
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO | UART_FCR7_64BYTE);
status2 = serial_in(up, UART_IIR) >> 5;
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_out(up, UART_LCR, 0);
DEBUG_AUTOCONF("iir1=%d iir2=%d ", status1, status2);
if (status1 == 6 && status2 == 7) {
up->port.type = PORT_16750;
up->capabilities |= UART_CAP_AFE | UART_CAP_SLEEP;
return;
}
iersave = serial_in(up, UART_IER);
serial_out(up, UART_IER, iersave & ~UART_IER_UUE);
if (!(serial_in(up, UART_IER) & UART_IER_UUE)) {
serial_out(up, UART_IER, iersave | UART_IER_UUE);
if (serial_in(up, UART_IER) & UART_IER_UUE) {
DEBUG_AUTOCONF("Xscale ");
up->port.type = PORT_XSCALE;
up->capabilities |= UART_CAP_UUE | UART_CAP_RTOIE;
return;
}
} else {
DEBUG_AUTOCONF("Couldn't force IER_UUE to 0 ");
}
serial_out(up, UART_IER, iersave);
if (up->port.flags & UPF_EXAR_EFR) {
DEBUG_AUTOCONF("Exar XR17D15x ");
up->port.type = PORT_XR17D15X;
up->capabilities |= UART_CAP_AFE | UART_CAP_EFR |
UART_CAP_SLEEP;
return;
}
if (up->port.type == PORT_16550A && size_fifo(up) == 64) {
up->port.type = PORT_U6_16550A;
up->capabilities |= UART_CAP_AFE;
}
}
static void autoconfig(struct uart_8250_port *up, unsigned int probeflags)
{
unsigned char status1, scratch, scratch2, scratch3;
unsigned char save_lcr, save_mcr;
struct uart_port *port = &up->port;
unsigned long flags;
unsigned int old_capabilities;
if (!port->iobase && !port->mapbase && !port->membase)
return;
DEBUG_AUTOCONF("ttyS%d: autoconf (0x%04lx, 0x%p): ",
serial_index(port), port->iobase, port->membase);
spin_lock_irqsave(&port->lock, flags);
up->capabilities = 0;
up->bugs = 0;
if (!(port->flags & UPF_BUGGY_UART)) {
scratch = serial_in(up, UART_IER);
serial_out(up, UART_IER, 0);
#ifdef __i386__
outb(0xff, 0x080);
#endif
scratch2 = serial_in(up, UART_IER) & 0x0f;
serial_out(up, UART_IER, 0x0F);
#ifdef __i386__
outb(0, 0x080);
#endif
scratch3 = serial_in(up, UART_IER) & 0x0f;
serial_out(up, UART_IER, scratch);
if (scratch2 != 0 || scratch3 != 0x0F) {
spin_unlock_irqrestore(&port->lock, flags);
DEBUG_AUTOCONF("IER test failed (%02x, %02x) ",
scratch2, scratch3);
goto out;
}
}
save_mcr = serial_in(up, UART_MCR);
save_lcr = serial_in(up, UART_LCR);
if (!(port->flags & UPF_SKIP_TEST)) {
serial_out(up, UART_MCR, UART_MCR_LOOP | 0x0A);
status1 = serial_in(up, UART_MSR) & 0xF0;
serial_out(up, UART_MCR, save_mcr);
if (status1 != 0x90) {
spin_unlock_irqrestore(&port->lock, flags);
DEBUG_AUTOCONF("LOOP test failed (%02x) ",
status1);
goto out;
}
}
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, 0);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
scratch = serial_in(up, UART_IIR) >> 6;
switch (scratch) {
case 0:
autoconfig_8250(up);
break;
case 1:
port->type = PORT_UNKNOWN;
break;
case 2:
port->type = PORT_16550;
break;
case 3:
autoconfig_16550a(up);
break;
}
#ifdef CONFIG_SERIAL_8250_RSA
if (port->type == PORT_16550A && probeflags & PROBE_RSA) {
int i;
for (i = 0 ; i < probe_rsa_count; ++i) {
if (probe_rsa[i] == port->iobase && __enable_rsa(up)) {
port->type = PORT_RSA;
break;
}
}
}
#endif
serial_out(up, UART_LCR, save_lcr);
port->fifosize = uart_config[up->port.type].fifo_size;
old_capabilities = up->capabilities;
up->capabilities = uart_config[port->type].flags;
up->tx_loadsz = uart_config[port->type].tx_loadsz;
if (port->type == PORT_UNKNOWN)
goto out_lock;
#ifdef CONFIG_SERIAL_8250_RSA
if (port->type == PORT_RSA)
serial_out(up, UART_RSA_FRR, 0);
#endif
serial_out(up, UART_MCR, save_mcr);
serial8250_clear_fifos(up);
serial_in(up, UART_RX);
if (up->capabilities & UART_CAP_UUE)
serial_out(up, UART_IER, UART_IER_UUE);
else
serial_out(up, UART_IER, 0);
out_lock:
spin_unlock_irqrestore(&port->lock, flags);
if (up->capabilities != old_capabilities) {
printk(KERN_WARNING
"ttyS%d: detected caps %08x should be %08x\n",
serial_index(port), old_capabilities,
up->capabilities);
}
out:
DEBUG_AUTOCONF("iir=%d ", scratch);
DEBUG_AUTOCONF("type=%s\n", uart_config[port->type].name);
}
static void autoconfig_irq(struct uart_8250_port *up)
{
struct uart_port *port = &up->port;
unsigned char save_mcr, save_ier;
unsigned char save_ICP = 0;
unsigned int ICP = 0;
unsigned long irqs;
int irq;
if (port->flags & UPF_FOURPORT) {
ICP = (port->iobase & 0xfe0) | 0x1f;
save_ICP = inb_p(ICP);
outb_p(0x80, ICP);
inb_p(ICP);
}
probe_irq_off(probe_irq_on());
save_mcr = serial_in(up, UART_MCR);
save_ier = serial_in(up, UART_IER);
serial_out(up, UART_MCR, UART_MCR_OUT1 | UART_MCR_OUT2);
irqs = probe_irq_on();
serial_out(up, UART_MCR, 0);
udelay(10);
if (port->flags & UPF_FOURPORT) {
serial_out(up, UART_MCR,
UART_MCR_DTR | UART_MCR_RTS);
} else {
serial_out(up, UART_MCR,
UART_MCR_DTR | UART_MCR_RTS | UART_MCR_OUT2);
}
serial_out(up, UART_IER, 0x0f);
serial_in(up, UART_LSR);
serial_in(up, UART_RX);
serial_in(up, UART_IIR);
serial_in(up, UART_MSR);
serial_out(up, UART_TX, 0xFF);
udelay(20);
irq = probe_irq_off(irqs);
serial_out(up, UART_MCR, save_mcr);
serial_out(up, UART_IER, save_ier);
if (port->flags & UPF_FOURPORT)
outb_p(save_ICP, ICP);
port->irq = (irq > 0) ? irq : 0;
}
static inline void __stop_tx(struct uart_8250_port *p)
{
if (p->ier & UART_IER_THRI) {
p->ier &= ~UART_IER_THRI;
serial_out(p, UART_IER, p->ier);
}
}
static void serial8250_stop_tx(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
__stop_tx(up);
if (port->type == PORT_16C950) {
up->acr |= UART_ACR_TXDIS;
serial_icr_write(up, UART_ACR, up->acr);
}
}
static void serial8250_start_tx(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
if (up->dma && !serial8250_tx_dma(up)) {
return;
} else if (!(up->ier & UART_IER_THRI)) {
up->ier |= UART_IER_THRI;
serial_port_out(port, UART_IER, up->ier);
if (up->bugs & UART_BUG_TXEN) {
unsigned char lsr;
lsr = serial_in(up, UART_LSR);
up->lsr_saved_flags |= lsr & LSR_SAVE_FLAGS;
if (lsr & UART_LSR_TEMT)
serial8250_tx_chars(up);
}
}
if (port->type == PORT_16C950 && up->acr & UART_ACR_TXDIS) {
up->acr &= ~UART_ACR_TXDIS;
serial_icr_write(up, UART_ACR, up->acr);
}
}
static void serial8250_stop_rx(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
up->ier &= ~UART_IER_RLSI;
up->port.read_status_mask &= ~UART_LSR_DR;
serial_port_out(port, UART_IER, up->ier);
}
static void serial8250_enable_ms(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
if (up->bugs & UART_BUG_NOMSR)
return;
up->ier |= UART_IER_MSI;
serial_port_out(port, UART_IER, up->ier);
}
unsigned char
serial8250_rx_chars(struct uart_8250_port *up, unsigned char lsr)
{
struct uart_port *port = &up->port;
unsigned char ch;
int max_count = 256;
char flag;
do {
if (likely(lsr & UART_LSR_DR))
ch = serial_in(up, UART_RX);
else
ch = 0;
flag = TTY_NORMAL;
port->icount.rx++;
lsr |= up->lsr_saved_flags;
up->lsr_saved_flags = 0;
if (unlikely(lsr & UART_LSR_BRK_ERROR_BITS)) {
if (lsr & UART_LSR_BI) {
lsr &= ~(UART_LSR_FE | UART_LSR_PE);
port->icount.brk++;
if (uart_handle_break(port))
goto ignore_char;
} else if (lsr & UART_LSR_PE)
port->icount.parity++;
else if (lsr & UART_LSR_FE)
port->icount.frame++;
if (lsr & UART_LSR_OE)
port->icount.overrun++;
lsr &= port->read_status_mask;
if (lsr & UART_LSR_BI) {
DEBUG_INTR("handling break....");
flag = TTY_BREAK;
} else if (lsr & UART_LSR_PE)
flag = TTY_PARITY;
else if (lsr & UART_LSR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(port, ch))
goto ignore_char;
uart_insert_char(port, lsr, UART_LSR_OE, ch, flag);
ignore_char:
lsr = serial_in(up, UART_LSR);
} while ((lsr & (UART_LSR_DR | UART_LSR_BI)) && (max_count-- > 0));
spin_unlock(&port->lock);
tty_flip_buffer_push(&port->state->port);
spin_lock(&port->lock);
return lsr;
}
void serial8250_tx_chars(struct uart_8250_port *up)
{
struct uart_port *port = &up->port;
struct circ_buf *xmit = &port->state->xmit;
int count;
if (port->x_char) {
serial_out(up, UART_TX, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_tx_stopped(port)) {
serial8250_stop_tx(port);
return;
}
if (uart_circ_empty(xmit)) {
__stop_tx(up);
return;
}
count = up->tx_loadsz;
do {
serial_out(up, UART_TX, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
if (up->capabilities & UART_CAP_HFIFO) {
if ((serial_port_in(port, UART_LSR) & BOTH_EMPTY) !=
BOTH_EMPTY)
break;
}
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
DEBUG_INTR("THRE...");
if (uart_circ_empty(xmit))
__stop_tx(up);
}
unsigned int serial8250_modem_status(struct uart_8250_port *up)
{
struct uart_port *port = &up->port;
unsigned int status = serial_in(up, UART_MSR);
status |= up->msr_saved_flags;
up->msr_saved_flags = 0;
if (status & UART_MSR_ANY_DELTA && up->ier & UART_IER_MSI &&
port->state != NULL) {
if (status & UART_MSR_TERI)
port->icount.rng++;
if (status & UART_MSR_DDSR)
port->icount.dsr++;
if (status & UART_MSR_DDCD)
uart_handle_dcd_change(port, status & UART_MSR_DCD);
if (status & UART_MSR_DCTS)
uart_handle_cts_change(port, status & UART_MSR_CTS);
wake_up_interruptible(&port->state->port.delta_msr_wait);
}
return status;
}
int serial8250_handle_irq(struct uart_port *port, unsigned int iir)
{
unsigned char status;
unsigned long flags;
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
int dma_err = 0;
if (iir & UART_IIR_NO_INT)
return 0;
spin_lock_irqsave(&port->lock, flags);
status = serial_port_in(port, UART_LSR);
DEBUG_INTR("status = %x...", status);
if (status & (UART_LSR_DR | UART_LSR_BI)) {
if (up->dma)
dma_err = serial8250_rx_dma(up, iir);
if (!up->dma || dma_err)
status = serial8250_rx_chars(up, status);
}
serial8250_modem_status(up);
if (status & UART_LSR_THRE)
serial8250_tx_chars(up);
spin_unlock_irqrestore(&port->lock, flags);
return 1;
}
static int serial8250_default_handle_irq(struct uart_port *port)
{
unsigned int iir = serial_port_in(port, UART_IIR);
return serial8250_handle_irq(port, iir);
}
static int exar_handle_irq(struct uart_port *port)
{
unsigned char int0, int1, int2, int3;
unsigned int iir = serial_port_in(port, UART_IIR);
int ret;
ret = serial8250_handle_irq(port, iir);
if ((port->type == PORT_XR17V35X) ||
(port->type == PORT_XR17D15X)) {
int0 = serial_port_in(port, 0x80);
int1 = serial_port_in(port, 0x81);
int2 = serial_port_in(port, 0x82);
int3 = serial_port_in(port, 0x83);
}
return ret;
}
static irqreturn_t serial8250_interrupt(int irq, void *dev_id)
{
struct irq_info *i = dev_id;
struct list_head *l, *end = NULL;
int pass_counter = 0, handled = 0;
DEBUG_INTR("serial8250_interrupt(%d)...", irq);
spin_lock(&i->lock);
l = i->head;
do {
struct uart_8250_port *up;
struct uart_port *port;
up = list_entry(l, struct uart_8250_port, list);
port = &up->port;
if (port->handle_irq(port)) {
handled = 1;
end = NULL;
} else if (end == NULL)
end = l;
l = l->next;
if (l == i->head && pass_counter++ > PASS_LIMIT) {
printk_ratelimited(KERN_ERR
"serial8250: too much work for irq%d\n", irq);
break;
}
} while (l != end);
spin_unlock(&i->lock);
DEBUG_INTR("end.\n");
return IRQ_RETVAL(handled);
}
static void serial_do_unlink(struct irq_info *i, struct uart_8250_port *up)
{
spin_lock_irq(&i->lock);
if (!list_empty(i->head)) {
if (i->head == &up->list)
i->head = i->head->next;
list_del(&up->list);
} else {
BUG_ON(i->head != &up->list);
i->head = NULL;
}
spin_unlock_irq(&i->lock);
if (i->head == NULL) {
hlist_del(&i->node);
kfree(i);
}
}
static int serial_link_irq_chain(struct uart_8250_port *up)
{
struct hlist_head *h;
struct hlist_node *n;
struct irq_info *i;
int ret, irq_flags = up->port.flags & UPF_SHARE_IRQ ? IRQF_SHARED : 0;
mutex_lock(&hash_mutex);
h = &irq_lists[up->port.irq % NR_IRQ_HASH];
hlist_for_each(n, h) {
i = hlist_entry(n, struct irq_info, node);
if (i->irq == up->port.irq)
break;
}
if (n == NULL) {
i = kzalloc(sizeof(struct irq_info), GFP_KERNEL);
if (i == NULL) {
mutex_unlock(&hash_mutex);
return -ENOMEM;
}
spin_lock_init(&i->lock);
i->irq = up->port.irq;
hlist_add_head(&i->node, h);
}
mutex_unlock(&hash_mutex);
spin_lock_irq(&i->lock);
if (i->head) {
list_add(&up->list, i->head);
spin_unlock_irq(&i->lock);
ret = 0;
} else {
INIT_LIST_HEAD(&up->list);
i->head = &up->list;
spin_unlock_irq(&i->lock);
irq_flags |= up->port.irqflags;
ret = request_irq(up->port.irq, serial8250_interrupt,
irq_flags, "serial", i);
if (ret < 0)
serial_do_unlink(i, up);
}
return ret;
}
static void serial_unlink_irq_chain(struct uart_8250_port *up)
{
struct irq_info *i;
struct hlist_node *n;
struct hlist_head *h;
mutex_lock(&hash_mutex);
h = &irq_lists[up->port.irq % NR_IRQ_HASH];
hlist_for_each(n, h) {
i = hlist_entry(n, struct irq_info, node);
if (i->irq == up->port.irq)
break;
}
BUG_ON(n == NULL);
BUG_ON(i->head == NULL);
if (list_empty(i->head))
free_irq(up->port.irq, i);
serial_do_unlink(i, up);
mutex_unlock(&hash_mutex);
}
static void serial8250_timeout(unsigned long data)
{
struct uart_8250_port *up = (struct uart_8250_port *)data;
up->port.handle_irq(&up->port);
mod_timer(&up->timer, jiffies + uart_poll_timeout(&up->port));
}
static void serial8250_backup_timeout(unsigned long data)
{
struct uart_8250_port *up = (struct uart_8250_port *)data;
unsigned int iir, ier = 0, lsr;
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
if (up->port.irq) {
ier = serial_in(up, UART_IER);
serial_out(up, UART_IER, 0);
}
iir = serial_in(up, UART_IIR);
lsr = serial_in(up, UART_LSR);
up->lsr_saved_flags |= lsr & LSR_SAVE_FLAGS;
if ((iir & UART_IIR_NO_INT) && (up->ier & UART_IER_THRI) &&
(!uart_circ_empty(&up->port.state->xmit) || up->port.x_char) &&
(lsr & UART_LSR_THRE)) {
iir &= ~(UART_IIR_ID | UART_IIR_NO_INT);
iir |= UART_IIR_THRI;
}
if (!(iir & UART_IIR_NO_INT))
serial8250_tx_chars(up);
if (up->port.irq)
serial_out(up, UART_IER, ier);
spin_unlock_irqrestore(&up->port.lock, flags);
mod_timer(&up->timer,
jiffies + uart_poll_timeout(&up->port) + HZ / 5);
}
static unsigned int serial8250_tx_empty(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
unsigned long flags;
unsigned int lsr;
spin_lock_irqsave(&port->lock, flags);
lsr = serial_port_in(port, UART_LSR);
up->lsr_saved_flags |= lsr & LSR_SAVE_FLAGS;
spin_unlock_irqrestore(&port->lock, flags);
return (lsr & BOTH_EMPTY) == BOTH_EMPTY ? TIOCSER_TEMT : 0;
}
static unsigned int serial8250_get_mctrl(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
unsigned int status;
unsigned int ret;
status = serial8250_modem_status(up);
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
static void serial8250_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
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
mcr = (mcr & up->mcr_mask) | up->mcr_force | up->mcr;
serial_port_out(port, UART_MCR, mcr);
}
static void serial8250_break_ctl(struct uart_port *port, int break_state)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (break_state == -1)
up->lcr |= UART_LCR_SBC;
else
up->lcr &= ~UART_LCR_SBC;
serial_port_out(port, UART_LCR, up->lcr);
spin_unlock_irqrestore(&port->lock, flags);
}
static void wait_for_xmitr(struct uart_8250_port *up, int bits)
{
unsigned int status, tmout = 10000;
for (;;) {
status = serial_in(up, UART_LSR);
up->lsr_saved_flags |= status & LSR_SAVE_FLAGS;
if ((status & bits) == bits)
break;
if (--tmout == 0)
break;
udelay(1);
}
if (up->port.flags & UPF_CONS_FLOW) {
unsigned int tmout;
for (tmout = 1000000; tmout; tmout--) {
unsigned int msr = serial_in(up, UART_MSR);
up->msr_saved_flags |= msr & MSR_SAVE_FLAGS;
if (msr & UART_MSR_CTS)
break;
udelay(1);
touch_nmi_watchdog();
}
}
}
static int serial8250_get_poll_char(struct uart_port *port)
{
unsigned char lsr = serial_port_in(port, UART_LSR);
if (!(lsr & UART_LSR_DR))
return NO_POLL_CHAR;
return serial_port_in(port, UART_RX);
}
static void serial8250_put_poll_char(struct uart_port *port,
unsigned char c)
{
unsigned int ier;
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
ier = serial_port_in(port, UART_IER);
if (up->capabilities & UART_CAP_UUE)
serial_port_out(port, UART_IER, UART_IER_UUE);
else
serial_port_out(port, UART_IER, 0);
wait_for_xmitr(up, BOTH_EMPTY);
serial_port_out(port, UART_TX, c);
if (c == 10) {
wait_for_xmitr(up, BOTH_EMPTY);
serial_port_out(port, UART_TX, 13);
}
wait_for_xmitr(up, BOTH_EMPTY);
serial_port_out(port, UART_IER, ier);
}
static int serial8250_startup(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
unsigned long flags;
unsigned char lsr, iir;
int retval;
if (port->type == PORT_8250_CIR)
return -ENODEV;
if (!port->fifosize)
port->fifosize = uart_config[port->type].fifo_size;
if (!up->tx_loadsz)
up->tx_loadsz = uart_config[port->type].tx_loadsz;
if (!up->capabilities)
up->capabilities = uart_config[port->type].flags;
up->mcr = 0;
if (port->iotype != up->cur_iotype)
set_io_from_upio(port);
if (port->type == PORT_16C950) {
up->acr = 0;
serial_port_out(port, UART_LCR, UART_LCR_CONF_MODE_B);
serial_port_out(port, UART_EFR, UART_EFR_ECB);
serial_port_out(port, UART_IER, 0);
serial_port_out(port, UART_LCR, 0);
serial_icr_write(up, UART_CSR, 0);
serial_port_out(port, UART_LCR, UART_LCR_CONF_MODE_B);
serial_port_out(port, UART_EFR, UART_EFR_ECB);
serial_port_out(port, UART_LCR, 0);
}
#ifdef CONFIG_SERIAL_8250_RSA
enable_rsa(up);
#endif
serial8250_clear_fifos(up);
serial_port_in(port, UART_LSR);
serial_port_in(port, UART_RX);
serial_port_in(port, UART_IIR);
serial_port_in(port, UART_MSR);
if (!(port->flags & UPF_BUGGY_UART) &&
(serial_port_in(port, UART_LSR) == 0xff)) {
printk_ratelimited(KERN_INFO "ttyS%d: LSR safety check engaged!\n",
serial_index(port));
return -ENODEV;
}
if (port->type == PORT_16850) {
unsigned char fctr;
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
fctr = serial_in(up, UART_FCTR) & ~(UART_FCTR_RX|UART_FCTR_TX);
serial_port_out(port, UART_FCTR,
fctr | UART_FCTR_TRGD | UART_FCTR_RX);
serial_port_out(port, UART_TRG, UART_TRG_96);
serial_port_out(port, UART_FCTR,
fctr | UART_FCTR_TRGD | UART_FCTR_TX);
serial_port_out(port, UART_TRG, UART_TRG_96);
serial_port_out(port, UART_LCR, 0);
}
if (port->irq) {
unsigned char iir1;
spin_lock_irqsave(&port->lock, flags);
if (up->port.irqflags & IRQF_SHARED)
disable_irq_nosync(port->irq);
wait_for_xmitr(up, UART_LSR_THRE);
serial_port_out_sync(port, UART_IER, UART_IER_THRI);
udelay(1);
iir1 = serial_port_in(port, UART_IIR);
serial_port_out(port, UART_IER, 0);
serial_port_out_sync(port, UART_IER, UART_IER_THRI);
udelay(1);
iir = serial_port_in(port, UART_IIR);
serial_port_out(port, UART_IER, 0);
if (port->irqflags & IRQF_SHARED)
enable_irq(port->irq);
spin_unlock_irqrestore(&port->lock, flags);
if ((!(iir1 & UART_IIR_NO_INT) && (iir & UART_IIR_NO_INT)) ||
up->port.flags & UPF_BUG_THRE) {
up->bugs |= UART_BUG_THRE;
pr_debug("ttyS%d - using backup timer\n",
serial_index(port));
}
}
if (up->bugs & UART_BUG_THRE) {
up->timer.function = serial8250_backup_timeout;
up->timer.data = (unsigned long)up;
mod_timer(&up->timer, jiffies +
uart_poll_timeout(port) + HZ / 5);
}
if (!port->irq) {
up->timer.data = (unsigned long)up;
mod_timer(&up->timer, jiffies + uart_poll_timeout(port));
} else {
retval = serial_link_irq_chain(up);
if (retval)
return retval;
}
serial_port_out(port, UART_LCR, UART_LCR_WLEN8);
spin_lock_irqsave(&port->lock, flags);
if (up->port.flags & UPF_FOURPORT) {
if (!up->port.irq)
up->port.mctrl |= TIOCM_OUT1;
} else
if (port->irq)
up->port.mctrl |= TIOCM_OUT2;
serial8250_set_mctrl(port, port->mctrl);
if (skip_txen_test || up->port.flags & UPF_NO_TXEN_TEST)
goto dont_test_tx_en;
serial_port_out(port, UART_IER, UART_IER_THRI);
lsr = serial_port_in(port, UART_LSR);
iir = serial_port_in(port, UART_IIR);
serial_port_out(port, UART_IER, 0);
if (lsr & UART_LSR_TEMT && iir & UART_IIR_NO_INT) {
if (!(up->bugs & UART_BUG_TXEN)) {
up->bugs |= UART_BUG_TXEN;
pr_debug("ttyS%d - enabling bad tx status workarounds\n",
serial_index(port));
}
} else {
up->bugs &= ~UART_BUG_TXEN;
}
dont_test_tx_en:
spin_unlock_irqrestore(&port->lock, flags);
serial_port_in(port, UART_LSR);
serial_port_in(port, UART_RX);
serial_port_in(port, UART_IIR);
serial_port_in(port, UART_MSR);
up->lsr_saved_flags = 0;
up->msr_saved_flags = 0;
if (up->dma) {
retval = serial8250_request_dma(up);
if (retval) {
pr_warn_ratelimited("ttyS%d - failed to request DMA\n",
serial_index(port));
up->dma = NULL;
}
}
up->ier = UART_IER_RLSI | UART_IER_RDI;
serial_port_out(port, UART_IER, up->ier);
if (port->flags & UPF_FOURPORT) {
unsigned int icp;
icp = (port->iobase & 0xfe0) | 0x01f;
outb_p(0x80, icp);
inb_p(icp);
}
return 0;
}
static void serial8250_shutdown(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
unsigned long flags;
up->ier = 0;
serial_port_out(port, UART_IER, 0);
if (up->dma)
serial8250_release_dma(up);
spin_lock_irqsave(&port->lock, flags);
if (port->flags & UPF_FOURPORT) {
inb((port->iobase & 0xfe0) | 0x1f);
port->mctrl |= TIOCM_OUT1;
} else
port->mctrl &= ~TIOCM_OUT2;
serial8250_set_mctrl(port, port->mctrl);
spin_unlock_irqrestore(&port->lock, flags);
serial_port_out(port, UART_LCR,
serial_port_in(port, UART_LCR) & ~UART_LCR_SBC);
serial8250_clear_fifos(up);
#ifdef CONFIG_SERIAL_8250_RSA
disable_rsa(up);
#endif
serial_port_in(port, UART_RX);
del_timer_sync(&up->timer);
up->timer.function = serial8250_timeout;
if (port->irq)
serial_unlink_irq_chain(up);
}
static unsigned int serial8250_get_divisor(struct uart_port *port, unsigned int baud)
{
unsigned int quot;
if ((port->flags & UPF_MAGIC_MULTIPLIER) &&
baud == (port->uartclk/4))
quot = 0x8001;
else if ((port->flags & UPF_MAGIC_MULTIPLIER) &&
baud == (port->uartclk/8))
quot = 0x8002;
else
quot = uart_get_divisor(port, baud);
return quot;
}
void
serial8250_do_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
unsigned char cval, fcr = 0;
unsigned long flags;
unsigned int baud, quot;
int fifo_bug = 0;
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
if (termios->c_cflag & CSTOPB)
cval |= UART_LCR_STOP;
if (termios->c_cflag & PARENB) {
cval |= UART_LCR_PARITY;
if (up->bugs & UART_BUG_PARITY)
fifo_bug = 1;
}
if (!(termios->c_cflag & PARODD))
cval |= UART_LCR_EPAR;
#ifdef CMSPAR
if (termios->c_cflag & CMSPAR)
cval |= UART_LCR_SPAR;
#endif
baud = uart_get_baud_rate(port, termios, old,
port->uartclk / 16 / 0xffff,
port->uartclk / 16);
quot = serial8250_get_divisor(port, baud);
if (up->bugs & UART_BUG_QUOT && (quot & 0xff) == 0)
quot++;
if (up->capabilities & UART_CAP_FIFO && port->fifosize > 1) {
fcr = uart_config[port->type].fcr;
if ((baud < 2400 && !up->dma) || fifo_bug) {
fcr &= ~UART_FCR_TRIGGER_MASK;
fcr |= UART_FCR_TRIGGER_1;
}
}
if (up->capabilities & UART_CAP_AFE && port->fifosize >= 32) {
up->mcr &= ~UART_MCR_AFE;
if (termios->c_cflag & CRTSCTS)
up->mcr |= UART_MCR_AFE;
}
spin_lock_irqsave(&port->lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
port->read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (termios->c_iflag & INPCK)
port->read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= UART_LSR_BI;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= UART_LSR_BI;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= UART_LSR_OE;
}
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |= UART_LSR_DR;
up->ier &= ~UART_IER_MSI;
if (!(up->bugs & UART_BUG_NOMSR) &&
UART_ENABLE_MS(&up->port, termios->c_cflag))
up->ier |= UART_IER_MSI;
if (up->capabilities & UART_CAP_UUE)
up->ier |= UART_IER_UUE;
if (up->capabilities & UART_CAP_RTOIE)
up->ier |= UART_IER_RTOIE;
serial_port_out(port, UART_IER, up->ier);
if (up->capabilities & UART_CAP_EFR) {
unsigned char efr = 0;
if (termios->c_cflag & CRTSCTS)
efr |= UART_EFR_CTS;
serial_port_out(port, UART_LCR, UART_LCR_CONF_MODE_B);
if (port->flags & UPF_EXAR_EFR)
serial_port_out(port, UART_XR_EFR, efr);
else
serial_port_out(port, UART_EFR, efr);
}
if (is_omap1510_8250(up)) {
if (baud == 115200) {
quot = 1;
serial_port_out(port, UART_OMAP_OSC_12M_SEL, 1);
} else
serial_port_out(port, UART_OMAP_OSC_12M_SEL, 0);
}
if (up->capabilities & UART_NATSEMI)
serial_port_out(port, UART_LCR, 0xe0);
else
serial_port_out(port, UART_LCR, cval | UART_LCR_DLAB);
serial_dl_write(up, quot);
if (up->port.type == PORT_XR17V35X) {
unsigned int baud_x32 = (port->uartclk * 2) / baud;
u16 quot = baud_x32 / 32;
u8 quot_frac = DIV_ROUND_CLOSEST(baud_x32 % 32, 2);
serial_dl_write(up, quot);
serial_port_out(port, 0x2, quot_frac & 0xf);
}
if (port->type == PORT_16750)
serial_port_out(port, UART_FCR, fcr);
serial_port_out(port, UART_LCR, cval);
up->lcr = cval;
if (port->type != PORT_16750) {
if (fcr & UART_FCR_ENABLE_FIFO)
serial_port_out(port, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_port_out(port, UART_FCR, fcr);
}
serial8250_set_mctrl(port, port->mctrl);
spin_unlock_irqrestore(&port->lock, flags);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
}
static void
serial8250_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
if (port->set_termios)
port->set_termios(port, termios, old);
else
serial8250_do_set_termios(port, termios, old);
}
static void
serial8250_set_ldisc(struct uart_port *port, int new)
{
if (new == N_PPS) {
port->flags |= UPF_HARDPPS_CD;
serial8250_enable_ms(port);
} else
port->flags &= ~UPF_HARDPPS_CD;
}
void serial8250_do_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct uart_8250_port *p =
container_of(port, struct uart_8250_port, port);
serial8250_set_sleep(p, state != 0);
}
static void
serial8250_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
if (port->pm)
port->pm(port, state, oldstate);
else
serial8250_do_pm(port, state, oldstate);
}
static unsigned int serial8250_port_size(struct uart_8250_port *pt)
{
if (pt->port.iotype == UPIO_AU)
return 0x1000;
if (is_omap1_8250(pt))
return 0x16 << pt->port.regshift;
return 8 << pt->port.regshift;
}
static int serial8250_request_std_resource(struct uart_8250_port *up)
{
unsigned int size = serial8250_port_size(up);
struct uart_port *port = &up->port;
int ret = 0;
switch (port->iotype) {
case UPIO_AU:
case UPIO_TSI:
case UPIO_MEM32:
case UPIO_MEM:
if (!port->mapbase)
break;
if (!request_mem_region(port->mapbase, size, "serial")) {
ret = -EBUSY;
break;
}
if (port->flags & UPF_IOREMAP) {
port->membase = ioremap_nocache(port->mapbase, size);
if (!port->membase) {
release_mem_region(port->mapbase, size);
ret = -ENOMEM;
}
}
break;
case UPIO_HUB6:
case UPIO_PORT:
if (!request_region(port->iobase, size, "serial"))
ret = -EBUSY;
break;
}
return ret;
}
static void serial8250_release_std_resource(struct uart_8250_port *up)
{
unsigned int size = serial8250_port_size(up);
struct uart_port *port = &up->port;
switch (port->iotype) {
case UPIO_AU:
case UPIO_TSI:
case UPIO_MEM32:
case UPIO_MEM:
if (!port->mapbase)
break;
if (port->flags & UPF_IOREMAP) {
iounmap(port->membase);
port->membase = NULL;
}
release_mem_region(port->mapbase, size);
break;
case UPIO_HUB6:
case UPIO_PORT:
release_region(port->iobase, size);
break;
}
}
static int serial8250_request_rsa_resource(struct uart_8250_port *up)
{
unsigned long start = UART_RSA_BASE << up->port.regshift;
unsigned int size = 8 << up->port.regshift;
struct uart_port *port = &up->port;
int ret = -EINVAL;
switch (port->iotype) {
case UPIO_HUB6:
case UPIO_PORT:
start += port->iobase;
if (request_region(start, size, "serial-rsa"))
ret = 0;
else
ret = -EBUSY;
break;
}
return ret;
}
static void serial8250_release_rsa_resource(struct uart_8250_port *up)
{
unsigned long offset = UART_RSA_BASE << up->port.regshift;
unsigned int size = 8 << up->port.regshift;
struct uart_port *port = &up->port;
switch (port->iotype) {
case UPIO_HUB6:
case UPIO_PORT:
release_region(port->iobase + offset, size);
break;
}
}
static void serial8250_release_port(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
serial8250_release_std_resource(up);
if (port->type == PORT_RSA)
serial8250_release_rsa_resource(up);
}
static int serial8250_request_port(struct uart_port *port)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
int ret;
if (port->type == PORT_8250_CIR)
return -ENODEV;
ret = serial8250_request_std_resource(up);
if (ret == 0 && port->type == PORT_RSA) {
ret = serial8250_request_rsa_resource(up);
if (ret < 0)
serial8250_release_std_resource(up);
}
return ret;
}
static void serial8250_config_port(struct uart_port *port, int flags)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
int probeflags = PROBE_ANY;
int ret;
if (port->type == PORT_8250_CIR)
return;
ret = serial8250_request_std_resource(up);
if (ret < 0)
return;
ret = serial8250_request_rsa_resource(up);
if (ret < 0)
probeflags &= ~PROBE_RSA;
if (port->iotype != up->cur_iotype)
set_io_from_upio(port);
if (flags & UART_CONFIG_TYPE)
autoconfig(up, probeflags);
if (port->type == PORT_16550A && port->iotype == UPIO_AU)
up->bugs |= UART_BUG_NOMSR;
if (port->type == PORT_TEGRA)
up->bugs |= UART_BUG_NOMSR;
if (port->type != PORT_UNKNOWN && flags & UART_CONFIG_IRQ)
autoconfig_irq(up);
if (port->type != PORT_RSA && probeflags & PROBE_RSA)
serial8250_release_rsa_resource(up);
if (port->type == PORT_UNKNOWN)
serial8250_release_std_resource(up);
if ((port->type == PORT_XR17V35X) ||
(port->type == PORT_XR17D15X))
port->handle_irq = exar_handle_irq;
}
static int
serial8250_verify_port(struct uart_port *port, struct serial_struct *ser)
{
if (ser->irq >= nr_irqs || ser->irq < 0 ||
ser->baud_base < 9600 || ser->type < PORT_UNKNOWN ||
ser->type >= ARRAY_SIZE(uart_config) || ser->type == PORT_CIRRUS ||
ser->type == PORT_STARTECH)
return -EINVAL;
return 0;
}
static const char *
serial8250_type(struct uart_port *port)
{
int type = port->type;
if (type >= ARRAY_SIZE(uart_config))
type = 0;
return uart_config[type].name;
}
void serial8250_set_isa_configurator(
void (*v)(int port, struct uart_port *up, unsigned short *capabilities))
{
serial8250_isa_config = v;
}
static void __init serial8250_isa_init_ports(void)
{
struct uart_8250_port *up;
static int first = 1;
int i, irqflag = 0;
if (!first)
return;
first = 0;
if (nr_uarts > UART_NR)
nr_uarts = UART_NR;
for (i = 0; i < nr_uarts; i++) {
struct uart_8250_port *up = &serial8250_ports[i];
struct uart_port *port = &up->port;
port->line = i;
spin_lock_init(&port->lock);
init_timer(&up->timer);
up->timer.function = serial8250_timeout;
up->cur_iotype = 0xFF;
up->mcr_mask = ~ALPHA_KLUDGE_MCR;
up->mcr_force = ALPHA_KLUDGE_MCR;
port->ops = &serial8250_pops;
}
if (share_irqs)
irqflag = IRQF_SHARED;
for (i = 0, up = serial8250_ports;
i < ARRAY_SIZE(old_serial_port) && i < nr_uarts;
i++, up++) {
struct uart_port *port = &up->port;
port->iobase = old_serial_port[i].port;
port->irq = irq_canonicalize(old_serial_port[i].irq);
port->irqflags = old_serial_port[i].irqflags;
port->uartclk = old_serial_port[i].baud_base * 16;
port->flags = old_serial_port[i].flags;
port->hub6 = old_serial_port[i].hub6;
port->membase = old_serial_port[i].iomem_base;
port->iotype = old_serial_port[i].io_type;
port->regshift = old_serial_port[i].iomem_reg_shift;
set_io_from_upio(port);
port->irqflags |= irqflag;
if (serial8250_isa_config != NULL)
serial8250_isa_config(i, &up->port, &up->capabilities);
}
}
static void
serial8250_init_fixed_type_port(struct uart_8250_port *up, unsigned int type)
{
up->port.type = type;
if (!up->port.fifosize)
up->port.fifosize = uart_config[type].fifo_size;
if (!up->tx_loadsz)
up->tx_loadsz = uart_config[type].tx_loadsz;
if (!up->capabilities)
up->capabilities = uart_config[type].flags;
}
static void __init
serial8250_register_ports(struct uart_driver *drv, struct device *dev)
{
int i;
for (i = 0; i < nr_uarts; i++) {
struct uart_8250_port *up = &serial8250_ports[i];
if (up->port.dev)
continue;
up->port.dev = dev;
if (up->port.flags & UPF_FIXED_TYPE)
serial8250_init_fixed_type_port(up, up->port.type);
uart_add_one_port(drv, &up->port);
}
}
static void serial8250_console_putchar(struct uart_port *port, int ch)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
wait_for_xmitr(up, UART_LSR_THRE);
serial_port_out(port, UART_TX, ch);
}
static void
serial8250_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_8250_port *up = &serial8250_ports[co->index];
struct uart_port *port = &up->port;
unsigned long flags;
unsigned int ier;
int locked = 1;
touch_nmi_watchdog();
local_irq_save(flags);
if (port->sysrq) {
locked = 0;
} else if (oops_in_progress) {
locked = spin_trylock(&port->lock);
} else
spin_lock(&port->lock);
ier = serial_port_in(port, UART_IER);
if (up->capabilities & UART_CAP_UUE)
serial_port_out(port, UART_IER, UART_IER_UUE);
else
serial_port_out(port, UART_IER, 0);
uart_console_write(port, s, count, serial8250_console_putchar);
wait_for_xmitr(up, BOTH_EMPTY);
serial_port_out(port, UART_IER, ier);
if (up->msr_saved_flags)
serial8250_modem_status(up);
if (locked)
spin_unlock(&port->lock);
local_irq_restore(flags);
}
static int __init serial8250_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= nr_uarts)
co->index = 0;
port = &serial8250_ports[co->index].port;
if (!port->iobase && !port->membase)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int serial8250_console_early_setup(void)
{
return serial8250_find_port_for_earlycon();
}
static int __init serial8250_console_init(void)
{
serial8250_isa_init_ports();
register_console(&serial8250_console);
return 0;
}
int serial8250_find_port(struct uart_port *p)
{
int line;
struct uart_port *port;
for (line = 0; line < nr_uarts; line++) {
port = &serial8250_ports[line].port;
if (uart_match_port(p, port))
return line;
}
return -ENODEV;
}
int __init early_serial_setup(struct uart_port *port)
{
struct uart_port *p;
if (port->line >= ARRAY_SIZE(serial8250_ports))
return -ENODEV;
serial8250_isa_init_ports();
p = &serial8250_ports[port->line].port;
p->iobase = port->iobase;
p->membase = port->membase;
p->irq = port->irq;
p->irqflags = port->irqflags;
p->uartclk = port->uartclk;
p->fifosize = port->fifosize;
p->regshift = port->regshift;
p->iotype = port->iotype;
p->flags = port->flags;
p->mapbase = port->mapbase;
p->private_data = port->private_data;
p->type = port->type;
p->line = port->line;
set_io_from_upio(p);
if (port->serial_in)
p->serial_in = port->serial_in;
if (port->serial_out)
p->serial_out = port->serial_out;
if (port->handle_irq)
p->handle_irq = port->handle_irq;
else
p->handle_irq = serial8250_default_handle_irq;
return 0;
}
void serial8250_suspend_port(int line)
{
uart_suspend_port(&serial8250_reg, &serial8250_ports[line].port);
}
void serial8250_resume_port(int line)
{
struct uart_8250_port *up = &serial8250_ports[line];
struct uart_port *port = &up->port;
if (up->capabilities & UART_NATSEMI) {
serial_port_out(port, UART_LCR, 0xE0);
ns16550a_goto_highspeed(up);
serial_port_out(port, UART_LCR, 0);
port->uartclk = 921600*16;
}
uart_resume_port(&serial8250_reg, port);
}
static int serial8250_probe(struct platform_device *dev)
{
struct plat_serial8250_port *p = dev_get_platdata(&dev->dev);
struct uart_8250_port uart;
int ret, i, irqflag = 0;
memset(&uart, 0, sizeof(uart));
if (share_irqs)
irqflag = IRQF_SHARED;
for (i = 0; p && p->flags != 0; p++, i++) {
uart.port.iobase = p->iobase;
uart.port.membase = p->membase;
uart.port.irq = p->irq;
uart.port.irqflags = p->irqflags;
uart.port.uartclk = p->uartclk;
uart.port.regshift = p->regshift;
uart.port.iotype = p->iotype;
uart.port.flags = p->flags;
uart.port.mapbase = p->mapbase;
uart.port.hub6 = p->hub6;
uart.port.private_data = p->private_data;
uart.port.type = p->type;
uart.port.serial_in = p->serial_in;
uart.port.serial_out = p->serial_out;
uart.port.handle_irq = p->handle_irq;
uart.port.handle_break = p->handle_break;
uart.port.set_termios = p->set_termios;
uart.port.pm = p->pm;
uart.port.dev = &dev->dev;
uart.port.irqflags |= irqflag;
ret = serial8250_register_8250_port(&uart);
if (ret < 0) {
dev_err(&dev->dev, "unable to register port at index %d "
"(IO%lx MEM%llx IRQ%d): %d\n", i,
p->iobase, (unsigned long long)p->mapbase,
p->irq, ret);
}
}
return 0;
}
static int serial8250_remove(struct platform_device *dev)
{
int i;
for (i = 0; i < nr_uarts; i++) {
struct uart_8250_port *up = &serial8250_ports[i];
if (up->port.dev == &dev->dev)
serial8250_unregister_port(i);
}
return 0;
}
static int serial8250_suspend(struct platform_device *dev, pm_message_t state)
{
int i;
for (i = 0; i < UART_NR; i++) {
struct uart_8250_port *up = &serial8250_ports[i];
if (up->port.type != PORT_UNKNOWN && up->port.dev == &dev->dev)
uart_suspend_port(&serial8250_reg, &up->port);
}
return 0;
}
static int serial8250_resume(struct platform_device *dev)
{
int i;
for (i = 0; i < UART_NR; i++) {
struct uart_8250_port *up = &serial8250_ports[i];
if (up->port.type != PORT_UNKNOWN && up->port.dev == &dev->dev)
serial8250_resume_port(i);
}
return 0;
}
static struct uart_8250_port *serial8250_find_match_or_unused(struct uart_port *port)
{
int i;
for (i = 0; i < nr_uarts; i++)
if (uart_match_port(&serial8250_ports[i].port, port))
return &serial8250_ports[i];
for (i = 0; i < nr_uarts; i++)
if (serial8250_ports[i].port.type == PORT_UNKNOWN &&
serial8250_ports[i].port.iobase == 0)
return &serial8250_ports[i];
for (i = 0; i < nr_uarts; i++)
if (serial8250_ports[i].port.type == PORT_UNKNOWN)
return &serial8250_ports[i];
return NULL;
}
int serial8250_register_8250_port(struct uart_8250_port *up)
{
struct uart_8250_port *uart;
int ret = -ENOSPC;
if (up->port.uartclk == 0)
return -EINVAL;
mutex_lock(&serial_mutex);
uart = serial8250_find_match_or_unused(&up->port);
if (uart && uart->port.type != PORT_8250_CIR) {
if (uart->port.dev)
uart_remove_one_port(&serial8250_reg, &uart->port);
uart->port.iobase = up->port.iobase;
uart->port.membase = up->port.membase;
uart->port.irq = up->port.irq;
uart->port.irqflags = up->port.irqflags;
uart->port.uartclk = up->port.uartclk;
uart->port.fifosize = up->port.fifosize;
uart->port.regshift = up->port.regshift;
uart->port.iotype = up->port.iotype;
uart->port.flags = up->port.flags | UPF_BOOT_AUTOCONF;
uart->bugs = up->bugs;
uart->port.mapbase = up->port.mapbase;
uart->port.private_data = up->port.private_data;
uart->port.fifosize = up->port.fifosize;
uart->tx_loadsz = up->tx_loadsz;
uart->capabilities = up->capabilities;
if (uart->port.fifosize && !uart->tx_loadsz)
uart->tx_loadsz = uart->port.fifosize;
if (up->port.dev)
uart->port.dev = up->port.dev;
if (up->port.flags & UPF_FIXED_TYPE)
serial8250_init_fixed_type_port(uart, up->port.type);
set_io_from_upio(&uart->port);
if (up->port.serial_in)
uart->port.serial_in = up->port.serial_in;
if (up->port.serial_out)
uart->port.serial_out = up->port.serial_out;
if (up->port.handle_irq)
uart->port.handle_irq = up->port.handle_irq;
if (up->port.set_termios)
uart->port.set_termios = up->port.set_termios;
if (up->port.pm)
uart->port.pm = up->port.pm;
if (up->port.handle_break)
uart->port.handle_break = up->port.handle_break;
if (up->dl_read)
uart->dl_read = up->dl_read;
if (up->dl_write)
uart->dl_write = up->dl_write;
if (up->dma)
uart->dma = up->dma;
if (serial8250_isa_config != NULL)
serial8250_isa_config(0, &uart->port,
&uart->capabilities);
ret = uart_add_one_port(&serial8250_reg, &uart->port);
if (ret == 0)
ret = uart->port.line;
}
mutex_unlock(&serial_mutex);
return ret;
}
void serial8250_unregister_port(int line)
{
struct uart_8250_port *uart = &serial8250_ports[line];
mutex_lock(&serial_mutex);
uart_remove_one_port(&serial8250_reg, &uart->port);
if (serial8250_isa_devs) {
uart->port.flags &= ~UPF_BOOT_AUTOCONF;
uart->port.type = PORT_UNKNOWN;
uart->port.dev = &serial8250_isa_devs->dev;
uart->capabilities = uart_config[uart->port.type].flags;
uart_add_one_port(&serial8250_reg, &uart->port);
} else {
uart->port.dev = NULL;
}
mutex_unlock(&serial_mutex);
}
static int __init serial8250_init(void)
{
int ret;
serial8250_isa_init_ports();
printk(KERN_INFO "Serial: 8250/16550 driver, "
"%d ports, IRQ sharing %sabled\n", nr_uarts,
share_irqs ? "en" : "dis");
#ifdef CONFIG_SPARC
ret = sunserial_register_minors(&serial8250_reg, UART_NR);
#else
serial8250_reg.nr = UART_NR;
ret = uart_register_driver(&serial8250_reg);
#endif
if (ret)
goto out;
ret = serial8250_pnp_init();
if (ret)
goto unreg_uart_drv;
serial8250_isa_devs = platform_device_alloc("serial8250",
PLAT8250_DEV_LEGACY);
if (!serial8250_isa_devs) {
ret = -ENOMEM;
goto unreg_pnp;
}
ret = platform_device_add(serial8250_isa_devs);
if (ret)
goto put_dev;
serial8250_register_ports(&serial8250_reg, &serial8250_isa_devs->dev);
ret = platform_driver_register(&serial8250_isa_driver);
if (ret == 0)
goto out;
platform_device_del(serial8250_isa_devs);
put_dev:
platform_device_put(serial8250_isa_devs);
unreg_pnp:
serial8250_pnp_exit();
unreg_uart_drv:
#ifdef CONFIG_SPARC
sunserial_unregister_minors(&serial8250_reg, UART_NR);
#else
uart_unregister_driver(&serial8250_reg);
#endif
out:
return ret;
}
static void __exit serial8250_exit(void)
{
struct platform_device *isa_dev = serial8250_isa_devs;
serial8250_isa_devs = NULL;
platform_driver_unregister(&serial8250_isa_driver);
platform_device_unregister(isa_dev);
serial8250_pnp_exit();
#ifdef CONFIG_SPARC
sunserial_unregister_minors(&serial8250_reg, UART_NR);
#else
uart_unregister_driver(&serial8250_reg);
#endif
}
static void __used s8250_options(void)
{
#undef MODULE_PARAM_PREFIX
#define MODULE_PARAM_PREFIX "8250_core."
module_param_cb(share_irqs, &param_ops_uint, &share_irqs, 0644);
module_param_cb(nr_uarts, &param_ops_uint, &nr_uarts, 0644);
module_param_cb(skip_txen_test, &param_ops_uint, &skip_txen_test, 0644);
#ifdef CONFIG_SERIAL_8250_RSA
__module_param_call(MODULE_PARAM_PREFIX, probe_rsa,
&param_array_ops, .arr = &__param_arr_probe_rsa,
0444, -1);
#endif
}
