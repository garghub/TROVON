void fimc_pipeline_prepare(struct fimc_dev *fimc, struct media_entity *me)
{
struct media_entity_graph graph;
struct v4l2_subdev *sd;
media_entity_graph_walk_start(&graph, me);
while ((me = media_entity_graph_walk_next(&graph))) {
if (media_entity_type(me) != MEDIA_ENT_T_V4L2_SUBDEV)
continue;
sd = media_entity_to_v4l2_subdev(me);
if (sd->grp_id == SENSOR_GROUP_ID)
fimc->pipeline.sensor = sd;
else if (sd->grp_id == CSIS_GROUP_ID)
fimc->pipeline.csis = sd;
}
}
static int __subdev_set_power(struct v4l2_subdev *sd, int on)
{
int *use_count;
int ret;
if (sd == NULL)
return -ENXIO;
use_count = &sd->entity.use_count;
if (on && (*use_count)++ > 0)
return 0;
else if (!on && (*use_count == 0 || --(*use_count) > 0))
return 0;
ret = v4l2_subdev_call(sd, core, s_power, on);
return ret != -ENOIOCTLCMD ? ret : 0;
}
int fimc_pipeline_s_power(struct fimc_dev *fimc, int state)
{
int ret = 0;
if (fimc->pipeline.sensor == NULL)
return -ENXIO;
if (state) {
ret = __subdev_set_power(fimc->pipeline.csis, 1);
if (ret && ret != -ENXIO)
return ret;
return __subdev_set_power(fimc->pipeline.sensor, 1);
}
ret = __subdev_set_power(fimc->pipeline.sensor, 0);
if (ret)
return ret;
ret = __subdev_set_power(fimc->pipeline.csis, 0);
return ret == -ENXIO ? 0 : ret;
}
static int __fimc_pipeline_initialize(struct fimc_dev *fimc,
struct media_entity *me, bool prep)
{
int ret;
if (prep)
fimc_pipeline_prepare(fimc, me);
if (fimc->pipeline.sensor == NULL)
return -EINVAL;
ret = fimc_md_set_camclk(fimc->pipeline.sensor, true);
if (ret)
return ret;
return fimc_pipeline_s_power(fimc, 1);
}
int fimc_pipeline_initialize(struct fimc_dev *fimc, struct media_entity *me,
bool prep)
{
int ret;
mutex_lock(&me->parent->graph_mutex);
ret = __fimc_pipeline_initialize(fimc, me, prep);
mutex_unlock(&me->parent->graph_mutex);
return ret;
}
int __fimc_pipeline_shutdown(struct fimc_dev *fimc)
{
int ret = 0;
if (fimc->pipeline.sensor) {
ret = fimc_pipeline_s_power(fimc, 0);
fimc_md_set_camclk(fimc->pipeline.sensor, false);
}
return ret == -ENXIO ? 0 : ret;
}
int fimc_pipeline_shutdown(struct fimc_dev *fimc)
{
struct media_entity *me = &fimc->vid_cap.vfd->entity;
int ret;
mutex_lock(&me->parent->graph_mutex);
ret = __fimc_pipeline_shutdown(fimc);
mutex_unlock(&me->parent->graph_mutex);
return ret;
}
int fimc_pipeline_s_stream(struct fimc_dev *fimc, int on)
{
struct fimc_pipeline *p = &fimc->pipeline;
int ret = 0;
if (p->sensor == NULL)
return -ENODEV;
if ((on && p->csis) || !on)
ret = v4l2_subdev_call(on ? p->csis : p->sensor,
video, s_stream, on);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
if ((!on && p->csis) || on)
ret = v4l2_subdev_call(on ? p->sensor : p->csis,
video, s_stream, on);
return ret == -ENOIOCTLCMD ? 0 : ret;
}
static struct v4l2_subdev *fimc_md_register_sensor(struct fimc_md *fmd,
struct fimc_sensor_info *s_info)
{
struct i2c_adapter *adapter;
struct v4l2_subdev *sd = NULL;
if (!s_info || !fmd)
return NULL;
adapter = i2c_get_adapter(s_info->pdata->i2c_bus_num);
if (!adapter)
return NULL;
sd = v4l2_i2c_new_subdev_board(&fmd->v4l2_dev, adapter,
s_info->pdata->board_info, NULL);
if (IS_ERR_OR_NULL(sd)) {
i2c_put_adapter(adapter);
v4l2_err(&fmd->v4l2_dev, "Failed to acquire subdev\n");
return NULL;
}
v4l2_set_subdev_hostdata(sd, s_info);
sd->grp_id = SENSOR_GROUP_ID;
v4l2_info(&fmd->v4l2_dev, "Registered sensor subdevice %s\n",
s_info->pdata->board_info->type);
return sd;
}
static void fimc_md_unregister_sensor(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct i2c_adapter *adapter;
if (!client)
return;
v4l2_device_unregister_subdev(sd);
adapter = client->adapter;
i2c_unregister_device(client);
if (adapter)
i2c_put_adapter(adapter);
}
static int fimc_md_register_sensor_entities(struct fimc_md *fmd)
{
struct s5p_platform_fimc *pdata = fmd->pdev->dev.platform_data;
struct fimc_dev *fd = NULL;
int num_clients, ret, i;
for (i = 0; !fd && i < ARRAY_SIZE(fmd->fimc); i++)
if (fmd->fimc[i])
fd = fmd->fimc[i];
if (!fd)
return -ENXIO;
ret = pm_runtime_get_sync(&fd->pdev->dev);
if (ret < 0)
return ret;
WARN_ON(pdata->num_clients > ARRAY_SIZE(fmd->sensor));
num_clients = min_t(u32, pdata->num_clients, ARRAY_SIZE(fmd->sensor));
fmd->num_sensors = num_clients;
for (i = 0; i < num_clients; i++) {
fmd->sensor[i].pdata = &pdata->isp_info[i];
ret = __fimc_md_set_camclk(fmd, &fmd->sensor[i], true);
if (ret)
break;
fmd->sensor[i].subdev =
fimc_md_register_sensor(fmd, &fmd->sensor[i]);
ret = __fimc_md_set_camclk(fmd, &fmd->sensor[i], false);
if (ret)
break;
}
pm_runtime_put(&fd->pdev->dev);
return ret;
}
static int fimc_register_callback(struct device *dev, void *p)
{
struct fimc_dev *fimc = dev_get_drvdata(dev);
struct fimc_md *fmd = p;
int ret;
if (!fimc || !fimc->pdev)
return 0;
if (fimc->pdev->id < 0 || fimc->pdev->id >= FIMC_MAX_DEVS)
return 0;
fmd->fimc[fimc->pdev->id] = fimc;
ret = fimc_register_m2m_device(fimc, &fmd->v4l2_dev);
if (ret)
return ret;
ret = fimc_register_capture_device(fimc, &fmd->v4l2_dev);
if (!ret)
fimc->vid_cap.user_subdev_api = fmd->user_subdev_api;
return ret;
}
static int csis_register_callback(struct device *dev, void *p)
{
struct v4l2_subdev *sd = dev_get_drvdata(dev);
struct platform_device *pdev;
struct fimc_md *fmd = p;
int id, ret;
if (!sd)
return 0;
pdev = v4l2_get_subdevdata(sd);
if (!pdev || pdev->id < 0 || pdev->id >= CSIS_MAX_ENTITIES)
return 0;
v4l2_info(sd, "csis%d sd: %s\n", pdev->id, sd->name);
id = pdev->id < 0 ? 0 : pdev->id;
fmd->csis[id].sd = sd;
sd->grp_id = CSIS_GROUP_ID;
ret = v4l2_device_register_subdev(&fmd->v4l2_dev, sd);
if (ret)
v4l2_err(&fmd->v4l2_dev,
"Failed to register CSIS subdevice: %d\n", ret);
return ret;
}
static int fimc_md_register_platform_entities(struct fimc_md *fmd)
{
struct device_driver *driver;
int ret;
driver = driver_find(FIMC_MODULE_NAME, &platform_bus_type);
if (!driver)
return -ENODEV;
ret = driver_for_each_device(driver, NULL, fmd,
fimc_register_callback);
if (ret)
return ret;
driver = driver_find(CSIS_DRIVER_NAME, &platform_bus_type);
if (driver)
ret = driver_for_each_device(driver, NULL, fmd,
csis_register_callback);
return ret;
}
static void fimc_md_unregister_entities(struct fimc_md *fmd)
{
int i;
for (i = 0; i < FIMC_MAX_DEVS; i++) {
if (fmd->fimc[i] == NULL)
continue;
fimc_unregister_m2m_device(fmd->fimc[i]);
fimc_unregister_capture_device(fmd->fimc[i]);
fmd->fimc[i] = NULL;
}
for (i = 0; i < CSIS_MAX_ENTITIES; i++) {
if (fmd->csis[i].sd == NULL)
continue;
v4l2_device_unregister_subdev(fmd->csis[i].sd);
fmd->csis[i].sd = NULL;
}
for (i = 0; i < fmd->num_sensors; i++) {
if (fmd->sensor[i].subdev == NULL)
continue;
fimc_md_unregister_sensor(fmd->sensor[i].subdev);
fmd->sensor[i].subdev = NULL;
}
}
static int fimc_md_register_video_nodes(struct fimc_md *fmd)
{
struct video_device *vdev;
int i, ret = 0;
for (i = 0; i < FIMC_MAX_DEVS && !ret; i++) {
if (!fmd->fimc[i])
continue;
vdev = fmd->fimc[i]->m2m.vfd;
if (vdev) {
ret = video_register_device(vdev, VFL_TYPE_GRABBER, -1);
if (ret)
break;
v4l2_info(&fmd->v4l2_dev, "Registered %s as /dev/%s\n",
vdev->name, video_device_node_name(vdev));
}
vdev = fmd->fimc[i]->vid_cap.vfd;
if (vdev == NULL)
continue;
ret = video_register_device(vdev, VFL_TYPE_GRABBER, -1);
v4l2_info(&fmd->v4l2_dev, "Registered %s as /dev/%s\n",
vdev->name, video_device_node_name(vdev));
}
return ret;
}
static int __fimc_md_create_fimc_links(struct fimc_md *fmd,
struct media_entity *source,
struct v4l2_subdev *sensor,
int pad, int fimc_id)
{
struct fimc_sensor_info *s_info;
struct media_entity *sink;
unsigned int flags;
int ret, i;
for (i = 0; i < FIMC_MAX_DEVS; i++) {
if (!fmd->fimc[i])
break;
if (sensor->grp_id == SENSOR_GROUP_ID &&
!fmd->fimc[i]->variant->has_cam_if)
continue;
flags = (i == fimc_id) ? MEDIA_LNK_FL_ENABLED : 0;
sink = &fmd->fimc[i]->vid_cap.subdev->entity;
ret = media_entity_create_link(source, pad, sink,
FIMC_SD_PAD_SINK, flags);
if (ret)
return ret;
ret = media_entity_call(sink, link_setup, &sink->pads[0],
&source->pads[pad], flags);
if (ret)
break;
v4l2_info(&fmd->v4l2_dev, "created link [%s] %c> [%s]",
source->name, flags ? '=' : '-', sink->name);
if (flags == 0)
continue;
s_info = v4l2_get_subdev_hostdata(sensor);
if (!WARN_ON(s_info == NULL)) {
unsigned long irq_flags;
spin_lock_irqsave(&fmd->slock, irq_flags);
s_info->host = fmd->fimc[i];
spin_unlock_irqrestore(&fmd->slock, irq_flags);
}
}
return 0;
}
static int fimc_md_create_links(struct fimc_md *fmd)
{
struct v4l2_subdev *sensor, *csis;
struct s5p_fimc_isp_info *pdata;
struct fimc_sensor_info *s_info;
struct media_entity *source, *sink;
int i, pad, fimc_id = 0;
int ret = 0;
u32 flags;
for (i = 0; i < fmd->num_sensors; i++) {
if (fmd->sensor[i].subdev == NULL)
continue;
sensor = fmd->sensor[i].subdev;
s_info = v4l2_get_subdev_hostdata(sensor);
if (!s_info || !s_info->pdata)
continue;
source = NULL;
pdata = s_info->pdata;
switch (pdata->bus_type) {
case FIMC_MIPI_CSI2:
if (WARN(pdata->mux_id >= CSIS_MAX_ENTITIES,
"Wrong CSI channel id: %d\n", pdata->mux_id))
return -EINVAL;
csis = fmd->csis[pdata->mux_id].sd;
if (WARN(csis == NULL,
"MIPI-CSI interface specified "
"but s5p-csis module is not loaded!\n"))
return -EINVAL;
ret = media_entity_create_link(&sensor->entity, 0,
&csis->entity, CSIS_PAD_SINK,
MEDIA_LNK_FL_IMMUTABLE |
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
v4l2_info(&fmd->v4l2_dev, "created link [%s] => [%s]",
sensor->entity.name, csis->entity.name);
source = &csis->entity;
pad = CSIS_PAD_SOURCE;
break;
case FIMC_ITU_601...FIMC_ITU_656:
source = &sensor->entity;
pad = 0;
break;
default:
v4l2_err(&fmd->v4l2_dev, "Wrong bus_type: %x\n",
pdata->bus_type);
return -EINVAL;
}
if (source == NULL)
continue;
ret = __fimc_md_create_fimc_links(fmd, source, sensor, pad,
fimc_id++);
}
flags = MEDIA_LNK_FL_IMMUTABLE | MEDIA_LNK_FL_ENABLED;
for (i = 0; i < FIMC_MAX_DEVS; i++) {
if (!fmd->fimc[i])
continue;
source = &fmd->fimc[i]->vid_cap.subdev->entity;
sink = &fmd->fimc[i]->vid_cap.vfd->entity;
ret = media_entity_create_link(source, FIMC_SD_PAD_SOURCE,
sink, 0, flags);
if (ret)
break;
}
return ret;
}
static int fimc_md_get_clocks(struct fimc_md *fmd)
{
char clk_name[32];
struct clk *clock;
int i;
for (i = 0; i < FIMC_MAX_CAMCLKS; i++) {
snprintf(clk_name, sizeof(clk_name), "sclk_cam%u", i);
clock = clk_get(NULL, clk_name);
if (IS_ERR_OR_NULL(clock)) {
v4l2_err(&fmd->v4l2_dev, "Failed to get clock: %s",
clk_name);
return -ENXIO;
}
fmd->camclk[i].clock = clock;
}
return 0;
}
static void fimc_md_put_clocks(struct fimc_md *fmd)
{
int i = FIMC_MAX_CAMCLKS;
while (--i >= 0) {
if (IS_ERR_OR_NULL(fmd->camclk[i].clock))
continue;
clk_put(fmd->camclk[i].clock);
fmd->camclk[i].clock = NULL;
}
}
static int __fimc_md_set_camclk(struct fimc_md *fmd,
struct fimc_sensor_info *s_info,
bool on)
{
struct s5p_fimc_isp_info *pdata = s_info->pdata;
struct fimc_camclk_info *camclk;
int ret = 0;
if (WARN_ON(pdata->clk_id >= FIMC_MAX_CAMCLKS) || fmd == NULL)
return -EINVAL;
if (s_info->clk_on == on)
return 0;
camclk = &fmd->camclk[pdata->clk_id];
dbg("camclk %d, f: %lu, clk: %p, on: %d",
pdata->clk_id, pdata->clk_frequency, camclk, on);
if (on) {
if (camclk->use_count > 0 &&
camclk->frequency != pdata->clk_frequency)
return -EINVAL;
if (camclk->use_count++ == 0) {
clk_set_rate(camclk->clock, pdata->clk_frequency);
camclk->frequency = pdata->clk_frequency;
ret = clk_enable(camclk->clock);
}
s_info->clk_on = 1;
dbg("Enabled camclk %d: f: %lu", pdata->clk_id,
clk_get_rate(camclk->clock));
return ret;
}
if (WARN_ON(camclk->use_count == 0))
return 0;
if (--camclk->use_count == 0) {
clk_disable(camclk->clock);
s_info->clk_on = 0;
dbg("Disabled camclk %d", pdata->clk_id);
}
return ret;
}
int fimc_md_set_camclk(struct v4l2_subdev *sd, bool on)
{
struct fimc_sensor_info *s_info = v4l2_get_subdev_hostdata(sd);
struct fimc_md *fmd = entity_to_fimc_mdev(&sd->entity);
return __fimc_md_set_camclk(fmd, s_info, on);
}
static int fimc_md_link_notify(struct media_pad *source,
struct media_pad *sink, u32 flags)
{
struct v4l2_subdev *sd;
struct fimc_dev *fimc;
int ret = 0;
if (media_entity_type(sink->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
return 0;
sd = media_entity_to_v4l2_subdev(sink->entity);
fimc = v4l2_get_subdevdata(sd);
if (!(flags & MEDIA_LNK_FL_ENABLED)) {
ret = __fimc_pipeline_shutdown(fimc);
fimc->pipeline.sensor = NULL;
fimc->pipeline.csis = NULL;
mutex_lock(&fimc->lock);
fimc_ctrls_delete(fimc->vid_cap.ctx);
mutex_unlock(&fimc->lock);
return ret;
}
mutex_lock(&fimc->lock);
if (fimc->vid_cap.refcnt > 0) {
ret = __fimc_pipeline_initialize(fimc, source->entity, true);
if (!ret)
ret = fimc_capture_ctrls_create(fimc);
}
mutex_unlock(&fimc->lock);
return ret ? -EPIPE : ret;
}
static ssize_t fimc_md_sysfs_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct fimc_md *fmd = platform_get_drvdata(pdev);
if (fmd->user_subdev_api)
return strlcpy(buf, "Sub-device API (sub-dev)\n", PAGE_SIZE);
return strlcpy(buf, "V4L2 video node only API (vid-dev)\n", PAGE_SIZE);
}
static ssize_t fimc_md_sysfs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct fimc_md *fmd = platform_get_drvdata(pdev);
bool subdev_api;
int i;
if (!strcmp(buf, "vid-dev\n"))
subdev_api = false;
else if (!strcmp(buf, "sub-dev\n"))
subdev_api = true;
else
return count;
fmd->user_subdev_api = subdev_api;
for (i = 0; i < FIMC_MAX_DEVS; i++)
if (fmd->fimc[i])
fmd->fimc[i]->vid_cap.user_subdev_api = subdev_api;
return count;
}
static int __devinit fimc_md_probe(struct platform_device *pdev)
{
struct v4l2_device *v4l2_dev;
struct fimc_md *fmd;
int ret;
fmd = devm_kzalloc(&pdev->dev, sizeof(*fmd), GFP_KERNEL);
if (!fmd)
return -ENOMEM;
spin_lock_init(&fmd->slock);
fmd->pdev = pdev;
strlcpy(fmd->media_dev.model, "SAMSUNG S5P FIMC",
sizeof(fmd->media_dev.model));
fmd->media_dev.link_notify = fimc_md_link_notify;
fmd->media_dev.dev = &pdev->dev;
v4l2_dev = &fmd->v4l2_dev;
v4l2_dev->mdev = &fmd->media_dev;
v4l2_dev->notify = fimc_sensor_notify;
snprintf(v4l2_dev->name, sizeof(v4l2_dev->name), "%s",
dev_name(&pdev->dev));
ret = v4l2_device_register(&pdev->dev, &fmd->v4l2_dev);
if (ret < 0) {
v4l2_err(v4l2_dev, "Failed to register v4l2_device: %d\n", ret);
return ret;
}
ret = media_device_register(&fmd->media_dev);
if (ret < 0) {
v4l2_err(v4l2_dev, "Failed to register media device: %d\n", ret);
goto err2;
}
ret = fimc_md_get_clocks(fmd);
if (ret)
goto err3;
fmd->user_subdev_api = false;
ret = fimc_md_register_platform_entities(fmd);
if (ret)
goto err3;
if (pdev->dev.platform_data) {
ret = fimc_md_register_sensor_entities(fmd);
if (ret)
goto err3;
}
ret = fimc_md_create_links(fmd);
if (ret)
goto err3;
ret = v4l2_device_register_subdev_nodes(&fmd->v4l2_dev);
if (ret)
goto err3;
ret = fimc_md_register_video_nodes(fmd);
if (ret)
goto err3;
ret = device_create_file(&pdev->dev, &dev_attr_subdev_conf_mode);
if (!ret) {
platform_set_drvdata(pdev, fmd);
return 0;
}
err3:
media_device_unregister(&fmd->media_dev);
fimc_md_put_clocks(fmd);
fimc_md_unregister_entities(fmd);
err2:
v4l2_device_unregister(&fmd->v4l2_dev);
return ret;
}
static int __devexit fimc_md_remove(struct platform_device *pdev)
{
struct fimc_md *fmd = platform_get_drvdata(pdev);
if (!fmd)
return 0;
device_remove_file(&pdev->dev, &dev_attr_subdev_conf_mode);
fimc_md_unregister_entities(fmd);
media_device_unregister(&fmd->media_dev);
fimc_md_put_clocks(fmd);
return 0;
}
int __init fimc_md_init(void)
{
int ret;
request_module("s5p-csis");
ret = fimc_register_driver();
if (ret)
return ret;
return platform_driver_register(&fimc_md_driver);
}
void __exit fimc_md_exit(void)
{
platform_driver_unregister(&fimc_md_driver);
fimc_unregister_driver();
}
