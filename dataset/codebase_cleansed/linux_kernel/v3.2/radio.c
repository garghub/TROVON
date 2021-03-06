static int uwb_radio_select_channel(struct uwb_rc *rc)
{
if (rc->active_pals == 0)
return -1;
if (rc->beaconing_forced)
return rc->beaconing_forced;
return 9;
}
static void uwb_radio_channel_changed(struct uwb_rc *rc, int channel)
{
struct uwb_pal *pal;
list_for_each_entry(pal, &rc->pals, node) {
if (pal->channel && channel != pal->channel) {
pal->channel = channel;
if (pal->channel_changed)
pal->channel_changed(pal, pal->channel);
}
}
}
static int uwb_radio_change_channel(struct uwb_rc *rc, int channel)
{
int ret = 0;
if (channel == -1)
uwb_radio_channel_changed(rc, channel);
if (channel != rc->beaconing) {
if (rc->beaconing != -1 && channel != -1) {
ret = uwb_radio_change_channel(rc, -1);
if (ret < 0)
return ret;
}
ret = uwb_rc_beacon(rc, channel, 0);
}
if (channel != -1)
uwb_radio_channel_changed(rc, rc->beaconing);
return ret;
}
int uwb_radio_start(struct uwb_pal *pal)
{
struct uwb_rc *rc = pal->rc;
int ret = 0;
mutex_lock(&rc->uwb_dev.mutex);
if (!pal->channel) {
pal->channel = -1;
rc->active_pals++;
ret = uwb_radio_change_channel(rc, uwb_radio_select_channel(rc));
}
mutex_unlock(&rc->uwb_dev.mutex);
return ret;
}
void uwb_radio_stop(struct uwb_pal *pal)
{
struct uwb_rc *rc = pal->rc;
mutex_lock(&rc->uwb_dev.mutex);
if (pal->channel) {
rc->active_pals--;
uwb_radio_change_channel(rc, uwb_radio_select_channel(rc));
pal->channel = 0;
}
mutex_unlock(&rc->uwb_dev.mutex);
}
int uwb_radio_force_channel(struct uwb_rc *rc, int channel)
{
int ret = 0;
mutex_lock(&rc->uwb_dev.mutex);
rc->beaconing_forced = channel;
ret = uwb_radio_change_channel(rc, uwb_radio_select_channel(rc));
mutex_unlock(&rc->uwb_dev.mutex);
return ret;
}
int uwb_radio_setup(struct uwb_rc *rc)
{
return uwb_rc_reset(rc);
}
void uwb_radio_reset_state(struct uwb_rc *rc)
{
struct uwb_pal *pal;
mutex_lock(&rc->uwb_dev.mutex);
list_for_each_entry(pal, &rc->pals, node) {
if (pal->channel) {
pal->channel = -1;
if (pal->channel_changed)
pal->channel_changed(pal, -1);
}
}
rc->beaconing = -1;
rc->scanning = -1;
mutex_unlock(&rc->uwb_dev.mutex);
}
void uwb_radio_shutdown(struct uwb_rc *rc)
{
uwb_radio_reset_state(rc);
uwb_rc_reset(rc);
}
