static inline void unlock_or_release_subpool(struct hugepage_subpool *spool)
{
bool free = (spool->count == 0) && (spool->used_hpages == 0);
spin_unlock(&spool->lock);
if (free) {
if (spool->min_hpages != -1)
hugetlb_acct_memory(spool->hstate,
-spool->min_hpages);
kfree(spool);
}
}
struct hugepage_subpool *hugepage_new_subpool(struct hstate *h, long max_hpages,
long min_hpages)
{
struct hugepage_subpool *spool;
spool = kzalloc(sizeof(*spool), GFP_KERNEL);
if (!spool)
return NULL;
spin_lock_init(&spool->lock);
spool->count = 1;
spool->max_hpages = max_hpages;
spool->hstate = h;
spool->min_hpages = min_hpages;
if (min_hpages != -1 && hugetlb_acct_memory(h, min_hpages)) {
kfree(spool);
return NULL;
}
spool->rsv_hpages = min_hpages;
return spool;
}
void hugepage_put_subpool(struct hugepage_subpool *spool)
{
spin_lock(&spool->lock);
BUG_ON(!spool->count);
spool->count--;
unlock_or_release_subpool(spool);
}
static long hugepage_subpool_get_pages(struct hugepage_subpool *spool,
long delta)
{
long ret = delta;
if (!spool)
return ret;
spin_lock(&spool->lock);
if (spool->max_hpages != -1) {
if ((spool->used_hpages + delta) <= spool->max_hpages)
spool->used_hpages += delta;
else {
ret = -ENOMEM;
goto unlock_ret;
}
}
if (spool->min_hpages != -1 && spool->rsv_hpages) {
if (delta > spool->rsv_hpages) {
ret = delta - spool->rsv_hpages;
spool->rsv_hpages = 0;
} else {
ret = 0;
spool->rsv_hpages -= delta;
}
}
unlock_ret:
spin_unlock(&spool->lock);
return ret;
}
static long hugepage_subpool_put_pages(struct hugepage_subpool *spool,
long delta)
{
long ret = delta;
if (!spool)
return delta;
spin_lock(&spool->lock);
if (spool->max_hpages != -1)
spool->used_hpages -= delta;
if (spool->min_hpages != -1 && spool->used_hpages < spool->min_hpages) {
if (spool->rsv_hpages + delta <= spool->min_hpages)
ret = 0;
else
ret = spool->rsv_hpages + delta - spool->min_hpages;
spool->rsv_hpages += delta;
if (spool->rsv_hpages > spool->min_hpages)
spool->rsv_hpages = spool->min_hpages;
}
unlock_or_release_subpool(spool);
return ret;
}
static inline struct hugepage_subpool *subpool_inode(struct inode *inode)
{
return HUGETLBFS_SB(inode->i_sb)->spool;
}
static inline struct hugepage_subpool *subpool_vma(struct vm_area_struct *vma)
{
return subpool_inode(file_inode(vma->vm_file));
}
static long region_add(struct resv_map *resv, long f, long t)
{
struct list_head *head = &resv->regions;
struct file_region *rg, *nrg, *trg;
long add = 0;
spin_lock(&resv->lock);
list_for_each_entry(rg, head, link)
if (f <= rg->to)
break;
if (&rg->link == head || t < rg->from) {
VM_BUG_ON(resv->region_cache_count <= 0);
resv->region_cache_count--;
nrg = list_first_entry(&resv->region_cache, struct file_region,
link);
list_del(&nrg->link);
nrg->from = f;
nrg->to = t;
list_add(&nrg->link, rg->link.prev);
add += t - f;
goto out_locked;
}
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
add -= (rg->to - rg->from);
list_del(&rg->link);
kfree(rg);
}
}
add += (nrg->from - f);
nrg->from = f;
add += t - nrg->to;
nrg->to = t;
out_locked:
resv->adds_in_progress--;
spin_unlock(&resv->lock);
VM_BUG_ON(add < 0);
return add;
}
static long region_chg(struct resv_map *resv, long f, long t)
{
struct list_head *head = &resv->regions;
struct file_region *rg, *nrg = NULL;
long chg = 0;
retry:
spin_lock(&resv->lock);
retry_locked:
resv->adds_in_progress++;
if (resv->adds_in_progress > resv->region_cache_count) {
struct file_region *trg;
VM_BUG_ON(resv->adds_in_progress - resv->region_cache_count > 1);
resv->adds_in_progress--;
spin_unlock(&resv->lock);
trg = kmalloc(sizeof(*trg), GFP_KERNEL);
if (!trg) {
kfree(nrg);
return -ENOMEM;
}
spin_lock(&resv->lock);
list_add(&trg->link, &resv->region_cache);
resv->region_cache_count++;
goto retry_locked;
}
list_for_each_entry(rg, head, link)
if (f <= rg->to)
break;
if (&rg->link == head || t < rg->from) {
if (!nrg) {
resv->adds_in_progress--;
spin_unlock(&resv->lock);
nrg = kmalloc(sizeof(*nrg), GFP_KERNEL);
if (!nrg)
return -ENOMEM;
nrg->from = f;
nrg->to = f;
INIT_LIST_HEAD(&nrg->link);
goto retry;
}
list_add(&nrg->link, rg->link.prev);
chg = t - f;
goto out_nrg;
}
if (f > rg->from)
f = rg->from;
chg = t - f;
list_for_each_entry(rg, rg->link.prev, link) {
if (&rg->link == head)
break;
if (rg->from > t)
goto out;
if (rg->to > t) {
chg += rg->to - t;
t = rg->to;
}
chg -= rg->to - rg->from;
}
out:
spin_unlock(&resv->lock);
kfree(nrg);
return chg;
out_nrg:
spin_unlock(&resv->lock);
return chg;
}
static void region_abort(struct resv_map *resv, long f, long t)
{
spin_lock(&resv->lock);
VM_BUG_ON(!resv->region_cache_count);
resv->adds_in_progress--;
spin_unlock(&resv->lock);
}
static long region_del(struct resv_map *resv, long f, long t)
{
struct list_head *head = &resv->regions;
struct file_region *rg, *trg;
struct file_region *nrg = NULL;
long del = 0;
retry:
spin_lock(&resv->lock);
list_for_each_entry_safe(rg, trg, head, link) {
if (rg->to <= f && (rg->to != rg->from || rg->to != f))
continue;
if (rg->from >= t)
break;
if (f > rg->from && t < rg->to) {
if (!nrg &&
resv->region_cache_count > resv->adds_in_progress) {
nrg = list_first_entry(&resv->region_cache,
struct file_region,
link);
list_del(&nrg->link);
resv->region_cache_count--;
}
if (!nrg) {
spin_unlock(&resv->lock);
nrg = kmalloc(sizeof(*nrg), GFP_KERNEL);
if (!nrg)
return -ENOMEM;
goto retry;
}
del += t - f;
nrg->from = t;
nrg->to = rg->to;
INIT_LIST_HEAD(&nrg->link);
rg->to = f;
list_add(&nrg->link, &rg->link);
nrg = NULL;
break;
}
if (f <= rg->from && t >= rg->to) {
del += rg->to - rg->from;
list_del(&rg->link);
kfree(rg);
continue;
}
if (f <= rg->from) {
del += t - rg->from;
rg->from = t;
} else {
del += rg->to - f;
rg->to = f;
}
}
spin_unlock(&resv->lock);
kfree(nrg);
return del;
}
void hugetlb_fix_reserve_counts(struct inode *inode)
{
struct hugepage_subpool *spool = subpool_inode(inode);
long rsv_adjust;
rsv_adjust = hugepage_subpool_get_pages(spool, 1);
if (rsv_adjust) {
struct hstate *h = hstate_inode(inode);
hugetlb_acct_memory(h, 1);
}
}
static long region_count(struct resv_map *resv, long f, long t)
{
struct list_head *head = &resv->regions;
struct file_region *rg;
long chg = 0;
spin_lock(&resv->lock);
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
spin_unlock(&resv->lock);
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
struct resv_map *resv_map_alloc(void)
{
struct resv_map *resv_map = kmalloc(sizeof(*resv_map), GFP_KERNEL);
struct file_region *rg = kmalloc(sizeof(*rg), GFP_KERNEL);
if (!resv_map || !rg) {
kfree(resv_map);
kfree(rg);
return NULL;
}
kref_init(&resv_map->refs);
spin_lock_init(&resv_map->lock);
INIT_LIST_HEAD(&resv_map->regions);
resv_map->adds_in_progress = 0;
INIT_LIST_HEAD(&resv_map->region_cache);
list_add(&rg->link, &resv_map->region_cache);
resv_map->region_cache_count = 1;
return resv_map;
}
void resv_map_release(struct kref *ref)
{
struct resv_map *resv_map = container_of(ref, struct resv_map, refs);
struct list_head *head = &resv_map->region_cache;
struct file_region *rg, *trg;
region_del(resv_map, 0, LONG_MAX);
list_for_each_entry_safe(rg, trg, head, link) {
list_del(&rg->link);
kfree(rg);
}
VM_BUG_ON(resv_map->adds_in_progress);
kfree(resv_map);
}
static inline struct resv_map *inode_resv_map(struct inode *inode)
{
return inode->i_mapping->private_data;
}
static struct resv_map *vma_resv_map(struct vm_area_struct *vma)
{
VM_BUG_ON_VMA(!is_vm_hugetlb_page(vma), vma);
if (vma->vm_flags & VM_MAYSHARE) {
struct address_space *mapping = vma->vm_file->f_mapping;
struct inode *inode = mapping->host;
return inode_resv_map(inode);
} else {
return (struct resv_map *)(get_vma_private_data(vma) &
~HPAGE_RESV_MASK);
}
}
static void set_vma_resv_map(struct vm_area_struct *vma, struct resv_map *map)
{
VM_BUG_ON_VMA(!is_vm_hugetlb_page(vma), vma);
VM_BUG_ON_VMA(vma->vm_flags & VM_MAYSHARE, vma);
set_vma_private_data(vma, (get_vma_private_data(vma) &
HPAGE_RESV_MASK) | (unsigned long)map);
}
static void set_vma_resv_flags(struct vm_area_struct *vma, unsigned long flags)
{
VM_BUG_ON_VMA(!is_vm_hugetlb_page(vma), vma);
VM_BUG_ON_VMA(vma->vm_flags & VM_MAYSHARE, vma);
set_vma_private_data(vma, get_vma_private_data(vma) | flags);
}
static int is_vma_resv_set(struct vm_area_struct *vma, unsigned long flag)
{
VM_BUG_ON_VMA(!is_vm_hugetlb_page(vma), vma);
return (get_vma_private_data(vma) & flag) != 0;
}
void reset_vma_resv_huge_pages(struct vm_area_struct *vma)
{
VM_BUG_ON_VMA(!is_vm_hugetlb_page(vma), vma);
if (!(vma->vm_flags & VM_MAYSHARE))
vma->vm_private_data = (void *)0;
}
static bool vma_has_reserves(struct vm_area_struct *vma, long chg)
{
if (vma->vm_flags & VM_NORESERVE) {
if (vma->vm_flags & VM_MAYSHARE && chg == 0)
return true;
else
return false;
}
if (vma->vm_flags & VM_MAYSHARE) {
if (chg)
return false;
else
return true;
}
if (is_vma_resv_set(vma, HPAGE_RESV_OWNER)) {
if (chg)
return false;
else
return true;
}
return false;
}
static void enqueue_huge_page(struct hstate *h, struct page *page)
{
int nid = page_to_nid(page);
list_move(&page->lru, &h->hugepage_freelists[nid]);
h->free_huge_pages++;
h->free_huge_pages_node[nid]++;
}
static struct page *dequeue_huge_page_node_exact(struct hstate *h, int nid)
{
struct page *page;
list_for_each_entry(page, &h->hugepage_freelists[nid], lru)
if (!PageHWPoison(page))
break;
if (&h->hugepage_freelists[nid] == &page->lru)
return NULL;
list_move(&page->lru, &h->hugepage_activelist);
set_page_refcounted(page);
h->free_huge_pages--;
h->free_huge_pages_node[nid]--;
return page;
}
static struct page *dequeue_huge_page_nodemask(struct hstate *h, gfp_t gfp_mask, int nid,
nodemask_t *nmask)
{
unsigned int cpuset_mems_cookie;
struct zonelist *zonelist;
struct zone *zone;
struct zoneref *z;
int node = -1;
zonelist = node_zonelist(nid, gfp_mask);
retry_cpuset:
cpuset_mems_cookie = read_mems_allowed_begin();
for_each_zone_zonelist_nodemask(zone, z, zonelist, gfp_zone(gfp_mask), nmask) {
struct page *page;
if (!cpuset_zone_allowed(zone, gfp_mask))
continue;
if (zone_to_nid(zone) == node)
continue;
node = zone_to_nid(zone);
page = dequeue_huge_page_node_exact(h, node);
if (page)
return page;
}
if (unlikely(read_mems_allowed_retry(cpuset_mems_cookie)))
goto retry_cpuset;
return NULL;
}
static inline gfp_t htlb_alloc_mask(struct hstate *h)
{
if (hugepages_treat_as_movable || hugepage_migration_supported(h))
return GFP_HIGHUSER_MOVABLE;
else
return GFP_HIGHUSER;
}
static struct page *dequeue_huge_page_vma(struct hstate *h,
struct vm_area_struct *vma,
unsigned long address, int avoid_reserve,
long chg)
{
struct page *page;
struct mempolicy *mpol;
gfp_t gfp_mask;
nodemask_t *nodemask;
int nid;
if (!vma_has_reserves(vma, chg) &&
h->free_huge_pages - h->resv_huge_pages == 0)
goto err;
if (avoid_reserve && h->free_huge_pages - h->resv_huge_pages == 0)
goto err;
gfp_mask = htlb_alloc_mask(h);
nid = huge_node(vma, address, gfp_mask, &mpol, &nodemask);
page = dequeue_huge_page_nodemask(h, gfp_mask, nid, nodemask);
if (page && !avoid_reserve && vma_has_reserves(vma, chg)) {
SetPagePrivate(page);
h->resv_huge_pages--;
}
mpol_cond_put(mpol);
return page;
err:
return NULL;
}
static int next_node_allowed(int nid, nodemask_t *nodes_allowed)
{
nid = next_node_in(nid, *nodes_allowed);
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
static int hstate_next_node_to_free(struct hstate *h, nodemask_t *nodes_allowed)
{
int nid;
VM_BUG_ON(!nodes_allowed);
nid = get_valid_node_allowed(h->next_nid_to_free, nodes_allowed);
h->next_nid_to_free = next_node_allowed(nid, nodes_allowed);
return nid;
}
static void destroy_compound_gigantic_page(struct page *page,
unsigned int order)
{
int i;
int nr_pages = 1 << order;
struct page *p = page + 1;
atomic_set(compound_mapcount_ptr(page), 0);
for (i = 1; i < nr_pages; i++, p = mem_map_next(p, page, i)) {
clear_compound_head(p);
set_page_refcounted(p);
}
set_compound_order(page, 0);
__ClearPageHead(page);
}
static void free_gigantic_page(struct page *page, unsigned int order)
{
free_contig_range(page_to_pfn(page), 1 << order);
}
static int __alloc_gigantic_page(unsigned long start_pfn,
unsigned long nr_pages, gfp_t gfp_mask)
{
unsigned long end_pfn = start_pfn + nr_pages;
return alloc_contig_range(start_pfn, end_pfn, MIGRATE_MOVABLE,
gfp_mask);
}
static bool pfn_range_valid_gigantic(struct zone *z,
unsigned long start_pfn, unsigned long nr_pages)
{
unsigned long i, end_pfn = start_pfn + nr_pages;
struct page *page;
for (i = start_pfn; i < end_pfn; i++) {
if (!pfn_valid(i))
return false;
page = pfn_to_page(i);
if (page_zone(page) != z)
return false;
if (PageReserved(page))
return false;
if (page_count(page) > 0)
return false;
if (PageHuge(page))
return false;
}
return true;
}
static bool zone_spans_last_pfn(const struct zone *zone,
unsigned long start_pfn, unsigned long nr_pages)
{
unsigned long last_pfn = start_pfn + nr_pages - 1;
return zone_spans_pfn(zone, last_pfn);
}
static struct page *alloc_gigantic_page(int nid, struct hstate *h)
{
unsigned int order = huge_page_order(h);
unsigned long nr_pages = 1 << order;
unsigned long ret, pfn, flags;
struct zonelist *zonelist;
struct zone *zone;
struct zoneref *z;
gfp_t gfp_mask;
gfp_mask = htlb_alloc_mask(h) | __GFP_THISNODE;
zonelist = node_zonelist(nid, gfp_mask);
for_each_zone_zonelist_nodemask(zone, z, zonelist, gfp_zone(gfp_mask), NULL) {
spin_lock_irqsave(&zone->lock, flags);
pfn = ALIGN(zone->zone_start_pfn, nr_pages);
while (zone_spans_last_pfn(zone, pfn, nr_pages)) {
if (pfn_range_valid_gigantic(zone, pfn, nr_pages)) {
spin_unlock_irqrestore(&zone->lock, flags);
ret = __alloc_gigantic_page(pfn, nr_pages, gfp_mask);
if (!ret)
return pfn_to_page(pfn);
spin_lock_irqsave(&zone->lock, flags);
}
pfn += nr_pages;
}
spin_unlock_irqrestore(&zone->lock, flags);
}
return NULL;
}
static struct page *alloc_fresh_gigantic_page_node(struct hstate *h, int nid)
{
struct page *page;
page = alloc_gigantic_page(nid, h);
if (page) {
prep_compound_gigantic_page(page, huge_page_order(h));
prep_new_huge_page(h, page, nid);
}
return page;
}
static int alloc_fresh_gigantic_page(struct hstate *h,
nodemask_t *nodes_allowed)
{
struct page *page = NULL;
int nr_nodes, node;
for_each_node_mask_to_alloc(h, nr_nodes, node, nodes_allowed) {
page = alloc_fresh_gigantic_page_node(h, node);
if (page)
return 1;
}
return 0;
}
static inline bool gigantic_page_supported(void) { return false; }
static inline void free_gigantic_page(struct page *page, unsigned int order) { }
static inline void destroy_compound_gigantic_page(struct page *page,
unsigned int order) { }
static inline int alloc_fresh_gigantic_page(struct hstate *h,
nodemask_t *nodes_allowed) { return 0; }
static void update_and_free_page(struct hstate *h, struct page *page)
{
int i;
if (hstate_is_gigantic(h) && !gigantic_page_supported())
return;
h->nr_huge_pages--;
h->nr_huge_pages_node[page_to_nid(page)]--;
for (i = 0; i < pages_per_huge_page(h); i++) {
page[i].flags &= ~(1 << PG_locked | 1 << PG_error |
1 << PG_referenced | 1 << PG_dirty |
1 << PG_active | 1 << PG_private |
1 << PG_writeback);
}
VM_BUG_ON_PAGE(hugetlb_cgroup_from_page(page), page);
set_compound_page_dtor(page, NULL_COMPOUND_DTOR);
set_page_refcounted(page);
if (hstate_is_gigantic(h)) {
destroy_compound_gigantic_page(page, huge_page_order(h));
free_gigantic_page(page, huge_page_order(h));
} else {
__free_pages(page, huge_page_order(h));
}
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
bool page_huge_active(struct page *page)
{
VM_BUG_ON_PAGE(!PageHuge(page), page);
return PageHead(page) && PagePrivate(&page[1]);
}
static void set_page_huge_active(struct page *page)
{
VM_BUG_ON_PAGE(!PageHeadHuge(page), page);
SetPagePrivate(&page[1]);
}
static void clear_page_huge_active(struct page *page)
{
VM_BUG_ON_PAGE(!PageHeadHuge(page), page);
ClearPagePrivate(&page[1]);
}
void free_huge_page(struct page *page)
{
struct hstate *h = page_hstate(page);
int nid = page_to_nid(page);
struct hugepage_subpool *spool =
(struct hugepage_subpool *)page_private(page);
bool restore_reserve;
set_page_private(page, 0);
page->mapping = NULL;
VM_BUG_ON_PAGE(page_count(page), page);
VM_BUG_ON_PAGE(page_mapcount(page), page);
restore_reserve = PagePrivate(page);
ClearPagePrivate(page);
if (hugepage_subpool_put_pages(spool, 1) == 0)
restore_reserve = true;
spin_lock(&hugetlb_lock);
clear_page_huge_active(page);
hugetlb_cgroup_uncharge_page(hstate_index(h),
pages_per_huge_page(h), page);
if (restore_reserve)
h->resv_huge_pages++;
if (h->surplus_huge_pages_node[nid]) {
list_del(&page->lru);
update_and_free_page(h, page);
h->surplus_huge_pages--;
h->surplus_huge_pages_node[nid]--;
} else {
arch_clear_hugepage_flags(page);
enqueue_huge_page(h, page);
}
spin_unlock(&hugetlb_lock);
}
static void prep_new_huge_page(struct hstate *h, struct page *page, int nid)
{
INIT_LIST_HEAD(&page->lru);
set_compound_page_dtor(page, HUGETLB_PAGE_DTOR);
spin_lock(&hugetlb_lock);
set_hugetlb_cgroup(page, NULL);
h->nr_huge_pages++;
h->nr_huge_pages_node[nid]++;
spin_unlock(&hugetlb_lock);
put_page(page);
}
static void prep_compound_gigantic_page(struct page *page, unsigned int order)
{
int i;
int nr_pages = 1 << order;
struct page *p = page + 1;
set_compound_order(page, order);
__ClearPageReserved(page);
__SetPageHead(page);
for (i = 1; i < nr_pages; i++, p = mem_map_next(p, page, i)) {
__ClearPageReserved(p);
set_page_count(p, 0);
set_compound_head(p, page);
}
atomic_set(compound_mapcount_ptr(page), -1);
}
int PageHuge(struct page *page)
{
if (!PageCompound(page))
return 0;
page = compound_head(page);
return page[1].compound_dtor == HUGETLB_PAGE_DTOR;
}
int PageHeadHuge(struct page *page_head)
{
if (!PageHead(page_head))
return 0;
return get_compound_page_dtor(page_head) == free_huge_page;
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
page = __alloc_pages_node(nid,
htlb_alloc_mask(h)|__GFP_COMP|__GFP_THISNODE|
__GFP_RETRY_MAYFAIL|__GFP_NOWARN,
huge_page_order(h));
if (page) {
prep_new_huge_page(h, page, nid);
}
return page;
}
static int alloc_fresh_huge_page(struct hstate *h, nodemask_t *nodes_allowed)
{
struct page *page;
int nr_nodes, node;
int ret = 0;
for_each_node_mask_to_alloc(h, nr_nodes, node, nodes_allowed) {
page = alloc_fresh_huge_page_node(h, node);
if (page) {
ret = 1;
break;
}
}
if (ret)
count_vm_event(HTLB_BUDDY_PGALLOC);
else
count_vm_event(HTLB_BUDDY_PGALLOC_FAIL);
return ret;
}
static int free_pool_huge_page(struct hstate *h, nodemask_t *nodes_allowed,
bool acct_surplus)
{
int nr_nodes, node;
int ret = 0;
for_each_node_mask_to_free(h, nr_nodes, node, nodes_allowed) {
if ((!acct_surplus || h->surplus_huge_pages_node[node]) &&
!list_empty(&h->hugepage_freelists[node])) {
struct page *page =
list_entry(h->hugepage_freelists[node].next,
struct page, lru);
list_del(&page->lru);
h->free_huge_pages--;
h->free_huge_pages_node[node]--;
if (acct_surplus) {
h->surplus_huge_pages--;
h->surplus_huge_pages_node[node]--;
}
update_and_free_page(h, page);
ret = 1;
break;
}
}
return ret;
}
int dissolve_free_huge_page(struct page *page)
{
int rc = 0;
spin_lock(&hugetlb_lock);
if (PageHuge(page) && !page_count(page)) {
struct page *head = compound_head(page);
struct hstate *h = page_hstate(head);
int nid = page_to_nid(head);
if (h->free_huge_pages - h->resv_huge_pages == 0) {
rc = -EBUSY;
goto out;
}
if (PageHWPoison(head) && page != head) {
SetPageHWPoison(page);
ClearPageHWPoison(head);
}
list_del(&head->lru);
h->free_huge_pages--;
h->free_huge_pages_node[nid]--;
h->max_huge_pages--;
update_and_free_page(h, head);
}
out:
spin_unlock(&hugetlb_lock);
return rc;
}
int dissolve_free_huge_pages(unsigned long start_pfn, unsigned long end_pfn)
{
unsigned long pfn;
struct page *page;
int rc = 0;
if (!hugepages_supported())
return rc;
for (pfn = start_pfn; pfn < end_pfn; pfn += 1 << minimum_order) {
page = pfn_to_page(pfn);
if (PageHuge(page) && !page_count(page)) {
rc = dissolve_free_huge_page(page);
if (rc)
break;
}
}
return rc;
}
static struct page *__hugetlb_alloc_buddy_huge_page(struct hstate *h,
gfp_t gfp_mask, int nid, nodemask_t *nmask)
{
int order = huge_page_order(h);
gfp_mask |= __GFP_COMP|__GFP_RETRY_MAYFAIL|__GFP_NOWARN;
if (nid == NUMA_NO_NODE)
nid = numa_mem_id();
return __alloc_pages_nodemask(gfp_mask, order, nid, nmask);
}
static struct page *__alloc_buddy_huge_page(struct hstate *h, gfp_t gfp_mask,
int nid, nodemask_t *nmask)
{
struct page *page;
unsigned int r_nid;
if (hstate_is_gigantic(h))
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
page = __hugetlb_alloc_buddy_huge_page(h, gfp_mask, nid, nmask);
spin_lock(&hugetlb_lock);
if (page) {
INIT_LIST_HEAD(&page->lru);
r_nid = page_to_nid(page);
set_compound_page_dtor(page, HUGETLB_PAGE_DTOR);
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
static
struct page *__alloc_buddy_huge_page_with_mpol(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
struct page *page;
struct mempolicy *mpol;
gfp_t gfp_mask = htlb_alloc_mask(h);
int nid;
nodemask_t *nodemask;
nid = huge_node(vma, addr, gfp_mask, &mpol, &nodemask);
page = __alloc_buddy_huge_page(h, gfp_mask, nid, nodemask);
mpol_cond_put(mpol);
return page;
}
struct page *alloc_huge_page_node(struct hstate *h, int nid)
{
gfp_t gfp_mask = htlb_alloc_mask(h);
struct page *page = NULL;
if (nid != NUMA_NO_NODE)
gfp_mask |= __GFP_THISNODE;
spin_lock(&hugetlb_lock);
if (h->free_huge_pages - h->resv_huge_pages > 0)
page = dequeue_huge_page_nodemask(h, gfp_mask, nid, NULL);
spin_unlock(&hugetlb_lock);
if (!page)
page = __alloc_buddy_huge_page(h, gfp_mask, nid, NULL);
return page;
}
struct page *alloc_huge_page_nodemask(struct hstate *h, int preferred_nid,
nodemask_t *nmask)
{
gfp_t gfp_mask = htlb_alloc_mask(h);
spin_lock(&hugetlb_lock);
if (h->free_huge_pages - h->resv_huge_pages > 0) {
struct page *page;
page = dequeue_huge_page_nodemask(h, gfp_mask, preferred_nid, nmask);
if (page) {
spin_unlock(&hugetlb_lock);
return page;
}
}
spin_unlock(&hugetlb_lock);
return __alloc_buddy_huge_page(h, gfp_mask, preferred_nid, nmask);
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
page = __alloc_buddy_huge_page(h, htlb_alloc_mask(h),
NUMA_NO_NODE, NULL);
if (!page) {
alloc_ok = false;
break;
}
list_add(&page->lru, &surplus_list);
cond_resched();
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
VM_BUG_ON_PAGE(page_count(page), page);
enqueue_huge_page(h, page);
}
free:
spin_unlock(&hugetlb_lock);
list_for_each_entry_safe(page, tmp, &surplus_list, lru)
put_page(page);
spin_lock(&hugetlb_lock);
return ret;
}
static void return_unused_surplus_pages(struct hstate *h,
unsigned long unused_resv_pages)
{
unsigned long nr_pages;
if (hstate_is_gigantic(h))
goto out;
nr_pages = min(unused_resv_pages, h->surplus_huge_pages);
while (nr_pages--) {
h->resv_huge_pages--;
unused_resv_pages--;
if (!free_pool_huge_page(h, &node_states[N_MEMORY], 1))
goto out;
cond_resched_lock(&hugetlb_lock);
}
out:
h->resv_huge_pages -= unused_resv_pages;
}
static long __vma_reservation_common(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr,
enum vma_resv_mode mode)
{
struct resv_map *resv;
pgoff_t idx;
long ret;
resv = vma_resv_map(vma);
if (!resv)
return 1;
idx = vma_hugecache_offset(h, vma, addr);
switch (mode) {
case VMA_NEEDS_RESV:
ret = region_chg(resv, idx, idx + 1);
break;
case VMA_COMMIT_RESV:
ret = region_add(resv, idx, idx + 1);
break;
case VMA_END_RESV:
region_abort(resv, idx, idx + 1);
ret = 0;
break;
case VMA_ADD_RESV:
if (vma->vm_flags & VM_MAYSHARE)
ret = region_add(resv, idx, idx + 1);
else {
region_abort(resv, idx, idx + 1);
ret = region_del(resv, idx, idx + 1);
}
break;
default:
BUG();
}
if (vma->vm_flags & VM_MAYSHARE)
return ret;
else if (is_vma_resv_set(vma, HPAGE_RESV_OWNER) && ret >= 0) {
if (ret)
return 0;
else
return 1;
}
else
return ret < 0 ? ret : 0;
}
static long vma_needs_reservation(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
return __vma_reservation_common(h, vma, addr, VMA_NEEDS_RESV);
}
static long vma_commit_reservation(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
return __vma_reservation_common(h, vma, addr, VMA_COMMIT_RESV);
}
static void vma_end_reservation(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
(void)__vma_reservation_common(h, vma, addr, VMA_END_RESV);
}
static long vma_add_reservation(struct hstate *h,
struct vm_area_struct *vma, unsigned long addr)
{
return __vma_reservation_common(h, vma, addr, VMA_ADD_RESV);
}
static void restore_reserve_on_error(struct hstate *h,
struct vm_area_struct *vma, unsigned long address,
struct page *page)
{
if (unlikely(PagePrivate(page))) {
long rc = vma_needs_reservation(h, vma, address);
if (unlikely(rc < 0)) {
ClearPagePrivate(page);
} else if (rc) {
rc = vma_add_reservation(h, vma, address);
if (unlikely(rc < 0))
ClearPagePrivate(page);
} else
vma_end_reservation(h, vma, address);
}
}
struct page *alloc_huge_page(struct vm_area_struct *vma,
unsigned long addr, int avoid_reserve)
{
struct hugepage_subpool *spool = subpool_vma(vma);
struct hstate *h = hstate_vma(vma);
struct page *page;
long map_chg, map_commit;
long gbl_chg;
int ret, idx;
struct hugetlb_cgroup *h_cg;
idx = hstate_index(h);
map_chg = gbl_chg = vma_needs_reservation(h, vma, addr);
if (map_chg < 0)
return ERR_PTR(-ENOMEM);
if (map_chg || avoid_reserve) {
gbl_chg = hugepage_subpool_get_pages(spool, 1);
if (gbl_chg < 0) {
vma_end_reservation(h, vma, addr);
return ERR_PTR(-ENOSPC);
}
if (avoid_reserve)
gbl_chg = 1;
}
ret = hugetlb_cgroup_charge_cgroup(idx, pages_per_huge_page(h), &h_cg);
if (ret)
goto out_subpool_put;
spin_lock(&hugetlb_lock);
page = dequeue_huge_page_vma(h, vma, addr, avoid_reserve, gbl_chg);
if (!page) {
spin_unlock(&hugetlb_lock);
page = __alloc_buddy_huge_page_with_mpol(h, vma, addr);
if (!page)
goto out_uncharge_cgroup;
if (!avoid_reserve && vma_has_reserves(vma, gbl_chg)) {
SetPagePrivate(page);
h->resv_huge_pages--;
}
spin_lock(&hugetlb_lock);
list_move(&page->lru, &h->hugepage_activelist);
}
hugetlb_cgroup_commit_charge(idx, pages_per_huge_page(h), h_cg, page);
spin_unlock(&hugetlb_lock);
set_page_private(page, (unsigned long)spool);
map_commit = vma_commit_reservation(h, vma, addr);
if (unlikely(map_chg > map_commit)) {
long rsv_adjust;
rsv_adjust = hugepage_subpool_put_pages(spool, 1);
hugetlb_acct_memory(h, -rsv_adjust);
}
return page;
out_uncharge_cgroup:
hugetlb_cgroup_uncharge_cgroup(idx, pages_per_huge_page(h), h_cg);
out_subpool_put:
if (map_chg || avoid_reserve)
hugepage_subpool_put_pages(spool, 1);
vma_end_reservation(h, vma, addr);
return ERR_PTR(-ENOSPC);
}
struct page *alloc_huge_page_noerr(struct vm_area_struct *vma,
unsigned long addr, int avoid_reserve)
{
struct page *page = alloc_huge_page(vma, addr, avoid_reserve);
if (IS_ERR(page))
page = NULL;
return page;
}
int __alloc_bootmem_huge_page(struct hstate *h)
{
struct huge_bootmem_page *m;
int nr_nodes, node;
for_each_node_mask_to_alloc(h, nr_nodes, node, &node_states[N_MEMORY]) {
void *addr;
addr = memblock_virt_alloc_try_nid_nopanic(
huge_page_size(h), huge_page_size(h),
0, BOOTMEM_ALLOC_ACCESSIBLE, node);
if (addr) {
m = addr;
goto found;
}
}
return 0;
found:
BUG_ON(!IS_ALIGNED(virt_to_phys(m), huge_page_size(h)));
list_add(&m->list, &huge_boot_pages);
m->hstate = h;
return 1;
}
static void __init prep_compound_huge_page(struct page *page,
unsigned int order)
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
memblock_free_late(__pa(m),
sizeof(struct huge_bootmem_page));
#else
page = virt_to_page(m);
#endif
WARN_ON(page_count(page) != 1);
prep_compound_huge_page(page, h->order);
WARN_ON(PageReserved(page));
prep_new_huge_page(h, page, page_to_nid(page));
if (hstate_is_gigantic(h))
adjust_managed_page_count(page, 1 << h->order);
}
}
static void __init hugetlb_hstate_alloc_pages(struct hstate *h)
{
unsigned long i;
for (i = 0; i < h->max_huge_pages; ++i) {
if (hstate_is_gigantic(h)) {
if (!alloc_bootmem_huge_page(h))
break;
} else if (!alloc_fresh_huge_page(h,
&node_states[N_MEMORY]))
break;
cond_resched();
}
if (i < h->max_huge_pages) {
char buf[32];
string_get_size(huge_page_size(h), 1, STRING_UNITS_2, buf, 32);
pr_warn("HugeTLB: allocating %lu of page size %s failed. Only allocated %lu hugepages.\n",
h->max_huge_pages, buf, i);
h->max_huge_pages = i;
}
}
static void __init hugetlb_init_hstates(void)
{
struct hstate *h;
for_each_hstate(h) {
if (minimum_order > huge_page_order(h))
minimum_order = huge_page_order(h);
if (!hstate_is_gigantic(h))
hugetlb_hstate_alloc_pages(h);
}
VM_BUG_ON(minimum_order == UINT_MAX);
}
static void __init report_hugepages(void)
{
struct hstate *h;
for_each_hstate(h) {
char buf[32];
string_get_size(huge_page_size(h), 1, STRING_UNITS_2, buf, 32);
pr_info("HugeTLB registered %s page size, pre-allocated %ld pages\n",
buf, h->free_huge_pages);
}
}
static void try_to_free_low(struct hstate *h, unsigned long count,
nodemask_t *nodes_allowed)
{
int i;
if (hstate_is_gigantic(h))
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
int nr_nodes, node;
VM_BUG_ON(delta != -1 && delta != 1);
if (delta < 0) {
for_each_node_mask_to_alloc(h, nr_nodes, node, nodes_allowed) {
if (h->surplus_huge_pages_node[node])
goto found;
}
} else {
for_each_node_mask_to_free(h, nr_nodes, node, nodes_allowed) {
if (h->surplus_huge_pages_node[node] <
h->nr_huge_pages_node[node])
goto found;
}
}
return 0;
found:
h->surplus_huge_pages += delta;
h->surplus_huge_pages_node[node] += delta;
return 1;
}
static unsigned long set_max_huge_pages(struct hstate *h, unsigned long count,
nodemask_t *nodes_allowed)
{
unsigned long min_count, ret;
if (hstate_is_gigantic(h) && !gigantic_page_supported())
return h->max_huge_pages;
spin_lock(&hugetlb_lock);
while (h->surplus_huge_pages && count > persistent_huge_pages(h)) {
if (!adjust_pool_surplus(h, nodes_allowed, -1))
break;
}
while (count > persistent_huge_pages(h)) {
spin_unlock(&hugetlb_lock);
cond_resched();
if (hstate_is_gigantic(h))
ret = alloc_fresh_gigantic_page(h, nodes_allowed);
else
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
cond_resched_lock(&hugetlb_lock);
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
static ssize_t __nr_hugepages_store_common(bool obey_mempolicy,
struct hstate *h, int nid,
unsigned long count, size_t len)
{
int err;
NODEMASK_ALLOC(nodemask_t, nodes_allowed, GFP_KERNEL | __GFP_NORETRY);
if (hstate_is_gigantic(h) && !gigantic_page_supported()) {
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
static ssize_t nr_hugepages_store_common(bool obey_mempolicy,
struct kobject *kobj, const char *buf,
size_t len)
{
struct hstate *h;
unsigned long count;
int nid;
int err;
err = kstrtoul(buf, 10, &count);
if (err)
return err;
h = kobj_to_hstate(kobj, &nid);
return __nr_hugepages_store_common(obey_mempolicy, h, nid, count, len);
}
static ssize_t nr_hugepages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return nr_hugepages_show_common(kobj, attr, buf);
}
static ssize_t nr_hugepages_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t len)
{
return nr_hugepages_store_common(false, kobj, buf, len);
}
static ssize_t nr_hugepages_mempolicy_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return nr_hugepages_show_common(kobj, attr, buf);
}
static ssize_t nr_hugepages_mempolicy_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t len)
{
return nr_hugepages_store_common(true, kobj, buf, len);
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
if (hstate_is_gigantic(h))
return -EINVAL;
err = kstrtoul(buf, 10, &input);
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
const struct attribute_group *hstate_attr_group)
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
static void __init hugetlb_register_all_nodes(void)
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
static void hugetlb_register_all_nodes(void) { }
static int __init hugetlb_init(void)
{
int i;
if (!hugepages_supported())
return 0;
if (!size_to_hstate(default_hstate_size)) {
if (default_hstate_size != 0) {
pr_err("HugeTLB: unsupported default_hugepagesz %lu. Reverting to %lu\n",
default_hstate_size, HPAGE_SIZE);
}
default_hstate_size = HPAGE_SIZE;
if (!size_to_hstate(default_hstate_size))
hugetlb_add_hstate(HUGETLB_PAGE_ORDER);
}
default_hstate_idx = hstate_index(size_to_hstate(default_hstate_size));
if (default_hstate_max_huge_pages) {
if (!default_hstate.max_huge_pages)
default_hstate.max_huge_pages = default_hstate_max_huge_pages;
}
hugetlb_init_hstates();
gather_bootmem_prealloc();
report_hugepages();
hugetlb_sysfs_init();
hugetlb_register_all_nodes();
hugetlb_cgroup_file_init();
#ifdef CONFIG_SMP
num_fault_mutexes = roundup_pow_of_two(8 * num_possible_cpus());
#else
num_fault_mutexes = 1;
#endif
hugetlb_fault_mutex_table =
kmalloc(sizeof(struct mutex) * num_fault_mutexes, GFP_KERNEL);
BUG_ON(!hugetlb_fault_mutex_table);
for (i = 0; i < num_fault_mutexes; i++)
mutex_init(&hugetlb_fault_mutex_table[i]);
return 0;
}
void __init hugetlb_bad_size(void)
{
parsed_valid_hugepagesz = false;
}
void __init hugetlb_add_hstate(unsigned int order)
{
struct hstate *h;
unsigned long i;
if (size_to_hstate(PAGE_SIZE << order)) {
pr_warn("hugepagesz= specified twice, ignoring\n");
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
h->next_nid_to_alloc = first_memory_node;
h->next_nid_to_free = first_memory_node;
snprintf(h->name, HSTATE_NAME_LEN, "hugepages-%lukB",
huge_page_size(h)/1024);
parsed_hstate = h;
}
static int __init hugetlb_nrpages_setup(char *s)
{
unsigned long *mhp;
static unsigned long *last_mhp;
if (!parsed_valid_hugepagesz) {
pr_warn("hugepages = %s preceded by "
"an unsupported hugepagesz, ignoring\n", s);
parsed_valid_hugepagesz = true;
return 1;
}
else if (!hugetlb_max_hstate)
mhp = &default_hstate_max_huge_pages;
else
mhp = &parsed_hstate->max_huge_pages;
if (mhp == last_mhp) {
pr_warn("hugepages= specified twice without interleaving hugepagesz=, ignoring\n");
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
unsigned long tmp = h->max_huge_pages;
int ret;
if (!hugepages_supported())
return -EOPNOTSUPP;
table->data = &tmp;
table->maxlen = sizeof(unsigned long);
ret = proc_doulongvec_minmax(table, write, buffer, length, ppos);
if (ret)
goto out;
if (write)
ret = __nr_hugepages_store_common(obey_mempolicy, h,
NUMA_NO_NODE, tmp, *length);
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
int hugetlb_overcommit_handler(struct ctl_table *table, int write,
void __user *buffer,
size_t *length, loff_t *ppos)
{
struct hstate *h = &default_hstate;
unsigned long tmp;
int ret;
if (!hugepages_supported())
return -EOPNOTSUPP;
tmp = h->nr_overcommit_huge_pages;
if (write && hstate_is_gigantic(h))
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
if (!hugepages_supported())
return;
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
if (!hugepages_supported())
return 0;
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
if (!hugepages_supported())
return;
for_each_node_state(nid, N_MEMORY)
for_each_hstate(h)
pr_info("Node %d hugepages_total=%u hugepages_free=%u hugepages_surp=%u hugepages_size=%lukB\n",
nid,
h->nr_huge_pages_node[nid],
h->free_huge_pages_node[nid],
h->surplus_huge_pages_node[nid],
1UL << (huge_page_order(h) + PAGE_SHIFT - 10));
}
void hugetlb_report_usage(struct seq_file *m, struct mm_struct *mm)
{
seq_printf(m, "HugetlbPages:\t%8lu kB\n",
atomic_long_read(&mm->hugetlb_usage) << (PAGE_SHIFT - 10));
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
struct resv_map *resv = vma_resv_map(vma);
if (resv && is_vma_resv_set(vma, HPAGE_RESV_OWNER))
kref_get(&resv->refs);
}
static void hugetlb_vm_op_close(struct vm_area_struct *vma)
{
struct hstate *h = hstate_vma(vma);
struct resv_map *resv = vma_resv_map(vma);
struct hugepage_subpool *spool = subpool_vma(vma);
unsigned long reserve, start, end;
long gbl_reserve;
if (!resv || !is_vma_resv_set(vma, HPAGE_RESV_OWNER))
return;
start = vma_hugecache_offset(h, vma, vma->vm_start);
end = vma_hugecache_offset(h, vma, vma->vm_end);
reserve = (end - start) - region_count(resv, start, end);
kref_put(&resv->refs, resv_map_release);
if (reserve) {
gbl_reserve = hugepage_subpool_put_pages(spool, reserve);
hugetlb_acct_memory(h, -gbl_reserve);
}
}
static int hugetlb_vm_op_fault(struct vm_fault *vmf)
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
bool is_hugetlb_entry_migration(pte_t pte)
{
swp_entry_t swp;
if (huge_pte_none(pte) || pte_present(pte))
return false;
swp = pte_to_swp_entry(pte);
if (non_swap_entry(swp) && is_migration_entry(swp))
return true;
else
return false;
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
int copy_hugetlb_page_range(struct mm_struct *dst, struct mm_struct *src,
struct vm_area_struct *vma)
{
pte_t *src_pte, *dst_pte, entry;
struct page *ptepage;
unsigned long addr;
int cow;
struct hstate *h = hstate_vma(vma);
unsigned long sz = huge_page_size(h);
unsigned long mmun_start;
unsigned long mmun_end;
int ret = 0;
cow = (vma->vm_flags & (VM_SHARED | VM_MAYWRITE)) == VM_MAYWRITE;
mmun_start = vma->vm_start;
mmun_end = vma->vm_end;
if (cow)
mmu_notifier_invalidate_range_start(src, mmun_start, mmun_end);
for (addr = vma->vm_start; addr < vma->vm_end; addr += sz) {
spinlock_t *src_ptl, *dst_ptl;
src_pte = huge_pte_offset(src, addr, sz);
if (!src_pte)
continue;
dst_pte = huge_pte_alloc(dst, addr, sz);
if (!dst_pte) {
ret = -ENOMEM;
break;
}
if (dst_pte == src_pte)
continue;
dst_ptl = huge_pte_lock(h, dst, dst_pte);
src_ptl = huge_pte_lockptr(h, src, src_pte);
spin_lock_nested(src_ptl, SINGLE_DEPTH_NESTING);
entry = huge_ptep_get(src_pte);
if (huge_pte_none(entry)) {
;
} else if (unlikely(is_hugetlb_entry_migration(entry) ||
is_hugetlb_entry_hwpoisoned(entry))) {
swp_entry_t swp_entry = pte_to_swp_entry(entry);
if (is_write_migration_entry(swp_entry) && cow) {
make_migration_entry_read(&swp_entry);
entry = swp_entry_to_pte(swp_entry);
set_huge_swap_pte_at(src, addr, src_pte,
entry, sz);
}
set_huge_swap_pte_at(dst, addr, dst_pte, entry, sz);
} else {
if (cow) {
huge_ptep_set_wrprotect(src, addr, src_pte);
mmu_notifier_invalidate_range(src, mmun_start,
mmun_end);
}
entry = huge_ptep_get(src_pte);
ptepage = pte_page(entry);
get_page(ptepage);
page_dup_rmap(ptepage, true);
set_huge_pte_at(dst, addr, dst_pte, entry);
hugetlb_count_add(pages_per_huge_page(h), dst);
}
spin_unlock(src_ptl);
spin_unlock(dst_ptl);
}
if (cow)
mmu_notifier_invalidate_range_end(src, mmun_start, mmun_end);
return ret;
}
void __unmap_hugepage_range(struct mmu_gather *tlb, struct vm_area_struct *vma,
unsigned long start, unsigned long end,
struct page *ref_page)
{
struct mm_struct *mm = vma->vm_mm;
unsigned long address;
pte_t *ptep;
pte_t pte;
spinlock_t *ptl;
struct page *page;
struct hstate *h = hstate_vma(vma);
unsigned long sz = huge_page_size(h);
const unsigned long mmun_start = start;
const unsigned long mmun_end = end;
WARN_ON(!is_vm_hugetlb_page(vma));
BUG_ON(start & ~huge_page_mask(h));
BUG_ON(end & ~huge_page_mask(h));
tlb_remove_check_page_size_change(tlb, sz);
tlb_start_vma(tlb, vma);
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
address = start;
for (; address < end; address += sz) {
ptep = huge_pte_offset(mm, address, sz);
if (!ptep)
continue;
ptl = huge_pte_lock(h, mm, ptep);
if (huge_pmd_unshare(mm, &address, ptep)) {
spin_unlock(ptl);
continue;
}
pte = huge_ptep_get(ptep);
if (huge_pte_none(pte)) {
spin_unlock(ptl);
continue;
}
if (unlikely(!pte_present(pte))) {
huge_pte_clear(mm, address, ptep, sz);
spin_unlock(ptl);
continue;
}
page = pte_page(pte);
if (ref_page) {
if (page != ref_page) {
spin_unlock(ptl);
continue;
}
set_vma_resv_flags(vma, HPAGE_RESV_UNMAPPED);
}
pte = huge_ptep_get_and_clear(mm, address, ptep);
tlb_remove_huge_tlb_entry(h, tlb, ptep, address);
if (huge_pte_dirty(pte))
set_page_dirty(page);
hugetlb_count_sub(pages_per_huge_page(h), mm);
page_remove_rmap(page, true);
spin_unlock(ptl);
tlb_remove_page_size(tlb, page, huge_page_size(h));
if (ref_page)
break;
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
static void unmap_ref_private(struct mm_struct *mm, struct vm_area_struct *vma,
struct page *page, unsigned long address)
{
struct hstate *h = hstate_vma(vma);
struct vm_area_struct *iter_vma;
struct address_space *mapping;
pgoff_t pgoff;
address = address & huge_page_mask(h);
pgoff = ((address - vma->vm_start) >> PAGE_SHIFT) +
vma->vm_pgoff;
mapping = vma->vm_file->f_mapping;
i_mmap_lock_write(mapping);
vma_interval_tree_foreach(iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if (iter_vma == vma)
continue;
if (iter_vma->vm_flags & VM_MAYSHARE)
continue;
if (!is_vma_resv_set(iter_vma, HPAGE_RESV_OWNER))
unmap_hugepage_range(iter_vma, address,
address + huge_page_size(h), page);
}
i_mmap_unlock_write(mapping);
}
static int hugetlb_cow(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pte_t *ptep,
struct page *pagecache_page, spinlock_t *ptl)
{
pte_t pte;
struct hstate *h = hstate_vma(vma);
struct page *old_page, *new_page;
int ret = 0, outside_reserve = 0;
unsigned long mmun_start;
unsigned long mmun_end;
pte = huge_ptep_get(ptep);
old_page = pte_page(pte);
retry_avoidcopy:
if (page_mapcount(old_page) == 1 && PageAnon(old_page)) {
page_move_anon_rmap(old_page, vma);
set_huge_ptep_writable(vma, address, ptep);
return 0;
}
if (is_vma_resv_set(vma, HPAGE_RESV_OWNER) &&
old_page != pagecache_page)
outside_reserve = 1;
get_page(old_page);
spin_unlock(ptl);
new_page = alloc_huge_page(vma, address, outside_reserve);
if (IS_ERR(new_page)) {
if (outside_reserve) {
put_page(old_page);
BUG_ON(huge_pte_none(pte));
unmap_ref_private(mm, vma, old_page, address);
BUG_ON(huge_pte_none(pte));
spin_lock(ptl);
ptep = huge_pte_offset(mm, address & huge_page_mask(h),
huge_page_size(h));
if (likely(ptep &&
pte_same(huge_ptep_get(ptep), pte)))
goto retry_avoidcopy;
return 0;
}
ret = (PTR_ERR(new_page) == -ENOMEM) ?
VM_FAULT_OOM : VM_FAULT_SIGBUS;
goto out_release_old;
}
if (unlikely(anon_vma_prepare(vma))) {
ret = VM_FAULT_OOM;
goto out_release_all;
}
copy_user_huge_page(new_page, old_page, address, vma,
pages_per_huge_page(h));
__SetPageUptodate(new_page);
set_page_huge_active(new_page);
mmun_start = address & huge_page_mask(h);
mmun_end = mmun_start + huge_page_size(h);
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
spin_lock(ptl);
ptep = huge_pte_offset(mm, address & huge_page_mask(h),
huge_page_size(h));
if (likely(ptep && pte_same(huge_ptep_get(ptep), pte))) {
ClearPagePrivate(new_page);
huge_ptep_clear_flush(vma, address, ptep);
mmu_notifier_invalidate_range(mm, mmun_start, mmun_end);
set_huge_pte_at(mm, address, ptep,
make_huge_pte(vma, new_page, 1));
page_remove_rmap(old_page, true);
hugepage_add_new_anon_rmap(new_page, vma, address);
new_page = old_page;
}
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
out_release_all:
restore_reserve_on_error(h, vma, address, new_page);
put_page(new_page);
out_release_old:
put_page(old_page);
spin_lock(ptl);
return ret;
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
int huge_add_to_page_cache(struct page *page, struct address_space *mapping,
pgoff_t idx)
{
struct inode *inode = mapping->host;
struct hstate *h = hstate_inode(inode);
int err = add_to_page_cache(page, mapping, idx, GFP_KERNEL);
if (err)
return err;
ClearPagePrivate(page);
spin_lock(&inode->i_lock);
inode->i_blocks += blocks_per_huge_page(h);
spin_unlock(&inode->i_lock);
return 0;
}
static int hugetlb_no_page(struct mm_struct *mm, struct vm_area_struct *vma,
struct address_space *mapping, pgoff_t idx,
unsigned long address, pte_t *ptep, unsigned int flags)
{
struct hstate *h = hstate_vma(vma);
int ret = VM_FAULT_SIGBUS;
int anon_rmap = 0;
unsigned long size;
struct page *page;
pte_t new_pte;
spinlock_t *ptl;
if (is_vma_resv_set(vma, HPAGE_RESV_UNMAPPED)) {
pr_warn_ratelimited("PID %d killed due to inadequate hugepage pool\n",
current->pid);
return ret;
}
retry:
page = find_lock_page(mapping, idx);
if (!page) {
size = i_size_read(mapping->host) >> huge_page_shift(h);
if (idx >= size)
goto out;
if (userfaultfd_missing(vma)) {
u32 hash;
struct vm_fault vmf = {
.vma = vma,
.address = address,
.flags = flags,
};
hash = hugetlb_fault_mutex_hash(h, mm, vma, mapping,
idx, address);
mutex_unlock(&hugetlb_fault_mutex_table[hash]);
ret = handle_userfault(&vmf, VM_UFFD_MISSING);
mutex_lock(&hugetlb_fault_mutex_table[hash]);
goto out;
}
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
set_page_huge_active(page);
if (vma->vm_flags & VM_MAYSHARE) {
int err = huge_add_to_page_cache(page, mapping, idx);
if (err) {
put_page(page);
if (err == -EEXIST)
goto retry;
goto out;
}
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
if ((flags & FAULT_FLAG_WRITE) && !(vma->vm_flags & VM_SHARED)) {
if (vma_needs_reservation(h, vma, address) < 0) {
ret = VM_FAULT_OOM;
goto backout_unlocked;
}
vma_end_reservation(h, vma, address);
}
ptl = huge_pte_lock(h, mm, ptep);
size = i_size_read(mapping->host) >> huge_page_shift(h);
if (idx >= size)
goto backout;
ret = 0;
if (!huge_pte_none(huge_ptep_get(ptep)))
goto backout;
if (anon_rmap) {
ClearPagePrivate(page);
hugepage_add_new_anon_rmap(page, vma, address);
} else
page_dup_rmap(page, true);
new_pte = make_huge_pte(vma, page, ((vma->vm_flags & VM_WRITE)
&& (vma->vm_flags & VM_SHARED)));
set_huge_pte_at(mm, address, ptep, new_pte);
hugetlb_count_add(pages_per_huge_page(h), mm);
if ((flags & FAULT_FLAG_WRITE) && !(vma->vm_flags & VM_SHARED)) {
ret = hugetlb_cow(mm, vma, address, ptep, page, ptl);
}
spin_unlock(ptl);
unlock_page(page);
out:
return ret;
backout:
spin_unlock(ptl);
backout_unlocked:
unlock_page(page);
restore_reserve_on_error(h, vma, address, page);
put_page(page);
goto out;
}
u32 hugetlb_fault_mutex_hash(struct hstate *h, struct mm_struct *mm,
struct vm_area_struct *vma,
struct address_space *mapping,
pgoff_t idx, unsigned long address)
{
unsigned long key[2];
u32 hash;
if (vma->vm_flags & VM_SHARED) {
key[0] = (unsigned long) mapping;
key[1] = idx;
} else {
key[0] = (unsigned long) mm;
key[1] = address >> huge_page_shift(h);
}
hash = jhash2((u32 *)&key, sizeof(key)/sizeof(u32), 0);
return hash & (num_fault_mutexes - 1);
}
u32 hugetlb_fault_mutex_hash(struct hstate *h, struct mm_struct *mm,
struct vm_area_struct *vma,
struct address_space *mapping,
pgoff_t idx, unsigned long address)
{
return 0;
}
int hugetlb_fault(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, unsigned int flags)
{
pte_t *ptep, entry;
spinlock_t *ptl;
int ret;
u32 hash;
pgoff_t idx;
struct page *page = NULL;
struct page *pagecache_page = NULL;
struct hstate *h = hstate_vma(vma);
struct address_space *mapping;
int need_wait_lock = 0;
address &= huge_page_mask(h);
ptep = huge_pte_offset(mm, address, huge_page_size(h));
if (ptep) {
entry = huge_ptep_get(ptep);
if (unlikely(is_hugetlb_entry_migration(entry))) {
migration_entry_wait_huge(vma, mm, ptep);
return 0;
} else if (unlikely(is_hugetlb_entry_hwpoisoned(entry)))
return VM_FAULT_HWPOISON_LARGE |
VM_FAULT_SET_HINDEX(hstate_index(h));
} else {
ptep = huge_pte_alloc(mm, address, huge_page_size(h));
if (!ptep)
return VM_FAULT_OOM;
}
mapping = vma->vm_file->f_mapping;
idx = vma_hugecache_offset(h, vma, address);
hash = hugetlb_fault_mutex_hash(h, mm, vma, mapping, idx, address);
mutex_lock(&hugetlb_fault_mutex_table[hash]);
entry = huge_ptep_get(ptep);
if (huge_pte_none(entry)) {
ret = hugetlb_no_page(mm, vma, mapping, idx, address, ptep, flags);
goto out_mutex;
}
ret = 0;
if (!pte_present(entry))
goto out_mutex;
if ((flags & FAULT_FLAG_WRITE) && !huge_pte_write(entry)) {
if (vma_needs_reservation(h, vma, address) < 0) {
ret = VM_FAULT_OOM;
goto out_mutex;
}
vma_end_reservation(h, vma, address);
if (!(vma->vm_flags & VM_MAYSHARE))
pagecache_page = hugetlbfs_pagecache_page(h,
vma, address);
}
ptl = huge_pte_lock(h, mm, ptep);
if (unlikely(!pte_same(entry, huge_ptep_get(ptep))))
goto out_ptl;
page = pte_page(entry);
if (page != pagecache_page)
if (!trylock_page(page)) {
need_wait_lock = 1;
goto out_ptl;
}
get_page(page);
if (flags & FAULT_FLAG_WRITE) {
if (!huge_pte_write(entry)) {
ret = hugetlb_cow(mm, vma, address, ptep,
pagecache_page, ptl);
goto out_put_page;
}
entry = huge_pte_mkdirty(entry);
}
entry = pte_mkyoung(entry);
if (huge_ptep_set_access_flags(vma, address, ptep, entry,
flags & FAULT_FLAG_WRITE))
update_mmu_cache(vma, address, ptep);
out_put_page:
if (page != pagecache_page)
unlock_page(page);
put_page(page);
out_ptl:
spin_unlock(ptl);
if (pagecache_page) {
unlock_page(pagecache_page);
put_page(pagecache_page);
}
out_mutex:
mutex_unlock(&hugetlb_fault_mutex_table[hash]);
if (need_wait_lock)
wait_on_page_locked(page);
return ret;
}
int hugetlb_mcopy_atomic_pte(struct mm_struct *dst_mm,
pte_t *dst_pte,
struct vm_area_struct *dst_vma,
unsigned long dst_addr,
unsigned long src_addr,
struct page **pagep)
{
struct address_space *mapping;
pgoff_t idx;
unsigned long size;
int vm_shared = dst_vma->vm_flags & VM_SHARED;
struct hstate *h = hstate_vma(dst_vma);
pte_t _dst_pte;
spinlock_t *ptl;
int ret;
struct page *page;
if (!*pagep) {
ret = -ENOMEM;
page = alloc_huge_page(dst_vma, dst_addr, 0);
if (IS_ERR(page))
goto out;
ret = copy_huge_page_from_user(page,
(const void __user *) src_addr,
pages_per_huge_page(h), false);
if (unlikely(ret)) {
ret = -EFAULT;
*pagep = page;
goto out;
}
} else {
page = *pagep;
*pagep = NULL;
}
__SetPageUptodate(page);
set_page_huge_active(page);
mapping = dst_vma->vm_file->f_mapping;
idx = vma_hugecache_offset(h, dst_vma, dst_addr);
if (vm_shared) {
size = i_size_read(mapping->host) >> huge_page_shift(h);
ret = -EFAULT;
if (idx >= size)
goto out_release_nounlock;
ret = huge_add_to_page_cache(page, mapping, idx);
if (ret)
goto out_release_nounlock;
}
ptl = huge_pte_lockptr(h, dst_mm, dst_pte);
spin_lock(ptl);
size = i_size_read(mapping->host) >> huge_page_shift(h);
ret = -EFAULT;
if (idx >= size)
goto out_release_unlock;
ret = -EEXIST;
if (!huge_pte_none(huge_ptep_get(dst_pte)))
goto out_release_unlock;
if (vm_shared) {
page_dup_rmap(page, true);
} else {
ClearPagePrivate(page);
hugepage_add_new_anon_rmap(page, dst_vma, dst_addr);
}
_dst_pte = make_huge_pte(dst_vma, page, dst_vma->vm_flags & VM_WRITE);
if (dst_vma->vm_flags & VM_WRITE)
_dst_pte = huge_pte_mkdirty(_dst_pte);
_dst_pte = pte_mkyoung(_dst_pte);
set_huge_pte_at(dst_mm, dst_addr, dst_pte, _dst_pte);
(void)huge_ptep_set_access_flags(dst_vma, dst_addr, dst_pte, _dst_pte,
dst_vma->vm_flags & VM_WRITE);
hugetlb_count_add(pages_per_huge_page(h), dst_mm);
update_mmu_cache(dst_vma, dst_addr, dst_pte);
spin_unlock(ptl);
if (vm_shared)
unlock_page(page);
ret = 0;
out:
return ret;
out_release_unlock:
spin_unlock(ptl);
if (vm_shared)
unlock_page(page);
out_release_nounlock:
put_page(page);
goto out;
}
long follow_hugetlb_page(struct mm_struct *mm, struct vm_area_struct *vma,
struct page **pages, struct vm_area_struct **vmas,
unsigned long *position, unsigned long *nr_pages,
long i, unsigned int flags, int *nonblocking)
{
unsigned long pfn_offset;
unsigned long vaddr = *position;
unsigned long remainder = *nr_pages;
struct hstate *h = hstate_vma(vma);
int err = -EFAULT;
while (vaddr < vma->vm_end && remainder) {
pte_t *pte;
spinlock_t *ptl = NULL;
int absent;
struct page *page;
if (unlikely(fatal_signal_pending(current))) {
remainder = 0;
break;
}
pte = huge_pte_offset(mm, vaddr & huge_page_mask(h),
huge_page_size(h));
if (pte)
ptl = huge_pte_lock(h, mm, pte);
absent = !pte || huge_pte_none(huge_ptep_get(pte));
if (absent && (flags & FOLL_DUMP) &&
!hugetlbfs_pagecache_present(h, vma, vaddr)) {
if (pte)
spin_unlock(ptl);
remainder = 0;
break;
}
if (absent || is_swap_pte(huge_ptep_get(pte)) ||
((flags & FOLL_WRITE) &&
!huge_pte_write(huge_ptep_get(pte)))) {
int ret;
unsigned int fault_flags = 0;
if (pte)
spin_unlock(ptl);
if (flags & FOLL_WRITE)
fault_flags |= FAULT_FLAG_WRITE;
if (nonblocking)
fault_flags |= FAULT_FLAG_ALLOW_RETRY;
if (flags & FOLL_NOWAIT)
fault_flags |= FAULT_FLAG_ALLOW_RETRY |
FAULT_FLAG_RETRY_NOWAIT;
if (flags & FOLL_TRIED) {
VM_WARN_ON_ONCE(fault_flags &
FAULT_FLAG_ALLOW_RETRY);
fault_flags |= FAULT_FLAG_TRIED;
}
ret = hugetlb_fault(mm, vma, vaddr, fault_flags);
if (ret & VM_FAULT_ERROR) {
err = vm_fault_to_errno(ret, flags);
remainder = 0;
break;
}
if (ret & VM_FAULT_RETRY) {
if (nonblocking)
*nonblocking = 0;
*nr_pages = 0;
return i;
}
continue;
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
spin_unlock(ptl);
}
*nr_pages = remainder;
*position = vaddr;
return i ? i : err;
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
mmu_notifier_invalidate_range_start(mm, start, end);
i_mmap_lock_write(vma->vm_file->f_mapping);
for (; address < end; address += huge_page_size(h)) {
spinlock_t *ptl;
ptep = huge_pte_offset(mm, address, huge_page_size(h));
if (!ptep)
continue;
ptl = huge_pte_lock(h, mm, ptep);
if (huge_pmd_unshare(mm, &address, ptep)) {
pages++;
spin_unlock(ptl);
continue;
}
pte = huge_ptep_get(ptep);
if (unlikely(is_hugetlb_entry_hwpoisoned(pte))) {
spin_unlock(ptl);
continue;
}
if (unlikely(is_hugetlb_entry_migration(pte))) {
swp_entry_t entry = pte_to_swp_entry(pte);
if (is_write_migration_entry(entry)) {
pte_t newpte;
make_migration_entry_read(&entry);
newpte = swp_entry_to_pte(entry);
set_huge_swap_pte_at(mm, address, ptep,
newpte, huge_page_size(h));
pages++;
}
spin_unlock(ptl);
continue;
}
if (!huge_pte_none(pte)) {
pte = huge_ptep_get_and_clear(mm, address, ptep);
pte = pte_mkhuge(huge_pte_modify(pte, newprot));
pte = arch_make_huge_pte(pte, vma, NULL, 0);
set_huge_pte_at(mm, address, ptep, pte);
pages++;
}
spin_unlock(ptl);
}
flush_hugetlb_tlb_range(vma, start, end);
mmu_notifier_invalidate_range(mm, start, end);
i_mmap_unlock_write(vma->vm_file->f_mapping);
mmu_notifier_invalidate_range_end(mm, start, end);
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
struct resv_map *resv_map;
long gbl_reserve;
if (vm_flags & VM_NORESERVE)
return 0;
if (!vma || vma->vm_flags & VM_MAYSHARE) {
resv_map = inode_resv_map(inode);
chg = region_chg(resv_map, from, to);
} else {
resv_map = resv_map_alloc();
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
gbl_reserve = hugepage_subpool_get_pages(spool, chg);
if (gbl_reserve < 0) {
ret = -ENOSPC;
goto out_err;
}
ret = hugetlb_acct_memory(h, gbl_reserve);
if (ret < 0) {
(void)hugepage_subpool_put_pages(spool, chg);
goto out_err;
}
if (!vma || vma->vm_flags & VM_MAYSHARE) {
long add = region_add(resv_map, from, to);
if (unlikely(chg > add)) {
long rsv_adjust;
rsv_adjust = hugepage_subpool_put_pages(spool,
chg - add);
hugetlb_acct_memory(h, -rsv_adjust);
}
}
return 0;
out_err:
if (!vma || vma->vm_flags & VM_MAYSHARE)
if (chg >= 0)
region_abort(resv_map, from, to);
if (vma && is_vma_resv_set(vma, HPAGE_RESV_OWNER))
kref_put(&resv_map->refs, resv_map_release);
return ret;
}
long hugetlb_unreserve_pages(struct inode *inode, long start, long end,
long freed)
{
struct hstate *h = hstate_inode(inode);
struct resv_map *resv_map = inode_resv_map(inode);
long chg = 0;
struct hugepage_subpool *spool = subpool_inode(inode);
long gbl_reserve;
if (resv_map) {
chg = region_del(resv_map, start, end);
if (chg < 0)
return chg;
}
spin_lock(&inode->i_lock);
inode->i_blocks -= (blocks_per_huge_page(h) * freed);
spin_unlock(&inode->i_lock);
gbl_reserve = hugepage_subpool_put_pages(spool, (chg - freed));
hugetlb_acct_memory(h, -gbl_reserve);
return 0;
}
static unsigned long page_table_shareable(struct vm_area_struct *svma,
struct vm_area_struct *vma,
unsigned long addr, pgoff_t idx)
{
unsigned long saddr = ((idx - svma->vm_pgoff) << PAGE_SHIFT) +
svma->vm_start;
unsigned long sbase = saddr & PUD_MASK;
unsigned long s_end = sbase + PUD_SIZE;
unsigned long vm_flags = vma->vm_flags & VM_LOCKED_CLEAR_MASK;
unsigned long svm_flags = svma->vm_flags & VM_LOCKED_CLEAR_MASK;
if (pmd_index(addr) != pmd_index(saddr) ||
vm_flags != svm_flags ||
sbase < svma->vm_start || svma->vm_end < s_end)
return 0;
return saddr;
}
static bool vma_shareable(struct vm_area_struct *vma, unsigned long addr)
{
unsigned long base = addr & PUD_MASK;
unsigned long end = base + PUD_SIZE;
if (vma->vm_flags & VM_MAYSHARE &&
vma->vm_start <= base && end <= vma->vm_end)
return true;
return false;
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
spinlock_t *ptl;
if (!vma_shareable(vma, addr))
return (pte_t *)pmd_alloc(mm, pud, addr);
i_mmap_lock_write(mapping);
vma_interval_tree_foreach(svma, &mapping->i_mmap, idx, idx) {
if (svma == vma)
continue;
saddr = page_table_shareable(svma, vma, addr, idx);
if (saddr) {
spte = huge_pte_offset(svma->vm_mm, saddr,
vma_mmu_pagesize(svma));
if (spte) {
get_page(virt_to_page(spte));
break;
}
}
}
if (!spte)
goto out;
ptl = huge_pte_lock(hstate_vma(vma), mm, spte);
if (pud_none(*pud)) {
pud_populate(mm, pud,
(pmd_t *)((unsigned long)spte & PAGE_MASK));
mm_inc_nr_pmds(mm);
} else {
put_page(virt_to_page(spte));
}
spin_unlock(ptl);
out:
pte = (pte_t *)pmd_alloc(mm, pud, addr);
i_mmap_unlock_write(mapping);
return pte;
}
int huge_pmd_unshare(struct mm_struct *mm, unsigned long *addr, pte_t *ptep)
{
pgd_t *pgd = pgd_offset(mm, *addr);
p4d_t *p4d = p4d_offset(pgd, *addr);
pud_t *pud = pud_offset(p4d, *addr);
BUG_ON(page_count(virt_to_page(ptep)) == 0);
if (page_count(virt_to_page(ptep)) == 1)
return 0;
pud_clear(pud);
put_page(virt_to_page(ptep));
mm_dec_nr_pmds(mm);
*addr = ALIGN(*addr, HPAGE_SIZE * PTRS_PER_PTE) - HPAGE_SIZE;
return 1;
}
pte_t *huge_pmd_share(struct mm_struct *mm, unsigned long addr, pud_t *pud)
{
return NULL;
}
int huge_pmd_unshare(struct mm_struct *mm, unsigned long *addr, pte_t *ptep)
{
return 0;
}
pte_t *huge_pte_alloc(struct mm_struct *mm,
unsigned long addr, unsigned long sz)
{
pgd_t *pgd;
p4d_t *p4d;
pud_t *pud;
pte_t *pte = NULL;
pgd = pgd_offset(mm, addr);
p4d = p4d_offset(pgd, addr);
pud = pud_alloc(mm, p4d, addr);
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
BUG_ON(pte && pte_present(*pte) && !pte_huge(*pte));
return pte;
}
pte_t *huge_pte_offset(struct mm_struct *mm,
unsigned long addr, unsigned long sz)
{
pgd_t *pgd;
p4d_t *p4d;
pud_t *pud;
pmd_t *pmd;
pgd = pgd_offset(mm, addr);
if (!pgd_present(*pgd))
return NULL;
p4d = p4d_offset(pgd, addr);
if (!p4d_present(*p4d))
return NULL;
pud = pud_offset(p4d, addr);
if (sz != PUD_SIZE && pud_none(*pud))
return NULL;
if (pud_huge(*pud) || !pud_present(*pud))
return (pte_t *)pud;
pmd = pmd_offset(pud, addr);
if (sz != PMD_SIZE && pmd_none(*pmd))
return NULL;
if (pmd_huge(*pmd) || !pmd_present(*pmd))
return (pte_t *)pmd;
return NULL;
}
struct page * __weak
follow_huge_addr(struct mm_struct *mm, unsigned long address,
int write)
{
return ERR_PTR(-EINVAL);
}
struct page * __weak
follow_huge_pd(struct vm_area_struct *vma,
unsigned long address, hugepd_t hpd, int flags, int pdshift)
{
WARN(1, "hugepd follow called with no support for hugepage directory format\n");
return NULL;
}
struct page * __weak
follow_huge_pmd(struct mm_struct *mm, unsigned long address,
pmd_t *pmd, int flags)
{
struct page *page = NULL;
spinlock_t *ptl;
pte_t pte;
retry:
ptl = pmd_lockptr(mm, pmd);
spin_lock(ptl);
if (!pmd_huge(*pmd))
goto out;
pte = huge_ptep_get((pte_t *)pmd);
if (pte_present(pte)) {
page = pmd_page(*pmd) + ((address & ~PMD_MASK) >> PAGE_SHIFT);
if (flags & FOLL_GET)
get_page(page);
} else {
if (is_hugetlb_entry_migration(pte)) {
spin_unlock(ptl);
__migration_entry_wait(mm, (pte_t *)pmd, ptl);
goto retry;
}
}
out:
spin_unlock(ptl);
return page;
}
struct page * __weak
follow_huge_pud(struct mm_struct *mm, unsigned long address,
pud_t *pud, int flags)
{
if (flags & FOLL_GET)
return NULL;
return pte_page(*(pte_t *)pud) + ((address & ~PUD_MASK) >> PAGE_SHIFT);
}
struct page * __weak
follow_huge_pgd(struct mm_struct *mm, unsigned long address, pgd_t *pgd, int flags)
{
if (flags & FOLL_GET)
return NULL;
return pte_page(*(pte_t *)pgd) + ((address & ~PGDIR_MASK) >> PAGE_SHIFT);
}
bool isolate_huge_page(struct page *page, struct list_head *list)
{
bool ret = true;
VM_BUG_ON_PAGE(!PageHead(page), page);
spin_lock(&hugetlb_lock);
if (!page_huge_active(page) || !get_page_unless_zero(page)) {
ret = false;
goto unlock;
}
clear_page_huge_active(page);
list_move_tail(&page->lru, list);
unlock:
spin_unlock(&hugetlb_lock);
return ret;
}
void putback_active_hugepage(struct page *page)
{
VM_BUG_ON_PAGE(!PageHead(page), page);
spin_lock(&hugetlb_lock);
set_page_huge_active(page);
list_move_tail(&page->lru, &(page_hstate(page))->hugepage_activelist);
spin_unlock(&hugetlb_lock);
put_page(page);
}
