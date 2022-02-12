static void dump_flag_info(struct pg_state *st, const struct flag_info
*flag, u64 pte, int num)
{
unsigned int i;
for (i = 0; i < num; i++, flag++) {
const char *s = NULL;
u64 val;
if (flag->mask == 0)
continue;
if (flag->is_val) {
val = pte & flag->val;
if (flag->shift)
val = val >> flag->shift;
seq_printf(st->seq, " %s:%llx", flag->set, val);
} else {
if ((pte & flag->mask) == flag->val)
s = flag->set;
else
s = flag->clear;
if (s)
seq_printf(st->seq, " %s", s);
}
st->current_flags &= ~flag->mask;
}
if (st->current_flags != 0)
seq_printf(st->seq, " unknown flags:%llx", st->current_flags);
}
static void dump_addr(struct pg_state *st, unsigned long addr)
{
static const char units[] = "KMGTPE";
const char *unit = units;
unsigned long delta;
seq_printf(st->seq, "0x%016lx-0x%016lx ", st->start_address, addr-1);
delta = (addr - st->start_address) >> 10;
while (!(delta & 1023) && unit[1]) {
delta >>= 10;
unit++;
}
seq_printf(st->seq, "%9lu%c", delta, *unit);
}
static void note_page(struct pg_state *st, unsigned long addr,
unsigned int level, u64 val)
{
u64 flag = val & pg_level[level].mask;
if (!st->level) {
st->level = level;
st->current_flags = flag;
st->start_address = addr;
seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
} else if (flag != st->current_flags || level != st->level ||
addr >= st->marker[1].start_address) {
if (st->current_flags) {
dump_addr(st, addr);
if (pg_level[st->level].flag)
dump_flag_info(st, pg_level[st->level].flag,
st->current_flags,
pg_level[st->level].num);
seq_puts(st->seq, "\n");
}
while (addr >= st->marker[1].start_address) {
st->marker++;
seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
}
st->start_address = addr;
st->current_flags = flag;
st->level = level;
}
}
static void walk_pte(struct pg_state *st, pmd_t *pmd, unsigned long start)
{
pte_t *pte = pte_offset_kernel(pmd, 0);
unsigned long addr;
unsigned int i;
for (i = 0; i < PTRS_PER_PTE; i++, pte++) {
addr = start + i * PAGE_SIZE;
note_page(st, addr, 4, pte_val(*pte));
}
}
static void walk_pmd(struct pg_state *st, pud_t *pud, unsigned long start)
{
pmd_t *pmd = pmd_offset(pud, 0);
unsigned long addr;
unsigned int i;
for (i = 0; i < PTRS_PER_PMD; i++, pmd++) {
addr = start + i * PMD_SIZE;
if (!pmd_none(*pmd))
walk_pte(st, pmd, addr);
else
note_page(st, addr, 3, pmd_val(*pmd));
}
}
static void walk_pud(struct pg_state *st, pgd_t *pgd, unsigned long start)
{
pud_t *pud = pud_offset(pgd, 0);
unsigned long addr;
unsigned int i;
for (i = 0; i < PTRS_PER_PUD; i++, pud++) {
addr = start + i * PUD_SIZE;
if (!pud_none(*pud))
walk_pmd(st, pud, addr);
else
note_page(st, addr, 2, pud_val(*pud));
}
}
static void walk_pagetables(struct pg_state *st)
{
pgd_t *pgd = pgd_offset_k(0UL);
unsigned int i;
unsigned long addr;
for (i = 0; i < PTRS_PER_PGD; i++, pgd++) {
addr = KERN_VIRT_START + i * PGDIR_SIZE;
if (!pgd_none(*pgd))
walk_pud(st, pgd, addr);
else
note_page(st, addr, 1, pgd_val(*pgd));
}
}
static void populate_markers(void)
{
address_markers[0].start_address = PAGE_OFFSET;
address_markers[1].start_address = VMALLOC_START;
address_markers[2].start_address = VMALLOC_END;
address_markers[3].start_address = ISA_IO_BASE;
address_markers[4].start_address = ISA_IO_END;
address_markers[5].start_address = PHB_IO_BASE;
address_markers[6].start_address = PHB_IO_END;
address_markers[7].start_address = IOREMAP_BASE;
address_markers[8].start_address = IOREMAP_END;
#ifdef CONFIG_PPC_STD_MMU_64
address_markers[9].start_address = H_VMEMMAP_BASE;
#else
address_markers[9].start_address = VMEMMAP_BASE;
#endif
}
static int ptdump_show(struct seq_file *m, void *v)
{
struct pg_state st = {
.seq = m,
.start_address = KERN_VIRT_START,
.marker = address_markers,
};
walk_pagetables(&st);
note_page(&st, 0, 0, 0);
return 0;
}
static int ptdump_open(struct inode *inode, struct file *file)
{
return single_open(file, ptdump_show, NULL);
}
static void build_pgtable_complete_mask(void)
{
unsigned int i, j;
for (i = 0; i < ARRAY_SIZE(pg_level); i++)
if (pg_level[i].flag)
for (j = 0; j < pg_level[i].num; j++)
pg_level[i].mask |= pg_level[i].flag[j].mask;
}
static int ptdump_init(void)
{
struct dentry *debugfs_file;
populate_markers();
build_pgtable_complete_mask();
debugfs_file = debugfs_create_file("kernel_pagetables", 0400, NULL,
NULL, &ptdump_fops);
return debugfs_file ? 0 : -ENOMEM;
}
