void ctcm_ccw_check_rc(struct channel *ch, int rc, char *msg)
{
CTCM_DBF_TEXT_(ERROR, CTC_DBF_ERROR,
"%s(%s): %s: %04x\n",
CTCM_FUNTAIL, ch->id, msg, rc);
switch (rc) {
case -EBUSY:
pr_info("%s: The communication peer is busy\n",
ch->id);
fsm_event(ch->fsm, CTC_EVENT_IO_EBUSY, ch);
break;
case -ENODEV:
pr_err("%s: The specified target device is not valid\n",
ch->id);
fsm_event(ch->fsm, CTC_EVENT_IO_ENODEV, ch);
break;
default:
pr_err("An I/O operation resulted in error %04x\n",
rc);
fsm_event(ch->fsm, CTC_EVENT_IO_UNKNOWN, ch);
}
}
void ctcm_purge_skb_queue(struct sk_buff_head *q)
{
struct sk_buff *skb;
CTCM_DBF_TEXT(TRACE, CTC_DBF_DEBUG, __func__);
while ((skb = skb_dequeue(q))) {
atomic_dec(&skb->users);
dev_kfree_skb_any(skb);
}
}
static void ctcm_action_nop(fsm_instance *fi, int event, void *arg)
{
}
static void chx_txdone(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct sk_buff *skb;
int first = 1;
int i;
unsigned long duration;
unsigned long done_stamp = jiffies;
CTCM_PR_DEBUG("%s(%s): %s\n", __func__, ch->id, dev->name);
duration = done_stamp - ch->prof.send_stamp;
if (duration > ch->prof.tx_time)
ch->prof.tx_time = duration;
if (ch->irb->scsw.cmd.count != 0)
CTCM_DBF_TEXT_(TRACE, CTC_DBF_DEBUG,
"%s(%s): TX not complete, remaining %d bytes",
CTCM_FUNTAIL, dev->name, ch->irb->scsw.cmd.count);
fsm_deltimer(&ch->timer);
while ((skb = skb_dequeue(&ch->io_queue))) {
priv->stats.tx_packets++;
priv->stats.tx_bytes += skb->len - LL_HEADER_LENGTH;
if (first) {
priv->stats.tx_bytes += 2;
first = 0;
}
atomic_dec(&skb->users);
dev_kfree_skb_irq(skb);
}
spin_lock(&ch->collect_lock);
clear_normalized_cda(&ch->ccw[4]);
if (ch->collect_len > 0) {
int rc;
if (ctcm_checkalloc_buffer(ch)) {
spin_unlock(&ch->collect_lock);
return;
}
ch->trans_skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(ch->trans_skb);
ch->trans_skb->len = 0;
if (ch->prof.maxmulti < (ch->collect_len + 2))
ch->prof.maxmulti = ch->collect_len + 2;
if (ch->prof.maxcqueue < skb_queue_len(&ch->collect_queue))
ch->prof.maxcqueue = skb_queue_len(&ch->collect_queue);
*((__u16 *)skb_put(ch->trans_skb, 2)) = ch->collect_len + 2;
i = 0;
while ((skb = skb_dequeue(&ch->collect_queue))) {
skb_copy_from_linear_data(skb,
skb_put(ch->trans_skb, skb->len), skb->len);
priv->stats.tx_packets++;
priv->stats.tx_bytes += skb->len - LL_HEADER_LENGTH;
atomic_dec(&skb->users);
dev_kfree_skb_irq(skb);
i++;
}
ch->collect_len = 0;
spin_unlock(&ch->collect_lock);
ch->ccw[1].count = ch->trans_skb->len;
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, ch);
ch->prof.send_stamp = jiffies;
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
ch->prof.doios_multi++;
if (rc != 0) {
priv->stats.tx_dropped += i;
priv->stats.tx_errors += i;
fsm_deltimer(&ch->timer);
ctcm_ccw_check_rc(ch, rc, "chained TX");
}
} else {
spin_unlock(&ch->collect_lock);
fsm_newstate(fi, CTC_STATE_TXIDLE);
}
ctcm_clear_busy_do(dev);
}
void ctcm_chx_txidle(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
CTCM_PR_DEBUG("%s(%s): %s\n", __func__, ch->id, dev->name);
fsm_deltimer(&ch->timer);
fsm_newstate(fi, CTC_STATE_TXIDLE);
fsm_event(priv->fsm, DEV_EVENT_TXUP, ch->netdev);
}
static void chx_rx(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
int len = ch->max_bufsize - ch->irb->scsw.cmd.count;
struct sk_buff *skb = ch->trans_skb;
__u16 block_len = *((__u16 *)skb->data);
int check_len;
int rc;
fsm_deltimer(&ch->timer);
if (len < 8) {
CTCM_DBF_TEXT_(TRACE, CTC_DBF_NOTICE,
"%s(%s): got packet with length %d < 8\n",
CTCM_FUNTAIL, dev->name, len);
priv->stats.rx_dropped++;
priv->stats.rx_length_errors++;
goto again;
}
if (len > ch->max_bufsize) {
CTCM_DBF_TEXT_(TRACE, CTC_DBF_NOTICE,
"%s(%s): got packet with length %d > %d\n",
CTCM_FUNTAIL, dev->name, len, ch->max_bufsize);
priv->stats.rx_dropped++;
priv->stats.rx_length_errors++;
goto again;
}
switch (ch->protocol) {
case CTCM_PROTO_S390:
case CTCM_PROTO_OS390:
check_len = block_len + 2;
break;
default:
check_len = block_len;
break;
}
if ((len < block_len) || (len > check_len)) {
CTCM_DBF_TEXT_(TRACE, CTC_DBF_NOTICE,
"%s(%s): got block length %d != rx length %d\n",
CTCM_FUNTAIL, dev->name, block_len, len);
if (do_debug)
ctcmpc_dump_skb(skb, 0);
*((__u16 *)skb->data) = len;
priv->stats.rx_dropped++;
priv->stats.rx_length_errors++;
goto again;
}
if (block_len > 2) {
*((__u16 *)skb->data) = block_len - 2;
ctcm_unpack_skb(ch, skb);
}
again:
skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(skb);
skb->len = 0;
if (ctcm_checkalloc_buffer(ch))
return;
ch->ccw[1].count = ch->max_bufsize;
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
if (rc != 0)
ctcm_ccw_check_rc(ch, rc, "normal RX");
}
static void chx_firstio(fsm_instance *fi, int event, void *arg)
{
int rc;
struct channel *ch = arg;
int fsmstate = fsm_getstate(fi);
CTCM_DBF_TEXT_(TRACE, CTC_DBF_NOTICE,
"%s(%s) : %02x",
CTCM_FUNTAIL, ch->id, fsmstate);
ch->sense_rc = 0;
if (fsmstate == CTC_STATE_TXIDLE)
CTCM_DBF_TEXT_(TRACE, CTC_DBF_DEBUG,
"%s(%s): remote side issued READ?, init.\n",
CTCM_FUNTAIL, ch->id);
fsm_deltimer(&ch->timer);
if (ctcm_checkalloc_buffer(ch))
return;
if ((fsmstate == CTC_STATE_SETUPWAIT) &&
(ch->protocol == CTCM_PROTO_OS390)) {
if (CHANNEL_DIRECTION(ch->flags) == CTCM_READ) {
*((__u16 *)ch->trans_skb->data) = CTCM_INITIAL_BLOCKLEN;
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC,
CTC_EVENT_TIMER, ch);
chx_rxidle(fi, event, arg);
} else {
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
fsm_newstate(fi, CTC_STATE_TXIDLE);
fsm_event(priv->fsm, DEV_EVENT_TXUP, dev);
}
return;
}
if ((CHANNEL_DIRECTION(ch->flags) == CTCM_WRITE) ||
(ch->protocol != CTCM_PROTO_S390))
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, ch);
*((__u16 *)ch->trans_skb->data) = CTCM_INITIAL_BLOCKLEN;
ch->ccw[1].count = 2;
fsm_newstate(fi, (CHANNEL_DIRECTION(ch->flags) == CTCM_READ)
? CTC_STATE_RXINIT : CTC_STATE_TXINIT);
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
if (rc != 0) {
fsm_deltimer(&ch->timer);
fsm_newstate(fi, CTC_STATE_SETUPWAIT);
ctcm_ccw_check_rc(ch, rc, "init IO");
}
if ((CHANNEL_DIRECTION(ch->flags) == CTCM_READ) &&
(ch->protocol == CTCM_PROTO_S390)) {
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
fsm_event(priv->fsm, DEV_EVENT_RXUP, dev);
}
}
static void chx_rxidle(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
__u16 buflen;
int rc;
fsm_deltimer(&ch->timer);
buflen = *((__u16 *)ch->trans_skb->data);
CTCM_PR_DEBUG("%s: %s: Initial RX count = %d\n",
__func__, dev->name, buflen);
if (buflen >= CTCM_INITIAL_BLOCKLEN) {
if (ctcm_checkalloc_buffer(ch))
return;
ch->ccw[1].count = ch->max_bufsize;
fsm_newstate(fi, CTC_STATE_RXIDLE);
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
if (rc != 0) {
fsm_newstate(fi, CTC_STATE_RXINIT);
ctcm_ccw_check_rc(ch, rc, "initial RX");
} else
fsm_event(priv->fsm, DEV_EVENT_RXUP, dev);
} else {
CTCM_PR_DEBUG("%s: %s: Initial RX count %d not %d\n",
__func__, dev->name,
buflen, CTCM_INITIAL_BLOCKLEN);
chx_firstio(fi, event, arg);
}
}
static void ctcm_chx_setmode(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
int rc;
unsigned long saveflags = 0;
int timeout = CTCM_TIME_5_SEC;
fsm_deltimer(&ch->timer);
if (IS_MPC(ch)) {
timeout = 1500;
CTCM_PR_DEBUG("enter %s: cp=%i ch=0x%p id=%s\n",
__func__, smp_processor_id(), ch, ch->id);
}
fsm_addtimer(&ch->timer, timeout, CTC_EVENT_TIMER, ch);
fsm_newstate(fi, CTC_STATE_SETUPWAIT);
CTCM_CCW_DUMP((char *)&ch->ccw[6], sizeof(struct ccw1) * 2);
if (event == CTC_EVENT_TIMER)
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
rc = ccw_device_start(ch->cdev, &ch->ccw[6],
(unsigned long)ch, 0xff, 0);
if (event == CTC_EVENT_TIMER)
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0) {
fsm_deltimer(&ch->timer);
fsm_newstate(fi, CTC_STATE_STARTWAIT);
ctcm_ccw_check_rc(ch, rc, "set Mode");
} else
ch->retry = 0;
}
static void ctcm_chx_start(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
unsigned long saveflags;
int rc;
CTCM_DBF_TEXT_(SETUP, CTC_DBF_INFO, "%s(%s): %s",
CTCM_FUNTAIL, ch->id,
(CHANNEL_DIRECTION(ch->flags) == CTCM_READ) ? "RX" : "TX");
if (ch->trans_skb != NULL) {
clear_normalized_cda(&ch->ccw[1]);
dev_kfree_skb(ch->trans_skb);
ch->trans_skb = NULL;
}
if (CHANNEL_DIRECTION(ch->flags) == CTCM_READ) {
ch->ccw[1].cmd_code = CCW_CMD_READ;
ch->ccw[1].flags = CCW_FLAG_SLI;
ch->ccw[1].count = 0;
} else {
ch->ccw[1].cmd_code = CCW_CMD_WRITE;
ch->ccw[1].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[1].count = 0;
}
if (ctcm_checkalloc_buffer(ch)) {
CTCM_DBF_TEXT_(TRACE, CTC_DBF_DEBUG,
"%s(%s): %s trans_skb alloc delayed "
"until first transfer",
CTCM_FUNTAIL, ch->id,
(CHANNEL_DIRECTION(ch->flags) == CTCM_READ) ?
"RX" : "TX");
}
ch->ccw[0].cmd_code = CCW_CMD_PREPARE;
ch->ccw[0].flags = CCW_FLAG_SLI | CCW_FLAG_CC;
ch->ccw[0].count = 0;
ch->ccw[0].cda = 0;
ch->ccw[2].cmd_code = CCW_CMD_NOOP;
ch->ccw[2].flags = CCW_FLAG_SLI;
ch->ccw[2].count = 0;
ch->ccw[2].cda = 0;
memcpy(&ch->ccw[3], &ch->ccw[0], sizeof(struct ccw1) * 3);
ch->ccw[4].cda = 0;
ch->ccw[4].flags &= ~CCW_FLAG_IDA;
fsm_newstate(fi, CTC_STATE_STARTWAIT);
fsm_addtimer(&ch->timer, 1000, CTC_EVENT_TIMER, ch);
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
rc = ccw_device_halt(ch->cdev, (unsigned long)ch);
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0) {
if (rc != -EBUSY)
fsm_deltimer(&ch->timer);
ctcm_ccw_check_rc(ch, rc, "initial HaltIO");
}
}
static void ctcm_chx_haltio(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
unsigned long saveflags = 0;
int rc;
int oldstate;
fsm_deltimer(&ch->timer);
if (IS_MPC(ch))
fsm_deltimer(&ch->sweep_timer);
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, ch);
if (event == CTC_EVENT_STOP)
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
oldstate = fsm_getstate(fi);
fsm_newstate(fi, CTC_STATE_TERM);
rc = ccw_device_halt(ch->cdev, (unsigned long)ch);
if (event == CTC_EVENT_STOP)
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0 && rc != -EBUSY) {
fsm_deltimer(&ch->timer);
if (event != CTC_EVENT_STOP) {
fsm_newstate(fi, oldstate);
ctcm_ccw_check_rc(ch, rc, (char *)__func__);
}
}
}
static void ctcm_chx_cleanup(fsm_instance *fi, int state,
struct channel *ch)
{
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
CTCM_DBF_TEXT_(SETUP, CTC_DBF_NOTICE,
"%s(%s): %s[%d]\n",
CTCM_FUNTAIL, dev->name, ch->id, state);
fsm_deltimer(&ch->timer);
if (IS_MPC(ch))
fsm_deltimer(&ch->sweep_timer);
fsm_newstate(fi, state);
if (state == CTC_STATE_STOPPED && ch->trans_skb != NULL) {
clear_normalized_cda(&ch->ccw[1]);
dev_kfree_skb_any(ch->trans_skb);
ch->trans_skb = NULL;
}
ch->th_seg = 0x00;
ch->th_seq_num = 0x00;
if (CHANNEL_DIRECTION(ch->flags) == CTCM_READ) {
skb_queue_purge(&ch->io_queue);
fsm_event(priv->fsm, DEV_EVENT_RXDOWN, dev);
} else {
ctcm_purge_skb_queue(&ch->io_queue);
if (IS_MPC(ch))
ctcm_purge_skb_queue(&ch->sweep_queue);
spin_lock(&ch->collect_lock);
ctcm_purge_skb_queue(&ch->collect_queue);
ch->collect_len = 0;
spin_unlock(&ch->collect_lock);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
}
}
static void ctcm_chx_stopped(fsm_instance *fi, int event, void *arg)
{
ctcm_chx_cleanup(fi, CTC_STATE_STOPPED, arg);
}
static void ctcm_chx_stop(fsm_instance *fi, int event, void *arg)
{
fsm_newstate(fi, CTC_STATE_STOPPED);
}
static void ctcm_chx_fail(fsm_instance *fi, int event, void *arg)
{
ctcm_chx_cleanup(fi, CTC_STATE_NOTOP, arg);
}
static void ctcm_chx_setuperr(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
if ((fsm_getstate(fi) == CTC_STATE_SETUPWAIT) &&
((event == CTC_EVENT_UC_RCRESET) ||
(event == CTC_EVENT_UC_RSRESET))) {
fsm_newstate(fi, CTC_STATE_STARTRETRY);
fsm_deltimer(&ch->timer);
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, ch);
if (!IS_MPC(ch) &&
(CHANNEL_DIRECTION(ch->flags) == CTCM_READ)) {
int rc = ccw_device_halt(ch->cdev, (unsigned long)ch);
if (rc != 0)
ctcm_ccw_check_rc(ch, rc,
"HaltIO in chx_setuperr");
}
return;
}
CTCM_DBF_TEXT_(ERROR, CTC_DBF_CRIT,
"%s(%s) : %s error during %s channel setup state=%s\n",
CTCM_FUNTAIL, dev->name, ctc_ch_event_names[event],
(CHANNEL_DIRECTION(ch->flags) == CTCM_READ) ? "RX" : "TX",
fsm_getstate_str(fi));
if (CHANNEL_DIRECTION(ch->flags) == CTCM_READ) {
fsm_newstate(fi, CTC_STATE_RXERR);
fsm_event(priv->fsm, DEV_EVENT_RXDOWN, dev);
} else {
fsm_newstate(fi, CTC_STATE_TXERR);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
}
}
static void ctcm_chx_restart(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
unsigned long saveflags = 0;
int oldstate;
int rc;
CTCM_DBF_TEXT_(TRACE, CTC_DBF_NOTICE,
"%s: %s[%d] of %s\n",
CTCM_FUNTAIL, ch->id, event, dev->name);
fsm_deltimer(&ch->timer);
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, ch);
oldstate = fsm_getstate(fi);
fsm_newstate(fi, CTC_STATE_STARTWAIT);
if (event == CTC_EVENT_TIMER)
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
rc = ccw_device_halt(ch->cdev, (unsigned long)ch);
if (event == CTC_EVENT_TIMER)
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0) {
if (rc != -EBUSY) {
fsm_deltimer(&ch->timer);
fsm_newstate(fi, oldstate);
}
ctcm_ccw_check_rc(ch, rc, "HaltIO in ctcm_chx_restart");
}
}
static void ctcm_chx_rxiniterr(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
if (event == CTC_EVENT_TIMER) {
if (!IS_MPCDEV(dev))
fsm_deltimer(&ch->timer);
if (ch->retry++ < 3)
ctcm_chx_restart(fi, event, arg);
else {
fsm_newstate(fi, CTC_STATE_RXERR);
fsm_event(priv->fsm, DEV_EVENT_RXDOWN, dev);
}
} else {
CTCM_DBF_TEXT_(ERROR, CTC_DBF_ERROR,
"%s(%s): %s in %s", CTCM_FUNTAIL, ch->id,
ctc_ch_event_names[event], fsm_getstate_str(fi));
dev_warn(&dev->dev,
"Initialization failed with RX/TX init handshake "
"error %s\n", ctc_ch_event_names[event]);
}
}
static void ctcm_chx_rxinitfail(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
CTCM_DBF_TEXT_(ERROR, CTC_DBF_ERROR,
"%s(%s): RX %s busy, init. fail",
CTCM_FUNTAIL, dev->name, ch->id);
fsm_newstate(fi, CTC_STATE_RXERR);
fsm_event(priv->fsm, DEV_EVENT_RXDOWN, dev);
}
static void ctcm_chx_rxdisc(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct channel *ch2;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
CTCM_DBF_TEXT_(TRACE, CTC_DBF_NOTICE,
"%s: %s: remote disconnect - re-init ...",
CTCM_FUNTAIL, dev->name);
fsm_deltimer(&ch->timer);
fsm_event(priv->fsm, DEV_EVENT_RXDOWN, dev);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
fsm_newstate(fi, CTC_STATE_DTERM);
ch2 = priv->channel[CTCM_WRITE];
fsm_newstate(ch2->fsm, CTC_STATE_DTERM);
ccw_device_halt(ch->cdev, (unsigned long)ch);
ccw_device_halt(ch2->cdev, (unsigned long)ch2);
}
static void ctcm_chx_txiniterr(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
if (event == CTC_EVENT_TIMER) {
fsm_deltimer(&ch->timer);
if (ch->retry++ < 3)
ctcm_chx_restart(fi, event, arg);
else {
fsm_newstate(fi, CTC_STATE_TXERR);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
}
} else {
CTCM_DBF_TEXT_(ERROR, CTC_DBF_ERROR,
"%s(%s): %s in %s", CTCM_FUNTAIL, ch->id,
ctc_ch_event_names[event], fsm_getstate_str(fi));
dev_warn(&dev->dev,
"Initialization failed with RX/TX init handshake "
"error %s\n", ctc_ch_event_names[event]);
}
}
static void ctcm_chx_txretry(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct sk_buff *skb;
CTCM_PR_DEBUG("Enter: %s: cp=%i ch=0x%p id=%s\n",
__func__, smp_processor_id(), ch, ch->id);
fsm_deltimer(&ch->timer);
if (ch->retry++ > 3) {
struct mpc_group *gptr = priv->mpcg;
CTCM_DBF_TEXT_(TRACE, CTC_DBF_INFO,
"%s: %s: retries exceeded",
CTCM_FUNTAIL, ch->id);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
if (!(gptr && (fsm_getstate(gptr->fsm) != MPCG_STATE_READY)))
ctcm_chx_restart(fi, event, arg);
goto done;
}
CTCM_DBF_TEXT_(TRACE, CTC_DBF_DEBUG,
"%s : %s: retry %d",
CTCM_FUNTAIL, ch->id, ch->retry);
skb = skb_peek(&ch->io_queue);
if (skb) {
int rc = 0;
unsigned long saveflags = 0;
clear_normalized_cda(&ch->ccw[4]);
ch->ccw[4].count = skb->len;
if (set_normalized_cda(&ch->ccw[4], skb->data)) {
CTCM_DBF_TEXT_(TRACE, CTC_DBF_INFO,
"%s: %s: IDAL alloc failed",
CTCM_FUNTAIL, ch->id);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
ctcm_chx_restart(fi, event, arg);
goto done;
}
fsm_addtimer(&ch->timer, 1000, CTC_EVENT_TIMER, ch);
if (event == CTC_EVENT_TIMER)
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
if (do_debug_ccw)
ctcmpc_dumpit((char *)&ch->ccw[3],
sizeof(struct ccw1) * 3);
rc = ccw_device_start(ch->cdev, &ch->ccw[3],
(unsigned long)ch, 0xff, 0);
if (event == CTC_EVENT_TIMER)
spin_unlock_irqrestore(get_ccwdev_lock(ch->cdev),
saveflags);
if (rc != 0) {
fsm_deltimer(&ch->timer);
ctcm_ccw_check_rc(ch, rc, "TX in chx_txretry");
ctcm_purge_skb_queue(&ch->io_queue);
}
}
done:
return;
}
static void ctcm_chx_iofatal(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
int rd = CHANNEL_DIRECTION(ch->flags);
fsm_deltimer(&ch->timer);
CTCM_DBF_TEXT_(ERROR, CTC_DBF_ERROR,
"%s: %s: %s unrecoverable channel error",
CTCM_FUNTAIL, ch->id, rd == CTCM_READ ? "RX" : "TX");
if (IS_MPC(ch)) {
priv->stats.tx_dropped++;
priv->stats.tx_errors++;
}
if (rd == CTCM_READ) {
fsm_newstate(fi, CTC_STATE_RXERR);
fsm_event(priv->fsm, DEV_EVENT_RXDOWN, dev);
} else {
fsm_newstate(fi, CTC_STATE_TXERR);
fsm_event(priv->fsm, DEV_EVENT_TXDOWN, dev);
}
}
static void ctcmpc_chx_txdone(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct sk_buff *skb;
int first = 1;
int i;
__u32 data_space;
unsigned long duration;
struct sk_buff *peekskb;
int rc;
struct th_header *header;
struct pdu *p_header;
unsigned long done_stamp = jiffies;
CTCM_PR_DEBUG("Enter %s: %s cp:%i\n",
__func__, dev->name, smp_processor_id());
duration = done_stamp - ch->prof.send_stamp;
if (duration > ch->prof.tx_time)
ch->prof.tx_time = duration;
if (ch->irb->scsw.cmd.count != 0)
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_DEBUG,
"%s(%s): TX not complete, remaining %d bytes",
CTCM_FUNTAIL, dev->name, ch->irb->scsw.cmd.count);
fsm_deltimer(&ch->timer);
while ((skb = skb_dequeue(&ch->io_queue))) {
priv->stats.tx_packets++;
priv->stats.tx_bytes += skb->len - TH_HEADER_LENGTH;
if (first) {
priv->stats.tx_bytes += 2;
first = 0;
}
atomic_dec(&skb->users);
dev_kfree_skb_irq(skb);
}
spin_lock(&ch->collect_lock);
clear_normalized_cda(&ch->ccw[4]);
if ((ch->collect_len <= 0) || (grp->in_sweep != 0)) {
spin_unlock(&ch->collect_lock);
fsm_newstate(fi, CTC_STATE_TXIDLE);
goto done;
}
if (ctcm_checkalloc_buffer(ch)) {
spin_unlock(&ch->collect_lock);
goto done;
}
ch->trans_skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(ch->trans_skb);
ch->trans_skb->len = 0;
if (ch->prof.maxmulti < (ch->collect_len + TH_HEADER_LENGTH))
ch->prof.maxmulti = ch->collect_len + TH_HEADER_LENGTH;
if (ch->prof.maxcqueue < skb_queue_len(&ch->collect_queue))
ch->prof.maxcqueue = skb_queue_len(&ch->collect_queue);
i = 0;
p_header = NULL;
data_space = grp->group_max_buflen - TH_HEADER_LENGTH;
CTCM_PR_DBGDATA("%s: building trans_skb from collect_q"
" data_space:%04x\n",
__func__, data_space);
while ((skb = skb_dequeue(&ch->collect_queue))) {
memcpy(skb_put(ch->trans_skb, skb->len), skb->data, skb->len);
p_header = (struct pdu *)
(skb_tail_pointer(ch->trans_skb) - skb->len);
p_header->pdu_flag = 0x00;
if (be16_to_cpu(skb->protocol) == ETH_P_SNAP)
p_header->pdu_flag |= 0x60;
else
p_header->pdu_flag |= 0x20;
CTCM_PR_DBGDATA("%s: trans_skb len:%04x \n",
__func__, ch->trans_skb->len);
CTCM_PR_DBGDATA("%s: pdu header and data for up"
" to 32 bytes sent to vtam\n", __func__);
CTCM_D3_DUMP((char *)p_header, min_t(int, skb->len, 32));
ch->collect_len -= skb->len;
data_space -= skb->len;
priv->stats.tx_packets++;
priv->stats.tx_bytes += skb->len;
atomic_dec(&skb->users);
dev_kfree_skb_any(skb);
peekskb = skb_peek(&ch->collect_queue);
if (peekskb->len > data_space)
break;
i++;
}
if (p_header)
p_header->pdu_flag |= PDU_LAST;
header = kzalloc(TH_HEADER_LENGTH, gfp_type());
if (!header) {
spin_unlock(&ch->collect_lock);
fsm_event(priv->mpcg->fsm, MPCG_EVENT_INOP, dev);
goto done;
}
header->th_ch_flag = TH_HAS_PDU;
ch->th_seq_num++;
header->th_seq_num = ch->th_seq_num;
CTCM_PR_DBGDATA("%s: ToVTAM_th_seq= %08x\n" ,
__func__, ch->th_seq_num);
memcpy(skb_push(ch->trans_skb, TH_HEADER_LENGTH), header,
TH_HEADER_LENGTH);
kfree(header);
CTCM_PR_DBGDATA("%s: trans_skb len:%04x \n",
__func__, ch->trans_skb->len);
CTCM_PR_DBGDATA("%s: up-to-50 bytes of trans_skb "
"data to vtam from collect_q\n", __func__);
CTCM_D3_DUMP((char *)ch->trans_skb->data,
min_t(int, ch->trans_skb->len, 50));
spin_unlock(&ch->collect_lock);
clear_normalized_cda(&ch->ccw[1]);
CTCM_PR_DBGDATA("ccwcda=0x%p data=0x%p\n",
(void *)(unsigned long)ch->ccw[1].cda,
ch->trans_skb->data);
ch->ccw[1].count = ch->max_bufsize;
if (set_normalized_cda(&ch->ccw[1], ch->trans_skb->data)) {
dev_kfree_skb_any(ch->trans_skb);
ch->trans_skb = NULL;
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_ERROR,
"%s: %s: IDAL alloc failed",
CTCM_FUNTAIL, ch->id);
fsm_event(priv->mpcg->fsm, MPCG_EVENT_INOP, dev);
return;
}
CTCM_PR_DBGDATA("ccwcda=0x%p data=0x%p\n",
(void *)(unsigned long)ch->ccw[1].cda,
ch->trans_skb->data);
ch->ccw[1].count = ch->trans_skb->len;
fsm_addtimer(&ch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, ch);
ch->prof.send_stamp = jiffies;
if (do_debug_ccw)
ctcmpc_dumpit((char *)&ch->ccw[0], sizeof(struct ccw1) * 3);
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
ch->prof.doios_multi++;
if (rc != 0) {
priv->stats.tx_dropped += i;
priv->stats.tx_errors += i;
fsm_deltimer(&ch->timer);
ctcm_ccw_check_rc(ch, rc, "chained TX");
}
done:
ctcm_clear_busy(dev);
return;
}
static void ctcmpc_chx_rx(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct sk_buff *skb = ch->trans_skb;
struct sk_buff *new_skb;
unsigned long saveflags = 0;
int len = ch->max_bufsize - ch->irb->scsw.cmd.count;
CTCM_PR_DEBUG("%s: %s: cp:%i %s maxbuf : %04x, len: %04x\n",
CTCM_FUNTAIL, dev->name, smp_processor_id(),
ch->id, ch->max_bufsize, len);
fsm_deltimer(&ch->timer);
if (skb == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): TRANS_SKB = NULL",
CTCM_FUNTAIL, dev->name);
goto again;
}
if (len < TH_HEADER_LENGTH) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): packet length %d to short",
CTCM_FUNTAIL, dev->name, len);
priv->stats.rx_dropped++;
priv->stats.rx_length_errors++;
} else {
__u32 block_len = len;
len = TH_HEADER_LENGTH + XID2_LENGTH + 4;
new_skb = __dev_alloc_skb(ch->max_bufsize, GFP_ATOMIC);
if (new_skb == NULL) {
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%d): skb allocation failed",
CTCM_FUNTAIL, dev->name);
fsm_event(priv->mpcg->fsm, MPCG_EVENT_INOP, dev);
goto again;
}
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_RESET:
case MPCG_STATE_INOP:
dev_kfree_skb_any(new_skb);
break;
case MPCG_STATE_FLOWC:
case MPCG_STATE_READY:
memcpy(skb_put(new_skb, block_len),
skb->data, block_len);
skb_queue_tail(&ch->io_queue, new_skb);
tasklet_schedule(&ch->ch_tasklet);
break;
default:
memcpy(skb_put(new_skb, len), skb->data, len);
skb_queue_tail(&ch->io_queue, new_skb);
tasklet_hi_schedule(&ch->ch_tasklet);
break;
}
}
again:
switch (fsm_getstate(grp->fsm)) {
int rc, dolock;
case MPCG_STATE_FLOWC:
case MPCG_STATE_READY:
if (ctcm_checkalloc_buffer(ch))
break;
ch->trans_skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(ch->trans_skb);
ch->trans_skb->len = 0;
ch->ccw[1].count = ch->max_bufsize;
if (do_debug_ccw)
ctcmpc_dumpit((char *)&ch->ccw[0],
sizeof(struct ccw1) * 3);
dolock = !in_irq();
if (dolock)
spin_lock_irqsave(
get_ccwdev_lock(ch->cdev), saveflags);
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
if (dolock)
spin_unlock_irqrestore(
get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0)
ctcm_ccw_check_rc(ch, rc, "normal RX");
default:
break;
}
CTCM_PR_DEBUG("Exit %s: %s, ch=0x%p, id=%s\n",
__func__, dev->name, ch, ch->id);
}
static void ctcmpc_chx_firstio(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *gptr = priv->mpcg;
CTCM_PR_DEBUG("Enter %s: id=%s, ch=0x%p\n",
__func__, ch->id, ch);
CTCM_DBF_TEXT_(MPC_TRACE, CTC_DBF_INFO,
"%s: %s: chstate:%i, grpstate:%i, prot:%i\n",
CTCM_FUNTAIL, ch->id, fsm_getstate(fi),
fsm_getstate(gptr->fsm), ch->protocol);
if (fsm_getstate(fi) == CTC_STATE_TXIDLE)
MPC_DBF_DEV_NAME(TRACE, dev, "remote side issued READ? ");
fsm_deltimer(&ch->timer);
if (ctcm_checkalloc_buffer(ch))
goto done;
switch (fsm_getstate(fi)) {
case CTC_STATE_STARTRETRY:
case CTC_STATE_SETUPWAIT:
if (CHANNEL_DIRECTION(ch->flags) == CTCM_READ) {
ctcmpc_chx_rxidle(fi, event, arg);
} else {
fsm_newstate(fi, CTC_STATE_TXIDLE);
fsm_event(priv->fsm, DEV_EVENT_TXUP, dev);
}
goto done;
default:
break;
}
fsm_newstate(fi, (CHANNEL_DIRECTION(ch->flags) == CTCM_READ)
? CTC_STATE_RXINIT : CTC_STATE_TXINIT);
done:
CTCM_PR_DEBUG("Exit %s: id=%s, ch=0x%p\n",
__func__, ch->id, ch);
return;
}
void ctcmpc_chx_rxidle(fsm_instance *fi, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
int rc;
unsigned long saveflags = 0;
fsm_deltimer(&ch->timer);
CTCM_PR_DEBUG("%s: %s: %s: cp:%i, chstate:%i grpstate:%i\n",
__func__, ch->id, dev->name, smp_processor_id(),
fsm_getstate(fi), fsm_getstate(grp->fsm));
fsm_newstate(fi, CTC_STATE_RXIDLE);
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_FLOWC:
case MPCG_STATE_READY:
if (ctcm_checkalloc_buffer(ch))
goto done;
ch->trans_skb->data = ch->trans_skb_data;
skb_reset_tail_pointer(ch->trans_skb);
ch->trans_skb->len = 0;
ch->ccw[1].count = ch->max_bufsize;
CTCM_CCW_DUMP((char *)&ch->ccw[0], sizeof(struct ccw1) * 3);
if (event == CTC_EVENT_START)
spin_lock_irqsave(get_ccwdev_lock(ch->cdev), saveflags);
rc = ccw_device_start(ch->cdev, &ch->ccw[0],
(unsigned long)ch, 0xff, 0);
if (event == CTC_EVENT_START)
spin_unlock_irqrestore(
get_ccwdev_lock(ch->cdev), saveflags);
if (rc != 0) {
fsm_newstate(fi, CTC_STATE_RXINIT);
ctcm_ccw_check_rc(ch, rc, "initial RX");
goto done;
}
break;
default:
break;
}
fsm_event(priv->fsm, DEV_EVENT_RXUP, dev);
done:
return;
}
static void ctcmpc_chx_attn(fsm_instance *fsm, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("%s(%s): %s(ch=0x%p), cp=%i, ChStat:%s, GrpStat:%s\n",
__func__, dev->name, ch->id, ch, smp_processor_id(),
fsm_getstate_str(ch->fsm), fsm_getstate_str(grp->fsm));
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_XID2INITW:
if (!ch->in_mpcgroup)
break;
if (fsm_getstate(ch->fsm) == CH_XID0_PENDING) {
fsm_deltimer(&grp->timer);
fsm_addtimer(&grp->timer,
MPC_XID_TIMEOUT_VALUE,
MPCG_EVENT_TIMER, dev);
fsm_event(grp->fsm, MPCG_EVENT_XID0DO, ch);
} else if (fsm_getstate(ch->fsm) < CH_XID7_PENDING1)
fsm_newstate(ch->fsm, CH_XID7_PENDING1);
break;
case MPCG_STATE_XID2INITX:
case MPCG_STATE_XID0IOWAIT:
case MPCG_STATE_XID0IOWAIX:
if (fsm_getstate(ch->fsm) < CH_XID7_PENDING1)
fsm_newstate(ch->fsm, CH_XID7_PENDING1);
break;
case MPCG_STATE_XID7INITW:
case MPCG_STATE_XID7INITX:
case MPCG_STATE_XID7INITI:
case MPCG_STATE_XID7INITZ:
switch (fsm_getstate(ch->fsm)) {
case CH_XID7_PENDING:
fsm_newstate(ch->fsm, CH_XID7_PENDING1);
break;
case CH_XID7_PENDING2:
fsm_newstate(ch->fsm, CH_XID7_PENDING3);
break;
}
fsm_event(grp->fsm, MPCG_EVENT_XID7DONE, dev);
break;
}
return;
}
static void ctcmpc_chx_attnbusy(fsm_instance *fsm, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
CTCM_PR_DEBUG("%s(%s): %s\n ChState:%s GrpState:%s\n",
__func__, dev->name, ch->id,
fsm_getstate_str(ch->fsm), fsm_getstate_str(grp->fsm));
fsm_deltimer(&ch->timer);
switch (fsm_getstate(grp->fsm)) {
case MPCG_STATE_XID0IOWAIT:
grp->changed_side = 1;
fsm_newstate(grp->fsm, MPCG_STATE_XID2INITW);
break;
case MPCG_STATE_XID2INITW:
if (grp->changed_side == 1) {
grp->changed_side = 2;
break;
}
if (grp->estconnfunc)
goto done;
if (fsm_getstate(ch->fsm) == CH_XID0_INPROGRESS) {
fsm_newstate(ch->fsm, CH_XID0_PENDING) ;
fsm_deltimer(&grp->timer);
goto done;
}
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
goto done;
case MPCG_STATE_XID2INITX:
if (grp->changed_side == 1) {
grp->changed_side = 2;
break;
}
case MPCG_STATE_XID0IOWAIX:
case MPCG_STATE_XID7INITW:
case MPCG_STATE_XID7INITX:
case MPCG_STATE_XID7INITI:
case MPCG_STATE_XID7INITZ:
default:
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
goto done;
}
if (grp->changed_side == 1) {
fsm_deltimer(&grp->timer);
fsm_addtimer(&grp->timer, MPC_XID_TIMEOUT_VALUE,
MPCG_EVENT_TIMER, dev);
}
if (ch->in_mpcgroup)
fsm_event(grp->fsm, MPCG_EVENT_XID0DO, ch);
else
CTCM_DBF_TEXT_(MPC_ERROR, CTC_DBF_ERROR,
"%s(%s): channel %s not added to group",
CTCM_FUNTAIL, dev->name, ch->id);
done:
return;
}
static void ctcmpc_chx_resend(fsm_instance *fsm, int event, void *arg)
{
struct channel *ch = arg;
struct net_device *dev = ch->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
fsm_event(grp->fsm, MPCG_EVENT_XID0DO, ch);
return;
}
static void ctcmpc_chx_send_sweep(fsm_instance *fsm, int event, void *arg)
{
struct channel *ach = arg;
struct net_device *dev = ach->netdev;
struct ctcm_priv *priv = dev->ml_priv;
struct mpc_group *grp = priv->mpcg;
struct channel *wch = priv->channel[CTCM_WRITE];
struct channel *rch = priv->channel[CTCM_READ];
struct sk_buff *skb;
struct th_sweep *header;
int rc = 0;
unsigned long saveflags = 0;
CTCM_PR_DEBUG("ctcmpc enter: %s(): cp=%i ch=0x%p id=%s\n",
__func__, smp_processor_id(), ach, ach->id);
if (grp->in_sweep == 0)
goto done;
CTCM_PR_DBGDATA("%s: 1: ToVTAM_th_seq= %08x\n" ,
__func__, wch->th_seq_num);
CTCM_PR_DBGDATA("%s: 1: FromVTAM_th_seq= %08x\n" ,
__func__, rch->th_seq_num);
if (fsm_getstate(wch->fsm) != CTC_STATE_TXIDLE) {
fsm_addtimer(&wch->sweep_timer,
200, CTC_EVENT_RSWEEP_TIMER, wch);
goto done;
}
skb = skb_dequeue(&wch->sweep_queue);
if (!skb)
goto done;
if (set_normalized_cda(&wch->ccw[4], skb->data)) {
grp->in_sweep = 0;
ctcm_clear_busy_do(dev);
dev_kfree_skb_any(skb);
fsm_event(grp->fsm, MPCG_EVENT_INOP, dev);
goto done;
} else {
atomic_inc(&skb->users);
skb_queue_tail(&wch->io_queue, skb);
}
wch->ccw[4].count = skb->len;
header = (struct th_sweep *)skb->data;
switch (header->th.th_ch_flag) {
case TH_SWEEP_REQ:
grp->sweep_req_pend_num--;
break;
case TH_SWEEP_RESP:
grp->sweep_rsp_pend_num--;
break;
}
header->sw.th_last_seq = wch->th_seq_num;
CTCM_CCW_DUMP((char *)&wch->ccw[3], sizeof(struct ccw1) * 3);
CTCM_PR_DBGDATA("%s: sweep packet\n", __func__);
CTCM_D3_DUMP((char *)header, TH_SWEEP_LENGTH);
fsm_addtimer(&wch->timer, CTCM_TIME_5_SEC, CTC_EVENT_TIMER, wch);
fsm_newstate(wch->fsm, CTC_STATE_TX);
spin_lock_irqsave(get_ccwdev_lock(wch->cdev), saveflags);
wch->prof.send_stamp = jiffies;
rc = ccw_device_start(wch->cdev, &wch->ccw[3],
(unsigned long) wch, 0xff, 0);
spin_unlock_irqrestore(get_ccwdev_lock(wch->cdev), saveflags);
if ((grp->sweep_req_pend_num == 0) &&
(grp->sweep_rsp_pend_num == 0)) {
grp->in_sweep = 0;
rch->th_seq_num = 0x00;
wch->th_seq_num = 0x00;
ctcm_clear_busy_do(dev);
}
CTCM_PR_DBGDATA("%s: To-/From-VTAM_th_seq = %08x/%08x\n" ,
__func__, wch->th_seq_num, rch->th_seq_num);
if (rc != 0)
ctcm_ccw_check_rc(wch, rc, "send sweep");
done:
return;
}
static void dev_action_start(fsm_instance *fi, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
int direction;
CTCMY_DBF_DEV_NAME(SETUP, dev, "");
fsm_deltimer(&priv->restart_timer);
fsm_newstate(fi, DEV_STATE_STARTWAIT_RXTX);
if (IS_MPC(priv))
priv->mpcg->channels_terminating = 0;
for (direction = CTCM_READ; direction <= CTCM_WRITE; direction++) {
struct channel *ch = priv->channel[direction];
fsm_event(ch->fsm, CTC_EVENT_START, ch);
}
}
static void dev_action_stop(fsm_instance *fi, int event, void *arg)
{
int direction;
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
CTCMY_DBF_DEV_NAME(SETUP, dev, "");
fsm_newstate(fi, DEV_STATE_STOPWAIT_RXTX);
for (direction = CTCM_READ; direction <= CTCM_WRITE; direction++) {
struct channel *ch = priv->channel[direction];
fsm_event(ch->fsm, CTC_EVENT_STOP, ch);
ch->th_seq_num = 0x00;
CTCM_PR_DEBUG("%s: CH_th_seq= %08x\n",
__func__, ch->th_seq_num);
}
if (IS_MPC(priv))
fsm_newstate(priv->mpcg->fsm, MPCG_STATE_RESET);
}
static void dev_action_restart(fsm_instance *fi, int event, void *arg)
{
int restart_timer;
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
CTCMY_DBF_DEV_NAME(TRACE, dev, "");
if (IS_MPC(priv)) {
restart_timer = CTCM_TIME_1_SEC;
} else {
restart_timer = CTCM_TIME_5_SEC;
}
dev_info(&dev->dev, "Restarting device\n");
dev_action_stop(fi, event, arg);
fsm_event(priv->fsm, DEV_EVENT_STOP, dev);
if (IS_MPC(priv))
fsm_newstate(priv->mpcg->fsm, MPCG_STATE_RESET);
fsm_addtimer(&priv->restart_timer, restart_timer,
DEV_EVENT_START, dev);
}
static void dev_action_chup(fsm_instance *fi, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
int dev_stat = fsm_getstate(fi);
CTCM_DBF_TEXT_(SETUP, CTC_DBF_NOTICE,
"%s(%s): priv = %p [%d,%d]\n ", CTCM_FUNTAIL,
dev->name, dev->ml_priv, dev_stat, event);
switch (fsm_getstate(fi)) {
case DEV_STATE_STARTWAIT_RXTX:
if (event == DEV_EVENT_RXUP)
fsm_newstate(fi, DEV_STATE_STARTWAIT_TX);
else
fsm_newstate(fi, DEV_STATE_STARTWAIT_RX);
break;
case DEV_STATE_STARTWAIT_RX:
if (event == DEV_EVENT_RXUP) {
fsm_newstate(fi, DEV_STATE_RUNNING);
dev_info(&dev->dev,
"Connected with remote side\n");
ctcm_clear_busy(dev);
}
break;
case DEV_STATE_STARTWAIT_TX:
if (event == DEV_EVENT_TXUP) {
fsm_newstate(fi, DEV_STATE_RUNNING);
dev_info(&dev->dev,
"Connected with remote side\n");
ctcm_clear_busy(dev);
}
break;
case DEV_STATE_STOPWAIT_TX:
if (event == DEV_EVENT_RXUP)
fsm_newstate(fi, DEV_STATE_STOPWAIT_RXTX);
break;
case DEV_STATE_STOPWAIT_RX:
if (event == DEV_EVENT_TXUP)
fsm_newstate(fi, DEV_STATE_STOPWAIT_RXTX);
break;
}
if (IS_MPC(priv)) {
if (event == DEV_EVENT_RXUP)
mpc_channel_action(priv->channel[CTCM_READ],
CTCM_READ, MPC_CHANNEL_ADD);
else
mpc_channel_action(priv->channel[CTCM_WRITE],
CTCM_WRITE, MPC_CHANNEL_ADD);
}
}
static void dev_action_chdown(fsm_instance *fi, int event, void *arg)
{
struct net_device *dev = arg;
struct ctcm_priv *priv = dev->ml_priv;
CTCMY_DBF_DEV_NAME(SETUP, dev, "");
switch (fsm_getstate(fi)) {
case DEV_STATE_RUNNING:
if (event == DEV_EVENT_TXDOWN)
fsm_newstate(fi, DEV_STATE_STARTWAIT_TX);
else
fsm_newstate(fi, DEV_STATE_STARTWAIT_RX);
break;
case DEV_STATE_STARTWAIT_RX:
if (event == DEV_EVENT_TXDOWN)
fsm_newstate(fi, DEV_STATE_STARTWAIT_RXTX);
break;
case DEV_STATE_STARTWAIT_TX:
if (event == DEV_EVENT_RXDOWN)
fsm_newstate(fi, DEV_STATE_STARTWAIT_RXTX);
break;
case DEV_STATE_STOPWAIT_RXTX:
if (event == DEV_EVENT_TXDOWN)
fsm_newstate(fi, DEV_STATE_STOPWAIT_RX);
else
fsm_newstate(fi, DEV_STATE_STOPWAIT_TX);
break;
case DEV_STATE_STOPWAIT_RX:
if (event == DEV_EVENT_RXDOWN)
fsm_newstate(fi, DEV_STATE_STOPPED);
break;
case DEV_STATE_STOPWAIT_TX:
if (event == DEV_EVENT_TXDOWN)
fsm_newstate(fi, DEV_STATE_STOPPED);
break;
}
if (IS_MPC(priv)) {
if (event == DEV_EVENT_RXDOWN)
mpc_channel_action(priv->channel[CTCM_READ],
CTCM_READ, MPC_CHANNEL_REMOVE);
else
mpc_channel_action(priv->channel[CTCM_WRITE],
CTCM_WRITE, MPC_CHANNEL_REMOVE);
}
}
