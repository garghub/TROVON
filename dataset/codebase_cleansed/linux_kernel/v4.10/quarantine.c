static bool qlist_empty(struct qlist_head *q)
{
return !q->head;
}
static void qlist_init(struct qlist_head *q)
{
q->head = q->tail = NULL;
q->bytes = 0;
}
static void qlist_put(struct qlist_head *q, struct qlist_node *qlink,
size_t size)
{
if (unlikely(qlist_empty(q)))
q->head = qlink;
else
q->tail->next = qlink;
q->tail = qlink;
qlink->next = NULL;
q->bytes += size;
}
static void qlist_move_all(struct qlist_head *from, struct qlist_head *to)
{
if (unlikely(qlist_empty(from)))
return;
if (qlist_empty(to)) {
*to = *from;
qlist_init(from);
return;
}
to->tail->next = from->head;
to->tail = from->tail;
to->bytes += from->bytes;
qlist_init(from);
}
static struct kmem_cache *qlink_to_cache(struct qlist_node *qlink)
{
return virt_to_head_page(qlink)->slab_cache;
}
static void *qlink_to_object(struct qlist_node *qlink, struct kmem_cache *cache)
{
struct kasan_free_meta *free_info =
container_of(qlink, struct kasan_free_meta,
quarantine_link);
return ((void *)free_info) - cache->kasan_info.free_meta_offset;
}
static void qlink_free(struct qlist_node *qlink, struct kmem_cache *cache)
{
void *object = qlink_to_object(qlink, cache);
unsigned long flags;
if (IS_ENABLED(CONFIG_SLAB))
local_irq_save(flags);
___cache_free(cache, object, _THIS_IP_);
if (IS_ENABLED(CONFIG_SLAB))
local_irq_restore(flags);
}
static void qlist_free_all(struct qlist_head *q, struct kmem_cache *cache)
{
struct qlist_node *qlink;
if (unlikely(qlist_empty(q)))
return;
qlink = q->head;
while (qlink) {
struct kmem_cache *obj_cache =
cache ? cache : qlink_to_cache(qlink);
struct qlist_node *next = qlink->next;
qlink_free(qlink, obj_cache);
qlink = next;
}
qlist_init(q);
}
void quarantine_put(struct kasan_free_meta *info, struct kmem_cache *cache)
{
unsigned long flags;
struct qlist_head *q;
struct qlist_head temp = QLIST_INIT;
local_irq_save(flags);
q = this_cpu_ptr(&cpu_quarantine);
qlist_put(q, &info->quarantine_link, cache->size);
if (unlikely(q->bytes > QUARANTINE_PERCPU_SIZE))
qlist_move_all(q, &temp);
local_irq_restore(flags);
if (unlikely(!qlist_empty(&temp))) {
spin_lock_irqsave(&quarantine_lock, flags);
WRITE_ONCE(quarantine_size, quarantine_size + temp.bytes);
qlist_move_all(&temp, &global_quarantine[quarantine_tail]);
if (global_quarantine[quarantine_tail].bytes >=
READ_ONCE(quarantine_batch_size)) {
int new_tail;
new_tail = quarantine_tail + 1;
if (new_tail == QUARANTINE_BATCHES)
new_tail = 0;
if (new_tail != quarantine_head)
quarantine_tail = new_tail;
}
spin_unlock_irqrestore(&quarantine_lock, flags);
}
}
void quarantine_reduce(void)
{
size_t total_size, new_quarantine_size, percpu_quarantines;
unsigned long flags;
struct qlist_head to_free = QLIST_INIT;
if (likely(READ_ONCE(quarantine_size) <=
READ_ONCE(quarantine_max_size)))
return;
spin_lock_irqsave(&quarantine_lock, flags);
total_size = (READ_ONCE(totalram_pages) << PAGE_SHIFT) /
QUARANTINE_FRACTION;
percpu_quarantines = QUARANTINE_PERCPU_SIZE * num_online_cpus();
new_quarantine_size = (total_size < percpu_quarantines) ?
0 : total_size - percpu_quarantines;
WRITE_ONCE(quarantine_max_size, new_quarantine_size);
WRITE_ONCE(quarantine_batch_size, max((size_t)QUARANTINE_PERCPU_SIZE,
2 * total_size / QUARANTINE_BATCHES));
if (likely(quarantine_size > quarantine_max_size)) {
qlist_move_all(&global_quarantine[quarantine_head], &to_free);
WRITE_ONCE(quarantine_size, quarantine_size - to_free.bytes);
quarantine_head++;
if (quarantine_head == QUARANTINE_BATCHES)
quarantine_head = 0;
}
spin_unlock_irqrestore(&quarantine_lock, flags);
qlist_free_all(&to_free, NULL);
}
static void qlist_move_cache(struct qlist_head *from,
struct qlist_head *to,
struct kmem_cache *cache)
{
struct qlist_node *curr;
if (unlikely(qlist_empty(from)))
return;
curr = from->head;
qlist_init(from);
while (curr) {
struct qlist_node *next = curr->next;
struct kmem_cache *obj_cache = qlink_to_cache(curr);
if (obj_cache == cache)
qlist_put(to, curr, obj_cache->size);
else
qlist_put(from, curr, obj_cache->size);
curr = next;
}
}
static void per_cpu_remove_cache(void *arg)
{
struct kmem_cache *cache = arg;
struct qlist_head to_free = QLIST_INIT;
struct qlist_head *q;
q = this_cpu_ptr(&cpu_quarantine);
qlist_move_cache(q, &to_free, cache);
qlist_free_all(&to_free, cache);
}
void quarantine_remove_cache(struct kmem_cache *cache)
{
unsigned long flags, i;
struct qlist_head to_free = QLIST_INIT;
on_each_cpu(per_cpu_remove_cache, cache, 1);
spin_lock_irqsave(&quarantine_lock, flags);
for (i = 0; i < QUARANTINE_BATCHES; i++)
qlist_move_cache(&global_quarantine[i], &to_free, cache);
spin_unlock_irqrestore(&quarantine_lock, flags);
qlist_free_all(&to_free, cache);
}
