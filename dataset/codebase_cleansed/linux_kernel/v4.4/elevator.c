static int elv_iosched_allow_merge(struct request *rq, struct bio *bio)
{
struct request_queue *q = rq->q;
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_allow_merge_fn)
return e->type->ops.elevator_allow_merge_fn(q, rq, bio);
return 1;
}
bool elv_rq_merge_ok(struct request *rq, struct bio *bio)
{
if (!blk_rq_merge_ok(rq, bio))
return 0;
if (!elv_iosched_allow_merge(rq, bio))
return 0;
return 1;
}
static struct elevator_type *elevator_find(const char *name)
{
struct elevator_type *e;
list_for_each_entry(e, &elv_list, list) {
if (!strcmp(e->elevator_name, name))
return e;
}
return NULL;
}
static void elevator_put(struct elevator_type *e)
{
module_put(e->elevator_owner);
}
static struct elevator_type *elevator_get(const char *name, bool try_loading)
{
struct elevator_type *e;
spin_lock(&elv_list_lock);
e = elevator_find(name);
if (!e && try_loading) {
spin_unlock(&elv_list_lock);
request_module("%s-iosched", name);
spin_lock(&elv_list_lock);
e = elevator_find(name);
}
if (e && !try_module_get(e->elevator_owner))
e = NULL;
spin_unlock(&elv_list_lock);
return e;
}
static int __init elevator_setup(char *str)
{
strncpy(chosen_elevator, str, sizeof(chosen_elevator) - 1);
return 1;
}
void __init load_default_elevator_module(void)
{
struct elevator_type *e;
if (!chosen_elevator[0])
return;
spin_lock(&elv_list_lock);
e = elevator_find(chosen_elevator);
spin_unlock(&elv_list_lock);
if (!e)
request_module("%s-iosched", chosen_elevator);
}
struct elevator_queue *elevator_alloc(struct request_queue *q,
struct elevator_type *e)
{
struct elevator_queue *eq;
eq = kzalloc_node(sizeof(*eq), GFP_KERNEL, q->node);
if (unlikely(!eq))
return NULL;
eq->type = e;
kobject_init(&eq->kobj, &elv_ktype);
mutex_init(&eq->sysfs_lock);
hash_init(eq->hash);
return eq;
}
static void elevator_release(struct kobject *kobj)
{
struct elevator_queue *e;
e = container_of(kobj, struct elevator_queue, kobj);
elevator_put(e->type);
kfree(e);
}
int elevator_init(struct request_queue *q, char *name)
{
struct elevator_type *e = NULL;
int err;
lockdep_assert_held(&q->sysfs_lock);
if (unlikely(q->elevator))
return 0;
INIT_LIST_HEAD(&q->queue_head);
q->last_merge = NULL;
q->end_sector = 0;
q->boundary_rq = NULL;
if (name) {
e = elevator_get(name, true);
if (!e)
return -EINVAL;
}
if (!e && *chosen_elevator) {
e = elevator_get(chosen_elevator, false);
if (!e)
printk(KERN_ERR "I/O scheduler %s not found\n",
chosen_elevator);
}
if (!e) {
e = elevator_get(CONFIG_DEFAULT_IOSCHED, false);
if (!e) {
printk(KERN_ERR
"Default I/O scheduler not found. " \
"Using noop.\n");
e = elevator_get("noop", false);
}
}
err = e->ops.elevator_init_fn(q, e);
if (err)
elevator_put(e);
return err;
}
void elevator_exit(struct elevator_queue *e)
{
mutex_lock(&e->sysfs_lock);
if (e->type->ops.elevator_exit_fn)
e->type->ops.elevator_exit_fn(e);
mutex_unlock(&e->sysfs_lock);
kobject_put(&e->kobj);
}
static inline void __elv_rqhash_del(struct request *rq)
{
hash_del(&rq->hash);
rq->cmd_flags &= ~REQ_HASHED;
}
static void elv_rqhash_del(struct request_queue *q, struct request *rq)
{
if (ELV_ON_HASH(rq))
__elv_rqhash_del(rq);
}
static void elv_rqhash_add(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
BUG_ON(ELV_ON_HASH(rq));
hash_add(e->hash, &rq->hash, rq_hash_key(rq));
rq->cmd_flags |= REQ_HASHED;
}
static void elv_rqhash_reposition(struct request_queue *q, struct request *rq)
{
__elv_rqhash_del(rq);
elv_rqhash_add(q, rq);
}
static struct request *elv_rqhash_find(struct request_queue *q, sector_t offset)
{
struct elevator_queue *e = q->elevator;
struct hlist_node *next;
struct request *rq;
hash_for_each_possible_safe(e->hash, rq, next, hash, offset) {
BUG_ON(!ELV_ON_HASH(rq));
if (unlikely(!rq_mergeable(rq))) {
__elv_rqhash_del(rq);
continue;
}
if (rq_hash_key(rq) == offset)
return rq;
}
return NULL;
}
void elv_rb_add(struct rb_root *root, struct request *rq)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct request *__rq;
while (*p) {
parent = *p;
__rq = rb_entry(parent, struct request, rb_node);
if (blk_rq_pos(rq) < blk_rq_pos(__rq))
p = &(*p)->rb_left;
else if (blk_rq_pos(rq) >= blk_rq_pos(__rq))
p = &(*p)->rb_right;
}
rb_link_node(&rq->rb_node, parent, p);
rb_insert_color(&rq->rb_node, root);
}
void elv_rb_del(struct rb_root *root, struct request *rq)
{
BUG_ON(RB_EMPTY_NODE(&rq->rb_node));
rb_erase(&rq->rb_node, root);
RB_CLEAR_NODE(&rq->rb_node);
}
struct request *elv_rb_find(struct rb_root *root, sector_t sector)
{
struct rb_node *n = root->rb_node;
struct request *rq;
while (n) {
rq = rb_entry(n, struct request, rb_node);
if (sector < blk_rq_pos(rq))
n = n->rb_left;
else if (sector > blk_rq_pos(rq))
n = n->rb_right;
else
return rq;
}
return NULL;
}
void elv_dispatch_sort(struct request_queue *q, struct request *rq)
{
sector_t boundary;
struct list_head *entry;
int stop_flags;
if (q->last_merge == rq)
q->last_merge = NULL;
elv_rqhash_del(q, rq);
q->nr_sorted--;
boundary = q->end_sector;
stop_flags = REQ_SOFTBARRIER | REQ_STARTED;
list_for_each_prev(entry, &q->queue_head) {
struct request *pos = list_entry_rq(entry);
if ((rq->cmd_flags & REQ_DISCARD) !=
(pos->cmd_flags & REQ_DISCARD))
break;
if (rq_data_dir(rq) != rq_data_dir(pos))
break;
if (pos->cmd_flags & stop_flags)
break;
if (blk_rq_pos(rq) >= boundary) {
if (blk_rq_pos(pos) < boundary)
continue;
} else {
if (blk_rq_pos(pos) >= boundary)
break;
}
if (blk_rq_pos(rq) >= blk_rq_pos(pos))
break;
}
list_add(&rq->queuelist, entry);
}
void elv_dispatch_add_tail(struct request_queue *q, struct request *rq)
{
if (q->last_merge == rq)
q->last_merge = NULL;
elv_rqhash_del(q, rq);
q->nr_sorted--;
q->end_sector = rq_end_sector(rq);
q->boundary_rq = rq;
list_add_tail(&rq->queuelist, &q->queue_head);
}
int elv_merge(struct request_queue *q, struct request **req, struct bio *bio)
{
struct elevator_queue *e = q->elevator;
struct request *__rq;
int ret;
if (blk_queue_nomerges(q) || !bio_mergeable(bio))
return ELEVATOR_NO_MERGE;
if (q->last_merge && elv_rq_merge_ok(q->last_merge, bio)) {
ret = blk_try_merge(q->last_merge, bio);
if (ret != ELEVATOR_NO_MERGE) {
*req = q->last_merge;
return ret;
}
}
if (blk_queue_noxmerges(q))
return ELEVATOR_NO_MERGE;
__rq = elv_rqhash_find(q, bio->bi_iter.bi_sector);
if (__rq && elv_rq_merge_ok(__rq, bio)) {
*req = __rq;
return ELEVATOR_BACK_MERGE;
}
if (e->type->ops.elevator_merge_fn)
return e->type->ops.elevator_merge_fn(q, req, bio);
return ELEVATOR_NO_MERGE;
}
static bool elv_attempt_insert_merge(struct request_queue *q,
struct request *rq)
{
struct request *__rq;
bool ret;
if (blk_queue_nomerges(q))
return false;
if (q->last_merge && blk_attempt_req_merge(q, q->last_merge, rq))
return true;
if (blk_queue_noxmerges(q))
return false;
ret = false;
while (1) {
__rq = elv_rqhash_find(q, blk_rq_pos(rq));
if (!__rq || !blk_attempt_req_merge(q, __rq, rq))
break;
ret = true;
rq = __rq;
}
return ret;
}
void elv_merged_request(struct request_queue *q, struct request *rq, int type)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_merged_fn)
e->type->ops.elevator_merged_fn(q, rq, type);
if (type == ELEVATOR_BACK_MERGE)
elv_rqhash_reposition(q, rq);
q->last_merge = rq;
}
void elv_merge_requests(struct request_queue *q, struct request *rq,
struct request *next)
{
struct elevator_queue *e = q->elevator;
const int next_sorted = next->cmd_flags & REQ_SORTED;
if (next_sorted && e->type->ops.elevator_merge_req_fn)
e->type->ops.elevator_merge_req_fn(q, rq, next);
elv_rqhash_reposition(q, rq);
if (next_sorted) {
elv_rqhash_del(q, next);
q->nr_sorted--;
}
q->last_merge = rq;
}
void elv_bio_merged(struct request_queue *q, struct request *rq,
struct bio *bio)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_bio_merged_fn)
e->type->ops.elevator_bio_merged_fn(q, rq, bio);
}
static void blk_pm_requeue_request(struct request *rq)
{
if (rq->q->dev && !(rq->cmd_flags & REQ_PM))
rq->q->nr_pending--;
}
static void blk_pm_add_request(struct request_queue *q, struct request *rq)
{
if (q->dev && !(rq->cmd_flags & REQ_PM) && q->nr_pending++ == 0 &&
(q->rpm_status == RPM_SUSPENDED || q->rpm_status == RPM_SUSPENDING))
pm_request_resume(q->dev);
}
static inline void blk_pm_requeue_request(struct request *rq) {}
static inline void blk_pm_add_request(struct request_queue *q,
struct request *rq)
{
}
void elv_requeue_request(struct request_queue *q, struct request *rq)
{
if (blk_account_rq(rq)) {
q->in_flight[rq_is_sync(rq)]--;
if (rq->cmd_flags & REQ_SORTED)
elv_deactivate_rq(q, rq);
}
rq->cmd_flags &= ~REQ_STARTED;
blk_pm_requeue_request(rq);
__elv_add_request(q, rq, ELEVATOR_INSERT_REQUEUE);
}
void elv_drain_elevator(struct request_queue *q)
{
static int printed;
lockdep_assert_held(q->queue_lock);
while (q->elevator->type->ops.elevator_dispatch_fn(q, 1))
;
if (q->nr_sorted && printed++ < 10) {
printk(KERN_ERR "%s: forced dispatching is broken "
"(nr_sorted=%u), please report this\n",
q->elevator->type->elevator_name, q->nr_sorted);
}
}
void __elv_add_request(struct request_queue *q, struct request *rq, int where)
{
trace_block_rq_insert(q, rq);
blk_pm_add_request(q, rq);
rq->q = q;
if (rq->cmd_flags & REQ_SOFTBARRIER) {
if (rq->cmd_type == REQ_TYPE_FS) {
q->end_sector = rq_end_sector(rq);
q->boundary_rq = rq;
}
} else if (!(rq->cmd_flags & REQ_ELVPRIV) &&
(where == ELEVATOR_INSERT_SORT ||
where == ELEVATOR_INSERT_SORT_MERGE))
where = ELEVATOR_INSERT_BACK;
switch (where) {
case ELEVATOR_INSERT_REQUEUE:
case ELEVATOR_INSERT_FRONT:
rq->cmd_flags |= REQ_SOFTBARRIER;
list_add(&rq->queuelist, &q->queue_head);
break;
case ELEVATOR_INSERT_BACK:
rq->cmd_flags |= REQ_SOFTBARRIER;
elv_drain_elevator(q);
list_add_tail(&rq->queuelist, &q->queue_head);
__blk_run_queue(q);
break;
case ELEVATOR_INSERT_SORT_MERGE:
if (elv_attempt_insert_merge(q, rq))
break;
case ELEVATOR_INSERT_SORT:
BUG_ON(rq->cmd_type != REQ_TYPE_FS);
rq->cmd_flags |= REQ_SORTED;
q->nr_sorted++;
if (rq_mergeable(rq)) {
elv_rqhash_add(q, rq);
if (!q->last_merge)
q->last_merge = rq;
}
q->elevator->type->ops.elevator_add_req_fn(q, rq);
break;
case ELEVATOR_INSERT_FLUSH:
rq->cmd_flags |= REQ_SOFTBARRIER;
blk_insert_flush(rq);
break;
default:
printk(KERN_ERR "%s: bad insertion point %d\n",
__func__, where);
BUG();
}
}
void elv_add_request(struct request_queue *q, struct request *rq, int where)
{
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
__elv_add_request(q, rq, where);
spin_unlock_irqrestore(q->queue_lock, flags);
}
struct request *elv_latter_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_latter_req_fn)
return e->type->ops.elevator_latter_req_fn(q, rq);
return NULL;
}
struct request *elv_former_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_former_req_fn)
return e->type->ops.elevator_former_req_fn(q, rq);
return NULL;
}
int elv_set_request(struct request_queue *q, struct request *rq,
struct bio *bio, gfp_t gfp_mask)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_set_req_fn)
return e->type->ops.elevator_set_req_fn(q, rq, bio, gfp_mask);
return 0;
}
void elv_put_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_put_req_fn)
e->type->ops.elevator_put_req_fn(rq);
}
int elv_may_queue(struct request_queue *q, int rw)
{
struct elevator_queue *e = q->elevator;
if (e->type->ops.elevator_may_queue_fn)
return e->type->ops.elevator_may_queue_fn(q, rw);
return ELV_MQUEUE_MAY;
}
void elv_completed_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (blk_account_rq(rq)) {
q->in_flight[rq_is_sync(rq)]--;
if ((rq->cmd_flags & REQ_SORTED) &&
e->type->ops.elevator_completed_req_fn)
e->type->ops.elevator_completed_req_fn(q, rq);
}
}
static ssize_t
elv_attr_show(struct kobject *kobj, struct attribute *attr, char *page)
{
struct elv_fs_entry *entry = to_elv(attr);
struct elevator_queue *e;
ssize_t error;
if (!entry->show)
return -EIO;
e = container_of(kobj, struct elevator_queue, kobj);
mutex_lock(&e->sysfs_lock);
error = e->type ? entry->show(e, page) : -ENOENT;
mutex_unlock(&e->sysfs_lock);
return error;
}
static ssize_t
elv_attr_store(struct kobject *kobj, struct attribute *attr,
const char *page, size_t length)
{
struct elv_fs_entry *entry = to_elv(attr);
struct elevator_queue *e;
ssize_t error;
if (!entry->store)
return -EIO;
e = container_of(kobj, struct elevator_queue, kobj);
mutex_lock(&e->sysfs_lock);
error = e->type ? entry->store(e, page, length) : -ENOENT;
mutex_unlock(&e->sysfs_lock);
return error;
}
int elv_register_queue(struct request_queue *q)
{
struct elevator_queue *e = q->elevator;
int error;
error = kobject_add(&e->kobj, &q->kobj, "%s", "iosched");
if (!error) {
struct elv_fs_entry *attr = e->type->elevator_attrs;
if (attr) {
while (attr->attr.name) {
if (sysfs_create_file(&e->kobj, &attr->attr))
break;
attr++;
}
}
kobject_uevent(&e->kobj, KOBJ_ADD);
e->registered = 1;
if (e->type->ops.elevator_registered_fn)
e->type->ops.elevator_registered_fn(q);
}
return error;
}
void elv_unregister_queue(struct request_queue *q)
{
if (q) {
struct elevator_queue *e = q->elevator;
kobject_uevent(&e->kobj, KOBJ_REMOVE);
kobject_del(&e->kobj);
e->registered = 0;
}
}
int elv_register(struct elevator_type *e)
{
char *def = "";
if (e->icq_size) {
if (WARN_ON(e->icq_size < sizeof(struct io_cq)) ||
WARN_ON(e->icq_align < __alignof__(struct io_cq)))
return -EINVAL;
snprintf(e->icq_cache_name, sizeof(e->icq_cache_name),
"%s_io_cq", e->elevator_name);
e->icq_cache = kmem_cache_create(e->icq_cache_name, e->icq_size,
e->icq_align, 0, NULL);
if (!e->icq_cache)
return -ENOMEM;
}
spin_lock(&elv_list_lock);
if (elevator_find(e->elevator_name)) {
spin_unlock(&elv_list_lock);
if (e->icq_cache)
kmem_cache_destroy(e->icq_cache);
return -EBUSY;
}
list_add_tail(&e->list, &elv_list);
spin_unlock(&elv_list_lock);
if (!strcmp(e->elevator_name, chosen_elevator) ||
(!*chosen_elevator &&
!strcmp(e->elevator_name, CONFIG_DEFAULT_IOSCHED)))
def = " (default)";
printk(KERN_INFO "io scheduler %s registered%s\n", e->elevator_name,
def);
return 0;
}
void elv_unregister(struct elevator_type *e)
{
spin_lock(&elv_list_lock);
list_del_init(&e->list);
spin_unlock(&elv_list_lock);
if (e->icq_cache) {
rcu_barrier();
kmem_cache_destroy(e->icq_cache);
e->icq_cache = NULL;
}
}
static int elevator_switch(struct request_queue *q, struct elevator_type *new_e)
{
struct elevator_queue *old = q->elevator;
bool registered = old->registered;
int err;
blk_queue_bypass_start(q);
if (registered)
elv_unregister_queue(q);
spin_lock_irq(q->queue_lock);
ioc_clear_queue(q);
spin_unlock_irq(q->queue_lock);
err = new_e->ops.elevator_init_fn(q, new_e);
if (err)
goto fail_init;
if (registered) {
err = elv_register_queue(q);
if (err)
goto fail_register;
}
elevator_exit(old);
blk_queue_bypass_end(q);
blk_add_trace_msg(q, "elv switch: %s", new_e->elevator_name);
return 0;
fail_register:
elevator_exit(q->elevator);
fail_init:
q->elevator = old;
elv_register_queue(q);
blk_queue_bypass_end(q);
return err;
}
static int __elevator_change(struct request_queue *q, const char *name)
{
char elevator_name[ELV_NAME_MAX];
struct elevator_type *e;
if (!q->elevator)
return -ENXIO;
strlcpy(elevator_name, name, sizeof(elevator_name));
e = elevator_get(strstrip(elevator_name), true);
if (!e) {
printk(KERN_ERR "elevator: type %s not found\n", elevator_name);
return -EINVAL;
}
if (!strcmp(elevator_name, q->elevator->type->elevator_name)) {
elevator_put(e);
return 0;
}
return elevator_switch(q, e);
}
int elevator_change(struct request_queue *q, const char *name)
{
int ret;
mutex_lock(&q->sysfs_lock);
ret = __elevator_change(q, name);
mutex_unlock(&q->sysfs_lock);
return ret;
}
ssize_t elv_iosched_store(struct request_queue *q, const char *name,
size_t count)
{
int ret;
if (!q->elevator)
return count;
ret = __elevator_change(q, name);
if (!ret)
return count;
printk(KERN_ERR "elevator: switch to %s failed\n", name);
return ret;
}
ssize_t elv_iosched_show(struct request_queue *q, char *name)
{
struct elevator_queue *e = q->elevator;
struct elevator_type *elv;
struct elevator_type *__e;
int len = 0;
if (!q->elevator || !blk_queue_stackable(q))
return sprintf(name, "none\n");
elv = e->type;
spin_lock(&elv_list_lock);
list_for_each_entry(__e, &elv_list, list) {
if (!strcmp(elv->elevator_name, __e->elevator_name))
len += sprintf(name+len, "[%s] ", elv->elevator_name);
else
len += sprintf(name+len, "%s ", __e->elevator_name);
}
spin_unlock(&elv_list_lock);
len += sprintf(len+name, "\n");
return len;
}
struct request *elv_rb_former_request(struct request_queue *q,
struct request *rq)
{
struct rb_node *rbprev = rb_prev(&rq->rb_node);
if (rbprev)
return rb_entry_rq(rbprev);
return NULL;
}
struct request *elv_rb_latter_request(struct request_queue *q,
struct request *rq)
{
struct rb_node *rbnext = rb_next(&rq->rb_node);
if (rbnext)
return rb_entry_rq(rbnext);
return NULL;
}
