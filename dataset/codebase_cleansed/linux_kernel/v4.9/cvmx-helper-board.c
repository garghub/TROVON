int cvmx_helper_board_get_mii_address(int ipd_port)
{
switch (cvmx_sysinfo_get()->board_type) {
case CVMX_BOARD_TYPE_SIM:
return -1;
case CVMX_BOARD_TYPE_EBT3000:
case CVMX_BOARD_TYPE_EBT5800:
case CVMX_BOARD_TYPE_THUNDER:
case CVMX_BOARD_TYPE_NICPRO2:
if ((ipd_port >= 16) && (ipd_port < 20))
return ipd_port - 16;
else
return -1;
case CVMX_BOARD_TYPE_KODAMA:
case CVMX_BOARD_TYPE_EBH3100:
case CVMX_BOARD_TYPE_HIKARI:
case CVMX_BOARD_TYPE_CN3010_EVB_HS5:
case CVMX_BOARD_TYPE_CN3005_EVB_HS5:
case CVMX_BOARD_TYPE_CN3020_EVB_HS5:
if (ipd_port == 0)
return 4;
else if (ipd_port == 1)
return 9;
else
return -1;
case CVMX_BOARD_TYPE_NAC38:
if ((ipd_port >= 0) && (ipd_port < 4))
return ipd_port;
else if ((ipd_port >= 16) && (ipd_port < 20))
return ipd_port - 16 + 4;
else
return -1;
case CVMX_BOARD_TYPE_EBH3000:
return -1;
case CVMX_BOARD_TYPE_EBH5200:
case CVMX_BOARD_TYPE_EBH5201:
case CVMX_BOARD_TYPE_EBT5200:
if ((ipd_port >= CVMX_HELPER_BOARD_MGMT_IPD_PORT) &&
(ipd_port < (CVMX_HELPER_BOARD_MGMT_IPD_PORT + 2)))
return ipd_port - CVMX_HELPER_BOARD_MGMT_IPD_PORT;
if ((ipd_port >= 0) && (ipd_port < 4))
return ipd_port + 2;
else
return -1;
case CVMX_BOARD_TYPE_EBH5600:
case CVMX_BOARD_TYPE_EBH5601:
case CVMX_BOARD_TYPE_EBH5610:
if (ipd_port == CVMX_HELPER_BOARD_MGMT_IPD_PORT)
return 0;
if ((ipd_port >= 0) && (ipd_port < 4))
return ipd_port + 1;
else
return -1;
case CVMX_BOARD_TYPE_CUST_NB5:
if (ipd_port == 2)
return 4;
else
return -1;
case CVMX_BOARD_TYPE_NIC_XLE_4G:
if ((ipd_port >= 16) && (ipd_port < 20))
return ipd_port - 16 + 1;
else
return -1;
case CVMX_BOARD_TYPE_NIC_XLE_10G:
case CVMX_BOARD_TYPE_NIC10E:
return -1;
case CVMX_BOARD_TYPE_NIC4E:
if (ipd_port >= 0 && ipd_port <= 3)
return (ipd_port + 0x1f) & 0x1f;
else
return -1;
case CVMX_BOARD_TYPE_NIC2E:
if (ipd_port >= 0 && ipd_port <= 1)
return ipd_port + 1;
else
return -1;
case CVMX_BOARD_TYPE_BBGW_REF:
return -1;
case CVMX_BOARD_TYPE_CUST_WSX16:
if (ipd_port >= 0 && ipd_port <= 3)
return ipd_port;
else if (ipd_port >= 16 && ipd_port <= 19)
return ipd_port - 16 + 4;
else
return -1;
case CVMX_BOARD_TYPE_UBNT_E100:
if (ipd_port >= 0 && ipd_port <= 2)
return 7 - ipd_port;
else
return -1;
case CVMX_BOARD_TYPE_KONTRON_S1901:
if (ipd_port == CVMX_HELPER_BOARD_MGMT_IPD_PORT)
return 1;
else
return -1;
}
cvmx_dprintf
("cvmx_helper_board_get_mii_address: Unknown board type %d\n",
cvmx_sysinfo_get()->board_type);
return -1;
}
cvmx_helper_link_info_t __cvmx_helper_board_link_get(int ipd_port)
{
cvmx_helper_link_info_t result;
result.u64 = 0;
switch (cvmx_sysinfo_get()->board_type) {
case CVMX_BOARD_TYPE_SIM:
result.s.link_up = 1;
result.s.full_duplex = 1;
result.s.speed = 1000;
return result;
case CVMX_BOARD_TYPE_EBH3100:
case CVMX_BOARD_TYPE_CN3010_EVB_HS5:
case CVMX_BOARD_TYPE_CN3005_EVB_HS5:
case CVMX_BOARD_TYPE_CN3020_EVB_HS5:
if (ipd_port == 1) {
result.s.link_up = 1;
result.s.full_duplex = 1;
result.s.speed = 1000;
return result;
}
break;
case CVMX_BOARD_TYPE_CUST_NB5:
if (ipd_port == 1) {
result.s.link_up = 1;
result.s.full_duplex = 1;
result.s.speed = 1000;
return result;
}
break;
case CVMX_BOARD_TYPE_BBGW_REF:
if (ipd_port == 2) {
result.u64 = 0;
return result;
} else {
result.s.link_up = 1;
result.s.full_duplex = 1;
result.s.speed = 1000;
return result;
}
break;
}
if (OCTEON_IS_MODEL(OCTEON_CN3XXX)
|| OCTEON_IS_MODEL(OCTEON_CN58XX)
|| OCTEON_IS_MODEL(OCTEON_CN50XX)) {
union cvmx_gmxx_rxx_rx_inbnd inband_status;
int interface = cvmx_helper_get_interface_num(ipd_port);
int index = cvmx_helper_get_interface_index_num(ipd_port);
inband_status.u64 =
cvmx_read_csr(CVMX_GMXX_RXX_RX_INBND(index, interface));
result.s.link_up = inband_status.s.status;
result.s.full_duplex = inband_status.s.duplex;
switch (inband_status.s.speed) {
case 0:
result.s.speed = 10;
break;
case 1:
result.s.speed = 100;
break;
case 2:
result.s.speed = 1000;
break;
case 3:
result.u64 = 0;
break;
}
} else {
result.u64 = 0;
}
if (!result.s.link_up)
result.u64 = 0;
return result;
}
int __cvmx_helper_board_interface_probe(int interface, int supported_ports)
{
switch (cvmx_sysinfo_get()->board_type) {
case CVMX_BOARD_TYPE_CN3005_EVB_HS5:
if (interface == 0)
return 2;
break;
case CVMX_BOARD_TYPE_BBGW_REF:
if (interface == 0)
return 2;
break;
case CVMX_BOARD_TYPE_NIC_XLE_4G:
if (interface == 0)
return 0;
break;
case CVMX_BOARD_TYPE_EBH5600:
if (interface == 1)
return 0;
break;
}
return supported_ports;
}
int __cvmx_helper_board_hardware_enable(int interface)
{
if (cvmx_sysinfo_get()->board_type == CVMX_BOARD_TYPE_CN3005_EVB_HS5) {
if (interface == 0) {
cvmx_write_csr(CVMX_ASXX_TX_CLK_SETX(1, interface), 0);
cvmx_write_csr(CVMX_ASXX_RX_CLK_SETX(1, interface), 0);
cvmx_write_csr(CVMX_ASXX_TX_CLK_SETX(0, interface),
0xc);
cvmx_write_csr(CVMX_ASXX_RX_CLK_SETX(0, interface),
0xc);
}
} else if (cvmx_sysinfo_get()->board_type ==
CVMX_BOARD_TYPE_UBNT_E100) {
cvmx_write_csr(CVMX_ASXX_RX_CLK_SETX(0, interface), 0);
cvmx_write_csr(CVMX_ASXX_TX_CLK_SETX(0, interface), 0x10);
cvmx_write_csr(CVMX_ASXX_RX_CLK_SETX(1, interface), 0);
cvmx_write_csr(CVMX_ASXX_TX_CLK_SETX(1, interface), 0x10);
cvmx_write_csr(CVMX_ASXX_RX_CLK_SETX(2, interface), 0);
cvmx_write_csr(CVMX_ASXX_TX_CLK_SETX(2, interface), 0x10);
}
return 0;
}
enum cvmx_helper_board_usb_clock_types __cvmx_helper_board_usb_get_clock_type(void)
{
switch (cvmx_sysinfo_get()->board_type) {
case CVMX_BOARD_TYPE_BBGW_REF:
case CVMX_BOARD_TYPE_LANAI2_A:
case CVMX_BOARD_TYPE_LANAI2_U:
case CVMX_BOARD_TYPE_LANAI2_G:
case CVMX_BOARD_TYPE_NIC10E_66:
case CVMX_BOARD_TYPE_UBNT_E100:
return USB_CLOCK_TYPE_CRYSTAL_12;
case CVMX_BOARD_TYPE_NIC10E:
return USB_CLOCK_TYPE_REF_12;
default:
break;
}
if (OCTEON_IS_OCTEON2())
return USB_CLOCK_TYPE_CRYSTAL_12;
return USB_CLOCK_TYPE_REF_48;
}
