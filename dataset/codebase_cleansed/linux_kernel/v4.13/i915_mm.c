static int remap_pfn(pte_t *pte, pgtable_t token,
unsigned long addr, void *data)
{
struct remap_pfn *r = data;
set_pte_at(r->mm, addr, pte, pte_mkspecial(pfn_pte(r->pfn, r->prot)));
r->pfn++;
return 0;
}
int remap_io_mapping(struct vm_area_struct *vma,
unsigned long addr, unsigned long pfn, unsigned long size,
struct io_mapping *iomap)
{
struct remap_pfn r;
int err;
GEM_BUG_ON((vma->vm_flags &
(VM_IO | VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP)) !=
(VM_IO | VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP));
r.mm = vma->vm_mm;
r.pfn = pfn;
r.prot = __pgprot((pgprot_val(iomap->prot) & _PAGE_CACHE_MASK) |
(pgprot_val(vma->vm_page_prot) & ~_PAGE_CACHE_MASK));
err = apply_to_page_range(r.mm, addr, size, remap_pfn, &r);
if (unlikely(err)) {
zap_vma_ptes(vma, addr, (r.pfn - pfn) << PAGE_SHIFT);
return err;
}
return 0;
}
