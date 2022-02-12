static int ps3rom_slave_configure(struct scsi_device *scsi_dev)
{
struct ps3rom_private *priv = shost_priv(scsi_dev->host);
struct ps3_storage_device *dev = priv->dev;
dev_dbg(&dev->sbd.core, "%s:%u: id %u, lun %u, channel %u\n", __func__,
__LINE__, scsi_dev->id, scsi_dev->lun, scsi_dev->channel);
scsi_dev->use_10_for_ms = 1;
scsi_dev->use_10_for_rw = 1;
return 0;
}
static int ps3rom_atapi_request(struct ps3_storage_device *dev,
struct scsi_cmnd *cmd)
{
struct lv1_atapi_cmnd_block atapi_cmnd;
unsigned char opcode = cmd->cmnd[0];
int res;
u64 lpar;
dev_dbg(&dev->sbd.core, "%s:%u: send ATAPI command 0x%02x\n", __func__,
__LINE__, opcode);
memset(&atapi_cmnd, 0, sizeof(struct lv1_atapi_cmnd_block));
memcpy(&atapi_cmnd.pkt, cmd->cmnd, 12);
atapi_cmnd.pktlen = 12;
atapi_cmnd.block_size = 1;
atapi_cmnd.blocks = atapi_cmnd.arglen = scsi_bufflen(cmd);
atapi_cmnd.buffer = dev->bounce_lpar;
switch (cmd->sc_data_direction) {
case DMA_FROM_DEVICE:
if (scsi_bufflen(cmd) >= CD_FRAMESIZE)
atapi_cmnd.proto = DMA_PROTO;
else
atapi_cmnd.proto = PIO_DATA_IN_PROTO;
atapi_cmnd.in_out = DIR_READ;
break;
case DMA_TO_DEVICE:
if (scsi_bufflen(cmd) >= CD_FRAMESIZE)
atapi_cmnd.proto = DMA_PROTO;
else
atapi_cmnd.proto = PIO_DATA_OUT_PROTO;
atapi_cmnd.in_out = DIR_WRITE;
scsi_sg_copy_to_buffer(cmd, dev->bounce_buf, dev->bounce_size);
break;
default:
atapi_cmnd.proto = NON_DATA_PROTO;
break;
}
lpar = ps3_mm_phys_to_lpar(__pa(&atapi_cmnd));
res = lv1_storage_send_device_command(dev->sbd.dev_id,
LV1_STORAGE_SEND_ATAPI_COMMAND,
lpar, sizeof(atapi_cmnd),
atapi_cmnd.buffer,
atapi_cmnd.arglen, &dev->tag);
if (res == LV1_DENIED_BY_POLICY) {
dev_dbg(&dev->sbd.core,
"%s:%u: ATAPI command 0x%02x denied by policy\n",
__func__, __LINE__, opcode);
return DID_ERROR << 16;
}
if (res) {
dev_err(&dev->sbd.core,
"%s:%u: ATAPI command 0x%02x failed %d\n", __func__,
__LINE__, opcode, res);
return DID_ERROR << 16;
}
return 0;
}
static inline unsigned int srb10_lba(const struct scsi_cmnd *cmd)
{
return cmd->cmnd[2] << 24 | cmd->cmnd[3] << 16 | cmd->cmnd[4] << 8 |
cmd->cmnd[5];
}
static inline unsigned int srb10_len(const struct scsi_cmnd *cmd)
{
return cmd->cmnd[7] << 8 | cmd->cmnd[8];
}
static int ps3rom_read_request(struct ps3_storage_device *dev,
struct scsi_cmnd *cmd, u32 start_sector,
u32 sectors)
{
int res;
dev_dbg(&dev->sbd.core, "%s:%u: read %u sectors starting at %u\n",
__func__, __LINE__, sectors, start_sector);
res = lv1_storage_read(dev->sbd.dev_id,
dev->regions[dev->region_idx].id, start_sector,
sectors, 0, dev->bounce_lpar, &dev->tag);
if (res) {
dev_err(&dev->sbd.core, "%s:%u: read failed %d\n", __func__,
__LINE__, res);
return DID_ERROR << 16;
}
return 0;
}
static int ps3rom_write_request(struct ps3_storage_device *dev,
struct scsi_cmnd *cmd, u32 start_sector,
u32 sectors)
{
int res;
dev_dbg(&dev->sbd.core, "%s:%u: write %u sectors starting at %u\n",
__func__, __LINE__, sectors, start_sector);
scsi_sg_copy_to_buffer(cmd, dev->bounce_buf, dev->bounce_size);
res = lv1_storage_write(dev->sbd.dev_id,
dev->regions[dev->region_idx].id, start_sector,
sectors, 0, dev->bounce_lpar, &dev->tag);
if (res) {
dev_err(&dev->sbd.core, "%s:%u: write failed %d\n", __func__,
__LINE__, res);
return DID_ERROR << 16;
}
return 0;
}
static int ps3rom_queuecommand_lck(struct scsi_cmnd *cmd,
void (*done)(struct scsi_cmnd *))
{
struct ps3rom_private *priv = shost_priv(cmd->device->host);
struct ps3_storage_device *dev = priv->dev;
unsigned char opcode;
int res;
#ifdef DEBUG
scsi_print_command(cmd);
#endif
priv->curr_cmd = cmd;
cmd->scsi_done = done;
opcode = cmd->cmnd[0];
switch (opcode) {
case READ_10:
res = ps3rom_read_request(dev, cmd, srb10_lba(cmd),
srb10_len(cmd));
break;
case WRITE_10:
res = ps3rom_write_request(dev, cmd, srb10_lba(cmd),
srb10_len(cmd));
break;
default:
res = ps3rom_atapi_request(dev, cmd);
break;
}
if (res) {
memset(cmd->sense_buffer, 0, SCSI_SENSE_BUFFERSIZE);
cmd->result = res;
cmd->sense_buffer[0] = 0x70;
cmd->sense_buffer[2] = ILLEGAL_REQUEST;
priv->curr_cmd = NULL;
cmd->scsi_done(cmd);
}
return 0;
}
irqreturn_t ps3rom_interrupt(int irq, void *data)
{
struct ps3_storage_device *dev = data;
struct Scsi_Host *host;
struct ps3rom_private *priv;
struct scsi_cmnd *cmd;
int res;
u64 tag, status;
unsigned char sense_key, asc, ascq;
res = lv1_storage_get_async_status(dev->sbd.dev_id, &tag, &status);
if (tag != dev->tag)
dev_err(&dev->sbd.core,
"%s:%u: tag mismatch, got %llx, expected %llx\n",
__func__, __LINE__, tag, dev->tag);
if (res) {
dev_err(&dev->sbd.core, "%s:%u: res=%d status=0x%llx\n",
__func__, __LINE__, res, status);
return IRQ_HANDLED;
}
host = ps3_system_bus_get_drvdata(&dev->sbd);
priv = shost_priv(host);
cmd = priv->curr_cmd;
if (!status) {
if (cmd->sc_data_direction == DMA_FROM_DEVICE) {
int len;
len = scsi_sg_copy_from_buffer(cmd,
dev->bounce_buf,
dev->bounce_size);
scsi_set_resid(cmd, scsi_bufflen(cmd) - len);
}
cmd->result = DID_OK << 16;
goto done;
}
if (cmd->cmnd[0] == REQUEST_SENSE) {
dev_err(&dev->sbd.core, "%s:%u: end error without autosense\n",
__func__, __LINE__);
cmd->result = DID_ERROR << 16 | SAM_STAT_CHECK_CONDITION;
goto done;
}
if (decode_lv1_status(status, &sense_key, &asc, &ascq)) {
cmd->result = DID_ERROR << 16;
goto done;
}
scsi_build_sense_buffer(0, cmd->sense_buffer, sense_key, asc, ascq);
cmd->result = SAM_STAT_CHECK_CONDITION;
done:
priv->curr_cmd = NULL;
cmd->scsi_done(cmd);
return IRQ_HANDLED;
}
static int ps3rom_probe(struct ps3_system_bus_device *_dev)
{
struct ps3_storage_device *dev = to_ps3_storage_device(&_dev->core);
int error;
struct Scsi_Host *host;
struct ps3rom_private *priv;
if (dev->blk_size != CD_FRAMESIZE) {
dev_err(&dev->sbd.core,
"%s:%u: cannot handle block size %llu\n", __func__,
__LINE__, dev->blk_size);
return -EINVAL;
}
dev->bounce_size = BOUNCE_SIZE;
dev->bounce_buf = kmalloc(BOUNCE_SIZE, GFP_DMA);
if (!dev->bounce_buf)
return -ENOMEM;
error = ps3stor_setup(dev, ps3rom_interrupt);
if (error)
goto fail_free_bounce;
host = scsi_host_alloc(&ps3rom_host_template,
sizeof(struct ps3rom_private));
if (!host) {
dev_err(&dev->sbd.core, "%s:%u: scsi_host_alloc failed\n",
__func__, __LINE__);
goto fail_teardown;
}
priv = shost_priv(host);
ps3_system_bus_set_drvdata(&dev->sbd, host);
priv->dev = dev;
host->max_id = 1;
host->max_lun = 1;
error = scsi_add_host(host, &dev->sbd.core);
if (error) {
dev_err(&dev->sbd.core, "%s:%u: scsi_host_alloc failed %d\n",
__func__, __LINE__, error);
error = -ENODEV;
goto fail_host_put;
}
scsi_scan_host(host);
return 0;
fail_host_put:
scsi_host_put(host);
ps3_system_bus_set_drvdata(&dev->sbd, NULL);
fail_teardown:
ps3stor_teardown(dev);
fail_free_bounce:
kfree(dev->bounce_buf);
return error;
}
static int ps3rom_remove(struct ps3_system_bus_device *_dev)
{
struct ps3_storage_device *dev = to_ps3_storage_device(&_dev->core);
struct Scsi_Host *host = ps3_system_bus_get_drvdata(&dev->sbd);
scsi_remove_host(host);
ps3stor_teardown(dev);
scsi_host_put(host);
ps3_system_bus_set_drvdata(&dev->sbd, NULL);
kfree(dev->bounce_buf);
return 0;
}
static int __init ps3rom_init(void)
{
return ps3_system_bus_driver_register(&ps3rom);
}
static void __exit ps3rom_exit(void)
{
ps3_system_bus_driver_unregister(&ps3rom);
}
