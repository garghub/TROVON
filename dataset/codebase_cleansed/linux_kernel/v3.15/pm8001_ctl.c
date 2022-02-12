static ssize_t pm8001_ctl_mpi_interface_rev_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
if (pm8001_ha->chip_id == chip_8001) {
return snprintf(buf, PAGE_SIZE, "%d\n",
pm8001_ha->main_cfg_tbl.pm8001_tbl.interface_rev);
} else {
return snprintf(buf, PAGE_SIZE, "%d\n",
pm8001_ha->main_cfg_tbl.pm80xx_tbl.interface_rev);
}
}
static ssize_t pm8001_ctl_fw_version_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
if (pm8001_ha->chip_id == chip_8001) {
return snprintf(buf, PAGE_SIZE, "%02x.%02x.%02x.%02x\n",
(u8)(pm8001_ha->main_cfg_tbl.pm8001_tbl.firmware_rev >> 24),
(u8)(pm8001_ha->main_cfg_tbl.pm8001_tbl.firmware_rev >> 16),
(u8)(pm8001_ha->main_cfg_tbl.pm8001_tbl.firmware_rev >> 8),
(u8)(pm8001_ha->main_cfg_tbl.pm8001_tbl.firmware_rev));
} else {
return snprintf(buf, PAGE_SIZE, "%02x.%02x.%02x.%02x\n",
(u8)(pm8001_ha->main_cfg_tbl.pm80xx_tbl.firmware_rev >> 24),
(u8)(pm8001_ha->main_cfg_tbl.pm80xx_tbl.firmware_rev >> 16),
(u8)(pm8001_ha->main_cfg_tbl.pm80xx_tbl.firmware_rev >> 8),
(u8)(pm8001_ha->main_cfg_tbl.pm80xx_tbl.firmware_rev));
}
}
static ssize_t pm8001_ctl_max_out_io_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
if (pm8001_ha->chip_id == chip_8001) {
return snprintf(buf, PAGE_SIZE, "%d\n",
pm8001_ha->main_cfg_tbl.pm8001_tbl.max_out_io);
} else {
return snprintf(buf, PAGE_SIZE, "%d\n",
pm8001_ha->main_cfg_tbl.pm80xx_tbl.max_out_io);
}
}
static ssize_t pm8001_ctl_max_devices_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
if (pm8001_ha->chip_id == chip_8001) {
return snprintf(buf, PAGE_SIZE, "%04d\n",
(u16)(pm8001_ha->main_cfg_tbl.pm8001_tbl.max_sgl >> 16)
);
} else {
return snprintf(buf, PAGE_SIZE, "%04d\n",
(u16)(pm8001_ha->main_cfg_tbl.pm80xx_tbl.max_sgl >> 16)
);
}
}
static ssize_t pm8001_ctl_max_sg_list_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
if (pm8001_ha->chip_id == chip_8001) {
return snprintf(buf, PAGE_SIZE, "%04d\n",
pm8001_ha->main_cfg_tbl.pm8001_tbl.max_sgl & 0x0000FFFF
);
} else {
return snprintf(buf, PAGE_SIZE, "%04d\n",
pm8001_ha->main_cfg_tbl.pm80xx_tbl.max_sgl & 0x0000FFFF
);
}
}
static ssize_t
show_sas_spec_support_status(unsigned int mode, char *buf)
{
ssize_t len = 0;
if (mode & SAS_1_1)
len = sprintf(buf, "%s", "SAS1.1");
if (mode & SAS_2_0)
len += sprintf(buf + len, "%s%s", len ? ", " : "", "SAS2.0");
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t pm8001_ctl_sas_spec_support_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
unsigned int mode;
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
if (pm8001_ha->chip_id == chip_8001)
mode = (pm8001_ha->main_cfg_tbl.pm8001_tbl.ctrl_cap_flag &
0xfe000000)>>25;
else
mode = (pm8001_ha->main_cfg_tbl.pm80xx_tbl.ctrl_cap_flag &
0xfe000000)>>25;
return show_sas_spec_support_status(mode, buf);
}
static ssize_t pm8001_ctl_host_sas_address_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
return snprintf(buf, PAGE_SIZE, "0x%016llx\n",
be64_to_cpu(*(__be64 *)pm8001_ha->sas_addr));
}
static ssize_t pm8001_ctl_logging_level_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
return snprintf(buf, PAGE_SIZE, "%08xh\n", pm8001_ha->logging_level);
}
static ssize_t pm8001_ctl_logging_level_store(struct device *cdev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
int val = 0;
if (sscanf(buf, "%x", &val) != 1)
return -EINVAL;
pm8001_ha->logging_level = val;
return strlen(buf);
}
static ssize_t pm8001_ctl_aap_log_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
int i;
#define AAP1_MEMMAP(r, c) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[AAP1].virt_ptr + (r) * 32 \
+ (c)))
char *str = buf;
int max = 2;
for (i = 0; i < max; i++) {
str += sprintf(str, "0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x"
"0x%08x 0x%08x\n",
AAP1_MEMMAP(i, 0),
AAP1_MEMMAP(i, 4),
AAP1_MEMMAP(i, 8),
AAP1_MEMMAP(i, 12),
AAP1_MEMMAP(i, 16),
AAP1_MEMMAP(i, 20),
AAP1_MEMMAP(i, 24),
AAP1_MEMMAP(i, 28));
}
return str - buf;
}
static ssize_t pm8001_ctl_ib_queue_log_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
int offset;
char *str = buf;
int start = 0;
#define IB_MEMMAP(c) \
(*(u32 *)((u8 *)pm8001_ha-> \
memoryMap.region[IB].virt_ptr + \
pm8001_ha->evtlog_ib_offset + (c)))
for (offset = 0; offset < IB_OB_READ_TIMES; offset++) {
str += sprintf(str, "0x%08x\n", IB_MEMMAP(start));
start = start + 4;
}
pm8001_ha->evtlog_ib_offset += SYSFS_OFFSET;
if (((pm8001_ha->evtlog_ib_offset) % (PM80XX_IB_OB_QUEUE_SIZE)) == 0)
pm8001_ha->evtlog_ib_offset = 0;
return str - buf;
}
static ssize_t pm8001_ctl_ob_queue_log_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
int offset;
char *str = buf;
int start = 0;
#define OB_MEMMAP(c) \
(*(u32 *)((u8 *)pm8001_ha-> \
memoryMap.region[OB].virt_ptr + \
pm8001_ha->evtlog_ob_offset + (c)))
for (offset = 0; offset < IB_OB_READ_TIMES; offset++) {
str += sprintf(str, "0x%08x\n", OB_MEMMAP(start));
start = start + 4;
}
pm8001_ha->evtlog_ob_offset += SYSFS_OFFSET;
if (((pm8001_ha->evtlog_ob_offset) % (PM80XX_IB_OB_QUEUE_SIZE)) == 0)
pm8001_ha->evtlog_ob_offset = 0;
return str - buf;
}
static ssize_t pm8001_ctl_bios_version_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
char *str = buf;
void *virt_addr;
int bios_index;
DECLARE_COMPLETION_ONSTACK(completion);
struct pm8001_ioctl_payload payload;
pm8001_ha->nvmd_completion = &completion;
payload.minor_function = 7;
payload.offset = 0;
payload.length = 4096;
payload.func_specific = kzalloc(4096, GFP_KERNEL);
PM8001_CHIP_DISP->get_nvmd_req(pm8001_ha, &payload);
wait_for_completion(&completion);
virt_addr = pm8001_ha->memoryMap.region[NVMD].virt_ptr;
for (bios_index = BIOSOFFSET; bios_index < BIOS_OFFSET_LIMIT;
bios_index++)
str += sprintf(str, "%c",
*((u8 *)((u8 *)virt_addr+bios_index)));
return str - buf;
}
static ssize_t pm8001_ctl_iop_log_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
#define IOP_MEMMAP(r, c) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[IOP].virt_ptr + (r) * 32 \
+ (c)))
int i;
char *str = buf;
int max = 2;
for (i = 0; i < max; i++) {
str += sprintf(str, "0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x"
"0x%08x 0x%08x\n",
IOP_MEMMAP(i, 0),
IOP_MEMMAP(i, 4),
IOP_MEMMAP(i, 8),
IOP_MEMMAP(i, 12),
IOP_MEMMAP(i, 16),
IOP_MEMMAP(i, 20),
IOP_MEMMAP(i, 24),
IOP_MEMMAP(i, 28));
}
return str - buf;
}
static ssize_t pm8001_ctl_fatal_log_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
ssize_t count;
count = pm80xx_get_fatal_dump(cdev, attr, buf);
return count;
}
static ssize_t pm8001_ctl_gsm_log_show(struct device *cdev,
struct device_attribute *attr, char *buf)
{
ssize_t count;
count = pm8001_get_gsm_dump(cdev, SYSFS_OFFSET, buf);
return count;
}
static int pm8001_set_nvmd(struct pm8001_hba_info *pm8001_ha)
{
struct pm8001_ioctl_payload *payload;
DECLARE_COMPLETION_ONSTACK(completion);
u8 *ioctlbuffer = NULL;
u32 length = 0;
u32 ret = 0;
length = 1024 * 5 + sizeof(*payload) - 1;
ioctlbuffer = kzalloc(length, GFP_KERNEL);
if (!ioctlbuffer)
return -ENOMEM;
if ((pm8001_ha->fw_image->size <= 0) ||
(pm8001_ha->fw_image->size > 4096)) {
ret = FAIL_FILE_SIZE;
goto out;
}
payload = (struct pm8001_ioctl_payload *)ioctlbuffer;
memcpy((u8 *)&payload->func_specific, (u8 *)pm8001_ha->fw_image->data,
pm8001_ha->fw_image->size);
payload->length = pm8001_ha->fw_image->size;
payload->id = 0;
payload->minor_function = 0x1;
pm8001_ha->nvmd_completion = &completion;
ret = PM8001_CHIP_DISP->set_nvmd_req(pm8001_ha, payload);
wait_for_completion(&completion);
out:
kfree(ioctlbuffer);
return ret;
}
static int pm8001_update_flash(struct pm8001_hba_info *pm8001_ha)
{
struct pm8001_ioctl_payload *payload;
DECLARE_COMPLETION_ONSTACK(completion);
u8 *ioctlbuffer = NULL;
u32 length = 0;
struct fw_control_info *fwControl;
u32 loopNumber, loopcount = 0;
u32 sizeRead = 0;
u32 partitionSize, partitionSizeTmp;
u32 ret = 0;
u32 partitionNumber = 0;
struct pm8001_fw_image_header *image_hdr;
length = 1024 * 16 + sizeof(*payload) - 1;
ioctlbuffer = kzalloc(length, GFP_KERNEL);
image_hdr = (struct pm8001_fw_image_header *)pm8001_ha->fw_image->data;
if (!ioctlbuffer)
return -ENOMEM;
if (pm8001_ha->fw_image->size < 28) {
ret = FAIL_FILE_SIZE;
goto out;
}
while (sizeRead < pm8001_ha->fw_image->size) {
partitionSizeTmp =
*(u32 *)((u8 *)&image_hdr->image_length + sizeRead);
partitionSize = be32_to_cpu(partitionSizeTmp);
loopcount = (partitionSize + HEADER_LEN)/IOCTL_BUF_SIZE;
if (loopcount % IOCTL_BUF_SIZE)
loopcount++;
if (loopcount == 0)
loopcount++;
for (loopNumber = 0; loopNumber < loopcount; loopNumber++) {
payload = (struct pm8001_ioctl_payload *)ioctlbuffer;
payload->length = 1024*16;
payload->id = 0;
fwControl =
(struct fw_control_info *)&payload->func_specific;
fwControl->len = IOCTL_BUF_SIZE;
fwControl->size = partitionSize + HEADER_LEN;
fwControl->retcode = 0;
fwControl->offset = loopNumber * IOCTL_BUF_SIZE;
if (((loopcount-loopNumber) == 1) &&
((partitionSize + HEADER_LEN) % IOCTL_BUF_SIZE)) {
fwControl->len =
(partitionSize + HEADER_LEN) % IOCTL_BUF_SIZE;
memcpy((u8 *)fwControl->buffer,
(u8 *)pm8001_ha->fw_image->data + sizeRead,
(partitionSize + HEADER_LEN) % IOCTL_BUF_SIZE);
sizeRead +=
(partitionSize + HEADER_LEN) % IOCTL_BUF_SIZE;
} else {
memcpy((u8 *)fwControl->buffer,
(u8 *)pm8001_ha->fw_image->data + sizeRead,
IOCTL_BUF_SIZE);
sizeRead += IOCTL_BUF_SIZE;
}
pm8001_ha->nvmd_completion = &completion;
ret = PM8001_CHIP_DISP->fw_flash_update_req(pm8001_ha, payload);
wait_for_completion(&completion);
if (ret || (fwControl->retcode > FLASH_UPDATE_IN_PROGRESS)) {
ret = fwControl->retcode;
kfree(ioctlbuffer);
ioctlbuffer = NULL;
break;
}
}
if (ret)
break;
partitionNumber++;
}
out:
kfree(ioctlbuffer);
return ret;
}
static ssize_t pm8001_store_update_fw(struct device *cdev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
char *cmd_ptr, *filename_ptr;
int res, i;
int flash_command = FLASH_CMD_NONE;
int err = 0;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
cmd_ptr = kzalloc(count*2, GFP_KERNEL);
if (!cmd_ptr) {
err = FAIL_OUT_MEMORY;
goto out;
}
filename_ptr = cmd_ptr + count;
res = sscanf(buf, "%s %s", cmd_ptr, filename_ptr);
if (res != 2) {
err = FAIL_PARAMETERS;
goto out1;
}
for (i = 0; flash_command_table[i].code != FLASH_CMD_NONE; i++) {
if (!memcmp(flash_command_table[i].command,
cmd_ptr, strlen(cmd_ptr))) {
flash_command = flash_command_table[i].code;
break;
}
}
if (flash_command == FLASH_CMD_NONE) {
err = FAIL_PARAMETERS;
goto out1;
}
if (pm8001_ha->fw_status == FLASH_IN_PROGRESS) {
err = FLASH_IN_PROGRESS;
goto out1;
}
err = request_firmware(&pm8001_ha->fw_image,
filename_ptr,
pm8001_ha->dev);
if (err) {
PM8001_FAIL_DBG(pm8001_ha,
pm8001_printk("Failed to load firmware image file %s,"
" error %d\n", filename_ptr, err));
err = FAIL_OPEN_BIOS_FILE;
goto out1;
}
switch (flash_command) {
case FLASH_CMD_UPDATE:
pm8001_ha->fw_status = FLASH_IN_PROGRESS;
err = pm8001_update_flash(pm8001_ha);
break;
case FLASH_CMD_SET_NVMD:
pm8001_ha->fw_status = FLASH_IN_PROGRESS;
err = pm8001_set_nvmd(pm8001_ha);
break;
default:
pm8001_ha->fw_status = FAIL_PARAMETERS;
err = FAIL_PARAMETERS;
break;
}
release_firmware(pm8001_ha->fw_image);
out1:
kfree(cmd_ptr);
out:
pm8001_ha->fw_status = err;
if (!err)
return count;
else
return -err;
}
static ssize_t pm8001_show_update_fw(struct device *cdev,
struct device_attribute *attr, char *buf)
{
int i;
struct Scsi_Host *shost = class_to_shost(cdev);
struct sas_ha_struct *sha = SHOST_TO_SAS_HA(shost);
struct pm8001_hba_info *pm8001_ha = sha->lldd_ha;
for (i = 0; flash_error_table[i].err_code != 0; i++) {
if (flash_error_table[i].err_code == pm8001_ha->fw_status)
break;
}
if (pm8001_ha->fw_status != FLASH_IN_PROGRESS)
pm8001_ha->fw_status = FLASH_OK;
return snprintf(buf, PAGE_SIZE, "status=%x %s\n",
flash_error_table[i].err_code,
flash_error_table[i].reason);
}
