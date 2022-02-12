acpi_status acpi_hw_set_mode(u32 mode)
{
acpi_status status;
ACPI_FUNCTION_TRACE(hw_set_mode);
if (!acpi_gbl_FADT.smi_command) {
ACPI_ERROR((AE_INFO,
"No SMI_CMD in FADT, mode transition failed"));
return_ACPI_STATUS(AE_NO_HARDWARE_RESPONSE);
}
if (!acpi_gbl_FADT.acpi_enable && !acpi_gbl_FADT.acpi_disable) {
ACPI_ERROR((AE_INFO,
"No ACPI mode transition supported in this system "
"(enable/disable both zero)"));
return_ACPI_STATUS(AE_OK);
}
switch (mode) {
case ACPI_SYS_MODE_ACPI:
status = acpi_hw_write_port(acpi_gbl_FADT.smi_command,
(u32) acpi_gbl_FADT.acpi_enable, 8);
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Attempting to enable ACPI mode\n"));
break;
case ACPI_SYS_MODE_LEGACY:
status = acpi_hw_write_port(acpi_gbl_FADT.smi_command,
(u32) acpi_gbl_FADT.acpi_disable,
8);
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Attempting to enable Legacy (non-ACPI) mode\n"));
break;
default:
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Could not write ACPI mode change"));
return_ACPI_STATUS(status);
}
return_ACPI_STATUS(AE_OK);
}
u32 acpi_hw_get_mode(void)
{
acpi_status status;
u32 value;
ACPI_FUNCTION_TRACE(hw_get_mode);
if (!acpi_gbl_FADT.smi_command) {
return_UINT32(ACPI_SYS_MODE_ACPI);
}
status = acpi_read_bit_register(ACPI_BITREG_SCI_ENABLE, &value);
if (ACPI_FAILURE(status)) {
return_UINT32(ACPI_SYS_MODE_LEGACY);
}
if (value) {
return_UINT32(ACPI_SYS_MODE_ACPI);
} else {
return_UINT32(ACPI_SYS_MODE_LEGACY);
}
}
