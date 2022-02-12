static int eata2x_slave_configure(struct scsi_device *dev)
{
int tqd, utqd;
char *tag_suffix, *link_suffix;
utqd = MAX_CMD_PER_LUN;
tqd = max_queue_depth;
if (TLDEV(dev->type) && dev->tagged_supported) {
if (tag_mode == TAG_SIMPLE) {
scsi_adjust_queue_depth(dev, MSG_SIMPLE_TAG, tqd);
tag_suffix = ", simple tags";
} else if (tag_mode == TAG_ORDERED) {
scsi_adjust_queue_depth(dev, MSG_ORDERED_TAG, tqd);
tag_suffix = ", ordered tags";
} else {
scsi_adjust_queue_depth(dev, 0, tqd);
tag_suffix = ", no tags";
}
} else if (TLDEV(dev->type) && linked_comm) {
scsi_adjust_queue_depth(dev, 0, tqd);
tag_suffix = ", untagged";
} else {
scsi_adjust_queue_depth(dev, 0, utqd);
tag_suffix = "";
}
if (TLDEV(dev->type) && linked_comm && dev->queue_depth > 2)
link_suffix = ", sorted";
else if (TLDEV(dev->type))
link_suffix = ", unsorted";
else
link_suffix = "";
sdev_printk(KERN_INFO, dev,
"cmds/lun %d%s%s.\n",
dev->queue_depth, link_suffix, tag_suffix);
return 0;
}
static int wait_on_busy(unsigned long iobase, unsigned int loop)
{
while (inb(iobase + REG_AUX_STATUS) & ABSY_ASSERTED) {
udelay(1L);
if (--loop == 0)
return 1;
}
return 0;
}
static int do_dma(unsigned long iobase, unsigned long addr, unchar cmd)
{
unsigned char *byaddr;
unsigned long devaddr;
if (wait_on_busy(iobase, (addr ? MAXLOOP * 100 : MAXLOOP)))
return 1;
if (addr) {
devaddr = H2DEV(addr);
byaddr = (unsigned char *)&devaddr;
outb(byaddr[3], iobase + REG_LOW);
outb(byaddr[2], iobase + REG_LM);
outb(byaddr[1], iobase + REG_MID);
outb(byaddr[0], iobase + REG_MSB);
}
outb(cmd, iobase + REG_CMD);
return 0;
}
static int read_pio(unsigned long iobase, ushort * start, ushort * end)
{
unsigned int loop = MAXLOOP;
ushort *p;
for (p = start; p <= end; p++) {
while (!(inb(iobase + REG_STATUS) & DRQ_ASSERTED)) {
udelay(1L);
if (--loop == 0)
return 1;
}
loop = MAXLOOP;
*p = REG2H(inw(iobase));
}
return 0;
}
static struct pci_dev *get_pci_dev(unsigned long port_base)
{
#if defined(CONFIG_PCI)
unsigned int addr;
struct pci_dev *dev = NULL;
while ((dev = pci_get_class(PCI_CLASS_STORAGE_SCSI << 8, dev))) {
addr = pci_resource_start(dev, 0);
#if defined(DEBUG_PCI_DETECT)
printk("%s: get_pci_dev, bus %d, devfn 0x%x, addr 0x%x.\n",
driver_name, dev->bus->number, dev->devfn, addr);
#endif
pci_dev_put(dev);
if (addr + PCI_BASE_ADDRESS_0 == port_base)
return dev;
}
#endif
return NULL;
}
static void enable_pci_ports(void)
{
#if defined(CONFIG_PCI)
struct pci_dev *dev = NULL;
while ((dev = pci_get_class(PCI_CLASS_STORAGE_SCSI << 8, dev))) {
#if defined(DEBUG_PCI_DETECT)
printk("%s: enable_pci_ports, bus %d, devfn 0x%x.\n",
driver_name, dev->bus->number, dev->devfn);
#endif
if (pci_enable_device(dev))
printk
("%s: warning, pci_enable_device failed, bus %d devfn 0x%x.\n",
driver_name, dev->bus->number, dev->devfn);
}
#endif
}
static int port_detect(unsigned long port_base, unsigned int j,
struct scsi_host_template *tpnt)
{
unsigned char irq, dma_channel, subversion, i, is_pci = 0;
unsigned char protocol_rev;
struct eata_info info;
char *bus_type, dma_name[16];
struct pci_dev *pdev;
unsigned char dma_channel_table[4] = { 5, 6, 7, 0 };
struct Scsi_Host *shost;
struct hostdata *ha;
char name[16];
sprintf(name, "%s%d", driver_name, j);
if (!request_region(port_base, REGION_SIZE, driver_name)) {
#if defined(DEBUG_DETECT)
printk("%s: address 0x%03lx in use, skipping probe.\n", name,
port_base);
#endif
goto fail;
}
spin_lock_irq(&driver_lock);
if (do_dma(port_base, 0, READ_CONFIG_PIO)) {
#if defined(DEBUG_DETECT)
printk("%s: detect, do_dma failed at 0x%03lx.\n", name,
port_base);
#endif
goto freelock;
}
if (read_pio(port_base, (ushort *) & info, (ushort *) & info.ipad[0])) {
#if defined(DEBUG_DETECT)
printk("%s: detect, read_pio failed at 0x%03lx.\n", name,
port_base);
#endif
goto freelock;
}
info.data_len = DEV2H(info.data_len);
info.sign = DEV2H(info.sign);
info.cp_pad_len = DEV2H16(info.cp_pad_len);
info.cp_len = DEV2H(info.cp_len);
info.sp_len = DEV2H(info.sp_len);
info.scatt_size = DEV2H16(info.scatt_size);
info.queue_size = DEV2H16(info.queue_size);
if (info.sign != EATA_SIG_BE) {
#if defined(DEBUG_DETECT)
printk("%s: signature 0x%04x discarded.\n", name, info.sign);
#endif
goto freelock;
}
if (info.data_len < EATA_2_0A_SIZE) {
printk
("%s: config structure size (%d bytes) too short, detaching.\n",
name, info.data_len);
goto freelock;
} else if (info.data_len == EATA_2_0A_SIZE)
protocol_rev = 'A';
else if (info.data_len == EATA_2_0B_SIZE)
protocol_rev = 'B';
else
protocol_rev = 'C';
if (protocol_rev != 'A' && info.forcaddr) {
printk("%s: warning, port address has been forced.\n", name);
bus_type = "PCI";
is_pci = 1;
subversion = ESA;
} else if (port_base > MAX_EISA_ADDR
|| (protocol_rev == 'C' && info.pci)) {
bus_type = "PCI";
is_pci = 1;
subversion = ESA;
} else if (port_base >= MIN_EISA_ADDR
|| (protocol_rev == 'C' && info.eisa)) {
bus_type = "EISA";
subversion = ESA;
} else if (protocol_rev == 'C' && !info.eisa && !info.pci) {
bus_type = "ISA";
subversion = ISA;
} else if (port_base > MAX_ISA_ADDR) {
bus_type = "PCI";
is_pci = 1;
subversion = ESA;
} else {
bus_type = "ISA";
subversion = ISA;
}
if (!info.haaval || info.ata) {
printk
("%s: address 0x%03lx, unusable %s board (%d%d), detaching.\n",
name, port_base, bus_type, info.haaval, info.ata);
goto freelock;
}
if (info.drqvld) {
if (subversion == ESA)
printk("%s: warning, weird %s board using DMA.\n", name,
bus_type);
subversion = ISA;
dma_channel = dma_channel_table[3 - info.drqx];
} else {
if (subversion == ISA)
printk("%s: warning, weird %s board not using DMA.\n",
name, bus_type);
subversion = ESA;
dma_channel = NO_DMA;
}
if (!info.dmasup)
printk("%s: warning, DMA protocol support not asserted.\n",
name);
irq = info.irq;
if (subversion == ESA && !info.irq_tr)
printk
("%s: warning, LEVEL triggering is suggested for IRQ %u.\n",
name, irq);
if (is_pci) {
pdev = get_pci_dev(port_base);
if (!pdev)
printk
("%s: warning, failed to get pci_dev structure.\n",
name);
} else
pdev = NULL;
if (pdev && (irq != pdev->irq)) {
printk("%s: IRQ %u mapped to IO-APIC IRQ %u.\n", name, irq,
pdev->irq);
irq = pdev->irq;
}
if (request_irq(irq, do_interrupt_handler,
(subversion == ESA) ? IRQF_SHARED : 0,
driver_name, (void *)&sha[j])) {
printk("%s: unable to allocate IRQ %u, detaching.\n", name,
irq);
goto freelock;
}
if (subversion == ISA && request_dma(dma_channel, driver_name)) {
printk("%s: unable to allocate DMA channel %u, detaching.\n",
name, dma_channel);
goto freeirq;
}
#if defined(FORCE_CONFIG)
{
struct eata_config *cf;
dma_addr_t cf_dma_addr;
cf = pci_zalloc_consistent(pdev, sizeof(struct eata_config),
&cf_dma_addr);
if (!cf) {
printk
("%s: config, pci_alloc_consistent failed, detaching.\n",
name);
goto freedma;
}
cf->len = (ushort) H2DEV16((ushort) 510);
cf->ocena = 1;
if (do_dma(port_base, cf_dma_addr, SET_CONFIG_DMA)) {
printk
("%s: busy timeout sending configuration, detaching.\n",
name);
pci_free_consistent(pdev, sizeof(struct eata_config),
cf, cf_dma_addr);
goto freedma;
}
}
#endif
spin_unlock_irq(&driver_lock);
sh[j] = shost = scsi_register(tpnt, sizeof(struct hostdata));
spin_lock_irq(&driver_lock);
if (shost == NULL) {
printk("%s: unable to register host, detaching.\n", name);
goto freedma;
}
shost->io_port = port_base;
shost->unique_id = port_base;
shost->n_io_port = REGION_SIZE;
shost->dma_channel = dma_channel;
shost->irq = irq;
shost->sg_tablesize = (ushort) info.scatt_size;
shost->this_id = (ushort) info.host_addr[3];
shost->can_queue = (ushort) info.queue_size;
shost->cmd_per_lun = MAX_CMD_PER_LUN;
ha = (struct hostdata *)shost->hostdata;
memset(ha, 0, sizeof(struct hostdata));
ha->subversion = subversion;
ha->protocol_rev = protocol_rev;
ha->is_pci = is_pci;
ha->pdev = pdev;
ha->board_number = j;
if (ha->subversion == ESA)
shost->unchecked_isa_dma = 0;
else {
unsigned long flags;
shost->unchecked_isa_dma = 1;
flags = claim_dma_lock();
disable_dma(dma_channel);
clear_dma_ff(dma_channel);
set_dma_mode(dma_channel, DMA_MODE_CASCADE);
enable_dma(dma_channel);
release_dma_lock(flags);
}
strcpy(ha->board_name, name);
if (shost->sg_tablesize > MAX_SGLIST || shost->sg_tablesize < 2) {
printk("%s: detect, wrong n. of SG lists %d, fixed.\n",
ha->board_name, shost->sg_tablesize);
shost->sg_tablesize = MAX_SGLIST;
}
if (shost->can_queue > MAX_MAILBOXES || shost->can_queue < 2) {
printk("%s: detect, wrong n. of mbox %d, fixed.\n",
ha->board_name, shost->can_queue);
shost->can_queue = MAX_MAILBOXES;
}
if (protocol_rev != 'A') {
if (info.max_chan > 0 && info.max_chan < MAX_CHANNEL)
shost->max_channel = info.max_chan;
if (info.max_id > 7 && info.max_id < MAX_TARGET)
shost->max_id = info.max_id + 1;
if (info.large_sg && shost->sg_tablesize == MAX_SGLIST)
shost->sg_tablesize = MAX_LARGE_SGLIST;
}
if (protocol_rev == 'C') {
if (info.max_lun > 7 && info.max_lun < MAX_LUN)
shost->max_lun = info.max_lun + 1;
}
if (dma_channel == NO_DMA)
sprintf(dma_name, "%s", "BMST");
else
sprintf(dma_name, "DMA %u", dma_channel);
spin_unlock_irq(&driver_lock);
for (i = 0; i < shost->can_queue; i++)
ha->cp[i].cp_dma_addr = pci_map_single(ha->pdev,
&ha->cp[i],
sizeof(struct mscp),
PCI_DMA_BIDIRECTIONAL);
for (i = 0; i < shost->can_queue; i++) {
size_t sz = shost->sg_tablesize *sizeof(struct sg_list);
gfp_t gfp_mask = (shost->unchecked_isa_dma ? GFP_DMA : 0) | GFP_ATOMIC;
ha->cp[i].sglist = kmalloc(sz, gfp_mask);
if (!ha->cp[i].sglist) {
printk
("%s: kmalloc SGlist failed, mbox %d, detaching.\n",
ha->board_name, i);
goto release;
}
}
if (!(ha->sp_cpu_addr = pci_alloc_consistent(ha->pdev,
sizeof(struct mssp),
&ha->sp_dma_addr))) {
printk("%s: pci_alloc_consistent failed, detaching.\n", ha->board_name);
goto release;
}
if (max_queue_depth > MAX_TAGGED_CMD_PER_LUN)
max_queue_depth = MAX_TAGGED_CMD_PER_LUN;
if (max_queue_depth < MAX_CMD_PER_LUN)
max_queue_depth = MAX_CMD_PER_LUN;
if (tag_mode != TAG_DISABLED && tag_mode != TAG_SIMPLE)
tag_mode = TAG_ORDERED;
if (j == 0) {
printk
("EATA/DMA 2.0x: Copyright (C) 1994-2003 Dario Ballabio.\n");
printk
("%s config options -> tm:%d, lc:%c, mq:%d, rs:%c, et:%c, "
"ip:%c, ep:%c, pp:%c.\n", driver_name, tag_mode,
YESNO(linked_comm), max_queue_depth, YESNO(rev_scan),
YESNO(ext_tran), YESNO(isa_probe), YESNO(eisa_probe),
YESNO(pci_probe));
}
printk("%s: 2.0%c, %s 0x%03lx, IRQ %u, %s, SG %d, MB %d.\n",
ha->board_name, ha->protocol_rev, bus_type,
(unsigned long)shost->io_port, shost->irq, dma_name,
shost->sg_tablesize, shost->can_queue);
if (shost->max_id > 8 || shost->max_lun > 8)
printk
("%s: wide SCSI support enabled, max_id %u, max_lun %llu.\n",
ha->board_name, shost->max_id, shost->max_lun);
for (i = 0; i <= shost->max_channel; i++)
printk("%s: SCSI channel %u enabled, host target ID %d.\n",
ha->board_name, i, info.host_addr[3 - i]);
#if defined(DEBUG_DETECT)
printk("%s: Vers. 0x%x, ocs %u, tar %u, trnxfr %u, more %u, SYNC 0x%x, "
"sec. %u, infol %d, cpl %d spl %d.\n", name, info.version,
info.ocsena, info.tarsup, info.trnxfr, info.morsup, info.sync,
info.second, info.data_len, info.cp_len, info.sp_len);
if (protocol_rev == 'B' || protocol_rev == 'C')
printk("%s: isaena %u, forcaddr %u, max_id %u, max_chan %u, "
"large_sg %u, res1 %u.\n", name, info.isaena,
info.forcaddr, info.max_id, info.max_chan, info.large_sg,
info.res1);
if (protocol_rev == 'C')
printk("%s: max_lun %u, m1 %u, idquest %u, pci %u, eisa %u, "
"raidnum %u.\n", name, info.max_lun, info.m1,
info.idquest, info.pci, info.eisa, info.raidnum);
#endif
if (ha->pdev) {
pci_set_master(ha->pdev);
if (pci_set_dma_mask(ha->pdev, DMA_BIT_MASK(32)))
printk("%s: warning, pci_set_dma_mask failed.\n",
ha->board_name);
}
return 1;
freedma:
if (subversion == ISA)
free_dma(dma_channel);
freeirq:
free_irq(irq, &sha[j]);
freelock:
spin_unlock_irq(&driver_lock);
release_region(port_base, REGION_SIZE);
fail:
return 0;
release:
eata2x_release(shost);
return 0;
}
static void internal_setup(char *str, int *ints)
{
int i, argc = ints[0];
char *cur = str, *pc;
if (argc > 0) {
if (argc > MAX_INT_PARAM)
argc = MAX_INT_PARAM;
for (i = 0; i < argc; i++)
io_port[i] = ints[i + 1];
io_port[i] = 0;
setup_done = 1;
}
while (cur && (pc = strchr(cur, ':'))) {
int val = 0, c = *++pc;
if (c == 'n' || c == 'N')
val = 0;
else if (c == 'y' || c == 'Y')
val = 1;
else
val = (int)simple_strtoul(pc, NULL, 0);
if (!strncmp(cur, "lc:", 3))
linked_comm = val;
else if (!strncmp(cur, "tm:", 3))
tag_mode = val;
else if (!strncmp(cur, "tc:", 3))
tag_mode = val;
else if (!strncmp(cur, "mq:", 3))
max_queue_depth = val;
else if (!strncmp(cur, "ls:", 3))
link_statistics = val;
else if (!strncmp(cur, "et:", 3))
ext_tran = val;
else if (!strncmp(cur, "rs:", 3))
rev_scan = val;
else if (!strncmp(cur, "ip:", 3))
isa_probe = val;
else if (!strncmp(cur, "ep:", 3))
eisa_probe = val;
else if (!strncmp(cur, "pp:", 3))
pci_probe = val;
if ((cur = strchr(cur, ',')))
++cur;
}
return;
}
static int option_setup(char *str)
{
int ints[MAX_INT_PARAM];
char *cur = str;
int i = 1;
while (cur && isdigit(*cur) && i < MAX_INT_PARAM) {
ints[i++] = simple_strtoul(cur, NULL, 0);
if ((cur = strchr(cur, ',')) != NULL)
cur++;
}
ints[0] = i - 1;
internal_setup(cur, ints);
return 1;
}
static void add_pci_ports(void)
{
#if defined(CONFIG_PCI)
unsigned int addr, k;
struct pci_dev *dev = NULL;
for (k = 0; k < MAX_PCI; k++) {
if (!(dev = pci_get_class(PCI_CLASS_STORAGE_SCSI << 8, dev)))
break;
if (pci_enable_device(dev)) {
#if defined(DEBUG_PCI_DETECT)
printk
("%s: detect, bus %d, devfn 0x%x, pci_enable_device failed.\n",
driver_name, dev->bus->number, dev->devfn);
#endif
continue;
}
addr = pci_resource_start(dev, 0);
#if defined(DEBUG_PCI_DETECT)
printk("%s: detect, seq. %d, bus %d, devfn 0x%x, addr 0x%x.\n",
driver_name, k, dev->bus->number, dev->devfn, addr);
#endif
io_port[MAX_INT_PARAM + (rev_scan ? (MAX_PCI - k) : (1 + k))] =
addr + PCI_BASE_ADDRESS_0;
}
pci_dev_put(dev);
#endif
}
static int eata2x_detect(struct scsi_host_template *tpnt)
{
unsigned int j = 0, k;
tpnt->proc_name = "eata2x";
if (strlen(boot_options))
option_setup(boot_options);
#if defined(MODULE)
if (io_port[0] != SKIP) {
setup_done = 1;
io_port[MAX_INT_PARAM] = 0;
}
#endif
for (k = MAX_INT_PARAM; io_port[k]; k++)
if (io_port[k] == SKIP)
continue;
else if (io_port[k] <= MAX_ISA_ADDR) {
if (!isa_probe)
io_port[k] = SKIP;
} else if (io_port[k] >= MIN_EISA_ADDR
&& io_port[k] <= MAX_EISA_ADDR) {
if (!eisa_probe)
io_port[k] = SKIP;
}
if (pci_probe) {
if (!setup_done)
add_pci_ports();
else
enable_pci_ports();
}
for (k = 0; io_port[k]; k++) {
if (io_port[k] == SKIP)
continue;
if (j < MAX_BOARDS && port_detect(io_port[k], j, tpnt))
j++;
}
num_boards = j;
return j;
}
static void map_dma(unsigned int i, struct hostdata *ha)
{
unsigned int k, pci_dir;
int count;
struct scatterlist *sg;
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &ha->cp[i];
SCpnt = cpp->SCpnt;
pci_dir = SCpnt->sc_data_direction;
if (SCpnt->sense_buffer)
cpp->sense_addr =
H2DEV(pci_map_single(ha->pdev, SCpnt->sense_buffer,
SCSI_SENSE_BUFFERSIZE, PCI_DMA_FROMDEVICE));
cpp->sense_len = SCSI_SENSE_BUFFERSIZE;
if (!scsi_sg_count(SCpnt)) {
cpp->data_len = 0;
return;
}
count = pci_map_sg(ha->pdev, scsi_sglist(SCpnt), scsi_sg_count(SCpnt),
pci_dir);
BUG_ON(!count);
scsi_for_each_sg(SCpnt, sg, count, k) {
cpp->sglist[k].address = H2DEV(sg_dma_address(sg));
cpp->sglist[k].num_bytes = H2DEV(sg_dma_len(sg));
}
cpp->sg = 1;
cpp->data_address = H2DEV(pci_map_single(ha->pdev, cpp->sglist,
scsi_sg_count(SCpnt) *
sizeof(struct sg_list),
pci_dir));
cpp->data_len = H2DEV((scsi_sg_count(SCpnt) * sizeof(struct sg_list)));
}
static void unmap_dma(unsigned int i, struct hostdata *ha)
{
unsigned int pci_dir;
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &ha->cp[i];
SCpnt = cpp->SCpnt;
pci_dir = SCpnt->sc_data_direction;
if (DEV2H(cpp->sense_addr))
pci_unmap_single(ha->pdev, DEV2H(cpp->sense_addr),
DEV2H(cpp->sense_len), PCI_DMA_FROMDEVICE);
if (scsi_sg_count(SCpnt))
pci_unmap_sg(ha->pdev, scsi_sglist(SCpnt), scsi_sg_count(SCpnt),
pci_dir);
if (!DEV2H(cpp->data_len))
pci_dir = PCI_DMA_BIDIRECTIONAL;
if (DEV2H(cpp->data_address))
pci_unmap_single(ha->pdev, DEV2H(cpp->data_address),
DEV2H(cpp->data_len), pci_dir);
}
static void sync_dma(unsigned int i, struct hostdata *ha)
{
unsigned int pci_dir;
struct mscp *cpp;
struct scsi_cmnd *SCpnt;
cpp = &ha->cp[i];
SCpnt = cpp->SCpnt;
pci_dir = SCpnt->sc_data_direction;
if (DEV2H(cpp->sense_addr))
pci_dma_sync_single_for_cpu(ha->pdev, DEV2H(cpp->sense_addr),
DEV2H(cpp->sense_len),
PCI_DMA_FROMDEVICE);
if (scsi_sg_count(SCpnt))
pci_dma_sync_sg_for_cpu(ha->pdev, scsi_sglist(SCpnt),
scsi_sg_count(SCpnt), pci_dir);
if (!DEV2H(cpp->data_len))
pci_dir = PCI_DMA_BIDIRECTIONAL;
if (DEV2H(cpp->data_address))
pci_dma_sync_single_for_cpu(ha->pdev,
DEV2H(cpp->data_address),
DEV2H(cpp->data_len), pci_dir);
}
static void scsi_to_dev_dir(unsigned int i, struct hostdata *ha)
{
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
cpp = &ha->cp[i];
SCpnt = cpp->SCpnt;
if (SCpnt->sc_data_direction == DMA_FROM_DEVICE) {
cpp->din = 1;
cpp->dout = 0;
return;
} else if (SCpnt->sc_data_direction == DMA_TO_DEVICE) {
cpp->din = 0;
cpp->dout = 1;
return;
} else if (SCpnt->sc_data_direction == DMA_NONE) {
cpp->din = 0;
cpp->dout = 0;
return;
}
if (SCpnt->sc_data_direction != DMA_BIDIRECTIONAL)
panic("%s: qcomm, invalid SCpnt->sc_data_direction.\n",
ha->board_name);
for (k = 0; k < ARRAY_SIZE(data_out_cmds); k++)
if (SCpnt->cmnd[0] == data_out_cmds[k]) {
cpp->dout = 1;
break;
}
if ((cpp->din = !cpp->dout))
for (k = 0; k < ARRAY_SIZE(data_none_cmds); k++)
if (SCpnt->cmnd[0] == data_none_cmds[k]) {
cpp->din = 0;
break;
}
}
static int eata2x_queuecommand_lck(struct scsi_cmnd *SCpnt,
void (*done) (struct scsi_cmnd *))
{
struct Scsi_Host *shost = SCpnt->device->host;
struct hostdata *ha = (struct hostdata *)shost->hostdata;
unsigned int i, k;
struct mscp *cpp;
if (SCpnt->host_scribble)
panic("%s: qcomm, SCpnt %p already active.\n",
ha->board_name, SCpnt);
i = ha->last_cp_used + 1;
for (k = 0; k < shost->can_queue; k++, i++) {
if (i >= shost->can_queue)
i = 0;
if (ha->cp_stat[i] == FREE) {
ha->last_cp_used = i;
break;
}
}
if (k == shost->can_queue) {
printk("%s: qcomm, no free mailbox.\n", ha->board_name);
return 1;
}
cpp = &ha->cp[i];
memset(cpp, 0, sizeof(struct mscp) - CP_TAIL_SIZE);
cpp->sp_dma_addr = H2DEV(ha->sp_dma_addr);
SCpnt->scsi_done = done;
cpp->cpp_index = i;
SCpnt->host_scribble = (unsigned char *)&cpp->cpp_index;
if (do_trace)
scmd_printk(KERN_INFO, SCpnt,
"qcomm, mbox %d.\n", i);
cpp->reqsen = 1;
cpp->dispri = 1;
#if 0
if (SCpnt->device->type == TYPE_TAPE)
cpp->hbaci = 1;
#endif
cpp->one = 1;
cpp->channel = SCpnt->device->channel;
cpp->target = SCpnt->device->id;
cpp->lun = SCpnt->device->lun;
cpp->SCpnt = SCpnt;
memcpy(cpp->cdb, SCpnt->cmnd, SCpnt->cmd_len);
scsi_to_dev_dir(i, ha);
map_dma(i, ha);
if (linked_comm && SCpnt->device->queue_depth > 2
&& TLDEV(SCpnt->device->type)) {
ha->cp_stat[i] = READY;
flush_dev(SCpnt->device, blk_rq_pos(SCpnt->request), ha, 0);
return 0;
}
if (do_dma(shost->io_port, cpp->cp_dma_addr, SEND_CP_DMA)) {
unmap_dma(i, ha);
SCpnt->host_scribble = NULL;
scmd_printk(KERN_INFO, SCpnt, "qcomm, adapter busy.\n");
return 1;
}
ha->cp_stat[i] = IN_USE;
return 0;
}
int eata2x_eh_host_reset(struct scsi_cmnd *SCarg)
{
unsigned int i, time, k, c, limit = 0;
int arg_done = 0;
struct scsi_cmnd *SCpnt;
struct Scsi_Host *shost = SCarg->device->host;
struct hostdata *ha = (struct hostdata *)shost->hostdata;
scmd_printk(KERN_INFO, SCarg, "reset, enter.\n");
spin_lock_irq(shost->host_lock);
if (SCarg->host_scribble == NULL)
printk("%s: reset, inactive.\n", ha->board_name);
if (ha->in_reset) {
printk("%s: reset, exit, already in reset.\n", ha->board_name);
spin_unlock_irq(shost->host_lock);
return FAILED;
}
if (wait_on_busy(shost->io_port, MAXLOOP)) {
printk("%s: reset, exit, timeout error.\n", ha->board_name);
spin_unlock_irq(shost->host_lock);
return FAILED;
}
ha->retries = 0;
for (c = 0; c <= shost->max_channel; c++)
for (k = 0; k < shost->max_id; k++) {
ha->target_redo[k][c] = 1;
ha->target_to[k][c] = 0;
}
for (i = 0; i < shost->can_queue; i++) {
if (ha->cp_stat[i] == FREE)
continue;
if (ha->cp_stat[i] == LOCKED) {
ha->cp_stat[i] = FREE;
printk("%s: reset, locked mbox %d forced free.\n",
ha->board_name, i);
continue;
}
if (!(SCpnt = ha->cp[i].SCpnt))
panic("%s: reset, mbox %d, SCpnt == NULL.\n", ha->board_name, i);
if (ha->cp_stat[i] == READY || ha->cp_stat[i] == ABORTING) {
ha->cp_stat[i] = ABORTING;
printk("%s: reset, mbox %d aborting.\n",
ha->board_name, i);
}
else {
ha->cp_stat[i] = IN_RESET;
printk("%s: reset, mbox %d in reset.\n",
ha->board_name, i);
}
if (SCpnt->host_scribble == NULL)
panic("%s: reset, mbox %d, garbled SCpnt.\n", ha->board_name, i);
if (*(unsigned int *)SCpnt->host_scribble != i)
panic("%s: reset, mbox %d, index mismatch.\n", ha->board_name, i);
if (SCpnt->scsi_done == NULL)
panic("%s: reset, mbox %d, SCpnt->scsi_done == NULL.\n",
ha->board_name, i);
if (SCpnt == SCarg)
arg_done = 1;
}
if (do_dma(shost->io_port, 0, RESET_PIO)) {
printk("%s: reset, cannot reset, timeout error.\n", ha->board_name);
spin_unlock_irq(shost->host_lock);
return FAILED;
}
printk("%s: reset, board reset done, enabling interrupts.\n", ha->board_name);
#if defined(DEBUG_RESET)
do_trace = 1;
#endif
ha->in_reset = 1;
spin_unlock_irq(shost->host_lock);
time = jiffies;
while ((jiffies - time) < (10 * HZ) && limit++ < 200000)
udelay(100L);
spin_lock_irq(shost->host_lock);
printk("%s: reset, interrupts disabled, loops %d.\n", ha->board_name, limit);
for (i = 0; i < shost->can_queue; i++) {
if (ha->cp_stat[i] == IN_RESET) {
SCpnt = ha->cp[i].SCpnt;
unmap_dma(i, ha);
SCpnt->result = DID_RESET << 16;
SCpnt->host_scribble = NULL;
ha->cp_stat[i] = LOCKED;
printk
("%s, reset, mbox %d locked, DID_RESET, done.\n",
ha->board_name, i);
}
else if (ha->cp_stat[i] == ABORTING) {
SCpnt = ha->cp[i].SCpnt;
unmap_dma(i, ha);
SCpnt->result = DID_RESET << 16;
SCpnt->host_scribble = NULL;
ha->cp_stat[i] = FREE;
printk
("%s, reset, mbox %d aborting, DID_RESET, done.\n",
ha->board_name, i);
}
else
continue;
SCpnt->scsi_done(SCpnt);
}
ha->in_reset = 0;
do_trace = 0;
if (arg_done)
printk("%s: reset, exit, done.\n", ha->board_name);
else
printk("%s: reset, exit.\n", ha->board_name);
spin_unlock_irq(shost->host_lock);
return SUCCESS;
}
int eata2x_bios_param(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int *dkinfo)
{
unsigned int size = capacity;
if (ext_tran || (scsicam_bios_param(bdev, capacity, dkinfo) < 0)) {
dkinfo[0] = 255;
dkinfo[1] = 63;
dkinfo[2] = size / (dkinfo[0] * dkinfo[1]);
}
#if defined (DEBUG_GEOMETRY)
printk("%s: bios_param, head=%d, sec=%d, cyl=%d.\n", driver_name,
dkinfo[0], dkinfo[1], dkinfo[2]);
#endif
return 0;
}
static void sort(unsigned long sk[], unsigned int da[], unsigned int n,
unsigned int rev)
{
unsigned int i, j, k, y;
unsigned long x;
for (i = 0; i < n - 1; i++) {
k = i;
for (j = k + 1; j < n; j++)
if (rev) {
if (sk[j] > sk[k])
k = j;
} else {
if (sk[j] < sk[k])
k = j;
}
if (k != i) {
x = sk[k];
sk[k] = sk[i];
sk[i] = x;
y = da[k];
da[k] = da[i];
da[i] = y;
}
}
return;
}
static int reorder(struct hostdata *ha, unsigned long cursec,
unsigned int ihdlr, unsigned int il[], unsigned int n_ready)
{
struct scsi_cmnd *SCpnt;
struct mscp *cpp;
unsigned int k, n;
unsigned int rev = 0, s = 1, r = 1;
unsigned int input_only = 1, overlap = 0;
unsigned long sl[n_ready], pl[n_ready], ll[n_ready];
unsigned long maxsec = 0, minsec = ULONG_MAX, seek = 0, iseek = 0;
unsigned long ioseek = 0;
static unsigned int flushcount = 0, batchcount = 0, sortcount = 0;
static unsigned int readycount = 0, ovlcount = 0, inputcount = 0;
static unsigned int readysorted = 0, revcount = 0;
static unsigned long seeksorted = 0, seeknosort = 0;
if (link_statistics && !(++flushcount % link_statistics))
printk("fc %d bc %d ic %d oc %d rc %d rs %d sc %d re %d"
" av %ldK as %ldK.\n", flushcount, batchcount,
inputcount, ovlcount, readycount, readysorted, sortcount,
revcount, seeknosort / (readycount + 1),
seeksorted / (readycount + 1));
if (n_ready <= 1)
return 0;
for (n = 0; n < n_ready; n++) {
k = il[n];
cpp = &ha->cp[k];
SCpnt = cpp->SCpnt;
if (!cpp->din)
input_only = 0;
if (blk_rq_pos(SCpnt->request) < minsec)
minsec = blk_rq_pos(SCpnt->request);
if (blk_rq_pos(SCpnt->request) > maxsec)
maxsec = blk_rq_pos(SCpnt->request);
sl[n] = blk_rq_pos(SCpnt->request);
ioseek += blk_rq_sectors(SCpnt->request);
if (!n)
continue;
if (sl[n] < sl[n - 1])
s = 0;
if (sl[n] > sl[n - 1])
r = 0;
if (link_statistics) {
if (sl[n] > sl[n - 1])
seek += sl[n] - sl[n - 1];
else
seek += sl[n - 1] - sl[n];
}
}
if (link_statistics) {
if (cursec > sl[0])
seek += cursec - sl[0];
else
seek += sl[0] - cursec;
}
if (cursec > ((maxsec + minsec) / 2))
rev = 1;
if (ioseek > ((maxsec - minsec) / 2))
rev = 0;
if (!((rev && r) || (!rev && s)))
sort(sl, il, n_ready, rev);
if (!input_only)
for (n = 0; n < n_ready; n++) {
k = il[n];
cpp = &ha->cp[k];
SCpnt = cpp->SCpnt;
ll[n] = blk_rq_sectors(SCpnt->request);
pl[n] = SCpnt->serial_number;
if (!n)
continue;
if ((sl[n] == sl[n - 1])
|| (!rev && ((sl[n - 1] + ll[n - 1]) > sl[n]))
|| (rev && ((sl[n] + ll[n]) > sl[n - 1])))
overlap = 1;
}
if (overlap)
sort(pl, il, n_ready, 0);
if (link_statistics) {
if (cursec > sl[0])
iseek = cursec - sl[0];
else
iseek = sl[0] - cursec;
batchcount++;
readycount += n_ready;
seeknosort += seek / 1024;
if (input_only)
inputcount++;
if (overlap) {
ovlcount++;
seeksorted += iseek / 1024;
} else
seeksorted += (iseek + maxsec - minsec) / 1024;
if (rev && !r) {
revcount++;
readysorted += n_ready;
}
if (!rev && !s) {
sortcount++;
readysorted += n_ready;
}
}
#if defined(DEBUG_LINKED_COMMANDS)
if (link_statistics && (overlap || !(flushcount % link_statistics)))
for (n = 0; n < n_ready; n++) {
k = il[n];
cpp = &ha->cp[k];
SCpnt = cpp->SCpnt;
scmd_printk(KERN_INFO, SCpnt,
"%s mb %d fc %d nr %d sec %ld ns %u"
" cur %ld s:%c r:%c rev:%c in:%c ov:%c xd %d.\n",
(ihdlr ? "ihdlr" : "qcomm"),
k, flushcount,
n_ready, blk_rq_pos(SCpnt->request),
blk_rq_sectors(SCpnt->request), cursec, YESNO(s),
YESNO(r), YESNO(rev), YESNO(input_only),
YESNO(overlap), cpp->din);
}
#endif
return overlap;
}
static void flush_dev(struct scsi_device *dev, unsigned long cursec,
struct hostdata *ha, unsigned int ihdlr)
{
struct scsi_cmnd *SCpnt;
struct mscp *cpp;
unsigned int k, n, n_ready = 0, il[MAX_MAILBOXES];
for (k = 0; k < dev->host->can_queue; k++) {
if (ha->cp_stat[k] != READY && ha->cp_stat[k] != IN_USE)
continue;
cpp = &ha->cp[k];
SCpnt = cpp->SCpnt;
if (SCpnt->device != dev)
continue;
if (ha->cp_stat[k] == IN_USE)
return;
il[n_ready++] = k;
}
if (reorder(ha, cursec, ihdlr, il, n_ready))
n_ready = 1;
for (n = 0; n < n_ready; n++) {
k = il[n];
cpp = &ha->cp[k];
SCpnt = cpp->SCpnt;
if (do_dma(dev->host->io_port, cpp->cp_dma_addr, SEND_CP_DMA)) {
scmd_printk(KERN_INFO, SCpnt,
"%s, mbox %d, adapter"
" busy, will abort.\n",
(ihdlr ? "ihdlr" : "qcomm"),
k);
ha->cp_stat[k] = ABORTING;
continue;
}
ha->cp_stat[k] = IN_USE;
}
}
static irqreturn_t ihdlr(struct Scsi_Host *shost)
{
struct scsi_cmnd *SCpnt;
unsigned int i, k, c, status, tstatus, reg;
struct mssp *spp;
struct mscp *cpp;
struct hostdata *ha = (struct hostdata *)shost->hostdata;
int irq = shost->irq;
if (!(inb(shost->io_port + REG_AUX_STATUS) & IRQ_ASSERTED))
goto none;
ha->iocount++;
if (do_trace)
printk("%s: ihdlr, enter, irq %d, count %d.\n", ha->board_name, irq,
ha->iocount);
if (wait_on_busy(shost->io_port, 20 * MAXLOOP)) {
reg = inb(shost->io_port + REG_STATUS);
printk
("%s: ihdlr, busy timeout error, irq %d, reg 0x%x, count %d.\n",
ha->board_name, irq, reg, ha->iocount);
goto none;
}
spp = &ha->sp;
memcpy(spp, ha->sp_cpu_addr, sizeof(struct mssp));
memset(ha->sp_cpu_addr, 0, sizeof(struct mssp));
reg = inb(shost->io_port + REG_STATUS);
#if defined (DEBUG_INTERRUPT)
{
unsigned char *bytesp;
int cnt;
bytesp = (unsigned char *)spp;
if (ha->iocount < 200) {
printk("sp[] =");
for (cnt = 0; cnt < 15; cnt++)
printk(" 0x%x", bytesp[cnt]);
printk("\n");
}
}
#endif
if (spp->eoc == 0 && ha->iocount > 1)
printk
("%s: ihdlr, spp->eoc == 0, irq %d, reg 0x%x, count %d.\n",
ha->board_name, irq, reg, ha->iocount);
if (spp->cpp_index < 0 || spp->cpp_index >= shost->can_queue)
printk
("%s: ihdlr, bad spp->cpp_index %d, irq %d, reg 0x%x, count %d.\n",
ha->board_name, spp->cpp_index, irq, reg, ha->iocount);
if (spp->eoc == 0 || spp->cpp_index < 0
|| spp->cpp_index >= shost->can_queue)
goto handled;
i = spp->cpp_index;
cpp = &(ha->cp[i]);
#if defined(DEBUG_GENERATE_ABORTS)
if ((ha->iocount > 500) && ((ha->iocount % 500) < 3))
goto handled;
#endif
if (ha->cp_stat[i] == IGNORE) {
ha->cp_stat[i] = FREE;
goto handled;
} else if (ha->cp_stat[i] == LOCKED) {
ha->cp_stat[i] = FREE;
printk("%s: ihdlr, mbox %d unlocked, count %d.\n", ha->board_name, i,
ha->iocount);
goto handled;
} else if (ha->cp_stat[i] == FREE) {
printk("%s: ihdlr, mbox %d is free, count %d.\n", ha->board_name, i,
ha->iocount);
goto handled;
} else if (ha->cp_stat[i] == IN_RESET)
printk("%s: ihdlr, mbox %d is in reset.\n", ha->board_name, i);
else if (ha->cp_stat[i] != IN_USE)
panic("%s: ihdlr, mbox %d, invalid cp_stat: %d.\n",
ha->board_name, i, ha->cp_stat[i]);
ha->cp_stat[i] = FREE;
SCpnt = cpp->SCpnt;
if (SCpnt == NULL)
panic("%s: ihdlr, mbox %d, SCpnt == NULL.\n", ha->board_name, i);
if (SCpnt->host_scribble == NULL)
panic("%s: ihdlr, mbox %d, SCpnt %p garbled.\n", ha->board_name,
i, SCpnt);
if (*(unsigned int *)SCpnt->host_scribble != i)
panic("%s: ihdlr, mbox %d, index mismatch %d.\n",
ha->board_name, i,
*(unsigned int *)SCpnt->host_scribble);
sync_dma(i, ha);
if (linked_comm && SCpnt->device->queue_depth > 2
&& TLDEV(SCpnt->device->type))
flush_dev(SCpnt->device, blk_rq_pos(SCpnt->request), ha, 1);
tstatus = status_byte(spp->target_status);
#if defined(DEBUG_GENERATE_ERRORS)
if ((ha->iocount > 500) && ((ha->iocount % 200) < 2))
spp->adapter_status = 0x01;
#endif
switch (spp->adapter_status) {
case ASOK:
if (tstatus == BUSY && SCpnt->device->type != TYPE_TAPE)
status = DID_ERROR << 16;
else if (tstatus != GOOD && SCpnt->device->type == TYPE_DISK
&& ha->target_redo[SCpnt->device->id][SCpnt->
device->
channel])
status = DID_BUS_BUSY << 16;
else if (tstatus == CHECK_CONDITION
&& SCpnt->device->type == TYPE_DISK
&& (SCpnt->sense_buffer[2] & 0xf) == RECOVERED_ERROR)
status = DID_BUS_BUSY << 16;
else
status = DID_OK << 16;
if (tstatus == GOOD)
ha->target_redo[SCpnt->device->id][SCpnt->device->
channel] = 0;
if (spp->target_status && SCpnt->device->type == TYPE_DISK &&
(!(tstatus == CHECK_CONDITION && ha->iocount <= 1000 &&
(SCpnt->sense_buffer[2] & 0xf) == NOT_READY)))
printk("%s: ihdlr, target %d.%d:%d, "
"target_status 0x%x, sense key 0x%x.\n",
ha->board_name,
SCpnt->device->channel, SCpnt->device->id,
(u8)SCpnt->device->lun,
spp->target_status, SCpnt->sense_buffer[2]);
ha->target_to[SCpnt->device->id][SCpnt->device->channel] = 0;
if (ha->last_retried_pid == SCpnt->serial_number)
ha->retries = 0;
break;
case ASST:
case 0x02:
if (ha->target_to[SCpnt->device->id][SCpnt->device->channel] > 1)
status = DID_ERROR << 16;
else {
status = DID_TIME_OUT << 16;
ha->target_to[SCpnt->device->id][SCpnt->device->
channel]++;
}
break;
case 0x03:
case 0x04:
for (c = 0; c <= shost->max_channel; c++)
for (k = 0; k < shost->max_id; k++)
ha->target_redo[k][c] = 1;
if (SCpnt->device->type != TYPE_TAPE
&& ha->retries < MAX_INTERNAL_RETRIES) {
#if defined(DID_SOFT_ERROR)
status = DID_SOFT_ERROR << 16;
#else
status = DID_BUS_BUSY << 16;
#endif
ha->retries++;
ha->last_retried_pid = SCpnt->serial_number;
} else
status = DID_ERROR << 16;
break;
case 0x05:
case 0x06:
case 0x07:
case 0x08:
case 0x09:
case 0x0a:
case 0x0b:
case 0x0c:
default:
status = DID_ERROR << 16;
break;
}
SCpnt->result = status | spp->target_status;
#if defined(DEBUG_INTERRUPT)
if (SCpnt->result || do_trace)
#else
if ((spp->adapter_status != ASOK && ha->iocount > 1000) ||
(spp->adapter_status != ASOK &&
spp->adapter_status != ASST && ha->iocount <= 1000) ||
do_trace || msg_byte(spp->target_status))
#endif
scmd_printk(KERN_INFO, SCpnt, "ihdlr, mbox %2d, err 0x%x:%x,"
" reg 0x%x, count %d.\n",
i, spp->adapter_status, spp->target_status,
reg, ha->iocount);
unmap_dma(i, ha);
SCpnt->host_scribble = NULL;
SCpnt->scsi_done(SCpnt);
if (do_trace)
printk("%s: ihdlr, exit, irq %d, count %d.\n", ha->board_name,
irq, ha->iocount);
handled:
return IRQ_HANDLED;
none:
return IRQ_NONE;
}
static irqreturn_t do_interrupt_handler(int dummy, void *shap)
{
struct Scsi_Host *shost;
unsigned int j;
unsigned long spin_flags;
irqreturn_t ret;
if ((j = (unsigned int)((char *)shap - sha)) >= num_boards)
return IRQ_NONE;
shost = sh[j];
spin_lock_irqsave(shost->host_lock, spin_flags);
ret = ihdlr(shost);
spin_unlock_irqrestore(shost->host_lock, spin_flags);
return ret;
}
static int eata2x_release(struct Scsi_Host *shost)
{
struct hostdata *ha = (struct hostdata *)shost->hostdata;
unsigned int i;
for (i = 0; i < shost->can_queue; i++)
kfree((&ha->cp[i])->sglist);
for (i = 0; i < shost->can_queue; i++)
pci_unmap_single(ha->pdev, ha->cp[i].cp_dma_addr,
sizeof(struct mscp), PCI_DMA_BIDIRECTIONAL);
if (ha->sp_cpu_addr)
pci_free_consistent(ha->pdev, sizeof(struct mssp),
ha->sp_cpu_addr, ha->sp_dma_addr);
free_irq(shost->irq, &sha[ha->board_number]);
if (shost->dma_channel != NO_DMA)
free_dma(shost->dma_channel);
release_region(shost->io_port, shost->n_io_port);
scsi_unregister(shost);
return 0;
}
