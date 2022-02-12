pgd_t *get_pgd_slow(struct mm_struct *mm)
{
pgd_t *new_pgd, *init_pgd;
pmd_t *new_pmd, *init_pmd;
pte_t *new_pte, *init_pte;
new_pgd = (pgd_t *)__get_free_pages(GFP_KERNEL, 0);
if (!new_pgd)
goto no_pgd;
memset(new_pgd, 0, FIRST_KERNEL_PGD_NR * sizeof(pgd_t));
init_pgd = pgd_offset_k(0);
memcpy(new_pgd + FIRST_KERNEL_PGD_NR, init_pgd + FIRST_KERNEL_PGD_NR,
(PTRS_PER_PGD - FIRST_KERNEL_PGD_NR) * sizeof(pgd_t));
clean_dcache_area(new_pgd, PTRS_PER_PGD * sizeof(pgd_t));
if (!vectors_high()) {
new_pmd = pmd_alloc(mm, (pud_t *)new_pgd, 0);
if (!new_pmd)
goto no_pmd;
new_pte = pte_alloc_map(mm, new_pmd, 0);
if (!new_pte)
goto no_pte;
init_pmd = pmd_offset((pud_t *)init_pgd, 0);
init_pte = pte_offset_map(init_pmd, 0);
set_pte(new_pte, *init_pte);
pte_unmap(init_pte);
pte_unmap(new_pte);
}
return new_pgd;
no_pte:
pmd_free(mm, new_pmd);
mm_dec_nr_pmds(mm);
no_pmd:
free_pages((unsigned long)new_pgd, 0);
no_pgd:
return NULL;
}
void free_pgd_slow(struct mm_struct *mm, pgd_t *pgd)
{
pmd_t *pmd;
pgtable_t pte;
if (!pgd)
return;
pmd = pmd_off(pgd, 0);
if (pmd_none(*pmd))
goto free;
if (pmd_bad(*pmd)) {
pmd_ERROR(*pmd);
pmd_clear(pmd);
goto free;
}
pte = pmd_pgtable(*pmd);
pmd_clear(pmd);
pte_free(mm, pte);
atomic_long_dec(&mm->nr_ptes);
pmd_free(mm, pmd);
mm_dec_nr_pmds(mm);
free:
free_pages((unsigned long) pgd, 0);
}
