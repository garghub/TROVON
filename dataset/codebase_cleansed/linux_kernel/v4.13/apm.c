int query_apm_bios(void)
{
struct biosregs ireg, oreg;
initregs(&ireg);
ireg.ah = 0x53;
intcall(0x15, &ireg, &oreg);
if (oreg.flags & X86_EFLAGS_CF)
return -1;
if (oreg.bx != 0x504d)
return -1;
if (!(oreg.cx & 0x02))
return -1;
ireg.al = 0x04;
intcall(0x15, &ireg, NULL);
ireg.al = 0x03;
intcall(0x15, &ireg, &oreg);
boot_params.apm_bios_info.cseg = oreg.ax;
boot_params.apm_bios_info.offset = oreg.ebx;
boot_params.apm_bios_info.cseg_16 = oreg.cx;
boot_params.apm_bios_info.dseg = oreg.dx;
boot_params.apm_bios_info.cseg_len = oreg.si;
boot_params.apm_bios_info.cseg_16_len = oreg.hsi;
boot_params.apm_bios_info.dseg_len = oreg.di;
if (oreg.flags & X86_EFLAGS_CF)
return -1;
ireg.al = 0x00;
intcall(0x15, &ireg, &oreg);
if ((oreg.eflags & X86_EFLAGS_CF) || oreg.bx != 0x504d) {
ireg.al = 0x04;
intcall(0x15, &ireg, NULL);
return -1;
}
boot_params.apm_bios_info.version = oreg.ax;
boot_params.apm_bios_info.flags = oreg.cx;
return 0;
}
