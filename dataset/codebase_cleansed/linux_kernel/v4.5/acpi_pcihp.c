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
int acpi_get_hp_hw_control_from_firmware(struct pci_dev *pdev, u32 flags)
{
acpi_status status;
acpi_handle chandle, handle;
struct acpi_buffer string = { ACPI_ALLOCATE_BUFFER, NULL };
flags &= OSC_PCI_SHPC_NATIVE_HP_CONTROL;
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
handle = ACPI_HANDLE(&pdev->dev);
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
dbg("Trying to get hotplug control for %s\n",
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
static int pcihp_is_ejectable(acpi_handle handle)
{
acpi_status status;
unsigned long long removable;
if (!acpi_has_method(handle, "_ADR"))
return 0;
if (acpi_has_method(handle, "_EJ0"))
return 1;
status = acpi_evaluate_integer(handle, "_RMV", NULL, &removable);
if (ACPI_SUCCESS(status) && removable)
return 1;
return 0;
}
int acpi_pci_check_ejectable(struct pci_bus *pbus, acpi_handle handle)
{
acpi_handle bridge_handle, parent_handle;
bridge_handle = acpi_pci_get_bridge_handle(pbus);
if (!bridge_handle)
return 0;
if ((ACPI_FAILURE(acpi_get_parent(handle, &parent_handle))))
return 0;
if (bridge_handle != parent_handle)
return 0;
return pcihp_is_ejectable(handle);
}
static acpi_status
check_hotplug(acpi_handle handle, u32 lvl, void *context, void **rv)
{
int *found = (int *)context;
if (pcihp_is_ejectable(handle)) {
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
