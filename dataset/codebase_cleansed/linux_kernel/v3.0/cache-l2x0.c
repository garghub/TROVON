static int mxc_init_l2x0(void)
{
void __iomem *l2x0_base;
void __iomem *clkctl_base;
if (!cpu_is_mx31() && !cpu_is_mx35())
return 0;
#define L2_MEM_VAL 0x10
clkctl_base = ioremap(MX35_CLKCTL_BASE_ADDR, 4096);
if (clkctl_base != NULL) {
writel(0x00000515, clkctl_base + L2_MEM_VAL);
iounmap(clkctl_base);
} else {
pr_err("L2 cache: Cannot fix timing. Trying to continue without\n");
}
l2x0_base = ioremap(MX3x_L2CC_BASE_ADDR, 4096);
if (IS_ERR(l2x0_base)) {
printk(KERN_ERR "remapping L2 cache area failed with %ld\n",
PTR_ERR(l2x0_base));
return 0;
}
l2x0_init(l2x0_base, 0x00030024, 0x00000000);
return 0;
}
