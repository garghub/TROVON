unsigned int ffaddr2pipehdl23a(struct dvobj_priv *pdvobj, u32 addr)
{
struct usb_device *pusbd = pdvobj->pusbdev;
unsigned int pipe = 0, ep_num = 0;
if (addr == RECV_BULK_IN_ADDR) {
pipe = usb_rcvbulkpipe(pusbd, pdvobj->RtInPipe[0]);
} else if (addr == RECV_INT_IN_ADDR) {
pipe = usb_rcvintpipe(pusbd, pdvobj->RtInPipe[1]);
} else if (addr < HW_QUEUE_ENTRY) {
ep_num = pdvobj->Queue2Pipe[addr];
pipe = usb_sndbulkpipe(pusbd, ep_num);
}
return pipe;
}
void usb_read_mem23a(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *rmem)
{
}
void usb_write_mem23a(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *wmem)
{
}
void usb_read_port_cancel23a(struct intf_hdl *pintfhdl)
{
struct recv_buf *precvbuf;
struct rtw_adapter *padapter = pintfhdl->padapter;
int i;
precvbuf = (struct recv_buf *)padapter->recvpriv.precv_buf;
DBG_8723A("%s\n", __func__);
padapter->bReadPortCancel = true;
for (i = 0; i < NR_RECVBUFF ; i++) {
if (precvbuf->purb)
usb_kill_urb(precvbuf->purb);
precvbuf++;
}
usb_kill_urb(padapter->recvpriv.int_in_urb);
}
static void usb_write_port23a_complete(struct urb *purb, struct pt_regs *regs)
{
struct xmit_buf *pxmitbuf = (struct xmit_buf *)purb->context;
struct rtw_adapter *padapter = pxmitbuf->padapter;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
struct hal_data_8723a *phaldata;
unsigned long irqL;
switch (pxmitbuf->flags) {
case VO_QUEUE_INX:
pxmitpriv->voq_cnt--;
break;
case VI_QUEUE_INX:
pxmitpriv->viq_cnt--;
break;
case BE_QUEUE_INX:
pxmitpriv->beq_cnt--;
break;
case BK_QUEUE_INX:
pxmitpriv->bkq_cnt--;
break;
case HIGH_QUEUE_INX:
#ifdef CONFIG_8723AU_AP_MODE
rtw_chk_hi_queue_cmd23a(padapter);
#endif
break;
default:
break;
}
if (padapter->bSurpriseRemoved || padapter->bDriverStopped ||
padapter->bWritePortCancel) {
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a_complete:bDriverStopped(%d) OR bSurpriseRemoved(%d)",
padapter->bDriverStopped, padapter->bSurpriseRemoved));
DBG_8723A("%s(): TX Warning! bDriverStopped(%d) OR bSurpriseRemoved(%d) bWritePortCancel(%d) pxmitbuf->ext_tag(%x)\n",
__func__, padapter->bDriverStopped,
padapter->bSurpriseRemoved, padapter->bReadPortCancel,
pxmitbuf->ext_tag);
goto check_completion;
}
if (purb->status) {
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a_complete : purb->status(%d) != 0\n",
purb->status));
DBG_8723A("###=> urb_write_port_complete status(%d)\n",
purb->status);
if ((purb->status == -EPIPE) || (purb->status == -EPROTO)) {
sreset_set_wifi_error_status23a(padapter,
USB_WRITE_PORT_FAIL);
} else if (purb->status == -EINPROGRESS) {
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a_complete: EINPROGESS\n"));
goto check_completion;
} else if (purb->status == -ENOENT) {
DBG_8723A("%s: -ENOENT\n", __func__);
goto check_completion;
} else if (purb->status == -ECONNRESET) {
DBG_8723A("%s: -ECONNRESET\n", __func__);
goto check_completion;
} else if (purb->status == -ESHUTDOWN) {
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a_complete: ESHUTDOWN\n"));
padapter->bDriverStopped = true;
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a_complete:bDriverStopped = true\n"));
goto check_completion;
} else {
padapter->bSurpriseRemoved = true;
DBG_8723A("bSurpriseRemoved = true\n");
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a_complete:bSurpriseRemoved = true\n"));
goto check_completion;
}
}
phaldata = GET_HAL_DATA(padapter);
phaldata->srestpriv.last_tx_complete_time = jiffies;
check_completion:
spin_lock_irqsave(&pxmitpriv->lock_sctx, irqL);
rtw23a_sctx_done_err(&pxmitbuf->sctx,
purb->status ? RTW_SCTX_DONE_WRITE_PORT_ERR :
RTW_SCTX_DONE_SUCCESS);
spin_unlock_irqrestore(&pxmitpriv->lock_sctx, irqL);
rtw_free_xmitbuf23a(pxmitpriv, pxmitbuf);
tasklet_hi_schedule(&pxmitpriv->xmit_tasklet);
}
u32 usb_write_port23a(struct intf_hdl *pintfhdl, u32 addr, u32 cnt,
struct xmit_buf *pxmitbuf)
{
struct urb *purb = NULL;
struct rtw_adapter *padapter = (struct rtw_adapter *)pintfhdl->padapter;
struct dvobj_priv *pdvobj = adapter_to_dvobj(padapter);
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
struct xmit_frame *pxmitframe = (struct xmit_frame *)pxmitbuf->priv_data;
struct usb_device *pusbd = pdvobj->pusbdev;
unsigned long irqL;
unsigned int pipe;
int status;
u32 ret = _FAIL;
RT_TRACE(_module_hci_ops_os_c_, _drv_err_, ("+usb_write_port23a\n"));
if ((padapter->bDriverStopped) || (padapter->bSurpriseRemoved) ||
(padapter->pwrctrlpriv.pnp_bstop_trx)) {
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a:( padapter->bDriverStopped ||padapter->bSurpriseRemoved ||adapter->pwrctrlpriv.pnp_bstop_trx)!!!\n"));
rtw23a_sctx_done_err(&pxmitbuf->sctx, RTW_SCTX_DONE_TX_DENY);
goto exit;
}
spin_lock_irqsave(&pxmitpriv->lock, irqL);
switch (addr) {
case VO_QUEUE_INX:
pxmitpriv->voq_cnt++;
pxmitbuf->flags = VO_QUEUE_INX;
break;
case VI_QUEUE_INX:
pxmitpriv->viq_cnt++;
pxmitbuf->flags = VI_QUEUE_INX;
break;
case BE_QUEUE_INX:
pxmitpriv->beq_cnt++;
pxmitbuf->flags = BE_QUEUE_INX;
break;
case BK_QUEUE_INX:
pxmitpriv->bkq_cnt++;
pxmitbuf->flags = BK_QUEUE_INX;
break;
case HIGH_QUEUE_INX:
pxmitbuf->flags = HIGH_QUEUE_INX;
break;
default:
pxmitbuf->flags = MGT_QUEUE_INX;
break;
}
spin_unlock_irqrestore(&pxmitpriv->lock, irqL);
purb = pxmitbuf->pxmit_urb[0];
pipe = ffaddr2pipehdl23a(pdvobj, addr);
usb_fill_bulk_urb(purb, pusbd, pipe,
pxmitframe->buf_addr,
cnt, usb_write_port23a_complete,
pxmitbuf);
status = usb_submit_urb(purb, GFP_ATOMIC);
if (!status) {
struct hal_data_8723a *phaldata = GET_HAL_DATA(padapter);
phaldata->srestpriv.last_tx_time = jiffies;
} else {
rtw23a_sctx_done_err(&pxmitbuf->sctx,
RTW_SCTX_DONE_WRITE_PORT_ERR);
DBG_8723A("usb_write_port23a, status =%d\n", status);
RT_TRACE(_module_hci_ops_os_c_, _drv_err_,
("usb_write_port23a(): usb_submit_urb, status =%x\n",
status));
switch (status) {
case -ENODEV:
padapter->bDriverStopped = true;
break;
default:
break;
}
goto exit;
}
ret = _SUCCESS;
RT_TRACE(_module_hci_ops_os_c_, _drv_err_, ("-usb_write_port23a\n"));
exit:
if (ret != _SUCCESS)
rtw_free_xmitbuf23a(pxmitpriv, pxmitbuf);
return ret;
}
void usb_write_port23a_cancel(struct intf_hdl *pintfhdl)
{
struct rtw_adapter *padapter = pintfhdl->padapter;
struct xmit_buf *pxmitbuf;
struct list_head *plist;
int j;
DBG_8723A("%s\n", __func__);
padapter->bWritePortCancel = true;
list_for_each(plist, &padapter->xmitpriv.xmitbuf_list) {
pxmitbuf = container_of(plist, struct xmit_buf, list2);
for (j = 0; j < 8; j++) {
if (pxmitbuf->pxmit_urb[j])
usb_kill_urb(pxmitbuf->pxmit_urb[j]);
}
}
list_for_each(plist, &padapter->xmitpriv.xmitextbuf_list) {
pxmitbuf = container_of(plist, struct xmit_buf, list2);
for (j = 0; j < 8; j++) {
if (pxmitbuf->pxmit_urb[j])
usb_kill_urb(pxmitbuf->pxmit_urb[j]);
}
}
}
