static void pcpu_schedule_balance_work(void)
{
if (pcpu_async_enabled)
schedule_work(&pcpu_balance_work);
}
static bool pcpu_addr_in_chunk(struct pcpu_chunk *chunk, void *addr)
{
void *start_addr, *end_addr;
if (!chunk)
return false;
start_addr = chunk->base_addr + chunk->start_offset;
end_addr = chunk->base_addr + chunk->nr_pages * PAGE_SIZE -
chunk->end_offset;
return addr >= start_addr && addr < end_addr;
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
if (chunk->free_bytes < PCPU_MIN_ALLOC_SIZE || chunk->contig_bits == 0)
return 0;
return pcpu_size_to_slot(chunk->free_bytes);
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
static unsigned long pcpu_unit_page_offset(unsigned int cpu, int page_idx)
{
return pcpu_unit_offsets[cpu] + (page_idx << PAGE_SHIFT);
}
static unsigned long pcpu_chunk_addr(struct pcpu_chunk *chunk,
unsigned int cpu, int page_idx)
{
return (unsigned long)chunk->base_addr +
pcpu_unit_page_offset(cpu, page_idx);
}
static void pcpu_next_unpop(unsigned long *bitmap, int *rs, int *re, int end)
{
*rs = find_next_zero_bit(bitmap, end, *rs);
*re = find_next_bit(bitmap, end, *rs + 1);
}
static void pcpu_next_pop(unsigned long *bitmap, int *rs, int *re, int end)
{
*rs = find_next_bit(bitmap, end, *rs);
*re = find_next_zero_bit(bitmap, end, *rs + 1);
}
static unsigned long *pcpu_index_alloc_map(struct pcpu_chunk *chunk, int index)
{
return chunk->alloc_map +
(index * PCPU_BITMAP_BLOCK_BITS / BITS_PER_LONG);
}
static unsigned long pcpu_off_to_block_index(int off)
{
return off / PCPU_BITMAP_BLOCK_BITS;
}
static unsigned long pcpu_off_to_block_off(int off)
{
return off & (PCPU_BITMAP_BLOCK_BITS - 1);
}
static unsigned long pcpu_block_off_to_off(int index, int off)
{
return index * PCPU_BITMAP_BLOCK_BITS + off;
}
static void pcpu_next_md_free_region(struct pcpu_chunk *chunk, int *bit_off,
int *bits)
{
int i = pcpu_off_to_block_index(*bit_off);
int block_off = pcpu_off_to_block_off(*bit_off);
struct pcpu_block_md *block;
*bits = 0;
for (block = chunk->md_blocks + i; i < pcpu_chunk_nr_blocks(chunk);
block++, i++) {
if (*bits) {
*bits += block->left_free;
if (block->left_free == PCPU_BITMAP_BLOCK_BITS)
continue;
return;
}
*bits = block->contig_hint;
if (*bits && block->contig_hint_start >= block_off &&
*bits + block->contig_hint_start < PCPU_BITMAP_BLOCK_BITS) {
*bit_off = pcpu_block_off_to_off(i,
block->contig_hint_start);
return;
}
block_off = 0;
*bits = block->right_free;
*bit_off = (i + 1) * PCPU_BITMAP_BLOCK_BITS - block->right_free;
}
}
static void pcpu_next_fit_region(struct pcpu_chunk *chunk, int alloc_bits,
int align, int *bit_off, int *bits)
{
int i = pcpu_off_to_block_index(*bit_off);
int block_off = pcpu_off_to_block_off(*bit_off);
struct pcpu_block_md *block;
*bits = 0;
for (block = chunk->md_blocks + i; i < pcpu_chunk_nr_blocks(chunk);
block++, i++) {
if (*bits) {
*bits += block->left_free;
if (*bits >= alloc_bits)
return;
if (block->left_free == PCPU_BITMAP_BLOCK_BITS)
continue;
}
*bits = ALIGN(block->contig_hint_start, align) -
block->contig_hint_start;
if (block->contig_hint &&
block->contig_hint_start >= block_off &&
block->contig_hint >= *bits + alloc_bits) {
*bits += alloc_bits + block->contig_hint_start -
block->first_free;
*bit_off = pcpu_block_off_to_off(i, block->first_free);
return;
}
block_off = 0;
*bit_off = ALIGN(PCPU_BITMAP_BLOCK_BITS - block->right_free,
align);
*bits = PCPU_BITMAP_BLOCK_BITS - *bit_off;
*bit_off = pcpu_block_off_to_off(i, *bit_off);
if (*bits >= alloc_bits)
return;
}
*bit_off = pcpu_chunk_map_bits(chunk);
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
static inline int pcpu_cnt_pop_pages(struct pcpu_chunk *chunk, int bit_off,
int bits)
{
int page_start = PFN_UP(bit_off * PCPU_MIN_ALLOC_SIZE);
int page_end = PFN_DOWN((bit_off + bits) * PCPU_MIN_ALLOC_SIZE);
if (page_start >= page_end)
return 0;
return bitmap_weight(chunk->populated, page_end) -
bitmap_weight(chunk->populated, page_start);
}
static void pcpu_chunk_update(struct pcpu_chunk *chunk, int bit_off, int bits)
{
if (bits > chunk->contig_bits) {
chunk->contig_bits_start = bit_off;
chunk->contig_bits = bits;
} else if (bits == chunk->contig_bits && chunk->contig_bits_start &&
(!bit_off ||
__ffs(bit_off) > __ffs(chunk->contig_bits_start))) {
chunk->contig_bits_start = bit_off;
}
}
static void pcpu_chunk_refresh_hint(struct pcpu_chunk *chunk)
{
int bit_off, bits, nr_empty_pop_pages;
chunk->contig_bits = 0;
bit_off = chunk->first_bit;
bits = nr_empty_pop_pages = 0;
pcpu_for_each_md_free_region(chunk, bit_off, bits) {
pcpu_chunk_update(chunk, bit_off, bits);
nr_empty_pop_pages += pcpu_cnt_pop_pages(chunk, bit_off, bits);
}
if (chunk != pcpu_reserved_chunk)
pcpu_nr_empty_pop_pages +=
(nr_empty_pop_pages - chunk->nr_empty_pop_pages);
chunk->nr_empty_pop_pages = nr_empty_pop_pages;
}
static void pcpu_block_update(struct pcpu_block_md *block, int start, int end)
{
int contig = end - start;
block->first_free = min(block->first_free, start);
if (start == 0)
block->left_free = contig;
if (end == PCPU_BITMAP_BLOCK_BITS)
block->right_free = contig;
if (contig > block->contig_hint) {
block->contig_hint_start = start;
block->contig_hint = contig;
} else if (block->contig_hint_start && contig == block->contig_hint &&
(!start || __ffs(start) > __ffs(block->contig_hint_start))) {
block->contig_hint_start = start;
}
}
static void pcpu_block_refresh_hint(struct pcpu_chunk *chunk, int index)
{
struct pcpu_block_md *block = chunk->md_blocks + index;
unsigned long *alloc_map = pcpu_index_alloc_map(chunk, index);
int rs, re;
block->contig_hint = 0;
block->left_free = block->right_free = 0;
pcpu_for_each_unpop_region(alloc_map, rs, re, block->first_free,
PCPU_BITMAP_BLOCK_BITS) {
pcpu_block_update(block, rs, re);
}
}
static void pcpu_block_update_hint_alloc(struct pcpu_chunk *chunk, int bit_off,
int bits)
{
struct pcpu_block_md *s_block, *e_block, *block;
int s_index, e_index;
int s_off, e_off;
s_index = pcpu_off_to_block_index(bit_off);
e_index = pcpu_off_to_block_index(bit_off + bits - 1);
s_off = pcpu_off_to_block_off(bit_off);
e_off = pcpu_off_to_block_off(bit_off + bits - 1) + 1;
s_block = chunk->md_blocks + s_index;
e_block = chunk->md_blocks + e_index;
if (s_off == s_block->first_free)
s_block->first_free = find_next_zero_bit(
pcpu_index_alloc_map(chunk, s_index),
PCPU_BITMAP_BLOCK_BITS,
s_off + bits);
if (s_off >= s_block->contig_hint_start &&
s_off < s_block->contig_hint_start + s_block->contig_hint) {
pcpu_block_refresh_hint(chunk, s_index);
} else {
s_block->left_free = min(s_block->left_free, s_off);
if (s_index == e_index)
s_block->right_free = min_t(int, s_block->right_free,
PCPU_BITMAP_BLOCK_BITS - e_off);
else
s_block->right_free = 0;
}
if (s_index != e_index) {
e_block->first_free = find_next_zero_bit(
pcpu_index_alloc_map(chunk, e_index),
PCPU_BITMAP_BLOCK_BITS, e_off);
if (e_off == PCPU_BITMAP_BLOCK_BITS) {
e_block++;
} else {
if (e_off > e_block->contig_hint_start) {
pcpu_block_refresh_hint(chunk, e_index);
} else {
e_block->left_free = 0;
e_block->right_free =
min_t(int, e_block->right_free,
PCPU_BITMAP_BLOCK_BITS - e_off);
}
}
for (block = s_block + 1; block < e_block; block++) {
block->contig_hint = 0;
block->left_free = 0;
block->right_free = 0;
}
}
if (bit_off >= chunk->contig_bits_start &&
bit_off < chunk->contig_bits_start + chunk->contig_bits)
pcpu_chunk_refresh_hint(chunk);
}
static void pcpu_block_update_hint_free(struct pcpu_chunk *chunk, int bit_off,
int bits)
{
struct pcpu_block_md *s_block, *e_block, *block;
int s_index, e_index;
int s_off, e_off;
int start, end;
s_index = pcpu_off_to_block_index(bit_off);
e_index = pcpu_off_to_block_index(bit_off + bits - 1);
s_off = pcpu_off_to_block_off(bit_off);
e_off = pcpu_off_to_block_off(bit_off + bits - 1) + 1;
s_block = chunk->md_blocks + s_index;
e_block = chunk->md_blocks + e_index;
start = s_off;
if (s_off == s_block->contig_hint + s_block->contig_hint_start) {
start = s_block->contig_hint_start;
} else {
int l_bit = find_last_bit(pcpu_index_alloc_map(chunk, s_index),
start);
start = (start == l_bit) ? 0 : l_bit + 1;
}
end = e_off;
if (e_off == e_block->contig_hint_start)
end = e_block->contig_hint_start + e_block->contig_hint;
else
end = find_next_bit(pcpu_index_alloc_map(chunk, e_index),
PCPU_BITMAP_BLOCK_BITS, end);
e_off = (s_index == e_index) ? end : PCPU_BITMAP_BLOCK_BITS;
pcpu_block_update(s_block, start, e_off);
if (s_index != e_index) {
pcpu_block_update(e_block, 0, end);
for (block = s_block + 1; block < e_block; block++) {
block->first_free = 0;
block->contig_hint_start = 0;
block->contig_hint = PCPU_BITMAP_BLOCK_BITS;
block->left_free = PCPU_BITMAP_BLOCK_BITS;
block->right_free = PCPU_BITMAP_BLOCK_BITS;
}
}
if ((ALIGN_DOWN(end, min(PCPU_BITS_PER_PAGE, PCPU_BITMAP_BLOCK_BITS)) >
ALIGN(start, min(PCPU_BITS_PER_PAGE, PCPU_BITMAP_BLOCK_BITS))) ||
s_index != e_index)
pcpu_chunk_refresh_hint(chunk);
else
pcpu_chunk_update(chunk, pcpu_block_off_to_off(s_index, start),
s_block->contig_hint);
}
static bool pcpu_is_populated(struct pcpu_chunk *chunk, int bit_off, int bits,
int *next_off)
{
int page_start, page_end, rs, re;
page_start = PFN_DOWN(bit_off * PCPU_MIN_ALLOC_SIZE);
page_end = PFN_UP((bit_off + bits) * PCPU_MIN_ALLOC_SIZE);
rs = page_start;
pcpu_next_unpop(chunk->populated, &rs, &re, page_end);
if (rs >= page_end)
return true;
*next_off = re * PAGE_SIZE / PCPU_MIN_ALLOC_SIZE;
return false;
}
static int pcpu_find_block_fit(struct pcpu_chunk *chunk, int alloc_bits,
size_t align, bool pop_only)
{
int bit_off, bits, next_off;
bit_off = ALIGN(chunk->contig_bits_start, align) -
chunk->contig_bits_start;
if (bit_off + alloc_bits > chunk->contig_bits)
return -1;
bit_off = chunk->first_bit;
bits = 0;
pcpu_for_each_fit_region(chunk, alloc_bits, align, bit_off, bits) {
if (!pop_only || pcpu_is_populated(chunk, bit_off, bits,
&next_off))
break;
bit_off = next_off;
bits = 0;
}
if (bit_off == pcpu_chunk_map_bits(chunk))
return -1;
return bit_off;
}
static int pcpu_alloc_area(struct pcpu_chunk *chunk, int alloc_bits,
size_t align, int start)
{
size_t align_mask = (align) ? (align - 1) : 0;
int bit_off, end, oslot;
lockdep_assert_held(&pcpu_lock);
oslot = pcpu_chunk_slot(chunk);
end = start + alloc_bits + PCPU_BITMAP_BLOCK_BITS;
bit_off = bitmap_find_next_zero_area(chunk->alloc_map, end, start,
alloc_bits, align_mask);
if (bit_off >= end)
return -1;
bitmap_set(chunk->alloc_map, bit_off, alloc_bits);
set_bit(bit_off, chunk->bound_map);
bitmap_clear(chunk->bound_map, bit_off + 1, alloc_bits - 1);
set_bit(bit_off + alloc_bits, chunk->bound_map);
chunk->free_bytes -= alloc_bits * PCPU_MIN_ALLOC_SIZE;
if (bit_off == chunk->first_bit)
chunk->first_bit = find_next_zero_bit(
chunk->alloc_map,
pcpu_chunk_map_bits(chunk),
bit_off + alloc_bits);
pcpu_block_update_hint_alloc(chunk, bit_off, alloc_bits);
pcpu_chunk_relocate(chunk, oslot);
return bit_off * PCPU_MIN_ALLOC_SIZE;
}
static void pcpu_free_area(struct pcpu_chunk *chunk, int off)
{
int bit_off, bits, end, oslot;
lockdep_assert_held(&pcpu_lock);
pcpu_stats_area_dealloc(chunk);
oslot = pcpu_chunk_slot(chunk);
bit_off = off / PCPU_MIN_ALLOC_SIZE;
end = find_next_bit(chunk->bound_map, pcpu_chunk_map_bits(chunk),
bit_off + 1);
bits = end - bit_off;
bitmap_clear(chunk->alloc_map, bit_off, bits);
chunk->free_bytes += bits * PCPU_MIN_ALLOC_SIZE;
chunk->first_bit = min(chunk->first_bit, bit_off);
pcpu_block_update_hint_free(chunk, bit_off, bits);
pcpu_chunk_relocate(chunk, oslot);
}
static void pcpu_init_md_blocks(struct pcpu_chunk *chunk)
{
struct pcpu_block_md *md_block;
for (md_block = chunk->md_blocks;
md_block != chunk->md_blocks + pcpu_chunk_nr_blocks(chunk);
md_block++) {
md_block->contig_hint = PCPU_BITMAP_BLOCK_BITS;
md_block->left_free = PCPU_BITMAP_BLOCK_BITS;
md_block->right_free = PCPU_BITMAP_BLOCK_BITS;
}
}
static struct pcpu_chunk * __init pcpu_alloc_first_chunk(unsigned long tmp_addr,
int map_size)
{
struct pcpu_chunk *chunk;
unsigned long aligned_addr, lcm_align;
int start_offset, offset_bits, region_size, region_bits;
aligned_addr = tmp_addr & PAGE_MASK;
start_offset = tmp_addr - aligned_addr;
lcm_align = lcm(PAGE_SIZE, PCPU_BITMAP_BLOCK_SIZE);
region_size = ALIGN(start_offset + map_size, lcm_align);
chunk = memblock_virt_alloc(sizeof(struct pcpu_chunk) +
BITS_TO_LONGS(region_size >> PAGE_SHIFT),
0);
INIT_LIST_HEAD(&chunk->list);
chunk->base_addr = (void *)aligned_addr;
chunk->start_offset = start_offset;
chunk->end_offset = region_size - chunk->start_offset - map_size;
chunk->nr_pages = region_size >> PAGE_SHIFT;
region_bits = pcpu_chunk_map_bits(chunk);
chunk->alloc_map = memblock_virt_alloc(BITS_TO_LONGS(region_bits) *
sizeof(chunk->alloc_map[0]), 0);
chunk->bound_map = memblock_virt_alloc(BITS_TO_LONGS(region_bits + 1) *
sizeof(chunk->bound_map[0]), 0);
chunk->md_blocks = memblock_virt_alloc(pcpu_chunk_nr_blocks(chunk) *
sizeof(chunk->md_blocks[0]), 0);
pcpu_init_md_blocks(chunk);
chunk->immutable = true;
bitmap_fill(chunk->populated, chunk->nr_pages);
chunk->nr_populated = chunk->nr_pages;
chunk->nr_empty_pop_pages =
pcpu_cnt_pop_pages(chunk, start_offset / PCPU_MIN_ALLOC_SIZE,
map_size / PCPU_MIN_ALLOC_SIZE);
chunk->contig_bits = map_size / PCPU_MIN_ALLOC_SIZE;
chunk->free_bytes = map_size;
if (chunk->start_offset) {
offset_bits = chunk->start_offset / PCPU_MIN_ALLOC_SIZE;
bitmap_set(chunk->alloc_map, 0, offset_bits);
set_bit(0, chunk->bound_map);
set_bit(offset_bits, chunk->bound_map);
chunk->first_bit = offset_bits;
pcpu_block_update_hint_alloc(chunk, 0, offset_bits);
}
if (chunk->end_offset) {
offset_bits = chunk->end_offset / PCPU_MIN_ALLOC_SIZE;
bitmap_set(chunk->alloc_map,
pcpu_chunk_map_bits(chunk) - offset_bits,
offset_bits);
set_bit((start_offset + map_size) / PCPU_MIN_ALLOC_SIZE,
chunk->bound_map);
set_bit(region_bits, chunk->bound_map);
pcpu_block_update_hint_alloc(chunk, pcpu_chunk_map_bits(chunk)
- offset_bits, offset_bits);
}
return chunk;
}
static struct pcpu_chunk *pcpu_alloc_chunk(void)
{
struct pcpu_chunk *chunk;
int region_bits;
chunk = pcpu_mem_zalloc(pcpu_chunk_struct_size);
if (!chunk)
return NULL;
INIT_LIST_HEAD(&chunk->list);
chunk->nr_pages = pcpu_unit_pages;
region_bits = pcpu_chunk_map_bits(chunk);
chunk->alloc_map = pcpu_mem_zalloc(BITS_TO_LONGS(region_bits) *
sizeof(chunk->alloc_map[0]));
if (!chunk->alloc_map)
goto alloc_map_fail;
chunk->bound_map = pcpu_mem_zalloc(BITS_TO_LONGS(region_bits + 1) *
sizeof(chunk->bound_map[0]));
if (!chunk->bound_map)
goto bound_map_fail;
chunk->md_blocks = pcpu_mem_zalloc(pcpu_chunk_nr_blocks(chunk) *
sizeof(chunk->md_blocks[0]));
if (!chunk->md_blocks)
goto md_blocks_fail;
pcpu_init_md_blocks(chunk);
chunk->contig_bits = region_bits;
chunk->free_bytes = chunk->nr_pages * PAGE_SIZE;
return chunk;
md_blocks_fail:
pcpu_mem_free(chunk->bound_map);
bound_map_fail:
pcpu_mem_free(chunk->alloc_map);
alloc_map_fail:
pcpu_mem_free(chunk);
return NULL;
}
static void pcpu_free_chunk(struct pcpu_chunk *chunk)
{
if (!chunk)
return;
pcpu_mem_free(chunk->bound_map);
pcpu_mem_free(chunk->alloc_map);
pcpu_mem_free(chunk);
}
static void pcpu_chunk_populated(struct pcpu_chunk *chunk, int page_start,
int page_end, bool for_alloc)
{
int nr = page_end - page_start;
lockdep_assert_held(&pcpu_lock);
bitmap_set(chunk->populated, page_start, nr);
chunk->nr_populated += nr;
if (!for_alloc) {
chunk->nr_empty_pop_pages += nr;
pcpu_nr_empty_pop_pages += nr;
}
}
static void pcpu_chunk_depopulated(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
int nr = page_end - page_start;
lockdep_assert_held(&pcpu_lock);
bitmap_clear(chunk->populated, page_start, nr);
chunk->nr_populated -= nr;
chunk->nr_empty_pop_pages -= nr;
pcpu_nr_empty_pop_pages -= nr;
}
static struct pcpu_chunk *pcpu_chunk_addr_search(void *addr)
{
if (pcpu_addr_in_chunk(pcpu_first_chunk, addr))
return pcpu_first_chunk;
if (pcpu_addr_in_chunk(pcpu_reserved_chunk, addr))
return pcpu_reserved_chunk;
addr += pcpu_unit_offsets[raw_smp_processor_id()];
return pcpu_get_page_chunk(pcpu_addr_to_page(addr));
}
static void __percpu *pcpu_alloc(size_t size, size_t align, bool reserved,
gfp_t gfp)
{
bool is_atomic = (gfp & GFP_KERNEL) != GFP_KERNEL;
bool do_warn = !(gfp & __GFP_NOWARN);
static int warn_limit = 10;
struct pcpu_chunk *chunk;
const char *err;
int slot, off, cpu, ret;
unsigned long flags;
void __percpu *ptr;
size_t bits, bit_align;
if (unlikely(align < PCPU_MIN_ALLOC_SIZE))
align = PCPU_MIN_ALLOC_SIZE;
size = ALIGN(size, PCPU_MIN_ALLOC_SIZE);
bits = size >> PCPU_MIN_ALLOC_SHIFT;
bit_align = align >> PCPU_MIN_ALLOC_SHIFT;
if (unlikely(!size || size > PCPU_MIN_UNIT_SIZE || align > PAGE_SIZE ||
!is_power_of_2(align))) {
WARN(do_warn, "illegal size (%zu) or align (%zu) for percpu allocation\n",
size, align);
return NULL;
}
if (!is_atomic)
mutex_lock(&pcpu_alloc_mutex);
spin_lock_irqsave(&pcpu_lock, flags);
if (reserved && pcpu_reserved_chunk) {
chunk = pcpu_reserved_chunk;
off = pcpu_find_block_fit(chunk, bits, bit_align, is_atomic);
if (off < 0) {
err = "alloc from reserved chunk failed";
goto fail_unlock;
}
off = pcpu_alloc_area(chunk, bits, bit_align, off);
if (off >= 0)
goto area_found;
err = "alloc from reserved chunk failed";
goto fail_unlock;
}
restart:
for (slot = pcpu_size_to_slot(size); slot < pcpu_nr_slots; slot++) {
list_for_each_entry(chunk, &pcpu_slot[slot], list) {
off = pcpu_find_block_fit(chunk, bits, bit_align,
is_atomic);
if (off < 0)
continue;
off = pcpu_alloc_area(chunk, bits, bit_align, off);
if (off >= 0)
goto area_found;
}
}
spin_unlock_irqrestore(&pcpu_lock, flags);
if (is_atomic) {
err = "atomic alloc failed, no space left";
goto fail;
}
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
pcpu_stats_area_alloc(chunk, size);
spin_unlock_irqrestore(&pcpu_lock, flags);
if (!is_atomic) {
int page_start, page_end, rs, re;
page_start = PFN_DOWN(off);
page_end = PFN_UP(off + size);
pcpu_for_each_unpop_region(chunk->populated, rs, re,
page_start, page_end) {
WARN_ON(chunk->immutable);
ret = pcpu_populate_chunk(chunk, rs, re);
spin_lock_irqsave(&pcpu_lock, flags);
if (ret) {
pcpu_free_area(chunk, off);
err = "failed to populate";
goto fail_unlock;
}
pcpu_chunk_populated(chunk, rs, re, true);
spin_unlock_irqrestore(&pcpu_lock, flags);
}
mutex_unlock(&pcpu_alloc_mutex);
}
if (pcpu_nr_empty_pop_pages < PCPU_EMPTY_POP_PAGES_LOW)
pcpu_schedule_balance_work();
for_each_possible_cpu(cpu)
memset((void *)pcpu_chunk_addr(chunk, cpu, 0) + off, 0, size);
ptr = __addr_to_pcpu_ptr(chunk->base_addr + off);
kmemleak_alloc_percpu(ptr, size, gfp);
trace_percpu_alloc_percpu(reserved, is_atomic, size, align,
chunk->base_addr, off, ptr);
return ptr;
fail_unlock:
spin_unlock_irqrestore(&pcpu_lock, flags);
fail:
trace_percpu_alloc_percpu_fail(reserved, is_atomic, size, align);
if (!is_atomic && do_warn && warn_limit) {
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
list_move(&chunk->list, &to_free);
}
spin_unlock_irq(&pcpu_lock);
list_for_each_entry_safe(chunk, next, &to_free, list) {
int rs, re;
pcpu_for_each_pop_region(chunk->populated, rs, re, 0,
chunk->nr_pages) {
pcpu_depopulate_chunk(chunk, rs, re);
spin_lock_irq(&pcpu_lock);
pcpu_chunk_depopulated(chunk, rs, re);
spin_unlock_irq(&pcpu_lock);
}
pcpu_destroy_chunk(chunk);
}
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
nr_unpop = chunk->nr_pages - chunk->nr_populated;
if (nr_unpop)
break;
}
spin_unlock_irq(&pcpu_lock);
if (!nr_unpop)
continue;
pcpu_for_each_unpop_region(chunk->populated, rs, re, 0,
chunk->nr_pages) {
int nr = min(re - rs, nr_to_pop);
ret = pcpu_populate_chunk(chunk, rs, rs + nr);
if (!ret) {
nr_to_pop -= nr;
spin_lock_irq(&pcpu_lock);
pcpu_chunk_populated(chunk, rs, rs + nr, false);
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
int off;
if (!ptr)
return;
kmemleak_free_percpu(ptr);
addr = __pcpu_ptr_to_addr(ptr);
spin_lock_irqsave(&pcpu_lock, flags);
chunk = pcpu_chunk_addr_search(addr);
off = addr - chunk->base_addr;
pcpu_free_area(chunk, off);
if (chunk->free_bytes == pcpu_unit_size) {
struct pcpu_chunk *pos;
list_for_each_entry(pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if (pos != chunk) {
pcpu_schedule_balance_work();
break;
}
}
trace_percpu_free_percpu(chunk->base_addr, off, ptr);
spin_unlock_irqrestore(&pcpu_lock, flags);
}
bool __is_kernel_percpu_address(unsigned long addr, unsigned long *can_addr)
{
#ifdef CONFIG_SMP
const size_t static_size = __per_cpu_end - __per_cpu_start;
void __percpu *base = __addr_to_pcpu_ptr(pcpu_base_addr);
unsigned int cpu;
for_each_possible_cpu(cpu) {
void *start = per_cpu_ptr(base, cpu);
void *va = (void *)addr;
if (va >= start && va < start + static_size) {
if (can_addr) {
*can_addr = (unsigned long) (va - start);
*can_addr += (unsigned long)
per_cpu_ptr(base, get_boot_cpu_id());
}
return true;
}
}
#endif
return false;
}
bool is_kernel_percpu_address(unsigned long addr)
{
return __is_kernel_percpu_address(addr, NULL);
}
phys_addr_t per_cpu_ptr_to_phys(void *addr)
{
void __percpu *base = __addr_to_pcpu_ptr(pcpu_base_addr);
bool in_first_chunk = false;
unsigned long first_low, first_high;
unsigned int cpu;
first_low = (unsigned long)pcpu_base_addr +
pcpu_unit_page_offset(pcpu_low_unit_cpu, 0);
first_high = (unsigned long)pcpu_base_addr +
pcpu_unit_page_offset(pcpu_high_unit_cpu, pcpu_unit_pages);
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
size_t size_sum = ai->static_size + ai->reserved_size + ai->dyn_size;
size_t static_size, dyn_size;
struct pcpu_chunk *chunk;
unsigned long *group_offsets;
size_t *group_sizes;
unsigned long *unit_off;
unsigned int cpu;
int *unit_map;
int group, unit, i;
int map_size;
unsigned long tmp_addr;
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
PCPU_SETUP_BUG_ON(!IS_ALIGNED(ai->unit_size, PCPU_BITMAP_BLOCK_SIZE));
PCPU_SETUP_BUG_ON(ai->dyn_size < PERCPU_DYNAMIC_EARLY_SIZE);
PCPU_SETUP_BUG_ON(!ai->dyn_size);
PCPU_SETUP_BUG_ON(!IS_ALIGNED(ai->reserved_size, PCPU_MIN_ALLOC_SIZE));
PCPU_SETUP_BUG_ON(!(IS_ALIGNED(PCPU_BITMAP_BLOCK_SIZE, PAGE_SIZE) ||
IS_ALIGNED(PAGE_SIZE, PCPU_BITMAP_BLOCK_SIZE)));
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
pcpu_stats_save_ai(ai);
pcpu_nr_slots = __pcpu_size_to_slot(pcpu_unit_size) + 2;
pcpu_slot = memblock_virt_alloc(
pcpu_nr_slots * sizeof(pcpu_slot[0]), 0);
for (i = 0; i < pcpu_nr_slots; i++)
INIT_LIST_HEAD(&pcpu_slot[i]);
static_size = ALIGN(ai->static_size, PCPU_MIN_ALLOC_SIZE);
dyn_size = ai->dyn_size - (static_size - ai->static_size);
tmp_addr = (unsigned long)base_addr + static_size;
map_size = ai->reserved_size ?: dyn_size;
chunk = pcpu_alloc_first_chunk(tmp_addr, map_size);
if (ai->reserved_size) {
pcpu_reserved_chunk = chunk;
tmp_addr = (unsigned long)base_addr + static_size +
ai->reserved_size;
map_size = dyn_size;
chunk = pcpu_alloc_first_chunk(tmp_addr, map_size);
}
pcpu_first_chunk = chunk;
pcpu_nr_empty_pop_pages = pcpu_first_chunk->nr_empty_pop_pages;
pcpu_chunk_relocate(pcpu_first_chunk, -1);
pcpu_stats_chunk_alloc();
trace_percpu_create_chunk(base_addr);
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
static int __init percpu_enable_async(void)
{
pcpu_async_enabled = true;
return 0;
}
