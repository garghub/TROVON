static inline void mts_debug_dump(struct mts_desc* desc) {
MTS_DEBUG("desc at 0x%x: toggle = %02x%02x\n",
(int)desc,
(int)desc->usb_dev->toggle[1],(int)desc->usb_dev->toggle[0]
);
MTS_DEBUG("ep_out=%x ep_response=%x ep_image=%x\n",
usb_sndbulkpipe(desc->usb_dev,desc->ep_out),
usb_rcvbulkpipe(desc->usb_dev,desc->ep_response),
usb_rcvbulkpipe(desc->usb_dev,desc->ep_image)
);
}
static inline void mts_show_command(struct scsi_cmnd *srb)
{
char *what = NULL;
switch (srb->cmnd[0]) {
case TEST_UNIT_READY: what = "TEST_UNIT_READY"; break;
case REZERO_UNIT: what = "REZERO_UNIT"; break;
case REQUEST_SENSE: what = "REQUEST_SENSE"; break;
case FORMAT_UNIT: what = "FORMAT_UNIT"; break;
case READ_BLOCK_LIMITS: what = "READ_BLOCK_LIMITS"; break;
case REASSIGN_BLOCKS: what = "REASSIGN_BLOCKS"; break;
case READ_6: what = "READ_6"; break;
case WRITE_6: what = "WRITE_6"; break;
case SEEK_6: what = "SEEK_6"; break;
case READ_REVERSE: what = "READ_REVERSE"; break;
case WRITE_FILEMARKS: what = "WRITE_FILEMARKS"; break;
case SPACE: what = "SPACE"; break;
case INQUIRY: what = "INQUIRY"; break;
case RECOVER_BUFFERED_DATA: what = "RECOVER_BUFFERED_DATA"; break;
case MODE_SELECT: what = "MODE_SELECT"; break;
case RESERVE: what = "RESERVE"; break;
case RELEASE: what = "RELEASE"; break;
case COPY: what = "COPY"; break;
case ERASE: what = "ERASE"; break;
case MODE_SENSE: what = "MODE_SENSE"; break;
case START_STOP: what = "START_STOP"; break;
case RECEIVE_DIAGNOSTIC: what = "RECEIVE_DIAGNOSTIC"; break;
case SEND_DIAGNOSTIC: what = "SEND_DIAGNOSTIC"; break;
case ALLOW_MEDIUM_REMOVAL: what = "ALLOW_MEDIUM_REMOVAL"; break;
case SET_WINDOW: what = "SET_WINDOW"; break;
case READ_CAPACITY: what = "READ_CAPACITY"; break;
case READ_10: what = "READ_10"; break;
case WRITE_10: what = "WRITE_10"; break;
case SEEK_10: what = "SEEK_10"; break;
case WRITE_VERIFY: what = "WRITE_VERIFY"; break;
case VERIFY: what = "VERIFY"; break;
case SEARCH_HIGH: what = "SEARCH_HIGH"; break;
case SEARCH_EQUAL: what = "SEARCH_EQUAL"; break;
case SEARCH_LOW: what = "SEARCH_LOW"; break;
case SET_LIMITS: what = "SET_LIMITS"; break;
case READ_POSITION: what = "READ_POSITION"; break;
case SYNCHRONIZE_CACHE: what = "SYNCHRONIZE_CACHE"; break;
case LOCK_UNLOCK_CACHE: what = "LOCK_UNLOCK_CACHE"; break;
case READ_DEFECT_DATA: what = "READ_DEFECT_DATA"; break;
case MEDIUM_SCAN: what = "MEDIUM_SCAN"; break;
case COMPARE: what = "COMPARE"; break;
case COPY_VERIFY: what = "COPY_VERIFY"; break;
case WRITE_BUFFER: what = "WRITE_BUFFER"; break;
case READ_BUFFER: what = "READ_BUFFER"; break;
case UPDATE_BLOCK: what = "UPDATE_BLOCK"; break;
case READ_LONG: what = "READ_LONG"; break;
case WRITE_LONG: what = "WRITE_LONG"; break;
case CHANGE_DEFINITION: what = "CHANGE_DEFINITION"; break;
case WRITE_SAME: what = "WRITE_SAME"; break;
case READ_TOC: what = "READ_TOC"; break;
case LOG_SELECT: what = "LOG_SELECT"; break;
case LOG_SENSE: what = "LOG_SENSE"; break;
case MODE_SELECT_10: what = "MODE_SELECT_10"; break;
case MODE_SENSE_10: what = "MODE_SENSE_10"; break;
case MOVE_MEDIUM: what = "MOVE_MEDIUM"; break;
case READ_12: what = "READ_12"; break;
case WRITE_12: what = "WRITE_12"; break;
case WRITE_VERIFY_12: what = "WRITE_VERIFY_12"; break;
case SEARCH_HIGH_12: what = "SEARCH_HIGH_12"; break;
case SEARCH_EQUAL_12: what = "SEARCH_EQUAL_12"; break;
case SEARCH_LOW_12: what = "SEARCH_LOW_12"; break;
case READ_ELEMENT_STATUS: what = "READ_ELEMENT_STATUS"; break;
case SEND_VOLUME_TAG: what = "SEND_VOLUME_TAG"; break;
case WRITE_LONG_2: what = "WRITE_LONG_2"; break;
default:
MTS_DEBUG("can't decode command\n");
goto out;
break;
}
MTS_DEBUG( "Command %s (%d bytes)\n", what, srb->cmd_len);
out:
MTS_DEBUG( " %10ph\n", srb->cmnd);
}
static inline void mts_show_command(struct scsi_cmnd * dummy)
{
}
static inline void mts_debug_dump(struct mts_desc* dummy)
{
}
static inline void mts_urb_abort(struct mts_desc* desc) {
MTS_DEBUG_GOT_HERE();
mts_debug_dump(desc);
usb_kill_urb( desc->urb );
}
static int mts_slave_alloc (struct scsi_device *s)
{
s->inquiry_len = 0x24;
return 0;
}
static int mts_slave_configure (struct scsi_device *s)
{
blk_queue_dma_alignment(s->request_queue, (512 - 1));
return 0;
}
static int mts_scsi_abort(struct scsi_cmnd *srb)
{
struct mts_desc* desc = (struct mts_desc*)(srb->device->host->hostdata[0]);
MTS_DEBUG_GOT_HERE();
mts_urb_abort(desc);
return FAILED;
}
static int mts_scsi_host_reset(struct scsi_cmnd *srb)
{
struct mts_desc* desc = (struct mts_desc*)(srb->device->host->hostdata[0]);
int result;
MTS_DEBUG_GOT_HERE();
mts_debug_dump(desc);
result = usb_lock_device_for_reset(desc->usb_dev, desc->usb_intf);
if (result == 0) {
result = usb_reset_device(desc->usb_dev);
usb_unlock_device(desc->usb_dev);
}
return result ? FAILED : SUCCESS;
}
static inline
void mts_int_submit_urb (struct urb* transfer,
int pipe,
void* data,
unsigned length,
usb_complete_t callback )
{
int res;
MTS_INT_INIT();
usb_fill_bulk_urb(transfer,
context->instance->usb_dev,
pipe,
data,
length,
callback,
context
);
res = usb_submit_urb( transfer, GFP_ATOMIC );
if ( unlikely(res) ) {
MTS_INT_ERROR( "could not submit URB! Error was %d\n",(int)res );
context->srb->result = DID_ERROR << 16;
mts_transfer_cleanup(transfer);
}
}
static void mts_transfer_cleanup( struct urb *transfer )
{
MTS_INT_INIT();
if ( likely(context->final_callback != NULL) )
context->final_callback(context->srb);
}
static void mts_transfer_done( struct urb *transfer )
{
MTS_INT_INIT();
context->srb->result &= MTS_SCSI_ERR_MASK;
context->srb->result |= (unsigned)(*context->scsi_status)<<1;
mts_transfer_cleanup(transfer);
}
static void mts_get_status( struct urb *transfer )
{
MTS_INT_INIT();
mts_int_submit_urb(transfer,
usb_rcvbulkpipe(context->instance->usb_dev,
context->instance->ep_response),
context->scsi_status,
1,
mts_transfer_done );
}
static void mts_data_done( struct urb* transfer )
{
int status = transfer->status;
MTS_INT_INIT();
if ( context->data_length != transfer->actual_length ) {
scsi_set_resid(context->srb, context->data_length -
transfer->actual_length);
} else if ( unlikely(status) ) {
context->srb->result = (status == -ENOENT ? DID_ABORT : DID_ERROR)<<16;
}
mts_get_status(transfer);
}
static void mts_command_done( struct urb *transfer )
{
int status = transfer->status;
MTS_INT_INIT();
if ( unlikely(status) ) {
if (status == -ENOENT) {
MTS_DEBUG_GOT_HERE();
context->srb->result = DID_ABORT<<16;
} else {
MTS_DEBUG_GOT_HERE();
context->srb->result = DID_ERROR<<16;
}
mts_transfer_cleanup(transfer);
return;
}
if (context->srb->cmnd[0] == REQUEST_SENSE) {
mts_int_submit_urb(transfer,
context->data_pipe,
context->srb->sense_buffer,
context->data_length,
mts_data_done);
} else { if ( context->data ) {
mts_int_submit_urb(transfer,
context->data_pipe,
context->data,
context->data_length,
scsi_sg_count(context->srb) > 1 ?
mts_do_sg : mts_data_done);
} else {
mts_get_status(transfer);
}
}
}
static void mts_do_sg (struct urb* transfer)
{
struct scatterlist * sg;
int status = transfer->status;
MTS_INT_INIT();
MTS_DEBUG("Processing fragment %d of %d\n", context->fragment,
scsi_sg_count(context->srb));
if (unlikely(status)) {
context->srb->result = (status == -ENOENT ? DID_ABORT : DID_ERROR)<<16;
mts_transfer_cleanup(transfer);
}
sg = scsi_sglist(context->srb);
context->fragment++;
mts_int_submit_urb(transfer,
context->data_pipe,
sg_virt(&sg[context->fragment]),
sg[context->fragment].length,
context->fragment + 1 == scsi_sg_count(context->srb) ?
mts_data_done : mts_do_sg);
}
static void
mts_build_transfer_context(struct scsi_cmnd *srb, struct mts_desc* desc)
{
int pipe;
struct scatterlist * sg;
MTS_DEBUG_GOT_HERE();
desc->context.instance = desc;
desc->context.srb = srb;
desc->context.fragment = 0;
if (!scsi_bufflen(srb)) {
desc->context.data = NULL;
desc->context.data_length = 0;
return;
} else {
sg = scsi_sglist(srb);
desc->context.data = sg_virt(&sg[0]);
desc->context.data_length = sg[0].length;
}
if ( !memcmp( srb->cmnd, mts_read_image_sig, mts_read_image_sig_len )
) { pipe = usb_rcvbulkpipe(desc->usb_dev,desc->ep_image);
MTS_DEBUG( "transferring from desc->ep_image == %d\n",
(int)desc->ep_image );
} else if ( MTS_DIRECTION_IS_IN(srb->cmnd[0]) ) {
pipe = usb_rcvbulkpipe(desc->usb_dev,desc->ep_response);
MTS_DEBUG( "transferring from desc->ep_response == %d\n",
(int)desc->ep_response);
} else {
MTS_DEBUG("transferring to desc->ep_out == %d\n",
(int)desc->ep_out);
pipe = usb_sndbulkpipe(desc->usb_dev,desc->ep_out);
}
desc->context.data_pipe = pipe;
}
static int
mts_scsi_queuecommand_lck(struct scsi_cmnd *srb, mts_scsi_cmnd_callback callback)
{
struct mts_desc* desc = (struct mts_desc*)(srb->device->host->hostdata[0]);
int err = 0;
int res;
MTS_DEBUG_GOT_HERE();
mts_show_command(srb);
mts_debug_dump(desc);
if ( srb->device->lun || srb->device->id || srb->device->channel ) {
MTS_DEBUG("Command to LUN=%d ID=%d CHANNEL=%d from SCSI layer\n",(int)srb->device->lun,(int)srb->device->id, (int)srb->device->channel );
MTS_DEBUG("this device doesn't exist\n");
srb->result = DID_BAD_TARGET << 16;
if(likely(callback != NULL))
callback(srb);
goto out;
}
usb_fill_bulk_urb(desc->urb,
desc->usb_dev,
usb_sndbulkpipe(desc->usb_dev,desc->ep_out),
srb->cmnd,
srb->cmd_len,
mts_command_done,
&desc->context
);
mts_build_transfer_context( srb, desc );
desc->context.final_callback = callback;
res=usb_submit_urb(desc->urb, GFP_ATOMIC);
if(unlikely(res)){
MTS_ERROR("error %d submitting URB\n",(int)res);
srb->result = DID_ERROR << 16;
if(likely(callback != NULL))
callback(srb);
}
out:
return err;
}
static int mts_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int i;
int ep_out = -1;
int ep_in_set[3];
int *ep_in_current = ep_in_set;
int err_retval = -ENOMEM;
struct mts_desc * new_desc;
struct usb_device *dev = interface_to_usbdev (intf);
struct usb_host_interface *altsetting;
MTS_DEBUG_GOT_HERE();
MTS_DEBUG( "usb-device descriptor at %x\n", (int)dev );
MTS_DEBUG( "product id = 0x%x, vendor id = 0x%x\n",
le16_to_cpu(dev->descriptor.idProduct),
le16_to_cpu(dev->descriptor.idVendor) );
MTS_DEBUG_GOT_HERE();
altsetting = intf->cur_altsetting;
if ( altsetting->desc.bNumEndpoints != MTS_EP_TOTAL ) {
MTS_WARNING( "expecting %d got %d endpoints! Bailing out.\n",
(int)MTS_EP_TOTAL, (int)altsetting->desc.bNumEndpoints );
return -ENODEV;
}
for( i = 0; i < altsetting->desc.bNumEndpoints; i++ ) {
if ((altsetting->endpoint[i].desc.bmAttributes &
USB_ENDPOINT_XFERTYPE_MASK) != USB_ENDPOINT_XFER_BULK) {
MTS_WARNING( "can only deal with bulk endpoints; endpoint %d is not bulk.\n",
(int)altsetting->endpoint[i].desc.bEndpointAddress );
} else {
if (altsetting->endpoint[i].desc.bEndpointAddress &
USB_DIR_IN)
*ep_in_current++
= altsetting->endpoint[i].desc.bEndpointAddress &
USB_ENDPOINT_NUMBER_MASK;
else {
if ( ep_out != -1 ) {
MTS_WARNING( "can only deal with one output endpoints. Bailing out." );
return -ENODEV;
}
ep_out = altsetting->endpoint[i].desc.bEndpointAddress &
USB_ENDPOINT_NUMBER_MASK;
}
}
}
if ( ep_out == -1 ) {
MTS_WARNING( "couldn't find an output bulk endpoint. Bailing out.\n" );
return -ENODEV;
}
new_desc = kzalloc(sizeof(struct mts_desc), GFP_KERNEL);
if (!new_desc)
goto out;
new_desc->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!new_desc->urb)
goto out_kfree;
new_desc->context.scsi_status = kmalloc(1, GFP_KERNEL);
if (!new_desc->context.scsi_status)
goto out_free_urb;
new_desc->usb_dev = dev;
new_desc->usb_intf = intf;
new_desc->ep_out = ep_out;
new_desc->ep_response = ep_in_set[0];
new_desc->ep_image = ep_in_set[1];
if ( new_desc->ep_out != MTS_EP_OUT )
MTS_WARNING( "will this work? Command EP is not usually %d\n",
(int)new_desc->ep_out );
if ( new_desc->ep_response != MTS_EP_RESPONSE )
MTS_WARNING( "will this work? Response EP is not usually %d\n",
(int)new_desc->ep_response );
if ( new_desc->ep_image != MTS_EP_IMAGE )
MTS_WARNING( "will this work? Image data EP is not usually %d\n",
(int)new_desc->ep_image );
new_desc->host = scsi_host_alloc(&mts_scsi_host_template,
sizeof(new_desc));
if (!new_desc->host)
goto out_kfree2;
new_desc->host->hostdata[0] = (unsigned long)new_desc;
if (scsi_add_host(new_desc->host, &dev->dev)) {
err_retval = -EIO;
goto out_host_put;
}
scsi_scan_host(new_desc->host);
usb_set_intfdata(intf, new_desc);
return 0;
out_host_put:
scsi_host_put(new_desc->host);
out_kfree2:
kfree(new_desc->context.scsi_status);
out_free_urb:
usb_free_urb(new_desc->urb);
out_kfree:
kfree(new_desc);
out:
return err_retval;
}
static void mts_usb_disconnect (struct usb_interface *intf)
{
struct mts_desc *desc = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
usb_kill_urb(desc->urb);
scsi_remove_host(desc->host);
scsi_host_put(desc->host);
usb_free_urb(desc->urb);
kfree(desc->context.scsi_status);
kfree(desc);
}
