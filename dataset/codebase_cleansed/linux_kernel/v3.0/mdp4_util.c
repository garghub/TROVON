void mdp4_sw_reset(ulong bits)
{
bits &= 0x1f;
outpdw(MDP_BASE + 0x001c, bits);
while (inpdw(MDP_BASE + 0x001c) & bits)
;
MSM_FB_INFO("mdp4_sw_reset: 0x%x\n", (int)bits);
}
void mdp4_overlay_cfg(int overlayer, int blt_mode, int refresh, int direct_out)
{
ulong bits = 0;
if (blt_mode)
bits |= (1 << 3);
refresh &= 0x03;
bits |= (refresh << 1);
direct_out &= 0x01;
bits |= direct_out;
if (overlayer == MDP4_MIXER0)
outpdw(MDP_BASE + 0x10004, bits);
else
outpdw(MDP_BASE + 0x18004, bits);
MSM_FB_INFO("mdp4_overlay_cfg: 0x%x\n", (int)inpdw(MDP_BASE + 0x10004));
}
void mdp4_display_intf_sel(int output, ulong intf)
{
ulong bits, mask;
bits = inpdw(MDP_BASE + 0x0038);
mask = 0x03;
intf &= 0x03;
switch (output) {
case EXTERNAL_INTF_SEL:
intf <<= 4;
mask <<= 4;
break;
case SECONDARY_INTF_SEL:
intf &= 0x02;
intf <<= 2;
mask <<= 2;
break;
default:
break;
}
bits &= ~mask;
bits |= intf;
outpdw(MDP_BASE + 0x0038, bits);
MSM_FB_INFO("mdp4_display_intf_sel: 0x%x\n", (int)inpdw(MDP_BASE + 0x0038));
}
unsigned long mdp4_display_status(void)
{
return inpdw(MDP_BASE + 0x0018) & 0x3ff;
}
void mdp4_ebi2_lcd_setup(int lcd, ulong base, int ystride)
{
ystride &= 0x01fff;
if (lcd == EBI2_LCD0) {
outpdw(MDP_BASE + 0x0060, base);
outpdw(MDP_BASE + 0x0068, ystride);
} else {
outpdw(MDP_BASE + 0x0064, base);
outpdw(MDP_BASE + 0x006c, ystride);
}
}
void mdp4_mddi_setup(int mddi, unsigned long id)
{
ulong bits;
if (mddi == MDDI_EXTERNAL_SET)
bits = 0x02;
else if (mddi == MDDI_SECONDARY_SET)
bits = 0x01;
else
bits = 0;
id <<= 16;
bits |= id;
outpdw(MDP_BASE + 0x0090, bits);
}
int mdp_ppp_blit(struct fb_info *info, struct mdp_blit_req *req,
struct file **pp_src_file, struct file **pp_dst_file)
{
return -1;
}
void mdp4_hw_init(void)
{
ulong bits;
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
#ifdef MDP4_ERROR
mdp4_sw_reset(0x17);
#endif
mdp4_clear_lcdc();
mdp4_mixer_blend_init(0);
mdp4_mixer_blend_init(1);
mdp4_vg_qseed_init(0);
mdp4_vg_qseed_init(1);
mdp4_vg_csc_mv_setup(0);
mdp4_vg_csc_mv_setup(1);
mdp4_vg_csc_pre_bv_setup(0);
mdp4_vg_csc_pre_bv_setup(1);
mdp4_vg_csc_post_bv_setup(0);
mdp4_vg_csc_post_bv_setup(1);
mdp4_vg_csc_pre_lv_setup(0);
mdp4_vg_csc_pre_lv_setup(1);
mdp4_vg_csc_post_lv_setup(0);
mdp4_vg_csc_post_lv_setup(1);
mdp4_mixer_gc_lut_setup(0);
mdp4_mixer_gc_lut_setup(1);
mdp4_vg_igc_lut_setup(0);
mdp4_vg_igc_lut_setup(1);
mdp4_rgb_igc_lut_setup(0);
mdp4_rgb_igc_lut_setup(1);
outp32(MDP_EBI2_PORTMAP_MODE, 0x3);
bits = mdp_intr_mask;
outpdw(MDP_BASE + 0x0050, bits);
MDP_OUTP(MDP_BASE + 0x95010, 1);
outpdw(MDP_BASE + 0x9501c, INTR_HIST_DONE);
outpdw(MDP_BASE + 0x004c, 0x02222);
outpdw(MDP_BASE + 0x91004, 0x27);
#ifndef CONFIG_FB_MSM_OVERLAY
mdp4_overlay_cfg(MDP4_MIXER0, OVERLAY_MODE_BLT, 0, 0);
mdp4_overlay_cfg(MDP4_MIXER1, OVERLAY_MODE_BLT, 0, 0);
#endif
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
}
void mdp4_clear_lcdc(void)
{
uint32 bits;
bits = inpdw(MDP_BASE + 0xc0000);
if (bits & 0x01)
return;
outpdw(MDP_BASE + 0xc0004, 0);
outpdw(MDP_BASE + 0xc0008, 0);
outpdw(MDP_BASE + 0xc000c, 0);
outpdw(MDP_BASE + 0xc0010, 0);
outpdw(MDP_BASE + 0xc0014, 0);
outpdw(MDP_BASE + 0xc0018, 0);
outpdw(MDP_BASE + 0xc001c, 0);
outpdw(MDP_BASE + 0xc0020, 0);
outpdw(MDP_BASE + 0xc0024, 0);
outpdw(MDP_BASE + 0xc0028, 0);
outpdw(MDP_BASE + 0xc002c, 0);
outpdw(MDP_BASE + 0xc0030, 0);
outpdw(MDP_BASE + 0xc0034, 0);
outpdw(MDP_BASE + 0xc0038, 0);
}
irqreturn_t mdp4_isr(int irq, void *ptr)
{
uint32 isr, mask, lcdc;
struct mdp_dma_data *dma;
mdp_is_in_isr = TRUE;
while (1) {
isr = inpdw(MDP_INTR_STATUS);
if (isr == 0)
break;
mask = inpdw(MDP_INTR_ENABLE);
outpdw(MDP_INTR_CLEAR, isr);
isr &= mask;
if (unlikely(isr == 0))
break;
if (isr & INTR_DMA_P_DONE) {
intr_dma_p++;
lcdc = inpdw(MDP_BASE + 0xc0000);
dma = &dma2_data;
if (lcdc & 0x01) {
mdp_intr_mask &= ~INTR_DMA_P_DONE;
outp32(MDP_INTR_ENABLE, mdp_intr_mask);
dma->waiting = FALSE;
} else {
dma->busy = FALSE;
mdp_pipe_ctrl(MDP_DMA2_BLOCK,
MDP_BLOCK_POWER_OFF, TRUE);
}
complete(&dma->comp);
}
if (isr & INTR_DMA_S_DONE) {
intr_dma_s++;
dma = &dma_s_data;
dma->busy = FALSE;
mdp_pipe_ctrl(MDP_DMA_S_BLOCK,
MDP_BLOCK_POWER_OFF, TRUE);
complete(&dma->comp);
}
if (isr & INTR_DMA_E_DONE) {
intr_dma_e++;
dma = &dma_e_data;
mdp_intr_mask &= ~INTR_DMA_E_DONE;
outp32(MDP_INTR_ENABLE, mdp_intr_mask);
dma->busy = FALSE;
if (dma->waiting) {
dma->waiting = FALSE;
complete(&dma->comp);
}
}
if (isr & INTR_OVERLAY0_DONE) {
intr_overlay0++;
lcdc = inpdw(MDP_BASE + 0xc0000);
dma = &dma2_data;
if (lcdc & 0x01) {
mdp_intr_mask &= ~INTR_OVERLAY0_DONE;
outp32(MDP_INTR_ENABLE, mdp_intr_mask);
dma->waiting = FALSE;
mdp4_overlay0_done_lcdc();
} else {
dma->busy = FALSE;
#ifdef MDP4_NONBLOCKING
mdp_disable_irq_nolock(MDP_OVERLAY0_TERM);
#endif
mdp_pipe_ctrl(MDP_OVERLAY0_BLOCK,
MDP_BLOCK_POWER_OFF, TRUE);
mdp4_overlay0_done_mddi();
}
}
if (isr & INTR_OVERLAY1_DONE) {
intr_overlay1++;
dma = &overlay1_data;
dma->busy = FALSE;
mdp_pipe_ctrl(MDP_OVERLAY1_BLOCK,
MDP_BLOCK_POWER_OFF, TRUE);
complete(&dma->comp);
}
if (isr & INTR_DMA_P_HISTOGRAM) {
isr = inpdw(MDP_DMA_P_HIST_INTR_STATUS);
mask = inpdw(MDP_DMA_P_HIST_INTR_ENABLE);
outpdw(MDP_DMA_P_HIST_INTR_CLEAR, isr);
isr &= mask;
if (isr & INTR_HIST_DONE) {
if (mdp_hist.r)
memcpy(mdp_hist.r, MDP_BASE + 0x95100,
mdp_hist.bin_cnt*4);
if (mdp_hist.g)
memcpy(mdp_hist.g, MDP_BASE + 0x95200,
mdp_hist.bin_cnt*4);
if (mdp_hist.b)
memcpy(mdp_hist.b, MDP_BASE + 0x95300,
mdp_hist.bin_cnt*4);
complete(&mdp_hist_comp);
}
}
}
mdp_is_in_isr = FALSE;
return IRQ_HANDLED;
}
void mdp4_vg_qseed_init(int vp_num)
{
uint32 *off;
int i, voff;
voff = MDP4_VIDEO_OFF * vp_num;
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_QSEED_TABLE0_OFF);
for (i = 0; i < (sizeof(vg_qseed_table0) / sizeof(uint32)); i++) {
outpdw(off, vg_qseed_table0[i]);
off++;
}
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_QSEED_TABLE1_OFF);
for (i = 0; i < (sizeof(vg_qseed_table1) / sizeof(uint32)); i++) {
outpdw(off, vg_qseed_table1[i]);
off++;
}
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_QSEED_TABLE2_OFF);
for (i = 0; i < (sizeof(vg_qseed_table2) / sizeof(uint32)); i++) {
outpdw(off, vg_qseed_table2[i]);
off++;
}
}
void mdp4_mixer_blend_init(mixer_num)
{
unsigned char *overlay_base;
int off;
if (mixer_num)
overlay_base = MDP_BASE + MDP4_OVERLAYPROC1_BASE;
else
overlay_base = MDP_BASE + MDP4_OVERLAYPROC0_BASE;
off = 0;
outpdw(overlay_base + off + 0x104, 0x010);
outpdw(overlay_base + off + 0x108, 0xff);
outpdw(overlay_base + off + 0x10c, 0x00);
off += 0x20;
outpdw(overlay_base + off + 0x104, 0x010);
outpdw(overlay_base + off + 0x108, 0xff);
outpdw(overlay_base + off + 0x10c, 0x00);
off += 0x20;
outpdw(overlay_base + off + 0x104, 0x010);
outpdw(overlay_base + off + 0x108, 0xff);
outpdw(overlay_base + off + 0x10c, 0x00);
}
void mdp4_vg_csc_mv_setup(int vp_num)
{
uint32 *off;
int i, voff;
voff = MDP4_VIDEO_OFF * vp_num;
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_CSC_MV_OFF);
for (i = 0; i < 9; i++) {
outpdw(off, csc_matrix_tab[i]);
off++;
}
}
void mdp4_vg_csc_pre_bv_setup(int vp_num)
{
uint32 *off;
int i, voff;
voff = MDP4_VIDEO_OFF * vp_num;
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_CSC_PRE_BV_OFF);
for (i = 0; i < 3; i++) {
outpdw(off, csc_pre_bv_tab[i]);
off++;
}
}
void mdp4_vg_csc_post_bv_setup(int vp_num)
{
uint32 *off;
int i, voff;
voff = MDP4_VIDEO_OFF * vp_num;
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_CSC_POST_BV_OFF);
for (i = 0; i < 3; i++) {
outpdw(off, csc_post_bv_tab[i]);
off++;
}
}
void mdp4_vg_csc_pre_lv_setup(int vp_num)
{
uint32 *off;
int i, voff;
voff = MDP4_VIDEO_OFF * vp_num;
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_CSC_PRE_LV_OFF);
for (i = 0; i < 6; i++) {
outpdw(off, csc_pre_lv_tab[i]);
off++;
}
}
void mdp4_vg_csc_post_lv_setup(int vp_num)
{
uint32 *off;
int i, voff;
voff = MDP4_VIDEO_OFF * vp_num;
off = (uint32 *)(MDP_BASE + MDP4_VIDEO_BASE + voff +
MDP4_CSC_POST_LV_OFF);
for (i = 0; i < 6; i++) {
outpdw(off, csc_post_lv_tab[i]);
off++;
}
}
void mdp4_mixer_gc_lut_setup(int mixer_num)
{
unsigned char *base;
uint32 data;
char val;
int i, off;
if (mixer_num)
base = MDP_BASE + MDP4_OVERLAYPROC1_BASE;
else
base = MDP_BASE + MDP4_OVERLAYPROC0_BASE;
base += 0x4000;
off = 0;
for (i = 0; i < 4096; i++) {
val = gc_lut[i];
data = (val << 16 | val << 8 | val);
outpdw(base + off, data);
off += 4;
}
}
void mdp4_vg_igc_lut_setup(int vp_num)
{
unsigned char *base;
int i, voff, off;
uint32 data, val;
voff = MDP4_VIDEO_OFF * vp_num;
base = MDP_BASE + MDP4_VIDEO_BASE + voff + 0x5000;
off = 0;
for (i = 0; i < 256; i++) {
val = igc_video_lut[i];
data = (val << 16 | val);
outpdw(base + off, data);
outpdw(base + off + 0x800, val);
off += 4;
}
}
void mdp4_rgb_igc_lut_setup(int num)
{
unsigned char *base;
int i, voff, off;
uint32 data, val;
voff = MDP4_RGB_OFF * num;
base = MDP_BASE + MDP4_RGB_BASE + voff + 0x5000;
off = 0;
for (i = 0; i < 256; i++) {
val = igc_rgb_lut[i];
data = (val << 16 | val);
outpdw(base + off, data);
outpdw(base + off + 0x800, val);
off += 4;
}
}
