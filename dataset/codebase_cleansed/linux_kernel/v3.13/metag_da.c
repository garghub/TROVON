static int chancall(int in_bios_function, int in_channel,
int in_arg2, void *in_arg3,
void *in_arg4)
{
register int bios_function asm("D1Ar1") = in_bios_function;
register int channel asm("D0Ar2") = in_channel;
register int arg2 asm("D1Ar3") = in_arg2;
register void *arg3 asm("D0Ar4") = in_arg3;
register void *arg4 asm("D1Ar5") = in_arg4;
register int bios_call asm("D0Ar6") = 3;
register int result asm("D0Re0");
asm volatile (
"MSETL [A0StP++], %6,%4,%2\n\t"
"ADD A0StP, A0StP, #8\n\t"
"SWITCH #0x0C30208\n\t"
"GETD %0, [A0StP+#-8]\n\t"
"SUB A0StP, A0StP, #(4*6)+8\n\t"
: "=d" (result)
: "d" (bios_function),
"d" (channel),
"d" (arg2),
"d" (arg3),
"d" (arg4),
"d" (bios_call)
: "memory");
return result;
}
static int fetch_data(unsigned int channel)
{
struct dashtty_port *dport = &dashtty_ports[channel];
int received = 0;
spin_lock_bh(&dport->rx_lock);
if (!dport->rx_buf)
goto unlock;
if (chancall(RDBUF, channel, RX_BUF_SIZE,
(void *)dport->rx_buf, &received) == CONAOK) {
if (received) {
int space;
unsigned char *cbuf;
space = tty_prepare_flip_string(&dport->port, &cbuf,
received);
if (space <= 0)
goto unlock;
memcpy(cbuf, dport->rx_buf, space);
tty_flip_buffer_push(&dport->port);
}
}
unlock:
spin_unlock_bh(&dport->rx_lock);
return received;
}
static int find_channel_to_poll(void)
{
static int last_polled_channel;
int last = last_polled_channel;
int chan;
struct dashtty_port *dport;
for (chan = last + 1; ; ++chan) {
if (chan >= NUM_TTY_CHANNELS)
chan = 0;
dport = &dashtty_ports[chan];
if (dport->rx_buf) {
last_polled_channel = chan;
return chan;
}
if (chan == last)
break;
}
return -1;
}
static int put_channel_data(unsigned int chan)
{
struct dashtty_port *dport;
struct tty_struct *tty;
int number_written;
unsigned int count = 0;
dport = &dashtty_ports[chan];
mutex_lock(&dport->xmit_lock);
if (dport->xmit_cnt) {
count = min((unsigned int)(SERIAL_XMIT_SIZE - dport->xmit_tail),
dport->xmit_cnt);
chancall(WRBUF, chan, count,
dport->port.xmit_buf + dport->xmit_tail,
&number_written);
dport->xmit_cnt -= number_written;
if (!dport->xmit_cnt) {
dport->xmit_head = 0;
dport->xmit_tail = 0;
complete(&dport->xmit_empty);
} else {
dport->xmit_tail += number_written;
if (dport->xmit_tail >= SERIAL_XMIT_SIZE)
dport->xmit_tail -= SERIAL_XMIT_SIZE;
}
atomic_sub(number_written, &dashtty_xmit_cnt);
}
mutex_unlock(&dport->xmit_lock);
if (count && number_written) {
tty = tty_port_tty_get(&dport->port);
if (tty) {
tty_wakeup(tty);
tty_kref_put(tty);
}
}
return count && !number_written;
}
static int put_data(void *arg)
{
unsigned int chan, stall;
__set_current_state(TASK_RUNNING);
while (!kthread_should_stop()) {
stall = 0;
for (chan = 0; chan < NUM_TTY_CHANNELS; ++chan)
stall += put_channel_data(chan);
if (stall)
msleep(25);
wait_event_interruptible(dashtty_waitqueue,
atomic_read(&dashtty_xmit_cnt));
}
return 0;
}
static void dashtty_timer(unsigned long ignored)
{
int channel;
if (!atomic_read(&num_channels_need_poll))
return;
channel = find_channel_to_poll();
if (channel >= 0)
fetch_data(channel);
mod_timer_pinned(&poll_timer, jiffies + DA_TTY_POLL);
}
static void add_poll_timer(struct timer_list *poll_timer)
{
setup_timer(poll_timer, dashtty_timer, 0);
poll_timer->expires = jiffies + DA_TTY_POLL;
add_timer_on(poll_timer, 0);
}
static int dashtty_port_activate(struct tty_port *port, struct tty_struct *tty)
{
struct dashtty_port *dport = container_of(port, struct dashtty_port,
port);
void *rx_buf;
if (tty_port_alloc_xmit_buf(port) < 0)
goto err;
rx_buf = kzalloc(RX_BUF_SIZE, GFP_KERNEL);
if (!rx_buf)
goto err_free_xmit;
spin_lock_bh(&dport->rx_lock);
dport->rx_buf = rx_buf;
spin_unlock_bh(&dport->rx_lock);
if (dport != &dashtty_ports[CONSOLE_CHANNEL])
if (atomic_inc_return(&num_channels_need_poll) == 1)
add_poll_timer(&poll_timer);
return 0;
err_free_xmit:
tty_port_free_xmit_buf(port);
err:
return -ENOMEM;
}
static void dashtty_port_shutdown(struct tty_port *port)
{
struct dashtty_port *dport = container_of(port, struct dashtty_port,
port);
void *rx_buf;
unsigned int count;
if (dport != &dashtty_ports[CONSOLE_CHANNEL])
if (atomic_dec_and_test(&num_channels_need_poll))
del_timer_sync(&poll_timer);
mutex_lock(&dport->xmit_lock);
count = dport->xmit_cnt;
mutex_unlock(&dport->xmit_lock);
if (count) {
del_timer(&put_timer);
wake_up_interruptible(&dashtty_waitqueue);
wait_for_completion(&dport->xmit_empty);
}
spin_lock_bh(&dport->rx_lock);
rx_buf = dport->rx_buf;
dport->rx_buf = NULL;
spin_unlock_bh(&dport->rx_lock);
kfree(rx_buf);
tty_port_free_xmit_buf(port);
}
static int dashtty_install(struct tty_driver *driver, struct tty_struct *tty)
{
return tty_port_install(&dashtty_ports[tty->index].port, driver, tty);
}
static int dashtty_open(struct tty_struct *tty, struct file *filp)
{
return tty_port_open(tty->port, tty, filp);
}
static void dashtty_close(struct tty_struct *tty, struct file *filp)
{
return tty_port_close(tty->port, tty, filp);
}
static void dashtty_hangup(struct tty_struct *tty)
{
int channel;
struct dashtty_port *dport;
channel = tty->index;
dport = &dashtty_ports[channel];
mutex_lock(&dport->xmit_lock);
if (dport->xmit_cnt) {
atomic_sub(dport->xmit_cnt, &dashtty_xmit_cnt);
dport->xmit_cnt = 0;
dport->xmit_head = 0;
dport->xmit_tail = 0;
complete(&dport->xmit_empty);
}
mutex_unlock(&dport->xmit_lock);
tty_port_hangup(tty->port);
}
static void dashtty_put_timer(unsigned long ignored)
{
if (atomic_read(&dashtty_xmit_cnt))
wake_up_interruptible(&dashtty_waitqueue);
}
static int dashtty_write(struct tty_struct *tty, const unsigned char *buf,
int total)
{
int channel, count, block;
struct dashtty_port *dport;
channel = tty->index;
dport = &dashtty_ports[channel];
mutex_lock(&dport->xmit_lock);
total = min(total, (int)(SERIAL_XMIT_SIZE - dport->xmit_cnt));
atomic_add(total, &dashtty_xmit_cnt);
dport->xmit_cnt += total;
for (count = total; count; count -= block) {
block = min(count, (int)(SERIAL_XMIT_SIZE - dport->xmit_head));
memcpy(dport->port.xmit_buf + dport->xmit_head, buf, block);
dport->xmit_head += block;
if (dport->xmit_head >= SERIAL_XMIT_SIZE)
dport->xmit_head -= SERIAL_XMIT_SIZE;
buf += block;
}
count = dport->xmit_cnt;
if (count)
reinit_completion(&dport->xmit_empty);
mutex_unlock(&dport->xmit_lock);
if (total) {
if (count == SERIAL_XMIT_SIZE) {
del_timer(&put_timer);
wake_up_interruptible(&dashtty_waitqueue);
} else {
mod_timer(&put_timer, jiffies + DA_TTY_PUT_DELAY);
}
}
return total;
}
static int dashtty_write_room(struct tty_struct *tty)
{
struct dashtty_port *dport;
int channel;
int room;
channel = tty->index;
dport = &dashtty_ports[channel];
mutex_lock(&dport->xmit_lock);
room = SERIAL_XMIT_SIZE - dport->xmit_cnt;
mutex_unlock(&dport->xmit_lock);
return room;
}
static int dashtty_chars_in_buffer(struct tty_struct *tty)
{
struct dashtty_port *dport;
int channel;
int chars;
channel = tty->index;
dport = &dashtty_ports[channel];
mutex_lock(&dport->xmit_lock);
chars = dport->xmit_cnt;
mutex_unlock(&dport->xmit_lock);
return chars;
}
static int __init dashtty_init(void)
{
int ret;
int nport;
struct dashtty_port *dport;
if (!metag_da_enabled())
return -ENODEV;
channel_driver = tty_alloc_driver(NUM_TTY_CHANNELS,
TTY_DRIVER_REAL_RAW);
if (IS_ERR(channel_driver))
return PTR_ERR(channel_driver);
channel_driver->driver_name = "metag_da";
channel_driver->name = "ttyDA";
channel_driver->major = DA_TTY_MAJOR;
channel_driver->minor_start = 0;
channel_driver->type = TTY_DRIVER_TYPE_SERIAL;
channel_driver->subtype = SERIAL_TYPE_NORMAL;
channel_driver->init_termios = tty_std_termios;
channel_driver->init_termios.c_cflag |= CLOCAL;
tty_set_operations(channel_driver, &dashtty_ops);
for (nport = 0; nport < NUM_TTY_CHANNELS; nport++) {
dport = &dashtty_ports[nport];
tty_port_init(&dport->port);
dport->port.ops = &dashtty_port_ops;
spin_lock_init(&dport->rx_lock);
mutex_init(&dport->xmit_lock);
init_completion(&dport->xmit_empty);
complete(&dport->xmit_empty);
}
setup_timer(&put_timer, dashtty_put_timer, 0);
init_waitqueue_head(&dashtty_waitqueue);
dashtty_thread = kthread_create(put_data, NULL, "ttyDA");
if (IS_ERR(dashtty_thread)) {
pr_err("Couldn't create dashtty thread\n");
ret = PTR_ERR(dashtty_thread);
goto err_destroy_ports;
}
kthread_bind(dashtty_thread, 0);
wake_up_process(dashtty_thread);
ret = tty_register_driver(channel_driver);
if (ret < 0) {
pr_err("Couldn't install dashtty driver: err %d\n",
ret);
goto err_stop_kthread;
}
return 0;
err_stop_kthread:
kthread_stop(dashtty_thread);
err_destroy_ports:
for (nport = 0; nport < NUM_TTY_CHANNELS; nport++) {
dport = &dashtty_ports[nport];
tty_port_destroy(&dport->port);
}
put_tty_driver(channel_driver);
return ret;
}
static void dashtty_exit(void)
{
int nport;
struct dashtty_port *dport;
del_timer_sync(&put_timer);
kthread_stop(dashtty_thread);
del_timer_sync(&poll_timer);
tty_unregister_driver(channel_driver);
for (nport = 0; nport < NUM_TTY_CHANNELS; nport++) {
dport = &dashtty_ports[nport];
tty_port_destroy(&dport->port);
}
put_tty_driver(channel_driver);
}
static void dash_console_write(struct console *co, const char *s,
unsigned int count)
{
int actually_written;
chancall(WRBUF, CONSOLE_CHANNEL, count, (void *)s, &actually_written);
}
static struct tty_driver *dash_console_device(struct console *c, int *index)
{
*index = c->index;
return channel_driver;
}
