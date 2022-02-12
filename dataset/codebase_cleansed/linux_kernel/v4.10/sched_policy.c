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
static void try_to_schedule_next_vgpu(struct intel_gvt *gvt)
{
struct intel_gvt_workload_scheduler *scheduler = &gvt->scheduler;
enum intel_engine_id i;
struct intel_engine_cs *engine;
if (!scheduler->next_vgpu)
return;
gvt_dbg_sched("try to schedule next vgpu %d\n",
scheduler->next_vgpu->id);
scheduler->need_reschedule = true;
for_each_engine(engine, gvt->dev_priv, i) {
if (scheduler->current_workload[i]) {
gvt_dbg_sched("still have running workload\n");
return;
}
}
gvt_dbg_sched("switch to next vgpu %d\n",
scheduler->next_vgpu->id);
scheduler->current_vgpu = scheduler->next_vgpu;
scheduler->next_vgpu = NULL;
scheduler->need_reschedule = false;
for_each_engine(engine, gvt->dev_priv, i)
wake_up(&scheduler->waitq[i]);
}
static void tbs_sched_func(struct work_struct *work)
{
struct tbs_sched_data *sched_data = container_of(work,
struct tbs_sched_data, work.work);
struct tbs_vgpu_data *vgpu_data;
struct intel_gvt *gvt = sched_data->gvt;
struct intel_gvt_workload_scheduler *scheduler = &gvt->scheduler;
struct intel_vgpu *vgpu = NULL;
struct list_head *pos, *head;
mutex_lock(&gvt->lock);
if (list_empty(&sched_data->runq_head) || scheduler->next_vgpu)
goto out;
if (scheduler->current_vgpu) {
vgpu_data = scheduler->current_vgpu->sched_data;
head = &vgpu_data->list;
} else {
gvt_dbg_sched("no current vgpu search from q head\n");
head = &sched_data->runq_head;
}
list_for_each(pos, head) {
if (pos == &sched_data->runq_head)
continue;
vgpu_data = container_of(pos, struct tbs_vgpu_data, list);
if (!vgpu_has_pending_workload(vgpu_data->vgpu))
continue;
vgpu = vgpu_data->vgpu;
break;
}
if (vgpu) {
scheduler->next_vgpu = vgpu;
gvt_dbg_sched("pick next vgpu %d\n", vgpu->id);
}
out:
if (scheduler->next_vgpu) {
gvt_dbg_sched("try to schedule next vgpu %d\n",
scheduler->next_vgpu->id);
try_to_schedule_next_vgpu(gvt);
}
if (!list_empty(&sched_data->runq_head) || scheduler->next_vgpu)
schedule_delayed_work(&sched_data->work, sched_data->period);
mutex_unlock(&gvt->lock);
}
static int tbs_sched_init(struct intel_gvt *gvt)
{
struct intel_gvt_workload_scheduler *scheduler =
&gvt->scheduler;
struct tbs_sched_data *data;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
INIT_LIST_HEAD(&data->runq_head);
INIT_DELAYED_WORK(&data->work, tbs_sched_func);
data->period = GVT_DEFAULT_TIME_SLICE;
data->gvt = gvt;
scheduler->sched_data = data;
return 0;
}
static void tbs_sched_clean(struct intel_gvt *gvt)
{
struct intel_gvt_workload_scheduler *scheduler =
&gvt->scheduler;
struct tbs_sched_data *data = scheduler->sched_data;
cancel_delayed_work(&data->work);
kfree(data);
scheduler->sched_data = NULL;
}
static int tbs_sched_init_vgpu(struct intel_vgpu *vgpu)
{
struct tbs_vgpu_data *data;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->vgpu = vgpu;
INIT_LIST_HEAD(&data->list);
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
struct tbs_sched_data *sched_data = vgpu->gvt->scheduler.sched_data;
struct tbs_vgpu_data *vgpu_data = vgpu->sched_data;
if (!list_empty(&vgpu_data->list))
return;
list_add_tail(&vgpu_data->list, &sched_data->runq_head);
schedule_delayed_work(&sched_data->work, sched_data->period);
}
static void tbs_sched_stop_schedule(struct intel_vgpu *vgpu)
{
struct tbs_vgpu_data *vgpu_data = vgpu->sched_data;
list_del_init(&vgpu_data->list);
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
gvt_dbg_core("vgpu%d: stop schedule\n", vgpu->id);
scheduler->sched_ops->stop_schedule(vgpu);
if (scheduler->next_vgpu == vgpu)
scheduler->next_vgpu = NULL;
if (scheduler->current_vgpu == vgpu) {
scheduler->need_reschedule = true;
scheduler->current_vgpu = NULL;
}
}
