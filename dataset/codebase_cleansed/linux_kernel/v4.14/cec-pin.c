static void cec_pin_update(struct cec_pin *pin, bool v, bool force)
{
if (!force && v == pin->adap->cec_pin_is_high)
return;
pin->adap->cec_pin_is_high = v;
if (atomic_read(&pin->work_pin_events) < CEC_NUM_PIN_EVENTS) {
pin->work_pin_is_high[pin->work_pin_events_wr] = v;
pin->work_pin_ts[pin->work_pin_events_wr] = ktime_get();
pin->work_pin_events_wr =
(pin->work_pin_events_wr + 1) % CEC_NUM_PIN_EVENTS;
atomic_inc(&pin->work_pin_events);
}
wake_up_interruptible(&pin->kthread_waitq);
}
static bool cec_pin_read(struct cec_pin *pin)
{
bool v = pin->ops->read(pin->adap);
cec_pin_update(pin, v, false);
return v;
}
static void cec_pin_low(struct cec_pin *pin)
{
pin->ops->low(pin->adap);
cec_pin_update(pin, false, false);
}
static bool cec_pin_high(struct cec_pin *pin)
{
pin->ops->high(pin->adap);
return cec_pin_read(pin);
}
static void cec_pin_to_idle(struct cec_pin *pin)
{
pin->rx_bit = pin->tx_bit = 0;
pin->rx_msg.len = 0;
memset(pin->rx_msg.msg, 0, sizeof(pin->rx_msg.msg));
pin->state = CEC_ST_IDLE;
pin->ts = 0;
}
static void cec_pin_tx_states(struct cec_pin *pin, ktime_t ts)
{
bool v;
bool is_ack_bit, ack;
switch (pin->state) {
case CEC_ST_TX_WAIT_FOR_HIGH:
if (cec_pin_read(pin))
cec_pin_to_idle(pin);
break;
case CEC_ST_TX_START_BIT_LOW:
pin->state = CEC_ST_TX_START_BIT_HIGH;
cec_pin_high(pin);
break;
case CEC_ST_TX_DATA_BIT_1_HIGH_POST_SAMPLE:
if (!cec_pin_read(pin)) {
pin->tx_msg.len = 0;
pin->work_tx_ts = ts;
pin->work_tx_status = CEC_TX_STATUS_LOW_DRIVE;
pin->state = CEC_ST_TX_WAIT_FOR_HIGH;
wake_up_interruptible(&pin->kthread_waitq);
break;
}
if (pin->tx_nacked) {
cec_pin_to_idle(pin);
pin->tx_msg.len = 0;
pin->work_tx_ts = ts;
pin->work_tx_status = CEC_TX_STATUS_NACK;
wake_up_interruptible(&pin->kthread_waitq);
break;
}
case CEC_ST_TX_DATA_BIT_0_HIGH:
case CEC_ST_TX_DATA_BIT_1_HIGH:
pin->tx_bit++;
case CEC_ST_TX_START_BIT_HIGH:
if (pin->tx_bit / 10 >= pin->tx_msg.len) {
cec_pin_to_idle(pin);
pin->tx_msg.len = 0;
pin->work_tx_ts = ts;
pin->work_tx_status = CEC_TX_STATUS_OK;
wake_up_interruptible(&pin->kthread_waitq);
break;
}
switch (pin->tx_bit % 10) {
default:
v = pin->tx_msg.msg[pin->tx_bit / 10] &
(1 << (7 - (pin->tx_bit % 10)));
pin->state = v ? CEC_ST_TX_DATA_BIT_1_LOW :
CEC_ST_TX_DATA_BIT_0_LOW;
break;
case 8:
v = pin->tx_bit / 10 == pin->tx_msg.len - 1;
pin->state = v ? CEC_ST_TX_DATA_BIT_1_LOW :
CEC_ST_TX_DATA_BIT_0_LOW;
break;
case 9:
pin->state = CEC_ST_TX_DATA_BIT_1_LOW;
break;
}
cec_pin_low(pin);
break;
case CEC_ST_TX_DATA_BIT_0_LOW:
case CEC_ST_TX_DATA_BIT_1_LOW:
v = pin->state == CEC_ST_TX_DATA_BIT_1_LOW;
pin->state = v ? CEC_ST_TX_DATA_BIT_1_HIGH :
CEC_ST_TX_DATA_BIT_0_HIGH;
is_ack_bit = pin->tx_bit % 10 == 9;
if (v && (pin->tx_bit < 4 || is_ack_bit))
pin->state = CEC_ST_TX_DATA_BIT_1_HIGH_PRE_SAMPLE;
cec_pin_high(pin);
break;
case CEC_ST_TX_DATA_BIT_1_HIGH_PRE_SAMPLE:
v = cec_pin_read(pin);
is_ack_bit = pin->tx_bit % 10 == 9;
if (!v && !is_ack_bit) {
pin->tx_msg.len = 0;
pin->work_tx_ts = ts;
pin->work_tx_status = CEC_TX_STATUS_ARB_LOST;
wake_up_interruptible(&pin->kthread_waitq);
pin->rx_bit = pin->tx_bit;
pin->tx_bit = 0;
memset(pin->rx_msg.msg, 0, sizeof(pin->rx_msg.msg));
pin->rx_msg.msg[0] = pin->tx_msg.msg[0];
pin->rx_msg.msg[0] &= ~(1 << (7 - pin->rx_bit));
pin->rx_msg.len = 0;
pin->state = CEC_ST_RX_DATA_POST_SAMPLE;
pin->rx_bit++;
break;
}
pin->state = CEC_ST_TX_DATA_BIT_1_HIGH_POST_SAMPLE;
if (!is_ack_bit)
break;
ack = cec_msg_is_broadcast(&pin->tx_msg) ? v : !v;
if (!ack) {
pin->tx_nacked = true;
}
break;
default:
break;
}
}
static void cec_pin_rx_states(struct cec_pin *pin, ktime_t ts)
{
s32 delta;
bool v;
bool ack;
bool bcast, for_us;
u8 dest;
switch (pin->state) {
case CEC_ST_RX_START_BIT_LOW:
v = cec_pin_read(pin);
if (!v)
break;
pin->state = CEC_ST_RX_START_BIT_HIGH;
delta = ktime_us_delta(ts, pin->ts);
pin->ts = ts;
if (delta < CEC_TIM_START_BIT_LOW_MIN -
CEC_TIM_IDLE_SAMPLE) {
cec_pin_to_idle(pin);
}
break;
case CEC_ST_RX_START_BIT_HIGH:
v = cec_pin_read(pin);
delta = ktime_us_delta(ts, pin->ts);
if (v && delta > CEC_TIM_START_BIT_TOTAL_MAX -
CEC_TIM_START_BIT_LOW_MIN) {
cec_pin_to_idle(pin);
break;
}
if (v)
break;
pin->state = CEC_ST_RX_DATA_SAMPLE;
pin->ts = ts;
pin->rx_eom = false;
break;
case CEC_ST_RX_DATA_SAMPLE:
v = cec_pin_read(pin);
pin->state = CEC_ST_RX_DATA_POST_SAMPLE;
switch (pin->rx_bit % 10) {
default:
if (pin->rx_bit / 10 < CEC_MAX_MSG_SIZE)
pin->rx_msg.msg[pin->rx_bit / 10] |=
v << (7 - (pin->rx_bit % 10));
break;
case 8:
pin->rx_eom = v;
pin->rx_msg.len = pin->rx_bit / 10 + 1;
break;
case 9:
break;
}
pin->rx_bit++;
break;
case CEC_ST_RX_DATA_POST_SAMPLE:
pin->state = CEC_ST_RX_DATA_HIGH;
break;
case CEC_ST_RX_DATA_HIGH:
v = cec_pin_read(pin);
delta = ktime_us_delta(ts, pin->ts);
if (v && delta > CEC_TIM_DATA_BIT_TOTAL_MAX) {
cec_pin_to_idle(pin);
break;
}
if (v)
break;
if (delta < CEC_TIM_DATA_BIT_TOTAL_MIN) {
cec_pin_low(pin);
pin->state = CEC_ST_LOW_DRIVE;
break;
}
pin->ts = ts;
if (pin->rx_bit % 10 != 9) {
pin->state = CEC_ST_RX_DATA_SAMPLE;
break;
}
dest = cec_msg_destination(&pin->rx_msg);
bcast = dest == CEC_LOG_ADDR_BROADCAST;
for_us = bcast || (pin->la_mask & (1 << dest));
ack = bcast ? 1 : !for_us;
if (ack) {
pin->state = CEC_ST_RX_ACK_HIGH_POST;
break;
}
cec_pin_low(pin);
pin->state = CEC_ST_RX_ACK_LOW;
break;
case CEC_ST_RX_ACK_LOW:
cec_pin_high(pin);
pin->state = CEC_ST_RX_ACK_LOW_POST;
break;
case CEC_ST_RX_ACK_LOW_POST:
case CEC_ST_RX_ACK_HIGH_POST:
v = cec_pin_read(pin);
if (v && pin->rx_eom) {
pin->work_rx_msg = pin->rx_msg;
pin->work_rx_msg.rx_ts = ts;
wake_up_interruptible(&pin->kthread_waitq);
pin->ts = ts;
pin->state = CEC_ST_RX_ACK_FINISH;
break;
}
pin->rx_bit++;
pin->state = CEC_ST_RX_DATA_HIGH;
break;
case CEC_ST_RX_ACK_FINISH:
cec_pin_to_idle(pin);
break;
default:
break;
}
}
static enum hrtimer_restart cec_pin_timer(struct hrtimer *timer)
{
struct cec_pin *pin = container_of(timer, struct cec_pin, timer);
struct cec_adapter *adap = pin->adap;
ktime_t ts;
s32 delta;
ts = ktime_get();
if (pin->timer_ts) {
delta = ktime_us_delta(ts, pin->timer_ts);
pin->timer_cnt++;
if (delta > 100 && pin->state != CEC_ST_IDLE) {
pin->timer_sum_overrun += delta;
pin->timer_100ms_overruns++;
if (delta > 300)
pin->timer_300ms_overruns++;
if (delta > pin->timer_max_overrun)
pin->timer_max_overrun = delta;
}
}
if (adap->monitor_pin_cnt)
cec_pin_read(pin);
if (pin->wait_usecs) {
if (pin->wait_usecs > 150) {
pin->wait_usecs -= 100;
pin->timer_ts = ktime_add_us(ts, 100);
hrtimer_forward_now(timer, 100000);
return HRTIMER_RESTART;
}
if (pin->wait_usecs > 100) {
pin->wait_usecs /= 2;
pin->timer_ts = ktime_add_us(ts, pin->wait_usecs);
hrtimer_forward_now(timer, pin->wait_usecs * 1000);
return HRTIMER_RESTART;
}
pin->timer_ts = ktime_add_us(ts, pin->wait_usecs);
hrtimer_forward_now(timer, pin->wait_usecs * 1000);
pin->wait_usecs = 0;
return HRTIMER_RESTART;
}
switch (pin->state) {
case CEC_ST_TX_WAIT_FOR_HIGH:
case CEC_ST_TX_START_BIT_LOW:
case CEC_ST_TX_DATA_BIT_1_HIGH_POST_SAMPLE:
case CEC_ST_TX_DATA_BIT_0_HIGH:
case CEC_ST_TX_DATA_BIT_1_HIGH:
case CEC_ST_TX_START_BIT_HIGH:
case CEC_ST_TX_DATA_BIT_0_LOW:
case CEC_ST_TX_DATA_BIT_1_LOW:
case CEC_ST_TX_DATA_BIT_1_HIGH_PRE_SAMPLE:
cec_pin_tx_states(pin, ts);
break;
case CEC_ST_RX_START_BIT_LOW:
case CEC_ST_RX_START_BIT_HIGH:
case CEC_ST_RX_DATA_SAMPLE:
case CEC_ST_RX_DATA_POST_SAMPLE:
case CEC_ST_RX_DATA_HIGH:
case CEC_ST_RX_ACK_LOW:
case CEC_ST_RX_ACK_LOW_POST:
case CEC_ST_RX_ACK_HIGH_POST:
case CEC_ST_RX_ACK_FINISH:
cec_pin_rx_states(pin, ts);
break;
case CEC_ST_IDLE:
case CEC_ST_TX_WAIT:
if (!cec_pin_high(pin)) {
pin->ts = ts;
pin->state = CEC_ST_RX_START_BIT_LOW;
break;
}
if (pin->ts == 0)
pin->ts = ts;
if (pin->tx_msg.len) {
delta = ktime_us_delta(ts, pin->ts);
if (delta / CEC_TIM_DATA_BIT_TOTAL >
pin->tx_signal_free_time) {
pin->tx_nacked = false;
pin->state = CEC_ST_TX_START_BIT_LOW;
cec_pin_low(pin);
break;
}
if (delta / CEC_TIM_DATA_BIT_TOTAL >
pin->tx_signal_free_time - 1)
pin->state = CEC_ST_TX_WAIT;
break;
}
if (pin->state != CEC_ST_IDLE || pin->ops->enable_irq == NULL ||
pin->enable_irq_failed || adap->is_configuring ||
adap->is_configured || adap->monitor_all_cnt)
break;
atomic_set(&pin->work_irq_change, CEC_PIN_IRQ_ENABLE);
pin->state = CEC_ST_RX_IRQ;
wake_up_interruptible(&pin->kthread_waitq);
return HRTIMER_NORESTART;
case CEC_ST_LOW_DRIVE:
cec_pin_to_idle(pin);
break;
default:
break;
}
if (!adap->monitor_pin_cnt || states[pin->state].usecs <= 150) {
pin->wait_usecs = 0;
pin->timer_ts = ktime_add_us(ts, states[pin->state].usecs);
hrtimer_forward_now(timer, states[pin->state].usecs * 1000);
return HRTIMER_RESTART;
}
pin->wait_usecs = states[pin->state].usecs - 100;
pin->timer_ts = ktime_add_us(ts, 100);
hrtimer_forward_now(timer, 100000);
return HRTIMER_RESTART;
}
static int cec_pin_thread_func(void *_adap)
{
struct cec_adapter *adap = _adap;
struct cec_pin *pin = adap->pin;
for (;;) {
wait_event_interruptible(pin->kthread_waitq,
kthread_should_stop() ||
pin->work_rx_msg.len ||
pin->work_tx_status ||
atomic_read(&pin->work_irq_change) ||
atomic_read(&pin->work_pin_events));
if (pin->work_rx_msg.len) {
cec_received_msg_ts(adap, &pin->work_rx_msg,
pin->work_rx_msg.rx_ts);
pin->work_rx_msg.len = 0;
}
if (pin->work_tx_status) {
unsigned int tx_status = pin->work_tx_status;
pin->work_tx_status = 0;
cec_transmit_attempt_done_ts(adap, tx_status,
pin->work_tx_ts);
}
while (atomic_read(&pin->work_pin_events)) {
unsigned int idx = pin->work_pin_events_rd;
cec_queue_pin_cec_event(adap,
pin->work_pin_is_high[idx],
pin->work_pin_ts[idx]);
pin->work_pin_events_rd = (idx + 1) % CEC_NUM_PIN_EVENTS;
atomic_dec(&pin->work_pin_events);
}
switch (atomic_xchg(&pin->work_irq_change,
CEC_PIN_IRQ_UNCHANGED)) {
case CEC_PIN_IRQ_DISABLE:
pin->ops->disable_irq(adap);
cec_pin_high(pin);
cec_pin_to_idle(pin);
hrtimer_start(&pin->timer, 0, HRTIMER_MODE_REL);
break;
case CEC_PIN_IRQ_ENABLE:
pin->enable_irq_failed = !pin->ops->enable_irq(adap);
if (pin->enable_irq_failed) {
cec_pin_to_idle(pin);
hrtimer_start(&pin->timer, 0, HRTIMER_MODE_REL);
}
break;
default:
break;
}
if (kthread_should_stop())
break;
}
return 0;
}
static int cec_pin_adap_enable(struct cec_adapter *adap, bool enable)
{
struct cec_pin *pin = adap->pin;
pin->enabled = enable;
if (enable) {
atomic_set(&pin->work_pin_events, 0);
pin->work_pin_events_rd = pin->work_pin_events_wr = 0;
cec_pin_read(pin);
cec_pin_to_idle(pin);
pin->tx_msg.len = 0;
pin->timer_ts = 0;
atomic_set(&pin->work_irq_change, CEC_PIN_IRQ_UNCHANGED);
pin->kthread = kthread_run(cec_pin_thread_func, adap,
"cec-pin");
if (IS_ERR(pin->kthread)) {
pr_err("cec-pin: kernel_thread() failed\n");
return PTR_ERR(pin->kthread);
}
hrtimer_start(&pin->timer, 0, HRTIMER_MODE_REL);
} else {
if (pin->ops->disable_irq)
pin->ops->disable_irq(adap);
hrtimer_cancel(&pin->timer);
kthread_stop(pin->kthread);
cec_pin_read(pin);
cec_pin_to_idle(pin);
pin->state = CEC_ST_OFF;
}
return 0;
}
static int cec_pin_adap_log_addr(struct cec_adapter *adap, u8 log_addr)
{
struct cec_pin *pin = adap->pin;
if (log_addr == CEC_LOG_ADDR_INVALID)
pin->la_mask = 0;
else
pin->la_mask |= (1 << log_addr);
return 0;
}
static int cec_pin_adap_transmit(struct cec_adapter *adap, u8 attempts,
u32 signal_free_time, struct cec_msg *msg)
{
struct cec_pin *pin = adap->pin;
pin->tx_signal_free_time = signal_free_time;
pin->tx_msg = *msg;
pin->work_tx_status = 0;
pin->tx_bit = 0;
if (pin->state == CEC_ST_RX_IRQ) {
atomic_set(&pin->work_irq_change, CEC_PIN_IRQ_UNCHANGED);
pin->ops->disable_irq(adap);
cec_pin_high(pin);
cec_pin_to_idle(pin);
hrtimer_start(&pin->timer, 0, HRTIMER_MODE_REL);
}
return 0;
}
static void cec_pin_adap_status(struct cec_adapter *adap,
struct seq_file *file)
{
struct cec_pin *pin = adap->pin;
seq_printf(file, "state: %s\n", states[pin->state].name);
seq_printf(file, "tx_bit: %d\n", pin->tx_bit);
seq_printf(file, "rx_bit: %d\n", pin->rx_bit);
seq_printf(file, "cec pin: %d\n", pin->ops->read(adap));
seq_printf(file, "irq failed: %d\n", pin->enable_irq_failed);
if (pin->timer_100ms_overruns) {
seq_printf(file, "timer overruns > 100ms: %u of %u\n",
pin->timer_100ms_overruns, pin->timer_cnt);
seq_printf(file, "timer overruns > 300ms: %u of %u\n",
pin->timer_300ms_overruns, pin->timer_cnt);
seq_printf(file, "max timer overrun: %u usecs\n",
pin->timer_max_overrun);
seq_printf(file, "avg timer overrun: %u usecs\n",
pin->timer_sum_overrun / pin->timer_100ms_overruns);
}
pin->timer_cnt = 0;
pin->timer_100ms_overruns = 0;
pin->timer_300ms_overruns = 0;
pin->timer_max_overrun = 0;
pin->timer_sum_overrun = 0;
if (pin->ops->status)
pin->ops->status(adap, file);
}
static int cec_pin_adap_monitor_all_enable(struct cec_adapter *adap,
bool enable)
{
struct cec_pin *pin = adap->pin;
pin->monitor_all = enable;
return 0;
}
static void cec_pin_adap_free(struct cec_adapter *adap)
{
struct cec_pin *pin = adap->pin;
if (pin->ops->free)
pin->ops->free(adap);
adap->pin = NULL;
kfree(pin);
}
void cec_pin_changed(struct cec_adapter *adap, bool value)
{
struct cec_pin *pin = adap->pin;
cec_pin_update(pin, value, false);
if (!value && (adap->is_configuring || adap->is_configured ||
adap->monitor_all_cnt))
atomic_set(&pin->work_irq_change, CEC_PIN_IRQ_DISABLE);
}
struct cec_adapter *cec_pin_allocate_adapter(const struct cec_pin_ops *pin_ops,
void *priv, const char *name, u32 caps)
{
struct cec_adapter *adap;
struct cec_pin *pin = kzalloc(sizeof(*pin), GFP_KERNEL);
if (pin == NULL)
return ERR_PTR(-ENOMEM);
pin->ops = pin_ops;
hrtimer_init(&pin->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
pin->timer.function = cec_pin_timer;
init_waitqueue_head(&pin->kthread_waitq);
adap = cec_allocate_adapter(&cec_pin_adap_ops, priv, name,
caps | CEC_CAP_MONITOR_ALL | CEC_CAP_MONITOR_PIN,
CEC_MAX_LOG_ADDRS);
if (PTR_ERR_OR_ZERO(adap)) {
kfree(pin);
return adap;
}
adap->pin = pin;
pin->adap = adap;
cec_pin_update(pin, cec_pin_high(pin), true);
return adap;
}
