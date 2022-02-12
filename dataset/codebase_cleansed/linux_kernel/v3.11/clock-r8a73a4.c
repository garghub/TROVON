static unsigned long pll_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (ioread32(CPG_MAP(PLLECR)) & (1 << clk->enable_bit))
mult = (((ioread32(clk->mapped_reg) >> 24) & 0x7f) + 1);
return clk->parent->rate * mult;
}
static int pll_set_parent(struct clk *clk, struct clk *parent)
{
u32 val;
int i, ret;
if (!clk->parent_table || !clk->parent_num)
return -EINVAL;
for (i = 0; i < clk->parent_num; i++)
if (clk->parent_table[i] == parent)
break;
if (i == clk->parent_num)
return -ENODEV;
ret = clk_reparent(clk, parent);
if (ret < 0)
return ret;
val = ioread32(clk->mapped_reg) &
~(((1 << clk->src_width) - 1) << clk->src_shift);
iowrite32(val | i << clk->src_shift, clk->mapped_reg);
return 0;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = ioread32(CPG_MAP(FRQCRB));
value |= (1 << 31);
iowrite32(value, CPG_MAP(FRQCRB));
}
void __init r8a73a4_clock_init(void)
{
void __iomem *reg;
int k, ret = 0;
u32 ckscr;
reg = ioremap_nocache(CKSCR, PAGE_SIZE);
BUG_ON(!reg);
ckscr = ioread32(reg);
iounmap(reg);
switch ((ckscr >> 28) & 0x3) {
case 0:
main_clk.parent = &extal1_clk;
break;
case 1:
main_clk.parent = &extal1_div2_clk;
break;
case 2:
main_clk.parent = &extal2_clk;
break;
case 3:
main_clk.parent = &extal2_div2_clk;
break;
}
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_reparent_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a73a4 clocks\n");
}
