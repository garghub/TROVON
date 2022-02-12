pgd_t *pgd_alloc(struct mm_struct *mm)
{
pgd_t *new_pgd;
if (PGD_SIZE == PAGE_SIZE)
new_pgd = (pgd_t *)get_zeroed_page(GFP_KERNEL);
else
new_pgd = kzalloc(PGD_SIZE, GFP_KERNEL);
if (!new_pgd)
return NULL;
return new_pgd;
}
void pgd_free(struct mm_struct *mm, pgd_t *pgd)
{
if (PGD_SIZE == PAGE_SIZE)
free_page((unsigned long)pgd);
else
kfree(pgd);
}
