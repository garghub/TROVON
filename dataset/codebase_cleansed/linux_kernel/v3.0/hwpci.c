acpi_status
acpi_hw_derive_pci_id(struct acpi_pci_id *pci_id,
acpi_handle root_pci_device, acpi_handle pci_region)
{
acpi_status status;
struct acpi_pci_device *list_head = NULL;
ACPI_FUNCTION_TRACE(hw_derive_pci_id);
if (!pci_id) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status =
acpi_hw_build_pci_list(root_pci_device, pci_region, &list_head);
if (ACPI_SUCCESS(status)) {
status = acpi_hw_process_pci_list(pci_id, list_head);
}
acpi_hw_delete_pci_list(list_head);
return_ACPI_STATUS(status);
}
static acpi_status
acpi_hw_build_pci_list(acpi_handle root_pci_device,
acpi_handle pci_region,
struct acpi_pci_device **return_list_head)
{
acpi_handle current_device;
acpi_handle parent_device;
acpi_status status;
struct acpi_pci_device *list_element;
struct acpi_pci_device *list_head = NULL;
current_device = pci_region;
while (1) {
status = acpi_get_parent(current_device, &parent_device);
if (ACPI_FAILURE(status)) {
return (status);
}
if (parent_device == root_pci_device) {
*return_list_head = list_head;
return (AE_OK);
}
list_element = ACPI_ALLOCATE(sizeof(struct acpi_pci_device));
if (!list_element) {
return (AE_NO_MEMORY);
}
list_element->next = list_head;
list_element->device = parent_device;
list_head = list_element;
current_device = parent_device;
}
}
static acpi_status
acpi_hw_process_pci_list(struct acpi_pci_id *pci_id,
struct acpi_pci_device *list_head)
{
acpi_status status = AE_OK;
struct acpi_pci_device *info;
u16 bus_number;
u8 is_bridge = TRUE;
ACPI_FUNCTION_NAME(hw_process_pci_list);
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Input PciId: Seg %4.4X Bus %4.4X Dev %4.4X Func %4.4X\n",
pci_id->segment, pci_id->bus, pci_id->device,
pci_id->function));
bus_number = pci_id->bus;
info = list_head;
while (info) {
status = acpi_hw_get_pci_device_info(pci_id, info->device,
&bus_number, &is_bridge);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
info = info->next;
}
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Output PciId: Seg %4.4X Bus %4.4X Dev %4.4X Func %4.4X "
"Status %X BusNumber %X IsBridge %X\n",
pci_id->segment, pci_id->bus, pci_id->device,
pci_id->function, status, bus_number, is_bridge));
return_ACPI_STATUS(AE_OK);
}
static void acpi_hw_delete_pci_list(struct acpi_pci_device *list_head)
{
struct acpi_pci_device *next;
struct acpi_pci_device *previous;
next = list_head;
while (next) {
previous = next;
next = previous->next;
ACPI_FREE(previous);
}
}
static acpi_status
acpi_hw_get_pci_device_info(struct acpi_pci_id *pci_id,
acpi_handle pci_device,
u16 *bus_number, u8 *is_bridge)
{
acpi_status status;
acpi_object_type object_type;
u64 return_value;
u64 pci_value;
status = acpi_get_type(pci_device, &object_type);
if (ACPI_FAILURE(status)) {
return (status);
}
if (object_type != ACPI_TYPE_DEVICE) {
return (AE_OK);
}
status = acpi_ut_evaluate_numeric_object(METHOD_NAME__ADR,
pci_device, &return_value);
if (ACPI_FAILURE(status)) {
return (AE_OK);
}
pci_id->device = ACPI_HIWORD(ACPI_LODWORD(return_value));
pci_id->function = ACPI_LOWORD(ACPI_LODWORD(return_value));
if (*is_bridge) {
pci_id->bus = *bus_number;
}
*is_bridge = FALSE;
status = acpi_os_read_pci_configuration(pci_id,
PCI_CFG_HEADER_TYPE_REG,
&pci_value, 8);
if (ACPI_FAILURE(status)) {
return (status);
}
pci_value &= PCI_HEADER_TYPE_MASK;
if ((pci_value != PCI_TYPE_BRIDGE) &&
(pci_value != PCI_TYPE_CARDBUS_BRIDGE)) {
return (AE_OK);
}
status = acpi_os_read_pci_configuration(pci_id,
PCI_CFG_PRIMARY_BUS_NUMBER_REG,
&pci_value, 8);
if (ACPI_FAILURE(status)) {
return (status);
}
*is_bridge = TRUE;
pci_id->bus = (u16)pci_value;
status = acpi_os_read_pci_configuration(pci_id,
PCI_CFG_SECONDARY_BUS_NUMBER_REG,
&pci_value, 8);
if (ACPI_FAILURE(status)) {
return (status);
}
*bus_number = (u16)pci_value;
return (AE_OK);
}
