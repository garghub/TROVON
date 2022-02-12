static struct hvc_struct *hvc_get_by_index(int index)
{
struct hvc_struct *hp;
unsigned long flags;
spin_lock(&hvc_structs_lock);
list_for_each_entry(hp, &hvc_structs, next) {
spin_lock_irqsave(&hp->lock, flags);
if (hp->index == index) {
tty_port_get(&hp->port);
spin_unlock_irqrestore(&hp->lock, flags);
spin_unlock(&hvc_structs_lock);
return hp;
}
spin_unlock_irqrestore(&hp->lock, flags);
}
hp = NULL;
spin_unlock(&hvc_structs_lock);
return hp;
}
static void hvc_console_print(struct console *co, const char *b,
unsigned count)
{
char c[N_OUTBUF] __ALIGNED__;
unsigned i = 0, n = 0;
int r, donecr = 0, index = co->index;
if (index >= MAX_NR_HVC_CONSOLES)
return;
if (vtermnos[index] == -1)
return;
while (count > 0 || i > 0) {
if (count > 0 && i < sizeof(c)) {
if (b[n] == '\n' && !donecr) {
c[i++] = '\r';
donecr = 1;
} else {
c[i++] = b[n++];
donecr = 0;
--count;
}
} else {
r = cons_ops[index]->put_chars(vtermnos[index], c, i);
if (r <= 0) {
if (r != -EAGAIN)
i = 0;
} else if (r > 0) {
i -= r;
if (i > 0)
memmove(c, c+r, i);
}
}
}
}
static struct tty_driver *hvc_console_device(struct console *c, int *index)
{
if (vtermnos[c->index] == -1)
return NULL;
*index = c->index;
return hvc_driver;
}
static int hvc_console_setup(struct console *co, char *options)
{
if (co->index < 0 || co->index >= MAX_NR_HVC_CONSOLES)
return -ENODEV;
if (vtermnos[co->index] == -1)
return -ENODEV;
return 0;
}
static int __init hvc_console_init(void)
{
register_console(&hvc_console);
return 0;
}
static void hvc_port_destruct(struct tty_port *port)
{
struct hvc_struct *hp = container_of(port, struct hvc_struct, port);
unsigned long flags;
spin_lock(&hvc_structs_lock);
spin_lock_irqsave(&hp->lock, flags);
list_del(&(hp->next));
spin_unlock_irqrestore(&hp->lock, flags);
spin_unlock(&hvc_structs_lock);
kfree(hp);
}
static void hvc_check_console(int index)
{
if (hvc_console.flags & CON_ENABLED)
return;
if (index == hvc_console.index)
register_console(&hvc_console);
}
int hvc_instantiate(uint32_t vtermno, int index, const struct hv_ops *ops)
{
struct hvc_struct *hp;
if (index < 0 || index >= MAX_NR_HVC_CONSOLES)
return -1;
if (vtermnos[index] != -1)
return -1;
hp = hvc_get_by_index(index);
if (hp) {
tty_port_put(&hp->port);
return -1;
}
vtermnos[index] = vtermno;
cons_ops[index] = ops;
if (last_hvc < index)
last_hvc = index;
hvc_check_console(index);
return 0;
}
void hvc_kick(void)
{
hvc_kicked = 1;
wake_up_process(hvc_task);
}
static void hvc_unthrottle(struct tty_struct *tty)
{
hvc_kick();
}
static int hvc_install(struct tty_driver *driver, struct tty_struct *tty)
{
struct hvc_struct *hp;
int rc;
if (!(hp = hvc_get_by_index(tty->index)))
return -ENODEV;
tty->driver_data = hp;
rc = tty_port_install(&hp->port, driver, tty);
if (rc)
tty_port_put(&hp->port);
return rc;
}
static int hvc_open(struct tty_struct *tty, struct file * filp)
{
struct hvc_struct *hp = tty->driver_data;
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&hp->port.lock, flags);
if (hp->port.count++ > 0) {
spin_unlock_irqrestore(&hp->port.lock, flags);
hvc_kick();
return 0;
}
spin_unlock_irqrestore(&hp->port.lock, flags);
tty_port_tty_set(&hp->port, tty);
if (hp->ops->notifier_add)
rc = hp->ops->notifier_add(hp, hp->data);
if (rc) {
tty_port_tty_set(&hp->port, NULL);
tty->driver_data = NULL;
tty_port_put(&hp->port);
printk(KERN_ERR "hvc_open: request_irq failed with rc %d.\n", rc);
} else
if (C_BAUD(tty))
if (hp->ops->dtr_rts)
hp->ops->dtr_rts(hp, 1);
hvc_kick();
return rc;
}
static void hvc_close(struct tty_struct *tty, struct file * filp)
{
struct hvc_struct *hp;
unsigned long flags;
if (tty_hung_up_p(filp))
return;
if (!tty->driver_data)
return;
hp = tty->driver_data;
spin_lock_irqsave(&hp->port.lock, flags);
if (--hp->port.count == 0) {
spin_unlock_irqrestore(&hp->port.lock, flags);
tty_port_tty_set(&hp->port, NULL);
if (C_HUPCL(tty))
if (hp->ops->dtr_rts)
hp->ops->dtr_rts(hp, 0);
if (hp->ops->notifier_del)
hp->ops->notifier_del(hp, hp->data);
cancel_work_sync(&hp->tty_resize);
tty_wait_until_sent_from_close(tty, HVC_CLOSE_WAIT);
} else {
if (hp->port.count < 0)
printk(KERN_ERR "hvc_close %X: oops, count is %d\n",
hp->vtermno, hp->port.count);
spin_unlock_irqrestore(&hp->port.lock, flags);
}
}
static void hvc_cleanup(struct tty_struct *tty)
{
struct hvc_struct *hp = tty->driver_data;
tty_port_put(&hp->port);
}
static void hvc_hangup(struct tty_struct *tty)
{
struct hvc_struct *hp = tty->driver_data;
unsigned long flags;
if (!hp)
return;
cancel_work_sync(&hp->tty_resize);
spin_lock_irqsave(&hp->port.lock, flags);
if (hp->port.count <= 0) {
spin_unlock_irqrestore(&hp->port.lock, flags);
return;
}
hp->port.count = 0;
spin_unlock_irqrestore(&hp->port.lock, flags);
tty_port_tty_set(&hp->port, NULL);
hp->n_outbuf = 0;
if (hp->ops->notifier_hangup)
hp->ops->notifier_hangup(hp, hp->data);
}
static int hvc_push(struct hvc_struct *hp)
{
int n;
n = hp->ops->put_chars(hp->vtermno, hp->outbuf, hp->n_outbuf);
if (n <= 0) {
if (n == 0 || n == -EAGAIN) {
hp->do_wakeup = 1;
return 0;
}
hp->n_outbuf = 0;
} else
hp->n_outbuf -= n;
if (hp->n_outbuf > 0)
memmove(hp->outbuf, hp->outbuf + n, hp->n_outbuf);
else
hp->do_wakeup = 1;
return n;
}
static int hvc_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
struct hvc_struct *hp = tty->driver_data;
unsigned long flags;
int rsize, written = 0;
if (!hp)
return -EPIPE;
if (hp->port.count <= 0)
return -EIO;
spin_lock_irqsave(&hp->lock, flags);
if (hp->n_outbuf > 0)
hvc_push(hp);
while (count > 0 && (rsize = hp->outbuf_size - hp->n_outbuf) > 0) {
if (rsize > count)
rsize = count;
memcpy(hp->outbuf + hp->n_outbuf, buf, rsize);
count -= rsize;
buf += rsize;
hp->n_outbuf += rsize;
written += rsize;
hvc_push(hp);
}
spin_unlock_irqrestore(&hp->lock, flags);
if (hp->n_outbuf)
hvc_kick();
return written;
}
static void hvc_set_winsz(struct work_struct *work)
{
struct hvc_struct *hp;
unsigned long hvc_flags;
struct tty_struct *tty;
struct winsize ws;
hp = container_of(work, struct hvc_struct, tty_resize);
tty = tty_port_tty_get(&hp->port);
if (!tty)
return;
spin_lock_irqsave(&hp->lock, hvc_flags);
ws = hp->ws;
spin_unlock_irqrestore(&hp->lock, hvc_flags);
tty_do_resize(tty, &ws);
tty_kref_put(tty);
}
static int hvc_write_room(struct tty_struct *tty)
{
struct hvc_struct *hp = tty->driver_data;
if (!hp)
return 0;
return hp->outbuf_size - hp->n_outbuf;
}
static int hvc_chars_in_buffer(struct tty_struct *tty)
{
struct hvc_struct *hp = tty->driver_data;
if (!hp)
return 0;
return hp->n_outbuf;
}
int hvc_poll(struct hvc_struct *hp)
{
struct tty_struct *tty;
int i, n, poll_mask = 0;
char buf[N_INBUF] __ALIGNED__;
unsigned long flags;
int read_total = 0;
int written_total = 0;
spin_lock_irqsave(&hp->lock, flags);
if (hp->n_outbuf > 0)
written_total = hvc_push(hp);
if (hp->n_outbuf > 0) {
poll_mask |= HVC_POLL_WRITE;
timeout = (written_total) ? 0 : MIN_TIMEOUT;
}
tty = tty_port_tty_get(&hp->port);
if (tty == NULL)
goto bail;
if (test_bit(TTY_THROTTLED, &tty->flags))
goto throttled;
if (!hp->irq_requested)
poll_mask |= HVC_POLL_READ;
for (;;) {
int count = tty_buffer_request_room(&hp->port, N_INBUF);
if (count == 0) {
poll_mask |= HVC_POLL_READ;
break;
}
n = hp->ops->get_chars(hp->vtermno, buf, count);
if (n <= 0) {
if (n == -EPIPE) {
spin_unlock_irqrestore(&hp->lock, flags);
tty_hangup(tty);
spin_lock_irqsave(&hp->lock, flags);
} else if ( n == -EAGAIN ) {
poll_mask |= HVC_POLL_READ;
}
break;
}
for (i = 0; i < n; ++i) {
#ifdef CONFIG_MAGIC_SYSRQ
if (hp->index == hvc_console.index) {
if (buf[i] == '\x0f') {
sysrq_pressed = !sysrq_pressed;
if (sysrq_pressed)
continue;
} else if (sysrq_pressed) {
handle_sysrq(buf[i]);
sysrq_pressed = 0;
continue;
}
}
#endif
tty_insert_flip_char(&hp->port, buf[i], 0);
}
read_total += n;
}
throttled:
if (hp->do_wakeup) {
hp->do_wakeup = 0;
tty_wakeup(tty);
}
bail:
spin_unlock_irqrestore(&hp->lock, flags);
if (read_total) {
timeout = MIN_TIMEOUT;
tty_flip_buffer_push(&hp->port);
}
tty_kref_put(tty);
return poll_mask;
}
void __hvc_resize(struct hvc_struct *hp, struct winsize ws)
{
hp->ws = ws;
schedule_work(&hp->tty_resize);
}
static int khvcd(void *unused)
{
int poll_mask;
struct hvc_struct *hp;
set_freezable();
do {
poll_mask = 0;
hvc_kicked = 0;
try_to_freeze();
wmb();
if (!cpus_are_in_xmon()) {
spin_lock(&hvc_structs_lock);
list_for_each_entry(hp, &hvc_structs, next) {
poll_mask |= hvc_poll(hp);
}
spin_unlock(&hvc_structs_lock);
} else
poll_mask |= HVC_POLL_READ;
if (hvc_kicked)
continue;
set_current_state(TASK_INTERRUPTIBLE);
if (!hvc_kicked) {
if (poll_mask == 0)
schedule();
else {
if (timeout < MAX_TIMEOUT)
timeout += (timeout >> 6) + 1;
msleep_interruptible(timeout);
}
}
__set_current_state(TASK_RUNNING);
} while (!kthread_should_stop());
return 0;
}
static int hvc_tiocmget(struct tty_struct *tty)
{
struct hvc_struct *hp = tty->driver_data;
if (!hp || !hp->ops->tiocmget)
return -EINVAL;
return hp->ops->tiocmget(hp);
}
static int hvc_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct hvc_struct *hp = tty->driver_data;
if (!hp || !hp->ops->tiocmset)
return -EINVAL;
return hp->ops->tiocmset(hp, set, clear);
}
static int hvc_poll_init(struct tty_driver *driver, int line, char *options)
{
return 0;
}
static int hvc_poll_get_char(struct tty_driver *driver, int line)
{
struct tty_struct *tty = driver->ttys[0];
struct hvc_struct *hp = tty->driver_data;
int n;
char ch;
n = hp->ops->get_chars(hp->vtermno, &ch, 1);
if (n == 0)
return NO_POLL_CHAR;
return ch;
}
static void hvc_poll_put_char(struct tty_driver *driver, int line, char ch)
{
struct tty_struct *tty = driver->ttys[0];
struct hvc_struct *hp = tty->driver_data;
int n;
do {
n = hp->ops->put_chars(hp->vtermno, &ch, 1);
} while (n <= 0);
}
struct hvc_struct *hvc_alloc(uint32_t vtermno, int data,
const struct hv_ops *ops,
int outbuf_size)
{
struct hvc_struct *hp;
int i;
if (atomic_inc_not_zero(&hvc_needs_init)) {
int err = hvc_init();
if (err)
return ERR_PTR(err);
}
hp = kzalloc(ALIGN(sizeof(*hp), sizeof(long)) + outbuf_size,
GFP_KERNEL);
if (!hp)
return ERR_PTR(-ENOMEM);
hp->vtermno = vtermno;
hp->data = data;
hp->ops = ops;
hp->outbuf_size = outbuf_size;
hp->outbuf = &((char *)hp)[ALIGN(sizeof(*hp), sizeof(long))];
tty_port_init(&hp->port);
hp->port.ops = &hvc_port_ops;
INIT_WORK(&hp->tty_resize, hvc_set_winsz);
spin_lock_init(&hp->lock);
spin_lock(&hvc_structs_lock);
for (i=0; i < MAX_NR_HVC_CONSOLES; i++)
if (vtermnos[i] == hp->vtermno &&
cons_ops[i] == hp->ops)
break;
if (i >= MAX_NR_HVC_CONSOLES)
i = ++last_hvc;
hp->index = i;
cons_ops[i] = ops;
vtermnos[i] = vtermno;
list_add_tail(&(hp->next), &hvc_structs);
spin_unlock(&hvc_structs_lock);
hvc_check_console(i);
return hp;
}
int hvc_remove(struct hvc_struct *hp)
{
unsigned long flags;
struct tty_struct *tty;
tty = tty_port_tty_get(&hp->port);
spin_lock_irqsave(&hp->lock, flags);
if (hp->index < MAX_NR_HVC_CONSOLES) {
console_lock();
vtermnos[hp->index] = -1;
cons_ops[hp->index] = NULL;
console_unlock();
}
spin_unlock_irqrestore(&hp->lock, flags);
tty_port_put(&hp->port);
if (tty) {
tty_vhangup(tty);
tty_kref_put(tty);
}
return 0;
}
static int hvc_init(void)
{
struct tty_driver *drv;
int err;
drv = alloc_tty_driver(HVC_ALLOC_TTY_ADAPTERS);
if (!drv) {
err = -ENOMEM;
goto out;
}
drv->driver_name = "hvc";
drv->name = "hvc";
drv->major = HVC_MAJOR;
drv->minor_start = HVC_MINOR;
drv->type = TTY_DRIVER_TYPE_SYSTEM;
drv->init_termios = tty_std_termios;
drv->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_RESET_TERMIOS;
tty_set_operations(drv, &hvc_ops);
hvc_task = kthread_run(khvcd, NULL, "khvcd");
if (IS_ERR(hvc_task)) {
printk(KERN_ERR "Couldn't create kthread for console.\n");
err = PTR_ERR(hvc_task);
goto put_tty;
}
err = tty_register_driver(drv);
if (err) {
printk(KERN_ERR "Couldn't register hvc console driver\n");
goto stop_thread;
}
smp_mb();
hvc_driver = drv;
return 0;
stop_thread:
kthread_stop(hvc_task);
hvc_task = NULL;
put_tty:
put_tty_driver(drv);
out:
return err;
}
static void __exit hvc_exit(void)
{
if (hvc_driver) {
kthread_stop(hvc_task);
tty_unregister_driver(hvc_driver);
put_tty_driver(hvc_driver);
unregister_console(&hvc_console);
}
}
