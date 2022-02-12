void fscache_cookie_init_once(void *_cookie)
{
struct fscache_cookie *cookie = _cookie;
memset(cookie, 0, sizeof(*cookie));
spin_lock_init(&cookie->lock);
spin_lock_init(&cookie->stores_lock);
INIT_HLIST_HEAD(&cookie->backing_objects);
}
struct fscache_cookie *__fscache_acquire_cookie(
struct fscache_cookie *parent,
const struct fscache_cookie_def *def,
void *netfs_data,
bool enable)
{
struct fscache_cookie *cookie;
BUG_ON(!def);
_enter("{%s},{%s},%p,%u",
parent ? (char *) parent->def->name : "<no-parent>",
def->name, netfs_data, enable);
fscache_stat(&fscache_n_acquires);
if (!parent) {
fscache_stat(&fscache_n_acquires_null);
_leave(" [no parent]");
return NULL;
}
BUG_ON(!def->get_key);
BUG_ON(!def->name[0]);
BUG_ON(def->type == FSCACHE_COOKIE_TYPE_INDEX &&
parent->def->type != FSCACHE_COOKIE_TYPE_INDEX);
cookie = kmem_cache_alloc(fscache_cookie_jar, GFP_KERNEL);
if (!cookie) {
fscache_stat(&fscache_n_acquires_oom);
_leave(" [ENOMEM]");
return NULL;
}
atomic_set(&cookie->usage, 1);
atomic_set(&cookie->n_children, 0);
atomic_set(&cookie->n_active, 1);
atomic_inc(&parent->usage);
atomic_inc(&parent->n_children);
cookie->def = def;
cookie->parent = parent;
cookie->netfs_data = netfs_data;
cookie->flags = (1 << FSCACHE_COOKIE_NO_DATA_YET);
INIT_RADIX_TREE(&cookie->stores, GFP_NOFS & ~__GFP_WAIT);
switch (cookie->def->type) {
case FSCACHE_COOKIE_TYPE_INDEX:
fscache_stat(&fscache_n_cookie_index);
break;
case FSCACHE_COOKIE_TYPE_DATAFILE:
fscache_stat(&fscache_n_cookie_data);
break;
default:
fscache_stat(&fscache_n_cookie_special);
break;
}
if (enable) {
if (cookie->def->type != FSCACHE_COOKIE_TYPE_INDEX) {
if (fscache_acquire_non_index_cookie(cookie) == 0) {
set_bit(FSCACHE_COOKIE_ENABLED, &cookie->flags);
} else {
atomic_dec(&parent->n_children);
__fscache_cookie_put(cookie);
fscache_stat(&fscache_n_acquires_nobufs);
_leave(" = NULL");
return NULL;
}
} else {
set_bit(FSCACHE_COOKIE_ENABLED, &cookie->flags);
}
}
fscache_stat(&fscache_n_acquires_ok);
_leave(" = %p", cookie);
return cookie;
}
void __fscache_enable_cookie(struct fscache_cookie *cookie,
bool (*can_enable)(void *data),
void *data)
{
_enter("%p", cookie);
wait_on_bit_lock(&cookie->flags, FSCACHE_COOKIE_ENABLEMENT_LOCK,
TASK_UNINTERRUPTIBLE);
if (test_bit(FSCACHE_COOKIE_ENABLED, &cookie->flags))
goto out_unlock;
if (can_enable && !can_enable(data)) {
} else if (cookie->def->type != FSCACHE_COOKIE_TYPE_INDEX) {
__fscache_wait_on_invalidate(cookie);
if (fscache_acquire_non_index_cookie(cookie) == 0)
set_bit(FSCACHE_COOKIE_ENABLED, &cookie->flags);
} else {
set_bit(FSCACHE_COOKIE_ENABLED, &cookie->flags);
}
out_unlock:
clear_bit_unlock(FSCACHE_COOKIE_ENABLEMENT_LOCK, &cookie->flags);
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_ENABLEMENT_LOCK);
}
static int fscache_acquire_non_index_cookie(struct fscache_cookie *cookie)
{
struct fscache_object *object;
struct fscache_cache *cache;
uint64_t i_size;
int ret;
_enter("");
set_bit(FSCACHE_COOKIE_UNAVAILABLE, &cookie->flags);
down_read(&fscache_addremove_sem);
if (list_empty(&fscache_cache_list)) {
up_read(&fscache_addremove_sem);
_leave(" = 0 [no caches]");
return 0;
}
cache = fscache_select_cache_for_object(cookie->parent);
if (!cache) {
up_read(&fscache_addremove_sem);
fscache_stat(&fscache_n_acquires_no_cache);
_leave(" = -ENOMEDIUM [no cache]");
return -ENOMEDIUM;
}
_debug("cache %s", cache->tag->name);
set_bit(FSCACHE_COOKIE_LOOKING_UP, &cookie->flags);
ret = fscache_alloc_object(cache, cookie);
if (ret < 0) {
up_read(&fscache_addremove_sem);
_leave(" = %d", ret);
return ret;
}
cookie->def->get_attr(cookie->netfs_data, &i_size);
spin_lock(&cookie->lock);
if (hlist_empty(&cookie->backing_objects)) {
spin_unlock(&cookie->lock);
goto unavailable;
}
object = hlist_entry(cookie->backing_objects.first,
struct fscache_object, cookie_link);
fscache_set_store_limit(object, i_size);
fscache_raise_event(object, FSCACHE_OBJECT_EV_NEW_CHILD);
spin_unlock(&cookie->lock);
if (!fscache_defer_lookup) {
_debug("non-deferred lookup %p", &cookie->flags);
wait_on_bit(&cookie->flags, FSCACHE_COOKIE_LOOKING_UP,
TASK_UNINTERRUPTIBLE);
_debug("complete");
if (test_bit(FSCACHE_COOKIE_UNAVAILABLE, &cookie->flags))
goto unavailable;
}
up_read(&fscache_addremove_sem);
_leave(" = 0 [deferred]");
return 0;
unavailable:
up_read(&fscache_addremove_sem);
_leave(" = -ENOBUFS");
return -ENOBUFS;
}
static int fscache_alloc_object(struct fscache_cache *cache,
struct fscache_cookie *cookie)
{
struct fscache_object *object;
int ret;
_enter("%p,%p{%s}", cache, cookie, cookie->def->name);
spin_lock(&cookie->lock);
hlist_for_each_entry(object, &cookie->backing_objects,
cookie_link) {
if (object->cache == cache)
goto object_already_extant;
}
spin_unlock(&cookie->lock);
fscache_stat(&fscache_n_cop_alloc_object);
object = cache->ops->alloc_object(cache, cookie);
fscache_stat_d(&fscache_n_cop_alloc_object);
if (IS_ERR(object)) {
fscache_stat(&fscache_n_object_no_alloc);
ret = PTR_ERR(object);
goto error;
}
fscache_stat(&fscache_n_object_alloc);
object->debug_id = atomic_inc_return(&fscache_object_debug_id);
_debug("ALLOC OBJ%x: %s {%lx}",
object->debug_id, cookie->def->name, object->events);
ret = fscache_alloc_object(cache, cookie->parent);
if (ret < 0)
goto error_put;
if (fscache_attach_object(cookie, object) < 0) {
fscache_stat(&fscache_n_cop_put_object);
cache->ops->put_object(object);
fscache_stat_d(&fscache_n_cop_put_object);
}
_leave(" = 0");
return 0;
object_already_extant:
ret = -ENOBUFS;
if (fscache_object_is_dead(object)) {
spin_unlock(&cookie->lock);
goto error;
}
spin_unlock(&cookie->lock);
_leave(" = 0 [found]");
return 0;
error_put:
fscache_stat(&fscache_n_cop_put_object);
cache->ops->put_object(object);
fscache_stat_d(&fscache_n_cop_put_object);
error:
_leave(" = %d", ret);
return ret;
}
static int fscache_attach_object(struct fscache_cookie *cookie,
struct fscache_object *object)
{
struct fscache_object *p;
struct fscache_cache *cache = object->cache;
int ret;
_enter("{%s},{OBJ%x}", cookie->def->name, object->debug_id);
spin_lock(&cookie->lock);
ret = -EEXIST;
hlist_for_each_entry(p, &cookie->backing_objects, cookie_link) {
if (p->cache == object->cache) {
if (fscache_object_is_dying(p))
ret = -ENOBUFS;
goto cant_attach_object;
}
}
spin_lock_nested(&cookie->parent->lock, 1);
hlist_for_each_entry(p, &cookie->parent->backing_objects,
cookie_link) {
if (p->cache == object->cache) {
if (fscache_object_is_dying(p)) {
ret = -ENOBUFS;
spin_unlock(&cookie->parent->lock);
goto cant_attach_object;
}
object->parent = p;
spin_lock(&p->lock);
p->n_children++;
spin_unlock(&p->lock);
break;
}
}
spin_unlock(&cookie->parent->lock);
if (list_empty(&object->cache_link)) {
spin_lock(&cache->object_list_lock);
list_add(&object->cache_link, &cache->object_list);
spin_unlock(&cache->object_list_lock);
}
object->cookie = cookie;
atomic_inc(&cookie->usage);
hlist_add_head(&object->cookie_link, &cookie->backing_objects);
fscache_objlist_add(object);
ret = 0;
cant_attach_object:
spin_unlock(&cookie->lock);
_leave(" = %d", ret);
return ret;
}
void __fscache_invalidate(struct fscache_cookie *cookie)
{
struct fscache_object *object;
_enter("{%s}", cookie->def->name);
fscache_stat(&fscache_n_invalidates);
ASSERTCMP(cookie->def->type, ==, FSCACHE_COOKIE_TYPE_DATAFILE);
BUG_ON(!cookie->def->get_aux);
if (!hlist_empty(&cookie->backing_objects)) {
spin_lock(&cookie->lock);
if (fscache_cookie_enabled(cookie) &&
!hlist_empty(&cookie->backing_objects) &&
!test_and_set_bit(FSCACHE_COOKIE_INVALIDATING,
&cookie->flags)) {
object = hlist_entry(cookie->backing_objects.first,
struct fscache_object,
cookie_link);
if (fscache_object_is_live(object))
fscache_raise_event(
object, FSCACHE_OBJECT_EV_INVALIDATE);
}
spin_unlock(&cookie->lock);
}
_leave("");
}
void __fscache_wait_on_invalidate(struct fscache_cookie *cookie)
{
_enter("%p", cookie);
wait_on_bit(&cookie->flags, FSCACHE_COOKIE_INVALIDATING,
TASK_UNINTERRUPTIBLE);
_leave("");
}
void __fscache_update_cookie(struct fscache_cookie *cookie)
{
struct fscache_object *object;
fscache_stat(&fscache_n_updates);
if (!cookie) {
fscache_stat(&fscache_n_updates_null);
_leave(" [no cookie]");
return;
}
_enter("{%s}", cookie->def->name);
BUG_ON(!cookie->def->get_aux);
spin_lock(&cookie->lock);
if (fscache_cookie_enabled(cookie)) {
hlist_for_each_entry(object,
&cookie->backing_objects, cookie_link) {
fscache_raise_event(object, FSCACHE_OBJECT_EV_UPDATE);
}
}
spin_unlock(&cookie->lock);
_leave("");
}
void __fscache_disable_cookie(struct fscache_cookie *cookie, bool invalidate)
{
struct fscache_object *object;
bool awaken = false;
_enter("%p,%u", cookie, invalidate);
ASSERTCMP(atomic_read(&cookie->n_active), >, 0);
if (atomic_read(&cookie->n_children) != 0) {
pr_err("Cookie '%s' still has children\n",
cookie->def->name);
BUG();
}
wait_on_bit_lock(&cookie->flags, FSCACHE_COOKIE_ENABLEMENT_LOCK,
TASK_UNINTERRUPTIBLE);
if (!test_and_clear_bit(FSCACHE_COOKIE_ENABLED, &cookie->flags))
goto out_unlock_enable;
__fscache_wait_on_invalidate(cookie);
set_bit(FSCACHE_COOKIE_INVALIDATING, &cookie->flags);
spin_lock(&cookie->lock);
if (!hlist_empty(&cookie->backing_objects)) {
hlist_for_each_entry(object, &cookie->backing_objects, cookie_link) {
if (invalidate)
set_bit(FSCACHE_OBJECT_RETIRED, &object->flags);
fscache_raise_event(object, FSCACHE_OBJECT_EV_KILL);
}
} else {
if (test_and_clear_bit(FSCACHE_COOKIE_INVALIDATING, &cookie->flags))
awaken = true;
}
spin_unlock(&cookie->lock);
if (awaken)
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_INVALIDATING);
if (!atomic_dec_and_test(&cookie->n_active))
wait_on_atomic_t(&cookie->n_active, fscache_wait_atomic_t,
TASK_UNINTERRUPTIBLE);
if (!test_bit(FSCACHE_COOKIE_RELINQUISHED, &cookie->flags)) {
atomic_inc(&cookie->n_active);
set_bit(FSCACHE_COOKIE_NO_DATA_YET, &cookie->flags);
}
out_unlock_enable:
clear_bit_unlock(FSCACHE_COOKIE_ENABLEMENT_LOCK, &cookie->flags);
wake_up_bit(&cookie->flags, FSCACHE_COOKIE_ENABLEMENT_LOCK);
_leave("");
}
void __fscache_relinquish_cookie(struct fscache_cookie *cookie, bool retire)
{
fscache_stat(&fscache_n_relinquishes);
if (retire)
fscache_stat(&fscache_n_relinquishes_retire);
if (!cookie) {
fscache_stat(&fscache_n_relinquishes_null);
_leave(" [no cookie]");
return;
}
_enter("%p{%s,%p,%d},%d",
cookie, cookie->def->name, cookie->netfs_data,
atomic_read(&cookie->n_active), retire);
set_bit(FSCACHE_COOKIE_RELINQUISHED, &cookie->flags);
__fscache_disable_cookie(cookie, retire);
cookie->netfs_data = NULL;
cookie->def = NULL;
BUG_ON(cookie->stores.rnode);
if (cookie->parent) {
ASSERTCMP(atomic_read(&cookie->parent->usage), >, 0);
ASSERTCMP(atomic_read(&cookie->parent->n_children), >, 0);
atomic_dec(&cookie->parent->n_children);
}
ASSERTCMP(atomic_read(&cookie->usage), >, 0);
fscache_cookie_put(cookie);
_leave("");
}
void __fscache_cookie_put(struct fscache_cookie *cookie)
{
struct fscache_cookie *parent;
_enter("%p", cookie);
for (;;) {
_debug("FREE COOKIE %p", cookie);
parent = cookie->parent;
BUG_ON(!hlist_empty(&cookie->backing_objects));
kmem_cache_free(fscache_cookie_jar, cookie);
if (!parent)
break;
cookie = parent;
BUG_ON(atomic_read(&cookie->usage) <= 0);
if (!atomic_dec_and_test(&cookie->usage))
break;
}
_leave("");
}
int __fscache_check_consistency(struct fscache_cookie *cookie)
{
struct fscache_operation *op;
struct fscache_object *object;
bool wake_cookie = false;
int ret;
_enter("%p,", cookie);
ASSERTCMP(cookie->def->type, ==, FSCACHE_COOKIE_TYPE_DATAFILE);
if (fscache_wait_for_deferred_lookup(cookie) < 0)
return -ERESTARTSYS;
if (hlist_empty(&cookie->backing_objects))
return 0;
op = kzalloc(sizeof(*op), GFP_NOIO | __GFP_NOMEMALLOC | __GFP_NORETRY);
if (!op)
return -ENOMEM;
fscache_operation_init(op, NULL, NULL);
op->flags = FSCACHE_OP_MYTHREAD |
(1 << FSCACHE_OP_WAITING) |
(1 << FSCACHE_OP_UNUSE_COOKIE);
spin_lock(&cookie->lock);
if (!fscache_cookie_enabled(cookie) ||
hlist_empty(&cookie->backing_objects))
goto inconsistent;
object = hlist_entry(cookie->backing_objects.first,
struct fscache_object, cookie_link);
if (test_bit(FSCACHE_IOERROR, &object->cache->flags))
goto inconsistent;
op->debug_id = atomic_inc_return(&fscache_op_debug_id);
__fscache_use_cookie(cookie);
if (fscache_submit_op(object, op) < 0)
goto submit_failed;
spin_unlock(&cookie->lock);
ret = fscache_wait_for_operation_activation(object, op,
NULL, NULL, NULL);
if (ret == 0) {
ret = object->cache->ops->check_consistency(op);
fscache_op_complete(op, false);
} else if (ret == -ENOBUFS) {
ret = 0;
}
fscache_put_operation(op);
_leave(" = %d", ret);
return ret;
submit_failed:
wake_cookie = __fscache_unuse_cookie(cookie);
inconsistent:
spin_unlock(&cookie->lock);
if (wake_cookie)
__fscache_wake_unused_cookie(cookie);
kfree(op);
_leave(" = -ESTALE");
return -ESTALE;
}
