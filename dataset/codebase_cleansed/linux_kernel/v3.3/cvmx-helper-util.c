const char *cvmx_helper_interface_mode_to_string(cvmx_helper_interface_mode_t
mode)
{
switch (mode) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
return "DISABLED";
case CVMX_HELPER_INTERFACE_MODE_RGMII:
return "RGMII";
case CVMX_HELPER_INTERFACE_MODE_GMII:
return "GMII";
case CVMX_HELPER_INTERFACE_MODE_SPI:
return "SPI";
case CVMX_HELPER_INTERFACE_MODE_PCIE:
return "PCIE";
case CVMX_HELPER_INTERFACE_MODE_XAUI:
return "XAUI";
case CVMX_HELPER_INTERFACE_MODE_SGMII:
return "SGMII";
case CVMX_HELPER_INTERFACE_MODE_PICMG:
return "PICMG";
case CVMX_HELPER_INTERFACE_MODE_NPI:
return "NPI";
case CVMX_HELPER_INTERFACE_MODE_LOOP:
return "LOOP";
}
return "UNKNOWN";
}
int cvmx_helper_dump_packet(cvmx_wqe_t *work)
{
uint64_t count;
uint64_t remaining_bytes;
union cvmx_buf_ptr buffer_ptr;
uint64_t start_of_buffer;
uint8_t *data_address;
uint8_t *end_of_data;
cvmx_dprintf("Packet Length: %u\n", work->len);
cvmx_dprintf(" Input Port: %u\n", work->ipprt);
cvmx_dprintf(" QoS: %u\n", work->qos);
cvmx_dprintf(" Buffers: %u\n", work->word2.s.bufs);
if (work->word2.s.bufs == 0) {
union cvmx_ipd_wqe_fpa_queue wqe_pool;
wqe_pool.u64 = cvmx_read_csr(CVMX_IPD_WQE_FPA_QUEUE);
buffer_ptr.u64 = 0;
buffer_ptr.s.pool = wqe_pool.s.wqe_pool;
buffer_ptr.s.size = 128;
buffer_ptr.s.addr = cvmx_ptr_to_phys(work->packet_data);
if (likely(!work->word2.s.not_IP)) {
union cvmx_pip_ip_offset pip_ip_offset;
pip_ip_offset.u64 = cvmx_read_csr(CVMX_PIP_IP_OFFSET);
buffer_ptr.s.addr +=
(pip_ip_offset.s.offset << 3) -
work->word2.s.ip_offset;
buffer_ptr.s.addr += (work->word2.s.is_v6 ^ 1) << 2;
} else {
union cvmx_pip_gbl_cfg pip_gbl_cfg;
pip_gbl_cfg.u64 = cvmx_read_csr(CVMX_PIP_GBL_CFG);
buffer_ptr.s.addr += pip_gbl_cfg.s.nip_shf;
}
} else
buffer_ptr = work->packet_ptr;
remaining_bytes = work->len;
while (remaining_bytes) {
start_of_buffer =
((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
cvmx_dprintf(" Buffer Start:%llx\n",
(unsigned long long)start_of_buffer);
cvmx_dprintf(" Buffer I : %u\n", buffer_ptr.s.i);
cvmx_dprintf(" Buffer Back: %u\n", buffer_ptr.s.back);
cvmx_dprintf(" Buffer Pool: %u\n", buffer_ptr.s.pool);
cvmx_dprintf(" Buffer Data: %llx\n",
(unsigned long long)buffer_ptr.s.addr);
cvmx_dprintf(" Buffer Size: %u\n", buffer_ptr.s.size);
cvmx_dprintf("\t\t");
data_address = (uint8_t *) cvmx_phys_to_ptr(buffer_ptr.s.addr);
end_of_data = data_address + buffer_ptr.s.size;
count = 0;
while (data_address < end_of_data) {
if (remaining_bytes == 0)
break;
else
remaining_bytes--;
cvmx_dprintf("%02x", (unsigned int)*data_address);
data_address++;
if (remaining_bytes && (count == 7)) {
cvmx_dprintf("\n\t\t");
count = 0;
} else
count++;
}
cvmx_dprintf("\n");
if (remaining_bytes)
buffer_ptr = *(union cvmx_buf_ptr *)
cvmx_phys_to_ptr(buffer_ptr.s.addr - 8);
}
return 0;
}
int cvmx_helper_setup_red_queue(int queue, int pass_thresh, int drop_thresh)
{
union cvmx_ipd_qosx_red_marks red_marks;
union cvmx_ipd_red_quex_param red_param;
red_marks.u64 = 0;
red_marks.s.drop = drop_thresh;
red_marks.s.pass = pass_thresh;
cvmx_write_csr(CVMX_IPD_QOSX_RED_MARKS(queue), red_marks.u64);
red_param.u64 = 0;
red_param.s.prb_con =
(255ul << 24) / (red_marks.s.pass - red_marks.s.drop);
red_param.s.avg_con = 1;
red_param.s.new_con = 255;
red_param.s.use_pcnt = 1;
cvmx_write_csr(CVMX_IPD_RED_QUEX_PARAM(queue), red_param.u64);
return 0;
}
int cvmx_helper_setup_red(int pass_thresh, int drop_thresh)
{
union cvmx_ipd_portx_bp_page_cnt page_cnt;
union cvmx_ipd_bp_prt_red_end ipd_bp_prt_red_end;
union cvmx_ipd_red_port_enable red_port_enable;
int queue;
int interface;
int port;
page_cnt.u64 = 0;
page_cnt.s.bp_enb = 0;
page_cnt.s.page_cnt = 100;
for (interface = 0; interface < 2; interface++) {
for (port = cvmx_helper_get_first_ipd_port(interface);
port < cvmx_helper_get_last_ipd_port(interface); port++)
cvmx_write_csr(CVMX_IPD_PORTX_BP_PAGE_CNT(port),
page_cnt.u64);
}
for (queue = 0; queue < 8; queue++)
cvmx_helper_setup_red_queue(queue, pass_thresh, drop_thresh);
ipd_bp_prt_red_end.u64 = 0;
ipd_bp_prt_red_end.s.prt_enb = 0;
cvmx_write_csr(CVMX_IPD_BP_PRT_RED_END, ipd_bp_prt_red_end.u64);
red_port_enable.u64 = 0;
red_port_enable.s.prt_enb = 0xfffffffffull;
red_port_enable.s.avg_dly = 10000;
red_port_enable.s.prb_dly = 10000;
cvmx_write_csr(CVMX_IPD_RED_PORT_ENABLE, red_port_enable.u64);
return 0;
}
int __cvmx_helper_setup_gmx(int interface, int num_ports)
{
union cvmx_gmxx_tx_prts gmx_tx_prts;
union cvmx_gmxx_rx_prts gmx_rx_prts;
union cvmx_pko_reg_gmx_port_mode pko_mode;
union cvmx_gmxx_txx_thresh gmx_tx_thresh;
int index;
gmx_tx_prts.u64 = cvmx_read_csr(CVMX_GMXX_TX_PRTS(interface));
gmx_tx_prts.s.prts = num_ports;
cvmx_write_csr(CVMX_GMXX_TX_PRTS(interface), gmx_tx_prts.u64);
if (cvmx_helper_interface_get_mode(interface) ==
CVMX_HELPER_INTERFACE_MODE_RGMII
|| cvmx_helper_interface_get_mode(interface) ==
CVMX_HELPER_INTERFACE_MODE_SGMII
|| cvmx_helper_interface_get_mode(interface) ==
CVMX_HELPER_INTERFACE_MODE_GMII
|| cvmx_helper_interface_get_mode(interface) ==
CVMX_HELPER_INTERFACE_MODE_XAUI) {
if (num_ports > 4) {
cvmx_dprintf("__cvmx_helper_setup_gmx: Illegal "
"num_ports\n");
return -1;
}
gmx_rx_prts.u64 = cvmx_read_csr(CVMX_GMXX_RX_PRTS(interface));
gmx_rx_prts.s.prts = num_ports;
cvmx_write_csr(CVMX_GMXX_RX_PRTS(interface), gmx_rx_prts.u64);
}
if (!OCTEON_IS_MODEL(OCTEON_CN30XX) && !OCTEON_IS_MODEL(OCTEON_CN31XX)
&& !OCTEON_IS_MODEL(OCTEON_CN50XX)) {
pko_mode.u64 = cvmx_read_csr(CVMX_PKO_REG_GMX_PORT_MODE);
if (interface == 0) {
if (num_ports == 1)
pko_mode.s.mode0 = 4;
else if (num_ports == 2)
pko_mode.s.mode0 = 3;
else if (num_ports <= 4)
pko_mode.s.mode0 = 2;
else if (num_ports <= 8)
pko_mode.s.mode0 = 1;
else
pko_mode.s.mode0 = 0;
} else {
if (num_ports == 1)
pko_mode.s.mode1 = 4;
else if (num_ports == 2)
pko_mode.s.mode1 = 3;
else if (num_ports <= 4)
pko_mode.s.mode1 = 2;
else if (num_ports <= 8)
pko_mode.s.mode1 = 1;
else
pko_mode.s.mode1 = 0;
}
cvmx_write_csr(CVMX_PKO_REG_GMX_PORT_MODE, pko_mode.u64);
}
gmx_tx_thresh.u64 = cvmx_read_csr(CVMX_GMXX_TXX_THRESH(0, interface));
if (OCTEON_IS_MODEL(OCTEON_CN30XX) || OCTEON_IS_MODEL(OCTEON_CN31XX)
|| OCTEON_IS_MODEL(OCTEON_CN50XX)) {
gmx_tx_thresh.s.cnt = 0x40;
} else {
if (num_ports <= 1)
gmx_tx_thresh.s.cnt = 0x100 / 1;
else if (num_ports == 2)
gmx_tx_thresh.s.cnt = 0x100 / 2;
else
gmx_tx_thresh.s.cnt = 0x100 / 4;
}
if (num_ports > 4)
num_ports = 4;
for (index = 0; index < num_ports; index++)
cvmx_write_csr(CVMX_GMXX_TXX_THRESH(index, interface),
gmx_tx_thresh.u64);
return 0;
}
int cvmx_helper_get_ipd_port(int interface, int port)
{
switch (interface) {
case 0:
return port;
case 1:
return port + 16;
case 2:
return port + 32;
case 3:
return port + 36;
}
return -1;
}
int cvmx_helper_get_interface_num(int ipd_port)
{
if (ipd_port < 16)
return 0;
else if (ipd_port < 32)
return 1;
else if (ipd_port < 36)
return 2;
else if (ipd_port < 40)
return 3;
else
cvmx_dprintf("cvmx_helper_get_interface_num: Illegal IPD "
"port number\n");
return -1;
}
int cvmx_helper_get_interface_index_num(int ipd_port)
{
if (ipd_port < 32)
return ipd_port & 15;
else if (ipd_port < 36)
return ipd_port & 3;
else if (ipd_port < 40)
return ipd_port & 3;
else
cvmx_dprintf("cvmx_helper_get_interface_index_num: "
"Illegal IPD port number\n");
return -1;
}
