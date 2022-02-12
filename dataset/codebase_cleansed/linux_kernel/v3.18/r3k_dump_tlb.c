static void dump_tlb(int first, int last)
{
int i;
unsigned int asid;
unsigned long entryhi, entrylo0;
asid = read_c0_entryhi() & 0xfc0;
for (i = first; i <= last; i++) {
write_c0_index(i<<8);
__asm__ __volatile__(
".set\tnoreorder\n\t"
"tlbr\n\t"
"nop\n\t"
".set\treorder");
entryhi = read_c0_entryhi();
entrylo0 = read_c0_entrylo0();
if ((entryhi & 0xfffff000) != 0x80000000
&& (entryhi & 0xfc0) == asid) {
printk("Index: %2d ", i);
printk("va=%08lx asid=%08lx"
" [pa=%06lx n=%d d=%d v=%d g=%d]",
(entryhi & 0xfffff000),
entryhi & 0xfc0,
entrylo0 & PAGE_MASK,
(entrylo0 & (1 << 11)) ? 1 : 0,
(entrylo0 & (1 << 10)) ? 1 : 0,
(entrylo0 & (1 << 9)) ? 1 : 0,
(entrylo0 & (1 << 8)) ? 1 : 0);
}
}
printk("\n");
write_c0_entryhi(asid);
}
void dump_tlb_all(void)
{
dump_tlb(0, current_cpu_data.tlbsize - 1);
}
