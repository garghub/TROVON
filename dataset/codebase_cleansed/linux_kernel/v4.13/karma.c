static int rio_karma_send_command(char cmd, struct us_data *us)
{
int result;
unsigned long timeout;
static unsigned char seq = 1;
struct karma_data *data = (struct karma_data *) us->extra;
usb_stor_dbg(us, "sending command %04x\n", cmd);
memset(us->iobuf, 0, RIO_SEND_LEN);
memcpy(us->iobuf, RIO_PREFIX, RIO_PREFIX_LEN);
us->iobuf[5] = cmd;
us->iobuf[6] = seq;
timeout = jiffies + msecs_to_jiffies(6000);
for (;;) {
result = usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe,
us->iobuf, RIO_SEND_LEN, NULL);
if (result != USB_STOR_XFER_GOOD)
goto err;
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
data->recv, RIO_RECV_LEN, NULL);
if (result != USB_STOR_XFER_GOOD)
goto err;
if (data->recv[5] == seq)
break;
if (time_after(jiffies, timeout))
goto err;
us->iobuf[4] = 0x80;
us->iobuf[5] = 0;
msleep(50);
}
seq++;
if (seq == 0)
seq = 1;
usb_stor_dbg(us, "sent command %04x\n", cmd);
return 0;
err:
usb_stor_dbg(us, "command %04x failed\n", cmd);
return USB_STOR_TRANSPORT_FAILED;
}
static int rio_karma_transport(struct scsi_cmnd *srb, struct us_data *us)
{
int ret;
struct karma_data *data = (struct karma_data *) us->extra;
if (srb->cmnd[0] == READ_10 && !data->in_storage) {
ret = rio_karma_send_command(RIO_ENTER_STORAGE, us);
if (ret)
return ret;
data->in_storage = 1;
return usb_stor_Bulk_transport(srb, us);
} else if (srb->cmnd[0] == START_STOP) {
ret = rio_karma_send_command(RIO_LEAVE_STORAGE, us);
if (ret)
return ret;
data->in_storage = 0;
return rio_karma_send_command(RIO_RESET, us);
}
return usb_stor_Bulk_transport(srb, us);
}
static void rio_karma_destructor(void *extra)
{
struct karma_data *data = (struct karma_data *) extra;
kfree(data->recv);
}
static int rio_karma_init(struct us_data *us)
{
int ret = 0;
struct karma_data *data = kzalloc(sizeof(struct karma_data), GFP_NOIO);
if (!data)
goto out;
data->recv = kmalloc(RIO_RECV_LEN, GFP_NOIO);
if (!data->recv) {
kfree(data);
goto out;
}
us->extra = data;
us->extra_destructor = rio_karma_destructor;
ret = rio_karma_send_command(RIO_ENTER_STORAGE, us);
data->in_storage = (ret == 0);
out:
return ret;
}
static int karma_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct us_data *us;
int result;
result = usb_stor_probe1(&us, intf, id,
(id - karma_usb_ids) + karma_unusual_dev_list,
&karma_host_template);
if (result)
return result;
us->transport_name = "Rio Karma/Bulk";
us->transport = rio_karma_transport;
us->transport_reset = usb_stor_Bulk_reset;
result = usb_stor_probe2(us);
return result;
}
