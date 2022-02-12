pgd_t *pgd_alloc(struct mm_struct *mm)
{
if (PGD_SIZE == PAGE_SIZE)
return (pgd_t *)__get_free_page(PGALLOC_GFP);
else
return kmem_cache_alloc(pgd_cache, PGALLOC_GFP);
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
