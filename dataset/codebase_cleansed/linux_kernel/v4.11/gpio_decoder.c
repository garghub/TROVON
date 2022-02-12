static int gpio_decoder_get_gpios_state(struct gpio_decoder *decoder)
{
struct gpio_descs *gpios = decoder->input_gpios;
unsigned int ret = 0;
int i, val;
for (i = 0; i < gpios->ndescs; i++) {
val = gpiod_get_value_cansleep(gpios->desc[i]);
if (val < 0) {
dev_err(decoder->dev,
"Error reading gpio %d: %d\n",
desc_to_gpio(gpios->desc[i]), val);
return val;
}
val = !!val;
ret = (ret << 1) | val;
}
return ret;
}
static void gpio_decoder_poll_gpios(struct input_polled_dev *poll_dev)
{
struct gpio_decoder *decoder = poll_dev->private;
int state;
state = gpio_decoder_get_gpios_state(decoder);
if (state >= 0 && state != decoder->last_stable) {
input_report_abs(poll_dev->input, decoder->axis, state);
input_sync(poll_dev->input);
decoder->last_stable = state;
}
}
static int gpio_decoder_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct gpio_decoder *decoder;
struct input_polled_dev *poll_dev;
u32 max;
int err;
decoder = devm_kzalloc(dev, sizeof(struct gpio_decoder), GFP_KERNEL);
if (!decoder)
return -ENOMEM;
device_property_read_u32(dev, "linux,axis", &decoder->axis);
decoder->input_gpios = devm_gpiod_get_array(dev, NULL, GPIOD_IN);
if (IS_ERR(decoder->input_gpios)) {
dev_err(dev, "unable to acquire input gpios\n");
return PTR_ERR(decoder->input_gpios);
}
if (decoder->input_gpios->ndescs < 2) {
dev_err(dev, "not enough gpios found\n");
return -EINVAL;
}
if (device_property_read_u32(dev, "decoder-max-value", &max))
max = (1U << decoder->input_gpios->ndescs) - 1;
decoder->dev = dev;
poll_dev = devm_input_allocate_polled_device(decoder->dev);
if (!poll_dev)
return -ENOMEM;
poll_dev->private = decoder;
poll_dev->poll = gpio_decoder_poll_gpios;
decoder->poll_dev = poll_dev;
poll_dev->input->name = pdev->name;
poll_dev->input->id.bustype = BUS_HOST;
input_set_abs_params(poll_dev->input, decoder->axis, 0, max, 0, 0);
err = input_register_polled_device(poll_dev);
if (err) {
dev_err(dev, "failed to register polled device\n");
return err;
}
return 0;
}
