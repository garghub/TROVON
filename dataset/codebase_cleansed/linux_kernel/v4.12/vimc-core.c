const struct vimc_pix_map *vimc_pix_map_by_code(u32 code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(vimc_pix_map_list); i++) {
if (vimc_pix_map_list[i].code == code)
return &vimc_pix_map_list[i];
}
return NULL;
}
const struct vimc_pix_map *vimc_pix_map_by_pixelformat(u32 pixelformat)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(vimc_pix_map_list); i++) {
if (vimc_pix_map_list[i].pixelformat == pixelformat)
return &vimc_pix_map_list[i];
}
return NULL;
}
int vimc_propagate_frame(struct media_pad *src, const void *frame)
{
struct media_link *link;
if (!(src->flags & MEDIA_PAD_FL_SOURCE))
return -EINVAL;
list_for_each_entry(link, &src->entity->links, list) {
if (link->source == src &&
(link->flags & MEDIA_LNK_FL_ENABLED)) {
struct vimc_ent_device *ved = NULL;
struct media_entity *entity = link->sink->entity;
if (is_media_entity_v4l2_subdev(entity)) {
struct v4l2_subdev *sd =
container_of(entity, struct v4l2_subdev,
entity);
ved = v4l2_get_subdevdata(sd);
} else if (is_media_entity_v4l2_video_device(entity)) {
struct video_device *vdev =
container_of(entity,
struct video_device,
entity);
ved = video_get_drvdata(vdev);
}
if (ved && ved->process_frame)
ved->process_frame(ved, link->sink, frame);
}
}
return 0;
}
static void vimc_device_unregister(struct vimc_device *vimc)
{
unsigned int i;
media_device_unregister(&vimc->mdev);
for (i = 0; i < vimc->pipe_cfg->num_ents; i++) {
if (vimc->ved[i] && vimc->ved[i]->destroy)
vimc->ved[i]->destroy(vimc->ved[i]);
vimc->ved[i] = NULL;
}
v4l2_device_unregister(&vimc->v4l2_dev);
media_device_cleanup(&vimc->mdev);
}
struct media_pad *vimc_pads_init(u16 num_pads, const unsigned long *pads_flag)
{
struct media_pad *pads;
unsigned int i;
pads = kcalloc(num_pads, sizeof(*pads), GFP_KERNEL);
if (!pads)
return ERR_PTR(-ENOMEM);
for (i = 0; i < num_pads; i++) {
pads[i].index = i;
pads[i].flags = pads_flag[i];
}
return pads;
}
static void vimc_raw_destroy(struct vimc_ent_device *ved)
{
media_device_unregister_entity(ved->ent);
media_entity_cleanup(ved->ent);
vimc_pads_cleanup(ved->pads);
kfree(ved->ent);
kfree(ved);
}
static struct vimc_ent_device *vimc_raw_create(struct v4l2_device *v4l2_dev,
const char *const name,
u16 num_pads,
const unsigned long *pads_flag)
{
struct vimc_ent_device *ved;
int ret;
ved = kzalloc(sizeof(*ved), GFP_KERNEL);
if (!ved)
return ERR_PTR(-ENOMEM);
ved->ent = kzalloc(sizeof(*ved->ent), GFP_KERNEL);
if (!ved->ent) {
ret = -ENOMEM;
goto err_free_ved;
}
ved->pads = vimc_pads_init(num_pads, pads_flag);
if (IS_ERR(ved->pads)) {
ret = PTR_ERR(ved->pads);
goto err_free_ent;
}
ved->ent->name = name;
ved->ent->function = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
ret = media_entity_pads_init(ved->ent, num_pads, ved->pads);
if (ret)
goto err_cleanup_pads;
ret = media_device_register_entity(v4l2_dev->mdev, ved->ent);
if (ret)
goto err_cleanup_entity;
ved->destroy = vimc_raw_destroy;
return ved;
err_cleanup_entity:
media_entity_cleanup(ved->ent);
err_cleanup_pads:
vimc_pads_cleanup(ved->pads);
err_free_ent:
kfree(ved->ent);
err_free_ved:
kfree(ved);
return ERR_PTR(ret);
}
static int vimc_device_register(struct vimc_device *vimc)
{
unsigned int i;
int ret;
vimc->ved = devm_kcalloc(vimc->mdev.dev, vimc->pipe_cfg->num_ents,
sizeof(*vimc->ved), GFP_KERNEL);
if (!vimc->ved)
return -ENOMEM;
vimc->v4l2_dev.mdev = &vimc->mdev;
ret = v4l2_device_register(vimc->mdev.dev, &vimc->v4l2_dev);
if (ret) {
dev_err(vimc->mdev.dev,
"v4l2 device register failed (err=%d)\n", ret);
return ret;
}
for (i = 0; i < vimc->pipe_cfg->num_ents; i++) {
struct vimc_ent_device *(*create_func)(struct v4l2_device *,
const char *const,
u16,
const unsigned long *);
switch (vimc->pipe_cfg->ents[i].node) {
case VIMC_ENT_NODE_SENSOR:
create_func = vimc_sen_create;
break;
case VIMC_ENT_NODE_CAPTURE:
create_func = vimc_cap_create;
break;
case VIMC_ENT_NODE_INPUT:
case VIMC_ENT_NODE_DEBAYER:
case VIMC_ENT_NODE_SCALER:
default:
create_func = vimc_raw_create;
break;
}
vimc->ved[i] = create_func(&vimc->v4l2_dev,
vimc->pipe_cfg->ents[i].name,
vimc->pipe_cfg->ents[i].pads_qty,
vimc->pipe_cfg->ents[i].pads_flag);
if (IS_ERR(vimc->ved[i])) {
ret = PTR_ERR(vimc->ved[i]);
vimc->ved[i] = NULL;
goto err;
}
}
for (i = 0; i < vimc->pipe_cfg->num_links; i++) {
const struct vimc_ent_link *link = &vimc->pipe_cfg->links[i];
ret = media_create_pad_link(vimc->ved[link->src_ent]->ent,
link->src_pad,
vimc->ved[link->sink_ent]->ent,
link->sink_pad,
link->flags);
if (ret)
goto err;
}
ret = media_device_register(&vimc->mdev);
if (ret) {
dev_err(vimc->mdev.dev,
"media device register failed (err=%d)\n", ret);
return ret;
}
ret = v4l2_device_register_subdev_nodes(&vimc->v4l2_dev);
if (ret) {
dev_err(vimc->mdev.dev,
"vimc subdev nodes registration failed (err=%d)\n",
ret);
goto err;
}
return 0;
err:
vimc_device_unregister(vimc);
return ret;
}
static int vimc_probe(struct platform_device *pdev)
{
struct vimc_device *vimc;
int ret;
vimc = kzalloc(sizeof(*vimc), GFP_KERNEL);
if (!vimc)
return -ENOMEM;
vimc->pipe_cfg = &pipe_cfg;
strlcpy(vimc->mdev.model, VIMC_MDEV_MODEL_NAME,
sizeof(vimc->mdev.model));
vimc->mdev.dev = &pdev->dev;
media_device_init(&vimc->mdev);
ret = vimc_device_register(vimc);
if (ret) {
dev_err(vimc->mdev.dev,
"vimc device registration failed (err=%d)\n", ret);
kfree(vimc);
return ret;
}
platform_set_drvdata(pdev, vimc);
return 0;
}
static int vimc_remove(struct platform_device *pdev)
{
struct vimc_device *vimc = platform_get_drvdata(pdev);
vimc_device_unregister(vimc);
kfree(vimc);
return 0;
}
static void vimc_dev_release(struct device *dev)
{
}
static int __init vimc_init(void)
{
int ret;
ret = platform_device_register(&vimc_pdev);
if (ret) {
dev_err(&vimc_pdev.dev,
"platform device registration failed (err=%d)\n", ret);
return ret;
}
ret = platform_driver_register(&vimc_pdrv);
if (ret) {
dev_err(&vimc_pdev.dev,
"platform driver registration failed (err=%d)\n", ret);
platform_device_unregister(&vimc_pdev);
}
return ret;
}
static void __exit vimc_exit(void)
{
platform_driver_unregister(&vimc_pdrv);
platform_device_unregister(&vimc_pdev);
}
