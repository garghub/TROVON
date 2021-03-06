u32 mpc885_get_clock(u32 crystal)
{
u32 *immr;
u32 plprcr;
int mfi, mfn, mfd, pdf, div;
u32 ret;
immr = fsl_get_immr();
if (!immr) {
printf("mpc885_get_clock: Couldn't get IMMR base.\r\n");
return 0;
}
plprcr = in_be32(&immr[MPC8XX_PLPRCR]);
mfi = (plprcr >> 16) & 15;
if (mfi < 5) {
printf("Warning: PLPRCR[MFI] value of %d out-of-bounds\r\n",
mfi);
mfi = 5;
}
pdf = (plprcr >> 1) & 0xf;
div = (plprcr >> 20) & 3;
mfd = (plprcr >> 22) & 0x1f;
mfn = (plprcr >> 27) & 0x1f;
ret = crystal * mfi;
if (mfn != 0)
ret += crystal * mfn / (mfd + 1);
return ret / (pdf + 1);
}
void mpc8xx_set_clocks(u32 sysclk)
{
void *node;
dt_fixup_cpu_clocks(sysclk, sysclk / 16, sysclk);
node = finddevice("/soc/cpm");
if (node)
setprop(node, "clock-frequency", &sysclk, 4);
node = finddevice("/soc/cpm/brg");
if (node)
setprop(node, "clock-frequency", &sysclk, 4);
}
int mpc885_fixup_clocks(u32 crystal)
{
u32 sysclk = mpc885_get_clock(crystal);
if (!sysclk)
return 0;
mpc8xx_set_clocks(sysclk);
return 1;
}
