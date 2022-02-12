static sense_reason_t
sbc_emulate_readcapacity(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb = cmd->t_task_cdb;
unsigned long long blocks_long = dev->transport->get_blocks(dev);
unsigned char *rbuf;
unsigned char buf[8];
u32 blocks;
if (!(cdb[8] & 1) && !!(cdb[2] | cdb[3] | cdb[4] | cdb[5]))
return TCM_INVALID_CDB_FIELD;
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
target_complete_cmd_with_length(cmd, GOOD, 8);
return 0;
}
static sense_reason_t
sbc_emulate_readcapacity_16(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
int pi_prot_type = dev->dev_attrib.pi_prot_type;
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
if (sess->sup_prot_ops & (TARGET_PROT_DIN_PASS | TARGET_PROT_DOUT_PASS)) {
if (!pi_prot_type)
pi_prot_type = sess->sess_prot_type;
if (pi_prot_type)
buf[12] = (pi_prot_type - 1) << 1 | 0x1;
}
if (dev->transport->get_lbppbe)
buf[13] = dev->transport->get_lbppbe(dev) & 0x0f;
if (dev->transport->get_alignment_offset_lbas) {
u16 lalba = dev->transport->get_alignment_offset_lbas(dev);
buf[14] = (lalba >> 8) & 0x3f;
buf[15] = lalba & 0xff;
}
if (dev->dev_attrib.emulate_tpu || dev->dev_attrib.emulate_tpws)
buf[14] |= 0x80;
rbuf = transport_kmap_data_sg(cmd);
if (rbuf) {
memcpy(rbuf, buf, min_t(u32, sizeof(buf), cmd->data_length));
transport_kunmap_data_sg(cmd);
}
target_complete_cmd_with_length(cmd, GOOD, 32);
return 0;
}
static sense_reason_t
sbc_emulate_startstop(struct se_cmd *cmd)
{
unsigned char *cdb = cmd->t_task_cdb;
if (!(cdb[1] & 1) || cdb[2] || cdb[3])
return TCM_INVALID_CDB_FIELD;
if (cdb[4] >> 4 & 0xf)
return TCM_INVALID_CDB_FIELD;
if (!(cdb[4] & 1) || (cdb[4] & 2) || (cdb[4] & 4))
return TCM_INVALID_CDB_FIELD;
target_complete_cmd(cmd, SAM_STAT_GOOD);
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
sbc_execute_write_same_unmap(struct se_cmd *cmd)
{
struct sbc_ops *ops = cmd->protocol_data;
sector_t nolb = sbc_get_write_same_sectors(cmd);
sense_reason_t ret;
if (nolb) {
ret = ops->execute_unmap(cmd, cmd->t_task_lba, nolb);
if (ret)
return ret;
}
target_complete_cmd(cmd, GOOD);
return 0;
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
struct se_device *dev = cmd->se_dev;
sector_t end_lba = dev->transport->get_blocks(dev) + 1;
unsigned int sectors = sbc_get_write_same_sectors(cmd);
sense_reason_t ret;
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
if (((cmd->t_task_lba + sectors) < cmd->t_task_lba) ||
((cmd->t_task_lba + sectors) > end_lba)) {
pr_err("WRITE_SAME exceeds last lba %llu (lba %llu, sectors %u)\n",
(unsigned long long)end_lba, cmd->t_task_lba, sectors);
return TCM_ADDRESS_OUT_OF_RANGE;
}
if (flags[0] & 0x10) {
pr_warn("WRITE SAME with ANCHOR not supported\n");
return TCM_INVALID_CDB_FIELD;
}
if (flags[0] & 0x08) {
if (!ops->execute_unmap)
return TCM_UNSUPPORTED_SCSI_OPCODE;
if (!dev->dev_attrib.emulate_tpws) {
pr_err("Got WRITE_SAME w/ UNMAP=1, but backend device"
" has emulate_tpws disabled\n");
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
cmd->execute_cmd = sbc_execute_write_same_unmap;
return 0;
}
if (!ops->execute_write_same)
return TCM_UNSUPPORTED_SCSI_OPCODE;
ret = sbc_check_prot(dev, cmd, &cmd->t_task_cdb[0], sectors, true);
if (ret)
return ret;
cmd->execute_cmd = ops->execute_write_same;
return 0;
}
static sense_reason_t xdreadwrite_callback(struct se_cmd *cmd, bool success)
{
unsigned char *buf, *addr;
struct scatterlist *sg;
unsigned int offset;
sense_reason_t ret = TCM_NO_SENSE;
int i, count;
buf = kmalloc(cmd->data_length, GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate xor_callback buf\n");
return TCM_OUT_OF_RESOURCES;
}
sg_copy_to_buffer(cmd->t_data_sg,
cmd->t_data_nents,
buf,
cmd->data_length);
offset = 0;
for_each_sg(cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
addr = kmap_atomic(sg_page(sg));
if (!addr) {
ret = TCM_OUT_OF_RESOURCES;
goto out;
}
for (i = 0; i < sg->length; i++)
*(addr + sg->offset + i) ^= *(buf + offset + i);
offset += sg->length;
kunmap_atomic(addr);
}
out:
kfree(buf);
return ret;
}
static sense_reason_t
sbc_execute_rw(struct se_cmd *cmd)
{
struct sbc_ops *ops = cmd->protocol_data;
return ops->execute_rw(cmd, cmd->t_data_sg, cmd->t_data_nents,
cmd->data_direction);
}
static sense_reason_t compare_and_write_post(struct se_cmd *cmd, bool success)
{
struct se_device *dev = cmd->se_dev;
spin_lock_irq(&cmd->t_state_lock);
if ((cmd->transport_state & CMD_T_SENT) && !cmd->scsi_status)
cmd->se_cmd_flags |= SCF_COMPARE_AND_WRITE_POST;
spin_unlock_irq(&cmd->t_state_lock);
up(&dev->caw_sem);
return TCM_NO_SENSE;
}
static sense_reason_t compare_and_write_callback(struct se_cmd *cmd, bool success)
{
struct se_device *dev = cmd->se_dev;
struct scatterlist *write_sg = NULL, *sg;
unsigned char *buf = NULL, *addr;
struct sg_mapping_iter m;
unsigned int offset = 0, len;
unsigned int nlbas = cmd->t_task_nolb;
unsigned int block_size = dev->dev_attrib.block_size;
unsigned int compare_len = (nlbas * block_size);
sense_reason_t ret = TCM_NO_SENSE;
int rc, i;
if (!success && (!cmd->t_data_sg || !cmd->t_bidi_data_sg))
return TCM_NO_SENSE;
if (!cmd->data_length)
goto out;
if (cmd->scsi_status) {
pr_err("compare_and_write_callback: non zero scsi_status:"
" 0x%02x\n", cmd->scsi_status);
goto out;
}
buf = kzalloc(cmd->data_length, GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate compare_and_write buf\n");
ret = TCM_OUT_OF_RESOURCES;
goto out;
}
write_sg = kmalloc(sizeof(struct scatterlist) * cmd->t_data_nents,
GFP_KERNEL);
if (!write_sg) {
pr_err("Unable to allocate compare_and_write sg\n");
ret = TCM_OUT_OF_RESOURCES;
goto out;
}
sg_init_table(write_sg, cmd->t_data_nents);
rc = sg_copy_to_buffer(cmd->t_data_sg, cmd->t_data_nents, buf,
cmd->data_length);
if (!rc) {
pr_err("sg_copy_to_buffer() failed for compare_and_write\n");
ret = TCM_OUT_OF_RESOURCES;
goto out;
}
for_each_sg(cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
addr = (unsigned char *)kmap_atomic(sg_page(sg));
if (!addr) {
ret = TCM_OUT_OF_RESOURCES;
goto out;
}
len = min(sg->length, compare_len);
if (memcmp(addr, buf + offset, len)) {
pr_warn("Detected MISCOMPARE for addr: %p buf: %p\n",
addr, buf + offset);
kunmap_atomic(addr);
goto miscompare;
}
kunmap_atomic(addr);
offset += len;
compare_len -= len;
if (!compare_len)
break;
}
i = 0;
len = cmd->t_task_nolb * block_size;
sg_miter_start(&m, cmd->t_data_sg, cmd->t_data_nents, SG_MITER_TO_SG);
while (len) {
sg_miter_next(&m);
if (block_size < PAGE_SIZE) {
sg_set_page(&write_sg[i], m.page, block_size,
block_size);
} else {
sg_miter_next(&m);
sg_set_page(&write_sg[i], m.page, block_size,
0);
}
len -= block_size;
i++;
}
sg_miter_stop(&m);
cmd->t_data_sg_orig = cmd->t_data_sg;
cmd->t_data_sg = write_sg;
cmd->t_data_nents_orig = cmd->t_data_nents;
cmd->t_data_nents = 1;
cmd->sam_task_attr = TCM_HEAD_TAG;
cmd->transport_complete_callback = compare_and_write_post;
cmd->execute_cmd = sbc_execute_rw;
spin_lock_irq(&cmd->t_state_lock);
cmd->t_state = TRANSPORT_PROCESSING;
cmd->transport_state |= CMD_T_ACTIVE|CMD_T_BUSY|CMD_T_SENT;
spin_unlock_irq(&cmd->t_state_lock);
__target_execute_cmd(cmd);
kfree(buf);
return ret;
miscompare:
pr_warn("Target/%s: Send MISCOMPARE check condition and sense\n",
dev->transport->name);
ret = TCM_MISCOMPARE_VERIFY;
out:
up(&dev->caw_sem);
kfree(write_sg);
kfree(buf);
return ret;
}
static sense_reason_t
sbc_compare_and_write(struct se_cmd *cmd)
{
struct sbc_ops *ops = cmd->protocol_data;
struct se_device *dev = cmd->se_dev;
sense_reason_t ret;
int rc;
rc = down_interruptible(&dev->caw_sem);
if (rc != 0) {
cmd->transport_complete_callback = NULL;
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
cmd->data_length = cmd->t_task_nolb * dev->dev_attrib.block_size;
ret = ops->execute_rw(cmd, cmd->t_bidi_data_sg, cmd->t_bidi_data_nents,
DMA_FROM_DEVICE);
if (ret) {
cmd->transport_complete_callback = NULL;
up(&dev->caw_sem);
return ret;
}
return TCM_NO_SENSE;
}
static int
sbc_set_prot_op_checks(u8 protect, bool fabric_prot, enum target_prot_type prot_type,
bool is_write, struct se_cmd *cmd)
{
if (is_write) {
cmd->prot_op = fabric_prot ? TARGET_PROT_DOUT_STRIP :
protect ? TARGET_PROT_DOUT_PASS :
TARGET_PROT_DOUT_INSERT;
switch (protect) {
case 0x0:
case 0x3:
cmd->prot_checks = 0;
break;
case 0x1:
case 0x5:
cmd->prot_checks = TARGET_DIF_CHECK_GUARD;
if (prot_type == TARGET_DIF_TYPE1_PROT)
cmd->prot_checks |= TARGET_DIF_CHECK_REFTAG;
break;
case 0x2:
if (prot_type == TARGET_DIF_TYPE1_PROT)
cmd->prot_checks = TARGET_DIF_CHECK_REFTAG;
break;
case 0x4:
cmd->prot_checks = TARGET_DIF_CHECK_GUARD;
break;
default:
pr_err("Unsupported protect field %d\n", protect);
return -EINVAL;
}
} else {
cmd->prot_op = fabric_prot ? TARGET_PROT_DIN_INSERT :
protect ? TARGET_PROT_DIN_PASS :
TARGET_PROT_DIN_STRIP;
switch (protect) {
case 0x0:
case 0x1:
case 0x5:
cmd->prot_checks = TARGET_DIF_CHECK_GUARD;
if (prot_type == TARGET_DIF_TYPE1_PROT)
cmd->prot_checks |= TARGET_DIF_CHECK_REFTAG;
break;
case 0x2:
if (prot_type == TARGET_DIF_TYPE1_PROT)
cmd->prot_checks = TARGET_DIF_CHECK_REFTAG;
break;
case 0x3:
cmd->prot_checks = 0;
break;
case 0x4:
cmd->prot_checks = TARGET_DIF_CHECK_GUARD;
break;
default:
pr_err("Unsupported protect field %d\n", protect);
return -EINVAL;
}
}
return 0;
}
static sense_reason_t
sbc_check_prot(struct se_device *dev, struct se_cmd *cmd, unsigned char *cdb,
u32 sectors, bool is_write)
{
u8 protect = cdb[1] >> 5;
int sp_ops = cmd->se_sess->sup_prot_ops;
int pi_prot_type = dev->dev_attrib.pi_prot_type;
bool fabric_prot = false;
if (!cmd->t_prot_sg || !cmd->t_prot_nents) {
if (unlikely(protect &&
!dev->dev_attrib.pi_prot_type && !cmd->se_sess->sess_prot_type)) {
pr_err("CDB contains protect bit, but device + fabric does"
" not advertise PROTECT=1 feature bit\n");
return TCM_INVALID_CDB_FIELD;
}
if (cmd->prot_pto)
return TCM_NO_SENSE;
}
switch (dev->dev_attrib.pi_prot_type) {
case TARGET_DIF_TYPE3_PROT:
cmd->reftag_seed = 0xffffffff;
break;
case TARGET_DIF_TYPE2_PROT:
if (protect)
return TCM_INVALID_CDB_FIELD;
cmd->reftag_seed = cmd->t_task_lba;
break;
case TARGET_DIF_TYPE1_PROT:
cmd->reftag_seed = cmd->t_task_lba;
break;
case TARGET_DIF_TYPE0_PROT:
fabric_prot = is_write ?
!!(sp_ops & (TARGET_PROT_DOUT_PASS | TARGET_PROT_DOUT_STRIP)) :
!!(sp_ops & (TARGET_PROT_DIN_PASS | TARGET_PROT_DIN_INSERT));
if (fabric_prot && cmd->se_sess->sess_prot_type) {
pi_prot_type = cmd->se_sess->sess_prot_type;
break;
}
if (!protect)
return TCM_NO_SENSE;
default:
pr_err("Unable to determine pi_prot_type for CDB: 0x%02x "
"PROTECT: 0x%02x\n", cdb[0], protect);
return TCM_INVALID_CDB_FIELD;
}
if (sbc_set_prot_op_checks(protect, fabric_prot, pi_prot_type, is_write, cmd))
return TCM_INVALID_CDB_FIELD;
cmd->prot_type = pi_prot_type;
cmd->prot_length = dev->prot_length * sectors;
if (protect)
cmd->data_length = sectors * dev->dev_attrib.block_size;
pr_debug("%s: prot_type=%d, data_length=%d, prot_length=%d "
"prot_op=%d prot_checks=%d\n",
__func__, cmd->prot_type, cmd->data_length, cmd->prot_length,
cmd->prot_op, cmd->prot_checks);
return TCM_NO_SENSE;
}
static int
sbc_check_dpofua(struct se_device *dev, struct se_cmd *cmd, unsigned char *cdb)
{
if (cdb[1] & 0x10) {
if (!target_check_fua(dev)) {
pr_err("Got CDB: 0x%02x with DPO bit set, but device"
" does not advertise support for DPO\n", cdb[0]);
return -EINVAL;
}
}
if (cdb[1] & 0x8) {
if (!target_check_fua(dev)) {
pr_err("Got CDB: 0x%02x with FUA bit set, but device"
" does not advertise support for FUA write\n",
cdb[0]);
return -EINVAL;
}
cmd->se_cmd_flags |= SCF_FUA;
}
return 0;
}
sense_reason_t
sbc_parse_cdb(struct se_cmd *cmd, struct sbc_ops *ops)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb = cmd->t_task_cdb;
unsigned int size;
u32 sectors = 0;
sense_reason_t ret;
cmd->protocol_data = ops;
switch (cdb[0]) {
case READ_6:
sectors = transport_get_sectors_6(cdb);
cmd->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case READ_10:
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
ret = sbc_check_prot(dev, cmd, cdb, sectors, false);
if (ret)
return ret;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case READ_12:
sectors = transport_get_sectors_12(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
ret = sbc_check_prot(dev, cmd, cdb, sectors, false);
if (ret)
return ret;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case READ_16:
sectors = transport_get_sectors_16(cdb);
cmd->t_task_lba = transport_lba_64(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
ret = sbc_check_prot(dev, cmd, cdb, sectors, false);
if (ret)
return ret;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case WRITE_6:
sectors = transport_get_sectors_6(cdb);
cmd->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case WRITE_10:
case WRITE_VERIFY:
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
ret = sbc_check_prot(dev, cmd, cdb, sectors, true);
if (ret)
return ret;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case WRITE_12:
sectors = transport_get_sectors_12(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
ret = sbc_check_prot(dev, cmd, cdb, sectors, true);
if (ret)
return ret;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case WRITE_16:
sectors = transport_get_sectors_16(cdb);
cmd->t_task_lba = transport_lba_64(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
ret = sbc_check_prot(dev, cmd, cdb, sectors, true);
if (ret)
return ret;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
break;
case XDWRITEREAD_10:
if (cmd->data_direction != DMA_TO_DEVICE ||
!(cmd->se_cmd_flags & SCF_BIDI))
return TCM_INVALID_CDB_FIELD;
sectors = transport_get_sectors_10(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
cmd->transport_complete_callback = &xdreadwrite_callback;
break;
case VARIABLE_LENGTH_CMD:
{
u16 service_action = get_unaligned_be16(&cdb[8]);
switch (service_action) {
case XDWRITEREAD_32:
sectors = transport_get_sectors_32(cdb);
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
cmd->t_task_lba = transport_lba_64_ext(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
cmd->execute_cmd = sbc_execute_rw;
cmd->transport_complete_callback = &xdreadwrite_callback;
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
case COMPARE_AND_WRITE:
sectors = cdb[13];
if (sectors > 1) {
pr_err("COMPARE_AND_WRITE contains NoLB: %u greater"
" than 1\n", sectors);
return TCM_INVALID_CDB_FIELD;
}
if (sbc_check_dpofua(dev, cmd, cdb))
return TCM_INVALID_CDB_FIELD;
size = 2 * sbc_get_size(cmd, sectors);
cmd->t_task_lba = get_unaligned_be64(&cdb[2]);
cmd->t_task_nolb = sectors;
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB | SCF_COMPARE_AND_WRITE;
cmd->execute_cmd = sbc_compare_and_write;
cmd->transport_complete_callback = compare_and_write_callback;
break;
case READ_CAPACITY:
size = READ_CAP_LEN;
cmd->execute_cmd = sbc_emulate_readcapacity;
break;
case SERVICE_ACTION_IN_16:
switch (cmd->t_task_cdb[1] & 0x1f) {
case SAI_READ_CAPACITY_16:
cmd->execute_cmd = sbc_emulate_readcapacity_16;
break;
case SAI_REPORT_REFERRALS:
cmd->execute_cmd = target_emulate_report_referrals;
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
if (cdb[0] == SYNCHRONIZE_CACHE) {
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
} else {
sectors = transport_get_sectors_16(cdb);
cmd->t_task_lba = transport_lba_64(cdb);
}
if (ops->execute_sync_cache) {
cmd->execute_cmd = ops->execute_sync_cache;
goto check_lba;
}
size = 0;
cmd->execute_cmd = sbc_emulate_noop;
break;
case UNMAP:
if (!ops->execute_unmap)
return TCM_UNSUPPORTED_SCSI_OPCODE;
if (!dev->dev_attrib.emulate_tpu) {
pr_err("Got UNMAP, but backend device has"
" emulate_tpu disabled\n");
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
size = get_unaligned_be16(&cdb[7]);
cmd->execute_cmd = sbc_execute_unmap;
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
sectors = transport_get_sectors_10(cdb);
cmd->t_task_lba = transport_lba_32(cdb);
cmd->execute_cmd = sbc_emulate_noop;
goto check_lba;
case REZERO_UNIT:
case SEEK_6:
case SEEK_10:
size = 0;
cmd->execute_cmd = sbc_emulate_noop;
break;
case START_STOP:
size = 0;
cmd->execute_cmd = sbc_emulate_startstop;
break;
default:
ret = spc_parse_cdb(cmd, &size);
if (ret)
return ret;
}
if (!cmd->execute_cmd)
return TCM_UNSUPPORTED_SCSI_OPCODE;
if (cmd->se_cmd_flags & SCF_SCSI_DATA_CDB) {
unsigned long long end_lba;
check_lba:
end_lba = dev->transport->get_blocks(dev) + 1;
if (((cmd->t_task_lba + sectors) < cmd->t_task_lba) ||
((cmd->t_task_lba + sectors) > end_lba)) {
pr_err("cmd exceeds last lba %llu "
"(lba %llu, sectors %u)\n",
end_lba, cmd->t_task_lba, sectors);
return TCM_ADDRESS_OUT_OF_RANGE;
}
if (!(cmd->se_cmd_flags & SCF_COMPARE_AND_WRITE))
size = sbc_get_size(cmd, sectors);
}
return target_cmd_size_check(cmd, size);
}
u32 sbc_get_device_type(struct se_device *dev)
{
return TYPE_DISK;
}
static sense_reason_t
sbc_execute_unmap(struct se_cmd *cmd)
{
struct sbc_ops *ops = cmd->protocol_data;
struct se_device *dev = cmd->se_dev;
unsigned char *buf, *ptr = NULL;
sector_t lba;
int size;
u32 range;
sense_reason_t ret = 0;
int dl, bd_dl;
if (cmd->t_task_cdb[1])
return TCM_INVALID_CDB_FIELD;
if (cmd->data_length == 0) {
target_complete_cmd(cmd, SAM_STAT_GOOD);
return 0;
}
if (cmd->data_length < 8) {
pr_warn("UNMAP parameter list length %u too small\n",
cmd->data_length);
return TCM_PARAMETER_LIST_LENGTH_ERROR;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
dl = get_unaligned_be16(&buf[0]);
bd_dl = get_unaligned_be16(&buf[2]);
size = cmd->data_length - 8;
if (bd_dl > size)
pr_warn("UNMAP parameter list length %u too small, ignoring bd_dl %u\n",
cmd->data_length, bd_dl);
else
size = bd_dl;
if (size / 16 > dev->dev_attrib.max_unmap_block_desc_count) {
ret = TCM_INVALID_PARAMETER_LIST;
goto err;
}
ptr = &buf[8];
pr_debug("UNMAP: Sub: %s Using dl: %u bd_dl: %u size: %u"
" ptr: %p\n", dev->transport->name, dl, bd_dl, size, ptr);
while (size >= 16) {
lba = get_unaligned_be64(&ptr[0]);
range = get_unaligned_be32(&ptr[8]);
pr_debug("UNMAP: Using lba: %llu and range: %u\n",
(unsigned long long)lba, range);
if (range > dev->dev_attrib.max_unmap_lba_count) {
ret = TCM_INVALID_PARAMETER_LIST;
goto err;
}
if (lba + range > dev->transport->get_blocks(dev) + 1) {
ret = TCM_ADDRESS_OUT_OF_RANGE;
goto err;
}
ret = ops->execute_unmap(cmd, lba, range);
if (ret)
goto err;
ptr += 16;
size -= 16;
}
err:
transport_kunmap_data_sg(cmd);
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
void
sbc_dif_generate(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct t10_pi_tuple *sdt;
struct scatterlist *dsg = cmd->t_data_sg, *psg;
sector_t sector = cmd->t_task_lba;
void *daddr, *paddr;
int i, j, offset = 0;
unsigned int block_size = dev->dev_attrib.block_size;
for_each_sg(cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
paddr = kmap_atomic(sg_page(psg)) + psg->offset;
daddr = kmap_atomic(sg_page(dsg)) + dsg->offset;
for (j = 0; j < psg->length;
j += sizeof(*sdt)) {
__u16 crc;
unsigned int avail;
if (offset >= dsg->length) {
offset -= dsg->length;
kunmap_atomic(daddr - dsg->offset);
dsg = sg_next(dsg);
if (!dsg) {
kunmap_atomic(paddr - psg->offset);
return;
}
daddr = kmap_atomic(sg_page(dsg)) + dsg->offset;
}
sdt = paddr + j;
avail = min(block_size, dsg->length - offset);
crc = crc_t10dif(daddr + offset, avail);
if (avail < block_size) {
kunmap_atomic(daddr - dsg->offset);
dsg = sg_next(dsg);
if (!dsg) {
kunmap_atomic(paddr - psg->offset);
return;
}
daddr = kmap_atomic(sg_page(dsg)) + dsg->offset;
offset = block_size - avail;
crc = crc_t10dif_update(crc, daddr, offset);
} else {
offset += block_size;
}
sdt->guard_tag = cpu_to_be16(crc);
if (cmd->prot_type == TARGET_DIF_TYPE1_PROT)
sdt->ref_tag = cpu_to_be32(sector & 0xffffffff);
sdt->app_tag = 0;
pr_debug("DIF %s INSERT sector: %llu guard_tag: 0x%04x"
" app_tag: 0x%04x ref_tag: %u\n",
(cmd->data_direction == DMA_TO_DEVICE) ?
"WRITE" : "READ", (unsigned long long)sector,
sdt->guard_tag, sdt->app_tag,
be32_to_cpu(sdt->ref_tag));
sector++;
}
kunmap_atomic(daddr - dsg->offset);
kunmap_atomic(paddr - psg->offset);
}
}
static sense_reason_t
sbc_dif_v1_verify(struct se_cmd *cmd, struct t10_pi_tuple *sdt,
__u16 crc, sector_t sector, unsigned int ei_lba)
{
__be16 csum;
if (!(cmd->prot_checks & TARGET_DIF_CHECK_GUARD))
goto check_ref;
csum = cpu_to_be16(crc);
if (sdt->guard_tag != csum) {
pr_err("DIFv1 checksum failed on sector %llu guard tag 0x%04x"
" csum 0x%04x\n", (unsigned long long)sector,
be16_to_cpu(sdt->guard_tag), be16_to_cpu(csum));
return TCM_LOGICAL_BLOCK_GUARD_CHECK_FAILED;
}
check_ref:
if (!(cmd->prot_checks & TARGET_DIF_CHECK_REFTAG))
return 0;
if (cmd->prot_type == TARGET_DIF_TYPE1_PROT &&
be32_to_cpu(sdt->ref_tag) != (sector & 0xffffffff)) {
pr_err("DIFv1 Type 1 reference failed on sector: %llu tag: 0x%08x"
" sector MSB: 0x%08x\n", (unsigned long long)sector,
be32_to_cpu(sdt->ref_tag), (u32)(sector & 0xffffffff));
return TCM_LOGICAL_BLOCK_REF_TAG_CHECK_FAILED;
}
if (cmd->prot_type == TARGET_DIF_TYPE2_PROT &&
be32_to_cpu(sdt->ref_tag) != ei_lba) {
pr_err("DIFv1 Type 2 reference failed on sector: %llu tag: 0x%08x"
" ei_lba: 0x%08x\n", (unsigned long long)sector,
be32_to_cpu(sdt->ref_tag), ei_lba);
return TCM_LOGICAL_BLOCK_REF_TAG_CHECK_FAILED;
}
return 0;
}
void sbc_dif_copy_prot(struct se_cmd *cmd, unsigned int sectors, bool read,
struct scatterlist *sg, int sg_off)
{
struct se_device *dev = cmd->se_dev;
struct scatterlist *psg;
void *paddr, *addr;
unsigned int i, len, left;
unsigned int offset = sg_off;
if (!sg)
return;
left = sectors * dev->prot_length;
for_each_sg(cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int psg_len, copied = 0;
paddr = kmap_atomic(sg_page(psg)) + psg->offset;
psg_len = min(left, psg->length);
while (psg_len) {
len = min(psg_len, sg->length - offset);
addr = kmap_atomic(sg_page(sg)) + sg->offset + offset;
if (read)
memcpy(paddr + copied, addr, len);
else
memcpy(addr, paddr + copied, len);
left -= len;
offset += len;
copied += len;
psg_len -= len;
kunmap_atomic(addr - sg->offset - offset);
if (offset >= sg->length) {
sg = sg_next(sg);
offset = 0;
}
}
kunmap_atomic(paddr - psg->offset);
}
}
sense_reason_t
sbc_dif_verify(struct se_cmd *cmd, sector_t start, unsigned int sectors,
unsigned int ei_lba, struct scatterlist *psg, int psg_off)
{
struct se_device *dev = cmd->se_dev;
struct t10_pi_tuple *sdt;
struct scatterlist *dsg = cmd->t_data_sg;
sector_t sector = start;
void *daddr, *paddr;
int i;
sense_reason_t rc;
int dsg_off = 0;
unsigned int block_size = dev->dev_attrib.block_size;
for (; psg && sector < start + sectors; psg = sg_next(psg)) {
paddr = kmap_atomic(sg_page(psg)) + psg->offset;
daddr = kmap_atomic(sg_page(dsg)) + dsg->offset;
for (i = psg_off; i < psg->length &&
sector < start + sectors;
i += sizeof(*sdt)) {
__u16 crc;
unsigned int avail;
if (dsg_off >= dsg->length) {
dsg_off -= dsg->length;
kunmap_atomic(daddr - dsg->offset);
dsg = sg_next(dsg);
if (!dsg) {
kunmap_atomic(paddr - psg->offset);
return 0;
}
daddr = kmap_atomic(sg_page(dsg)) + dsg->offset;
}
sdt = paddr + i;
pr_debug("DIF READ sector: %llu guard_tag: 0x%04x"
" app_tag: 0x%04x ref_tag: %u\n",
(unsigned long long)sector, sdt->guard_tag,
sdt->app_tag, be32_to_cpu(sdt->ref_tag));
if (sdt->app_tag == cpu_to_be16(0xffff)) {
dsg_off += block_size;
goto next;
}
avail = min(block_size, dsg->length - dsg_off);
crc = crc_t10dif(daddr + dsg_off, avail);
if (avail < block_size) {
kunmap_atomic(daddr - dsg->offset);
dsg = sg_next(dsg);
if (!dsg) {
kunmap_atomic(paddr - psg->offset);
return 0;
}
daddr = kmap_atomic(sg_page(dsg)) + dsg->offset;
dsg_off = block_size - avail;
crc = crc_t10dif_update(crc, daddr, dsg_off);
} else {
dsg_off += block_size;
}
rc = sbc_dif_v1_verify(cmd, sdt, crc, sector, ei_lba);
if (rc) {
kunmap_atomic(daddr - dsg->offset);
kunmap_atomic(paddr - psg->offset);
cmd->bad_sector = sector;
return rc;
}
next:
sector++;
ei_lba++;
}
psg_off = 0;
kunmap_atomic(daddr - dsg->offset);
kunmap_atomic(paddr - psg->offset);
}
return 0;
}
