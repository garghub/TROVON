static void dump_prot(struct pg_state *st, const struct prot_bits *bits,
size_t num)
{
unsigned i;
for (i = 0; i < num; i++, bits++) {
const char *s;
if ((st->current_prot & bits->mask) == bits->val)
s = bits->set;
else
s = bits->clear;
if (s)
seq_printf(st->seq, " %s", s);
}
}
static void note_page(struct pg_state *st, unsigned long addr, unsigned level,
u64 val)
{
static const char units[] = "KMGTPE";
u64 prot = val & pg_level[level].mask;
if (!st->level) {
st->level = level;
st->current_prot = prot;
st->start_address = addr;
seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
} else if (prot != st->current_prot || level != st->level ||
addr >= st->marker[1].start_address) {
const char *unit = units;
unsigned long delta;
if (st->current_prot) {
seq_printf(st->seq, "0x%016lx-0x%016lx ",
st->start_address, addr);
delta = (addr - st->start_address) >> 10;
while (!(delta & 1023) && unit[1]) {
delta >>= 10;
unit++;
}
seq_printf(st->seq, "%9lu%c", delta, *unit);
if (pg_level[st->level].bits)
dump_prot(st, pg_level[st->level].bits,
pg_level[st->level].num);
seq_puts(st->seq, "\n");
}
if (addr >= st->marker[1].start_address) {
st->marker++;
seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
}
st->start_address = addr;
st->current_prot = prot;
st->level = level;
}
if (addr >= st->marker[1].start_address) {
st->marker++;
seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
}
}
static void walk_pte(struct pg_state *st, pmd_t *pmd, unsigned long start)
{
pte_t *pte = pte_offset_kernel(pmd, 0);
unsigned long addr;
unsigned i;
for (i = 0; i < PTRS_PER_PTE; i++, pte++) {
addr = start + i * PAGE_SIZE;
note_page(st, addr, 4, pte_val(*pte));
}
}
static void walk_pmd(struct pg_state *st, pud_t *pud, unsigned long start)
{
pmd_t *pmd = pmd_offset(pud, 0);
unsigned long addr;
unsigned i;
for (i = 0; i < PTRS_PER_PMD; i++, pmd++) {
addr = start + i * PMD_SIZE;
if (pmd_none(*pmd) || pmd_sect(*pmd)) {
note_page(st, addr, 3, pmd_val(*pmd));
} else {
BUG_ON(pmd_bad(*pmd));
walk_pte(st, pmd, addr);
}
}
}
static void walk_pud(struct pg_state *st, pgd_t *pgd, unsigned long start)
{
pud_t *pud = pud_offset(pgd, 0);
unsigned long addr;
unsigned i;
for (i = 0; i < PTRS_PER_PUD; i++, pud++) {
addr = start + i * PUD_SIZE;
if (pud_none(*pud) || pud_sect(*pud)) {
note_page(st, addr, 2, pud_val(*pud));
} else {
BUG_ON(pud_bad(*pud));
walk_pmd(st, pud, addr);
}
}
}
static void walk_pgd(struct pg_state *st, struct mm_struct *mm, unsigned long start)
{
pgd_t *pgd = pgd_offset(mm, 0UL);
unsigned i;
unsigned long addr;
for (i = 0; i < PTRS_PER_PGD; i++, pgd++) {
addr = start + i * PGDIR_SIZE;
if (pgd_none(*pgd)) {
note_page(st, addr, 1, pgd_val(*pgd));
} else {
BUG_ON(pgd_bad(*pgd));
walk_pud(st, pgd, addr);
}
}
}
static int ptdump_show(struct seq_file *m, void *v)
{
struct pg_state st = {
.seq = m,
.marker = address_markers,
};
walk_pgd(&st, &init_mm, VA_START);
note_page(&st, 0, 0, 0);
return 0;
}
static int ptdump_open(struct inode *inode, struct file *file)
{
return single_open(file, ptdump_show, NULL);
}
static int ptdump_init(void)
{
struct dentry *pe;
unsigned i, j;
for (i = 0; i < ARRAY_SIZE(pg_level); i++)
if (pg_level[i].bits)
for (j = 0; j < pg_level[i].num; j++)
pg_level[i].mask |= pg_level[i].bits[j].mask;
#ifdef CONFIG_SPARSEMEM_VMEMMAP
address_markers[VMEMMAP_START_NR].start_address =
(unsigned long)virt_to_page(PAGE_OFFSET);
address_markers[VMEMMAP_END_NR].start_address =
(unsigned long)virt_to_page(high_memory);
#endif
pe = debugfs_create_file("kernel_page_tables", 0400, NULL, NULL,
&ptdump_fops);
return pe ? 0 : -ENOMEM;
}
