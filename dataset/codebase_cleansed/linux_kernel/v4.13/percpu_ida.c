static inline void move_tags(unsigned *dst, unsigned *dst_nr,
unsigned *src, unsigned *src_nr,
unsigned nr)
{
*src_nr -= nr;
memcpy(dst + *dst_nr, src + *src_nr, sizeof(unsigned) * nr);
*dst_nr += nr;
}
static inline void steal_tags(struct percpu_ida *pool,
struct percpu_ida_cpu *tags)
{
unsigned cpus_have_tags, cpu = pool->cpu_last_stolen;
struct percpu_ida_cpu *remote;
for (cpus_have_tags = cpumask_weight(&pool->cpus_have_tags);
cpus_have_tags; cpus_have_tags--) {
cpu = cpumask_next(cpu, &pool->cpus_have_tags);
if (cpu >= nr_cpu_ids) {
cpu = cpumask_first(&pool->cpus_have_tags);
if (cpu >= nr_cpu_ids)
BUG();
}
pool->cpu_last_stolen = cpu;
remote = per_cpu_ptr(pool->tag_cpu, cpu);
cpumask_clear_cpu(cpu, &pool->cpus_have_tags);
if (remote == tags)
continue;
spin_lock(&remote->lock);
if (remote->nr_free) {
memcpy(tags->freelist,
remote->freelist,
sizeof(unsigned) * remote->nr_free);
tags->nr_free = remote->nr_free;
remote->nr_free = 0;
}
spin_unlock(&remote->lock);
if (tags->nr_free)
break;
}
}
static inline void alloc_global_tags(struct percpu_ida *pool,
struct percpu_ida_cpu *tags)
{
move_tags(tags->freelist, &tags->nr_free,
pool->freelist, &pool->nr_free,
min(pool->nr_free, pool->percpu_batch_size));
}
static inline unsigned alloc_local_tag(struct percpu_ida_cpu *tags)
{
int tag = -ENOSPC;
spin_lock(&tags->lock);
if (tags->nr_free)
tag = tags->freelist[--tags->nr_free];
spin_unlock(&tags->lock);
return tag;
}
int percpu_ida_alloc(struct percpu_ida *pool, int state)
{
DEFINE_WAIT(wait);
struct percpu_ida_cpu *tags;
unsigned long flags;
int tag;
local_irq_save(flags);
tags = this_cpu_ptr(pool->tag_cpu);
tag = alloc_local_tag(tags);
if (likely(tag >= 0)) {
local_irq_restore(flags);
return tag;
}
while (1) {
spin_lock(&pool->lock);
if (state != TASK_RUNNING)
prepare_to_wait(&pool->wait, &wait, state);
if (!tags->nr_free)
alloc_global_tags(pool, tags);
if (!tags->nr_free)
steal_tags(pool, tags);
if (tags->nr_free) {
tag = tags->freelist[--tags->nr_free];
if (tags->nr_free)
cpumask_set_cpu(smp_processor_id(),
&pool->cpus_have_tags);
}
spin_unlock(&pool->lock);
local_irq_restore(flags);
if (tag >= 0 || state == TASK_RUNNING)
break;
if (signal_pending_state(state, current)) {
tag = -ERESTARTSYS;
break;
}
schedule();
local_irq_save(flags);
tags = this_cpu_ptr(pool->tag_cpu);
}
if (state != TASK_RUNNING)
finish_wait(&pool->wait, &wait);
return tag;
}
void percpu_ida_free(struct percpu_ida *pool, unsigned tag)
{
struct percpu_ida_cpu *tags;
unsigned long flags;
unsigned nr_free;
BUG_ON(tag >= pool->nr_tags);
local_irq_save(flags);
tags = this_cpu_ptr(pool->tag_cpu);
spin_lock(&tags->lock);
tags->freelist[tags->nr_free++] = tag;
nr_free = tags->nr_free;
spin_unlock(&tags->lock);
if (nr_free == 1) {
cpumask_set_cpu(smp_processor_id(),
&pool->cpus_have_tags);
wake_up(&pool->wait);
}
if (nr_free == pool->percpu_max_size) {
spin_lock(&pool->lock);
if (tags->nr_free == pool->percpu_max_size) {
move_tags(pool->freelist, &pool->nr_free,
tags->freelist, &tags->nr_free,
pool->percpu_batch_size);
wake_up(&pool->wait);
}
spin_unlock(&pool->lock);
}
local_irq_restore(flags);
}
void percpu_ida_destroy(struct percpu_ida *pool)
{
free_percpu(pool->tag_cpu);
free_pages((unsigned long) pool->freelist,
get_order(pool->nr_tags * sizeof(unsigned)));
}
int __percpu_ida_init(struct percpu_ida *pool, unsigned long nr_tags,
unsigned long max_size, unsigned long batch_size)
{
unsigned i, cpu, order;
memset(pool, 0, sizeof(*pool));
init_waitqueue_head(&pool->wait);
spin_lock_init(&pool->lock);
pool->nr_tags = nr_tags;
pool->percpu_max_size = max_size;
pool->percpu_batch_size = batch_size;
if (nr_tags > (unsigned) INT_MAX + 1) {
pr_err("percpu_ida_init(): nr_tags too large\n");
return -EINVAL;
}
order = get_order(nr_tags * sizeof(unsigned));
pool->freelist = (void *) __get_free_pages(GFP_KERNEL, order);
if (!pool->freelist)
return -ENOMEM;
for (i = 0; i < nr_tags; i++)
pool->freelist[i] = i;
pool->nr_free = nr_tags;
pool->tag_cpu = __alloc_percpu(sizeof(struct percpu_ida_cpu) +
pool->percpu_max_size * sizeof(unsigned),
sizeof(unsigned));
if (!pool->tag_cpu)
goto err;
for_each_possible_cpu(cpu)
spin_lock_init(&per_cpu_ptr(pool->tag_cpu, cpu)->lock);
return 0;
err:
percpu_ida_destroy(pool);
return -ENOMEM;
}
int percpu_ida_for_each_free(struct percpu_ida *pool, percpu_ida_cb fn,
void *data)
{
unsigned long flags;
struct percpu_ida_cpu *remote;
unsigned cpu, i, err = 0;
local_irq_save(flags);
for_each_possible_cpu(cpu) {
remote = per_cpu_ptr(pool->tag_cpu, cpu);
spin_lock(&remote->lock);
for (i = 0; i < remote->nr_free; i++) {
err = fn(remote->freelist[i], data);
if (err)
break;
}
spin_unlock(&remote->lock);
if (err)
goto out;
}
spin_lock(&pool->lock);
for (i = 0; i < pool->nr_free; i++) {
err = fn(pool->freelist[i], data);
if (err)
break;
}
spin_unlock(&pool->lock);
out:
local_irq_restore(flags);
return err;
}
unsigned percpu_ida_free_tags(struct percpu_ida *pool, int cpu)
{
struct percpu_ida_cpu *remote;
if (cpu == nr_cpu_ids)
return pool->nr_free;
remote = per_cpu_ptr(pool->tag_cpu, cpu);
return remote->nr_free;
}
