static bool init_stack_slab(void **prealloc)
{
if (!*prealloc)
return false;
if (smp_load_acquire(&next_slab_inited))
return true;
if (stack_slabs[depot_index] == NULL) {
stack_slabs[depot_index] = *prealloc;
} else {
stack_slabs[depot_index + 1] = *prealloc;
smp_store_release(&next_slab_inited, 1);
}
*prealloc = NULL;
return true;
}
static struct stack_record *depot_alloc_stack(unsigned long *entries, int size,
u32 hash, void **prealloc, gfp_t alloc_flags)
{
int required_size = offsetof(struct stack_record, entries) +
sizeof(unsigned long) * size;
struct stack_record *stack;
required_size = ALIGN(required_size, 1 << STACK_ALLOC_ALIGN);
if (unlikely(depot_offset + required_size > STACK_ALLOC_SIZE)) {
if (unlikely(depot_index + 1 >= STACK_ALLOC_MAX_SLABS)) {
WARN_ONCE(1, "Stack depot reached limit capacity");
return NULL;
}
depot_index++;
depot_offset = 0;
if (depot_index + 1 < STACK_ALLOC_MAX_SLABS)
smp_store_release(&next_slab_inited, 0);
}
init_stack_slab(prealloc);
if (stack_slabs[depot_index] == NULL)
return NULL;
stack = stack_slabs[depot_index] + depot_offset;
stack->hash = hash;
stack->size = size;
stack->handle.slabindex = depot_index;
stack->handle.offset = depot_offset >> STACK_ALLOC_ALIGN;
stack->handle.valid = 1;
memcpy(stack->entries, entries, size * sizeof(unsigned long));
depot_offset += required_size;
return stack;
}
static inline u32 hash_stack(unsigned long *entries, unsigned int size)
{
return jhash2((u32 *)entries,
size * sizeof(unsigned long) / sizeof(u32),
STACK_HASH_SEED);
}
static inline struct stack_record *find_stack(struct stack_record *bucket,
unsigned long *entries, int size,
u32 hash)
{
struct stack_record *found;
for (found = bucket; found; found = found->next) {
if (found->hash == hash &&
found->size == size &&
!memcmp(entries, found->entries,
size * sizeof(unsigned long))) {
return found;
}
}
return NULL;
}
void depot_fetch_stack(depot_stack_handle_t handle, struct stack_trace *trace)
{
union handle_parts parts = { .handle = handle };
void *slab = stack_slabs[parts.slabindex];
size_t offset = parts.offset << STACK_ALLOC_ALIGN;
struct stack_record *stack = slab + offset;
trace->nr_entries = trace->max_entries = stack->size;
trace->entries = stack->entries;
trace->skip = 0;
}
depot_stack_handle_t depot_save_stack(struct stack_trace *trace,
gfp_t alloc_flags)
{
u32 hash;
depot_stack_handle_t retval = 0;
struct stack_record *found = NULL, **bucket;
unsigned long flags;
struct page *page = NULL;
void *prealloc = NULL;
if (unlikely(trace->nr_entries == 0))
goto fast_exit;
hash = hash_stack(trace->entries, trace->nr_entries);
bucket = &stack_table[hash & STACK_HASH_MASK];
found = find_stack(smp_load_acquire(bucket), trace->entries,
trace->nr_entries, hash);
if (found)
goto exit;
if (unlikely(!smp_load_acquire(&next_slab_inited))) {
alloc_flags &= ~GFP_ZONEMASK;
alloc_flags &= (GFP_ATOMIC | GFP_KERNEL);
page = alloc_pages(alloc_flags, STACK_ALLOC_ORDER);
if (page)
prealloc = page_address(page);
}
spin_lock_irqsave(&depot_lock, flags);
found = find_stack(*bucket, trace->entries, trace->nr_entries, hash);
if (!found) {
struct stack_record *new =
depot_alloc_stack(trace->entries, trace->nr_entries,
hash, &prealloc, alloc_flags);
if (new) {
new->next = *bucket;
smp_store_release(bucket, new);
found = new;
}
} else if (prealloc) {
WARN_ON(!init_stack_slab(&prealloc));
}
spin_unlock_irqrestore(&depot_lock, flags);
exit:
if (prealloc) {
free_pages((unsigned long)prealloc, STACK_ALLOC_ORDER);
}
if (found)
retval = found->handle.handle;
fast_exit:
return retval;
}
