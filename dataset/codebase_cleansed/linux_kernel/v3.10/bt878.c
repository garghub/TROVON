static void bt878_mem_free(struct bt878 *bt)
{
if (bt->buf_cpu) {
pci_free_consistent(bt->dev, bt->buf_size, bt->buf_cpu,
bt->buf_dma);
bt->buf_cpu = NULL;
}
if (bt->risc_cpu) {
pci_free_consistent(bt->dev, bt->risc_size, bt->risc_cpu,
bt->risc_dma);
bt->risc_cpu = NULL;
}
}
static int bt878_mem_alloc(struct bt878 *bt)
{
if (!bt->buf_cpu) {
bt->buf_size = 128 * 1024;
bt->buf_cpu =
pci_alloc_consistent(bt->dev, bt->buf_size,
&bt->buf_dma);
if (!bt->buf_cpu)
return -ENOMEM;
memset(bt->buf_cpu, 0, bt->buf_size);
}
if (!bt->risc_cpu) {
bt->risc_size = PAGE_SIZE;
bt->risc_cpu =
pci_alloc_consistent(bt->dev, bt->risc_size,
&bt->risc_dma);
if (!bt->risc_cpu) {
bt878_mem_free(bt);
return -ENOMEM;
}
memset(bt->risc_cpu, 0, bt->risc_size);
}
return 0;
}
static int bt878_make_risc(struct bt878 *bt)
{
bt->block_bytes = bt->buf_size >> 4;
bt->block_count = 1 << 4;
bt->line_bytes = bt->block_bytes;
bt->line_count = bt->block_count;
while (bt->line_bytes > 4095) {
bt->line_bytes >>= 1;
bt->line_count <<= 1;
}
if (bt->line_count > 255) {
printk(KERN_ERR "bt878: buffer size error!\n");
return -EINVAL;
}
return 0;
}
static void bt878_risc_program(struct bt878 *bt, u32 op_sync_orin)
{
u32 buf_pos = 0;
u32 line;
RISC_FLUSH();
RISC_INSTR(RISC_SYNC | RISC_SYNC_FM1 | op_sync_orin);
RISC_INSTR(0);
dprintk("bt878: risc len lines %u, bytes per line %u\n",
bt->line_count, bt->line_bytes);
for (line = 0; line < bt->line_count; line++) {
if (!(buf_pos % bt->block_bytes))
RISC_INSTR(RISC_WRITE | RISC_WR_SOL | RISC_WR_EOL |
RISC_IRQ |
RISC_STATUS(((buf_pos /
bt->block_bytes) +
(bt->block_count -
1)) %
bt->block_count) | bt->
line_bytes);
else
RISC_INSTR(RISC_WRITE | RISC_WR_SOL | RISC_WR_EOL |
bt->line_bytes);
RISC_INSTR(bt->buf_dma + buf_pos);
buf_pos += bt->line_bytes;
}
RISC_INSTR(RISC_SYNC | op_sync_orin | RISC_SYNC_VRO);
RISC_INSTR(0);
RISC_INSTR(RISC_JUMP);
RISC_INSTR(bt->risc_dma);
btwrite((bt->line_count << 16) | bt->line_bytes, BT878_APACK_LEN);
}
void bt878_start(struct bt878 *bt, u32 controlreg, u32 op_sync_orin,
u32 irq_err_ignore)
{
u32 int_mask;
dprintk("bt878 debug: bt878_start (ctl=%8.8x)\n", controlreg);
bt878_risc_program(bt, op_sync_orin);
controlreg &= ~0x1f;
controlreg |= 0x1b;
btwrite(bt->risc_dma, BT878_ARISC_START);
int_mask = BT878_ASCERR | BT878_AOCERR | BT878_APABORT |
BT878_ARIPERR | BT878_APPERR | BT878_AFDSR | BT878_AFTRGT |
BT878_AFBUS | BT878_ARISCI;
int_mask &= ~irq_err_ignore;
btwrite(int_mask, BT878_AINT_MASK);
btwrite(controlreg, BT878_AGPIO_DMA_CTL);
}
void bt878_stop(struct bt878 *bt)
{
u32 stat;
int i = 0;
dprintk("bt878 debug: bt878_stop\n");
btwrite(0, BT878_AINT_MASK);
btand(~0x13, BT878_AGPIO_DMA_CTL);
do {
stat = btread(BT878_AINT_STAT);
if (!(stat & BT878_ARISC_EN))
break;
i++;
} while (i < 500);
dprintk("bt878(%d) debug: bt878_stop, i=%d, stat=0x%8.8x\n",
bt->nr, i, stat);
}
static irqreturn_t bt878_irq(int irq, void *dev_id)
{
u32 stat, astat, mask;
int count;
struct bt878 *bt;
bt = (struct bt878 *) dev_id;
count = 0;
while (1) {
stat = btread(BT878_AINT_STAT);
mask = btread(BT878_AINT_MASK);
if (!(astat = (stat & mask)))
return IRQ_NONE;
btwrite(astat, BT878_AINT_STAT);
if (astat & (BT878_ASCERR | BT878_AOCERR)) {
if (bt878_verbose) {
printk(KERN_INFO
"bt878(%d): irq%s%s risc_pc=%08x\n",
bt->nr,
(astat & BT878_ASCERR) ? " SCERR" :
"",
(astat & BT878_AOCERR) ? " OCERR" :
"", btread(BT878_ARISC_PC));
}
}
if (astat & (BT878_APABORT | BT878_ARIPERR | BT878_APPERR)) {
if (bt878_verbose) {
printk(KERN_INFO
"bt878(%d): irq%s%s%s risc_pc=%08x\n",
bt->nr,
(astat & BT878_APABORT) ? " PABORT" :
"",
(astat & BT878_ARIPERR) ? " RIPERR" :
"",
(astat & BT878_APPERR) ? " PPERR" :
"", btread(BT878_ARISC_PC));
}
}
if (astat & (BT878_AFDSR | BT878_AFTRGT | BT878_AFBUS)) {
if (bt878_verbose) {
printk(KERN_INFO
"bt878(%d): irq%s%s%s risc_pc=%08x\n",
bt->nr,
(astat & BT878_AFDSR) ? " FDSR" : "",
(astat & BT878_AFTRGT) ? " FTRGT" :
"",
(astat & BT878_AFBUS) ? " FBUS" : "",
btread(BT878_ARISC_PC));
}
}
if (astat & BT878_ARISCI) {
bt->finished_block = (stat & BT878_ARISCS) >> 28;
tasklet_schedule(&bt->tasklet);
break;
}
count++;
if (count > 20) {
btwrite(0, BT878_AINT_MASK);
printk(KERN_ERR
"bt878(%d): IRQ lockup, cleared int mask\n",
bt->nr);
break;
}
}
return IRQ_HANDLED;
}
int
bt878_device_control(struct bt878 *bt, unsigned int cmd, union dst_gpio_packet *mp)
{
int retval;
retval = 0;
if (mutex_lock_interruptible(&bt->gpio_lock))
return -ERESTARTSYS;
switch (cmd) {
case DST_IG_ENABLE:
retval = bttv_gpio_enable(bt->bttv_nr,
mp->enb.mask,
mp->enb.enable);
break;
case DST_IG_WRITE:
retval = bttv_write_gpio(bt->bttv_nr,
mp->outp.mask,
mp->outp.highvals);
break;
case DST_IG_READ:
retval = bttv_read_gpio(bt->bttv_nr, &mp->rd.value);
break;
case DST_IG_TS:
bt->TS_Size = mp->psize;
break;
default:
retval = -EINVAL;
break;
}
mutex_unlock(&bt->gpio_lock);
return retval;
}
static const char * card_name(const struct pci_device_id *id)
{
return id->driver_data ? (const char *)id->driver_data : "Unknown";
}
static int bt878_probe(struct pci_dev *dev, const struct pci_device_id *pci_id)
{
int result = 0;
unsigned char lat;
struct bt878 *bt;
#if defined(__powerpc__)
unsigned int cmd;
#endif
unsigned int cardid;
printk(KERN_INFO "bt878: Bt878 AUDIO function found (%d).\n",
bt878_num);
if (bt878_num >= BT878_MAX) {
printk(KERN_ERR "bt878: Too many devices inserted\n");
result = -ENOMEM;
goto fail0;
}
if (pci_enable_device(dev))
return -EIO;
cardid = dev->subsystem_device << 16;
cardid |= dev->subsystem_vendor;
printk(KERN_INFO "%s: card id=[0x%x],[ %s ] has DVB functions.\n",
__func__, cardid, card_name(pci_id));
bt = &bt878[bt878_num];
bt->dev = dev;
bt->nr = bt878_num;
bt->shutdown = 0;
bt->id = dev->device;
bt->irq = dev->irq;
bt->bt878_adr = pci_resource_start(dev, 0);
if (!request_mem_region(pci_resource_start(dev, 0),
pci_resource_len(dev, 0), "bt878")) {
result = -EBUSY;
goto fail0;
}
bt->revision = dev->revision;
pci_read_config_byte(dev, PCI_LATENCY_TIMER, &lat);
printk(KERN_INFO "bt878(%d): Bt%x (rev %d) at %02x:%02x.%x, ",
bt878_num, bt->id, bt->revision, dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
printk("irq: %d, latency: %d, memory: 0x%lx\n",
bt->irq, lat, bt->bt878_adr);
#if defined(__powerpc__)
pci_read_config_dword(dev, PCI_COMMAND, &cmd);
cmd = (cmd | PCI_COMMAND_MEMORY);
pci_write_config_dword(dev, PCI_COMMAND, cmd);
#endif
#ifdef __sparc__
bt->bt878_mem = (unsigned char *) bt->bt878_adr;
#else
bt->bt878_mem = ioremap(bt->bt878_adr, 0x1000);
#endif
btwrite(0, BT848_INT_MASK);
result = request_irq(bt->irq, bt878_irq,
IRQF_SHARED | IRQF_DISABLED, "bt878",
(void *) bt);
if (result == -EINVAL) {
printk(KERN_ERR "bt878(%d): Bad irq number or handler\n",
bt878_num);
goto fail1;
}
if (result == -EBUSY) {
printk(KERN_ERR
"bt878(%d): IRQ %d busy, change your PnP config in BIOS\n",
bt878_num, bt->irq);
goto fail1;
}
if (result < 0)
goto fail1;
pci_set_master(dev);
pci_set_drvdata(dev, bt);
if ((result = bt878_mem_alloc(bt))) {
printk(KERN_ERR "bt878: failed to allocate memory!\n");
goto fail2;
}
bt878_make_risc(bt);
btwrite(0, BT878_AINT_MASK);
bt878_num++;
return 0;
fail2:
free_irq(bt->irq, bt);
fail1:
release_mem_region(pci_resource_start(bt->dev, 0),
pci_resource_len(bt->dev, 0));
fail0:
pci_disable_device(dev);
return result;
}
static void bt878_remove(struct pci_dev *pci_dev)
{
u8 command;
struct bt878 *bt = pci_get_drvdata(pci_dev);
if (bt878_verbose)
printk(KERN_INFO "bt878(%d): unloading\n", bt->nr);
btand(~0x13, BT878_AGPIO_DMA_CTL);
btwrite(0, BT878_AINT_MASK);
btwrite(~0U, BT878_AINT_STAT);
pci_read_config_byte(bt->dev, PCI_COMMAND, &command);
command &= ~PCI_COMMAND_MASTER;
pci_write_config_byte(bt->dev, PCI_COMMAND, command);
free_irq(bt->irq, bt);
printk(KERN_DEBUG "bt878_mem: 0x%p.\n", bt->bt878_mem);
if (bt->bt878_mem)
iounmap(bt->bt878_mem);
release_mem_region(pci_resource_start(bt->dev, 0),
pci_resource_len(bt->dev, 0));
bt->shutdown = 1;
bt878_mem_free(bt);
pci_set_drvdata(pci_dev, NULL);
pci_disable_device(pci_dev);
return;
}
static int __init bt878_init_module(void)
{
bt878_num = 0;
printk(KERN_INFO "bt878: AUDIO driver version %d.%d.%d loaded\n",
(BT878_VERSION_CODE >> 16) & 0xff,
(BT878_VERSION_CODE >> 8) & 0xff,
BT878_VERSION_CODE & 0xff);
return pci_register_driver(&bt878_pci_driver);
}
static void __exit bt878_cleanup_module(void)
{
pci_unregister_driver(&bt878_pci_driver);
}
