static void ene_ub6250_info_destructor(void *extra)
{
if (!extra)
return;
}
static int ene_send_scsi_cmd(struct us_data *us, u8 fDir, void *buf, int use_sg)
{
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
struct bulk_cs_wrap *bcs = (struct bulk_cs_wrap *) us->iobuf;
int result;
unsigned int residue;
unsigned int cswlen = 0, partial = 0;
unsigned int transfer_length = bcb->DataTransferLength;
result = usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe,
bcb, US_BULK_CB_WRAP_LEN, NULL);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("send cmd to out endpoint fail ---\n");
return USB_STOR_TRANSPORT_ERROR;
}
if (buf) {
unsigned int pipe = fDir;
if (fDir == FDIR_READ)
pipe = us->recv_bulk_pipe;
else
pipe = us->send_bulk_pipe;
if (use_sg) {
result = usb_stor_bulk_srb(us, pipe, us->srb);
} else {
result = usb_stor_bulk_transfer_sg(us, pipe, buf,
transfer_length, 0, &partial);
}
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("data transfer fail ---\n");
return USB_STOR_TRANSPORT_ERROR;
}
}
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe, bcs,
US_BULK_CS_WRAP_LEN, &cswlen);
if (result == USB_STOR_XFER_SHORT && cswlen == 0) {
US_DEBUGP("Received 0-length CSW; retrying...\n");
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
bcs, US_BULK_CS_WRAP_LEN, &cswlen);
}
if (result == USB_STOR_XFER_STALLED) {
US_DEBUGP("Attempting to get CSW (2nd try)...\n");
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
bcs, US_BULK_CS_WRAP_LEN, NULL);
}
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
residue = le32_to_cpu(bcs->Residue);
if (residue && !(us->fflags & US_FL_IGNORE_RESIDUE)) {
residue = min(residue, transfer_length);
if (us->srb != NULL)
scsi_set_resid(us->srb, max(scsi_get_resid(us->srb),
(int)residue));
}
if (bcs->Status != US_BULK_STAT_OK)
return USB_STOR_TRANSPORT_ERROR;
return USB_STOR_TRANSPORT_GOOD;
}
static int sd_scsi_test_unit_ready(struct us_data *us, struct scsi_cmnd *srb)
{
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
if (info->SD_Status.Insert && info->SD_Status.Ready)
return USB_STOR_TRANSPORT_GOOD;
else {
ene_sd_init(us);
return USB_STOR_TRANSPORT_GOOD;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int sd_scsi_inquiry(struct us_data *us, struct scsi_cmnd *srb)
{
unsigned char data_ptr[36] = {
0x00, 0x80, 0x02, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x55,
0x53, 0x42, 0x32, 0x2E, 0x30, 0x20, 0x20, 0x43, 0x61,
0x72, 0x64, 0x52, 0x65, 0x61, 0x64, 0x65, 0x72, 0x20,
0x20, 0x20, 0x20, 0x20, 0x20, 0x30, 0x31, 0x30, 0x30 };
usb_stor_set_xfer_buf(data_ptr, 36, srb);
return USB_STOR_TRANSPORT_GOOD;
}
static int sd_scsi_mode_sense(struct us_data *us, struct scsi_cmnd *srb)
{
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
unsigned char mediaNoWP[12] = {
0x0b, 0x00, 0x00, 0x08, 0x00, 0x00,
0x71, 0xc0, 0x00, 0x00, 0x02, 0x00 };
unsigned char mediaWP[12] = {
0x0b, 0x00, 0x80, 0x08, 0x00, 0x00,
0x71, 0xc0, 0x00, 0x00, 0x02, 0x00 };
if (info->SD_Status.WtP)
usb_stor_set_xfer_buf(mediaWP, 12, srb);
else
usb_stor_set_xfer_buf(mediaNoWP, 12, srb);
return USB_STOR_TRANSPORT_GOOD;
}
static int sd_scsi_read_capacity(struct us_data *us, struct scsi_cmnd *srb)
{
u32 bl_num;
u16 bl_len;
unsigned int offset = 0;
unsigned char buf[8];
struct scatterlist *sg = NULL;
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
US_DEBUGP("sd_scsi_read_capacity\n");
if (info->SD_Status.HiCapacity) {
bl_len = 0x200;
if (info->SD_Status.IsMMC)
bl_num = info->HC_C_SIZE-1;
else
bl_num = (info->HC_C_SIZE + 1) * 1024 - 1;
} else {
bl_len = 1<<(info->SD_READ_BL_LEN);
bl_num = info->SD_Block_Mult * (info->SD_C_SIZE + 1)
* (1 << (info->SD_C_SIZE_MULT + 2)) - 1;
}
info->bl_num = bl_num;
US_DEBUGP("bl_len = %x\n", bl_len);
US_DEBUGP("bl_num = %x\n", bl_num);
buf[0] = (bl_num >> 24) & 0xff;
buf[1] = (bl_num >> 16) & 0xff;
buf[2] = (bl_num >> 8) & 0xff;
buf[3] = (bl_num >> 0) & 0xff;
buf[4] = (bl_len >> 24) & 0xff;
buf[5] = (bl_len >> 16) & 0xff;
buf[6] = (bl_len >> 8) & 0xff;
buf[7] = (bl_len >> 0) & 0xff;
usb_stor_access_xfer_buf(buf, 8, srb, &sg, &offset, TO_XFER_BUF);
return USB_STOR_TRANSPORT_GOOD;
}
static int sd_scsi_read(struct us_data *us, struct scsi_cmnd *srb)
{
int result;
unsigned char *cdb = srb->cmnd;
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
u32 bn = ((cdb[2] << 24) & 0xff000000) | ((cdb[3] << 16) & 0x00ff0000) |
((cdb[4] << 8) & 0x0000ff00) | ((cdb[5] << 0) & 0x000000ff);
u16 blen = ((cdb[7] << 8) & 0xff00) | ((cdb[8] << 0) & 0x00ff);
u32 bnByte = bn * 0x200;
u32 blenByte = blen * 0x200;
if (bn > info->bl_num)
return USB_STOR_TRANSPORT_ERROR;
result = ene_load_bincode(us, SD_RW_PATTERN);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("Load SD RW pattern Fail !!\n");
return USB_STOR_TRANSPORT_ERROR;
}
if (info->SD_Status.HiCapacity)
bnByte = bn;
memset(bcb, 0, sizeof(struct bulk_cb_wrap));
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->DataTransferLength = blenByte;
bcb->Flags = 0x80;
bcb->CDB[0] = 0xF1;
bcb->CDB[5] = (unsigned char)(bnByte);
bcb->CDB[4] = (unsigned char)(bnByte>>8);
bcb->CDB[3] = (unsigned char)(bnByte>>16);
bcb->CDB[2] = (unsigned char)(bnByte>>24);
result = ene_send_scsi_cmd(us, FDIR_READ, scsi_sglist(srb), 1);
return result;
}
static int sd_scsi_write(struct us_data *us, struct scsi_cmnd *srb)
{
int result;
unsigned char *cdb = srb->cmnd;
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
u32 bn = ((cdb[2] << 24) & 0xff000000) | ((cdb[3] << 16) & 0x00ff0000) |
((cdb[4] << 8) & 0x0000ff00) | ((cdb[5] << 0) & 0x000000ff);
u16 blen = ((cdb[7] << 8) & 0xff00) | ((cdb[8] << 0) & 0x00ff);
u32 bnByte = bn * 0x200;
u32 blenByte = blen * 0x200;
if (bn > info->bl_num)
return USB_STOR_TRANSPORT_ERROR;
result = ene_load_bincode(us, SD_RW_PATTERN);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("Load SD RW pattern Fail !!\n");
return USB_STOR_TRANSPORT_ERROR;
}
if (info->SD_Status.HiCapacity)
bnByte = bn;
memset(bcb, 0, sizeof(struct bulk_cb_wrap));
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->DataTransferLength = blenByte;
bcb->Flags = 0x00;
bcb->CDB[0] = 0xF0;
bcb->CDB[5] = (unsigned char)(bnByte);
bcb->CDB[4] = (unsigned char)(bnByte>>8);
bcb->CDB[3] = (unsigned char)(bnByte>>16);
bcb->CDB[2] = (unsigned char)(bnByte>>24);
result = ene_send_scsi_cmd(us, FDIR_WRITE, scsi_sglist(srb), 1);
return result;
}
static int ene_get_card_type(struct us_data *us, u16 index, void *buf)
{
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
int result;
memset(bcb, 0, sizeof(struct bulk_cb_wrap));
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->DataTransferLength = 0x01;
bcb->Flags = 0x80;
bcb->CDB[0] = 0xED;
bcb->CDB[2] = (unsigned char)(index>>8);
bcb->CDB[3] = (unsigned char)index;
result = ene_send_scsi_cmd(us, FDIR_READ, buf, 0);
return result;
}
static int ene_get_card_status(struct us_data *us, u8 *buf)
{
u16 tmpreg;
u32 reg4b;
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
reg4b = *(u32 *)&buf[0x18];
info->SD_READ_BL_LEN = (u8)((reg4b >> 8) & 0x0f);
tmpreg = (u16) reg4b;
reg4b = *(u32 *)(&buf[0x14]);
if (info->SD_Status.HiCapacity && !info->SD_Status.IsMMC)
info->HC_C_SIZE = (reg4b >> 8) & 0x3fffff;
info->SD_C_SIZE = ((tmpreg & 0x03) << 10) | (u16)(reg4b >> 22);
info->SD_C_SIZE_MULT = (u8)(reg4b >> 7) & 0x07;
if (info->SD_Status.HiCapacity && info->SD_Status.IsMMC)
info->HC_C_SIZE = *(u32 *)(&buf[0x100]);
if (info->SD_READ_BL_LEN > SD_BLOCK_LEN) {
info->SD_Block_Mult = 1 << (info->SD_READ_BL_LEN-SD_BLOCK_LEN);
info->SD_READ_BL_LEN = SD_BLOCK_LEN;
} else {
info->SD_Block_Mult = 1;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int ene_load_bincode(struct us_data *us, unsigned char flag)
{
int err;
char *fw_name = NULL;
unsigned char *buf = NULL;
const struct firmware *sd_fw = NULL;
int result = USB_STOR_TRANSPORT_ERROR;
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
if (info->BIN_FLAG == flag)
return USB_STOR_TRANSPORT_GOOD;
switch (flag) {
case SD_INIT1_PATTERN:
US_DEBUGP("SD_INIT1_PATTERN\n");
fw_name = "ene-ub6250/sd_init1.bin";
break;
case SD_INIT2_PATTERN:
US_DEBUGP("SD_INIT2_PATTERN\n");
fw_name = "ene-ub6250/sd_init2.bin";
break;
case SD_RW_PATTERN:
US_DEBUGP("SD_RDWR_PATTERN\n");
fw_name = "ene-ub6250/sd_rdwr.bin";
break;
default:
US_DEBUGP("----------- Unknown PATTERN ----------\n");
goto nofw;
}
err = request_firmware(&sd_fw, fw_name, &us->pusb_dev->dev);
if (err) {
US_DEBUGP("load firmware %s failed\n", fw_name);
goto nofw;
}
buf = kmalloc(sd_fw->size, GFP_KERNEL);
if (buf == NULL) {
US_DEBUGP("Malloc memory for fireware failed!\n");
goto nofw;
}
memcpy(buf, sd_fw->data, sd_fw->size);
memset(bcb, 0, sizeof(struct bulk_cb_wrap));
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->DataTransferLength = sd_fw->size;
bcb->Flags = 0x00;
bcb->CDB[0] = 0xEF;
result = ene_send_scsi_cmd(us, FDIR_WRITE, buf, 0);
info->BIN_FLAG = flag;
kfree(buf);
nofw:
if (sd_fw != NULL) {
release_firmware(sd_fw);
sd_fw = NULL;
}
return result;
}
static int ene_sd_init(struct us_data *us)
{
int result;
u8 buf[0x200];
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
struct ene_ub6250_info *info = (struct ene_ub6250_info *) us->extra;
US_DEBUGP("transport --- ENE_SDInit\n");
result = ene_load_bincode(us, SD_INIT1_PATTERN);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("Load SD Init Code Part-1 Fail !!\n");
return USB_STOR_TRANSPORT_ERROR;
}
memset(bcb, 0, sizeof(struct bulk_cb_wrap));
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->Flags = 0x80;
bcb->CDB[0] = 0xF2;
result = ene_send_scsi_cmd(us, FDIR_READ, NULL, 0);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("Execution SD Init Code Fail !!\n");
return USB_STOR_TRANSPORT_ERROR;
}
result = ene_load_bincode(us, SD_INIT2_PATTERN);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("Load SD Init Code Part-2 Fail !!\n");
return USB_STOR_TRANSPORT_ERROR;
}
memset(bcb, 0, sizeof(struct bulk_cb_wrap));
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->DataTransferLength = 0x200;
bcb->Flags = 0x80;
bcb->CDB[0] = 0xF1;
result = ene_send_scsi_cmd(us, FDIR_READ, &buf, 0);
if (result != USB_STOR_XFER_GOOD) {
US_DEBUGP("Execution SD Init Code Fail !!\n");
return USB_STOR_TRANSPORT_ERROR;
}
info->SD_Status = *(struct SD_STATUS *)&buf[0];
if (info->SD_Status.Insert && info->SD_Status.Ready) {
ene_get_card_status(us, (unsigned char *)&buf);
US_DEBUGP("Insert = %x\n", info->SD_Status.Insert);
US_DEBUGP("Ready = %x\n", info->SD_Status.Ready);
US_DEBUGP("IsMMC = %x\n", info->SD_Status.IsMMC);
US_DEBUGP("HiCapacity = %x\n", info->SD_Status.HiCapacity);
US_DEBUGP("HiSpeed = %x\n", info->SD_Status.HiSpeed);
US_DEBUGP("WtP = %x\n", info->SD_Status.WtP);
} else {
US_DEBUGP("SD Card Not Ready --- %x\n", buf[0]);
return USB_STOR_TRANSPORT_ERROR;
}
return USB_STOR_TRANSPORT_GOOD;
}
static int ene_init(struct us_data *us)
{
int result;
u8 misc_reg03 = 0;
struct ene_ub6250_info *info = (struct ene_ub6250_info *)(us->extra);
result = ene_get_card_type(us, REG_CARD_STATUS, &misc_reg03);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (misc_reg03 & 0x01) {
if (!info->SD_Status.Ready) {
result = ene_sd_init(us);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
}
}
return result;
}
static int sd_scsi_irp(struct us_data *us, struct scsi_cmnd *srb)
{
int result;
struct ene_ub6250_info *info = (struct ene_ub6250_info *)us->extra;
info->SrbStatus = SS_SUCCESS;
switch (srb->cmnd[0]) {
case TEST_UNIT_READY:
result = sd_scsi_test_unit_ready(us, srb);
break;
case INQUIRY:
result = sd_scsi_inquiry(us, srb);
break;
case MODE_SENSE:
result = sd_scsi_mode_sense(us, srb);
break;
case READ_CAPACITY:
result = sd_scsi_read_capacity(us, srb);
break;
case READ_10:
result = sd_scsi_read(us, srb);
break;
case WRITE_10:
result = sd_scsi_write(us, srb);
break;
default:
info->SrbStatus = SS_ILLEGAL_REQUEST;
result = USB_STOR_TRANSPORT_FAILED;
break;
}
return result;
}
static int ene_transport(struct scsi_cmnd *srb, struct us_data *us)
{
int result = 0;
struct ene_ub6250_info *info = (struct ene_ub6250_info *)(us->extra);
scsi_set_resid(srb, 0);
if (unlikely(!info->SD_Status.Ready))
result = ene_init(us);
else
result = sd_scsi_irp(us, srb);
return 0;
}
static int ene_ub6250_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int result;
u8 misc_reg03 = 0;
struct us_data *us;
result = usb_stor_probe1(&us, intf, id,
(id - ene_ub6250_usb_ids) + ene_ub6250_unusual_dev_list);
if (result)
return result;
if (!us->extra) {
us->extra = kzalloc(sizeof(struct ene_ub6250_info), GFP_KERNEL);
if (!us->extra)
return -ENOMEM;
us->extra_destructor = ene_ub6250_info_destructor;
}
us->transport_name = "ene_ub6250";
us->transport = ene_transport;
us->max_lun = 0;
result = usb_stor_probe2(us);
if (result)
return result;
result = ene_get_card_type(us, REG_CARD_STATUS, &misc_reg03);
if (result != USB_STOR_XFER_GOOD) {
usb_stor_disconnect(intf);
return USB_STOR_TRANSPORT_ERROR;
}
if (!(misc_reg03 & 0x01)) {
result = -ENODEV;
printk(KERN_NOTICE "ums_eneub6250: The driver only supports SD card. "
"To use SM/MS card, please build driver/staging/keucr\n");
usb_stor_disconnect(intf);
}
return result;
}
static int ene_ub6250_resume(struct usb_interface *iface)
{
u8 tmp = 0;
struct us_data *us = usb_get_intfdata(iface);
struct ene_ub6250_info *info = (struct ene_ub6250_info *)(us->extra);
mutex_lock(&us->dev_mutex);
US_DEBUGP("%s\n", __func__);
if (us->suspend_resume_hook)
(us->suspend_resume_hook)(us, US_RESUME);
mutex_unlock(&us->dev_mutex);
info->Power_IsResum = true;
info->SD_Status = *(struct SD_STATUS *)&tmp;
info->MS_Status = *(struct MS_STATUS *)&tmp;
info->SM_Status = *(struct SM_STATUS *)&tmp;
return 0;
}
static int ene_ub6250_reset_resume(struct usb_interface *iface)
{
u8 tmp = 0;
struct us_data *us = usb_get_intfdata(iface);
struct ene_ub6250_info *info = (struct ene_ub6250_info *)(us->extra);
US_DEBUGP("%s\n", __func__);
usb_stor_reset_resume(iface);
info->Power_IsResum = true;
info->SD_Status = *(struct SD_STATUS *)&tmp;
info->MS_Status = *(struct MS_STATUS *)&tmp;
info->SM_Status = *(struct SM_STATUS *)&tmp;
return 0;
}
static int __init ene_ub6250_init(void)
{
return usb_register(&ene_ub6250_driver);
}
static void __exit ene_ub6250_exit(void)
{
usb_deregister(&ene_ub6250_driver);
}
