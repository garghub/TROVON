static u32 __init mv88f5182_get_tclk_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_MV88F5182_TCLK_FREQ) &
SAR_MV88F5182_TCLK_FREQ_MASK;
if (opt == 1)
return 150000000;
else if (opt == 2)
return 166666667;
else
return 0;
}
static u32 __init mv88f5182_get_cpu_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_MV88F5182_CPU_FREQ) &
SAR_MV88F5182_CPU_FREQ_MASK;
if (opt == 0)
return 333333333;
else if (opt == 1 || opt == 2)
return 400000000;
else if (opt == 3)
return 500000000;
else
return 0;
}
static void __init mv88f5182_get_clk_ratio(void __iomem *sar, int id,
int *mult, int *div)
{
u32 opt = (readl(sar) >> SAR_MV88F5182_CPU_FREQ) &
SAR_MV88F5182_CPU_FREQ_MASK;
if (opt == 0 || opt == 1) {
*mult = 1;
*div = 2;
} else if (opt == 2 || opt == 3) {
*mult = 1;
*div = 3;
} else {
*mult = 0;
*div = 1;
}
}
static void __init mv88f5182_clk_init(struct device_node *np)
{
return mvebu_coreclk_setup(np, &mv88f5182_coreclks);
}
static u32 __init mv88f5281_get_tclk_freq(void __iomem *sar)
{
return 166666667;
}
static u32 __init mv88f5281_get_cpu_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_MV88F5281_CPU_FREQ) &
SAR_MV88F5281_CPU_FREQ_MASK;
if (opt == 1 || opt == 2)
return 400000000;
else if (opt == 3)
return 500000000;
else
return 0;
}
static void __init mv88f5281_get_clk_ratio(void __iomem *sar, int id,
int *mult, int *div)
{
u32 opt = (readl(sar) >> SAR_MV88F5281_CPU_FREQ) &
SAR_MV88F5281_CPU_FREQ_MASK;
if (opt == 1) {
*mult = 1;
*div = 2;
} else if (opt == 2 || opt == 3) {
*mult = 1;
*div = 3;
} else {
*mult = 0;
*div = 1;
}
}
static void __init mv88f5281_clk_init(struct device_node *np)
{
return mvebu_coreclk_setup(np, &mv88f5281_coreclks);
}
static u32 __init mv88f6183_get_tclk_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_MV88F6183_TCLK_FREQ) &
SAR_MV88F6183_TCLK_FREQ_MASK;
if (opt == 0)
return 133333333;
else if (opt == 1)
return 166666667;
else
return 0;
}
static u32 __init mv88f6183_get_cpu_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_MV88F6183_CPU_FREQ) &
SAR_MV88F6183_CPU_FREQ_MASK;
if (opt == 9)
return 333333333;
else if (opt == 17)
return 400000000;
else
return 0;
}
static void __init mv88f6183_get_clk_ratio(void __iomem *sar, int id,
int *mult, int *div)
{
u32 opt = (readl(sar) >> SAR_MV88F6183_CPU_FREQ) &
SAR_MV88F6183_CPU_FREQ_MASK;
if (opt == 9 || opt == 17) {
*mult = 1;
*div = 2;
} else {
*mult = 0;
*div = 1;
}
}
static void __init mv88f6183_clk_init(struct device_node *np)
{
return mvebu_coreclk_setup(np, &mv88f6183_coreclks);
}
