void usb_stor_pad12_command(struct scsi_cmnd *srb, struct us_data *us)
{
for (; srb->cmd_len<12; srb->cmd_len++)
srb->cmnd[srb->cmd_len] = 0;
usb_stor_invoke_transport(srb, us);
}
void usb_stor_ufi_command(struct scsi_cmnd *srb, struct us_data *us)
{
for (; srb->cmd_len<12; srb->cmd_len++)
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
unsigned int cnt;
struct scatterlist *sg = *sgptr;
if (!sg)
sg = scsi_sglist(srb);
cnt = 0;
while (cnt < buflen && sg) {
struct page *page = sg_page(sg) +
((sg->offset + *offset) >> PAGE_SHIFT);
unsigned int poff = (sg->offset + *offset) & (PAGE_SIZE-1);
unsigned int sglen = sg->length - *offset;
if (sglen > buflen - cnt) {
sglen = buflen - cnt;
*offset += sglen;
} else {
*offset = 0;
sg = sg_next(sg);
}
while (sglen > 0) {
unsigned int plen = min(sglen, (unsigned int)
PAGE_SIZE - poff);
unsigned char *ptr = kmap(page);
if (dir == TO_XFER_BUF)
memcpy(ptr + poff, buffer + cnt, plen);
else
memcpy(buffer + cnt, ptr + poff, plen);
kunmap(page);
poff = 0;
++page;
cnt += plen;
sglen -= plen;
}
}
*sgptr = sg;
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
