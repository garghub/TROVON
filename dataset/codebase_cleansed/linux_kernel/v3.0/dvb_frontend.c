static void dvb_frontend_add_event(struct dvb_frontend *fe, fe_status_t status)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_fe_events *events = &fepriv->events;
struct dvb_frontend_event *e;
int wp;
dprintk ("%s\n", __func__);
if (mutex_lock_interruptible (&events->mtx))
return;
wp = (events->eventw + 1) % MAX_EVENT;
if (wp == events->eventr) {
events->overflow = 1;
events->eventr = (events->eventr + 1) % MAX_EVENT;
}
e = &events->events[events->eventw];
if (status & FE_HAS_LOCK)
if (fe->ops.get_frontend)
fe->ops.get_frontend(fe, &fepriv->parameters_out);
e->parameters = fepriv->parameters_out;
events->eventw = wp;
mutex_unlock(&events->mtx);
e->status = status;
wake_up_interruptible (&events->wait_queue);
}
static int dvb_frontend_get_event(struct dvb_frontend *fe,
struct dvb_frontend_event *event, int flags)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_fe_events *events = &fepriv->events;
dprintk ("%s\n", __func__);
if (events->overflow) {
events->overflow = 0;
return -EOVERFLOW;
}
if (events->eventw == events->eventr) {
int ret;
if (flags & O_NONBLOCK)
return -EWOULDBLOCK;
up(&fepriv->sem);
ret = wait_event_interruptible (events->wait_queue,
events->eventw != events->eventr);
if (down_interruptible (&fepriv->sem))
return -ERESTARTSYS;
if (ret < 0)
return ret;
}
if (mutex_lock_interruptible (&events->mtx))
return -ERESTARTSYS;
memcpy (event, &events->events[events->eventr],
sizeof(struct dvb_frontend_event));
events->eventr = (events->eventr + 1) % MAX_EVENT;
mutex_unlock(&events->mtx);
return 0;
}
static void dvb_frontend_init(struct dvb_frontend *fe)
{
dprintk ("DVB: initialising adapter %i frontend %i (%s)...\n",
fe->dvb->num,
fe->id,
fe->ops.info.name);
if (fe->ops.init)
fe->ops.init(fe);
if (fe->ops.tuner_ops.init) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.init(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
}
void dvb_frontend_reinitialise(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
fepriv->reinitialise = 1;
dvb_frontend_wakeup(fe);
}
static void dvb_frontend_swzigzag_update_delay(struct dvb_frontend_private *fepriv, int locked)
{
int q2;
dprintk ("%s\n", __func__);
if (locked)
(fepriv->quality) = (fepriv->quality * 220 + 36*256) / 256;
else
(fepriv->quality) = (fepriv->quality * 220 + 0) / 256;
q2 = fepriv->quality - 128;
q2 *= q2;
fepriv->delay = fepriv->min_delay + q2 * HZ / (128*128);
}
static int dvb_frontend_swzigzag_autotune(struct dvb_frontend *fe, int check_wrapped)
{
int autoinversion;
int ready = 0;
int fe_set_err = 0;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
int original_inversion = fepriv->parameters_in.inversion;
u32 original_frequency = fepriv->parameters_in.frequency;
autoinversion = ((!(fe->ops.info.caps & FE_CAN_INVERSION_AUTO)) &&
(fepriv->parameters_in.inversion == INVERSION_AUTO));
while(!ready) {
fepriv->lnb_drift = fepriv->auto_step * fepriv->step_size;
if (fepriv->lnb_drift > fepriv->max_drift) {
fepriv->auto_step = 0;
fepriv->auto_sub_step = 0;
fepriv->lnb_drift = 0;
}
switch(fepriv->auto_sub_step) {
case 0:
ready = 1;
break;
case 1:
if (!autoinversion) break;
fepriv->inversion = (fepriv->inversion == INVERSION_OFF) ? INVERSION_ON : INVERSION_OFF;
ready = 1;
break;
case 2:
if (fepriv->lnb_drift == 0) break;
fepriv->lnb_drift = -fepriv->lnb_drift;
ready = 1;
break;
case 3:
if (fepriv->lnb_drift == 0) break;
if (!autoinversion) break;
fepriv->inversion = (fepriv->inversion == INVERSION_OFF) ? INVERSION_ON : INVERSION_OFF;
fepriv->lnb_drift = -fepriv->lnb_drift;
ready = 1;
break;
default:
fepriv->auto_step++;
fepriv->auto_sub_step = -1;
break;
}
if (!ready) fepriv->auto_sub_step++;
}
if ((fepriv->auto_step == fepriv->started_auto_step) &&
(fepriv->auto_sub_step == 0) && check_wrapped) {
return 1;
}
dprintk("%s: drift:%i inversion:%i auto_step:%i "
"auto_sub_step:%i started_auto_step:%i\n",
__func__, fepriv->lnb_drift, fepriv->inversion,
fepriv->auto_step, fepriv->auto_sub_step, fepriv->started_auto_step);
fepriv->parameters_in.frequency += fepriv->lnb_drift;
if (autoinversion)
fepriv->parameters_in.inversion = fepriv->inversion;
if (fe->ops.set_frontend)
fe_set_err = fe->ops.set_frontend(fe, &fepriv->parameters_in);
fepriv->parameters_out = fepriv->parameters_in;
if (fe_set_err < 0) {
fepriv->state = FESTATE_ERROR;
return fe_set_err;
}
fepriv->parameters_in.frequency = original_frequency;
fepriv->parameters_in.inversion = original_inversion;
fepriv->auto_sub_step++;
return 0;
}
static void dvb_frontend_swzigzag(struct dvb_frontend *fe)
{
fe_status_t s = 0;
int retval = 0;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
if (fepriv->state & FESTATE_IDLE) {
fepriv->delay = 3*HZ;
fepriv->quality = 0;
return;
}
if (fepriv->tune_mode_flags & FE_TUNE_MODE_ONESHOT) {
if (fepriv->state & FESTATE_RETUNE) {
if (fe->ops.set_frontend)
retval = fe->ops.set_frontend(fe,
&fepriv->parameters_in);
fepriv->parameters_out = fepriv->parameters_in;
if (retval < 0)
fepriv->state = FESTATE_ERROR;
else
fepriv->state = FESTATE_TUNED;
}
fepriv->delay = 3*HZ;
fepriv->quality = 0;
return;
}
if (fepriv->state & FESTATE_RETUNE) {
s = 0;
} else {
if (fe->ops.read_status)
fe->ops.read_status(fe, &s);
if (s != fepriv->status) {
dvb_frontend_add_event(fe, s);
fepriv->status = s;
}
}
if ((fepriv->state & FESTATE_WAITFORLOCK) && (s & FE_HAS_LOCK)) {
dvb_frontend_swzigzag_update_delay(fepriv, s & FE_HAS_LOCK);
fepriv->state = FESTATE_TUNED;
if ((!(fe->ops.info.caps & FE_CAN_INVERSION_AUTO)) &&
(fepriv->parameters_in.inversion == INVERSION_AUTO)) {
fepriv->parameters_in.inversion = fepriv->inversion;
}
return;
}
if (fepriv->state & FESTATE_TUNED) {
dvb_frontend_swzigzag_update_delay(fepriv, s & FE_HAS_LOCK);
if (s & FE_HAS_LOCK) {
return;
} else {
fepriv->state = FESTATE_ZIGZAG_FAST;
fepriv->started_auto_step = fepriv->auto_step;
fepriv->check_wrapped = 0;
}
}
if ((fepriv->state & FESTATE_LOSTLOCK) &&
(fe->ops.info.caps & FE_CAN_RECOVER) && (fepriv->max_drift == 0)) {
dvb_frontend_swzigzag_update_delay(fepriv, s & FE_HAS_LOCK);
return;
}
if (fepriv->state & FESTATE_DISEQC) {
dvb_frontend_swzigzag_update_delay(fepriv, s & FE_HAS_LOCK);
return;
}
if (fepriv->state & FESTATE_RETUNE) {
fepriv->lnb_drift = 0;
fepriv->auto_step = 0;
fepriv->auto_sub_step = 0;
fepriv->started_auto_step = 0;
fepriv->check_wrapped = 0;
}
if ((fepriv->state & FESTATE_SEARCHING_FAST) || (fepriv->state & FESTATE_RETUNE)) {
fepriv->delay = fepriv->min_delay;
retval = dvb_frontend_swzigzag_autotune(fe,
fepriv->check_wrapped);
if (retval < 0) {
return;
} else if (retval) {
fepriv->state = FESTATE_SEARCHING_SLOW;
fepriv->started_auto_step = fepriv->auto_step;
return;
}
fepriv->check_wrapped = 1;
if (fepriv->state & FESTATE_RETUNE) {
fepriv->state = FESTATE_TUNING_FAST;
}
}
if (fepriv->state & FESTATE_SEARCHING_SLOW) {
dvb_frontend_swzigzag_update_delay(fepriv, s & FE_HAS_LOCK);
dvb_frontend_swzigzag_autotune(fe, 0);
}
}
static int dvb_frontend_is_exiting(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
if (fepriv->exit != DVB_FE_NO_EXIT)
return 1;
if (fepriv->dvbdev->writers == 1)
if (time_after(jiffies, fepriv->release_jiffies +
dvb_shutdown_timeout * HZ))
return 1;
return 0;
}
static int dvb_frontend_should_wakeup(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
if (fepriv->wakeup) {
fepriv->wakeup = 0;
return 1;
}
return dvb_frontend_is_exiting(fe);
}
static void dvb_frontend_wakeup(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
fepriv->wakeup = 1;
wake_up_interruptible(&fepriv->wait_queue);
}
static int dvb_frontend_thread(void *data)
{
struct dvb_frontend *fe = data;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
unsigned long timeout;
fe_status_t s;
enum dvbfe_algo algo;
struct dvb_frontend_parameters *params;
dprintk("%s\n", __func__);
fepriv->check_wrapped = 0;
fepriv->quality = 0;
fepriv->delay = 3*HZ;
fepriv->status = 0;
fepriv->wakeup = 0;
fepriv->reinitialise = 0;
dvb_frontend_init(fe);
set_freezable();
while (1) {
up(&fepriv->sem);
restart:
timeout = wait_event_interruptible_timeout(fepriv->wait_queue,
dvb_frontend_should_wakeup(fe) || kthread_should_stop()
|| freezing(current),
fepriv->delay);
if (kthread_should_stop() || dvb_frontend_is_exiting(fe)) {
fepriv->exit = DVB_FE_NORMAL_EXIT;
break;
}
if (try_to_freeze())
goto restart;
if (down_interruptible(&fepriv->sem))
break;
if (fepriv->reinitialise) {
dvb_frontend_init(fe);
if (fepriv->tone != -1) {
fe->ops.set_tone(fe, fepriv->tone);
}
if (fepriv->voltage != -1) {
fe->ops.set_voltage(fe, fepriv->voltage);
}
fepriv->reinitialise = 0;
}
if (fe->ops.get_frontend_algo) {
algo = fe->ops.get_frontend_algo(fe);
switch (algo) {
case DVBFE_ALGO_HW:
dprintk("%s: Frontend ALGO = DVBFE_ALGO_HW\n", __func__);
params = NULL;
if (fepriv->state & FESTATE_RETUNE) {
dprintk("%s: Retune requested, FESTATE_RETUNE\n", __func__);
params = &fepriv->parameters_in;
fepriv->state = FESTATE_TUNED;
}
if (fe->ops.tune)
fe->ops.tune(fe, params, fepriv->tune_mode_flags, &fepriv->delay, &s);
if (params)
fepriv->parameters_out = *params;
if (s != fepriv->status && !(fepriv->tune_mode_flags & FE_TUNE_MODE_ONESHOT)) {
dprintk("%s: state changed, adding current state\n", __func__);
dvb_frontend_add_event(fe, s);
fepriv->status = s;
}
break;
case DVBFE_ALGO_SW:
dprintk("%s: Frontend ALGO = DVBFE_ALGO_SW\n", __func__);
dvb_frontend_swzigzag(fe);
break;
case DVBFE_ALGO_CUSTOM:
dprintk("%s: Frontend ALGO = DVBFE_ALGO_CUSTOM, state=%d\n", __func__, fepriv->state);
if (fepriv->state & FESTATE_RETUNE) {
dprintk("%s: Retune requested, FESTAT_RETUNE\n", __func__);
fepriv->state = FESTATE_TUNED;
}
if (fepriv->algo_status & DVBFE_ALGO_SEARCH_AGAIN) {
if (fe->ops.search) {
fepriv->algo_status = fe->ops.search(fe, &fepriv->parameters_in);
} else {
fepriv->algo_status &= ~DVBFE_ALGO_SEARCH_AGAIN;
}
}
if (fepriv->algo_status == DVBFE_ALGO_SEARCH_SUCCESS) {
if (fe->ops.track)
fe->ops.track(fe, &fepriv->parameters_in);
} else {
fepriv->algo_status |= DVBFE_ALGO_SEARCH_AGAIN;
fepriv->delay = HZ / 2;
}
fepriv->parameters_out = fepriv->parameters_in;
fe->ops.read_status(fe, &s);
if (s != fepriv->status) {
dvb_frontend_add_event(fe, s);
fepriv->status = s;
if (!(s & FE_HAS_LOCK)) {
fepriv->delay = HZ / 10;
fepriv->algo_status |= DVBFE_ALGO_SEARCH_AGAIN;
} else {
fepriv->delay = 60 * HZ;
}
}
break;
default:
dprintk("%s: UNDEFINED ALGO !\n", __func__);
break;
}
} else {
dvb_frontend_swzigzag(fe);
}
}
if (dvb_powerdown_on_sleep) {
if (fe->ops.set_voltage)
fe->ops.set_voltage(fe, SEC_VOLTAGE_OFF);
if (fe->ops.tuner_ops.sleep) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.sleep(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
if (fe->ops.sleep)
fe->ops.sleep(fe);
}
fepriv->thread = NULL;
if (kthread_should_stop())
fepriv->exit = DVB_FE_DEVICE_REMOVED;
else
fepriv->exit = DVB_FE_NO_EXIT;
mb();
dvb_frontend_wakeup(fe);
return 0;
}
static void dvb_frontend_stop(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dprintk ("%s\n", __func__);
fepriv->exit = DVB_FE_NORMAL_EXIT;
mb();
if (!fepriv->thread)
return;
kthread_stop(fepriv->thread);
sema_init(&fepriv->sem, 1);
fepriv->state = FESTATE_IDLE;
if (fepriv->thread)
printk("dvb_frontend_stop: warning: thread %p won't exit\n",
fepriv->thread);
}
s32 timeval_usec_diff(struct timeval lasttime, struct timeval curtime)
{
return ((curtime.tv_usec < lasttime.tv_usec) ?
1000000 - lasttime.tv_usec + curtime.tv_usec :
curtime.tv_usec - lasttime.tv_usec);
}
static inline void timeval_usec_add(struct timeval *curtime, u32 add_usec)
{
curtime->tv_usec += add_usec;
if (curtime->tv_usec >= 1000000) {
curtime->tv_usec -= 1000000;
curtime->tv_sec++;
}
}
void dvb_frontend_sleep_until(struct timeval *waketime, u32 add_usec)
{
struct timeval lasttime;
s32 delta, newdelta;
timeval_usec_add(waketime, add_usec);
do_gettimeofday(&lasttime);
delta = timeval_usec_diff(lasttime, *waketime);
if (delta > 2500) {
msleep((delta - 1500) / 1000);
do_gettimeofday(&lasttime);
newdelta = timeval_usec_diff(lasttime, *waketime);
delta = (newdelta > delta) ? 0 : newdelta;
}
if (delta > 0)
udelay(delta);
}
static int dvb_frontend_start(struct dvb_frontend *fe)
{
int ret;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct task_struct *fe_thread;
dprintk ("%s\n", __func__);
if (fepriv->thread) {
if (fepriv->exit == DVB_FE_NO_EXIT)
return 0;
else
dvb_frontend_stop (fe);
}
if (signal_pending(current))
return -EINTR;
if (down_interruptible (&fepriv->sem))
return -EINTR;
fepriv->state = FESTATE_IDLE;
fepriv->exit = DVB_FE_NO_EXIT;
fepriv->thread = NULL;
mb();
fe_thread = kthread_run(dvb_frontend_thread, fe,
"kdvb-ad-%i-fe-%i", fe->dvb->num,fe->id);
if (IS_ERR(fe_thread)) {
ret = PTR_ERR(fe_thread);
printk("dvb_frontend_start: failed to start kthread (%d)\n", ret);
up(&fepriv->sem);
return ret;
}
fepriv->thread = fe_thread;
return 0;
}
static void dvb_frontend_get_frequency_limits(struct dvb_frontend *fe,
u32 *freq_min, u32 *freq_max)
{
*freq_min = max(fe->ops.info.frequency_min, fe->ops.tuner_ops.info.frequency_min);
if (fe->ops.info.frequency_max == 0)
*freq_max = fe->ops.tuner_ops.info.frequency_max;
else if (fe->ops.tuner_ops.info.frequency_max == 0)
*freq_max = fe->ops.info.frequency_max;
else
*freq_max = min(fe->ops.info.frequency_max, fe->ops.tuner_ops.info.frequency_max);
if (*freq_min == 0 || *freq_max == 0)
printk(KERN_WARNING "DVB: adapter %i frontend %u frequency limits undefined - fix the driver\n",
fe->dvb->num,fe->id);
}
static int dvb_frontend_check_parameters(struct dvb_frontend *fe,
struct dvb_frontend_parameters *parms)
{
u32 freq_min;
u32 freq_max;
dvb_frontend_get_frequency_limits(fe, &freq_min, &freq_max);
if ((freq_min && parms->frequency < freq_min) ||
(freq_max && parms->frequency > freq_max)) {
printk(KERN_WARNING "DVB: adapter %i frontend %i frequency %u out of range (%u..%u)\n",
fe->dvb->num, fe->id, parms->frequency, freq_min, freq_max);
return -EINVAL;
}
if (fe->ops.info.type == FE_QPSK) {
if ((fe->ops.info.symbol_rate_min &&
parms->u.qpsk.symbol_rate < fe->ops.info.symbol_rate_min) ||
(fe->ops.info.symbol_rate_max &&
parms->u.qpsk.symbol_rate > fe->ops.info.symbol_rate_max)) {
printk(KERN_WARNING "DVB: adapter %i frontend %i symbol rate %u out of range (%u..%u)\n",
fe->dvb->num, fe->id, parms->u.qpsk.symbol_rate,
fe->ops.info.symbol_rate_min, fe->ops.info.symbol_rate_max);
return -EINVAL;
}
} else if (fe->ops.info.type == FE_QAM) {
if ((fe->ops.info.symbol_rate_min &&
parms->u.qam.symbol_rate < fe->ops.info.symbol_rate_min) ||
(fe->ops.info.symbol_rate_max &&
parms->u.qam.symbol_rate > fe->ops.info.symbol_rate_max)) {
printk(KERN_WARNING "DVB: adapter %i frontend %i symbol rate %u out of range (%u..%u)\n",
fe->dvb->num, fe->id, parms->u.qam.symbol_rate,
fe->ops.info.symbol_rate_min, fe->ops.info.symbol_rate_max);
return -EINVAL;
}
}
if (fe->ops.info.type == FE_QAM &&
(parms->u.qam.modulation > QAM_AUTO ||
!((1 << (parms->u.qam.modulation + 10)) & fe->ops.info.caps))) {
printk(KERN_WARNING "DVB: adapter %i frontend %i modulation %u not supported\n",
fe->dvb->num, fe->id, parms->u.qam.modulation);
return -EINVAL;
}
return 0;
}
static int dvb_frontend_clear_cache(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int i;
memset(c, 0, sizeof(struct dtv_frontend_properties));
c->state = DTV_CLEAR;
c->delivery_system = SYS_UNDEFINED;
c->inversion = INVERSION_AUTO;
c->fec_inner = FEC_AUTO;
c->transmission_mode = TRANSMISSION_MODE_AUTO;
c->bandwidth_hz = BANDWIDTH_AUTO;
c->guard_interval = GUARD_INTERVAL_AUTO;
c->hierarchy = HIERARCHY_AUTO;
c->symbol_rate = QAM_AUTO;
c->code_rate_HP = FEC_AUTO;
c->code_rate_LP = FEC_AUTO;
c->isdbt_partial_reception = -1;
c->isdbt_sb_mode = -1;
c->isdbt_sb_subchannel = -1;
c->isdbt_sb_segment_idx = -1;
c->isdbt_sb_segment_count = -1;
c->isdbt_layer_enabled = 0x7;
for (i = 0; i < 3; i++) {
c->layer[i].fec = FEC_AUTO;
c->layer[i].modulation = QAM_AUTO;
c->layer[i].interleaving = -1;
c->layer[i].segment_count = -1;
}
return 0;
}
static void dtv_property_dump(struct dtv_property *tvp)
{
int i;
if (tvp->cmd <= 0 || tvp->cmd > DTV_MAX_COMMAND) {
printk(KERN_WARNING "%s: tvp.cmd = 0x%08x undefined\n",
__func__, tvp->cmd);
return;
}
dprintk("%s() tvp.cmd = 0x%08x (%s)\n"
,__func__
,tvp->cmd
,dtv_cmds[ tvp->cmd ].name);
if(dtv_cmds[ tvp->cmd ].buffer) {
dprintk("%s() tvp.u.buffer.len = 0x%02x\n"
,__func__
,tvp->u.buffer.len);
for(i = 0; i < tvp->u.buffer.len; i++)
dprintk("%s() tvp.u.buffer.data[0x%02x] = 0x%02x\n"
,__func__
,i
,tvp->u.buffer.data[i]);
} else
dprintk("%s() tvp.u.data = 0x%08x\n", __func__, tvp->u.data);
}
static int is_legacy_delivery_system(fe_delivery_system_t s)
{
if((s == SYS_UNDEFINED) || (s == SYS_DVBC_ANNEX_AC) ||
(s == SYS_DVBC_ANNEX_B) || (s == SYS_DVBT) || (s == SYS_DVBS) ||
(s == SYS_ATSC))
return 1;
return 0;
}
static void dtv_property_cache_sync(struct dvb_frontend *fe,
struct dtv_frontend_properties *c,
const struct dvb_frontend_parameters *p)
{
c->frequency = p->frequency;
c->inversion = p->inversion;
switch (fe->ops.info.type) {
case FE_QPSK:
c->modulation = QPSK;
c->rolloff = ROLLOFF_35;
c->symbol_rate = p->u.qpsk.symbol_rate;
c->fec_inner = p->u.qpsk.fec_inner;
c->delivery_system = SYS_DVBS;
break;
case FE_QAM:
c->symbol_rate = p->u.qam.symbol_rate;
c->fec_inner = p->u.qam.fec_inner;
c->modulation = p->u.qam.modulation;
c->delivery_system = SYS_DVBC_ANNEX_AC;
break;
case FE_OFDM:
if (p->u.ofdm.bandwidth == BANDWIDTH_6_MHZ)
c->bandwidth_hz = 6000000;
else if (p->u.ofdm.bandwidth == BANDWIDTH_7_MHZ)
c->bandwidth_hz = 7000000;
else if (p->u.ofdm.bandwidth == BANDWIDTH_8_MHZ)
c->bandwidth_hz = 8000000;
else
c->bandwidth_hz = 0;
c->code_rate_HP = p->u.ofdm.code_rate_HP;
c->code_rate_LP = p->u.ofdm.code_rate_LP;
c->modulation = p->u.ofdm.constellation;
c->transmission_mode = p->u.ofdm.transmission_mode;
c->guard_interval = p->u.ofdm.guard_interval;
c->hierarchy = p->u.ofdm.hierarchy_information;
c->delivery_system = SYS_DVBT;
break;
case FE_ATSC:
c->modulation = p->u.vsb.modulation;
if ((c->modulation == VSB_8) || (c->modulation == VSB_16))
c->delivery_system = SYS_ATSC;
else
c->delivery_system = SYS_DVBC_ANNEX_B;
break;
}
}
static void dtv_property_legacy_params_sync(struct dvb_frontend *fe)
{
const struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_frontend_parameters *p = &fepriv->parameters_in;
p->frequency = c->frequency;
p->inversion = c->inversion;
switch (fe->ops.info.type) {
case FE_QPSK:
dprintk("%s() Preparing QPSK req\n", __func__);
p->u.qpsk.symbol_rate = c->symbol_rate;
p->u.qpsk.fec_inner = c->fec_inner;
break;
case FE_QAM:
dprintk("%s() Preparing QAM req\n", __func__);
p->u.qam.symbol_rate = c->symbol_rate;
p->u.qam.fec_inner = c->fec_inner;
p->u.qam.modulation = c->modulation;
break;
case FE_OFDM:
dprintk("%s() Preparing OFDM req\n", __func__);
if (c->bandwidth_hz == 6000000)
p->u.ofdm.bandwidth = BANDWIDTH_6_MHZ;
else if (c->bandwidth_hz == 7000000)
p->u.ofdm.bandwidth = BANDWIDTH_7_MHZ;
else if (c->bandwidth_hz == 8000000)
p->u.ofdm.bandwidth = BANDWIDTH_8_MHZ;
else
p->u.ofdm.bandwidth = BANDWIDTH_AUTO;
p->u.ofdm.code_rate_HP = c->code_rate_HP;
p->u.ofdm.code_rate_LP = c->code_rate_LP;
p->u.ofdm.constellation = c->modulation;
p->u.ofdm.transmission_mode = c->transmission_mode;
p->u.ofdm.guard_interval = c->guard_interval;
p->u.ofdm.hierarchy_information = c->hierarchy;
break;
case FE_ATSC:
dprintk("%s() Preparing VSB req\n", __func__);
p->u.vsb.modulation = c->modulation;
break;
}
}
static void dtv_property_adv_params_sync(struct dvb_frontend *fe)
{
const struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_frontend_parameters *p = &fepriv->parameters_in;
p->frequency = c->frequency;
p->inversion = c->inversion;
switch(c->modulation) {
case PSK_8:
case APSK_16:
case APSK_32:
case QPSK:
p->u.qpsk.symbol_rate = c->symbol_rate;
p->u.qpsk.fec_inner = c->fec_inner;
break;
default:
break;
}
if ((c->delivery_system == SYS_ISDBT) ||
(c->delivery_system == SYS_DVBT2)) {
p->u.ofdm.constellation = QAM_AUTO;
p->u.ofdm.code_rate_HP = FEC_AUTO;
p->u.ofdm.code_rate_LP = FEC_AUTO;
p->u.ofdm.transmission_mode = TRANSMISSION_MODE_AUTO;
p->u.ofdm.guard_interval = GUARD_INTERVAL_AUTO;
p->u.ofdm.hierarchy_information = HIERARCHY_AUTO;
if (c->bandwidth_hz == 8000000)
p->u.ofdm.bandwidth = BANDWIDTH_8_MHZ;
else if (c->bandwidth_hz == 7000000)
p->u.ofdm.bandwidth = BANDWIDTH_7_MHZ;
else if (c->bandwidth_hz == 6000000)
p->u.ofdm.bandwidth = BANDWIDTH_6_MHZ;
else
p->u.ofdm.bandwidth = BANDWIDTH_AUTO;
}
}
static void dtv_property_cache_submit(struct dvb_frontend *fe)
{
const struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if(is_legacy_delivery_system(c->delivery_system)) {
dprintk("%s() legacy, modulation = %d\n", __func__, c->modulation);
dtv_property_legacy_params_sync(fe);
} else {
dprintk("%s() adv, modulation = %d\n", __func__, c->modulation);
dtv_property_adv_params_sync(fe);
}
}
static int dtv_property_process_get(struct dvb_frontend *fe,
struct dtv_property *tvp,
struct file *file)
{
const struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dtv_frontend_properties cdetected;
int r;
if (fe->ops.get_frontend) {
cdetected = *c;
dtv_property_cache_sync(fe, &cdetected, &fepriv->parameters_out);
c = &cdetected;
}
switch(tvp->cmd) {
case DTV_FREQUENCY:
tvp->u.data = c->frequency;
break;
case DTV_MODULATION:
tvp->u.data = c->modulation;
break;
case DTV_BANDWIDTH_HZ:
tvp->u.data = c->bandwidth_hz;
break;
case DTV_INVERSION:
tvp->u.data = c->inversion;
break;
case DTV_SYMBOL_RATE:
tvp->u.data = c->symbol_rate;
break;
case DTV_INNER_FEC:
tvp->u.data = c->fec_inner;
break;
case DTV_PILOT:
tvp->u.data = c->pilot;
break;
case DTV_ROLLOFF:
tvp->u.data = c->rolloff;
break;
case DTV_DELIVERY_SYSTEM:
tvp->u.data = c->delivery_system;
break;
case DTV_VOLTAGE:
tvp->u.data = c->voltage;
break;
case DTV_TONE:
tvp->u.data = c->sectone;
break;
case DTV_API_VERSION:
tvp->u.data = (DVB_API_VERSION << 8) | DVB_API_VERSION_MINOR;
break;
case DTV_CODE_RATE_HP:
tvp->u.data = c->code_rate_HP;
break;
case DTV_CODE_RATE_LP:
tvp->u.data = c->code_rate_LP;
break;
case DTV_GUARD_INTERVAL:
tvp->u.data = c->guard_interval;
break;
case DTV_TRANSMISSION_MODE:
tvp->u.data = c->transmission_mode;
break;
case DTV_HIERARCHY:
tvp->u.data = c->hierarchy;
break;
case DTV_ISDBT_PARTIAL_RECEPTION:
tvp->u.data = c->isdbt_partial_reception;
break;
case DTV_ISDBT_SOUND_BROADCASTING:
tvp->u.data = c->isdbt_sb_mode;
break;
case DTV_ISDBT_SB_SUBCHANNEL_ID:
tvp->u.data = c->isdbt_sb_subchannel;
break;
case DTV_ISDBT_SB_SEGMENT_IDX:
tvp->u.data = c->isdbt_sb_segment_idx;
break;
case DTV_ISDBT_SB_SEGMENT_COUNT:
tvp->u.data = c->isdbt_sb_segment_count;
break;
case DTV_ISDBT_LAYER_ENABLED:
tvp->u.data = c->isdbt_layer_enabled;
break;
case DTV_ISDBT_LAYERA_FEC:
tvp->u.data = c->layer[0].fec;
break;
case DTV_ISDBT_LAYERA_MODULATION:
tvp->u.data = c->layer[0].modulation;
break;
case DTV_ISDBT_LAYERA_SEGMENT_COUNT:
tvp->u.data = c->layer[0].segment_count;
break;
case DTV_ISDBT_LAYERA_TIME_INTERLEAVING:
tvp->u.data = c->layer[0].interleaving;
break;
case DTV_ISDBT_LAYERB_FEC:
tvp->u.data = c->layer[1].fec;
break;
case DTV_ISDBT_LAYERB_MODULATION:
tvp->u.data = c->layer[1].modulation;
break;
case DTV_ISDBT_LAYERB_SEGMENT_COUNT:
tvp->u.data = c->layer[1].segment_count;
break;
case DTV_ISDBT_LAYERB_TIME_INTERLEAVING:
tvp->u.data = c->layer[1].interleaving;
break;
case DTV_ISDBT_LAYERC_FEC:
tvp->u.data = c->layer[2].fec;
break;
case DTV_ISDBT_LAYERC_MODULATION:
tvp->u.data = c->layer[2].modulation;
break;
case DTV_ISDBT_LAYERC_SEGMENT_COUNT:
tvp->u.data = c->layer[2].segment_count;
break;
case DTV_ISDBT_LAYERC_TIME_INTERLEAVING:
tvp->u.data = c->layer[2].interleaving;
break;
case DTV_ISDBS_TS_ID:
tvp->u.data = c->isdbs_ts_id;
break;
case DTV_DVBT2_PLP_ID:
tvp->u.data = c->dvbt2_plp_id;
break;
default:
return -EINVAL;
}
if (fe->ops.get_property) {
r = fe->ops.get_property(fe, tvp);
if (r < 0)
return r;
}
dtv_property_dump(tvp);
return 0;
}
static int dtv_property_process_set(struct dvb_frontend *fe,
struct dtv_property *tvp,
struct file *file)
{
int r = 0;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dtv_property_dump(tvp);
if (fe->ops.set_property) {
r = fe->ops.set_property(fe, tvp);
if (r < 0)
return r;
}
switch(tvp->cmd) {
case DTV_CLEAR:
dvb_frontend_clear_cache(fe);
dprintk("%s() Flushing property cache\n", __func__);
break;
case DTV_TUNE:
c->state = tvp->cmd;
dprintk("%s() Finalised property cache\n", __func__);
dtv_property_cache_submit(fe);
r = dvb_frontend_ioctl_legacy(file, FE_SET_FRONTEND,
&fepriv->parameters_in);
break;
case DTV_FREQUENCY:
c->frequency = tvp->u.data;
break;
case DTV_MODULATION:
c->modulation = tvp->u.data;
break;
case DTV_BANDWIDTH_HZ:
c->bandwidth_hz = tvp->u.data;
break;
case DTV_INVERSION:
c->inversion = tvp->u.data;
break;
case DTV_SYMBOL_RATE:
c->symbol_rate = tvp->u.data;
break;
case DTV_INNER_FEC:
c->fec_inner = tvp->u.data;
break;
case DTV_PILOT:
c->pilot = tvp->u.data;
break;
case DTV_ROLLOFF:
c->rolloff = tvp->u.data;
break;
case DTV_DELIVERY_SYSTEM:
c->delivery_system = tvp->u.data;
break;
case DTV_VOLTAGE:
c->voltage = tvp->u.data;
r = dvb_frontend_ioctl_legacy(file, FE_SET_VOLTAGE,
(void *)c->voltage);
break;
case DTV_TONE:
c->sectone = tvp->u.data;
r = dvb_frontend_ioctl_legacy(file, FE_SET_TONE,
(void *)c->sectone);
break;
case DTV_CODE_RATE_HP:
c->code_rate_HP = tvp->u.data;
break;
case DTV_CODE_RATE_LP:
c->code_rate_LP = tvp->u.data;
break;
case DTV_GUARD_INTERVAL:
c->guard_interval = tvp->u.data;
break;
case DTV_TRANSMISSION_MODE:
c->transmission_mode = tvp->u.data;
break;
case DTV_HIERARCHY:
c->hierarchy = tvp->u.data;
break;
case DTV_ISDBT_PARTIAL_RECEPTION:
c->isdbt_partial_reception = tvp->u.data;
break;
case DTV_ISDBT_SOUND_BROADCASTING:
c->isdbt_sb_mode = tvp->u.data;
break;
case DTV_ISDBT_SB_SUBCHANNEL_ID:
c->isdbt_sb_subchannel = tvp->u.data;
break;
case DTV_ISDBT_SB_SEGMENT_IDX:
c->isdbt_sb_segment_idx = tvp->u.data;
break;
case DTV_ISDBT_SB_SEGMENT_COUNT:
c->isdbt_sb_segment_count = tvp->u.data;
break;
case DTV_ISDBT_LAYER_ENABLED:
c->isdbt_layer_enabled = tvp->u.data;
break;
case DTV_ISDBT_LAYERA_FEC:
c->layer[0].fec = tvp->u.data;
break;
case DTV_ISDBT_LAYERA_MODULATION:
c->layer[0].modulation = tvp->u.data;
break;
case DTV_ISDBT_LAYERA_SEGMENT_COUNT:
c->layer[0].segment_count = tvp->u.data;
break;
case DTV_ISDBT_LAYERA_TIME_INTERLEAVING:
c->layer[0].interleaving = tvp->u.data;
break;
case DTV_ISDBT_LAYERB_FEC:
c->layer[1].fec = tvp->u.data;
break;
case DTV_ISDBT_LAYERB_MODULATION:
c->layer[1].modulation = tvp->u.data;
break;
case DTV_ISDBT_LAYERB_SEGMENT_COUNT:
c->layer[1].segment_count = tvp->u.data;
break;
case DTV_ISDBT_LAYERB_TIME_INTERLEAVING:
c->layer[1].interleaving = tvp->u.data;
break;
case DTV_ISDBT_LAYERC_FEC:
c->layer[2].fec = tvp->u.data;
break;
case DTV_ISDBT_LAYERC_MODULATION:
c->layer[2].modulation = tvp->u.data;
break;
case DTV_ISDBT_LAYERC_SEGMENT_COUNT:
c->layer[2].segment_count = tvp->u.data;
break;
case DTV_ISDBT_LAYERC_TIME_INTERLEAVING:
c->layer[2].interleaving = tvp->u.data;
break;
case DTV_ISDBS_TS_ID:
c->isdbs_ts_id = tvp->u.data;
break;
case DTV_DVBT2_PLP_ID:
c->dvbt2_plp_id = tvp->u.data;
break;
default:
return -EINVAL;
}
return r;
}
static int dvb_frontend_ioctl(struct file *file,
unsigned int cmd, void *parg)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
int err = -EOPNOTSUPP;
dprintk("%s (%d)\n", __func__, _IOC_NR(cmd));
if (fepriv->exit != DVB_FE_NO_EXIT)
return -ENODEV;
if ((file->f_flags & O_ACCMODE) == O_RDONLY &&
(_IOC_DIR(cmd) != _IOC_READ || cmd == FE_GET_EVENT ||
cmd == FE_DISEQC_RECV_SLAVE_REPLY))
return -EPERM;
if (down_interruptible (&fepriv->sem))
return -ERESTARTSYS;
if ((cmd == FE_SET_PROPERTY) || (cmd == FE_GET_PROPERTY))
err = dvb_frontend_ioctl_properties(file, cmd, parg);
else {
c->state = DTV_UNDEFINED;
err = dvb_frontend_ioctl_legacy(file, cmd, parg);
}
up(&fepriv->sem);
return err;
}
static int dvb_frontend_ioctl_properties(struct file *file,
unsigned int cmd, void *parg)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int err = 0;
struct dtv_properties *tvps = NULL;
struct dtv_property *tvp = NULL;
int i;
dprintk("%s\n", __func__);
if(cmd == FE_SET_PROPERTY) {
tvps = (struct dtv_properties __user *)parg;
dprintk("%s() properties.num = %d\n", __func__, tvps->num);
dprintk("%s() properties.props = %p\n", __func__, tvps->props);
if ((tvps->num == 0) || (tvps->num > DTV_IOCTL_MAX_MSGS))
return -EINVAL;
tvp = kmalloc(tvps->num * sizeof(struct dtv_property), GFP_KERNEL);
if (!tvp) {
err = -ENOMEM;
goto out;
}
if (copy_from_user(tvp, tvps->props, tvps->num * sizeof(struct dtv_property))) {
err = -EFAULT;
goto out;
}
for (i = 0; i < tvps->num; i++) {
err = dtv_property_process_set(fe, tvp + i, file);
if (err < 0)
goto out;
(tvp + i)->result = err;
}
if (c->state == DTV_TUNE)
dprintk("%s() Property cache is full, tuning\n", __func__);
} else
if(cmd == FE_GET_PROPERTY) {
tvps = (struct dtv_properties __user *)parg;
dprintk("%s() properties.num = %d\n", __func__, tvps->num);
dprintk("%s() properties.props = %p\n", __func__, tvps->props);
if ((tvps->num == 0) || (tvps->num > DTV_IOCTL_MAX_MSGS))
return -EINVAL;
tvp = kmalloc(tvps->num * sizeof(struct dtv_property), GFP_KERNEL);
if (!tvp) {
err = -ENOMEM;
goto out;
}
if (copy_from_user(tvp, tvps->props, tvps->num * sizeof(struct dtv_property))) {
err = -EFAULT;
goto out;
}
for (i = 0; i < tvps->num; i++) {
err = dtv_property_process_get(fe, tvp + i, file);
if (err < 0)
goto out;
(tvp + i)->result = err;
}
if (copy_to_user(tvps->props, tvp, tvps->num * sizeof(struct dtv_property))) {
err = -EFAULT;
goto out;
}
} else
err = -EOPNOTSUPP;
out:
kfree(tvp);
return err;
}
static int dvb_frontend_ioctl_legacy(struct file *file,
unsigned int cmd, void *parg)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
int cb_err, err = -EOPNOTSUPP;
if (fe->dvb->fe_ioctl_override) {
cb_err = fe->dvb->fe_ioctl_override(fe, cmd, parg,
DVB_FE_IOCTL_PRE);
if (cb_err < 0)
return cb_err;
if (cb_err > 0)
return 0;
}
switch (cmd) {
case FE_GET_INFO: {
struct dvb_frontend_info* info = parg;
memcpy(info, &fe->ops.info, sizeof(struct dvb_frontend_info));
dvb_frontend_get_frequency_limits(fe, &info->frequency_min, &info->frequency_max);
info->caps |= FE_CAN_INVERSION_AUTO;
err = 0;
break;
}
case FE_READ_STATUS: {
fe_status_t* status = parg;
if (fepriv->state == FESTATE_RETUNE ||
fepriv->state == FESTATE_ERROR) {
err=0;
*status = 0;
break;
}
if (fe->ops.read_status)
err = fe->ops.read_status(fe, status);
break;
}
case FE_READ_BER:
if (fe->ops.read_ber)
err = fe->ops.read_ber(fe, (__u32*) parg);
break;
case FE_READ_SIGNAL_STRENGTH:
if (fe->ops.read_signal_strength)
err = fe->ops.read_signal_strength(fe, (__u16*) parg);
break;
case FE_READ_SNR:
if (fe->ops.read_snr)
err = fe->ops.read_snr(fe, (__u16*) parg);
break;
case FE_READ_UNCORRECTED_BLOCKS:
if (fe->ops.read_ucblocks)
err = fe->ops.read_ucblocks(fe, (__u32*) parg);
break;
case FE_DISEQC_RESET_OVERLOAD:
if (fe->ops.diseqc_reset_overload) {
err = fe->ops.diseqc_reset_overload(fe);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_DISEQC_SEND_MASTER_CMD:
if (fe->ops.diseqc_send_master_cmd) {
err = fe->ops.diseqc_send_master_cmd(fe, (struct dvb_diseqc_master_cmd*) parg);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_DISEQC_SEND_BURST:
if (fe->ops.diseqc_send_burst) {
err = fe->ops.diseqc_send_burst(fe, (fe_sec_mini_cmd_t) parg);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_SET_TONE:
if (fe->ops.set_tone) {
err = fe->ops.set_tone(fe, (fe_sec_tone_mode_t) parg);
fepriv->tone = (fe_sec_tone_mode_t) parg;
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_SET_VOLTAGE:
if (fe->ops.set_voltage) {
err = fe->ops.set_voltage(fe, (fe_sec_voltage_t) parg);
fepriv->voltage = (fe_sec_voltage_t) parg;
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_DISHNETWORK_SEND_LEGACY_CMD:
if (fe->ops.dishnetwork_send_legacy_command) {
err = fe->ops.dishnetwork_send_legacy_command(fe, (unsigned long) parg);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
} else if (fe->ops.set_voltage) {
unsigned long swcmd = ((unsigned long) parg) << 1;
struct timeval nexttime;
struct timeval tv[10];
int i;
u8 last = 1;
if (dvb_frontend_debug)
printk("%s switch command: 0x%04lx\n", __func__, swcmd);
do_gettimeofday(&nexttime);
if (dvb_frontend_debug)
memcpy(&tv[0], &nexttime, sizeof(struct timeval));
fe->ops.set_voltage(fe, SEC_VOLTAGE_18);
dvb_frontend_sleep_until(&nexttime, 32000);
for (i = 0; i < 9; i++) {
if (dvb_frontend_debug)
do_gettimeofday(&tv[i + 1]);
if ((swcmd & 0x01) != last) {
fe->ops.set_voltage(fe, (last) ? SEC_VOLTAGE_13 : SEC_VOLTAGE_18);
last = (last) ? 0 : 1;
}
swcmd = swcmd >> 1;
if (i != 8)
dvb_frontend_sleep_until(&nexttime, 8000);
}
if (dvb_frontend_debug) {
printk("%s(%d): switch delay (should be 32k followed by all 8k\n",
__func__, fe->dvb->num);
for (i = 1; i < 10; i++)
printk("%d: %d\n", i, timeval_usec_diff(tv[i-1] , tv[i]));
}
err = 0;
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_DISEQC_RECV_SLAVE_REPLY:
if (fe->ops.diseqc_recv_slave_reply)
err = fe->ops.diseqc_recv_slave_reply(fe, (struct dvb_diseqc_slave_reply*) parg);
break;
case FE_ENABLE_HIGH_LNB_VOLTAGE:
if (fe->ops.enable_high_lnb_voltage)
err = fe->ops.enable_high_lnb_voltage(fe, (long) parg);
break;
case FE_SET_FRONTEND: {
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_tune_settings fetunesettings;
if (c->state == DTV_TUNE) {
if (dvb_frontend_check_parameters(fe, &fepriv->parameters_in) < 0) {
err = -EINVAL;
break;
}
} else {
if (dvb_frontend_check_parameters(fe, parg) < 0) {
err = -EINVAL;
break;
}
memcpy (&fepriv->parameters_in, parg,
sizeof (struct dvb_frontend_parameters));
dtv_property_cache_sync(fe, c, &fepriv->parameters_in);
}
memset(&fetunesettings, 0, sizeof(struct dvb_frontend_tune_settings));
memcpy(&fetunesettings.parameters, parg,
sizeof (struct dvb_frontend_parameters));
if (dvb_force_auto_inversion) {
fepriv->parameters_in.inversion = INVERSION_AUTO;
fetunesettings.parameters.inversion = INVERSION_AUTO;
}
if (fe->ops.info.type == FE_OFDM) {
if (fepriv->parameters_in.u.ofdm.hierarchy_information == HIERARCHY_NONE &&
fepriv->parameters_in.u.ofdm.code_rate_LP == FEC_NONE)
fepriv->parameters_in.u.ofdm.code_rate_LP = FEC_AUTO;
}
if (fe->ops.get_tune_settings && (fe->ops.get_tune_settings(fe, &fetunesettings) == 0)) {
fepriv->min_delay = (fetunesettings.min_delay_ms * HZ) / 1000;
fepriv->max_drift = fetunesettings.max_drift;
fepriv->step_size = fetunesettings.step_size;
} else {
switch(fe->ops.info.type) {
case FE_QPSK:
fepriv->min_delay = HZ/20;
fepriv->step_size = fepriv->parameters_in.u.qpsk.symbol_rate / 16000;
fepriv->max_drift = fepriv->parameters_in.u.qpsk.symbol_rate / 2000;
break;
case FE_QAM:
fepriv->min_delay = HZ/20;
fepriv->step_size = 0;
fepriv->max_drift = 0;
break;
case FE_OFDM:
fepriv->min_delay = HZ/20;
fepriv->step_size = fe->ops.info.frequency_stepsize * 2;
fepriv->max_drift = (fe->ops.info.frequency_stepsize * 2) + 1;
break;
case FE_ATSC:
fepriv->min_delay = HZ/20;
fepriv->step_size = 0;
fepriv->max_drift = 0;
break;
}
}
if (dvb_override_tune_delay > 0)
fepriv->min_delay = (dvb_override_tune_delay * HZ) / 1000;
fepriv->state = FESTATE_RETUNE;
fepriv->algo_status |= DVBFE_ALGO_SEARCH_AGAIN;
dvb_frontend_wakeup(fe);
dvb_frontend_add_event(fe, 0);
fepriv->status = 0;
err = 0;
break;
}
case FE_GET_EVENT:
err = dvb_frontend_get_event (fe, parg, file->f_flags);
break;
case FE_GET_FRONTEND:
if (fe->ops.get_frontend) {
err = fe->ops.get_frontend(fe, &fepriv->parameters_out);
memcpy(parg, &fepriv->parameters_out, sizeof(struct dvb_frontend_parameters));
}
break;
case FE_SET_FRONTEND_TUNE_MODE:
fepriv->tune_mode_flags = (unsigned long) parg;
err = 0;
break;
};
if (fe->dvb->fe_ioctl_override) {
cb_err = fe->dvb->fe_ioctl_override(fe, cmd, parg,
DVB_FE_IOCTL_POST);
if (cb_err < 0)
return cb_err;
}
return err;
}
static unsigned int dvb_frontend_poll(struct file *file, struct poll_table_struct *wait)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dprintk ("%s\n", __func__);
poll_wait (file, &fepriv->events.wait_queue, wait);
if (fepriv->events.eventw != fepriv->events.eventr)
return (POLLIN | POLLRDNORM | POLLPRI);
return 0;
}
static int dvb_frontend_open(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_adapter *adapter = fe->dvb;
int ret;
dprintk ("%s\n", __func__);
if (fepriv->exit == DVB_FE_DEVICE_REMOVED)
return -ENODEV;
if (adapter->mfe_shared) {
mutex_lock (&adapter->mfe_lock);
if (adapter->mfe_dvbdev == NULL)
adapter->mfe_dvbdev = dvbdev;
else if (adapter->mfe_dvbdev != dvbdev) {
struct dvb_device
*mfedev = adapter->mfe_dvbdev;
struct dvb_frontend
*mfe = mfedev->priv;
struct dvb_frontend_private
*mfepriv = mfe->frontend_priv;
int mferetry = (dvb_mfe_wait_time << 1);
mutex_unlock (&adapter->mfe_lock);
while (mferetry-- && (mfedev->users != -1 ||
mfepriv->thread != NULL)) {
if(msleep_interruptible(500)) {
if(signal_pending(current))
return -EINTR;
}
}
mutex_lock (&adapter->mfe_lock);
if(adapter->mfe_dvbdev != dvbdev) {
mfedev = adapter->mfe_dvbdev;
mfe = mfedev->priv;
mfepriv = mfe->frontend_priv;
if (mfedev->users != -1 ||
mfepriv->thread != NULL) {
mutex_unlock (&adapter->mfe_lock);
return -EBUSY;
}
adapter->mfe_dvbdev = dvbdev;
}
}
}
if (dvbdev->users == -1 && fe->ops.ts_bus_ctrl) {
if ((ret = fe->ops.ts_bus_ctrl(fe, 1)) < 0)
goto err0;
fepriv->reinitialise = 1;
}
if ((ret = dvb_generic_open (inode, file)) < 0)
goto err1;
if ((file->f_flags & O_ACCMODE) != O_RDONLY) {
fepriv->tune_mode_flags &= ~FE_TUNE_MODE_ONESHOT;
fepriv->tone = -1;
fepriv->voltage = -1;
ret = dvb_frontend_start (fe);
if (ret)
goto err2;
fepriv->events.eventr = fepriv->events.eventw = 0;
}
if (adapter->mfe_shared)
mutex_unlock (&adapter->mfe_lock);
return ret;
err2:
dvb_generic_release(inode, file);
err1:
if (dvbdev->users == -1 && fe->ops.ts_bus_ctrl)
fe->ops.ts_bus_ctrl(fe, 0);
err0:
if (adapter->mfe_shared)
mutex_unlock (&adapter->mfe_lock);
return ret;
}
static int dvb_frontend_release(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
int ret;
dprintk ("%s\n", __func__);
if ((file->f_flags & O_ACCMODE) != O_RDONLY)
fepriv->release_jiffies = jiffies;
ret = dvb_generic_release (inode, file);
if (dvbdev->users == -1) {
if (fepriv->exit != DVB_FE_NO_EXIT) {
fops_put(file->f_op);
file->f_op = NULL;
wake_up(&dvbdev->wait_queue);
}
if (fe->ops.ts_bus_ctrl)
fe->ops.ts_bus_ctrl(fe, 0);
}
return ret;
}
int dvb_register_frontend(struct dvb_adapter* dvb,
struct dvb_frontend* fe)
{
struct dvb_frontend_private *fepriv;
static const struct dvb_device dvbdev_template = {
.users = ~0,
.writers = 1,
.readers = (~0)-1,
.fops = &dvb_frontend_fops,
.kernel_ioctl = dvb_frontend_ioctl
};
dprintk ("%s\n", __func__);
if (mutex_lock_interruptible(&frontend_mutex))
return -ERESTARTSYS;
fe->frontend_priv = kzalloc(sizeof(struct dvb_frontend_private), GFP_KERNEL);
if (fe->frontend_priv == NULL) {
mutex_unlock(&frontend_mutex);
return -ENOMEM;
}
fepriv = fe->frontend_priv;
sema_init(&fepriv->sem, 1);
init_waitqueue_head (&fepriv->wait_queue);
init_waitqueue_head (&fepriv->events.wait_queue);
mutex_init(&fepriv->events.mtx);
fe->dvb = dvb;
fepriv->inversion = INVERSION_OFF;
printk ("DVB: registering adapter %i frontend %i (%s)...\n",
fe->dvb->num,
fe->id,
fe->ops.info.name);
dvb_register_device (fe->dvb, &fepriv->dvbdev, &dvbdev_template,
fe, DVB_DEVICE_FRONTEND);
mutex_unlock(&frontend_mutex);
return 0;
}
int dvb_unregister_frontend(struct dvb_frontend* fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dprintk ("%s\n", __func__);
mutex_lock(&frontend_mutex);
dvb_frontend_stop (fe);
mutex_unlock(&frontend_mutex);
if (fepriv->dvbdev->users < -1)
wait_event(fepriv->dvbdev->wait_queue,
fepriv->dvbdev->users==-1);
mutex_lock(&frontend_mutex);
dvb_unregister_device (fepriv->dvbdev);
kfree(fepriv);
mutex_unlock(&frontend_mutex);
return 0;
}
void dvb_frontend_detach(struct dvb_frontend* fe)
{
void *ptr;
if (fe->ops.release_sec) {
fe->ops.release_sec(fe);
symbol_put_addr(fe->ops.release_sec);
}
if (fe->ops.tuner_ops.release) {
fe->ops.tuner_ops.release(fe);
symbol_put_addr(fe->ops.tuner_ops.release);
}
if (fe->ops.analog_ops.release) {
fe->ops.analog_ops.release(fe);
symbol_put_addr(fe->ops.analog_ops.release);
}
ptr = (void*)fe->ops.release;
if (ptr) {
fe->ops.release(fe);
symbol_put_addr(ptr);
}
}
void dvb_frontend_detach(struct dvb_frontend* fe)
{
if (fe->ops.release_sec)
fe->ops.release_sec(fe);
if (fe->ops.tuner_ops.release)
fe->ops.tuner_ops.release(fe);
if (fe->ops.analog_ops.release)
fe->ops.analog_ops.release(fe);
if (fe->ops.release)
fe->ops.release(fe);
}
