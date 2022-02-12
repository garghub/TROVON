unsigned long
arch_get_unmapped_area (struct file *filp, unsigned long addr, unsigned long len,
unsigned long pgoff, unsigned long flags)
{
long map_shared = (flags & MAP_SHARED);
unsigned long align_mask = 0;
struct mm_struct *mm = current->mm;
struct vm_unmapped_area_info info;
if (len > RGN_MAP_LIMIT)
return -ENOMEM;
if (flags & MAP_FIXED) {
if (is_hugepage_only_range(mm, addr, len))
return -EINVAL;
return addr;
}
#ifdef CONFIG_HUGETLB_PAGE
if (REGION_NUMBER(addr) == RGN_HPAGE)
addr = 0;
#endif
if (!addr)
addr = TASK_UNMAPPED_BASE;
if (map_shared && (TASK_SIZE > 0xfffffffful))
align_mask = PAGE_MASK & (SHMLBA - 1);
info.flags = 0;
info.length = len;
info.low_limit = addr;
info.high_limit = TASK_SIZE;
info.align_mask = align_mask;
info.align_offset = 0;
return vm_unmapped_area(&info);
}
asmlinkage long
ia64_getpriority (int which, int who)
{
long prio;
prio = sys_getpriority(which, who);
if (prio >= 0) {
force_successful_syscall_return();
prio = 20 - prio;
}
return prio;
}
asmlinkage unsigned long
sys_getpagesize (void)
{
return PAGE_SIZE;
}
asmlinkage unsigned long
ia64_brk (unsigned long brk)
{
unsigned long retval = sys_brk(brk);
force_successful_syscall_return();
return retval;
}
asmlinkage long
sys_ia64_pipe (void)
{
struct pt_regs *regs = task_pt_regs(current);
int fd[2];
int retval;
retval = do_pipe_flags(fd, 0);
if (retval)
goto out;
retval = fd[0];
regs->r9 = fd[1];
out:
return retval;
}
int ia64_mmap_check(unsigned long addr, unsigned long len,
unsigned long flags)
{
unsigned long roff;
roff = REGION_OFFSET(addr);
if ((len > RGN_MAP_LIMIT) || (roff > (RGN_MAP_LIMIT - len)))
return -EINVAL;
return 0;
}
asmlinkage unsigned long
sys_mmap2 (unsigned long addr, unsigned long len, int prot, int flags, int fd, long pgoff)
{
addr = sys_mmap_pgoff(addr, len, prot, flags, fd, pgoff);
if (!IS_ERR((void *) addr))
force_successful_syscall_return();
return addr;
}
asmlinkage unsigned long
sys_mmap (unsigned long addr, unsigned long len, int prot, int flags, int fd, long off)
{
if (offset_in_page(off) != 0)
return -EINVAL;
addr = sys_mmap_pgoff(addr, len, prot, flags, fd, off >> PAGE_SHIFT);
if (!IS_ERR((void *) addr))
force_successful_syscall_return();
return addr;
}
asmlinkage unsigned long
ia64_mremap (unsigned long addr, unsigned long old_len, unsigned long new_len, unsigned long flags,
unsigned long new_addr)
{
addr = sys_mremap(addr, old_len, new_len, flags, new_addr);
if (!IS_ERR((void *) addr))
force_successful_syscall_return();
return addr;
}
asmlinkage long
sys_pciconfig_read (unsigned long bus, unsigned long dfn, unsigned long off, unsigned long len,
void *buf)
{
return -ENOSYS;
}
asmlinkage long
sys_pciconfig_write (unsigned long bus, unsigned long dfn, unsigned long off, unsigned long len,
void *buf)
{
return -ENOSYS;
}
