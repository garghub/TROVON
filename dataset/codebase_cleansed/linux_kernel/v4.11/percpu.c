static void pcpu_schedule_balance_work(void)
{
if (pcpu_async_enabled)
schedule_work(&pcpu_balance_work);
}
static bool pcpu_addr_in_first_chunk(void *addr)
{
void *first_start = pcpu_first_chunk->base_addr;
return addr >= first_start && addr < first_start + pcpu_unit_size;
}
static bool pcpu_addr_in_reserved_chunk(void *addr)
{
void *first_start = pcpu_first_chunk->base_addr;
return addr >= first_start &&
addr < first_start + pcpu_reserved_chunk_limit;
}
static int __pcpu_size_to_slot(int size)
{
int highbit = fls(size);
return max(highbit - PCPU_SLOT_BASE_SHIFT + 2, 1);
}
static int pcpu_size_to_slot(int size)
{
if (size == pcpu_unit_size)
return pcpu_nr_slots - 1;
return __pcpu_size_to_slot(size);
}
static int pcpu_chunk_slot(const struct pcpu_chunk *chunk)
{
if (chunk->free_size < sizeof(int) || chunk->contig_hint < sizeof(int))
return 0;
return pcpu_size_to_slot(chunk->free_size);
}
static void pcpu_set_page_chunk(struct page *page, struct pcpu_chunk *pcpu)
{
page->index = (unsigned long)pcpu;
}
static struct pcpu_chunk *pcpu_get_page_chunk(struct page *page)
{
return (struct pcpu_chunk *)page->index;
}
static int __maybe_unused pcpu_page_idx(unsigned int cpu, int page_idx)
{
return pcpu_unit_map[cpu] * pcpu_unit_pages + page_idx;
}
static unsigned long pcpu_chunk_addr(struct pcpu_chunk *chunk,
unsigned int cpu, int page_idx)
{
return (unsigned long)chunk->base_addr + pcpu_unit_offsets[cpu] +
(page_idx << PAGE_SHIFT);
}
static void __maybe_unused pcpu_next_unpop(struct pcpu_chunk *chunk,
int *rs, int *re, int end)
{
*rs = find_next_zero_bit(chunk->populated, end, *rs);
*re = find_next_bit(chunk->populated, end, *rs + 1);
}
static void __maybe_unused pcpu_next_pop(struct pcpu_chunk *chunk,
int *rs, int *re, int end)
{
*rs = find_next_bit(chunk->populated, end, *rs);
*re = find_next_zero_bit(chunk->populated, end, *rs + 1);
}
static void *pcpu_mem_zalloc(size_t size)
{
if (WARN_ON_ONCE(!slab_is_available()))
return NULL;
if (size <= PAGE_SIZE)
return kzalloc(size, GFP_KERNEL);
else
return vzalloc(size);
}
static void pcpu_mem_free(void *ptr)
{
kvfree(ptr);
}
static int pcpu_count_occupied_pages(struct pcpu_chunk *chunk, int i)
{
int off = chunk->map[i] & ~1;
int end = chunk->map[i + 1] & ~1;
if (!PAGE_ALIGNED(off) && i > 0) {
int prev = chunk->map[i - 1];
if (!(prev & 1) && prev <= round_down(off, PAGE_SIZE))
off = round_down(off, PAGE_SIZE);
}
if (!PAGE_ALIGNED(end) && i + 1 < chunk->map_used) {
int next = chunk->map[i + 1];
int nend = chunk->map[i + 2] & ~1;
if (!(next & 1) && nend >= round_up(end, PAGE_SIZE))
end = round_up(end, PAGE_SIZE);
}
return max_t(int, PFN_DOWN(end) - PFN_UP(off), 0);
}
static void pcpu_chunk_relocate(struct pcpu_chunk *chunk, int oslot)
{
int nslot = pcpu_chunk_slot(chunk);
if (chunk != pcpu_reserved_chunk && oslot != nslot) {
if (oslot < nslot)
list_move(&chunk->list, &pcpu_slot[nslot]);
else
list_move_tail(&chunk->list, &pcpu_slot[nslot]);
}
}
static int pcpu_need_to_extend(struct pcpu_chunk *chunk, bool is_atomic)
{
int margin, new_alloc;
lockdep_assert_held(&pcpu_lock);
if (is_atomic) {
margin = 3;
if (chunk->map_alloc <
chunk->map_used + PCPU_ATOMIC_MAP_MARGIN_LOW) {
if (list_empty(&chunk->map_extend_list)) {
list_add_tail(&chunk->map_extend_list,
&pcpu_map_extend_chunks);
pcpu_schedule_balance_work();
}
}
} else {
margin = PCPU_ATOMIC_MAP_MARGIN_HIGH;
}
if (chunk->map_alloc >= chunk->map_used + margin)
return 0;
new_alloc = PCPU_DFL_MAP_ALLOC;
while (new_alloc < chunk->map_used + margin)
new_alloc *= 2;
return new_alloc;
}
static int pcpu_extend_area_map(struct pcpu_chunk *chunk, int new_alloc)
{
int *old = NULL, *new = NULL;
size_t old_size = 0, new_size = new_alloc * sizeof(new[0]);
unsigned long flags;
lockdep_assert_held(&pcpu_alloc_mutex);
new = pcpu_mem_zalloc(new_size);
if (!new)
return -ENOMEM;
spin_lock_irqsave(&pcpu_lock, flags);
if (new_alloc <= chunk->map_alloc)
goto out_unlock;
old_size = chunk->map_alloc * sizeof(chunk->map[0]);
old = chunk->map;
memcpy(new, old, old_size);
chunk->map_alloc = new_alloc;
chunk->map = new;
new = NULL;
out_unlock:
spin_unlock_irqrestore(&pcpu_lock, flags);
pcpu_mem_free(old);
pcpu_mem_free(new);
return 0;
}
static int pcpu_fit_in_area(struct pcpu_chunk *chunk, int off, int this_size,
int size, int align, bool pop_only)
{
int cand_off = off;
while (true) {
int head = ALIGN(cand_off, align) - off;
int page_start, page_end, rs, re;
if (this_size < head + size)
return -1;
if (!pop_only)
return head;
page_start = PFN_DOWN(head + off);
page_end = PFN_UP(head + off + size);
rs = page_start;
pcpu_next_unpop(chunk, &rs, &re, PFN_UP(off + this_size));
if (rs >= page_end)
return head;
cand_off = re * PAGE_SIZE;
}
}
static int pcpu_alloc_area(struct pcpu_chunk *chunk, int size, int align,
bool pop_only, int *occ_pages_p)
{
int oslot = pcpu_chunk_slot(chunk);
int max_contig = 0;
int i, off;
bool seen_free = false;
int *p;
for (i = chunk->first_free, p = chunk->map + i; i < chunk->map_used; i++, p++) {
int head, tail;
int this_size;
off = *p;
if (off & 1)
continue;
this_size = (p[1] & ~1) - off;
head = pcpu_fit_in_area(chunk, off, this_size, size, align,
pop_only);
if (head < 0) {
if (!seen_free) {
chunk->first_free = i;
seen_free = true;
}
max_contig = max(this_size, max_contig);
continue;
}
if (head && (head < sizeof(int) || !(p[-1] & 1))) {
*p = off += head;
if (p[-1] & 1)
chunk->free_size -= head;
else
max_contig = max(*p - p[-1], max_contig);
this_size -= head;
head = 0;
}
tail = this_size - head - size;
if (tail < sizeof(int)) {
tail = 0;
size = this_size - head;
}
if (head || tail) {
int nr_extra = !!head + !!tail;
memmove(p + nr_extra + 1, p + 1,
sizeof(chunk->map[0]) * (chunk->map_used - i));
chunk->map_used += nr_extra;
if (head) {
if (!seen_free) {
chunk->first_free = i;
seen_free = true;
}
*++p = off += head;
++i;
max_contig = max(head, max_contig);
}
if (tail) {
p[1] = off + size;
max_contig = max(tail, max_contig);
}
}
if (!seen_free)
chunk->first_free = i + 1;
if (i + 1 == chunk->map_used)
chunk->contig_hint = max_contig;
else
chunk->contig_hint = max(chunk->contig_hint,
max_contig);
chunk->free_size -= size;
*p |= 1;
*occ_pages_p = pcpu_count_occupied_pages(chunk, i);
pcpu_chunk_relocate(chunk, oslot);
return off;
}
chunk->contig_hint = max_contig;
pcpu_chunk_relocate(chunk, oslot);
return -1;
}
static void pcpu_free_area(struct pcpu_chunk *chunk, int freeme,
int *occ_pages_p)
{
int oslot = pcpu_chunk_slot(chunk);
int off = 0;
unsigned i, j;
int to_free = 0;
int *p;
freeme |= 1;
i = 0;
j = chunk->map_used;
while (i != j) {
unsigned k = (i + j) / 2;
off = chunk->map[k];
if (off < freeme)
i = k + 1;
else if (off > freeme)
j = k;
else
i = j = k;
}
BUG_ON(off != freeme);
if (i < chunk->first_free)
chunk->first_free = i;
p = chunk->map + i;
*p = off &= ~1;
chunk->free_size += (p[1] & ~1) - off;
*occ_pages_p = pcpu_count_occupied_pages(chunk, i);
if (!(p[1] & 1))
to_free++;
if (i > 0 && !(p[-1] & 1)) {
to_free++;
i--;
p--;
}
if (to_free) {
chunk->map_used -= to_free;
memmove(p + 1, p + 1 + to_free,
(chunk->map_used - i) * sizeof(chunk->map[0]));
}
chunk->contig_hint = max(chunk->map[i + 1] - chunk->map[i] - 1, chunk->contig_hint);
pcpu_chunk_relocate(chunk, oslot);
}
static struct pcpu_chunk *pcpu_alloc_chunk(void)
{
struct pcpu_chunk *chunk;
chunk = pcpu_mem_zalloc(pcpu_chunk_struct_size);
if (!chunk)
return NULL;
chunk->map = pcpu_mem_zalloc(PCPU_DFL_MAP_ALLOC *
sizeof(chunk->map[0]));
if (!chunk->map) {
pcpu_mem_free(chunk);
return NULL;
}
chunk->map_alloc = PCPU_DFL_MAP_ALLOC;
chunk->map[0] = 0;
chunk->map[1] = pcpu_unit_size | 1;
chunk->map_used = 1;
INIT_LIST_HEAD(&chunk->list);
INIT_LIST_HEAD(&chunk->map_extend_list);
chunk->free_size = pcpu_unit_size;
chunk->contig_hint = pcpu_unit_size;
return chunk;
}
static void pcpu_free_chunk(struct pcpu_chunk *chunk)
{
if (!chunk)
return;
pcpu_mem_free(chunk->map);
pcpu_mem_free(chunk);
}
static void pcpu_chunk_populated(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
int nr = page_end - page_start;
lockdep_assert_held(&pcpu_lock);
bitmap_set(chunk->populated, page_start, nr);
chunk->nr_populated += nr;
pcpu_nr_empty_pop_pages += nr;
}
static void pcpu_chunk_depopulated(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
int nr = page_end - page_start;
lockdep_assert_held(&pcpu_lock);
bitmap_clear(chunk->populated, page_start, nr);
chunk->nr_populated -= nr;
pcpu_nr_empty_pop_pages -= nr;
}
static struct pcpu_chunk *pcpu_chunk_addr_search(void *addr)
{
if (pcpu_addr_in_first_chunk(addr)) {
if (pcpu_addr_in_reserved_chunk(addr))
return pcpu_reserved_chunk;
return pcpu_first_chunk;
}
addr += pcpu_unit_offsets[raw_smp_processor_id()];
return pcpu_get_page_chunk(pcpu_addr_to_page(addr));
}
static void __percpu *pcpu_alloc(size_t size, size_t align, bool reserved,
gfp_t gfp)
{
static int warn_limit = 10;
struct pcpu_chunk *chunk;
const char *err;
bool is_atomic = (gfp & GFP_KERNEL) != GFP_KERNEL;
int occ_pages = 0;
int slot, off, new_alloc, cpu, ret;
unsigned long flags;
void __percpu *ptr;
if (unlikely(align < 2))
align = 2;
size = ALIGN(size, 2);
if (unlikely(!size || size > PCPU_MIN_UNIT_SIZE || align > PAGE_SIZE ||
!is_power_of_2(align))) {
WARN(true, "illegal size (%zu) or align (%zu) for percpu allocation\n",
size, align);
return NULL;
}
if (!is_atomic)
mutex_lock(&pcpu_alloc_mutex);
spin_lock_irqsave(&pcpu_lock, flags);
if (reserved && pcpu_reserved_chunk) {
chunk = pcpu_reserved_chunk;
if (size > chunk->contig_hint) {
err = "alloc from reserved chunk failed";
goto fail_unlock;
}
while ((new_alloc = pcpu_need_to_extend(chunk, is_atomic))) {
spin_unlock_irqrestore(&pcpu_lock, flags);
if (is_atomic ||
pcpu_extend_area_map(chunk, new_alloc) < 0) {
err = "failed to extend area map of reserved chunk";
goto fail;
}
spin_lock_irqsave(&pcpu_lock, flags);
}
off = pcpu_alloc_area(chunk, size, align, is_atomic,
&occ_pages);
if (off >= 0)
goto area_found;
err = "alloc from reserved chunk failed";
goto fail_unlock;
}
restart:
for (slot = pcpu_size_to_slot(size); slot < pcpu_nr_slots; slot++) {
list_for_each_entry(chunk, &pcpu_slot[slot], list) {
if (size > chunk->contig_hint)
continue;
new_alloc = pcpu_need_to_extend(chunk, is_atomic);
if (new_alloc) {
if (is_atomic)
continue;
spin_unlock_irqrestore(&pcpu_lock, flags);
if (pcpu_extend_area_map(chunk,
new_alloc) < 0) {
err = "failed to extend area map";
goto fail;
}
spin_lock_irqsave(&pcpu_lock, flags);
goto restart;
}
off = pcpu_alloc_area(chunk, size, align, is_atomic,
&occ_pages);
if (off >= 0)
goto area_found;
}
}
spin_unlock_irqrestore(&pcpu_lock, flags);
if (is_atomic)
goto fail;
if (list_empty(&pcpu_slot[pcpu_nr_slots - 1])) {
chunk = pcpu_create_chunk();
if (!chunk) {
err = "failed to allocate new chunk";
goto fail;
}
spin_lock_irqsave(&pcpu_lock, flags);
pcpu_chunk_relocate(chunk, -1);
} else {
spin_lock_irqsave(&pcpu_lock, flags);
}
goto restart;
area_found:
spin_unlock_irqrestore(&pcpu_lock, flags);
if (!is_atomic) {
int page_start, page_end, rs, re;
page_start = PFN_DOWN(off);
page_end = PFN_UP(off + size);
pcpu_for_each_unpop_region(chunk, rs, re, page_start, page_end) {
WARN_ON(chunk->immutable);
ret = pcpu_populate_chunk(chunk, rs, re);
spin_lock_irqsave(&pcpu_lock, flags);
if (ret) {
pcpu_free_area(chunk, off, &occ_pages);
err = "failed to populate";
goto fail_unlock;
}
pcpu_chunk_populated(chunk, rs, re);
spin_unlock_irqrestore(&pcpu_lock, flags);
}
mutex_unlock(&pcpu_alloc_mutex);
}
if (chunk != pcpu_reserved_chunk) {
spin_lock_irqsave(&pcpu_lock, flags);
pcpu_nr_empty_pop_pages -= occ_pages;
spin_unlock_irqrestore(&pcpu_lock, flags);
}
if (pcpu_nr_empty_pop_pages < PCPU_EMPTY_POP_PAGES_LOW)
pcpu_schedule_balance_work();
for_each_possible_cpu(cpu)
memset((void *)pcpu_chunk_addr(chunk, cpu, 0) + off, 0, size);
ptr = __addr_to_pcpu_ptr(chunk->base_addr + off);
kmemleak_alloc_percpu(ptr, size, gfp);
return ptr;
fail_unlock:
spin_unlock_irqrestore(&pcpu_lock, flags);
fail:
if (!is_atomic && warn_limit) {
pr_warn("allocation failed, size=%zu align=%zu atomic=%d, %s\n",
size, align, is_atomic, err);
dump_stack();
if (!--warn_limit)
pr_info("limit reached, disable warning\n");
}
if (is_atomic) {
pcpu_atomic_alloc_failed = true;
pcpu_schedule_balance_work();
} else {
mutex_unlock(&pcpu_alloc_mutex);
}
return NULL;
}
void __percpu *__alloc_percpu_gfp(size_t size, size_t align, gfp_t gfp)
{
return pcpu_alloc(size, align, false, gfp);
}
void __percpu *__alloc_percpu(size_t size, size_t align)
{
return pcpu_alloc(size, align, false, GFP_KERNEL);
}
void __percpu *__alloc_reserved_percpu(size_t size, size_t align)
{
return pcpu_alloc(size, align, true, GFP_KERNEL);
}
static void pcpu_balance_workfn(struct work_struct *work)
{
LIST_HEAD(to_free);
struct list_head *free_head = &pcpu_slot[pcpu_nr_slots - 1];
struct pcpu_chunk *chunk, *next;
int slot, nr_to_pop, ret;
mutex_lock(&pcpu_alloc_mutex);
spin_lock_irq(&pcpu_lock);
list_for_each_entry_safe(chunk, next, free_head, list) {
WARN_ON(chunk->immutable);
if (chunk == list_first_entry(free_head, struct pcpu_chunk, list))
continue;
list_del_init(&chunk->map_extend_list);
list_move(&chunk->list, &to_free);
}
spin_unlock_irq(&pcpu_lock);
list_for_each_entry_safe(chunk, next, &to_free, list) {
int rs, re;
pcpu_for_each_pop_region(chunk, rs, re, 0, pcpu_unit_pages) {
pcpu_depopulate_chunk(chunk, rs, re);
spin_lock_irq(&pcpu_lock);
pcpu_chunk_depopulated(chunk, rs, re);
spin_unlock_irq(&pcpu_lock);
}
pcpu_destroy_chunk(chunk);
}
do {
int new_alloc = 0;
spin_lock_irq(&pcpu_lock);
chunk = list_first_entry_or_null(&pcpu_map_extend_chunks,
struct pcpu_chunk, map_extend_list);
if (chunk) {
list_del_init(&chunk->map_extend_list);
new_alloc = pcpu_need_to_extend(chunk, false);
}
spin_unlock_irq(&pcpu_lock);
if (new_alloc)
pcpu_extend_area_map(chunk, new_alloc);
} while (chunk);
retry_pop:
if (pcpu_atomic_alloc_failed) {
nr_to_pop = PCPU_EMPTY_POP_PAGES_HIGH;
pcpu_atomic_alloc_failed = false;
} else {
nr_to_pop = clamp(PCPU_EMPTY_POP_PAGES_HIGH -
pcpu_nr_empty_pop_pages,
0, PCPU_EMPTY_POP_PAGES_HIGH);
}
for (slot = pcpu_size_to_slot(PAGE_SIZE); slot < pcpu_nr_slots; slot++) {
int nr_unpop = 0, rs, re;
if (!nr_to_pop)
break;
spin_lock_irq(&pcpu_lock);
list_for_each_entry(chunk, &pcpu_slot[slot], list) {
nr_unpop = pcpu_unit_pages - chunk->nr_populated;
if (nr_unpop)
break;
}
spin_unlock_irq(&pcpu_lock);
if (!nr_unpop)
continue;
pcpu_for_each_unpop_region(chunk, rs, re, 0, pcpu_unit_pages) {
int nr = min(re - rs, nr_to_pop);
ret = pcpu_populate_chunk(chunk, rs, rs + nr);
if (!ret) {
nr_to_pop -= nr;
spin_lock_irq(&pcpu_lock);
pcpu_chunk_populated(chunk, rs, rs + nr);
spin_unlock_irq(&pcpu_lock);
} else {
nr_to_pop = 0;
}
if (!nr_to_pop)
break;
}
}
if (nr_to_pop) {
chunk = pcpu_create_chunk();
if (chunk) {
spin_lock_irq(&pcpu_lock);
pcpu_chunk_relocate(chunk, -1);
spin_unlock_irq(&pcpu_lock);
goto retry_pop;
}
}
mutex_unlock(&pcpu_alloc_mutex);
}
void free_percpu(void __percpu *ptr)
{
void *addr;
struct pcpu_chunk *chunk;
unsigned long flags;
int off, occ_pages;
if (!ptr)
return;
kmemleak_free_percpu(ptr);
addr = __pcpu_ptr_to_addr(ptr);
spin_lock_irqsave(&pcpu_lock, flags);
chunk = pcpu_chunk_addr_search(addr);
off = addr - chunk->base_addr;
pcpu_free_area(chunk, off, &occ_pages);
if (chunk != pcpu_reserved_chunk)
pcpu_nr_empty_pop_pages += occ_pages;
if (chunk->free_size == pcpu_unit_size) {
struct pcpu_chunk *pos;
list_for_each_entry(pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if (pos != chunk) {
pcpu_schedule_balance_work();
break;
}
}
spin_unlock_irqrestore(&pcpu_lock, flags);
}
bool is_kernel_percpu_address(unsigned long addr)
{
#ifdef CONFIG_SMP
const size_t static_size = __per_cpu_end - __per_cpu_start;
void __percpu *base = __addr_to_pcpu_ptr(pcpu_base_addr);
unsigned int cpu;
for_each_possible_cpu(cpu) {
void *start = per_cpu_ptr(base, cpu);
if ((void *)addr >= start && (void *)addr < start + static_size)
return true;
}
#endif
return false;
}
phys_addr_t per_cpu_ptr_to_phys(void *addr)
{
void __percpu *base = __addr_to_pcpu_ptr(pcpu_base_addr);
bool in_first_chunk = false;
unsigned long first_low, first_high;
unsigned int cpu;
first_low = pcpu_chunk_addr(pcpu_first_chunk, pcpu_low_unit_cpu, 0);
first_high = pcpu_chunk_addr(pcpu_first_chunk, pcpu_high_unit_cpu,
pcpu_unit_pages);
if ((unsigned long)addr >= first_low &&
(unsigned long)addr < first_high) {
for_each_possible_cpu(cpu) {
void *start = per_cpu_ptr(base, cpu);
if (addr >= start && addr < start + pcpu_unit_size) {
in_first_chunk = true;
break;
}
}
}
if (in_first_chunk) {
if (!is_vmalloc_addr(addr))
return __pa(addr);
else
return page_to_phys(vmalloc_to_page(addr)) +
offset_in_page(addr);
} else
return page_to_phys(pcpu_addr_to_page(addr)) +
offset_in_page(addr);
}
struct pcpu_alloc_info * __init pcpu_alloc_alloc_info(int nr_groups,
int nr_units)
{
struct pcpu_alloc_info *ai;
size_t base_size, ai_size;
void *ptr;
int unit;
base_size = ALIGN(sizeof(*ai) + nr_groups * sizeof(ai->groups[0]),
__alignof__(ai->groups[0].cpu_map[0]));
ai_size = base_size + nr_units * sizeof(ai->groups[0].cpu_map[0]);
ptr = memblock_virt_alloc_nopanic(PFN_ALIGN(ai_size), 0);
if (!ptr)
return NULL;
ai = ptr;
ptr += base_size;
ai->groups[0].cpu_map = ptr;
for (unit = 0; unit < nr_units; unit++)
ai->groups[0].cpu_map[unit] = NR_CPUS;
ai->nr_groups = nr_groups;
ai->__ai_size = PFN_ALIGN(ai_size);
return ai;
}
void __init pcpu_free_alloc_info(struct pcpu_alloc_info *ai)
{
memblock_free_early(__pa(ai), ai->__ai_size);
}
static void pcpu_dump_alloc_info(const char *lvl,
const struct pcpu_alloc_info *ai)
{
int group_width = 1, cpu_width = 1, width;
char empty_str[] = "--------";
int alloc = 0, alloc_end = 0;
int group, v;
int upa, apl;
v = ai->nr_groups;
while (v /= 10)
group_width++;
v = num_possible_cpus();
while (v /= 10)
cpu_width++;
empty_str[min_t(int, cpu_width, sizeof(empty_str) - 1)] = '\0';
upa = ai->alloc_size / ai->unit_size;
width = upa * (cpu_width + 1) + group_width + 3;
apl = rounddown_pow_of_two(max(60 / width, 1));
printk("%spcpu-alloc: s%zu r%zu d%zu u%zu alloc=%zu*%zu",
lvl, ai->static_size, ai->reserved_size, ai->dyn_size,
ai->unit_size, ai->alloc_size / ai->atom_size, ai->atom_size);
for (group = 0; group < ai->nr_groups; group++) {
const struct pcpu_group_info *gi = &ai->groups[group];
int unit = 0, unit_end = 0;
BUG_ON(gi->nr_units % upa);
for (alloc_end += gi->nr_units / upa;
alloc < alloc_end; alloc++) {
if (!(alloc % apl)) {
pr_cont("\n");
printk("%spcpu-alloc: ", lvl);
}
pr_cont("[%0*d] ", group_width, group);
for (unit_end += upa; unit < unit_end; unit++)
if (gi->cpu_map[unit] != NR_CPUS)
pr_cont("%0*d ",
cpu_width, gi->cpu_map[unit]);
else
pr_cont("%s ", empty_str);
}
}
pr_cont("\n");
}
int __init pcpu_setup_first_chunk(const struct pcpu_alloc_info *ai,
void *base_addr)
{
static int smap[PERCPU_DYNAMIC_EARLY_SLOTS] __initdata;
static int dmap[PERCPU_DYNAMIC_EARLY_SLOTS] __initdata;
size_t dyn_size = ai->dyn_size;
size_t size_sum = ai->static_size + ai->reserved_size + dyn_size;
struct pcpu_chunk *schunk, *dchunk = NULL;
unsigned long *group_offsets;
size_t *group_sizes;
unsigned long *unit_off;
unsigned int cpu;
int *unit_map;
int group, unit, i;
#define PCPU_SETUP_BUG_ON(cond) do { \
if (unlikely(cond)) { \
pr_emerg("failed to initialize, %s\n", #cond); \
pr_emerg("cpu_possible_mask=%*pb\n", \
cpumask_pr_args(cpu_possible_mask)); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
PCPU_SETUP_BUG_ON(ai->nr_groups <= 0);
#ifdef CONFIG_SMP
PCPU_SETUP_BUG_ON(!ai->static_size);
PCPU_SETUP_BUG_ON(offset_in_page(__per_cpu_start));
#endif
PCPU_SETUP_BUG_ON(!base_addr);
PCPU_SETUP_BUG_ON(offset_in_page(base_addr));
PCPU_SETUP_BUG_ON(ai->unit_size < size_sum);
PCPU_SETUP_BUG_ON(offset_in_page(ai->unit_size));
PCPU_SETUP_BUG_ON(ai->unit_size < PCPU_MIN_UNIT_SIZE);
PCPU_SETUP_BUG_ON(ai->dyn_size < PERCPU_DYNAMIC_EARLY_SIZE);
PCPU_SETUP_BUG_ON(pcpu_verify_alloc_info(ai) < 0);
group_offsets = memblock_virt_alloc(ai->nr_groups *
sizeof(group_offsets[0]), 0);
group_sizes = memblock_virt_alloc(ai->nr_groups *
sizeof(group_sizes[0]), 0);
unit_map = memblock_virt_alloc(nr_cpu_ids * sizeof(unit_map[0]), 0);
unit_off = memblock_virt_alloc(nr_cpu_ids * sizeof(unit_off[0]), 0);
for (cpu = 0; cpu < nr_cpu_ids; cpu++)
unit_map[cpu] = UINT_MAX;
pcpu_low_unit_cpu = NR_CPUS;
pcpu_high_unit_cpu = NR_CPUS;
for (group = 0, unit = 0; group < ai->nr_groups; group++, unit += i) {
const struct pcpu_group_info *gi = &ai->groups[group];
group_offsets[group] = gi->base_offset;
group_sizes[group] = gi->nr_units * ai->unit_size;
for (i = 0; i < gi->nr_units; i++) {
cpu = gi->cpu_map[i];
if (cpu == NR_CPUS)
continue;
PCPU_SETUP_BUG_ON(cpu >= nr_cpu_ids);
PCPU_SETUP_BUG_ON(!cpu_possible(cpu));
PCPU_SETUP_BUG_ON(unit_map[cpu] != UINT_MAX);
unit_map[cpu] = unit + i;
unit_off[cpu] = gi->base_offset + i * ai->unit_size;
if (pcpu_low_unit_cpu == NR_CPUS ||
unit_off[cpu] < unit_off[pcpu_low_unit_cpu])
pcpu_low_unit_cpu = cpu;
if (pcpu_high_unit_cpu == NR_CPUS ||
unit_off[cpu] > unit_off[pcpu_high_unit_cpu])
pcpu_high_unit_cpu = cpu;
}
}
pcpu_nr_units = unit;
for_each_possible_cpu(cpu)
PCPU_SETUP_BUG_ON(unit_map[cpu] == UINT_MAX);
#undef PCPU_SETUP_BUG_ON
pcpu_dump_alloc_info(KERN_DEBUG, ai);
pcpu_nr_groups = ai->nr_groups;
pcpu_group_offsets = group_offsets;
pcpu_group_sizes = group_sizes;
pcpu_unit_map = unit_map;
pcpu_unit_offsets = unit_off;
pcpu_unit_pages = ai->unit_size >> PAGE_SHIFT;
pcpu_unit_size = pcpu_unit_pages << PAGE_SHIFT;
pcpu_atom_size = ai->atom_size;
pcpu_chunk_struct_size = sizeof(struct pcpu_chunk) +
BITS_TO_LONGS(pcpu_unit_pages) * sizeof(unsigned long);
pcpu_nr_slots = __pcpu_size_to_slot(pcpu_unit_size) + 2;
pcpu_slot = memblock_virt_alloc(
pcpu_nr_slots * sizeof(pcpu_slot[0]), 0);
for (i = 0; i < pcpu_nr_slots; i++)
INIT_LIST_HEAD(&pcpu_slot[i]);
schunk = memblock_virt_alloc(pcpu_chunk_struct_size, 0);
INIT_LIST_HEAD(&schunk->list);
INIT_LIST_HEAD(&schunk->map_extend_list);
schunk->base_addr = base_addr;
schunk->map = smap;
schunk->map_alloc = ARRAY_SIZE(smap);
schunk->immutable = true;
bitmap_fill(schunk->populated, pcpu_unit_pages);
schunk->nr_populated = pcpu_unit_pages;
if (ai->reserved_size) {
schunk->free_size = ai->reserved_size;
pcpu_reserved_chunk = schunk;
pcpu_reserved_chunk_limit = ai->static_size + ai->reserved_size;
} else {
schunk->free_size = dyn_size;
dyn_size = 0;
}
schunk->contig_hint = schunk->free_size;
schunk->map[0] = 1;
schunk->map[1] = ai->static_size;
schunk->map_used = 1;
if (schunk->free_size)
schunk->map[++schunk->map_used] = ai->static_size + schunk->free_size;
schunk->map[schunk->map_used] |= 1;
if (dyn_size) {
dchunk = memblock_virt_alloc(pcpu_chunk_struct_size, 0);
INIT_LIST_HEAD(&dchunk->list);
INIT_LIST_HEAD(&dchunk->map_extend_list);
dchunk->base_addr = base_addr;
dchunk->map = dmap;
dchunk->map_alloc = ARRAY_SIZE(dmap);
dchunk->immutable = true;
bitmap_fill(dchunk->populated, pcpu_unit_pages);
dchunk->nr_populated = pcpu_unit_pages;
dchunk->contig_hint = dchunk->free_size = dyn_size;
dchunk->map[0] = 1;
dchunk->map[1] = pcpu_reserved_chunk_limit;
dchunk->map[2] = (pcpu_reserved_chunk_limit + dchunk->free_size) | 1;
dchunk->map_used = 2;
}
pcpu_first_chunk = dchunk ?: schunk;
pcpu_nr_empty_pop_pages +=
pcpu_count_occupied_pages(pcpu_first_chunk, 1);
pcpu_chunk_relocate(pcpu_first_chunk, -1);
pcpu_base_addr = base_addr;
return 0;
}
static int __init percpu_alloc_setup(char *str)
{
if (!str)
return -EINVAL;
if (0)
;
#ifdef CONFIG_NEED_PER_CPU_EMBED_FIRST_CHUNK
else if (!strcmp(str, "embed"))
pcpu_chosen_fc = PCPU_FC_EMBED;
#endif
#ifdef CONFIG_NEED_PER_CPU_PAGE_FIRST_CHUNK
else if (!strcmp(str, "page"))
pcpu_chosen_fc = PCPU_FC_PAGE;
#endif
else
pr_warn("unknown allocator %s specified\n", str);
return 0;
}
static struct pcpu_alloc_info * __init pcpu_build_alloc_info(
size_t reserved_size, size_t dyn_size,
size_t atom_size,
pcpu_fc_cpu_distance_fn_t cpu_distance_fn)
{
static int group_map[NR_CPUS] __initdata;
static int group_cnt[NR_CPUS] __initdata;
const size_t static_size = __per_cpu_end - __per_cpu_start;
int nr_groups = 1, nr_units = 0;
size_t size_sum, min_unit_size, alloc_size;
int upa, max_upa, uninitialized_var(best_upa);
int last_allocs, group, unit;
unsigned int cpu, tcpu;
struct pcpu_alloc_info *ai;
unsigned int *cpu_map;
memset(group_map, 0, sizeof(group_map));
memset(group_cnt, 0, sizeof(group_cnt));
size_sum = PFN_ALIGN(static_size + reserved_size +
max_t(size_t, dyn_size, PERCPU_DYNAMIC_EARLY_SIZE));
dyn_size = size_sum - static_size - reserved_size;
min_unit_size = max_t(size_t, size_sum, PCPU_MIN_UNIT_SIZE);
alloc_size = roundup(min_unit_size, atom_size);
upa = alloc_size / min_unit_size;
while (alloc_size % upa || (offset_in_page(alloc_size / upa)))
upa--;
max_upa = upa;
for_each_possible_cpu(cpu) {
group = 0;
next_group:
for_each_possible_cpu(tcpu) {
if (cpu == tcpu)
break;
if (group_map[tcpu] == group && cpu_distance_fn &&
(cpu_distance_fn(cpu, tcpu) > LOCAL_DISTANCE ||
cpu_distance_fn(tcpu, cpu) > LOCAL_DISTANCE)) {
group++;
nr_groups = max(nr_groups, group + 1);
goto next_group;
}
}
group_map[cpu] = group;
group_cnt[group]++;
}
last_allocs = INT_MAX;
for (upa = max_upa; upa; upa--) {
int allocs = 0, wasted = 0;
if (alloc_size % upa || (offset_in_page(alloc_size / upa)))
continue;
for (group = 0; group < nr_groups; group++) {
int this_allocs = DIV_ROUND_UP(group_cnt[group], upa);
allocs += this_allocs;
wasted += this_allocs * upa - group_cnt[group];
}
if (wasted > num_possible_cpus() / 3)
continue;
if (allocs > last_allocs)
break;
last_allocs = allocs;
best_upa = upa;
}
upa = best_upa;
for (group = 0; group < nr_groups; group++)
nr_units += roundup(group_cnt[group], upa);
ai = pcpu_alloc_alloc_info(nr_groups, nr_units);
if (!ai)
return ERR_PTR(-ENOMEM);
cpu_map = ai->groups[0].cpu_map;
for (group = 0; group < nr_groups; group++) {
ai->groups[group].cpu_map = cpu_map;
cpu_map += roundup(group_cnt[group], upa);
}
ai->static_size = static_size;
ai->reserved_size = reserved_size;
ai->dyn_size = dyn_size;
ai->unit_size = alloc_size / upa;
ai->atom_size = atom_size;
ai->alloc_size = alloc_size;
for (group = 0, unit = 0; group_cnt[group]; group++) {
struct pcpu_group_info *gi = &ai->groups[group];
gi->base_offset = unit * ai->unit_size;
for_each_possible_cpu(cpu)
if (group_map[cpu] == group)
gi->cpu_map[gi->nr_units++] = cpu;
gi->nr_units = roundup(gi->nr_units, upa);
unit += gi->nr_units;
}
BUG_ON(unit != nr_units);
return ai;
}
int __init pcpu_embed_first_chunk(size_t reserved_size, size_t dyn_size,
size_t atom_size,
pcpu_fc_cpu_distance_fn_t cpu_distance_fn,
pcpu_fc_alloc_fn_t alloc_fn,
pcpu_fc_free_fn_t free_fn)
{
void *base = (void *)ULONG_MAX;
void **areas = NULL;
struct pcpu_alloc_info *ai;
size_t size_sum, areas_size;
unsigned long max_distance;
int group, i, highest_group, rc;
ai = pcpu_build_alloc_info(reserved_size, dyn_size, atom_size,
cpu_distance_fn);
if (IS_ERR(ai))
return PTR_ERR(ai);
size_sum = ai->static_size + ai->reserved_size + ai->dyn_size;
areas_size = PFN_ALIGN(ai->nr_groups * sizeof(void *));
areas = memblock_virt_alloc_nopanic(areas_size, 0);
if (!areas) {
rc = -ENOMEM;
goto out_free;
}
highest_group = 0;
for (group = 0; group < ai->nr_groups; group++) {
struct pcpu_group_info *gi = &ai->groups[group];
unsigned int cpu = NR_CPUS;
void *ptr;
for (i = 0; i < gi->nr_units && cpu == NR_CPUS; i++)
cpu = gi->cpu_map[i];
BUG_ON(cpu == NR_CPUS);
ptr = alloc_fn(cpu, gi->nr_units * ai->unit_size, atom_size);
if (!ptr) {
rc = -ENOMEM;
goto out_free_areas;
}
kmemleak_free(ptr);
areas[group] = ptr;
base = min(ptr, base);
if (ptr > areas[highest_group])
highest_group = group;
}
max_distance = areas[highest_group] - base;
max_distance += ai->unit_size * ai->groups[highest_group].nr_units;
if (max_distance > VMALLOC_TOTAL * 3 / 4) {
pr_warn("max_distance=0x%lx too large for vmalloc space 0x%lx\n",
max_distance, VMALLOC_TOTAL);
#ifdef CONFIG_NEED_PER_CPU_PAGE_FIRST_CHUNK
rc = -EINVAL;
goto out_free_areas;
#endif
}
for (group = 0; group < ai->nr_groups; group++) {
struct pcpu_group_info *gi = &ai->groups[group];
void *ptr = areas[group];
for (i = 0; i < gi->nr_units; i++, ptr += ai->unit_size) {
if (gi->cpu_map[i] == NR_CPUS) {
free_fn(ptr, ai->unit_size);
continue;
}
memcpy(ptr, __per_cpu_load, ai->static_size);
free_fn(ptr + size_sum, ai->unit_size - size_sum);
}
}
for (group = 0; group < ai->nr_groups; group++) {
ai->groups[group].base_offset = areas[group] - base;
}
pr_info("Embedded %zu pages/cpu @%p s%zu r%zu d%zu u%zu\n",
PFN_DOWN(size_sum), base, ai->static_size, ai->reserved_size,
ai->dyn_size, ai->unit_size);
rc = pcpu_setup_first_chunk(ai, base);
goto out_free;
out_free_areas:
for (group = 0; group < ai->nr_groups; group++)
if (areas[group])
free_fn(areas[group],
ai->groups[group].nr_units * ai->unit_size);
out_free:
pcpu_free_alloc_info(ai);
if (areas)
memblock_free_early(__pa(areas), areas_size);
return rc;
}
int __init pcpu_page_first_chunk(size_t reserved_size,
pcpu_fc_alloc_fn_t alloc_fn,
pcpu_fc_free_fn_t free_fn,
pcpu_fc_populate_pte_fn_t populate_pte_fn)
{
static struct vm_struct vm;
struct pcpu_alloc_info *ai;
char psize_str[16];
int unit_pages;
size_t pages_size;
struct page **pages;
int unit, i, j, rc;
int upa;
int nr_g0_units;
snprintf(psize_str, sizeof(psize_str), "%luK", PAGE_SIZE >> 10);
ai = pcpu_build_alloc_info(reserved_size, 0, PAGE_SIZE, NULL);
if (IS_ERR(ai))
return PTR_ERR(ai);
BUG_ON(ai->nr_groups != 1);
upa = ai->alloc_size/ai->unit_size;
nr_g0_units = roundup(num_possible_cpus(), upa);
if (unlikely(WARN_ON(ai->groups[0].nr_units != nr_g0_units))) {
pcpu_free_alloc_info(ai);
return -EINVAL;
}
unit_pages = ai->unit_size >> PAGE_SHIFT;
pages_size = PFN_ALIGN(unit_pages * num_possible_cpus() *
sizeof(pages[0]));
pages = memblock_virt_alloc(pages_size, 0);
j = 0;
for (unit = 0; unit < num_possible_cpus(); unit++) {
unsigned int cpu = ai->groups[0].cpu_map[unit];
for (i = 0; i < unit_pages; i++) {
void *ptr;
ptr = alloc_fn(cpu, PAGE_SIZE, PAGE_SIZE);
if (!ptr) {
pr_warn("failed to allocate %s page for cpu%u\n",
psize_str, cpu);
goto enomem;
}
kmemleak_free(ptr);
pages[j++] = virt_to_page(ptr);
}
}
vm.flags = VM_ALLOC;
vm.size = num_possible_cpus() * ai->unit_size;
vm_area_register_early(&vm, PAGE_SIZE);
for (unit = 0; unit < num_possible_cpus(); unit++) {
unsigned long unit_addr =
(unsigned long)vm.addr + unit * ai->unit_size;
for (i = 0; i < unit_pages; i++)
populate_pte_fn(unit_addr + (i << PAGE_SHIFT));
rc = __pcpu_map_pages(unit_addr, &pages[unit * unit_pages],
unit_pages);
if (rc < 0)
panic("failed to map percpu area, err=%d\n", rc);
memcpy((void *)unit_addr, __per_cpu_load, ai->static_size);
}
pr_info("%d %s pages/cpu @%p s%zu r%zu d%zu\n",
unit_pages, psize_str, vm.addr, ai->static_size,
ai->reserved_size, ai->dyn_size);
rc = pcpu_setup_first_chunk(ai, vm.addr);
goto out_free_ar;
enomem:
while (--j >= 0)
free_fn(page_address(pages[j]), PAGE_SIZE);
rc = -ENOMEM;
out_free_ar:
memblock_free_early(__pa(pages), pages_size);
pcpu_free_alloc_info(ai);
return rc;
}
static void * __init pcpu_dfl_fc_alloc(unsigned int cpu, size_t size,
size_t align)
{
return memblock_virt_alloc_from_nopanic(
size, align, __pa(MAX_DMA_ADDRESS));
}
static void __init pcpu_dfl_fc_free(void *ptr, size_t size)
{
memblock_free_early(__pa(ptr), size);
}
void __init setup_per_cpu_areas(void)
{
unsigned long delta;
unsigned int cpu;
int rc;
rc = pcpu_embed_first_chunk(PERCPU_MODULE_RESERVE,
PERCPU_DYNAMIC_RESERVE, PAGE_SIZE, NULL,
pcpu_dfl_fc_alloc, pcpu_dfl_fc_free);
if (rc < 0)
panic("Failed to initialize percpu areas.");
delta = (unsigned long)pcpu_base_addr - (unsigned long)__per_cpu_start;
for_each_possible_cpu(cpu)
__per_cpu_offset[cpu] = delta + pcpu_unit_offsets[cpu];
}
void __init setup_per_cpu_areas(void)
{
const size_t unit_size =
roundup_pow_of_two(max_t(size_t, PCPU_MIN_UNIT_SIZE,
PERCPU_DYNAMIC_RESERVE));
struct pcpu_alloc_info *ai;
void *fc;
ai = pcpu_alloc_alloc_info(1, 1);
fc = memblock_virt_alloc_from_nopanic(unit_size,
PAGE_SIZE,
__pa(MAX_DMA_ADDRESS));
if (!ai || !fc)
panic("Failed to allocate memory for percpu areas.");
kmemleak_free(fc);
ai->dyn_size = unit_size;
ai->unit_size = unit_size;
ai->atom_size = unit_size;
ai->alloc_size = unit_size;
ai->groups[0].nr_units = 1;
ai->groups[0].cpu_map[0] = 0;
if (pcpu_setup_first_chunk(ai, fc) < 0)
panic("Failed to initialize percpu areas.");
}
void __init percpu_init_late(void)
{
struct pcpu_chunk *target_chunks[] =
{ pcpu_first_chunk, pcpu_reserved_chunk, NULL };
struct pcpu_chunk *chunk;
unsigned long flags;
int i;
for (i = 0; (chunk = target_chunks[i]); i++) {
int *map;
const size_t size = PERCPU_DYNAMIC_EARLY_SLOTS * sizeof(map[0]);
BUILD_BUG_ON(size > PAGE_SIZE);
map = pcpu_mem_zalloc(size);
BUG_ON(!map);
spin_lock_irqsave(&pcpu_lock, flags);
memcpy(map, chunk->map, size);
chunk->map = map;
spin_unlock_irqrestore(&pcpu_lock, flags);
}
}
static int __init percpu_enable_async(void)
{
pcpu_async_enabled = true;
return 0;
}
