static int mcp_bus_match(struct device *dev, struct device_driver *drv)
{
return 1;
}
static int mcp_bus_probe(struct device *dev)
{
struct mcp *mcp = to_mcp(dev);
struct mcp_driver *drv = to_mcp_driver(dev->driver);
return drv->probe(mcp);
}
static int mcp_bus_remove(struct device *dev)
{
struct mcp *mcp = to_mcp(dev);
struct mcp_driver *drv = to_mcp_driver(dev->driver);
drv->remove(mcp);
return 0;
}
static int mcp_bus_suspend(struct device *dev, pm_message_t state)
{
struct mcp *mcp = to_mcp(dev);
int ret = 0;
if (dev->driver) {
struct mcp_driver *drv = to_mcp_driver(dev->driver);
ret = drv->suspend(mcp, state);
}
return ret;
}
static int mcp_bus_resume(struct device *dev)
{
struct mcp *mcp = to_mcp(dev);
int ret = 0;
if (dev->driver) {
struct mcp_driver *drv = to_mcp_driver(dev->driver);
ret = drv->resume(mcp);
}
return ret;
}
void mcp_set_telecom_divisor(struct mcp *mcp, unsigned int div)
{
spin_lock_irq(&mcp->lock);
mcp->ops->set_telecom_divisor(mcp, div);
spin_unlock_irq(&mcp->lock);
}
void mcp_set_audio_divisor(struct mcp *mcp, unsigned int div)
{
spin_lock_irq(&mcp->lock);
mcp->ops->set_audio_divisor(mcp, div);
spin_unlock_irq(&mcp->lock);
}
void mcp_reg_write(struct mcp *mcp, unsigned int reg, unsigned int val)
{
unsigned long flags;
spin_lock_irqsave(&mcp->lock, flags);
mcp->ops->reg_write(mcp, reg, val);
spin_unlock_irqrestore(&mcp->lock, flags);
}
unsigned int mcp_reg_read(struct mcp *mcp, unsigned int reg)
{
unsigned long flags;
unsigned int val;
spin_lock_irqsave(&mcp->lock, flags);
val = mcp->ops->reg_read(mcp, reg);
spin_unlock_irqrestore(&mcp->lock, flags);
return val;
}
void mcp_enable(struct mcp *mcp)
{
spin_lock_irq(&mcp->lock);
if (mcp->use_count++ == 0)
mcp->ops->enable(mcp);
spin_unlock_irq(&mcp->lock);
}
void mcp_disable(struct mcp *mcp)
{
unsigned long flags;
spin_lock_irqsave(&mcp->lock, flags);
if (--mcp->use_count == 0)
mcp->ops->disable(mcp);
spin_unlock_irqrestore(&mcp->lock, flags);
}
static void mcp_release(struct device *dev)
{
struct mcp *mcp = container_of(dev, struct mcp, attached_device);
kfree(mcp);
}
struct mcp *mcp_host_alloc(struct device *parent, size_t size)
{
struct mcp *mcp;
mcp = kzalloc(sizeof(struct mcp) + size, GFP_KERNEL);
if (mcp) {
spin_lock_init(&mcp->lock);
mcp->attached_device.parent = parent;
mcp->attached_device.bus = &mcp_bus_type;
mcp->attached_device.dma_mask = parent->dma_mask;
mcp->attached_device.release = mcp_release;
}
return mcp;
}
int mcp_host_register(struct mcp *mcp)
{
dev_set_name(&mcp->attached_device, "mcp0");
return device_register(&mcp->attached_device);
}
void mcp_host_unregister(struct mcp *mcp)
{
device_unregister(&mcp->attached_device);
}
int mcp_driver_register(struct mcp_driver *mcpdrv)
{
mcpdrv->drv.bus = &mcp_bus_type;
return driver_register(&mcpdrv->drv);
}
void mcp_driver_unregister(struct mcp_driver *mcpdrv)
{
driver_unregister(&mcpdrv->drv);
}
static int __init mcp_init(void)
{
return bus_register(&mcp_bus_type);
}
static void __exit mcp_exit(void)
{
bus_unregister(&mcp_bus_type);
}
