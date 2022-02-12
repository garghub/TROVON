static int __init fd_mcs_setup(char *str)
{
static int done_setup = 0;
int ints[3];
get_options(str, 3, ints);
if (done_setup++ || ints[0] < 1 || ints[0] > 2 || ints[1] < 1 || ints[1] > 16) {
printk("fd_mcs: usage: fd_mcs=FIFO_COUNT, FIFO_SIZE\n");
return 0;
}
user_fifo_count = ints[0] >= 1 ? ints[1] : 0;
user_fifo_size = ints[0] >= 2 ? ints[2] : 0;
return 1;
}
static void print_banner(struct Scsi_Host *shpnt)
{
printk("scsi%d <fd_mcs>: ", shpnt->host_no);
if (bios_base) {
printk("BIOS at 0x%lX", bios_base);
} else {
printk("No BIOS");
}
printk(", HostID %d, %s Chip, IRQ %d, IO 0x%lX\n", shpnt->this_id, chip == tmc18c50 ? "TMC-18C50" : (chip == tmc18c30 ? "TMC-18C30" : (chip == tmc1800 ? "TMC-1800" : "Unknown")), shpnt->irq, shpnt->io_port);
}
static void do_pause(unsigned amount)
{
do {
mdelay(10);
} while (--amount);
}
static void fd_mcs_make_bus_idle(struct Scsi_Host *shpnt)
{
outb(0, SCSI_Cntl_port);
outb(0, SCSI_Mode_Cntl_port);
if (chip == tmc18c50 || chip == tmc18c30)
outb(0x21 | PARITY_MASK, TMC_Cntl_port);
else
outb(0x01 | PARITY_MASK, TMC_Cntl_port);
}
static int fd_mcs_detect(struct scsi_host_template * tpnt)
{
int loop;
struct Scsi_Host *shpnt;
int slot;
u_char pos2, pos3, pos4;
int id, port, irq;
unsigned long bios;
if (!MCA_bus)
return 0;
id = 7;
for (loop = 0; loop < FD_BRDS; loop++) {
slot = 0;
while (MCA_NOTFOUND != (slot = mca_find_adapter(fd_mcs_adapters[loop].id, slot))) {
printk(KERN_INFO "scsi <fd_mcs>: %s at slot %d\n", fd_mcs_adapters[loop].name, slot + 1);
pos2 = mca_read_stored_pos(slot, 2);
pos3 = mca_read_stored_pos(slot, 3);
pos4 = mca_read_stored_pos(slot, 4);
slot++;
if (fd_mcs_adapters[loop].id == REPLY_ID) {
static int reply_irq[] = { 10, 11, 14, 15 };
bios = 0;
if (pos2 & 0x2)
port = ports[pos4 & 0x3];
else
continue;
irq = reply_irq[((pos4 >> 2) & 0x1) + 2 * ((pos4 >> 4) & 0x1)];
} else {
bios = addresses[pos2 >> 6];
port = ports[(pos2 >> 4) & 0x03];
irq = interrupts[(pos2 >> 1) & 0x07];
}
if (irq) {
mca_set_adapter_name(slot - 1, fd_mcs_adapters[loop].name);
if (request_irq(irq, fd_mcs_intr, IRQF_SHARED, "fd_mcs", hosts)) {
printk(KERN_ERR "fd_mcs: interrupt is not available, skipping...\n");
continue;
}
if (request_region(port, 0x10, "fd_mcs")) {
printk(KERN_ERR "fd_mcs: I/O region is already in use, skipping...\n");
continue;
}
if (!(shpnt = scsi_register(tpnt, sizeof(struct fd_hostdata)))) {
printk(KERN_ERR "fd_mcs: scsi_register() failed\n");
release_region(port, 0x10);
free_irq(irq, hosts);
continue;
}
strcpy(adapter_name, fd_mcs_adapters[loop].name);
chip = fd_mcs_adapters[loop].fd_chip;
FIFO_COUNT = user_fifo_count ? user_fifo_count : fd_mcs_adapters[loop].fifo_count;
FIFO_Size = user_fifo_size ? user_fifo_size : fd_mcs_adapters[loop].fifo_size;
#ifdef NOT_USED
outb(0x80, port + IO_Control);
if ((inb(port + Configuration2) & 0x80) == 0x80) {
outb(0x00, port + IO_Control);
if ((inb(port + Configuration2) & 0x80) == 0x00) {
chip = tmc18c30;
FIFO_Size = 0x800;
printk("FIRST: chip=%s, fifo_size=0x%x\n", (chip == tmc18c30) ? "tmc18c30" : "tmc18c50", FIFO_Size);
}
}
if (inb(port + Configuration2) & 0x02) {
chip = tmc18c30;
FIFO_Size = 0x800;
printk("SECOND: chip=%s, fifo_size=0x%x\n", (chip == tmc18c30) ? "tmc18c30" : "tmc18c50", FIFO_Size);
}
#endif
shpnt->reverse_ordering = 1;
hosts[found++] = shpnt;
shpnt->this_id = id;
shpnt->irq = irq;
shpnt->io_port = port;
shpnt->n_io_port = 0x10;
bios_base = bios;
adapter_mask = (1 << id);
SCSI_Mode_Cntl_port = port + SCSI_Mode_Cntl;
FIFO_Data_Count_port = port + FIFO_Data_Count;
Interrupt_Cntl_port = port + Interrupt_Cntl;
Interrupt_Status_port = port + Interrupt_Status;
Interrupt_Cond_port = port + Interrupt_Cond;
Read_FIFO_port = port + Read_FIFO;
Read_SCSI_Data_port = port + Read_SCSI_Data;
SCSI_Cntl_port = port + SCSI_Cntl;
SCSI_Data_NoACK_port = port + SCSI_Data_NoACK;
SCSI_Status_port = port + SCSI_Status;
TMC_Cntl_port = port + TMC_Cntl;
TMC_Status_port = port + TMC_Status;
Write_FIFO_port = port + Write_FIFO;
Write_SCSI_Data_port = port + Write_SCSI_Data;
Bytes_Read = 0;
Bytes_Written = 0;
INTR_Processed = 0;
print_banner(shpnt);
outb(1, SCSI_Cntl_port);
do_pause(2);
outb(0, SCSI_Cntl_port);
do_pause(115);
outb(0, SCSI_Mode_Cntl_port);
outb(PARITY_MASK, TMC_Cntl_port);
}
}
if (found == FD_MAX_HOSTS) {
printk("fd_mcs: detecting reached max=%d host adapters.\n", FD_MAX_HOSTS);
break;
}
}
return found;
}
static const char *fd_mcs_info(struct Scsi_Host *shpnt)
{
return adapter_name;
}
static int fd_mcs_proc_info(struct Scsi_Host *shpnt, char *buffer, char **start, off_t offset, int length, int inout)
{
int len = 0;
if (inout)
return (-ENOSYS);
*start = buffer + offset;
len += sprintf(buffer + len, "Future Domain MCS-600/700 Driver %s\n", DRIVER_VERSION);
len += sprintf(buffer + len, "HOST #%d: %s\n", shpnt->host_no, adapter_name);
len += sprintf(buffer + len, "FIFO Size=0x%x, FIFO Count=%d\n", FIFO_Size, FIFO_COUNT);
len += sprintf(buffer + len, "DriverCalls=%d, Interrupts=%d, BytesRead=%d, BytesWrite=%d\n\n", TOTAL_INTR, INTR_Processed, Bytes_Read, Bytes_Written);
if ((len -= offset) <= 0)
return 0;
if (len > length)
len = length;
return len;
}
static int fd_mcs_select(struct Scsi_Host *shpnt, int target)
{
int status;
unsigned long timeout;
outb(0x82, SCSI_Cntl_port);
outb(adapter_mask | (1 << target), SCSI_Data_NoACK_port);
outb(PARITY_MASK, TMC_Cntl_port);
timeout = 350;
do {
status = inb(SCSI_Status_port);
if (status & 1) {
outb(0x80, SCSI_Cntl_port);
return 0;
}
udelay(1000);
} while (--timeout);
fd_mcs_make_bus_idle(shpnt);
#if EVERY_ACCESS
if (!target)
printk("Selection failed\n");
#endif
#if ERRORS_ONLY
if (!target) {
static int flag = 0;
if (!flag)
++flag;
else
printk("fd_mcs: Selection failed\n");
}
#endif
return 1;
}
static void my_done(struct Scsi_Host *shpnt, int error)
{
if (in_command) {
in_command = 0;
outb(0x00, Interrupt_Cntl_port);
fd_mcs_make_bus_idle(shpnt);
current_SC->result = error;
current_SC->scsi_done(current_SC);
} else {
panic("fd_mcs: my_done() called outside of command\n");
}
#if DEBUG_RACE
in_interrupt_flag = 0;
#endif
}
static irqreturn_t fd_mcs_intr(int irq, void *dev_id)
{
unsigned long flags;
int status;
int done = 0;
unsigned data_count, tmp_count;
int i = 0;
struct Scsi_Host *shpnt;
TOTAL_INTR++;
while ((shpnt = hosts[i++])) {
if ((inb(TMC_Status_port)) & 1)
break;
}
if (!shpnt) {
return IRQ_NONE;
}
INTR_Processed++;
outb(0x00, Interrupt_Cntl_port);
if (current_SC->SCp.phase & aborted) {
#if DEBUG_ABORT
printk("Interrupt after abort, ignoring\n");
#endif
}
#if DEBUG_RACE
++in_interrupt_flag;
#endif
if (current_SC->SCp.phase & in_arbitration) {
status = inb(TMC_Status_port);
if (!(status & 0x02)) {
#if EVERY_ACCESS
printk(" AFAIL ");
#endif
spin_lock_irqsave(shpnt->host_lock, flags);
my_done(shpnt, DID_BUS_BUSY << 16);
spin_unlock_irqrestore(shpnt->host_lock, flags);
return IRQ_HANDLED;
}
current_SC->SCp.phase = in_selection;
outb(0x40 | FIFO_COUNT, Interrupt_Cntl_port);
outb(0x82, SCSI_Cntl_port);
outb(adapter_mask | (1 << scmd_id(current_SC)), SCSI_Data_NoACK_port);
outb(0x10 | PARITY_MASK, TMC_Cntl_port);
#if DEBUG_RACE
in_interrupt_flag = 0;
#endif
return IRQ_HANDLED;
} else if (current_SC->SCp.phase & in_selection) {
status = inb(SCSI_Status_port);
if (!(status & 0x01)) {
if (fd_mcs_select(shpnt, scmd_id(current_SC))) {
#if EVERY_ACCESS
printk(" SFAIL ");
#endif
spin_lock_irqsave(shpnt->host_lock, flags);
my_done(shpnt, DID_NO_CONNECT << 16);
spin_unlock_irqrestore(shpnt->host_lock, flags);
return IRQ_HANDLED;
} else {
#if EVERY_ACCESS
printk(" AltSel ");
#endif
outb(0x10 | PARITY_MASK, TMC_Cntl_port);
}
}
current_SC->SCp.phase = in_other;
outb(0x90 | FIFO_COUNT, Interrupt_Cntl_port);
outb(0x80, SCSI_Cntl_port);
#if DEBUG_RACE
in_interrupt_flag = 0;
#endif
return IRQ_HANDLED;
}
status = inb(SCSI_Status_port);
if (status & 0x10) {
switch (status & 0x0e) {
case 0x08:
outb(current_SC->cmnd[current_SC->SCp.sent_command++], Write_SCSI_Data_port);
#if EVERY_ACCESS
printk("CMD = %x,", current_SC->cmnd[current_SC->SCp.sent_command - 1]);
#endif
break;
case 0x00:
if (chip != tmc1800 && !current_SC->SCp.have_data_in) {
current_SC->SCp.have_data_in = -1;
outb(0xd0 | PARITY_MASK, TMC_Cntl_port);
}
break;
case 0x04:
if (chip != tmc1800 && !current_SC->SCp.have_data_in) {
current_SC->SCp.have_data_in = 1;
outb(0x90 | PARITY_MASK, TMC_Cntl_port);
}
break;
case 0x0c:
current_SC->SCp.Status = inb(Read_SCSI_Data_port);
#if EVERY_ACCESS
printk("Status = %x, ", current_SC->SCp.Status);
#endif
#if ERRORS_ONLY
if (current_SC->SCp.Status && current_SC->SCp.Status != 2 && current_SC->SCp.Status != 8) {
printk("ERROR fd_mcs: target = %d, command = %x, status = %x\n", current_SC->device->id, current_SC->cmnd[0], current_SC->SCp.Status);
}
#endif
break;
case 0x0a:
outb(MESSAGE_REJECT, Write_SCSI_Data_port);
break;
case 0x0e:
current_SC->SCp.Message = inb(Read_SCSI_Data_port);
#if EVERY_ACCESS
printk("Message = %x, ", current_SC->SCp.Message);
#endif
if (!current_SC->SCp.Message)
++done;
#if DEBUG_MESSAGES || EVERY_ACCESS
if (current_SC->SCp.Message) {
printk("fd_mcs: message = %x\n", current_SC->SCp.Message);
}
#endif
break;
}
}
if (chip == tmc1800 && !current_SC->SCp.have_data_in && (current_SC->SCp.sent_command >= current_SC->cmd_len)) {
switch (current_SC->cmnd[0]) {
case CHANGE_DEFINITION:
case COMPARE:
case COPY:
case COPY_VERIFY:
case LOG_SELECT:
case MODE_SELECT:
case MODE_SELECT_10:
case SEND_DIAGNOSTIC:
case WRITE_BUFFER:
case FORMAT_UNIT:
case REASSIGN_BLOCKS:
case RESERVE:
case SEARCH_EQUAL:
case SEARCH_HIGH:
case SEARCH_LOW:
case WRITE_6:
case WRITE_10:
case WRITE_VERIFY:
case 0x3f:
case 0x41:
case 0xb1:
case 0xb0:
case 0xb2:
case 0xaa:
case 0xae:
case 0x24:
case 0x38:
case 0x3d:
case 0xb6:
case 0xea:
current_SC->SCp.have_data_in = -1;
outb(0xd0 | PARITY_MASK, TMC_Cntl_port);
break;
case 0x00:
default:
current_SC->SCp.have_data_in = 1;
outb(0x90 | PARITY_MASK, TMC_Cntl_port);
break;
}
}
if (current_SC->SCp.have_data_in == -1) {
while ((data_count = FIFO_Size - inw(FIFO_Data_Count_port)) > 512) {
#if EVERY_ACCESS
printk("DC=%d, ", data_count);
#endif
if (data_count > current_SC->SCp.this_residual)
data_count = current_SC->SCp.this_residual;
if (data_count > 0) {
#if EVERY_ACCESS
printk("%d OUT, ", data_count);
#endif
if (data_count == 1) {
Bytes_Written++;
outb(*current_SC->SCp.ptr++, Write_FIFO_port);
--current_SC->SCp.this_residual;
} else {
data_count >>= 1;
tmp_count = data_count << 1;
outsw(Write_FIFO_port, current_SC->SCp.ptr, data_count);
current_SC->SCp.ptr += tmp_count;
Bytes_Written += tmp_count;
current_SC->SCp.this_residual -= tmp_count;
}
}
if (!current_SC->SCp.this_residual) {
if (current_SC->SCp.buffers_residual) {
--current_SC->SCp.buffers_residual;
++current_SC->SCp.buffer;
current_SC->SCp.ptr = sg_virt(current_SC->SCp.buffer);
current_SC->SCp.this_residual = current_SC->SCp.buffer->length;
} else
break;
}
}
} else if (current_SC->SCp.have_data_in == 1) {
while ((data_count = inw(FIFO_Data_Count_port)) > 0) {
#if EVERY_ACCESS
printk("DC=%d, ", data_count);
#endif
if (data_count > current_SC->SCp.this_residual)
data_count = current_SC->SCp.this_residual;
if (data_count) {
#if EVERY_ACCESS
printk("%d IN, ", data_count);
#endif
if (data_count == 1) {
Bytes_Read++;
*current_SC->SCp.ptr++ = inb(Read_FIFO_port);
--current_SC->SCp.this_residual;
} else {
data_count >>= 1;
tmp_count = data_count << 1;
insw(Read_FIFO_port, current_SC->SCp.ptr, data_count);
current_SC->SCp.ptr += tmp_count;
Bytes_Read += tmp_count;
current_SC->SCp.this_residual -= tmp_count;
}
}
if (!current_SC->SCp.this_residual && current_SC->SCp.buffers_residual) {
--current_SC->SCp.buffers_residual;
++current_SC->SCp.buffer;
current_SC->SCp.ptr = sg_virt(current_SC->SCp.buffer);
current_SC->SCp.this_residual = current_SC->SCp.buffer->length;
}
}
}
if (done) {
#if EVERY_ACCESS
printk(" ** IN DONE %d ** ", current_SC->SCp.have_data_in);
#endif
#if EVERY_ACCESS
printk("BEFORE MY_DONE. . .");
#endif
spin_lock_irqsave(shpnt->host_lock, flags);
my_done(shpnt, (current_SC->SCp.Status & 0xff)
| ((current_SC->SCp.Message & 0xff) << 8) | (DID_OK << 16));
spin_unlock_irqrestore(shpnt->host_lock, flags);
#if EVERY_ACCESS
printk("RETURNING.\n");
#endif
} else {
if (current_SC->SCp.phase & disconnect) {
outb(0xd0 | FIFO_COUNT, Interrupt_Cntl_port);
outb(0x00, SCSI_Cntl_port);
} else {
outb(0x90 | FIFO_COUNT, Interrupt_Cntl_port);
}
}
#if DEBUG_RACE
in_interrupt_flag = 0;
#endif
return IRQ_HANDLED;
}
static int fd_mcs_release(struct Scsi_Host *shpnt)
{
int i, this_host, irq_usage;
release_region(shpnt->io_port, shpnt->n_io_port);
this_host = -1;
irq_usage = 0;
for (i = 0; i < found; i++) {
if (shpnt == hosts[i])
this_host = i;
if (shpnt->irq == hosts[i]->irq)
irq_usage++;
}
if (1 == irq_usage)
free_irq(shpnt->irq, hosts);
found--;
for (i = this_host; i < found; i++)
hosts[i] = hosts[i + 1];
hosts[found] = NULL;
return 0;
}
static int fd_mcs_queue_lck(Scsi_Cmnd * SCpnt, void (*done) (Scsi_Cmnd *))
{
struct Scsi_Host *shpnt = SCpnt->device->host;
if (in_command) {
panic("fd_mcs: fd_mcs_queue() NOT REENTRANT!\n");
}
#if EVERY_ACCESS
printk("queue: target = %d cmnd = 0x%02x pieces = %d size = %u\n",
SCpnt->target, *(unsigned char *) SCpnt->cmnd,
scsi_sg_count(SCpnt), scsi_bufflen(SCpnt));
#endif
fd_mcs_make_bus_idle(shpnt);
SCpnt->scsi_done = done;
current_SC = SCpnt;
if (scsi_bufflen(current_SC)) {
current_SC->SCp.buffer = scsi_sglist(current_SC);
current_SC->SCp.ptr = sg_virt(current_SC->SCp.buffer);
current_SC->SCp.this_residual = current_SC->SCp.buffer->length;
current_SC->SCp.buffers_residual = scsi_sg_count(current_SC) - 1;
} else {
current_SC->SCp.ptr = NULL;
current_SC->SCp.this_residual = 0;
current_SC->SCp.buffer = NULL;
current_SC->SCp.buffers_residual = 0;
}
current_SC->SCp.Status = 0;
current_SC->SCp.Message = 0;
current_SC->SCp.have_data_in = 0;
current_SC->SCp.sent_command = 0;
current_SC->SCp.phase = in_arbitration;
outb(0x00, Interrupt_Cntl_port);
outb(0x00, SCSI_Cntl_port);
outb(adapter_mask, SCSI_Data_NoACK_port);
in_command = 1;
outb(0x20, Interrupt_Cntl_port);
outb(0x14 | PARITY_MASK, TMC_Cntl_port);
return 0;
}
int fd_mcs_abort(Scsi_Cmnd * SCpnt)
{
struct Scsi_Host *shpnt = SCpnt->device->host;
unsigned long flags;
#if EVERY_ACCESS || ERRORS_ONLY || DEBUG_ABORT
printk("fd_mcs: abort ");
#endif
spin_lock_irqsave(shpnt->host_lock, flags);
if (!in_command) {
#if EVERY_ACCESS || ERRORS_ONLY
printk(" (not in command)\n");
#endif
spin_unlock_irqrestore(shpnt->host_lock, flags);
return FAILED;
} else
printk("\n");
#if DEBUG_ABORT
fd_mcs_print_info(SCpnt);
#endif
fd_mcs_make_bus_idle(shpnt);
current_SC->SCp.phase |= aborted;
current_SC->result = DID_ABORT << 16;
my_done(shpnt, DID_ABORT << 16);
spin_unlock_irqrestore(shpnt->host_lock, flags);
return SUCCESS;
}
static int fd_mcs_bus_reset(Scsi_Cmnd * SCpnt) {
struct Scsi_Host *shpnt = SCpnt->device->host;
unsigned long flags;
#if DEBUG_RESET
static int called_once = 0;
#endif
#if ERRORS_ONLY
if (SCpnt)
printk("fd_mcs: SCSI Bus Reset\n");
#endif
#if DEBUG_RESET
if (called_once)
fd_mcs_print_info(current_SC);
called_once = 1;
#endif
spin_lock_irqsave(shpnt->host_lock, flags);
outb(1, SCSI_Cntl_port);
do_pause(2);
outb(0, SCSI_Cntl_port);
do_pause(115);
outb(0, SCSI_Mode_Cntl_port);
outb(PARITY_MASK, TMC_Cntl_port);
spin_unlock_irqrestore(shpnt->host_lock, flags);
return SUCCESS;
}
static int fd_mcs_biosparam(struct scsi_device * disk, struct block_device *bdev,
sector_t capacity, int *info_array)
{
unsigned char *p = scsi_bios_ptable(bdev);
int size = capacity;
if (p && p[65] == 0xaa && p[64] == 0x55
&& p[4]) {
info_array[0] = p[5] + 1;
info_array[1] = p[6] & 0x3f;
} else {
if ((unsigned int) size >= 0x7e0000U)
{
info_array[0] = 0xff;
info_array[1] = 0x3f;
} else if ((unsigned int) size >= 0x200000U) {
info_array[0] = 0x80;
info_array[1] = 0x3f;
} else {
info_array[0] = 0x40;
info_array[1] = 0x20;
}
}
info_array[2] = (unsigned int) size / (info_array[0] * info_array[1]);
kfree(p);
return 0;
}
