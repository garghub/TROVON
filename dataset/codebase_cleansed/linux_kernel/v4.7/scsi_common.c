const char *scsi_device_type(unsigned type)
{
if (type == 0x1e)
return "Well-known LUN ";
if (type == 0x1f)
return "No Device ";
if (type >= ARRAY_SIZE(scsi_device_types))
return "Unknown ";
return scsi_device_types[type];
}
u64 scsilun_to_int(struct scsi_lun *scsilun)
{
int i;
u64 lun;
lun = 0;
for (i = 0; i < sizeof(lun); i += 2)
lun = lun | (((u64)scsilun->scsi_lun[i] << ((i + 1) * 8)) |
((u64)scsilun->scsi_lun[i + 1] << (i * 8)));
return lun;
}
void int_to_scsilun(u64 lun, struct scsi_lun *scsilun)
{
int i;
memset(scsilun->scsi_lun, 0, sizeof(scsilun->scsi_lun));
for (i = 0; i < sizeof(lun); i += 2) {
scsilun->scsi_lun[i] = (lun >> 8) & 0xFF;
scsilun->scsi_lun[i+1] = lun & 0xFF;
lun = lun >> 16;
}
}
bool scsi_normalize_sense(const u8 *sense_buffer, int sb_len,
struct scsi_sense_hdr *sshdr)
{
if (!sense_buffer || !sb_len)
return false;
memset(sshdr, 0, sizeof(struct scsi_sense_hdr));
sshdr->response_code = (sense_buffer[0] & 0x7f);
if (!scsi_sense_valid(sshdr))
return false;
if (sshdr->response_code >= 0x72) {
if (sb_len > 1)
sshdr->sense_key = (sense_buffer[1] & 0xf);
if (sb_len > 2)
sshdr->asc = sense_buffer[2];
if (sb_len > 3)
sshdr->ascq = sense_buffer[3];
if (sb_len > 7)
sshdr->additional_length = sense_buffer[7];
} else {
if (sb_len > 2)
sshdr->sense_key = (sense_buffer[2] & 0xf);
if (sb_len > 7) {
sb_len = (sb_len < (sense_buffer[7] + 8)) ?
sb_len : (sense_buffer[7] + 8);
if (sb_len > 12)
sshdr->asc = sense_buffer[12];
if (sb_len > 13)
sshdr->ascq = sense_buffer[13];
}
}
return true;
}
const u8 * scsi_sense_desc_find(const u8 * sense_buffer, int sb_len,
int desc_type)
{
int add_sen_len, add_len, desc_len, k;
const u8 * descp;
if ((sb_len < 8) || (0 == (add_sen_len = sense_buffer[7])))
return NULL;
if ((sense_buffer[0] < 0x72) || (sense_buffer[0] > 0x73))
return NULL;
add_sen_len = (add_sen_len < (sb_len - 8)) ?
add_sen_len : (sb_len - 8);
descp = &sense_buffer[8];
for (desc_len = 0, k = 0; k < add_sen_len; k += desc_len) {
descp += desc_len;
add_len = (k < (add_sen_len - 1)) ? descp[1]: -1;
desc_len = add_len + 2;
if (descp[0] == desc_type)
return descp;
if (add_len < 0)
break;
}
return NULL;
}
void scsi_build_sense_buffer(int desc, u8 *buf, u8 key, u8 asc, u8 ascq)
{
if (desc) {
buf[0] = 0x72;
buf[1] = key;
buf[2] = asc;
buf[3] = ascq;
buf[7] = 0;
} else {
buf[0] = 0x70;
buf[2] = key;
buf[7] = 0xa;
buf[12] = asc;
buf[13] = ascq;
}
}
int scsi_set_sense_information(u8 *buf, int buf_len, u64 info)
{
if ((buf[0] & 0x7f) == 0x72) {
u8 *ucp, len;
len = buf[7];
ucp = (char *)scsi_sense_desc_find(buf, len + 8, 0);
if (!ucp) {
buf[7] = len + 0xc;
ucp = buf + 8 + len;
}
if (buf_len < len + 0xc)
return -EINVAL;
ucp[0] = 0;
ucp[1] = 0xa;
ucp[2] = 0x80;
ucp[3] = 0;
put_unaligned_be64(info, &ucp[4]);
} else if ((buf[0] & 0x7f) == 0x70) {
if (info <= 0xffffffffUL)
buf[0] |= 0x80;
else
buf[0] &= 0x7f;
put_unaligned_be32((u32)info, &buf[3]);
}
return 0;
}
int scsi_set_sense_field_pointer(u8 *buf, int buf_len, u16 fp, u8 bp, bool cd)
{
u8 *ucp, len;
if ((buf[0] & 0x7f) == 0x72) {
len = buf[7];
ucp = (char *)scsi_sense_desc_find(buf, len + 8, 2);
if (!ucp) {
buf[7] = len + 8;
ucp = buf + 8 + len;
}
if (buf_len < len + 8)
return -EINVAL;
ucp[0] = 2;
ucp[1] = 6;
ucp[4] = 0x80;
if (cd)
ucp[4] |= 0x40;
if (bp < 0x8)
ucp[4] |= 0x8 | bp;
put_unaligned_be16(fp, &ucp[5]);
} else if ((buf[0] & 0x7f) == 0x70) {
len = buf[7];
if (len < 18)
buf[7] = 18;
buf[15] = 0x80;
if (cd)
buf[15] |= 0x40;
if (bp < 0x8)
buf[15] |= 0x8 | bp;
put_unaligned_be16(fp, &buf[16]);
}
return 0;
}
