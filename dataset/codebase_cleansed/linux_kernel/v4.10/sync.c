void rcu_sync_lockdep_assert(struct rcu_sync *rsp)
{
RCU_LOCKDEP_WARN(!gp_ops[rsp->gp_type].held(),
"suspicious rcu_sync_is_idle() usage");
}
void rcu_sync_init(struct rcu_sync *rsp, enum rcu_sync_type type)
{
memset(rsp, 0, sizeof(*rsp));
init_waitqueue_head(&rsp->gp_wait);
rsp->gp_type = type;
}
void rcu_sync_enter_start(struct rcu_sync *rsp)
{
rsp->gp_count++;
rsp->gp_state = GP_PASSED;
}
void rcu_sync_enter(struct rcu_sync *rsp)
{
bool need_wait, need_sync;
spin_lock_irq(&rsp->rss_lock);
need_wait = rsp->gp_count++;
need_sync = rsp->gp_state == GP_IDLE;
if (need_sync)
rsp->gp_state = GP_PENDING;
spin_unlock_irq(&rsp->rss_lock);
BUG_ON(need_wait && need_sync);
if (need_sync) {
gp_ops[rsp->gp_type].sync();
rsp->gp_state = GP_PASSED;
wake_up_all(&rsp->gp_wait);
} else if (need_wait) {
wait_event(rsp->gp_wait, rsp->gp_state == GP_PASSED);
} else {
BUG_ON(rsp->gp_state != GP_PASSED);
}
}
static void rcu_sync_func(struct rcu_head *rcu)
{
struct rcu_sync *rsp = container_of(rcu, struct rcu_sync, cb_head);
unsigned long flags;
BUG_ON(rsp->gp_state != GP_PASSED);
BUG_ON(rsp->cb_state == CB_IDLE);
spin_lock_irqsave(&rsp->rss_lock, flags);
if (rsp->gp_count) {
rsp->cb_state = CB_IDLE;
} else if (rsp->cb_state == CB_REPLAY) {
rsp->cb_state = CB_PENDING;
gp_ops[rsp->gp_type].call(&rsp->cb_head, rcu_sync_func);
} else {
rsp->cb_state = CB_IDLE;
rsp->gp_state = GP_IDLE;
}
spin_unlock_irqrestore(&rsp->rss_lock, flags);
}
void rcu_sync_exit(struct rcu_sync *rsp)
{
spin_lock_irq(&rsp->rss_lock);
if (!--rsp->gp_count) {
if (rsp->cb_state == CB_IDLE) {
rsp->cb_state = CB_PENDING;
gp_ops[rsp->gp_type].call(&rsp->cb_head, rcu_sync_func);
} else if (rsp->cb_state == CB_PENDING) {
rsp->cb_state = CB_REPLAY;
}
}
spin_unlock_irq(&rsp->rss_lock);
}
void rcu_sync_dtor(struct rcu_sync *rsp)
{
int cb_state;
BUG_ON(rsp->gp_count);
spin_lock_irq(&rsp->rss_lock);
if (rsp->cb_state == CB_REPLAY)
rsp->cb_state = CB_PENDING;
cb_state = rsp->cb_state;
spin_unlock_irq(&rsp->rss_lock);
if (cb_state != CB_IDLE) {
gp_ops[rsp->gp_type].wait();
BUG_ON(rsp->cb_state != CB_IDLE);
}
}
