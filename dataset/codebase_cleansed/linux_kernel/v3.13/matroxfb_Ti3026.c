static int Ti3026_calcclock(const struct matrox_fb_info *minfo,
unsigned int freq, unsigned int fmax, int *in,
int *feed, int *post)
{
unsigned int fvco;
unsigned int lin, lfeed, lpost;
DBG(__func__)
fvco = PLL_calcclock(minfo, freq, fmax, &lin, &lfeed, &lpost);
fvco >>= (*post = lpost);
*in = 64 - lin;
*feed = 64 - lfeed;
return fvco;
}
static int Ti3026_setpclk(struct matrox_fb_info *minfo, int clk)
{
unsigned int f_pll;
unsigned int pixfeed, pixin, pixpost;
struct matrox_hw_state *hw = &minfo->hw;
DBG(__func__)
f_pll = Ti3026_calcclock(minfo, clk, minfo->max_pixel_clock, &pixin, &pixfeed, &pixpost);
hw->DACclk[0] = pixin | 0xC0;
hw->DACclk[1] = pixfeed;
hw->DACclk[2] = pixpost | 0xB0;
{
unsigned int loopfeed, loopin, looppost, loopdiv, z;
unsigned int Bpp;
Bpp = minfo->curr.final_bppShift;
if (minfo->fbcon.var.bits_per_pixel == 24) {
loopfeed = 3;
loopin = 3 * 32 / Bpp;
} else {
loopfeed = 4;
loopin = 4 * 32 / Bpp;
}
z = (110000 * loopin) / (f_pll * loopfeed);
loopdiv = 0;
if (z < 2)
looppost = 0;
else if (z < 4)
looppost = 1;
else if (z < 8)
looppost = 2;
else {
looppost = 3;
loopdiv = z/16;
}
if (minfo->fbcon.var.bits_per_pixel == 24) {
hw->DACclk[3] = ((65 - loopin) & 0x3F) | 0xC0;
hw->DACclk[4] = (65 - loopfeed) | 0x80;
if (minfo->accel.ramdac_rev > 0x20) {
if (isInterleave(minfo))
hw->DACreg[POS3026_XLATCHCTRL] = TVP3026B_XLATCHCTRL_8_3;
else {
hw->DACclk[4] &= ~0xC0;
hw->DACreg[POS3026_XLATCHCTRL] = TVP3026B_XLATCHCTRL_4_3;
}
} else {
if (isInterleave(minfo))
;
else {
hw->DACclk[4] ^= 0xC0;
hw->DACreg[POS3026_XLATCHCTRL] = TVP3026A_XLATCHCTRL_4_3;
}
}
hw->DACclk[5] = looppost | 0xF8;
if (minfo->devflags.mga_24bpp_fix)
hw->DACclk[5] ^= 0x40;
} else {
hw->DACclk[3] = ((65 - loopin) & 0x3F) | 0xC0;
hw->DACclk[4] = 65 - loopfeed;
hw->DACclk[5] = looppost | 0xF0;
}
hw->DACreg[POS3026_XMEMPLLCTRL] = loopdiv | TVP3026_XMEMPLLCTRL_MCLK_MCLKPLL | TVP3026_XMEMPLLCTRL_RCLK_LOOPPLL;
}
return 0;
}
static int Ti3026_init(struct matrox_fb_info *minfo, struct my_timming *m)
{
u_int8_t muxctrl = isInterleave(minfo) ? TVP3026_XMUXCTRL_MEMORY_64BIT : TVP3026_XMUXCTRL_MEMORY_32BIT;
struct matrox_hw_state *hw = &minfo->hw;
DBG(__func__)
memcpy(hw->DACreg, MGADACbpp32, sizeof(hw->DACreg));
switch (minfo->fbcon.var.bits_per_pixel) {
case 4: hw->DACreg[POS3026_XLATCHCTRL] = TVP3026_XLATCHCTRL_16_1;
hw->DACreg[POS3026_XTRUECOLORCTRL] = TVP3026_XTRUECOLORCTRL_PSEUDOCOLOR;
hw->DACreg[POS3026_XMUXCTRL] = muxctrl | TVP3026_XMUXCTRL_PIXEL_4BIT;
hw->DACreg[POS3026_XCLKCTRL] = TVP3026_XCLKCTRL_SRC_PLL | TVP3026_XCLKCTRL_DIV8;
hw->DACreg[POS3026_XMISCCTRL] = TVP3026_XMISCCTRL_DAC_PUP | TVP3026_XMISCCTRL_DAC_8BIT | TVP3026_XMISCCTRL_PSEL_DIS | TVP3026_XMISCCTRL_PSEL_LOW;
break;
case 8: hw->DACreg[POS3026_XLATCHCTRL] = TVP3026_XLATCHCTRL_8_1;
hw->DACreg[POS3026_XTRUECOLORCTRL] = TVP3026_XTRUECOLORCTRL_PSEUDOCOLOR;
hw->DACreg[POS3026_XMUXCTRL] = muxctrl | TVP3026_XMUXCTRL_PIXEL_8BIT;
hw->DACreg[POS3026_XCLKCTRL] = TVP3026_XCLKCTRL_SRC_PLL | TVP3026_XCLKCTRL_DIV4;
hw->DACreg[POS3026_XMISCCTRL] = TVP3026_XMISCCTRL_DAC_PUP | TVP3026_XMISCCTRL_DAC_8BIT | TVP3026_XMISCCTRL_PSEL_DIS | TVP3026_XMISCCTRL_PSEL_LOW;
break;
case 16:
hw->DACreg[POS3026_XTRUECOLORCTRL] = (minfo->fbcon.var.green.length == 5) ? (TVP3026_XTRUECOLORCTRL_DIRECTCOLOR | TVP3026_XTRUECOLORCTRL_ORGB_1555) : (TVP3026_XTRUECOLORCTRL_DIRECTCOLOR | TVP3026_XTRUECOLORCTRL_RGB_565);
hw->DACreg[POS3026_XMUXCTRL] = muxctrl | TVP3026_XMUXCTRL_PIXEL_16BIT;
hw->DACreg[POS3026_XCLKCTRL] = TVP3026_XCLKCTRL_SRC_PLL | TVP3026_XCLKCTRL_DIV2;
break;
case 24:
hw->DACreg[POS3026_XTRUECOLORCTRL] = TVP3026_XTRUECOLORCTRL_DIRECTCOLOR | TVP3026_XTRUECOLORCTRL_RGB_888;
hw->DACreg[POS3026_XMUXCTRL] = muxctrl | TVP3026_XMUXCTRL_PIXEL_32BIT;
hw->DACreg[POS3026_XCLKCTRL] = TVP3026_XCLKCTRL_SRC_PLL | TVP3026_XCLKCTRL_DIV4;
break;
case 32:
hw->DACreg[POS3026_XMUXCTRL] = muxctrl | TVP3026_XMUXCTRL_PIXEL_32BIT;
break;
default:
return 1;
}
if (matroxfb_vgaHWinit(minfo, m)) return 1;
hw->MiscOutReg = 0xCB;
if (m->sync & FB_SYNC_HOR_HIGH_ACT)
hw->DACreg[POS3026_XGENCTRL] |= TVP3026_XGENCTRL_HSYNC_NEG;
if (m->sync & FB_SYNC_VERT_HIGH_ACT)
hw->DACreg[POS3026_XGENCTRL] |= TVP3026_XGENCTRL_VSYNC_NEG;
if (m->sync & FB_SYNC_ON_GREEN)
hw->DACreg[POS3026_XGENCTRL] |= TVP3026_XGENCTRL_SYNC_ON_GREEN;
if (minfo->video.len < 0x400000)
hw->CRTCEXT[3] |= 0x08;
else if (minfo->video.len > 0x400000)
hw->CRTCEXT[3] |= 0x10;
if (m->interlaced) {
hw->DACreg[POS3026_XCURCTRL] |= TVP3026_XCURCTRL_INTERLACED;
}
if (m->HTotal >= 1536)
hw->DACreg[POS3026_XCURCTRL] |= TVP3026_XCURCTRL_BLANK4096;
hw->MXoptionReg &= ~0x00001000;
if (isInterleave(minfo)) hw->MXoptionReg |= 0x00001000;
Ti3026_setpclk(minfo, m->pixclock);
return 0;
}
static void ti3026_setMCLK(struct matrox_fb_info *minfo, int fout)
{
unsigned int f_pll;
unsigned int pclk_m, pclk_n, pclk_p;
unsigned int mclk_m, mclk_n, mclk_p;
unsigned int rfhcnt, mclk_ctl;
int tmout;
DBG(__func__)
f_pll = Ti3026_calcclock(minfo, fout, minfo->max_pixel_clock, &mclk_n, &mclk_m, &mclk_p);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFC);
pclk_n = inTi3026(minfo, TVP3026_XPIXPLLDATA);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFD);
pclk_m = inTi3026(minfo, TVP3026_XPIXPLLDATA);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFE);
pclk_p = inTi3026(minfo, TVP3026_XPIXPLLDATA);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFE);
outTi3026(minfo, TVP3026_XPIXPLLDATA, 0x00);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFC);
outTi3026(minfo, TVP3026_XPIXPLLDATA, mclk_n | 0xC0);
outTi3026(minfo, TVP3026_XPIXPLLDATA, mclk_m);
outTi3026(minfo, TVP3026_XPIXPLLDATA, mclk_p | 0xB0);
for (tmout = 500000; tmout; tmout--) {
if (inTi3026(minfo, TVP3026_XPIXPLLDATA) & 0x40)
break;
udelay(10);
}
if (!tmout)
printk(KERN_ERR "matroxfb: Temporary pixel PLL not locked after 5 secs\n");
mclk_ctl = inTi3026(minfo, TVP3026_XMEMPLLCTRL);
outTi3026(minfo, TVP3026_XMEMPLLCTRL, mclk_ctl & 0xE7);
outTi3026(minfo, TVP3026_XMEMPLLCTRL, (mclk_ctl & 0xE7) | TVP3026_XMEMPLLCTRL_STROBEMKC4);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFB);
outTi3026(minfo, TVP3026_XMEMPLLDATA, 0x00);
outTi3026(minfo, TVP3026_XPLLADDR, 0xF3);
outTi3026(minfo, TVP3026_XMEMPLLDATA, mclk_n | 0xC0);
outTi3026(minfo, TVP3026_XMEMPLLDATA, mclk_m);
outTi3026(minfo, TVP3026_XMEMPLLDATA, mclk_p | 0xB0);
for (tmout = 500000; tmout; tmout--) {
if (inTi3026(minfo, TVP3026_XMEMPLLDATA) & 0x40)
break;
udelay(10);
}
if (!tmout)
printk(KERN_ERR "matroxfb: Memory PLL not locked after 5 secs\n");
f_pll = f_pll * 333 / (10000 << mclk_p);
if (isMilleniumII(minfo)) {
rfhcnt = (f_pll - 128) / 256;
if (rfhcnt > 15)
rfhcnt = 15;
} else {
rfhcnt = (f_pll - 64) / 128;
if (rfhcnt > 15)
rfhcnt = 0;
}
minfo->hw.MXoptionReg = (minfo->hw.MXoptionReg & ~0x000F0000) | (rfhcnt << 16);
pci_write_config_dword(minfo->pcidev, PCI_OPTION_REG, minfo->hw.MXoptionReg);
outTi3026(minfo, TVP3026_XMEMPLLCTRL, (mclk_ctl & 0xE7) | TVP3026_XMEMPLLCTRL_MCLK_MCLKPLL);
outTi3026(minfo, TVP3026_XMEMPLLCTRL, (mclk_ctl ) | TVP3026_XMEMPLLCTRL_MCLK_MCLKPLL | TVP3026_XMEMPLLCTRL_STROBEMKC4);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFE);
outTi3026(minfo, TVP3026_XPIXPLLDATA, 0x00);
outTi3026(minfo, TVP3026_XPLLADDR, 0xFC);
outTi3026(minfo, TVP3026_XPIXPLLDATA, pclk_n);
outTi3026(minfo, TVP3026_XPIXPLLDATA, pclk_m);
outTi3026(minfo, TVP3026_XPIXPLLDATA, pclk_p);
for (tmout = 500000; tmout; tmout--) {
if (inTi3026(minfo, TVP3026_XPIXPLLDATA) & 0x40)
break;
udelay(10);
}
if (!tmout)
printk(KERN_ERR "matroxfb: Pixel PLL not locked after 5 secs\n");
}
static void ti3026_ramdac_init(struct matrox_fb_info *minfo)
{
DBG(__func__)
minfo->features.pll.vco_freq_min = 110000;
minfo->features.pll.ref_freq = 114545;
minfo->features.pll.feed_div_min = 2;
minfo->features.pll.feed_div_max = 24;
minfo->features.pll.in_div_min = 2;
minfo->features.pll.in_div_max = 63;
minfo->features.pll.post_shift_max = 3;
if (minfo->devflags.noinit)
return;
ti3026_setMCLK(minfo, 60000);
}
static void Ti3026_restore(struct matrox_fb_info *minfo)
{
int i;
unsigned char progdac[6];
struct matrox_hw_state *hw = &minfo->hw;
CRITFLAGS
DBG(__func__)
#ifdef DEBUG
dprintk(KERN_INFO "EXTVGA regs: ");
for (i = 0; i < 6; i++)
dprintk("%02X:", hw->CRTCEXT[i]);
dprintk("\n");
#endif
CRITBEGIN
pci_write_config_dword(minfo->pcidev, PCI_OPTION_REG, hw->MXoptionReg);
CRITEND
matroxfb_vgaHWrestore(minfo);
CRITBEGIN
minfo->crtc1.panpos = -1;
for (i = 0; i < 6; i++)
mga_setr(M_EXTVGA_INDEX, i, hw->CRTCEXT[i]);
for (i = 0; i < 21; i++) {
outTi3026(minfo, DACseq[i], hw->DACreg[i]);
}
outTi3026(minfo, TVP3026_XPLLADDR, 0x00);
progdac[0] = inTi3026(minfo, TVP3026_XPIXPLLDATA);
progdac[3] = inTi3026(minfo, TVP3026_XLOOPPLLDATA);
outTi3026(minfo, TVP3026_XPLLADDR, 0x15);
progdac[1] = inTi3026(minfo, TVP3026_XPIXPLLDATA);
progdac[4] = inTi3026(minfo, TVP3026_XLOOPPLLDATA);
outTi3026(minfo, TVP3026_XPLLADDR, 0x2A);
progdac[2] = inTi3026(minfo, TVP3026_XPIXPLLDATA);
progdac[5] = inTi3026(minfo, TVP3026_XLOOPPLLDATA);
CRITEND
if (memcmp(hw->DACclk, progdac, 6)) {
CRITBEGIN
outTi3026(minfo, TVP3026_XCLKCTRL, hw->DACreg[POS3026_XCLKCTRL]);
outTi3026(minfo, TVP3026_XPLLADDR, 0x2A);
outTi3026(minfo, TVP3026_XLOOPPLLDATA, 0);
outTi3026(minfo, TVP3026_XPIXPLLDATA, 0);
outTi3026(minfo, TVP3026_XPLLADDR, 0x00);
for (i = 0; i < 3; i++)
outTi3026(minfo, TVP3026_XPIXPLLDATA, hw->DACclk[i]);
if (hw->MiscOutReg & 0x08) {
int tmout;
outTi3026(minfo, TVP3026_XPLLADDR, 0x3F);
for (tmout = 500000; tmout; --tmout) {
if (inTi3026(minfo, TVP3026_XPIXPLLDATA) & 0x40)
break;
udelay(10);
}
CRITEND
if (!tmout)
printk(KERN_ERR "matroxfb: Pixel PLL not locked after 5 secs\n");
else
dprintk(KERN_INFO "PixelPLL: %d\n", 500000-tmout);
CRITBEGIN
}
outTi3026(minfo, TVP3026_XMEMPLLCTRL, hw->DACreg[POS3026_XMEMPLLCTRL]);
outTi3026(minfo, TVP3026_XPLLADDR, 0x00);
for (i = 3; i < 6; i++)
outTi3026(minfo, TVP3026_XLOOPPLLDATA, hw->DACclk[i]);
CRITEND
if ((hw->MiscOutReg & 0x08) && ((hw->DACclk[5] & 0x80) == 0x80)) {
int tmout;
CRITBEGIN
outTi3026(minfo, TVP3026_XPLLADDR, 0x3F);
for (tmout = 500000; tmout; --tmout) {
if (inTi3026(minfo, TVP3026_XLOOPPLLDATA) & 0x40)
break;
udelay(10);
}
CRITEND
if (!tmout)
printk(KERN_ERR "matroxfb: Loop PLL not locked after 5 secs\n");
else
dprintk(KERN_INFO "LoopPLL: %d\n", 500000-tmout);
}
}
#ifdef DEBUG
dprintk(KERN_DEBUG "3026DACregs ");
for (i = 0; i < 21; i++) {
dprintk("R%02X=%02X ", DACseq[i], hw->DACreg[i]);
if ((i & 0x7) == 0x7) dprintk(KERN_DEBUG "continuing... ");
}
dprintk(KERN_DEBUG "DACclk ");
for (i = 0; i < 6; i++)
dprintk("C%02X=%02X ", i, hw->DACclk[i]);
dprintk("\n");
#endif
}
static void Ti3026_reset(struct matrox_fb_info *minfo)
{
DBG(__func__)
ti3026_ramdac_init(minfo);
}
static int Ti3026_preinit(struct matrox_fb_info *minfo)
{
static const int vxres_mill2[] = { 512, 640, 768, 800, 832, 960,
1024, 1152, 1280, 1600, 1664, 1920,
2048, 0};
static const int vxres_mill1[] = { 640, 768, 800, 960,
1024, 1152, 1280, 1600, 1920,
2048, 0};
struct matrox_hw_state *hw = &minfo->hw;
DBG(__func__)
minfo->millenium = 1;
minfo->milleniumII = (minfo->pcidev->device != PCI_DEVICE_ID_MATROX_MIL);
minfo->capable.cfb4 = 1;
minfo->capable.text = 1;
minfo->capable.vxres = isMilleniumII(minfo) ? vxres_mill2 : vxres_mill1;
minfo->outputs[0].data = minfo;
minfo->outputs[0].output = &ti3026_output;
minfo->outputs[0].src = minfo->outputs[0].default_src;
minfo->outputs[0].mode = MATROXFB_OUTPUT_MODE_MONITOR;
if (minfo->devflags.noinit)
return 0;
hw->MXoptionReg &= 0xC0000100;
hw->MXoptionReg |= 0x002C0000;
if (minfo->devflags.novga)
hw->MXoptionReg &= ~0x00000100;
if (minfo->devflags.nobios)
hw->MXoptionReg &= ~0x40000000;
if (minfo->devflags.nopciretry)
hw->MXoptionReg |= 0x20000000;
pci_write_config_dword(minfo->pcidev, PCI_OPTION_REG, hw->MXoptionReg);
minfo->accel.ramdac_rev = inTi3026(minfo, TVP3026_XSILICONREV);
outTi3026(minfo, TVP3026_XCLKCTRL, TVP3026_XCLKCTRL_SRC_CLK0VGA | TVP3026_XCLKCTRL_CLKSTOPPED);
outTi3026(minfo, TVP3026_XTRUECOLORCTRL, TVP3026_XTRUECOLORCTRL_PSEUDOCOLOR);
outTi3026(minfo, TVP3026_XMUXCTRL, TVP3026_XMUXCTRL_VGA);
outTi3026(minfo, TVP3026_XPLLADDR, 0x2A);
outTi3026(minfo, TVP3026_XLOOPPLLDATA, 0x00);
outTi3026(minfo, TVP3026_XPIXPLLDATA, 0x00);
mga_outb(M_MISC_REG, 0x67);
outTi3026(minfo, TVP3026_XMEMPLLCTRL, TVP3026_XMEMPLLCTRL_STROBEMKC4 | TVP3026_XMEMPLLCTRL_MCLK_MCLKPLL);
mga_outl(M_RESET, 1);
udelay(250);
mga_outl(M_RESET, 0);
udelay(250);
mga_outl(M_MACCESS, 0x00008000);
udelay(10);
return 0;
}
