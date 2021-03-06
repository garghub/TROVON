void __cvmx_interrupt_gmxx_rxx_int_en_enable(int index, int block)
{
union cvmx_gmxx_rxx_int_en gmx_rx_int_en;
cvmx_write_csr(CVMX_GMXX_RXX_INT_REG(index, block),
cvmx_read_csr(CVMX_GMXX_RXX_INT_REG(index, block)));
gmx_rx_int_en.u64 = 0;
if (OCTEON_IS_MODEL(OCTEON_CN56XX)) {
gmx_rx_int_en.s.hg2cc = 1;
gmx_rx_int_en.s.hg2fld = 1;
gmx_rx_int_en.s.undat = 1;
gmx_rx_int_en.s.uneop = 1;
gmx_rx_int_en.s.unsop = 1;
gmx_rx_int_en.s.bad_term = 1;
gmx_rx_int_en.s.bad_seq = 1;
gmx_rx_int_en.s.rem_fault = 1;
gmx_rx_int_en.s.loc_fault = 1;
gmx_rx_int_en.s.pause_drp = 1;
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.carext = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN30XX)) {
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.niberr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.alnerr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.maxerr = 1;
gmx_rx_int_en.s.carext = 1;
gmx_rx_int_en.s.minerr = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN50XX)) {
gmx_rx_int_en.s.pause_drp = 1;
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.niberr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.alnerr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.carext = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN38XX)) {
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.niberr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.alnerr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.maxerr = 1;
gmx_rx_int_en.s.carext = 1;
gmx_rx_int_en.s.minerr = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN31XX)) {
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.niberr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.alnerr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.maxerr = 1;
gmx_rx_int_en.s.carext = 1;
gmx_rx_int_en.s.minerr = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN58XX)) {
gmx_rx_int_en.s.pause_drp = 1;
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.niberr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.alnerr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.maxerr = 1;
gmx_rx_int_en.s.carext = 1;
gmx_rx_int_en.s.minerr = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX)) {
gmx_rx_int_en.s.hg2cc = 1;
gmx_rx_int_en.s.hg2fld = 1;
gmx_rx_int_en.s.undat = 1;
gmx_rx_int_en.s.uneop = 1;
gmx_rx_int_en.s.unsop = 1;
gmx_rx_int_en.s.bad_term = 1;
gmx_rx_int_en.s.bad_seq = 0;
gmx_rx_int_en.s.rem_fault = 1;
gmx_rx_int_en.s.loc_fault = 0;
gmx_rx_int_en.s.pause_drp = 1;
gmx_rx_int_en.s.ovrerr = 1;
gmx_rx_int_en.s.skperr = 1;
gmx_rx_int_en.s.rcverr = 1;
gmx_rx_int_en.s.jabber = 1;
gmx_rx_int_en.s.carext = 1;
}
cvmx_write_csr(CVMX_GMXX_RXX_INT_EN(index, block), gmx_rx_int_en.u64);
}
void __cvmx_interrupt_pcsx_intx_en_reg_enable(int index, int block)
{
union cvmx_pcsx_intx_en_reg pcs_int_en_reg;
cvmx_write_csr(CVMX_PCSX_INTX_REG(index, block),
cvmx_read_csr(CVMX_PCSX_INTX_REG(index, block)));
pcs_int_en_reg.u64 = 0;
if (OCTEON_IS_MODEL(OCTEON_CN56XX)) {
pcs_int_en_reg.s.sync_bad_en = 1;
pcs_int_en_reg.s.an_bad_en = 1;
pcs_int_en_reg.s.rxlock_en = 1;
pcs_int_en_reg.s.rxbad_en = 1;
pcs_int_en_reg.s.txbad_en = 1;
pcs_int_en_reg.s.txfifo_en = 1;
pcs_int_en_reg.s.txfifu_en = 1;
pcs_int_en_reg.s.an_err_en = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX)) {
pcs_int_en_reg.s.sync_bad_en = 1;
pcs_int_en_reg.s.an_bad_en = 1;
pcs_int_en_reg.s.rxlock_en = 1;
pcs_int_en_reg.s.rxbad_en = 1;
pcs_int_en_reg.s.txbad_en = 1;
pcs_int_en_reg.s.txfifo_en = 1;
pcs_int_en_reg.s.txfifu_en = 1;
pcs_int_en_reg.s.an_err_en = 1;
}
cvmx_write_csr(CVMX_PCSX_INTX_EN_REG(index, block), pcs_int_en_reg.u64);
}
void __cvmx_interrupt_pcsxx_int_en_reg_enable(int index)
{
union cvmx_pcsxx_int_en_reg pcsx_int_en_reg;
cvmx_write_csr(CVMX_PCSXX_INT_REG(index),
cvmx_read_csr(CVMX_PCSXX_INT_REG(index)));
pcsx_int_en_reg.u64 = 0;
if (OCTEON_IS_MODEL(OCTEON_CN56XX)) {
pcsx_int_en_reg.s.algnlos_en = 1;
pcsx_int_en_reg.s.synlos_en = 1;
pcsx_int_en_reg.s.bitlckls_en = 1;
pcsx_int_en_reg.s.rxsynbad_en = 1;
pcsx_int_en_reg.s.rxbad_en = 1;
pcsx_int_en_reg.s.txflt_en = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX)) {
pcsx_int_en_reg.s.algnlos_en = 1;
pcsx_int_en_reg.s.synlos_en = 1;
pcsx_int_en_reg.s.bitlckls_en = 0;
pcsx_int_en_reg.s.rxsynbad_en = 1;
pcsx_int_en_reg.s.rxbad_en = 1;
pcsx_int_en_reg.s.txflt_en = 1;
}
cvmx_write_csr(CVMX_PCSXX_INT_EN_REG(index), pcsx_int_en_reg.u64);
}
void __cvmx_interrupt_spxx_int_msk_enable(int index)
{
union cvmx_spxx_int_msk spx_int_msk;
cvmx_write_csr(CVMX_SPXX_INT_REG(index),
cvmx_read_csr(CVMX_SPXX_INT_REG(index)));
spx_int_msk.u64 = 0;
if (OCTEON_IS_MODEL(OCTEON_CN38XX)) {
spx_int_msk.s.calerr = 1;
spx_int_msk.s.syncerr = 1;
spx_int_msk.s.diperr = 1;
spx_int_msk.s.tpaovr = 1;
spx_int_msk.s.rsverr = 1;
spx_int_msk.s.drwnng = 1;
spx_int_msk.s.clserr = 1;
spx_int_msk.s.spiovr = 1;
spx_int_msk.s.abnorm = 1;
spx_int_msk.s.prtnxa = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN58XX)) {
spx_int_msk.s.calerr = 1;
spx_int_msk.s.syncerr = 1;
spx_int_msk.s.diperr = 1;
spx_int_msk.s.tpaovr = 1;
spx_int_msk.s.rsverr = 1;
spx_int_msk.s.drwnng = 1;
spx_int_msk.s.clserr = 1;
spx_int_msk.s.spiovr = 1;
spx_int_msk.s.abnorm = 1;
spx_int_msk.s.prtnxa = 1;
}
cvmx_write_csr(CVMX_SPXX_INT_MSK(index), spx_int_msk.u64);
}
void __cvmx_interrupt_stxx_int_msk_enable(int index)
{
union cvmx_stxx_int_msk stx_int_msk;
cvmx_write_csr(CVMX_STXX_INT_REG(index),
cvmx_read_csr(CVMX_STXX_INT_REG(index)));
stx_int_msk.u64 = 0;
if (OCTEON_IS_MODEL(OCTEON_CN38XX)) {
stx_int_msk.s.frmerr = 1;
stx_int_msk.s.unxfrm = 1;
stx_int_msk.s.nosync = 1;
stx_int_msk.s.diperr = 1;
stx_int_msk.s.datovr = 1;
stx_int_msk.s.ovrbst = 1;
stx_int_msk.s.calpar1 = 1;
stx_int_msk.s.calpar0 = 1;
}
if (OCTEON_IS_MODEL(OCTEON_CN58XX)) {
stx_int_msk.s.frmerr = 1;
stx_int_msk.s.unxfrm = 1;
stx_int_msk.s.nosync = 1;
stx_int_msk.s.diperr = 1;
stx_int_msk.s.datovr = 1;
stx_int_msk.s.ovrbst = 1;
stx_int_msk.s.calpar1 = 1;
stx_int_msk.s.calpar0 = 1;
}
cvmx_write_csr(CVMX_STXX_INT_MSK(index), stx_int_msk.u64);
}
