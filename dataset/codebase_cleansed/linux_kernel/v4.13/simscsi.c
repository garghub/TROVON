static int __init
simscsi_setup (char *s)
{
if (strlen(s) > MAX_ROOT_LEN) {
printk(KERN_ERR "simscsi_setup: prefix too long---using default %s\n",
simscsi_root);
} else
simscsi_root = s;
return 1;
}
static void
simscsi_interrupt (unsigned long val)
{
struct scsi_cmnd *sc;
while ((sc = queue[rd].sc) != NULL) {
atomic_dec(&num_reqs);
queue[rd].sc = NULL;
if (DBG)
printk("simscsi_interrupt: done with %ld\n", sc->serial_number);
(*sc->scsi_done)(sc);
rd = (rd + 1) % SIMSCSI_REQ_QUEUE_LEN;
}
}
static int
simscsi_biosparam (struct scsi_device *sdev, struct block_device *n,
sector_t capacity, int ip[])
{
ip[0] = 64;
ip[1] = 32;
ip[2] = capacity >> 11;
return 0;
}
static void
simscsi_sg_readwrite (struct scsi_cmnd *sc, int mode, unsigned long offset)
{
int i;
struct scatterlist *sl;
struct disk_stat stat;
struct disk_req req;
stat.fd = desc[sc->device->id];
scsi_for_each_sg(sc, sl, scsi_sg_count(sc), i) {
req.addr = __pa(sg_virt(sl));
req.len = sl->length;
if (DBG)
printk("simscsi_sg_%s @ %lx (off %lx) use_sg=%d len=%d\n",
mode == SSC_READ ? "read":"write", req.addr, offset,
scsi_sg_count(sc) - i, sl->length);
ia64_ssc(stat.fd, 1, __pa(&req), offset, mode);
ia64_ssc(__pa(&stat), 0, 0, 0, SSC_WAIT_COMPLETION);
if (stat.count != req.len) {
sc->result = DID_ERROR << 16;
return;
}
offset += sl->length;
}
sc->result = GOOD;
}
static void
simscsi_readwrite6 (struct scsi_cmnd *sc, int mode)
{
unsigned long offset;
offset = (((sc->cmnd[1] & 0x1f) << 16) | (sc->cmnd[2] << 8) | sc->cmnd[3])*512;
simscsi_sg_readwrite(sc, mode, offset);
}
static size_t
simscsi_get_disk_size (int fd)
{
struct disk_stat stat;
size_t bit, sectors = 0;
struct disk_req req;
char buf[512];
for (bit = (128UL << 30)/512; bit != 0; bit >>= 1) {
req.addr = __pa(&buf);
req.len = sizeof(buf);
ia64_ssc(fd, 1, __pa(&req), ((sectors | bit) - 1)*512, SSC_READ);
stat.fd = fd;
ia64_ssc(__pa(&stat), 0, 0, 0, SSC_WAIT_COMPLETION);
if (stat.count == sizeof(buf))
sectors |= bit;
}
return sectors - 1;
}
static void
simscsi_readwrite10 (struct scsi_cmnd *sc, int mode)
{
unsigned long offset;
offset = (((unsigned long)sc->cmnd[2] << 24)
| ((unsigned long)sc->cmnd[3] << 16)
| ((unsigned long)sc->cmnd[4] << 8)
| ((unsigned long)sc->cmnd[5] << 0))*512UL;
simscsi_sg_readwrite(sc, mode, offset);
}
static int
simscsi_queuecommand_lck (struct scsi_cmnd *sc, void (*done)(struct scsi_cmnd *))
{
unsigned int target_id = sc->device->id;
char fname[MAX_ROOT_LEN+16];
size_t disk_size;
char *buf;
char localbuf[36];
#if DEBUG_SIMSCSI
register long sp asm ("sp");
if (DBG)
printk("simscsi_queuecommand: target=%d,cmnd=%u,sc=%lu,sp=%lx,done=%p\n",
target_id, sc->cmnd[0], sc->serial_number, sp, done);
#endif
sc->result = DID_BAD_TARGET << 16;
sc->scsi_done = done;
if (target_id <= 15 && sc->device->lun == 0) {
switch (sc->cmnd[0]) {
case INQUIRY:
if (scsi_bufflen(sc) < 35) {
break;
}
sprintf (fname, "%s%c", simscsi_root, 'a' + target_id);
desc[target_id] = ia64_ssc(__pa(fname), SSC_READ_ACCESS|SSC_WRITE_ACCESS,
0, 0, SSC_OPEN);
if (desc[target_id] < 0) {
break;
}
buf = localbuf;
buf[0] = 0;
buf[1] = 0;
buf[2] = 2;
buf[3] = 2;
buf[4] = 31;
buf[5] = 0;
buf[6] = 0;
buf[7] = 0;
memcpy(buf + 8, "HP SIMULATED DISK 0.00", 28);
scsi_sg_copy_from_buffer(sc, buf, 36);
sc->result = GOOD;
break;
case TEST_UNIT_READY:
sc->result = GOOD;
break;
case READ_6:
if (desc[target_id] < 0 )
break;
simscsi_readwrite6(sc, SSC_READ);
break;
case READ_10:
if (desc[target_id] < 0 )
break;
simscsi_readwrite10(sc, SSC_READ);
break;
case WRITE_6:
if (desc[target_id] < 0)
break;
simscsi_readwrite6(sc, SSC_WRITE);
break;
case WRITE_10:
if (desc[target_id] < 0)
break;
simscsi_readwrite10(sc, SSC_WRITE);
break;
case READ_CAPACITY:
if (desc[target_id] < 0 || scsi_bufflen(sc) < 8) {
break;
}
buf = localbuf;
disk_size = simscsi_get_disk_size(desc[target_id]);
buf[0] = (disk_size >> 24) & 0xff;
buf[1] = (disk_size >> 16) & 0xff;
buf[2] = (disk_size >> 8) & 0xff;
buf[3] = (disk_size >> 0) & 0xff;
buf[4] = 0;
buf[5] = 0;
buf[6] = 2;
buf[7] = 0;
scsi_sg_copy_from_buffer(sc, buf, 8);
sc->result = GOOD;
break;
case MODE_SENSE:
case MODE_SENSE_10:
scsi_sg_copy_from_buffer(sc, (char *)empty_zero_page,
PAGE_SIZE);
sc->result = GOOD;
break;
case START_STOP:
printk(KERN_ERR "START_STOP\n");
break;
default:
panic("simscsi: unknown SCSI command %u\n", sc->cmnd[0]);
}
}
if (sc->result == DID_BAD_TARGET) {
sc->result |= DRIVER_SENSE << 24;
sc->sense_buffer[0] = 0x70;
sc->sense_buffer[2] = 0x00;
}
if (atomic_read(&num_reqs) >= SIMSCSI_REQ_QUEUE_LEN) {
panic("Attempt to queue command while command is pending!!");
}
atomic_inc(&num_reqs);
queue[wr].sc = sc;
wr = (wr + 1) % SIMSCSI_REQ_QUEUE_LEN;
tasklet_schedule(&simscsi_tasklet);
return 0;
}
static int __init
simscsi_init(void)
{
int error;
host = scsi_host_alloc(&driver_template, 0);
if (!host)
return -ENOMEM;
error = scsi_add_host(host, NULL);
if (error)
goto free_host;
scsi_scan_host(host);
return 0;
free_host:
scsi_host_put(host);
return error;
}
