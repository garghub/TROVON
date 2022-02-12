static ssize_t show_card(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vfd = to_video_device(cd);
struct bttv *btv = video_get_drvdata(vfd);
return sprintf(buf, "%d\n", btv ? btv->c.type : UNSET);
}
static void request_module_async(struct work_struct *work)
{
request_module("dvb-bt8xx");
}
static void request_modules(struct bttv *dev)
{
INIT_WORK(&dev->request_module_wk, request_module_async);
schedule_work(&dev->request_module_wk);
}
static void flush_request_modules(struct bttv *dev)
{
flush_work(&dev->request_module_wk);
}
static
int check_alloc_btres_lock(struct bttv *btv, struct bttv_fh *fh, int bit)
{
int xbits;
if (fh->resources & bit)
return 1;
xbits = bit;
if (bit & (RESOURCE_VIDEO_READ | RESOURCE_VIDEO_STREAM))
xbits |= RESOURCE_VIDEO_READ | RESOURCE_VIDEO_STREAM;
if (btv->resources & xbits) {
goto fail;
}
if ((bit & VIDEO_RESOURCES)
&& 0 == (btv->resources & VIDEO_RESOURCES)) {
__s32 top = btv->crop[!!fh->do_crop].rect.top;
if (btv->vbi_end > top)
goto fail;
btv->crop_start = top;
} else if (bit & VBI_RESOURCES) {
__s32 end = fh->vbi_fmt.end;
if (end > btv->crop_start)
goto fail;
btv->vbi_end = end;
}
fh->resources |= bit;
btv->resources |= bit;
return 1;
fail:
return 0;
}
static
int check_btres(struct bttv_fh *fh, int bit)
{
return (fh->resources & bit);
}
static
int locked_btres(struct bttv *btv, int bit)
{
return (btv->resources & bit);
}
static void
disclaim_vbi_lines(struct bttv *btv)
{
btv->vbi_end = 0;
}
static void
disclaim_video_lines(struct bttv *btv)
{
const struct bttv_tvnorm *tvnorm;
u8 crop;
tvnorm = &bttv_tvnorms[btv->tvnorm];
btv->crop_start = tvnorm->cropcap.bounds.top
+ tvnorm->cropcap.bounds.height;
crop = btread(BT848_E_CROP) | 0xc0;
btwrite(crop, BT848_E_CROP);
btwrite(0xfe, BT848_E_VDELAY_LO);
btwrite(crop, BT848_O_CROP);
btwrite(0xfe, BT848_O_VDELAY_LO);
}
static
void free_btres_lock(struct bttv *btv, struct bttv_fh *fh, int bits)
{
if ((fh->resources & bits) != bits) {
pr_err("BUG! (btres)\n");
}
fh->resources &= ~bits;
btv->resources &= ~bits;
bits = btv->resources;
if (0 == (bits & VIDEO_RESOURCES))
disclaim_video_lines(btv);
if (0 == (bits & VBI_RESOURCES))
disclaim_vbi_lines(btv);
}
static void set_pll_freq(struct bttv *btv, unsigned int fin, unsigned int fout)
{
unsigned char fl, fh, fi;
fin/=4;
fout/=4;
fout*=12;
fi=fout/fin;
fout=(fout%fin)*256;
fh=fout/fin;
fout=(fout%fin)*256;
fl=fout/fin;
btwrite(fl, BT848_PLL_F_LO);
btwrite(fh, BT848_PLL_F_HI);
btwrite(fi|BT848_PLL_X, BT848_PLL_XCI);
}
static void set_pll(struct bttv *btv)
{
int i;
if (!btv->pll.pll_crystal)
return;
if (btv->pll.pll_ofreq == btv->pll.pll_current) {
dprintk("%d: PLL: no change required\n", btv->c.nr);
return;
}
if (btv->pll.pll_ifreq == btv->pll.pll_ofreq) {
if (btv->pll.pll_current == 0)
return;
if (bttv_verbose)
pr_info("%d: PLL can sleep, using XTAL (%d)\n",
btv->c.nr, btv->pll.pll_ifreq);
btwrite(0x00,BT848_TGCTRL);
btwrite(0x00,BT848_PLL_XCI);
btv->pll.pll_current = 0;
return;
}
if (bttv_verbose)
pr_info("%d: Setting PLL: %d => %d (needs up to 100ms)\n",
btv->c.nr,
btv->pll.pll_ifreq, btv->pll.pll_ofreq);
set_pll_freq(btv, btv->pll.pll_ifreq, btv->pll.pll_ofreq);
for (i=0; i<10; i++) {
msleep(10);
if (btread(BT848_DSTATUS) & BT848_DSTATUS_PLOCK) {
btwrite(0,BT848_DSTATUS);
} else {
btwrite(0x08,BT848_TGCTRL);
btv->pll.pll_current = btv->pll.pll_ofreq;
if (bttv_verbose)
pr_info("PLL set ok\n");
return;
}
}
btv->pll.pll_current = -1;
if (bttv_verbose)
pr_info("Setting PLL failed\n");
return;
}
static void bt848A_set_timing(struct bttv *btv)
{
int i, len;
int table_idx = bttv_tvnorms[btv->tvnorm].sram;
int fsc = bttv_tvnorms[btv->tvnorm].Fsc;
if (btv->input == btv->dig) {
dprintk("%d: load digital timing table (table_idx=%d)\n",
btv->c.nr,table_idx);
btwrite(0x00, BT848_TGCTRL);
btwrite(0x02, BT848_TGCTRL);
btwrite(0x00, BT848_TGCTRL);
len=SRAM_Table[table_idx][0];
for(i = 1; i <= len; i++)
btwrite(SRAM_Table[table_idx][i],BT848_TGLB);
btv->pll.pll_ofreq = 27000000;
set_pll(btv);
btwrite(0x11, BT848_TGCTRL);
btwrite(0x41, BT848_DVSIF);
} else {
btv->pll.pll_ofreq = fsc;
set_pll(btv);
btwrite(0x0, BT848_DVSIF);
}
}
static void bt848_bright(struct bttv *btv, int bright)
{
int value;
btv->bright = bright;
value = (bright >> 8) - 128;
btwrite(value & 0xff, BT848_BRIGHT);
}
static void bt848_hue(struct bttv *btv, int hue)
{
int value;
btv->hue = hue;
value = (hue >> 8) - 128;
btwrite(value & 0xff, BT848_HUE);
}
static void bt848_contrast(struct bttv *btv, int cont)
{
int value,hibit;
btv->contrast = cont;
value = (cont >> 7);
hibit = (value >> 6) & 4;
btwrite(value & 0xff, BT848_CONTRAST_LO);
btaor(hibit, ~4, BT848_E_CONTROL);
btaor(hibit, ~4, BT848_O_CONTROL);
}
static void bt848_sat(struct bttv *btv, int color)
{
int val_u,val_v,hibits;
btv->saturation = color;
val_u = ((color * btv->opt_uv_ratio) / 50) >> 7;
val_v = (((color * (100 - btv->opt_uv_ratio) / 50) >>7)*180L)/254;
hibits = (val_u >> 7) & 2;
hibits |= (val_v >> 8) & 1;
btwrite(val_u & 0xff, BT848_SAT_U_LO);
btwrite(val_v & 0xff, BT848_SAT_V_LO);
btaor(hibits, ~3, BT848_E_CONTROL);
btaor(hibits, ~3, BT848_O_CONTROL);
}
static int
video_mux(struct bttv *btv, unsigned int input)
{
int mux,mask2;
if (input >= bttv_tvcards[btv->c.type].video_inputs)
return -EINVAL;
mask2 = bttv_tvcards[btv->c.type].gpiomask2;
if (mask2)
gpio_inout(mask2,mask2);
if (input == btv->svhs) {
btor(BT848_CONTROL_COMP, BT848_E_CONTROL);
btor(BT848_CONTROL_COMP, BT848_O_CONTROL);
} else {
btand(~BT848_CONTROL_COMP, BT848_E_CONTROL);
btand(~BT848_CONTROL_COMP, BT848_O_CONTROL);
}
mux = bttv_muxsel(btv, input);
btaor(mux<<5, ~(3<<5), BT848_IFORM);
dprintk("%d: video mux: input=%d mux=%d\n", btv->c.nr, input, mux);
if(bttv_tvcards[btv->c.type].muxsel_hook)
bttv_tvcards[btv->c.type].muxsel_hook (btv, input);
return 0;
}
static void
audio_mux_gpio(struct bttv *btv, int input, int mute)
{
int gpio_val, signal, mute_gpio;
gpio_inout(bttv_tvcards[btv->c.type].gpiomask,
bttv_tvcards[btv->c.type].gpiomask);
signal = btread(BT848_DSTATUS) & BT848_DSTATUS_HLOC;
mute_gpio = mute || (btv->opt_automute && (!signal || !btv->users)
&& !btv->has_radio_tuner);
if (mute_gpio)
gpio_val = bttv_tvcards[btv->c.type].gpiomute;
else
gpio_val = bttv_tvcards[btv->c.type].gpiomux[input];
switch (btv->c.type) {
case BTTV_BOARD_VOODOOTV_FM:
case BTTV_BOARD_VOODOOTV_200:
gpio_val = bttv_tda9880_setnorm(btv, gpio_val);
break;
default:
gpio_bits(bttv_tvcards[btv->c.type].gpiomask, gpio_val);
}
if (bttv_gpio)
bttv_gpio_tracking(btv, audio_modes[mute_gpio ? 4 : input]);
}
static int
audio_mute(struct bttv *btv, int mute)
{
struct v4l2_ctrl *ctrl;
audio_mux_gpio(btv, btv->audio_input, mute);
if (btv->sd_msp34xx) {
ctrl = v4l2_ctrl_find(btv->sd_msp34xx->ctrl_handler, V4L2_CID_AUDIO_MUTE);
if (ctrl)
v4l2_ctrl_s_ctrl(ctrl, mute);
}
if (btv->sd_tvaudio) {
ctrl = v4l2_ctrl_find(btv->sd_tvaudio->ctrl_handler, V4L2_CID_AUDIO_MUTE);
if (ctrl)
v4l2_ctrl_s_ctrl(ctrl, mute);
}
if (btv->sd_tda7432) {
ctrl = v4l2_ctrl_find(btv->sd_tda7432->ctrl_handler, V4L2_CID_AUDIO_MUTE);
if (ctrl)
v4l2_ctrl_s_ctrl(ctrl, mute);
}
return 0;
}
static int
audio_input(struct bttv *btv, int input)
{
audio_mux_gpio(btv, input, btv->mute);
if (btv->sd_msp34xx) {
u32 in;
switch (input) {
case TVAUDIO_INPUT_RADIO:
if (btv->radio_uses_msp_demodulator) {
in = MSP_INPUT_DEFAULT;
break;
}
in = MSP_INPUT(MSP_IN_SCART2, MSP_IN_TUNER1,
MSP_DSP_IN_SCART, MSP_DSP_IN_SCART);
break;
case TVAUDIO_INPUT_EXTERN:
in = MSP_INPUT(MSP_IN_SCART1, MSP_IN_TUNER1,
MSP_DSP_IN_SCART, MSP_DSP_IN_SCART);
break;
case TVAUDIO_INPUT_INTERN:
in = MSP_INPUT(MSP_IN_SCART2, MSP_IN_TUNER1,
MSP_DSP_IN_SCART, MSP_DSP_IN_SCART);
break;
case TVAUDIO_INPUT_TUNER:
default:
if (btv->c.type == BTTV_BOARD_VOODOOTV_200)
in = MSP_INPUT(MSP_IN_SCART1, MSP_IN_TUNER2, \
MSP_DSP_IN_TUNER, MSP_DSP_IN_TUNER);
else
in = MSP_INPUT_DEFAULT;
break;
}
v4l2_subdev_call(btv->sd_msp34xx, audio, s_routing,
in, MSP_OUTPUT_DEFAULT, 0);
}
if (btv->sd_tvaudio) {
v4l2_subdev_call(btv->sd_tvaudio, audio, s_routing,
input, 0, 0);
}
return 0;
}
static void
bttv_crop_calc_limits(struct bttv_crop *c)
{
if (1) {
c->min_scaled_width = 48;
c->min_scaled_height = 32;
} else {
c->min_scaled_width =
(max_t(unsigned int, 48, c->rect.width >> 4) + 3) & ~3;
c->min_scaled_height =
max_t(unsigned int, 32, c->rect.height >> 4);
}
c->max_scaled_width = c->rect.width & ~3;
c->max_scaled_height = c->rect.height;
}
static void
bttv_crop_reset(struct bttv_crop *c, unsigned int norm)
{
c->rect = bttv_tvnorms[norm].cropcap.defrect;
bttv_crop_calc_limits(c);
}
static int
set_tvnorm(struct bttv *btv, unsigned int norm)
{
const struct bttv_tvnorm *tvnorm;
v4l2_std_id id;
BUG_ON(norm >= BTTV_TVNORMS);
BUG_ON(btv->tvnorm >= BTTV_TVNORMS);
tvnorm = &bttv_tvnorms[norm];
if (memcmp(&bttv_tvnorms[btv->tvnorm].cropcap, &tvnorm->cropcap,
sizeof (tvnorm->cropcap))) {
bttv_crop_reset(&btv->crop[0], norm);
btv->crop[1] = btv->crop[0];
if (0 == (btv->resources & VIDEO_RESOURCES)) {
btv->crop_start = tvnorm->cropcap.bounds.top
+ tvnorm->cropcap.bounds.height;
}
}
btv->tvnorm = norm;
btwrite(tvnorm->adelay, BT848_ADELAY);
btwrite(tvnorm->bdelay, BT848_BDELAY);
btaor(tvnorm->iform,~(BT848_IFORM_NORM|BT848_IFORM_XTBOTH),
BT848_IFORM);
btwrite(tvnorm->vbipack, BT848_VBI_PACK_SIZE);
btwrite(1, BT848_VBI_PACK_DEL);
bt848A_set_timing(btv);
switch (btv->c.type) {
case BTTV_BOARD_VOODOOTV_FM:
case BTTV_BOARD_VOODOOTV_200:
bttv_tda9880_setnorm(btv, gpio_read());
break;
}
id = tvnorm->v4l2_id;
bttv_call_all(btv, video, s_std, id);
return 0;
}
static void
set_input(struct bttv *btv, unsigned int input, unsigned int norm)
{
unsigned long flags;
btv->input = input;
if (irq_iswitch) {
spin_lock_irqsave(&btv->s_lock,flags);
if (btv->curr.frame_irq) {
btv->new_input = input;
} else {
video_mux(btv,input);
}
spin_unlock_irqrestore(&btv->s_lock,flags);
} else {
video_mux(btv,input);
}
btv->audio_input = (btv->tuner_type != TUNER_ABSENT && input == 0) ?
TVAUDIO_INPUT_TUNER : TVAUDIO_INPUT_EXTERN;
audio_input(btv, btv->audio_input);
set_tvnorm(btv, norm);
}
static void init_irqreg(struct bttv *btv)
{
btwrite(0xfffffUL, BT848_INT_STAT);
if (bttv_tvcards[btv->c.type].no_video) {
btwrite(BT848_INT_I2CDONE,
BT848_INT_MASK);
} else {
btwrite((btv->triton1) |
(btv->gpioirq ? BT848_INT_GPINT : 0) |
BT848_INT_SCERR |
(fdsr ? BT848_INT_FDSR : 0) |
BT848_INT_RISCI | BT848_INT_OCERR |
BT848_INT_FMTCHG|BT848_INT_HLOCK|
BT848_INT_I2CDONE,
BT848_INT_MASK);
}
}
static void init_bt848(struct bttv *btv)
{
if (bttv_tvcards[btv->c.type].no_video) {
init_irqreg(btv);
return;
}
btwrite(0x00, BT848_CAP_CTL);
btwrite(BT848_COLOR_CTL_GAMMA, BT848_COLOR_CTL);
btwrite(BT848_IFORM_XTAUTO | BT848_IFORM_AUTO, BT848_IFORM);
btwrite(BT848_GPIO_DMA_CTL_PKTP_32|
BT848_GPIO_DMA_CTL_PLTP1_16|
BT848_GPIO_DMA_CTL_PLTP23_16|
BT848_GPIO_DMA_CTL_GPINTC|
BT848_GPIO_DMA_CTL_GPINTI,
BT848_GPIO_DMA_CTL);
btwrite(0x20, BT848_E_VSCALE_HI);
btwrite(0x20, BT848_O_VSCALE_HI);
v4l2_ctrl_handler_setup(&btv->ctrl_handler);
init_irqreg(btv);
}
static void bttv_reinit_bt848(struct bttv *btv)
{
unsigned long flags;
if (bttv_verbose)
pr_info("%d: reset, reinitialize\n", btv->c.nr);
spin_lock_irqsave(&btv->s_lock,flags);
btv->errors=0;
bttv_set_dma(btv,0);
spin_unlock_irqrestore(&btv->s_lock,flags);
init_bt848(btv);
btv->pll.pll_current = -1;
set_input(btv, btv->input, btv->tvnorm);
}
static int bttv_s_ctrl(struct v4l2_ctrl *c)
{
struct bttv *btv = container_of(c->handler, struct bttv, ctrl_handler);
int val;
switch (c->id) {
case V4L2_CID_BRIGHTNESS:
bt848_bright(btv, c->val);
break;
case V4L2_CID_HUE:
bt848_hue(btv, c->val);
break;
case V4L2_CID_CONTRAST:
bt848_contrast(btv, c->val);
break;
case V4L2_CID_SATURATION:
bt848_sat(btv, c->val);
break;
case V4L2_CID_COLOR_KILLER:
if (c->val) {
btor(BT848_SCLOOP_CKILL, BT848_E_SCLOOP);
btor(BT848_SCLOOP_CKILL, BT848_O_SCLOOP);
} else {
btand(~BT848_SCLOOP_CKILL, BT848_E_SCLOOP);
btand(~BT848_SCLOOP_CKILL, BT848_O_SCLOOP);
}
break;
case V4L2_CID_AUDIO_MUTE:
audio_mute(btv, c->val);
btv->mute = c->val;
break;
case V4L2_CID_AUDIO_VOLUME:
btv->volume_gpio(btv, c->val);
break;
case V4L2_CID_CHROMA_AGC:
val = c->val ? BT848_SCLOOP_CAGC : 0;
btwrite(val, BT848_E_SCLOOP);
btwrite(val, BT848_O_SCLOOP);
break;
case V4L2_CID_PRIVATE_COMBFILTER:
btv->opt_combfilter = c->val;
break;
case V4L2_CID_PRIVATE_LUMAFILTER:
if (c->val) {
btand(~BT848_CONTROL_LDEC, BT848_E_CONTROL);
btand(~BT848_CONTROL_LDEC, BT848_O_CONTROL);
} else {
btor(BT848_CONTROL_LDEC, BT848_E_CONTROL);
btor(BT848_CONTROL_LDEC, BT848_O_CONTROL);
}
break;
case V4L2_CID_PRIVATE_AUTOMUTE:
btv->opt_automute = c->val;
break;
case V4L2_CID_PRIVATE_AGC_CRUSH:
btwrite(BT848_ADC_RESERVED |
(c->val ? BT848_ADC_CRUSH : 0),
BT848_ADC);
break;
case V4L2_CID_PRIVATE_VCR_HACK:
btv->opt_vcr_hack = c->val;
break;
case V4L2_CID_PRIVATE_WHITECRUSH_UPPER:
btwrite(c->val, BT848_WC_UP);
break;
case V4L2_CID_PRIVATE_WHITECRUSH_LOWER:
btwrite(c->val, BT848_WC_DOWN);
break;
case V4L2_CID_PRIVATE_UV_RATIO:
btv->opt_uv_ratio = c->val;
bt848_sat(btv, btv->saturation);
break;
case V4L2_CID_PRIVATE_FULL_LUMA_RANGE:
btaor((c->val << 7), ~BT848_OFORM_RANGE, BT848_OFORM);
break;
case V4L2_CID_PRIVATE_CORING:
btaor((c->val << 5), ~BT848_OFORM_CORE32, BT848_OFORM);
break;
default:
return -EINVAL;
}
return 0;
}
void bttv_gpio_tracking(struct bttv *btv, char *comment)
{
unsigned int outbits, data;
outbits = btread(BT848_GPIO_OUT_EN);
data = btread(BT848_GPIO_DATA);
pr_debug("%d: gpio: en=%08x, out=%08x in=%08x [%s]\n",
btv->c.nr, outbits, data & outbits, data & ~outbits, comment);
}
static void bttv_field_count(struct bttv *btv)
{
int need_count = 0;
if (btv->users)
need_count++;
if (need_count) {
btor(BT848_INT_VSYNC,BT848_INT_MASK);
} else {
btand(~BT848_INT_VSYNC,BT848_INT_MASK);
btv->field_count = 0;
}
}
static const struct bttv_format*
format_by_fourcc(int fourcc)
{
unsigned int i;
for (i = 0; i < FORMATS; i++) {
if (-1 == formats[i].fourcc)
continue;
if (formats[i].fourcc == fourcc)
return formats+i;
}
return NULL;
}
static int
bttv_switch_overlay(struct bttv *btv, struct bttv_fh *fh,
struct bttv_buffer *new)
{
struct bttv_buffer *old;
unsigned long flags;
dprintk("switch_overlay: enter [new=%p]\n", new);
if (new)
new->vb.state = VIDEOBUF_DONE;
spin_lock_irqsave(&btv->s_lock,flags);
old = btv->screen;
btv->screen = new;
btv->loop_irq |= 1;
bttv_set_dma(btv, 0x03);
spin_unlock_irqrestore(&btv->s_lock,flags);
if (NULL != old) {
dprintk("switch_overlay: old=%p state is %d\n",
old, old->vb.state);
bttv_dma_free(&fh->cap,btv, old);
kfree(old);
}
if (NULL == new)
free_btres_lock(btv,fh,RESOURCE_OVERLAY);
dprintk("switch_overlay: done\n");
return 0;
}
static int bttv_prepare_buffer(struct videobuf_queue *q,struct bttv *btv,
struct bttv_buffer *buf,
const struct bttv_format *fmt,
unsigned int width, unsigned int height,
enum v4l2_field field)
{
struct bttv_fh *fh = q->priv_data;
int redo_dma_risc = 0;
struct bttv_crop c;
int norm;
int rc;
if (NULL == fmt)
return -EINVAL;
if (fmt->btformat == BT848_COLOR_FMT_RAW) {
width = RAW_BPL;
height = RAW_LINES*2;
if (width*height > buf->vb.bsize)
return -EINVAL;
buf->vb.size = buf->vb.bsize;
norm = btv->tvnorm;
if (btv->vbi_end > bttv_tvnorms[norm].cropcap.defrect.top) {
return -EINVAL;
}
c.rect = bttv_tvnorms[norm].cropcap.defrect;
} else {
norm = btv->tvnorm;
c = btv->crop[!!fh->do_crop];
if (width < c.min_scaled_width ||
width > c.max_scaled_width ||
height < c.min_scaled_height)
return -EINVAL;
switch (field) {
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
case V4L2_FIELD_ALTERNATE:
if (height * 2 > c.max_scaled_height)
return -EINVAL;
break;
default:
if (height > c.max_scaled_height)
return -EINVAL;
break;
}
buf->vb.size = (width * height * fmt->depth) >> 3;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
}
if (buf->vb.width != width || buf->vb.height != height ||
buf->vb.field != field ||
buf->tvnorm != norm || buf->fmt != fmt ||
buf->crop.top != c.rect.top ||
buf->crop.left != c.rect.left ||
buf->crop.width != c.rect.width ||
buf->crop.height != c.rect.height) {
buf->vb.width = width;
buf->vb.height = height;
buf->vb.field = field;
buf->tvnorm = norm;
buf->fmt = fmt;
buf->crop = c.rect;
redo_dma_risc = 1;
}
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
redo_dma_risc = 1;
if (0 != (rc = videobuf_iolock(q,&buf->vb,&btv->fbuf)))
goto fail;
}
if (redo_dma_risc)
if (0 != (rc = bttv_buffer_risc(btv,buf)))
goto fail;
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
bttv_dma_free(q,btv,buf);
return rc;
}
static int
buffer_setup(struct videobuf_queue *q, unsigned int *count, unsigned int *size)
{
struct bttv_fh *fh = q->priv_data;
*size = fh->fmt->depth*fh->width*fh->height >> 3;
if (0 == *count)
*count = gbuffers;
if (*size * *count > gbuffers * gbufsize)
*count = (gbuffers * gbufsize) / *size;
return 0;
}
static int
buffer_prepare(struct videobuf_queue *q, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct bttv_buffer *buf = container_of(vb,struct bttv_buffer,vb);
struct bttv_fh *fh = q->priv_data;
return bttv_prepare_buffer(q,fh->btv, buf, fh->fmt,
fh->width, fh->height, field);
}
static void
buffer_queue(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct bttv_buffer *buf = container_of(vb,struct bttv_buffer,vb);
struct bttv_fh *fh = q->priv_data;
struct bttv *btv = fh->btv;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue,&btv->capture);
if (!btv->curr.frame_irq) {
btv->loop_irq |= 1;
bttv_set_dma(btv, 0x03);
}
}
static void buffer_release(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct bttv_buffer *buf = container_of(vb,struct bttv_buffer,vb);
struct bttv_fh *fh = q->priv_data;
bttv_dma_free(q,fh->btv,buf);
}
static void radio_enable(struct bttv *btv)
{
if (!btv->has_radio_tuner) {
btv->has_radio_tuner = 1;
bttv_call_all(btv, tuner, s_radio);
btv->audio_input = TVAUDIO_INPUT_RADIO;
audio_input(btv, btv->audio_input);
}
}
static int bttv_s_std(struct file *file, void *priv, v4l2_std_id id)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
unsigned int i;
for (i = 0; i < BTTV_TVNORMS; i++)
if (id & bttv_tvnorms[i].v4l2_id)
break;
if (i == BTTV_TVNORMS)
return -EINVAL;
btv->std = id;
set_tvnorm(btv, i);
return 0;
}
static int bttv_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
*id = btv->std;
return 0;
}
static int bttv_querystd(struct file *file, void *f, v4l2_std_id *id)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
if (btread(BT848_DSTATUS) & BT848_DSTATUS_NUML)
*id &= V4L2_STD_625_50;
else
*id &= V4L2_STD_525_60;
return 0;
}
static int bttv_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (i->index >= bttv_tvcards[btv->c.type].video_inputs)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
i->audioset = 0;
if (btv->tuner_type != TUNER_ABSENT && i->index == 0) {
sprintf(i->name, "Television");
i->type = V4L2_INPUT_TYPE_TUNER;
i->tuner = 0;
} else if (i->index == btv->svhs) {
sprintf(i->name, "S-Video");
} else {
sprintf(i->name, "Composite%d", i->index);
}
if (i->index == btv->input) {
__u32 dstatus = btread(BT848_DSTATUS);
if (0 == (dstatus & BT848_DSTATUS_PRES))
i->status |= V4L2_IN_ST_NO_SIGNAL;
if (0 == (dstatus & BT848_DSTATUS_HLOC))
i->status |= V4L2_IN_ST_NO_H_LOCK;
}
i->std = BTTV_NORMS;
return 0;
}
static int bttv_g_input(struct file *file, void *priv, unsigned int *i)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
*i = btv->input;
return 0;
}
static int bttv_s_input(struct file *file, void *priv, unsigned int i)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (i >= bttv_tvcards[btv->c.type].video_inputs)
return -EINVAL;
set_input(btv, i, btv->tvnorm);
return 0;
}
static int bttv_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (t->index)
return -EINVAL;
bttv_call_all(btv, tuner, s_tuner, t);
if (btv->audio_mode_gpio) {
struct v4l2_tuner copy = *t;
btv->audio_mode_gpio(btv, &copy, 1);
}
return 0;
}
static int bttv_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (f->tuner)
return -EINVAL;
if (f->type == V4L2_TUNER_RADIO)
radio_enable(btv);
f->frequency = f->type == V4L2_TUNER_RADIO ?
btv->radio_freq : btv->tv_freq;
return 0;
}
static void bttv_set_frequency(struct bttv *btv, const struct v4l2_frequency *f)
{
struct v4l2_frequency new_freq = *f;
bttv_call_all(btv, tuner, s_frequency, f);
bttv_call_all(btv, tuner, g_frequency, &new_freq);
if (new_freq.type == V4L2_TUNER_RADIO) {
radio_enable(btv);
btv->radio_freq = new_freq.frequency;
if (btv->has_tea575x) {
btv->tea.freq = btv->radio_freq;
snd_tea575x_set_freq(&btv->tea);
}
} else {
btv->tv_freq = new_freq.frequency;
}
}
static int bttv_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (f->tuner)
return -EINVAL;
bttv_set_frequency(btv, f);
return 0;
}
static int bttv_log_status(struct file *file, void *f)
{
struct video_device *vdev = video_devdata(file);
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
v4l2_ctrl_handler_log_status(vdev->ctrl_handler, btv->c.v4l2_dev.name);
bttv_call_all(btv, core, log_status);
return 0;
}
static int bttv_g_register(struct file *file, void *f,
struct v4l2_dbg_register *reg)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
reg->reg &= 0xfff;
reg->val = btread(reg->reg);
reg->size = 1;
return 0;
}
static int bttv_s_register(struct file *file, void *f,
const struct v4l2_dbg_register *reg)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
btwrite(reg->val, reg->reg & 0xfff);
return 0;
}
static void
bttv_crop_adjust (struct bttv_crop * c,
const struct v4l2_rect * b,
__s32 width,
__s32 height,
enum v4l2_field field)
{
__s32 frame_height = height << !V4L2_FIELD_HAS_BOTH(field);
__s32 max_left;
__s32 max_top;
if (width < c->min_scaled_width) {
c->rect.width = width * 16;
} else if (width > c->max_scaled_width) {
c->rect.width = width;
max_left = b->left + b->width - width;
max_left = min(max_left, (__s32) MAX_HDELAY);
if (c->rect.left > max_left)
c->rect.left = max_left;
}
if (height < c->min_scaled_height) {
c->rect.height = height * 16;
} else if (frame_height > c->max_scaled_height) {
c->rect.height = (frame_height + 1) & ~1;
max_top = b->top + b->height - c->rect.height;
if (c->rect.top > max_top)
c->rect.top = max_top;
}
bttv_crop_calc_limits(c);
}
static int
limit_scaled_size_lock (struct bttv_fh * fh,
__s32 * width,
__s32 * height,
enum v4l2_field field,
unsigned int width_mask,
unsigned int width_bias,
int adjust_size,
int adjust_crop)
{
struct bttv *btv = fh->btv;
const struct v4l2_rect *b;
struct bttv_crop *c;
__s32 min_width;
__s32 min_height;
__s32 max_width;
__s32 max_height;
int rc;
BUG_ON((int) width_mask >= 0 ||
width_bias >= (unsigned int) -width_mask);
b = &bttv_tvnorms[btv->tvnorm].cropcap.bounds;
c = &btv->crop[!!fh->do_crop];
if (fh->do_crop
&& adjust_size
&& adjust_crop
&& !locked_btres(btv, VIDEO_RESOURCES)) {
min_width = 48;
min_height = 32;
max_width = min_t(unsigned int, b->width, MAX_HACTIVE);
max_height = b->height;
if (btv->vbi_end > b->top) {
max_height -= btv->vbi_end - b->top;
rc = -EBUSY;
if (min_height > max_height)
goto fail;
}
} else {
rc = -EBUSY;
if (btv->vbi_end > c->rect.top)
goto fail;
min_width = c->min_scaled_width;
min_height = c->min_scaled_height;
max_width = c->max_scaled_width;
max_height = c->max_scaled_height;
adjust_crop = 0;
}
min_width = (min_width - width_mask - 1) & width_mask;
max_width = max_width & width_mask;
min_height = min_height;
max_height >>= !V4L2_FIELD_HAS_BOTH(field);
if (adjust_size) {
*width = clamp(*width, min_width, max_width);
*height = clamp(*height, min_height, max_height);
*width = (*width + width_bias) & width_mask;
if (adjust_crop) {
bttv_crop_adjust(c, b, *width, *height, field);
if (btv->vbi_end > c->rect.top) {
c->rect.top = btv->vbi_end;
}
}
} else {
rc = -EINVAL;
if (*width < min_width ||
*height < min_height ||
*width > max_width ||
*height > max_height ||
0 != (*width & ~width_mask))
goto fail;
}
rc = 0;
fail:
return rc;
}
static int
verify_window_lock(struct bttv_fh *fh, struct v4l2_window *win,
int adjust_size, int adjust_crop)
{
enum v4l2_field field;
unsigned int width_mask;
int rc;
if (win->w.width < 48)
win->w.width = 48;
if (win->w.height < 32)
win->w.height = 32;
if (win->clipcount > 2048)
win->clipcount = 2048;
win->chromakey = 0;
win->global_alpha = 0;
field = win->field;
switch (field) {
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
case V4L2_FIELD_INTERLACED:
break;
default:
field = V4L2_FIELD_ANY;
break;
}
if (V4L2_FIELD_ANY == field) {
__s32 height2;
height2 = fh->btv->crop[!!fh->do_crop].rect.height >> 1;
field = (win->w.height > height2)
? V4L2_FIELD_INTERLACED
: V4L2_FIELD_TOP;
}
win->field = field;
if (NULL == fh->ovfmt)
return -EINVAL;
width_mask = ~0;
switch (fh->ovfmt->depth) {
case 8:
case 24:
width_mask = ~3;
break;
case 16:
width_mask = ~1;
break;
case 32:
break;
default:
BUG();
}
win->w.width -= win->w.left & ~width_mask;
win->w.left = (win->w.left - width_mask - 1) & width_mask;
rc = limit_scaled_size_lock(fh, &win->w.width, &win->w.height,
field, width_mask,
0,
adjust_size, adjust_crop);
if (0 != rc)
return rc;
return 0;
}
static int setup_window_lock(struct bttv_fh *fh, struct bttv *btv,
struct v4l2_window *win, int fixup)
{
struct v4l2_clip *clips = NULL;
int n,size,retval = 0;
if (NULL == fh->ovfmt)
return -EINVAL;
if (!(fh->ovfmt->flags & FORMAT_FLAGS_PACKED))
return -EINVAL;
retval = verify_window_lock(fh, win,
fixup,
fixup);
if (0 != retval)
return retval;
n = win->clipcount;
size = sizeof(*clips)*(n+4);
clips = kmalloc(size,GFP_KERNEL);
if (NULL == clips)
return -ENOMEM;
if (n > 0) {
if (copy_from_user(clips,win->clips,sizeof(struct v4l2_clip)*n)) {
kfree(clips);
return -EFAULT;
}
}
if (NULL != btv->fbuf.base)
n = btcx_screen_clips(btv->fbuf.fmt.width, btv->fbuf.fmt.height,
&win->w, clips, n);
btcx_sort_clips(clips,n);
switch (fh->ovfmt->depth) {
case 8:
case 24:
btcx_align(&win->w, clips, n, 3);
break;
case 16:
btcx_align(&win->w, clips, n, 1);
break;
case 32:
break;
default:
BUG();
}
kfree(fh->ov.clips);
fh->ov.clips = clips;
fh->ov.nclips = n;
fh->ov.w = win->w;
fh->ov.field = win->field;
fh->ov.setup_ok = 1;
btv->init.ov.w.width = win->w.width;
btv->init.ov.w.height = win->w.height;
btv->init.ov.field = win->field;
retval = 0;
if (check_btres(fh, RESOURCE_OVERLAY)) {
struct bttv_buffer *new;
new = videobuf_sg_alloc(sizeof(*new));
new->crop = btv->crop[!!fh->do_crop].rect;
bttv_overlay_risc(btv, &fh->ov, fh->ovfmt, new);
retval = bttv_switch_overlay(btv,fh,new);
}
return retval;
}
static struct videobuf_queue* bttv_queue(struct bttv_fh *fh)
{
struct videobuf_queue* q = NULL;
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
q = &fh->cap;
break;
case V4L2_BUF_TYPE_VBI_CAPTURE:
q = &fh->vbi;
break;
default:
BUG();
}
return q;
}
static int bttv_resource(struct bttv_fh *fh)
{
int res = 0;
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
res = RESOURCE_VIDEO_STREAM;
break;
case V4L2_BUF_TYPE_VBI_CAPTURE:
res = RESOURCE_VBI;
break;
default:
BUG();
}
return res;
}
static int bttv_switch_type(struct bttv_fh *fh, enum v4l2_buf_type type)
{
struct videobuf_queue *q = bttv_queue(fh);
int res = bttv_resource(fh);
if (check_btres(fh,res))
return -EBUSY;
if (videobuf_queue_is_busy(q))
return -EBUSY;
fh->type = type;
return 0;
}
static void
pix_format_set_size (struct v4l2_pix_format * f,
const struct bttv_format * fmt,
unsigned int width,
unsigned int height)
{
f->width = width;
f->height = height;
if (fmt->flags & FORMAT_FLAGS_PLANAR) {
f->bytesperline = width;
f->sizeimage = (width * height * fmt->depth) >> 3;
} else {
f->bytesperline = (width * fmt->depth) >> 3;
f->sizeimage = height * f->bytesperline;
}
}
static int bttv_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bttv_fh *fh = priv;
pix_format_set_size(&f->fmt.pix, fh->fmt,
fh->width, fh->height);
f->fmt.pix.field = fh->cap.field;
f->fmt.pix.pixelformat = fh->fmt->fourcc;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int bttv_g_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bttv_fh *fh = priv;
f->fmt.win.w = fh->ov.w;
f->fmt.win.field = fh->ov.field;
return 0;
}
static void bttv_get_width_mask_vid_cap(const struct bttv_format *fmt,
unsigned int *width_mask,
unsigned int *width_bias)
{
if (fmt->flags & FORMAT_FLAGS_PLANAR) {
*width_mask = ~15;
*width_bias = 8;
} else {
*width_mask = ~3;
*width_bias = 2;
}
}
static int bttv_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
const struct bttv_format *fmt;
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
enum v4l2_field field;
__s32 width, height;
__s32 height2;
unsigned int width_mask, width_bias;
int rc;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (NULL == fmt)
return -EINVAL;
field = f->fmt.pix.field;
switch (field) {
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
case V4L2_FIELD_ALTERNATE:
case V4L2_FIELD_INTERLACED:
break;
case V4L2_FIELD_SEQ_BT:
case V4L2_FIELD_SEQ_TB:
if (!(fmt->flags & FORMAT_FLAGS_PLANAR)) {
field = V4L2_FIELD_SEQ_TB;
break;
}
default:
height2 = btv->crop[!!fh->do_crop].rect.height >> 1;
field = (f->fmt.pix.height > height2)
? V4L2_FIELD_INTERLACED
: V4L2_FIELD_BOTTOM;
break;
}
width = f->fmt.pix.width;
height = f->fmt.pix.height;
bttv_get_width_mask_vid_cap(fmt, &width_mask, &width_bias);
rc = limit_scaled_size_lock(fh, &width, &height, field,
width_mask, width_bias,
1,
0);
if (0 != rc)
return rc;
f->fmt.pix.field = field;
pix_format_set_size(&f->fmt.pix, fmt, width, height);
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int bttv_try_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bttv_fh *fh = priv;
verify_window_lock(fh, &f->fmt.win,
1,
0);
return 0;
}
static int bttv_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
int retval;
const struct bttv_format *fmt;
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
__s32 width, height;
unsigned int width_mask, width_bias;
enum v4l2_field field;
retval = bttv_switch_type(fh, f->type);
if (0 != retval)
return retval;
retval = bttv_try_fmt_vid_cap(file, priv, f);
if (0 != retval)
return retval;
width = f->fmt.pix.width;
height = f->fmt.pix.height;
field = f->fmt.pix.field;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
bttv_get_width_mask_vid_cap(fmt, &width_mask, &width_bias);
retval = limit_scaled_size_lock(fh, &width, &height, f->fmt.pix.field,
width_mask, width_bias,
1,
1);
if (0 != retval)
return retval;
f->fmt.pix.field = field;
fh->fmt = fmt;
fh->cap.field = f->fmt.pix.field;
fh->cap.last = V4L2_FIELD_NONE;
fh->width = f->fmt.pix.width;
fh->height = f->fmt.pix.height;
btv->init.fmt = fmt;
btv->init.width = f->fmt.pix.width;
btv->init.height = f->fmt.pix.height;
return 0;
}
static int bttv_s_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (no_overlay > 0) {
pr_err("V4L2_BUF_TYPE_VIDEO_OVERLAY: no_overlay\n");
return -EINVAL;
}
return setup_window_lock(fh, btv, &f->fmt.win, 1);
}
static int bttv_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct video_device *vdev = video_devdata(file);
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (0 == v4l2)
return -EINVAL;
strlcpy(cap->driver, "bttv", sizeof(cap->driver));
strlcpy(cap->card, btv->video_dev.name, sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info),
"PCI:%s", pci_name(btv->c.pci));
cap->capabilities =
V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING |
V4L2_CAP_DEVICE_CAPS;
if (no_overlay <= 0)
cap->capabilities |= V4L2_CAP_VIDEO_OVERLAY;
if (video_is_registered(&btv->vbi_dev))
cap->capabilities |= V4L2_CAP_VBI_CAPTURE;
if (video_is_registered(&btv->radio_dev))
cap->capabilities |= V4L2_CAP_RADIO;
if (btv->has_saa6588)
cap->capabilities |= V4L2_CAP_RDS_CAPTURE;
if (btv->tuner_type != TUNER_ABSENT)
cap->capabilities |= V4L2_CAP_TUNER;
if (vdev->vfl_type == VFL_TYPE_GRABBER)
cap->device_caps = cap->capabilities &
(V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING |
V4L2_CAP_VIDEO_OVERLAY |
V4L2_CAP_TUNER);
else if (vdev->vfl_type == VFL_TYPE_VBI)
cap->device_caps = cap->capabilities &
(V4L2_CAP_VBI_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING |
V4L2_CAP_TUNER);
else {
cap->device_caps = V4L2_CAP_RADIO | V4L2_CAP_TUNER;
if (btv->has_saa6588)
cap->device_caps |= V4L2_CAP_READWRITE |
V4L2_CAP_RDS_CAPTURE;
if (btv->has_tea575x)
cap->device_caps |= V4L2_CAP_HW_FREQ_SEEK;
}
return 0;
}
static int bttv_enum_fmt_cap_ovr(struct v4l2_fmtdesc *f)
{
int index = -1, i;
for (i = 0; i < FORMATS; i++) {
if (formats[i].fourcc != -1)
index++;
if ((unsigned int)index == f->index)
break;
}
if (FORMATS == i)
return -EINVAL;
f->pixelformat = formats[i].fourcc;
strlcpy(f->description, formats[i].name, sizeof(f->description));
return i;
}
static int bttv_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
int rc = bttv_enum_fmt_cap_ovr(f);
if (rc < 0)
return rc;
return 0;
}
static int bttv_enum_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
int rc;
if (no_overlay > 0) {
pr_err("V4L2_BUF_TYPE_VIDEO_OVERLAY: no_overlay\n");
return -EINVAL;
}
rc = bttv_enum_fmt_cap_ovr(f);
if (rc < 0)
return rc;
if (!(formats[rc].flags & FORMAT_FLAGS_PACKED))
return -EINVAL;
return 0;
}
static int bttv_g_fbuf(struct file *file, void *f,
struct v4l2_framebuffer *fb)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
*fb = btv->fbuf;
fb->capability = V4L2_FBUF_CAP_LIST_CLIPPING;
fb->flags = V4L2_FBUF_FLAG_PRIMARY;
if (fh->ovfmt)
fb->fmt.pixelformat = fh->ovfmt->fourcc;
return 0;
}
static int bttv_overlay(struct file *file, void *f, unsigned int on)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
struct bttv_buffer *new;
int retval = 0;
if (on) {
if (unlikely(!btv->fbuf.base)) {
return -EINVAL;
}
if (unlikely(!fh->ov.setup_ok)) {
dprintk("%d: overlay: !setup_ok\n", btv->c.nr);
retval = -EINVAL;
}
if (retval)
return retval;
}
if (!check_alloc_btres_lock(btv, fh, RESOURCE_OVERLAY))
return -EBUSY;
if (on) {
fh->ov.tvnorm = btv->tvnorm;
new = videobuf_sg_alloc(sizeof(*new));
new->crop = btv->crop[!!fh->do_crop].rect;
bttv_overlay_risc(btv, &fh->ov, fh->ovfmt, new);
} else {
new = NULL;
}
retval = bttv_switch_overlay(btv, fh, new);
return retval;
}
static int bttv_s_fbuf(struct file *file, void *f,
const struct v4l2_framebuffer *fb)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
const struct bttv_format *fmt;
int retval;
if (!capable(CAP_SYS_ADMIN) &&
!capable(CAP_SYS_RAWIO))
return -EPERM;
fmt = format_by_fourcc(fb->fmt.pixelformat);
if (NULL == fmt)
return -EINVAL;
if (0 == (fmt->flags & FORMAT_FLAGS_PACKED))
return -EINVAL;
retval = -EINVAL;
if (fb->flags & V4L2_FBUF_FLAG_OVERLAY) {
__s32 width = fb->fmt.width;
__s32 height = fb->fmt.height;
retval = limit_scaled_size_lock(fh, &width, &height,
V4L2_FIELD_INTERLACED,
~3,
2,
0,
0);
if (0 != retval)
return retval;
}
btv->fbuf.base = fb->base;
btv->fbuf.fmt.width = fb->fmt.width;
btv->fbuf.fmt.height = fb->fmt.height;
if (0 != fb->fmt.bytesperline)
btv->fbuf.fmt.bytesperline = fb->fmt.bytesperline;
else
btv->fbuf.fmt.bytesperline = btv->fbuf.fmt.width*fmt->depth/8;
retval = 0;
fh->ovfmt = fmt;
btv->init.ovfmt = fmt;
if (fb->flags & V4L2_FBUF_FLAG_OVERLAY) {
fh->ov.w.left = 0;
fh->ov.w.top = 0;
fh->ov.w.width = fb->fmt.width;
fh->ov.w.height = fb->fmt.height;
btv->init.ov.w.width = fb->fmt.width;
btv->init.ov.w.height = fb->fmt.height;
kfree(fh->ov.clips);
fh->ov.clips = NULL;
fh->ov.nclips = 0;
if (check_btres(fh, RESOURCE_OVERLAY)) {
struct bttv_buffer *new;
new = videobuf_sg_alloc(sizeof(*new));
new->crop = btv->crop[!!fh->do_crop].rect;
bttv_overlay_risc(btv, &fh->ov, fh->ovfmt, new);
retval = bttv_switch_overlay(btv, fh, new);
}
}
return retval;
}
static int bttv_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct bttv_fh *fh = priv;
return videobuf_reqbufs(bttv_queue(fh), p);
}
static int bttv_querybuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct bttv_fh *fh = priv;
return videobuf_querybuf(bttv_queue(fh), b);
}
static int bttv_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
int res = bttv_resource(fh);
if (!check_alloc_btres_lock(btv, fh, res))
return -EBUSY;
return videobuf_qbuf(bttv_queue(fh), b);
}
static int bttv_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct bttv_fh *fh = priv;
return videobuf_dqbuf(bttv_queue(fh), b,
file->f_flags & O_NONBLOCK);
}
static int bttv_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
int res = bttv_resource(fh);
if (!check_alloc_btres_lock(btv, fh, res))
return -EBUSY;
return videobuf_streamon(bttv_queue(fh));
}
static int bttv_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
int retval;
int res = bttv_resource(fh);
retval = videobuf_streamoff(bttv_queue(fh));
if (retval < 0)
return retval;
free_btres_lock(btv, fh, res);
return 0;
}
static int bttv_g_parm(struct file *file, void *f,
struct v4l2_streamparm *parm)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
parm->parm.capture.readbuffers = gbuffers;
v4l2_video_std_frame_period(bttv_tvnorms[btv->tvnorm].v4l2_id,
&parm->parm.capture.timeperframe);
return 0;
}
static int bttv_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (0 != t->index)
return -EINVAL;
t->rxsubchans = V4L2_TUNER_SUB_MONO;
t->capability = V4L2_TUNER_CAP_NORM;
bttv_call_all(btv, tuner, g_tuner, t);
strcpy(t->name, "Television");
t->type = V4L2_TUNER_ANALOG_TV;
if (btread(BT848_DSTATUS)&BT848_DSTATUS_HLOC)
t->signal = 0xffff;
if (btv->audio_mode_gpio)
btv->audio_mode_gpio(btv, t, 0);
return 0;
}
static int bttv_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *cap)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (cap->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
cap->type != V4L2_BUF_TYPE_VIDEO_OVERLAY)
return -EINVAL;
cap->pixelaspect = bttv_tvnorms[btv->tvnorm].cropcap.pixelaspect;
return 0;
}
static int bttv_g_selection(struct file *file, void *f, struct v4l2_selection *sel)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
if (sel->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
sel->type != V4L2_BUF_TYPE_VIDEO_OVERLAY)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP:
sel->r = btv->crop[!!fh->do_crop].rect;
break;
case V4L2_SEL_TGT_CROP_DEFAULT:
sel->r = bttv_tvnorms[btv->tvnorm].cropcap.defrect;
break;
case V4L2_SEL_TGT_CROP_BOUNDS:
sel->r = bttv_tvnorms[btv->tvnorm].cropcap.bounds;
break;
default:
return -EINVAL;
}
return 0;
}
static int bttv_s_selection(struct file *file, void *f, struct v4l2_selection *sel)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
const struct v4l2_rect *b;
int retval;
struct bttv_crop c;
__s32 b_left;
__s32 b_top;
__s32 b_right;
__s32 b_bottom;
if (sel->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
sel->type != V4L2_BUF_TYPE_VIDEO_OVERLAY)
return -EINVAL;
if (sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
retval = -EBUSY;
if (locked_btres(fh->btv, VIDEO_RESOURCES)) {
return retval;
}
b = &bttv_tvnorms[btv->tvnorm].cropcap.bounds;
b_left = b->left;
b_right = b_left + b->width;
b_bottom = b->top + b->height;
b_top = max(b->top, btv->vbi_end);
if (b_top + 32 >= b_bottom) {
return retval;
}
c.rect.left = clamp_t(s32, sel->r.left, b_left, b_right - 48);
c.rect.left = min(c.rect.left, (__s32) MAX_HDELAY);
c.rect.width = clamp_t(s32, sel->r.width,
48, b_right - c.rect.left);
c.rect.top = clamp_t(s32, sel->r.top, b_top, b_bottom - 32);
c.rect.top = (c.rect.top + 1) & ~1;
c.rect.height = clamp_t(s32, sel->r.height,
32, b_bottom - c.rect.top);
c.rect.height = (c.rect.height + 1) & ~1;
bttv_crop_calc_limits(&c);
sel->r = c.rect;
btv->crop[1] = c;
fh->do_crop = 1;
if (fh->width < c.min_scaled_width) {
fh->width = c.min_scaled_width;
btv->init.width = c.min_scaled_width;
} else if (fh->width > c.max_scaled_width) {
fh->width = c.max_scaled_width;
btv->init.width = c.max_scaled_width;
}
if (fh->height < c.min_scaled_height) {
fh->height = c.min_scaled_height;
btv->init.height = c.min_scaled_height;
} else if (fh->height > c.max_scaled_height) {
fh->height = c.max_scaled_height;
btv->init.height = c.max_scaled_height;
}
return 0;
}
static ssize_t bttv_read(struct file *file, char __user *data,
size_t count, loff_t *ppos)
{
struct bttv_fh *fh = file->private_data;
int retval = 0;
if (fh->btv->errors)
bttv_reinit_bt848(fh->btv);
dprintk("%d: read count=%d type=%s\n",
fh->btv->c.nr, (int)count, v4l2_type_names[fh->type]);
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
if (!check_alloc_btres_lock(fh->btv, fh, RESOURCE_VIDEO_READ)) {
return -EBUSY;
}
retval = videobuf_read_one(&fh->cap, data, count, ppos,
file->f_flags & O_NONBLOCK);
free_btres_lock(fh->btv, fh, RESOURCE_VIDEO_READ);
break;
case V4L2_BUF_TYPE_VBI_CAPTURE:
if (!check_alloc_btres_lock(fh->btv,fh,RESOURCE_VBI))
return -EBUSY;
retval = videobuf_read_stream(&fh->vbi, data, count, ppos, 1,
file->f_flags & O_NONBLOCK);
break;
default:
BUG();
}
return retval;
}
static unsigned int bttv_poll(struct file *file, poll_table *wait)
{
struct bttv_fh *fh = file->private_data;
struct bttv_buffer *buf;
enum v4l2_field field;
unsigned int rc = 0;
unsigned long req_events = poll_requested_events(wait);
if (v4l2_event_pending(&fh->fh))
rc = POLLPRI;
else if (req_events & POLLPRI)
poll_wait(file, &fh->fh.wait, wait);
if (!(req_events & (POLLIN | POLLRDNORM)))
return rc;
if (V4L2_BUF_TYPE_VBI_CAPTURE == fh->type) {
if (!check_alloc_btres_lock(fh->btv,fh,RESOURCE_VBI))
return rc | POLLERR;
return rc | videobuf_poll_stream(file, &fh->vbi, wait);
}
if (check_btres(fh,RESOURCE_VIDEO_STREAM)) {
if (list_empty(&fh->cap.stream))
return rc | POLLERR;
buf = list_entry(fh->cap.stream.next,struct bttv_buffer,vb.stream);
} else {
if (NULL == fh->cap.read_buf) {
if (locked_btres(fh->btv,RESOURCE_VIDEO_STREAM))
return rc | POLLERR;
fh->cap.read_buf = videobuf_sg_alloc(fh->cap.msize);
if (NULL == fh->cap.read_buf)
return rc | POLLERR;
fh->cap.read_buf->memory = V4L2_MEMORY_USERPTR;
field = videobuf_next_field(&fh->cap);
if (0 != fh->cap.ops->buf_prepare(&fh->cap,fh->cap.read_buf,field)) {
kfree (fh->cap.read_buf);
fh->cap.read_buf = NULL;
return rc | POLLERR;
}
fh->cap.ops->buf_queue(&fh->cap,fh->cap.read_buf);
fh->cap.read_off = 0;
}
buf = (struct bttv_buffer*)fh->cap.read_buf;
}
poll_wait(file, &buf->vb.done, wait);
if (buf->vb.state == VIDEOBUF_DONE ||
buf->vb.state == VIDEOBUF_ERROR)
rc = rc | POLLIN|POLLRDNORM;
return rc;
}
static int bttv_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct bttv *btv = video_drvdata(file);
struct bttv_fh *fh;
enum v4l2_buf_type type = 0;
dprintk("open dev=%s\n", video_device_node_name(vdev));
if (vdev->vfl_type == VFL_TYPE_GRABBER) {
type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
} else if (vdev->vfl_type == VFL_TYPE_VBI) {
type = V4L2_BUF_TYPE_VBI_CAPTURE;
} else {
WARN_ON(1);
return -ENODEV;
}
dprintk("%d: open called (type=%s)\n",
btv->c.nr, v4l2_type_names[type]);
fh = kmalloc(sizeof(*fh), GFP_KERNEL);
if (unlikely(!fh))
return -ENOMEM;
btv->users++;
file->private_data = fh;
*fh = btv->init;
v4l2_fh_init(&fh->fh, vdev);
fh->type = type;
fh->ov.setup_ok = 0;
videobuf_queue_sg_init(&fh->cap, &bttv_video_qops,
&btv->c.pci->dev, &btv->s_lock,
V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_INTERLACED,
sizeof(struct bttv_buffer),
fh, &btv->lock);
videobuf_queue_sg_init(&fh->vbi, &bttv_vbi_qops,
&btv->c.pci->dev, &btv->s_lock,
V4L2_BUF_TYPE_VBI_CAPTURE,
V4L2_FIELD_SEQ_TB,
sizeof(struct bttv_buffer),
fh, &btv->lock);
set_tvnorm(btv,btv->tvnorm);
set_input(btv, btv->input, btv->tvnorm);
audio_mute(btv, btv->mute);
fh->do_crop = !reset_crop;
bttv_vbi_fmt_reset(&fh->vbi_fmt, btv->tvnorm);
bttv_field_count(btv);
v4l2_fh_add(&fh->fh);
return 0;
}
static int bttv_release(struct file *file)
{
struct bttv_fh *fh = file->private_data;
struct bttv *btv = fh->btv;
if (check_btres(fh, RESOURCE_OVERLAY))
bttv_switch_overlay(btv,fh,NULL);
if (check_btres(fh, RESOURCE_VIDEO_STREAM)) {
videobuf_streamoff(&fh->cap);
free_btres_lock(btv,fh,RESOURCE_VIDEO_STREAM);
}
if (fh->cap.read_buf) {
buffer_release(&fh->cap,fh->cap.read_buf);
kfree(fh->cap.read_buf);
}
if (check_btres(fh, RESOURCE_VIDEO_READ)) {
free_btres_lock(btv, fh, RESOURCE_VIDEO_READ);
}
if (check_btres(fh, RESOURCE_VBI)) {
videobuf_stop(&fh->vbi);
free_btres_lock(btv,fh,RESOURCE_VBI);
}
videobuf_mmap_free(&fh->cap);
videobuf_mmap_free(&fh->vbi);
file->private_data = NULL;
btv->users--;
bttv_field_count(btv);
if (!btv->users)
audio_mute(btv, btv->mute);
v4l2_fh_del(&fh->fh);
v4l2_fh_exit(&fh->fh);
kfree(fh);
return 0;
}
static int
bttv_mmap(struct file *file, struct vm_area_struct *vma)
{
struct bttv_fh *fh = file->private_data;
dprintk("%d: mmap type=%s 0x%lx+%ld\n",
fh->btv->c.nr, v4l2_type_names[fh->type],
vma->vm_start, vma->vm_end - vma->vm_start);
return videobuf_mmap_mapper(bttv_queue(fh),vma);
}
static int radio_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct bttv *btv = video_drvdata(file);
struct bttv_fh *fh;
dprintk("open dev=%s\n", video_device_node_name(vdev));
dprintk("%d: open called (radio)\n", btv->c.nr);
fh = kmalloc(sizeof(*fh), GFP_KERNEL);
if (unlikely(!fh))
return -ENOMEM;
file->private_data = fh;
*fh = btv->init;
v4l2_fh_init(&fh->fh, vdev);
btv->radio_user++;
audio_mute(btv, btv->mute);
v4l2_fh_add(&fh->fh);
return 0;
}
static int radio_release(struct file *file)
{
struct bttv_fh *fh = file->private_data;
struct bttv *btv = fh->btv;
struct saa6588_command cmd;
file->private_data = NULL;
v4l2_fh_del(&fh->fh);
v4l2_fh_exit(&fh->fh);
kfree(fh);
btv->radio_user--;
bttv_call_all(btv, core, ioctl, SAA6588_CMD_CLOSE, &cmd);
if (btv->radio_user == 0)
btv->has_radio_tuner = 0;
return 0;
}
static int radio_g_tuner(struct file *file, void *priv, struct v4l2_tuner *t)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Radio");
t->type = V4L2_TUNER_RADIO;
radio_enable(btv);
bttv_call_all(btv, tuner, g_tuner, t);
if (btv->audio_mode_gpio)
btv->audio_mode_gpio(btv, t, 0);
if (btv->has_tea575x)
return snd_tea575x_g_tuner(&btv->tea, t);
return 0;
}
static int radio_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (0 != t->index)
return -EINVAL;
radio_enable(btv);
bttv_call_all(btv, tuner, s_tuner, t);
return 0;
}
static int radio_s_hw_freq_seek(struct file *file, void *priv,
const struct v4l2_hw_freq_seek *a)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (btv->has_tea575x)
return snd_tea575x_s_hw_freq_seek(file, &btv->tea, a);
return -ENOTTY;
}
static int radio_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
struct bttv_fh *fh = priv;
struct bttv *btv = fh->btv;
if (btv->has_tea575x)
return snd_tea575x_enum_freq_bands(&btv->tea, band);
return -ENOTTY;
}
static ssize_t radio_read(struct file *file, char __user *data,
size_t count, loff_t *ppos)
{
struct bttv_fh *fh = file->private_data;
struct bttv *btv = fh->btv;
struct saa6588_command cmd;
cmd.block_count = count / 3;
cmd.nonblocking = file->f_flags & O_NONBLOCK;
cmd.buffer = data;
cmd.instance = file;
cmd.result = -ENODEV;
radio_enable(btv);
bttv_call_all(btv, core, ioctl, SAA6588_CMD_READ, &cmd);
return cmd.result;
}
static unsigned int radio_poll(struct file *file, poll_table *wait)
{
struct bttv_fh *fh = file->private_data;
struct bttv *btv = fh->btv;
unsigned long req_events = poll_requested_events(wait);
struct saa6588_command cmd;
unsigned int res = 0;
if (v4l2_event_pending(&fh->fh))
res = POLLPRI;
else if (req_events & POLLPRI)
poll_wait(file, &fh->fh.wait, wait);
radio_enable(btv);
cmd.instance = file;
cmd.event_list = wait;
cmd.result = res;
bttv_call_all(btv, core, ioctl, SAA6588_CMD_POLL, &cmd);
return cmd.result;
}
static int bttv_risc_decode(u32 risc)
{
static char *instr[16] = {
[ BT848_RISC_WRITE >> 28 ] = "write",
[ BT848_RISC_SKIP >> 28 ] = "skip",
[ BT848_RISC_WRITEC >> 28 ] = "writec",
[ BT848_RISC_JUMP >> 28 ] = "jump",
[ BT848_RISC_SYNC >> 28 ] = "sync",
[ BT848_RISC_WRITE123 >> 28 ] = "write123",
[ BT848_RISC_SKIP123 >> 28 ] = "skip123",
[ BT848_RISC_WRITE1S23 >> 28 ] = "write1s23",
};
static int incr[16] = {
[ BT848_RISC_WRITE >> 28 ] = 2,
[ BT848_RISC_JUMP >> 28 ] = 2,
[ BT848_RISC_SYNC >> 28 ] = 2,
[ BT848_RISC_WRITE123 >> 28 ] = 5,
[ BT848_RISC_SKIP123 >> 28 ] = 2,
[ BT848_RISC_WRITE1S23 >> 28 ] = 3,
};
static char *bits[] = {
"be0", "be1", "be2", "be3/resync",
"set0", "set1", "set2", "set3",
"clr0", "clr1", "clr2", "clr3",
"irq", "res", "eol", "sol",
};
int i;
pr_cont("0x%08x [ %s", risc,
instr[risc >> 28] ? instr[risc >> 28] : "INVALID");
for (i = ARRAY_SIZE(bits)-1; i >= 0; i--)
if (risc & (1 << (i + 12)))
pr_cont(" %s", bits[i]);
pr_cont(" count=%d ]\n", risc & 0xfff);
return incr[risc >> 28] ? incr[risc >> 28] : 1;
}
static void bttv_risc_disasm(struct bttv *btv,
struct btcx_riscmem *risc)
{
unsigned int i,j,n;
pr_info("%s: risc disasm: %p [dma=0x%08lx]\n",
btv->c.v4l2_dev.name, risc->cpu, (unsigned long)risc->dma);
for (i = 0; i < (risc->size >> 2); i += n) {
pr_info("%s: 0x%lx: ",
btv->c.v4l2_dev.name,
(unsigned long)(risc->dma + (i<<2)));
n = bttv_risc_decode(le32_to_cpu(risc->cpu[i]));
for (j = 1; j < n; j++)
pr_info("%s: 0x%lx: 0x%08x [ arg #%d ]\n",
btv->c.v4l2_dev.name,
(unsigned long)(risc->dma + ((i+j)<<2)),
risc->cpu[i+j], j);
if (0 == risc->cpu[i])
break;
}
}
static void bttv_print_riscaddr(struct bttv *btv)
{
pr_info(" main: %08llx\n", (unsigned long long)btv->main.dma);
pr_info(" vbi : o=%08llx e=%08llx\n",
btv->cvbi ? (unsigned long long)btv->cvbi->top.dma : 0,
btv->cvbi ? (unsigned long long)btv->cvbi->bottom.dma : 0);
pr_info(" cap : o=%08llx e=%08llx\n",
btv->curr.top
? (unsigned long long)btv->curr.top->top.dma : 0,
btv->curr.bottom
? (unsigned long long)btv->curr.bottom->bottom.dma : 0);
pr_info(" scr : o=%08llx e=%08llx\n",
btv->screen ? (unsigned long long)btv->screen->top.dma : 0,
btv->screen ? (unsigned long long)btv->screen->bottom.dma : 0);
bttv_risc_disasm(btv, &btv->main);
}
static void bttv_print_irqbits(u32 print, u32 mark)
{
unsigned int i;
pr_cont("bits:");
for (i = 0; i < ARRAY_SIZE(irq_name); i++) {
if (print & (1 << i))
pr_cont(" %s", irq_name[i]);
if (mark & (1 << i))
pr_cont("*");
}
}
static void bttv_irq_debug_low_latency(struct bttv *btv, u32 rc)
{
pr_warn("%d: irq: skipped frame [main=%lx,o_vbi=%lx,o_field=%lx,rc=%lx]\n",
btv->c.nr,
(unsigned long)btv->main.dma,
(unsigned long)le32_to_cpu(btv->main.cpu[RISC_SLOT_O_VBI+1]),
(unsigned long)le32_to_cpu(btv->main.cpu[RISC_SLOT_O_FIELD+1]),
(unsigned long)rc);
if (0 == (btread(BT848_DSTATUS) & BT848_DSTATUS_HLOC)) {
pr_notice("%d: Oh, there (temporarily?) is no input signal. Ok, then this is harmless, don't worry ;)\n",
btv->c.nr);
return;
}
pr_notice("%d: Uhm. Looks like we have unusual high IRQ latencies\n",
btv->c.nr);
pr_notice("%d: Lets try to catch the culpit red-handed ...\n",
btv->c.nr);
dump_stack();
}
static int
bttv_irq_next_video(struct bttv *btv, struct bttv_buffer_set *set)
{
struct bttv_buffer *item;
memset(set,0,sizeof(*set));
if (!list_empty(&btv->capture)) {
set->frame_irq = 1;
item = list_entry(btv->capture.next, struct bttv_buffer, vb.queue);
if (V4L2_FIELD_HAS_TOP(item->vb.field))
set->top = item;
if (V4L2_FIELD_HAS_BOTTOM(item->vb.field))
set->bottom = item;
if (!V4L2_FIELD_HAS_BOTH(item->vb.field) &&
(item->vb.queue.next != &btv->capture)) {
item = list_entry(item->vb.queue.next, struct bttv_buffer, vb.queue);
if (!V4L2_FIELD_HAS_BOTH(item->vb.field)) {
if (NULL == set->bottom &&
V4L2_FIELD_BOTTOM == item->vb.field) {
set->bottom = item;
}
if (NULL != set->top && NULL != set->bottom)
set->top_irq = 2;
}
}
}
if (NULL != btv->screen) {
if (V4L2_FIELD_HAS_BOTH(btv->screen->vb.field)) {
if (NULL == set->top && NULL == set->bottom) {
set->top = btv->screen;
set->bottom = btv->screen;
}
} else {
if (V4L2_FIELD_TOP == btv->screen->vb.field &&
NULL == set->top) {
set->top = btv->screen;
}
if (V4L2_FIELD_BOTTOM == btv->screen->vb.field &&
NULL == set->bottom) {
set->bottom = btv->screen;
}
}
}
dprintk("%d: next set: top=%p bottom=%p [screen=%p,irq=%d,%d]\n",
btv->c.nr, set->top, set->bottom,
btv->screen, set->frame_irq, set->top_irq);
return 0;
}
static void
bttv_irq_wakeup_video(struct bttv *btv, struct bttv_buffer_set *wakeup,
struct bttv_buffer_set *curr, unsigned int state)
{
struct timeval ts;
v4l2_get_timestamp(&ts);
if (wakeup->top == wakeup->bottom) {
if (NULL != wakeup->top && curr->top != wakeup->top) {
if (irq_debug > 1)
pr_debug("%d: wakeup: both=%p\n",
btv->c.nr, wakeup->top);
wakeup->top->vb.ts = ts;
wakeup->top->vb.field_count = btv->field_count;
wakeup->top->vb.state = state;
wake_up(&wakeup->top->vb.done);
}
} else {
if (NULL != wakeup->top && curr->top != wakeup->top) {
if (irq_debug > 1)
pr_debug("%d: wakeup: top=%p\n",
btv->c.nr, wakeup->top);
wakeup->top->vb.ts = ts;
wakeup->top->vb.field_count = btv->field_count;
wakeup->top->vb.state = state;
wake_up(&wakeup->top->vb.done);
}
if (NULL != wakeup->bottom && curr->bottom != wakeup->bottom) {
if (irq_debug > 1)
pr_debug("%d: wakeup: bottom=%p\n",
btv->c.nr, wakeup->bottom);
wakeup->bottom->vb.ts = ts;
wakeup->bottom->vb.field_count = btv->field_count;
wakeup->bottom->vb.state = state;
wake_up(&wakeup->bottom->vb.done);
}
}
}
static void
bttv_irq_wakeup_vbi(struct bttv *btv, struct bttv_buffer *wakeup,
unsigned int state)
{
if (NULL == wakeup)
return;
v4l2_get_timestamp(&wakeup->vb.ts);
wakeup->vb.field_count = btv->field_count;
wakeup->vb.state = state;
wake_up(&wakeup->vb.done);
}
static void bttv_irq_timeout(unsigned long data)
{
struct bttv *btv = (struct bttv *)data;
struct bttv_buffer_set old,new;
struct bttv_buffer *ovbi;
struct bttv_buffer *item;
unsigned long flags;
if (bttv_verbose) {
pr_info("%d: timeout: drop=%d irq=%d/%d, risc=%08x, ",
btv->c.nr, btv->framedrop, btv->irq_me, btv->irq_total,
btread(BT848_RISC_COUNT));
bttv_print_irqbits(btread(BT848_INT_STAT),0);
pr_cont("\n");
}
spin_lock_irqsave(&btv->s_lock,flags);
memset(&new,0,sizeof(new));
old = btv->curr;
ovbi = btv->cvbi;
btv->curr = new;
btv->cvbi = NULL;
btv->loop_irq = 0;
bttv_buffer_activate_video(btv, &new);
bttv_buffer_activate_vbi(btv, NULL);
bttv_set_dma(btv, 0);
bttv_irq_wakeup_video(btv, &old, &new, VIDEOBUF_ERROR);
bttv_irq_wakeup_vbi(btv, ovbi, VIDEOBUF_ERROR);
while (!list_empty(&btv->capture)) {
item = list_entry(btv->capture.next, struct bttv_buffer, vb.queue);
list_del(&item->vb.queue);
item->vb.state = VIDEOBUF_ERROR;
wake_up(&item->vb.done);
}
while (!list_empty(&btv->vcapture)) {
item = list_entry(btv->vcapture.next, struct bttv_buffer, vb.queue);
list_del(&item->vb.queue);
item->vb.state = VIDEOBUF_ERROR;
wake_up(&item->vb.done);
}
btv->errors++;
spin_unlock_irqrestore(&btv->s_lock,flags);
}
static void
bttv_irq_wakeup_top(struct bttv *btv)
{
struct bttv_buffer *wakeup = btv->curr.top;
if (NULL == wakeup)
return;
spin_lock(&btv->s_lock);
btv->curr.top_irq = 0;
btv->curr.top = NULL;
bttv_risc_hook(btv, RISC_SLOT_O_FIELD, NULL, 0);
v4l2_get_timestamp(&wakeup->vb.ts);
wakeup->vb.field_count = btv->field_count;
wakeup->vb.state = VIDEOBUF_DONE;
wake_up(&wakeup->vb.done);
spin_unlock(&btv->s_lock);
}
static inline int is_active(struct btcx_riscmem *risc, u32 rc)
{
if (rc < risc->dma)
return 0;
if (rc > risc->dma + risc->size)
return 0;
return 1;
}
static void
bttv_irq_switch_video(struct bttv *btv)
{
struct bttv_buffer_set new;
struct bttv_buffer_set old;
dma_addr_t rc;
spin_lock(&btv->s_lock);
bttv_irq_next_video(btv, &new);
rc = btread(BT848_RISC_COUNT);
if ((btv->curr.top && is_active(&btv->curr.top->top, rc)) ||
(btv->curr.bottom && is_active(&btv->curr.bottom->bottom, rc))) {
btv->framedrop++;
if (debug_latency)
bttv_irq_debug_low_latency(btv, rc);
spin_unlock(&btv->s_lock);
return;
}
old = btv->curr;
btv->curr = new;
btv->loop_irq &= ~1;
bttv_buffer_activate_video(btv, &new);
bttv_set_dma(btv, 0);
if (UNSET != btv->new_input) {
video_mux(btv,btv->new_input);
btv->new_input = UNSET;
}
bttv_irq_wakeup_video(btv, &old, &new, VIDEOBUF_DONE);
spin_unlock(&btv->s_lock);
}
static void
bttv_irq_switch_vbi(struct bttv *btv)
{
struct bttv_buffer *new = NULL;
struct bttv_buffer *old;
u32 rc;
spin_lock(&btv->s_lock);
if (!list_empty(&btv->vcapture))
new = list_entry(btv->vcapture.next, struct bttv_buffer, vb.queue);
old = btv->cvbi;
rc = btread(BT848_RISC_COUNT);
if (NULL != old && (is_active(&old->top, rc) ||
is_active(&old->bottom, rc))) {
btv->framedrop++;
if (debug_latency)
bttv_irq_debug_low_latency(btv, rc);
spin_unlock(&btv->s_lock);
return;
}
btv->cvbi = new;
btv->loop_irq &= ~4;
bttv_buffer_activate_vbi(btv, new);
bttv_set_dma(btv, 0);
bttv_irq_wakeup_vbi(btv, old, VIDEOBUF_DONE);
spin_unlock(&btv->s_lock);
}
static irqreturn_t bttv_irq(int irq, void *dev_id)
{
u32 stat,astat;
u32 dstat;
int count;
struct bttv *btv;
int handled = 0;
btv=(struct bttv *)dev_id;
count=0;
while (1) {
stat=btread(BT848_INT_STAT);
astat=stat&btread(BT848_INT_MASK);
if (!astat)
break;
handled = 1;
btwrite(stat,BT848_INT_STAT);
dstat=btread(BT848_DSTATUS);
if (irq_debug) {
pr_debug("%d: irq loop=%d fc=%d riscs=%x, riscc=%08x, ",
btv->c.nr, count, btv->field_count,
stat>>28, btread(BT848_RISC_COUNT));
bttv_print_irqbits(stat,astat);
if (stat & BT848_INT_HLOCK)
pr_cont(" HLOC => %s",
dstat & BT848_DSTATUS_HLOC
? "yes" : "no");
if (stat & BT848_INT_VPRES)
pr_cont(" PRES => %s",
dstat & BT848_DSTATUS_PRES
? "yes" : "no");
if (stat & BT848_INT_FMTCHG)
pr_cont(" NUML => %s",
dstat & BT848_DSTATUS_NUML
? "625" : "525");
pr_cont("\n");
}
if (astat&BT848_INT_VSYNC)
btv->field_count++;
if ((astat & BT848_INT_GPINT) && btv->remote) {
bttv_input_irq(btv);
}
if (astat & BT848_INT_I2CDONE) {
btv->i2c_done = stat;
wake_up(&btv->i2c_queue);
}
if ((astat & BT848_INT_RISCI) && (stat & (4<<28)))
bttv_irq_switch_vbi(btv);
if ((astat & BT848_INT_RISCI) && (stat & (2<<28)))
bttv_irq_wakeup_top(btv);
if ((astat & BT848_INT_RISCI) && (stat & (1<<28)))
bttv_irq_switch_video(btv);
if ((astat & BT848_INT_HLOCK) && btv->opt_automute)
audio_mux_gpio(btv, btv->audio_input, btv->mute);
if (astat & (BT848_INT_SCERR|BT848_INT_OCERR)) {
pr_info("%d: %s%s @ %08x,",
btv->c.nr,
(astat & BT848_INT_SCERR) ? "SCERR" : "",
(astat & BT848_INT_OCERR) ? "OCERR" : "",
btread(BT848_RISC_COUNT));
bttv_print_irqbits(stat,astat);
pr_cont("\n");
if (bttv_debug)
bttv_print_riscaddr(btv);
}
if (fdsr && astat & BT848_INT_FDSR) {
pr_info("%d: FDSR @ %08x\n",
btv->c.nr, btread(BT848_RISC_COUNT));
if (bttv_debug)
bttv_print_riscaddr(btv);
}
count++;
if (count > 4) {
if (count > 8 || !(astat & BT848_INT_GPINT)) {
btwrite(0, BT848_INT_MASK);
pr_err("%d: IRQ lockup, cleared int mask [",
btv->c.nr);
} else {
pr_err("%d: IRQ lockup, clearing GPINT from int mask [",
btv->c.nr);
btwrite(btread(BT848_INT_MASK) & (-1 ^ BT848_INT_GPINT),
BT848_INT_MASK);
}
bttv_print_irqbits(stat,astat);
pr_cont("]\n");
}
}
btv->irq_total++;
if (handled)
btv->irq_me++;
return IRQ_RETVAL(handled);
}
static void vdev_init(struct bttv *btv,
struct video_device *vfd,
const struct video_device *template,
const char *type_name)
{
*vfd = *template;
vfd->v4l2_dev = &btv->c.v4l2_dev;
vfd->release = video_device_release_empty;
video_set_drvdata(vfd, btv);
snprintf(vfd->name, sizeof(vfd->name), "BT%d%s %s (%s)",
btv->id, (btv->id==848 && btv->revision==0x12) ? "A" : "",
type_name, bttv_tvcards[btv->c.type].name);
if (btv->tuner_type == TUNER_ABSENT) {
v4l2_disable_ioctl(vfd, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(vfd, VIDIOC_S_FREQUENCY);
v4l2_disable_ioctl(vfd, VIDIOC_G_TUNER);
v4l2_disable_ioctl(vfd, VIDIOC_S_TUNER);
}
}
static void bttv_unregister_video(struct bttv *btv)
{
video_unregister_device(&btv->video_dev);
video_unregister_device(&btv->vbi_dev);
video_unregister_device(&btv->radio_dev);
}
static int bttv_register_video(struct bttv *btv)
{
if (no_overlay > 0)
pr_notice("Overlay support disabled\n");
vdev_init(btv, &btv->video_dev, &bttv_video_template, "video");
if (video_register_device(&btv->video_dev, VFL_TYPE_GRABBER,
video_nr[btv->c.nr]) < 0)
goto err;
pr_info("%d: registered device %s\n",
btv->c.nr, video_device_node_name(&btv->video_dev));
if (device_create_file(&btv->video_dev.dev,
&dev_attr_card)<0) {
pr_err("%d: device_create_file 'card' failed\n", btv->c.nr);
goto err;
}
vdev_init(btv, &btv->vbi_dev, &bttv_video_template, "vbi");
if (video_register_device(&btv->vbi_dev, VFL_TYPE_VBI,
vbi_nr[btv->c.nr]) < 0)
goto err;
pr_info("%d: registered device %s\n",
btv->c.nr, video_device_node_name(&btv->vbi_dev));
if (!btv->has_radio)
return 0;
vdev_init(btv, &btv->radio_dev, &radio_template, "radio");
btv->radio_dev.ctrl_handler = &btv->radio_ctrl_handler;
if (video_register_device(&btv->radio_dev, VFL_TYPE_RADIO,
radio_nr[btv->c.nr]) < 0)
goto err;
pr_info("%d: registered device %s\n",
btv->c.nr, video_device_node_name(&btv->radio_dev));
return 0;
err:
bttv_unregister_video(btv);
return -1;
}
static void pci_set_command(struct pci_dev *dev)
{
#if defined(__powerpc__)
unsigned int cmd;
pci_read_config_dword(dev, PCI_COMMAND, &cmd);
cmd = (cmd | PCI_COMMAND_MEMORY );
pci_write_config_dword(dev, PCI_COMMAND, cmd);
#endif
}
static int bttv_probe(struct pci_dev *dev, const struct pci_device_id *pci_id)
{
struct v4l2_frequency init_freq = {
.tuner = 0,
.type = V4L2_TUNER_ANALOG_TV,
.frequency = 980,
};
int result;
unsigned char lat;
struct bttv *btv;
struct v4l2_ctrl_handler *hdl;
if (bttv_num == BTTV_MAX)
return -ENOMEM;
pr_info("Bt8xx card found (%d)\n", bttv_num);
bttvs[bttv_num] = btv = kzalloc(sizeof(*btv), GFP_KERNEL);
if (btv == NULL) {
pr_err("out of memory\n");
return -ENOMEM;
}
btv->c.nr = bttv_num;
snprintf(btv->c.v4l2_dev.name, sizeof(btv->c.v4l2_dev.name),
"bttv%d", btv->c.nr);
mutex_init(&btv->lock);
spin_lock_init(&btv->s_lock);
spin_lock_init(&btv->gpio_lock);
init_waitqueue_head(&btv->i2c_queue);
INIT_LIST_HEAD(&btv->c.subs);
INIT_LIST_HEAD(&btv->capture);
INIT_LIST_HEAD(&btv->vcapture);
setup_timer(&btv->timeout, bttv_irq_timeout, (unsigned long)btv);
btv->i2c_rc = -1;
btv->tuner_type = UNSET;
btv->new_input = UNSET;
btv->has_radio=radio[btv->c.nr];
btv->c.pci = dev;
btv->id = dev->device;
if (pci_enable_device(dev)) {
pr_warn("%d: Can't enable device\n", btv->c.nr);
return -EIO;
}
if (pci_set_dma_mask(dev, DMA_BIT_MASK(32))) {
pr_warn("%d: No suitable DMA available\n", btv->c.nr);
return -EIO;
}
if (!request_mem_region(pci_resource_start(dev,0),
pci_resource_len(dev,0),
btv->c.v4l2_dev.name)) {
pr_warn("%d: can't request iomem (0x%llx)\n",
btv->c.nr,
(unsigned long long)pci_resource_start(dev, 0));
return -EBUSY;
}
pci_set_master(dev);
pci_set_command(dev);
result = v4l2_device_register(&dev->dev, &btv->c.v4l2_dev);
if (result < 0) {
pr_warn("%d: v4l2_device_register() failed\n", btv->c.nr);
goto fail0;
}
hdl = &btv->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 20);
btv->c.v4l2_dev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(&btv->radio_ctrl_handler, 6);
btv->revision = dev->revision;
pci_read_config_byte(dev, PCI_LATENCY_TIMER, &lat);
pr_info("%d: Bt%d (rev %d) at %s, irq: %d, latency: %d, mmio: 0x%llx\n",
bttv_num, btv->id, btv->revision, pci_name(dev),
btv->c.pci->irq, lat,
(unsigned long long)pci_resource_start(dev, 0));
schedule();
btv->bt848_mmio = ioremap(pci_resource_start(dev, 0), 0x1000);
if (NULL == btv->bt848_mmio) {
pr_err("%d: ioremap() failed\n", btv->c.nr);
result = -EIO;
goto fail1;
}
bttv_idcard(btv);
btwrite(0, BT848_INT_MASK);
result = request_irq(btv->c.pci->irq, bttv_irq,
IRQF_SHARED, btv->c.v4l2_dev.name, (void *)btv);
if (result < 0) {
pr_err("%d: can't get IRQ %d\n",
bttv_num, btv->c.pci->irq);
goto fail1;
}
if (0 != bttv_handle_chipset(btv)) {
result = -EIO;
goto fail2;
}
btv->opt_combfilter = combfilter;
bttv_ctrl_combfilter.def = combfilter;
bttv_ctrl_lumafilter.def = lumafilter;
btv->opt_automute = automute;
bttv_ctrl_automute.def = automute;
bttv_ctrl_agc_crush.def = agc_crush;
btv->opt_vcr_hack = vcr_hack;
bttv_ctrl_vcr_hack.def = vcr_hack;
bttv_ctrl_whitecrush_upper.def = whitecrush_upper;
bttv_ctrl_whitecrush_lower.def = whitecrush_lower;
btv->opt_uv_ratio = uv_ratio;
bttv_ctrl_uv_ratio.def = uv_ratio;
bttv_ctrl_full_luma.def = full_luma_range;
bttv_ctrl_coring.def = coring;
btv->init.btv = btv;
btv->init.ov.w.width = 320;
btv->init.ov.w.height = 240;
btv->init.fmt = format_by_fourcc(V4L2_PIX_FMT_BGR24);
btv->init.width = 320;
btv->init.height = 240;
btv->init.ov.w.width = 320;
btv->init.ov.w.height = 240;
btv->init.ov.field = V4L2_FIELD_INTERLACED;
btv->input = 0;
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 0xff00, 0x100, 32768);
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_CONTRAST, 0, 0xff80, 0x80, 0x6c00);
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_SATURATION, 0, 0xff80, 0x80, 32768);
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_COLOR_KILLER, 0, 1, 1, 0);
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_HUE, 0, 0xff00, 0x100, 32768);
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_CHROMA_AGC, 0, 1, 1, !!chroma_agc);
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
if (btv->volume_gpio)
v4l2_ctrl_new_std(hdl, &bttv_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 0xff00, 0x100, 0xff00);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_combfilter, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_automute, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_lumafilter, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_agc_crush, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_vcr_hack, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_whitecrush_lower, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_whitecrush_upper, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_uv_ratio, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_full_luma, NULL);
v4l2_ctrl_new_custom(hdl, &bttv_ctrl_coring, NULL);
if (bttv_gpio)
bttv_gpio_tracking(btv,"pre-init");
bttv_risc_init_main(btv);
init_bt848(btv);
btwrite(0x00, BT848_GPIO_REG_INP);
btwrite(0x00, BT848_GPIO_OUT_EN);
if (bttv_verbose)
bttv_gpio_tracking(btv,"init");
bttv_init_card1(btv);
init_bttv_i2c(btv);
bttv_init_card2(btv);
bttv_init_tuner(btv);
if (btv->tuner_type != TUNER_ABSENT) {
bttv_set_frequency(btv, &init_freq);
btv->radio_freq = 90500 * 16;
}
btv->std = V4L2_STD_PAL;
init_irqreg(btv);
if (!bttv_tvcards[btv->c.type].no_video)
v4l2_ctrl_handler_setup(hdl);
if (hdl->error) {
result = hdl->error;
goto fail2;
}
audio_mute(btv, 1);
if (!bttv_tvcards[btv->c.type].no_video) {
v4l2_ctrl_add_handler(&btv->radio_ctrl_handler, hdl,
v4l2_ctrl_radio_filter);
if (btv->radio_ctrl_handler.error) {
result = btv->radio_ctrl_handler.error;
goto fail2;
}
set_input(btv, 0, btv->tvnorm);
bttv_crop_reset(&btv->crop[0], btv->tvnorm);
btv->crop[1] = btv->crop[0];
disclaim_vbi_lines(btv);
disclaim_video_lines(btv);
bttv_register_video(btv);
}
if (bttv_tvcards[btv->c.type].has_dvb) {
bttv_sub_add_device(&btv->c, "dvb");
request_modules(btv);
}
if (!disable_ir) {
init_bttv_i2c_ir(btv);
bttv_input_init(btv);
}
bttv_num++;
return 0;
fail2:
free_irq(btv->c.pci->irq,btv);
fail1:
v4l2_ctrl_handler_free(&btv->ctrl_handler);
v4l2_ctrl_handler_free(&btv->radio_ctrl_handler);
v4l2_device_unregister(&btv->c.v4l2_dev);
fail0:
if (btv->bt848_mmio)
iounmap(btv->bt848_mmio);
release_mem_region(pci_resource_start(btv->c.pci,0),
pci_resource_len(btv->c.pci,0));
pci_disable_device(btv->c.pci);
return result;
}
static void bttv_remove(struct pci_dev *pci_dev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct bttv *btv = to_bttv(v4l2_dev);
if (bttv_verbose)
pr_info("%d: unloading\n", btv->c.nr);
if (bttv_tvcards[btv->c.type].has_dvb)
flush_request_modules(btv);
btand(~15, BT848_GPIO_DMA_CTL);
btwrite(0, BT848_INT_MASK);
btwrite(~0x0, BT848_INT_STAT);
btwrite(0x0, BT848_GPIO_OUT_EN);
if (bttv_gpio)
bttv_gpio_tracking(btv,"cleanup");
btv->shutdown=1;
bttv_input_fini(btv);
bttv_sub_del_devices(&btv->c);
fini_bttv_i2c(btv);
bttv_unregister_video(btv);
v4l2_ctrl_handler_free(&btv->ctrl_handler);
v4l2_ctrl_handler_free(&btv->radio_ctrl_handler);
btcx_riscmem_free(btv->c.pci,&btv->main);
free_irq(btv->c.pci->irq,btv);
iounmap(btv->bt848_mmio);
release_mem_region(pci_resource_start(btv->c.pci,0),
pci_resource_len(btv->c.pci,0));
pci_disable_device(btv->c.pci);
v4l2_device_unregister(&btv->c.v4l2_dev);
bttvs[btv->c.nr] = NULL;
kfree(btv);
return;
}
static int bttv_suspend(struct pci_dev *pci_dev, pm_message_t state)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct bttv *btv = to_bttv(v4l2_dev);
struct bttv_buffer_set idle;
unsigned long flags;
dprintk("%d: suspend %d\n", btv->c.nr, state.event);
spin_lock_irqsave(&btv->s_lock,flags);
memset(&idle, 0, sizeof(idle));
btv->state.video = btv->curr;
btv->state.vbi = btv->cvbi;
btv->state.loop_irq = btv->loop_irq;
btv->curr = idle;
btv->loop_irq = 0;
bttv_buffer_activate_video(btv, &idle);
bttv_buffer_activate_vbi(btv, NULL);
bttv_set_dma(btv, 0);
btwrite(0, BT848_INT_MASK);
spin_unlock_irqrestore(&btv->s_lock,flags);
btv->state.gpio_enable = btread(BT848_GPIO_OUT_EN);
btv->state.gpio_data = gpio_read();
pci_save_state(pci_dev);
if (0 != pci_set_power_state(pci_dev, pci_choose_state(pci_dev, state))) {
pci_disable_device(pci_dev);
btv->state.disabled = 1;
}
return 0;
}
static int bttv_resume(struct pci_dev *pci_dev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct bttv *btv = to_bttv(v4l2_dev);
unsigned long flags;
int err;
dprintk("%d: resume\n", btv->c.nr);
if (btv->state.disabled) {
err=pci_enable_device(pci_dev);
if (err) {
pr_warn("%d: Can't enable device\n", btv->c.nr);
return err;
}
btv->state.disabled = 0;
}
err=pci_set_power_state(pci_dev, PCI_D0);
if (err) {
pci_disable_device(pci_dev);
pr_warn("%d: Can't enable device\n", btv->c.nr);
btv->state.disabled = 1;
return err;
}
pci_restore_state(pci_dev);
bttv_reinit_bt848(btv);
gpio_inout(0xffffff, btv->state.gpio_enable);
gpio_write(btv->state.gpio_data);
spin_lock_irqsave(&btv->s_lock,flags);
btv->curr = btv->state.video;
btv->cvbi = btv->state.vbi;
btv->loop_irq = btv->state.loop_irq;
bttv_buffer_activate_video(btv, &btv->curr);
bttv_buffer_activate_vbi(btv, btv->cvbi);
bttv_set_dma(btv, 0);
spin_unlock_irqrestore(&btv->s_lock,flags);
return 0;
}
static int __init bttv_init_module(void)
{
int ret;
bttv_num = 0;
pr_info("driver version %s loaded\n", BTTV_VERSION);
if (gbuffers < 2 || gbuffers > VIDEO_MAX_FRAME)
gbuffers = 2;
if (gbufsize > BTTV_MAX_FBUF)
gbufsize = BTTV_MAX_FBUF;
gbufsize = (gbufsize + PAGE_SIZE - 1) & PAGE_MASK;
if (bttv_verbose)
pr_info("using %d buffers with %dk (%d pages) each for capture\n",
gbuffers, gbufsize >> 10, gbufsize >> PAGE_SHIFT);
bttv_check_chipset();
ret = bus_register(&bttv_sub_bus_type);
if (ret < 0) {
pr_warn("bus_register error: %d\n", ret);
return ret;
}
ret = pci_register_driver(&bttv_pci_driver);
if (ret < 0)
bus_unregister(&bttv_sub_bus_type);
return ret;
}
static void __exit bttv_cleanup_module(void)
{
pci_unregister_driver(&bttv_pci_driver);
bus_unregister(&bttv_sub_bus_type);
}
