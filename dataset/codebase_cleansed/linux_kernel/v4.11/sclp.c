static void sclp_suspend_req_cb(struct sclp_req *req, void *data)
{
complete(&sclp_request_queue_flushed);
}
static int __init sclp_setup_console_pages(char *str)
{
int pages, rc;
rc = kstrtoint(str, 0, &pages);
if (!rc && pages >= SCLP_CONSOLE_PAGES)
sclp_console_pages = pages;
return 1;
}
static int __init sclp_setup_console_drop(char *str)
{
int drop, rc;
rc = kstrtoint(str, 0, &drop);
if (!rc)
sclp_console_drop = drop;
return 1;
}
static void
__sclp_queue_read_req(void)
{
if (sclp_reading_state == sclp_reading_state_idle) {
sclp_reading_state = sclp_reading_state_reading;
__sclp_make_read_req();
list_add(&sclp_read_req.list, &sclp_req_queue);
}
}
static inline void
__sclp_set_request_timer(unsigned long time, void (*function)(unsigned long),
unsigned long data)
{
del_timer(&sclp_request_timer);
sclp_request_timer.function = function;
sclp_request_timer.data = data;
sclp_request_timer.expires = jiffies + time;
add_timer(&sclp_request_timer);
}
static void
sclp_request_timeout(unsigned long data)
{
unsigned long flags;
spin_lock_irqsave(&sclp_lock, flags);
if (data) {
if (sclp_running_state == sclp_running_state_running) {
__sclp_queue_read_req();
sclp_running_state = sclp_running_state_idle;
}
} else {
__sclp_set_request_timer(SCLP_BUSY_INTERVAL * HZ,
sclp_request_timeout, 0);
}
spin_unlock_irqrestore(&sclp_lock, flags);
sclp_process_queue();
}
static unsigned long __sclp_req_queue_find_next_timeout(void)
{
unsigned long expires_next = 0;
struct sclp_req *req;
list_for_each_entry(req, &sclp_req_queue, list) {
if (!req->queue_expires)
continue;
if (!expires_next ||
(time_before(req->queue_expires, expires_next)))
expires_next = req->queue_expires;
}
return expires_next;
}
static struct sclp_req *__sclp_req_queue_remove_expired_req(void)
{
unsigned long flags, now;
struct sclp_req *req;
spin_lock_irqsave(&sclp_lock, flags);
now = jiffies;
list_for_each_entry(req, &sclp_req_queue, list) {
if (!req->queue_expires)
continue;
if (time_before_eq(req->queue_expires, now)) {
if (req->status == SCLP_REQ_QUEUED) {
req->status = SCLP_REQ_QUEUED_TIMEOUT;
list_del(&req->list);
goto out;
}
}
}
req = NULL;
out:
spin_unlock_irqrestore(&sclp_lock, flags);
return req;
}
static void sclp_req_queue_timeout(unsigned long data)
{
unsigned long flags, expires_next;
struct sclp_req *req;
do {
req = __sclp_req_queue_remove_expired_req();
if (req && req->callback)
req->callback(req, req->callback_data);
} while (req);
spin_lock_irqsave(&sclp_lock, flags);
expires_next = __sclp_req_queue_find_next_timeout();
if (expires_next)
mod_timer(&sclp_queue_timer, expires_next);
spin_unlock_irqrestore(&sclp_lock, flags);
}
static int
__sclp_start_request(struct sclp_req *req)
{
int rc;
if (sclp_running_state != sclp_running_state_idle)
return 0;
del_timer(&sclp_request_timer);
rc = sclp_service_call(req->command, req->sccb);
req->start_count++;
if (rc == 0) {
req->status = SCLP_REQ_RUNNING;
sclp_running_state = sclp_running_state_running;
__sclp_set_request_timer(SCLP_RETRY_INTERVAL * HZ,
sclp_request_timeout, 1);
return 0;
} else if (rc == -EBUSY) {
__sclp_set_request_timer(SCLP_BUSY_INTERVAL * HZ,
sclp_request_timeout, 0);
return 0;
}
req->status = SCLP_REQ_FAILED;
return rc;
}
static void
sclp_process_queue(void)
{
struct sclp_req *req;
int rc;
unsigned long flags;
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_running_state != sclp_running_state_idle) {
spin_unlock_irqrestore(&sclp_lock, flags);
return;
}
del_timer(&sclp_request_timer);
while (!list_empty(&sclp_req_queue)) {
req = list_entry(sclp_req_queue.next, struct sclp_req, list);
if (!req->sccb)
goto do_post;
rc = __sclp_start_request(req);
if (rc == 0)
break;
if (req->start_count > 1) {
__sclp_set_request_timer(SCLP_BUSY_INTERVAL * HZ,
sclp_request_timeout, 0);
break;
}
do_post:
list_del(&req->list);
if (req->callback) {
spin_unlock_irqrestore(&sclp_lock, flags);
req->callback(req, req->callback_data);
spin_lock_irqsave(&sclp_lock, flags);
}
}
spin_unlock_irqrestore(&sclp_lock, flags);
}
static int __sclp_can_add_request(struct sclp_req *req)
{
if (req == &sclp_suspend_req || req == &sclp_init_req)
return 1;
if (sclp_suspend_state != sclp_suspend_state_running)
return 0;
if (sclp_init_state != sclp_init_state_initialized)
return 0;
if (sclp_activation_state != sclp_activation_state_active)
return 0;
return 1;
}
int
sclp_add_request(struct sclp_req *req)
{
unsigned long flags;
int rc;
spin_lock_irqsave(&sclp_lock, flags);
if (!__sclp_can_add_request(req)) {
spin_unlock_irqrestore(&sclp_lock, flags);
return -EIO;
}
req->status = SCLP_REQ_QUEUED;
req->start_count = 0;
list_add_tail(&req->list, &sclp_req_queue);
rc = 0;
if (req->queue_timeout) {
req->queue_expires = jiffies + req->queue_timeout * HZ;
if (!timer_pending(&sclp_queue_timer) ||
time_after(sclp_queue_timer.expires, req->queue_expires))
mod_timer(&sclp_queue_timer, req->queue_expires);
} else
req->queue_expires = 0;
if (sclp_running_state == sclp_running_state_idle &&
req->list.prev == &sclp_req_queue) {
if (!req->sccb) {
list_del(&req->list);
rc = -ENODATA;
goto out;
}
rc = __sclp_start_request(req);
if (rc)
list_del(&req->list);
}
out:
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
static int
sclp_dispatch_evbufs(struct sccb_header *sccb)
{
unsigned long flags;
struct evbuf_header *evbuf;
struct list_head *l;
struct sclp_register *reg;
int offset;
int rc;
spin_lock_irqsave(&sclp_lock, flags);
rc = 0;
for (offset = sizeof(struct sccb_header); offset < sccb->length;
offset += evbuf->length) {
evbuf = (struct evbuf_header *) ((addr_t) sccb + offset);
if (evbuf->length == 0)
break;
reg = NULL;
list_for_each(l, &sclp_reg_list) {
reg = list_entry(l, struct sclp_register, list);
if (reg->receive_mask & (1 << (32 - evbuf->type)))
break;
else
reg = NULL;
}
if (reg && reg->receiver_fn) {
spin_unlock_irqrestore(&sclp_lock, flags);
reg->receiver_fn(evbuf);
spin_lock_irqsave(&sclp_lock, flags);
} else if (reg == NULL)
rc = -EOPNOTSUPP;
}
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
static void
sclp_read_cb(struct sclp_req *req, void *data)
{
unsigned long flags;
struct sccb_header *sccb;
sccb = (struct sccb_header *) req->sccb;
if (req->status == SCLP_REQ_DONE && (sccb->response_code == 0x20 ||
sccb->response_code == 0x220))
sclp_dispatch_evbufs(sccb);
spin_lock_irqsave(&sclp_lock, flags);
sclp_reading_state = sclp_reading_state_idle;
spin_unlock_irqrestore(&sclp_lock, flags);
}
static void __sclp_make_read_req(void)
{
struct sccb_header *sccb;
sccb = (struct sccb_header *) sclp_read_sccb;
clear_page(sccb);
memset(&sclp_read_req, 0, sizeof(struct sclp_req));
sclp_read_req.command = SCLP_CMDW_READ_EVENT_DATA;
sclp_read_req.status = SCLP_REQ_QUEUED;
sclp_read_req.start_count = 0;
sclp_read_req.callback = sclp_read_cb;
sclp_read_req.sccb = sccb;
sccb->length = PAGE_SIZE;
sccb->function_code = 0;
sccb->control_mask[2] = 0x80;
}
static inline struct sclp_req *
__sclp_find_req(u32 sccb)
{
struct list_head *l;
struct sclp_req *req;
list_for_each(l, &sclp_req_queue) {
req = list_entry(l, struct sclp_req, list);
if (sccb == (u32) (addr_t) req->sccb)
return req;
}
return NULL;
}
static void sclp_interrupt_handler(struct ext_code ext_code,
unsigned int param32, unsigned long param64)
{
struct sclp_req *req;
u32 finished_sccb;
u32 evbuf_pending;
inc_irq_stat(IRQEXT_SCP);
spin_lock(&sclp_lock);
finished_sccb = param32 & 0xfffffff8;
evbuf_pending = param32 & 0x3;
if (finished_sccb) {
del_timer(&sclp_request_timer);
sclp_running_state = sclp_running_state_reset_pending;
req = __sclp_find_req(finished_sccb);
if (req) {
list_del(&req->list);
req->status = SCLP_REQ_DONE;
if (req->callback) {
spin_unlock(&sclp_lock);
req->callback(req, req->callback_data);
spin_lock(&sclp_lock);
}
}
sclp_running_state = sclp_running_state_idle;
}
if (evbuf_pending &&
sclp_activation_state == sclp_activation_state_active)
__sclp_queue_read_req();
spin_unlock(&sclp_lock);
sclp_process_queue();
}
static inline u64
sclp_tod_from_jiffies(unsigned long jiffies)
{
return (u64) (jiffies / HZ) << 32;
}
void
sclp_sync_wait(void)
{
unsigned long long old_tick;
unsigned long flags;
unsigned long cr0, cr0_sync;
u64 timeout;
int irq_context;
timeout = 0;
if (timer_pending(&sclp_request_timer)) {
timeout = get_tod_clock_fast() +
sclp_tod_from_jiffies(sclp_request_timer.expires -
jiffies);
}
local_irq_save(flags);
irq_context = in_interrupt();
if (!irq_context)
local_bh_disable();
old_tick = local_tick_disable();
trace_hardirqs_on();
__ctl_store(cr0, 0, 0);
cr0_sync = cr0 & ~CR0_IRQ_SUBCLASS_MASK;
cr0_sync |= 1UL << (63 - 54);
__ctl_load(cr0_sync, 0, 0);
__arch_local_irq_stosm(0x01);
while (sclp_running_state != sclp_running_state_idle) {
if (timer_pending(&sclp_request_timer) &&
get_tod_clock_fast() > timeout &&
del_timer(&sclp_request_timer))
sclp_request_timer.function(sclp_request_timer.data);
cpu_relax();
}
local_irq_disable();
__ctl_load(cr0, 0, 0);
if (!irq_context)
_local_bh_enable();
local_tick_enable(old_tick);
local_irq_restore(flags);
}
static void
sclp_dispatch_state_change(void)
{
struct list_head *l;
struct sclp_register *reg;
unsigned long flags;
sccb_mask_t receive_mask;
sccb_mask_t send_mask;
do {
spin_lock_irqsave(&sclp_lock, flags);
reg = NULL;
list_for_each(l, &sclp_reg_list) {
reg = list_entry(l, struct sclp_register, list);
receive_mask = reg->send_mask & sclp_receive_mask;
send_mask = reg->receive_mask & sclp_send_mask;
if (reg->sclp_receive_mask != receive_mask ||
reg->sclp_send_mask != send_mask) {
reg->sclp_receive_mask = receive_mask;
reg->sclp_send_mask = send_mask;
break;
} else
reg = NULL;
}
spin_unlock_irqrestore(&sclp_lock, flags);
if (reg && reg->state_change_fn)
reg->state_change_fn(reg);
} while (reg);
}
static void
sclp_state_change_cb(struct evbuf_header *evbuf)
{
unsigned long flags;
struct sclp_statechangebuf *scbuf;
scbuf = (struct sclp_statechangebuf *) evbuf;
if (scbuf->mask_length != sizeof(sccb_mask_t))
return;
spin_lock_irqsave(&sclp_lock, flags);
if (scbuf->validity_sclp_receive_mask)
sclp_receive_mask = scbuf->sclp_receive_mask;
if (scbuf->validity_sclp_send_mask)
sclp_send_mask = scbuf->sclp_send_mask;
spin_unlock_irqrestore(&sclp_lock, flags);
if (scbuf->validity_sclp_active_facility_mask)
sclp.facilities = scbuf->sclp_active_facility_mask;
sclp_dispatch_state_change();
}
static inline void
__sclp_get_mask(sccb_mask_t *receive_mask, sccb_mask_t *send_mask)
{
struct list_head *l;
struct sclp_register *t;
*receive_mask = 0;
*send_mask = 0;
list_for_each(l, &sclp_reg_list) {
t = list_entry(l, struct sclp_register, list);
*receive_mask |= t->receive_mask;
*send_mask |= t->send_mask;
}
}
int
sclp_register(struct sclp_register *reg)
{
unsigned long flags;
sccb_mask_t receive_mask;
sccb_mask_t send_mask;
int rc;
rc = sclp_init();
if (rc)
return rc;
spin_lock_irqsave(&sclp_lock, flags);
__sclp_get_mask(&receive_mask, &send_mask);
if (reg->receive_mask & receive_mask || reg->send_mask & send_mask) {
spin_unlock_irqrestore(&sclp_lock, flags);
return -EBUSY;
}
reg->sclp_receive_mask = 0;
reg->sclp_send_mask = 0;
reg->pm_event_posted = 0;
list_add(&reg->list, &sclp_reg_list);
spin_unlock_irqrestore(&sclp_lock, flags);
rc = sclp_init_mask(1);
if (rc) {
spin_lock_irqsave(&sclp_lock, flags);
list_del(&reg->list);
spin_unlock_irqrestore(&sclp_lock, flags);
}
return rc;
}
void
sclp_unregister(struct sclp_register *reg)
{
unsigned long flags;
spin_lock_irqsave(&sclp_lock, flags);
list_del(&reg->list);
spin_unlock_irqrestore(&sclp_lock, flags);
sclp_init_mask(1);
}
int
sclp_remove_processed(struct sccb_header *sccb)
{
struct evbuf_header *evbuf;
int unprocessed;
u16 remaining;
evbuf = (struct evbuf_header *) (sccb + 1);
unprocessed = 0;
remaining = sccb->length - sizeof(struct sccb_header);
while (remaining > 0) {
remaining -= evbuf->length;
if (evbuf->flags & 0x80) {
sccb->length -= evbuf->length;
memcpy(evbuf, (void *) ((addr_t) evbuf + evbuf->length),
remaining);
} else {
unprocessed++;
evbuf = (struct evbuf_header *)
((addr_t) evbuf + evbuf->length);
}
}
return unprocessed;
}
static inline void
__sclp_make_init_req(u32 receive_mask, u32 send_mask)
{
struct init_sccb *sccb;
sccb = (struct init_sccb *) sclp_init_sccb;
clear_page(sccb);
memset(&sclp_init_req, 0, sizeof(struct sclp_req));
sclp_init_req.command = SCLP_CMDW_WRITE_EVENT_MASK;
sclp_init_req.status = SCLP_REQ_FILLED;
sclp_init_req.start_count = 0;
sclp_init_req.callback = NULL;
sclp_init_req.callback_data = NULL;
sclp_init_req.sccb = sccb;
sccb->header.length = sizeof(struct init_sccb);
sccb->mask_length = sizeof(sccb_mask_t);
sccb->receive_mask = receive_mask;
sccb->send_mask = send_mask;
sccb->sclp_receive_mask = 0;
sccb->sclp_send_mask = 0;
}
static int
sclp_init_mask(int calculate)
{
unsigned long flags;
struct init_sccb *sccb = (struct init_sccb *) sclp_init_sccb;
sccb_mask_t receive_mask;
sccb_mask_t send_mask;
int retry;
int rc;
unsigned long wait;
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_mask_state != sclp_mask_state_idle) {
spin_unlock_irqrestore(&sclp_lock, flags);
return -EBUSY;
}
if (sclp_activation_state == sclp_activation_state_inactive) {
spin_unlock_irqrestore(&sclp_lock, flags);
return -EINVAL;
}
sclp_mask_state = sclp_mask_state_initializing;
if (calculate)
__sclp_get_mask(&receive_mask, &send_mask);
else {
receive_mask = 0;
send_mask = 0;
}
rc = -EIO;
for (retry = 0; retry <= SCLP_MASK_RETRY; retry++) {
__sclp_make_init_req(receive_mask, send_mask);
spin_unlock_irqrestore(&sclp_lock, flags);
if (sclp_add_request(&sclp_init_req)) {
wait = jiffies + SCLP_BUSY_INTERVAL * HZ;
while (time_before(jiffies, wait))
sclp_sync_wait();
spin_lock_irqsave(&sclp_lock, flags);
continue;
}
while (sclp_init_req.status != SCLP_REQ_DONE &&
sclp_init_req.status != SCLP_REQ_FAILED)
sclp_sync_wait();
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_init_req.status == SCLP_REQ_DONE &&
sccb->header.response_code == 0x20) {
if (calculate) {
sclp_receive_mask = sccb->sclp_receive_mask;
sclp_send_mask = sccb->sclp_send_mask;
} else {
sclp_receive_mask = 0;
sclp_send_mask = 0;
}
spin_unlock_irqrestore(&sclp_lock, flags);
sclp_dispatch_state_change();
spin_lock_irqsave(&sclp_lock, flags);
rc = 0;
break;
}
}
sclp_mask_state = sclp_mask_state_idle;
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
int
sclp_deactivate(void)
{
unsigned long flags;
int rc;
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_activation_state != sclp_activation_state_active) {
spin_unlock_irqrestore(&sclp_lock, flags);
return -EINVAL;
}
sclp_activation_state = sclp_activation_state_deactivating;
spin_unlock_irqrestore(&sclp_lock, flags);
rc = sclp_init_mask(0);
spin_lock_irqsave(&sclp_lock, flags);
if (rc == 0)
sclp_activation_state = sclp_activation_state_inactive;
else
sclp_activation_state = sclp_activation_state_active;
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
int
sclp_reactivate(void)
{
unsigned long flags;
int rc;
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_activation_state != sclp_activation_state_inactive) {
spin_unlock_irqrestore(&sclp_lock, flags);
return -EINVAL;
}
sclp_activation_state = sclp_activation_state_activating;
spin_unlock_irqrestore(&sclp_lock, flags);
rc = sclp_init_mask(1);
spin_lock_irqsave(&sclp_lock, flags);
if (rc == 0)
sclp_activation_state = sclp_activation_state_active;
else
sclp_activation_state = sclp_activation_state_inactive;
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
static void sclp_check_handler(struct ext_code ext_code,
unsigned int param32, unsigned long param64)
{
u32 finished_sccb;
inc_irq_stat(IRQEXT_SCP);
finished_sccb = param32 & 0xfffffff8;
if (finished_sccb == 0)
return;
if (finished_sccb != (u32) (addr_t) sclp_init_sccb)
panic("sclp: unsolicited interrupt for buffer at 0x%x\n",
finished_sccb);
spin_lock(&sclp_lock);
if (sclp_running_state == sclp_running_state_running) {
sclp_init_req.status = SCLP_REQ_DONE;
sclp_running_state = sclp_running_state_idle;
}
spin_unlock(&sclp_lock);
}
static void
sclp_check_timeout(unsigned long data)
{
unsigned long flags;
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_running_state == sclp_running_state_running) {
sclp_init_req.status = SCLP_REQ_FAILED;
sclp_running_state = sclp_running_state_idle;
}
spin_unlock_irqrestore(&sclp_lock, flags);
}
static int
sclp_check_interface(void)
{
struct init_sccb *sccb;
unsigned long flags;
int retry;
int rc;
spin_lock_irqsave(&sclp_lock, flags);
rc = register_external_irq(EXT_IRQ_SERVICE_SIG, sclp_check_handler);
if (rc) {
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
for (retry = 0; retry <= SCLP_INIT_RETRY; retry++) {
__sclp_make_init_req(0, 0);
sccb = (struct init_sccb *) sclp_init_req.sccb;
rc = sclp_service_call(sclp_init_req.command, sccb);
if (rc == -EIO)
break;
sclp_init_req.status = SCLP_REQ_RUNNING;
sclp_running_state = sclp_running_state_running;
__sclp_set_request_timer(SCLP_RETRY_INTERVAL * HZ,
sclp_check_timeout, 0);
spin_unlock_irqrestore(&sclp_lock, flags);
irq_subclass_register(IRQ_SUBCLASS_SERVICE_SIGNAL);
sclp_sync_wait();
irq_subclass_unregister(IRQ_SUBCLASS_SERVICE_SIGNAL);
spin_lock_irqsave(&sclp_lock, flags);
del_timer(&sclp_request_timer);
if (sclp_init_req.status == SCLP_REQ_DONE &&
sccb->header.response_code == 0x20) {
rc = 0;
break;
} else
rc = -EBUSY;
}
unregister_external_irq(EXT_IRQ_SERVICE_SIG, sclp_check_handler);
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
static int
sclp_reboot_event(struct notifier_block *this, unsigned long event, void *ptr)
{
sclp_deactivate();
return NOTIFY_DONE;
}
static void sclp_pm_event(enum sclp_pm_event sclp_pm_event, int rollback)
{
struct sclp_register *reg;
unsigned long flags;
if (!rollback) {
spin_lock_irqsave(&sclp_lock, flags);
list_for_each_entry(reg, &sclp_reg_list, list)
reg->pm_event_posted = 0;
spin_unlock_irqrestore(&sclp_lock, flags);
}
do {
spin_lock_irqsave(&sclp_lock, flags);
list_for_each_entry(reg, &sclp_reg_list, list) {
if (rollback && reg->pm_event_posted)
goto found;
if (!rollback && !reg->pm_event_posted)
goto found;
}
spin_unlock_irqrestore(&sclp_lock, flags);
return;
found:
spin_unlock_irqrestore(&sclp_lock, flags);
if (reg->pm_event_fn)
reg->pm_event_fn(reg, sclp_pm_event);
reg->pm_event_posted = rollback ? 0 : 1;
} while (1);
}
static int sclp_freeze(struct device *dev)
{
unsigned long flags;
int rc;
sclp_pm_event(SCLP_PM_EVENT_FREEZE, 0);
spin_lock_irqsave(&sclp_lock, flags);
sclp_suspend_state = sclp_suspend_state_suspended;
spin_unlock_irqrestore(&sclp_lock, flags);
memset(&sclp_suspend_req, 0, sizeof(sclp_suspend_req));
sclp_suspend_req.callback = sclp_suspend_req_cb;
sclp_suspend_req.status = SCLP_REQ_FILLED;
init_completion(&sclp_request_queue_flushed);
rc = sclp_add_request(&sclp_suspend_req);
if (rc == 0)
wait_for_completion(&sclp_request_queue_flushed);
else if (rc != -ENODATA)
goto fail_thaw;
rc = sclp_deactivate();
if (rc)
goto fail_thaw;
return 0;
fail_thaw:
spin_lock_irqsave(&sclp_lock, flags);
sclp_suspend_state = sclp_suspend_state_running;
spin_unlock_irqrestore(&sclp_lock, flags);
sclp_pm_event(SCLP_PM_EVENT_THAW, 1);
return rc;
}
static int sclp_undo_suspend(enum sclp_pm_event event)
{
unsigned long flags;
int rc;
rc = sclp_reactivate();
if (rc)
return rc;
spin_lock_irqsave(&sclp_lock, flags);
sclp_suspend_state = sclp_suspend_state_running;
spin_unlock_irqrestore(&sclp_lock, flags);
sclp_pm_event(event, 0);
return 0;
}
static int sclp_thaw(struct device *dev)
{
return sclp_undo_suspend(SCLP_PM_EVENT_THAW);
}
static int sclp_restore(struct device *dev)
{
return sclp_undo_suspend(SCLP_PM_EVENT_RESTORE);
}
static ssize_t sclp_show_console_pages(struct device_driver *dev, char *buf)
{
return sprintf(buf, "%i\n", sclp_console_pages);
}
static ssize_t sclp_show_con_drop(struct device_driver *dev, char *buf)
{
return sprintf(buf, "%i\n", sclp_console_drop);
}
static ssize_t sclp_show_console_full(struct device_driver *dev, char *buf)
{
return sprintf(buf, "%lu\n", sclp_console_full);
}
static int
sclp_init(void)
{
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&sclp_lock, flags);
if (sclp_init_state != sclp_init_state_uninitialized)
goto fail_unlock;
sclp_init_state = sclp_init_state_initializing;
INIT_LIST_HEAD(&sclp_req_queue);
INIT_LIST_HEAD(&sclp_reg_list);
list_add(&sclp_state_change_event.list, &sclp_reg_list);
init_timer(&sclp_request_timer);
init_timer(&sclp_queue_timer);
sclp_queue_timer.function = sclp_req_queue_timeout;
spin_unlock_irqrestore(&sclp_lock, flags);
rc = sclp_check_interface();
spin_lock_irqsave(&sclp_lock, flags);
if (rc)
goto fail_init_state_uninitialized;
rc = register_reboot_notifier(&sclp_reboot_notifier);
if (rc)
goto fail_init_state_uninitialized;
rc = register_external_irq(EXT_IRQ_SERVICE_SIG, sclp_interrupt_handler);
if (rc)
goto fail_unregister_reboot_notifier;
sclp_init_state = sclp_init_state_initialized;
spin_unlock_irqrestore(&sclp_lock, flags);
irq_subclass_register(IRQ_SUBCLASS_SERVICE_SIGNAL);
sclp_init_mask(1);
return 0;
fail_unregister_reboot_notifier:
unregister_reboot_notifier(&sclp_reboot_notifier);
fail_init_state_uninitialized:
sclp_init_state = sclp_init_state_uninitialized;
fail_unlock:
spin_unlock_irqrestore(&sclp_lock, flags);
return rc;
}
static int sclp_panic_notify(struct notifier_block *self,
unsigned long event, void *data)
{
if (sclp_suspend_state == sclp_suspend_state_suspended)
sclp_undo_suspend(SCLP_PM_EVENT_THAW);
return NOTIFY_OK;
}
static __init int sclp_initcall(void)
{
int rc;
rc = platform_driver_register(&sclp_pdrv);
if (rc)
return rc;
sclp_pdev = platform_device_register_simple("sclp", -1, NULL, 0);
rc = PTR_ERR_OR_ZERO(sclp_pdev);
if (rc)
goto fail_platform_driver_unregister;
rc = atomic_notifier_chain_register(&panic_notifier_list,
&sclp_on_panic_nb);
if (rc)
goto fail_platform_device_unregister;
return sclp_init();
fail_platform_device_unregister:
platform_device_unregister(sclp_pdev);
fail_platform_driver_unregister:
platform_driver_unregister(&sclp_pdrv);
return rc;
}
