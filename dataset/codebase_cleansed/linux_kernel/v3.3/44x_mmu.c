static void __cpuinit ppc44x_update_tlb_hwater(void)
{
extern unsigned int tlb_44x_patch_hwater_D[];
extern unsigned int tlb_44x_patch_hwater_I[];
tlb_44x_patch_hwater_D[0] = (tlb_44x_patch_hwater_D[0] & 0xffff0000) |
tlb_44x_hwater;
flush_icache_range((unsigned long)&tlb_44x_patch_hwater_D[0],
(unsigned long)&tlb_44x_patch_hwater_D[1]);
tlb_44x_patch_hwater_I[0] = (tlb_44x_patch_hwater_I[0] & 0xffff0000) |
tlb_44x_hwater;
flush_icache_range((unsigned long)&tlb_44x_patch_hwater_I[0],
(unsigned long)&tlb_44x_patch_hwater_I[1]);
}
static void __init ppc44x_pin_tlb(unsigned int virt, unsigned int phys)
{
unsigned int entry = tlb_44x_hwater--;
ppc44x_update_tlb_hwater();
mtspr(SPRN_MMUCR, 0);
__asm__ __volatile__(
"tlbwe %2,%3,%4\n"
"tlbwe %1,%3,%5\n"
"tlbwe %0,%3,%6\n"
:
: "r" (PPC44x_TLB_SW | PPC44x_TLB_SR | PPC44x_TLB_SX | PPC44x_TLB_G),
"r" (phys),
"r" (virt | PPC44x_TLB_VALID | PPC44x_TLB_256M),
"r" (entry),
"i" (PPC44x_TLB_PAGEID),
"i" (PPC44x_TLB_XLAT),
"i" (PPC44x_TLB_ATTRIB));
}
static int __init ppc47x_find_free_bolted(void)
{
unsigned int mmube0 = mfspr(SPRN_MMUBE0);
unsigned int mmube1 = mfspr(SPRN_MMUBE1);
if (!(mmube0 & MMUBE0_VBE0))
return 0;
if (!(mmube0 & MMUBE0_VBE1))
return 1;
if (!(mmube0 & MMUBE0_VBE2))
return 2;
if (!(mmube1 & MMUBE1_VBE3))
return 3;
if (!(mmube1 & MMUBE1_VBE4))
return 4;
if (!(mmube1 & MMUBE1_VBE5))
return 5;
return -1;
}
static void __init ppc47x_update_boltmap(void)
{
unsigned int mmube0 = mfspr(SPRN_MMUBE0);
unsigned int mmube1 = mfspr(SPRN_MMUBE1);
if (mmube0 & MMUBE0_VBE0)
__set_bit((mmube0 >> MMUBE0_IBE0_SHIFT) & 0xff,
tlb_47x_boltmap);
if (mmube0 & MMUBE0_VBE1)
__set_bit((mmube0 >> MMUBE0_IBE1_SHIFT) & 0xff,
tlb_47x_boltmap);
if (mmube0 & MMUBE0_VBE2)
__set_bit((mmube0 >> MMUBE0_IBE2_SHIFT) & 0xff,
tlb_47x_boltmap);
if (mmube1 & MMUBE1_VBE3)
__set_bit((mmube1 >> MMUBE1_IBE3_SHIFT) & 0xff,
tlb_47x_boltmap);
if (mmube1 & MMUBE1_VBE4)
__set_bit((mmube1 >> MMUBE1_IBE4_SHIFT) & 0xff,
tlb_47x_boltmap);
if (mmube1 & MMUBE1_VBE5)
__set_bit((mmube1 >> MMUBE1_IBE5_SHIFT) & 0xff,
tlb_47x_boltmap);
}
static void __cpuinit ppc47x_pin_tlb(unsigned int virt, unsigned int phys)
{
unsigned int rA;
int bolted;
rA = 0x88000000;
bolted = ppc47x_find_free_bolted();
BUG_ON(bolted < 0);
rA |= bolted << 24;
pr_debug("256M TLB entry for 0x%08x->0x%08x in bolt slot %d\n",
virt, phys, bolted);
mtspr(SPRN_MMUCR, 0);
__asm__ __volatile__(
"tlbwe %2,%3,0\n"
"tlbwe %1,%3,1\n"
"tlbwe %0,%3,2\n"
:
: "r" (PPC47x_TLB2_SW | PPC47x_TLB2_SR |
PPC47x_TLB2_SX
#ifdef CONFIG_SMP
| PPC47x_TLB2_M
#endif
),
"r" (phys),
"r" (virt | PPC47x_TLB0_VALID | PPC47x_TLB0_256M),
"r" (rA));
}
void __init MMU_init_hw(void)
{
ppc44x_update_tlb_hwater();
flush_instruction_cache();
}
unsigned long __init mmu_mapin_ram(unsigned long top)
{
unsigned long addr;
unsigned long memstart = memstart_addr & ~(PPC_PIN_SIZE - 1);
for (addr = memstart + PPC_PIN_SIZE; addr < lowmem_end_addr;
addr += PPC_PIN_SIZE) {
if (mmu_has_feature(MMU_FTR_TYPE_47x))
ppc47x_pin_tlb(addr + PAGE_OFFSET, addr);
else
ppc44x_pin_tlb(addr + PAGE_OFFSET, addr);
}
if (mmu_has_feature(MMU_FTR_TYPE_47x)) {
ppc47x_update_boltmap();
#ifdef DEBUG
{
int i;
printk(KERN_DEBUG "bolted entries: ");
for (i = 0; i < 255; i++) {
if (test_bit(i, tlb_47x_boltmap))
printk("%d ", i);
}
printk("\n");
}
#endif
}
return total_lowmem;
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
u64 size;
#ifndef CONFIG_NONSTATIC_KERNEL
BUG_ON(first_memblock_base != 0);
#endif
size = (min_t(u64, first_memblock_size, PPC_PIN_SIZE));
memblock_set_current_limit(first_memblock_base + size);
}
void __cpuinit mmu_init_secondary(int cpu)
{
unsigned long addr;
unsigned long memstart = memstart_addr & ~(PPC_PIN_SIZE - 1);
for (addr = memstart + PPC_PIN_SIZE; addr < lowmem_end_addr;
addr += PPC_PIN_SIZE) {
if (mmu_has_feature(MMU_FTR_TYPE_47x))
ppc47x_pin_tlb(addr + PAGE_OFFSET, addr);
else
ppc44x_pin_tlb(addr + PAGE_OFFSET, addr);
}
}
