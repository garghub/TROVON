static void
sclp_vt220_process_queue(struct sclp_vt220_request *request)
{
unsigned long flags;
void *page;
do {
page = request->sclp_req.sccb;
spin_lock_irqsave(&sclp_vt220_lock, flags);
list_del(&request->list);
list_add_tail((struct list_head *) page, &sclp_vt220_empty);
request = NULL;
if (!list_empty(&sclp_vt220_outqueue))
request = list_entry(sclp_vt220_outqueue.next,
struct sclp_vt220_request, list);
if (!request || sclp_vt220_suspended) {
sclp_vt220_queue_running = 0;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
break;
}
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
} while (__sclp_vt220_emit(request));
if (request == NULL && sclp_vt220_flush_later)
sclp_vt220_emit_current();
tty_port_tty_wakeup(&sclp_vt220_port);
}
static void
sclp_vt220_callback(struct sclp_req *request, void *data)
{
struct sclp_vt220_request *vt220_request;
struct sclp_vt220_sccb *sccb;
vt220_request = (struct sclp_vt220_request *) data;
if (request->status == SCLP_REQ_FAILED) {
sclp_vt220_process_queue(vt220_request);
return;
}
sccb = (struct sclp_vt220_sccb *) vt220_request->sclp_req.sccb;
switch (sccb->header.response_code) {
case 0x0020 :
break;
case 0x05f0:
break;
case 0x0340:
if (++vt220_request->retry_count > SCLP_BUFFER_MAX_RETRY)
break;
if (sclp_remove_processed((struct sccb_header *) sccb) > 0) {
sccb->header.response_code = 0x0000;
vt220_request->sclp_req.status = SCLP_REQ_FILLED;
if (sclp_add_request(request) == 0)
return;
}
break;
case 0x0040:
if (++vt220_request->retry_count > SCLP_BUFFER_MAX_RETRY)
break;
sccb->header.response_code = 0x0000;
vt220_request->sclp_req.status = SCLP_REQ_FILLED;
if (sclp_add_request(request) == 0)
return;
break;
default:
break;
}
sclp_vt220_process_queue(vt220_request);
}
static int
__sclp_vt220_emit(struct sclp_vt220_request *request)
{
request->sclp_req.command = SCLP_CMDW_WRITE_EVENT_DATA;
request->sclp_req.status = SCLP_REQ_FILLED;
request->sclp_req.callback = sclp_vt220_callback;
request->sclp_req.callback_data = (void *) request;
return sclp_add_request(&request->sclp_req);
}
static void
sclp_vt220_emit_current(void)
{
unsigned long flags;
struct sclp_vt220_request *request;
struct sclp_vt220_sccb *sccb;
spin_lock_irqsave(&sclp_vt220_lock, flags);
if (sclp_vt220_current_request) {
sccb = (struct sclp_vt220_sccb *)
sclp_vt220_current_request->sclp_req.sccb;
if (sccb->header.length != sizeof(struct sclp_vt220_sccb)) {
list_add_tail(&sclp_vt220_current_request->list,
&sclp_vt220_outqueue);
sclp_vt220_current_request = NULL;
if (timer_pending(&sclp_vt220_timer))
del_timer(&sclp_vt220_timer);
}
sclp_vt220_flush_later = 0;
}
if (sclp_vt220_queue_running || sclp_vt220_suspended)
goto out_unlock;
if (list_empty(&sclp_vt220_outqueue))
goto out_unlock;
request = list_first_entry(&sclp_vt220_outqueue,
struct sclp_vt220_request, list);
sclp_vt220_queue_running = 1;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
if (__sclp_vt220_emit(request))
sclp_vt220_process_queue(request);
return;
out_unlock:
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
}
static struct sclp_vt220_request *
sclp_vt220_initialize_page(void *page)
{
struct sclp_vt220_request *request;
struct sclp_vt220_sccb *sccb;
request = ((struct sclp_vt220_request *)
((addr_t) page + PAGE_SIZE)) - 1;
request->retry_count = 0;
request->sclp_req.sccb = page;
sccb = (struct sclp_vt220_sccb *) page;
memset((void *) sccb, 0, sizeof(struct sclp_vt220_sccb));
sccb->header.length = sizeof(struct sclp_vt220_sccb);
sccb->header.function_code = SCLP_NORMAL_WRITE;
sccb->header.response_code = 0x0000;
sccb->evbuf.type = EVTYP_VT220MSG;
sccb->evbuf.length = sizeof(struct evbuf_header);
return request;
}
static inline unsigned int
sclp_vt220_space_left(struct sclp_vt220_request *request)
{
struct sclp_vt220_sccb *sccb;
sccb = (struct sclp_vt220_sccb *) request->sclp_req.sccb;
return PAGE_SIZE - sizeof(struct sclp_vt220_request) -
sccb->header.length;
}
static inline unsigned int
sclp_vt220_chars_stored(struct sclp_vt220_request *request)
{
struct sclp_vt220_sccb *sccb;
sccb = (struct sclp_vt220_sccb *) request->sclp_req.sccb;
return sccb->evbuf.length - sizeof(struct evbuf_header);
}
static int
sclp_vt220_add_msg(struct sclp_vt220_request *request,
const unsigned char *msg, int count, int convertlf)
{
struct sclp_vt220_sccb *sccb;
void *buffer;
unsigned char c;
int from;
int to;
if (count > sclp_vt220_space_left(request))
count = sclp_vt220_space_left(request);
if (count <= 0)
return 0;
sccb = (struct sclp_vt220_sccb *) request->sclp_req.sccb;
buffer = (void *) ((addr_t) sccb + sccb->header.length);
if (convertlf) {
for (from=0, to=0;
(from < count) && (to < sclp_vt220_space_left(request));
from++) {
c = msg[from];
if (c == 0x0a) {
if (to + 1 < sclp_vt220_space_left(request)) {
((unsigned char *) buffer)[to++] = c;
((unsigned char *) buffer)[to++] = 0x0d;
} else
break;
} else
((unsigned char *) buffer)[to++] = c;
}
sccb->header.length += to;
sccb->evbuf.length += to;
return from;
} else {
memcpy(buffer, (const void *) msg, count);
sccb->header.length += count;
sccb->evbuf.length += count;
return count;
}
}
static void
sclp_vt220_timeout(unsigned long data)
{
sclp_vt220_emit_current();
}
static int
sclp_vt220_drop_buffer(void)
{
struct list_head *list;
struct sclp_vt220_request *request;
void *page;
if (!sclp_console_drop)
return 0;
list = sclp_vt220_outqueue.next;
if (sclp_vt220_queue_running)
list = list->next;
if (list == &sclp_vt220_outqueue)
return 0;
list_del(list);
request = list_entry(list, struct sclp_vt220_request, list);
page = request->sclp_req.sccb;
list_add_tail((struct list_head *) page, &sclp_vt220_empty);
return 1;
}
static int
__sclp_vt220_write(const unsigned char *buf, int count, int do_schedule,
int convertlf, int may_fail)
{
unsigned long flags;
void *page;
int written;
int overall_written;
if (count <= 0)
return 0;
overall_written = 0;
spin_lock_irqsave(&sclp_vt220_lock, flags);
do {
if (sclp_vt220_current_request == NULL) {
if (list_empty(&sclp_vt220_empty))
sclp_console_full++;
while (list_empty(&sclp_vt220_empty)) {
if (may_fail || sclp_vt220_suspended)
goto out;
if (sclp_vt220_drop_buffer())
break;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
sclp_sync_wait();
spin_lock_irqsave(&sclp_vt220_lock, flags);
}
page = (void *) sclp_vt220_empty.next;
list_del((struct list_head *) page);
sclp_vt220_current_request =
sclp_vt220_initialize_page(page);
}
written = sclp_vt220_add_msg(sclp_vt220_current_request,
buf, count, convertlf);
overall_written += written;
if (written == count)
break;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
sclp_vt220_emit_current();
spin_lock_irqsave(&sclp_vt220_lock, flags);
buf += written;
count -= written;
} while (count > 0);
if (sclp_vt220_current_request != NULL &&
!timer_pending(&sclp_vt220_timer) && do_schedule) {
sclp_vt220_timer.function = sclp_vt220_timeout;
sclp_vt220_timer.data = 0UL;
sclp_vt220_timer.expires = jiffies + BUFFER_MAX_DELAY;
add_timer(&sclp_vt220_timer);
}
out:
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
return overall_written;
}
static int
sclp_vt220_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
return __sclp_vt220_write(buf, count, 1, 0, 1);
}
static void
sclp_vt220_receiver_fn(struct evbuf_header *evbuf)
{
char *buffer;
unsigned int count;
buffer = (char *) ((addr_t) evbuf + sizeof(struct evbuf_header));
count = evbuf->length - sizeof(struct evbuf_header);
switch (*buffer) {
case SCLP_VT220_SESSION_ENDED:
case SCLP_VT220_SESSION_STARTED:
break;
case SCLP_VT220_SESSION_DATA:
buffer++;
count--;
tty_insert_flip_string(&sclp_vt220_port, buffer, count);
tty_flip_buffer_push(&sclp_vt220_port);
break;
}
}
static int
sclp_vt220_open(struct tty_struct *tty, struct file *filp)
{
if (tty->count == 1) {
tty_port_tty_set(&sclp_vt220_port, tty);
sclp_vt220_port.low_latency = 0;
if (!tty->winsize.ws_row && !tty->winsize.ws_col) {
tty->winsize.ws_row = 24;
tty->winsize.ws_col = 80;
}
}
return 0;
}
static void
sclp_vt220_close(struct tty_struct *tty, struct file *filp)
{
if (tty->count == 1)
tty_port_tty_set(&sclp_vt220_port, NULL);
}
static int
sclp_vt220_put_char(struct tty_struct *tty, unsigned char ch)
{
return __sclp_vt220_write(&ch, 1, 0, 0, 1);
}
static void
sclp_vt220_flush_chars(struct tty_struct *tty)
{
if (!sclp_vt220_queue_running)
sclp_vt220_emit_current();
else
sclp_vt220_flush_later = 1;
}
static int
sclp_vt220_write_room(struct tty_struct *tty)
{
unsigned long flags;
struct list_head *l;
int count;
spin_lock_irqsave(&sclp_vt220_lock, flags);
count = 0;
if (sclp_vt220_current_request != NULL)
count = sclp_vt220_space_left(sclp_vt220_current_request);
list_for_each(l, &sclp_vt220_empty)
count += SCLP_VT220_MAX_CHARS_PER_BUFFER;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
return count;
}
static int
sclp_vt220_chars_in_buffer(struct tty_struct *tty)
{
unsigned long flags;
struct list_head *l;
struct sclp_vt220_request *r;
int count;
spin_lock_irqsave(&sclp_vt220_lock, flags);
count = 0;
if (sclp_vt220_current_request != NULL)
count = sclp_vt220_chars_stored(sclp_vt220_current_request);
list_for_each(l, &sclp_vt220_outqueue) {
r = list_entry(l, struct sclp_vt220_request, list);
count += sclp_vt220_chars_stored(r);
}
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
return count;
}
static void
sclp_vt220_flush_buffer(struct tty_struct *tty)
{
sclp_vt220_emit_current();
}
static void __init __sclp_vt220_free_pages(void)
{
struct list_head *page, *p;
list_for_each_safe(page, p, &sclp_vt220_empty) {
list_del(page);
free_page((unsigned long) page);
}
}
static void __init __sclp_vt220_cleanup(void)
{
sclp_vt220_init_count--;
if (sclp_vt220_init_count != 0)
return;
sclp_unregister(&sclp_vt220_register);
__sclp_vt220_free_pages();
tty_port_destroy(&sclp_vt220_port);
}
static int __init __sclp_vt220_init(int num_pages)
{
void *page;
int i;
int rc;
sclp_vt220_init_count++;
if (sclp_vt220_init_count != 1)
return 0;
spin_lock_init(&sclp_vt220_lock);
INIT_LIST_HEAD(&sclp_vt220_empty);
INIT_LIST_HEAD(&sclp_vt220_outqueue);
init_timer(&sclp_vt220_timer);
tty_port_init(&sclp_vt220_port);
sclp_vt220_current_request = NULL;
sclp_vt220_buffered_chars = 0;
sclp_vt220_flush_later = 0;
rc = -ENOMEM;
for (i = 0; i < num_pages; i++) {
page = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!page)
goto out;
list_add_tail(page, &sclp_vt220_empty);
}
rc = sclp_register(&sclp_vt220_register);
out:
if (rc) {
__sclp_vt220_free_pages();
sclp_vt220_init_count--;
tty_port_destroy(&sclp_vt220_port);
}
return rc;
}
static int __init sclp_vt220_tty_init(void)
{
struct tty_driver *driver;
int rc;
driver = alloc_tty_driver(1);
if (!driver)
return -ENOMEM;
rc = __sclp_vt220_init(MAX_KMEM_PAGES);
if (rc)
goto out_driver;
driver->driver_name = SCLP_VT220_DRIVER_NAME;
driver->name = SCLP_VT220_DEVICE_NAME;
driver->major = SCLP_VT220_MAJOR;
driver->minor_start = SCLP_VT220_MINOR;
driver->type = TTY_DRIVER_TYPE_SYSTEM;
driver->subtype = SYSTEM_TYPE_TTY;
driver->init_termios = tty_std_termios;
driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(driver, &sclp_vt220_ops);
tty_port_link_device(&sclp_vt220_port, driver, 0);
rc = tty_register_driver(driver);
if (rc)
goto out_init;
rc = sclp_register(&sclp_vt220_register_input);
if (rc)
goto out_reg;
sclp_vt220_driver = driver;
return 0;
out_reg:
tty_unregister_driver(driver);
out_init:
__sclp_vt220_cleanup();
out_driver:
put_tty_driver(driver);
return rc;
}
static void __sclp_vt220_flush_buffer(void)
{
unsigned long flags;
sclp_vt220_emit_current();
spin_lock_irqsave(&sclp_vt220_lock, flags);
if (timer_pending(&sclp_vt220_timer))
del_timer(&sclp_vt220_timer);
while (sclp_vt220_queue_running) {
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
sclp_sync_wait();
spin_lock_irqsave(&sclp_vt220_lock, flags);
}
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
}
static void sclp_vt220_resume(void)
{
unsigned long flags;
spin_lock_irqsave(&sclp_vt220_lock, flags);
sclp_vt220_suspended = 0;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
sclp_vt220_emit_current();
}
static void sclp_vt220_suspend(void)
{
unsigned long flags;
spin_lock_irqsave(&sclp_vt220_lock, flags);
sclp_vt220_suspended = 1;
spin_unlock_irqrestore(&sclp_vt220_lock, flags);
__sclp_vt220_flush_buffer();
}
static void sclp_vt220_pm_event_fn(struct sclp_register *reg,
enum sclp_pm_event sclp_pm_event)
{
switch (sclp_pm_event) {
case SCLP_PM_EVENT_FREEZE:
sclp_vt220_suspend();
break;
case SCLP_PM_EVENT_RESTORE:
case SCLP_PM_EVENT_THAW:
sclp_vt220_resume();
break;
}
}
static void
sclp_vt220_con_write(struct console *con, const char *buf, unsigned int count)
{
__sclp_vt220_write((const unsigned char *) buf, count, 1, 1, 0);
}
static struct tty_driver *
sclp_vt220_con_device(struct console *c, int *index)
{
*index = 0;
return sclp_vt220_driver;
}
static int
sclp_vt220_notify(struct notifier_block *self,
unsigned long event, void *data)
{
__sclp_vt220_flush_buffer();
return NOTIFY_OK;
}
static int __init
sclp_vt220_con_init(void)
{
int rc;
rc = __sclp_vt220_init(sclp_console_pages);
if (rc)
return rc;
atomic_notifier_chain_register(&panic_notifier_list, &on_panic_nb);
register_reboot_notifier(&on_reboot_nb);
register_console(&sclp_vt220_console);
return 0;
}
