static int calculate_pagesize(struct pg_state *st, int ps, char s[])
{
static const char units[] = "BKMGTPE";
const char *unit = units;
while (ps > 9 && unit[1]) {
ps -= 10;
unit++;
}
seq_printf(st->seq, " %s_ps: %i%c\t", s, 1<<ps, *unit);
return ps;
}
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
}
}
static void dump_hpte_info(struct pg_state *st, unsigned long ea, u64 v, u64 r,
unsigned long rpn, int bps, int aps, unsigned long lp)
{
int aps_index;
while (ea >= st->marker[1].start_address) {
st->marker++;
seq_printf(st->seq, "---[ %s ]---\n", st->marker->name);
}
seq_printf(st->seq, "0x%lx:\t", ea);
seq_printf(st->seq, "AVPN:%llx\t", HPTE_V_AVPN_VAL(v));
dump_flag_info(st, v_flag_array, v, ARRAY_SIZE(v_flag_array));
seq_printf(st->seq, " rpn: %lx\t", rpn);
dump_flag_info(st, r_flag_array, r, ARRAY_SIZE(r_flag_array));
calculate_pagesize(st, bps, "base");
aps_index = calculate_pagesize(st, aps, "actual");
if (aps_index != 2)
seq_printf(st->seq, "LP enc: %lx", lp);
seq_puts(st->seq, "\n");
}
static int native_find(unsigned long ea, int psize, bool primary, u64 *v, u64
*r)
{
struct hash_pte *hptep;
unsigned long hash, vsid, vpn, hpte_group, want_v, hpte_v;
int i, ssize = mmu_kernel_ssize;
unsigned long shift = mmu_psize_defs[psize].shift;
vsid = get_kernel_vsid(ea, ssize);
vpn = hpt_vpn(ea, vsid, ssize);
hash = hpt_hash(vpn, shift, ssize);
want_v = hpte_encode_avpn(vpn, psize, ssize);
if (!primary)
hash = ~hash;
hpte_group = (hash & htab_hash_mask) * HPTES_PER_GROUP;
for (i = 0; i < HPTES_PER_GROUP; i++) {
hptep = htab_address + hpte_group;
hpte_v = be64_to_cpu(hptep->v);
if (HPTE_V_COMPARE(hpte_v, want_v) && (hpte_v & HPTE_V_VALID)) {
*v = be64_to_cpu(hptep->v);
*r = be64_to_cpu(hptep->r);
return 0;
}
++hpte_group;
}
return -1;
}
static int pseries_find(unsigned long ea, int psize, bool primary, u64 *v, u64 *r)
{
struct hash_pte ptes[4];
unsigned long vsid, vpn, hash, hpte_group, want_v;
int i, j, ssize = mmu_kernel_ssize;
long lpar_rc = 0;
unsigned long shift = mmu_psize_defs[psize].shift;
vsid = get_kernel_vsid(ea, ssize);
vpn = hpt_vpn(ea, vsid, ssize);
hash = hpt_hash(vpn, shift, ssize);
want_v = hpte_encode_avpn(vpn, psize, ssize);
if (!primary)
hash = ~hash;
hpte_group = ((hash & htab_hash_mask) * HPTES_PER_GROUP) & ~0x7UL;
for (i = 0; i < HPTES_PER_GROUP; i += 4, hpte_group += 4) {
lpar_rc = plpar_pte_read_4(0, hpte_group, (void *)ptes);
if (lpar_rc != H_SUCCESS)
continue;
for (j = 0; j < 4; j++) {
if (HPTE_V_COMPARE(ptes[j].v, want_v) &&
(ptes[j].v & HPTE_V_VALID)) {
*v = ptes[j].v;
*r = ptes[j].r;
return 0;
}
}
}
return -1;
}
static void decode_r(int bps, unsigned long r, unsigned long *rpn, int *aps,
unsigned long *lp_bits)
{
struct mmu_psize_def entry;
unsigned long arpn, mask, lp;
int penc = -2, idx = 0, shift;
arpn = (r & HPTE_R_RPN) >> HPTE_R_RPN_SHIFT;
lp = arpn & 0xff;
entry = mmu_psize_defs[bps];
while (idx < MMU_PAGE_COUNT) {
penc = entry.penc[idx];
if ((penc != -1) && (mmu_psize_defs[idx].shift)) {
shift = mmu_psize_defs[idx].shift - HPTE_R_RPN_SHIFT;
mask = (0x1 << (shift)) - 1;
if ((lp & mask) == penc) {
*aps = mmu_psize_to_shift(idx);
*lp_bits = lp & mask;
*rpn = arpn >> shift;
return;
}
}
idx++;
}
}
static int base_hpte_find(unsigned long ea, int psize, bool primary, u64 *v,
u64 *r)
{
#ifdef CONFIG_PPC_PSERIES
if (firmware_has_feature(FW_FEATURE_LPAR))
return pseries_find(ea, psize, primary, v, r);
#endif
return native_find(ea, psize, primary, v, r);
}
static unsigned long hpte_find(struct pg_state *st, unsigned long ea, int psize)
{
unsigned long slot;
u64 v = 0, r = 0;
unsigned long rpn, lp_bits;
int base_psize = 0, actual_psize = 0;
if (ea < PAGE_OFFSET)
return -1;
slot = base_hpte_find(ea, psize, true, &v, &r);
if (slot == -1)
slot = base_hpte_find(ea, psize, true, &v, &r);
if (slot == -1)
return -1;
base_psize = mmu_psize_to_shift(psize);
if ((v & HPTE_V_LARGE) == HPTE_V_LARGE) {
decode_r(psize, r, &rpn, &actual_psize, &lp_bits);
} else {
actual_psize = 12;
rpn = (r & HPTE_R_RPN) >> HPTE_R_RPN_SHIFT;
lp_bits = -1;
}
if (actual_psize == -1)
return -1;
dump_hpte_info(st, ea, v, r, rpn, base_psize, actual_psize, lp_bits);
return 0;
}
static void walk_pte(struct pg_state *st, pmd_t *pmd, unsigned long start)
{
pte_t *pte = pte_offset_kernel(pmd, 0);
unsigned long addr, pteval, psize;
int i, status;
for (i = 0; i < PTRS_PER_PTE; i++, pte++) {
addr = start + i * PAGE_SIZE;
pteval = pte_val(*pte);
if (addr < VMALLOC_END)
psize = mmu_vmalloc_psize;
else
psize = mmu_io_psize;
#ifdef CONFIG_PPC_64K_PAGES
if (((pteval & H_PAGE_COMBO) == H_PAGE_COMBO) ||
((pteval & H_PAGE_4K_PFN) == H_PAGE_4K_PFN))
psize = mmu_io_psize;
#endif
status = hpte_find(st, addr, psize);
if (((pteval & H_PAGE_HASHPTE) != H_PAGE_HASHPTE)
&& (status != -1)) {
seq_printf(st->seq, "page probably bolted before linux"
" pagetables were set: addr:%lx, pteval:%lx\n",
addr, pteval);
}
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
}
}
static void walk_linearmapping(struct pg_state *st)
{
unsigned long addr;
unsigned long psize = 1 << mmu_psize_defs[mmu_linear_psize].shift;
for (addr = PAGE_OFFSET; addr < PAGE_OFFSET +
memblock_end_of_DRAM(); addr += psize)
hpte_find(st, addr, mmu_linear_psize);
}
static void walk_vmemmap(struct pg_state *st)
{
#ifdef CONFIG_SPARSEMEM_VMEMMAP
struct vmemmap_backing *ptr = vmemmap_list;
while (ptr->list) {
hpte_find(st, ptr->virt_addr, mmu_vmemmap_psize);
ptr = ptr->list;
}
seq_puts(st->seq, "---[ vmemmap end ]---\n");
#endif
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
.start_address = PAGE_OFFSET,
.marker = address_markers,
};
walk_linearmapping(&st);
walk_pagetables(&st);
walk_vmemmap(&st);
return 0;
}
static int ptdump_open(struct inode *inode, struct file *file)
{
return single_open(file, ptdump_show, NULL);
}
static int ptdump_init(void)
{
struct dentry *debugfs_file;
if (!radix_enabled()) {
populate_markers();
debugfs_file = debugfs_create_file("kernel_hash_pagetable",
0400, NULL, NULL, &ptdump_fops);
return debugfs_file ? 0 : -ENOMEM;
}
return 0;
}
