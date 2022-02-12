static void micro_key_receive(void *data, int len, unsigned char *msg)
{
struct ipaq_micro_keys *keys = data;
int key, down;
down = 0x80 & msg[0];
key = 0x7f & msg[0];
if (key < ARRAY_SIZE(micro_keycodes)) {
input_report_key(keys->input, keys->codes[key], down);
input_sync(keys->input);
}
}
static void micro_key_start(struct ipaq_micro_keys *keys)
{
spin_lock(&keys->micro->lock);
keys->micro->key = micro_key_receive;
keys->micro->key_data = keys;
spin_unlock(&keys->micro->lock);
}
static void micro_key_stop(struct ipaq_micro_keys *keys)
{
spin_lock(&keys->micro->lock);
keys->micro->key = NULL;
keys->micro->key_data = NULL;
spin_unlock(&keys->micro->lock);
}
static int micro_key_open(struct input_dev *input)
{
struct ipaq_micro_keys *keys = input_get_drvdata(input);
micro_key_start(keys);
return 0;
}
static void micro_key_close(struct input_dev *input)
{
struct ipaq_micro_keys *keys = input_get_drvdata(input);
micro_key_stop(keys);
}
static int micro_key_probe(struct platform_device *pdev)
{
struct ipaq_micro_keys *keys;
int error;
int i;
keys = devm_kzalloc(&pdev->dev, sizeof(*keys), GFP_KERNEL);
if (!keys)
return -ENOMEM;
keys->micro = dev_get_drvdata(pdev->dev.parent);
keys->input = devm_input_allocate_device(&pdev->dev);
if (!keys->input)
return -ENOMEM;
keys->input->keycodesize = sizeof(micro_keycodes[0]);
keys->input->keycodemax = ARRAY_SIZE(micro_keycodes);
keys->codes = devm_kmemdup(&pdev->dev, micro_keycodes,
keys->input->keycodesize * keys->input->keycodemax,
GFP_KERNEL);
keys->input->keycode = keys->codes;
__set_bit(EV_KEY, keys->input->evbit);
for (i = 0; i < ARRAY_SIZE(micro_keycodes); i++)
__set_bit(micro_keycodes[i], keys->input->keybit);
keys->input->name = "h3600 micro keys";
keys->input->open = micro_key_open;
keys->input->close = micro_key_close;
input_set_drvdata(keys->input, keys);
error = input_register_device(keys->input);
if (error)
return error;
platform_set_drvdata(pdev, keys);
return 0;
}
static int __maybe_unused micro_key_suspend(struct device *dev)
{
struct ipaq_micro_keys *keys = dev_get_drvdata(dev);
micro_key_stop(keys);
return 0;
}
static int __maybe_unused micro_key_resume(struct device *dev)
{
struct ipaq_micro_keys *keys = dev_get_drvdata(dev);
struct input_dev *input = keys->input;
mutex_lock(&input->mutex);
if (input->users)
micro_key_start(keys);
mutex_unlock(&input->mutex);
return 0;
}
