pgd_t *pgd_alloc(struct mm_struct *mm)
{
if (PGD_SIZE == PAGE_SIZE)
return (pgd_t *)get_zeroed_page(GFP_KERNEL);
else
return kmem_cache_zalloc(pgd_cache, GFP_KERNEL);
}
void pgd_free(struct mm_struct *mm, pgd_t *pgd)
{
if (PGD_SIZE == PAGE_SIZE)
free_page((unsigned long)pgd);
else
kmem_cache_free(pgd_cache, pgd);
}
static int __init pgd_cache_init(void)
{
if (PGD_SIZE != PAGE_SIZE)
pgd_cache = kmem_cache_create("pgd_cache", PGD_SIZE, PGD_SIZE,
SLAB_PANIC, NULL);
return 0;
}
