static inline struct raw3215_req *raw3215_alloc_req(void)
{
struct raw3215_req *req;
unsigned long flags;
spin_lock_irqsave(&raw3215_freelist_lock, flags);
req = raw3215_freelist;
raw3215_freelist = req->next;
spin_unlock_irqrestore(&raw3215_freelist_lock, flags);
return req;
}
static inline void raw3215_free_req(struct raw3215_req *req)
{
unsigned long flags;
if (req->type == RAW3215_FREE)
return;
req->type = RAW3215_FREE;
spin_lock_irqsave(&raw3215_freelist_lock, flags);
req->next = raw3215_freelist;
raw3215_freelist = req;
spin_unlock_irqrestore(&raw3215_freelist_lock, flags);
}
static void raw3215_mk_read_req(struct raw3215_info *raw)
{
struct raw3215_req *req;
struct ccw1 *ccw;
req = raw->queued_read;
if (req == NULL) {
req = raw3215_alloc_req();
req->type = RAW3215_READ;
req->info = raw;
raw->queued_read = req;
}
ccw = req->ccws;
ccw->cmd_code = 0x0A;
ccw->flags = 0x20;
ccw->count = 160;
ccw->cda = (__u32) __pa(raw->inbuf);
}
static void raw3215_mk_write_req(struct raw3215_info *raw)
{
struct raw3215_req *req;
struct ccw1 *ccw;
int len, count, ix, lines;
if (raw->count <= raw->written)
return;
req = raw->queued_write;
if (req == NULL) {
req = raw3215_alloc_req();
req->type = RAW3215_WRITE;
req->info = raw;
raw->queued_write = req;
} else {
raw->written -= req->len;
}
ccw = req->ccws;
req->start = (raw->head - raw->count + raw->written) &
(RAW3215_BUFFER_SIZE - 1);
lines = 0;
ix = req->start;
while (lines < RAW3215_MAX_NEWLINE && ix != raw->head) {
if (raw->buffer[ix] == 0x15)
lines++;
ix = (ix + 1) & (RAW3215_BUFFER_SIZE - 1);
}
len = ((ix - 1 - req->start) & (RAW3215_BUFFER_SIZE - 1)) + 1;
if (len > RAW3215_MAX_BYTES)
len = RAW3215_MAX_BYTES;
req->len = len;
raw->written += len;
req->delayable = (ix == raw->head) && (len < RAW3215_MIN_WRITE);
ix = req->start;
while (len > 0) {
if (ccw > req->ccws)
ccw[-1].flags |= 0x40;
ccw->cmd_code = 0x01;
ccw->flags = 0x20;
ccw->cda =
(__u32) __pa(raw->buffer + ix);
count = len;
if (ix + count > RAW3215_BUFFER_SIZE)
count = RAW3215_BUFFER_SIZE - ix;
ccw->count = count;
len -= count;
ix = (ix + count) & (RAW3215_BUFFER_SIZE - 1);
ccw++;
}
if (ccw > req->ccws)
ccw[-1].flags |= 0x40;
ccw->cmd_code = 0x03;
ccw->flags = 0;
ccw->cda = 0;
ccw->count = 1;
}
static void raw3215_start_io(struct raw3215_info *raw)
{
struct raw3215_req *req;
int res;
req = raw->queued_read;
if (req != NULL &&
!(raw->flags & (RAW3215_WORKING | RAW3215_THROTTLED))) {
raw->queued_read = NULL;
res = ccw_device_start(raw->cdev, req->ccws,
(unsigned long) req, 0, 0);
if (res != 0) {
raw->queued_read = req;
} else {
raw->flags |= RAW3215_WORKING;
}
}
req = raw->queued_write;
if (req != NULL &&
!(raw->flags & (RAW3215_WORKING | RAW3215_STOPPED))) {
raw->queued_write = NULL;
res = ccw_device_start(raw->cdev, req->ccws,
(unsigned long) req, 0, 0);
if (res != 0) {
raw->queued_write = req;
} else {
raw->flags |= RAW3215_WORKING;
}
}
}
static void raw3215_timeout(unsigned long __data)
{
struct raw3215_info *raw = (struct raw3215_info *) __data;
unsigned long flags;
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
if (raw->flags & RAW3215_TIMER_RUNS) {
del_timer(&raw->timer);
raw->flags &= ~RAW3215_TIMER_RUNS;
if (!(raw->flags & RAW3215_FROZEN)) {
raw3215_mk_write_req(raw);
raw3215_start_io(raw);
}
}
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
static inline void raw3215_try_io(struct raw3215_info *raw)
{
if (!(raw->flags & RAW3215_ACTIVE) || (raw->flags & RAW3215_FROZEN))
return;
if (raw->queued_read != NULL)
raw3215_start_io(raw);
else if (raw->queued_write != NULL) {
if ((raw->queued_write->delayable == 0) ||
(raw->flags & RAW3215_FLUSHING)) {
raw3215_start_io(raw);
if (raw->flags & RAW3215_TIMER_RUNS) {
del_timer(&raw->timer);
raw->flags &= ~RAW3215_TIMER_RUNS;
}
} else if (!(raw->flags & RAW3215_TIMER_RUNS)) {
init_timer(&raw->timer);
raw->timer.expires = RAW3215_TIMEOUT + jiffies;
raw->timer.data = (unsigned long) raw;
raw->timer.function = raw3215_timeout;
add_timer(&raw->timer);
raw->flags |= RAW3215_TIMER_RUNS;
}
}
}
static void raw3215_next_io(struct raw3215_info *raw)
{
struct tty_struct *tty;
raw3215_mk_write_req(raw);
raw3215_try_io(raw);
tty = raw->tty;
if (tty != NULL &&
RAW3215_BUFFER_SIZE - raw->count >= RAW3215_MIN_SPACE) {
tty_wakeup(tty);
}
}
static void raw3215_irq(struct ccw_device *cdev, unsigned long intparm,
struct irb *irb)
{
struct raw3215_info *raw;
struct raw3215_req *req;
struct tty_struct *tty;
int cstat, dstat;
int count;
kstat_cpu(smp_processor_id()).irqs[IOINT_C15]++;
raw = dev_get_drvdata(&cdev->dev);
req = (struct raw3215_req *) intparm;
cstat = irb->scsw.cmd.cstat;
dstat = irb->scsw.cmd.dstat;
if (cstat != 0)
raw3215_next_io(raw);
if (dstat & 0x01) {
dstat &= ~0x01;
}
switch (dstat) {
case 0x80:
if (cstat != 0)
break;
raw3215_mk_read_req(raw);
raw3215_next_io(raw);
break;
case 0x08:
case 0x0C:
if ((raw = req->info) == NULL)
return;
if (req->type == RAW3215_READ) {
req->residual = irb->scsw.cmd.count;
}
if (dstat == 0x08)
break;
case 0x04:
if ((raw = req->info) == NULL)
return;
if (req->type == RAW3215_READ && raw->tty != NULL) {
unsigned int cchar;
tty = raw->tty;
count = 160 - req->residual;
EBCASC(raw->inbuf, count);
cchar = ctrlchar_handle(raw->inbuf, count, tty);
switch (cchar & CTRLCHAR_MASK) {
case CTRLCHAR_SYSRQ:
break;
case CTRLCHAR_CTRL:
tty_insert_flip_char(tty, cchar, TTY_NORMAL);
tty_flip_buffer_push(raw->tty);
break;
case CTRLCHAR_NONE:
if (count < 2 ||
(strncmp(raw->inbuf+count-2, "\252n", 2) &&
strncmp(raw->inbuf+count-2, "^n", 2)) ) {
raw->inbuf[count] = '\n';
count++;
} else
count -= 2;
tty_insert_flip_string(tty, raw->inbuf, count);
tty_flip_buffer_push(raw->tty);
break;
}
} else if (req->type == RAW3215_WRITE) {
raw->count -= req->len;
raw->written -= req->len;
}
raw->flags &= ~RAW3215_WORKING;
raw3215_free_req(req);
if (waitqueue_active(&raw->empty_wait) &&
raw->queued_write == NULL &&
raw->queued_read == NULL) {
wake_up_interruptible(&raw->empty_wait);
}
raw3215_next_io(raw);
break;
default:
if (req != NULL && req->type != RAW3215_FREE) {
if (req->type == RAW3215_WRITE) {
raw->count -= req->len;
raw->written -= req->len;
}
raw->flags &= ~RAW3215_WORKING;
raw3215_free_req(req);
}
raw3215_next_io(raw);
}
return;
}
static void raw3215_drop_line(struct raw3215_info *raw)
{
int ix;
char ch;
BUG_ON(raw->written != 0);
ix = (raw->head - raw->count) & (RAW3215_BUFFER_SIZE - 1);
while (raw->count > 0) {
ch = raw->buffer[ix];
ix = (ix + 1) & (RAW3215_BUFFER_SIZE - 1);
raw->count--;
if (ch == 0x15)
break;
}
raw->head = ix;
}
static void raw3215_make_room(struct raw3215_info *raw, unsigned int length)
{
while (RAW3215_BUFFER_SIZE - raw->count < length) {
if (raw->flags & RAW3215_FROZEN) {
raw3215_drop_line(raw);
continue;
}
raw->flags |= RAW3215_FLUSHING;
raw3215_mk_write_req(raw);
raw3215_try_io(raw);
raw->flags &= ~RAW3215_FLUSHING;
#ifdef CONFIG_TN3215_CONSOLE
wait_cons_dev();
#endif
if (RAW3215_BUFFER_SIZE - raw->count >= length)
break;
spin_unlock(get_ccwdev_lock(raw->cdev));
udelay(100);
spin_lock(get_ccwdev_lock(raw->cdev));
}
}
static void raw3215_write(struct raw3215_info *raw, const char *str,
unsigned int length)
{
unsigned long flags;
int c, count;
while (length > 0) {
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
count = (length > RAW3215_BUFFER_SIZE) ?
RAW3215_BUFFER_SIZE : length;
length -= count;
raw3215_make_room(raw, count);
while (1) {
c = min_t(int, count,
min(RAW3215_BUFFER_SIZE - raw->count,
RAW3215_BUFFER_SIZE - raw->head));
if (c <= 0)
break;
memcpy(raw->buffer + raw->head, str, c);
ASCEBC(raw->buffer + raw->head, c);
raw->head = (raw->head + c) & (RAW3215_BUFFER_SIZE - 1);
raw->count += c;
raw->line_pos += c;
str += c;
count -= c;
}
if (!(raw->flags & RAW3215_WORKING)) {
raw3215_mk_write_req(raw);
raw3215_try_io(raw);
}
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
}
static void raw3215_putchar(struct raw3215_info *raw, unsigned char ch)
{
unsigned long flags;
unsigned int length, i;
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
if (ch == '\t') {
length = TAB_STOP_SIZE - (raw->line_pos%TAB_STOP_SIZE);
raw->line_pos += length;
ch = ' ';
} else if (ch == '\n') {
length = 1;
raw->line_pos = 0;
} else {
length = 1;
raw->line_pos++;
}
raw3215_make_room(raw, length);
for (i = 0; i < length; i++) {
raw->buffer[raw->head] = (char) _ascebc[(int) ch];
raw->head = (raw->head + 1) & (RAW3215_BUFFER_SIZE - 1);
raw->count++;
}
if (!(raw->flags & RAW3215_WORKING)) {
raw3215_mk_write_req(raw);
raw3215_try_io(raw);
}
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
static void raw3215_flush_buffer(struct raw3215_info *raw)
{
unsigned long flags;
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
if (raw->count > 0) {
raw->flags |= RAW3215_FLUSHING;
raw3215_try_io(raw);
raw->flags &= ~RAW3215_FLUSHING;
}
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
static int raw3215_startup(struct raw3215_info *raw)
{
unsigned long flags;
if (raw->flags & RAW3215_ACTIVE)
return 0;
raw->line_pos = 0;
raw->flags |= RAW3215_ACTIVE;
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
raw3215_try_io(raw);
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
return 0;
}
static void raw3215_shutdown(struct raw3215_info *raw)
{
DECLARE_WAITQUEUE(wait, current);
unsigned long flags;
if (!(raw->flags & RAW3215_ACTIVE) || (raw->flags & RAW3215_FIXED))
return;
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
if ((raw->flags & RAW3215_WORKING) ||
raw->queued_write != NULL ||
raw->queued_read != NULL) {
raw->flags |= RAW3215_CLOSING;
add_wait_queue(&raw->empty_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
schedule();
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
remove_wait_queue(&raw->empty_wait, &wait);
set_current_state(TASK_RUNNING);
raw->flags &= ~(RAW3215_ACTIVE | RAW3215_CLOSING);
}
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
static int raw3215_probe (struct ccw_device *cdev)
{
struct raw3215_info *raw;
int line;
if (raw3215[0] && (raw3215[0] == dev_get_drvdata(&cdev->dev)))
return 0;
raw = kmalloc(sizeof(struct raw3215_info) +
RAW3215_INBUF_SIZE, GFP_KERNEL|GFP_DMA);
if (raw == NULL)
return -ENOMEM;
spin_lock(&raw3215_device_lock);
for (line = 0; line < NR_3215; line++) {
if (!raw3215[line]) {
raw3215[line] = raw;
break;
}
}
spin_unlock(&raw3215_device_lock);
if (line == NR_3215) {
kfree(raw);
return -ENODEV;
}
raw->cdev = cdev;
raw->inbuf = (char *) raw + sizeof(struct raw3215_info);
memset(raw, 0, sizeof(struct raw3215_info));
raw->buffer = kmalloc(RAW3215_BUFFER_SIZE,
GFP_KERNEL|GFP_DMA);
if (raw->buffer == NULL) {
spin_lock(&raw3215_device_lock);
raw3215[line] = NULL;
spin_unlock(&raw3215_device_lock);
kfree(raw);
return -ENOMEM;
}
init_waitqueue_head(&raw->empty_wait);
dev_set_drvdata(&cdev->dev, raw);
cdev->handler = raw3215_irq;
return 0;
}
static void raw3215_remove (struct ccw_device *cdev)
{
struct raw3215_info *raw;
ccw_device_set_offline(cdev);
raw = dev_get_drvdata(&cdev->dev);
if (raw) {
dev_set_drvdata(&cdev->dev, NULL);
kfree(raw->buffer);
kfree(raw);
}
}
static int raw3215_set_online (struct ccw_device *cdev)
{
struct raw3215_info *raw;
raw = dev_get_drvdata(&cdev->dev);
if (!raw)
return -ENODEV;
return raw3215_startup(raw);
}
static int raw3215_set_offline (struct ccw_device *cdev)
{
struct raw3215_info *raw;
raw = dev_get_drvdata(&cdev->dev);
if (!raw)
return -ENODEV;
raw3215_shutdown(raw);
return 0;
}
static int raw3215_pm_stop(struct ccw_device *cdev)
{
struct raw3215_info *raw;
unsigned long flags;
raw = dev_get_drvdata(&cdev->dev);
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
raw3215_make_room(raw, RAW3215_BUFFER_SIZE);
raw->flags |= RAW3215_FROZEN;
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
return 0;
}
static int raw3215_pm_start(struct ccw_device *cdev)
{
struct raw3215_info *raw;
unsigned long flags;
raw = dev_get_drvdata(&cdev->dev);
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
raw->flags &= ~RAW3215_FROZEN;
raw->flags |= RAW3215_FLUSHING;
raw3215_try_io(raw);
raw->flags &= ~RAW3215_FLUSHING;
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
return 0;
}
static void con3215_write(struct console *co, const char *str,
unsigned int count)
{
struct raw3215_info *raw;
int i;
if (count <= 0)
return;
raw = raw3215[0];
while (count > 0) {
for (i = 0; i < count; i++)
if (str[i] == '\t' || str[i] == '\n')
break;
raw3215_write(raw, str, i);
count -= i;
str += i;
if (count > 0) {
raw3215_putchar(raw, *str);
count--;
str++;
}
}
}
static struct tty_driver *con3215_device(struct console *c, int *index)
{
*index = c->index;
return tty3215_driver;
}
static void con3215_flush(void)
{
struct raw3215_info *raw;
unsigned long flags;
raw = raw3215[0];
if (raw->flags & RAW3215_FROZEN)
if (ccw_device_force_console())
return;
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
raw3215_make_room(raw, RAW3215_BUFFER_SIZE);
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
static int con3215_notify(struct notifier_block *self,
unsigned long event, void *data)
{
con3215_flush();
return NOTIFY_OK;
}
static int __init con3215_init(void)
{
struct ccw_device *cdev;
struct raw3215_info *raw;
struct raw3215_req *req;
int i;
if (!CONSOLE_IS_3215)
return -ENODEV;
if (MACHINE_IS_VM) {
cpcmd("TERM CONMODE 3215", NULL, 0, NULL);
cpcmd("TERM AUTOCR OFF", NULL, 0, NULL);
}
raw3215_freelist = NULL;
spin_lock_init(&raw3215_freelist_lock);
for (i = 0; i < NR_3215_REQ; i++) {
req = kzalloc(sizeof(struct raw3215_req), GFP_KERNEL | GFP_DMA);
req->next = raw3215_freelist;
raw3215_freelist = req;
}
cdev = ccw_device_probe_console();
if (IS_ERR(cdev))
return -ENODEV;
raw3215[0] = raw = (struct raw3215_info *)
kzalloc(sizeof(struct raw3215_info), GFP_KERNEL | GFP_DMA);
raw->buffer = kzalloc(RAW3215_BUFFER_SIZE, GFP_KERNEL | GFP_DMA);
raw->inbuf = kzalloc(RAW3215_INBUF_SIZE, GFP_KERNEL | GFP_DMA);
raw->cdev = cdev;
dev_set_drvdata(&cdev->dev, raw);
cdev->handler = raw3215_irq;
raw->flags |= RAW3215_FIXED;
init_waitqueue_head(&raw->empty_wait);
if (raw3215_startup(raw) != 0) {
kfree(raw->inbuf);
kfree(raw->buffer);
kfree(raw);
raw3215[0] = NULL;
return -ENODEV;
}
atomic_notifier_chain_register(&panic_notifier_list, &on_panic_nb);
register_reboot_notifier(&on_reboot_nb);
register_console(&con3215);
return 0;
}
static int tty3215_open(struct tty_struct *tty, struct file * filp)
{
struct raw3215_info *raw;
int retval, line;
line = tty->index;
if ((line < 0) || (line >= NR_3215))
return -ENODEV;
raw = raw3215[line];
if (raw == NULL)
return -ENODEV;
tty->driver_data = raw;
raw->tty = tty;
tty->low_latency = 0;
retval = raw3215_startup(raw);
if (retval)
return retval;
return 0;
}
static void tty3215_close(struct tty_struct *tty, struct file * filp)
{
struct raw3215_info *raw;
raw = (struct raw3215_info *) tty->driver_data;
if (raw == NULL || tty->count > 1)
return;
tty->closing = 1;
raw3215_shutdown(raw);
tty->closing = 0;
raw->tty = NULL;
}
static int tty3215_write_room(struct tty_struct *tty)
{
struct raw3215_info *raw;
raw = (struct raw3215_info *) tty->driver_data;
if ((RAW3215_BUFFER_SIZE - raw->count - TAB_STOP_SIZE) >= 0)
return RAW3215_BUFFER_SIZE - raw->count - TAB_STOP_SIZE;
else
return 0;
}
static int tty3215_write(struct tty_struct * tty,
const unsigned char *buf, int count)
{
struct raw3215_info *raw;
if (!tty)
return 0;
raw = (struct raw3215_info *) tty->driver_data;
raw3215_write(raw, buf, count);
return count;
}
static int tty3215_put_char(struct tty_struct *tty, unsigned char ch)
{
struct raw3215_info *raw;
if (!tty)
return 0;
raw = (struct raw3215_info *) tty->driver_data;
raw3215_putchar(raw, ch);
return 1;
}
static void tty3215_flush_chars(struct tty_struct *tty)
{
}
static int tty3215_chars_in_buffer(struct tty_struct *tty)
{
struct raw3215_info *raw;
raw = (struct raw3215_info *) tty->driver_data;
return raw->count;
}
static void tty3215_flush_buffer(struct tty_struct *tty)
{
struct raw3215_info *raw;
raw = (struct raw3215_info *) tty->driver_data;
raw3215_flush_buffer(raw);
tty_wakeup(tty);
}
static void tty3215_throttle(struct tty_struct * tty)
{
struct raw3215_info *raw;
raw = (struct raw3215_info *) tty->driver_data;
raw->flags |= RAW3215_THROTTLED;
}
static void tty3215_unthrottle(struct tty_struct * tty)
{
struct raw3215_info *raw;
unsigned long flags;
raw = (struct raw3215_info *) tty->driver_data;
if (raw->flags & RAW3215_THROTTLED) {
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
raw->flags &= ~RAW3215_THROTTLED;
raw3215_try_io(raw);
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
}
static void tty3215_stop(struct tty_struct *tty)
{
struct raw3215_info *raw;
raw = (struct raw3215_info *) tty->driver_data;
raw->flags |= RAW3215_STOPPED;
}
static void tty3215_start(struct tty_struct *tty)
{
struct raw3215_info *raw;
unsigned long flags;
raw = (struct raw3215_info *) tty->driver_data;
if (raw->flags & RAW3215_STOPPED) {
spin_lock_irqsave(get_ccwdev_lock(raw->cdev), flags);
raw->flags &= ~RAW3215_STOPPED;
raw3215_try_io(raw);
spin_unlock_irqrestore(get_ccwdev_lock(raw->cdev), flags);
}
}
static int __init tty3215_init(void)
{
struct tty_driver *driver;
int ret;
if (!CONSOLE_IS_3215)
return 0;
driver = alloc_tty_driver(NR_3215);
if (!driver)
return -ENOMEM;
ret = ccw_driver_register(&raw3215_ccw_driver);
if (ret) {
put_tty_driver(driver);
return ret;
}
driver->owner = THIS_MODULE;
driver->driver_name = "tty3215";
driver->name = "ttyS";
driver->major = TTY_MAJOR;
driver->minor_start = 64;
driver->type = TTY_DRIVER_TYPE_SYSTEM;
driver->subtype = SYSTEM_TYPE_TTY;
driver->init_termios = tty_std_termios;
driver->init_termios.c_iflag = IGNBRK | IGNPAR;
driver->init_termios.c_oflag = ONLCR | XTABS;
driver->init_termios.c_lflag = ISIG;
driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(driver, &tty3215_ops);
ret = tty_register_driver(driver);
if (ret) {
put_tty_driver(driver);
return ret;
}
tty3215_driver = driver;
return 0;
}
static void __exit tty3215_exit(void)
{
tty_unregister_driver(tty3215_driver);
put_tty_driver(tty3215_driver);
ccw_driver_unregister(&raw3215_ccw_driver);
}
