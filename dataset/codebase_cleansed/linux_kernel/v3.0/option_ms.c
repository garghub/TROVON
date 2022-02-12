static int option_rezero(struct us_data *us)
{
const unsigned char rezero_msg[] = {
0x55, 0x53, 0x42, 0x43, 0x78, 0x56, 0x34, 0x12,
0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x06, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
char *buffer;
int result;
US_DEBUGP("Option MS: %s", "DEVICE MODE SWITCH\n");
buffer = kzalloc(RESPONSE_LEN, GFP_KERNEL);
if (buffer == NULL)
return USB_STOR_TRANSPORT_ERROR;
memcpy(buffer, rezero_msg, sizeof(rezero_msg));
result = usb_stor_bulk_transfer_buf(us,
us->send_bulk_pipe,
buffer, sizeof(rezero_msg), NULL);
if (result != USB_STOR_XFER_GOOD) {
result = USB_STOR_XFER_ERROR;
goto out;
}
usb_stor_bulk_transfer_buf(us,
us->recv_bulk_pipe,
buffer, RESPONSE_LEN, NULL);
usb_stor_bulk_transfer_buf(us,
us->recv_bulk_pipe,
buffer, 13, NULL);
result = USB_STOR_XFER_GOOD;
out:
kfree(buffer);
return result;
}
static int option_inquiry(struct us_data *us)
{
const unsigned char inquiry_msg[] = {
0x55, 0x53, 0x42, 0x43, 0x12, 0x34, 0x56, 0x78,
0x24, 0x00, 0x00, 0x00, 0x80, 0x00, 0x06, 0x12,
0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
char *buffer;
int result;
US_DEBUGP("Option MS: %s", "device inquiry for vendor name\n");
buffer = kzalloc(0x24, GFP_KERNEL);
if (buffer == NULL)
return USB_STOR_TRANSPORT_ERROR;
memcpy(buffer, inquiry_msg, sizeof(inquiry_msg));
result = usb_stor_bulk_transfer_buf(us,
us->send_bulk_pipe,
buffer, sizeof(inquiry_msg), NULL);
if (result != USB_STOR_XFER_GOOD) {
result = USB_STOR_XFER_ERROR;
goto out;
}
result = usb_stor_bulk_transfer_buf(us,
us->recv_bulk_pipe,
buffer, 0x24, NULL);
if (result != USB_STOR_XFER_GOOD) {
result = USB_STOR_XFER_ERROR;
goto out;
}
result = memcmp(buffer+8, "Option", 6);
if (result != 0)
result = memcmp(buffer+8, "ZCOPTION", 8);
usb_stor_bulk_transfer_buf(us,
us->recv_bulk_pipe,
buffer, 13, NULL);
out:
kfree(buffer);
return result;
}
int option_ms_init(struct us_data *us)
{
int result;
US_DEBUGP("Option MS: option_ms_init called\n");
result = option_inquiry(us);
if (result != 0) {
US_DEBUGP("Option MS: vendor is not Option or not determinable,"
" no action taken\n");
return 0;
} else
US_DEBUGP("Option MS: this is a genuine Option device,"
" proceeding\n");
if (option_zero_cd == ZCD_FORCE_MODEM) {
US_DEBUGP("Option MS: %s", "Forcing Modem Mode\n");
result = option_rezero(us);
if (result != USB_STOR_XFER_GOOD)
US_DEBUGP("Option MS: Failed to switch to modem mode.\n");
return -EIO;
} else if (option_zero_cd == ZCD_ALLOW_MS) {
US_DEBUGP("Option MS: %s", "Allowing Mass Storage Mode if device"
" requests it\n");
}
return 0;
}
