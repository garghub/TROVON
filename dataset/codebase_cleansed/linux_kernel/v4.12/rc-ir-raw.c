static int ir_raw_event_thread(void *data)
{
struct ir_raw_event ev;
struct ir_raw_handler *handler;
struct ir_raw_event_ctrl *raw = (struct ir_raw_event_ctrl *)data;
while (1) {
mutex_lock(&ir_raw_handler_lock);
while (kfifo_out(&raw->kfifo, &ev, 1)) {
list_for_each_entry(handler, &ir_raw_handler_list, list)
if (raw->dev->enabled_protocols &
handler->protocols || !handler->protocols)
handler->decode(raw->dev, ev);
raw->prev_ev = ev;
}
mutex_unlock(&ir_raw_handler_lock);
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop()) {
__set_current_state(TASK_RUNNING);
break;
} else if (!kfifo_is_empty(&raw->kfifo))
set_current_state(TASK_RUNNING);
schedule();
}
return 0;
}
int ir_raw_event_store(struct rc_dev *dev, struct ir_raw_event *ev)
{
if (!dev->raw)
return -EINVAL;
IR_dprintk(2, "sample: (%05dus %s)\n",
TO_US(ev->duration), TO_STR(ev->pulse));
if (!kfifo_put(&dev->raw->kfifo, *ev)) {
dev_err(&dev->dev, "IR event FIFO is full!\n");
return -ENOSPC;
}
return 0;
}
int ir_raw_event_store_edge(struct rc_dev *dev, enum raw_event_type type)
{
ktime_t now;
s64 delta;
DEFINE_IR_RAW_EVENT(ev);
int rc = 0;
int delay;
if (!dev->raw)
return -EINVAL;
now = ktime_get();
delta = ktime_to_ns(ktime_sub(now, dev->raw->last_event));
delay = MS_TO_NS(dev->input_dev->rep[REP_DELAY]);
if (delta > delay || !dev->raw->last_type)
type |= IR_START_EVENT;
else
ev.duration = delta;
if (type & IR_START_EVENT)
ir_raw_event_reset(dev);
else if (dev->raw->last_type & IR_SPACE) {
ev.pulse = false;
rc = ir_raw_event_store(dev, &ev);
} else if (dev->raw->last_type & IR_PULSE) {
ev.pulse = true;
rc = ir_raw_event_store(dev, &ev);
} else
return 0;
dev->raw->last_event = now;
dev->raw->last_type = type;
return rc;
}
int ir_raw_event_store_with_filter(struct rc_dev *dev, struct ir_raw_event *ev)
{
if (!dev->raw)
return -EINVAL;
if (dev->idle && !ev->pulse)
return 0;
else if (dev->idle)
ir_raw_event_set_idle(dev, false);
if (!dev->raw->this_ev.duration)
dev->raw->this_ev = *ev;
else if (ev->pulse == dev->raw->this_ev.pulse)
dev->raw->this_ev.duration += ev->duration;
else {
ir_raw_event_store(dev, &dev->raw->this_ev);
dev->raw->this_ev = *ev;
}
if (!ev->pulse && dev->timeout &&
dev->raw->this_ev.duration >= dev->timeout)
ir_raw_event_set_idle(dev, true);
return 1;
}
void ir_raw_event_set_idle(struct rc_dev *dev, bool idle)
{
if (!dev->raw)
return;
IR_dprintk(2, "%s idle mode\n", idle ? "enter" : "leave");
if (idle) {
dev->raw->this_ev.timeout = true;
ir_raw_event_store(dev, &dev->raw->this_ev);
init_ir_raw_event(&dev->raw->this_ev);
}
if (dev->s_idle)
dev->s_idle(dev, idle);
dev->idle = idle;
}
void ir_raw_event_handle(struct rc_dev *dev)
{
if (!dev->raw || !dev->raw->thread)
return;
wake_up_process(dev->raw->thread);
}
u64
ir_raw_get_allowed_protocols(void)
{
return atomic64_read(&available_protocols);
}
static int change_protocol(struct rc_dev *dev, u64 *rc_type)
{
return 0;
}
static void ir_raw_disable_protocols(struct rc_dev *dev, u64 protocols)
{
mutex_lock(&dev->lock);
dev->enabled_protocols &= ~protocols;
mutex_unlock(&dev->lock);
}
int ir_raw_gen_manchester(struct ir_raw_event **ev, unsigned int max,
const struct ir_raw_timings_manchester *timings,
unsigned int n, u64 data)
{
bool need_pulse;
u64 i;
int ret = -ENOBUFS;
i = BIT_ULL(n - 1);
if (timings->leader) {
if (!max--)
return ret;
if (timings->pulse_space_start) {
init_ir_raw_event_duration((*ev)++, 1, timings->leader);
if (!max--)
return ret;
init_ir_raw_event_duration((*ev), 0, timings->leader);
} else {
init_ir_raw_event_duration((*ev), 1, timings->leader);
}
i >>= 1;
} else {
--(*ev);
}
while (n && i > 0) {
need_pulse = !(data & i);
if (timings->invert)
need_pulse = !need_pulse;
if (need_pulse == !!(*ev)->pulse) {
(*ev)->duration += timings->clock;
} else {
if (!max--)
goto nobufs;
init_ir_raw_event_duration(++(*ev), need_pulse,
timings->clock);
}
if (!max--)
goto nobufs;
init_ir_raw_event_duration(++(*ev), !need_pulse,
timings->clock);
i >>= 1;
}
if (timings->trailer_space) {
if (!(*ev)->pulse)
(*ev)->duration += timings->trailer_space;
else if (!max--)
goto nobufs;
else
init_ir_raw_event_duration(++(*ev), 0,
timings->trailer_space);
}
ret = 0;
nobufs:
++(*ev);
return ret;
}
int ir_raw_gen_pd(struct ir_raw_event **ev, unsigned int max,
const struct ir_raw_timings_pd *timings,
unsigned int n, u64 data)
{
int i;
int ret;
unsigned int space;
if (timings->header_pulse) {
ret = ir_raw_gen_pulse_space(ev, &max, timings->header_pulse,
timings->header_space);
if (ret)
return ret;
}
if (timings->msb_first) {
for (i = n - 1; i >= 0; --i) {
space = timings->bit_space[(data >> i) & 1];
ret = ir_raw_gen_pulse_space(ev, &max,
timings->bit_pulse,
space);
if (ret)
return ret;
}
} else {
for (i = 0; i < n; ++i, data >>= 1) {
space = timings->bit_space[data & 1];
ret = ir_raw_gen_pulse_space(ev, &max,
timings->bit_pulse,
space);
if (ret)
return ret;
}
}
ret = ir_raw_gen_pulse_space(ev, &max, timings->trailer_pulse,
timings->trailer_space);
return ret;
}
int ir_raw_gen_pl(struct ir_raw_event **ev, unsigned int max,
const struct ir_raw_timings_pl *timings,
unsigned int n, u64 data)
{
int i;
int ret = -ENOBUFS;
unsigned int pulse;
if (!max--)
return ret;
init_ir_raw_event_duration((*ev)++, 1, timings->header_pulse);
if (timings->msb_first) {
for (i = n - 1; i >= 0; --i) {
if (!max--)
return ret;
init_ir_raw_event_duration((*ev)++, 0,
timings->bit_space);
if (!max--)
return ret;
pulse = timings->bit_pulse[(data >> i) & 1];
init_ir_raw_event_duration((*ev)++, 1, pulse);
}
} else {
for (i = 0; i < n; ++i, data >>= 1) {
if (!max--)
return ret;
init_ir_raw_event_duration((*ev)++, 0,
timings->bit_space);
if (!max--)
return ret;
pulse = timings->bit_pulse[data & 1];
init_ir_raw_event_duration((*ev)++, 1, pulse);
}
}
if (!max--)
return ret;
init_ir_raw_event_duration((*ev)++, 0, timings->trailer_space);
return 0;
}
int ir_raw_encode_scancode(enum rc_type protocol, u32 scancode,
struct ir_raw_event *events, unsigned int max)
{
struct ir_raw_handler *handler;
int ret = -EINVAL;
u64 mask = 1ULL << protocol;
mutex_lock(&ir_raw_handler_lock);
list_for_each_entry(handler, &ir_raw_handler_list, list) {
if (handler->protocols & mask && handler->encode) {
ret = handler->encode(protocol, scancode, events, max);
if (ret >= 0 || ret == -ENOBUFS)
break;
}
}
mutex_unlock(&ir_raw_handler_lock);
return ret;
}
int ir_raw_event_register(struct rc_dev *dev)
{
int rc;
struct ir_raw_handler *handler;
struct task_struct *thread;
if (!dev)
return -EINVAL;
dev->raw = kzalloc(sizeof(*dev->raw), GFP_KERNEL);
if (!dev->raw)
return -ENOMEM;
dev->raw->dev = dev;
dev->change_protocol = change_protocol;
INIT_KFIFO(dev->raw->kfifo);
if (dev->driver_type != RC_DRIVER_IR_RAW_TX) {
thread = kthread_run(ir_raw_event_thread, dev->raw, "rc%u",
dev->minor);
if (IS_ERR(thread)) {
rc = PTR_ERR(thread);
goto out;
}
dev->raw->thread = thread;
}
mutex_lock(&ir_raw_handler_lock);
list_add_tail(&dev->raw->list, &ir_raw_client_list);
list_for_each_entry(handler, &ir_raw_handler_list, list)
if (handler->raw_register)
handler->raw_register(dev);
mutex_unlock(&ir_raw_handler_lock);
return 0;
out:
kfree(dev->raw);
dev->raw = NULL;
return rc;
}
void ir_raw_event_unregister(struct rc_dev *dev)
{
struct ir_raw_handler *handler;
if (!dev || !dev->raw)
return;
kthread_stop(dev->raw->thread);
mutex_lock(&ir_raw_handler_lock);
list_del(&dev->raw->list);
list_for_each_entry(handler, &ir_raw_handler_list, list)
if (handler->raw_unregister)
handler->raw_unregister(dev);
mutex_unlock(&ir_raw_handler_lock);
kfree(dev->raw);
dev->raw = NULL;
}
int ir_raw_handler_register(struct ir_raw_handler *ir_raw_handler)
{
struct ir_raw_event_ctrl *raw;
mutex_lock(&ir_raw_handler_lock);
list_add_tail(&ir_raw_handler->list, &ir_raw_handler_list);
if (ir_raw_handler->raw_register)
list_for_each_entry(raw, &ir_raw_client_list, list)
ir_raw_handler->raw_register(raw->dev);
atomic64_or(ir_raw_handler->protocols, &available_protocols);
mutex_unlock(&ir_raw_handler_lock);
return 0;
}
void ir_raw_handler_unregister(struct ir_raw_handler *ir_raw_handler)
{
struct ir_raw_event_ctrl *raw;
u64 protocols = ir_raw_handler->protocols;
mutex_lock(&ir_raw_handler_lock);
list_del(&ir_raw_handler->list);
list_for_each_entry(raw, &ir_raw_client_list, list) {
ir_raw_disable_protocols(raw->dev, protocols);
if (ir_raw_handler->raw_unregister)
ir_raw_handler->raw_unregister(raw->dev);
}
atomic64_andnot(protocols, &available_protocols);
mutex_unlock(&ir_raw_handler_lock);
}
