void set_pte_vaddr(unsigned long vaddr, pte_t pteval)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pgd = swapper_pg_dir + pgd_index(vaddr);
if (pgd_none(*pgd)) {
BUG();
return;
}
pud = pud_offset(pgd, vaddr);
if (pud_none(*pud)) {
BUG();
return;
}
pmd = pmd_offset(pud, vaddr);
if (pmd_none(*pmd)) {
BUG();
return;
}
pte = pte_offset_kernel(pmd, vaddr);
if (pte_val(pteval))
set_pte_at(&init_mm, vaddr, pte, pteval);
else
pte_clear(&init_mm, vaddr, pte);
__flush_tlb_one(vaddr);
}
void set_pmd_pfn(unsigned long vaddr, unsigned long pfn, pgprot_t flags)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
if (vaddr & (PMD_SIZE-1)) {
printk(KERN_WARNING "set_pmd_pfn: vaddr misaligned\n");
return;
}
if (pfn & (PTRS_PER_PTE-1)) {
printk(KERN_WARNING "set_pmd_pfn: pfn misaligned\n");
return;
}
pgd = swapper_pg_dir + pgd_index(vaddr);
if (pgd_none(*pgd)) {
printk(KERN_WARNING "set_pmd_pfn: pgd_none\n");
return;
}
pud = pud_offset(pgd, vaddr);
pmd = pmd_offset(pud, vaddr);
set_pmd(pmd, pfn_pmd(pfn, flags));
__flush_tlb_one(vaddr);
}
static int __init parse_vmalloc(char *arg)
{
if (!arg)
return -EINVAL;
__VMALLOC_RESERVE = memparse(arg, &arg) + VMALLOC_OFFSET;
return 0;
}
static int __init parse_reservetop(char *arg)
{
unsigned long address;
if (!arg)
return -EINVAL;
address = memparse(arg, &arg);
reserve_top_address(address);
fixup_early_ioremap();
return 0;
}
