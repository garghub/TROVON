unsigned long align_addr(unsigned long addr, struct file *filp,
enum align_flags flags)
{
unsigned long tmp_addr;
if (va_align.flags < 0 || !(va_align.flags & (2 - mmap_is_ia32())))
return addr;
if (!(current->flags & PF_RANDOMIZE))
return addr;
if (!((flags & ALIGN_VDSO) || filp))
return addr;
tmp_addr = addr;
if (!(flags & ALIGN_TOPDOWN))
tmp_addr += va_align.mask;
tmp_addr &= ~va_align.mask;
return tmp_addr;
}
static int __init control_va_addr_alignment(char *str)
{
if (va_align.flags < 0)
return 1;
if (*str == 0)
return 1;
if (*str == '=')
str++;
if (!strcmp(str, "32"))
va_align.flags = ALIGN_VA_32;
else if (!strcmp(str, "64"))
va_align.flags = ALIGN_VA_64;
else if (!strcmp(str, "off"))
va_align.flags = 0;
else if (!strcmp(str, "on"))
va_align.flags = ALIGN_VA_32 | ALIGN_VA_64;
else
return 0;
return 1;
}
static void find_start_end(unsigned long flags, unsigned long *begin,
unsigned long *end)
{
if (!test_thread_flag(TIF_IA32) && (flags & MAP_32BIT)) {
unsigned long new_begin;
*begin = 0x40000000;
*end = 0x80000000;
if (current->flags & PF_RANDOMIZE) {
new_begin = randomize_range(*begin, *begin + 0x02000000, 0);
if (new_begin)
*begin = new_begin;
}
} else {
*begin = TASK_UNMAPPED_BASE;
*end = TASK_SIZE;
}
}
unsigned long
arch_get_unmapped_area(struct file *filp, unsigned long addr,
unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
unsigned long start_addr;
unsigned long begin, end;
if (flags & MAP_FIXED)
return addr;
find_start_end(flags, &begin, &end);
if (len > end)
return -ENOMEM;
if (addr) {
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (end - len >= addr &&
(!vma || addr + len <= vma->vm_start))
return addr;
}
if (((flags & MAP_32BIT) || test_thread_flag(TIF_IA32))
&& len <= mm->cached_hole_size) {
mm->cached_hole_size = 0;
mm->free_area_cache = begin;
}
addr = mm->free_area_cache;
if (addr < begin)
addr = begin;
start_addr = addr;
full_search:
addr = align_addr(addr, filp, 0);
for (vma = find_vma(mm, addr); ; vma = vma->vm_next) {
if (end - len < addr) {
if (start_addr != begin) {
start_addr = addr = begin;
mm->cached_hole_size = 0;
goto full_search;
}
return -ENOMEM;
}
if (!vma || addr + len <= vma->vm_start) {
mm->free_area_cache = addr + len;
return addr;
}
if (addr + mm->cached_hole_size < vma->vm_start)
mm->cached_hole_size = vma->vm_start - addr;
addr = vma->vm_end;
addr = align_addr(addr, filp, 0);
}
}
unsigned long
arch_get_unmapped_area_topdown(struct file *filp, const unsigned long addr0,
const unsigned long len, const unsigned long pgoff,
const unsigned long flags)
{
struct vm_area_struct *vma;
struct mm_struct *mm = current->mm;
unsigned long addr = addr0;
if (len > TASK_SIZE)
return -ENOMEM;
if (flags & MAP_FIXED)
return addr;
if (!test_thread_flag(TIF_IA32) && (flags & MAP_32BIT))
goto bottomup;
if (addr) {
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (TASK_SIZE - len >= addr &&
(!vma || addr + len <= vma->vm_start))
return addr;
}
if (len <= mm->cached_hole_size) {
mm->cached_hole_size = 0;
mm->free_area_cache = mm->mmap_base;
}
addr = mm->free_area_cache;
if (addr > len) {
unsigned long tmp_addr = align_addr(addr - len, filp,
ALIGN_TOPDOWN);
vma = find_vma(mm, tmp_addr);
if (!vma || tmp_addr + len <= vma->vm_start)
return mm->free_area_cache = tmp_addr;
}
if (mm->mmap_base < len)
goto bottomup;
addr = mm->mmap_base-len;
do {
addr = align_addr(addr, filp, ALIGN_TOPDOWN);
vma = find_vma(mm, addr);
if (!vma || addr+len <= vma->vm_start)
return mm->free_area_cache = addr;
if (addr + mm->cached_hole_size < vma->vm_start)
mm->cached_hole_size = vma->vm_start - addr;
addr = vma->vm_start-len;
} while (len < vma->vm_start);
bottomup:
mm->cached_hole_size = ~0UL;
mm->free_area_cache = TASK_UNMAPPED_BASE;
addr = arch_get_unmapped_area(filp, addr0, len, pgoff, flags);
mm->free_area_cache = mm->mmap_base;
mm->cached_hole_size = ~0UL;
return addr;
}
