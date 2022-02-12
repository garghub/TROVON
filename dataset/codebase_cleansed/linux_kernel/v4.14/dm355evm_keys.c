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
static int dm355evm_keys_probe(struct platform_device *pdev)
{
struct dm355evm_keys *keys;
struct input_dev *input;
int irq;
int error;
keys = devm_kzalloc(&pdev->dev, sizeof (*keys), GFP_KERNEL);
if (!keys)
return -ENOMEM;
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
keys->dev = &pdev->dev;
keys->input = input;
input->name = "DM355 EVM Controls";
input->phys = "dm355evm/input0";
input->id.bustype = BUS_I2C;
input->id.product = 0x0355;
input->id.version = dm355evm_msp_read(DM355EVM_MSP_FIRMREV);
error = sparse_keymap_setup(input, dm355evm_keys, NULL);
if (error)
return error;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
error = devm_request_threaded_irq(&pdev->dev, irq,
NULL, dm355evm_keys_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev_name(&pdev->dev), keys);
if (error)
return error;
error = input_register_device(input);
if (error)
return error;
return 0;
}
