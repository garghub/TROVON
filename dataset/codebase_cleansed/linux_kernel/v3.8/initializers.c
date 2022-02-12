int usb_stor_euscsi_init(struct us_data *us)
{
int result;
US_DEBUGP("Attempting to init eUSCSI bridge...\n");
us->iobuf[0] = 0x1;
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
0x0C, USB_RECIP_INTERFACE | USB_TYPE_VENDOR,
0x01, 0x0, us->iobuf, 0x1, 5000);
US_DEBUGP("-- result is %d\n", result);
return 0;
}
int usb_stor_ucr61s2b_init(struct us_data *us)
{
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap*) us->iobuf;
struct bulk_cs_wrap *bcs = (struct bulk_cs_wrap*) us->iobuf;
int res;
unsigned int partial;
static char init_string[] = "\xec\x0a\x06\x00$PCCHIPS";
US_DEBUGP("Sending UCR-61S2B initialization packet...\n");
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->Tag = 0;
bcb->DataTransferLength = cpu_to_le32(0);
bcb->Flags = bcb->Lun = 0;
bcb->Length = sizeof(init_string) - 1;
memset(bcb->CDB, 0, sizeof(bcb->CDB));
memcpy(bcb->CDB, init_string, sizeof(init_string) - 1);
res = usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe, bcb,
US_BULK_CB_WRAP_LEN, &partial);
if (res)
return -EIO;
US_DEBUGP("Getting status packet...\n");
res = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe, bcs,
US_BULK_CS_WRAP_LEN, &partial);
if (res)
return -EIO;
return 0;
}
static int usb_stor_huawei_feature_init(struct us_data *us)
{
int result;
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
USB_REQ_SET_FEATURE,
USB_TYPE_STANDARD | USB_RECIP_DEVICE,
0x01, 0x0, NULL, 0x0, 1000);
US_DEBUGP("Huawei mode set result is %d\n", result);
return 0;
}
static int usb_stor_huawei_scsi_init(struct us_data *us)
{
int result = 0;
int act_len = 0;
struct bulk_cb_wrap *bcbw = (struct bulk_cb_wrap *) us->iobuf;
char rewind_cmd[] = {0x11, 0x06, 0x20, 0x00, 0x00, 0x01, 0x01, 0x00,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
bcbw->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcbw->Tag = 0;
bcbw->DataTransferLength = 0;
bcbw->Flags = bcbw->Lun = 0;
bcbw->Length = sizeof(rewind_cmd);
memset(bcbw->CDB, 0, sizeof(bcbw->CDB));
memcpy(bcbw->CDB, rewind_cmd, sizeof(rewind_cmd));
result = usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe, bcbw,
US_BULK_CB_WRAP_LEN, &act_len);
US_DEBUGP("transfer actual length=%d, result=%d\n", act_len, result);
return result;
}
static int usb_stor_huawei_dongles_pid(struct us_data *us)
{
struct usb_interface_descriptor *idesc;
int idProduct;
idesc = &us->pusb_intf->cur_altsetting->desc;
idProduct = us->pusb_dev->descriptor.idProduct;
if (idesc && idesc->bInterfaceNumber == 0) {
if ((idProduct == 0x1001)
|| (idProduct == 0x1003)
|| (idProduct == 0x1004)
|| (idProduct >= 0x1401 && idProduct <= 0x1500)
|| (idProduct >= 0x1505 && idProduct <= 0x1600)
|| (idProduct >= 0x1c02 && idProduct <= 0x2202)) {
return 1;
}
}
return 0;
}
int usb_stor_huawei_init(struct us_data *us)
{
int result = 0;
if (usb_stor_huawei_dongles_pid(us)) {
if (us->pusb_dev->descriptor.idProduct >= 0x1446)
result = usb_stor_huawei_scsi_init(us);
else
result = usb_stor_huawei_feature_init(us);
}
return result;
}
