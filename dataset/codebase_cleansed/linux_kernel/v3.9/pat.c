static inline void pat_disable(const char *reason)
{
pat_enabled = 0;
printk(KERN_INFO "%s\n", reason);
}
static int __init nopat(char *str)
{
pat_disable("PAT support disabled.");
return 0;
}
static inline void pat_disable(const char *reason)
{
(void)reason;
}
static int __init pat_debug_setup(char *str)
{
pat_debug_enable = 1;
return 0;
}
void pat_init(void)
{
u64 pat;
bool boot_cpu = !boot_pat_state;
if (!pat_enabled)
return;
if (!cpu_has_pat) {
if (!boot_pat_state) {
pat_disable("PAT not supported by CPU.");
return;
} else {
printk(KERN_ERR "PAT enabled, "
"but not supported by secondary CPU\n");
BUG();
}
}
pat = PAT(0, WB) | PAT(1, WC) | PAT(2, UC_MINUS) | PAT(3, UC) |
PAT(4, WB) | PAT(5, WC) | PAT(6, UC_MINUS) | PAT(7, UC);
if (!boot_pat_state)
rdmsrl(MSR_IA32_CR_PAT, boot_pat_state);
wrmsrl(MSR_IA32_CR_PAT, pat);
if (boot_cpu)
printk(KERN_INFO "x86 PAT enabled: cpu %d, old 0x%Lx, new 0x%Lx\n",
smp_processor_id(), boot_pat_state, pat);
}
static unsigned long pat_x_mtrr_type(u64 start, u64 end, unsigned long req_type)
{
if (req_type == _PAGE_CACHE_WB) {
u8 mtrr_type;
mtrr_type = mtrr_type_lookup(start, end);
if (mtrr_type != MTRR_TYPE_WRBACK)
return _PAGE_CACHE_UC_MINUS;
return _PAGE_CACHE_WB;
}
return req_type;
}
static int
pagerange_is_ram_callback(unsigned long initial_pfn, unsigned long total_nr_pages, void *arg)
{
struct pagerange_state *state = arg;
state->not_ram |= initial_pfn > state->cur_pfn;
state->ram |= total_nr_pages > 0;
state->cur_pfn = initial_pfn + total_nr_pages;
return state->ram && state->not_ram;
}
static int pat_pagerange_is_ram(resource_size_t start, resource_size_t end)
{
int ret = 0;
unsigned long start_pfn = start >> PAGE_SHIFT;
unsigned long end_pfn = (end + PAGE_SIZE - 1) >> PAGE_SHIFT;
struct pagerange_state state = {start_pfn, 0, 0};
if (start_pfn < ISA_END_ADDRESS >> PAGE_SHIFT)
start_pfn = ISA_END_ADDRESS >> PAGE_SHIFT;
if (start_pfn < end_pfn) {
ret = walk_system_ram_range(start_pfn, end_pfn - start_pfn,
&state, pagerange_is_ram_callback);
}
return (ret > 0) ? -1 : (state.ram ? 1 : 0);
}
static int reserve_ram_pages_type(u64 start, u64 end, unsigned long req_type,
unsigned long *new_type)
{
struct page *page;
u64 pfn;
if (req_type == _PAGE_CACHE_UC) {
WARN_ON_ONCE(1);
req_type = _PAGE_CACHE_UC_MINUS;
}
for (pfn = (start >> PAGE_SHIFT); pfn < (end >> PAGE_SHIFT); ++pfn) {
unsigned long type;
page = pfn_to_page(pfn);
type = get_page_memtype(page);
if (type != -1) {
printk(KERN_INFO "reserve_ram_pages_type failed [mem %#010Lx-%#010Lx], track 0x%lx, req 0x%lx\n",
start, end - 1, type, req_type);
if (new_type)
*new_type = type;
return -EBUSY;
}
}
if (new_type)
*new_type = req_type;
for (pfn = (start >> PAGE_SHIFT); pfn < (end >> PAGE_SHIFT); ++pfn) {
page = pfn_to_page(pfn);
set_page_memtype(page, req_type);
}
return 0;
}
static int free_ram_pages_type(u64 start, u64 end)
{
struct page *page;
u64 pfn;
for (pfn = (start >> PAGE_SHIFT); pfn < (end >> PAGE_SHIFT); ++pfn) {
page = pfn_to_page(pfn);
set_page_memtype(page, -1);
}
return 0;
}
int reserve_memtype(u64 start, u64 end, unsigned long req_type,
unsigned long *new_type)
{
struct memtype *new;
unsigned long actual_type;
int is_range_ram;
int err = 0;
BUG_ON(start >= end);
if (!pat_enabled) {
if (new_type) {
if (req_type == _PAGE_CACHE_WC)
*new_type = _PAGE_CACHE_UC_MINUS;
else
*new_type = req_type & _PAGE_CACHE_MASK;
}
return 0;
}
if (x86_platform.is_untracked_pat_range(start, end)) {
if (new_type)
*new_type = _PAGE_CACHE_WB;
return 0;
}
actual_type = pat_x_mtrr_type(start, end, req_type & _PAGE_CACHE_MASK);
if (new_type)
*new_type = actual_type;
is_range_ram = pat_pagerange_is_ram(start, end);
if (is_range_ram == 1) {
err = reserve_ram_pages_type(start, end, req_type, new_type);
return err;
} else if (is_range_ram < 0) {
return -EINVAL;
}
new = kzalloc(sizeof(struct memtype), GFP_KERNEL);
if (!new)
return -ENOMEM;
new->start = start;
new->end = end;
new->type = actual_type;
spin_lock(&memtype_lock);
err = rbt_memtype_check_insert(new, new_type);
if (err) {
printk(KERN_INFO "reserve_memtype failed [mem %#010Lx-%#010Lx], track %s, req %s\n",
start, end - 1,
cattr_name(new->type), cattr_name(req_type));
kfree(new);
spin_unlock(&memtype_lock);
return err;
}
spin_unlock(&memtype_lock);
dprintk("reserve_memtype added [mem %#010Lx-%#010Lx], track %s, req %s, ret %s\n",
start, end - 1, cattr_name(new->type), cattr_name(req_type),
new_type ? cattr_name(*new_type) : "-");
return err;
}
int free_memtype(u64 start, u64 end)
{
int err = -EINVAL;
int is_range_ram;
struct memtype *entry;
if (!pat_enabled)
return 0;
if (x86_platform.is_untracked_pat_range(start, end))
return 0;
is_range_ram = pat_pagerange_is_ram(start, end);
if (is_range_ram == 1) {
err = free_ram_pages_type(start, end);
return err;
} else if (is_range_ram < 0) {
return -EINVAL;
}
spin_lock(&memtype_lock);
entry = rbt_memtype_erase(start, end);
spin_unlock(&memtype_lock);
if (!entry) {
printk(KERN_INFO "%s:%d freeing invalid memtype [mem %#010Lx-%#010Lx]\n",
current->comm, current->pid, start, end - 1);
return -EINVAL;
}
kfree(entry);
dprintk("free_memtype request [mem %#010Lx-%#010Lx]\n", start, end - 1);
return 0;
}
static unsigned long lookup_memtype(u64 paddr)
{
int rettype = _PAGE_CACHE_WB;
struct memtype *entry;
if (x86_platform.is_untracked_pat_range(paddr, paddr + PAGE_SIZE))
return rettype;
if (pat_pagerange_is_ram(paddr, paddr + PAGE_SIZE)) {
struct page *page;
page = pfn_to_page(paddr >> PAGE_SHIFT);
rettype = get_page_memtype(page);
if (rettype == -1)
rettype = _PAGE_CACHE_WB;
return rettype;
}
spin_lock(&memtype_lock);
entry = rbt_memtype_lookup(paddr);
if (entry != NULL)
rettype = entry->type;
else
rettype = _PAGE_CACHE_UC_MINUS;
spin_unlock(&memtype_lock);
return rettype;
}
int io_reserve_memtype(resource_size_t start, resource_size_t end,
unsigned long *type)
{
resource_size_t size = end - start;
unsigned long req_type = *type;
unsigned long new_type;
int ret;
WARN_ON_ONCE(iomem_map_sanity_check(start, size));
ret = reserve_memtype(start, end, req_type, &new_type);
if (ret)
goto out_err;
if (!is_new_memtype_allowed(start, size, req_type, new_type))
goto out_free;
if (kernel_map_sync_memtype(start, size, new_type) < 0)
goto out_free;
*type = new_type;
return 0;
out_free:
free_memtype(start, end);
ret = -EBUSY;
out_err:
return ret;
}
void io_free_memtype(resource_size_t start, resource_size_t end)
{
free_memtype(start, end);
}
pgprot_t phys_mem_access_prot(struct file *file, unsigned long pfn,
unsigned long size, pgprot_t vma_prot)
{
return vma_prot;
}
static inline int range_is_allowed(unsigned long pfn, unsigned long size)
{
return 1;
}
static inline int range_is_allowed(unsigned long pfn, unsigned long size)
{
u64 from = ((u64)pfn) << PAGE_SHIFT;
u64 to = from + size;
u64 cursor = from;
if (!pat_enabled)
return 1;
while (cursor < to) {
if (!devmem_is_allowed(pfn)) {
printk(KERN_INFO "Program %s tried to access /dev/mem between [mem %#010Lx-%#010Lx]\n",
current->comm, from, to - 1);
return 0;
}
cursor += PAGE_SIZE;
pfn++;
}
return 1;
}
int phys_mem_access_prot_allowed(struct file *file, unsigned long pfn,
unsigned long size, pgprot_t *vma_prot)
{
unsigned long flags = _PAGE_CACHE_WB;
if (!range_is_allowed(pfn, size))
return 0;
if (file->f_flags & O_DSYNC)
flags = _PAGE_CACHE_UC_MINUS;
#ifdef CONFIG_X86_32
if (!pat_enabled &&
!(boot_cpu_has(X86_FEATURE_MTRR) ||
boot_cpu_has(X86_FEATURE_K6_MTRR) ||
boot_cpu_has(X86_FEATURE_CYRIX_ARR) ||
boot_cpu_has(X86_FEATURE_CENTAUR_MCR)) &&
(pfn << PAGE_SHIFT) >= __pa(high_memory)) {
flags = _PAGE_CACHE_UC;
}
#endif
*vma_prot = __pgprot((pgprot_val(*vma_prot) & ~_PAGE_CACHE_MASK) |
flags);
return 1;
}
int kernel_map_sync_memtype(u64 base, unsigned long size, unsigned long flags)
{
unsigned long id_sz;
if (base > __pa(high_memory-1))
return 0;
if (!page_is_ram(base >> PAGE_SHIFT))
return 0;
id_sz = (__pa(high_memory-1) <= base + size) ?
__pa(high_memory) - base :
size;
if (ioremap_change_attr((unsigned long)__va(base), id_sz, flags) < 0) {
printk(KERN_INFO "%s:%d ioremap_change_attr failed %s "
"for [mem %#010Lx-%#010Lx]\n",
current->comm, current->pid,
cattr_name(flags),
base, (unsigned long long)(base + size-1));
return -EINVAL;
}
return 0;
}
static int reserve_pfn_range(u64 paddr, unsigned long size, pgprot_t *vma_prot,
int strict_prot)
{
int is_ram = 0;
int ret;
unsigned long want_flags = (pgprot_val(*vma_prot) & _PAGE_CACHE_MASK);
unsigned long flags = want_flags;
is_ram = pat_pagerange_is_ram(paddr, paddr + size);
if (is_ram) {
if (!pat_enabled)
return 0;
flags = lookup_memtype(paddr);
if (want_flags != flags) {
printk(KERN_WARNING "%s:%d map pfn RAM range req %s for [mem %#010Lx-%#010Lx], got %s\n",
current->comm, current->pid,
cattr_name(want_flags),
(unsigned long long)paddr,
(unsigned long long)(paddr + size - 1),
cattr_name(flags));
*vma_prot = __pgprot((pgprot_val(*vma_prot) &
(~_PAGE_CACHE_MASK)) |
flags);
}
return 0;
}
ret = reserve_memtype(paddr, paddr + size, want_flags, &flags);
if (ret)
return ret;
if (flags != want_flags) {
if (strict_prot ||
!is_new_memtype_allowed(paddr, size, want_flags, flags)) {
free_memtype(paddr, paddr + size);
printk(KERN_ERR "%s:%d map pfn expected mapping type %s"
" for [mem %#010Lx-%#010Lx], got %s\n",
current->comm, current->pid,
cattr_name(want_flags),
(unsigned long long)paddr,
(unsigned long long)(paddr + size - 1),
cattr_name(flags));
return -EINVAL;
}
*vma_prot = __pgprot((pgprot_val(*vma_prot) &
(~_PAGE_CACHE_MASK)) |
flags);
}
if (kernel_map_sync_memtype(paddr, size, flags) < 0) {
free_memtype(paddr, paddr + size);
return -EINVAL;
}
return 0;
}
static void free_pfn_range(u64 paddr, unsigned long size)
{
int is_ram;
is_ram = pat_pagerange_is_ram(paddr, paddr + size);
if (is_ram == 0)
free_memtype(paddr, paddr + size);
}
int track_pfn_copy(struct vm_area_struct *vma)
{
resource_size_t paddr;
unsigned long prot;
unsigned long vma_size = vma->vm_end - vma->vm_start;
pgprot_t pgprot;
if (vma->vm_flags & VM_PAT) {
if (follow_phys(vma, vma->vm_start, 0, &prot, &paddr)) {
WARN_ON_ONCE(1);
return -EINVAL;
}
pgprot = __pgprot(prot);
return reserve_pfn_range(paddr, vma_size, &pgprot, 1);
}
return 0;
}
int track_pfn_remap(struct vm_area_struct *vma, pgprot_t *prot,
unsigned long pfn, unsigned long addr, unsigned long size)
{
resource_size_t paddr = (resource_size_t)pfn << PAGE_SHIFT;
unsigned long flags;
if (addr == vma->vm_start && size == (vma->vm_end - vma->vm_start)) {
int ret;
ret = reserve_pfn_range(paddr, size, prot, 0);
if (!ret)
vma->vm_flags |= VM_PAT;
return ret;
}
if (!pat_enabled)
return 0;
flags = lookup_memtype(paddr);
while (size > PAGE_SIZE) {
size -= PAGE_SIZE;
paddr += PAGE_SIZE;
if (flags != lookup_memtype(paddr))
return -EINVAL;
}
*prot = __pgprot((pgprot_val(vma->vm_page_prot) & (~_PAGE_CACHE_MASK)) |
flags);
return 0;
}
int track_pfn_insert(struct vm_area_struct *vma, pgprot_t *prot,
unsigned long pfn)
{
unsigned long flags;
if (!pat_enabled)
return 0;
flags = lookup_memtype((resource_size_t)pfn << PAGE_SHIFT);
*prot = __pgprot((pgprot_val(vma->vm_page_prot) & (~_PAGE_CACHE_MASK)) |
flags);
return 0;
}
void untrack_pfn(struct vm_area_struct *vma, unsigned long pfn,
unsigned long size)
{
resource_size_t paddr;
unsigned long prot;
if (!(vma->vm_flags & VM_PAT))
return;
paddr = (resource_size_t)pfn << PAGE_SHIFT;
if (!paddr && !size) {
if (follow_phys(vma, vma->vm_start, 0, &prot, &paddr)) {
WARN_ON_ONCE(1);
return;
}
size = vma->vm_end - vma->vm_start;
}
free_pfn_range(paddr, size);
vma->vm_flags &= ~VM_PAT;
}
pgprot_t pgprot_writecombine(pgprot_t prot)
{
if (pat_enabled)
return __pgprot(pgprot_val(prot) | _PAGE_CACHE_WC);
else
return pgprot_noncached(prot);
}
static struct memtype *memtype_get_idx(loff_t pos)
{
struct memtype *print_entry;
int ret;
print_entry = kzalloc(sizeof(struct memtype), GFP_KERNEL);
if (!print_entry)
return NULL;
spin_lock(&memtype_lock);
ret = rbt_memtype_copy_nth_element(print_entry, pos);
spin_unlock(&memtype_lock);
if (!ret) {
return print_entry;
} else {
kfree(print_entry);
return NULL;
}
}
static void *memtype_seq_start(struct seq_file *seq, loff_t *pos)
{
if (*pos == 0) {
++*pos;
seq_printf(seq, "PAT memtype list:\n");
}
return memtype_get_idx(*pos);
}
static void *memtype_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return memtype_get_idx(*pos);
}
static void memtype_seq_stop(struct seq_file *seq, void *v)
{
}
static int memtype_seq_show(struct seq_file *seq, void *v)
{
struct memtype *print_entry = (struct memtype *)v;
seq_printf(seq, "%s @ 0x%Lx-0x%Lx\n", cattr_name(print_entry->type),
print_entry->start, print_entry->end);
kfree(print_entry);
return 0;
}
static int memtype_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &memtype_seq_ops);
}
static int __init pat_memtype_list_init(void)
{
if (pat_enabled) {
debugfs_create_file("pat_memtype_list", S_IRUSR,
arch_debugfs_dir, NULL, &memtype_fops);
}
return 0;
}
