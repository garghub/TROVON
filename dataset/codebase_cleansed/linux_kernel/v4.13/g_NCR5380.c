static void g_NCR5380_trigger_irq(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
NCR5380_write(TARGET_COMMAND_REG,
PHASE_SR_TO_TCR(NCR5380_read(STATUS_REG) & PHASE_MASK));
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
NCR5380_write(OUTPUT_DATA_REG, hostdata->id_mask);
NCR5380_write(INITIATOR_COMMAND_REG,
ICR_BASE | ICR_ASSERT_DATA | ICR_ASSERT_SEL);
msleep(1);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(SELECT_ENABLE_REG, 0);
NCR5380_write(TARGET_COMMAND_REG, 0);
}
static int g_NCR5380_probe_irq(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int irq_mask, irq;
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
irq_mask = probe_irq_on();
g_NCR5380_trigger_irq(instance);
irq = probe_irq_off(irq_mask);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
if (irq <= 0)
return NO_IRQ;
return irq;
}
static void magic_configure(int idx, u8 irq, u8 magic[])
{
u8 cfg = 0;
outb(magic[0], 0x779);
outb(magic[1], 0x379);
outb(magic[2], 0x379);
outb(magic[3], 0x379);
outb(magic[4], 0x379);
if (irq == 9)
irq = 2;
if (idx >= 0 && idx <= 7)
cfg = 0x80 | idx | (irq << 4);
outb(cfg, 0x379);
}
static irqreturn_t legacy_empty_irq_handler(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static int legacy_find_free_irq(int *irq_table)
{
while (*irq_table != -1) {
if (!request_irq(*irq_table, legacy_empty_irq_handler,
IRQF_PROBE_SHARED, "Test IRQ",
(void *)irq_table)) {
free_irq(*irq_table, (void *) irq_table);
return *irq_table;
}
irq_table++;
}
return -1;
}
static int generic_NCR5380_init_one(struct scsi_host_template *tpnt,
struct device *pdev, int base, int irq, int board)
{
bool is_pmio = base <= 0xffff;
int ret;
int flags = 0;
unsigned int *ports = NULL;
u8 *magic = NULL;
int i;
int port_idx = -1;
unsigned long region_size;
struct Scsi_Host *instance;
struct NCR5380_hostdata *hostdata;
u8 __iomem *iomem;
switch (board) {
case BOARD_NCR5380:
flags = FLAG_NO_PSEUDO_DMA | FLAG_DMA_FIXUP;
break;
case BOARD_NCR53C400A:
ports = ncr_53c400a_ports;
magic = ncr_53c400a_magic;
break;
case BOARD_HP_C2502:
ports = ncr_53c400a_ports;
magic = hp_c2502_magic;
break;
case BOARD_DTC3181E:
ports = dtc_3181e_ports;
magic = ncr_53c400a_magic;
break;
}
if (is_pmio && ports && magic) {
magic_configure(-1, 0, magic);
region_size = 16;
if (base)
for (i = 0; ports[i]; i++) {
if (base == ports[i]) {
if (!request_region(ports[i],
region_size,
"ncr53c80"))
return -EBUSY;
break;
}
}
else
for (i = 0; ports[i]; i++) {
if (!request_region(ports[i], region_size,
"ncr53c80"))
continue;
if (inb(ports[i]) == 0xff)
break;
release_region(ports[i], region_size);
}
if (ports[i]) {
magic_configure(i, 0, magic);
base = ports[i];
outb(0xc0, base + 9);
if (inb(base + 9) != 0x80) {
ret = -ENODEV;
goto out_release;
}
port_idx = i;
} else
return -EINVAL;
} else if (is_pmio) {
region_size = 8;
if (!base || !request_region(base, region_size, "ncr5380"))
return -EBUSY;
} else {
region_size = NCR53C400_region_size;
if (!request_mem_region(base, region_size, "ncr5380"))
return -EBUSY;
}
if (is_pmio)
iomem = ioport_map(base, region_size);
else
iomem = ioremap(base, region_size);
if (!iomem) {
ret = -ENOMEM;
goto out_release;
}
instance = scsi_host_alloc(tpnt, sizeof(struct NCR5380_hostdata));
if (instance == NULL) {
ret = -ENOMEM;
goto out_unmap;
}
hostdata = shost_priv(instance);
hostdata->io = iomem;
hostdata->region_size = region_size;
if (is_pmio) {
hostdata->io_port = base;
hostdata->io_width = 1;
hostdata->offset = 0;
switch (board) {
case BOARD_NCR53C400:
hostdata->io_port += 8;
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
} else {
hostdata->base = base;
hostdata->offset = NCR53C400_mem_base;
switch (board) {
case BOARD_NCR53C400:
hostdata->c400_ctl_status = 0x100;
hostdata->c400_blk_cnt = 0x101;
hostdata->c400_host_buf = 0x104;
break;
case BOARD_DTC3181E:
case BOARD_NCR53C400A:
case BOARD_HP_C2502:
pr_err(DRV_MODULE_NAME ": unknown register offsets\n");
ret = -EINVAL;
goto out_unregister;
}
}
NCR5380_write(MODE_REG, 0);
if (NCR5380_read(MODE_REG) != 0) {
ret = -ENODEV;
goto out_unregister;
}
ret = NCR5380_init(instance, flags | FLAG_LATE_DMA_SETUP);
if (ret)
goto out_unregister;
switch (board) {
case BOARD_NCR53C400:
case BOARD_DTC3181E:
case BOARD_NCR53C400A:
case BOARD_HP_C2502:
NCR5380_write(hostdata->c400_ctl_status, CSR_BASE);
}
NCR5380_maybe_reset_bus(instance);
if (irq == 255 || irq == 0)
irq = NO_IRQ;
else if (irq == -1)
irq = IRQ_AUTO;
if (board == BOARD_HP_C2502) {
int *irq_table = hp_c2502_irqs;
int board_irq = -1;
switch (irq) {
case NO_IRQ:
board_irq = 0;
break;
case IRQ_AUTO:
board_irq = legacy_find_free_irq(irq_table);
break;
default:
while (*irq_table != -1)
if (*irq_table++ == irq)
board_irq = irq;
}
if (board_irq <= 0) {
board_irq = 0;
irq = NO_IRQ;
}
magic_configure(port_idx, board_irq, magic);
}
if (irq == IRQ_AUTO) {
instance->irq = g_NCR5380_probe_irq(instance);
if (instance->irq == NO_IRQ)
shost_printk(KERN_INFO, instance, "no irq detected\n");
} else {
instance->irq = irq;
if (instance->irq == NO_IRQ)
shost_printk(KERN_INFO, instance, "no irq provided\n");
}
if (instance->irq != NO_IRQ) {
if (request_irq(instance->irq, generic_NCR5380_intr,
0, "NCR5380", instance)) {
instance->irq = NO_IRQ;
shost_printk(KERN_INFO, instance,
"irq %d denied\n", instance->irq);
} else {
shost_printk(KERN_INFO, instance,
"irq %d acquired\n", instance->irq);
}
}
ret = scsi_add_host(instance, pdev);
if (ret)
goto out_free_irq;
scsi_scan_host(instance);
dev_set_drvdata(pdev, instance);
return 0;
out_free_irq:
if (instance->irq != NO_IRQ)
free_irq(instance->irq, instance);
NCR5380_exit(instance);
out_unregister:
scsi_host_put(instance);
out_unmap:
iounmap(iomem);
out_release:
if (is_pmio)
release_region(base, region_size);
else
release_mem_region(base, region_size);
return ret;
}
static void generic_NCR5380_release_resources(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
void __iomem *iomem = hostdata->io;
unsigned long io_port = hostdata->io_port;
unsigned long base = hostdata->base;
unsigned long region_size = hostdata->region_size;
scsi_remove_host(instance);
if (instance->irq != NO_IRQ)
free_irq(instance->irq, instance);
NCR5380_exit(instance);
scsi_host_put(instance);
iounmap(iomem);
if (io_port)
release_region(io_port, region_size);
else
release_mem_region(base, region_size);
}
static inline int generic_NCR5380_pread(struct NCR5380_hostdata *hostdata,
unsigned char *dst, int len)
{
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
if (hostdata->io_port && hostdata->io_width == 2)
insw(hostdata->io_port + hostdata->c400_host_buf,
dst + start, 64);
else if (hostdata->io_port)
insb(hostdata->io_port + hostdata->c400_host_buf,
dst + start, 128);
else
memcpy_fromio(dst + start,
hostdata->io + NCR53C400_host_buffer, 128);
start += 128;
blocks--;
}
if (blocks) {
while (NCR5380_read(hostdata->c400_ctl_status) & CSR_HOST_BUF_NOT_RDY)
;
if (hostdata->io_port && hostdata->io_width == 2)
insw(hostdata->io_port + hostdata->c400_host_buf,
dst + start, 64);
else if (hostdata->io_port)
insb(hostdata->io_port + hostdata->c400_host_buf,
dst + start, 128);
else
memcpy_fromio(dst + start,
hostdata->io + NCR53C400_host_buffer, 128);
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
static inline int generic_NCR5380_pwrite(struct NCR5380_hostdata *hostdata,
unsigned char *src, int len)
{
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
if (hostdata->io_port && hostdata->io_width == 2)
outsw(hostdata->io_port + hostdata->c400_host_buf,
src + start, 64);
else if (hostdata->io_port)
outsb(hostdata->io_port + hostdata->c400_host_buf,
src + start, 128);
else
memcpy_toio(hostdata->io + NCR53C400_host_buffer,
src + start, 128);
start += 128;
blocks--;
}
if (blocks) {
while (NCR5380_read(hostdata->c400_ctl_status) & CSR_HOST_BUF_NOT_RDY)
;
if (hostdata->io_port && hostdata->io_width == 2)
outsw(hostdata->io_port + hostdata->c400_host_buf,
src + start, 64);
else if (hostdata->io_port)
outsb(hostdata->io_port + hostdata->c400_host_buf,
src + start, 128);
else
memcpy_toio(hostdata->io + NCR53C400_host_buffer,
src + start, 128);
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
static int generic_NCR5380_dma_xfer_len(struct NCR5380_hostdata *hostdata,
struct scsi_cmnd *cmd)
{
int transfersize = cmd->transfersize;
if (hostdata->flags & FLAG_NO_PSEUDO_DMA)
return 0;
if (transfersize > 32 * 1024 && cmd->SCp.this_residual &&
!(cmd->SCp.this_residual % transfersize))
transfersize = 32 * 1024;
if (transfersize % 128)
transfersize = 0;
return transfersize;
}
static int generic_NCR5380_isa_match(struct device *pdev, unsigned int ndev)
{
int ret = generic_NCR5380_init_one(&driver_template, pdev, base[ndev],
irq[ndev], card[ndev]);
if (ret) {
if (base[ndev])
printk(KERN_WARNING "Card not found at address 0x%03x\n",
base[ndev]);
return 0;
}
return 1;
}
static int generic_NCR5380_isa_remove(struct device *pdev,
unsigned int ndev)
{
generic_NCR5380_release_resources(dev_get_drvdata(pdev));
dev_set_drvdata(pdev, NULL);
return 0;
}
static int generic_NCR5380_pnp_probe(struct pnp_dev *pdev,
const struct pnp_device_id *id)
{
int base, irq;
if (pnp_activate_dev(pdev) < 0)
return -EBUSY;
base = pnp_port_start(pdev, 0);
irq = pnp_irq(pdev, 0);
return generic_NCR5380_init_one(&driver_template, &pdev->dev, base, irq,
id->driver_data);
}
static void generic_NCR5380_pnp_remove(struct pnp_dev *pdev)
{
generic_NCR5380_release_resources(pnp_get_drvdata(pdev));
pnp_set_drvdata(pdev, NULL);
}
static int __init generic_NCR5380_init(void)
{
int ret = 0;
if (irq[0] == -1 && base[0] == 0 && card[0] == -1) {
irq[0] = ncr_irq;
base[0] = ncr_addr;
if (ncr_5380)
card[0] = BOARD_NCR5380;
if (ncr_53c400)
card[0] = BOARD_NCR53C400;
if (ncr_53c400a)
card[0] = BOARD_NCR53C400A;
if (dtc_3181e)
card[0] = BOARD_DTC3181E;
if (hp_c2502)
card[0] = BOARD_HP_C2502;
}
#ifdef CONFIG_PNP
if (!pnp_register_driver(&generic_NCR5380_pnp_driver))
pnp_registered = 1;
#endif
ret = isa_register_driver(&generic_NCR5380_isa_driver, MAX_CARDS);
if (!ret)
isa_registered = 1;
return (pnp_registered || isa_registered) ? 0 : ret;
}
static void __exit generic_NCR5380_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_driver(&generic_NCR5380_pnp_driver);
#endif
if (isa_registered)
isa_unregister_driver(&generic_NCR5380_isa_driver);
}
