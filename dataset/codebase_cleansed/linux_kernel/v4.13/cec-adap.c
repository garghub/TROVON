static int cec_log_addr2idx(const struct cec_adapter *adap, u8 log_addr)
{
int i;
for (i = 0; i < adap->log_addrs.num_log_addrs; i++)
if (adap->log_addrs.log_addr[i] == log_addr)
return i;
return -1;
}
static unsigned int cec_log_addr2dev(const struct cec_adapter *adap, u8 log_addr)
{
int i = cec_log_addr2idx(adap, log_addr);
return adap->log_addrs.primary_device_type[i < 0 ? 0 : i];
}
void cec_queue_event_fh(struct cec_fh *fh,
const struct cec_event *new_ev, u64 ts)
{
struct cec_event *ev = &fh->events[new_ev->event - 1];
if (ts == 0)
ts = ktime_get_ns();
mutex_lock(&fh->lock);
if (new_ev->event == CEC_EVENT_LOST_MSGS &&
fh->pending_events & (1 << new_ev->event)) {
ev->lost_msgs.lost_msgs += new_ev->lost_msgs.lost_msgs;
goto unlock;
}
*ev = *new_ev;
ev->ts = ts;
fh->pending_events |= 1 << new_ev->event;
unlock:
mutex_unlock(&fh->lock);
wake_up_interruptible(&fh->wait);
}
static void cec_queue_event(struct cec_adapter *adap,
const struct cec_event *ev)
{
u64 ts = ktime_get_ns();
struct cec_fh *fh;
mutex_lock(&adap->devnode.lock);
list_for_each_entry(fh, &adap->devnode.fhs, list)
cec_queue_event_fh(fh, ev, ts);
mutex_unlock(&adap->devnode.lock);
}
static void cec_queue_msg_fh(struct cec_fh *fh, const struct cec_msg *msg)
{
static const struct cec_event ev_lost_msg = {
.ts = 0,
.event = CEC_EVENT_LOST_MSGS,
.flags = 0,
{
.lost_msgs.lost_msgs = 1,
},
};
struct cec_msg_entry *entry;
mutex_lock(&fh->lock);
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
goto lost_msgs;
entry->msg = *msg;
list_add_tail(&entry->list, &fh->msgs);
if (fh->queued_msgs == CEC_MAX_MSG_RX_QUEUE_SZ) {
list_del(&entry->list);
goto lost_msgs;
}
fh->queued_msgs++;
mutex_unlock(&fh->lock);
wake_up_interruptible(&fh->wait);
return;
lost_msgs:
mutex_unlock(&fh->lock);
cec_queue_event_fh(fh, &ev_lost_msg, 0);
}
static void cec_queue_msg_monitor(struct cec_adapter *adap,
const struct cec_msg *msg,
bool valid_la)
{
struct cec_fh *fh;
u32 monitor_mode = valid_la ? CEC_MODE_MONITOR :
CEC_MODE_MONITOR_ALL;
mutex_lock(&adap->devnode.lock);
list_for_each_entry(fh, &adap->devnode.fhs, list) {
if (fh->mode_follower >= monitor_mode)
cec_queue_msg_fh(fh, msg);
}
mutex_unlock(&adap->devnode.lock);
}
static void cec_queue_msg_followers(struct cec_adapter *adap,
const struct cec_msg *msg)
{
struct cec_fh *fh;
mutex_lock(&adap->devnode.lock);
list_for_each_entry(fh, &adap->devnode.fhs, list) {
if (fh->mode_follower == CEC_MODE_FOLLOWER)
cec_queue_msg_fh(fh, msg);
}
mutex_unlock(&adap->devnode.lock);
}
static void cec_post_state_event(struct cec_adapter *adap)
{
struct cec_event ev = {
.event = CEC_EVENT_STATE_CHANGE,
};
ev.state_change.phys_addr = adap->phys_addr;
ev.state_change.log_addr_mask = adap->log_addrs.log_addr_mask;
cec_queue_event(adap, &ev);
}
static void cec_data_completed(struct cec_data *data)
{
if (data->fh)
list_del(&data->xfer_list);
if (data->blocking) {
data->completed = true;
complete(&data->c);
} else {
if (data->fh)
cec_queue_msg_fh(data->fh, &data->msg);
kfree(data);
}
}
static void cec_data_cancel(struct cec_data *data)
{
if (data->adap->transmitting == data) {
data->adap->transmitting = NULL;
} else {
list_del_init(&data->list);
if (!(data->msg.tx_status & CEC_TX_STATUS_OK))
data->adap->transmit_queue_sz--;
}
data->msg.tx_ts = ktime_get_ns();
data->msg.tx_status |= CEC_TX_STATUS_ERROR |
CEC_TX_STATUS_MAX_RETRIES;
data->msg.tx_error_cnt++;
data->attempts = 0;
cec_queue_msg_monitor(data->adap, &data->msg, 1);
cec_data_completed(data);
}
static void cec_flush(struct cec_adapter *adap)
{
struct cec_data *data, *n;
while (!list_empty(&adap->transmit_queue)) {
data = list_first_entry(&adap->transmit_queue,
struct cec_data, list);
cec_data_cancel(data);
}
if (adap->transmitting)
cec_data_cancel(adap->transmitting);
list_for_each_entry_safe(data, n, &adap->wait_queue, list) {
if (cancel_delayed_work(&data->work))
cec_data_cancel(data);
}
}
int cec_thread_func(void *_adap)
{
struct cec_adapter *adap = _adap;
for (;;) {
unsigned int signal_free_time;
struct cec_data *data;
bool timeout = false;
u8 attempts;
if (adap->transmitting) {
int err;
err = wait_event_interruptible_timeout(adap->kthread_waitq,
(adap->needs_hpd &&
(!adap->is_configured && !adap->is_configuring)) ||
kthread_should_stop() ||
(!adap->transmitting &&
!list_empty(&adap->transmit_queue)),
msecs_to_jiffies(CEC_XFER_TIMEOUT_MS));
timeout = err == 0;
} else {
wait_event_interruptible(adap->kthread_waitq,
kthread_should_stop() ||
(!adap->transmitting &&
!list_empty(&adap->transmit_queue)));
}
mutex_lock(&adap->lock);
if ((adap->needs_hpd &&
(!adap->is_configured && !adap->is_configuring)) ||
kthread_should_stop()) {
cec_flush(adap);
goto unlock;
}
if (adap->transmitting && timeout) {
dprintk(0, "%s: message %*ph timed out!\n", __func__,
adap->transmitting->msg.len,
adap->transmitting->msg.msg);
cec_data_cancel(adap->transmitting);
goto unlock;
}
if (adap->transmitting || list_empty(&adap->transmit_queue))
goto unlock;
data = list_first_entry(&adap->transmit_queue,
struct cec_data, list);
list_del_init(&data->list);
adap->transmit_queue_sz--;
adap->transmitting = data;
if (data->msg.len == 1 && adap->is_configured)
attempts = 2;
else
attempts = 4;
if (data->attempts) {
signal_free_time = CEC_SIGNAL_FREE_TIME_RETRY;
} else if (data->new_initiator) {
signal_free_time = CEC_SIGNAL_FREE_TIME_NEW_INITIATOR;
} else {
signal_free_time = CEC_SIGNAL_FREE_TIME_NEXT_XFER;
}
if (data->attempts == 0)
data->attempts = attempts;
if (adap->ops->adap_transmit(adap, data->attempts,
signal_free_time, &data->msg))
cec_data_cancel(data);
unlock:
mutex_unlock(&adap->lock);
if (kthread_should_stop())
break;
}
return 0;
}
void cec_transmit_done(struct cec_adapter *adap, u8 status, u8 arb_lost_cnt,
u8 nack_cnt, u8 low_drive_cnt, u8 error_cnt)
{
struct cec_data *data;
struct cec_msg *msg;
u64 ts = ktime_get_ns();
dprintk(2, "%s: status %02x\n", __func__, status);
mutex_lock(&adap->lock);
data = adap->transmitting;
if (!data) {
dprintk(1, "%s was called without an ongoing transmit!\n",
__func__);
goto unlock;
}
msg = &data->msg;
WARN_ON(status == 0);
msg->tx_ts = ts;
msg->tx_status |= status;
msg->tx_arb_lost_cnt += arb_lost_cnt;
msg->tx_nack_cnt += nack_cnt;
msg->tx_low_drive_cnt += low_drive_cnt;
msg->tx_error_cnt += error_cnt;
adap->transmitting = NULL;
if (data->attempts > 1 &&
!(status & (CEC_TX_STATUS_MAX_RETRIES | CEC_TX_STATUS_OK))) {
data->attempts--;
if (msg->timeout)
dprintk(2, "retransmit: %*ph (attempts: %d, wait for 0x%02x)\n",
msg->len, msg->msg, data->attempts, msg->reply);
else
dprintk(2, "retransmit: %*ph (attempts: %d)\n",
msg->len, msg->msg, data->attempts);
list_add(&data->list, &adap->transmit_queue);
adap->transmit_queue_sz++;
goto wake_thread;
}
data->attempts = 0;
if (!(status & CEC_TX_STATUS_OK))
msg->tx_status |= CEC_TX_STATUS_MAX_RETRIES;
cec_queue_msg_monitor(adap, msg, 1);
if ((status & CEC_TX_STATUS_OK) && adap->is_configured &&
msg->timeout) {
list_add_tail(&data->list, &adap->wait_queue);
schedule_delayed_work(&data->work,
msecs_to_jiffies(msg->timeout));
} else {
cec_data_completed(data);
}
wake_thread:
wake_up_interruptible(&adap->kthread_waitq);
unlock:
mutex_unlock(&adap->lock);
}
void cec_transmit_attempt_done(struct cec_adapter *adap, u8 status)
{
switch (status & ~CEC_TX_STATUS_MAX_RETRIES) {
case CEC_TX_STATUS_OK:
cec_transmit_done(adap, status, 0, 0, 0, 0);
return;
case CEC_TX_STATUS_ARB_LOST:
cec_transmit_done(adap, status, 1, 0, 0, 0);
return;
case CEC_TX_STATUS_NACK:
cec_transmit_done(adap, status, 0, 1, 0, 0);
return;
case CEC_TX_STATUS_LOW_DRIVE:
cec_transmit_done(adap, status, 0, 0, 1, 0);
return;
case CEC_TX_STATUS_ERROR:
cec_transmit_done(adap, status, 0, 0, 0, 1);
return;
default:
WARN(1, "cec-%s: invalid status 0x%02x\n", adap->name, status);
return;
}
}
static void cec_wait_timeout(struct work_struct *work)
{
struct cec_data *data = container_of(work, struct cec_data, work.work);
struct cec_adapter *adap = data->adap;
mutex_lock(&adap->lock);
if (list_empty(&data->list))
goto unlock;
list_del_init(&data->list);
data->msg.rx_ts = ktime_get_ns();
data->msg.rx_status = CEC_RX_STATUS_TIMEOUT;
cec_data_completed(data);
unlock:
mutex_unlock(&adap->lock);
}
int cec_transmit_msg_fh(struct cec_adapter *adap, struct cec_msg *msg,
struct cec_fh *fh, bool block)
{
struct cec_data *data;
u8 last_initiator = 0xff;
unsigned int timeout;
int res = 0;
msg->rx_ts = 0;
msg->tx_ts = 0;
msg->rx_status = 0;
msg->tx_status = 0;
msg->tx_arb_lost_cnt = 0;
msg->tx_nack_cnt = 0;
msg->tx_low_drive_cnt = 0;
msg->tx_error_cnt = 0;
msg->sequence = ++adap->sequence;
if (!msg->sequence)
msg->sequence = ++adap->sequence;
if (msg->reply && msg->timeout == 0) {
msg->timeout = 1000;
}
if (msg->timeout)
msg->flags &= CEC_MSG_FL_REPLY_TO_FOLLOWERS;
else
msg->flags = 0;
if (msg->len == 0 || msg->len > CEC_MAX_MSG_SIZE) {
dprintk(1, "%s: invalid length %d\n", __func__, msg->len);
return -EINVAL;
}
if (msg->timeout && msg->len == 1) {
dprintk(1, "%s: can't reply for poll msg\n", __func__);
return -EINVAL;
}
memset(msg->msg + msg->len, 0, sizeof(msg->msg) - msg->len);
if (msg->len == 1) {
if (cec_msg_destination(msg) == 0xf) {
dprintk(1, "%s: invalid poll message\n", __func__);
return -EINVAL;
}
if (cec_has_log_addr(adap, cec_msg_destination(msg))) {
msg->tx_ts = ktime_get_ns();
msg->tx_status = CEC_TX_STATUS_NACK |
CEC_TX_STATUS_MAX_RETRIES;
msg->tx_nack_cnt = 1;
return 0;
}
}
if (msg->len > 1 && !cec_msg_is_broadcast(msg) &&
cec_has_log_addr(adap, cec_msg_destination(msg))) {
dprintk(1, "%s: destination is the adapter itself\n", __func__);
return -EINVAL;
}
if (msg->len > 1 && adap->is_configured &&
!cec_has_log_addr(adap, cec_msg_initiator(msg))) {
dprintk(1, "%s: initiator has unknown logical address %d\n",
__func__, cec_msg_initiator(msg));
return -EINVAL;
}
if (!adap->is_configured && !adap->is_configuring) {
if (adap->needs_hpd || msg->msg[0] != 0xf0) {
dprintk(1, "%s: adapter is unconfigured\n", __func__);
return -ENONET;
}
if (msg->reply) {
dprintk(1, "%s: invalid msg->reply\n", __func__);
return -EINVAL;
}
}
if (adap->transmit_queue_sz >= CEC_MAX_MSG_TX_QUEUE_SZ) {
dprintk(1, "%s: transmit queue full\n", __func__);
return -EBUSY;
}
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (msg->len > 1 && msg->msg[1] == CEC_MSG_CDC_MESSAGE) {
msg->msg[2] = adap->phys_addr >> 8;
msg->msg[3] = adap->phys_addr & 0xff;
}
if (msg->timeout)
dprintk(2, "%s: %*ph (wait for 0x%02x%s)\n",
__func__, msg->len, msg->msg, msg->reply, !block ? ", nb" : "");
else
dprintk(2, "%s: %*ph%s\n",
__func__, msg->len, msg->msg, !block ? " (nb)" : "");
data->msg = *msg;
data->fh = fh;
data->adap = adap;
data->blocking = block;
if (msg->len > 1) {
if (!(list_empty(&adap->transmit_queue))) {
const struct cec_data *last;
last = list_last_entry(&adap->transmit_queue,
const struct cec_data, list);
last_initiator = cec_msg_initiator(&last->msg);
} else if (adap->transmitting) {
last_initiator =
cec_msg_initiator(&adap->transmitting->msg);
}
}
data->new_initiator = last_initiator != cec_msg_initiator(msg);
init_completion(&data->c);
INIT_DELAYED_WORK(&data->work, cec_wait_timeout);
if (fh)
list_add_tail(&data->xfer_list, &fh->xfer_list);
list_add_tail(&data->list, &adap->transmit_queue);
adap->transmit_queue_sz++;
if (!adap->transmitting)
wake_up_interruptible(&adap->kthread_waitq);
if (!block)
return 0;
timeout = CEC_XFER_TIMEOUT_MS;
if (msg->timeout)
timeout += msg->timeout;
mutex_unlock(&adap->lock);
res = wait_for_completion_killable_timeout(&data->c,
msecs_to_jiffies(timeout));
mutex_lock(&adap->lock);
if (data->completed) {
*msg = data->msg;
kfree(data);
return 0;
}
data->blocking = false;
if (data->fh)
list_del(&data->xfer_list);
data->fh = NULL;
if (res == 0) {
if (msg->timeout && (msg->tx_status & CEC_TX_STATUS_OK))
msg->rx_status = CEC_RX_STATUS_TIMEOUT;
else
msg->tx_status = CEC_TX_STATUS_MAX_RETRIES;
}
return res > 0 ? 0 : res;
}
int cec_transmit_msg(struct cec_adapter *adap, struct cec_msg *msg,
bool block)
{
int ret;
mutex_lock(&adap->lock);
ret = cec_transmit_msg_fh(adap, msg, NULL, block);
mutex_unlock(&adap->lock);
return ret;
}
void cec_received_msg(struct cec_adapter *adap, struct cec_msg *msg)
{
struct cec_data *data;
u8 msg_init = cec_msg_initiator(msg);
u8 msg_dest = cec_msg_destination(msg);
u8 cmd = msg->msg[1];
bool is_reply = false;
bool valid_la = true;
u8 min_len = 0;
if (WARN_ON(!msg->len || msg->len > CEC_MAX_MSG_SIZE))
return;
if (msg_init != CEC_LOG_ADDR_UNREGISTERED &&
cec_has_log_addr(adap, msg_init))
return;
msg->rx_ts = ktime_get_ns();
msg->rx_status = CEC_RX_STATUS_OK;
msg->sequence = msg->reply = msg->timeout = 0;
msg->tx_status = 0;
msg->tx_ts = 0;
msg->tx_arb_lost_cnt = 0;
msg->tx_nack_cnt = 0;
msg->tx_low_drive_cnt = 0;
msg->tx_error_cnt = 0;
msg->flags = 0;
memset(msg->msg + msg->len, 0, sizeof(msg->msg) - msg->len);
mutex_lock(&adap->lock);
dprintk(2, "%s: %*ph\n", __func__, msg->len, msg->msg);
if (!cec_msg_is_broadcast(msg))
valid_la = cec_has_log_addr(adap, msg_dest);
if (valid_la && msg->len > 1 && cec_msg_size[cmd]) {
u8 dir_fl = cec_msg_size[cmd] & BOTH;
min_len = cec_msg_size[cmd] & 0x1f;
if (msg->len < min_len)
valid_la = false;
else if (!cec_msg_is_broadcast(msg) && !(dir_fl & DIRECTED))
valid_la = false;
else if (cec_msg_is_broadcast(msg) && !(dir_fl & BCAST1_4))
valid_la = false;
else if (cec_msg_is_broadcast(msg) &&
adap->log_addrs.cec_version >= CEC_OP_CEC_VERSION_2_0 &&
!(dir_fl & BCAST2_0))
valid_la = false;
}
if (valid_la && min_len) {
switch (cmd) {
case CEC_MSG_TIMER_STATUS:
if (msg->msg[2] & 0x10) {
switch (msg->msg[2] & 0xf) {
case CEC_OP_PROG_INFO_NOT_ENOUGH_SPACE:
case CEC_OP_PROG_INFO_MIGHT_NOT_BE_ENOUGH_SPACE:
if (msg->len < 5)
valid_la = false;
break;
}
} else if ((msg->msg[2] & 0xf) == CEC_OP_PROG_ERROR_DUPLICATE) {
if (msg->len < 5)
valid_la = false;
}
break;
case CEC_MSG_RECORD_ON:
switch (msg->msg[2]) {
case CEC_OP_RECORD_SRC_OWN:
break;
case CEC_OP_RECORD_SRC_DIGITAL:
if (msg->len < 10)
valid_la = false;
break;
case CEC_OP_RECORD_SRC_ANALOG:
if (msg->len < 7)
valid_la = false;
break;
case CEC_OP_RECORD_SRC_EXT_PLUG:
if (msg->len < 4)
valid_la = false;
break;
case CEC_OP_RECORD_SRC_EXT_PHYS_ADDR:
if (msg->len < 5)
valid_la = false;
break;
}
break;
}
}
if (valid_la && msg->len > 1 && cmd != CEC_MSG_CDC_MESSAGE) {
bool abort = cmd == CEC_MSG_FEATURE_ABORT;
if (abort)
cmd = msg->msg[2];
list_for_each_entry(data, &adap->wait_queue, list) {
struct cec_msg *dst = &data->msg;
if (!abort && dst->msg[1] == CEC_MSG_INITIATE_ARC &&
(cmd == CEC_MSG_REPORT_ARC_INITIATED ||
cmd == CEC_MSG_REPORT_ARC_TERMINATED) &&
(dst->reply == CEC_MSG_REPORT_ARC_INITIATED ||
dst->reply == CEC_MSG_REPORT_ARC_TERMINATED))
dst->reply = cmd;
if ((abort && cmd != dst->msg[1]) ||
(!abort && cmd != dst->reply))
continue;
if (msg_init != cec_msg_destination(dst) &&
!cec_msg_is_broadcast(dst))
continue;
memcpy(dst->msg, msg->msg, msg->len);
dst->len = msg->len;
dst->rx_ts = msg->rx_ts;
dst->rx_status = msg->rx_status;
if (abort)
dst->rx_status |= CEC_RX_STATUS_FEATURE_ABORT;
msg->flags = dst->flags;
list_del_init(&data->list);
if (!cancel_delayed_work(&data->work)) {
mutex_unlock(&adap->lock);
flush_scheduled_work();
mutex_lock(&adap->lock);
}
if (data->fh)
is_reply = true;
cec_data_completed(data);
break;
}
}
mutex_unlock(&adap->lock);
cec_queue_msg_monitor(adap, msg, valid_la);
if (!valid_la || msg->len <= 1)
return;
if (adap->log_addrs.log_addr_mask == 0)
return;
cec_receive_notify(adap, msg, is_reply);
}
static int cec_config_log_addr(struct cec_adapter *adap,
unsigned int idx,
unsigned int log_addr)
{
struct cec_log_addrs *las = &adap->log_addrs;
struct cec_msg msg = { };
int err;
if (cec_has_log_addr(adap, log_addr))
return 0;
msg.len = 1;
msg.msg[0] = (log_addr << 4) | log_addr;
err = cec_transmit_msg_fh(adap, &msg, NULL, true);
if (!adap->is_configuring)
return -EINTR;
if (err)
return err;
if (msg.tx_status & CEC_TX_STATUS_OK)
return 0;
err = adap->ops->adap_log_addr(adap, log_addr);
if (err)
return err;
las->log_addr[idx] = log_addr;
las->log_addr_mask |= 1 << log_addr;
adap->phys_addrs[log_addr] = adap->phys_addr;
return 1;
}
static void cec_adap_unconfigure(struct cec_adapter *adap)
{
if (!adap->needs_hpd ||
adap->phys_addr != CEC_PHYS_ADDR_INVALID)
WARN_ON(adap->ops->adap_log_addr(adap, CEC_LOG_ADDR_INVALID));
adap->log_addrs.log_addr_mask = 0;
adap->is_configuring = false;
adap->is_configured = false;
memset(adap->phys_addrs, 0xff, sizeof(adap->phys_addrs));
cec_flush(adap);
wake_up_interruptible(&adap->kthread_waitq);
cec_post_state_event(adap);
}
static int cec_config_thread_func(void *arg)
{
static const u8 tv_log_addrs[] = {
CEC_LOG_ADDR_TV, CEC_LOG_ADDR_SPECIFIC,
CEC_LOG_ADDR_INVALID
};
static const u8 record_log_addrs[] = {
CEC_LOG_ADDR_RECORD_1, CEC_LOG_ADDR_RECORD_2,
CEC_LOG_ADDR_RECORD_3,
CEC_LOG_ADDR_BACKUP_1, CEC_LOG_ADDR_BACKUP_2,
CEC_LOG_ADDR_INVALID
};
static const u8 tuner_log_addrs[] = {
CEC_LOG_ADDR_TUNER_1, CEC_LOG_ADDR_TUNER_2,
CEC_LOG_ADDR_TUNER_3, CEC_LOG_ADDR_TUNER_4,
CEC_LOG_ADDR_BACKUP_1, CEC_LOG_ADDR_BACKUP_2,
CEC_LOG_ADDR_INVALID
};
static const u8 playback_log_addrs[] = {
CEC_LOG_ADDR_PLAYBACK_1, CEC_LOG_ADDR_PLAYBACK_2,
CEC_LOG_ADDR_PLAYBACK_3,
CEC_LOG_ADDR_BACKUP_1, CEC_LOG_ADDR_BACKUP_2,
CEC_LOG_ADDR_INVALID
};
static const u8 audiosystem_log_addrs[] = {
CEC_LOG_ADDR_AUDIOSYSTEM,
CEC_LOG_ADDR_INVALID
};
static const u8 specific_use_log_addrs[] = {
CEC_LOG_ADDR_SPECIFIC,
CEC_LOG_ADDR_BACKUP_1, CEC_LOG_ADDR_BACKUP_2,
CEC_LOG_ADDR_INVALID
};
static const u8 *type2addrs[6] = {
[CEC_LOG_ADDR_TYPE_TV] = tv_log_addrs,
[CEC_LOG_ADDR_TYPE_RECORD] = record_log_addrs,
[CEC_LOG_ADDR_TYPE_TUNER] = tuner_log_addrs,
[CEC_LOG_ADDR_TYPE_PLAYBACK] = playback_log_addrs,
[CEC_LOG_ADDR_TYPE_AUDIOSYSTEM] = audiosystem_log_addrs,
[CEC_LOG_ADDR_TYPE_SPECIFIC] = specific_use_log_addrs,
};
static const u16 type2mask[] = {
[CEC_LOG_ADDR_TYPE_TV] = CEC_LOG_ADDR_MASK_TV,
[CEC_LOG_ADDR_TYPE_RECORD] = CEC_LOG_ADDR_MASK_RECORD,
[CEC_LOG_ADDR_TYPE_TUNER] = CEC_LOG_ADDR_MASK_TUNER,
[CEC_LOG_ADDR_TYPE_PLAYBACK] = CEC_LOG_ADDR_MASK_PLAYBACK,
[CEC_LOG_ADDR_TYPE_AUDIOSYSTEM] = CEC_LOG_ADDR_MASK_AUDIOSYSTEM,
[CEC_LOG_ADDR_TYPE_SPECIFIC] = CEC_LOG_ADDR_MASK_SPECIFIC,
};
struct cec_adapter *adap = arg;
struct cec_log_addrs *las = &adap->log_addrs;
int err;
int i, j;
mutex_lock(&adap->lock);
dprintk(1, "physical address: %x.%x.%x.%x, claim %d logical addresses\n",
cec_phys_addr_exp(adap->phys_addr), las->num_log_addrs);
las->log_addr_mask = 0;
if (las->log_addr_type[0] == CEC_LOG_ADDR_TYPE_UNREGISTERED)
goto configured;
for (i = 0; i < las->num_log_addrs; i++) {
unsigned int type = las->log_addr_type[i];
const u8 *la_list;
u8 last_la;
if (adap->phys_addr && type == CEC_LOG_ADDR_TYPE_TV)
type = CEC_LOG_ADDR_TYPE_SPECIFIC;
la_list = type2addrs[type];
last_la = las->log_addr[i];
las->log_addr[i] = CEC_LOG_ADDR_INVALID;
if (last_la == CEC_LOG_ADDR_INVALID ||
last_la == CEC_LOG_ADDR_UNREGISTERED ||
!((1 << last_la) & type2mask[type]))
last_la = la_list[0];
err = cec_config_log_addr(adap, i, last_la);
if (err > 0)
continue;
if (err < 0)
goto unconfigure;
for (j = 0; la_list[j] != CEC_LOG_ADDR_INVALID; j++) {
if (la_list[j] == last_la)
continue;
if ((la_list[j] == CEC_LOG_ADDR_BACKUP_1 ||
la_list[j] == CEC_LOG_ADDR_BACKUP_2) &&
las->cec_version < CEC_OP_CEC_VERSION_2_0)
continue;
err = cec_config_log_addr(adap, i, la_list[j]);
if (err == 0)
continue;
if (err < 0)
goto unconfigure;
break;
}
if (la_list[j] == CEC_LOG_ADDR_INVALID)
dprintk(1, "could not claim LA %d\n", i);
}
if (adap->log_addrs.log_addr_mask == 0 &&
!(las->flags & CEC_LOG_ADDRS_FL_ALLOW_UNREG_FALLBACK))
goto unconfigure;
configured:
if (adap->log_addrs.log_addr_mask == 0) {
las->log_addr[0] = CEC_LOG_ADDR_UNREGISTERED;
las->log_addr_mask = 1 << las->log_addr[0];
for (i = 1; i < las->num_log_addrs; i++)
las->log_addr[i] = CEC_LOG_ADDR_INVALID;
}
for (i = las->num_log_addrs; i < CEC_MAX_LOG_ADDRS; i++)
las->log_addr[i] = CEC_LOG_ADDR_INVALID;
adap->is_configured = true;
adap->is_configuring = false;
cec_post_state_event(adap);
for (i = 0; i < las->num_log_addrs; i++) {
struct cec_msg msg = {};
if (las->log_addr[i] == CEC_LOG_ADDR_INVALID ||
(las->flags & CEC_LOG_ADDRS_FL_CDC_ONLY))
continue;
msg.msg[0] = (las->log_addr[i] << 4) | 0x0f;
if (las->log_addr[i] != CEC_LOG_ADDR_UNREGISTERED &&
adap->log_addrs.cec_version >= CEC_OP_CEC_VERSION_2_0) {
cec_fill_msg_report_features(adap, &msg, i);
cec_transmit_msg_fh(adap, &msg, NULL, false);
}
cec_msg_report_physical_addr(&msg, adap->phys_addr,
las->primary_device_type[i]);
dprintk(1, "config: la %d pa %x.%x.%x.%x\n",
las->log_addr[i],
cec_phys_addr_exp(adap->phys_addr));
cec_transmit_msg_fh(adap, &msg, NULL, false);
}
adap->kthread_config = NULL;
complete(&adap->config_completion);
mutex_unlock(&adap->lock);
return 0;
unconfigure:
for (i = 0; i < las->num_log_addrs; i++)
las->log_addr[i] = CEC_LOG_ADDR_INVALID;
cec_adap_unconfigure(adap);
adap->kthread_config = NULL;
mutex_unlock(&adap->lock);
complete(&adap->config_completion);
return 0;
}
static void cec_claim_log_addrs(struct cec_adapter *adap, bool block)
{
if (WARN_ON(adap->is_configuring || adap->is_configured))
return;
init_completion(&adap->config_completion);
adap->is_configuring = true;
adap->kthread_config = kthread_run(cec_config_thread_func, adap,
"ceccfg-%s", adap->name);
if (IS_ERR(adap->kthread_config)) {
adap->kthread_config = NULL;
} else if (block) {
mutex_unlock(&adap->lock);
wait_for_completion(&adap->config_completion);
mutex_lock(&adap->lock);
}
}
void __cec_s_phys_addr(struct cec_adapter *adap, u16 phys_addr, bool block)
{
if (phys_addr == adap->phys_addr || adap->devnode.unregistered)
return;
dprintk(1, "new physical address %x.%x.%x.%x\n",
cec_phys_addr_exp(phys_addr));
if (phys_addr == CEC_PHYS_ADDR_INVALID ||
adap->phys_addr != CEC_PHYS_ADDR_INVALID) {
adap->phys_addr = CEC_PHYS_ADDR_INVALID;
cec_post_state_event(adap);
cec_adap_unconfigure(adap);
if (adap->monitor_all_cnt)
WARN_ON(call_op(adap, adap_monitor_all_enable, false));
mutex_lock(&adap->devnode.lock);
if (adap->needs_hpd || list_empty(&adap->devnode.fhs))
WARN_ON(adap->ops->adap_enable(adap, false));
mutex_unlock(&adap->devnode.lock);
if (phys_addr == CEC_PHYS_ADDR_INVALID)
return;
}
mutex_lock(&adap->devnode.lock);
if ((adap->needs_hpd || list_empty(&adap->devnode.fhs)) &&
adap->ops->adap_enable(adap, true)) {
mutex_unlock(&adap->devnode.lock);
return;
}
if (adap->monitor_all_cnt &&
call_op(adap, adap_monitor_all_enable, true)) {
if (adap->needs_hpd || list_empty(&adap->devnode.fhs))
WARN_ON(adap->ops->adap_enable(adap, false));
mutex_unlock(&adap->devnode.lock);
return;
}
mutex_unlock(&adap->devnode.lock);
adap->phys_addr = phys_addr;
cec_post_state_event(adap);
if (adap->log_addrs.num_log_addrs)
cec_claim_log_addrs(adap, block);
}
void cec_s_phys_addr(struct cec_adapter *adap, u16 phys_addr, bool block)
{
if (IS_ERR_OR_NULL(adap))
return;
mutex_lock(&adap->lock);
__cec_s_phys_addr(adap, phys_addr, block);
mutex_unlock(&adap->lock);
}
void cec_s_phys_addr_from_edid(struct cec_adapter *adap,
const struct edid *edid)
{
u16 pa = CEC_PHYS_ADDR_INVALID;
if (edid && edid->extensions)
pa = cec_get_edid_phys_addr((const u8 *)edid,
EDID_LENGTH * (edid->extensions + 1), NULL);
cec_s_phys_addr(adap, pa, false);
}
int __cec_s_log_addrs(struct cec_adapter *adap,
struct cec_log_addrs *log_addrs, bool block)
{
u16 type_mask = 0;
int i;
if (adap->devnode.unregistered)
return -ENODEV;
if (!log_addrs || log_addrs->num_log_addrs == 0) {
adap->log_addrs.num_log_addrs = 0;
cec_adap_unconfigure(adap);
return 0;
}
if (log_addrs->flags & CEC_LOG_ADDRS_FL_CDC_ONLY) {
log_addrs->num_log_addrs = 1;
log_addrs->osd_name[0] = '\0';
log_addrs->vendor_id = CEC_VENDOR_ID_NONE;
log_addrs->log_addr_type[0] = CEC_LOG_ADDR_TYPE_UNREGISTERED;
log_addrs->primary_device_type[0] = CEC_OP_PRIM_DEVTYPE_SWITCH;
log_addrs->all_device_types[0] = 0;
log_addrs->features[0][0] = 0;
log_addrs->features[0][1] = 0;
}
log_addrs->osd_name[sizeof(log_addrs->osd_name) - 1] = '\0';
if (log_addrs->num_log_addrs > adap->available_log_addrs) {
dprintk(1, "num_log_addrs > %d\n", adap->available_log_addrs);
return -EINVAL;
}
if (log_addrs->vendor_id != CEC_VENDOR_ID_NONE &&
(log_addrs->vendor_id & 0xff000000) != 0) {
dprintk(1, "invalid vendor ID\n");
return -EINVAL;
}
if (log_addrs->cec_version != CEC_OP_CEC_VERSION_1_4 &&
log_addrs->cec_version != CEC_OP_CEC_VERSION_2_0) {
dprintk(1, "invalid CEC version\n");
return -EINVAL;
}
if (log_addrs->num_log_addrs > 1)
for (i = 0; i < log_addrs->num_log_addrs; i++)
if (log_addrs->log_addr_type[i] ==
CEC_LOG_ADDR_TYPE_UNREGISTERED) {
dprintk(1, "num_log_addrs > 1 can't be combined with unregistered LA\n");
return -EINVAL;
}
for (i = 0; i < log_addrs->num_log_addrs; i++) {
const u8 feature_sz = ARRAY_SIZE(log_addrs->features[0]);
u8 *features = log_addrs->features[i];
bool op_is_dev_features = false;
unsigned j;
log_addrs->log_addr[i] = CEC_LOG_ADDR_INVALID;
if (type_mask & (1 << log_addrs->log_addr_type[i])) {
dprintk(1, "duplicate logical address type\n");
return -EINVAL;
}
type_mask |= 1 << log_addrs->log_addr_type[i];
if ((type_mask & (1 << CEC_LOG_ADDR_TYPE_RECORD)) &&
(type_mask & (1 << CEC_LOG_ADDR_TYPE_PLAYBACK))) {
dprintk(1, "invalid record + playback combination\n");
return -EINVAL;
}
if (log_addrs->primary_device_type[i] >
CEC_OP_PRIM_DEVTYPE_PROCESSOR) {
dprintk(1, "unknown primary device type\n");
return -EINVAL;
}
if (log_addrs->primary_device_type[i] == 2) {
dprintk(1, "invalid primary device type\n");
return -EINVAL;
}
if (log_addrs->log_addr_type[i] > CEC_LOG_ADDR_TYPE_UNREGISTERED) {
dprintk(1, "unknown logical address type\n");
return -EINVAL;
}
for (j = 0; j < feature_sz; j++) {
if ((features[j] & 0x80) == 0) {
if (op_is_dev_features)
break;
op_is_dev_features = true;
}
}
if (!op_is_dev_features || j == feature_sz) {
dprintk(1, "malformed features\n");
return -EINVAL;
}
memset(features + j + 1, 0, feature_sz - j - 1);
}
if (log_addrs->cec_version >= CEC_OP_CEC_VERSION_2_0) {
if (log_addrs->num_log_addrs > 2) {
dprintk(1, "CEC 2.0 allows no more than 2 logical addresses\n");
return -EINVAL;
}
if (log_addrs->num_log_addrs == 2) {
if (!(type_mask & ((1 << CEC_LOG_ADDR_TYPE_AUDIOSYSTEM) |
(1 << CEC_LOG_ADDR_TYPE_TV)))) {
dprintk(1, "two LAs is only allowed for audiosystem and TV\n");
return -EINVAL;
}
if (!(type_mask & ((1 << CEC_LOG_ADDR_TYPE_PLAYBACK) |
(1 << CEC_LOG_ADDR_TYPE_RECORD)))) {
dprintk(1, "an audiosystem/TV can only be combined with record or playback\n");
return -EINVAL;
}
}
}
for (i = log_addrs->num_log_addrs; i < CEC_MAX_LOG_ADDRS; i++) {
log_addrs->primary_device_type[i] = 0;
log_addrs->log_addr_type[i] = 0;
log_addrs->all_device_types[i] = 0;
memset(log_addrs->features[i], 0,
sizeof(log_addrs->features[i]));
}
log_addrs->log_addr_mask = adap->log_addrs.log_addr_mask;
adap->log_addrs = *log_addrs;
if (adap->phys_addr != CEC_PHYS_ADDR_INVALID)
cec_claim_log_addrs(adap, block);
return 0;
}
int cec_s_log_addrs(struct cec_adapter *adap,
struct cec_log_addrs *log_addrs, bool block)
{
int err;
mutex_lock(&adap->lock);
err = __cec_s_log_addrs(adap, log_addrs, block);
mutex_unlock(&adap->lock);
return err;
}
static void cec_fill_msg_report_features(struct cec_adapter *adap,
struct cec_msg *msg,
unsigned int la_idx)
{
const struct cec_log_addrs *las = &adap->log_addrs;
const u8 *features = las->features[la_idx];
bool op_is_dev_features = false;
unsigned int idx;
msg->msg[0] = (las->log_addr[la_idx] << 4) | 0x0f;
msg->len = 4;
msg->msg[1] = CEC_MSG_REPORT_FEATURES;
msg->msg[2] = adap->log_addrs.cec_version;
msg->msg[3] = las->all_device_types[la_idx];
for (idx = 0; idx < ARRAY_SIZE(las->features[0]); idx++) {
msg->msg[msg->len++] = features[idx];
if ((features[idx] & CEC_OP_FEAT_EXT) == 0) {
if (op_is_dev_features)
break;
op_is_dev_features = true;
}
}
}
static int cec_feature_abort_reason(struct cec_adapter *adap,
struct cec_msg *msg, u8 reason)
{
struct cec_msg tx_msg = { };
if (msg->msg[1] == CEC_MSG_FEATURE_ABORT)
return 0;
if (cec_msg_initiator(msg) == CEC_LOG_ADDR_UNREGISTERED)
return 0;
cec_msg_set_reply_to(&tx_msg, msg);
cec_msg_feature_abort(&tx_msg, msg->msg[1], reason);
return cec_transmit_msg(adap, &tx_msg, false);
}
static int cec_feature_abort(struct cec_adapter *adap, struct cec_msg *msg)
{
return cec_feature_abort_reason(adap, msg,
CEC_OP_ABORT_UNRECOGNIZED_OP);
}
static int cec_feature_refused(struct cec_adapter *adap, struct cec_msg *msg)
{
return cec_feature_abort_reason(adap, msg,
CEC_OP_ABORT_REFUSED);
}
static int cec_receive_notify(struct cec_adapter *adap, struct cec_msg *msg,
bool is_reply)
{
bool is_broadcast = cec_msg_is_broadcast(msg);
u8 dest_laddr = cec_msg_destination(msg);
u8 init_laddr = cec_msg_initiator(msg);
u8 devtype = cec_log_addr2dev(adap, dest_laddr);
int la_idx = cec_log_addr2idx(adap, dest_laddr);
bool from_unregistered = init_laddr == 0xf;
struct cec_msg tx_cec_msg = { };
dprintk(2, "%s: %*ph\n", __func__, msg->len, msg->msg);
if (cec_is_cdc_only(&adap->log_addrs) &&
msg->msg[1] != CEC_MSG_CDC_MESSAGE)
return 0;
if (adap->ops->received) {
if (adap->ops->received(adap, msg) != -ENOMSG)
return 0;
}
switch (msg->msg[1]) {
case CEC_MSG_GET_CEC_VERSION:
case CEC_MSG_GIVE_DEVICE_VENDOR_ID:
case CEC_MSG_ABORT:
case CEC_MSG_GIVE_DEVICE_POWER_STATUS:
case CEC_MSG_GIVE_PHYSICAL_ADDR:
case CEC_MSG_GIVE_OSD_NAME:
case CEC_MSG_GIVE_FEATURES:
if (adap->passthrough)
goto skip_processing;
if (is_broadcast || from_unregistered)
return 0;
break;
case CEC_MSG_USER_CONTROL_PRESSED:
case CEC_MSG_USER_CONTROL_RELEASED:
if (is_broadcast || from_unregistered)
goto skip_processing;
break;
case CEC_MSG_REPORT_PHYSICAL_ADDR:
if (!is_broadcast)
goto skip_processing;
break;
default:
break;
}
cec_msg_set_reply_to(&tx_cec_msg, msg);
switch (msg->msg[1]) {
case CEC_MSG_REPORT_PHYSICAL_ADDR: {
u16 pa = (msg->msg[2] << 8) | msg->msg[3];
if (!from_unregistered)
adap->phys_addrs[init_laddr] = pa;
dprintk(1, "reported physical address %x.%x.%x.%x for logical address %d\n",
cec_phys_addr_exp(pa), init_laddr);
break;
}
case CEC_MSG_USER_CONTROL_PRESSED:
if (!(adap->capabilities & CEC_CAP_RC) ||
!(adap->log_addrs.flags & CEC_LOG_ADDRS_FL_ALLOW_RC_PASSTHRU))
break;
#ifdef CONFIG_MEDIA_CEC_RC
switch (msg->msg[2]) {
case 0x60:
if (msg->len == 2)
rc_keydown(adap->rc, RC_TYPE_CEC,
msg->msg[2], 0);
else
rc_keydown(adap->rc, RC_TYPE_CEC,
msg->msg[2] << 8 | msg->msg[3], 0);
break;
case 0x56: case 0x57:
case 0x67: case 0x68: case 0x69: case 0x6a:
break;
default:
rc_keydown(adap->rc, RC_TYPE_CEC, msg->msg[2], 0);
break;
}
#endif
break;
case CEC_MSG_USER_CONTROL_RELEASED:
if (!(adap->capabilities & CEC_CAP_RC) ||
!(adap->log_addrs.flags & CEC_LOG_ADDRS_FL_ALLOW_RC_PASSTHRU))
break;
#ifdef CONFIG_MEDIA_CEC_RC
rc_keyup(adap->rc);
#endif
break;
case CEC_MSG_GET_CEC_VERSION:
cec_msg_cec_version(&tx_cec_msg, adap->log_addrs.cec_version);
return cec_transmit_msg(adap, &tx_cec_msg, false);
case CEC_MSG_GIVE_PHYSICAL_ADDR:
if (devtype == CEC_OP_PRIM_DEVTYPE_SWITCH && dest_laddr == 15)
return 0;
cec_msg_report_physical_addr(&tx_cec_msg, adap->phys_addr, devtype);
return cec_transmit_msg(adap, &tx_cec_msg, false);
case CEC_MSG_GIVE_DEVICE_VENDOR_ID:
if (adap->log_addrs.vendor_id == CEC_VENDOR_ID_NONE)
return cec_feature_abort(adap, msg);
cec_msg_device_vendor_id(&tx_cec_msg, adap->log_addrs.vendor_id);
return cec_transmit_msg(adap, &tx_cec_msg, false);
case CEC_MSG_ABORT:
if (devtype == CEC_OP_PRIM_DEVTYPE_SWITCH)
return 0;
return cec_feature_refused(adap, msg);
case CEC_MSG_GIVE_OSD_NAME: {
if (adap->log_addrs.osd_name[0] == 0)
return cec_feature_abort(adap, msg);
cec_msg_set_osd_name(&tx_cec_msg, adap->log_addrs.osd_name);
return cec_transmit_msg(adap, &tx_cec_msg, false);
}
case CEC_MSG_GIVE_FEATURES:
if (adap->log_addrs.cec_version < CEC_OP_CEC_VERSION_2_0)
return cec_feature_abort(adap, msg);
cec_fill_msg_report_features(adap, &tx_cec_msg, la_idx);
return cec_transmit_msg(adap, &tx_cec_msg, false);
default:
if (!is_broadcast && !is_reply && !adap->follower_cnt &&
!adap->cec_follower && msg->msg[1] != CEC_MSG_FEATURE_ABORT)
return cec_feature_abort(adap, msg);
break;
}
skip_processing:
if (is_reply && !(msg->flags & CEC_MSG_FL_REPLY_TO_FOLLOWERS))
return 0;
if (adap->cec_follower)
cec_queue_msg_fh(adap->cec_follower, msg);
else
cec_queue_msg_followers(adap, msg);
return 0;
}
int cec_monitor_all_cnt_inc(struct cec_adapter *adap)
{
int ret = 0;
if (adap->monitor_all_cnt == 0)
ret = call_op(adap, adap_monitor_all_enable, 1);
if (ret == 0)
adap->monitor_all_cnt++;
return ret;
}
void cec_monitor_all_cnt_dec(struct cec_adapter *adap)
{
adap->monitor_all_cnt--;
if (adap->monitor_all_cnt == 0)
WARN_ON(call_op(adap, adap_monitor_all_enable, 0));
}
int cec_adap_status(struct seq_file *file, void *priv)
{
struct cec_adapter *adap = dev_get_drvdata(file->private);
struct cec_data *data;
mutex_lock(&adap->lock);
seq_printf(file, "configured: %d\n", adap->is_configured);
seq_printf(file, "configuring: %d\n", adap->is_configuring);
seq_printf(file, "phys_addr: %x.%x.%x.%x\n",
cec_phys_addr_exp(adap->phys_addr));
seq_printf(file, "number of LAs: %d\n", adap->log_addrs.num_log_addrs);
seq_printf(file, "LA mask: 0x%04x\n", adap->log_addrs.log_addr_mask);
if (adap->cec_follower)
seq_printf(file, "has CEC follower%s\n",
adap->passthrough ? " (in passthrough mode)" : "");
if (adap->cec_initiator)
seq_puts(file, "has CEC initiator\n");
if (adap->monitor_all_cnt)
seq_printf(file, "file handles in Monitor All mode: %u\n",
adap->monitor_all_cnt);
data = adap->transmitting;
if (data)
seq_printf(file, "transmitting message: %*ph (reply: %02x, timeout: %ums)\n",
data->msg.len, data->msg.msg, data->msg.reply,
data->msg.timeout);
seq_printf(file, "pending transmits: %u\n", adap->transmit_queue_sz);
list_for_each_entry(data, &adap->transmit_queue, list) {
seq_printf(file, "queued tx message: %*ph (reply: %02x, timeout: %ums)\n",
data->msg.len, data->msg.msg, data->msg.reply,
data->msg.timeout);
}
list_for_each_entry(data, &adap->wait_queue, list) {
seq_printf(file, "message waiting for reply: %*ph (reply: %02x, timeout: %ums)\n",
data->msg.len, data->msg.msg, data->msg.reply,
data->msg.timeout);
}
call_void_op(adap, adap_status, file);
mutex_unlock(&adap->lock);
return 0;
}
