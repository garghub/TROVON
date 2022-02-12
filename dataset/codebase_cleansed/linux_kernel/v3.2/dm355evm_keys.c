static irqreturn_t dm355evm_keys_irq(int irq, void *_keys)
{
static u16 last_event;
struct dm355evm_keys *keys = _keys;
const struct key_entry *ke;
unsigned int keycode;
int status;
u16 event;
for (;;) {
status = dm355evm_msp_read(DM355EVM_MSP_INPUT_HIGH);
if (status < 0) {
dev_dbg(keys->dev, "input high err %d\n",
status);
break;
}
event = status << 8;
status = dm355evm_msp_read(DM355EVM_MSP_INPUT_LOW);
if (status < 0) {
dev_dbg(keys->dev, "input low err %d\n",
status);
break;
}
event |= status;
if (event == 0xdead)
break;
if (event == last_event) {
last_event = 0;
continue;
}
last_event = event;
event &= ~0x0800;
ke = sparse_keymap_entry_from_scancode(keys->input, event);
keycode = ke ? ke->keycode : KEY_UNKNOWN;
dev_dbg(keys->dev,
"input event 0x%04x--> keycode %d\n",
event, keycode);
input_report_key(keys->input, keycode, 1);
input_sync(keys->input);
input_report_key(keys->input, keycode, 0);
input_sync(keys->input);
}
return IRQ_HANDLED;
}
static int __devinit dm355evm_keys_probe(struct platform_device *pdev)
{
struct dm355evm_keys *keys;
struct input_dev *input;
int status;
keys = kzalloc(sizeof *keys, GFP_KERNEL);
input = input_allocate_device();
if (!keys || !input) {
status = -ENOMEM;
goto fail1;
}
keys->dev = &pdev->dev;
keys->input = input;
status = platform_get_irq(pdev, 0);
if (status < 0)
goto fail1;
keys->irq = status;
input_set_drvdata(input, keys);
input->name = "DM355 EVM Controls";
input->phys = "dm355evm/input0";
input->dev.parent = &pdev->dev;
input->id.bustype = BUS_I2C;
input->id.product = 0x0355;
input->id.version = dm355evm_msp_read(DM355EVM_MSP_FIRMREV);
status = sparse_keymap_setup(input, dm355evm_keys, NULL);
if (status)
goto fail1;
status = request_threaded_irq(keys->irq, NULL, dm355evm_keys_irq,
IRQF_TRIGGER_FALLING, dev_name(&pdev->dev), keys);
if (status < 0)
goto fail2;
status = input_register_device(input);
if (status < 0)
goto fail3;
platform_set_drvdata(pdev, keys);
return 0;
fail3:
free_irq(keys->irq, keys);
fail2:
sparse_keymap_free(input);
fail1:
input_free_device(input);
kfree(keys);
dev_err(&pdev->dev, "can't register, err %d\n", status);
return status;
}
static int __devexit dm355evm_keys_remove(struct platform_device *pdev)
{
struct dm355evm_keys *keys = platform_get_drvdata(pdev);
free_irq(keys->irq, keys);
sparse_keymap_free(keys->input);
input_unregister_device(keys->input);
kfree(keys);
return 0;
}
static int __init dm355evm_keys_init(void)
{
return platform_driver_register(&dm355evm_keys_driver);
}
static void __exit dm355evm_keys_exit(void)
{
platform_driver_unregister(&dm355evm_keys_driver);
}
