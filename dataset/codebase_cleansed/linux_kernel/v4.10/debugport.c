static void
start_port(struct dbg_port* p)
{
unsigned long rec_ctrl = 0;
unsigned long tr_ctrl = 0;
if (!p)
return;
if (p->started)
return;
p->started = 1;
if (p->index == 0)
{
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma6);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma6, unused);
}
else if (p->index == 1)
{
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma8);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma8, usb);
}
else if (p->index == 2)
{
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma2);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma2, par0);
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma3);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma3, par0);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, ser2, select);
}
else
{
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma4);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma4, par1);
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma5);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma5, par1);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, ser3, select);
}
*R_GEN_CONFIG = genconfig_shadow;
*p->xoff =
IO_STATE(R_SERIAL0_XOFF, tx_stop, enable) |
IO_STATE(R_SERIAL0_XOFF, auto_xoff, disable) |
IO_FIELD(R_SERIAL0_XOFF, xoff_char, 0);
switch (p->baudrate)
{
case 0:
case 115200:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c115k2Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c115k2Hz);
break;
case 1200:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c1200Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c1200Hz);
break;
case 2400:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c2400Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c2400Hz);
break;
case 4800:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c4800Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c4800Hz);
break;
case 9600:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c9600Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c9600Hz);
break;
case 19200:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c19k2Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c19k2Hz);
break;
case 38400:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c38k4Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c38k4Hz);
break;
case 57600:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c57k6Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c57k6Hz);
break;
default:
*p->baud =
IO_STATE(R_SERIAL0_BAUD, tr_baud, c115k2Hz) |
IO_STATE(R_SERIAL0_BAUD, rec_baud, c115k2Hz);
break;
}
if (p->parity == 'E') {
rec_ctrl =
IO_STATE(R_SERIAL0_REC_CTRL, rec_par, even) |
IO_STATE(R_SERIAL0_REC_CTRL, rec_par_en, enable);
tr_ctrl =
IO_STATE(R_SERIAL0_TR_CTRL, tr_par, even) |
IO_STATE(R_SERIAL0_TR_CTRL, tr_par_en, enable);
} else if (p->parity == 'O') {
rec_ctrl =
IO_STATE(R_SERIAL0_REC_CTRL, rec_par, odd) |
IO_STATE(R_SERIAL0_REC_CTRL, rec_par_en, enable);
tr_ctrl =
IO_STATE(R_SERIAL0_TR_CTRL, tr_par, odd) |
IO_STATE(R_SERIAL0_TR_CTRL, tr_par_en, enable);
} else {
rec_ctrl =
IO_STATE(R_SERIAL0_REC_CTRL, rec_par, even) |
IO_STATE(R_SERIAL0_REC_CTRL, rec_par_en, disable);
tr_ctrl =
IO_STATE(R_SERIAL0_TR_CTRL, tr_par, even) |
IO_STATE(R_SERIAL0_TR_CTRL, tr_par_en, disable);
}
if (p->bits == 7)
{
rec_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_bitnr, rec_7bit);
tr_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_bitnr, tr_7bit);
}
else
{
rec_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_bitnr, rec_8bit);
tr_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_bitnr, tr_8bit);
}
*p->rec_ctrl =
IO_STATE(R_SERIAL0_REC_CTRL, dma_err, stop) |
IO_STATE(R_SERIAL0_REC_CTRL, rec_enable, enable) |
IO_STATE(R_SERIAL0_REC_CTRL, rts_, active) |
IO_STATE(R_SERIAL0_REC_CTRL, sampling, middle) |
IO_STATE(R_SERIAL0_REC_CTRL, rec_stick_par, normal) |
rec_ctrl;
*p->tr_ctrl =
IO_FIELD(R_SERIAL0_TR_CTRL, txd, 0) |
IO_STATE(R_SERIAL0_TR_CTRL, tr_enable, enable) |
IO_STATE(R_SERIAL0_TR_CTRL, auto_cts, disabled) |
IO_STATE(R_SERIAL0_TR_CTRL, stop_bits, one_bit) |
IO_STATE(R_SERIAL0_TR_CTRL, tr_stick_par, normal) |
tr_ctrl;
}
static void
console_write_direct(struct console *co, const char *buf, unsigned int len)
{
int i;
unsigned long flags;
if (!port)
return;
local_irq_save(flags);
for (i = 0; i < len; i++) {
if (buf[i] == '\n') {
while (!(*port->read & IO_MASK(R_SERIAL0_READ, tr_ready)))
;
*port->write = '\r';
}
while (!(*port->read & IO_MASK(R_SERIAL0_READ, tr_ready)))
;
*port->write = buf[i];
}
reset_watchdog();
local_irq_restore(flags);
}
static void
console_write(struct console *co, const char *buf, unsigned int len)
{
if (!port)
return;
console_write_direct(co, buf, len);
}
void
console_print_etrax(const char *buf)
{
console_write(NULL, buf, strlen(buf));
}
int
getDebugChar(void)
{
unsigned long readval;
if (!kgdb_port)
return 0;
do {
readval = *kgdb_port->read;
} while (!(readval & IO_MASK(R_SERIAL0_READ, data_avail)));
return (readval & IO_MASK(R_SERIAL0_READ, data_in));
}
void
putDebugChar(int val)
{
if (!kgdb_port)
return;
while (!(*kgdb_port->read & IO_MASK(R_SERIAL0_READ, tr_ready)))
;
*kgdb_port->write = val;
}
void
enableDebugIRQ(void)
{
if (!kgdb_port)
return;
*R_IRQ_MASK1_SET = kgdb_port->irq;
*R_VECT_MASK_SET = IO_STATE(R_VECT_MASK_SET, serial, set);
*kgdb_port->rec_ctrl = IO_STATE(R_SERIAL0_REC_CTRL, rec_enable, enable);
}
static int __init
console_setup(struct console *co, char *options)
{
char* s;
if (options) {
port = &ports[co->index];
port->baudrate = 115200;
port->parity = 'N';
port->bits = 8;
port->baudrate = simple_strtoul(options, NULL, 10);
s = options;
while(*s >= '0' && *s <= '9')
s++;
if (*s) port->parity = *s++;
if (*s) port->bits = *s++ - '0';
port->started = 0;
start_port(0);
}
return 0;
}
static int dummy_open(struct tty_struct *tty, struct file * filp)
{
return 0;
}
static void dummy_close(struct tty_struct *tty, struct file * filp)
{
}
static int dummy_write(struct tty_struct * tty,
const unsigned char *buf, int count)
{
return count;
}
static int dummy_write_room(struct tty_struct *tty)
{
return 8192;
}
void __init
init_dummy_console(void)
{
memset(&dummy_driver, 0, sizeof(struct tty_driver));
dummy_driver.driver_name = "serial";
dummy_driver.name = "ttyS";
dummy_driver.major = TTY_MAJOR;
dummy_driver.minor_start = 68;
dummy_driver.num = 1;
dummy_driver.type = TTY_DRIVER_TYPE_SERIAL;
dummy_driver.subtype = SERIAL_TYPE_NORMAL;
dummy_driver.init_termios = tty_std_termios;
dummy_driver.init_termios.c_cflag =
B115200 | CS8 | CREAD | HUPCL | CLOCAL;
dummy_driver.flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
dummy_driver.init_termios.c_ispeed = 115200;
dummy_driver.init_termios.c_ospeed = 115200;
dummy_driver.ops = &dummy_ops;
if (tty_register_driver(&dummy_driver))
panic("Couldn't register dummy serial driver\n");
}
static struct tty_driver*
etrax_console_device(struct console* co, int *index)
{
if (port)
*index = port->index;
else
*index = 0;
#ifdef CONFIG_ETRAX_SERIAL
return port ? serial_driver : &dummy_driver;
#else
return &dummy_driver;
#endif
}
int __init
init_etrax_debug(void)
{
static int first = 1;
if (!first) {
unregister_console(&ser_console);
register_console(&ser0_console);
register_console(&ser1_console);
register_console(&ser2_console);
register_console(&ser3_console);
init_dummy_console();
return 0;
}
first = 0;
register_console(&ser_console);
start_port(port);
#ifdef CONFIG_ETRAX_KGDB
start_port(kgdb_port);
#endif
return 0;
}
