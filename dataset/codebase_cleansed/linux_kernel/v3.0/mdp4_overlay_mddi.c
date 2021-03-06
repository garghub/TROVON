void mdp4_overlay_update_lcd(struct msm_fb_data_type *mfd)
{
MDPIBUF *iBuf = &mfd->ibuf;
uint8 *src;
int bpp, ptype;
uint32 format;
uint32 mddi_ld_param;
uint16 mddi_vdo_packet_reg;
struct mdp4_overlay_pipe *pipe;
if (mfd->key != MFD_KEY)
return;
mddi_mfd = mfd;
bpp = iBuf->bpp;
if (bpp == 2)
format = MDP_RGB_565;
else if (bpp == 3)
format = MDP_RGB_888;
else
format = MDP_ARGB_8888;
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
if (mddi_pipe == NULL) {
ptype = mdp4_overlay_format2type(format);
pipe = mdp4_overlay_pipe_alloc();
pipe->pipe_type = ptype;
pipe->pipe_num = OVERLAY_PIPE_RGB1;
pipe->mixer_num = MDP4_MIXER0;
pipe->src_format = format;
mdp4_overlay_format2pipe(pipe);
mddi_pipe = pipe;
mddi_ld_param = 0;
mddi_vdo_packet_reg = mfd->panel_info.mddi.vdopkt;
if (mfd->panel_info.type == MDDI_PANEL) {
if (mfd->panel_info.pdest == DISPLAY_1)
mddi_ld_param = 0;
else
mddi_ld_param = 1;
} else {
mddi_ld_param = 2;
}
MDP_OUTP(MDP_BASE + 0x00090, mddi_ld_param);
MDP_OUTP(MDP_BASE + 0x00094,
(MDDI_VDO_PACKET_DESC << 16) | mddi_vdo_packet_reg);
} else {
pipe = mddi_pipe;
}
src = (uint8 *) iBuf->buf;
#ifdef WHOLESCREEN
{
struct fb_info *fbi;
fbi = mfd->fbi;
pipe->src_height = fbi->var.yres;
pipe->src_width = fbi->var.xres;
pipe->src_h = fbi->var.yres;
pipe->src_w = fbi->var.xres;
pipe->src_y = 0;
pipe->src_x = 0;
pipe->dst_h = fbi->var.yres;
pipe->dst_w = fbi->var.xres;
pipe->dst_y = 0;
pipe->dst_x = 0;
pipe->srcp0_addr = (uint32)src;
pipe->srcp0_ystride = fbi->var.xres_virtual * bpp;
}
#else
if (mdp4_overlay_active(MDP4_MIXER0)) {
struct fb_info *fbi;
fbi = mfd->fbi;
pipe->src_height = fbi->var.yres;
pipe->src_width = fbi->var.xres;
pipe->src_h = fbi->var.yres;
pipe->src_w = fbi->var.xres;
pipe->src_y = 0;
pipe->src_x = 0;
pipe->dst_h = fbi->var.yres;
pipe->dst_w = fbi->var.xres;
pipe->dst_y = 0;
pipe->dst_x = 0;
pipe->srcp0_addr = (uint32) src;
pipe->srcp0_ystride = fbi->var.xres_virtual * bpp;
} else {
src += (iBuf->dma_x + iBuf->dma_y * iBuf->ibuf_width) * bpp;
pipe->src_height = iBuf->dma_h;
pipe->src_width = iBuf->dma_w;
pipe->src_h = iBuf->dma_h;
pipe->src_w = iBuf->dma_w;
pipe->src_y = 0;
pipe->src_x = 0;
pipe->dst_h = iBuf->dma_h;
pipe->dst_w = iBuf->dma_w;
pipe->dst_y = iBuf->dma_y;
pipe->dst_x = iBuf->dma_x;
pipe->srcp0_addr = (uint32) src;
pipe->srcp0_ystride = iBuf->ibuf_width * bpp;
}
#endif
pipe->mixer_stage = MDP4_MIXER_STAGE_BASE;
mdp4_overlay_rgb_setup(pipe);
mdp4_mixer_stage_up(pipe);
mdp4_overlayproc_cfg(pipe);
mdp4_overlay_dmap_xy(pipe);
mdp4_overlay_dmap_cfg(mfd, 0);
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
}
void mdp4_overlay0_done_mddi()
{
if (pending_pipe)
complete(&pending_pipe->comp);
}
void mdp4_mddi_overlay_restore(void)
{
mdp4_overlay_update_lcd(mddi_mfd);
mdp4_mddi_overlay_kickoff(mddi_mfd, mddi_pipe);
}
void mdp4_mddi_overlay_kickoff(struct msm_fb_data_type *mfd,
struct mdp4_overlay_pipe *pipe)
{
#ifdef MDP4_NONBLOCKING
unsigned long flag;
spin_lock_irqsave(&mdp_spin_lock, flag);
if (mfd->dma->busy == TRUE) {
INIT_COMPLETION(pipe->comp);
pending_pipe = pipe;
}
spin_unlock_irqrestore(&mdp_spin_lock, flag);
if (pending_pipe != NULL) {
wait_for_completion_killable(&pipe->comp);
pending_pipe = NULL;
}
down(&mfd->sem);
mdp_enable_irq(MDP_OVERLAY0_TERM);
mfd->dma->busy = TRUE;
mdp_pipe_kickoff(MDP_OVERLAY0_TERM, mfd);
up(&mfd->sem);
#else
down(&mfd->sem);
mdp_enable_irq(MDP_OVERLAY0_TERM);
mfd->dma->busy = TRUE;
INIT_COMPLETION(pipe->comp);
pending_pipe = pipe;
mdp_pipe_kickoff(MDP_OVERLAY0_TERM, mfd);
up(&mfd->sem);
wait_for_completion_killable(&pipe->comp);
mdp_disable_irq(MDP_OVERLAY0_TERM);
#endif
}
void mdp4_mddi_overlay(struct msm_fb_data_type *mfd)
{
mutex_lock(&mfd->dma->ov_mutex);
if ((mfd) && (!mfd->dma->busy) && (mfd->panel_power_on)) {
mdp4_overlay_update_lcd(mfd);
mdp4_mddi_overlay_kickoff(mfd, mddi_pipe);
if (mfd->pan_waiting) {
mfd->pan_waiting = FALSE;
complete(&mfd->pan_comp);
}
}
mutex_unlock(&mfd->dma->ov_mutex);
}
