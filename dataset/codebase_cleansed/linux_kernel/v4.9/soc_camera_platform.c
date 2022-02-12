static struct soc_camera_platform_priv *get_priv(struct platform_device *pdev)
{
struct v4l2_subdev *subdev = platform_get_drvdata(pdev);
return container_of(subdev, struct soc_camera_platform_priv, subdev);
}
static int soc_camera_platform_s_stream(struct v4l2_subdev *sd, int enable)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
return p->set_capture(p, enable);
}
static int soc_camera_platform_fill_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *mf = &format->format;
mf->width = p->format.width;
mf->height = p->format.height;
mf->code = p->format.code;
mf->colorspace = p->format.colorspace;
mf->field = p->format.field;
return 0;
}
static int soc_camera_platform_s_power(struct v4l2_subdev *sd, int on)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
return soc_camera_set_power(p->icd->control, &p->icd->sdesc->subdev_desc, NULL, on);
}
static int soc_camera_platform_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
if (code->pad || code->index)
return -EINVAL;
code->code = p->format.code;
return 0;
}
static int soc_camera_platform_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
if (sel->which != V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
case V4L2_SEL_TGT_CROP:
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = p->format.width;
sel->r.height = p->format.height;
return 0;
default:
return -EINVAL;
}
}
static int soc_camera_platform_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
cfg->flags = p->mbus_param;
cfg->type = p->mbus_type;
return 0;
}
static int soc_camera_platform_probe(struct platform_device *pdev)
{
struct soc_camera_host *ici;
struct soc_camera_platform_priv *priv;
struct soc_camera_platform_info *p = pdev->dev.platform_data;
struct soc_camera_device *icd;
if (!p)
return -EINVAL;
if (!p->icd) {
dev_err(&pdev->dev,
"Platform has not set soc_camera_device pointer!\n");
return -EINVAL;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
icd = p->icd;
platform_set_drvdata(pdev, &priv->subdev);
icd->control = &pdev->dev;
ici = to_soc_camera_host(icd->parent);
v4l2_subdev_init(&priv->subdev, &platform_subdev_ops);
v4l2_set_subdevdata(&priv->subdev, p);
strncpy(priv->subdev.name, dev_name(&pdev->dev), V4L2_SUBDEV_NAME_SIZE);
return v4l2_device_register_subdev(&ici->v4l2_dev, &priv->subdev);
}
static int soc_camera_platform_remove(struct platform_device *pdev)
{
struct soc_camera_platform_priv *priv = get_priv(pdev);
struct soc_camera_platform_info *p = v4l2_get_subdevdata(&priv->subdev);
p->icd->control = NULL;
v4l2_device_unregister_subdev(&priv->subdev);
return 0;
}
