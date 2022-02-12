void kasan_enable_current(void)
{
current->kasan_depth++;
}
void kasan_disable_current(void)
{
current->kasan_depth--;
}
static void kasan_poison_shadow(const void *address, size_t size, u8 value)
{
void *shadow_start, *shadow_end;
shadow_start = kasan_mem_to_shadow(address);
shadow_end = kasan_mem_to_shadow(address + size);
memset(shadow_start, value, shadow_end - shadow_start);
}
void kasan_unpoison_shadow(const void *address, size_t size)
{
kasan_poison_shadow(address, size, 0);
if (size & KASAN_SHADOW_MASK) {
u8 *shadow = (u8 *)kasan_mem_to_shadow(address + size);
*shadow = size & KASAN_SHADOW_MASK;
}
}
static void __kasan_unpoison_stack(struct task_struct *task, const void *sp)
{
void *base = task_stack_page(task);
size_t size = sp - base;
kasan_unpoison_shadow(base, size);
}
void kasan_unpoison_task_stack(struct task_struct *task)
{
__kasan_unpoison_stack(task, task_stack_page(task) + THREAD_SIZE);
}
asmlinkage void kasan_unpoison_task_stack_below(const void *watermark)
{
void *base = (void *)((unsigned long)watermark & ~(THREAD_SIZE - 1));
kasan_unpoison_shadow(base, watermark - base);
}
void kasan_unpoison_stack_above_sp_to(const void *watermark)
{
const void *sp = __builtin_frame_address(0);
size_t size = watermark - sp;
if (WARN_ON(sp > watermark))
return;
kasan_unpoison_shadow(sp, size);
}
static __always_inline bool memory_is_poisoned_1(unsigned long addr)
{
s8 shadow_value = *(s8 *)kasan_mem_to_shadow((void *)addr);
if (unlikely(shadow_value)) {
s8 last_accessible_byte = addr & KASAN_SHADOW_MASK;
return unlikely(last_accessible_byte >= shadow_value);
}
return false;
}
static __always_inline bool memory_is_poisoned_2_4_8(unsigned long addr,
unsigned long size)
{
u8 *shadow_addr = (u8 *)kasan_mem_to_shadow((void *)addr);
if (unlikely(((addr + size - 1) & KASAN_SHADOW_MASK) < size - 1))
return *shadow_addr || memory_is_poisoned_1(addr + size - 1);
return memory_is_poisoned_1(addr + size - 1);
}
static __always_inline bool memory_is_poisoned_16(unsigned long addr)
{
u16 *shadow_addr = (u16 *)kasan_mem_to_shadow((void *)addr);
if (unlikely(!IS_ALIGNED(addr, KASAN_SHADOW_SCALE_SIZE)))
return *shadow_addr || memory_is_poisoned_1(addr + 15);
return *shadow_addr;
}
static __always_inline unsigned long bytes_is_nonzero(const u8 *start,
size_t size)
{
while (size) {
if (unlikely(*start))
return (unsigned long)start;
start++;
size--;
}
return 0;
}
static __always_inline unsigned long memory_is_nonzero(const void *start,
const void *end)
{
unsigned int words;
unsigned long ret;
unsigned int prefix = (unsigned long)start % 8;
if (end - start <= 16)
return bytes_is_nonzero(start, end - start);
if (prefix) {
prefix = 8 - prefix;
ret = bytes_is_nonzero(start, prefix);
if (unlikely(ret))
return ret;
start += prefix;
}
words = (end - start) / 8;
while (words) {
if (unlikely(*(u64 *)start))
return bytes_is_nonzero(start, 8);
start += 8;
words--;
}
return bytes_is_nonzero(start, (end - start) % 8);
}
static __always_inline bool memory_is_poisoned_n(unsigned long addr,
size_t size)
{
unsigned long ret;
ret = memory_is_nonzero(kasan_mem_to_shadow((void *)addr),
kasan_mem_to_shadow((void *)addr + size - 1) + 1);
if (unlikely(ret)) {
unsigned long last_byte = addr + size - 1;
s8 *last_shadow = (s8 *)kasan_mem_to_shadow((void *)last_byte);
if (unlikely(ret != (unsigned long)last_shadow ||
((long)(last_byte & KASAN_SHADOW_MASK) >= *last_shadow)))
return true;
}
return false;
}
static __always_inline bool memory_is_poisoned(unsigned long addr, size_t size)
{
if (__builtin_constant_p(size)) {
switch (size) {
case 1:
return memory_is_poisoned_1(addr);
case 2:
case 4:
case 8:
return memory_is_poisoned_2_4_8(addr, size);
case 16:
return memory_is_poisoned_16(addr);
default:
BUILD_BUG();
}
}
return memory_is_poisoned_n(addr, size);
}
static __always_inline void check_memory_region_inline(unsigned long addr,
size_t size, bool write,
unsigned long ret_ip)
{
if (unlikely(size == 0))
return;
if (unlikely((void *)addr <
kasan_shadow_to_mem((void *)KASAN_SHADOW_START))) {
kasan_report(addr, size, write, ret_ip);
return;
}
if (likely(!memory_is_poisoned(addr, size)))
return;
kasan_report(addr, size, write, ret_ip);
}
static void check_memory_region(unsigned long addr,
size_t size, bool write,
unsigned long ret_ip)
{
check_memory_region_inline(addr, size, write, ret_ip);
}
void kasan_check_read(const volatile void *p, unsigned int size)
{
check_memory_region((unsigned long)p, size, false, _RET_IP_);
}
void kasan_check_write(const volatile void *p, unsigned int size)
{
check_memory_region((unsigned long)p, size, true, _RET_IP_);
}
void *memset(void *addr, int c, size_t len)
{
check_memory_region((unsigned long)addr, len, true, _RET_IP_);
return __memset(addr, c, len);
}
void *memmove(void *dest, const void *src, size_t len)
{
check_memory_region((unsigned long)src, len, false, _RET_IP_);
check_memory_region((unsigned long)dest, len, true, _RET_IP_);
return __memmove(dest, src, len);
}
void *memcpy(void *dest, const void *src, size_t len)
{
check_memory_region((unsigned long)src, len, false, _RET_IP_);
check_memory_region((unsigned long)dest, len, true, _RET_IP_);
return __memcpy(dest, src, len);
}
void kasan_alloc_pages(struct page *page, unsigned int order)
{
if (likely(!PageHighMem(page)))
kasan_unpoison_shadow(page_address(page), PAGE_SIZE << order);
}
void kasan_free_pages(struct page *page, unsigned int order)
{
if (likely(!PageHighMem(page)))
kasan_poison_shadow(page_address(page),
PAGE_SIZE << order,
KASAN_FREE_PAGE);
}
static size_t optimal_redzone(size_t object_size)
{
int rz =
object_size <= 64 - 16 ? 16 :
object_size <= 128 - 32 ? 32 :
object_size <= 512 - 64 ? 64 :
object_size <= 4096 - 128 ? 128 :
object_size <= (1 << 14) - 256 ? 256 :
object_size <= (1 << 15) - 512 ? 512 :
object_size <= (1 << 16) - 1024 ? 1024 : 2048;
return rz;
}
void kasan_cache_create(struct kmem_cache *cache, size_t *size,
unsigned long *flags)
{
int redzone_adjust;
int orig_size = *size;
cache->kasan_info.alloc_meta_offset = *size;
*size += sizeof(struct kasan_alloc_meta);
if (cache->flags & SLAB_TYPESAFE_BY_RCU || cache->ctor ||
cache->object_size < sizeof(struct kasan_free_meta)) {
cache->kasan_info.free_meta_offset = *size;
*size += sizeof(struct kasan_free_meta);
}
redzone_adjust = optimal_redzone(cache->object_size) -
(*size - cache->object_size);
if (redzone_adjust > 0)
*size += redzone_adjust;
*size = min(KMALLOC_MAX_SIZE, max(*size, cache->object_size +
optimal_redzone(cache->object_size)));
if (*size <= cache->kasan_info.alloc_meta_offset ||
*size <= cache->kasan_info.free_meta_offset) {
cache->kasan_info.alloc_meta_offset = 0;
cache->kasan_info.free_meta_offset = 0;
*size = orig_size;
return;
}
*flags |= SLAB_KASAN;
}
void kasan_cache_shrink(struct kmem_cache *cache)
{
quarantine_remove_cache(cache);
}
void kasan_cache_shutdown(struct kmem_cache *cache)
{
quarantine_remove_cache(cache);
}
size_t kasan_metadata_size(struct kmem_cache *cache)
{
return (cache->kasan_info.alloc_meta_offset ?
sizeof(struct kasan_alloc_meta) : 0) +
(cache->kasan_info.free_meta_offset ?
sizeof(struct kasan_free_meta) : 0);
}
void kasan_poison_slab(struct page *page)
{
kasan_poison_shadow(page_address(page),
PAGE_SIZE << compound_order(page),
KASAN_KMALLOC_REDZONE);
}
void kasan_unpoison_object_data(struct kmem_cache *cache, void *object)
{
kasan_unpoison_shadow(object, cache->object_size);
}
void kasan_poison_object_data(struct kmem_cache *cache, void *object)
{
kasan_poison_shadow(object,
round_up(cache->object_size, KASAN_SHADOW_SCALE_SIZE),
KASAN_KMALLOC_REDZONE);
}
static inline int in_irqentry_text(unsigned long ptr)
{
return (ptr >= (unsigned long)&__irqentry_text_start &&
ptr < (unsigned long)&__irqentry_text_end) ||
(ptr >= (unsigned long)&__softirqentry_text_start &&
ptr < (unsigned long)&__softirqentry_text_end);
}
static inline void filter_irq_stacks(struct stack_trace *trace)
{
int i;
if (!trace->nr_entries)
return;
for (i = 0; i < trace->nr_entries; i++)
if (in_irqentry_text(trace->entries[i])) {
trace->nr_entries = i + 1;
break;
}
}
static inline depot_stack_handle_t save_stack(gfp_t flags)
{
unsigned long entries[KASAN_STACK_DEPTH];
struct stack_trace trace = {
.nr_entries = 0,
.entries = entries,
.max_entries = KASAN_STACK_DEPTH,
.skip = 0
};
save_stack_trace(&trace);
filter_irq_stacks(&trace);
if (trace.nr_entries != 0 &&
trace.entries[trace.nr_entries-1] == ULONG_MAX)
trace.nr_entries--;
return depot_save_stack(&trace, flags);
}
static inline void set_track(struct kasan_track *track, gfp_t flags)
{
track->pid = current->pid;
track->stack = save_stack(flags);
}
struct kasan_alloc_meta *get_alloc_info(struct kmem_cache *cache,
const void *object)
{
BUILD_BUG_ON(sizeof(struct kasan_alloc_meta) > 32);
return (void *)object + cache->kasan_info.alloc_meta_offset;
}
struct kasan_free_meta *get_free_info(struct kmem_cache *cache,
const void *object)
{
BUILD_BUG_ON(sizeof(struct kasan_free_meta) > 32);
return (void *)object + cache->kasan_info.free_meta_offset;
}
void kasan_init_slab_obj(struct kmem_cache *cache, const void *object)
{
struct kasan_alloc_meta *alloc_info;
if (!(cache->flags & SLAB_KASAN))
return;
alloc_info = get_alloc_info(cache, object);
__memset(alloc_info, 0, sizeof(*alloc_info));
}
void kasan_slab_alloc(struct kmem_cache *cache, void *object, gfp_t flags)
{
kasan_kmalloc(cache, object, cache->object_size, flags);
}
static void kasan_poison_slab_free(struct kmem_cache *cache, void *object)
{
unsigned long size = cache->object_size;
unsigned long rounded_up_size = round_up(size, KASAN_SHADOW_SCALE_SIZE);
if (unlikely(cache->flags & SLAB_TYPESAFE_BY_RCU))
return;
kasan_poison_shadow(object, rounded_up_size, KASAN_KMALLOC_FREE);
}
bool kasan_slab_free(struct kmem_cache *cache, void *object)
{
s8 shadow_byte;
if (unlikely(cache->flags & SLAB_TYPESAFE_BY_RCU))
return false;
shadow_byte = READ_ONCE(*(s8 *)kasan_mem_to_shadow(object));
if (shadow_byte < 0 || shadow_byte >= KASAN_SHADOW_SCALE_SIZE) {
kasan_report_double_free(cache, object,
__builtin_return_address(1));
return true;
}
kasan_poison_slab_free(cache, object);
if (unlikely(!(cache->flags & SLAB_KASAN)))
return false;
set_track(&get_alloc_info(cache, object)->free_track, GFP_NOWAIT);
quarantine_put(get_free_info(cache, object), cache);
return true;
}
void kasan_kmalloc(struct kmem_cache *cache, const void *object, size_t size,
gfp_t flags)
{
unsigned long redzone_start;
unsigned long redzone_end;
if (gfpflags_allow_blocking(flags))
quarantine_reduce();
if (unlikely(object == NULL))
return;
redzone_start = round_up((unsigned long)(object + size),
KASAN_SHADOW_SCALE_SIZE);
redzone_end = round_up((unsigned long)object + cache->object_size,
KASAN_SHADOW_SCALE_SIZE);
kasan_unpoison_shadow(object, size);
kasan_poison_shadow((void *)redzone_start, redzone_end - redzone_start,
KASAN_KMALLOC_REDZONE);
if (cache->flags & SLAB_KASAN)
set_track(&get_alloc_info(cache, object)->alloc_track, flags);
}
void kasan_kmalloc_large(const void *ptr, size_t size, gfp_t flags)
{
struct page *page;
unsigned long redzone_start;
unsigned long redzone_end;
if (gfpflags_allow_blocking(flags))
quarantine_reduce();
if (unlikely(ptr == NULL))
return;
page = virt_to_page(ptr);
redzone_start = round_up((unsigned long)(ptr + size),
KASAN_SHADOW_SCALE_SIZE);
redzone_end = (unsigned long)ptr + (PAGE_SIZE << compound_order(page));
kasan_unpoison_shadow(ptr, size);
kasan_poison_shadow((void *)redzone_start, redzone_end - redzone_start,
KASAN_PAGE_REDZONE);
}
void kasan_krealloc(const void *object, size_t size, gfp_t flags)
{
struct page *page;
if (unlikely(object == ZERO_SIZE_PTR))
return;
page = virt_to_head_page(object);
if (unlikely(!PageSlab(page)))
kasan_kmalloc_large(object, size, flags);
else
kasan_kmalloc(page->slab_cache, object, size, flags);
}
void kasan_poison_kfree(void *ptr)
{
struct page *page;
page = virt_to_head_page(ptr);
if (unlikely(!PageSlab(page)))
kasan_poison_shadow(ptr, PAGE_SIZE << compound_order(page),
KASAN_FREE_PAGE);
else
kasan_poison_slab_free(page->slab_cache, ptr);
}
void kasan_kfree_large(const void *ptr)
{
struct page *page = virt_to_page(ptr);
kasan_poison_shadow(ptr, PAGE_SIZE << compound_order(page),
KASAN_FREE_PAGE);
}
int kasan_module_alloc(void *addr, size_t size)
{
void *ret;
size_t shadow_size;
unsigned long shadow_start;
shadow_start = (unsigned long)kasan_mem_to_shadow(addr);
shadow_size = round_up(size >> KASAN_SHADOW_SCALE_SHIFT,
PAGE_SIZE);
if (WARN_ON(!PAGE_ALIGNED(shadow_start)))
return -EINVAL;
ret = __vmalloc_node_range(shadow_size, 1, shadow_start,
shadow_start + shadow_size,
GFP_KERNEL | __GFP_ZERO,
PAGE_KERNEL, VM_NO_GUARD, NUMA_NO_NODE,
__builtin_return_address(0));
if (ret) {
find_vm_area(addr)->flags |= VM_KASAN;
kmemleak_ignore(ret);
return 0;
}
return -ENOMEM;
}
void kasan_free_shadow(const struct vm_struct *vm)
{
if (vm->flags & VM_KASAN)
vfree(kasan_mem_to_shadow(vm->addr));
}
static void register_global(struct kasan_global *global)
{
size_t aligned_size = round_up(global->size, KASAN_SHADOW_SCALE_SIZE);
kasan_unpoison_shadow(global->beg, global->size);
kasan_poison_shadow(global->beg + aligned_size,
global->size_with_redzone - aligned_size,
KASAN_GLOBAL_REDZONE);
}
void __asan_register_globals(struct kasan_global *globals, size_t size)
{
int i;
for (i = 0; i < size; i++)
register_global(&globals[i]);
}
void __asan_unregister_globals(struct kasan_global *globals, size_t size)
{
}
void __asan_loadN(unsigned long addr, size_t size)
{
check_memory_region(addr, size, false, _RET_IP_);
}
void __asan_storeN(unsigned long addr, size_t size)
{
check_memory_region(addr, size, true, _RET_IP_);
}
void __asan_handle_no_return(void) {}
void __asan_poison_stack_memory(const void *addr, size_t size)
{
kasan_poison_shadow(addr, round_up(size, KASAN_SHADOW_SCALE_SIZE),
KASAN_USE_AFTER_SCOPE);
}
void __asan_unpoison_stack_memory(const void *addr, size_t size)
{
kasan_unpoison_shadow(addr, size);
}
static int __meminit kasan_mem_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct memory_notify *mem_data = data;
unsigned long nr_shadow_pages, start_kaddr, shadow_start;
unsigned long shadow_end, shadow_size;
nr_shadow_pages = mem_data->nr_pages >> KASAN_SHADOW_SCALE_SHIFT;
start_kaddr = (unsigned long)pfn_to_kaddr(mem_data->start_pfn);
shadow_start = (unsigned long)kasan_mem_to_shadow((void *)start_kaddr);
shadow_size = nr_shadow_pages << PAGE_SHIFT;
shadow_end = shadow_start + shadow_size;
if (WARN_ON(mem_data->nr_pages % KASAN_SHADOW_SCALE_SIZE) ||
WARN_ON(start_kaddr % (KASAN_SHADOW_SCALE_SIZE << PAGE_SHIFT)))
return NOTIFY_BAD;
switch (action) {
case MEM_GOING_ONLINE: {
void *ret;
ret = __vmalloc_node_range(shadow_size, PAGE_SIZE, shadow_start,
shadow_end, GFP_KERNEL,
PAGE_KERNEL, VM_NO_GUARD,
pfn_to_nid(mem_data->start_pfn),
__builtin_return_address(0));
if (!ret)
return NOTIFY_BAD;
kmemleak_ignore(ret);
return NOTIFY_OK;
}
case MEM_OFFLINE:
vfree((void *)shadow_start);
}
return NOTIFY_OK;
}
static int __init kasan_memhotplug_init(void)
{
hotplug_memory_notifier(kasan_mem_notifier, 0);
return 0;
}
