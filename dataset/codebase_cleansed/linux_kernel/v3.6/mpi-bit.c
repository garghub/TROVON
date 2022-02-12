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
