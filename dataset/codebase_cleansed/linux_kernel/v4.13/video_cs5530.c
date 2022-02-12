static void cs5530_set_dclk_frequency(struct fb_info *info)
{
struct geodefb_par *par = info->par;
int i;
u32 value;
long min, diff;
value = cs5530_pll_table[0].pll_value;
min = cs5530_pll_table[0].pixclock - info->var.pixclock;
if (min < 0) min = -min;
for (i = 1; i < ARRAY_SIZE(cs5530_pll_table); i++) {
diff = cs5530_pll_table[i].pixclock - info->var.pixclock;
if (diff < 0L) diff = -diff;
if (diff < min) {
min = diff;
value = cs5530_pll_table[i].pll_value;
}
}
writel(value, par->vid_regs + CS5530_DOT_CLK_CONFIG);
writel(value | 0x80000100, par->vid_regs + CS5530_DOT_CLK_CONFIG);
udelay(500);
writel(value & 0x7FFFFFFF, par->vid_regs + CS5530_DOT_CLK_CONFIG);
writel(value & 0x7FFFFEFF, par->vid_regs + CS5530_DOT_CLK_CONFIG);
}
static void cs5530_configure_display(struct fb_info *info)
{
struct geodefb_par *par = info->par;
u32 dcfg;
dcfg = readl(par->vid_regs + CS5530_DISPLAY_CONFIG);
dcfg &= ~(CS5530_DCFG_CRT_SYNC_SKW_MASK | CS5530_DCFG_PWR_SEQ_DLY_MASK
| CS5530_DCFG_CRT_HSYNC_POL | CS5530_DCFG_CRT_VSYNC_POL
| CS5530_DCFG_FP_PWR_EN | CS5530_DCFG_FP_DATA_EN
| CS5530_DCFG_DAC_PWR_EN | CS5530_DCFG_VSYNC_EN
| CS5530_DCFG_HSYNC_EN);
dcfg |= (CS5530_DCFG_CRT_SYNC_SKW_INIT | CS5530_DCFG_PWR_SEQ_DLY_INIT
| CS5530_DCFG_GV_PAL_BYP);
if (par->enable_crt) {
dcfg |= CS5530_DCFG_DAC_PWR_EN;
dcfg |= CS5530_DCFG_HSYNC_EN | CS5530_DCFG_VSYNC_EN;
}
if (par->panel_x > 0) {
dcfg |= CS5530_DCFG_FP_PWR_EN;
dcfg |= CS5530_DCFG_FP_DATA_EN;
}
if (info->var.sync & FB_SYNC_HOR_HIGH_ACT)
dcfg |= CS5530_DCFG_CRT_HSYNC_POL;
if (info->var.sync & FB_SYNC_VERT_HIGH_ACT)
dcfg |= CS5530_DCFG_CRT_VSYNC_POL;
writel(dcfg, par->vid_regs + CS5530_DISPLAY_CONFIG);
}
static int cs5530_blank_display(struct fb_info *info, int blank_mode)
{
struct geodefb_par *par = info->par;
u32 dcfg;
int blank, hsync, vsync;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
blank = 0; hsync = 1; vsync = 1;
break;
case FB_BLANK_NORMAL:
blank = 1; hsync = 1; vsync = 1;
break;
case FB_BLANK_VSYNC_SUSPEND:
blank = 1; hsync = 1; vsync = 0;
break;
case FB_BLANK_HSYNC_SUSPEND:
blank = 1; hsync = 0; vsync = 1;
break;
case FB_BLANK_POWERDOWN:
blank = 1; hsync = 0; vsync = 0;
break;
default:
return -EINVAL;
}
dcfg = readl(par->vid_regs + CS5530_DISPLAY_CONFIG);
dcfg &= ~(CS5530_DCFG_DAC_BL_EN | CS5530_DCFG_DAC_PWR_EN
| CS5530_DCFG_HSYNC_EN | CS5530_DCFG_VSYNC_EN
| CS5530_DCFG_FP_DATA_EN | CS5530_DCFG_FP_PWR_EN);
if (par->enable_crt) {
if (!blank)
dcfg |= CS5530_DCFG_DAC_BL_EN | CS5530_DCFG_DAC_PWR_EN;
if (hsync)
dcfg |= CS5530_DCFG_HSYNC_EN;
if (vsync)
dcfg |= CS5530_DCFG_VSYNC_EN;
}
if (par->panel_x > 0) {
if (!blank)
dcfg |= CS5530_DCFG_FP_DATA_EN;
if (hsync && vsync)
dcfg |= CS5530_DCFG_FP_PWR_EN;
}
writel(dcfg, par->vid_regs + CS5530_DISPLAY_CONFIG);
return 0;
}
