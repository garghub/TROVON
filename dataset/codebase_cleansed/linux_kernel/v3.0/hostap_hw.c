static u16 hfa384x_read_reg(struct net_device *dev, u16 reg)
{
return HFA384X_INW(reg);
}
static void hfa384x_read_regs(struct net_device *dev,
struct hfa384x_regs *regs)
{
regs->cmd = HFA384X_INW(HFA384X_CMD_OFF);
regs->evstat = HFA384X_INW(HFA384X_EVSTAT_OFF);
regs->offset0 = HFA384X_INW(HFA384X_OFFSET0_OFF);
regs->offset1 = HFA384X_INW(HFA384X_OFFSET1_OFF);
regs->swsupport0 = HFA384X_INW(HFA384X_SWSUPPORT0_OFF);
}
static inline void __hostap_cmd_queue_free(local_info_t *local,
struct hostap_cmd_queue *entry,
int del_req)
{
if (del_req) {
entry->del_req = 1;
if (!list_empty(&entry->list)) {
list_del_init(&entry->list);
local->cmd_queue_len--;
}
}
if (atomic_dec_and_test(&entry->usecnt) && entry->del_req)
kfree(entry);
}
static inline void hostap_cmd_queue_free(local_info_t *local,
struct hostap_cmd_queue *entry,
int del_req)
{
unsigned long flags;
spin_lock_irqsave(&local->cmdlock, flags);
__hostap_cmd_queue_free(local, entry, del_req);
spin_unlock_irqrestore(&local->cmdlock, flags);
}
static void prism2_clear_cmd_queue(local_info_t *local)
{
struct list_head *ptr, *n;
unsigned long flags;
struct hostap_cmd_queue *entry;
spin_lock_irqsave(&local->cmdlock, flags);
list_for_each_safe(ptr, n, &local->cmd_queue) {
entry = list_entry(ptr, struct hostap_cmd_queue, list);
atomic_inc(&entry->usecnt);
printk(KERN_DEBUG "%s: removed pending cmd_queue entry "
"(type=%d, cmd=0x%04x, param0=0x%04x)\n",
local->dev->name, entry->type, entry->cmd,
entry->param0);
__hostap_cmd_queue_free(local, entry, 1);
}
if (local->cmd_queue_len) {
printk(KERN_DEBUG "%s: cmd_queue_len (%d) not zero after "
"flush\n", local->dev->name, local->cmd_queue_len);
local->cmd_queue_len = 0;
}
spin_unlock_irqrestore(&local->cmdlock, flags);
}
static int hfa384x_cmd_issue(struct net_device *dev,
struct hostap_cmd_queue *entry)
{
struct hostap_interface *iface;
local_info_t *local;
int tries;
u16 reg;
unsigned long flags;
iface = netdev_priv(dev);
local = iface->local;
if (local->func->card_present && !local->func->card_present(local))
return -ENODEV;
if (entry->issued) {
printk(KERN_DEBUG "%s: driver bug - re-issuing command @%p\n",
dev->name, entry);
}
tries = HFA384X_CMD_BUSY_TIMEOUT;
while (HFA384X_INW(HFA384X_CMD_OFF) & HFA384X_CMD_BUSY && tries > 0) {
tries--;
udelay(1);
}
#ifndef final_version
if (tries != HFA384X_CMD_BUSY_TIMEOUT) {
prism2_io_debug_error(dev, 1);
printk(KERN_DEBUG "%s: hfa384x_cmd_issue: cmd reg was busy "
"for %d usec\n", dev->name,
HFA384X_CMD_BUSY_TIMEOUT - tries);
}
#endif
if (tries == 0) {
reg = HFA384X_INW(HFA384X_CMD_OFF);
prism2_io_debug_error(dev, 2);
printk(KERN_DEBUG "%s: hfa384x_cmd_issue - timeout - "
"reg=0x%04x\n", dev->name, reg);
return -ETIMEDOUT;
}
spin_lock_irqsave(&local->cmdlock, flags);
HFA384X_OUTW(entry->param0, HFA384X_PARAM0_OFF);
HFA384X_OUTW(entry->param1, HFA384X_PARAM1_OFF);
HFA384X_OUTW(entry->cmd, HFA384X_CMD_OFF);
entry->issued = 1;
spin_unlock_irqrestore(&local->cmdlock, flags);
return 0;
}
static int hfa384x_cmd(struct net_device *dev, u16 cmd, u16 param0,
u16 *param1, u16 *resp0)
{
struct hostap_interface *iface;
local_info_t *local;
int err, res, issue, issued = 0;
unsigned long flags;
struct hostap_cmd_queue *entry;
DECLARE_WAITQUEUE(wait, current);
iface = netdev_priv(dev);
local = iface->local;
if (in_interrupt()) {
printk(KERN_DEBUG "%s: hfa384x_cmd called from interrupt "
"context\n", dev->name);
return -1;
}
if (local->cmd_queue_len >= HOSTAP_CMD_QUEUE_MAX_LEN) {
printk(KERN_DEBUG "%s: hfa384x_cmd: cmd_queue full\n",
dev->name);
return -1;
}
if (signal_pending(current))
return -EINTR;
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (entry == NULL) {
printk(KERN_DEBUG "%s: hfa384x_cmd - kmalloc failed\n",
dev->name);
return -ENOMEM;
}
atomic_set(&entry->usecnt, 1);
entry->type = CMD_SLEEP;
entry->cmd = cmd;
entry->param0 = param0;
if (param1)
entry->param1 = *param1;
init_waitqueue_head(&entry->compl);
add_wait_queue(&entry->compl, &wait);
set_current_state(TASK_INTERRUPTIBLE);
spin_lock_irqsave(&local->cmdlock, flags);
issue = list_empty(&local->cmd_queue);
if (issue)
entry->issuing = 1;
list_add_tail(&entry->list, &local->cmd_queue);
local->cmd_queue_len++;
spin_unlock_irqrestore(&local->cmdlock, flags);
err = 0;
if (!issue)
goto wait_completion;
if (signal_pending(current))
err = -EINTR;
if (!err) {
if (hfa384x_cmd_issue(dev, entry))
err = -ETIMEDOUT;
else
issued = 1;
}
wait_completion:
if (!err && entry->type != CMD_COMPLETED) {
res = schedule_timeout(2 * HZ);
} else
res = -1;
if (!err && signal_pending(current))
err = -EINTR;
if (err && issued) {
udelay(300);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&entry->compl, &wait);
spin_lock_irqsave(&local->cmdlock, flags);
if (!list_empty(&entry->list)) {
printk(KERN_DEBUG "%s: hfa384x_cmd: entry still in list? "
"(entry=%p, type=%d, res=%d)\n", dev->name, entry,
entry->type, res);
list_del_init(&entry->list);
local->cmd_queue_len--;
}
spin_unlock_irqrestore(&local->cmdlock, flags);
if (err) {
printk(KERN_DEBUG "%s: hfa384x_cmd: interrupted; err=%d\n",
dev->name, err);
res = err;
goto done;
}
if (entry->type != CMD_COMPLETED) {
u16 reg = HFA384X_INW(HFA384X_EVSTAT_OFF);
printk(KERN_DEBUG "%s: hfa384x_cmd: command was not "
"completed (res=%d, entry=%p, type=%d, cmd=0x%04x, "
"param0=0x%04x, EVSTAT=%04x INTEN=%04x)\n", dev->name,
res, entry, entry->type, entry->cmd, entry->param0, reg,
HFA384X_INW(HFA384X_INTEN_OFF));
if (reg & HFA384X_EV_CMD) {
printk(KERN_WARNING "%s: interrupt delivery does not "
"seem to work\n", dev->name);
}
prism2_io_debug_error(dev, 3);
res = -ETIMEDOUT;
goto done;
}
if (resp0 != NULL)
*resp0 = entry->resp0;
#ifndef final_version
if (entry->res) {
printk(KERN_DEBUG "%s: CMD=0x%04x => res=0x%02x, "
"resp0=0x%04x\n",
dev->name, cmd, entry->res, entry->resp0);
}
#endif
res = entry->res;
done:
hostap_cmd_queue_free(local, entry, 1);
return res;
}
static int hfa384x_cmd_callback(struct net_device *dev, u16 cmd, u16 param0,
void (*callback)(struct net_device *dev,
long context, u16 resp0,
u16 status),
long context)
{
struct hostap_interface *iface;
local_info_t *local;
int issue, ret;
unsigned long flags;
struct hostap_cmd_queue *entry;
iface = netdev_priv(dev);
local = iface->local;
if (local->cmd_queue_len >= HOSTAP_CMD_QUEUE_MAX_LEN + 2) {
printk(KERN_DEBUG "%s: hfa384x_cmd: cmd_queue full\n",
dev->name);
return -1;
}
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (entry == NULL) {
printk(KERN_DEBUG "%s: hfa384x_cmd_callback - kmalloc "
"failed\n", dev->name);
return -ENOMEM;
}
atomic_set(&entry->usecnt, 1);
entry->type = CMD_CALLBACK;
entry->cmd = cmd;
entry->param0 = param0;
entry->callback = callback;
entry->context = context;
spin_lock_irqsave(&local->cmdlock, flags);
issue = list_empty(&local->cmd_queue);
if (issue)
entry->issuing = 1;
list_add_tail(&entry->list, &local->cmd_queue);
local->cmd_queue_len++;
spin_unlock_irqrestore(&local->cmdlock, flags);
if (issue && hfa384x_cmd_issue(dev, entry))
ret = -ETIMEDOUT;
else
ret = 0;
hostap_cmd_queue_free(local, entry, ret);
return ret;
}
static int __hfa384x_cmd_no_wait(struct net_device *dev, u16 cmd, u16 param0,
int io_debug_num)
{
int tries;
u16 reg;
tries = HFA384X_CMD_BUSY_TIMEOUT;
while (HFA384X_INW(HFA384X_CMD_OFF) & HFA384X_CMD_BUSY && tries > 0) {
tries--;
udelay(1);
}
if (tries == 0) {
reg = HFA384X_INW(HFA384X_CMD_OFF);
prism2_io_debug_error(dev, io_debug_num);
printk(KERN_DEBUG "%s: __hfa384x_cmd_no_wait(%d) - timeout - "
"reg=0x%04x\n", dev->name, io_debug_num, reg);
return -ETIMEDOUT;
}
HFA384X_OUTW(param0, HFA384X_PARAM0_OFF);
HFA384X_OUTW(cmd, HFA384X_CMD_OFF);
return 0;
}
static int hfa384x_cmd_wait(struct net_device *dev, u16 cmd, u16 param0)
{
int res, tries;
u16 reg;
res = __hfa384x_cmd_no_wait(dev, cmd, param0, 4);
if (res)
return res;
if ((cmd & HFA384X_CMDCODE_MASK) == HFA384X_CMDCODE_DOWNLOAD)
tries = HFA384X_DL_COMPL_TIMEOUT;
else
tries = HFA384X_CMD_COMPL_TIMEOUT;
while (!(HFA384X_INW(HFA384X_EVSTAT_OFF) & HFA384X_EV_CMD) &&
tries > 0) {
tries--;
udelay(10);
}
if (tries == 0) {
reg = HFA384X_INW(HFA384X_EVSTAT_OFF);
prism2_io_debug_error(dev, 5);
printk(KERN_DEBUG "%s: hfa384x_cmd_wait - timeout2 - "
"reg=0x%04x\n", dev->name, reg);
return -ETIMEDOUT;
}
res = (HFA384X_INW(HFA384X_STATUS_OFF) &
(BIT(14) | BIT(13) | BIT(12) | BIT(11) | BIT(10) | BIT(9) |
BIT(8))) >> 8;
#ifndef final_version
if (res) {
printk(KERN_DEBUG "%s: CMD=0x%04x => res=0x%02x\n",
dev->name, cmd, res);
}
#endif
HFA384X_OUTW(HFA384X_EV_CMD, HFA384X_EVACK_OFF);
return res;
}
static inline int hfa384x_cmd_no_wait(struct net_device *dev, u16 cmd,
u16 param0)
{
return __hfa384x_cmd_no_wait(dev, cmd, param0, 6);
}
static void prism2_cmd_ev(struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
struct hostap_cmd_queue *entry = NULL;
iface = netdev_priv(dev);
local = iface->local;
spin_lock(&local->cmdlock);
if (!list_empty(&local->cmd_queue)) {
entry = list_entry(local->cmd_queue.next,
struct hostap_cmd_queue, list);
atomic_inc(&entry->usecnt);
list_del_init(&entry->list);
local->cmd_queue_len--;
if (!entry->issued) {
printk(KERN_DEBUG "%s: Command completion event, but "
"cmd not issued\n", dev->name);
__hostap_cmd_queue_free(local, entry, 1);
entry = NULL;
}
}
spin_unlock(&local->cmdlock);
if (!entry) {
HFA384X_OUTW(HFA384X_EV_CMD, HFA384X_EVACK_OFF);
printk(KERN_DEBUG "%s: Command completion event, but no "
"pending commands\n", dev->name);
return;
}
entry->resp0 = HFA384X_INW(HFA384X_RESP0_OFF);
entry->res = (HFA384X_INW(HFA384X_STATUS_OFF) &
(BIT(14) | BIT(13) | BIT(12) | BIT(11) | BIT(10) |
BIT(9) | BIT(8))) >> 8;
HFA384X_OUTW(HFA384X_EV_CMD, HFA384X_EVACK_OFF);
if (entry->type == CMD_SLEEP) {
entry->type = CMD_COMPLETED;
wake_up_interruptible(&entry->compl);
} else if (entry->type == CMD_CALLBACK) {
if (entry->callback)
entry->callback(dev, entry->context, entry->resp0,
entry->res);
} else {
printk(KERN_DEBUG "%s: Invalid command completion type %d\n",
dev->name, entry->type);
}
hostap_cmd_queue_free(local, entry, 1);
entry = NULL;
spin_lock(&local->cmdlock);
if (!list_empty(&local->cmd_queue)) {
entry = list_entry(local->cmd_queue.next,
struct hostap_cmd_queue, list);
if (entry->issuing) {
entry = NULL;
}
if (entry)
atomic_inc(&entry->usecnt);
}
spin_unlock(&local->cmdlock);
if (entry) {
int res = hfa384x_cmd_issue(dev, entry);
spin_lock(&local->cmdlock);
__hostap_cmd_queue_free(local, entry, res);
spin_unlock(&local->cmdlock);
}
}
static int hfa384x_wait_offset(struct net_device *dev, u16 o_off)
{
int tries = HFA384X_BAP_BUSY_TIMEOUT;
int res = HFA384X_INW(o_off) & HFA384X_OFFSET_BUSY;
while (res && tries > 0) {
tries--;
udelay(1);
res = HFA384X_INW(o_off) & HFA384X_OFFSET_BUSY;
}
return res;
}
static int hfa384x_setup_bap(struct net_device *dev, u16 bap, u16 id,
int offset)
{
u16 o_off, s_off;
int ret = 0;
if (offset % 2 || bap > 1)
return -EINVAL;
if (bap == BAP1) {
o_off = HFA384X_OFFSET1_OFF;
s_off = HFA384X_SELECT1_OFF;
} else {
o_off = HFA384X_OFFSET0_OFF;
s_off = HFA384X_SELECT0_OFF;
}
if (hfa384x_wait_offset(dev, o_off)) {
prism2_io_debug_error(dev, 7);
printk(KERN_DEBUG "%s: hfa384x_setup_bap - timeout before\n",
dev->name);
ret = -ETIMEDOUT;
goto out;
}
HFA384X_OUTW(id, s_off);
HFA384X_OUTW(offset, o_off);
if (hfa384x_wait_offset(dev, o_off)) {
prism2_io_debug_error(dev, 8);
printk(KERN_DEBUG "%s: hfa384x_setup_bap - timeout after\n",
dev->name);
ret = -ETIMEDOUT;
goto out;
}
#ifndef final_version
if (HFA384X_INW(o_off) & HFA384X_OFFSET_ERR) {
prism2_io_debug_error(dev, 9);
printk(KERN_DEBUG "%s: hfa384x_setup_bap - offset error "
"(%d,0x04%x,%d); reg=0x%04x\n",
dev->name, bap, id, offset, HFA384X_INW(o_off));
ret = -EINVAL;
}
#endif
out:
return ret;
}
static int hfa384x_get_rid(struct net_device *dev, u16 rid, void *buf, int len,
int exact_len)
{
struct hostap_interface *iface;
local_info_t *local;
int res, rlen = 0;
struct hfa384x_rid_hdr rec;
iface = netdev_priv(dev);
local = iface->local;
if (local->no_pri) {
printk(KERN_DEBUG "%s: cannot get RID %04x (len=%d) - no PRI "
"f/w\n", dev->name, rid, len);
return -ENOTTY;
}
if ((local->func->card_present && !local->func->card_present(local)) ||
local->hw_downloading)
return -ENODEV;
res = mutex_lock_interruptible(&local->rid_bap_mtx);
if (res)
return res;
res = hfa384x_cmd(dev, HFA384X_CMDCODE_ACCESS, rid, NULL, NULL);
if (res) {
printk(KERN_DEBUG "%s: hfa384x_get_rid: CMDCODE_ACCESS failed "
"(res=%d, rid=%04x, len=%d)\n",
dev->name, res, rid, len);
mutex_unlock(&local->rid_bap_mtx);
return res;
}
spin_lock_bh(&local->baplock);
res = hfa384x_setup_bap(dev, BAP0, rid, 0);
if (!res)
res = hfa384x_from_bap(dev, BAP0, &rec, sizeof(rec));
if (le16_to_cpu(rec.len) == 0) {
res = -ENODATA;
}
rlen = (le16_to_cpu(rec.len) - 1) * 2;
if (!res && exact_len && rlen != len) {
printk(KERN_DEBUG "%s: hfa384x_get_rid - RID len mismatch: "
"rid=0x%04x, len=%d (expected %d)\n",
dev->name, rid, rlen, len);
res = -ENODATA;
}
if (!res)
res = hfa384x_from_bap(dev, BAP0, buf, len);
spin_unlock_bh(&local->baplock);
mutex_unlock(&local->rid_bap_mtx);
if (res) {
if (res != -ENODATA)
printk(KERN_DEBUG "%s: hfa384x_get_rid (rid=%04x, "
"len=%d) - failed - res=%d\n", dev->name, rid,
len, res);
if (res == -ETIMEDOUT)
prism2_hw_reset(dev);
return res;
}
return rlen;
}
static int hfa384x_set_rid(struct net_device *dev, u16 rid, void *buf, int len)
{
struct hostap_interface *iface;
local_info_t *local;
struct hfa384x_rid_hdr rec;
int res;
iface = netdev_priv(dev);
local = iface->local;
if (local->no_pri) {
printk(KERN_DEBUG "%s: cannot set RID %04x (len=%d) - no PRI "
"f/w\n", dev->name, rid, len);
return -ENOTTY;
}
if ((local->func->card_present && !local->func->card_present(local)) ||
local->hw_downloading)
return -ENODEV;
rec.rid = cpu_to_le16(rid);
rec.len = cpu_to_le16(len / 2 + len % 2 + 1);
res = mutex_lock_interruptible(&local->rid_bap_mtx);
if (res)
return res;
spin_lock_bh(&local->baplock);
res = hfa384x_setup_bap(dev, BAP0, rid, 0);
if (!res)
res = hfa384x_to_bap(dev, BAP0, &rec, sizeof(rec));
if (!res)
res = hfa384x_to_bap(dev, BAP0, buf, len);
spin_unlock_bh(&local->baplock);
if (res) {
printk(KERN_DEBUG "%s: hfa384x_set_rid (rid=%04x, len=%d) - "
"failed - res=%d\n", dev->name, rid, len, res);
mutex_unlock(&local->rid_bap_mtx);
return res;
}
res = hfa384x_cmd(dev, HFA384X_CMDCODE_ACCESS_WRITE, rid, NULL, NULL);
mutex_unlock(&local->rid_bap_mtx);
if (res) {
printk(KERN_DEBUG "%s: hfa384x_set_rid: CMDCODE_ACCESS_WRITE "
"failed (res=%d, rid=%04x, len=%d)\n",
dev->name, res, rid, len);
if (res == -ETIMEDOUT)
prism2_hw_reset(dev);
}
return res;
}
static void hfa384x_disable_interrupts(struct net_device *dev)
{
HFA384X_OUTW(0, HFA384X_INTEN_OFF);
HFA384X_OUTW(0xffff, HFA384X_EVACK_OFF);
}
static void hfa384x_enable_interrupts(struct net_device *dev)
{
HFA384X_OUTW(0xffff, HFA384X_EVACK_OFF);
HFA384X_OUTW(HFA384X_EVENT_MASK, HFA384X_INTEN_OFF);
}
static void hfa384x_events_no_bap0(struct net_device *dev)
{
HFA384X_OUTW(HFA384X_EVENT_MASK & ~HFA384X_BAP0_EVENTS,
HFA384X_INTEN_OFF);
}
static void hfa384x_events_all(struct net_device *dev)
{
HFA384X_OUTW(HFA384X_EVENT_MASK, HFA384X_INTEN_OFF);
}
static void hfa384x_events_only_cmd(struct net_device *dev)
{
HFA384X_OUTW(HFA384X_EV_CMD, HFA384X_INTEN_OFF);
}
static u16 hfa384x_allocate_fid(struct net_device *dev, int len)
{
u16 fid;
unsigned long delay;
if (hfa384x_cmd_wait(dev, HFA384X_CMDCODE_ALLOC, len)) {
printk(KERN_DEBUG "%s: cannot allocate fid, len=%d\n",
dev->name, len);
return 0xffff;
}
delay = jiffies + HFA384X_ALLOC_COMPL_TIMEOUT;
while (!(HFA384X_INW(HFA384X_EVSTAT_OFF) & HFA384X_EV_ALLOC) &&
time_before(jiffies, delay))
yield();
if (!(HFA384X_INW(HFA384X_EVSTAT_OFF) & HFA384X_EV_ALLOC)) {
printk("%s: fid allocate, len=%d - timeout\n", dev->name, len);
return 0xffff;
}
fid = HFA384X_INW(HFA384X_ALLOCFID_OFF);
HFA384X_OUTW(HFA384X_EV_ALLOC, HFA384X_EVACK_OFF);
return fid;
}
static int prism2_reset_port(struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
int res;
iface = netdev_priv(dev);
local = iface->local;
if (!local->dev_enabled)
return 0;
res = hfa384x_cmd(dev, HFA384X_CMDCODE_DISABLE, 0,
NULL, NULL);
if (res)
printk(KERN_DEBUG "%s: reset port failed to disable port\n",
dev->name);
else {
res = hfa384x_cmd(dev, HFA384X_CMDCODE_ENABLE, 0,
NULL, NULL);
if (res)
printk(KERN_DEBUG "%s: reset port failed to enable "
"port\n", dev->name);
}
if (local->fragm_threshold != 2346 &&
hostap_set_word(dev, HFA384X_RID_FRAGMENTATIONTHRESHOLD,
local->fragm_threshold)) {
printk(KERN_DEBUG "%s: failed to restore fragmentation "
"threshold (%d) after Port0 enable\n",
dev->name, local->fragm_threshold);
}
(void) hostap_set_antsel(local);
return res;
}
static int prism2_get_version_info(struct net_device *dev, u16 rid,
const char *txt)
{
struct hfa384x_comp_ident comp;
struct hostap_interface *iface;
local_info_t *local;
iface = netdev_priv(dev);
local = iface->local;
if (local->no_pri) {
return -1;
}
if (hfa384x_get_rid(dev, rid, &comp, sizeof(comp), 1) < 0) {
printk(KERN_DEBUG "Could not get RID for component %s\n", txt);
return -1;
}
printk(KERN_INFO "%s: %s: id=0x%02x v%d.%d.%d\n", dev->name, txt,
__le16_to_cpu(comp.id), __le16_to_cpu(comp.major),
__le16_to_cpu(comp.minor), __le16_to_cpu(comp.variant));
return 0;
}
static int prism2_setup_rids(struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
__le16 tmp;
int ret = 0;
iface = netdev_priv(dev);
local = iface->local;
hostap_set_word(dev, HFA384X_RID_TICKTIME, 2000);
if (!local->fw_ap) {
u16 tmp1 = hostap_get_porttype(local);
ret = hostap_set_word(dev, HFA384X_RID_CNFPORTTYPE, tmp1);
if (ret) {
printk("%s: Port type setting to %d failed\n",
dev->name, tmp1);
goto fail;
}
}
if (local->iw_mode != IW_MODE_MASTER || local->essid[0] != '\0') {
ret = hostap_set_string(dev, HFA384X_RID_CNFOWNSSID,
local->essid);
if (ret) {
printk("%s: AP own SSID setting failed\n", dev->name);
goto fail;
}
}
ret = hostap_set_word(dev, HFA384X_RID_CNFMAXDATALEN,
PRISM2_DATA_MAXLEN);
if (ret) {
printk("%s: MAC data length setting to %d failed\n",
dev->name, PRISM2_DATA_MAXLEN);
goto fail;
}
if (hfa384x_get_rid(dev, HFA384X_RID_CHANNELLIST, &tmp, 2, 1) < 0) {
printk("%s: Channel list read failed\n", dev->name);
ret = -EINVAL;
goto fail;
}
local->channel_mask = le16_to_cpu(tmp);
if (local->channel < 1 || local->channel > 14 ||
!(local->channel_mask & (1 << (local->channel - 1)))) {
printk(KERN_WARNING "%s: Channel setting out of range "
"(%d)!\n", dev->name, local->channel);
ret = -EBUSY;
goto fail;
}
ret = hostap_set_word(dev, HFA384X_RID_CNFOWNCHANNEL, local->channel);
if (ret) {
printk("%s: Channel setting to %d failed\n",
dev->name, local->channel);
goto fail;
}
ret = hostap_set_word(dev, HFA384X_RID_CNFBEACONINT,
local->beacon_int);
if (ret) {
printk("%s: Beacon interval setting to %d failed\n",
dev->name, local->beacon_int);
if (ret == -ETIMEDOUT)
goto fail;
}
ret = hostap_set_word(dev, HFA384X_RID_CNFOWNDTIMPERIOD,
local->dtim_period);
if (ret) {
printk("%s: DTIM period setting to %d failed\n",
dev->name, local->dtim_period);
if (ret == -ETIMEDOUT)
goto fail;
}
ret = hostap_set_word(dev, HFA384X_RID_PROMISCUOUSMODE,
local->is_promisc);
if (ret)
printk(KERN_INFO "%s: Setting promiscuous mode (%d) failed\n",
dev->name, local->is_promisc);
if (!local->fw_ap) {
ret = hostap_set_string(dev, HFA384X_RID_CNFDESIREDSSID,
local->essid);
if (ret) {
printk("%s: Desired SSID setting failed\n", dev->name);
goto fail;
}
}
if (local->tx_rate_control == 0) {
local->tx_rate_control =
HFA384X_RATES_1MBPS |
HFA384X_RATES_2MBPS |
HFA384X_RATES_5MBPS |
HFA384X_RATES_11MBPS;
}
if (local->basic_rates == 0)
local->basic_rates = HFA384X_RATES_1MBPS | HFA384X_RATES_2MBPS;
if (!local->fw_ap) {
ret = hostap_set_word(dev, HFA384X_RID_TXRATECONTROL,
local->tx_rate_control);
if (ret) {
printk("%s: TXRateControl setting to %d failed\n",
dev->name, local->tx_rate_control);
goto fail;
}
ret = hostap_set_word(dev, HFA384X_RID_CNFSUPPORTEDRATES,
local->tx_rate_control);
if (ret) {
printk("%s: cnfSupportedRates setting to %d failed\n",
dev->name, local->tx_rate_control);
}
ret = hostap_set_word(dev, HFA384X_RID_CNFBASICRATES,
local->basic_rates);
if (ret) {
printk("%s: cnfBasicRates setting to %d failed\n",
dev->name, local->basic_rates);
}
ret = hostap_set_word(dev, HFA384X_RID_CREATEIBSS, 1);
if (ret) {
printk("%s: Create IBSS setting to 1 failed\n",
dev->name);
}
}
if (local->name_set)
(void) hostap_set_string(dev, HFA384X_RID_CNFOWNNAME,
local->name);
if (hostap_set_encryption(local)) {
printk(KERN_INFO "%s: could not configure encryption\n",
dev->name);
}
(void) hostap_set_antsel(local);
if (hostap_set_roaming(local)) {
printk(KERN_INFO "%s: could not set host roaming\n",
dev->name);
}
if (local->sta_fw_ver >= PRISM2_FW_VER(1,6,3) &&
hostap_set_word(dev, HFA384X_RID_CNFENHSECURITY, local->enh_sec))
printk(KERN_INFO "%s: cnfEnhSecurity setting to 0x%x failed\n",
dev->name, local->enh_sec);
if (local->sta_fw_ver >= PRISM2_FW_VER(0,8,2)) {
if (hostap_set_word(dev, HFA384X_RID_CNFTHIRTY2TALLY, 1)) {
printk(KERN_INFO "%s: cnfThirty2Tally setting "
"failed\n", dev->name);
local->tallies32 = 0;
} else
local->tallies32 = 1;
} else
local->tallies32 = 0;
hostap_set_auth_algs(local);
if (hostap_set_word(dev, HFA384X_RID_FRAGMENTATIONTHRESHOLD,
local->fragm_threshold)) {
printk(KERN_INFO "%s: setting FragmentationThreshold to %d "
"failed\n", dev->name, local->fragm_threshold);
}
if (hostap_set_word(dev, HFA384X_RID_RTSTHRESHOLD,
local->rts_threshold)) {
printk(KERN_INFO "%s: setting RTSThreshold to %d failed\n",
dev->name, local->rts_threshold);
}
if (local->manual_retry_count >= 0 &&
hostap_set_word(dev, HFA384X_RID_CNFALTRETRYCOUNT,
local->manual_retry_count)) {
printk(KERN_INFO "%s: setting cnfAltRetryCount to %d failed\n",
dev->name, local->manual_retry_count);
}
if (local->sta_fw_ver >= PRISM2_FW_VER(1,3,1) &&
hfa384x_get_rid(dev, HFA384X_RID_CNFDBMADJUST, &tmp, 2, 1) == 2) {
local->rssi_to_dBm = le16_to_cpu(tmp);
}
if (local->sta_fw_ver >= PRISM2_FW_VER(1,7,0) && local->wpa &&
hostap_set_word(dev, HFA384X_RID_SSNHANDLINGMODE, 1)) {
printk(KERN_INFO "%s: setting ssnHandlingMode to 1 failed\n",
dev->name);
}
if (local->sta_fw_ver >= PRISM2_FW_VER(1,7,0) && local->generic_elem &&
hfa384x_set_rid(dev, HFA384X_RID_GENERICELEMENT,
local->generic_elem, local->generic_elem_len)) {
printk(KERN_INFO "%s: setting genericElement failed\n",
dev->name);
}
fail:
return ret;
}
static int prism2_hw_init(struct net_device *dev, int initial)
{
struct hostap_interface *iface;
local_info_t *local;
int ret, first = 1;
unsigned long start, delay;
PDEBUG(DEBUG_FLOW, "prism2_hw_init()\n");
iface = netdev_priv(dev);
local = iface->local;
clear_bit(HOSTAP_BITS_TRANSMIT, &local->bits);
init:
ret = hfa384x_cmd_no_wait(dev, HFA384X_CMDCODE_INIT, 0);
if (ret) {
printk(KERN_INFO "%s: first command failed - assuming card "
"does not have primary firmware\n", dev_info);
}
if (first && (HFA384X_INW(HFA384X_EVSTAT_OFF) & HFA384X_EV_CMD)) {
HFA384X_OUTW(HFA384X_EV_CMD, HFA384X_EVACK_OFF);
printk(KERN_DEBUG "%s: init command completed too quickly - "
"retrying\n", dev->name);
first = 0;
goto init;
}
start = jiffies;
delay = jiffies + HFA384X_INIT_TIMEOUT;
while (!(HFA384X_INW(HFA384X_EVSTAT_OFF) & HFA384X_EV_CMD) &&
time_before(jiffies, delay))
yield();
if (!(HFA384X_INW(HFA384X_EVSTAT_OFF) & HFA384X_EV_CMD)) {
printk(KERN_DEBUG "%s: assuming no Primary image in "
"flash - card initialization not completed\n",
dev_info);
local->no_pri = 1;
#ifdef PRISM2_DOWNLOAD_SUPPORT
if (local->sram_type == -1)
local->sram_type = prism2_get_ram_size(local);
#endif
return 1;
}
local->no_pri = 0;
printk(KERN_DEBUG "prism2_hw_init: initialized in %lu ms\n",
(jiffies - start) * 1000 / HZ);
HFA384X_OUTW(HFA384X_EV_CMD, HFA384X_EVACK_OFF);
return 0;
}
static int prism2_hw_init2(struct net_device *dev, int initial)
{
struct hostap_interface *iface;
local_info_t *local;
int i;
iface = netdev_priv(dev);
local = iface->local;
#ifdef PRISM2_DOWNLOAD_SUPPORT
kfree(local->pda);
if (local->no_pri)
local->pda = NULL;
else
local->pda = prism2_read_pda(dev);
#endif
hfa384x_disable_interrupts(dev);
#ifndef final_version
HFA384X_OUTW(HFA384X_MAGIC, HFA384X_SWSUPPORT0_OFF);
if (HFA384X_INW(HFA384X_SWSUPPORT0_OFF) != HFA384X_MAGIC) {
printk("SWSUPPORT0 write/read failed: %04X != %04X\n",
HFA384X_INW(HFA384X_SWSUPPORT0_OFF), HFA384X_MAGIC);
goto failed;
}
#endif
if (initial || local->pri_only) {
hfa384x_events_only_cmd(dev);
if (prism2_get_version_info(dev, HFA384X_RID_NICID, "NIC") ||
prism2_get_version_info(dev, HFA384X_RID_PRIID, "PRI")) {
hfa384x_disable_interrupts(dev);
goto failed;
}
if (prism2_get_version_info(dev, HFA384X_RID_STAID, "STA")) {
printk(KERN_DEBUG "%s: Failed to read STA f/w version "
"- only Primary f/w present\n", dev->name);
local->pri_only = 1;
return 0;
}
local->pri_only = 0;
hfa384x_disable_interrupts(dev);
}
local->txfid_len = PRISM2_TXFID_LEN;
for (i = 0; i < PRISM2_TXFID_COUNT; i++) {
local->txfid[i] = hfa384x_allocate_fid(dev, local->txfid_len);
if (local->txfid[i] == 0xffff && local->txfid_len > 1600) {
local->txfid[i] = hfa384x_allocate_fid(dev, 1600);
if (local->txfid[i] != 0xffff) {
printk(KERN_DEBUG "%s: Using shorter TX FID "
"(1600 bytes)\n", dev->name);
local->txfid_len = 1600;
}
}
if (local->txfid[i] == 0xffff)
goto failed;
local->intransmitfid[i] = PRISM2_TXFID_EMPTY;
}
hfa384x_events_only_cmd(dev);
if (initial) {
struct list_head *ptr;
prism2_check_sta_fw_version(local);
if (hfa384x_get_rid(dev, HFA384X_RID_CNFOWNMACADDR,
dev->dev_addr, 6, 1) < 0) {
printk("%s: could not get own MAC address\n",
dev->name);
}
list_for_each(ptr, &local->hostap_interfaces) {
iface = list_entry(ptr, struct hostap_interface, list);
memcpy(iface->dev->dev_addr, dev->dev_addr, ETH_ALEN);
}
} else if (local->fw_ap)
prism2_check_sta_fw_version(local);
prism2_setup_rids(dev);
return 0;
failed:
if (!local->no_pri)
printk(KERN_WARNING "%s: Initialization failed\n", dev_info);
return 1;
}
static int prism2_hw_enable(struct net_device *dev, int initial)
{
struct hostap_interface *iface;
local_info_t *local;
int was_resetting;
iface = netdev_priv(dev);
local = iface->local;
was_resetting = local->hw_resetting;
if (hfa384x_cmd(dev, HFA384X_CMDCODE_ENABLE, 0, NULL, NULL)) {
printk("%s: MAC port 0 enabling failed\n", dev->name);
return 1;
}
local->hw_ready = 1;
local->hw_reset_tries = 0;
local->hw_resetting = 0;
hfa384x_enable_interrupts(dev);
if (initial && prism2_reset_port(dev)) {
printk("%s: MAC port 0 reseting failed\n", dev->name);
return 1;
}
if (was_resetting && netif_queue_stopped(dev)) {
netif_wake_queue(dev);
}
return 0;
}
static int prism2_hw_config(struct net_device *dev, int initial)
{
struct hostap_interface *iface;
local_info_t *local;
iface = netdev_priv(dev);
local = iface->local;
if (local->hw_downloading)
return 1;
if (prism2_hw_init(dev, initial)) {
return local->no_pri ? 0 : 1;
}
if (prism2_hw_init2(dev, initial))
return 1;
if (!local->pri_only &&
(initial == 0 || (initial == 2 && local->num_dev_open > 0))) {
if (!local->dev_enabled)
prism2_callback(local, PRISM2_CALLBACK_ENABLE);
local->dev_enabled = 1;
return prism2_hw_enable(dev, initial);
}
return 0;
}
static void prism2_hw_shutdown(struct net_device *dev, int no_disable)
{
struct hostap_interface *iface;
local_info_t *local;
iface = netdev_priv(dev);
local = iface->local;
hfa384x_events_only_cmd(dev);
local->hw_ready = 0;
if (local->dev_enabled)
prism2_callback(local, PRISM2_CALLBACK_DISABLE);
local->dev_enabled = 0;
if (local->func->card_present && !local->func->card_present(local)) {
printk(KERN_DEBUG "%s: card already removed or not configured "
"during shutdown\n", dev->name);
return;
}
if ((no_disable & HOSTAP_HW_NO_DISABLE) == 0 &&
hfa384x_cmd(dev, HFA384X_CMDCODE_DISABLE, 0, NULL, NULL))
printk(KERN_WARNING "%s: Shutdown failed\n", dev_info);
hfa384x_disable_interrupts(dev);
if (no_disable & HOSTAP_HW_ENABLE_CMDCOMPL)
hfa384x_events_only_cmd(dev);
else
prism2_clear_cmd_queue(local);
}
static void prism2_hw_reset(struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
#if 0
static long last_reset = 0;
if (time_before_eq(jiffies, last_reset + HZ))
return;
last_reset = jiffies;
#endif
iface = netdev_priv(dev);
local = iface->local;
if (in_interrupt()) {
printk(KERN_DEBUG "%s: driver bug - prism2_hw_reset() called "
"in interrupt context\n", dev->name);
return;
}
if (local->hw_downloading)
return;
if (local->hw_resetting) {
printk(KERN_WARNING "%s: %s: already resetting card - "
"ignoring reset request\n", dev_info, dev->name);
return;
}
local->hw_reset_tries++;
if (local->hw_reset_tries > 10) {
printk(KERN_WARNING "%s: too many reset tries, skipping\n",
dev->name);
return;
}
printk(KERN_WARNING "%s: %s: resetting card\n", dev_info, dev->name);
hfa384x_disable_interrupts(dev);
local->hw_resetting = 1;
if (local->func->cor_sreset) {
disable_irq(dev->irq);
local->func->cor_sreset(local);
enable_irq(dev->irq);
}
prism2_hw_shutdown(dev, 1);
prism2_hw_config(dev, 0);
local->hw_resetting = 0;
#ifdef PRISM2_DOWNLOAD_SUPPORT
if (local->dl_pri) {
printk(KERN_DEBUG "%s: persistent download of primary "
"firmware\n", dev->name);
if (prism2_download_genesis(local, local->dl_pri) < 0)
printk(KERN_WARNING "%s: download (PRI) failed\n",
dev->name);
}
if (local->dl_sec) {
printk(KERN_DEBUG "%s: persistent download of secondary "
"firmware\n", dev->name);
if (prism2_download_volatile(local, local->dl_sec) < 0)
printk(KERN_WARNING "%s: download (SEC) failed\n",
dev->name);
}
#endif
}
static void prism2_schedule_reset(local_info_t *local)
{
schedule_work(&local->reset_queue);
}
static void handle_reset_queue(struct work_struct *work)
{
local_info_t *local = container_of(work, local_info_t, reset_queue);
printk(KERN_DEBUG "%s: scheduled card reset\n", local->dev->name);
prism2_hw_reset(local->dev);
if (netif_queue_stopped(local->dev)) {
int i;
for (i = 0; i < PRISM2_TXFID_COUNT; i++)
if (local->intransmitfid[i] == PRISM2_TXFID_EMPTY) {
PDEBUG(DEBUG_EXTRA, "prism2_tx_timeout: "
"wake up queue\n");
netif_wake_queue(local->dev);
break;
}
}
}
static int prism2_get_txfid_idx(local_info_t *local)
{
int idx, end;
unsigned long flags;
spin_lock_irqsave(&local->txfidlock, flags);
end = idx = local->next_txfid;
do {
if (local->intransmitfid[idx] == PRISM2_TXFID_EMPTY) {
local->intransmitfid[idx] = PRISM2_TXFID_RESERVED;
spin_unlock_irqrestore(&local->txfidlock, flags);
return idx;
}
idx++;
if (idx >= PRISM2_TXFID_COUNT)
idx = 0;
} while (idx != end);
spin_unlock_irqrestore(&local->txfidlock, flags);
PDEBUG(DEBUG_EXTRA2, "prism2_get_txfid_idx: no room in txfid buf: "
"packet dropped\n");
local->dev->stats.tx_dropped++;
return -1;
}
static void prism2_transmit_cb(struct net_device *dev, long context,
u16 resp0, u16 res)
{
struct hostap_interface *iface;
local_info_t *local;
int idx = (int) context;
iface = netdev_priv(dev);
local = iface->local;
if (res) {
printk(KERN_DEBUG "%s: prism2_transmit_cb - res=0x%02x\n",
dev->name, res);
return;
}
if (idx < 0 || idx >= PRISM2_TXFID_COUNT) {
printk(KERN_DEBUG "%s: prism2_transmit_cb called with invalid "
"idx=%d\n", dev->name, idx);
return;
}
if (!test_and_clear_bit(HOSTAP_BITS_TRANSMIT, &local->bits)) {
printk(KERN_DEBUG "%s: driver bug: prism2_transmit_cb called "
"with no pending transmit\n", dev->name);
}
if (netif_queue_stopped(dev)) {
netif_wake_queue(dev);
}
spin_lock(&local->txfidlock);
local->intransmitfid[idx] = resp0;
PDEBUG(DEBUG_FID, "%s: prism2_transmit_cb: txfid[%d]=0x%04x, "
"resp0=0x%04x, transmit_txfid=0x%04x\n",
dev->name, idx, local->txfid[idx],
resp0, local->intransmitfid[local->next_txfid]);
idx++;
if (idx >= PRISM2_TXFID_COUNT)
idx = 0;
local->next_txfid = idx;
do {
if (local->intransmitfid[idx] == PRISM2_TXFID_EMPTY) {
spin_unlock(&local->txfidlock);
return;
}
idx++;
if (idx >= PRISM2_TXFID_COUNT)
idx = 0;
} while (idx != local->next_txfid);
spin_unlock(&local->txfidlock);
netif_stop_queue(dev);
}
static int prism2_transmit(struct net_device *dev, int idx)
{
struct hostap_interface *iface;
local_info_t *local;
int res;
iface = netdev_priv(dev);
local = iface->local;
if (test_and_set_bit(HOSTAP_BITS_TRANSMIT, &local->bits)) {
printk(KERN_DEBUG "%s: driver bug - prism2_transmit() called "
"when previous TX was pending\n", dev->name);
return -1;
}
netif_stop_queue(dev);
res = hfa384x_cmd_callback(
dev,
HFA384X_CMDCODE_TRANSMIT | HFA384X_CMD_TX_RECLAIM,
local->txfid[idx],
prism2_transmit_cb, (long) idx);
if (res) {
printk(KERN_DEBUG "%s: prism2_transmit: CMDCODE_TRANSMIT "
"failed (res=%d)\n", dev->name, res);
dev->stats.tx_dropped++;
netif_wake_queue(dev);
return -1;
}
dev->trans_start = jiffies;
return 0;
}
static int prism2_tx_80211(struct sk_buff *skb, struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
struct hfa384x_tx_frame txdesc;
struct hostap_skb_tx_data *meta;
int hdr_len, data_len, idx, res, ret = -1;
u16 tx_control, fc;
iface = netdev_priv(dev);
local = iface->local;
meta = (struct hostap_skb_tx_data *) skb->cb;
prism2_callback(local, PRISM2_CALLBACK_TX_START);
if ((local->func->card_present && !local->func->card_present(local)) ||
!local->hw_ready || local->hw_downloading || local->pri_only) {
if (net_ratelimit()) {
printk(KERN_DEBUG "%s: prism2_tx_80211: hw not ready -"
" skipping\n", dev->name);
}
goto fail;
}
memset(&txdesc, 0, sizeof(txdesc));
hdr_len = 24;
skb_copy_from_linear_data(skb, &txdesc.frame_control, hdr_len);
fc = le16_to_cpu(txdesc.frame_control);
if (ieee80211_is_data(txdesc.frame_control) &&
ieee80211_has_a4(txdesc.frame_control) &&
skb->len >= 30) {
skb_copy_from_linear_data_offset(skb, hdr_len, txdesc.addr4,
ETH_ALEN);
hdr_len += ETH_ALEN;
}
tx_control = local->tx_control;
if (meta->tx_cb_idx) {
tx_control |= HFA384X_TX_CTRL_TX_OK;
txdesc.sw_support = cpu_to_le32(meta->tx_cb_idx);
}
txdesc.tx_control = cpu_to_le16(tx_control);
txdesc.tx_rate = meta->rate;
data_len = skb->len - hdr_len;
txdesc.data_len = cpu_to_le16(data_len);
txdesc.len = cpu_to_be16(data_len);
idx = prism2_get_txfid_idx(local);
if (idx < 0)
goto fail;
if (local->frame_dump & PRISM2_DUMP_TX_HDR)
hostap_dump_tx_header(dev->name, &txdesc);
spin_lock(&local->baplock);
res = hfa384x_setup_bap(dev, BAP0, local->txfid[idx], 0);
if (!res)
res = hfa384x_to_bap(dev, BAP0, &txdesc, sizeof(txdesc));
if (!res)
res = hfa384x_to_bap(dev, BAP0, skb->data + hdr_len,
skb->len - hdr_len);
spin_unlock(&local->baplock);
if (!res)
res = prism2_transmit(dev, idx);
if (res) {
printk(KERN_DEBUG "%s: prism2_tx_80211 - to BAP0 failed\n",
dev->name);
local->intransmitfid[idx] = PRISM2_TXFID_EMPTY;
schedule_work(&local->reset_queue);
goto fail;
}
ret = 0;
fail:
prism2_callback(local, PRISM2_CALLBACK_TX_END);
return ret;
}
static u16 prism2_read_fid_reg(struct net_device *dev, u16 reg)
{
#ifdef EXTRA_FID_READ_TESTS
u16 val, val2, val3;
int i;
for (i = 0; i < 10; i++) {
val = HFA384X_INW(reg);
val2 = HFA384X_INW(reg);
val3 = HFA384X_INW(reg);
if (val == val2 && val == val3)
return val;
printk(KERN_DEBUG "%s: detected fid change (try=%d, reg=%04x):"
" %04x %04x %04x\n",
dev->name, i, reg, val, val2, val3);
if ((val == val2 || val == val3) && val != 0)
return val;
if (val2 == val3 && val2 != 0)
return val2;
}
printk(KERN_WARNING "%s: Uhhuh.. could not read good fid from reg "
"%04x (%04x %04x %04x)\n", dev->name, reg, val, val2, val3);
return val;
#else
return HFA384X_INW(reg);
#endif
}
static void prism2_rx(local_info_t *local)
{
struct net_device *dev = local->dev;
int res, rx_pending = 0;
u16 len, hdr_len, rxfid, status, macport;
struct hfa384x_rx_frame rxdesc;
struct sk_buff *skb = NULL;
prism2_callback(local, PRISM2_CALLBACK_RX_START);
rxfid = prism2_read_fid_reg(dev, HFA384X_RXFID_OFF);
#ifndef final_version
if (rxfid == 0) {
rxfid = HFA384X_INW(HFA384X_RXFID_OFF);
printk(KERN_DEBUG "prism2_rx: rxfid=0 (next 0x%04x)\n",
rxfid);
if (rxfid == 0) {
schedule_work(&local->reset_queue);
goto rx_dropped;
}
}
#endif
spin_lock(&local->baplock);
res = hfa384x_setup_bap(dev, BAP0, rxfid, 0);
if (!res)
res = hfa384x_from_bap(dev, BAP0, &rxdesc, sizeof(rxdesc));
if (res) {
spin_unlock(&local->baplock);
printk(KERN_DEBUG "%s: copy from BAP0 failed %d\n", dev->name,
res);
if (res == -ETIMEDOUT) {
schedule_work(&local->reset_queue);
}
goto rx_dropped;
}
len = le16_to_cpu(rxdesc.data_len);
hdr_len = sizeof(rxdesc);
status = le16_to_cpu(rxdesc.status);
macport = (status >> 8) & 0x07;
if (len > PRISM2_DATA_MAXLEN + 8 ) {
if (macport == 7 && local->iw_mode == IW_MODE_MONITOR) {
if (len >= (u16) -14) {
hdr_len -= 65535 - len;
hdr_len--;
}
len = 0;
} else {
spin_unlock(&local->baplock);
printk(KERN_DEBUG "%s: Received frame with invalid "
"length 0x%04x\n", dev->name, len);
hostap_dump_rx_header(dev->name, &rxdesc);
goto rx_dropped;
}
}
skb = dev_alloc_skb(len + hdr_len);
if (!skb) {
spin_unlock(&local->baplock);
printk(KERN_DEBUG "%s: RX failed to allocate skb\n",
dev->name);
goto rx_dropped;
}
skb->dev = dev;
memcpy(skb_put(skb, hdr_len), &rxdesc, hdr_len);
if (len > 0)
res = hfa384x_from_bap(dev, BAP0, skb_put(skb, len), len);
spin_unlock(&local->baplock);
if (res) {
printk(KERN_DEBUG "%s: RX failed to read "
"frame data\n", dev->name);
goto rx_dropped;
}
skb_queue_tail(&local->rx_list, skb);
tasklet_schedule(&local->rx_tasklet);
rx_exit:
prism2_callback(local, PRISM2_CALLBACK_RX_END);
if (!rx_pending) {
HFA384X_OUTW(HFA384X_EV_RX, HFA384X_EVACK_OFF);
}
return;
rx_dropped:
dev->stats.rx_dropped++;
if (skb)
dev_kfree_skb(skb);
goto rx_exit;
}
static void hostap_rx_skb(local_info_t *local, struct sk_buff *skb)
{
struct hfa384x_rx_frame *rxdesc;
struct net_device *dev = skb->dev;
struct hostap_80211_rx_status stats;
int hdrlen, rx_hdrlen;
rx_hdrlen = sizeof(*rxdesc);
if (skb->len < sizeof(*rxdesc)) {
if (local->iw_mode == IW_MODE_MONITOR &&
skb->len >= sizeof(*rxdesc) - 30) {
rx_hdrlen = skb->len;
} else {
dev_kfree_skb(skb);
return;
}
}
rxdesc = (struct hfa384x_rx_frame *) skb->data;
if (local->frame_dump & PRISM2_DUMP_RX_HDR &&
skb->len >= sizeof(*rxdesc))
hostap_dump_rx_header(dev->name, rxdesc);
if (le16_to_cpu(rxdesc->status) & HFA384X_RX_STATUS_FCSERR &&
(!local->monitor_allow_fcserr ||
local->iw_mode != IW_MODE_MONITOR))
goto drop;
if (skb->len > PRISM2_DATA_MAXLEN) {
printk(KERN_DEBUG "%s: RX: len(%d) > MAX(%d)\n",
dev->name, skb->len, PRISM2_DATA_MAXLEN);
goto drop;
}
stats.mac_time = le32_to_cpu(rxdesc->time);
stats.signal = rxdesc->signal - local->rssi_to_dBm;
stats.noise = rxdesc->silence - local->rssi_to_dBm;
stats.rate = rxdesc->rate;
hdrlen = hostap_80211_get_hdrlen(rxdesc->frame_control);
if (hdrlen > rx_hdrlen)
hdrlen = rx_hdrlen;
memmove(skb_pull(skb, rx_hdrlen - hdrlen),
&rxdesc->frame_control, hdrlen);
hostap_80211_rx(dev, skb, &stats);
return;
drop:
dev_kfree_skb(skb);
}
static void hostap_rx_tasklet(unsigned long data)
{
local_info_t *local = (local_info_t *) data;
struct sk_buff *skb;
while ((skb = skb_dequeue(&local->rx_list)) != NULL)
hostap_rx_skb(local, skb);
}
static void prism2_alloc_ev(struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
int idx;
u16 fid;
iface = netdev_priv(dev);
local = iface->local;
fid = prism2_read_fid_reg(dev, HFA384X_ALLOCFID_OFF);
PDEBUG(DEBUG_FID, "FID: interrupt: ALLOC - fid=0x%04x\n", fid);
spin_lock(&local->txfidlock);
idx = local->next_alloc;
do {
if (local->txfid[idx] == fid) {
PDEBUG(DEBUG_FID, "FID: found matching txfid[%d]\n",
idx);
#ifndef final_version
if (local->intransmitfid[idx] == PRISM2_TXFID_EMPTY)
printk("Already released txfid found at idx "
"%d\n", idx);
if (local->intransmitfid[idx] == PRISM2_TXFID_RESERVED)
printk("Already reserved txfid found at idx "
"%d\n", idx);
#endif
local->intransmitfid[idx] = PRISM2_TXFID_EMPTY;
idx++;
local->next_alloc = idx >= PRISM2_TXFID_COUNT ? 0 :
idx;
if (!test_bit(HOSTAP_BITS_TRANSMIT, &local->bits) &&
netif_queue_stopped(dev))
netif_wake_queue(dev);
spin_unlock(&local->txfidlock);
return;
}
idx++;
if (idx >= PRISM2_TXFID_COUNT)
idx = 0;
} while (idx != local->next_alloc);
printk(KERN_WARNING "%s: could not find matching txfid (0x%04x, new "
"read 0x%04x) for alloc event\n", dev->name, fid,
HFA384X_INW(HFA384X_ALLOCFID_OFF));
printk(KERN_DEBUG "TXFIDs:");
for (idx = 0; idx < PRISM2_TXFID_COUNT; idx++)
printk(" %04x[%04x]", local->txfid[idx],
local->intransmitfid[idx]);
printk("\n");
spin_unlock(&local->txfidlock);
}
static void hostap_tx_callback(local_info_t *local,
struct hfa384x_tx_frame *txdesc, int ok,
char *payload)
{
u16 sw_support, hdrlen, len;
struct sk_buff *skb;
struct hostap_tx_callback_info *cb;
if (memcmp(txdesc->addr2, local->dev->dev_addr, ETH_ALEN)) {
printk(KERN_DEBUG "%s: TX callback - foreign frame\n",
local->dev->name);
return;
}
sw_support = le32_to_cpu(txdesc->sw_support);
spin_lock(&local->lock);
cb = local->tx_callback;
while (cb != NULL && cb->idx != sw_support)
cb = cb->next;
spin_unlock(&local->lock);
if (cb == NULL) {
printk(KERN_DEBUG "%s: could not find TX callback (idx %d)\n",
local->dev->name, sw_support);
return;
}
hdrlen = hostap_80211_get_hdrlen(txdesc->frame_control);
len = le16_to_cpu(txdesc->data_len);
skb = dev_alloc_skb(hdrlen + len);
if (skb == NULL) {
printk(KERN_DEBUG "%s: hostap_tx_callback failed to allocate "
"skb\n", local->dev->name);
return;
}
memcpy(skb_put(skb, hdrlen), (void *) &txdesc->frame_control, hdrlen);
if (payload)
memcpy(skb_put(skb, len), payload, len);
skb->dev = local->dev;
skb_reset_mac_header(skb);
cb->func(skb, ok, cb->data);
}
static int hostap_tx_compl_read(local_info_t *local, int error,
struct hfa384x_tx_frame *txdesc,
char **payload)
{
u16 fid, len;
int res, ret = 0;
struct net_device *dev = local->dev;
fid = prism2_read_fid_reg(dev, HFA384X_TXCOMPLFID_OFF);
PDEBUG(DEBUG_FID, "interrupt: TX (err=%d) - fid=0x%04x\n", fid, error);
spin_lock(&local->baplock);
res = hfa384x_setup_bap(dev, BAP0, fid, 0);
if (!res)
res = hfa384x_from_bap(dev, BAP0, txdesc, sizeof(*txdesc));
if (res) {
PDEBUG(DEBUG_EXTRA, "%s: TX (err=%d) - fid=0x%04x - could not "
"read txdesc\n", dev->name, error, fid);
if (res == -ETIMEDOUT) {
schedule_work(&local->reset_queue);
}
ret = -1;
goto fail;
}
if (txdesc->sw_support) {
len = le16_to_cpu(txdesc->data_len);
if (len < PRISM2_DATA_MAXLEN) {
*payload = kmalloc(len, GFP_ATOMIC);
if (*payload == NULL ||
hfa384x_from_bap(dev, BAP0, *payload, len)) {
PDEBUG(DEBUG_EXTRA, "%s: could not read TX "
"frame payload\n", dev->name);
kfree(*payload);
*payload = NULL;
ret = -1;
goto fail;
}
}
}
fail:
spin_unlock(&local->baplock);
return ret;
}
static void prism2_tx_ev(local_info_t *local)
{
struct net_device *dev = local->dev;
char *payload = NULL;
struct hfa384x_tx_frame txdesc;
if (hostap_tx_compl_read(local, 0, &txdesc, &payload))
goto fail;
if (local->frame_dump & PRISM2_DUMP_TX_HDR) {
PDEBUG(DEBUG_EXTRA, "%s: TX - status=0x%04x "
"retry_count=%d tx_rate=%d seq_ctrl=%d "
"duration_id=%d\n",
dev->name, le16_to_cpu(txdesc.status),
txdesc.retry_count, txdesc.tx_rate,
le16_to_cpu(txdesc.seq_ctrl),
le16_to_cpu(txdesc.duration_id));
}
if (txdesc.sw_support)
hostap_tx_callback(local, &txdesc, 1, payload);
kfree(payload);
fail:
HFA384X_OUTW(HFA384X_EV_TX, HFA384X_EVACK_OFF);
}
static void hostap_sta_tx_exc_tasklet(unsigned long data)
{
local_info_t *local = (local_info_t *) data;
struct sk_buff *skb;
while ((skb = skb_dequeue(&local->sta_tx_exc_list)) != NULL) {
struct hfa384x_tx_frame *txdesc =
(struct hfa384x_tx_frame *) skb->data;
if (skb->len >= sizeof(*txdesc)) {
int hdrlen = hostap_80211_get_hdrlen(txdesc->frame_control);
memmove(skb_pull(skb, sizeof(*txdesc) - hdrlen),
&txdesc->frame_control, hdrlen);
hostap_handle_sta_tx_exc(local, skb);
}
dev_kfree_skb(skb);
}
}
static void prism2_txexc(local_info_t *local)
{
struct net_device *dev = local->dev;
u16 status, fc;
int show_dump, res;
char *payload = NULL;
struct hfa384x_tx_frame txdesc;
show_dump = local->frame_dump & PRISM2_DUMP_TXEXC_HDR;
dev->stats.tx_errors++;
res = hostap_tx_compl_read(local, 1, &txdesc, &payload);
HFA384X_OUTW(HFA384X_EV_TXEXC, HFA384X_EVACK_OFF);
if (res)
return;
status = le16_to_cpu(txdesc.status);
if (status & (HFA384X_TX_STATUS_RETRYERR | HFA384X_TX_STATUS_AGEDERR))
{
union iwreq_data wrqu;
memcpy(wrqu.addr.sa_data, txdesc.addr1, ETH_ALEN);
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event(dev, IWEVTXDROP, &wrqu, NULL);
} else
show_dump = 1;
if (local->iw_mode == IW_MODE_MASTER ||
local->iw_mode == IW_MODE_REPEAT ||
local->wds_type & HOSTAP_WDS_AP_CLIENT) {
struct sk_buff *skb;
skb = dev_alloc_skb(sizeof(txdesc));
if (skb) {
memcpy(skb_put(skb, sizeof(txdesc)), &txdesc,
sizeof(txdesc));
skb_queue_tail(&local->sta_tx_exc_list, skb);
tasklet_schedule(&local->sta_tx_exc_tasklet);
}
}
if (txdesc.sw_support)
hostap_tx_callback(local, &txdesc, 0, payload);
kfree(payload);
if (!show_dump)
return;
PDEBUG(DEBUG_EXTRA, "%s: TXEXC - status=0x%04x (%s%s%s%s)"
" tx_control=%04x\n",
dev->name, status,
status & HFA384X_TX_STATUS_RETRYERR ? "[RetryErr]" : "",
status & HFA384X_TX_STATUS_AGEDERR ? "[AgedErr]" : "",
status & HFA384X_TX_STATUS_DISCON ? "[Discon]" : "",
status & HFA384X_TX_STATUS_FORMERR ? "[FormErr]" : "",
le16_to_cpu(txdesc.tx_control));
fc = le16_to_cpu(txdesc.frame_control);
PDEBUG(DEBUG_EXTRA, " retry_count=%d tx_rate=%d fc=0x%04x "
"(%s%s%s::%d%s%s)\n",
txdesc.retry_count, txdesc.tx_rate, fc,
ieee80211_is_mgmt(txdesc.frame_control) ? "Mgmt" : "",
ieee80211_is_ctl(txdesc.frame_control) ? "Ctrl" : "",
ieee80211_is_data(txdesc.frame_control) ? "Data" : "",
(fc & IEEE80211_FCTL_STYPE) >> 4,
ieee80211_has_tods(txdesc.frame_control) ? " ToDS" : "",
ieee80211_has_fromds(txdesc.frame_control) ? " FromDS" : "");
PDEBUG(DEBUG_EXTRA, " A1=%pM A2=%pM A3=%pM A4=%pM\n",
txdesc.addr1, txdesc.addr2,
txdesc.addr3, txdesc.addr4);
}
static void hostap_info_tasklet(unsigned long data)
{
local_info_t *local = (local_info_t *) data;
struct sk_buff *skb;
while ((skb = skb_dequeue(&local->info_list)) != NULL) {
hostap_info_process(local, skb);
dev_kfree_skb(skb);
}
}
static void prism2_info(local_info_t *local)
{
struct net_device *dev = local->dev;
u16 fid;
int res, left;
struct hfa384x_info_frame info;
struct sk_buff *skb;
fid = HFA384X_INW(HFA384X_INFOFID_OFF);
spin_lock(&local->baplock);
res = hfa384x_setup_bap(dev, BAP0, fid, 0);
if (!res)
res = hfa384x_from_bap(dev, BAP0, &info, sizeof(info));
if (res) {
spin_unlock(&local->baplock);
printk(KERN_DEBUG "Could not get info frame (fid=0x%04x)\n",
fid);
if (res == -ETIMEDOUT) {
schedule_work(&local->reset_queue);
}
goto out;
}
left = (le16_to_cpu(info.len) - 1) * 2;
if (info.len & cpu_to_le16(0x8000) || info.len == 0 || left > 2060) {
spin_unlock(&local->baplock);
printk(KERN_DEBUG "%s: Received info frame with invalid "
"length 0x%04x (type 0x%04x)\n", dev->name,
le16_to_cpu(info.len), le16_to_cpu(info.type));
goto out;
}
skb = dev_alloc_skb(sizeof(info) + left);
if (skb == NULL) {
spin_unlock(&local->baplock);
printk(KERN_DEBUG "%s: Could not allocate skb for info "
"frame\n", dev->name);
goto out;
}
memcpy(skb_put(skb, sizeof(info)), &info, sizeof(info));
if (left > 0 && hfa384x_from_bap(dev, BAP0, skb_put(skb, left), left))
{
spin_unlock(&local->baplock);
printk(KERN_WARNING "%s: Info frame read failed (fid=0x%04x, "
"len=0x%04x, type=0x%04x\n", dev->name, fid,
le16_to_cpu(info.len), le16_to_cpu(info.type));
dev_kfree_skb(skb);
goto out;
}
spin_unlock(&local->baplock);
skb_queue_tail(&local->info_list, skb);
tasklet_schedule(&local->info_tasklet);
out:
HFA384X_OUTW(HFA384X_EV_INFO, HFA384X_EVACK_OFF);
}
static void hostap_bap_tasklet(unsigned long data)
{
local_info_t *local = (local_info_t *) data;
struct net_device *dev = local->dev;
u16 ev;
int frames = 30;
if (local->func->card_present && !local->func->card_present(local))
return;
set_bit(HOSTAP_BITS_BAP_TASKLET, &local->bits);
while (frames-- > 0) {
ev = HFA384X_INW(HFA384X_EVSTAT_OFF);
if (ev == 0xffff || !(ev & HFA384X_BAP0_EVENTS))
break;
if (ev & HFA384X_EV_RX)
prism2_rx(local);
if (ev & HFA384X_EV_INFO)
prism2_info(local);
if (ev & HFA384X_EV_TX)
prism2_tx_ev(local);
if (ev & HFA384X_EV_TXEXC)
prism2_txexc(local);
}
set_bit(HOSTAP_BITS_BAP_TASKLET2, &local->bits);
clear_bit(HOSTAP_BITS_BAP_TASKLET, &local->bits);
hfa384x_events_all(dev);
clear_bit(HOSTAP_BITS_BAP_TASKLET2, &local->bits);
}
static void prism2_infdrop(struct net_device *dev)
{
static unsigned long last_inquire = 0;
PDEBUG(DEBUG_EXTRA, "%s: INFDROP event\n", dev->name);
if (!last_inquire || time_after(jiffies, last_inquire + HZ)) {
hfa384x_cmd_callback(dev, HFA384X_CMDCODE_INQUIRE,
HFA384X_INFO_COMMTALLIES, NULL, 0);
last_inquire = jiffies;
}
}
static void prism2_ev_tick(struct net_device *dev)
{
struct hostap_interface *iface;
local_info_t *local;
u16 evstat, inten;
static int prev_stuck = 0;
iface = netdev_priv(dev);
local = iface->local;
if (time_after(jiffies, local->last_tick_timer + 5 * HZ) &&
local->last_tick_timer) {
evstat = HFA384X_INW(HFA384X_EVSTAT_OFF);
inten = HFA384X_INW(HFA384X_INTEN_OFF);
if (!prev_stuck) {
printk(KERN_INFO "%s: SW TICK stuck? "
"bits=0x%lx EvStat=%04x IntEn=%04x\n",
dev->name, local->bits, evstat, inten);
}
local->sw_tick_stuck++;
if ((evstat & HFA384X_BAP0_EVENTS) &&
(inten & HFA384X_BAP0_EVENTS)) {
printk(KERN_INFO "%s: trying to recover from IRQ "
"hang\n", dev->name);
hfa384x_events_no_bap0(dev);
}
prev_stuck = 1;
} else
prev_stuck = 0;
}
static void prism2_check_magic(local_info_t *local)
{
#ifndef PRISM2_PCI
#ifndef final_version
static unsigned long last_magic_err = 0;
struct net_device *dev = local->dev;
if (HFA384X_INW(HFA384X_SWSUPPORT0_OFF) != HFA384X_MAGIC) {
if (!local->hw_ready)
return;
HFA384X_OUTW(0xffff, HFA384X_EVACK_OFF);
if (time_after(jiffies, last_magic_err + 10 * HZ)) {
printk("%s: Interrupt, but SWSUPPORT0 does not match: "
"%04X != %04X - card removed?\n", dev->name,
HFA384X_INW(HFA384X_SWSUPPORT0_OFF),
HFA384X_MAGIC);
last_magic_err = jiffies;
} else if (net_ratelimit()) {
printk(KERN_DEBUG "%s: interrupt - SWSUPPORT0=%04x "
"MAGIC=%04x\n", dev->name,
HFA384X_INW(HFA384X_SWSUPPORT0_OFF),
HFA384X_MAGIC);
}
if (HFA384X_INW(HFA384X_SWSUPPORT0_OFF) != 0xffff)
schedule_work(&local->reset_queue);
return;
}
#endif
#endif
}
static irqreturn_t prism2_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct hostap_interface *iface;
local_info_t *local;
int events = 0;
u16 ev;
iface = netdev_priv(dev);
local = iface->local;
spin_lock(&local->irq_init_lock);
if (!dev->base_addr) {
if (net_ratelimit()) {
printk(KERN_DEBUG "%s: Interrupt, but dev not configured\n",
dev->name);
}
spin_unlock(&local->irq_init_lock);
return IRQ_HANDLED;
}
spin_unlock(&local->irq_init_lock);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_INTERRUPT, 0, 0);
if (local->func->card_present && !local->func->card_present(local)) {
if (net_ratelimit()) {
printk(KERN_DEBUG "%s: Interrupt, but dev not OK\n",
dev->name);
}
return IRQ_HANDLED;
}
prism2_check_magic(local);
for (;;) {
ev = HFA384X_INW(HFA384X_EVSTAT_OFF);
if (ev == 0xffff) {
if (local->shutdown)
return IRQ_HANDLED;
HFA384X_OUTW(0xffff, HFA384X_EVACK_OFF);
printk(KERN_DEBUG "%s: prism2_interrupt: ev=0xffff\n",
dev->name);
return IRQ_HANDLED;
}
ev &= HFA384X_INW(HFA384X_INTEN_OFF);
if (ev == 0)
break;
if (ev & HFA384X_EV_CMD) {
prism2_cmd_ev(dev);
}
if (!local->hw_ready || local->hw_resetting ||
!local->dev_enabled) {
ev = HFA384X_INW(HFA384X_EVSTAT_OFF);
if (ev & HFA384X_EV_CMD)
goto next_event;
if ((ev & HFA384X_EVENT_MASK) == 0)
return IRQ_HANDLED;
if (local->dev_enabled && (ev & ~HFA384X_EV_TICK) &&
net_ratelimit()) {
printk(KERN_DEBUG "%s: prism2_interrupt: hw "
"not ready; skipping events 0x%04x "
"(IntEn=0x%04x)%s%s%s\n",
dev->name, ev,
HFA384X_INW(HFA384X_INTEN_OFF),
!local->hw_ready ? " (!hw_ready)" : "",
local->hw_resetting ?
" (hw_resetting)" : "",
!local->dev_enabled ?
" (!dev_enabled)" : "");
}
HFA384X_OUTW(ev, HFA384X_EVACK_OFF);
return IRQ_HANDLED;
}
if (ev & HFA384X_EV_TICK) {
prism2_ev_tick(dev);
HFA384X_OUTW(HFA384X_EV_TICK, HFA384X_EVACK_OFF);
}
if (ev & HFA384X_EV_ALLOC) {
prism2_alloc_ev(dev);
HFA384X_OUTW(HFA384X_EV_ALLOC, HFA384X_EVACK_OFF);
}
if (ev & HFA384X_BAP0_EVENTS) {
hfa384x_events_no_bap0(dev);
tasklet_schedule(&local->bap_tasklet);
}
#ifndef final_version
if (ev & HFA384X_EV_WTERR) {
PDEBUG(DEBUG_EXTRA, "%s: WTERR event\n", dev->name);
HFA384X_OUTW(HFA384X_EV_WTERR, HFA384X_EVACK_OFF);
}
#endif
if (ev & HFA384X_EV_INFDROP) {
prism2_infdrop(dev);
HFA384X_OUTW(HFA384X_EV_INFDROP, HFA384X_EVACK_OFF);
}
next_event:
events++;
if (events >= PRISM2_MAX_INTERRUPT_EVENTS) {
PDEBUG(DEBUG_EXTRA, "prism2_interrupt: >%d events "
"(EvStat=0x%04x)\n",
PRISM2_MAX_INTERRUPT_EVENTS,
HFA384X_INW(HFA384X_EVSTAT_OFF));
break;
}
}
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_INTERRUPT, 0, 1);
return IRQ_RETVAL(events);
}
static void prism2_check_sta_fw_version(local_info_t *local)
{
struct hfa384x_comp_ident comp;
int id, variant, major, minor;
if (hfa384x_get_rid(local->dev, HFA384X_RID_STAID,
&comp, sizeof(comp), 1) < 0)
return;
local->fw_ap = 0;
id = le16_to_cpu(comp.id);
if (id != HFA384X_COMP_ID_STA) {
if (id == HFA384X_COMP_ID_FW_AP)
local->fw_ap = 1;
return;
}
major = __le16_to_cpu(comp.major);
minor = __le16_to_cpu(comp.minor);
variant = __le16_to_cpu(comp.variant);
local->sta_fw_ver = PRISM2_FW_VER(major, minor, variant);
local->fw_encrypt_ok = local->sta_fw_ver >= PRISM2_FW_VER(1,4,9);
if (local->iw_mode == IW_MODE_MASTER && !local->host_encrypt &&
!local->fw_encrypt_ok) {
printk(KERN_DEBUG "%s: defaulting to host-based encryption as "
"a workaround for firmware bug in Host AP mode WEP\n",
local->dev->name);
local->host_encrypt = 1;
}
if (local->sta_fw_ver >= PRISM2_FW_VER(1,5,0))
local->wds_type |= HOSTAP_WDS_STANDARD_FRAME;
else {
printk(KERN_DEBUG "%s: defaulting to bogus WDS frame as a "
"workaround for firmware bug in Host AP mode WDS\n",
local->dev->name);
}
hostap_check_sta_fw_version(local->ap, local->sta_fw_ver);
}
static void hostap_passive_scan(unsigned long data)
{
local_info_t *local = (local_info_t *) data;
struct net_device *dev = local->dev;
u16 chan;
if (local->passive_scan_interval <= 0)
return;
if (local->passive_scan_state == PASSIVE_SCAN_LISTEN) {
int max_tries = 16;
if (test_bit(HOSTAP_BITS_TRANSMIT, &local->bits)) {
printk(KERN_DEBUG "%s: passive scan detected pending "
"TX - delaying\n", dev->name);
local->passive_scan_timer.expires = jiffies + HZ / 10;
add_timer(&local->passive_scan_timer);
return;
}
do {
local->passive_scan_channel++;
if (local->passive_scan_channel > 14)
local->passive_scan_channel = 1;
max_tries--;
} while (!(local->channel_mask &
(1 << (local->passive_scan_channel - 1))) &&
max_tries > 0);
if (max_tries == 0) {
printk(KERN_INFO "%s: no allowed passive scan channels"
" found\n", dev->name);
return;
}
printk(KERN_DEBUG "%s: passive scan channel %d\n",
dev->name, local->passive_scan_channel);
chan = local->passive_scan_channel;
local->passive_scan_state = PASSIVE_SCAN_WAIT;
local->passive_scan_timer.expires = jiffies + HZ / 10;
} else {
chan = local->channel;
local->passive_scan_state = PASSIVE_SCAN_LISTEN;
local->passive_scan_timer.expires = jiffies +
local->passive_scan_interval * HZ;
}
if (hfa384x_cmd_callback(dev, HFA384X_CMDCODE_TEST |
(HFA384X_TEST_CHANGE_CHANNEL << 8),
chan, NULL, 0))
printk(KERN_ERR "%s: passive scan channel set %d "
"failed\n", dev->name, chan);
add_timer(&local->passive_scan_timer);
}
static void handle_comms_qual_update(struct work_struct *work)
{
local_info_t *local =
container_of(work, local_info_t, comms_qual_update);
prism2_update_comms_qual(local->dev);
}
static void hostap_tick_timer(unsigned long data)
{
static unsigned long last_inquire = 0;
local_info_t *local = (local_info_t *) data;
local->last_tick_timer = jiffies;
if ((!last_inquire || time_after(jiffies, last_inquire + 10 * HZ)) &&
!local->hw_downloading && local->hw_ready &&
!local->hw_resetting && local->dev_enabled) {
hfa384x_cmd_callback(local->dev, HFA384X_CMDCODE_INQUIRE,
HFA384X_INFO_COMMTALLIES, NULL, 0);
last_inquire = jiffies;
}
if ((local->last_comms_qual_update == 0 ||
time_after(jiffies, local->last_comms_qual_update + 10 * HZ)) &&
(local->iw_mode == IW_MODE_INFRA ||
local->iw_mode == IW_MODE_ADHOC)) {
schedule_work(&local->comms_qual_update);
}
local->tick_timer.expires = jiffies + 2 * HZ;
add_timer(&local->tick_timer);
}
static int prism2_registers_proc_read(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
char *p = page;
local_info_t *local = (local_info_t *) data;
if (off != 0) {
*eof = 1;
return 0;
}
#define SHOW_REG(n) \
p += sprintf(p, #n "=%04x\n", hfa384x_read_reg(local->dev, HFA384X_##n##_OFF))
SHOW_REG(CMD);
SHOW_REG(PARAM0);
SHOW_REG(PARAM1);
SHOW_REG(PARAM2);
SHOW_REG(STATUS);
SHOW_REG(RESP0);
SHOW_REG(RESP1);
SHOW_REG(RESP2);
SHOW_REG(INFOFID);
SHOW_REG(CONTROL);
SHOW_REG(SELECT0);
SHOW_REG(SELECT1);
SHOW_REG(OFFSET0);
SHOW_REG(OFFSET1);
SHOW_REG(RXFID);
SHOW_REG(ALLOCFID);
SHOW_REG(TXCOMPLFID);
SHOW_REG(SWSUPPORT0);
SHOW_REG(SWSUPPORT1);
SHOW_REG(SWSUPPORT2);
SHOW_REG(EVSTAT);
SHOW_REG(INTEN);
SHOW_REG(EVACK);
SHOW_REG(AUXPAGE);
SHOW_REG(AUXOFFSET);
#ifdef PRISM2_PCI
SHOW_REG(PCICOR);
SHOW_REG(PCIHCR);
SHOW_REG(PCI_M0_ADDRH);
SHOW_REG(PCI_M0_ADDRL);
SHOW_REG(PCI_M0_LEN);
SHOW_REG(PCI_M0_CTL);
SHOW_REG(PCI_STATUS);
SHOW_REG(PCI_M1_ADDRH);
SHOW_REG(PCI_M1_ADDRL);
SHOW_REG(PCI_M1_LEN);
SHOW_REG(PCI_M1_CTL);
#endif
return (p - page);
}
static int prism2_set_tim(struct net_device *dev, int aid, int set)
{
struct list_head *ptr;
struct set_tim_data *new_entry;
struct hostap_interface *iface;
local_info_t *local;
iface = netdev_priv(dev);
local = iface->local;
new_entry = kzalloc(sizeof(*new_entry), GFP_ATOMIC);
if (new_entry == NULL) {
printk(KERN_DEBUG "%s: prism2_set_tim: kmalloc failed\n",
local->dev->name);
return -ENOMEM;
}
new_entry->aid = aid;
new_entry->set = set;
spin_lock_bh(&local->set_tim_lock);
list_for_each(ptr, &local->set_tim_list) {
struct set_tim_data *entry =
list_entry(ptr, struct set_tim_data, list);
if (entry->aid == aid) {
PDEBUG(DEBUG_PS2, "%s: prism2_set_tim: aid=%d "
"set=%d ==> %d\n",
local->dev->name, aid, entry->set, set);
entry->set = set;
kfree(new_entry);
new_entry = NULL;
break;
}
}
if (new_entry)
list_add_tail(&new_entry->list, &local->set_tim_list);
spin_unlock_bh(&local->set_tim_lock);
schedule_work(&local->set_tim_queue);
return 0;
}
static void handle_set_tim_queue(struct work_struct *work)
{
local_info_t *local = container_of(work, local_info_t, set_tim_queue);
struct set_tim_data *entry;
u16 val;
for (;;) {
entry = NULL;
spin_lock_bh(&local->set_tim_lock);
if (!list_empty(&local->set_tim_list)) {
entry = list_entry(local->set_tim_list.next,
struct set_tim_data, list);
list_del(&entry->list);
}
spin_unlock_bh(&local->set_tim_lock);
if (!entry)
break;
PDEBUG(DEBUG_PS2, "%s: handle_set_tim_queue: aid=%d set=%d\n",
local->dev->name, entry->aid, entry->set);
val = entry->aid;
if (entry->set)
val |= 0x8000;
if (hostap_set_word(local->dev, HFA384X_RID_CNFTIMCTRL, val)) {
printk(KERN_DEBUG "%s: set_tim failed (aid=%d "
"set=%d)\n",
local->dev->name, entry->aid, entry->set);
}
kfree(entry);
}
}
static void prism2_clear_set_tim_queue(local_info_t *local)
{
struct list_head *ptr, *n;
list_for_each_safe(ptr, n, &local->set_tim_list) {
struct set_tim_data *entry;
entry = list_entry(ptr, struct set_tim_data, list);
list_del(&entry->list);
kfree(entry);
}
}
static void prism2_set_lockdep_class_one(struct net_device *dev,
struct netdev_queue *txq,
void *_unused)
{
lockdep_set_class(&txq->_xmit_lock,
&hostap_netdev_xmit_lock_key);
}
static void prism2_set_lockdep_class(struct net_device *dev)
{
lockdep_set_class(&dev->addr_list_lock,
&hostap_netdev_addr_lock_key);
netdev_for_each_tx_queue(dev, prism2_set_lockdep_class_one, NULL);
}
static struct net_device *
prism2_init_local_data(struct prism2_helper_functions *funcs, int card_idx,
struct device *sdev)
{
struct net_device *dev;
struct hostap_interface *iface;
struct local_info *local;
int len, i, ret;
if (funcs == NULL)
return NULL;
len = strlen(dev_template);
if (len >= IFNAMSIZ || strstr(dev_template, "%d") == NULL) {
printk(KERN_WARNING "hostap: Invalid dev_template='%s'\n",
dev_template);
return NULL;
}
len = sizeof(struct hostap_interface) +
3 + sizeof(struct local_info) +
3 + sizeof(struct ap_data);
dev = alloc_etherdev(len);
if (dev == NULL)
return NULL;
iface = netdev_priv(dev);
local = (struct local_info *) ((((long) (iface + 1)) + 3) & ~3);
local->ap = (struct ap_data *) ((((long) (local + 1)) + 3) & ~3);
local->dev = iface->dev = dev;
iface->local = local;
iface->type = HOSTAP_INTERFACE_MASTER;
INIT_LIST_HEAD(&local->hostap_interfaces);
local->hw_module = THIS_MODULE;
#ifdef PRISM2_IO_DEBUG
local->io_debug_enabled = 1;
#endif
local->func = funcs;
local->func->cmd = hfa384x_cmd;
local->func->read_regs = hfa384x_read_regs;
local->func->get_rid = hfa384x_get_rid;
local->func->set_rid = hfa384x_set_rid;
local->func->hw_enable = prism2_hw_enable;
local->func->hw_config = prism2_hw_config;
local->func->hw_reset = prism2_hw_reset;
local->func->hw_shutdown = prism2_hw_shutdown;
local->func->reset_port = prism2_reset_port;
local->func->schedule_reset = prism2_schedule_reset;
#ifdef PRISM2_DOWNLOAD_SUPPORT
local->func->read_aux = prism2_download_aux_dump;
local->func->download = prism2_download;
#endif
local->func->tx = prism2_tx_80211;
local->func->set_tim = prism2_set_tim;
local->func->need_tx_headroom = 0;
local->mtu = mtu;
rwlock_init(&local->iface_lock);
spin_lock_init(&local->txfidlock);
spin_lock_init(&local->cmdlock);
spin_lock_init(&local->baplock);
spin_lock_init(&local->lock);
spin_lock_init(&local->irq_init_lock);
mutex_init(&local->rid_bap_mtx);
if (card_idx < 0 || card_idx >= MAX_PARM_DEVICES)
card_idx = 0;
local->card_idx = card_idx;
len = strlen(essid);
memcpy(local->essid, essid,
len > MAX_SSID_LEN ? MAX_SSID_LEN : len);
local->essid[MAX_SSID_LEN] = '\0';
i = GET_INT_PARM(iw_mode, card_idx);
if ((i >= IW_MODE_ADHOC && i <= IW_MODE_REPEAT) ||
i == IW_MODE_MONITOR) {
local->iw_mode = i;
} else {
printk(KERN_WARNING "prism2: Unknown iw_mode %d; using "
"IW_MODE_MASTER\n", i);
local->iw_mode = IW_MODE_MASTER;
}
local->channel = GET_INT_PARM(channel, card_idx);
local->beacon_int = GET_INT_PARM(beacon_int, card_idx);
local->dtim_period = GET_INT_PARM(dtim_period, card_idx);
local->wds_max_connections = 16;
local->tx_control = HFA384X_TX_CTRL_FLAGS;
local->manual_retry_count = -1;
local->rts_threshold = 2347;
local->fragm_threshold = 2346;
local->rssi_to_dBm = 100;
local->auth_algs = PRISM2_AUTH_OPEN | PRISM2_AUTH_SHARED_KEY;
local->sram_type = -1;
local->scan_channel_mask = 0xffff;
local->monitor_type = PRISM2_MONITOR_RADIOTAP;
INIT_WORK(&local->reset_queue, handle_reset_queue);
INIT_WORK(&local->set_multicast_list_queue,
hostap_set_multicast_list_queue);
INIT_WORK(&local->set_tim_queue, handle_set_tim_queue);
INIT_LIST_HEAD(&local->set_tim_list);
spin_lock_init(&local->set_tim_lock);
INIT_WORK(&local->comms_qual_update, handle_comms_qual_update);
#define HOSTAP_TASKLET_INIT(q, f, d) \
do { memset((q), 0, sizeof(*(q))); (q)->func = (f); (q)->data = (d); } \
while (0)
HOSTAP_TASKLET_INIT(&local->bap_tasklet, hostap_bap_tasklet,
(unsigned long) local);
HOSTAP_TASKLET_INIT(&local->info_tasklet, hostap_info_tasklet,
(unsigned long) local);
hostap_info_init(local);
HOSTAP_TASKLET_INIT(&local->rx_tasklet,
hostap_rx_tasklet, (unsigned long) local);
skb_queue_head_init(&local->rx_list);
HOSTAP_TASKLET_INIT(&local->sta_tx_exc_tasklet,
hostap_sta_tx_exc_tasklet, (unsigned long) local);
skb_queue_head_init(&local->sta_tx_exc_list);
INIT_LIST_HEAD(&local->cmd_queue);
init_waitqueue_head(&local->hostscan_wq);
lib80211_crypt_info_init(&local->crypt_info, dev->name, &local->lock);
init_timer(&local->passive_scan_timer);
local->passive_scan_timer.data = (unsigned long) local;
local->passive_scan_timer.function = hostap_passive_scan;
init_timer(&local->tick_timer);
local->tick_timer.data = (unsigned long) local;
local->tick_timer.function = hostap_tick_timer;
local->tick_timer.expires = jiffies + 2 * HZ;
add_timer(&local->tick_timer);
INIT_LIST_HEAD(&local->bss_list);
hostap_setup_dev(dev, local, HOSTAP_INTERFACE_MASTER);
dev->type = ARPHRD_IEEE80211;
dev->header_ops = &hostap_80211_ops;
rtnl_lock();
ret = dev_alloc_name(dev, "wifi%d");
SET_NETDEV_DEV(dev, sdev);
if (ret >= 0)
ret = register_netdevice(dev);
prism2_set_lockdep_class(dev);
rtnl_unlock();
if (ret < 0) {
printk(KERN_WARNING "%s: register netdevice failed!\n",
dev_info);
goto fail;
}
printk(KERN_INFO "%s: Registered netdevice %s\n", dev_info, dev->name);
hostap_init_data(local);
return dev;
fail:
free_netdev(dev);
return NULL;
}
static int hostap_hw_ready(struct net_device *dev)
{
struct hostap_interface *iface;
struct local_info *local;
iface = netdev_priv(dev);
local = iface->local;
local->ddev = hostap_add_interface(local, HOSTAP_INTERFACE_MAIN, 0,
"", dev_template);
if (local->ddev) {
if (local->iw_mode == IW_MODE_INFRA ||
local->iw_mode == IW_MODE_ADHOC) {
netif_carrier_off(local->dev);
netif_carrier_off(local->ddev);
}
hostap_init_proc(local);
#ifndef PRISM2_NO_PROCFS_DEBUG
create_proc_read_entry("registers", 0, local->proc,
prism2_registers_proc_read, local);
#endif
hostap_init_ap_proc(local);
return 0;
}
return -1;
}
static void prism2_free_local_data(struct net_device *dev)
{
struct hostap_tx_callback_info *tx_cb, *tx_cb_prev;
int i;
struct hostap_interface *iface;
struct local_info *local;
struct list_head *ptr, *n;
if (dev == NULL)
return;
iface = netdev_priv(dev);
local = iface->local;
list_for_each_safe(ptr, n, &local->hostap_interfaces) {
iface = list_entry(ptr, struct hostap_interface, list);
if (iface->type == HOSTAP_INTERFACE_MASTER) {
continue;
}
hostap_remove_interface(iface->dev, 0, 1);
}
unregister_netdev(local->dev);
flush_work_sync(&local->reset_queue);
flush_work_sync(&local->set_multicast_list_queue);
flush_work_sync(&local->set_tim_queue);
#ifndef PRISM2_NO_STATION_MODES
flush_work_sync(&local->info_queue);
#endif
flush_work_sync(&local->comms_qual_update);
lib80211_crypt_info_free(&local->crypt_info);
if (timer_pending(&local->passive_scan_timer))
del_timer(&local->passive_scan_timer);
if (timer_pending(&local->tick_timer))
del_timer(&local->tick_timer);
prism2_clear_cmd_queue(local);
skb_queue_purge(&local->info_list);
skb_queue_purge(&local->rx_list);
skb_queue_purge(&local->sta_tx_exc_list);
if (local->dev_enabled)
prism2_callback(local, PRISM2_CALLBACK_DISABLE);
if (local->ap != NULL)
hostap_free_data(local->ap);
#ifndef PRISM2_NO_PROCFS_DEBUG
if (local->proc != NULL)
remove_proc_entry("registers", local->proc);
#endif
hostap_remove_proc(local);
tx_cb = local->tx_callback;
while (tx_cb != NULL) {
tx_cb_prev = tx_cb;
tx_cb = tx_cb->next;
kfree(tx_cb_prev);
}
hostap_set_hostapd(local, 0, 0);
hostap_set_hostapd_sta(local, 0, 0);
for (i = 0; i < PRISM2_FRAG_CACHE_LEN; i++) {
if (local->frag_cache[i].skb != NULL)
dev_kfree_skb(local->frag_cache[i].skb);
}
#ifdef PRISM2_DOWNLOAD_SUPPORT
prism2_download_free_data(local->dl_pri);
prism2_download_free_data(local->dl_sec);
#endif
prism2_clear_set_tim_queue(local);
list_for_each_safe(ptr, n, &local->bss_list) {
struct hostap_bss_info *bss =
list_entry(ptr, struct hostap_bss_info, list);
kfree(bss);
}
kfree(local->pda);
kfree(local->last_scan_results);
kfree(local->generic_elem);
free_netdev(local->dev);
}
static void prism2_suspend(struct net_device *dev)
{
struct hostap_interface *iface;
struct local_info *local;
union iwreq_data wrqu;
iface = netdev_priv(dev);
local = iface->local;
memset(&wrqu, 0, sizeof(wrqu));
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
wireless_send_event(local->dev, SIOCGIWAP, &wrqu, NULL);
prism2_hw_shutdown(dev, 0);
}
