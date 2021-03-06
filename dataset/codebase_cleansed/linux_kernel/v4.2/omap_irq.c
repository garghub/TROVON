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
assert_spin_locked(&list_lock);
list_for_each_entry(irq, &priv->irq_list, node)
irqmask |= irq->irqmask;
DBG("irqmask=%08x", irqmask);
dispc_write_irqenable(irqmask);
dispc_read_irqenable();
}
void __omap_irq_register(struct drm_device *dev, struct omap_drm_irq *irq)
{
struct omap_drm_private *priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&list_lock, flags);
if (!WARN_ON(irq->registered)) {
irq->registered = true;
list_add(&irq->node, &priv->irq_list);
omap_irq_update(dev);
}
spin_unlock_irqrestore(&list_lock, flags);
}
void omap_irq_register(struct drm_device *dev, struct omap_drm_irq *irq)
{
dispc_runtime_get();
__omap_irq_register(dev, irq);
dispc_runtime_put();
}
void __omap_irq_unregister(struct drm_device *dev, struct omap_drm_irq *irq)
{
unsigned long flags;
spin_lock_irqsave(&list_lock, flags);
if (!WARN_ON(!irq->registered)) {
irq->registered = false;
list_del(&irq->node);
omap_irq_update(dev);
}
spin_unlock_irqrestore(&list_lock, flags);
}
void omap_irq_unregister(struct drm_device *dev, struct omap_drm_irq *irq)
{
dispc_runtime_get();
__omap_irq_unregister(dev, irq);
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
spin_lock_irqsave(&list_lock, flags);
priv->vblank_mask |= pipe2vbl(crtc);
omap_irq_update(dev);
spin_unlock_irqrestore(&list_lock, flags);
return 0;
}
void omap_irq_disable_vblank(struct drm_device *dev, int crtc_id)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_crtc *crtc = priv->crtcs[crtc_id];
unsigned long flags;
DBG("dev=%p, crtc=%d", dev, crtc_id);
spin_lock_irqsave(&list_lock, flags);
priv->vblank_mask &= ~pipe2vbl(crtc);
omap_irq_update(dev);
spin_unlock_irqrestore(&list_lock, flags);
}
static irqreturn_t omap_irq_handler(int irq, void *arg)
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
int omap_drm_irq_install(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_drm_irq *error_handler = &priv->error_handler;
int ret;
INIT_LIST_HEAD(&priv->irq_list);
dispc_runtime_get();
dispc_clear_irqstatus(0xffffffff);
dispc_runtime_put();
ret = dispc_request_irq(omap_irq_handler, dev);
if (ret < 0)
return ret;
error_handler->irq = omap_irq_error_handler;
error_handler->irqmask = DISPC_IRQ_OCP_ERR;
error_handler->irqmask &= ~DISPC_IRQ_SYNC_LOST_DIGIT;
omap_irq_register(dev, error_handler);
dev->irq_enabled = true;
return 0;
}
void omap_drm_irq_uninstall(struct drm_device *dev)
{
unsigned long irqflags;
int i;
if (!dev->irq_enabled)
return;
dev->irq_enabled = false;
if (dev->num_crtcs) {
spin_lock_irqsave(&dev->vbl_lock, irqflags);
for (i = 0; i < dev->num_crtcs; i++) {
wake_up(&dev->vblank[i].queue);
dev->vblank[i].enabled = false;
dev->vblank[i].last =
dev->driver->get_vblank_counter(dev, i);
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
dispc_free_irq(dev);
}
