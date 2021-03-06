asmlinkage long sys_mmap2(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long pgoff)
{
return sys_mmap_pgoff(addr, len, prot, flags, fd, pgoff);
}
static inline int
cache_flush_040 (unsigned long addr, int scope, int cache, unsigned long len)
{
unsigned long paddr, i;
switch (scope)
{
case FLUSH_SCOPE_ALL:
switch (cache)
{
case FLUSH_CACHE_DATA:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpusha %dc\n\t"
".chip 68k");
break;
case FLUSH_CACHE_INSN:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpusha %ic\n\t"
".chip 68k");
break;
default:
case FLUSH_CACHE_BOTH:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpusha %bc\n\t"
".chip 68k");
break;
}
break;
case FLUSH_SCOPE_LINE:
if ((paddr = virt_to_phys_040(addr))) {
paddr += addr & ~(PAGE_MASK | 15);
len = (len + (addr & 15) + 15) >> 4;
} else {
unsigned long tmp = PAGE_SIZE - (addr & ~PAGE_MASK);
if (len <= tmp)
return 0;
addr += tmp;
len -= tmp;
tmp = PAGE_SIZE;
for (;;)
{
if ((paddr = virt_to_phys_040(addr)))
break;
if (len <= tmp)
return 0;
addr += tmp;
len -= tmp;
}
len = (len + 15) >> 4;
}
i = (PAGE_SIZE - (paddr & ~PAGE_MASK)) >> 4;
while (len--)
{
switch (cache)
{
case FLUSH_CACHE_DATA:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushl %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case FLUSH_CACHE_INSN:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushl %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case FLUSH_CACHE_BOTH:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
if (!--i && len)
{
addr += PAGE_SIZE;
i = PAGE_SIZE / 16;
for (;;)
{
if ((paddr = virt_to_phys_040(addr)))
break;
if (len <= i)
return 0;
len -= i;
addr += PAGE_SIZE;
}
}
else
paddr += 16;
}
break;
default:
case FLUSH_SCOPE_PAGE:
len += (addr & ~PAGE_MASK) + (PAGE_SIZE - 1);
for (len >>= PAGE_SHIFT; len--; addr += PAGE_SIZE)
{
if (!(paddr = virt_to_phys_040(addr)))
continue;
switch (cache)
{
case FLUSH_CACHE_DATA:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushp %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case FLUSH_CACHE_INSN:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushp %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case FLUSH_CACHE_BOTH:
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushp %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
}
break;
}
return 0;
}
static inline int
cache_flush_060 (unsigned long addr, int scope, int cache, unsigned long len)
{
unsigned long paddr, i;
switch (scope)
{
case FLUSH_SCOPE_ALL:
switch (cache)
{
case FLUSH_CACHE_DATA:
__asm__ __volatile__ (".chip 68060\n\t"
"cpusha %dc\n\t"
".chip 68k");
break;
case FLUSH_CACHE_INSN:
__asm__ __volatile__ (".chip 68060\n\t"
"cpusha %ic\n\t"
".chip 68k");
break;
default:
case FLUSH_CACHE_BOTH:
__asm__ __volatile__ (".chip 68060\n\t"
"cpusha %bc\n\t"
".chip 68k");
break;
}
break;
case FLUSH_SCOPE_LINE:
len += addr & 15;
addr &= -16;
if (!(paddr = virt_to_phys_060(addr))) {
unsigned long tmp = PAGE_SIZE - (addr & ~PAGE_MASK);
if (len <= tmp)
return 0;
addr += tmp;
len -= tmp;
tmp = PAGE_SIZE;
for (;;)
{
if ((paddr = virt_to_phys_060(addr)))
break;
if (len <= tmp)
return 0;
addr += tmp;
len -= tmp;
}
}
len = (len + 15) >> 4;
i = (PAGE_SIZE - (paddr & ~PAGE_MASK)) >> 4;
while (len--)
{
switch (cache)
{
case FLUSH_CACHE_DATA:
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case FLUSH_CACHE_INSN:
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case FLUSH_CACHE_BOTH:
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
if (!--i && len)
{
addr += PAGE_SIZE;
addr &= PAGE_MASK;
i = PAGE_SIZE / 16;
for (;;)
{
if ((paddr = virt_to_phys_060(addr)))
break;
if (len <= i)
return 0;
len -= i;
addr += PAGE_SIZE;
}
}
else
paddr += 16;
}
break;
default:
case FLUSH_SCOPE_PAGE:
len += (addr & ~PAGE_MASK) + (PAGE_SIZE - 1);
addr &= PAGE_MASK;
for (len >>= PAGE_SHIFT; len--; addr += PAGE_SIZE)
{
if (!(paddr = virt_to_phys_060(addr)))
continue;
switch (cache)
{
case FLUSH_CACHE_DATA:
__asm__ __volatile__ (".chip 68060\n\t"
"cpushp %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case FLUSH_CACHE_INSN:
__asm__ __volatile__ (".chip 68060\n\t"
"cpushp %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case FLUSH_CACHE_BOTH:
__asm__ __volatile__ (".chip 68060\n\t"
"cpushp %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
}
break;
}
return 0;
}
asmlinkage int
sys_cacheflush (unsigned long addr, int scope, int cache, unsigned long len)
{
int ret = -EINVAL;
if (scope < FLUSH_SCOPE_LINE || scope > FLUSH_SCOPE_ALL ||
cache & ~FLUSH_CACHE_BOTH)
goto out;
if (scope == FLUSH_SCOPE_ALL) {
ret = -EPERM;
if (!capable(CAP_SYS_ADMIN))
goto out;
} else {
struct vm_area_struct *vma;
if (addr + len < addr)
goto out;
down_read(&current->mm->mmap_sem);
vma = find_vma(current->mm, addr);
if (!vma || addr < vma->vm_start || addr + len > vma->vm_end)
goto out_unlock;
}
if (CPU_IS_020_OR_030) {
if (scope == FLUSH_SCOPE_LINE && len < 256) {
unsigned long cacr;
__asm__ ("movec %%cacr, %0" : "=r" (cacr));
if (cache & FLUSH_CACHE_INSN)
cacr |= 4;
if (cache & FLUSH_CACHE_DATA)
cacr |= 0x400;
len >>= 2;
while (len--) {
__asm__ __volatile__ ("movec %1, %%caar\n\t"
"movec %0, %%cacr"
:
: "r" (cacr), "r" (addr));
addr += 4;
}
} else {
unsigned long cacr;
__asm__ ("movec %%cacr, %0" : "=r" (cacr));
if (cache & FLUSH_CACHE_INSN)
cacr |= 8;
if (cache & FLUSH_CACHE_DATA)
cacr |= 0x800;
__asm__ __volatile__ ("movec %0, %%cacr" : : "r" (cacr));
}
ret = 0;
goto out_unlock;
} else {
if (len>=3*PAGE_SIZE && scope<FLUSH_SCOPE_PAGE)
scope=FLUSH_SCOPE_PAGE;
if (len>=10*PAGE_SIZE && scope<FLUSH_SCOPE_ALL)
scope=FLUSH_SCOPE_ALL;
if (CPU_IS_040) {
ret = cache_flush_040 (addr, scope, cache, len);
} else if (CPU_IS_060) {
ret = cache_flush_060 (addr, scope, cache, len);
}
}
out_unlock:
up_read(&current->mm->mmap_sem);
out:
return ret;
}
asmlinkage int
sys_atomic_cmpxchg_32(unsigned long newval, int oldval, int d3, int d4, int d5,
unsigned long __user * mem)
{
for (;;) {
struct mm_struct *mm = current->mm;
pgd_t *pgd;
pmd_t *pmd;
pte_t *pte;
spinlock_t *ptl;
unsigned long mem_value;
down_read(&mm->mmap_sem);
pgd = pgd_offset(mm, (unsigned long)mem);
if (!pgd_present(*pgd))
goto bad_access;
pmd = pmd_offset(pgd, (unsigned long)mem);
if (!pmd_present(*pmd))
goto bad_access;
pte = pte_offset_map_lock(mm, pmd, (unsigned long)mem, &ptl);
if (!pte_present(*pte) || !pte_dirty(*pte)
|| !pte_write(*pte)) {
pte_unmap_unlock(pte, ptl);
goto bad_access;
}
__get_user(mem_value, mem);
if (mem_value == oldval)
__put_user(newval, mem);
pte_unmap_unlock(pte, ptl);
up_read(&mm->mmap_sem);
return mem_value;
bad_access:
up_read(&mm->mmap_sem);
{
struct pt_regs *fp = (struct pt_regs *)&newval;
if (do_page_fault(fp, (unsigned long)mem, 3))
return 0xdeadbeef;
}
}
}
asmlinkage int
sys_cacheflush (unsigned long addr, int scope, int cache, unsigned long len)
{
flush_cache_all();
return 0;
}
asmlinkage int
sys_atomic_cmpxchg_32(unsigned long newval, int oldval, int d3, int d4, int d5,
unsigned long __user * mem)
{
struct mm_struct *mm = current->mm;
unsigned long mem_value;
down_read(&mm->mmap_sem);
mem_value = *mem;
if (mem_value == oldval)
*mem = newval;
up_read(&mm->mmap_sem);
return mem_value;
}
asmlinkage int sys_getpagesize(void)
{
return PAGE_SIZE;
}
asmlinkage unsigned long sys_get_thread_area(void)
{
return current_thread_info()->tp_value;
}
asmlinkage int sys_set_thread_area(unsigned long tp)
{
current_thread_info()->tp_value = tp;
return 0;
}
asmlinkage int sys_atomic_barrier(void)
{
return 0;
}
