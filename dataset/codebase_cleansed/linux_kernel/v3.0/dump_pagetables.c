static void printk_prot(struct seq_file *m, pgprot_t prot, int level)
{
pgprotval_t pr = pgprot_val(prot);
static const char * const level_name[] =
{ "cr3", "pgd", "pud", "pmd", "pte" };
if (!pgprot_val(prot)) {
seq_printf(m, " ");
} else {
if (pr & _PAGE_USER)
seq_printf(m, "USR ");
else
seq_printf(m, " ");
if (pr & _PAGE_RW)
seq_printf(m, "RW ");
else
seq_printf(m, "ro ");
if (pr & _PAGE_PWT)
seq_printf(m, "PWT ");
else
seq_printf(m, " ");
if (pr & _PAGE_PCD)
seq_printf(m, "PCD ");
else
seq_printf(m, " ");
if (level <= 3) {
if (pr & _PAGE_PSE)
seq_printf(m, "PSE ");
else
seq_printf(m, " ");
} else {
if (pr & _PAGE_PAT)
seq_printf(m, "pat ");
else
seq_printf(m, " ");
}
if (pr & _PAGE_GLOBAL)
seq_printf(m, "GLB ");
else
seq_printf(m, " ");
if (pr & _PAGE_NX)
seq_printf(m, "NX ");
else
seq_printf(m, "x ");
}
seq_printf(m, "%s\n", level_name[level]);
}
static unsigned long normalize_addr(unsigned long u)
{
#ifdef CONFIG_X86_64
return (signed long)(u << 16) >> 16;
#else
return u;
#endif
}
static void note_page(struct seq_file *m, struct pg_state *st,
pgprot_t new_prot, int level)
{
pgprotval_t prot, cur;
static const char units[] = "KMGTPE";
prot = pgprot_val(new_prot) & PTE_FLAGS_MASK;
cur = pgprot_val(st->current_prot) & PTE_FLAGS_MASK;
if (!st->level) {
st->current_prot = new_prot;
st->level = level;
st->marker = address_markers;
seq_printf(m, "---[ %s ]---\n", st->marker->name);
} else if (prot != cur || level != st->level ||
st->current_address >= st->marker[1].start_address) {
const char *unit = units;
unsigned long delta;
int width = sizeof(unsigned long) * 2;
seq_printf(m, "0x%0*lx-0x%0*lx ",
width, st->start_address,
width, st->current_address);
delta = (st->current_address - st->start_address) >> 10;
while (!(delta & 1023) && unit[1]) {
delta >>= 10;
unit++;
}
seq_printf(m, "%9lu%c ", delta, *unit);
printk_prot(m, st->current_prot, st->level);
if (st->current_address >= st->marker[1].start_address) {
st->marker++;
seq_printf(m, "---[ %s ]---\n", st->marker->name);
}
st->start_address = st->current_address;
st->current_prot = new_prot;
st->level = level;
}
}
static void walk_pte_level(struct seq_file *m, struct pg_state *st, pmd_t addr,
unsigned long P)
{
int i;
pte_t *start;
start = (pte_t *) pmd_page_vaddr(addr);
for (i = 0; i < PTRS_PER_PTE; i++) {
pgprot_t prot = pte_pgprot(*start);
st->current_address = normalize_addr(P + i * PTE_LEVEL_MULT);
note_page(m, st, prot, 4);
start++;
}
}
static void walk_pmd_level(struct seq_file *m, struct pg_state *st, pud_t addr,
unsigned long P)
{
int i;
pmd_t *start;
start = (pmd_t *) pud_page_vaddr(addr);
for (i = 0; i < PTRS_PER_PMD; i++) {
st->current_address = normalize_addr(P + i * PMD_LEVEL_MULT);
if (!pmd_none(*start)) {
pgprotval_t prot = pmd_val(*start) & PTE_FLAGS_MASK;
if (pmd_large(*start) || !pmd_present(*start))
note_page(m, st, __pgprot(prot), 3);
else
walk_pte_level(m, st, *start,
P + i * PMD_LEVEL_MULT);
} else
note_page(m, st, __pgprot(0), 3);
start++;
}
}
static void walk_pud_level(struct seq_file *m, struct pg_state *st, pgd_t addr,
unsigned long P)
{
int i;
pud_t *start;
start = (pud_t *) pgd_page_vaddr(addr);
for (i = 0; i < PTRS_PER_PUD; i++) {
st->current_address = normalize_addr(P + i * PUD_LEVEL_MULT);
if (!pud_none(*start)) {
pgprotval_t prot = pud_val(*start) & PTE_FLAGS_MASK;
if (pud_large(*start) || !pud_present(*start))
note_page(m, st, __pgprot(prot), 2);
else
walk_pmd_level(m, st, *start,
P + i * PUD_LEVEL_MULT);
} else
note_page(m, st, __pgprot(0), 2);
start++;
}
}
static void walk_pgd_level(struct seq_file *m)
{
#ifdef CONFIG_X86_64
pgd_t *start = (pgd_t *) &init_level4_pgt;
#else
pgd_t *start = swapper_pg_dir;
#endif
int i;
struct pg_state st;
memset(&st, 0, sizeof(st));
for (i = 0; i < PTRS_PER_PGD; i++) {
st.current_address = normalize_addr(i * PGD_LEVEL_MULT);
if (!pgd_none(*start)) {
pgprotval_t prot = pgd_val(*start) & PTE_FLAGS_MASK;
if (pgd_large(*start) || !pgd_present(*start))
note_page(m, &st, __pgprot(prot), 1);
else
walk_pud_level(m, &st, *start,
i * PGD_LEVEL_MULT);
} else
note_page(m, &st, __pgprot(0), 1);
start++;
}
st.current_address = normalize_addr(PTRS_PER_PGD*PGD_LEVEL_MULT);
note_page(m, &st, __pgprot(0), 0);
}
static int ptdump_show(struct seq_file *m, void *v)
{
walk_pgd_level(m);
return 0;
}
static int ptdump_open(struct inode *inode, struct file *filp)
{
return single_open(filp, ptdump_show, NULL);
}
static int pt_dump_init(void)
{
struct dentry *pe;
#ifdef CONFIG_X86_32
address_markers[VMALLOC_START_NR].start_address = VMALLOC_START;
address_markers[VMALLOC_END_NR].start_address = VMALLOC_END;
# ifdef CONFIG_HIGHMEM
address_markers[PKMAP_BASE_NR].start_address = PKMAP_BASE;
# endif
address_markers[FIXADDR_START_NR].start_address = FIXADDR_START;
#endif
pe = debugfs_create_file("kernel_page_tables", 0600, NULL, NULL,
&ptdump_fops);
if (!pe)
return -ENOMEM;
return 0;
}
