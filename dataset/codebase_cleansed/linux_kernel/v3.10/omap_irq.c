static void omap_irq_error_handler(struct omap_drm_irq *irq,
uint32_t irqstatus)
{
DRM_ERROR("errors: %08x\n", irqstatus);
}
static void omap_irq_update(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_drm_irq *irq;
uint32_t irqmask = priv->vblank_mask;
BUG_ON(!spin_is_locked(&list_lock));
list_for_each_entry(irq, &priv->irq_list, node)
irqmask |= irq->irqmask;
DBG("irqmask=%08x", irqmask);
dispc_write_irqenable(irqmask);
dispc_read_irqenable();
}
void omap_irq_register(struct drm_device *dev, struct omap_drm_irq *irq)
{
struct omap_drm_private *priv = dev->dev_private;
unsigned long flags;
dispc_runtime_get();
spin_lock_irqsave(&list_lock, flags);
if (!WARN_ON(irq->registered)) {
irq->registered = true;
list_add(&irq->node, &priv->irq_list);
omap_irq_update(dev);
}
spin_unlock_irqrestore(&list_lock, flags);
dispc_runtime_put();
}
void omap_irq_unregister(struct drm_device *dev, struct omap_drm_irq *irq)
{
unsigned long flags;
dispc_runtime_get();
spin_lock_irqsave(&list_lock, flags);
if (!WARN_ON(!irq->registered)) {
irq->registered = false;
list_del(&irq->node);
omap_irq_update(dev);
}
spin_unlock_irqrestore(&list_lock, flags);
dispc_runtime_put();
}
static void wait_irq(struct omap_drm_irq *irq, uint32_t irqstatus)
{
struct omap_irq_wait *wait =
container_of(irq, struct omap_irq_wait, irq);
wait->count--;
wake_up_all(&wait_event);
}
struct omap_irq_wait * omap_irq_wait_init(struct drm_device *dev,
uint32_t irqmask, int count)
{
struct omap_irq_wait *wait = kzalloc(sizeof(*wait), GFP_KERNEL);
wait->irq.irq = wait_irq;
wait->irq.irqmask = irqmask;
wait->count = count;
omap_irq_register(dev, &wait->irq);
return wait;
}
int omap_irq_wait(struct drm_device *dev, struct omap_irq_wait *wait,
unsigned long timeout)
{
int ret = wait_event_timeout(wait_event, (wait->count <= 0), timeout);
omap_irq_unregister(dev, &wait->irq);
kfree(wait);
if (ret == 0)
return -1;
return 0;
}
int omap_irq_enable_vblank(struct drm_device *dev, int crtc_id)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_crtc *crtc = priv->crtcs[crtc_id];
unsigned long flags;
DBG("dev=%p, crtc=%d", dev, crtc_id);
dispc_runtime_get();
spin_lock_irqsave(&list_lock, flags);
priv->vblank_mask |= pipe2vbl(crtc);
omap_irq_update(dev);
spin_unlock_irqrestore(&list_lock, flags);
dispc_runtime_put();
return 0;
}
void omap_irq_disable_vblank(struct drm_device *dev, int crtc_id)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_crtc *crtc = priv->crtcs[crtc_id];
unsigned long flags;
DBG("dev=%p, crtc=%d", dev, crtc_id);
dispc_runtime_get();
spin_lock_irqsave(&list_lock, flags);
priv->vblank_mask &= ~pipe2vbl(crtc);
omap_irq_update(dev);
spin_unlock_irqrestore(&list_lock, flags);
dispc_runtime_put();
}
irqreturn_t omap_irq_handler(DRM_IRQ_ARGS)
{
struct drm_device *dev = (struct drm_device *) arg;
struct omap_drm_private *priv = dev->dev_private;
struct omap_drm_irq *handler, *n;
unsigned long flags;
unsigned int id;
u32 irqstatus;
irqstatus = dispc_read_irqstatus();
dispc_clear_irqstatus(irqstatus);
dispc_read_irqstatus();
VERB("irqs: %08x", irqstatus);
for (id = 0; id < priv->num_crtcs; id++) {
struct drm_crtc *crtc = priv->crtcs[id];
if (irqstatus & pipe2vbl(crtc))
drm_handle_vblank(dev, id);
}
spin_lock_irqsave(&list_lock, flags);
list_for_each_entry_safe(handler, n, &priv->irq_list, node) {
if (handler->irqmask & irqstatus) {
spin_unlock_irqrestore(&list_lock, flags);
handler->irq(handler, handler->irqmask & irqstatus);
spin_lock_irqsave(&list_lock, flags);
}
}
spin_unlock_irqrestore(&list_lock, flags);
return IRQ_HANDLED;
}
void omap_irq_preinstall(struct drm_device *dev)
{
DBG("dev=%p", dev);
dispc_runtime_get();
dispc_clear_irqstatus(0xffffffff);
dispc_runtime_put();
}
int omap_irq_postinstall(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_drm_irq *error_handler = &priv->error_handler;
DBG("dev=%p", dev);
INIT_LIST_HEAD(&priv->irq_list);
error_handler->irq = omap_irq_error_handler;
error_handler->irqmask = DISPC_IRQ_OCP_ERR;
error_handler->irqmask &= ~DISPC_IRQ_SYNC_LOST_DIGIT;
omap_irq_register(dev, error_handler);
return 0;
}
void omap_irq_uninstall(struct drm_device *dev)
{
DBG("dev=%p", dev);
}
int omap_drm_irq_install(struct drm_device *dev)
{
int ret;
mutex_lock(&dev->struct_mutex);
if (dev->irq_enabled) {
mutex_unlock(&dev->struct_mutex);
return -EBUSY;
}
dev->irq_enabled = 1;
mutex_unlock(&dev->struct_mutex);
if (dev->driver->irq_preinstall)
dev->driver->irq_preinstall(dev);
ret = dispc_request_irq(dev->driver->irq_handler, dev);
if (ret < 0) {
mutex_lock(&dev->struct_mutex);
dev->irq_enabled = 0;
mutex_unlock(&dev->struct_mutex);
return ret;
}
if (dev->driver->irq_postinstall)
ret = dev->driver->irq_postinstall(dev);
if (ret < 0) {
mutex_lock(&dev->struct_mutex);
dev->irq_enabled = 0;
mutex_unlock(&dev->struct_mutex);
dispc_free_irq(dev);
}
return ret;
}
int omap_drm_irq_uninstall(struct drm_device *dev)
{
unsigned long irqflags;
int irq_enabled, i;
mutex_lock(&dev->struct_mutex);
irq_enabled = dev->irq_enabled;
dev->irq_enabled = 0;
mutex_unlock(&dev->struct_mutex);
if (dev->num_crtcs) {
spin_lock_irqsave(&dev->vbl_lock, irqflags);
for (i = 0; i < dev->num_crtcs; i++) {
DRM_WAKEUP(&dev->vbl_queue[i]);
dev->vblank_enabled[i] = 0;
dev->last_vblank[i] =
dev->driver->get_vblank_counter(dev, i);
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
if (!irq_enabled)
return -EINVAL;
if (dev->driver->irq_uninstall)
dev->driver->irq_uninstall(dev);
dispc_free_irq(dev);
return 0;
}
