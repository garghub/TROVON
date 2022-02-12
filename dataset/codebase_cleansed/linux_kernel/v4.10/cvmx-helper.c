int cvmx_helper_get_number_of_interfaces(void)
{
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
return 9;
if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX))
return 4;
if (OCTEON_IS_MODEL(OCTEON_CN7XXX))
return 5;
else
return 3;
}
int cvmx_helper_ports_on_interface(int interface)
{
return interface_port_count[interface];
}
static cvmx_helper_interface_mode_t __cvmx_get_mode_cn68xx(int interface)
{
union cvmx_mio_qlmx_cfg qlm_cfg;
switch (interface) {
case 0:
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(0));
if (qlm_cfg.s.qlm_spd == 15)
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (qlm_cfg.s.qlm_cfg == 2)
return CVMX_HELPER_INTERFACE_MODE_SGMII;
else if (qlm_cfg.s.qlm_cfg == 3)
return CVMX_HELPER_INTERFACE_MODE_XAUI;
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
case 2:
case 3:
case 4:
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(interface));
if (qlm_cfg.s.qlm_spd == 15)
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (qlm_cfg.s.qlm_cfg == 2)
return CVMX_HELPER_INTERFACE_MODE_SGMII;
else if (qlm_cfg.s.qlm_cfg == 3)
return CVMX_HELPER_INTERFACE_MODE_XAUI;
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
case 7:
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(3));
if (qlm_cfg.s.qlm_spd == 15) {
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
} else if (qlm_cfg.s.qlm_cfg != 0) {
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(1));
if (qlm_cfg.s.qlm_cfg != 0)
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
return CVMX_HELPER_INTERFACE_MODE_NPI;
case 8:
return CVMX_HELPER_INTERFACE_MODE_LOOP;
default:
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
}
static cvmx_helper_interface_mode_t __cvmx_get_mode_octeon2(int interface)
{
union cvmx_gmxx_inf_mode mode;
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
return __cvmx_get_mode_cn68xx(interface);
if (interface == 2)
return CVMX_HELPER_INTERFACE_MODE_NPI;
if (interface == 3)
return CVMX_HELPER_INTERFACE_MODE_LOOP;
if ((OCTEON_IS_MODEL(OCTEON_CN63XX) &&
(interface == 4 || interface == 5)) ||
(OCTEON_IS_MODEL(OCTEON_CN66XX) &&
interface >= 4 && interface <= 7)) {
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
if (OCTEON_IS_MODEL(OCTEON_CN66XX)) {
union cvmx_mio_qlmx_cfg mio_qlm_cfg;
if (interface == 0)
mio_qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(2));
else if (interface == 1)
mio_qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(1));
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (mio_qlm_cfg.s.qlm_spd == 15)
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (mio_qlm_cfg.s.qlm_cfg == 9)
return CVMX_HELPER_INTERFACE_MODE_SGMII;
else if (mio_qlm_cfg.s.qlm_cfg == 11)
return CVMX_HELPER_INTERFACE_MODE_XAUI;
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
} else if (OCTEON_IS_MODEL(OCTEON_CN61XX)) {
union cvmx_mio_qlmx_cfg qlm_cfg;
if (interface == 0) {
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(2));
if (qlm_cfg.s.qlm_cfg == 2)
return CVMX_HELPER_INTERFACE_MODE_SGMII;
else if (qlm_cfg.s.qlm_cfg == 3)
return CVMX_HELPER_INTERFACE_MODE_XAUI;
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
} else if (interface == 1) {
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(0));
if (qlm_cfg.s.qlm_cfg == 2)
return CVMX_HELPER_INTERFACE_MODE_SGMII;
else if (qlm_cfg.s.qlm_cfg == 3)
return CVMX_HELPER_INTERFACE_MODE_XAUI;
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
} else if (OCTEON_IS_MODEL(OCTEON_CNF71XX)) {
if (interface == 0) {
union cvmx_mio_qlmx_cfg qlm_cfg;
qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(0));
if (qlm_cfg.s.qlm_cfg == 2)
return CVMX_HELPER_INTERFACE_MODE_SGMII;
}
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
if (interface == 1 && OCTEON_IS_MODEL(OCTEON_CN63XX))
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));
if (OCTEON_IS_MODEL(OCTEON_CN63XX)) {
switch (mode.cn63xx.mode) {
case 0:
return CVMX_HELPER_INTERFACE_MODE_SGMII;
case 1:
return CVMX_HELPER_INTERFACE_MODE_XAUI;
default:
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
} else {
if (!mode.s.en)
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (mode.s.type)
return CVMX_HELPER_INTERFACE_MODE_GMII;
else
return CVMX_HELPER_INTERFACE_MODE_RGMII;
}
}
static cvmx_helper_interface_mode_t __cvmx_get_mode_cn7xxx(int interface)
{
union cvmx_gmxx_inf_mode mode;
mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));
switch (interface) {
case 0:
case 1:
switch (mode.cn68xx.mode) {
case 0:
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
case 1:
case 2:
return CVMX_HELPER_INTERFACE_MODE_SGMII;
case 3:
return CVMX_HELPER_INTERFACE_MODE_XAUI;
default:
return CVMX_HELPER_INTERFACE_MODE_SGMII;
}
case 2:
return CVMX_HELPER_INTERFACE_MODE_NPI;
case 3:
return CVMX_HELPER_INTERFACE_MODE_LOOP;
case 4:
return CVMX_HELPER_INTERFACE_MODE_RGMII;
default:
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
}
cvmx_helper_interface_mode_t cvmx_helper_interface_get_mode(int interface)
{
union cvmx_gmxx_inf_mode mode;
if (interface < 0 ||
interface >= cvmx_helper_get_number_of_interfaces())
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (OCTEON_IS_MODEL(OCTEON_CN7XXX))
return __cvmx_get_mode_cn7xxx(interface);
if (OCTEON_IS_MODEL(OCTEON_CN6XXX) || OCTEON_IS_MODEL(OCTEON_CNF71XX))
return __cvmx_get_mode_octeon2(interface);
if (interface == 2)
return CVMX_HELPER_INTERFACE_MODE_NPI;
if (interface == 3) {
if (OCTEON_IS_MODEL(OCTEON_CN56XX)
|| OCTEON_IS_MODEL(OCTEON_CN52XX))
return CVMX_HELPER_INTERFACE_MODE_LOOP;
else
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
if (interface == 0
&& cvmx_sysinfo_get()->board_type == CVMX_BOARD_TYPE_CN3005_EVB_HS5
&& cvmx_sysinfo_get()->board_rev_major == 1) {
return CVMX_HELPER_INTERFACE_MODE_GMII;
}
if ((interface == 1)
&& (OCTEON_IS_MODEL(OCTEON_CN31XX) || OCTEON_IS_MODEL(OCTEON_CN30XX)
|| OCTEON_IS_MODEL(OCTEON_CN50XX)
|| OCTEON_IS_MODEL(OCTEON_CN52XX)))
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));
if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX)) {
switch (mode.cn56xx.mode) {
case 0:
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
case 1:
return CVMX_HELPER_INTERFACE_MODE_XAUI;
case 2:
return CVMX_HELPER_INTERFACE_MODE_SGMII;
case 3:
return CVMX_HELPER_INTERFACE_MODE_PICMG;
default:
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
}
} else {
if (!mode.s.en)
return CVMX_HELPER_INTERFACE_MODE_DISABLED;
if (mode.s.type) {
if (OCTEON_IS_MODEL(OCTEON_CN38XX)
|| OCTEON_IS_MODEL(OCTEON_CN58XX))
return CVMX_HELPER_INTERFACE_MODE_SPI;
else
return CVMX_HELPER_INTERFACE_MODE_GMII;
} else
return CVMX_HELPER_INTERFACE_MODE_RGMII;
}
}
static int __cvmx_helper_port_setup_ipd(int ipd_port)
{
union cvmx_pip_prt_cfgx port_config;
union cvmx_pip_prt_tagx tag_config;
port_config.u64 = cvmx_read_csr(CVMX_PIP_PRT_CFGX(ipd_port));
tag_config.u64 = cvmx_read_csr(CVMX_PIP_PRT_TAGX(ipd_port));
port_config.s.qos = ipd_port & 0x7;
port_config.s.mode = CVMX_HELPER_INPUT_PORT_SKIP_MODE;
tag_config.s.ip6_src_flag = CVMX_HELPER_INPUT_TAG_IPV6_SRC_IP;
tag_config.s.ip6_dst_flag = CVMX_HELPER_INPUT_TAG_IPV6_DST_IP;
tag_config.s.ip6_sprt_flag = CVMX_HELPER_INPUT_TAG_IPV6_SRC_PORT;
tag_config.s.ip6_dprt_flag = CVMX_HELPER_INPUT_TAG_IPV6_DST_PORT;
tag_config.s.ip6_nxth_flag = CVMX_HELPER_INPUT_TAG_IPV6_NEXT_HEADER;
tag_config.s.ip4_src_flag = CVMX_HELPER_INPUT_TAG_IPV4_SRC_IP;
tag_config.s.ip4_dst_flag = CVMX_HELPER_INPUT_TAG_IPV4_DST_IP;
tag_config.s.ip4_sprt_flag = CVMX_HELPER_INPUT_TAG_IPV4_SRC_PORT;
tag_config.s.ip4_dprt_flag = CVMX_HELPER_INPUT_TAG_IPV4_DST_PORT;
tag_config.s.ip4_pctl_flag = CVMX_HELPER_INPUT_TAG_IPV4_PROTOCOL;
tag_config.s.inc_prt_flag = CVMX_HELPER_INPUT_TAG_INPUT_PORT;
tag_config.s.tcp6_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
tag_config.s.tcp4_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
tag_config.s.ip6_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
tag_config.s.ip4_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
tag_config.s.non_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
tag_config.s.grp = 0;
cvmx_pip_config_port(ipd_port, port_config, tag_config);
if (cvmx_override_ipd_port_setup)
cvmx_override_ipd_port_setup(ipd_port);
return 0;
}
int cvmx_helper_interface_enumerate(int interface)
{
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
interface_port_count[interface] = 0;
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
interface_port_count[interface] =
__cvmx_helper_xaui_enumerate(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
interface_port_count[interface] =
__cvmx_helper_rgmii_enumerate(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_SPI:
interface_port_count[interface] =
__cvmx_helper_spi_enumerate(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
interface_port_count[interface] =
__cvmx_helper_sgmii_enumerate(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_NPI:
interface_port_count[interface] =
__cvmx_helper_npi_enumerate(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_LOOP:
interface_port_count[interface] =
__cvmx_helper_loop_enumerate(interface);
break;
}
interface_port_count[interface] =
__cvmx_helper_board_interface_probe(interface,
interface_port_count
[interface]);
CVMX_SYNCWS;
return 0;
}
int cvmx_helper_interface_probe(int interface)
{
cvmx_helper_interface_enumerate(interface);
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
__cvmx_helper_xaui_probe(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
__cvmx_helper_rgmii_probe(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_SPI:
__cvmx_helper_spi_probe(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
__cvmx_helper_sgmii_probe(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_NPI:
__cvmx_helper_npi_probe(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_LOOP:
__cvmx_helper_loop_probe(interface);
break;
}
CVMX_SYNCWS;
return 0;
}
static int __cvmx_helper_interface_setup_ipd(int interface)
{
int ipd_port = cvmx_helper_get_ipd_port(interface, 0);
int num_ports = interface_port_count[interface];
while (num_ports--) {
__cvmx_helper_port_setup_ipd(ipd_port);
ipd_port++;
}
return 0;
}
static int __cvmx_helper_global_setup_ipd(void)
{
cvmx_ipd_config(CVMX_FPA_PACKET_POOL_SIZE / 8,
CVMX_HELPER_FIRST_MBUFF_SKIP / 8,
CVMX_HELPER_NOT_FIRST_MBUFF_SKIP / 8,
(CVMX_HELPER_FIRST_MBUFF_SKIP + 8) / 128,
(CVMX_HELPER_NOT_FIRST_MBUFF_SKIP + 8) / 128,
CVMX_FPA_WQE_POOL,
CVMX_IPD_OPC_MODE_STT,
CVMX_HELPER_ENABLE_BACK_PRESSURE);
return 0;
}
static int __cvmx_helper_interface_setup_pko(int interface)
{
uint64_t priorities[16] =
{ 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1 };
int ipd_port = cvmx_helper_get_ipd_port(interface, 0);
int num_ports = interface_port_count[interface];
while (num_ports--) {
if (cvmx_override_pko_queue_priority)
cvmx_override_pko_queue_priority(ipd_port, priorities);
cvmx_pko_config_port(ipd_port,
cvmx_pko_get_base_queue_per_core(ipd_port,
0),
cvmx_pko_get_num_queues(ipd_port),
priorities);
ipd_port++;
}
return 0;
}
static int __cvmx_helper_global_setup_pko(void)
{
union cvmx_iob_fau_timeout fau_to;
fau_to.u64 = 0;
fau_to.s.tout_val = 0xfff;
fau_to.s.tout_enb = 0;
cvmx_write_csr(CVMX_IOB_FAU_TIMEOUT, fau_to.u64);
if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
union cvmx_pko_reg_min_pkt min_pkt;
min_pkt.u64 = 0;
min_pkt.s.size1 = 59;
min_pkt.s.size2 = 59;
min_pkt.s.size3 = 59;
min_pkt.s.size4 = 59;
min_pkt.s.size5 = 59;
min_pkt.s.size6 = 59;
min_pkt.s.size7 = 59;
cvmx_write_csr(CVMX_PKO_REG_MIN_PKT, min_pkt.u64);
}
return 0;
}
static int __cvmx_helper_global_setup_backpressure(void)
{
#if CVMX_HELPER_DISABLE_RGMII_BACKPRESSURE
int num_interfaces = cvmx_helper_get_number_of_interfaces();
int interface;
for (interface = 0; interface < num_interfaces; interface++) {
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
case CVMX_HELPER_INTERFACE_MODE_NPI:
case CVMX_HELPER_INTERFACE_MODE_LOOP:
case CVMX_HELPER_INTERFACE_MODE_XAUI:
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
case CVMX_HELPER_INTERFACE_MODE_SPI:
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
cvmx_gmx_set_backpressure_override(interface, 0xf);
break;
}
}
#endif
return 0;
}
static int __cvmx_helper_packet_hardware_enable(int interface)
{
int result = 0;
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
result = __cvmx_helper_xaui_enable(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
result = __cvmx_helper_rgmii_enable(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_SPI:
result = __cvmx_helper_spi_enable(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
result = __cvmx_helper_sgmii_enable(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_NPI:
result = __cvmx_helper_npi_enable(interface);
break;
case CVMX_HELPER_INTERFACE_MODE_LOOP:
result = __cvmx_helper_loop_enable(interface);
break;
}
result |= __cvmx_helper_board_hardware_enable(interface);
return result;
}
int __cvmx_helper_errata_fix_ipd_ptr_alignment(void)
{
#define FIX_IPD_FIRST_BUFF_PAYLOAD_BYTES \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_FIRST_MBUFF_SKIP)
#define FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES \
(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_NOT_FIRST_MBUFF_SKIP)
#define FIX_IPD_OUTPORT 0
#define INTERFACE(port) (port >> 4)
#define INDEX(port) (port & 0xf)
uint64_t *p64;
cvmx_pko_command_word0_t pko_command;
union cvmx_buf_ptr g_buffer, pkt_buffer;
cvmx_wqe_t *work;
int size, num_segs = 0, wqe_pcnt, pkt_pcnt;
union cvmx_gmxx_prtx_cfg gmx_cfg;
int retry_cnt;
int retry_loop_cnt;
int i;
uint64_t prtx_cfg =
cvmx_read_csr(CVMX_GMXX_PRTX_CFG
(INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)));
uint64_t tx_ptr_en =
cvmx_read_csr(CVMX_ASXX_TX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)));
uint64_t rx_ptr_en =
cvmx_read_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)));
uint64_t rxx_jabber =
cvmx_read_csr(CVMX_GMXX_RXX_JABBER
(INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)));
uint64_t frame_max =
cvmx_read_csr(CVMX_GMXX_RXX_FRM_MAX
(INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)));
cvmx_helper_rgmii_internal_loopback(FIX_IPD_OUTPORT);
cvmx_write_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)), 0);
cvmx_wait(100000000ull);
for (retry_loop_cnt = 0; retry_loop_cnt < 10; retry_loop_cnt++) {
retry_cnt = 100000;
wqe_pcnt = cvmx_read_csr(CVMX_IPD_PTR_COUNT);
pkt_pcnt = (wqe_pcnt >> 7) & 0x7f;
wqe_pcnt &= 0x7f;
num_segs = (2 + pkt_pcnt - wqe_pcnt) & 3;
if (num_segs == 0)
goto fix_ipd_exit;
num_segs += 1;
size =
FIX_IPD_FIRST_BUFF_PAYLOAD_BYTES +
((num_segs - 1) * FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES) -
(FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES / 2);
cvmx_write_csr(CVMX_ASXX_PRT_LOOP(INTERFACE(FIX_IPD_OUTPORT)),
1 << INDEX(FIX_IPD_OUTPORT));
CVMX_SYNC;
g_buffer.u64 = 0;
g_buffer.s.addr =
cvmx_ptr_to_phys(cvmx_fpa_alloc(CVMX_FPA_WQE_POOL));
if (g_buffer.s.addr == 0) {
cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT "
"buffer allocation failure.\n");
goto fix_ipd_exit;
}
g_buffer.s.pool = CVMX_FPA_WQE_POOL;
g_buffer.s.size = num_segs;
pkt_buffer.u64 = 0;
pkt_buffer.s.addr =
cvmx_ptr_to_phys(cvmx_fpa_alloc(CVMX_FPA_PACKET_POOL));
if (pkt_buffer.s.addr == 0) {
cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT "
"buffer allocation failure.\n");
goto fix_ipd_exit;
}
pkt_buffer.s.i = 1;
pkt_buffer.s.pool = CVMX_FPA_PACKET_POOL;
pkt_buffer.s.size = FIX_IPD_FIRST_BUFF_PAYLOAD_BYTES;
p64 = (uint64_t *) cvmx_phys_to_ptr(pkt_buffer.s.addr);
p64[0] = 0xffffffffffff0000ull;
p64[1] = 0x08004510ull;
p64[2] = ((uint64_t) (size - 14) << 48) | 0x5ae740004000ull;
p64[3] = 0x3a5fc0a81073c0a8ull;
for (i = 0; i < num_segs; i++) {
if (i > 0)
pkt_buffer.s.size =
FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES;
if (i == (num_segs - 1))
pkt_buffer.s.i = 0;
*(uint64_t *) cvmx_phys_to_ptr(g_buffer.s.addr +
8 * i) = pkt_buffer.u64;
}
pko_command.u64 = 0;
pko_command.s.segs = num_segs;
pko_command.s.total_bytes = size;
pko_command.s.dontfree = 0;
pko_command.s.gather = 1;
gmx_cfg.u64 =
cvmx_read_csr(CVMX_GMXX_PRTX_CFG
(INDEX(FIX_IPD_OUTPORT),
INTERFACE(FIX_IPD_OUTPORT)));
gmx_cfg.s.en = 1;
cvmx_write_csr(CVMX_GMXX_PRTX_CFG
(INDEX(FIX_IPD_OUTPORT),
INTERFACE(FIX_IPD_OUTPORT)), gmx_cfg.u64);
cvmx_write_csr(CVMX_ASXX_TX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
1 << INDEX(FIX_IPD_OUTPORT));
cvmx_write_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
1 << INDEX(FIX_IPD_OUTPORT));
cvmx_write_csr(CVMX_GMXX_RXX_JABBER
(INDEX(FIX_IPD_OUTPORT),
INTERFACE(FIX_IPD_OUTPORT)), 65392 - 14 - 4);
cvmx_write_csr(CVMX_GMXX_RXX_FRM_MAX
(INDEX(FIX_IPD_OUTPORT),
INTERFACE(FIX_IPD_OUTPORT)), 65392 - 14 - 4);
cvmx_pko_send_packet_prepare(FIX_IPD_OUTPORT,
cvmx_pko_get_base_queue
(FIX_IPD_OUTPORT),
CVMX_PKO_LOCK_CMD_QUEUE);
cvmx_pko_send_packet_finish(FIX_IPD_OUTPORT,
cvmx_pko_get_base_queue
(FIX_IPD_OUTPORT), pko_command,
g_buffer, CVMX_PKO_LOCK_CMD_QUEUE);
CVMX_SYNC;
do {
work = cvmx_pow_work_request_sync(CVMX_POW_WAIT);
retry_cnt--;
} while ((work == NULL) && (retry_cnt > 0));
if (!retry_cnt)
cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT "
"get_work() timeout occurred.\n");
if (work)
cvmx_helper_free_packet_data(work);
}
fix_ipd_exit:
cvmx_write_csr(CVMX_GMXX_PRTX_CFG
(INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)),
prtx_cfg);
cvmx_write_csr(CVMX_ASXX_TX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
tx_ptr_en);
cvmx_write_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
rx_ptr_en);
cvmx_write_csr(CVMX_GMXX_RXX_JABBER
(INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)),
rxx_jabber);
cvmx_write_csr(CVMX_GMXX_RXX_FRM_MAX
(INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)),
frame_max);
cvmx_write_csr(CVMX_ASXX_PRT_LOOP(INTERFACE(FIX_IPD_OUTPORT)), 0);
CVMX_SYNC;
if (num_segs)
cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT failed.\n");
return !!num_segs;
}
int cvmx_helper_ipd_and_packet_input_enable(void)
{
int num_interfaces;
int interface;
cvmx_ipd_enable();
num_interfaces = cvmx_helper_get_number_of_interfaces();
for (interface = 0; interface < num_interfaces; interface++) {
if (cvmx_helper_ports_on_interface(interface) > 0)
__cvmx_helper_packet_hardware_enable(interface);
}
cvmx_pko_enable();
if ((OCTEON_IS_MODEL(OCTEON_CN31XX_PASS1)
|| OCTEON_IS_MODEL(OCTEON_CN30XX_PASS1))
&& (cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM))
__cvmx_helper_errata_fix_ipd_ptr_alignment();
return 0;
}
int cvmx_helper_initialize_packet_io_global(void)
{
int result = 0;
int interface;
union cvmx_l2c_cfg l2c_cfg;
union cvmx_smix_en smix_en;
const int num_interfaces = cvmx_helper_get_number_of_interfaces();
if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_0))
__cvmx_helper_errata_qlm_disable_2nd_order_cdr(1);
l2c_cfg.u64 = cvmx_read_csr(CVMX_L2C_CFG);
l2c_cfg.s.lrf_arb_mode = 0;
l2c_cfg.s.rfb_arb_mode = 0;
cvmx_write_csr(CVMX_L2C_CFG, l2c_cfg.u64);
smix_en.u64 = cvmx_read_csr(CVMX_SMIX_EN(0));
if (!smix_en.s.en) {
smix_en.s.en = 1;
cvmx_write_csr(CVMX_SMIX_EN(0), smix_en.u64);
}
if (!OCTEON_IS_MODEL(OCTEON_CN3XXX) &&
!OCTEON_IS_MODEL(OCTEON_CN58XX) &&
!OCTEON_IS_MODEL(OCTEON_CN50XX)) {
smix_en.u64 = cvmx_read_csr(CVMX_SMIX_EN(1));
if (!smix_en.s.en) {
smix_en.s.en = 1;
cvmx_write_csr(CVMX_SMIX_EN(1), smix_en.u64);
}
}
cvmx_pko_initialize_global();
for (interface = 0; interface < num_interfaces; interface++) {
result |= cvmx_helper_interface_probe(interface);
if (cvmx_helper_ports_on_interface(interface) > 0)
cvmx_dprintf("Interface %d has %d ports (%s)\n",
interface,
cvmx_helper_ports_on_interface(interface),
cvmx_helper_interface_mode_to_string
(cvmx_helper_interface_get_mode
(interface)));
result |= __cvmx_helper_interface_setup_ipd(interface);
result |= __cvmx_helper_interface_setup_pko(interface);
}
result |= __cvmx_helper_global_setup_ipd();
result |= __cvmx_helper_global_setup_pko();
result |= __cvmx_helper_global_setup_backpressure();
#if CVMX_HELPER_ENABLE_IPD
result |= cvmx_helper_ipd_and_packet_input_enable();
#endif
return result;
}
int cvmx_helper_initialize_packet_io_local(void)
{
return cvmx_pko_initialize_local();
}
cvmx_helper_link_info_t cvmx_helper_link_autoconf(int ipd_port)
{
cvmx_helper_link_info_t link_info;
int interface = cvmx_helper_get_interface_num(ipd_port);
int index = cvmx_helper_get_interface_index_num(ipd_port);
if (index >= cvmx_helper_ports_on_interface(interface)) {
link_info.u64 = 0;
return link_info;
}
link_info = cvmx_helper_link_get(ipd_port);
if (link_info.u64 == port_link_info[ipd_port].u64)
return link_info;
cvmx_helper_link_set(ipd_port, link_info);
return port_link_info[ipd_port];
}
cvmx_helper_link_info_t cvmx_helper_link_get(int ipd_port)
{
cvmx_helper_link_info_t result;
int interface = cvmx_helper_get_interface_num(ipd_port);
int index = cvmx_helper_get_interface_index_num(ipd_port);
result.u64 = 0;
if (index >= cvmx_helper_ports_on_interface(interface))
return result;
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
result = __cvmx_helper_xaui_link_get(ipd_port);
break;
case CVMX_HELPER_INTERFACE_MODE_GMII:
if (index == 0)
result = __cvmx_helper_rgmii_link_get(ipd_port);
else {
result.s.full_duplex = 1;
result.s.link_up = 1;
result.s.speed = 1000;
}
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
result = __cvmx_helper_rgmii_link_get(ipd_port);
break;
case CVMX_HELPER_INTERFACE_MODE_SPI:
result = __cvmx_helper_spi_link_get(ipd_port);
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
result = __cvmx_helper_sgmii_link_get(ipd_port);
break;
case CVMX_HELPER_INTERFACE_MODE_NPI:
case CVMX_HELPER_INTERFACE_MODE_LOOP:
break;
}
return result;
}
int cvmx_helper_link_set(int ipd_port, cvmx_helper_link_info_t link_info)
{
int result = -1;
int interface = cvmx_helper_get_interface_num(ipd_port);
int index = cvmx_helper_get_interface_index_num(ipd_port);
if (index >= cvmx_helper_ports_on_interface(interface))
return -1;
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
result = __cvmx_helper_xaui_link_set(ipd_port, link_info);
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
result = __cvmx_helper_rgmii_link_set(ipd_port, link_info);
break;
case CVMX_HELPER_INTERFACE_MODE_SPI:
result = __cvmx_helper_spi_link_set(ipd_port, link_info);
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
result = __cvmx_helper_sgmii_link_set(ipd_port, link_info);
break;
case CVMX_HELPER_INTERFACE_MODE_NPI:
case CVMX_HELPER_INTERFACE_MODE_LOOP:
break;
}
if (result == 0)
port_link_info[ipd_port].u64 = link_info.u64;
return result;
}
int cvmx_helper_configure_loopback(int ipd_port, int enable_internal,
int enable_external)
{
int result = -1;
int interface = cvmx_helper_get_interface_num(ipd_port);
int index = cvmx_helper_get_interface_index_num(ipd_port);
if (index >= cvmx_helper_ports_on_interface(interface))
return -1;
switch (cvmx_helper_interface_get_mode(interface)) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
case CVMX_HELPER_INTERFACE_MODE_SPI:
case CVMX_HELPER_INTERFACE_MODE_NPI:
case CVMX_HELPER_INTERFACE_MODE_LOOP:
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
result =
__cvmx_helper_xaui_configure_loopback(ipd_port,
enable_internal,
enable_external);
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
result =
__cvmx_helper_rgmii_configure_loopback(ipd_port,
enable_internal,
enable_external);
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
result =
__cvmx_helper_sgmii_configure_loopback(ipd_port,
enable_internal,
enable_external);
break;
}
return result;
}
