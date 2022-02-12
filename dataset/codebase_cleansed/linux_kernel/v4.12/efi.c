static efi_system_table_t __init *xen_efi_probe(void)
{
struct xen_platform_op op = {
.cmd = XENPF_firmware_info,
.u.firmware_info = {
.type = XEN_FW_EFI_INFO,
.index = XEN_FW_EFI_CONFIG_TABLE
}
};
union xenpf_efi_info *info = &op.u.firmware_info.u.efi_info;
if (!xen_initial_domain() || HYPERVISOR_platform_op(&op) < 0)
return NULL;
efi = efi_xen;
efi_systab_xen.tables = info->cfg.addr;
efi_systab_xen.nr_tables = info->cfg.nent;
op.cmd = XENPF_firmware_info;
op.u.firmware_info.type = XEN_FW_EFI_INFO;
op.u.firmware_info.index = XEN_FW_EFI_VENDOR;
info->vendor.bufsz = sizeof(vendor);
set_xen_guest_handle(info->vendor.name, vendor);
if (HYPERVISOR_platform_op(&op) == 0) {
efi_systab_xen.fw_vendor = __pa_symbol(vendor);
efi_systab_xen.fw_revision = info->vendor.revision;
} else
efi_systab_xen.fw_vendor = __pa_symbol(L"UNKNOWN");
op.cmd = XENPF_firmware_info;
op.u.firmware_info.type = XEN_FW_EFI_INFO;
op.u.firmware_info.index = XEN_FW_EFI_VERSION;
if (HYPERVISOR_platform_op(&op) == 0)
efi_systab_xen.hdr.revision = info->version;
op.cmd = XENPF_firmware_info;
op.u.firmware_info.type = XEN_FW_EFI_INFO;
op.u.firmware_info.index = XEN_FW_EFI_RT_VERSION;
if (HYPERVISOR_platform_op(&op) == 0)
efi.runtime_version = info->version;
return &efi_systab_xen;
}
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
