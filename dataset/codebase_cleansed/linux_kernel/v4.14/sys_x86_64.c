static unsigned long get_align_mask(void)
{
if (va_align.flags < 0 || !(va_align.flags & (2 - mmap_is_ia32())))
return 0;
if (!(current->flags & PF_RANDOMIZE))
return 0;
return va_align.mask;
}
static unsigned long get_align_bits(void)
{
return va_align.bits & get_align_mask();
}
unsigned long align_vdso_addr(unsigned long addr)
{
unsigned long align_mask = get_align_mask();
addr = (addr + align_mask) & ~align_mask;
return addr | get_align_bits();
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
static void find_start_end(unsigned long addr, unsigned long flags,
unsigned long *begin, unsigned long *end)
{
if (!in_compat_syscall() && (flags & MAP_32BIT)) {
*begin = 0x40000000;
*end = 0x80000000;
if (current->flags & PF_RANDOMIZE) {
*begin = randomize_page(*begin, 0x02000000);
}
return;
}
*begin = get_mmap_base(1);
if (in_compat_syscall())
*end = task_size_32bit();
else
*end = task_size_64bit(addr > DEFAULT_MAP_WINDOW);
}
unsigned long
arch_get_unmapped_area(struct file *filp, unsigned long addr,
unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
struct vm_unmapped_area_info info;
unsigned long begin, end;
addr = mpx_unmapped_area_check(addr, len, flags);
if (IS_ERR_VALUE(addr))
return addr;
if (flags & MAP_FIXED)
return addr;
find_start_end(addr, flags, &begin, &end);
if (len > end)
return -ENOMEM;
if (addr) {
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (end - len >= addr &&
(!vma || addr + len <= vm_start_gap(vma)))
return addr;
}
info.flags = 0;
info.length = len;
info.low_limit = begin;
info.high_limit = end;
info.align_mask = 0;
info.align_offset = pgoff << PAGE_SHIFT;
if (filp) {
info.align_mask = get_align_mask();
info.align_offset += get_align_bits();
}
return vm_unmapped_area(&info);
}
unsigned long
arch_get_unmapped_area_topdown(struct file *filp, const unsigned long addr0,
const unsigned long len, const unsigned long pgoff,
const unsigned long flags)
{
struct vm_area_struct *vma;
struct mm_struct *mm = current->mm;
unsigned long addr = addr0;
struct vm_unmapped_area_info info;
addr = mpx_unmapped_area_check(addr, len, flags);
if (IS_ERR_VALUE(addr))
return addr;
if (len > TASK_SIZE)
return -ENOMEM;
if (flags & MAP_FIXED)
return addr;
if (!in_compat_syscall() && (flags & MAP_32BIT))
goto bottomup;
if (addr) {
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (TASK_SIZE - len >= addr &&
(!vma || addr + len <= vm_start_gap(vma)))
return addr;
}
info.flags = VM_UNMAPPED_AREA_TOPDOWN;
info.length = len;
info.low_limit = PAGE_SIZE;
info.high_limit = get_mmap_base(0);
if (addr > DEFAULT_MAP_WINDOW && !in_compat_syscall())
info.high_limit += TASK_SIZE_MAX - DEFAULT_MAP_WINDOW;
info.align_mask = 0;
info.align_offset = pgoff << PAGE_SHIFT;
if (filp) {
info.align_mask = get_align_mask();
info.align_offset += get_align_bits();
}
addr = vm_unmapped_area(&info);
if (!(addr & ~PAGE_MASK))
return addr;
VM_BUG_ON(addr != -ENOMEM);
bottomup:
return arch_get_unmapped_area(filp, addr0, len, pgoff, flags);
}
