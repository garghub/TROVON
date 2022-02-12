static bool vgpu_has_pending_workload(struct intel_vgpu *vgpu)
{
enum intel_engine_id i;
struct intel_engine_cs *engine;
for_each_engine(engine, vgpu->gvt->dev_priv, i) {
if (!list_empty(workload_q_head(vgpu, i)))
return true;
}
return false;
}
static void vgpu_update_timeslice(struct intel_vgpu *pre_vgpu)
{
ktime_t delta_ts;
struct vgpu_sched_data *vgpu_data = pre_vgpu->sched_data;
delta_ts = vgpu_data->sched_out_time - vgpu_data->sched_in_time;
vgpu_data->sched_time += delta_ts;
vgpu_data->left_ts -= delta_ts;
}
static void gvt_balance_timeslice(struct gvt_sched_data *sched_data)
{
struct vgpu_sched_data *vgpu_data;
struct list_head *pos;
static uint64_t stage_check;
int stage = stage_check++ % GVT_TS_BALANCE_STAGE_NUM;
if (stage == 0) {
int total_weight = 0;
ktime_t fair_timeslice;
list_for_each(pos, &sched_data->lru_runq_head) {
vgpu_data = container_of(pos, struct vgpu_sched_data, lru_list);
total_weight += vgpu_data->sched_ctl.weight;
}
list_for_each(pos, &sched_data->lru_runq_head) {
vgpu_data = container_of(pos, struct vgpu_sched_data, lru_list);
fair_timeslice = ms_to_ktime(GVT_TS_BALANCE_PERIOD_MS) *
vgpu_data->sched_ctl.weight /
total_weight;
vgpu_data->allocated_ts = fair_timeslice;
vgpu_data->left_ts = vgpu_data->allocated_ts;
}
} else {
list_for_each(pos, &sched_data->lru_runq_head) {
vgpu_data = container_of(pos, struct vgpu_sched_data, lru_list);
vgpu_data->left_ts += vgpu_data->allocated_ts;
}
}
}
static void try_to_schedule_next_vgpu(struct intel_gvt *gvt)
{
struct intel_gvt_workload_scheduler *scheduler = &gvt->scheduler;
enum intel_engine_id i;
struct intel_engine_cs *engine;
struct vgpu_sched_data *vgpu_data;
ktime_t cur_time;
if (scheduler->next_vgpu == scheduler->current_vgpu) {
scheduler->next_vgpu = NULL;
return;
}
scheduler->need_reschedule = true;
for_each_engine(engine, gvt->dev_priv, i) {
if (scheduler->current_workload[i])
return;
}
cur_time = ktime_get();
if (scheduler->current_vgpu) {
vgpu_data = scheduler->current_vgpu->sched_data;
vgpu_data->sched_out_time = cur_time;
vgpu_update_timeslice(scheduler->current_vgpu);
}
vgpu_data = scheduler->next_vgpu->sched_data;
vgpu_data->sched_in_time = cur_time;
scheduler->current_vgpu = scheduler->next_vgpu;
scheduler->next_vgpu = NULL;
scheduler->need_reschedule = false;
for_each_engine(engine, gvt->dev_priv, i)
wake_up(&scheduler->waitq[i]);
}
static struct intel_vgpu *find_busy_vgpu(struct gvt_sched_data *sched_data)
{
struct vgpu_sched_data *vgpu_data;
struct intel_vgpu *vgpu = NULL;
struct list_head *head = &sched_data->lru_runq_head;
struct list_head *pos;
list_for_each(pos, head) {
vgpu_data = container_of(pos, struct vgpu_sched_data, lru_list);
if (!vgpu_has_pending_workload(vgpu_data->vgpu))
continue;
if (vgpu_data->left_ts > 0) {
vgpu = vgpu_data->vgpu;
break;
}
}
return vgpu;
}
static void tbs_sched_func(struct gvt_sched_data *sched_data)
{
struct intel_gvt *gvt = sched_data->gvt;
struct intel_gvt_workload_scheduler *scheduler = &gvt->scheduler;
struct vgpu_sched_data *vgpu_data;
struct intel_vgpu *vgpu = NULL;
if (list_empty(&sched_data->lru_runq_head) || scheduler->next_vgpu)
goto out;
vgpu = find_busy_vgpu(sched_data);
if (vgpu) {
scheduler->next_vgpu = vgpu;
vgpu_data = vgpu->sched_data;
list_del_init(&vgpu_data->lru_list);
list_add_tail(&vgpu_data->lru_list,
&sched_data->lru_runq_head);
} else {
scheduler->next_vgpu = gvt->idle_vgpu;
}
out:
if (scheduler->next_vgpu)
try_to_schedule_next_vgpu(gvt);
}
void intel_gvt_schedule(struct intel_gvt *gvt)
{
struct gvt_sched_data *sched_data = gvt->scheduler.sched_data;
static uint64_t timer_check;
mutex_lock(&gvt->lock);
if (test_and_clear_bit(INTEL_GVT_REQUEST_SCHED,
(void *)&gvt->service_request)) {
if (!(timer_check++ % GVT_TS_BALANCE_PERIOD_MS))
gvt_balance_timeslice(sched_data);
}
clear_bit(INTEL_GVT_REQUEST_EVENT_SCHED, (void *)&gvt->service_request);
tbs_sched_func(sched_data);
mutex_unlock(&gvt->lock);
}
static enum hrtimer_restart tbs_timer_fn(struct hrtimer *timer_data)
{
struct gvt_sched_data *data;
data = container_of(timer_data, struct gvt_sched_data, timer);
intel_gvt_request_service(data->gvt, INTEL_GVT_REQUEST_SCHED);
hrtimer_add_expires_ns(&data->timer, data->period);
return HRTIMER_RESTART;
}
static int tbs_sched_init(struct intel_gvt *gvt)
{
struct intel_gvt_workload_scheduler *scheduler =
&gvt->scheduler;
struct gvt_sched_data *data;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
INIT_LIST_HEAD(&data->lru_runq_head);
hrtimer_init(&data->timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
data->timer.function = tbs_timer_fn;
data->period = GVT_DEFAULT_TIME_SLICE;
data->gvt = gvt;
scheduler->sched_data = data;
return 0;
}
static void tbs_sched_clean(struct intel_gvt *gvt)
{
struct intel_gvt_workload_scheduler *scheduler =
&gvt->scheduler;
struct gvt_sched_data *data = scheduler->sched_data;
hrtimer_cancel(&data->timer);
kfree(data);
scheduler->sched_data = NULL;
}
static int tbs_sched_init_vgpu(struct intel_vgpu *vgpu)
{
struct vgpu_sched_data *data;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->sched_ctl.weight = vgpu->sched_ctl.weight;
data->vgpu = vgpu;
INIT_LIST_HEAD(&data->lru_list);
vgpu->sched_data = data;
return 0;
}
static void tbs_sched_clean_vgpu(struct intel_vgpu *vgpu)
{
kfree(vgpu->sched_data);
vgpu->sched_data = NULL;
}
static void tbs_sched_start_schedule(struct intel_vgpu *vgpu)
{
struct gvt_sched_data *sched_data = vgpu->gvt->scheduler.sched_data;
struct vgpu_sched_data *vgpu_data = vgpu->sched_data;
if (!list_empty(&vgpu_data->lru_list))
return;
list_add_tail(&vgpu_data->lru_list, &sched_data->lru_runq_head);
if (!hrtimer_active(&sched_data->timer))
hrtimer_start(&sched_data->timer, ktime_add_ns(ktime_get(),
sched_data->period), HRTIMER_MODE_ABS);
}
static void tbs_sched_stop_schedule(struct intel_vgpu *vgpu)
{
struct vgpu_sched_data *vgpu_data = vgpu->sched_data;
list_del_init(&vgpu_data->lru_list);
}
int intel_gvt_init_sched_policy(struct intel_gvt *gvt)
{
gvt->scheduler.sched_ops = &tbs_schedule_ops;
return gvt->scheduler.sched_ops->init(gvt);
}
void intel_gvt_clean_sched_policy(struct intel_gvt *gvt)
{
gvt->scheduler.sched_ops->clean(gvt);
}
int intel_vgpu_init_sched_policy(struct intel_vgpu *vgpu)
{
return vgpu->gvt->scheduler.sched_ops->init_vgpu(vgpu);
}
void intel_vgpu_clean_sched_policy(struct intel_vgpu *vgpu)
{
vgpu->gvt->scheduler.sched_ops->clean_vgpu(vgpu);
}
void intel_vgpu_start_schedule(struct intel_vgpu *vgpu)
{
gvt_dbg_core("vgpu%d: start schedule\n", vgpu->id);
vgpu->gvt->scheduler.sched_ops->start_schedule(vgpu);
}
void intel_vgpu_stop_schedule(struct intel_vgpu *vgpu)
{
struct intel_gvt_workload_scheduler *scheduler =
&vgpu->gvt->scheduler;
int ring_id;
gvt_dbg_core("vgpu%d: stop schedule\n", vgpu->id);
scheduler->sched_ops->stop_schedule(vgpu);
if (scheduler->next_vgpu == vgpu)
scheduler->next_vgpu = NULL;
if (scheduler->current_vgpu == vgpu) {
scheduler->need_reschedule = true;
scheduler->current_vgpu = NULL;
}
spin_lock_bh(&scheduler->mmio_context_lock);
for (ring_id = 0; ring_id < I915_NUM_ENGINES; ring_id++) {
if (scheduler->engine_owner[ring_id] == vgpu) {
intel_gvt_switch_mmio(vgpu, NULL, ring_id);
scheduler->engine_owner[ring_id] = NULL;
}
}
spin_unlock_bh(&scheduler->mmio_context_lock);
}
