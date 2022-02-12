static int imx_ic_probe(struct platform_device *pdev)
{
struct imx_media_internal_sd_platformdata *pdata;
struct imx_ic_priv *priv;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, &priv->sd);
priv->dev = &pdev->dev;
pdata = priv->dev->platform_data;
priv->ipu_id = pdata->ipu_id;
switch (pdata->grp_id) {
case IMX_MEDIA_GRP_ID_IC_PRP:
priv->task_id = IC_TASK_PRP;
break;
case IMX_MEDIA_GRP_ID_IC_PRPENC:
priv->task_id = IC_TASK_ENCODER;
break;
case IMX_MEDIA_GRP_ID_IC_PRPVF:
priv->task_id = IC_TASK_VIEWFINDER;
break;
default:
return -EINVAL;
}
v4l2_subdev_init(&priv->sd, ic_ops[priv->task_id]->subdev_ops);
v4l2_set_subdevdata(&priv->sd, priv);
priv->sd.internal_ops = ic_ops[priv->task_id]->internal_ops;
priv->sd.entity.ops = ic_ops[priv->task_id]->entity_ops;
priv->sd.entity.function = MEDIA_ENT_F_PROC_VIDEO_SCALER;
priv->sd.dev = &pdev->dev;
priv->sd.owner = THIS_MODULE;
priv->sd.flags = V4L2_SUBDEV_FL_HAS_DEVNODE | V4L2_SUBDEV_FL_HAS_EVENTS;
priv->sd.grp_id = pdata->grp_id;
strncpy(priv->sd.name, pdata->sd_name, sizeof(priv->sd.name));
ret = ic_ops[priv->task_id]->init(priv);
if (ret)
return ret;
ret = v4l2_async_register_subdev(&priv->sd);
if (ret)
ic_ops[priv->task_id]->remove(priv);
return ret;
}
static int imx_ic_remove(struct platform_device *pdev)
{
struct v4l2_subdev *sd = platform_get_drvdata(pdev);
struct imx_ic_priv *priv = container_of(sd, struct imx_ic_priv, sd);
v4l2_info(sd, "Removing\n");
ic_ops[priv->task_id]->remove(priv);
v4l2_async_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
return 0;
}
