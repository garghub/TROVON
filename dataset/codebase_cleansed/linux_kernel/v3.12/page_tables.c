static pgd_t *spgd_addr(struct lg_cpu *cpu, u32 i, unsigned long vaddr)
{
unsigned int index = pgd_index(vaddr);
return &cpu->lg->pgdirs[i].pgdir[index];
}
static pmd_t *spmd_addr(struct lg_cpu *cpu, pgd_t spgd, unsigned long vaddr)
{
unsigned int index = pmd_index(vaddr);
pmd_t *page;
BUG_ON(!(pgd_flags(spgd) & _PAGE_PRESENT));
page = __va(pgd_pfn(spgd) << PAGE_SHIFT);
return &page[index];
}
static pte_t *spte_addr(struct lg_cpu *cpu, pgd_t spgd, unsigned long vaddr)
{
#ifdef CONFIG_X86_PAE
pmd_t *pmd = spmd_addr(cpu, spgd, vaddr);
pte_t *page = __va(pmd_pfn(*pmd) << PAGE_SHIFT);
BUG_ON(!(pmd_flags(*pmd) & _PAGE_PRESENT));
#else
pte_t *page = __va(pgd_pfn(spgd) << PAGE_SHIFT);
BUG_ON(!(pgd_flags(spgd) & _PAGE_PRESENT));
#endif
return &page[pte_index(vaddr)];
}
static unsigned long gpgd_addr(struct lg_cpu *cpu, unsigned long vaddr)
{
unsigned int index = vaddr >> (PGDIR_SHIFT);
return cpu->lg->pgdirs[cpu->cpu_pgd].gpgdir + index * sizeof(pgd_t);
}
static unsigned long gpmd_addr(pgd_t gpgd, unsigned long vaddr)
{
unsigned long gpage = pgd_pfn(gpgd) << PAGE_SHIFT;
BUG_ON(!(pgd_flags(gpgd) & _PAGE_PRESENT));
return gpage + pmd_index(vaddr) * sizeof(pmd_t);
}
static unsigned long gpte_addr(struct lg_cpu *cpu,
pmd_t gpmd, unsigned long vaddr)
{
unsigned long gpage = pmd_pfn(gpmd) << PAGE_SHIFT;
BUG_ON(!(pmd_flags(gpmd) & _PAGE_PRESENT));
return gpage + pte_index(vaddr) * sizeof(pte_t);
}
static unsigned long gpte_addr(struct lg_cpu *cpu,
pgd_t gpgd, unsigned long vaddr)
{
unsigned long gpage = pgd_pfn(gpgd) << PAGE_SHIFT;
BUG_ON(!(pgd_flags(gpgd) & _PAGE_PRESENT));
return gpage + pte_index(vaddr) * sizeof(pte_t);
}
static unsigned long get_pfn(unsigned long virtpfn, int write)
{
struct page *page;
if (get_user_pages_fast(virtpfn << PAGE_SHIFT, 1, write, &page) == 1)
return page_to_pfn(page);
return -1UL;
}
static pte_t gpte_to_spte(struct lg_cpu *cpu, pte_t gpte, int write)
{
unsigned long pfn, base, flags;
flags = (pte_flags(gpte) & ~_PAGE_GLOBAL);
base = (unsigned long)cpu->lg->mem_base / PAGE_SIZE;
pfn = get_pfn(base + pte_pfn(gpte), write);
if (pfn == -1UL) {
kill_guest(cpu, "failed to get page %lu", pte_pfn(gpte));
flags = 0;
}
return pfn_pte(pfn, __pgprot(flags));
}
static void release_pte(pte_t pte)
{
if (pte_flags(pte) & _PAGE_PRESENT)
put_page(pte_page(pte));
}
static bool check_gpte(struct lg_cpu *cpu, pte_t gpte)
{
if ((pte_flags(gpte) & _PAGE_PSE) ||
pte_pfn(gpte) >= cpu->lg->pfn_limit) {
kill_guest(cpu, "bad page table entry");
return false;
}
return true;
}
static bool check_gpgd(struct lg_cpu *cpu, pgd_t gpgd)
{
if ((pgd_flags(gpgd) & ~CHECK_GPGD_MASK) ||
(pgd_pfn(gpgd) >= cpu->lg->pfn_limit)) {
kill_guest(cpu, "bad page directory entry");
return false;
}
return true;
}
static bool check_gpmd(struct lg_cpu *cpu, pmd_t gpmd)
{
if ((pmd_flags(gpmd) & ~_PAGE_TABLE) ||
(pmd_pfn(gpmd) >= cpu->lg->pfn_limit)) {
kill_guest(cpu, "bad page middle directory entry");
return false;
}
return true;
}
static pte_t *find_spte(struct lg_cpu *cpu, unsigned long vaddr, bool allocate,
int pgd_flags, int pmd_flags)
{
pgd_t *spgd;
#ifdef CONFIG_X86_PAE
pmd_t *spmd;
#endif
spgd = spgd_addr(cpu, cpu->cpu_pgd, vaddr);
if (!(pgd_flags(*spgd) & _PAGE_PRESENT)) {
unsigned long ptepage;
if (!allocate)
return NULL;
ptepage = get_zeroed_page(GFP_KERNEL);
if (!ptepage) {
kill_guest(cpu, "out of memory allocating pte page");
return NULL;
}
set_pgd(spgd, __pgd(__pa(ptepage) | pgd_flags));
}
#ifdef CONFIG_X86_PAE
spmd = spmd_addr(cpu, *spgd, vaddr);
if (!(pmd_flags(*spmd) & _PAGE_PRESENT)) {
unsigned long ptepage;
if (!allocate)
return NULL;
ptepage = get_zeroed_page(GFP_KERNEL);
if (!ptepage) {
kill_guest(cpu, "out of memory allocating pmd page");
return NULL;
}
set_pmd(spmd, __pmd(__pa(ptepage) | pmd_flags));
}
#endif
return spte_addr(cpu, *spgd, vaddr);
}
bool demand_page(struct lg_cpu *cpu, unsigned long vaddr, int errcode)
{
unsigned long gpte_ptr;
pte_t gpte;
pte_t *spte;
pmd_t gpmd;
pgd_t gpgd;
if (vaddr >= switcher_addr)
return false;
if (unlikely(cpu->linear_pages)) {
gpgd = __pgd(CHECK_GPGD_MASK);
} else {
gpgd = lgread(cpu, gpgd_addr(cpu, vaddr), pgd_t);
if (!(pgd_flags(gpgd) & _PAGE_PRESENT))
return false;
if (!check_gpgd(cpu, gpgd))
return false;
}
gpmd = __pmd(_PAGE_TABLE);
#ifdef CONFIG_X86_PAE
if (likely(!cpu->linear_pages)) {
gpmd = lgread(cpu, gpmd_addr(gpgd, vaddr), pmd_t);
if (!(pmd_flags(gpmd) & _PAGE_PRESENT))
return false;
if (!check_gpmd(cpu, gpmd))
return false;
}
gpte_ptr = gpte_addr(cpu, gpmd, vaddr);
#else
gpte_ptr = gpte_addr(cpu, gpgd, vaddr);
#endif
if (unlikely(cpu->linear_pages)) {
gpte = __pte((vaddr & PAGE_MASK) | _PAGE_RW | _PAGE_PRESENT);
} else {
gpte = lgread(cpu, gpte_ptr, pte_t);
}
if (!(pte_flags(gpte) & _PAGE_PRESENT))
return false;
if ((errcode & 2) && !(pte_flags(gpte) & _PAGE_RW))
return false;
if ((errcode & 4) && !(pte_flags(gpte) & _PAGE_USER))
return false;
if (!check_gpte(cpu, gpte))
return false;
gpte = pte_mkyoung(gpte);
if (errcode & 2)
gpte = pte_mkdirty(gpte);
spte = find_spte(cpu, vaddr, true, pgd_flags(gpgd), pmd_flags(gpmd));
if (!spte)
return false;
release_pte(*spte);
if (pte_dirty(gpte))
*spte = gpte_to_spte(cpu, gpte, 1);
else
set_pte(spte, gpte_to_spte(cpu, pte_wrprotect(gpte), 0));
if (likely(!cpu->linear_pages))
lgwrite(cpu, gpte_ptr, pte_t, gpte);
return true;
}
static bool page_writable(struct lg_cpu *cpu, unsigned long vaddr)
{
pte_t *spte;
unsigned long flags;
if (vaddr >= switcher_addr)
return false;
spte = find_spte(cpu, vaddr, false, 0, 0);
if (!spte)
return false;
flags = pte_flags(*spte);
return (flags & (_PAGE_PRESENT|_PAGE_RW)) == (_PAGE_PRESENT|_PAGE_RW);
}
void pin_page(struct lg_cpu *cpu, unsigned long vaddr)
{
if (!page_writable(cpu, vaddr) && !demand_page(cpu, vaddr, 2))
kill_guest(cpu, "bad stack page %#lx", vaddr);
}
static void release_pmd(pmd_t *spmd)
{
if (pmd_flags(*spmd) & _PAGE_PRESENT) {
unsigned int i;
pte_t *ptepage = __va(pmd_pfn(*spmd) << PAGE_SHIFT);
for (i = 0; i < PTRS_PER_PTE; i++)
release_pte(ptepage[i]);
free_page((long)ptepage);
set_pmd(spmd, __pmd(0));
}
}
static void release_pgd(pgd_t *spgd)
{
if (pgd_flags(*spgd) & _PAGE_PRESENT) {
unsigned int i;
pmd_t *pmdpage = __va(pgd_pfn(*spgd) << PAGE_SHIFT);
for (i = 0; i < PTRS_PER_PMD; i++)
release_pmd(&pmdpage[i]);
free_page((long)pmdpage);
set_pgd(spgd, __pgd(0));
}
}
static void release_pgd(pgd_t *spgd)
{
if (pgd_flags(*spgd) & _PAGE_PRESENT) {
unsigned int i;
pte_t *ptepage = __va(pgd_pfn(*spgd) << PAGE_SHIFT);
for (i = 0; i < PTRS_PER_PTE; i++)
release_pte(ptepage[i]);
free_page((long)ptepage);
*spgd = __pgd(0);
}
}
static void flush_user_mappings(struct lguest *lg, int idx)
{
unsigned int i;
for (i = 0; i < pgd_index(lg->kernel_address); i++)
release_pgd(lg->pgdirs[idx].pgdir + i);
}
void guest_pagetable_flush_user(struct lg_cpu *cpu)
{
flush_user_mappings(cpu->lg, cpu->cpu_pgd);
}
unsigned long guest_pa(struct lg_cpu *cpu, unsigned long vaddr)
{
pgd_t gpgd;
pte_t gpte;
#ifdef CONFIG_X86_PAE
pmd_t gpmd;
#endif
if (unlikely(cpu->linear_pages))
return vaddr;
gpgd = lgread(cpu, gpgd_addr(cpu, vaddr), pgd_t);
if (!(pgd_flags(gpgd) & _PAGE_PRESENT)) {
kill_guest(cpu, "Bad address %#lx", vaddr);
return -1UL;
}
#ifdef CONFIG_X86_PAE
gpmd = lgread(cpu, gpmd_addr(gpgd, vaddr), pmd_t);
if (!(pmd_flags(gpmd) & _PAGE_PRESENT)) {
kill_guest(cpu, "Bad address %#lx", vaddr);
return -1UL;
}
gpte = lgread(cpu, gpte_addr(cpu, gpmd, vaddr), pte_t);
#else
gpte = lgread(cpu, gpte_addr(cpu, gpgd, vaddr), pte_t);
#endif
if (!(pte_flags(gpte) & _PAGE_PRESENT))
kill_guest(cpu, "Bad address %#lx", vaddr);
return pte_pfn(gpte) * PAGE_SIZE | (vaddr & ~PAGE_MASK);
}
static unsigned int find_pgdir(struct lguest *lg, unsigned long pgtable)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(lg->pgdirs); i++)
if (lg->pgdirs[i].pgdir && lg->pgdirs[i].gpgdir == pgtable)
break;
return i;
}
static unsigned int new_pgdir(struct lg_cpu *cpu,
unsigned long gpgdir,
int *blank_pgdir)
{
unsigned int next;
next = prandom_u32() % ARRAY_SIZE(cpu->lg->pgdirs);
if (!cpu->lg->pgdirs[next].pgdir) {
cpu->lg->pgdirs[next].pgdir =
(pgd_t *)get_zeroed_page(GFP_KERNEL);
if (!cpu->lg->pgdirs[next].pgdir)
next = cpu->cpu_pgd;
else {
*blank_pgdir = 1;
}
}
cpu->lg->pgdirs[next].gpgdir = gpgdir;
flush_user_mappings(cpu->lg, next);
cpu->lg->pgdirs[next].last_host_cpu = -1;
return next;
}
static bool allocate_switcher_mapping(struct lg_cpu *cpu)
{
int i;
for (i = 0; i < TOTAL_SWITCHER_PAGES; i++) {
pte_t *pte = find_spte(cpu, switcher_addr + i * PAGE_SIZE, true,
CHECK_GPGD_MASK, _PAGE_TABLE);
if (!pte)
return false;
if (i == 0 && !(pte_flags(*pte) & _PAGE_PRESENT)) {
get_page(lg_switcher_pages[0]);
set_pte(pte,
mk_pte(lg_switcher_pages[0], PAGE_KERNEL_RX));
}
}
cpu->lg->pgdirs[cpu->cpu_pgd].switcher_mapped = true;
return true;
}
static void release_all_pagetables(struct lguest *lg)
{
unsigned int i, j;
for (i = 0; i < ARRAY_SIZE(lg->pgdirs); i++) {
if (!lg->pgdirs[i].pgdir)
continue;
for (j = 0; j < PTRS_PER_PGD; j++)
release_pgd(lg->pgdirs[i].pgdir + j);
lg->pgdirs[i].switcher_mapped = false;
lg->pgdirs[i].last_host_cpu = -1;
}
}
void guest_pagetable_clear_all(struct lg_cpu *cpu)
{
release_all_pagetables(cpu->lg);
pin_stack_pages(cpu);
if (!allocate_switcher_mapping(cpu))
kill_guest(cpu, "Cannot populate switcher mapping");
}
void guest_new_pagetable(struct lg_cpu *cpu, unsigned long pgtable)
{
int newpgdir, repin = 0;
if (unlikely(cpu->linear_pages)) {
release_all_pagetables(cpu->lg);
cpu->linear_pages = false;
newpgdir = ARRAY_SIZE(cpu->lg->pgdirs);
} else {
newpgdir = find_pgdir(cpu->lg, pgtable);
}
if (newpgdir == ARRAY_SIZE(cpu->lg->pgdirs))
newpgdir = new_pgdir(cpu, pgtable, &repin);
cpu->cpu_pgd = newpgdir;
if (repin)
pin_stack_pages(cpu);
if (!cpu->lg->pgdirs[cpu->cpu_pgd].switcher_mapped) {
if (!allocate_switcher_mapping(cpu))
kill_guest(cpu, "Cannot populate switcher mapping");
}
}
static void do_set_pte(struct lg_cpu *cpu, int idx,
unsigned long vaddr, pte_t gpte)
{
pgd_t *spgd = spgd_addr(cpu, idx, vaddr);
#ifdef CONFIG_X86_PAE
pmd_t *spmd;
#endif
if (pgd_flags(*spgd) & _PAGE_PRESENT) {
#ifdef CONFIG_X86_PAE
spmd = spmd_addr(cpu, *spgd, vaddr);
if (pmd_flags(*spmd) & _PAGE_PRESENT) {
#endif
pte_t *spte = spte_addr(cpu, *spgd, vaddr);
release_pte(*spte);
if (pte_flags(gpte) & (_PAGE_DIRTY | _PAGE_ACCESSED)) {
if (!check_gpte(cpu, gpte))
return;
set_pte(spte,
gpte_to_spte(cpu, gpte,
pte_flags(gpte) & _PAGE_DIRTY));
} else {
set_pte(spte, __pte(0));
}
#ifdef CONFIG_X86_PAE
}
#endif
}
}
void guest_set_pte(struct lg_cpu *cpu,
unsigned long gpgdir, unsigned long vaddr, pte_t gpte)
{
if (vaddr >= switcher_addr) {
kill_guest(cpu, "attempt to set pte into Switcher pages");
return;
}
if (vaddr >= cpu->lg->kernel_address) {
unsigned int i;
for (i = 0; i < ARRAY_SIZE(cpu->lg->pgdirs); i++)
if (cpu->lg->pgdirs[i].pgdir)
do_set_pte(cpu, i, vaddr, gpte);
} else {
int pgdir = find_pgdir(cpu->lg, gpgdir);
if (pgdir != ARRAY_SIZE(cpu->lg->pgdirs))
do_set_pte(cpu, pgdir, vaddr, gpte);
}
}
void guest_set_pgd(struct lguest *lg, unsigned long gpgdir, u32 idx)
{
int pgdir;
if (idx > PTRS_PER_PGD) {
kill_guest(&lg->cpus[0], "Attempt to set pgd %u/%u",
idx, PTRS_PER_PGD);
return;
}
pgdir = find_pgdir(lg, gpgdir);
if (pgdir < ARRAY_SIZE(lg->pgdirs)) {
release_pgd(lg->pgdirs[pgdir].pgdir + idx);
if (!allocate_switcher_mapping(&lg->cpus[0])) {
kill_guest(&lg->cpus[0],
"Cannot populate switcher mapping");
}
lg->pgdirs[pgdir].last_host_cpu = -1;
}
}
void guest_set_pmd(struct lguest *lg, unsigned long pmdp, u32 idx)
{
guest_pagetable_clear_all(&lg->cpus[0]);
}
int init_guest_pagetable(struct lguest *lg)
{
struct lg_cpu *cpu = &lg->cpus[0];
int allocated = 0;
cpu->cpu_pgd = new_pgdir(cpu, 0, &allocated);
if (!allocated)
return -ENOMEM;
cpu->linear_pages = true;
if (!allocate_switcher_mapping(cpu)) {
release_all_pagetables(lg);
return -ENOMEM;
}
return 0;
}
void page_table_guest_data_init(struct lg_cpu *cpu)
{
u32 top = ~switcher_addr + 1;
if (get_user(cpu->lg->kernel_address,
&cpu->lg->lguest_data->kernel_address)
|| put_user(top, &cpu->lg->lguest_data->reserve_mem)) {
kill_guest(cpu, "bad guest page %p", cpu->lg->lguest_data);
return;
}
if (cpu->lg->kernel_address >= switcher_addr)
kill_guest(cpu, "bad kernel address %#lx",
cpu->lg->kernel_address);
}
void free_guest_pagetable(struct lguest *lg)
{
unsigned int i;
release_all_pagetables(lg);
for (i = 0; i < ARRAY_SIZE(lg->pgdirs); i++)
free_page((long)lg->pgdirs[i].pgdir);
}
static void remove_switcher_percpu_map(struct lg_cpu *cpu, unsigned int i)
{
unsigned long base = switcher_addr + PAGE_SIZE + i * PAGE_SIZE*2;
pte_t *pte;
pte = find_spte(cpu, base, false, 0, 0);
release_pte(*pte);
set_pte(pte, __pte(0));
pte = find_spte(cpu, base + PAGE_SIZE, false, 0, 0);
release_pte(*pte);
set_pte(pte, __pte(0));
}
void map_switcher_in_guest(struct lg_cpu *cpu, struct lguest_pages *pages)
{
unsigned long base;
struct page *percpu_switcher_page, *regs_page;
pte_t *pte;
struct pgdir *pgdir = &cpu->lg->pgdirs[cpu->cpu_pgd];
BUG_ON(!pgdir->switcher_mapped);
if (pgdir->last_host_cpu == raw_smp_processor_id())
return;
if (pgdir->last_host_cpu == -1) {
unsigned int i;
for_each_possible_cpu(i)
remove_switcher_percpu_map(cpu, i);
} else {
remove_switcher_percpu_map(cpu, pgdir->last_host_cpu);
}
base = switcher_addr + PAGE_SIZE
+ raw_smp_processor_id() * sizeof(struct lguest_pages);
pte = find_spte(cpu, base, false, 0, 0);
regs_page = pfn_to_page(__pa(cpu->regs_page) >> PAGE_SHIFT);
get_page(regs_page);
set_pte(pte, mk_pte(regs_page, __pgprot(__PAGE_KERNEL & ~_PAGE_GLOBAL)));
pte = find_spte(cpu, base + PAGE_SIZE, false, 0, 0);
percpu_switcher_page
= lg_switcher_pages[1 + raw_smp_processor_id()*2 + 1];
get_page(percpu_switcher_page);
set_pte(pte, mk_pte(percpu_switcher_page,
__pgprot(__PAGE_KERNEL_RO & ~_PAGE_GLOBAL)));
pgdir->last_host_cpu = raw_smp_processor_id();
}
