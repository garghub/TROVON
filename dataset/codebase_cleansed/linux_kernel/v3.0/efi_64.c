static void __init early_code_mapping_set_exec(int executable)
{
efi_memory_desc_t *md;
void *p;
if (!(__supported_pte_mask & _PAGE_NX))
return;
for (p = memmap.map; p < memmap.map_end; p += memmap.desc_size) {
md = p;
if (md->type == EFI_RUNTIME_SERVICES_CODE ||
md->type == EFI_BOOT_SERVICES_CODE)
efi_set_executable(md, executable);
}
}
void __init efi_call_phys_prelog(void)
{
unsigned long vaddress;
early_code_mapping_set_exec(1);
local_irq_save(efi_flags);
vaddress = (unsigned long)__va(0x0UL);
save_pgd = *pgd_offset_k(0x0UL);
set_pgd(pgd_offset_k(0x0UL), *pgd_offset_k(vaddress));
__flush_tlb_all();
}
void __init efi_call_phys_epilog(void)
{
set_pgd(pgd_offset_k(0x0UL), save_pgd);
__flush_tlb_all();
local_irq_restore(efi_flags);
early_code_mapping_set_exec(0);
}
void __iomem *__init efi_ioremap(unsigned long phys_addr, unsigned long size,
u32 type)
{
unsigned long last_map_pfn;
if (type == EFI_MEMORY_MAPPED_IO)
return ioremap(phys_addr, size);
last_map_pfn = init_memory_mapping(phys_addr, phys_addr + size);
if ((last_map_pfn << PAGE_SHIFT) < phys_addr + size) {
unsigned long top = last_map_pfn << PAGE_SHIFT;
efi_ioremap(top, size - (top - phys_addr), type);
}
return (void __iomem *)__va(phys_addr);
}
