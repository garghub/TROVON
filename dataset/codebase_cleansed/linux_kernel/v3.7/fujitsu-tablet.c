static u8 fujitsu_ack(void)
{
return inb(fujitsu.io_base + 2);
}
static u8 fujitsu_status(void)
{
return inb(fujitsu.io_base + 6);
}
static u8 fujitsu_read_register(const u8 addr)
{
outb(addr, fujitsu.io_base);
return inb(fujitsu.io_base + 4);
}
static void fujitsu_send_state(void)
{
int state;
int dock, tablet_mode;
state = fujitsu_read_register(0xdd);
dock = state & 0x02;
if (fujitsu.config.quirks & INVERT_DOCK_STATE_BIT)
dock = !dock;
if ((fujitsu.config.quirks & FORCE_TABLET_MODE_IF_UNDOCK) && (!dock)) {
tablet_mode = 1;
} else{
tablet_mode = state & 0x01;
if (fujitsu.config.quirks & INVERT_TABLET_MODE_BIT)
tablet_mode = !tablet_mode;
}
input_report_switch(fujitsu.idev, SW_DOCK, dock);
input_report_switch(fujitsu.idev, SW_TABLET_MODE, tablet_mode);
input_sync(fujitsu.idev);
}
static void fujitsu_reset(void)
{
int timeout = 50;
fujitsu_ack();
while ((fujitsu_status() & 0x02) && (--timeout))
msleep(20);
fujitsu_send_state();
}
static int __devinit input_fujitsu_setup(struct device *parent,
const char *name, const char *phys)
{
struct input_dev *idev;
int error;
int i;
idev = input_allocate_device();
if (!idev)
return -ENOMEM;
idev->dev.parent = parent;
idev->phys = phys;
idev->name = name;
idev->id.bustype = BUS_HOST;
idev->id.vendor = 0x1734;
idev->id.product = 0x0001;
idev->id.version = 0x0101;
idev->keycode = fujitsu.config.keymap;
idev->keycodesize = sizeof(fujitsu.config.keymap[0]);
idev->keycodemax = ARRAY_SIZE(fujitsu.config.keymap);
__set_bit(EV_REP, idev->evbit);
for (i = 0; i < ARRAY_SIZE(fujitsu.config.keymap); i++)
if (fujitsu.config.keymap[i])
input_set_capability(idev, EV_KEY, fujitsu.config.keymap[i]);
input_set_capability(idev, EV_MSC, MSC_SCAN);
input_set_capability(idev, EV_SW, SW_DOCK);
input_set_capability(idev, EV_SW, SW_TABLET_MODE);
error = input_register_device(idev);
if (error) {
input_free_device(idev);
return error;
}
fujitsu.idev = idev;
return 0;
}
static void input_fujitsu_remove(void)
{
input_unregister_device(fujitsu.idev);
}
static irqreturn_t fujitsu_interrupt(int irq, void *dev_id)
{
unsigned long keymask, changed;
unsigned int keycode;
int pressed;
int i;
if (unlikely(!(fujitsu_status() & 0x01)))
return IRQ_NONE;
fujitsu_send_state();
keymask = fujitsu_read_register(0xde);
keymask |= fujitsu_read_register(0xdf) << 8;
keymask ^= 0xffff;
changed = keymask ^ fujitsu.prev_keymask;
if (changed) {
fujitsu.prev_keymask = keymask;
for_each_set_bit(i, &changed, KEYMAP_LEN) {
keycode = fujitsu.config.keymap[i];
pressed = keymask & changed & BIT(i);
if (pressed)
input_event(fujitsu.idev, EV_MSC, MSC_SCAN, i);
input_report_key(fujitsu.idev, keycode, pressed);
input_sync(fujitsu.idev);
}
}
fujitsu_ack();
return IRQ_HANDLED;
}
static void __devinit fujitsu_dmi_common(const struct dmi_system_id *dmi)
{
pr_info("%s\n", dmi->ident);
memcpy(fujitsu.config.keymap, dmi->driver_data,
sizeof(fujitsu.config.keymap));
}
static int __devinit fujitsu_dmi_lifebook(const struct dmi_system_id *dmi)
{
fujitsu_dmi_common(dmi);
fujitsu.config.quirks |= INVERT_TABLET_MODE_BIT;
return 1;
}
static int __devinit fujitsu_dmi_stylistic(const struct dmi_system_id *dmi)
{
fujitsu_dmi_common(dmi);
fujitsu.config.quirks |= FORCE_TABLET_MODE_IF_UNDOCK;
fujitsu.config.quirks |= INVERT_DOCK_STATE_BIT;
return 1;
}
static acpi_status __devinit
fujitsu_walk_resources(struct acpi_resource *res, void *data)
{
switch (res->type) {
case ACPI_RESOURCE_TYPE_IRQ:
fujitsu.irq = res->data.irq.interrupts[0];
return AE_OK;
case ACPI_RESOURCE_TYPE_IO:
fujitsu.io_base = res->data.io.minimum;
fujitsu.io_length = res->data.io.address_length;
return AE_OK;
case ACPI_RESOURCE_TYPE_END_TAG:
if (fujitsu.irq && fujitsu.io_base)
return AE_OK;
else
return AE_NOT_FOUND;
default:
return AE_ERROR;
}
}
static int __devinit acpi_fujitsu_add(struct acpi_device *adev)
{
acpi_status status;
int error;
if (!adev)
return -EINVAL;
status = acpi_walk_resources(adev->handle, METHOD_NAME__CRS,
fujitsu_walk_resources, NULL);
if (ACPI_FAILURE(status) || !fujitsu.irq || !fujitsu.io_base)
return -ENODEV;
sprintf(acpi_device_name(adev), "Fujitsu %s", acpi_device_hid(adev));
sprintf(acpi_device_class(adev), "%s", ACPI_FUJITSU_CLASS);
snprintf(fujitsu.phys, sizeof(fujitsu.phys),
"%s/input0", acpi_device_hid(adev));
error = input_fujitsu_setup(&adev->dev,
acpi_device_name(adev), fujitsu.phys);
if (error)
return error;
if (!request_region(fujitsu.io_base, fujitsu.io_length, MODULENAME)) {
input_fujitsu_remove();
return -EBUSY;
}
fujitsu_reset();
error = request_irq(fujitsu.irq, fujitsu_interrupt,
IRQF_SHARED, MODULENAME, fujitsu_interrupt);
if (error) {
release_region(fujitsu.io_base, fujitsu.io_length);
input_fujitsu_remove();
return error;
}
return 0;
}
static int __devexit acpi_fujitsu_remove(struct acpi_device *adev, int type)
{
free_irq(fujitsu.irq, fujitsu_interrupt);
release_region(fujitsu.io_base, fujitsu.io_length);
input_fujitsu_remove();
return 0;
}
static int acpi_fujitsu_resume(struct device *dev)
{
fujitsu_reset();
return 0;
}
static int __init fujitsu_module_init(void)
{
int error;
dmi_check_system(dmi_ids);
error = acpi_bus_register_driver(&acpi_fujitsu_driver);
if (error)
return error;
return 0;
}
static void __exit fujitsu_module_exit(void)
{
acpi_bus_unregister_driver(&acpi_fujitsu_driver);
}
