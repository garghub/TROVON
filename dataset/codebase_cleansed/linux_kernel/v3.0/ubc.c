static void sh4a_ubc_enable(struct arch_hw_breakpoint *info, int idx)
{
__raw_writel(UBC_CBR_CE | info->len | info->type, UBC_CBR(idx));
__raw_writel(info->address, UBC_CAR(idx));
}
static void sh4a_ubc_disable(struct arch_hw_breakpoint *info, int idx)
{
__raw_writel(0, UBC_CBR(idx));
__raw_writel(0, UBC_CAR(idx));
}
static void sh4a_ubc_enable_all(unsigned long mask)
{
int i;
for (i = 0; i < sh4a_ubc.num_events; i++)
if (mask & (1 << i))
__raw_writel(__raw_readl(UBC_CBR(i)) | UBC_CBR_CE,
UBC_CBR(i));
}
static void sh4a_ubc_disable_all(void)
{
int i;
for (i = 0; i < sh4a_ubc.num_events; i++)
__raw_writel(__raw_readl(UBC_CBR(i)) & ~UBC_CBR_CE,
UBC_CBR(i));
}
static unsigned long sh4a_ubc_active_mask(void)
{
unsigned long active = 0;
int i;
for (i = 0; i < sh4a_ubc.num_events; i++)
if (__raw_readl(UBC_CBR(i)) & UBC_CBR_CE)
active |= (1 << i);
return active;
}
static unsigned long sh4a_ubc_triggered_mask(void)
{
return __raw_readl(UBC_CCMFR);
}
static void sh4a_ubc_clear_triggered_mask(unsigned long mask)
{
__raw_writel(__raw_readl(UBC_CCMFR) & ~mask, UBC_CCMFR);
}
static int __init sh4a_ubc_init(void)
{
struct clk *ubc_iclk = clk_get(NULL, "ubc0");
int i;
if (IS_ERR(ubc_iclk))
ubc_iclk = NULL;
clk_enable(ubc_iclk);
__raw_writel(0, UBC_CBCR);
for (i = 0; i < sh4a_ubc.num_events; i++) {
__raw_writel(0, UBC_CAMR(i));
__raw_writel(0, UBC_CBR(i));
__raw_writel(UBC_CRR_BIE | UBC_CRR_PCB, UBC_CRR(i));
(void)__raw_readl(UBC_CRR(i));
}
clk_disable(ubc_iclk);
sh4a_ubc.clk = ubc_iclk;
return register_sh_ubc(&sh4a_ubc);
}
