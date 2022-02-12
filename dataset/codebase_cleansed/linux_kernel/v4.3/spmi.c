static void spmi_dev_release(struct device *dev)
{
struct spmi_device *sdev = to_spmi_device(dev);
kfree(sdev);
}
static void spmi_ctrl_release(struct device *dev)
{
struct spmi_controller *ctrl = to_spmi_controller(dev);
ida_simple_remove(&ctrl_ida, ctrl->nr);
kfree(ctrl);
}
static int spmi_device_match(struct device *dev, struct device_driver *drv)
{
if (of_driver_match_device(dev, drv))
return 1;
if (drv->name)
return strncmp(dev_name(dev), drv->name,
SPMI_NAME_SIZE) == 0;
return 0;
}
int spmi_device_add(struct spmi_device *sdev)
{
struct spmi_controller *ctrl = sdev->ctrl;
int err;
dev_set_name(&sdev->dev, "%d-%02x", ctrl->nr, sdev->usid);
err = device_add(&sdev->dev);
if (err < 0) {
dev_err(&sdev->dev, "Can't add %s, status %d\n",
dev_name(&sdev->dev), err);
goto err_device_add;
}
dev_dbg(&sdev->dev, "device %s registered\n", dev_name(&sdev->dev));
err_device_add:
return err;
}
void spmi_device_remove(struct spmi_device *sdev)
{
device_unregister(&sdev->dev);
}
static inline int
spmi_cmd(struct spmi_controller *ctrl, u8 opcode, u8 sid)
{
int ret;
if (!ctrl || !ctrl->cmd || ctrl->dev.type != &spmi_ctrl_type)
return -EINVAL;
ret = ctrl->cmd(ctrl, opcode, sid);
trace_spmi_cmd(opcode, sid, ret);
return ret;
}
static inline int spmi_read_cmd(struct spmi_controller *ctrl, u8 opcode,
u8 sid, u16 addr, u8 *buf, size_t len)
{
int ret;
if (!ctrl || !ctrl->read_cmd || ctrl->dev.type != &spmi_ctrl_type)
return -EINVAL;
trace_spmi_read_begin(opcode, sid, addr);
ret = ctrl->read_cmd(ctrl, opcode, sid, addr, buf, len);
trace_spmi_read_end(opcode, sid, addr, ret, len, buf);
return ret;
}
static inline int spmi_write_cmd(struct spmi_controller *ctrl, u8 opcode,
u8 sid, u16 addr, const u8 *buf, size_t len)
{
int ret;
if (!ctrl || !ctrl->write_cmd || ctrl->dev.type != &spmi_ctrl_type)
return -EINVAL;
trace_spmi_write_begin(opcode, sid, addr, len, buf);
ret = ctrl->write_cmd(ctrl, opcode, sid, addr, buf, len);
trace_spmi_write_end(opcode, sid, addr, ret);
return ret;
}
int spmi_register_read(struct spmi_device *sdev, u8 addr, u8 *buf)
{
if (addr > 0x1F)
return -EINVAL;
return spmi_read_cmd(sdev->ctrl, SPMI_CMD_READ, sdev->usid, addr,
buf, 1);
}
int spmi_ext_register_read(struct spmi_device *sdev, u8 addr, u8 *buf,
size_t len)
{
if (len == 0 || len > 16)
return -EINVAL;
return spmi_read_cmd(sdev->ctrl, SPMI_CMD_EXT_READ, sdev->usid, addr,
buf, len);
}
int spmi_ext_register_readl(struct spmi_device *sdev, u16 addr, u8 *buf,
size_t len)
{
if (len == 0 || len > 8)
return -EINVAL;
return spmi_read_cmd(sdev->ctrl, SPMI_CMD_EXT_READL, sdev->usid, addr,
buf, len);
}
int spmi_register_write(struct spmi_device *sdev, u8 addr, u8 data)
{
if (addr > 0x1F)
return -EINVAL;
return spmi_write_cmd(sdev->ctrl, SPMI_CMD_WRITE, sdev->usid, addr,
&data, 1);
}
int spmi_register_zero_write(struct spmi_device *sdev, u8 data)
{
return spmi_write_cmd(sdev->ctrl, SPMI_CMD_ZERO_WRITE, sdev->usid, 0,
&data, 1);
}
int spmi_ext_register_write(struct spmi_device *sdev, u8 addr, const u8 *buf,
size_t len)
{
if (len == 0 || len > 16)
return -EINVAL;
return spmi_write_cmd(sdev->ctrl, SPMI_CMD_EXT_WRITE, sdev->usid, addr,
buf, len);
}
int spmi_ext_register_writel(struct spmi_device *sdev, u16 addr, const u8 *buf,
size_t len)
{
if (len == 0 || len > 8)
return -EINVAL;
return spmi_write_cmd(sdev->ctrl, SPMI_CMD_EXT_WRITEL, sdev->usid,
addr, buf, len);
}
int spmi_command_reset(struct spmi_device *sdev)
{
return spmi_cmd(sdev->ctrl, SPMI_CMD_RESET, sdev->usid);
}
int spmi_command_sleep(struct spmi_device *sdev)
{
return spmi_cmd(sdev->ctrl, SPMI_CMD_SLEEP, sdev->usid);
}
int spmi_command_wakeup(struct spmi_device *sdev)
{
return spmi_cmd(sdev->ctrl, SPMI_CMD_WAKEUP, sdev->usid);
}
int spmi_command_shutdown(struct spmi_device *sdev)
{
return spmi_cmd(sdev->ctrl, SPMI_CMD_SHUTDOWN, sdev->usid);
}
static int spmi_drv_probe(struct device *dev)
{
const struct spmi_driver *sdrv = to_spmi_driver(dev->driver);
struct spmi_device *sdev = to_spmi_device(dev);
int err;
pm_runtime_get_noresume(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
err = sdrv->probe(sdev);
if (err)
goto fail_probe;
return 0;
fail_probe:
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
pm_runtime_put_noidle(dev);
return err;
}
static int spmi_drv_remove(struct device *dev)
{
const struct spmi_driver *sdrv = to_spmi_driver(dev->driver);
pm_runtime_get_sync(dev);
sdrv->remove(to_spmi_device(dev));
pm_runtime_put_noidle(dev);
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
pm_runtime_put_noidle(dev);
return 0;
}
struct spmi_device *spmi_device_alloc(struct spmi_controller *ctrl)
{
struct spmi_device *sdev;
sdev = kzalloc(sizeof(*sdev), GFP_KERNEL);
if (!sdev)
return NULL;
sdev->ctrl = ctrl;
device_initialize(&sdev->dev);
sdev->dev.parent = &ctrl->dev;
sdev->dev.bus = &spmi_bus_type;
sdev->dev.type = &spmi_dev_type;
return sdev;
}
struct spmi_controller *spmi_controller_alloc(struct device *parent,
size_t size)
{
struct spmi_controller *ctrl;
int id;
if (WARN_ON(!parent))
return NULL;
ctrl = kzalloc(sizeof(*ctrl) + size, GFP_KERNEL);
if (!ctrl)
return NULL;
device_initialize(&ctrl->dev);
ctrl->dev.type = &spmi_ctrl_type;
ctrl->dev.bus = &spmi_bus_type;
ctrl->dev.parent = parent;
ctrl->dev.of_node = parent->of_node;
spmi_controller_set_drvdata(ctrl, &ctrl[1]);
id = ida_simple_get(&ctrl_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
dev_err(parent,
"unable to allocate SPMI controller identifier.\n");
spmi_controller_put(ctrl);
return NULL;
}
ctrl->nr = id;
dev_set_name(&ctrl->dev, "spmi-%d", id);
dev_dbg(&ctrl->dev, "allocated controller 0x%p id %d\n", ctrl, id);
return ctrl;
}
static void of_spmi_register_devices(struct spmi_controller *ctrl)
{
struct device_node *node;
int err;
if (!ctrl->dev.of_node)
return;
for_each_available_child_of_node(ctrl->dev.of_node, node) {
struct spmi_device *sdev;
u32 reg[2];
dev_dbg(&ctrl->dev, "adding child %s\n", node->full_name);
err = of_property_read_u32_array(node, "reg", reg, 2);
if (err) {
dev_err(&ctrl->dev,
"node %s err (%d) does not have 'reg' property\n",
node->full_name, err);
continue;
}
if (reg[1] != SPMI_USID) {
dev_err(&ctrl->dev,
"node %s contains unsupported 'reg' entry\n",
node->full_name);
continue;
}
if (reg[0] >= SPMI_MAX_SLAVE_ID) {
dev_err(&ctrl->dev,
"invalid usid on node %s\n",
node->full_name);
continue;
}
dev_dbg(&ctrl->dev, "read usid %02x\n", reg[0]);
sdev = spmi_device_alloc(ctrl);
if (!sdev)
continue;
sdev->dev.of_node = node;
sdev->usid = (u8) reg[0];
err = spmi_device_add(sdev);
if (err) {
dev_err(&sdev->dev,
"failure adding device. status %d\n", err);
spmi_device_put(sdev);
}
}
}
int spmi_controller_add(struct spmi_controller *ctrl)
{
int ret;
if (WARN_ON(!spmi_bus_type.p))
return -EAGAIN;
ret = device_add(&ctrl->dev);
if (ret)
return ret;
if (IS_ENABLED(CONFIG_OF))
of_spmi_register_devices(ctrl);
dev_dbg(&ctrl->dev, "spmi-%d registered: dev:%p\n",
ctrl->nr, &ctrl->dev);
return 0;
}
static int spmi_ctrl_remove_device(struct device *dev, void *data)
{
struct spmi_device *spmidev = to_spmi_device(dev);
if (dev->type == &spmi_dev_type)
spmi_device_remove(spmidev);
return 0;
}
void spmi_controller_remove(struct spmi_controller *ctrl)
{
int dummy;
if (!ctrl)
return;
dummy = device_for_each_child(&ctrl->dev, NULL,
spmi_ctrl_remove_device);
device_del(&ctrl->dev);
}
int spmi_driver_register(struct spmi_driver *sdrv)
{
sdrv->driver.bus = &spmi_bus_type;
return driver_register(&sdrv->driver);
}
static void __exit spmi_exit(void)
{
bus_unregister(&spmi_bus_type);
}
static int __init spmi_init(void)
{
return bus_register(&spmi_bus_type);
}
