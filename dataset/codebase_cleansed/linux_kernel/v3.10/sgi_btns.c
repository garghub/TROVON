static inline u8 button_status(void)
{
u8 status;
status = readb(&sgioc->panel) ^ 0xa0;
return ((status & 0x80) >> 6) | ((status & 0x20) >> 5);
}
static inline u8 button_status(void)
{
u64 status;
status = readq(&mace->perif.audio.control);
writeq(status & ~(3U << 23), &mace->perif.audio.control);
return (status >> 23) & 3;
}
static void handle_buttons(struct input_polled_dev *dev)
{
struct buttons_dev *bdev = dev->private;
struct input_dev *input = dev->input;
u8 status;
int i;
status = button_status();
for (i = 0; i < ARRAY_SIZE(bdev->keymap); i++) {
if (status & (1U << i)) {
if (++bdev->count[i] == BUTTONS_COUNT_THRESHOLD) {
input_event(input, EV_MSC, MSC_SCAN, i);
input_report_key(input, bdev->keymap[i], 1);
input_sync(input);
}
} else {
if (bdev->count[i] >= BUTTONS_COUNT_THRESHOLD) {
input_event(input, EV_MSC, MSC_SCAN, i);
input_report_key(input, bdev->keymap[i], 0);
input_sync(input);
}
bdev->count[i] = 0;
}
}
}
static int sgi_buttons_probe(struct platform_device *pdev)
{
struct buttons_dev *bdev;
struct input_polled_dev *poll_dev;
struct input_dev *input;
int error, i;
bdev = kzalloc(sizeof(struct buttons_dev), GFP_KERNEL);
poll_dev = input_allocate_polled_device();
if (!bdev || !poll_dev) {
error = -ENOMEM;
goto err_free_mem;
}
memcpy(bdev->keymap, sgi_map, sizeof(bdev->keymap));
poll_dev->private = bdev;
poll_dev->poll = handle_buttons;
poll_dev->poll_interval = BUTTONS_POLL_INTERVAL;
input = poll_dev->input;
input->name = "SGI buttons";
input->phys = "sgi/input0";
input->id.bustype = BUS_HOST;
input->dev.parent = &pdev->dev;
input->keycode = bdev->keymap;
input->keycodemax = ARRAY_SIZE(bdev->keymap);
input->keycodesize = sizeof(unsigned short);
input_set_capability(input, EV_MSC, MSC_SCAN);
__set_bit(EV_KEY, input->evbit);
for (i = 0; i < ARRAY_SIZE(sgi_map); i++)
__set_bit(bdev->keymap[i], input->keybit);
__clear_bit(KEY_RESERVED, input->keybit);
bdev->poll_dev = poll_dev;
dev_set_drvdata(&pdev->dev, bdev);
error = input_register_polled_device(poll_dev);
if (error)
goto err_free_mem;
return 0;
err_free_mem:
input_free_polled_device(poll_dev);
kfree(bdev);
dev_set_drvdata(&pdev->dev, NULL);
return error;
}
static int sgi_buttons_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct buttons_dev *bdev = dev_get_drvdata(dev);
input_unregister_polled_device(bdev->poll_dev);
input_free_polled_device(bdev->poll_dev);
kfree(bdev);
dev_set_drvdata(dev, NULL);
return 0;
}
