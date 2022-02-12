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
int usb_stor_huawei_e220_init(struct us_data *us)
{
int result;
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
USB_REQ_SET_FEATURE,
USB_TYPE_STANDARD | USB_RECIP_DEVICE,
0x01, 0x0, NULL, 0x0, 1000);
US_DEBUGP("Huawei mode set result is %d\n", result);
return 0;
}
