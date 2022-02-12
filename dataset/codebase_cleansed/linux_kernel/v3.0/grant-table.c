static int map_pte_fn(pte_t *pte, struct page *pmd_page,
unsigned long addr, void *data)
{
unsigned long **frames = (unsigned long **)data;
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
struct grant_entry **__shared)
{
int rc;
struct grant_entry *shared = *__shared;
if (shared == NULL) {
struct vm_struct *area =
xen_alloc_vm_area(PAGE_SIZE * max_nr_gframes);
BUG_ON(area == NULL);
shared = area->addr;
*__shared = shared;
}
rc = apply_to_page_range(&init_mm, (unsigned long)shared,
PAGE_SIZE * nr_gframes,
map_pte_fn, &frames);
return rc;
}
void arch_gnttab_unmap_shared(struct grant_entry *shared,
unsigned long nr_gframes)
{
apply_to_page_range(&init_mm, (unsigned long)shared,
PAGE_SIZE * nr_gframes, unmap_pte_fn, NULL);
}
