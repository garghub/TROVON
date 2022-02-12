void usb_stor_pad12_command(struct scsi_cmnd *srb, struct us_data *us)
{
for (; srb->cmd_len < 12; srb->cmd_len++)
srb->cmnd[srb->cmd_len] = 0;
usb_stor_invoke_transport(srb, us);
}
void usb_stor_ufi_command(struct scsi_cmnd *srb, struct us_data *us)
{
for (; srb->cmd_len < 12; srb->cmd_len++)
srb->cmnd[srb->cmd_len] = 0;
srb->cmd_len = 12;
switch (srb->cmnd[0]) {
case INQUIRY:
srb->cmnd[4] = 36;
break;
case MODE_SENSE_10:
srb->cmnd[7] = 0;
srb->cmnd[8] = 8;
break;
case REQUEST_SENSE:
srb->cmnd[4] = 18;
break;
}
usb_stor_invoke_transport(srb, us);
}
void usb_stor_transparent_scsi_command(struct scsi_cmnd *srb,
struct us_data *us)
{
usb_stor_invoke_transport(srb, us);
}
unsigned int usb_stor_access_xfer_buf(unsigned char *buffer,
unsigned int buflen, struct scsi_cmnd *srb, struct scatterlist **sgptr,
unsigned int *offset, enum xfer_buf_dir dir)
{
unsigned int cnt = 0;
struct scatterlist *sg = *sgptr;
struct sg_mapping_iter miter;
unsigned int nents = scsi_sg_count(srb);
if (sg)
nents = sg_nents(sg);
else
sg = scsi_sglist(srb);
sg_miter_start(&miter, sg, nents, dir == FROM_XFER_BUF ?
SG_MITER_FROM_SG: SG_MITER_TO_SG);
if (!sg_miter_skip(&miter, *offset))
return cnt;
while (sg_miter_next(&miter) && cnt < buflen) {
unsigned int len = min_t(unsigned int, miter.length,
buflen - cnt);
if (dir == FROM_XFER_BUF)
memcpy(buffer + cnt, miter.addr, len);
else
memcpy(miter.addr, buffer + cnt, len);
if (*offset + len < miter.piter.sg->length) {
*offset += len;
*sgptr = miter.piter.sg;
} else {
*offset = 0;
*sgptr = sg_next(miter.piter.sg);
}
cnt += len;
}
sg_miter_stop(&miter);
return cnt;
}
void usb_stor_set_xfer_buf(unsigned char *buffer,
unsigned int buflen, struct scsi_cmnd *srb)
{
unsigned int offset = 0;
struct scatterlist *sg = NULL;
buflen = min(buflen, scsi_bufflen(srb));
buflen = usb_stor_access_xfer_buf(buffer, buflen, srb, &sg, &offset,
TO_XFER_BUF);
if (buflen < scsi_bufflen(srb))
scsi_set_resid(srb, scsi_bufflen(srb) - buflen);
}
