static inline int kmem_cache_debug(struct kmem_cache *s)
{
#ifdef CONFIG_SLUB_DEBUG
return unlikely(s->flags & SLAB_DEBUG_FLAGS);
#else
return 0;
#endif
}
void *fixup_red_left(struct kmem_cache *s, void *p)
{
if (kmem_cache_debug(s) && s->flags & SLAB_RED_ZONE)
p += s->red_left_pad;
return p;
}
static inline bool kmem_cache_has_cpu_partial(struct kmem_cache *s)
{
#ifdef CONFIG_SLUB_CPU_PARTIAL
return !kmem_cache_debug(s);
#else
return false;
#endif
}
static inline int sysfs_slab_add(struct kmem_cache *s) { return 0; }
static inline int sysfs_slab_alias(struct kmem_cache *s, const char *p)
{ return 0; }
static inline void memcg_propagate_slab_attrs(struct kmem_cache *s) { }
static inline void sysfs_slab_remove(struct kmem_cache *s) { }
static inline void stat(const struct kmem_cache *s, enum stat_item si)
{
#ifdef CONFIG_SLUB_STATS
raw_cpu_inc(s->cpu_slab->stat[si]);
#endif
}
static inline void *get_freepointer(struct kmem_cache *s, void *object)
{
return *(void **)(object + s->offset);
}
static void prefetch_freepointer(const struct kmem_cache *s, void *object)
{
prefetch(object + s->offset);
}
static inline void *get_freepointer_safe(struct kmem_cache *s, void *object)
{
void *p;
if (!debug_pagealloc_enabled())
return get_freepointer(s, object);
probe_kernel_read(&p, (void **)(object + s->offset), sizeof(p));
return p;
}
static inline void set_freepointer(struct kmem_cache *s, void *object, void *fp)
{
*(void **)(object + s->offset) = fp;
}
static inline int slab_index(void *p, struct kmem_cache *s, void *addr)
{
return (p - addr) / s->size;
}
static inline int order_objects(int order, unsigned long size, int reserved)
{
return ((PAGE_SIZE << order) - reserved) / size;
}
static inline struct kmem_cache_order_objects oo_make(int order,
unsigned long size, int reserved)
{
struct kmem_cache_order_objects x = {
(order << OO_SHIFT) + order_objects(order, size, reserved)
};
return x;
}
static inline int oo_order(struct kmem_cache_order_objects x)
{
return x.x >> OO_SHIFT;
}
static inline int oo_objects(struct kmem_cache_order_objects x)
{
return x.x & OO_MASK;
}
static __always_inline void slab_lock(struct page *page)
{
VM_BUG_ON_PAGE(PageTail(page), page);
bit_spin_lock(PG_locked, &page->flags);
}
static __always_inline void slab_unlock(struct page *page)
{
VM_BUG_ON_PAGE(PageTail(page), page);
__bit_spin_unlock(PG_locked, &page->flags);
}
static inline void set_page_slub_counters(struct page *page, unsigned long counters_new)
{
struct page tmp;
tmp.counters = counters_new;
page->frozen = tmp.frozen;
page->inuse = tmp.inuse;
page->objects = tmp.objects;
}
static inline bool __cmpxchg_double_slab(struct kmem_cache *s, struct page *page,
void *freelist_old, unsigned long counters_old,
void *freelist_new, unsigned long counters_new,
const char *n)
{
VM_BUG_ON(!irqs_disabled());
#if defined(CONFIG_HAVE_CMPXCHG_DOUBLE) && \
defined(CONFIG_HAVE_ALIGNED_STRUCT_PAGE)
if (s->flags & __CMPXCHG_DOUBLE) {
if (cmpxchg_double(&page->freelist, &page->counters,
freelist_old, counters_old,
freelist_new, counters_new))
return true;
} else
#endif
{
slab_lock(page);
if (page->freelist == freelist_old &&
page->counters == counters_old) {
page->freelist = freelist_new;
set_page_slub_counters(page, counters_new);
slab_unlock(page);
return true;
}
slab_unlock(page);
}
cpu_relax();
stat(s, CMPXCHG_DOUBLE_FAIL);
#ifdef SLUB_DEBUG_CMPXCHG
pr_info("%s %s: cmpxchg double redo ", n, s->name);
#endif
return false;
}
static inline bool cmpxchg_double_slab(struct kmem_cache *s, struct page *page,
void *freelist_old, unsigned long counters_old,
void *freelist_new, unsigned long counters_new,
const char *n)
{
#if defined(CONFIG_HAVE_CMPXCHG_DOUBLE) && \
defined(CONFIG_HAVE_ALIGNED_STRUCT_PAGE)
if (s->flags & __CMPXCHG_DOUBLE) {
if (cmpxchg_double(&page->freelist, &page->counters,
freelist_old, counters_old,
freelist_new, counters_new))
return true;
} else
#endif
{
unsigned long flags;
local_irq_save(flags);
slab_lock(page);
if (page->freelist == freelist_old &&
page->counters == counters_old) {
page->freelist = freelist_new;
set_page_slub_counters(page, counters_new);
slab_unlock(page);
local_irq_restore(flags);
return true;
}
slab_unlock(page);
local_irq_restore(flags);
}
cpu_relax();
stat(s, CMPXCHG_DOUBLE_FAIL);
#ifdef SLUB_DEBUG_CMPXCHG
pr_info("%s %s: cmpxchg double redo ", n, s->name);
#endif
return false;
}
static void get_map(struct kmem_cache *s, struct page *page, unsigned long *map)
{
void *p;
void *addr = page_address(page);
for (p = page->freelist; p; p = get_freepointer(s, p))
set_bit(slab_index(p, s, addr), map);
}
static inline int size_from_object(struct kmem_cache *s)
{
if (s->flags & SLAB_RED_ZONE)
return s->size - s->red_left_pad;
return s->size;
}
static inline void *restore_red_left(struct kmem_cache *s, void *p)
{
if (s->flags & SLAB_RED_ZONE)
p -= s->red_left_pad;
return p;
}
static inline void metadata_access_enable(void)
{
kasan_disable_current();
}
static inline void metadata_access_disable(void)
{
kasan_enable_current();
}
static inline int check_valid_pointer(struct kmem_cache *s,
struct page *page, void *object)
{
void *base;
if (!object)
return 1;
base = page_address(page);
object = restore_red_left(s, object);
if (object < base || object >= base + page->objects * s->size ||
(object - base) % s->size) {
return 0;
}
return 1;
}
static void print_section(char *level, char *text, u8 *addr,
unsigned int length)
{
metadata_access_enable();
print_hex_dump(level, text, DUMP_PREFIX_ADDRESS, 16, 1, addr,
length, 1);
metadata_access_disable();
}
static struct track *get_track(struct kmem_cache *s, void *object,
enum track_item alloc)
{
struct track *p;
if (s->offset)
p = object + s->offset + sizeof(void *);
else
p = object + s->inuse;
return p + alloc;
}
static void set_track(struct kmem_cache *s, void *object,
enum track_item alloc, unsigned long addr)
{
struct track *p = get_track(s, object, alloc);
if (addr) {
#ifdef CONFIG_STACKTRACE
struct stack_trace trace;
int i;
trace.nr_entries = 0;
trace.max_entries = TRACK_ADDRS_COUNT;
trace.entries = p->addrs;
trace.skip = 3;
metadata_access_enable();
save_stack_trace(&trace);
metadata_access_disable();
if (trace.nr_entries != 0 &&
trace.entries[trace.nr_entries - 1] == ULONG_MAX)
trace.nr_entries--;
for (i = trace.nr_entries; i < TRACK_ADDRS_COUNT; i++)
p->addrs[i] = 0;
#endif
p->addr = addr;
p->cpu = smp_processor_id();
p->pid = current->pid;
p->when = jiffies;
} else
memset(p, 0, sizeof(struct track));
}
static void init_tracking(struct kmem_cache *s, void *object)
{
if (!(s->flags & SLAB_STORE_USER))
return;
set_track(s, object, TRACK_FREE, 0UL);
set_track(s, object, TRACK_ALLOC, 0UL);
}
static void print_track(const char *s, struct track *t)
{
if (!t->addr)
return;
pr_err("INFO: %s in %pS age=%lu cpu=%u pid=%d\n",
s, (void *)t->addr, jiffies - t->when, t->cpu, t->pid);
#ifdef CONFIG_STACKTRACE
{
int i;
for (i = 0; i < TRACK_ADDRS_COUNT; i++)
if (t->addrs[i])
pr_err("\t%pS\n", (void *)t->addrs[i]);
else
break;
}
#endif
}
static void print_tracking(struct kmem_cache *s, void *object)
{
if (!(s->flags & SLAB_STORE_USER))
return;
print_track("Allocated", get_track(s, object, TRACK_ALLOC));
print_track("Freed", get_track(s, object, TRACK_FREE));
}
static void print_page_info(struct page *page)
{
pr_err("INFO: Slab 0x%p objects=%u used=%u fp=0x%p flags=0x%04lx\n",
page, page->objects, page->inuse, page->freelist, page->flags);
}
static void slab_bug(struct kmem_cache *s, char *fmt, ...)
{
struct va_format vaf;
va_list args;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
pr_err("=============================================================================\n");
pr_err("BUG %s (%s): %pV\n", s->name, print_tainted(), &vaf);
pr_err("-----------------------------------------------------------------------------\n\n");
add_taint(TAINT_BAD_PAGE, LOCKDEP_NOW_UNRELIABLE);
va_end(args);
}
static void slab_fix(struct kmem_cache *s, char *fmt, ...)
{
struct va_format vaf;
va_list args;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
pr_err("FIX %s: %pV\n", s->name, &vaf);
va_end(args);
}
static void print_trailer(struct kmem_cache *s, struct page *page, u8 *p)
{
unsigned int off;
u8 *addr = page_address(page);
print_tracking(s, p);
print_page_info(page);
pr_err("INFO: Object 0x%p @offset=%tu fp=0x%p\n\n",
p, p - addr, get_freepointer(s, p));
if (s->flags & SLAB_RED_ZONE)
print_section(KERN_ERR, "Redzone ", p - s->red_left_pad,
s->red_left_pad);
else if (p > addr + 16)
print_section(KERN_ERR, "Bytes b4 ", p - 16, 16);
print_section(KERN_ERR, "Object ", p,
min_t(unsigned long, s->object_size, PAGE_SIZE));
if (s->flags & SLAB_RED_ZONE)
print_section(KERN_ERR, "Redzone ", p + s->object_size,
s->inuse - s->object_size);
if (s->offset)
off = s->offset + sizeof(void *);
else
off = s->inuse;
if (s->flags & SLAB_STORE_USER)
off += 2 * sizeof(struct track);
off += kasan_metadata_size(s);
if (off != size_from_object(s))
print_section(KERN_ERR, "Padding ", p + off,
size_from_object(s) - off);
dump_stack();
}
void object_err(struct kmem_cache *s, struct page *page,
u8 *object, char *reason)
{
slab_bug(s, "%s", reason);
print_trailer(s, page, object);
}
static void slab_err(struct kmem_cache *s, struct page *page,
const char *fmt, ...)
{
va_list args;
char buf[100];
va_start(args, fmt);
vsnprintf(buf, sizeof(buf), fmt, args);
va_end(args);
slab_bug(s, "%s", buf);
print_page_info(page);
dump_stack();
}
static void init_object(struct kmem_cache *s, void *object, u8 val)
{
u8 *p = object;
if (s->flags & SLAB_RED_ZONE)
memset(p - s->red_left_pad, val, s->red_left_pad);
if (s->flags & __OBJECT_POISON) {
memset(p, POISON_FREE, s->object_size - 1);
p[s->object_size - 1] = POISON_END;
}
if (s->flags & SLAB_RED_ZONE)
memset(p + s->object_size, val, s->inuse - s->object_size);
}
static void restore_bytes(struct kmem_cache *s, char *message, u8 data,
void *from, void *to)
{
slab_fix(s, "Restoring 0x%p-0x%p=0x%x\n", from, to - 1, data);
memset(from, data, to - from);
}
static int check_bytes_and_report(struct kmem_cache *s, struct page *page,
u8 *object, char *what,
u8 *start, unsigned int value, unsigned int bytes)
{
u8 *fault;
u8 *end;
metadata_access_enable();
fault = memchr_inv(start, value, bytes);
metadata_access_disable();
if (!fault)
return 1;
end = start + bytes;
while (end > fault && end[-1] == value)
end--;
slab_bug(s, "%s overwritten", what);
pr_err("INFO: 0x%p-0x%p. First byte 0x%x instead of 0x%x\n",
fault, end - 1, fault[0], value);
print_trailer(s, page, object);
restore_bytes(s, what, value, fault, end);
return 0;
}
static int check_pad_bytes(struct kmem_cache *s, struct page *page, u8 *p)
{
unsigned long off = s->inuse;
if (s->offset)
off += sizeof(void *);
if (s->flags & SLAB_STORE_USER)
off += 2 * sizeof(struct track);
off += kasan_metadata_size(s);
if (size_from_object(s) == off)
return 1;
return check_bytes_and_report(s, page, p, "Object padding",
p + off, POISON_INUSE, size_from_object(s) - off);
}
static int slab_pad_check(struct kmem_cache *s, struct page *page)
{
u8 *start;
u8 *fault;
u8 *end;
int length;
int remainder;
if (!(s->flags & SLAB_POISON))
return 1;
start = page_address(page);
length = (PAGE_SIZE << compound_order(page)) - s->reserved;
end = start + length;
remainder = length % s->size;
if (!remainder)
return 1;
metadata_access_enable();
fault = memchr_inv(end - remainder, POISON_INUSE, remainder);
metadata_access_disable();
if (!fault)
return 1;
while (end > fault && end[-1] == POISON_INUSE)
end--;
slab_err(s, page, "Padding overwritten. 0x%p-0x%p", fault, end - 1);
print_section(KERN_ERR, "Padding ", end - remainder, remainder);
restore_bytes(s, "slab padding", POISON_INUSE, end - remainder, end);
return 0;
}
static int check_object(struct kmem_cache *s, struct page *page,
void *object, u8 val)
{
u8 *p = object;
u8 *endobject = object + s->object_size;
if (s->flags & SLAB_RED_ZONE) {
if (!check_bytes_and_report(s, page, object, "Redzone",
object - s->red_left_pad, val, s->red_left_pad))
return 0;
if (!check_bytes_and_report(s, page, object, "Redzone",
endobject, val, s->inuse - s->object_size))
return 0;
} else {
if ((s->flags & SLAB_POISON) && s->object_size < s->inuse) {
check_bytes_and_report(s, page, p, "Alignment padding",
endobject, POISON_INUSE,
s->inuse - s->object_size);
}
}
if (s->flags & SLAB_POISON) {
if (val != SLUB_RED_ACTIVE && (s->flags & __OBJECT_POISON) &&
(!check_bytes_and_report(s, page, p, "Poison", p,
POISON_FREE, s->object_size - 1) ||
!check_bytes_and_report(s, page, p, "Poison",
p + s->object_size - 1, POISON_END, 1)))
return 0;
check_pad_bytes(s, page, p);
}
if (!s->offset && val == SLUB_RED_ACTIVE)
return 1;
if (!check_valid_pointer(s, page, get_freepointer(s, p))) {
object_err(s, page, p, "Freepointer corrupt");
set_freepointer(s, p, NULL);
return 0;
}
return 1;
}
static int check_slab(struct kmem_cache *s, struct page *page)
{
int maxobj;
VM_BUG_ON(!irqs_disabled());
if (!PageSlab(page)) {
slab_err(s, page, "Not a valid slab page");
return 0;
}
maxobj = order_objects(compound_order(page), s->size, s->reserved);
if (page->objects > maxobj) {
slab_err(s, page, "objects %u > max %u",
page->objects, maxobj);
return 0;
}
if (page->inuse > page->objects) {
slab_err(s, page, "inuse %u > max %u",
page->inuse, page->objects);
return 0;
}
slab_pad_check(s, page);
return 1;
}
static int on_freelist(struct kmem_cache *s, struct page *page, void *search)
{
int nr = 0;
void *fp;
void *object = NULL;
int max_objects;
fp = page->freelist;
while (fp && nr <= page->objects) {
if (fp == search)
return 1;
if (!check_valid_pointer(s, page, fp)) {
if (object) {
object_err(s, page, object,
"Freechain corrupt");
set_freepointer(s, object, NULL);
} else {
slab_err(s, page, "Freepointer corrupt");
page->freelist = NULL;
page->inuse = page->objects;
slab_fix(s, "Freelist cleared");
return 0;
}
break;
}
object = fp;
fp = get_freepointer(s, object);
nr++;
}
max_objects = order_objects(compound_order(page), s->size, s->reserved);
if (max_objects > MAX_OBJS_PER_PAGE)
max_objects = MAX_OBJS_PER_PAGE;
if (page->objects != max_objects) {
slab_err(s, page, "Wrong number of objects. Found %d but should be %d",
page->objects, max_objects);
page->objects = max_objects;
slab_fix(s, "Number of objects adjusted.");
}
if (page->inuse != page->objects - nr) {
slab_err(s, page, "Wrong object count. Counter is %d but counted were %d",
page->inuse, page->objects - nr);
page->inuse = page->objects - nr;
slab_fix(s, "Object count adjusted.");
}
return search == NULL;
}
static void trace(struct kmem_cache *s, struct page *page, void *object,
int alloc)
{
if (s->flags & SLAB_TRACE) {
pr_info("TRACE %s %s 0x%p inuse=%d fp=0x%p\n",
s->name,
alloc ? "alloc" : "free",
object, page->inuse,
page->freelist);
if (!alloc)
print_section(KERN_INFO, "Object ", (void *)object,
s->object_size);
dump_stack();
}
}
static void add_full(struct kmem_cache *s,
struct kmem_cache_node *n, struct page *page)
{
if (!(s->flags & SLAB_STORE_USER))
return;
lockdep_assert_held(&n->list_lock);
list_add(&page->lru, &n->full);
}
static void remove_full(struct kmem_cache *s, struct kmem_cache_node *n, struct page *page)
{
if (!(s->flags & SLAB_STORE_USER))
return;
lockdep_assert_held(&n->list_lock);
list_del(&page->lru);
}
static inline unsigned long slabs_node(struct kmem_cache *s, int node)
{
struct kmem_cache_node *n = get_node(s, node);
return atomic_long_read(&n->nr_slabs);
}
static inline unsigned long node_nr_slabs(struct kmem_cache_node *n)
{
return atomic_long_read(&n->nr_slabs);
}
static inline void inc_slabs_node(struct kmem_cache *s, int node, int objects)
{
struct kmem_cache_node *n = get_node(s, node);
if (likely(n)) {
atomic_long_inc(&n->nr_slabs);
atomic_long_add(objects, &n->total_objects);
}
}
static inline void dec_slabs_node(struct kmem_cache *s, int node, int objects)
{
struct kmem_cache_node *n = get_node(s, node);
atomic_long_dec(&n->nr_slabs);
atomic_long_sub(objects, &n->total_objects);
}
static void setup_object_debug(struct kmem_cache *s, struct page *page,
void *object)
{
if (!(s->flags & (SLAB_STORE_USER|SLAB_RED_ZONE|__OBJECT_POISON)))
return;
init_object(s, object, SLUB_RED_INACTIVE);
init_tracking(s, object);
}
static inline int alloc_consistency_checks(struct kmem_cache *s,
struct page *page,
void *object, unsigned long addr)
{
if (!check_slab(s, page))
return 0;
if (!check_valid_pointer(s, page, object)) {
object_err(s, page, object, "Freelist Pointer check fails");
return 0;
}
if (!check_object(s, page, object, SLUB_RED_INACTIVE))
return 0;
return 1;
}
static noinline int alloc_debug_processing(struct kmem_cache *s,
struct page *page,
void *object, unsigned long addr)
{
if (s->flags & SLAB_CONSISTENCY_CHECKS) {
if (!alloc_consistency_checks(s, page, object, addr))
goto bad;
}
if (s->flags & SLAB_STORE_USER)
set_track(s, object, TRACK_ALLOC, addr);
trace(s, page, object, 1);
init_object(s, object, SLUB_RED_ACTIVE);
return 1;
bad:
if (PageSlab(page)) {
slab_fix(s, "Marking all objects used");
page->inuse = page->objects;
page->freelist = NULL;
}
return 0;
}
static inline int free_consistency_checks(struct kmem_cache *s,
struct page *page, void *object, unsigned long addr)
{
if (!check_valid_pointer(s, page, object)) {
slab_err(s, page, "Invalid object pointer 0x%p", object);
return 0;
}
if (on_freelist(s, page, object)) {
object_err(s, page, object, "Object already free");
return 0;
}
if (!check_object(s, page, object, SLUB_RED_ACTIVE))
return 0;
if (unlikely(s != page->slab_cache)) {
if (!PageSlab(page)) {
slab_err(s, page, "Attempt to free object(0x%p) outside of slab",
object);
} else if (!page->slab_cache) {
pr_err("SLUB <none>: no slab for object 0x%p.\n",
object);
dump_stack();
} else
object_err(s, page, object,
"page slab pointer corrupt.");
return 0;
}
return 1;
}
static noinline int free_debug_processing(
struct kmem_cache *s, struct page *page,
void *head, void *tail, int bulk_cnt,
unsigned long addr)
{
struct kmem_cache_node *n = get_node(s, page_to_nid(page));
void *object = head;
int cnt = 0;
unsigned long uninitialized_var(flags);
int ret = 0;
spin_lock_irqsave(&n->list_lock, flags);
slab_lock(page);
if (s->flags & SLAB_CONSISTENCY_CHECKS) {
if (!check_slab(s, page))
goto out;
}
next_object:
cnt++;
if (s->flags & SLAB_CONSISTENCY_CHECKS) {
if (!free_consistency_checks(s, page, object, addr))
goto out;
}
if (s->flags & SLAB_STORE_USER)
set_track(s, object, TRACK_FREE, addr);
trace(s, page, object, 0);
init_object(s, object, SLUB_RED_INACTIVE);
if (object != tail) {
object = get_freepointer(s, object);
goto next_object;
}
ret = 1;
out:
if (cnt != bulk_cnt)
slab_err(s, page, "Bulk freelist count(%d) invalid(%d)\n",
bulk_cnt, cnt);
slab_unlock(page);
spin_unlock_irqrestore(&n->list_lock, flags);
if (!ret)
slab_fix(s, "Object at 0x%p not freed", object);
return ret;
}
static int __init setup_slub_debug(char *str)
{
slub_debug = DEBUG_DEFAULT_FLAGS;
if (*str++ != '=' || !*str)
goto out;
if (*str == ',')
goto check_slabs;
slub_debug = 0;
if (*str == '-')
goto out;
for (; *str && *str != ','; str++) {
switch (tolower(*str)) {
case 'f':
slub_debug |= SLAB_CONSISTENCY_CHECKS;
break;
case 'z':
slub_debug |= SLAB_RED_ZONE;
break;
case 'p':
slub_debug |= SLAB_POISON;
break;
case 'u':
slub_debug |= SLAB_STORE_USER;
break;
case 't':
slub_debug |= SLAB_TRACE;
break;
case 'a':
slub_debug |= SLAB_FAILSLAB;
break;
case 'o':
disable_higher_order_debug = 1;
break;
default:
pr_err("slub_debug option '%c' unknown. skipped\n",
*str);
}
}
check_slabs:
if (*str == ',')
slub_debug_slabs = str + 1;
out:
return 1;
}
unsigned long kmem_cache_flags(unsigned long object_size,
unsigned long flags, const char *name,
void (*ctor)(void *))
{
if (slub_debug && (!slub_debug_slabs || (name &&
!strncmp(slub_debug_slabs, name, strlen(slub_debug_slabs)))))
flags |= slub_debug;
return flags;
}
static inline void setup_object_debug(struct kmem_cache *s,
struct page *page, void *object) {}
static inline int alloc_debug_processing(struct kmem_cache *s,
struct page *page, void *object, unsigned long addr) { return 0; }
static inline int free_debug_processing(
struct kmem_cache *s, struct page *page,
void *head, void *tail, int bulk_cnt,
unsigned long addr) { return 0; }
static inline int slab_pad_check(struct kmem_cache *s, struct page *page)
{ return 1; }
static inline int check_object(struct kmem_cache *s, struct page *page,
void *object, u8 val) { return 1; }
static inline void add_full(struct kmem_cache *s, struct kmem_cache_node *n,
struct page *page) {}
static inline void remove_full(struct kmem_cache *s, struct kmem_cache_node *n,
struct page *page) {}
unsigned long kmem_cache_flags(unsigned long object_size,
unsigned long flags, const char *name,
void (*ctor)(void *))
{
return flags;
}
static inline unsigned long slabs_node(struct kmem_cache *s, int node)
{ return 0; }
static inline unsigned long node_nr_slabs(struct kmem_cache_node *n)
{ return 0; }
static inline void inc_slabs_node(struct kmem_cache *s, int node,
int objects) {}
static inline void dec_slabs_node(struct kmem_cache *s, int node,
int objects) {}
static inline void kmalloc_large_node_hook(void *ptr, size_t size, gfp_t flags)
{
kmemleak_alloc(ptr, size, 1, flags);
kasan_kmalloc_large(ptr, size, flags);
}
static inline void kfree_hook(const void *x)
{
kmemleak_free(x);
kasan_kfree_large(x);
}
static inline void *slab_free_hook(struct kmem_cache *s, void *x)
{
void *freeptr;
kmemleak_free_recursive(x, s->flags);
#if defined(CONFIG_KMEMCHECK) || defined(CONFIG_LOCKDEP)
{
unsigned long flags;
local_irq_save(flags);
kmemcheck_slab_free(s, x, s->object_size);
debug_check_no_locks_freed(x, s->object_size);
local_irq_restore(flags);
}
#endif
if (!(s->flags & SLAB_DEBUG_OBJECTS))
debug_check_no_obj_freed(x, s->object_size);
freeptr = get_freepointer(s, x);
kasan_slab_free(s, x);
return freeptr;
}
static inline void slab_free_freelist_hook(struct kmem_cache *s,
void *head, void *tail)
{
#if defined(CONFIG_KMEMCHECK) || \
defined(CONFIG_LOCKDEP) || \
defined(CONFIG_DEBUG_KMEMLEAK) || \
defined(CONFIG_DEBUG_OBJECTS_FREE) || \
defined(CONFIG_KASAN)
void *object = head;
void *tail_obj = tail ? : head;
void *freeptr;
do {
freeptr = slab_free_hook(s, object);
} while ((object != tail_obj) && (object = freeptr));
#endif
}
static void setup_object(struct kmem_cache *s, struct page *page,
void *object)
{
setup_object_debug(s, page, object);
kasan_init_slab_obj(s, object);
if (unlikely(s->ctor)) {
kasan_unpoison_object_data(s, object);
s->ctor(object);
kasan_poison_object_data(s, object);
}
}
static inline struct page *alloc_slab_page(struct kmem_cache *s,
gfp_t flags, int node, struct kmem_cache_order_objects oo)
{
struct page *page;
int order = oo_order(oo);
flags |= __GFP_NOTRACK;
if (node == NUMA_NO_NODE)
page = alloc_pages(flags, order);
else
page = __alloc_pages_node(node, flags, order);
if (page && memcg_charge_slab(page, flags, order, s)) {
__free_pages(page, order);
page = NULL;
}
return page;
}
static int init_cache_random_seq(struct kmem_cache *s)
{
int err;
unsigned long i, count = oo_objects(s->oo);
if (s->random_seq)
return 0;
err = cache_random_seq_create(s, count, GFP_KERNEL);
if (err) {
pr_err("SLUB: Unable to initialize free list for %s\n",
s->name);
return err;
}
if (s->random_seq) {
for (i = 0; i < count; i++)
s->random_seq[i] *= s->size;
}
return 0;
}
static void __init init_freelist_randomization(void)
{
struct kmem_cache *s;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list)
init_cache_random_seq(s);
mutex_unlock(&slab_mutex);
}
static void *next_freelist_entry(struct kmem_cache *s, struct page *page,
unsigned long *pos, void *start,
unsigned long page_limit,
unsigned long freelist_count)
{
unsigned int idx;
do {
idx = s->random_seq[*pos];
*pos += 1;
if (*pos >= freelist_count)
*pos = 0;
} while (unlikely(idx >= page_limit));
return (char *)start + idx;
}
static bool shuffle_freelist(struct kmem_cache *s, struct page *page)
{
void *start;
void *cur;
void *next;
unsigned long idx, pos, page_limit, freelist_count;
if (page->objects < 2 || !s->random_seq)
return false;
freelist_count = oo_objects(s->oo);
pos = get_random_int() % freelist_count;
page_limit = page->objects * s->size;
start = fixup_red_left(s, page_address(page));
cur = next_freelist_entry(s, page, &pos, start, page_limit,
freelist_count);
page->freelist = cur;
for (idx = 1; idx < page->objects; idx++) {
setup_object(s, page, cur);
next = next_freelist_entry(s, page, &pos, start, page_limit,
freelist_count);
set_freepointer(s, cur, next);
cur = next;
}
setup_object(s, page, cur);
set_freepointer(s, cur, NULL);
return true;
}
static inline int init_cache_random_seq(struct kmem_cache *s)
{
return 0;
}
static inline void init_freelist_randomization(void) { }
static inline bool shuffle_freelist(struct kmem_cache *s, struct page *page)
{
return false;
}
static struct page *allocate_slab(struct kmem_cache *s, gfp_t flags, int node)
{
struct page *page;
struct kmem_cache_order_objects oo = s->oo;
gfp_t alloc_gfp;
void *start, *p;
int idx, order;
bool shuffle;
flags &= gfp_allowed_mask;
if (gfpflags_allow_blocking(flags))
local_irq_enable();
flags |= s->allocflags;
alloc_gfp = (flags | __GFP_NOWARN | __GFP_NORETRY) & ~__GFP_NOFAIL;
if ((alloc_gfp & __GFP_DIRECT_RECLAIM) && oo_order(oo) > oo_order(s->min))
alloc_gfp = (alloc_gfp | __GFP_NOMEMALLOC) & ~(__GFP_RECLAIM|__GFP_NOFAIL);
page = alloc_slab_page(s, alloc_gfp, node, oo);
if (unlikely(!page)) {
oo = s->min;
alloc_gfp = flags;
page = alloc_slab_page(s, alloc_gfp, node, oo);
if (unlikely(!page))
goto out;
stat(s, ORDER_FALLBACK);
}
if (kmemcheck_enabled &&
!(s->flags & (SLAB_NOTRACK | DEBUG_DEFAULT_FLAGS))) {
int pages = 1 << oo_order(oo);
kmemcheck_alloc_shadow(page, oo_order(oo), alloc_gfp, node);
if (s->ctor)
kmemcheck_mark_uninitialized_pages(page, pages);
else
kmemcheck_mark_unallocated_pages(page, pages);
}
page->objects = oo_objects(oo);
order = compound_order(page);
page->slab_cache = s;
__SetPageSlab(page);
if (page_is_pfmemalloc(page))
SetPageSlabPfmemalloc(page);
start = page_address(page);
if (unlikely(s->flags & SLAB_POISON))
memset(start, POISON_INUSE, PAGE_SIZE << order);
kasan_poison_slab(page);
shuffle = shuffle_freelist(s, page);
if (!shuffle) {
for_each_object_idx(p, idx, s, start, page->objects) {
setup_object(s, page, p);
if (likely(idx < page->objects))
set_freepointer(s, p, p + s->size);
else
set_freepointer(s, p, NULL);
}
page->freelist = fixup_red_left(s, start);
}
page->inuse = page->objects;
page->frozen = 1;
out:
if (gfpflags_allow_blocking(flags))
local_irq_disable();
if (!page)
return NULL;
mod_zone_page_state(page_zone(page),
(s->flags & SLAB_RECLAIM_ACCOUNT) ?
NR_SLAB_RECLAIMABLE : NR_SLAB_UNRECLAIMABLE,
1 << oo_order(oo));
inc_slabs_node(s, page_to_nid(page), page->objects);
return page;
}
static struct page *new_slab(struct kmem_cache *s, gfp_t flags, int node)
{
if (unlikely(flags & GFP_SLAB_BUG_MASK)) {
gfp_t invalid_mask = flags & GFP_SLAB_BUG_MASK;
flags &= ~GFP_SLAB_BUG_MASK;
pr_warn("Unexpected gfp: %#x (%pGg). Fixing up to gfp: %#x (%pGg). Fix your code!\n",
invalid_mask, &invalid_mask, flags, &flags);
dump_stack();
}
return allocate_slab(s,
flags & (GFP_RECLAIM_MASK | GFP_CONSTRAINT_MASK), node);
}
static void __free_slab(struct kmem_cache *s, struct page *page)
{
int order = compound_order(page);
int pages = 1 << order;
if (s->flags & SLAB_CONSISTENCY_CHECKS) {
void *p;
slab_pad_check(s, page);
for_each_object(p, s, page_address(page),
page->objects)
check_object(s, page, p, SLUB_RED_INACTIVE);
}
kmemcheck_free_shadow(page, compound_order(page));
mod_zone_page_state(page_zone(page),
(s->flags & SLAB_RECLAIM_ACCOUNT) ?
NR_SLAB_RECLAIMABLE : NR_SLAB_UNRECLAIMABLE,
-pages);
__ClearPageSlabPfmemalloc(page);
__ClearPageSlab(page);
page_mapcount_reset(page);
if (current->reclaim_state)
current->reclaim_state->reclaimed_slab += pages;
memcg_uncharge_slab(page, order, s);
__free_pages(page, order);
}
static void rcu_free_slab(struct rcu_head *h)
{
struct page *page;
if (need_reserve_slab_rcu)
page = virt_to_head_page(h);
else
page = container_of((struct list_head *)h, struct page, lru);
__free_slab(page->slab_cache, page);
}
static void free_slab(struct kmem_cache *s, struct page *page)
{
if (unlikely(s->flags & SLAB_DESTROY_BY_RCU)) {
struct rcu_head *head;
if (need_reserve_slab_rcu) {
int order = compound_order(page);
int offset = (PAGE_SIZE << order) - s->reserved;
VM_BUG_ON(s->reserved != sizeof(*head));
head = page_address(page) + offset;
} else {
head = &page->rcu_head;
}
call_rcu(head, rcu_free_slab);
} else
__free_slab(s, page);
}
static void discard_slab(struct kmem_cache *s, struct page *page)
{
dec_slabs_node(s, page_to_nid(page), page->objects);
free_slab(s, page);
}
static inline void
__add_partial(struct kmem_cache_node *n, struct page *page, int tail)
{
n->nr_partial++;
if (tail == DEACTIVATE_TO_TAIL)
list_add_tail(&page->lru, &n->partial);
else
list_add(&page->lru, &n->partial);
}
static inline void add_partial(struct kmem_cache_node *n,
struct page *page, int tail)
{
lockdep_assert_held(&n->list_lock);
__add_partial(n, page, tail);
}
static inline void remove_partial(struct kmem_cache_node *n,
struct page *page)
{
lockdep_assert_held(&n->list_lock);
list_del(&page->lru);
n->nr_partial--;
}
static inline void *acquire_slab(struct kmem_cache *s,
struct kmem_cache_node *n, struct page *page,
int mode, int *objects)
{
void *freelist;
unsigned long counters;
struct page new;
lockdep_assert_held(&n->list_lock);
freelist = page->freelist;
counters = page->counters;
new.counters = counters;
*objects = new.objects - new.inuse;
if (mode) {
new.inuse = page->objects;
new.freelist = NULL;
} else {
new.freelist = freelist;
}
VM_BUG_ON(new.frozen);
new.frozen = 1;
if (!__cmpxchg_double_slab(s, page,
freelist, counters,
new.freelist, new.counters,
"acquire_slab"))
return NULL;
remove_partial(n, page);
WARN_ON(!freelist);
return freelist;
}
static void *get_partial_node(struct kmem_cache *s, struct kmem_cache_node *n,
struct kmem_cache_cpu *c, gfp_t flags)
{
struct page *page, *page2;
void *object = NULL;
int available = 0;
int objects;
if (!n || !n->nr_partial)
return NULL;
spin_lock(&n->list_lock);
list_for_each_entry_safe(page, page2, &n->partial, lru) {
void *t;
if (!pfmemalloc_match(page, flags))
continue;
t = acquire_slab(s, n, page, object == NULL, &objects);
if (!t)
break;
available += objects;
if (!object) {
c->page = page;
stat(s, ALLOC_FROM_PARTIAL);
object = t;
} else {
put_cpu_partial(s, page, 0);
stat(s, CPU_PARTIAL_NODE);
}
if (!kmem_cache_has_cpu_partial(s)
|| available > s->cpu_partial / 2)
break;
}
spin_unlock(&n->list_lock);
return object;
}
static void *get_any_partial(struct kmem_cache *s, gfp_t flags,
struct kmem_cache_cpu *c)
{
#ifdef CONFIG_NUMA
struct zonelist *zonelist;
struct zoneref *z;
struct zone *zone;
enum zone_type high_zoneidx = gfp_zone(flags);
void *object;
unsigned int cpuset_mems_cookie;
if (!s->remote_node_defrag_ratio ||
get_cycles() % 1024 > s->remote_node_defrag_ratio)
return NULL;
do {
cpuset_mems_cookie = read_mems_allowed_begin();
zonelist = node_zonelist(mempolicy_slab_node(), flags);
for_each_zone_zonelist(zone, z, zonelist, high_zoneidx) {
struct kmem_cache_node *n;
n = get_node(s, zone_to_nid(zone));
if (n && cpuset_zone_allowed(zone, flags) &&
n->nr_partial > s->min_partial) {
object = get_partial_node(s, n, c, flags);
if (object) {
return object;
}
}
}
} while (read_mems_allowed_retry(cpuset_mems_cookie));
#endif
return NULL;
}
static void *get_partial(struct kmem_cache *s, gfp_t flags, int node,
struct kmem_cache_cpu *c)
{
void *object;
int searchnode = node;
if (node == NUMA_NO_NODE)
searchnode = numa_mem_id();
else if (!node_present_pages(node))
searchnode = node_to_mem_node(node);
object = get_partial_node(s, get_node(s, searchnode), c, flags);
if (object || node != NUMA_NO_NODE)
return object;
return get_any_partial(s, flags, c);
}
static inline unsigned long next_tid(unsigned long tid)
{
return tid + TID_STEP;
}
static inline unsigned int tid_to_cpu(unsigned long tid)
{
return tid % TID_STEP;
}
static inline unsigned long tid_to_event(unsigned long tid)
{
return tid / TID_STEP;
}
static inline unsigned int init_tid(int cpu)
{
return cpu;
}
static inline void note_cmpxchg_failure(const char *n,
const struct kmem_cache *s, unsigned long tid)
{
#ifdef SLUB_DEBUG_CMPXCHG
unsigned long actual_tid = __this_cpu_read(s->cpu_slab->tid);
pr_info("%s %s: cmpxchg redo ", n, s->name);
#ifdef CONFIG_PREEMPT
if (tid_to_cpu(tid) != tid_to_cpu(actual_tid))
pr_warn("due to cpu change %d -> %d\n",
tid_to_cpu(tid), tid_to_cpu(actual_tid));
else
#endif
if (tid_to_event(tid) != tid_to_event(actual_tid))
pr_warn("due to cpu running other code. Event %ld->%ld\n",
tid_to_event(tid), tid_to_event(actual_tid));
else
pr_warn("for unknown reason: actual=%lx was=%lx target=%lx\n",
actual_tid, tid, next_tid(tid));
#endif
stat(s, CMPXCHG_DOUBLE_CPU_FAIL);
}
static void init_kmem_cache_cpus(struct kmem_cache *s)
{
int cpu;
for_each_possible_cpu(cpu)
per_cpu_ptr(s->cpu_slab, cpu)->tid = init_tid(cpu);
}
static void deactivate_slab(struct kmem_cache *s, struct page *page,
void *freelist)
{
enum slab_modes { M_NONE, M_PARTIAL, M_FULL, M_FREE };
struct kmem_cache_node *n = get_node(s, page_to_nid(page));
int lock = 0;
enum slab_modes l = M_NONE, m = M_NONE;
void *nextfree;
int tail = DEACTIVATE_TO_HEAD;
struct page new;
struct page old;
if (page->freelist) {
stat(s, DEACTIVATE_REMOTE_FREES);
tail = DEACTIVATE_TO_TAIL;
}
while (freelist && (nextfree = get_freepointer(s, freelist))) {
void *prior;
unsigned long counters;
do {
prior = page->freelist;
counters = page->counters;
set_freepointer(s, freelist, prior);
new.counters = counters;
new.inuse--;
VM_BUG_ON(!new.frozen);
} while (!__cmpxchg_double_slab(s, page,
prior, counters,
freelist, new.counters,
"drain percpu freelist"));
freelist = nextfree;
}
redo:
old.freelist = page->freelist;
old.counters = page->counters;
VM_BUG_ON(!old.frozen);
new.counters = old.counters;
if (freelist) {
new.inuse--;
set_freepointer(s, freelist, old.freelist);
new.freelist = freelist;
} else
new.freelist = old.freelist;
new.frozen = 0;
if (!new.inuse && n->nr_partial >= s->min_partial)
m = M_FREE;
else if (new.freelist) {
m = M_PARTIAL;
if (!lock) {
lock = 1;
spin_lock(&n->list_lock);
}
} else {
m = M_FULL;
if (kmem_cache_debug(s) && !lock) {
lock = 1;
spin_lock(&n->list_lock);
}
}
if (l != m) {
if (l == M_PARTIAL)
remove_partial(n, page);
else if (l == M_FULL)
remove_full(s, n, page);
if (m == M_PARTIAL) {
add_partial(n, page, tail);
stat(s, tail);
} else if (m == M_FULL) {
stat(s, DEACTIVATE_FULL);
add_full(s, n, page);
}
}
l = m;
if (!__cmpxchg_double_slab(s, page,
old.freelist, old.counters,
new.freelist, new.counters,
"unfreezing slab"))
goto redo;
if (lock)
spin_unlock(&n->list_lock);
if (m == M_FREE) {
stat(s, DEACTIVATE_EMPTY);
discard_slab(s, page);
stat(s, FREE_SLAB);
}
}
static void unfreeze_partials(struct kmem_cache *s,
struct kmem_cache_cpu *c)
{
#ifdef CONFIG_SLUB_CPU_PARTIAL
struct kmem_cache_node *n = NULL, *n2 = NULL;
struct page *page, *discard_page = NULL;
while ((page = c->partial)) {
struct page new;
struct page old;
c->partial = page->next;
n2 = get_node(s, page_to_nid(page));
if (n != n2) {
if (n)
spin_unlock(&n->list_lock);
n = n2;
spin_lock(&n->list_lock);
}
do {
old.freelist = page->freelist;
old.counters = page->counters;
VM_BUG_ON(!old.frozen);
new.counters = old.counters;
new.freelist = old.freelist;
new.frozen = 0;
} while (!__cmpxchg_double_slab(s, page,
old.freelist, old.counters,
new.freelist, new.counters,
"unfreezing slab"));
if (unlikely(!new.inuse && n->nr_partial >= s->min_partial)) {
page->next = discard_page;
discard_page = page;
} else {
add_partial(n, page, DEACTIVATE_TO_TAIL);
stat(s, FREE_ADD_PARTIAL);
}
}
if (n)
spin_unlock(&n->list_lock);
while (discard_page) {
page = discard_page;
discard_page = discard_page->next;
stat(s, DEACTIVATE_EMPTY);
discard_slab(s, page);
stat(s, FREE_SLAB);
}
#endif
}
static void put_cpu_partial(struct kmem_cache *s, struct page *page, int drain)
{
#ifdef CONFIG_SLUB_CPU_PARTIAL
struct page *oldpage;
int pages;
int pobjects;
preempt_disable();
do {
pages = 0;
pobjects = 0;
oldpage = this_cpu_read(s->cpu_slab->partial);
if (oldpage) {
pobjects = oldpage->pobjects;
pages = oldpage->pages;
if (drain && pobjects > s->cpu_partial) {
unsigned long flags;
local_irq_save(flags);
unfreeze_partials(s, this_cpu_ptr(s->cpu_slab));
local_irq_restore(flags);
oldpage = NULL;
pobjects = 0;
pages = 0;
stat(s, CPU_PARTIAL_DRAIN);
}
}
pages++;
pobjects += page->objects - page->inuse;
page->pages = pages;
page->pobjects = pobjects;
page->next = oldpage;
} while (this_cpu_cmpxchg(s->cpu_slab->partial, oldpage, page)
!= oldpage);
if (unlikely(!s->cpu_partial)) {
unsigned long flags;
local_irq_save(flags);
unfreeze_partials(s, this_cpu_ptr(s->cpu_slab));
local_irq_restore(flags);
}
preempt_enable();
#endif
}
static inline void flush_slab(struct kmem_cache *s, struct kmem_cache_cpu *c)
{
stat(s, CPUSLAB_FLUSH);
deactivate_slab(s, c->page, c->freelist);
c->tid = next_tid(c->tid);
c->page = NULL;
c->freelist = NULL;
}
static inline void __flush_cpu_slab(struct kmem_cache *s, int cpu)
{
struct kmem_cache_cpu *c = per_cpu_ptr(s->cpu_slab, cpu);
if (likely(c)) {
if (c->page)
flush_slab(s, c);
unfreeze_partials(s, c);
}
}
static void flush_cpu_slab(void *d)
{
struct kmem_cache *s = d;
__flush_cpu_slab(s, smp_processor_id());
}
static bool has_cpu_slab(int cpu, void *info)
{
struct kmem_cache *s = info;
struct kmem_cache_cpu *c = per_cpu_ptr(s->cpu_slab, cpu);
return c->page || c->partial;
}
static void flush_all(struct kmem_cache *s)
{
on_each_cpu_cond(has_cpu_slab, flush_cpu_slab, s, 1, GFP_ATOMIC);
}
static int slub_cpu_dead(unsigned int cpu)
{
struct kmem_cache *s;
unsigned long flags;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list) {
local_irq_save(flags);
__flush_cpu_slab(s, cpu);
local_irq_restore(flags);
}
mutex_unlock(&slab_mutex);
return 0;
}
static inline int node_match(struct page *page, int node)
{
#ifdef CONFIG_NUMA
if (!page || (node != NUMA_NO_NODE && page_to_nid(page) != node))
return 0;
#endif
return 1;
}
static int count_free(struct page *page)
{
return page->objects - page->inuse;
}
static inline unsigned long node_nr_objs(struct kmem_cache_node *n)
{
return atomic_long_read(&n->total_objects);
}
static unsigned long count_partial(struct kmem_cache_node *n,
int (*get_count)(struct page *))
{
unsigned long flags;
unsigned long x = 0;
struct page *page;
spin_lock_irqsave(&n->list_lock, flags);
list_for_each_entry(page, &n->partial, lru)
x += get_count(page);
spin_unlock_irqrestore(&n->list_lock, flags);
return x;
}
static noinline void
slab_out_of_memory(struct kmem_cache *s, gfp_t gfpflags, int nid)
{
#ifdef CONFIG_SLUB_DEBUG
static DEFINE_RATELIMIT_STATE(slub_oom_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
int node;
struct kmem_cache_node *n;
if ((gfpflags & __GFP_NOWARN) || !__ratelimit(&slub_oom_rs))
return;
pr_warn("SLUB: Unable to allocate memory on node %d, gfp=%#x(%pGg)\n",
nid, gfpflags, &gfpflags);
pr_warn(" cache: %s, object size: %d, buffer size: %d, default order: %d, min order: %d\n",
s->name, s->object_size, s->size, oo_order(s->oo),
oo_order(s->min));
if (oo_order(s->min) > get_order(s->object_size))
pr_warn(" %s debugging increased min order, use slub_debug=O to disable.\n",
s->name);
for_each_kmem_cache_node(s, node, n) {
unsigned long nr_slabs;
unsigned long nr_objs;
unsigned long nr_free;
nr_free = count_partial(n, count_free);
nr_slabs = node_nr_slabs(n);
nr_objs = node_nr_objs(n);
pr_warn(" node %d: slabs: %ld, objs: %ld, free: %ld\n",
node, nr_slabs, nr_objs, nr_free);
}
#endif
}
static inline void *new_slab_objects(struct kmem_cache *s, gfp_t flags,
int node, struct kmem_cache_cpu **pc)
{
void *freelist;
struct kmem_cache_cpu *c = *pc;
struct page *page;
freelist = get_partial(s, flags, node, c);
if (freelist)
return freelist;
page = new_slab(s, flags, node);
if (page) {
c = raw_cpu_ptr(s->cpu_slab);
if (c->page)
flush_slab(s, c);
freelist = page->freelist;
page->freelist = NULL;
stat(s, ALLOC_SLAB);
c->page = page;
*pc = c;
} else
freelist = NULL;
return freelist;
}
static inline bool pfmemalloc_match(struct page *page, gfp_t gfpflags)
{
if (unlikely(PageSlabPfmemalloc(page)))
return gfp_pfmemalloc_allowed(gfpflags);
return true;
}
static inline void *get_freelist(struct kmem_cache *s, struct page *page)
{
struct page new;
unsigned long counters;
void *freelist;
do {
freelist = page->freelist;
counters = page->counters;
new.counters = counters;
VM_BUG_ON(!new.frozen);
new.inuse = page->objects;
new.frozen = freelist != NULL;
} while (!__cmpxchg_double_slab(s, page,
freelist, counters,
NULL, new.counters,
"get_freelist"));
return freelist;
}
static void *___slab_alloc(struct kmem_cache *s, gfp_t gfpflags, int node,
unsigned long addr, struct kmem_cache_cpu *c)
{
void *freelist;
struct page *page;
page = c->page;
if (!page)
goto new_slab;
redo:
if (unlikely(!node_match(page, node))) {
int searchnode = node;
if (node != NUMA_NO_NODE && !node_present_pages(node))
searchnode = node_to_mem_node(node);
if (unlikely(!node_match(page, searchnode))) {
stat(s, ALLOC_NODE_MISMATCH);
deactivate_slab(s, page, c->freelist);
c->page = NULL;
c->freelist = NULL;
goto new_slab;
}
}
if (unlikely(!pfmemalloc_match(page, gfpflags))) {
deactivate_slab(s, page, c->freelist);
c->page = NULL;
c->freelist = NULL;
goto new_slab;
}
freelist = c->freelist;
if (freelist)
goto load_freelist;
freelist = get_freelist(s, page);
if (!freelist) {
c->page = NULL;
stat(s, DEACTIVATE_BYPASS);
goto new_slab;
}
stat(s, ALLOC_REFILL);
load_freelist:
VM_BUG_ON(!c->page->frozen);
c->freelist = get_freepointer(s, freelist);
c->tid = next_tid(c->tid);
return freelist;
new_slab:
if (c->partial) {
page = c->page = c->partial;
c->partial = page->next;
stat(s, CPU_PARTIAL_ALLOC);
c->freelist = NULL;
goto redo;
}
freelist = new_slab_objects(s, gfpflags, node, &c);
if (unlikely(!freelist)) {
slab_out_of_memory(s, gfpflags, node);
return NULL;
}
page = c->page;
if (likely(!kmem_cache_debug(s) && pfmemalloc_match(page, gfpflags)))
goto load_freelist;
if (kmem_cache_debug(s) &&
!alloc_debug_processing(s, page, freelist, addr))
goto new_slab;
deactivate_slab(s, page, get_freepointer(s, freelist));
c->page = NULL;
c->freelist = NULL;
return freelist;
}
static void *__slab_alloc(struct kmem_cache *s, gfp_t gfpflags, int node,
unsigned long addr, struct kmem_cache_cpu *c)
{
void *p;
unsigned long flags;
local_irq_save(flags);
#ifdef CONFIG_PREEMPT
c = this_cpu_ptr(s->cpu_slab);
#endif
p = ___slab_alloc(s, gfpflags, node, addr, c);
local_irq_restore(flags);
return p;
}
static __always_inline void *slab_alloc_node(struct kmem_cache *s,
gfp_t gfpflags, int node, unsigned long addr)
{
void *object;
struct kmem_cache_cpu *c;
struct page *page;
unsigned long tid;
s = slab_pre_alloc_hook(s, gfpflags);
if (!s)
return NULL;
redo:
do {
tid = this_cpu_read(s->cpu_slab->tid);
c = raw_cpu_ptr(s->cpu_slab);
} while (IS_ENABLED(CONFIG_PREEMPT) &&
unlikely(tid != READ_ONCE(c->tid)));
barrier();
object = c->freelist;
page = c->page;
if (unlikely(!object || !node_match(page, node))) {
object = __slab_alloc(s, gfpflags, node, addr, c);
stat(s, ALLOC_SLOWPATH);
} else {
void *next_object = get_freepointer_safe(s, object);
if (unlikely(!this_cpu_cmpxchg_double(
s->cpu_slab->freelist, s->cpu_slab->tid,
object, tid,
next_object, next_tid(tid)))) {
note_cmpxchg_failure("slab_alloc", s, tid);
goto redo;
}
prefetch_freepointer(s, next_object);
stat(s, ALLOC_FASTPATH);
}
if (unlikely(gfpflags & __GFP_ZERO) && object)
memset(object, 0, s->object_size);
slab_post_alloc_hook(s, gfpflags, 1, &object);
return object;
}
static __always_inline void *slab_alloc(struct kmem_cache *s,
gfp_t gfpflags, unsigned long addr)
{
return slab_alloc_node(s, gfpflags, NUMA_NO_NODE, addr);
}
void *kmem_cache_alloc(struct kmem_cache *s, gfp_t gfpflags)
{
void *ret = slab_alloc(s, gfpflags, _RET_IP_);
trace_kmem_cache_alloc(_RET_IP_, ret, s->object_size,
s->size, gfpflags);
return ret;
}
void *kmem_cache_alloc_trace(struct kmem_cache *s, gfp_t gfpflags, size_t size)
{
void *ret = slab_alloc(s, gfpflags, _RET_IP_);
trace_kmalloc(_RET_IP_, ret, size, s->size, gfpflags);
kasan_kmalloc(s, ret, size, gfpflags);
return ret;
}
void *kmem_cache_alloc_node(struct kmem_cache *s, gfp_t gfpflags, int node)
{
void *ret = slab_alloc_node(s, gfpflags, node, _RET_IP_);
trace_kmem_cache_alloc_node(_RET_IP_, ret,
s->object_size, s->size, gfpflags, node);
return ret;
}
void *kmem_cache_alloc_node_trace(struct kmem_cache *s,
gfp_t gfpflags,
int node, size_t size)
{
void *ret = slab_alloc_node(s, gfpflags, node, _RET_IP_);
trace_kmalloc_node(_RET_IP_, ret,
size, s->size, gfpflags, node);
kasan_kmalloc(s, ret, size, gfpflags);
return ret;
}
static void __slab_free(struct kmem_cache *s, struct page *page,
void *head, void *tail, int cnt,
unsigned long addr)
{
void *prior;
int was_frozen;
struct page new;
unsigned long counters;
struct kmem_cache_node *n = NULL;
unsigned long uninitialized_var(flags);
stat(s, FREE_SLOWPATH);
if (kmem_cache_debug(s) &&
!free_debug_processing(s, page, head, tail, cnt, addr))
return;
do {
if (unlikely(n)) {
spin_unlock_irqrestore(&n->list_lock, flags);
n = NULL;
}
prior = page->freelist;
counters = page->counters;
set_freepointer(s, tail, prior);
new.counters = counters;
was_frozen = new.frozen;
new.inuse -= cnt;
if ((!new.inuse || !prior) && !was_frozen) {
if (kmem_cache_has_cpu_partial(s) && !prior) {
new.frozen = 1;
} else {
n = get_node(s, page_to_nid(page));
spin_lock_irqsave(&n->list_lock, flags);
}
}
} while (!cmpxchg_double_slab(s, page,
prior, counters,
head, new.counters,
"__slab_free"));
if (likely(!n)) {
if (new.frozen && !was_frozen) {
put_cpu_partial(s, page, 1);
stat(s, CPU_PARTIAL_FREE);
}
if (was_frozen)
stat(s, FREE_FROZEN);
return;
}
if (unlikely(!new.inuse && n->nr_partial >= s->min_partial))
goto slab_empty;
if (!kmem_cache_has_cpu_partial(s) && unlikely(!prior)) {
if (kmem_cache_debug(s))
remove_full(s, n, page);
add_partial(n, page, DEACTIVATE_TO_TAIL);
stat(s, FREE_ADD_PARTIAL);
}
spin_unlock_irqrestore(&n->list_lock, flags);
return;
slab_empty:
if (prior) {
remove_partial(n, page);
stat(s, FREE_REMOVE_PARTIAL);
} else {
remove_full(s, n, page);
}
spin_unlock_irqrestore(&n->list_lock, flags);
stat(s, FREE_SLAB);
discard_slab(s, page);
}
static __always_inline void do_slab_free(struct kmem_cache *s,
struct page *page, void *head, void *tail,
int cnt, unsigned long addr)
{
void *tail_obj = tail ? : head;
struct kmem_cache_cpu *c;
unsigned long tid;
redo:
do {
tid = this_cpu_read(s->cpu_slab->tid);
c = raw_cpu_ptr(s->cpu_slab);
} while (IS_ENABLED(CONFIG_PREEMPT) &&
unlikely(tid != READ_ONCE(c->tid)));
barrier();
if (likely(page == c->page)) {
set_freepointer(s, tail_obj, c->freelist);
if (unlikely(!this_cpu_cmpxchg_double(
s->cpu_slab->freelist, s->cpu_slab->tid,
c->freelist, tid,
head, next_tid(tid)))) {
note_cmpxchg_failure("slab_free", s, tid);
goto redo;
}
stat(s, FREE_FASTPATH);
} else
__slab_free(s, page, head, tail_obj, cnt, addr);
}
static __always_inline void slab_free(struct kmem_cache *s, struct page *page,
void *head, void *tail, int cnt,
unsigned long addr)
{
slab_free_freelist_hook(s, head, tail);
if (s->flags & SLAB_KASAN && !(s->flags & SLAB_DESTROY_BY_RCU))
return;
do_slab_free(s, page, head, tail, cnt, addr);
}
void ___cache_free(struct kmem_cache *cache, void *x, unsigned long addr)
{
do_slab_free(cache, virt_to_head_page(x), x, NULL, 1, addr);
}
void kmem_cache_free(struct kmem_cache *s, void *x)
{
s = cache_from_obj(s, x);
if (!s)
return;
slab_free(s, virt_to_head_page(x), x, NULL, 1, _RET_IP_);
trace_kmem_cache_free(_RET_IP_, x);
}
static inline
int build_detached_freelist(struct kmem_cache *s, size_t size,
void **p, struct detached_freelist *df)
{
size_t first_skipped_index = 0;
int lookahead = 3;
void *object;
struct page *page;
df->page = NULL;
do {
object = p[--size];
} while (!object && size);
if (!object)
return 0;
page = virt_to_head_page(object);
if (!s) {
if (unlikely(!PageSlab(page))) {
BUG_ON(!PageCompound(page));
kfree_hook(object);
__free_pages(page, compound_order(page));
p[size] = NULL;
return size;
}
df->s = page->slab_cache;
} else {
df->s = cache_from_obj(s, object);
}
df->page = page;
set_freepointer(df->s, object, NULL);
df->tail = object;
df->freelist = object;
p[size] = NULL;
df->cnt = 1;
while (size) {
object = p[--size];
if (!object)
continue;
if (df->page == virt_to_head_page(object)) {
set_freepointer(df->s, object, df->freelist);
df->freelist = object;
df->cnt++;
p[size] = NULL;
continue;
}
if (!--lookahead)
break;
if (!first_skipped_index)
first_skipped_index = size + 1;
}
return first_skipped_index;
}
void kmem_cache_free_bulk(struct kmem_cache *s, size_t size, void **p)
{
if (WARN_ON(!size))
return;
do {
struct detached_freelist df;
size = build_detached_freelist(s, size, p, &df);
if (!df.page)
continue;
slab_free(df.s, df.page, df.freelist, df.tail, df.cnt,_RET_IP_);
} while (likely(size));
}
int kmem_cache_alloc_bulk(struct kmem_cache *s, gfp_t flags, size_t size,
void **p)
{
struct kmem_cache_cpu *c;
int i;
s = slab_pre_alloc_hook(s, flags);
if (unlikely(!s))
return false;
local_irq_disable();
c = this_cpu_ptr(s->cpu_slab);
for (i = 0; i < size; i++) {
void *object = c->freelist;
if (unlikely(!object)) {
p[i] = ___slab_alloc(s, flags, NUMA_NO_NODE,
_RET_IP_, c);
if (unlikely(!p[i]))
goto error;
c = this_cpu_ptr(s->cpu_slab);
continue;
}
c->freelist = get_freepointer(s, object);
p[i] = object;
}
c->tid = next_tid(c->tid);
local_irq_enable();
if (unlikely(flags & __GFP_ZERO)) {
int j;
for (j = 0; j < i; j++)
memset(p[j], 0, s->object_size);
}
slab_post_alloc_hook(s, flags, size, p);
return i;
error:
local_irq_enable();
slab_post_alloc_hook(s, flags, i, p);
__kmem_cache_free_bulk(s, i, p);
return 0;
}
static inline int slab_order(int size, int min_objects,
int max_order, int fract_leftover, int reserved)
{
int order;
int rem;
int min_order = slub_min_order;
if (order_objects(min_order, size, reserved) > MAX_OBJS_PER_PAGE)
return get_order(size * MAX_OBJS_PER_PAGE) - 1;
for (order = max(min_order, get_order(min_objects * size + reserved));
order <= max_order; order++) {
unsigned long slab_size = PAGE_SIZE << order;
rem = (slab_size - reserved) % size;
if (rem <= slab_size / fract_leftover)
break;
}
return order;
}
static inline int calculate_order(int size, int reserved)
{
int order;
int min_objects;
int fraction;
int max_objects;
min_objects = slub_min_objects;
if (!min_objects)
min_objects = 4 * (fls(nr_cpu_ids) + 1);
max_objects = order_objects(slub_max_order, size, reserved);
min_objects = min(min_objects, max_objects);
while (min_objects > 1) {
fraction = 16;
while (fraction >= 4) {
order = slab_order(size, min_objects,
slub_max_order, fraction, reserved);
if (order <= slub_max_order)
return order;
fraction /= 2;
}
min_objects--;
}
order = slab_order(size, 1, slub_max_order, 1, reserved);
if (order <= slub_max_order)
return order;
order = slab_order(size, 1, MAX_ORDER, 1, reserved);
if (order < MAX_ORDER)
return order;
return -ENOSYS;
}
static void
init_kmem_cache_node(struct kmem_cache_node *n)
{
n->nr_partial = 0;
spin_lock_init(&n->list_lock);
INIT_LIST_HEAD(&n->partial);
#ifdef CONFIG_SLUB_DEBUG
atomic_long_set(&n->nr_slabs, 0);
atomic_long_set(&n->total_objects, 0);
INIT_LIST_HEAD(&n->full);
#endif
}
static inline int alloc_kmem_cache_cpus(struct kmem_cache *s)
{
BUILD_BUG_ON(PERCPU_DYNAMIC_EARLY_SIZE <
KMALLOC_SHIFT_HIGH * sizeof(struct kmem_cache_cpu));
s->cpu_slab = __alloc_percpu(sizeof(struct kmem_cache_cpu),
2 * sizeof(void *));
if (!s->cpu_slab)
return 0;
init_kmem_cache_cpus(s);
return 1;
}
static void early_kmem_cache_node_alloc(int node)
{
struct page *page;
struct kmem_cache_node *n;
BUG_ON(kmem_cache_node->size < sizeof(struct kmem_cache_node));
page = new_slab(kmem_cache_node, GFP_NOWAIT, node);
BUG_ON(!page);
if (page_to_nid(page) != node) {
pr_err("SLUB: Unable to allocate memory from node %d\n", node);
pr_err("SLUB: Allocating a useless per node structure in order to be able to continue\n");
}
n = page->freelist;
BUG_ON(!n);
page->freelist = get_freepointer(kmem_cache_node, n);
page->inuse = 1;
page->frozen = 0;
kmem_cache_node->node[node] = n;
#ifdef CONFIG_SLUB_DEBUG
init_object(kmem_cache_node, n, SLUB_RED_ACTIVE);
init_tracking(kmem_cache_node, n);
#endif
kasan_kmalloc(kmem_cache_node, n, sizeof(struct kmem_cache_node),
GFP_KERNEL);
init_kmem_cache_node(n);
inc_slabs_node(kmem_cache_node, node, page->objects);
__add_partial(n, page, DEACTIVATE_TO_HEAD);
}
static void free_kmem_cache_nodes(struct kmem_cache *s)
{
int node;
struct kmem_cache_node *n;
for_each_kmem_cache_node(s, node, n) {
kmem_cache_free(kmem_cache_node, n);
s->node[node] = NULL;
}
}
void __kmem_cache_release(struct kmem_cache *s)
{
cache_random_seq_destroy(s);
free_percpu(s->cpu_slab);
free_kmem_cache_nodes(s);
}
static int init_kmem_cache_nodes(struct kmem_cache *s)
{
int node;
for_each_node_state(node, N_NORMAL_MEMORY) {
struct kmem_cache_node *n;
if (slab_state == DOWN) {
early_kmem_cache_node_alloc(node);
continue;
}
n = kmem_cache_alloc_node(kmem_cache_node,
GFP_KERNEL, node);
if (!n) {
free_kmem_cache_nodes(s);
return 0;
}
s->node[node] = n;
init_kmem_cache_node(n);
}
return 1;
}
static void set_min_partial(struct kmem_cache *s, unsigned long min)
{
if (min < MIN_PARTIAL)
min = MIN_PARTIAL;
else if (min > MAX_PARTIAL)
min = MAX_PARTIAL;
s->min_partial = min;
}
static int calculate_sizes(struct kmem_cache *s, int forced_order)
{
unsigned long flags = s->flags;
size_t size = s->object_size;
int order;
size = ALIGN(size, sizeof(void *));
#ifdef CONFIG_SLUB_DEBUG
if ((flags & SLAB_POISON) && !(flags & SLAB_DESTROY_BY_RCU) &&
!s->ctor)
s->flags |= __OBJECT_POISON;
else
s->flags &= ~__OBJECT_POISON;
if ((flags & SLAB_RED_ZONE) && size == s->object_size)
size += sizeof(void *);
#endif
s->inuse = size;
if (((flags & (SLAB_DESTROY_BY_RCU | SLAB_POISON)) ||
s->ctor)) {
s->offset = size;
size += sizeof(void *);
}
#ifdef CONFIG_SLUB_DEBUG
if (flags & SLAB_STORE_USER)
size += 2 * sizeof(struct track);
#endif
kasan_cache_create(s, &size, &s->flags);
#ifdef CONFIG_SLUB_DEBUG
if (flags & SLAB_RED_ZONE) {
size += sizeof(void *);
s->red_left_pad = sizeof(void *);
s->red_left_pad = ALIGN(s->red_left_pad, s->align);
size += s->red_left_pad;
}
#endif
size = ALIGN(size, s->align);
s->size = size;
if (forced_order >= 0)
order = forced_order;
else
order = calculate_order(size, s->reserved);
if (order < 0)
return 0;
s->allocflags = 0;
if (order)
s->allocflags |= __GFP_COMP;
if (s->flags & SLAB_CACHE_DMA)
s->allocflags |= GFP_DMA;
if (s->flags & SLAB_RECLAIM_ACCOUNT)
s->allocflags |= __GFP_RECLAIMABLE;
s->oo = oo_make(order, size, s->reserved);
s->min = oo_make(get_order(size), size, s->reserved);
if (oo_objects(s->oo) > oo_objects(s->max))
s->max = s->oo;
return !!oo_objects(s->oo);
}
static int kmem_cache_open(struct kmem_cache *s, unsigned long flags)
{
s->flags = kmem_cache_flags(s->size, flags, s->name, s->ctor);
s->reserved = 0;
if (need_reserve_slab_rcu && (s->flags & SLAB_DESTROY_BY_RCU))
s->reserved = sizeof(struct rcu_head);
if (!calculate_sizes(s, -1))
goto error;
if (disable_higher_order_debug) {
if (get_order(s->size) > get_order(s->object_size)) {
s->flags &= ~DEBUG_METADATA_FLAGS;
s->offset = 0;
if (!calculate_sizes(s, -1))
goto error;
}
}
#if defined(CONFIG_HAVE_CMPXCHG_DOUBLE) && \
defined(CONFIG_HAVE_ALIGNED_STRUCT_PAGE)
if (system_has_cmpxchg_double() && (s->flags & SLAB_NO_CMPXCHG) == 0)
s->flags |= __CMPXCHG_DOUBLE;
#endif
set_min_partial(s, ilog2(s->size) / 2);
if (!kmem_cache_has_cpu_partial(s))
s->cpu_partial = 0;
else if (s->size >= PAGE_SIZE)
s->cpu_partial = 2;
else if (s->size >= 1024)
s->cpu_partial = 6;
else if (s->size >= 256)
s->cpu_partial = 13;
else
s->cpu_partial = 30;
#ifdef CONFIG_NUMA
s->remote_node_defrag_ratio = 1000;
#endif
if (slab_state >= UP) {
if (init_cache_random_seq(s))
goto error;
}
if (!init_kmem_cache_nodes(s))
goto error;
if (alloc_kmem_cache_cpus(s))
return 0;
free_kmem_cache_nodes(s);
error:
if (flags & SLAB_PANIC)
panic("Cannot create slab %s size=%lu realsize=%u order=%u offset=%u flags=%lx\n",
s->name, (unsigned long)s->size, s->size,
oo_order(s->oo), s->offset, flags);
return -EINVAL;
}
static void list_slab_objects(struct kmem_cache *s, struct page *page,
const char *text)
{
#ifdef CONFIG_SLUB_DEBUG
void *addr = page_address(page);
void *p;
unsigned long *map = kzalloc(BITS_TO_LONGS(page->objects) *
sizeof(long), GFP_ATOMIC);
if (!map)
return;
slab_err(s, page, text, s->name);
slab_lock(page);
get_map(s, page, map);
for_each_object(p, s, addr, page->objects) {
if (!test_bit(slab_index(p, s, addr), map)) {
pr_err("INFO: Object 0x%p @offset=%tu\n", p, p - addr);
print_tracking(s, p);
}
}
slab_unlock(page);
kfree(map);
#endif
}
static void free_partial(struct kmem_cache *s, struct kmem_cache_node *n)
{
LIST_HEAD(discard);
struct page *page, *h;
BUG_ON(irqs_disabled());
spin_lock_irq(&n->list_lock);
list_for_each_entry_safe(page, h, &n->partial, lru) {
if (!page->inuse) {
remove_partial(n, page);
list_add(&page->lru, &discard);
} else {
list_slab_objects(s, page,
"Objects remaining in %s on __kmem_cache_shutdown()");
}
}
spin_unlock_irq(&n->list_lock);
list_for_each_entry_safe(page, h, &discard, lru)
discard_slab(s, page);
}
int __kmem_cache_shutdown(struct kmem_cache *s)
{
int node;
struct kmem_cache_node *n;
flush_all(s);
for_each_kmem_cache_node(s, node, n) {
free_partial(s, n);
if (n->nr_partial || slabs_node(s, node))
return 1;
}
sysfs_slab_remove(s);
return 0;
}
static int __init setup_slub_min_order(char *str)
{
get_option(&str, &slub_min_order);
return 1;
}
static int __init setup_slub_max_order(char *str)
{
get_option(&str, &slub_max_order);
slub_max_order = min(slub_max_order, MAX_ORDER - 1);
return 1;
}
static int __init setup_slub_min_objects(char *str)
{
get_option(&str, &slub_min_objects);
return 1;
}
void *__kmalloc(size_t size, gfp_t flags)
{
struct kmem_cache *s;
void *ret;
if (unlikely(size > KMALLOC_MAX_CACHE_SIZE))
return kmalloc_large(size, flags);
s = kmalloc_slab(size, flags);
if (unlikely(ZERO_OR_NULL_PTR(s)))
return s;
ret = slab_alloc(s, flags, _RET_IP_);
trace_kmalloc(_RET_IP_, ret, size, s->size, flags);
kasan_kmalloc(s, ret, size, flags);
return ret;
}
static void *kmalloc_large_node(size_t size, gfp_t flags, int node)
{
struct page *page;
void *ptr = NULL;
flags |= __GFP_COMP | __GFP_NOTRACK;
page = alloc_pages_node(node, flags, get_order(size));
if (page)
ptr = page_address(page);
kmalloc_large_node_hook(ptr, size, flags);
return ptr;
}
void *__kmalloc_node(size_t size, gfp_t flags, int node)
{
struct kmem_cache *s;
void *ret;
if (unlikely(size > KMALLOC_MAX_CACHE_SIZE)) {
ret = kmalloc_large_node(size, flags, node);
trace_kmalloc_node(_RET_IP_, ret,
size, PAGE_SIZE << get_order(size),
flags, node);
return ret;
}
s = kmalloc_slab(size, flags);
if (unlikely(ZERO_OR_NULL_PTR(s)))
return s;
ret = slab_alloc_node(s, flags, node, _RET_IP_);
trace_kmalloc_node(_RET_IP_, ret, size, s->size, flags, node);
kasan_kmalloc(s, ret, size, flags);
return ret;
}
const char *__check_heap_object(const void *ptr, unsigned long n,
struct page *page)
{
struct kmem_cache *s;
unsigned long offset;
size_t object_size;
s = page->slab_cache;
object_size = slab_ksize(s);
if (ptr < page_address(page))
return s->name;
offset = (ptr - page_address(page)) % s->size;
if (kmem_cache_debug(s) && s->flags & SLAB_RED_ZONE) {
if (offset < s->red_left_pad)
return s->name;
offset -= s->red_left_pad;
}
if (offset <= object_size && n <= object_size - offset)
return NULL;
return s->name;
}
static size_t __ksize(const void *object)
{
struct page *page;
if (unlikely(object == ZERO_SIZE_PTR))
return 0;
page = virt_to_head_page(object);
if (unlikely(!PageSlab(page))) {
WARN_ON(!PageCompound(page));
return PAGE_SIZE << compound_order(page);
}
return slab_ksize(page->slab_cache);
}
size_t ksize(const void *object)
{
size_t size = __ksize(object);
kasan_unpoison_shadow(object, size);
return size;
}
void kfree(const void *x)
{
struct page *page;
void *object = (void *)x;
trace_kfree(_RET_IP_, x);
if (unlikely(ZERO_OR_NULL_PTR(x)))
return;
page = virt_to_head_page(x);
if (unlikely(!PageSlab(page))) {
BUG_ON(!PageCompound(page));
kfree_hook(x);
__free_pages(page, compound_order(page));
return;
}
slab_free(page->slab_cache, page, object, NULL, 1, _RET_IP_);
}
int __kmem_cache_shrink(struct kmem_cache *s)
{
int node;
int i;
struct kmem_cache_node *n;
struct page *page;
struct page *t;
struct list_head discard;
struct list_head promote[SHRINK_PROMOTE_MAX];
unsigned long flags;
int ret = 0;
flush_all(s);
for_each_kmem_cache_node(s, node, n) {
INIT_LIST_HEAD(&discard);
for (i = 0; i < SHRINK_PROMOTE_MAX; i++)
INIT_LIST_HEAD(promote + i);
spin_lock_irqsave(&n->list_lock, flags);
list_for_each_entry_safe(page, t, &n->partial, lru) {
int free = page->objects - page->inuse;
barrier();
BUG_ON(free <= 0);
if (free == page->objects) {
list_move(&page->lru, &discard);
n->nr_partial--;
} else if (free <= SHRINK_PROMOTE_MAX)
list_move(&page->lru, promote + free - 1);
}
for (i = SHRINK_PROMOTE_MAX - 1; i >= 0; i--)
list_splice(promote + i, &n->partial);
spin_unlock_irqrestore(&n->list_lock, flags);
list_for_each_entry_safe(page, t, &discard, lru)
discard_slab(s, page);
if (slabs_node(s, node))
ret = 1;
}
return ret;
}
static void kmemcg_cache_deact_after_rcu(struct kmem_cache *s)
{
if (!__kmem_cache_shrink(s))
sysfs_slab_remove(s);
}
void __kmemcg_cache_deactivate(struct kmem_cache *s)
{
s->cpu_partial = 0;
s->min_partial = 0;
slab_deactivate_memcg_cache_rcu_sched(s, kmemcg_cache_deact_after_rcu);
}
static int slab_mem_going_offline_callback(void *arg)
{
struct kmem_cache *s;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list)
__kmem_cache_shrink(s);
mutex_unlock(&slab_mutex);
return 0;
}
static void slab_mem_offline_callback(void *arg)
{
struct kmem_cache_node *n;
struct kmem_cache *s;
struct memory_notify *marg = arg;
int offline_node;
offline_node = marg->status_change_nid_normal;
if (offline_node < 0)
return;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list) {
n = get_node(s, offline_node);
if (n) {
BUG_ON(slabs_node(s, offline_node));
s->node[offline_node] = NULL;
kmem_cache_free(kmem_cache_node, n);
}
}
mutex_unlock(&slab_mutex);
}
static int slab_mem_going_online_callback(void *arg)
{
struct kmem_cache_node *n;
struct kmem_cache *s;
struct memory_notify *marg = arg;
int nid = marg->status_change_nid_normal;
int ret = 0;
if (nid < 0)
return 0;
mutex_lock(&slab_mutex);
list_for_each_entry(s, &slab_caches, list) {
n = kmem_cache_alloc(kmem_cache_node, GFP_KERNEL);
if (!n) {
ret = -ENOMEM;
goto out;
}
init_kmem_cache_node(n);
s->node[nid] = n;
}
out:
mutex_unlock(&slab_mutex);
return ret;
}
static int slab_memory_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
int ret = 0;
switch (action) {
case MEM_GOING_ONLINE:
ret = slab_mem_going_online_callback(arg);
break;
case MEM_GOING_OFFLINE:
ret = slab_mem_going_offline_callback(arg);
break;
case MEM_OFFLINE:
case MEM_CANCEL_ONLINE:
slab_mem_offline_callback(arg);
break;
case MEM_ONLINE:
case MEM_CANCEL_OFFLINE:
break;
}
if (ret)
ret = notifier_from_errno(ret);
else
ret = NOTIFY_OK;
return ret;
}
static struct kmem_cache * __init bootstrap(struct kmem_cache *static_cache)
{
int node;
struct kmem_cache *s = kmem_cache_zalloc(kmem_cache, GFP_NOWAIT);
struct kmem_cache_node *n;
memcpy(s, static_cache, kmem_cache->object_size);
__flush_cpu_slab(s, smp_processor_id());
for_each_kmem_cache_node(s, node, n) {
struct page *p;
list_for_each_entry(p, &n->partial, lru)
p->slab_cache = s;
#ifdef CONFIG_SLUB_DEBUG
list_for_each_entry(p, &n->full, lru)
p->slab_cache = s;
#endif
}
slab_init_memcg_params(s);
list_add(&s->list, &slab_caches);
memcg_link_cache(s);
return s;
}
void __init kmem_cache_init(void)
{
static __initdata struct kmem_cache boot_kmem_cache,
boot_kmem_cache_node;
if (debug_guardpage_minorder())
slub_max_order = 0;
kmem_cache_node = &boot_kmem_cache_node;
kmem_cache = &boot_kmem_cache;
create_boot_cache(kmem_cache_node, "kmem_cache_node",
sizeof(struct kmem_cache_node), SLAB_HWCACHE_ALIGN);
register_hotmemory_notifier(&slab_memory_callback_nb);
slab_state = PARTIAL;
create_boot_cache(kmem_cache, "kmem_cache",
offsetof(struct kmem_cache, node) +
nr_node_ids * sizeof(struct kmem_cache_node *),
SLAB_HWCACHE_ALIGN);
kmem_cache = bootstrap(&boot_kmem_cache);
kmem_cache_node = bootstrap(&boot_kmem_cache_node);
setup_kmalloc_cache_index_table();
create_kmalloc_caches(0);
init_freelist_randomization();
cpuhp_setup_state_nocalls(CPUHP_SLUB_DEAD, "slub:dead", NULL,
slub_cpu_dead);
pr_info("SLUB: HWalign=%d, Order=%d-%d, MinObjects=%d, CPUs=%d, Nodes=%d\n",
cache_line_size(),
slub_min_order, slub_max_order, slub_min_objects,
nr_cpu_ids, nr_node_ids);
}
void __init kmem_cache_init_late(void)
{
}
struct kmem_cache *
__kmem_cache_alias(const char *name, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *))
{
struct kmem_cache *s, *c;
s = find_mergeable(size, align, flags, name, ctor);
if (s) {
s->refcount++;
s->object_size = max(s->object_size, (int)size);
s->inuse = max_t(int, s->inuse, ALIGN(size, sizeof(void *)));
for_each_memcg_cache(c, s) {
c->object_size = s->object_size;
c->inuse = max_t(int, c->inuse,
ALIGN(size, sizeof(void *)));
}
if (sysfs_slab_alias(s, name)) {
s->refcount--;
s = NULL;
}
}
return s;
}
int __kmem_cache_create(struct kmem_cache *s, unsigned long flags)
{
int err;
err = kmem_cache_open(s, flags);
if (err)
return err;
if (slab_state <= UP)
return 0;
memcg_propagate_slab_attrs(s);
err = sysfs_slab_add(s);
if (err)
__kmem_cache_release(s);
return err;
}
void *__kmalloc_track_caller(size_t size, gfp_t gfpflags, unsigned long caller)
{
struct kmem_cache *s;
void *ret;
if (unlikely(size > KMALLOC_MAX_CACHE_SIZE))
return kmalloc_large(size, gfpflags);
s = kmalloc_slab(size, gfpflags);
if (unlikely(ZERO_OR_NULL_PTR(s)))
return s;
ret = slab_alloc(s, gfpflags, caller);
trace_kmalloc(caller, ret, size, s->size, gfpflags);
return ret;
}
void *__kmalloc_node_track_caller(size_t size, gfp_t gfpflags,
int node, unsigned long caller)
{
struct kmem_cache *s;
void *ret;
if (unlikely(size > KMALLOC_MAX_CACHE_SIZE)) {
ret = kmalloc_large_node(size, gfpflags, node);
trace_kmalloc_node(caller, ret,
size, PAGE_SIZE << get_order(size),
gfpflags, node);
return ret;
}
s = kmalloc_slab(size, gfpflags);
if (unlikely(ZERO_OR_NULL_PTR(s)))
return s;
ret = slab_alloc_node(s, gfpflags, node, caller);
trace_kmalloc_node(caller, ret, size, s->size, gfpflags, node);
return ret;
}
static int count_inuse(struct page *page)
{
return page->inuse;
}
static int count_total(struct page *page)
{
return page->objects;
}
static int validate_slab(struct kmem_cache *s, struct page *page,
unsigned long *map)
{
void *p;
void *addr = page_address(page);
if (!check_slab(s, page) ||
!on_freelist(s, page, NULL))
return 0;
bitmap_zero(map, page->objects);
get_map(s, page, map);
for_each_object(p, s, addr, page->objects) {
if (test_bit(slab_index(p, s, addr), map))
if (!check_object(s, page, p, SLUB_RED_INACTIVE))
return 0;
}
for_each_object(p, s, addr, page->objects)
if (!test_bit(slab_index(p, s, addr), map))
if (!check_object(s, page, p, SLUB_RED_ACTIVE))
return 0;
return 1;
}
static void validate_slab_slab(struct kmem_cache *s, struct page *page,
unsigned long *map)
{
slab_lock(page);
validate_slab(s, page, map);
slab_unlock(page);
}
static int validate_slab_node(struct kmem_cache *s,
struct kmem_cache_node *n, unsigned long *map)
{
unsigned long count = 0;
struct page *page;
unsigned long flags;
spin_lock_irqsave(&n->list_lock, flags);
list_for_each_entry(page, &n->partial, lru) {
validate_slab_slab(s, page, map);
count++;
}
if (count != n->nr_partial)
pr_err("SLUB %s: %ld partial slabs counted but counter=%ld\n",
s->name, count, n->nr_partial);
if (!(s->flags & SLAB_STORE_USER))
goto out;
list_for_each_entry(page, &n->full, lru) {
validate_slab_slab(s, page, map);
count++;
}
if (count != atomic_long_read(&n->nr_slabs))
pr_err("SLUB: %s %ld slabs counted but counter=%ld\n",
s->name, count, atomic_long_read(&n->nr_slabs));
out:
spin_unlock_irqrestore(&n->list_lock, flags);
return count;
}
static long validate_slab_cache(struct kmem_cache *s)
{
int node;
unsigned long count = 0;
unsigned long *map = kmalloc(BITS_TO_LONGS(oo_objects(s->max)) *
sizeof(unsigned long), GFP_KERNEL);
struct kmem_cache_node *n;
if (!map)
return -ENOMEM;
flush_all(s);
for_each_kmem_cache_node(s, node, n)
count += validate_slab_node(s, n, map);
kfree(map);
return count;
}
static void free_loc_track(struct loc_track *t)
{
if (t->max)
free_pages((unsigned long)t->loc,
get_order(sizeof(struct location) * t->max));
}
static int alloc_loc_track(struct loc_track *t, unsigned long max, gfp_t flags)
{
struct location *l;
int order;
order = get_order(sizeof(struct location) * max);
l = (void *)__get_free_pages(flags, order);
if (!l)
return 0;
if (t->count) {
memcpy(l, t->loc, sizeof(struct location) * t->count);
free_loc_track(t);
}
t->max = max;
t->loc = l;
return 1;
}
static int add_location(struct loc_track *t, struct kmem_cache *s,
const struct track *track)
{
long start, end, pos;
struct location *l;
unsigned long caddr;
unsigned long age = jiffies - track->when;
start = -1;
end = t->count;
for ( ; ; ) {
pos = start + (end - start + 1) / 2;
if (pos == end)
break;
caddr = t->loc[pos].addr;
if (track->addr == caddr) {
l = &t->loc[pos];
l->count++;
if (track->when) {
l->sum_time += age;
if (age < l->min_time)
l->min_time = age;
if (age > l->max_time)
l->max_time = age;
if (track->pid < l->min_pid)
l->min_pid = track->pid;
if (track->pid > l->max_pid)
l->max_pid = track->pid;
cpumask_set_cpu(track->cpu,
to_cpumask(l->cpus));
}
node_set(page_to_nid(virt_to_page(track)), l->nodes);
return 1;
}
if (track->addr < caddr)
end = pos;
else
start = pos;
}
if (t->count >= t->max && !alloc_loc_track(t, 2 * t->max, GFP_ATOMIC))
return 0;
l = t->loc + pos;
if (pos < t->count)
memmove(l + 1, l,
(t->count - pos) * sizeof(struct location));
t->count++;
l->count = 1;
l->addr = track->addr;
l->sum_time = age;
l->min_time = age;
l->max_time = age;
l->min_pid = track->pid;
l->max_pid = track->pid;
cpumask_clear(to_cpumask(l->cpus));
cpumask_set_cpu(track->cpu, to_cpumask(l->cpus));
nodes_clear(l->nodes);
node_set(page_to_nid(virt_to_page(track)), l->nodes);
return 1;
}
static void process_slab(struct loc_track *t, struct kmem_cache *s,
struct page *page, enum track_item alloc,
unsigned long *map)
{
void *addr = page_address(page);
void *p;
bitmap_zero(map, page->objects);
get_map(s, page, map);
for_each_object(p, s, addr, page->objects)
if (!test_bit(slab_index(p, s, addr), map))
add_location(t, s, get_track(s, p, alloc));
}
static int list_locations(struct kmem_cache *s, char *buf,
enum track_item alloc)
{
int len = 0;
unsigned long i;
struct loc_track t = { 0, 0, NULL };
int node;
unsigned long *map = kmalloc(BITS_TO_LONGS(oo_objects(s->max)) *
sizeof(unsigned long), GFP_KERNEL);
struct kmem_cache_node *n;
if (!map || !alloc_loc_track(&t, PAGE_SIZE / sizeof(struct location),
GFP_TEMPORARY)) {
kfree(map);
return sprintf(buf, "Out of memory\n");
}
flush_all(s);
for_each_kmem_cache_node(s, node, n) {
unsigned long flags;
struct page *page;
if (!atomic_long_read(&n->nr_slabs))
continue;
spin_lock_irqsave(&n->list_lock, flags);
list_for_each_entry(page, &n->partial, lru)
process_slab(&t, s, page, alloc, map);
list_for_each_entry(page, &n->full, lru)
process_slab(&t, s, page, alloc, map);
spin_unlock_irqrestore(&n->list_lock, flags);
}
for (i = 0; i < t.count; i++) {
struct location *l = &t.loc[i];
if (len > PAGE_SIZE - KSYM_SYMBOL_LEN - 100)
break;
len += sprintf(buf + len, "%7ld ", l->count);
if (l->addr)
len += sprintf(buf + len, "%pS", (void *)l->addr);
else
len += sprintf(buf + len, "<not-available>");
if (l->sum_time != l->min_time) {
len += sprintf(buf + len, " age=%ld/%ld/%ld",
l->min_time,
(long)div_u64(l->sum_time, l->count),
l->max_time);
} else
len += sprintf(buf + len, " age=%ld",
l->min_time);
if (l->min_pid != l->max_pid)
len += sprintf(buf + len, " pid=%ld-%ld",
l->min_pid, l->max_pid);
else
len += sprintf(buf + len, " pid=%ld",
l->min_pid);
if (num_online_cpus() > 1 &&
!cpumask_empty(to_cpumask(l->cpus)) &&
len < PAGE_SIZE - 60)
len += scnprintf(buf + len, PAGE_SIZE - len - 50,
" cpus=%*pbl",
cpumask_pr_args(to_cpumask(l->cpus)));
if (nr_online_nodes > 1 && !nodes_empty(l->nodes) &&
len < PAGE_SIZE - 60)
len += scnprintf(buf + len, PAGE_SIZE - len - 50,
" nodes=%*pbl",
nodemask_pr_args(&l->nodes));
len += sprintf(buf + len, "\n");
}
free_loc_track(&t);
kfree(map);
if (!t.count)
len += sprintf(buf, "No data\n");
return len;
}
static void __init resiliency_test(void)
{
u8 *p;
BUILD_BUG_ON(KMALLOC_MIN_SIZE > 16 || KMALLOC_SHIFT_HIGH < 10);
pr_err("SLUB resiliency testing\n");
pr_err("-----------------------\n");
pr_err("A. Corruption after allocation\n");
p = kzalloc(16, GFP_KERNEL);
p[16] = 0x12;
pr_err("\n1. kmalloc-16: Clobber Redzone/next pointer 0x12->0x%p\n\n",
p + 16);
validate_slab_cache(kmalloc_caches[4]);
p = kzalloc(32, GFP_KERNEL);
p[32 + sizeof(void *)] = 0x34;
pr_err("\n2. kmalloc-32: Clobber next pointer/next slab 0x34 -> -0x%p\n",
p);
pr_err("If allocated object is overwritten then not detectable\n\n");
validate_slab_cache(kmalloc_caches[5]);
p = kzalloc(64, GFP_KERNEL);
p += 64 + (get_cycles() & 0xff) * sizeof(void *);
*p = 0x56;
pr_err("\n3. kmalloc-64: corrupting random byte 0x56->0x%p\n",
p);
pr_err("If allocated object is overwritten then not detectable\n\n");
validate_slab_cache(kmalloc_caches[6]);
pr_err("\nB. Corruption after free\n");
p = kzalloc(128, GFP_KERNEL);
kfree(p);
*p = 0x78;
pr_err("1. kmalloc-128: Clobber first word 0x78->0x%p\n\n", p);
validate_slab_cache(kmalloc_caches[7]);
p = kzalloc(256, GFP_KERNEL);
kfree(p);
p[50] = 0x9a;
pr_err("\n2. kmalloc-256: Clobber 50th byte 0x9a->0x%p\n\n", p);
validate_slab_cache(kmalloc_caches[8]);
p = kzalloc(512, GFP_KERNEL);
kfree(p);
p[512] = 0xab;
pr_err("\n3. kmalloc-512: Clobber redzone 0xab->0x%p\n\n", p);
validate_slab_cache(kmalloc_caches[9]);
}
static void resiliency_test(void) {}
static int __init setup_slub_memcg_sysfs(char *str)
{
int v;
if (get_option(&str, &v) > 0)
memcg_sysfs_enabled = v;
return 1;
}
static ssize_t show_slab_objects(struct kmem_cache *s,
char *buf, unsigned long flags)
{
unsigned long total = 0;
int node;
int x;
unsigned long *nodes;
nodes = kzalloc(sizeof(unsigned long) * nr_node_ids, GFP_KERNEL);
if (!nodes)
return -ENOMEM;
if (flags & SO_CPU) {
int cpu;
for_each_possible_cpu(cpu) {
struct kmem_cache_cpu *c = per_cpu_ptr(s->cpu_slab,
cpu);
int node;
struct page *page;
page = READ_ONCE(c->page);
if (!page)
continue;
node = page_to_nid(page);
if (flags & SO_TOTAL)
x = page->objects;
else if (flags & SO_OBJECTS)
x = page->inuse;
else
x = 1;
total += x;
nodes[node] += x;
page = READ_ONCE(c->partial);
if (page) {
node = page_to_nid(page);
if (flags & SO_TOTAL)
WARN_ON_ONCE(1);
else if (flags & SO_OBJECTS)
WARN_ON_ONCE(1);
else
x = page->pages;
total += x;
nodes[node] += x;
}
}
}
get_online_mems();
#ifdef CONFIG_SLUB_DEBUG
if (flags & SO_ALL) {
struct kmem_cache_node *n;
for_each_kmem_cache_node(s, node, n) {
if (flags & SO_TOTAL)
x = atomic_long_read(&n->total_objects);
else if (flags & SO_OBJECTS)
x = atomic_long_read(&n->total_objects) -
count_partial(n, count_free);
else
x = atomic_long_read(&n->nr_slabs);
total += x;
nodes[node] += x;
}
} else
#endif
if (flags & SO_PARTIAL) {
struct kmem_cache_node *n;
for_each_kmem_cache_node(s, node, n) {
if (flags & SO_TOTAL)
x = count_partial(n, count_total);
else if (flags & SO_OBJECTS)
x = count_partial(n, count_inuse);
else
x = n->nr_partial;
total += x;
nodes[node] += x;
}
}
x = sprintf(buf, "%lu", total);
#ifdef CONFIG_NUMA
for (node = 0; node < nr_node_ids; node++)
if (nodes[node])
x += sprintf(buf + x, " N%d=%lu",
node, nodes[node]);
#endif
put_online_mems();
kfree(nodes);
return x + sprintf(buf + x, "\n");
}
static int any_slab_objects(struct kmem_cache *s)
{
int node;
struct kmem_cache_node *n;
for_each_kmem_cache_node(s, node, n)
if (atomic_long_read(&n->total_objects))
return 1;
return 0;
}
static ssize_t slab_size_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", s->size);
}
static ssize_t align_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", s->align);
}
static ssize_t object_size_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", s->object_size);
}
static ssize_t objs_per_slab_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", oo_objects(s->oo));
}
static ssize_t order_store(struct kmem_cache *s,
const char *buf, size_t length)
{
unsigned long order;
int err;
err = kstrtoul(buf, 10, &order);
if (err)
return err;
if (order > slub_max_order || order < slub_min_order)
return -EINVAL;
calculate_sizes(s, order);
return length;
}
static ssize_t order_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", oo_order(s->oo));
}
static ssize_t min_partial_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%lu\n", s->min_partial);
}
static ssize_t min_partial_store(struct kmem_cache *s, const char *buf,
size_t length)
{
unsigned long min;
int err;
err = kstrtoul(buf, 10, &min);
if (err)
return err;
set_min_partial(s, min);
return length;
}
static ssize_t cpu_partial_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%u\n", s->cpu_partial);
}
static ssize_t cpu_partial_store(struct kmem_cache *s, const char *buf,
size_t length)
{
unsigned long objects;
int err;
err = kstrtoul(buf, 10, &objects);
if (err)
return err;
if (objects && !kmem_cache_has_cpu_partial(s))
return -EINVAL;
s->cpu_partial = objects;
flush_all(s);
return length;
}
static ssize_t ctor_show(struct kmem_cache *s, char *buf)
{
if (!s->ctor)
return 0;
return sprintf(buf, "%pS\n", s->ctor);
}
static ssize_t aliases_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", s->refcount < 0 ? 0 : s->refcount - 1);
}
static ssize_t partial_show(struct kmem_cache *s, char *buf)
{
return show_slab_objects(s, buf, SO_PARTIAL);
}
static ssize_t cpu_slabs_show(struct kmem_cache *s, char *buf)
{
return show_slab_objects(s, buf, SO_CPU);
}
static ssize_t objects_show(struct kmem_cache *s, char *buf)
{
return show_slab_objects(s, buf, SO_ALL|SO_OBJECTS);
}
static ssize_t objects_partial_show(struct kmem_cache *s, char *buf)
{
return show_slab_objects(s, buf, SO_PARTIAL|SO_OBJECTS);
}
static ssize_t slabs_cpu_partial_show(struct kmem_cache *s, char *buf)
{
int objects = 0;
int pages = 0;
int cpu;
int len;
for_each_online_cpu(cpu) {
struct page *page = per_cpu_ptr(s->cpu_slab, cpu)->partial;
if (page) {
pages += page->pages;
objects += page->pobjects;
}
}
len = sprintf(buf, "%d(%d)", objects, pages);
#ifdef CONFIG_SMP
for_each_online_cpu(cpu) {
struct page *page = per_cpu_ptr(s->cpu_slab, cpu) ->partial;
if (page && len < PAGE_SIZE - 20)
len += sprintf(buf + len, " C%d=%d(%d)", cpu,
page->pobjects, page->pages);
}
#endif
return len + sprintf(buf + len, "\n");
}
static ssize_t reclaim_account_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_RECLAIM_ACCOUNT));
}
static ssize_t reclaim_account_store(struct kmem_cache *s,
const char *buf, size_t length)
{
s->flags &= ~SLAB_RECLAIM_ACCOUNT;
if (buf[0] == '1')
s->flags |= SLAB_RECLAIM_ACCOUNT;
return length;
}
static ssize_t hwcache_align_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_HWCACHE_ALIGN));
}
static ssize_t cache_dma_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_CACHE_DMA));
}
static ssize_t destroy_by_rcu_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_DESTROY_BY_RCU));
}
static ssize_t reserved_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", s->reserved);
}
static ssize_t slabs_show(struct kmem_cache *s, char *buf)
{
return show_slab_objects(s, buf, SO_ALL);
}
static ssize_t total_objects_show(struct kmem_cache *s, char *buf)
{
return show_slab_objects(s, buf, SO_ALL|SO_TOTAL);
}
static ssize_t sanity_checks_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_CONSISTENCY_CHECKS));
}
static ssize_t sanity_checks_store(struct kmem_cache *s,
const char *buf, size_t length)
{
s->flags &= ~SLAB_CONSISTENCY_CHECKS;
if (buf[0] == '1') {
s->flags &= ~__CMPXCHG_DOUBLE;
s->flags |= SLAB_CONSISTENCY_CHECKS;
}
return length;
}
static ssize_t trace_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_TRACE));
}
static ssize_t trace_store(struct kmem_cache *s, const char *buf,
size_t length)
{
if (s->refcount > 1)
return -EINVAL;
s->flags &= ~SLAB_TRACE;
if (buf[0] == '1') {
s->flags &= ~__CMPXCHG_DOUBLE;
s->flags |= SLAB_TRACE;
}
return length;
}
static ssize_t red_zone_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_RED_ZONE));
}
static ssize_t red_zone_store(struct kmem_cache *s,
const char *buf, size_t length)
{
if (any_slab_objects(s))
return -EBUSY;
s->flags &= ~SLAB_RED_ZONE;
if (buf[0] == '1') {
s->flags |= SLAB_RED_ZONE;
}
calculate_sizes(s, -1);
return length;
}
static ssize_t poison_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_POISON));
}
static ssize_t poison_store(struct kmem_cache *s,
const char *buf, size_t length)
{
if (any_slab_objects(s))
return -EBUSY;
s->flags &= ~SLAB_POISON;
if (buf[0] == '1') {
s->flags |= SLAB_POISON;
}
calculate_sizes(s, -1);
return length;
}
static ssize_t store_user_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_STORE_USER));
}
static ssize_t store_user_store(struct kmem_cache *s,
const char *buf, size_t length)
{
if (any_slab_objects(s))
return -EBUSY;
s->flags &= ~SLAB_STORE_USER;
if (buf[0] == '1') {
s->flags &= ~__CMPXCHG_DOUBLE;
s->flags |= SLAB_STORE_USER;
}
calculate_sizes(s, -1);
return length;
}
static ssize_t validate_show(struct kmem_cache *s, char *buf)
{
return 0;
}
static ssize_t validate_store(struct kmem_cache *s,
const char *buf, size_t length)
{
int ret = -EINVAL;
if (buf[0] == '1') {
ret = validate_slab_cache(s);
if (ret >= 0)
ret = length;
}
return ret;
}
static ssize_t alloc_calls_show(struct kmem_cache *s, char *buf)
{
if (!(s->flags & SLAB_STORE_USER))
return -ENOSYS;
return list_locations(s, buf, TRACK_ALLOC);
}
static ssize_t free_calls_show(struct kmem_cache *s, char *buf)
{
if (!(s->flags & SLAB_STORE_USER))
return -ENOSYS;
return list_locations(s, buf, TRACK_FREE);
}
static ssize_t failslab_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", !!(s->flags & SLAB_FAILSLAB));
}
static ssize_t failslab_store(struct kmem_cache *s, const char *buf,
size_t length)
{
if (s->refcount > 1)
return -EINVAL;
s->flags &= ~SLAB_FAILSLAB;
if (buf[0] == '1')
s->flags |= SLAB_FAILSLAB;
return length;
}
static ssize_t shrink_show(struct kmem_cache *s, char *buf)
{
return 0;
}
static ssize_t shrink_store(struct kmem_cache *s,
const char *buf, size_t length)
{
if (buf[0] == '1')
kmem_cache_shrink(s);
else
return -EINVAL;
return length;
}
static ssize_t remote_node_defrag_ratio_show(struct kmem_cache *s, char *buf)
{
return sprintf(buf, "%d\n", s->remote_node_defrag_ratio / 10);
}
static ssize_t remote_node_defrag_ratio_store(struct kmem_cache *s,
const char *buf, size_t length)
{
unsigned long ratio;
int err;
err = kstrtoul(buf, 10, &ratio);
if (err)
return err;
if (ratio <= 100)
s->remote_node_defrag_ratio = ratio * 10;
return length;
}
static int show_stat(struct kmem_cache *s, char *buf, enum stat_item si)
{
unsigned long sum = 0;
int cpu;
int len;
int *data = kmalloc(nr_cpu_ids * sizeof(int), GFP_KERNEL);
if (!data)
return -ENOMEM;
for_each_online_cpu(cpu) {
unsigned x = per_cpu_ptr(s->cpu_slab, cpu)->stat[si];
data[cpu] = x;
sum += x;
}
len = sprintf(buf, "%lu", sum);
#ifdef CONFIG_SMP
for_each_online_cpu(cpu) {
if (data[cpu] && len < PAGE_SIZE - 20)
len += sprintf(buf + len, " C%d=%u", cpu, data[cpu]);
}
#endif
kfree(data);
return len + sprintf(buf + len, "\n");
}
static void clear_stat(struct kmem_cache *s, enum stat_item si)
{
int cpu;
for_each_online_cpu(cpu)
per_cpu_ptr(s->cpu_slab, cpu)->stat[si] = 0;
}
static ssize_t slab_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct slab_attribute *attribute;
struct kmem_cache *s;
int err;
attribute = to_slab_attr(attr);
s = to_slab(kobj);
if (!attribute->show)
return -EIO;
err = attribute->show(s, buf);
return err;
}
static ssize_t slab_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t len)
{
struct slab_attribute *attribute;
struct kmem_cache *s;
int err;
attribute = to_slab_attr(attr);
s = to_slab(kobj);
if (!attribute->store)
return -EIO;
err = attribute->store(s, buf, len);
#ifdef CONFIG_MEMCG
if (slab_state >= FULL && err >= 0 && is_root_cache(s)) {
struct kmem_cache *c;
mutex_lock(&slab_mutex);
if (s->max_attr_size < len)
s->max_attr_size = len;
for_each_memcg_cache(c, s)
attribute->store(c, buf, len);
mutex_unlock(&slab_mutex);
}
#endif
return err;
}
static void memcg_propagate_slab_attrs(struct kmem_cache *s)
{
#ifdef CONFIG_MEMCG
int i;
char *buffer = NULL;
struct kmem_cache *root_cache;
if (is_root_cache(s))
return;
root_cache = s->memcg_params.root_cache;
if (!root_cache->max_attr_size)
return;
for (i = 0; i < ARRAY_SIZE(slab_attrs); i++) {
char mbuf[64];
char *buf;
struct slab_attribute *attr = to_slab_attr(slab_attrs[i]);
if (!attr || !attr->store || !attr->show)
continue;
if (buffer)
buf = buffer;
else if (root_cache->max_attr_size < ARRAY_SIZE(mbuf))
buf = mbuf;
else {
buffer = (char *) get_zeroed_page(GFP_KERNEL);
if (WARN_ON(!buffer))
continue;
buf = buffer;
}
attr->show(root_cache, buf);
attr->store(s, buf, strlen(buf));
}
if (buffer)
free_page((unsigned long)buffer);
#endif
}
static void kmem_cache_release(struct kobject *k)
{
slab_kmem_cache_release(to_slab(k));
}
static int uevent_filter(struct kset *kset, struct kobject *kobj)
{
struct kobj_type *ktype = get_ktype(kobj);
if (ktype == &slab_ktype)
return 1;
return 0;
}
static inline struct kset *cache_kset(struct kmem_cache *s)
{
#ifdef CONFIG_MEMCG
if (!is_root_cache(s))
return s->memcg_params.root_cache->memcg_kset;
#endif
return slab_kset;
}
static char *create_unique_id(struct kmem_cache *s)
{
char *name = kmalloc(ID_STR_LENGTH, GFP_KERNEL);
char *p = name;
BUG_ON(!name);
*p++ = ':';
if (s->flags & SLAB_CACHE_DMA)
*p++ = 'd';
if (s->flags & SLAB_RECLAIM_ACCOUNT)
*p++ = 'a';
if (s->flags & SLAB_CONSISTENCY_CHECKS)
*p++ = 'F';
if (!(s->flags & SLAB_NOTRACK))
*p++ = 't';
if (s->flags & SLAB_ACCOUNT)
*p++ = 'A';
if (p != name + 1)
*p++ = '-';
p += sprintf(p, "%07d", s->size);
BUG_ON(p > name + ID_STR_LENGTH - 1);
return name;
}
static int sysfs_slab_add(struct kmem_cache *s)
{
int err;
const char *name;
struct kset *kset = cache_kset(s);
int unmergeable = slab_unmergeable(s);
if (!kset) {
kobject_init(&s->kobj, &slab_ktype);
return 0;
}
if (unmergeable) {
sysfs_remove_link(&slab_kset->kobj, s->name);
name = s->name;
} else {
name = create_unique_id(s);
}
s->kobj.kset = kset;
err = kobject_init_and_add(&s->kobj, &slab_ktype, NULL, "%s", name);
if (err)
goto out;
err = sysfs_create_group(&s->kobj, &slab_attr_group);
if (err)
goto out_del_kobj;
#ifdef CONFIG_MEMCG
if (is_root_cache(s) && memcg_sysfs_enabled) {
s->memcg_kset = kset_create_and_add("cgroup", NULL, &s->kobj);
if (!s->memcg_kset) {
err = -ENOMEM;
goto out_del_kobj;
}
}
#endif
kobject_uevent(&s->kobj, KOBJ_ADD);
if (!unmergeable) {
sysfs_slab_alias(s, s->name);
}
out:
if (!unmergeable)
kfree(name);
return err;
out_del_kobj:
kobject_del(&s->kobj);
goto out;
}
static void sysfs_slab_remove(struct kmem_cache *s)
{
if (slab_state < FULL)
return;
if (!s->kobj.state_in_sysfs)
return;
#ifdef CONFIG_MEMCG
kset_unregister(s->memcg_kset);
#endif
kobject_uevent(&s->kobj, KOBJ_REMOVE);
kobject_del(&s->kobj);
}
void sysfs_slab_release(struct kmem_cache *s)
{
if (slab_state >= FULL)
kobject_put(&s->kobj);
}
static int sysfs_slab_alias(struct kmem_cache *s, const char *name)
{
struct saved_alias *al;
if (slab_state == FULL) {
sysfs_remove_link(&slab_kset->kobj, name);
return sysfs_create_link(&slab_kset->kobj, &s->kobj, name);
}
al = kmalloc(sizeof(struct saved_alias), GFP_KERNEL);
if (!al)
return -ENOMEM;
al->s = s;
al->name = name;
al->next = alias_list;
alias_list = al;
return 0;
}
static int __init slab_sysfs_init(void)
{
struct kmem_cache *s;
int err;
mutex_lock(&slab_mutex);
slab_kset = kset_create_and_add("slab", &slab_uevent_ops, kernel_kobj);
if (!slab_kset) {
mutex_unlock(&slab_mutex);
pr_err("Cannot register slab subsystem.\n");
return -ENOSYS;
}
slab_state = FULL;
list_for_each_entry(s, &slab_caches, list) {
err = sysfs_slab_add(s);
if (err)
pr_err("SLUB: Unable to add boot slab %s to sysfs\n",
s->name);
}
while (alias_list) {
struct saved_alias *al = alias_list;
alias_list = alias_list->next;
err = sysfs_slab_alias(al->s, al->name);
if (err)
pr_err("SLUB: Unable to add boot slab alias %s to sysfs\n",
al->name);
kfree(al);
}
mutex_unlock(&slab_mutex);
resiliency_test();
return 0;
}
void get_slabinfo(struct kmem_cache *s, struct slabinfo *sinfo)
{
unsigned long nr_slabs = 0;
unsigned long nr_objs = 0;
unsigned long nr_free = 0;
int node;
struct kmem_cache_node *n;
for_each_kmem_cache_node(s, node, n) {
nr_slabs += node_nr_slabs(n);
nr_objs += node_nr_objs(n);
nr_free += count_partial(n, count_free);
}
sinfo->active_objs = nr_objs - nr_free;
sinfo->num_objs = nr_objs;
sinfo->active_slabs = nr_slabs;
sinfo->num_slabs = nr_slabs;
sinfo->objects_per_slab = oo_objects(s->oo);
sinfo->cache_order = oo_order(s->oo);
}
void slabinfo_show_stats(struct seq_file *m, struct kmem_cache *s)
{
}
ssize_t slabinfo_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
return -EIO;
}
