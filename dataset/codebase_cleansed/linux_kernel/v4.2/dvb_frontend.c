static bool has_get_frontend(struct dvb_frontend *fe)
{
return fe->ops.get_frontend != NULL;
}
static enum dvbv3_emulation_type dvbv3_type(u32 delivery_system)
{
switch (delivery_system) {
case SYS_DVBC_ANNEX_A:
case SYS_DVBC_ANNEX_C:
return DVBV3_QAM;
case SYS_DVBS:
case SYS_DVBS2:
case SYS_TURBO:
case SYS_ISDBS:
case SYS_DSS:
return DVBV3_QPSK;
case SYS_DVBT:
case SYS_DVBT2:
case SYS_ISDBT:
case SYS_DTMB:
return DVBV3_OFDM;
case SYS_ATSC:
case SYS_ATSCMH:
case SYS_DVBC_ANNEX_B:
return DVBV3_ATSC;
case SYS_UNDEFINED:
case SYS_ISDBC:
case SYS_DVBH:
case SYS_DAB:
default:
return DVBV3_UNKNOWN;
}
}
static void dvb_frontend_add_event(struct dvb_frontend *fe,
enum fe_status status)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_fe_events *events = &fepriv->events;
struct dvb_frontend_event *e;
int wp;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
if ((status & FE_HAS_LOCK) && has_get_frontend(fe))
dtv_get_frontend(fe, &fepriv->parameters_out);
mutex_lock(&events->mtx);
wp = (events->eventw + 1) % MAX_EVENT;
if (wp == events->eventr) {
events->overflow = 1;
events->eventr = (events->eventr + 1) % MAX_EVENT;
}
e = &events->events[events->eventw];
e->status = status;
e->parameters = fepriv->parameters_out;
events->eventw = wp;
mutex_unlock(&events->mtx);
wake_up_interruptible (&events->wait_queue);
}
static int dvb_frontend_get_event(struct dvb_frontend *fe,
struct dvb_frontend_event *event, int flags)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_fe_events *events = &fepriv->events;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
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
mutex_lock(&events->mtx);
*event = events->events[events->eventr];
events->eventr = (events->eventr + 1) % MAX_EVENT;
mutex_unlock(&events->mtx);
return 0;
}
static void dvb_frontend_clear_events(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_fe_events *events = &fepriv->events;
mutex_lock(&events->mtx);
events->eventr = events->eventw;
mutex_unlock(&events->mtx);
}
static void dvb_frontend_init(struct dvb_frontend *fe)
{
dev_dbg(fe->dvb->device,
"%s: initialising adapter %i frontend %i (%s)...\n",
__func__, fe->dvb->num, fe->id, fe->ops.info.name);
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
struct dvb_frontend *fe = fepriv->dvbdev->priv;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
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
struct dtv_frontend_properties *c = &fe->dtv_property_cache, tmp;
int original_inversion = c->inversion;
u32 original_frequency = c->frequency;
autoinversion = ((!(fe->ops.info.caps & FE_CAN_INVERSION_AUTO)) &&
(c->inversion == INVERSION_AUTO));
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
dev_dbg(fe->dvb->device, "%s: drift:%i inversion:%i auto_step:%i " \
"auto_sub_step:%i started_auto_step:%i\n",
__func__, fepriv->lnb_drift, fepriv->inversion,
fepriv->auto_step, fepriv->auto_sub_step,
fepriv->started_auto_step);
c->frequency += fepriv->lnb_drift;
if (autoinversion)
c->inversion = fepriv->inversion;
tmp = *c;
if (fe->ops.set_frontend)
fe_set_err = fe->ops.set_frontend(fe);
*c = tmp;
if (fe_set_err < 0) {
fepriv->state = FESTATE_ERROR;
return fe_set_err;
}
c->frequency = original_frequency;
c->inversion = original_inversion;
fepriv->auto_sub_step++;
return 0;
}
static void dvb_frontend_swzigzag(struct dvb_frontend *fe)
{
enum fe_status s = 0;
int retval = 0;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache, tmp;
if (fepriv->state & FESTATE_IDLE) {
fepriv->delay = 3*HZ;
fepriv->quality = 0;
return;
}
if (fepriv->tune_mode_flags & FE_TUNE_MODE_ONESHOT) {
if (fepriv->state & FESTATE_RETUNE) {
tmp = *c;
if (fe->ops.set_frontend)
retval = fe->ops.set_frontend(fe);
*c = tmp;
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
(c->inversion == INVERSION_AUTO)) {
c->inversion = fepriv->inversion;
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
if (fe->exit != DVB_FE_NO_EXIT)
return 1;
if (fepriv->dvbdev->writers == 1)
if (time_after_eq(jiffies, fepriv->release_jiffies +
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
static int dvb_enable_media_tuner(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dvb_adapter *adapter = fe->dvb;
struct media_device *mdev = adapter->mdev;
struct media_entity *entity, *source;
struct media_link *link, *found_link = NULL;
int i, ret, n_links = 0, active_links = 0;
fepriv->pipe_start_entity = NULL;
if (!mdev)
return 0;
entity = fepriv->dvbdev->entity;
fepriv->pipe_start_entity = entity;
for (i = 0; i < entity->num_links; i++) {
link = &entity->links[i];
if (link->sink->entity == entity) {
found_link = link;
n_links++;
if (link->flags & MEDIA_LNK_FL_ENABLED)
active_links++;
}
}
if (!n_links || active_links == 1 || !found_link)
return 0;
if (n_links > 1 && active_links != 1) {
dev_err(fe->dvb->device,
"WARNING: there are %d active links among %d tuners. This is a driver's bug!\n",
active_links, n_links);
return -EINVAL;
}
source = found_link->source->entity;
fepriv->pipe_start_entity = source;
for (i = 0; i < source->num_links; i++) {
struct media_entity *sink;
int flags = 0;
link = &source->links[i];
sink = link->sink->entity;
if (sink == entity)
flags = MEDIA_LNK_FL_ENABLED;
ret = media_entity_setup_link(link, flags);
if (ret) {
dev_err(fe->dvb->device,
"Couldn't change link %s->%s to %s. Error %d\n",
source->name, sink->name,
flags ? "enabled" : "disabled",
ret);
return ret;
} else
dev_dbg(fe->dvb->device,
"link %s->%s was %s\n",
source->name, sink->name,
flags ? "ENABLED" : "disabled");
}
return 0;
}
static int dvb_frontend_thread(void *data)
{
struct dvb_frontend *fe = data;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
enum fe_status s;
enum dvbfe_algo algo;
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
int ret;
#endif
bool re_tune = false;
bool semheld = false;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
fepriv->check_wrapped = 0;
fepriv->quality = 0;
fepriv->delay = 3*HZ;
fepriv->status = 0;
fepriv->wakeup = 0;
fepriv->reinitialise = 0;
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
ret = dvb_enable_media_tuner(fe);
if (ret) {
dev_info(fe->dvb->device,
"proceeding with FE task\n");
} else if (fepriv->pipe_start_entity) {
ret = media_entity_pipeline_start(fepriv->pipe_start_entity,
&fepriv->pipe);
if (ret)
return ret;
}
#endif
dvb_frontend_init(fe);
set_freezable();
while (1) {
up(&fepriv->sem);
restart:
wait_event_interruptible_timeout(fepriv->wait_queue,
dvb_frontend_should_wakeup(fe) || kthread_should_stop()
|| freezing(current),
fepriv->delay);
if (kthread_should_stop() || dvb_frontend_is_exiting(fe)) {
if (!down_interruptible(&fepriv->sem))
semheld = true;
fe->exit = DVB_FE_NORMAL_EXIT;
break;
}
if (try_to_freeze())
goto restart;
if (down_interruptible(&fepriv->sem))
break;
if (fepriv->reinitialise) {
dvb_frontend_init(fe);
if (fe->ops.set_tone && fepriv->tone != -1)
fe->ops.set_tone(fe, fepriv->tone);
if (fe->ops.set_voltage && fepriv->voltage != -1)
fe->ops.set_voltage(fe, fepriv->voltage);
fepriv->reinitialise = 0;
}
if (fe->ops.get_frontend_algo) {
algo = fe->ops.get_frontend_algo(fe);
switch (algo) {
case DVBFE_ALGO_HW:
dev_dbg(fe->dvb->device, "%s: Frontend ALGO = DVBFE_ALGO_HW\n", __func__);
if (fepriv->state & FESTATE_RETUNE) {
dev_dbg(fe->dvb->device, "%s: Retune requested, FESTATE_RETUNE\n", __func__);
re_tune = true;
fepriv->state = FESTATE_TUNED;
} else {
re_tune = false;
}
if (fe->ops.tune)
fe->ops.tune(fe, re_tune, fepriv->tune_mode_flags, &fepriv->delay, &s);
if (s != fepriv->status && !(fepriv->tune_mode_flags & FE_TUNE_MODE_ONESHOT)) {
dev_dbg(fe->dvb->device, "%s: state changed, adding current state\n", __func__);
dvb_frontend_add_event(fe, s);
fepriv->status = s;
}
break;
case DVBFE_ALGO_SW:
dev_dbg(fe->dvb->device, "%s: Frontend ALGO = DVBFE_ALGO_SW\n", __func__);
dvb_frontend_swzigzag(fe);
break;
case DVBFE_ALGO_CUSTOM:
dev_dbg(fe->dvb->device, "%s: Frontend ALGO = DVBFE_ALGO_CUSTOM, state=%d\n", __func__, fepriv->state);
if (fepriv->state & FESTATE_RETUNE) {
dev_dbg(fe->dvb->device, "%s: Retune requested, FESTAT_RETUNE\n", __func__);
fepriv->state = FESTATE_TUNED;
}
if (fepriv->algo_status & DVBFE_ALGO_SEARCH_AGAIN) {
if (fe->ops.search) {
fepriv->algo_status = fe->ops.search(fe);
} else {
fepriv->algo_status &= ~DVBFE_ALGO_SEARCH_AGAIN;
}
}
if (fepriv->algo_status != DVBFE_ALGO_SEARCH_SUCCESS) {
fepriv->algo_status |= DVBFE_ALGO_SEARCH_AGAIN;
fepriv->delay = HZ / 2;
}
dtv_property_legacy_params_sync(fe, &fepriv->parameters_out);
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
dev_dbg(fe->dvb->device, "%s: UNDEFINED ALGO !\n", __func__);
break;
}
} else {
dvb_frontend_swzigzag(fe);
}
}
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
if (fepriv->pipe_start_entity)
media_entity_pipeline_stop(fepriv->pipe_start_entity);
fepriv->pipe_start_entity = NULL;
#endif
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
fe->exit = DVB_FE_DEVICE_REMOVED;
else
fe->exit = DVB_FE_NO_EXIT;
mb();
if (semheld)
up(&fepriv->sem);
dvb_frontend_wakeup(fe);
return 0;
}
static void dvb_frontend_stop(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
if (fe->exit != DVB_FE_DEVICE_REMOVED)
fe->exit = DVB_FE_NORMAL_EXIT;
mb();
if (!fepriv->thread)
return;
kthread_stop(fepriv->thread);
sema_init(&fepriv->sem, 1);
fepriv->state = FESTATE_IDLE;
if (fepriv->thread)
dev_warn(fe->dvb->device,
"dvb_frontend_stop: warning: thread %p won't exit\n",
fepriv->thread);
}
void dvb_frontend_sleep_until(ktime_t *waketime, u32 add_usec)
{
s32 delta, newdelta;
ktime_add_us(*waketime, add_usec);
delta = ktime_us_delta(ktime_get_real(), *waketime);
if (delta > 2500) {
msleep((delta - 1500) / 1000);
newdelta = ktime_us_delta(ktime_get_real(), *waketime);
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
dev_dbg(fe->dvb->device, "%s:\n", __func__);
if (fepriv->thread) {
if (fe->exit == DVB_FE_NO_EXIT)
return 0;
else
dvb_frontend_stop (fe);
}
if (signal_pending(current))
return -EINTR;
if (down_interruptible (&fepriv->sem))
return -EINTR;
fepriv->state = FESTATE_IDLE;
fe->exit = DVB_FE_NO_EXIT;
fepriv->thread = NULL;
mb();
fe_thread = kthread_run(dvb_frontend_thread, fe,
"kdvb-ad-%i-fe-%i", fe->dvb->num,fe->id);
if (IS_ERR(fe_thread)) {
ret = PTR_ERR(fe_thread);
dev_warn(fe->dvb->device,
"dvb_frontend_start: failed to start kthread (%d)\n",
ret);
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
dev_warn(fe->dvb->device, "DVB: adapter %i frontend %u frequency limits undefined - fix the driver\n",
fe->dvb->num, fe->id);
}
static int dvb_frontend_check_parameters(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 freq_min;
u32 freq_max;
dvb_frontend_get_frequency_limits(fe, &freq_min, &freq_max);
if ((freq_min && c->frequency < freq_min) ||
(freq_max && c->frequency > freq_max)) {
dev_warn(fe->dvb->device, "DVB: adapter %i frontend %i frequency %u out of range (%u..%u)\n",
fe->dvb->num, fe->id, c->frequency,
freq_min, freq_max);
return -EINVAL;
}
switch (c->delivery_system) {
case SYS_DVBS:
case SYS_DVBS2:
case SYS_TURBO:
case SYS_DVBC_ANNEX_A:
case SYS_DVBC_ANNEX_C:
if ((fe->ops.info.symbol_rate_min &&
c->symbol_rate < fe->ops.info.symbol_rate_min) ||
(fe->ops.info.symbol_rate_max &&
c->symbol_rate > fe->ops.info.symbol_rate_max)) {
dev_warn(fe->dvb->device, "DVB: adapter %i frontend %i symbol rate %u out of range (%u..%u)\n",
fe->dvb->num, fe->id, c->symbol_rate,
fe->ops.info.symbol_rate_min,
fe->ops.info.symbol_rate_max);
return -EINVAL;
}
default:
break;
}
return 0;
}
static int dvb_frontend_clear_cache(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int i;
u32 delsys;
delsys = c->delivery_system;
memset(c, 0, offsetof(struct dtv_frontend_properties, strength));
c->delivery_system = delsys;
c->state = DTV_CLEAR;
dev_dbg(fe->dvb->device, "%s: Clearing cache for delivery system %d\n",
__func__, c->delivery_system);
c->transmission_mode = TRANSMISSION_MODE_AUTO;
c->bandwidth_hz = 0;
c->guard_interval = GUARD_INTERVAL_AUTO;
c->hierarchy = HIERARCHY_AUTO;
c->symbol_rate = 0;
c->code_rate_HP = FEC_AUTO;
c->code_rate_LP = FEC_AUTO;
c->fec_inner = FEC_AUTO;
c->rolloff = ROLLOFF_AUTO;
c->voltage = SEC_VOLTAGE_OFF;
c->sectone = SEC_TONE_OFF;
c->pilot = PILOT_AUTO;
c->isdbt_partial_reception = 0;
c->isdbt_sb_mode = 0;
c->isdbt_sb_subchannel = 0;
c->isdbt_sb_segment_idx = 0;
c->isdbt_sb_segment_count = 0;
c->isdbt_layer_enabled = 0;
for (i = 0; i < 3; i++) {
c->layer[i].fec = FEC_AUTO;
c->layer[i].modulation = QAM_AUTO;
c->layer[i].interleaving = 0;
c->layer[i].segment_count = 0;
}
c->stream_id = NO_STREAM_ID_FILTER;
switch (c->delivery_system) {
case SYS_DVBS:
case SYS_DVBS2:
case SYS_TURBO:
c->modulation = QPSK;
c->rolloff = ROLLOFF_35;
break;
case SYS_ATSC:
c->modulation = VSB_8;
break;
case SYS_ISDBS:
c->symbol_rate = 28860000;
c->rolloff = ROLLOFF_35;
c->bandwidth_hz = c->symbol_rate / 100 * 135;
break;
default:
c->modulation = QAM_AUTO;
break;
}
c->lna = LNA_AUTO;
return 0;
}
static void dtv_property_dump(struct dvb_frontend *fe, struct dtv_property *tvp)
{
int i;
if (tvp->cmd <= 0 || tvp->cmd > DTV_MAX_COMMAND) {
dev_warn(fe->dvb->device, "%s: tvp.cmd = 0x%08x undefined\n",
__func__, tvp->cmd);
return;
}
dev_dbg(fe->dvb->device, "%s: tvp.cmd = 0x%08x (%s)\n", __func__,
tvp->cmd, dtv_cmds[tvp->cmd].name);
if (dtv_cmds[tvp->cmd].buffer) {
dev_dbg(fe->dvb->device, "%s: tvp.u.buffer.len = 0x%02x\n",
__func__, tvp->u.buffer.len);
for(i = 0; i < tvp->u.buffer.len; i++)
dev_dbg(fe->dvb->device,
"%s: tvp.u.buffer.data[0x%02x] = 0x%02x\n",
__func__, i, tvp->u.buffer.data[i]);
} else {
dev_dbg(fe->dvb->device, "%s: tvp.u.data = 0x%08x\n", __func__,
tvp->u.data);
}
}
static int dtv_property_cache_sync(struct dvb_frontend *fe,
struct dtv_frontend_properties *c,
const struct dvb_frontend_parameters *p)
{
c->frequency = p->frequency;
c->inversion = p->inversion;
switch (dvbv3_type(c->delivery_system)) {
case DVBV3_QPSK:
dev_dbg(fe->dvb->device, "%s: Preparing QPSK req\n", __func__);
c->symbol_rate = p->u.qpsk.symbol_rate;
c->fec_inner = p->u.qpsk.fec_inner;
break;
case DVBV3_QAM:
dev_dbg(fe->dvb->device, "%s: Preparing QAM req\n", __func__);
c->symbol_rate = p->u.qam.symbol_rate;
c->fec_inner = p->u.qam.fec_inner;
c->modulation = p->u.qam.modulation;
break;
case DVBV3_OFDM:
dev_dbg(fe->dvb->device, "%s: Preparing OFDM req\n", __func__);
switch (p->u.ofdm.bandwidth) {
case BANDWIDTH_10_MHZ:
c->bandwidth_hz = 10000000;
break;
case BANDWIDTH_8_MHZ:
c->bandwidth_hz = 8000000;
break;
case BANDWIDTH_7_MHZ:
c->bandwidth_hz = 7000000;
break;
case BANDWIDTH_6_MHZ:
c->bandwidth_hz = 6000000;
break;
case BANDWIDTH_5_MHZ:
c->bandwidth_hz = 5000000;
break;
case BANDWIDTH_1_712_MHZ:
c->bandwidth_hz = 1712000;
break;
case BANDWIDTH_AUTO:
c->bandwidth_hz = 0;
}
c->code_rate_HP = p->u.ofdm.code_rate_HP;
c->code_rate_LP = p->u.ofdm.code_rate_LP;
c->modulation = p->u.ofdm.constellation;
c->transmission_mode = p->u.ofdm.transmission_mode;
c->guard_interval = p->u.ofdm.guard_interval;
c->hierarchy = p->u.ofdm.hierarchy_information;
break;
case DVBV3_ATSC:
dev_dbg(fe->dvb->device, "%s: Preparing ATSC req\n", __func__);
c->modulation = p->u.vsb.modulation;
if (c->delivery_system == SYS_ATSCMH)
break;
if ((c->modulation == VSB_8) || (c->modulation == VSB_16))
c->delivery_system = SYS_ATSC;
else
c->delivery_system = SYS_DVBC_ANNEX_B;
break;
case DVBV3_UNKNOWN:
dev_err(fe->dvb->device,
"%s: doesn't know how to handle a DVBv3 call to delivery system %i\n",
__func__, c->delivery_system);
return -EINVAL;
}
return 0;
}
static int dtv_property_legacy_params_sync(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
const struct dtv_frontend_properties *c = &fe->dtv_property_cache;
p->frequency = c->frequency;
p->inversion = c->inversion;
switch (dvbv3_type(c->delivery_system)) {
case DVBV3_UNKNOWN:
dev_err(fe->dvb->device,
"%s: doesn't know how to handle a DVBv3 call to delivery system %i\n",
__func__, c->delivery_system);
return -EINVAL;
case DVBV3_QPSK:
dev_dbg(fe->dvb->device, "%s: Preparing QPSK req\n", __func__);
p->u.qpsk.symbol_rate = c->symbol_rate;
p->u.qpsk.fec_inner = c->fec_inner;
break;
case DVBV3_QAM:
dev_dbg(fe->dvb->device, "%s: Preparing QAM req\n", __func__);
p->u.qam.symbol_rate = c->symbol_rate;
p->u.qam.fec_inner = c->fec_inner;
p->u.qam.modulation = c->modulation;
break;
case DVBV3_OFDM:
dev_dbg(fe->dvb->device, "%s: Preparing OFDM req\n", __func__);
switch (c->bandwidth_hz) {
case 10000000:
p->u.ofdm.bandwidth = BANDWIDTH_10_MHZ;
break;
case 8000000:
p->u.ofdm.bandwidth = BANDWIDTH_8_MHZ;
break;
case 7000000:
p->u.ofdm.bandwidth = BANDWIDTH_7_MHZ;
break;
case 6000000:
p->u.ofdm.bandwidth = BANDWIDTH_6_MHZ;
break;
case 5000000:
p->u.ofdm.bandwidth = BANDWIDTH_5_MHZ;
break;
case 1712000:
p->u.ofdm.bandwidth = BANDWIDTH_1_712_MHZ;
break;
case 0:
default:
p->u.ofdm.bandwidth = BANDWIDTH_AUTO;
}
p->u.ofdm.code_rate_HP = c->code_rate_HP;
p->u.ofdm.code_rate_LP = c->code_rate_LP;
p->u.ofdm.constellation = c->modulation;
p->u.ofdm.transmission_mode = c->transmission_mode;
p->u.ofdm.guard_interval = c->guard_interval;
p->u.ofdm.hierarchy_information = c->hierarchy;
break;
case DVBV3_ATSC:
dev_dbg(fe->dvb->device, "%s: Preparing VSB req\n", __func__);
p->u.vsb.modulation = c->modulation;
break;
}
return 0;
}
static int dtv_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p_out)
{
int r;
if (fe->ops.get_frontend) {
r = fe->ops.get_frontend(fe);
if (unlikely(r < 0))
return r;
if (p_out)
dtv_property_legacy_params_sync(fe, p_out);
return 0;
}
return 0;
}
static int dtv_property_process_get(struct dvb_frontend *fe,
const struct dtv_frontend_properties *c,
struct dtv_property *tvp,
struct file *file)
{
int r, ncaps;
switch(tvp->cmd) {
case DTV_ENUM_DELSYS:
ncaps = 0;
while (ncaps < MAX_DELSYS && fe->ops.delsys[ncaps]) {
tvp->u.buffer.data[ncaps] = fe->ops.delsys[ncaps];
ncaps++;
}
tvp->u.buffer.len = ncaps;
break;
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
case DTV_INTERLEAVING:
tvp->u.data = c->interleaving;
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
case DTV_STREAM_ID:
case DTV_DVBT2_PLP_ID_LEGACY:
tvp->u.data = c->stream_id;
break;
case DTV_ATSCMH_FIC_VER:
tvp->u.data = fe->dtv_property_cache.atscmh_fic_ver;
break;
case DTV_ATSCMH_PARADE_ID:
tvp->u.data = fe->dtv_property_cache.atscmh_parade_id;
break;
case DTV_ATSCMH_NOG:
tvp->u.data = fe->dtv_property_cache.atscmh_nog;
break;
case DTV_ATSCMH_TNOG:
tvp->u.data = fe->dtv_property_cache.atscmh_tnog;
break;
case DTV_ATSCMH_SGN:
tvp->u.data = fe->dtv_property_cache.atscmh_sgn;
break;
case DTV_ATSCMH_PRC:
tvp->u.data = fe->dtv_property_cache.atscmh_prc;
break;
case DTV_ATSCMH_RS_FRAME_MODE:
tvp->u.data = fe->dtv_property_cache.atscmh_rs_frame_mode;
break;
case DTV_ATSCMH_RS_FRAME_ENSEMBLE:
tvp->u.data = fe->dtv_property_cache.atscmh_rs_frame_ensemble;
break;
case DTV_ATSCMH_RS_CODE_MODE_PRI:
tvp->u.data = fe->dtv_property_cache.atscmh_rs_code_mode_pri;
break;
case DTV_ATSCMH_RS_CODE_MODE_SEC:
tvp->u.data = fe->dtv_property_cache.atscmh_rs_code_mode_sec;
break;
case DTV_ATSCMH_SCCC_BLOCK_MODE:
tvp->u.data = fe->dtv_property_cache.atscmh_sccc_block_mode;
break;
case DTV_ATSCMH_SCCC_CODE_MODE_A:
tvp->u.data = fe->dtv_property_cache.atscmh_sccc_code_mode_a;
break;
case DTV_ATSCMH_SCCC_CODE_MODE_B:
tvp->u.data = fe->dtv_property_cache.atscmh_sccc_code_mode_b;
break;
case DTV_ATSCMH_SCCC_CODE_MODE_C:
tvp->u.data = fe->dtv_property_cache.atscmh_sccc_code_mode_c;
break;
case DTV_ATSCMH_SCCC_CODE_MODE_D:
tvp->u.data = fe->dtv_property_cache.atscmh_sccc_code_mode_d;
break;
case DTV_LNA:
tvp->u.data = c->lna;
break;
case DTV_STAT_SIGNAL_STRENGTH:
tvp->u.st = c->strength;
break;
case DTV_STAT_CNR:
tvp->u.st = c->cnr;
break;
case DTV_STAT_PRE_ERROR_BIT_COUNT:
tvp->u.st = c->pre_bit_error;
break;
case DTV_STAT_PRE_TOTAL_BIT_COUNT:
tvp->u.st = c->pre_bit_count;
break;
case DTV_STAT_POST_ERROR_BIT_COUNT:
tvp->u.st = c->post_bit_error;
break;
case DTV_STAT_POST_TOTAL_BIT_COUNT:
tvp->u.st = c->post_bit_count;
break;
case DTV_STAT_ERROR_BLOCK_COUNT:
tvp->u.st = c->block_error;
break;
case DTV_STAT_TOTAL_BLOCK_COUNT:
tvp->u.st = c->block_count;
break;
default:
dev_dbg(fe->dvb->device,
"%s: FE property %d doesn't exist\n",
__func__, tvp->cmd);
return -EINVAL;
}
if (fe->ops.get_property) {
r = fe->ops.get_property(fe, tvp);
if (r < 0)
return r;
}
dtv_property_dump(fe, tvp);
return 0;
}
static bool is_dvbv3_delsys(u32 delsys)
{
bool status;
status = (delsys == SYS_DVBT) || (delsys == SYS_DVBC_ANNEX_A) ||
(delsys == SYS_DVBS) || (delsys == SYS_ATSC);
return status;
}
static int emulate_delivery_system(struct dvb_frontend *fe, u32 delsys)
{
int i;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
c->delivery_system = delsys;
if (c->delivery_system == SYS_ISDBT) {
dev_dbg(fe->dvb->device,
"%s: Using defaults for SYS_ISDBT\n",
__func__);
if (!c->bandwidth_hz)
c->bandwidth_hz = 6000000;
c->isdbt_partial_reception = 0;
c->isdbt_sb_mode = 0;
c->isdbt_sb_subchannel = 0;
c->isdbt_sb_segment_idx = 0;
c->isdbt_sb_segment_count = 0;
c->isdbt_layer_enabled = 7;
for (i = 0; i < 3; i++) {
c->layer[i].fec = FEC_AUTO;
c->layer[i].modulation = QAM_AUTO;
c->layer[i].interleaving = 0;
c->layer[i].segment_count = 0;
}
}
dev_dbg(fe->dvb->device, "%s: change delivery system on cache to %d\n",
__func__, c->delivery_system);
return 0;
}
static int dvbv5_set_delivery_system(struct dvb_frontend *fe,
u32 desired_system)
{
int ncaps;
u32 delsys = SYS_UNDEFINED;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
enum dvbv3_emulation_type type;
if (desired_system == SYS_UNDEFINED)
desired_system = fe->ops.delsys[0];
ncaps = 0;
while (ncaps < MAX_DELSYS && fe->ops.delsys[ncaps]) {
if (fe->ops.delsys[ncaps] == desired_system) {
c->delivery_system = desired_system;
dev_dbg(fe->dvb->device,
"%s: Changing delivery system to %d\n",
__func__, desired_system);
return 0;
}
ncaps++;
}
if (!is_dvbv3_delsys(desired_system)) {
dev_dbg(fe->dvb->device,
"%s: Delivery system %d not supported.\n",
__func__, desired_system);
return -EINVAL;
}
type = dvbv3_type(desired_system);
ncaps = 0;
while (ncaps < MAX_DELSYS && fe->ops.delsys[ncaps]) {
if (dvbv3_type(fe->ops.delsys[ncaps]) == type)
delsys = fe->ops.delsys[ncaps];
ncaps++;
}
if (delsys == SYS_UNDEFINED) {
dev_dbg(fe->dvb->device,
"%s: Delivery system %d not supported on emulation mode.\n",
__func__, desired_system);
return -EINVAL;
}
dev_dbg(fe->dvb->device,
"%s: Using delivery system %d emulated as if it were %d\n",
__func__, delsys, desired_system);
return emulate_delivery_system(fe, desired_system);
}
static int dvbv3_set_delivery_system(struct dvb_frontend *fe)
{
int ncaps;
u32 delsys = SYS_UNDEFINED;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->delivery_system == SYS_UNDEFINED)
c->delivery_system = fe->ops.delsys[0];
if (is_dvbv3_delsys(c->delivery_system)) {
dev_dbg(fe->dvb->device,
"%s: Using delivery system to %d\n",
__func__, c->delivery_system);
return 0;
}
ncaps = 0;
while (ncaps < MAX_DELSYS && fe->ops.delsys[ncaps]) {
if (dvbv3_type(fe->ops.delsys[ncaps]) != DVBV3_UNKNOWN) {
delsys = fe->ops.delsys[ncaps];
break;
}
ncaps++;
}
if (delsys == SYS_UNDEFINED) {
dev_dbg(fe->dvb->device,
"%s: Couldn't find a delivery system that works with FE_SET_FRONTEND\n",
__func__);
return -EINVAL;
}
return emulate_delivery_system(fe, delsys);
}
static int dtv_property_process_set(struct dvb_frontend *fe,
struct dtv_property *tvp,
struct file *file)
{
int r = 0;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (fe->ops.set_property) {
r = fe->ops.set_property(fe, tvp);
if (r < 0)
return r;
}
switch(tvp->cmd) {
case DTV_CLEAR:
dvb_frontend_clear_cache(fe);
break;
case DTV_TUNE:
c->state = tvp->cmd;
dev_dbg(fe->dvb->device, "%s: Finalised property cache\n",
__func__);
r = dtv_set_frontend(fe);
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
r = dvbv5_set_delivery_system(fe, tvp->u.data);
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
case DTV_INTERLEAVING:
c->interleaving = tvp->u.data;
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
case DTV_STREAM_ID:
case DTV_DVBT2_PLP_ID_LEGACY:
c->stream_id = tvp->u.data;
break;
case DTV_ATSCMH_PARADE_ID:
fe->dtv_property_cache.atscmh_parade_id = tvp->u.data;
break;
case DTV_ATSCMH_RS_FRAME_ENSEMBLE:
fe->dtv_property_cache.atscmh_rs_frame_ensemble = tvp->u.data;
break;
case DTV_LNA:
c->lna = tvp->u.data;
if (fe->ops.set_lna)
r = fe->ops.set_lna(fe);
if (r < 0)
c->lna = LNA_AUTO;
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
dev_dbg(fe->dvb->device, "%s: (%d)\n", __func__, _IOC_NR(cmd));
if (down_interruptible(&fepriv->sem))
return -ERESTARTSYS;
if (fe->exit != DVB_FE_NO_EXIT) {
up(&fepriv->sem);
return -ENODEV;
}
if ((file->f_flags & O_ACCMODE) == O_RDONLY &&
(_IOC_DIR(cmd) != _IOC_READ || cmd == FE_GET_EVENT ||
cmd == FE_DISEQC_RECV_SLAVE_REPLY)) {
up(&fepriv->sem);
return -EPERM;
}
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
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int err = 0;
struct dtv_properties *tvps = parg;
struct dtv_property *tvp = NULL;
int i;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
if (cmd == FE_SET_PROPERTY) {
dev_dbg(fe->dvb->device, "%s: properties.num = %d\n", __func__, tvps->num);
dev_dbg(fe->dvb->device, "%s: properties.props = %p\n", __func__, tvps->props);
if ((tvps->num == 0) || (tvps->num > DTV_IOCTL_MAX_MSGS))
return -EINVAL;
tvp = kmalloc(tvps->num * sizeof(struct dtv_property), GFP_KERNEL);
if (!tvp) {
err = -ENOMEM;
goto out;
}
if (copy_from_user(tvp, (void __user *)tvps->props,
tvps->num * sizeof(struct dtv_property))) {
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
dev_dbg(fe->dvb->device, "%s: Property cache is full, tuning\n", __func__);
} else if (cmd == FE_GET_PROPERTY) {
dev_dbg(fe->dvb->device, "%s: properties.num = %d\n", __func__, tvps->num);
dev_dbg(fe->dvb->device, "%s: properties.props = %p\n", __func__, tvps->props);
if ((tvps->num == 0) || (tvps->num > DTV_IOCTL_MAX_MSGS))
return -EINVAL;
tvp = kmalloc(tvps->num * sizeof(struct dtv_property), GFP_KERNEL);
if (!tvp) {
err = -ENOMEM;
goto out;
}
if (copy_from_user(tvp, (void __user *)tvps->props,
tvps->num * sizeof(struct dtv_property))) {
err = -EFAULT;
goto out;
}
if (fepriv->state != FESTATE_IDLE) {
err = dtv_get_frontend(fe, NULL);
if (err < 0)
goto out;
}
for (i = 0; i < tvps->num; i++) {
err = dtv_property_process_get(fe, c, tvp + i, file);
if (err < 0)
goto out;
(tvp + i)->result = err;
}
if (copy_to_user((void __user *)tvps->props, tvp,
tvps->num * sizeof(struct dtv_property))) {
err = -EFAULT;
goto out;
}
} else
err = -EOPNOTSUPP;
out:
kfree(tvp);
return err;
}
static int dtv_set_frontend(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_frontend_tune_settings fetunesettings;
u32 rolloff = 0;
if (dvb_frontend_check_parameters(fe) < 0)
return -EINVAL;
dtv_property_legacy_params_sync(fe, &fepriv->parameters_out);
switch (c->delivery_system) {
case SYS_ATSC:
case SYS_DVBC_ANNEX_B:
c->bandwidth_hz = 6000000;
break;
case SYS_DVBC_ANNEX_A:
rolloff = 115;
break;
case SYS_DVBC_ANNEX_C:
rolloff = 113;
break;
case SYS_DVBS:
case SYS_TURBO:
case SYS_ISDBS:
rolloff = 135;
break;
case SYS_DVBS2:
switch (c->rolloff) {
case ROLLOFF_20:
rolloff = 120;
break;
case ROLLOFF_25:
rolloff = 125;
break;
default:
case ROLLOFF_35:
rolloff = 135;
}
break;
default:
break;
}
if (rolloff)
c->bandwidth_hz = mult_frac(c->symbol_rate, rolloff, 100);
if (dvb_force_auto_inversion)
c->inversion = INVERSION_AUTO;
if (c->hierarchy == HIERARCHY_NONE && c->code_rate_LP == FEC_NONE)
c->code_rate_LP = FEC_AUTO;
memset(&fetunesettings, 0, sizeof(struct dvb_frontend_tune_settings));
if (fe->ops.get_tune_settings && (fe->ops.get_tune_settings(fe, &fetunesettings) == 0)) {
fepriv->min_delay = (fetunesettings.min_delay_ms * HZ) / 1000;
fepriv->max_drift = fetunesettings.max_drift;
fepriv->step_size = fetunesettings.step_size;
} else {
switch (c->delivery_system) {
case SYS_DVBS:
case SYS_DVBS2:
case SYS_ISDBS:
case SYS_TURBO:
case SYS_DVBC_ANNEX_A:
case SYS_DVBC_ANNEX_C:
fepriv->min_delay = HZ / 20;
fepriv->step_size = c->symbol_rate / 16000;
fepriv->max_drift = c->symbol_rate / 2000;
break;
case SYS_DVBT:
case SYS_DVBT2:
case SYS_ISDBT:
case SYS_DTMB:
fepriv->min_delay = HZ / 20;
fepriv->step_size = fe->ops.info.frequency_stepsize * 2;
fepriv->max_drift = (fe->ops.info.frequency_stepsize * 2) + 1;
break;
default:
fepriv->min_delay = HZ / 20;
fepriv->step_size = 0;
fepriv->max_drift = 0;
break;
}
}
if (dvb_override_tune_delay > 0)
fepriv->min_delay = (dvb_override_tune_delay * HZ) / 1000;
fepriv->state = FESTATE_RETUNE;
fepriv->algo_status |= DVBFE_ALGO_SEARCH_AGAIN;
dvb_frontend_clear_events(fe);
dvb_frontend_add_event(fe, 0);
dvb_frontend_wakeup(fe);
fepriv->status = 0;
return 0;
}
static int dvb_frontend_ioctl_legacy(struct file *file,
unsigned int cmd, void *parg)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int err = -EOPNOTSUPP;
switch (cmd) {
case FE_GET_INFO: {
struct dvb_frontend_info* info = parg;
memcpy(info, &fe->ops.info, sizeof(struct dvb_frontend_info));
dvb_frontend_get_frequency_limits(fe, &info->frequency_min, &info->frequency_max);
switch (dvbv3_type(c->delivery_system)) {
case DVBV3_QPSK:
info->type = FE_QPSK;
break;
case DVBV3_ATSC:
info->type = FE_ATSC;
break;
case DVBV3_QAM:
info->type = FE_QAM;
break;
case DVBV3_OFDM:
info->type = FE_OFDM;
break;
default:
dev_err(fe->dvb->device,
"%s: doesn't know how to handle a DVBv3 call to delivery system %i\n",
__func__, c->delivery_system);
fe->ops.info.type = FE_OFDM;
}
dev_dbg(fe->dvb->device, "%s: current delivery system on cache: %d, V3 type: %d\n",
__func__, c->delivery_system, fe->ops.info.type);
info->caps |= FE_CAN_INVERSION_AUTO;
err = 0;
break;
}
case FE_READ_STATUS: {
enum fe_status *status = parg;
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
if (fe->ops.read_ber) {
if (fepriv->thread)
err = fe->ops.read_ber(fe, (__u32 *) parg);
else
err = -EAGAIN;
}
break;
case FE_READ_SIGNAL_STRENGTH:
if (fe->ops.read_signal_strength) {
if (fepriv->thread)
err = fe->ops.read_signal_strength(fe, (__u16 *) parg);
else
err = -EAGAIN;
}
break;
case FE_READ_SNR:
if (fe->ops.read_snr) {
if (fepriv->thread)
err = fe->ops.read_snr(fe, (__u16 *) parg);
else
err = -EAGAIN;
}
break;
case FE_READ_UNCORRECTED_BLOCKS:
if (fe->ops.read_ucblocks) {
if (fepriv->thread)
err = fe->ops.read_ucblocks(fe, (__u32 *) parg);
else
err = -EAGAIN;
}
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
struct dvb_diseqc_master_cmd *cmd = parg;
if (cmd->msg_len > sizeof(cmd->msg)) {
err = -EINVAL;
break;
}
err = fe->ops.diseqc_send_master_cmd(fe, cmd);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_DISEQC_SEND_BURST:
if (fe->ops.diseqc_send_burst) {
err = fe->ops.diseqc_send_burst(fe,
(enum fe_sec_mini_cmd)parg);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_SET_TONE:
if (fe->ops.set_tone) {
err = fe->ops.set_tone(fe,
(enum fe_sec_tone_mode)parg);
fepriv->tone = (enum fe_sec_tone_mode)parg;
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_SET_VOLTAGE:
if (fe->ops.set_voltage) {
err = fe->ops.set_voltage(fe,
(enum fe_sec_voltage)parg);
fepriv->voltage = (enum fe_sec_voltage)parg;
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
}
break;
case FE_DISHNETWORK_SEND_LEGACY_CMD:
if (fe->ops.dishnetwork_send_legacy_command) {
err = fe->ops.dishnetwork_send_legacy_command(fe,
(unsigned long)parg);
fepriv->state = FESTATE_DISEQC;
fepriv->status = 0;
} else if (fe->ops.set_voltage) {
unsigned long swcmd = ((unsigned long) parg) << 1;
ktime_t nexttime;
ktime_t tv[10];
int i;
u8 last = 1;
if (dvb_frontend_debug)
printk("%s switch command: 0x%04lx\n", __func__, swcmd);
nexttime = ktime_get_real();
if (dvb_frontend_debug)
tv[0] = nexttime;
fe->ops.set_voltage(fe, SEC_VOLTAGE_18);
dvb_frontend_sleep_until(&nexttime, 32000);
for (i = 0; i < 9; i++) {
if (dvb_frontend_debug)
tv[i+1] = ktime_get_real();
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
printk("%d: %d\n", i,
(int) ktime_us_delta(tv[i], tv[i-1]));
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
case FE_SET_FRONTEND:
err = dvbv3_set_delivery_system(fe);
if (err)
break;
err = dtv_property_cache_sync(fe, c, parg);
if (err)
break;
err = dtv_set_frontend(fe);
break;
case FE_GET_EVENT:
err = dvb_frontend_get_event (fe, parg, file->f_flags);
break;
case FE_GET_FRONTEND:
err = dtv_get_frontend(fe, parg);
break;
case FE_SET_FRONTEND_TUNE_MODE:
fepriv->tune_mode_flags = (unsigned long) parg;
err = 0;
break;
}
return err;
}
static unsigned int dvb_frontend_poll(struct file *file, struct poll_table_struct *wait)
{
struct dvb_device *dvbdev = file->private_data;
struct dvb_frontend *fe = dvbdev->priv;
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dev_dbg_ratelimited(fe->dvb->device, "%s:\n", __func__);
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
dev_dbg(fe->dvb->device, "%s:\n", __func__);
if (fe->exit == DVB_FE_DEVICE_REMOVED)
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
dev_dbg(fe->dvb->device, "%s:\n", __func__);
if ((file->f_flags & O_ACCMODE) != O_RDONLY) {
fepriv->release_jiffies = jiffies;
mb();
}
ret = dvb_generic_release (inode, file);
if (dvbdev->users == -1) {
wake_up(&fepriv->wait_queue);
if (fe->exit != DVB_FE_NO_EXIT)
wake_up(&dvbdev->wait_queue);
if (fe->ops.ts_bus_ctrl)
fe->ops.ts_bus_ctrl(fe, 0);
}
return ret;
}
int dvb_frontend_suspend(struct dvb_frontend *fe)
{
int ret = 0;
dev_dbg(fe->dvb->device, "%s: adap=%d fe=%d\n", __func__, fe->dvb->num,
fe->id);
if (fe->ops.tuner_ops.suspend)
ret = fe->ops.tuner_ops.suspend(fe);
else if (fe->ops.tuner_ops.sleep)
ret = fe->ops.tuner_ops.sleep(fe);
if (fe->ops.sleep)
ret = fe->ops.sleep(fe);
return ret;
}
int dvb_frontend_resume(struct dvb_frontend *fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
int ret = 0;
dev_dbg(fe->dvb->device, "%s: adap=%d fe=%d\n", __func__, fe->dvb->num,
fe->id);
fe->exit = DVB_FE_DEVICE_RESUME;
if (fe->ops.init)
ret = fe->ops.init(fe);
if (fe->ops.tuner_ops.resume)
ret = fe->ops.tuner_ops.resume(fe);
else if (fe->ops.tuner_ops.init)
ret = fe->ops.tuner_ops.init(fe);
fe->exit = DVB_FE_NO_EXIT;
fepriv->state = FESTATE_RETUNE;
dvb_frontend_wakeup(fe);
return ret;
}
int dvb_register_frontend(struct dvb_adapter* dvb,
struct dvb_frontend* fe)
{
struct dvb_frontend_private *fepriv;
const struct dvb_device dvbdev_template = {
.users = ~0,
.writers = 1,
.readers = (~0)-1,
.fops = &dvb_frontend_fops,
#if defined(CONFIG_MEDIA_CONTROLLER_DVB)
.name = fe->ops.info.name,
#endif
.kernel_ioctl = dvb_frontend_ioctl
};
dev_dbg(dvb->device, "%s:\n", __func__);
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
dev_info(fe->dvb->device,
"DVB: registering adapter %i frontend %i (%s)...\n",
fe->dvb->num, fe->id, fe->ops.info.name);
dvb_register_device (fe->dvb, &fepriv->dvbdev, &dvbdev_template,
fe, DVB_DEVICE_FRONTEND);
fe->dtv_property_cache.delivery_system = fe->ops.delsys[0];
dvb_frontend_clear_cache(fe);
mutex_unlock(&frontend_mutex);
return 0;
}
int dvb_unregister_frontend(struct dvb_frontend* fe)
{
struct dvb_frontend_private *fepriv = fe->frontend_priv;
dev_dbg(fe->dvb->device, "%s:\n", __func__);
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
dvb_detach(fe->ops.release_sec);
}
if (fe->ops.tuner_ops.release) {
fe->ops.tuner_ops.release(fe);
dvb_detach(fe->ops.tuner_ops.release);
}
if (fe->ops.analog_ops.release) {
fe->ops.analog_ops.release(fe);
dvb_detach(fe->ops.analog_ops.release);
}
ptr = (void*)fe->ops.release;
if (ptr) {
fe->ops.release(fe);
dvb_detach(ptr);
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
