static unsigned long get_unshared_area(unsigned long addr, unsigned long len)
{
struct vm_unmapped_area_info info;
info.flags = 0;
info.length = len;
info.low_limit = PAGE_ALIGN(addr);
info.high_limit = TASK_SIZE;
info.align_mask = 0;
info.align_offset = 0;
return vm_unmapped_area(&info);
}
static int get_offset(struct address_space *mapping)
{
return (unsigned long) mapping >> 8;
}
static unsigned long get_shared_area(struct address_space *mapping,
unsigned long addr, unsigned long len, unsigned long pgoff)
{
struct vm_unmapped_area_info info;
info.flags = 0;
info.length = len;
info.low_limit = PAGE_ALIGN(addr);
info.high_limit = TASK_SIZE;
info.align_mask = PAGE_MASK & (SHMLBA - 1);
info.align_offset = (get_offset(mapping) + pgoff) << PAGE_SHIFT;
return vm_unmapped_area(&info);
}
unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr,
unsigned long len, unsigned long pgoff, unsigned long flags)
{
if (len > TASK_SIZE)
return -ENOMEM;
if (flags & MAP_FIXED) {
if ((flags & MAP_SHARED) &&
(addr - (pgoff << PAGE_SHIFT)) & (SHMLBA - 1))
return -EINVAL;
return addr;
}
if (!addr)
addr = TASK_UNMAPPED_BASE;
if (filp) {
addr = get_shared_area(filp->f_mapping, addr, len, pgoff);
} else if(flags & MAP_SHARED) {
addr = get_shared_area(NULL, addr, len, pgoff);
} else {
addr = get_unshared_area(addr, len);
}
return addr;
}
asmlinkage unsigned long sys_mmap2(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags, unsigned long fd,
unsigned long pgoff)
{
return sys_mmap_pgoff(addr, len, prot, flags, fd,
pgoff >> (PAGE_SHIFT - 12));
}
asmlinkage unsigned long sys_mmap(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags, unsigned long fd,
unsigned long offset)
{
if (!(offset & ~PAGE_MASK)) {
return sys_mmap_pgoff(addr, len, prot, flags, fd,
offset >> PAGE_SHIFT);
} else {
return -EINVAL;
}
}
asmlinkage long parisc_truncate64(const char __user * path,
unsigned int high, unsigned int low)
{
return sys_truncate(path, (long)high << 32 | low);
}
asmlinkage long parisc_ftruncate64(unsigned int fd,
unsigned int high, unsigned int low)
{
return sys_ftruncate(fd, (long)high << 32 | low);
}
asmlinkage long sys_truncate64(const char __user * path, unsigned long length)
{
return sys_truncate(path, length);
}
asmlinkage long sys_ftruncate64(unsigned int fd, unsigned long length)
{
return sys_ftruncate(fd, length);
}
asmlinkage long sys_fcntl64(unsigned int fd, unsigned int cmd, unsigned long arg)
{
return sys_fcntl(fd, cmd, arg);
}
asmlinkage long parisc_truncate64(const char __user * path,
unsigned int high, unsigned int low)
{
return sys_truncate64(path, (loff_t)high << 32 | low);
}
asmlinkage long parisc_ftruncate64(unsigned int fd,
unsigned int high, unsigned int low)
{
return sys_ftruncate64(fd, (loff_t)high << 32 | low);
}
asmlinkage ssize_t parisc_pread64(unsigned int fd, char __user *buf, size_t count,
unsigned int high, unsigned int low)
{
return sys_pread64(fd, buf, count, (loff_t)high << 32 | low);
}
asmlinkage ssize_t parisc_pwrite64(unsigned int fd, const char __user *buf,
size_t count, unsigned int high, unsigned int low)
{
return sys_pwrite64(fd, buf, count, (loff_t)high << 32 | low);
}
asmlinkage ssize_t parisc_readahead(int fd, unsigned int high, unsigned int low,
size_t count)
{
return sys_readahead(fd, (loff_t)high << 32 | low, count);
}
asmlinkage long parisc_fadvise64_64(int fd,
unsigned int high_off, unsigned int low_off,
unsigned int high_len, unsigned int low_len, int advice)
{
return sys_fadvise64_64(fd, (loff_t)high_off << 32 | low_off,
(loff_t)high_len << 32 | low_len, advice);
}
asmlinkage long parisc_sync_file_range(int fd,
u32 hi_off, u32 lo_off, u32 hi_nbytes, u32 lo_nbytes,
unsigned int flags)
{
return sys_sync_file_range(fd, (loff_t)hi_off << 32 | lo_off,
(loff_t)hi_nbytes << 32 | lo_nbytes, flags);
}
asmlinkage long parisc_fallocate(int fd, int mode, u32 offhi, u32 offlo,
u32 lenhi, u32 lenlo)
{
return sys_fallocate(fd, mode, ((u64)offhi << 32) | offlo,
((u64)lenhi << 32) | lenlo);
}
asmlinkage unsigned long sys_alloc_hugepages(int key, unsigned long addr, unsigned long len, int prot, int flag)
{
return -ENOMEM;
}
asmlinkage int sys_free_hugepages(unsigned long addr)
{
return -EINVAL;
}
long parisc_personality(unsigned long personality)
{
long err;
if (personality(current->personality) == PER_LINUX32
&& personality(personality) == PER_LINUX)
personality = (personality & ~PER_MASK) | PER_LINUX32;
err = sys_personality(personality);
if (personality(err) == PER_LINUX32)
err = (err & ~PER_MASK) | PER_LINUX;
return err;
}
