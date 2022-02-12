static struct flushlist_node *ramster_flnode_alloc(struct tmem_pool *pool)
{
struct flushlist_node *flnode = NULL;
struct ramster_preload *kp;
kp = &__get_cpu_var(ramster_preloads);
flnode = kp->flnode;
BUG_ON(flnode == NULL);
kp->flnode = NULL;
inc_ramster_flnodes();
return flnode;
}
static void ramster_flnode_free(struct flushlist_node *flnode,
struct tmem_pool *pool)
{
dec_ramster_flnodes();
BUG_ON(ramster_flnodes < 0);
kmem_cache_free(ramster_flnode_cache, flnode);
}
int ramster_do_preload_flnode(struct tmem_pool *pool)
{
struct ramster_preload *kp;
struct flushlist_node *flnode;
int ret = -ENOMEM;
BUG_ON(!irqs_disabled());
if (unlikely(ramster_flnode_cache == NULL))
BUG();
kp = &__get_cpu_var(ramster_preloads);
flnode = kmem_cache_alloc(ramster_flnode_cache, GFP_ATOMIC);
if (unlikely(flnode == NULL) && kp->flnode == NULL)
BUG();
else if (kp->flnode == NULL)
kp->flnode = flnode;
else
kmem_cache_free(ramster_flnode_cache, flnode);
return ret;
}
int ramster_localify(int pool_id, struct tmem_oid *oidp, uint32_t index,
char *data, unsigned int size, void *extra)
{
int ret = -ENOENT;
unsigned long flags;
struct tmem_pool *pool;
bool eph, delete = false;
void *pampd, *saved_hb;
struct tmem_obj *obj;
pool = zcache_get_pool_by_id(LOCAL_CLIENT, pool_id);
if (unlikely(pool == NULL))
goto out;
eph = is_ephemeral(pool);
local_irq_save(flags);
pampd = tmem_localify_get_pampd(pool, oidp, index, &obj, &saved_hb);
if (pampd == NULL) {
#ifdef RAMSTER_TESTING
pr_err("UNTESTED pampd==NULL in ramster_localify\n");
#endif
if (eph)
inc_ramster_remote_eph_pages_unsucc_get();
else
inc_ramster_remote_pers_pages_unsucc_get();
obj = NULL;
goto finish;
} else if (unlikely(!pampd_is_remote(pampd))) {
#ifdef RAMSTER_TESTING
pr_err("UNTESTED dup while waiting in ramster_localify\n");
#endif
if (eph)
inc_ramster_remote_eph_pages_unsucc_get();
else
inc_ramster_remote_pers_pages_unsucc_get();
obj = NULL;
pampd = NULL;
ret = -EEXIST;
goto finish;
} else if (size == 0) {
pampd = NULL;
if (eph)
inc_ramster_remote_eph_pages_unsucc_get();
else
BUG();
delete = true;
goto finish;
}
if (pampd_is_intransit(pampd)) {
BUG_ON(eph);
pampd = pampd_mask_intransit_and_remote(pampd);
zbud_copy_to_zbud(pampd, data, size);
} else {
pampd = NULL;
obj = NULL;
}
BUG_ON(extra == NULL);
zcache_decompress_to_page(data, size, (struct page *)extra);
if (eph)
inc_ramster_remote_eph_pages_succ_get();
else
inc_ramster_remote_pers_pages_succ_get();
ret = 0;
finish:
tmem_localify_finish(obj, index, pampd, saved_hb, delete);
zcache_put_pool(pool);
local_irq_restore(flags);
out:
return ret;
}
void ramster_pampd_new_obj(struct tmem_obj *obj)
{
obj->extra = NULL;
}
void ramster_pampd_free_obj(struct tmem_pool *pool, struct tmem_obj *obj,
bool pool_destroy)
{
struct flushlist_node *flnode;
BUG_ON(preemptible());
if (obj->extra == NULL)
return;
if (pool_destroy && is_ephemeral(pool))
return;
BUG_ON(!pampd_is_remote(obj->extra));
flnode = ramster_flnode_alloc(pool);
flnode->xh.client_id = pampd_remote_node(obj->extra);
flnode->xh.pool_id = pool->pool_id;
flnode->xh.oid = obj->oid;
flnode->xh.index = FLUSH_ENTIRE_OBJECT;
flnode->rem_op.op = RAMSTER_REMOTIFY_FLUSH_OBJ;
spin_lock(&ramster_rem_op_list_lock);
list_add(&flnode->rem_op.list, &ramster_rem_op_list);
spin_unlock(&ramster_rem_op_list_lock);
}
void *ramster_pampd_repatriate_preload(void *pampd, struct tmem_pool *pool,
struct tmem_oid *oidp, uint32_t index,
bool *intransit)
{
int clen = pampd_remote_size(pampd), c;
void *ret_pampd = NULL;
unsigned long flags;
struct tmem_handle th;
BUG_ON(!pampd_is_remote(pampd));
BUG_ON(is_ephemeral(pool));
if (use_frontswap_exclusive_gets)
goto out;
if (pampd_is_intransit(pampd)) {
*intransit = true;
goto out;
}
*intransit = false;
local_irq_save(flags);
th.client_id = pampd_remote_node(pampd);
th.pool_id = pool->pool_id;
th.oid = *oidp;
th.index = index;
ret_pampd = zcache_pampd_create(NULL, clen, true, false, &th);
if (ret_pampd != NULL) {
ret_pampd = pampd_mark_intransit(ret_pampd);
c = atomic_dec_return(&ramster_remote_pers_pages);
WARN_ON_ONCE(c < 0);
} else {
inc_ramster_pers_pages_remote_nomem();
}
local_irq_restore(flags);
out:
return ret_pampd;
}
int ramster_pampd_repatriate(void *fake_pampd, void *real_pampd,
struct tmem_pool *pool,
struct tmem_oid *oid, uint32_t index,
bool free, void *extra)
{
struct tmem_xhandle xh;
int ret;
if (pampd_is_intransit(real_pampd))
free = true;
xh = tmem_xhandle_fill(LOCAL_CLIENT, pool, oid, index);
ret = r2net_remote_async_get(&xh, free,
pampd_remote_node(fake_pampd),
pampd_remote_size(fake_pampd),
pampd_remote_cksum(fake_pampd),
extra);
return ret;
}
bool ramster_pampd_is_remote(void *pampd)
{
return pampd_is_remote(pampd);
}
int ramster_pampd_replace_in_obj(void *new_pampd, struct tmem_obj *obj)
{
int ret = -1;
if (new_pampd != NULL) {
if (obj->extra == NULL)
obj->extra = new_pampd;
else if (pampd_remote_node(new_pampd) !=
pampd_remote_node((void *)(obj->extra)))
BUG();
ret = 0;
}
return ret;
}
void *ramster_pampd_free(void *pampd, struct tmem_pool *pool,
struct tmem_oid *oid, uint32_t index, bool acct)
{
bool eph = is_ephemeral(pool);
void *local_pampd = NULL;
int c;
BUG_ON(preemptible());
BUG_ON(!pampd_is_remote(pampd));
WARN_ON(acct == false);
if (oid == NULL) {
} else if (eph) {
} else if (pampd_is_intransit(pampd)) {
local_pampd = pampd_mask_intransit_and_remote(pampd);
} else {
struct flushlist_node *flnode =
ramster_flnode_alloc(pool);
flnode->xh.client_id = pampd_remote_node(pampd);
flnode->xh.pool_id = pool->pool_id;
flnode->xh.oid = *oid;
flnode->xh.index = index;
flnode->rem_op.op = RAMSTER_REMOTIFY_FLUSH_PAGE;
spin_lock(&ramster_rem_op_list_lock);
list_add(&flnode->rem_op.list, &ramster_rem_op_list);
spin_unlock(&ramster_rem_op_list_lock);
c = atomic_dec_return(&ramster_remote_pers_pages);
WARN_ON_ONCE(c < 0);
}
return local_pampd;
}
void ramster_count_foreign_pages(bool eph, int count)
{
BUG_ON(count != 1 && count != -1);
if (eph) {
if (count > 0) {
inc_ramster_foreign_eph_pages();
} else {
dec_ramster_foreign_eph_pages();
#ifdef CONFIG_RAMSTER_DEBUG
WARN_ON_ONCE(ramster_foreign_eph_pages < 0);
#endif
}
} else {
if (count > 0) {
inc_ramster_foreign_pers_pages();
} else {
dec_ramster_foreign_pers_pages();
#ifdef CONFIG_RAMSTER_DEBUG
WARN_ON_ONCE(ramster_foreign_pers_pages < 0);
#endif
}
}
}
static void ramster_remotify_queue_delayed_work(unsigned long delay)
{
if (!queue_delayed_work(ramster_remotify_workqueue,
&ramster_remotify_worker, delay))
pr_err("ramster_remotify: bad workqueue\n");
}
static void ramster_remote_flush_page(struct flushlist_node *flnode)
{
struct tmem_xhandle *xh;
int remotenode, ret;
preempt_disable();
xh = &flnode->xh;
remotenode = flnode->xh.client_id;
ret = r2net_remote_flush(xh, remotenode);
if (ret >= 0)
inc_ramster_remote_pages_flushed();
else
inc_ramster_remote_page_flushes_failed();
preempt_enable_no_resched();
ramster_flnode_free(flnode, NULL);
}
static void ramster_remote_flush_object(struct flushlist_node *flnode)
{
struct tmem_xhandle *xh;
int remotenode, ret;
preempt_disable();
xh = &flnode->xh;
remotenode = flnode->xh.client_id;
ret = r2net_remote_flush_object(xh, remotenode);
if (ret >= 0)
inc_ramster_remote_objects_flushed();
else
inc_ramster_remote_object_flushes_failed();
preempt_enable_no_resched();
ramster_flnode_free(flnode, NULL);
}
int ramster_remotify_pageframe(bool eph)
{
struct tmem_xhandle xh;
unsigned int size;
int remotenode, ret, zbuds;
struct tmem_pool *pool;
unsigned long flags;
unsigned char cksum;
char *p;
int i, j;
unsigned char *tmpmem[2];
struct tmem_handle th[2];
unsigned int zsize[2];
tmpmem[0] = __get_cpu_var(ramster_remoteputmem1);
tmpmem[1] = __get_cpu_var(ramster_remoteputmem2);
local_bh_disable();
zbuds = zbud_make_zombie_lru(&th[0], &tmpmem[0], &zsize[0], eph);
local_bh_enable();
if (zbuds == 0)
goto out;
BUG_ON(zbuds > 2);
for (i = 0; i < zbuds; i++) {
xh.client_id = th[i].client_id;
xh.pool_id = th[i].pool_id;
xh.oid = th[i].oid;
xh.index = th[i].index;
size = zsize[i];
BUG_ON(size == 0 || size > zbud_max_buddy_size());
for (p = tmpmem[i], cksum = 0, j = 0; j < size; j++)
cksum += *p++;
ret = r2net_remote_put(&xh, tmpmem[i], size, eph, &remotenode);
if (ret != 0) {
if (eph)
inc_ramster_eph_pages_remote_failed();
else
inc_ramster_pers_pages_remote_failed();
break;
} else {
if (!eph)
atomic_inc(&ramster_remote_pers_pages);
}
if (eph)
inc_ramster_eph_pages_remoted();
else
inc_ramster_pers_pages_remoted();
local_bh_disable();
pool = zcache_get_pool_by_id(LOCAL_CLIENT, xh.pool_id);
local_irq_save(flags);
(void)tmem_replace(pool, &xh.oid, xh.index,
pampd_make_remote(remotenode, size, cksum));
local_irq_restore(flags);
zcache_put_pool(pool);
local_bh_enable();
}
out:
return zbuds;
}
static void zcache_do_remotify_flushes(void)
{
struct ramster_remotify_hdr *rem_op;
union remotify_list_node *u;
while (1) {
spin_lock(&ramster_rem_op_list_lock);
if (list_empty(&ramster_rem_op_list)) {
spin_unlock(&ramster_rem_op_list_lock);
goto out;
}
rem_op = list_first_entry(&ramster_rem_op_list,
struct ramster_remotify_hdr, list);
list_del_init(&rem_op->list);
spin_unlock(&ramster_rem_op_list_lock);
u = (union remotify_list_node *)rem_op;
switch (rem_op->op) {
case RAMSTER_REMOTIFY_FLUSH_PAGE:
ramster_remote_flush_page((struct flushlist_node *)u);
break;
case RAMSTER_REMOTIFY_FLUSH_OBJ:
ramster_remote_flush_object((struct flushlist_node *)u);
break;
default:
BUG();
}
}
out:
return;
}
static void ramster_remotify_process(struct work_struct *work)
{
static bool remotify_in_progress;
int i;
BUG_ON(irqs_disabled());
if (remotify_in_progress)
goto requeue;
if (ramster_remote_target_nodenum == -1)
goto requeue;
remotify_in_progress = true;
if (use_cleancache && ramster_eph_remotify_enable) {
for (i = 0; i < 100; i++) {
zcache_do_remotify_flushes();
(void)ramster_remotify_pageframe(true);
}
}
if (use_frontswap && ramster_pers_remotify_enable) {
for (i = 0; i < 100; i++) {
zcache_do_remotify_flushes();
(void)ramster_remotify_pageframe(false);
}
}
remotify_in_progress = false;
requeue:
ramster_remotify_queue_delayed_work(HZ);
}
void ramster_remotify_init(void)
{
unsigned long n = 60UL;
ramster_remotify_workqueue =
create_singlethread_workqueue("ramster_remotify");
ramster_remotify_queue_delayed_work(n * HZ);
}
static ssize_t ramster_manual_node_up_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
int i;
char *p = buf;
for (i = 0; i < MANUAL_NODES; i++)
if (ramster_nodes_manual_up[i])
p += sprintf(p, "%d ", i);
p += sprintf(p, "\n");
return p - buf;
}
static ssize_t ramster_manual_node_up_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
int err;
unsigned long node_num;
err = kstrtoul(buf, 10, &node_num);
if (err) {
pr_err("ramster: bad strtoul?\n");
return -EINVAL;
}
if (node_num >= MANUAL_NODES) {
pr_err("ramster: bad node_num=%lu?\n", node_num);
return -EINVAL;
}
if (ramster_nodes_manual_up[node_num]) {
pr_err("ramster: node %d already up, ignoring\n",
(int)node_num);
} else {
ramster_nodes_manual_up[node_num] = true;
r2net_hb_node_up_manual((int)node_num);
}
return count;
}
static ssize_t ramster_remote_target_nodenum_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
if (ramster_remote_target_nodenum == -1UL)
return sprintf(buf, "unset\n");
else
return sprintf(buf, "%d\n", ramster_remote_target_nodenum);
}
static ssize_t ramster_remote_target_nodenum_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
int err;
unsigned long node_num;
err = kstrtoul(buf, 10, &node_num);
if (err) {
pr_err("ramster: bad strtoul?\n");
return -EINVAL;
} else if (node_num == -1UL) {
pr_err("ramster: disabling all remotification, "
"data may still reside on remote nodes however\n");
return -EINVAL;
} else if (node_num >= MANUAL_NODES) {
pr_err("ramster: bad node_num=%lu?\n", node_num);
return -EINVAL;
} else if (!ramster_nodes_manual_up[node_num]) {
pr_err("ramster: node %d not up, ignoring setting "
"of remotification target\n", (int)node_num);
} else if (r2net_remote_target_node_set((int)node_num) >= 0) {
pr_info("ramster: node %d set as remotification target\n",
(int)node_num);
ramster_remote_target_nodenum = (int)node_num;
} else {
pr_err("ramster: bad num to node node_num=%d?\n",
(int)node_num);
return -EINVAL;
}
return count;
}
static void frontswap_selfshrink(void)
{
static unsigned long cur_frontswap_pages;
static unsigned long last_frontswap_pages;
static unsigned long tgt_frontswap_pages;
last_frontswap_pages = cur_frontswap_pages;
cur_frontswap_pages = frontswap_curr_pages();
if (!cur_frontswap_pages ||
(cur_frontswap_pages > last_frontswap_pages)) {
frontswap_inertia_counter = frontswap_inertia;
return;
}
if (frontswap_inertia_counter && --frontswap_inertia_counter)
return;
if (cur_frontswap_pages <= frontswap_hysteresis)
tgt_frontswap_pages = 0;
else
tgt_frontswap_pages = cur_frontswap_pages -
(cur_frontswap_pages / frontswap_hysteresis);
frontswap_shrink(tgt_frontswap_pages);
}
static int __init ramster_nofrontswap_selfshrink_setup(char *s)
{
use_frontswap_selfshrink = false;
return 1;
}
static void selfshrink_process(struct work_struct *work)
{
if (frontswap_selfshrinking && frontswap_enabled) {
frontswap_selfshrink();
schedule_delayed_work(&selfshrink_worker,
selfshrink_interval * HZ);
}
}
void ramster_cpu_up(int cpu)
{
unsigned char *p1 = kzalloc(PAGE_SIZE, GFP_KERNEL | __GFP_REPEAT);
unsigned char *p2 = kzalloc(PAGE_SIZE, GFP_KERNEL | __GFP_REPEAT);
BUG_ON(!p1 || !p2);
per_cpu(ramster_remoteputmem1, cpu) = p1;
per_cpu(ramster_remoteputmem2, cpu) = p2;
}
void ramster_cpu_down(int cpu)
{
struct ramster_preload *kp;
kfree(per_cpu(ramster_remoteputmem1, cpu));
per_cpu(ramster_remoteputmem1, cpu) = NULL;
kfree(per_cpu(ramster_remoteputmem2, cpu));
per_cpu(ramster_remoteputmem2, cpu) = NULL;
kp = &per_cpu(ramster_preloads, cpu);
if (kp->flnode) {
kmem_cache_free(ramster_flnode_cache, kp->flnode);
kp->flnode = NULL;
}
}
void ramster_register_pamops(struct tmem_pamops *pamops)
{
pamops->free_obj = ramster_pampd_free_obj;
pamops->new_obj = ramster_pampd_new_obj;
pamops->replace_in_obj = ramster_pampd_replace_in_obj;
pamops->is_remote = ramster_pampd_is_remote;
pamops->repatriate = ramster_pampd_repatriate;
pamops->repatriate_preload = ramster_pampd_repatriate_preload;
}
void ramster_init(bool cleancache, bool frontswap,
bool frontswap_exclusive_gets,
bool frontswap_selfshrink)
{
int ret = 0;
if (cleancache)
use_cleancache = true;
if (frontswap)
use_frontswap = true;
if (frontswap_exclusive_gets)
use_frontswap_exclusive_gets = true;
ramster_debugfs_init();
ret = sysfs_create_group(mm_kobj, &ramster_attr_group);
if (ret)
pr_err("ramster: can't create sysfs for ramster\n");
(void)r2net_register_handlers();
#ifdef CONFIG_RAMSTER_MODULE
ret = r2nm_init();
if (ret)
pr_err("ramster: can't init r2net\n");
frontswap_selfshrinking = frontswap_selfshrink;
#else
frontswap_selfshrinking = use_frontswap_selfshrink;
#endif
INIT_LIST_HEAD(&ramster_rem_op_list);
ramster_flnode_cache = kmem_cache_create("ramster_flnode",
sizeof(struct flushlist_node), 0, 0, NULL);
if (frontswap_selfshrinking) {
pr_info("ramster: Initializing frontswap selfshrink driver.\n");
schedule_delayed_work(&selfshrink_worker,
selfshrink_interval * HZ);
}
ramster_remotify_init();
}
