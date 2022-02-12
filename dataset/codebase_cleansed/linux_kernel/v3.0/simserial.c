static void rs_stop(struct tty_struct *tty)
{
#ifdef SIMSERIAL_DEBUG
printk("rs_stop: tty->stopped=%d tty->hw_stopped=%d tty->flow_stopped=%d\n",
tty->stopped, tty->hw_stopped, tty->flow_stopped);
#endif
}
static void rs_start(struct tty_struct *tty)
{
#ifdef SIMSERIAL_DEBUG
printk("rs_start: tty->stopped=%d tty->hw_stopped=%d tty->flow_stopped=%d\n",
tty->stopped, tty->hw_stopped, tty->flow_stopped);
#endif
}
static void receive_chars(struct tty_struct *tty)
{
unsigned char ch;
static unsigned char seen_esc = 0;
while ( (ch = ia64_ssc(0, 0, 0, 0, SSC_GETCHAR)) ) {
if ( ch == 27 && seen_esc == 0 ) {
seen_esc = 1;
continue;
} else {
if ( seen_esc==1 && ch == 'O' ) {
seen_esc = 2;
continue;
} else if ( seen_esc == 2 ) {
if ( ch == 'P' )
show_state();
#ifdef CONFIG_MAGIC_SYSRQ
if ( ch == 'S' ) {
do
ch = ia64_ssc(0, 0, 0, 0,
SSC_GETCHAR);
while (!ch);
handle_sysrq(ch);
}
#endif
seen_esc = 0;
continue;
}
}
seen_esc = 0;
if (tty_insert_flip_char(tty, ch, TTY_NORMAL) == 0)
break;
}
tty_flip_buffer_push(tty);
}
static irqreturn_t rs_interrupt_single(int irq, void *dev_id)
{
struct async_struct * info;
info = IRQ_ports[irq];
if (!info || !info->tty) {
printk(KERN_INFO "simrs_interrupt_single: info|tty=0 info=%p problem\n", info);
return IRQ_NONE;
}
receive_chars(info->tty);
return IRQ_HANDLED;
}
static void do_softint(struct work_struct *private_)
{
printk(KERN_ERR "simserial: do_softint called\n");
}
static int rs_put_char(struct tty_struct *tty, unsigned char ch)
{
struct async_struct *info = (struct async_struct *)tty->driver_data;
unsigned long flags;
if (!tty || !info->xmit.buf)
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
static void transmit_chars(struct async_struct *info, int *intr_done)
{
int count;
unsigned long flags;
local_irq_save(flags);
if (info->x_char) {
char c = info->x_char;
console->write(console, &c, 1);
info->state->icount.tx++;
info->x_char = 0;
goto out;
}
if (info->xmit.head == info->xmit.tail || info->tty->stopped || info->tty->hw_stopped) {
#ifdef SIMSERIAL_DEBUG
printk("transmit_chars: head=%d, tail=%d, stopped=%d\n",
info->xmit.head, info->xmit.tail, info->tty->stopped);
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
struct async_struct *info = (struct async_struct *)tty->driver_data;
if (info->xmit.head == info->xmit.tail || tty->stopped || tty->hw_stopped ||
!info->xmit.buf)
return;
transmit_chars(info, NULL);
}
static int rs_write(struct tty_struct * tty,
const unsigned char *buf, int count)
{
int c, ret = 0;
struct async_struct *info = (struct async_struct *)tty->driver_data;
unsigned long flags;
if (!tty || !info->xmit.buf || !tmp_buf) return 0;
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
if (CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE)
&& !tty->stopped && !tty->hw_stopped) {
transmit_chars(info, NULL);
}
return ret;
}
static int rs_write_room(struct tty_struct *tty)
{
struct async_struct *info = (struct async_struct *)tty->driver_data;
return CIRC_SPACE(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static int rs_chars_in_buffer(struct tty_struct *tty)
{
struct async_struct *info = (struct async_struct *)tty->driver_data;
return CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static void rs_flush_buffer(struct tty_struct *tty)
{
struct async_struct *info = (struct async_struct *)tty->driver_data;
unsigned long flags;
local_irq_save(flags);
info->xmit.head = info->xmit.tail = 0;
local_irq_restore(flags);
tty_wakeup(tty);
}
static void rs_send_xchar(struct tty_struct *tty, char ch)
{
struct async_struct *info = (struct async_struct *)tty->driver_data;
info->x_char = ch;
if (ch) {
transmit_chars(info, NULL);
}
}
static void rs_throttle(struct tty_struct * tty)
{
if (I_IXOFF(tty)) rs_send_xchar(tty, STOP_CHAR(tty));
printk(KERN_INFO "simrs_throttle called\n");
}
static void rs_unthrottle(struct tty_struct * tty)
{
struct async_struct *info = (struct async_struct *)tty->driver_data;
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
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
}
switch (cmd) {
case TIOCGSERIAL:
printk(KERN_INFO "simrs_ioctl TIOCGSERIAL called\n");
return 0;
case TIOCSSERIAL:
printk(KERN_INFO "simrs_ioctl TIOCSSERIAL called\n");
return 0;
case TIOCSERCONFIG:
printk(KERN_INFO "rs_ioctl: TIOCSERCONFIG called\n");
return -EINVAL;
case TIOCSERGETLSR:
printk(KERN_INFO "rs_ioctl: TIOCSERGETLSR called\n");
return -EINVAL;
case TIOCSERGSTRUCT:
printk(KERN_INFO "rs_ioctl: TIOCSERGSTRUCT called\n");
#if 0
if (copy_to_user((struct async_struct *) arg,
info, sizeof(struct async_struct)))
return -EFAULT;
#endif
return 0;
case TIOCMIWAIT:
printk(KERN_INFO "rs_ioctl: TIOCMIWAIT: called\n");
return 0;
case TIOCSERGWILD:
case TIOCSERSWILD:
printk (KERN_INFO "TIOCSER?WILD ioctl obsolete, ignored.\n");
return 0;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void rs_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios->c_cflag & CRTSCTS)) {
tty->hw_stopped = 0;
rs_start(tty);
}
}
static void shutdown(struct async_struct * info)
{
unsigned long flags;
struct serial_state *state;
int retval;
if (!(info->flags & ASYNC_INITIALIZED)) return;
state = info->state;
#ifdef SIMSERIAL_DEBUG
printk("Shutting down serial port %d (irq %d)....", info->line,
state->irq);
#endif
local_irq_save(flags);
{
if (info->next_port)
info->next_port->prev_port = info->prev_port;
if (info->prev_port)
info->prev_port->next_port = info->next_port;
else
IRQ_ports[state->irq] = info->next_port;
if (state->irq && (!IRQ_ports[state->irq] ||
!IRQ_ports[state->irq]->next_port)) {
if (IRQ_ports[state->irq]) {
free_irq(state->irq, NULL);
retval = request_irq(state->irq, rs_interrupt_single,
IRQ_T(info), "serial", NULL);
if (retval)
printk(KERN_ERR "serial shutdown: request_irq: error %d"
" Couldn't reacquire IRQ.\n", retval);
} else
free_irq(state->irq, NULL);
}
if (info->xmit.buf) {
free_page((unsigned long) info->xmit.buf);
info->xmit.buf = NULL;
}
if (info->tty) set_bit(TTY_IO_ERROR, &info->tty->flags);
info->flags &= ~ASYNC_INITIALIZED;
}
local_irq_restore(flags);
}
static void rs_close(struct tty_struct *tty, struct file * filp)
{
struct async_struct * info = (struct async_struct *)tty->driver_data;
struct serial_state *state;
unsigned long flags;
if (!info ) return;
state = info->state;
local_irq_save(flags);
if (tty_hung_up_p(filp)) {
#ifdef SIMSERIAL_DEBUG
printk("rs_close: hung_up\n");
#endif
local_irq_restore(flags);
return;
}
#ifdef SIMSERIAL_DEBUG
printk("rs_close ttys%d, count = %d\n", info->line, state->count);
#endif
if ((tty->count == 1) && (state->count != 1)) {
printk(KERN_ERR "rs_close: bad serial port count; tty->count is 1, "
"state->count is %d\n", state->count);
state->count = 1;
}
if (--state->count < 0) {
printk(KERN_ERR "rs_close: bad serial port count for ttys%d: %d\n",
info->line, state->count);
state->count = 0;
}
if (state->count) {
local_irq_restore(flags);
return;
}
info->flags |= ASYNC_CLOSING;
local_irq_restore(flags);
shutdown(info);
rs_flush_buffer(tty);
tty_ldisc_flush(tty);
info->event = 0;
info->tty = NULL;
if (info->blocked_open) {
if (info->close_delay)
schedule_timeout_interruptible(info->close_delay);
wake_up_interruptible(&info->open_wait);
}
info->flags &= ~(ASYNC_NORMAL_ACTIVE|ASYNC_CLOSING);
wake_up_interruptible(&info->close_wait);
}
static void rs_wait_until_sent(struct tty_struct *tty, int timeout)
{
}
static void rs_hangup(struct tty_struct *tty)
{
struct async_struct * info = (struct async_struct *)tty->driver_data;
struct serial_state *state = info->state;
#ifdef SIMSERIAL_DEBUG
printk("rs_hangup: called\n");
#endif
state = info->state;
rs_flush_buffer(tty);
if (info->flags & ASYNC_CLOSING)
return;
shutdown(info);
info->event = 0;
state->count = 0;
info->flags &= ~ASYNC_NORMAL_ACTIVE;
info->tty = NULL;
wake_up_interruptible(&info->open_wait);
}
static int get_async_struct(int line, struct async_struct **ret_info)
{
struct async_struct *info;
struct serial_state *sstate;
sstate = rs_table + line;
sstate->count++;
if (sstate->info) {
*ret_info = sstate->info;
return 0;
}
info = kzalloc(sizeof(struct async_struct), GFP_KERNEL);
if (!info) {
sstate->count--;
return -ENOMEM;
}
init_waitqueue_head(&info->open_wait);
init_waitqueue_head(&info->close_wait);
init_waitqueue_head(&info->delta_msr_wait);
info->magic = SERIAL_MAGIC;
info->port = sstate->port;
info->flags = sstate->flags;
info->xmit_fifo_size = sstate->xmit_fifo_size;
info->line = line;
INIT_WORK(&info->work, do_softint);
info->state = sstate;
if (sstate->info) {
kfree(info);
*ret_info = sstate->info;
return 0;
}
*ret_info = sstate->info = info;
return 0;
}
static int
startup(struct async_struct *info)
{
unsigned long flags;
int retval=0;
irq_handler_t handler;
struct serial_state *state= info->state;
unsigned long page;
page = get_zeroed_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
local_irq_save(flags);
if (info->flags & ASYNC_INITIALIZED) {
free_page(page);
goto errout;
}
if (!state->port || !state->type) {
if (info->tty) set_bit(TTY_IO_ERROR, &info->tty->flags);
free_page(page);
goto errout;
}
if (info->xmit.buf)
free_page(page);
else
info->xmit.buf = (unsigned char *) page;
#ifdef SIMSERIAL_DEBUG
printk("startup: ttys%d (irq %d)...", info->line, state->irq);
#endif
if (state->irq && (!IRQ_ports[state->irq] ||
!IRQ_ports[state->irq]->next_port)) {
if (IRQ_ports[state->irq]) {
retval = -EBUSY;
goto errout;
} else
handler = rs_interrupt_single;
retval = request_irq(state->irq, handler, IRQ_T(info), "simserial", NULL);
if (retval) {
if (capable(CAP_SYS_ADMIN)) {
if (info->tty)
set_bit(TTY_IO_ERROR,
&info->tty->flags);
retval = 0;
}
goto errout;
}
}
info->prev_port = NULL;
info->next_port = IRQ_ports[state->irq];
if (info->next_port)
info->next_port->prev_port = info;
IRQ_ports[state->irq] = info;
if (info->tty) clear_bit(TTY_IO_ERROR, &info->tty->flags);
info->xmit.head = info->xmit.tail = 0;
#if 0
timer_table[RS_TIMER].expires = jiffies + 2*HZ/100;
timer_active |= 1 << RS_TIMER;
#endif
if (info->tty) {
if ((info->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
info->tty->alt_speed = 57600;
if ((info->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
info->tty->alt_speed = 115200;
if ((info->flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
info->tty->alt_speed = 230400;
if ((info->flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
info->tty->alt_speed = 460800;
}
info->flags |= ASYNC_INITIALIZED;
local_irq_restore(flags);
return 0;
errout:
local_irq_restore(flags);
return retval;
}
static int rs_open(struct tty_struct *tty, struct file * filp)
{
struct async_struct *info;
int retval, line;
unsigned long page;
line = tty->index;
if ((line < 0) || (line >= NR_PORTS))
return -ENODEV;
retval = get_async_struct(line, &info);
if (retval)
return retval;
tty->driver_data = info;
info->tty = tty;
#ifdef SIMSERIAL_DEBUG
printk("rs_open %s, count = %d\n", tty->name, info->state->count);
#endif
info->tty->low_latency = (info->flags & ASYNC_LOW_LATENCY) ? 1 : 0;
if (!tmp_buf) {
page = get_zeroed_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
if (tmp_buf)
free_page(page);
else
tmp_buf = (unsigned char *) page;
}
if (tty_hung_up_p(filp) ||
(info->flags & ASYNC_CLOSING)) {
if (info->flags & ASYNC_CLOSING)
interruptible_sleep_on(&info->close_wait);
#ifdef SERIAL_DO_RESTART
return ((info->flags & ASYNC_HUP_NOTIFY) ?
-EAGAIN : -ERESTARTSYS);
#else
return -EAGAIN;
#endif
}
retval = startup(info);
if (retval) {
return retval;
}
console = console_drivers;
while (console) {
if ((console->flags & CON_ENABLED) && console->write) break;
console = console->next;
}
#ifdef SIMSERIAL_DEBUG
printk("rs_open ttys%d successful\n", info->line);
#endif
return 0;
}
static inline void line_info(struct seq_file *m, struct serial_state *state)
{
seq_printf(m, "%d: uart:%s port:%lX irq:%d\n",
state->line, uart_config[state->type].name,
state->port, state->irq);
}
static int rs_proc_show(struct seq_file *m, void *v)
{
int i;
seq_printf(m, "simserinfo:1.0 driver:%s\n", serial_version);
for (i = 0; i < NR_PORTS; i++)
line_info(m, &rs_table[i]);
return 0;
}
static int rs_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, rs_proc_show, NULL);
}
static inline void show_serial_version(void)
{
printk(KERN_INFO "%s version %s with", serial_name, serial_version);
printk(KERN_INFO " no serial options enabled\n");
}
static int __init
simrs_init (void)
{
int i, rc;
struct serial_state *state;
if (!ia64_platform_is("hpsim"))
return -ENODEV;
hp_simserial_driver = alloc_tty_driver(1);
if (!hp_simserial_driver)
return -ENOMEM;
show_serial_version();
hp_simserial_driver->owner = THIS_MODULE;
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
for (i = 0, state = rs_table; i < NR_PORTS; i++,state++) {
if (state->type == PORT_UNKNOWN) continue;
if (!state->irq) {
if ((rc = assign_irq_vector(AUTO_ASSIGN)) < 0)
panic("%s: out of interrupt vectors!\n",
__func__);
state->irq = rc;
ia64_ssc_connect_irq(KEYBOARD_INTR, state->irq);
}
printk(KERN_INFO "ttyS%d at 0x%04lx (irq = %d) is a %s\n",
state->line,
state->port, state->irq,
uart_config[state->type].name);
}
if (tty_register_driver(hp_simserial_driver))
panic("Couldn't register simserial driver\n");
return 0;
}
