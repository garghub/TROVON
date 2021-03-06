static void flow_cache_new_hashrnd(unsigned long arg)
{
struct flow_cache *fc = (void *) arg;
int i;
for_each_possible_cpu(i)
per_cpu_ptr(fc->percpu, i)->hash_rnd_recalc = 1;
fc->rnd_timer.expires = jiffies + FLOW_HASH_RND_PERIOD;
add_timer(&fc->rnd_timer);
}
static int flow_entry_valid(struct flow_cache_entry *fle)
{
if (atomic_read(&flow_cache_genid) != fle->genid)
return 0;
if (fle->object && !fle->object->ops->check(fle->object))
return 0;
return 1;
}
static void flow_entry_kill(struct flow_cache_entry *fle)
{
if (fle->object)
fle->object->ops->delete(fle->object);
kmem_cache_free(flow_cachep, fle);
}
static void flow_cache_gc_task(struct work_struct *work)
{
struct list_head gc_list;
struct flow_cache_entry *fce, *n;
INIT_LIST_HEAD(&gc_list);
spin_lock_bh(&flow_cache_gc_lock);
list_splice_tail_init(&flow_cache_gc_list, &gc_list);
spin_unlock_bh(&flow_cache_gc_lock);
list_for_each_entry_safe(fce, n, &gc_list, u.gc_list)
flow_entry_kill(fce);
}
static void flow_cache_queue_garbage(struct flow_cache_percpu *fcp,
int deleted, struct list_head *gc_list)
{
if (deleted) {
fcp->hash_count -= deleted;
spin_lock_bh(&flow_cache_gc_lock);
list_splice_tail(gc_list, &flow_cache_gc_list);
spin_unlock_bh(&flow_cache_gc_lock);
schedule_work(&flow_cache_gc_work);
}
}
static void __flow_cache_shrink(struct flow_cache *fc,
struct flow_cache_percpu *fcp,
int shrink_to)
{
struct flow_cache_entry *fle;
struct hlist_node *entry, *tmp;
LIST_HEAD(gc_list);
int i, deleted = 0;
for (i = 0; i < flow_cache_hash_size(fc); i++) {
int saved = 0;
hlist_for_each_entry_safe(fle, entry, tmp,
&fcp->hash_table[i], u.hlist) {
if (saved < shrink_to &&
flow_entry_valid(fle)) {
saved++;
} else {
deleted++;
hlist_del(&fle->u.hlist);
list_add_tail(&fle->u.gc_list, &gc_list);
}
}
}
flow_cache_queue_garbage(fcp, deleted, &gc_list);
}
static void flow_cache_shrink(struct flow_cache *fc,
struct flow_cache_percpu *fcp)
{
int shrink_to = fc->low_watermark / flow_cache_hash_size(fc);
__flow_cache_shrink(fc, fcp, shrink_to);
}
static void flow_new_hash_rnd(struct flow_cache *fc,
struct flow_cache_percpu *fcp)
{
get_random_bytes(&fcp->hash_rnd, sizeof(u32));
fcp->hash_rnd_recalc = 0;
__flow_cache_shrink(fc, fcp, 0);
}
static u32 flow_hash_code(struct flow_cache *fc,
struct flow_cache_percpu *fcp,
const struct flowi *key,
size_t keysize)
{
const u32 *k = (const u32 *) key;
const u32 length = keysize * sizeof(flow_compare_t) / sizeof(u32);
return jhash2(k, length, fcp->hash_rnd)
& (flow_cache_hash_size(fc) - 1);
}
static int flow_key_compare(const struct flowi *key1, const struct flowi *key2,
size_t keysize)
{
const flow_compare_t *k1, *k1_lim, *k2;
k1 = (const flow_compare_t *) key1;
k1_lim = k1 + keysize;
k2 = (const flow_compare_t *) key2;
do {
if (*k1++ != *k2++)
return 1;
} while (k1 < k1_lim);
return 0;
}
struct flow_cache_object *
flow_cache_lookup(struct net *net, const struct flowi *key, u16 family, u8 dir,
flow_resolve_t resolver, void *ctx)
{
struct flow_cache *fc = &flow_cache_global;
struct flow_cache_percpu *fcp;
struct flow_cache_entry *fle, *tfle;
struct hlist_node *entry;
struct flow_cache_object *flo;
size_t keysize;
unsigned int hash;
local_bh_disable();
fcp = this_cpu_ptr(fc->percpu);
fle = NULL;
flo = NULL;
keysize = flow_key_size(family);
if (!keysize)
goto nocache;
if (!fcp->hash_table)
goto nocache;
if (fcp->hash_rnd_recalc)
flow_new_hash_rnd(fc, fcp);
hash = flow_hash_code(fc, fcp, key, keysize);
hlist_for_each_entry(tfle, entry, &fcp->hash_table[hash], u.hlist) {
if (tfle->net == net &&
tfle->family == family &&
tfle->dir == dir &&
flow_key_compare(key, &tfle->key, keysize) == 0) {
fle = tfle;
break;
}
}
if (unlikely(!fle)) {
if (fcp->hash_count > fc->high_watermark)
flow_cache_shrink(fc, fcp);
fle = kmem_cache_alloc(flow_cachep, GFP_ATOMIC);
if (fle) {
fle->net = net;
fle->family = family;
fle->dir = dir;
memcpy(&fle->key, key, keysize * sizeof(flow_compare_t));
fle->object = NULL;
hlist_add_head(&fle->u.hlist, &fcp->hash_table[hash]);
fcp->hash_count++;
}
} else if (likely(fle->genid == atomic_read(&flow_cache_genid))) {
flo = fle->object;
if (!flo)
goto ret_object;
flo = flo->ops->get(flo);
if (flo)
goto ret_object;
} else if (fle->object) {
flo = fle->object;
flo->ops->delete(flo);
fle->object = NULL;
}
nocache:
flo = NULL;
if (fle) {
flo = fle->object;
fle->object = NULL;
}
flo = resolver(net, key, family, dir, flo, ctx);
if (fle) {
fle->genid = atomic_read(&flow_cache_genid);
if (!IS_ERR(flo))
fle->object = flo;
else
fle->genid--;
} else {
if (flo && !IS_ERR(flo))
flo->ops->delete(flo);
}
ret_object:
local_bh_enable();
return flo;
}
static void flow_cache_flush_tasklet(unsigned long data)
{
struct flow_flush_info *info = (void *)data;
struct flow_cache *fc = info->cache;
struct flow_cache_percpu *fcp;
struct flow_cache_entry *fle;
struct hlist_node *entry, *tmp;
LIST_HEAD(gc_list);
int i, deleted = 0;
fcp = this_cpu_ptr(fc->percpu);
for (i = 0; i < flow_cache_hash_size(fc); i++) {
hlist_for_each_entry_safe(fle, entry, tmp,
&fcp->hash_table[i], u.hlist) {
if (flow_entry_valid(fle))
continue;
deleted++;
hlist_del(&fle->u.hlist);
list_add_tail(&fle->u.gc_list, &gc_list);
}
}
flow_cache_queue_garbage(fcp, deleted, &gc_list);
if (atomic_dec_and_test(&info->cpuleft))
complete(&info->completion);
}
static void flow_cache_flush_per_cpu(void *data)
{
struct flow_flush_info *info = data;
int cpu;
struct tasklet_struct *tasklet;
cpu = smp_processor_id();
tasklet = &per_cpu_ptr(info->cache->percpu, cpu)->flush_tasklet;
tasklet->data = (unsigned long)info;
tasklet_schedule(tasklet);
}
void flow_cache_flush(void)
{
struct flow_flush_info info;
static DEFINE_MUTEX(flow_flush_sem);
get_online_cpus();
mutex_lock(&flow_flush_sem);
info.cache = &flow_cache_global;
atomic_set(&info.cpuleft, num_online_cpus());
init_completion(&info.completion);
local_bh_disable();
smp_call_function(flow_cache_flush_per_cpu, &info, 0);
flow_cache_flush_tasklet((unsigned long)&info);
local_bh_enable();
wait_for_completion(&info.completion);
mutex_unlock(&flow_flush_sem);
put_online_cpus();
}
static int __cpuinit flow_cache_cpu_prepare(struct flow_cache *fc, int cpu)
{
struct flow_cache_percpu *fcp = per_cpu_ptr(fc->percpu, cpu);
size_t sz = sizeof(struct hlist_head) * flow_cache_hash_size(fc);
if (!fcp->hash_table) {
fcp->hash_table = kzalloc_node(sz, GFP_KERNEL, cpu_to_node(cpu));
if (!fcp->hash_table) {
pr_err("NET: failed to allocate flow cache sz %zu\n", sz);
return -ENOMEM;
}
fcp->hash_rnd_recalc = 1;
fcp->hash_count = 0;
tasklet_init(&fcp->flush_tasklet, flow_cache_flush_tasklet, 0);
}
return 0;
}
static int __cpuinit flow_cache_cpu(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
struct flow_cache *fc = container_of(nfb, struct flow_cache, hotcpu_notifier);
int res, cpu = (unsigned long) hcpu;
struct flow_cache_percpu *fcp = per_cpu_ptr(fc->percpu, cpu);
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
res = flow_cache_cpu_prepare(fc, cpu);
if (res)
return notifier_from_errno(res);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
__flow_cache_shrink(fc, fcp, 0);
break;
}
return NOTIFY_OK;
}
static int __init flow_cache_init(struct flow_cache *fc)
{
int i;
fc->hash_shift = 10;
fc->low_watermark = 2 * flow_cache_hash_size(fc);
fc->high_watermark = 4 * flow_cache_hash_size(fc);
fc->percpu = alloc_percpu(struct flow_cache_percpu);
if (!fc->percpu)
return -ENOMEM;
for_each_online_cpu(i) {
if (flow_cache_cpu_prepare(fc, i))
return -ENOMEM;
}
fc->hotcpu_notifier = (struct notifier_block){
.notifier_call = flow_cache_cpu,
};
register_hotcpu_notifier(&fc->hotcpu_notifier);
setup_timer(&fc->rnd_timer, flow_cache_new_hashrnd,
(unsigned long) fc);
fc->rnd_timer.expires = jiffies + FLOW_HASH_RND_PERIOD;
add_timer(&fc->rnd_timer);
return 0;
}
static int __init flow_cache_init_global(void)
{
flow_cachep = kmem_cache_create("flow_cache",
sizeof(struct flow_cache_entry),
0, SLAB_PANIC, NULL);
return flow_cache_init(&flow_cache_global);
}
