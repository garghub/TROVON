static fasdmatype_t
arxescsi_dma_setup(struct Scsi_Host *host, struct scsi_pointer *SCp,
fasdmadir_t direction, fasdmatype_t min_type)
{
return fasdma_pseudo;
}
static void arxescsi_pseudo_dma_write(unsigned char *addr, void __iomem *base)
{
__asm__ __volatile__(
" stmdb sp!, {r0-r12}\n"
" mov r3, %0\n"
" mov r1, %1\n"
" add r2, r1, #512\n"
" mov r4, #256\n"
".loop_1: ldmia r3!, {r6, r8, r10, r12}\n"
" mov r5, r6, lsl #16\n"
" mov r7, r8, lsl #16\n"
".loop_2: ldrb r0, [r1, #1536]\n"
" tst r0, #1\n"
" beq .loop_2\n"
" stmia r2, {r5-r8}\n\t"
" mov r9, r10, lsl #16\n"
" mov r11, r12, lsl #16\n"
".loop_3: ldrb r0, [r1, #1536]\n"
" tst r0, #1\n"
" beq .loop_3\n"
" stmia r2, {r9-r12}\n"
" subs r4, r4, #16\n"
" bne .loop_1\n"
" ldmia sp!, {r0-r12}\n"
:
: "r" (addr), "r" (base));
}
static void
arxescsi_dma_pseudo(struct Scsi_Host *host, struct scsi_pointer *SCp,
fasdmadir_t direction, int transfer)
{
struct arxescsi_info *info = (struct arxescsi_info *)host->hostdata;
unsigned int length, error = 0;
void __iomem *base = info->info.scsi.io_base;
unsigned char *addr;
length = SCp->this_residual;
addr = SCp->ptr;
if (direction == DMA_OUT) {
unsigned int word;
while (length > 256) {
if (readb(base + 0x80) & STAT_INT) {
error = 1;
break;
}
arxescsi_pseudo_dma_write(addr, base);
addr += 256;
length -= 256;
}
if (!error)
while (length > 0) {
if (readb(base + 0x80) & STAT_INT)
break;
if (!(readb(base + DMASTAT_OFFSET) & DMASTAT_DRQ))
continue;
word = *addr | *(addr + 1) << 8;
writew(word, base + DMADATA_OFFSET);
if (length > 1) {
addr += 2;
length -= 2;
} else {
addr += 1;
length -= 1;
}
}
}
else {
if (transfer && (transfer & 255)) {
while (length >= 256) {
if (readb(base + 0x80) & STAT_INT) {
error = 1;
break;
}
if (!(readb(base + DMASTAT_OFFSET) & DMASTAT_DRQ))
continue;
readsw(base + DMADATA_OFFSET, addr, 256 >> 1);
addr += 256;
length -= 256;
}
}
if (!(error))
while (length > 0) {
unsigned long word;
if (readb(base + 0x80) & STAT_INT)
break;
if (!(readb(base + DMASTAT_OFFSET) & DMASTAT_DRQ))
continue;
word = readw(base + DMADATA_OFFSET);
*addr++ = word;
if (--length > 0) {
*addr++ = word >> 8;
length --;
}
}
}
}
static void arxescsi_dma_stop(struct Scsi_Host *host, struct scsi_pointer *SCp)
{
}
static const char *arxescsi_info(struct Scsi_Host *host)
{
struct arxescsi_info *info = (struct arxescsi_info *)host->hostdata;
static char string[150];
sprintf(string, "%s (%s) in slot %d v%s",
host->hostt->name, info->info.scsi.type, info->ec->slot_no,
VERSION);
return string;
}
static int
arxescsi_proc_info(struct Scsi_Host *host, char *buffer, char **start, off_t offset, int length,
int inout)
{
struct arxescsi_info *info;
char *p = buffer;
int pos;
info = (struct arxescsi_info *)host->hostdata;
if (inout == 1)
return -EINVAL;
p += sprintf(p, "ARXE 16-bit SCSI driver v%s\n", VERSION);
p += fas216_print_host(&info->info, p);
p += fas216_print_stats(&info->info, p);
p += fas216_print_devices(&info->info, p);
*start = buffer + offset;
pos = p - buffer - offset;
if (pos > length)
pos = length;
return pos;
}
static int __devinit
arxescsi_probe(struct expansion_card *ec, const struct ecard_id *id)
{
struct Scsi_Host *host;
struct arxescsi_info *info;
void __iomem *base;
int ret;
ret = ecard_request_resources(ec);
if (ret)
goto out;
base = ecardm_iomap(ec, ECARD_RES_MEMC, 0, 0);
if (!base) {
ret = -ENOMEM;
goto out_region;
}
host = scsi_host_alloc(&arxescsi_template, sizeof(struct arxescsi_info));
if (!host) {
ret = -ENOMEM;
goto out_region;
}
info = (struct arxescsi_info *)host->hostdata;
info->ec = ec;
info->base = base;
info->info.scsi.io_base = base + 0x2000;
info->info.scsi.irq = 0;
info->info.scsi.dma = NO_DMA;
info->info.scsi.io_shift = 5;
info->info.ifcfg.clockrate = 24;
info->info.ifcfg.select_timeout = 255;
info->info.ifcfg.asyncperiod = 200;
info->info.ifcfg.sync_max_depth = 0;
info->info.ifcfg.cntl3 = CNTL3_FASTSCSI | CNTL3_FASTCLK;
info->info.ifcfg.disconnect_ok = 0;
info->info.ifcfg.wide_max_size = 0;
info->info.ifcfg.capabilities = FASCAP_PSEUDODMA;
info->info.dma.setup = arxescsi_dma_setup;
info->info.dma.pseudo = arxescsi_dma_pseudo;
info->info.dma.stop = arxescsi_dma_stop;
ec->irqaddr = base;
ec->irqmask = CSTATUS_IRQ;
ret = fas216_init(host);
if (ret)
goto out_unregister;
ret = fas216_add(host, &ec->dev);
if (ret == 0)
goto out;
fas216_release(host);
out_unregister:
scsi_host_put(host);
out_region:
ecard_release_resources(ec);
out:
return ret;
}
static void __devexit arxescsi_remove(struct expansion_card *ec)
{
struct Scsi_Host *host = ecard_get_drvdata(ec);
ecard_set_drvdata(ec, NULL);
fas216_remove(host);
fas216_release(host);
scsi_host_put(host);
ecard_release_resources(ec);
}
static int __init init_arxe_scsi_driver(void)
{
return ecard_register_driver(&arxescsi_driver);
}
static void __exit exit_arxe_scsi_driver(void)
{
ecard_remove_driver(&arxescsi_driver);
}
