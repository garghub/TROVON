static void rotator_reg_set_irq(struct rot_context *rot, bool enable)
{
u32 val = rot_read(ROT_CONFIG);
if (enable == true)
val |= ROT_CONFIG_IRQ;
else
val &= ~ROT_CONFIG_IRQ;
rot_write(val, ROT_CONFIG);
}
static u32 rotator_reg_get_fmt(struct rot_context *rot)
{
u32 val = rot_read(ROT_CONTROL);
val &= ROT_CONTROL_FMT_MASK;
return val;
}
static enum rot_irq_status rotator_reg_get_irq_status(struct rot_context *rot)
{
u32 val = rot_read(ROT_STATUS);
val = ROT_STATUS_IRQ(val);
if (val == ROT_STATUS_IRQ_VAL_COMPLETE)
return ROT_IRQ_STATUS_COMPLETE;
return ROT_IRQ_STATUS_ILLEGAL;
}
static irqreturn_t rotator_irq_handler(int irq, void *arg)
{
struct rot_context *rot = arg;
struct exynos_drm_ippdrv *ippdrv = &rot->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_event_work *event_work = c_node->event_work;
enum rot_irq_status irq_status;
u32 val;
irq_status = rotator_reg_get_irq_status(rot);
val = rot_read(ROT_STATUS);
val |= ROT_STATUS_IRQ_PENDING((u32)irq_status);
rot_write(val, ROT_STATUS);
if (irq_status == ROT_IRQ_STATUS_COMPLETE) {
event_work->ippdrv = ippdrv;
event_work->buf_id[EXYNOS_DRM_OPS_DST] =
rot->cur_buf_id[EXYNOS_DRM_OPS_DST];
queue_work(ippdrv->event_workq, &event_work->work);
} else {
DRM_ERROR("the SFR is set illegally\n");
}
return IRQ_HANDLED;
}
static void rotator_align_size(struct rot_context *rot, u32 fmt, u32 *hsize,
u32 *vsize)
{
struct rot_limit_table *limit_tbl = rot->limit_tbl;
struct rot_limit *limit;
u32 mask, val;
if (fmt == ROT_CONTROL_FMT_RGB888)
limit = &limit_tbl->rgb888;
else
limit = &limit_tbl->ycbcr420_2p;
mask = ~((1 << limit->align) - 1);
val = ROT_ALIGN(*hsize, limit->align, mask);
if (val < limit->min_w)
*hsize = ROT_MIN(limit->min_w, mask);
else if (val > limit->max_w)
*hsize = ROT_MAX(limit->max_w, mask);
else
*hsize = val;
val = ROT_ALIGN(*vsize, limit->align, mask);
if (val < limit->min_h)
*vsize = ROT_MIN(limit->min_h, mask);
else if (val > limit->max_h)
*vsize = ROT_MAX(limit->max_h, mask);
else
*vsize = val;
}
static int rotator_src_set_fmt(struct device *dev, u32 fmt)
{
struct rot_context *rot = dev_get_drvdata(dev);
u32 val;
val = rot_read(ROT_CONTROL);
val &= ~ROT_CONTROL_FMT_MASK;
switch (fmt) {
case DRM_FORMAT_NV12:
val |= ROT_CONTROL_FMT_YCBCR420_2P;
break;
case DRM_FORMAT_XRGB8888:
val |= ROT_CONTROL_FMT_RGB888;
break;
default:
DRM_ERROR("invalid image format\n");
return -EINVAL;
}
rot_write(val, ROT_CONTROL);
return 0;
}
static inline bool rotator_check_reg_fmt(u32 fmt)
{
if ((fmt == ROT_CONTROL_FMT_YCBCR420_2P) ||
(fmt == ROT_CONTROL_FMT_RGB888))
return true;
return false;
}
static int rotator_src_set_size(struct device *dev, int swap,
struct drm_exynos_pos *pos,
struct drm_exynos_sz *sz)
{
struct rot_context *rot = dev_get_drvdata(dev);
u32 fmt, hsize, vsize;
u32 val;
fmt = rotator_reg_get_fmt(rot);
if (!rotator_check_reg_fmt(fmt)) {
DRM_ERROR("invalid format.\n");
return -EINVAL;
}
hsize = sz->hsize;
vsize = sz->vsize;
rotator_align_size(rot, fmt, &hsize, &vsize);
val = ROT_SET_BUF_SIZE_H(vsize) | ROT_SET_BUF_SIZE_W(hsize);
rot_write(val, ROT_SRC_BUF_SIZE);
val = ROT_CROP_POS_Y(pos->y) | ROT_CROP_POS_X(pos->x);
rot_write(val, ROT_SRC_CROP_POS);
val = ROT_SRC_CROP_SIZE_H(pos->h) | ROT_SRC_CROP_SIZE_W(pos->w);
rot_write(val, ROT_SRC_CROP_SIZE);
return 0;
}
static int rotator_src_set_addr(struct device *dev,
struct drm_exynos_ipp_buf_info *buf_info,
u32 buf_id, enum drm_exynos_ipp_buf_type buf_type)
{
struct rot_context *rot = dev_get_drvdata(dev);
dma_addr_t addr[EXYNOS_DRM_PLANAR_MAX];
u32 val, fmt, hsize, vsize;
int i;
rot->cur_buf_id[EXYNOS_DRM_OPS_SRC] = buf_id;
switch (buf_type) {
case IPP_BUF_ENQUEUE:
for_each_ipp_planar(i)
addr[i] = buf_info->base[i];
fmt = rotator_reg_get_fmt(rot);
if (!rotator_check_reg_fmt(fmt)) {
DRM_ERROR("invalid format.\n");
return -EINVAL;
}
if ((fmt == ROT_CONTROL_FMT_YCBCR420_2P) &&
!addr[EXYNOS_DRM_PLANAR_CB]) {
val = rot_read(ROT_SRC_BUF_SIZE);
hsize = ROT_GET_BUF_SIZE_W(val);
vsize = ROT_GET_BUF_SIZE_H(val);
addr[EXYNOS_DRM_PLANAR_CB] =
addr[EXYNOS_DRM_PLANAR_Y] + hsize * vsize;
}
for_each_ipp_planar(i)
rot_write(addr[i], ROT_SRC_BUF_ADDR(i));
break;
case IPP_BUF_DEQUEUE:
for_each_ipp_planar(i)
rot_write(0x0, ROT_SRC_BUF_ADDR(i));
break;
default:
break;
}
return 0;
}
static int rotator_dst_set_transf(struct device *dev,
enum drm_exynos_degree degree,
enum drm_exynos_flip flip, bool *swap)
{
struct rot_context *rot = dev_get_drvdata(dev);
u32 val;
val = rot_read(ROT_CONTROL);
val &= ~ROT_CONTROL_FLIP_MASK;
switch (flip) {
case EXYNOS_DRM_FLIP_VERTICAL:
val |= ROT_CONTROL_FLIP_VERTICAL;
break;
case EXYNOS_DRM_FLIP_HORIZONTAL:
val |= ROT_CONTROL_FLIP_HORIZONTAL;
break;
default:
break;
}
val &= ~ROT_CONTROL_ROT_MASK;
switch (degree) {
case EXYNOS_DRM_DEGREE_90:
val |= ROT_CONTROL_ROT_90;
break;
case EXYNOS_DRM_DEGREE_180:
val |= ROT_CONTROL_ROT_180;
break;
case EXYNOS_DRM_DEGREE_270:
val |= ROT_CONTROL_ROT_270;
break;
default:
break;
}
rot_write(val, ROT_CONTROL);
if ((degree == EXYNOS_DRM_DEGREE_90) ||
(degree == EXYNOS_DRM_DEGREE_270))
*swap = true;
else
*swap = false;
return 0;
}
static int rotator_dst_set_size(struct device *dev, int swap,
struct drm_exynos_pos *pos,
struct drm_exynos_sz *sz)
{
struct rot_context *rot = dev_get_drvdata(dev);
u32 val, fmt, hsize, vsize;
fmt = rotator_reg_get_fmt(rot);
if (!rotator_check_reg_fmt(fmt)) {
DRM_ERROR("invalid format.\n");
return -EINVAL;
}
hsize = sz->hsize;
vsize = sz->vsize;
rotator_align_size(rot, fmt, &hsize, &vsize);
val = ROT_SET_BUF_SIZE_H(vsize) | ROT_SET_BUF_SIZE_W(hsize);
rot_write(val, ROT_DST_BUF_SIZE);
val = ROT_CROP_POS_Y(pos->y) | ROT_CROP_POS_X(pos->x);
rot_write(val, ROT_DST_CROP_POS);
return 0;
}
static int rotator_dst_set_addr(struct device *dev,
struct drm_exynos_ipp_buf_info *buf_info,
u32 buf_id, enum drm_exynos_ipp_buf_type buf_type)
{
struct rot_context *rot = dev_get_drvdata(dev);
dma_addr_t addr[EXYNOS_DRM_PLANAR_MAX];
u32 val, fmt, hsize, vsize;
int i;
rot->cur_buf_id[EXYNOS_DRM_OPS_DST] = buf_id;
switch (buf_type) {
case IPP_BUF_ENQUEUE:
for_each_ipp_planar(i)
addr[i] = buf_info->base[i];
fmt = rotator_reg_get_fmt(rot);
if (!rotator_check_reg_fmt(fmt)) {
DRM_ERROR("invalid format.\n");
return -EINVAL;
}
if ((fmt == ROT_CONTROL_FMT_YCBCR420_2P) &&
!addr[EXYNOS_DRM_PLANAR_CB]) {
val = rot_read(ROT_DST_BUF_SIZE);
hsize = ROT_GET_BUF_SIZE_W(val);
vsize = ROT_GET_BUF_SIZE_H(val);
addr[EXYNOS_DRM_PLANAR_CB] =
addr[EXYNOS_DRM_PLANAR_Y] + hsize * vsize;
}
for_each_ipp_planar(i)
rot_write(addr[i], ROT_DST_BUF_ADDR(i));
break;
case IPP_BUF_DEQUEUE:
for_each_ipp_planar(i)
rot_write(0x0, ROT_DST_BUF_ADDR(i));
break;
default:
break;
}
return 0;
}
static int rotator_init_prop_list(struct exynos_drm_ippdrv *ippdrv)
{
struct drm_exynos_ipp_prop_list *prop_list = &ippdrv->prop_list;
prop_list->version = 1;
prop_list->flip = (1 << EXYNOS_DRM_FLIP_VERTICAL) |
(1 << EXYNOS_DRM_FLIP_HORIZONTAL);
prop_list->degree = (1 << EXYNOS_DRM_DEGREE_0) |
(1 << EXYNOS_DRM_DEGREE_90) |
(1 << EXYNOS_DRM_DEGREE_180) |
(1 << EXYNOS_DRM_DEGREE_270);
prop_list->csc = 0;
prop_list->crop = 0;
prop_list->scale = 0;
return 0;
}
static inline bool rotator_check_drm_fmt(u32 fmt)
{
switch (fmt) {
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_NV12:
return true;
default:
DRM_DEBUG_KMS("not support format\n");
return false;
}
}
static inline bool rotator_check_drm_flip(enum drm_exynos_flip flip)
{
switch (flip) {
case EXYNOS_DRM_FLIP_NONE:
case EXYNOS_DRM_FLIP_VERTICAL:
case EXYNOS_DRM_FLIP_HORIZONTAL:
case EXYNOS_DRM_FLIP_BOTH:
return true;
default:
DRM_DEBUG_KMS("invalid flip\n");
return false;
}
}
static int rotator_ippdrv_check_property(struct device *dev,
struct drm_exynos_ipp_property *property)
{
struct drm_exynos_ipp_config *src_config =
&property->config[EXYNOS_DRM_OPS_SRC];
struct drm_exynos_ipp_config *dst_config =
&property->config[EXYNOS_DRM_OPS_DST];
struct drm_exynos_pos *src_pos = &src_config->pos;
struct drm_exynos_pos *dst_pos = &dst_config->pos;
struct drm_exynos_sz *src_sz = &src_config->sz;
struct drm_exynos_sz *dst_sz = &dst_config->sz;
bool swap = false;
if (src_config->fmt != dst_config->fmt) {
DRM_DEBUG_KMS("not support csc feature\n");
return -EINVAL;
}
if (!rotator_check_drm_fmt(dst_config->fmt)) {
DRM_DEBUG_KMS("invalid format\n");
return -EINVAL;
}
if (src_config->degree != EXYNOS_DRM_DEGREE_0) {
DRM_DEBUG_KMS("not support source-side rotation\n");
return -EINVAL;
}
switch (dst_config->degree) {
case EXYNOS_DRM_DEGREE_90:
case EXYNOS_DRM_DEGREE_270:
swap = true;
case EXYNOS_DRM_DEGREE_0:
case EXYNOS_DRM_DEGREE_180:
break;
default:
DRM_DEBUG_KMS("invalid degree\n");
return -EINVAL;
}
if (src_config->flip != EXYNOS_DRM_FLIP_NONE) {
DRM_DEBUG_KMS("not support source-side flip\n");
return -EINVAL;
}
if (!rotator_check_drm_flip(dst_config->flip)) {
DRM_DEBUG_KMS("invalid flip\n");
return -EINVAL;
}
if ((src_pos->x + src_pos->w > src_sz->hsize) ||
(src_pos->y + src_pos->h > src_sz->vsize)) {
DRM_DEBUG_KMS("out of source buffer bound\n");
return -EINVAL;
}
if (swap) {
if ((dst_pos->x + dst_pos->h > dst_sz->vsize) ||
(dst_pos->y + dst_pos->w > dst_sz->hsize)) {
DRM_DEBUG_KMS("out of destination buffer bound\n");
return -EINVAL;
}
if ((src_pos->w != dst_pos->h) || (src_pos->h != dst_pos->w)) {
DRM_DEBUG_KMS("not support scale feature\n");
return -EINVAL;
}
} else {
if ((dst_pos->x + dst_pos->w > dst_sz->hsize) ||
(dst_pos->y + dst_pos->h > dst_sz->vsize)) {
DRM_DEBUG_KMS("out of destination buffer bound\n");
return -EINVAL;
}
if ((src_pos->w != dst_pos->w) || (src_pos->h != dst_pos->h)) {
DRM_DEBUG_KMS("not support scale feature\n");
return -EINVAL;
}
}
return 0;
}
static int rotator_ippdrv_start(struct device *dev, enum drm_exynos_ipp_cmd cmd)
{
struct rot_context *rot = dev_get_drvdata(dev);
u32 val;
if (rot->suspended) {
DRM_ERROR("suspended state\n");
return -EPERM;
}
if (cmd != IPP_CMD_M2M) {
DRM_ERROR("not support cmd: %d\n", cmd);
return -EINVAL;
}
rotator_reg_set_irq(rot, true);
val = rot_read(ROT_CONTROL);
val |= ROT_CONTROL_START;
rot_write(val, ROT_CONTROL);
return 0;
}
static int rotator_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rot_context *rot;
struct exynos_drm_ippdrv *ippdrv;
int ret;
if (!dev->of_node) {
dev_err(dev, "cannot find of_node.\n");
return -ENODEV;
}
rot = devm_kzalloc(dev, sizeof(*rot), GFP_KERNEL);
if (!rot)
return -ENOMEM;
rot->limit_tbl = (struct rot_limit_table *)
of_device_get_match_data(dev);
rot->regs_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rot->regs = devm_ioremap_resource(dev, rot->regs_res);
if (IS_ERR(rot->regs))
return PTR_ERR(rot->regs);
rot->irq = platform_get_irq(pdev, 0);
if (rot->irq < 0) {
dev_err(dev, "failed to get irq\n");
return rot->irq;
}
ret = devm_request_threaded_irq(dev, rot->irq, NULL,
rotator_irq_handler, IRQF_ONESHOT, "drm_rotator", rot);
if (ret < 0) {
dev_err(dev, "failed to request irq\n");
return ret;
}
rot->clock = devm_clk_get(dev, "rotator");
if (IS_ERR(rot->clock)) {
dev_err(dev, "failed to get clock\n");
return PTR_ERR(rot->clock);
}
pm_runtime_enable(dev);
ippdrv = &rot->ippdrv;
ippdrv->dev = dev;
ippdrv->ops[EXYNOS_DRM_OPS_SRC] = &rot_src_ops;
ippdrv->ops[EXYNOS_DRM_OPS_DST] = &rot_dst_ops;
ippdrv->check_property = rotator_ippdrv_check_property;
ippdrv->start = rotator_ippdrv_start;
ret = rotator_init_prop_list(ippdrv);
if (ret < 0) {
dev_err(dev, "failed to init property list.\n");
goto err_ippdrv_register;
}
DRM_DEBUG_KMS("ippdrv[%p]\n", ippdrv);
platform_set_drvdata(pdev, rot);
ret = exynos_drm_ippdrv_register(ippdrv);
if (ret < 0) {
dev_err(dev, "failed to register drm rotator device\n");
goto err_ippdrv_register;
}
dev_info(dev, "The exynos rotator is probed successfully\n");
return 0;
err_ippdrv_register:
pm_runtime_disable(dev);
return ret;
}
static int rotator_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rot_context *rot = dev_get_drvdata(dev);
struct exynos_drm_ippdrv *ippdrv = &rot->ippdrv;
exynos_drm_ippdrv_unregister(ippdrv);
pm_runtime_disable(dev);
return 0;
}
static int rotator_clk_crtl(struct rot_context *rot, bool enable)
{
if (enable) {
clk_prepare_enable(rot->clock);
rot->suspended = false;
} else {
clk_disable_unprepare(rot->clock);
rot->suspended = true;
}
return 0;
}
static int rotator_runtime_suspend(struct device *dev)
{
struct rot_context *rot = dev_get_drvdata(dev);
return rotator_clk_crtl(rot, false);
}
static int rotator_runtime_resume(struct device *dev)
{
struct rot_context *rot = dev_get_drvdata(dev);
return rotator_clk_crtl(rot, true);
}
