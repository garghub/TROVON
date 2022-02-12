static void sms_board_dvb3_event(struct smsdvb_client_t *client,
enum SMS_DVB3_EVENTS event) {
struct smscore_device_t *coredev = client->coredev;
switch (event) {
case DVB3_EVENT_INIT:
sms_debug("DVB3_EVENT_INIT");
sms_board_event(coredev, BOARD_EVENT_BIND);
break;
case DVB3_EVENT_SLEEP:
sms_debug("DVB3_EVENT_SLEEP");
sms_board_event(coredev, BOARD_EVENT_POWER_SUSPEND);
break;
case DVB3_EVENT_HOTPLUG:
sms_debug("DVB3_EVENT_HOTPLUG");
sms_board_event(coredev, BOARD_EVENT_POWER_INIT);
break;
case DVB3_EVENT_FE_LOCK:
if (client->event_fe_state != DVB3_EVENT_FE_LOCK) {
client->event_fe_state = DVB3_EVENT_FE_LOCK;
sms_debug("DVB3_EVENT_FE_LOCK");
sms_board_event(coredev, BOARD_EVENT_FE_LOCK);
}
break;
case DVB3_EVENT_FE_UNLOCK:
if (client->event_fe_state != DVB3_EVENT_FE_UNLOCK) {
client->event_fe_state = DVB3_EVENT_FE_UNLOCK;
sms_debug("DVB3_EVENT_FE_UNLOCK");
sms_board_event(coredev, BOARD_EVENT_FE_UNLOCK);
}
break;
case DVB3_EVENT_UNC_OK:
if (client->event_unc_state != DVB3_EVENT_UNC_OK) {
client->event_unc_state = DVB3_EVENT_UNC_OK;
sms_debug("DVB3_EVENT_UNC_OK");
sms_board_event(coredev, BOARD_EVENT_MULTIPLEX_OK);
}
break;
case DVB3_EVENT_UNC_ERR:
if (client->event_unc_state != DVB3_EVENT_UNC_ERR) {
client->event_unc_state = DVB3_EVENT_UNC_ERR;
sms_debug("DVB3_EVENT_UNC_ERR");
sms_board_event(coredev, BOARD_EVENT_MULTIPLEX_ERRORS);
}
break;
default:
sms_err("Unknown dvb3 api event");
break;
}
}
static void smsdvb_stats_not_ready(struct dvb_frontend *fe)
{
struct smsdvb_client_t *client =
container_of(fe, struct smsdvb_client_t, frontend);
struct smscore_device_t *coredev = client->coredev;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int i, n_layers;
switch (smscore_get_device_mode(coredev)) {
case DEVICE_MODE_ISDBT:
case DEVICE_MODE_ISDBT_BDA:
n_layers = 4;
break;
default:
n_layers = 1;
}
c->strength.len = 1;
c->cnr.len = 1;
c->strength.stat[0].scale = FE_SCALE_DECIBEL;
c->cnr.stat[0].scale = FE_SCALE_DECIBEL;
c->post_bit_error.len = n_layers;
c->post_bit_count.len = n_layers;
c->block_error.len = n_layers;
c->block_count.len = n_layers;
for (i = 0; i < n_layers; i++) {
c->post_bit_error.stat[i].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.stat[i].scale = FE_SCALE_NOT_AVAILABLE;
c->block_error.stat[i].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.stat[i].scale = FE_SCALE_NOT_AVAILABLE;
}
}
static inline int sms_to_mode(u32 mode)
{
switch (mode) {
case 2:
return TRANSMISSION_MODE_2K;
case 4:
return TRANSMISSION_MODE_4K;
case 8:
return TRANSMISSION_MODE_8K;
}
return TRANSMISSION_MODE_AUTO;
}
static inline int sms_to_status(u32 is_demod_locked, u32 is_rf_locked)
{
if (is_demod_locked)
return FE_HAS_SIGNAL | FE_HAS_CARRIER | FE_HAS_VITERBI |
FE_HAS_SYNC | FE_HAS_LOCK;
if (is_rf_locked)
return FE_HAS_SIGNAL | FE_HAS_CARRIER;
return 0;
}
static inline u32 sms_to_bw(u32 value)
{
return value * 1000000;
}
static void smsdvb_update_tx_params(struct smsdvb_client_t *client,
struct sms_tx_stats *p)
{
struct dvb_frontend *fe = &client->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
c->frequency = p->frequency;
client->fe_status = sms_to_status(p->is_demod_locked, 0);
c->bandwidth_hz = sms_to_bw(p->bandwidth);
c->transmission_mode = sms_to_mode(p->transmission_mode);
c->guard_interval = sms_to_guard_interval(p->guard_interval);
c->code_rate_HP = sms_to_code_rate(p->code_rate);
c->code_rate_LP = sms_to_code_rate(p->lp_code_rate);
c->hierarchy = sms_to_hierarchy(p->hierarchy);
c->modulation = sms_to_modulation(p->constellation);
}
static void smsdvb_update_per_slices(struct smsdvb_client_t *client,
struct RECEPTION_STATISTICS_PER_SLICES_S *p)
{
struct dvb_frontend *fe = &client->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u64 tmp;
client->fe_status = sms_to_status(p->is_demod_locked, p->is_rf_locked);
c->modulation = sms_to_modulation(p->constellation);
c->strength.stat[0].uvalue = p->in_band_power * 1000;
c->cnr.stat[0].svalue = p->snr * 1000;
if (!p->is_demod_locked)
return;
client->last_per = c->block_error.stat[0].uvalue;
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->block_error.stat[0].uvalue += p->ets_packets;
c->block_count.stat[0].uvalue += p->ets_packets + p->ts_packets;
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue += p->ber_error_count;
c->post_bit_count.stat[0].uvalue += p->ber_bit_count;
tmp = p->ets_packets * 65535;
if (p->ts_packets + p->ets_packets)
do_div(tmp, p->ts_packets + p->ets_packets);
client->legacy_per = tmp;
}
static void smsdvb_update_dvb_stats(struct smsdvb_client_t *client,
struct sms_stats *p)
{
struct dvb_frontend *fe = &client->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (client->prt_dvb_stats)
client->prt_dvb_stats(client->debug_data, p);
client->fe_status = sms_to_status(p->is_demod_locked, p->is_rf_locked);
c->frequency = p->frequency;
client->fe_status = sms_to_status(p->is_demod_locked, 0);
c->bandwidth_hz = sms_to_bw(p->bandwidth);
c->transmission_mode = sms_to_mode(p->transmission_mode);
c->guard_interval = sms_to_guard_interval(p->guard_interval);
c->code_rate_HP = sms_to_code_rate(p->code_rate);
c->code_rate_LP = sms_to_code_rate(p->lp_code_rate);
c->hierarchy = sms_to_hierarchy(p->hierarchy);
c->modulation = sms_to_modulation(p->constellation);
c->lna = p->is_external_lna_on ? 1 : 0;
c->cnr.stat[0].svalue = p->SNR * 1000;
c->strength.stat[0].uvalue = p->in_band_pwr * 1000;
if (!p->is_demod_locked)
return;
client->last_per = c->block_error.stat[0].uvalue;
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->block_error.stat[0].uvalue += p->error_ts_packets;
c->block_count.stat[0].uvalue += p->total_ts_packets;
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue += p->ber_error_count;
c->post_bit_count.stat[0].uvalue += p->ber_bit_count;
client->legacy_ber = p->ber;
}
static void smsdvb_update_isdbt_stats(struct smsdvb_client_t *client,
struct sms_isdbt_stats *p)
{
struct dvb_frontend *fe = &client->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct sms_isdbt_layer_stats *lr;
int i, n_layers;
if (client->prt_isdb_stats)
client->prt_isdb_stats(client->debug_data, p);
client->fe_status = sms_to_status(p->is_demod_locked, p->is_rf_locked);
if (p->statistics_type == 0) {
c->strength.stat[0].uvalue = ((s32)p->transmission_mode) * 1000;
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
return;
}
c->frequency = p->frequency;
c->bandwidth_hz = sms_to_bw(p->bandwidth);
c->transmission_mode = sms_to_mode(p->transmission_mode);
c->guard_interval = sms_to_guard_interval(p->guard_interval);
c->isdbt_partial_reception = p->partial_reception ? 1 : 0;
n_layers = p->num_of_layers;
if (n_layers < 1)
n_layers = 1;
if (n_layers > 3)
n_layers = 3;
c->isdbt_layer_enabled = 0;
c->lna = p->is_external_lna_on ? 1 : 0;
c->cnr.stat[0].svalue = p->SNR * 1000;
c->strength.stat[0].uvalue = p->in_band_pwr * 1000;
if (!p->is_demod_locked)
return;
client->last_per = c->block_error.stat[0].uvalue;
c->block_error.stat[0].uvalue = 0;
c->block_count.stat[0].uvalue = 0;
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue = 0;
c->post_bit_count.stat[0].uvalue = 0;
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
for (i = 0; i < n_layers; i++) {
lr = &p->layer_info[i];
if (lr->number_of_segments > 0 && lr->number_of_segments < 13) {
c->isdbt_layer_enabled |= 1 << i;
c->layer[i].segment_count = lr->number_of_segments;
} else {
continue;
}
c->layer[i].modulation = sms_to_modulation(lr->constellation);
c->block_error.stat[i + 1].scale = FE_SCALE_COUNTER;
c->block_count.stat[i + 1].scale = FE_SCALE_COUNTER;
c->block_error.stat[i + 1].uvalue += lr->error_ts_packets;
c->block_count.stat[i + 1].uvalue += lr->total_ts_packets;
c->block_error.stat[0].uvalue += lr->error_ts_packets;
c->block_count.stat[0].uvalue += lr->total_ts_packets;
c->post_bit_error.stat[i + 1].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[i + 1].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[i + 1].uvalue += lr->ber_error_count;
c->post_bit_count.stat[i + 1].uvalue += lr->ber_bit_count;
c->post_bit_error.stat[0].uvalue += lr->ber_error_count;
c->post_bit_count.stat[0].uvalue += lr->ber_bit_count;
}
}
static void smsdvb_update_isdbt_stats_ex(struct smsdvb_client_t *client,
struct sms_isdbt_stats_ex *p)
{
struct dvb_frontend *fe = &client->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct sms_isdbt_layer_stats *lr;
int i, n_layers;
if (client->prt_isdb_stats_ex)
client->prt_isdb_stats_ex(client->debug_data, p);
c->frequency = p->frequency;
client->fe_status = sms_to_status(p->is_demod_locked, 0);
c->bandwidth_hz = sms_to_bw(p->bandwidth);
c->transmission_mode = sms_to_mode(p->transmission_mode);
c->guard_interval = sms_to_guard_interval(p->guard_interval);
c->isdbt_partial_reception = p->partial_reception ? 1 : 0;
n_layers = p->num_of_layers;
if (n_layers < 1)
n_layers = 1;
if (n_layers > 3)
n_layers = 3;
c->isdbt_layer_enabled = 0;
c->lna = p->is_external_lna_on ? 1 : 0;
c->cnr.stat[0].svalue = p->SNR * 1000;
c->strength.stat[0].uvalue = p->in_band_pwr * 1000;
if (!p->is_demod_locked)
return;
client->last_per = c->block_error.stat[0].uvalue;
c->block_error.stat[0].uvalue = 0;
c->block_count.stat[0].uvalue = 0;
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue = 0;
c->post_bit_count.stat[0].uvalue = 0;
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.len = n_layers + 1;
c->post_bit_count.len = n_layers + 1;
c->block_error.len = n_layers + 1;
c->block_count.len = n_layers + 1;
for (i = 0; i < n_layers; i++) {
lr = &p->layer_info[i];
if (lr->number_of_segments > 0 && lr->number_of_segments < 13) {
c->isdbt_layer_enabled |= 1 << i;
c->layer[i].segment_count = lr->number_of_segments;
} else {
continue;
}
c->layer[i].modulation = sms_to_modulation(lr->constellation);
c->block_error.stat[i + 1].scale = FE_SCALE_COUNTER;
c->block_count.stat[i + 1].scale = FE_SCALE_COUNTER;
c->block_error.stat[i + 1].uvalue += lr->error_ts_packets;
c->block_count.stat[i + 1].uvalue += lr->total_ts_packets;
c->block_error.stat[0].uvalue += lr->error_ts_packets;
c->block_count.stat[0].uvalue += lr->total_ts_packets;
c->post_bit_error.stat[i + 1].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[i + 1].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[i + 1].uvalue += lr->ber_error_count;
c->post_bit_count.stat[i + 1].uvalue += lr->ber_bit_count;
c->post_bit_error.stat[0].uvalue += lr->ber_error_count;
c->post_bit_count.stat[0].uvalue += lr->ber_bit_count;
}
}
static int smsdvb_onresponse(void *context, struct smscore_buffer_t *cb)
{
struct smsdvb_client_t *client = (struct smsdvb_client_t *) context;
struct sms_msg_hdr *phdr = (struct sms_msg_hdr *) (((u8 *) cb->p)
+ cb->offset);
void *p = phdr + 1;
struct dvb_frontend *fe = &client->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
bool is_status_update = false;
switch (phdr->msg_type) {
case MSG_SMS_DVBT_BDA_DATA:
if (client->feed_users && client->has_tuned)
dvb_dmx_swfilter(&client->demux, p,
cb->size - sizeof(struct sms_msg_hdr));
break;
case MSG_SMS_RF_TUNE_RES:
case MSG_SMS_ISDBT_TUNE_RES:
complete(&client->tune_done);
break;
case MSG_SMS_SIGNAL_DETECTED_IND:
client->fe_status = FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC |
FE_HAS_LOCK;
is_status_update = true;
break;
case MSG_SMS_NO_SIGNAL_IND:
client->fe_status = 0;
is_status_update = true;
break;
case MSG_SMS_TRANSMISSION_IND:
smsdvb_update_tx_params(client, p);
is_status_update = true;
break;
case MSG_SMS_HO_PER_SLICES_IND:
smsdvb_update_per_slices(client, p);
is_status_update = true;
break;
case MSG_SMS_GET_STATISTICS_RES:
switch (smscore_get_device_mode(client->coredev)) {
case DEVICE_MODE_ISDBT:
case DEVICE_MODE_ISDBT_BDA:
smsdvb_update_isdbt_stats(client, p);
break;
default:
smsdvb_update_dvb_stats(client, p + sizeof(u32));
}
is_status_update = true;
break;
case MSG_SMS_GET_STATISTICS_EX_RES:
smsdvb_update_isdbt_stats_ex(client, p + sizeof(u32));
is_status_update = true;
break;
default:
sms_info("message not handled");
}
smscore_putbuffer(client->coredev, cb);
if (is_status_update) {
if (client->fe_status & FE_HAS_LOCK) {
sms_board_dvb3_event(client, DVB3_EVENT_FE_LOCK);
if (client->last_per == c->block_error.stat[0].uvalue)
sms_board_dvb3_event(client, DVB3_EVENT_UNC_OK);
else
sms_board_dvb3_event(client, DVB3_EVENT_UNC_ERR);
client->has_tuned = true;
} else {
smsdvb_stats_not_ready(fe);
client->has_tuned = false;
sms_board_dvb3_event(client, DVB3_EVENT_FE_UNLOCK);
}
complete(&client->stats_done);
}
return 0;
}
static void smsdvb_unregister_client(struct smsdvb_client_t *client)
{
list_del(&client->entry);
smsdvb_debugfs_release(client);
smscore_unregister_client(client->smsclient);
dvb_unregister_frontend(&client->frontend);
dvb_dmxdev_release(&client->dmxdev);
dvb_dmx_release(&client->demux);
dvb_unregister_adapter(&client->adapter);
kfree(client);
}
static void smsdvb_onremove(void *context)
{
kmutex_lock(&g_smsdvb_clientslock);
smsdvb_unregister_client((struct smsdvb_client_t *) context);
kmutex_unlock(&g_smsdvb_clientslock);
}
static int smsdvb_start_feed(struct dvb_demux_feed *feed)
{
struct smsdvb_client_t *client =
container_of(feed->demux, struct smsdvb_client_t, demux);
struct sms_msg_data pid_msg;
sms_debug("add pid %d(%x)",
feed->pid, feed->pid);
client->feed_users++;
pid_msg.x_msg_header.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
pid_msg.x_msg_header.msg_dst_id = HIF_TASK;
pid_msg.x_msg_header.msg_flags = 0;
pid_msg.x_msg_header.msg_type = MSG_SMS_ADD_PID_FILTER_REQ;
pid_msg.x_msg_header.msg_length = sizeof(pid_msg);
pid_msg.msg_data[0] = feed->pid;
return smsclient_sendrequest(client->smsclient,
&pid_msg, sizeof(pid_msg));
}
static int smsdvb_stop_feed(struct dvb_demux_feed *feed)
{
struct smsdvb_client_t *client =
container_of(feed->demux, struct smsdvb_client_t, demux);
struct sms_msg_data pid_msg;
sms_debug("remove pid %d(%x)",
feed->pid, feed->pid);
client->feed_users--;
pid_msg.x_msg_header.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
pid_msg.x_msg_header.msg_dst_id = HIF_TASK;
pid_msg.x_msg_header.msg_flags = 0;
pid_msg.x_msg_header.msg_type = MSG_SMS_REMOVE_PID_FILTER_REQ;
pid_msg.x_msg_header.msg_length = sizeof(pid_msg);
pid_msg.msg_data[0] = feed->pid;
return smsclient_sendrequest(client->smsclient,
&pid_msg, sizeof(pid_msg));
}
static int smsdvb_sendrequest_and_wait(struct smsdvb_client_t *client,
void *buffer, size_t size,
struct completion *completion)
{
int rc;
rc = smsclient_sendrequest(client->smsclient, buffer, size);
if (rc < 0)
return rc;
return wait_for_completion_timeout(completion,
msecs_to_jiffies(2000)) ?
0 : -ETIME;
}
static int smsdvb_send_statistics_request(struct smsdvb_client_t *client)
{
int rc;
struct sms_msg_hdr msg;
if (client->get_stats_jiffies &&
(!time_after(jiffies, client->get_stats_jiffies)))
return 0;
client->get_stats_jiffies = jiffies + msecs_to_jiffies(100);
msg.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
msg.msg_dst_id = HIF_TASK;
msg.msg_flags = 0;
msg.msg_length = sizeof(msg);
switch (smscore_get_device_mode(client->coredev)) {
case DEVICE_MODE_ISDBT:
case DEVICE_MODE_ISDBT_BDA:
if (client->coredev->fw_version >= 0x800)
msg.msg_type = MSG_SMS_GET_STATISTICS_EX_REQ;
else
msg.msg_type = MSG_SMS_GET_STATISTICS_REQ;
break;
default:
msg.msg_type = MSG_SMS_GET_STATISTICS_REQ;
}
rc = smsdvb_sendrequest_and_wait(client, &msg, sizeof(msg),
&client->stats_done);
return rc;
}
static inline int led_feedback(struct smsdvb_client_t *client)
{
if (!(client->fe_status & FE_HAS_LOCK))
return sms_board_led_feedback(client->coredev, SMS_LED_OFF);
return sms_board_led_feedback(client->coredev,
(client->legacy_ber == 0) ?
SMS_LED_HI : SMS_LED_LO);
}
static int smsdvb_read_status(struct dvb_frontend *fe, fe_status_t *stat)
{
int rc;
struct smsdvb_client_t *client;
client = container_of(fe, struct smsdvb_client_t, frontend);
rc = smsdvb_send_statistics_request(client);
*stat = client->fe_status;
led_feedback(client);
return rc;
}
static int smsdvb_read_ber(struct dvb_frontend *fe, u32 *ber)
{
int rc;
struct smsdvb_client_t *client;
client = container_of(fe, struct smsdvb_client_t, frontend);
rc = smsdvb_send_statistics_request(client);
*ber = client->legacy_ber;
led_feedback(client);
return rc;
}
static int smsdvb_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc;
s32 power = (s32) c->strength.stat[0].uvalue;
struct smsdvb_client_t *client;
client = container_of(fe, struct smsdvb_client_t, frontend);
rc = smsdvb_send_statistics_request(client);
if (power < -95)
*strength = 0;
else if (power > -29)
*strength = 65535;
else
*strength = (power + 95) * 65535 / 66;
led_feedback(client);
return rc;
}
static int smsdvb_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc;
struct smsdvb_client_t *client;
client = container_of(fe, struct smsdvb_client_t, frontend);
rc = smsdvb_send_statistics_request(client);
*snr = ((u32)c->cnr.stat[0].svalue) / 100;
led_feedback(client);
return rc;
}
static int smsdvb_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
int rc;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct smsdvb_client_t *client;
client = container_of(fe, struct smsdvb_client_t, frontend);
rc = smsdvb_send_statistics_request(client);
*ucblocks = c->block_error.stat[0].uvalue;
led_feedback(client);
return rc;
}
static int smsdvb_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
sms_debug("");
tune->min_delay_ms = 400;
tune->step_size = 250000;
tune->max_drift = 0;
return 0;
}
static int smsdvb_dvbt_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct smsdvb_client_t *client =
container_of(fe, struct smsdvb_client_t, frontend);
struct {
struct sms_msg_hdr msg;
u32 Data[3];
} msg;
int ret;
client->fe_status = 0;
client->event_fe_state = -1;
client->event_unc_state = -1;
fe->dtv_property_cache.delivery_system = SYS_DVBT;
msg.msg.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
msg.msg.msg_dst_id = HIF_TASK;
msg.msg.msg_flags = 0;
msg.msg.msg_type = MSG_SMS_RF_TUNE_REQ;
msg.msg.msg_length = sizeof(msg);
msg.Data[0] = c->frequency;
msg.Data[2] = 12000000;
sms_info("%s: freq %d band %d", __func__, c->frequency,
c->bandwidth_hz);
switch (c->bandwidth_hz / 1000000) {
case 8:
msg.Data[1] = BW_8_MHZ;
break;
case 7:
msg.Data[1] = BW_7_MHZ;
break;
case 6:
msg.Data[1] = BW_6_MHZ;
break;
case 0:
return -EOPNOTSUPP;
default:
return -EINVAL;
}
ret = sms_board_lna_control(client->coredev, 0);
if (ret == 0) {
fe_status_t status;
ret = smsdvb_sendrequest_and_wait(client, &msg, sizeof(msg),
&client->tune_done);
smsdvb_read_status(fe, &status);
if (status & FE_HAS_LOCK)
return ret;
sms_board_lna_control(client->coredev, 1);
}
return smsdvb_sendrequest_and_wait(client, &msg, sizeof(msg),
&client->tune_done);
}
static int smsdvb_isdbt_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct smsdvb_client_t *client =
container_of(fe, struct smsdvb_client_t, frontend);
int board_id = smscore_get_board_id(client->coredev);
struct sms_board *board = sms_get_board(board_id);
enum sms_device_type_st type = board->type;
int ret;
struct {
struct sms_msg_hdr msg;
u32 Data[4];
} msg;
fe->dtv_property_cache.delivery_system = SYS_ISDBT;
msg.msg.msg_src_id = DVBT_BDA_CONTROL_MSG_ID;
msg.msg.msg_dst_id = HIF_TASK;
msg.msg.msg_flags = 0;
msg.msg.msg_type = MSG_SMS_ISDBT_TUNE_REQ;
msg.msg.msg_length = sizeof(msg);
if (c->isdbt_sb_segment_idx == -1)
c->isdbt_sb_segment_idx = 0;
if (!c->isdbt_layer_enabled)
c->isdbt_layer_enabled = 7;
msg.Data[0] = c->frequency;
msg.Data[1] = BW_ISDBT_1SEG;
msg.Data[2] = 12000000;
msg.Data[3] = c->isdbt_sb_segment_idx;
if (c->isdbt_partial_reception) {
if ((type == SMS_PELE || type == SMS_RIO) &&
c->isdbt_sb_segment_count > 3)
msg.Data[1] = BW_ISDBT_13SEG;
else if (c->isdbt_sb_segment_count > 1)
msg.Data[1] = BW_ISDBT_3SEG;
} else if (type == SMS_PELE || type == SMS_RIO)
msg.Data[1] = BW_ISDBT_13SEG;
c->bandwidth_hz = 6000000;
sms_info("%s: freq %d segwidth %d segindex %d", __func__,
c->frequency, c->isdbt_sb_segment_count,
c->isdbt_sb_segment_idx);
ret = sms_board_lna_control(client->coredev, 0);
if (ret == 0) {
fe_status_t status;
ret = smsdvb_sendrequest_and_wait(client, &msg, sizeof(msg),
&client->tune_done);
smsdvb_read_status(fe, &status);
if (status & FE_HAS_LOCK)
return ret;
sms_board_lna_control(client->coredev, 1);
}
return smsdvb_sendrequest_and_wait(client, &msg, sizeof(msg),
&client->tune_done);
}
static int smsdvb_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct smsdvb_client_t *client =
container_of(fe, struct smsdvb_client_t, frontend);
struct smscore_device_t *coredev = client->coredev;
smsdvb_stats_not_ready(fe);
c->strength.stat[0].uvalue = 0;
c->cnr.stat[0].uvalue = 0;
client->has_tuned = false;
switch (smscore_get_device_mode(coredev)) {
case DEVICE_MODE_DVBT:
case DEVICE_MODE_DVBT_BDA:
return smsdvb_dvbt_set_frontend(fe);
case DEVICE_MODE_ISDBT:
case DEVICE_MODE_ISDBT_BDA:
return smsdvb_isdbt_set_frontend(fe);
default:
return -EINVAL;
}
}
static int smsdvb_get_frontend(struct dvb_frontend *fe)
{
return 0;
}
static int smsdvb_init(struct dvb_frontend *fe)
{
struct smsdvb_client_t *client =
container_of(fe, struct smsdvb_client_t, frontend);
sms_board_power(client->coredev, 1);
sms_board_dvb3_event(client, DVB3_EVENT_INIT);
return 0;
}
static int smsdvb_sleep(struct dvb_frontend *fe)
{
struct smsdvb_client_t *client =
container_of(fe, struct smsdvb_client_t, frontend);
sms_board_led_feedback(client->coredev, SMS_LED_OFF);
sms_board_power(client->coredev, 0);
sms_board_dvb3_event(client, DVB3_EVENT_SLEEP);
return 0;
}
static void smsdvb_release(struct dvb_frontend *fe)
{
}
static int smsdvb_hotplug(struct smscore_device_t *coredev,
struct device *device, int arrival)
{
struct smsclient_params_t params;
struct smsdvb_client_t *client;
int rc;
if (!arrival)
return 0;
client = kzalloc(sizeof(struct smsdvb_client_t), GFP_KERNEL);
if (!client) {
sms_err("kmalloc() failed");
return -ENOMEM;
}
rc = dvb_register_adapter(&client->adapter,
sms_get_board(
smscore_get_board_id(coredev))->name,
THIS_MODULE, device, adapter_nr);
if (rc < 0) {
sms_err("dvb_register_adapter() failed %d", rc);
goto adapter_error;
}
client->demux.dmx.capabilities = DMX_TS_FILTERING;
client->demux.filternum = 32;
client->demux.feednum = 32;
client->demux.start_feed = smsdvb_start_feed;
client->demux.stop_feed = smsdvb_stop_feed;
rc = dvb_dmx_init(&client->demux);
if (rc < 0) {
sms_err("dvb_dmx_init failed %d", rc);
goto dvbdmx_error;
}
client->dmxdev.filternum = 32;
client->dmxdev.demux = &client->demux.dmx;
client->dmxdev.capabilities = 0;
rc = dvb_dmxdev_init(&client->dmxdev, &client->adapter);
if (rc < 0) {
sms_err("dvb_dmxdev_init failed %d", rc);
goto dmxdev_error;
}
memcpy(&client->frontend.ops, &smsdvb_fe_ops,
sizeof(struct dvb_frontend_ops));
switch (smscore_get_device_mode(coredev)) {
case DEVICE_MODE_DVBT:
case DEVICE_MODE_DVBT_BDA:
client->frontend.ops.delsys[0] = SYS_DVBT;
break;
case DEVICE_MODE_ISDBT:
case DEVICE_MODE_ISDBT_BDA:
client->frontend.ops.delsys[0] = SYS_ISDBT;
break;
}
rc = dvb_register_frontend(&client->adapter, &client->frontend);
if (rc < 0) {
sms_err("frontend registration failed %d", rc);
goto frontend_error;
}
params.initial_id = 1;
params.data_type = MSG_SMS_DVBT_BDA_DATA;
params.onresponse_handler = smsdvb_onresponse;
params.onremove_handler = smsdvb_onremove;
params.context = client;
rc = smscore_register_client(coredev, &params, &client->smsclient);
if (rc < 0) {
sms_err("smscore_register_client() failed %d", rc);
goto client_error;
}
client->coredev = coredev;
init_completion(&client->tune_done);
init_completion(&client->stats_done);
kmutex_lock(&g_smsdvb_clientslock);
list_add(&client->entry, &g_smsdvb_clients);
kmutex_unlock(&g_smsdvb_clientslock);
client->event_fe_state = -1;
client->event_unc_state = -1;
sms_board_dvb3_event(client, DVB3_EVENT_HOTPLUG);
sms_info("success");
sms_board_setup(coredev);
if (smsdvb_debugfs_create(client) < 0)
sms_info("failed to create debugfs node");
return 0;
client_error:
dvb_unregister_frontend(&client->frontend);
frontend_error:
dvb_dmxdev_release(&client->dmxdev);
dmxdev_error:
dvb_dmx_release(&client->demux);
dvbdmx_error:
dvb_unregister_adapter(&client->adapter);
adapter_error:
kfree(client);
return rc;
}
static int __init smsdvb_module_init(void)
{
int rc;
INIT_LIST_HEAD(&g_smsdvb_clients);
kmutex_init(&g_smsdvb_clientslock);
smsdvb_debugfs_register();
rc = smscore_register_hotplug(smsdvb_hotplug);
sms_debug("");
return rc;
}
static void __exit smsdvb_module_exit(void)
{
smscore_unregister_hotplug(smsdvb_hotplug);
kmutex_lock(&g_smsdvb_clientslock);
while (!list_empty(&g_smsdvb_clients))
smsdvb_unregister_client((struct smsdvb_client_t *)g_smsdvb_clients.next);
smsdvb_debugfs_unregister();
kmutex_unlock(&g_smsdvb_clientslock);
}
