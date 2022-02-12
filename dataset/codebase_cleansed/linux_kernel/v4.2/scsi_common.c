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
