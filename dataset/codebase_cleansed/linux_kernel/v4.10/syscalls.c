static inline unsigned long do_mmap2(unsigned long addr, size_t len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long off, int shift)
{
unsigned long ret = -EINVAL;
if (!arch_validate_prot(prot))
goto out;
if (shift) {
if (off & ((1 << shift) - 1))
goto out;
off >>= shift;
}
ret = sys_mmap_pgoff(addr, len, prot, flags, fd, off);
out:
return ret;
}
unsigned long sys_mmap2(unsigned long addr, size_t len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long pgoff)
{
return do_mmap2(addr, len, prot, flags, fd, pgoff, PAGE_SHIFT-12);
}
unsigned long sys_mmap(unsigned long addr, size_t len,
unsigned long prot, unsigned long flags,
unsigned long fd, off_t offset)
{
return do_mmap2(addr, len, prot, flags, fd, offset, PAGE_SHIFT);
}
int
ppc_select(int n, fd_set __user *inp, fd_set __user *outp, fd_set __user *exp, struct timeval __user *tvp)
{
if ( (unsigned long)n >= 4096 )
{
unsigned long __user *buffer = (unsigned long __user *)n;
if (!access_ok(VERIFY_READ, buffer, 5*sizeof(unsigned long))
|| __get_user(n, buffer)
|| __get_user(inp, ((fd_set __user * __user *)(buffer+1)))
|| __get_user(outp, ((fd_set __user * __user *)(buffer+2)))
|| __get_user(exp, ((fd_set __user * __user *)(buffer+3)))
|| __get_user(tvp, ((struct timeval __user * __user *)(buffer+4))))
return -EFAULT;
}
return sys_select(n, inp, outp, exp, tvp);
}
long ppc64_personality(unsigned long personality)
{
long ret;
if (personality(current->personality) == PER_LINUX32
&& personality(personality) == PER_LINUX)
personality = (personality & ~PER_MASK) | PER_LINUX32;
ret = sys_personality(personality);
if (personality(ret) == PER_LINUX32)
ret = (ret & ~PER_MASK) | PER_LINUX;
return ret;
}
long ppc_fadvise64_64(int fd, int advice, u32 offset_high, u32 offset_low,
u32 len_high, u32 len_low)
{
return sys_fadvise64(fd, (u64)offset_high << 32 | offset_low,
(u64)len_high << 32 | len_low, advice);
}
long sys_switch_endian(void)
{
struct thread_info *ti;
current->thread.regs->msr ^= MSR_LE;
ti = current_thread_info();
ti->flags |= _TIF_RESTOREALL;
return 0;
}
