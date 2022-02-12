static void dac124s085_led_work(struct work_struct *work)
{
struct dac124s085_led *led = container_of(work, struct dac124s085_led,
work);
u16 word;
mutex_lock(&led->mutex);
word = cpu_to_le16(((led->id) << 14) | REG_WRITE_UPDATE |
(led->brightness & 0xfff));
spi_write(led->spi, (const u8 *)&word, sizeof(word));
mutex_unlock(&led->mutex);
}
static void dac124s085_set_brightness(struct led_classdev *ldev,
enum led_brightness brightness)
{
struct dac124s085_led *led = container_of(ldev, struct dac124s085_led,
ldev);
spin_lock(&led->lock);
led->brightness = brightness;
schedule_work(&led->work);
spin_unlock(&led->lock);
}
static int dac124s085_probe(struct spi_device *spi)
{
struct dac124s085 *dac;
struct dac124s085_led *led;
int i, ret;
dac = kzalloc(sizeof(*dac), GFP_KERNEL);
if (!dac)
return -ENOMEM;
spi->bits_per_word = 16;
for (i = 0; i < ARRAY_SIZE(dac->leds); i++) {
led = dac->leds + i;
led->id = i;
led->brightness = LED_OFF;
led->spi = spi;
snprintf(led->name, sizeof(led->name), "dac124s085-%d", i);
spin_lock_init(&led->lock);
INIT_WORK(&led->work, dac124s085_led_work);
mutex_init(&led->mutex);
led->ldev.name = led->name;
led->ldev.brightness = LED_OFF;
led->ldev.max_brightness = 0xfff;
led->ldev.brightness_set = dac124s085_set_brightness;
ret = led_classdev_register(&spi->dev, &led->ldev);
if (ret < 0)
goto eledcr;
}
spi_set_drvdata(spi, dac);
return 0;
eledcr:
while (i--)
led_classdev_unregister(&dac->leds[i].ldev);
spi_set_drvdata(spi, NULL);
kfree(dac);
return ret;
}
static int dac124s085_remove(struct spi_device *spi)
{
struct dac124s085 *dac = spi_get_drvdata(spi);
int i;
for (i = 0; i < ARRAY_SIZE(dac->leds); i++) {
led_classdev_unregister(&dac->leds[i].ldev);
cancel_work_sync(&dac->leds[i].work);
}
spi_set_drvdata(spi, NULL);
kfree(dac);
return 0;
}
