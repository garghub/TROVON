static acpi_status
decode_type0_hpx_record(union acpi_object *record, struct hotplug_params *hpx)
{
int i;
union acpi_object *fields = record->package.elements;
u32 revision = fields[1].integer.value;
switch (revision) {
case 1:
if (record->package.count != 6)
return AE_ERROR;
for (i = 2; i < 6; i++)
if (fields[i].type != ACPI_TYPE_INTEGER)
return AE_ERROR;
hpx->t0 = &hpx->type0_data;
hpx->t0->revision = revision;
hpx->t0->cache_line_size = fields[2].integer.value;
hpx->t0->latency_timer = fields[3].integer.value;
hpx->t0->enable_serr = fields[4].integer.value;
hpx->t0->enable_perr = fields[5].integer.value;
break;
default:
printk(KERN_WARNING
"%s: Type 0 Revision %d record not supported\n",
__func__, revision);
return AE_ERROR;
}
return AE_OK;
}
static acpi_status
decode_type1_hpx_record(union acpi_object *record, struct hotplug_params *hpx)
{
int i;
union acpi_object *fields = record->package.elements;
u32 revision = fields[1].integer.value;
switch (revision) {
case 1:
if (record->package.count != 5)
return AE_ERROR;
for (i = 2; i < 5; i++)
if (fields[i].type != ACPI_TYPE_INTEGER)
return AE_ERROR;
hpx->t1 = &hpx->type1_data;
hpx->t1->revision = revision;
hpx->t1->max_mem_read = fields[2].integer.value;
hpx->t1->avg_max_split = fields[3].integer.value;
hpx->t1->tot_max_split = fields[4].integer.value;
break;
default:
printk(KERN_WARNING
"%s: Type 1 Revision %d record not supported\n",
__func__, revision);
return AE_ERROR;
}
return AE_OK;
}
static acpi_status
decode_type2_hpx_record(union acpi_object *record, struct hotplug_params *hpx)
{
int i;
union acpi_object *fields = record->package.elements;
u32 revision = fields[1].integer.value;
switch (revision) {
case 1:
if (record->package.count != 18)
return AE_ERROR;
for (i = 2; i < 18; i++)
if (fields[i].type != ACPI_TYPE_INTEGER)
return AE_ERROR;
hpx->t2 = &hpx->type2_data;
hpx->t2->revision = revision;
hpx->t2->unc_err_mask_and = fields[2].integer.value;
hpx->t2->unc_err_mask_or = fields[3].integer.value;
hpx->t2->unc_err_sever_and = fields[4].integer.value;
hpx->t2->unc_err_sever_or = fields[5].integer.value;
hpx->t2->cor_err_mask_and = fields[6].integer.value;
hpx->t2->cor_err_mask_or = fields[7].integer.value;
hpx->t2->adv_err_cap_and = fields[8].integer.value;
hpx->t2->adv_err_cap_or = fields[9].integer.value;
hpx->t2->pci_exp_devctl_and = fields[10].integer.value;
hpx->t2->pci_exp_devctl_or = fields[11].integer.value;
hpx->t2->pci_exp_lnkctl_and = fields[12].integer.value;
hpx->t2->pci_exp_lnkctl_or = fields[13].integer.value;
hpx->t2->sec_unc_err_sever_and = fields[14].integer.value;
hpx->t2->sec_unc_err_sever_or = fields[15].integer.value;
hpx->t2->sec_unc_err_mask_and = fields[16].integer.value;
hpx->t2->sec_unc_err_mask_or = fields[17].integer.value;
break;
default:
printk(KERN_WARNING
"%s: Type 2 Revision %d record not supported\n",
__func__, revision);
return AE_ERROR;
}
return AE_OK;
}
static acpi_status
acpi_run_hpx(acpi_handle handle, struct hotplug_params *hpx)
{
acpi_status status;
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *package, *record, *fields;
u32 type;
int i;
memset(hpx, 0, sizeof(struct hotplug_params));
status = acpi_evaluate_object(handle, "_HPX", NULL, &buffer);
if (ACPI_FAILURE(status))
return status;
package = (union acpi_object *)buffer.pointer;
if (package->type != ACPI_TYPE_PACKAGE) {
status = AE_ERROR;
goto exit;
}
for (i = 0; i < package->package.count; i++) {
record = &package->package.elements[i];
if (record->type != ACPI_TYPE_PACKAGE) {
status = AE_ERROR;
goto exit;
}
fields = record->package.elements;
if (fields[0].type != ACPI_TYPE_INTEGER ||
fields[1].type != ACPI_TYPE_INTEGER) {
status = AE_ERROR;
goto exit;
}
type = fields[0].integer.value;
switch (type) {
case 0:
status = decode_type0_hpx_record(record, hpx);
if (ACPI_FAILURE(status))
goto exit;
break;
case 1:
status = decode_type1_hpx_record(record, hpx);
if (ACPI_FAILURE(status))
goto exit;
break;
case 2:
status = decode_type2_hpx_record(record, hpx);
if (ACPI_FAILURE(status))
goto exit;
break;
default:
printk(KERN_ERR "%s: Type %d record not supported\n",
__func__, type);
status = AE_ERROR;
goto exit;
}
}
exit:
kfree(buffer.pointer);
return status;
}
static acpi_status
acpi_run_hpp(acpi_handle handle, struct hotplug_params *hpp)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *package, *fields;
int i;
memset(hpp, 0, sizeof(struct hotplug_params));
status = acpi_evaluate_object(handle, "_HPP", NULL, &buffer);
if (ACPI_FAILURE(status))
return status;
package = (union acpi_object *) buffer.pointer;
if (package->type != ACPI_TYPE_PACKAGE ||
package->package.count != 4) {
status = AE_ERROR;
goto exit;
}
fields = package->package.elements;
for (i = 0; i < 4; i++) {
if (fields[i].type != ACPI_TYPE_INTEGER) {
status = AE_ERROR;
goto exit;
}
}
hpp->t0 = &hpp->type0_data;
hpp->t0->revision = 1;
hpp->t0->cache_line_size = fields[0].integer.value;
hpp->t0->latency_timer = fields[1].integer.value;
hpp->t0->enable_serr = fields[2].integer.value;
hpp->t0->enable_perr = fields[3].integer.value;
exit:
kfree(buffer.pointer);
return status;
}
static acpi_status acpi_run_oshp(acpi_handle handle)
{
acpi_status status;
struct acpi_buffer string = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_get_name(handle, ACPI_FULL_PATHNAME, &string);
status = acpi_evaluate_object(handle, METHOD_NAME_OSHP, NULL, NULL);
if (ACPI_FAILURE(status))
if (status != AE_NOT_FOUND)
printk(KERN_ERR "%s:%s OSHP fails=0x%x\n",
__func__, (char *)string.pointer, status);
else
dbg("%s:%s OSHP not found\n",
__func__, (char *)string.pointer);
else
pr_debug("%s:%s OSHP passes\n", __func__,
(char *)string.pointer);
kfree(string.pointer);
return status;
}
int pci_get_hp_params(struct pci_dev *dev, struct hotplug_params *hpp)
{
acpi_status status;
acpi_handle handle, phandle;
struct pci_bus *pbus;
handle = NULL;
for (pbus = dev->bus; pbus; pbus = pbus->parent) {
handle = acpi_pci_get_bridge_handle(pbus);
if (handle)
break;
}
while (handle) {
status = acpi_run_hpx(handle, hpp);
if (ACPI_SUCCESS(status))
return 0;
status = acpi_run_hpp(handle, hpp);
if (ACPI_SUCCESS(status))
return 0;
if (acpi_is_root_bridge(handle))
break;
status = acpi_get_parent(handle, &phandle);
if (ACPI_FAILURE(status))
break;
handle = phandle;
}
return -ENODEV;
}
int acpi_get_hp_hw_control_from_firmware(struct pci_dev *pdev, u32 flags)
{
acpi_status status;
acpi_handle chandle, handle;
struct acpi_buffer string = { ACPI_ALLOCATE_BUFFER, NULL };
flags &= OSC_SHPC_NATIVE_HP_CONTROL;
if (!flags) {
err("Invalid flags %u specified!\n", flags);
return -EINVAL;
}
handle = acpi_find_root_bridge_handle(pdev);
if (handle) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &string);
dbg("Trying to get hotplug control for %s\n",
(char *)string.pointer);
status = acpi_pci_osc_control_set(handle, &flags, flags);
if (ACPI_SUCCESS(status))
goto got_one;
if (status == AE_SUPPORT)
goto no_control;
kfree(string.pointer);
string = (struct acpi_buffer){ ACPI_ALLOCATE_BUFFER, NULL };
}
handle = DEVICE_ACPI_HANDLE(&pdev->dev);
if (!handle) {
struct pci_bus *pbus;
for (pbus = pdev->bus; pbus; pbus = pbus->parent) {
handle = acpi_pci_get_bridge_handle(pbus);
if (handle)
break;
}
}
while (handle) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &string);
dbg("Trying to get hotplug control for %s \n",
(char *)string.pointer);
status = acpi_run_oshp(handle);
if (ACPI_SUCCESS(status))
goto got_one;
if (acpi_is_root_bridge(handle))
break;
chandle = handle;
status = acpi_get_parent(chandle, &handle);
if (ACPI_FAILURE(status))
break;
}
no_control:
dbg("Cannot get control of hotplug hardware for pci %s\n",
pci_name(pdev));
kfree(string.pointer);
return -ENODEV;
got_one:
dbg("Gained control for hotplug HW for pci %s (%s)\n",
pci_name(pdev), (char *)string.pointer);
kfree(string.pointer);
return 0;
}
static int is_ejectable(acpi_handle handle)
{
acpi_status status;
acpi_handle tmp;
unsigned long long removable;
status = acpi_get_handle(handle, "_ADR", &tmp);
if (ACPI_FAILURE(status))
return 0;
status = acpi_get_handle(handle, "_EJ0", &tmp);
if (ACPI_SUCCESS(status))
return 1;
status = acpi_evaluate_integer(handle, "_RMV", NULL, &removable);
if (ACPI_SUCCESS(status) && removable)
return 1;
return 0;
}
int acpi_pci_check_ejectable(struct pci_bus *pbus, acpi_handle handle)
{
acpi_handle bridge_handle, parent_handle;
if (!(bridge_handle = acpi_pci_get_bridge_handle(pbus)))
return 0;
if ((ACPI_FAILURE(acpi_get_parent(handle, &parent_handle))))
return 0;
if (bridge_handle != parent_handle)
return 0;
return is_ejectable(handle);
}
static acpi_status
check_hotplug(acpi_handle handle, u32 lvl, void *context, void **rv)
{
int *found = (int *)context;
if (is_ejectable(handle)) {
*found = 1;
return AE_CTRL_TERMINATE;
}
return AE_OK;
}
int acpi_pci_detect_ejectable(acpi_handle handle)
{
int found = 0;
if (!handle)
return found;
acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
check_hotplug, NULL, (void *)&found, NULL);
return found;
}
