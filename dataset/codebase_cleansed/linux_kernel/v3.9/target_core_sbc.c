static sense_reason_t
sbc_emulate_readcapacity(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned long long blocks_long = dev->transport->get_blocks(dev);
unsigned char *rbuf;
unsigned char buf[8];
u32 blocks;
if (blocks_long >= 0x00000000ffffffff)
blocks = 0xffffffff;
else
blocks = (u32)blocks_long;
buf[0] = (blocks >> 24) & 0xff;
buf[1] = (blocks >> 16) & 0xff;
buf[2] = (blocks >> 8) & 0xff;
buf[3] = blocks & 0xff;
buf[4] = (dev->dev_attrib.block_size >> 24) & 0xff;
buf[5] = (dev->dev_attrib.block_size >> 16) & 0xff;
buf[6] = (dev->dev_attrib.block_size >> 8) & 0xff;
buf[7] = dev->dev_attrib.block_size & 0xff;
rbuf = transport_kmap_data_sg(cmd);
if (rbuf) {
memcpy(rbuf, buf, min_t(u32, sizeof(buf), cmd->data_length));
transport_kunmap_data_sg(cmd);
}
target_complete_cmd(cmd, GOOD);
return 0;
}
static sense_reason_t
sbc_emulate_readcapacity_16(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned char *rbuf;
unsigned char buf[32];
unsigned long long blocks = dev->transport->get_blocks(dev);
memset(buf, 0, sizeof(buf));
buf[0] = (blocks >> 56) & 0xff;
buf[1] = (blocks >> 48) & 0xff;
buf[2] = (blocks >> 40) & 0xff;
buf[3] = (blocks >> 32) & 0xff;
buf[4] = (blocks >> 24) & 0xff;
buf[5] = (blocks >> 16) & 0xff;
buf[6] = (blocks >> 8) & 0xff;
buf[7] = blocks & 0xff;
buf[8] = (dev->dev_attrib.block_size >> 24) & 0xff;
buf[9] = (dev->dev_attrib.block_size >> 16) & 0xff;
buf[10] = (dev->dev_attrib.block_size >> 8) & 0xff;
buf[11] = dev->dev_attrib.block_size & 0xff;
if (dev->dev_attrib.emulate_tpu || dev->dev_attrib.emulate_tpws)
buf[14] = 0x80;
rbuf = transport_kmap_data_sg(cmd);
if (rbuf) {
memcpy(rbuf, buf, min_t(u32, sizeof(buf), cmd->data_length));
transport_kunmap_data_sg(cmd);
}
target_complete_cmd(cmd, GOOD);
return 0;
}
sector_t sbc_get_write_same_sectors(struct se_cmd *cmd)
{
u32 num_blocks;
if (cmd->t_task_cdb[0] == WRITE_SAME)
num_blocks = get_unaligned_be16(&cmd->t_task_cdb[7]);
else if (cmd->t_task_cdb[0] == WRITE_SAME_16)
num_blocks = get_unaligned_be32(&cmd->t_task_cdb[10]);
else
num_blocks = get_unaligned_be32(&cmd->t_task_cdb[28]);
if (num_blocks)
return num_blocks;
return cmd->se_dev->transport->get_blocks(cmd->se_dev) -
cmd->t_task_lba + 1;
}
static sense_reason_t
sbc_emulate_noop(struct se_cmd *cmd)
{
target_complete_cmd(cmd, GOOD);
return 0;
}
static inline u32 sbc_get_size(struct se_cmd *cmd, u32 sectors)
{
return cmd->se_dev->dev_attrib.block_size * sectors;
}
static int sbc_check_valid_sectors(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned long long end_lba;
u32 sectors;
sectors = cmd->data_length / dev->dev_attrib.block_size;
end_lba = dev->transport->get_blocks(dev) + 1;
if (cmd->t_task_lba + sectors > end_lba) {
pr_err("target: lba %llu, sectors %u exceeds end lba %llu\n",
cmd->t_task_lba, sectors, end_lba);
return -EINVAL;
}
return 0;
}
static inline u32 transport_get_sectors_6(unsigned char *cdb)
{
return cdb[4] ? : 256;
}
static inline u32 transport_get_sectors_10(unsigned char *cdb)
{
return (u32)(cdb[7] << 8) + cdb[8];
}
static inline u32 transport_get_sectors_12(unsigned char *cdb)
{
return (u32)(cdb[6] << 24) + (cdb[7] << 16) + (cdb[8] << 8) + cdb[9];
}
static inline u32 transport_get_sectors_16(unsigned char *cdb)
{
return (u32)(cdb[10] << 24) + (cdb[11] << 16) +
(cdb[12] << 8) + cdb[13];
}
static inline u32 transport_get_sectors_32(unsigned char *cdb)
{
return (u32)(cdb[28] << 24) + (cdb[29] << 16) +
(cdb[30] << 8) + cdb[31];
}
static inline u32 transport_lba_21(unsigned char *cdb)
{
return ((cdb[1] & 0x1f) << 16) | (cdb[2] << 8) | cdb[3];
}
static inline u32 transport_lba_32(unsigned char *cdb)
{
return (cdb[2] << 24) | (cdb[3] << 16) | (cdb[4] << 8) | cdb[5];
}
static inline unsigned long long transport_lba_64(unsigned char *cdb)
{
unsigned int __v1, __v2;
__v1 = (cdb[2] << 24) | (cdb[3] << 16) | (cdb[4] << 8) | cdb[5];
__v2 = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
return ((unsigned long long)__v2) | (unsigned long long)__v1 << 32;
}
static inline unsigned long long transport_lba_64_ext(unsigned char *cdb)
{
unsigned int __v1, __v2;
__v1 = (cdb[12] << 24) | (cdb[13] << 16) | (cdb[14] << 8) | cdb[15];
__v2 = (cdb[16] << 24) | (cdb[17] << 16) | (cdb[18] << 8) | cdb[19];
return ((unsigned long long)__v2) | (unsigned long long)__v1 << 32;
}
static sense_reason_t
sbc_setup_write_same(struct se_cmd *cmd, unsigned char *flags, struct sbc_ops *ops)
{
unsigned int sectors = sbc_get_write_same_sectors(cmd);
if ((flags[0] & 0x04) || (flags[0] & 0x02)) {
pr_err("WRITE_SAME PBDATA and LBDATA"
" bits not supported for Block Discard"
" Emulation\n");
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
if (sectors > cmd->se_dev->dev_attrib.max_write_same_len) {
pr_warn("WRITE_SAME sectors: %u exceeds max_write_same_len: %u\n",
sectors, cmd->se_dev->dev_attrib.max_write_same_len);
return TCM_INVALID_CDB_FIELD;
}
if (flags[0] & 0x08) {
if (!ops->execute_write_same_unmap)
return TCM_UNSUPPORTED_SCSI_OPCODE;
cmd->execute_cmd = ops->execute_write_same_unmap;
return 0;
}
if (!ops->execute_write_same)
return TCM_UNSUPPORTED_SCSI_OPCODE;
cmd->execute_cmd = ops->execute_write_same;
return 0;
}
static void xdreadwrite_callback(struct se_cmd *cmd)
{
unsigned char *buf, *addr;
struct scatterlist *sg;
unsigned int offset;
int i;
int count;
buf = kmalloc(cmd->data_length, GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate xor_callback buf\n");
return;
}
sg_copy_to_buffer(cmd->t_data_sg,
cmd->t_data_nents,
buf,
cmd->data_length);
offset = 0;
for_each_sg(cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
addr = kmap_atomic(sg_page(sg));
if (!addr)
goto out;
for (i = 0; i < sg->length; i++)
*(addr + sg->offset + i) ^= *(buf + offset + i);
offset += sg->length;
kunmap_atomic(addr);
}
out:
kfree(buf);
}
sense_reason_t
sbc_parse_cdb(struct se_cmd *cmd, struct sbc_ops *ops)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb = cmd->t_task_cdb;
unsigned int size;
u32 sectors = 0;
sense_reason_t ret;
switch (cdb[0]) {
case READ_6:
sectors = transport_get_sectors_6(cdb);
cmd->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case READ_10:
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case READ_12:
sectors = transport_get_sectors_12(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case READ_16:
sectors = transport_get_sectors_16(cdb);
cmd->t_task_lba = transport_lba_64(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case WRITE_6:
sectors = transport_get_sectors_6(cdb);
cmd->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case WRITE_10:
case WRITE_VERIFY:
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
if (cdb[1] & 0x8)
cmd->se_cmd_flags |= SCF_FUA;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case WRITE_12:
sectors = transport_get_sectors_12(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
if (cdb[1] & 0x8)
cmd->se_cmd_flags |= SCF_FUA;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case WRITE_16:
sectors = transport_get_sectors_16(cdb);
cmd->t_task_lba = transport_lba_64(cdb);
if (cdb[1] & 0x8)
cmd->se_cmd_flags |= SCF_FUA;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
break;
case XDWRITEREAD_10:
if (cmd->data_direction != DMA_TO_DEVICE ||
!(cmd->se_cmd_flags & SCF_BIDI))
return TCM_INVALID_CDB_FIELD;
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
cmd->transport_complete_callback = &xdreadwrite_callback;
if (cdb[1] & 0x8)
cmd->se_cmd_flags |= SCF_FUA;
break;
case VARIABLE_LENGTH_CMD:
{
u16 service_action = get_unaligned_be16(&cdb[8]);
switch (service_action) {
case XDWRITEREAD_32:
sectors = transport_get_sectors_32(cdb);
cmd->t_task_lba = transport_lba_64_ext(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = ops->execute_rw;
cmd->transport_complete_callback = &xdreadwrite_callback;
if (cdb[1] & 0x8)
cmd->se_cmd_flags |= SCF_FUA;
break;
case WRITE_SAME_32:
sectors = transport_get_sectors_32(cdb);
if (!sectors) {
pr_err("WSNZ=1, WRITE_SAME w/sectors=0 not"
" supported\n");
return TCM_INVALID_CDB_FIELD;
}
size = sbc_get_size(cmd, 1);
cmd->t_task_lba = get_unaligned_be64(&cdb[12]);
ret = sbc_setup_write_same(cmd, &cdb[10], ops);
if (ret)
return ret;
break;
default:
pr_err("VARIABLE_LENGTH_CMD service action"
" 0x%04x not supported\n", service_action);
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
break;
}
case READ_CAPACITY:
size = READ_CAP_LEN;
cmd->execute_cmd = sbc_emulate_readcapacity;
break;
case SERVICE_ACTION_IN:
switch (cmd->t_task_cdb[1] & 0x1f) {
case SAI_READ_CAPACITY_16:
cmd->execute_cmd = sbc_emulate_readcapacity_16;
break;
default:
pr_err("Unsupported SA: 0x%02x\n",
cmd->t_task_cdb[1] & 0x1f);
return TCM_INVALID_CDB_FIELD;
}
size = (cdb[10] << 24) | (cdb[11] << 16) |
(cdb[12] << 8) | cdb[13];
break;
case SYNCHRONIZE_CACHE:
case SYNCHRONIZE_CACHE_16:
if (!ops->execute_sync_cache) {
size = 0;
cmd->execute_cmd = sbc_emulate_noop;
break;
}
if (cdb[0] == SYNCHRONIZE_CACHE) {
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
} else {
sectors = transport_get_sectors_16(cdb);
cmd->t_task_lba = transport_lba_64(cdb);
}
size = sbc_get_size(cmd, sectors);
if (cmd->t_task_lba || sectors) {
if (sbc_check_valid_sectors(cmd) < 0)
return TCM_ADDRESS_OUT_OF_RANGE;
}
cmd->execute_cmd = ops->execute_sync_cache;
break;
case UNMAP:
if (!ops->execute_unmap)
return TCM_UNSUPPORTED_SCSI_OPCODE;
size = get_unaligned_be16(&cdb[7]);
cmd->execute_cmd = ops->execute_unmap;
break;
case WRITE_SAME_16:
sectors = transport_get_sectors_16(cdb);
if (!sectors) {
pr_err("WSNZ=1, WRITE_SAME w/sectors=0 not supported\n");
return TCM_INVALID_CDB_FIELD;
}
size = sbc_get_size(cmd, 1);
cmd->t_task_lba = get_unaligned_be64(&cdb[2]);
ret = sbc_setup_write_same(cmd, &cdb[1], ops);
if (ret)
return ret;
break;
case WRITE_SAME:
sectors = transport_get_sectors_10(cdb);
if (!sectors) {
pr_err("WSNZ=1, WRITE_SAME w/sectors=0 not supported\n");
return TCM_INVALID_CDB_FIELD;
}
size = sbc_get_size(cmd, 1);
cmd->t_task_lba = get_unaligned_be32(&cdb[2]);
ret = sbc_setup_write_same(cmd, &cdb[1], ops);
if (ret)
return ret;
break;
case VERIFY:
size = 0;
cmd->execute_cmd = sbc_emulate_noop;
break;
case REZERO_UNIT:
case SEEK_6:
case SEEK_10:
size = 0;
cmd->execute_cmd = sbc_emulate_noop;
break;
default:
ret = spc_parse_cdb(cmd, &size);
if (ret)
return ret;
}
if (!(cmd->se_cmd_flags & SCF_SCSI_DATA_CDB) && !cmd->execute_cmd)
return TCM_UNSUPPORTED_SCSI_OPCODE;
if (cmd->se_cmd_flags & SCF_SCSI_DATA_CDB) {
unsigned long long end_lba;
if (sectors > dev->dev_attrib.fabric_max_sectors) {
printk_ratelimited(KERN_ERR "SCSI OP %02xh with too"
" big sectors %u exceeds fabric_max_sectors:"
" %u\n", cdb[0], sectors,
dev->dev_attrib.fabric_max_sectors);
return TCM_INVALID_CDB_FIELD;
}
if (sectors > dev->dev_attrib.hw_max_sectors) {
printk_ratelimited(KERN_ERR "SCSI OP %02xh with too"
" big sectors %u exceeds backend hw_max_sectors:"
" %u\n", cdb[0], sectors,
dev->dev_attrib.hw_max_sectors);
return TCM_INVALID_CDB_FIELD;
}
end_lba = dev->transport->get_blocks(dev) + 1;
if (cmd->t_task_lba + sectors > end_lba) {
pr_err("cmd exceeds last lba %llu "
"(lba %llu, sectors %u)\n",
end_lba, cmd->t_task_lba, sectors);
return TCM_INVALID_CDB_FIELD;
}
size = sbc_get_size(cmd, sectors);
}
return target_cmd_size_check(cmd, size);
}
u32 sbc_get_device_type(struct se_device *dev)
{
return TYPE_DISK;
}
