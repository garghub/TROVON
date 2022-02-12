static int cid_of_response(char *s)
{
int cid;
int rc;
if (s[-1] != ';')
return 0;
rc = kstrtoint(s, 10, &cid);
if (rc)
return 0;
if (cid < 1 || cid > 65535)
return -1;
return cid;
}
void gigaset_handle_modem_response(struct cardstate *cs)
{
unsigned char *argv[MAX_REC_PARAMS + 1];
int params;
int i, j;
const struct resp_type_t *rt;
const struct zsau_resp_t *zr;
int curarg;
unsigned long flags;
unsigned next, tail, head;
struct event_t *event;
int resp_code;
int param_type;
int abort;
size_t len;
int cid;
int rawstring;
len = cs->cbytes;
if (!len) {
gig_dbg(DEBUG_MCMD, "skipped EOL [%02X]", cs->respdata[0]);
return;
}
cs->respdata[len] = 0;
argv[0] = cs->respdata;
params = 1;
if (cs->at_state.getstring) {
cs->at_state.getstring = 0;
rawstring = 1;
cid = 0;
} else {
for (i = 0; i < len; i++)
switch (cs->respdata[i]) {
case ';':
case ',':
case '=':
if (params > MAX_REC_PARAMS) {
dev_warn(cs->dev,
"too many parameters in response\n");
params--;
}
argv[params++] = cs->respdata + i + 1;
}
rawstring = 0;
cid = params > 1 ? cid_of_response(argv[params - 1]) : 0;
if (cid < 0) {
gigaset_add_event(cs, &cs->at_state, RSP_INVAL,
NULL, 0, NULL);
return;
}
for (j = 1; j < params; ++j)
argv[j][-1] = 0;
gig_dbg(DEBUG_EVENT, "CMD received: %s", argv[0]);
if (cid) {
--params;
gig_dbg(DEBUG_EVENT, "CID: %s", argv[params]);
}
gig_dbg(DEBUG_EVENT, "available params: %d", params - 1);
for (j = 1; j < params; j++)
gig_dbg(DEBUG_EVENT, "param %d: %s", j, argv[j]);
}
spin_lock_irqsave(&cs->ev_lock, flags);
head = cs->ev_head;
tail = cs->ev_tail;
abort = 1;
curarg = 0;
while (curarg < params) {
next = (tail + 1) % MAX_EVENTS;
if (unlikely(next == head)) {
dev_err(cs->dev, "event queue full\n");
break;
}
event = cs->events + tail;
event->at_state = NULL;
event->cid = cid;
event->ptr = NULL;
event->arg = NULL;
tail = next;
if (rawstring) {
resp_code = RSP_STRING;
param_type = RT_STRING;
} else {
for (rt = resp_type; rt->response; ++rt)
if (!strcmp(argv[curarg], rt->response))
break;
if (!rt->response) {
event->type = RSP_NONE;
gig_dbg(DEBUG_EVENT,
"unknown modem response: '%s'\n",
argv[curarg]);
break;
}
resp_code = rt->resp_code;
param_type = rt->type;
++curarg;
}
event->type = resp_code;
switch (param_type) {
case RT_NOTHING:
break;
case RT_RING:
if (!cid) {
dev_err(cs->dev,
"received RING without CID!\n");
event->type = RSP_INVAL;
abort = 1;
} else {
event->cid = 0;
event->parameter = cid;
abort = 0;
}
break;
case RT_ZSAU:
if (curarg >= params) {
event->parameter = ZSAU_NONE;
break;
}
for (zr = zsau_resp; zr->str; ++zr)
if (!strcmp(argv[curarg], zr->str))
break;
event->parameter = zr->code;
if (!zr->str)
dev_warn(cs->dev,
"%s: unknown parameter %s after ZSAU\n",
__func__, argv[curarg]);
++curarg;
break;
case RT_STRING:
if (curarg < params) {
event->ptr = kstrdup(argv[curarg], GFP_ATOMIC);
if (!event->ptr)
dev_err(cs->dev, "out of memory\n");
++curarg;
}
gig_dbg(DEBUG_EVENT, "string==%s",
event->ptr ? (char *) event->ptr : "NULL");
break;
case RT_ZCAU:
event->parameter = -1;
if (curarg + 1 < params) {
u8 type, value;
i = kstrtou8(argv[curarg++], 16, &type);
j = kstrtou8(argv[curarg++], 16, &value);
if (i == 0 && j == 0)
event->parameter = (type << 8) | value;
} else
curarg = params - 1;
break;
case RT_NUMBER:
if (curarg >= params ||
kstrtoint(argv[curarg++], 10, &event->parameter))
event->parameter = -1;
gig_dbg(DEBUG_EVENT, "parameter==%d", event->parameter);
break;
}
if (resp_code == RSP_ZDLE)
cs->dle = event->parameter;
if (abort)
break;
}
cs->ev_tail = tail;
spin_unlock_irqrestore(&cs->ev_lock, flags);
if (curarg != params)
gig_dbg(DEBUG_EVENT,
"invalid number of processed parameters: %d/%d",
curarg, params);
}
static void disconnect_nobc(struct at_state_t **at_state_p,
struct cardstate *cs)
{
unsigned long flags;
spin_lock_irqsave(&cs->lock, flags);
++(*at_state_p)->seq_index;
if (!cs->cidmode) {
cs->at_state.pending_commands |= PC_UMMODE;
gig_dbg(DEBUG_EVENT, "Scheduling PC_UMMODE");
cs->commands_pending = 1;
}
if (!list_empty(&(*at_state_p)->list)) {
list_del(&(*at_state_p)->list);
kfree(*at_state_p);
*at_state_p = NULL;
}
spin_unlock_irqrestore(&cs->lock, flags);
}
static void disconnect_bc(struct at_state_t *at_state,
struct cardstate *cs, struct bc_state *bcs)
{
unsigned long flags;
spin_lock_irqsave(&cs->lock, flags);
++at_state->seq_index;
if (!cs->cidmode) {
cs->at_state.pending_commands |= PC_UMMODE;
gig_dbg(DEBUG_EVENT, "Scheduling PC_UMMODE");
cs->commands_pending = 1;
}
spin_unlock_irqrestore(&cs->lock, flags);
cs->ops->close_bchannel(bcs);
if (bcs->chstate & (CHS_D_UP | CHS_NOTIFY_LL)) {
bcs->chstate &= ~(CHS_D_UP | CHS_NOTIFY_LL);
gigaset_isdn_hupD(bcs);
}
}
static inline struct at_state_t *get_free_channel(struct cardstate *cs,
int cid)
{
unsigned long flags;
int i;
struct at_state_t *ret;
for (i = 0; i < cs->channels; ++i)
if (gigaset_get_channel(cs->bcs + i) >= 0) {
ret = &cs->bcs[i].at_state;
ret->cid = cid;
return ret;
}
spin_lock_irqsave(&cs->lock, flags);
ret = kmalloc(sizeof(struct at_state_t), GFP_ATOMIC);
if (ret) {
gigaset_at_init(ret, NULL, cs, cid);
list_add(&ret->list, &cs->temp_at_states);
}
spin_unlock_irqrestore(&cs->lock, flags);
return ret;
}
static void init_failed(struct cardstate *cs, int mode)
{
int i;
struct at_state_t *at_state;
cs->at_state.pending_commands &= ~PC_INIT;
cs->mode = mode;
cs->mstate = MS_UNINITIALIZED;
gigaset_free_channels(cs);
for (i = 0; i < cs->channels; ++i) {
at_state = &cs->bcs[i].at_state;
if (at_state->pending_commands & PC_CID) {
at_state->pending_commands &= ~PC_CID;
at_state->pending_commands |= PC_NOCID;
cs->commands_pending = 1;
}
}
}
static void schedule_init(struct cardstate *cs, int state)
{
if (cs->at_state.pending_commands & PC_INIT) {
gig_dbg(DEBUG_EVENT, "not scheduling PC_INIT again");
return;
}
cs->mstate = state;
cs->mode = M_UNKNOWN;
gigaset_block_channels(cs);
cs->at_state.pending_commands |= PC_INIT;
gig_dbg(DEBUG_EVENT, "Scheduling PC_INIT");
cs->commands_pending = 1;
}
static void send_command(struct cardstate *cs, const char *cmd,
struct at_state_t *at_state)
{
int cid = at_state->cid;
struct cmdbuf_t *cb;
size_t buflen;
buflen = strlen(cmd) + 12;
cb = kmalloc(sizeof(struct cmdbuf_t) + buflen, GFP_ATOMIC);
if (!cb) {
dev_err(cs->dev, "%s: out of memory\n", __func__);
return;
}
if (cid > 0 && cid <= 65535)
cb->len = snprintf(cb->buf, buflen,
cs->dle ? "\020(AT%d%s\020)" : "AT%d%s",
cid, cmd);
else
cb->len = snprintf(cb->buf, buflen,
cs->dle ? "\020(AT%s\020)" : "AT%s",
cmd);
cb->offset = 0;
cb->next = NULL;
cb->wake_tasklet = NULL;
cs->ops->write_cmd(cs, cb);
}
static struct at_state_t *at_state_from_cid(struct cardstate *cs, int cid)
{
struct at_state_t *at_state;
int i;
unsigned long flags;
if (cid == 0)
return &cs->at_state;
for (i = 0; i < cs->channels; ++i)
if (cid == cs->bcs[i].at_state.cid)
return &cs->bcs[i].at_state;
spin_lock_irqsave(&cs->lock, flags);
list_for_each_entry(at_state, &cs->temp_at_states, list)
if (cid == at_state->cid) {
spin_unlock_irqrestore(&cs->lock, flags);
return at_state;
}
spin_unlock_irqrestore(&cs->lock, flags);
return NULL;
}
static void bchannel_down(struct bc_state *bcs)
{
if (bcs->chstate & CHS_B_UP) {
bcs->chstate &= ~CHS_B_UP;
gigaset_isdn_hupB(bcs);
}
if (bcs->chstate & (CHS_D_UP | CHS_NOTIFY_LL)) {
bcs->chstate &= ~(CHS_D_UP | CHS_NOTIFY_LL);
gigaset_isdn_hupD(bcs);
}
gigaset_free_channel(bcs);
gigaset_bcs_reinit(bcs);
}
static void bchannel_up(struct bc_state *bcs)
{
if (bcs->chstate & CHS_B_UP) {
dev_notice(bcs->cs->dev, "%s: B channel already up\n",
__func__);
return;
}
bcs->chstate |= CHS_B_UP;
gigaset_isdn_connB(bcs);
}
static void start_dial(struct at_state_t *at_state, void *data,
unsigned seq_index)
{
struct bc_state *bcs = at_state->bcs;
struct cardstate *cs = at_state->cs;
char **commands = data;
unsigned long flags;
int i;
bcs->chstate |= CHS_NOTIFY_LL;
spin_lock_irqsave(&cs->lock, flags);
if (at_state->seq_index != seq_index) {
spin_unlock_irqrestore(&cs->lock, flags);
goto error;
}
spin_unlock_irqrestore(&cs->lock, flags);
for (i = 0; i < AT_NUM; ++i) {
kfree(bcs->commands[i]);
bcs->commands[i] = commands[i];
}
at_state->pending_commands |= PC_CID;
gig_dbg(DEBUG_EVENT, "Scheduling PC_CID");
cs->commands_pending = 1;
return;
error:
for (i = 0; i < AT_NUM; ++i) {
kfree(commands[i]);
commands[i] = NULL;
}
at_state->pending_commands |= PC_NOCID;
gig_dbg(DEBUG_EVENT, "Scheduling PC_NOCID");
cs->commands_pending = 1;
return;
}
static void start_accept(struct at_state_t *at_state)
{
struct cardstate *cs = at_state->cs;
struct bc_state *bcs = at_state->bcs;
int i;
for (i = 0; i < AT_NUM; ++i) {
kfree(bcs->commands[i]);
bcs->commands[i] = NULL;
}
bcs->commands[AT_PROTO] = kmalloc(9, GFP_ATOMIC);
bcs->commands[AT_ISO] = kmalloc(9, GFP_ATOMIC);
if (!bcs->commands[AT_PROTO] || !bcs->commands[AT_ISO]) {
dev_err(at_state->cs->dev, "out of memory\n");
at_state->pending_commands |= PC_HUP;
gig_dbg(DEBUG_EVENT, "Scheduling PC_HUP");
cs->commands_pending = 1;
return;
}
snprintf(bcs->commands[AT_PROTO], 9, "^SBPR=%u\r", bcs->proto2);
snprintf(bcs->commands[AT_ISO], 9, "^SISO=%u\r", bcs->channel + 1);
at_state->pending_commands |= PC_ACCEPT;
gig_dbg(DEBUG_EVENT, "Scheduling PC_ACCEPT");
cs->commands_pending = 1;
}
static void do_start(struct cardstate *cs)
{
gigaset_free_channels(cs);
if (cs->mstate != MS_LOCKED)
schedule_init(cs, MS_INIT);
cs->isdn_up = 1;
gigaset_isdn_start(cs);
cs->waiting = 0;
wake_up(&cs->waitqueue);
}
static void finish_shutdown(struct cardstate *cs)
{
if (cs->mstate != MS_LOCKED) {
cs->mstate = MS_UNINITIALIZED;
cs->mode = M_UNKNOWN;
}
if (cs->isdn_up) {
cs->isdn_up = 0;
gigaset_isdn_stop(cs);
}
cs->cmd_result = -ENODEV;
cs->waiting = 0;
wake_up(&cs->waitqueue);
}
static void do_shutdown(struct cardstate *cs)
{
gigaset_block_channels(cs);
if (cs->mstate == MS_READY) {
cs->mstate = MS_SHUTDOWN;
cs->at_state.pending_commands |= PC_SHUTDOWN;
gig_dbg(DEBUG_EVENT, "Scheduling PC_SHUTDOWN");
cs->commands_pending = 1;
} else
finish_shutdown(cs);
}
static void do_stop(struct cardstate *cs)
{
unsigned long flags;
spin_lock_irqsave(&cs->lock, flags);
cs->connected = 0;
spin_unlock_irqrestore(&cs->lock, flags);
do_shutdown(cs);
}
static int reinit_and_retry(struct cardstate *cs, int channel)
{
int i;
if (--cs->retry_count <= 0)
return -EFAULT;
for (i = 0; i < cs->channels; ++i)
if (cs->bcs[i].at_state.cid > 0)
return -EBUSY;
if (channel < 0)
dev_warn(cs->dev,
"Could not enter cid mode. Reinit device and try again.\n");
else {
dev_warn(cs->dev,
"Could not get a call id. Reinit device and try again.\n");
cs->bcs[channel].at_state.pending_commands |= PC_CID;
}
schedule_init(cs, MS_INIT);
return 0;
}
static int at_state_invalid(struct cardstate *cs,
struct at_state_t *test_ptr)
{
unsigned long flags;
unsigned channel;
struct at_state_t *at_state;
int retval = 0;
spin_lock_irqsave(&cs->lock, flags);
if (test_ptr == &cs->at_state)
goto exit;
list_for_each_entry(at_state, &cs->temp_at_states, list)
if (at_state == test_ptr)
goto exit;
for (channel = 0; channel < cs->channels; ++channel)
if (&cs->bcs[channel].at_state == test_ptr)
goto exit;
retval = 1;
exit:
spin_unlock_irqrestore(&cs->lock, flags);
return retval;
}
static void handle_icall(struct cardstate *cs, struct bc_state *bcs,
struct at_state_t *at_state)
{
int retval;
retval = gigaset_isdn_icall(at_state);
switch (retval) {
case ICALL_ACCEPT:
break;
default:
dev_err(cs->dev, "internal error: disposition=%d\n", retval);
case ICALL_IGNORE:
case ICALL_REJECT:
at_state->pending_commands |= PC_HUP;
cs->commands_pending = 1;
break;
}
}
static int do_lock(struct cardstate *cs)
{
int mode;
int i;
switch (cs->mstate) {
case MS_UNINITIALIZED:
case MS_READY:
if (cs->cur_at_seq || !list_empty(&cs->temp_at_states) ||
cs->at_state.pending_commands)
return -EBUSY;
for (i = 0; i < cs->channels; ++i)
if (cs->bcs[i].at_state.pending_commands)
return -EBUSY;
if (gigaset_get_channels(cs) < 0)
return -EBUSY;
break;
case MS_LOCKED:
break;
default:
return -EBUSY;
}
mode = cs->mode;
cs->mstate = MS_LOCKED;
cs->mode = M_UNKNOWN;
return mode;
}
static int do_unlock(struct cardstate *cs)
{
if (cs->mstate != MS_LOCKED)
return -EINVAL;
cs->mstate = MS_UNINITIALIZED;
cs->mode = M_UNKNOWN;
gigaset_free_channels(cs);
if (cs->connected)
schedule_init(cs, MS_INIT);
return 0;
}
static void do_action(int action, struct cardstate *cs,
struct bc_state *bcs,
struct at_state_t **p_at_state, char **pp_command,
int *p_genresp, int *p_resp_code,
struct event_t *ev)
{
struct at_state_t *at_state = *p_at_state;
struct bc_state *bcs2;
unsigned long flags;
int channel;
unsigned char *s, *e;
int i;
unsigned long val;
switch (action) {
case ACT_NOTHING:
break;
case ACT_TIMEOUT:
at_state->waiting = 1;
break;
case ACT_INIT:
cs->at_state.pending_commands &= ~PC_INIT;
cs->cur_at_seq = SEQ_NONE;
cs->mode = M_UNIMODEM;
spin_lock_irqsave(&cs->lock, flags);
if (!cs->cidmode) {
spin_unlock_irqrestore(&cs->lock, flags);
gigaset_free_channels(cs);
cs->mstate = MS_READY;
break;
}
spin_unlock_irqrestore(&cs->lock, flags);
cs->at_state.pending_commands |= PC_CIDMODE;
gig_dbg(DEBUG_EVENT, "Scheduling PC_CIDMODE");
cs->commands_pending = 1;
break;
case ACT_FAILINIT:
dev_warn(cs->dev, "Could not initialize the device.\n");
cs->dle = 0;
init_failed(cs, M_UNKNOWN);
cs->cur_at_seq = SEQ_NONE;
break;
case ACT_CONFIGMODE:
init_failed(cs, M_CONFIG);
cs->cur_at_seq = SEQ_NONE;
break;
case ACT_SETDLE1:
cs->dle = 1;
cs->inbuf[0].inputstate &=
~(INS_command | INS_DLE_command);
break;
case ACT_SETDLE0:
cs->dle = 0;
cs->inbuf[0].inputstate =
(cs->inbuf[0].inputstate & ~INS_DLE_command)
| INS_command;
break;
case ACT_CMODESET:
if (cs->mstate == MS_INIT || cs->mstate == MS_RECOVER) {
gigaset_free_channels(cs);
cs->mstate = MS_READY;
}
cs->mode = M_CID;
cs->cur_at_seq = SEQ_NONE;
break;
case ACT_UMODESET:
cs->mode = M_UNIMODEM;
cs->cur_at_seq = SEQ_NONE;
break;
case ACT_FAILCMODE:
cs->cur_at_seq = SEQ_NONE;
if (cs->mstate == MS_INIT || cs->mstate == MS_RECOVER) {
init_failed(cs, M_UNKNOWN);
break;
}
if (reinit_and_retry(cs, -1) < 0)
schedule_init(cs, MS_RECOVER);
break;
case ACT_FAILUMODE:
cs->cur_at_seq = SEQ_NONE;
schedule_init(cs, MS_RECOVER);
break;
case ACT_HUPMODEM:
if (cs->connected) {
struct cmdbuf_t *cb;
cb = kmalloc(sizeof(struct cmdbuf_t) + 3, GFP_ATOMIC);
if (!cb) {
dev_err(cs->dev, "%s: out of memory\n",
__func__);
return;
}
memcpy(cb->buf, "+++", 3);
cb->len = 3;
cb->offset = 0;
cb->next = NULL;
cb->wake_tasklet = NULL;
cs->ops->write_cmd(cs, cb);
}
break;
case ACT_RING:
at_state = get_free_channel(cs, ev->parameter);
if (!at_state) {
dev_warn(cs->dev,
"RING ignored: could not allocate channel structure\n");
break;
}
at_state->ConState = 700;
for (i = 0; i < STR_NUM; ++i) {
kfree(at_state->str_var[i]);
at_state->str_var[i] = NULL;
}
at_state->int_var[VAR_ZCTP] = -1;
spin_lock_irqsave(&cs->lock, flags);
at_state->timer_expires = RING_TIMEOUT;
at_state->timer_active = 1;
spin_unlock_irqrestore(&cs->lock, flags);
break;
case ACT_ICALL:
handle_icall(cs, bcs, at_state);
break;
case ACT_FAILSDOWN:
dev_warn(cs->dev, "Could not shut down the device.\n");
case ACT_FAKESDOWN:
case ACT_SDOWN:
cs->cur_at_seq = SEQ_NONE;
finish_shutdown(cs);
break;
case ACT_CONNECT:
if (cs->onechannel) {
at_state->pending_commands |= PC_DLE1;
cs->commands_pending = 1;
break;
}
bcs->chstate |= CHS_D_UP;
gigaset_isdn_connD(bcs);
cs->ops->init_bchannel(bcs);
break;
case ACT_DLE1:
cs->cur_at_seq = SEQ_NONE;
bcs = cs->bcs + cs->curchannel;
bcs->chstate |= CHS_D_UP;
gigaset_isdn_connD(bcs);
cs->ops->init_bchannel(bcs);
break;
case ACT_FAKEHUP:
at_state->int_var[VAR_ZSAU] = ZSAU_NULL;
case ACT_DISCONNECT:
cs->cur_at_seq = SEQ_NONE;
at_state->cid = -1;
if (!bcs) {
disconnect_nobc(p_at_state, cs);
} else if (cs->onechannel && cs->dle) {
at_state->pending_commands |= PC_DLE0;
cs->commands_pending = 1;
} else {
disconnect_bc(at_state, cs, bcs);
}
break;
case ACT_FAKEDLE0:
at_state->int_var[VAR_ZDLE] = 0;
cs->dle = 0;
case ACT_DLE0:
cs->cur_at_seq = SEQ_NONE;
bcs2 = cs->bcs + cs->curchannel;
disconnect_bc(&bcs2->at_state, cs, bcs2);
break;
case ACT_ABORTHUP:
cs->cur_at_seq = SEQ_NONE;
dev_warn(cs->dev, "Could not hang up.\n");
at_state->cid = -1;
if (!bcs)
disconnect_nobc(p_at_state, cs);
else if (cs->onechannel)
at_state->pending_commands |= PC_DLE0;
else
disconnect_bc(at_state, cs, bcs);
schedule_init(cs, MS_RECOVER);
break;
case ACT_FAILDLE0:
cs->cur_at_seq = SEQ_NONE;
dev_warn(cs->dev, "Error leaving DLE mode.\n");
cs->dle = 0;
bcs2 = cs->bcs + cs->curchannel;
disconnect_bc(&bcs2->at_state, cs, bcs2);
schedule_init(cs, MS_RECOVER);
break;
case ACT_FAILDLE1:
cs->cur_at_seq = SEQ_NONE;
dev_warn(cs->dev,
"Could not enter DLE mode. Trying to hang up.\n");
channel = cs->curchannel;
cs->bcs[channel].at_state.pending_commands |= PC_HUP;
cs->commands_pending = 1;
break;
case ACT_CID:
cs->cur_at_seq = SEQ_NONE;
channel = cs->curchannel;
if (ev->parameter > 0 && ev->parameter <= 65535) {
cs->bcs[channel].at_state.cid = ev->parameter;
cs->bcs[channel].at_state.pending_commands |=
PC_DIAL;
cs->commands_pending = 1;
break;
}
case ACT_FAILCID:
cs->cur_at_seq = SEQ_NONE;
channel = cs->curchannel;
if (reinit_and_retry(cs, channel) < 0) {
dev_warn(cs->dev,
"Could not get a call ID. Cannot dial.\n");
bcs2 = cs->bcs + channel;
disconnect_bc(&bcs2->at_state, cs, bcs2);
}
break;
case ACT_ABORTCID:
cs->cur_at_seq = SEQ_NONE;
bcs2 = cs->bcs + cs->curchannel;
disconnect_bc(&bcs2->at_state, cs, bcs2);
break;
case ACT_DIALING:
case ACT_ACCEPTED:
cs->cur_at_seq = SEQ_NONE;
break;
case ACT_ABORTACCEPT:
if (bcs)
disconnect_bc(at_state, cs, bcs);
else
disconnect_nobc(p_at_state, cs);
break;
case ACT_ABORTDIAL:
cs->cur_at_seq = SEQ_NONE;
at_state->pending_commands |= PC_HUP;
cs->commands_pending = 1;
break;
case ACT_REMOTEREJECT:
case ACT_CONNTIMEOUT:
case ACT_REMOTEHUP:
at_state->pending_commands |= PC_HUP;
cs->commands_pending = 1;
break;
case ACT_GETSTRING:
at_state->getstring = 1;
break;
case ACT_SETVER:
if (!ev->ptr) {
*p_genresp = 1;
*p_resp_code = RSP_ERROR;
break;
}
s = ev->ptr;
if (!strcmp(s, "OK")) {
*p_genresp = 1;
*p_resp_code = RSP_NONE;
break;
}
for (i = 0; i < 4; ++i) {
val = simple_strtoul(s, (char **) &e, 10);
if (val > INT_MAX || e == s)
break;
if (i == 3) {
if (*e)
break;
} else if (*e != '.')
break;
else
s = e + 1;
cs->fwver[i] = val;
}
if (i != 4) {
*p_genresp = 1;
*p_resp_code = RSP_ERROR;
break;
}
cs->gotfwver = 0;
break;
case ACT_GOTVER:
if (cs->gotfwver == 0) {
cs->gotfwver = 1;
gig_dbg(DEBUG_EVENT,
"firmware version %02d.%03d.%02d.%02d",
cs->fwver[0], cs->fwver[1],
cs->fwver[2], cs->fwver[3]);
break;
}
case ACT_FAILVER:
cs->gotfwver = -1;
dev_err(cs->dev, "could not read firmware version.\n");
break;
case ACT_ERROR:
gig_dbg(DEBUG_ANY, "%s: ERROR response in ConState %d",
__func__, at_state->ConState);
cs->cur_at_seq = SEQ_NONE;
break;
case ACT_DEBUG:
gig_dbg(DEBUG_ANY, "%s: resp_code %d in ConState %d",
__func__, ev->type, at_state->ConState);
break;
case ACT_WARN:
dev_warn(cs->dev, "%s: resp_code %d in ConState %d!\n",
__func__, ev->type, at_state->ConState);
break;
case ACT_ZCAU:
dev_warn(cs->dev, "cause code %04x in connection state %d.\n",
ev->parameter, at_state->ConState);
break;
case ACT_DIAL:
if (!ev->ptr) {
*p_genresp = 1;
*p_resp_code = RSP_ERROR;
break;
}
start_dial(at_state, ev->ptr, ev->parameter);
break;
case ACT_ACCEPT:
start_accept(at_state);
break;
case ACT_HUP:
at_state->pending_commands |= PC_HUP;
gig_dbg(DEBUG_EVENT, "Scheduling PC_HUP");
cs->commands_pending = 1;
break;
case ACT_STOP:
do_stop(cs);
break;
case ACT_START:
do_start(cs);
break;
case ACT_IF_LOCK:
cs->cmd_result = ev->parameter ? do_lock(cs) : do_unlock(cs);
cs->waiting = 0;
wake_up(&cs->waitqueue);
break;
case ACT_IF_VER:
if (ev->parameter != 0)
cs->cmd_result = -EINVAL;
else if (cs->gotfwver != 1) {
cs->cmd_result = -ENOENT;
} else {
memcpy(ev->arg, cs->fwver, sizeof cs->fwver);
cs->cmd_result = 0;
}
cs->waiting = 0;
wake_up(&cs->waitqueue);
break;
case ACT_PROC_CIDMODE:
spin_lock_irqsave(&cs->lock, flags);
if (ev->parameter != cs->cidmode) {
cs->cidmode = ev->parameter;
if (ev->parameter) {
cs->at_state.pending_commands |= PC_CIDMODE;
gig_dbg(DEBUG_EVENT, "Scheduling PC_CIDMODE");
} else {
cs->at_state.pending_commands |= PC_UMMODE;
gig_dbg(DEBUG_EVENT, "Scheduling PC_UMMODE");
}
cs->commands_pending = 1;
}
spin_unlock_irqrestore(&cs->lock, flags);
cs->waiting = 0;
wake_up(&cs->waitqueue);
break;
case ACT_NOTIFY_BC_DOWN:
bchannel_down(bcs);
break;
case ACT_NOTIFY_BC_UP:
bchannel_up(bcs);
break;
case ACT_SHUTDOWN:
do_shutdown(cs);
break;
default:
if (action >= ACT_CMD && action < ACT_CMD + AT_NUM) {
*pp_command = at_state->bcs->commands[action - ACT_CMD];
if (!*pp_command) {
*p_genresp = 1;
*p_resp_code = RSP_NULL;
}
} else
dev_err(cs->dev, "%s: action==%d!\n", __func__, action);
}
}
static void process_event(struct cardstate *cs, struct event_t *ev)
{
struct bc_state *bcs;
char *p_command = NULL;
struct reply_t *rep;
int rcode;
int genresp = 0;
int resp_code = RSP_ERROR;
struct at_state_t *at_state;
int index;
int curact;
unsigned long flags;
if (ev->cid >= 0) {
at_state = at_state_from_cid(cs, ev->cid);
if (!at_state) {
gig_dbg(DEBUG_EVENT, "event %d for invalid cid %d",
ev->type, ev->cid);
gigaset_add_event(cs, &cs->at_state, RSP_WRONG_CID,
NULL, 0, NULL);
return;
}
} else {
at_state = ev->at_state;
if (at_state_invalid(cs, at_state)) {
gig_dbg(DEBUG_EVENT, "event for invalid at_state %p",
at_state);
return;
}
}
gig_dbg(DEBUG_EVENT, "connection state %d, event %d",
at_state->ConState, ev->type);
bcs = at_state->bcs;
rep = at_state->replystruct;
spin_lock_irqsave(&cs->lock, flags);
if (ev->type == EV_TIMEOUT) {
if (ev->parameter != at_state->timer_index
|| !at_state->timer_active) {
ev->type = RSP_NONE;
gig_dbg(DEBUG_EVENT, "old timeout");
} else {
if (at_state->waiting)
gig_dbg(DEBUG_EVENT, "stopped waiting");
else
gig_dbg(DEBUG_EVENT, "timeout occurred");
}
}
spin_unlock_irqrestore(&cs->lock, flags);
if (ev->type >= RSP_VAR && ev->type < RSP_VAR + VAR_NUM) {
index = ev->type - RSP_VAR;
at_state->int_var[index] = ev->parameter;
} else if (ev->type >= RSP_STR && ev->type < RSP_STR + STR_NUM) {
index = ev->type - RSP_STR;
kfree(at_state->str_var[index]);
at_state->str_var[index] = ev->ptr;
ev->ptr = NULL;
}
if (ev->type == EV_TIMEOUT || ev->type == RSP_STRING)
at_state->getstring = 0;
for (;; rep++) {
rcode = rep->resp_code;
if (rcode == RSP_LAST) {
dev_warn(cs->dev, "%s: rcode=RSP_LAST: "
"resp_code %d in ConState %d!\n",
__func__, ev->type, at_state->ConState);
return;
}
if ((rcode == RSP_ANY || rcode == ev->type)
&& ((int) at_state->ConState >= rep->min_ConState)
&& (rep->max_ConState < 0
|| (int) at_state->ConState <= rep->max_ConState)
&& (rep->parameter < 0 || rep->parameter == ev->parameter))
break;
}
p_command = rep->command;
at_state->waiting = 0;
for (curact = 0; curact < MAXACT; ++curact) {
do_action(rep->action[curact], cs, bcs, &at_state, &p_command,
&genresp, &resp_code, ev);
if (!at_state)
return;
}
if (rep->new_ConState >= 0)
at_state->ConState = rep->new_ConState;
if (genresp) {
spin_lock_irqsave(&cs->lock, flags);
at_state->timer_expires = 0;
at_state->timer_active = 0;
spin_unlock_irqrestore(&cs->lock, flags);
gigaset_add_event(cs, at_state, resp_code, NULL, 0, NULL);
} else {
if (p_command) {
if (cs->connected)
send_command(cs, p_command, at_state);
else
gigaset_add_event(cs, at_state, RSP_NODEV,
NULL, 0, NULL);
}
spin_lock_irqsave(&cs->lock, flags);
if (!rep->timeout) {
at_state->timer_expires = 0;
at_state->timer_active = 0;
} else if (rep->timeout > 0) {
at_state->timer_expires = rep->timeout * 10;
at_state->timer_active = 1;
++at_state->timer_index;
}
spin_unlock_irqrestore(&cs->lock, flags);
}
}
static void schedule_sequence(struct cardstate *cs,
struct at_state_t *at_state, int sequence)
{
cs->cur_at_seq = sequence;
gigaset_add_event(cs, at_state, RSP_INIT, NULL, sequence, NULL);
}
static void process_command_flags(struct cardstate *cs)
{
struct at_state_t *at_state = NULL;
struct bc_state *bcs;
int i;
int sequence;
unsigned long flags;
cs->commands_pending = 0;
if (cs->cur_at_seq) {
gig_dbg(DEBUG_EVENT, "not searching scheduled commands: busy");
return;
}
gig_dbg(DEBUG_EVENT, "searching scheduled commands");
sequence = SEQ_NONE;
if (cs->at_state.pending_commands & PC_SHUTDOWN) {
cs->at_state.pending_commands &= ~PC_CIDMODE;
for (i = 0; i < cs->channels; ++i) {
bcs = cs->bcs + i;
at_state = &bcs->at_state;
at_state->pending_commands &=
~(PC_DLE1 | PC_ACCEPT | PC_DIAL);
if (at_state->cid > 0)
at_state->pending_commands |= PC_HUP;
if (at_state->pending_commands & PC_CID) {
at_state->pending_commands |= PC_NOCID;
at_state->pending_commands &= ~PC_CID;
}
}
}
if (cs->at_state.pending_commands & PC_INIT) {
cs->at_state.pending_commands &= ~PC_CIDMODE;
for (i = 0; i < cs->channels; ++i) {
bcs = cs->bcs + i;
at_state = &bcs->at_state;
at_state->pending_commands &=
~(PC_DLE1 | PC_ACCEPT | PC_DIAL);
if (at_state->cid > 0)
at_state->pending_commands |= PC_HUP;
if (cs->mstate == MS_RECOVER) {
if (at_state->pending_commands & PC_CID) {
at_state->pending_commands |= PC_NOCID;
at_state->pending_commands &= ~PC_CID;
}
}
}
}
spin_lock_irqsave(&cs->lock, flags);
if (cs->at_state.pending_commands == PC_UMMODE
&& !cs->cidmode
&& list_empty(&cs->temp_at_states)
&& cs->mode == M_CID) {
sequence = SEQ_UMMODE;
at_state = &cs->at_state;
for (i = 0; i < cs->channels; ++i) {
bcs = cs->bcs + i;
if (bcs->at_state.pending_commands ||
bcs->at_state.cid > 0) {
sequence = SEQ_NONE;
break;
}
}
}
spin_unlock_irqrestore(&cs->lock, flags);
cs->at_state.pending_commands &= ~PC_UMMODE;
if (sequence != SEQ_NONE) {
schedule_sequence(cs, at_state, sequence);
return;
}
for (i = 0; i < cs->channels; ++i) {
bcs = cs->bcs + i;
if (bcs->at_state.pending_commands & PC_HUP) {
if (cs->dle) {
cs->curchannel = bcs->channel;
schedule_sequence(cs, &cs->at_state, SEQ_DLE0);
return;
}
bcs->at_state.pending_commands &= ~PC_HUP;
if (bcs->at_state.pending_commands & PC_CID) {
bcs->at_state.pending_commands |= PC_NOCID;
bcs->at_state.pending_commands &= ~PC_CID;
} else {
schedule_sequence(cs, &bcs->at_state, SEQ_HUP);
return;
}
}
if (bcs->at_state.pending_commands & PC_NOCID) {
bcs->at_state.pending_commands &= ~PC_NOCID;
cs->curchannel = bcs->channel;
schedule_sequence(cs, &cs->at_state, SEQ_NOCID);
return;
} else if (bcs->at_state.pending_commands & PC_DLE0) {
bcs->at_state.pending_commands &= ~PC_DLE0;
cs->curchannel = bcs->channel;
schedule_sequence(cs, &cs->at_state, SEQ_DLE0);
return;
}
}
list_for_each_entry(at_state, &cs->temp_at_states, list)
if (at_state->pending_commands & PC_HUP) {
at_state->pending_commands &= ~PC_HUP;
schedule_sequence(cs, at_state, SEQ_HUP);
return;
}
if (cs->at_state.pending_commands & PC_INIT) {
cs->at_state.pending_commands &= ~PC_INIT;
cs->dle = 0;
cs->inbuf->inputstate = INS_command;
schedule_sequence(cs, &cs->at_state, SEQ_INIT);
return;
}
if (cs->at_state.pending_commands & PC_SHUTDOWN) {
cs->at_state.pending_commands &= ~PC_SHUTDOWN;
schedule_sequence(cs, &cs->at_state, SEQ_SHUTDOWN);
return;
}
if (cs->at_state.pending_commands & PC_CIDMODE) {
cs->at_state.pending_commands &= ~PC_CIDMODE;
if (cs->mode == M_UNIMODEM) {
cs->retry_count = 1;
schedule_sequence(cs, &cs->at_state, SEQ_CIDMODE);
return;
}
}
for (i = 0; i < cs->channels; ++i) {
bcs = cs->bcs + i;
if (bcs->at_state.pending_commands & PC_DLE1) {
bcs->at_state.pending_commands &= ~PC_DLE1;
cs->curchannel = bcs->channel;
schedule_sequence(cs, &cs->at_state, SEQ_DLE1);
return;
}
if (bcs->at_state.pending_commands & PC_ACCEPT) {
bcs->at_state.pending_commands &= ~PC_ACCEPT;
schedule_sequence(cs, &bcs->at_state, SEQ_ACCEPT);
return;
}
if (bcs->at_state.pending_commands & PC_DIAL) {
bcs->at_state.pending_commands &= ~PC_DIAL;
schedule_sequence(cs, &bcs->at_state, SEQ_DIAL);
return;
}
if (bcs->at_state.pending_commands & PC_CID) {
switch (cs->mode) {
case M_UNIMODEM:
cs->at_state.pending_commands |= PC_CIDMODE;
gig_dbg(DEBUG_EVENT, "Scheduling PC_CIDMODE");
cs->commands_pending = 1;
return;
case M_UNKNOWN:
schedule_init(cs, MS_INIT);
return;
}
bcs->at_state.pending_commands &= ~PC_CID;
cs->curchannel = bcs->channel;
cs->retry_count = 2;
schedule_sequence(cs, &cs->at_state, SEQ_CID);
return;
}
}
}
static void process_events(struct cardstate *cs)
{
struct event_t *ev;
unsigned head, tail;
int i;
int check_flags = 0;
int was_busy;
unsigned long flags;
spin_lock_irqsave(&cs->ev_lock, flags);
head = cs->ev_head;
for (i = 0; i < 2 * MAX_EVENTS; ++i) {
tail = cs->ev_tail;
if (tail == head) {
if (!check_flags && !cs->commands_pending)
break;
check_flags = 0;
spin_unlock_irqrestore(&cs->ev_lock, flags);
process_command_flags(cs);
spin_lock_irqsave(&cs->ev_lock, flags);
tail = cs->ev_tail;
if (tail == head) {
if (!cs->commands_pending)
break;
continue;
}
}
ev = cs->events + head;
was_busy = cs->cur_at_seq != SEQ_NONE;
spin_unlock_irqrestore(&cs->ev_lock, flags);
process_event(cs, ev);
spin_lock_irqsave(&cs->ev_lock, flags);
kfree(ev->ptr);
ev->ptr = NULL;
if (was_busy && cs->cur_at_seq == SEQ_NONE)
check_flags = 1;
head = (head + 1) % MAX_EVENTS;
cs->ev_head = head;
}
spin_unlock_irqrestore(&cs->ev_lock, flags);
if (i == 2 * MAX_EVENTS) {
dev_err(cs->dev,
"infinite loop in process_events; aborting.\n");
}
}
void gigaset_handle_event(unsigned long data)
{
struct cardstate *cs = (struct cardstate *) data;
if (cs->inbuf->head != cs->inbuf->tail) {
gig_dbg(DEBUG_INTR, "processing new data");
cs->ops->handle_input(cs->inbuf);
}
process_events(cs);
}
