void pat_disable(const char *reason)
{
if (!__pat_enabled)
return;
if (boot_cpu_done) {
WARN_ONCE(1, "x86/PAT: PAT cannot be disabled after initialization\n");
return;
}
__pat_enabled = 0;
pr_info("x86/PAT: %s\n", reason);
init_cache_modes();
}
static int __init nopat(char *str)
{
pat_disable("PAT support disabled.");
return 0;
}
bool pat_enabled(void)
{
return !!__pat_enabled;
}
static int __init pat_debug_setup(char *str)
{
pat_debug_enable = 1;
return 0;
}
static inline enum page_cache_mode get_page_memtype(struct page *pg)
{
unsigned long pg_flags = pg->flags & _PGMT_MASK;
if (pg_flags == _PGMT_WB)
return _PAGE_CACHE_MODE_WB;
else if (pg_flags == _PGMT_WC)
return _PAGE_CACHE_MODE_WC;
else if (pg_flags == _PGMT_UC_MINUS)
return _PAGE_CACHE_MODE_UC_MINUS;
else
return _PAGE_CACHE_MODE_WT;
}
static inline void set_page_memtype(struct page *pg,
enum page_cache_mode memtype)
{
unsigned long memtype_flags;
unsigned long old_flags;
unsigned long new_flags;
switch (memtype) {
case _PAGE_CACHE_MODE_WC:
memtype_flags = _PGMT_WC;
break;
case _PAGE_CACHE_MODE_UC_MINUS:
memtype_flags = _PGMT_UC_MINUS;
break;
case _PAGE_CACHE_MODE_WT:
memtype_flags = _PGMT_WT;
break;
case _PAGE_CACHE_MODE_WB:
default:
memtype_flags = _PGMT_WB;
break;
}
do {
old_flags = pg->flags;
new_flags = (old_flags & _PGMT_CLEAR_MASK) | memtype_flags;
} while (cmpxchg(&pg->flags, old_flags, new_flags) != old_flags);
}
static inline enum page_cache_mode get_page_memtype(struct page *pg)
{
return -1;
}
static inline void set_page_memtype(struct page *pg,
enum page_cache_mode memtype)
{
}
static enum page_cache_mode pat_get_cache_mode(unsigned pat_val, char *msg)
{
enum page_cache_mode cache;
char *cache_mode;
switch (pat_val) {
case PAT_UC: cache = CM(UC); cache_mode = "UC "; break;
case PAT_WC: cache = CM(WC); cache_mode = "WC "; break;
case PAT_WT: cache = CM(WT); cache_mode = "WT "; break;
case PAT_WP: cache = CM(WP); cache_mode = "WP "; break;
case PAT_WB: cache = CM(WB); cache_mode = "WB "; break;
case PAT_UC_MINUS: cache = CM(UC_MINUS); cache_mode = "UC- "; break;
default: cache = CM(WB); cache_mode = "WB "; break;
}
memcpy(msg, cache_mode, 4);
return cache;
}
static void __init_cache_modes(u64 pat)
{
enum page_cache_mode cache;
char pat_msg[33];
int i;
pat_msg[32] = 0;
for (i = 7; i >= 0; i--) {
cache = pat_get_cache_mode((pat >> (i * 8)) & 7,
pat_msg + 4 * i);
update_cache_mode_entry(i, cache);
}
pr_info("x86/PAT: Configuration [0-7]: %s\n", pat_msg);
}
static void pat_bsp_init(u64 pat)
{
u64 tmp_pat;
if (!boot_cpu_has(X86_FEATURE_PAT)) {
pat_disable("PAT not supported by CPU.");
return;
}
rdmsrl(MSR_IA32_CR_PAT, tmp_pat);
if (!tmp_pat) {
pat_disable("PAT MSR is 0, disabled.");
return;
}
wrmsrl(MSR_IA32_CR_PAT, pat);
__init_cache_modes(pat);
}
static void pat_ap_init(u64 pat)
{
if (!boot_cpu_has(X86_FEATURE_PAT)) {
panic("x86/PAT: PAT enabled, but not supported by secondary CPU\n");
}
wrmsrl(MSR_IA32_CR_PAT, pat);
}
static void init_cache_modes(void)
{
u64 pat = 0;
static int init_cm_done;
if (init_cm_done)
return;
if (boot_cpu_has(X86_FEATURE_PAT)) {
rdmsrl(MSR_IA32_CR_PAT, pat);
}
if (!pat) {
pat = PAT(0, WB) | PAT(1, WT) | PAT(2, UC_MINUS) | PAT(3, UC) |
PAT(4, WB) | PAT(5, WT) | PAT(6, UC_MINUS) | PAT(7, UC);
}
__init_cache_modes(pat);
init_cm_done = 1;
}
void pat_init(void)
{
u64 pat;
struct cpuinfo_x86 *c = &boot_cpu_data;
if (!pat_enabled()) {
init_cache_modes();
return;
}
if ((c->x86_vendor == X86_VENDOR_INTEL) &&
(((c->x86 == 0x6) && (c->x86_model <= 0xd)) ||
((c->x86 == 0xf) && (c->x86_model <= 0x6)))) {
pat = PAT(0, WB) | PAT(1, WC) | PAT(2, UC_MINUS) | PAT(3, UC) |
PAT(4, WB) | PAT(5, WC) | PAT(6, UC_MINUS) | PAT(7, UC);
} else {
pat = PAT(0, WB) | PAT(1, WC) | PAT(2, UC_MINUS) | PAT(3, UC) |
PAT(4, WB) | PAT(5, WC) | PAT(6, UC_MINUS) | PAT(7, WT);
}
if (!boot_cpu_done) {
pat_bsp_init(pat);
boot_cpu_done = true;
} else {
pat_ap_init(pat);
}
}
static unsigned long pat_x_mtrr_type(u64 start, u64 end,
enum page_cache_mode req_type)
{
if (req_type == _PAGE_CACHE_MODE_WB) {
u8 mtrr_type, uniform;
mtrr_type = mtrr_type_lookup(start, end, &uniform);
if (mtrr_type != MTRR_TYPE_WRBACK)
return _PAGE_CACHE_MODE_UC_MINUS;
return _PAGE_CACHE_MODE_WB;
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
static int reserve_ram_pages_type(u64 start, u64 end,
enum page_cache_mode req_type,
enum page_cache_mode *new_type)
{
struct page *page;
u64 pfn;
if (req_type == _PAGE_CACHE_MODE_WP) {
if (new_type)
*new_type = _PAGE_CACHE_MODE_UC_MINUS;
return -EINVAL;
}
if (req_type == _PAGE_CACHE_MODE_UC) {
WARN_ON_ONCE(1);
req_type = _PAGE_CACHE_MODE_UC_MINUS;
}
for (pfn = (start >> PAGE_SHIFT); pfn < (end >> PAGE_SHIFT); ++pfn) {
enum page_cache_mode type;
page = pfn_to_page(pfn);
type = get_page_memtype(page);
if (type != _PAGE_CACHE_MODE_WB) {
pr_info("x86/PAT: reserve_ram_pages_type failed [mem %#010Lx-%#010Lx], track 0x%x, req 0x%x\n",
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
set_page_memtype(page, _PAGE_CACHE_MODE_WB);
}
return 0;
}
int reserve_memtype(u64 start, u64 end, enum page_cache_mode req_type,
enum page_cache_mode *new_type)
{
struct memtype *new;
enum page_cache_mode actual_type;
int is_range_ram;
int err = 0;
BUG_ON(start >= end);
if (!pat_enabled()) {
if (new_type)
*new_type = req_type;
return 0;
}
if (x86_platform.is_untracked_pat_range(start, end)) {
if (new_type)
*new_type = _PAGE_CACHE_MODE_WB;
return 0;
}
actual_type = pat_x_mtrr_type(start, end, req_type);
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
pr_info("x86/PAT: reserve_memtype failed [mem %#010Lx-%#010Lx], track %s, req %s\n",
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
if (!pat_enabled())
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
if (IS_ERR(entry)) {
pr_info("x86/PAT: %s:%d freeing invalid memtype [mem %#010Lx-%#010Lx]\n",
current->comm, current->pid, start, end - 1);
return -EINVAL;
}
kfree(entry);
dprintk("free_memtype request [mem %#010Lx-%#010Lx]\n", start, end - 1);
return 0;
}
static enum page_cache_mode lookup_memtype(u64 paddr)
{
enum page_cache_mode rettype = _PAGE_CACHE_MODE_WB;
struct memtype *entry;
if (x86_platform.is_untracked_pat_range(paddr, paddr + PAGE_SIZE))
return rettype;
if (pat_pagerange_is_ram(paddr, paddr + PAGE_SIZE)) {
struct page *page;
page = pfn_to_page(paddr >> PAGE_SHIFT);
return get_page_memtype(page);
}
spin_lock(&memtype_lock);
entry = rbt_memtype_lookup(paddr);
if (entry != NULL)
rettype = entry->type;
else
rettype = _PAGE_CACHE_MODE_UC_MINUS;
spin_unlock(&memtype_lock);
return rettype;
}
int io_reserve_memtype(resource_size_t start, resource_size_t end,
enum page_cache_mode *type)
{
resource_size_t size = end - start;
enum page_cache_mode req_type = *type;
enum page_cache_mode new_type;
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
int arch_io_reserve_memtype_wc(resource_size_t start, resource_size_t size)
{
enum page_cache_mode type = _PAGE_CACHE_MODE_WC;
return io_reserve_memtype(start, start + size, &type);
}
void arch_io_free_memtype_wc(resource_size_t start, resource_size_t size)
{
io_free_memtype(start, start + size);
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
if (!pat_enabled())
return 1;
while (cursor < to) {
if (!devmem_is_allowed(pfn))
return 0;
cursor += PAGE_SIZE;
pfn++;
}
return 1;
}
int phys_mem_access_prot_allowed(struct file *file, unsigned long pfn,
unsigned long size, pgprot_t *vma_prot)
{
enum page_cache_mode pcm = _PAGE_CACHE_MODE_WB;
if (!range_is_allowed(pfn, size))
return 0;
if (file->f_flags & O_DSYNC)
pcm = _PAGE_CACHE_MODE_UC_MINUS;
*vma_prot = __pgprot((pgprot_val(*vma_prot) & ~_PAGE_CACHE_MASK) |
cachemode2protval(pcm));
return 1;
}
int kernel_map_sync_memtype(u64 base, unsigned long size,
enum page_cache_mode pcm)
{
unsigned long id_sz;
if (base > __pa(high_memory-1))
return 0;
if (!page_is_ram(base >> PAGE_SHIFT))
return 0;
id_sz = (__pa(high_memory-1) <= base + size) ?
__pa(high_memory) - base :
size;
if (ioremap_change_attr((unsigned long)__va(base), id_sz, pcm) < 0) {
pr_info("x86/PAT: %s:%d ioremap_change_attr failed %s for [mem %#010Lx-%#010Lx]\n",
current->comm, current->pid,
cattr_name(pcm),
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
enum page_cache_mode want_pcm = pgprot2cachemode(*vma_prot);
enum page_cache_mode pcm = want_pcm;
is_ram = pat_pagerange_is_ram(paddr, paddr + size);
if (is_ram) {
if (!pat_enabled())
return 0;
pcm = lookup_memtype(paddr);
if (want_pcm != pcm) {
pr_warn("x86/PAT: %s:%d map pfn RAM range req %s for [mem %#010Lx-%#010Lx], got %s\n",
current->comm, current->pid,
cattr_name(want_pcm),
(unsigned long long)paddr,
(unsigned long long)(paddr + size - 1),
cattr_name(pcm));
*vma_prot = __pgprot((pgprot_val(*vma_prot) &
(~_PAGE_CACHE_MASK)) |
cachemode2protval(pcm));
}
return 0;
}
ret = reserve_memtype(paddr, paddr + size, want_pcm, &pcm);
if (ret)
return ret;
if (pcm != want_pcm) {
if (strict_prot ||
!is_new_memtype_allowed(paddr, size, want_pcm, pcm)) {
free_memtype(paddr, paddr + size);
pr_err("x86/PAT: %s:%d map pfn expected mapping type %s for [mem %#010Lx-%#010Lx], got %s\n",
current->comm, current->pid,
cattr_name(want_pcm),
(unsigned long long)paddr,
(unsigned long long)(paddr + size - 1),
cattr_name(pcm));
return -EINVAL;
}
*vma_prot = __pgprot((pgprot_val(*vma_prot) &
(~_PAGE_CACHE_MASK)) |
cachemode2protval(pcm));
}
if (kernel_map_sync_memtype(paddr, size, pcm) < 0) {
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
enum page_cache_mode pcm;
if (!vma || (addr == vma->vm_start
&& size == (vma->vm_end - vma->vm_start))) {
int ret;
ret = reserve_pfn_range(paddr, size, prot, 0);
if (ret == 0 && vma)
vma->vm_flags |= VM_PAT;
return ret;
}
if (!pat_enabled())
return 0;
pcm = lookup_memtype(paddr);
while (size > PAGE_SIZE) {
size -= PAGE_SIZE;
paddr += PAGE_SIZE;
if (pcm != lookup_memtype(paddr))
return -EINVAL;
}
*prot = __pgprot((pgprot_val(*prot) & (~_PAGE_CACHE_MASK)) |
cachemode2protval(pcm));
return 0;
}
int track_pfn_insert(struct vm_area_struct *vma, pgprot_t *prot,
pfn_t pfn)
{
enum page_cache_mode pcm;
if (!pat_enabled())
return 0;
pcm = lookup_memtype(pfn_t_to_phys(pfn));
*prot = __pgprot((pgprot_val(*prot) & (~_PAGE_CACHE_MASK)) |
cachemode2protval(pcm));
return 0;
}
void untrack_pfn(struct vm_area_struct *vma, unsigned long pfn,
unsigned long size)
{
resource_size_t paddr;
unsigned long prot;
if (vma && !(vma->vm_flags & VM_PAT))
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
if (vma)
vma->vm_flags &= ~VM_PAT;
}
void untrack_pfn_moved(struct vm_area_struct *vma)
{
vma->vm_flags &= ~VM_PAT;
}
pgprot_t pgprot_writecombine(pgprot_t prot)
{
return __pgprot(pgprot_val(prot) |
cachemode2protval(_PAGE_CACHE_MODE_WC));
}
pgprot_t pgprot_writethrough(pgprot_t prot)
{
return __pgprot(pgprot_val(prot) |
cachemode2protval(_PAGE_CACHE_MODE_WT));
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
seq_puts(seq, "PAT memtype list:\n");
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
if (pat_enabled()) {
debugfs_create_file("pat_memtype_list", S_IRUSR,
arch_debugfs_dir, NULL, &memtype_fops);
}
return 0;
}
