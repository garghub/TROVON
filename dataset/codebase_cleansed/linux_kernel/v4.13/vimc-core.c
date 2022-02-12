static int vimc_create_links(struct vimc_device *vimc)
{
unsigned int i;
int ret;
for (i = 0; i < vimc->pipe_cfg->num_links; i++) {
const struct vimc_ent_link *link = &vimc->pipe_cfg->links[i];
struct vimc_ent_device *ved_src =
platform_get_drvdata(vimc->subdevs[link->src_ent]);
struct vimc_ent_device *ved_sink =
platform_get_drvdata(vimc->subdevs[link->sink_ent]);
ret = media_create_pad_link(ved_src->ent, link->src_pad,
ved_sink->ent, link->sink_pad,
link->flags);
if (ret)
return ret;
}
return 0;
}
static int vimc_comp_bind(struct device *master)
{
struct vimc_device *vimc = container_of(to_platform_device(master),
struct vimc_device, pdev);
int ret;
dev_dbg(master, "bind");
ret = v4l2_device_register(vimc->mdev.dev, &vimc->v4l2_dev);
if (ret) {
dev_err(vimc->mdev.dev,
"v4l2 device register failed (err=%d)\n", ret);
return ret;
}
ret = component_bind_all(master, &vimc->v4l2_dev);
if (ret)
goto err_v4l2_unregister;
ret = vimc_create_links(vimc);
if (ret)
goto err_comp_unbind_all;
ret = media_device_register(&vimc->mdev);
if (ret) {
dev_err(vimc->mdev.dev,
"media device register failed (err=%d)\n", ret);
goto err_comp_unbind_all;
}
ret = v4l2_device_register_subdev_nodes(&vimc->v4l2_dev);
if (ret) {
dev_err(vimc->mdev.dev,
"vimc subdev nodes registration failed (err=%d)\n",
ret);
goto err_mdev_unregister;
}
return 0;
err_mdev_unregister:
media_device_unregister(&vimc->mdev);
err_comp_unbind_all:
component_unbind_all(master, NULL);
err_v4l2_unregister:
v4l2_device_unregister(&vimc->v4l2_dev);
return ret;
}
static void vimc_comp_unbind(struct device *master)
{
struct vimc_device *vimc = container_of(to_platform_device(master),
struct vimc_device, pdev);
dev_dbg(master, "unbind");
media_device_unregister(&vimc->mdev);
component_unbind_all(master, NULL);
v4l2_device_unregister(&vimc->v4l2_dev);
}
static int vimc_comp_compare(struct device *comp, void *data)
{
const struct platform_device *pdev = to_platform_device(comp);
const char *name = data;
return !strcmp(pdev->dev.platform_data, name);
}
static struct component_match *vimc_add_subdevs(struct vimc_device *vimc)
{
struct component_match *match = NULL;
struct vimc_platform_data pdata;
int i;
for (i = 0; i < vimc->pipe_cfg->num_ents; i++) {
dev_dbg(&vimc->pdev.dev, "new pdev for %s\n",
vimc->pipe_cfg->ents[i].drv);
strlcpy(pdata.entity_name, vimc->pipe_cfg->ents[i].name,
sizeof(pdata.entity_name));
vimc->subdevs[i] = platform_device_register_data(&vimc->pdev.dev,
vimc->pipe_cfg->ents[i].drv,
PLATFORM_DEVID_AUTO,
&pdata,
sizeof(pdata));
if (!vimc->subdevs[i]) {
while (--i >= 0)
platform_device_unregister(vimc->subdevs[i]);
return ERR_PTR(-ENOMEM);
}
component_match_add(&vimc->pdev.dev, &match, vimc_comp_compare,
(void *)vimc->pipe_cfg->ents[i].name);
}
return match;
}
static void vimc_rm_subdevs(struct vimc_device *vimc)
{
unsigned int i;
for (i = 0; i < vimc->pipe_cfg->num_ents; i++)
platform_device_unregister(vimc->subdevs[i]);
}
static int vimc_probe(struct platform_device *pdev)
{
struct vimc_device *vimc = container_of(pdev, struct vimc_device, pdev);
struct component_match *match = NULL;
int ret;
dev_dbg(&pdev->dev, "probe");
vimc->subdevs = devm_kcalloc(&vimc->pdev.dev, vimc->pipe_cfg->num_ents,
sizeof(*vimc->subdevs), GFP_KERNEL);
if (!vimc->subdevs)
return -ENOMEM;
match = vimc_add_subdevs(vimc);
if (IS_ERR(match))
return PTR_ERR(match);
vimc->v4l2_dev.mdev = &vimc->mdev;
strlcpy(vimc->mdev.model, VIMC_MDEV_MODEL_NAME,
sizeof(vimc->mdev.model));
vimc->mdev.dev = &pdev->dev;
media_device_init(&vimc->mdev);
ret = component_master_add_with_match(&pdev->dev, &vimc_comp_ops,
match);
if (ret) {
media_device_cleanup(&vimc->mdev);
vimc_rm_subdevs(vimc);
kfree(vimc);
return ret;
}
return 0;
}
static int vimc_remove(struct platform_device *pdev)
{
struct vimc_device *vimc = container_of(pdev, struct vimc_device, pdev);
dev_dbg(&pdev->dev, "remove");
component_master_del(&pdev->dev, &vimc_comp_ops);
vimc_rm_subdevs(vimc);
return 0;
}
static void vimc_dev_release(struct device *dev)
{
}
static int __init vimc_init(void)
{
int ret;
ret = platform_device_register(&vimc_dev.pdev);
if (ret) {
dev_err(&vimc_dev.pdev.dev,
"platform device registration failed (err=%d)\n", ret);
return ret;
}
ret = platform_driver_register(&vimc_pdrv);
if (ret) {
dev_err(&vimc_dev.pdev.dev,
"platform driver registration failed (err=%d)\n", ret);
platform_driver_unregister(&vimc_pdrv);
return ret;
}
return 0;
}
static void __exit vimc_exit(void)
{
platform_driver_unregister(&vimc_pdrv);
platform_device_unregister(&vimc_dev.pdev);
}
