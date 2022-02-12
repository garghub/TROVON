void efi_call_phys_prelog(void)
{
struct desc_ptr gdt_descr;
local_irq_save(efi_rt_eflags);
load_cr3(initial_page_table);
__flush_tlb_all();
gdt_descr.address = __pa(get_cpu_gdt_table(0));
gdt_descr.size = GDT_SIZE - 1;
load_gdt(&gdt_descr);
}
void efi_call_phys_epilog(void)
{
struct desc_ptr gdt_descr;
gdt_descr.address = (unsigned long)get_cpu_gdt_table(0);
gdt_descr.size = GDT_SIZE - 1;
load_gdt(&gdt_descr);
load_cr3(swapper_pg_dir);
__flush_tlb_all();
local_irq_restore(efi_rt_eflags);
}
