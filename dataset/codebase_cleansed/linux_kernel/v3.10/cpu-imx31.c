static int mx31_read_cpu_rev(void)
{
u32 i, srev;
srev = __raw_readl(MX31_IO_ADDRESS(MX31_IIM_BASE_ADDR + MXC_IIMSREV));
srev &= 0xff;
for (i = 0; i < ARRAY_SIZE(mx31_cpu_type); i++)
if (srev == mx31_cpu_type[i].srev) {
imx_print_silicon_rev(mx31_cpu_type[i].name,
mx31_cpu_type[i].rev);
return mx31_cpu_type[i].rev;
}
imx_print_silicon_rev("i.MX31", IMX_CHIP_REVISION_UNKNOWN);
return IMX_CHIP_REVISION_UNKNOWN;
}
int mx31_revision(void)
{
if (mx31_cpu_rev == -1)
mx31_cpu_rev = mx31_read_cpu_rev();
return mx31_cpu_rev;
}
