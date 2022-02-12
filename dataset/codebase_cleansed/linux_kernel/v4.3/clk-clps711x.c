static struct clps711x_clk * __init _clps711x_clk_init(void __iomem *base,
u32 fref)
{
u32 tmp, f_cpu, f_pll, f_bus, f_tim, f_pwm, f_spi;
struct clps711x_clk *clps711x_clk;
unsigned i;
if (!base)
return ERR_PTR(-ENOMEM);
clps711x_clk = kzalloc(sizeof(*clps711x_clk), GFP_KERNEL);
if (!clps711x_clk)
return ERR_PTR(-ENOMEM);
spin_lock_init(&clps711x_clk->lock);
tmp = readl(base + CLPS711X_PLLR) >> 24;
if (((tmp >= 10) && (tmp <= 50)) || !fref)
f_pll = DIV_ROUND_UP(CLPS711X_OSC_FREQ * tmp, 2);
else
f_pll = fref;
tmp = readl(base + CLPS711X_SYSFLG2);
if (tmp & SYSFLG2_CKMODE) {
f_cpu = CLPS711X_EXT_FREQ;
f_bus = CLPS711X_EXT_FREQ;
f_spi = DIV_ROUND_CLOSEST(CLPS711X_EXT_FREQ, 96);
f_pll = 0;
f_pwm = DIV_ROUND_CLOSEST(CLPS711X_EXT_FREQ, 128);
} else {
f_cpu = f_pll;
if (f_cpu > 36864000)
f_bus = DIV_ROUND_UP(f_cpu, 2);
else
f_bus = 36864000 / 2;
f_spi = DIV_ROUND_CLOSEST(f_cpu, 576);
f_pwm = DIV_ROUND_CLOSEST(f_cpu, 768);
}
if (tmp & SYSFLG2_CKMODE) {
if (readl(base + CLPS711X_SYSCON2) & SYSCON2_OSTB)
f_tim = DIV_ROUND_CLOSEST(CLPS711X_EXT_FREQ, 26);
else
f_tim = DIV_ROUND_CLOSEST(CLPS711X_EXT_FREQ, 24);
} else
f_tim = DIV_ROUND_CLOSEST(f_cpu, 144);
tmp = readl(base + CLPS711X_SYSCON1);
tmp &= ~(SYSCON1_TC1M | SYSCON1_TC1S);
tmp |= SYSCON1_TC2M | SYSCON1_TC2S;
writel(tmp, base + CLPS711X_SYSCON1);
clps711x_clk->clks[CLPS711X_CLK_DUMMY] =
clk_register_fixed_rate(NULL, "dummy", NULL, CLK_IS_ROOT, 0);
clps711x_clk->clks[CLPS711X_CLK_CPU] =
clk_register_fixed_rate(NULL, "cpu", NULL, CLK_IS_ROOT, f_cpu);
clps711x_clk->clks[CLPS711X_CLK_BUS] =
clk_register_fixed_rate(NULL, "bus", NULL, CLK_IS_ROOT, f_bus);
clps711x_clk->clks[CLPS711X_CLK_PLL] =
clk_register_fixed_rate(NULL, "pll", NULL, CLK_IS_ROOT, f_pll);
clps711x_clk->clks[CLPS711X_CLK_TIMERREF] =
clk_register_fixed_rate(NULL, "timer_ref", NULL, CLK_IS_ROOT,
f_tim);
clps711x_clk->clks[CLPS711X_CLK_TIMER1] =
clk_register_divider_table(NULL, "timer1", "timer_ref", 0,
base + CLPS711X_SYSCON1, 5, 1, 0,
timer_div_table, &clps711x_clk->lock);
clps711x_clk->clks[CLPS711X_CLK_TIMER2] =
clk_register_divider_table(NULL, "timer2", "timer_ref", 0,
base + CLPS711X_SYSCON1, 7, 1, 0,
timer_div_table, &clps711x_clk->lock);
clps711x_clk->clks[CLPS711X_CLK_PWM] =
clk_register_fixed_rate(NULL, "pwm", NULL, CLK_IS_ROOT, f_pwm);
clps711x_clk->clks[CLPS711X_CLK_SPIREF] =
clk_register_fixed_rate(NULL, "spi_ref", NULL, CLK_IS_ROOT,
f_spi);
clps711x_clk->clks[CLPS711X_CLK_SPI] =
clk_register_divider_table(NULL, "spi", "spi_ref", 0,
base + CLPS711X_SYSCON1, 16, 2, 0,
spi_div_table, &clps711x_clk->lock);
clps711x_clk->clks[CLPS711X_CLK_UART] =
clk_register_fixed_factor(NULL, "uart", "bus", 0, 1, 10);
clps711x_clk->clks[CLPS711X_CLK_TICK] =
clk_register_fixed_rate(NULL, "tick", NULL, CLK_IS_ROOT, 64);
for (i = 0; i < CLPS711X_CLK_MAX; i++)
if (IS_ERR(clps711x_clk->clks[i]))
pr_err("clk %i: register failed with %ld\n",
i, PTR_ERR(clps711x_clk->clks[i]));
return clps711x_clk;
}
void __init clps711x_clk_init(void __iomem *base)
{
struct clps711x_clk *clps711x_clk;
clps711x_clk = _clps711x_clk_init(base, 73728000);
BUG_ON(IS_ERR(clps711x_clk));
clk_register_clkdev(clps711x_clk->clks[CLPS711X_CLK_TIMER1],
NULL, "clps711x-timer.0");
clk_register_clkdev(clps711x_clk->clks[CLPS711X_CLK_TIMER2],
NULL, "clps711x-timer.1");
clk_register_clkdev(clps711x_clk->clks[CLPS711X_CLK_PWM],
NULL, "clps711x-pwm");
clk_register_clkdev(clps711x_clk->clks[CLPS711X_CLK_UART],
NULL, "clps711x-uart.0");
clk_register_clkdev(clps711x_clk->clks[CLPS711X_CLK_UART],
NULL, "clps711x-uart.1");
}
static void __init clps711x_clk_init_dt(struct device_node *np)
{
void __iomem *base = of_iomap(np, 0);
struct clps711x_clk *clps711x_clk;
u32 fref = 0;
WARN_ON(of_property_read_u32(np, "startup-frequency", &fref));
clps711x_clk = _clps711x_clk_init(base, fref);
BUG_ON(IS_ERR(clps711x_clk));
clps711x_clk->clk_data.clks = clps711x_clk->clks;
clps711x_clk->clk_data.clk_num = CLPS711X_CLK_MAX;
of_clk_add_provider(np, of_clk_src_onecell_get,
&clps711x_clk->clk_data);
}
