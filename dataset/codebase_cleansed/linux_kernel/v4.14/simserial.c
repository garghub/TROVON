static void receive_chars(struct tty_port *port)
{
unsigned char ch;
static unsigned char seen_esc = 0;
while ( (ch = ia64_ssc(0, 0, 0, 0, SSC_GETCHAR)) ) {
if (ch == 27 && seen_esc == 0) {
seen_esc = 1;
continue;
} else if (seen_esc == 1 && ch == 'O') {
seen_esc = 2;
continue;
} else if (seen_esc == 2) {
if (ch == 'P')
show_state();
#ifdef CONFIG_MAGIC_SYSRQ
if (ch == 'S') {
do {
ch = ia64_ssc(0, 0, 0, 0, SSC_GETCHAR);
} while (!ch);
handle_sysrq(ch);
}
#endif
seen_esc = 0;
continue;
}
seen_esc = 0;
if (tty_insert_flip_char(port, ch, TTY_NORMAL) == 0)
break;
}
tty_flip_buffer_push(port);
}
static irqreturn_t rs_interrupt_single(int irq, void *dev_id)
{
struct serial_state *info = dev_id;
receive_chars(&info->port);
return IRQ_HANDLED;
}
static int rs_put_char(struct tty_struct *tty, unsigned char ch)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (!info->xmit.buf)
return 0;
local_irq_save(flags);
if (CIRC_SPACE(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE) == 0) {
local_irq_restore(flags);
return 0;
}
info->xmit.buf[info->xmit.head] = ch;
info->xmit.head = (info->xmit.head + 1) & (SERIAL_XMIT_SIZE-1);
local_irq_restore(flags);
return 1;
}
static void transmit_chars(struct tty_struct *tty, struct serial_state *info,
int *intr_done)
{
int count;
unsigned long flags;
local_irq_save(flags);
if (info->x_char) {
char c = info->x_char;
console->write(console, &c, 1);
info->x_char = 0;
goto out;
}
if (info->xmit.head == info->xmit.tail || tty->stopped) {
#ifdef SIMSERIAL_DEBUG
printk("transmit_chars: head=%d, tail=%d, stopped=%d\n",
info->xmit.head, info->xmit.tail, tty->stopped);
#endif
goto out;
}
count = min(CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE),
SERIAL_XMIT_SIZE - info->xmit.tail);
console->write(console, info->xmit.buf+info->xmit.tail, count);
info->xmit.tail = (info->xmit.tail+count) & (SERIAL_XMIT_SIZE-1);
count = CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
if (count) {
console->write(console, info->xmit.buf, count);
info->xmit.tail += count;
}
out:
local_irq_restore(flags);
}
static void rs_flush_chars(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
if (info->xmit.head == info->xmit.tail || tty->stopped ||
!info->xmit.buf)
return;
transmit_chars(tty, info, NULL);
}
static int rs_write(struct tty_struct * tty,
const unsigned char *buf, int count)
{
struct serial_state *info = tty->driver_data;
int c, ret = 0;
unsigned long flags;
if (!info->xmit.buf)
return 0;
local_irq_save(flags);
while (1) {
c = CIRC_SPACE_TO_END(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
if (count < c)
c = count;
if (c <= 0) {
break;
}
memcpy(info->xmit.buf + info->xmit.head, buf, c);
info->xmit.head = ((info->xmit.head + c) &
(SERIAL_XMIT_SIZE-1));
buf += c;
count -= c;
ret += c;
}
local_irq_restore(flags);
if (CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE) &&
!tty->stopped)
transmit_chars(tty, info, NULL);
return ret;
}
static int rs_write_room(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
return CIRC_SPACE(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static int rs_chars_in_buffer(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
return CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static void rs_flush_buffer(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
local_irq_save(flags);
info->xmit.head = info->xmit.tail = 0;
local_irq_restore(flags);
tty_wakeup(tty);
}
static void rs_send_xchar(struct tty_struct *tty, char ch)
{
struct serial_state *info = tty->driver_data;
info->x_char = ch;
if (ch) {
transmit_chars(tty, info, NULL);
}
}
static void rs_throttle(struct tty_struct * tty)
{
if (I_IXOFF(tty))
rs_send_xchar(tty, STOP_CHAR(tty));
printk(KERN_INFO "simrs_throttle called\n");
}
static void rs_unthrottle(struct tty_struct * tty)
{
struct serial_state *info = tty->driver_data;
if (I_IXOFF(tty)) {
if (info->x_char)
info->x_char = 0;
else
rs_send_xchar(tty, START_CHAR(tty));
}
printk(KERN_INFO "simrs_unthrottle called\n");
}
static int rs_ioctl(struct tty_struct *tty, unsigned int cmd, unsigned long arg)
{
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != TIOCSERCONFIG) && (cmd != TIOCSERGSTRUCT) &&
(cmd != TIOCMIWAIT)) {
if (tty_io_error(tty))
return -EIO;
}
switch (cmd) {
case TIOCGSERIAL:
case TIOCSSERIAL:
case TIOCSERGSTRUCT:
case TIOCMIWAIT:
return 0;
case TIOCSERCONFIG:
case TIOCSERGETLSR:
return -EINVAL;
case TIOCSERGWILD:
case TIOCSERSWILD:
printk (KERN_INFO "TIOCSER?WILD ioctl obsolete, ignored.\n");
return 0;
}
return -ENOIOCTLCMD;
}
static void shutdown(struct tty_port *port)
{
struct serial_state *info = container_of(port, struct serial_state,
port);
unsigned long flags;
local_irq_save(flags);
if (info->irq)
free_irq(info->irq, info);
if (info->xmit.buf) {
free_page((unsigned long) info->xmit.buf);
info->xmit.buf = NULL;
}
local_irq_restore(flags);
}
static void rs_close(struct tty_struct *tty, struct file * filp)
{
struct serial_state *info = tty->driver_data;
tty_port_close(&info->port, tty, filp);
}
static void rs_hangup(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
rs_flush_buffer(tty);
tty_port_hangup(&info->port);
}
static int activate(struct tty_port *port, struct tty_struct *tty)
{
struct serial_state *state = container_of(port, struct serial_state,
port);
unsigned long flags, page;
int retval = 0;
page = get_zeroed_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
local_irq_save(flags);
if (state->xmit.buf)
free_page(page);
else
state->xmit.buf = (unsigned char *) page;
if (state->irq) {
retval = request_irq(state->irq, rs_interrupt_single, 0,
"simserial", state);
if (retval)
goto errout;
}
state->xmit.head = state->xmit.tail = 0;
errout:
local_irq_restore(flags);
return retval;
}
static int rs_open(struct tty_struct *tty, struct file * filp)
{
struct serial_state *info = rs_table + tty->index;
struct tty_port *port = &info->port;
tty->driver_data = info;
port->low_latency = (port->flags & ASYNC_LOW_LATENCY) ? 1 : 0;
console = console_drivers;
while (console) {
if ((console->flags & CON_ENABLED) && console->write) break;
console = console->next;
}
return tty_port_open(port, tty, filp);
}
static int rs_proc_show(struct seq_file *m, void *v)
{
int i;
seq_printf(m, "simserinfo:1.0\n");
for (i = 0; i < NR_PORTS; i++)
seq_printf(m, "%d: uart:16550 port:3F8 irq:%d\n",
i, rs_table[i].irq);
return 0;
}
static int rs_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, rs_proc_show, NULL);
}
static int __init simrs_init(void)
{
struct serial_state *state;
int retval;
if (!ia64_platform_is("hpsim"))
return -ENODEV;
hp_simserial_driver = alloc_tty_driver(NR_PORTS);
if (!hp_simserial_driver)
return -ENOMEM;
printk(KERN_INFO "SimSerial driver with no serial options enabled\n");
hp_simserial_driver->driver_name = "simserial";
hp_simserial_driver->name = "ttyS";
hp_simserial_driver->major = TTY_MAJOR;
hp_simserial_driver->minor_start = 64;
hp_simserial_driver->type = TTY_DRIVER_TYPE_SERIAL;
hp_simserial_driver->subtype = SERIAL_TYPE_NORMAL;
hp_simserial_driver->init_termios = tty_std_termios;
hp_simserial_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
hp_simserial_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(hp_simserial_driver, &hp_ops);
state = rs_table;
tty_port_init(&state->port);
state->port.ops = &hp_port_ops;
state->port.close_delay = 0;
retval = hpsim_get_irq(KEYBOARD_INTR);
if (retval < 0) {
printk(KERN_ERR "%s: out of interrupt vectors!\n",
__func__);
goto err_free_tty;
}
state->irq = retval;
printk(KERN_INFO "ttyS0 at 0x03f8 (irq = %d) is a 16550\n", state->irq);
tty_port_link_device(&state->port, hp_simserial_driver, 0);
retval = tty_register_driver(hp_simserial_driver);
if (retval) {
printk(KERN_ERR "Couldn't register simserial driver\n");
goto err_free_tty;
}
return 0;
err_free_tty:
put_tty_driver(hp_simserial_driver);
tty_port_destroy(&state->port);
return retval;
}
