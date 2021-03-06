static int get_ctrl_id(__u32 v4l2_id) {
int i;
for (i = 0; i < G450CTRLS; i++) {
if (v4l2_id < g450_controls[i].desc.id) {
if (g450_controls[i].desc.id == 0x08000000) {
return -EINVAL;
}
return -ENOENT;
}
if (v4l2_id == g450_controls[i].desc.id) {
return i;
}
}
return -EINVAL;
}
static inline int *get_ctrl_ptr(struct matrox_fb_info *minfo, unsigned int idx)
{
return (int*)((char*)minfo + g450_controls[idx].control);
}
static void tvo_fill_defaults(struct matrox_fb_info *minfo)
{
unsigned int i;
for (i = 0; i < G450CTRLS; i++) {
*get_ctrl_ptr(minfo, i) = g450_controls[i].desc.default_value;
}
}
static int cve2_get_reg(struct matrox_fb_info *minfo, int reg)
{
unsigned long flags;
int val;
matroxfb_DAC_lock_irqsave(flags);
matroxfb_DAC_out(minfo, 0x87, reg);
val = matroxfb_DAC_in(minfo, 0x88);
matroxfb_DAC_unlock_irqrestore(flags);
return val;
}
static void cve2_set_reg(struct matrox_fb_info *minfo, int reg, int val)
{
unsigned long flags;
matroxfb_DAC_lock_irqsave(flags);
matroxfb_DAC_out(minfo, 0x87, reg);
matroxfb_DAC_out(minfo, 0x88, val);
matroxfb_DAC_unlock_irqrestore(flags);
}
static void cve2_set_reg10(struct matrox_fb_info *minfo, int reg, int val)
{
unsigned long flags;
matroxfb_DAC_lock_irqsave(flags);
matroxfb_DAC_out(minfo, 0x87, reg);
matroxfb_DAC_out(minfo, 0x88, val >> 2);
matroxfb_DAC_out(minfo, 0x87, reg + 1);
matroxfb_DAC_out(minfo, 0x88, val & 3);
matroxfb_DAC_unlock_irqrestore(flags);
}
static void g450_compute_bwlevel(const struct matrox_fb_info *minfo, int *bl,
int *wl)
{
const int b = minfo->altout.tvo_params.brightness + BLMIN;
const int c = minfo->altout.tvo_params.contrast;
*bl = max(b - c, BLMIN);
*wl = min(b + c, WLMAX);
}
static int g450_query_ctrl(void* md, struct v4l2_queryctrl *p) {
int i;
i = get_ctrl_id(p->id);
if (i >= 0) {
*p = g450_controls[i].desc;
return 0;
}
if (i == -ENOENT) {
static const struct v4l2_queryctrl disctrl =
{ .flags = V4L2_CTRL_FLAG_DISABLED };
i = p->id;
*p = disctrl;
p->id = i;
sprintf(p->name, "Ctrl #%08X", i);
return 0;
}
return -EINVAL;
}
static int g450_set_ctrl(void* md, struct v4l2_control *p) {
int i;
struct matrox_fb_info *minfo = md;
i = get_ctrl_id(p->id);
if (i < 0) return -EINVAL;
if (p->value == *get_ctrl_ptr(minfo, i)) return 0;
if (p->value > g450_controls[i].desc.maximum) return -EINVAL;
if (p->value < g450_controls[i].desc.minimum) return -EINVAL;
*get_ctrl_ptr(minfo, i) = p->value;
switch (p->id) {
case V4L2_CID_BRIGHTNESS:
case V4L2_CID_CONTRAST:
{
int blacklevel, whitelevel;
g450_compute_bwlevel(minfo, &blacklevel, &whitelevel);
cve2_set_reg10(minfo, 0x0e, blacklevel);
cve2_set_reg10(minfo, 0x1e, whitelevel);
}
break;
case V4L2_CID_SATURATION:
cve2_set_reg(minfo, 0x20, p->value);
cve2_set_reg(minfo, 0x22, p->value);
break;
case V4L2_CID_HUE:
cve2_set_reg(minfo, 0x25, p->value);
break;
case MATROXFB_CID_TESTOUT:
{
unsigned char val = cve2_get_reg(minfo, 0x05);
if (p->value) val |= 0x02;
else val &= ~0x02;
cve2_set_reg(minfo, 0x05, val);
}
break;
}
return 0;
}
static int g450_get_ctrl(void* md, struct v4l2_control *p) {
int i;
struct matrox_fb_info *minfo = md;
i = get_ctrl_id(p->id);
if (i < 0) return -EINVAL;
p->value = *get_ctrl_ptr(minfo, i);
return 0;
}
static void computeRegs(struct matrox_fb_info *minfo, struct mavenregs *r,
struct my_timming *mt, const struct output_desc *outd)
{
u_int32_t chromasc;
u_int32_t hlen;
u_int32_t hsl;
u_int32_t hbp;
u_int32_t hfp;
u_int32_t hvis;
unsigned int pixclock;
unsigned long long piic;
int mnp;
int over;
r->regs[0x80] = 0x03;
hvis = ((mt->HDisplay << 1) + 3) & ~3;
if (hvis >= 2048) {
hvis = 2044;
}
piic = 1000000000ULL * hvis;
do_div(piic, outd->h_vis);
dprintk(KERN_DEBUG "Want %u kHz pixclock\n", (unsigned int)piic);
mnp = matroxfb_g450_setclk(minfo, piic, M_VIDEO_PLL);
mt->mnp = mnp;
mt->pixclock = g450_mnp2f(minfo, mnp);
dprintk(KERN_DEBUG "MNP=%08X\n", mnp);
pixclock = 1000000000U / mt->pixclock;
dprintk(KERN_DEBUG "Got %u ps pixclock\n", pixclock);
piic = outd->chromasc;
do_div(piic, mt->pixclock);
chromasc = piic;
dprintk(KERN_DEBUG "Chroma is %08X\n", chromasc);
r->regs[0] = piic >> 24;
r->regs[1] = piic >> 16;
r->regs[2] = piic >> 8;
r->regs[3] = piic >> 0;
hbp = (((outd->h_b_porch + pixclock) / pixclock)) & ~1;
hfp = (((outd->h_f_porch + pixclock) / pixclock)) & ~1;
hsl = (((outd->h_sync + pixclock) / pixclock)) & ~1;
hlen = hvis + hfp + hsl + hbp;
over = hlen & 0x0F;
dprintk(KERN_DEBUG "WL: vis=%u, hf=%u, hs=%u, hb=%u, total=%u\n", hvis, hfp, hsl, hbp, hlen);
if (over) {
hfp -= over;
hlen -= over;
if (over <= 2) {
} else if (over < 10) {
hfp += 4;
hlen += 4;
} else {
hfp += 16;
hlen += 16;
}
}
r->regs[0x08] = hsl;
r->regs[0x09] = (outd->burst + pixclock - 1) / pixclock;
r->regs[0x0A] = hbp;
r->regs[0x2C] = hfp;
r->regs[0x31] = hvis / 8;
r->regs[0x32] = hvis & 7;
dprintk(KERN_DEBUG "PG: vis=%04X, hf=%02X, hs=%02X, hb=%02X, total=%04X\n", hvis, hfp, hsl, hbp, hlen);
r->regs[0x84] = 1;
r->regs[0x85] = 0;
hvis = hvis >> 1;
hlen = hlen >> 1;
dprintk(KERN_DEBUG "hlen=%u hvis=%u\n", hlen, hvis);
mt->interlaced = 1;
mt->HDisplay = hvis & ~7;
mt->HSyncStart = mt->HDisplay + 8;
mt->HSyncEnd = (hlen & ~7) - 8;
mt->HTotal = hlen;
{
int upper;
unsigned int vtotal;
unsigned int vsyncend;
unsigned int vdisplay;
vtotal = mt->VTotal;
vsyncend = mt->VSyncEnd;
vdisplay = mt->VDisplay;
if (vtotal < outd->v_total) {
unsigned int yovr = outd->v_total - vtotal;
vsyncend += yovr >> 1;
} else if (vtotal > outd->v_total) {
vdisplay = outd->v_total - 4;
vsyncend = outd->v_total;
}
upper = (outd->v_total - vsyncend) >> 1;
r->regs[0x17] = outd->v_total / 4;
r->regs[0x18] = outd->v_total & 3;
r->regs[0x33] = upper - 1;
r->regs[0x82] = upper;
r->regs[0x83] = upper >> 8;
mt->VDisplay = vdisplay;
mt->VSyncStart = outd->v_total - 2;
mt->VSyncEnd = outd->v_total;
mt->VTotal = outd->v_total;
}
}
static void cve2_init_TVdata(int norm, struct mavenregs* data, const struct output_desc** outd) {
static const struct output_desc paloutd = {
.h_vis = 52148148,
.h_f_porch = 1407407,
.h_sync = 4666667,
.h_b_porch = 5777778,
.chromasc = 19042247534182ULL,
.burst = 2518518,
.v_total = 625,
};
static const struct output_desc ntscoutd = {
.h_vis = 52888889,
.h_f_porch = 1333333,
.h_sync = 4666667,
.h_b_porch = 4666667,
.chromasc = 15374030659475ULL,
.burst = 2418418,
.v_total = 525,
};
static const struct mavenregs palregs = { {
0x2A, 0x09, 0x8A, 0xCB,
0x00,
0x00,
0xF9,
0x00,
0x7E,
0x44,
0x9C,
0x2E,
0x21,
0x00,
0x3C, 0x03,
0x3C, 0x03,
0x1A,
0x2A,
0x1C, 0x3D, 0x14,
0x9C, 0x01,
0x00,
0xFE,
0x7E,
0x60,
0x05,
0xAD, 0x03,
0xA5,
0x07,
0xA5,
0x00,
0x00,
0x00,
0x08,
0x04,
0x00,
0x1A,
0x55, 0x01,
0x26,
0x07, 0x7E,
0x02, 0x54,
0xB0, 0x00,
0x14,
0x49,
0x00,
0x00,
0xA3,
0xC8,
0x22,
0x02,
0x22,
0x3F, 0x03,
0x00,
0x00,
} };
static struct mavenregs ntscregs = { {
0x21, 0xF0, 0x7C, 0x1F,
0x00,
0x00,
0xF9,
0x00,
0x7E,
0x43,
0x7E,
0x3D,
0x00,
0x00,
0x41, 0x00,
0x3C, 0x00,
0x17,
0x21,
0x1B, 0x1B, 0x24,
0x83, 0x01,
0x00,
0x0F,
0x0F,
0x60,
0x05,
0xC0, 0x02,
0x9C,
0x04,
0x9C,
0x01,
0x02,
0x00,
0x0A,
0x05,
0x00,
0x10,
0xFF, 0x03,
0x24,
0x0F, 0x78,
0x00, 0x00,
0xB2, 0x04,
0x14,
0x02,
0x00,
0x00,
0xA3,
0xC8,
0x15,
0x05,
0x3B,
0x3C, 0x00,
0x00,
0x00,
} };
if (norm == MATROXFB_OUTPUT_MODE_PAL) {
*data = palregs;
*outd = &paloutd;
} else {
*data = ntscregs;
*outd = &ntscoutd;
}
return;
}
static void cve2_init_TV(struct matrox_fb_info *minfo,
const struct mavenregs *m)
{
int i;
LR(0x80);
LR(0x82); LR(0x83);
LR(0x84); LR(0x85);
cve2_set_reg(minfo, 0x3E, 0x01);
for (i = 0; i < 0x3E; i++) {
LR(i);
}
cve2_set_reg(minfo, 0x3E, 0x00);
}
static int matroxfb_g450_compute(void* md, struct my_timming* mt) {
struct matrox_fb_info *minfo = md;
dprintk(KERN_DEBUG "Computing, mode=%u\n", minfo->outputs[1].mode);
if (mt->crtc == MATROXFB_SRC_CRTC2 &&
minfo->outputs[1].mode != MATROXFB_OUTPUT_MODE_MONITOR) {
const struct output_desc* outd;
cve2_init_TVdata(minfo->outputs[1].mode, &minfo->hw.maven, &outd);
{
int blacklevel, whitelevel;
g450_compute_bwlevel(minfo, &blacklevel, &whitelevel);
minfo->hw.maven.regs[0x0E] = blacklevel >> 2;
minfo->hw.maven.regs[0x0F] = blacklevel & 3;
minfo->hw.maven.regs[0x1E] = whitelevel >> 2;
minfo->hw.maven.regs[0x1F] = whitelevel & 3;
minfo->hw.maven.regs[0x20] =
minfo->hw.maven.regs[0x22] = minfo->altout.tvo_params.saturation;
minfo->hw.maven.regs[0x25] = minfo->altout.tvo_params.hue;
if (minfo->altout.tvo_params.testout) {
minfo->hw.maven.regs[0x05] |= 0x02;
}
}
computeRegs(minfo, &minfo->hw.maven, mt, outd);
} else if (mt->mnp < 0) {
mt->mnp = matroxfb_g450_setclk(minfo, mt->pixclock, (mt->crtc == MATROXFB_SRC_CRTC1) ? M_PIXEL_PLL_C : M_VIDEO_PLL);
mt->pixclock = g450_mnp2f(minfo, mt->mnp);
}
dprintk(KERN_DEBUG "Pixclock = %u\n", mt->pixclock);
return 0;
}
static int matroxfb_g450_program(void* md) {
struct matrox_fb_info *minfo = md;
if (minfo->outputs[1].mode != MATROXFB_OUTPUT_MODE_MONITOR) {
cve2_init_TV(minfo, &minfo->hw.maven);
}
return 0;
}
static int matroxfb_g450_verify_mode(void* md, u_int32_t arg) {
switch (arg) {
case MATROXFB_OUTPUT_MODE_PAL:
case MATROXFB_OUTPUT_MODE_NTSC:
case MATROXFB_OUTPUT_MODE_MONITOR:
return 0;
}
return -EINVAL;
}
static int g450_dvi_compute(void* md, struct my_timming* mt) {
struct matrox_fb_info *minfo = md;
if (mt->mnp < 0) {
mt->mnp = matroxfb_g450_setclk(minfo, mt->pixclock, (mt->crtc == MATROXFB_SRC_CRTC1) ? M_PIXEL_PLL_C : M_VIDEO_PLL);
mt->pixclock = g450_mnp2f(minfo, mt->mnp);
}
return 0;
}
void matroxfb_g450_connect(struct matrox_fb_info *minfo)
{
if (minfo->devflags.g450dac) {
down_write(&minfo->altout.lock);
tvo_fill_defaults(minfo);
minfo->outputs[1].src = minfo->outputs[1].default_src;
minfo->outputs[1].data = minfo;
minfo->outputs[1].output = &matroxfb_g450_altout;
minfo->outputs[1].mode = MATROXFB_OUTPUT_MODE_MONITOR;
minfo->outputs[2].src = minfo->outputs[2].default_src;
minfo->outputs[2].data = minfo;
minfo->outputs[2].output = &matroxfb_g450_dvi;
minfo->outputs[2].mode = MATROXFB_OUTPUT_MODE_MONITOR;
up_write(&minfo->altout.lock);
}
}
void matroxfb_g450_shutdown(struct matrox_fb_info *minfo)
{
if (minfo->devflags.g450dac) {
down_write(&minfo->altout.lock);
minfo->outputs[1].src = MATROXFB_SRC_NONE;
minfo->outputs[1].output = NULL;
minfo->outputs[1].data = NULL;
minfo->outputs[1].mode = MATROXFB_OUTPUT_MODE_MONITOR;
minfo->outputs[2].src = MATROXFB_SRC_NONE;
minfo->outputs[2].output = NULL;
minfo->outputs[2].data = NULL;
minfo->outputs[2].mode = MATROXFB_OUTPUT_MODE_MONITOR;
up_write(&minfo->altout.lock);
}
}
