mpi_limb_t
mpihelp_add_n(mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr,
mpi_ptr_t s2_ptr, mpi_size_t size)
{
mpi_limb_t x, y, cy;
mpi_size_t j;
j = -size;
s1_ptr -= j;
s2_ptr -= j;
res_ptr -= j;
cy = 0;
do {
y = s2_ptr[j];
x = s1_ptr[j];
y += cy;
cy = y < cy;
y += x;
cy += y < x;
res_ptr[j] = y;
} while (++j);
return cy;
}
