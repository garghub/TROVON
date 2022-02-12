static inline void unlock_or_release_subpool(struct hugepage_subpool *spool)
{
bool free = (spool->count == 0) && (spool->used_hpages == 0);
spin_unlock(&spool->lock);
if (free)
kfree(spool);
}
struct hugepage_subpool *hugepage_new_subpool(long nr_blocks)
{
struct hugepage_subpool *spool;
spool = kmalloc(sizeof(*spool), GFP_KERNEL);
if (!spool)
return NULL;
spin_lock_init(&spool->lock);
spool->count = 1;
spool->max_hpages = nr_blocks;
spool->used_hpages = 0;
return spool;
}
void hugepage_put_subpool(struct hugepage_subpool *spool)
{
spin_lock(&spool->lock);
BUG_ON(!spool->count);
spool->count--;
unlock_or_release_subpool(spool);
}
static int hugepage_subpool_get_pages(struct hugepage_subpool *spool,
long delta)
{
int ret = 0;
if (!spool)
return 0;
spin_lock(&spool->lock);
if ((spool->used_hpages + delta) <= spool->max_hpages) {
spool->used_hpages += delta;
} else {
ret = -ENOMEM;
}
spin_unlock(&spool->lock);
return ret;
}
static void hugepage_subpool_put_pages(struct hugepage_subpool *spool,
long delta)
{
if (!spool)
return;
spin_lock(&spool->lock);
spool->used_hpages -= delta;
unlock_or_release_subpool(spool);
}
static inline struct hugepage_subpool *subpool_inode(struct inode *inode)
{
return HUGETLBFS_SB(inode->i_sb)->spool;
}
static inline struct hugepage_subpool *subpool_vma(struct vm_area_struct *vma)
{
return subpool_inode(file_inode(vma->vm_file));
}
static long region_add(struct list_head *head, long f, long t)
{
struct file_region *rg, *nrg, *trg;
list_for_each_entry(rg, head, link)
if (f <= rg->to)
break;
if (f > rg->from)
f = rg->from;
nrg = rg;
list_for_each_entry_safe(rg, trg, rg->link.prev, link) {
if (&rg->link == head)
break;
if (rg->from > t)
break;
if (rg->to > t)
t = rg->to;
if (rg != nrg) {
list_del(&rg->link);
kfree(rg);
}
}
nrg->from = f;
nrg->to = t;
return 0;
}
static long region_chg(struct list_head *head, long f, long t)
{
struct file_region *rg, *nrg;
long chg = 0;
list_for_each_entry(rg, head, link)
if (f <= rg->to)
break;
if (&rg->link == head || t < rg->from) {
nrg = kmalloc(sizeof(*nrg), GFP_KERNEL);
if (!nrg)
return -ENOMEM;
nrg->from = f;
nrg->to = f;
INIT_LIST_HEAD(&nrg->link);
list_add(&nrg->link, rg->link.prev);
return t - f;
}
if (f > rg->from)
f = rg->from;
chg = t - f;
list_for_each_entry(rg, rg->link.prev, link) {
if (&rg->link == head)
break;
if (rg->from > t)
return chg;
if (rg->to > t) {
chg += rg->to - t;
t = rg->to;
}
chg -= rg->to - rg->from;
}
return chg;
}
static long region_truncate(struct list_head *head, long end)
{
struct file_region *rg, *trg;
long chg = 0;
list_for_each_entry(rg, head, link)
if (end <= rg->to)
break;
if (&rg->link == head)
return 0;
if (end > rg->from) {
chg = rg->to - end;
rg->to = end;
rg = list_entry(rg->link.next, typeof(*rg), link);
}
list_for_each_entry_safe(rg, trg, rg->link.prev, link) {
if (&rg->link == head)
break;
chg += rg->to - rg->from;
list_del(&rg->link);
kfree(rg);
}
return chg;
}
static long region_count(struct list_head *head, long f, long t)
{
struct file_region *rg;
long chg = 0;
list_for_each_entry(rg, head, link) {
long seg_from;
long seg_to;
if (rg->to <= f)
continue;
if (rg->from >= t)
break;
seg_from = max(rg->from, f);
seg_to = min(rg->to, t);
chg += seg_to - seg_from;
}
return chg;
}
static pgoff_t vma_hugecache_offset(struct hstate *h,
struct vm_area_struct *vma, unsigned long address)
{
return ((address - vma->vm_start) >> huge_page_shift(h)) +
(vma->vm_pgoff >> huge_page_order(h));
}
pgoff_t linear_hugepage_index(struct vm_area_struct *vma,
unsigned long address)
{
return vma_hugecache_offset(hstate_vma(vma), vma, address);
}
unsigned long vma_kernel_pagesize(struct vm_area_struct *vma)
{
struct hstate *hstate;
if (!is_vm_hugetlb_page(vma))
return PAGE_SIZE;
hstate = hstate_vma(vma);
return 1UL << huge_page_shift(hstate);
}
unsigned long vma_mmu_pagesize(struct vm_area_struct *vma)
{
return vma_kernel_pagesize(vma);
}
static unsigned long get_vma_private_data(struct vm_area_struct *vma)
{
return (unsigned long)vma->vm_private_data;
}
static void set_vma_private_data(struct vm_area_struct *vma,
unsigned long value)
{
vma->vm_private_data = (void *)value;
}
static struct resv_map *resv_map_alloc(void)
{
struct resv_map *resv_map = kmalloc(sizeof(*resv_map), GFP_KERNEL);
if (!resv_map)
return NULL;
kref_init(&resv_map->refs);
INIT_LIST_HEAD(&resv_map->regions);
return resv_map;
}
static void resv_map_release(struct kref *ref)
{
struct resv_map *resv_map = container_of(ref, struct resv_map, refs);
region_truncate(&resv_map->regions, 0);
kfree(resv_map);
}
static struct resv_map *vma_resv_map(struct vm_area_struct *vma)
{
VM_BUG_ON(!is_vm_hugetlb_page(vma));
if (!(vma->vm_flags & VM_MAYSHARE))
return (struct resv_map *)(get_vma_private_data(vma) &
~HPAGE_RESV_MASK);
return NULL;
}
static void set_vma_resv_map(struct vm_area_struct *vma, struct resv_map *map)
{
VM_BUG_ON(!is_vm_hugetlb_page(vma));
VM_BUG_ON(vma->vm_flags & VM_MAYSHARE);
set_vma_private_data(vma, (get_vma_private_data(vma) &
HPAGE_RESV_MASK) | (unsigned long)map);
}
static void set_vma_resv_flags(struct vm_area_struct *vma, unsigned long flags)
{
VM_BUG_ON(!is_vm_hugetlb_page(vma));
VM_BUG_ON(vma->vm_flags & VM_MAYSHARE);
set_vma_private_data(vma, get_vma_private_data(vma) | flags);
}
static int is_vma_resv_set(struct vm_area_struct *vma, unsigned long flag)
{
VM_BUG_ON(!is_vm_hugetlb_page(vma));
return (get_vma_private_data(vma) & flag) != 0;
}
static void decrement_hugepage_resv_vma(struct hstate *h,
struct vm_area_struct *vma)
{
if (vma->vm_flags & VM_NORESERVE)
return;
if (vma->vm_flags & VM_MAYSHARE) {
h->resv_huge_pages--;
} else if (is_vma_resv_set(vma, HPAGE_RESV_OWNER)) {
h->resv_huge_pages--;
}
}
void reset_vma_resv_huge_pages(struct vm_area_struct *vma)
{
VM_BUG_ON(!is_vm_hugetlb_page(vma));
if (!(vma->vm_flags & VM_MAYSHARE))
vma->vm_private_data = (void *)0;
}
static int vma_has_reserves(struct vm_area_struct *vma)
{
if (vma->vm_flags & VM_MAYSHARE)
return 1;
if (is_vma_resv_set(vma, HPAGE_RESV_OWNER))
return 1;
return 0;
}
static void copy_gigantic_page(struct page *dst, struct page *src)
{
int i;
struct hstate *h = page_hstate(src);
struct page *dst_base = dst;
struct page *src_base = src;
for (i = 0; i < pages_per_huge_page(h); ) {
cond_resched();
copy_highpage(dst, src);
i++;
dst = mem_map_next(dst, dst_base, i);
src = mem_map_next(src, src_base, i);
}
}
void copy_huge_page(struct page *dst, struct page *src)
{
int i;
struct hstate *h = page_hstate(src);
if (unlikely(pages_per_huge_page(h) > MAX_ORDER_NR_PAGES)) {
copy_gigantic_page(dst, src);
return;
}
might_sleep();
for (i = 0; i < pages_per_huge_page(h); i++) {
cond_resched();
copy_highpage(dst + i, src + i);
}
}
static void enqueue_huge_page(struct hstate *h, struct page *page)
{
int nid = page_to_nid(page);
list_move(&page->lru, &h->hugepage_freelists[nid]);
h->free_huge_pages++;
h->free_huge_pages_node[nid]++;
}
static struct page *dequeue_huge_page_node(struct hstate *h, int nid)
{
struct page *page;
if (list_empty(&h->hugepage_freelists[nid]))
return NULL;
page = list_entry(h->hugepage_freelists[nid].next, struct page, lru);
list_move(&page->lru, &h->hugepage_activelist);
set_page_refcounted(page);
h->free_huge_pages--;
h->free_huge_pages_node[nid]--;
return page;
}
static struct page *dequeue_huge_page_vma(struct hstate *h,
struct vm_area_struct *vma,
unsigned long address, int avoid_reserve)
{
struct page *page = NULL;
struct mempolicy *mpol;
nodemask_t *nodemask;
struct zonelist *zonelist;
struct zone *zone;
struct zoneref *z;
unsigned int cpuset_mems_cookie;
retry_cpuset:
cpuset_mems_cookie = get_mems_allowed();
zonelist = huge_zonelist(vma, address,
htlb_alloc_mask, &mpol, &nodemask);
if (!vma_has_reserves(vma) &&
h->free_huge_pages - h->resv_huge_pages == 0)
goto err;
if (avoid_reserve && h->free_huge_pages - h->resv_huge_pages == 0)
goto err;
for_each_zone_zonelist_nodemask(zone, z, zonelist,
MAX_NR_ZONES - 1, nodemask) {
if (cpuset_zone_allowed_softwall(zone, htlb_alloc_mask)) {
page = dequeue_huge_page_node(h, zone_to_nid(zone));
if (page) {
if (!avoid_reserve)
decrement_hugepage_resv_vma(h, vma);
break;
}
}
}
mpol_cond_put(mpol);
if (unlikely(!put_mems_allowed(cpuset_mems_cookie) && !page))
goto retry_cpuset;
return page;
err:
mpol_cond_put(mpol);
return NULL;
}
static void update_and_free_page(struct hstate *h, struct page *page)
{
int i;
VM_BUG_ON(h->order >= MAX_ORDER);
h->nr_huge_pages--;
h->nr_huge_pages_node[page_to_nid(page)]--;
for (i = 0; i < pages_per_huge_page(h); i++) {
page[i].flags &= ~(1 << PG_locked | 1 << PG_error |
1 << PG_referenced | 1 << PG_dirty |
1 << PG_active | 1 << PG_reserved |
1 << PG_private | 1 << PG_writeback);
}
VM_BUG_ON(hugetlb_cgroup_from_page(page));
set_compound_page_dtor(page, NULL);
set_page_refcounted(page);
arch_release_hugepage(page);
__free_pages(page, huge_page_order(h));
}
struct hstate *size_to_hstate(unsigned long size)
{
struct hstate *h;
for_each_hstate(h) {
if (huge_page_size(h) == size)
return h;
}
return NULL;
}
static void free_huge_page(struct page *page)
{
struct hstate *h = page_hstate(page);
int nid = page_to_nid(page);
struct hugepage_subpool *spool =
(struct hugepage_subpool *)page_private(page);
set_page_private(page, 0);
page->mapping = NULL;
BUG_ON(page_count(page));
BUG_ON(page_mapcount(page));
spin_lock(&hugetlb_lock);
hugetlb_cgroup_uncharge_page(hstate_index(h),
pages_per_huge_page(h), page);
if (h->surplus_huge_pages_node[nid] && huge_page_order(h) < MAX_ORDER) {
list_del(&page->lru);
update_and_free_page(h, page);
h->surplus_huge_pages--;
h->surplus_huge_pages_node[nid]--;
} else {
arch_clear_hugepage_flags(page);
enqueue_huge_page(h, page);
}
spin_unlock(&hugetlb_lock);
hugepage_subpool_put_pages(spool, 1);
}
static void prep_new_huge_page(struct hstate *h, struct page *page, int nid)
{
INIT_LIST_HEAD(&page->lru);
set_compound_page_dtor(page, free_huge_page);
spin_lock(&hugetlb_lock);
set_hugetlb_cgroup(page, NULL);
h->nr_huge_pages++;
h->nr_huge_pages_node[nid]++;
spin_unlock(&hugetlb_lock);
put_page(page);
}
static void prep_compound_gigantic_page(struct page *page, unsigned long order)
{
int i;
int nr_pages = 1 << order;
struct page *p = page + 1;
set_compound_order(page, order);
__SetPageHead(page);
for (i = 1; i < nr_pages; i++, p = mem_map_next(p, page, i)) {
__SetPageTail(p);
set_page_count(p, 0);
p->first_page = page;
}
}
int PageHuge(struct page *page)
{
compound_page_dtor *dtor;
if (!PageCompound(page))
return 0;
page = compound_head(page);
dtor = get_compound_page_dtor(page);
return dtor == free_huge_page;
}
pgoff_t __basepage_index(struct page *page)
{
struct page *page_head = compound_head(page);
pgoff_t index = page_index(page_head);
unsigned long compound_idx;
if (!PageHuge(page_head))
return page_index(page);
if (compound_order(page_head) >= MAX_ORDER)
compound_idx = page_to_pfn(page) - page_to_pfn(page_head);
else
compound_idx = page - page_head;
return (index << compound_order(page_head)) + compound_idx;
}
static struct page *alloc_fresh_huge_page_node(struct hstate *h, int nid)
{
struct page *page;
if (h->order >= MAX_ORDER)
return NULL;
page = alloc_pages_exact_node(nid,
htlb_alloc_mask|__GFP_COMP|__GFP_THISNODE|
__GFP_REPEAT|__GFP_NOWARN,
huge_page_order(h));
if (page) {
if (arch_prepare_hugepage(page)) {
__free_pages(page, huge_page_order(h));
return NULL;
}
prep_new_huge_page(h, page, nid);
}
return page;
}
static int next_node_allowed(int nid, nodemask_t *nodes_allowed)
{
nid = next_node(nid, *nodes_allowed);
if (nid == MAX_NUMNODES)
nid = first_node(*nodes_allowed);
VM_BUG_ON(nid >= MAX_NUMNODES);
return nid;
}
static int get_valid_node_allowed(int nid, nodemask_t *nodes_allowed)
{
if (!node_isset(nid, *nodes_allowed))
nid = next_node_allowed(nid, nodes_allowed);
return nid;
}
static int hstate_next_node_to_alloc(struct hstate *h,
nodemask_t *nodes_allowed)
{
int nid;
VM_BUG_ON(!nodes_allowed);
nid = get_valid_node_allowed(h->next_nid_to_alloc, nodes_allowed);
h->next_nid_to_alloc = next_node_allowed(nid, nodes_allowed);
return nid;
}
static int alloc_fresh_huge_page(struct hstate *h, nodemask_t *nodes_allowed)
{
struct page *page;
int start_nid;
int next_nid;
int ret = 0;
start_nid = hstate_next_node_to_alloc(h, nodes_allowed);
next_nid = start_nid;
do {
page = alloc_fresh_huge_page_node(h, next_nid);
if (page) {
ret = 1;
break;
}
next_nid = hstate_next_node_to_alloc(h, nodes_allowed);
} while (next_nid != start_nid);
if (ret)
count_vm_event(HTLB_BUDDY_PGALLOC);
else
count_vm_event(HTLB_BUDDY_PGALLOC_FAIL);
return ret;
}
static int hstate_next_node_to_free(struct hstate *h, nodemask_t *nodes_allowed)
{
int nid;
VM_BUG_ON(!nodes_allowed);
nid = get_valid_node_allowed(h->next_nid_to_free, nodes_allowed);
h->next_nid_to_free = next_node_allowed(nid, nodes_allowed);
return nid;
}
static int free_pool_huge_page(struct hstate *h, nodemask_t *nodes_allowed,
bool acct_surplus)
{
int start_nid;
int next_nid;
int ret = 0;
start_nid = hstate_next_node_to_free(h, nodes_allowed);
next_nid = start_nid;
do {
if ((!acct_surplus || h->surplus_huge_pages_node[next_nid]) &&
!list_empty(&h->hugepage_freelists[next_nid])) {
struct page *page =
list_entry(h->hugepage_freelists[next_nid].next,
struct page, lru);
list_del(&page->lru);
h->free_huge_pages--;
h->free_huge_pages_node[next_nid]--;
if (acct_surplus) {
h->surplus_huge_pages--;
h->surplus_huge_pages_node[next_nid]--;
}
update_and_free_page(h, page);
ret = 1;
break;
}
next_nid = hstate_next_node_to_free(h, nodes_allowed);
} while (next_nid != start_nid);
return ret;
}
static struct page *alloc_buddy_huge_page(struct hstate *h, int nid)
{
struct page *page;
unsigned int r_nid;
if (h->order >= MAX_ORDER)
return NULL;
spin_lock(&hugetlb_lock);
if (h->surplus_huge_pages >= h->nr_overcommit_huge_pages) {
spin_unlock(&hugetlb_lock);
return NULL;
} else {
h->nr_huge_pages++;
h->surplus_huge_pages++;
}
spin_unlock(&hugetlb_lock);
if (nid == NUMA_NO_NODE)
page = alloc_pages(htlb_alloc_mask|__GFP_COMP|
__GFP_REPEAT|__GFP_NOWARN,
huge_page_order(h));
else
page = alloc_pages_exact_node(nid,
htlb_alloc_mask|__GFP_COMP|__GFP_THISNODE|
__GFP_REPEAT|__GFP_NOWARN, huge_page_order(h));
if (page && arch_prepare_hugepage(page)) {
__free_pages(page, huge_page_order(h));
page = NULL;
}
spin_lock(&hugetlb_lock);
if (page) {
INIT_LIST_HEAD(&page->lru);
r_nid = page_to_nid(page);
set_compound_page_dtor(page, free_huge_page);
set_hugetlb_cgroup(page, NULL);
h->nr_huge_pages_node[r_nid]++;
h->surplus_huge_pages_node[r_nid]++;
__count_vm_event(HTLB_BUDDY_PGALLOC);
} else {
h->nr_huge_pages--;
h->surplus_huge_pages--;
__count_vm_event(HTLB_BUDDY_PGALLOC_FAIL);
}
spin_unlock(&hugetlb_lock);
return page;
}
struct page *alloc_huge_page_node(struct hstate *h, int nid)
{
struct page *page;
spin_lock(&hugetlb_lock);
page = dequeue_huge_page_node(h, nid);
spin_unlock(&hugetlb_lock);
if (!page)
page = alloc_buddy_huge_page(h, nid);
return page;
}
static int gather_surplus_pages(struct hstate *h, int delta)
{
struct list_head surplus_list;
struct page *page, *tmp;
int ret, i;
int needed, allocated;
bool alloc_ok = true;
needed = (h->resv_huge_pages + delta) - h->free_huge_pages;
if (needed <= 0) {
h->resv_huge_pages += delta;
return 0;
}
allocated = 0;
INIT_LIST_HEAD(&surplus_list);
ret = -ENOMEM;
retry:
spin_unlock(&hugetlb_lock);
for (i = 0; i < needed; i++) {
page = alloc_buddy_huge_page(h, NUMA_NO_NODE);
if (!page) {
alloc_ok = false;
break;
}
list_add(&page->lru, &surplus_list);
}
allocated += i;
spin_lock(&hugetlb_lock);
needed = (h->resv_huge_pages + delta) -
(h->free_huge_pages + allocated);
if (needed > 0) {
if (alloc_ok)
goto retry;
goto free;
}
needed += allocated;
h->resv_huge_pages += delta;
ret = 0;
list_for_each_entry_safe(page, tmp, &surplus_list, lru) {
if ((--needed) < 0)
break;
put_page_testzero(page);
VM_BUG_ON(page_count(page));
enqueue_huge_page(h, page);
}
free:
spin_unlock(&hugetlb_lock);
if (!list_empty(&surplus_list)) {
list_for_each_entry_safe(page, tmp, &surplus_list, lru) {
put_page(page);
}
}
spin_lock(&hugetlb_lock);
return ret;
}
static void return_unused_surplus_pages(struct hstate *h,
unsigned long unused_resv_pages)
{
unsigned long nr_pages;
h->resv_huge_pages -= unused_resv_pages;
if (h->order >= MAX_ORDER)
return;
nr_pages = min(unused_resv_pages, h->surplus_huge_pages);
while (nr_pages--) {
if (!free_pool_huge_page(h, &node_states[N_MEMORY], 1))
break;
}
}
static long vma_needs_reservation(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
struct address_space *mapping = vma->vm_file->f_mapping;
struct inode *inode = mapping->host;
if (vma->vm_flags & VM_MAYSHARE) {
pgoff_t idx = vma_hugecache_offset(h, vma, addr);
return region_chg(&inode->i_mapping->private_list,
idx, idx + 1);
} else if (!is_vma_resv_set(vma, HPAGE_RESV_OWNER)) {
return 1;
} else {
long err;
pgoff_t idx = vma_hugecache_offset(h, vma, addr);
struct resv_map *reservations = vma_resv_map(vma);
err = region_chg(&reservations->regions, idx, idx + 1);
if (err < 0)
return err;
return 0;
}
}
static void vma_commit_reservation(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
struct address_space *mapping = vma->vm_file->f_mapping;
struct inode *inode = mapping->host;
if (vma->vm_flags & VM_MAYSHARE) {
pgoff_t idx = vma_hugecache_offset(h, vma, addr);
region_add(&inode->i_mapping->private_list, idx, idx + 1);
} else if (is_vma_resv_set(vma, HPAGE_RESV_OWNER)) {
pgoff_t idx = vma_hugecache_offset(h, vma, addr);
struct resv_map *reservations = vma_resv_map(vma);
region_add(&reservations->regions, idx, idx + 1);
}
}
static struct page *alloc_huge_page(struct vm_area_struct *vma,
unsigned long addr, int avoid_reserve)
{
struct hugepage_subpool *spool = subpool_vma(vma);
struct hstate *h = hstate_vma(vma);
struct page *page;
long chg;
int ret, idx;
struct hugetlb_cgroup *h_cg;
idx = hstate_index(h);
chg = vma_needs_reservation(h, vma, addr);
if (chg < 0)
return ERR_PTR(-ENOMEM);
if (chg)
if (hugepage_subpool_get_pages(spool, chg))
return ERR_PTR(-ENOSPC);
ret = hugetlb_cgroup_charge_cgroup(idx, pages_per_huge_page(h), &h_cg);
if (ret) {
hugepage_subpool_put_pages(spool, chg);
return ERR_PTR(-ENOSPC);
}
spin_lock(&hugetlb_lock);
page = dequeue_huge_page_vma(h, vma, addr, avoid_reserve);
if (page) {
hugetlb_cgroup_commit_charge(idx, pages_per_huge_page(h),
h_cg, page);
spin_unlock(&hugetlb_lock);
} else {
spin_unlock(&hugetlb_lock);
page = alloc_buddy_huge_page(h, NUMA_NO_NODE);
if (!page) {
hugetlb_cgroup_uncharge_cgroup(idx,
pages_per_huge_page(h),
h_cg);
hugepage_subpool_put_pages(spool, chg);
return ERR_PTR(-ENOSPC);
}
spin_lock(&hugetlb_lock);
hugetlb_cgroup_commit_charge(idx, pages_per_huge_page(h),
h_cg, page);
list_move(&page->lru, &h->hugepage_activelist);
spin_unlock(&hugetlb_lock);
}
set_page_private(page, (unsigned long)spool);
vma_commit_reservation(h, vma, addr);
return page;
}
int __weak alloc_bootmem_huge_page(struct hstate *h)
{
struct huge_bootmem_page *m;
int nr_nodes = nodes_weight(node_states[N_MEMORY]);
while (nr_nodes) {
void *addr;
addr = __alloc_bootmem_node_nopanic(
NODE_DATA(hstate_next_node_to_alloc(h,
&node_states[N_MEMORY])),
huge_page_size(h), huge_page_size(h), 0);
if (addr) {
m = addr;
goto found;
}
nr_nodes--;
}
return 0;
found:
BUG_ON((unsigned long)virt_to_phys(m) & (huge_page_size(h) - 1));
list_add(&m->list, &huge_boot_pages);
m->hstate = h;
return 1;
}
static void prep_compound_huge_page(struct page *page, int order)
{
if (unlikely(order > (MAX_ORDER - 1)))
prep_compound_gigantic_page(page, order);
else
prep_compound_page(page, order);
}
static void __init gather_bootmem_prealloc(void)
{
struct huge_bootmem_page *m;
list_for_each_entry(m, &huge_boot_pages, list) {
struct hstate *h = m->hstate;
struct page *page;
#ifdef CONFIG_HIGHMEM
page = pfn_to_page(m->phys >> PAGE_SHIFT);
free_bootmem_late((unsigned long)m,
sizeof(struct huge_bootmem_page));
#else
page = virt_to_page(m);
#endif
__ClearPageReserved(page);
WARN_ON(page_count(page) != 1);
prep_compound_huge_page(page, h->order);
prep_new_huge_page(h, page, page_to_nid(page));
if (h->order > (MAX_ORDER - 1))
adjust_managed_page_count(page, 1 << h->order);
}
}
static void __init hugetlb_hstate_alloc_pages(struct hstate *h)
{
unsigned long i;
for (i = 0; i < h->max_huge_pages; ++i) {
if (h->order >= MAX_ORDER) {
if (!alloc_bootmem_huge_page(h))
break;
} else if (!alloc_fresh_huge_page(h,
&node_states[N_MEMORY]))
break;
}
h->max_huge_pages = i;
}
static void __init hugetlb_init_hstates(void)
{
struct hstate *h;
for_each_hstate(h) {
if (h->order < MAX_ORDER)
hugetlb_hstate_alloc_pages(h);
}
}
static char * __init memfmt(char *buf, unsigned long n)
{
if (n >= (1UL << 30))
sprintf(buf, "%lu GB", n >> 30);
else if (n >= (1UL << 20))
sprintf(buf, "%lu MB", n >> 20);
else
sprintf(buf, "%lu KB", n >> 10);
return buf;
}
static void __init report_hugepages(void)
{
struct hstate *h;
for_each_hstate(h) {
char buf[32];
pr_info("HugeTLB registered %s page size, pre-allocated %ld pages\n",
memfmt(buf, huge_page_size(h)),
h->free_huge_pages);
}
}
static void try_to_free_low(struct hstate *h, unsigned long count,
nodemask_t *nodes_allowed)
{
int i;
if (h->order >= MAX_ORDER)
return;
for_each_node_mask(i, *nodes_allowed) {
struct page *page, *next;
struct list_head *freel = &h->hugepage_freelists[i];
list_for_each_entry_safe(page, next, freel, lru) {
if (count >= h->nr_huge_pages)
return;
if (PageHighMem(page))
continue;
list_del(&page->lru);
update_and_free_page(h, page);
h->free_huge_pages--;
h->free_huge_pages_node[page_to_nid(page)]--;
}
}
}
static inline void try_to_free_low(struct hstate *h, unsigned long count,
nodemask_t *nodes_allowed)
{
}
static int adjust_pool_surplus(struct hstate *h, nodemask_t *nodes_allowed,
int delta)
{
int start_nid, next_nid;
int ret = 0;
VM_BUG_ON(delta != -1 && delta != 1);
if (delta < 0)
start_nid = hstate_next_node_to_alloc(h, nodes_allowed);
else
start_nid = hstate_next_node_to_free(h, nodes_allowed);
next_nid = start_nid;
do {
int nid = next_nid;
if (delta < 0) {
if (!h->surplus_huge_pages_node[nid]) {
next_nid = hstate_next_node_to_alloc(h,
nodes_allowed);
continue;
}
}
if (delta > 0) {
if (h->surplus_huge_pages_node[nid] >=
h->nr_huge_pages_node[nid]) {
next_nid = hstate_next_node_to_free(h,
nodes_allowed);
continue;
}
}
h->surplus_huge_pages += delta;
h->surplus_huge_pages_node[nid] += delta;
ret = 1;
break;
} while (next_nid != start_nid);
return ret;
}
static unsigned long set_max_huge_pages(struct hstate *h, unsigned long count,
nodemask_t *nodes_allowed)
{
unsigned long min_count, ret;
if (h->order >= MAX_ORDER)
return h->max_huge_pages;
spin_lock(&hugetlb_lock);
while (h->surplus_huge_pages && count > persistent_huge_pages(h)) {
if (!adjust_pool_surplus(h, nodes_allowed, -1))
break;
}
while (count > persistent_huge_pages(h)) {
spin_unlock(&hugetlb_lock);
ret = alloc_fresh_huge_page(h, nodes_allowed);
spin_lock(&hugetlb_lock);
if (!ret)
goto out;
if (signal_pending(current))
goto out;
}
min_count = h->resv_huge_pages + h->nr_huge_pages - h->free_huge_pages;
min_count = max(count, min_count);
try_to_free_low(h, min_count, nodes_allowed);
while (min_count < persistent_huge_pages(h)) {
if (!free_pool_huge_page(h, nodes_allowed, 0))
break;
}
while (count < persistent_huge_pages(h)) {
if (!adjust_pool_surplus(h, nodes_allowed, 1))
break;
}
out:
ret = persistent_huge_pages(h);
spin_unlock(&hugetlb_lock);
return ret;
}
static struct hstate *kobj_to_hstate(struct kobject *kobj, int *nidp)
{
int i;
for (i = 0; i < HUGE_MAX_HSTATE; i++)
if (hstate_kobjs[i] == kobj) {
if (nidp)
*nidp = NUMA_NO_NODE;
return &hstates[i];
}
return kobj_to_node_hstate(kobj, nidp);
}
static ssize_t nr_hugepages_show_common(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct hstate *h;
unsigned long nr_huge_pages;
int nid;
h = kobj_to_hstate(kobj, &nid);
if (nid == NUMA_NO_NODE)
nr_huge_pages = h->nr_huge_pages;
else
nr_huge_pages = h->nr_huge_pages_node[nid];
return sprintf(buf, "%lu\n", nr_huge_pages);
}
static ssize_t nr_hugepages_store_common(bool obey_mempolicy,
struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t len)
{
int err;
int nid;
unsigned long count;
struct hstate *h;
NODEMASK_ALLOC(nodemask_t, nodes_allowed, GFP_KERNEL | __GFP_NORETRY);
err = strict_strtoul(buf, 10, &count);
if (err)
goto out;
h = kobj_to_hstate(kobj, &nid);
if (h->order >= MAX_ORDER) {
err = -EINVAL;
goto out;
}
if (nid == NUMA_NO_NODE) {
if (!(obey_mempolicy &&
init_nodemask_of_mempolicy(nodes_allowed))) {
NODEMASK_FREE(nodes_allowed);
nodes_allowed = &node_states[N_MEMORY];
}
} else if (nodes_allowed) {
count += h->nr_huge_pages - h->nr_huge_pages_node[nid];
init_nodemask_of_node(nodes_allowed, nid);
} else
nodes_allowed = &node_states[N_MEMORY];
h->max_huge_pages = set_max_huge_pages(h, count, nodes_allowed);
if (nodes_allowed != &node_states[N_MEMORY])
NODEMASK_FREE(nodes_allowed);
return len;
out:
NODEMASK_FREE(nodes_allowed);
return err;
}
static ssize_t nr_hugepages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return nr_hugepages_show_common(kobj, attr, buf);
}
static ssize_t nr_hugepages_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t len)
{
return nr_hugepages_store_common(false, kobj, attr, buf, len);
}
static ssize_t nr_hugepages_mempolicy_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return nr_hugepages_show_common(kobj, attr, buf);
}
static ssize_t nr_hugepages_mempolicy_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t len)
{
return nr_hugepages_store_common(true, kobj, attr, buf, len);
}
static ssize_t nr_overcommit_hugepages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct hstate *h = kobj_to_hstate(kobj, NULL);
return sprintf(buf, "%lu\n", h->nr_overcommit_huge_pages);
}
static ssize_t nr_overcommit_hugepages_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
int err;
unsigned long input;
struct hstate *h = kobj_to_hstate(kobj, NULL);
if (h->order >= MAX_ORDER)
return -EINVAL;
err = strict_strtoul(buf, 10, &input);
if (err)
return err;
spin_lock(&hugetlb_lock);
h->nr_overcommit_huge_pages = input;
spin_unlock(&hugetlb_lock);
return count;
}
static ssize_t free_hugepages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct hstate *h;
unsigned long free_huge_pages;
int nid;
h = kobj_to_hstate(kobj, &nid);
if (nid == NUMA_NO_NODE)
free_huge_pages = h->free_huge_pages;
else
free_huge_pages = h->free_huge_pages_node[nid];
return sprintf(buf, "%lu\n", free_huge_pages);
}
static ssize_t resv_hugepages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct hstate *h = kobj_to_hstate(kobj, NULL);
return sprintf(buf, "%lu\n", h->resv_huge_pages);
}
static ssize_t surplus_hugepages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct hstate *h;
unsigned long surplus_huge_pages;
int nid;
h = kobj_to_hstate(kobj, &nid);
if (nid == NUMA_NO_NODE)
surplus_huge_pages = h->surplus_huge_pages;
else
surplus_huge_pages = h->surplus_huge_pages_node[nid];
return sprintf(buf, "%lu\n", surplus_huge_pages);
}
static int hugetlb_sysfs_add_hstate(struct hstate *h, struct kobject *parent,
struct kobject **hstate_kobjs,
struct attribute_group *hstate_attr_group)
{
int retval;
int hi = hstate_index(h);
hstate_kobjs[hi] = kobject_create_and_add(h->name, parent);
if (!hstate_kobjs[hi])
return -ENOMEM;
retval = sysfs_create_group(hstate_kobjs[hi], hstate_attr_group);
if (retval)
kobject_put(hstate_kobjs[hi]);
return retval;
}
static void __init hugetlb_sysfs_init(void)
{
struct hstate *h;
int err;
hugepages_kobj = kobject_create_and_add("hugepages", mm_kobj);
if (!hugepages_kobj)
return;
for_each_hstate(h) {
err = hugetlb_sysfs_add_hstate(h, hugepages_kobj,
hstate_kobjs, &hstate_attr_group);
if (err)
pr_err("Hugetlb: Unable to add hstate %s", h->name);
}
}
static struct hstate *kobj_to_node_hstate(struct kobject *kobj, int *nidp)
{
int nid;
for (nid = 0; nid < nr_node_ids; nid++) {
struct node_hstate *nhs = &node_hstates[nid];
int i;
for (i = 0; i < HUGE_MAX_HSTATE; i++)
if (nhs->hstate_kobjs[i] == kobj) {
if (nidp)
*nidp = nid;
return &hstates[i];
}
}
BUG();
return NULL;
}
static void hugetlb_unregister_node(struct node *node)
{
struct hstate *h;
struct node_hstate *nhs = &node_hstates[node->dev.id];
if (!nhs->hugepages_kobj)
return;
for_each_hstate(h) {
int idx = hstate_index(h);
if (nhs->hstate_kobjs[idx]) {
kobject_put(nhs->hstate_kobjs[idx]);
nhs->hstate_kobjs[idx] = NULL;
}
}
kobject_put(nhs->hugepages_kobj);
nhs->hugepages_kobj = NULL;
}
static void hugetlb_unregister_all_nodes(void)
{
int nid;
register_hugetlbfs_with_node(NULL, NULL);
for (nid = 0; nid < nr_node_ids; nid++)
hugetlb_unregister_node(node_devices[nid]);
}
static void hugetlb_register_node(struct node *node)
{
struct hstate *h;
struct node_hstate *nhs = &node_hstates[node->dev.id];
int err;
if (nhs->hugepages_kobj)
return;
nhs->hugepages_kobj = kobject_create_and_add("hugepages",
&node->dev.kobj);
if (!nhs->hugepages_kobj)
return;
for_each_hstate(h) {
err = hugetlb_sysfs_add_hstate(h, nhs->hugepages_kobj,
nhs->hstate_kobjs,
&per_node_hstate_attr_group);
if (err) {
pr_err("Hugetlb: Unable to add hstate %s for node %d\n",
h->name, node->dev.id);
hugetlb_unregister_node(node);
break;
}
}
}
static void hugetlb_register_all_nodes(void)
{
int nid;
for_each_node_state(nid, N_MEMORY) {
struct node *node = node_devices[nid];
if (node->dev.id == nid)
hugetlb_register_node(node);
}
register_hugetlbfs_with_node(hugetlb_register_node,
hugetlb_unregister_node);
}
static struct hstate *kobj_to_node_hstate(struct kobject *kobj, int *nidp)
{
BUG();
if (nidp)
*nidp = -1;
return NULL;
}
static void hugetlb_unregister_all_nodes(void) { }
static void hugetlb_register_all_nodes(void) { }
static void __exit hugetlb_exit(void)
{
struct hstate *h;
hugetlb_unregister_all_nodes();
for_each_hstate(h) {
kobject_put(hstate_kobjs[hstate_index(h)]);
}
kobject_put(hugepages_kobj);
}
static int __init hugetlb_init(void)
{
if (HPAGE_SHIFT == 0)
return 0;
if (!size_to_hstate(default_hstate_size)) {
default_hstate_size = HPAGE_SIZE;
if (!size_to_hstate(default_hstate_size))
hugetlb_add_hstate(HUGETLB_PAGE_ORDER);
}
default_hstate_idx = hstate_index(size_to_hstate(default_hstate_size));
if (default_hstate_max_huge_pages)
default_hstate.max_huge_pages = default_hstate_max_huge_pages;
hugetlb_init_hstates();
gather_bootmem_prealloc();
report_hugepages();
hugetlb_sysfs_init();
hugetlb_register_all_nodes();
hugetlb_cgroup_file_init();
return 0;
}
void __init hugetlb_add_hstate(unsigned order)
{
struct hstate *h;
unsigned long i;
if (size_to_hstate(PAGE_SIZE << order)) {
pr_warning("hugepagesz= specified twice, ignoring\n");
return;
}
BUG_ON(hugetlb_max_hstate >= HUGE_MAX_HSTATE);
BUG_ON(order == 0);
h = &hstates[hugetlb_max_hstate++];
h->order = order;
h->mask = ~((1ULL << (order + PAGE_SHIFT)) - 1);
h->nr_huge_pages = 0;
h->free_huge_pages = 0;
for (i = 0; i < MAX_NUMNODES; ++i)
INIT_LIST_HEAD(&h->hugepage_freelists[i]);
INIT_LIST_HEAD(&h->hugepage_activelist);
h->next_nid_to_alloc = first_node(node_states[N_MEMORY]);
h->next_nid_to_free = first_node(node_states[N_MEMORY]);
snprintf(h->name, HSTATE_NAME_LEN, "hugepages-%lukB",
huge_page_size(h)/1024);
parsed_hstate = h;
}
static int __init hugetlb_nrpages_setup(char *s)
{
unsigned long *mhp;
static unsigned long *last_mhp;
if (!hugetlb_max_hstate)
mhp = &default_hstate_max_huge_pages;
else
mhp = &parsed_hstate->max_huge_pages;
if (mhp == last_mhp) {
pr_warning("hugepages= specified twice without "
"interleaving hugepagesz=, ignoring\n");
return 1;
}
if (sscanf(s, "%lu", mhp) <= 0)
*mhp = 0;
if (hugetlb_max_hstate && parsed_hstate->order >= MAX_ORDER)
hugetlb_hstate_alloc_pages(parsed_hstate);
last_mhp = mhp;
return 1;
}
static int __init hugetlb_default_setup(char *s)
{
default_hstate_size = memparse(s, &s);
return 1;
}
static unsigned int cpuset_mems_nr(unsigned int *array)
{
int node;
unsigned int nr = 0;
for_each_node_mask(node, cpuset_current_mems_allowed)
nr += array[node];
return nr;
}
static int hugetlb_sysctl_handler_common(bool obey_mempolicy,
struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
struct hstate *h = &default_hstate;
unsigned long tmp;
int ret;
tmp = h->max_huge_pages;
if (write && h->order >= MAX_ORDER)
return -EINVAL;
table->data = &tmp;
table->maxlen = sizeof(unsigned long);
ret = proc_doulongvec_minmax(table, write, buffer, length, ppos);
if (ret)
goto out;
if (write) {
NODEMASK_ALLOC(nodemask_t, nodes_allowed,
GFP_KERNEL | __GFP_NORETRY);
if (!(obey_mempolicy &&
init_nodemask_of_mempolicy(nodes_allowed))) {
NODEMASK_FREE(nodes_allowed);
nodes_allowed = &node_states[N_MEMORY];
}
h->max_huge_pages = set_max_huge_pages(h, tmp, nodes_allowed);
if (nodes_allowed != &node_states[N_MEMORY])
NODEMASK_FREE(nodes_allowed);
}
out:
return ret;
}
int hugetlb_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
return hugetlb_sysctl_handler_common(false, table, write,
buffer, length, ppos);
}
int hugetlb_mempolicy_sysctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *length, loff_t *ppos)
{
return hugetlb_sysctl_handler_common(true, table, write,
buffer, length, ppos);
}
int hugetlb_treat_movable_handler(struct ctl_table *table, int write,
void __user *buffer,
size_t *length, loff_t *ppos)
{
proc_dointvec(table, write, buffer, length, ppos);
if (hugepages_treat_as_movable)
htlb_alloc_mask = GFP_HIGHUSER_MOVABLE;
else
htlb_alloc_mask = GFP_HIGHUSER;
return 0;
}
int hugetlb_overcommit_handler(struct ctl_table *table, int write,
void __user *buffer,
size_t *length, loff_t *ppos)
{
struct hstate *h = &default_hstate;
unsigned long tmp;
int ret;
tmp = h->nr_overcommit_huge_pages;
if (write && h->order >= MAX_ORDER)
return -EINVAL;
table->data = &tmp;
table->maxlen = sizeof(unsigned long);
ret = proc_doulongvec_minmax(table, write, buffer, length, ppos);
if (ret)
goto out;
if (write) {
spin_lock(&hugetlb_lock);
h->nr_overcommit_huge_pages = tmp;
spin_unlock(&hugetlb_lock);
}
out:
return ret;
}
void hugetlb_report_meminfo(struct seq_file *m)
{
struct hstate *h = &default_hstate;
seq_printf(m,
"HugePages_Total: %5lu\n"
"HugePages_Free: %5lu\n"
"HugePages_Rsvd: %5lu\n"
"HugePages_Surp: %5lu\n"
"Hugepagesize: %8lu kB\n",
h->nr_huge_pages,
h->free_huge_pages,
h->resv_huge_pages,
h->surplus_huge_pages,
1UL << (huge_page_order(h) + PAGE_SHIFT - 10));
}
int hugetlb_report_node_meminfo(int nid, char *buf)
{
struct hstate *h = &default_hstate;
return sprintf(buf,
"Node %d HugePages_Total: %5u\n"
"Node %d HugePages_Free: %5u\n"
"Node %d HugePages_Surp: %5u\n",
nid, h->nr_huge_pages_node[nid],
nid, h->free_huge_pages_node[nid],
nid, h->surplus_huge_pages_node[nid]);
}
void hugetlb_show_meminfo(void)
{
struct hstate *h;
int nid;
for_each_node_state(nid, N_MEMORY)
for_each_hstate(h)
pr_info("Node %d hugepages_total=%u hugepages_free=%u hugepages_surp=%u hugepages_size=%lukB\n",
nid,
h->nr_huge_pages_node[nid],
h->free_huge_pages_node[nid],
h->surplus_huge_pages_node[nid],
1UL << (huge_page_order(h) + PAGE_SHIFT - 10));
}
unsigned long hugetlb_total_pages(void)
{
struct hstate *h;
unsigned long nr_total_pages = 0;
for_each_hstate(h)
nr_total_pages += h->nr_huge_pages * pages_per_huge_page(h);
return nr_total_pages;
}
static int hugetlb_acct_memory(struct hstate *h, long delta)
{
int ret = -ENOMEM;
spin_lock(&hugetlb_lock);
if (delta > 0) {
if (gather_surplus_pages(h, delta) < 0)
goto out;
if (delta > cpuset_mems_nr(h->free_huge_pages_node)) {
return_unused_surplus_pages(h, delta);
goto out;
}
}
ret = 0;
if (delta < 0)
return_unused_surplus_pages(h, (unsigned long) -delta);
out:
spin_unlock(&hugetlb_lock);
return ret;
}
static void hugetlb_vm_op_open(struct vm_area_struct *vma)
{
struct resv_map *reservations = vma_resv_map(vma);
if (reservations)
kref_get(&reservations->refs);
}
static void resv_map_put(struct vm_area_struct *vma)
{
struct resv_map *reservations = vma_resv_map(vma);
if (!reservations)
return;
kref_put(&reservations->refs, resv_map_release);
}
static void hugetlb_vm_op_close(struct vm_area_struct *vma)
{
struct hstate *h = hstate_vma(vma);
struct resv_map *reservations = vma_resv_map(vma);
struct hugepage_subpool *spool = subpool_vma(vma);
unsigned long reserve;
unsigned long start;
unsigned long end;
if (reservations) {
start = vma_hugecache_offset(h, vma, vma->vm_start);
end = vma_hugecache_offset(h, vma, vma->vm_end);
reserve = (end - start) -
region_count(&reservations->regions, start, end);
resv_map_put(vma);
if (reserve) {
hugetlb_acct_memory(h, -reserve);
hugepage_subpool_put_pages(spool, reserve);
}
}
}
static int hugetlb_vm_op_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
BUG();
return 0;
}
static pte_t make_huge_pte(struct vm_area_struct *vma, struct page *page,
int writable)
{
pte_t entry;
if (writable) {
entry = huge_pte_mkwrite(huge_pte_mkdirty(mk_huge_pte(page,
vma->vm_page_prot)));
} else {
entry = huge_pte_wrprotect(mk_huge_pte(page,
vma->vm_page_prot));
}
entry = pte_mkyoung(entry);
entry = pte_mkhuge(entry);
entry = arch_make_huge_pte(entry, vma, page, writable);
return entry;
}
static void set_huge_ptep_writable(struct vm_area_struct *vma,
unsigned long address, pte_t *ptep)
{
pte_t entry;
entry = huge_pte_mkwrite(huge_pte_mkdirty(huge_ptep_get(ptep)));
if (huge_ptep_set_access_flags(vma, address, ptep, entry, 1))
update_mmu_cache(vma, address, ptep);
}
int copy_hugetlb_page_range(struct mm_struct *dst, struct mm_struct *src,
struct vm_area_struct *vma)
{
pte_t *src_pte, *dst_pte, entry;
struct page *ptepage;
unsigned long addr;
int cow;
struct hstate *h = hstate_vma(vma);
unsigned long sz = huge_page_size(h);
cow = (vma->vm_flags & (VM_SHARED | VM_MAYWRITE)) == VM_MAYWRITE;
for (addr = vma->vm_start; addr < vma->vm_end; addr += sz) {
src_pte = huge_pte_offset(src, addr);
if (!src_pte)
continue;
dst_pte = huge_pte_alloc(dst, addr, sz);
if (!dst_pte)
goto nomem;
if (dst_pte == src_pte)
continue;
spin_lock(&dst->page_table_lock);
spin_lock_nested(&src->page_table_lock, SINGLE_DEPTH_NESTING);
if (!huge_pte_none(huge_ptep_get(src_pte))) {
if (cow)
huge_ptep_set_wrprotect(src, addr, src_pte);
entry = huge_ptep_get(src_pte);
ptepage = pte_page(entry);
get_page(ptepage);
page_dup_rmap(ptepage);
set_huge_pte_at(dst, addr, dst_pte, entry);
}
spin_unlock(&src->page_table_lock);
spin_unlock(&dst->page_table_lock);
}
return 0;
nomem:
return -ENOMEM;
}
static int is_hugetlb_entry_migration(pte_t pte)
{
swp_entry_t swp;
if (huge_pte_none(pte) || pte_present(pte))
return 0;
swp = pte_to_swp_entry(pte);
if (non_swap_entry(swp) && is_migration_entry(swp))
return 1;
else
return 0;
}
static int is_hugetlb_entry_hwpoisoned(pte_t pte)
{
swp_entry_t swp;
if (huge_pte_none(pte) || pte_present(pte))
return 0;
swp = pte_to_swp_entry(pte);
if (non_swap_entry(swp) && is_hwpoison_entry(swp))
return 1;
else
return 0;
}
void __unmap_hugepage_range(struct mmu_gather *tlb, struct vm_area_struct *vma,
unsigned long start, unsigned long end,
struct page *ref_page)
{
int force_flush = 0;
struct mm_struct *mm = vma->vm_mm;
unsigned long address;
pte_t *ptep;
pte_t pte;
struct page *page;
struct hstate *h = hstate_vma(vma);
unsigned long sz = huge_page_size(h);
const unsigned long mmun_start = start;
const unsigned long mmun_end = end;
WARN_ON(!is_vm_hugetlb_page(vma));
BUG_ON(start & ~huge_page_mask(h));
BUG_ON(end & ~huge_page_mask(h));
tlb_start_vma(tlb, vma);
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
again:
spin_lock(&mm->page_table_lock);
for (address = start; address < end; address += sz) {
ptep = huge_pte_offset(mm, address);
if (!ptep)
continue;
if (huge_pmd_unshare(mm, &address, ptep))
continue;
pte = huge_ptep_get(ptep);
if (huge_pte_none(pte))
continue;
if (unlikely(is_hugetlb_entry_hwpoisoned(pte))) {
huge_pte_clear(mm, address, ptep);
continue;
}
page = pte_page(pte);
if (ref_page) {
if (page != ref_page)
continue;
set_vma_resv_flags(vma, HPAGE_RESV_UNMAPPED);
}
pte = huge_ptep_get_and_clear(mm, address, ptep);
tlb_remove_tlb_entry(tlb, ptep, address);
if (huge_pte_dirty(pte))
set_page_dirty(page);
page_remove_rmap(page);
force_flush = !__tlb_remove_page(tlb, page);
if (force_flush)
break;
if (ref_page)
break;
}
spin_unlock(&mm->page_table_lock);
if (force_flush) {
force_flush = 0;
tlb_flush_mmu(tlb);
if (address < end && !ref_page)
goto again;
}
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
tlb_end_vma(tlb, vma);
}
void __unmap_hugepage_range_final(struct mmu_gather *tlb,
struct vm_area_struct *vma, unsigned long start,
unsigned long end, struct page *ref_page)
{
__unmap_hugepage_range(tlb, vma, start, end, ref_page);
vma->vm_flags &= ~VM_MAYSHARE;
}
void unmap_hugepage_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end, struct page *ref_page)
{
struct mm_struct *mm;
struct mmu_gather tlb;
mm = vma->vm_mm;
tlb_gather_mmu(&tlb, mm, start, end);
__unmap_hugepage_range(&tlb, vma, start, end, ref_page);
tlb_finish_mmu(&tlb, start, end);
}
static int unmap_ref_private(struct mm_struct *mm, struct vm_area_struct *vma,
struct page *page, unsigned long address)
{
struct hstate *h = hstate_vma(vma);
struct vm_area_struct *iter_vma;
struct address_space *mapping;
pgoff_t pgoff;
address = address & huge_page_mask(h);
pgoff = ((address - vma->vm_start) >> PAGE_SHIFT) +
vma->vm_pgoff;
mapping = file_inode(vma->vm_file)->i_mapping;
mutex_lock(&mapping->i_mmap_mutex);
vma_interval_tree_foreach(iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if (iter_vma == vma)
continue;
if (!is_vma_resv_set(iter_vma, HPAGE_RESV_OWNER))
unmap_hugepage_range(iter_vma, address,
address + huge_page_size(h), page);
}
mutex_unlock(&mapping->i_mmap_mutex);
return 1;
}
static int hugetlb_cow(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pte_t *ptep, pte_t pte,
struct page *pagecache_page)
{
struct hstate *h = hstate_vma(vma);
struct page *old_page, *new_page;
int avoidcopy;
int outside_reserve = 0;
unsigned long mmun_start;
unsigned long mmun_end;
old_page = pte_page(pte);
retry_avoidcopy:
avoidcopy = (page_mapcount(old_page) == 1);
if (avoidcopy) {
if (PageAnon(old_page))
page_move_anon_rmap(old_page, vma, address);
set_huge_ptep_writable(vma, address, ptep);
return 0;
}
if (!(vma->vm_flags & VM_MAYSHARE) &&
is_vma_resv_set(vma, HPAGE_RESV_OWNER) &&
old_page != pagecache_page)
outside_reserve = 1;
page_cache_get(old_page);
spin_unlock(&mm->page_table_lock);
new_page = alloc_huge_page(vma, address, outside_reserve);
if (IS_ERR(new_page)) {
long err = PTR_ERR(new_page);
page_cache_release(old_page);
if (outside_reserve) {
BUG_ON(huge_pte_none(pte));
if (unmap_ref_private(mm, vma, old_page, address)) {
BUG_ON(huge_pte_none(pte));
spin_lock(&mm->page_table_lock);
ptep = huge_pte_offset(mm, address & huge_page_mask(h));
if (likely(pte_same(huge_ptep_get(ptep), pte)))
goto retry_avoidcopy;
return 0;
}
WARN_ON_ONCE(1);
}
spin_lock(&mm->page_table_lock);
if (err == -ENOMEM)
return VM_FAULT_OOM;
else
return VM_FAULT_SIGBUS;
}
if (unlikely(anon_vma_prepare(vma))) {
page_cache_release(new_page);
page_cache_release(old_page);
spin_lock(&mm->page_table_lock);
return VM_FAULT_OOM;
}
copy_user_huge_page(new_page, old_page, address, vma,
pages_per_huge_page(h));
__SetPageUptodate(new_page);
mmun_start = address & huge_page_mask(h);
mmun_end = mmun_start + huge_page_size(h);
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
spin_lock(&mm->page_table_lock);
ptep = huge_pte_offset(mm, address & huge_page_mask(h));
if (likely(pte_same(huge_ptep_get(ptep), pte))) {
huge_ptep_clear_flush(vma, address, ptep);
set_huge_pte_at(mm, address, ptep,
make_huge_pte(vma, new_page, 1));
page_remove_rmap(old_page);
hugepage_add_new_anon_rmap(new_page, vma, address);
new_page = old_page;
}
spin_unlock(&mm->page_table_lock);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
spin_lock(&mm->page_table_lock);
page_cache_release(new_page);
page_cache_release(old_page);
return 0;
}
static struct page *hugetlbfs_pagecache_page(struct hstate *h,
struct vm_area_struct *vma, unsigned long address)
{
struct address_space *mapping;
pgoff_t idx;
mapping = vma->vm_file->f_mapping;
idx = vma_hugecache_offset(h, vma, address);
return find_lock_page(mapping, idx);
}
static bool hugetlbfs_pagecache_present(struct hstate *h,
struct vm_area_struct *vma, unsigned long address)
{
struct address_space *mapping;
pgoff_t idx;
struct page *page;
mapping = vma->vm_file->f_mapping;
idx = vma_hugecache_offset(h, vma, address);
page = find_get_page(mapping, idx);
if (page)
put_page(page);
return page != NULL;
}
static int hugetlb_no_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pte_t *ptep, unsigned int flags)
{
struct hstate *h = hstate_vma(vma);
int ret = VM_FAULT_SIGBUS;
int anon_rmap = 0;
pgoff_t idx;
unsigned long size;
struct page *page;
struct address_space *mapping;
pte_t new_pte;
if (is_vma_resv_set(vma, HPAGE_RESV_UNMAPPED)) {
pr_warning("PID %d killed due to inadequate hugepage pool\n",
current->pid);
return ret;
}
mapping = vma->vm_file->f_mapping;
idx = vma_hugecache_offset(h, vma, address);
retry:
page = find_lock_page(mapping, idx);
if (!page) {
size = i_size_read(mapping->host) >> huge_page_shift(h);
if (idx >= size)
goto out;
page = alloc_huge_page(vma, address, 0);
if (IS_ERR(page)) {
ret = PTR_ERR(page);
if (ret == -ENOMEM)
ret = VM_FAULT_OOM;
else
ret = VM_FAULT_SIGBUS;
goto out;
}
clear_huge_page(page, address, pages_per_huge_page(h));
__SetPageUptodate(page);
if (vma->vm_flags & VM_MAYSHARE) {
int err;
struct inode *inode = mapping->host;
err = add_to_page_cache(page, mapping, idx, GFP_KERNEL);
if (err) {
put_page(page);
if (err == -EEXIST)
goto retry;
goto out;
}
spin_lock(&inode->i_lock);
inode->i_blocks += blocks_per_huge_page(h);
spin_unlock(&inode->i_lock);
} else {
lock_page(page);
if (unlikely(anon_vma_prepare(vma))) {
ret = VM_FAULT_OOM;
goto backout_unlocked;
}
anon_rmap = 1;
}
} else {
if (unlikely(PageHWPoison(page))) {
ret = VM_FAULT_HWPOISON |
VM_FAULT_SET_HINDEX(hstate_index(h));
goto backout_unlocked;
}
}
if ((flags & FAULT_FLAG_WRITE) && !(vma->vm_flags & VM_SHARED))
if (vma_needs_reservation(h, vma, address) < 0) {
ret = VM_FAULT_OOM;
goto backout_unlocked;
}
spin_lock(&mm->page_table_lock);
size = i_size_read(mapping->host) >> huge_page_shift(h);
if (idx >= size)
goto backout;
ret = 0;
if (!huge_pte_none(huge_ptep_get(ptep)))
goto backout;
if (anon_rmap)
hugepage_add_new_anon_rmap(page, vma, address);
else
page_dup_rmap(page);
new_pte = make_huge_pte(vma, page, ((vma->vm_flags & VM_WRITE)
&& (vma->vm_flags & VM_SHARED)));
set_huge_pte_at(mm, address, ptep, new_pte);
if ((flags & FAULT_FLAG_WRITE) && !(vma->vm_flags & VM_SHARED)) {
ret = hugetlb_cow(mm, vma, address, ptep, new_pte, page);
}
spin_unlock(&mm->page_table_lock);
unlock_page(page);
out:
return ret;
backout:
spin_unlock(&mm->page_table_lock);
backout_unlocked:
unlock_page(page);
put_page(page);
goto out;
}
int hugetlb_fault(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, unsigned int flags)
{
pte_t *ptep;
pte_t entry;
int ret;
struct page *page = NULL;
struct page *pagecache_page = NULL;
static DEFINE_MUTEX(hugetlb_instantiation_mutex);
struct hstate *h = hstate_vma(vma);
address &= huge_page_mask(h);
ptep = huge_pte_offset(mm, address);
if (ptep) {
entry = huge_ptep_get(ptep);
if (unlikely(is_hugetlb_entry_migration(entry))) {
migration_entry_wait_huge(mm, ptep);
return 0;
} else if (unlikely(is_hugetlb_entry_hwpoisoned(entry)))
return VM_FAULT_HWPOISON_LARGE |
VM_FAULT_SET_HINDEX(hstate_index(h));
}
ptep = huge_pte_alloc(mm, address, huge_page_size(h));
if (!ptep)
return VM_FAULT_OOM;
mutex_lock(&hugetlb_instantiation_mutex);
entry = huge_ptep_get(ptep);
if (huge_pte_none(entry)) {
ret = hugetlb_no_page(mm, vma, address, ptep, flags);
goto out_mutex;
}
ret = 0;
if ((flags & FAULT_FLAG_WRITE) && !huge_pte_write(entry)) {
if (vma_needs_reservation(h, vma, address) < 0) {
ret = VM_FAULT_OOM;
goto out_mutex;
}
if (!(vma->vm_flags & VM_MAYSHARE))
pagecache_page = hugetlbfs_pagecache_page(h,
vma, address);
}
page = pte_page(entry);
get_page(page);
if (page != pagecache_page)
lock_page(page);
spin_lock(&mm->page_table_lock);
if (unlikely(!pte_same(entry, huge_ptep_get(ptep))))
goto out_page_table_lock;
if (flags & FAULT_FLAG_WRITE) {
if (!huge_pte_write(entry)) {
ret = hugetlb_cow(mm, vma, address, ptep, entry,
pagecache_page);
goto out_page_table_lock;
}
entry = huge_pte_mkdirty(entry);
}
entry = pte_mkyoung(entry);
if (huge_ptep_set_access_flags(vma, address, ptep, entry,
flags & FAULT_FLAG_WRITE))
update_mmu_cache(vma, address, ptep);
out_page_table_lock:
spin_unlock(&mm->page_table_lock);
if (pagecache_page) {
unlock_page(pagecache_page);
put_page(pagecache_page);
}
if (page != pagecache_page)
unlock_page(page);
put_page(page);
out_mutex:
mutex_unlock(&hugetlb_instantiation_mutex);
return ret;
}
long follow_hugetlb_page(struct mm_struct *mm, struct vm_area_struct *vma,
struct page **pages, struct vm_area_struct **vmas,
unsigned long *position, unsigned long *nr_pages,
long i, unsigned int flags)
{
unsigned long pfn_offset;
unsigned long vaddr = *position;
unsigned long remainder = *nr_pages;
struct hstate *h = hstate_vma(vma);
spin_lock(&mm->page_table_lock);
while (vaddr < vma->vm_end && remainder) {
pte_t *pte;
int absent;
struct page *page;
pte = huge_pte_offset(mm, vaddr & huge_page_mask(h));
absent = !pte || huge_pte_none(huge_ptep_get(pte));
if (absent && (flags & FOLL_DUMP) &&
!hugetlbfs_pagecache_present(h, vma, vaddr)) {
remainder = 0;
break;
}
if (absent || is_swap_pte(huge_ptep_get(pte)) ||
((flags & FOLL_WRITE) &&
!huge_pte_write(huge_ptep_get(pte)))) {
int ret;
spin_unlock(&mm->page_table_lock);
ret = hugetlb_fault(mm, vma, vaddr,
(flags & FOLL_WRITE) ? FAULT_FLAG_WRITE : 0);
spin_lock(&mm->page_table_lock);
if (!(ret & VM_FAULT_ERROR))
continue;
remainder = 0;
break;
}
pfn_offset = (vaddr & ~huge_page_mask(h)) >> PAGE_SHIFT;
page = pte_page(huge_ptep_get(pte));
same_page:
if (pages) {
pages[i] = mem_map_offset(page, pfn_offset);
get_page(pages[i]);
}
if (vmas)
vmas[i] = vma;
vaddr += PAGE_SIZE;
++pfn_offset;
--remainder;
++i;
if (vaddr < vma->vm_end && remainder &&
pfn_offset < pages_per_huge_page(h)) {
goto same_page;
}
}
spin_unlock(&mm->page_table_lock);
*nr_pages = remainder;
*position = vaddr;
return i ? i : -EFAULT;
}
unsigned long hugetlb_change_protection(struct vm_area_struct *vma,
unsigned long address, unsigned long end, pgprot_t newprot)
{
struct mm_struct *mm = vma->vm_mm;
unsigned long start = address;
pte_t *ptep;
pte_t pte;
struct hstate *h = hstate_vma(vma);
unsigned long pages = 0;
BUG_ON(address >= end);
flush_cache_range(vma, address, end);
mutex_lock(&vma->vm_file->f_mapping->i_mmap_mutex);
spin_lock(&mm->page_table_lock);
for (; address < end; address += huge_page_size(h)) {
ptep = huge_pte_offset(mm, address);
if (!ptep)
continue;
if (huge_pmd_unshare(mm, &address, ptep)) {
pages++;
continue;
}
if (!huge_pte_none(huge_ptep_get(ptep))) {
pte = huge_ptep_get_and_clear(mm, address, ptep);
pte = pte_mkhuge(huge_pte_modify(pte, newprot));
pte = arch_make_huge_pte(pte, vma, NULL, 0);
set_huge_pte_at(mm, address, ptep, pte);
pages++;
}
}
spin_unlock(&mm->page_table_lock);
flush_tlb_range(vma, start, end);
mutex_unlock(&vma->vm_file->f_mapping->i_mmap_mutex);
return pages << h->order;
}
int hugetlb_reserve_pages(struct inode *inode,
long from, long to,
struct vm_area_struct *vma,
vm_flags_t vm_flags)
{
long ret, chg;
struct hstate *h = hstate_inode(inode);
struct hugepage_subpool *spool = subpool_inode(inode);
if (vm_flags & VM_NORESERVE)
return 0;
if (!vma || vma->vm_flags & VM_MAYSHARE)
chg = region_chg(&inode->i_mapping->private_list, from, to);
else {
struct resv_map *resv_map = resv_map_alloc();
if (!resv_map)
return -ENOMEM;
chg = to - from;
set_vma_resv_map(vma, resv_map);
set_vma_resv_flags(vma, HPAGE_RESV_OWNER);
}
if (chg < 0) {
ret = chg;
goto out_err;
}
if (hugepage_subpool_get_pages(spool, chg)) {
ret = -ENOSPC;
goto out_err;
}
ret = hugetlb_acct_memory(h, chg);
if (ret < 0) {
hugepage_subpool_put_pages(spool, chg);
goto out_err;
}
if (!vma || vma->vm_flags & VM_MAYSHARE)
region_add(&inode->i_mapping->private_list, from, to);
return 0;
out_err:
if (vma)
resv_map_put(vma);
return ret;
}
void hugetlb_unreserve_pages(struct inode *inode, long offset, long freed)
{
struct hstate *h = hstate_inode(inode);
long chg = region_truncate(&inode->i_mapping->private_list, offset);
struct hugepage_subpool *spool = subpool_inode(inode);
spin_lock(&inode->i_lock);
inode->i_blocks -= (blocks_per_huge_page(h) * freed);
spin_unlock(&inode->i_lock);
hugepage_subpool_put_pages(spool, (chg - freed));
hugetlb_acct_memory(h, -(chg - freed));
}
static unsigned long page_table_shareable(struct vm_area_struct *svma,
struct vm_area_struct *vma,
unsigned long addr, pgoff_t idx)
{
unsigned long saddr = ((idx - svma->vm_pgoff) << PAGE_SHIFT) +
svma->vm_start;
unsigned long sbase = saddr & PUD_MASK;
unsigned long s_end = sbase + PUD_SIZE;
unsigned long vm_flags = vma->vm_flags & ~VM_LOCKED;
unsigned long svm_flags = svma->vm_flags & ~VM_LOCKED;
if (pmd_index(addr) != pmd_index(saddr) ||
vm_flags != svm_flags ||
sbase < svma->vm_start || svma->vm_end < s_end)
return 0;
return saddr;
}
static int vma_shareable(struct vm_area_struct *vma, unsigned long addr)
{
unsigned long base = addr & PUD_MASK;
unsigned long end = base + PUD_SIZE;
if (vma->vm_flags & VM_MAYSHARE &&
vma->vm_start <= base && end <= vma->vm_end)
return 1;
return 0;
}
pte_t *huge_pmd_share(struct mm_struct *mm, unsigned long addr, pud_t *pud)
{
struct vm_area_struct *vma = find_vma(mm, addr);
struct address_space *mapping = vma->vm_file->f_mapping;
pgoff_t idx = ((addr - vma->vm_start) >> PAGE_SHIFT) +
vma->vm_pgoff;
struct vm_area_struct *svma;
unsigned long saddr;
pte_t *spte = NULL;
pte_t *pte;
if (!vma_shareable(vma, addr))
return (pte_t *)pmd_alloc(mm, pud, addr);
mutex_lock(&mapping->i_mmap_mutex);
vma_interval_tree_foreach(svma, &mapping->i_mmap, idx, idx) {
if (svma == vma)
continue;
saddr = page_table_shareable(svma, vma, addr, idx);
if (saddr) {
spte = huge_pte_offset(svma->vm_mm, saddr);
if (spte) {
get_page(virt_to_page(spte));
break;
}
}
}
if (!spte)
goto out;
spin_lock(&mm->page_table_lock);
if (pud_none(*pud))
pud_populate(mm, pud,
(pmd_t *)((unsigned long)spte & PAGE_MASK));
else
put_page(virt_to_page(spte));
spin_unlock(&mm->page_table_lock);
out:
pte = (pte_t *)pmd_alloc(mm, pud, addr);
mutex_unlock(&mapping->i_mmap_mutex);
return pte;
}
int huge_pmd_unshare(struct mm_struct *mm, unsigned long *addr, pte_t *ptep)
{
pgd_t *pgd = pgd_offset(mm, *addr);
pud_t *pud = pud_offset(pgd, *addr);
BUG_ON(page_count(virt_to_page(ptep)) == 0);
if (page_count(virt_to_page(ptep)) == 1)
return 0;
pud_clear(pud);
put_page(virt_to_page(ptep));
*addr = ALIGN(*addr, HPAGE_SIZE * PTRS_PER_PTE) - HPAGE_SIZE;
return 1;
}
pte_t *huge_pmd_share(struct mm_struct *mm, unsigned long addr, pud_t *pud)
{
return NULL;
}
pte_t *huge_pte_alloc(struct mm_struct *mm,
unsigned long addr, unsigned long sz)
{
pgd_t *pgd;
pud_t *pud;
pte_t *pte = NULL;
pgd = pgd_offset(mm, addr);
pud = pud_alloc(mm, pgd, addr);
if (pud) {
if (sz == PUD_SIZE) {
pte = (pte_t *)pud;
} else {
BUG_ON(sz != PMD_SIZE);
if (want_pmd_share() && pud_none(*pud))
pte = huge_pmd_share(mm, addr, pud);
else
pte = (pte_t *)pmd_alloc(mm, pud, addr);
}
}
BUG_ON(pte && !pte_none(*pte) && !pte_huge(*pte));
return pte;
}
pte_t *huge_pte_offset(struct mm_struct *mm, unsigned long addr)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd = NULL;
pgd = pgd_offset(mm, addr);
if (pgd_present(*pgd)) {
pud = pud_offset(pgd, addr);
if (pud_present(*pud)) {
if (pud_huge(*pud))
return (pte_t *)pud;
pmd = pmd_offset(pud, addr);
}
}
return (pte_t *) pmd;
}
struct page *
follow_huge_pmd(struct mm_struct *mm, unsigned long address,
pmd_t *pmd, int write)
{
struct page *page;
page = pte_page(*(pte_t *)pmd);
if (page)
page += ((address & ~PMD_MASK) >> PAGE_SHIFT);
return page;
}
struct page *
follow_huge_pud(struct mm_struct *mm, unsigned long address,
pud_t *pud, int write)
{
struct page *page;
page = pte_page(*(pte_t *)pud);
if (page)
page += ((address & ~PUD_MASK) >> PAGE_SHIFT);
return page;
}
struct page *
follow_huge_pud(struct mm_struct *mm, unsigned long address,
pud_t *pud, int write)
{
BUG();
return NULL;
}
static int is_hugepage_on_freelist(struct page *hpage)
{
struct page *page;
struct page *tmp;
struct hstate *h = page_hstate(hpage);
int nid = page_to_nid(hpage);
list_for_each_entry_safe(page, tmp, &h->hugepage_freelists[nid], lru)
if (page == hpage)
return 1;
return 0;
}
int dequeue_hwpoisoned_huge_page(struct page *hpage)
{
struct hstate *h = page_hstate(hpage);
int nid = page_to_nid(hpage);
int ret = -EBUSY;
spin_lock(&hugetlb_lock);
if (is_hugepage_on_freelist(hpage)) {
list_del_init(&hpage->lru);
set_page_refcounted(hpage);
h->free_huge_pages--;
h->free_huge_pages_node[nid]--;
ret = 0;
}
spin_unlock(&hugetlb_lock);
return ret;
}
