static long ps3_hpte_insert(unsigned long hpte_group, unsigned long vpn,
unsigned long pa, unsigned long rflags, unsigned long vflags,
int psize, int apsize, int ssize)
{
int result;
u64 hpte_v, hpte_r;
u64 inserted_index;
u64 evicted_v, evicted_r;
u64 hpte_v_array[4], hpte_rs;
unsigned long flags;
long ret = -1;
vflags &= ~HPTE_V_SECONDARY;
hpte_v = hpte_encode_v(vpn, psize, apsize, ssize) | vflags | HPTE_V_VALID;
hpte_r = hpte_encode_r(ps3_mm_phys_to_lpar(pa), psize, apsize, ssize) | rflags;
spin_lock_irqsave(&ps3_htab_lock, flags);
result = lv1_insert_htab_entry(PS3_LPAR_VAS_ID_CURRENT, hpte_group,
hpte_v, hpte_r,
HPTE_V_BOLTED, 0,
&inserted_index,
&evicted_v, &evicted_r);
if (result) {
pr_info("%s:result=%s vpn=%lx pa=%lx ix=%lx v=%llx r=%llx\n",
__func__, ps3_result(result), vpn, pa, hpte_group,
hpte_v, hpte_r);
BUG();
}
result = lv1_read_htab_entries(PS3_LPAR_VAS_ID_CURRENT,
inserted_index & ~0x3UL,
&hpte_v_array[0], &hpte_v_array[1],
&hpte_v_array[2], &hpte_v_array[3],
&hpte_rs);
BUG_ON(result);
if (hpte_v_array[inserted_index % 4] & HPTE_V_SECONDARY)
ret = (inserted_index & 7) | (1 << 3);
else
ret = inserted_index & 7;
spin_unlock_irqrestore(&ps3_htab_lock, flags);
return ret;
}
static long ps3_hpte_remove(unsigned long hpte_group)
{
panic("ps3_hpte_remove() not implemented");
return 0;
}
static long ps3_hpte_updatepp(unsigned long slot, unsigned long newpp,
unsigned long vpn, int psize, int apsize,
int ssize, unsigned long inv_flags)
{
int result;
u64 hpte_v, want_v, hpte_rs;
u64 hpte_v_array[4];
unsigned long flags;
long ret;
want_v = hpte_encode_avpn(vpn, psize, ssize);
spin_lock_irqsave(&ps3_htab_lock, flags);
result = lv1_read_htab_entries(PS3_LPAR_VAS_ID_CURRENT, slot & ~0x3UL,
&hpte_v_array[0], &hpte_v_array[1],
&hpte_v_array[2], &hpte_v_array[3],
&hpte_rs);
if (result) {
pr_info("%s: result=%s read vpn=%lx slot=%lx psize=%d\n",
__func__, ps3_result(result), vpn, slot, psize);
BUG();
}
hpte_v = hpte_v_array[slot % 4];
if (!HPTE_V_COMPARE(hpte_v, want_v) || !(hpte_v & HPTE_V_VALID)) {
ret = -1;
} else {
result = lv1_write_htab_entry(PS3_LPAR_VAS_ID_CURRENT,
slot, 0, 0);
ret = -1;
}
spin_unlock_irqrestore(&ps3_htab_lock, flags);
return ret;
}
static void ps3_hpte_updateboltedpp(unsigned long newpp, unsigned long ea,
int psize, int ssize)
{
panic("ps3_hpte_updateboltedpp() not implemented");
}
static void ps3_hpte_invalidate(unsigned long slot, unsigned long vpn,
int psize, int apsize, int ssize, int local)
{
unsigned long flags;
int result;
spin_lock_irqsave(&ps3_htab_lock, flags);
result = lv1_write_htab_entry(PS3_LPAR_VAS_ID_CURRENT, slot, 0, 0);
if (result) {
pr_info("%s: result=%s vpn=%lx slot=%lx psize=%d\n",
__func__, ps3_result(result), vpn, slot, psize);
BUG();
}
spin_unlock_irqrestore(&ps3_htab_lock, flags);
}
static void ps3_hpte_clear(void)
{
unsigned long hpte_count = (1UL << ppc64_pft_size) >> 4;
u64 i;
for (i = 0; i < hpte_count; i++)
lv1_write_htab_entry(PS3_LPAR_VAS_ID_CURRENT, i, 0, 0);
ps3_mm_shutdown();
ps3_mm_vas_destroy();
}
void __init ps3_hpte_init(unsigned long htab_size)
{
mmu_hash_ops.hpte_invalidate = ps3_hpte_invalidate;
mmu_hash_ops.hpte_updatepp = ps3_hpte_updatepp;
mmu_hash_ops.hpte_updateboltedpp = ps3_hpte_updateboltedpp;
mmu_hash_ops.hpte_insert = ps3_hpte_insert;
mmu_hash_ops.hpte_remove = ps3_hpte_remove;
mmu_hash_ops.hpte_clear_all = ps3_hpte_clear;
ppc64_pft_size = __ilog2(htab_size);
}
