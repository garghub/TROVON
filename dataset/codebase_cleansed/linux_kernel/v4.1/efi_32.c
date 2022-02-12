void efi_sync_low_kernel_mappings(void) {}
void __init efi_dump_pagetable(void) {}
int __init efi_setup_page_tables(unsigned long pa_memmap, unsigned num_pages)
{
return 0;
}
void __init efi_cleanup_page_tables(unsigned long pa_memmap, unsigned num_pages)
{
}
void __init efi_map_region(efi_memory_desc_t *md)
{
old_map_region(md);
}
void __init efi_map_region_fixed(efi_memory_desc_t *md) {}
void __init parse_efi_setup(u64 phys_addr, u32 data_len) {}
pgd_t * __init efi_call_phys_prolog(void)
{
struct desc_ptr gdt_descr;
pgd_t *save_pgd;
save_pgd = swapper_pg_dir;
load_cr3(initial_page_table);
__flush_tlb_all();
gdt_descr.address = __pa(get_cpu_gdt_table(0));
gdt_descr.size = GDT_SIZE - 1;
load_gdt(&gdt_descr);
return save_pgd;
}
void __init efi_call_phys_epilog(pgd_t *save_pgd)
{
struct desc_ptr gdt_descr;
gdt_descr.address = (unsigned long)get_cpu_gdt_table(0);
gdt_descr.size = GDT_SIZE - 1;
load_gdt(&gdt_descr);
load_cr3(save_pgd);
__flush_tlb_all();
}
void __init efi_runtime_mkexec(void)
{
if (__supported_pte_mask & _PAGE_NX)
runtime_code_page_mkexec();
}
