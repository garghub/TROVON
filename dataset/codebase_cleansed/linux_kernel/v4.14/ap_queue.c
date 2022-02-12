struct ap_queue_status ap_queue_irq_ctrl(ap_qid_t qid,
struct ap_qirq_ctrl qirqctrl,
void *ind)
{
return ap_aqic(qid, qirqctrl, ind);
}
static int ap_queue_enable_interruption(struct ap_queue *aq, void *ind)
{
struct ap_queue_status status;
struct ap_qirq_ctrl qirqctrl = { 0 };
qirqctrl.ir = 1;
qirqctrl.isc = AP_ISC;
status = ap_aqic(aq->qid, qirqctrl, ind);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
case AP_RESPONSE_OTHERWISE_CHANGED:
return 0;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
case AP_RESPONSE_INVALID_ADDRESS:
pr_err("Registering adapter interrupts for AP device %02x.%04x failed\n",
AP_QID_CARD(aq->qid),
AP_QID_QUEUE(aq->qid));
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
if (special == 1)
qid |= 0x400000UL;
return ap_nqap(qid, psmid, msg, length);
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
int ap_recv(ap_qid_t qid, unsigned long long *psmid, void *msg, size_t length)
{
struct ap_queue_status status;
if (msg == NULL)
return -EINVAL;
status = ap_dqap(qid, psmid, msg, length);
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
static enum ap_wait ap_sm_nop(struct ap_queue *aq)
{
return AP_WAIT_NONE;
}
static struct ap_queue_status ap_sm_recv(struct ap_queue *aq)
{
struct ap_queue_status status;
struct ap_message *ap_msg;
status = ap_dqap(aq->qid, &aq->reply->psmid,
aq->reply->message, aq->reply->length);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
aq->queue_count--;
if (aq->queue_count > 0)
mod_timer(&aq->timeout,
jiffies + aq->request_timeout);
list_for_each_entry(ap_msg, &aq->pendingq, list) {
if (ap_msg->psmid != aq->reply->psmid)
continue;
list_del_init(&ap_msg->list);
aq->pendingq_count--;
ap_msg->receive(aq, ap_msg, aq->reply);
break;
}
case AP_RESPONSE_NO_PENDING_REPLY:
if (!status.queue_empty || aq->queue_count <= 0)
break;
aq->queue_count = 0;
list_splice_init(&aq->pendingq, &aq->requestq);
aq->requestq_count += aq->pendingq_count;
aq->pendingq_count = 0;
break;
default:
break;
}
return status;
}
static enum ap_wait ap_sm_read(struct ap_queue *aq)
{
struct ap_queue_status status;
if (!aq->reply)
return AP_WAIT_NONE;
status = ap_sm_recv(aq);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
if (aq->queue_count > 0) {
aq->state = AP_STATE_WORKING;
return AP_WAIT_AGAIN;
}
aq->state = AP_STATE_IDLE;
return AP_WAIT_NONE;
case AP_RESPONSE_NO_PENDING_REPLY:
if (aq->queue_count > 0)
return AP_WAIT_INTERRUPT;
aq->state = AP_STATE_IDLE;
return AP_WAIT_NONE;
default:
aq->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_suspend_read(struct ap_queue *aq)
{
struct ap_queue_status status;
if (!aq->reply)
return AP_WAIT_NONE;
status = ap_sm_recv(aq);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
if (aq->queue_count > 0)
return AP_WAIT_AGAIN;
default:
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_write(struct ap_queue *aq)
{
struct ap_queue_status status;
struct ap_message *ap_msg;
if (aq->requestq_count <= 0)
return AP_WAIT_NONE;
ap_msg = list_entry(aq->requestq.next, struct ap_message, list);
status = __ap_send(aq->qid, ap_msg->psmid,
ap_msg->message, ap_msg->length, ap_msg->special);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
aq->queue_count++;
if (aq->queue_count == 1)
mod_timer(&aq->timeout, jiffies + aq->request_timeout);
list_move_tail(&ap_msg->list, &aq->pendingq);
aq->requestq_count--;
aq->pendingq_count++;
if (aq->queue_count < aq->card->queue_depth) {
aq->state = AP_STATE_WORKING;
return AP_WAIT_AGAIN;
}
case AP_RESPONSE_Q_FULL:
aq->state = AP_STATE_QUEUE_FULL;
return AP_WAIT_INTERRUPT;
case AP_RESPONSE_RESET_IN_PROGRESS:
aq->state = AP_STATE_RESET_WAIT;
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_MESSAGE_TOO_BIG:
case AP_RESPONSE_REQ_FAC_NOT_INST:
list_del_init(&ap_msg->list);
aq->requestq_count--;
ap_msg->rc = -EINVAL;
ap_msg->receive(aq, ap_msg, NULL);
return AP_WAIT_AGAIN;
default:
aq->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_read_write(struct ap_queue *aq)
{
return min(ap_sm_read(aq), ap_sm_write(aq));
}
static enum ap_wait ap_sm_reset(struct ap_queue *aq)
{
struct ap_queue_status status;
status = ap_rapq(aq->qid);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
case AP_RESPONSE_RESET_IN_PROGRESS:
aq->state = AP_STATE_RESET_WAIT;
aq->interrupt = AP_INTR_DISABLED;
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_BUSY:
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
default:
aq->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_reset_wait(struct ap_queue *aq)
{
struct ap_queue_status status;
void *lsi_ptr;
if (aq->queue_count > 0 && aq->reply)
status = ap_sm_recv(aq);
else
status = ap_tapq(aq->qid, NULL);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
lsi_ptr = ap_airq_ptr();
if (lsi_ptr && ap_queue_enable_interruption(aq, lsi_ptr) == 0)
aq->state = AP_STATE_SETIRQ_WAIT;
else
aq->state = (aq->queue_count > 0) ?
AP_STATE_WORKING : AP_STATE_IDLE;
return AP_WAIT_AGAIN;
case AP_RESPONSE_BUSY:
case AP_RESPONSE_RESET_IN_PROGRESS:
return AP_WAIT_TIMEOUT;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
default:
aq->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
static enum ap_wait ap_sm_setirq_wait(struct ap_queue *aq)
{
struct ap_queue_status status;
if (aq->queue_count > 0 && aq->reply)
status = ap_sm_recv(aq);
else
status = ap_tapq(aq->qid, NULL);
if (status.irq_enabled == 1) {
aq->interrupt = AP_INTR_ENABLED;
aq->state = (aq->queue_count > 0) ?
AP_STATE_WORKING : AP_STATE_IDLE;
}
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
if (aq->queue_count > 0)
return AP_WAIT_AGAIN;
case AP_RESPONSE_NO_PENDING_REPLY:
return AP_WAIT_TIMEOUT;
default:
aq->state = AP_STATE_BORKED;
return AP_WAIT_NONE;
}
}
enum ap_wait ap_sm_event(struct ap_queue *aq, enum ap_event event)
{
return ap_jumptable[aq->state][event](aq);
}
enum ap_wait ap_sm_event_loop(struct ap_queue *aq, enum ap_event event)
{
enum ap_wait wait;
while ((wait = ap_sm_event(aq, event)) == AP_WAIT_AGAIN)
;
return wait;
}
void ap_queue_suspend(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
spin_lock_bh(&aq->lock);
aq->state = AP_STATE_SUSPEND_WAIT;
while (ap_sm_event(aq, AP_EVENT_POLL) != AP_WAIT_NONE)
;
aq->state = AP_STATE_BORKED;
spin_unlock_bh(&aq->lock);
}
void ap_queue_resume(struct ap_device *ap_dev)
{
}
static ssize_t ap_req_count_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ap_queue *aq = to_ap_queue(dev);
unsigned int req_cnt;
spin_lock_bh(&aq->lock);
req_cnt = aq->total_request_count;
spin_unlock_bh(&aq->lock);
return snprintf(buf, PAGE_SIZE, "%d\n", req_cnt);
}
static ssize_t ap_req_count_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ap_queue *aq = to_ap_queue(dev);
spin_lock_bh(&aq->lock);
aq->total_request_count = 0;
spin_unlock_bh(&aq->lock);
return count;
}
static ssize_t ap_requestq_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_queue *aq = to_ap_queue(dev);
unsigned int reqq_cnt = 0;
spin_lock_bh(&aq->lock);
reqq_cnt = aq->requestq_count;
spin_unlock_bh(&aq->lock);
return snprintf(buf, PAGE_SIZE, "%d\n", reqq_cnt);
}
static ssize_t ap_pendingq_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_queue *aq = to_ap_queue(dev);
unsigned int penq_cnt = 0;
spin_lock_bh(&aq->lock);
penq_cnt = aq->pendingq_count;
spin_unlock_bh(&aq->lock);
return snprintf(buf, PAGE_SIZE, "%d\n", penq_cnt);
}
static ssize_t ap_reset_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_queue *aq = to_ap_queue(dev);
int rc = 0;
spin_lock_bh(&aq->lock);
switch (aq->state) {
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
spin_unlock_bh(&aq->lock);
return rc;
}
static ssize_t ap_interrupt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_queue *aq = to_ap_queue(dev);
int rc = 0;
spin_lock_bh(&aq->lock);
if (aq->state == AP_STATE_SETIRQ_WAIT)
rc = snprintf(buf, PAGE_SIZE, "Enable Interrupt pending.\n");
else if (aq->interrupt == AP_INTR_ENABLED)
rc = snprintf(buf, PAGE_SIZE, "Interrupts enabled.\n");
else
rc = snprintf(buf, PAGE_SIZE, "Interrupts disabled.\n");
spin_unlock_bh(&aq->lock);
return rc;
}
static void ap_queue_device_release(struct device *dev)
{
struct ap_queue *aq = to_ap_queue(dev);
if (!list_empty(&aq->list)) {
spin_lock_bh(&ap_list_lock);
list_del_init(&aq->list);
spin_unlock_bh(&ap_list_lock);
}
kfree(aq);
}
struct ap_queue *ap_queue_create(ap_qid_t qid, int device_type)
{
struct ap_queue *aq;
aq = kzalloc(sizeof(*aq), GFP_KERNEL);
if (!aq)
return NULL;
aq->ap_dev.device.release = ap_queue_device_release;
aq->ap_dev.device.type = &ap_queue_type;
aq->ap_dev.device_type = device_type;
if (device_type == AP_DEVICE_TYPE_CEX6)
aq->ap_dev.device_type = AP_DEVICE_TYPE_CEX5;
aq->qid = qid;
aq->state = AP_STATE_RESET_START;
aq->interrupt = AP_INTR_DISABLED;
spin_lock_init(&aq->lock);
INIT_LIST_HEAD(&aq->pendingq);
INIT_LIST_HEAD(&aq->requestq);
setup_timer(&aq->timeout, ap_request_timeout, (unsigned long) aq);
return aq;
}
void ap_queue_init_reply(struct ap_queue *aq, struct ap_message *reply)
{
aq->reply = reply;
spin_lock_bh(&aq->lock);
ap_wait(ap_sm_event(aq, AP_EVENT_POLL));
spin_unlock_bh(&aq->lock);
}
void ap_queue_message(struct ap_queue *aq, struct ap_message *ap_msg)
{
BUG_ON(!ap_msg->receive);
spin_lock_bh(&aq->lock);
list_add_tail(&ap_msg->list, &aq->requestq);
aq->requestq_count++;
aq->total_request_count++;
atomic_inc(&aq->card->total_request_count);
ap_wait(ap_sm_event_loop(aq, AP_EVENT_POLL));
spin_unlock_bh(&aq->lock);
}
void ap_cancel_message(struct ap_queue *aq, struct ap_message *ap_msg)
{
struct ap_message *tmp;
spin_lock_bh(&aq->lock);
if (!list_empty(&ap_msg->list)) {
list_for_each_entry(tmp, &aq->pendingq, list)
if (tmp->psmid == ap_msg->psmid) {
aq->pendingq_count--;
goto found;
}
aq->requestq_count--;
found:
list_del_init(&ap_msg->list);
}
spin_unlock_bh(&aq->lock);
}
static void __ap_flush_queue(struct ap_queue *aq)
{
struct ap_message *ap_msg, *next;
list_for_each_entry_safe(ap_msg, next, &aq->pendingq, list) {
list_del_init(&ap_msg->list);
aq->pendingq_count--;
ap_msg->rc = -EAGAIN;
ap_msg->receive(aq, ap_msg, NULL);
}
list_for_each_entry_safe(ap_msg, next, &aq->requestq, list) {
list_del_init(&ap_msg->list);
aq->requestq_count--;
ap_msg->rc = -EAGAIN;
ap_msg->receive(aq, ap_msg, NULL);
}
}
void ap_flush_queue(struct ap_queue *aq)
{
spin_lock_bh(&aq->lock);
__ap_flush_queue(aq);
spin_unlock_bh(&aq->lock);
}
void ap_queue_remove(struct ap_queue *aq)
{
ap_flush_queue(aq);
del_timer_sync(&aq->timeout);
}
