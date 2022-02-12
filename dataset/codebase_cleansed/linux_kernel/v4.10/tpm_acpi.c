int tpm_read_log_acpi(struct tpm_chip *chip)
{
struct acpi_tcpa *buff;
acpi_status status;
void __iomem *virt;
u64 len, start;
struct tpm_bios_log *log;
log = &chip->log;
if (!chip->acpi_dev_handle)
return -ENODEV;
status = acpi_get_table(ACPI_SIG_TCPA, 1,
(struct acpi_table_header **)&buff);
if (ACPI_FAILURE(status))
return -ENODEV;
switch(buff->platform_class) {
case BIOS_SERVER:
len = buff->server.log_max_len;
start = buff->server.log_start_addr;
break;
case BIOS_CLIENT:
default:
len = buff->client.log_max_len;
start = buff->client.log_start_addr;
break;
}
if (!len) {
dev_warn(&chip->dev, "%s: TCPA log area empty\n", __func__);
return -EIO;
}
log->bios_event_log = kmalloc(len, GFP_KERNEL);
if (!log->bios_event_log)
return -ENOMEM;
log->bios_event_log_end = log->bios_event_log + len;
virt = acpi_os_map_iomem(start, len);
if (!virt)
goto err;
memcpy_fromio(log->bios_event_log, virt, len);
acpi_os_unmap_iomem(virt, len);
return 0;
err:
kfree(log->bios_event_log);
log->bios_event_log = NULL;
return -EIO;
}
