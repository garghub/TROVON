int read_log(struct tpm_bios_log *log)
{
struct acpi_tcpa *buff;
acpi_status status;
void __iomem *virt;
u64 len, start;
if (log->bios_event_log != NULL) {
printk(KERN_ERR
"%s: ERROR - Eventlog already initialized\n",
__func__);
return -EFAULT;
}
status = acpi_get_table(ACPI_SIG_TCPA, 1,
(struct acpi_table_header **)&buff);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR "%s: ERROR - Could not get TCPA table\n",
__func__);
return -EIO;
}
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
printk(KERN_ERR "%s: ERROR - TCPA log area empty\n", __func__);
return -EIO;
}
log->bios_event_log = kmalloc(len, GFP_KERNEL);
if (!log->bios_event_log) {
printk("%s: ERROR - Not enough Memory for BIOS measurements\n",
__func__);
return -ENOMEM;
}
log->bios_event_log_end = log->bios_event_log + len;
virt = acpi_os_map_iomem(start, len);
if (!virt) {
kfree(log->bios_event_log);
printk("%s: ERROR - Unable to map memory\n", __func__);
return -EIO;
}
memcpy_fromio(log->bios_event_log, virt, len);
acpi_os_unmap_iomem(virt, len);
return 0;
}
