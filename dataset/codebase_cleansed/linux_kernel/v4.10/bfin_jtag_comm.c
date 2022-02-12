static inline uint32_t bfin_write_emudat(uint32_t emudat)
{
__asm__ __volatile__("emudat = %0;" : : "d"(emudat));
return emudat;
}
static inline uint32_t bfin_read_emudat(void)
{
uint32_t emudat;
__asm__ __volatile__("%0 = emudat;" : "=d"(emudat));
return emudat;
}
static inline uint32_t bfin_write_emudat_chars(char a, char b, char c, char d)
{
return bfin_write_emudat((a << 0) | (b << 8) | (c << 16) | (d << 24));
}
static int
bfin_jc_emudat_manager(void *arg)
{
uint32_t inbound_len = 0, outbound_len = 0;
while (!kthread_should_stop()) {
struct tty_struct *tty = tty_port_tty_get(&port);
if (tty == NULL && circ_empty(&bfin_jc_write_buf)) {
pr_debug("waiting for readers\n");
__set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
continue;
}
if (!(bfin_read_DBGSTAT() & EMUDIF) && circ_empty(&bfin_jc_write_buf)) {
pr_debug("waiting for data (in_len = %i) (circ: %i %i)\n",
inbound_len, bfin_jc_write_buf.tail, bfin_jc_write_buf.head);
tty_kref_put(tty);
if (inbound_len)
schedule();
else
schedule_timeout_interruptible(HZ);
continue;
}
if (bfin_read_DBGSTAT() & EMUDIF) {
uint32_t emudat = bfin_read_emudat();
if (inbound_len == 0) {
pr_debug("incoming length: 0x%08x\n", emudat);
inbound_len = emudat;
} else {
size_t num_chars = (4 <= inbound_len ? 4 : inbound_len);
pr_debug(" incoming data: 0x%08x (pushing %zu)\n", emudat, num_chars);
inbound_len -= num_chars;
tty_insert_flip_string(&port, (unsigned char *)&emudat, num_chars);
tty_flip_buffer_push(&port);
}
}
if (!(bfin_read_DBGSTAT() & EMUDOF) && !circ_empty(&bfin_jc_write_buf)) {
if (outbound_len == 0) {
outbound_len = circ_cnt(&bfin_jc_write_buf);
bfin_write_emudat(outbound_len);
pr_debug("outgoing length: 0x%08x\n", outbound_len);
} else {
int tail = bfin_jc_write_buf.tail;
size_t ate = (4 <= outbound_len ? 4 : outbound_len);
uint32_t emudat =
bfin_write_emudat_chars(
circ_byte(&bfin_jc_write_buf, tail + 0),
circ_byte(&bfin_jc_write_buf, tail + 1),
circ_byte(&bfin_jc_write_buf, tail + 2),
circ_byte(&bfin_jc_write_buf, tail + 3)
);
bfin_jc_write_buf.tail += ate;
outbound_len -= ate;
if (tty)
tty_wakeup(tty);
pr_debug(" outgoing data: 0x%08x (pushing %zu)\n", emudat, ate);
}
}
tty_kref_put(tty);
}
__set_current_state(TASK_RUNNING);
return 0;
}
static int
bfin_jc_open(struct tty_struct *tty, struct file *filp)
{
unsigned long flags;
spin_lock_irqsave(&port.lock, flags);
port.count++;
spin_unlock_irqrestore(&port.lock, flags);
tty_port_tty_set(&port, tty);
wake_up_process(bfin_jc_kthread);
return 0;
}
static void
bfin_jc_close(struct tty_struct *tty, struct file *filp)
{
unsigned long flags;
bool last;
spin_lock_irqsave(&port.lock, flags);
last = --port.count == 0;
spin_unlock_irqrestore(&port.lock, flags);
if (last)
tty_port_tty_set(&port, NULL);
wake_up_process(bfin_jc_kthread);
}
static int
bfin_jc_circ_write(const unsigned char *buf, int count)
{
int i;
count = min(count, circ_free(&bfin_jc_write_buf));
pr_debug("going to write chunk of %i bytes\n", count);
for (i = 0; i < count; ++i)
circ_byte(&bfin_jc_write_buf, bfin_jc_write_buf.head + i) = buf[i];
bfin_jc_write_buf.head += i;
return i;
}
static int
bfin_jc_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
int i;
console_lock();
i = bfin_jc_circ_write(buf, count);
console_unlock();
wake_up_process(bfin_jc_kthread);
return i;
}
static void
bfin_jc_flush_chars(struct tty_struct *tty)
{
wake_up_process(bfin_jc_kthread);
}
static int
bfin_jc_write_room(struct tty_struct *tty)
{
return circ_free(&bfin_jc_write_buf);
}
static int
bfin_jc_chars_in_buffer(struct tty_struct *tty)
{
return circ_cnt(&bfin_jc_write_buf);
}
static int __init bfin_jc_init(void)
{
int ret;
bfin_jc_kthread = kthread_create(bfin_jc_emudat_manager, NULL, DRV_NAME);
if (IS_ERR(bfin_jc_kthread))
return PTR_ERR(bfin_jc_kthread);
ret = -ENOMEM;
bfin_jc_write_buf.head = bfin_jc_write_buf.tail = 0;
bfin_jc_write_buf.buf = kmalloc(CIRC_SIZE, GFP_KERNEL);
if (!bfin_jc_write_buf.buf)
goto err_buf;
bfin_jc_driver = alloc_tty_driver(1);
if (!bfin_jc_driver)
goto err_driver;
tty_port_init(&port);
bfin_jc_driver->driver_name = DRV_NAME;
bfin_jc_driver->name = DEV_NAME;
bfin_jc_driver->type = TTY_DRIVER_TYPE_SERIAL;
bfin_jc_driver->subtype = SERIAL_TYPE_NORMAL;
bfin_jc_driver->init_termios = tty_std_termios;
tty_set_operations(bfin_jc_driver, &bfin_jc_ops);
tty_port_link_device(&port, bfin_jc_driver, 0);
ret = tty_register_driver(bfin_jc_driver);
if (ret)
goto err;
pr_init(KERN_INFO DRV_NAME ": initialized\n");
return 0;
err:
tty_port_destroy(&port);
put_tty_driver(bfin_jc_driver);
err_driver:
kfree(bfin_jc_write_buf.buf);
err_buf:
kthread_stop(bfin_jc_kthread);
return ret;
}
static void __exit bfin_jc_exit(void)
{
kthread_stop(bfin_jc_kthread);
kfree(bfin_jc_write_buf.buf);
tty_unregister_driver(bfin_jc_driver);
put_tty_driver(bfin_jc_driver);
tty_port_destroy(&port);
}
static void
bfin_jc_straight_buffer_write(const char *buf, unsigned count)
{
unsigned ate = 0;
while (bfin_read_DBGSTAT() & EMUDOF)
continue;
bfin_write_emudat(count);
while (ate < count) {
while (bfin_read_DBGSTAT() & EMUDOF)
continue;
bfin_write_emudat_chars(buf[ate], buf[ate+1], buf[ate+2], buf[ate+3]);
ate += 4;
}
}
static void
bfin_jc_console_write(struct console *co, const char *buf, unsigned count)
{
if (bfin_jc_kthread == NULL)
bfin_jc_straight_buffer_write(buf, count);
else
bfin_jc_circ_write(buf, count);
}
static struct tty_driver *
bfin_jc_console_device(struct console *co, int *index)
{
*index = co->index;
return bfin_jc_driver;
}
static int __init bfin_jc_console_init(void)
{
register_console(&bfin_jc_console);
return 0;
}
static void __init
bfin_jc_early_write(struct console *co, const char *buf, unsigned int count)
{
bfin_jc_straight_buffer_write(buf, count);
}
struct console * __init
bfin_jc_early_init(unsigned int port, unsigned int cflag)
{
return &bfin_jc_early_console;
}
