static void set_idt(void *newidt, __u16 limit)
{
struct desc_ptr curidt;
curidt.size = limit;
curidt.address = (unsigned long)newidt;
load_idt(&curidt);
}
static void set_gdt(void *newgdt, __u16 limit)
{
struct desc_ptr curgdt;
curgdt.size = limit;
curgdt.address = (unsigned long)newgdt;
load_gdt(&curgdt);
}
static void load_segments(void)
{
#define __STR(X) #X
#define STR(X) __STR(X)
__asm__ __volatile__ (
"\tljmp $"STR(__KERNEL_CS)",$1f\n"
"\t1:\n"
"\tmovl $"STR(__KERNEL_DS)",%%eax\n"
"\tmovl %%eax,%%ds\n"
"\tmovl %%eax,%%es\n"
"\tmovl %%eax,%%fs\n"
"\tmovl %%eax,%%gs\n"
"\tmovl %%eax,%%ss\n"
: : : "eax", "memory");
#undef STR
#undef __STR
}
static void machine_kexec_free_page_tables(struct kimage *image)
{
free_page((unsigned long)image->arch.pgd);
#ifdef CONFIG_X86_PAE
free_page((unsigned long)image->arch.pmd0);
free_page((unsigned long)image->arch.pmd1);
#endif
free_page((unsigned long)image->arch.pte0);
free_page((unsigned long)image->arch.pte1);
}
static int machine_kexec_alloc_page_tables(struct kimage *image)
{
image->arch.pgd = (pgd_t *)get_zeroed_page(GFP_KERNEL);
#ifdef CONFIG_X86_PAE
image->arch.pmd0 = (pmd_t *)get_zeroed_page(GFP_KERNEL);
image->arch.pmd1 = (pmd_t *)get_zeroed_page(GFP_KERNEL);
#endif
image->arch.pte0 = (pte_t *)get_zeroed_page(GFP_KERNEL);
image->arch.pte1 = (pte_t *)get_zeroed_page(GFP_KERNEL);
if (!image->arch.pgd ||
#ifdef CONFIG_X86_PAE
!image->arch.pmd0 || !image->arch.pmd1 ||
#endif
!image->arch.pte0 || !image->arch.pte1) {
machine_kexec_free_page_tables(image);
return -ENOMEM;
}
return 0;
}
static void machine_kexec_page_table_set_one(
pgd_t *pgd, pmd_t *pmd, pte_t *pte,
unsigned long vaddr, unsigned long paddr)
{
pud_t *pud;
pgd += pgd_index(vaddr);
#ifdef CONFIG_X86_PAE
if (!(pgd_val(*pgd) & _PAGE_PRESENT))
set_pgd(pgd, __pgd(__pa(pmd) | _PAGE_PRESENT));
#endif
pud = pud_offset(pgd, vaddr);
pmd = pmd_offset(pud, vaddr);
if (!(pmd_val(*pmd) & _PAGE_PRESENT))
set_pmd(pmd, __pmd(__pa(pte) | _PAGE_TABLE));
pte = pte_offset_kernel(pmd, vaddr);
set_pte(pte, pfn_pte(paddr >> PAGE_SHIFT, PAGE_KERNEL_EXEC));
}
static void machine_kexec_prepare_page_tables(struct kimage *image)
{
void *control_page;
pmd_t *pmd = NULL;
control_page = page_address(image->control_code_page);
#ifdef CONFIG_X86_PAE
pmd = image->arch.pmd0;
#endif
machine_kexec_page_table_set_one(
image->arch.pgd, pmd, image->arch.pte0,
(unsigned long)control_page, __pa(control_page));
#ifdef CONFIG_X86_PAE
pmd = image->arch.pmd1;
#endif
machine_kexec_page_table_set_one(
image->arch.pgd, pmd, image->arch.pte1,
__pa(control_page), __pa(control_page));
}
int machine_kexec_prepare(struct kimage *image)
{
int error;
set_pages_x(image->control_code_page, 1);
error = machine_kexec_alloc_page_tables(image);
if (error)
return error;
machine_kexec_prepare_page_tables(image);
return 0;
}
void machine_kexec_cleanup(struct kimage *image)
{
set_pages_nx(image->control_code_page, 1);
machine_kexec_free_page_tables(image);
}
void machine_kexec(struct kimage *image)
{
unsigned long page_list[PAGES_NR];
void *control_page;
int save_ftrace_enabled;
asmlinkage unsigned long
(*relocate_kernel_ptr)(unsigned long indirection_page,
unsigned long control_page,
unsigned long start_address,
unsigned int has_pae,
unsigned int preserve_context);
#ifdef CONFIG_KEXEC_JUMP
if (image->preserve_context)
save_processor_state();
#endif
save_ftrace_enabled = __ftrace_enabled_save();
local_irq_disable();
hw_breakpoint_disable();
if (image->preserve_context) {
#ifdef CONFIG_X86_IO_APIC
disable_IO_APIC();
#endif
}
control_page = page_address(image->control_code_page);
memcpy(control_page, relocate_kernel, KEXEC_CONTROL_CODE_MAX_SIZE);
relocate_kernel_ptr = control_page;
page_list[PA_CONTROL_PAGE] = __pa(control_page);
page_list[VA_CONTROL_PAGE] = (unsigned long)control_page;
page_list[PA_PGD] = __pa(image->arch.pgd);
if (image->type == KEXEC_TYPE_DEFAULT)
page_list[PA_SWAP_PAGE] = (page_to_pfn(image->swap_page)
<< PAGE_SHIFT);
load_segments();
set_gdt(phys_to_virt(0), 0);
set_idt(phys_to_virt(0), 0);
image->start = relocate_kernel_ptr((unsigned long)image->head,
(unsigned long)page_list,
image->start, cpu_has_pae,
image->preserve_context);
#ifdef CONFIG_KEXEC_JUMP
if (image->preserve_context)
restore_processor_state();
#endif
__ftrace_enabled_restore(save_ftrace_enabled);
}
void arch_crash_save_vmcoreinfo(void)
{
#ifdef CONFIG_NUMA
VMCOREINFO_SYMBOL(node_data);
VMCOREINFO_LENGTH(node_data, MAX_NUMNODES);
#endif
#ifdef CONFIG_X86_PAE
VMCOREINFO_CONFIG(X86_PAE);
#endif
}
