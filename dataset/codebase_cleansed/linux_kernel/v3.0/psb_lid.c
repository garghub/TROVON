static void psb_lid_timer_func(unsigned long data)
{
struct drm_psb_private * dev_priv = (struct drm_psb_private *)data;
struct drm_device *dev = (struct drm_device *)dev_priv->dev;
struct timer_list *lid_timer = &dev_priv->lid_timer;
unsigned long irq_flags;
u32 *lid_state = dev_priv->lid_state;
u32 pp_status;
if (*lid_state == dev_priv->lid_last_state)
goto lid_timer_schedule;
if ((*lid_state) & 0x01) {
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) | POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while ((pp_status & PP_ON) == 0);
psb_intel_lvds_set_brightness(dev, 100);
} else {
psb_intel_lvds_set_brightness(dev, 0);
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) & ~POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while ((pp_status & PP_ON) == 0);
}
dev_priv->lid_last_state = *lid_state;
lid_timer_schedule:
spin_lock_irqsave(&dev_priv->lid_lock, irq_flags);
if (!timer_pending(lid_timer)) {
lid_timer->expires = jiffies + PSB_LID_DELAY;
add_timer(lid_timer);
}
spin_unlock_irqrestore(&dev_priv->lid_lock, irq_flags);
}
void psb_lid_timer_init(struct drm_psb_private *dev_priv)
{
struct timer_list *lid_timer = &dev_priv->lid_timer;
unsigned long irq_flags;
spin_lock_init(&dev_priv->lid_lock);
spin_lock_irqsave(&dev_priv->lid_lock, irq_flags);
init_timer(lid_timer);
lid_timer->data = (unsigned long)dev_priv;
lid_timer->function = psb_lid_timer_func;
lid_timer->expires = jiffies + PSB_LID_DELAY;
add_timer(lid_timer);
spin_unlock_irqrestore(&dev_priv->lid_lock, irq_flags);
}
void psb_lid_timer_takedown(struct drm_psb_private *dev_priv)
{
del_timer_sync(&dev_priv->lid_timer);
}
