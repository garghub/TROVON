int mdfld_get_panel_type(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
return dev_priv->panel_id;
}
int mdfld_panel_dpi(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
switch (dev_priv->panel_id) {
case TMD_VID:
case TPO_VID:
case PYR_VID:
return true;
case TMD_CMD:
case TPO_CMD:
case PYR_CMD:
default:
return false;
}
}
static int init_panel(struct drm_device *dev, int mipi_pipe, int p_type)
{
struct panel_funcs *p_cmd_funcs;
struct panel_funcs *p_vid_funcs;
p_cmd_funcs = kzalloc(sizeof(struct panel_funcs), GFP_KERNEL);
if (p_cmd_funcs == NULL)
return -ENODEV;
p_vid_funcs = kzalloc(sizeof(struct panel_funcs), GFP_KERNEL);
if (p_vid_funcs == NULL) {
kfree(p_cmd_funcs);
return -ENODEV;
}
switch (p_type) {
case TPO_CMD:
tpo_cmd_init(dev, p_cmd_funcs);
mdfld_dsi_output_init(dev, mipi_pipe, NULL, p_cmd_funcs, NULL);
break;
case TPO_VID:
tpo_vid_init(dev, p_vid_funcs);
mdfld_dsi_output_init(dev, mipi_pipe, NULL, NULL, p_vid_funcs);
break;
case TMD_CMD:
mdfld_dsi_output_init(dev, mipi_pipe, NULL, p_cmd_funcs, NULL);
break;
case TMD_VID:
tmd_vid_init(dev, p_vid_funcs);
mdfld_dsi_output_init(dev, mipi_pipe, NULL, NULL, p_vid_funcs);
break;
case PYR_CMD:
pyr_cmd_init(dev, p_cmd_funcs);
mdfld_dsi_output_init(dev, mipi_pipe, NULL, p_cmd_funcs, NULL);
break;
case PYR_VID:
mdfld_dsi_output_init(dev, mipi_pipe, NULL, NULL, p_vid_funcs);
break;
case TPO:
tpo_cmd_init(dev, p_cmd_funcs);
tpo_vid_init(dev, p_vid_funcs);
mdfld_dsi_output_init(dev, mipi_pipe, NULL, p_cmd_funcs,
p_vid_funcs);
break;
case TMD:
break;
case PYR:
break;
#if 0
case HDMI:
dev_dbg(dev->dev, "Initializing HDMI");
mdfld_hdmi_init(dev, &dev_priv->mode_dev);
break;
#endif
default:
dev_err(dev->dev, "Unsupported interface %d", p_type);
return -ENODEV;
}
return 0;
}
int mdfld_output_init(struct drm_device *dev)
{
int type;
type = mdfld_get_panel_type(dev, 0);
dev_info(dev->dev, "panel 1: type is %d\n", type);
init_panel(dev, 0, type);
if (mdfld_dual_mipi) {
type = mdfld_get_panel_type(dev, 2);
dev_info(dev->dev, "panel 2: type is %d\n", type);
init_panel(dev, 2, type);
}
if (mdfld_hdmi)
init_panel(dev, 0, HDMI);
return 0;
}
void mdfld_output_setup(struct drm_device *dev)
{
if (IS_MFLD(dev)) {
if (mdfld_dpu)
mdfld_dbi_dpu_init(dev);
else
mdfld_dbi_dsr_init(dev);
}
}
