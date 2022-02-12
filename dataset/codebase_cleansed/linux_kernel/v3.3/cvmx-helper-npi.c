int __cvmx_helper_npi_probe(int interface)
{
#if CVMX_PKO_QUEUES_PER_PORT_PCI > 0
if (OCTEON_IS_MODEL(OCTEON_CN38XX) || OCTEON_IS_MODEL(OCTEON_CN58XX))
return 4;
else if (OCTEON_IS_MODEL(OCTEON_CN56XX)
&& !OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X))
return 4;
else if (OCTEON_IS_MODEL(OCTEON_CN52XX)
&& !OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
return 4;
#if 0
else if (OCTEON_IS_MODEL(OCTEON_CN31XX)
|| OCTEON_IS_MODEL(OCTEON_CN50XX))
return 2;
else if (OCTEON_IS_MODEL(OCTEON_CN30XX))
return 1;
#endif
#endif
return 0;
}
int __cvmx_helper_npi_enable(int interface)
{
if (!OCTEON_IS_MODEL(OCTEON_CN3XXX) &&
!OCTEON_IS_MODEL(OCTEON_CN58XX)) {
int num_ports = cvmx_helper_ports_on_interface(interface);
int port;
for (port = 0; port < num_ports; port++) {
union cvmx_pip_prt_cfgx port_cfg;
int ipd_port =
cvmx_helper_get_ipd_port(interface, port);
port_cfg.u64 =
cvmx_read_csr(CVMX_PIP_PRT_CFGX(ipd_port));
port_cfg.s.maxerr_en = 0;
port_cfg.s.minerr_en = 0;
cvmx_write_csr(CVMX_PIP_PRT_CFGX(ipd_port),
port_cfg.u64);
}
}
return 0;
}
