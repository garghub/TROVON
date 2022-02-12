pgd_t *pgd_alloc(struct mm_struct *mm)
{
if (PGD_SIZE == PAGE_SIZE)
return (pgd_t *)get_zeroed_page(GFP_KERNEL);
else
return kzalloc(PGD_SIZE, GFP_KERNEL);
}
void pgd_free(struct mm_struct *mm, pgd_t *pgd)
{
if (PGD_SIZE == PAGE_SIZE)
free_page((unsigned long)pgd);
else
kfree(pgd);
}
