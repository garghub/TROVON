static struct soc_camera_platform_priv *get_priv(struct platform_device *pdev)
{
struct v4l2_subdev *subdev = platform_get_drvdata(pdev);
return container_of(subdev, struct soc_camera_platform_priv, subdev);
}
static struct soc_camera_platform_info *get_info(struct soc_camera_device *icd)
{
struct platform_device *pdev =
to_platform_device(to_soc_camera_control(icd));
return pdev->dev.platform_data;
}
static int soc_camera_platform_s_stream(struct v4l2_subdev *sd, int enable)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
return p->set_capture(p, enable);
}
static int soc_camera_platform_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
return 0;
}
static unsigned long
soc_camera_platform_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_platform_info *p = get_info(icd);
return p->bus_param;
}
static int soc_camera_platform_fill_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
mf->width = p->format.width;
mf->height = p->format.height;
mf->code = p->format.code;
mf->colorspace = p->format.colorspace;
mf->field = p->format.field;
return 0;
}
static int soc_camera_platform_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
if (index)
return -EINVAL;
*code = p->format.code;
return 0;
}
static int soc_camera_platform_g_crop(struct v4l2_subdev *sd,
struct v4l2_crop *a)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
a->c.left = 0;
a->c.top = 0;
a->c.width = p->format.width;
a->c.height = p->format.height;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static int soc_camera_platform_cropcap(struct v4l2_subdev *sd,
struct v4l2_cropcap *a)
{
struct soc_camera_platform_info *p = v4l2_get_subdevdata(sd);
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = p->format.width;
a->bounds.height = p->format.height;
a->defrect = a->bounds;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static int soc_camera_platform_probe(struct platform_device *pdev)
{
struct soc_camera_host *ici;
struct soc_camera_platform_priv *priv;
struct soc_camera_platform_info *p = pdev->dev.platform_data;
struct soc_camera_device *icd;
int ret;
if (!p)
return -EINVAL;
if (!p->icd) {
dev_err(&pdev->dev,
"Platform has not set soc_camera_device pointer!\n");
return -EINVAL;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
icd = p->icd;
platform_set_drvdata(pdev, &priv->subdev);
icd->control = &pdev->dev;
icd->ops = &soc_camera_platform_ops;
ici = to_soc_camera_host(icd->parent);
v4l2_subdev_init(&priv->subdev, &platform_subdev_ops);
v4l2_set_subdevdata(&priv->subdev, p);
strncpy(priv->subdev.name, dev_name(&pdev->dev), V4L2_SUBDEV_NAME_SIZE);
ret = v4l2_device_register_subdev(&ici->v4l2_dev, &priv->subdev);
if (ret)
goto evdrs;
return ret;
evdrs:
icd->ops = NULL;
platform_set_drvdata(pdev, NULL);
kfree(priv);
return ret;
}
static int soc_camera_platform_remove(struct platform_device *pdev)
{
struct soc_camera_platform_priv *priv = get_priv(pdev);
struct soc_camera_platform_info *p = pdev->dev.platform_data;
struct soc_camera_device *icd = p->icd;
v4l2_device_unregister_subdev(&priv->subdev);
icd->ops = NULL;
platform_set_drvdata(pdev, NULL);
kfree(priv);
return 0;
}
static int __init soc_camera_platform_module_init(void)
{
return platform_driver_register(&soc_camera_platform_driver);
}
static void __exit soc_camera_platform_module_exit(void)
{
platform_driver_unregister(&soc_camera_platform_driver);
}
