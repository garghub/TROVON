static u8 gx1_read_conf_reg(u8 reg)
{
u8 val, ccr3;
unsigned long flags;
spin_lock_irqsave(&gx1_conf_reg_lock, flags);
outb(CONFIG_CCR3, 0x22);
ccr3 = inb(0x23);
outb(CONFIG_CCR3, 0x22);
outb(ccr3 | CONFIG_CCR3_MAPEN, 0x23);
outb(reg, 0x22);
val = inb(0x23);
outb(CONFIG_CCR3, 0x22);
outb(ccr3, 0x23);
spin_unlock_irqrestore(&gx1_conf_reg_lock, flags);
return val;
}
unsigned gx1_gx_base(void)
{
return (gx1_read_conf_reg(CONFIG_GCR) & 0x03) << 30;
}
int gx1_frame_buffer_size(void)
{
void __iomem *mc_regs;
u32 bank_cfg;
int d;
unsigned dram_size = 0, fb_base;
mc_regs = ioremap(gx1_gx_base() + 0x8400, 0x100);
if (!mc_regs)
return -ENOMEM;
bank_cfg = readl(mc_regs + MC_BANK_CFG);
for (d = 0; d < 2; d++) {
if ((bank_cfg & MC_BCFG_DIMM0_PG_SZ_MASK) != MC_BCFG_DIMM0_PG_SZ_NO_DIMM)
dram_size += 0x400000 << ((bank_cfg & MC_BCFG_DIMM0_SZ_MASK) >> 8);
bank_cfg >>= 16;
}
fb_base = (readl(mc_regs + MC_GBASE_ADD) & MC_GADD_GBADD_MASK) << 19;
iounmap(mc_regs);
return dram_size - fb_base;
}
static void gx1_set_mode(struct fb_info *info)
{
struct geodefb_par *par = info->par;
u32 gcfg, tcfg, ocfg, dclk_div, val;
int hactive, hblankstart, hsyncstart, hsyncend, hblankend, htotal;
int vactive, vblankstart, vsyncstart, vsyncend, vblankend, vtotal;
readl(par->dc_regs + DC_UNLOCK);
writel(DC_UNLOCK_CODE, par->dc_regs + DC_UNLOCK);
gcfg = readl(par->dc_regs + DC_GENERAL_CFG);
tcfg = readl(par->dc_regs + DC_TIMING_CFG);
tcfg &= ~(DC_TCFG_BLKE | DC_TCFG_TGEN);
writel(tcfg, par->dc_regs + DC_TIMING_CFG);
udelay(100);
gcfg &= ~(DC_GCFG_DFLE | DC_GCFG_CMPE | DC_GCFG_DECE);
writel(gcfg, par->dc_regs + DC_GENERAL_CFG);
gcfg &= ~DC_GCFG_DCLK_MASK;
writel(gcfg, par->dc_regs + DC_GENERAL_CFG);
par->vid_ops->set_dclk(info);
dclk_div = DC_GCFG_DCLK_DIV_1;
gcfg |= dclk_div;
writel(gcfg, par->dc_regs + DC_GENERAL_CFG);
udelay(1000);
gcfg = DC_GCFG_VRDY | dclk_div;
gcfg |= (6 << DC_GCFG_DFHPEL_POS) | (5 << DC_GCFG_DFHPSL_POS) | DC_GCFG_DFLE;
writel(0, par->dc_regs + DC_FB_ST_OFFSET);
writel(info->fix.line_length >> 2, par->dc_regs + DC_LINE_DELTA);
writel(((info->var.xres * info->var.bits_per_pixel/8) >> 3) + 2,
par->dc_regs + DC_BUF_SIZE);
ocfg = DC_OCFG_PCKE | DC_OCFG_PDEL | DC_OCFG_PDEH;
if (info->var.bits_per_pixel == 8) ocfg |= DC_OCFG_8BPP;
tcfg = DC_TCFG_FPPE | DC_TCFG_HSYE | DC_TCFG_VSYE | DC_TCFG_BLKE
| DC_TCFG_TGEN;
hactive = info->var.xres;
hblankstart = hactive;
hsyncstart = hblankstart + info->var.right_margin;
hsyncend = hsyncstart + info->var.hsync_len;
hblankend = hsyncend + info->var.left_margin;
htotal = hblankend;
vactive = info->var.yres;
vblankstart = vactive;
vsyncstart = vblankstart + info->var.lower_margin;
vsyncend = vsyncstart + info->var.vsync_len;
vblankend = vsyncend + info->var.upper_margin;
vtotal = vblankend;
val = (hactive - 1) | ((htotal - 1) << 16);
writel(val, par->dc_regs + DC_H_TIMING_1);
val = (hblankstart - 1) | ((hblankend - 1) << 16);
writel(val, par->dc_regs + DC_H_TIMING_2);
val = (hsyncstart - 1) | ((hsyncend - 1) << 16);
writel(val, par->dc_regs + DC_H_TIMING_3);
writel(val, par->dc_regs + DC_FP_H_TIMING);
val = (vactive - 1) | ((vtotal - 1) << 16);
writel(val, par->dc_regs + DC_V_TIMING_1);
val = (vblankstart - 1) | ((vblankend - 1) << 16);
writel(val, par->dc_regs + DC_V_TIMING_2);
val = (vsyncstart - 1) | ((vsyncend - 1) << 16);
writel(val, par->dc_regs + DC_V_TIMING_3);
val = (vsyncstart - 2) | ((vsyncend - 2) << 16);
writel(val, par->dc_regs + DC_FP_V_TIMING);
writel(ocfg, par->dc_regs + DC_OUTPUT_CFG);
writel(tcfg, par->dc_regs + DC_TIMING_CFG);
udelay(1000);
writel(gcfg, par->dc_regs + DC_GENERAL_CFG);
par->vid_ops->configure_display(info);
writel(0, par->dc_regs + DC_UNLOCK);
}
static void gx1_set_hw_palette_reg(struct fb_info *info, unsigned regno,
unsigned red, unsigned green, unsigned blue)
{
struct geodefb_par *par = info->par;
int val;
val = (red << 2) & 0x3f000;
val |= (green >> 4) & 0x00fc0;
val |= (blue >> 10) & 0x0003f;
writel(regno, par->dc_regs + DC_PAL_ADDRESS);
writel(val, par->dc_regs + DC_PAL_DATA);
}
