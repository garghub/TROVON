static inline int ap_using_interrupts(void)
{
return ap_airq_flag;
}
static inline int ap_instructions_available(void)
{
register unsigned long reg0 asm ("0") = AP_MKQID(0,0);
register unsigned long reg1 asm ("1") = -ENODEV;
register unsigned long reg2 asm ("2") = 0UL;
asm volatile(
" .long 0xb2af0000\n"
"0: la %1,0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (reg0), "+d" (reg1), "+d" (reg2) : : "cc" );
return reg1;
}
static int ap_interrupts_available(void)
{
return test_facility(65);
}
static int ap_configuration_available(void)
{
return test_facility(12);
}
static inline struct ap_queue_status
ap_test_queue(ap_qid_t qid, unsigned long *info)
{
register unsigned long reg0 asm ("0") = qid;
register struct ap_queue_status reg1 asm ("1");
register unsigned long reg2 asm ("2") = 0UL;
if (test_facility(15))
reg0 |= 1UL << 23;
asm volatile(".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
if (info)
*info = reg2;
return reg1;
}
static inline struct ap_queue_status ap_reset_queue(ap_qid_t qid)
{
register unsigned long reg0 asm ("0") = qid | 0x01000000UL;
register struct ap_queue_status reg1 asm ("1");
register unsigned long reg2 asm ("2") = 0UL;
asm volatile(
".long 0xb2af0000"
: "+d" (reg0), "=d" (reg1), "+d" (reg2) : : "cc");
return reg1;
}
static inline struct ap_queue_status
ap_queue_interruption_control(ap_qid_t qid, void *ind)
{
register unsigned long reg0 asm ("0") = qid | 0x03000000UL;
register unsigned long reg1_in asm ("1") = 0x0000800000000000UL | AP_ISC;
register struct ap_queue_status reg1_out asm ("1");
register void *reg2 asm ("2") = ind;
asm volatile(
".long 0xb2af0000"
: "+d" (reg0), "+d" (reg1_in), "=d" (reg1_out), "+d" (reg2)
:
: "cc" );
return reg1_out;
}
static inline int ap_query_configuration(void)
{
register unsigned long reg0 asm ("0") = 0x04000000UL;
register unsigned long reg1 asm ("1") = -EINVAL;
register void *reg2 asm ("2") = (void *) ap_configuration;
if (!ap_configuration)
return -EOPNOTSUPP;
asm volatile(
".long 0xb2af0000\n"
"0: la %1,0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (reg0), "+d" (reg1), "+d" (reg2)
:
: "cc");
return reg1;
}
static void ap_init_configuration(void)
{
if (!ap_configuration_available())
return;
ap_configuration = kzalloc(sizeof(*ap_configuration), GFP_KERNEL);
if (!ap_configuration)
return;
if (ap_query_configuration() != 0) {
kfree(ap_configuration);
ap_configuration = NULL;
return;
}
}
static inline int ap_test_config(unsigned int *field, unsigned int nr)
{
return ap_test_bit((field + (nr >> 5)), (nr & 0x1f));
}
static inline int ap_test_config_card_id(unsigned int id)
{
if (!ap_configuration)
return 1;
return ap_test_config(ap_configuration->apm, id);
}
static inline int ap_test_config_domain(unsigned int domain)
{
if (!ap_configuration)
return domain < 16;
return ap_test_config(ap_configuration->aqm, domain);
}
static int ap_queue_enable_interruption(struct ap_device *ap_dev, void *ind)
{
struct ap_queue_status status;
status = ap_queue_interruption_control(ap_dev->qid, ind);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
case AP_RESPONSE_OTHERWISE_CHANGED:
return 0;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
case AP_RESPONSE_INVALID_ADDRESS:
pr_err("Registering adapter interrupts for AP %d failed\n",
AP_QID_DEVICE(ap_dev->qid));
return -EOPNOTSUPP;
case AP_RESPONSE_RESET_IN_PROGRESS:
case AP_RESPONSE_BUSY:
default:
return -EBUSY;
}
}
static inline struct ap_queue_status
__ap_send(ap_qid_t qid, unsigned long long psmid, void *msg, size_t length,
unsigned int special)
{
typedef struct { char _[length]; } msgblock;
register unsigned long reg0 asm ("0") = qid | 0x40000000UL;
register struct ap_queue_status reg1 asm ("1");
register unsigned long reg2 asm ("2") = (unsigned long) msg;
register unsigned long reg3 asm ("3") = (unsigned long) length;
register unsigned long reg4 asm ("4") = (unsigned int) (psmid >> 32);
register unsigned long reg5 asm ("5") = psmid & 0xffffffff;
if (special == 1)
reg0 |= 0x400000UL;
asm volatile (
"0: .long 0xb2ad0042\n"
" brc 2,0b"
: "+d" (reg0), "=d" (reg1), "+d" (reg2), "+d" (reg3)
: "d" (reg4), "d" (reg5), "m" (*(msgblock *) msg)
: "cc" );
return reg1;
}
int ap_send(ap_qid_t qid, unsigned long long psmid, void *msg, size_t length)
{
struct ap_queue_status status;
status = __ap_send(qid, psmid, msg, length, 0);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
return 0;
case AP_RESPONSE_Q_FULL:
case AP_RESPONSE_RESET_IN_PROGRESS:
return -EBUSY;
case AP_RESPONSE_REQ_FAC_NOT_INST:
return -EINVAL;
default:
return -ENODEV;
}
}
static inline struct ap_queue_status
__ap_recv(ap_qid_t qid, unsigned long long *psmid, void *msg, size_t length)
{
typedef struct { char _[length]; } msgblock;
register unsigned long reg0 asm("0") = qid | 0x80000000UL;
register struct ap_queue_status reg1 asm ("1");
register unsigned long reg2 asm("2") = 0UL;
register unsigned long reg4 asm("4") = (unsigned long) msg;
register unsigned long reg5 asm("5") = (unsigned long) length;
register unsigned long reg6 asm("6") = 0UL;
register unsigned long reg7 asm("7") = 0UL;
asm volatile(
"0: .long 0xb2ae0064\n"
" brc 6,0b\n"
: "+d" (reg0), "=d" (reg1), "+d" (reg2),
"+d" (reg4), "+d" (reg5), "+d" (reg6), "+d" (reg7),
"=m" (*(msgblock *) msg) : : "cc" );
*psmid = (((unsigned long long) reg6) << 32) + reg7;
return reg1;
}
int ap_recv(ap_qid_t qid, unsigned long long *psmid, void *msg, size_t length)
{
struct ap_queue_status status;
status = __ap_recv(qid, psmid, msg, length);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
return 0;
case AP_RESPONSE_NO_PENDING_REPLY:
if (status.queue_empty)
return -ENOENT;
return -EBUSY;
case AP_RESPONSE_RESET_IN_PROGRESS:
return -EBUSY;
default:
return -ENODEV;
}
}
static int ap_query_queue(ap_qid_t qid, int *queue_depth, int *device_type,
unsigned int *facilities)
{
struct ap_queue_status status;
unsigned long info;
int nd;
if (!ap_test_config_card_id(AP_QID_DEVICE(qid)))
return -ENODEV;
status = ap_test_queue(qid, &info);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
*queue_depth = (int)(info & 0xff);
*device_type = (int)((info >> 24) & 0xff);
*facilities = (unsigned int)(info >> 32);
nd = (info >> 16) & 0xff;
if ((info & (1UL << 57)) && nd > 0)
ap_max_domain_id = nd;
return 0;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
case AP_RESPONSE_INVALID_ADDRESS:
return -ENODEV;
case AP_RESPONSE_RESET_IN_PROGRESS:
case AP_RESPONSE_OTHERWISE_CHANGED:
case AP_RESPONSE_BUSY:
return -EBUSY;
default:
BUG();
}
}
static void ap_sm_wait(enum ap_wait wait)
{
ktime_t hr_time;
switch (wait) {
case AP_WAIT_AGAIN:
case AP_WAIT_INTERRUPT:
if (ap_using_interrupts())
break;
if (ap_poll_kthread) {
wake_up(&ap_poll_wait);
break;
}
case AP_WAIT_TIMEOUT:
spin_lock_bh(&ap_poll_timer_lock);
if (!hrtimer_is_queued(&ap_poll_timer)) {
hr_time = ktime_set(0, poll_timeout);
hrtimer_forward_now(&ap_poll_timer, hr_time);
hrtimer_restart(&ap_poll_timer);
}
spin_unlock_bh(&ap_poll_timer_lock);
break;
case AP_WAIT_NONE:
default:
break;
}
}
static enum ap_wait ap_sm_nop(struct ap_device *ap_dev)
{
return AP_WAIT_NONE;
}
static struct ap_queue_status ap_sm_recv(struct ap_device *ap_dev)
{
struct ap_queue_status status;
struct ap_message *ap_msg;
status = __ap_recv(ap_dev->qid, &ap_dev->reply->psmid,
ap_dev->reply->message, ap_dev->reply->length);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
atomic_dec(&ap_poll_requests);
ap_dev->queue_count--;
if (ap_dev->queue_count > 0)
mod_timer(&ap_dev->timeout,
jiffies + ap_dev->drv->request_timeout);
list_for_each_entry(ap_msg, &ap_dev->pendingq, list) {
if (ap_msg->psmid != ap_dev->reply->psmid)
continue;
list_del_init(&ap_msg->list);
ap_dev->pendingq_count--;
ap_msg->receive(ap_dev, ap_msg, ap_dev->reply);
break;
}
case AP_RESPONSE_NO_PENDING_REPLY:
if (!status.queue_empty || ap_dev->queue_count <= 0)
break;
atomic_sub(ap_dev->queue_count, &ap_poll_requests);
ap_dev->queue_count = 0;
list_splice_init(&ap_dev->pendingq, &ap_dev->requestq);
ap_dev->requestq_count += ap_dev->pendingq_count;
ap_dev->pendingq_count = 0;
break;
default:
break;
}
return status;
}
static enum ap_wait ap_sm_read(struct ap_device *ap_dev)
{
struct ap_queue_status status;
status = ap_sm_recv(ap_dev);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
if (ap_dev->queue_count > 0) {
ap_dev->state = AP_STATE_WORKING;
return AP_WAIT_AGAIN;
}
ap_dev->state = AP_STATE_IDLE;
return AP_WAIT_NONE;
case AP_RESPONSE_NO_PENDING_REPLY:
if (ap_dev->queue_count > 0)
return AP_WAIT_INTERRUPT;
ap_dev->state = AP_STATE_IDLE;
return AP_WAIT_NONE;
default:
ap_dev->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_write(struct ap_device *ap_dev)
{
struct ap_queue_status status;
struct ap_message *ap_msg;
if (ap_dev->requestq_count <= 0)
return AP_WAIT_NONE;
ap_msg = list_entry(ap_dev->requestq.next, struct ap_message, list);
status = __ap_send(ap_dev->qid, ap_msg->psmid,
ap_msg->message, ap_msg->length, ap_msg->special);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
atomic_inc(&ap_poll_requests);
ap_dev->queue_count++;
if (ap_dev->queue_count == 1)
mod_timer(&ap_dev->timeout,
jiffies + ap_dev->drv->request_timeout);
list_move_tail(&ap_msg->list, &ap_dev->pendingq);
ap_dev->requestq_count--;
ap_dev->pendingq_count++;
if (ap_dev->queue_count < ap_dev->queue_depth) {
ap_dev->state = AP_STATE_WORKING;
return AP_WAIT_AGAIN;
}
case AP_RESPONSE_Q_FULL:
ap_dev->state = AP_STATE_QUEUE_FULL;
return AP_WAIT_INTERRUPT;
case AP_RESPONSE_RESET_IN_PROGRESS:
ap_dev->state = AP_STATE_RESET_WAIT;
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_MESSAGE_TOO_BIG:
case AP_RESPONSE_REQ_FAC_NOT_INST:
list_del_init(&ap_msg->list);
ap_dev->requestq_count--;
ap_msg->rc = -EINVAL;
ap_msg->receive(ap_dev, ap_msg, NULL);
return AP_WAIT_AGAIN;
default:
ap_dev->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_read_write(struct ap_device *ap_dev)
{
return min(ap_sm_read(ap_dev), ap_sm_write(ap_dev));
}
static enum ap_wait ap_sm_reset(struct ap_device *ap_dev)
{
struct ap_queue_status status;
status = ap_reset_queue(ap_dev->qid);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
case AP_RESPONSE_RESET_IN_PROGRESS:
ap_dev->state = AP_STATE_RESET_WAIT;
ap_dev->interrupt = AP_INTR_DISABLED;
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_BUSY:
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
default:
ap_dev->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_reset_wait(struct ap_device *ap_dev)
{
struct ap_queue_status status;
unsigned long info;
if (ap_dev->queue_count > 0)
status = ap_sm_recv(ap_dev);
else
status = ap_test_queue(ap_dev->qid, &info);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
if (ap_using_interrupts() &&
ap_queue_enable_interruption(ap_dev,
ap_airq.lsi_ptr) == 0)
ap_dev->state = AP_STATE_SETIRQ_WAIT;
else
ap_dev->state = (ap_dev->queue_count > 0) ?
AP_STATE_WORKING : AP_STATE_IDLE;
return AP_WAIT_AGAIN;
case AP_RESPONSE_BUSY:
case AP_RESPONSE_RESET_IN_PROGRESS:
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
default:
ap_dev->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_setirq_wait(struct ap_device *ap_dev)
{
struct ap_queue_status status;
unsigned long info;
if (ap_dev->queue_count > 0)
status = ap_sm_recv(ap_dev);
else
status = ap_test_queue(ap_dev->qid, &info);
if (status.int_enabled == 1) {
ap_dev->interrupt = AP_INTR_ENABLED;
ap_dev->state = (ap_dev->queue_count > 0) ?
AP_STATE_WORKING : AP_STATE_IDLE;
}
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
if (ap_dev->queue_count > 0)
return AP_WAIT_AGAIN;
case AP_RESPONSE_NO_PENDING_REPLY:
return AP_WAIT_TIMEOUT;
default:
ap_dev->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static inline enum ap_wait ap_sm_event(struct ap_device *ap_dev,
enum ap_event event)
{
return ap_jumptable[ap_dev->state][event](ap_dev);
}
static inline enum ap_wait ap_sm_event_loop(struct ap_device *ap_dev,
enum ap_event event)
{
enum ap_wait wait;
while ((wait = ap_sm_event(ap_dev, event)) == AP_WAIT_AGAIN)
;
return wait;
}
static void ap_request_timeout(unsigned long data)
{
struct ap_device *ap_dev = (struct ap_device *) data;
if (ap_suspend_flag)
return;
spin_lock_bh(&ap_dev->lock);
ap_sm_wait(ap_sm_event(ap_dev, AP_EVENT_TIMEOUT));
spin_unlock_bh(&ap_dev->lock);
}
static enum hrtimer_restart ap_poll_timeout(struct hrtimer *unused)
{
if (!ap_suspend_flag)
tasklet_schedule(&ap_tasklet);
return HRTIMER_NORESTART;
}
static void ap_interrupt_handler(struct airq_struct *airq)
{
inc_irq_stat(IRQIO_APB);
if (!ap_suspend_flag)
tasklet_schedule(&ap_tasklet);
}
static void ap_tasklet_fn(unsigned long dummy)
{
struct ap_device *ap_dev;
enum ap_wait wait = AP_WAIT_NONE;
if (ap_using_interrupts())
xchg(ap_airq.lsi_ptr, 0);
spin_lock(&ap_device_list_lock);
list_for_each_entry(ap_dev, &ap_device_list, list) {
spin_lock_bh(&ap_dev->lock);
wait = min(wait, ap_sm_event_loop(ap_dev, AP_EVENT_POLL));
spin_unlock_bh(&ap_dev->lock);
}
spin_unlock(&ap_device_list_lock);
ap_sm_wait(wait);
}
static int ap_poll_thread(void *data)
{
DECLARE_WAITQUEUE(wait, current);
set_user_nice(current, MAX_NICE);
set_freezable();
while (!kthread_should_stop()) {
add_wait_queue(&ap_poll_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
if (ap_suspend_flag ||
atomic_read(&ap_poll_requests) <= 0) {
schedule();
try_to_freeze();
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&ap_poll_wait, &wait);
if (need_resched()) {
schedule();
try_to_freeze();
continue;
}
ap_tasklet_fn(0);
} while (!kthread_should_stop());
return 0;
}
static int ap_poll_thread_start(void)
{
int rc;
if (ap_using_interrupts() || ap_poll_kthread)
return 0;
mutex_lock(&ap_poll_thread_mutex);
ap_poll_kthread = kthread_run(ap_poll_thread, NULL, "appoll");
rc = PTR_RET(ap_poll_kthread);
if (rc)
ap_poll_kthread = NULL;
mutex_unlock(&ap_poll_thread_mutex);
return rc;
}
static void ap_poll_thread_stop(void)
{
if (!ap_poll_kthread)
return;
mutex_lock(&ap_poll_thread_mutex);
kthread_stop(ap_poll_kthread);
ap_poll_kthread = NULL;
mutex_unlock(&ap_poll_thread_mutex);
}
void ap_queue_message(struct ap_device *ap_dev, struct ap_message *ap_msg)
{
BUG_ON(!ap_msg->receive);
spin_lock_bh(&ap_dev->lock);
list_add_tail(&ap_msg->list, &ap_dev->requestq);
ap_dev->requestq_count++;
ap_dev->total_request_count++;
ap_sm_wait(ap_sm_event_loop(ap_dev, AP_EVENT_POLL));
spin_unlock_bh(&ap_dev->lock);
}
void ap_cancel_message(struct ap_device *ap_dev, struct ap_message *ap_msg)
{
struct ap_message *tmp;
spin_lock_bh(&ap_dev->lock);
if (!list_empty(&ap_msg->list)) {
list_for_each_entry(tmp, &ap_dev->pendingq, list)
if (tmp->psmid == ap_msg->psmid) {
ap_dev->pendingq_count--;
goto found;
}
ap_dev->requestq_count--;
found:
list_del_init(&ap_msg->list);
}
spin_unlock_bh(&ap_dev->lock);
}
static ssize_t ap_hwtype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ap_dev->device_type);
}
static ssize_t ap_raw_hwtype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ap_dev->raw_hwtype);
}
static ssize_t ap_depth_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ap_dev->queue_depth);
}
static ssize_t ap_request_count_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int rc;
spin_lock_bh(&ap_dev->lock);
rc = snprintf(buf, PAGE_SIZE, "%d\n", ap_dev->total_request_count);
spin_unlock_bh(&ap_dev->lock);
return rc;
}
static ssize_t ap_requestq_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int rc;
spin_lock_bh(&ap_dev->lock);
rc = snprintf(buf, PAGE_SIZE, "%d\n", ap_dev->requestq_count);
spin_unlock_bh(&ap_dev->lock);
return rc;
}
static ssize_t ap_pendingq_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int rc;
spin_lock_bh(&ap_dev->lock);
rc = snprintf(buf, PAGE_SIZE, "%d\n", ap_dev->pendingq_count);
spin_unlock_bh(&ap_dev->lock);
return rc;
}
static ssize_t ap_reset_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int rc = 0;
spin_lock_bh(&ap_dev->lock);
switch (ap_dev->state) {
case AP_STATE_RESET_START:
case AP_STATE_RESET_WAIT:
rc = snprintf(buf, PAGE_SIZE, "Reset in progress.\n");
break;
case AP_STATE_WORKING:
case AP_STATE_QUEUE_FULL:
rc = snprintf(buf, PAGE_SIZE, "Reset Timer armed.\n");
break;
default:
rc = snprintf(buf, PAGE_SIZE, "No Reset Timer set.\n");
}
spin_unlock_bh(&ap_dev->lock);
return rc;
}
static ssize_t ap_interrupt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int rc = 0;
spin_lock_bh(&ap_dev->lock);
if (ap_dev->state == AP_STATE_SETIRQ_WAIT)
rc = snprintf(buf, PAGE_SIZE, "Enable Interrupt pending.\n");
else if (ap_dev->interrupt == AP_INTR_ENABLED)
rc = snprintf(buf, PAGE_SIZE, "Interrupts enabled.\n");
else
rc = snprintf(buf, PAGE_SIZE, "Interrupts disabled.\n");
spin_unlock_bh(&ap_dev->lock);
return rc;
}
static ssize_t ap_modalias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "ap:t%02X\n", to_ap_dev(dev)->device_type);
}
static ssize_t ap_functions_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_device *ap_dev = to_ap_dev(dev);
return snprintf(buf, PAGE_SIZE, "0x%08X\n", ap_dev->functions);
}
static int ap_bus_match(struct device *dev, struct device_driver *drv)
{
struct ap_device *ap_dev = to_ap_dev(dev);
struct ap_driver *ap_drv = to_ap_drv(drv);
struct ap_device_id *id;
for (id = ap_drv->ids; id->match_flags; id++) {
if ((id->match_flags & AP_DEVICE_ID_MATCH_DEVICE_TYPE) &&
(id->dev_type != ap_dev->device_type))
continue;
return 1;
}
return 0;
}
static int ap_uevent (struct device *dev, struct kobj_uevent_env *env)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int retval = 0;
if (!ap_dev)
return -ENODEV;
retval = add_uevent_var(env, "DEV_TYPE=%04X", ap_dev->device_type);
if (retval)
return retval;
retval = add_uevent_var(env, "MODALIAS=ap:t%02X", ap_dev->device_type);
return retval;
}
static int ap_dev_suspend(struct device *dev, pm_message_t state)
{
struct ap_device *ap_dev = to_ap_dev(dev);
spin_lock_bh(&ap_dev->lock);
ap_dev->state = AP_STATE_SUSPEND_WAIT;
while (ap_sm_event(ap_dev, AP_EVENT_POLL) != AP_WAIT_NONE)
;
ap_dev->state = AP_STATE_BORKED;
spin_unlock_bh(&ap_dev->lock);
return 0;
}
static int ap_dev_resume(struct device *dev)
{
return 0;
}
static void ap_bus_suspend(void)
{
ap_suspend_flag = 1;
flush_work(&ap_scan_work);
tasklet_disable(&ap_tasklet);
}
static int __ap_devices_unregister(struct device *dev, void *dummy)
{
device_unregister(dev);
return 0;
}
static void ap_bus_resume(void)
{
int rc;
bus_for_each_dev(&ap_bus_type, NULL, NULL, __ap_devices_unregister);
if (ap_interrupts_available() && !ap_using_interrupts()) {
rc = register_adapter_interrupt(&ap_airq);
ap_airq_flag = (rc == 0);
}
if (!ap_interrupts_available() && ap_using_interrupts()) {
unregister_adapter_interrupt(&ap_airq);
ap_airq_flag = 0;
}
if (!user_set_domain)
ap_domain_index = -1;
ap_suspend_flag = 0;
if (ap_airq_flag)
xchg(ap_airq.lsi_ptr, 0);
tasklet_enable(&ap_tasklet);
queue_work(system_long_wq, &ap_scan_work);
}
static int ap_power_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
switch (event) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
ap_bus_suspend();
break;
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
ap_bus_resume();
break;
default:
break;
}
return NOTIFY_DONE;
}
static int ap_device_probe(struct device *dev)
{
struct ap_device *ap_dev = to_ap_dev(dev);
struct ap_driver *ap_drv = to_ap_drv(dev->driver);
int rc;
ap_dev->drv = ap_drv;
rc = ap_drv->probe ? ap_drv->probe(ap_dev) : -ENODEV;
if (rc)
ap_dev->drv = NULL;
return rc;
}
static void __ap_flush_queue(struct ap_device *ap_dev)
{
struct ap_message *ap_msg, *next;
list_for_each_entry_safe(ap_msg, next, &ap_dev->pendingq, list) {
list_del_init(&ap_msg->list);
ap_dev->pendingq_count--;
ap_msg->rc = -EAGAIN;
ap_msg->receive(ap_dev, ap_msg, NULL);
}
list_for_each_entry_safe(ap_msg, next, &ap_dev->requestq, list) {
list_del_init(&ap_msg->list);
ap_dev->requestq_count--;
ap_msg->rc = -EAGAIN;
ap_msg->receive(ap_dev, ap_msg, NULL);
}
}
void ap_flush_queue(struct ap_device *ap_dev)
{
spin_lock_bh(&ap_dev->lock);
__ap_flush_queue(ap_dev);
spin_unlock_bh(&ap_dev->lock);
}
static int ap_device_remove(struct device *dev)
{
struct ap_device *ap_dev = to_ap_dev(dev);
struct ap_driver *ap_drv = ap_dev->drv;
ap_flush_queue(ap_dev);
del_timer_sync(&ap_dev->timeout);
spin_lock_bh(&ap_device_list_lock);
list_del_init(&ap_dev->list);
spin_unlock_bh(&ap_device_list_lock);
if (ap_drv->remove)
ap_drv->remove(ap_dev);
spin_lock_bh(&ap_dev->lock);
atomic_sub(ap_dev->queue_count, &ap_poll_requests);
spin_unlock_bh(&ap_dev->lock);
return 0;
}
static void ap_device_release(struct device *dev)
{
kfree(to_ap_dev(dev));
}
int ap_driver_register(struct ap_driver *ap_drv, struct module *owner,
char *name)
{
struct device_driver *drv = &ap_drv->driver;
if (!initialised)
return -ENODEV;
drv->bus = &ap_bus_type;
drv->probe = ap_device_probe;
drv->remove = ap_device_remove;
drv->owner = owner;
drv->name = name;
return driver_register(drv);
}
void ap_driver_unregister(struct ap_driver *ap_drv)
{
driver_unregister(&ap_drv->driver);
}
void ap_bus_force_rescan(void)
{
if (ap_suspend_flag)
return;
del_timer(&ap_config_timer);
queue_work(system_long_wq, &ap_scan_work);
flush_work(&ap_scan_work);
}
static ssize_t ap_domain_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ap_domain_index);
}
static ssize_t ap_control_domain_mask_show(struct bus_type *bus, char *buf)
{
if (!ap_configuration)
return snprintf(buf, PAGE_SIZE, "not supported\n");
if (!test_facility(76))
return snprintf(buf, PAGE_SIZE, "%08x%08x\n",
ap_configuration->adm[0],
ap_configuration->adm[1]);
return snprintf(buf, PAGE_SIZE,
"0x%08x%08x%08x%08x%08x%08x%08x%08x\n",
ap_configuration->adm[0], ap_configuration->adm[1],
ap_configuration->adm[2], ap_configuration->adm[3],
ap_configuration->adm[4], ap_configuration->adm[5],
ap_configuration->adm[6], ap_configuration->adm[7]);
}
static ssize_t ap_config_time_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ap_config_time);
}
static ssize_t ap_interrupts_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n",
ap_using_interrupts() ? 1 : 0);
}
static ssize_t ap_config_time_store(struct bus_type *bus,
const char *buf, size_t count)
{
int time;
if (sscanf(buf, "%d\n", &time) != 1 || time < 5 || time > 120)
return -EINVAL;
ap_config_time = time;
mod_timer(&ap_config_timer, jiffies + ap_config_time * HZ);
return count;
}
static ssize_t ap_poll_thread_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ap_poll_kthread ? 1 : 0);
}
static ssize_t ap_poll_thread_store(struct bus_type *bus,
const char *buf, size_t count)
{
int flag, rc;
if (sscanf(buf, "%d\n", &flag) != 1)
return -EINVAL;
if (flag) {
rc = ap_poll_thread_start();
if (rc)
count = rc;
} else
ap_poll_thread_stop();
return count;
}
static ssize_t poll_timeout_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%llu\n", poll_timeout);
}
static ssize_t poll_timeout_store(struct bus_type *bus, const char *buf,
size_t count)
{
unsigned long long time;
ktime_t hr_time;
if (sscanf(buf, "%llu\n", &time) != 1 || time < 1 ||
time > 120000000000ULL)
return -EINVAL;
poll_timeout = time;
hr_time = ktime_set(0, poll_timeout);
spin_lock_bh(&ap_poll_timer_lock);
hrtimer_cancel(&ap_poll_timer);
hrtimer_set_expires(&ap_poll_timer, hr_time);
hrtimer_start_expires(&ap_poll_timer, HRTIMER_MODE_ABS);
spin_unlock_bh(&ap_poll_timer_lock);
return count;
}
static ssize_t ap_max_domain_id_show(struct bus_type *bus, char *buf)
{
int max_domain_id;
if (ap_configuration)
max_domain_id = ap_max_domain_id ? : -1;
else
max_domain_id = 15;
return snprintf(buf, PAGE_SIZE, "%d\n", max_domain_id);
}
static int ap_select_domain(void)
{
int count, max_count, best_domain;
struct ap_queue_status status;
int i, j;
if (ap_domain_index >= 0)
return 0;
best_domain = -1;
max_count = 0;
for (i = 0; i < AP_DOMAINS; i++) {
if (!ap_test_config_domain(i))
continue;
count = 0;
for (j = 0; j < AP_DEVICES; j++) {
if (!ap_test_config_card_id(j))
continue;
status = ap_test_queue(AP_MKQID(j, i), NULL);
if (status.response_code != AP_RESPONSE_NORMAL)
continue;
count++;
}
if (count > max_count) {
max_count = count;
best_domain = i;
}
}
if (best_domain >= 0){
ap_domain_index = best_domain;
return 0;
}
return -ENODEV;
}
static int __ap_scan_bus(struct device *dev, void *data)
{
return to_ap_dev(dev)->qid == (ap_qid_t)(unsigned long) data;
}
static void ap_scan_bus(struct work_struct *unused)
{
struct ap_device *ap_dev;
struct device *dev;
ap_qid_t qid;
int queue_depth = 0, device_type = 0;
unsigned int device_functions = 0;
int rc, i, borked;
ap_query_configuration();
if (ap_select_domain() != 0)
goto out;
for (i = 0; i < AP_DEVICES; i++) {
qid = AP_MKQID(i, ap_domain_index);
dev = bus_find_device(&ap_bus_type, NULL,
(void *)(unsigned long)qid,
__ap_scan_bus);
rc = ap_query_queue(qid, &queue_depth, &device_type,
&device_functions);
if (dev) {
ap_dev = to_ap_dev(dev);
spin_lock_bh(&ap_dev->lock);
if (rc == -ENODEV)
ap_dev->state = AP_STATE_BORKED;
borked = ap_dev->state == AP_STATE_BORKED;
spin_unlock_bh(&ap_dev->lock);
if (borked)
device_unregister(dev);
put_device(dev);
if (!borked)
continue;
}
if (rc)
continue;
ap_dev = kzalloc(sizeof(*ap_dev), GFP_KERNEL);
if (!ap_dev)
break;
ap_dev->qid = qid;
ap_dev->state = AP_STATE_RESET_START;
ap_dev->interrupt = AP_INTR_DISABLED;
ap_dev->queue_depth = queue_depth;
ap_dev->raw_hwtype = device_type;
ap_dev->device_type = device_type;
ap_dev->functions = device_functions;
spin_lock_init(&ap_dev->lock);
INIT_LIST_HEAD(&ap_dev->pendingq);
INIT_LIST_HEAD(&ap_dev->requestq);
INIT_LIST_HEAD(&ap_dev->list);
setup_timer(&ap_dev->timeout, ap_request_timeout,
(unsigned long) ap_dev);
ap_dev->device.bus = &ap_bus_type;
ap_dev->device.parent = ap_root_device;
rc = dev_set_name(&ap_dev->device, "card%02x",
AP_QID_DEVICE(ap_dev->qid));
if (rc) {
kfree(ap_dev);
continue;
}
spin_lock_bh(&ap_device_list_lock);
list_add(&ap_dev->list, &ap_device_list);
spin_unlock_bh(&ap_device_list_lock);
spin_lock_bh(&ap_dev->lock);
ap_sm_wait(ap_sm_event(ap_dev, AP_EVENT_POLL));
spin_unlock_bh(&ap_dev->lock);
ap_dev->device.release = ap_device_release;
rc = device_register(&ap_dev->device);
if (rc) {
spin_lock_bh(&ap_dev->lock);
list_del_init(&ap_dev->list);
spin_unlock_bh(&ap_dev->lock);
put_device(&ap_dev->device);
continue;
}
rc = sysfs_create_group(&ap_dev->device.kobj,
&ap_dev_attr_group);
if (rc) {
device_unregister(&ap_dev->device);
continue;
}
}
out:
mod_timer(&ap_config_timer, jiffies + ap_config_time * HZ);
}
static void ap_config_timeout(unsigned long ptr)
{
if (ap_suspend_flag)
return;
queue_work(system_long_wq, &ap_scan_work);
}
static void ap_reset_domain(void)
{
int i;
if (ap_domain_index == -1 || !ap_test_config_domain(ap_domain_index))
return;
for (i = 0; i < AP_DEVICES; i++)
ap_reset_queue(AP_MKQID(i, ap_domain_index));
}
static void ap_reset_all(void)
{
int i, j;
for (i = 0; i < AP_DOMAINS; i++) {
if (!ap_test_config_domain(i))
continue;
for (j = 0; j < AP_DEVICES; j++) {
if (!ap_test_config_card_id(j))
continue;
ap_reset_queue(AP_MKQID(j, i));
}
}
}
int __init ap_module_init(void)
{
int max_domain_id;
int rc, i;
if (ap_instructions_available() != 0) {
pr_warn("The hardware system does not support AP instructions\n");
return -ENODEV;
}
ap_init_configuration();
if (ap_configuration)
max_domain_id = ap_max_domain_id ? : (AP_DOMAINS - 1);
else
max_domain_id = 15;
if (ap_domain_index < -1 || ap_domain_index > max_domain_id) {
pr_warn("%d is not a valid cryptographic domain\n",
ap_domain_index);
return -EINVAL;
}
if (ap_domain_index >= 0)
user_set_domain = 1;
if (ap_interrupts_available()) {
rc = register_adapter_interrupt(&ap_airq);
ap_airq_flag = (rc == 0);
}
register_reset_call(&ap_reset_call);
rc = bus_register(&ap_bus_type);
if (rc)
goto out;
for (i = 0; ap_bus_attrs[i]; i++) {
rc = bus_create_file(&ap_bus_type, ap_bus_attrs[i]);
if (rc)
goto out_bus;
}
ap_root_device = root_device_register("ap");
rc = PTR_RET(ap_root_device);
if (rc)
goto out_bus;
setup_timer(&ap_config_timer, ap_config_timeout, 0);
if (MACHINE_IS_VM)
poll_timeout = 1500000;
spin_lock_init(&ap_poll_timer_lock);
hrtimer_init(&ap_poll_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
ap_poll_timer.function = ap_poll_timeout;
if (ap_thread_flag) {
rc = ap_poll_thread_start();
if (rc)
goto out_work;
}
rc = register_pm_notifier(&ap_power_notifier);
if (rc)
goto out_pm;
queue_work(system_long_wq, &ap_scan_work);
initialised = true;
return 0;
out_pm:
ap_poll_thread_stop();
out_work:
hrtimer_cancel(&ap_poll_timer);
root_device_unregister(ap_root_device);
out_bus:
while (i--)
bus_remove_file(&ap_bus_type, ap_bus_attrs[i]);
bus_unregister(&ap_bus_type);
out:
unregister_reset_call(&ap_reset_call);
if (ap_using_interrupts())
unregister_adapter_interrupt(&ap_airq);
kfree(ap_configuration);
return rc;
}
void ap_module_exit(void)
{
int i;
initialised = false;
ap_reset_domain();
ap_poll_thread_stop();
del_timer_sync(&ap_config_timer);
hrtimer_cancel(&ap_poll_timer);
tasklet_kill(&ap_tasklet);
bus_for_each_dev(&ap_bus_type, NULL, NULL, __ap_devices_unregister);
for (i = 0; ap_bus_attrs[i]; i++)
bus_remove_file(&ap_bus_type, ap_bus_attrs[i]);
unregister_pm_notifier(&ap_power_notifier);
root_device_unregister(ap_root_device);
bus_unregister(&ap_bus_type);
kfree(ap_configuration);
unregister_reset_call(&ap_reset_call);
if (ap_using_interrupts())
unregister_adapter_interrupt(&ap_airq);
}
