static int mx25_read_cpu_rev(void)
{
u32 rev;
rev = __raw_readl(MX25_IO_ADDRESS(MX25_IIM_BASE_ADDR + MXC_IIMSREV));
switch (rev) {
case 0x00:
return IMX_CHIP_REVISION_1_0;
case 0x01:
return IMX_CHIP_REVISION_1_1;
default:
return IMX_CHIP_REVISION_UNKNOWN;
}
}
int mx25_revision(void)
{
if (mx25_cpu_rev == -1)
mx25_cpu_rev = mx25_read_cpu_rev();
return mx25_cpu_rev;
}
