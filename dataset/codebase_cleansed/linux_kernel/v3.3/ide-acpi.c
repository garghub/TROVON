static int no_acpi_psx(const struct dmi_system_id *id)
{
ide_noacpi_psx = true;
printk(KERN_NOTICE"%s detected - disable ACPI _PSx.\n", id->ident);
return 0;
}
int ide_acpi_init(void)
{
dmi_check_system(ide_acpi_dmi_table);
return 0;
}
bool ide_port_acpi(ide_hwif_t *hwif)
{
return ide_noacpi == 0 && hwif->acpidata;
}
static int ide_get_dev_handle(struct device *dev, acpi_handle *handle,
u64 *pcidevfn)
{
struct pci_dev *pdev = to_pci_dev(dev);
unsigned int bus, devnum, func;
u64 addr;
acpi_handle dev_handle;
acpi_status status;
struct acpi_device_info *dinfo = NULL;
int ret = -ENODEV;
bus = pdev->bus->number;
devnum = PCI_SLOT(pdev->devfn);
func = PCI_FUNC(pdev->devfn);
addr = (u64)(devnum << 16 | func);
DEBPRINT("ENTER: pci %02x:%02x.%01x\n", bus, devnum, func);
dev_handle = DEVICE_ACPI_HANDLE(dev);
if (!dev_handle) {
DEBPRINT("no acpi handle for device\n");
goto err;
}
status = acpi_get_object_info(dev_handle, &dinfo);
if (ACPI_FAILURE(status)) {
DEBPRINT("get_object_info for device failed\n");
goto err;
}
if (dinfo && (dinfo->valid & ACPI_VALID_ADR) &&
dinfo->address == addr) {
*pcidevfn = addr;
*handle = dev_handle;
} else {
DEBPRINT("get_object_info for device has wrong "
" address: %llu, should be %u\n",
dinfo ? (unsigned long long)dinfo->address : -1ULL,
(unsigned int)addr);
goto err;
}
DEBPRINT("for dev=0x%x.%x, addr=0x%llx, *handle=0x%p\n",
devnum, func, (unsigned long long)addr, *handle);
ret = 0;
err:
kfree(dinfo);
return ret;
}
static acpi_handle ide_acpi_hwif_get_handle(ide_hwif_t *hwif)
{
struct device *dev = hwif->gendev.parent;
acpi_handle uninitialized_var(dev_handle);
u64 pcidevfn;
acpi_handle chan_handle;
int err;
DEBPRINT("ENTER: device %s\n", hwif->name);
if (!dev) {
DEBPRINT("no PCI device for %s\n", hwif->name);
return NULL;
}
err = ide_get_dev_handle(dev, &dev_handle, &pcidevfn);
if (err < 0) {
DEBPRINT("ide_get_dev_handle failed (%d)\n", err);
return NULL;
}
chan_handle = acpi_get_child(dev_handle, hwif->channel);
DEBPRINT("chan adr=%d: handle=0x%p\n",
hwif->channel, chan_handle);
return chan_handle;
}
static int do_drive_get_GTF(ide_drive_t *drive,
unsigned int *gtf_length, unsigned long *gtf_address,
unsigned long *obj_loc)
{
acpi_status status;
struct acpi_buffer output;
union acpi_object *out_obj;
int err = -ENODEV;
*gtf_length = 0;
*gtf_address = 0UL;
*obj_loc = 0UL;
if (!drive->acpidata->obj_handle) {
DEBPRINT("No ACPI object found for %s\n", drive->name);
goto out;
}
output.length = ACPI_ALLOCATE_BUFFER;
output.pointer = NULL;
err = -EIO;
status = acpi_evaluate_object(drive->acpidata->obj_handle, "_GTF",
NULL, &output);
if (ACPI_FAILURE(status)) {
printk(KERN_DEBUG
"%s: Run _GTF error: status = 0x%x\n",
__func__, status);
goto out;
}
if (!output.length || !output.pointer) {
DEBPRINT("Run _GTF: "
"length or ptr is NULL (0x%llx, 0x%p)\n",
(unsigned long long)output.length,
output.pointer);
goto out;
}
out_obj = output.pointer;
if (out_obj->type != ACPI_TYPE_BUFFER) {
DEBPRINT("Run _GTF: error: "
"expected object type of ACPI_TYPE_BUFFER, "
"got 0x%x\n", out_obj->type);
err = -ENOENT;
kfree(output.pointer);
goto out;
}
if (!out_obj->buffer.length || !out_obj->buffer.pointer ||
out_obj->buffer.length % REGS_PER_GTF) {
printk(KERN_ERR
"%s: unexpected GTF length (%d) or addr (0x%p)\n",
__func__, out_obj->buffer.length,
out_obj->buffer.pointer);
err = -ENOENT;
kfree(output.pointer);
goto out;
}
*gtf_length = out_obj->buffer.length;
*gtf_address = (unsigned long)out_obj->buffer.pointer;
*obj_loc = (unsigned long)out_obj;
DEBPRINT("returning gtf_length=%d, gtf_address=0x%lx, obj_loc=0x%lx\n",
*gtf_length, *gtf_address, *obj_loc);
err = 0;
out:
return err;
}
static int do_drive_set_taskfiles(ide_drive_t *drive,
unsigned int gtf_length,
unsigned long gtf_address)
{
int rc = 0, err;
int gtf_count = gtf_length / REGS_PER_GTF;
int ix;
DEBPRINT("total GTF bytes=%u (0x%x), gtf_count=%d, addr=0x%lx\n",
gtf_length, gtf_length, gtf_count, gtf_address);
for (ix = 0; ix < gtf_count; ix++) {
u8 *gtf = (u8 *)(gtf_address + ix * REGS_PER_GTF);
struct ide_cmd cmd;
DEBPRINT("(0x1f1-1f7): "
"hex: %02x %02x %02x %02x %02x %02x %02x\n",
gtf[0], gtf[1], gtf[2],
gtf[3], gtf[4], gtf[5], gtf[6]);
if (!ide_acpigtf) {
DEBPRINT("_GTF execution disabled\n");
continue;
}
memset(&cmd, 0, sizeof(cmd));
memcpy(&cmd.tf.feature, gtf, REGS_PER_GTF);
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
err = ide_no_data_taskfile(drive, &cmd);
if (err) {
printk(KERN_ERR "%s: ide_no_data_taskfile failed: %u\n",
__func__, err);
rc = err;
}
}
return rc;
}
int ide_acpi_exec_tfs(ide_drive_t *drive)
{
int ret;
unsigned int gtf_length;
unsigned long gtf_address;
unsigned long obj_loc;
DEBPRINT("call get_GTF, drive=%s port=%d\n", drive->name, drive->dn);
ret = do_drive_get_GTF(drive, &gtf_length, &gtf_address, &obj_loc);
if (ret < 0) {
DEBPRINT("get_GTF error (%d)\n", ret);
return ret;
}
DEBPRINT("call set_taskfiles, drive=%s\n", drive->name);
ret = do_drive_set_taskfiles(drive, gtf_length, gtf_address);
kfree((void *)obj_loc);
if (ret < 0) {
DEBPRINT("set_taskfiles error (%d)\n", ret);
}
DEBPRINT("ret=%d\n", ret);
return ret;
}
void ide_acpi_get_timing(ide_hwif_t *hwif)
{
acpi_status status;
struct acpi_buffer output;
union acpi_object *out_obj;
output.length = ACPI_ALLOCATE_BUFFER;
output.pointer = NULL;
status = acpi_evaluate_object(hwif->acpidata->obj_handle, "_GTM",
NULL, &output);
DEBPRINT("_GTM status: %d, outptr: 0x%p, outlen: 0x%llx\n",
status, output.pointer,
(unsigned long long)output.length);
if (ACPI_FAILURE(status)) {
DEBPRINT("Run _GTM error: status = 0x%x\n", status);
return;
}
if (!output.length || !output.pointer) {
DEBPRINT("Run _GTM: length or ptr is NULL (0x%llx, 0x%p)\n",
(unsigned long long)output.length,
output.pointer);
kfree(output.pointer);
return;
}
out_obj = output.pointer;
if (out_obj->type != ACPI_TYPE_BUFFER) {
DEBPRINT("Run _GTM: error: "
"expected object type of ACPI_TYPE_BUFFER, "
"got 0x%x\n", out_obj->type);
kfree(output.pointer);
return;
}
if (!out_obj->buffer.length || !out_obj->buffer.pointer ||
out_obj->buffer.length != sizeof(struct GTM_buffer)) {
printk(KERN_ERR
"%s: unexpected _GTM length (0x%x)[should be 0x%zx] or "
"addr (0x%p)\n",
__func__, out_obj->buffer.length,
sizeof(struct GTM_buffer), out_obj->buffer.pointer);
kfree(output.pointer);
return;
}
memcpy(&hwif->acpidata->gtm, out_obj->buffer.pointer,
sizeof(struct GTM_buffer));
DEBPRINT("_GTM info: ptr: 0x%p, len: 0x%x, exp.len: 0x%Zx\n",
out_obj->buffer.pointer, out_obj->buffer.length,
sizeof(struct GTM_buffer));
DEBPRINT("_GTM fields: 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
hwif->acpidata->gtm.PIO_speed0,
hwif->acpidata->gtm.DMA_speed0,
hwif->acpidata->gtm.PIO_speed1,
hwif->acpidata->gtm.DMA_speed1,
hwif->acpidata->gtm.GTM_flags);
kfree(output.pointer);
}
void ide_acpi_push_timing(ide_hwif_t *hwif)
{
acpi_status status;
struct acpi_object_list input;
union acpi_object in_params[3];
struct ide_acpi_drive_link *master = &hwif->acpidata->master;
struct ide_acpi_drive_link *slave = &hwif->acpidata->slave;
input.count = 3;
input.pointer = in_params;
in_params[0].type = ACPI_TYPE_BUFFER;
in_params[0].buffer.length = sizeof(struct GTM_buffer);
in_params[0].buffer.pointer = (u8 *)&hwif->acpidata->gtm;
in_params[1].type = ACPI_TYPE_BUFFER;
in_params[1].buffer.length = ATA_ID_WORDS * 2;
in_params[1].buffer.pointer = (u8 *)&master->idbuff;
in_params[2].type = ACPI_TYPE_BUFFER;
in_params[2].buffer.length = ATA_ID_WORDS * 2;
in_params[2].buffer.pointer = (u8 *)&slave->idbuff;
status = acpi_evaluate_object(hwif->acpidata->obj_handle, "_STM",
&input, NULL);
if (ACPI_FAILURE(status)) {
DEBPRINT("Run _STM error: status = 0x%x\n", status);
}
DEBPRINT("_STM status: %d\n", status);
}
void ide_acpi_set_state(ide_hwif_t *hwif, int on)
{
ide_drive_t *drive;
int i;
if (ide_noacpi_psx)
return;
DEBPRINT("ENTER:\n");
if (on)
acpi_bus_set_power(hwif->acpidata->obj_handle, ACPI_STATE_D0);
ide_port_for_each_present_dev(i, drive, hwif) {
if (drive->acpidata->obj_handle)
acpi_bus_set_power(drive->acpidata->obj_handle,
on ? ACPI_STATE_D0 : ACPI_STATE_D3);
}
if (!on)
acpi_bus_set_power(hwif->acpidata->obj_handle, ACPI_STATE_D3);
}
void ide_acpi_init_port(ide_hwif_t *hwif)
{
hwif->acpidata = kzalloc(sizeof(struct ide_acpi_hwif_link), GFP_KERNEL);
if (!hwif->acpidata)
return;
hwif->acpidata->obj_handle = ide_acpi_hwif_get_handle(hwif);
if (!hwif->acpidata->obj_handle) {
DEBPRINT("no ACPI object for %s found\n", hwif->name);
kfree(hwif->acpidata);
hwif->acpidata = NULL;
}
}
void ide_acpi_port_init_devices(ide_hwif_t *hwif)
{
ide_drive_t *drive;
int i, err;
if (hwif->acpidata == NULL)
return;
hwif->devices[0]->acpidata = &hwif->acpidata->master;
hwif->devices[1]->acpidata = &hwif->acpidata->slave;
ide_port_for_each_present_dev(i, drive, hwif) {
acpi_handle dev_handle;
DEBPRINT("ENTER: %s at channel#: %d port#: %d\n",
drive->name, hwif->channel, drive->dn & 1);
dev_handle = acpi_get_child(hwif->acpidata->obj_handle,
drive->dn & 1);
DEBPRINT("drive %s handle 0x%p\n", drive->name, dev_handle);
drive->acpidata->obj_handle = dev_handle;
}
ide_port_for_each_present_dev(i, drive, hwif) {
err = taskfile_lib_get_identify(drive, drive->acpidata->idbuff);
if (err)
DEBPRINT("identify device %s failed (%d)\n",
drive->name, err);
}
if (ide_noacpi || ide_acpionboot == 0) {
DEBPRINT("ACPI methods disabled on boot\n");
return;
}
ide_acpi_set_state(hwif, 1);
ide_acpi_get_timing(hwif);
ide_acpi_push_timing(hwif);
ide_port_for_each_present_dev(i, drive, hwif) {
ide_acpi_exec_tfs(drive);
}
}
