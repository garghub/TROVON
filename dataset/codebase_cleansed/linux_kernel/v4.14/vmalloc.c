static void free_work(struct work_struct *w)
{
struct vfree_deferred *p = container_of(w, struct vfree_deferred, wq);
struct llist_node *t, *llnode;
llist_for_each_safe(llnode, t, llist_del_all(&p->list))
__vunmap((void *)llnode, 1);
}
static void vunmap_pte_range(pmd_t *pmd, unsigned long addr, unsigned long end)
{
pte_t *pte;
pte = pte_offset_kernel(pmd, addr);
do {
pte_t ptent = ptep_get_and_clear(&init_mm, addr, pte);
WARN_ON(!pte_none(ptent) && !pte_present(ptent));
} while (pte++, addr += PAGE_SIZE, addr != end);
}
static void vunmap_pmd_range(pud_t *pud, unsigned long addr, unsigned long end)
{
pmd_t *pmd;
unsigned long next;
pmd = pmd_offset(pud, addr);
do {
next = pmd_addr_end(addr, end);
if (pmd_clear_huge(pmd))
continue;
if (pmd_none_or_clear_bad(pmd))
continue;
vunmap_pte_range(pmd, addr, next);
} while (pmd++, addr = next, addr != end);
}
static void vunmap_pud_range(p4d_t *p4d, unsigned long addr, unsigned long end)
{
pud_t *pud;
unsigned long next;
pud = pud_offset(p4d, addr);
do {
next = pud_addr_end(addr, end);
if (pud_clear_huge(pud))
continue;
if (pud_none_or_clear_bad(pud))
continue;
vunmap_pmd_range(pud, addr, next);
} while (pud++, addr = next, addr != end);
}
static void vunmap_p4d_range(pgd_t *pgd, unsigned long addr, unsigned long end)
{
p4d_t *p4d;
unsigned long next;
p4d = p4d_offset(pgd, addr);
do {
next = p4d_addr_end(addr, end);
if (p4d_clear_huge(p4d))
continue;
if (p4d_none_or_clear_bad(p4d))
continue;
vunmap_pud_range(p4d, addr, next);
} while (p4d++, addr = next, addr != end);
}
static void vunmap_page_range(unsigned long addr, unsigned long end)
{
pgd_t *pgd;
unsigned long next;
BUG_ON(addr >= end);
pgd = pgd_offset_k(addr);
do {
next = pgd_addr_end(addr, end);
if (pgd_none_or_clear_bad(pgd))
continue;
vunmap_p4d_range(pgd, addr, next);
} while (pgd++, addr = next, addr != end);
}
static int vmap_pte_range(pmd_t *pmd, unsigned long addr,
unsigned long end, pgprot_t prot, struct page **pages, int *nr)
{
pte_t *pte;
pte = pte_alloc_kernel(pmd, addr);
if (!pte)
return -ENOMEM;
do {
struct page *page = pages[*nr];
if (WARN_ON(!pte_none(*pte)))
return -EBUSY;
if (WARN_ON(!page))
return -ENOMEM;
set_pte_at(&init_mm, addr, pte, mk_pte(page, prot));
(*nr)++;
} while (pte++, addr += PAGE_SIZE, addr != end);
return 0;
}
static int vmap_pmd_range(pud_t *pud, unsigned long addr,
unsigned long end, pgprot_t prot, struct page **pages, int *nr)
{
pmd_t *pmd;
unsigned long next;
pmd = pmd_alloc(&init_mm, pud, addr);
if (!pmd)
return -ENOMEM;
do {
next = pmd_addr_end(addr, end);
if (vmap_pte_range(pmd, addr, next, prot, pages, nr))
return -ENOMEM;
} while (pmd++, addr = next, addr != end);
return 0;
}
static int vmap_pud_range(p4d_t *p4d, unsigned long addr,
unsigned long end, pgprot_t prot, struct page **pages, int *nr)
{
pud_t *pud;
unsigned long next;
pud = pud_alloc(&init_mm, p4d, addr);
if (!pud)
return -ENOMEM;
do {
next = pud_addr_end(addr, end);
if (vmap_pmd_range(pud, addr, next, prot, pages, nr))
return -ENOMEM;
} while (pud++, addr = next, addr != end);
return 0;
}
static int vmap_p4d_range(pgd_t *pgd, unsigned long addr,
unsigned long end, pgprot_t prot, struct page **pages, int *nr)
{
p4d_t *p4d;
unsigned long next;
p4d = p4d_alloc(&init_mm, pgd, addr);
if (!p4d)
return -ENOMEM;
do {
next = p4d_addr_end(addr, end);
if (vmap_pud_range(p4d, addr, next, prot, pages, nr))
return -ENOMEM;
} while (p4d++, addr = next, addr != end);
return 0;
}
static int vmap_page_range_noflush(unsigned long start, unsigned long end,
pgprot_t prot, struct page **pages)
{
pgd_t *pgd;
unsigned long next;
unsigned long addr = start;
int err = 0;
int nr = 0;
BUG_ON(addr >= end);
pgd = pgd_offset_k(addr);
do {
next = pgd_addr_end(addr, end);
err = vmap_p4d_range(pgd, addr, next, prot, pages, &nr);
if (err)
return err;
} while (pgd++, addr = next, addr != end);
return nr;
}
static int vmap_page_range(unsigned long start, unsigned long end,
pgprot_t prot, struct page **pages)
{
int ret;
ret = vmap_page_range_noflush(start, end, prot, pages);
flush_cache_vmap(start, end);
return ret;
}
int is_vmalloc_or_module_addr(const void *x)
{
#if defined(CONFIG_MODULES) && defined(MODULES_VADDR)
unsigned long addr = (unsigned long)x;
if (addr >= MODULES_VADDR && addr < MODULES_END)
return 1;
#endif
return is_vmalloc_addr(x);
}
struct page *vmalloc_to_page(const void *vmalloc_addr)
{
unsigned long addr = (unsigned long) vmalloc_addr;
struct page *page = NULL;
pgd_t *pgd = pgd_offset_k(addr);
p4d_t *p4d;
pud_t *pud;
pmd_t *pmd;
pte_t *ptep, pte;
VIRTUAL_BUG_ON(!is_vmalloc_or_module_addr(vmalloc_addr));
if (pgd_none(*pgd))
return NULL;
p4d = p4d_offset(pgd, addr);
if (p4d_none(*p4d))
return NULL;
pud = pud_offset(p4d, addr);
WARN_ON_ONCE(pud_bad(*pud));
if (pud_none(*pud) || pud_bad(*pud))
return NULL;
pmd = pmd_offset(pud, addr);
WARN_ON_ONCE(pmd_bad(*pmd));
if (pmd_none(*pmd) || pmd_bad(*pmd))
return NULL;
ptep = pte_offset_map(pmd, addr);
pte = *ptep;
if (pte_present(pte))
page = pte_page(pte);
pte_unmap(ptep);
return page;
}
unsigned long vmalloc_to_pfn(const void *vmalloc_addr)
{
return page_to_pfn(vmalloc_to_page(vmalloc_addr));
}
static struct vmap_area *__find_vmap_area(unsigned long addr)
{
struct rb_node *n = vmap_area_root.rb_node;
while (n) {
struct vmap_area *va;
va = rb_entry(n, struct vmap_area, rb_node);
if (addr < va->va_start)
n = n->rb_left;
else if (addr >= va->va_end)
n = n->rb_right;
else
return va;
}
return NULL;
}
static void __insert_vmap_area(struct vmap_area *va)
{
struct rb_node **p = &vmap_area_root.rb_node;
struct rb_node *parent = NULL;
struct rb_node *tmp;
while (*p) {
struct vmap_area *tmp_va;
parent = *p;
tmp_va = rb_entry(parent, struct vmap_area, rb_node);
if (va->va_start < tmp_va->va_end)
p = &(*p)->rb_left;
else if (va->va_end > tmp_va->va_start)
p = &(*p)->rb_right;
else
BUG();
}
rb_link_node(&va->rb_node, parent, p);
rb_insert_color(&va->rb_node, &vmap_area_root);
tmp = rb_prev(&va->rb_node);
if (tmp) {
struct vmap_area *prev;
prev = rb_entry(tmp, struct vmap_area, rb_node);
list_add_rcu(&va->list, &prev->list);
} else
list_add_rcu(&va->list, &vmap_area_list);
}
static struct vmap_area *alloc_vmap_area(unsigned long size,
unsigned long align,
unsigned long vstart, unsigned long vend,
int node, gfp_t gfp_mask)
{
struct vmap_area *va;
struct rb_node *n;
unsigned long addr;
int purged = 0;
struct vmap_area *first;
BUG_ON(!size);
BUG_ON(offset_in_page(size));
BUG_ON(!is_power_of_2(align));
might_sleep();
va = kmalloc_node(sizeof(struct vmap_area),
gfp_mask & GFP_RECLAIM_MASK, node);
if (unlikely(!va))
return ERR_PTR(-ENOMEM);
kmemleak_scan_area(&va->rb_node, SIZE_MAX, gfp_mask & GFP_RECLAIM_MASK);
retry:
spin_lock(&vmap_area_lock);
if (!free_vmap_cache ||
size < cached_hole_size ||
vstart < cached_vstart ||
align < cached_align) {
nocache:
cached_hole_size = 0;
free_vmap_cache = NULL;
}
cached_vstart = vstart;
cached_align = align;
if (free_vmap_cache) {
first = rb_entry(free_vmap_cache, struct vmap_area, rb_node);
addr = ALIGN(first->va_end, align);
if (addr < vstart)
goto nocache;
if (addr + size < addr)
goto overflow;
} else {
addr = ALIGN(vstart, align);
if (addr + size < addr)
goto overflow;
n = vmap_area_root.rb_node;
first = NULL;
while (n) {
struct vmap_area *tmp;
tmp = rb_entry(n, struct vmap_area, rb_node);
if (tmp->va_end >= addr) {
first = tmp;
if (tmp->va_start <= addr)
break;
n = n->rb_left;
} else
n = n->rb_right;
}
if (!first)
goto found;
}
while (addr + size > first->va_start && addr + size <= vend) {
if (addr + cached_hole_size < first->va_start)
cached_hole_size = first->va_start - addr;
addr = ALIGN(first->va_end, align);
if (addr + size < addr)
goto overflow;
if (list_is_last(&first->list, &vmap_area_list))
goto found;
first = list_next_entry(first, list);
}
found:
if (addr + size > vend)
goto overflow;
va->va_start = addr;
va->va_end = addr + size;
va->flags = 0;
__insert_vmap_area(va);
free_vmap_cache = &va->rb_node;
spin_unlock(&vmap_area_lock);
BUG_ON(!IS_ALIGNED(va->va_start, align));
BUG_ON(va->va_start < vstart);
BUG_ON(va->va_end > vend);
return va;
overflow:
spin_unlock(&vmap_area_lock);
if (!purged) {
purge_vmap_area_lazy();
purged = 1;
goto retry;
}
if (gfpflags_allow_blocking(gfp_mask)) {
unsigned long freed = 0;
blocking_notifier_call_chain(&vmap_notify_list, 0, &freed);
if (freed > 0) {
purged = 0;
goto retry;
}
}
if (!(gfp_mask & __GFP_NOWARN) && printk_ratelimit())
pr_warn("vmap allocation for size %lu failed: use vmalloc=<size> to increase size\n",
size);
kfree(va);
return ERR_PTR(-EBUSY);
}
int register_vmap_purge_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&vmap_notify_list, nb);
}
int unregister_vmap_purge_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&vmap_notify_list, nb);
}
static void __free_vmap_area(struct vmap_area *va)
{
BUG_ON(RB_EMPTY_NODE(&va->rb_node));
if (free_vmap_cache) {
if (va->va_end < cached_vstart) {
free_vmap_cache = NULL;
} else {
struct vmap_area *cache;
cache = rb_entry(free_vmap_cache, struct vmap_area, rb_node);
if (va->va_start <= cache->va_start) {
free_vmap_cache = rb_prev(&va->rb_node);
}
}
}
rb_erase(&va->rb_node, &vmap_area_root);
RB_CLEAR_NODE(&va->rb_node);
list_del_rcu(&va->list);
if (va->va_end > VMALLOC_START && va->va_end <= VMALLOC_END)
vmap_area_pcpu_hole = max(vmap_area_pcpu_hole, va->va_end);
kfree_rcu(va, rcu_head);
}
static void free_vmap_area(struct vmap_area *va)
{
spin_lock(&vmap_area_lock);
__free_vmap_area(va);
spin_unlock(&vmap_area_lock);
}
static void unmap_vmap_area(struct vmap_area *va)
{
vunmap_page_range(va->va_start, va->va_end);
}
static void vmap_debug_free_range(unsigned long start, unsigned long end)
{
if (debug_pagealloc_enabled()) {
vunmap_page_range(start, end);
flush_tlb_kernel_range(start, end);
}
}
static unsigned long lazy_max_pages(void)
{
unsigned int log;
log = fls(num_online_cpus());
return log * (32UL * 1024 * 1024 / PAGE_SIZE);
}
void set_iounmap_nonlazy(void)
{
atomic_set(&vmap_lazy_nr, lazy_max_pages()+1);
}
static bool __purge_vmap_area_lazy(unsigned long start, unsigned long end)
{
struct llist_node *valist;
struct vmap_area *va;
struct vmap_area *n_va;
bool do_free = false;
lockdep_assert_held(&vmap_purge_lock);
valist = llist_del_all(&vmap_purge_list);
llist_for_each_entry(va, valist, purge_list) {
if (va->va_start < start)
start = va->va_start;
if (va->va_end > end)
end = va->va_end;
do_free = true;
}
if (!do_free)
return false;
flush_tlb_kernel_range(start, end);
spin_lock(&vmap_area_lock);
llist_for_each_entry_safe(va, n_va, valist, purge_list) {
int nr = (va->va_end - va->va_start) >> PAGE_SHIFT;
__free_vmap_area(va);
atomic_sub(nr, &vmap_lazy_nr);
cond_resched_lock(&vmap_area_lock);
}
spin_unlock(&vmap_area_lock);
return true;
}
static void try_purge_vmap_area_lazy(void)
{
if (mutex_trylock(&vmap_purge_lock)) {
__purge_vmap_area_lazy(ULONG_MAX, 0);
mutex_unlock(&vmap_purge_lock);
}
}
static void purge_vmap_area_lazy(void)
{
mutex_lock(&vmap_purge_lock);
purge_fragmented_blocks_allcpus();
__purge_vmap_area_lazy(ULONG_MAX, 0);
mutex_unlock(&vmap_purge_lock);
}
static void free_vmap_area_noflush(struct vmap_area *va)
{
int nr_lazy;
nr_lazy = atomic_add_return((va->va_end - va->va_start) >> PAGE_SHIFT,
&vmap_lazy_nr);
llist_add(&va->purge_list, &vmap_purge_list);
if (unlikely(nr_lazy > lazy_max_pages()))
try_purge_vmap_area_lazy();
}
static void free_unmap_vmap_area(struct vmap_area *va)
{
flush_cache_vunmap(va->va_start, va->va_end);
unmap_vmap_area(va);
free_vmap_area_noflush(va);
}
static struct vmap_area *find_vmap_area(unsigned long addr)
{
struct vmap_area *va;
spin_lock(&vmap_area_lock);
va = __find_vmap_area(addr);
spin_unlock(&vmap_area_lock);
return va;
}
static unsigned long addr_to_vb_idx(unsigned long addr)
{
addr -= VMALLOC_START & ~(VMAP_BLOCK_SIZE-1);
addr /= VMAP_BLOCK_SIZE;
return addr;
}
static void *vmap_block_vaddr(unsigned long va_start, unsigned long pages_off)
{
unsigned long addr;
addr = va_start + (pages_off << PAGE_SHIFT);
BUG_ON(addr_to_vb_idx(addr) != addr_to_vb_idx(va_start));
return (void *)addr;
}
static void *new_vmap_block(unsigned int order, gfp_t gfp_mask)
{
struct vmap_block_queue *vbq;
struct vmap_block *vb;
struct vmap_area *va;
unsigned long vb_idx;
int node, err;
void *vaddr;
node = numa_node_id();
vb = kmalloc_node(sizeof(struct vmap_block),
gfp_mask & GFP_RECLAIM_MASK, node);
if (unlikely(!vb))
return ERR_PTR(-ENOMEM);
va = alloc_vmap_area(VMAP_BLOCK_SIZE, VMAP_BLOCK_SIZE,
VMALLOC_START, VMALLOC_END,
node, gfp_mask);
if (IS_ERR(va)) {
kfree(vb);
return ERR_CAST(va);
}
err = radix_tree_preload(gfp_mask);
if (unlikely(err)) {
kfree(vb);
free_vmap_area(va);
return ERR_PTR(err);
}
vaddr = vmap_block_vaddr(va->va_start, 0);
spin_lock_init(&vb->lock);
vb->va = va;
BUG_ON(VMAP_BBMAP_BITS <= (1UL << order));
vb->free = VMAP_BBMAP_BITS - (1UL << order);
vb->dirty = 0;
vb->dirty_min = VMAP_BBMAP_BITS;
vb->dirty_max = 0;
INIT_LIST_HEAD(&vb->free_list);
vb_idx = addr_to_vb_idx(va->va_start);
spin_lock(&vmap_block_tree_lock);
err = radix_tree_insert(&vmap_block_tree, vb_idx, vb);
spin_unlock(&vmap_block_tree_lock);
BUG_ON(err);
radix_tree_preload_end();
vbq = &get_cpu_var(vmap_block_queue);
spin_lock(&vbq->lock);
list_add_tail_rcu(&vb->free_list, &vbq->free);
spin_unlock(&vbq->lock);
put_cpu_var(vmap_block_queue);
return vaddr;
}
static void free_vmap_block(struct vmap_block *vb)
{
struct vmap_block *tmp;
unsigned long vb_idx;
vb_idx = addr_to_vb_idx(vb->va->va_start);
spin_lock(&vmap_block_tree_lock);
tmp = radix_tree_delete(&vmap_block_tree, vb_idx);
spin_unlock(&vmap_block_tree_lock);
BUG_ON(tmp != vb);
free_vmap_area_noflush(vb->va);
kfree_rcu(vb, rcu_head);
}
static void purge_fragmented_blocks(int cpu)
{
LIST_HEAD(purge);
struct vmap_block *vb;
struct vmap_block *n_vb;
struct vmap_block_queue *vbq = &per_cpu(vmap_block_queue, cpu);
rcu_read_lock();
list_for_each_entry_rcu(vb, &vbq->free, free_list) {
if (!(vb->free + vb->dirty == VMAP_BBMAP_BITS && vb->dirty != VMAP_BBMAP_BITS))
continue;
spin_lock(&vb->lock);
if (vb->free + vb->dirty == VMAP_BBMAP_BITS && vb->dirty != VMAP_BBMAP_BITS) {
vb->free = 0;
vb->dirty = VMAP_BBMAP_BITS;
vb->dirty_min = 0;
vb->dirty_max = VMAP_BBMAP_BITS;
spin_lock(&vbq->lock);
list_del_rcu(&vb->free_list);
spin_unlock(&vbq->lock);
spin_unlock(&vb->lock);
list_add_tail(&vb->purge, &purge);
} else
spin_unlock(&vb->lock);
}
rcu_read_unlock();
list_for_each_entry_safe(vb, n_vb, &purge, purge) {
list_del(&vb->purge);
free_vmap_block(vb);
}
}
static void purge_fragmented_blocks_allcpus(void)
{
int cpu;
for_each_possible_cpu(cpu)
purge_fragmented_blocks(cpu);
}
static void *vb_alloc(unsigned long size, gfp_t gfp_mask)
{
struct vmap_block_queue *vbq;
struct vmap_block *vb;
void *vaddr = NULL;
unsigned int order;
BUG_ON(offset_in_page(size));
BUG_ON(size > PAGE_SIZE*VMAP_MAX_ALLOC);
if (WARN_ON(size == 0)) {
return NULL;
}
order = get_order(size);
rcu_read_lock();
vbq = &get_cpu_var(vmap_block_queue);
list_for_each_entry_rcu(vb, &vbq->free, free_list) {
unsigned long pages_off;
spin_lock(&vb->lock);
if (vb->free < (1UL << order)) {
spin_unlock(&vb->lock);
continue;
}
pages_off = VMAP_BBMAP_BITS - vb->free;
vaddr = vmap_block_vaddr(vb->va->va_start, pages_off);
vb->free -= 1UL << order;
if (vb->free == 0) {
spin_lock(&vbq->lock);
list_del_rcu(&vb->free_list);
spin_unlock(&vbq->lock);
}
spin_unlock(&vb->lock);
break;
}
put_cpu_var(vmap_block_queue);
rcu_read_unlock();
if (!vaddr)
vaddr = new_vmap_block(order, gfp_mask);
return vaddr;
}
static void vb_free(const void *addr, unsigned long size)
{
unsigned long offset;
unsigned long vb_idx;
unsigned int order;
struct vmap_block *vb;
BUG_ON(offset_in_page(size));
BUG_ON(size > PAGE_SIZE*VMAP_MAX_ALLOC);
flush_cache_vunmap((unsigned long)addr, (unsigned long)addr + size);
order = get_order(size);
offset = (unsigned long)addr & (VMAP_BLOCK_SIZE - 1);
offset >>= PAGE_SHIFT;
vb_idx = addr_to_vb_idx((unsigned long)addr);
rcu_read_lock();
vb = radix_tree_lookup(&vmap_block_tree, vb_idx);
rcu_read_unlock();
BUG_ON(!vb);
vunmap_page_range((unsigned long)addr, (unsigned long)addr + size);
spin_lock(&vb->lock);
vb->dirty_min = min(vb->dirty_min, offset);
vb->dirty_max = max(vb->dirty_max, offset + (1UL << order));
vb->dirty += 1UL << order;
if (vb->dirty == VMAP_BBMAP_BITS) {
BUG_ON(vb->free);
spin_unlock(&vb->lock);
free_vmap_block(vb);
} else
spin_unlock(&vb->lock);
}
void vm_unmap_aliases(void)
{
unsigned long start = ULONG_MAX, end = 0;
int cpu;
int flush = 0;
if (unlikely(!vmap_initialized))
return;
might_sleep();
for_each_possible_cpu(cpu) {
struct vmap_block_queue *vbq = &per_cpu(vmap_block_queue, cpu);
struct vmap_block *vb;
rcu_read_lock();
list_for_each_entry_rcu(vb, &vbq->free, free_list) {
spin_lock(&vb->lock);
if (vb->dirty) {
unsigned long va_start = vb->va->va_start;
unsigned long s, e;
s = va_start + (vb->dirty_min << PAGE_SHIFT);
e = va_start + (vb->dirty_max << PAGE_SHIFT);
start = min(s, start);
end = max(e, end);
flush = 1;
}
spin_unlock(&vb->lock);
}
rcu_read_unlock();
}
mutex_lock(&vmap_purge_lock);
purge_fragmented_blocks_allcpus();
if (!__purge_vmap_area_lazy(start, end) && flush)
flush_tlb_kernel_range(start, end);
mutex_unlock(&vmap_purge_lock);
}
void vm_unmap_ram(const void *mem, unsigned int count)
{
unsigned long size = (unsigned long)count << PAGE_SHIFT;
unsigned long addr = (unsigned long)mem;
struct vmap_area *va;
might_sleep();
BUG_ON(!addr);
BUG_ON(addr < VMALLOC_START);
BUG_ON(addr > VMALLOC_END);
BUG_ON(!PAGE_ALIGNED(addr));
debug_check_no_locks_freed(mem, size);
vmap_debug_free_range(addr, addr+size);
if (likely(count <= VMAP_MAX_ALLOC)) {
vb_free(mem, size);
return;
}
va = find_vmap_area(addr);
BUG_ON(!va);
free_unmap_vmap_area(va);
}
void *vm_map_ram(struct page **pages, unsigned int count, int node, pgprot_t prot)
{
unsigned long size = (unsigned long)count << PAGE_SHIFT;
unsigned long addr;
void *mem;
if (likely(count <= VMAP_MAX_ALLOC)) {
mem = vb_alloc(size, GFP_KERNEL);
if (IS_ERR(mem))
return NULL;
addr = (unsigned long)mem;
} else {
struct vmap_area *va;
va = alloc_vmap_area(size, PAGE_SIZE,
VMALLOC_START, VMALLOC_END, node, GFP_KERNEL);
if (IS_ERR(va))
return NULL;
addr = va->va_start;
mem = (void *)addr;
}
if (vmap_page_range(addr, addr + size, prot, pages) < 0) {
vm_unmap_ram(mem, count);
return NULL;
}
return mem;
}
void __init vm_area_add_early(struct vm_struct *vm)
{
struct vm_struct *tmp, **p;
BUG_ON(vmap_initialized);
for (p = &vmlist; (tmp = *p) != NULL; p = &tmp->next) {
if (tmp->addr >= vm->addr) {
BUG_ON(tmp->addr < vm->addr + vm->size);
break;
} else
BUG_ON(tmp->addr + tmp->size > vm->addr);
}
vm->next = *p;
*p = vm;
}
void __init vm_area_register_early(struct vm_struct *vm, size_t align)
{
static size_t vm_init_off __initdata;
unsigned long addr;
addr = ALIGN(VMALLOC_START + vm_init_off, align);
vm_init_off = PFN_ALIGN(addr + vm->size) - VMALLOC_START;
vm->addr = (void *)addr;
vm_area_add_early(vm);
}
void __init vmalloc_init(void)
{
struct vmap_area *va;
struct vm_struct *tmp;
int i;
for_each_possible_cpu(i) {
struct vmap_block_queue *vbq;
struct vfree_deferred *p;
vbq = &per_cpu(vmap_block_queue, i);
spin_lock_init(&vbq->lock);
INIT_LIST_HEAD(&vbq->free);
p = &per_cpu(vfree_deferred, i);
init_llist_head(&p->list);
INIT_WORK(&p->wq, free_work);
}
for (tmp = vmlist; tmp; tmp = tmp->next) {
va = kzalloc(sizeof(struct vmap_area), GFP_NOWAIT);
va->flags = VM_VM_AREA;
va->va_start = (unsigned long)tmp->addr;
va->va_end = va->va_start + tmp->size;
va->vm = tmp;
__insert_vmap_area(va);
}
vmap_area_pcpu_hole = VMALLOC_END;
vmap_initialized = true;
}
int map_kernel_range_noflush(unsigned long addr, unsigned long size,
pgprot_t prot, struct page **pages)
{
return vmap_page_range_noflush(addr, addr + size, prot, pages);
}
void unmap_kernel_range_noflush(unsigned long addr, unsigned long size)
{
vunmap_page_range(addr, addr + size);
}
void unmap_kernel_range(unsigned long addr, unsigned long size)
{
unsigned long end = addr + size;
flush_cache_vunmap(addr, end);
vunmap_page_range(addr, end);
flush_tlb_kernel_range(addr, end);
}
int map_vm_area(struct vm_struct *area, pgprot_t prot, struct page **pages)
{
unsigned long addr = (unsigned long)area->addr;
unsigned long end = addr + get_vm_area_size(area);
int err;
err = vmap_page_range(addr, end, prot, pages);
return err > 0 ? 0 : err;
}
static void setup_vmalloc_vm(struct vm_struct *vm, struct vmap_area *va,
unsigned long flags, const void *caller)
{
spin_lock(&vmap_area_lock);
vm->flags = flags;
vm->addr = (void *)va->va_start;
vm->size = va->va_end - va->va_start;
vm->caller = caller;
va->vm = vm;
va->flags |= VM_VM_AREA;
spin_unlock(&vmap_area_lock);
}
static void clear_vm_uninitialized_flag(struct vm_struct *vm)
{
smp_wmb();
vm->flags &= ~VM_UNINITIALIZED;
}
static struct vm_struct *__get_vm_area_node(unsigned long size,
unsigned long align, unsigned long flags, unsigned long start,
unsigned long end, int node, gfp_t gfp_mask, const void *caller)
{
struct vmap_area *va;
struct vm_struct *area;
BUG_ON(in_interrupt());
size = PAGE_ALIGN(size);
if (unlikely(!size))
return NULL;
if (flags & VM_IOREMAP)
align = 1ul << clamp_t(int, get_count_order_long(size),
PAGE_SHIFT, IOREMAP_MAX_ORDER);
area = kzalloc_node(sizeof(*area), gfp_mask & GFP_RECLAIM_MASK, node);
if (unlikely(!area))
return NULL;
if (!(flags & VM_NO_GUARD))
size += PAGE_SIZE;
va = alloc_vmap_area(size, align, start, end, node, gfp_mask);
if (IS_ERR(va)) {
kfree(area);
return NULL;
}
setup_vmalloc_vm(area, va, flags, caller);
return area;
}
struct vm_struct *__get_vm_area(unsigned long size, unsigned long flags,
unsigned long start, unsigned long end)
{
return __get_vm_area_node(size, 1, flags, start, end, NUMA_NO_NODE,
GFP_KERNEL, __builtin_return_address(0));
}
struct vm_struct *__get_vm_area_caller(unsigned long size, unsigned long flags,
unsigned long start, unsigned long end,
const void *caller)
{
return __get_vm_area_node(size, 1, flags, start, end, NUMA_NO_NODE,
GFP_KERNEL, caller);
}
struct vm_struct *get_vm_area(unsigned long size, unsigned long flags)
{
return __get_vm_area_node(size, 1, flags, VMALLOC_START, VMALLOC_END,
NUMA_NO_NODE, GFP_KERNEL,
__builtin_return_address(0));
}
struct vm_struct *get_vm_area_caller(unsigned long size, unsigned long flags,
const void *caller)
{
return __get_vm_area_node(size, 1, flags, VMALLOC_START, VMALLOC_END,
NUMA_NO_NODE, GFP_KERNEL, caller);
}
struct vm_struct *find_vm_area(const void *addr)
{
struct vmap_area *va;
va = find_vmap_area((unsigned long)addr);
if (va && va->flags & VM_VM_AREA)
return va->vm;
return NULL;
}
struct vm_struct *remove_vm_area(const void *addr)
{
struct vmap_area *va;
might_sleep();
va = find_vmap_area((unsigned long)addr);
if (va && va->flags & VM_VM_AREA) {
struct vm_struct *vm = va->vm;
spin_lock(&vmap_area_lock);
va->vm = NULL;
va->flags &= ~VM_VM_AREA;
va->flags |= VM_LAZY_FREE;
spin_unlock(&vmap_area_lock);
vmap_debug_free_range(va->va_start, va->va_end);
kasan_free_shadow(vm);
free_unmap_vmap_area(va);
return vm;
}
return NULL;
}
static void __vunmap(const void *addr, int deallocate_pages)
{
struct vm_struct *area;
if (!addr)
return;
if (WARN(!PAGE_ALIGNED(addr), "Trying to vfree() bad address (%p)\n",
addr))
return;
area = remove_vm_area(addr);
if (unlikely(!area)) {
WARN(1, KERN_ERR "Trying to vfree() nonexistent vm area (%p)\n",
addr);
return;
}
debug_check_no_locks_freed(addr, get_vm_area_size(area));
debug_check_no_obj_freed(addr, get_vm_area_size(area));
if (deallocate_pages) {
int i;
for (i = 0; i < area->nr_pages; i++) {
struct page *page = area->pages[i];
BUG_ON(!page);
__free_pages(page, 0);
}
kvfree(area->pages);
}
kfree(area);
return;
}
static inline void __vfree_deferred(const void *addr)
{
struct vfree_deferred *p = raw_cpu_ptr(&vfree_deferred);
if (llist_add((struct llist_node *)addr, &p->list))
schedule_work(&p->wq);
}
void vfree_atomic(const void *addr)
{
BUG_ON(in_nmi());
kmemleak_free(addr);
if (!addr)
return;
__vfree_deferred(addr);
}
void vfree(const void *addr)
{
BUG_ON(in_nmi());
kmemleak_free(addr);
if (!addr)
return;
if (unlikely(in_interrupt()))
__vfree_deferred(addr);
else
__vunmap(addr, 1);
}
void vunmap(const void *addr)
{
BUG_ON(in_interrupt());
might_sleep();
if (addr)
__vunmap(addr, 0);
}
void *vmap(struct page **pages, unsigned int count,
unsigned long flags, pgprot_t prot)
{
struct vm_struct *area;
unsigned long size;
might_sleep();
if (count > totalram_pages)
return NULL;
size = (unsigned long)count << PAGE_SHIFT;
area = get_vm_area_caller(size, flags, __builtin_return_address(0));
if (!area)
return NULL;
if (map_vm_area(area, prot, pages)) {
vunmap(area->addr);
return NULL;
}
return area->addr;
}
static void *__vmalloc_area_node(struct vm_struct *area, gfp_t gfp_mask,
pgprot_t prot, int node)
{
struct page **pages;
unsigned int nr_pages, array_size, i;
const gfp_t nested_gfp = (gfp_mask & GFP_RECLAIM_MASK) | __GFP_ZERO;
const gfp_t alloc_mask = gfp_mask | __GFP_NOWARN;
const gfp_t highmem_mask = (gfp_mask & (GFP_DMA | GFP_DMA32)) ?
0 :
__GFP_HIGHMEM;
nr_pages = get_vm_area_size(area) >> PAGE_SHIFT;
array_size = (nr_pages * sizeof(struct page *));
area->nr_pages = nr_pages;
if (array_size > PAGE_SIZE) {
pages = __vmalloc_node(array_size, 1, nested_gfp|highmem_mask,
PAGE_KERNEL, node, area->caller);
} else {
pages = kmalloc_node(array_size, nested_gfp, node);
}
area->pages = pages;
if (!area->pages) {
remove_vm_area(area->addr);
kfree(area);
return NULL;
}
for (i = 0; i < area->nr_pages; i++) {
struct page *page;
if (node == NUMA_NO_NODE)
page = alloc_page(alloc_mask|highmem_mask);
else
page = alloc_pages_node(node, alloc_mask|highmem_mask, 0);
if (unlikely(!page)) {
area->nr_pages = i;
goto fail;
}
area->pages[i] = page;
if (gfpflags_allow_blocking(gfp_mask|highmem_mask))
cond_resched();
}
if (map_vm_area(area, prot, pages))
goto fail;
return area->addr;
fail:
warn_alloc(gfp_mask, NULL,
"vmalloc: allocation failure, allocated %ld of %ld bytes",
(area->nr_pages*PAGE_SIZE), area->size);
vfree(area->addr);
return NULL;
}
void *__vmalloc_node_range(unsigned long size, unsigned long align,
unsigned long start, unsigned long end, gfp_t gfp_mask,
pgprot_t prot, unsigned long vm_flags, int node,
const void *caller)
{
struct vm_struct *area;
void *addr;
unsigned long real_size = size;
size = PAGE_ALIGN(size);
if (!size || (size >> PAGE_SHIFT) > totalram_pages)
goto fail;
area = __get_vm_area_node(size, align, VM_ALLOC | VM_UNINITIALIZED |
vm_flags, start, end, node, gfp_mask, caller);
if (!area)
goto fail;
addr = __vmalloc_area_node(area, gfp_mask, prot, node);
if (!addr)
return NULL;
clear_vm_uninitialized_flag(area);
kmemleak_vmalloc(area, size, gfp_mask);
return addr;
fail:
warn_alloc(gfp_mask, NULL,
"vmalloc: allocation failure: %lu bytes", real_size);
return NULL;
}
static void *__vmalloc_node(unsigned long size, unsigned long align,
gfp_t gfp_mask, pgprot_t prot,
int node, const void *caller)
{
return __vmalloc_node_range(size, align, VMALLOC_START, VMALLOC_END,
gfp_mask, prot, 0, node, caller);
}
void *__vmalloc(unsigned long size, gfp_t gfp_mask, pgprot_t prot)
{
return __vmalloc_node(size, 1, gfp_mask, prot, NUMA_NO_NODE,
__builtin_return_address(0));
}
static inline void *__vmalloc_node_flags(unsigned long size,
int node, gfp_t flags)
{
return __vmalloc_node(size, 1, flags, PAGE_KERNEL,
node, __builtin_return_address(0));
}
void *__vmalloc_node_flags_caller(unsigned long size, int node, gfp_t flags,
void *caller)
{
return __vmalloc_node(size, 1, flags, PAGE_KERNEL, node, caller);
}
void *vmalloc(unsigned long size)
{
return __vmalloc_node_flags(size, NUMA_NO_NODE,
GFP_KERNEL);
}
void *vzalloc(unsigned long size)
{
return __vmalloc_node_flags(size, NUMA_NO_NODE,
GFP_KERNEL | __GFP_ZERO);
}
void *vmalloc_user(unsigned long size)
{
struct vm_struct *area;
void *ret;
ret = __vmalloc_node(size, SHMLBA,
GFP_KERNEL | __GFP_ZERO,
PAGE_KERNEL, NUMA_NO_NODE,
__builtin_return_address(0));
if (ret) {
area = find_vm_area(ret);
area->flags |= VM_USERMAP;
}
return ret;
}
void *vmalloc_node(unsigned long size, int node)
{
return __vmalloc_node(size, 1, GFP_KERNEL, PAGE_KERNEL,
node, __builtin_return_address(0));
}
void *vzalloc_node(unsigned long size, int node)
{
return __vmalloc_node_flags(size, node,
GFP_KERNEL | __GFP_ZERO);
}
void *vmalloc_exec(unsigned long size)
{
return __vmalloc_node(size, 1, GFP_KERNEL, PAGE_KERNEL_EXEC,
NUMA_NO_NODE, __builtin_return_address(0));
}
void *vmalloc_32(unsigned long size)
{
return __vmalloc_node(size, 1, GFP_VMALLOC32, PAGE_KERNEL,
NUMA_NO_NODE, __builtin_return_address(0));
}
void *vmalloc_32_user(unsigned long size)
{
struct vm_struct *area;
void *ret;
ret = __vmalloc_node(size, 1, GFP_VMALLOC32 | __GFP_ZERO, PAGE_KERNEL,
NUMA_NO_NODE, __builtin_return_address(0));
if (ret) {
area = find_vm_area(ret);
area->flags |= VM_USERMAP;
}
return ret;
}
static int aligned_vread(char *buf, char *addr, unsigned long count)
{
struct page *p;
int copied = 0;
while (count) {
unsigned long offset, length;
offset = offset_in_page(addr);
length = PAGE_SIZE - offset;
if (length > count)
length = count;
p = vmalloc_to_page(addr);
if (p) {
void *map = kmap_atomic(p);
memcpy(buf, map + offset, length);
kunmap_atomic(map);
} else
memset(buf, 0, length);
addr += length;
buf += length;
copied += length;
count -= length;
}
return copied;
}
static int aligned_vwrite(char *buf, char *addr, unsigned long count)
{
struct page *p;
int copied = 0;
while (count) {
unsigned long offset, length;
offset = offset_in_page(addr);
length = PAGE_SIZE - offset;
if (length > count)
length = count;
p = vmalloc_to_page(addr);
if (p) {
void *map = kmap_atomic(p);
memcpy(map + offset, buf, length);
kunmap_atomic(map);
}
addr += length;
buf += length;
copied += length;
count -= length;
}
return copied;
}
long vread(char *buf, char *addr, unsigned long count)
{
struct vmap_area *va;
struct vm_struct *vm;
char *vaddr, *buf_start = buf;
unsigned long buflen = count;
unsigned long n;
if ((unsigned long) addr + count < count)
count = -(unsigned long) addr;
spin_lock(&vmap_area_lock);
list_for_each_entry(va, &vmap_area_list, list) {
if (!count)
break;
if (!(va->flags & VM_VM_AREA))
continue;
vm = va->vm;
vaddr = (char *) vm->addr;
if (addr >= vaddr + get_vm_area_size(vm))
continue;
while (addr < vaddr) {
if (count == 0)
goto finished;
*buf = '\0';
buf++;
addr++;
count--;
}
n = vaddr + get_vm_area_size(vm) - addr;
if (n > count)
n = count;
if (!(vm->flags & VM_IOREMAP))
aligned_vread(buf, addr, n);
else
memset(buf, 0, n);
buf += n;
addr += n;
count -= n;
}
finished:
spin_unlock(&vmap_area_lock);
if (buf == buf_start)
return 0;
if (buf != buf_start + buflen)
memset(buf, 0, buflen - (buf - buf_start));
return buflen;
}
long vwrite(char *buf, char *addr, unsigned long count)
{
struct vmap_area *va;
struct vm_struct *vm;
char *vaddr;
unsigned long n, buflen;
int copied = 0;
if ((unsigned long) addr + count < count)
count = -(unsigned long) addr;
buflen = count;
spin_lock(&vmap_area_lock);
list_for_each_entry(va, &vmap_area_list, list) {
if (!count)
break;
if (!(va->flags & VM_VM_AREA))
continue;
vm = va->vm;
vaddr = (char *) vm->addr;
if (addr >= vaddr + get_vm_area_size(vm))
continue;
while (addr < vaddr) {
if (count == 0)
goto finished;
buf++;
addr++;
count--;
}
n = vaddr + get_vm_area_size(vm) - addr;
if (n > count)
n = count;
if (!(vm->flags & VM_IOREMAP)) {
aligned_vwrite(buf, addr, n);
copied++;
}
buf += n;
addr += n;
count -= n;
}
finished:
spin_unlock(&vmap_area_lock);
if (!copied)
return 0;
return buflen;
}
int remap_vmalloc_range_partial(struct vm_area_struct *vma, unsigned long uaddr,
void *kaddr, unsigned long size)
{
struct vm_struct *area;
size = PAGE_ALIGN(size);
if (!PAGE_ALIGNED(uaddr) || !PAGE_ALIGNED(kaddr))
return -EINVAL;
area = find_vm_area(kaddr);
if (!area)
return -EINVAL;
if (!(area->flags & VM_USERMAP))
return -EINVAL;
if (kaddr + size > area->addr + area->size)
return -EINVAL;
do {
struct page *page = vmalloc_to_page(kaddr);
int ret;
ret = vm_insert_page(vma, uaddr, page);
if (ret)
return ret;
uaddr += PAGE_SIZE;
kaddr += PAGE_SIZE;
size -= PAGE_SIZE;
} while (size > 0);
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
return 0;
}
int remap_vmalloc_range(struct vm_area_struct *vma, void *addr,
unsigned long pgoff)
{
return remap_vmalloc_range_partial(vma, vma->vm_start,
addr + (pgoff << PAGE_SHIFT),
vma->vm_end - vma->vm_start);
}
void __weak vmalloc_sync_all(void)
{
}
static int f(pte_t *pte, pgtable_t table, unsigned long addr, void *data)
{
pte_t ***p = data;
if (p) {
*(*p) = pte;
(*p)++;
}
return 0;
}
struct vm_struct *alloc_vm_area(size_t size, pte_t **ptes)
{
struct vm_struct *area;
area = get_vm_area_caller(size, VM_IOREMAP,
__builtin_return_address(0));
if (area == NULL)
return NULL;
if (apply_to_page_range(&init_mm, (unsigned long)area->addr,
size, f, ptes ? &ptes : NULL)) {
free_vm_area(area);
return NULL;
}
return area;
}
void free_vm_area(struct vm_struct *area)
{
struct vm_struct *ret;
ret = remove_vm_area(area->addr);
BUG_ON(ret != area);
kfree(area);
}
static struct vmap_area *node_to_va(struct rb_node *n)
{
return rb_entry_safe(n, struct vmap_area, rb_node);
}
static bool pvm_find_next_prev(unsigned long end,
struct vmap_area **pnext,
struct vmap_area **pprev)
{
struct rb_node *n = vmap_area_root.rb_node;
struct vmap_area *va = NULL;
while (n) {
va = rb_entry(n, struct vmap_area, rb_node);
if (end < va->va_end)
n = n->rb_left;
else if (end > va->va_end)
n = n->rb_right;
else
break;
}
if (!va)
return false;
if (va->va_end > end) {
*pnext = va;
*pprev = node_to_va(rb_prev(&(*pnext)->rb_node));
} else {
*pprev = va;
*pnext = node_to_va(rb_next(&(*pprev)->rb_node));
}
return true;
}
static unsigned long pvm_determine_end(struct vmap_area **pnext,
struct vmap_area **pprev,
unsigned long align)
{
const unsigned long vmalloc_end = VMALLOC_END & ~(align - 1);
unsigned long addr;
if (*pnext)
addr = min((*pnext)->va_start & ~(align - 1), vmalloc_end);
else
addr = vmalloc_end;
while (*pprev && (*pprev)->va_end > addr) {
*pnext = *pprev;
*pprev = node_to_va(rb_prev(&(*pnext)->rb_node));
}
return addr;
}
struct vm_struct **pcpu_get_vm_areas(const unsigned long *offsets,
const size_t *sizes, int nr_vms,
size_t align)
{
const unsigned long vmalloc_start = ALIGN(VMALLOC_START, align);
const unsigned long vmalloc_end = VMALLOC_END & ~(align - 1);
struct vmap_area **vas, *prev, *next;
struct vm_struct **vms;
int area, area2, last_area, term_area;
unsigned long base, start, end, last_end;
bool purged = false;
BUG_ON(offset_in_page(align) || !is_power_of_2(align));
for (last_area = 0, area = 0; area < nr_vms; area++) {
start = offsets[area];
end = start + sizes[area];
BUG_ON(!IS_ALIGNED(offsets[area], align));
BUG_ON(!IS_ALIGNED(sizes[area], align));
if (start > offsets[last_area])
last_area = area;
for (area2 = area + 1; area2 < nr_vms; area2++) {
unsigned long start2 = offsets[area2];
unsigned long end2 = start2 + sizes[area2];
BUG_ON(start2 < end && start < end2);
}
}
last_end = offsets[last_area] + sizes[last_area];
if (vmalloc_end - vmalloc_start < last_end) {
WARN_ON(true);
return NULL;
}
vms = kcalloc(nr_vms, sizeof(vms[0]), GFP_KERNEL);
vas = kcalloc(nr_vms, sizeof(vas[0]), GFP_KERNEL);
if (!vas || !vms)
goto err_free2;
for (area = 0; area < nr_vms; area++) {
vas[area] = kzalloc(sizeof(struct vmap_area), GFP_KERNEL);
vms[area] = kzalloc(sizeof(struct vm_struct), GFP_KERNEL);
if (!vas[area] || !vms[area])
goto err_free;
}
retry:
spin_lock(&vmap_area_lock);
area = term_area = last_area;
start = offsets[area];
end = start + sizes[area];
if (!pvm_find_next_prev(vmap_area_pcpu_hole, &next, &prev)) {
base = vmalloc_end - last_end;
goto found;
}
base = pvm_determine_end(&next, &prev, align) - end;
while (true) {
BUG_ON(next && next->va_end <= base + end);
BUG_ON(prev && prev->va_end > base + end);
if (base + last_end < vmalloc_start + last_end) {
spin_unlock(&vmap_area_lock);
if (!purged) {
purge_vmap_area_lazy();
purged = true;
goto retry;
}
goto err_free;
}
if (next && next->va_start < base + end) {
base = pvm_determine_end(&next, &prev, align) - end;
term_area = area;
continue;
}
if (prev && prev->va_end > base + start) {
next = prev;
prev = node_to_va(rb_prev(&next->rb_node));
base = pvm_determine_end(&next, &prev, align) - end;
term_area = area;
continue;
}
area = (area + nr_vms - 1) % nr_vms;
if (area == term_area)
break;
start = offsets[area];
end = start + sizes[area];
pvm_find_next_prev(base + end, &next, &prev);
}
found:
for (area = 0; area < nr_vms; area++) {
struct vmap_area *va = vas[area];
va->va_start = base + offsets[area];
va->va_end = va->va_start + sizes[area];
__insert_vmap_area(va);
}
vmap_area_pcpu_hole = base + offsets[last_area];
spin_unlock(&vmap_area_lock);
for (area = 0; area < nr_vms; area++)
setup_vmalloc_vm(vms[area], vas[area], VM_ALLOC,
pcpu_get_vm_areas);
kfree(vas);
return vms;
err_free:
for (area = 0; area < nr_vms; area++) {
kfree(vas[area]);
kfree(vms[area]);
}
err_free2:
kfree(vas);
kfree(vms);
return NULL;
}
void pcpu_free_vm_areas(struct vm_struct **vms, int nr_vms)
{
int i;
for (i = 0; i < nr_vms; i++)
free_vm_area(vms[i]);
kfree(vms);
}
static void *s_start(struct seq_file *m, loff_t *pos)
__acquires(&vmap_area_lock
static void *s_next(struct seq_file *m, void *p, loff_t *pos)
{
return seq_list_next(p, &vmap_area_list, pos);
}
static void s_stop(struct seq_file *m, void *p)
__releases(&vmap_area_lock
static void show_numa_info(struct seq_file *m, struct vm_struct *v)
{
if (IS_ENABLED(CONFIG_NUMA)) {
unsigned int nr, *counters = m->private;
if (!counters)
return;
if (v->flags & VM_UNINITIALIZED)
return;
smp_rmb();
memset(counters, 0, nr_node_ids * sizeof(unsigned int));
for (nr = 0; nr < v->nr_pages; nr++)
counters[page_to_nid(v->pages[nr])]++;
for_each_node_state(nr, N_HIGH_MEMORY)
if (counters[nr])
seq_printf(m, " N%u=%u", nr, counters[nr]);
}
}
static int s_show(struct seq_file *m, void *p)
{
struct vmap_area *va;
struct vm_struct *v;
va = list_entry(p, struct vmap_area, list);
if (!(va->flags & VM_VM_AREA)) {
seq_printf(m, "0x%pK-0x%pK %7ld %s\n",
(void *)va->va_start, (void *)va->va_end,
va->va_end - va->va_start,
va->flags & VM_LAZY_FREE ? "unpurged vm_area" : "vm_map_ram");
return 0;
}
v = va->vm;
seq_printf(m, "0x%pK-0x%pK %7ld",
v->addr, v->addr + v->size, v->size);
if (v->caller)
seq_printf(m, " %pS", v->caller);
if (v->nr_pages)
seq_printf(m, " pages=%d", v->nr_pages);
if (v->phys_addr)
seq_printf(m, " phys=%pa", &v->phys_addr);
if (v->flags & VM_IOREMAP)
seq_puts(m, " ioremap");
if (v->flags & VM_ALLOC)
seq_puts(m, " vmalloc");
if (v->flags & VM_MAP)
seq_puts(m, " vmap");
if (v->flags & VM_USERMAP)
seq_puts(m, " user");
if (is_vmalloc_addr(v->pages))
seq_puts(m, " vpages");
show_numa_info(m, v);
seq_putc(m, '\n');
return 0;
}
static int vmalloc_open(struct inode *inode, struct file *file)
{
if (IS_ENABLED(CONFIG_NUMA))
return seq_open_private(file, &vmalloc_op,
nr_node_ids * sizeof(unsigned int));
else
return seq_open(file, &vmalloc_op);
}
static int __init proc_vmalloc_init(void)
{
proc_create("vmallocinfo", S_IRUSR, NULL, &proc_vmalloc_operations);
return 0;
}
