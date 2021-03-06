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
pt_dump_seq_printf(st->seq, " %s", s);
}
}
static void note_prot_uxn(struct pg_state *st, unsigned long addr)
{
if (!st->check_wx)
return;
if ((st->current_prot & PTE_UXN) == PTE_UXN)
return;
WARN_ONCE(1, "arm64/mm: Found non-UXN mapping at address %p/%pS\n",
(void *)st->start_address, (void *)st->start_address);
st->uxn_pages += (addr - st->start_address) / PAGE_SIZE;
}
static void note_prot_wx(struct pg_state *st, unsigned long addr)
{
if (!st->check_wx)
return;
if ((st->current_prot & PTE_RDONLY) == PTE_RDONLY)
return;
if ((st->current_prot & PTE_PXN) == PTE_PXN)
return;
WARN_ONCE(1, "arm64/mm: Found insecure W+X mapping at address %p/%pS\n",
(void *)st->start_address, (void *)st->start_address);
st->wx_pages += (addr - st->start_address) / PAGE_SIZE;
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
pt_dump_seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
} else if (prot != st->current_prot || level != st->level ||
addr >= st->marker[1].start_address) {
const char *unit = units;
unsigned long delta;
if (st->current_prot) {
note_prot_uxn(st, addr);
note_prot_wx(st, addr);
pt_dump_seq_printf(st->seq, "0x%016lx-0x%016lx ",
st->start_address, addr);
delta = (addr - st->start_address) >> 10;
while (!(delta & 1023) && unit[1]) {
delta >>= 10;
unit++;
}
pt_dump_seq_printf(st->seq, "%9lu%c %s", delta, *unit,
pg_level[st->level].name);
if (pg_level[st->level].bits)
dump_prot(st, pg_level[st->level].bits,
pg_level[st->level].num);
pt_dump_seq_puts(st->seq, "\n");
}
if (addr >= st->marker[1].start_address) {
st->marker++;
pt_dump_seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
}
st->start_address = addr;
st->current_prot = prot;
st->level = level;
}
if (addr >= st->marker[1].start_address) {
st->marker++;
pt_dump_seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
}
}
static void walk_pte(struct pg_state *st, pmd_t *pmd, unsigned long start)
{
pte_t *pte = pte_offset_kernel(pmd, 0UL);
unsigned long addr;
unsigned i;
for (i = 0; i < PTRS_PER_PTE; i++, pte++) {
addr = start + i * PAGE_SIZE;
note_page(st, addr, 4, pte_val(*pte));
}
}
static void walk_pmd(struct pg_state *st, pud_t *pud, unsigned long start)
{
pmd_t *pmd = pmd_offset(pud, 0UL);
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
pud_t *pud = pud_offset(pgd, 0UL);
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
static void walk_pgd(struct pg_state *st, struct mm_struct *mm,
unsigned long start)
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
void ptdump_walk_pgd(struct seq_file *m, struct ptdump_info *info)
{
struct pg_state st = {
.seq = m,
.marker = info->markers,
};
walk_pgd(&st, info->mm, info->base_addr);
note_page(&st, 0, 0, 0);
}
static void ptdump_initialize(void)
{
unsigned i, j;
for (i = 0; i < ARRAY_SIZE(pg_level); i++)
if (pg_level[i].bits)
for (j = 0; j < pg_level[i].num; j++)
pg_level[i].mask |= pg_level[i].bits[j].mask;
}
void ptdump_check_wx(void)
{
struct pg_state st = {
.seq = NULL,
.marker = (struct addr_marker[]) {
{ 0, NULL},
{ -1, NULL},
},
.check_wx = true,
};
walk_pgd(&st, &init_mm, 0);
note_page(&st, 0, 0, 0);
if (st.wx_pages || st.uxn_pages)
pr_warn("Checked W+X mappings: FAILED, %lu W+X pages found, %lu non-UXN pages found\n",
st.wx_pages, st.uxn_pages);
else
pr_info("Checked W+X mappings: passed, no W+X pages found\n");
}
static int ptdump_init(void)
{
ptdump_initialize();
return ptdump_debugfs_register(&kernel_ptdump_info,
"kernel_page_tables");
}
