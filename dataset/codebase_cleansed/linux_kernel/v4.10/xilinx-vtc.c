static inline void xvtc_gen_write(struct xvtc_device *xvtc, u32 addr, u32 value)
{
xvip_write(&xvtc->xvip, XVTC_GENERATOR_OFFSET + addr, value);
}
int xvtc_generator_start(struct xvtc_device *xvtc,
const struct xvtc_config *config)
{
int ret;
if (!xvtc->has_generator)
return -ENXIO;
ret = clk_prepare_enable(xvtc->xvip.clk);
if (ret < 0)
return ret;
xvtc_gen_write(xvtc, XVTC_POLARITY,
XVTC_POLARITY_ACTIVE_CHROMA_POL |
XVTC_POLARITY_ACTIVE_VIDEO_POL |
XVTC_POLARITY_HSYNC_POL | XVTC_POLARITY_VSYNC_POL |
XVTC_POLARITY_HBLANK_POL | XVTC_POLARITY_VBLANK_POL);
xvtc_gen_write(xvtc, XVTC_ENCODING, 0);
xvtc_gen_write(xvtc, XVTC_ACTIVE_SIZE,
(config->vblank_start << XVTC_ACTIVE_VSIZE_SHIFT) |
(config->hblank_start << XVTC_ACTIVE_HSIZE_SHIFT));
xvtc_gen_write(xvtc, XVTC_HSIZE, config->hsize);
xvtc_gen_write(xvtc, XVTC_VSIZE, config->vsize);
xvtc_gen_write(xvtc, XVTC_HSYNC,
(config->hsync_end << XVTC_HSYNC_END_SHIFT) |
(config->hsync_start << XVTC_HSYNC_START_SHIFT));
xvtc_gen_write(xvtc, XVTC_F0_VBLANK_H, 0);
xvtc_gen_write(xvtc, XVTC_F0_VSYNC_V,
(config->vsync_end << XVTC_F0_VSYNC_VEND_SHIFT) |
(config->vsync_start << XVTC_F0_VSYNC_VSTART_SHIFT));
xvtc_gen_write(xvtc, XVTC_F0_VSYNC_H, 0);
xvip_write(&xvtc->xvip, XVIP_CTRL_CONTROL,
XVTC_CONTROL_ACTIVE_CHROMA_POL_SRC |
XVTC_CONTROL_ACTIVE_VIDEO_POL_SRC |
XVTC_CONTROL_HSYNC_POL_SRC | XVTC_CONTROL_VSYNC_POL_SRC |
XVTC_CONTROL_HBLANK_POL_SRC | XVTC_CONTROL_VBLANK_POL_SRC |
XVTC_CONTROL_CHROMA_SRC | XVTC_CONTROL_VBLANK_HOFF_SRC |
XVTC_CONTROL_VSYNC_END_SRC | XVTC_CONTROL_VSYNC_START_SRC |
XVTC_CONTROL_ACTIVE_VSIZE_SRC |
XVTC_CONTROL_FRAME_VSIZE_SRC | XVTC_CONTROL_HSYNC_END_SRC |
XVTC_CONTROL_HSYNC_START_SRC |
XVTC_CONTROL_ACTIVE_HSIZE_SRC |
XVTC_CONTROL_FRAME_HSIZE_SRC | XVTC_CONTROL_GEN_ENABLE |
XVIP_CTRL_CONTROL_REG_UPDATE);
return 0;
}
int xvtc_generator_stop(struct xvtc_device *xvtc)
{
if (!xvtc->has_generator)
return -ENXIO;
xvip_write(&xvtc->xvip, XVIP_CTRL_CONTROL, 0);
clk_disable_unprepare(xvtc->xvip.clk);
return 0;
}
struct xvtc_device *xvtc_of_get(struct device_node *np)
{
struct device_node *xvtc_node;
struct xvtc_device *found = NULL;
struct xvtc_device *xvtc;
if (!of_find_property(np, "xlnx,vtc", NULL))
return NULL;
xvtc_node = of_parse_phandle(np, "xlnx,vtc", 0);
if (xvtc_node == NULL)
return ERR_PTR(-EINVAL);
mutex_lock(&xvtc_lock);
list_for_each_entry(xvtc, &xvtc_list, list) {
if (xvtc->xvip.dev->of_node == xvtc_node) {
found = xvtc;
break;
}
}
mutex_unlock(&xvtc_lock);
of_node_put(xvtc_node);
if (!found)
return ERR_PTR(-EPROBE_DEFER);
return found;
}
void xvtc_put(struct xvtc_device *xvtc)
{
}
static void xvtc_register_device(struct xvtc_device *xvtc)
{
mutex_lock(&xvtc_lock);
list_add_tail(&xvtc->list, &xvtc_list);
mutex_unlock(&xvtc_lock);
}
static void xvtc_unregister_device(struct xvtc_device *xvtc)
{
mutex_lock(&xvtc_lock);
list_del(&xvtc->list);
mutex_unlock(&xvtc_lock);
}
static int xvtc_parse_of(struct xvtc_device *xvtc)
{
struct device_node *node = xvtc->xvip.dev->of_node;
xvtc->has_detector = of_property_read_bool(node, "xlnx,detector");
xvtc->has_generator = of_property_read_bool(node, "xlnx,generator");
return 0;
}
static int xvtc_probe(struct platform_device *pdev)
{
struct xvtc_device *xvtc;
int ret;
xvtc = devm_kzalloc(&pdev->dev, sizeof(*xvtc), GFP_KERNEL);
if (!xvtc)
return -ENOMEM;
xvtc->xvip.dev = &pdev->dev;
ret = xvtc_parse_of(xvtc);
if (ret < 0)
return ret;
ret = xvip_init_resources(&xvtc->xvip);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, xvtc);
xvip_print_version(&xvtc->xvip);
xvtc_register_device(xvtc);
return 0;
}
static int xvtc_remove(struct platform_device *pdev)
{
struct xvtc_device *xvtc = platform_get_drvdata(pdev);
xvtc_unregister_device(xvtc);
xvip_cleanup_resources(&xvtc->xvip);
return 0;
}
