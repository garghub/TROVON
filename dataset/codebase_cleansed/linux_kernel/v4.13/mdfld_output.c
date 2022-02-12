int mdfld_get_panel_type(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
return dev_priv->mdfld_panel_id;
}
static void mdfld_init_panel(struct drm_device *dev, int mipi_pipe,
int p_type)
{
switch (p_type) {
case TPO_VID:
mdfld_dsi_output_init(dev, mipi_pipe, &mdfld_tpo_vid_funcs);
break;
case TC35876X:
tc35876x_init(dev);
mdfld_dsi_output_init(dev, mipi_pipe, &mdfld_tc35876x_funcs);
break;
case TMD_VID:
mdfld_dsi_output_init(dev, mipi_pipe, &mdfld_tmd_vid_funcs);
break;
case HDMI:
break;
}
}
int mdfld_output_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
dev_priv->mdfld_panel_id = TC35876X;
mdfld_init_panel(dev, 0, dev_priv->mdfld_panel_id);
mdfld_init_panel(dev, 1, HDMI);
return 0;
}
