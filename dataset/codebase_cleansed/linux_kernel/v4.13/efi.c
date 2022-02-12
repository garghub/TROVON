static int __init set_permissions(pte_t *ptep, pgtable_t token,
unsigned long addr, void *data)
{
efi_memory_desc_t *md = data;
pte_t pte = *ptep;
if (md->attribute & EFI_MEMORY_RO)
pte = set_pte_bit(pte, __pgprot(L_PTE_RDONLY));
if (md->attribute & EFI_MEMORY_XP)
pte = set_pte_bit(pte, __pgprot(L_PTE_XN));
set_pte_ext(ptep, pte, PTE_EXT_NG);
return 0;
}
int __init efi_set_mapping_permissions(struct mm_struct *mm,
efi_memory_desc_t *md)
{
unsigned long base, size;
base = md->virt_addr;
size = md->num_pages << EFI_PAGE_SHIFT;
if (round_down(base + size, SECTION_SIZE) <
round_up(base, SECTION_SIZE) + SECTION_SIZE)
return apply_to_page_range(mm, base, size, set_permissions, md);
return 0;
}
int __init efi_create_mapping(struct mm_struct *mm, efi_memory_desc_t *md)
{
struct map_desc desc = {
.virtual = md->virt_addr,
.pfn = __phys_to_pfn(md->phys_addr),
.length = md->num_pages * EFI_PAGE_SIZE,
};
if (md->attribute & EFI_MEMORY_WB)
desc.type = MT_MEMORY_RWX;
else if (md->attribute & EFI_MEMORY_WT)
desc.type = MT_MEMORY_RWX_NONCACHED;
else if (md->attribute & EFI_MEMORY_WC)
desc.type = MT_DEVICE_WC;
else
desc.type = MT_DEVICE;
create_mapping_late(mm, &desc, true);
if (md->attribute & (EFI_MEMORY_RO | EFI_MEMORY_XP))
return efi_set_mapping_permissions(mm, md);
return 0;
}
