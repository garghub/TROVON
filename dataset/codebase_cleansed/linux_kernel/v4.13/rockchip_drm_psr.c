static struct psr_drv *find_psr_by_crtc(struct drm_crtc *crtc)
{
struct rockchip_drm_private *drm_drv = crtc->dev->dev_private;
struct psr_drv *psr;
unsigned long flags;
spin_lock_irqsave(&drm_drv->psr_list_lock, flags);
list_for_each_entry(psr, &drm_drv->psr_list, list) {
if (psr->encoder->crtc == crtc)
goto out;
}
psr = ERR_PTR(-ENODEV);
out:
spin_unlock_irqrestore(&drm_drv->psr_list_lock, flags);
return psr;
}
static void psr_set_state_locked(struct psr_drv *psr, enum psr_state state)
{
if (state == psr->state || !psr->active)
return;
if (state == PSR_DISABLE && psr->state == PSR_FLUSH) {
psr->state = state;
return;
}
psr->state = state;
switch (psr->state) {
case PSR_ENABLE:
psr->set(psr->encoder, true);
break;
case PSR_DISABLE:
case PSR_FLUSH:
psr->set(psr->encoder, false);
break;
}
}
static void psr_set_state(struct psr_drv *psr, enum psr_state state)
{
unsigned long flags;
spin_lock_irqsave(&psr->lock, flags);
psr_set_state_locked(psr, state);
spin_unlock_irqrestore(&psr->lock, flags);
}
static void psr_flush_handler(unsigned long data)
{
struct psr_drv *psr = (struct psr_drv *)data;
unsigned long flags;
spin_lock_irqsave(&psr->lock, flags);
if (psr->state == PSR_FLUSH)
psr_set_state_locked(psr, PSR_ENABLE);
spin_unlock_irqrestore(&psr->lock, flags);
}
int rockchip_drm_psr_activate(struct drm_crtc *crtc)
{
struct psr_drv *psr = find_psr_by_crtc(crtc);
unsigned long flags;
if (IS_ERR(psr))
return PTR_ERR(psr);
spin_lock_irqsave(&psr->lock, flags);
psr->active = true;
spin_unlock_irqrestore(&psr->lock, flags);
return 0;
}
int rockchip_drm_psr_deactivate(struct drm_crtc *crtc)
{
struct psr_drv *psr = find_psr_by_crtc(crtc);
unsigned long flags;
if (IS_ERR(psr))
return PTR_ERR(psr);
spin_lock_irqsave(&psr->lock, flags);
psr->active = false;
spin_unlock_irqrestore(&psr->lock, flags);
del_timer_sync(&psr->flush_timer);
return 0;
}
static void rockchip_drm_do_flush(struct psr_drv *psr)
{
mod_timer(&psr->flush_timer,
round_jiffies_up(jiffies + PSR_FLUSH_TIMEOUT));
psr_set_state(psr, PSR_FLUSH);
}
int rockchip_drm_psr_flush(struct drm_crtc *crtc)
{
struct psr_drv *psr = find_psr_by_crtc(crtc);
if (IS_ERR(psr))
return PTR_ERR(psr);
rockchip_drm_do_flush(psr);
return 0;
}
void rockchip_drm_psr_flush_all(struct drm_device *dev)
{
struct rockchip_drm_private *drm_drv = dev->dev_private;
struct psr_drv *psr;
unsigned long flags;
spin_lock_irqsave(&drm_drv->psr_list_lock, flags);
list_for_each_entry(psr, &drm_drv->psr_list, list)
rockchip_drm_do_flush(psr);
spin_unlock_irqrestore(&drm_drv->psr_list_lock, flags);
}
int rockchip_drm_psr_register(struct drm_encoder *encoder,
void (*psr_set)(struct drm_encoder *, bool enable))
{
struct rockchip_drm_private *drm_drv = encoder->dev->dev_private;
struct psr_drv *psr;
unsigned long flags;
if (!encoder || !psr_set)
return -EINVAL;
psr = kzalloc(sizeof(struct psr_drv), GFP_KERNEL);
if (!psr)
return -ENOMEM;
setup_timer(&psr->flush_timer, psr_flush_handler, (unsigned long)psr);
spin_lock_init(&psr->lock);
psr->active = true;
psr->state = PSR_DISABLE;
psr->encoder = encoder;
psr->set = psr_set;
spin_lock_irqsave(&drm_drv->psr_list_lock, flags);
list_add_tail(&psr->list, &drm_drv->psr_list);
spin_unlock_irqrestore(&drm_drv->psr_list_lock, flags);
return 0;
}
void rockchip_drm_psr_unregister(struct drm_encoder *encoder)
{
struct rockchip_drm_private *drm_drv = encoder->dev->dev_private;
struct psr_drv *psr, *n;
unsigned long flags;
spin_lock_irqsave(&drm_drv->psr_list_lock, flags);
list_for_each_entry_safe(psr, n, &drm_drv->psr_list, list) {
if (psr->encoder == encoder) {
del_timer(&psr->flush_timer);
list_del(&psr->list);
kfree(psr);
}
}
spin_unlock_irqrestore(&drm_drv->psr_list_lock, flags);
}
