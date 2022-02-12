void efi_enable_reset_attack_mitigation(efi_system_table_t *sys_table_arg)
{
u8 val = 1;
efi_guid_t var_guid = MEMORY_ONLY_RESET_CONTROL_GUID;
efi_status_t status;
unsigned long datasize = 0;
status = get_efi_var(efi_MemoryOverWriteRequest_name, &var_guid,
NULL, &datasize, NULL);
if (status == EFI_NOT_FOUND)
return;
set_efi_var(efi_MemoryOverWriteRequest_name, &var_guid,
EFI_VARIABLE_NON_VOLATILE |
EFI_VARIABLE_BOOTSERVICE_ACCESS |
EFI_VARIABLE_RUNTIME_ACCESS, sizeof(val), &val);
}
