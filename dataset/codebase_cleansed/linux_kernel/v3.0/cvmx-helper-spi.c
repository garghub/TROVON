int __cvmx_helper_spi_probe(int interface)
{
int num_ports = 0;
if ((cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM) &&
cvmx_spi4000_is_present(interface)) {
num_ports = 10;
} else {
union cvmx_pko_reg_crc_enable enable;
num_ports = 16;
enable.u64 = cvmx_read_csr(CVMX_PKO_REG_CRC_ENABLE);
enable.s.enable |= 0xffff << (interface * 16);
cvmx_write_csr(CVMX_PKO_REG_CRC_ENABLE, enable.u64);
}
__cvmx_helper_setup_gmx(interface, num_ports);
return num_ports;
}
int __cvmx_helper_spi_enable(int interface)
{
int num_ports = cvmx_helper_ports_on_interface(interface);
int ipd_port;
for (ipd_port = interface * 16; ipd_port < interface * 16 + num_ports;
ipd_port++) {
union cvmx_pip_prt_cfgx port_config;
port_config.u64 = cvmx_read_csr(CVMX_PIP_PRT_CFGX(ipd_port));
port_config.s.crc_en = 1;
cvmx_write_csr(CVMX_PIP_PRT_CFGX(ipd_port), port_config.u64);
}
if (cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM) {
cvmx_spi_start_interface(interface, CVMX_SPI_MODE_DUPLEX,
CVMX_HELPER_SPI_TIMEOUT, num_ports);
if (cvmx_spi4000_is_present(interface))
cvmx_spi4000_initialize(interface);
}
__cvmx_interrupt_spxx_int_msk_enable(interface);
__cvmx_interrupt_stxx_int_msk_enable(interface);
__cvmx_interrupt_gmxx_enable(interface);
return 0;
}
cvmx_helper_link_info_t __cvmx_helper_spi_link_get(int ipd_port)
{
cvmx_helper_link_info_t result;
int interface = cvmx_helper_get_interface_num(ipd_port);
int index = cvmx_helper_get_interface_index_num(ipd_port);
result.u64 = 0;
if (cvmx_sysinfo_get()->board_type == CVMX_BOARD_TYPE_SIM) {
result.s.link_up = 1;
result.s.full_duplex = 1;
result.s.speed = 10000;
} else if (cvmx_spi4000_is_present(interface)) {
union cvmx_gmxx_rxx_rx_inbnd inband =
cvmx_spi4000_check_speed(interface, index);
result.s.link_up = inband.s.status;
result.s.full_duplex = inband.s.duplex;
switch (inband.s.speed) {
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
result.s.speed = 0;
result.s.link_up = 0;
break;
}
} else {
result.s.link_up = 1;
result.s.full_duplex = 1;
result.s.speed = 10000;
}
return result;
}
int __cvmx_helper_spi_link_set(int ipd_port, cvmx_helper_link_info_t link_info)
{
return 0;
}
