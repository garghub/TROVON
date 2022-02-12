static void __init internal_setup(int board, char *str, int *ints)
{
static int commandline_current;
switch (board) {
case BOARD_NCR5380:
if (ints[0] != 2 && ints[0] != 3) {
printk(KERN_ERR "generic_NCR5380_setup : usage ncr5380=" STRVAL(NCR5380_map_name) ",irq,dma\n");
return;
}
break;
case BOARD_NCR53C400:
if (ints[0] != 2) {
printk(KERN_ERR "generic_NCR53C400_setup : usage ncr53c400=" STRVAL(NCR5380_map_name) ",irq\n");
return;
}
break;
case BOARD_NCR53C400A:
if (ints[0] != 2) {
printk(KERN_ERR "generic_NCR53C400A_setup : usage ncr53c400a=" STRVAL(NCR5380_map_name) ",irq\n");
return;
}
break;
case BOARD_DTC3181E:
if (ints[0] != 2) {
printk("generic_DTC3181E_setup : usage dtc3181e=" STRVAL(NCR5380_map_name) ",irq\n");
return;
}
break;
}
if (commandline_current < NO_OVERRIDES) {
overrides[commandline_current].NCR5380_map_name = (NCR5380_map_type) ints[1];
overrides[commandline_current].irq = ints[2];
if (ints[0] == 3)
overrides[commandline_current].dma = ints[3];
else
overrides[commandline_current].dma = DMA_NONE;
overrides[commandline_current].board = board;
++commandline_current;
}
}
static int __init do_NCR5380_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_NCR5380, str, ints);
return 1;
}
static int __init do_NCR53C400_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_NCR53C400, str, ints);
return 1;
}
static int __init do_NCR53C400A_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_NCR53C400A, str, ints);
return 1;
}
static int __init do_DTC3181E_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_DTC3181E, str, ints);
return 1;
}
static void magic_configure(int idx, u8 irq, u8 magic[])
{
u8 cfg = 0;
outb(magic[0], 0x779);
outb(magic[1], 0x379);
outb(magic[2], 0x379);
outb(magic[3], 0x379);
outb(magic[4], 0x379);
if (irq != 2 && irq != 3 && irq != 4 && irq != 5 && irq != 7)
irq = 0;
if (idx >= 0 && idx <= 7)
cfg = 0x80 | idx | (irq << 4);
outb(cfg, 0x379);
}
static int __init generic_NCR5380_detect(struct scsi_host_template *tpnt)
{
static int current_override;
int count;
unsigned int *ports;
u8 *magic = NULL;
#ifndef SCSI_G_NCR5380_MEM
int i;
int port_idx = -1;
unsigned long region_size = 16;
#endif
static unsigned int __initdata ncr_53c400a_ports[] = {
0x280, 0x290, 0x300, 0x310, 0x330, 0x340, 0x348, 0x350, 0
};
static unsigned int __initdata dtc_3181e_ports[] = {
0x220, 0x240, 0x280, 0x2a0, 0x2c0, 0x300, 0x320, 0x340, 0
};
static u8 ncr_53c400a_magic[] __initdata = {
0x59, 0xb9, 0xc5, 0xae, 0xa6
};
static u8 hp_c2502_magic[] __initdata = {
0x0f, 0x22, 0xf0, 0x20, 0x80
};
int flags;
struct Scsi_Host *instance;
struct NCR5380_hostdata *hostdata;
#ifdef SCSI_G_NCR5380_MEM
unsigned long base;
void __iomem *iomem;
#endif
if (ncr_irq)
overrides[0].irq = ncr_irq;
if (ncr_dma)
overrides[0].dma = ncr_dma;
if (ncr_addr)
overrides[0].NCR5380_map_name = (NCR5380_map_type) ncr_addr;
if (ncr_5380)
overrides[0].board = BOARD_NCR5380;
else if (ncr_53c400)
overrides[0].board = BOARD_NCR53C400;
else if (ncr_53c400a)
overrides[0].board = BOARD_NCR53C400A;
else if (dtc_3181e)
overrides[0].board = BOARD_DTC3181E;
else if (hp_c2502)
overrides[0].board = BOARD_HP_C2502;
#ifndef SCSI_G_NCR5380_MEM
if (!current_override && isapnp_present()) {
struct pnp_dev *dev = NULL;
count = 0;
while ((dev = pnp_find_dev(NULL, ISAPNP_VENDOR('D', 'T', 'C'), ISAPNP_FUNCTION(0x436e), dev))) {
if (count >= NO_OVERRIDES)
break;
if (pnp_device_attach(dev) < 0)
continue;
if (pnp_activate_dev(dev) < 0) {
printk(KERN_ERR "dtc436e probe: activate failed\n");
pnp_device_detach(dev);
continue;
}
if (!pnp_port_valid(dev, 0)) {
printk(KERN_ERR "dtc436e probe: no valid port\n");
pnp_device_detach(dev);
continue;
}
if (pnp_irq_valid(dev, 0))
overrides[count].irq = pnp_irq(dev, 0);
else
overrides[count].irq = NO_IRQ;
if (pnp_dma_valid(dev, 0))
overrides[count].dma = pnp_dma(dev, 0);
else
overrides[count].dma = DMA_NONE;
overrides[count].NCR5380_map_name = (NCR5380_map_type) pnp_port_start(dev, 0);
overrides[count].board = BOARD_DTC3181E;
count++;
}
}
#endif
for (count = 0; current_override < NO_OVERRIDES; ++current_override) {
if (!(overrides[current_override].NCR5380_map_name))
continue;
ports = NULL;
flags = 0;
switch (overrides[current_override].board) {
case BOARD_NCR5380:
flags = FLAG_NO_PSEUDO_DMA;
break;
case BOARD_NCR53C400:
#ifdef PSEUDO_DMA
flags = FLAG_NO_DMA_FIXUP;
#endif
break;
case BOARD_NCR53C400A:
flags = FLAG_NO_DMA_FIXUP;
ports = ncr_53c400a_ports;
magic = ncr_53c400a_magic;
break;
case BOARD_HP_C2502:
flags = FLAG_NO_DMA_FIXUP;
ports = ncr_53c400a_ports;
magic = hp_c2502_magic;
break;
case BOARD_DTC3181E:
flags = FLAG_NO_DMA_FIXUP;
ports = dtc_3181e_ports;
magic = ncr_53c400a_magic;
break;
}
#ifndef SCSI_G_NCR5380_MEM
if (ports && magic) {
magic_configure(-1, 0, magic);
if (overrides[current_override].NCR5380_map_name != PORT_AUTO)
for (i = 0; ports[i]; i++) {
if (!request_region(ports[i], 16, "ncr53c80"))
continue;
if (overrides[current_override].NCR5380_map_name == ports[i])
break;
release_region(ports[i], 16);
} else
for (i = 0; ports[i]; i++) {
if (!request_region(ports[i], 16, "ncr53c80"))
continue;
if (inb(ports[i]) == 0xff)
break;
release_region(ports[i], 16);
}
if (ports[i]) {
magic_configure(i, 0, magic);
outb(0xc0, ports[i] + 9);
if (inb(ports[i] + 9) != 0x80)
continue;
overrides[current_override].NCR5380_map_name = ports[i];
port_idx = i;
} else
continue;
}
else
{
if(!(request_region(overrides[current_override].NCR5380_map_name, NCR5380_region_size, "ncr5380")))
continue;
region_size = NCR5380_region_size;
}
#else
base = overrides[current_override].NCR5380_map_name;
if (!request_mem_region(base, NCR5380_region_size, "ncr5380"))
continue;
iomem = ioremap(base, NCR5380_region_size);
if (!iomem) {
release_mem_region(base, NCR5380_region_size);
continue;
}
#endif
instance = scsi_register(tpnt, sizeof(struct NCR5380_hostdata));
if (instance == NULL)
goto out_release;
hostdata = shost_priv(instance);
#ifndef SCSI_G_NCR5380_MEM
instance->io_port = overrides[current_override].NCR5380_map_name;
instance->n_io_port = region_size;
hostdata->io_width = 1;
switch (overrides[current_override].board) {
case BOARD_NCR53C400:
instance->io_port += 8;
hostdata->c400_ctl_status = 0;
hostdata->c400_blk_cnt = 1;
hostdata->c400_host_buf = 4;
break;
case BOARD_DTC3181E:
hostdata->io_width = 2;
case BOARD_NCR53C400A:
case BOARD_HP_C2502:
hostdata->c400_ctl_status = 9;
hostdata->c400_blk_cnt = 10;
hostdata->c400_host_buf = 8;
break;
}
#else
instance->base = overrides[current_override].NCR5380_map_name;
hostdata->iomem = iomem;
switch (overrides[current_override].board) {
case BOARD_NCR53C400:
hostdata->c400_ctl_status = 0x100;
hostdata->c400_blk_cnt = 0x101;
hostdata->c400_host_buf = 0x104;
break;
case BOARD_DTC3181E:
case BOARD_NCR53C400A:
case BOARD_HP_C2502:
pr_err(DRV_MODULE_NAME ": unknown register offsets\n");
goto out_unregister;
}
#endif
if (NCR5380_init(instance, flags))
goto out_unregister;
switch (overrides[current_override].board) {
case BOARD_NCR53C400:
case BOARD_DTC3181E:
case BOARD_NCR53C400A:
case BOARD_HP_C2502:
NCR5380_write(hostdata->c400_ctl_status, CSR_BASE);
}
NCR5380_maybe_reset_bus(instance);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, 0xffff);
if (instance->irq == 255)
instance->irq = NO_IRQ;
if (instance->irq != NO_IRQ) {
#ifndef SCSI_G_NCR5380_MEM
if (overrides[current_override].board == BOARD_HP_C2502)
magic_configure(port_idx, instance->irq, magic);
#endif
if (request_irq(instance->irq, generic_NCR5380_intr,
0, "NCR5380", instance)) {
printk(KERN_WARNING "scsi%d : IRQ%d not free, interrupts disabled\n", instance->host_no, instance->irq);
instance->irq = NO_IRQ;
}
}
if (instance->irq == NO_IRQ) {
printk(KERN_INFO "scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk(KERN_INFO "scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
}
++current_override;
++count;
}
return count;
out_unregister:
scsi_unregister(instance);
out_release:
#ifndef SCSI_G_NCR5380_MEM
release_region(overrides[current_override].NCR5380_map_name, region_size);
#else
iounmap(iomem);
release_mem_region(base, NCR5380_region_size);
#endif
return count;
}
static int generic_NCR5380_release_resources(struct Scsi_Host *instance)
{
if (instance->irq != NO_IRQ)
free_irq(instance->irq, instance);
NCR5380_exit(instance);
#ifndef SCSI_G_NCR5380_MEM
release_region(instance->io_port, instance->n_io_port);
#else
iounmap(((struct NCR5380_hostdata *)instance->hostdata)->iomem);
release_mem_region(instance->base, NCR5380_region_size);
#endif
return 0;
}
static int
generic_NCR5380_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int *ip)
{
ip[0] = 64;
ip[1] = 32;
ip[2] = capacity >> 11;
return 0;
}
static inline int NCR5380_pread(struct Scsi_Host *instance, unsigned char *dst, int len)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int blocks = len / 128;
int start = 0;
NCR5380_write(hostdata->c400_ctl_status, CSR_BASE | CSR_TRANS_DIR);
NCR5380_write(hostdata->c400_blk_cnt, blocks);
while (1) {
if (NCR5380_read(hostdata->c400_blk_cnt) == 0)
break;
if (NCR5380_read(hostdata->c400_ctl_status) & CSR_GATED_53C80_IRQ) {
printk(KERN_ERR "53C400r: Got 53C80_IRQ start=%d, blocks=%d\n", start, blocks);
return -1;
}
while (NCR5380_read(hostdata->c400_ctl_status) & CSR_HOST_BUF_NOT_RDY)
;
#ifndef SCSI_G_NCR5380_MEM
if (hostdata->io_width == 2)
insw(instance->io_port + hostdata->c400_host_buf,
dst + start, 64);
else
insb(instance->io_port + hostdata->c400_host_buf,
dst + start, 128);
#else
memcpy_fromio(dst + start,
hostdata->iomem + NCR53C400_host_buffer, 128);
#endif
start += 128;
blocks--;
}
if (blocks) {
while (NCR5380_read(hostdata->c400_ctl_status) & CSR_HOST_BUF_NOT_RDY)
;
#ifndef SCSI_G_NCR5380_MEM
if (hostdata->io_width == 2)
insw(instance->io_port + hostdata->c400_host_buf,
dst + start, 64);
else
insb(instance->io_port + hostdata->c400_host_buf,
dst + start, 128);
#else
memcpy_fromio(dst + start,
hostdata->iomem + NCR53C400_host_buffer, 128);
#endif
start += 128;
blocks--;
}
if (!(NCR5380_read(hostdata->c400_ctl_status) & CSR_GATED_53C80_IRQ))
printk("53C400r: no 53C80 gated irq after transfer");
while (!(NCR5380_read(hostdata->c400_ctl_status) & CSR_53C80_REG))
;
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_END_DMA_TRANSFER))
printk(KERN_ERR "53C400r: no end dma signal\n");
return 0;
}
static inline int NCR5380_pwrite(struct Scsi_Host *instance, unsigned char *src, int len)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int blocks = len / 128;
int start = 0;
NCR5380_write(hostdata->c400_ctl_status, CSR_BASE);
NCR5380_write(hostdata->c400_blk_cnt, blocks);
while (1) {
if (NCR5380_read(hostdata->c400_ctl_status) & CSR_GATED_53C80_IRQ) {
printk(KERN_ERR "53C400w: Got 53C80_IRQ start=%d, blocks=%d\n", start, blocks);
return -1;
}
if (NCR5380_read(hostdata->c400_blk_cnt) == 0)
break;
while (NCR5380_read(hostdata->c400_ctl_status) & CSR_HOST_BUF_NOT_RDY)
;
#ifndef SCSI_G_NCR5380_MEM
if (hostdata->io_width == 2)
outsw(instance->io_port + hostdata->c400_host_buf,
src + start, 64);
else
outsb(instance->io_port + hostdata->c400_host_buf,
src + start, 128);
#else
memcpy_toio(hostdata->iomem + NCR53C400_host_buffer,
src + start, 128);
#endif
start += 128;
blocks--;
}
if (blocks) {
while (NCR5380_read(hostdata->c400_ctl_status) & CSR_HOST_BUF_NOT_RDY)
;
#ifndef SCSI_G_NCR5380_MEM
if (hostdata->io_width == 2)
outsw(instance->io_port + hostdata->c400_host_buf,
src + start, 64);
else
outsb(instance->io_port + hostdata->c400_host_buf,
src + start, 128);
#else
memcpy_toio(hostdata->iomem + NCR53C400_host_buffer,
src + start, 128);
#endif
start += 128;
blocks--;
}
while (!(NCR5380_read(hostdata->c400_ctl_status) & CSR_53C80_REG)) {
udelay(4);
}
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_END_DMA_TRANSFER)) {
printk(KERN_ERR "53C400w: no end dma signal\n");
}
while (!(NCR5380_read(TARGET_COMMAND_REG) & TCR_LAST_BYTE_SENT))
;
return 0;
}
static int generic_NCR5380_dma_xfer_len(struct scsi_cmnd *cmd)
{
int transfersize = cmd->transfersize;
if (transfersize > 32 * 1024 && cmd->SCp.this_residual &&
!(cmd->SCp.this_residual % transfersize))
transfersize = 32 * 1024;
if (transfersize % 128)
transfersize = 0;
return transfersize;
}
