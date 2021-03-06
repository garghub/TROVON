static int ht16k33_display_on(struct ht16k33_priv *priv)
{
uint8_t data = REG_DISPLAY_SETUP | REG_DISPLAY_SETUP_ON;
return i2c_smbus_write_byte(priv->client, data);
}
static int ht16k33_display_off(struct ht16k33_priv *priv)
{
return i2c_smbus_write_byte(priv->client, REG_DISPLAY_SETUP);
}
static void ht16k33_fb_queue(struct ht16k33_priv *priv)
{
struct ht16k33_fbdev *fbdev = &priv->fbdev;
queue_delayed_work(priv->workqueue, &fbdev->work,
msecs_to_jiffies(HZ / fbdev->refresh_rate));
}
static void ht16k33_keypad_queue(struct ht16k33_priv *priv)
{
struct ht16k33_keypad *keypad = &priv->keypad;
queue_delayed_work(priv->workqueue, &keypad->work,
msecs_to_jiffies(keypad->debounce_ms));
}
static void ht16k33_fb_update(struct work_struct *work)
{
struct ht16k33_fbdev *fbdev =
container_of(work, struct ht16k33_fbdev, work.work);
struct ht16k33_priv *priv =
container_of(fbdev, struct ht16k33_priv, fbdev);
uint8_t *p1, *p2;
int len, pos = 0, first = -1;
p1 = fbdev->cache;
p2 = fbdev->buffer;
while (pos < HT16K33_FB_SIZE && first < 0) {
if (*(p1++) - *(p2++))
first = pos;
pos++;
}
if (first < 0)
goto requeue;
len = HT16K33_FB_SIZE - first;
p1 = fbdev->cache + HT16K33_FB_SIZE - 1;
p2 = fbdev->buffer + HT16K33_FB_SIZE - 1;
while (len > 1) {
if (*(p1--) - *(p2--))
break;
len--;
}
p1 = fbdev->cache + first;
p2 = fbdev->buffer + first;
if (!i2c_smbus_write_i2c_block_data(priv->client, first, len, p2))
memcpy(p1, p2, len);
requeue:
ht16k33_fb_queue(priv);
}
static int ht16k33_keypad_start(struct input_dev *dev)
{
struct ht16k33_priv *priv = input_get_drvdata(dev);
struct ht16k33_keypad *keypad = &priv->keypad;
queue_delayed_work(priv->workqueue, &keypad->work, 0);
return 0;
}
static void ht16k33_keypad_stop(struct input_dev *dev)
{
struct ht16k33_priv *priv = input_get_drvdata(dev);
struct ht16k33_keypad *keypad = &priv->keypad;
cancel_delayed_work(&keypad->work);
disable_irq_nosync(priv->client->irq);
}
static int ht16k33_initialize(struct ht16k33_priv *priv)
{
uint8_t byte;
int err;
uint8_t data[HT16K33_MATRIX_LED_MAX_COLS * 2];
memset(data, 0, sizeof(data));
err = i2c_smbus_write_block_data(priv->client, 0, sizeof(data), data);
if (err)
return err;
byte = REG_SYSTEM_SETUP_OSC_ON | REG_SYSTEM_SETUP;
err = i2c_smbus_write_byte(priv->client, byte);
if (err)
return err;
byte = REG_ROWINT_SET | REG_ROWINT_SET_INT_ACT_HIGH;
if (priv->client->irq > 0)
byte |= REG_ROWINT_SET_INT_EN;
return i2c_smbus_write_byte(priv->client, byte);
}
static void ht16k33_keypad_scan(struct work_struct *work)
{
struct ht16k33_keypad *keypad =
container_of(work, struct ht16k33_keypad, work.work);
struct ht16k33_priv *priv =
container_of(keypad, struct ht16k33_priv, keypad);
const unsigned short *keycodes = keypad->dev->keycode;
uint16_t bits_changed, new_state[HT16K33_MATRIX_KEYPAD_MAX_COLS];
uint8_t data[HT16K33_MATRIX_KEYPAD_MAX_COLS * 2];
int row, col, code;
bool reschedule = false;
if (i2c_smbus_read_i2c_block_data(priv->client, 0x40, 6, data) != 6) {
dev_err(&priv->client->dev, "Failed to read key data\n");
goto end;
}
for (col = 0; col < keypad->cols; col++) {
new_state[col] = (data[col * 2 + 1] << 8) | data[col * 2];
if (new_state[col])
reschedule = true;
bits_changed = keypad->last_key_state[col] ^ new_state[col];
while (bits_changed) {
row = ffs(bits_changed) - 1;
code = MATRIX_SCAN_CODE(row, col, keypad->row_shift);
input_event(keypad->dev, EV_MSC, MSC_SCAN, code);
input_report_key(keypad->dev, keycodes[code],
new_state[col] & BIT(row));
bits_changed &= ~BIT(row);
}
}
input_sync(keypad->dev);
memcpy(keypad->last_key_state, new_state, sizeof(new_state));
end:
if (reschedule)
ht16k33_keypad_queue(priv);
else
enable_irq(priv->client->irq);
}
static irqreturn_t ht16k33_irq_thread(int irq, void *dev)
{
struct ht16k33_priv *priv = dev;
disable_irq_nosync(priv->client->irq);
ht16k33_keypad_queue(priv);
return IRQ_HANDLED;
}
static int ht16k33_bl_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
struct ht16k33_priv *priv = bl_get_data(bl);
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.fb_blank != FB_BLANK_UNBLANK ||
bl->props.state & BL_CORE_FBBLANK || brightness == 0) {
return ht16k33_display_off(priv);
}
ht16k33_display_on(priv);
return i2c_smbus_write_byte(priv->client,
REG_BRIGHTNESS | (brightness - 1));
}
static int ht16k33_bl_check_fb(struct backlight_device *bl, struct fb_info *fi)
{
struct ht16k33_priv *priv = bl_get_data(bl);
return (fi == NULL) || (fi->par == priv);
}
static int ht16k33_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct ht16k33_priv *priv = info->par;
return vm_insert_page(vma, vma->vm_start,
virt_to_page(priv->fbdev.buffer));
}
static int ht16k33_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err;
uint32_t rows, cols, dft_brightness;
struct backlight_device *bl;
struct backlight_properties bl_props;
struct ht16k33_priv *priv;
struct ht16k33_keypad *keypad;
struct ht16k33_fbdev *fbdev;
struct device_node *node = client->dev.of_node;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "i2c_check_functionality error\n");
return -EIO;
}
if (client->irq <= 0) {
dev_err(&client->dev, "No IRQ specified\n");
return -EINVAL;
}
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->client = client;
i2c_set_clientdata(client, priv);
fbdev = &priv->fbdev;
keypad = &priv->keypad;
priv->workqueue = create_singlethread_workqueue(DRIVER_NAME "-wq");
if (priv->workqueue == NULL)
return -ENOMEM;
err = ht16k33_initialize(priv);
if (err)
goto err_destroy_wq;
BUILD_BUG_ON(PAGE_SIZE < HT16K33_FB_SIZE);
fbdev->buffer = (unsigned char *) get_zeroed_page(GFP_KERNEL);
if (!fbdev->buffer) {
err = -ENOMEM;
goto err_free_fbdev;
}
fbdev->cache = devm_kmalloc(&client->dev, HT16K33_FB_SIZE, GFP_KERNEL);
if (!fbdev->cache) {
err = -ENOMEM;
goto err_fbdev_buffer;
}
fbdev->info = framebuffer_alloc(0, &client->dev);
if (!fbdev->info) {
err = -ENOMEM;
goto err_fbdev_buffer;
}
err = of_property_read_u32(node, "refresh-rate-hz",
&fbdev->refresh_rate);
if (err) {
dev_err(&client->dev, "refresh rate not specified\n");
goto err_fbdev_info;
}
fb_bl_default_curve(fbdev->info, 0, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
INIT_DELAYED_WORK(&fbdev->work, ht16k33_fb_update);
fbdev->info->fbops = &ht16k33_fb_ops;
fbdev->info->screen_base = (char __iomem *) fbdev->buffer;
fbdev->info->screen_size = HT16K33_FB_SIZE;
fbdev->info->fix = ht16k33_fb_fix;
fbdev->info->var = ht16k33_fb_var;
fbdev->info->pseudo_palette = NULL;
fbdev->info->flags = FBINFO_FLAG_DEFAULT;
fbdev->info->par = priv;
err = register_framebuffer(fbdev->info);
if (err)
goto err_fbdev_info;
keypad->dev = devm_input_allocate_device(&client->dev);
if (!keypad->dev) {
err = -ENOMEM;
goto err_fbdev_unregister;
}
keypad->dev->name = DRIVER_NAME"-keypad";
keypad->dev->id.bustype = BUS_I2C;
keypad->dev->open = ht16k33_keypad_start;
keypad->dev->close = ht16k33_keypad_stop;
if (!of_get_property(node, "linux,no-autorepeat", NULL))
__set_bit(EV_REP, keypad->dev->evbit);
err = of_property_read_u32(node, "debounce-delay-ms",
&keypad->debounce_ms);
if (err) {
dev_err(&client->dev, "key debounce delay not specified\n");
goto err_fbdev_unregister;
}
err = devm_request_threaded_irq(&client->dev, client->irq, NULL,
ht16k33_irq_thread,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
DRIVER_NAME, priv);
if (err) {
dev_err(&client->dev, "irq request failed %d, error %d\n",
client->irq, err);
goto err_fbdev_unregister;
}
disable_irq_nosync(client->irq);
rows = HT16K33_MATRIX_KEYPAD_MAX_ROWS;
cols = HT16K33_MATRIX_KEYPAD_MAX_COLS;
err = matrix_keypad_parse_of_params(&client->dev, &rows, &cols);
if (err)
goto err_fbdev_unregister;
err = matrix_keypad_build_keymap(NULL, NULL, rows, cols, NULL,
keypad->dev);
if (err) {
dev_err(&client->dev, "failed to build keymap\n");
goto err_fbdev_unregister;
}
input_set_drvdata(keypad->dev, priv);
keypad->rows = rows;
keypad->cols = cols;
keypad->row_shift = get_count_order(cols);
INIT_DELAYED_WORK(&keypad->work, ht16k33_keypad_scan);
err = input_register_device(keypad->dev);
if (err)
goto err_fbdev_unregister;
memset(&bl_props, 0, sizeof(struct backlight_properties));
bl_props.type = BACKLIGHT_RAW;
bl_props.max_brightness = MAX_BRIGHTNESS;
bl = devm_backlight_device_register(&client->dev, DRIVER_NAME"-bl",
&client->dev, priv,
&ht16k33_bl_ops, &bl_props);
if (IS_ERR(bl)) {
dev_err(&client->dev, "failed to register backlight\n");
err = PTR_ERR(bl);
goto err_keypad_unregister;
}
err = of_property_read_u32(node, "default-brightness-level",
&dft_brightness);
if (err) {
dft_brightness = MAX_BRIGHTNESS;
} else if (dft_brightness > MAX_BRIGHTNESS) {
dev_warn(&client->dev,
"invalid default brightness level: %u, using %u\n",
dft_brightness, MAX_BRIGHTNESS);
dft_brightness = MAX_BRIGHTNESS;
}
bl->props.brightness = dft_brightness;
ht16k33_bl_update_status(bl);
ht16k33_fb_queue(priv);
return 0;
err_keypad_unregister:
input_unregister_device(keypad->dev);
err_fbdev_unregister:
unregister_framebuffer(fbdev->info);
err_fbdev_info:
framebuffer_release(fbdev->info);
err_fbdev_buffer:
free_page((unsigned long) fbdev->buffer);
err_free_fbdev:
kfree(fbdev);
err_destroy_wq:
destroy_workqueue(priv->workqueue);
return err;
}
static int ht16k33_remove(struct i2c_client *client)
{
struct ht16k33_priv *priv = i2c_get_clientdata(client);
struct ht16k33_keypad *keypad = &priv->keypad;
struct ht16k33_fbdev *fbdev = &priv->fbdev;
ht16k33_keypad_stop(keypad->dev);
cancel_delayed_work(&fbdev->work);
unregister_framebuffer(fbdev->info);
framebuffer_release(fbdev->info);
free_page((unsigned long) fbdev->buffer);
destroy_workqueue(priv->workqueue);
return 0;
}
