static void img_ir_refresh_raw(struct img_ir_priv *priv, u32 irq_status)
{
struct img_ir_priv_raw *raw = &priv->raw;
struct rc_dev *rc_dev = priv->raw.rdev;
int multiple;
u32 ir_status;
multiple = ((irq_status & IMG_IR_IRQ_EDGE) == IMG_IR_IRQ_EDGE);
ir_status = img_ir_read(priv, IMG_IR_STATUS) & IMG_IR_IRRXD;
if (multiple && ir_status == raw->last_status)
return;
raw->last_status = ir_status;
if (ir_status)
ir_raw_event_store_edge(rc_dev, false);
else
ir_raw_event_store_edge(rc_dev, true);
ir_raw_event_handle(rc_dev);
}
void img_ir_isr_raw(struct img_ir_priv *priv, u32 irq_status)
{
struct img_ir_priv_raw *raw = &priv->raw;
if (!raw->rdev)
return;
img_ir_refresh_raw(priv, irq_status);
mod_timer(&raw->timer, jiffies + msecs_to_jiffies(ECHO_TIMEOUT_MS));
}
static void img_ir_echo_timer(unsigned long arg)
{
struct img_ir_priv *priv = (struct img_ir_priv *)arg;
spin_lock_irq(&priv->lock);
if (priv->raw.rdev)
img_ir_refresh_raw(priv, 0);
spin_unlock_irq(&priv->lock);
}
void img_ir_setup_raw(struct img_ir_priv *priv)
{
u32 irq_en;
if (!priv->raw.rdev)
return;
spin_lock_irq(&priv->lock);
irq_en = img_ir_read(priv, IMG_IR_IRQ_ENABLE);
irq_en |= IMG_IR_IRQ_EDGE;
img_ir_write(priv, IMG_IR_IRQ_CLEAR, IMG_IR_IRQ_EDGE);
img_ir_write(priv, IMG_IR_IRQ_ENABLE, irq_en);
spin_unlock_irq(&priv->lock);
}
int img_ir_probe_raw(struct img_ir_priv *priv)
{
struct img_ir_priv_raw *raw = &priv->raw;
struct rc_dev *rdev;
int error;
setup_timer(&raw->timer, img_ir_echo_timer, (unsigned long)priv);
raw->rdev = rdev = rc_allocate_device(RC_DRIVER_IR_RAW);
if (!rdev) {
dev_err(priv->dev, "cannot allocate raw input device\n");
return -ENOMEM;
}
rdev->priv = priv;
rdev->map_name = RC_MAP_EMPTY;
rdev->device_name = "IMG Infrared Decoder Raw";
error = rc_register_device(rdev);
if (error) {
dev_err(priv->dev, "failed to register raw IR input device\n");
rc_free_device(rdev);
raw->rdev = NULL;
return error;
}
return 0;
}
void img_ir_remove_raw(struct img_ir_priv *priv)
{
struct img_ir_priv_raw *raw = &priv->raw;
struct rc_dev *rdev = raw->rdev;
u32 irq_en;
if (!rdev)
return;
spin_lock_irq(&priv->lock);
raw->rdev = NULL;
irq_en = img_ir_read(priv, IMG_IR_IRQ_ENABLE);
irq_en &= ~IMG_IR_IRQ_EDGE;
img_ir_write(priv, IMG_IR_IRQ_ENABLE, irq_en);
img_ir_write(priv, IMG_IR_IRQ_CLEAR, IMG_IR_IRQ_EDGE);
spin_unlock_irq(&priv->lock);
rc_unregister_device(rdev);
del_timer_sync(&raw->timer);
}
