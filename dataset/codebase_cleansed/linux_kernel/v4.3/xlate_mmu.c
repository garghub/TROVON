static int map_foreign_page(unsigned long lpfn, unsigned long fgfn,
unsigned int domid)
{
int rc;
struct xen_add_to_physmap_range xatp = {
.domid = DOMID_SELF,
.foreign_domid = domid,
.size = 1,
.space = XENMAPSPACE_gmfn_foreign,
};
xen_ulong_t idx = fgfn;
xen_pfn_t gpfn = lpfn;
int err = 0;
set_xen_guest_handle(xatp.idxs, &idx);
set_xen_guest_handle(xatp.gpfns, &gpfn);
set_xen_guest_handle(xatp.errs, &err);
rc = HYPERVISOR_memory_op(XENMEM_add_to_physmap_range, &xatp);
return rc < 0 ? rc : err;
}
static int remap_pte_fn(pte_t *ptep, pgtable_t token, unsigned long addr,
void *data)
{
struct remap_data *info = data;
struct page *page = info->pages[info->index++];
unsigned long pfn = page_to_pfn(page);
pte_t pte = pte_mkspecial(pfn_pte(pfn, info->prot));
int rc;
rc = map_foreign_page(pfn, *info->fgfn, info->domid);
*info->err_ptr++ = rc;
if (!rc) {
set_pte_at(info->vma->vm_mm, addr, ptep, pte);
info->mapped++;
}
info->fgfn++;
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
unsigned long range = nr << PAGE_SHIFT;
BUG_ON(!((vma->vm_flags & (VM_PFNMAP | VM_IO)) == (VM_PFNMAP | VM_IO)));
data.fgfn = gfn;
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
int xen_xlate_unmap_gfn_range(struct vm_area_struct *vma,
int nr, struct page **pages)
{
int i;
for (i = 0; i < nr; i++) {
struct xen_remove_from_physmap xrp;
unsigned long pfn;
pfn = page_to_pfn(pages[i]);
xrp.domid = DOMID_SELF;
xrp.gpfn = pfn;
(void)HYPERVISOR_memory_op(XENMEM_remove_from_physmap, &xrp);
}
return 0;
}
