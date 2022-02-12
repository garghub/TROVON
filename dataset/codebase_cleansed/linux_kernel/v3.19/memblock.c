static __init_memblock const char *
memblock_type_name(struct memblock_type *type)
{
if (type == &memblock.memory)
return "memory";
else if (type == &memblock.reserved)
return "reserved";
else
return "unknown";
}
static inline phys_addr_t memblock_cap_size(phys_addr_t base, phys_addr_t *size)
{
return *size = min(*size, (phys_addr_t)ULLONG_MAX - base);
}
static unsigned long __init_memblock memblock_addrs_overlap(phys_addr_t base1, phys_addr_t size1,
phys_addr_t base2, phys_addr_t size2)
{
return ((base1 < (base2 + size2)) && (base2 < (base1 + size1)));
}
static long __init_memblock memblock_overlaps_region(struct memblock_type *type,
phys_addr_t base, phys_addr_t size)
{
unsigned long i;
for (i = 0; i < type->cnt; i++) {
phys_addr_t rgnbase = type->regions[i].base;
phys_addr_t rgnsize = type->regions[i].size;
if (memblock_addrs_overlap(base, size, rgnbase, rgnsize))
break;
}
return (i < type->cnt) ? i : -1;
}
static phys_addr_t __init_memblock
__memblock_find_range_bottom_up(phys_addr_t start, phys_addr_t end,
phys_addr_t size, phys_addr_t align, int nid)
{
phys_addr_t this_start, this_end, cand;
u64 i;
for_each_free_mem_range(i, nid, &this_start, &this_end, NULL) {
this_start = clamp(this_start, start, end);
this_end = clamp(this_end, start, end);
cand = round_up(this_start, align);
if (cand < this_end && this_end - cand >= size)
return cand;
}
return 0;
}
static phys_addr_t __init_memblock
__memblock_find_range_top_down(phys_addr_t start, phys_addr_t end,
phys_addr_t size, phys_addr_t align, int nid)
{
phys_addr_t this_start, this_end, cand;
u64 i;
for_each_free_mem_range_reverse(i, nid, &this_start, &this_end, NULL) {
this_start = clamp(this_start, start, end);
this_end = clamp(this_end, start, end);
if (this_end < size)
continue;
cand = round_down(this_end - size, align);
if (cand >= this_start)
return cand;
}
return 0;
}
phys_addr_t __init_memblock memblock_find_in_range_node(phys_addr_t size,
phys_addr_t align, phys_addr_t start,
phys_addr_t end, int nid)
{
phys_addr_t kernel_end, ret;
if (end == MEMBLOCK_ALLOC_ACCESSIBLE)
end = memblock.current_limit;
start = max_t(phys_addr_t, start, PAGE_SIZE);
end = max(start, end);
kernel_end = __pa_symbol(_end);
if (memblock_bottom_up() && end > kernel_end) {
phys_addr_t bottom_up_start;
bottom_up_start = max(start, kernel_end);
ret = __memblock_find_range_bottom_up(bottom_up_start, end,
size, align, nid);
if (ret)
return ret;
WARN_ONCE(1, "memblock: bottom-up allocation failed, "
"memory hotunplug may be affected\n");
}
return __memblock_find_range_top_down(start, end, size, align, nid);
}
phys_addr_t __init_memblock memblock_find_in_range(phys_addr_t start,
phys_addr_t end, phys_addr_t size,
phys_addr_t align)
{
return memblock_find_in_range_node(size, align, start, end,
NUMA_NO_NODE);
}
static void __init_memblock memblock_remove_region(struct memblock_type *type, unsigned long r)
{
type->total_size -= type->regions[r].size;
memmove(&type->regions[r], &type->regions[r + 1],
(type->cnt - (r + 1)) * sizeof(type->regions[r]));
type->cnt--;
if (type->cnt == 0) {
WARN_ON(type->total_size != 0);
type->cnt = 1;
type->regions[0].base = 0;
type->regions[0].size = 0;
type->regions[0].flags = 0;
memblock_set_region_node(&type->regions[0], MAX_NUMNODES);
}
}
phys_addr_t __init_memblock get_allocated_memblock_reserved_regions_info(
phys_addr_t *addr)
{
if (memblock.reserved.regions == memblock_reserved_init_regions)
return 0;
*addr = __pa(memblock.reserved.regions);
return PAGE_ALIGN(sizeof(struct memblock_region) *
memblock.reserved.max);
}
phys_addr_t __init_memblock get_allocated_memblock_memory_regions_info(
phys_addr_t *addr)
{
if (memblock.memory.regions == memblock_memory_init_regions)
return 0;
*addr = __pa(memblock.memory.regions);
return PAGE_ALIGN(sizeof(struct memblock_region) *
memblock.memory.max);
}
static int __init_memblock memblock_double_array(struct memblock_type *type,
phys_addr_t new_area_start,
phys_addr_t new_area_size)
{
struct memblock_region *new_array, *old_array;
phys_addr_t old_alloc_size, new_alloc_size;
phys_addr_t old_size, new_size, addr;
int use_slab = slab_is_available();
int *in_slab;
if (!memblock_can_resize)
return -1;
old_size = type->max * sizeof(struct memblock_region);
new_size = old_size << 1;
old_alloc_size = PAGE_ALIGN(old_size);
new_alloc_size = PAGE_ALIGN(new_size);
if (type == &memblock.memory)
in_slab = &memblock_memory_in_slab;
else
in_slab = &memblock_reserved_in_slab;
if (use_slab) {
new_array = kmalloc(new_size, GFP_KERNEL);
addr = new_array ? __pa(new_array) : 0;
} else {
if (type != &memblock.reserved)
new_area_start = new_area_size = 0;
addr = memblock_find_in_range(new_area_start + new_area_size,
memblock.current_limit,
new_alloc_size, PAGE_SIZE);
if (!addr && new_area_size)
addr = memblock_find_in_range(0,
min(new_area_start, memblock.current_limit),
new_alloc_size, PAGE_SIZE);
new_array = addr ? __va(addr) : NULL;
}
if (!addr) {
pr_err("memblock: Failed to double %s array from %ld to %ld entries !\n",
memblock_type_name(type), type->max, type->max * 2);
return -1;
}
memblock_dbg("memblock: %s is doubled to %ld at [%#010llx-%#010llx]",
memblock_type_name(type), type->max * 2, (u64)addr,
(u64)addr + new_size - 1);
memcpy(new_array, type->regions, old_size);
memset(new_array + type->max, 0, old_size);
old_array = type->regions;
type->regions = new_array;
type->max <<= 1;
if (*in_slab)
kfree(old_array);
else if (old_array != memblock_memory_init_regions &&
old_array != memblock_reserved_init_regions)
memblock_free(__pa(old_array), old_alloc_size);
if (!use_slab)
BUG_ON(memblock_reserve(addr, new_alloc_size));
*in_slab = use_slab;
return 0;
}
static void __init_memblock memblock_merge_regions(struct memblock_type *type)
{
int i = 0;
while (i < type->cnt - 1) {
struct memblock_region *this = &type->regions[i];
struct memblock_region *next = &type->regions[i + 1];
if (this->base + this->size != next->base ||
memblock_get_region_node(this) !=
memblock_get_region_node(next) ||
this->flags != next->flags) {
BUG_ON(this->base + this->size > next->base);
i++;
continue;
}
this->size += next->size;
memmove(next, next + 1, (type->cnt - (i + 2)) * sizeof(*next));
type->cnt--;
}
}
static void __init_memblock memblock_insert_region(struct memblock_type *type,
int idx, phys_addr_t base,
phys_addr_t size,
int nid, unsigned long flags)
{
struct memblock_region *rgn = &type->regions[idx];
BUG_ON(type->cnt >= type->max);
memmove(rgn + 1, rgn, (type->cnt - idx) * sizeof(*rgn));
rgn->base = base;
rgn->size = size;
rgn->flags = flags;
memblock_set_region_node(rgn, nid);
type->cnt++;
type->total_size += size;
}
int __init_memblock memblock_add_range(struct memblock_type *type,
phys_addr_t base, phys_addr_t size,
int nid, unsigned long flags)
{
bool insert = false;
phys_addr_t obase = base;
phys_addr_t end = base + memblock_cap_size(base, &size);
int i, nr_new;
if (!size)
return 0;
if (type->regions[0].size == 0) {
WARN_ON(type->cnt != 1 || type->total_size);
type->regions[0].base = base;
type->regions[0].size = size;
type->regions[0].flags = flags;
memblock_set_region_node(&type->regions[0], nid);
type->total_size = size;
return 0;
}
repeat:
base = obase;
nr_new = 0;
for (i = 0; i < type->cnt; i++) {
struct memblock_region *rgn = &type->regions[i];
phys_addr_t rbase = rgn->base;
phys_addr_t rend = rbase + rgn->size;
if (rbase >= end)
break;
if (rend <= base)
continue;
if (rbase > base) {
nr_new++;
if (insert)
memblock_insert_region(type, i++, base,
rbase - base, nid,
flags);
}
base = min(rend, end);
}
if (base < end) {
nr_new++;
if (insert)
memblock_insert_region(type, i, base, end - base,
nid, flags);
}
if (!insert) {
while (type->cnt + nr_new > type->max)
if (memblock_double_array(type, obase, size) < 0)
return -ENOMEM;
insert = true;
goto repeat;
} else {
memblock_merge_regions(type);
return 0;
}
}
int __init_memblock memblock_add_node(phys_addr_t base, phys_addr_t size,
int nid)
{
return memblock_add_range(&memblock.memory, base, size, nid, 0);
}
int __init_memblock memblock_add(phys_addr_t base, phys_addr_t size)
{
return memblock_add_range(&memblock.memory, base, size,
MAX_NUMNODES, 0);
}
static int __init_memblock memblock_isolate_range(struct memblock_type *type,
phys_addr_t base, phys_addr_t size,
int *start_rgn, int *end_rgn)
{
phys_addr_t end = base + memblock_cap_size(base, &size);
int i;
*start_rgn = *end_rgn = 0;
if (!size)
return 0;
while (type->cnt + 2 > type->max)
if (memblock_double_array(type, base, size) < 0)
return -ENOMEM;
for (i = 0; i < type->cnt; i++) {
struct memblock_region *rgn = &type->regions[i];
phys_addr_t rbase = rgn->base;
phys_addr_t rend = rbase + rgn->size;
if (rbase >= end)
break;
if (rend <= base)
continue;
if (rbase < base) {
rgn->base = base;
rgn->size -= base - rbase;
type->total_size -= base - rbase;
memblock_insert_region(type, i, rbase, base - rbase,
memblock_get_region_node(rgn),
rgn->flags);
} else if (rend > end) {
rgn->base = end;
rgn->size -= end - rbase;
type->total_size -= end - rbase;
memblock_insert_region(type, i--, rbase, end - rbase,
memblock_get_region_node(rgn),
rgn->flags);
} else {
if (!*end_rgn)
*start_rgn = i;
*end_rgn = i + 1;
}
}
return 0;
}
int __init_memblock memblock_remove_range(struct memblock_type *type,
phys_addr_t base, phys_addr_t size)
{
int start_rgn, end_rgn;
int i, ret;
ret = memblock_isolate_range(type, base, size, &start_rgn, &end_rgn);
if (ret)
return ret;
for (i = end_rgn - 1; i >= start_rgn; i--)
memblock_remove_region(type, i);
return 0;
}
int __init_memblock memblock_remove(phys_addr_t base, phys_addr_t size)
{
return memblock_remove_range(&memblock.memory, base, size);
}
int __init_memblock memblock_free(phys_addr_t base, phys_addr_t size)
{
memblock_dbg(" memblock_free: [%#016llx-%#016llx] %pF\n",
(unsigned long long)base,
(unsigned long long)base + size - 1,
(void *)_RET_IP_);
kmemleak_free_part(__va(base), size);
return memblock_remove_range(&memblock.reserved, base, size);
}
static int __init_memblock memblock_reserve_region(phys_addr_t base,
phys_addr_t size,
int nid,
unsigned long flags)
{
struct memblock_type *_rgn = &memblock.reserved;
memblock_dbg("memblock_reserve: [%#016llx-%#016llx] flags %#02lx %pF\n",
(unsigned long long)base,
(unsigned long long)base + size - 1,
flags, (void *)_RET_IP_);
return memblock_add_range(_rgn, base, size, nid, flags);
}
int __init_memblock memblock_reserve(phys_addr_t base, phys_addr_t size)
{
return memblock_reserve_region(base, size, MAX_NUMNODES, 0);
}
static int __init_memblock memblock_setclr_flag(phys_addr_t base,
phys_addr_t size, int set, int flag)
{
struct memblock_type *type = &memblock.memory;
int i, ret, start_rgn, end_rgn;
ret = memblock_isolate_range(type, base, size, &start_rgn, &end_rgn);
if (ret)
return ret;
for (i = start_rgn; i < end_rgn; i++)
if (set)
memblock_set_region_flags(&type->regions[i], flag);
else
memblock_clear_region_flags(&type->regions[i], flag);
memblock_merge_regions(type);
return 0;
}
int __init_memblock memblock_mark_hotplug(phys_addr_t base, phys_addr_t size)
{
return memblock_setclr_flag(base, size, 1, MEMBLOCK_HOTPLUG);
}
int __init_memblock memblock_clear_hotplug(phys_addr_t base, phys_addr_t size)
{
return memblock_setclr_flag(base, size, 0, MEMBLOCK_HOTPLUG);
}
void __init_memblock __next_mem_range(u64 *idx, int nid,
struct memblock_type *type_a,
struct memblock_type *type_b,
phys_addr_t *out_start,
phys_addr_t *out_end, int *out_nid)
{
int idx_a = *idx & 0xffffffff;
int idx_b = *idx >> 32;
if (WARN_ONCE(nid == MAX_NUMNODES,
"Usage of MAX_NUMNODES is deprecated. Use NUMA_NO_NODE instead\n"))
nid = NUMA_NO_NODE;
for (; idx_a < type_a->cnt; idx_a++) {
struct memblock_region *m = &type_a->regions[idx_a];
phys_addr_t m_start = m->base;
phys_addr_t m_end = m->base + m->size;
int m_nid = memblock_get_region_node(m);
if (nid != NUMA_NO_NODE && nid != m_nid)
continue;
if (movable_node_is_enabled() && memblock_is_hotpluggable(m))
continue;
if (!type_b) {
if (out_start)
*out_start = m_start;
if (out_end)
*out_end = m_end;
if (out_nid)
*out_nid = m_nid;
idx_a++;
*idx = (u32)idx_a | (u64)idx_b << 32;
return;
}
for (; idx_b < type_b->cnt + 1; idx_b++) {
struct memblock_region *r;
phys_addr_t r_start;
phys_addr_t r_end;
r = &type_b->regions[idx_b];
r_start = idx_b ? r[-1].base + r[-1].size : 0;
r_end = idx_b < type_b->cnt ?
r->base : ULLONG_MAX;
if (r_start >= m_end)
break;
if (m_start < r_end) {
if (out_start)
*out_start =
max(m_start, r_start);
if (out_end)
*out_end = min(m_end, r_end);
if (out_nid)
*out_nid = m_nid;
if (m_end <= r_end)
idx_a++;
else
idx_b++;
*idx = (u32)idx_a | (u64)idx_b << 32;
return;
}
}
}
*idx = ULLONG_MAX;
}
void __init_memblock __next_mem_range_rev(u64 *idx, int nid,
struct memblock_type *type_a,
struct memblock_type *type_b,
phys_addr_t *out_start,
phys_addr_t *out_end, int *out_nid)
{
int idx_a = *idx & 0xffffffff;
int idx_b = *idx >> 32;
if (WARN_ONCE(nid == MAX_NUMNODES, "Usage of MAX_NUMNODES is deprecated. Use NUMA_NO_NODE instead\n"))
nid = NUMA_NO_NODE;
if (*idx == (u64)ULLONG_MAX) {
idx_a = type_a->cnt - 1;
idx_b = type_b->cnt;
}
for (; idx_a >= 0; idx_a--) {
struct memblock_region *m = &type_a->regions[idx_a];
phys_addr_t m_start = m->base;
phys_addr_t m_end = m->base + m->size;
int m_nid = memblock_get_region_node(m);
if (nid != NUMA_NO_NODE && nid != m_nid)
continue;
if (movable_node_is_enabled() && memblock_is_hotpluggable(m))
continue;
if (!type_b) {
if (out_start)
*out_start = m_start;
if (out_end)
*out_end = m_end;
if (out_nid)
*out_nid = m_nid;
idx_a++;
*idx = (u32)idx_a | (u64)idx_b << 32;
return;
}
for (; idx_b >= 0; idx_b--) {
struct memblock_region *r;
phys_addr_t r_start;
phys_addr_t r_end;
r = &type_b->regions[idx_b];
r_start = idx_b ? r[-1].base + r[-1].size : 0;
r_end = idx_b < type_b->cnt ?
r->base : ULLONG_MAX;
if (r_end <= m_start)
break;
if (m_end > r_start) {
if (out_start)
*out_start = max(m_start, r_start);
if (out_end)
*out_end = min(m_end, r_end);
if (out_nid)
*out_nid = m_nid;
if (m_start >= r_start)
idx_a--;
else
idx_b--;
*idx = (u32)idx_a | (u64)idx_b << 32;
return;
}
}
}
*idx = ULLONG_MAX;
}
void __init_memblock __next_mem_pfn_range(int *idx, int nid,
unsigned long *out_start_pfn,
unsigned long *out_end_pfn, int *out_nid)
{
struct memblock_type *type = &memblock.memory;
struct memblock_region *r;
while (++*idx < type->cnt) {
r = &type->regions[*idx];
if (PFN_UP(r->base) >= PFN_DOWN(r->base + r->size))
continue;
if (nid == MAX_NUMNODES || nid == r->nid)
break;
}
if (*idx >= type->cnt) {
*idx = -1;
return;
}
if (out_start_pfn)
*out_start_pfn = PFN_UP(r->base);
if (out_end_pfn)
*out_end_pfn = PFN_DOWN(r->base + r->size);
if (out_nid)
*out_nid = r->nid;
}
int __init_memblock memblock_set_node(phys_addr_t base, phys_addr_t size,
struct memblock_type *type, int nid)
{
int start_rgn, end_rgn;
int i, ret;
ret = memblock_isolate_range(type, base, size, &start_rgn, &end_rgn);
if (ret)
return ret;
for (i = start_rgn; i < end_rgn; i++)
memblock_set_region_node(&type->regions[i], nid);
memblock_merge_regions(type);
return 0;
}
static phys_addr_t __init memblock_alloc_range_nid(phys_addr_t size,
phys_addr_t align, phys_addr_t start,
phys_addr_t end, int nid)
{
phys_addr_t found;
if (!align)
align = SMP_CACHE_BYTES;
found = memblock_find_in_range_node(size, align, start, end, nid);
if (found && !memblock_reserve(found, size)) {
kmemleak_alloc(__va(found), size, 0, 0);
return found;
}
return 0;
}
phys_addr_t __init memblock_alloc_range(phys_addr_t size, phys_addr_t align,
phys_addr_t start, phys_addr_t end)
{
return memblock_alloc_range_nid(size, align, start, end, NUMA_NO_NODE);
}
static phys_addr_t __init memblock_alloc_base_nid(phys_addr_t size,
phys_addr_t align, phys_addr_t max_addr,
int nid)
{
return memblock_alloc_range_nid(size, align, 0, max_addr, nid);
}
phys_addr_t __init memblock_alloc_nid(phys_addr_t size, phys_addr_t align, int nid)
{
return memblock_alloc_base_nid(size, align, MEMBLOCK_ALLOC_ACCESSIBLE, nid);
}
phys_addr_t __init __memblock_alloc_base(phys_addr_t size, phys_addr_t align, phys_addr_t max_addr)
{
return memblock_alloc_base_nid(size, align, max_addr, NUMA_NO_NODE);
}
phys_addr_t __init memblock_alloc_base(phys_addr_t size, phys_addr_t align, phys_addr_t max_addr)
{
phys_addr_t alloc;
alloc = __memblock_alloc_base(size, align, max_addr);
if (alloc == 0)
panic("ERROR: Failed to allocate 0x%llx bytes below 0x%llx.\n",
(unsigned long long) size, (unsigned long long) max_addr);
return alloc;
}
phys_addr_t __init memblock_alloc(phys_addr_t size, phys_addr_t align)
{
return memblock_alloc_base(size, align, MEMBLOCK_ALLOC_ACCESSIBLE);
}
phys_addr_t __init memblock_alloc_try_nid(phys_addr_t size, phys_addr_t align, int nid)
{
phys_addr_t res = memblock_alloc_nid(size, align, nid);
if (res)
return res;
return memblock_alloc_base(size, align, MEMBLOCK_ALLOC_ACCESSIBLE);
}
static void * __init memblock_virt_alloc_internal(
phys_addr_t size, phys_addr_t align,
phys_addr_t min_addr, phys_addr_t max_addr,
int nid)
{
phys_addr_t alloc;
void *ptr;
if (WARN_ONCE(nid == MAX_NUMNODES, "Usage of MAX_NUMNODES is deprecated. Use NUMA_NO_NODE instead\n"))
nid = NUMA_NO_NODE;
if (WARN_ON_ONCE(slab_is_available()))
return kzalloc_node(size, GFP_NOWAIT, nid);
if (!align)
align = SMP_CACHE_BYTES;
if (max_addr > memblock.current_limit)
max_addr = memblock.current_limit;
again:
alloc = memblock_find_in_range_node(size, align, min_addr, max_addr,
nid);
if (alloc)
goto done;
if (nid != NUMA_NO_NODE) {
alloc = memblock_find_in_range_node(size, align, min_addr,
max_addr, NUMA_NO_NODE);
if (alloc)
goto done;
}
if (min_addr) {
min_addr = 0;
goto again;
} else {
goto error;
}
done:
memblock_reserve(alloc, size);
ptr = phys_to_virt(alloc);
memset(ptr, 0, size);
kmemleak_alloc(ptr, size, 0, 0);
return ptr;
error:
return NULL;
}
void * __init memblock_virt_alloc_try_nid_nopanic(
phys_addr_t size, phys_addr_t align,
phys_addr_t min_addr, phys_addr_t max_addr,
int nid)
{
memblock_dbg("%s: %llu bytes align=0x%llx nid=%d from=0x%llx max_addr=0x%llx %pF\n",
__func__, (u64)size, (u64)align, nid, (u64)min_addr,
(u64)max_addr, (void *)_RET_IP_);
return memblock_virt_alloc_internal(size, align, min_addr,
max_addr, nid);
}
void * __init memblock_virt_alloc_try_nid(
phys_addr_t size, phys_addr_t align,
phys_addr_t min_addr, phys_addr_t max_addr,
int nid)
{
void *ptr;
memblock_dbg("%s: %llu bytes align=0x%llx nid=%d from=0x%llx max_addr=0x%llx %pF\n",
__func__, (u64)size, (u64)align, nid, (u64)min_addr,
(u64)max_addr, (void *)_RET_IP_);
ptr = memblock_virt_alloc_internal(size, align,
min_addr, max_addr, nid);
if (ptr)
return ptr;
panic("%s: Failed to allocate %llu bytes align=0x%llx nid=%d from=0x%llx max_addr=0x%llx\n",
__func__, (u64)size, (u64)align, nid, (u64)min_addr,
(u64)max_addr);
return NULL;
}
void __init __memblock_free_early(phys_addr_t base, phys_addr_t size)
{
memblock_dbg("%s: [%#016llx-%#016llx] %pF\n",
__func__, (u64)base, (u64)base + size - 1,
(void *)_RET_IP_);
kmemleak_free_part(__va(base), size);
memblock_remove_range(&memblock.reserved, base, size);
}
void __init __memblock_free_late(phys_addr_t base, phys_addr_t size)
{
u64 cursor, end;
memblock_dbg("%s: [%#016llx-%#016llx] %pF\n",
__func__, (u64)base, (u64)base + size - 1,
(void *)_RET_IP_);
kmemleak_free_part(__va(base), size);
cursor = PFN_UP(base);
end = PFN_DOWN(base + size);
for (; cursor < end; cursor++) {
__free_pages_bootmem(pfn_to_page(cursor), 0);
totalram_pages++;
}
}
phys_addr_t __init memblock_phys_mem_size(void)
{
return memblock.memory.total_size;
}
phys_addr_t __init memblock_mem_size(unsigned long limit_pfn)
{
unsigned long pages = 0;
struct memblock_region *r;
unsigned long start_pfn, end_pfn;
for_each_memblock(memory, r) {
start_pfn = memblock_region_memory_base_pfn(r);
end_pfn = memblock_region_memory_end_pfn(r);
start_pfn = min_t(unsigned long, start_pfn, limit_pfn);
end_pfn = min_t(unsigned long, end_pfn, limit_pfn);
pages += end_pfn - start_pfn;
}
return PFN_PHYS(pages);
}
phys_addr_t __init_memblock memblock_start_of_DRAM(void)
{
return memblock.memory.regions[0].base;
}
phys_addr_t __init_memblock memblock_end_of_DRAM(void)
{
int idx = memblock.memory.cnt - 1;
return (memblock.memory.regions[idx].base + memblock.memory.regions[idx].size);
}
void __init memblock_enforce_memory_limit(phys_addr_t limit)
{
phys_addr_t max_addr = (phys_addr_t)ULLONG_MAX;
struct memblock_region *r;
if (!limit)
return;
for_each_memblock(memory, r) {
if (limit <= r->size) {
max_addr = r->base + limit;
break;
}
limit -= r->size;
}
memblock_remove_range(&memblock.memory, max_addr,
(phys_addr_t)ULLONG_MAX);
memblock_remove_range(&memblock.reserved, max_addr,
(phys_addr_t)ULLONG_MAX);
}
static int __init_memblock memblock_search(struct memblock_type *type, phys_addr_t addr)
{
unsigned int left = 0, right = type->cnt;
do {
unsigned int mid = (right + left) / 2;
if (addr < type->regions[mid].base)
right = mid;
else if (addr >= (type->regions[mid].base +
type->regions[mid].size))
left = mid + 1;
else
return mid;
} while (left < right);
return -1;
}
int __init memblock_is_reserved(phys_addr_t addr)
{
return memblock_search(&memblock.reserved, addr) != -1;
}
int __init_memblock memblock_is_memory(phys_addr_t addr)
{
return memblock_search(&memblock.memory, addr) != -1;
}
int __init_memblock memblock_search_pfn_nid(unsigned long pfn,
unsigned long *start_pfn, unsigned long *end_pfn)
{
struct memblock_type *type = &memblock.memory;
int mid = memblock_search(type, PFN_PHYS(pfn));
if (mid == -1)
return -1;
*start_pfn = PFN_DOWN(type->regions[mid].base);
*end_pfn = PFN_DOWN(type->regions[mid].base + type->regions[mid].size);
return type->regions[mid].nid;
}
int __init_memblock memblock_is_region_memory(phys_addr_t base, phys_addr_t size)
{
int idx = memblock_search(&memblock.memory, base);
phys_addr_t end = base + memblock_cap_size(base, &size);
if (idx == -1)
return 0;
return memblock.memory.regions[idx].base <= base &&
(memblock.memory.regions[idx].base +
memblock.memory.regions[idx].size) >= end;
}
int __init_memblock memblock_is_region_reserved(phys_addr_t base, phys_addr_t size)
{
memblock_cap_size(base, &size);
return memblock_overlaps_region(&memblock.reserved, base, size) >= 0;
}
void __init_memblock memblock_trim_memory(phys_addr_t align)
{
phys_addr_t start, end, orig_start, orig_end;
struct memblock_region *r;
for_each_memblock(memory, r) {
orig_start = r->base;
orig_end = r->base + r->size;
start = round_up(orig_start, align);
end = round_down(orig_end, align);
if (start == orig_start && end == orig_end)
continue;
if (start < end) {
r->base = start;
r->size = end - start;
} else {
memblock_remove_region(&memblock.memory,
r - memblock.memory.regions);
r--;
}
}
}
void __init_memblock memblock_set_current_limit(phys_addr_t limit)
{
memblock.current_limit = limit;
}
phys_addr_t __init_memblock memblock_get_current_limit(void)
{
return memblock.current_limit;
}
static void __init_memblock memblock_dump(struct memblock_type *type, char *name)
{
unsigned long long base, size;
unsigned long flags;
int i;
pr_info(" %s.cnt = 0x%lx\n", name, type->cnt);
for (i = 0; i < type->cnt; i++) {
struct memblock_region *rgn = &type->regions[i];
char nid_buf[32] = "";
base = rgn->base;
size = rgn->size;
flags = rgn->flags;
#ifdef CONFIG_HAVE_MEMBLOCK_NODE_MAP
if (memblock_get_region_node(rgn) != MAX_NUMNODES)
snprintf(nid_buf, sizeof(nid_buf), " on node %d",
memblock_get_region_node(rgn));
#endif
pr_info(" %s[%#x]\t[%#016llx-%#016llx], %#llx bytes%s flags: %#lx\n",
name, i, base, base + size - 1, size, nid_buf, flags);
}
}
void __init_memblock __memblock_dump_all(void)
{
pr_info("MEMBLOCK configuration:\n");
pr_info(" memory size = %#llx reserved size = %#llx\n",
(unsigned long long)memblock.memory.total_size,
(unsigned long long)memblock.reserved.total_size);
memblock_dump(&memblock.memory, "memory");
memblock_dump(&memblock.reserved, "reserved");
}
void __init memblock_allow_resize(void)
{
memblock_can_resize = 1;
}
static int __init early_memblock(char *p)
{
if (p && strstr(p, "debug"))
memblock_debug = 1;
return 0;
}
static int memblock_debug_show(struct seq_file *m, void *private)
{
struct memblock_type *type = m->private;
struct memblock_region *reg;
int i;
for (i = 0; i < type->cnt; i++) {
reg = &type->regions[i];
seq_printf(m, "%4d: ", i);
if (sizeof(phys_addr_t) == 4)
seq_printf(m, "0x%08lx..0x%08lx\n",
(unsigned long)reg->base,
(unsigned long)(reg->base + reg->size - 1));
else
seq_printf(m, "0x%016llx..0x%016llx\n",
(unsigned long long)reg->base,
(unsigned long long)(reg->base + reg->size - 1));
}
return 0;
}
static int memblock_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, memblock_debug_show, inode->i_private);
}
static int __init memblock_init_debugfs(void)
{
struct dentry *root = debugfs_create_dir("memblock", NULL);
if (!root)
return -ENXIO;
debugfs_create_file("memory", S_IRUGO, root, &memblock.memory, &memblock_debug_fops);
debugfs_create_file("reserved", S_IRUGO, root, &memblock.reserved, &memblock_debug_fops);
#ifdef CONFIG_HAVE_MEMBLOCK_PHYS_MAP
debugfs_create_file("physmem", S_IRUGO, root, &memblock.physmem, &memblock_debug_fops);
#endif
return 0;
}
