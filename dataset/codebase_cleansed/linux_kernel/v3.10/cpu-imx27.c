static int mx27_read_cpu_rev(void)
{
u32 val;
val = __raw_readl(MX27_IO_ADDRESS(MX27_SYSCTRL_BASE_ADDR
+ SYS_CHIP_ID));
mx27_cpu_partnumber = (int)((val >> 12) & 0xFFFF);
switch (val >> 28) {
case 0:
return IMX_CHIP_REVISION_1_0;
case 1:
return IMX_CHIP_REVISION_2_0;
case 2:
return IMX_CHIP_REVISION_2_1;
default:
return IMX_CHIP_REVISION_UNKNOWN;
}
}
int mx27_revision(void)
{
if (mx27_cpu_rev == -1)
mx27_cpu_rev = mx27_read_cpu_rev();
if (mx27_cpu_partnumber != 0x8821)
return -EINVAL;
return mx27_cpu_rev;
}
