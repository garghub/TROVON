static struct gmap *gmap_alloc(unsigned long limit)
{
struct gmap *gmap;
struct page *page;
unsigned long *table;
unsigned long etype, atype;
if (limit < (1UL << 31)) {
limit = (1UL << 31) - 1;
atype = _ASCE_TYPE_SEGMENT;
etype = _SEGMENT_ENTRY_EMPTY;
} else if (limit < (1UL << 42)) {
limit = (1UL << 42) - 1;
atype = _ASCE_TYPE_REGION3;
etype = _REGION3_ENTRY_EMPTY;
} else if (limit < (1UL << 53)) {
limit = (1UL << 53) - 1;
atype = _ASCE_TYPE_REGION2;
etype = _REGION2_ENTRY_EMPTY;
} else {
limit = -1UL;
atype = _ASCE_TYPE_REGION1;
etype = _REGION1_ENTRY_EMPTY;
}
gmap = kzalloc(sizeof(struct gmap), GFP_KERNEL);
if (!gmap)
goto out;
INIT_LIST_HEAD(&gmap->crst_list);
INIT_LIST_HEAD(&gmap->children);
INIT_LIST_HEAD(&gmap->pt_list);
INIT_RADIX_TREE(&gmap->guest_to_host, GFP_KERNEL);
INIT_RADIX_TREE(&gmap->host_to_guest, GFP_ATOMIC);
INIT_RADIX_TREE(&gmap->host_to_rmap, GFP_ATOMIC);
spin_lock_init(&gmap->guest_table_lock);
spin_lock_init(&gmap->shadow_lock);
atomic_set(&gmap->ref_count, 1);
page = alloc_pages(GFP_KERNEL, 2);
if (!page)
goto out_free;
page->index = 0;
list_add(&page->lru, &gmap->crst_list);
table = (unsigned long *) page_to_phys(page);
crst_table_init(table, etype);
gmap->table = table;
gmap->asce = atype | _ASCE_TABLE_LENGTH |
_ASCE_USER_BITS | __pa(table);
gmap->asce_end = limit;
return gmap;
out_free:
kfree(gmap);
out:
return NULL;
}
struct gmap *gmap_create(struct mm_struct *mm, unsigned long limit)
{
struct gmap *gmap;
gmap = gmap_alloc(limit);
if (!gmap)
return NULL;
gmap->mm = mm;
spin_lock(&mm->context.gmap_lock);
list_add_rcu(&gmap->list, &mm->context.gmap_list);
spin_unlock(&mm->context.gmap_lock);
return gmap;
}
static void gmap_flush_tlb(struct gmap *gmap)
{
if (MACHINE_HAS_IDTE)
__tlb_flush_idte(gmap->asce);
else
__tlb_flush_global();
}
static void gmap_radix_tree_free(struct radix_tree_root *root)
{
struct radix_tree_iter iter;
unsigned long indices[16];
unsigned long index;
void **slot;
int i, nr;
index = 0;
do {
nr = 0;
radix_tree_for_each_slot(slot, root, &iter, index) {
indices[nr] = iter.index;
if (++nr == 16)
break;
}
for (i = 0; i < nr; i++) {
index = indices[i];
radix_tree_delete(root, index);
}
} while (nr > 0);
}
static void gmap_rmap_radix_tree_free(struct radix_tree_root *root)
{
struct gmap_rmap *rmap, *rnext, *head;
struct radix_tree_iter iter;
unsigned long indices[16];
unsigned long index;
void **slot;
int i, nr;
index = 0;
do {
nr = 0;
radix_tree_for_each_slot(slot, root, &iter, index) {
indices[nr] = iter.index;
if (++nr == 16)
break;
}
for (i = 0; i < nr; i++) {
index = indices[i];
head = radix_tree_delete(root, index);
gmap_for_each_rmap_safe(rmap, rnext, head)
kfree(rmap);
}
} while (nr > 0);
}
static void gmap_free(struct gmap *gmap)
{
struct page *page, *next;
if (!(gmap_is_shadow(gmap) && gmap->removed))
gmap_flush_tlb(gmap);
list_for_each_entry_safe(page, next, &gmap->crst_list, lru)
__free_pages(page, 2);
gmap_radix_tree_free(&gmap->guest_to_host);
gmap_radix_tree_free(&gmap->host_to_guest);
if (gmap_is_shadow(gmap)) {
list_for_each_entry_safe(page, next, &gmap->pt_list, lru)
page_table_free_pgste(page);
gmap_rmap_radix_tree_free(&gmap->host_to_rmap);
gmap_put(gmap->parent);
}
kfree(gmap);
}
struct gmap *gmap_get(struct gmap *gmap)
{
atomic_inc(&gmap->ref_count);
return gmap;
}
void gmap_put(struct gmap *gmap)
{
if (atomic_dec_return(&gmap->ref_count) == 0)
gmap_free(gmap);
}
void gmap_remove(struct gmap *gmap)
{
struct gmap *sg, *next;
if (!list_empty(&gmap->children)) {
spin_lock(&gmap->shadow_lock);
list_for_each_entry_safe(sg, next, &gmap->children, list) {
list_del(&sg->list);
gmap_put(sg);
}
spin_unlock(&gmap->shadow_lock);
}
spin_lock(&gmap->mm->context.gmap_lock);
list_del_rcu(&gmap->list);
spin_unlock(&gmap->mm->context.gmap_lock);
synchronize_rcu();
gmap_put(gmap);
}
void gmap_enable(struct gmap *gmap)
{
S390_lowcore.gmap = (unsigned long) gmap;
}
void gmap_disable(struct gmap *gmap)
{
S390_lowcore.gmap = 0UL;
}
struct gmap *gmap_get_enabled(void)
{
return (struct gmap *) S390_lowcore.gmap;
}
static int gmap_alloc_table(struct gmap *gmap, unsigned long *table,
unsigned long init, unsigned long gaddr)
{
struct page *page;
unsigned long *new;
page = alloc_pages(GFP_KERNEL, 2);
if (!page)
return -ENOMEM;
new = (unsigned long *) page_to_phys(page);
crst_table_init(new, init);
spin_lock(&gmap->guest_table_lock);
if (*table & _REGION_ENTRY_INVALID) {
list_add(&page->lru, &gmap->crst_list);
*table = (unsigned long) new | _REGION_ENTRY_LENGTH |
(*table & _REGION_ENTRY_TYPE_MASK);
page->index = gaddr;
page = NULL;
}
spin_unlock(&gmap->guest_table_lock);
if (page)
__free_pages(page, 2);
return 0;
}
static unsigned long __gmap_segment_gaddr(unsigned long *entry)
{
struct page *page;
unsigned long offset, mask;
offset = (unsigned long) entry / sizeof(unsigned long);
offset = (offset & (PTRS_PER_PMD - 1)) * PMD_SIZE;
mask = ~(PTRS_PER_PMD * sizeof(pmd_t) - 1);
page = virt_to_page((void *)((unsigned long) entry & mask));
return page->index + offset;
}
static int __gmap_unlink_by_vmaddr(struct gmap *gmap, unsigned long vmaddr)
{
unsigned long *entry;
int flush = 0;
BUG_ON(gmap_is_shadow(gmap));
spin_lock(&gmap->guest_table_lock);
entry = radix_tree_delete(&gmap->host_to_guest, vmaddr >> PMD_SHIFT);
if (entry) {
flush = (*entry != _SEGMENT_ENTRY_INVALID);
*entry = _SEGMENT_ENTRY_INVALID;
}
spin_unlock(&gmap->guest_table_lock);
return flush;
}
static int __gmap_unmap_by_gaddr(struct gmap *gmap, unsigned long gaddr)
{
unsigned long vmaddr;
vmaddr = (unsigned long) radix_tree_delete(&gmap->guest_to_host,
gaddr >> PMD_SHIFT);
return vmaddr ? __gmap_unlink_by_vmaddr(gmap, vmaddr) : 0;
}
int gmap_unmap_segment(struct gmap *gmap, unsigned long to, unsigned long len)
{
unsigned long off;
int flush;
BUG_ON(gmap_is_shadow(gmap));
if ((to | len) & (PMD_SIZE - 1))
return -EINVAL;
if (len == 0 || to + len < to)
return -EINVAL;
flush = 0;
down_write(&gmap->mm->mmap_sem);
for (off = 0; off < len; off += PMD_SIZE)
flush |= __gmap_unmap_by_gaddr(gmap, to + off);
up_write(&gmap->mm->mmap_sem);
if (flush)
gmap_flush_tlb(gmap);
return 0;
}
int gmap_map_segment(struct gmap *gmap, unsigned long from,
unsigned long to, unsigned long len)
{
unsigned long off;
int flush;
BUG_ON(gmap_is_shadow(gmap));
if ((from | to | len) & (PMD_SIZE - 1))
return -EINVAL;
if (len == 0 || from + len < from || to + len < to ||
from + len - 1 > TASK_MAX_SIZE || to + len - 1 > gmap->asce_end)
return -EINVAL;
flush = 0;
down_write(&gmap->mm->mmap_sem);
for (off = 0; off < len; off += PMD_SIZE) {
flush |= __gmap_unmap_by_gaddr(gmap, to + off);
if (radix_tree_insert(&gmap->guest_to_host,
(to + off) >> PMD_SHIFT,
(void *) from + off))
break;
}
up_write(&gmap->mm->mmap_sem);
if (flush)
gmap_flush_tlb(gmap);
if (off >= len)
return 0;
gmap_unmap_segment(gmap, to, len);
return -ENOMEM;
}
unsigned long __gmap_translate(struct gmap *gmap, unsigned long gaddr)
{
unsigned long vmaddr;
vmaddr = (unsigned long)
radix_tree_lookup(&gmap->guest_to_host, gaddr >> PMD_SHIFT);
return vmaddr ? (vmaddr | (gaddr & ~PMD_MASK)) : -EFAULT;
}
unsigned long gmap_translate(struct gmap *gmap, unsigned long gaddr)
{
unsigned long rc;
down_read(&gmap->mm->mmap_sem);
rc = __gmap_translate(gmap, gaddr);
up_read(&gmap->mm->mmap_sem);
return rc;
}
void gmap_unlink(struct mm_struct *mm, unsigned long *table,
unsigned long vmaddr)
{
struct gmap *gmap;
int flush;
rcu_read_lock();
list_for_each_entry_rcu(gmap, &mm->context.gmap_list, list) {
flush = __gmap_unlink_by_vmaddr(gmap, vmaddr);
if (flush)
gmap_flush_tlb(gmap);
}
rcu_read_unlock();
}
int __gmap_link(struct gmap *gmap, unsigned long gaddr, unsigned long vmaddr)
{
struct mm_struct *mm;
unsigned long *table;
spinlock_t *ptl;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
int rc;
BUG_ON(gmap_is_shadow(gmap));
table = gmap->table;
if ((gmap->asce & _ASCE_TYPE_MASK) >= _ASCE_TYPE_REGION1) {
table += (gaddr >> 53) & 0x7ff;
if ((*table & _REGION_ENTRY_INVALID) &&
gmap_alloc_table(gmap, table, _REGION2_ENTRY_EMPTY,
gaddr & 0xffe0000000000000UL))
return -ENOMEM;
table = (unsigned long *)(*table & _REGION_ENTRY_ORIGIN);
}
if ((gmap->asce & _ASCE_TYPE_MASK) >= _ASCE_TYPE_REGION2) {
table += (gaddr >> 42) & 0x7ff;
if ((*table & _REGION_ENTRY_INVALID) &&
gmap_alloc_table(gmap, table, _REGION3_ENTRY_EMPTY,
gaddr & 0xfffffc0000000000UL))
return -ENOMEM;
table = (unsigned long *)(*table & _REGION_ENTRY_ORIGIN);
}
if ((gmap->asce & _ASCE_TYPE_MASK) >= _ASCE_TYPE_REGION3) {
table += (gaddr >> 31) & 0x7ff;
if ((*table & _REGION_ENTRY_INVALID) &&
gmap_alloc_table(gmap, table, _SEGMENT_ENTRY_EMPTY,
gaddr & 0xffffffff80000000UL))
return -ENOMEM;
table = (unsigned long *)(*table & _REGION_ENTRY_ORIGIN);
}
table += (gaddr >> 20) & 0x7ff;
mm = gmap->mm;
pgd = pgd_offset(mm, vmaddr);
VM_BUG_ON(pgd_none(*pgd));
pud = pud_offset(pgd, vmaddr);
VM_BUG_ON(pud_none(*pud));
if (pud_large(*pud))
return -EFAULT;
pmd = pmd_offset(pud, vmaddr);
VM_BUG_ON(pmd_none(*pmd));
if (pmd_large(*pmd))
return -EFAULT;
rc = radix_tree_preload(GFP_KERNEL);
if (rc)
return rc;
ptl = pmd_lock(mm, pmd);
spin_lock(&gmap->guest_table_lock);
if (*table == _SEGMENT_ENTRY_INVALID) {
rc = radix_tree_insert(&gmap->host_to_guest,
vmaddr >> PMD_SHIFT, table);
if (!rc)
*table = pmd_val(*pmd);
} else
rc = 0;
spin_unlock(&gmap->guest_table_lock);
spin_unlock(ptl);
radix_tree_preload_end();
return rc;
}
int gmap_fault(struct gmap *gmap, unsigned long gaddr,
unsigned int fault_flags)
{
unsigned long vmaddr;
int rc;
bool unlocked;
down_read(&gmap->mm->mmap_sem);
retry:
unlocked = false;
vmaddr = __gmap_translate(gmap, gaddr);
if (IS_ERR_VALUE(vmaddr)) {
rc = vmaddr;
goto out_up;
}
if (fixup_user_fault(current, gmap->mm, vmaddr, fault_flags,
&unlocked)) {
rc = -EFAULT;
goto out_up;
}
if (unlocked)
goto retry;
rc = __gmap_link(gmap, gaddr, vmaddr);
out_up:
up_read(&gmap->mm->mmap_sem);
return rc;
}
void __gmap_zap(struct gmap *gmap, unsigned long gaddr)
{
unsigned long vmaddr;
spinlock_t *ptl;
pte_t *ptep;
vmaddr = (unsigned long) radix_tree_lookup(&gmap->guest_to_host,
gaddr >> PMD_SHIFT);
if (vmaddr) {
vmaddr |= gaddr & ~PMD_MASK;
ptep = get_locked_pte(gmap->mm, vmaddr, &ptl);
if (likely(ptep))
ptep_zap_unused(gmap->mm, vmaddr, ptep, 0);
pte_unmap_unlock(ptep, ptl);
}
}
void gmap_discard(struct gmap *gmap, unsigned long from, unsigned long to)
{
unsigned long gaddr, vmaddr, size;
struct vm_area_struct *vma;
down_read(&gmap->mm->mmap_sem);
for (gaddr = from; gaddr < to;
gaddr = (gaddr + PMD_SIZE) & PMD_MASK) {
vmaddr = (unsigned long)
radix_tree_lookup(&gmap->guest_to_host,
gaddr >> PMD_SHIFT);
if (!vmaddr)
continue;
vmaddr |= gaddr & ~PMD_MASK;
vma = find_vma(gmap->mm, vmaddr);
size = min(to - gaddr, PMD_SIZE - (gaddr & ~PMD_MASK));
zap_page_range(vma, vmaddr, size, NULL);
}
up_read(&gmap->mm->mmap_sem);
}
void gmap_register_pte_notifier(struct gmap_notifier *nb)
{
spin_lock(&gmap_notifier_lock);
list_add_rcu(&nb->list, &gmap_notifier_list);
spin_unlock(&gmap_notifier_lock);
}
void gmap_unregister_pte_notifier(struct gmap_notifier *nb)
{
spin_lock(&gmap_notifier_lock);
list_del_rcu(&nb->list);
spin_unlock(&gmap_notifier_lock);
synchronize_rcu();
}
static void gmap_call_notifier(struct gmap *gmap, unsigned long start,
unsigned long end)
{
struct gmap_notifier *nb;
list_for_each_entry(nb, &gmap_notifier_list, list)
nb->notifier_call(gmap, start, end);
}
static inline unsigned long *gmap_table_walk(struct gmap *gmap,
unsigned long gaddr, int level)
{
unsigned long *table;
if ((gmap->asce & _ASCE_TYPE_MASK) + 4 < (level * 4))
return NULL;
if (gmap_is_shadow(gmap) && gmap->removed)
return NULL;
if (gaddr & (-1UL << (31 + ((gmap->asce & _ASCE_TYPE_MASK) >> 2)*11)))
return NULL;
table = gmap->table;
switch (gmap->asce & _ASCE_TYPE_MASK) {
case _ASCE_TYPE_REGION1:
table += (gaddr >> 53) & 0x7ff;
if (level == 4)
break;
if (*table & _REGION_ENTRY_INVALID)
return NULL;
table = (unsigned long *)(*table & _REGION_ENTRY_ORIGIN);
case _ASCE_TYPE_REGION2:
table += (gaddr >> 42) & 0x7ff;
if (level == 3)
break;
if (*table & _REGION_ENTRY_INVALID)
return NULL;
table = (unsigned long *)(*table & _REGION_ENTRY_ORIGIN);
case _ASCE_TYPE_REGION3:
table += (gaddr >> 31) & 0x7ff;
if (level == 2)
break;
if (*table & _REGION_ENTRY_INVALID)
return NULL;
table = (unsigned long *)(*table & _REGION_ENTRY_ORIGIN);
case _ASCE_TYPE_SEGMENT:
table += (gaddr >> 20) & 0x7ff;
if (level == 1)
break;
if (*table & _REGION_ENTRY_INVALID)
return NULL;
table = (unsigned long *)(*table & _SEGMENT_ENTRY_ORIGIN);
table += (gaddr >> 12) & 0xff;
}
return table;
}
static pte_t *gmap_pte_op_walk(struct gmap *gmap, unsigned long gaddr,
spinlock_t **ptl)
{
unsigned long *table;
if (gmap_is_shadow(gmap))
spin_lock(&gmap->guest_table_lock);
table = gmap_table_walk(gmap, gaddr, 1);
if (!table || *table & _SEGMENT_ENTRY_INVALID) {
if (gmap_is_shadow(gmap))
spin_unlock(&gmap->guest_table_lock);
return NULL;
}
if (gmap_is_shadow(gmap)) {
*ptl = &gmap->guest_table_lock;
return pte_offset_map((pmd_t *) table, gaddr);
}
return pte_alloc_map_lock(gmap->mm, (pmd_t *) table, gaddr, ptl);
}
static int gmap_pte_op_fixup(struct gmap *gmap, unsigned long gaddr,
unsigned long vmaddr, int prot)
{
struct mm_struct *mm = gmap->mm;
unsigned int fault_flags;
bool unlocked = false;
BUG_ON(gmap_is_shadow(gmap));
fault_flags = (prot == PROT_WRITE) ? FAULT_FLAG_WRITE : 0;
if (fixup_user_fault(current, mm, vmaddr, fault_flags, &unlocked))
return -EFAULT;
if (unlocked)
return 0;
return __gmap_link(gmap, gaddr, vmaddr);
}
static void gmap_pte_op_end(spinlock_t *ptl)
{
spin_unlock(ptl);
}
static int gmap_protect_range(struct gmap *gmap, unsigned long gaddr,
unsigned long len, int prot, unsigned long bits)
{
unsigned long vmaddr;
spinlock_t *ptl;
pte_t *ptep;
int rc;
while (len) {
rc = -EAGAIN;
ptep = gmap_pte_op_walk(gmap, gaddr, &ptl);
if (ptep) {
rc = ptep_force_prot(gmap->mm, gaddr, ptep, prot, bits);
gmap_pte_op_end(ptl);
}
if (rc) {
vmaddr = __gmap_translate(gmap, gaddr);
if (IS_ERR_VALUE(vmaddr))
return vmaddr;
rc = gmap_pte_op_fixup(gmap, gaddr, vmaddr, prot);
if (rc)
return rc;
continue;
}
gaddr += PAGE_SIZE;
len -= PAGE_SIZE;
}
return 0;
}
int gmap_mprotect_notify(struct gmap *gmap, unsigned long gaddr,
unsigned long len, int prot)
{
int rc;
if ((gaddr & ~PAGE_MASK) || (len & ~PAGE_MASK) || gmap_is_shadow(gmap))
return -EINVAL;
if (!MACHINE_HAS_ESOP && prot == PROT_READ)
return -EINVAL;
down_read(&gmap->mm->mmap_sem);
rc = gmap_protect_range(gmap, gaddr, len, prot, PGSTE_IN_BIT);
up_read(&gmap->mm->mmap_sem);
return rc;
}
int gmap_read_table(struct gmap *gmap, unsigned long gaddr, unsigned long *val)
{
unsigned long address, vmaddr;
spinlock_t *ptl;
pte_t *ptep, pte;
int rc;
while (1) {
rc = -EAGAIN;
ptep = gmap_pte_op_walk(gmap, gaddr, &ptl);
if (ptep) {
pte = *ptep;
if (pte_present(pte) && (pte_val(pte) & _PAGE_READ)) {
address = pte_val(pte) & PAGE_MASK;
address += gaddr & ~PAGE_MASK;
*val = *(unsigned long *) address;
pte_val(*ptep) |= _PAGE_YOUNG;
rc = 0;
}
gmap_pte_op_end(ptl);
}
if (!rc)
break;
vmaddr = __gmap_translate(gmap, gaddr);
if (IS_ERR_VALUE(vmaddr)) {
rc = vmaddr;
break;
}
rc = gmap_pte_op_fixup(gmap, gaddr, vmaddr, PROT_READ);
if (rc)
break;
}
return rc;
}
static inline void gmap_insert_rmap(struct gmap *sg, unsigned long vmaddr,
struct gmap_rmap *rmap)
{
void **slot;
BUG_ON(!gmap_is_shadow(sg));
slot = radix_tree_lookup_slot(&sg->host_to_rmap, vmaddr >> PAGE_SHIFT);
if (slot) {
rmap->next = radix_tree_deref_slot_protected(slot,
&sg->guest_table_lock);
radix_tree_replace_slot(slot, rmap);
} else {
rmap->next = NULL;
radix_tree_insert(&sg->host_to_rmap, vmaddr >> PAGE_SHIFT,
rmap);
}
}
static int gmap_protect_rmap(struct gmap *sg, unsigned long raddr,
unsigned long paddr, unsigned long len, int prot)
{
struct gmap *parent;
struct gmap_rmap *rmap;
unsigned long vmaddr;
spinlock_t *ptl;
pte_t *ptep;
int rc;
BUG_ON(!gmap_is_shadow(sg));
parent = sg->parent;
while (len) {
vmaddr = __gmap_translate(parent, paddr);
if (IS_ERR_VALUE(vmaddr))
return vmaddr;
rmap = kzalloc(sizeof(*rmap), GFP_KERNEL);
if (!rmap)
return -ENOMEM;
rmap->raddr = raddr;
rc = radix_tree_preload(GFP_KERNEL);
if (rc) {
kfree(rmap);
return rc;
}
rc = -EAGAIN;
ptep = gmap_pte_op_walk(parent, paddr, &ptl);
if (ptep) {
spin_lock(&sg->guest_table_lock);
rc = ptep_force_prot(parent->mm, paddr, ptep, prot,
PGSTE_VSIE_BIT);
if (!rc)
gmap_insert_rmap(sg, vmaddr, rmap);
spin_unlock(&sg->guest_table_lock);
gmap_pte_op_end(ptl);
}
radix_tree_preload_end();
if (rc) {
kfree(rmap);
rc = gmap_pte_op_fixup(parent, paddr, vmaddr, prot);
if (rc)
return rc;
continue;
}
paddr += PAGE_SIZE;
len -= PAGE_SIZE;
}
return 0;
}
static inline void gmap_idte_one(unsigned long asce, unsigned long vaddr)
{
asm volatile(
" .insn rrf,0xb98e0000,%0,%1,0,0"
: : "a" (asce), "a" (vaddr) : "cc", "memory");
}
static void gmap_unshadow_page(struct gmap *sg, unsigned long raddr)
{
unsigned long *table;
BUG_ON(!gmap_is_shadow(sg));
table = gmap_table_walk(sg, raddr, 0);
if (!table || *table & _PAGE_INVALID)
return;
gmap_call_notifier(sg, raddr, raddr + (1UL << 12) - 1);
ptep_unshadow_pte(sg->mm, raddr, (pte_t *) table);
}
static void __gmap_unshadow_pgt(struct gmap *sg, unsigned long raddr,
unsigned long *pgt)
{
int i;
BUG_ON(!gmap_is_shadow(sg));
for (i = 0; i < 256; i++, raddr += 1UL << 12)
pgt[i] = _PAGE_INVALID;
}
static void gmap_unshadow_pgt(struct gmap *sg, unsigned long raddr)
{
unsigned long sto, *ste, *pgt;
struct page *page;
BUG_ON(!gmap_is_shadow(sg));
ste = gmap_table_walk(sg, raddr, 1);
if (!ste || !(*ste & _SEGMENT_ENTRY_ORIGIN))
return;
gmap_call_notifier(sg, raddr, raddr + (1UL << 20) - 1);
sto = (unsigned long) (ste - ((raddr >> 20) & 0x7ff));
gmap_idte_one(sto | _ASCE_TYPE_SEGMENT, raddr);
pgt = (unsigned long *)(*ste & _SEGMENT_ENTRY_ORIGIN);
*ste = _SEGMENT_ENTRY_EMPTY;
__gmap_unshadow_pgt(sg, raddr, pgt);
page = pfn_to_page(__pa(pgt) >> PAGE_SHIFT);
list_del(&page->lru);
page_table_free_pgste(page);
}
static void __gmap_unshadow_sgt(struct gmap *sg, unsigned long raddr,
unsigned long *sgt)
{
unsigned long asce, *pgt;
struct page *page;
int i;
BUG_ON(!gmap_is_shadow(sg));
asce = (unsigned long) sgt | _ASCE_TYPE_SEGMENT;
for (i = 0; i < 2048; i++, raddr += 1UL << 20) {
if (!(sgt[i] & _SEGMENT_ENTRY_ORIGIN))
continue;
pgt = (unsigned long *)(sgt[i] & _REGION_ENTRY_ORIGIN);
sgt[i] = _SEGMENT_ENTRY_EMPTY;
__gmap_unshadow_pgt(sg, raddr, pgt);
page = pfn_to_page(__pa(pgt) >> PAGE_SHIFT);
list_del(&page->lru);
page_table_free_pgste(page);
}
}
static void gmap_unshadow_sgt(struct gmap *sg, unsigned long raddr)
{
unsigned long r3o, *r3e, *sgt;
struct page *page;
BUG_ON(!gmap_is_shadow(sg));
r3e = gmap_table_walk(sg, raddr, 2);
if (!r3e || !(*r3e & _REGION_ENTRY_ORIGIN))
return;
gmap_call_notifier(sg, raddr, raddr + (1UL << 31) - 1);
r3o = (unsigned long) (r3e - ((raddr >> 31) & 0x7ff));
gmap_idte_one(r3o | _ASCE_TYPE_REGION3, raddr);
sgt = (unsigned long *)(*r3e & _REGION_ENTRY_ORIGIN);
*r3e = _REGION3_ENTRY_EMPTY;
__gmap_unshadow_sgt(sg, raddr, sgt);
page = pfn_to_page(__pa(sgt) >> PAGE_SHIFT);
list_del(&page->lru);
__free_pages(page, 2);
}
static void __gmap_unshadow_r3t(struct gmap *sg, unsigned long raddr,
unsigned long *r3t)
{
unsigned long asce, *sgt;
struct page *page;
int i;
BUG_ON(!gmap_is_shadow(sg));
asce = (unsigned long) r3t | _ASCE_TYPE_REGION3;
for (i = 0; i < 2048; i++, raddr += 1UL << 31) {
if (!(r3t[i] & _REGION_ENTRY_ORIGIN))
continue;
sgt = (unsigned long *)(r3t[i] & _REGION_ENTRY_ORIGIN);
r3t[i] = _REGION3_ENTRY_EMPTY;
__gmap_unshadow_sgt(sg, raddr, sgt);
page = pfn_to_page(__pa(sgt) >> PAGE_SHIFT);
list_del(&page->lru);
__free_pages(page, 2);
}
}
static void gmap_unshadow_r3t(struct gmap *sg, unsigned long raddr)
{
unsigned long r2o, *r2e, *r3t;
struct page *page;
BUG_ON(!gmap_is_shadow(sg));
r2e = gmap_table_walk(sg, raddr, 3);
if (!r2e || !(*r2e & _REGION_ENTRY_ORIGIN))
return;
gmap_call_notifier(sg, raddr, raddr + (1UL << 42) - 1);
r2o = (unsigned long) (r2e - ((raddr >> 42) & 0x7ff));
gmap_idte_one(r2o | _ASCE_TYPE_REGION2, raddr);
r3t = (unsigned long *)(*r2e & _REGION_ENTRY_ORIGIN);
*r2e = _REGION2_ENTRY_EMPTY;
__gmap_unshadow_r3t(sg, raddr, r3t);
page = pfn_to_page(__pa(r3t) >> PAGE_SHIFT);
list_del(&page->lru);
__free_pages(page, 2);
}
static void __gmap_unshadow_r2t(struct gmap *sg, unsigned long raddr,
unsigned long *r2t)
{
unsigned long asce, *r3t;
struct page *page;
int i;
BUG_ON(!gmap_is_shadow(sg));
asce = (unsigned long) r2t | _ASCE_TYPE_REGION2;
for (i = 0; i < 2048; i++, raddr += 1UL << 42) {
if (!(r2t[i] & _REGION_ENTRY_ORIGIN))
continue;
r3t = (unsigned long *)(r2t[i] & _REGION_ENTRY_ORIGIN);
r2t[i] = _REGION2_ENTRY_EMPTY;
__gmap_unshadow_r3t(sg, raddr, r3t);
page = pfn_to_page(__pa(r3t) >> PAGE_SHIFT);
list_del(&page->lru);
__free_pages(page, 2);
}
}
static void gmap_unshadow_r2t(struct gmap *sg, unsigned long raddr)
{
unsigned long r1o, *r1e, *r2t;
struct page *page;
BUG_ON(!gmap_is_shadow(sg));
r1e = gmap_table_walk(sg, raddr, 4);
if (!r1e || !(*r1e & _REGION_ENTRY_ORIGIN))
return;
gmap_call_notifier(sg, raddr, raddr + (1UL << 53) - 1);
r1o = (unsigned long) (r1e - ((raddr >> 53) & 0x7ff));
gmap_idte_one(r1o | _ASCE_TYPE_REGION1, raddr);
r2t = (unsigned long *)(*r1e & _REGION_ENTRY_ORIGIN);
*r1e = _REGION1_ENTRY_EMPTY;
__gmap_unshadow_r2t(sg, raddr, r2t);
page = pfn_to_page(__pa(r2t) >> PAGE_SHIFT);
list_del(&page->lru);
__free_pages(page, 2);
}
static void __gmap_unshadow_r1t(struct gmap *sg, unsigned long raddr,
unsigned long *r1t)
{
unsigned long asce, *r2t;
struct page *page;
int i;
BUG_ON(!gmap_is_shadow(sg));
asce = (unsigned long) r1t | _ASCE_TYPE_REGION1;
for (i = 0; i < 2048; i++, raddr += 1UL << 53) {
if (!(r1t[i] & _REGION_ENTRY_ORIGIN))
continue;
r2t = (unsigned long *)(r1t[i] & _REGION_ENTRY_ORIGIN);
__gmap_unshadow_r2t(sg, raddr, r2t);
gmap_idte_one(asce, raddr);
r1t[i] = _REGION1_ENTRY_EMPTY;
page = pfn_to_page(__pa(r2t) >> PAGE_SHIFT);
list_del(&page->lru);
__free_pages(page, 2);
}
}
static void gmap_unshadow(struct gmap *sg)
{
unsigned long *table;
BUG_ON(!gmap_is_shadow(sg));
if (sg->removed)
return;
sg->removed = 1;
gmap_call_notifier(sg, 0, -1UL);
gmap_flush_tlb(sg);
table = (unsigned long *)(sg->asce & _ASCE_ORIGIN);
switch (sg->asce & _ASCE_TYPE_MASK) {
case _ASCE_TYPE_REGION1:
__gmap_unshadow_r1t(sg, 0, table);
break;
case _ASCE_TYPE_REGION2:
__gmap_unshadow_r2t(sg, 0, table);
break;
case _ASCE_TYPE_REGION3:
__gmap_unshadow_r3t(sg, 0, table);
break;
case _ASCE_TYPE_SEGMENT:
__gmap_unshadow_sgt(sg, 0, table);
break;
}
}
static struct gmap *gmap_find_shadow(struct gmap *parent, unsigned long asce,
int edat_level)
{
struct gmap *sg;
list_for_each_entry(sg, &parent->children, list) {
if (sg->orig_asce != asce || sg->edat_level != edat_level ||
sg->removed)
continue;
if (!sg->initialized)
return ERR_PTR(-EAGAIN);
atomic_inc(&sg->ref_count);
return sg;
}
return NULL;
}
int gmap_shadow_valid(struct gmap *sg, unsigned long asce, int edat_level)
{
if (sg->removed)
return 0;
return sg->orig_asce == asce && sg->edat_level == edat_level;
}
struct gmap *gmap_shadow(struct gmap *parent, unsigned long asce,
int edat_level)
{
struct gmap *sg, *new;
unsigned long limit;
int rc;
BUG_ON(gmap_is_shadow(parent));
spin_lock(&parent->shadow_lock);
sg = gmap_find_shadow(parent, asce, edat_level);
spin_unlock(&parent->shadow_lock);
if (sg)
return sg;
limit = -1UL >> (33 - (((asce & _ASCE_TYPE_MASK) >> 2) * 11));
if (asce & _ASCE_REAL_SPACE)
limit = -1UL;
new = gmap_alloc(limit);
if (!new)
return ERR_PTR(-ENOMEM);
new->mm = parent->mm;
new->parent = gmap_get(parent);
new->orig_asce = asce;
new->edat_level = edat_level;
new->initialized = false;
spin_lock(&parent->shadow_lock);
sg = gmap_find_shadow(parent, asce, edat_level);
if (sg) {
spin_unlock(&parent->shadow_lock);
gmap_free(new);
return sg;
}
if (asce & _ASCE_REAL_SPACE) {
list_for_each_entry(sg, &parent->children, list) {
if (sg->orig_asce & _ASCE_REAL_SPACE) {
spin_lock(&sg->guest_table_lock);
gmap_unshadow(sg);
spin_unlock(&sg->guest_table_lock);
list_del(&sg->list);
gmap_put(sg);
break;
}
}
}
atomic_set(&new->ref_count, 2);
list_add(&new->list, &parent->children);
if (asce & _ASCE_REAL_SPACE) {
new->initialized = true;
spin_unlock(&parent->shadow_lock);
return new;
}
spin_unlock(&parent->shadow_lock);
down_read(&parent->mm->mmap_sem);
rc = gmap_protect_range(parent, asce & _ASCE_ORIGIN,
((asce & _ASCE_TABLE_LENGTH) + 1) * 4096,
PROT_READ, PGSTE_VSIE_BIT);
up_read(&parent->mm->mmap_sem);
spin_lock(&parent->shadow_lock);
new->initialized = true;
if (rc) {
list_del(&new->list);
gmap_free(new);
new = ERR_PTR(rc);
}
spin_unlock(&parent->shadow_lock);
return new;
}
int gmap_shadow_r2t(struct gmap *sg, unsigned long saddr, unsigned long r2t,
int fake)
{
unsigned long raddr, origin, offset, len;
unsigned long *s_r2t, *table;
struct page *page;
int rc;
BUG_ON(!gmap_is_shadow(sg));
page = alloc_pages(GFP_KERNEL, 2);
if (!page)
return -ENOMEM;
page->index = r2t & _REGION_ENTRY_ORIGIN;
if (fake)
page->index |= GMAP_SHADOW_FAKE_TABLE;
s_r2t = (unsigned long *) page_to_phys(page);
spin_lock(&sg->guest_table_lock);
table = gmap_table_walk(sg, saddr, 4);
if (!table) {
rc = -EAGAIN;
goto out_free;
}
if (!(*table & _REGION_ENTRY_INVALID)) {
rc = 0;
goto out_free;
} else if (*table & _REGION_ENTRY_ORIGIN) {
rc = -EAGAIN;
goto out_free;
}
crst_table_init(s_r2t, _REGION2_ENTRY_EMPTY);
*table = (unsigned long) s_r2t | _REGION_ENTRY_LENGTH |
_REGION_ENTRY_TYPE_R1 | _REGION_ENTRY_INVALID;
if (sg->edat_level >= 1)
*table |= (r2t & _REGION_ENTRY_PROTECT);
list_add(&page->lru, &sg->crst_list);
if (fake) {
*table &= ~_REGION_ENTRY_INVALID;
spin_unlock(&sg->guest_table_lock);
return 0;
}
spin_unlock(&sg->guest_table_lock);
raddr = (saddr & 0xffe0000000000000UL) | _SHADOW_RMAP_REGION1;
origin = r2t & _REGION_ENTRY_ORIGIN;
offset = ((r2t & _REGION_ENTRY_OFFSET) >> 6) * 4096;
len = ((r2t & _REGION_ENTRY_LENGTH) + 1) * 4096 - offset;
rc = gmap_protect_rmap(sg, raddr, origin + offset, len, PROT_READ);
spin_lock(&sg->guest_table_lock);
if (!rc) {
table = gmap_table_walk(sg, saddr, 4);
if (!table || (*table & _REGION_ENTRY_ORIGIN) !=
(unsigned long) s_r2t)
rc = -EAGAIN;
else
*table &= ~_REGION_ENTRY_INVALID;
} else {
gmap_unshadow_r2t(sg, raddr);
}
spin_unlock(&sg->guest_table_lock);
return rc;
out_free:
spin_unlock(&sg->guest_table_lock);
__free_pages(page, 2);
return rc;
}
int gmap_shadow_r3t(struct gmap *sg, unsigned long saddr, unsigned long r3t,
int fake)
{
unsigned long raddr, origin, offset, len;
unsigned long *s_r3t, *table;
struct page *page;
int rc;
BUG_ON(!gmap_is_shadow(sg));
page = alloc_pages(GFP_KERNEL, 2);
if (!page)
return -ENOMEM;
page->index = r3t & _REGION_ENTRY_ORIGIN;
if (fake)
page->index |= GMAP_SHADOW_FAKE_TABLE;
s_r3t = (unsigned long *) page_to_phys(page);
spin_lock(&sg->guest_table_lock);
table = gmap_table_walk(sg, saddr, 3);
if (!table) {
rc = -EAGAIN;
goto out_free;
}
if (!(*table & _REGION_ENTRY_INVALID)) {
rc = 0;
goto out_free;
} else if (*table & _REGION_ENTRY_ORIGIN) {
rc = -EAGAIN;
}
crst_table_init(s_r3t, _REGION3_ENTRY_EMPTY);
*table = (unsigned long) s_r3t | _REGION_ENTRY_LENGTH |
_REGION_ENTRY_TYPE_R2 | _REGION_ENTRY_INVALID;
if (sg->edat_level >= 1)
*table |= (r3t & _REGION_ENTRY_PROTECT);
list_add(&page->lru, &sg->crst_list);
if (fake) {
*table &= ~_REGION_ENTRY_INVALID;
spin_unlock(&sg->guest_table_lock);
return 0;
}
spin_unlock(&sg->guest_table_lock);
raddr = (saddr & 0xfffffc0000000000UL) | _SHADOW_RMAP_REGION2;
origin = r3t & _REGION_ENTRY_ORIGIN;
offset = ((r3t & _REGION_ENTRY_OFFSET) >> 6) * 4096;
len = ((r3t & _REGION_ENTRY_LENGTH) + 1) * 4096 - offset;
rc = gmap_protect_rmap(sg, raddr, origin + offset, len, PROT_READ);
spin_lock(&sg->guest_table_lock);
if (!rc) {
table = gmap_table_walk(sg, saddr, 3);
if (!table || (*table & _REGION_ENTRY_ORIGIN) !=
(unsigned long) s_r3t)
rc = -EAGAIN;
else
*table &= ~_REGION_ENTRY_INVALID;
} else {
gmap_unshadow_r3t(sg, raddr);
}
spin_unlock(&sg->guest_table_lock);
return rc;
out_free:
spin_unlock(&sg->guest_table_lock);
__free_pages(page, 2);
return rc;
}
int gmap_shadow_sgt(struct gmap *sg, unsigned long saddr, unsigned long sgt,
int fake)
{
unsigned long raddr, origin, offset, len;
unsigned long *s_sgt, *table;
struct page *page;
int rc;
BUG_ON(!gmap_is_shadow(sg) || (sgt & _REGION3_ENTRY_LARGE));
page = alloc_pages(GFP_KERNEL, 2);
if (!page)
return -ENOMEM;
page->index = sgt & _REGION_ENTRY_ORIGIN;
if (fake)
page->index |= GMAP_SHADOW_FAKE_TABLE;
s_sgt = (unsigned long *) page_to_phys(page);
spin_lock(&sg->guest_table_lock);
table = gmap_table_walk(sg, saddr, 2);
if (!table) {
rc = -EAGAIN;
goto out_free;
}
if (!(*table & _REGION_ENTRY_INVALID)) {
rc = 0;
goto out_free;
} else if (*table & _REGION_ENTRY_ORIGIN) {
rc = -EAGAIN;
goto out_free;
}
crst_table_init(s_sgt, _SEGMENT_ENTRY_EMPTY);
*table = (unsigned long) s_sgt | _REGION_ENTRY_LENGTH |
_REGION_ENTRY_TYPE_R3 | _REGION_ENTRY_INVALID;
if (sg->edat_level >= 1)
*table |= sgt & _REGION_ENTRY_PROTECT;
list_add(&page->lru, &sg->crst_list);
if (fake) {
*table &= ~_REGION_ENTRY_INVALID;
spin_unlock(&sg->guest_table_lock);
return 0;
}
spin_unlock(&sg->guest_table_lock);
raddr = (saddr & 0xffffffff80000000UL) | _SHADOW_RMAP_REGION3;
origin = sgt & _REGION_ENTRY_ORIGIN;
offset = ((sgt & _REGION_ENTRY_OFFSET) >> 6) * 4096;
len = ((sgt & _REGION_ENTRY_LENGTH) + 1) * 4096 - offset;
rc = gmap_protect_rmap(sg, raddr, origin + offset, len, PROT_READ);
spin_lock(&sg->guest_table_lock);
if (!rc) {
table = gmap_table_walk(sg, saddr, 2);
if (!table || (*table & _REGION_ENTRY_ORIGIN) !=
(unsigned long) s_sgt)
rc = -EAGAIN;
else
*table &= ~_REGION_ENTRY_INVALID;
} else {
gmap_unshadow_sgt(sg, raddr);
}
spin_unlock(&sg->guest_table_lock);
return rc;
out_free:
spin_unlock(&sg->guest_table_lock);
__free_pages(page, 2);
return rc;
}
int gmap_shadow_pgt_lookup(struct gmap *sg, unsigned long saddr,
unsigned long *pgt, int *dat_protection,
int *fake)
{
unsigned long *table;
struct page *page;
int rc;
BUG_ON(!gmap_is_shadow(sg));
spin_lock(&sg->guest_table_lock);
table = gmap_table_walk(sg, saddr, 1);
if (table && !(*table & _SEGMENT_ENTRY_INVALID)) {
page = pfn_to_page(*table >> PAGE_SHIFT);
*pgt = page->index & ~GMAP_SHADOW_FAKE_TABLE;
*dat_protection = !!(*table & _SEGMENT_ENTRY_PROTECT);
*fake = !!(page->index & GMAP_SHADOW_FAKE_TABLE);
rc = 0;
} else {
rc = -EAGAIN;
}
spin_unlock(&sg->guest_table_lock);
return rc;
}
int gmap_shadow_pgt(struct gmap *sg, unsigned long saddr, unsigned long pgt,
int fake)
{
unsigned long raddr, origin;
unsigned long *s_pgt, *table;
struct page *page;
int rc;
BUG_ON(!gmap_is_shadow(sg) || (pgt & _SEGMENT_ENTRY_LARGE));
page = page_table_alloc_pgste(sg->mm);
if (!page)
return -ENOMEM;
page->index = pgt & _SEGMENT_ENTRY_ORIGIN;
if (fake)
page->index |= GMAP_SHADOW_FAKE_TABLE;
s_pgt = (unsigned long *) page_to_phys(page);
spin_lock(&sg->guest_table_lock);
table = gmap_table_walk(sg, saddr, 1);
if (!table) {
rc = -EAGAIN;
goto out_free;
}
if (!(*table & _SEGMENT_ENTRY_INVALID)) {
rc = 0;
goto out_free;
} else if (*table & _SEGMENT_ENTRY_ORIGIN) {
rc = -EAGAIN;
goto out_free;
}
*table = (unsigned long) s_pgt | _SEGMENT_ENTRY |
(pgt & _SEGMENT_ENTRY_PROTECT) | _SEGMENT_ENTRY_INVALID;
list_add(&page->lru, &sg->pt_list);
if (fake) {
*table &= ~_SEGMENT_ENTRY_INVALID;
spin_unlock(&sg->guest_table_lock);
return 0;
}
spin_unlock(&sg->guest_table_lock);
raddr = (saddr & 0xfffffffffff00000UL) | _SHADOW_RMAP_SEGMENT;
origin = pgt & _SEGMENT_ENTRY_ORIGIN & PAGE_MASK;
rc = gmap_protect_rmap(sg, raddr, origin, PAGE_SIZE, PROT_READ);
spin_lock(&sg->guest_table_lock);
if (!rc) {
table = gmap_table_walk(sg, saddr, 1);
if (!table || (*table & _SEGMENT_ENTRY_ORIGIN) !=
(unsigned long) s_pgt)
rc = -EAGAIN;
else
*table &= ~_SEGMENT_ENTRY_INVALID;
} else {
gmap_unshadow_pgt(sg, raddr);
}
spin_unlock(&sg->guest_table_lock);
return rc;
out_free:
spin_unlock(&sg->guest_table_lock);
page_table_free_pgste(page);
return rc;
}
int gmap_shadow_page(struct gmap *sg, unsigned long saddr, pte_t pte)
{
struct gmap *parent;
struct gmap_rmap *rmap;
unsigned long vmaddr, paddr;
spinlock_t *ptl;
pte_t *sptep, *tptep;
int prot;
int rc;
BUG_ON(!gmap_is_shadow(sg));
parent = sg->parent;
prot = (pte_val(pte) & _PAGE_PROTECT) ? PROT_READ : PROT_WRITE;
rmap = kzalloc(sizeof(*rmap), GFP_KERNEL);
if (!rmap)
return -ENOMEM;
rmap->raddr = (saddr & PAGE_MASK) | _SHADOW_RMAP_PGTABLE;
while (1) {
paddr = pte_val(pte) & PAGE_MASK;
vmaddr = __gmap_translate(parent, paddr);
if (IS_ERR_VALUE(vmaddr)) {
rc = vmaddr;
break;
}
rc = radix_tree_preload(GFP_KERNEL);
if (rc)
break;
rc = -EAGAIN;
sptep = gmap_pte_op_walk(parent, paddr, &ptl);
if (sptep) {
spin_lock(&sg->guest_table_lock);
tptep = (pte_t *) gmap_table_walk(sg, saddr, 0);
if (!tptep) {
spin_unlock(&sg->guest_table_lock);
gmap_pte_op_end(ptl);
radix_tree_preload_end();
break;
}
rc = ptep_shadow_pte(sg->mm, saddr, sptep, tptep, pte);
if (rc > 0) {
gmap_insert_rmap(sg, vmaddr, rmap);
rmap = NULL;
rc = 0;
}
gmap_pte_op_end(ptl);
spin_unlock(&sg->guest_table_lock);
}
radix_tree_preload_end();
if (!rc)
break;
rc = gmap_pte_op_fixup(parent, paddr, vmaddr, prot);
if (rc)
break;
}
kfree(rmap);
return rc;
}
static void gmap_shadow_notify(struct gmap *sg, unsigned long vmaddr,
unsigned long offset, pte_t *pte)
{
struct gmap_rmap *rmap, *rnext, *head;
unsigned long gaddr, start, end, bits, raddr;
unsigned long *table;
BUG_ON(!gmap_is_shadow(sg));
spin_lock(&sg->parent->guest_table_lock);
table = radix_tree_lookup(&sg->parent->host_to_guest,
vmaddr >> PMD_SHIFT);
gaddr = table ? __gmap_segment_gaddr(table) + offset : 0;
spin_unlock(&sg->parent->guest_table_lock);
if (!table)
return;
spin_lock(&sg->guest_table_lock);
if (sg->removed) {
spin_unlock(&sg->guest_table_lock);
return;
}
start = sg->orig_asce & _ASCE_ORIGIN;
end = start + ((sg->orig_asce & _ASCE_TABLE_LENGTH) + 1) * 4096;
if (!(sg->orig_asce & _ASCE_REAL_SPACE) && gaddr >= start &&
gaddr < end) {
gmap_unshadow(sg);
spin_unlock(&sg->guest_table_lock);
list_del(&sg->list);
gmap_put(sg);
return;
}
head = radix_tree_delete(&sg->host_to_rmap, vmaddr >> 12);
gmap_for_each_rmap_safe(rmap, rnext, head) {
bits = rmap->raddr & _SHADOW_RMAP_MASK;
raddr = rmap->raddr ^ bits;
switch (bits) {
case _SHADOW_RMAP_REGION1:
gmap_unshadow_r2t(sg, raddr);
break;
case _SHADOW_RMAP_REGION2:
gmap_unshadow_r3t(sg, raddr);
break;
case _SHADOW_RMAP_REGION3:
gmap_unshadow_sgt(sg, raddr);
break;
case _SHADOW_RMAP_SEGMENT:
gmap_unshadow_pgt(sg, raddr);
break;
case _SHADOW_RMAP_PGTABLE:
gmap_unshadow_page(sg, raddr);
break;
}
kfree(rmap);
}
spin_unlock(&sg->guest_table_lock);
}
void ptep_notify(struct mm_struct *mm, unsigned long vmaddr,
pte_t *pte, unsigned long bits)
{
unsigned long offset, gaddr;
unsigned long *table;
struct gmap *gmap, *sg, *next;
offset = ((unsigned long) pte) & (255 * sizeof(pte_t));
offset = offset * (4096 / sizeof(pte_t));
rcu_read_lock();
list_for_each_entry_rcu(gmap, &mm->context.gmap_list, list) {
if (!list_empty(&gmap->children) && (bits & PGSTE_VSIE_BIT)) {
spin_lock(&gmap->shadow_lock);
list_for_each_entry_safe(sg, next,
&gmap->children, list)
gmap_shadow_notify(sg, vmaddr, offset, pte);
spin_unlock(&gmap->shadow_lock);
}
if (!(bits & PGSTE_IN_BIT))
continue;
spin_lock(&gmap->guest_table_lock);
table = radix_tree_lookup(&gmap->host_to_guest,
vmaddr >> PMD_SHIFT);
if (table)
gaddr = __gmap_segment_gaddr(table) + offset;
spin_unlock(&gmap->guest_table_lock);
if (table)
gmap_call_notifier(gmap, gaddr, gaddr + PAGE_SIZE - 1);
}
rcu_read_unlock();
}
static inline void thp_split_mm(struct mm_struct *mm)
{
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
struct vm_area_struct *vma;
unsigned long addr;
for (vma = mm->mmap; vma != NULL; vma = vma->vm_next) {
for (addr = vma->vm_start;
addr < vma->vm_end;
addr += PAGE_SIZE)
follow_page(vma, addr, FOLL_SPLIT);
vma->vm_flags &= ~VM_HUGEPAGE;
vma->vm_flags |= VM_NOHUGEPAGE;
}
mm->def_flags |= VM_NOHUGEPAGE;
#endif
}
int s390_enable_sie(void)
{
struct mm_struct *mm = current->mm;
if (mm_has_pgste(mm))
return 0;
if (!mm_alloc_pgste(mm))
return -EINVAL;
down_write(&mm->mmap_sem);
mm->context.has_pgste = 1;
thp_split_mm(mm);
up_write(&mm->mmap_sem);
return 0;
}
static int __s390_enable_skey(pte_t *pte, unsigned long addr,
unsigned long next, struct mm_walk *walk)
{
if (is_zero_pfn(pte_pfn(*pte)))
ptep_xchg_direct(walk->mm, addr, pte, __pte(_PAGE_INVALID));
ptep_zap_key(walk->mm, addr, pte);
return 0;
}
int s390_enable_skey(void)
{
struct mm_walk walk = { .pte_entry = __s390_enable_skey };
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
int rc = 0;
down_write(&mm->mmap_sem);
if (mm_use_skey(mm))
goto out_up;
mm->context.use_skey = 1;
for (vma = mm->mmap; vma; vma = vma->vm_next) {
if (ksm_madvise(vma, vma->vm_start, vma->vm_end,
MADV_UNMERGEABLE, &vma->vm_flags)) {
mm->context.use_skey = 0;
rc = -ENOMEM;
goto out_up;
}
}
mm->def_flags &= ~VM_MERGEABLE;
walk.mm = mm;
walk_page_range(0, TASK_SIZE, &walk);
out_up:
up_write(&mm->mmap_sem);
return rc;
}
static int __s390_reset_cmma(pte_t *pte, unsigned long addr,
unsigned long next, struct mm_walk *walk)
{
ptep_zap_unused(walk->mm, addr, pte, 1);
return 0;
}
void s390_reset_cmma(struct mm_struct *mm)
{
struct mm_walk walk = { .pte_entry = __s390_reset_cmma };
down_write(&mm->mmap_sem);
walk.mm = mm;
walk_page_range(0, TASK_SIZE, &walk);
up_write(&mm->mmap_sem);
}
