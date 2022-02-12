static enum led_brightness
nouveau_led_get_brightness(struct led_classdev *led)
{
struct drm_device *drm_dev = container_of(led, struct nouveau_led, led)->dev;
struct nouveau_drm *drm = nouveau_drm(drm_dev);
struct nvif_object *device = &drm->client.device.object;
u32 div, duty;
div = nvif_rd32(device, 0x61c880) & 0x00ffffff;
duty = nvif_rd32(device, 0x61c884) & 0x00ffffff;
if (div > 0)
return duty * LED_FULL / div;
else
return 0;
}
static void
nouveau_led_set_brightness(struct led_classdev *led, enum led_brightness value)
{
struct drm_device *drm_dev = container_of(led, struct nouveau_led, led)->dev;
struct nouveau_drm *drm = nouveau_drm(drm_dev);
struct nvif_object *device = &drm->client.device.object;
u32 input_clk = 27e6;
u32 freq = 100;
u32 div, duty;
div = input_clk / freq;
duty = value * div / LED_FULL;
nvif_wr32(device, 0x61c880, div);
nvif_wr32(device, 0x61c884, 0xc0000000 | duty);
}
int
nouveau_led_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_gpio *gpio = nvxx_gpio(&drm->client.device);
struct dcb_gpio_func logo_led;
int ret;
if (!gpio)
return 0;
if (nvkm_gpio_find(gpio, 0, DCB_GPIO_LOGO_LED_PWM, 0xff, &logo_led))
return 0;
drm->led = kzalloc(sizeof(*drm->led), GFP_KERNEL);
if (!drm->led)
return -ENOMEM;
drm->led->dev = dev;
drm->led->led.name = "nvidia-logo";
drm->led->led.max_brightness = 255;
drm->led->led.brightness_get = nouveau_led_get_brightness;
drm->led->led.brightness_set = nouveau_led_set_brightness;
ret = led_classdev_register(dev->dev, &drm->led->led);
if (ret) {
kfree(drm->led);
drm->led = NULL;
return ret;
}
return 0;
}
void
nouveau_led_suspend(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->led)
led_classdev_suspend(&drm->led->led);
}
void
nouveau_led_resume(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->led)
led_classdev_resume(&drm->led->led);
}
void
nouveau_led_fini(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->led) {
led_classdev_unregister(&drm->led->led);
kfree(drm->led);
drm->led = NULL;
}
}
