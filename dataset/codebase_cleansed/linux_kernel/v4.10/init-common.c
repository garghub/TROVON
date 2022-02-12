static void pgd_ctor(void *addr)
{
memset(addr, 0, PGD_TABLE_SIZE);
}
static void pud_ctor(void *addr)
{
memset(addr, 0, PUD_TABLE_SIZE);
}
static void pmd_ctor(void *addr)
{
memset(addr, 0, PMD_TABLE_SIZE);
}
void pgtable_cache_add(unsigned shift, void (*ctor)(void *))
{
char *name;
unsigned long table_size = sizeof(void *) << shift;
unsigned long align = table_size;
unsigned long minalign = max(MAX_PGTABLE_INDEX_SIZE + 1,
HUGEPD_SHIFT_MASK + 1);
struct kmem_cache *new;
BUG_ON(!is_power_of_2(minalign));
BUG_ON((shift < 1) || (shift > MAX_PGTABLE_INDEX_SIZE));
if (PGT_CACHE(shift))
return;
align = max_t(unsigned long, align, minalign);
name = kasprintf(GFP_KERNEL, "pgtable-2^%d", shift);
new = kmem_cache_create(name, table_size, align, 0, ctor);
if (!new)
panic("Could not allocate pgtable cache for order %d", shift);
kfree(name);
pgtable_cache[shift - 1] = new;
pr_debug("Allocated pgtable cache for order %d\n", shift);
}
void pgtable_cache_init(void)
{
pgtable_cache_add(PGD_INDEX_SIZE, pgd_ctor);
if (PMD_CACHE_INDEX && !PGT_CACHE(PMD_CACHE_INDEX))
pgtable_cache_add(PMD_CACHE_INDEX, pmd_ctor);
if (PUD_INDEX_SIZE && !PGT_CACHE(PUD_INDEX_SIZE))
pgtable_cache_add(PUD_INDEX_SIZE, pud_ctor);
}
