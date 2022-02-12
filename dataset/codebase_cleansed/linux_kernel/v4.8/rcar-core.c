static int rvin_mbus_supported(struct rvin_dev *vin)
{
struct v4l2_subdev *sd;
struct v4l2_subdev_mbus_code_enum code = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
sd = vin_to_source(vin);
code.index = 0;
while (!v4l2_subdev_call(sd, pad, enum_mbus_code, NULL, &code)) {
code.index++;
switch (code.code) {
case MEDIA_BUS_FMT_YUYV8_1X16:
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_YUYV10_2X10:
case MEDIA_BUS_FMT_RGB888_1X24:
vin->source.code = code.code;
vin_dbg(vin, "Found supported media bus format: %d\n",
vin->source.code);
return true;
default:
break;
}
}
return false;
}
static int rvin_graph_notify_complete(struct v4l2_async_notifier *notifier)
{
struct rvin_dev *vin = notifier_to_vin(notifier);
int ret;
ret = v4l2_device_register_subdev_nodes(&vin->v4l2_dev);
if (ret < 0) {
vin_err(vin, "Failed to register subdev nodes\n");
return ret;
}
if (!rvin_mbus_supported(vin)) {
vin_err(vin, "No supported mediabus format found\n");
return -EINVAL;
}
return rvin_v4l2_probe(vin);
}
static void rvin_graph_notify_unbind(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *sd,
struct v4l2_async_subdev *asd)
{
struct rvin_dev *vin = notifier_to_vin(notifier);
rvin_v4l2_remove(vin);
}
static int rvin_graph_notify_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct rvin_dev *vin = notifier_to_vin(notifier);
vin_dbg(vin, "subdev %s bound\n", subdev->name);
vin->entity.entity = &subdev->entity;
vin->entity.subdev = subdev;
return 0;
}
static int rvin_graph_parse(struct rvin_dev *vin,
struct device_node *node)
{
struct device_node *remote;
struct device_node *ep = NULL;
struct device_node *next;
int ret = 0;
while (1) {
next = of_graph_get_next_endpoint(node, ep);
if (!next)
break;
of_node_put(ep);
ep = next;
remote = of_graph_get_remote_port_parent(ep);
if (!remote) {
ret = -EINVAL;
break;
}
if (remote == vin->dev->of_node) {
of_node_put(remote);
continue;
}
if (!vin->entity.node) {
vin->entity.node = remote;
vin->entity.asd.match_type = V4L2_ASYNC_MATCH_OF;
vin->entity.asd.match.of.node = remote;
ret++;
}
}
of_node_put(ep);
return ret;
}
static int rvin_graph_init(struct rvin_dev *vin)
{
struct v4l2_async_subdev **subdevs = NULL;
int ret;
ret = rvin_graph_parse(vin, vin->dev->of_node);
if (ret < 0) {
vin_err(vin, "Graph parsing failed\n");
goto done;
}
if (!ret) {
vin_err(vin, "No subdev found in graph\n");
goto done;
}
if (ret != 1) {
vin_err(vin, "More then one subdev found in graph\n");
goto done;
}
subdevs = devm_kzalloc(vin->dev, sizeof(*subdevs), GFP_KERNEL);
if (subdevs == NULL) {
ret = -ENOMEM;
goto done;
}
subdevs[0] = &vin->entity.asd;
vin->notifier.subdevs = subdevs;
vin->notifier.num_subdevs = 1;
vin->notifier.bound = rvin_graph_notify_bound;
vin->notifier.unbind = rvin_graph_notify_unbind;
vin->notifier.complete = rvin_graph_notify_complete;
ret = v4l2_async_notifier_register(&vin->v4l2_dev, &vin->notifier);
if (ret < 0) {
vin_err(vin, "Notifier registration failed\n");
goto done;
}
ret = 0;
done:
if (ret < 0) {
v4l2_async_notifier_unregister(&vin->notifier);
of_node_put(vin->entity.node);
}
return ret;
}
static int rvin_parse_dt(struct rvin_dev *vin)
{
const struct of_device_id *match;
struct v4l2_of_endpoint ep;
struct device_node *np;
int ret;
match = of_match_device(of_match_ptr(rvin_of_id_table), vin->dev);
if (!match)
return -ENODEV;
vin->chip = (enum chip_id)match->data;
np = of_graph_get_next_endpoint(vin->dev->of_node, NULL);
if (!np) {
vin_err(vin, "Could not find endpoint\n");
return -EINVAL;
}
ret = v4l2_of_parse_endpoint(np, &ep);
if (ret) {
vin_err(vin, "Could not parse endpoint\n");
return ret;
}
of_node_put(np);
vin->mbus_cfg.type = ep.bus_type;
switch (vin->mbus_cfg.type) {
case V4L2_MBUS_PARALLEL:
vin->mbus_cfg.flags = ep.bus.parallel.flags;
break;
case V4L2_MBUS_BT656:
vin->mbus_cfg.flags = 0;
break;
default:
vin_err(vin, "Unknown media bus type\n");
return -EINVAL;
}
return 0;
}
static int rcar_vin_probe(struct platform_device *pdev)
{
struct rvin_dev *vin;
struct resource *mem;
int irq, ret;
vin = devm_kzalloc(&pdev->dev, sizeof(*vin), GFP_KERNEL);
if (!vin)
return -ENOMEM;
vin->dev = &pdev->dev;
ret = rvin_parse_dt(vin);
if (ret)
return ret;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem == NULL)
return -EINVAL;
vin->base = devm_ioremap_resource(vin->dev, mem);
if (IS_ERR(vin->base))
return PTR_ERR(vin->base);
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return ret;
ret = rvin_dma_probe(vin, irq);
if (ret)
return ret;
ret = rvin_graph_init(vin);
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
