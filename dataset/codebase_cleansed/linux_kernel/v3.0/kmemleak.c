static void hex_dump_object(struct seq_file *seq,
struct kmemleak_object *object)
{
const u8 *ptr = (const u8 *)object->pointer;
int i, len, remaining;
unsigned char linebuf[HEX_ROW_SIZE * 5];
remaining = len =
min(object->size, (size_t)(HEX_MAX_LINES * HEX_ROW_SIZE));
seq_printf(seq, " hex dump (first %d bytes):\n", len);
for (i = 0; i < len; i += HEX_ROW_SIZE) {
int linelen = min(remaining, HEX_ROW_SIZE);
remaining -= HEX_ROW_SIZE;
hex_dump_to_buffer(ptr + i, linelen, HEX_ROW_SIZE,
HEX_GROUP_SIZE, linebuf, sizeof(linebuf),
HEX_ASCII);
seq_printf(seq, " %s\n", linebuf);
}
}
static bool color_white(const struct kmemleak_object *object)
{
return object->count != KMEMLEAK_BLACK &&
object->count < object->min_count;
}
static bool color_gray(const struct kmemleak_object *object)
{
return object->min_count != KMEMLEAK_BLACK &&
object->count >= object->min_count;
}
static bool unreferenced_object(struct kmemleak_object *object)
{
return (color_white(object) && object->flags & OBJECT_ALLOCATED) &&
time_before_eq(object->jiffies + jiffies_min_age,
jiffies_last_scan);
}
static void print_unreferenced(struct seq_file *seq,
struct kmemleak_object *object)
{
int i;
unsigned int msecs_age = jiffies_to_msecs(jiffies - object->jiffies);
seq_printf(seq, "unreferenced object 0x%08lx (size %zu):\n",
object->pointer, object->size);
seq_printf(seq, " comm \"%s\", pid %d, jiffies %lu (age %d.%03ds)\n",
object->comm, object->pid, object->jiffies,
msecs_age / 1000, msecs_age % 1000);
hex_dump_object(seq, object);
seq_printf(seq, " backtrace:\n");
for (i = 0; i < object->trace_len; i++) {
void *ptr = (void *)object->trace[i];
seq_printf(seq, " [<%p>] %pS\n", ptr, ptr);
}
}
static void dump_object_info(struct kmemleak_object *object)
{
struct stack_trace trace;
trace.nr_entries = object->trace_len;
trace.entries = object->trace;
pr_notice("Object 0x%08lx (size %zu):\n",
object->tree_node.start, object->size);
pr_notice(" comm \"%s\", pid %d, jiffies %lu\n",
object->comm, object->pid, object->jiffies);
pr_notice(" min_count = %d\n", object->min_count);
pr_notice(" count = %d\n", object->count);
pr_notice(" flags = 0x%lx\n", object->flags);
pr_notice(" checksum = %d\n", object->checksum);
pr_notice(" backtrace:\n");
print_stack_trace(&trace, 4);
}
static struct kmemleak_object *lookup_object(unsigned long ptr, int alias)
{
struct prio_tree_node *node;
struct prio_tree_iter iter;
struct kmemleak_object *object;
prio_tree_iter_init(&iter, &object_tree_root, ptr, ptr);
node = prio_tree_next(&iter);
if (node) {
object = prio_tree_entry(node, struct kmemleak_object,
tree_node);
if (!alias && object->pointer != ptr) {
pr_warning("Found object by alias at 0x%08lx\n", ptr);
dump_stack();
dump_object_info(object);
object = NULL;
}
} else
object = NULL;
return object;
}
static int get_object(struct kmemleak_object *object)
{
return atomic_inc_not_zero(&object->use_count);
}
static void free_object_rcu(struct rcu_head *rcu)
{
struct hlist_node *elem, *tmp;
struct kmemleak_scan_area *area;
struct kmemleak_object *object =
container_of(rcu, struct kmemleak_object, rcu);
hlist_for_each_entry_safe(area, elem, tmp, &object->area_list, node) {
hlist_del(elem);
kmem_cache_free(scan_area_cache, area);
}
kmem_cache_free(object_cache, object);
}
static void put_object(struct kmemleak_object *object)
{
if (!atomic_dec_and_test(&object->use_count))
return;
WARN_ON(object->flags & OBJECT_ALLOCATED);
call_rcu(&object->rcu, free_object_rcu);
}
static struct kmemleak_object *find_and_get_object(unsigned long ptr, int alias)
{
unsigned long flags;
struct kmemleak_object *object = NULL;
rcu_read_lock();
read_lock_irqsave(&kmemleak_lock, flags);
if (ptr >= min_addr && ptr < max_addr)
object = lookup_object(ptr, alias);
read_unlock_irqrestore(&kmemleak_lock, flags);
if (object && !get_object(object))
object = NULL;
rcu_read_unlock();
return object;
}
static int __save_stack_trace(unsigned long *trace)
{
struct stack_trace stack_trace;
stack_trace.max_entries = MAX_TRACE;
stack_trace.nr_entries = 0;
stack_trace.entries = trace;
stack_trace.skip = 2;
save_stack_trace(&stack_trace);
return stack_trace.nr_entries;
}
static struct kmemleak_object *create_object(unsigned long ptr, size_t size,
int min_count, gfp_t gfp)
{
unsigned long flags;
struct kmemleak_object *object;
struct prio_tree_node *node;
object = kmem_cache_alloc(object_cache, gfp_kmemleak_mask(gfp));
if (!object) {
pr_warning("Cannot allocate a kmemleak_object structure\n");
kmemleak_disable();
return NULL;
}
INIT_LIST_HEAD(&object->object_list);
INIT_LIST_HEAD(&object->gray_list);
INIT_HLIST_HEAD(&object->area_list);
spin_lock_init(&object->lock);
atomic_set(&object->use_count, 1);
object->flags = OBJECT_ALLOCATED;
object->pointer = ptr;
object->size = size;
object->min_count = min_count;
object->count = 0;
object->jiffies = jiffies;
object->checksum = 0;
if (in_irq()) {
object->pid = 0;
strncpy(object->comm, "hardirq", sizeof(object->comm));
} else if (in_softirq()) {
object->pid = 0;
strncpy(object->comm, "softirq", sizeof(object->comm));
} else {
object->pid = current->pid;
strncpy(object->comm, current->comm, sizeof(object->comm));
}
object->trace_len = __save_stack_trace(object->trace);
INIT_PRIO_TREE_NODE(&object->tree_node);
object->tree_node.start = ptr;
object->tree_node.last = ptr + size - 1;
write_lock_irqsave(&kmemleak_lock, flags);
min_addr = min(min_addr, ptr);
max_addr = max(max_addr, ptr + size);
node = prio_tree_insert(&object_tree_root, &object->tree_node);
if (node != &object->tree_node) {
kmemleak_stop("Cannot insert 0x%lx into the object search tree "
"(already existing)\n", ptr);
object = lookup_object(ptr, 1);
spin_lock(&object->lock);
dump_object_info(object);
spin_unlock(&object->lock);
goto out;
}
list_add_tail_rcu(&object->object_list, &object_list);
out:
write_unlock_irqrestore(&kmemleak_lock, flags);
return object;
}
static void __delete_object(struct kmemleak_object *object)
{
unsigned long flags;
write_lock_irqsave(&kmemleak_lock, flags);
prio_tree_remove(&object_tree_root, &object->tree_node);
list_del_rcu(&object->object_list);
write_unlock_irqrestore(&kmemleak_lock, flags);
WARN_ON(!(object->flags & OBJECT_ALLOCATED));
WARN_ON(atomic_read(&object->use_count) < 2);
spin_lock_irqsave(&object->lock, flags);
object->flags &= ~OBJECT_ALLOCATED;
spin_unlock_irqrestore(&object->lock, flags);
put_object(object);
}
static void delete_object_full(unsigned long ptr)
{
struct kmemleak_object *object;
object = find_and_get_object(ptr, 0);
if (!object) {
#ifdef DEBUG
kmemleak_warn("Freeing unknown object at 0x%08lx\n",
ptr);
#endif
return;
}
__delete_object(object);
put_object(object);
}
static void delete_object_part(unsigned long ptr, size_t size)
{
struct kmemleak_object *object;
unsigned long start, end;
object = find_and_get_object(ptr, 1);
if (!object) {
#ifdef DEBUG
kmemleak_warn("Partially freeing unknown object at 0x%08lx "
"(size %zu)\n", ptr, size);
#endif
return;
}
__delete_object(object);
start = object->pointer;
end = object->pointer + object->size;
if (ptr > start)
create_object(start, ptr - start, object->min_count,
GFP_KERNEL);
if (ptr + size < end)
create_object(ptr + size, end - ptr - size, object->min_count,
GFP_KERNEL);
put_object(object);
}
static void __paint_it(struct kmemleak_object *object, int color)
{
object->min_count = color;
if (color == KMEMLEAK_BLACK)
object->flags |= OBJECT_NO_SCAN;
}
static void paint_it(struct kmemleak_object *object, int color)
{
unsigned long flags;
spin_lock_irqsave(&object->lock, flags);
__paint_it(object, color);
spin_unlock_irqrestore(&object->lock, flags);
}
static void paint_ptr(unsigned long ptr, int color)
{
struct kmemleak_object *object;
object = find_and_get_object(ptr, 0);
if (!object) {
kmemleak_warn("Trying to color unknown object "
"at 0x%08lx as %s\n", ptr,
(color == KMEMLEAK_GREY) ? "Grey" :
(color == KMEMLEAK_BLACK) ? "Black" : "Unknown");
return;
}
paint_it(object, color);
put_object(object);
}
static void make_gray_object(unsigned long ptr)
{
paint_ptr(ptr, KMEMLEAK_GREY);
}
static void make_black_object(unsigned long ptr)
{
paint_ptr(ptr, KMEMLEAK_BLACK);
}
static void add_scan_area(unsigned long ptr, size_t size, gfp_t gfp)
{
unsigned long flags;
struct kmemleak_object *object;
struct kmemleak_scan_area *area;
object = find_and_get_object(ptr, 1);
if (!object) {
kmemleak_warn("Adding scan area to unknown object at 0x%08lx\n",
ptr);
return;
}
area = kmem_cache_alloc(scan_area_cache, gfp_kmemleak_mask(gfp));
if (!area) {
pr_warning("Cannot allocate a scan area\n");
goto out;
}
spin_lock_irqsave(&object->lock, flags);
if (ptr + size > object->pointer + object->size) {
kmemleak_warn("Scan area larger than object 0x%08lx\n", ptr);
dump_object_info(object);
kmem_cache_free(scan_area_cache, area);
goto out_unlock;
}
INIT_HLIST_NODE(&area->node);
area->start = ptr;
area->size = size;
hlist_add_head(&area->node, &object->area_list);
out_unlock:
spin_unlock_irqrestore(&object->lock, flags);
out:
put_object(object);
}
static void object_no_scan(unsigned long ptr)
{
unsigned long flags;
struct kmemleak_object *object;
object = find_and_get_object(ptr, 0);
if (!object) {
kmemleak_warn("Not scanning unknown object at 0x%08lx\n", ptr);
return;
}
spin_lock_irqsave(&object->lock, flags);
object->flags |= OBJECT_NO_SCAN;
spin_unlock_irqrestore(&object->lock, flags);
put_object(object);
}
static void __init log_early(int op_type, const void *ptr, size_t size,
int min_count)
{
unsigned long flags;
struct early_log *log;
if (crt_early_log >= ARRAY_SIZE(early_log)) {
pr_warning("Early log buffer exceeded, "
"please increase DEBUG_KMEMLEAK_EARLY_LOG_SIZE\n");
kmemleak_disable();
return;
}
local_irq_save(flags);
log = &early_log[crt_early_log];
log->op_type = op_type;
log->ptr = ptr;
log->size = size;
log->min_count = min_count;
if (op_type == KMEMLEAK_ALLOC)
log->trace_len = __save_stack_trace(log->trace);
crt_early_log++;
local_irq_restore(flags);
}
static void early_alloc(struct early_log *log)
{
struct kmemleak_object *object;
unsigned long flags;
int i;
if (!atomic_read(&kmemleak_enabled) || !log->ptr || IS_ERR(log->ptr))
return;
rcu_read_lock();
object = create_object((unsigned long)log->ptr, log->size,
log->min_count, GFP_ATOMIC);
if (!object)
goto out;
spin_lock_irqsave(&object->lock, flags);
for (i = 0; i < log->trace_len; i++)
object->trace[i] = log->trace[i];
object->trace_len = log->trace_len;
spin_unlock_irqrestore(&object->lock, flags);
out:
rcu_read_unlock();
}
void __ref kmemleak_alloc(const void *ptr, size_t size, int min_count,
gfp_t gfp)
{
pr_debug("%s(0x%p, %zu, %d)\n", __func__, ptr, size, min_count);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
create_object((unsigned long)ptr, size, min_count, gfp);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_ALLOC, ptr, size, min_count);
}
void __ref kmemleak_free(const void *ptr)
{
pr_debug("%s(0x%p)\n", __func__, ptr);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
delete_object_full((unsigned long)ptr);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_FREE, ptr, 0, 0);
}
void __ref kmemleak_free_part(const void *ptr, size_t size)
{
pr_debug("%s(0x%p)\n", __func__, ptr);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
delete_object_part((unsigned long)ptr, size);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_FREE_PART, ptr, size, 0);
}
void __ref kmemleak_not_leak(const void *ptr)
{
pr_debug("%s(0x%p)\n", __func__, ptr);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
make_gray_object((unsigned long)ptr);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_NOT_LEAK, ptr, 0, 0);
}
void __ref kmemleak_ignore(const void *ptr)
{
pr_debug("%s(0x%p)\n", __func__, ptr);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
make_black_object((unsigned long)ptr);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_IGNORE, ptr, 0, 0);
}
void __ref kmemleak_scan_area(const void *ptr, size_t size, gfp_t gfp)
{
pr_debug("%s(0x%p)\n", __func__, ptr);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
add_scan_area((unsigned long)ptr, size, gfp);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_SCAN_AREA, ptr, size, 0);
}
void __ref kmemleak_no_scan(const void *ptr)
{
pr_debug("%s(0x%p)\n", __func__, ptr);
if (atomic_read(&kmemleak_enabled) && ptr && !IS_ERR(ptr))
object_no_scan((unsigned long)ptr);
else if (atomic_read(&kmemleak_early_log))
log_early(KMEMLEAK_NO_SCAN, ptr, 0, 0);
}
static bool update_checksum(struct kmemleak_object *object)
{
u32 old_csum = object->checksum;
if (!kmemcheck_is_obj_initialized(object->pointer, object->size))
return false;
object->checksum = crc32(0, (void *)object->pointer, object->size);
return object->checksum != old_csum;
}
static int scan_should_stop(void)
{
if (!atomic_read(&kmemleak_enabled))
return 1;
if (current->mm)
return signal_pending(current);
else
return kthread_should_stop();
return 0;
}
static void scan_block(void *_start, void *_end,
struct kmemleak_object *scanned, int allow_resched)
{
unsigned long *ptr;
unsigned long *start = PTR_ALIGN(_start, BYTES_PER_POINTER);
unsigned long *end = _end - (BYTES_PER_POINTER - 1);
for (ptr = start; ptr < end; ptr++) {
struct kmemleak_object *object;
unsigned long flags;
unsigned long pointer;
if (allow_resched)
cond_resched();
if (scan_should_stop())
break;
if (!kmemcheck_is_obj_initialized((unsigned long)ptr,
BYTES_PER_POINTER))
continue;
pointer = *ptr;
object = find_and_get_object(pointer, 1);
if (!object)
continue;
if (object == scanned) {
put_object(object);
continue;
}
spin_lock_irqsave_nested(&object->lock, flags,
SINGLE_DEPTH_NESTING);
if (!color_white(object)) {
spin_unlock_irqrestore(&object->lock, flags);
put_object(object);
continue;
}
object->count++;
if (color_gray(object)) {
list_add_tail(&object->gray_list, &gray_list);
spin_unlock_irqrestore(&object->lock, flags);
continue;
}
spin_unlock_irqrestore(&object->lock, flags);
put_object(object);
}
}
static void scan_object(struct kmemleak_object *object)
{
struct kmemleak_scan_area *area;
struct hlist_node *elem;
unsigned long flags;
spin_lock_irqsave(&object->lock, flags);
if (object->flags & OBJECT_NO_SCAN)
goto out;
if (!(object->flags & OBJECT_ALLOCATED))
goto out;
if (hlist_empty(&object->area_list)) {
void *start = (void *)object->pointer;
void *end = (void *)(object->pointer + object->size);
while (start < end && (object->flags & OBJECT_ALLOCATED) &&
!(object->flags & OBJECT_NO_SCAN)) {
scan_block(start, min(start + MAX_SCAN_SIZE, end),
object, 0);
start += MAX_SCAN_SIZE;
spin_unlock_irqrestore(&object->lock, flags);
cond_resched();
spin_lock_irqsave(&object->lock, flags);
}
} else
hlist_for_each_entry(area, elem, &object->area_list, node)
scan_block((void *)area->start,
(void *)(area->start + area->size),
object, 0);
out:
spin_unlock_irqrestore(&object->lock, flags);
}
static void scan_gray_list(void)
{
struct kmemleak_object *object, *tmp;
object = list_entry(gray_list.next, typeof(*object), gray_list);
while (&object->gray_list != &gray_list) {
cond_resched();
if (!scan_should_stop())
scan_object(object);
tmp = list_entry(object->gray_list.next, typeof(*object),
gray_list);
list_del(&object->gray_list);
put_object(object);
object = tmp;
}
WARN_ON(!list_empty(&gray_list));
}
static void kmemleak_scan(void)
{
unsigned long flags;
struct kmemleak_object *object;
int i;
int new_leaks = 0;
jiffies_last_scan = jiffies;
rcu_read_lock();
list_for_each_entry_rcu(object, &object_list, object_list) {
spin_lock_irqsave(&object->lock, flags);
#ifdef DEBUG
if (atomic_read(&object->use_count) > 1) {
pr_debug("object->use_count = %d\n",
atomic_read(&object->use_count));
dump_object_info(object);
}
#endif
object->count = 0;
if (color_gray(object) && get_object(object))
list_add_tail(&object->gray_list, &gray_list);
spin_unlock_irqrestore(&object->lock, flags);
}
rcu_read_unlock();
scan_block(_sdata, _edata, NULL, 1);
scan_block(__bss_start, __bss_stop, NULL, 1);
#ifdef CONFIG_SMP
for_each_possible_cpu(i)
scan_block(__per_cpu_start + per_cpu_offset(i),
__per_cpu_end + per_cpu_offset(i), NULL, 1);
#endif
for_each_online_node(i) {
pg_data_t *pgdat = NODE_DATA(i);
unsigned long start_pfn = pgdat->node_start_pfn;
unsigned long end_pfn = start_pfn + pgdat->node_spanned_pages;
unsigned long pfn;
for (pfn = start_pfn; pfn < end_pfn; pfn++) {
struct page *page;
if (!pfn_valid(pfn))
continue;
page = pfn_to_page(pfn);
if (page_count(page) == 0)
continue;
scan_block(page, page + 1, NULL, 1);
}
}
if (kmemleak_stack_scan) {
struct task_struct *p, *g;
read_lock(&tasklist_lock);
do_each_thread(g, p) {
scan_block(task_stack_page(p), task_stack_page(p) +
THREAD_SIZE, NULL, 0);
} while_each_thread(g, p);
read_unlock(&tasklist_lock);
}
scan_gray_list();
rcu_read_lock();
list_for_each_entry_rcu(object, &object_list, object_list) {
spin_lock_irqsave(&object->lock, flags);
if (color_white(object) && (object->flags & OBJECT_ALLOCATED)
&& update_checksum(object) && get_object(object)) {
object->count = object->min_count;
list_add_tail(&object->gray_list, &gray_list);
}
spin_unlock_irqrestore(&object->lock, flags);
}
rcu_read_unlock();
scan_gray_list();
if (scan_should_stop())
return;
rcu_read_lock();
list_for_each_entry_rcu(object, &object_list, object_list) {
spin_lock_irqsave(&object->lock, flags);
if (unreferenced_object(object) &&
!(object->flags & OBJECT_REPORTED)) {
object->flags |= OBJECT_REPORTED;
new_leaks++;
}
spin_unlock_irqrestore(&object->lock, flags);
}
rcu_read_unlock();
if (new_leaks)
pr_info("%d new suspected memory leaks (see "
"/sys/kernel/debug/kmemleak)\n", new_leaks);
}
static int kmemleak_scan_thread(void *arg)
{
static int first_run = 1;
pr_info("Automatic memory scanning thread started\n");
set_user_nice(current, 10);
if (first_run) {
first_run = 0;
ssleep(SECS_FIRST_SCAN);
}
while (!kthread_should_stop()) {
signed long timeout = jiffies_scan_wait;
mutex_lock(&scan_mutex);
kmemleak_scan();
mutex_unlock(&scan_mutex);
while (timeout && !kthread_should_stop())
timeout = schedule_timeout_interruptible(timeout);
}
pr_info("Automatic memory scanning thread ended\n");
return 0;
}
static void start_scan_thread(void)
{
if (scan_thread)
return;
scan_thread = kthread_run(kmemleak_scan_thread, NULL, "kmemleak");
if (IS_ERR(scan_thread)) {
pr_warning("Failed to create the scan thread\n");
scan_thread = NULL;
}
}
static void stop_scan_thread(void)
{
if (scan_thread) {
kthread_stop(scan_thread);
scan_thread = NULL;
}
}
static void *kmemleak_seq_start(struct seq_file *seq, loff_t *pos)
{
struct kmemleak_object *object;
loff_t n = *pos;
int err;
err = mutex_lock_interruptible(&scan_mutex);
if (err < 0)
return ERR_PTR(err);
rcu_read_lock();
list_for_each_entry_rcu(object, &object_list, object_list) {
if (n-- > 0)
continue;
if (get_object(object))
goto out;
}
object = NULL;
out:
return object;
}
static void *kmemleak_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct kmemleak_object *prev_obj = v;
struct kmemleak_object *next_obj = NULL;
struct list_head *n = &prev_obj->object_list;
++(*pos);
list_for_each_continue_rcu(n, &object_list) {
struct kmemleak_object *obj =
list_entry(n, struct kmemleak_object, object_list);
if (get_object(obj)) {
next_obj = obj;
break;
}
}
put_object(prev_obj);
return next_obj;
}
static void kmemleak_seq_stop(struct seq_file *seq, void *v)
{
if (!IS_ERR(v)) {
rcu_read_unlock();
mutex_unlock(&scan_mutex);
if (v)
put_object(v);
}
}
static int kmemleak_seq_show(struct seq_file *seq, void *v)
{
struct kmemleak_object *object = v;
unsigned long flags;
spin_lock_irqsave(&object->lock, flags);
if ((object->flags & OBJECT_REPORTED) && unreferenced_object(object))
print_unreferenced(seq, object);
spin_unlock_irqrestore(&object->lock, flags);
return 0;
}
static int kmemleak_open(struct inode *inode, struct file *file)
{
if (!atomic_read(&kmemleak_enabled))
return -EBUSY;
return seq_open(file, &kmemleak_seq_ops);
}
static int kmemleak_release(struct inode *inode, struct file *file)
{
return seq_release(inode, file);
}
static int dump_str_object_info(const char *str)
{
unsigned long flags;
struct kmemleak_object *object;
unsigned long addr;
addr= simple_strtoul(str, NULL, 0);
object = find_and_get_object(addr, 0);
if (!object) {
pr_info("Unknown object at 0x%08lx\n", addr);
return -EINVAL;
}
spin_lock_irqsave(&object->lock, flags);
dump_object_info(object);
spin_unlock_irqrestore(&object->lock, flags);
put_object(object);
return 0;
}
static void kmemleak_clear(void)
{
struct kmemleak_object *object;
unsigned long flags;
rcu_read_lock();
list_for_each_entry_rcu(object, &object_list, object_list) {
spin_lock_irqsave(&object->lock, flags);
if ((object->flags & OBJECT_REPORTED) &&
unreferenced_object(object))
__paint_it(object, KMEMLEAK_GREY);
spin_unlock_irqrestore(&object->lock, flags);
}
rcu_read_unlock();
}
static ssize_t kmemleak_write(struct file *file, const char __user *user_buf,
size_t size, loff_t *ppos)
{
char buf[64];
int buf_size;
int ret;
buf_size = min(size, (sizeof(buf) - 1));
if (strncpy_from_user(buf, user_buf, buf_size) < 0)
return -EFAULT;
buf[buf_size] = 0;
ret = mutex_lock_interruptible(&scan_mutex);
if (ret < 0)
return ret;
if (strncmp(buf, "off", 3) == 0)
kmemleak_disable();
else if (strncmp(buf, "stack=on", 8) == 0)
kmemleak_stack_scan = 1;
else if (strncmp(buf, "stack=off", 9) == 0)
kmemleak_stack_scan = 0;
else if (strncmp(buf, "scan=on", 7) == 0)
start_scan_thread();
else if (strncmp(buf, "scan=off", 8) == 0)
stop_scan_thread();
else if (strncmp(buf, "scan=", 5) == 0) {
unsigned long secs;
ret = strict_strtoul(buf + 5, 0, &secs);
if (ret < 0)
goto out;
stop_scan_thread();
if (secs) {
jiffies_scan_wait = msecs_to_jiffies(secs * 1000);
start_scan_thread();
}
} else if (strncmp(buf, "scan", 4) == 0)
kmemleak_scan();
else if (strncmp(buf, "clear", 5) == 0)
kmemleak_clear();
else if (strncmp(buf, "dump=", 5) == 0)
ret = dump_str_object_info(buf + 5);
else
ret = -EINVAL;
out:
mutex_unlock(&scan_mutex);
if (ret < 0)
return ret;
*ppos += size;
return size;
}
static void kmemleak_do_cleanup(struct work_struct *work)
{
struct kmemleak_object *object;
mutex_lock(&scan_mutex);
stop_scan_thread();
rcu_read_lock();
list_for_each_entry_rcu(object, &object_list, object_list)
delete_object_full(object->pointer);
rcu_read_unlock();
mutex_unlock(&scan_mutex);
}
static void kmemleak_disable(void)
{
if (atomic_cmpxchg(&kmemleak_error, 0, 1))
return;
atomic_set(&kmemleak_early_log, 0);
atomic_set(&kmemleak_enabled, 0);
if (atomic_read(&kmemleak_initialized))
schedule_work(&cleanup_work);
pr_info("Kernel memory leak detector disabled\n");
}
static int kmemleak_boot_config(char *str)
{
if (!str)
return -EINVAL;
if (strcmp(str, "off") == 0)
kmemleak_disable();
else if (strcmp(str, "on") == 0)
kmemleak_skip_disable = 1;
else
return -EINVAL;
return 0;
}
void __init kmemleak_init(void)
{
int i;
unsigned long flags;
#ifdef CONFIG_DEBUG_KMEMLEAK_DEFAULT_OFF
if (!kmemleak_skip_disable) {
kmemleak_disable();
return;
}
#endif
jiffies_min_age = msecs_to_jiffies(MSECS_MIN_AGE);
jiffies_scan_wait = msecs_to_jiffies(SECS_SCAN_WAIT * 1000);
object_cache = KMEM_CACHE(kmemleak_object, SLAB_NOLEAKTRACE);
scan_area_cache = KMEM_CACHE(kmemleak_scan_area, SLAB_NOLEAKTRACE);
INIT_PRIO_TREE_ROOT(&object_tree_root);
local_irq_save(flags);
if (!atomic_read(&kmemleak_error)) {
atomic_set(&kmemleak_enabled, 1);
atomic_set(&kmemleak_early_log, 0);
}
local_irq_restore(flags);
for (i = 0; i < crt_early_log; i++) {
struct early_log *log = &early_log[i];
switch (log->op_type) {
case KMEMLEAK_ALLOC:
early_alloc(log);
break;
case KMEMLEAK_FREE:
kmemleak_free(log->ptr);
break;
case KMEMLEAK_FREE_PART:
kmemleak_free_part(log->ptr, log->size);
break;
case KMEMLEAK_NOT_LEAK:
kmemleak_not_leak(log->ptr);
break;
case KMEMLEAK_IGNORE:
kmemleak_ignore(log->ptr);
break;
case KMEMLEAK_SCAN_AREA:
kmemleak_scan_area(log->ptr, log->size, GFP_KERNEL);
break;
case KMEMLEAK_NO_SCAN:
kmemleak_no_scan(log->ptr);
break;
default:
WARN_ON(1);
}
}
}
static int __init kmemleak_late_init(void)
{
struct dentry *dentry;
atomic_set(&kmemleak_initialized, 1);
if (atomic_read(&kmemleak_error)) {
schedule_work(&cleanup_work);
return -ENOMEM;
}
dentry = debugfs_create_file("kmemleak", S_IRUGO, NULL, NULL,
&kmemleak_fops);
if (!dentry)
pr_warning("Failed to create the debugfs kmemleak file\n");
mutex_lock(&scan_mutex);
start_scan_thread();
mutex_unlock(&scan_mutex);
pr_info("Kernel memory leak detector initialized\n");
return 0;
}
