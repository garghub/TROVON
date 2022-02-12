MPI mpi_alloc(unsigned nlimbs)
{
MPI a;
a = kmalloc(sizeof *a, GFP_KERNEL);
if (!a)
return a;
if (nlimbs) {
a->d = mpi_alloc_limb_space(nlimbs);
if (!a->d) {
kfree(a);
return NULL;
}
} else {
a->d = NULL;
}
a->alloced = nlimbs;
a->nlimbs = 0;
a->sign = 0;
a->flags = 0;
a->nbits = 0;
return a;
}
mpi_ptr_t mpi_alloc_limb_space(unsigned nlimbs)
{
size_t len = nlimbs * sizeof(mpi_limb_t);
if (!len)
return NULL;
return kmalloc(len, GFP_KERNEL);
}
void mpi_free_limb_space(mpi_ptr_t a)
{
if (!a)
return;
kfree(a);
}
void mpi_assign_limb_space(MPI a, mpi_ptr_t ap, unsigned nlimbs)
{
mpi_free_limb_space(a->d);
a->d = ap;
a->alloced = nlimbs;
}
int mpi_resize(MPI a, unsigned nlimbs)
{
void *p;
if (nlimbs <= a->alloced)
return 0;
if (a->d) {
p = kmalloc(nlimbs * sizeof(mpi_limb_t), GFP_KERNEL);
if (!p)
return -ENOMEM;
memcpy(p, a->d, a->alloced * sizeof(mpi_limb_t));
kfree(a->d);
a->d = p;
} else {
a->d = kzalloc(nlimbs * sizeof(mpi_limb_t), GFP_KERNEL);
if (!a->d)
return -ENOMEM;
}
a->alloced = nlimbs;
return 0;
}
void mpi_free(MPI a)
{
if (!a)
return;
if (a->flags & 4)
kfree(a->d);
else
mpi_free_limb_space(a->d);
if (a->flags & ~7)
pr_info("invalid flag value in mpi\n");
kfree(a);
}
