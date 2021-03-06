phys_addr_t v_mapped_by_bats(unsigned long va)
{
int b;
for (b = 0; b < 4; ++b)
if (va >= bat_addrs[b].start && va < bat_addrs[b].limit)
return bat_addrs[b].phys + (va - bat_addrs[b].start);
return 0;
}
unsigned long p_mapped_by_bats(phys_addr_t pa)
{
int b;
for (b = 0; b < 4; ++b)
if (pa >= bat_addrs[b].phys
&& pa < (bat_addrs[b].limit-bat_addrs[b].start)
+bat_addrs[b].phys)
return bat_addrs[b].start+(pa-bat_addrs[b].phys);
return 0;
}
unsigned long __init mmu_mapin_ram(unsigned long top)
{
unsigned long tot, bl, done;
unsigned long max_size = (256<<20);
if (__map_without_bats) {
printk(KERN_DEBUG "RAM mapped without BATs\n");
return 0;
}
tot = top;
for (bl = 128<<10; bl < max_size; bl <<= 1) {
if (bl * 2 > tot)
break;
}
setbat(2, PAGE_OFFSET, 0, bl, PAGE_KERNEL_X);
done = (unsigned long)bat_addrs[2].limit - PAGE_OFFSET + 1;
if ((done < tot) && !bat_addrs[3].limit) {
tot -= done;
for (bl = 128<<10; bl < max_size; bl <<= 1)
if (bl * 2 > tot)
break;
setbat(3, PAGE_OFFSET+done, done, bl, PAGE_KERNEL_X);
done = (unsigned long)bat_addrs[3].limit - PAGE_OFFSET + 1;
}
return done;
}
void __init setbat(int index, unsigned long virt, phys_addr_t phys,
unsigned int size, pgprot_t prot)
{
unsigned int bl;
int wimgxpp;
struct ppc_bat *bat = BATS[index];
unsigned long flags = pgprot_val(prot);
if ((flags & _PAGE_NO_CACHE) ||
(cpu_has_feature(CPU_FTR_NEED_COHERENT) == 0))
flags &= ~_PAGE_COHERENT;
bl = (size >> 17) - 1;
if (PVR_VER(mfspr(SPRN_PVR)) != 1) {
wimgxpp = flags & (_PAGE_WRITETHRU | _PAGE_NO_CACHE
| _PAGE_COHERENT | _PAGE_GUARDED);
wimgxpp |= (flags & _PAGE_RW)? BPP_RW: BPP_RX;
bat[1].batu = virt | (bl << 2) | 2;
bat[1].batl = BAT_PHYS_ADDR(phys) | wimgxpp;
if (flags & _PAGE_USER)
bat[1].batu |= 1;
if (flags & _PAGE_GUARDED) {
bat[0].batu = bat[0].batl = 0;
} else {
bat[0] = bat[1];
}
} else {
if (bl > BL_8M)
bl = BL_8M;
wimgxpp = flags & (_PAGE_WRITETHRU | _PAGE_NO_CACHE
| _PAGE_COHERENT);
wimgxpp |= (flags & _PAGE_RW)?
((flags & _PAGE_USER)? PP_RWRW: PP_RWXX): PP_RXRX;
bat->batu = virt | wimgxpp | 4;
bat->batl = phys | bl | 0x40;
}
bat_addrs[index].start = virt;
bat_addrs[index].limit = virt + ((bl + 1) << 17) - 1;
bat_addrs[index].phys = phys;
}
void hash_preload(struct mm_struct *mm, unsigned long ea,
unsigned long access, unsigned long trap)
{
pmd_t *pmd;
if (Hash == 0)
return;
pmd = pmd_offset(pud_offset(pgd_offset(mm, ea), ea), ea);
if (!pmd_none(*pmd))
add_hash_page(mm->context.id, ea, pmd_val(*pmd));
}
void __init MMU_init_hw(void)
{
unsigned int hmask, mb, mb2;
unsigned int n_hpteg, lg_n_hpteg;
extern unsigned int hash_page_patch_A[];
extern unsigned int hash_page_patch_B[], hash_page_patch_C[];
extern unsigned int hash_page[];
extern unsigned int flush_hash_patch_A[], flush_hash_patch_B[];
if (!mmu_has_feature(MMU_FTR_HPTE_TABLE)) {
hash_page[0] = 0x4e800020;
flush_icache_range((unsigned long) &hash_page[0],
(unsigned long) &hash_page[1]);
return;
}
if ( ppc_md.progress ) ppc_md.progress("hash:enter", 0x105);
#define LG_HPTEG_SIZE 6
#define SDR1_LOW_BITS ((n_hpteg - 1) >> 10)
#define MIN_N_HPTEG 1024
n_hpteg = total_memory / (PAGE_SIZE * 8);
if (n_hpteg < MIN_N_HPTEG)
n_hpteg = MIN_N_HPTEG;
lg_n_hpteg = __ilog2(n_hpteg);
if (n_hpteg & (n_hpteg - 1)) {
++lg_n_hpteg;
n_hpteg = 1 << lg_n_hpteg;
}
Hash_size = n_hpteg << LG_HPTEG_SIZE;
if ( ppc_md.progress ) ppc_md.progress("hash:find piece", 0x322);
Hash = __va(memblock_alloc(Hash_size, Hash_size));
memset(Hash, 0, Hash_size);
_SDR1 = __pa(Hash) | SDR1_LOW_BITS;
Hash_end = (struct hash_pte *) ((unsigned long)Hash + Hash_size);
printk("Total memory = %lldMB; using %ldkB for hash table (at %p)\n",
(unsigned long long)(total_memory >> 20), Hash_size >> 10, Hash);
if ( ppc_md.progress ) ppc_md.progress("hash:patch", 0x345);
Hash_mask = n_hpteg - 1;
hmask = Hash_mask >> (16 - LG_HPTEG_SIZE);
mb2 = mb = 32 - LG_HPTEG_SIZE - lg_n_hpteg;
if (lg_n_hpteg > 16)
mb2 = 16 - LG_HPTEG_SIZE;
hash_page_patch_A[0] = (hash_page_patch_A[0] & ~0xffff)
| ((unsigned int)(Hash) >> 16);
hash_page_patch_A[1] = (hash_page_patch_A[1] & ~0x7c0) | (mb << 6);
hash_page_patch_A[2] = (hash_page_patch_A[2] & ~0x7c0) | (mb2 << 6);
hash_page_patch_B[0] = (hash_page_patch_B[0] & ~0xffff) | hmask;
hash_page_patch_C[0] = (hash_page_patch_C[0] & ~0xffff) | hmask;
flush_icache_range((unsigned long) &hash_page_patch_A[0],
(unsigned long) &hash_page_patch_C[1]);
flush_hash_patch_A[0] = (flush_hash_patch_A[0] & ~0xffff)
| ((unsigned int)(Hash) >> 16);
flush_hash_patch_A[1] = (flush_hash_patch_A[1] & ~0x7c0) | (mb << 6);
flush_hash_patch_A[2] = (flush_hash_patch_A[2] & ~0x7c0) | (mb2 << 6);
flush_hash_patch_B[0] = (flush_hash_patch_B[0] & ~0xffff) | hmask;
flush_icache_range((unsigned long) &flush_hash_patch_A[0],
(unsigned long) &flush_hash_patch_B[1]);
if ( ppc_md.progress ) ppc_md.progress("hash:done", 0x205);
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
BUG_ON(first_memblock_base != 0);
if (PVR_VER(mfspr(SPRN_PVR)) == 1)
memblock_set_current_limit(min_t(u64, first_memblock_size, 0x01000000));
else
memblock_set_current_limit(min_t(u64, first_memblock_size, 0x10000000));
}
