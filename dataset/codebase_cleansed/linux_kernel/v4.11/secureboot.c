enum efi_secureboot_mode efi_get_secureboot(efi_system_table_t *sys_table_arg)
{
u32 attr;
u8 secboot, setupmode, moksbstate;
unsigned long size;
efi_status_t status;
size = sizeof(secboot);
status = get_efi_var(efi_SecureBoot_name, &efi_variable_guid,
NULL, &size, &secboot);
if (status == EFI_NOT_FOUND)
return efi_secureboot_mode_disabled;
if (status != EFI_SUCCESS)
goto out_efi_err;
size = sizeof(setupmode);
status = get_efi_var(efi_SetupMode_name, &efi_variable_guid,
NULL, &size, &setupmode);
if (status != EFI_SUCCESS)
goto out_efi_err;
if (secboot == 0 || setupmode == 1)
return efi_secureboot_mode_disabled;
size = sizeof(moksbstate);
status = get_efi_var(shim_MokSBState_name, &shim_guid,
&attr, &size, &moksbstate);
if (status != EFI_SUCCESS)
goto secure_boot_enabled;
if (!(attr & EFI_VARIABLE_RUNTIME_ACCESS) && moksbstate == 1)
return efi_secureboot_mode_disabled;
secure_boot_enabled:
pr_efi(sys_table_arg, "UEFI Secure Boot is enabled.\n");
return efi_secureboot_mode_enabled;
out_efi_err:
pr_efi_err(sys_table_arg, "Could not determine UEFI Secure Boot status.\n");
return efi_secureboot_mode_unknown;
}
