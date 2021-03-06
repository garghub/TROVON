static int set_lid_wake_behavior(bool wake_on_close)
{
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = wake_on_close;
status = acpi_evaluate_object(NULL, "\\_SB.PCI0.LID.LIDW", &arg_list, NULL);
if (ACPI_FAILURE(status)) {
pr_warning(PFX "failed to set lid behavior\n");
return 1;
}
lid_wake_on_close = wake_on_close;
return 0;
}
static ssize_t
lid_wake_on_close_show(struct kobject *s, struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", lid_wake_on_close);
}
static ssize_t lid_wake_on_close_store(struct kobject *s,
struct kobj_attribute *attr,
const char *buf, size_t n)
{
unsigned int val;
if (sscanf(buf, "%u", &val) != 1)
return -EINVAL;
set_lid_wake_behavior(!!val);
return n;
}
static void battery_status_changed(void)
{
struct power_supply *psy = power_supply_get_by_name("olpc-battery");
if (psy) {
power_supply_changed(psy);
put_device(psy->dev);
}
}
static void ac_status_changed(void)
{
struct power_supply *psy = power_supply_get_by_name("olpc-ac");
if (psy) {
power_supply_changed(psy);
put_device(psy->dev);
}
}
static void process_sci_queue(void)
{
u16 data;
int r;
do {
r = olpc_ec_sci_query(&data);
if (r || !data)
break;
pr_debug(PFX "SCI 0x%x received\n", data);
switch (data) {
case EC_SCI_SRC_BATERR:
case EC_SCI_SRC_BATSOC:
case EC_SCI_SRC_BATTERY:
case EC_SCI_SRC_BATCRIT:
battery_status_changed();
break;
case EC_SCI_SRC_ACPWR:
ac_status_changed();
break;
}
} while (data);
if (r)
pr_err(PFX "Failed to clear SCI queue");
}
static void process_sci_queue_work(struct work_struct *work)
{
process_sci_queue();
}
static u32 xo15_sci_gpe_handler(acpi_handle gpe_device, u32 gpe, void *context)
{
schedule_work(&sci_work);
return ACPI_INTERRUPT_HANDLED | ACPI_REENABLE_GPE;
}
static int xo15_sci_add(struct acpi_device *device)
{
unsigned long long tmp;
acpi_status status;
int r;
if (!device)
return -EINVAL;
strcpy(acpi_device_name(device), XO15_SCI_DEVICE_NAME);
strcpy(acpi_device_class(device), XO15_SCI_CLASS);
status = acpi_evaluate_integer(device->handle, "_GPE", NULL, &tmp);
if (ACPI_FAILURE(status))
return -EINVAL;
xo15_sci_gpe = tmp;
status = acpi_install_gpe_handler(NULL, xo15_sci_gpe,
ACPI_GPE_EDGE_TRIGGERED,
xo15_sci_gpe_handler, device);
if (ACPI_FAILURE(status))
return -ENODEV;
dev_info(&device->dev, "Initialized, GPE = 0x%lx\n", xo15_sci_gpe);
r = sysfs_create_file(&device->dev.kobj, &lid_wake_on_close_attr.attr);
if (r)
goto err_sysfs;
process_sci_queue();
olpc_ec_mask_write(EC_SCI_SRC_ALL);
acpi_enable_gpe(NULL, xo15_sci_gpe);
if (device->wakeup.flags.valid)
device_init_wakeup(&device->dev, true);
return 0;
err_sysfs:
acpi_remove_gpe_handler(NULL, xo15_sci_gpe, xo15_sci_gpe_handler);
cancel_work_sync(&sci_work);
return r;
}
static int xo15_sci_remove(struct acpi_device *device, int type)
{
acpi_disable_gpe(NULL, xo15_sci_gpe);
acpi_remove_gpe_handler(NULL, xo15_sci_gpe, xo15_sci_gpe_handler);
cancel_work_sync(&sci_work);
sysfs_remove_file(&device->dev.kobj, &lid_wake_on_close_attr.attr);
return 0;
}
static int xo15_sci_resume(struct device *dev)
{
olpc_ec_mask_write(EC_SCI_SRC_ALL);
battery_status_changed();
ac_status_changed();
return 0;
}
static int __init xo15_sci_init(void)
{
return acpi_bus_register_driver(&xo15_sci_drv);
}
