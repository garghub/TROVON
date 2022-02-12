void __init xen_efi_init(void)
{
efi_system_table_t *efi_systab_xen;
efi_systab_xen = xen_efi_probe();
if (efi_systab_xen == NULL)
return;
strncpy((char *)&boot_params.efi_info.efi_loader_signature, "Xen",
sizeof(boot_params.efi_info.efi_loader_signature));
boot_params.efi_info.efi_systab = (__u32)__pa(efi_systab_xen);
boot_params.efi_info.efi_systab_hi = (__u32)(__pa(efi_systab_xen) >> 32);
set_bit(EFI_BOOT, &efi.flags);
set_bit(EFI_PARAVIRT, &efi.flags);
set_bit(EFI_64BIT, &efi.flags);
}
