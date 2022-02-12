static int s3c2412_clkcon_enable(struct clk *clk, int enable)
{
unsigned int clocks = clk->ctrlbit;
unsigned long clkcon;
clkcon = __raw_readl(S3C2410_CLKCON);
if (enable)
clkcon |= clocks;
else
clkcon &= ~clocks;
__raw_writel(clkcon, S3C2410_CLKCON);
return 0;
}
static int s3c2412_upll_enable(struct clk *clk, int enable)
{
unsigned long upllcon = __raw_readl(S3C2410_UPLLCON);
unsigned long orig = upllcon;
if (!enable)
upllcon |= S3C2412_PLLCON_OFF;
else
upllcon &= ~S3C2412_PLLCON_OFF;
__raw_writel(upllcon, S3C2410_UPLLCON);
if (enable && (orig & S3C2412_PLLCON_OFF))
udelay(150);
return 0;
}
static int s3c2412_setparent_usysclk(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
if (parent == &clk_urefclk)
clksrc &= ~S3C2412_CLKSRC_USYSCLK_UPLL;
else if (parent == &clk_upll)
clksrc |= S3C2412_CLKSRC_USYSCLK_UPLL;
else
return -EINVAL;
clk->parent = parent;
__raw_writel(clksrc, S3C2412_CLKSRC);
return 0;
}
static int s3c2412_setparent_usbsrc(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
if (parent == &clk_usysclk)
clksrc &= ~S3C2412_CLKSRC_USBCLK_HCLK;
else if (parent == &clk_h)
clksrc |= S3C2412_CLKSRC_USBCLK_HCLK;
else
return -EINVAL;
clk->parent = parent;
__raw_writel(clksrc, S3C2412_CLKSRC);
return 0;
}
static unsigned long s3c2412_roundrate_usbsrc(struct clk *clk,
unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
int div;
if (rate > parent_rate)
return parent_rate;
div = parent_rate / rate;
if (div > 2)
div = 2;
return parent_rate / div;
}
static unsigned long s3c2412_getrate_usbsrc(struct clk *clk)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long div = __raw_readl(S3C2410_CLKDIVN);
return parent_rate / ((div & S3C2412_CLKDIVN_USB48DIV) ? 2 : 1);
}
static int s3c2412_setrate_usbsrc(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long clkdivn = __raw_readl(S3C2410_CLKDIVN);
rate = s3c2412_roundrate_usbsrc(clk, rate);
if ((parent_rate / rate) == 2)
clkdivn |= S3C2412_CLKDIVN_USB48DIV;
else
clkdivn &= ~S3C2412_CLKDIVN_USB48DIV;
__raw_writel(clkdivn, S3C2410_CLKDIVN);
return 0;
}
static int s3c2412_setparent_msysclk(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
if (parent == &clk_mdivclk)
clksrc &= ~S3C2412_CLKSRC_MSYSCLK_MPLL;
else if (parent == &clk_mpll)
clksrc |= S3C2412_CLKSRC_MSYSCLK_MPLL;
else
return -EINVAL;
clk->parent = parent;
__raw_writel(clksrc, S3C2412_CLKSRC);
return 0;
}
static int s3c2412_setparent_armclk(struct clk *clk, struct clk *parent)
{
unsigned long flags;
unsigned long clkdiv;
unsigned long dvs;
if (parent == &clk_msysclk || parent == &clk_f)
dvs = 0;
else if (parent == &clk_h)
dvs = S3C2412_CLKDIVN_DVSEN;
else
return -EINVAL;
clk->parent = parent;
local_irq_save(flags);
clkdiv = __raw_readl(S3C2410_CLKDIVN);
clkdiv &= ~S3C2412_CLKDIVN_DVSEN;
clkdiv |= dvs;
__raw_writel(clkdiv, S3C2410_CLKDIVN);
local_irq_restore(flags);
return 0;
}
static unsigned long s3c2412_roundrate_clksrc(struct clk *clk,
unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
int div;
if (rate > parent_rate)
return parent_rate;
div = (rate / parent_rate);
if (div < 1)
div = 1;
else if (div > 16)
div = 16;
return parent_rate / div;
}
static int s3c2412_setparent_uart(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
if (parent == &clk_erefclk)
clksrc &= ~S3C2412_CLKSRC_UARTCLK_MPLL;
else if (parent == &clk_mpll)
clksrc |= S3C2412_CLKSRC_UARTCLK_MPLL;
else
return -EINVAL;
clk->parent = parent;
__raw_writel(clksrc, S3C2412_CLKSRC);
return 0;
}
static unsigned long s3c2412_getrate_uart(struct clk *clk)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long div = __raw_readl(S3C2410_CLKDIVN);
div &= S3C2412_CLKDIVN_UARTDIV_MASK;
div >>= S3C2412_CLKDIVN_UARTDIV_SHIFT;
return parent_rate / (div + 1);
}
static int s3c2412_setrate_uart(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long clkdivn = __raw_readl(S3C2410_CLKDIVN);
rate = s3c2412_roundrate_clksrc(clk, rate);
clkdivn &= ~S3C2412_CLKDIVN_UARTDIV_MASK;
clkdivn |= ((parent_rate / rate) - 1) << S3C2412_CLKDIVN_UARTDIV_SHIFT;
__raw_writel(clkdivn, S3C2410_CLKDIVN);
return 0;
}
static int s3c2412_setparent_i2s(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
if (parent == &clk_erefclk)
clksrc &= ~S3C2412_CLKSRC_I2SCLK_MPLL;
else if (parent == &clk_mpll)
clksrc |= S3C2412_CLKSRC_I2SCLK_MPLL;
else
return -EINVAL;
clk->parent = parent;
__raw_writel(clksrc, S3C2412_CLKSRC);
return 0;
}
static unsigned long s3c2412_getrate_i2s(struct clk *clk)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long div = __raw_readl(S3C2410_CLKDIVN);
div &= S3C2412_CLKDIVN_I2SDIV_MASK;
div >>= S3C2412_CLKDIVN_I2SDIV_SHIFT;
return parent_rate / (div + 1);
}
static int s3c2412_setrate_i2s(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long clkdivn = __raw_readl(S3C2410_CLKDIVN);
rate = s3c2412_roundrate_clksrc(clk, rate);
clkdivn &= ~S3C2412_CLKDIVN_I2SDIV_MASK;
clkdivn |= ((parent_rate / rate) - 1) << S3C2412_CLKDIVN_I2SDIV_SHIFT;
__raw_writel(clkdivn, S3C2410_CLKDIVN);
return 0;
}
static int s3c2412_setparent_cam(struct clk *clk, struct clk *parent)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
if (parent == &clk_usysclk)
clksrc &= ~S3C2412_CLKSRC_CAMCLK_HCLK;
else if (parent == &clk_h)
clksrc |= S3C2412_CLKSRC_CAMCLK_HCLK;
else
return -EINVAL;
clk->parent = parent;
__raw_writel(clksrc, S3C2412_CLKSRC);
return 0;
}
static unsigned long s3c2412_getrate_cam(struct clk *clk)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long div = __raw_readl(S3C2410_CLKDIVN);
div &= S3C2412_CLKDIVN_CAMDIV_MASK;
div >>= S3C2412_CLKDIVN_CAMDIV_SHIFT;
return parent_rate / (div + 1);
}
static int s3c2412_setrate_cam(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long clkdivn = __raw_readl(S3C2410_CLKDIVN);
rate = s3c2412_roundrate_clksrc(clk, rate);
clkdivn &= ~S3C2412_CLKDIVN_CAMDIV_MASK;
clkdivn |= ((parent_rate / rate) - 1) << S3C2412_CLKDIVN_CAMDIV_SHIFT;
__raw_writel(clkdivn, S3C2410_CLKDIVN);
return 0;
}
static void __init s3c2412_clk_initparents(void)
{
unsigned long clksrc = __raw_readl(S3C2412_CLKSRC);
struct clk_init *cip = clks_src;
struct clk *src;
int ptr;
int ret;
for (ptr = 0; ptr < ARRAY_SIZE(clks_src); ptr++, cip++) {
ret = s3c24xx_register_clock(cip->clk);
if (ret < 0) {
printk(KERN_ERR "Failed to register clock %s (%d)\n",
cip->clk->name, ret);
}
src = (clksrc & cip->bit) ? cip->src_1 : cip->src_0;
printk(KERN_INFO "%s: parent %s\n", cip->clk->name, src->name);
clk_set_parent(cip->clk, src);
}
}
int __init s3c2412_baseclk_add(void)
{
unsigned long clkcon = __raw_readl(S3C2410_CLKCON);
unsigned int dvs;
struct clk *clkp;
int ret;
int ptr;
clk_upll.enable = s3c2412_upll_enable;
clk_usb_bus.parent = &clk_usbsrc;
clk_usb_bus.rate = 0x0;
clk_f.parent = &clk_msysclk;
s3c2412_clk_initparents();
for (ptr = 0; ptr < ARRAY_SIZE(clks); ptr++) {
clkp = clks[ptr];
ret = s3c24xx_register_clock(clkp);
if (ret < 0) {
printk(KERN_ERR "Failed to register clock %s (%d)\n",
clkp->name, ret);
}
}
dvs = __raw_readl(S3C2410_CLKDIVN) & S3C2412_CLKDIVN_DVSEN;
if (dvs)
clk_armclk.parent = &clk_h;
printk(KERN_INFO "S3C2412: DVS is %s\n", dvs ? "on" : "off");
if (clk_get_rate(&clk_usb_bus) != (48 * 1000 * 1000)) {
printk(KERN_INFO "Warning: USB bus clock not at 48MHz\n");
clk_set_parent(&clk_usysclk, &clk_upll);
clk_set_parent(&clk_usbsrc, &clk_usysclk);
clk_set_rate(&clk_usbsrc, 48*1000*1000);
}
printk("S3C2412: upll %s, %ld.%03ld MHz, usb-bus %ld.%03ld MHz\n",
(__raw_readl(S3C2410_UPLLCON) & S3C2412_PLLCON_OFF) ? "off":"on",
print_mhz(clk_get_rate(&clk_upll)),
print_mhz(clk_get_rate(&clk_usb_bus)));
clkp = init_clocks;
for (ptr = 0; ptr < ARRAY_SIZE(init_clocks); ptr++, clkp++) {
clkp->usage = clkcon & clkp->ctrlbit ? 1 : 0;
ret = s3c24xx_register_clock(clkp);
if (ret < 0) {
printk(KERN_ERR "Failed to register clock %s (%d)\n",
clkp->name, ret);
}
}
clkp = init_clocks_disable;
for (ptr = 0; ptr < ARRAY_SIZE(init_clocks_disable); ptr++, clkp++) {
ret = s3c24xx_register_clock(clkp);
if (ret < 0) {
printk(KERN_ERR "Failed to register clock %s (%d)\n",
clkp->name, ret);
}
s3c2412_clkcon_enable(clkp, 0);
}
clkdev_add_table(s3c2412_clk_lookup, ARRAY_SIZE(s3c2412_clk_lookup));
s3c_pwmclk_init();
return 0;
}
