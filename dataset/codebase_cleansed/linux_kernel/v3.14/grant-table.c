static int map_pte_fn(pte_t *pte, struct page *pmd_page,
unsigned long addr, void *data)
{
unsigned long **frames = (unsigned long **)data;
set_pte_at(&init_mm, addr, pte, mfn_pte((*frames)[0], PAGE_KERNEL));
(*frames)++;
return 0;
}
static int map_pte_fn_status(pte_t *pte, struct page *pmd_page,
unsigned long addr, void *data)
{
uint64_t **frames = (uint64_t **)data;
set_pte_at(&init_mm, addr, pte, mfn_pte((*frames)[0], PAGE_KERNEL));
(*frames)++;
return 0;
}
static int unmap_pte_fn(pte_t *pte, struct page *pmd_page,
unsigned long addr, void *data)
{
set_pte_at(&init_mm, addr, pte, __pte(0));
return 0;
}
int arch_gnttab_map_shared(unsigned long *frames, unsigned long nr_gframes,
unsigned long max_nr_gframes,
void **__shared)
{
int rc;
void *shared = *__shared;
if (shared == NULL) {
struct vm_struct *area =
alloc_vm_area(PAGE_SIZE * max_nr_gframes, NULL);
BUG_ON(area == NULL);
shared = area->addr;
*__shared = shared;
}
rc = apply_to_page_range(&init_mm, (unsigned long)shared,
PAGE_SIZE * nr_gframes,
map_pte_fn, &frames);
return rc;
}
int arch_gnttab_map_status(uint64_t *frames, unsigned long nr_gframes,
unsigned long max_nr_gframes,
grant_status_t **__shared)
{
int rc;
grant_status_t *shared = *__shared;
if (shared == NULL) {
struct vm_struct *area =
alloc_vm_area(PAGE_SIZE * max_nr_gframes, NULL);
BUG_ON(area == NULL);
shared = area->addr;
*__shared = shared;
}
rc = apply_to_page_range(&init_mm, (unsigned long)shared,
PAGE_SIZE * nr_gframes,
map_pte_fn_status, &frames);
return rc;
}
void arch_gnttab_unmap(void *shared, unsigned long nr_gframes)
{
apply_to_page_range(&init_mm, (unsigned long)shared,
PAGE_SIZE * nr_gframes, unmap_pte_fn, NULL);
}
static int __init xlated_setup_gnttab_pages(void)
{
struct page **pages;
xen_pfn_t *pfns;
int rc;
unsigned int i;
unsigned long nr_grant_frames = gnttab_max_grant_frames();
BUG_ON(nr_grant_frames == 0);
pages = kcalloc(nr_grant_frames, sizeof(pages[0]), GFP_KERNEL);
if (!pages)
return -ENOMEM;
pfns = kcalloc(nr_grant_frames, sizeof(pfns[0]), GFP_KERNEL);
if (!pfns) {
kfree(pages);
return -ENOMEM;
}
rc = alloc_xenballooned_pages(nr_grant_frames, pages, 0 );
if (rc) {
pr_warn("%s Couldn't balloon alloc %ld pfns rc:%d\n", __func__,
nr_grant_frames, rc);
kfree(pages);
kfree(pfns);
return rc;
}
for (i = 0; i < nr_grant_frames; i++)
pfns[i] = page_to_pfn(pages[i]);
rc = arch_gnttab_map_shared(pfns, nr_grant_frames, nr_grant_frames,
&xen_auto_xlat_grant_frames.vaddr);
if (rc) {
pr_warn("%s Couldn't map %ld pfns rc:%d\n", __func__,
nr_grant_frames, rc);
free_xenballooned_pages(nr_grant_frames, pages);
kfree(pages);
kfree(pfns);
return rc;
}
kfree(pages);
xen_auto_xlat_grant_frames.pfn = pfns;
xen_auto_xlat_grant_frames.count = nr_grant_frames;
return 0;
}
static int __init xen_pvh_gnttab_setup(void)
{
if (!xen_pvh_domain())
return -ENODEV;
return xlated_setup_gnttab_pages();
}
