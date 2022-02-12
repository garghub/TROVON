int mpihelp_cmp(mpi_ptr_t op1_ptr, mpi_ptr_t op2_ptr, mpi_size_t size)
{
mpi_size_t i;
mpi_limb_t op1_word, op2_word;
for (i = size - 1; i >= 0; i--) {
op1_word = op1_ptr[i];
op2_word = op2_ptr[i];
if (op1_word != op2_word)
goto diff;
}
return 0;
diff:
return (op1_word > op2_word) ? 1 : -1;
}
