void walk_pte(struct pg_state *st, pmd_t *pmd, unsigned long start)
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
if (pmd_none(*pmd) || pmd_large(*pmd) || !pmd_present(*pmd))
note_page(st, addr, 3, pmd_val(*pmd));
else
walk_pte(st, pmd, addr);
if (SECTION_SIZE < PMD_SIZE && pmd_large(pmd[1]))
note_page(st, addr + SECTION_SIZE, 3, pmd_val(pmd[1]));
}
}
static void walk_pud(struct pg_state *st, pgd_t *pgd, unsigned long start)
{
pud_t *pud = pud_offset(pgd, 0);
unsigned long addr;
unsigned i;
for (i = 0; i < PTRS_PER_PUD; i++, pud++) {
addr = start + i * PUD_SIZE;
if (!pud_none(*pud)) {
walk_pmd(st, pud, addr);
} else {
note_page(st, addr, 2, pud_val(*pud));
}
}
}
static void walk_pgd(struct seq_file *m)
{
pgd_t *pgd = swapper_pg_dir;
struct pg_state st;
unsigned long addr;
unsigned i, pgdoff = USER_PGTABLES_CEILING / PGDIR_SIZE;
memset(&st, 0, sizeof(st));
st.seq = m;
st.marker = address_markers;
pgd += pgdoff;
for (i = pgdoff; i < PTRS_PER_PGD; i++, pgd++) {
addr = i * PGDIR_SIZE;
if (!pgd_none(*pgd)) {
walk_pud(&st, pgd, addr);
} else {
note_page(&st, addr, 1, pgd_val(*pgd));
}
}
note_page(&st, 0, 0, 0);
}
static int ptdump_show(struct seq_file *m, void *v)
{
walk_pgd(m);
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
address_markers[2].start_address = VMALLOC_START;
pe = debugfs_create_file("kernel_page_tables", 0400, NULL, NULL,
&ptdump_fops);
return pe ? 0 : -ENOMEM;
}
