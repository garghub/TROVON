static int get_mx51_srev(void)
{
void __iomem *iim_base = MX51_IO_ADDRESS(MX51_IIM_BASE_ADDR);
u32 rev = readl(iim_base + IIM_SREV) & 0xff;
switch (rev) {
case 0x0:
return IMX_CHIP_REVISION_2_0;
case 0x10:
return IMX_CHIP_REVISION_3_0;
default:
return IMX_CHIP_REVISION_UNKNOWN;
}
}
int mx51_revision(void)
{
if (!cpu_is_mx51())
return -EINVAL;
if (mx5_cpu_rev == -1)
mx5_cpu_rev = get_mx51_srev();
return mx5_cpu_rev;
}
int __init mx51_neon_fixup(void)
{
if (mx51_revision() < IMX_CHIP_REVISION_3_0 &&
(elf_hwcap & HWCAP_NEON)) {
elf_hwcap &= ~HWCAP_NEON;
pr_info("Turning off NEON support, detected broken NEON implementation\n");
}
return 0;
}
static int get_mx53_srev(void)
{
void __iomem *iim_base = MX51_IO_ADDRESS(MX53_IIM_BASE_ADDR);
u32 rev = readl(iim_base + IIM_SREV) & 0xff;
switch (rev) {
case 0x0:
return IMX_CHIP_REVISION_1_0;
case 0x2:
return IMX_CHIP_REVISION_2_0;
case 0x3:
return IMX_CHIP_REVISION_2_1;
default:
return IMX_CHIP_REVISION_UNKNOWN;
}
}
int mx53_revision(void)
{
if (!cpu_is_mx53())
return -EINVAL;
if (mx5_cpu_rev == -1)
mx5_cpu_rev = get_mx53_srev();
return mx5_cpu_rev;
}
