static inline struct nic78bx_led *to_nic78bx_led(struct led_classdev *cdev)
{
return container_of(cdev, struct nic78bx_led, cdev);
}
static void nic78bx_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct nic78bx_led *nled = to_nic78bx_led(cdev);
unsigned long flags;
u8 value;
spin_lock_irqsave(&nled->data->lock, flags);
value = inb(nled->data->io_base);
if (brightness) {
value &= ~nled->mask;
value |= nled->bit;
} else {
value &= ~nled->bit;
}
outb(value, nled->data->io_base);
spin_unlock_irqrestore(&nled->data->lock, flags);
}
static enum led_brightness nic78bx_brightness_get(struct led_classdev *cdev)
{
struct nic78bx_led *nled = to_nic78bx_led(cdev);
unsigned long flags;
u8 value;
spin_lock_irqsave(&nled->data->lock, flags);
value = inb(nled->data->io_base);
spin_unlock_irqrestore(&nled->data->lock, flags);
return (value & nled->bit) ? 1 : LED_OFF;
}
static int nic78bx_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct nic78bx_led_data *led_data;
struct resource *io_rc;
int ret, i;
led_data = devm_kzalloc(dev, sizeof(*led_data), GFP_KERNEL);
if (!led_data)
return -ENOMEM;
led_data->pdev = pdev;
platform_set_drvdata(pdev, led_data);
io_rc = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!io_rc) {
dev_err(dev, "missing IO resources\n");
return -EINVAL;
}
if (resource_size(io_rc) < NIC78BX_USER_LED_IO_SIZE) {
dev_err(dev, "IO region too small\n");
return -EINVAL;
}
if (!devm_request_region(dev, io_rc->start, resource_size(io_rc),
KBUILD_MODNAME)) {
dev_err(dev, "failed to get IO region\n");
return -EBUSY;
}
led_data->io_base = io_rc->start;
spin_lock_init(&led_data->lock);
for (i = 0; i < ARRAY_SIZE(nic78bx_leds); i++) {
nic78bx_leds[i].data = led_data;
ret = devm_led_classdev_register(dev, &nic78bx_leds[i].cdev);
if (ret)
return ret;
}
outb(NIC78BX_UNLOCK_VALUE,
led_data->io_base + NIC78BX_LOCK_REG_OFFSET);
return ret;
}
static int nic78bx_remove(struct platform_device *pdev)
{
struct nic78bx_led_data *led_data = platform_get_drvdata(pdev);
outb(NIC78BX_LOCK_VALUE,
led_data->io_base + NIC78BX_LOCK_REG_OFFSET);
return 0;
}
