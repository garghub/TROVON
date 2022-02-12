static int __init msp_pci_setup(void)
{
#if 0
if (getdeviceid() & DEV_ID_SINGLE_PC) {
slmRegs *sreg = (slmRegs *) SREG_BASE;
sreg->single_pc_enable = SINGLE_PCCARD;
}
#endif
msp_pci_init();
return 0;
}
