int mpi_gcd(MPI g, const MPI xa, const MPI xb)
{
MPI a = NULL, b = NULL;
if (mpi_copy(&a, xa) < 0)
goto nomem;
if (mpi_copy(&b, xb) < 0)
goto nomem;
a->sign = 0;
b->sign = 0;
while (mpi_cmp_ui(b, 0)) {
if (mpi_fdiv_r(g, a, b) < 0)
goto nomem;
if (mpi_set(a, b) < 0)
goto nomem;
if (mpi_set(b, g) < 0)
goto nomem;
}
if (mpi_set(g, a) < 0)
goto nomem;
mpi_free(a);
mpi_free(b);
return !mpi_cmp_ui(g, 1);
nomem:
mpi_free(a);
mpi_free(b);
return -ENOMEM;
}
