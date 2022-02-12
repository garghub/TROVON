static int psc_open(void)
{
return 0;
}
static void psc_putc(unsigned char c)
{
while (!(in_be16(psc + MPC52xx_PSC_SR) & MPC52xx_PSC_SR_TXRDY)) ;
out_8(psc + MPC52xx_PSC_BUFFER, c);
}
static unsigned char psc_tstc(void)
{
return (in_be16(psc + MPC52xx_PSC_SR) & MPC52xx_PSC_SR_RXRDY) != 0;
}
static unsigned char psc_getc(void)
{
while (!(in_be16(psc + MPC52xx_PSC_SR) & MPC52xx_PSC_SR_RXRDY)) ;
return in_8(psc + MPC52xx_PSC_BUFFER);
}
int mpc5200_psc_console_init(void *devp, struct serial_console_data *scdp)
{
if (dt_get_virtual_reg(devp, &psc, 1) < 1)
return -1;
scdp->open = psc_open;
scdp->putc = psc_putc;
scdp->getc = psc_getc;
scdp->tstc = psc_tstc;
return 0;
}
