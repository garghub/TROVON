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
int pgd;
int n_pgds;
if (!efi_enabled(EFI_OLD_MEMMAP))
return;
early_code_mapping_set_exec(1);
local_irq_save(efi_flags);
n_pgds = DIV_ROUND_UP((max_pfn << PAGE_SHIFT), PGDIR_SIZE);
save_pgd = kmalloc(n_pgds * sizeof(pgd_t), GFP_KERNEL);
for (pgd = 0; pgd < n_pgds; pgd++) {
save_pgd[pgd] = *pgd_offset_k(pgd * PGDIR_SIZE);
vaddress = (unsigned long)__va(pgd * PGDIR_SIZE);
set_pgd(pgd_offset_k(pgd * PGDIR_SIZE), *pgd_offset_k(vaddress));
}
__flush_tlb_all();
}
void __init efi_call_phys_epilog(void)
{
int pgd;
int n_pgds = DIV_ROUND_UP((max_pfn << PAGE_SHIFT) , PGDIR_SIZE);
if (!efi_enabled(EFI_OLD_MEMMAP))
return;
for (pgd = 0; pgd < n_pgds; pgd++)
set_pgd(pgd_offset_k(pgd * PGDIR_SIZE), save_pgd[pgd]);
kfree(save_pgd);
__flush_tlb_all();
local_irq_restore(efi_flags);
early_code_mapping_set_exec(0);
}
void efi_sync_low_kernel_mappings(void)
{
unsigned num_pgds;
pgd_t *pgd = (pgd_t *)__va(real_mode_header->trampoline_pgd);
if (efi_enabled(EFI_OLD_MEMMAP))
return;
num_pgds = pgd_index(MODULES_END - 1) - pgd_index(PAGE_OFFSET);
memcpy(pgd + pgd_index(PAGE_OFFSET),
init_mm.pgd + pgd_index(PAGE_OFFSET),
sizeof(pgd_t) * num_pgds);
}
void efi_setup_page_tables(void)
{
efi_scratch.efi_pgt = (pgd_t *)(unsigned long)real_mode_header->trampoline_pgd;
if (!efi_enabled(EFI_OLD_MEMMAP))
efi_scratch.use_pgd = true;
}
static void __init __map_region(efi_memory_desc_t *md, u64 va)
{
pgd_t *pgd = (pgd_t *)__va(real_mode_header->trampoline_pgd);
unsigned long pf = 0;
if (!(md->attribute & EFI_MEMORY_WB))
pf |= _PAGE_PCD;
if (kernel_map_pages_in_pgd(pgd, md->phys_addr, va, md->num_pages, pf))
pr_warn("Error mapping PA 0x%llx -> VA 0x%llx!\n",
md->phys_addr, va);
}
void __init efi_map_region(efi_memory_desc_t *md)
{
unsigned long size = md->num_pages << PAGE_SHIFT;
u64 pa = md->phys_addr;
if (efi_enabled(EFI_OLD_MEMMAP))
return old_map_region(md);
__map_region(md, md->phys_addr);
efi_va -= size;
if (!(pa & (PMD_SIZE - 1))) {
efi_va &= PMD_MASK;
} else {
u64 pa_offset = pa & (PMD_SIZE - 1);
u64 prev_va = efi_va;
efi_va = (efi_va & PMD_MASK) + pa_offset;
if (efi_va > prev_va)
efi_va -= PMD_SIZE;
}
if (efi_va < EFI_VA_END) {
pr_warn(FW_WARN "VA address range overflow!\n");
return;
}
__map_region(md, efi_va);
md->virt_addr = efi_va;
}
void __init efi_map_region_fixed(efi_memory_desc_t *md)
{
__map_region(md, md->virt_addr);
}
void __iomem *__init efi_ioremap(unsigned long phys_addr, unsigned long size,
u32 type, u64 attribute)
{
unsigned long last_map_pfn;
if (type == EFI_MEMORY_MAPPED_IO)
return ioremap(phys_addr, size);
last_map_pfn = init_memory_mapping(phys_addr, phys_addr + size);
if ((last_map_pfn << PAGE_SHIFT) < phys_addr + size) {
unsigned long top = last_map_pfn << PAGE_SHIFT;
efi_ioremap(top, size - (top - phys_addr), type, attribute);
}
if (!(attribute & EFI_MEMORY_WB))
efi_memory_uc((u64)(unsigned long)__va(phys_addr), size);
return (void __iomem *)__va(phys_addr);
}
void __init parse_efi_setup(u64 phys_addr, u32 data_len)
{
efi_setup = phys_addr + sizeof(struct setup_data);
}
void __init efi_runtime_mkexec(void)
{
if (!efi_enabled(EFI_OLD_MEMMAP))
return;
if (__supported_pte_mask & _PAGE_NX)
runtime_code_page_mkexec();
}
