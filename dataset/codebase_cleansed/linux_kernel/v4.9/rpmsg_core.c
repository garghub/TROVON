struct rpmsg_endpoint *rpmsg_create_ept(struct rpmsg_device *rpdev,
rpmsg_rx_cb_t cb, void *priv,
struct rpmsg_channel_info chinfo)
{
return rpdev->ops->create_ept(rpdev, cb, priv, chinfo);
}
void rpmsg_destroy_ept(struct rpmsg_endpoint *ept)
{
ept->ops->destroy_ept(ept);
}
int rpmsg_send(struct rpmsg_endpoint *ept, void *data, int len)
{
return ept->ops->send(ept, data, len);
}
int rpmsg_sendto(struct rpmsg_endpoint *ept, void *data, int len, u32 dst)
{
return ept->ops->sendto(ept, data, len, dst);
}
int rpmsg_send_offchannel(struct rpmsg_endpoint *ept, u32 src, u32 dst,
void *data, int len)
{
return ept->ops->send_offchannel(ept, src, dst, data, len);
}
int rpmsg_trysend(struct rpmsg_endpoint *ept, void *data, int len)
{
return ept->ops->trysend(ept, data, len);
}
int rpmsg_trysendto(struct rpmsg_endpoint *ept, void *data, int len, u32 dst)
{
return ept->ops->trysendto(ept, data, len, dst);
}
int rpmsg_trysend_offchannel(struct rpmsg_endpoint *ept, u32 src, u32 dst,
void *data, int len)
{
return ept->ops->trysend_offchannel(ept, src, dst, data, len);
}
static int rpmsg_device_match(struct device *dev, void *data)
{
struct rpmsg_channel_info *chinfo = data;
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
if (chinfo->src != RPMSG_ADDR_ANY && chinfo->src != rpdev->src)
return 0;
if (chinfo->dst != RPMSG_ADDR_ANY && chinfo->dst != rpdev->dst)
return 0;
if (strncmp(chinfo->name, rpdev->id.name, RPMSG_NAME_SIZE))
return 0;
return 1;
}
struct device *rpmsg_find_device(struct device *parent,
struct rpmsg_channel_info *chinfo)
{
return device_find_child(parent, chinfo, rpmsg_device_match);
}
static ssize_t modalias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
return sprintf(buf, RPMSG_DEVICE_MODALIAS_FMT "\n", rpdev->id.name);
}
static inline int rpmsg_id_match(const struct rpmsg_device *rpdev,
const struct rpmsg_device_id *id)
{
return strncmp(id->name, rpdev->id.name, RPMSG_NAME_SIZE) == 0;
}
static int rpmsg_dev_match(struct device *dev, struct device_driver *drv)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
struct rpmsg_driver *rpdrv = to_rpmsg_driver(drv);
const struct rpmsg_device_id *ids = rpdrv->id_table;
unsigned int i;
if (ids)
for (i = 0; ids[i].name[0]; i++)
if (rpmsg_id_match(rpdev, &ids[i]))
return 1;
return of_driver_match_device(dev, drv);
}
static int rpmsg_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
return add_uevent_var(env, "MODALIAS=" RPMSG_DEVICE_MODALIAS_FMT,
rpdev->id.name);
}
static int rpmsg_dev_probe(struct device *dev)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
struct rpmsg_driver *rpdrv = to_rpmsg_driver(rpdev->dev.driver);
struct rpmsg_channel_info chinfo = {};
struct rpmsg_endpoint *ept;
int err;
strncpy(chinfo.name, rpdev->id.name, RPMSG_NAME_SIZE);
chinfo.src = rpdev->src;
chinfo.dst = RPMSG_ADDR_ANY;
ept = rpmsg_create_ept(rpdev, rpdrv->callback, NULL, chinfo);
if (!ept) {
dev_err(dev, "failed to create endpoint\n");
err = -ENOMEM;
goto out;
}
rpdev->ept = ept;
rpdev->src = ept->addr;
err = rpdrv->probe(rpdev);
if (err) {
dev_err(dev, "%s: failed: %d\n", __func__, err);
rpmsg_destroy_ept(ept);
goto out;
}
if (rpdev->ops->announce_create)
err = rpdev->ops->announce_create(rpdev);
out:
return err;
}
static int rpmsg_dev_remove(struct device *dev)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
struct rpmsg_driver *rpdrv = to_rpmsg_driver(rpdev->dev.driver);
int err = 0;
if (rpdev->ops->announce_destroy)
err = rpdev->ops->announce_destroy(rpdev);
rpdrv->remove(rpdev);
rpmsg_destroy_ept(rpdev->ept);
return err;
}
static void rpmsg_release_device(struct device *dev)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
kfree(rpdev);
}
int rpmsg_register_device(struct rpmsg_device *rpdev)
{
struct device *dev = &rpdev->dev;
int ret;
dev_set_name(&rpdev->dev, "%s:%s",
dev_name(dev->parent), rpdev->id.name);
rpdev->dev.bus = &rpmsg_bus;
rpdev->dev.release = rpmsg_release_device;
ret = device_register(&rpdev->dev);
if (ret) {
dev_err(dev, "device_register failed: %d\n", ret);
put_device(&rpdev->dev);
}
return ret;
}
int rpmsg_unregister_device(struct device *parent,
struct rpmsg_channel_info *chinfo)
{
struct device *dev;
dev = rpmsg_find_device(parent, chinfo);
if (!dev)
return -EINVAL;
device_unregister(dev);
put_device(dev);
return 0;
}
int __register_rpmsg_driver(struct rpmsg_driver *rpdrv, struct module *owner)
{
rpdrv->drv.bus = &rpmsg_bus;
rpdrv->drv.owner = owner;
return driver_register(&rpdrv->drv);
}
void unregister_rpmsg_driver(struct rpmsg_driver *rpdrv)
{
driver_unregister(&rpdrv->drv);
}
static int __init rpmsg_init(void)
{
int ret;
ret = bus_register(&rpmsg_bus);
if (ret)
pr_err("failed to register rpmsg bus: %d\n", ret);
return ret;
}
static void __exit rpmsg_fini(void)
{
bus_unregister(&rpmsg_bus);
}
