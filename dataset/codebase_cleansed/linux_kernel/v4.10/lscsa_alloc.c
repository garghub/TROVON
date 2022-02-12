int spu_alloc_lscsa(struct spu_state *csa)
{
struct spu_lscsa *lscsa;
unsigned char *p;
lscsa = vzalloc(sizeof(struct spu_lscsa));
if (!lscsa)
return -ENOMEM;
csa->lscsa = lscsa;
for (p = lscsa->ls; p < lscsa->ls + LS_SIZE; p += PAGE_SIZE)
SetPageReserved(vmalloc_to_page(p));
return 0;
}
void spu_free_lscsa(struct spu_state *csa)
{
unsigned char *p;
if (csa->lscsa == NULL)
return;
for (p = csa->lscsa->ls; p < csa->lscsa->ls + LS_SIZE; p += PAGE_SIZE)
ClearPageReserved(vmalloc_to_page(p));
vfree(csa->lscsa);
}
