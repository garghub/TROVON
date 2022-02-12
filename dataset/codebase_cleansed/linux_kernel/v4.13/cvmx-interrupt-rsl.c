void __cvmx_interrupt_asxx_enable(int block)
{
int mask;
union cvmx_asxx_int_en csr;
if (OCTEON_IS_MODEL(OCTEON_CN38XX) || OCTEON_IS_MODEL(OCTEON_CN58XX))
mask = 0xf;
else
mask = 0x7;
csr.u64 = cvmx_read_csr(CVMX_ASXX_INT_EN(block));
csr.s.txpsh = mask;
csr.s.txpop = mask;
csr.s.ovrflw = mask;
cvmx_write_csr(CVMX_ASXX_INT_EN(block), csr.u64);
}
void __cvmx_interrupt_gmxx_enable(int interface)
{
union cvmx_gmxx_inf_mode mode;
union cvmx_gmxx_tx_int_en gmx_tx_int_en;
int num_ports;
int index;
mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));
if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX)) {
if (mode.s.en) {
switch (mode.cn56xx.mode) {
case 1:
num_ports = 1;
break;
case 2:
case 3:
num_ports = 4;
break;
default:
num_ports = 0;
break;
}
} else
num_ports = 0;
} else {
if (mode.s.en) {
if (OCTEON_IS_MODEL(OCTEON_CN38XX)
|| OCTEON_IS_MODEL(OCTEON_CN58XX)) {
if (mode.s.type)
num_ports = 1;
else
num_ports = 4;
} else {
if (mode.s.type)
num_ports = 2;
else
num_ports = 3;
}
} else
num_ports = 0;
}
gmx_tx_int_en.u64 = 0;
if (num_ports) {
if (OCTEON_IS_MODEL(OCTEON_CN38XX)
|| OCTEON_IS_MODEL(OCTEON_CN58XX))
gmx_tx_int_en.cn38xx.ncb_nxa = 1;
gmx_tx_int_en.s.pko_nxa = 1;
}
gmx_tx_int_en.s.undflw = (1 << num_ports) - 1;
cvmx_write_csr(CVMX_GMXX_TX_INT_EN(interface), gmx_tx_int_en.u64);
for (index = 0; index < num_ports; index++)
__cvmx_interrupt_gmxx_rxx_int_en_enable(index, interface);
}
