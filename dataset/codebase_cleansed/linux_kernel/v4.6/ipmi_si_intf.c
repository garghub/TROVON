void debug_timestamp(char *msg)
{
struct timespec64 t;
getnstimeofday64(&t);
pr_debug("**%s: %lld.%9.9ld\n", msg, (long long) t.tv_sec, t.tv_nsec);
}
static int register_xaction_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&xaction_notifier_list, nb);
}
static void deliver_recv_msg(struct smi_info *smi_info,
struct ipmi_smi_msg *msg)
{
if (smi_info->intf)
ipmi_smi_msg_received(smi_info->intf, msg);
else
ipmi_free_smi_msg(msg);
}
static void return_hosed_msg(struct smi_info *smi_info, int cCode)
{
struct ipmi_smi_msg *msg = smi_info->curr_msg;
if (cCode < 0 || cCode > IPMI_ERR_UNSPECIFIED)
cCode = IPMI_ERR_UNSPECIFIED;
msg->rsp[0] = msg->data[0] | 4;
msg->rsp[1] = msg->data[1];
msg->rsp[2] = cCode;
msg->rsp_size = 3;
smi_info->curr_msg = NULL;
deliver_recv_msg(smi_info, msg);
}
static enum si_sm_result start_next_msg(struct smi_info *smi_info)
{
int rv;
if (!smi_info->waiting_msg) {
smi_info->curr_msg = NULL;
rv = SI_SM_IDLE;
} else {
int err;
smi_info->curr_msg = smi_info->waiting_msg;
smi_info->waiting_msg = NULL;
debug_timestamp("Start2");
err = atomic_notifier_call_chain(&xaction_notifier_list,
0, smi_info);
if (err & NOTIFY_STOP_MASK) {
rv = SI_SM_CALL_WITHOUT_DELAY;
goto out;
}
err = smi_info->handlers->start_transaction(
smi_info->si_sm,
smi_info->curr_msg->data,
smi_info->curr_msg->data_size);
if (err)
return_hosed_msg(smi_info, err);
rv = SI_SM_CALL_WITHOUT_DELAY;
}
out:
return rv;
}
static void smi_mod_timer(struct smi_info *smi_info, unsigned long new_val)
{
smi_info->last_timeout_jiffies = jiffies;
mod_timer(&smi_info->si_timer, new_val);
smi_info->timer_running = true;
}
static void start_new_msg(struct smi_info *smi_info, unsigned char *msg,
unsigned int size)
{
smi_mod_timer(smi_info, jiffies + SI_TIMEOUT_JIFFIES);
if (smi_info->thread)
wake_up_process(smi_info->thread);
smi_info->handlers->start_transaction(smi_info->si_sm, msg, size);
}
static void start_check_enables(struct smi_info *smi_info, bool start_timer)
{
unsigned char msg[2];
msg[0] = (IPMI_NETFN_APP_REQUEST << 2);
msg[1] = IPMI_GET_BMC_GLOBAL_ENABLES_CMD;
if (start_timer)
start_new_msg(smi_info, msg, 2);
else
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 2);
smi_info->si_state = SI_CHECKING_ENABLES;
}
static void start_clear_flags(struct smi_info *smi_info, bool start_timer)
{
unsigned char msg[3];
msg[0] = (IPMI_NETFN_APP_REQUEST << 2);
msg[1] = IPMI_CLEAR_MSG_FLAGS_CMD;
msg[2] = WDT_PRE_TIMEOUT_INT;
if (start_timer)
start_new_msg(smi_info, msg, 3);
else
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 3);
smi_info->si_state = SI_CLEARING_FLAGS;
}
static void start_getting_msg_queue(struct smi_info *smi_info)
{
smi_info->curr_msg->data[0] = (IPMI_NETFN_APP_REQUEST << 2);
smi_info->curr_msg->data[1] = IPMI_GET_MSG_CMD;
smi_info->curr_msg->data_size = 2;
start_new_msg(smi_info, smi_info->curr_msg->data,
smi_info->curr_msg->data_size);
smi_info->si_state = SI_GETTING_MESSAGES;
}
static void start_getting_events(struct smi_info *smi_info)
{
smi_info->curr_msg->data[0] = (IPMI_NETFN_APP_REQUEST << 2);
smi_info->curr_msg->data[1] = IPMI_READ_EVENT_MSG_BUFFER_CMD;
smi_info->curr_msg->data_size = 2;
start_new_msg(smi_info, smi_info->curr_msg->data,
smi_info->curr_msg->data_size);
smi_info->si_state = SI_GETTING_EVENTS;
}
static inline bool disable_si_irq(struct smi_info *smi_info, bool start_timer)
{
if ((smi_info->irq) && (!smi_info->interrupt_disabled)) {
smi_info->interrupt_disabled = true;
start_check_enables(smi_info, start_timer);
return true;
}
return false;
}
static inline bool enable_si_irq(struct smi_info *smi_info)
{
if ((smi_info->irq) && (smi_info->interrupt_disabled)) {
smi_info->interrupt_disabled = false;
start_check_enables(smi_info, true);
return true;
}
return false;
}
static struct ipmi_smi_msg *alloc_msg_handle_irq(struct smi_info *smi_info)
{
struct ipmi_smi_msg *msg;
msg = ipmi_alloc_smi_msg();
if (!msg) {
if (!disable_si_irq(smi_info, true))
smi_info->si_state = SI_NORMAL;
} else if (enable_si_irq(smi_info)) {
ipmi_free_smi_msg(msg);
msg = NULL;
}
return msg;
}
static void handle_flags(struct smi_info *smi_info)
{
retry:
if (smi_info->msg_flags & WDT_PRE_TIMEOUT_INT) {
smi_inc_stat(smi_info, watchdog_pretimeouts);
start_clear_flags(smi_info, true);
smi_info->msg_flags &= ~WDT_PRE_TIMEOUT_INT;
if (smi_info->intf)
ipmi_smi_watchdog_pretimeout(smi_info->intf);
} else if (smi_info->msg_flags & RECEIVE_MSG_AVAIL) {
smi_info->curr_msg = alloc_msg_handle_irq(smi_info);
if (!smi_info->curr_msg)
return;
start_getting_msg_queue(smi_info);
} else if (smi_info->msg_flags & EVENT_MSG_BUFFER_FULL) {
smi_info->curr_msg = alloc_msg_handle_irq(smi_info);
if (!smi_info->curr_msg)
return;
start_getting_events(smi_info);
} else if (smi_info->msg_flags & OEM_DATA_AVAIL &&
smi_info->oem_data_avail_handler) {
if (smi_info->oem_data_avail_handler(smi_info))
goto retry;
} else
smi_info->si_state = SI_NORMAL;
}
static u8 current_global_enables(struct smi_info *smi_info, u8 base,
bool *irq_on)
{
u8 enables = 0;
if (smi_info->supports_event_msg_buff)
enables |= IPMI_BMC_EVT_MSG_BUFF;
if (((smi_info->irq && !smi_info->interrupt_disabled) ||
smi_info->cannot_disable_irq) &&
!smi_info->irq_enable_broken)
enables |= IPMI_BMC_RCV_MSG_INTR;
if (smi_info->supports_event_msg_buff &&
smi_info->irq && !smi_info->interrupt_disabled &&
!smi_info->irq_enable_broken)
enables |= IPMI_BMC_EVT_MSG_INTR;
*irq_on = enables & (IPMI_BMC_EVT_MSG_INTR | IPMI_BMC_RCV_MSG_INTR);
return enables;
}
static void check_bt_irq(struct smi_info *smi_info, bool irq_on)
{
u8 irqstate = smi_info->io.inputb(&smi_info->io, IPMI_BT_INTMASK_REG);
irqstate &= IPMI_BT_INTMASK_ENABLE_IRQ_BIT;
if ((bool)irqstate == irq_on)
return;
if (irq_on)
smi_info->io.outputb(&smi_info->io, IPMI_BT_INTMASK_REG,
IPMI_BT_INTMASK_ENABLE_IRQ_BIT);
else
smi_info->io.outputb(&smi_info->io, IPMI_BT_INTMASK_REG, 0);
}
static void handle_transaction_done(struct smi_info *smi_info)
{
struct ipmi_smi_msg *msg;
debug_timestamp("Done");
switch (smi_info->si_state) {
case SI_NORMAL:
if (!smi_info->curr_msg)
break;
smi_info->curr_msg->rsp_size
= smi_info->handlers->get_result(
smi_info->si_sm,
smi_info->curr_msg->rsp,
IPMI_MAX_MSG_LENGTH);
msg = smi_info->curr_msg;
smi_info->curr_msg = NULL;
deliver_recv_msg(smi_info, msg);
break;
case SI_GETTING_FLAGS:
{
unsigned char msg[4];
unsigned int len;
len = smi_info->handlers->get_result(smi_info->si_sm, msg, 4);
if (msg[2] != 0) {
smi_info->si_state = SI_NORMAL;
} else if (len < 4) {
smi_info->si_state = SI_NORMAL;
} else {
smi_info->msg_flags = msg[3];
handle_flags(smi_info);
}
break;
}
case SI_CLEARING_FLAGS:
{
unsigned char msg[3];
smi_info->handlers->get_result(smi_info->si_sm, msg, 3);
if (msg[2] != 0) {
dev_warn(smi_info->dev,
"Error clearing flags: %2.2x\n", msg[2]);
}
smi_info->si_state = SI_NORMAL;
break;
}
case SI_GETTING_EVENTS:
{
smi_info->curr_msg->rsp_size
= smi_info->handlers->get_result(
smi_info->si_sm,
smi_info->curr_msg->rsp,
IPMI_MAX_MSG_LENGTH);
msg = smi_info->curr_msg;
smi_info->curr_msg = NULL;
if (msg->rsp[2] != 0) {
msg->done(msg);
smi_info->msg_flags &= ~EVENT_MSG_BUFFER_FULL;
handle_flags(smi_info);
} else {
smi_inc_stat(smi_info, events);
handle_flags(smi_info);
deliver_recv_msg(smi_info, msg);
}
break;
}
case SI_GETTING_MESSAGES:
{
smi_info->curr_msg->rsp_size
= smi_info->handlers->get_result(
smi_info->si_sm,
smi_info->curr_msg->rsp,
IPMI_MAX_MSG_LENGTH);
msg = smi_info->curr_msg;
smi_info->curr_msg = NULL;
if (msg->rsp[2] != 0) {
msg->done(msg);
smi_info->msg_flags &= ~RECEIVE_MSG_AVAIL;
handle_flags(smi_info);
} else {
smi_inc_stat(smi_info, incoming_messages);
handle_flags(smi_info);
deliver_recv_msg(smi_info, msg);
}
break;
}
case SI_CHECKING_ENABLES:
{
unsigned char msg[4];
u8 enables;
bool irq_on;
smi_info->handlers->get_result(smi_info->si_sm, msg, 4);
if (msg[2] != 0) {
dev_warn(smi_info->dev,
"Couldn't get irq info: %x.\n", msg[2]);
dev_warn(smi_info->dev,
"Maybe ok, but ipmi might run very slowly.\n");
smi_info->si_state = SI_NORMAL;
break;
}
enables = current_global_enables(smi_info, 0, &irq_on);
if (smi_info->si_type == SI_BT)
check_bt_irq(smi_info, irq_on);
if (enables != (msg[3] & GLOBAL_ENABLES_MASK)) {
msg[0] = (IPMI_NETFN_APP_REQUEST << 2);
msg[1] = IPMI_SET_BMC_GLOBAL_ENABLES_CMD;
msg[2] = enables | (msg[3] & ~GLOBAL_ENABLES_MASK);
smi_info->handlers->start_transaction(
smi_info->si_sm, msg, 3);
smi_info->si_state = SI_SETTING_ENABLES;
} else if (smi_info->supports_event_msg_buff) {
smi_info->curr_msg = ipmi_alloc_smi_msg();
if (!smi_info->curr_msg) {
smi_info->si_state = SI_NORMAL;
break;
}
start_getting_msg_queue(smi_info);
} else {
smi_info->si_state = SI_NORMAL;
}
break;
}
case SI_SETTING_ENABLES:
{
unsigned char msg[4];
smi_info->handlers->get_result(smi_info->si_sm, msg, 4);
if (msg[2] != 0)
dev_warn(smi_info->dev,
"Could not set the global enables: 0x%x.\n",
msg[2]);
if (smi_info->supports_event_msg_buff) {
smi_info->curr_msg = ipmi_alloc_smi_msg();
if (!smi_info->curr_msg) {
smi_info->si_state = SI_NORMAL;
break;
}
start_getting_msg_queue(smi_info);
} else {
smi_info->si_state = SI_NORMAL;
}
break;
}
}
}
static enum si_sm_result smi_event_handler(struct smi_info *smi_info,
int time)
{
enum si_sm_result si_sm_result;
restart:
si_sm_result = smi_info->handlers->event(smi_info->si_sm, time);
time = 0;
while (si_sm_result == SI_SM_CALL_WITHOUT_DELAY)
si_sm_result = smi_info->handlers->event(smi_info->si_sm, 0);
if (si_sm_result == SI_SM_TRANSACTION_COMPLETE) {
smi_inc_stat(smi_info, complete_transactions);
handle_transaction_done(smi_info);
goto restart;
} else if (si_sm_result == SI_SM_HOSED) {
smi_inc_stat(smi_info, hosed_count);
smi_info->si_state = SI_NORMAL;
if (smi_info->curr_msg != NULL) {
return_hosed_msg(smi_info, IPMI_ERR_UNSPECIFIED);
}
goto restart;
}
if (likely(smi_info->intf) &&
(si_sm_result == SI_SM_ATTN || smi_info->got_attn)) {
unsigned char msg[2];
if (smi_info->si_state != SI_NORMAL) {
smi_info->got_attn = true;
} else {
smi_info->got_attn = false;
smi_inc_stat(smi_info, attentions);
msg[0] = (IPMI_NETFN_APP_REQUEST << 2);
msg[1] = IPMI_GET_MSG_FLAGS_CMD;
start_new_msg(smi_info, msg, 2);
smi_info->si_state = SI_GETTING_FLAGS;
goto restart;
}
}
if (si_sm_result == SI_SM_IDLE) {
smi_inc_stat(smi_info, idles);
si_sm_result = start_next_msg(smi_info);
if (si_sm_result != SI_SM_IDLE)
goto restart;
}
if ((si_sm_result == SI_SM_IDLE)
&& (atomic_read(&smi_info->req_events))) {
atomic_set(&smi_info->req_events, 0);
if (smi_info->supports_event_msg_buff || smi_info->irq) {
start_check_enables(smi_info, true);
} else {
smi_info->curr_msg = alloc_msg_handle_irq(smi_info);
if (!smi_info->curr_msg)
goto out;
start_getting_events(smi_info);
}
goto restart;
}
if (si_sm_result == SI_SM_IDLE && smi_info->timer_running) {
if (del_timer(&smi_info->si_timer))
smi_info->timer_running = false;
}
out:
return si_sm_result;
}
static void check_start_timer_thread(struct smi_info *smi_info)
{
if (smi_info->si_state == SI_NORMAL && smi_info->curr_msg == NULL) {
smi_mod_timer(smi_info, jiffies + SI_TIMEOUT_JIFFIES);
if (smi_info->thread)
wake_up_process(smi_info->thread);
start_next_msg(smi_info);
smi_event_handler(smi_info, 0);
}
}
static void flush_messages(void *send_info)
{
struct smi_info *smi_info = send_info;
enum si_sm_result result;
result = smi_event_handler(smi_info, 0);
while (result != SI_SM_IDLE) {
udelay(SI_SHORT_TIMEOUT_USEC);
result = smi_event_handler(smi_info, SI_SHORT_TIMEOUT_USEC);
}
}
static void sender(void *send_info,
struct ipmi_smi_msg *msg)
{
struct smi_info *smi_info = send_info;
unsigned long flags;
debug_timestamp("Enqueue");
if (smi_info->run_to_completion) {
smi_info->waiting_msg = msg;
return;
}
spin_lock_irqsave(&smi_info->si_lock, flags);
BUG_ON(smi_info->waiting_msg);
smi_info->waiting_msg = msg;
check_start_timer_thread(smi_info);
spin_unlock_irqrestore(&smi_info->si_lock, flags);
}
static void set_run_to_completion(void *send_info, bool i_run_to_completion)
{
struct smi_info *smi_info = send_info;
smi_info->run_to_completion = i_run_to_completion;
if (i_run_to_completion)
flush_messages(smi_info);
}
static inline void ipmi_si_set_not_busy(struct timespec64 *ts)
{
ts->tv_nsec = -1;
}
static inline int ipmi_si_is_busy(struct timespec64 *ts)
{
return ts->tv_nsec != -1;
}
static inline int ipmi_thread_busy_wait(enum si_sm_result smi_result,
const struct smi_info *smi_info,
struct timespec64 *busy_until)
{
unsigned int max_busy_us = 0;
if (smi_info->intf_num < num_max_busy_us)
max_busy_us = kipmid_max_busy_us[smi_info->intf_num];
if (max_busy_us == 0 || smi_result != SI_SM_CALL_WITH_DELAY)
ipmi_si_set_not_busy(busy_until);
else if (!ipmi_si_is_busy(busy_until)) {
getnstimeofday64(busy_until);
timespec64_add_ns(busy_until, max_busy_us*NSEC_PER_USEC);
} else {
struct timespec64 now;
getnstimeofday64(&now);
if (unlikely(timespec64_compare(&now, busy_until) > 0)) {
ipmi_si_set_not_busy(busy_until);
return 0;
}
}
return 1;
}
static int ipmi_thread(void *data)
{
struct smi_info *smi_info = data;
unsigned long flags;
enum si_sm_result smi_result;
struct timespec64 busy_until;
ipmi_si_set_not_busy(&busy_until);
set_user_nice(current, MAX_NICE);
while (!kthread_should_stop()) {
int busy_wait;
spin_lock_irqsave(&(smi_info->si_lock), flags);
smi_result = smi_event_handler(smi_info, 0);
if (smi_result != SI_SM_IDLE && !smi_info->timer_running)
smi_mod_timer(smi_info, jiffies + SI_TIMEOUT_JIFFIES);
spin_unlock_irqrestore(&(smi_info->si_lock), flags);
busy_wait = ipmi_thread_busy_wait(smi_result, smi_info,
&busy_until);
if (smi_result == SI_SM_CALL_WITHOUT_DELAY)
;
else if (smi_result == SI_SM_CALL_WITH_DELAY && busy_wait)
schedule();
else if (smi_result == SI_SM_IDLE) {
if (atomic_read(&smi_info->need_watch)) {
schedule_timeout_interruptible(100);
} else {
__set_current_state(TASK_INTERRUPTIBLE);
schedule();
}
} else
schedule_timeout_interruptible(1);
}
return 0;
}
static void poll(void *send_info)
{
struct smi_info *smi_info = send_info;
unsigned long flags = 0;
bool run_to_completion = smi_info->run_to_completion;
udelay(10);
if (!run_to_completion)
spin_lock_irqsave(&smi_info->si_lock, flags);
smi_event_handler(smi_info, 10);
if (!run_to_completion)
spin_unlock_irqrestore(&smi_info->si_lock, flags);
}
static void request_events(void *send_info)
{
struct smi_info *smi_info = send_info;
if (!smi_info->has_event_buffer)
return;
atomic_set(&smi_info->req_events, 1);
}
static void set_need_watch(void *send_info, bool enable)
{
struct smi_info *smi_info = send_info;
unsigned long flags;
atomic_set(&smi_info->need_watch, enable);
spin_lock_irqsave(&smi_info->si_lock, flags);
check_start_timer_thread(smi_info);
spin_unlock_irqrestore(&smi_info->si_lock, flags);
}
static void smi_timeout(unsigned long data)
{
struct smi_info *smi_info = (struct smi_info *) data;
enum si_sm_result smi_result;
unsigned long flags;
unsigned long jiffies_now;
long time_diff;
long timeout;
spin_lock_irqsave(&(smi_info->si_lock), flags);
debug_timestamp("Timer");
jiffies_now = jiffies;
time_diff = (((long)jiffies_now - (long)smi_info->last_timeout_jiffies)
* SI_USEC_PER_JIFFY);
smi_result = smi_event_handler(smi_info, time_diff);
if ((smi_info->irq) && (!smi_info->interrupt_disabled)) {
timeout = jiffies + SI_TIMEOUT_JIFFIES;
smi_inc_stat(smi_info, long_timeouts);
goto do_mod_timer;
}
if (smi_result == SI_SM_CALL_WITH_DELAY) {
smi_inc_stat(smi_info, short_timeouts);
timeout = jiffies + 1;
} else {
smi_inc_stat(smi_info, long_timeouts);
timeout = jiffies + SI_TIMEOUT_JIFFIES;
}
do_mod_timer:
if (smi_result != SI_SM_IDLE)
smi_mod_timer(smi_info, timeout);
else
smi_info->timer_running = false;
spin_unlock_irqrestore(&(smi_info->si_lock), flags);
}
static irqreturn_t si_irq_handler(int irq, void *data)
{
struct smi_info *smi_info = data;
unsigned long flags;
spin_lock_irqsave(&(smi_info->si_lock), flags);
smi_inc_stat(smi_info, interrupts);
debug_timestamp("Interrupt");
smi_event_handler(smi_info, 0);
spin_unlock_irqrestore(&(smi_info->si_lock), flags);
return IRQ_HANDLED;
}
static irqreturn_t si_bt_irq_handler(int irq, void *data)
{
struct smi_info *smi_info = data;
smi_info->io.outputb(&smi_info->io, IPMI_BT_INTMASK_REG,
IPMI_BT_INTMASK_CLEAR_IRQ_BIT
| IPMI_BT_INTMASK_ENABLE_IRQ_BIT);
return si_irq_handler(irq, data);
}
static int smi_start_processing(void *send_info,
ipmi_smi_t intf)
{
struct smi_info *new_smi = send_info;
int enable = 0;
new_smi->intf = intf;
setup_timer(&new_smi->si_timer, smi_timeout, (long)new_smi);
smi_mod_timer(new_smi, jiffies + SI_TIMEOUT_JIFFIES);
if (new_smi->irq_setup)
new_smi->irq_setup(new_smi);
if (new_smi->intf_num < num_force_kipmid)
enable = force_kipmid[new_smi->intf_num];
else if ((new_smi->si_type != SI_BT) && (!new_smi->irq))
enable = 1;
if (enable) {
new_smi->thread = kthread_run(ipmi_thread, new_smi,
"kipmi%d", new_smi->intf_num);
if (IS_ERR(new_smi->thread)) {
dev_notice(new_smi->dev, "Could not start"
" kernel thread due to error %ld, only using"
" timers to drive the interface\n",
PTR_ERR(new_smi->thread));
new_smi->thread = NULL;
}
}
return 0;
}
static int get_smi_info(void *send_info, struct ipmi_smi_info *data)
{
struct smi_info *smi = send_info;
data->addr_src = smi->addr_source;
data->dev = smi->dev;
data->addr_info = smi->addr_info;
get_device(smi->dev);
return 0;
}
static void set_maintenance_mode(void *send_info, bool enable)
{
struct smi_info *smi_info = send_info;
if (!enable)
atomic_set(&smi_info->req_events, 0);
}
static void std_irq_cleanup(struct smi_info *info)
{
if (info->si_type == SI_BT)
info->io.outputb(&info->io, IPMI_BT_INTMASK_REG, 0);
free_irq(info->irq, info);
}
static int std_irq_setup(struct smi_info *info)
{
int rv;
if (!info->irq)
return 0;
if (info->si_type == SI_BT) {
rv = request_irq(info->irq,
si_bt_irq_handler,
IRQF_SHARED,
DEVICE_NAME,
info);
if (!rv)
info->io.outputb(&info->io, IPMI_BT_INTMASK_REG,
IPMI_BT_INTMASK_ENABLE_IRQ_BIT);
} else
rv = request_irq(info->irq,
si_irq_handler,
IRQF_SHARED,
DEVICE_NAME,
info);
if (rv) {
dev_warn(info->dev, "%s unable to claim interrupt %d,"
" running polled\n",
DEVICE_NAME, info->irq);
info->irq = 0;
} else {
info->irq_cleanup = std_irq_cleanup;
dev_info(info->dev, "Using irq %d\n", info->irq);
}
return rv;
}
static unsigned char port_inb(const struct si_sm_io *io, unsigned int offset)
{
unsigned int addr = io->addr_data;
return inb(addr + (offset * io->regspacing));
}
static void port_outb(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
unsigned int addr = io->addr_data;
outb(b, addr + (offset * io->regspacing));
}
static unsigned char port_inw(const struct si_sm_io *io, unsigned int offset)
{
unsigned int addr = io->addr_data;
return (inw(addr + (offset * io->regspacing)) >> io->regshift) & 0xff;
}
static void port_outw(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
unsigned int addr = io->addr_data;
outw(b << io->regshift, addr + (offset * io->regspacing));
}
static unsigned char port_inl(const struct si_sm_io *io, unsigned int offset)
{
unsigned int addr = io->addr_data;
return (inl(addr + (offset * io->regspacing)) >> io->regshift) & 0xff;
}
static void port_outl(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
unsigned int addr = io->addr_data;
outl(b << io->regshift, addr+(offset * io->regspacing));
}
static void port_cleanup(struct smi_info *info)
{
unsigned int addr = info->io.addr_data;
int idx;
if (addr) {
for (idx = 0; idx < info->io_size; idx++)
release_region(addr + idx * info->io.regspacing,
info->io.regsize);
}
}
static int port_setup(struct smi_info *info)
{
unsigned int addr = info->io.addr_data;
int idx;
if (!addr)
return -ENODEV;
info->io_cleanup = port_cleanup;
switch (info->io.regsize) {
case 1:
info->io.inputb = port_inb;
info->io.outputb = port_outb;
break;
case 2:
info->io.inputb = port_inw;
info->io.outputb = port_outw;
break;
case 4:
info->io.inputb = port_inl;
info->io.outputb = port_outl;
break;
default:
dev_warn(info->dev, "Invalid register size: %d\n",
info->io.regsize);
return -EINVAL;
}
for (idx = 0; idx < info->io_size; idx++) {
if (request_region(addr + idx * info->io.regspacing,
info->io.regsize, DEVICE_NAME) == NULL) {
while (idx--) {
release_region(addr + idx * info->io.regspacing,
info->io.regsize);
}
return -EIO;
}
}
return 0;
}
static unsigned char intf_mem_inb(const struct si_sm_io *io,
unsigned int offset)
{
return readb((io->addr)+(offset * io->regspacing));
}
static void intf_mem_outb(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
writeb(b, (io->addr)+(offset * io->regspacing));
}
static unsigned char intf_mem_inw(const struct si_sm_io *io,
unsigned int offset)
{
return (readw((io->addr)+(offset * io->regspacing)) >> io->regshift)
& 0xff;
}
static void intf_mem_outw(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
writeb(b << io->regshift, (io->addr)+(offset * io->regspacing));
}
static unsigned char intf_mem_inl(const struct si_sm_io *io,
unsigned int offset)
{
return (readl((io->addr)+(offset * io->regspacing)) >> io->regshift)
& 0xff;
}
static void intf_mem_outl(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
writel(b << io->regshift, (io->addr)+(offset * io->regspacing));
}
static unsigned char mem_inq(const struct si_sm_io *io, unsigned int offset)
{
return (readq((io->addr)+(offset * io->regspacing)) >> io->regshift)
& 0xff;
}
static void mem_outq(const struct si_sm_io *io, unsigned int offset,
unsigned char b)
{
writeq(b << io->regshift, (io->addr)+(offset * io->regspacing));
}
static void mem_cleanup(struct smi_info *info)
{
unsigned long addr = info->io.addr_data;
int mapsize;
if (info->io.addr) {
iounmap(info->io.addr);
mapsize = ((info->io_size * info->io.regspacing)
- (info->io.regspacing - info->io.regsize));
release_mem_region(addr, mapsize);
}
}
static int mem_setup(struct smi_info *info)
{
unsigned long addr = info->io.addr_data;
int mapsize;
if (!addr)
return -ENODEV;
info->io_cleanup = mem_cleanup;
switch (info->io.regsize) {
case 1:
info->io.inputb = intf_mem_inb;
info->io.outputb = intf_mem_outb;
break;
case 2:
info->io.inputb = intf_mem_inw;
info->io.outputb = intf_mem_outw;
break;
case 4:
info->io.inputb = intf_mem_inl;
info->io.outputb = intf_mem_outl;
break;
#ifdef readq
case 8:
info->io.inputb = mem_inq;
info->io.outputb = mem_outq;
break;
#endif
default:
dev_warn(info->dev, "Invalid register size: %d\n",
info->io.regsize);
return -EINVAL;
}
mapsize = ((info->io_size * info->io.regspacing)
- (info->io.regspacing - info->io.regsize));
if (request_mem_region(addr, mapsize, DEVICE_NAME) == NULL)
return -EIO;
info->io.addr = ioremap(addr, mapsize);
if (info->io.addr == NULL) {
release_mem_region(addr, mapsize);
return -EIO;
}
return 0;
}
static int parse_str(const struct hotmod_vals *v, int *val, char *name,
char **curr)
{
char *s;
int i;
s = strchr(*curr, ',');
if (!s) {
printk(KERN_WARNING PFX "No hotmod %s given.\n", name);
return -EINVAL;
}
*s = '\0';
s++;
for (i = 0; v[i].name; i++) {
if (strcmp(*curr, v[i].name) == 0) {
*val = v[i].val;
*curr = s;
return 0;
}
}
printk(KERN_WARNING PFX "Invalid hotmod %s '%s'\n", name, *curr);
return -EINVAL;
}
static int check_hotmod_int_op(const char *curr, const char *option,
const char *name, int *val)
{
char *n;
if (strcmp(curr, name) == 0) {
if (!option) {
printk(KERN_WARNING PFX
"No option given for '%s'\n",
curr);
return -EINVAL;
}
*val = simple_strtoul(option, &n, 0);
if ((*n != '\0') || (*option == '\0')) {
printk(KERN_WARNING PFX
"Bad option given for '%s'\n",
curr);
return -EINVAL;
}
return 1;
}
return 0;
}
static struct smi_info *smi_info_alloc(void)
{
struct smi_info *info = kzalloc(sizeof(*info), GFP_KERNEL);
if (info)
spin_lock_init(&info->si_lock);
return info;
}
static int hotmod_handler(const char *val, struct kernel_param *kp)
{
char *str = kstrdup(val, GFP_KERNEL);
int rv;
char *next, *curr, *s, *n, *o;
enum hotmod_op op;
enum si_type si_type;
int addr_space;
unsigned long addr;
int regspacing;
int regsize;
int regshift;
int irq;
int ipmb;
int ival;
int len;
struct smi_info *info;
if (!str)
return -ENOMEM;
len = strlen(str);
ival = len - 1;
while ((ival >= 0) && isspace(str[ival])) {
str[ival] = '\0';
ival--;
}
for (curr = str; curr; curr = next) {
regspacing = 1;
regsize = 1;
regshift = 0;
irq = 0;
ipmb = 0;
next = strchr(curr, ':');
if (next) {
*next = '\0';
next++;
}
rv = parse_str(hotmod_ops, &ival, "operation", &curr);
if (rv)
break;
op = ival;
rv = parse_str(hotmod_si, &ival, "interface type", &curr);
if (rv)
break;
si_type = ival;
rv = parse_str(hotmod_as, &addr_space, "address space", &curr);
if (rv)
break;
s = strchr(curr, ',');
if (s) {
*s = '\0';
s++;
}
addr = simple_strtoul(curr, &n, 0);
if ((*n != '\0') || (*curr == '\0')) {
printk(KERN_WARNING PFX "Invalid hotmod address"
" '%s'\n", curr);
break;
}
while (s) {
curr = s;
s = strchr(curr, ',');
if (s) {
*s = '\0';
s++;
}
o = strchr(curr, '=');
if (o) {
*o = '\0';
o++;
}
rv = check_hotmod_int_op(curr, o, "rsp", &regspacing);
if (rv < 0)
goto out;
else if (rv)
continue;
rv = check_hotmod_int_op(curr, o, "rsi", &regsize);
if (rv < 0)
goto out;
else if (rv)
continue;
rv = check_hotmod_int_op(curr, o, "rsh", &regshift);
if (rv < 0)
goto out;
else if (rv)
continue;
rv = check_hotmod_int_op(curr, o, "irq", &irq);
if (rv < 0)
goto out;
else if (rv)
continue;
rv = check_hotmod_int_op(curr, o, "ipmb", &ipmb);
if (rv < 0)
goto out;
else if (rv)
continue;
rv = -EINVAL;
printk(KERN_WARNING PFX
"Invalid hotmod option '%s'\n",
curr);
goto out;
}
if (op == HM_ADD) {
info = smi_info_alloc();
if (!info) {
rv = -ENOMEM;
goto out;
}
info->addr_source = SI_HOTMOD;
info->si_type = si_type;
info->io.addr_data = addr;
info->io.addr_type = addr_space;
if (addr_space == IPMI_MEM_ADDR_SPACE)
info->io_setup = mem_setup;
else
info->io_setup = port_setup;
info->io.addr = NULL;
info->io.regspacing = regspacing;
if (!info->io.regspacing)
info->io.regspacing = DEFAULT_REGSPACING;
info->io.regsize = regsize;
if (!info->io.regsize)
info->io.regsize = DEFAULT_REGSPACING;
info->io.regshift = regshift;
info->irq = irq;
if (info->irq)
info->irq_setup = std_irq_setup;
info->slave_addr = ipmb;
rv = add_smi(info);
if (rv) {
kfree(info);
goto out;
}
rv = try_smi_init(info);
if (rv) {
cleanup_one_si(info);
goto out;
}
} else {
struct smi_info *e, *tmp_e;
mutex_lock(&smi_infos_lock);
list_for_each_entry_safe(e, tmp_e, &smi_infos, link) {
if (e->io.addr_type != addr_space)
continue;
if (e->si_type != si_type)
continue;
if (e->io.addr_data == addr)
cleanup_one_si(e);
}
mutex_unlock(&smi_infos_lock);
}
}
rv = len;
out:
kfree(str);
return rv;
}
static int hardcode_find_bmc(void)
{
int ret = -ENODEV;
int i;
struct smi_info *info;
for (i = 0; i < SI_MAX_PARMS; i++) {
if (!ports[i] && !addrs[i])
continue;
info = smi_info_alloc();
if (!info)
return -ENOMEM;
info->addr_source = SI_HARDCODED;
printk(KERN_INFO PFX "probing via hardcoded address\n");
if (!si_type[i] || strcmp(si_type[i], "kcs") == 0) {
info->si_type = SI_KCS;
} else if (strcmp(si_type[i], "smic") == 0) {
info->si_type = SI_SMIC;
} else if (strcmp(si_type[i], "bt") == 0) {
info->si_type = SI_BT;
} else {
printk(KERN_WARNING PFX "Interface type specified "
"for interface %d, was invalid: %s\n",
i, si_type[i]);
kfree(info);
continue;
}
if (ports[i]) {
info->io_setup = port_setup;
info->io.addr_data = ports[i];
info->io.addr_type = IPMI_IO_ADDR_SPACE;
} else if (addrs[i]) {
info->io_setup = mem_setup;
info->io.addr_data = addrs[i];
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
} else {
printk(KERN_WARNING PFX "Interface type specified "
"for interface %d, but port and address were "
"not set or set to zero.\n", i);
kfree(info);
continue;
}
info->io.addr = NULL;
info->io.regspacing = regspacings[i];
if (!info->io.regspacing)
info->io.regspacing = DEFAULT_REGSPACING;
info->io.regsize = regsizes[i];
if (!info->io.regsize)
info->io.regsize = DEFAULT_REGSPACING;
info->io.regshift = regshifts[i];
info->irq = irqs[i];
if (info->irq)
info->irq_setup = std_irq_setup;
info->slave_addr = slave_addrs[i];
if (!add_smi(info)) {
if (try_smi_init(info))
cleanup_one_si(info);
ret = 0;
} else {
kfree(info);
}
}
return ret;
}
static u32 ipmi_acpi_gpe(acpi_handle gpe_device,
u32 gpe_number, void *context)
{
struct smi_info *smi_info = context;
unsigned long flags;
spin_lock_irqsave(&(smi_info->si_lock), flags);
smi_inc_stat(smi_info, interrupts);
debug_timestamp("ACPI_GPE");
smi_event_handler(smi_info, 0);
spin_unlock_irqrestore(&(smi_info->si_lock), flags);
return ACPI_INTERRUPT_HANDLED;
}
static void acpi_gpe_irq_cleanup(struct smi_info *info)
{
if (!info->irq)
return;
acpi_remove_gpe_handler(NULL, info->irq, &ipmi_acpi_gpe);
}
static int acpi_gpe_irq_setup(struct smi_info *info)
{
acpi_status status;
if (!info->irq)
return 0;
status = acpi_install_gpe_handler(NULL,
info->irq,
ACPI_GPE_LEVEL_TRIGGERED,
&ipmi_acpi_gpe,
info);
if (status != AE_OK) {
dev_warn(info->dev, "%s unable to claim ACPI GPE %d,"
" running polled\n", DEVICE_NAME, info->irq);
info->irq = 0;
return -EINVAL;
} else {
info->irq_cleanup = acpi_gpe_irq_cleanup;
dev_info(info->dev, "Using ACPI GPE %d\n", info->irq);
return 0;
}
}
static int try_init_spmi(struct SPMITable *spmi)
{
struct smi_info *info;
int rv;
if (spmi->IPMIlegacy != 1) {
printk(KERN_INFO PFX "Bad SPMI legacy %d\n", spmi->IPMIlegacy);
return -ENODEV;
}
info = smi_info_alloc();
if (!info) {
printk(KERN_ERR PFX "Could not allocate SI data (3)\n");
return -ENOMEM;
}
info->addr_source = SI_SPMI;
printk(KERN_INFO PFX "probing via SPMI\n");
switch (spmi->InterfaceType) {
case 1:
info->si_type = SI_KCS;
break;
case 2:
info->si_type = SI_SMIC;
break;
case 3:
info->si_type = SI_BT;
break;
case 4:
kfree(info);
return -EIO;
default:
printk(KERN_INFO PFX "Unknown ACPI/SPMI SI type %d\n",
spmi->InterfaceType);
kfree(info);
return -EIO;
}
if (spmi->InterruptType & 1) {
info->irq = spmi->GPE;
info->irq_setup = acpi_gpe_irq_setup;
} else if (spmi->InterruptType & 2) {
info->irq = spmi->GlobalSystemInterrupt;
info->irq_setup = std_irq_setup;
} else {
info->irq = 0;
info->irq_setup = NULL;
}
if (spmi->addr.bit_width) {
info->io.regspacing = spmi->addr.bit_width / 8;
} else {
info->io.regspacing = DEFAULT_REGSPACING;
}
info->io.regsize = info->io.regspacing;
info->io.regshift = spmi->addr.bit_offset;
if (spmi->addr.space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY) {
info->io_setup = mem_setup;
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
} else if (spmi->addr.space_id == ACPI_ADR_SPACE_SYSTEM_IO) {
info->io_setup = port_setup;
info->io.addr_type = IPMI_IO_ADDR_SPACE;
} else {
kfree(info);
printk(KERN_WARNING PFX "Unknown ACPI I/O Address type\n");
return -EIO;
}
info->io.addr_data = spmi->addr.address;
pr_info("ipmi_si: SPMI: %s %#lx regsize %d spacing %d irq %d\n",
(info->io.addr_type == IPMI_IO_ADDR_SPACE) ? "io" : "mem",
info->io.addr_data, info->io.regsize, info->io.regspacing,
info->irq);
rv = add_smi(info);
if (rv)
kfree(info);
return rv;
}
static void spmi_find_bmc(void)
{
acpi_status status;
struct SPMITable *spmi;
int i;
if (acpi_disabled)
return;
if (acpi_failure)
return;
for (i = 0; ; i++) {
status = acpi_get_table(ACPI_SIG_SPMI, i+1,
(struct acpi_table_header **)&spmi);
if (status != AE_OK)
return;
try_init_spmi(spmi);
}
}
static int decode_dmi(const struct dmi_header *dm,
struct dmi_ipmi_data *dmi)
{
const u8 *data = (const u8 *)dm;
unsigned long base_addr;
u8 reg_spacing;
u8 len = dm->length;
dmi->type = data[4];
memcpy(&base_addr, data+8, sizeof(unsigned long));
if (len >= 0x11) {
if (base_addr & 1) {
base_addr &= 0xFFFE;
dmi->addr_space = IPMI_IO_ADDR_SPACE;
} else
dmi->addr_space = IPMI_MEM_ADDR_SPACE;
dmi->base_addr = base_addr | ((data[0x10] & 0x10) >> 4);
dmi->irq = data[0x11];
reg_spacing = (data[0x10] & 0xC0) >> 6;
switch (reg_spacing) {
case 0x00:
dmi->offset = 1;
break;
case 0x01:
dmi->offset = 4;
break;
case 0x02:
dmi->offset = 16;
break;
default:
return -EIO;
}
} else {
dmi->base_addr = base_addr & 0xfffe;
dmi->addr_space = IPMI_IO_ADDR_SPACE;
dmi->offset = 1;
}
dmi->slave_addr = data[6];
return 0;
}
static void try_init_dmi(struct dmi_ipmi_data *ipmi_data)
{
struct smi_info *info;
info = smi_info_alloc();
if (!info) {
printk(KERN_ERR PFX "Could not allocate SI data\n");
return;
}
info->addr_source = SI_SMBIOS;
printk(KERN_INFO PFX "probing via SMBIOS\n");
switch (ipmi_data->type) {
case 0x01:
info->si_type = SI_KCS;
break;
case 0x02:
info->si_type = SI_SMIC;
break;
case 0x03:
info->si_type = SI_BT;
break;
default:
kfree(info);
return;
}
switch (ipmi_data->addr_space) {
case IPMI_MEM_ADDR_SPACE:
info->io_setup = mem_setup;
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
break;
case IPMI_IO_ADDR_SPACE:
info->io_setup = port_setup;
info->io.addr_type = IPMI_IO_ADDR_SPACE;
break;
default:
kfree(info);
printk(KERN_WARNING PFX "Unknown SMBIOS I/O Address type: %d\n",
ipmi_data->addr_space);
return;
}
info->io.addr_data = ipmi_data->base_addr;
info->io.regspacing = ipmi_data->offset;
if (!info->io.regspacing)
info->io.regspacing = DEFAULT_REGSPACING;
info->io.regsize = DEFAULT_REGSPACING;
info->io.regshift = 0;
info->slave_addr = ipmi_data->slave_addr;
info->irq = ipmi_data->irq;
if (info->irq)
info->irq_setup = std_irq_setup;
pr_info("ipmi_si: SMBIOS: %s %#lx regsize %d spacing %d irq %d\n",
(info->io.addr_type == IPMI_IO_ADDR_SPACE) ? "io" : "mem",
info->io.addr_data, info->io.regsize, info->io.regspacing,
info->irq);
if (add_smi(info))
kfree(info);
}
static void dmi_find_bmc(void)
{
const struct dmi_device *dev = NULL;
struct dmi_ipmi_data data;
int rv;
while ((dev = dmi_find_device(DMI_DEV_TYPE_IPMI, NULL, dev))) {
memset(&data, 0, sizeof(data));
rv = decode_dmi((const struct dmi_header *) dev->device_data,
&data);
if (!rv)
try_init_dmi(&data);
}
}
static void ipmi_pci_cleanup(struct smi_info *info)
{
struct pci_dev *pdev = info->addr_source_data;
pci_disable_device(pdev);
}
static int ipmi_pci_probe_regspacing(struct smi_info *info)
{
if (info->si_type == SI_KCS) {
unsigned char status;
int regspacing;
info->io.regsize = DEFAULT_REGSIZE;
info->io.regshift = 0;
info->io_size = 2;
info->handlers = &kcs_smi_handlers;
for (regspacing = DEFAULT_REGSPACING; regspacing <= 16;) {
info->io.regspacing = regspacing;
if (info->io_setup(info)) {
dev_err(info->dev,
"Could not setup I/O space\n");
return DEFAULT_REGSPACING;
}
info->io.outputb(&info->io, 1, 0x10);
status = info->io.inputb(&info->io, 1);
info->io_cleanup(info);
if (status)
return regspacing;
regspacing *= 4;
}
}
return DEFAULT_REGSPACING;
}
static int ipmi_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rv;
int class_type = pdev->class & PCI_ERMC_CLASSCODE_TYPE_MASK;
struct smi_info *info;
info = smi_info_alloc();
if (!info)
return -ENOMEM;
info->addr_source = SI_PCI;
dev_info(&pdev->dev, "probing via PCI");
switch (class_type) {
case PCI_ERMC_CLASSCODE_TYPE_SMIC:
info->si_type = SI_SMIC;
break;
case PCI_ERMC_CLASSCODE_TYPE_KCS:
info->si_type = SI_KCS;
break;
case PCI_ERMC_CLASSCODE_TYPE_BT:
info->si_type = SI_BT;
break;
default:
kfree(info);
dev_info(&pdev->dev, "Unknown IPMI type: %d\n", class_type);
return -ENOMEM;
}
rv = pci_enable_device(pdev);
if (rv) {
dev_err(&pdev->dev, "couldn't enable PCI device\n");
kfree(info);
return rv;
}
info->addr_source_cleanup = ipmi_pci_cleanup;
info->addr_source_data = pdev;
if (pci_resource_flags(pdev, 0) & IORESOURCE_IO) {
info->io_setup = port_setup;
info->io.addr_type = IPMI_IO_ADDR_SPACE;
} else {
info->io_setup = mem_setup;
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
}
info->io.addr_data = pci_resource_start(pdev, 0);
info->io.regspacing = ipmi_pci_probe_regspacing(info);
info->io.regsize = DEFAULT_REGSIZE;
info->io.regshift = 0;
info->irq = pdev->irq;
if (info->irq)
info->irq_setup = std_irq_setup;
info->dev = &pdev->dev;
pci_set_drvdata(pdev, info);
dev_info(&pdev->dev, "%pR regsize %d spacing %d irq %d\n",
&pdev->resource[0], info->io.regsize, info->io.regspacing,
info->irq);
rv = add_smi(info);
if (rv) {
kfree(info);
pci_disable_device(pdev);
}
return rv;
}
static void ipmi_pci_remove(struct pci_dev *pdev)
{
struct smi_info *info = pci_get_drvdata(pdev);
cleanup_one_si(info);
}
static int of_ipmi_probe(struct platform_device *dev)
{
const struct of_device_id *match;
struct smi_info *info;
struct resource resource;
const __be32 *regsize, *regspacing, *regshift;
struct device_node *np = dev->dev.of_node;
int ret;
int proplen;
dev_info(&dev->dev, "probing via device tree\n");
match = of_match_device(of_ipmi_match, &dev->dev);
if (!match)
return -ENODEV;
if (!of_device_is_available(np))
return -EINVAL;
ret = of_address_to_resource(np, 0, &resource);
if (ret) {
dev_warn(&dev->dev, PFX "invalid address from OF\n");
return ret;
}
regsize = of_get_property(np, "reg-size", &proplen);
if (regsize && proplen != 4) {
dev_warn(&dev->dev, PFX "invalid regsize from OF\n");
return -EINVAL;
}
regspacing = of_get_property(np, "reg-spacing", &proplen);
if (regspacing && proplen != 4) {
dev_warn(&dev->dev, PFX "invalid regspacing from OF\n");
return -EINVAL;
}
regshift = of_get_property(np, "reg-shift", &proplen);
if (regshift && proplen != 4) {
dev_warn(&dev->dev, PFX "invalid regshift from OF\n");
return -EINVAL;
}
info = smi_info_alloc();
if (!info) {
dev_err(&dev->dev,
"could not allocate memory for OF probe\n");
return -ENOMEM;
}
info->si_type = (enum si_type) match->data;
info->addr_source = SI_DEVICETREE;
info->irq_setup = std_irq_setup;
if (resource.flags & IORESOURCE_IO) {
info->io_setup = port_setup;
info->io.addr_type = IPMI_IO_ADDR_SPACE;
} else {
info->io_setup = mem_setup;
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
}
info->io.addr_data = resource.start;
info->io.regsize = regsize ? be32_to_cpup(regsize) : DEFAULT_REGSIZE;
info->io.regspacing = regspacing ? be32_to_cpup(regspacing) : DEFAULT_REGSPACING;
info->io.regshift = regshift ? be32_to_cpup(regshift) : 0;
info->irq = irq_of_parse_and_map(dev->dev.of_node, 0);
info->dev = &dev->dev;
dev_dbg(&dev->dev, "addr 0x%lx regsize %d spacing %d irq %d\n",
info->io.addr_data, info->io.regsize, info->io.regspacing,
info->irq);
dev_set_drvdata(&dev->dev, info);
ret = add_smi(info);
if (ret) {
kfree(info);
return ret;
}
return 0;
}
static int of_ipmi_probe(struct platform_device *dev)
{
return -ENODEV;
}
static int acpi_ipmi_probe(struct platform_device *dev)
{
struct smi_info *info;
struct resource *res, *res_second;
acpi_handle handle;
acpi_status status;
unsigned long long tmp;
int rv = -EINVAL;
if (!si_tryacpi)
return 0;
handle = ACPI_HANDLE(&dev->dev);
if (!handle)
return -ENODEV;
info = smi_info_alloc();
if (!info)
return -ENOMEM;
info->addr_source = SI_ACPI;
dev_info(&dev->dev, PFX "probing via ACPI\n");
info->addr_info.acpi_info.acpi_handle = handle;
status = acpi_evaluate_integer(handle, "_IFT", NULL, &tmp);
if (ACPI_FAILURE(status)) {
dev_err(&dev->dev, "Could not find ACPI IPMI interface type\n");
goto err_free;
}
switch (tmp) {
case 1:
info->si_type = SI_KCS;
break;
case 2:
info->si_type = SI_SMIC;
break;
case 3:
info->si_type = SI_BT;
break;
case 4:
rv = -ENODEV;
goto err_free;
default:
dev_info(&dev->dev, "unknown IPMI type %lld\n", tmp);
goto err_free;
}
res = platform_get_resource(dev, IORESOURCE_IO, 0);
if (res) {
info->io_setup = port_setup;
info->io.addr_type = IPMI_IO_ADDR_SPACE;
} else {
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res) {
info->io_setup = mem_setup;
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
}
}
if (!res) {
dev_err(&dev->dev, "no I/O or memory address\n");
goto err_free;
}
info->io.addr_data = res->start;
info->io.regspacing = DEFAULT_REGSPACING;
res_second = platform_get_resource(dev,
(info->io.addr_type == IPMI_IO_ADDR_SPACE) ?
IORESOURCE_IO : IORESOURCE_MEM,
1);
if (res_second) {
if (res_second->start > info->io.addr_data)
info->io.regspacing =
res_second->start - info->io.addr_data;
}
info->io.regsize = DEFAULT_REGSPACING;
info->io.regshift = 0;
status = acpi_evaluate_integer(handle, "_GPE", NULL, &tmp);
if (ACPI_SUCCESS(status)) {
info->irq = tmp;
info->irq_setup = acpi_gpe_irq_setup;
} else {
int irq = platform_get_irq(dev, 0);
if (irq > 0) {
info->irq = irq;
info->irq_setup = std_irq_setup;
}
}
info->dev = &dev->dev;
platform_set_drvdata(dev, info);
dev_info(info->dev, "%pR regsize %d spacing %d irq %d\n",
res, info->io.regsize, info->io.regspacing,
info->irq);
rv = add_smi(info);
if (rv)
kfree(info);
return rv;
err_free:
kfree(info);
return rv;
}
static int acpi_ipmi_probe(struct platform_device *dev)
{
return -ENODEV;
}
static int ipmi_probe(struct platform_device *dev)
{
if (of_ipmi_probe(dev) == 0)
return 0;
return acpi_ipmi_probe(dev);
}
static int ipmi_remove(struct platform_device *dev)
{
struct smi_info *info = dev_get_drvdata(&dev->dev);
cleanup_one_si(info);
return 0;
}
static int ipmi_parisc_probe(struct parisc_device *dev)
{
struct smi_info *info;
int rv;
info = smi_info_alloc();
if (!info) {
dev_err(&dev->dev,
"could not allocate memory for PARISC probe\n");
return -ENOMEM;
}
info->si_type = SI_KCS;
info->addr_source = SI_DEVICETREE;
info->io_setup = mem_setup;
info->io.addr_type = IPMI_MEM_ADDR_SPACE;
info->io.addr_data = dev->hpa.start;
info->io.regsize = 1;
info->io.regspacing = 1;
info->io.regshift = 0;
info->irq = 0;
info->irq_setup = NULL;
info->dev = &dev->dev;
dev_dbg(&dev->dev, "addr 0x%lx\n", info->io.addr_data);
dev_set_drvdata(&dev->dev, info);
rv = add_smi(info);
if (rv) {
kfree(info);
return rv;
}
return 0;
}
static int ipmi_parisc_remove(struct parisc_device *dev)
{
cleanup_one_si(dev_get_drvdata(&dev->dev));
return 0;
}
static int wait_for_msg_done(struct smi_info *smi_info)
{
enum si_sm_result smi_result;
smi_result = smi_info->handlers->event(smi_info->si_sm, 0);
for (;;) {
if (smi_result == SI_SM_CALL_WITH_DELAY ||
smi_result == SI_SM_CALL_WITH_TICK_DELAY) {
schedule_timeout_uninterruptible(1);
smi_result = smi_info->handlers->event(
smi_info->si_sm, jiffies_to_usecs(1));
} else if (smi_result == SI_SM_CALL_WITHOUT_DELAY) {
smi_result = smi_info->handlers->event(
smi_info->si_sm, 0);
} else
break;
}
if (smi_result == SI_SM_HOSED)
return -ENODEV;
return 0;
}
static int try_get_dev_id(struct smi_info *smi_info)
{
unsigned char msg[2];
unsigned char *resp;
unsigned long resp_len;
int rv = 0;
resp = kmalloc(IPMI_MAX_MSG_LENGTH, GFP_KERNEL);
if (!resp)
return -ENOMEM;
msg[0] = IPMI_NETFN_APP_REQUEST << 2;
msg[1] = IPMI_GET_DEVICE_ID_CMD;
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 2);
rv = wait_for_msg_done(smi_info);
if (rv)
goto out;
resp_len = smi_info->handlers->get_result(smi_info->si_sm,
resp, IPMI_MAX_MSG_LENGTH);
rv = ipmi_demangle_device_id(resp, resp_len, &smi_info->device_id);
out:
kfree(resp);
return rv;
}
static int get_global_enables(struct smi_info *smi_info, u8 *enables)
{
unsigned char msg[3];
unsigned char *resp;
unsigned long resp_len;
int rv;
resp = kmalloc(IPMI_MAX_MSG_LENGTH, GFP_KERNEL);
if (!resp)
return -ENOMEM;
msg[0] = IPMI_NETFN_APP_REQUEST << 2;
msg[1] = IPMI_GET_BMC_GLOBAL_ENABLES_CMD;
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 2);
rv = wait_for_msg_done(smi_info);
if (rv) {
dev_warn(smi_info->dev,
"Error getting response from get global enables command: %d\n",
rv);
goto out;
}
resp_len = smi_info->handlers->get_result(smi_info->si_sm,
resp, IPMI_MAX_MSG_LENGTH);
if (resp_len < 4 ||
resp[0] != (IPMI_NETFN_APP_REQUEST | 1) << 2 ||
resp[1] != IPMI_GET_BMC_GLOBAL_ENABLES_CMD ||
resp[2] != 0) {
dev_warn(smi_info->dev,
"Invalid return from get global enables command: %ld %x %x %x\n",
resp_len, resp[0], resp[1], resp[2]);
rv = -EINVAL;
goto out;
} else {
*enables = resp[3];
}
out:
kfree(resp);
return rv;
}
static int set_global_enables(struct smi_info *smi_info, u8 enables)
{
unsigned char msg[3];
unsigned char *resp;
unsigned long resp_len;
int rv;
resp = kmalloc(IPMI_MAX_MSG_LENGTH, GFP_KERNEL);
if (!resp)
return -ENOMEM;
msg[0] = IPMI_NETFN_APP_REQUEST << 2;
msg[1] = IPMI_SET_BMC_GLOBAL_ENABLES_CMD;
msg[2] = enables;
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 3);
rv = wait_for_msg_done(smi_info);
if (rv) {
dev_warn(smi_info->dev,
"Error getting response from set global enables command: %d\n",
rv);
goto out;
}
resp_len = smi_info->handlers->get_result(smi_info->si_sm,
resp, IPMI_MAX_MSG_LENGTH);
if (resp_len < 3 ||
resp[0] != (IPMI_NETFN_APP_REQUEST | 1) << 2 ||
resp[1] != IPMI_SET_BMC_GLOBAL_ENABLES_CMD) {
dev_warn(smi_info->dev,
"Invalid return from set global enables command: %ld %x %x\n",
resp_len, resp[0], resp[1]);
rv = -EINVAL;
goto out;
}
if (resp[2] != 0)
rv = 1;
out:
kfree(resp);
return rv;
}
static void check_clr_rcv_irq(struct smi_info *smi_info)
{
u8 enables = 0;
int rv;
rv = get_global_enables(smi_info, &enables);
if (!rv) {
if ((enables & IPMI_BMC_RCV_MSG_INTR) == 0)
return;
enables &= ~IPMI_BMC_RCV_MSG_INTR;
rv = set_global_enables(smi_info, enables);
}
if (rv < 0) {
dev_err(smi_info->dev,
"Cannot check clearing the rcv irq: %d\n", rv);
return;
}
if (rv) {
dev_warn(smi_info->dev,
"The BMC does not support clearing the recv irq bit, compensating, but the BMC needs to be fixed.\n");
smi_info->cannot_disable_irq = true;
}
}
static void check_set_rcv_irq(struct smi_info *smi_info)
{
u8 enables = 0;
int rv;
if (!smi_info->irq)
return;
rv = get_global_enables(smi_info, &enables);
if (!rv) {
enables |= IPMI_BMC_RCV_MSG_INTR;
rv = set_global_enables(smi_info, enables);
}
if (rv < 0) {
dev_err(smi_info->dev,
"Cannot check setting the rcv irq: %d\n", rv);
return;
}
if (rv) {
dev_warn(smi_info->dev,
"The BMC does not support setting the recv irq bit, compensating, but the BMC needs to be fixed.\n");
smi_info->cannot_disable_irq = true;
smi_info->irq_enable_broken = true;
}
}
static int try_enable_event_buffer(struct smi_info *smi_info)
{
unsigned char msg[3];
unsigned char *resp;
unsigned long resp_len;
int rv = 0;
resp = kmalloc(IPMI_MAX_MSG_LENGTH, GFP_KERNEL);
if (!resp)
return -ENOMEM;
msg[0] = IPMI_NETFN_APP_REQUEST << 2;
msg[1] = IPMI_GET_BMC_GLOBAL_ENABLES_CMD;
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 2);
rv = wait_for_msg_done(smi_info);
if (rv) {
printk(KERN_WARNING PFX "Error getting response from get"
" global enables command, the event buffer is not"
" enabled.\n");
goto out;
}
resp_len = smi_info->handlers->get_result(smi_info->si_sm,
resp, IPMI_MAX_MSG_LENGTH);
if (resp_len < 4 ||
resp[0] != (IPMI_NETFN_APP_REQUEST | 1) << 2 ||
resp[1] != IPMI_GET_BMC_GLOBAL_ENABLES_CMD ||
resp[2] != 0) {
printk(KERN_WARNING PFX "Invalid return from get global"
" enables command, cannot enable the event buffer.\n");
rv = -EINVAL;
goto out;
}
if (resp[3] & IPMI_BMC_EVT_MSG_BUFF) {
smi_info->supports_event_msg_buff = true;
goto out;
}
msg[0] = IPMI_NETFN_APP_REQUEST << 2;
msg[1] = IPMI_SET_BMC_GLOBAL_ENABLES_CMD;
msg[2] = resp[3] | IPMI_BMC_EVT_MSG_BUFF;
smi_info->handlers->start_transaction(smi_info->si_sm, msg, 3);
rv = wait_for_msg_done(smi_info);
if (rv) {
printk(KERN_WARNING PFX "Error getting response from set"
" global, enables command, the event buffer is not"
" enabled.\n");
goto out;
}
resp_len = smi_info->handlers->get_result(smi_info->si_sm,
resp, IPMI_MAX_MSG_LENGTH);
if (resp_len < 3 ||
resp[0] != (IPMI_NETFN_APP_REQUEST | 1) << 2 ||
resp[1] != IPMI_SET_BMC_GLOBAL_ENABLES_CMD) {
printk(KERN_WARNING PFX "Invalid return from get global,"
"enables command, not enable the event buffer.\n");
rv = -EINVAL;
goto out;
}
if (resp[2] != 0)
rv = -ENOENT;
else
smi_info->supports_event_msg_buff = true;
out:
kfree(resp);
return rv;
}
static int smi_type_proc_show(struct seq_file *m, void *v)
{
struct smi_info *smi = m->private;
seq_printf(m, "%s\n", si_to_str[smi->si_type]);
return 0;
}
static int smi_type_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, smi_type_proc_show, PDE_DATA(inode));
}
static int smi_si_stats_proc_show(struct seq_file *m, void *v)
{
struct smi_info *smi = m->private;
seq_printf(m, "interrupts_enabled: %d\n",
smi->irq && !smi->interrupt_disabled);
seq_printf(m, "short_timeouts: %u\n",
smi_get_stat(smi, short_timeouts));
seq_printf(m, "long_timeouts: %u\n",
smi_get_stat(smi, long_timeouts));
seq_printf(m, "idles: %u\n",
smi_get_stat(smi, idles));
seq_printf(m, "interrupts: %u\n",
smi_get_stat(smi, interrupts));
seq_printf(m, "attentions: %u\n",
smi_get_stat(smi, attentions));
seq_printf(m, "flag_fetches: %u\n",
smi_get_stat(smi, flag_fetches));
seq_printf(m, "hosed_count: %u\n",
smi_get_stat(smi, hosed_count));
seq_printf(m, "complete_transactions: %u\n",
smi_get_stat(smi, complete_transactions));
seq_printf(m, "events: %u\n",
smi_get_stat(smi, events));
seq_printf(m, "watchdog_pretimeouts: %u\n",
smi_get_stat(smi, watchdog_pretimeouts));
seq_printf(m, "incoming_messages: %u\n",
smi_get_stat(smi, incoming_messages));
return 0;
}
static int smi_si_stats_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, smi_si_stats_proc_show, PDE_DATA(inode));
}
static int smi_params_proc_show(struct seq_file *m, void *v)
{
struct smi_info *smi = m->private;
seq_printf(m,
"%s,%s,0x%lx,rsp=%d,rsi=%d,rsh=%d,irq=%d,ipmb=%d\n",
si_to_str[smi->si_type],
addr_space_to_str[smi->io.addr_type],
smi->io.addr_data,
smi->io.regspacing,
smi->io.regsize,
smi->io.regshift,
smi->irq,
smi->slave_addr);
return 0;
}
static int smi_params_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, smi_params_proc_show, PDE_DATA(inode));
}
static int oem_data_avail_to_receive_msg_avail(struct smi_info *smi_info)
{
smi_info->msg_flags = ((smi_info->msg_flags & ~OEM_DATA_AVAIL) |
RECEIVE_MSG_AVAIL);
return 1;
}
static void setup_dell_poweredge_oem_data_handler(struct smi_info *smi_info)
{
struct ipmi_device_id *id = &smi_info->device_id;
if (id->manufacturer_id == DELL_IANA_MFR_ID) {
if (id->device_id == DELL_POWEREDGE_8G_BMC_DEVICE_ID &&
id->device_revision == DELL_POWEREDGE_8G_BMC_DEVICE_REV &&
id->ipmi_version == DELL_POWEREDGE_8G_BMC_IPMI_VERSION) {
smi_info->oem_data_avail_handler =
oem_data_avail_to_receive_msg_avail;
} else if (ipmi_version_major(id) < 1 ||
(ipmi_version_major(id) == 1 &&
ipmi_version_minor(id) < 5)) {
smi_info->oem_data_avail_handler =
oem_data_avail_to_receive_msg_avail;
}
}
}
static void return_hosed_msg_badsize(struct smi_info *smi_info)
{
struct ipmi_smi_msg *msg = smi_info->curr_msg;
msg->rsp[0] = msg->data[0] | 4;
msg->rsp[1] = msg->data[1];
msg->rsp[2] = CANNOT_RETURN_REQUESTED_LENGTH;
msg->rsp_size = 3;
smi_info->curr_msg = NULL;
deliver_recv_msg(smi_info, msg);
}
static int dell_poweredge_bt_xaction_handler(struct notifier_block *self,
unsigned long unused,
void *in)
{
struct smi_info *smi_info = in;
unsigned char *data = smi_info->curr_msg->data;
unsigned int size = smi_info->curr_msg->data_size;
if (size >= 8 &&
(data[0]>>2) == STORAGE_NETFN &&
data[1] == STORAGE_CMD_GET_SDR &&
data[7] == 0x3A) {
return_hosed_msg_badsize(smi_info);
return NOTIFY_STOP;
}
return NOTIFY_DONE;
}
static void
setup_dell_poweredge_bt_xaction_handler(struct smi_info *smi_info)
{
struct ipmi_device_id *id = &smi_info->device_id;
if (id->manufacturer_id == DELL_IANA_MFR_ID &&
smi_info->si_type == SI_BT)
register_xaction_notifier(&dell_poweredge_bt_xaction_notifier);
}
static void setup_oem_data_handler(struct smi_info *smi_info)
{
setup_dell_poweredge_oem_data_handler(smi_info);
}
static void setup_xaction_handlers(struct smi_info *smi_info)
{
setup_dell_poweredge_bt_xaction_handler(smi_info);
}
static void check_for_broken_irqs(struct smi_info *smi_info)
{
check_clr_rcv_irq(smi_info);
check_set_rcv_irq(smi_info);
}
static inline void wait_for_timer_and_thread(struct smi_info *smi_info)
{
if (smi_info->thread != NULL)
kthread_stop(smi_info->thread);
if (smi_info->timer_running)
del_timer_sync(&smi_info->si_timer);
}
static void default_find_bmc(void)
{
struct smi_info *info;
int i;
for (i = 0; ; i++) {
if (!ipmi_defaults[i].port)
break;
#ifdef CONFIG_PPC
if (check_legacy_ioport(ipmi_defaults[i].port))
continue;
#endif
info = smi_info_alloc();
if (!info)
return;
info->addr_source = SI_DEFAULT;
info->si_type = ipmi_defaults[i].type;
info->io_setup = port_setup;
info->io.addr_data = ipmi_defaults[i].port;
info->io.addr_type = IPMI_IO_ADDR_SPACE;
info->io.addr = NULL;
info->io.regspacing = DEFAULT_REGSPACING;
info->io.regsize = DEFAULT_REGSPACING;
info->io.regshift = 0;
if (add_smi(info) == 0) {
if ((try_smi_init(info)) == 0) {
printk(KERN_INFO PFX "Found default %s"
" state machine at %s address 0x%lx\n",
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data);
} else
cleanup_one_si(info);
} else {
kfree(info);
}
}
}
static int is_new_interface(struct smi_info *info)
{
struct smi_info *e;
list_for_each_entry(e, &smi_infos, link) {
if (e->io.addr_type != info->io.addr_type)
continue;
if (e->io.addr_data == info->io.addr_data)
return 0;
}
return 1;
}
static int add_smi(struct smi_info *new_smi)
{
int rv = 0;
printk(KERN_INFO PFX "Adding %s-specified %s state machine",
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type]);
mutex_lock(&smi_infos_lock);
if (!is_new_interface(new_smi)) {
printk(KERN_CONT " duplicate interface\n");
rv = -EBUSY;
goto out_err;
}
printk(KERN_CONT "\n");
new_smi->intf = NULL;
new_smi->si_sm = NULL;
new_smi->handlers = NULL;
list_add_tail(&new_smi->link, &smi_infos);
out_err:
mutex_unlock(&smi_infos_lock);
return rv;
}
static int try_smi_init(struct smi_info *new_smi)
{
int rv = 0;
int i;
printk(KERN_INFO PFX "Trying %s-specified %s state"
" machine at %s address 0x%lx, slave address 0x%x,"
" irq %d\n",
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq);
switch (new_smi->si_type) {
case SI_KCS:
new_smi->handlers = &kcs_smi_handlers;
break;
case SI_SMIC:
new_smi->handlers = &smic_smi_handlers;
break;
case SI_BT:
new_smi->handlers = &bt_smi_handlers;
break;
default:
rv = -EIO;
goto out_err;
}
new_smi->si_sm = kmalloc(new_smi->handlers->size(), GFP_KERNEL);
if (!new_smi->si_sm) {
printk(KERN_ERR PFX
"Could not allocate state machine memory\n");
rv = -ENOMEM;
goto out_err;
}
new_smi->io_size = new_smi->handlers->init_data(new_smi->si_sm,
&new_smi->io);
rv = new_smi->io_setup(new_smi);
if (rv) {
printk(KERN_ERR PFX "Could not set up I/O space\n");
goto out_err;
}
if (new_smi->handlers->detect(new_smi->si_sm)) {
if (new_smi->addr_source)
printk(KERN_INFO PFX "Interface detection failed\n");
rv = -ENODEV;
goto out_err;
}
rv = try_get_dev_id(new_smi);
if (rv) {
if (new_smi->addr_source)
printk(KERN_INFO PFX "There appears to be no BMC"
" at this location\n");
goto out_err;
}
setup_oem_data_handler(new_smi);
setup_xaction_handlers(new_smi);
check_for_broken_irqs(new_smi);
new_smi->waiting_msg = NULL;
new_smi->curr_msg = NULL;
atomic_set(&new_smi->req_events, 0);
new_smi->run_to_completion = false;
for (i = 0; i < SI_NUM_STATS; i++)
atomic_set(&new_smi->stats[i], 0);
new_smi->interrupt_disabled = true;
atomic_set(&new_smi->need_watch, 0);
new_smi->intf_num = smi_num;
smi_num++;
rv = try_enable_event_buffer(new_smi);
if (rv == 0)
new_smi->has_event_buffer = true;
start_clear_flags(new_smi, false);
if (new_smi->irq) {
new_smi->interrupt_disabled = false;
atomic_set(&new_smi->req_events, 1);
}
if (!new_smi->dev) {
new_smi->pdev = platform_device_alloc("ipmi_si",
new_smi->intf_num);
if (!new_smi->pdev) {
printk(KERN_ERR PFX
"Unable to allocate platform device\n");
goto out_err;
}
new_smi->dev = &new_smi->pdev->dev;
new_smi->dev->driver = &ipmi_driver.driver;
rv = platform_device_add(new_smi->pdev);
if (rv) {
printk(KERN_ERR PFX
"Unable to register system interface device:"
" %d\n",
rv);
goto out_err;
}
new_smi->dev_registered = true;
}
rv = ipmi_register_smi(&handlers,
new_smi,
&new_smi->device_id,
new_smi->dev,
new_smi->slave_addr);
if (rv) {
dev_err(new_smi->dev, "Unable to register device: error %d\n",
rv);
goto out_err_stop_timer;
}
rv = ipmi_smi_add_proc_entry(new_smi->intf, "type",
&smi_type_proc_ops,
new_smi);
if (rv) {
dev_err(new_smi->dev, "Unable to create proc entry: %d\n", rv);
goto out_err_stop_timer;
}
rv = ipmi_smi_add_proc_entry(new_smi->intf, "si_stats",
&smi_si_stats_proc_ops,
new_smi);
if (rv) {
dev_err(new_smi->dev, "Unable to create proc entry: %d\n", rv);
goto out_err_stop_timer;
}
rv = ipmi_smi_add_proc_entry(new_smi->intf, "params",
&smi_params_proc_ops,
new_smi);
if (rv) {
dev_err(new_smi->dev, "Unable to create proc entry: %d\n", rv);
goto out_err_stop_timer;
}
dev_info(new_smi->dev, "IPMI %s interface initialized\n",
si_to_str[new_smi->si_type]);
return 0;
out_err_stop_timer:
wait_for_timer_and_thread(new_smi);
out_err:
new_smi->interrupt_disabled = true;
if (new_smi->intf) {
ipmi_smi_t intf = new_smi->intf;
new_smi->intf = NULL;
ipmi_unregister_smi(intf);
}
if (new_smi->irq_cleanup) {
new_smi->irq_cleanup(new_smi);
new_smi->irq_cleanup = NULL;
}
synchronize_sched();
if (new_smi->si_sm) {
if (new_smi->handlers)
new_smi->handlers->cleanup(new_smi->si_sm);
kfree(new_smi->si_sm);
new_smi->si_sm = NULL;
}
if (new_smi->addr_source_cleanup) {
new_smi->addr_source_cleanup(new_smi);
new_smi->addr_source_cleanup = NULL;
}
if (new_smi->io_cleanup) {
new_smi->io_cleanup(new_smi);
new_smi->io_cleanup = NULL;
}
if (new_smi->dev_registered) {
platform_device_unregister(new_smi->pdev);
new_smi->dev_registered = false;
}
return rv;
}
static int init_ipmi_si(void)
{
int i;
char *str;
int rv;
struct smi_info *e;
enum ipmi_addr_src type = SI_INVALID;
if (initialized)
return 0;
initialized = 1;
if (si_tryplatform) {
rv = platform_driver_register(&ipmi_driver);
if (rv) {
printk(KERN_ERR PFX "Unable to register "
"driver: %d\n", rv);
return rv;
}
}
str = si_type_str;
if (*str != '\0') {
for (i = 0; (i < SI_MAX_PARMS) && (*str != '\0'); i++) {
si_type[i] = str;
str = strchr(str, ',');
if (str) {
*str = '\0';
str++;
} else {
break;
}
}
}
printk(KERN_INFO "IPMI System Interface driver.\n");
if (!hardcode_find_bmc())
return 0;
#ifdef CONFIG_PCI
if (si_trypci) {
rv = pci_register_driver(&ipmi_pci_driver);
if (rv)
printk(KERN_ERR PFX "Unable to register "
"PCI driver: %d\n", rv);
else
pci_registered = true;
}
#endif
#ifdef CONFIG_DMI
if (si_trydmi)
dmi_find_bmc();
#endif
#ifdef CONFIG_ACPI
if (si_tryacpi)
spmi_find_bmc();
#endif
#ifdef CONFIG_PARISC
register_parisc_driver(&ipmi_parisc_driver);
parisc_registered = true;
si_trydefaults = 0;
#endif
mutex_lock(&smi_infos_lock);
list_for_each_entry(e, &smi_infos, link) {
if (e->irq && (!type || e->addr_source == type)) {
if (!try_smi_init(e)) {
type = e->addr_source;
}
}
}
if (type) {
mutex_unlock(&smi_infos_lock);
return 0;
}
list_for_each_entry(e, &smi_infos, link) {
if (!e->irq && (!type || e->addr_source == type)) {
if (!try_smi_init(e)) {
type = e->addr_source;
}
}
}
mutex_unlock(&smi_infos_lock);
if (type)
return 0;
if (si_trydefaults) {
mutex_lock(&smi_infos_lock);
if (list_empty(&smi_infos)) {
mutex_unlock(&smi_infos_lock);
default_find_bmc();
} else
mutex_unlock(&smi_infos_lock);
}
mutex_lock(&smi_infos_lock);
if (unload_when_empty && list_empty(&smi_infos)) {
mutex_unlock(&smi_infos_lock);
cleanup_ipmi_si();
printk(KERN_WARNING PFX
"Unable to find any System Interface(s)\n");
return -ENODEV;
} else {
mutex_unlock(&smi_infos_lock);
return 0;
}
}
static void cleanup_one_si(struct smi_info *to_clean)
{
int rv = 0;
if (!to_clean)
return;
if (to_clean->intf) {
ipmi_smi_t intf = to_clean->intf;
to_clean->intf = NULL;
rv = ipmi_unregister_smi(intf);
if (rv) {
pr_err(PFX "Unable to unregister device: errno=%d\n",
rv);
}
}
if (to_clean->dev)
dev_set_drvdata(to_clean->dev, NULL);
list_del(&to_clean->link);
if (to_clean->irq_cleanup)
to_clean->irq_cleanup(to_clean);
wait_for_timer_and_thread(to_clean);
while (to_clean->curr_msg || (to_clean->si_state != SI_NORMAL)) {
poll(to_clean);
schedule_timeout_uninterruptible(1);
}
disable_si_irq(to_clean, false);
while (to_clean->curr_msg || (to_clean->si_state != SI_NORMAL)) {
poll(to_clean);
schedule_timeout_uninterruptible(1);
}
if (to_clean->handlers)
to_clean->handlers->cleanup(to_clean->si_sm);
kfree(to_clean->si_sm);
if (to_clean->addr_source_cleanup)
to_clean->addr_source_cleanup(to_clean);
if (to_clean->io_cleanup)
to_clean->io_cleanup(to_clean);
if (to_clean->dev_registered)
platform_device_unregister(to_clean->pdev);
kfree(to_clean);
}
static void cleanup_ipmi_si(void)
{
struct smi_info *e, *tmp_e;
if (!initialized)
return;
#ifdef CONFIG_PCI
if (pci_registered)
pci_unregister_driver(&ipmi_pci_driver);
#endif
#ifdef CONFIG_PARISC
if (parisc_registered)
unregister_parisc_driver(&ipmi_parisc_driver);
#endif
platform_driver_unregister(&ipmi_driver);
mutex_lock(&smi_infos_lock);
list_for_each_entry_safe(e, tmp_e, &smi_infos, link)
cleanup_one_si(e);
mutex_unlock(&smi_infos_lock);
}
