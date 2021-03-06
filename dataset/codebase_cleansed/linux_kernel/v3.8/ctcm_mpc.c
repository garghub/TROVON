void ctcmpc_dumpit(char *buf, int len)
{
__u32 ct, sw, rm, dup;
char *ptr, *rptr;
char tbuf[82], tdup[82];
#ifdef CONFIG_64BIT
char addr[22];
#else
char addr[12];
#endif
char boff[12];
char bhex[82], duphex[82];
char basc[40];
sw = 0;
rptr = ptr = buf;
rm = 16;
duphex[0] = 0x00;
dup = 0;
for (ct = 0; ct < len; ct++, ptr++, rptr++) {
if (sw == 0) {
#ifdef CONFIG_64BIT
sprintf(addr, "%16.16llx", (__u64)rptr);
#else
sprintf(addr, "%8.8X", (__u32)rptr);
#endif
sprintf(boff, "%4.4X", (__u32)ct);
bhex[0] = '\0';
basc[0] = '\0';
}
if ((sw == 4) || (sw == 12))
strcat(bhex, " ");
if (sw == 8)
strcat(bhex, " ");
#if CONFIG_64BIT
sprintf(tbuf, "%2.2llX", (__u64)*ptr);
#else
sprintf(tbuf, "%2.2X", (__u32)*ptr);
#endif
tbuf[2] = '\0';
strcat(bhex, tbuf);
if ((0 != isprint(*ptr)) && (*ptr >= 0x20))
basc[sw] = *ptr;
else
basc[sw] = '.';
basc[sw+1] = '\0';
sw++;
rm--;
if (sw != 16)
continue;
if ((strcmp(duphex, bhex)) != 0) {
if (dup != 0) {
sprintf(tdup,
"Duplicate as above to %s", addr);
ctcm_pr_debug(" --- %s ---\n",
tdup);
}
ctcm_pr_debug(" %s (+%s) : %s [%s]\n",
addr, boff, bhex, basc);
dup = 0;
strcpy(duphex, bhex);
} else
dup++;
sw = 0;
rm = 16;
}
if (sw != 0) {
for ( ; rm > 0; rm--, sw++) {
if ((sw == 4) || (sw == 12))
strcat(bhex, " ");
if (sw == 8)
strcat(bhex, " ");
strcat(bhex, " ");
strcat(basc, " ");
}
if (dup != 0) {
sprintf(tdup, "Duplicate as above to %s", addr);
ctcm_pr_debug(" --- %s ---\n", tdup);
}
ctcm_pr_debug(" %s (+%s) : %s [%s]\n",
addr, boff, bhex, basc);
} else {
if (dup >= 1) {
sprintf(tdup, "Duplicate as above to %s", addr);
ctcm_pr_debug(" --- %s ---\n", tdup);
}
if (dup != 0) {
ctcm_pr_debug(" %s (+%s) : %s [%s]\n",
addr, boff, bhex, basc);
}
}
return;
}
void ctcmpc_dump_skb(struct sk_buff *skb, int offset)
{
__u8 *p = skb->data;
struct th_header *header;
struct pdu *pheader;
int bl = skb->len;
int i;
if (p == NULL)
return;
p += offset;
header = (struct th_header *)p;
ctcm_pr_debug("dump:\n");
ctcm_pr_debug("skb len=%d \n", skb->len);
if (skb->len > 2) {
switch (header->th_ch_flag) {
case TH_HAS_PDU:
break;
case 0x00:
case TH_IS_XID:
if ((header->th_blk_flag == TH_DATA_IS_XID) &&
(header->th_is_xid == 0x01))
goto dumpth;
case TH_SWEEP_REQ:
goto dumpth;
case TH_SWEEP_RESP:
goto dumpth;
default:
break;
}
pheader = (struct pdu *)p;
ctcm_pr_debug("pdu->offset: %d hex: %04x\n",
pheader->pdu_offset, pheader->pdu_offset);
ctcm_pr_debug("pdu->flag : %02x\n", pheader->pdu_flag);
ctcm_pr_debug("pdu->proto : %02x\n", pheader->pdu_proto);
ctcm_pr_debug("pdu->seq : %02x\n", pheader->pdu_seq);
goto dumpdata;
dumpth:
ctcm_pr_debug("th->seg : %02x\n", header->th_seg);
ctcm_pr_debug("th->ch : %02x\n", header->th_ch_flag);
ctcm_pr_debug("th->blk_flag: %02x\n", header->th_blk_flag);
ctcm_pr_debug("th->type : %s\n",
(header->th_is_xid) ? "DATA" : "XID");
ctcm_pr_debug("th->seqnum : %04x\n", header->th_seq_num);
}
dumpdata:
if (bl > 32)
bl = 32;
ctcm_pr_debug("data: ");
for (i = 0; i < bl; i++)
ctcm_pr_debug("%02x%s", *p++, (i % 16) ? " " : "\n");
ctcm_pr_debug("\n");
}
static struct net_device *ctcmpc_get_dev(int port_num)
{
char device[20];
struct net_device *dev;
struct ctcm_priv *priv;
sprintf(device, "%s%i", MPC_DEVICE_NAME, port_num);
dev = __dev_get_by_name(&init_net, device);
if (dev == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s: Device not found by name: %s",
CTCM_FUNTAIL, device);
return NULL;
}
priv = dev->ml_priv;
if (priv == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): dev->ml_priv is NULL",
CTCM_FUNTAIL, device);
return NULL;
}
if (priv->mpcg == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): priv->mpcg is NULL",
CTCM_FUNTAIL, device);
return NULL;
}
return dev;
}
int ctc_mpc_alloc_channel(int port_num, void (*callback)(int, int))
{
struct net_device *dev;
struct mpc_group *grp;
struct ctcm_priv *priv;
dev = ctcmpc_get_dev(port_num);
if (dev == NULL)
return 1;
priv = dev->ml_priv;
grp = priv->mpcg;
grp->allochanfunc = callback;
grp->port_num = port_num;
grp->port_persist = 1;
CTCM_DBF_TEXT_(MPC_SETUP, CTC_DBF_INFO,
"%s(%s): state=%s",
CTCM_FUNTAIL, dev->name, fsm_getstate_str(grp->fsm));
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_INOP:
grp->alloc_called = 1;
break;
case MPCG_STATE_RESET:
if (callback)
grp->send_qllc_disc = 1;
case MPCG_STATE_XID0IOWAIT:
fsm_deltimer(&grp->timer);
grp->outstanding_xid2 = 0;
grp->outstanding_xid7 = 0;
grp->outstanding_xid7_p2 = 0;
grp->saved_xid2 = NULL;
if (callback)
ctcm_open(dev);
fsm_event(priv->fsm, DEV_EVENT_START, dev);
break;
case MPCG_STATE_READY:
grp->allocchan_callback_retries++;
if (grp->allocchan_callback_retries < 4) {
if (grp->allochanfunc)
grp->allochanfunc(grp->port_num,
grp->group_max_buflen);
} else {
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
grp->allocchan_callback_retries = 0;
}
break;
}
return 0;
}
void ctc_mpc_establish_connectivity(int port_num,
void (*callback)(int, int, int))
{
struct net_device *dev;
struct mpc_group *grp;
struct ctcm_priv *priv;
struct channel *rch, *wch;
dev = ctcmpc_get_dev(port_num);
if (dev == NULL)
return;
priv = dev->ml_priv;
grp = priv->mpcg;
rch = priv->channel[CTCM_READ];
wch = priv->channel[CTCM_WRITE];
CTCM_DBF_TEXT_(MPC_SETUP, CTC_DBF_INFO,
"%s(%s): state=%s",
CTCM_FUNTAIL, dev->name, fsm_getstate_str(grp->fsm));
grp->estconnfunc = callback;
grp->port_num = port_num;
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_READY:
fsm_deltimer(&grp->timer);
grp->estconn_callback_retries++;
if (grp->estconn_callback_retries < 4) {
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, 0,
grp->group_max_buflen);
grp->estconnfunc = NULL;
}
} else {
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
grp->estconn_callback_retries = 0;
}
break;
case MPCG_STATE_INOP:
case MPCG_STATE_RESET:
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): REJECTED - inactive channels",
CTCM_FUNTAIL, dev->name);
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, -1, 0);
grp->estconnfunc = NULL;
}
break;
case MPCG_STATE_XID2INITW:
if ((fsm_getstate(rch->fsm) > CH_XID0_PENDING) ||
(fsm_getstate(wch->fsm) > CH_XID0_PENDING)) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): ABORT - PASSIVE XID",
CTCM_FUNTAIL, dev->name);
break;
}
grp->send_qllc_disc = 1;
fsm_newstate(grp->fsm, MPCG_STATE_XID0IOWAIT);
fsm_deltimer(&grp->timer);
fsm_addtimer(&grp->timer, MPC_XID_TIMEOUT_VALUE,
MPCG_EVENT_TIMER, dev);
grp->outstanding_xid7 = 0;
grp->outstanding_xid7_p2 = 0;
grp->saved_xid2 = NULL;
if ((rch->in_mpcgroup) &&
(fsm_getstate(rch->fsm) == CH_XID0_PENDING))
fsm_event(grp->fsm, MPCG_EVENT_XID0DO, rch);
else {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): RX-%s not ready for ACTIVE XID0",
CTCM_FUNTAIL, dev->name, rch->id);
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, -1, 0);
grp->estconnfunc = NULL;
}
fsm_deltimer(&grp->timer);
goto done;
}
if ((wch->in_mpcgroup) &&
(fsm_getstate(wch->fsm) == CH_XID0_PENDING))
fsm_event(grp->fsm, MPCG_EVENT_XID0DO, wch);
else {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): WX-%s not ready for ACTIVE XID0",
CTCM_FUNTAIL, dev->name, wch->id);
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, -1, 0);
grp->estconnfunc = NULL;
}
fsm_deltimer(&grp->timer);
goto done;
}
break;
case MPCG_STATE_XID0IOWAIT:
default:
break;
}
done:
CTCM_PR_DEBUG("Exit %s()\n", __func__);
return;
}
void ctc_mpc_dealloc_ch(int port_num)
{
struct net_device *dev;
struct ctcm_priv *priv;
struct mpc_group *grp;
dev = ctcmpc_get_dev(port_num);
if (dev == NULL)
return;
priv = dev->ml_priv;
grp = priv->mpcg;
CTCM_DBF_TEXT_(MPC_SETUP, CTC_DBF_DEBUG,
"%s: %s: refcount = %d\n",
CTCM_FUNTAIL, dev->name, netdev_refcnt_read(dev));
fsm_deltimer(&priv->restart_timer);
grp->channels_terminating = 0;
fsm_deltimer(&grp->timer);
grp->allochanfunc = NULL;
grp->estconnfunc = NULL;
grp->port_persist = 0;
grp->send_qllc_disc = 0;
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
ctcm_close(dev);
return;
}
void ctc_mpc_flow_control(int port_num, int flowc)
{
struct ctcm_priv *priv;
struct mpc_group *grp;
struct net_device *dev;
struct channel *rch;
int mpcg_state;
dev = ctcmpc_get_dev(port_num);
if (dev == NULL)
return;
priv = dev->ml_priv;
grp = priv->mpcg;
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_DEBUG,
"%s: %s: flowc = %d",
CTCM_FUNTAIL, dev->name, flowc);
rch = priv->channel[CTCM_READ];
mpcg_state = fsm_getstate(grp->fsm);
switch (flowc) {
case 1:
if (mpcg_state == MPCG_STATE_FLOWC)
break;
if (mpcg_state == MPCG_STATE_READY) {
if (grp->flow_off_called == 1)
grp->flow_off_called = 0;
else
fsm_newstate(grp->fsm, MPCG_STATE_FLOWC);
break;
}
break;
case 0:
if (mpcg_state == MPCG_STATE_FLOWC) {
fsm_newstate(grp->fsm, MPCG_STATE_READY);
tasklet_schedule(&rch->ch_tasklet);
}
if (mpcg_state == MPCG_STATE_READY) {
grp->flow_off_called = 1;
break;
}
break;
}
}
static void mpc_rcvd_sweep_resp(struct mpcg_info *mpcginfo)
{
struct channel *rch = mpcginfo->ch;
struct net_device *dev = rch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct channel *ch = priv->channel[CTCM_WRITE];
CTCM_PR_DEBUG("%s: ch=0x%p id=%s\n", __func__, ch, ch->id);
CTCM_D3_DUMP((char *)mpcginfo->sweep, TH_SWEEP_LENGTH);
grp->sweep_rsp_pend_num--;
if ((grp->sweep_req_pend_num == 0) &&
(grp->sweep_rsp_pend_num == 0)) {
fsm_deltimer(&ch->sweep_timer);
grp->in_sweep = 0;
rch->th_seq_num = 0x00;
ch->th_seq_num = 0x00;
ctcm_clear_busy_do(dev);
}
kfree(mpcginfo);
return;
}
static void ctcmpc_send_sweep_resp(struct channel *rch)
{
struct net_device *dev = rch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct th_sweep *header;
struct sk_buff *sweep_skb;
struct channel *ch = priv->channel[CTCM_WRITE];
CTCM_PR_DEBUG("%s: ch=0x%p id=%s\n", __func__, rch, rch->id);
sweep_skb = __dev_alloc_skb(MPC_BUFSIZE_DEFAULT, GFP_ATOMIC | GFP_DMA);
if (sweep_skb == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): sweep_skb allocation ERROR\n",
CTCM_FUNTAIL, rch->id);
goto done;
}
header = kmalloc(sizeof(struct th_sweep), gfp_type());
if (!header) {
dev_kfree_skb_any(sweep_skb);
goto done;
}
header->th.th_seg = 0x00 ;
header->th.th_ch_flag = TH_SWEEP_RESP;
header->th.th_blk_flag = 0x00;
header->th.th_is_xid = 0x00;
header->th.th_seq_num = 0x00;
header->sw.th_last_seq = ch->th_seq_num;
memcpy(skb_put(sweep_skb, TH_SWEEP_LENGTH), header, TH_SWEEP_LENGTH);
kfree(header);
dev->trans_start = jiffies;
skb_queue_tail(&ch->sweep_queue, sweep_skb);
fsm_addtimer(&ch->sweep_timer, 100, CTC_EVENT_RSWEEP_TIMER, ch);
return;
done:
grp->in_sweep = 0;
ctcm_clear_busy_do(dev);
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
return;
}
static void mpc_rcvd_sweep_req(struct mpcg_info *mpcginfo)
{
struct channel *rch = mpcginfo->ch;
struct net_device *dev = rch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct channel *ch = priv->channel[CTCM_WRITE];
if (do_debug)
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_DEBUG,
" %s(): ch=0x%p id=%s\n", __func__, ch, ch->id);
if (grp->in_sweep == 0) {
grp->in_sweep = 1;
ctcm_test_and_set_busy(dev);
grp->sweep_req_pend_num = grp->active_channels[CTCM_READ];
grp->sweep_rsp_pend_num = grp->active_channels[CTCM_READ];
}
CTCM_D3_DUMP((char *)mpcginfo->sweep, TH_SWEEP_LENGTH);
grp->sweep_req_pend_num--;
ctcmpc_send_sweep_resp(ch);
kfree(mpcginfo);
return;
}
static void mpc_action_go_ready(fsm_instance *fsm, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
if (grp == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): No MPC group",
CTCM_FUNTAIL, dev->name);
return;
}
fsm_deltimer(&grp->timer);
if (grp->saved_xid2->xid2_flag2 == 0x40) {
priv->xid->xid2_flag2 = 0x00;
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, 1,
grp->group_max_buflen);
grp->estconnfunc = NULL;
} else if (grp->allochanfunc)
grp->send_qllc_disc = 1;
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): fails",
CTCM_FUNTAIL, dev->name);
return;
}
grp->port_persist = 1;
grp->out_of_sequence = 0;
grp->estconn_called = 0;
tasklet_hi_schedule(&grp->mpc_tasklet2);
return;
}
void mpc_group_ready(unsigned long adev)
{
struct net_device *dev = (struct net_device *)adev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct channel *ch = NULL;
if (grp == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): No MPC group",
CTCM_FUNTAIL, dev->name);
return;
}
CTCM_DBF_TEXT_(MPC_SETUP, CTC_DBF_NOTICE,
"%s: %s: GROUP TRANSITIONED TO READY, maxbuf = %d\n",
CTCM_FUNTAIL, dev->name, grp->group_max_buflen);
fsm_newstate(grp->fsm, MPCG_STATE_READY);
ch = priv->channel[CTCM_READ];
ch->pdu_seq = 0;
CTCM_PR_DBGDATA("ctcmpc: %s() ToDCM_pdu_seq= %08x\n" ,
__func__, ch->pdu_seq);
ctcmpc_chx_rxidle(ch->fsm, CTC_EVENT_START, ch);
ch = priv->channel[CTCM_WRITE];
if (ch->collect_len > 0) {
spin_lock(&ch->collect_lock);
ctcm_purge_skb_queue(&ch->collect_queue);
ch->collect_len = 0;
spin_unlock(&ch->collect_lock);
}
ctcm_chx_txidle(ch->fsm, CTC_EVENT_START, ch);
ctcm_clear_busy(dev);
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, 0,
grp->group_max_buflen);
grp->estconnfunc = NULL;
} else if (grp->allochanfunc)
grp->allochanfunc(grp->port_num, grp->group_max_buflen);
grp->send_qllc_disc = 1;
grp->changed_side = 0;
return;
}
void mpc_channel_action(struct channel *ch, int direction, int action)
{
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
if (grp == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): No MPC group",
CTCM_FUNTAIL, dev->name);
return;
}
CTCM_PR_DEBUG("enter %s: ch=0x%p id=%s\n", __func__, ch, ch->id);
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_NOTICE,
"%s: %i / Grp:%s total_channels=%i, active_channels: "
"read=%i, write=%i\n", __func__, action,
fsm_getstate_str(grp->fsm), grp->num_channel_paths,
grp->active_channels[CTCM_READ],
grp->active_channels[CTCM_WRITE]);
if ((action == MPC_CHANNEL_ADD) && (ch->in_mpcgroup == 0)) {
grp->num_channel_paths++;
grp->active_channels[direction]++;
grp->outstanding_xid2++;
ch->in_mpcgroup = 1;
if (ch->xid_skb != NULL)
dev_kfree_skb_any(ch->xid_skb);
ch->xid_skb = __dev_alloc_skb(MPC_BUFSIZE_DEFAULT,
GFP_ATOMIC | GFP_DMA);
if (ch->xid_skb == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): Couldn't alloc ch xid_skb\n",
CTCM_FUNTAIL, dev->name);
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
return;
}
ch->xid_skb_data = ch->xid_skb->data;
ch->xid_th = (struct th_header *)ch->xid_skb->data;
skb_put(ch->xid_skb, TH_HEADER_LENGTH);
ch->xid = (struct xid2 *)skb_tail_pointer(ch->xid_skb);
skb_put(ch->xid_skb, XID2_LENGTH);
ch->xid_id = skb_tail_pointer(ch->xid_skb);
ch->xid_skb->data = ch->xid_skb_data;
skb_reset_tail_pointer(ch->xid_skb);
ch->xid_skb->len = 0;
memcpy(skb_put(ch->xid_skb, grp->xid_skb->len),
grp->xid_skb->data,
grp->xid_skb->len);
ch->xid->xid2_dlc_type =
((CHANNEL_DIRECTION(ch->flags) == CTCM_READ)
? XID2_READ_SIDE : XID2_WRITE_SIDE);
if (CHANNEL_DIRECTION(ch->flags) == CTCM_WRITE)
ch->xid->xid2_buf_len = 0x00;
ch->xid_skb->data = ch->xid_skb_data;
skb_reset_tail_pointer(ch->xid_skb);
ch->xid_skb->len = 0;
fsm_newstate(ch->fsm, CH_XID0_PENDING);
if ((grp->active_channels[CTCM_READ] > 0) &&
(grp->active_channels[CTCM_WRITE] > 0) &&
(fsm_getstate(grp->fsm) < MPCG_STATE_XID2INITW)) {
fsm_newstate(grp->fsm, MPCG_STATE_XID2INITW);
CTCM_DBF_TEXT_(MPC_SETUP, CTC_DBF_NOTICE,
"%s: %s: MPC GROUP CHANNELS ACTIVE\n",
__func__, dev->name);
}
} else if ((action == MPC_CHANNEL_REMOVE) &&
(ch->in_mpcgroup == 1)) {
ch->in_mpcgroup = 0;
grp->num_channel_paths--;
grp->active_channels[direction]--;
if (ch->xid_skb != NULL)
dev_kfree_skb_any(ch->xid_skb);
ch->xid_skb = NULL;
if (grp->channels_terminating)
goto done;
if (((grp->active_channels[CTCM_READ] == 0) &&
(grp->active_channels[CTCM_WRITE] > 0))
|| ((grp->active_channels[CTCM_WRITE] == 0) &&
(grp->active_channels[CTCM_READ] > 0)))
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
}
done:
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_DEBUG,
"exit %s: %i / Grp:%s total_channels=%i, active_channels: "
"read=%i, write=%i\n", __func__, action,
fsm_getstate_str(grp->fsm), grp->num_channel_paths,
grp->active_channels[CTCM_READ],
grp->active_channels[CTCM_WRITE]);
CTCM_PR_DEBUG("exit %s: ch=0x%p id=%s\n", __func__, ch, ch->id);
}
static void ctcmpc_unpack_skb(struct channel *ch, struct sk_buff *pskb)
{
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct pdu *curr_pdu;
struct mpcg_info *mpcginfo;
struct th_header *header = NULL;
struct th_sweep *sweep = NULL;
int pdu_last_seen = 0;
__u32 new_len;
struct sk_buff *skb;
int skblen;
int sendrc = 0;
CTCM_PR_DEBUG("ctcmpc enter: %s() %s cp:%i ch:%s\n",
__func__, dev->name, smp_processor_id(), ch->id);
header = (struct th_header *)pskb->data;
if ((header->th_seg == 0) &&
(header->th_ch_flag == 0) &&
(header->th_blk_flag == 0) &&
(header->th_seq_num == 0))
goto done;
CTCM_PR_DBGDATA("%s: th_header\n", __func__);
CTCM_D3_DUMP((char *)header, TH_HEADER_LENGTH);
CTCM_PR_DBGDATA("%s: pskb len: %04x \n", __func__, pskb->len);
pskb->dev = dev;
pskb->ip_summed = CHECKSUM_UNNECESSARY;
skb_pull(pskb, TH_HEADER_LENGTH);
if (likely(header->th_ch_flag == TH_HAS_PDU)) {
CTCM_PR_DBGDATA("%s: came into th_has_pdu\n", __func__);
if ((fsm_getstate(grp->fsm) == MPCG_STATE_FLOWC) ||
((fsm_getstate(grp->fsm) == MPCG_STATE_READY) &&
(header->th_seq_num != ch->th_seq_num + 1) &&
(ch->th_seq_num != 0))) {
grp->out_of_sequence += 1;
__skb_push(pskb, TH_HEADER_LENGTH);
skb_queue_tail(&ch->io_queue, pskb);
CTCM_PR_DBGDATA("%s: th_seq_num expect:%08x "
"got:%08x\n", __func__,
ch->th_seq_num + 1, header->th_seq_num);
return;
}
grp->out_of_sequence = 0;
ch->th_seq_num = header->th_seq_num;
CTCM_PR_DBGDATA("ctcmpc: %s() FromVTAM_th_seq=%08x\n",
__func__, ch->th_seq_num);
if (unlikely(fsm_getstate(grp->fsm) != MPCG_STATE_READY))
goto done;
while ((pskb->len > 0) && !pdu_last_seen) {
curr_pdu = (struct pdu *)pskb->data;
CTCM_PR_DBGDATA("%s: pdu_header\n", __func__);
CTCM_D3_DUMP((char *)pskb->data, PDU_HEADER_LENGTH);
CTCM_PR_DBGDATA("%s: pskb len: %04x \n",
__func__, pskb->len);
skb_pull(pskb, PDU_HEADER_LENGTH);
if (curr_pdu->pdu_flag & PDU_LAST)
pdu_last_seen = 1;
if (curr_pdu->pdu_flag & PDU_CNTL)
pskb->protocol = htons(ETH_P_SNAP);
else
pskb->protocol = htons(ETH_P_SNA_DIX);
if ((pskb->len <= 0) || (pskb->len > ch->max_bufsize)) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): Dropping packet with "
"illegal siize %d",
CTCM_FUNTAIL, dev->name, pskb->len);
priv->stats.rx_dropped++;
priv->stats.rx_length_errors++;
goto done;
}
skb_reset_mac_header(pskb);
new_len = curr_pdu->pdu_offset;
CTCM_PR_DBGDATA("%s: new_len: %04x \n",
__func__, new_len);
if ((new_len == 0) || (new_len > pskb->len)) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): non valid pdu_offset: %04x",
CTCM_FUNTAIL, dev->name, new_len);
goto done;
}
skb = __dev_alloc_skb(new_len+4, GFP_ATOMIC);
if (!skb) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): MEMORY allocation error",
CTCM_FUNTAIL, dev->name);
priv->stats.rx_dropped++;
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
goto done;
}
memcpy(skb_put(skb, new_len), pskb->data, new_len);
skb_reset_mac_header(skb);
skb->dev = pskb->dev;
skb->protocol = pskb->protocol;
skb->ip_summed = CHECKSUM_UNNECESSARY;
*((__u32 *) skb_push(skb, 4)) = ch->pdu_seq;
ch->pdu_seq++;
if (do_debug_data) {
ctcm_pr_debug("%s: ToDCM_pdu_seq= %08x\n",
__func__, ch->pdu_seq);
ctcm_pr_debug("%s: skb:%0lx "
"skb len: %d \n", __func__,
(unsigned long)skb, skb->len);
ctcm_pr_debug("%s: up to 32 bytes "
"of pdu_data sent\n", __func__);
ctcmpc_dump32((char *)skb->data, skb->len);
}
skblen = skb->len;
sendrc = netif_rx(skb);
priv->stats.rx_packets++;
priv->stats.rx_bytes += skblen;
skb_pull(pskb, new_len);
}
} else {
mpcginfo = kmalloc(sizeof(struct mpcg_info), gfp_type());
if (mpcginfo == NULL)
goto done;
mpcginfo->ch = ch;
mpcginfo->th = header;
mpcginfo->skb = pskb;
CTCM_PR_DEBUG("%s: Not PDU - may be control pkt\n",
__func__);
sweep = (struct th_sweep *)pskb->data;
mpcginfo->sweep = sweep;
if (header->th_ch_flag == TH_SWEEP_REQ)
mpc_rcvd_sweep_req(mpcginfo);
else if (header->th_ch_flag == TH_SWEEP_RESP)
mpc_rcvd_sweep_resp(mpcginfo);
else if (header->th_blk_flag == TH_DATA_IS_XID) {
struct xid2 *thisxid = (struct xid2 *)pskb->data;
skb_pull(pskb, XID2_LENGTH);
mpcginfo->xid = thisxid;
fsm_event(grp->fsm, MPCG_EVENT_XID2, mpcginfo);
} else if (header->th_blk_flag == TH_DISCONTACT)
fsm_event(grp->fsm, MPCG_EVENT_DISCONC, mpcginfo);
else if (header->th_seq_num != 0) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): control pkt expected\n",
CTCM_FUNTAIL, dev->name);
priv->stats.rx_dropped++;
kfree(mpcginfo);
if (do_debug_data)
ctcmpc_dump_skb(pskb, -8);
}
}
done:
dev_kfree_skb_any(pskb);
if (sendrc == NET_RX_DROP) {
dev_warn(&dev->dev,
"The network backlog for %s is exceeded, "
"package dropped\n", __func__);
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
}
CTCM_PR_DEBUG("exit %s: %s: ch=0x%p id=%s\n",
__func__, dev->name, ch, ch->id);
}
void ctcmpc_bh(unsigned long thischan)
{
struct channel *ch = (struct channel *)thischan;
struct sk_buff *skb;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("%s cp:%i enter: %s() %s\n",
dev->name, smp_processor_id(), __func__, ch->id);
while ((fsm_getstate(grp->fsm) != MPCG_STATE_FLOWC) &&
(skb = skb_dequeue(&ch->io_queue))) {
ctcmpc_unpack_skb(ch, skb);
if (grp->out_of_sequence > 20) {
grp->out_of_sequence = 0;
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
break;
}
if (skb == skb_peek(&ch->io_queue))
break;
}
CTCM_PR_DEBUG("exit %s: %s: ch=0x%p id=%s\n",
__func__, dev->name, ch, ch->id);
return;
}
struct mpc_group *ctcmpc_init_mpc_group(struct ctcm_priv *priv)
{
struct mpc_group *grp;
CTCM_DBF_TEXT_(MPC_SETUP, CTC_DBF_INFO,
"Enter %s(%p)", CTCM_FUNTAIL, priv);
grp = kzalloc(sizeof(struct mpc_group), GFP_KERNEL);
if (grp == NULL)
return NULL;
grp->fsm = init_fsm("mpcg", mpcg_state_names, mpcg_event_names,
MPCG_NR_STATES, MPCG_NR_EVENTS, mpcg_fsm,
mpcg_fsm_len, GFP_KERNEL);
if (grp->fsm == NULL) {
kfree(grp);
return NULL;
}
fsm_newstate(grp->fsm, MPCG_STATE_RESET);
fsm_settimer(grp->fsm, &grp->timer);
grp->xid_skb =
__dev_alloc_skb(MPC_BUFSIZE_DEFAULT, GFP_ATOMIC | GFP_DMA);
if (grp->xid_skb == NULL) {
kfree_fsm(grp->fsm);
kfree(grp);
return NULL;
}
grp->xid_skb_data = grp->xid_skb->data;
grp->xid_th = (struct th_header *)grp->xid_skb->data;
memcpy(skb_put(grp->xid_skb, TH_HEADER_LENGTH),
&thnorm, TH_HEADER_LENGTH);
grp->xid = (struct xid2 *)skb_tail_pointer(grp->xid_skb);
memcpy(skb_put(grp->xid_skb, XID2_LENGTH), &init_xid, XID2_LENGTH);
grp->xid->xid2_adj_id = jiffies | 0xfff00000;
grp->xid->xid2_sender_id = jiffies;
grp->xid_id = skb_tail_pointer(grp->xid_skb);
memcpy(skb_put(grp->xid_skb, 4), "VTAM", 4);
grp->rcvd_xid_skb =
__dev_alloc_skb(MPC_BUFSIZE_DEFAULT, GFP_ATOMIC|GFP_DMA);
if (grp->rcvd_xid_skb == NULL) {
kfree_fsm(grp->fsm);
dev_kfree_skb(grp->xid_skb);
kfree(grp);
return NULL;
}
grp->rcvd_xid_data = grp->rcvd_xid_skb->data;
grp->rcvd_xid_th = (struct th_header *)grp->rcvd_xid_skb->data;
memcpy(skb_put(grp->rcvd_xid_skb, TH_HEADER_LENGTH),
&thnorm, TH_HEADER_LENGTH);
grp->saved_xid2 = NULL;
priv->xid = grp->xid;
priv->mpcg = grp;
return grp;
}
static void mpc_action_nop(fsm_instance *fi, int event, void *arg)
{
}
static void mpc_action_go_inop(fsm_instance *fi, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv;
struct mpc_group *grp;
struct channel *wch;
CTCM_PR_DEBUG("Enter %s: %s\n", __func__, dev->name);
priv = dev->ml_priv;
grp = priv->mpcg;
grp->flow_off_called = 0;
fsm_deltimer(&grp->timer);
if (grp->channels_terminating)
return;
grp->channels_terminating = 1;
grp->saved_state = fsm_getstate(grp->fsm);
fsm_newstate(grp->fsm, MPCG_STATE_INOP);
if (grp->saved_state > MPCG_STATE_XID7INITF)
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_NOTICE,
"%s(%s): MPC GROUP INOPERATIVE",
CTCM_FUNTAIL, dev->name);
if ((grp->saved_state != MPCG_STATE_RESET) ||
(grp->port_persist == 0))
fsm_deltimer(&priv->restart_timer);
wch = priv->channel[CTCM_WRITE];
switch (grp->saved_state) {
case MPCG_STATE_RESET:
case MPCG_STATE_INOP:
case MPCG_STATE_XID2INITW:
case MPCG_STATE_XID0IOWAIT:
case MPCG_STATE_XID2INITX:
case MPCG_STATE_XID7INITW:
case MPCG_STATE_XID7INITX:
case MPCG_STATE_XID0IOWAIX:
case MPCG_STATE_XID7INITI:
case MPCG_STATE_XID7INITZ:
case MPCG_STATE_XID7INITF:
break;
case MPCG_STATE_FLOWC:
case MPCG_STATE_READY:
default:
tasklet_hi_schedule(&wch->ch_disc_tasklet);
}
grp->xid2_tgnum = 0;
grp->group_max_buflen = 0;
grp->outstanding_xid2 = 0;
grp->outstanding_xid7 = 0;
grp->outstanding_xid7_p2 = 0;
grp->saved_xid2 = NULL;
grp->xidnogood = 0;
grp->changed_side = 0;
grp->rcvd_xid_skb->data = grp->rcvd_xid_data;
skb_reset_tail_pointer(grp->rcvd_xid_skb);
grp->rcvd_xid_skb->len = 0;
grp->rcvd_xid_th = (struct th_header *)grp->rcvd_xid_skb->data;
memcpy(skb_put(grp->rcvd_xid_skb, TH_HEADER_LENGTH), &thnorm,
TH_HEADER_LENGTH);
if (grp->send_qllc_disc == 1) {
grp->send_qllc_disc = 0;
mpc_send_qllc_discontact(dev);
}
if ((grp->port_persist == 1) || (grp->alloc_called)) {
grp->alloc_called = 0;
fsm_deltimer(&priv->restart_timer);
fsm_addtimer(&priv->restart_timer, 500, DEV_EVENT_RESTART, dev);
fsm_newstate(grp->fsm, MPCG_STATE_RESET);
if (grp->saved_state > MPCG_STATE_XID7INITF)
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_ALWAYS,
"%s(%s): MPC GROUP RECOVERY SCHEDULED",
CTCM_FUNTAIL, dev->name);
} else {
fsm_deltimer(&priv->restart_timer);
fsm_addtimer(&priv->restart_timer, 500, DEV_EVENT_STOP, dev);
fsm_newstate(grp->fsm, MPCG_STATE_RESET);
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_ALWAYS,
"%s(%s): NO MPC GROUP RECOVERY ATTEMPTED",
CTCM_FUNTAIL, dev->name);
}
}
static void mpc_action_timeout(fsm_instance *fi, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv;
struct mpc_group *grp;
struct channel *wch;
struct channel *rch;
priv = dev->ml_priv;
grp = priv->mpcg;
wch = priv->channel[CTCM_WRITE];
rch = priv->channel[CTCM_READ];
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_XID2INITW:
if ((fsm_getstate(rch->fsm) == CH_XID0_PENDING) &&
(fsm_getstate(wch->fsm) == CH_XID0_PENDING))
break;
default:
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
}
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_DEBUG,
"%s: dev=%s exit",
CTCM_FUNTAIL, dev->name);
return;
}
void mpc_action_discontact(fsm_instance *fi, int event, void *arg)
{
struct mpcg_info *mpcginfo = arg;
struct channel *ch = mpcginfo->ch;
struct net_device *dev;
struct ctcm_priv *priv;
struct mpc_group *grp;
if (ch) {
dev = ch->netdev;
if (dev) {
priv = dev->ml_priv;
if (priv) {
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_NOTICE,
"%s: %s: %s\n",
CTCM_FUNTAIL, dev->name, ch->id);
grp = priv->mpcg;
grp->send_qllc_disc = 1;
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
}
}
}
return;
}
void mpc_action_send_discontact(unsigned long thischan)
{
int rc;
struct channel *ch = (struct channel *)thischan;
unsigned long saveflags = 0;
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
rc = ccw_device_start(ch->cdev, &ch->ccw[15],
(unsigned long)ch, 0xff, 0);
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0) {
ctcm_ccw_check_rc(ch, rc, (char *)__func__);
}
return;
}
static int mpc_validate_xid(struct mpcg_info *mpcginfo)
{
struct channel *ch = mpcginfo->ch;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct xid2 *xid = mpcginfo->xid;
int rc = 0;
__u64 our_id = 0;
__u64 their_id = 0;
int len = TH_HEADER_LENGTH + PDU_HEADER_LENGTH;
CTCM_PR_DEBUG("Enter %s: xid=%p\n", __func__, xid);
if (xid == NULL) {
rc = 1;
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): xid = NULL",
CTCM_FUNTAIL, ch->id);
goto done;
}
CTCM_D3_DUMP((char *)xid, XID2_LENGTH);
if (((CHANNEL_DIRECTION(ch->flags) == CTCM_READ) ? XID2_WRITE_SIDE :
XID2_READ_SIDE) != xid->xid2_dlc_type) {
rc = 2;
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): r/w channel pairing mismatch",
CTCM_FUNTAIL, ch->id);
goto done;
}
if (xid->xid2_dlc_type == XID2_READ_SIDE) {
CTCM_PR_DEBUG("%s: grpmaxbuf:%d xid2buflen:%d\n", __func__,
grp->group_max_buflen, xid->xid2_buf_len);
if (grp->group_max_buflen == 0 || grp->group_max_buflen >
xid->xid2_buf_len - len)
grp->group_max_buflen = xid->xid2_buf_len - len;
}
if (grp->saved_xid2 == NULL) {
grp->saved_xid2 =
(struct xid2 *)skb_tail_pointer(grp->rcvd_xid_skb);
memcpy(skb_put(grp->rcvd_xid_skb,
XID2_LENGTH), xid, XID2_LENGTH);
grp->rcvd_xid_skb->data = grp->rcvd_xid_data;
skb_reset_tail_pointer(grp->rcvd_xid_skb);
grp->rcvd_xid_skb->len = 0;
our_id = (__u64)priv->xid->xid2_adj_id;
our_id = our_id << 32;
our_id = our_id + priv->xid->xid2_sender_id;
their_id = (__u64)xid->xid2_adj_id;
their_id = their_id << 32;
their_id = their_id + xid->xid2_sender_id;
if (our_id < their_id) {
grp->roll = XSIDE;
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_NOTICE,
"%s(%s): WE HAVE LOW ID - TAKE XSIDE",
CTCM_FUNTAIL, ch->id);
} else {
grp->roll = YSIDE;
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_NOTICE,
"%s(%s): WE HAVE HIGH ID - TAKE YSIDE",
CTCM_FUNTAIL, ch->id);
}
} else {
if (xid->xid2_flag4 != grp->saved_xid2->xid2_flag4) {
rc = 3;
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): xid flag byte4 mismatch",
CTCM_FUNTAIL, ch->id);
}
if (xid->xid2_flag2 == 0x40) {
rc = 4;
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): xid NOGOOD",
CTCM_FUNTAIL, ch->id);
}
if (xid->xid2_adj_id != grp->saved_xid2->xid2_adj_id) {
rc = 5;
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): Adjacent Station ID Mismatch",
CTCM_FUNTAIL, ch->id);
}
if (xid->xid2_sender_id != grp->saved_xid2->xid2_sender_id) {
rc = 6;
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): Sender Address Mismatch",
CTCM_FUNTAIL, ch->id);
}
}
done:
if (rc) {
dev_warn(&dev->dev,
"The XID used in the MPC protocol is not valid, "
"rc = %d\n", rc);
priv->xid->xid2_flag2 = 0x40;
grp->saved_xid2->xid2_flag2 = 0x40;
}
return rc;
}
static void mpc_action_side_xid(fsm_instance *fsm, void *arg, int side)
{
struct channel *ch = arg;
int rc = 0;
int gotlock = 0;
unsigned long saveflags = 0;
CTCM_PR_DEBUG("Enter %s: cp=%i ch=0x%p id=%s\n",
__func__, smp_processor_id(), ch, ch->id);
if (ctcm_checkalloc_buffer(ch))
goto done;
ch->trans_skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(ch->trans_skb);
ch->trans_skb->len = 0;
memset(ch->trans_skb->data, 0, 16);
ch->rcvd_xid_th = (struct th_header *)ch->trans_skb_data;
skb_put(ch->trans_skb, TH_HEADER_LENGTH);
ch->rcvd_xid = (struct xid2 *)skb_tail_pointer(ch->trans_skb);
skb_put(ch->trans_skb, XID2_LENGTH);
ch->rcvd_xid_id = skb_tail_pointer(ch->trans_skb);
ch->trans_skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(ch->trans_skb);
ch->trans_skb->len = 0;
ch->ccw[8].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[8].count = 0;
ch->ccw[8].cda = 0x00;
if (!(ch->xid_th && ch->xid && ch->xid_id))
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_INFO,
"%s(%s): xid_th=%p, xid=%p, xid_id=%p",
CTCM_FUNTAIL, ch->id, ch->xid_th, ch->xid, ch->xid_id);
if (side == XSIDE) {
if (ch->xid_th == NULL)
goto done;
ch->ccw[9].cmd_code = CCW_CMD_WRITE;
ch->ccw[9].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[9].count = TH_HEADER_LENGTH;
ch->ccw[9].cda = virt_to_phys(ch->xid_th);
if (ch->xid == NULL)
goto done;
ch->ccw[10].cmd_code = CCW_CMD_WRITE;
ch->ccw[10].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[10].count = XID2_LENGTH;
ch->ccw[10].cda = virt_to_phys(ch->xid);
ch->ccw[11].cmd_code = CCW_CMD_READ;
ch->ccw[11].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[11].count = TH_HEADER_LENGTH;
ch->ccw[11].cda = virt_to_phys(ch->rcvd_xid_th);
ch->ccw[12].cmd_code = CCW_CMD_READ;
ch->ccw[12].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[12].count = XID2_LENGTH;
ch->ccw[12].cda = virt_to_phys(ch->rcvd_xid);
ch->ccw[13].cmd_code = CCW_CMD_READ;
ch->ccw[13].cda = virt_to_phys(ch->rcvd_xid_id);
} else {
ch->ccw[9].cmd_code = CCW_CMD_READ;
ch->ccw[9].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[9].count = TH_HEADER_LENGTH;
ch->ccw[9].cda = virt_to_phys(ch->rcvd_xid_th);
ch->ccw[10].cmd_code = CCW_CMD_READ;
ch->ccw[10].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[10].count = XID2_LENGTH;
ch->ccw[10].cda = virt_to_phys(ch->rcvd_xid);
if (ch->xid_th == NULL)
goto done;
ch->ccw[11].cmd_code = CCW_CMD_WRITE;
ch->ccw[11].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[11].count = TH_HEADER_LENGTH;
ch->ccw[11].cda = virt_to_phys(ch->xid_th);
if (ch->xid == NULL)
goto done;
ch->ccw[12].cmd_code = CCW_CMD_WRITE;
ch->ccw[12].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[12].count = XID2_LENGTH;
ch->ccw[12].cda = virt_to_phys(ch->xid);
if (ch->xid_id == NULL)
goto done;
ch->ccw[13].cmd_code = CCW_CMD_WRITE;
ch->ccw[13].cda = virt_to_phys(ch->xid_id);
}
ch->ccw[13].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[13].count = 4;
ch->ccw[14].cmd_code = CCW_CMD_NOOP;
ch->ccw[14].flags = CCW_FLAG_SLI;
ch->ccw[14].count = 0;
ch->ccw[14].cda = 0;
CTCM_CCW_DUMP((char *)&ch->ccw[8], sizeof(struct ccw1) * 7);
CTCM_D3_DUMP((char *)ch->xid_th, TH_HEADER_LENGTH);
CTCM_D3_DUMP((char *)ch->xid, XID2_LENGTH);
CTCM_D3_DUMP((char *)ch->xid_id, 4);
if (!in_irq()) {
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
gotlock = 1;
}
fsm_addtimer(&ch->timer, 5000 , CTC_EVENT_TIMER, ch);
rc = ccw_device_start(ch->cdev, &ch->ccw[8],
(unsigned long)ch, 0xff, 0);
if (gotlock)
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0) {
ctcm_ccw_check_rc(ch, rc,
(side == XSIDE) ? "x-side XID" : "y-side XID");
}
done:
CTCM_PR_DEBUG("Exit %s: ch=0x%p id=%s\n",
__func__, ch, ch->id);
return;
}
static void mpc_action_xside_xid(fsm_instance *fsm, int event, void *arg)
{
mpc_action_side_xid(fsm, arg, XSIDE);
}
static void mpc_action_yside_xid(fsm_instance *fsm, int event, void *arg)
{
mpc_action_side_xid(fsm, arg, YSIDE);
}
static void mpc_action_doxid0(fsm_instance *fsm, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("Enter %s: cp=%i ch=0x%p id=%s\n",
__func__, smp_processor_id(), ch, ch->id);
if (ch->xid == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): ch->xid == NULL",
CTCM_FUNTAIL, dev->name);
return;
}
fsm_newstate(ch->fsm, CH_XID0_INPROGRESS);
ch->xid->xid2_option = XID2_0;
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_XID2INITW:
case MPCG_STATE_XID2INITX:
ch->ccw[8].cmd_code = CCW_CMD_SENSE_CMD;
break;
case MPCG_STATE_XID0IOWAIT:
case MPCG_STATE_XID0IOWAIX:
ch->ccw[8].cmd_code = CCW_CMD_WRITE_CTL;
break;
}
fsm_event(grp->fsm, MPCG_EVENT_DOIO, ch);
return;
}
static void mpc_action_doxid7(fsm_instance *fsm, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = NULL;
int direction;
int send = 0;
if (priv)
grp = priv->mpcg;
if (grp == NULL)
return;
for (direction = CTCM_READ; direction <= CTCM_WRITE; direction++) {
struct channel *ch = priv->channel[direction];
struct xid2 *thisxid = ch->xid;
ch->xid_skb->data = ch->xid_skb_data;
skb_reset_tail_pointer(ch->xid_skb);
ch->xid_skb->len = 0;
thisxid->xid2_option = XID2_7;
send = 0;
if (grp->outstanding_xid7_p2 > 0) {
if (grp->roll == YSIDE) {
if (fsm_getstate(ch->fsm) == CH_XID7_PENDING1) {
fsm_newstate(ch->fsm, CH_XID7_PENDING2);
ch->ccw[8].cmd_code = CCW_CMD_SENSE_CMD;
memcpy(skb_put(ch->xid_skb,
TH_HEADER_LENGTH),
&thdummy, TH_HEADER_LENGTH);
send = 1;
}
} else if (fsm_getstate(ch->fsm) < CH_XID7_PENDING2) {
fsm_newstate(ch->fsm, CH_XID7_PENDING2);
ch->ccw[8].cmd_code = CCW_CMD_WRITE_CTL;
memcpy(skb_put(ch->xid_skb,
TH_HEADER_LENGTH),
&thnorm, TH_HEADER_LENGTH);
send = 1;
}
} else {
if (grp->roll == YSIDE) {
if (fsm_getstate(ch->fsm) < CH_XID7_PENDING4) {
fsm_newstate(ch->fsm, CH_XID7_PENDING4);
memcpy(skb_put(ch->xid_skb,
TH_HEADER_LENGTH),
&thnorm, TH_HEADER_LENGTH);
ch->ccw[8].cmd_code = CCW_CMD_WRITE_CTL;
send = 1;
}
} else if (fsm_getstate(ch->fsm) == CH_XID7_PENDING3) {
fsm_newstate(ch->fsm, CH_XID7_PENDING4);
ch->ccw[8].cmd_code = CCW_CMD_SENSE_CMD;
memcpy(skb_put(ch->xid_skb, TH_HEADER_LENGTH),
&thdummy, TH_HEADER_LENGTH);
send = 1;
}
}
if (send)
fsm_event(grp->fsm, MPCG_EVENT_DOIO, ch);
}
return;
}
static void mpc_action_rcvd_xid0(fsm_instance *fsm, int event, void *arg)
{
struct mpcg_info *mpcginfo = arg;
struct channel *ch = mpcginfo->ch;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("%s: ch-id:%s xid2:%i xid7:%i xidt_p2:%i \n",
__func__, ch->id, grp->outstanding_xid2,
grp->outstanding_xid7, grp->outstanding_xid7_p2);
if (fsm_getstate(ch->fsm) < CH_XID7_PENDING)
fsm_newstate(ch->fsm, CH_XID7_PENDING);
grp->outstanding_xid2--;
grp->outstanding_xid7++;
grp->outstanding_xid7_p2++;
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_XID2INITW:
fsm_newstate(grp->fsm, MPCG_STATE_XID2INITX);
mpc_validate_xid(mpcginfo);
break;
case MPCG_STATE_XID0IOWAIT:
fsm_newstate(grp->fsm, MPCG_STATE_XID0IOWAIX);
mpc_validate_xid(mpcginfo);
break;
case MPCG_STATE_XID2INITX:
if (grp->outstanding_xid2 == 0) {
fsm_newstate(grp->fsm, MPCG_STATE_XID7INITW);
mpc_validate_xid(mpcginfo);
fsm_event(grp->fsm, MPCG_EVENT_XID2DONE, dev);
}
break;
case MPCG_STATE_XID0IOWAIX:
if (grp->outstanding_xid2 == 0) {
fsm_newstate(grp->fsm, MPCG_STATE_XID7INITI);
mpc_validate_xid(mpcginfo);
fsm_event(grp->fsm, MPCG_EVENT_XID2DONE, dev);
}
break;
}
kfree(mpcginfo);
CTCM_PR_DEBUG("ctcmpc:%s() %s xid2:%i xid7:%i xidt_p2:%i \n",
__func__, ch->id, grp->outstanding_xid2,
grp->outstanding_xid7, grp->outstanding_xid7_p2);
CTCM_PR_DEBUG("ctcmpc:%s() %s grpstate: %s chanstate: %s \n",
__func__, ch->id,
fsm_getstate_str(grp->fsm), fsm_getstate_str(ch->fsm));
return;
}
static void mpc_action_rcvd_xid7(fsm_instance *fsm, int event, void *arg)
{
struct mpcg_info *mpcginfo = arg;
struct channel *ch = mpcginfo->ch;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("Enter %s: cp=%i ch=0x%p id=%s\n",
__func__, smp_processor_id(), ch, ch->id);
CTCM_PR_DEBUG("%s: outstanding_xid7: %i, outstanding_xid7_p2: %i\n",
__func__, grp->outstanding_xid7, grp->outstanding_xid7_p2);
grp->outstanding_xid7--;
ch->xid_skb->data = ch->xid_skb_data;
skb_reset_tail_pointer(ch->xid_skb);
ch->xid_skb->len = 0;
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_XID7INITI:
fsm_newstate(grp->fsm, MPCG_STATE_XID7INITZ);
mpc_validate_xid(mpcginfo);
break;
case MPCG_STATE_XID7INITW:
fsm_newstate(grp->fsm, MPCG_STATE_XID7INITX);
mpc_validate_xid(mpcginfo);
break;
case MPCG_STATE_XID7INITZ:
case MPCG_STATE_XID7INITX:
if (grp->outstanding_xid7 == 0) {
if (grp->outstanding_xid7_p2 > 0) {
grp->outstanding_xid7 =
grp->outstanding_xid7_p2;
grp->outstanding_xid7_p2 = 0;
} else
fsm_newstate(grp->fsm, MPCG_STATE_XID7INITF);
mpc_validate_xid(mpcginfo);
fsm_event(grp->fsm, MPCG_EVENT_XID7DONE, dev);
break;
}
mpc_validate_xid(mpcginfo);
break;
}
kfree(mpcginfo);
return;
}
static int mpc_send_qllc_discontact(struct net_device *dev)
{
__u32 new_len = 0;
struct sk_buff *skb;
struct qllc *qllcptr;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("%s: GROUP STATE: %s\n",
__func__, mpcg_state_names[grp->saved_state]);
switch (grp->saved_state) {
case MPCG_STATE_XID0IOWAIT:
case MPCG_STATE_XID0IOWAIX:
case MPCG_STATE_XID7INITI:
case MPCG_STATE_XID7INITZ:
case MPCG_STATE_XID2INITW:
case MPCG_STATE_XID2INITX:
case MPCG_STATE_XID7INITW:
case MPCG_STATE_XID7INITX:
if (grp->estconnfunc) {
grp->estconnfunc(grp->port_num, -1, 0);
grp->estconnfunc = NULL;
break;
}
case MPCG_STATE_FLOWC:
case MPCG_STATE_READY:
grp->send_qllc_disc = 2;
new_len = sizeof(struct qllc);
qllcptr = kzalloc(new_len, gfp_type() | GFP_DMA);
if (qllcptr == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): qllcptr allocation error",
CTCM_FUNTAIL, dev->name);
return -ENOMEM;
}
qllcptr->qllc_address = 0xcc;
qllcptr->qllc_commands = 0x03;
skb = __dev_alloc_skb(new_len, GFP_ATOMIC);
if (skb == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): skb allocation error",
CTCM_FUNTAIL, dev->name);
priv->stats.rx_dropped++;
kfree(qllcptr);
return -ENOMEM;
}
memcpy(skb_put(skb, new_len), qllcptr, new_len);
kfree(qllcptr);
if (skb_headroom(skb) < 4) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): skb_headroom error",
CTCM_FUNTAIL, dev->name);
dev_kfree_skb_any(skb);
return -ENOMEM;
}
*((__u32 *)skb_push(skb, 4)) =
priv->channel[CTCM_READ]->pdu_seq;
priv->channel[CTCM_READ]->pdu_seq++;
CTCM_PR_DBGDATA("ctcmpc: %s ToDCM_pdu_seq= %08x\n",
__func__, priv->channel[CTCM_READ]->pdu_seq);
priv->channel[CTCM_READ]->pdu_seq = 0x00;
skb_reset_mac_header(skb);
skb->dev = dev;
skb->protocol = htons(ETH_P_SNAP);
skb->ip_summed = CHECKSUM_UNNECESSARY;
CTCM_D3_DUMP(skb->data, (sizeof(struct qllc) + 4));
netif_rx(skb);
break;
default:
break;
}
return 0;
}
