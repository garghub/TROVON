static bool acpi_ec_started(struct acpi_ec *ec)
{
return test_bit(EC_FLAGS_STARTED, &ec->flags) &&
!test_bit(EC_FLAGS_STOPPED, &ec->flags);
}
static bool acpi_ec_event_enabled(struct acpi_ec *ec)
{
if (!test_bit(EC_FLAGS_QUERY_ENABLED, &ec->flags))
return false;
if (ec_freeze_events)
return acpi_ec_started(ec);
else
return test_bit(EC_FLAGS_STARTED, &ec->flags);
}
static bool acpi_ec_flushed(struct acpi_ec *ec)
{
return ec->reference_count == 1;
}
static inline u8 acpi_ec_read_status(struct acpi_ec *ec)
{
u8 x = inb(ec->command_addr);
ec_dbg_raw("EC_SC(R) = 0x%2.2x "
"SCI_EVT=%d BURST=%d CMD=%d IBF=%d OBF=%d",
x,
!!(x & ACPI_EC_FLAG_SCI),
!!(x & ACPI_EC_FLAG_BURST),
!!(x & ACPI_EC_FLAG_CMD),
!!(x & ACPI_EC_FLAG_IBF),
!!(x & ACPI_EC_FLAG_OBF));
return x;
}
static inline u8 acpi_ec_read_data(struct acpi_ec *ec)
{
u8 x = inb(ec->data_addr);
ec->timestamp = jiffies;
ec_dbg_raw("EC_DATA(R) = 0x%2.2x", x);
return x;
}
static inline void acpi_ec_write_cmd(struct acpi_ec *ec, u8 command)
{
ec_dbg_raw("EC_SC(W) = 0x%2.2x", command);
outb(command, ec->command_addr);
ec->timestamp = jiffies;
}
static inline void acpi_ec_write_data(struct acpi_ec *ec, u8 data)
{
ec_dbg_raw("EC_DATA(W) = 0x%2.2x", data);
outb(data, ec->data_addr);
ec->timestamp = jiffies;
}
static const char *acpi_ec_cmd_string(u8 cmd)
{
switch (cmd) {
case 0x80:
return "RD_EC";
case 0x81:
return "WR_EC";
case 0x82:
return "BE_EC";
case 0x83:
return "BD_EC";
case 0x84:
return "QR_EC";
}
return "UNKNOWN";
}
static inline bool acpi_ec_is_gpe_raised(struct acpi_ec *ec)
{
acpi_event_status gpe_status = 0;
(void)acpi_get_gpe_status(NULL, ec->gpe, &gpe_status);
return (gpe_status & ACPI_EVENT_FLAG_STATUS_SET) ? true : false;
}
static inline void acpi_ec_enable_gpe(struct acpi_ec *ec, bool open)
{
if (open)
acpi_enable_gpe(NULL, ec->gpe);
else {
BUG_ON(ec->reference_count < 1);
acpi_set_gpe(NULL, ec->gpe, ACPI_GPE_ENABLE);
}
if (acpi_ec_is_gpe_raised(ec)) {
ec_dbg_raw("Polling quirk");
advance_transaction(ec);
}
}
static inline void acpi_ec_disable_gpe(struct acpi_ec *ec, bool close)
{
if (close)
acpi_disable_gpe(NULL, ec->gpe);
else {
BUG_ON(ec->reference_count < 1);
acpi_set_gpe(NULL, ec->gpe, ACPI_GPE_DISABLE);
}
}
static inline void acpi_ec_clear_gpe(struct acpi_ec *ec)
{
if (!acpi_ec_is_gpe_raised(ec))
return;
acpi_clear_gpe(NULL, ec->gpe);
}
static void acpi_ec_submit_request(struct acpi_ec *ec)
{
ec->reference_count++;
if (test_bit(EC_FLAGS_GPE_HANDLER_INSTALLED, &ec->flags) &&
ec->reference_count == 1)
acpi_ec_enable_gpe(ec, true);
}
static void acpi_ec_complete_request(struct acpi_ec *ec)
{
bool flushed = false;
ec->reference_count--;
if (test_bit(EC_FLAGS_GPE_HANDLER_INSTALLED, &ec->flags) &&
ec->reference_count == 0)
acpi_ec_disable_gpe(ec, true);
flushed = acpi_ec_flushed(ec);
if (flushed)
wake_up(&ec->wait);
}
static void acpi_ec_set_storm(struct acpi_ec *ec, u8 flag)
{
if (!test_bit(flag, &ec->flags)) {
acpi_ec_disable_gpe(ec, false);
ec_dbg_drv("Polling enabled");
set_bit(flag, &ec->flags);
}
}
static void acpi_ec_clear_storm(struct acpi_ec *ec, u8 flag)
{
if (test_bit(flag, &ec->flags)) {
clear_bit(flag, &ec->flags);
acpi_ec_enable_gpe(ec, false);
ec_dbg_drv("Polling disabled");
}
}
static bool acpi_ec_submit_flushable_request(struct acpi_ec *ec)
{
if (!acpi_ec_started(ec))
return false;
acpi_ec_submit_request(ec);
return true;
}
static void acpi_ec_submit_query(struct acpi_ec *ec)
{
if (acpi_ec_event_enabled(ec) &&
!test_and_set_bit(EC_FLAGS_QUERY_PENDING, &ec->flags)) {
ec_dbg_evt("Command(%s) submitted/blocked",
acpi_ec_cmd_string(ACPI_EC_COMMAND_QUERY));
ec->nr_pending_queries++;
schedule_work(&ec->work);
}
}
static void acpi_ec_complete_query(struct acpi_ec *ec)
{
if (test_bit(EC_FLAGS_QUERY_PENDING, &ec->flags)) {
clear_bit(EC_FLAGS_QUERY_PENDING, &ec->flags);
ec_dbg_evt("Command(%s) unblocked",
acpi_ec_cmd_string(ACPI_EC_COMMAND_QUERY));
}
}
static inline void __acpi_ec_enable_event(struct acpi_ec *ec)
{
if (!test_and_set_bit(EC_FLAGS_QUERY_ENABLED, &ec->flags))
ec_log_drv("event unblocked");
if (!test_bit(EC_FLAGS_QUERY_PENDING, &ec->flags))
advance_transaction(ec);
}
static inline void __acpi_ec_disable_event(struct acpi_ec *ec)
{
if (test_and_clear_bit(EC_FLAGS_QUERY_ENABLED, &ec->flags))
ec_log_drv("event blocked");
}
static void acpi_ec_clear(struct acpi_ec *ec)
{
int i, status;
u8 value = 0;
for (i = 0; i < ACPI_EC_CLEAR_MAX; i++) {
status = acpi_ec_query(ec, &value);
if (status || !value)
break;
}
if (unlikely(i == ACPI_EC_CLEAR_MAX))
pr_warn("Warning: Maximum of %d stale EC events cleared\n", i);
else
pr_info("%d stale EC events cleared\n", i);
}
static void acpi_ec_enable_event(struct acpi_ec *ec)
{
unsigned long flags;
spin_lock_irqsave(&ec->lock, flags);
if (acpi_ec_started(ec))
__acpi_ec_enable_event(ec);
spin_unlock_irqrestore(&ec->lock, flags);
if (EC_FLAGS_CLEAR_ON_RESUME)
acpi_ec_clear(ec);
}
static bool acpi_ec_query_flushed(struct acpi_ec *ec)
{
bool flushed;
unsigned long flags;
spin_lock_irqsave(&ec->lock, flags);
flushed = !ec->nr_pending_queries;
spin_unlock_irqrestore(&ec->lock, flags);
return flushed;
}
static void __acpi_ec_flush_event(struct acpi_ec *ec)
{
wait_event(ec->wait, acpi_ec_query_flushed(ec));
if (ec_query_wq)
flush_workqueue(ec_query_wq);
}
static void acpi_ec_disable_event(struct acpi_ec *ec)
{
unsigned long flags;
spin_lock_irqsave(&ec->lock, flags);
__acpi_ec_disable_event(ec);
spin_unlock_irqrestore(&ec->lock, flags);
__acpi_ec_flush_event(ec);
}
static bool acpi_ec_guard_event(struct acpi_ec *ec)
{
bool guarded = true;
unsigned long flags;
spin_lock_irqsave(&ec->lock, flags);
if (ec_event_clearing == ACPI_EC_EVT_TIMING_STATUS ||
ec_event_clearing == ACPI_EC_EVT_TIMING_QUERY ||
!test_bit(EC_FLAGS_QUERY_PENDING, &ec->flags) ||
(ec->curr && ec->curr->command == ACPI_EC_COMMAND_QUERY))
guarded = false;
spin_unlock_irqrestore(&ec->lock, flags);
return guarded;
}
static int ec_transaction_polled(struct acpi_ec *ec)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&ec->lock, flags);
if (ec->curr && (ec->curr->flags & ACPI_EC_COMMAND_POLL))
ret = 1;
spin_unlock_irqrestore(&ec->lock, flags);
return ret;
}
static int ec_transaction_completed(struct acpi_ec *ec)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&ec->lock, flags);
if (ec->curr && (ec->curr->flags & ACPI_EC_COMMAND_COMPLETE))
ret = 1;
spin_unlock_irqrestore(&ec->lock, flags);
return ret;
}
static inline void ec_transaction_transition(struct acpi_ec *ec, unsigned long flag)
{
ec->curr->flags |= flag;
if (ec->curr->command == ACPI_EC_COMMAND_QUERY) {
if (ec_event_clearing == ACPI_EC_EVT_TIMING_STATUS &&
flag == ACPI_EC_COMMAND_POLL)
acpi_ec_complete_query(ec);
if (ec_event_clearing == ACPI_EC_EVT_TIMING_QUERY &&
flag == ACPI_EC_COMMAND_COMPLETE)
acpi_ec_complete_query(ec);
if (ec_event_clearing == ACPI_EC_EVT_TIMING_EVENT &&
flag == ACPI_EC_COMMAND_COMPLETE)
set_bit(EC_FLAGS_QUERY_GUARDING, &ec->flags);
}
}
static void advance_transaction(struct acpi_ec *ec)
{
struct transaction *t;
u8 status;
bool wakeup = false;
ec_dbg_stm("%s (%d)", in_interrupt() ? "IRQ" : "TASK",
smp_processor_id());
acpi_ec_clear_gpe(ec);
status = acpi_ec_read_status(ec);
t = ec->curr;
if (!t || !(t->flags & ACPI_EC_COMMAND_POLL)) {
if (ec_event_clearing == ACPI_EC_EVT_TIMING_EVENT &&
(!ec->nr_pending_queries ||
test_bit(EC_FLAGS_QUERY_GUARDING, &ec->flags))) {
clear_bit(EC_FLAGS_QUERY_GUARDING, &ec->flags);
acpi_ec_complete_query(ec);
}
}
if (!t)
goto err;
if (t->flags & ACPI_EC_COMMAND_POLL) {
if (t->wlen > t->wi) {
if ((status & ACPI_EC_FLAG_IBF) == 0)
acpi_ec_write_data(ec, t->wdata[t->wi++]);
else
goto err;
} else if (t->rlen > t->ri) {
if ((status & ACPI_EC_FLAG_OBF) == 1) {
t->rdata[t->ri++] = acpi_ec_read_data(ec);
if (t->rlen == t->ri) {
ec_transaction_transition(ec, ACPI_EC_COMMAND_COMPLETE);
if (t->command == ACPI_EC_COMMAND_QUERY)
ec_dbg_evt("Command(%s) completed by hardware",
acpi_ec_cmd_string(ACPI_EC_COMMAND_QUERY));
wakeup = true;
}
} else
goto err;
} else if (t->wlen == t->wi &&
(status & ACPI_EC_FLAG_IBF) == 0) {
ec_transaction_transition(ec, ACPI_EC_COMMAND_COMPLETE);
wakeup = true;
}
goto out;
} else {
if (EC_FLAGS_QUERY_HANDSHAKE &&
!(status & ACPI_EC_FLAG_SCI) &&
(t->command == ACPI_EC_COMMAND_QUERY)) {
ec_transaction_transition(ec, ACPI_EC_COMMAND_POLL);
t->rdata[t->ri++] = 0x00;
ec_transaction_transition(ec, ACPI_EC_COMMAND_COMPLETE);
ec_dbg_evt("Command(%s) completed by software",
acpi_ec_cmd_string(ACPI_EC_COMMAND_QUERY));
wakeup = true;
} else if ((status & ACPI_EC_FLAG_IBF) == 0) {
acpi_ec_write_cmd(ec, t->command);
ec_transaction_transition(ec, ACPI_EC_COMMAND_POLL);
} else
goto err;
goto out;
}
err:
if (!(status & ACPI_EC_FLAG_SCI)) {
if (in_interrupt() && t) {
if (t->irq_count < ec_storm_threshold)
++t->irq_count;
if (t->irq_count == ec_storm_threshold)
acpi_ec_set_storm(ec, EC_FLAGS_COMMAND_STORM);
}
}
out:
if (status & ACPI_EC_FLAG_SCI)
acpi_ec_submit_query(ec);
if (wakeup && in_interrupt())
wake_up(&ec->wait);
}
static void start_transaction(struct acpi_ec *ec)
{
ec->curr->irq_count = ec->curr->wi = ec->curr->ri = 0;
ec->curr->flags = 0;
}
static int ec_guard(struct acpi_ec *ec)
{
unsigned long guard = usecs_to_jiffies(ec_polling_guard);
unsigned long timeout = ec->timestamp + guard;
do {
if (ec_busy_polling) {
if (ec_transaction_completed(ec))
return 0;
udelay(jiffies_to_usecs(guard));
} else {
if (!ec_transaction_polled(ec) &&
!acpi_ec_guard_event(ec))
break;
if (wait_event_timeout(ec->wait,
ec_transaction_completed(ec),
guard))
return 0;
}
} while (time_before(jiffies, timeout));
return -ETIME;
}
static int ec_poll(struct acpi_ec *ec)
{
unsigned long flags;
int repeat = 5;
while (repeat--) {
unsigned long delay = jiffies +
msecs_to_jiffies(ec_delay);
do {
if (!ec_guard(ec))
return 0;
spin_lock_irqsave(&ec->lock, flags);
advance_transaction(ec);
spin_unlock_irqrestore(&ec->lock, flags);
} while (time_before(jiffies, delay));
pr_debug("controller reset, restart transaction\n");
spin_lock_irqsave(&ec->lock, flags);
start_transaction(ec);
spin_unlock_irqrestore(&ec->lock, flags);
}
return -ETIME;
}
static int acpi_ec_transaction_unlocked(struct acpi_ec *ec,
struct transaction *t)
{
unsigned long tmp;
int ret = 0;
spin_lock_irqsave(&ec->lock, tmp);
if (!acpi_ec_submit_flushable_request(ec)) {
ret = -EINVAL;
goto unlock;
}
ec_dbg_ref(ec, "Increase command");
ec->curr = t;
ec_dbg_req("Command(%s) started", acpi_ec_cmd_string(t->command));
start_transaction(ec);
spin_unlock_irqrestore(&ec->lock, tmp);
ret = ec_poll(ec);
spin_lock_irqsave(&ec->lock, tmp);
if (t->irq_count == ec_storm_threshold)
acpi_ec_clear_storm(ec, EC_FLAGS_COMMAND_STORM);
ec_dbg_req("Command(%s) stopped", acpi_ec_cmd_string(t->command));
ec->curr = NULL;
acpi_ec_complete_request(ec);
ec_dbg_ref(ec, "Decrease command");
unlock:
spin_unlock_irqrestore(&ec->lock, tmp);
return ret;
}
static int acpi_ec_transaction(struct acpi_ec *ec, struct transaction *t)
{
int status;
u32 glk;
if (!ec || (!t) || (t->wlen && !t->wdata) || (t->rlen && !t->rdata))
return -EINVAL;
if (t->rdata)
memset(t->rdata, 0, t->rlen);
mutex_lock(&ec->mutex);
if (ec->global_lock) {
status = acpi_acquire_global_lock(ACPI_EC_UDELAY_GLK, &glk);
if (ACPI_FAILURE(status)) {
status = -ENODEV;
goto unlock;
}
}
status = acpi_ec_transaction_unlocked(ec, t);
if (ec->global_lock)
acpi_release_global_lock(glk);
unlock:
mutex_unlock(&ec->mutex);
return status;
}
static int acpi_ec_burst_enable(struct acpi_ec *ec)
{
u8 d;
struct transaction t = {.command = ACPI_EC_BURST_ENABLE,
.wdata = NULL, .rdata = &d,
.wlen = 0, .rlen = 1};
return acpi_ec_transaction(ec, &t);
}
static int acpi_ec_burst_disable(struct acpi_ec *ec)
{
struct transaction t = {.command = ACPI_EC_BURST_DISABLE,
.wdata = NULL, .rdata = NULL,
.wlen = 0, .rlen = 0};
return (acpi_ec_read_status(ec) & ACPI_EC_FLAG_BURST) ?
acpi_ec_transaction(ec, &t) : 0;
}
static int acpi_ec_read(struct acpi_ec *ec, u8 address, u8 *data)
{
int result;
u8 d;
struct transaction t = {.command = ACPI_EC_COMMAND_READ,
.wdata = &address, .rdata = &d,
.wlen = 1, .rlen = 1};
result = acpi_ec_transaction(ec, &t);
*data = d;
return result;
}
static int acpi_ec_write(struct acpi_ec *ec, u8 address, u8 data)
{
u8 wdata[2] = { address, data };
struct transaction t = {.command = ACPI_EC_COMMAND_WRITE,
.wdata = wdata, .rdata = NULL,
.wlen = 2, .rlen = 0};
return acpi_ec_transaction(ec, &t);
}
int ec_read(u8 addr, u8 *val)
{
int err;
u8 temp_data;
if (!first_ec)
return -ENODEV;
err = acpi_ec_read(first_ec, addr, &temp_data);
if (!err) {
*val = temp_data;
return 0;
}
return err;
}
int ec_write(u8 addr, u8 val)
{
int err;
if (!first_ec)
return -ENODEV;
err = acpi_ec_write(first_ec, addr, val);
return err;
}
int ec_transaction(u8 command,
const u8 *wdata, unsigned wdata_len,
u8 *rdata, unsigned rdata_len)
{
struct transaction t = {.command = command,
.wdata = wdata, .rdata = rdata,
.wlen = wdata_len, .rlen = rdata_len};
if (!first_ec)
return -ENODEV;
return acpi_ec_transaction(first_ec, &t);
}
acpi_handle ec_get_handle(void)
{
if (!first_ec)
return NULL;
return first_ec->handle;
}
static void acpi_ec_start(struct acpi_ec *ec, bool resuming)
{
unsigned long flags;
spin_lock_irqsave(&ec->lock, flags);
if (!test_and_set_bit(EC_FLAGS_STARTED, &ec->flags)) {
ec_dbg_drv("Starting EC");
if (!resuming) {
acpi_ec_submit_request(ec);
ec_dbg_ref(ec, "Increase driver");
}
ec_log_drv("EC started");
}
spin_unlock_irqrestore(&ec->lock, flags);
}
static bool acpi_ec_stopped(struct acpi_ec *ec)
{
unsigned long flags;
bool flushed;
spin_lock_irqsave(&ec->lock, flags);
flushed = acpi_ec_flushed(ec);
spin_unlock_irqrestore(&ec->lock, flags);
return flushed;
}
static void acpi_ec_stop(struct acpi_ec *ec, bool suspending)
{
unsigned long flags;
spin_lock_irqsave(&ec->lock, flags);
if (acpi_ec_started(ec)) {
ec_dbg_drv("Stopping EC");
set_bit(EC_FLAGS_STOPPED, &ec->flags);
spin_unlock_irqrestore(&ec->lock, flags);
wait_event(ec->wait, acpi_ec_stopped(ec));
spin_lock_irqsave(&ec->lock, flags);
if (!suspending) {
acpi_ec_complete_request(ec);
ec_dbg_ref(ec, "Decrease driver");
} else if (!ec_freeze_events)
__acpi_ec_disable_event(ec);
clear_bit(EC_FLAGS_STARTED, &ec->flags);
clear_bit(EC_FLAGS_STOPPED, &ec->flags);
ec_log_drv("EC stopped");
}
spin_unlock_irqrestore(&ec->lock, flags);
}
void acpi_ec_block_transactions(void)
{
struct acpi_ec *ec = first_ec;
if (!ec)
return;
mutex_lock(&ec->mutex);
acpi_ec_stop(ec, true);
mutex_unlock(&ec->mutex);
}
void acpi_ec_unblock_transactions(void)
{
if (first_ec)
acpi_ec_start(first_ec, true);
}
static struct acpi_ec_query_handler *
acpi_ec_get_query_handler(struct acpi_ec_query_handler *handler)
{
if (handler)
kref_get(&handler->kref);
return handler;
}
static struct acpi_ec_query_handler *
acpi_ec_get_query_handler_by_value(struct acpi_ec *ec, u8 value)
{
struct acpi_ec_query_handler *handler;
bool found = false;
mutex_lock(&ec->mutex);
list_for_each_entry(handler, &ec->list, node) {
if (value == handler->query_bit) {
found = true;
break;
}
}
mutex_unlock(&ec->mutex);
return found ? acpi_ec_get_query_handler(handler) : NULL;
}
static void acpi_ec_query_handler_release(struct kref *kref)
{
struct acpi_ec_query_handler *handler =
container_of(kref, struct acpi_ec_query_handler, kref);
kfree(handler);
}
static void acpi_ec_put_query_handler(struct acpi_ec_query_handler *handler)
{
kref_put(&handler->kref, acpi_ec_query_handler_release);
}
int acpi_ec_add_query_handler(struct acpi_ec *ec, u8 query_bit,
acpi_handle handle, acpi_ec_query_func func,
void *data)
{
struct acpi_ec_query_handler *handler =
kzalloc(sizeof(struct acpi_ec_query_handler), GFP_KERNEL);
if (!handler)
return -ENOMEM;
handler->query_bit = query_bit;
handler->handle = handle;
handler->func = func;
handler->data = data;
mutex_lock(&ec->mutex);
kref_init(&handler->kref);
list_add(&handler->node, &ec->list);
mutex_unlock(&ec->mutex);
return 0;
}
static void acpi_ec_remove_query_handlers(struct acpi_ec *ec,
bool remove_all, u8 query_bit)
{
struct acpi_ec_query_handler *handler, *tmp;
LIST_HEAD(free_list);
mutex_lock(&ec->mutex);
list_for_each_entry_safe(handler, tmp, &ec->list, node) {
if (remove_all || query_bit == handler->query_bit) {
list_del_init(&handler->node);
list_add(&handler->node, &free_list);
}
}
mutex_unlock(&ec->mutex);
list_for_each_entry_safe(handler, tmp, &free_list, node)
acpi_ec_put_query_handler(handler);
}
void acpi_ec_remove_query_handler(struct acpi_ec *ec, u8 query_bit)
{
acpi_ec_remove_query_handlers(ec, false, query_bit);
}
static struct acpi_ec_query *acpi_ec_create_query(u8 *pval)
{
struct acpi_ec_query *q;
struct transaction *t;
q = kzalloc(sizeof (struct acpi_ec_query), GFP_KERNEL);
if (!q)
return NULL;
INIT_WORK(&q->work, acpi_ec_event_processor);
t = &q->transaction;
t->command = ACPI_EC_COMMAND_QUERY;
t->rdata = pval;
t->rlen = 1;
return q;
}
static void acpi_ec_delete_query(struct acpi_ec_query *q)
{
if (q) {
if (q->handler)
acpi_ec_put_query_handler(q->handler);
kfree(q);
}
}
static void acpi_ec_event_processor(struct work_struct *work)
{
struct acpi_ec_query *q = container_of(work, struct acpi_ec_query, work);
struct acpi_ec_query_handler *handler = q->handler;
ec_dbg_evt("Query(0x%02x) started", handler->query_bit);
if (handler->func)
handler->func(handler->data);
else if (handler->handle)
acpi_evaluate_object(handler->handle, NULL, NULL, NULL);
ec_dbg_evt("Query(0x%02x) stopped", handler->query_bit);
acpi_ec_delete_query(q);
}
static int acpi_ec_query(struct acpi_ec *ec, u8 *data)
{
u8 value = 0;
int result;
struct acpi_ec_query *q;
q = acpi_ec_create_query(&value);
if (!q)
return -ENOMEM;
result = acpi_ec_transaction(ec, &q->transaction);
if (!value)
result = -ENODATA;
if (result)
goto err_exit;
q->handler = acpi_ec_get_query_handler_by_value(ec, value);
if (!q->handler) {
result = -ENODATA;
goto err_exit;
}
ec_dbg_evt("Query(0x%02x) scheduled", value);
if (!queue_work(ec_query_wq, &q->work)) {
ec_dbg_evt("Query(0x%02x) overlapped", value);
result = -EBUSY;
}
err_exit:
if (result)
acpi_ec_delete_query(q);
if (data)
*data = value;
return result;
}
static void acpi_ec_check_event(struct acpi_ec *ec)
{
unsigned long flags;
if (ec_event_clearing == ACPI_EC_EVT_TIMING_EVENT) {
if (ec_guard(ec)) {
spin_lock_irqsave(&ec->lock, flags);
if (!ec->curr)
advance_transaction(ec);
spin_unlock_irqrestore(&ec->lock, flags);
}
}
}
static void acpi_ec_event_handler(struct work_struct *work)
{
unsigned long flags;
struct acpi_ec *ec = container_of(work, struct acpi_ec, work);
ec_dbg_evt("Event started");
spin_lock_irqsave(&ec->lock, flags);
while (ec->nr_pending_queries) {
spin_unlock_irqrestore(&ec->lock, flags);
(void)acpi_ec_query(ec, NULL);
spin_lock_irqsave(&ec->lock, flags);
ec->nr_pending_queries--;
if (!ec->nr_pending_queries) {
if (ec_event_clearing == ACPI_EC_EVT_TIMING_STATUS ||
ec_event_clearing == ACPI_EC_EVT_TIMING_QUERY)
acpi_ec_complete_query(ec);
}
}
spin_unlock_irqrestore(&ec->lock, flags);
ec_dbg_evt("Event stopped");
acpi_ec_check_event(ec);
}
static u32 acpi_ec_gpe_handler(acpi_handle gpe_device,
u32 gpe_number, void *data)
{
unsigned long flags;
struct acpi_ec *ec = data;
spin_lock_irqsave(&ec->lock, flags);
advance_transaction(ec);
spin_unlock_irqrestore(&ec->lock, flags);
return ACPI_INTERRUPT_HANDLED;
}
static acpi_status
acpi_ec_space_handler(u32 function, acpi_physical_address address,
u32 bits, u64 *value64,
void *handler_context, void *region_context)
{
struct acpi_ec *ec = handler_context;
int result = 0, i, bytes = bits / 8;
u8 *value = (u8 *)value64;
if ((address > 0xFF) || !value || !handler_context)
return AE_BAD_PARAMETER;
if (function != ACPI_READ && function != ACPI_WRITE)
return AE_BAD_PARAMETER;
if (ec_busy_polling || bits > 8)
acpi_ec_burst_enable(ec);
for (i = 0; i < bytes; ++i, ++address, ++value)
result = (function == ACPI_READ) ?
acpi_ec_read(ec, address, value) :
acpi_ec_write(ec, address, *value);
if (ec_busy_polling || bits > 8)
acpi_ec_burst_disable(ec);
switch (result) {
case -EINVAL:
return AE_BAD_PARAMETER;
case -ENODEV:
return AE_NOT_FOUND;
case -ETIME:
return AE_TIME;
default:
return AE_OK;
}
}
static void acpi_ec_free(struct acpi_ec *ec)
{
if (first_ec == ec)
first_ec = NULL;
if (boot_ec == ec)
boot_ec = NULL;
kfree(ec);
}
static struct acpi_ec *acpi_ec_alloc(void)
{
struct acpi_ec *ec = kzalloc(sizeof(struct acpi_ec), GFP_KERNEL);
if (!ec)
return NULL;
mutex_init(&ec->mutex);
init_waitqueue_head(&ec->wait);
INIT_LIST_HEAD(&ec->list);
spin_lock_init(&ec->lock);
INIT_WORK(&ec->work, acpi_ec_event_handler);
ec->timestamp = jiffies;
return ec;
}
static acpi_status
acpi_ec_register_query_methods(acpi_handle handle, u32 level,
void *context, void **return_value)
{
char node_name[5];
struct acpi_buffer buffer = { sizeof(node_name), node_name };
struct acpi_ec *ec = context;
int value = 0;
acpi_status status;
status = acpi_get_name(handle, ACPI_SINGLE_NAME, &buffer);
if (ACPI_SUCCESS(status) && sscanf(node_name, "_Q%x", &value) == 1)
acpi_ec_add_query_handler(ec, value, handle, NULL, NULL);
return AE_OK;
}
static acpi_status
ec_parse_device(acpi_handle handle, u32 Level, void *context, void **retval)
{
acpi_status status;
unsigned long long tmp = 0;
struct acpi_ec *ec = context;
ec->command_addr = ec->data_addr = 0;
status = acpi_walk_resources(handle, METHOD_NAME__CRS,
ec_parse_io_ports, ec);
if (ACPI_FAILURE(status))
return status;
status = acpi_evaluate_integer(handle, "_GPE", NULL, &tmp);
if (ACPI_FAILURE(status))
return status;
ec->gpe = tmp;
tmp = 0;
acpi_evaluate_integer(handle, "_GLK", NULL, &tmp);
ec->global_lock = tmp;
ec->handle = handle;
return AE_CTRL_TERMINATE;
}
static int ec_install_handlers(struct acpi_ec *ec, bool handle_events)
{
acpi_status status;
acpi_ec_start(ec, false);
if (!test_bit(EC_FLAGS_EC_HANDLER_INSTALLED, &ec->flags)) {
status = acpi_install_address_space_handler(ec->handle,
ACPI_ADR_SPACE_EC,
&acpi_ec_space_handler,
NULL, ec);
if (ACPI_FAILURE(status)) {
if (status == AE_NOT_FOUND) {
pr_err("Fail in evaluating the _REG object"
" of EC device. Broken bios is suspected.\n");
} else {
acpi_ec_stop(ec, false);
return -ENODEV;
}
}
set_bit(EC_FLAGS_EC_HANDLER_INSTALLED, &ec->flags);
}
if (!handle_events)
return 0;
if (!test_bit(EC_FLAGS_EVT_HANDLER_INSTALLED, &ec->flags)) {
acpi_walk_namespace(ACPI_TYPE_METHOD, ec->handle, 1,
acpi_ec_register_query_methods,
NULL, ec, NULL);
set_bit(EC_FLAGS_EVT_HANDLER_INSTALLED, &ec->flags);
}
if (!test_bit(EC_FLAGS_GPE_HANDLER_INSTALLED, &ec->flags)) {
status = acpi_install_gpe_raw_handler(NULL, ec->gpe,
ACPI_GPE_EDGE_TRIGGERED,
&acpi_ec_gpe_handler, ec);
if (ACPI_SUCCESS(status)) {
set_bit(EC_FLAGS_GPE_HANDLER_INSTALLED, &ec->flags);
if (test_bit(EC_FLAGS_STARTED, &ec->flags) &&
ec->reference_count >= 1)
acpi_ec_enable_gpe(ec, true);
acpi_ec_enable_event(ec);
}
}
return 0;
}
static void ec_remove_handlers(struct acpi_ec *ec)
{
if (test_bit(EC_FLAGS_EC_HANDLER_INSTALLED, &ec->flags)) {
if (ACPI_FAILURE(acpi_remove_address_space_handler(ec->handle,
ACPI_ADR_SPACE_EC, &acpi_ec_space_handler)))
pr_err("failed to remove space handler\n");
clear_bit(EC_FLAGS_EC_HANDLER_INSTALLED, &ec->flags);
}
acpi_ec_stop(ec, false);
if (test_bit(EC_FLAGS_GPE_HANDLER_INSTALLED, &ec->flags)) {
if (ACPI_FAILURE(acpi_remove_gpe_handler(NULL, ec->gpe,
&acpi_ec_gpe_handler)))
pr_err("failed to remove gpe handler\n");
clear_bit(EC_FLAGS_GPE_HANDLER_INSTALLED, &ec->flags);
}
if (test_bit(EC_FLAGS_EVT_HANDLER_INSTALLED, &ec->flags)) {
acpi_ec_remove_query_handlers(ec, true, 0);
clear_bit(EC_FLAGS_EVT_HANDLER_INSTALLED, &ec->flags);
}
}
static int acpi_ec_setup(struct acpi_ec *ec, bool handle_events)
{
int ret;
ret = ec_install_handlers(ec, handle_events);
if (ret)
return ret;
if (!first_ec) {
first_ec = ec;
acpi_handle_info(first_ec->handle, "Used as first EC\n");
}
acpi_handle_info(ec->handle,
"GPE=0x%lx, EC_CMD/EC_SC=0x%lx, EC_DATA=0x%lx\n",
ec->gpe, ec->command_addr, ec->data_addr);
return ret;
}
static int acpi_config_boot_ec(struct acpi_ec *ec, acpi_handle handle,
bool handle_events, bool is_ecdt)
{
int ret;
if (boot_ec && boot_ec->handle != handle)
ec_remove_handlers(boot_ec);
if (boot_ec != ec)
acpi_ec_free(boot_ec);
if (ec->handle != handle)
ec->handle = handle;
ret = acpi_ec_setup(ec, handle_events);
if (ret)
return ret;
if (!boot_ec) {
boot_ec = ec;
boot_ec_is_ecdt = is_ecdt;
}
acpi_handle_info(boot_ec->handle,
"Used as boot %s EC to handle transactions%s\n",
is_ecdt ? "ECDT" : "DSDT",
handle_events ? " and events" : "");
return ret;
}
static bool acpi_ec_ecdt_get_handle(acpi_handle *phandle)
{
struct acpi_table_ecdt *ecdt_ptr;
acpi_status status;
acpi_handle handle;
status = acpi_get_table(ACPI_SIG_ECDT, 1,
(struct acpi_table_header **)&ecdt_ptr);
if (ACPI_FAILURE(status))
return false;
status = acpi_get_handle(NULL, ecdt_ptr->id, &handle);
if (ACPI_FAILURE(status))
return false;
*phandle = handle;
return true;
}
static bool acpi_is_boot_ec(struct acpi_ec *ec)
{
if (!boot_ec)
return false;
if (ec->handle == boot_ec->handle &&
ec->gpe == boot_ec->gpe &&
ec->command_addr == boot_ec->command_addr &&
ec->data_addr == boot_ec->data_addr)
return true;
return false;
}
static int acpi_ec_add(struct acpi_device *device)
{
struct acpi_ec *ec = NULL;
int ret;
strcpy(acpi_device_name(device), ACPI_EC_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_EC_CLASS);
ec = acpi_ec_alloc();
if (!ec)
return -ENOMEM;
if (ec_parse_device(device->handle, 0, ec, NULL) !=
AE_CTRL_TERMINATE) {
ret = -EINVAL;
goto err_alloc;
}
if (acpi_is_boot_ec(ec)) {
boot_ec_is_ecdt = false;
acpi_handle_debug(ec->handle, "duplicated.\n");
acpi_ec_free(ec);
ec = boot_ec;
ret = acpi_config_boot_ec(ec, ec->handle, true, false);
} else
ret = acpi_ec_setup(ec, true);
if (ret)
goto err_query;
device->driver_data = ec;
ret = !!request_region(ec->data_addr, 1, "EC data");
WARN(!ret, "Could not request EC data io port 0x%lx", ec->data_addr);
ret = !!request_region(ec->command_addr, 1, "EC cmd");
WARN(!ret, "Could not request EC cmd io port 0x%lx", ec->command_addr);
acpi_walk_dep_device_list(ec->handle);
acpi_handle_debug(ec->handle, "enumerated.\n");
return 0;
err_query:
if (ec != boot_ec)
acpi_ec_remove_query_handlers(ec, true, 0);
err_alloc:
if (ec != boot_ec)
acpi_ec_free(ec);
return ret;
}
static int acpi_ec_remove(struct acpi_device *device)
{
struct acpi_ec *ec;
if (!device)
return -EINVAL;
ec = acpi_driver_data(device);
release_region(ec->data_addr, 1);
release_region(ec->command_addr, 1);
device->driver_data = NULL;
if (ec != boot_ec) {
ec_remove_handlers(ec);
acpi_ec_free(ec);
}
return 0;
}
static acpi_status
ec_parse_io_ports(struct acpi_resource *resource, void *context)
{
struct acpi_ec *ec = context;
if (resource->type != ACPI_RESOURCE_TYPE_IO)
return AE_OK;
if (ec->data_addr == 0)
ec->data_addr = resource->data.io.minimum;
else if (ec->command_addr == 0)
ec->command_addr = resource->data.io.minimum;
else
return AE_CTRL_TERMINATE;
return AE_OK;
}
int __init acpi_ec_dsdt_probe(void)
{
acpi_status status;
struct acpi_ec *ec;
int ret;
ec = acpi_ec_alloc();
if (!ec)
return -ENOMEM;
status = acpi_get_devices(ec_device_ids[0].id,
ec_parse_device, ec, NULL);
if (ACPI_FAILURE(status) || !ec->handle) {
ret = -ENODEV;
goto error;
}
ret = acpi_config_boot_ec(ec, ec->handle, false, false);
error:
if (ret)
acpi_ec_free(ec);
return ret;
}
int __init acpi_ec_ecdt_start(void)
{
acpi_handle handle;
if (!boot_ec)
return -ENODEV;
if (!boot_ec_is_ecdt)
return -ENODEV;
if (!acpi_ec_ecdt_get_handle(&handle))
return -ENODEV;
return acpi_config_boot_ec(boot_ec, handle, true, true);
}
static int ec_clear_on_resume(const struct dmi_system_id *id)
{
pr_debug("Detected system needing EC poll on resume.\n");
EC_FLAGS_CLEAR_ON_RESUME = 1;
ec_event_clearing = ACPI_EC_EVT_TIMING_STATUS;
return 0;
}
static int ec_correct_ecdt(const struct dmi_system_id *id)
{
pr_debug("Detected system needing ECDT address correction.\n");
EC_FLAGS_CORRECT_ECDT = 1;
return 0;
}
int __init acpi_ec_ecdt_probe(void)
{
int ret;
acpi_status status;
struct acpi_table_ecdt *ecdt_ptr;
struct acpi_ec *ec;
ec = acpi_ec_alloc();
if (!ec)
return -ENOMEM;
dmi_check_system(ec_dmi_table);
status = acpi_get_table(ACPI_SIG_ECDT, 1,
(struct acpi_table_header **)&ecdt_ptr);
if (ACPI_FAILURE(status)) {
ret = -ENODEV;
goto error;
}
if (!ecdt_ptr->control.address || !ecdt_ptr->data.address) {
ret = -ENODEV;
goto error;
}
if (EC_FLAGS_CORRECT_ECDT) {
ec->command_addr = ecdt_ptr->data.address;
ec->data_addr = ecdt_ptr->control.address;
} else {
ec->command_addr = ecdt_ptr->control.address;
ec->data_addr = ecdt_ptr->data.address;
}
ec->gpe = ecdt_ptr->gpe;
ret = acpi_config_boot_ec(ec, ACPI_ROOT_OBJECT, false, true);
error:
if (ret)
acpi_ec_free(ec);
return ret;
}
static void acpi_ec_enter_noirq(struct acpi_ec *ec)
{
unsigned long flags;
if (ec == first_ec) {
spin_lock_irqsave(&ec->lock, flags);
ec->saved_busy_polling = ec_busy_polling;
ec->saved_polling_guard = ec_polling_guard;
ec_busy_polling = true;
ec_polling_guard = 0;
ec_log_drv("interrupt blocked");
spin_unlock_irqrestore(&ec->lock, flags);
}
}
static void acpi_ec_leave_noirq(struct acpi_ec *ec)
{
unsigned long flags;
if (ec == first_ec) {
spin_lock_irqsave(&ec->lock, flags);
ec_busy_polling = ec->saved_busy_polling;
ec_polling_guard = ec->saved_polling_guard;
ec_log_drv("interrupt unblocked");
spin_unlock_irqrestore(&ec->lock, flags);
}
}
static int acpi_ec_suspend_noirq(struct device *dev)
{
struct acpi_ec *ec =
acpi_driver_data(to_acpi_device(dev));
acpi_ec_enter_noirq(ec);
return 0;
}
static int acpi_ec_resume_noirq(struct device *dev)
{
struct acpi_ec *ec =
acpi_driver_data(to_acpi_device(dev));
acpi_ec_leave_noirq(ec);
return 0;
}
static int acpi_ec_suspend(struct device *dev)
{
struct acpi_ec *ec =
acpi_driver_data(to_acpi_device(dev));
if (ec_freeze_events)
acpi_ec_disable_event(ec);
return 0;
}
static int acpi_ec_resume(struct device *dev)
{
struct acpi_ec *ec =
acpi_driver_data(to_acpi_device(dev));
acpi_ec_enable_event(ec);
return 0;
}
static int param_set_event_clearing(const char *val, struct kernel_param *kp)
{
int result = 0;
if (!strncmp(val, "status", sizeof("status") - 1)) {
ec_event_clearing = ACPI_EC_EVT_TIMING_STATUS;
pr_info("Assuming SCI_EVT clearing on EC_SC accesses\n");
} else if (!strncmp(val, "query", sizeof("query") - 1)) {
ec_event_clearing = ACPI_EC_EVT_TIMING_QUERY;
pr_info("Assuming SCI_EVT clearing on QR_EC writes\n");
} else if (!strncmp(val, "event", sizeof("event") - 1)) {
ec_event_clearing = ACPI_EC_EVT_TIMING_EVENT;
pr_info("Assuming SCI_EVT clearing on event reads\n");
} else
result = -EINVAL;
return result;
}
static int param_get_event_clearing(char *buffer, struct kernel_param *kp)
{
switch (ec_event_clearing) {
case ACPI_EC_EVT_TIMING_STATUS:
return sprintf(buffer, "status");
case ACPI_EC_EVT_TIMING_QUERY:
return sprintf(buffer, "query");
case ACPI_EC_EVT_TIMING_EVENT:
return sprintf(buffer, "event");
default:
return sprintf(buffer, "invalid");
}
return 0;
}
static inline int acpi_ec_query_init(void)
{
if (!ec_query_wq) {
ec_query_wq = alloc_workqueue("kec_query", 0,
ec_max_queries);
if (!ec_query_wq)
return -ENODEV;
}
return 0;
}
static inline void acpi_ec_query_exit(void)
{
if (ec_query_wq) {
destroy_workqueue(ec_query_wq);
ec_query_wq = NULL;
}
}
int __init acpi_ec_init(void)
{
int result;
result = acpi_ec_query_init();
if (result)
goto err_exit;
result = acpi_bus_register_driver(&acpi_ec_driver);
if (result)
goto err_exit;
err_exit:
if (result)
acpi_ec_query_exit();
return result;
}
