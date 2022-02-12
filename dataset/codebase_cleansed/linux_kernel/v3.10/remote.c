static void print_input(struct remote_input *input)
{
if (input->type == INPUT_TYPE_MOUSE) {
unsigned char buttons = input->mouse_buttons;
dbg("remote mouse movement: (x,y)=(%d,%d)%s%s%s%s\n",
input->data.mouse.x, input->data.mouse.y,
(buttons) ? " -- buttons:" : "",
(buttons & REMOTE_BUTTON_LEFT) ? "left " : "",
(buttons & REMOTE_BUTTON_MIDDLE) ? "middle " : "",
(buttons & REMOTE_BUTTON_RIGHT) ? "right" : ""
);
} else {
dbg("remote keypress (code, flag, down):"
"%d (0x%x) [0x%x] [0x%x]\n",
input->data.keyboard.key_code,
input->data.keyboard.key_code,
input->data.keyboard.key_flag,
input->data.keyboard.key_down
);
}
}
static void send_mouse_event(struct input_dev *dev, struct remote_input *input)
{
unsigned char buttons = input->mouse_buttons;
input_report_abs(dev, ABS_X, input->data.mouse.x);
input_report_abs(dev, ABS_Y, input->data.mouse.y);
input_report_key(dev, BTN_LEFT, buttons & REMOTE_BUTTON_LEFT);
input_report_key(dev, BTN_MIDDLE, buttons & REMOTE_BUTTON_MIDDLE);
input_report_key(dev, BTN_RIGHT, buttons & REMOTE_BUTTON_RIGHT);
input_sync(dev);
}
static void send_keyboard_event(struct input_dev *dev,
struct remote_input *input)
{
unsigned int key;
unsigned short code = input->data.keyboard.key_code;
if (code & 0xff00)
key = xlate_high[code & 0xff];
else
key = xlate[code];
input_report_key(dev, key, input->data.keyboard.key_down);
input_sync(dev);
}
void ibmasm_handle_mouse_interrupt(struct service_processor *sp)
{
unsigned long reader;
unsigned long writer;
struct remote_input input;
reader = get_queue_reader(sp);
writer = get_queue_writer(sp);
while (reader != writer) {
memcpy_fromio(&input, get_queue_entry(sp, reader),
sizeof(struct remote_input));
print_input(&input);
if (input.type == INPUT_TYPE_MOUSE) {
send_mouse_event(sp->remote.mouse_dev, &input);
} else if (input.type == INPUT_TYPE_KEYBOARD) {
send_keyboard_event(sp->remote.keybd_dev, &input);
} else
break;
reader = advance_queue_reader(sp, reader);
writer = get_queue_writer(sp);
}
}
int ibmasm_init_remote_input_dev(struct service_processor *sp)
{
struct input_dev *mouse_dev, *keybd_dev;
struct pci_dev *pdev = to_pci_dev(sp->dev);
int error = -ENOMEM;
int i;
sp->remote.mouse_dev = mouse_dev = input_allocate_device();
sp->remote.keybd_dev = keybd_dev = input_allocate_device();
if (!mouse_dev || !keybd_dev)
goto err_free_devices;
mouse_dev->id.bustype = BUS_PCI;
mouse_dev->id.vendor = pdev->vendor;
mouse_dev->id.product = pdev->device;
mouse_dev->id.version = 1;
mouse_dev->dev.parent = sp->dev;
mouse_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
mouse_dev->keybit[BIT_WORD(BTN_MOUSE)] = BIT_MASK(BTN_LEFT) |
BIT_MASK(BTN_RIGHT) | BIT_MASK(BTN_MIDDLE);
set_bit(BTN_TOUCH, mouse_dev->keybit);
mouse_dev->name = "ibmasm RSA I remote mouse";
input_set_abs_params(mouse_dev, ABS_X, 0, MOUSE_X_MAX, 0, 0);
input_set_abs_params(mouse_dev, ABS_Y, 0, MOUSE_Y_MAX, 0, 0);
keybd_dev->id.bustype = BUS_PCI;
keybd_dev->id.vendor = pdev->vendor;
keybd_dev->id.product = pdev->device;
keybd_dev->id.version = 2;
keybd_dev->dev.parent = sp->dev;
keybd_dev->evbit[0] = BIT_MASK(EV_KEY);
keybd_dev->name = "ibmasm RSA I remote keyboard";
for (i = 0; i < XLATE_SIZE; i++) {
if (xlate_high[i])
set_bit(xlate_high[i], keybd_dev->keybit);
if (xlate[i])
set_bit(xlate[i], keybd_dev->keybit);
}
error = input_register_device(mouse_dev);
if (error)
goto err_free_devices;
error = input_register_device(keybd_dev);
if (error)
goto err_unregister_mouse_dev;
enable_mouse_interrupts(sp);
printk(KERN_INFO "ibmasm remote responding to events on RSA card %d\n", sp->number);
return 0;
err_unregister_mouse_dev:
input_unregister_device(mouse_dev);
mouse_dev = NULL;
err_free_devices:
input_free_device(mouse_dev);
input_free_device(keybd_dev);
return error;
}
void ibmasm_free_remote_input_dev(struct service_processor *sp)
{
disable_mouse_interrupts(sp);
input_unregister_device(sp->remote.mouse_dev);
input_unregister_device(sp->remote.keybd_dev);
}
