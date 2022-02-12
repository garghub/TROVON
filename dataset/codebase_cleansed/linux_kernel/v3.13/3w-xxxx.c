static int tw_check_bits(u32 status_reg_value)
{
if ((status_reg_value & TW_STATUS_EXPECTED_BITS) != TW_STATUS_EXPECTED_BITS) {
dprintk(KERN_WARNING "3w-xxxx: tw_check_bits(): No expected bits (0x%x).\n", status_reg_value);
return 1;
}
if ((status_reg_value & TW_STATUS_UNEXPECTED_BITS) != 0) {
dprintk(KERN_WARNING "3w-xxxx: tw_check_bits(): Found unexpected bits (0x%x).\n", status_reg_value);
return 1;
}
return 0;
}
static int tw_decode_bits(TW_Device_Extension *tw_dev, u32 status_reg_value, int print_host)
{
char host[16];
dprintk(KERN_WARNING "3w-xxxx: tw_decode_bits()\n");
if (print_host)
sprintf(host, " scsi%d:", tw_dev->host->host_no);
else
host[0] = '\0';
if (status_reg_value & TW_STATUS_PCI_PARITY_ERROR) {
printk(KERN_WARNING "3w-xxxx:%s PCI Parity Error: clearing.\n", host);
outl(TW_CONTROL_CLEAR_PARITY_ERROR, TW_CONTROL_REG_ADDR(tw_dev));
}
if (status_reg_value & TW_STATUS_PCI_ABORT) {
printk(KERN_WARNING "3w-xxxx:%s PCI Abort: clearing.\n", host);
outl(TW_CONTROL_CLEAR_PCI_ABORT, TW_CONTROL_REG_ADDR(tw_dev));
pci_write_config_word(tw_dev->tw_pci_dev, PCI_STATUS, TW_PCI_CLEAR_PCI_ABORT);
}
if (status_reg_value & TW_STATUS_QUEUE_ERROR) {
printk(KERN_WARNING "3w-xxxx:%s Controller Queue Error: clearing.\n", host);
outl(TW_CONTROL_CLEAR_QUEUE_ERROR, TW_CONTROL_REG_ADDR(tw_dev));
}
if (status_reg_value & TW_STATUS_SBUF_WRITE_ERROR) {
printk(KERN_WARNING "3w-xxxx:%s SBUF Write Error: clearing.\n", host);
outl(TW_CONTROL_CLEAR_SBUF_WRITE_ERROR, TW_CONTROL_REG_ADDR(tw_dev));
}
if (status_reg_value & TW_STATUS_MICROCONTROLLER_ERROR) {
if (tw_dev->reset_print == 0) {
printk(KERN_WARNING "3w-xxxx:%s Microcontroller Error: clearing.\n", host);
tw_dev->reset_print = 1;
}
return 1;
}
return 0;
}
static int tw_poll_status(TW_Device_Extension *tw_dev, u32 flag, int seconds)
{
u32 status_reg_value;
unsigned long before;
int retval = 1;
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
before = jiffies;
if (tw_check_bits(status_reg_value))
tw_decode_bits(tw_dev, status_reg_value, 0);
while ((status_reg_value & flag) != flag) {
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
if (tw_check_bits(status_reg_value))
tw_decode_bits(tw_dev, status_reg_value, 0);
if (time_after(jiffies, before + HZ * seconds))
goto out;
msleep(50);
}
retval = 0;
out:
return retval;
}
static int tw_poll_status_gone(TW_Device_Extension *tw_dev, u32 flag, int seconds)
{
u32 status_reg_value;
unsigned long before;
int retval = 1;
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
before = jiffies;
if (tw_check_bits(status_reg_value))
tw_decode_bits(tw_dev, status_reg_value, 0);
while ((status_reg_value & flag) != 0) {
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
if (tw_check_bits(status_reg_value))
tw_decode_bits(tw_dev, status_reg_value, 0);
if (time_after(jiffies, before + HZ * seconds))
goto out;
msleep(50);
}
retval = 0;
out:
return retval;
}
static int tw_post_command_packet(TW_Device_Extension *tw_dev, int request_id)
{
u32 status_reg_value;
unsigned long command_que_value;
dprintk(KERN_NOTICE "3w-xxxx: tw_post_command_packet()\n");
command_que_value = tw_dev->command_packet_physical_address[request_id];
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
if (tw_check_bits(status_reg_value)) {
dprintk(KERN_WARNING "3w-xxxx: tw_post_command_packet(): Unexpected bits.\n");
tw_decode_bits(tw_dev, status_reg_value, 1);
}
if ((status_reg_value & TW_STATUS_COMMAND_QUEUE_FULL) == 0) {
outl(command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
tw_dev->state[request_id] = TW_S_POSTED;
tw_dev->posted_request_count++;
if (tw_dev->posted_request_count > tw_dev->max_posted_request_count) {
tw_dev->max_posted_request_count = tw_dev->posted_request_count;
}
} else {
if (tw_dev->state[request_id] != TW_S_PENDING) {
tw_dev->state[request_id] = TW_S_PENDING;
tw_dev->pending_request_count++;
if (tw_dev->pending_request_count > tw_dev->max_pending_request_count) {
tw_dev->max_pending_request_count = tw_dev->pending_request_count;
}
tw_dev->pending_queue[tw_dev->pending_tail] = request_id;
if (tw_dev->pending_tail == TW_Q_LENGTH-1) {
tw_dev->pending_tail = TW_Q_START;
} else {
tw_dev->pending_tail = tw_dev->pending_tail + 1;
}
}
TW_UNMASK_COMMAND_INTERRUPT(tw_dev);
return 1;
}
return 0;
}
static int tw_decode_sense(TW_Device_Extension *tw_dev, int request_id, int fill_sense)
{
int i;
TW_Command *command;
dprintk(KERN_WARNING "3w-xxxx: tw_decode_sense()\n");
command = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
printk(KERN_WARNING "3w-xxxx: scsi%d: Command failed: status = 0x%x, flags = 0x%x, unit #%d.\n", tw_dev->host->host_no, command->status, command->flags, TW_UNIT_OUT(command->unit__hostid));
if (fill_sense) {
if ((command->status == 0xc7) || (command->status == 0xcb)) {
for (i = 0; i < ARRAY_SIZE(tw_sense_table); i++) {
if (command->flags == tw_sense_table[i][0]) {
tw_dev->srb[request_id]->sense_buffer[0] = (0x1 << 7 | 0x70);
tw_dev->srb[request_id]->sense_buffer[2] = tw_sense_table[i][1];
tw_dev->srb[request_id]->sense_buffer[7] = 0xa;
tw_dev->srb[request_id]->sense_buffer[12] = tw_sense_table[i][2];
tw_dev->srb[request_id]->sense_buffer[13] = tw_sense_table[i][3];
tw_dev->srb[request_id]->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
return TW_ISR_DONT_RESULT;
}
}
}
return 1;
}
return 0;
}
static int tw_check_errors(TW_Device_Extension *tw_dev)
{
u32 status_reg_value;
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
if (TW_STATUS_ERRORS(status_reg_value) || tw_check_bits(status_reg_value)) {
tw_decode_bits(tw_dev, status_reg_value, 0);
return 1;
}
return 0;
}
static void tw_empty_response_que(TW_Device_Extension *tw_dev)
{
u32 status_reg_value, response_que_value;
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
while ((status_reg_value & TW_STATUS_RESPONSE_QUEUE_EMPTY) == 0) {
response_que_value = inl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
}
}
static void tw_state_request_finish(TW_Device_Extension *tw_dev, int request_id)
{
tw_dev->free_queue[tw_dev->free_tail] = request_id;
tw_dev->state[request_id] = TW_S_FINISHED;
tw_dev->free_tail = (tw_dev->free_tail + 1) % TW_Q_LENGTH;
}
static void tw_state_request_start(TW_Device_Extension *tw_dev, int *request_id)
{
*request_id = tw_dev->free_queue[tw_dev->free_head];
tw_dev->free_head = (tw_dev->free_head + 1) % TW_Q_LENGTH;
tw_dev->state[*request_id] = TW_S_STARTED;
}
static ssize_t tw_show_stats(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
unsigned long flags = 0;
ssize_t len;
spin_lock_irqsave(tw_dev->host->host_lock, flags);
len = snprintf(buf, PAGE_SIZE, "3w-xxxx Driver version: %s\n"
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
static int tw_change_queue_depth(struct scsi_device *sdev, int queue_depth,
int reason)
{
if (reason != SCSI_QDEPTH_DEFAULT)
return -EOPNOTSUPP;
if (queue_depth > TW_Q_LENGTH-2)
queue_depth = TW_Q_LENGTH-2;
scsi_adjust_queue_depth(sdev, MSG_ORDERED_TAG, queue_depth);
return queue_depth;
}
static int tw_aen_read_queue(TW_Device_Extension *tw_dev, int request_id)
{
TW_Command *command_packet;
TW_Param *param;
unsigned long command_que_value;
u32 status_reg_value;
unsigned long param_value = 0;
dprintk(KERN_NOTICE "3w-xxxx: tw_aen_read_queue()\n");
status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
if (tw_check_bits(status_reg_value)) {
dprintk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Unexpected bits.\n");
tw_decode_bits(tw_dev, status_reg_value, 1);
return 1;
}
if (tw_dev->command_packet_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Bad command packet virtual address.\n");
return 1;
}
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.parameter_count = 1;
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Bad command packet physical address.\n");
return 1;
}
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
memset(param, 0, sizeof(TW_Sector));
param->table_id = 0x401;
param->parameter_id = 2;
param->parameter_size_bytes = 2;
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Bad alignment physical address.\n");
return 1;
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
if ((status_reg_value & TW_STATUS_COMMAND_QUEUE_FULL) == 0) {
dprintk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Post succeeded.\n");
tw_dev->srb[request_id] = NULL;
tw_dev->state[request_id] = TW_S_POSTED;
outl(command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
} else {
printk(KERN_WARNING "3w-xxxx: tw_aen_read_queue(): Post failed, will retry.\n");
return 1;
}
return 0;
}
static int tw_aen_complete(TW_Device_Extension *tw_dev, int request_id)
{
TW_Param *param;
unsigned short aen;
int error = 0, table_max = 0;
dprintk(KERN_WARNING "3w-xxxx: tw_aen_complete()\n");
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_aen_complete(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
aen = *(unsigned short *)(param->data);
dprintk(KERN_NOTICE "3w-xxxx: tw_aen_complete(): Queue'd code 0x%x\n", aen);
if (aen == 0x0ff) {
printk(KERN_WARNING "3w-xxxx: scsi%d: AEN: INFO: AEN queue overflow.\n", tw_dev->host->host_no);
} else {
table_max = ARRAY_SIZE(tw_aen_string);
if ((aen & 0x0ff) < table_max) {
if ((tw_aen_string[aen & 0xff][strlen(tw_aen_string[aen & 0xff])-1]) == '#') {
printk(KERN_WARNING "3w-xxxx: scsi%d: AEN: %s%d.\n", tw_dev->host->host_no, tw_aen_string[aen & 0xff], aen >> 8);
} else {
if (aen != 0x0)
printk(KERN_WARNING "3w-xxxx: scsi%d: AEN: %s.\n", tw_dev->host->host_no, tw_aen_string[aen & 0xff]);
}
} else {
printk(KERN_WARNING "3w-xxxx: scsi%d: Received AEN %d.\n", tw_dev->host->host_no, aen);
}
}
if (aen != TW_AEN_QUEUE_EMPTY) {
tw_dev->aen_count++;
tw_dev->aen_queue[tw_dev->aen_tail] = aen;
if (tw_dev->aen_tail == TW_Q_LENGTH - 1) {
tw_dev->aen_tail = TW_Q_START;
} else {
tw_dev->aen_tail = tw_dev->aen_tail + 1;
}
if (tw_dev->aen_head == tw_dev->aen_tail) {
if (tw_dev->aen_head == TW_Q_LENGTH - 1) {
tw_dev->aen_head = TW_Q_START;
} else {
tw_dev->aen_head = tw_dev->aen_head + 1;
}
}
error = tw_aen_read_queue(tw_dev, request_id);
if (error) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Error completing AEN.\n", tw_dev->host->host_no);
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
}
} else {
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
}
return 0;
}
static int tw_aen_drain_queue(TW_Device_Extension *tw_dev)
{
TW_Command *command_packet;
TW_Param *param;
int request_id = 0;
unsigned long command_que_value;
unsigned long param_value;
TW_Response_Queue response_queue;
unsigned short aen;
unsigned short aen_code;
int finished = 0;
int first_reset = 0;
int queue = 0;
int found = 0, table_max = 0;
dprintk(KERN_NOTICE "3w-xxxx: tw_aen_drain_queue()\n");
if (tw_poll_status(tw_dev, TW_STATUS_ATTENTION_INTERRUPT | TW_STATUS_MICROCONTROLLER_READY, 30)) {
dprintk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): No attention interrupt for card %d.\n", tw_device_extension_count);
return 1;
}
TW_CLEAR_ATTENTION_INTERRUPT(tw_dev);
tw_empty_response_que(tw_dev);
if (tw_dev->command_packet_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): Bad command packet virtual address.\n");
return 1;
}
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.parameter_count = 1;
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): Bad command packet physical address.\n");
return 1;
}
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
memset(param, 0, sizeof(TW_Sector));
param->table_id = 0x401;
param->parameter_id = 2;
param->parameter_size_bytes = 2;
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): Bad alignment physical address.\n");
return 1;
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
do {
outl(command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
if (tw_poll_status_gone(tw_dev, TW_STATUS_RESPONSE_QUEUE_EMPTY, 30) == 0) {
response_queue.value = inl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
request_id = TW_RESID_OUT(response_queue.response_id);
if (request_id != 0) {
printk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): Unexpected request id.\n");
return 1;
}
if (command_packet->status != 0) {
if (command_packet->flags != TW_AEN_TABLE_UNDEFINED) {
tw_decode_sense(tw_dev, request_id, 0);
return 1;
} else {
return 0;
}
}
aen = *(unsigned short *)(param->data);
aen_code = (aen & 0x0ff);
queue = 0;
switch (aen_code) {
case TW_AEN_QUEUE_EMPTY:
dprintk(KERN_WARNING "3w-xxxx: AEN: %s.\n", tw_aen_string[aen & 0xff]);
if (first_reset != 1) {
return 1;
} else {
finished = 1;
}
break;
case TW_AEN_SOFT_RESET:
if (first_reset == 0) {
first_reset = 1;
} else {
printk(KERN_WARNING "3w-xxxx: AEN: %s.\n", tw_aen_string[aen & 0xff]);
tw_dev->aen_count++;
queue = 1;
}
break;
default:
if (aen == 0x0ff) {
printk(KERN_WARNING "3w-xxxx: AEN: INFO: AEN queue overflow.\n");
} else {
table_max = ARRAY_SIZE(tw_aen_string);
if ((aen & 0x0ff) < table_max) {
if ((tw_aen_string[aen & 0xff][strlen(tw_aen_string[aen & 0xff])-1]) == '#') {
printk(KERN_WARNING "3w-xxxx: AEN: %s%d.\n", tw_aen_string[aen & 0xff], aen >> 8);
} else {
printk(KERN_WARNING "3w-xxxx: AEN: %s.\n", tw_aen_string[aen & 0xff]);
}
} else
printk(KERN_WARNING "3w-xxxx: Received AEN %d.\n", aen);
}
tw_dev->aen_count++;
queue = 1;
}
if (queue == 1) {
tw_dev->aen_queue[tw_dev->aen_tail] = aen;
if (tw_dev->aen_tail == TW_Q_LENGTH - 1) {
tw_dev->aen_tail = TW_Q_START;
} else {
tw_dev->aen_tail = tw_dev->aen_tail + 1;
}
if (tw_dev->aen_head == tw_dev->aen_tail) {
if (tw_dev->aen_head == TW_Q_LENGTH - 1) {
tw_dev->aen_head = TW_Q_START;
} else {
tw_dev->aen_head = tw_dev->aen_head + 1;
}
}
}
found = 1;
}
if (found == 0) {
printk(KERN_WARNING "3w-xxxx: tw_aen_drain_queue(): Response never received.\n");
return 1;
}
} while (finished == 0);
return 0;
}
static int tw_allocate_memory(TW_Device_Extension *tw_dev, int size, int which)
{
int i;
dma_addr_t dma_handle;
unsigned long *cpu_addr = NULL;
dprintk(KERN_NOTICE "3w-xxxx: tw_allocate_memory()\n");
cpu_addr = pci_alloc_consistent(tw_dev->tw_pci_dev, size*TW_Q_LENGTH, &dma_handle);
if (cpu_addr == NULL) {
printk(KERN_WARNING "3w-xxxx: pci_alloc_consistent() failed.\n");
return 1;
}
if ((unsigned long)cpu_addr % (tw_dev->tw_pci_dev->device == TW_DEVICE_ID ? TW_ALIGNMENT_6000 : TW_ALIGNMENT_7000)) {
printk(KERN_WARNING "3w-xxxx: Couldn't allocate correctly aligned memory.\n");
pci_free_consistent(tw_dev->tw_pci_dev, size*TW_Q_LENGTH, cpu_addr, dma_handle);
return 1;
}
memset(cpu_addr, 0, size*TW_Q_LENGTH);
for (i=0;i<TW_Q_LENGTH;i++) {
switch(which) {
case 0:
tw_dev->command_packet_physical_address[i] = dma_handle+(i*size);
tw_dev->command_packet_virtual_address[i] = (unsigned long *)((unsigned char *)cpu_addr + (i*size));
break;
case 1:
tw_dev->alignment_physical_address[i] = dma_handle+(i*size);
tw_dev->alignment_virtual_address[i] = (unsigned long *)((unsigned char *)cpu_addr + (i*size));
break;
default:
printk(KERN_WARNING "3w-xxxx: tw_allocate_memory(): case slip in tw_allocate_memory()\n");
return 1;
}
}
return 0;
}
static long tw_chrdev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int request_id;
dma_addr_t dma_handle;
unsigned short tw_aen_code;
unsigned long flags;
unsigned int data_buffer_length = 0;
unsigned long data_buffer_length_adjusted = 0;
struct inode *inode = file_inode(file);
unsigned long *cpu_addr;
long timeout;
TW_New_Ioctl *tw_ioctl;
TW_Passthru *passthru;
TW_Device_Extension *tw_dev = tw_device_extension_list[iminor(inode)];
int retval = -EFAULT;
void __user *argp = (void __user *)arg;
dprintk(KERN_WARNING "3w-xxxx: tw_chrdev_ioctl()\n");
mutex_lock(&tw_mutex);
if (mutex_lock_interruptible(&tw_dev->ioctl_lock)) {
mutex_unlock(&tw_mutex);
return -EINTR;
}
if (copy_from_user(&data_buffer_length, argp, sizeof(unsigned int)))
goto out;
if (data_buffer_length > TW_MAX_IOCTL_SECTORS * 512) {
retval = -EINVAL;
goto out;
}
data_buffer_length_adjusted = (data_buffer_length + 511) & ~511;
cpu_addr = dma_alloc_coherent(&tw_dev->tw_pci_dev->dev, data_buffer_length_adjusted+sizeof(TW_New_Ioctl) - 1, &dma_handle, GFP_KERNEL);
if (cpu_addr == NULL) {
retval = -ENOMEM;
goto out;
}
tw_ioctl = (TW_New_Ioctl *)cpu_addr;
if (copy_from_user(tw_ioctl, argp, data_buffer_length + sizeof(TW_New_Ioctl) - 1))
goto out2;
passthru = (TW_Passthru *)&tw_ioctl->firmware_command;
switch (cmd) {
case TW_OP_NOP:
dprintk(KERN_WARNING "3w-xxxx: tw_chrdev_ioctl(): caught TW_OP_NOP.\n");
break;
case TW_OP_AEN_LISTEN:
dprintk(KERN_WARNING "3w-xxxx: tw_chrdev_ioctl(): caught TW_AEN_LISTEN.\n");
memset(tw_ioctl->data_buffer, 0, data_buffer_length);
spin_lock_irqsave(tw_dev->host->host_lock, flags);
if (tw_dev->aen_head == tw_dev->aen_tail) {
tw_aen_code = TW_AEN_QUEUE_EMPTY;
} else {
tw_aen_code = tw_dev->aen_queue[tw_dev->aen_head];
if (tw_dev->aen_head == TW_Q_LENGTH - 1) {
tw_dev->aen_head = TW_Q_START;
} else {
tw_dev->aen_head = tw_dev->aen_head + 1;
}
}
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
memcpy(tw_ioctl->data_buffer, &tw_aen_code, sizeof(tw_aen_code));
break;
case TW_CMD_PACKET_WITH_DATA:
dprintk(KERN_WARNING "3w-xxxx: tw_chrdev_ioctl(): caught TW_CMD_PACKET_WITH_DATA.\n");
spin_lock_irqsave(tw_dev->host->host_lock, flags);
tw_state_request_start(tw_dev, &request_id);
tw_dev->srb[request_id] = NULL;
tw_dev->chrdev_request_id = request_id;
tw_ioctl->firmware_command.request_id = request_id;
switch (TW_SGL_OUT(tw_ioctl->firmware_command.opcode__sgloffset)) {
case 2:
tw_ioctl->firmware_command.byte8.param.sgl[0].address = dma_handle + sizeof(TW_New_Ioctl) - 1;
tw_ioctl->firmware_command.byte8.param.sgl[0].length = data_buffer_length_adjusted;
break;
case 3:
tw_ioctl->firmware_command.byte8.io.sgl[0].address = dma_handle + sizeof(TW_New_Ioctl) - 1;
tw_ioctl->firmware_command.byte8.io.sgl[0].length = data_buffer_length_adjusted;
break;
case 5:
passthru->sg_list[0].address = dma_handle + sizeof(TW_New_Ioctl) - 1;
passthru->sg_list[0].length = data_buffer_length_adjusted;
break;
}
memcpy(tw_dev->command_packet_virtual_address[request_id], &(tw_ioctl->firmware_command), sizeof(TW_Command));
tw_post_command_packet(tw_dev, request_id);
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
timeout = TW_IOCTL_CHRDEV_TIMEOUT*HZ;
timeout = wait_event_timeout(tw_dev->ioctl_wqueue, tw_dev->chrdev_request_id == TW_IOCTL_CHRDEV_FREE, timeout);
if (tw_dev->chrdev_request_id != TW_IOCTL_CHRDEV_FREE) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Character ioctl (0x%x) timed out, resetting card.\n", tw_dev->host->host_no, cmd);
retval = -EIO;
if (tw_reset_device_extension(tw_dev)) {
printk(KERN_WARNING "3w-xxxx: tw_chrdev_ioctl(): Reset failed for card %d.\n", tw_dev->host->host_no);
}
goto out2;
}
memcpy(&(tw_ioctl->firmware_command), tw_dev->command_packet_virtual_address[request_id], sizeof(TW_Command));
spin_lock_irqsave(tw_dev->host->host_lock, flags);
tw_dev->posted_request_count--;
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
spin_unlock_irqrestore(tw_dev->host->host_lock, flags);
break;
default:
retval = -ENOTTY;
goto out2;
}
if (copy_to_user(argp, tw_ioctl, sizeof(TW_New_Ioctl) + data_buffer_length - 1))
goto out2;
retval = 0;
out2:
dma_free_coherent(&tw_dev->tw_pci_dev->dev, data_buffer_length_adjusted+sizeof(TW_New_Ioctl) - 1, cpu_addr, dma_handle);
out:
mutex_unlock(&tw_dev->ioctl_lock);
mutex_unlock(&tw_mutex);
return retval;
}
static int tw_chrdev_open(struct inode *inode, struct file *file)
{
unsigned int minor_number;
dprintk(KERN_WARNING "3w-xxxx: tw_ioctl_open()\n");
minor_number = iminor(inode);
if (minor_number >= tw_device_extension_count)
return -ENODEV;
return 0;
}
static void tw_free_device_extension(TW_Device_Extension *tw_dev)
{
dprintk(KERN_NOTICE "3w-xxxx: tw_free_device_extension()\n");
if (tw_dev->command_packet_virtual_address[0])
pci_free_consistent(tw_dev->tw_pci_dev, sizeof(TW_Command)*TW_Q_LENGTH, tw_dev->command_packet_virtual_address[0], tw_dev->command_packet_physical_address[0]);
if (tw_dev->alignment_virtual_address[0])
pci_free_consistent(tw_dev->tw_pci_dev, sizeof(TW_Sector)*TW_Q_LENGTH, tw_dev->alignment_virtual_address[0], tw_dev->alignment_physical_address[0]);
}
static int tw_initconnection(TW_Device_Extension *tw_dev, int message_credits)
{
unsigned long command_que_value;
TW_Command *command_packet;
TW_Response_Queue response_queue;
int request_id = 0;
dprintk(KERN_NOTICE "3w-xxxx: tw_initconnection()\n");
if (tw_dev->command_packet_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_initconnection(): Bad command packet virtual address.\n");
return 1;
}
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(0, TW_OP_INIT_CONNECTION);
command_packet->size = TW_INIT_COMMAND_PACKET_SIZE;
command_packet->request_id = request_id;
command_packet->status = 0x0;
command_packet->flags = 0x0;
command_packet->byte6.message_credits = message_credits;
command_packet->byte8.init_connection.response_queue_pointer = 0x0;
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_initconnection(): Bad command packet physical address.\n");
return 1;
}
outl(command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
if (tw_poll_status_gone(tw_dev, TW_STATUS_RESPONSE_QUEUE_EMPTY, 30) == 0) {
response_queue.value = inl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
request_id = TW_RESID_OUT(response_queue.response_id);
if (request_id != 0) {
printk(KERN_WARNING "3w-xxxx: tw_initconnection(): Unexpected request id.\n");
return 1;
}
if (command_packet->status != 0) {
tw_decode_sense(tw_dev, request_id, 0);
return 1;
}
}
return 0;
}
static int tw_setfeature(TW_Device_Extension *tw_dev, int parm, int param_size,
unsigned char *val)
{
TW_Param *param;
TW_Command *command_packet;
TW_Response_Queue response_queue;
int request_id = 0;
unsigned long command_que_value;
unsigned long param_value;
if (tw_dev->command_packet_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_setfeature(): Bad command packet virtual address.\n");
return 1;
}
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
memset(command_packet, 0, sizeof(TW_Sector));
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_SET_PARAM);
param->table_id = 0x404;
param->parameter_id = parm;
param->parameter_size_bytes = param_size;
memcpy(param->data, val, param_size);
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_setfeature(): Bad alignment physical address.\n");
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
tw_dev->srb[request_id]->result = (DID_OK << 16);
tw_dev->srb[request_id]->scsi_done(tw_dev->srb[request_id]);
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->byte6.parameter_count = 1;
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_setfeature(): Bad command packet physical address.\n");
return 1;
}
outl(command_que_value, TW_COMMAND_QUEUE_REG_ADDR(tw_dev));
if (tw_poll_status_gone(tw_dev, TW_STATUS_RESPONSE_QUEUE_EMPTY, 30) == 0) {
response_queue.value = inl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
request_id = TW_RESID_OUT(response_queue.response_id);
if (request_id != 0) {
printk(KERN_WARNING "3w-xxxx: tw_setfeature(): Unexpected request id.\n");
return 1;
}
if (command_packet->status != 0) {
tw_decode_sense(tw_dev, request_id, 0);
return 1;
}
}
return 0;
}
static int tw_reset_sequence(TW_Device_Extension *tw_dev)
{
int error = 0;
int tries = 0;
unsigned char c = 1;
while (tries < TW_MAX_RESET_TRIES) {
TW_SOFT_RESET(tw_dev);
error = tw_aen_drain_queue(tw_dev);
if (error) {
printk(KERN_WARNING "3w-xxxx: scsi%d: AEN drain failed, retrying.\n", tw_dev->host->host_no);
tries++;
continue;
}
if (tw_check_errors(tw_dev)) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Controller errors found, retrying.\n", tw_dev->host->host_no);
tries++;
continue;
}
break;
}
if (tries >= TW_MAX_RESET_TRIES) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Controller errors, card not responding, check all cabling.\n", tw_dev->host->host_no);
return 1;
}
error = tw_initconnection(tw_dev, TW_INIT_MESSAGE_CREDITS);
if (error) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Connection initialization failed.\n", tw_dev->host->host_no);
return 1;
}
error = tw_setfeature(tw_dev, 2, 1, &c);
if (error) {
printk(KERN_WARNING "3w-xxxx: Unable to set features for card, probable old firmware or card.\n");
}
return 0;
}
static int tw_initialize_device_extension(TW_Device_Extension *tw_dev)
{
int i, error=0;
dprintk(KERN_NOTICE "3w-xxxx: tw_initialize_device_extension()\n");
error = tw_allocate_memory(tw_dev, sizeof(TW_Command), 0);
if (error) {
printk(KERN_WARNING "3w-xxxx: Command packet memory allocation failed.\n");
return 1;
}
error = tw_allocate_memory(tw_dev, sizeof(TW_Sector), 1);
if (error) {
printk(KERN_WARNING "3w-xxxx: Generic memory allocation failed.\n");
return 1;
}
for (i=0;i<TW_Q_LENGTH;i++) {
tw_dev->free_queue[i] = i;
tw_dev->state[i] = TW_S_INITIAL;
}
tw_dev->pending_head = TW_Q_START;
tw_dev->pending_tail = TW_Q_START;
tw_dev->chrdev_request_id = TW_IOCTL_CHRDEV_FREE;
mutex_init(&tw_dev->ioctl_lock);
init_waitqueue_head(&tw_dev->ioctl_wqueue);
return 0;
}
static int tw_map_scsi_sg_data(struct pci_dev *pdev, struct scsi_cmnd *cmd)
{
int use_sg;
dprintk(KERN_WARNING "3w-xxxx: tw_map_scsi_sg_data()\n");
use_sg = scsi_dma_map(cmd);
if (use_sg < 0) {
printk(KERN_WARNING "3w-xxxx: tw_map_scsi_sg_data(): pci_map_sg() failed.\n");
return 0;
}
cmd->SCp.phase = TW_PHASE_SGLIST;
cmd->SCp.have_data_in = use_sg;
return use_sg;
}
static void tw_unmap_scsi_data(struct pci_dev *pdev, struct scsi_cmnd *cmd)
{
dprintk(KERN_WARNING "3w-xxxx: tw_unmap_scsi_data()\n");
if (cmd->SCp.phase == TW_PHASE_SGLIST)
scsi_dma_unmap(cmd);
}
static int tw_reset_device_extension(TW_Device_Extension *tw_dev)
{
int i = 0;
struct scsi_cmnd *srb;
unsigned long flags = 0;
dprintk(KERN_NOTICE "3w-xxxx: tw_reset_device_extension()\n");
set_bit(TW_IN_RESET, &tw_dev->flags);
TW_DISABLE_INTERRUPTS(tw_dev);
TW_MASK_COMMAND_INTERRUPT(tw_dev);
spin_lock_irqsave(tw_dev->host->host_lock, flags);
for (i=0;i<TW_Q_LENGTH;i++) {
if ((tw_dev->state[i] != TW_S_FINISHED) &&
(tw_dev->state[i] != TW_S_INITIAL) &&
(tw_dev->state[i] != TW_S_COMPLETED)) {
srb = tw_dev->srb[i];
if (srb != NULL) {
srb->result = (DID_RESET << 16);
tw_dev->srb[i]->scsi_done(tw_dev->srb[i]);
tw_unmap_scsi_data(tw_dev->tw_pci_dev, tw_dev->srb[i]);
}
}
}
for (i=0;i<TW_Q_LENGTH;i++) {
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
if (tw_reset_sequence(tw_dev)) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Reset sequence failed.\n", tw_dev->host->host_no);
return 1;
}
TW_ENABLE_AND_CLEAR_INTERRUPTS(tw_dev);
clear_bit(TW_IN_RESET, &tw_dev->flags);
tw_dev->chrdev_request_id = TW_IOCTL_CHRDEV_FREE;
return 0;
}
static int tw_scsi_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int geom[])
{
int heads, sectors, cylinders;
TW_Device_Extension *tw_dev;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_biosparam()\n");
tw_dev = (TW_Device_Extension *)sdev->host->hostdata;
heads = 64;
sectors = 32;
cylinders = sector_div(capacity, heads * sectors);
if (capacity >= 0x200000) {
heads = 255;
sectors = 63;
cylinders = sector_div(capacity, heads * sectors);
}
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_biosparam(): heads = %d, sectors = %d, cylinders = %d\n", heads, sectors, cylinders);
geom[0] = heads;
geom[1] = sectors;
geom[2] = cylinders;
return 0;
}
static int tw_scsi_eh_reset(struct scsi_cmnd *SCpnt)
{
TW_Device_Extension *tw_dev=NULL;
int retval = FAILED;
tw_dev = (TW_Device_Extension *)SCpnt->device->host->hostdata;
tw_dev->num_resets++;
sdev_printk(KERN_WARNING, SCpnt->device,
"WARNING: Command (0x%x) timed out, resetting card.\n",
SCpnt->cmnd[0]);
mutex_lock(&tw_dev->ioctl_lock);
if (tw_reset_device_extension(tw_dev)) {
printk(KERN_WARNING "3w-xxxx: scsi%d: Reset failed.\n", tw_dev->host->host_no);
goto out;
}
retval = SUCCESS;
out:
mutex_unlock(&tw_dev->ioctl_lock);
return retval;
}
static int tw_scsiop_inquiry(TW_Device_Extension *tw_dev, int request_id)
{
TW_Param *param;
TW_Command *command_packet;
unsigned long command_que_value;
unsigned long param_value;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_inquiry()\n");
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
if (command_packet == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_inquiry(): Bad command packet virtual address.\n");
return 1;
}
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.parameter_count = 1;
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_inquiry(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
memset(param, 0, sizeof(TW_Sector));
param->table_id = 3;
param->parameter_id = 3;
param->parameter_size_bytes = TW_MAX_UNITS;
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_inquiry(): Bad alignment physical address.\n");
return 1;
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_inquiry(): Bad command packet physical address.\n");
return 1;
}
tw_post_command_packet(tw_dev, request_id);
return 0;
}
static void tw_transfer_internal(TW_Device_Extension *tw_dev, int request_id,
void *data, unsigned int len)
{
scsi_sg_copy_from_buffer(tw_dev->srb[request_id], data, len);
}
static int tw_scsiop_inquiry_complete(TW_Device_Extension *tw_dev, int request_id)
{
unsigned char *is_unit_present;
unsigned char request_buffer[36];
TW_Param *param;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_inquiry_complete()\n");
memset(request_buffer, 0, sizeof(request_buffer));
request_buffer[0] = TYPE_DISK;
request_buffer[1] = 0;
request_buffer[2] = 0;
request_buffer[4] = 31;
memcpy(&request_buffer[8], "3ware ", 8);
sprintf(&request_buffer[16], "Logical Disk %-2d ", tw_dev->srb[request_id]->device->id);
memcpy(&request_buffer[32], TW_DRIVER_VERSION, 3);
tw_transfer_internal(tw_dev, request_id, request_buffer,
sizeof(request_buffer));
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
if (param == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_inquiry_complete(): Bad alignment virtual address.\n");
return 1;
}
is_unit_present = &(param->data[0]);
if (is_unit_present[tw_dev->srb[request_id]->device->id] & TW_UNIT_ONLINE) {
tw_dev->is_unit_present[tw_dev->srb[request_id]->device->id] = 1;
} else {
tw_dev->is_unit_present[tw_dev->srb[request_id]->device->id] = 0;
tw_dev->srb[request_id]->result = (DID_BAD_TARGET << 16);
return TW_ISR_DONT_RESULT;
}
return 0;
}
static int tw_scsiop_mode_sense(TW_Device_Extension *tw_dev, int request_id)
{
TW_Param *param;
TW_Command *command_packet;
unsigned long command_que_value;
unsigned long param_value;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_mode_sense()\n");
if (tw_dev->srb[request_id]->cmnd[2] != 0x8) {
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
tw_dev->srb[request_id]->result = (DID_OK << 16);
tw_dev->srb[request_id]->scsi_done(tw_dev->srb[request_id]);
return 0;
}
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
if (command_packet == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_mode_sense(): Bad command packet virtual address.\n");
return 1;
}
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.parameter_count = 1;
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_mode_sense(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
memset(param, 0, sizeof(TW_Sector));
param->table_id = TW_UNIT_INFORMATION_TABLE_BASE + tw_dev->srb[request_id]->device->id;
param->parameter_id = 7;
param->parameter_size_bytes = 1;
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_mode_sense(): Bad alignment physical address.\n");
return 1;
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_mode_sense(): Bad command packet physical address.\n");
return 1;
}
tw_post_command_packet(tw_dev, request_id);
return 0;
}
static int tw_scsiop_mode_sense_complete(TW_Device_Extension *tw_dev, int request_id)
{
TW_Param *param;
unsigned char *flags;
unsigned char request_buffer[8];
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_mode_sense_complete()\n");
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
if (param == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_mode_sense_complete(): Bad alignment virtual address.\n");
return 1;
}
flags = (char *)&(param->data[0]);
memset(request_buffer, 0, sizeof(request_buffer));
request_buffer[0] = 0xf;
request_buffer[1] = 0;
request_buffer[2] = 0x10;
request_buffer[3] = 0;
request_buffer[4] = 0x8;
request_buffer[5] = 0xa;
if (*flags & 0x1)
request_buffer[6] = 0x5;
else
request_buffer[6] = 0x1;
tw_transfer_internal(tw_dev, request_id, request_buffer,
sizeof(request_buffer));
return 0;
}
static int tw_scsiop_read_capacity(TW_Device_Extension *tw_dev, int request_id)
{
TW_Param *param;
TW_Command *command_packet;
unsigned long command_que_value;
unsigned long param_value;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity()\n");
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
if (command_packet == NULL) {
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity(): Bad command packet virtual address.\n");
return 1;
}
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->unit__hostid = TW_UNITHOST_IN(0, tw_dev->srb[request_id]->device->id);
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.block_count = 1;
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
memset(param, 0, sizeof(TW_Sector));
param->table_id = TW_UNIT_INFORMATION_TABLE_BASE +
tw_dev->srb[request_id]->device->id;
param->parameter_id = 4;
param->parameter_size_bytes = 4;
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity(): Bad alignment physical address.\n");
return 1;
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity(): Bad command packet physical address.\n");
return 1;
}
tw_post_command_packet(tw_dev, request_id);
return 0;
}
static int tw_scsiop_read_capacity_complete(TW_Device_Extension *tw_dev, int request_id)
{
unsigned char *param_data;
u32 capacity;
char buff[8];
TW_Param *param;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity_complete()\n");
memset(buff, 0, sizeof(buff));
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
if (param == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_read_capacity_complete(): Bad alignment virtual address.\n");
return 1;
}
param_data = &(param->data[0]);
capacity = (param_data[3] << 24) | (param_data[2] << 16) |
(param_data[1] << 8) | param_data[0];
capacity -= 1;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_capacity_complete(): Capacity = 0x%x.\n", capacity);
buff[0] = (capacity >> 24);
buff[1] = (capacity >> 16) & 0xff;
buff[2] = (capacity >> 8) & 0xff;
buff[3] = capacity & 0xff;
buff[4] = (TW_BLOCK_SIZE >> 24);
buff[5] = (TW_BLOCK_SIZE >> 16) & 0xff;
buff[6] = (TW_BLOCK_SIZE >> 8) & 0xff;
buff[7] = TW_BLOCK_SIZE & 0xff;
tw_transfer_internal(tw_dev, request_id, buff, sizeof(buff));
return 0;
}
static int tw_scsiop_read_write(TW_Device_Extension *tw_dev, int request_id)
{
TW_Command *command_packet;
unsigned long command_que_value;
u32 lba = 0x0, num_sectors = 0x0;
int i, use_sg;
struct scsi_cmnd *srb;
struct scatterlist *sglist, *sg;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_write()\n");
srb = tw_dev->srb[request_id];
sglist = scsi_sglist(srb);
if (!sglist) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_read_write(): Request buffer NULL.\n");
return 1;
}
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
if (command_packet == NULL) {
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_write(): Bad command packet virtual address.\n");
return 1;
}
if (srb->cmnd[0] == READ_6 || srb->cmnd[0] == READ_10) {
command_packet->opcode__sgloffset = TW_OPSGL_IN(3, TW_OP_READ);
} else {
command_packet->opcode__sgloffset = TW_OPSGL_IN(3, TW_OP_WRITE);
}
command_packet->size = 3;
command_packet->request_id = request_id;
command_packet->unit__hostid = TW_UNITHOST_IN(0, srb->device->id);
command_packet->status = 0;
command_packet->flags = 0;
if (srb->cmnd[0] == WRITE_10) {
if ((srb->cmnd[1] & 0x8) || (srb->cmnd[1] & 0x10))
command_packet->flags = 1;
}
if (srb->cmnd[0] == READ_6 || srb->cmnd[0] == WRITE_6) {
lba = ((u32)srb->cmnd[1] << 16) | ((u32)srb->cmnd[2] << 8) | (u32)srb->cmnd[3];
num_sectors = (u32)srb->cmnd[4];
} else {
lba = ((u32)srb->cmnd[2] << 24) | ((u32)srb->cmnd[3] << 16) | ((u32)srb->cmnd[4] << 8) | (u32)srb->cmnd[5];
num_sectors = (u32)srb->cmnd[8] | ((u32)srb->cmnd[7] << 8);
}
tw_dev->sector_count = num_sectors;
if (tw_dev->sector_count > tw_dev->max_sector_count)
tw_dev->max_sector_count = tw_dev->sector_count;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_read_write(): lba = 0x%x num_sectors = 0x%x\n", lba, num_sectors);
command_packet->byte8.io.lba = lba;
command_packet->byte6.block_count = num_sectors;
use_sg = tw_map_scsi_sg_data(tw_dev->tw_pci_dev, tw_dev->srb[request_id]);
if (!use_sg)
return 1;
scsi_for_each_sg(tw_dev->srb[request_id], sg, use_sg, i) {
command_packet->byte8.io.sgl[i].address = sg_dma_address(sg);
command_packet->byte8.io.sgl[i].length = sg_dma_len(sg);
command_packet->size+=2;
}
tw_dev->sgl_entries = scsi_sg_count(tw_dev->srb[request_id]);
if (tw_dev->sgl_entries > tw_dev->max_sgl_entries)
tw_dev->max_sgl_entries = tw_dev->sgl_entries;
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
dprintk(KERN_WARNING "3w-xxxx: tw_scsiop_read_write(): Bad command packet physical address.\n");
return 1;
}
tw_post_command_packet(tw_dev, request_id);
return 0;
}
static int tw_scsiop_request_sense(TW_Device_Extension *tw_dev, int request_id)
{
char request_buffer[18];
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_request_sense()\n");
memset(request_buffer, 0, sizeof(request_buffer));
request_buffer[0] = 0x70;
request_buffer[7] = 10;
tw_transfer_internal(tw_dev, request_id, request_buffer,
sizeof(request_buffer));
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
tw_dev->srb[request_id]->result = (DID_ERROR << 16);
tw_dev->srb[request_id]->scsi_done(tw_dev->srb[request_id]);
return 0;
}
static int tw_scsiop_synchronize_cache(TW_Device_Extension *tw_dev, int request_id)
{
TW_Command *command_packet;
unsigned long command_que_value;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_synchronize_cache()\n");
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
if (command_packet == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_synchronize_cache(): Bad command packet virtual address.\n");
return 1;
}
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(0, TW_OP_FLUSH_CACHE);
command_packet->size = 2;
command_packet->request_id = request_id;
command_packet->unit__hostid = TW_UNITHOST_IN(0, tw_dev->srb[request_id]->device->id);
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.parameter_count = 1;
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_synchronize_cache(): Bad command packet physical address.\n");
return 1;
}
tw_post_command_packet(tw_dev, request_id);
return 0;
}
static int tw_scsiop_test_unit_ready(TW_Device_Extension *tw_dev, int request_id)
{
TW_Param *param;
TW_Command *command_packet;
unsigned long command_que_value;
unsigned long param_value;
dprintk(KERN_NOTICE "3w-xxxx: tw_scsiop_test_unit_ready()\n");
command_packet = (TW_Command *)tw_dev->command_packet_virtual_address[request_id];
if (command_packet == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_test_unit_ready(): Bad command packet virtual address.\n");
return 1;
}
memset(command_packet, 0, sizeof(TW_Sector));
command_packet->opcode__sgloffset = TW_OPSGL_IN(2, TW_OP_GET_PARAM);
command_packet->size = 4;
command_packet->request_id = request_id;
command_packet->status = 0;
command_packet->flags = 0;
command_packet->byte6.parameter_count = 1;
if (tw_dev->alignment_virtual_address[request_id] == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_test_unit_ready(): Bad alignment virtual address.\n");
return 1;
}
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
memset(param, 0, sizeof(TW_Sector));
param->table_id = 3;
param->parameter_id = 3;
param->parameter_size_bytes = TW_MAX_UNITS;
param_value = tw_dev->alignment_physical_address[request_id];
if (param_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_test_unit_ready(): Bad alignment physical address.\n");
return 1;
}
command_packet->byte8.param.sgl[0].address = param_value;
command_packet->byte8.param.sgl[0].length = sizeof(TW_Sector);
command_que_value = tw_dev->command_packet_physical_address[request_id];
if (command_que_value == 0) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_test_unit_ready(): Bad command packet physical address.\n");
return 1;
}
tw_post_command_packet(tw_dev, request_id);
return 0;
}
static int tw_scsiop_test_unit_ready_complete(TW_Device_Extension *tw_dev, int request_id)
{
unsigned char *is_unit_present;
TW_Param *param;
dprintk(KERN_WARNING "3w-xxxx: tw_scsiop_test_unit_ready_complete()\n");
param = (TW_Param *)tw_dev->alignment_virtual_address[request_id];
if (param == NULL) {
printk(KERN_WARNING "3w-xxxx: tw_scsiop_test_unit_ready_complete(): Bad alignment virtual address.\n");
return 1;
}
is_unit_present = &(param->data[0]);
if (is_unit_present[tw_dev->srb[request_id]->device->id] & TW_UNIT_ONLINE) {
tw_dev->is_unit_present[tw_dev->srb[request_id]->device->id] = 1;
} else {
tw_dev->is_unit_present[tw_dev->srb[request_id]->device->id] = 0;
tw_dev->srb[request_id]->result = (DID_BAD_TARGET << 16);
return TW_ISR_DONT_RESULT;
}
return 0;
}
static int tw_scsi_queue_lck(struct scsi_cmnd *SCpnt, void (*done)(struct scsi_cmnd *))
{
unsigned char *command = SCpnt->cmnd;
int request_id = 0;
int retval = 1;
TW_Device_Extension *tw_dev = (TW_Device_Extension *)SCpnt->device->host->hostdata;
if (test_bit(TW_IN_RESET, &tw_dev->flags))
return SCSI_MLQUEUE_HOST_BUSY;
SCpnt->scsi_done = done;
tw_state_request_start(tw_dev, &request_id);
tw_dev->srb[request_id] = SCpnt;
SCpnt->SCp.phase = TW_PHASE_INITIAL;
switch (*command) {
case READ_10:
case READ_6:
case WRITE_10:
case WRITE_6:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught READ/WRITE.\n");
retval = tw_scsiop_read_write(tw_dev, request_id);
break;
case TEST_UNIT_READY:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught TEST_UNIT_READY.\n");
retval = tw_scsiop_test_unit_ready(tw_dev, request_id);
break;
case INQUIRY:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught INQUIRY.\n");
retval = tw_scsiop_inquiry(tw_dev, request_id);
break;
case READ_CAPACITY:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught READ_CAPACITY.\n");
retval = tw_scsiop_read_capacity(tw_dev, request_id);
break;
case REQUEST_SENSE:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught REQUEST_SENSE.\n");
retval = tw_scsiop_request_sense(tw_dev, request_id);
break;
case MODE_SENSE:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught MODE_SENSE.\n");
retval = tw_scsiop_mode_sense(tw_dev, request_id);
break;
case SYNCHRONIZE_CACHE:
dprintk(KERN_NOTICE "3w-xxxx: tw_scsi_queue(): caught SYNCHRONIZE_CACHE.\n");
retval = tw_scsiop_synchronize_cache(tw_dev, request_id);
break;
case TW_IOCTL:
printk(KERN_WARNING "3w-xxxx: SCSI_IOCTL_SEND_COMMAND deprecated, please update your 3ware tools.\n");
break;
default:
printk(KERN_NOTICE "3w-xxxx: scsi%d: Unknown scsi opcode: 0x%x\n", tw_dev->host->host_no, *command);
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
SCpnt->result = (DRIVER_SENSE << 24) | SAM_STAT_CHECK_CONDITION;
scsi_build_sense_buffer(1, SCpnt->sense_buffer, ILLEGAL_REQUEST, 0x20, 0);
done(SCpnt);
retval = 0;
}
if (retval) {
tw_dev->state[request_id] = TW_S_COMPLETED;
tw_state_request_finish(tw_dev, request_id);
SCpnt->result = (DID_ERROR << 16);
done(SCpnt);
retval = 0;
}
return retval;
}
void __tw_shutdown(TW_Device_Extension *tw_dev)
{
TW_DISABLE_INTERRUPTS(tw_dev);
free_irq(tw_dev->tw_pci_dev->irq, tw_dev);
printk(KERN_WARNING "3w-xxxx: Shutting down host %d.\n", tw_dev->host->host_no);
if (tw_initconnection(tw_dev, 1)) {
printk(KERN_WARNING "3w-xxxx: Connection shutdown failed.\n");
} else {
printk(KERN_WARNING "3w-xxxx: Shutdown complete.\n");
}
TW_ENABLE_AND_CLEAR_INTERRUPTS(tw_dev);
}
static void tw_shutdown(struct pci_dev *pdev)
{
struct Scsi_Host *host = pci_get_drvdata(pdev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
__tw_shutdown(tw_dev);
}
static int tw_slave_configure(struct scsi_device *sdev)
{
blk_queue_rq_timeout(sdev->request_queue, 60 * HZ);
return 0;
}
static int tw_probe(struct pci_dev *pdev, const struct pci_device_id *dev_id)
{
struct Scsi_Host *host = NULL;
TW_Device_Extension *tw_dev;
int retval = -ENODEV;
retval = pci_enable_device(pdev);
if (retval) {
printk(KERN_WARNING "3w-xxxx: Failed to enable pci device.");
goto out_disable_device;
}
pci_set_master(pdev);
retval = pci_set_dma_mask(pdev, TW_DMA_MASK);
if (retval) {
printk(KERN_WARNING "3w-xxxx: Failed to set dma mask.");
goto out_disable_device;
}
host = scsi_host_alloc(&driver_template, sizeof(TW_Device_Extension));
if (!host) {
printk(KERN_WARNING "3w-xxxx: Failed to allocate memory for device extension.");
retval = -ENOMEM;
goto out_disable_device;
}
tw_dev = (TW_Device_Extension *)host->hostdata;
tw_dev->host = host;
tw_dev->tw_pci_dev = pdev;
if (tw_initialize_device_extension(tw_dev)) {
printk(KERN_WARNING "3w-xxxx: Failed to initialize device extension.");
goto out_free_device_extension;
}
retval = pci_request_regions(pdev, "3w-xxxx");
if (retval) {
printk(KERN_WARNING "3w-xxxx: Failed to get mem region.");
goto out_free_device_extension;
}
tw_dev->base_addr = pci_resource_start(pdev, 0);
if (!tw_dev->base_addr) {
printk(KERN_WARNING "3w-xxxx: Failed to get io address.");
goto out_release_mem_region;
}
TW_DISABLE_INTERRUPTS(tw_dev);
if (tw_reset_sequence(tw_dev))
goto out_release_mem_region;
host->max_id = TW_MAX_UNITS;
host->max_cmd_len = TW_MAX_CDB_LEN;
host->max_lun = 0;
host->max_channel = 0;
retval = scsi_add_host(host, &pdev->dev);
if (retval) {
printk(KERN_WARNING "3w-xxxx: scsi add host failed");
goto out_release_mem_region;
}
pci_set_drvdata(pdev, host);
printk(KERN_WARNING "3w-xxxx: scsi%d: Found a 3ware Storage Controller at 0x%x, IRQ: %d.\n", host->host_no, tw_dev->base_addr, pdev->irq);
retval = request_irq(pdev->irq, tw_interrupt, IRQF_SHARED, "3w-xxxx", tw_dev);
if (retval) {
printk(KERN_WARNING "3w-xxxx: Error requesting IRQ.");
goto out_remove_host;
}
tw_device_extension_list[tw_device_extension_count] = tw_dev;
tw_device_extension_count++;
TW_ENABLE_AND_CLEAR_INTERRUPTS(tw_dev);
scsi_scan_host(host);
if (twe_major == -1) {
if ((twe_major = register_chrdev (0, "twe", &tw_fops)) < 0)
printk(KERN_WARNING "3w-xxxx: Failed to register character device.");
}
return 0;
out_remove_host:
scsi_remove_host(host);
out_release_mem_region:
pci_release_regions(pdev);
out_free_device_extension:
tw_free_device_extension(tw_dev);
scsi_host_put(host);
out_disable_device:
pci_disable_device(pdev);
return retval;
}
static void tw_remove(struct pci_dev *pdev)
{
struct Scsi_Host *host = pci_get_drvdata(pdev);
TW_Device_Extension *tw_dev = (TW_Device_Extension *)host->hostdata;
scsi_remove_host(tw_dev->host);
if (twe_major >= 0) {
unregister_chrdev(twe_major, "twe");
twe_major = -1;
}
__tw_shutdown(tw_dev);
pci_release_regions(pdev);
tw_free_device_extension(tw_dev);
scsi_host_put(tw_dev->host);
pci_disable_device(pdev);
tw_device_extension_count--;
}
static int __init tw_init(void)
{
printk(KERN_WARNING "3ware Storage Controller device driver for Linux v%s.\n", TW_DRIVER_VERSION);
return pci_register_driver(&tw_driver);
}
static void __exit tw_exit(void)
{
pci_unregister_driver(&tw_driver);
}
