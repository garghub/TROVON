void gx_set_dclk_frequency(struct fb_info *info)
{
const struct gx_pll_entry *pll_table;
int pll_table_len;
int i, best_i;
long min, diff;
u64 dotpll, sys_rstpll;
int timeout = 1000;
if (cpu_data(0).x86_mask == 1) {
pll_table = gx_pll_table_14MHz;
pll_table_len = ARRAY_SIZE(gx_pll_table_14MHz);
} else {
pll_table = gx_pll_table_48MHz;
pll_table_len = ARRAY_SIZE(gx_pll_table_48MHz);
}
best_i = 0;
min = abs(pll_table[0].pixclock - info->var.pixclock);
for (i = 1; i < pll_table_len; i++) {
diff = abs(pll_table[i].pixclock - info->var.pixclock);
if (diff < min) {
min = diff;
best_i = i;
}
}
rdmsrl(MSR_GLCP_SYS_RSTPLL, sys_rstpll);
rdmsrl(MSR_GLCP_DOTPLL, dotpll);
dotpll &= 0x00000000ffffffffull;
dotpll |= (u64)pll_table[best_i].dotpll_value << 32;
dotpll |= MSR_GLCP_DOTPLL_DOTRESET;
dotpll &= ~MSR_GLCP_DOTPLL_BYPASS;
wrmsrl(MSR_GLCP_DOTPLL, dotpll);
sys_rstpll &= ~( MSR_GLCP_SYS_RSTPLL_DOTPREDIV2
| MSR_GLCP_SYS_RSTPLL_DOTPREMULT2
| MSR_GLCP_SYS_RSTPLL_DOTPOSTDIV3 );
sys_rstpll |= pll_table[best_i].sys_rstpll_bits;
wrmsrl(MSR_GLCP_SYS_RSTPLL, sys_rstpll);
dotpll &= ~(MSR_GLCP_DOTPLL_DOTRESET);
wrmsrl(MSR_GLCP_DOTPLL, dotpll);
do {
rdmsrl(MSR_GLCP_DOTPLL, dotpll);
} while (timeout-- && !(dotpll & MSR_GLCP_DOTPLL_LOCK));
}
static void
gx_configure_tft(struct fb_info *info)
{
struct gxfb_par *par = info->par;
unsigned long val;
unsigned long fp;
rdmsrl(MSR_GX_MSR_PADSEL, val);
val &= ~MSR_GX_MSR_PADSEL_MASK;
val |= MSR_GX_MSR_PADSEL_TFT;
wrmsrl(MSR_GX_MSR_PADSEL, val);
fp = read_fp(par, FP_PM);
fp &= ~FP_PM_P;
write_fp(par, FP_PM, fp);
fp = read_fp(par, FP_PT1);
fp &= FP_PT1_VSIZE_MASK;
fp |= info->var.yres << FP_PT1_VSIZE_SHIFT;
write_fp(par, FP_PT1, fp);
fp = 0x0F100000;
if (!(info->var.sync & FB_SYNC_VERT_HIGH_ACT))
fp |= FP_PT2_VSP;
if (!(info->var.sync & FB_SYNC_HOR_HIGH_ACT))
fp |= FP_PT2_HSP;
write_fp(par, FP_PT2, fp);
write_fp(par, FP_DFC, FP_DFC_NFI);
fp = read_vp(par, VP_DCFG);
fp |= VP_DCFG_FP_PWR_EN | VP_DCFG_FP_DATA_EN;
write_vp(par, VP_DCFG, fp);
fp = read_fp(par, FP_PM);
fp |= FP_PM_P;
write_fp(par, FP_PM, fp);
}
void gx_configure_display(struct fb_info *info)
{
struct gxfb_par *par = info->par;
u32 dcfg, misc;
dcfg = read_vp(par, VP_DCFG);
dcfg &= ~(VP_DCFG_VSYNC_EN | VP_DCFG_HSYNC_EN);
write_vp(par, VP_DCFG, dcfg);
dcfg &= ~(VP_DCFG_CRT_SYNC_SKW
| VP_DCFG_CRT_HSYNC_POL | VP_DCFG_CRT_VSYNC_POL
| VP_DCFG_VSYNC_EN | VP_DCFG_HSYNC_EN);
dcfg |= VP_DCFG_CRT_SYNC_SKW_DEFAULT;
dcfg |= VP_DCFG_HSYNC_EN | VP_DCFG_VSYNC_EN;
misc = read_vp(par, VP_MISC);
misc |= VP_MISC_GAM_EN;
if (par->enable_crt) {
misc &= ~(VP_MISC_APWRDN | VP_MISC_DACPWRDN);
write_vp(par, VP_MISC, misc);
if (!(info->var.sync & FB_SYNC_HOR_HIGH_ACT))
dcfg |= VP_DCFG_CRT_HSYNC_POL;
if (!(info->var.sync & FB_SYNC_VERT_HIGH_ACT))
dcfg |= VP_DCFG_CRT_VSYNC_POL;
} else {
misc |= (VP_MISC_APWRDN | VP_MISC_DACPWRDN);
write_vp(par, VP_MISC, misc);
}
dcfg |= VP_DCFG_CRT_EN | VP_DCFG_DAC_BL_EN;
write_vp(par, VP_DCFG, dcfg);
if (par->enable_crt == 0)
gx_configure_tft(info);
}
int gx_blank_display(struct fb_info *info, int blank_mode)
{
struct gxfb_par *par = info->par;
u32 dcfg, fp_pm;
int blank, hsync, vsync, crt;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
blank = 0; hsync = 1; vsync = 1; crt = 1;
break;
case FB_BLANK_NORMAL:
blank = 1; hsync = 1; vsync = 1; crt = 1;
break;
case FB_BLANK_VSYNC_SUSPEND:
blank = 1; hsync = 1; vsync = 0; crt = 1;
break;
case FB_BLANK_HSYNC_SUSPEND:
blank = 1; hsync = 0; vsync = 1; crt = 1;
break;
case FB_BLANK_POWERDOWN:
blank = 1; hsync = 0; vsync = 0; crt = 0;
break;
default:
return -EINVAL;
}
dcfg = read_vp(par, VP_DCFG);
dcfg &= ~(VP_DCFG_DAC_BL_EN | VP_DCFG_HSYNC_EN | VP_DCFG_VSYNC_EN |
VP_DCFG_CRT_EN);
if (!blank)
dcfg |= VP_DCFG_DAC_BL_EN;
if (hsync)
dcfg |= VP_DCFG_HSYNC_EN;
if (vsync)
dcfg |= VP_DCFG_VSYNC_EN;
if (crt)
dcfg |= VP_DCFG_CRT_EN;
write_vp(par, VP_DCFG, dcfg);
if (par->enable_crt == 0) {
fp_pm = read_fp(par, FP_PM);
if (blank_mode == FB_BLANK_POWERDOWN)
fp_pm &= ~FP_PM_P;
else
fp_pm |= FP_PM_P;
write_fp(par, FP_PM, fp_pm);
}
return 0;
}
