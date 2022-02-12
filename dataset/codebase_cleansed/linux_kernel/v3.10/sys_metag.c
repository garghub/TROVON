int metag_mmap_check(unsigned long addr, unsigned long len,
unsigned long flags)
{
if ((flags & MAP_FIXED) && (addr < TASK_UNMAPPED_BASE))
return -EINVAL;
return 0;
}
asmlinkage long sys_mmap2(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long pgoff)
{
if (pgoff & ((1 << (PAGE_SHIFT - 12)) - 1))
return -EINVAL;
pgoff >>= PAGE_SHIFT - 12;
return sys_mmap_pgoff(addr, len, prot, flags, fd, pgoff);
}
asmlinkage int sys_metag_setglobalbit(char __user *addr, int mask)
{
char tmp;
int ret = 0;
unsigned int flags;
if (!((__force unsigned int)addr >= LINCORE_BASE))
return -EFAULT;
__global_lock2(flags);
metag_data_cache_flush((__force void *)addr, sizeof(mask));
ret = __get_user(tmp, addr);
if (ret)
goto out;
tmp |= mask;
ret = __put_user(tmp, addr);
metag_data_cache_flush((__force void *)addr, sizeof(mask));
out:
__global_unlock2(flags);
return ret;
}
asmlinkage void sys_metag_set_fpu_flags(unsigned int flags)
{
unsigned int temp;
flags &= TXDEFR_FPU_MASK;
temp = __core_reg_get(TXDEFR);
temp &= ~TXDEFR_FPU_MASK;
temp |= flags;
__core_reg_set(TXDEFR, temp);
}
asmlinkage int sys_metag_set_tls(void __user *ptr)
{
current->thread.tls_ptr = ptr;
set_gateway_tls(ptr);
return 0;
}
asmlinkage void *sys_metag_get_tls(void)
{
return (__force void *)current->thread.tls_ptr;
}
asmlinkage long sys_truncate64_metag(const char __user *path, unsigned long lo,
unsigned long hi)
{
return sys_truncate64(path, merge_64(hi, lo));
}
asmlinkage long sys_ftruncate64_metag(unsigned int fd, unsigned long lo,
unsigned long hi)
{
return sys_ftruncate64(fd, merge_64(hi, lo));
}
asmlinkage long sys_fadvise64_64_metag(int fd, unsigned long offs_lo,
unsigned long offs_hi,
unsigned long len_lo,
unsigned long len_hi, int advice)
{
return sys_fadvise64_64(fd, merge_64(offs_hi, offs_lo),
merge_64(len_hi, len_lo), advice);
}
asmlinkage long sys_readahead_metag(int fd, unsigned long lo, unsigned long hi,
size_t count)
{
return sys_readahead(fd, merge_64(hi, lo), count);
}
asmlinkage ssize_t sys_pread64_metag(unsigned long fd, char __user *buf,
size_t count, unsigned long lo,
unsigned long hi)
{
return sys_pread64(fd, buf, count, merge_64(hi, lo));
}
asmlinkage ssize_t sys_pwrite64_metag(unsigned long fd, char __user *buf,
size_t count, unsigned long lo,
unsigned long hi)
{
return sys_pwrite64(fd, buf, count, merge_64(hi, lo));
}
asmlinkage long sys_sync_file_range_metag(int fd, unsigned long offs_lo,
unsigned long offs_hi,
unsigned long len_lo,
unsigned long len_hi,
unsigned int flags)
{
return sys_sync_file_range(fd, merge_64(offs_hi, offs_lo),
merge_64(len_hi, len_lo), flags);
}
