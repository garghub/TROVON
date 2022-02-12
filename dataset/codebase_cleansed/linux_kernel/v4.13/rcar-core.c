static int rvin_find_pad(struct v4l2_subdev *sd, int direction)
{
unsigned int pad;
if (sd->entity.num_pads <= 1)
return 0;
for (pad = 0; pad < sd->entity.num_pads; pad++)
if (sd->entity.pads[pad].flags & direction)
return pad;
return -EINVAL;
}
static bool rvin_mbus_supported(struct rvin_graph_entity *entity)
{
struct v4l2_subdev *sd = entity->subdev;
struct v4l2_subdev_mbus_code_enum code = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
code.index = 0;
code.pad = entity->source_pad;
while (!v4l2_subdev_call(sd, pad, enum_mbus_code, NULL, &code)) {
code.index++;
switch (code.code) {
case MEDIA_BUS_FMT_YUYV8_1X16:
case MEDIA_BUS_FMT_UYVY8_2X8:
case MEDIA_BUS_FMT_UYVY10_2X10:
case MEDIA_BUS_FMT_RGB888_1X24:
entity->code = code.code;
return true;
default:
break;
}
}
return false;
}
static int rvin_digital_notify_complete(struct v4l2_async_notifier *notifier)
{
struct rvin_dev *vin = notifier_to_vin(notifier);
int ret;
if (!rvin_mbus_supported(&vin->digital)) {
vin_err(vin, "Unsupported media bus format for %s\n",
vin->digital.subdev->name);
return -EINVAL;
}
vin_dbg(vin, "Found media bus format for %s: %d\n",
vin->digital.subdev->name, vin->digital.code);
ret = v4l2_device_register_subdev_nodes(&vin->v4l2_dev);
if (ret < 0) {
vin_err(vin, "Failed to register subdev nodes\n");
return ret;
}
return rvin_v4l2_probe(vin);
}
static void rvin_digital_notify_unbind(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct rvin_dev *vin = notifier_to_vin(notifier);
vin_dbg(vin, "unbind digital subdev %s\n", subdev->name);
rvin_v4l2_remove(vin);
vin->digital.subdev = NULL;
}
static int rvin_digital_notify_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct rvin_dev *vin = notifier_to_vin(notifier);
int ret;
v4l2_set_subdev_hostdata(subdev, vin);
ret = rvin_find_pad(subdev, MEDIA_PAD_FL_SOURCE);
if (ret < 0)
return ret;
vin->digital.source_pad = ret;
ret = rvin_find_pad(subdev, MEDIA_PAD_FL_SINK);
vin->digital.sink_pad = ret < 0 ? 0 : ret;
vin->digital.subdev = subdev;
vin_dbg(vin, "bound subdev %s source pad: %u sink pad: %u\n",
subdev->name, vin->digital.source_pad,
vin->digital.sink_pad);
return 0;
}
static int rvin_digitial_parse_v4l2(struct rvin_dev *vin,
struct device_node *ep,
struct v4l2_mbus_config *mbus_cfg)
{
struct v4l2_fwnode_endpoint v4l2_ep;
int ret;
ret = v4l2_fwnode_endpoint_parse(of_fwnode_handle(ep), &v4l2_ep);
if (ret) {
vin_err(vin, "Could not parse v4l2 endpoint\n");
return -EINVAL;
}
mbus_cfg->type = v4l2_ep.bus_type;
switch (mbus_cfg->type) {
case V4L2_MBUS_PARALLEL:
vin_dbg(vin, "Found PARALLEL media bus\n");
mbus_cfg->flags = v4l2_ep.bus.parallel.flags;
break;
case V4L2_MBUS_BT656:
vin_dbg(vin, "Found BT656 media bus\n");
mbus_cfg->flags = 0;
break;
default:
vin_err(vin, "Unknown media bus type\n");
return -EINVAL;
}
return 0;
}
static int rvin_digital_graph_parse(struct rvin_dev *vin)
{
struct device_node *ep, *np;
int ret;
vin->digital.asd.match.fwnode.fwnode = NULL;
vin->digital.subdev = NULL;
ep = of_graph_get_endpoint_by_regs(vin->dev->of_node, 0, 0);
if (!ep)
return 0;
np = of_graph_get_remote_port_parent(ep);
if (!np) {
vin_err(vin, "No remote parent for digital input\n");
of_node_put(ep);
return -EINVAL;
}
of_node_put(np);
ret = rvin_digitial_parse_v4l2(vin, ep, &vin->digital.mbus_cfg);
of_node_put(ep);
if (ret)
return ret;
vin->digital.asd.match.fwnode.fwnode = of_fwnode_handle(np);
vin->digital.asd.match_type = V4L2_ASYNC_MATCH_FWNODE;
return 0;
}
static int rvin_digital_graph_init(struct rvin_dev *vin)
{
struct v4l2_async_subdev **subdevs = NULL;
int ret;
ret = rvin_digital_graph_parse(vin);
if (ret)
return ret;
if (!vin->digital.asd.match.fwnode.fwnode) {
vin_dbg(vin, "No digital subdevice found\n");
return -ENODEV;
}
subdevs = devm_kzalloc(vin->dev, sizeof(*subdevs), GFP_KERNEL);
if (subdevs == NULL)
return -ENOMEM;
subdevs[0] = &vin->digital.asd;
vin_dbg(vin, "Found digital subdevice %s\n",
of_node_full_name(to_of_node(subdevs[0]->match.fwnode.fwnode)));
vin->notifier.num_subdevs = 1;
vin->notifier.subdevs = subdevs;
vin->notifier.bound = rvin_digital_notify_bound;
vin->notifier.unbind = rvin_digital_notify_unbind;
vin->notifier.complete = rvin_digital_notify_complete;
ret = v4l2_async_notifier_register(&vin->v4l2_dev, &vin->notifier);
if (ret < 0) {
vin_err(vin, "Notifier registration failed\n");
return ret;
}
return 0;
}
static int rcar_vin_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct rvin_dev *vin;
struct resource *mem;
int irq, ret;
vin = devm_kzalloc(&pdev->dev, sizeof(*vin), GFP_KERNEL);
if (!vin)
return -ENOMEM;
match = of_match_device(of_match_ptr(rvin_of_id_table), &pdev->dev);
if (!match)
return -ENODEV;
vin->dev = &pdev->dev;
vin->chip = (enum chip_id)match->data;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem == NULL)
return -EINVAL;
vin->base = devm_ioremap_resource(vin->dev, mem);
if (IS_ERR(vin->base))
return PTR_ERR(vin->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
ret = rvin_dma_probe(vin, irq);
if (ret)
return ret;
ret = rvin_digital_graph_init(vin);
if (ret < 0)
goto error;
pm_suspend_ignore_children(&pdev->dev, true);
pm_runtime_enable(&pdev->dev);
platform_set_drvdata(pdev, vin);
return 0;
error:
rvin_dma_remove(vin);
return ret;
}
static int rcar_vin_remove(struct platform_device *pdev)
{
struct rvin_dev *vin = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
v4l2_async_notifier_unregister(&vin->notifier);
rvin_dma_remove(vin);
return 0;
}
