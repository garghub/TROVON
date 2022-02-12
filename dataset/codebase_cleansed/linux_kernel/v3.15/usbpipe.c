int PIPEnsControlOutAsyn(struct vnt_private *pDevice, u8 byRequest,
u16 wValue, u16 wIndex, u16 wLength, u8 *pbyBuffer)
{
int ntStatus;
if (pDevice->Flags & fMP_DISCONNECTED)
return STATUS_FAILURE;
if (pDevice->Flags & fMP_CONTROL_WRITES)
return STATUS_FAILURE;
if (in_interrupt()) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"in_interrupt return ..byRequest %x\n", byRequest);
return STATUS_FAILURE;
}
ntStatus = usb_control_msg(
pDevice->usb,
usb_sndctrlpipe(pDevice->usb , 0),
byRequest,
0x40,
wValue,
wIndex,
(void *) pbyBuffer,
wLength,
HZ
);
if (ntStatus >= 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"usb_sndctrlpipe ntStatus= %d\n", ntStatus);
ntStatus = 0;
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"usb_sndctrlpipe fail, ntStatus= %d\n", ntStatus);
}
return ntStatus;
}
int PIPEnsControlOut(struct vnt_private *pDevice, u8 byRequest, u16 wValue,
u16 wIndex, u16 wLength, u8 *pbyBuffer)
__releases(&pDevice->lock
int PIPEnsControlIn(struct vnt_private *pDevice, u8 byRequest, u16 wValue,
u16 wIndex, u16 wLength, u8 *pbyBuffer)
__releases(&pDevice->lock
static void s_nsControlInUsbIoCompleteWrite(struct urb *urb)
{
struct vnt_private *pDevice = (struct vnt_private *)urb->context;
pDevice = urb->context;
switch (urb->status) {
case 0:
break;
case -EINPROGRESS:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ctrl write urb status EINPROGRESS%d\n", urb->status);
break;
case -ENOENT:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ctrl write urb status ENOENT %d\n", urb->status);
break;
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ctrl write urb status %d\n", urb->status);
}
MP_CLEAR_FLAG(pDevice, fMP_CONTROL_WRITES);
}
static void s_nsControlInUsbIoCompleteRead(struct urb *urb)
{
struct vnt_private *pDevice = (struct vnt_private *)urb->context;
switch (urb->status) {
case 0:
break;
case -EINPROGRESS:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ctrl read urb status EINPROGRESS%d\n", urb->status);
break;
case -ENOENT:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ctrl read urb status = ENOENT %d\n", urb->status);
break;
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ctrl read urb status %d\n", urb->status);
}
MP_CLEAR_FLAG(pDevice, fMP_CONTROL_READS);
}
int PIPEnsInterruptRead(struct vnt_private *priv)
{
int status = STATUS_FAILURE;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"---->s_nsStartInterruptUsbRead()\n");
if (priv->int_buf.in_use == true)
return STATUS_FAILURE;
priv->int_buf.in_use = true;
usb_fill_int_urb(priv->pInterruptURB,
priv->usb,
usb_rcvintpipe(priv->usb, 1),
priv->int_buf.data_buf,
MAX_INTERRUPT_SIZE,
s_nsInterruptUsbIoCompleteRead,
priv,
priv->int_interval);
status = usb_submit_urb(priv->pInterruptURB, GFP_ATOMIC);
if (status) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"Submit int URB failed %d\n", status);
priv->int_buf.in_use = false;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"<----s_nsStartInterruptUsbRead Return(%x)\n", status);
return status;
}
static void s_nsInterruptUsbIoCompleteRead(struct urb *urb)
{
struct vnt_private *priv = urb->context;
int status;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"---->s_nsInterruptUsbIoCompleteRead\n");
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
priv->int_buf.in_use = false;
return;
default:
break;
}
status = urb->status;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"s_nsInterruptUsbIoCompleteRead Status %d\n", status);
if (status != STATUS_SUCCESS) {
priv->int_buf.in_use = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"IntUSBIoCompleteControl STATUS = %d\n", status);
} else {
INTnsProcessData(priv);
}
status = usb_submit_urb(priv->pInterruptURB, GFP_ATOMIC);
if (status) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"Submit int URB failed %d\n", status);
} else {
priv->int_buf.in_use = true;
}
return;
}
int PIPEnsBulkInUsbRead(struct vnt_private *priv, struct vnt_rcb *rcb)
{
int status = 0;
struct urb *urb;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"---->s_nsStartBulkInUsbRead\n");
if (priv->Flags & fMP_DISCONNECTED)
return STATUS_FAILURE;
urb = rcb->pUrb;
if (rcb->skb == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"rcb->skb is null\n");
return status;
}
usb_fill_bulk_urb(urb,
priv->usb,
usb_rcvbulkpipe(priv->usb, 2),
(void *) (rcb->skb->data),
MAX_TOTAL_SIZE_WITH_ALL_HEADERS,
s_nsBulkInUsbIoCompleteRead,
rcb);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status != 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"Submit Rx URB failed %d\n", status);
return STATUS_FAILURE ;
}
rcb->Ref = 1;
rcb->bBoolInUse = true;
return status;
}
static void s_nsBulkInUsbIoCompleteRead(struct urb *urb)
{
struct vnt_rcb *rcb = urb->context;
struct vnt_private *priv = rcb->pDevice;
int re_alloc_skb = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"---->s_nsBulkInUsbIoCompleteRead\n");
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
case -ETIMEDOUT:
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"BULK In failed %d\n", urb->status);
break;
}
if (urb->actual_length) {
spin_lock(&priv->lock);
if (RXbBulkInProcessData(priv, rcb, urb->actual_length) == true)
re_alloc_skb = true;
spin_unlock(&priv->lock);
}
rcb->Ref--;
if (rcb->Ref == 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"RxvFreeNormal %d\n",
priv->NumRecvFreeList);
spin_lock(&priv->lock);
RXvFreeRCB(rcb, re_alloc_skb);
spin_unlock(&priv->lock);
}
return;
}
int PIPEnsSendBulkOut(struct vnt_private *priv,
struct vnt_usb_send_context *context)
{
int status;
struct urb *urb;
priv->bPWBitOn = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"s_nsSendBulkOut\n");
if (!(MP_IS_READY(priv) && priv->Flags & fMP_POST_WRITES)) {
context->bBoolInUse = false;
return STATUS_RESOURCES;
}
urb = context->pUrb;
usb_fill_bulk_urb(urb,
priv->usb,
usb_sndbulkpipe(priv->usb, 3),
context->Data,
context->uBufLen,
s_nsBulkOutIoCompleteWrite,
context);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status != 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"Submit Tx URB failed %d\n", status);
context->bBoolInUse = false;
return STATUS_FAILURE;
}
return STATUS_PENDING;
}
static void s_nsBulkOutIoCompleteWrite(struct urb *urb)
{
struct vnt_usb_send_context *context = urb->context;
struct vnt_private *priv = context->pDevice;
u8 context_type = context->type;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"---->s_nsBulkOutIoCompleteWrite\n");
switch (urb->status) {
case 0:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"Write %d bytes\n", context->uBufLen);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
context->bBoolInUse = false;
return;
case -ETIMEDOUT:
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"BULK Out failed %d\n", urb->status);
break;
}
if (!netif_device_present(priv->dev))
return;
if (CONTEXT_DATA_PACKET == context_type) {
if (context->pPacket != NULL) {
dev_kfree_skb_irq(context->pPacket);
context->pPacket = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"tx %d bytes\n", context->uBufLen);
}
priv->dev->trans_start = jiffies;
}
if (priv->bLinkPass == true) {
if (netif_queue_stopped(priv->dev))
netif_wake_queue(priv->dev);
}
context->bBoolInUse = false;
return;
}
