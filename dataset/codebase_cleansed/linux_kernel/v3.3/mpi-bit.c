void mpi_normalize(MPI a)
{
for (; a->nlimbs && !a->d[a->nlimbs - 1]; a->nlimbs--)
;
}
unsigned mpi_get_nbits(MPI a)
{
unsigned n;
mpi_normalize(a);
if (a->nlimbs) {
mpi_limb_t alimb = a->d[a->nlimbs - 1];
if (alimb)
count_leading_zeros(n, alimb);
else
n = BITS_PER_MPI_LIMB;
n = BITS_PER_MPI_LIMB - n + (a->nlimbs - 1) * BITS_PER_MPI_LIMB;
} else
n = 0;
return n;
}
int mpi_test_bit(MPI a, unsigned n)
{
unsigned limbno, bitno;
mpi_limb_t limb;
limbno = n / BITS_PER_MPI_LIMB;
bitno = n % BITS_PER_MPI_LIMB;
if (limbno >= a->nlimbs)
return 0;
limb = a->d[limbno];
return (limb & (A_LIMB_1 << bitno)) ? 1 : 0;
}
int mpi_set_bit(MPI a, unsigned n)
{
unsigned limbno, bitno;
limbno = n / BITS_PER_MPI_LIMB;
bitno = n % BITS_PER_MPI_LIMB;
if (limbno >= a->nlimbs) {
if (a->alloced >= limbno)
if (mpi_resize(a, limbno + 1) < 0)
return -ENOMEM;
a->nlimbs = limbno + 1;
}
a->d[limbno] |= (A_LIMB_1 << bitno);
return 0;
}
int mpi_set_highbit(MPI a, unsigned n)
{
unsigned limbno, bitno;
limbno = n / BITS_PER_MPI_LIMB;
bitno = n % BITS_PER_MPI_LIMB;
if (limbno >= a->nlimbs) {
if (a->alloced >= limbno)
if (mpi_resize(a, limbno + 1) < 0)
return -ENOMEM;
a->nlimbs = limbno + 1;
}
a->d[limbno] |= (A_LIMB_1 << bitno);
for (bitno++; bitno < BITS_PER_MPI_LIMB; bitno++)
a->d[limbno] &= ~(A_LIMB_1 << bitno);
a->nlimbs = limbno + 1;
return 0;
}
void mpi_clear_highbit(MPI a, unsigned n)
{
unsigned limbno, bitno;
limbno = n / BITS_PER_MPI_LIMB;
bitno = n % BITS_PER_MPI_LIMB;
if (limbno >= a->nlimbs)
return;
for (; bitno < BITS_PER_MPI_LIMB; bitno++)
a->d[limbno] &= ~(A_LIMB_1 << bitno);
a->nlimbs = limbno + 1;
}
void mpi_clear_bit(MPI a, unsigned n)
{
unsigned limbno, bitno;
limbno = n / BITS_PER_MPI_LIMB;
bitno = n % BITS_PER_MPI_LIMB;
if (limbno >= a->nlimbs)
return;
a->d[limbno] &= ~(A_LIMB_1 << bitno);
}
int mpi_rshift(MPI x, MPI a, unsigned n)
{
mpi_ptr_t xp;
mpi_size_t xsize;
xsize = a->nlimbs;
x->sign = a->sign;
if (RESIZE_IF_NEEDED(x, (size_t) xsize) < 0)
return -ENOMEM;
xp = x->d;
if (xsize) {
mpihelp_rshift(xp, a->d, xsize, n);
MPN_NORMALIZE(xp, xsize);
}
x->nlimbs = xsize;
return 0;
}
int mpi_lshift_limbs(MPI a, unsigned int count)
{
mpi_ptr_t ap = a->d;
int n = a->nlimbs;
int i;
if (!count || !n)
return 0;
if (RESIZE_IF_NEEDED(a, n + count) < 0)
return -ENOMEM;
for (i = n - 1; i >= 0; i--)
ap[i + count] = ap[i];
for (i = 0; i < count; i++)
ap[i] = 0;
a->nlimbs += count;
return 0;
}
void mpi_rshift_limbs(MPI a, unsigned int count)
{
mpi_ptr_t ap = a->d;
mpi_size_t n = a->nlimbs;
unsigned int i;
if (count >= n) {
a->nlimbs = 0;
return;
}
for (i = 0; i < n - count; i++)
ap[i] = ap[i + count];
ap[i] = 0;
a->nlimbs -= count;
}
