static int u14_34f_slave_configure(struct scsi_device *dev) {
int j, tqd, utqd;
char *tag_suffix, *link_suffix;
struct Scsi_Host *host = dev->host;
j = ((struct hostdata *) host->hostdata)->board_number;
utqd = MAX_CMD_PER_LUN;
tqd = max_queue_depth;
if (TLDEV(dev->type) && dev->tagged_supported)
if (tag_mode == TAG_SIMPLE) {
scsi_change_queue_depth(dev, tqd);
tag_suffix = ", simple tags";
}
else if (tag_mode == TAG_ORDERED) {
scsi_change_queue_depth(dev, tqd);
tag_suffix = ", ordered tags";
}
else {
scsi_change_queue_depth(dev, tqd);
tag_suffix = ", no tags";
}
else if (TLDEV(dev->type) && linked_comm) {
scsi_change_queue_depth(dev, tqd);
tag_suffix = ", untagged";
}
else {
scsi_change_queue_depth(dev, utqd);
tag_suffix = "";
}
if (TLDEV(dev->type) && linked_comm && dev->queue_depth > 2)
link_suffix = ", sorted";
else if (TLDEV(dev->type))
link_suffix = ", unsorted";
else
link_suffix = "";
sdev_printk(KERN_INFO, dev, "cmds/lun %d%s%s.\n",
dev->queue_depth, link_suffix, tag_suffix);
return FALSE;
}
static int wait_on_busy(unsigned long iobase, unsigned int loop) {
while (inb(iobase + REG_LCL_INTR) & BSY_ASSERTED) {
udelay(1L);
if (--loop == 0) return TRUE;
}
return FALSE;
}
static int board_inquiry(unsigned int j) {
struct mscp *cpp;
dma_addr_t id_dma_addr;
unsigned int limit = 0;
unsigned long time;
id_dma_addr = pci_map_single(HD(j)->pdev, HD(j)->board_id,
sizeof(HD(j)->board_id), PCI_DMA_BIDIRECTIONAL);
cpp = &HD(j)->cp[0];
cpp->cp_dma_addr = pci_map_single(HD(j)->pdev, cpp, sizeof(struct mscp),
PCI_DMA_BIDIRECTIONAL);
memset(cpp, 0, sizeof(struct mscp) - CP_TAIL_SIZE);
cpp->opcode = OP_HOST_ADAPTER;
cpp->xdir = DTD_IN;
cpp->data_address = H2DEV(id_dma_addr);
cpp->data_len = H2DEV(sizeof(HD(j)->board_id));
cpp->cdb_len = 6;
cpp->cdb[0] = HA_CMD_INQUIRY;
if (wait_on_busy(sh[j]->io_port, MAXLOOP)) {
printk("%s: board_inquiry, adapter busy.\n", BN(j));
return TRUE;
}
HD(j)->cp_stat[0] = IGNORE;
outb(CMD_CLR_INTR, sh[j]->io_port + REG_SYS_INTR);
outl(H2DEV(cpp->cp_dma_addr), sh[j]->io_port + REG_OGM);
outb(CMD_OGM_INTR, sh[j]->io_port + REG_LCL_INTR);
spin_unlock_irq(&driver_lock);
time = jiffies;
while ((jiffies - time) < HZ && limit++ < 20000) udelay(100L);
spin_lock_irq(&driver_lock);
if (cpp->adapter_status || HD(j)->cp_stat[0] != FREE) {
HD(j)->cp_stat[0] = FREE;
printk("%s: board_inquiry, err 0x%x.\n", BN(j), cpp->adapter_status);
return TRUE;
}
pci_unmap_single(HD(j)->pdev, cpp->cp_dma_addr, sizeof(struct mscp),
PCI_DMA_BIDIRECTIONAL);
pci_unmap_single(HD(j)->pdev, id_dma_addr, sizeof(HD(j)->board_id),
PCI_DMA_BIDIRECTIONAL);
return FALSE;
}
static int port_detect \
(unsigned long port_base, unsigned int j, struct scsi_host_template *tpnt) {
unsigned char irq, dma_channel, subversion, i;
unsigned char in_byte;
char *bus_type, dma_name[16];
unsigned long bios_segment_table[8] = {
0,
0xc4000, 0xc8000, 0xcc000, 0xd0000,
0xd4000, 0xd8000, 0xdc000
};
unsigned char interrupt_table[4] = { 15, 14, 11, 10 };
unsigned char dma_channel_table[4] = { 5, 6, 7, 0 };
struct {
unsigned char heads;
unsigned char sectors;
} mapping_table[4] = {
{ 16, 63 }, { 64, 32 }, { 64, 63 }, { 64, 32 }
};
struct config_1 {
#if defined(__BIG_ENDIAN_BITFIELD)
unsigned char dma_channel: 2, interrupt:2,
removable_disks_as_fixed:1, bios_segment: 3;
#else
unsigned char bios_segment: 3, removable_disks_as_fixed: 1,
interrupt: 2, dma_channel: 2;
#endif
} config_1;
struct config_2 {
#if defined(__BIG_ENDIAN_BITFIELD)
unsigned char tfr_port: 2, bios_drive_number: 1,
mapping_mode: 2, ha_scsi_id: 3;
#else
unsigned char ha_scsi_id: 3, mapping_mode: 2,
bios_drive_number: 1, tfr_port: 2;
#endif
} config_2;
char name[16];
sprintf(name, "%s%d", driver_name, j);
if (!request_region(port_base, REGION_SIZE, driver_name)) {
#if defined(DEBUG_DETECT)
printk("%s: address 0x%03lx in use, skipping probe.\n", name, port_base);
#endif
goto fail;
}
spin_lock_irq(&driver_lock);
if (inb(port_base + REG_PRODUCT_ID1) != PRODUCT_ID1) goto freelock;
in_byte = inb(port_base + REG_PRODUCT_ID2);
if ((in_byte & 0xf0) != PRODUCT_ID2) goto freelock;
*(char *)&config_1 = inb(port_base + REG_CONFIG1);
*(char *)&config_2 = inb(port_base + REG_CONFIG2);
irq = interrupt_table[config_1.interrupt];
dma_channel = dma_channel_table[config_1.dma_channel];
subversion = (in_byte & 0x0f);
if (request_irq(irq, do_interrupt_handler,
(subversion == ESA) ? IRQF_SHARED : 0,
driver_name, (void *) &sha[j])) {
printk("%s: unable to allocate IRQ %u, detaching.\n", name, irq);
goto freelock;
}
if (subversion == ISA && request_dma(dma_channel, driver_name)) {
printk("%s: unable to allocate DMA channel %u, detaching.\n",
name, dma_channel);
goto freeirq;
}
if (have_old_firmware) tpnt->use_clustering = DISABLE_CLUSTERING;
spin_unlock_irq(&driver_lock);
sh[j] = scsi_register(tpnt, sizeof(struct hostdata));
spin_lock_irq(&driver_lock);
if (sh[j] == NULL) {
printk("%s: unable to register host, detaching.\n", name);
goto freedma;
}
sh[j]->io_port = port_base;
sh[j]->unique_id = port_base;
sh[j]->n_io_port = REGION_SIZE;
sh[j]->base = bios_segment_table[config_1.bios_segment];
sh[j]->irq = irq;
sh[j]->sg_tablesize = MAX_SGLIST;
sh[j]->this_id = config_2.ha_scsi_id;
sh[j]->can_queue = MAX_MAILBOXES;
sh[j]->cmd_per_lun = MAX_CMD_PER_LUN;
#if defined(DEBUG_DETECT)
{
unsigned char sys_mask, lcl_mask;
sys_mask = inb(sh[j]->io_port + REG_SYS_MASK);
lcl_mask = inb(sh[j]->io_port + REG_LCL_MASK);
printk("SYS_MASK 0x%x, LCL_MASK 0x%x.\n", sys_mask, lcl_mask);
}
#endif
if (sh[j]->this_id == 0) sh[j]->this_id = -1;
if (sh[j]->base == 0) outb(CMD_ENA_INTR, sh[j]->io_port + REG_SYS_MASK);
memset(HD(j), 0, sizeof(struct hostdata));
HD(j)->heads = mapping_table[config_2.mapping_mode].heads;
HD(j)->sectors = mapping_table[config_2.mapping_mode].sectors;
HD(j)->subversion = subversion;
HD(j)->pdev = NULL;
HD(j)->board_number = j;
if (have_old_firmware) sh[j]->sg_tablesize = MAX_SAFE_SGLIST;
if (HD(j)->subversion == ESA) {
sh[j]->unchecked_isa_dma = FALSE;
sh[j]->dma_channel = NO_DMA;
sprintf(BN(j), "U34F%d", j);
bus_type = "VESA";
}
else {
unsigned long flags;
sh[j]->unchecked_isa_dma = TRUE;
flags=claim_dma_lock();
disable_dma(dma_channel);
clear_dma_ff(dma_channel);
set_dma_mode(dma_channel, DMA_MODE_CASCADE);
enable_dma(dma_channel);
release_dma_lock(flags);
sh[j]->dma_channel = dma_channel;
sprintf(BN(j), "U14F%d", j);
bus_type = "ISA";
}
sh[j]->max_channel = MAX_CHANNEL - 1;
sh[j]->max_id = MAX_TARGET;
sh[j]->max_lun = MAX_LUN;
if (HD(j)->subversion == ISA && !board_inquiry(j)) {
HD(j)->board_id[40] = 0;
if (strcmp(&HD(j)->board_id[32], "06000600")) {
printk("%s: %s.\n", BN(j), &HD(j)->board_id[8]);
printk("%s: firmware %s is outdated, FW PROM should be 28004-006.\n",
BN(j), &HD(j)->board_id[32]);
sh[j]->hostt->use_clustering = DISABLE_CLUSTERING;
sh[j]->sg_tablesize = MAX_SAFE_SGLIST;
}
}
if (dma_channel == NO_DMA) sprintf(dma_name, "%s", "BMST");
else sprintf(dma_name, "DMA %u", dma_channel);
spin_unlock_irq(&driver_lock);
for (i = 0; i < sh[j]->can_queue; i++)
HD(j)->cp[i].cp_dma_addr = pci_map_single(HD(j)->pdev,
&HD(j)->cp[i], sizeof(struct mscp), PCI_DMA_BIDIRECTIONAL);
for (i = 0; i < sh[j]->can_queue; i++)
if (! ((&HD(j)->cp[i])->sglist = kmalloc(
sh[j]->sg_tablesize * sizeof(struct sg_list),
(sh[j]->unchecked_isa_dma ? GFP_DMA : 0) | GFP_ATOMIC))) {
printk("%s: kmalloc SGlist failed, mbox %d, detaching.\n", BN(j), i);
goto release;
}
if (max_queue_depth > MAX_TAGGED_CMD_PER_LUN)
max_queue_depth = MAX_TAGGED_CMD_PER_LUN;
if (max_queue_depth < MAX_CMD_PER_LUN) max_queue_depth = MAX_CMD_PER_LUN;
if (tag_mode != TAG_DISABLED && tag_mode != TAG_SIMPLE)
tag_mode = TAG_ORDERED;
if (j == 0) {
printk("UltraStor 14F/34F: Copyright (C) 1994-2003 Dario Ballabio.\n");
printk("%s config options -> of:%c, tm:%d, lc:%c, mq:%d, et:%c.\n",
driver_name, YESNO(have_old_firmware), tag_mode,
YESNO(linked_comm), max_queue_depth, YESNO(ext_tran));
}
printk("%s: %s 0x%03lx, BIOS 0x%05x, IRQ %u, %s, SG %d, MB %d.\n",
BN(j), bus_type, (unsigned long)sh[j]->io_port, (int)sh[j]->base,
sh[j]->irq, dma_name, sh[j]->sg_tablesize, sh[j]->can_queue);
if (sh[j]->max_id > 8 || sh[j]->max_lun > 8)
printk("%s: wide SCSI support enabled, max_id %u, max_lun %llu.\n",
BN(j), sh[j]->max_id, sh[j]->max_lun);
for (i = 0; i <= sh[j]->max_channel; i++)
printk("%s: SCSI channel %u enabled, host target ID %d.\n",
BN(j), i, sh[j]->this_id);
return TRUE;
freedma:
if (subversion == ISA) free_dma(dma_channel);
freeirq:
free_irq(irq, &sha[j]);
freelock:
spin_unlock_irq(&driver_lock);
release_region(port_base, REGION_SIZE);
fail:
return FALSE;
release:
u14_34f_release(sh[j]);
return FALSE;
}
static void internal_setup(char *str, int *ints) {
int i, argc = ints[0];
char *cur = str, *pc;
if (argc > 0) {
if (argc > MAX_INT_PARAM) argc = MAX_INT_PARAM;
for (i = 0; i < argc; i++) io_port[i] = ints[i + 1];
io_port[i] = 0;
setup_done = TRUE;
}
while (cur && (pc = strchr(cur, ':'))) {
int val = 0, c = *++pc;
if (c == 'n' || c == 'N') val = FALSE;
else if (c == 'y' || c == 'Y') val = TRUE;
else val = (int) simple_strtoul(pc, NULL, 0);
if (!strncmp(cur, "lc:", 3)) linked_comm = val;
else if (!strncmp(cur, "of:", 3)) have_old_firmware = val;
else if (!strncmp(cur, "tm:", 3)) tag_mode = val;
else if (!strncmp(cur, "tc:", 3)) tag_mode = val;
else if (!strncmp(cur, "mq:", 3)) max_queue_depth = val;
else if (!strncmp(cur, "ls:", 3)) link_statistics = val;
else if (!strncmp(cur, "et:", 3)) ext_tran = val;
if ((cur = strchr(cur, ','))) ++cur;
}
return;
}
static int option_setup(char *str) {
int ints[MAX_INT_PARAM];
char *cur = str;
int i = 1;
while (cur && isdigit(*cur) && i < MAX_INT_PARAM) {
ints[i++] = simple_strtoul(cur, NULL, 0);
if ((cur = strchr(cur, ',')) != NULL) cur++;
}
ints[0] = i - 1;
internal_setup(cur, ints);
return 1;
}
static int u14_34f_detect(struct scsi_host_template *tpnt) {
unsigned int j = 0, k;
tpnt->proc_name = "u14-34f";
if(strlen(boot_options)) option_setup(boot_options);
#if defined(MODULE)
if(io_port[0] != SKIP) {
setup_done = TRUE;
io_port[MAX_INT_PARAM] = 0;
}
#endif
for (k = 0; k < MAX_BOARDS + 1; k++) sh[k] = NULL;
for (k = 0; io_port[k]; k++) {
if (io_port[k] == SKIP) continue;
if (j < MAX_BOARDS && port_detect(io_port[k], j, tpnt)) j++;
}
num_boards = j;
return j;
}
static void map_dma(unsigned int i, unsigned int j) {
unsigned int data_len = 0;
unsigned int k, pci_dir;
int count;
struct scatterlist *sg;
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &HD(j)->cp[i]; SCpnt = cpp->SCpnt;
pci_dir = SCpnt->sc_data_direction;
if (SCpnt->sense_buffer)
cpp->sense_addr = H2DEV(pci_map_single(HD(j)->pdev, SCpnt->sense_buffer,
SCSI_SENSE_BUFFERSIZE, PCI_DMA_FROMDEVICE));
cpp->sense_len = SCSI_SENSE_BUFFERSIZE;
if (scsi_bufflen(SCpnt)) {
count = scsi_dma_map(SCpnt);
BUG_ON(count < 0);
scsi_for_each_sg(SCpnt, sg, count, k) {
cpp->sglist[k].address = H2DEV(sg_dma_address(sg));
cpp->sglist[k].num_bytes = H2DEV(sg_dma_len(sg));
data_len += sg->length;
}
cpp->sg = TRUE;
cpp->use_sg = scsi_sg_count(SCpnt);
cpp->data_address =
H2DEV(pci_map_single(HD(j)->pdev, cpp->sglist,
cpp->use_sg * sizeof(struct sg_list),
pci_dir));
cpp->data_len = H2DEV(data_len);
} else {
pci_dir = PCI_DMA_BIDIRECTIONAL;
cpp->data_len = H2DEV(scsi_bufflen(SCpnt));
}
}
static void unmap_dma(unsigned int i, unsigned int j) {
unsigned int pci_dir;
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &HD(j)->cp[i]; SCpnt = cpp->SCpnt;
pci_dir = SCpnt->sc_data_direction;
if (DEV2H(cpp->sense_addr))
pci_unmap_single(HD(j)->pdev, DEV2H(cpp->sense_addr),
DEV2H(cpp->sense_len), PCI_DMA_FROMDEVICE);
scsi_dma_unmap(SCpnt);
if (!DEV2H(cpp->data_len)) pci_dir = PCI_DMA_BIDIRECTIONAL;
if (DEV2H(cpp->data_address))
pci_unmap_single(HD(j)->pdev, DEV2H(cpp->data_address),
DEV2H(cpp->data_len), pci_dir);
}
static void sync_dma(unsigned int i, unsigned int j) {
unsigned int pci_dir;
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &HD(j)->cp[i]; SCpnt = cpp->SCpnt;
pci_dir = SCpnt->sc_data_direction;
if (DEV2H(cpp->sense_addr))
pci_dma_sync_single_for_cpu(HD(j)->pdev, DEV2H(cpp->sense_addr),
DEV2H(cpp->sense_len), PCI_DMA_FROMDEVICE);
if (scsi_sg_count(SCpnt))
pci_dma_sync_sg_for_cpu(HD(j)->pdev, scsi_sglist(SCpnt),
scsi_sg_count(SCpnt), pci_dir);
if (!DEV2H(cpp->data_len)) pci_dir = PCI_DMA_BIDIRECTIONAL;
if (DEV2H(cpp->data_address))
pci_dma_sync_single_for_cpu(HD(j)->pdev, DEV2H(cpp->data_address),
DEV2H(cpp->data_len), pci_dir);
}
static void scsi_to_dev_dir(unsigned int i, unsigned int j) {
unsigned int k;
static const unsigned char data_out_cmds[] = {
0x0a, 0x2a, 0x15, 0x55, 0x04, 0x07, 0x18, 0x1d, 0x24, 0x2e,
0x30, 0x31, 0x32, 0x38, 0x39, 0x3a, 0x3b, 0x3d, 0x3f, 0x40,
0x41, 0x4c, 0xaa, 0xae, 0xb0, 0xb1, 0xb2, 0xb6, 0xea, 0x1b, 0x5d
};
static const unsigned char data_none_cmds[] = {
0x01, 0x0b, 0x10, 0x11, 0x13, 0x16, 0x17, 0x19, 0x2b, 0x1e,
0x2c, 0xac, 0x2f, 0xaf, 0x33, 0xb3, 0x35, 0x36, 0x45, 0x47,
0x48, 0x49, 0xa9, 0x4b, 0xa5, 0xa6, 0xb5, 0x00
};
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &HD(j)->cp[i]; SCpnt = cpp->SCpnt;
if (SCpnt->sc_data_direction == DMA_FROM_DEVICE) {
cpp->xdir = DTD_IN;
return;
}
else if (SCpnt->sc_data_direction == DMA_TO_DEVICE) {
cpp->xdir = DTD_OUT;
return;
}
else if (SCpnt->sc_data_direction == DMA_NONE) {
cpp->xdir = DTD_NONE;
return;
}
if (SCpnt->sc_data_direction != DMA_BIDIRECTIONAL)
panic("%s: qcomm, invalid SCpnt->sc_data_direction.\n", BN(j));
cpp->xdir = DTD_IN;
for (k = 0; k < ARRAY_SIZE(data_out_cmds); k++)
if (SCpnt->cmnd[0] == data_out_cmds[k]) {
cpp->xdir = DTD_OUT;
break;
}
if (cpp->xdir == DTD_IN)
for (k = 0; k < ARRAY_SIZE(data_none_cmds); k++)
if (SCpnt->cmnd[0] == data_none_cmds[k]) {
cpp->xdir = DTD_NONE;
break;
}
}
static int u14_34f_queuecommand_lck(struct scsi_cmnd *SCpnt, void (*done)(struct scsi_cmnd *)) {
unsigned int i, j, k;
struct mscp *cpp;
j = ((struct hostdata *) SCpnt->device->host->hostdata)->board_number;
if (SCpnt->host_scribble)
panic("%s: qcomm, SCpnt %p already active.\n",
BN(j), SCpnt);
i = HD(j)->last_cp_used + 1;
for (k = 0; k < sh[j]->can_queue; k++, i++) {
if (i >= sh[j]->can_queue) i = 0;
if (HD(j)->cp_stat[i] == FREE) {
HD(j)->last_cp_used = i;
break;
}
}
if (k == sh[j]->can_queue) {
printk("%s: qcomm, no free mailbox.\n", BN(j));
return 1;
}
cpp = &HD(j)->cp[i];
memset(cpp, 0, sizeof(struct mscp) - CP_TAIL_SIZE);
SCpnt->scsi_done = done;
cpp->cpp_index = i;
SCpnt->host_scribble = (unsigned char *) &cpp->cpp_index;
if (do_trace) printk("%s: qcomm, mbox %d, target %d.%d:%u.\n",
BN(j), i, SCpnt->device->channel, SCpnt->device->id,
(u8)SCpnt->device->lun);
cpp->opcode = OP_SCSI;
cpp->channel = SCpnt->device->channel;
cpp->target = SCpnt->device->id;
cpp->lun = (u8)SCpnt->device->lun;
cpp->SCpnt = SCpnt;
cpp->cdb_len = SCpnt->cmd_len;
memcpy(cpp->cdb, SCpnt->cmnd, SCpnt->cmd_len);
scsi_to_dev_dir(i, j);
map_dma(i, j);
if (linked_comm && SCpnt->device->queue_depth > 2
&& TLDEV(SCpnt->device->type)) {
HD(j)->cp_stat[i] = READY;
flush_dev(SCpnt->device, blk_rq_pos(SCpnt->request), j, FALSE);
return 0;
}
if (wait_on_busy(sh[j]->io_port, MAXLOOP)) {
unmap_dma(i, j);
SCpnt->host_scribble = NULL;
scmd_printk(KERN_INFO, SCpnt,
"qcomm, adapter busy.\n");
return 1;
}
outl(H2DEV(cpp->cp_dma_addr), sh[j]->io_port + REG_OGM);
outb(CMD_OGM_INTR, sh[j]->io_port + REG_LCL_INTR);
HD(j)->cp_stat[i] = IN_USE;
return 0;
}
int u14_34f_eh_host_reset(struct scsi_cmnd *SCarg) {
unsigned int i, j, k, c, limit = 0;
unsigned long time;
int arg_done = FALSE;
struct scsi_cmnd *SCpnt;
j = ((struct hostdata *) SCarg->device->host->hostdata)->board_number;
scmd_printk(KERN_INFO, SCarg, "reset, enter.\n");
spin_lock_irq(sh[j]->host_lock);
if (SCarg->host_scribble == NULL)
printk("%s: reset, inactive.\n", BN(j));
if (HD(j)->in_reset) {
printk("%s: reset, exit, already in reset.\n", BN(j));
spin_unlock_irq(sh[j]->host_lock);
return FAILED;
}
if (wait_on_busy(sh[j]->io_port, MAXLOOP)) {
printk("%s: reset, exit, timeout error.\n", BN(j));
spin_unlock_irq(sh[j]->host_lock);
return FAILED;
}
HD(j)->retries = 0;
for (c = 0; c <= sh[j]->max_channel; c++)
for (k = 0; k < sh[j]->max_id; k++) {
HD(j)->target_redo[k][c] = TRUE;
HD(j)->target_to[k][c] = 0;
}
for (i = 0; i < sh[j]->can_queue; i++) {
if (HD(j)->cp_stat[i] == FREE) continue;
if (HD(j)->cp_stat[i] == LOCKED) {
HD(j)->cp_stat[i] = FREE;
printk("%s: reset, locked mbox %d forced free.\n", BN(j), i);
continue;
}
if (!(SCpnt = HD(j)->cp[i].SCpnt))
panic("%s: reset, mbox %d, SCpnt == NULL.\n", BN(j), i);
if (HD(j)->cp_stat[i] == READY || HD(j)->cp_stat[i] == ABORTING) {
HD(j)->cp_stat[i] = ABORTING;
printk("%s: reset, mbox %d aborting.\n", BN(j), i);
}
else {
HD(j)->cp_stat[i] = IN_RESET;
printk("%s: reset, mbox %d in reset.\n", BN(j), i);
}
if (SCpnt->host_scribble == NULL)
panic("%s: reset, mbox %d, garbled SCpnt.\n", BN(j), i);
if (*(unsigned int *)SCpnt->host_scribble != i)
panic("%s: reset, mbox %d, index mismatch.\n", BN(j), i);
if (SCpnt->scsi_done == NULL)
panic("%s: reset, mbox %d, SCpnt->scsi_done == NULL.\n", BN(j), i);
if (SCpnt == SCarg) arg_done = TRUE;
}
if (wait_on_busy(sh[j]->io_port, MAXLOOP)) {
printk("%s: reset, cannot reset, timeout error.\n", BN(j));
spin_unlock_irq(sh[j]->host_lock);
return FAILED;
}
outb(CMD_RESET, sh[j]->io_port + REG_LCL_INTR);
printk("%s: reset, board reset done, enabling interrupts.\n", BN(j));
#if defined(DEBUG_RESET)
do_trace = TRUE;
#endif
HD(j)->in_reset = TRUE;
spin_unlock_irq(sh[j]->host_lock);
time = jiffies;
while ((jiffies - time) < (10 * HZ) && limit++ < 200000) udelay(100L);
spin_lock_irq(sh[j]->host_lock);
printk("%s: reset, interrupts disabled, loops %d.\n", BN(j), limit);
for (i = 0; i < sh[j]->can_queue; i++) {
if (HD(j)->cp_stat[i] == IN_RESET) {
SCpnt = HD(j)->cp[i].SCpnt;
unmap_dma(i, j);
SCpnt->result = DID_RESET << 16;
SCpnt->host_scribble = NULL;
HD(j)->cp_stat[i] = LOCKED;
printk("%s, reset, mbox %d locked, DID_RESET, done.\n", BN(j), i);
}
else if (HD(j)->cp_stat[i] == ABORTING) {
SCpnt = HD(j)->cp[i].SCpnt;
unmap_dma(i, j);
SCpnt->result = DID_RESET << 16;
SCpnt->host_scribble = NULL;
HD(j)->cp_stat[i] = FREE;
printk("%s, reset, mbox %d aborting, DID_RESET, done.\n", BN(j), i);
}
else
continue;
SCpnt->scsi_done(SCpnt);
}
HD(j)->in_reset = FALSE;
do_trace = FALSE;
if (arg_done) printk("%s: reset, exit, done.\n", BN(j));
else printk("%s: reset, exit.\n", BN(j));
spin_unlock_irq(sh[j]->host_lock);
return SUCCESS;
}
static int u14_34f_bios_param(struct scsi_device *disk,
struct block_device *bdev, sector_t capacity, int *dkinfo) {
unsigned int j = 0;
unsigned int size = capacity;
dkinfo[0] = HD(j)->heads;
dkinfo[1] = HD(j)->sectors;
dkinfo[2] = size / (HD(j)->heads * HD(j)->sectors);
if (ext_tran && (scsicam_bios_param(bdev, capacity, dkinfo) < 0)) {
dkinfo[0] = 255;
dkinfo[1] = 63;
dkinfo[2] = size / (dkinfo[0] * dkinfo[1]);
}
#if defined (DEBUG_GEOMETRY)
printk ("%s: bios_param, head=%d, sec=%d, cyl=%d.\n", driver_name,
dkinfo[0], dkinfo[1], dkinfo[2]);
#endif
return FALSE;
}
static void sort(unsigned long sk[], unsigned int da[], unsigned int n,
unsigned int rev) {
unsigned int i, j, k, y;
unsigned long x;
for (i = 0; i < n - 1; i++) {
k = i;
for (j = k + 1; j < n; j++)
if (rev) {
if (sk[j] > sk[k]) k = j;
}
else {
if (sk[j] < sk[k]) k = j;
}
if (k != i) {
x = sk[k]; sk[k] = sk[i]; sk[i] = x;
y = da[k]; da[k] = da[i]; da[i] = y;
}
}
return;
}
static int reorder(unsigned int j, unsigned long cursec,
unsigned int ihdlr, unsigned int il[], unsigned int n_ready) {
struct scsi_cmnd *SCpnt;
struct mscp *cpp;
unsigned int k, n;
unsigned int rev = FALSE, s = TRUE, r = TRUE;
unsigned int input_only = TRUE, overlap = FALSE;
unsigned long sl[n_ready], pl[n_ready], ll[n_ready];
unsigned long maxsec = 0, minsec = ULONG_MAX, seek = 0, iseek = 0;
unsigned long ioseek = 0;
static unsigned int flushcount = 0, batchcount = 0, sortcount = 0;
static unsigned int readycount = 0, ovlcount = 0, inputcount = 0;
static unsigned int readysorted = 0, revcount = 0;
static unsigned long seeksorted = 0, seeknosort = 0;
if (link_statistics && !(++flushcount % link_statistics))
printk("fc %d bc %d ic %d oc %d rc %d rs %d sc %d re %d"\
" av %ldK as %ldK.\n", flushcount, batchcount, inputcount,
ovlcount, readycount, readysorted, sortcount, revcount,
seeknosort / (readycount + 1),
seeksorted / (readycount + 1));
if (n_ready <= 1) return FALSE;
for (n = 0; n < n_ready; n++) {
k = il[n]; cpp = &HD(j)->cp[k]; SCpnt = cpp->SCpnt;
if (!(cpp->xdir == DTD_IN)) input_only = FALSE;
if (blk_rq_pos(SCpnt->request) < minsec)
minsec = blk_rq_pos(SCpnt->request);
if (blk_rq_pos(SCpnt->request) > maxsec)
maxsec = blk_rq_pos(SCpnt->request);
sl[n] = blk_rq_pos(SCpnt->request);
ioseek += blk_rq_sectors(SCpnt->request);
if (!n) continue;
if (sl[n] < sl[n - 1]) s = FALSE;
if (sl[n] > sl[n - 1]) r = FALSE;
if (link_statistics) {
if (sl[n] > sl[n - 1])
seek += sl[n] - sl[n - 1];
else
seek += sl[n - 1] - sl[n];
}
}
if (link_statistics) {
if (cursec > sl[0]) seek += cursec - sl[0]; else seek += sl[0] - cursec;
}
if (cursec > ((maxsec + minsec) / 2)) rev = TRUE;
if (ioseek > ((maxsec - minsec) / 2)) rev = FALSE;
if (!((rev && r) || (!rev && s))) sort(sl, il, n_ready, rev);
if (!input_only) for (n = 0; n < n_ready; n++) {
k = il[n]; cpp = &HD(j)->cp[k]; SCpnt = cpp->SCpnt;
ll[n] = blk_rq_sectors(SCpnt->request); pl[n] = SCpnt->serial_number;
if (!n) continue;
if ((sl[n] == sl[n - 1]) || (!rev && ((sl[n - 1] + ll[n - 1]) > sl[n]))
|| (rev && ((sl[n] + ll[n]) > sl[n - 1]))) overlap = TRUE;
}
if (overlap) sort(pl, il, n_ready, FALSE);
if (link_statistics) {
if (cursec > sl[0]) iseek = cursec - sl[0]; else iseek = sl[0] - cursec;
batchcount++; readycount += n_ready; seeknosort += seek / 1024;
if (input_only) inputcount++;
if (overlap) { ovlcount++; seeksorted += iseek / 1024; }
else seeksorted += (iseek + maxsec - minsec) / 1024;
if (rev && !r) { revcount++; readysorted += n_ready; }
if (!rev && !s) { sortcount++; readysorted += n_ready; }
}
#if defined(DEBUG_LINKED_COMMANDS)
if (link_statistics && (overlap || !(flushcount % link_statistics)))
for (n = 0; n < n_ready; n++) {
k = il[n]; cpp = &HD(j)->cp[k]; SCpnt = cpp->SCpnt;
printk("%s %d.%d:%llu mb %d fc %d nr %d sec %ld ns %u"\
" cur %ld s:%c r:%c rev:%c in:%c ov:%c xd %d.\n",
(ihdlr ? "ihdlr" : "qcomm"), SCpnt->channel, SCpnt->target,
(u8)SCpnt->lun, k, flushcount, n_ready,
blk_rq_pos(SCpnt->request), blk_rq_sectors(SCpnt->request),
cursec, YESNO(s), YESNO(r), YESNO(rev), YESNO(input_only),
YESNO(overlap), cpp->xdir);
}
#endif
return overlap;
}
static void flush_dev(struct scsi_device *dev, unsigned long cursec, unsigned int j,
unsigned int ihdlr) {
struct scsi_cmnd *SCpnt;
struct mscp *cpp;
unsigned int k, n, n_ready = 0, il[MAX_MAILBOXES];
for (k = 0; k < sh[j]->can_queue; k++) {
if (HD(j)->cp_stat[k] != READY && HD(j)->cp_stat[k] != IN_USE) continue;
cpp = &HD(j)->cp[k]; SCpnt = cpp->SCpnt;
if (SCpnt->device != dev) continue;
if (HD(j)->cp_stat[k] == IN_USE) return;
il[n_ready++] = k;
}
if (reorder(j, cursec, ihdlr, il, n_ready)) n_ready = 1;
for (n = 0; n < n_ready; n++) {
k = il[n]; cpp = &HD(j)->cp[k]; SCpnt = cpp->SCpnt;
if (wait_on_busy(sh[j]->io_port, MAXLOOP)) {
scmd_printk(KERN_INFO, SCpnt,
"%s, mbox %d, adapter"
" busy, will abort.\n", (ihdlr ? "ihdlr" : "qcomm"),
k);
HD(j)->cp_stat[k] = ABORTING;
continue;
}
outl(H2DEV(cpp->cp_dma_addr), sh[j]->io_port + REG_OGM);
outb(CMD_OGM_INTR, sh[j]->io_port + REG_LCL_INTR);
HD(j)->cp_stat[k] = IN_USE;
}
}
static irqreturn_t ihdlr(unsigned int j)
{
struct scsi_cmnd *SCpnt;
unsigned int i, k, c, status, tstatus, reg, ret;
struct mscp *spp, *cpp;
int irq = sh[j]->irq;
if (!((reg = inb(sh[j]->io_port + REG_SYS_INTR)) & IRQ_ASSERTED)) goto none;
HD(j)->iocount++;
if (do_trace) printk("%s: ihdlr, enter, irq %d, count %d.\n", BN(j), irq,
HD(j)->iocount);
if (wait_on_busy(sh[j]->io_port, 20 * MAXLOOP)) {
outb(CMD_CLR_INTR, sh[j]->io_port + REG_SYS_INTR);
printk("%s: ihdlr, busy timeout error, irq %d, reg 0x%x, count %d.\n",
BN(j), irq, reg, HD(j)->iocount);
goto none;
}
ret = inl(sh[j]->io_port + REG_ICM);
outb(CMD_CLR_INTR, sh[j]->io_port + REG_SYS_INTR);
for (i = 0; i < sh[j]->can_queue; i++)
if (H2DEV(HD(j)->cp[i].cp_dma_addr) == ret) break;
if (i >= sh[j]->can_queue)
panic("%s: ihdlr, invalid mscp bus address %p, cp0 %p.\n", BN(j),
(void *)ret, (void *)H2DEV(HD(j)->cp[0].cp_dma_addr));
cpp = &(HD(j)->cp[i]);
spp = cpp;
#if defined(DEBUG_GENERATE_ABORTS)
if ((HD(j)->iocount > 500) && ((HD(j)->iocount % 500) < 3)) goto handled;
#endif
if (HD(j)->cp_stat[i] == IGNORE) {
HD(j)->cp_stat[i] = FREE;
goto handled;
}
else if (HD(j)->cp_stat[i] == LOCKED) {
HD(j)->cp_stat[i] = FREE;
printk("%s: ihdlr, mbox %d unlocked, count %d.\n", BN(j), i,
HD(j)->iocount);
goto handled;
}
else if (HD(j)->cp_stat[i] == FREE) {
printk("%s: ihdlr, mbox %d is free, count %d.\n", BN(j), i,
HD(j)->iocount);
goto handled;
}
else if (HD(j)->cp_stat[i] == IN_RESET)
printk("%s: ihdlr, mbox %d is in reset.\n", BN(j), i);
else if (HD(j)->cp_stat[i] != IN_USE)
panic("%s: ihdlr, mbox %d, invalid cp_stat: %d.\n",
BN(j), i, HD(j)->cp_stat[i]);
HD(j)->cp_stat[i] = FREE;
SCpnt = cpp->SCpnt;
if (SCpnt == NULL) panic("%s: ihdlr, mbox %d, SCpnt == NULL.\n", BN(j), i);
if (SCpnt->host_scribble == NULL)
panic("%s: ihdlr, mbox %d, SCpnt %p garbled.\n", BN(j), i,
SCpnt);
if (*(unsigned int *)SCpnt->host_scribble != i)
panic("%s: ihdlr, mbox %d, index mismatch %d.\n",
BN(j), i, *(unsigned int *)SCpnt->host_scribble);
sync_dma(i, j);
if (linked_comm && SCpnt->device->queue_depth > 2
&& TLDEV(SCpnt->device->type))
flush_dev(SCpnt->device, blk_rq_pos(SCpnt->request), j, TRUE);
tstatus = status_byte(spp->target_status);
#if defined(DEBUG_GENERATE_ERRORS)
if ((HD(j)->iocount > 500) && ((HD(j)->iocount % 200) < 2))
spp->adapter_status = 0x01;
#endif
switch (spp->adapter_status) {
case ASOK:
if (tstatus == BUSY && SCpnt->device->type != TYPE_TAPE)
status = DID_ERROR << 16;
else if (tstatus != GOOD && SCpnt->device->type == TYPE_DISK
&& HD(j)->target_redo[scmd_id(SCpnt)][scmd_channel(SCpnt)])
status = DID_BUS_BUSY << 16;
else if (tstatus == CHECK_CONDITION
&& SCpnt->device->type == TYPE_DISK
&& (SCpnt->sense_buffer[2] & 0xf) == RECOVERED_ERROR)
status = DID_BUS_BUSY << 16;
else
status = DID_OK << 16;
if (tstatus == GOOD)
HD(j)->target_redo[scmd_id(SCpnt)][scmd_channel(SCpnt)] = FALSE;
if (spp->target_status && SCpnt->device->type == TYPE_DISK &&
(!(tstatus == CHECK_CONDITION && HD(j)->iocount <= 1000 &&
(SCpnt->sense_buffer[2] & 0xf) == NOT_READY)))
scmd_printk(KERN_INFO, SCpnt,
"ihdlr, target_status 0x%x, sense key 0x%x.\n",
spp->target_status,
SCpnt->sense_buffer[2]);
HD(j)->target_to[scmd_id(SCpnt)][scmd_channel(SCpnt)] = 0;
if (HD(j)->last_retried_pid == SCpnt->serial_number) HD(j)->retries = 0;
break;
case ASST:
if (HD(j)->target_to[scmd_id(SCpnt)][scmd_channel(SCpnt)] > 1)
status = DID_ERROR << 16;
else {
status = DID_TIME_OUT << 16;
HD(j)->target_to[scmd_id(SCpnt)][scmd_channel(SCpnt)]++;
}
break;
case 0x93:
case 0x94:
case 0x96:
case 0xa3:
for (c = 0; c <= sh[j]->max_channel; c++)
for (k = 0; k < sh[j]->max_id; k++)
HD(j)->target_redo[k][c] = TRUE;
case 0x92:
if (SCpnt->device->type != TYPE_TAPE
&& HD(j)->retries < MAX_INTERNAL_RETRIES) {
#if defined(DID_SOFT_ERROR)
status = DID_SOFT_ERROR << 16;
#else
status = DID_BUS_BUSY << 16;
#endif
HD(j)->retries++;
HD(j)->last_retried_pid = SCpnt->serial_number;
}
else
status = DID_ERROR << 16;
break;
case 0x01:
case 0x02:
case 0x03:
case 0x84:
case 0x9b:
case 0x9f:
case 0xff:
default:
status = DID_ERROR << 16;
break;
}
SCpnt->result = status | spp->target_status;
#if defined(DEBUG_INTERRUPT)
if (SCpnt->result || do_trace)
#else
if ((spp->adapter_status != ASOK && HD(j)->iocount > 1000) ||
(spp->adapter_status != ASOK &&
spp->adapter_status != ASST && HD(j)->iocount <= 1000) ||
do_trace || msg_byte(spp->target_status))
#endif
scmd_printk(KERN_INFO, SCpnt, "ihdlr, mbox %2d, err 0x%x:%x,"\
" reg 0x%x, count %d.\n",
i, spp->adapter_status, spp->target_status,
reg, HD(j)->iocount);
unmap_dma(i, j);
SCpnt->host_scribble = NULL;
SCpnt->scsi_done(SCpnt);
if (do_trace) printk("%s: ihdlr, exit, irq %d, count %d.\n", BN(j), irq,
HD(j)->iocount);
handled:
return IRQ_HANDLED;
none:
return IRQ_NONE;
}
static irqreturn_t do_interrupt_handler(int irq, void *shap) {
unsigned int j;
unsigned long spin_flags;
irqreturn_t ret;
if ((j = (unsigned int)((char *)shap - sha)) >= num_boards) return IRQ_NONE;
spin_lock_irqsave(sh[j]->host_lock, spin_flags);
ret = ihdlr(j);
spin_unlock_irqrestore(sh[j]->host_lock, spin_flags);
return ret;
}
static int u14_34f_release(struct Scsi_Host *shpnt) {
unsigned int i, j;
for (j = 0; sh[j] != NULL && sh[j] != shpnt; j++);
if (sh[j] == NULL)
panic("%s: release, invalid Scsi_Host pointer.\n", driver_name);
for (i = 0; i < sh[j]->can_queue; i++)
kfree((&HD(j)->cp[i])->sglist);
for (i = 0; i < sh[j]->can_queue; i++)
pci_unmap_single(HD(j)->pdev, HD(j)->cp[i].cp_dma_addr,
sizeof(struct mscp), PCI_DMA_BIDIRECTIONAL);
free_irq(sh[j]->irq, &sha[j]);
if (sh[j]->dma_channel != NO_DMA)
free_dma(sh[j]->dma_channel);
release_region(sh[j]->io_port, sh[j]->n_io_port);
scsi_unregister(sh[j]);
return FALSE;
}
