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
static int isp_xclk_init(struct isp_device *isp)
{
struct isp_platform_data *pdata = isp->pdata;
struct clk_init_data init;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(isp->xclks); ++i) {
struct isp_xclk *xclk = &isp->xclks[i];
struct clk *clk;
xclk->isp = isp;
xclk->id = i == 0 ? ISP_XCLK_A : ISP_XCLK_B;
xclk->divider = 1;
spin_lock_init(&xclk->lock);
init.name = i == 0 ? "cam_xclka" : "cam_xclkb";
init.ops = &isp_xclk_ops;
init.parent_names = &isp_xclk_parent_name;
init.num_parents = 1;
xclk->hw.init = &init;
clk = devm_clk_register(isp->dev, &xclk->hw);
if (IS_ERR(clk))
return PTR_ERR(clk);
if (pdata->xclks[i].con_id == NULL &&
pdata->xclks[i].dev_id == NULL)
continue;
xclk->lookup = kzalloc(sizeof(*xclk->lookup), GFP_KERNEL);
if (xclk->lookup == NULL)
return -ENOMEM;
xclk->lookup->con_id = pdata->xclks[i].con_id;
xclk->lookup->dev_id = pdata->xclks[i].dev_id;
xclk->lookup->clk = clk;
clkdev_add(xclk->lookup);
}
return 0;
}
static void isp_xclk_cleanup(struct isp_device *isp)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(isp->xclks); ++i) {
struct isp_xclk *xclk = &isp->xclks[i];
if (xclk->lookup)
clkdev_drop(xclk->lookup);
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
const struct isp_parallel_platform_data *pdata,
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
ispctrl_val |= pdata->clk_pol << ISPCTRL_PAR_CLK_POL_SHIFT;
shift += pdata->data_lane_shift * 2;
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
dev_dbg(isp->dev, "hist: Out of synchronization with "
"CCDC. Ignoring next buffer.\n");
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
static int isp_pipeline_pm_use_count(struct media_entity *entity)
{
struct media_entity_graph graph;
int use = 0;
media_entity_graph_walk_start(&graph, entity);
while ((entity = media_entity_graph_walk_next(&graph))) {
if (media_entity_type(entity) == MEDIA_ENT_T_DEVNODE)
use += entity->use_count;
}
return use;
}
static int isp_pipeline_pm_power_one(struct media_entity *entity, int change)
{
struct v4l2_subdev *subdev;
int ret;
subdev = media_entity_type(entity) == MEDIA_ENT_T_V4L2_SUBDEV
? media_entity_to_v4l2_subdev(entity) : NULL;
if (entity->use_count == 0 && change > 0 && subdev != NULL) {
ret = v4l2_subdev_call(subdev, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
}
entity->use_count += change;
WARN_ON(entity->use_count < 0);
if (entity->use_count == 0 && change < 0 && subdev != NULL)
v4l2_subdev_call(subdev, core, s_power, 0);
return 0;
}
static int isp_pipeline_pm_power(struct media_entity *entity, int change)
{
struct media_entity_graph graph;
struct media_entity *first = entity;
int ret = 0;
if (!change)
return 0;
media_entity_graph_walk_start(&graph, entity);
while (!ret && (entity = media_entity_graph_walk_next(&graph)))
if (media_entity_type(entity) != MEDIA_ENT_T_DEVNODE)
ret = isp_pipeline_pm_power_one(entity, change);
if (!ret)
return 0;
media_entity_graph_walk_start(&graph, first);
while ((first = media_entity_graph_walk_next(&graph))
&& first != entity)
if (media_entity_type(first) != MEDIA_ENT_T_DEVNODE)
isp_pipeline_pm_power_one(first, -change);
return ret;
}
int omap3isp_pipeline_pm_use(struct media_entity *entity, int use)
{
int change = use ? 1 : -1;
int ret;
mutex_lock(&entity->parent->graph_mutex);
entity->use_count += change;
WARN_ON(entity->use_count < 0);
ret = isp_pipeline_pm_power(entity, change);
if (ret < 0)
entity->use_count -= change;
mutex_unlock(&entity->parent->graph_mutex);
return ret;
}
static int isp_pipeline_link_notify(struct media_link *link, u32 flags,
unsigned int notification)
{
struct media_entity *source = link->source->entity;
struct media_entity *sink = link->sink->entity;
int source_use = isp_pipeline_pm_use_count(source);
int sink_use = isp_pipeline_pm_use_count(sink);
int ret;
if (notification == MEDIA_DEV_NOTIFY_POST_LINK_CH &&
!(link->flags & MEDIA_LNK_FL_ENABLED)) {
isp_pipeline_pm_power(source, -sink_use);
isp_pipeline_pm_power(sink, -source_use);
return 0;
}
if (notification == MEDIA_DEV_NOTIFY_POST_LINK_CH &&
(flags & MEDIA_LNK_FL_ENABLED)) {
ret = isp_pipeline_pm_power(source, sink_use);
if (ret < 0)
return ret;
ret = isp_pipeline_pm_power(sink, source_use);
if (ret < 0)
isp_pipeline_pm_power(source, -sink_use);
return ret;
}
return 0;
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
if ((pipe->entities & isp->crashed) &
(1U << isp->isp_prev.subdev.entity.id))
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
if (pad == NULL ||
media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
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
if (pad == NULL ||
media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
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
v4l2_subdev_call(subdev, video, s_stream, 0);
if (subdev == &isp->isp_res.subdev)
ret = isp_pipeline_wait(isp, isp_pipeline_wait_resizer);
else if (subdev == &isp->isp_prev.subdev)
ret = isp_pipeline_wait(isp, isp_pipeline_wait_preview);
else if (subdev == &isp->isp_ccdc.subdev)
ret = isp_pipeline_wait(isp, isp_pipeline_wait_ccdc);
else
ret = 0;
if (ret) {
dev_info(isp->dev, "Unable to stop %s\n", subdev->name);
isp->crashed |= 1U << subdev->entity.id;
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
isp->crashed = 0;
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
spin_lock_irqsave(&video->queue->irqlock, flags);
if (video->dmaqueue_flags & ISP_VIDEO_DMAQUEUE_UNDERRUN) {
spin_unlock_irqrestore(&video->queue->irqlock, flags);
atomic_set(stopping, 0);
smp_mb();
return 0;
}
spin_unlock_irqrestore(&video->queue->irqlock, flags);
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
void omap3isp_put(struct isp_device *isp)
{
if (isp == NULL)
return;
mutex_lock(&isp->isp_mutex);
BUG_ON(isp->ref_count == 0);
if (--isp->ref_count == 0) {
isp_disable_interrupts(isp);
if (isp->domain) {
isp_save_ctx(isp);
isp->has_context = 1;
}
if (isp->crashed)
isp_reset(isp);
isp_disable_clocks(isp);
}
mutex_unlock(&isp->isp_mutex);
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
}
static struct v4l2_subdev *
isp_register_subdev_group(struct isp_device *isp,
struct isp_subdev_i2c_board_info *board_info)
{
struct v4l2_subdev *sensor = NULL;
unsigned int first;
if (board_info->board_info == NULL)
return NULL;
for (first = 1; board_info->board_info; ++board_info, first = 0) {
struct v4l2_subdev *subdev;
struct i2c_adapter *adapter;
adapter = i2c_get_adapter(board_info->i2c_adapter_id);
if (adapter == NULL) {
dev_err(isp->dev, "%s: Unable to get I2C adapter %d for "
"device %s\n", __func__,
board_info->i2c_adapter_id,
board_info->board_info->type);
continue;
}
subdev = v4l2_i2c_new_subdev_board(&isp->v4l2_dev, adapter,
board_info->board_info, NULL);
if (subdev == NULL) {
dev_err(isp->dev, "%s: Unable to register subdev %s\n",
__func__, board_info->board_info->type);
continue;
}
if (first)
sensor = subdev;
}
return sensor;
}
static int isp_register_entities(struct isp_device *isp)
{
struct isp_platform_data *pdata = isp->pdata;
struct isp_v4l2_subdevs_group *subdevs;
int ret;
isp->media_dev.dev = isp->dev;
strlcpy(isp->media_dev.model, "TI OMAP3 ISP",
sizeof(isp->media_dev.model));
isp->media_dev.hw_revision = isp->revision;
isp->media_dev.link_notify = isp_pipeline_link_notify;
ret = media_device_register(&isp->media_dev);
if (ret < 0) {
dev_err(isp->dev, "%s: Media device registration failed (%d)\n",
__func__, ret);
return ret;
}
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
for (subdevs = pdata->subdevs; subdevs && subdevs->subdevs; ++subdevs) {
struct v4l2_subdev *sensor;
struct media_entity *input;
unsigned int flags;
unsigned int pad;
unsigned int i;
sensor = isp_register_subdev_group(isp, subdevs->subdevs);
if (sensor == NULL)
continue;
sensor->host_priv = subdevs;
switch (subdevs->interface) {
case ISP_INTERFACE_PARALLEL:
input = &isp->isp_ccdc.subdev.entity;
pad = CCDC_PAD_SINK;
flags = 0;
break;
case ISP_INTERFACE_CSI2A_PHY2:
input = &isp->isp_csi2a.subdev.entity;
pad = CSI2_PAD_SINK;
flags = MEDIA_LNK_FL_IMMUTABLE
| MEDIA_LNK_FL_ENABLED;
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
flags = MEDIA_LNK_FL_IMMUTABLE
| MEDIA_LNK_FL_ENABLED;
break;
default:
dev_err(isp->dev, "%s: invalid interface type %u\n",
__func__, subdevs->interface);
ret = -EINVAL;
goto done;
}
for (i = 0; i < sensor->entity.num_pads; i++) {
if (sensor->entity.pads[i].flags & MEDIA_PAD_FL_SOURCE)
break;
}
if (i == sensor->entity.num_pads) {
dev_err(isp->dev,
"%s: no source pad in external entity\n",
__func__);
ret = -EINVAL;
goto done;
}
ret = media_entity_create_link(&sensor->entity, i, input, pad,
flags);
if (ret < 0)
goto done;
}
ret = v4l2_device_register_subdev_nodes(&isp->v4l2_dev);
done:
if (ret < 0)
isp_unregister_entities(isp);
return ret;
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
ret = media_entity_create_link(
&isp->isp_csi2a.subdev.entity, CSI2_PAD_SOURCE,
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_ccp2.subdev.entity, CCP2_PAD_SOURCE,
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_prev.subdev.entity, PREV_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_OF,
&isp->isp_res.subdev.entity, RESZ_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_prev.subdev.entity, PREV_PAD_SOURCE,
&isp->isp_res.subdev.entity, RESZ_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_aewb.subdev.entity, 0,
MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_af.subdev.entity, 0,
MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(
&isp->isp_ccdc.subdev.entity, CCDC_PAD_SOURCE_VP,
&isp->isp_hist.subdev.entity, 0,
MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
goto error_link;
return 0;
error_link:
omap3isp_h3a_af_cleanup(isp);
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
static int isp_remove(struct platform_device *pdev)
{
struct isp_device *isp = platform_get_drvdata(pdev);
isp_unregister_entities(isp);
isp_cleanup_modules(isp);
isp_xclk_cleanup(isp);
__omap3isp_get(isp, false);
iommu_detach_device(isp->domain, &pdev->dev);
iommu_domain_free(isp->domain);
isp->domain = NULL;
omap3isp_put(isp);
return 0;
}
static int isp_map_mem_resource(struct platform_device *pdev,
struct isp_device *isp,
enum isp_mem_resources res)
{
struct resource *mem;
mem = platform_get_resource(pdev, IORESOURCE_MEM, res);
if (!mem) {
dev_err(isp->dev, "no mem resource?\n");
return -ENODEV;
}
if (!devm_request_mem_region(isp->dev, mem->start, resource_size(mem),
pdev->name)) {
dev_err(isp->dev,
"cannot reserve camera register I/O region\n");
return -ENODEV;
}
isp->mmio_base_phys[res] = mem->start;
isp->mmio_size[res] = resource_size(mem);
isp->mmio_base[res] = devm_ioremap_nocache(isp->dev,
isp->mmio_base_phys[res],
isp->mmio_size[res]);
if (!isp->mmio_base[res]) {
dev_err(isp->dev, "cannot map camera register I/O region\n");
return -ENODEV;
}
return 0;
}
static int isp_probe(struct platform_device *pdev)
{
struct isp_platform_data *pdata = pdev->dev.platform_data;
struct isp_device *isp;
int ret;
int i, m;
if (pdata == NULL)
return -EINVAL;
isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
if (!isp) {
dev_err(&pdev->dev, "could not allocate memory\n");
return -ENOMEM;
}
isp->autoidle = autoidle;
mutex_init(&isp->isp_mutex);
spin_lock_init(&isp->stat_lock);
isp->dev = &pdev->dev;
isp->pdata = pdata;
isp->ref_count = 0;
ret = dma_coerce_mask_and_coherent(isp->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
platform_set_drvdata(pdev, isp);
isp->isp_csiphy1.vdd = devm_regulator_get(&pdev->dev, "VDD_CSIPHY1");
isp->isp_csiphy2.vdd = devm_regulator_get(&pdev->dev, "VDD_CSIPHY2");
ret = isp_map_mem_resource(pdev, isp, OMAP3_ISP_IOMEM_MAIN);
if (ret < 0)
goto error;
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
for (i = 1; i < OMAP3_ISP_IOMEM_LAST; i++) {
if (isp_res_maps[m].map & 1 << i) {
ret = isp_map_mem_resource(pdev, isp, i);
if (ret)
goto error_isp;
}
}
isp->domain = iommu_domain_alloc(pdev->dev.bus);
if (!isp->domain) {
dev_err(isp->dev, "can't alloc iommu domain\n");
ret = -ENOMEM;
goto error_isp;
}
ret = iommu_attach_device(isp->domain, &pdev->dev);
if (ret) {
dev_err(&pdev->dev, "can't attach iommu device: %d\n", ret);
ret = -EPROBE_DEFER;
goto free_domain;
}
isp->irq_num = platform_get_irq(pdev, 0);
if (isp->irq_num <= 0) {
dev_err(isp->dev, "No IRQ resource\n");
ret = -ENODEV;
goto detach_dev;
}
if (devm_request_irq(isp->dev, isp->irq_num, isp_isr, IRQF_SHARED,
"OMAP3 ISP", isp)) {
dev_err(isp->dev, "Unable to request IRQ\n");
ret = -EINVAL;
goto detach_dev;
}
ret = isp_initialize_modules(isp);
if (ret < 0)
goto detach_dev;
ret = isp_register_entities(isp);
if (ret < 0)
goto error_modules;
isp_core_init(isp, 1);
omap3isp_put(isp);
return 0;
error_modules:
isp_cleanup_modules(isp);
detach_dev:
iommu_detach_device(isp->domain, &pdev->dev);
free_domain:
iommu_domain_free(isp->domain);
isp->domain = NULL;
error_isp:
isp_xclk_cleanup(isp);
omap3isp_put(isp);
error:
mutex_destroy(&isp->isp_mutex);
return ret;
}
