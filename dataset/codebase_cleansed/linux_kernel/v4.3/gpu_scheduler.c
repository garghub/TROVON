static void amd_sched_rq_init(struct amd_sched_rq *rq)
{
spin_lock_init(&rq->lock);
INIT_LIST_HEAD(&rq->entities);
rq->current_entity = NULL;
}
static void amd_sched_rq_add_entity(struct amd_sched_rq *rq,
struct amd_sched_entity *entity)
{
spin_lock(&rq->lock);
list_add_tail(&entity->list, &rq->entities);
spin_unlock(&rq->lock);
}
static void amd_sched_rq_remove_entity(struct amd_sched_rq *rq,
struct amd_sched_entity *entity)
{
spin_lock(&rq->lock);
list_del_init(&entity->list);
if (rq->current_entity == entity)
rq->current_entity = NULL;
spin_unlock(&rq->lock);
}
static struct amd_sched_job *
amd_sched_rq_select_job(struct amd_sched_rq *rq)
{
struct amd_sched_entity *entity;
struct amd_sched_job *sched_job;
spin_lock(&rq->lock);
entity = rq->current_entity;
if (entity) {
list_for_each_entry_continue(entity, &rq->entities, list) {
sched_job = amd_sched_entity_pop_job(entity);
if (sched_job) {
rq->current_entity = entity;
spin_unlock(&rq->lock);
return sched_job;
}
}
}
list_for_each_entry(entity, &rq->entities, list) {
sched_job = amd_sched_entity_pop_job(entity);
if (sched_job) {
rq->current_entity = entity;
spin_unlock(&rq->lock);
return sched_job;
}
if (entity == rq->current_entity)
break;
}
spin_unlock(&rq->lock);
return NULL;
}
int amd_sched_entity_init(struct amd_gpu_scheduler *sched,
struct amd_sched_entity *entity,
struct amd_sched_rq *rq,
uint32_t jobs)
{
int r;
if (!(sched && entity && rq))
return -EINVAL;
memset(entity, 0, sizeof(struct amd_sched_entity));
INIT_LIST_HEAD(&entity->list);
entity->rq = rq;
entity->sched = sched;
spin_lock_init(&entity->queue_lock);
r = kfifo_alloc(&entity->job_queue, jobs * sizeof(void *), GFP_KERNEL);
if (r)
return r;
atomic_set(&entity->fence_seq, 0);
entity->fence_context = fence_context_alloc(1);
amd_sched_rq_add_entity(rq, entity);
return 0;
}
static bool amd_sched_entity_is_initialized(struct amd_gpu_scheduler *sched,
struct amd_sched_entity *entity)
{
return entity->sched == sched &&
entity->rq != NULL;
}
static bool amd_sched_entity_is_idle(struct amd_sched_entity *entity)
{
rmb();
if (kfifo_is_empty(&entity->job_queue))
return true;
return false;
}
void amd_sched_entity_fini(struct amd_gpu_scheduler *sched,
struct amd_sched_entity *entity)
{
struct amd_sched_rq *rq = entity->rq;
if (!amd_sched_entity_is_initialized(sched, entity))
return;
wait_event(sched->job_scheduled, amd_sched_entity_is_idle(entity));
amd_sched_rq_remove_entity(rq, entity);
kfifo_free(&entity->job_queue);
}
static void amd_sched_entity_wakeup(struct fence *f, struct fence_cb *cb)
{
struct amd_sched_entity *entity =
container_of(cb, struct amd_sched_entity, cb);
entity->dependency = NULL;
fence_put(f);
amd_sched_wakeup(entity->sched);
}
static struct amd_sched_job *
amd_sched_entity_pop_job(struct amd_sched_entity *entity)
{
struct amd_gpu_scheduler *sched = entity->sched;
struct amd_sched_job *sched_job;
if (ACCESS_ONCE(entity->dependency))
return NULL;
if (!kfifo_out_peek(&entity->job_queue, &sched_job, sizeof(sched_job)))
return NULL;
while ((entity->dependency = sched->ops->dependency(sched_job))) {
if (fence_add_callback(entity->dependency, &entity->cb,
amd_sched_entity_wakeup))
fence_put(entity->dependency);
else
return NULL;
}
return sched_job;
}
static bool amd_sched_entity_in(struct amd_sched_job *sched_job)
{
struct amd_sched_entity *entity = sched_job->s_entity;
bool added, first = false;
spin_lock(&entity->queue_lock);
added = kfifo_in(&entity->job_queue, &sched_job,
sizeof(sched_job)) == sizeof(sched_job);
if (added && kfifo_len(&entity->job_queue) == sizeof(sched_job))
first = true;
spin_unlock(&entity->queue_lock);
if (first)
amd_sched_wakeup(sched_job->sched);
return added;
}
int amd_sched_entity_push_job(struct amd_sched_job *sched_job)
{
struct amd_sched_entity *entity = sched_job->s_entity;
struct amd_sched_fence *fence = amd_sched_fence_create(
entity, sched_job->owner);
if (!fence)
return -ENOMEM;
fence_get(&fence->base);
sched_job->s_fence = fence;
wait_event(entity->sched->job_scheduled,
amd_sched_entity_in(sched_job));
trace_amd_sched_job(sched_job);
return 0;
}
static bool amd_sched_ready(struct amd_gpu_scheduler *sched)
{
return atomic_read(&sched->hw_rq_count) <
sched->hw_submission_limit;
}
static void amd_sched_wakeup(struct amd_gpu_scheduler *sched)
{
if (amd_sched_ready(sched))
wake_up_interruptible(&sched->wake_up_worker);
}
static struct amd_sched_job *
amd_sched_select_job(struct amd_gpu_scheduler *sched)
{
struct amd_sched_job *sched_job;
if (!amd_sched_ready(sched))
return NULL;
sched_job = amd_sched_rq_select_job(&sched->kernel_rq);
if (sched_job == NULL)
sched_job = amd_sched_rq_select_job(&sched->sched_rq);
return sched_job;
}
static void amd_sched_process_job(struct fence *f, struct fence_cb *cb)
{
struct amd_sched_fence *s_fence =
container_of(cb, struct amd_sched_fence, cb);
struct amd_gpu_scheduler *sched = s_fence->sched;
atomic_dec(&sched->hw_rq_count);
amd_sched_fence_signal(s_fence);
fence_put(&s_fence->base);
wake_up_interruptible(&sched->wake_up_worker);
}
static int amd_sched_main(void *param)
{
struct sched_param sparam = {.sched_priority = 1};
struct amd_gpu_scheduler *sched = (struct amd_gpu_scheduler *)param;
int r, count;
sched_setscheduler(current, SCHED_FIFO, &sparam);
while (!kthread_should_stop()) {
struct amd_sched_entity *entity;
struct amd_sched_fence *s_fence;
struct amd_sched_job *sched_job;
struct fence *fence;
wait_event_interruptible(sched->wake_up_worker,
kthread_should_stop() ||
(sched_job = amd_sched_select_job(sched)));
if (!sched_job)
continue;
entity = sched_job->s_entity;
s_fence = sched_job->s_fence;
atomic_inc(&sched->hw_rq_count);
fence = sched->ops->run_job(sched_job);
if (fence) {
r = fence_add_callback(fence, &s_fence->cb,
amd_sched_process_job);
if (r == -ENOENT)
amd_sched_process_job(fence, &s_fence->cb);
else if (r)
DRM_ERROR("fence add callback failed (%d)\n", r);
fence_put(fence);
} else {
DRM_ERROR("Failed to run job!\n");
amd_sched_process_job(NULL, &s_fence->cb);
}
count = kfifo_out(&entity->job_queue, &sched_job,
sizeof(sched_job));
WARN_ON(count != sizeof(sched_job));
wake_up(&sched->job_scheduled);
}
return 0;
}
int amd_sched_init(struct amd_gpu_scheduler *sched,
struct amd_sched_backend_ops *ops,
unsigned hw_submission, const char *name)
{
sched->ops = ops;
sched->hw_submission_limit = hw_submission;
sched->name = name;
amd_sched_rq_init(&sched->sched_rq);
amd_sched_rq_init(&sched->kernel_rq);
init_waitqueue_head(&sched->wake_up_worker);
init_waitqueue_head(&sched->job_scheduled);
atomic_set(&sched->hw_rq_count, 0);
sched->thread = kthread_run(amd_sched_main, sched, sched->name);
if (IS_ERR(sched->thread)) {
DRM_ERROR("Failed to create scheduler for %s.\n", name);
return PTR_ERR(sched->thread);
}
return 0;
}
void amd_sched_fini(struct amd_gpu_scheduler *sched)
{
kthread_stop(sched->thread);
}
