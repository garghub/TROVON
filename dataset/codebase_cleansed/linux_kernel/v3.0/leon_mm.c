unsigned long srmmu_swprobe(unsigned long vaddr, unsigned long *paddr)
{
unsigned int ctxtbl;
unsigned int pgd, pmd, ped;
unsigned int ptr;
unsigned int lvl, pte, paddrbase;
unsigned int ctx;
unsigned int paddr_calc;
paddrbase = 0;
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: trace on\n");
ctxtbl = srmmu_get_ctable_ptr();
if (!(ctxtbl)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: srmmu_get_ctable_ptr returned 0=>0\n");
return 0;
}
if (!_pfn_valid(PFN(ctxtbl))) {
if (srmmu_swprobe_trace)
printk(KERN_INFO
"swprobe: !_pfn_valid(%x)=>0\n",
PFN(ctxtbl));
return 0;
}
ctx = srmmu_get_context();
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: --- ctx (%x) ---\n", ctx);
pgd = LEON_BYPASS_LOAD_PA(ctxtbl + (ctx * 4));
if (((pgd & SRMMU_ET_MASK) == SRMMU_ET_PTE)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: pgd is entry level 3\n");
lvl = 3;
pte = pgd;
paddrbase = pgd & _SRMMU_PTE_PMASK_LEON;
goto ready;
}
if (((pgd & SRMMU_ET_MASK) != SRMMU_ET_PTD)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: pgd is invalid => 0\n");
return 0;
}
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: --- pgd (%x) ---\n", pgd);
ptr = (pgd & SRMMU_PTD_PMASK) << 4;
ptr += ((((vaddr) >> LEON_PGD_SH) & LEON_PGD_M) * 4);
if (!_pfn_valid(PFN(ptr)))
return 0;
pmd = LEON_BYPASS_LOAD_PA(ptr);
if (((pmd & SRMMU_ET_MASK) == SRMMU_ET_PTE)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: pmd is entry level 2\n");
lvl = 2;
pte = pmd;
paddrbase = pmd & _SRMMU_PTE_PMASK_LEON;
goto ready;
}
if (((pmd & SRMMU_ET_MASK) != SRMMU_ET_PTD)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: pmd is invalid => 0\n");
return 0;
}
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: --- pmd (%x) ---\n", pmd);
ptr = (pmd & SRMMU_PTD_PMASK) << 4;
ptr += (((vaddr >> LEON_PMD_SH) & LEON_PMD_M) * 4);
if (!_pfn_valid(PFN(ptr))) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: !_pfn_valid(%x)=>0\n",
PFN(ptr));
return 0;
}
ped = LEON_BYPASS_LOAD_PA(ptr);
if (((ped & SRMMU_ET_MASK) == SRMMU_ET_PTE)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: ped is entry level 1\n");
lvl = 1;
pte = ped;
paddrbase = ped & _SRMMU_PTE_PMASK_LEON;
goto ready;
}
if (((ped & SRMMU_ET_MASK) != SRMMU_ET_PTD)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: ped is invalid => 0\n");
return 0;
}
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: --- ped (%x) ---\n", ped);
ptr = (ped & SRMMU_PTD_PMASK) << 4;
ptr += (((vaddr >> LEON_PTE_SH) & LEON_PTE_M) * 4);
if (!_pfn_valid(PFN(ptr)))
return 0;
ptr = LEON_BYPASS_LOAD_PA(ptr);
if (((ptr & SRMMU_ET_MASK) == SRMMU_ET_PTE)) {
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: ptr is entry level 0\n");
lvl = 0;
pte = ptr;
paddrbase = ptr & _SRMMU_PTE_PMASK_LEON;
goto ready;
}
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: ptr is invalid => 0\n");
return 0;
ready:
switch (lvl) {
case 0:
paddr_calc =
(vaddr & ~(-1 << LEON_PTE_SH)) | ((pte & ~0xff) << 4);
break;
case 1:
paddr_calc =
(vaddr & ~(-1 << LEON_PMD_SH)) | ((pte & ~0xff) << 4);
break;
case 2:
paddr_calc =
(vaddr & ~(-1 << LEON_PGD_SH)) | ((pte & ~0xff) << 4);
break;
default:
case 3:
paddr_calc = vaddr;
break;
}
if (srmmu_swprobe_trace)
printk(KERN_INFO "swprobe: padde %x\n", paddr_calc);
if (paddr)
*paddr = paddr_calc;
return paddrbase;
}
void leon_flush_icache_all(void)
{
__asm__ __volatile__(" flush ");
}
void leon_flush_dcache_all(void)
{
__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
"i"(ASI_LEON_DFLUSH) : "memory");
}
void leon_flush_pcache_all(struct vm_area_struct *vma, unsigned long page)
{
if (vma->vm_flags & VM_EXEC)
leon_flush_icache_all();
leon_flush_dcache_all();
}
void leon_flush_cache_all(void)
{
__asm__ __volatile__(" flush ");
__asm__ __volatile__("sta %%g0, [%%g0] %0\n\t" : :
"i"(ASI_LEON_DFLUSH) : "memory");
}
void leon_flush_tlb_all(void)
{
leon_flush_cache_all();
__asm__ __volatile__("sta %%g0, [%0] %1\n\t" : : "r"(0x400),
"i"(ASI_LEON_MMUFLUSH) : "memory");
}
void leon3_getCacheRegs(struct leon3_cacheregs *regs)
{
unsigned long ccr, iccr, dccr;
if (!regs)
return;
__asm__ __volatile__("lda [%%g0] %3, %0\n\t"
"mov 0x08, %%g1\n\t"
"lda [%%g1] %3, %1\n\t"
"mov 0x0c, %%g1\n\t"
"lda [%%g1] %3, %2\n\t"
: "=r"(ccr), "=r"(iccr), "=r"(dccr)
: "i"(ASI_LEON_CACHEREGS)
: "g1"
);
regs->ccr = ccr;
regs->iccr = iccr;
regs->dccr = dccr;
}
int __init leon_flush_needed(void)
{
int flush_needed = -1;
unsigned int ssize, sets;
char *setStr[4] =
{ "direct mapped", "2-way associative", "3-way associative",
"4-way associative"
};
struct leon3_cacheregs cregs;
leon3_getCacheRegs(&cregs);
sets = (cregs.dccr & LEON3_XCCR_SETS_MASK) >> 24;
ssize = 1 << ((cregs.dccr & LEON3_XCCR_SSIZE_MASK) >> 20);
printk(KERN_INFO "CACHE: %s cache, set size %dk\n",
sets > 3 ? "unknown" : setStr[sets], ssize);
if ((ssize <= (PAGE_SIZE / 1024)) && (sets == 0)) {
flush_needed = 0;
printk(KERN_INFO "CACHE: not flushing on every context switch\n");
}
return flush_needed;
}
void leon_switch_mm(void)
{
flush_tlb_mm((void *)0);
if (leon_flush_during_switch)
leon_flush_cache_all();
}
