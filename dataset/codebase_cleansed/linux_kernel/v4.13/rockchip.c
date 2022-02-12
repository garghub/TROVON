static void __init rockchip_timer_init(void)
{
if (of_machine_is_compatible("rockchip,rk3288")) {
void __iomem *reg_base;
reg_base = ioremap(RK3288_TIMER6_7_PHYS, SZ_16K);
if (reg_base) {
writel(0, reg_base + 0x30);
writel(0xffffffff, reg_base + 0x20);
writel(0xffffffff, reg_base + 0x24);
writel(1, reg_base + 0x30);
dsb();
iounmap(reg_base);
} else {
pr_err("rockchip: could not map timer7 registers\n");
}
}
of_clk_init(NULL);
timer_probe();
}
static void __init rockchip_dt_init(void)
{
rockchip_suspend_init();
}
