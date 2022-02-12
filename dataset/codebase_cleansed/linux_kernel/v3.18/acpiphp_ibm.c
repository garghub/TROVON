static union apci_descriptor *ibm_slot_from_id(int id)
{
int ind = 0, size;
union apci_descriptor *ret = NULL, *des;
char *table;
size = ibm_get_table_from_acpi(&table);
des = (union apci_descriptor *)table;
if (memcmp(des->header.sig, "aPCI", 4) != 0)
goto ibm_slot_done;
des = (union apci_descriptor *)&table[ind += des->header.len];
while (ind < size && (des->generic.type != 0x82 ||
des->slot.slot_num != id)) {
des = (union apci_descriptor *)&table[ind += des->generic.len];
}
if (ind < size && des->slot.slot_num == id)
ret = des;
ibm_slot_done:
if (ret) {
ret = kmalloc(sizeof(union apci_descriptor), GFP_KERNEL);
memcpy(ret, des, sizeof(union apci_descriptor));
}
kfree(table);
return ret;
}
static int ibm_set_attention_status(struct hotplug_slot *slot, u8 status)
{
union acpi_object args[2];
struct acpi_object_list params = { .pointer = args, .count = 2 };
acpi_status stat;
unsigned long long rc;
union apci_descriptor *ibm_slot;
ibm_slot = ibm_slot_from_id(hpslot_to_sun(slot));
pr_debug("%s: set slot %d (%d) attention status to %d\n", __func__,
ibm_slot->slot.slot_num, ibm_slot->slot.slot_id,
(status ? 1 : 0));
args[0].type = ACPI_TYPE_INTEGER;
args[0].integer.value = ibm_slot->slot.slot_id;
args[1].type = ACPI_TYPE_INTEGER;
args[1].integer.value = (status) ? 1 : 0;
kfree(ibm_slot);
stat = acpi_evaluate_integer(ibm_acpi_handle, "APLS", &params, &rc);
if (ACPI_FAILURE(stat)) {
pr_err("APLS evaluation failed: 0x%08x\n", stat);
return -ENODEV;
} else if (!rc) {
pr_err("APLS method failed: 0x%08llx\n", rc);
return -ERANGE;
}
return 0;
}
static int ibm_get_attention_status(struct hotplug_slot *slot, u8 *status)
{
union apci_descriptor *ibm_slot;
ibm_slot = ibm_slot_from_id(hpslot_to_sun(slot));
if (ibm_slot->slot.attn & 0xa0 || ibm_slot->slot.status[1] & 0x08)
*status = 1;
else
*status = 0;
pr_debug("%s: get slot %d (%d) attention status is %d\n", __func__,
ibm_slot->slot.slot_num, ibm_slot->slot.slot_id,
*status);
kfree(ibm_slot);
return 0;
}
static void ibm_handle_events(acpi_handle handle, u32 event, void *context)
{
u8 detail = event & 0x0f;
u8 subevent = event & 0xf0;
struct notification *note = context;
pr_debug("%s: Received notification %02x\n", __func__, event);
if (subevent == 0x80) {
pr_debug("%s: generating bus event\n", __func__);
acpi_bus_generate_netlink_event(note->device->pnp.device_class,
dev_name(&note->device->dev),
note->event, detail);
} else
note->event = event;
}
static int ibm_get_table_from_acpi(char **bufp)
{
union acpi_object *package;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_status status;
char *lbuf = NULL;
int i, size = -EIO;
status = acpi_evaluate_object(ibm_acpi_handle, "APCI", NULL, &buffer);
if (ACPI_FAILURE(status)) {
pr_err("%s: APCI evaluation failed\n", __func__);
return -ENODEV;
}
package = (union acpi_object *) buffer.pointer;
if (!(package) ||
(package->type != ACPI_TYPE_PACKAGE) ||
!(package->package.elements)) {
pr_err("%s: Invalid APCI object\n", __func__);
goto read_table_done;
}
for (size = 0, i = 0; i < package->package.count; i++) {
if (package->package.elements[i].type != ACPI_TYPE_BUFFER) {
pr_err("%s: Invalid APCI element %d\n", __func__, i);
goto read_table_done;
}
size += package->package.elements[i].buffer.length;
}
if (bufp == NULL)
goto read_table_done;
lbuf = kzalloc(size, GFP_KERNEL);
pr_debug("%s: element count: %i, ASL table size: %i, &table = 0x%p\n",
__func__, package->package.count, size, lbuf);
if (lbuf) {
*bufp = lbuf;
} else {
size = -ENOMEM;
goto read_table_done;
}
size = 0;
for (i=0; i<package->package.count; i++) {
memcpy(&lbuf[size],
package->package.elements[i].buffer.pointer,
package->package.elements[i].buffer.length);
size += package->package.elements[i].buffer.length;
}
read_table_done:
kfree(buffer.pointer);
return size;
}
static ssize_t ibm_read_apci_table(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t size)
{
int bytes_read = -EINVAL;
char *table = NULL;
pr_debug("%s: pos = %d, size = %zd\n", __func__, (int)pos, size);
if (pos == 0) {
bytes_read = ibm_get_table_from_acpi(&table);
if (bytes_read > 0 && bytes_read <= size)
memcpy(buffer, table, bytes_read);
kfree(table);
}
return bytes_read;
}
static acpi_status __init ibm_find_acpi_device(acpi_handle handle,
u32 lvl, void *context, void **rv)
{
acpi_handle *phandle = (acpi_handle *)context;
acpi_status status;
struct acpi_device_info *info;
int retval = 0;
status = acpi_get_object_info(handle, &info);
if (ACPI_FAILURE(status)) {
pr_err("%s: Failed to get device information status=0x%x\n",
__func__, status);
return retval;
}
if (info->current_status && (info->valid & ACPI_VALID_HID) &&
(!strcmp(info->hardware_id.string, IBM_HARDWARE_ID1) ||
!strcmp(info->hardware_id.string, IBM_HARDWARE_ID2))) {
pr_debug("found hardware: %s, handle: %p\n",
info->hardware_id.string, handle);
*phandle = handle;
retval = FOUND_APCI;
}
kfree(info);
return retval;
}
static int __init ibm_acpiphp_init(void)
{
int retval = 0;
acpi_status status;
struct acpi_device *device;
struct kobject *sysdir = &pci_slots_kset->kobj;
pr_debug("%s\n", __func__);
if (acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, ibm_find_acpi_device, NULL,
&ibm_acpi_handle, NULL) != FOUND_APCI) {
pr_err("%s: acpi_walk_namespace failed\n", __func__);
retval = -ENODEV;
goto init_return;
}
pr_debug("%s: found IBM aPCI device\n", __func__);
if (acpi_bus_get_device(ibm_acpi_handle, &device)) {
pr_err("%s: acpi_bus_get_device failed\n", __func__);
retval = -ENODEV;
goto init_return;
}
if (acpiphp_register_attention(&ibm_attention_info)) {
retval = -ENODEV;
goto init_return;
}
ibm_note.device = device;
status = acpi_install_notify_handler(ibm_acpi_handle,
ACPI_DEVICE_NOTIFY, ibm_handle_events,
&ibm_note);
if (ACPI_FAILURE(status)) {
pr_err("%s: Failed to register notification handler\n",
__func__);
retval = -EBUSY;
goto init_cleanup;
}
ibm_apci_table_attr.size = ibm_get_table_from_acpi(NULL);
retval = sysfs_create_bin_file(sysdir, &ibm_apci_table_attr);
return retval;
init_cleanup:
acpiphp_unregister_attention(&ibm_attention_info);
init_return:
return retval;
}
static void __exit ibm_acpiphp_exit(void)
{
acpi_status status;
struct kobject *sysdir = &pci_slots_kset->kobj;
pr_debug("%s\n", __func__);
if (acpiphp_unregister_attention(&ibm_attention_info))
pr_err("%s: attention info deregistration failed", __func__);
status = acpi_remove_notify_handler(
ibm_acpi_handle,
ACPI_DEVICE_NOTIFY,
ibm_handle_events);
if (ACPI_FAILURE(status))
pr_err("%s: Notification handler removal failed\n", __func__);
sysfs_remove_bin_file(sysdir, &ibm_apci_table_attr);
}
