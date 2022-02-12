void __init r8a7791_clock_init(void)
{
void __iomem *modemr = ioremap_nocache(MODEMR, PAGE_SIZE);
u32 mode;
int k, ret = 0;
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
switch (mode & (MD(14) | MD(13))) {
case 0:
R8A7791_CLOCK_ROOT(15, &extal_clk, 172, 208, 106, 88);
break;
case MD(13):
R8A7791_CLOCK_ROOT(20, &extal_clk, 130, 156, 80, 66);
break;
case MD(14):
R8A7791_CLOCK_ROOT(26, &extal_div2_clk, 200, 240, 122, 102);
break;
case MD(13) | MD(14):
R8A7791_CLOCK_ROOT(30, &extal_div2_clk, 172, 208, 106, 88);
break;
}
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
goto epanic;
return;
epanic:
panic("failed to setup r8a7791 clocks\n");
}
