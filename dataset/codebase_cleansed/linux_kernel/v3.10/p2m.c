static inline unsigned p2m_top_index(unsigned long pfn)
{
BUG_ON(pfn >= MAX_P2M_PFN);
return pfn / (P2M_MID_PER_PAGE * P2M_PER_PAGE);
}
static inline unsigned p2m_mid_index(unsigned long pfn)
{
return (pfn / P2M_PER_PAGE) % P2M_MID_PER_PAGE;
}
static inline unsigned p2m_index(unsigned long pfn)
{
return pfn % P2M_PER_PAGE;
}
static void p2m_top_init(unsigned long ***top)
{
unsigned i;
for (i = 0; i < P2M_TOP_PER_PAGE; i++)
top[i] = p2m_mid_missing;
}
static void p2m_top_mfn_init(unsigned long *top)
{
unsigned i;
for (i = 0; i < P2M_TOP_PER_PAGE; i++)
top[i] = virt_to_mfn(p2m_mid_missing_mfn);
}
static void p2m_top_mfn_p_init(unsigned long **top)
{
unsigned i;
for (i = 0; i < P2M_TOP_PER_PAGE; i++)
top[i] = p2m_mid_missing_mfn;
}
static void p2m_mid_init(unsigned long **mid)
{
unsigned i;
for (i = 0; i < P2M_MID_PER_PAGE; i++)
mid[i] = p2m_missing;
}
static void p2m_mid_mfn_init(unsigned long *mid)
{
unsigned i;
for (i = 0; i < P2M_MID_PER_PAGE; i++)
mid[i] = virt_to_mfn(p2m_missing);
}
static void p2m_init(unsigned long *p2m)
{
unsigned i;
for (i = 0; i < P2M_MID_PER_PAGE; i++)
p2m[i] = INVALID_P2M_ENTRY;
}
void __ref xen_build_mfn_list_list(void)
{
unsigned long pfn;
if (p2m_top_mfn == NULL) {
p2m_mid_missing_mfn = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_mid_mfn_init(p2m_mid_missing_mfn);
p2m_top_mfn_p = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_top_mfn_p_init(p2m_top_mfn_p);
p2m_top_mfn = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_top_mfn_init(p2m_top_mfn);
} else {
p2m_mid_mfn_init(p2m_mid_missing_mfn);
}
for (pfn = 0; pfn < xen_max_p2m_pfn; pfn += P2M_PER_PAGE) {
unsigned topidx = p2m_top_index(pfn);
unsigned mididx = p2m_mid_index(pfn);
unsigned long **mid;
unsigned long *mid_mfn_p;
mid = p2m_top[topidx];
mid_mfn_p = p2m_top_mfn_p[topidx];
if (mid == p2m_mid_missing) {
BUG_ON(mididx);
BUG_ON(mid_mfn_p != p2m_mid_missing_mfn);
p2m_top_mfn[topidx] = virt_to_mfn(p2m_mid_missing_mfn);
pfn += (P2M_MID_PER_PAGE - 1) * P2M_PER_PAGE;
continue;
}
if (mid_mfn_p == p2m_mid_missing_mfn) {
mid_mfn_p = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_mid_mfn_init(mid_mfn_p);
p2m_top_mfn_p[topidx] = mid_mfn_p;
}
p2m_top_mfn[topidx] = virt_to_mfn(mid_mfn_p);
mid_mfn_p[mididx] = virt_to_mfn(mid[mididx]);
}
}
void xen_setup_mfn_list_list(void)
{
BUG_ON(HYPERVISOR_shared_info == &xen_dummy_shared_info);
HYPERVISOR_shared_info->arch.pfn_to_mfn_frame_list_list =
virt_to_mfn(p2m_top_mfn);
HYPERVISOR_shared_info->arch.max_pfn = xen_max_p2m_pfn;
}
void __init xen_build_dynamic_phys_to_machine(void)
{
unsigned long *mfn_list = (unsigned long *)xen_start_info->mfn_list;
unsigned long max_pfn = min(MAX_DOMAIN_PAGES, xen_start_info->nr_pages);
unsigned long pfn;
xen_max_p2m_pfn = max_pfn;
p2m_missing = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_init(p2m_missing);
p2m_mid_missing = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_mid_init(p2m_mid_missing);
p2m_top = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_top_init(p2m_top);
p2m_identity = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_init(p2m_identity);
for (pfn = 0; pfn < max_pfn; pfn += P2M_PER_PAGE) {
unsigned topidx = p2m_top_index(pfn);
unsigned mididx = p2m_mid_index(pfn);
if (p2m_top[topidx] == p2m_mid_missing) {
unsigned long **mid = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_mid_init(mid);
p2m_top[topidx] = mid;
}
if (unlikely(pfn + P2M_PER_PAGE > max_pfn)) {
unsigned long p2midx;
p2midx = max_pfn % P2M_PER_PAGE;
for ( ; p2midx < P2M_PER_PAGE; p2midx++)
mfn_list[pfn + p2midx] = INVALID_P2M_ENTRY;
}
p2m_top[topidx][mididx] = &mfn_list[pfn];
}
m2p_override_init();
}
unsigned long __init xen_revector_p2m_tree(void)
{
unsigned long va_start;
unsigned long va_end;
unsigned long pfn;
unsigned long pfn_free = 0;
unsigned long *mfn_list = NULL;
unsigned long size;
va_start = xen_start_info->mfn_list;
size = PAGE_ALIGN(xen_start_info->nr_pages * sizeof(unsigned long));
va_end = va_start + size;
if (va_start <= __START_KERNEL_map && va_start >= __PAGE_OFFSET)
return 0;
mfn_list = alloc_bootmem_align(size, PAGE_SIZE);
if (!mfn_list) {
pr_warn("Could not allocate space for a new P2M tree!\n");
return xen_start_info->mfn_list;
}
memset(mfn_list, 0xFF, size);
for (pfn = 0; pfn < ALIGN(MAX_DOMAIN_PAGES, P2M_PER_PAGE); pfn += P2M_PER_PAGE) {
unsigned topidx = p2m_top_index(pfn);
unsigned mididx;
unsigned long *mid_p;
if (!p2m_top[topidx])
continue;
if (p2m_top[topidx] == p2m_mid_missing)
continue;
mididx = p2m_mid_index(pfn);
mid_p = p2m_top[topidx][mididx];
if (!mid_p)
continue;
if ((mid_p == p2m_missing) || (mid_p == p2m_identity))
continue;
if ((unsigned long)mid_p == INVALID_P2M_ENTRY)
continue;
if (mid_p >= (unsigned long *)va_start && mid_p <= (unsigned long *)va_end) {
unsigned long *new;
if (pfn_free > (size / sizeof(unsigned long))) {
WARN(1, "Only allocated for %ld pages, but we want %ld!\n",
size / sizeof(unsigned long), pfn_free);
return 0;
}
new = &mfn_list[pfn_free];
copy_page(new, mid_p);
p2m_top[topidx][mididx] = &mfn_list[pfn_free];
p2m_top_mfn_p[topidx][mididx] = virt_to_mfn(&mfn_list[pfn_free]);
pfn_free += P2M_PER_PAGE;
}
}
return (unsigned long)mfn_list;
}
unsigned long __init xen_revector_p2m_tree(void)
{
return 0;
}
unsigned long get_phys_to_machine(unsigned long pfn)
{
unsigned topidx, mididx, idx;
if (unlikely(pfn >= MAX_P2M_PFN))
return INVALID_P2M_ENTRY;
topidx = p2m_top_index(pfn);
mididx = p2m_mid_index(pfn);
idx = p2m_index(pfn);
if (p2m_top[topidx][mididx] == p2m_identity)
return IDENTITY_FRAME(pfn);
return p2m_top[topidx][mididx][idx];
}
static void *alloc_p2m_page(void)
{
return (void *)__get_free_page(GFP_KERNEL | __GFP_REPEAT);
}
static void free_p2m_page(void *p)
{
free_page((unsigned long)p);
}
static bool alloc_p2m(unsigned long pfn)
{
unsigned topidx, mididx;
unsigned long ***top_p, **mid;
unsigned long *top_mfn_p, *mid_mfn;
topidx = p2m_top_index(pfn);
mididx = p2m_mid_index(pfn);
top_p = &p2m_top[topidx];
mid = *top_p;
if (mid == p2m_mid_missing) {
mid = alloc_p2m_page();
if (!mid)
return false;
p2m_mid_init(mid);
if (cmpxchg(top_p, p2m_mid_missing, mid) != p2m_mid_missing)
free_p2m_page(mid);
}
top_mfn_p = &p2m_top_mfn[topidx];
mid_mfn = p2m_top_mfn_p[topidx];
BUG_ON(virt_to_mfn(mid_mfn) != *top_mfn_p);
if (mid_mfn == p2m_mid_missing_mfn) {
unsigned long missing_mfn;
unsigned long mid_mfn_mfn;
mid_mfn = alloc_p2m_page();
if (!mid_mfn)
return false;
p2m_mid_mfn_init(mid_mfn);
missing_mfn = virt_to_mfn(p2m_mid_missing_mfn);
mid_mfn_mfn = virt_to_mfn(mid_mfn);
if (cmpxchg(top_mfn_p, missing_mfn, mid_mfn_mfn) != missing_mfn)
free_p2m_page(mid_mfn);
else
p2m_top_mfn_p[topidx] = mid_mfn;
}
if (p2m_top[topidx][mididx] == p2m_identity ||
p2m_top[topidx][mididx] == p2m_missing) {
unsigned long *p2m;
unsigned long *p2m_orig = p2m_top[topidx][mididx];
p2m = alloc_p2m_page();
if (!p2m)
return false;
p2m_init(p2m);
if (cmpxchg(&mid[mididx], p2m_orig, p2m) != p2m_orig)
free_p2m_page(p2m);
else
mid_mfn[mididx] = virt_to_mfn(p2m);
}
return true;
}
static bool __init early_alloc_p2m_middle(unsigned long pfn, bool check_boundary)
{
unsigned topidx, mididx, idx;
unsigned long *p2m;
unsigned long *mid_mfn_p;
topidx = p2m_top_index(pfn);
mididx = p2m_mid_index(pfn);
idx = p2m_index(pfn);
if (!idx && check_boundary)
return false;
WARN(p2m_top[topidx][mididx] == p2m_identity,
"P2M[%d][%d] == IDENTITY, should be MISSING (or alloced)!\n",
topidx, mididx);
if (p2m_top[topidx][mididx] != p2m_missing)
return false;
p2m = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_init(p2m);
p2m_top[topidx][mididx] = p2m;
mid_mfn_p = p2m_top_mfn_p[topidx];
WARN(mid_mfn_p[mididx] != virt_to_mfn(p2m_missing),
"P2M_TOP_P[%d][%d] != MFN of p2m_missing!\n",
topidx, mididx);
mid_mfn_p[mididx] = virt_to_mfn(p2m);
return true;
}
static bool __init early_alloc_p2m(unsigned long pfn)
{
unsigned topidx = p2m_top_index(pfn);
unsigned long *mid_mfn_p;
unsigned long **mid;
mid = p2m_top[topidx];
mid_mfn_p = p2m_top_mfn_p[topidx];
if (mid == p2m_mid_missing) {
mid = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_mid_init(mid);
p2m_top[topidx] = mid;
BUG_ON(mid_mfn_p != p2m_mid_missing_mfn);
}
if (mid_mfn_p == p2m_mid_missing_mfn) {
mid_mfn_p = extend_brk(PAGE_SIZE, PAGE_SIZE);
p2m_mid_mfn_init(mid_mfn_p);
p2m_top_mfn_p[topidx] = mid_mfn_p;
p2m_top_mfn[topidx] = virt_to_mfn(mid_mfn_p);
}
return true;
}
bool __init early_can_reuse_p2m_middle(unsigned long set_pfn, unsigned long set_mfn)
{
unsigned topidx;
unsigned mididx;
unsigned ident_pfns;
unsigned inv_pfns;
unsigned long *p2m;
unsigned long *mid_mfn_p;
unsigned idx;
unsigned long pfn;
if (p2m_index(set_pfn))
return false;
for (pfn = 0; pfn < MAX_DOMAIN_PAGES; pfn += P2M_PER_PAGE) {
topidx = p2m_top_index(pfn);
if (!p2m_top[topidx])
continue;
if (p2m_top[topidx] == p2m_mid_missing)
continue;
mididx = p2m_mid_index(pfn);
p2m = p2m_top[topidx][mididx];
if (!p2m)
continue;
if ((p2m == p2m_missing) || (p2m == p2m_identity))
continue;
if ((unsigned long)p2m == INVALID_P2M_ENTRY)
continue;
ident_pfns = 0;
inv_pfns = 0;
for (idx = 0; idx < P2M_PER_PAGE; idx++) {
if (p2m[idx] == IDENTITY_FRAME(pfn + idx))
ident_pfns++;
else if (p2m[idx] == INVALID_P2M_ENTRY)
inv_pfns++;
else
break;
}
if ((ident_pfns == P2M_PER_PAGE) || (inv_pfns == P2M_PER_PAGE))
goto found;
}
return false;
found:
p2m_top[topidx][mididx] = (ident_pfns ? p2m_identity : p2m_missing);
mid_mfn_p = p2m_top_mfn_p[topidx];
mid_mfn_p[mididx] = virt_to_mfn(p2m_missing);
topidx = p2m_top_index(set_pfn);
mididx = p2m_mid_index(set_pfn);
if (WARN_ON(p2m_top[topidx] == p2m_mid_missing))
early_alloc_p2m(set_pfn);
if (WARN_ON(p2m_top[topidx][mididx] != p2m_missing))
return false;
p2m_init(p2m);
p2m_top[topidx][mididx] = p2m;
mid_mfn_p = p2m_top_mfn_p[topidx];
mid_mfn_p[mididx] = virt_to_mfn(p2m);
return true;
}
bool __init early_set_phys_to_machine(unsigned long pfn, unsigned long mfn)
{
if (unlikely(!__set_phys_to_machine(pfn, mfn))) {
if (!early_alloc_p2m(pfn))
return false;
if (early_can_reuse_p2m_middle(pfn, mfn))
return __set_phys_to_machine(pfn, mfn);
if (!early_alloc_p2m_middle(pfn, false ))
return false;
if (!__set_phys_to_machine(pfn, mfn))
return false;
}
return true;
}
unsigned long __init set_phys_range_identity(unsigned long pfn_s,
unsigned long pfn_e)
{
unsigned long pfn;
if (unlikely(pfn_s >= MAX_P2M_PFN || pfn_e >= MAX_P2M_PFN))
return 0;
if (unlikely(xen_feature(XENFEAT_auto_translated_physmap)))
return pfn_e - pfn_s;
if (pfn_s > pfn_e)
return 0;
for (pfn = (pfn_s & ~(P2M_MID_PER_PAGE * P2M_PER_PAGE - 1));
pfn < ALIGN(pfn_e, (P2M_MID_PER_PAGE * P2M_PER_PAGE));
pfn += P2M_MID_PER_PAGE * P2M_PER_PAGE)
{
WARN_ON(!early_alloc_p2m(pfn));
}
early_alloc_p2m_middle(pfn_s, true);
early_alloc_p2m_middle(pfn_e, true);
for (pfn = pfn_s; pfn < pfn_e; pfn++)
if (!__set_phys_to_machine(pfn, IDENTITY_FRAME(pfn)))
break;
if (!WARN((pfn - pfn_s) != (pfn_e - pfn_s),
"Identity mapping failed. We are %ld short of 1-1 mappings!\n",
(pfn_e - pfn_s) - (pfn - pfn_s)))
printk(KERN_DEBUG "1-1 mapping on %lx->%lx\n", pfn_s, pfn);
return pfn - pfn_s;
}
bool __set_phys_to_machine(unsigned long pfn, unsigned long mfn)
{
unsigned topidx, mididx, idx;
if (unlikely(xen_feature(XENFEAT_auto_translated_physmap))) {
BUG_ON(pfn != mfn && mfn != INVALID_P2M_ENTRY);
return true;
}
if (unlikely(pfn >= MAX_P2M_PFN)) {
BUG_ON(mfn != INVALID_P2M_ENTRY);
return true;
}
topidx = p2m_top_index(pfn);
mididx = p2m_mid_index(pfn);
idx = p2m_index(pfn);
if (mfn != INVALID_P2M_ENTRY && (mfn & IDENTITY_FRAME_BIT)) {
if (p2m_top[topidx][mididx] == p2m_identity)
return true;
if (p2m_top[topidx][mididx] == p2m_missing) {
WARN_ON(cmpxchg(&p2m_top[topidx][mididx], p2m_missing,
p2m_identity) != p2m_missing);
return true;
}
}
if (p2m_top[topidx][mididx] == p2m_missing)
return mfn == INVALID_P2M_ENTRY;
p2m_top[topidx][mididx][idx] = mfn;
return true;
}
bool set_phys_to_machine(unsigned long pfn, unsigned long mfn)
{
if (unlikely(!__set_phys_to_machine(pfn, mfn))) {
if (!alloc_p2m(pfn))
return false;
if (!__set_phys_to_machine(pfn, mfn))
return false;
}
return true;
}
static void __init m2p_override_init(void)
{
unsigned i;
m2p_overrides = extend_brk(sizeof(*m2p_overrides) * M2P_OVERRIDE_HASH,
sizeof(unsigned long));
for (i = 0; i < M2P_OVERRIDE_HASH; i++)
INIT_LIST_HEAD(&m2p_overrides[i]);
}
static unsigned long mfn_hash(unsigned long mfn)
{
return hash_long(mfn, M2P_OVERRIDE_HASH_SHIFT);
}
int m2p_add_override(unsigned long mfn, struct page *page,
struct gnttab_map_grant_ref *kmap_op)
{
unsigned long flags;
unsigned long pfn;
unsigned long uninitialized_var(address);
unsigned level;
pte_t *ptep = NULL;
int ret = 0;
pfn = page_to_pfn(page);
if (!PageHighMem(page)) {
address = (unsigned long)__va(pfn << PAGE_SHIFT);
ptep = lookup_address(address, &level);
if (WARN(ptep == NULL || level != PG_LEVEL_4K,
"m2p_add_override: pfn %lx not mapped", pfn))
return -EINVAL;
}
WARN_ON(PagePrivate(page));
SetPagePrivate(page);
set_page_private(page, mfn);
page->index = pfn_to_mfn(pfn);
if (unlikely(!set_phys_to_machine(pfn, FOREIGN_FRAME(mfn))))
return -ENOMEM;
if (kmap_op != NULL) {
if (!PageHighMem(page)) {
struct multicall_space mcs =
xen_mc_entry(sizeof(*kmap_op));
MULTI_grant_table_op(mcs.mc,
GNTTABOP_map_grant_ref, kmap_op, 1);
xen_mc_issue(PARAVIRT_LAZY_MMU);
}
}
spin_lock_irqsave(&m2p_override_lock, flags);
list_add(&page->lru, &m2p_overrides[mfn_hash(mfn)]);
spin_unlock_irqrestore(&m2p_override_lock, flags);
ret = __get_user(pfn, &machine_to_phys_mapping[mfn]);
if (ret == 0 && get_phys_to_machine(pfn) == mfn)
set_phys_to_machine(pfn, FOREIGN_FRAME(mfn));
return 0;
}
int m2p_remove_override(struct page *page,
struct gnttab_map_grant_ref *kmap_op)
{
unsigned long flags;
unsigned long mfn;
unsigned long pfn;
unsigned long uninitialized_var(address);
unsigned level;
pte_t *ptep = NULL;
int ret = 0;
pfn = page_to_pfn(page);
mfn = get_phys_to_machine(pfn);
if (mfn == INVALID_P2M_ENTRY || !(mfn & FOREIGN_FRAME_BIT))
return -EINVAL;
if (!PageHighMem(page)) {
address = (unsigned long)__va(pfn << PAGE_SHIFT);
ptep = lookup_address(address, &level);
if (WARN(ptep == NULL || level != PG_LEVEL_4K,
"m2p_remove_override: pfn %lx not mapped", pfn))
return -EINVAL;
}
spin_lock_irqsave(&m2p_override_lock, flags);
list_del(&page->lru);
spin_unlock_irqrestore(&m2p_override_lock, flags);
WARN_ON(!PagePrivate(page));
ClearPagePrivate(page);
set_phys_to_machine(pfn, page->index);
if (kmap_op != NULL) {
if (!PageHighMem(page)) {
struct multicall_space mcs;
struct gnttab_unmap_grant_ref *unmap_op;
if (kmap_op->handle == -1)
xen_mc_flush();
if (kmap_op->handle == GNTST_general_error) {
printk(KERN_WARNING "m2p_remove_override: "
"pfn %lx mfn %lx, failed to modify kernel mappings",
pfn, mfn);
return -1;
}
mcs = xen_mc_entry(
sizeof(struct gnttab_unmap_grant_ref));
unmap_op = mcs.args;
unmap_op->host_addr = kmap_op->host_addr;
unmap_op->handle = kmap_op->handle;
unmap_op->dev_bus_addr = 0;
MULTI_grant_table_op(mcs.mc,
GNTTABOP_unmap_grant_ref, unmap_op, 1);
xen_mc_issue(PARAVIRT_LAZY_MMU);
set_pte_at(&init_mm, address, ptep,
pfn_pte(pfn, PAGE_KERNEL));
__flush_tlb_single(address);
kmap_op->host_addr = 0;
}
}
mfn &= ~FOREIGN_FRAME_BIT;
ret = __get_user(pfn, &machine_to_phys_mapping[mfn]);
if (ret == 0 && get_phys_to_machine(pfn) == FOREIGN_FRAME(mfn) &&
m2p_find_override(mfn) == NULL)
set_phys_to_machine(pfn, mfn);
return 0;
}
struct page *m2p_find_override(unsigned long mfn)
{
unsigned long flags;
struct list_head *bucket = &m2p_overrides[mfn_hash(mfn)];
struct page *p, *ret;
ret = NULL;
spin_lock_irqsave(&m2p_override_lock, flags);
list_for_each_entry(p, bucket, lru) {
if (page_private(p) == mfn) {
ret = p;
break;
}
}
spin_unlock_irqrestore(&m2p_override_lock, flags);
return ret;
}
unsigned long m2p_find_override_pfn(unsigned long mfn, unsigned long pfn)
{
struct page *p = m2p_find_override(mfn);
unsigned long ret = pfn;
if (p)
ret = page_to_pfn(p);
return ret;
}
static int p2m_dump_show(struct seq_file *m, void *v)
{
static const char * const level_name[] = { "top", "middle",
"entry", "abnormal", "error"};
#define TYPE_IDENTITY 0
#define TYPE_MISSING 1
#define TYPE_PFN 2
#define TYPE_UNKNOWN 3
static const char * const type_name[] = {
[TYPE_IDENTITY] = "identity",
[TYPE_MISSING] = "missing",
[TYPE_PFN] = "pfn",
[TYPE_UNKNOWN] = "abnormal"};
unsigned long pfn, prev_pfn_type = 0, prev_pfn_level = 0;
unsigned int uninitialized_var(prev_level);
unsigned int uninitialized_var(prev_type);
if (!p2m_top)
return 0;
for (pfn = 0; pfn < MAX_DOMAIN_PAGES; pfn++) {
unsigned topidx = p2m_top_index(pfn);
unsigned mididx = p2m_mid_index(pfn);
unsigned idx = p2m_index(pfn);
unsigned lvl, type;
lvl = 4;
type = TYPE_UNKNOWN;
if (p2m_top[topidx] == p2m_mid_missing) {
lvl = 0; type = TYPE_MISSING;
} else if (p2m_top[topidx] == NULL) {
lvl = 0; type = TYPE_UNKNOWN;
} else if (p2m_top[topidx][mididx] == NULL) {
lvl = 1; type = TYPE_UNKNOWN;
} else if (p2m_top[topidx][mididx] == p2m_identity) {
lvl = 1; type = TYPE_IDENTITY;
} else if (p2m_top[topidx][mididx] == p2m_missing) {
lvl = 1; type = TYPE_MISSING;
} else if (p2m_top[topidx][mididx][idx] == 0) {
lvl = 2; type = TYPE_UNKNOWN;
} else if (p2m_top[topidx][mididx][idx] == IDENTITY_FRAME(pfn)) {
lvl = 2; type = TYPE_IDENTITY;
} else if (p2m_top[topidx][mididx][idx] == INVALID_P2M_ENTRY) {
lvl = 2; type = TYPE_MISSING;
} else if (p2m_top[topidx][mididx][idx] == pfn) {
lvl = 2; type = TYPE_PFN;
} else if (p2m_top[topidx][mididx][idx] != pfn) {
lvl = 2; type = TYPE_PFN;
}
if (pfn == 0) {
prev_level = lvl;
prev_type = type;
}
if (pfn == MAX_DOMAIN_PAGES-1) {
lvl = 3;
type = TYPE_UNKNOWN;
}
if (prev_type != type) {
seq_printf(m, " [0x%lx->0x%lx] %s\n",
prev_pfn_type, pfn, type_name[prev_type]);
prev_pfn_type = pfn;
prev_type = type;
}
if (prev_level != lvl) {
seq_printf(m, " [0x%lx->0x%lx] level %s\n",
prev_pfn_level, pfn, level_name[prev_level]);
prev_pfn_level = pfn;
prev_level = lvl;
}
}
return 0;
#undef TYPE_IDENTITY
#undef TYPE_MISSING
#undef TYPE_PFN
#undef TYPE_UNKNOWN
}
static int p2m_dump_open(struct inode *inode, struct file *filp)
{
return single_open(filp, p2m_dump_show, NULL);
}
static int __init xen_p2m_debugfs(void)
{
struct dentry *d_xen = xen_init_debugfs();
if (d_xen == NULL)
return -ENOMEM;
d_mmu_debug = debugfs_create_dir("mmu", d_xen);
debugfs_create_file("p2m", 0600, d_mmu_debug, NULL, &p2m_dump_fops);
return 0;
}
