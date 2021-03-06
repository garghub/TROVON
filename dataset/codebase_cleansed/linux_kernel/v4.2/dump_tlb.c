static inline const char *msk2str(unsigned int mask)
{
switch (mask) {
case PM_4K: return "4kb";
case PM_16K: return "16kb";
case PM_64K: return "64kb";
case PM_256K: return "256kb";
#ifdef CONFIG_CPU_CAVIUM_OCTEON
case PM_8K: return "8kb";
case PM_32K: return "32kb";
case PM_128K: return "128kb";
case PM_512K: return "512kb";
case PM_2M: return "2Mb";
case PM_8M: return "8Mb";
case PM_32M: return "32Mb";
#endif
#ifndef CONFIG_CPU_VR41XX
case PM_1M: return "1Mb";
case PM_4M: return "4Mb";
case PM_16M: return "16Mb";
case PM_64M: return "64Mb";
case PM_256M: return "256Mb";
case PM_1G: return "1Gb";
#endif
}
return "";
}
static void dump_tlb(int first, int last)
{
unsigned long s_entryhi, entryhi, asid;
unsigned long long entrylo0, entrylo1, pa;
unsigned int s_index, s_pagemask, pagemask, c0, c1, i;
#ifdef CONFIG_32BIT
bool xpa = cpu_has_xpa && (read_c0_pagegrain() & PG_ELPA);
int pwidth = xpa ? 11 : 8;
int vwidth = 8;
#else
bool xpa = false;
int pwidth = 11;
int vwidth = 11;
#endif
s_pagemask = read_c0_pagemask();
s_entryhi = read_c0_entryhi();
s_index = read_c0_index();
asid = s_entryhi & 0xff;
for (i = first; i <= last; i++) {
write_c0_index(i);
mtc0_tlbr_hazard();
tlb_read();
tlb_read_hazard();
pagemask = read_c0_pagemask();
entryhi = read_c0_entryhi();
entrylo0 = read_c0_entrylo0();
entrylo1 = read_c0_entrylo1();
if (cpu_has_tlbinv && entryhi & MIPS_ENTRYHI_EHINV)
continue;
if ((entryhi & ~0x1ffffUL) == CKSEG0)
continue;
if (!((entrylo0 | entrylo1) & MIPS_ENTRYLO_G) &&
(entryhi & 0xff) != asid)
continue;
printk("Index: %2d pgmask=%s ", i, msk2str(pagemask));
c0 = (entrylo0 & MIPS_ENTRYLO_C) >> MIPS_ENTRYLO_C_SHIFT;
c1 = (entrylo1 & MIPS_ENTRYLO_C) >> MIPS_ENTRYLO_C_SHIFT;
printk("va=%0*lx asid=%02lx\n",
vwidth, (entryhi & ~0x1fffUL),
entryhi & 0xff);
pa = entrylo0 & ~(MIPS_ENTRYLO_RI | MIPS_ENTRYLO_XI);
if (xpa)
pa |= (unsigned long long)readx_c0_entrylo0() << 30;
pa = (pa << 6) & PAGE_MASK;
printk("\t[");
if (cpu_has_rixi)
printk("ri=%d xi=%d ",
(entrylo0 & MIPS_ENTRYLO_RI) ? 1 : 0,
(entrylo0 & MIPS_ENTRYLO_XI) ? 1 : 0);
printk("pa=%0*llx c=%d d=%d v=%d g=%d] [",
pwidth, pa, c0,
(entrylo0 & MIPS_ENTRYLO_D) ? 1 : 0,
(entrylo0 & MIPS_ENTRYLO_V) ? 1 : 0,
(entrylo0 & MIPS_ENTRYLO_G) ? 1 : 0);
pa = entrylo1 & ~(MIPS_ENTRYLO_RI | MIPS_ENTRYLO_XI);
if (xpa)
pa |= (unsigned long long)readx_c0_entrylo1() << 30;
pa = (pa << 6) & PAGE_MASK;
if (cpu_has_rixi)
printk("ri=%d xi=%d ",
(entrylo1 & MIPS_ENTRYLO_RI) ? 1 : 0,
(entrylo1 & MIPS_ENTRYLO_XI) ? 1 : 0);
printk("pa=%0*llx c=%d d=%d v=%d g=%d]\n",
pwidth, pa, c1,
(entrylo1 & MIPS_ENTRYLO_D) ? 1 : 0,
(entrylo1 & MIPS_ENTRYLO_V) ? 1 : 0,
(entrylo1 & MIPS_ENTRYLO_G) ? 1 : 0);
}
printk("\n");
write_c0_entryhi(s_entryhi);
write_c0_index(s_index);
write_c0_pagemask(s_pagemask);
}
void dump_tlb_all(void)
{
dump_tlb(0, current_cpu_data.tlbsize - 1);
}
