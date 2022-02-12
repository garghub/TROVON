unsigned long tlbcam_sz(int idx)
{
return tlbcam_addrs[idx].limit - tlbcam_addrs[idx].start + 1;
}
phys_addr_t v_mapped_by_tlbcam(unsigned long va)
{
int b;
for (b = 0; b < tlbcam_index; ++b)
if (va >= tlbcam_addrs[b].start && va < tlbcam_addrs[b].limit)
return tlbcam_addrs[b].phys + (va - tlbcam_addrs[b].start);
return 0;
}
unsigned long p_mapped_by_tlbcam(phys_addr_t pa)
{
int b;
for (b = 0; b < tlbcam_index; ++b)
if (pa >= tlbcam_addrs[b].phys
&& pa < (tlbcam_addrs[b].limit-tlbcam_addrs[b].start)
+tlbcam_addrs[b].phys)
return tlbcam_addrs[b].start+(pa-tlbcam_addrs[b].phys);
return 0;
}
static void settlbcam(int index, unsigned long virt, phys_addr_t phys,
unsigned long size, unsigned long flags, unsigned int pid)
{
unsigned int tsize;
tsize = __ilog2(size) - 10;
#if defined(CONFIG_SMP) || defined(CONFIG_PPC_E500MC)
if ((flags & _PAGE_NO_CACHE) == 0)
flags |= _PAGE_COHERENT;
#endif
TLBCAM[index].MAS0 = MAS0_TLBSEL(1) | MAS0_ESEL(index) | MAS0_NV(index+1);
TLBCAM[index].MAS1 = MAS1_VALID | MAS1_IPROT | MAS1_TSIZE(tsize) | MAS1_TID(pid);
TLBCAM[index].MAS2 = virt & PAGE_MASK;
TLBCAM[index].MAS2 |= (flags & _PAGE_WRITETHRU) ? MAS2_W : 0;
TLBCAM[index].MAS2 |= (flags & _PAGE_NO_CACHE) ? MAS2_I : 0;
TLBCAM[index].MAS2 |= (flags & _PAGE_COHERENT) ? MAS2_M : 0;
TLBCAM[index].MAS2 |= (flags & _PAGE_GUARDED) ? MAS2_G : 0;
TLBCAM[index].MAS2 |= (flags & _PAGE_ENDIAN) ? MAS2_E : 0;
TLBCAM[index].MAS3 = (phys & MAS3_RPN) | MAS3_SX | MAS3_SR;
TLBCAM[index].MAS3 |= ((flags & _PAGE_RW) ? MAS3_SW : 0);
if (mmu_has_feature(MMU_FTR_BIG_PHYS))
TLBCAM[index].MAS7 = (u64)phys >> 32;
if (pte_user(flags)) {
TLBCAM[index].MAS3 |= MAS3_UX | MAS3_UR;
TLBCAM[index].MAS3 |= ((flags & _PAGE_RW) ? MAS3_UW : 0);
}
tlbcam_addrs[index].start = virt;
tlbcam_addrs[index].limit = virt + size - 1;
tlbcam_addrs[index].phys = phys;
loadcam_entry(index);
}
unsigned long calc_cam_sz(unsigned long ram, unsigned long virt,
phys_addr_t phys)
{
unsigned int camsize = __ilog2(ram);
unsigned int align = __ffs(virt | phys);
unsigned long max_cam;
if ((mfspr(SPRN_MMUCFG) & MMUCFG_MAVN) == MMUCFG_MAVN_V1) {
max_cam = ((mfspr(SPRN_TLB1CFG) >> 16) & 0xf) * 2 + 10;
camsize &= ~1U;
align &= ~1U;
} else {
max_cam = __ilog2(mfspr(SPRN_TLB1PS)) + 10;
}
if (camsize > align)
camsize = align;
if (camsize > max_cam)
camsize = max_cam;
return 1UL << camsize;
}
static unsigned long map_mem_in_cams_addr(phys_addr_t phys, unsigned long virt,
unsigned long ram, int max_cam_idx)
{
int i;
unsigned long amount_mapped = 0;
for (i = 0; ram && i < max_cam_idx; i++) {
unsigned long cam_sz;
cam_sz = calc_cam_sz(ram, virt, phys);
settlbcam(i, virt, phys, cam_sz, pgprot_val(PAGE_KERNEL_X), 0);
ram -= cam_sz;
amount_mapped += cam_sz;
virt += cam_sz;
phys += cam_sz;
}
tlbcam_index = i;
#ifdef CONFIG_PPC64
get_paca()->tcd.esel_next = i;
get_paca()->tcd.esel_max = mfspr(SPRN_TLB1CFG) & TLBnCFG_N_ENTRY;
get_paca()->tcd.esel_first = i;
#endif
return amount_mapped;
}
unsigned long map_mem_in_cams(unsigned long ram, int max_cam_idx)
{
unsigned long virt = PAGE_OFFSET;
phys_addr_t phys = memstart_addr;
return map_mem_in_cams_addr(phys, virt, ram, max_cam_idx);
}
unsigned long __init mmu_mapin_ram(unsigned long top)
{
return tlbcam_addrs[tlbcam_index - 1].limit - PAGE_OFFSET + 1;
}
void __init MMU_init_hw(void)
{
flush_instruction_cache();
}
void __init adjust_total_lowmem(void)
{
unsigned long ram;
int i;
ram = min((phys_addr_t)__max_low_memory, (phys_addr_t)total_lowmem);
i = switch_to_as1();
__max_low_memory = map_mem_in_cams(ram, CONFIG_LOWMEM_CAM_NUM);
restore_to_as0(i, 0, 0, 1);
pr_info("Memory CAM mapping: ");
for (i = 0; i < tlbcam_index - 1; i++)
pr_cont("%lu/", tlbcam_sz(i) >> 20);
pr_cont("%lu Mb, residual: %dMb\n", tlbcam_sz(tlbcam_index - 1) >> 20,
(unsigned int)((total_lowmem - __max_low_memory) >> 20));
memblock_set_current_limit(memstart_addr + __max_low_memory);
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
phys_addr_t limit = first_memblock_base + first_memblock_size;
memblock_set_current_limit(min_t(u64, limit, 0x04000000));
}
notrace void __init relocate_init(u64 dt_ptr, phys_addr_t start)
{
unsigned long base = KERNELBASE;
kernstart_addr = start;
if (is_second_reloc) {
virt_phys_offset = PAGE_OFFSET - memstart_addr;
return;
}
start &= ~0x3ffffff;
base &= ~0x3ffffff;
virt_phys_offset = base - start;
early_get_first_memblock_info(__va(dt_ptr), NULL);
if (start != memstart_addr) {
int n;
long offset = start - memstart_addr;
is_second_reloc = 1;
n = switch_to_as1();
if (memstart_addr > start)
map_mem_in_cams(0x4000000, CONFIG_LOWMEM_CAM_NUM);
else
map_mem_in_cams_addr(start, PAGE_OFFSET + offset,
0x4000000, CONFIG_LOWMEM_CAM_NUM);
restore_to_as0(n, offset, __va(dt_ptr), 1);
panic("Relocation error");
}
}
