static int elv_iosched_allow_bio_merge(struct request *rq, struct bio *bio)
{
struct request_queue *q = rq->q;
struct elevator_queue *e = q->elevator;
if (e->uses_mq && e->type->ops.mq.allow_merge)
return e->type->ops.mq.allow_merge(q, rq, bio);
else if (!e->uses_mq && e->type->ops.sq.elevator_allow_bio_merge_fn)
return e->type->ops.sq.elevator_allow_bio_merge_fn(q, rq, bio);
return 1;
}
bool elv_bio_merge_ok(struct request *rq, struct bio *bio)
{
if (!blk_rq_merge_ok(rq, bio))
return false;
if (!elv_iosched_allow_bio_merge(rq, bio))
return false;
return true;
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
eq->uses_mq = e->uses_mq;
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
if (!e && !q->mq_ops && *chosen_elevator) {
e = elevator_get(chosen_elevator, false);
if (!e)
printk(KERN_ERR "I/O scheduler %s not found\n",
chosen_elevator);
}
if (!e) {
if (q->mq_ops) {
if (q->nr_hw_queues == 1)
e = elevator_get("mq-deadline", false);
if (!e)
return 0;
} else
e = elevator_get(CONFIG_DEFAULT_IOSCHED, false);
if (!e) {
printk(KERN_ERR
"Default I/O scheduler not found. " \
"Using noop.\n");
e = elevator_get("noop", false);
}
}
if (e->uses_mq)
err = blk_mq_init_sched(q, e);
else
err = e->ops.sq.elevator_init_fn(q, e);
if (err)
elevator_put(e);
return err;
}
void elevator_exit(struct request_queue *q, struct elevator_queue *e)
{
mutex_lock(&e->sysfs_lock);
if (e->uses_mq && e->type->ops.mq.exit_sched)
blk_mq_exit_sched(q, e);
else if (!e->uses_mq && e->type->ops.sq.elevator_exit_fn)
e->type->ops.sq.elevator_exit_fn(e);
mutex_unlock(&e->sysfs_lock);
kobject_put(&e->kobj);
}
static inline void __elv_rqhash_del(struct request *rq)
{
hash_del(&rq->hash);
rq->rq_flags &= ~RQF_HASHED;
}
void elv_rqhash_del(struct request_queue *q, struct request *rq)
{
if (ELV_ON_HASH(rq))
__elv_rqhash_del(rq);
}
void elv_rqhash_add(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
BUG_ON(ELV_ON_HASH(rq));
hash_add(e->hash, &rq->hash, rq_hash_key(rq));
rq->rq_flags |= RQF_HASHED;
}
void elv_rqhash_reposition(struct request_queue *q, struct request *rq)
{
__elv_rqhash_del(rq);
elv_rqhash_add(q, rq);
}
struct request *elv_rqhash_find(struct request_queue *q, sector_t offset)
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
if (q->last_merge == rq)
q->last_merge = NULL;
elv_rqhash_del(q, rq);
q->nr_sorted--;
boundary = q->end_sector;
list_for_each_prev(entry, &q->queue_head) {
struct request *pos = list_entry_rq(entry);
if (req_op(rq) != req_op(pos))
break;
if (rq_data_dir(rq) != rq_data_dir(pos))
break;
if (pos->rq_flags & (RQF_STARTED | RQF_SOFTBARRIER))
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
enum elv_merge elv_merge(struct request_queue *q, struct request **req,
struct bio *bio)
{
struct elevator_queue *e = q->elevator;
struct request *__rq;
if (blk_queue_nomerges(q) || !bio_mergeable(bio))
return ELEVATOR_NO_MERGE;
if (q->last_merge && elv_bio_merge_ok(q->last_merge, bio)) {
enum elv_merge ret = blk_try_merge(q->last_merge, bio);
if (ret != ELEVATOR_NO_MERGE) {
*req = q->last_merge;
return ret;
}
}
if (blk_queue_noxmerges(q))
return ELEVATOR_NO_MERGE;
__rq = elv_rqhash_find(q, bio->bi_iter.bi_sector);
if (__rq && elv_bio_merge_ok(__rq, bio)) {
*req = __rq;
return ELEVATOR_BACK_MERGE;
}
if (e->uses_mq && e->type->ops.mq.request_merge)
return e->type->ops.mq.request_merge(q, req, bio);
else if (!e->uses_mq && e->type->ops.sq.elevator_merge_fn)
return e->type->ops.sq.elevator_merge_fn(q, req, bio);
return ELEVATOR_NO_MERGE;
}
bool elv_attempt_insert_merge(struct request_queue *q, struct request *rq)
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
void elv_merged_request(struct request_queue *q, struct request *rq,
enum elv_merge type)
{
struct elevator_queue *e = q->elevator;
if (e->uses_mq && e->type->ops.mq.request_merged)
e->type->ops.mq.request_merged(q, rq, type);
else if (!e->uses_mq && e->type->ops.sq.elevator_merged_fn)
e->type->ops.sq.elevator_merged_fn(q, rq, type);
if (type == ELEVATOR_BACK_MERGE)
elv_rqhash_reposition(q, rq);
q->last_merge = rq;
}
void elv_merge_requests(struct request_queue *q, struct request *rq,
struct request *next)
{
struct elevator_queue *e = q->elevator;
bool next_sorted = false;
if (e->uses_mq && e->type->ops.mq.requests_merged)
e->type->ops.mq.requests_merged(q, rq, next);
else if (e->type->ops.sq.elevator_merge_req_fn) {
next_sorted = (__force bool)(next->rq_flags & RQF_SORTED);
if (next_sorted)
e->type->ops.sq.elevator_merge_req_fn(q, rq, next);
}
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
if (WARN_ON_ONCE(e->uses_mq))
return;
if (e->type->ops.sq.elevator_bio_merged_fn)
e->type->ops.sq.elevator_bio_merged_fn(q, rq, bio);
}
static void blk_pm_requeue_request(struct request *rq)
{
if (rq->q->dev && !(rq->rq_flags & RQF_PM))
rq->q->nr_pending--;
}
static void blk_pm_add_request(struct request_queue *q, struct request *rq)
{
if (q->dev && !(rq->rq_flags & RQF_PM) && q->nr_pending++ == 0 &&
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
if (rq->rq_flags & RQF_SORTED)
elv_deactivate_rq(q, rq);
}
rq->rq_flags &= ~RQF_STARTED;
blk_pm_requeue_request(rq);
__elv_add_request(q, rq, ELEVATOR_INSERT_REQUEUE);
}
void elv_drain_elevator(struct request_queue *q)
{
struct elevator_queue *e = q->elevator;
static int printed;
if (WARN_ON_ONCE(e->uses_mq))
return;
lockdep_assert_held(q->queue_lock);
while (e->type->ops.sq.elevator_dispatch_fn(q, 1))
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
if (rq->rq_flags & RQF_SOFTBARRIER) {
if (!blk_rq_is_passthrough(rq)) {
q->end_sector = rq_end_sector(rq);
q->boundary_rq = rq;
}
} else if (!(rq->rq_flags & RQF_ELVPRIV) &&
(where == ELEVATOR_INSERT_SORT ||
where == ELEVATOR_INSERT_SORT_MERGE))
where = ELEVATOR_INSERT_BACK;
switch (where) {
case ELEVATOR_INSERT_REQUEUE:
case ELEVATOR_INSERT_FRONT:
rq->rq_flags |= RQF_SOFTBARRIER;
list_add(&rq->queuelist, &q->queue_head);
break;
case ELEVATOR_INSERT_BACK:
rq->rq_flags |= RQF_SOFTBARRIER;
elv_drain_elevator(q);
list_add_tail(&rq->queuelist, &q->queue_head);
__blk_run_queue(q);
break;
case ELEVATOR_INSERT_SORT_MERGE:
if (elv_attempt_insert_merge(q, rq))
break;
case ELEVATOR_INSERT_SORT:
BUG_ON(blk_rq_is_passthrough(rq));
rq->rq_flags |= RQF_SORTED;
q->nr_sorted++;
if (rq_mergeable(rq)) {
elv_rqhash_add(q, rq);
if (!q->last_merge)
q->last_merge = rq;
}
q->elevator->type->ops.sq.elevator_add_req_fn(q, rq);
break;
case ELEVATOR_INSERT_FLUSH:
rq->rq_flags |= RQF_SOFTBARRIER;
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
if (e->uses_mq && e->type->ops.mq.next_request)
return e->type->ops.mq.next_request(q, rq);
else if (!e->uses_mq && e->type->ops.sq.elevator_latter_req_fn)
return e->type->ops.sq.elevator_latter_req_fn(q, rq);
return NULL;
}
struct request *elv_former_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (e->uses_mq && e->type->ops.mq.former_request)
return e->type->ops.mq.former_request(q, rq);
if (!e->uses_mq && e->type->ops.sq.elevator_former_req_fn)
return e->type->ops.sq.elevator_former_req_fn(q, rq);
return NULL;
}
int elv_set_request(struct request_queue *q, struct request *rq,
struct bio *bio, gfp_t gfp_mask)
{
struct elevator_queue *e = q->elevator;
if (WARN_ON_ONCE(e->uses_mq))
return 0;
if (e->type->ops.sq.elevator_set_req_fn)
return e->type->ops.sq.elevator_set_req_fn(q, rq, bio, gfp_mask);
return 0;
}
void elv_put_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (WARN_ON_ONCE(e->uses_mq))
return;
if (e->type->ops.sq.elevator_put_req_fn)
e->type->ops.sq.elevator_put_req_fn(rq);
}
int elv_may_queue(struct request_queue *q, unsigned int op)
{
struct elevator_queue *e = q->elevator;
if (WARN_ON_ONCE(e->uses_mq))
return 0;
if (e->type->ops.sq.elevator_may_queue_fn)
return e->type->ops.sq.elevator_may_queue_fn(q, op);
return ELV_MQUEUE_MAY;
}
void elv_completed_request(struct request_queue *q, struct request *rq)
{
struct elevator_queue *e = q->elevator;
if (WARN_ON_ONCE(e->uses_mq))
return;
if (blk_account_rq(rq)) {
q->in_flight[rq_is_sync(rq)]--;
if ((rq->rq_flags & RQF_SORTED) &&
e->type->ops.sq.elevator_completed_req_fn)
e->type->ops.sq.elevator_completed_req_fn(q, rq);
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
if (!e->uses_mq && e->type->ops.sq.elevator_registered_fn)
e->type->ops.sq.elevator_registered_fn(q);
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
static int elevator_switch_mq(struct request_queue *q,
struct elevator_type *new_e)
{
int ret;
blk_mq_freeze_queue(q);
blk_mq_quiesce_queue(q);
if (q->elevator) {
if (q->elevator->registered)
elv_unregister_queue(q);
ioc_clear_queue(q);
elevator_exit(q, q->elevator);
}
ret = blk_mq_init_sched(q, new_e);
if (ret)
goto out;
if (new_e) {
ret = elv_register_queue(q);
if (ret) {
elevator_exit(q, q->elevator);
goto out;
}
}
if (new_e)
blk_add_trace_msg(q, "elv switch: %s", new_e->elevator_name);
else
blk_add_trace_msg(q, "elv switch: none");
out:
blk_mq_unfreeze_queue(q);
blk_mq_start_stopped_hw_queues(q, true);
return ret;
}
static int elevator_switch(struct request_queue *q, struct elevator_type *new_e)
{
struct elevator_queue *old = q->elevator;
bool old_registered = false;
int err;
if (q->mq_ops)
return elevator_switch_mq(q, new_e);
if (old) {
old_registered = old->registered;
blk_queue_bypass_start(q);
if (old_registered)
elv_unregister_queue(q);
ioc_clear_queue(q);
}
err = new_e->ops.sq.elevator_init_fn(q, new_e);
if (err)
goto fail_init;
err = elv_register_queue(q);
if (err)
goto fail_register;
if (old) {
elevator_exit(q, old);
blk_queue_bypass_end(q);
}
blk_add_trace_msg(q, "elv switch: %s", new_e->elevator_name);
return 0;
fail_register:
elevator_exit(q, q->elevator);
fail_init:
if (old) {
q->elevator = old;
elv_register_queue(q);
blk_queue_bypass_end(q);
}
return err;
}
static int __elevator_change(struct request_queue *q, const char *name)
{
char elevator_name[ELV_NAME_MAX];
struct elevator_type *e;
if (q->mq_ops && !strncmp(name, "none", 4))
return elevator_switch(q, NULL);
strlcpy(elevator_name, name, sizeof(elevator_name));
e = elevator_get(strstrip(elevator_name), true);
if (!e) {
printk(KERN_ERR "elevator: type %s not found\n", elevator_name);
return -EINVAL;
}
if (q->elevator &&
!strcmp(elevator_name, q->elevator->type->elevator_name)) {
elevator_put(e);
return 0;
}
if (!e->uses_mq && q->mq_ops) {
elevator_put(e);
return -EINVAL;
}
if (e->uses_mq && !q->mq_ops) {
elevator_put(e);
return -EINVAL;
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
static inline bool elv_support_iosched(struct request_queue *q)
{
if (q->mq_ops && q->tag_set && (q->tag_set->flags &
BLK_MQ_F_NO_SCHED))
return false;
return true;
}
ssize_t elv_iosched_store(struct request_queue *q, const char *name,
size_t count)
{
int ret;
if (!(q->mq_ops || q->request_fn) || !elv_support_iosched(q))
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
struct elevator_type *elv = NULL;
struct elevator_type *__e;
int len = 0;
if (!blk_queue_stackable(q))
return sprintf(name, "none\n");
if (!q->elevator)
len += sprintf(name+len, "[none] ");
else
elv = e->type;
spin_lock(&elv_list_lock);
list_for_each_entry(__e, &elv_list, list) {
if (elv && !strcmp(elv->elevator_name, __e->elevator_name)) {
len += sprintf(name+len, "[%s] ", elv->elevator_name);
continue;
}
if (__e->uses_mq && q->mq_ops && elv_support_iosched(q))
len += sprintf(name+len, "%s ", __e->elevator_name);
else if (!__e->uses_mq && !q->mq_ops)
len += sprintf(name+len, "%s ", __e->elevator_name);
}
spin_unlock(&elv_list_lock);
if (q->mq_ops && q->elevator)
len += sprintf(name+len, "none");
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
