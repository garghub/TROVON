static int T_1 F_1 ( void )
{
#if 0
if (getdeviceid() & DEV_ID_SINGLE_PC) {
slmRegs *sreg = (slmRegs *) SREG_BASE;
sreg->single_pc_enable = SINGLE_PCCARD;
}
#endif
F_2 () ;
return 0 ;
}
