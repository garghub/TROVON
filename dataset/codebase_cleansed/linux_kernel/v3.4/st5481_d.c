static inline void D_L1L2(struct st5481_adapter *adapter, int pr, void *arg)
{
struct hisax_if *ifc = (struct hisax_if *) &adapter->hisax_d_if;
ifc->l1l2(ifc, pr, arg);
}
static void
l1_go_f3(struct FsmInst *fi, int event, void *arg)
{
struct st5481_adapter *adapter = fi->userdata;
if (fi->state == ST_L1_F7)
ph_disconnect(adapter);
FsmChangeState(fi, ST_L1_F3);
D_L1L2(adapter, PH_DEACTIVATE | INDICATION, NULL);
}
static void
l1_go_f6(struct FsmInst *fi, int event, void *arg)
{
struct st5481_adapter *adapter = fi->userdata;
if (fi->state == ST_L1_F7)
ph_disconnect(adapter);
FsmChangeState(fi, ST_L1_F6);
}
static void
l1_go_f7(struct FsmInst *fi, int event, void *arg)
{
struct st5481_adapter *adapter = fi->userdata;
FsmDelTimer(&adapter->timer, 0);
ph_connect(adapter);
FsmChangeState(fi, ST_L1_F7);
D_L1L2(adapter, PH_ACTIVATE | INDICATION, NULL);
}
static void
l1_go_f8(struct FsmInst *fi, int event, void *arg)
{
struct st5481_adapter *adapter = fi->userdata;
if (fi->state == ST_L1_F7)
ph_disconnect(adapter);
FsmChangeState(fi, ST_L1_F8);
}
static void
l1_timer3(struct FsmInst *fi, int event, void *arg)
{
struct st5481_adapter *adapter = fi->userdata;
st5481_ph_command(adapter, ST5481_CMD_DR);
FsmChangeState(fi, ST_L1_F3);
D_L1L2(adapter, PH_DEACTIVATE | INDICATION, NULL);
}
static void
l1_ignore(struct FsmInst *fi, int event, void *arg)
{
}
static void
l1_activate(struct FsmInst *fi, int event, void *arg)
{
struct st5481_adapter *adapter = fi->userdata;
st5481_ph_command(adapter, ST5481_CMD_DR);
st5481_ph_command(adapter, ST5481_CMD_PUP);
FsmRestartTimer(&adapter->timer, TIMER3_VALUE, EV_TIMER3, NULL, 2);
st5481_ph_command(adapter, ST5481_CMD_AR8);
FsmChangeState(fi, ST_L1_F4);
}
void fifo_reseted(void *context)
{
struct st5481_adapter *adapter = context;
FsmEvent(&adapter->d_out.fsm, EV_DOUT_RESETED, NULL);
}
static void usb_d_out_complete(struct urb *urb)
{
struct st5481_adapter *adapter = urb->context;
struct st5481_d_out *d_out = &adapter->d_out;
long buf_nr;
DBG(2, "");
buf_nr = get_buf_nr(d_out->urb, urb);
test_and_clear_bit(buf_nr, &d_out->busy);
if (unlikely(urb->status < 0)) {
switch (urb->status) {
case -ENOENT:
case -ESHUTDOWN:
case -ECONNRESET:
DBG(1, "urb killed status %d", urb->status);
break;
default:
WARNING("urb status %d", urb->status);
if (d_out->busy == 0) {
st5481_usb_pipe_reset(adapter, EP_D_OUT | USB_DIR_OUT, fifo_reseted, adapter);
}
break;
}
return;
}
FsmEvent(&adapter->d_out.fsm, EV_DOUT_COMPLETE, (void *) buf_nr);
}
static void dout_start_xmit(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
struct urb *urb;
int len, bytes_sent;
struct sk_buff *skb;
int buf_nr = 0;
skb = d_out->tx_skb;
DBG(2, "len=%d", skb->len);
isdnhdlc_out_init(&d_out->hdlc_state, HDLC_DCHANNEL | HDLC_BITREVERSE);
if (test_and_set_bit(buf_nr, &d_out->busy)) {
WARNING("ep %d urb %d busy %#lx", EP_D_OUT, buf_nr, d_out->busy);
return;
}
urb = d_out->urb[buf_nr];
DBG_SKB(0x10, skb);
len = isdnhdlc_encode(&d_out->hdlc_state,
skb->data, skb->len, &bytes_sent,
urb->transfer_buffer, 16);
skb_pull(skb, bytes_sent);
if (len < 16)
FsmChangeState(&d_out->fsm, ST_DOUT_SHORT_INIT);
else
FsmChangeState(&d_out->fsm, ST_DOUT_LONG_INIT);
if (skb->len == 0) {
d_out->tx_skb = NULL;
D_L1L2(adapter, PH_DATA | CONFIRM, NULL);
dev_kfree_skb_any(skb);
}
urb->transfer_buffer_length = len;
urb->iso_frame_desc[0].offset = 0;
urb->iso_frame_desc[0].length = len;
urb->number_of_packets = 1;
urb->dev = adapter->usb_dev;
urb->transfer_flags = URB_ISO_ASAP;
DBG_ISO_PACKET(0x20, urb);
SUBMIT_URB(urb, GFP_KERNEL);
}
static void dout_short_fifo(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
FsmChangeState(&d_out->fsm, ST_DOUT_SHORT_WAIT_DEN);
st5481_usb_device_ctrl_msg(adapter, OUT_D_COUNTER, 16, NULL, NULL);
}
static void dout_end_short_frame(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
FsmChangeState(&d_out->fsm, ST_DOUT_WAIT_FOR_UNDERRUN);
}
static void dout_long_enable_fifo(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
st5481_usb_device_ctrl_msg(adapter, OUT_D_COUNTER, 16, NULL, NULL);
FsmChangeState(&d_out->fsm, ST_DOUT_LONG_WAIT_DEN);
}
static void dout_long_den(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
FsmChangeState(&d_out->fsm, ST_DOUT_NORMAL);
usb_d_out(adapter, 0);
usb_d_out(adapter, 1);
}
static void dout_reset(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
FsmChangeState(&d_out->fsm, ST_DOUT_WAIT_FOR_RESET);
st5481_usb_pipe_reset(adapter, EP_D_OUT | USB_DIR_OUT, fifo_reseted, adapter);
}
static void dout_stop(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
FsmChangeState(&d_out->fsm, ST_DOUT_WAIT_FOR_STOP);
st5481_usb_device_ctrl_msg(adapter, OUT_D_COUNTER, 0, dout_stop_event, adapter);
}
static void dout_underrun(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
if (test_bit(0, &d_out->busy) || test_bit(1, &d_out->busy)) {
FsmChangeState(&d_out->fsm, ST_DOUT_WAIT_FOR_NOT_BUSY);
} else {
dout_stop(fsm, event, arg);
}
}
static void dout_check_busy(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
if (!test_bit(0, &d_out->busy) && !test_bit(1, &d_out->busy))
dout_stop(fsm, event, arg);
}
static void dout_reseted(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
struct st5481_d_out *d_out = &adapter->d_out;
FsmChangeState(&d_out->fsm, ST_DOUT_NONE);
if (d_out->tx_skb)
FsmEvent(&d_out->fsm, EV_DOUT_START_XMIT, NULL);
}
static void dout_complete(struct FsmInst *fsm, int event, void *arg)
{
struct st5481_adapter *adapter = fsm->userdata;
long buf_nr = (long) arg;
usb_d_out(adapter, buf_nr);
}
static void dout_ignore(struct FsmInst *fsm, int event, void *arg)
{
}
void st5481_d_l2l1(struct hisax_if *hisax_d_if, int pr, void *arg)
{
struct st5481_adapter *adapter = hisax_d_if->priv;
struct sk_buff *skb = arg;
switch (pr) {
case PH_ACTIVATE | REQUEST:
FsmEvent(&adapter->l1m, EV_PH_ACTIVATE_REQ, NULL);
break;
case PH_DEACTIVATE | REQUEST:
FsmEvent(&adapter->l1m, EV_PH_DEACTIVATE_REQ, NULL);
break;
case PH_DATA | REQUEST:
DBG(2, "PH_DATA REQUEST len %d", skb->len);
BUG_ON(adapter->d_out.tx_skb);
adapter->d_out.tx_skb = skb;
FsmEvent(&adapter->d_out.fsm, EV_DOUT_START_XMIT, NULL);
break;
default:
WARNING("pr %#x\n", pr);
break;
}
}
static void ph_connect(struct st5481_adapter *adapter)
{
struct st5481_d_out *d_out = &adapter->d_out;
struct st5481_in *d_in = &adapter->d_in;
DBG(8, "");
FsmChangeState(&d_out->fsm, ST_DOUT_NONE);
st5481_usb_device_ctrl_msg(adapter, FFMSK_D, 0xfc, NULL, NULL);
st5481_in_mode(d_in, L1_MODE_HDLC);
#ifdef LOOPBACK
st5481_usb_device_ctrl_msg(cs, LBB, 0x04, NULL, NULL);
#endif
st5481_usb_pipe_reset(adapter, EP_D_OUT | USB_DIR_OUT, NULL, NULL);
adapter->leds |= GREEN_LED;
st5481_usb_device_ctrl_msg(adapter, GPIO_OUT, adapter->leds, NULL, NULL);
}
static void ph_disconnect(struct st5481_adapter *adapter)
{
DBG(8, "");
st5481_in_mode(&adapter->d_in, L1_MODE_NULL);
adapter->leds &= ~GREEN_LED;
st5481_usb_device_ctrl_msg(adapter, GPIO_OUT, adapter->leds, NULL, NULL);
}
static int st5481_setup_d_out(struct st5481_adapter *adapter)
{
struct usb_device *dev = adapter->usb_dev;
struct usb_interface *intf;
struct usb_host_interface *altsetting = NULL;
struct usb_host_endpoint *endpoint;
struct st5481_d_out *d_out = &adapter->d_out;
DBG(2, "");
intf = usb_ifnum_to_if(dev, 0);
if (intf)
altsetting = usb_altnum_to_altsetting(intf, 3);
if (!altsetting)
return -ENXIO;
endpoint = &altsetting->endpoint[EP_D_OUT-1];
DBG(2, "endpoint address=%02x,packet size=%d",
endpoint->desc.bEndpointAddress, le16_to_cpu(endpoint->desc.wMaxPacketSize));
return st5481_setup_isocpipes(d_out->urb, dev,
usb_sndisocpipe(dev, endpoint->desc.bEndpointAddress),
NUM_ISO_PACKETS_D, SIZE_ISO_PACKETS_D_OUT,
NUM_ISO_PACKETS_D * SIZE_ISO_PACKETS_D_OUT,
usb_d_out_complete, adapter);
}
static void st5481_release_d_out(struct st5481_adapter *adapter)
{
struct st5481_d_out *d_out = &adapter->d_out;
DBG(2, "");
st5481_release_isocpipes(d_out->urb);
}
int st5481_setup_d(struct st5481_adapter *adapter)
{
int retval;
DBG(2, "");
retval = st5481_setup_d_out(adapter);
if (retval)
goto err;
adapter->d_in.bufsize = MAX_DFRAME_LEN_L1;
adapter->d_in.num_packets = NUM_ISO_PACKETS_D;
adapter->d_in.packet_size = SIZE_ISO_PACKETS_D_IN;
adapter->d_in.ep = EP_D_IN | USB_DIR_IN;
adapter->d_in.counter = IN_D_COUNTER;
adapter->d_in.adapter = adapter;
adapter->d_in.hisax_if = &adapter->hisax_d_if.ifc;
retval = st5481_setup_in(&adapter->d_in);
if (retval)
goto err_d_out;
adapter->l1m.fsm = &l1fsm;
adapter->l1m.state = ST_L1_F3;
adapter->l1m.debug = st5481_debug & 0x100;
adapter->l1m.userdata = adapter;
adapter->l1m.printdebug = l1m_debug;
FsmInitTimer(&adapter->l1m, &adapter->timer);
adapter->d_out.fsm.fsm = &dout_fsm;
adapter->d_out.fsm.state = ST_DOUT_NONE;
adapter->d_out.fsm.debug = st5481_debug & 0x100;
adapter->d_out.fsm.userdata = adapter;
adapter->d_out.fsm.printdebug = dout_debug;
return 0;
err_d_out:
st5481_release_d_out(adapter);
err:
return retval;
}
void st5481_release_d(struct st5481_adapter *adapter)
{
DBG(2, "");
st5481_release_in(&adapter->d_in);
st5481_release_d_out(adapter);
}
int __init st5481_d_init(void)
{
int retval;
l1fsm.state_count = L1_STATE_COUNT;
l1fsm.event_count = L1_EVENT_COUNT;
l1fsm.strEvent = strL1Event;
l1fsm.strState = strL1State;
retval = FsmNew(&l1fsm, L1FnList, ARRAY_SIZE(L1FnList));
if (retval)
goto err;
dout_fsm.state_count = DOUT_STATE_COUNT;
dout_fsm.event_count = DOUT_EVENT_COUNT;
dout_fsm.strEvent = strDoutEvent;
dout_fsm.strState = strDoutState;
retval = FsmNew(&dout_fsm, DoutFnList, ARRAY_SIZE(DoutFnList));
if (retval)
goto err_l1;
return 0;
err_l1:
FsmFree(&l1fsm);
err:
return retval;
}
void st5481_d_exit(void)
{
FsmFree(&l1fsm);
FsmFree(&dout_fsm);
}
