static void cvmx_boot_vector_init(void *mem)
{
uint64_t kseg0_mem;
int i;
memset(mem, 0, VECTOR_TABLE_SIZE);
kseg0_mem = cvmx_ptr_to_phys(mem) | 0x8000000000000000ull;
for (i = 0; i < 15; i++) {
uint64_t v = _cvmx_bootvector_data[i];
if (OCTEON_IS_OCTEON1PLUS() && (i == 0 || i == 7))
v &= 0xffffffff00000000ull;
cvmx_write_csr(CVMX_MIO_BOOT_LOC_ADR, i * 8);
cvmx_write_csr(CVMX_MIO_BOOT_LOC_DAT, v);
}
cvmx_write_csr(CVMX_MIO_BOOT_LOC_ADR, 15 * 8);
cvmx_write_csr(CVMX_MIO_BOOT_LOC_DAT, kseg0_mem);
cvmx_write_csr(CVMX_MIO_BOOT_LOC_CFGX(0), 0x81fc0000);
}
struct cvmx_boot_vector_element *cvmx_boot_vector_get(void)
{
struct cvmx_boot_vector_element *ret;
ret = cvmx_bootmem_alloc_named_range_once(VECTOR_TABLE_SIZE, 0,
(1ull << 32) - 1, 8, "__boot_vector1__", cvmx_boot_vector_init);
return ret;
}
