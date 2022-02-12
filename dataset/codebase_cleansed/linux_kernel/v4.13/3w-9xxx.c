static ssize_t twa_show_stats(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
unsigned long flags = 0;
ssize_t len;
spin_lock_irqsave(tw_dev->host->host_lock, flags);
len = snprintf(buf, PAGE_SIZE, "3w-9xxx Driver version: %s\n"
"Current commands posted: %4d\n"
"Max commands posted: %4d\n"
"Current pending commands: %4d\n"
"Max pending commands: %4d\n"
"Last sgl length: %4d\n"
"Max sgl length: %4d\n"
"Last sector count: %4d\n"
"Max sector count: %4d\n"
"SCSI Host Resets: %4d\n"
"AEN's: %4d\n",
TW_DRIVER_VERSION,
tw_dev->posted_request_count,
tw_dev->max_posted_request_count,
tw_dev->pending_request_count,
tw_dev->max_pending_request_count,
tw_dev->sgl_entries,
tw_dev->max_sgl_entries,
tw_dev->sector_count,
tw_dev->max_sector_count,
tw_dev->num_resets,
tw_dev->aen_count);
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
return len;
}
static bool twa_command_mapped(struct scsi_cmnd *cmd)
{
return scsi_sg_count(cmd) != 1 ||
scsi_bufflen(cmd) >= TW_MIN_SGL_LENGTH;
}
static int twa_aen_complete(TW_Device_Extension *tw_dev, int request_id)
{
TW_Command_Full *full_command_packet;
TW_Command *command_packet;
TW_Command_Apache_Header *header;
unsigned short aen;
int retval = 1;
header = (TW_Command_Apache_Header *)tw_dev->generic_buffer_virt[request_id];
tw_dev->posted_request_count--;
aen = le16_to_cpu(header->status_block.error);
full_command_packet = tw_dev->command_packet_virt[request_id];
command_packet = &full_command_packet->command.oldcommand;
if (TW_OP_OUT(command_packet->opcode__sgloffset) == TW_OP_SET_PARAM) {
if (twa_aen_read_queue(tw_dev, request_id))
goto out2;
else {
retval = 0;
goto out;
}
}
switch (aen) {
case TW_AEN_QUEUE_EMPTY:
break;
case TW_AEN_SYNC_TIME_WITH_HOST:
twa_aen_sync_time(tw_dev, request_id);
retval = 0;
goto out;
default:
twa_aen_queue_event(tw_dev, header);
if (twa_aen_read_queue(tw_dev, request_id))
goto out2;
else {
retval = 0;
goto out;
}
}
retval = 0;
out2:
tw_dev->state[request_id] = TW_S_COMPLETED;
twa_free_request_id(tw_dev, request_id);
clear_bit(TW_IN_ATTENTION_LOOP, &tw_dev->flags);
out:
return retval;
}
static int twa_aen_drain_queue(TW_Device_Extension *tw_dev, int no_check_reset)
{
int request_id = 0;
char cdb[TW_MAX_CDB_LEN];
TW_SG_Entry sglist[1];
int finished = 0, count = 0;
TW_Command_Full *full_command_packet;
TW_Command_Apache_Header *header;
unsigned short aen;
int first_reset = 0, queue = 0, retval = 1;
if (no_check_reset)
first_reset = 0;
else
first_reset = 1;
full_command_packet = tw_dev->command_packet_virt[request_id];
memset(full_command_packet, 0, sizeof(TW_Command_Full));
memset(&cdb, 0, TW_MAX_CDB_LEN);
cdb[0] = REQUEST_SENSE;
cdb[4] = TW_ALLOCATION_LENGTH;
memset(&sglist, 0, sizeof(TW_SG_Entry));
sglist[0].length = TW_SECTOR_SIZE;
sglist[0].address = tw_dev->generic_buffer_phys[request_id];
if (sglist[0].address & TW_ALIGNMENT_9000_SGL) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x1, "Found unaligned address during AEN drain");
goto out;
}
tw_dev->srb[request_id] = NULL;
do {
if (twa_scsiop_execute_scsi(tw_dev, request_id, cdb, 1, sglist)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x2, "Error posting request sense");
goto out;
}
if (twa_poll_response(tw_dev, request_id, 30)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x3, "No valid response while draining AEN queue");
tw_dev->posted_request_count--;
goto out;
}
tw_dev->posted_request_count--;
header = (TW_Command_Apache_Header *)tw_dev->generic_buffer_virt[request_id];
aen = le16_to_cpu(header->status_block.error);
queue = 0;
count++;
switch (aen) {
case TW_AEN_QUEUE_EMPTY:
if (first_reset != 1)
goto out;
else
finished = 1;
break;
case TW_AEN_SOFT_RESET:
if (first_reset == 0)
first_reset = 1;
else
queue = 1;
break;
case TW_AEN_SYNC_TIME_WITH_HOST:
break;
default:
queue = 1;
}
if (queue)
twa_aen_queue_event(tw_dev, header);
} while ((finished == 0) && (count < TW_MAX_AEN_DRAIN));
if (count == TW_MAX_AEN_DRAIN)
goto out;
retval = 0;
out:
tw_dev->state[request_id] = TW_S_INITIAL;
return retval;
}
static void twa_aen_queue_event(TW_Device_Extension *tw_dev, TW_Command_Apache_Header *header)
{
u32 local_time;
struct timeval time;
TW_Event *event;
unsigned short aen;
char host[16];
char *error_str;
tw_dev->aen_count++;
event = tw_dev->event_queue[tw_dev->error_index];
host[0] = '\0';
if (tw_dev->host) {
sprintf(host, " scsi%d:", tw_dev->host->host_no);
if (event->retrieved == TW_AEN_NOT_RETRIEVED)
tw_dev->aen_clobber = 1;
}
aen = le16_to_cpu(header->status_block.error);
memset(event, 0, sizeof(TW_Event));
event->severity = TW_SEV_OUT(header->status_block.severity__reserved);
do_gettimeofday(&time);
local_time = (u32)(time.tv_sec - (sys_tz.tz_minuteswest * 60));
event->time_stamp_sec = local_time;
event->aen_code = aen;
event->retrieved = TW_AEN_NOT_RETRIEVED;
event->sequence_id = tw_dev->error_sequence_id;
tw_dev->error_sequence_id++;
error_str = &(header->err_specific_desc[strlen(header->err_specific_desc)+1]);
header->err_specific_desc[sizeof(header->err_specific_desc) - 1] = '\0';
event->parameter_len = strlen(header->err_specific_desc);
memcpy(event->parameter_data, header->err_specific_desc, event->parameter_len + (error_str[0] == '\0' ? 0 : (1 + strlen(error_str))));
if (event->severity != TW_AEN_SEVERITY_DEBUG)
printk(KERN_WARNING "3w-9xxx:%s AEN: %s (0x%02X:0x%04X): %s:%s.\n",
host,
twa_aen_severity_lookup(TW_SEV_OUT(header->status_block.severity__reserved)),
TW_MESSAGE_SOURCE_CONTROLLER_EVENT, aen,
error_str[0] == '\0' ? twa_string_lookup(twa_aen_table, aen) : error_str,
header->err_specific_desc);
else
tw_dev->aen_count--;
if ((tw_dev->error_index + 1) == TW_Q_LENGTH)
tw_dev->event_queue_wrapped = 1;
tw_dev->error_index = (tw_dev->error_index + 1 ) % TW_Q_LENGTH;
}
static int twa_aen_read_queue(TW_Device_Extension *tw_dev, int request_id)
{
char cdb[TW_MAX_CDB_LEN];
TW_SG_Entry sglist[1];
TW_Command_Full *full_command_packet;
int retval = 1;
full_command_packet = tw_dev->command_packet_virt[request_id];
memset(full_command_packet, 0, sizeof(TW_Command_Full));
memset(&cdb, 0, TW_MAX_CDB_LEN);
cdb[0] = REQUEST_SENSE;
cdb[4] = TW_ALLOCATION_LENGTH;
memset(&sglist, 0, sizeof(TW_SG_Entry));
sglist[0].length = TW_SECTOR_SIZE;
sglist[0].address = tw_dev->generic_buffer_phys[request_id];
tw_dev->srb[request_id] = NULL;
if (twa_scsiop_execute_scsi(tw_dev, request_id, cdb, 1, sglist)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x4, "Post failed while reading AEN queue");
goto out;
}
retval = 0;
out:
return retval;
}
static char *twa_aen_severity_lookup(unsigned char severity_code)
{
char *retval = NULL;
if ((severity_code < (unsigned char) TW_AEN_SEVERITY_ERROR) ||
(severity_code > (unsigned char) TW_AEN_SEVERITY_DEBUG))
goto out;
retval = twa_aen_severity_table[severity_code];
out:
return retval;
}
static void twa_aen_sync_time(TW_Device_Extension *tw_dev, int request_id)
{
u32 schedulertime;
struct timeval utc;
TW_Command_Full *full_command_packet;
TW_Command *command_packet;
TW_Param_Apache *param;
u32 local_time;
full_command_packet = tw_dev->command_packet_virt[request_id];
memset(full_command_packet, 0, sizeof(TW_Command_Full));
command_packet = &full_command_packet->command.oldcommand;
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_SET_PARAM);
command_packet->request_id = request_id;
command_packet->byte8_offset.param.sgl[0].address = TW_CPU_TO_SGL(tw_dev->generic_buffer_phys[request_id]);
command_packet->byte8_offset.param.sgl[0].length = cpu_to_le32(TW_SECTOR_SIZE);
command_packet->size = TW_COMMAND_SIZE;
command_packet->byte6_offset.parameter_count = cpu_to_le16(1);
param = (TW_Param_Apache *)tw_dev->generic_buffer_virt[request_id];
memset(param, 0, TW_SECTOR_SIZE);
param->table_id = cpu_to_le16(TW_TIMEKEEP_TABLE | 0x8000);
param->parameter_id = cpu_to_le16(0x3);
param->parameter_size_bytes = cpu_to_le16(4);
do_gettimeofday(&utc);
local_time = (u32)(utc.tv_sec - (sys_tz.tz_minuteswest * 60));
schedulertime = local_time - (3 * 86400);
schedulertime = cpu_to_le32(schedulertime % 604800);
memcpy(param->data, &schedulertime, sizeof(u32));
tw_dev->srb[request_id] = NULL;
twa_post_command_packet(tw_dev, request_id, 1);
}
static int twa_allocate_memory(TW_Device_Extension *tw_dev, int size, int which)
{
int i;
dma_addr_t dma_handle;
unsigned long *cpu_addr;
int retval = 1;
cpu_addr = pci_alloc_consistent(tw_dev->tw_pci_dev, size*TW_Q_LENGTH, &dma_handle);
if (!cpu_addr) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x5, "Memory allocation failed");
goto out;
}
if ((unsigned long)cpu_addr % (TW_ALIGNMENT_9000)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x6, "Failed to allocate correctly aligned memory");
pci_free_consistent(tw_dev->tw_pci_dev, size*TW_Q_LENGTH, cpu_addr, dma_handle);
goto out;
}
memset(cpu_addr, 0, size*TW_Q_LENGTH);
for (i = 0; i < TW_Q_LENGTH; i++) {
switch(which) {
case 0:
tw_dev->command_packet_phys[i] = dma_handle+(i*size);
tw_dev->command_packet_virt[i] = (TW_Command_Full *)((unsigned char *)cpu_addr + (i*size));
break;
case 1:
tw_dev->generic_buffer_phys[i] = dma_handle+(i*size);
tw_dev->generic_buffer_virt[i] = (unsigned long *)((unsigned char *)cpu_addr + (i*size));
break;
}
}
retval = 0;
out:
return retval;
}
static int twa_check_bits(u32 status_reg_value)
{
int retval = 1;
if ((status_reg_value & TW_STATUS_EXPECTED_BITS) != TW_STATUS_EXPECTED_BITS)
goto out;
if ((status_reg_value & TW_STATUS_UNEXPECTED_BITS) != 0)
goto out;
retval = 0;
out:
return retval;
}
static int twa_check_srl(TW_Device_Extension *tw_dev, int *flashed)
{
int retval = 1;
unsigned short fw_on_ctlr_srl = 0, fw_on_ctlr_arch_id = 0;
unsigned short fw_on_ctlr_branch = 0, fw_on_ctlr_build = 0;
u32 init_connect_result = 0;
if (twa_initconnection(tw_dev, TW_INIT_MESSAGE_CREDITS,
TW_EXTENDED_INIT_CONNECT, TW_CURRENT_DRIVER_SRL,
TW_9000_ARCH_ID, TW_CURRENT_DRIVER_BRANCH,
TW_CURRENT_DRIVER_BUILD, &fw_on_ctlr_srl,
&fw_on_ctlr_arch_id, &fw_on_ctlr_branch,
&fw_on_ctlr_build, &init_connect_result)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x7, "Initconnection failed while checking SRL");
goto out;
}
tw_dev->tw_compat_info.working_srl = fw_on_ctlr_srl;
tw_dev->tw_compat_info.working_branch = fw_on_ctlr_branch;
tw_dev->tw_compat_info.working_build = fw_on_ctlr_build;
if (!(init_connect_result & TW_CTLR_FW_COMPATIBLE)) {
if (twa_initconnection(tw_dev, TW_INIT_MESSAGE_CREDITS,
TW_EXTENDED_INIT_CONNECT,
TW_BASE_FW_SRL, TW_9000_ARCH_ID,
TW_BASE_FW_BRANCH, TW_BASE_FW_BUILD,
&fw_on_ctlr_srl, &fw_on_ctlr_arch_id,
&fw_on_ctlr_branch, &fw_on_ctlr_build,
&init_connect_result)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0xa, "Initconnection (base mode) failed while checking SRL");
goto out;
}
if (!(init_connect_result & TW_CTLR_FW_COMPATIBLE)) {
if (TW_CURRENT_DRIVER_SRL > fw_on_ctlr_srl) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x32, "Firmware and driver incompatibility: please upgrade firmware");
} else {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x33, "Firmware and driver incompatibility: please upgrade driver");
}
goto out;
}
tw_dev->tw_compat_info.working_srl = TW_BASE_FW_SRL;
tw_dev->tw_compat_info.working_branch = TW_BASE_FW_BRANCH;
tw_dev->tw_compat_info.working_build = TW_BASE_FW_BUILD;
}
strlcpy(tw_dev->tw_compat_info.driver_version, TW_DRIVER_VERSION,
sizeof(tw_dev->tw_compat_info.driver_version));
tw_dev->tw_compat_info.driver_srl_high = TW_CURRENT_DRIVER_SRL;
tw_dev->tw_compat_info.driver_branch_high = TW_CURRENT_DRIVER_BRANCH;
tw_dev->tw_compat_info.driver_build_high = TW_CURRENT_DRIVER_BUILD;
tw_dev->tw_compat_info.driver_srl_low = TW_BASE_FW_SRL;
tw_dev->tw_compat_info.driver_branch_low = TW_BASE_FW_BRANCH;
tw_dev->tw_compat_info.driver_build_low = TW_BASE_FW_BUILD;
tw_dev->tw_compat_info.fw_on_ctlr_srl = fw_on_ctlr_srl;
tw_dev->tw_compat_info.fw_on_ctlr_branch = fw_on_ctlr_branch;
tw_dev->tw_compat_info.fw_on_ctlr_build = fw_on_ctlr_build;
retval = 0;
out:
return retval;
}
static long twa_chrdev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct inode *inode = file_inode(file);
long timeout;
unsigned long *cpu_addr, data_buffer_length_adjusted = 0, flags = 0;
dma_addr_t dma_handle;
int request_id = 0;
unsigned int sequence_id = 0;
unsigned char event_index, start_index;
TW_Ioctl_Driver_Command driver_command;
TW_Ioctl_Buf_Apache *tw_ioctl;
TW_Lock *tw_lock;
TW_Command_Full *full_command_packet;
TW_Compatibility_Info *tw_compat_info;
TW_Event *event;
struct timeval current_time;
u32 current_time_ms;
TW_Device_Extension *tw_dev = twa_device_extension_list[iminor(inode)];
int retval = TW_IOCTL_ERROR_OS_EFAULT;
void __user *argp = (void __user *)arg;
mutex_lock(&twa_chrdev_mutex);
if (mutex_lock_interruptible(&tw_dev->ioctl_lock)) {
retval = TW_IOCTL_ERROR_OS_EINTR;
goto out;
}
if (copy_from_user(&driver_command, argp, sizeof(TW_Ioctl_Driver_Command)))
goto out2;
if (driver_command.buffer_length > TW_MAX_SECTORS * 2048) {
retval = TW_IOCTL_ERROR_OS_EINVAL;
goto out2;
}
data_buffer_length_adjusted = (driver_command.buffer_length + 511) & ~511;
cpu_addr = dma_alloc_coherent(&tw_dev->tw_pci_dev->dev, data_buffer_length_adjusted+sizeof(TW_Ioctl_Buf_Apache) - 1, &dma_handle, GFP_KERNEL);
if (!cpu_addr) {
retval = TW_IOCTL_ERROR_OS_ENOMEM;
goto out2;
}
tw_ioctl = (TW_Ioctl_Buf_Apache *)cpu_addr;
if (copy_from_user(tw_ioctl, argp, driver_command.buffer_length + sizeof(TW_Ioctl_Buf_Apache) - 1))
goto out3;
switch (cmd) {
case TW_IOCTL_FIRMWARE_PASS_THROUGH:
spin_lock_irqsave(tw_dev->host->host_lock, flags);
twa_get_request_id(tw_dev, &request_id);
tw_dev->srb[request_id] = NULL;
tw_dev->chrdev_request_id = request_id;
full_command_packet = &tw_ioctl->firmware_command;
twa_load_sgl(tw_dev, full_command_packet, request_id, dma_handle, data_buffer_length_adjusted);
memcpy(tw_dev->command_packet_virt[request_id], &(tw_ioctl->firmware_command), sizeof(TW_Command_Full));
twa_post_command_packet(tw_dev, request_id, 1);
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
timeout = TW_IOCTL_CHRDEV_TIMEOUT*HZ;
timeout = wait_event_timeout(tw_dev->ioctl_wqueue, tw_dev->chrdev_request_id == TW_IOCTL_CHRDEV_FREE, timeout);
if (tw_dev->chrdev_request_id != TW_IOCTL_CHRDEV_FREE) {
printk(KERN_WARNING "3w-9xxx: scsi%d: WARNING: (0x%02X:0x%04X): Character ioctl (0x%x) timed out, resetting card.\n",
tw_dev->host->host_no, TW_DRIVER, 0x37,
cmd);
retval = TW_IOCTL_ERROR_OS_EIO;
twa_reset_device_extension(tw_dev);
goto out3;
}
memcpy(&(tw_ioctl->firmware_command), tw_dev->command_packet_virt[request_id], sizeof(TW_Command_Full));
spin_lock_irqsave(tw_dev->host->host_lock, flags);
tw_dev->posted_request_count--;
tw_dev->state[request_id] = TW_S_COMPLETED;
twa_free_request_id(tw_dev, request_id);
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
break;
case TW_IOCTL_GET_COMPATIBILITY_INFO:
tw_ioctl->driver_command.status = 0;
tw_compat_info = (TW_Compatibility_Info *)tw_ioctl->data_buffer;
memcpy(tw_compat_info, &tw_dev->tw_compat_info, sizeof(TW_Compatibility_Info));
break;
case TW_IOCTL_GET_LAST_EVENT:
if (tw_dev->event_queue_wrapped) {
if (tw_dev->aen_clobber) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_AEN_CLOBBER;
tw_dev->aen_clobber = 0;
} else
tw_ioctl->driver_command.status = 0;
} else {
if (!tw_dev->error_index) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NO_MORE_EVENTS;
break;
}
tw_ioctl->driver_command.status = 0;
}
event_index = (tw_dev->error_index - 1 + TW_Q_LENGTH) % TW_Q_LENGTH;
memcpy(tw_ioctl->data_buffer, tw_dev->event_queue[event_index], sizeof(TW_Event));
tw_dev->event_queue[event_index]->retrieved = TW_AEN_RETRIEVED;
break;
case TW_IOCTL_GET_FIRST_EVENT:
if (tw_dev->event_queue_wrapped) {
if (tw_dev->aen_clobber) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_AEN_CLOBBER;
tw_dev->aen_clobber = 0;
} else
tw_ioctl->driver_command.status = 0;
event_index = tw_dev->error_index;
} else {
if (!tw_dev->error_index) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NO_MORE_EVENTS;
break;
}
tw_ioctl->driver_command.status = 0;
event_index = 0;
}
memcpy(tw_ioctl->data_buffer, tw_dev->event_queue[event_index], sizeof(TW_Event));
tw_dev->event_queue[event_index]->retrieved = TW_AEN_RETRIEVED;
break;
case TW_IOCTL_GET_NEXT_EVENT:
event = (TW_Event *)tw_ioctl->data_buffer;
sequence_id = event->sequence_id;
tw_ioctl->driver_command.status = 0;
if (tw_dev->event_queue_wrapped) {
if (tw_dev->aen_clobber) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_AEN_CLOBBER;
tw_dev->aen_clobber = 0;
}
start_index = tw_dev->error_index;
} else {
if (!tw_dev->error_index) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NO_MORE_EVENTS;
break;
}
start_index = 0;
}
event_index = (start_index + sequence_id - tw_dev->event_queue[start_index]->sequence_id + 1) % TW_Q_LENGTH;
if (!(tw_dev->event_queue[event_index]->sequence_id > sequence_id)) {
if (tw_ioctl->driver_command.status == TW_IOCTL_ERROR_STATUS_AEN_CLOBBER)
tw_dev->aen_clobber = 1;
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NO_MORE_EVENTS;
break;
}
memcpy(tw_ioctl->data_buffer, tw_dev->event_queue[event_index], sizeof(TW_Event));
tw_dev->event_queue[event_index]->retrieved = TW_AEN_RETRIEVED;
break;
case TW_IOCTL_GET_PREVIOUS_EVENT:
event = (TW_Event *)tw_ioctl->data_buffer;
sequence_id = event->sequence_id;
tw_ioctl->driver_command.status = 0;
if (tw_dev->event_queue_wrapped) {
if (tw_dev->aen_clobber) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_AEN_CLOBBER;
tw_dev->aen_clobber = 0;
}
start_index = tw_dev->error_index;
} else {
if (!tw_dev->error_index) {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NO_MORE_EVENTS;
break;
}
start_index = 0;
}
event_index = (start_index + sequence_id - tw_dev->event_queue[start_index]->sequence_id - 1) % TW_Q_LENGTH;
if (!(tw_dev->event_queue[event_index]->sequence_id < sequence_id)) {
if (tw_ioctl->driver_command.status == TW_IOCTL_ERROR_STATUS_AEN_CLOBBER)
tw_dev->aen_clobber = 1;
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NO_MORE_EVENTS;
break;
}
memcpy(tw_ioctl->data_buffer, tw_dev->event_queue[event_index], sizeof(TW_Event));
tw_dev->event_queue[event_index]->retrieved = TW_AEN_RETRIEVED;
break;
case TW_IOCTL_GET_LOCK:
tw_lock = (TW_Lock *)tw_ioctl->data_buffer;
do_gettimeofday(&current_time);
current_time_ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
if ((tw_lock->force_flag == 1) || (tw_dev->ioctl_sem_lock == 0) || (current_time_ms >= tw_dev->ioctl_msec)) {
tw_dev->ioctl_sem_lock = 1;
tw_dev->ioctl_msec = current_time_ms + tw_lock->timeout_msec;
tw_ioctl->driver_command.status = 0;
tw_lock->time_remaining_msec = tw_lock->timeout_msec;
} else {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_LOCKED;
tw_lock->time_remaining_msec = tw_dev->ioctl_msec - current_time_ms;
}
break;
case TW_IOCTL_RELEASE_LOCK:
if (tw_dev->ioctl_sem_lock == 1) {
tw_dev->ioctl_sem_lock = 0;
tw_ioctl->driver_command.status = 0;
} else {
tw_ioctl->driver_command.status = TW_IOCTL_ERROR_STATUS_NOT_LOCKED;
}
break;
default:
retval = TW_IOCTL_ERROR_OS_ENOTTY;
goto out3;
}
if (copy_to_user(argp, tw_ioctl, sizeof(TW_Ioctl_Buf_Apache) + driver_command.buffer_length - 1) == 0)
retval = 0;
out3:
dma_free_coherent(&tw_dev->tw_pci_dev->dev, data_buffer_length_adjusted+sizeof(TW_Ioctl_Buf_Apache) - 1, cpu_addr, dma_handle);
out2:
mutex_unlock(&tw_dev->ioctl_lock);
out:
mutex_unlock(&twa_chrdev_mutex);
return retval;
}
static int twa_chrdev_open(struct inode *inode, struct file *file)
{
unsigned int minor_number;
int retval = TW_IOCTL_ERROR_OS_ENODEV;
minor_number = iminor(inode);
if (minor_number >= twa_device_extension_count)
goto out;
retval = 0;
out:
return retval;
}
static int twa_decode_bits(TW_Device_Extension *tw_dev, u32 status_reg_value)
{
int retval = 1;
if (status_reg_value & TW_STATUS_PCI_PARITY_ERROR) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0xc, "PCI Parity Error: clearing");
writel(TW_CONTROL_CLEAR_PARITY_ERROR, TW_CONTROL_REG_ADDR(tw_dev));
}
if (status_reg_value & TW_STATUS_PCI_ABORT) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0xd, "PCI Abort: clearing");
writel(TW_CONTROL_CLEAR_PCI_ABORT, TW_CONTROL_REG_ADDR(tw_dev));
pci_write_config_word(tw_dev->tw_pci_dev, PCI_STATUS, TW_PCI_CLEAR_PCI_ABORT);
}
if (status_reg_value & TW_STATUS_QUEUE_ERROR) {
if (((tw_dev->tw_pci_dev->device != PCI_DEVICE_ID_3WARE_9650SE) &&
(tw_dev->tw_pci_dev->device != PCI_DEVICE_ID_3WARE_9690SA)) ||
(!test_bit(TW_IN_RESET, &tw_dev->flags)))
TW_PRINTK(tw_dev->host, TW_DRIVER, 0xe, "Controller Queue Error: clearing");
writel(TW_CONTROL_CLEAR_QUEUE_ERROR, TW_CONTROL_REG_ADDR(tw_dev));
}
if (status_reg_value & TW_STATUS_MICROCONTROLLER_ERROR) {
if (tw_dev->reset_print == 0) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x10, "Microcontroller Error: clearing");
tw_dev->reset_print = 1;
}
goto out;
}
retval = 0;
out:
return retval;
}
static int twa_empty_response_queue(TW_Device_Extension *tw_dev)
{
u32 status_reg_value, response_que_value;
int count = 0, retval = 1;
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
while (((status_reg_value & TW_STATUS_RESPONSE_QUEUE_EMPTY) == 0) && (count < TW_MAX_RESPONSE_DRAIN)) {
response_que_value = readl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
count++;
}
if (count == TW_MAX_RESPONSE_DRAIN)
goto out;
retval = 0;
out:
return retval;
}
static int twa_empty_response_queue_large(TW_Device_Extension *tw_dev)
{
u32 response_que_value = 0;
unsigned long before;
int retval = 1;
if (tw_dev->tw_pci_dev->device != PCI_DEVICE_ID_3WARE_9000) {
before = jiffies;
while ((response_que_value & TW_9550SX_DRAIN_COMPLETED) != TW_9550SX_DRAIN_COMPLETED) {
response_que_value = readl(TW_RESPONSE_QUEUE_REG_ADDR_LARGE(tw_dev));
msleep(1);
if (time_after(jiffies, before + HZ * 30))
goto out;
}
msleep(500);
retval = 0;
} else
retval = 0;
out:
return retval;
}
static int twa_fill_sense(TW_Device_Extension *tw_dev, int request_id, int copy_sense, int print_host)
{
TW_Command_Full *full_command_packet;
unsigned short error;
int retval = 1;
char *error_str;
full_command_packet = tw_dev->command_packet_virt[request_id];
error_str = &(full_command_packet->header.err_specific_desc[strlen(full_command_packet->header.err_specific_desc) + 1]);
error = le16_to_cpu(full_command_packet->header.status_block.error);
if ((error != TW_ERROR_LOGICAL_UNIT_NOT_SUPPORTED) && (error != TW_ERROR_UNIT_OFFLINE)) {
if (print_host)
printk(KERN_WARNING "3w-9xxx: scsi%d: ERROR: (0x%02X:0x%04X): %s:%s.\n",
tw_dev->host->host_no,
TW_MESSAGE_SOURCE_CONTROLLER_ERROR,
full_command_packet->header.status_block.error,
error_str[0] == '\0' ?
twa_string_lookup(twa_error_table,
full_command_packet->header.status_block.error) : error_str,
full_command_packet->header.err_specific_desc);
else
printk(KERN_WARNING "3w-9xxx: ERROR: (0x%02X:0x%04X): %s:%s.\n",
TW_MESSAGE_SOURCE_CONTROLLER_ERROR,
full_command_packet->header.status_block.error,
error_str[0] == '\0' ?
twa_string_lookup(twa_error_table,
full_command_packet->header.status_block.error) : error_str,
full_command_packet->header.err_specific_desc);
}
if (copy_sense) {
memcpy(tw_dev->srb[request_id]->sense_buffer, full_command_packet->header.sense_data, TW_SENSE_DATA_LENGTH);
tw_dev->srb[request_id]->result = (full_command_packet->command.newcommand.status << 1);
retval = TW_ISR_DONT_RESULT;
goto out;
}
retval = 0;
out:
return retval;
}
static void twa_free_device_extension(TW_Device_Extension *tw_dev)
{
if (tw_dev->command_packet_virt[0])
pci_free_consistent(tw_dev->tw_pci_dev,
sizeof(TW_Command_Full)*TW_Q_LENGTH,
tw_dev->command_packet_virt[0],
tw_dev->command_packet_phys[0]);
if (tw_dev->generic_buffer_virt[0])
pci_free_consistent(tw_dev->tw_pci_dev,
TW_SECTOR_SIZE*TW_Q_LENGTH,
tw_dev->generic_buffer_virt[0],
tw_dev->generic_buffer_phys[0]);
kfree(tw_dev->event_queue[0]);
}
static void twa_free_request_id(TW_Device_Extension *tw_dev, int request_id)
{
tw_dev->free_queue[tw_dev->free_tail] = request_id;
tw_dev->state[request_id] = TW_S_FINISHED;
tw_dev->free_tail = (tw_dev->free_tail + 1) % TW_Q_LENGTH;
}
static void *twa_get_param(TW_Device_Extension *tw_dev, int request_id, int table_id, int parameter_id, int parameter_size_bytes)
{
TW_Command_Full *full_command_packet;
TW_Command *command_packet;
TW_Param_Apache *param;
void *retval = NULL;
full_command_packet = tw_dev->command_packet_virt[request_id];
memset(full_command_packet, 0, sizeof(TW_Command_Full));
command_packet = &full_command_packet->command.oldcommand;
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = TW_COMMAND_SIZE;
command_packet->request_id = request_id;
command_packet->byte6_offset.block_count = cpu_to_le16(1);
param = (TW_Param_Apache *)tw_dev->generic_buffer_virt[request_id];
memset(param, 0, TW_SECTOR_SIZE);
param->table_id = cpu_to_le16(table_id | 0x8000);
param->parameter_id = cpu_to_le16(parameter_id);
param->parameter_size_bytes = cpu_to_le16(parameter_size_bytes);
command_packet->byte8_offset.param.sgl[0].address = TW_CPU_TO_SGL(tw_dev->generic_buffer_phys[request_id]);
command_packet->byte8_offset.param.sgl[0].length = cpu_to_le32(TW_SECTOR_SIZE);
twa_post_command_packet(tw_dev, request_id, 1);
if (twa_poll_response(tw_dev, request_id, 30))
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x13, "No valid response during get param")
else
retval = (void *)&(param->data[0]);
tw_dev->posted_request_count--;
tw_dev->state[request_id] = TW_S_INITIAL;
return retval;
}
static void twa_get_request_id(TW_Device_Extension *tw_dev, int *request_id)
{
*request_id = tw_dev->free_queue[tw_dev->free_head];
tw_dev->free_head = (tw_dev->free_head + 1) % TW_Q_LENGTH;
tw_dev->state[*request_id] = TW_S_STARTED;
}
static int twa_initconnection(TW_Device_Extension *tw_dev, int message_credits,
u32 set_features, unsigned short current_fw_srl,
unsigned short current_fw_arch_id,
unsigned short current_fw_branch,
unsigned short current_fw_build,
unsigned short *fw_on_ctlr_srl,
unsigned short *fw_on_ctlr_arch_id,
unsigned short *fw_on_ctlr_branch,
unsigned short *fw_on_ctlr_build,
u32 *init_connect_result)
{
TW_Command_Full *full_command_packet;
TW_Initconnect *tw_initconnect;
int request_id = 0, retval = 1;
full_command_packet = tw_dev->command_packet_virt[request_id];
memset(full_command_packet, 0, sizeof(TW_Command_Full));
full_command_packet->header.header_desc.size_header = 128;
tw_initconnect = (TW_Initconnect *)&full_command_packet->command.oldcommand;
tw_initconnect->opcode__reserved = TW_OPRES_IN(0, TW_OP_INIT_CONNECTION);
tw_initconnect->request_id = request_id;
tw_initconnect->message_credits = cpu_to_le16(message_credits);
tw_initconnect->features = set_features;
tw_initconnect->features |= sizeof(dma_addr_t) > 4 ? 1 : 0;
tw_initconnect->features = cpu_to_le32(tw_initconnect->features);
if (set_features & TW_EXTENDED_INIT_CONNECT) {
tw_initconnect->size = TW_INIT_COMMAND_PACKET_SIZE_EXTENDED;
tw_initconnect->fw_srl = cpu_to_le16(current_fw_srl);
tw_initconnect->fw_arch_id = cpu_to_le16(current_fw_arch_id);
tw_initconnect->fw_branch = cpu_to_le16(current_fw_branch);
tw_initconnect->fw_build = cpu_to_le16(current_fw_build);
} else
tw_initconnect->size = TW_INIT_COMMAND_PACKET_SIZE;
twa_post_command_packet(tw_dev, request_id, 1);
if (twa_poll_response(tw_dev, request_id, 30)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x15, "No valid response during init connection");
} else {
if (set_features & TW_EXTENDED_INIT_CONNECT) {
*fw_on_ctlr_srl = le16_to_cpu(tw_initconnect->fw_srl);
*fw_on_ctlr_arch_id = le16_to_cpu(tw_initconnect->fw_arch_id);
*fw_on_ctlr_branch = le16_to_cpu(tw_initconnect->fw_branch);
*fw_on_ctlr_build = le16_to_cpu(tw_initconnect->fw_build);
*init_connect_result = le32_to_cpu(tw_initconnect->result);
}
retval = 0;
}
tw_dev->posted_request_count--;
tw_dev->state[request_id] = TW_S_INITIAL;
return retval;
}
static int twa_initialize_device_extension(TW_Device_Extension *tw_dev)
{
int i, retval = 1;
if (twa_allocate_memory(tw_dev, sizeof(TW_Command_Full), 0)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x16, "Command packet memory allocation failed");
goto out;
}
if (twa_allocate_memory(tw_dev, TW_SECTOR_SIZE, 1)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x17, "Generic memory allocation failed");
goto out;
}
tw_dev->event_queue[0] = kcalloc(TW_Q_LENGTH, sizeof(TW_Event), GFP_KERNEL);
if (!tw_dev->event_queue[0]) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x18, "Event info memory allocation failed");
goto out;
}
for (i = 0; i < TW_Q_LENGTH; i++) {
tw_dev->event_queue[i] = (TW_Event *)((unsigned char *)tw_dev->event_queue[0] + (i * sizeof(TW_Event)));
tw_dev->free_queue[i] = i;
tw_dev->state[i] = TW_S_INITIAL;
}
tw_dev->pending_head = TW_Q_START;
tw_dev->pending_tail = TW_Q_START;
tw_dev->free_head = TW_Q_START;
tw_dev->free_tail = TW_Q_START;
tw_dev->error_sequence_id = 1;
tw_dev->chrdev_request_id = TW_IOCTL_CHRDEV_FREE;
mutex_init(&tw_dev->ioctl_lock);
init_waitqueue_head(&tw_dev->ioctl_wqueue);
retval = 0;
out:
return retval;
}
static irqreturn_t twa_interrupt(int irq, void *dev_instance)
{
int request_id, error = 0;
u32 status_reg_value;
TW_Response_Queue response_que;
TW_Command_Full *full_command_packet;
TW_Device_Extension *tw_dev = (TW_Device_Extension *)dev_instance;
int handled = 0;
spin_lock(tw_dev->host->host_lock);
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
if (!(status_reg_value & TW_STATUS_VALID_INTERRUPT))
goto twa_interrupt_bail;
handled = 1;
if (test_bit(TW_IN_RESET, &tw_dev->flags))
goto twa_interrupt_bail;
if (twa_check_bits(status_reg_value)) {
if (twa_decode_bits(tw_dev, status_reg_value)) {
TW_CLEAR_ALL_INTERRUPTS(tw_dev);
goto twa_interrupt_bail;
}
}
if (status_reg_value & TW_STATUS_HOST_INTERRUPT)
TW_CLEAR_HOST_INTERRUPT(tw_dev);
if (status_reg_value & TW_STATUS_ATTENTION_INTERRUPT) {
TW_CLEAR_ATTENTION_INTERRUPT(tw_dev);
if (!(test_and_set_bit(TW_IN_ATTENTION_LOOP, &tw_dev->flags))) {
twa_get_request_id(tw_dev, &request_id);
error = twa_aen_read_queue(tw_dev, request_id);
if (error) {
tw_dev->state[request_id] = TW_S_COMPLETED;
twa_free_request_id(tw_dev, request_id);
clear_bit(TW_IN_ATTENTION_LOOP, &tw_dev->flags);
}
}
}
if (status_reg_value & TW_STATUS_COMMAND_INTERRUPT) {
TW_MASK_COMMAND_INTERRUPT(tw_dev);
while (tw_dev->pending_request_count > 0) {
request_id = tw_dev->pending_queue[tw_dev->pending_head];
if (tw_dev->state[request_id] != TW_S_PENDING) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x19, "Found request id that wasn't pending");
TW_CLEAR_ALL_INTERRUPTS(tw_dev);
goto twa_interrupt_bail;
}
if (twa_post_command_packet(tw_dev, request_id, 1)==0) {
tw_dev->pending_head = (tw_dev->pending_head + 1) % TW_Q_LENGTH;
tw_dev->pending_request_count--;
} else {
break;
}
}
}
if (status_reg_value & TW_STATUS_RESPONSE_INTERRUPT) {
while ((status_reg_value & TW_STATUS_RESPONSE_QUEUE_EMPTY) == 0) {
response_que.value = readl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
request_id = TW_RESID_OUT(response_que.response_id);
full_command_packet = tw_dev->command_packet_virt[request_id];
error = 0;
if (full_command_packet->command.newcommand.status != 0) {
if (tw_dev->srb[request_id] != NULL) {
error = twa_fill_sense(tw_dev, request_id, 1, 1);
} else {
if (request_id != tw_dev->chrdev_request_id) {
error = twa_fill_sense(tw_dev, request_id, 0, 1);
}
}
}
if (tw_dev->state[request_id] != TW_S_POSTED) {
if (tw_dev->srb[request_id] != NULL) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x1a, "Received a request id that wasn't posted");
TW_CLEAR_ALL_INTERRUPTS(tw_dev);
goto twa_interrupt_bail;
}
}
if (tw_dev->srb[request_id] == NULL) {
if (request_id != tw_dev->chrdev_request_id) {
if (twa_aen_complete(tw_dev, request_id))
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x1b, "Error completing AEN during attention interrupt");
} else {
tw_dev->chrdev_request_id = TW_IOCTL_CHRDEV_FREE;
wake_up(&tw_dev->ioctl_wqueue);
}
} else {
struct scsi_cmnd *cmd;
cmd = tw_dev->srb[request_id];
twa_scsiop_execute_scsi_complete(tw_dev, request_id);
if (error == 0) {
cmd->result = (DID_OK << 16);
}
if (error == 1) {
cmd->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
}
if ((scsi_sg_count(cmd) <= 1) && (full_command_packet->command.newcommand.status == 0)) {
if (full_command_packet->command.newcommand.sg_list[0].length < scsi_bufflen(tw_dev->srb[request_id]))
scsi_set_resid(cmd, scsi_bufflen(cmd) - full_command_packet->command.newcommand.sg_list[0].length);
}
if (twa_command_mapped(cmd))
scsi_dma_unmap(cmd);
cmd->scsi_done(cmd);
tw_dev->state[request_id] = TW_S_COMPLETED;
twa_free_request_id(tw_dev, request_id);
tw_dev->posted_request_count--;
}
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
if (twa_check_bits(status_reg_value)) {
if (twa_decode_bits(tw_dev, status_reg_value)) {
TW_CLEAR_ALL_INTERRUPTS(tw_dev);
goto twa_interrupt_bail;
}
}
}
}
twa_interrupt_bail:
spin_unlock(tw_dev->host->host_lock);
return IRQ_RETVAL(handled);
}
static void twa_load_sgl(TW_Device_Extension *tw_dev, TW_Command_Full *full_command_packet, int request_id, dma_addr_t dma_handle, int length)
{
TW_Command *oldcommand;
TW_Command_Apache *newcommand;
TW_SG_Entry *sgl;
unsigned int pae = 0;
if ((sizeof(long) < 8) && (sizeof(dma_addr_t) > 4))
pae = 1;
if (TW_OP_OUT(full_command_packet->command.newcommand.opcode__reserved) == TW_OP_EXECUTE_SCSI) {
newcommand = &full_command_packet->command.newcommand;
newcommand->request_id__lunl =
cpu_to_le16(TW_REQ_LUN_IN(TW_LUN_OUT(newcommand->request_id__lunl), request_id));
if (length) {
newcommand->sg_list[0].address = TW_CPU_TO_SGL(dma_handle + sizeof(TW_Ioctl_Buf_Apache) - 1);
newcommand->sg_list[0].length = cpu_to_le32(length);
}
newcommand->sgl_entries__lunh =
cpu_to_le16(TW_REQ_LUN_IN(TW_LUN_OUT(newcommand->sgl_entries__lunh), length ? 1 : 0));
} else {
oldcommand = &full_command_packet->command.oldcommand;
oldcommand->request_id = request_id;
if (TW_SGL_OUT(oldcommand->opcode__sgloffset)) {
if (tw_dev->tw_pci_dev->device == PCI_DEVICE_ID_3WARE_9690SA)
sgl = (TW_SG_Entry *)((u32 *)oldcommand+oldcommand->size - (sizeof(TW_SG_Entry)/4) + pae);
else
sgl = (TW_SG_Entry *)((u32 *)oldcommand+TW_SGL_OUT(oldcommand->opcode__sgloffset));
sgl->address = TW_CPU_TO_SGL(dma_handle + sizeof(TW_Ioctl_Buf_Apache) - 1);
sgl->length = cpu_to_le32(length);
oldcommand->size += pae;
}
}
}
static int twa_poll_response(TW_Device_Extension *tw_dev, int request_id, int seconds)
{
int retval = 1, found = 0, response_request_id;
TW_Response_Queue response_queue;
TW_Command_Full *full_command_packet = tw_dev->command_packet_virt[request_id];
if (twa_poll_status_gone(tw_dev, TW_STATUS_RESPONSE_QUEUE_EMPTY, seconds) == 0) {
response_queue.value = readl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
response_request_id = TW_RESID_OUT(response_queue.response_id);
if (request_id != response_request_id) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x1e, "Found unexpected request id while polling for response");
goto out;
}
if (TW_OP_OUT(full_command_packet->command.newcommand.opcode__reserved) == TW_OP_EXECUTE_SCSI) {
if (full_command_packet->command.newcommand.status != 0) {
twa_fill_sense(tw_dev, request_id, 0, 0);
goto out;
}
found = 1;
} else {
if (full_command_packet->command.oldcommand.status != 0) {
twa_fill_sense(tw_dev, request_id, 0, 0);
goto out;
}
found = 1;
}
}
if (found)
retval = 0;
out:
return retval;
}
static int twa_poll_status(TW_Device_Extension *tw_dev, u32 flag, int seconds)
{
u32 status_reg_value;
unsigned long before;
int retval = 1;
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
before = jiffies;
if (twa_check_bits(status_reg_value))
twa_decode_bits(tw_dev, status_reg_value);
while ((status_reg_value & flag) != flag) {
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
if (twa_check_bits(status_reg_value))
twa_decode_bits(tw_dev, status_reg_value);
if (time_after(jiffies, before + HZ * seconds))
goto out;
msleep(50);
}
retval = 0;
out:
return retval;
}
static int twa_poll_status_gone(TW_Device_Extension *tw_dev, u32 flag, int seconds)
{
u32 status_reg_value;
unsigned long before;
int retval = 1;
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
before = jiffies;
if (twa_check_bits(status_reg_value))
twa_decode_bits(tw_dev, status_reg_value);
while ((status_reg_value & flag) != 0) {
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
if (twa_check_bits(status_reg_value))
twa_decode_bits(tw_dev, status_reg_value);
if (time_after(jiffies, before + HZ * seconds))
goto out;
msleep(50);
}
retval = 0;
out:
return retval;
}
static int twa_post_command_packet(TW_Device_Extension *tw_dev, int request_id, char internal)
{
u32 status_reg_value;
dma_addr_t command_que_value;
int retval = 1;
command_que_value = tw_dev->command_packet_phys[request_id];
if ((tw_dev->tw_pci_dev->device == PCI_DEVICE_ID_3WARE_9650SE) ||
(tw_dev->tw_pci_dev->device == PCI_DEVICE_ID_3WARE_9690SA)) {
command_que_value += TW_COMMAND_OFFSET;
writel((u32)command_que_value, TW_COMMAND_QUEUE_REG_ADDR_LARGE(tw_dev));
}
status_reg_value = readl(TW_STATUS_REG_ADDR(tw_dev));
if (twa_check_bits(status_reg_value))
twa_decode_bits(tw_dev, status_reg_value);
if (((tw_dev->pending_request_count > 0) && (tw_dev->state[request_id] != TW_S_PENDING)) || (status_reg_value & TW_STATUS_COMMAND_QUEUE_FULL)) {
if (!internal) {
retval = SCSI_MLQUEUE_HOST_BUSY;
goto out;
}
if (tw_dev->state[request_id] != TW_S_PENDING) {
tw_dev->state[request_id] = TW_S_PENDING;
tw_dev->pending_request_count++;
if (tw_dev->pending_request_count > tw_dev->max_pending_request_count) {
tw_dev->max_pending_request_count = tw_dev->pending_request_count;
}
tw_dev->pending_queue[tw_dev->pending_tail] = request_id;
tw_dev->pending_tail = (tw_dev->pending_tail + 1) % TW_Q_LENGTH;
}
TW_UNMASK_COMMAND_INTERRUPT(tw_dev);
goto out;
} else {
if ((tw_dev->tw_pci_dev->device == PCI_DEVICE_ID_3WARE_9650SE) ||
(tw_dev->tw_pci_dev->device == PCI_DEVICE_ID_3WARE_9690SA)) {
writel((u32)((u64)command_que_value >> 32), TW_COMMAND_QUEUE_REG_ADDR_LARGE(tw_dev) + 0x4);
} else {
if (sizeof(dma_addr_t) > 4) {
command_que_value += TW_COMMAND_OFFSET;
writel((u32)command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
writel((u32)((u64)command_que_value >> 32), TW_COMMAND_QUEUE_REG_ADDR(tw_dev) + 0x4);
} else {
writel(TW_COMMAND_OFFSET + command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
}
}
tw_dev->state[request_id] = TW_S_POSTED;
tw_dev->posted_request_count++;
if (tw_dev->posted_request_count > tw_dev->max_posted_request_count) {
tw_dev->max_posted_request_count = tw_dev->posted_request_count;
}
}
retval = 0;
out:
return retval;
}
static int twa_reset_device_extension(TW_Device_Extension *tw_dev)
{
int i = 0;
int retval = 1;
unsigned long flags = 0;
set_bit(TW_IN_RESET, &tw_dev->flags);
TW_DISABLE_INTERRUPTS(tw_dev);
TW_MASK_COMMAND_INTERRUPT(tw_dev);
spin_lock_irqsave(tw_dev->host->host_lock, flags);
for (i = 0; i < TW_Q_LENGTH; i++) {
if ((tw_dev->state[i] != TW_S_FINISHED) &&
(tw_dev->state[i] != TW_S_INITIAL) &&
(tw_dev->state[i] != TW_S_COMPLETED)) {
if (tw_dev->srb[i]) {
struct scsi_cmnd *cmd = tw_dev->srb[i];
cmd->result = (DID_RESET << 16);
if (twa_command_mapped(cmd))
scsi_dma_unmap(cmd);
cmd->scsi_done(cmd);
}
}
}
for (i = 0; i < TW_Q_LENGTH; i++) {
tw_dev->free_queue[i] = i;
tw_dev->state[i] = TW_S_INITIAL;
}
tw_dev->free_head = TW_Q_START;
tw_dev->free_tail = TW_Q_START;
tw_dev->posted_request_count = 0;
tw_dev->pending_request_count = 0;
tw_dev->pending_head = TW_Q_START;
tw_dev->pending_tail = TW_Q_START;
tw_dev->reset_print = 0;
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
if (twa_reset_sequence(tw_dev, 1))
goto out;
TW_ENABLE_AND_CLEAR_INTERRUPTS(tw_dev);
clear_bit(TW_IN_RESET, &tw_dev->flags);
tw_dev->chrdev_request_id = TW_IOCTL_CHRDEV_FREE;
retval = 0;
out:
return retval;
}
static int twa_reset_sequence(TW_Device_Extension *tw_dev, int soft_reset)
{
int tries = 0, retval = 1, flashed = 0, do_soft_reset = soft_reset;
while (tries < TW_MAX_RESET_TRIES) {
if (do_soft_reset) {
TW_SOFT_RESET(tw_dev);
if (twa_empty_response_queue_large(tw_dev)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x36, "Response queue (large) empty failed during reset sequence");
do_soft_reset = 1;
tries++;
continue;
}
}
if (twa_poll_status(tw_dev, TW_STATUS_MICROCONTROLLER_READY | (do_soft_reset == 1 ? TW_STATUS_ATTENTION_INTERRUPT : 0), 60)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x1f, "Microcontroller not ready during reset sequence");
do_soft_reset = 1;
tries++;
continue;
}
if (twa_empty_response_queue(tw_dev)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x20, "Response queue empty failed during reset sequence");
do_soft_reset = 1;
tries++;
continue;
}
flashed = 0;
if (twa_check_srl(tw_dev, &flashed)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x21, "Compatibility check failed during reset sequence");
do_soft_reset = 1;
tries++;
continue;
} else {
if (flashed) {
tries++;
continue;
}
}
if (twa_aen_drain_queue(tw_dev, soft_reset)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x22, "AEN drain failed during reset sequence");
do_soft_reset = 1;
tries++;
continue;
}
retval = 0;
goto out;
}
out:
return retval;
}
static int twa_scsi_biosparam(struct scsi_device *sdev, struct block_device *bdev, sector_t capacity, int geom[])
{
int heads, sectors, cylinders;
TW_Device_Extension *tw_dev;
tw_dev = (TW_Device_Extension *)sdev->host->hostdata;
if (capacity >= 0x200000) {
heads = 255;
sectors = 63;
cylinders = sector_div(capacity, heads * sectors);
} else {
heads = 64;
sectors = 32;
cylinders = sector_div(capacity, heads * sectors);
}
geom[0] = heads;
geom[1] = sectors;
geom[2] = cylinders;
return 0;
}
static int twa_scsi_eh_reset(struct scsi_cmnd *SCpnt)
{
TW_Device_Extension *tw_dev = NULL;
int retval = FAILED;
tw_dev = (TW_Device_Extension *)SCpnt->device->host->hostdata;
tw_dev->num_resets++;
sdev_printk(KERN_WARNING, SCpnt->device,
"WARNING: (0x%02X:0x%04X): Command (0x%x) timed out, resetting card.\n",
TW_DRIVER, 0x2c, SCpnt->cmnd[0]);
mutex_lock(&tw_dev->ioctl_lock);
if (twa_reset_device_extension(tw_dev)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x2b, "Controller reset failed during scsi host reset");
goto out;
}
retval = SUCCESS;
out:
mutex_unlock(&tw_dev->ioctl_lock);
return retval;
}
static int twa_scsi_queue_lck(struct scsi_cmnd *SCpnt, void (*done)(struct scsi_cmnd *))
{
int request_id, retval;
TW_Device_Extension *tw_dev = (TW_Device_Extension *)SCpnt->device->host->hostdata;
if (test_bit(TW_IN_RESET, &tw_dev->flags)) {
retval = SCSI_MLQUEUE_HOST_BUSY;
goto out;
}
if ((SCpnt->device->lun != 0) && (tw_dev->tw_compat_info.working_srl < TW_FW_SRL_LUNS_SUPPORTED)) {
SCpnt->result = (DID_BAD_TARGET << 16);
done(SCpnt);
retval = 0;
goto out;
}
SCpnt->scsi_done = done;
twa_get_request_id(tw_dev, &request_id);
tw_dev->srb[request_id] = SCpnt;
retval = twa_scsiop_execute_scsi(tw_dev, request_id, NULL, 0, NULL);
switch (retval) {
case SCSI_MLQUEUE_HOST_BUSY:
if (twa_command_mapped(SCpnt))
scsi_dma_unmap(SCpnt);
twa_free_request_id(tw_dev, request_id);
break;
case 1:
SCpnt->result = (DID_ERROR << 16);
if (twa_command_mapped(SCpnt))
scsi_dma_unmap(SCpnt);
done(SCpnt);
tw_dev->state[request_id] = TW_S_COMPLETED;
twa_free_request_id(tw_dev, request_id);
retval = 0;
}
out:
return retval;
}
void twa_scsiop_execute_scsi_complete(TW_Device_Extension *tw_dev, int request_id)
{
struct scsi_cmnd *cmd = tw_dev->srb[request_id];
if (!twa_command_mapped(cmd) &&
(cmd->sc_data_direction == DMA_FROM_DEVICE ||
cmd->sc_data_direction == DMA_BIDIRECTIONAL)) {
if (scsi_sg_count(cmd) == 1) {
void *buf = tw_dev->generic_buffer_virt[request_id];
scsi_sg_copy_from_buffer(cmd, buf, TW_SECTOR_SIZE);
}
}
}
static void __twa_shutdown(TW_Device_Extension *tw_dev)
{
TW_DISABLE_INTERRUPTS(tw_dev);
free_irq(tw_dev->tw_pci_dev->irq, tw_dev);
printk(KERN_WARNING "3w-9xxx: Shutting down host %d.\n", tw_dev->host->host_no);
if (twa_initconnection(tw_dev, 1, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x31, "Connection shutdown failed");
} else {
printk(KERN_WARNING "3w-9xxx: Shutdown complete.\n");
}
TW_CLEAR_ALL_INTERRUPTS(tw_dev);
}
static void twa_shutdown(struct pci_dev *pdev)
{
struct Scsi_Host *host = pci_get_drvdata(pdev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
__twa_shutdown(tw_dev);
}
static char *twa_string_lookup(twa_message_type *table, unsigned int code)
{
int index;
for (index = 0; ((code != table[index].code) &&
(table[index].text != (char *)0)); index++);
return(table[index].text);
}
static int twa_slave_configure(struct scsi_device *sdev)
{
blk_queue_rq_timeout(sdev->request_queue, 60 * HZ);
return 0;
}
static int twa_probe(struct pci_dev *pdev, const struct pci_device_id *dev_id)
{
struct Scsi_Host *host = NULL;
TW_Device_Extension *tw_dev;
unsigned long mem_addr, mem_len;
int retval = -ENODEV;
retval = pci_enable_device(pdev);
if (retval) {
TW_PRINTK(host, TW_DRIVER, 0x34, "Failed to enable pci device");
goto out_disable_device;
}
pci_set_master(pdev);
pci_try_set_mwi(pdev);
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64))
|| pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)))
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))
|| pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32))) {
TW_PRINTK(host, TW_DRIVER, 0x23, "Failed to set dma mask");
retval = -ENODEV;
goto out_disable_device;
}
host = scsi_host_alloc(&driver_template, sizeof(TW_Device_Extension));
if (!host) {
TW_PRINTK(host, TW_DRIVER, 0x24, "Failed to allocate memory for device extension");
retval = -ENOMEM;
goto out_disable_device;
}
tw_dev = (TW_Device_Extension *)host->hostdata;
tw_dev->host = host;
tw_dev->tw_pci_dev = pdev;
if (twa_initialize_device_extension(tw_dev)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x25, "Failed to initialize device extension");
goto out_free_device_extension;
}
retval = pci_request_regions(pdev, "3w-9xxx");
if (retval) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x26, "Failed to get mem region");
goto out_free_device_extension;
}
if (pdev->device == PCI_DEVICE_ID_3WARE_9000) {
mem_addr = pci_resource_start(pdev, 1);
mem_len = pci_resource_len(pdev, 1);
} else {
mem_addr = pci_resource_start(pdev, 2);
mem_len = pci_resource_len(pdev, 2);
}
tw_dev->base_addr = ioremap(mem_addr, mem_len);
if (!tw_dev->base_addr) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x35, "Failed to ioremap");
goto out_release_mem_region;
}
TW_DISABLE_INTERRUPTS(tw_dev);
if (twa_reset_sequence(tw_dev, 0))
goto out_iounmap;
if ((pdev->device == PCI_DEVICE_ID_3WARE_9650SE) ||
(pdev->device == PCI_DEVICE_ID_3WARE_9690SA))
host->max_id = TW_MAX_UNITS_9650SE;
else
host->max_id = TW_MAX_UNITS;
host->max_cmd_len = TW_MAX_CDB_LEN;
host->max_lun = TW_MAX_LUNS(tw_dev->tw_compat_info.working_srl);
host->max_channel = 0;
retval = scsi_add_host(host, &pdev->dev);
if (retval) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x27, "scsi add host failed");
goto out_iounmap;
}
pci_set_drvdata(pdev, host);
printk(KERN_WARNING "3w-9xxx: scsi%d: Found a 3ware 9000 Storage Controller at 0x%lx, IRQ: %d.\n",
host->host_no, mem_addr, pdev->irq);
printk(KERN_WARNING "3w-9xxx: scsi%d: Firmware %s, BIOS %s, Ports: %d.\n",
host->host_no,
(char *)twa_get_param(tw_dev, 0, TW_VERSION_TABLE,
TW_PARAM_FWVER, TW_PARAM_FWVER_LENGTH),
(char *)twa_get_param(tw_dev, 1, TW_VERSION_TABLE,
TW_PARAM_BIOSVER, TW_PARAM_BIOSVER_LENGTH),
le32_to_cpu(*(int *)twa_get_param(tw_dev, 2, TW_INFORMATION_TABLE,
TW_PARAM_PORTCOUNT, TW_PARAM_PORTCOUNT_LENGTH)));
if (use_msi && (pdev->device != PCI_DEVICE_ID_3WARE_9000) &&
!pci_enable_msi(pdev))
set_bit(TW_USING_MSI, &tw_dev->flags);
retval = request_irq(pdev->irq, twa_interrupt, IRQF_SHARED, "3w-9xxx", tw_dev);
if (retval) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x30, "Error requesting IRQ");
goto out_remove_host;
}
twa_device_extension_list[twa_device_extension_count] = tw_dev;
twa_device_extension_count++;
TW_ENABLE_AND_CLEAR_INTERRUPTS(tw_dev);
scsi_scan_host(host);
if (twa_major == -1) {
if ((twa_major = register_chrdev (0, "twa", &twa_fops)) < 0)
TW_PRINTK(host, TW_DRIVER, 0x29, "Failed to register character device");
}
return 0;
out_remove_host:
if (test_bit(TW_USING_MSI, &tw_dev->flags))
pci_disable_msi(pdev);
scsi_remove_host(host);
out_iounmap:
iounmap(tw_dev->base_addr);
out_release_mem_region:
pci_release_regions(pdev);
out_free_device_extension:
twa_free_device_extension(tw_dev);
scsi_host_put(host);
out_disable_device:
pci_disable_device(pdev);
return retval;
}
static void twa_remove(struct pci_dev *pdev)
{
struct Scsi_Host *host = pci_get_drvdata(pdev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
scsi_remove_host(tw_dev->host);
if (twa_major >= 0) {
unregister_chrdev(twa_major, "twa");
twa_major = -1;
}
__twa_shutdown(tw_dev);
if (test_bit(TW_USING_MSI, &tw_dev->flags))
pci_disable_msi(pdev);
iounmap(tw_dev->base_addr);
pci_release_regions(pdev);
twa_free_device_extension(tw_dev);
scsi_host_put(tw_dev->host);
pci_disable_device(pdev);
twa_device_extension_count--;
}
static int twa_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct Scsi_Host *host = pci_get_drvdata(pdev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
printk(KERN_WARNING "3w-9xxx: Suspending host %d.\n", tw_dev->host->host_no);
TW_DISABLE_INTERRUPTS(tw_dev);
free_irq(tw_dev->tw_pci_dev->irq, tw_dev);
if (test_bit(TW_USING_MSI, &tw_dev->flags))
pci_disable_msi(pdev);
if (twa_initconnection(tw_dev, 1, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL)) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x38, "Connection shutdown failed during suspend");
} else {
printk(KERN_WARNING "3w-9xxx: Suspend complete.\n");
}
TW_CLEAR_ALL_INTERRUPTS(tw_dev);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int twa_resume(struct pci_dev *pdev)
{
int retval = 0;
struct Scsi_Host *host = pci_get_drvdata(pdev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
printk(KERN_WARNING "3w-9xxx: Resuming host %d.\n", tw_dev->host->host_no);
pci_set_power_state(pdev, PCI_D0);
pci_enable_wake(pdev, PCI_D0, 0);
pci_restore_state(pdev);
retval = pci_enable_device(pdev);
if (retval) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x39, "Enable device failed during resume");
return retval;
}
pci_set_master(pdev);
pci_try_set_mwi(pdev);
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64))
|| pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)))
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))
|| pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32))) {
TW_PRINTK(host, TW_DRIVER, 0x40, "Failed to set dma mask during resume");
retval = -ENODEV;
goto out_disable_device;
}
if (twa_reset_sequence(tw_dev, 0)) {
retval = -ENODEV;
goto out_disable_device;
}
retval = request_irq(pdev->irq, twa_interrupt, IRQF_SHARED, "3w-9xxx", tw_dev);
if (retval) {
TW_PRINTK(tw_dev->host, TW_DRIVER, 0x42, "Error requesting IRQ during resume");
retval = -ENODEV;
goto out_disable_device;
}
if (test_bit(TW_USING_MSI, &tw_dev->flags))
pci_enable_msi(pdev);
TW_ENABLE_AND_CLEAR_INTERRUPTS(tw_dev);
printk(KERN_WARNING "3w-9xxx: Resume complete.\n");
return 0;
out_disable_device:
scsi_remove_host(host);
pci_disable_device(pdev);
return retval;
}
static int __init twa_init(void)
{
printk(KERN_WARNING "3ware 9000 Storage Controller device driver for Linux v%s.\n", TW_DRIVER_VERSION);
return pci_register_driver(&twa_driver);
}
static void __exit twa_exit(void)
{
pci_unregister_driver(&twa_driver);
}
