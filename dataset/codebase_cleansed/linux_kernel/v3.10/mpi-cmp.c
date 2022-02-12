int mpi_cmp_ui(MPI u, unsigned long v)
{
mpi_limb_t limb = v;
mpi_normalize(u);
if (!u->nlimbs && !limb)
return 0;
if (u->sign)
return -1;
if (u->nlimbs > 1)
return 1;
if (u->d[0] == limb)
return 0;
else if (u->d[0] > limb)
return 1;
else
return -1;
}
int mpi_cmp(MPI u, MPI v)
{
mpi_size_t usize, vsize;
int cmp;
mpi_normalize(u);
mpi_normalize(v);
usize = u->nlimbs;
vsize = v->nlimbs;
if (!u->sign && v->sign)
return 1;
if (u->sign && !v->sign)
return -1;
if (usize != vsize && !u->sign && !v->sign)
return usize - vsize;
if (usize != vsize && u->sign && v->sign)
return vsize + usize;
if (!usize)
return 0;
cmp = mpihelp_cmp(u->d, v->d, usize);
if (!cmp)
return 0;
if ((cmp < 0 ? 1 : 0) == (u->sign ? 1 : 0))
return 1;
return -1;
}
