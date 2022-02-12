static int adapter_err_occurred(const struct bcm_interface_adapter *ad)
{
if (ad->psAdapter->device_removed == TRUE) {
BCM_DEBUG_PRINT(ad->psAdapter, DBG_TYPE_PRINTK, 0, 0,
"Device got removed");
return -ENODEV;
}
if ((ad->psAdapter->StopAllXaction == TRUE) &&
(ad->psAdapter->chip_id >= T3LPB)) {
BCM_DEBUG_PRINT(ad->psAdapter, DBG_TYPE_OTHERS, RDM,
DBG_LVL_ALL,
"Currently Xaction is not allowed on the bus");
return -EACCES;
}
if (ad->bSuspended == TRUE || ad->bPreparingForBusSuspend == TRUE) {
BCM_DEBUG_PRINT(ad->psAdapter, DBG_TYPE_OTHERS, RDM,
DBG_LVL_ALL,
"Bus is in suspended states hence RDM not allowed..");
return -EACCES;
}
return 0;
}
int InterfaceRDM(struct bcm_interface_adapter *psIntfAdapter,
unsigned int addr,
void *buff,
int len)
{
int bytes;
int err = 0;
if (!psIntfAdapter)
return -EINVAL;
err = adapter_err_occurred(psIntfAdapter);
if (err)
return err;
psIntfAdapter->psAdapter->DeviceAccess = TRUE;
bytes = usb_control_msg(psIntfAdapter->udev,
usb_rcvctrlpipe(psIntfAdapter->udev, 0),
0x02,
0xC2,
(addr & 0xFFFF),
((addr >> 16) & 0xFFFF),
buff,
len,
5000);
if (-ENODEV == bytes)
psIntfAdapter->psAdapter->device_removed = TRUE;
if (bytes < 0)
BCM_DEBUG_PRINT(psIntfAdapter->psAdapter, DBG_TYPE_OTHERS, RDM,
DBG_LVL_ALL, "RDM failed status :%d", bytes);
else
BCM_DEBUG_PRINT(psIntfAdapter->psAdapter, DBG_TYPE_OTHERS, RDM,
DBG_LVL_ALL, "RDM sent %d", bytes);
psIntfAdapter->psAdapter->DeviceAccess = false;
return bytes;
}
int InterfaceWRM(struct bcm_interface_adapter *psIntfAdapter,
unsigned int addr,
void *buff,
int len)
{
int retval = 0;
int err = 0;
if (!psIntfAdapter)
return -EINVAL;
err = adapter_err_occurred(psIntfAdapter);
if (err)
return err;
psIntfAdapter->psAdapter->DeviceAccess = TRUE;
retval = usb_control_msg(psIntfAdapter->udev,
usb_sndctrlpipe(psIntfAdapter->udev, 0),
0x01,
0x42,
(addr & 0xFFFF),
((addr >> 16) & 0xFFFF),
buff,
len,
5000);
if (-ENODEV == retval)
psIntfAdapter->psAdapter->device_removed = TRUE;
if (retval < 0) {
BCM_DEBUG_PRINT(psIntfAdapter->psAdapter, DBG_TYPE_OTHERS, WRM,
DBG_LVL_ALL, "WRM failed status :%d", retval);
psIntfAdapter->psAdapter->DeviceAccess = false;
return retval;
} else {
psIntfAdapter->psAdapter->DeviceAccess = false;
BCM_DEBUG_PRINT(psIntfAdapter->psAdapter, DBG_TYPE_OTHERS, WRM,
DBG_LVL_ALL, "WRM sent %d", retval);
return STATUS_SUCCESS;
}
}
int BcmRDM(void *arg,
unsigned int addr,
void *buff,
int len)
{
return InterfaceRDM((struct bcm_interface_adapter *)arg, addr, buff,
len);
}
int BcmWRM(void *arg,
unsigned int addr,
void *buff,
int len)
{
return InterfaceWRM((struct bcm_interface_adapter *)arg, addr, buff,
len);
}
int Bcm_clear_halt_of_endpoints(struct bcm_mini_adapter *Adapter)
{
struct bcm_interface_adapter *psIntfAdapter =
(struct bcm_interface_adapter *)(Adapter->pvInterfaceAdapter);
int status = STATUS_SUCCESS;
Bcm_kill_all_URBs(psIntfAdapter);
status = usb_clear_halt(psIntfAdapter->udev,
psIntfAdapter->sIntrIn.int_in_pipe);
if (status != STATUS_SUCCESS)
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, INTF_INIT,
DBG_LVL_ALL,
"Unable to Clear Halt of Interrupt IN end point. :%d ",
status);
status = usb_clear_halt(psIntfAdapter->udev,
psIntfAdapter->sBulkIn.bulk_in_pipe);
if (status != STATUS_SUCCESS)
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, INTF_INIT,
DBG_LVL_ALL,
"Unable to Clear Halt of Bulk IN end point. :%d ",
status);
status = usb_clear_halt(psIntfAdapter->udev,
psIntfAdapter->sBulkOut.bulk_out_pipe);
if (status != STATUS_SUCCESS)
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, INTF_INIT,
DBG_LVL_ALL,
"Unable to Clear Halt of Bulk OUT end point. :%d ",
status);
return status;
}
void Bcm_kill_all_URBs(struct bcm_interface_adapter *psIntfAdapter)
{
struct urb *tempUrb = NULL;
unsigned int i;
if (psIntfAdapter->psInterruptUrb) {
if (psIntfAdapter->psInterruptUrb->status == -EINPROGRESS)
usb_kill_urb(psIntfAdapter->psInterruptUrb);
}
for (i = 0; i < MAXIMUM_USB_TCB; i++) {
tempUrb = psIntfAdapter->asUsbTcb[i].urb;
if (tempUrb) {
if (tempUrb->status == -EINPROGRESS)
usb_kill_urb(tempUrb);
}
}
for (i = 0; i < MAXIMUM_USB_RCB; i++) {
tempUrb = psIntfAdapter->asUsbRcb[i].urb;
if (tempUrb) {
if (tempUrb->status == -EINPROGRESS)
usb_kill_urb(tempUrb);
}
}
atomic_set(&psIntfAdapter->uNumTcbUsed, 0);
atomic_set(&psIntfAdapter->uCurrTcb, 0);
atomic_set(&psIntfAdapter->uNumRcbUsed, 0);
atomic_set(&psIntfAdapter->uCurrRcb, 0);
}
void putUsbSuspend(struct work_struct *work)
{
struct bcm_interface_adapter *psIntfAdapter = NULL;
struct usb_interface *intf = NULL;
psIntfAdapter = container_of(work, struct bcm_interface_adapter,
usbSuspendWork);
intf = psIntfAdapter->interface;
if (psIntfAdapter->bSuspended == false)
usb_autopm_put_interface(intf);
}
