void __init sgihpc_init(void)
{
hpc3c0 = (struct hpc3_regs *)
ioremap(HPC3_CHIP0_BASE, sizeof(struct hpc3_regs));
hpc3c1 = (struct hpc3_regs *)
ioremap(HPC3_CHIP1_BASE, sizeof(struct hpc3_regs));
sgioc = (struct sgioc_regs *)hpc3c0->pbus_extregs[6];
hpc3c0->pbus_piocfg[6][0] |= HPC3_PIOCFG_DS16;
if (ip22_is_fullhouse()) {
sgint = (struct sgint_regs *)hpc3c0->pbus_extregs[4];
system_type = "SGI Indigo2";
} else {
sgint = &sgioc->int3;
system_type = "SGI Indy";
}
sgi_ioc_reset = (SGIOC_RESET_PPORT | SGIOC_RESET_KBDMOUSE |
SGIOC_RESET_EISA | SGIOC_RESET_ISDN |
SGIOC_RESET_LC0OFF);
sgi_ioc_write = (SGIOC_WRITE_EASEL | SGIOC_WRITE_NTHRESH |
SGIOC_WRITE_TPSPEED | SGIOC_WRITE_EPSEL |
SGIOC_WRITE_U0AMODE | SGIOC_WRITE_U1AMODE);
sgioc->reset = sgi_ioc_reset;
sgioc->write = sgi_ioc_write;
}
