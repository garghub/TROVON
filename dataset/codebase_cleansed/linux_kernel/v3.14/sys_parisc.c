static int get_offset(unsigned int last_mmap)
{
return (last_mmap & (SHMLBA-1)) >> PAGE_SHIFT;
}
static unsigned long shared_align_offset(unsigned int last_mmap,
unsigned long pgoff)
{
return (get_offset(last_mmap) + pgoff) << PAGE_SHIFT;
}
static inline unsigned long COLOR_ALIGN(unsigned long addr,
unsigned int last_mmap, unsigned long pgoff)
{
unsigned long base = (addr+SHMLBA-1) & ~(SHMLBA-1);
unsigned long off = (SHMLBA-1) &
(shared_align_offset(last_mmap, pgoff) << PAGE_SHIFT);
return base + off;
}
static unsigned long mmap_upper_limit(void)
{
unsigned long stack_base;
stack_base = rlimit_max(RLIMIT_STACK);
if (stack_base > (1 << 30))
stack_base = 1 << 30;
return PAGE_ALIGN(STACK_TOP - stack_base);
}
unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr,
unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
unsigned long task_size = TASK_SIZE;
int do_color_align, last_mmap;
struct vm_unmapped_area_info info;
if (len > task_size)
return -ENOMEM;
do_color_align = 0;
if (filp || (flags & MAP_SHARED))
do_color_align = 1;
last_mmap = GET_LAST_MMAP(filp);
if (flags & MAP_FIXED) {
if ((flags & MAP_SHARED) && last_mmap &&
(addr - shared_align_offset(last_mmap, pgoff))
& (SHMLBA - 1))
return -EINVAL;
goto found_addr;
}
if (addr) {
if (do_color_align && last_mmap)
addr = COLOR_ALIGN(addr, last_mmap, pgoff);
else
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (task_size - len >= addr &&
(!vma || addr + len <= vma->vm_start))
goto found_addr;
}
info.flags = 0;
info.length = len;
info.low_limit = mm->mmap_legacy_base;
info.high_limit = mmap_upper_limit();
info.align_mask = last_mmap ? (PAGE_MASK & (SHMLBA - 1)) : 0;
info.align_offset = shared_align_offset(last_mmap, pgoff);
addr = vm_unmapped_area(&info);
found_addr:
if (do_color_align && !last_mmap && !(addr & ~PAGE_MASK))
SET_LAST_MMAP(filp, addr - (pgoff << PAGE_SHIFT));
return addr;
}
unsigned long
arch_get_unmapped_area_topdown(struct file *filp, const unsigned long addr0,
const unsigned long len, const unsigned long pgoff,
const unsigned long flags)
{
struct vm_area_struct *vma;
struct mm_struct *mm = current->mm;
unsigned long addr = addr0;
int do_color_align, last_mmap;
struct vm_unmapped_area_info info;
#ifdef CONFIG_64BIT
BUG_ON(!test_thread_flag(TIF_32BIT));
#endif
if (len > TASK_SIZE)
return -ENOMEM;
do_color_align = 0;
if (filp || (flags & MAP_SHARED))
do_color_align = 1;
last_mmap = GET_LAST_MMAP(filp);
if (flags & MAP_FIXED) {
if ((flags & MAP_SHARED) && last_mmap &&
(addr - shared_align_offset(last_mmap, pgoff))
& (SHMLBA - 1))
return -EINVAL;
goto found_addr;
}
if (addr) {
if (do_color_align && last_mmap)
addr = COLOR_ALIGN(addr, last_mmap, pgoff);
else
addr = PAGE_ALIGN(addr);
vma = find_vma(mm, addr);
if (TASK_SIZE - len >= addr &&
(!vma || addr + len <= vma->vm_start))
goto found_addr;
}
info.flags = VM_UNMAPPED_AREA_TOPDOWN;
info.length = len;
info.low_limit = PAGE_SIZE;
info.high_limit = mm->mmap_base;
info.align_mask = last_mmap ? (PAGE_MASK & (SHMLBA - 1)) : 0;
info.align_offset = shared_align_offset(last_mmap, pgoff);
addr = vm_unmapped_area(&info);
if (!(addr & ~PAGE_MASK))
goto found_addr;
VM_BUG_ON(addr != -ENOMEM);
return arch_get_unmapped_area(filp, addr0, len, pgoff, flags);
found_addr:
if (do_color_align && !last_mmap && !(addr & ~PAGE_MASK))
SET_LAST_MMAP(filp, addr - (pgoff << PAGE_SHIFT));
return addr;
}
static int mmap_is_legacy(void)
{
if (current->personality & ADDR_COMPAT_LAYOUT)
return 1;
return sysctl_legacy_va_layout;
}
static unsigned long mmap_rnd(void)
{
unsigned long rnd = 0;
if (current->flags & PF_RANDOMIZE) {
if (is_32bit_task())
rnd = get_random_int() % (1<<8);
else
rnd = get_random_int() % (1<<28);
}
return rnd << PAGE_SHIFT;
}
static unsigned long mmap_legacy_base(void)
{
return TASK_UNMAPPED_BASE + mmap_rnd();
}
void arch_pick_mmap_layout(struct mm_struct *mm)
{
mm->mmap_legacy_base = mmap_legacy_base();
mm->mmap_base = mmap_upper_limit();
if (mmap_is_legacy()) {
mm->mmap_base = mm->mmap_legacy_base;
mm->get_unmapped_area = arch_get_unmapped_area;
} else {
mm->get_unmapped_area = arch_get_unmapped_area_topdown;
}
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
