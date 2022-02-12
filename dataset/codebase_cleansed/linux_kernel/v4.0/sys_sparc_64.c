asmlinkage unsigned long sys_getpagesize(void)
{
return PAGE_SIZE;
}
static inline int invalid_64bit_range(unsigned long addr, unsigned long len)
{
unsigned long va_exclude_start, va_exclude_end;
va_exclude_start = VA_EXCLUDE_START;
va_exclude_end = VA_EXCLUDE_END;
if (unlikely(len >= va_exclude_start))
return 1;
if (unlikely((addr + len) < addr))
return 1;
if (unlikely((addr >= va_exclude_start && addr < va_exclude_end) ||
((addr + len) >= va_exclude_start &&
(addr + len) < va_exclude_end)))
return 1;
return 0;
}
static inline unsigned long COLOR_ALIGN(unsigned long addr,
unsigned long pgoff)
{
unsigned long base = (addr+SHMLBA-1)&~(SHMLBA-1);
unsigned long off = (pgoff<<PAGE_SHIFT) & (SHMLBA-1);
return base + off;
}
unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr, unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct * vma;
unsigned long task_size = TASK_SIZE;
int do_color_align;
struct vm_unmapped_area_info info;
if (flags & MAP_FIXED) {
if ((flags & MAP_SHARED) &&
((addr - (pgoff << PAGE_SHIFT)) & (SHMLBA - 1)))
return -EINVAL;
return addr;
}
if (test_thread_flag(TIF_32BIT))
task_size = STACK_TOP32;
if (unlikely(len > task_size || len >= VA_EXCLUDE_START))
return -ENOMEM;
do_color_align = 0;
if (filp || (flags & MAP_SHARED))
do_color_align = 1;
if (addr) {
if (do_color_align)
addr = COLOR_ALIGN(addr, pgoff);
else
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (task_size - len >= addr &&
(!vma || addr + len <= vma->vm_start))
return addr;
}
info.flags = 0;
info.length = len;
info.low_limit = TASK_UNMAPPED_BASE;
info.high_limit = min(task_size, VA_EXCLUDE_START);
info.align_mask = do_color_align ? (PAGE_MASK & (SHMLBA - 1)) : 0;
info.align_offset = pgoff << PAGE_SHIFT;
addr = vm_unmapped_area(&info);
if ((addr & ~PAGE_MASK) && task_size > VA_EXCLUDE_END) {
VM_BUG_ON(addr != -ENOMEM);
info.low_limit = VA_EXCLUDE_END;
info.high_limit = task_size;
addr = vm_unmapped_area(&info);
}
return addr;
}
unsigned long
arch_get_unmapped_area_topdown(struct file *filp, const unsigned long addr0,
const unsigned long len, const unsigned long pgoff,
const unsigned long flags)
{
struct vm_area_struct *vma;
struct mm_struct *mm = current->mm;
unsigned long task_size = STACK_TOP32;
unsigned long addr = addr0;
int do_color_align;
struct vm_unmapped_area_info info;
BUG_ON(!test_thread_flag(TIF_32BIT));
if (flags & MAP_FIXED) {
if ((flags & MAP_SHARED) &&
((addr - (pgoff << PAGE_SHIFT)) & (SHMLBA - 1)))
return -EINVAL;
return addr;
}
if (unlikely(len > task_size))
return -ENOMEM;
do_color_align = 0;
if (filp || (flags & MAP_SHARED))
do_color_align = 1;
if (addr) {
if (do_color_align)
addr = COLOR_ALIGN(addr, pgoff);
else
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (task_size - len >= addr &&
(!vma || addr + len <= vma->vm_start))
return addr;
}
info.flags = VM_UNMAPPED_AREA_TOPDOWN;
info.length = len;
info.low_limit = PAGE_SIZE;
info.high_limit = mm->mmap_base;
info.align_mask = do_color_align ? (PAGE_MASK & (SHMLBA - 1)) : 0;
info.align_offset = pgoff << PAGE_SHIFT;
addr = vm_unmapped_area(&info);
if (addr & ~PAGE_MASK) {
VM_BUG_ON(addr != -ENOMEM);
info.flags = 0;
info.low_limit = TASK_UNMAPPED_BASE;
info.high_limit = STACK_TOP32;
addr = vm_unmapped_area(&info);
}
return addr;
}
unsigned long get_fb_unmapped_area(struct file *filp, unsigned long orig_addr, unsigned long len, unsigned long pgoff, unsigned long flags)
{
unsigned long align_goal, addr = -ENOMEM;
unsigned long (*get_area)(struct file *, unsigned long,
unsigned long, unsigned long, unsigned long);
get_area = current->mm->get_unmapped_area;
if (flags & MAP_FIXED) {
return get_area(NULL, orig_addr, len, pgoff, flags);
}
flags &= ~MAP_SHARED;
align_goal = PAGE_SIZE;
if (len >= (4UL * 1024 * 1024))
align_goal = (4UL * 1024 * 1024);
else if (len >= (512UL * 1024))
align_goal = (512UL * 1024);
else if (len >= (64UL * 1024))
align_goal = (64UL * 1024);
do {
addr = get_area(NULL, orig_addr, len + (align_goal - PAGE_SIZE), pgoff, flags);
if (!(addr & ~PAGE_MASK)) {
addr = (addr + (align_goal - 1UL)) & ~(align_goal - 1UL);
break;
}
if (align_goal == (4UL * 1024 * 1024))
align_goal = (512UL * 1024);
else if (align_goal == (512UL * 1024))
align_goal = (64UL * 1024);
else
align_goal = PAGE_SIZE;
} while ((addr & ~PAGE_MASK) && align_goal > PAGE_SIZE);
if (addr & ~PAGE_MASK)
addr = get_area(NULL, orig_addr, len, pgoff, flags);
return addr;
}
static unsigned long mmap_rnd(void)
{
unsigned long rnd = 0UL;
if (current->flags & PF_RANDOMIZE) {
unsigned long val = get_random_int();
if (test_thread_flag(TIF_32BIT))
rnd = (val % (1UL << (23UL-PAGE_SHIFT)));
else
rnd = (val % (1UL << (30UL-PAGE_SHIFT)));
}
return rnd << PAGE_SHIFT;
}
void arch_pick_mmap_layout(struct mm_struct *mm)
{
unsigned long random_factor = mmap_rnd();
unsigned long gap;
gap = rlimit(RLIMIT_STACK);
if (!test_thread_flag(TIF_32BIT) ||
(current->personality & ADDR_COMPAT_LAYOUT) ||
gap == RLIM_INFINITY ||
sysctl_legacy_va_layout) {
mm->mmap_base = TASK_UNMAPPED_BASE + random_factor;
mm->get_unmapped_area = arch_get_unmapped_area;
} else {
unsigned long task_size = STACK_TOP32;
if (gap < 128 * 1024 * 1024)
gap = 128 * 1024 * 1024;
if (gap > (task_size / 6 * 5))
gap = (task_size / 6 * 5);
mm->mmap_base = PAGE_ALIGN(task_size - gap - random_factor);
mm->get_unmapped_area = arch_get_unmapped_area_topdown;
}
}
int sparc_mmap_check(unsigned long addr, unsigned long len)
{
if (test_thread_flag(TIF_32BIT)) {
if (len >= STACK_TOP32)
return -EINVAL;
if (addr > STACK_TOP32 - len)
return -EINVAL;
} else {
if (len >= VA_EXCLUDE_START)
return -EINVAL;
if (invalid_64bit_range(addr, len))
return -EINVAL;
}
return 0;
}
asmlinkage unsigned long c_sys_nis_syscall(struct pt_regs *regs)
{
static int count;
if (count++ > 5)
return -ENOSYS;
printk ("Unimplemented SPARC system call %ld\n",regs->u_regs[1]);
#ifdef DEBUG_UNIMP_SYSCALL
show_regs (regs);
#endif
return -ENOSYS;
}
asmlinkage void sparc_breakpoint(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
#ifdef DEBUG_SPARC_BREAKPOINT
printk ("TRAP: Entering kernel PC=%lx, nPC=%lx\n", regs->tpc, regs->tnpc);
#endif
info.si_signo = SIGTRAP;
info.si_errno = 0;
info.si_code = TRAP_BRKPT;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = 0;
force_sig_info(SIGTRAP, &info, current);
#ifdef DEBUG_SPARC_BREAKPOINT
printk ("TRAP: Returning to space: PC=%lx nPC=%lx\n", regs->tpc, regs->tnpc);
#endif
exception_exit(prev_state);
}
asmlinkage long sparc_memory_ordering(unsigned long model,
struct pt_regs *regs)
{
if (model >= 3)
return -EINVAL;
regs->tstate = (regs->tstate & ~TSTATE_MM) | (model << 14);
return 0;
}
asmlinkage long sys_kern_features(void)
{
return KERN_FEATURE_MIXED_MODE_STACK;
}
