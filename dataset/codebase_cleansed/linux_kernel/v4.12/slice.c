static void slice_print_mask(const char *label, struct slice_mask mask)
{
if (!_slice_debug)
return;
pr_devel("%s low_slice: %*pbl\n", label, (int)SLICE_NUM_LOW, &mask.low_slices);
pr_devel("%s high_slice: %*pbl\n", label, (int)SLICE_NUM_HIGH, mask.high_slices);
}
static void slice_print_mask(const char *label, struct slice_mask mask) {}
static void slice_range_to_mask(unsigned long start, unsigned long len,
struct slice_mask *ret)
{
unsigned long end = start + len - 1;
ret->low_slices = 0;
bitmap_zero(ret->high_slices, SLICE_NUM_HIGH);
if (start < SLICE_LOW_TOP) {
unsigned long mend = min(end, (SLICE_LOW_TOP - 1));
ret->low_slices = (1u << (GET_LOW_SLICE_INDEX(mend) + 1))
- (1u << GET_LOW_SLICE_INDEX(start));
}
if ((start + len) > SLICE_LOW_TOP) {
unsigned long start_index = GET_HIGH_SLICE_INDEX(start);
unsigned long align_end = ALIGN(end, (1UL << SLICE_HIGH_SHIFT));
unsigned long count = GET_HIGH_SLICE_INDEX(align_end) - start_index;
bitmap_set(ret->high_slices, start_index, count);
}
}
static int slice_area_is_free(struct mm_struct *mm, unsigned long addr,
unsigned long len)
{
struct vm_area_struct *vma;
if ((mm->task_size - len) < addr)
return 0;
vma = find_vma(mm, addr);
return (!vma || (addr + len) <= vm_start_gap(vma));
}
static int slice_low_has_vma(struct mm_struct *mm, unsigned long slice)
{
return !slice_area_is_free(mm, slice << SLICE_LOW_SHIFT,
1ul << SLICE_LOW_SHIFT);
}
static int slice_high_has_vma(struct mm_struct *mm, unsigned long slice)
{
unsigned long start = slice << SLICE_HIGH_SHIFT;
unsigned long end = start + (1ul << SLICE_HIGH_SHIFT);
if (start == 0)
start = SLICE_LOW_TOP;
return !slice_area_is_free(mm, start, end - start);
}
static void slice_mask_for_free(struct mm_struct *mm, struct slice_mask *ret)
{
unsigned long i;
ret->low_slices = 0;
bitmap_zero(ret->high_slices, SLICE_NUM_HIGH);
for (i = 0; i < SLICE_NUM_LOW; i++)
if (!slice_low_has_vma(mm, i))
ret->low_slices |= 1u << i;
if (mm->task_size <= SLICE_LOW_TOP)
return;
for (i = 0; i < GET_HIGH_SLICE_INDEX(mm->context.addr_limit); i++)
if (!slice_high_has_vma(mm, i))
__set_bit(i, ret->high_slices);
}
static void slice_mask_for_size(struct mm_struct *mm, int psize, struct slice_mask *ret)
{
unsigned char *hpsizes;
int index, mask_index;
unsigned long i;
u64 lpsizes;
ret->low_slices = 0;
bitmap_zero(ret->high_slices, SLICE_NUM_HIGH);
lpsizes = mm->context.low_slices_psize;
for (i = 0; i < SLICE_NUM_LOW; i++)
if (((lpsizes >> (i * 4)) & 0xf) == psize)
ret->low_slices |= 1u << i;
hpsizes = mm->context.high_slices_psize;
for (i = 0; i < GET_HIGH_SLICE_INDEX(mm->context.addr_limit); i++) {
mask_index = i & 0x1;
index = i >> 1;
if (((hpsizes[index] >> (mask_index * 4)) & 0xf) == psize)
__set_bit(i, ret->high_slices);
}
}
static int slice_check_fit(struct mm_struct *mm,
struct slice_mask mask, struct slice_mask available)
{
DECLARE_BITMAP(result, SLICE_NUM_HIGH);
unsigned long slice_count = GET_HIGH_SLICE_INDEX(mm->context.addr_limit);
bitmap_and(result, mask.high_slices,
available.high_slices, slice_count);
return (mask.low_slices & available.low_slices) == mask.low_slices &&
bitmap_equal(result, mask.high_slices, slice_count);
}
static void slice_flush_segments(void *parm)
{
struct mm_struct *mm = parm;
unsigned long flags;
if (mm != current->active_mm)
return;
copy_mm_to_paca(current->active_mm);
local_irq_save(flags);
slb_flush_and_rebolt();
local_irq_restore(flags);
}
static void slice_convert(struct mm_struct *mm, struct slice_mask mask, int psize)
{
int index, mask_index;
unsigned char *hpsizes;
u64 lpsizes;
unsigned long i, flags;
slice_dbg("slice_convert(mm=%p, psize=%d)\n", mm, psize);
slice_print_mask(" mask", mask);
spin_lock_irqsave(&slice_convert_lock, flags);
lpsizes = mm->context.low_slices_psize;
for (i = 0; i < SLICE_NUM_LOW; i++)
if (mask.low_slices & (1u << i))
lpsizes = (lpsizes & ~(0xful << (i * 4))) |
(((unsigned long)psize) << (i * 4));
mm->context.low_slices_psize = lpsizes;
hpsizes = mm->context.high_slices_psize;
for (i = 0; i < GET_HIGH_SLICE_INDEX(mm->context.addr_limit); i++) {
mask_index = i & 0x1;
index = i >> 1;
if (test_bit(i, mask.high_slices))
hpsizes[index] = (hpsizes[index] &
~(0xf << (mask_index * 4))) |
(((unsigned long)psize) << (mask_index * 4));
}
slice_dbg(" lsps=%lx, hsps=%lx\n",
(unsigned long)mm->context.low_slices_psize,
(unsigned long)mm->context.high_slices_psize);
spin_unlock_irqrestore(&slice_convert_lock, flags);
copro_flush_all_slbs(mm);
}
static bool slice_scan_available(unsigned long addr,
struct slice_mask available,
int end,
unsigned long *boundary_addr)
{
unsigned long slice;
if (addr < SLICE_LOW_TOP) {
slice = GET_LOW_SLICE_INDEX(addr);
*boundary_addr = (slice + end) << SLICE_LOW_SHIFT;
return !!(available.low_slices & (1u << slice));
} else {
slice = GET_HIGH_SLICE_INDEX(addr);
*boundary_addr = (slice + end) ?
((slice + end) << SLICE_HIGH_SHIFT) : SLICE_LOW_TOP;
return !!test_bit(slice, available.high_slices);
}
}
static unsigned long slice_find_area_bottomup(struct mm_struct *mm,
unsigned long len,
struct slice_mask available,
int psize, unsigned long high_limit)
{
int pshift = max_t(int, mmu_psize_defs[psize].shift, PAGE_SHIFT);
unsigned long addr, found, next_end;
struct vm_unmapped_area_info info;
info.flags = 0;
info.length = len;
info.align_mask = PAGE_MASK & ((1ul << pshift) - 1);
info.align_offset = 0;
addr = TASK_UNMAPPED_BASE;
while (addr < high_limit) {
info.low_limit = addr;
if (!slice_scan_available(addr, available, 1, &addr))
continue;
next_slice:
if (addr >= high_limit)
addr = high_limit;
else if (slice_scan_available(addr, available, 1, &next_end)) {
addr = next_end;
goto next_slice;
}
info.high_limit = addr;
found = vm_unmapped_area(&info);
if (!(found & ~PAGE_MASK))
return found;
}
return -ENOMEM;
}
static unsigned long slice_find_area_topdown(struct mm_struct *mm,
unsigned long len,
struct slice_mask available,
int psize, unsigned long high_limit)
{
int pshift = max_t(int, mmu_psize_defs[psize].shift, PAGE_SHIFT);
unsigned long addr, found, prev;
struct vm_unmapped_area_info info;
info.flags = VM_UNMAPPED_AREA_TOPDOWN;
info.length = len;
info.align_mask = PAGE_MASK & ((1ul << pshift) - 1);
info.align_offset = 0;
addr = mm->mmap_base;
if (high_limit > DEFAULT_MAP_WINDOW)
addr += mm->context.addr_limit - DEFAULT_MAP_WINDOW;
while (addr > PAGE_SIZE) {
info.high_limit = addr;
if (!slice_scan_available(addr - 1, available, 0, &addr))
continue;
prev_slice:
if (addr < PAGE_SIZE)
addr = PAGE_SIZE;
else if (slice_scan_available(addr - 1, available, 0, &prev)) {
addr = prev;
goto prev_slice;
}
info.low_limit = addr;
found = vm_unmapped_area(&info);
if (!(found & ~PAGE_MASK))
return found;
}
return slice_find_area_bottomup(mm, len, available, psize, high_limit);
}
static unsigned long slice_find_area(struct mm_struct *mm, unsigned long len,
struct slice_mask mask, int psize,
int topdown, unsigned long high_limit)
{
if (topdown)
return slice_find_area_topdown(mm, len, mask, psize, high_limit);
else
return slice_find_area_bottomup(mm, len, mask, psize, high_limit);
}
static inline void slice_or_mask(struct slice_mask *dst, struct slice_mask *src)
{
DECLARE_BITMAP(result, SLICE_NUM_HIGH);
dst->low_slices |= src->low_slices;
bitmap_or(result, dst->high_slices, src->high_slices, SLICE_NUM_HIGH);
bitmap_copy(dst->high_slices, result, SLICE_NUM_HIGH);
}
static inline void slice_andnot_mask(struct slice_mask *dst, struct slice_mask *src)
{
DECLARE_BITMAP(result, SLICE_NUM_HIGH);
dst->low_slices &= ~src->low_slices;
bitmap_andnot(result, dst->high_slices, src->high_slices, SLICE_NUM_HIGH);
bitmap_copy(dst->high_slices, result, SLICE_NUM_HIGH);
}
unsigned long slice_get_unmapped_area(unsigned long addr, unsigned long len,
unsigned long flags, unsigned int psize,
int topdown)
{
struct slice_mask mask;
struct slice_mask good_mask;
struct slice_mask potential_mask;
struct slice_mask compat_mask;
int fixed = (flags & MAP_FIXED);
int pshift = max_t(int, mmu_psize_defs[psize].shift, PAGE_SHIFT);
struct mm_struct *mm = current->mm;
unsigned long newaddr;
unsigned long high_limit;
if (unlikely(addr > mm->context.addr_limit &&
mm->context.addr_limit != TASK_SIZE)) {
mm->context.addr_limit = TASK_SIZE;
on_each_cpu(slice_flush_segments, mm, 1);
}
if (addr > DEFAULT_MAP_WINDOW)
high_limit = mm->context.addr_limit;
else
high_limit = DEFAULT_MAP_WINDOW;
mask.low_slices = 0;
bitmap_zero(mask.high_slices, SLICE_NUM_HIGH);
;
potential_mask.low_slices = 0;
bitmap_zero(potential_mask.high_slices, SLICE_NUM_HIGH);
compat_mask.low_slices = 0;
bitmap_zero(compat_mask.high_slices, SLICE_NUM_HIGH);
BUG_ON(mm->task_size == 0);
VM_BUG_ON(radix_enabled());
slice_dbg("slice_get_unmapped_area(mm=%p, psize=%d...\n", mm, psize);
slice_dbg(" addr=%lx, len=%lx, flags=%lx, topdown=%d\n",
addr, len, flags, topdown);
if (len > mm->task_size)
return -ENOMEM;
if (len & ((1ul << pshift) - 1))
return -EINVAL;
if (fixed && (addr & ((1ul << pshift) - 1)))
return -EINVAL;
if (fixed && addr > (mm->task_size - len))
return -ENOMEM;
if (!fixed && addr) {
addr = _ALIGN_UP(addr, 1ul << pshift);
slice_dbg(" aligned addr=%lx\n", addr);
if (addr > mm->task_size - len ||
!slice_area_is_free(mm, addr, len))
addr = 0;
}
slice_mask_for_size(mm, psize, &good_mask);
slice_print_mask(" good_mask", good_mask);
#ifdef CONFIG_PPC_64K_PAGES
if (psize == MMU_PAGE_64K) {
slice_mask_for_size(mm, MMU_PAGE_4K, &compat_mask);
if (fixed)
slice_or_mask(&good_mask, &compat_mask);
}
#endif
if (addr != 0 || fixed) {
slice_range_to_mask(addr, len, &mask);
slice_print_mask(" mask", mask);
if (slice_check_fit(mm, mask, good_mask)) {
slice_dbg(" fits good !\n");
return addr;
}
} else {
newaddr = slice_find_area(mm, len, good_mask,
psize, topdown, high_limit);
if (newaddr != -ENOMEM) {
slice_dbg(" found area at 0x%lx\n", newaddr);
return newaddr;
}
}
slice_mask_for_free(mm, &potential_mask);
slice_or_mask(&potential_mask, &good_mask);
slice_print_mask(" potential", potential_mask);
if ((addr != 0 || fixed) && slice_check_fit(mm, mask, potential_mask)) {
slice_dbg(" fits potential !\n");
goto convert;
}
if (fixed)
return -EBUSY;
slice_dbg(" search...\n");
if (addr) {
addr = slice_find_area(mm, len, good_mask,
psize, topdown, high_limit);
if (addr != -ENOMEM) {
slice_dbg(" found area at 0x%lx\n", addr);
return addr;
}
}
addr = slice_find_area(mm, len, potential_mask,
psize, topdown, high_limit);
#ifdef CONFIG_PPC_64K_PAGES
if (addr == -ENOMEM && psize == MMU_PAGE_64K) {
slice_or_mask(&potential_mask, &compat_mask);
addr = slice_find_area(mm, len, potential_mask,
psize, topdown, high_limit);
}
#endif
if (addr == -ENOMEM)
return -ENOMEM;
slice_range_to_mask(addr, len, &mask);
slice_dbg(" found potential area at 0x%lx\n", addr);
slice_print_mask(" mask", mask);
convert:
slice_andnot_mask(&mask, &good_mask);
slice_andnot_mask(&mask, &compat_mask);
if (mask.low_slices || !bitmap_empty(mask.high_slices, SLICE_NUM_HIGH)) {
slice_convert(mm, mask, psize);
if (psize > MMU_PAGE_BASE)
on_each_cpu(slice_flush_segments, mm, 1);
}
return addr;
}
unsigned long arch_get_unmapped_area(struct file *filp,
unsigned long addr,
unsigned long len,
unsigned long pgoff,
unsigned long flags)
{
return slice_get_unmapped_area(addr, len, flags,
current->mm->context.user_psize, 0);
}
unsigned long arch_get_unmapped_area_topdown(struct file *filp,
const unsigned long addr0,
const unsigned long len,
const unsigned long pgoff,
const unsigned long flags)
{
return slice_get_unmapped_area(addr0, len, flags,
current->mm->context.user_psize, 1);
}
unsigned int get_slice_psize(struct mm_struct *mm, unsigned long addr)
{
unsigned char *hpsizes;
int index, mask_index;
if (radix_enabled()) {
#ifdef CONFIG_PPC_64K_PAGES
return MMU_PAGE_64K;
#else
return MMU_PAGE_4K;
#endif
}
if (addr < SLICE_LOW_TOP) {
u64 lpsizes;
lpsizes = mm->context.low_slices_psize;
index = GET_LOW_SLICE_INDEX(addr);
return (lpsizes >> (index * 4)) & 0xf;
}
hpsizes = mm->context.high_slices_psize;
index = GET_HIGH_SLICE_INDEX(addr);
mask_index = index & 0x1;
return (hpsizes[index >> 1] >> (mask_index * 4)) & 0xf;
}
void slice_set_user_psize(struct mm_struct *mm, unsigned int psize)
{
int index, mask_index;
unsigned char *hpsizes;
unsigned long flags, lpsizes;
unsigned int old_psize;
int i;
slice_dbg("slice_set_user_psize(mm=%p, psize=%d)\n", mm, psize);
VM_BUG_ON(radix_enabled());
spin_lock_irqsave(&slice_convert_lock, flags);
old_psize = mm->context.user_psize;
slice_dbg(" old_psize=%d\n", old_psize);
if (old_psize == psize)
goto bail;
mm->context.user_psize = psize;
wmb();
lpsizes = mm->context.low_slices_psize;
for (i = 0; i < SLICE_NUM_LOW; i++)
if (((lpsizes >> (i * 4)) & 0xf) == old_psize)
lpsizes = (lpsizes & ~(0xful << (i * 4))) |
(((unsigned long)psize) << (i * 4));
mm->context.low_slices_psize = lpsizes;
hpsizes = mm->context.high_slices_psize;
for (i = 0; i < SLICE_NUM_HIGH; i++) {
mask_index = i & 0x1;
index = i >> 1;
if (((hpsizes[index] >> (mask_index * 4)) & 0xf) == old_psize)
hpsizes[index] = (hpsizes[index] &
~(0xf << (mask_index * 4))) |
(((unsigned long)psize) << (mask_index * 4));
}
slice_dbg(" lsps=%lx, hsps=%lx\n",
(unsigned long)mm->context.low_slices_psize,
(unsigned long)mm->context.high_slices_psize);
bail:
spin_unlock_irqrestore(&slice_convert_lock, flags);
}
void slice_set_range_psize(struct mm_struct *mm, unsigned long start,
unsigned long len, unsigned int psize)
{
struct slice_mask mask;
VM_BUG_ON(radix_enabled());
slice_range_to_mask(start, len, &mask);
slice_convert(mm, mask, psize);
}
int is_hugepage_only_range(struct mm_struct *mm, unsigned long addr,
unsigned long len)
{
struct slice_mask mask, available;
unsigned int psize = mm->context.user_psize;
if (radix_enabled())
return 0;
slice_range_to_mask(addr, len, &mask);
slice_mask_for_size(mm, psize, &available);
#ifdef CONFIG_PPC_64K_PAGES
if (psize == MMU_PAGE_64K) {
struct slice_mask compat_mask;
slice_mask_for_size(mm, MMU_PAGE_4K, &compat_mask);
slice_or_mask(&available, &compat_mask);
}
#endif
#if 0
slice_dbg("is_hugepage_only_range(mm=%p, addr=%lx, len=%lx)\n",
mm, addr, len);
slice_print_mask(" mask", mask);
slice_print_mask(" available", available);
#endif
return !slice_check_fit(mm, mask, available);
}
