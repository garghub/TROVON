static void mdp_dma_s_update_lcd(struct msm_fb_data_type *mfd)
{
MDPIBUF *iBuf = &mfd->ibuf;
int mddi_dest = FALSE;
uint32 outBpp = iBuf->bpp;
uint32 dma_s_cfg_reg;
uint8 *src;
struct msm_fb_panel_data *pdata =
(struct msm_fb_panel_data *)mfd->pdev->dev.platform_data;
dma_s_cfg_reg = DMA_PACK_TIGHT | DMA_PACK_ALIGN_LSB |
DMA_OUT_SEL_AHB | DMA_IBUF_NONCONTIGUOUS;
if (mfd->fb_imgType == MDP_BGR_565)
dma_s_cfg_reg |= DMA_PACK_PATTERN_BGR;
else
dma_s_cfg_reg |= DMA_PACK_PATTERN_RGB;
if (outBpp == 4)
dma_s_cfg_reg |= DMA_IBUF_C3ALPHA_EN;
if (outBpp == 2)
dma_s_cfg_reg |= DMA_IBUF_FORMAT_RGB565;
if (mfd->panel_info.pdest != DISPLAY_2) {
printk(KERN_ERR "error: non-secondary type through dma_s!\n");
return;
}
if (mfd->panel_info.type == MDDI_PANEL) {
dma_s_cfg_reg |= DMA_OUT_SEL_MDDI;
mddi_dest = TRUE;
} else {
dma_s_cfg_reg |= DMA_AHBM_LCD_SEL_SECONDARY;
outp32(MDP_EBI2_LCD1, mfd->data_port_phys);
}
dma_s_cfg_reg |= DMA_DITHER_EN;
src = (uint8 *) iBuf->buf;
src += (iBuf->dma_x + iBuf->dma_y * iBuf->ibuf_width) * outBpp;
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
MDP_OUTP(MDP_BASE + 0xa0004, (iBuf->dma_h << 16 | iBuf->dma_w));
MDP_OUTP(MDP_BASE + 0xa0008, src);
MDP_OUTP(MDP_BASE + 0xa000c, iBuf->ibuf_width * outBpp);
if (mfd->panel_info.bpp == 18) {
dma_s_cfg_reg |= DMA_DSTC0G_6BITS |
DMA_DSTC1B_6BITS | DMA_DSTC2R_6BITS;
} else {
dma_s_cfg_reg |= DMA_DSTC0G_6BITS |
DMA_DSTC1B_5BITS | DMA_DSTC2R_5BITS;
}
if (mddi_dest) {
MDP_OUTP(MDP_BASE + 0xa0010, (iBuf->dma_y << 16) | iBuf->dma_x);
MDP_OUTP(MDP_BASE + 0x00090, 1);
MDP_OUTP(MDP_BASE + 0x00094,
(MDDI_VDO_PACKET_DESC << 16) |
mfd->panel_info.mddi.vdopkt);
} else {
pdata->set_rect(iBuf->dma_x, iBuf->dma_y, iBuf->dma_w,
iBuf->dma_h);
}
MDP_OUTP(MDP_BASE + 0xa0000, dma_s_cfg_reg);
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, FALSE);
mdp_pipe_kickoff(MDP_DMA_S_TERM, mfd);
}
void mdp_dma_s_update(struct msm_fb_data_type *mfd)
{
down(&mfd->dma->mutex);
if ((mfd) && (!mfd->dma->busy) && (mfd->panel_power_on)) {
down(&mfd->sem);
mdp_enable_irq(MDP_DMA_S_TERM);
mfd->dma->busy = TRUE;
INIT_COMPLETION(mfd->dma->comp);
mfd->ibuf_flushed = TRUE;
mdp_dma_s_update_lcd(mfd);
up(&mfd->sem);
wait_for_completion_killable(&mfd->dma->comp);
mdp_disable_irq(MDP_DMA_S_TERM);
if (mfd->pan_waiting) {
mfd->pan_waiting = FALSE;
complete(&mfd->pan_comp);
}
}
up(&mfd->dma->mutex);
}
