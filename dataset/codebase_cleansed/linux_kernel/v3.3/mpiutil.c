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
void mpi_clear(MPI a)
{
a->nlimbs = 0;
a->nbits = 0;
a->flags = 0;
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
int mpi_copy(MPI *copied, const MPI a)
{
size_t i;
MPI b;
*copied = NULL;
if (a) {
b = mpi_alloc(a->nlimbs);
if (!b)
return -ENOMEM;
b->nlimbs = a->nlimbs;
b->sign = a->sign;
b->flags = a->flags;
b->nbits = a->nbits;
for (i = 0; i < b->nlimbs; i++)
b->d[i] = a->d[i];
*copied = b;
}
return 0;
}
int mpi_set(MPI w, const MPI u)
{
mpi_ptr_t wp, up;
mpi_size_t usize = u->nlimbs;
int usign = u->sign;
if (RESIZE_IF_NEEDED(w, (size_t) usize) < 0)
return -ENOMEM;
wp = w->d;
up = u->d;
MPN_COPY(wp, up, usize);
w->nlimbs = usize;
w->nbits = u->nbits;
w->flags = u->flags;
w->sign = usign;
return 0;
}
int mpi_set_ui(MPI w, unsigned long u)
{
if (RESIZE_IF_NEEDED(w, 1) < 0)
return -ENOMEM;
w->d[0] = u;
w->nlimbs = u ? 1 : 0;
w->sign = 0;
w->nbits = 0;
w->flags = 0;
return 0;
}
MPI mpi_alloc_set_ui(unsigned long u)
{
MPI w = mpi_alloc(1);
if (!w)
return w;
w->d[0] = u;
w->nlimbs = u ? 1 : 0;
w->sign = 0;
return w;
}
void mpi_swap(MPI a, MPI b)
{
struct gcry_mpi tmp;
tmp = *a;
*a = *b;
*b = tmp;
}
