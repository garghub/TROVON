static void __setup_sensor_notification(struct fimc_md *fmd,
struct v4l2_subdev *sensor,
struct v4l2_subdev *fimc_sd)
{
struct fimc_source_info *src_inf;
struct fimc_sensor_info *md_si;
unsigned long flags;
src_inf = v4l2_get_subdev_hostdata(sensor);
if (!src_inf || WARN_ON(fmd == NULL))
return;
md_si = source_to_sensor_info(src_inf);
spin_lock_irqsave(&fmd->slock, flags);
md_si->host = v4l2_get_subdevdata(fimc_sd);
spin_unlock_irqrestore(&fmd->slock, flags);
}
static void fimc_pipeline_prepare(struct fimc_pipeline *p,
struct media_entity *me)
{
struct fimc_md *fmd = entity_to_fimc_mdev(me);
struct v4l2_subdev *sd;
struct v4l2_subdev *sensor = NULL;
int i;
for (i = 0; i < IDX_MAX; i++)
p->subdevs[i] = NULL;
while (1) {
struct media_pad *pad = NULL;
for (i = 0; i < me->num_pads; i++) {
struct media_pad *spad = &me->pads[i];
if (!(spad->flags & MEDIA_PAD_FL_SINK))
continue;
pad = media_entity_remote_pad(spad);
if (pad)
break;
}
if (pad == NULL ||
media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
break;
sd = media_entity_to_v4l2_subdev(pad->entity);
switch (sd->grp_id) {
case GRP_ID_SENSOR:
sensor = sd;
case GRP_ID_FIMC_IS_SENSOR:
p->subdevs[IDX_SENSOR] = sd;
break;
case GRP_ID_CSIS:
p->subdevs[IDX_CSIS] = sd;
break;
case GRP_ID_FLITE:
p->subdevs[IDX_FLITE] = sd;
break;
case GRP_ID_FIMC:
p->subdevs[IDX_FIMC] = sd;
break;
case GRP_ID_FIMC_IS:
p->subdevs[IDX_IS_ISP] = sd;
break;
default:
break;
}
me = &sd->entity;
if (me->num_pads == 1)
break;
}
if (sensor && p->subdevs[IDX_FIMC])
__setup_sensor_notification(fmd, sensor, p->subdevs[IDX_FIMC]);
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
static int fimc_pipeline_s_power(struct fimc_pipeline *p, bool on)
{
static const u8 seq[2][IDX_MAX - 1] = {
{ IDX_IS_ISP, IDX_SENSOR, IDX_CSIS, IDX_FLITE },
{ IDX_CSIS, IDX_FLITE, IDX_SENSOR, IDX_IS_ISP },
};
int i, ret = 0;
if (p->subdevs[IDX_SENSOR] == NULL)
return -ENXIO;
for (i = 0; i < IDX_MAX - 1; i++) {
unsigned int idx = seq[on][i];
ret = __subdev_set_power(p->subdevs[idx], on);
if (ret < 0 && ret != -ENXIO)
goto error;
}
return 0;
error:
for (; i >= 0; i--) {
unsigned int idx = seq[on][i];
__subdev_set_power(p->subdevs[idx], !on);
}
return ret;
}
static int __fimc_pipeline_open(struct exynos_media_pipeline *ep,
struct media_entity *me, bool prepare)
{
struct fimc_md *fmd = entity_to_fimc_mdev(me);
struct fimc_pipeline *p = to_fimc_pipeline(ep);
struct v4l2_subdev *sd;
int ret;
if (WARN_ON(p == NULL || me == NULL))
return -EINVAL;
if (prepare)
fimc_pipeline_prepare(p, me);
sd = p->subdevs[IDX_SENSOR];
if (sd == NULL)
return -EINVAL;
if (!IS_ERR(fmd->wbclk[CLK_IDX_WB_B]) && p->subdevs[IDX_IS_ISP]) {
ret = clk_prepare_enable(fmd->wbclk[CLK_IDX_WB_B]);
if (ret < 0)
return ret;
}
ret = fimc_md_set_camclk(sd, true);
if (ret < 0)
goto err_wbclk;
ret = fimc_pipeline_s_power(p, 1);
if (!ret)
return 0;
fimc_md_set_camclk(sd, false);
err_wbclk:
if (!IS_ERR(fmd->wbclk[CLK_IDX_WB_B]) && p->subdevs[IDX_IS_ISP])
clk_disable_unprepare(fmd->wbclk[CLK_IDX_WB_B]);
return ret;
}
static int __fimc_pipeline_close(struct exynos_media_pipeline *ep)
{
struct fimc_pipeline *p = to_fimc_pipeline(ep);
struct v4l2_subdev *sd = p ? p->subdevs[IDX_SENSOR] : NULL;
struct fimc_md *fmd;
int ret;
if (sd == NULL) {
pr_warn("%s(): No sensor subdev\n", __func__);
return 0;
}
ret = fimc_pipeline_s_power(p, 0);
fimc_md_set_camclk(sd, false);
fmd = entity_to_fimc_mdev(&sd->entity);
if (!IS_ERR(fmd->wbclk[CLK_IDX_WB_B]) && p->subdevs[IDX_IS_ISP])
clk_disable_unprepare(fmd->wbclk[CLK_IDX_WB_B]);
return ret == -ENXIO ? 0 : ret;
}
static int __fimc_pipeline_s_stream(struct exynos_media_pipeline *ep, bool on)
{
static const u8 seq[2][IDX_MAX] = {
{ IDX_FIMC, IDX_SENSOR, IDX_IS_ISP, IDX_CSIS, IDX_FLITE },
{ IDX_CSIS, IDX_FLITE, IDX_FIMC, IDX_SENSOR, IDX_IS_ISP },
};
struct fimc_pipeline *p = to_fimc_pipeline(ep);
int i, ret = 0;
if (p->subdevs[IDX_SENSOR] == NULL)
return -ENODEV;
for (i = 0; i < IDX_MAX; i++) {
unsigned int idx = seq[on][i];
ret = v4l2_subdev_call(p->subdevs[idx], video, s_stream, on);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
goto error;
}
return 0;
error:
for (; i >= 0; i--) {
unsigned int idx = seq[on][i];
v4l2_subdev_call(p->subdevs[idx], video, s_stream, !on);
}
return ret;
}
static struct exynos_media_pipeline *fimc_md_pipeline_create(
struct fimc_md *fmd)
{
struct fimc_pipeline *p;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return NULL;
list_add_tail(&p->list, &fmd->pipelines);
p->ep.ops = &fimc_pipeline_ops;
return &p->ep;
}
static void fimc_md_pipelines_free(struct fimc_md *fmd)
{
while (!list_empty(&fmd->pipelines)) {
struct fimc_pipeline *p;
p = list_entry(fmd->pipelines.next, typeof(*p), list);
list_del(&p->list);
kfree(p);
}
}
static struct v4l2_subdev *fimc_md_register_sensor(struct fimc_md *fmd,
struct fimc_source_info *si)
{
struct i2c_adapter *adapter;
struct v4l2_subdev *sd = NULL;
if (!si || !fmd)
return NULL;
si->fimc_bus_type = si->sensor_bus_type;
adapter = i2c_get_adapter(si->i2c_bus_num);
if (!adapter) {
v4l2_warn(&fmd->v4l2_dev,
"Failed to get I2C adapter %d, deferring probe\n",
si->i2c_bus_num);
return ERR_PTR(-EPROBE_DEFER);
}
sd = v4l2_i2c_new_subdev_board(&fmd->v4l2_dev, adapter,
si->board_info, NULL);
if (IS_ERR_OR_NULL(sd)) {
i2c_put_adapter(adapter);
v4l2_warn(&fmd->v4l2_dev,
"Failed to acquire subdev %s, deferring probe\n",
si->board_info->type);
return ERR_PTR(-EPROBE_DEFER);
}
v4l2_set_subdev_hostdata(sd, si);
sd->grp_id = GRP_ID_SENSOR;
v4l2_info(&fmd->v4l2_dev, "Registered sensor subdevice %s\n",
sd->name);
return sd;
}
static void fimc_md_unregister_sensor(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct i2c_adapter *adapter;
if (!client || client->dev.of_node)
return;
v4l2_device_unregister_subdev(sd);
adapter = client->adapter;
i2c_unregister_device(client);
if (adapter)
i2c_put_adapter(adapter);
}
static int fimc_md_parse_port_node(struct fimc_md *fmd,
struct device_node *port,
unsigned int index)
{
struct device_node *rem, *ep, *np;
struct fimc_source_info *pd;
struct v4l2_of_endpoint endpoint;
u32 val;
pd = &fmd->sensor[index].pdata;
ep = of_get_next_child(port, NULL);
if (!ep)
return 0;
v4l2_of_parse_endpoint(ep, &endpoint);
if (WARN_ON(endpoint.base.port == 0) || index >= FIMC_MAX_SENSORS)
return -EINVAL;
pd->mux_id = (endpoint.base.port - 1) & 0x1;
rem = of_graph_get_remote_port_parent(ep);
of_node_put(ep);
if (rem == NULL) {
v4l2_info(&fmd->v4l2_dev, "Remote device at %s not found\n",
ep->full_name);
return 0;
}
if (!of_property_read_u32(rem, "samsung,camclk-out", &val))
pd->clk_id = val;
if (!of_property_read_u32(rem, "clock-frequency", &val))
pd->clk_frequency = val;
else
pd->clk_frequency = DEFAULT_SENSOR_CLK_FREQ;
if (pd->clk_frequency == 0) {
v4l2_err(&fmd->v4l2_dev, "Wrong clock frequency at node %s\n",
rem->full_name);
of_node_put(rem);
return -EINVAL;
}
if (fimc_input_is_parallel(endpoint.base.port)) {
if (endpoint.bus_type == V4L2_MBUS_PARALLEL)
pd->sensor_bus_type = FIMC_BUS_TYPE_ITU_601;
else
pd->sensor_bus_type = FIMC_BUS_TYPE_ITU_656;
pd->flags = endpoint.bus.parallel.flags;
} else if (fimc_input_is_mipi_csi(endpoint.base.port)) {
pd->sensor_bus_type = FIMC_BUS_TYPE_MIPI_CSI2;
} else {
v4l2_err(&fmd->v4l2_dev, "Wrong port id (%u) at node %s\n",
endpoint.base.port, rem->full_name);
}
np = of_get_parent(rem);
if (np && !of_node_cmp(np->name, "i2c-isp"))
pd->fimc_bus_type = FIMC_BUS_TYPE_ISP_WRITEBACK;
else
pd->fimc_bus_type = pd->sensor_bus_type;
if (WARN_ON(index >= ARRAY_SIZE(fmd->sensor)))
return -EINVAL;
fmd->sensor[index].asd.match_type = V4L2_ASYNC_MATCH_OF;
fmd->sensor[index].asd.match.of.node = rem;
fmd->async_subdevs[index] = &fmd->sensor[index].asd;
fmd->num_sensors++;
of_node_put(rem);
return 0;
}
static int fimc_md_of_sensors_register(struct fimc_md *fmd,
struct device_node *np)
{
struct device_node *parent = fmd->pdev->dev.of_node;
struct device_node *node, *ports;
int index = 0;
int ret;
for_each_available_child_of_node(parent, node) {
struct device_node *port;
if (of_node_cmp(node->name, "csis"))
continue;
port = of_get_next_child(node, NULL);
if (!port)
continue;
ret = fimc_md_parse_port_node(fmd, port, index);
if (ret < 0)
return ret;
index++;
}
ports = of_get_child_by_name(parent, "parallel-ports");
if (!ports)
return 0;
for_each_child_of_node(ports, node) {
ret = fimc_md_parse_port_node(fmd, node, index);
if (ret < 0)
break;
index++;
}
return 0;
}
static int __of_get_csis_id(struct device_node *np)
{
u32 reg = 0;
np = of_get_child_by_name(np, "port");
if (!np)
return -EINVAL;
of_property_read_u32(np, "reg", &reg);
return reg - FIMC_INPUT_MIPI_CSI2_0;
}
static int fimc_md_register_sensor_entities(struct fimc_md *fmd)
{
struct s5p_platform_fimc *pdata = fmd->pdev->dev.platform_data;
struct device_node *of_node = fmd->pdev->dev.of_node;
int num_clients = 0;
int ret, i;
if (!fmd->pmf)
return -ENXIO;
ret = pm_runtime_get_sync(fmd->pmf);
if (ret < 0)
return ret;
if (of_node) {
fmd->num_sensors = 0;
ret = fimc_md_of_sensors_register(fmd, of_node);
} else if (pdata) {
WARN_ON(pdata->num_clients > ARRAY_SIZE(fmd->sensor));
num_clients = min_t(u32, pdata->num_clients,
ARRAY_SIZE(fmd->sensor));
fmd->num_sensors = num_clients;
for (i = 0; i < num_clients; i++) {
struct fimc_sensor_info *si = &fmd->sensor[i];
struct v4l2_subdev *sd;
si->pdata = pdata->source_info[i];
ret = __fimc_md_set_camclk(fmd, &si->pdata, true);
if (ret)
break;
sd = fimc_md_register_sensor(fmd, &si->pdata);
ret = __fimc_md_set_camclk(fmd, &si->pdata, false);
if (IS_ERR(sd)) {
si->subdev = NULL;
ret = PTR_ERR(sd);
break;
}
si->subdev = sd;
if (ret)
break;
}
}
pm_runtime_put(fmd->pmf);
return ret;
}
static int register_fimc_lite_entity(struct fimc_md *fmd,
struct fimc_lite *fimc_lite)
{
struct v4l2_subdev *sd;
struct exynos_media_pipeline *ep;
int ret;
if (WARN_ON(fimc_lite->index >= FIMC_LITE_MAX_DEVS ||
fmd->fimc_lite[fimc_lite->index]))
return -EBUSY;
sd = &fimc_lite->subdev;
sd->grp_id = GRP_ID_FLITE;
ep = fimc_md_pipeline_create(fmd);
if (!ep)
return -ENOMEM;
v4l2_set_subdev_hostdata(sd, ep);
ret = v4l2_device_register_subdev(&fmd->v4l2_dev, sd);
if (!ret)
fmd->fimc_lite[fimc_lite->index] = fimc_lite;
else
v4l2_err(&fmd->v4l2_dev, "Failed to register FIMC.LITE%d\n",
fimc_lite->index);
return ret;
}
static int register_fimc_entity(struct fimc_md *fmd, struct fimc_dev *fimc)
{
struct v4l2_subdev *sd;
struct exynos_media_pipeline *ep;
int ret;
if (WARN_ON(fimc->id >= FIMC_MAX_DEVS || fmd->fimc[fimc->id]))
return -EBUSY;
sd = &fimc->vid_cap.subdev;
sd->grp_id = GRP_ID_FIMC;
ep = fimc_md_pipeline_create(fmd);
if (!ep)
return -ENOMEM;
v4l2_set_subdev_hostdata(sd, ep);
ret = v4l2_device_register_subdev(&fmd->v4l2_dev, sd);
if (!ret) {
if (!fmd->pmf && fimc->pdev)
fmd->pmf = &fimc->pdev->dev;
fmd->fimc[fimc->id] = fimc;
fimc->vid_cap.user_subdev_api = fmd->user_subdev_api;
} else {
v4l2_err(&fmd->v4l2_dev, "Failed to register FIMC.%d (%d)\n",
fimc->id, ret);
}
return ret;
}
static int register_csis_entity(struct fimc_md *fmd,
struct platform_device *pdev,
struct v4l2_subdev *sd)
{
struct device_node *node = pdev->dev.of_node;
int id, ret;
id = node ? __of_get_csis_id(node) : max(0, pdev->id);
if (WARN_ON(id < 0 || id >= CSIS_MAX_ENTITIES))
return -ENOENT;
if (WARN_ON(fmd->csis[id].sd))
return -EBUSY;
sd->grp_id = GRP_ID_CSIS;
ret = v4l2_device_register_subdev(&fmd->v4l2_dev, sd);
if (!ret)
fmd->csis[id].sd = sd;
else
v4l2_err(&fmd->v4l2_dev,
"Failed to register MIPI-CSIS.%d (%d)\n", id, ret);
return ret;
}
static int register_fimc_is_entity(struct fimc_md *fmd, struct fimc_is *is)
{
struct v4l2_subdev *sd = &is->isp.subdev;
struct exynos_media_pipeline *ep;
int ret;
ep = fimc_md_pipeline_create(fmd);
if (!ep)
return -ENOMEM;
v4l2_set_subdev_hostdata(sd, ep);
ret = v4l2_device_register_subdev(&fmd->v4l2_dev, sd);
if (ret) {
v4l2_err(&fmd->v4l2_dev,
"Failed to register FIMC-ISP (%d)\n", ret);
return ret;
}
fmd->fimc_is = is;
return 0;
}
static int fimc_md_register_platform_entity(struct fimc_md *fmd,
struct platform_device *pdev,
int plat_entity)
{
struct device *dev = &pdev->dev;
int ret = -EPROBE_DEFER;
void *drvdata;
device_lock(dev);
if (!dev->driver || !try_module_get(dev->driver->owner))
goto dev_unlock;
drvdata = dev_get_drvdata(dev);
if (drvdata) {
switch (plat_entity) {
case IDX_FIMC:
ret = register_fimc_entity(fmd, drvdata);
break;
case IDX_FLITE:
ret = register_fimc_lite_entity(fmd, drvdata);
break;
case IDX_CSIS:
ret = register_csis_entity(fmd, pdev, drvdata);
break;
case IDX_IS_ISP:
ret = register_fimc_is_entity(fmd, drvdata);
break;
default:
ret = -ENODEV;
}
}
module_put(dev->driver->owner);
dev_unlock:
device_unlock(dev);
if (ret == -EPROBE_DEFER)
dev_info(&fmd->pdev->dev, "deferring %s device registration\n",
dev_name(dev));
else if (ret < 0)
dev_err(&fmd->pdev->dev, "%s device registration failed (%d)\n",
dev_name(dev), ret);
return ret;
}
static int fimc_md_pdev_match(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
int plat_entity = -1;
int ret;
char *p;
if (!get_device(dev))
return -ENODEV;
if (!strcmp(pdev->name, CSIS_DRIVER_NAME)) {
plat_entity = IDX_CSIS;
} else {
p = strstr(pdev->name, "fimc");
if (p && *(p + 4) == 0)
plat_entity = IDX_FIMC;
}
if (plat_entity >= 0)
ret = fimc_md_register_platform_entity(data, pdev,
plat_entity);
put_device(dev);
return 0;
}
static int fimc_md_register_of_platform_entities(struct fimc_md *fmd,
struct device_node *parent)
{
struct device_node *node;
int ret = 0;
for_each_available_child_of_node(parent, node) {
struct platform_device *pdev;
int plat_entity = -1;
pdev = of_find_device_by_node(node);
if (!pdev)
continue;
if (!strcmp(node->name, CSIS_OF_NODE_NAME))
plat_entity = IDX_CSIS;
else if (!strcmp(node->name, FIMC_IS_OF_NODE_NAME))
plat_entity = IDX_IS_ISP;
else if (!strcmp(node->name, FIMC_LITE_OF_NODE_NAME))
plat_entity = IDX_FLITE;
else if (!strcmp(node->name, FIMC_OF_NODE_NAME) &&
!of_property_read_bool(node, "samsung,lcd-wb"))
plat_entity = IDX_FIMC;
if (plat_entity >= 0)
ret = fimc_md_register_platform_entity(fmd, pdev,
plat_entity);
put_device(&pdev->dev);
if (ret < 0)
break;
}
return ret;
}
static void fimc_md_unregister_entities(struct fimc_md *fmd)
{
int i;
for (i = 0; i < FIMC_MAX_DEVS; i++) {
struct fimc_dev *dev = fmd->fimc[i];
if (dev == NULL)
continue;
v4l2_device_unregister_subdev(&dev->vid_cap.subdev);
dev->vid_cap.ve.pipe = NULL;
fmd->fimc[i] = NULL;
}
for (i = 0; i < FIMC_LITE_MAX_DEVS; i++) {
struct fimc_lite *dev = fmd->fimc_lite[i];
if (dev == NULL)
continue;
v4l2_device_unregister_subdev(&dev->subdev);
dev->ve.pipe = NULL;
fmd->fimc_lite[i] = NULL;
}
for (i = 0; i < CSIS_MAX_ENTITIES; i++) {
if (fmd->csis[i].sd == NULL)
continue;
v4l2_device_unregister_subdev(fmd->csis[i].sd);
fmd->csis[i].sd = NULL;
}
if (fmd->pdev->dev.of_node == NULL) {
for (i = 0; i < fmd->num_sensors; i++) {
if (fmd->sensor[i].subdev == NULL)
continue;
fimc_md_unregister_sensor(fmd->sensor[i].subdev);
fmd->sensor[i].subdev = NULL;
}
}
if (fmd->fimc_is)
v4l2_device_unregister_subdev(&fmd->fimc_is->isp.subdev);
v4l2_info(&fmd->v4l2_dev, "Unregistered all entities\n");
}
static int __fimc_md_create_fimc_sink_links(struct fimc_md *fmd,
struct media_entity *source,
struct v4l2_subdev *sensor,
int pad, int link_mask)
{
struct fimc_source_info *si = NULL;
struct media_entity *sink;
unsigned int flags = 0;
int i, ret = 0;
if (sensor) {
si = v4l2_get_subdev_hostdata(sensor);
if (si && si->fimc_bus_type == FIMC_BUS_TYPE_ISP_WRITEBACK)
ret = 1;
}
for (i = 0; !ret && i < FIMC_MAX_DEVS; i++) {
if (!fmd->fimc[i])
continue;
if (!fmd->fimc[i]->variant->has_cam_if)
continue;
flags = ((1 << i) & link_mask) ? MEDIA_LNK_FL_ENABLED : 0;
sink = &fmd->fimc[i]->vid_cap.subdev.entity;
ret = media_entity_create_link(source, pad, sink,
FIMC_SD_PAD_SINK_CAM, flags);
if (ret)
return ret;
ret = media_entity_call(sink, link_setup, &sink->pads[0],
&source->pads[pad], flags);
if (ret)
break;
v4l2_info(&fmd->v4l2_dev, "created link [%s] %c> [%s]\n",
source->name, flags ? '=' : '-', sink->name);
}
for (i = 0; i < FIMC_LITE_MAX_DEVS; i++) {
if (!fmd->fimc_lite[i])
continue;
sink = &fmd->fimc_lite[i]->subdev.entity;
ret = media_entity_create_link(source, pad, sink,
FLITE_SD_PAD_SINK, 0);
if (ret)
return ret;
ret = media_entity_call(sink, link_setup, &sink->pads[0],
&source->pads[pad], 0);
if (ret)
break;
v4l2_info(&fmd->v4l2_dev, "created link [%s] -> [%s]\n",
source->name, sink->name);
}
return 0;
}
static int __fimc_md_create_flite_source_links(struct fimc_md *fmd)
{
struct media_entity *source, *sink;
int i, ret = 0;
for (i = 0; i < FIMC_LITE_MAX_DEVS; i++) {
struct fimc_lite *fimc = fmd->fimc_lite[i];
if (fimc == NULL)
continue;
source = &fimc->subdev.entity;
sink = &fimc->ve.vdev.entity;
ret = media_entity_create_link(source, FLITE_SD_PAD_SOURCE_DMA,
sink, 0, 0);
if (ret)
break;
sink = &fmd->fimc_is->isp.subdev.entity;
ret = media_entity_create_link(source, FLITE_SD_PAD_SOURCE_ISP,
sink, 0, 0);
if (ret)
break;
}
return ret;
}
static int __fimc_md_create_fimc_is_links(struct fimc_md *fmd)
{
struct fimc_isp *isp = &fmd->fimc_is->isp;
struct media_entity *source, *sink;
int i, ret;
source = &isp->subdev.entity;
for (i = 0; i < FIMC_MAX_DEVS; i++) {
if (fmd->fimc[i] == NULL)
continue;
sink = &fmd->fimc[i]->vid_cap.subdev.entity;
ret = media_entity_create_link(source, FIMC_ISP_SD_PAD_SRC_FIFO,
sink, FIMC_SD_PAD_SINK_FIFO, 0);
if (ret)
return ret;
}
sink = &isp->video_capture.ve.vdev.entity;
if (sink->num_pads == 0)
return 0;
return media_entity_create_link(source, FIMC_ISP_SD_PAD_SRC_DMA,
sink, 0, 0);
}
static int fimc_md_create_links(struct fimc_md *fmd)
{
struct v4l2_subdev *csi_sensors[CSIS_MAX_ENTITIES] = { NULL };
struct v4l2_subdev *sensor, *csis;
struct fimc_source_info *pdata;
struct media_entity *source, *sink;
int i, pad, fimc_id = 0, ret = 0;
u32 flags, link_mask = 0;
for (i = 0; i < fmd->num_sensors; i++) {
if (fmd->sensor[i].subdev == NULL)
continue;
sensor = fmd->sensor[i].subdev;
pdata = v4l2_get_subdev_hostdata(sensor);
if (!pdata)
continue;
source = NULL;
switch (pdata->sensor_bus_type) {
case FIMC_BUS_TYPE_MIPI_CSI2:
if (WARN(pdata->mux_id >= CSIS_MAX_ENTITIES,
"Wrong CSI channel id: %d\n", pdata->mux_id))
return -EINVAL;
csis = fmd->csis[pdata->mux_id].sd;
if (WARN(csis == NULL,
"MIPI-CSI interface specified "
"but s5p-csis module is not loaded!\n"))
return -EINVAL;
pad = sensor->entity.num_pads - 1;
ret = media_entity_create_link(&sensor->entity, pad,
&csis->entity, CSIS_PAD_SINK,
MEDIA_LNK_FL_IMMUTABLE |
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
v4l2_info(&fmd->v4l2_dev, "created link [%s] => [%s]\n",
sensor->entity.name, csis->entity.name);
source = NULL;
csi_sensors[pdata->mux_id] = sensor;
break;
case FIMC_BUS_TYPE_ITU_601...FIMC_BUS_TYPE_ITU_656:
source = &sensor->entity;
pad = 0;
break;
default:
v4l2_err(&fmd->v4l2_dev, "Wrong bus_type: %x\n",
pdata->sensor_bus_type);
return -EINVAL;
}
if (source == NULL)
continue;
link_mask = 1 << fimc_id++;
ret = __fimc_md_create_fimc_sink_links(fmd, source, sensor,
pad, link_mask);
}
for (i = 0; i < CSIS_MAX_ENTITIES; i++) {
if (fmd->csis[i].sd == NULL)
continue;
source = &fmd->csis[i].sd->entity;
pad = CSIS_PAD_SOURCE;
sensor = csi_sensors[i];
link_mask = 1 << fimc_id++;
ret = __fimc_md_create_fimc_sink_links(fmd, source, sensor,
pad, link_mask);
}
flags = MEDIA_LNK_FL_IMMUTABLE | MEDIA_LNK_FL_ENABLED;
for (i = 0; i < FIMC_MAX_DEVS; i++) {
if (!fmd->fimc[i])
continue;
source = &fmd->fimc[i]->vid_cap.subdev.entity;
sink = &fmd->fimc[i]->vid_cap.ve.vdev.entity;
ret = media_entity_create_link(source, FIMC_SD_PAD_SOURCE,
sink, 0, flags);
if (ret)
break;
}
ret = __fimc_md_create_flite_source_links(fmd);
if (ret < 0)
return ret;
if (fmd->use_isp)
ret = __fimc_md_create_fimc_is_links(fmd);
return ret;
}
static void fimc_md_put_clocks(struct fimc_md *fmd)
{
int i = FIMC_MAX_CAMCLKS;
while (--i >= 0) {
if (IS_ERR(fmd->camclk[i].clock))
continue;
clk_put(fmd->camclk[i].clock);
fmd->camclk[i].clock = ERR_PTR(-EINVAL);
}
for (i = 0; i < FIMC_MAX_WBCLKS; i++) {
if (IS_ERR(fmd->wbclk[i]))
continue;
clk_put(fmd->wbclk[i]);
fmd->wbclk[i] = ERR_PTR(-EINVAL);
}
}
static int fimc_md_get_clocks(struct fimc_md *fmd)
{
struct device *dev = NULL;
char clk_name[32];
struct clk *clock;
int i, ret = 0;
for (i = 0; i < FIMC_MAX_CAMCLKS; i++)
fmd->camclk[i].clock = ERR_PTR(-EINVAL);
if (fmd->pdev->dev.of_node)
dev = &fmd->pdev->dev;
for (i = 0; i < FIMC_MAX_CAMCLKS; i++) {
snprintf(clk_name, sizeof(clk_name), "sclk_cam%u", i);
clock = clk_get(dev, clk_name);
if (IS_ERR(clock)) {
dev_err(&fmd->pdev->dev, "Failed to get clock: %s\n",
clk_name);
ret = PTR_ERR(clock);
break;
}
fmd->camclk[i].clock = clock;
}
if (ret)
fimc_md_put_clocks(fmd);
if (!fmd->use_isp)
return 0;
fmd->wbclk[CLK_IDX_WB_A] = ERR_PTR(-EINVAL);
for (i = CLK_IDX_WB_B; i < FIMC_MAX_WBCLKS; i++) {
snprintf(clk_name, sizeof(clk_name), "pxl_async%u", i);
clock = clk_get(dev, clk_name);
if (IS_ERR(clock)) {
v4l2_err(&fmd->v4l2_dev, "Failed to get clock: %s\n",
clk_name);
ret = PTR_ERR(clock);
break;
}
fmd->wbclk[i] = clock;
}
if (ret)
fimc_md_put_clocks(fmd);
return ret;
}
static int __fimc_md_set_camclk(struct fimc_md *fmd,
struct fimc_source_info *si,
bool on)
{
struct fimc_camclk_info *camclk;
int ret = 0;
if (fmd->pdev->dev.of_node)
return 0;
if (WARN_ON(si->clk_id >= FIMC_MAX_CAMCLKS) || !fmd || !fmd->pmf)
return -EINVAL;
camclk = &fmd->camclk[si->clk_id];
dbg("camclk %d, f: %lu, use_count: %d, on: %d",
si->clk_id, si->clk_frequency, camclk->use_count, on);
if (on) {
if (camclk->use_count > 0 &&
camclk->frequency != si->clk_frequency)
return -EINVAL;
if (camclk->use_count++ == 0) {
clk_set_rate(camclk->clock, si->clk_frequency);
camclk->frequency = si->clk_frequency;
ret = pm_runtime_get_sync(fmd->pmf);
if (ret < 0)
return ret;
ret = clk_prepare_enable(camclk->clock);
dbg("Enabled camclk %d: f: %lu", si->clk_id,
clk_get_rate(camclk->clock));
}
return ret;
}
if (WARN_ON(camclk->use_count == 0))
return 0;
if (--camclk->use_count == 0) {
clk_disable_unprepare(camclk->clock);
pm_runtime_put(fmd->pmf);
dbg("Disabled camclk %d", si->clk_id);
}
return ret;
}
int fimc_md_set_camclk(struct v4l2_subdev *sd, bool on)
{
struct fimc_source_info *si = v4l2_get_subdev_hostdata(sd);
struct fimc_md *fmd = entity_to_fimc_mdev(&sd->entity);
if (fmd->clk_provider.num_clocks > 0)
return 0;
return __fimc_md_set_camclk(fmd, si, on);
}
static int __fimc_md_modify_pipeline(struct media_entity *entity, bool enable)
{
struct exynos_video_entity *ve;
struct fimc_pipeline *p;
struct video_device *vdev;
int ret;
vdev = media_entity_to_video_device(entity);
if (vdev->entity.use_count == 0)
return 0;
ve = vdev_to_exynos_video_entity(vdev);
p = to_fimc_pipeline(ve->pipe);
if (!enable && p->subdevs[IDX_SENSOR] == NULL)
return 0;
if (enable)
ret = __fimc_pipeline_open(ve->pipe, entity, true);
else
ret = __fimc_pipeline_close(ve->pipe);
if (ret == 0 && !enable)
memset(p->subdevs, 0, sizeof(p->subdevs));
return ret;
}
static int __fimc_md_modify_pipelines(struct media_entity *entity, bool enable)
{
struct media_entity *entity_err = entity;
struct media_entity_graph graph;
int ret;
media_entity_graph_walk_start(&graph, entity);
while ((entity = media_entity_graph_walk_next(&graph))) {
if (media_entity_type(entity) != MEDIA_ENT_T_DEVNODE)
continue;
ret = __fimc_md_modify_pipeline(entity, enable);
if (ret < 0)
goto err;
}
return 0;
err:
media_entity_graph_walk_start(&graph, entity_err);
while ((entity_err = media_entity_graph_walk_next(&graph))) {
if (media_entity_type(entity_err) != MEDIA_ENT_T_DEVNODE)
continue;
__fimc_md_modify_pipeline(entity_err, !enable);
if (entity_err == entity)
break;
}
return ret;
}
static int fimc_md_link_notify(struct media_link *link, unsigned int flags,
unsigned int notification)
{
struct media_entity *sink = link->sink->entity;
int ret = 0;
if (notification == MEDIA_DEV_NOTIFY_PRE_LINK_CH) {
if (!(flags & MEDIA_LNK_FL_ENABLED))
ret = __fimc_md_modify_pipelines(sink, false);
else
;
} else if (notification == MEDIA_DEV_NOTIFY_POST_LINK_CH &&
(link->flags & MEDIA_LNK_FL_ENABLED)) {
ret = __fimc_md_modify_pipelines(sink, true);
}
return ret ? -EPIPE : 0;
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
static int fimc_md_get_pinctrl(struct fimc_md *fmd)
{
struct device *dev = &fmd->pdev->dev;
struct fimc_pinctrl *pctl = &fmd->pinctl;
pctl->pinctrl = devm_pinctrl_get(dev);
if (IS_ERR(pctl->pinctrl))
return PTR_ERR(pctl->pinctrl);
pctl->state_default = pinctrl_lookup_state(pctl->pinctrl,
PINCTRL_STATE_DEFAULT);
if (IS_ERR(pctl->state_default))
return PTR_ERR(pctl->state_default);
pctl->state_idle = pinctrl_lookup_state(pctl->pinctrl,
PINCTRL_STATE_IDLE);
return 0;
}
static int cam_clk_prepare(struct clk_hw *hw)
{
struct cam_clk *camclk = to_cam_clk(hw);
int ret;
if (camclk->fmd->pmf == NULL)
return -ENODEV;
ret = pm_runtime_get_sync(camclk->fmd->pmf);
return ret < 0 ? ret : 0;
}
static void cam_clk_unprepare(struct clk_hw *hw)
{
struct cam_clk *camclk = to_cam_clk(hw);
if (camclk->fmd->pmf == NULL)
return;
pm_runtime_put_sync(camclk->fmd->pmf);
}
static void fimc_md_unregister_clk_provider(struct fimc_md *fmd)
{
struct cam_clk_provider *cp = &fmd->clk_provider;
unsigned int i;
if (cp->of_node)
of_clk_del_provider(cp->of_node);
for (i = 0; i < cp->num_clocks; i++)
clk_unregister(cp->clks[i]);
}
static int fimc_md_register_clk_provider(struct fimc_md *fmd)
{
struct cam_clk_provider *cp = &fmd->clk_provider;
struct device *dev = &fmd->pdev->dev;
int i, ret;
for (i = 0; i < FIMC_MAX_CAMCLKS; i++) {
struct cam_clk *camclk = &cp->camclk[i];
struct clk_init_data init;
const char *p_name;
ret = of_property_read_string_index(dev->of_node,
"clock-output-names", i, &init.name);
if (ret < 0)
break;
p_name = __clk_get_name(fmd->camclk[i].clock);
init.parent_names = &p_name;
init.num_parents = 1;
init.ops = &cam_clk_ops;
init.flags = CLK_SET_RATE_PARENT;
camclk->hw.init = &init;
camclk->fmd = fmd;
cp->clks[i] = clk_register(NULL, &camclk->hw);
if (IS_ERR(cp->clks[i])) {
dev_err(dev, "failed to register clock: %s (%ld)\n",
init.name, PTR_ERR(cp->clks[i]));
ret = PTR_ERR(cp->clks[i]);
goto err;
}
cp->num_clocks++;
}
if (cp->num_clocks == 0) {
dev_warn(dev, "clk provider not registered\n");
return 0;
}
cp->clk_data.clks = cp->clks;
cp->clk_data.clk_num = cp->num_clocks;
cp->of_node = dev->of_node;
ret = of_clk_add_provider(dev->of_node, of_clk_src_onecell_get,
&cp->clk_data);
if (ret == 0)
return 0;
err:
fimc_md_unregister_clk_provider(fmd);
return ret;
}
static int subdev_notifier_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct fimc_md *fmd = notifier_to_fimc_md(notifier);
struct fimc_sensor_info *si = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(fmd->sensor); i++)
if (fmd->sensor[i].asd.match.of.node == subdev->dev->of_node)
si = &fmd->sensor[i];
if (si == NULL)
return -EINVAL;
v4l2_set_subdev_hostdata(subdev, &si->pdata);
if (si->pdata.fimc_bus_type == FIMC_BUS_TYPE_ISP_WRITEBACK)
subdev->grp_id = GRP_ID_FIMC_IS_SENSOR;
else
subdev->grp_id = GRP_ID_SENSOR;
si->subdev = subdev;
v4l2_info(&fmd->v4l2_dev, "Registered sensor subdevice: %s (%d)\n",
subdev->name, fmd->num_sensors);
fmd->num_sensors++;
return 0;
}
static int subdev_notifier_complete(struct v4l2_async_notifier *notifier)
{
struct fimc_md *fmd = notifier_to_fimc_md(notifier);
int ret;
mutex_lock(&fmd->media_dev.graph_mutex);
ret = fimc_md_create_links(fmd);
if (ret < 0)
goto unlock;
ret = v4l2_device_register_subdev_nodes(&fmd->v4l2_dev);
unlock:
mutex_unlock(&fmd->media_dev.graph_mutex);
return ret;
}
static int fimc_md_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct v4l2_device *v4l2_dev;
struct fimc_md *fmd;
int ret;
fmd = devm_kzalloc(dev, sizeof(*fmd), GFP_KERNEL);
if (!fmd)
return -ENOMEM;
spin_lock_init(&fmd->slock);
fmd->pdev = pdev;
INIT_LIST_HEAD(&fmd->pipelines);
strlcpy(fmd->media_dev.model, "SAMSUNG S5P FIMC",
sizeof(fmd->media_dev.model));
fmd->media_dev.link_notify = fimc_md_link_notify;
fmd->media_dev.dev = dev;
v4l2_dev = &fmd->v4l2_dev;
v4l2_dev->mdev = &fmd->media_dev;
v4l2_dev->notify = fimc_sensor_notify;
strlcpy(v4l2_dev->name, "s5p-fimc-md", sizeof(v4l2_dev->name));
fmd->use_isp = fimc_md_is_isp_available(dev->of_node);
ret = v4l2_device_register(dev, &fmd->v4l2_dev);
if (ret < 0) {
v4l2_err(v4l2_dev, "Failed to register v4l2_device: %d\n", ret);
return ret;
}
ret = media_device_register(&fmd->media_dev);
if (ret < 0) {
v4l2_err(v4l2_dev, "Failed to register media device: %d\n", ret);
goto err_v4l2_dev;
}
ret = fimc_md_get_clocks(fmd);
if (ret)
goto err_md;
fmd->user_subdev_api = (dev->of_node != NULL);
ret = fimc_md_get_pinctrl(fmd);
if (ret < 0) {
if (ret != EPROBE_DEFER)
dev_err(dev, "Failed to get pinctrl: %d\n", ret);
goto err_clk;
}
platform_set_drvdata(pdev, fmd);
mutex_lock(&fmd->media_dev.graph_mutex);
if (dev->of_node)
ret = fimc_md_register_of_platform_entities(fmd, dev->of_node);
else
ret = bus_for_each_dev(&platform_bus_type, NULL, fmd,
fimc_md_pdev_match);
if (ret) {
mutex_unlock(&fmd->media_dev.graph_mutex);
goto err_clk;
}
if (dev->platform_data || dev->of_node) {
ret = fimc_md_register_sensor_entities(fmd);
if (ret) {
mutex_unlock(&fmd->media_dev.graph_mutex);
goto err_m_ent;
}
}
mutex_unlock(&fmd->media_dev.graph_mutex);
ret = device_create_file(&pdev->dev, &dev_attr_subdev_conf_mode);
if (ret)
goto err_m_ent;
ret = fimc_md_register_clk_provider(fmd);
if (ret < 0) {
v4l2_err(v4l2_dev, "clock provider registration failed\n");
goto err_attr;
}
if (fmd->num_sensors > 0) {
fmd->subdev_notifier.subdevs = fmd->async_subdevs;
fmd->subdev_notifier.num_subdevs = fmd->num_sensors;
fmd->subdev_notifier.bound = subdev_notifier_bound;
fmd->subdev_notifier.complete = subdev_notifier_complete;
fmd->num_sensors = 0;
ret = v4l2_async_notifier_register(&fmd->v4l2_dev,
&fmd->subdev_notifier);
if (ret)
goto err_clk_p;
}
return 0;
err_clk_p:
fimc_md_unregister_clk_provider(fmd);
err_attr:
device_remove_file(&pdev->dev, &dev_attr_subdev_conf_mode);
err_clk:
fimc_md_put_clocks(fmd);
err_m_ent:
fimc_md_unregister_entities(fmd);
err_md:
media_device_unregister(&fmd->media_dev);
err_v4l2_dev:
v4l2_device_unregister(&fmd->v4l2_dev);
return ret;
}
static int fimc_md_remove(struct platform_device *pdev)
{
struct fimc_md *fmd = platform_get_drvdata(pdev);
if (!fmd)
return 0;
fimc_md_unregister_clk_provider(fmd);
v4l2_async_notifier_unregister(&fmd->subdev_notifier);
v4l2_device_unregister(&fmd->v4l2_dev);
device_remove_file(&pdev->dev, &dev_attr_subdev_conf_mode);
fimc_md_unregister_entities(fmd);
fimc_md_pipelines_free(fmd);
media_device_unregister(&fmd->media_dev);
fimc_md_put_clocks(fmd);
return 0;
}
static int __init fimc_md_init(void)
{
int ret;
request_module("s5p-csis");
ret = fimc_register_driver();
if (ret)
return ret;
return platform_driver_register(&fimc_md_driver);
}
static void __exit fimc_md_exit(void)
{
platform_driver_unregister(&fimc_md_driver);
fimc_unregister_driver();
}
