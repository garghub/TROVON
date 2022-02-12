static inline void fscache_done_parent_op(struct fscache_object *object)
{
struct fscache_object *parent = object->parent;
_enter("OBJ%x {OBJ%x,%x}",
object->debug_id, parent->debug_id, parent->n_ops);
spin_lock_nested(&parent->lock, 1);
parent->n_obj_ops--;
parent->n_ops--;
if (parent->n_ops == 0)
fscache_raise_event(parent, FSCACHE_OBJECT_EV_CLEARED);
spin_unlock(&parent->lock);
}
static void fscache_object_sm_dispatcher(struct fscache_object *object)
{
const struct fscache_transition *t;
const struct fscache_state *state, *new_state;
unsigned long events, event_mask;
int event = -1;
ASSERT(object != NULL);
_enter("{OBJ%x,%s,%lx}",
object->debug_id, object->state->name, object->events);
event_mask = object->event_mask;
restart:
object->event_mask = 0;
state = object->state;
restart_masked:
events = object->events;
if (events & object->oob_event_mask) {
_debug("{OBJ%x} oob %lx",
object->debug_id, events & object->oob_event_mask);
for (t = object->oob_table; t->events; t++) {
if (events & t->events) {
state = t->transit_to;
ASSERT(state->work != NULL);
event = fls(events & t->events) - 1;
__clear_bit(event, &object->oob_event_mask);
clear_bit(event, &object->events);
goto execute_work_state;
}
}
}
if (!state->work) {
if (events & event_mask) {
for (t = state->transitions; t->events; t++) {
if (events & t->events) {
new_state = t->transit_to;
event = fls(events & t->events) - 1;
clear_bit(event, &object->events);
_debug("{OBJ%x} ev %d: %s -> %s",
object->debug_id, event,
state->name, new_state->name);
object->state = state = new_state;
goto execute_work_state;
}
}
BUG();
}
goto unmask_events;
}
execute_work_state:
_debug("{OBJ%x} exec %s", object->debug_id, state->name);
new_state = state->work(object, event);
event = -1;
if (new_state == NO_TRANSIT) {
_debug("{OBJ%x} %s notrans", object->debug_id, state->name);
fscache_enqueue_object(object);
event_mask = object->oob_event_mask;
goto unmask_events;
}
_debug("{OBJ%x} %s -> %s",
object->debug_id, state->name, new_state->name);
object->state = state = new_state;
if (state->work) {
if (unlikely(state->work == ((void *)2UL))) {
_leave(" [dead]");
return;
}
goto restart_masked;
}
event_mask = object->oob_event_mask;
for (t = state->transitions; t->events; t++)
event_mask |= t->events;
unmask_events:
object->event_mask = event_mask;
smp_mb();
events = object->events;
if (events & event_mask)
goto restart;
_leave(" [msk %lx]", event_mask);
}
static void fscache_object_work_func(struct work_struct *work)
{
struct fscache_object *object =
container_of(work, struct fscache_object, work);
unsigned long start;
_enter("{OBJ%x}", object->debug_id);
start = jiffies;
fscache_object_sm_dispatcher(object);
fscache_hist(fscache_objs_histogram, start);
fscache_put_object(object);
}
void fscache_object_init(struct fscache_object *object,
struct fscache_cookie *cookie,
struct fscache_cache *cache)
{
const struct fscache_transition *t;
atomic_inc(&cache->object_count);
object->state = STATE(WAIT_FOR_INIT);
object->oob_table = fscache_osm_init_oob;
object->flags = 1 << FSCACHE_OBJECT_IS_LIVE;
spin_lock_init(&object->lock);
INIT_LIST_HEAD(&object->cache_link);
INIT_HLIST_NODE(&object->cookie_link);
INIT_WORK(&object->work, fscache_object_work_func);
INIT_LIST_HEAD(&object->dependents);
INIT_LIST_HEAD(&object->dep_link);
INIT_LIST_HEAD(&object->pending_ops);
object->n_children = 0;
object->n_ops = object->n_in_progress = object->n_exclusive = 0;
object->events = 0;
object->store_limit = 0;
object->store_limit_l = 0;
object->cache = cache;
object->cookie = cookie;
object->parent = NULL;
#ifdef CONFIG_FSCACHE_OBJECT_LIST
RB_CLEAR_NODE(&object->objlist_link);
#endif
object->oob_event_mask = 0;
for (t = object->oob_table; t->events; t++)
object->oob_event_mask |= t->events;
object->event_mask = object->oob_event_mask;
for (t = object->state->transitions; t->events; t++)
object->event_mask |= t->events;
}
static const struct fscache_state *fscache_abort_initialisation(struct fscache_object *object,
int event)
{
_enter("{OBJ%x},%d", object->debug_id, event);
object->oob_event_mask = 0;
fscache_dequeue_object(object);
return transit_to(KILL_OBJECT);
}
static const struct fscache_state *fscache_initialise_object(struct fscache_object *object,
int event)
{
struct fscache_object *parent;
bool success;
_enter("{OBJ%x},%d", object->debug_id, event);
ASSERT(list_empty(&object->dep_link));
parent = object->parent;
if (!parent) {
_leave(" [no parent]");
return transit_to(DROP_OBJECT);
}
_debug("parent: %s of:%lx", parent->state->name, parent->flags);
if (fscache_object_is_dying(parent)) {
_leave(" [bad parent]");
return transit_to(DROP_OBJECT);
}
if (fscache_object_is_available(parent)) {
_leave(" [ready]");
return transit_to(PARENT_READY);
}
_debug("wait");
spin_lock(&parent->lock);
fscache_stat(&fscache_n_cop_grab_object);
success = false;
if (fscache_object_is_live(parent) &&
object->cache->ops->grab_object(object)) {
list_add(&object->dep_link, &parent->dependents);
success = true;
}
fscache_stat_d(&fscache_n_cop_grab_object);
spin_unlock(&parent->lock);
if (!success) {
_leave(" [grab failed]");
return transit_to(DROP_OBJECT);
}
fscache_raise_event(parent, FSCACHE_OBJECT_EV_NEW_CHILD);
_leave(" [wait]");
return transit_to(WAIT_FOR_PARENT);
}
static const struct fscache_state *fscache_parent_ready(struct fscache_object *object,
int event)
{
struct fscache_object *parent = object->parent;
_enter("{OBJ%x},%d", object->debug_id, event);
ASSERT(parent != NULL);
spin_lock(&parent->lock);
parent->n_ops++;
parent->n_obj_ops++;
object->lookup_jif = jiffies;
spin_unlock(&parent->lock);
_leave("");
return transit_to(LOOK_UP_OBJECT);
}
static const struct fscache_state *fscache_look_up_object(struct fscache_object *object,
int event)
{
struct fscache_cookie *cookie = object->cookie;
struct fscache_object *parent = object->parent;
int ret;
_enter("{OBJ%x},%d", object->debug_id, event);
object->oob_table = fscache_osm_lookup_oob;
ASSERT(parent != NULL);
ASSERTCMP(parent->n_ops, >, 0);
ASSERTCMP(parent->n_obj_ops, >, 0);
ASSERT(fscache_object_is_available(parent));
if (fscache_object_is_dying(parent) ||
test_bit(FSCACHE_IOERROR, &object->cache->flags) ||
!fscache_use_cookie(object)) {
_leave(" [unavailable]");
return transit_to(LOOKUP_FAILURE);
}
_debug("LOOKUP \"%s\" in \"%s\"",
cookie->def->name, object->cache->tag->name);
fscache_stat(&fscache_n_object_lookups);
fscache_stat(&fscache_n_cop_lookup_object);
ret = object->cache->ops->lookup_object(object);
fscache_stat_d(&fscache_n_cop_lookup_object);
fscache_unuse_cookie(object);
if (ret == -ETIMEDOUT) {
fscache_stat(&fscache_n_object_lookups_timed_out);
_leave(" [timeout]");
return NO_TRANSIT;
}
if (ret < 0) {
_leave(" [error]");
return transit_to(LOOKUP_FAILURE);
}
_leave(" [ok]");
return transit_to(OBJECT_AVAILABLE);
}
void fscache_object_lookup_negative(struct fscache_object *object)
{
struct fscache_cookie *cookie = object->cookie;
_enter("{OBJ%x,%s}", object->debug_id, object->state->name);
if (!test_and_set_bit(FSCACHE_OBJECT_IS_LOOKED_UP, &object->flags)) {
fscache_stat(&fscache_n_object_lookups_negative);
set_bit(FSCACHE_COOKIE_NO_DATA_YET, &cookie->flags);
clear_bit(FSCACHE_COOKIE_UNAVAILABLE, &cookie->flags);
_debug("wake up lookup %p", &cookie->flags);
clear_bit_unlock(FSCACHE_COOKIE_LOOKING_UP, &cookie->flags);
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_LOOKING_UP);
}
_leave("");
}
void fscache_obtained_object(struct fscache_object *object)
{
struct fscache_cookie *cookie = object->cookie;
_enter("{OBJ%x,%s}", object->debug_id, object->state->name);
if (!test_and_set_bit(FSCACHE_OBJECT_IS_LOOKED_UP, &object->flags)) {
fscache_stat(&fscache_n_object_lookups_positive);
clear_bit_unlock(FSCACHE_COOKIE_NO_DATA_YET, &cookie->flags);
clear_bit(FSCACHE_COOKIE_UNAVAILABLE, &cookie->flags);
clear_bit_unlock(FSCACHE_COOKIE_LOOKING_UP, &cookie->flags);
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_LOOKING_UP);
} else {
fscache_stat(&fscache_n_object_created);
}
set_bit(FSCACHE_OBJECT_IS_AVAILABLE, &object->flags);
_leave("");
}
static const struct fscache_state *fscache_object_available(struct fscache_object *object,
int event)
{
_enter("{OBJ%x},%d", object->debug_id, event);
object->oob_table = fscache_osm_run_oob;
spin_lock(&object->lock);
fscache_done_parent_op(object);
if (object->n_in_progress == 0) {
if (object->n_ops > 0) {
ASSERTCMP(object->n_ops, >=, object->n_obj_ops);
fscache_start_operations(object);
} else {
ASSERT(list_empty(&object->pending_ops));
}
}
spin_unlock(&object->lock);
fscache_stat(&fscache_n_cop_lookup_complete);
object->cache->ops->lookup_complete(object);
fscache_stat_d(&fscache_n_cop_lookup_complete);
fscache_hist(fscache_obj_instantiate_histogram, object->lookup_jif);
fscache_stat(&fscache_n_object_avail);
_leave("");
return transit_to(JUMPSTART_DEPS);
}
static const struct fscache_state *fscache_jumpstart_dependents(struct fscache_object *object,
int event)
{
_enter("{OBJ%x},%d", object->debug_id, event);
if (!fscache_enqueue_dependents(object, FSCACHE_OBJECT_EV_PARENT_READY))
return NO_TRANSIT;
return transit_to(WAIT_FOR_CMD);
}
static const struct fscache_state *fscache_lookup_failure(struct fscache_object *object,
int event)
{
struct fscache_cookie *cookie;
_enter("{OBJ%x},%d", object->debug_id, event);
object->oob_event_mask = 0;
fscache_stat(&fscache_n_cop_lookup_complete);
object->cache->ops->lookup_complete(object);
fscache_stat_d(&fscache_n_cop_lookup_complete);
cookie = object->cookie;
set_bit(FSCACHE_COOKIE_UNAVAILABLE, &cookie->flags);
if (test_and_clear_bit(FSCACHE_COOKIE_LOOKING_UP, &cookie->flags))
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_LOOKING_UP);
fscache_done_parent_op(object);
return transit_to(KILL_OBJECT);
}
static const struct fscache_state *fscache_kill_object(struct fscache_object *object,
int event)
{
_enter("{OBJ%x,%d,%d},%d",
object->debug_id, object->n_ops, object->n_children, event);
clear_bit(FSCACHE_OBJECT_IS_LIVE, &object->flags);
object->oob_event_mask = 0;
if (list_empty(&object->dependents) &&
object->n_ops == 0 &&
object->n_children == 0)
return transit_to(DROP_OBJECT);
if (object->n_in_progress == 0) {
spin_lock(&object->lock);
if (object->n_ops > 0 && object->n_in_progress == 0)
fscache_start_operations(object);
spin_unlock(&object->lock);
}
if (!list_empty(&object->dependents))
return transit_to(KILL_DEPENDENTS);
return transit_to(WAIT_FOR_CLEARANCE);
}
static const struct fscache_state *fscache_kill_dependents(struct fscache_object *object,
int event)
{
_enter("{OBJ%x},%d", object->debug_id, event);
if (!fscache_enqueue_dependents(object, FSCACHE_OBJECT_EV_KILL))
return NO_TRANSIT;
return transit_to(WAIT_FOR_CLEARANCE);
}
static const struct fscache_state *fscache_drop_object(struct fscache_object *object,
int event)
{
struct fscache_object *parent = object->parent;
struct fscache_cookie *cookie = object->cookie;
struct fscache_cache *cache = object->cache;
bool awaken = false;
_enter("{OBJ%x,%d},%d", object->debug_id, object->n_children, event);
ASSERT(cookie != NULL);
ASSERT(!hlist_unhashed(&object->cookie_link));
spin_lock(&cookie->lock);
hlist_del_init(&object->cookie_link);
if (hlist_empty(&cookie->backing_objects) &&
test_and_clear_bit(FSCACHE_COOKIE_INVALIDATING, &cookie->flags))
awaken = true;
spin_unlock(&cookie->lock);
if (awaken)
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_INVALIDATING);
spin_lock(&object->lock);
spin_unlock(&object->lock);
spin_lock(&cache->object_list_lock);
list_del_init(&object->cache_link);
spin_unlock(&cache->object_list_lock);
fscache_stat(&fscache_n_cop_drop_object);
cache->ops->drop_object(object);
fscache_stat_d(&fscache_n_cop_drop_object);
if (parent) {
_debug("release parent OBJ%x {%d}",
parent->debug_id, parent->n_children);
spin_lock(&parent->lock);
parent->n_children--;
if (parent->n_children == 0)
fscache_raise_event(parent, FSCACHE_OBJECT_EV_CLEARED);
spin_unlock(&parent->lock);
object->parent = NULL;
}
fscache_put_object(object);
fscache_stat(&fscache_n_object_dead);
_leave("");
return transit_to(OBJECT_DEAD);
}
static int fscache_get_object(struct fscache_object *object)
{
int ret;
fscache_stat(&fscache_n_cop_grab_object);
ret = object->cache->ops->grab_object(object) ? 0 : -EAGAIN;
fscache_stat_d(&fscache_n_cop_grab_object);
return ret;
}
static void fscache_put_object(struct fscache_object *object)
{
fscache_stat(&fscache_n_cop_put_object);
object->cache->ops->put_object(object);
fscache_stat_d(&fscache_n_cop_put_object);
}
void fscache_object_destroy(struct fscache_object *object)
{
fscache_objlist_remove(object);
fscache_cookie_put(object->cookie);
object->cookie = NULL;
}
void fscache_enqueue_object(struct fscache_object *object)
{
_enter("{OBJ%x}", object->debug_id);
if (fscache_get_object(object) >= 0) {
wait_queue_head_t *cong_wq =
&get_cpu_var(fscache_object_cong_wait);
if (queue_work(fscache_object_wq, &object->work)) {
if (fscache_object_congested())
wake_up(cong_wq);
} else
fscache_put_object(object);
put_cpu_var(fscache_object_cong_wait);
}
}
bool fscache_object_sleep_till_congested(signed long *timeoutp)
{
wait_queue_head_t *cong_wq = this_cpu_ptr(&fscache_object_cong_wait);
DEFINE_WAIT(wait);
if (fscache_object_congested())
return true;
add_wait_queue_exclusive(cong_wq, &wait);
if (!fscache_object_congested())
*timeoutp = schedule_timeout(*timeoutp);
finish_wait(cong_wq, &wait);
return fscache_object_congested();
}
static bool fscache_enqueue_dependents(struct fscache_object *object, int event)
{
struct fscache_object *dep;
bool ret = true;
_enter("{OBJ%x}", object->debug_id);
if (list_empty(&object->dependents))
return true;
spin_lock(&object->lock);
while (!list_empty(&object->dependents)) {
dep = list_entry(object->dependents.next,
struct fscache_object, dep_link);
list_del_init(&dep->dep_link);
fscache_raise_event(dep, event);
fscache_put_object(dep);
if (!list_empty(&object->dependents) && need_resched()) {
ret = false;
break;
}
}
spin_unlock(&object->lock);
return ret;
}
static void fscache_dequeue_object(struct fscache_object *object)
{
_enter("{OBJ%x}", object->debug_id);
if (!list_empty(&object->dep_link)) {
spin_lock(&object->parent->lock);
list_del_init(&object->dep_link);
spin_unlock(&object->parent->lock);
}
_leave("");
}
enum fscache_checkaux fscache_check_aux(struct fscache_object *object,
const void *data, uint16_t datalen)
{
enum fscache_checkaux result;
if (!object->cookie->def->check_aux) {
fscache_stat(&fscache_n_checkaux_none);
return FSCACHE_CHECKAUX_OKAY;
}
result = object->cookie->def->check_aux(object->cookie->netfs_data,
data, datalen);
switch (result) {
case FSCACHE_CHECKAUX_OKAY:
fscache_stat(&fscache_n_checkaux_okay);
break;
case FSCACHE_CHECKAUX_NEEDS_UPDATE:
fscache_stat(&fscache_n_checkaux_update);
break;
case FSCACHE_CHECKAUX_OBSOLETE:
fscache_stat(&fscache_n_checkaux_obsolete);
break;
default:
BUG();
}
return result;
}
static const struct fscache_state *_fscache_invalidate_object(struct fscache_object *object,
int event)
{
struct fscache_operation *op;
struct fscache_cookie *cookie = object->cookie;
_enter("{OBJ%x},%d", object->debug_id, event);
if (!fscache_use_cookie(object)) {
ASSERT(object->cookie->stores.rnode == NULL);
set_bit(FSCACHE_OBJECT_RETIRED, &object->flags);
_leave(" [no cookie]");
return transit_to(KILL_OBJECT);
}
fscache_invalidate_writes(cookie);
clear_bit(FSCACHE_OBJECT_PENDING_WRITE, &object->flags);
fscache_cancel_all_ops(object);
op = kzalloc(sizeof(*op), GFP_KERNEL);
if (!op)
goto nomem;
fscache_operation_init(op, object->cache->ops->invalidate_object, NULL);
op->flags = FSCACHE_OP_ASYNC |
(1 << FSCACHE_OP_EXCLUSIVE) |
(1 << FSCACHE_OP_UNUSE_COOKIE);
spin_lock(&cookie->lock);
if (fscache_submit_exclusive_op(object, op) < 0)
goto submit_op_failed;
spin_unlock(&cookie->lock);
fscache_put_operation(op);
set_bit(FSCACHE_COOKIE_NO_DATA_YET, &cookie->flags);
if (test_and_clear_bit(FSCACHE_COOKIE_INVALIDATING, &cookie->flags))
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_INVALIDATING);
_leave(" [ok]");
return transit_to(UPDATE_OBJECT);
nomem:
clear_bit(FSCACHE_OBJECT_IS_LIVE, &object->flags);
fscache_unuse_cookie(object);
_leave(" [ENOMEM]");
return transit_to(KILL_OBJECT);
submit_op_failed:
clear_bit(FSCACHE_OBJECT_IS_LIVE, &object->flags);
spin_unlock(&cookie->lock);
kfree(op);
_leave(" [EIO]");
return transit_to(KILL_OBJECT);
}
static const struct fscache_state *fscache_invalidate_object(struct fscache_object *object,
int event)
{
const struct fscache_state *s;
fscache_stat(&fscache_n_invalidates_run);
fscache_stat(&fscache_n_cop_invalidate_object);
s = _fscache_invalidate_object(object, event);
fscache_stat_d(&fscache_n_cop_invalidate_object);
return s;
}
static const struct fscache_state *fscache_update_object(struct fscache_object *object,
int event)
{
_enter("{OBJ%x},%d", object->debug_id, event);
fscache_stat(&fscache_n_updates_run);
fscache_stat(&fscache_n_cop_update_object);
object->cache->ops->update_object(object);
fscache_stat_d(&fscache_n_cop_update_object);
_leave("");
return transit_to(WAIT_FOR_CMD);
}
