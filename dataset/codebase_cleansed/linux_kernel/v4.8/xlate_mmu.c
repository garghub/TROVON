static void xen_for_each_gfn(struct page **pages, unsigned nr_gfn,
xen_gfn_fn_t fn, void *data)
{
unsigned long xen_pfn = 0;
struct page *page;
int i;
for (i = 0; i < nr_gfn; i++) {
if ((i % XEN_PFN_PER_PAGE) == 0) {
page = pages[i / XEN_PFN_PER_PAGE];
xen_pfn = page_to_xen_pfn(page);
}
fn(pfn_to_gfn(xen_pfn++), data);
}
}
static void setup_hparams(unsigned long gfn, void *data)
{
struct remap_data *info = data;
info->h_idxs[info->h_iter] = *info->fgfn;
info->h_gpfns[info->h_iter] = gfn;
info->h_errs[info->h_iter] = 0;
info->h_iter++;
info->fgfn++;
}
static int remap_pte_fn(pte_t *ptep, pgtable_t token, unsigned long addr,
void *data)
{
struct remap_data *info = data;
struct page *page = info->pages[info->index++];
pte_t pte = pte_mkspecial(pfn_pte(page_to_pfn(page), info->prot));
int rc, nr_gfn;
uint32_t i;
struct xen_add_to_physmap_range xatp = {
.domid = DOMID_SELF,
.foreign_domid = info->domid,
.space = XENMAPSPACE_gmfn_foreign,
};
nr_gfn = min_t(typeof(info->nr_fgfn), XEN_PFN_PER_PAGE, info->nr_fgfn);
info->nr_fgfn -= nr_gfn;
info->h_iter = 0;
xen_for_each_gfn(&page, nr_gfn, setup_hparams, info);
BUG_ON(info->h_iter != nr_gfn);
set_xen_guest_handle(xatp.idxs, info->h_idxs);
set_xen_guest_handle(xatp.gpfns, info->h_gpfns);
set_xen_guest_handle(xatp.errs, info->h_errs);
xatp.size = nr_gfn;
rc = HYPERVISOR_memory_op(XENMEM_add_to_physmap_range, &xatp);
for (i = 0; i < nr_gfn; i++) {
int err = (rc < 0) ? rc : info->h_errs[i];
*(info->err_ptr++) = err;
if (!err)
info->mapped++;
}
if (!rc)
set_pte_at(info->vma->vm_mm, addr, ptep, pte);
return 0;
}
int xen_xlate_remap_gfn_array(struct vm_area_struct *vma,
unsigned long addr,
xen_pfn_t *gfn, int nr,
int *err_ptr, pgprot_t prot,
unsigned domid,
struct page **pages)
{
int err;
struct remap_data data;
unsigned long range = DIV_ROUND_UP(nr, XEN_PFN_PER_PAGE) << PAGE_SHIFT;
BUG_ON(!((vma->vm_flags & (VM_PFNMAP | VM_IO)) == (VM_PFNMAP | VM_IO)));
data.fgfn = gfn;
data.nr_fgfn = nr;
data.prot = prot;
data.domid = domid;
data.vma = vma;
data.pages = pages;
data.index = 0;
data.err_ptr = err_ptr;
data.mapped = 0;
err = apply_to_page_range(vma->vm_mm, addr, range,
remap_pte_fn, &data);
return err < 0 ? err : data.mapped;
}
static void unmap_gfn(unsigned long gfn, void *data)
{
struct xen_remove_from_physmap xrp;
xrp.domid = DOMID_SELF;
xrp.gpfn = gfn;
(void)HYPERVISOR_memory_op(XENMEM_remove_from_physmap, &xrp);
}
int xen_xlate_unmap_gfn_range(struct vm_area_struct *vma,
int nr, struct page **pages)
{
xen_for_each_gfn(pages, nr, unmap_gfn, NULL);
return 0;
}
static void setup_balloon_gfn(unsigned long gfn, void *data)
{
struct map_balloon_pages *info = data;
info->pfns[info->idx++] = gfn;
}
int __init xen_xlate_map_ballooned_pages(xen_pfn_t **gfns, void **virt,
unsigned long nr_grant_frames)
{
struct page **pages;
xen_pfn_t *pfns;
void *vaddr;
struct map_balloon_pages data;
int rc;
unsigned long nr_pages;
BUG_ON(nr_grant_frames == 0);
nr_pages = DIV_ROUND_UP(nr_grant_frames, XEN_PFN_PER_PAGE);
pages = kcalloc(nr_pages, sizeof(pages[0]), GFP_KERNEL);
if (!pages)
return -ENOMEM;
pfns = kcalloc(nr_grant_frames, sizeof(pfns[0]), GFP_KERNEL);
if (!pfns) {
kfree(pages);
return -ENOMEM;
}
rc = alloc_xenballooned_pages(nr_pages, pages);
if (rc) {
pr_warn("%s Couldn't balloon alloc %ld pages rc:%d\n", __func__,
nr_pages, rc);
kfree(pages);
kfree(pfns);
return rc;
}
data.pfns = pfns;
data.idx = 0;
xen_for_each_gfn(pages, nr_grant_frames, setup_balloon_gfn, &data);
vaddr = vmap(pages, nr_pages, 0, PAGE_KERNEL);
if (!vaddr) {
pr_warn("%s Couldn't map %ld pages rc:%d\n", __func__,
nr_pages, rc);
free_xenballooned_pages(nr_pages, pages);
kfree(pages);
kfree(pfns);
return -ENOMEM;
}
kfree(pages);
*gfns = pfns;
*virt = vaddr;
return 0;
}
