void cvmx_spi_get_callbacks(cvmx_spi_callbacks_t *callbacks)
{
memcpy(callbacks, &cvmx_spi_callbacks, sizeof(cvmx_spi_callbacks));
}
void cvmx_spi_set_callbacks(cvmx_spi_callbacks_t *new_callbacks)
{
memcpy(&cvmx_spi_callbacks, new_callbacks, sizeof(cvmx_spi_callbacks));
}
int cvmx_spi_start_interface(int interface, cvmx_spi_mode_t mode, int timeout,
int num_ports)
{
int res = -1;
if (!(OCTEON_IS_MODEL(OCTEON_CN38XX) || OCTEON_IS_MODEL(OCTEON_CN58XX)))
return res;
INVOKE_CB(cvmx_spi_callbacks.reset_cb, interface, mode);
INVOKE_CB(cvmx_spi_callbacks.calendar_setup_cb, interface, mode,
num_ports);
INVOKE_CB(cvmx_spi_callbacks.clock_detect_cb, interface, mode, timeout);
INVOKE_CB(cvmx_spi_callbacks.training_cb, interface, mode, timeout);
INVOKE_CB(cvmx_spi_callbacks.calendar_sync_cb, interface, mode,
timeout);
INVOKE_CB(cvmx_spi_callbacks.interface_up_cb, interface, mode);
return res;
}
int cvmx_spi_restart_interface(int interface, cvmx_spi_mode_t mode, int timeout)
{
int res = -1;
if (!(OCTEON_IS_MODEL(OCTEON_CN38XX) || OCTEON_IS_MODEL(OCTEON_CN58XX)))
return res;
cvmx_dprintf("SPI%d: Restart %s\n", interface, modes[mode]);
INVOKE_CB(cvmx_spi_callbacks.reset_cb, interface, mode);
INVOKE_CB(cvmx_spi_callbacks.clock_detect_cb, interface, mode, timeout);
INVOKE_CB(cvmx_spi_callbacks.training_cb, interface, mode, timeout);
INVOKE_CB(cvmx_spi_callbacks.calendar_sync_cb, interface, mode,
timeout);
INVOKE_CB(cvmx_spi_callbacks.interface_up_cb, interface, mode);
return res;
}
int cvmx_spi_reset_cb(int interface, cvmx_spi_mode_t mode)
{
union cvmx_spxx_dbg_deskew_ctl spxx_dbg_deskew_ctl;
union cvmx_spxx_clk_ctl spxx_clk_ctl;
union cvmx_spxx_bist_stat spxx_bist_stat;
union cvmx_spxx_int_msk spxx_int_msk;
union cvmx_stxx_int_msk stxx_int_msk;
union cvmx_spxx_trn4_ctl spxx_trn4_ctl;
int index;
uint64_t MS = cvmx_sysinfo_get()->cpu_clock_hz / 1000;
spxx_int_msk.u64 = cvmx_read_csr(CVMX_SPXX_INT_MSK(interface));
cvmx_write_csr(CVMX_SPXX_INT_MSK(interface), 0);
stxx_int_msk.u64 = cvmx_read_csr(CVMX_STXX_INT_MSK(interface));
cvmx_write_csr(CVMX_STXX_INT_MSK(interface), 0);
cvmx_write_csr(CVMX_SRXX_COM_CTL(interface), 0);
cvmx_write_csr(CVMX_STXX_COM_CTL(interface), 0);
spxx_clk_ctl.u64 = 0;
spxx_clk_ctl.s.runbist = 1;
cvmx_write_csr(CVMX_SPXX_CLK_CTL(interface), spxx_clk_ctl.u64);
cvmx_wait(10 * MS);
spxx_bist_stat.u64 = cvmx_read_csr(CVMX_SPXX_BIST_STAT(interface));
if (spxx_bist_stat.s.stat0)
cvmx_dprintf
("ERROR SPI%d: BIST failed on receive datapath FIFO\n",
interface);
if (spxx_bist_stat.s.stat1)
cvmx_dprintf("ERROR SPI%d: BIST failed on RX calendar table\n",
interface);
if (spxx_bist_stat.s.stat2)
cvmx_dprintf("ERROR SPI%d: BIST failed on TX calendar table\n",
interface);
for (index = 0; index < 32; index++) {
union cvmx_srxx_spi4_calx srxx_spi4_calx;
union cvmx_stxx_spi4_calx stxx_spi4_calx;
srxx_spi4_calx.u64 = 0;
srxx_spi4_calx.s.oddpar = 1;
cvmx_write_csr(CVMX_SRXX_SPI4_CALX(index, interface),
srxx_spi4_calx.u64);
stxx_spi4_calx.u64 = 0;
stxx_spi4_calx.s.oddpar = 1;
cvmx_write_csr(CVMX_STXX_SPI4_CALX(index, interface),
stxx_spi4_calx.u64);
}
cvmx_write_csr(CVMX_SPXX_INT_REG(interface),
cvmx_read_csr(CVMX_SPXX_INT_REG(interface)));
cvmx_write_csr(CVMX_SPXX_INT_MSK(interface), spxx_int_msk.u64);
cvmx_write_csr(CVMX_STXX_INT_REG(interface),
cvmx_read_csr(CVMX_STXX_INT_REG(interface)));
cvmx_write_csr(CVMX_STXX_INT_MSK(interface), stxx_int_msk.u64);
spxx_clk_ctl.u64 = 0;
spxx_clk_ctl.s.seetrn = 0;
spxx_clk_ctl.s.clkdly = 0x10;
spxx_clk_ctl.s.runbist = 0;
spxx_clk_ctl.s.statdrv = 0;
spxx_clk_ctl.s.statrcv = 1;
spxx_clk_ctl.s.sndtrn = 0;
spxx_clk_ctl.s.drptrn = 0;
spxx_clk_ctl.s.rcvtrn = 0;
spxx_clk_ctl.s.srxdlck = 0;
cvmx_write_csr(CVMX_SPXX_CLK_CTL(interface), spxx_clk_ctl.u64);
cvmx_wait(100 * MS);
spxx_clk_ctl.s.srxdlck = 1;
cvmx_write_csr(CVMX_SPXX_CLK_CTL(interface), spxx_clk_ctl.u64);
cvmx_wait(100 * MS);
spxx_trn4_ctl.s.trntest = 0;
spxx_trn4_ctl.s.jitter = 1;
spxx_trn4_ctl.s.clr_boot = 1;
spxx_trn4_ctl.s.set_boot = 0;
if (OCTEON_IS_MODEL(OCTEON_CN58XX))
spxx_trn4_ctl.s.maxdist = 3;
else
spxx_trn4_ctl.s.maxdist = 8;
spxx_trn4_ctl.s.macro_en = 1;
spxx_trn4_ctl.s.mux_en = 1;
cvmx_write_csr(CVMX_SPXX_TRN4_CTL(interface), spxx_trn4_ctl.u64);
spxx_dbg_deskew_ctl.u64 = 0;
cvmx_write_csr(CVMX_SPXX_DBG_DESKEW_CTL(interface),
spxx_dbg_deskew_ctl.u64);
return 0;
}
int cvmx_spi_calendar_setup_cb(int interface, cvmx_spi_mode_t mode,
int num_ports)
{
int port;
int index;
if (mode & CVMX_SPI_MODE_RX_HALFPLEX) {
union cvmx_srxx_com_ctl srxx_com_ctl;
union cvmx_srxx_spi4_stat srxx_spi4_stat;
srxx_com_ctl.u64 = 0;
srxx_com_ctl.s.prts = num_ports - 1;
srxx_com_ctl.s.st_en = 0;
srxx_com_ctl.s.inf_en = 0;
cvmx_write_csr(CVMX_SRXX_COM_CTL(interface), srxx_com_ctl.u64);
port = 0;
index = 0;
while (port < num_ports) {
union cvmx_srxx_spi4_calx srxx_spi4_calx;
srxx_spi4_calx.u64 = 0;
srxx_spi4_calx.s.prt0 = port++;
srxx_spi4_calx.s.prt1 = port++;
srxx_spi4_calx.s.prt2 = port++;
srxx_spi4_calx.s.prt3 = port++;
srxx_spi4_calx.s.oddpar =
~(cvmx_dpop(srxx_spi4_calx.u64) & 1);
cvmx_write_csr(CVMX_SRXX_SPI4_CALX(index, interface),
srxx_spi4_calx.u64);
index++;
}
srxx_spi4_stat.u64 = 0;
srxx_spi4_stat.s.len = num_ports;
srxx_spi4_stat.s.m = 1;
cvmx_write_csr(CVMX_SRXX_SPI4_STAT(interface),
srxx_spi4_stat.u64);
}
if (mode & CVMX_SPI_MODE_TX_HALFPLEX) {
union cvmx_stxx_arb_ctl stxx_arb_ctl;
union cvmx_gmxx_tx_spi_max gmxx_tx_spi_max;
union cvmx_gmxx_tx_spi_thresh gmxx_tx_spi_thresh;
union cvmx_gmxx_tx_spi_ctl gmxx_tx_spi_ctl;
union cvmx_stxx_spi4_stat stxx_spi4_stat;
union cvmx_stxx_spi4_dat stxx_spi4_dat;
stxx_arb_ctl.u64 = 0;
stxx_arb_ctl.s.igntpa = 0;
stxx_arb_ctl.s.mintrn = 0;
cvmx_write_csr(CVMX_STXX_ARB_CTL(interface), stxx_arb_ctl.u64);
gmxx_tx_spi_max.u64 = 0;
gmxx_tx_spi_max.s.max1 = 8;
gmxx_tx_spi_max.s.max2 = 4;
gmxx_tx_spi_max.s.slice = 0;
cvmx_write_csr(CVMX_GMXX_TX_SPI_MAX(interface),
gmxx_tx_spi_max.u64);
gmxx_tx_spi_thresh.u64 = 0;
gmxx_tx_spi_thresh.s.thresh = 4;
cvmx_write_csr(CVMX_GMXX_TX_SPI_THRESH(interface),
gmxx_tx_spi_thresh.u64);
gmxx_tx_spi_ctl.u64 = 0;
gmxx_tx_spi_ctl.s.tpa_clr = 0;
gmxx_tx_spi_ctl.s.cont_pkt = 0;
cvmx_write_csr(CVMX_GMXX_TX_SPI_CTL(interface),
gmxx_tx_spi_ctl.u64);
stxx_spi4_dat.u64 = 0;
stxx_spi4_dat.s.alpha = 32;
stxx_spi4_dat.s.max_t = 0xFFFF;
cvmx_write_csr(CVMX_STXX_SPI4_DAT(interface),
stxx_spi4_dat.u64);
port = 0;
index = 0;
while (port < num_ports) {
union cvmx_stxx_spi4_calx stxx_spi4_calx;
stxx_spi4_calx.u64 = 0;
stxx_spi4_calx.s.prt0 = port++;
stxx_spi4_calx.s.prt1 = port++;
stxx_spi4_calx.s.prt2 = port++;
stxx_spi4_calx.s.prt3 = port++;
stxx_spi4_calx.s.oddpar =
~(cvmx_dpop(stxx_spi4_calx.u64) & 1);
cvmx_write_csr(CVMX_STXX_SPI4_CALX(index, interface),
stxx_spi4_calx.u64);
index++;
}
stxx_spi4_stat.u64 = 0;
stxx_spi4_stat.s.len = num_ports;
stxx_spi4_stat.s.m = 1;
cvmx_write_csr(CVMX_STXX_SPI4_STAT(interface),
stxx_spi4_stat.u64);
}
return 0;
}
int cvmx_spi_clock_detect_cb(int interface, cvmx_spi_mode_t mode, int timeout)
{
int clock_transitions;
union cvmx_spxx_clk_stat stat;
uint64_t timeout_time;
uint64_t MS = cvmx_sysinfo_get()->cpu_clock_hz / 1000;
cvmx_dprintf("SPI%d: Waiting to see TsClk...\n", interface);
timeout_time = cvmx_get_cycle() + 1000ull * MS * timeout;
clock_transitions = 100;
do {
stat.u64 = cvmx_read_csr(CVMX_SPXX_CLK_STAT(interface));
if (stat.s.s4clk0 && stat.s.s4clk1 && clock_transitions) {
clock_transitions--;
cvmx_write_csr(CVMX_SPXX_CLK_STAT(interface), stat.u64);
stat.s.s4clk0 = 0;
stat.s.s4clk1 = 0;
}
if (cvmx_get_cycle() > timeout_time) {
cvmx_dprintf("SPI%d: Timeout\n", interface);
return -1;
}
} while (stat.s.s4clk0 == 0 || stat.s.s4clk1 == 0);
cvmx_dprintf("SPI%d: Waiting to see RsClk...\n", interface);
timeout_time = cvmx_get_cycle() + 1000ull * MS * timeout;
clock_transitions = 100;
do {
stat.u64 = cvmx_read_csr(CVMX_SPXX_CLK_STAT(interface));
if (stat.s.d4clk0 && stat.s.d4clk1 && clock_transitions) {
clock_transitions--;
cvmx_write_csr(CVMX_SPXX_CLK_STAT(interface), stat.u64);
stat.s.d4clk0 = 0;
stat.s.d4clk1 = 0;
}
if (cvmx_get_cycle() > timeout_time) {
cvmx_dprintf("SPI%d: Timeout\n", interface);
return -1;
}
} while (stat.s.d4clk0 == 0 || stat.s.d4clk1 == 0);
return 0;
}
int cvmx_spi_training_cb(int interface, cvmx_spi_mode_t mode, int timeout)
{
union cvmx_spxx_trn4_ctl spxx_trn4_ctl;
union cvmx_spxx_clk_stat stat;
uint64_t MS = cvmx_sysinfo_get()->cpu_clock_hz / 1000;
uint64_t timeout_time = cvmx_get_cycle() + 1000ull * MS * timeout;
int rx_training_needed;
union cvmx_spxx_clk_ctl spxx_clk_ctl;
spxx_clk_ctl.u64 = 0;
spxx_clk_ctl.s.seetrn = 0;
spxx_clk_ctl.s.clkdly = 0x10;
spxx_clk_ctl.s.runbist = 0;
spxx_clk_ctl.s.statdrv = 0;
spxx_clk_ctl.s.statrcv = 1;
spxx_clk_ctl.s.sndtrn = 1;
spxx_clk_ctl.s.drptrn = 1;
spxx_clk_ctl.s.rcvtrn = 1;
spxx_clk_ctl.s.srxdlck = 1;
cvmx_write_csr(CVMX_SPXX_CLK_CTL(interface), spxx_clk_ctl.u64);
cvmx_wait(1000 * MS);
spxx_trn4_ctl.u64 = cvmx_read_csr(CVMX_SPXX_TRN4_CTL(interface));
spxx_trn4_ctl.s.clr_boot = 1;
cvmx_write_csr(CVMX_SPXX_TRN4_CTL(interface), spxx_trn4_ctl.u64);
cvmx_dprintf("SPI%d: Waiting for training\n", interface);
cvmx_wait(1000 * MS);
timeout_time = cvmx_get_cycle() + 1000ull * MS * 600;
rx_training_needed = 500;
do {
stat.u64 = cvmx_read_csr(CVMX_SPXX_CLK_STAT(interface));
if (stat.s.srxtrn && rx_training_needed) {
rx_training_needed--;
cvmx_write_csr(CVMX_SPXX_CLK_STAT(interface), stat.u64);
stat.s.srxtrn = 0;
}
if (cvmx_get_cycle() > timeout_time) {
cvmx_dprintf("SPI%d: Timeout\n", interface);
return -1;
}
} while (stat.s.srxtrn == 0);
return 0;
}
int cvmx_spi_calendar_sync_cb(int interface, cvmx_spi_mode_t mode, int timeout)
{
uint64_t MS = cvmx_sysinfo_get()->cpu_clock_hz / 1000;
if (mode & CVMX_SPI_MODE_RX_HALFPLEX) {
union cvmx_srxx_com_ctl srxx_com_ctl;
cvmx_dprintf
("SPI%d: Rx is synchronized, start sending calendar data\n",
interface);
srxx_com_ctl.u64 = cvmx_read_csr(CVMX_SRXX_COM_CTL(interface));
srxx_com_ctl.s.inf_en = 1;
srxx_com_ctl.s.st_en = 1;
cvmx_write_csr(CVMX_SRXX_COM_CTL(interface), srxx_com_ctl.u64);
}
if (mode & CVMX_SPI_MODE_TX_HALFPLEX) {
union cvmx_spxx_clk_stat stat;
uint64_t timeout_time;
union cvmx_stxx_com_ctl stxx_com_ctl;
stxx_com_ctl.u64 = 0;
stxx_com_ctl.s.st_en = 1;
cvmx_write_csr(CVMX_STXX_COM_CTL(interface), stxx_com_ctl.u64);
cvmx_dprintf("SPI%d: Waiting to sync on STX[%d] STAT\n",
interface, interface);
timeout_time = cvmx_get_cycle() + 1000ull * MS * timeout;
do {
stat.u64 = cvmx_read_csr(CVMX_SPXX_CLK_STAT(interface));
if (cvmx_get_cycle() > timeout_time) {
cvmx_dprintf("SPI%d: Timeout\n", interface);
return -1;
}
} while (stat.s.stxcal == 0);
}
return 0;
}
int cvmx_spi_interface_up_cb(int interface, cvmx_spi_mode_t mode)
{
union cvmx_gmxx_rxx_frm_min gmxx_rxx_frm_min;
union cvmx_gmxx_rxx_frm_max gmxx_rxx_frm_max;
union cvmx_gmxx_rxx_jabber gmxx_rxx_jabber;
if (mode & CVMX_SPI_MODE_RX_HALFPLEX) {
union cvmx_srxx_com_ctl srxx_com_ctl;
srxx_com_ctl.u64 = cvmx_read_csr(CVMX_SRXX_COM_CTL(interface));
srxx_com_ctl.s.inf_en = 1;
cvmx_write_csr(CVMX_SRXX_COM_CTL(interface), srxx_com_ctl.u64);
cvmx_dprintf("SPI%d: Rx is now up\n", interface);
}
if (mode & CVMX_SPI_MODE_TX_HALFPLEX) {
union cvmx_stxx_com_ctl stxx_com_ctl;
stxx_com_ctl.u64 = cvmx_read_csr(CVMX_STXX_COM_CTL(interface));
stxx_com_ctl.s.inf_en = 1;
cvmx_write_csr(CVMX_STXX_COM_CTL(interface), stxx_com_ctl.u64);
cvmx_dprintf("SPI%d: Tx is now up\n", interface);
}
gmxx_rxx_frm_min.u64 = 0;
gmxx_rxx_frm_min.s.len = 64;
cvmx_write_csr(CVMX_GMXX_RXX_FRM_MIN(0, interface),
gmxx_rxx_frm_min.u64);
gmxx_rxx_frm_max.u64 = 0;
gmxx_rxx_frm_max.s.len = 64 * 1024 - 4;
cvmx_write_csr(CVMX_GMXX_RXX_FRM_MAX(0, interface),
gmxx_rxx_frm_max.u64);
gmxx_rxx_jabber.u64 = 0;
gmxx_rxx_jabber.s.cnt = 64 * 1024 - 4;
cvmx_write_csr(CVMX_GMXX_RXX_JABBER(0, interface), gmxx_rxx_jabber.u64);
return 0;
}
