static void __init nettel_smc91x_setmac(unsigned int ioaddr, unsigned int flashaddr)
{
u16 *macp;
macp = (u16 *) flashaddr;
if ((macp[0] == 0xffff) && (macp[1] == 0xffff) && (macp[2] == 0xffff))
macp = (u16 *) &nettel_macdefault[0];
writew(1, NETTEL_SMC0_ADDR + SMC91xx_BANKSELECT);
writew(macp[0], ioaddr + SMC91xx_BASEMAC);
writew(macp[1], ioaddr + SMC91xx_BASEMAC + 2);
writew(macp[2], ioaddr + SMC91xx_BASEMAC + 4);
}
static void __init nettel_smc91x_init(void)
{
writew(0x00ec, MCF_MBAR + MCFSIM_PADDR);
mcf_setppdata(0, 0x0080);
writew(1, NETTEL_SMC0_ADDR + SMC91xx_BANKSELECT);
writew(0x0067, NETTEL_SMC0_ADDR + SMC91xx_BASEADDR);
mcf_setppdata(0x0080, 0);
writew(0x1180, MCF_MBAR + MCFSIM_CSCR3);
mcf_autovector(NETTEL_SMC0_IRQ);
mcf_autovector(NETTEL_SMC1_IRQ);
nettel_smc91x_setmac(NETTEL_SMC0_ADDR, 0xf0006000);
nettel_smc91x_setmac(NETTEL_SMC1_ADDR, 0xf0006006);
}
static int __init init_nettel(void)
{
nettel_smc91x_init();
platform_add_devices(nettel_devices, ARRAY_SIZE(nettel_devices));
return 0;
}
