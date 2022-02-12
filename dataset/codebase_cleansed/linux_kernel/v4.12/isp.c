void omap3isp_flush(struct isp_device *isp)
{
isp_reg_writel(isp, 0, OMAP3_ISP_IOMEM_MAIN, ISP_REVISION);
isp_reg_readl(isp, OMAP3_ISP_IOMEM_MAIN, ISP_REVISION);
}
static void isp_xclk_update(struct isp_xclk *xclk, u32 divider)
{
switch (xclk->id) {
case ISP_XCLK_A:
isp_reg_clr_set(xclk->isp, OMAP3_ISP_IOMEM_MAIN, ISP_TCTRL_CTRL,
ISPTCTRL_CTRL_DIVA_MASK,
divider << ISPTCTRL_CTRL_DIVA_SHIFT);
break;
case ISP_XCLK_B:
isp_reg_clr_set(xclk->isp, OMAP3_ISP_IOMEM_MAIN, ISP_TCTRL_CTRL,
ISPTCTRL_CTRL_DIVB_MASK,
divider << ISPTCTRL_CTRL_DIVB_SHIFT);
break;
}
}
static int isp_xclk_prepare(struct clk_hw *hw)
{
struct isp_xclk *xclk = to_isp_xclk(hw);
omap3isp_get(xclk->isp);
return 0;
}
static void isp_xclk_unprepare(struct clk_hw *hw)
{
struct isp_xclk *xclk = to_isp_xclk(hw);
omap3isp_put(xclk->isp);
}
static int isp_xclk_enable(struct clk_hw *hw)
{
struct isp_xclk *xclk = to_isp_xclk(hw);
unsigned long flags;
spin_lock_irqsave(&xclk->lock, flags);
isp_xclk_update(xclk, xclk->divider);
xclk->enabled = true;
spin_unlock_irqrestore(&xclk->lock, flags);
return 0;
}
static void isp_xclk_disable(struct clk_hw *hw)
{
struct isp_xclk *xclk = to_isp_xclk(hw);
unsigned long flags;
spin_lock_irqsave(&xclk->lock, flags);
isp_xclk_update(xclk, 0);
xclk->enabled = false;
spin_unlock_irqrestore(&xclk->lock, flags);
}
static unsigned long isp_xclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct isp_xclk *xclk = to_isp_xclk(hw);
return parent_rate / xclk->divider;
}
static u32 isp_xclk_calc_divider(unsigned long *rate, unsigned long parent_rate)
{
u32 divider;
if (*rate >= parent_rate) {
*rate = parent_rate;
return ISPTCTRL_CTRL_DIV_BYPASS;
}
if (*rate == 0)
*rate = 1;
divider = DIV_ROUND_CLOSEST(parent_rate, *rate);
if (divider >= ISPTCTRL_CTRL_DIV_BYPASS)
divider = ISPTCTRL_CTRL_DIV_BYPASS - 1;
*rate = parent_rate / divider;
return divider;
}
static long isp_xclk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
isp_xclk_calc_divider(&rate, *parent_rate);
return rate;
}
static int isp_xclk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct isp_xclk *xclk = to_isp_xclk(hw);
unsigned long flags;
u32 divider;
divider = isp_xclk_calc_divider(&rate, parent_rate);
spin_lock_irqsave(&xclk->lock, flags);
xclk->divider = divider;
if (xclk->enabled)
isp_xclk_update(xclk, divider);
spin_unlock_irqrestore(&xclk->lock, flags);
dev_dbg(xclk->isp->dev, "%s: cam_xclk%c set to %lu Hz (div %u)\n",
__func__, xclk->id == ISP_XCLK_A ? 'a' : 'b', rate, divider);
return 0;
}
static struct clk *isp_xclk_src_get(struct of_phandle_args *clkspec, void *data)
{
unsigned int idx = clkspec->args[0];
struct isp_device *isp = data;
if (idx >= ARRAY_SIZE(isp->xclks))
return ERR_PTR(-ENOENT);
return isp->xclks[idx].clk;
}
static int isp_xclk_init(struct isp_device *isp)
{
struct device_node *np = isp->dev->of_node;
struct clk_init_data init;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(isp->xclks); ++i)
isp->xclks[i].clk = ERR_PTR(-EINVAL);
for (i = 0; i < ARRAY_SIZE(isp->xclks); ++i) {
struct isp_xclk *xclk = &isp->xclks[i];
xclk->isp = isp;
xclk->id = i == 0 ? ISP_XCLK_A : ISP_XCLK_B;
xclk->divider = 1;
spin_lock_init(&xclk->lock);
init.name = i == 0 ? "cam_xclka" : "cam_xclkb";
init.ops = &isp_xclk_ops;
init.parent_names = &isp_xclk_parent_name;
init.num_parents = 1;
xclk->hw.init = &init;
xclk->clk = clk_register(NULL, &xclk->hw);
if (IS_ERR(xclk->clk))
return PTR_ERR(xclk->clk);
}
if (np)
of_clk_add_provider(np, isp_xclk_src_get, isp);
return 0;
}
static void isp_xclk_cleanup(struct isp_device *isp)
{
struct device_node *np = isp->dev->of_node;
unsigned int i;
if (np)
of_clk_del_provider(np);
for (i = 0; i < ARRAY_SIZE(isp->xclks); ++i) {
struct isp_xclk *xclk = &isp->xclks[i];
if (!IS_ERR(xclk->clk))
clk_unregister(xclk->clk);
}
}
static void isp_enable_interrupts(struct isp_device *isp)
{
static const u32 irq = IRQ0ENABLE_CSIA_IRQ
| IRQ0ENABLE_CSIB_IRQ
| IRQ0ENABLE_CCDC_LSC_PREF_ERR_IRQ
| IRQ0ENABLE_CCDC_LSC_DONE_IRQ
| IRQ0ENABLE_CCDC_VD0_IRQ
| IRQ0ENABLE_CCDC_VD1_IRQ
| IRQ0ENABLE_HS_VS_IRQ
| IRQ0ENABLE_HIST_DONE_IRQ
| IRQ0ENABLE_H3A_AWB_DONE_IRQ
| IRQ0ENABLE_H3A_AF_DONE_IRQ
| IRQ0ENABLE_PRV_DONE_IRQ
| IRQ0ENABLE_RSZ_DONE_IRQ;
isp_reg_writel(isp, irq, OMAP3_ISP_IOMEM_MAIN, ISP_IRQ0STATUS);
isp_reg_writel(isp, irq, OMAP3_ISP_IOMEM_MAIN, ISP_IRQ0ENABLE);
}
static void isp_disable_interrupts(struct isp_device *isp)
{
isp_reg_writel(isp, 0, OMAP3_ISP_IOMEM_MAIN, ISP_IRQ0ENABLE);
}
static void isp_core_init(struct isp_device *isp, int idle)
{
isp_reg_writel(isp,
((idle ? ISP_SYSCONFIG_MIDLEMODE_SMARTSTANDBY :
ISP_SYSCONFIG_MIDLEMODE_FORCESTANDBY) <<
ISP_SYSCONFIG_MIDLEMODE_SHIFT) |
((isp->revision == ISP_REVISION_15_0) ?
ISP_SYSCONFIG_AUTOIDLE : 0),
OMAP3_ISP_IOMEM_MAIN, ISP_SYSCONFIG);
isp_reg_writel(isp,
(isp->autoidle ? ISPCTRL_SBL_AUTOIDLE : 0) |
ISPCTRL_SYNC_DETECT_VSRISE,
OMAP3_ISP_IOMEM_MAIN, ISP_CTRL);
}
void omap3isp_configure_bridge(struct isp_device *isp,
enum ccdc_input_entity input,
const struct isp_parallel_cfg *parcfg,
unsigned int shift, unsigned int bridge)
{
u32 ispctrl_val;
ispctrl_val = isp_reg_readl(isp, OMAP3_ISP_IOMEM_MAIN, ISP_CTRL);
ispctrl_val &= ~ISPCTRL_SHIFT_MASK;
ispctrl_val &= ~ISPCTRL_PAR_CLK_POL_INV;
ispctrl_val &= ~ISPCTRL_PAR_SER_CLK_SEL_MASK;
ispctrl_val &= ~ISPCTRL_PAR_BRIDGE_MASK;
ispctrl_val |= bridge;
switch (input) {
case CCDC_INPUT_PARALLEL:
ispctrl_val |= ISPCTRL_PAR_SER_CLK_SEL_PARALLEL;
ispctrl_val |= parcfg->clk_pol << ISPCTRL_PAR_CLK_POL_SHIFT;
shift += parcfg->data_lane_shift;
break;
case CCDC_INPUT_CSI2A:
ispctrl_val |= ISPCTRL_PAR_SER_CLK_SEL_CSIA;
break;
case CCDC_INPUT_CCP2B:
ispctrl_val |= ISPCTRL_PAR_SER_CLK_SEL_CSIB;
break;
case CCDC_INPUT_CSI2C:
ispctrl_val |= ISPCTRL_PAR_SER_CLK_SEL_CSIC;
break;
default:
return;
}
ispctrl_val |= ((shift/2) << ISPCTRL_SHIFT_SHIFT) & ISPCTRL_SHIFT_MASK;
isp_reg_writel(isp, ispctrl_val, OMAP3_ISP_IOMEM_MAIN, ISP_CTRL);
}
void omap3isp_hist_dma_done(struct isp_device *isp)
{
if (omap3isp_ccdc_busy(&isp->isp_ccdc) ||
omap3isp_stat_pcr_busy(&isp->isp_hist)) {
atomic_set(&isp->isp_hist.buf_err, 1);
dev_dbg(isp->dev,
"hist: Out of synchronization with CCDC. Ignoring next buffer.\n");
}
}
static inline void isp_isr_dbg(struct isp_device *isp, u32 irqstatus)
{
static const char *name[] = {
"CSIA_IRQ",
"res1",
"res2",
"CSIB_LCM_IRQ",
"CSIB_IRQ",
"res5",
"res6",
"res7",
"CCDC_VD0_IRQ",
"CCDC_VD1_IRQ",
"CCDC_VD2_IRQ",
"CCDC_ERR_IRQ",
"H3A_AF_DONE_IRQ",
"H3A_AWB_DONE_IRQ",
"res14",
"res15",
"HIST_DONE_IRQ",
"CCDC_LSC_DONE",
"CCDC_LSC_PREFETCH_COMPLETED",
"CCDC_LSC_PREFETCH_ERROR",
"PRV_DONE_IRQ",
"CBUFF_IRQ",
"res22",
"res23",
"RSZ_DONE_IRQ",
"OVF_IRQ",
"res26",
"res27",
"MMU_ERR_IRQ",
"OCP_ERR_IRQ",
"SEC_ERR_IRQ",
"HS_VS_IRQ",
};
int i;
dev_dbg(isp->dev, "ISP IRQ: ");
for (i = 0; i < ARRAY_SIZE(name); i++) {
if ((1 << i) & irqstatus)
printk(KERN_CONT "%s ", name[i]);
}
printk(KERN_CONT "\n");
}
static void isp_isr_sbl(struct isp_device *isp)
{
struct device *dev = isp->dev;
struct isp_pipeline *pipe;
u32 sbl_pcr;
sbl_pcr = isp_reg_readl(isp, OMAP3_ISP_IOMEM_SBL, ISPSBL_PCR);
isp_reg_writel(isp, sbl_pcr, OMAP3_ISP_IOMEM_SBL, ISPSBL_PCR);
sbl_pcr &= ~ISPSBL_PCR_CCDCPRV_2_RSZ_OVF;
if (sbl_pcr)
dev_dbg(dev, "SBL overflow (PCR = 0x%08x)\n", sbl_pcr);
if (sbl_pcr & ISPSBL_PCR_CSIB_WBL_OVF) {
pipe = to_isp_pipeline(&isp->isp_ccp2.subdev.entity);
if (pipe != NULL)
pipe->error = true;
}
if (sbl_pcr & ISPSBL_PCR_CSIA_WBL_OVF) {
pipe = to_isp_pipeline(&isp->isp_csi2a.subdev.entity);
if (pipe != NULL)
pipe->error = true;
}
if (sbl_pcr & ISPSBL_PCR_CCDC_WBL_OVF) {
pipe = to_isp_pipeline(&isp->isp_ccdc.subdev.entity);
if (pipe != NULL)
pipe->error = true;
}
if (sbl_pcr & ISPSBL_PCR_PRV_WBL_OVF) {
pipe = to_isp_pipeline(&isp->isp_prev.subdev.entity);
if (pipe != NULL)
pipe->error = true;
}
if (sbl_pcr & (ISPSBL_PCR_RSZ1_WBL_OVF
| ISPSBL_PCR_RSZ2_WBL_OVF
| ISPSBL_PCR_RSZ3_WBL_OVF
| ISPSBL_PCR_RSZ4_WBL_OVF)) {
pipe = to_isp_pipeline(&isp->isp_res.subdev.entity);
if (pipe != NULL)
pipe->error = true;
}
if (sbl_pcr & ISPSBL_PCR_H3A_AF_WBL_OVF)
omap3isp_stat_sbl_overflow(&isp->isp_af);
if (sbl_pcr & ISPSBL_PCR_H3A_AEAWB_WBL_OVF)
omap3isp_stat_sbl_overflow(&isp->isp_aewb);
}
static irqreturn_t isp_isr(int irq, void *_isp)
{
static const u32 ccdc_events = IRQ0STATUS_CCDC_LSC_PREF_ERR_IRQ |
IRQ0STATUS_CCDC_LSC_DONE_IRQ |
IRQ0STATUS_CCDC_VD0_IRQ |
IRQ0STATUS_CCDC_VD1_IRQ |
IRQ0STATUS_HS_VS_IRQ;
struct isp_device *isp = _isp;
u32 irqstatus;
irqstatus = isp_reg_readl(isp, OMAP3_ISP_IOMEM_MAIN, ISP_IRQ0STATUS);
isp_reg_writel(isp, irqstatus, OMAP3_ISP_IOMEM_MAIN, ISP_IRQ0STATUS);
isp_isr_sbl(isp);
if (irqstatus & IRQ0STATUS_CSIA_IRQ)
omap3isp_csi2_isr(&isp->isp_csi2a);
if (irqstatus & IRQ0STATUS_CSIB_IRQ)
omap3isp_ccp2_isr(&isp->isp_ccp2);
if (irqstatus & IRQ0STATUS_CCDC_VD0_IRQ) {
if (isp->isp_ccdc.output & CCDC_OUTPUT_PREVIEW)
omap3isp_preview_isr_frame_sync(&isp->isp_prev);
if (isp->isp_ccdc.output & CCDC_OUTPUT_RESIZER)
omap3isp_resizer_isr_frame_sync(&isp->isp_res);
omap3isp_stat_isr_frame_sync(&isp->isp_aewb);
omap3isp_stat_isr_frame_sync(&isp->isp_af);
omap3isp_stat_isr_frame_sync(&isp->isp_hist);
}
if (irqstatus & ccdc_events)
omap3isp_ccdc_isr(&isp->isp_ccdc, irqstatus & ccdc_events);
if (irqstatus & IRQ0STATUS_PRV_DONE_IRQ) {
if (isp->isp_prev.output & PREVIEW_OUTPUT_RESIZER)
omap3isp_resizer_isr_frame_sync(&isp->isp_res);
omap3isp_preview_isr(&isp->isp_prev);
}
if (irqstatus & IRQ0STATUS_RSZ_DONE_IRQ)
omap3isp_resizer_isr(&isp->isp_res);
if (irqstatus & IRQ0STATUS_H3A_AWB_DONE_IRQ)
omap3isp_stat_isr(&isp->isp_aewb);
if (irqstatus & IRQ0STATUS_H3A_AF_DONE_IRQ)
omap3isp_stat_isr(&isp->isp_af);
if (irqstatus & IRQ0STATUS_HIST_DONE_IRQ)
omap3isp_stat_isr(&isp->isp_hist);
omap3isp_flush(isp);
#if defined(DEBUG) && defined(ISP_ISR_DEBUG)
isp_isr_dbg(isp, irqstatus);
#endif
return IRQ_HANDLED;
}
static int isp_pipeline_enable(struct isp_pipeline *pipe,
enum isp_pipeline_stream_state mode)
{
struct isp_device *isp = pipe->output->isp;
struct media_entity *entity;
struct media_pad *pad;
struct v4l2_subdev *subdev;
unsigned long flags;
int ret;
if (media_entity_enum_intersects(&pipe->ent_enum, &isp->crashed))
return -EIO;
spin_lock_irqsave(&pipe->lock, flags);
pipe->state &= ~(ISP_PIPELINE_IDLE_INPUT | ISP_PIPELINE_IDLE_OUTPUT);
spin_unlock_irqrestore(&pipe->lock, flags);
pipe->do_propagation = false;
entity = &pipe->output->video.entity;
while (1) {
pad = &entity->pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
pad = media_entity_remote_pad(pad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
break;
entity = pad->entity;
subdev = media_entity_to_v4l2_subdev(entity);
ret = v4l2_subdev_call(subdev, video, s_stream, mode);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
if (subdev == &isp->isp_ccdc.subdev) {
v4l2_subdev_call(&isp->isp_aewb.subdev, video,
s_stream, mode);
v4l2_subdev_call(&isp->isp_af.subdev, video,
s_stream, mode);
v4l2_subdev_call(&isp->isp_hist.subdev, video,
s_stream, mode);
pipe->do_propagation = true;
}
}
return 0;
}
static int isp_pipeline_wait_resizer(struct isp_device *isp)
{
return omap3isp_resizer_busy(&isp->isp_res);
}
static int isp_pipeline_wait_preview(struct isp_device *isp)
{
return omap3isp_preview_busy(&isp->isp_prev);
}
static int isp_pipeline_wait_ccdc(struct isp_device *isp)
{
return omap3isp_stat_busy(&isp->isp_af)
|| omap3isp_stat_busy(&isp->isp_aewb)
|| omap3isp_stat_busy(&isp->isp_hist)
|| omap3isp_ccdc_busy(&isp->isp_ccdc);
}
static int isp_pipeline_wait(struct isp_device *isp,
int(*busy)(struct isp_device *isp))
{
unsigned long timeout = jiffies + ISP_STOP_TIMEOUT;
while (!time_after(jiffies, timeout)) {
if (!busy(isp))
return 0;
}
return 1;
}
static int isp_pipeline_disable(struct isp_pipeline *pipe)
{
struct isp_device *isp = pipe->output->isp;
struct media_entity *entity;
struct media_pad *pad;
struct v4l2_subdev *subdev;
int failure = 0;
int ret;
entity = &pipe->output->video.entity;
while (1) {
pad = &entity->pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
pad = media_entity_remote_pad(pad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
break;
entity = pad->entity;
subdev = media_entity_to_v4l2_subdev(entity);
if (subdev == &isp->isp_ccdc.subdev) {
v4l2_subdev_call(&isp->isp_aewb.subdev,
video, s_stream, 0);
v4l2_subdev_call(&isp->isp_af.subdev,
video, s_stream, 0);
v4l2_subdev_call(&isp->isp_hist.subdev,
video, s_stream, 0);
}
ret = v4l2_subdev_call(subdev, video, s_stream, 0);
if (subdev == &isp->isp_res.subdev)
ret |= isp_pipeline_wait(isp, isp_pipeline_wait_resizer);
else if (subdev == &isp->isp_prev.subdev)
ret |= isp_pipeline_wait(isp, isp_pipeline_wait_preview);
else if (subdev == &isp->isp_ccdc.subdev)
ret |= isp_pipeline_wait(isp, isp_pipeline_wait_ccdc);
if (ret) {
dev_info(isp->dev, "Unable to stop %s\n", subdev->name);
isp->stop_failure = true;
if (subdev == &isp->isp_prev.subdev)
media_entity_enum_set(&isp->crashed,
&subdev->entity);
failure = -ETIMEDOUT;
}
}
return failure;
}
int omap3isp_pipeline_set_stream(struct isp_pipeline *pipe,
enum isp_pipeline_stream_state state)
{
int ret;
if (state == ISP_PIPELINE_STREAM_STOPPED)
ret = isp_pipeline_disable(pipe);
else
ret = isp_pipeline_enable(pipe, state);
if (ret == 0 || state == ISP_PIPELINE_STREAM_STOPPED)
pipe->stream_state = state;
return ret;
}
void omap3isp_pipeline_cancel_stream(struct isp_pipeline *pipe)
{
if (pipe->input)
omap3isp_video_cancel_stream(pipe->input);
if (pipe->output)
omap3isp_video_cancel_stream(pipe->output);
}
static void isp_pipeline_resume(struct isp_pipeline *pipe)
{
int singleshot = pipe->stream_state == ISP_PIPELINE_STREAM_SINGLESHOT;
omap3isp_video_resume(pipe->output, !singleshot);
if (singleshot)
omap3isp_video_resume(pipe->input, 0);
isp_pipeline_enable(pipe, pipe->stream_state);
}
static void isp_pipeline_suspend(struct isp_pipeline *pipe)
{
isp_pipeline_disable(pipe);
}
static int isp_pipeline_is_last(struct media_entity *me)
{
struct isp_pipeline *pipe;
struct media_pad *pad;
if (!me->pipe)
return 0;
pipe = to_isp_pipeline(me);
if (pipe->stream_state == ISP_PIPELINE_STREAM_STOPPED)
return 0;
pad = media_entity_remote_pad(&pipe->output->pad);
return pad->entity == me;
}
static void isp_suspend_module_pipeline(struct media_entity *me)
{
if (isp_pipeline_is_last(me))
isp_pipeline_suspend(to_isp_pipeline(me));
}
static void isp_resume_module_pipeline(struct media_entity *me)
{
if (isp_pipeline_is_last(me))
isp_pipeline_resume(to_isp_pipeline(me));
}
static int isp_suspend_modules(struct isp_device *isp)
{
unsigned long timeout;
omap3isp_stat_suspend(&isp->isp_aewb);
omap3isp_stat_suspend(&isp->isp_af);
omap3isp_stat_suspend(&isp->isp_hist);
isp_suspend_module_pipeline(&isp->isp_res.subdev.entity);
isp_suspend_module_pipeline(&isp->isp_prev.subdev.entity);
isp_suspend_module_pipeline(&isp->isp_ccdc.subdev.entity);
isp_suspend_module_pipeline(&isp->isp_csi2a.subdev.entity);
isp_suspend_module_pipeline(&isp->isp_ccp2.subdev.entity);
timeout = jiffies + ISP_STOP_TIMEOUT;
while (omap3isp_stat_busy(&isp->isp_af)
|| omap3isp_stat_busy(&isp->isp_aewb)
|| omap3isp_stat_busy(&isp->isp_hist)
|| omap3isp_preview_busy(&isp->isp_prev)
|| omap3isp_resizer_busy(&isp->isp_res)
|| omap3isp_ccdc_busy(&isp->isp_ccdc)) {
if (time_after(jiffies, timeout)) {
dev_info(isp->dev, "can't stop modules.\n");
return 1;
}
msleep(1);
}
return 0;
}
static void isp_resume_modules(struct isp_device *isp)
{
omap3isp_stat_resume(&isp->isp_aewb);
omap3isp_stat_resume(&isp->isp_af);
omap3isp_stat_resume(&isp->isp_hist);
isp_resume_module_pipeline(&isp->isp_res.subdev.entity);
isp_resume_module_pipeline(&isp->isp_prev.subdev.entity);
isp_resume_module_pipeline(&isp->isp_ccdc.subdev.entity);
isp_resume_module_pipeline(&isp->isp_csi2a.subdev.entity);
isp_resume_module_pipeline(&isp->isp_ccp2.subdev.entity);
}
static int isp_reset(struct isp_device *isp)
{
unsigned long timeout = 0;
isp_reg_writel(isp,
isp_reg_readl(isp, OMAP3_ISP_IOMEM_MAIN, ISP_SYSCONFIG)
| ISP_SYSCONFIG_SOFTRESET,
OMAP3_ISP_IOMEM_MAIN, ISP_SYSCONFIG);
while (!(isp_reg_readl(isp, OMAP3_ISP_IOMEM_MAIN,
ISP_SYSSTATUS) & 0x1)) {
if (timeout++ > 10000) {
dev_alert(isp->dev, "cannot reset ISP\n");
return -ETIMEDOUT;
}
udelay(1);
}
isp->stop_failure = false;
media_entity_enum_zero(&isp->crashed);
return 0;
}
static void
isp_save_context(struct isp_device *isp, struct isp_reg *reg_list)
{
struct isp_reg *next = reg_list;
for (; next->reg != ISP_TOK_TERM; next++)
next->val = isp_reg_readl(isp, next->mmio_range, next->reg);
}
static void
isp_restore_context(struct isp_device *isp, struct isp_reg *reg_list)
{
struct isp_reg *next = reg_list;
for (; next->reg != ISP_TOK_TERM; next++)
isp_reg_writel(isp, next->val, next->mmio_range, next->reg);
}
static void isp_save_ctx(struct isp_device *isp)
{
isp_save_context(isp, isp_reg_list);
omap_iommu_save_ctx(isp->dev);
}
static void isp_restore_ctx(struct isp_device *isp)
{
isp_restore_context(isp, isp_reg_list);
omap_iommu_restore_ctx(isp->dev);
omap3isp_ccdc_restore_context(isp);
omap3isp_preview_restore_context(isp);
}
void omap3isp_sbl_enable(struct isp_device *isp, enum isp_sbl_resource res)
{
u32 sbl = 0;
isp->sbl_resources |= res;
if (isp->sbl_resources & OMAP3_ISP_SBL_CSI1_READ)
sbl |= ISPCTRL_SBL_SHARED_RPORTA;
if (isp->sbl_resources & OMAP3_ISP_SBL_CCDC_LSC_READ)
sbl |= ISPCTRL_SBL_SHARED_RPORTB;
if (isp->sbl_resources & OMAP3_ISP_SBL_CSI2C_WRITE)
sbl |= ISPCTRL_SBL_SHARED_WPORTC;
if (isp->sbl_resources & OMAP3_ISP_SBL_RESIZER_WRITE)
sbl |= ISPCTRL_SBL_WR0_RAM_EN;
if (isp->sbl_resources & OMAP3_ISP_SBL_WRITE)
sbl |= ISPCTRL_SBL_WR1_RAM_EN;
if (isp->sbl_resources & OMAP3_ISP_SBL_READ)
sbl |= ISPCTRL_SBL_RD_RAM_EN;
isp_reg_set(isp, OMAP3_ISP_IOMEM_MAIN, ISP_CTRL, sbl);
}
void omap3isp_sbl_disable(struct isp_device *isp, enum isp_sbl_resource res)
{
u32 sbl = 0;
isp->sbl_resources &= ~res;
if (!(isp->sbl_resources & OMAP3_ISP_SBL_CSI1_READ))
sbl |= ISPCTRL_SBL_SHARED_RPORTA;
if (!(isp->sbl_resources & OMAP3_ISP_SBL_CCDC_LSC_READ))
sbl |= ISPCTRL_SBL_SHARED_RPORTB;
if (!(isp->sbl_resources & OMAP3_ISP_SBL_CSI2C_WRITE))
sbl |= ISPCTRL_SBL_SHARED_WPORTC;
if (!(isp->sbl_resources & OMAP3_ISP_SBL_RESIZER_WRITE))
sbl |= ISPCTRL_SBL_WR0_RAM_EN;
if (!(isp->sbl_resources & OMAP3_ISP_SBL_WRITE))
sbl |= ISPCTRL_SBL_WR1_RAM_EN;
if (!(isp->sbl_resources & OMAP3_ISP_SBL_READ))
sbl |= ISPCTRL_SBL_RD_RAM_EN;
isp_reg_clr(isp, OMAP3_ISP_IOMEM_MAIN, ISP_CTRL, sbl);
}
int omap3isp_module_sync_idle(struct media_entity *me, wait_queue_head_t *wait,
atomic_t *stopping)
{
struct isp_pipeline *pipe = to_isp_pipeline(me);
if (pipe->stream_state == ISP_PIPELINE_STREAM_STOPPED ||
(pipe->stream_state == ISP_PIPELINE_STREAM_SINGLESHOT &&
!isp_pipeline_ready(pipe)))
return 0;
atomic_set(stopping, 1);
smp_mb();
if (isp_pipeline_is_last(me)) {
struct isp_video *video = pipe->output;
unsigned long flags;
spin_lock_irqsave(&video->irqlock, flags);
if (video->dmaqueue_flags & ISP_VIDEO_DMAQUEUE_UNDERRUN) {
spin_unlock_irqrestore(&video->irqlock, flags);
atomic_set(stopping, 0);
smp_mb();
return 0;
}
spin_unlock_irqrestore(&video->irqlock, flags);
if (!wait_event_timeout(*wait, !atomic_read(stopping),
msecs_to_jiffies(1000))) {
atomic_set(stopping, 0);
smp_mb();
return -ETIMEDOUT;
}
}
return 0;
}
int omap3isp_module_sync_is_stopping(wait_queue_head_t *wait,
atomic_t *stopping)
{
if (atomic_cmpxchg(stopping, 1, 0)) {
wake_up(wait);
return 1;
}
return 0;
}
static void __isp_subclk_update(struct isp_device *isp)
{
u32 clk = 0;
if (isp->subclk_resources &
(OMAP3_ISP_SUBCLK_AEWB | OMAP3_ISP_SUBCLK_AF))
clk |= ISPCTRL_H3A_CLK_EN;
if (isp->subclk_resources & OMAP3_ISP_SUBCLK_HIST)
clk |= ISPCTRL_HIST_CLK_EN;
if (isp->subclk_resources & OMAP3_ISP_SUBCLK_RESIZER)
clk |= ISPCTRL_RSZ_CLK_EN;
if (isp->subclk_resources & OMAP3_ISP_SUBCLK_CCDC)
clk |= ISPCTRL_CCDC_CLK_EN | ISPCTRL_CCDC_RAM_EN;
if (isp->subclk_resources & OMAP3_ISP_SUBCLK_PREVIEW)
clk |= ISPCTRL_PREV_CLK_EN | ISPCTRL_PREV_RAM_EN;
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_MAIN, ISP_CTRL,
ISPCTRL_CLKS_MASK, clk);
}
void omap3isp_subclk_enable(struct isp_device *isp,
enum isp_subclk_resource res)
{
isp->subclk_resources |= res;
__isp_subclk_update(isp);
}
void omap3isp_subclk_disable(struct isp_device *isp,
enum isp_subclk_resource res)
{
isp->subclk_resources &= ~res;
__isp_subclk_update(isp);
}
static int isp_enable_clocks(struct isp_device *isp)
{
int r;
unsigned long rate;
r = clk_prepare_enable(isp->clock[ISP_CLK_CAM_ICK]);
if (r) {
dev_err(isp->dev, "failed to enable cam_ick clock\n");
goto out_clk_enable_ick;
}
r = clk_set_rate(isp->clock[ISP_CLK_CAM_MCLK], CM_CAM_MCLK_HZ);
if (r) {
dev_err(isp->dev, "clk_set_rate for cam_mclk failed\n");
goto out_clk_enable_mclk;
}
r = clk_prepare_enable(isp->clock[ISP_CLK_CAM_MCLK]);
if (r) {
dev_err(isp->dev, "failed to enable cam_mclk clock\n");
goto out_clk_enable_mclk;
}
rate = clk_get_rate(isp->clock[ISP_CLK_CAM_MCLK]);
if (rate != CM_CAM_MCLK_HZ)
dev_warn(isp->dev, "unexpected cam_mclk rate:\n"
" expected : %d\n"
" actual : %ld\n", CM_CAM_MCLK_HZ, rate);
r = clk_prepare_enable(isp->clock[ISP_CLK_CSI2_FCK]);
if (r) {
dev_err(isp->dev, "failed to enable csi2_fck clock\n");
goto out_clk_enable_csi2_fclk;
}
return 0;
out_clk_enable_csi2_fclk:
clk_disable_unprepare(isp->clock[ISP_CLK_CAM_MCLK]);
out_clk_enable_mclk:
clk_disable_unprepare(isp->clock[ISP_CLK_CAM_ICK]);
out_clk_enable_ick:
return r;
}
static void isp_disable_clocks(struct isp_device *isp)
{
clk_disable_unprepare(isp->clock[ISP_CLK_CAM_ICK]);
clk_disable_unprepare(isp->clock[ISP_CLK_CAM_MCLK]);
clk_disable_unprepare(isp->clock[ISP_CLK_CSI2_FCK]);
}
static int isp_get_clocks(struct isp_device *isp)
{
struct clk *clk;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(isp_clocks); ++i) {
clk = devm_clk_get(isp->dev, isp_clocks[i]);
if (IS_ERR(clk)) {
dev_err(isp->dev, "clk_get %s failed\n", isp_clocks[i]);
return PTR_ERR(clk);
}
isp->clock[i] = clk;
}
return 0;
}
static struct isp_device *__omap3isp_get(struct isp_device *isp, bool irq)
{
struct isp_device *__isp = isp;
if (isp == NULL)
return NULL;
mutex_lock(&isp->isp_mutex);
if (isp->ref_count > 0)
goto out;
if (isp_enable_clocks(isp) < 0) {
__isp = NULL;
goto out;
}
if (isp->has_context)
isp_restore_ctx(isp);
if (irq)
isp_enable_interrupts(isp);
out:
if (__isp != NULL)
isp->ref_count++;
mutex_unlock(&isp->isp_mutex);
return __isp;
}
struct isp_device *omap3isp_get(struct isp_device *isp)
{
return __omap3isp_get(isp, true);
}
static void __omap3isp_put(struct isp_device *isp, bool save_ctx)
{
if (isp == NULL)
return;
mutex_lock(&isp->isp_mutex);
BUG_ON(isp->ref_count == 0);
if (--isp->ref_count == 0) {
isp_disable_interrupts(isp);
if (save_ctx) {
isp_save_ctx(isp);
isp->has_context = 1;
}
if (!media_entity_enum_empty(&isp->crashed) ||
isp->stop_failure)
isp_reset(isp);
isp_disable_clocks(isp);
}
mutex_unlock(&isp->isp_mutex);
}
void omap3isp_put(struct isp_device *isp)
{
__omap3isp_put(isp, true);
}
void omap3isp_print_status(struct isp_device *isp)
{
dev_dbg(isp->dev, "-------------ISP Register dump--------------\n");
ISP_PRINT_REGISTER(isp, SYSCONFIG);
ISP_PRINT_REGISTER(isp, SYSSTATUS);
ISP_PRINT_REGISTER(isp, IRQ0ENABLE);
ISP_PRINT_REGISTER(isp, IRQ0STATUS);
ISP_PRINT_REGISTER(isp, TCTRL_GRESET_LENGTH);
ISP_PRINT_REGISTER(isp, TCTRL_PSTRB_REPLAY);
ISP_PRINT_REGISTER(isp, CTRL);
ISP_PRINT_REGISTER(isp, TCTRL_CTRL);
ISP_PRINT_REGISTER(isp, TCTRL_FRAME);
ISP_PRINT_REGISTER(isp, TCTRL_PSTRB_DELAY);
ISP_PRINT_REGISTER(isp, TCTRL_STRB_DELAY);
ISP_PRINT_REGISTER(isp, TCTRL_SHUT_DELAY);
ISP_PRINT_REGISTER(isp, TCTRL_PSTRB_LENGTH);
ISP_PRINT_REGISTER(isp, TCTRL_STRB_LENGTH);
ISP_PRINT_REGISTER(isp, TCTRL_SHUT_LENGTH);
SBL_PRINT_REGISTER(isp, PCR);
SBL_PRINT_REGISTER(isp, SDR_REQ_EXP);
dev_dbg(isp->dev, "--------------------------------------------\n");
}
static int isp_pm_prepare(struct device *dev)
{
struct isp_device *isp = dev_get_drvdata(dev);
int reset;
WARN_ON(mutex_is_locked(&isp->isp_mutex));
if (isp->ref_count == 0)
return 0;
reset = isp_suspend_modules(isp);
isp_disable_interrupts(isp);
isp_save_ctx(isp);
if (reset)
isp_reset(isp);
return 0;
}
static int isp_pm_suspend(struct device *dev)
{
struct isp_device *isp = dev_get_drvdata(dev);
WARN_ON(mutex_is_locked(&isp->isp_mutex));
if (isp->ref_count)
isp_disable_clocks(isp);
return 0;
}
static int isp_pm_resume(struct device *dev)
{
struct isp_device *isp = dev_get_drvdata(dev);
if (isp->ref_count == 0)
return 0;
return isp_enable_clocks(isp);
}
static void isp_pm_complete(struct device *dev)
{
struct isp_device *isp = dev_get_drvdata(dev);
if (isp->ref_count == 0)
return;
isp_restore_ctx(isp);
isp_enable_interrupts(isp);
isp_resume_modules(isp);
}
static void isp_unregister_entities(struct isp_device *isp)
{
omap3isp_csi2_unregister_entities(&isp->isp_csi2a);
omap3isp_ccp2_unregister_entities(&isp->isp_ccp2);
omap3isp_ccdc_unregister_entities(&isp->isp_ccdc);
omap3isp_preview_unregister_entities(&isp->isp_prev);
omap3isp_resizer_unregister_entities(&isp->isp_res);
omap3isp_stat_unregister_entities(&isp->isp_aewb);
omap3isp_stat_unregister_entities(&isp->isp_af);
omap3isp_stat_unregister_entities(&isp->isp_hist);
v4l2_device_unregister(&isp->v4l2_dev);
media_device_unregister(&isp->media_dev);
media_device_cleanup(&isp->media_dev);
}
static int isp_link_entity(
struct isp_device *isp, struct media_entity *entity,
enum isp_interface_type interface)
{
struct media_entity *input;
unsigned int flags;
unsigned int pad;
unsigned int i;
switch (interface) {
case ISP_INTERFACE_PARALLEL:
input = &isp->isp_ccdc.subdev.entity;
pad = CCDC_PAD_SINK;
flags = 0;
break;
case ISP_INTERFACE_CSI2A_PHY2:
input = &isp->isp_csi2a.subdev.entity;
pad = CSI2_PAD_SINK;
flags = MEDIA_LNK_FL_IMMUTABLE | MEDIA_LNK_FL_ENABLED;
break;
case ISP_INTERFACE_CCP2B_PHY1:
case ISP_INTERFACE_CCP2B_PHY2:
input = &isp->isp_ccp2.subdev.entity;
pad = CCP2_PAD_SINK;
flags = 0;
break;
case ISP_INTERFACE_CSI2C_PHY1:
input = &isp->isp_csi2c.subdev.entity;
pad = CSI2_PAD_SINK;
flags = MEDIA_LNK_FL_IMMUTABLE | MEDIA_LNK_FL_ENABLED;
break;
default:
dev_err(isp->dev, "%s: invalid interface type %u\n", __func__,
interface);
return -EINVAL;
}
if (!input->num_pads) {
dev_err(isp->dev, "%s: invalid input %u\n", entity->name,
interface);
return -EINVAL;
}
for (i = 0; i < entity->num_pads; i++) {
if (entity->pads[i].flags & MEDIA_PAD_FL_SOURCE)
break;
}
if (i == entity->num_pads) {
dev_err(isp->dev, "%s: no source pad in external entity\n",
__func__);
return -EINVAL;
}
return media_create_pad_link(entity, i, input, pad, flags);
}
static int isp_register_entities(struct isp_device *isp)
{
int ret;
isp->media_dev.dev = isp->dev;
strlcpy(isp->media_dev.model, "TI OMAP3 ISP",
sizeof(isp->media_dev.model));
isp->media_dev.hw_revision = isp->revision;
isp->media_dev.ops = &isp_media_ops;
media_device_init(&isp->media_dev);
isp->v4l2_dev.mdev = &isp->media_dev;
ret = v4l2_device_register(isp->dev, &isp->v4l2_dev);
if (ret < 0) {
dev_err(isp->dev, "%s: V4L2 device registration failed (%d)\n",
__func__, ret);
goto done;
}
ret = omap3isp_ccp2_register_entities(&isp->isp_ccp2, &isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_csi2_register_entities(&isp->isp_csi2a, &isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_ccdc_register_entities(&isp->isp_ccdc, &isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_preview_register_entities(&isp->isp_prev,
&isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_resizer_register_entities(&isp->isp_res, &isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_stat_register_entities(&isp->isp_aewb, &isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_stat_register_entities(&isp->isp_af, &isp->v4l2_dev);
if (ret < 0)
goto done;
ret = omap3isp_stat_register_entities(&isp->isp_hist, &isp->v4l2_dev);
if (ret < 0)
goto done;
done:
if (ret < 0)
isp_unregister_entities(isp);
return ret;
}
static int isp_create_links(struct isp_device *isp)
{
int ret;
ret = media_create_pad_link(
&isp->isp_csi2a.subdev.entity, CSI2_PAD_SOURCE,
&isp->isp_csi2a.video_out.video.entity, 0, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccp2.video_in.video.entity, 0,
&isp->isp_ccp2.subdev.entity, CCP2_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_OF,
&isp->isp_ccdc.video_out.video.entity, 0, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_prev.video_in.video.entity, 0,
&isp->isp_prev.subdev.entity, PREV_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_prev.subdev.entity, PREV_PAD_SOURCE,
&isp->isp_prev.video_out.video.entity, 0, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_res.video_in.video.entity, 0,
&isp->isp_res.subdev.entity, RESZ_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_res.subdev.entity, RESZ_PAD_SOURCE,
&isp->isp_res.video_out.video.entity, 0, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_csi2a.subdev.entity, CSI2_PAD_SOURCE,
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccp2.subdev.entity, CCP2_PAD_SOURCE,
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_prev.subdev.entity, PREV_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_OF,
&isp->isp_res.subdev.entity, RESZ_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_prev.subdev.entity, PREV_PAD_SOURCE,
&isp->isp_res.subdev.entity, RESZ_PAD_SINK, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_aewb.subdev.entity, 0,
MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_af.subdev.entity, 0,
MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
return ret;
ret = media_create_pad_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_hist.subdev.entity, 0,
MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
return ret;
return 0;
}
static void isp_cleanup_modules(struct isp_device *isp)
{
omap3isp_h3a_aewb_cleanup(isp);
omap3isp_h3a_af_cleanup(isp);
omap3isp_hist_cleanup(isp);
omap3isp_resizer_cleanup(isp);
omap3isp_preview_cleanup(isp);
omap3isp_ccdc_cleanup(isp);
omap3isp_ccp2_cleanup(isp);
omap3isp_csi2_cleanup(isp);
}
static int isp_initialize_modules(struct isp_device *isp)
{
int ret;
ret = omap3isp_csiphy_init(isp);
if (ret < 0) {
dev_err(isp->dev, "CSI PHY initialization failed\n");
goto error_csiphy;
}
ret = omap3isp_csi2_init(isp);
if (ret < 0) {
dev_err(isp->dev, "CSI2 initialization failed\n");
goto error_csi2;
}
ret = omap3isp_ccp2_init(isp);
if (ret < 0) {
dev_err(isp->dev, "CCP2 initialization failed\n");
goto error_ccp2;
}
ret = omap3isp_ccdc_init(isp);
if (ret < 0) {
dev_err(isp->dev, "CCDC initialization failed\n");
goto error_ccdc;
}
ret = omap3isp_preview_init(isp);
if (ret < 0) {
dev_err(isp->dev, "Preview initialization failed\n");
goto error_preview;
}
ret = omap3isp_resizer_init(isp);
if (ret < 0) {
dev_err(isp->dev, "Resizer initialization failed\n");
goto error_resizer;
}
ret = omap3isp_hist_init(isp);
if (ret < 0) {
dev_err(isp->dev, "Histogram initialization failed\n");
goto error_hist;
}
ret = omap3isp_h3a_aewb_init(isp);
if (ret < 0) {
dev_err(isp->dev, "H3A AEWB initialization failed\n");
goto error_h3a_aewb;
}
ret = omap3isp_h3a_af_init(isp);
if (ret < 0) {
dev_err(isp->dev, "H3A AF initialization failed\n");
goto error_h3a_af;
}
return 0;
error_h3a_af:
omap3isp_h3a_aewb_cleanup(isp);
error_h3a_aewb:
omap3isp_hist_cleanup(isp);
error_hist:
omap3isp_resizer_cleanup(isp);
error_resizer:
omap3isp_preview_cleanup(isp);
error_preview:
omap3isp_ccdc_cleanup(isp);
error_ccdc:
omap3isp_ccp2_cleanup(isp);
error_ccp2:
omap3isp_csi2_cleanup(isp);
error_csi2:
error_csiphy:
return ret;
}
static void isp_detach_iommu(struct isp_device *isp)
{
arm_iommu_release_mapping(isp->mapping);
isp->mapping = NULL;
}
static int isp_attach_iommu(struct isp_device *isp)
{
struct dma_iommu_mapping *mapping;
int ret;
mapping = arm_iommu_create_mapping(&platform_bus_type, SZ_1G, SZ_2G);
if (IS_ERR(mapping)) {
dev_err(isp->dev, "failed to create ARM IOMMU mapping\n");
ret = PTR_ERR(mapping);
goto error;
}
isp->mapping = mapping;
ret = arm_iommu_attach_device(isp->dev, mapping);
if (ret < 0) {
dev_err(isp->dev, "failed to attach device to VA mapping\n");
goto error;
}
return 0;
error:
isp_detach_iommu(isp);
return ret;
}
static int isp_remove(struct platform_device *pdev)
{
struct isp_device *isp = platform_get_drvdata(pdev);
v4l2_async_notifier_unregister(&isp->notifier);
isp_unregister_entities(isp);
isp_cleanup_modules(isp);
isp_xclk_cleanup(isp);
__omap3isp_get(isp, false);
isp_detach_iommu(isp);
__omap3isp_put(isp, false);
media_entity_enum_cleanup(&isp->crashed);
return 0;
}
static int isp_of_parse_node(struct device *dev, struct device_node *node,
struct isp_async_subdev *isd)
{
struct isp_bus_cfg *buscfg = &isd->bus;
struct v4l2_of_endpoint vep;
unsigned int i;
int ret;
ret = v4l2_of_parse_endpoint(node, &vep);
if (ret)
return ret;
dev_dbg(dev, "parsing endpoint %s, interface %u\n", node->full_name,
vep.base.port);
switch (vep.base.port) {
case ISP_OF_PHY_PARALLEL:
buscfg->interface = ISP_INTERFACE_PARALLEL;
buscfg->bus.parallel.data_lane_shift =
vep.bus.parallel.data_shift;
buscfg->bus.parallel.clk_pol =
!!(vep.bus.parallel.flags
& V4L2_MBUS_PCLK_SAMPLE_FALLING);
buscfg->bus.parallel.hs_pol =
!!(vep.bus.parallel.flags & V4L2_MBUS_VSYNC_ACTIVE_LOW);
buscfg->bus.parallel.vs_pol =
!!(vep.bus.parallel.flags & V4L2_MBUS_HSYNC_ACTIVE_LOW);
buscfg->bus.parallel.fld_pol =
!!(vep.bus.parallel.flags & V4L2_MBUS_FIELD_EVEN_LOW);
buscfg->bus.parallel.data_pol =
!!(vep.bus.parallel.flags & V4L2_MBUS_DATA_ACTIVE_LOW);
break;
case ISP_OF_PHY_CSIPHY1:
case ISP_OF_PHY_CSIPHY2:
switch (vep.base.port) {
case ISP_OF_PHY_CSIPHY1:
buscfg->interface = ISP_INTERFACE_CSI2C_PHY1;
break;
case ISP_OF_PHY_CSIPHY2:
buscfg->interface = ISP_INTERFACE_CSI2A_PHY2;
break;
}
buscfg->bus.csi2.lanecfg.clk.pos = vep.bus.mipi_csi2.clock_lane;
buscfg->bus.csi2.lanecfg.clk.pol =
vep.bus.mipi_csi2.lane_polarities[0];
dev_dbg(dev, "clock lane polarity %u, pos %u\n",
buscfg->bus.csi2.lanecfg.clk.pol,
buscfg->bus.csi2.lanecfg.clk.pos);
for (i = 0; i < ISP_CSIPHY2_NUM_DATA_LANES; i++) {
buscfg->bus.csi2.lanecfg.data[i].pos =
vep.bus.mipi_csi2.data_lanes[i];
buscfg->bus.csi2.lanecfg.data[i].pol =
vep.bus.mipi_csi2.lane_polarities[i + 1];
dev_dbg(dev, "data lane %u polarity %u, pos %u\n", i,
buscfg->bus.csi2.lanecfg.data[i].pol,
buscfg->bus.csi2.lanecfg.data[i].pos);
}
buscfg->bus.csi2.crc = 1;
break;
default:
dev_warn(dev, "%s: invalid interface %u\n", node->full_name,
vep.base.port);
break;
}
return 0;
}
static int isp_of_parse_nodes(struct device *dev,
struct v4l2_async_notifier *notifier)
{
struct device_node *node = NULL;
notifier->subdevs = devm_kcalloc(
dev, ISP_MAX_SUBDEVS, sizeof(*notifier->subdevs), GFP_KERNEL);
if (!notifier->subdevs)
return -ENOMEM;
while (notifier->num_subdevs < ISP_MAX_SUBDEVS &&
(node = of_graph_get_next_endpoint(dev->of_node, node))) {
struct isp_async_subdev *isd;
isd = devm_kzalloc(dev, sizeof(*isd), GFP_KERNEL);
if (!isd)
goto error;
notifier->subdevs[notifier->num_subdevs] = &isd->asd;
if (isp_of_parse_node(dev, node, isd))
goto error;
isd->asd.match.of.node = of_graph_get_remote_port_parent(node);
if (!isd->asd.match.of.node) {
dev_warn(dev, "bad remote port parent\n");
goto error;
}
isd->asd.match_type = V4L2_ASYNC_MATCH_OF;
notifier->num_subdevs++;
}
return notifier->num_subdevs;
error:
of_node_put(node);
return -EINVAL;
}
static int isp_subdev_notifier_bound(struct v4l2_async_notifier *async,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct isp_async_subdev *isd =
container_of(asd, struct isp_async_subdev, asd);
isd->sd = subdev;
isd->sd->host_priv = &isd->bus;
return 0;
}
static int isp_subdev_notifier_complete(struct v4l2_async_notifier *async)
{
struct isp_device *isp = container_of(async, struct isp_device,
notifier);
struct v4l2_device *v4l2_dev = &isp->v4l2_dev;
struct v4l2_subdev *sd;
struct isp_bus_cfg *bus;
int ret;
ret = media_entity_enum_init(&isp->crashed, &isp->media_dev);
if (ret)
return ret;
list_for_each_entry(sd, &v4l2_dev->subdevs, list) {
if (sd->host_priv) {
bus = (struct isp_bus_cfg *)sd->host_priv;
ret = isp_link_entity(isp, &sd->entity, bus->interface);
if (ret < 0)
return ret;
}
}
ret = v4l2_device_register_subdev_nodes(&isp->v4l2_dev);
if (ret < 0)
return ret;
return media_device_register(&isp->media_dev);
}
static int isp_probe(struct platform_device *pdev)
{
struct isp_device *isp;
struct resource *mem;
int ret;
int i, m;
isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
if (!isp) {
dev_err(&pdev->dev, "could not allocate memory\n");
return -ENOMEM;
}
ret = of_property_read_u32(pdev->dev.of_node, "ti,phy-type",
&isp->phy_type);
if (ret)
return ret;
isp->syscon = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"syscon");
if (IS_ERR(isp->syscon))
return PTR_ERR(isp->syscon);
ret = of_property_read_u32_index(pdev->dev.of_node, "syscon", 1,
&isp->syscon_offset);
if (ret)
return ret;
ret = isp_of_parse_nodes(&pdev->dev, &isp->notifier);
if (ret < 0)
return ret;
isp->autoidle = autoidle;
mutex_init(&isp->isp_mutex);
spin_lock_init(&isp->stat_lock);
isp->dev = &pdev->dev;
isp->ref_count = 0;
ret = dma_coerce_mask_and_coherent(isp->dev, DMA_BIT_MASK(32));
if (ret)
goto error;
platform_set_drvdata(pdev, isp);
isp->isp_csiphy1.vdd = devm_regulator_get(&pdev->dev, "vdd-csiphy1");
isp->isp_csiphy2.vdd = devm_regulator_get(&pdev->dev, "vdd-csiphy2");
for (i = 0; i < 2; i++) {
unsigned int map_idx = i ? OMAP3_ISP_IOMEM_CSI2A_REGS1 : 0;
mem = platform_get_resource(pdev, IORESOURCE_MEM, i);
isp->mmio_base[map_idx] =
devm_ioremap_resource(isp->dev, mem);
if (IS_ERR(isp->mmio_base[map_idx]))
return PTR_ERR(isp->mmio_base[map_idx]);
}
ret = isp_get_clocks(isp);
if (ret < 0)
goto error;
ret = clk_enable(isp->clock[ISP_CLK_CAM_ICK]);
if (ret < 0)
goto error;
isp->revision = isp_reg_readl(isp, OMAP3_ISP_IOMEM_MAIN, ISP_REVISION);
dev_info(isp->dev, "Revision %d.%d found\n",
(isp->revision & 0xf0) >> 4, isp->revision & 0x0f);
clk_disable(isp->clock[ISP_CLK_CAM_ICK]);
if (__omap3isp_get(isp, false) == NULL) {
ret = -ENODEV;
goto error;
}
ret = isp_reset(isp);
if (ret < 0)
goto error_isp;
ret = isp_xclk_init(isp);
if (ret < 0)
goto error_isp;
for (m = 0; m < ARRAY_SIZE(isp_res_maps); m++)
if (isp->revision == isp_res_maps[m].isp_rev)
break;
if (m == ARRAY_SIZE(isp_res_maps)) {
dev_err(isp->dev, "No resource map found for ISP rev %d.%d\n",
(isp->revision & 0xf0) >> 4, isp->revision & 0xf);
ret = -ENODEV;
goto error_isp;
}
for (i = 1; i < OMAP3_ISP_IOMEM_CSI2A_REGS1; i++)
isp->mmio_base[i] =
isp->mmio_base[0] + isp_res_maps[m].offset[i];
for (i = OMAP3_ISP_IOMEM_CSIPHY2; i < OMAP3_ISP_IOMEM_LAST; i++)
isp->mmio_base[i] =
isp->mmio_base[OMAP3_ISP_IOMEM_CSI2A_REGS1]
+ isp_res_maps[m].offset[i];
isp->mmio_hist_base_phys =
mem->start + isp_res_maps[m].offset[OMAP3_ISP_IOMEM_HIST];
ret = isp_attach_iommu(isp);
if (ret < 0) {
dev_err(&pdev->dev, "unable to attach to IOMMU\n");
goto error_isp;
}
ret = platform_get_irq(pdev, 0);
if (ret <= 0) {
dev_err(isp->dev, "No IRQ resource\n");
ret = -ENODEV;
goto error_iommu;
}
isp->irq_num = ret;
if (devm_request_irq(isp->dev, isp->irq_num, isp_isr, IRQF_SHARED,
"OMAP3 ISP", isp)) {
dev_err(isp->dev, "Unable to request IRQ\n");
ret = -EINVAL;
goto error_iommu;
}
ret = isp_initialize_modules(isp);
if (ret < 0)
goto error_iommu;
ret = isp_register_entities(isp);
if (ret < 0)
goto error_modules;
ret = isp_create_links(isp);
if (ret < 0)
goto error_register_entities;
isp->notifier.bound = isp_subdev_notifier_bound;
isp->notifier.complete = isp_subdev_notifier_complete;
ret = v4l2_async_notifier_register(&isp->v4l2_dev, &isp->notifier);
if (ret)
goto error_register_entities;
isp_core_init(isp, 1);
omap3isp_put(isp);
return 0;
error_register_entities:
isp_unregister_entities(isp);
error_modules:
isp_cleanup_modules(isp);
error_iommu:
isp_detach_iommu(isp);
error_isp:
isp_xclk_cleanup(isp);
__omap3isp_put(isp, false);
error:
mutex_destroy(&isp->isp_mutex);
return ret;
}
