int speakup_add_virtual_keyboard(void)
{
int err;
virt_keyboard = input_allocate_device();
if (!virt_keyboard)
return -ENOMEM;
virt_keyboard->name = "Speakup";
virt_keyboard->id.bustype = BUS_VIRTUAL;
virt_keyboard->phys = "speakup/input0";
virt_keyboard->dev.parent = NULL;
__set_bit(EV_KEY, virt_keyboard->evbit);
__set_bit(KEY_DOWN, virt_keyboard->keybit);
err = input_register_device(virt_keyboard);
if (err) {
input_free_device(virt_keyboard);
virt_keyboard = NULL;
}
return err;
}
void speakup_remove_virtual_keyboard(void)
{
if (virt_keyboard != NULL) {
input_unregister_device(virt_keyboard);
virt_keyboard = NULL;
}
}
void speakup_fake_down_arrow(void)
{
unsigned long flags;
local_irq_save(flags);
preempt_disable();
__this_cpu_write(reporting_keystroke, true);
input_report_key(virt_keyboard, KEY_DOWN, PRESSED);
input_report_key(virt_keyboard, KEY_DOWN, RELEASED);
input_sync(virt_keyboard);
__this_cpu_write(reporting_keystroke, false);
preempt_enable();
local_irq_restore(flags);
}
bool speakup_fake_key_pressed(void)
{
return this_cpu_read(reporting_keystroke);
}
