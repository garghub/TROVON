static int codec_exec_verb(struct hdac_device *dev, unsigned int cmd,
unsigned int flags, unsigned int *res)
{
struct hda_codec *codec = container_of(dev, struct hda_codec, core);
struct hda_bus *bus = codec->bus;
int err;
if (cmd == ~0)
return -1;
again:
snd_hda_power_up_pm(codec);
mutex_lock(&bus->core.cmd_mutex);
if (flags & HDA_RW_NO_RESPONSE_FALLBACK)
bus->no_response_fallback = 1;
err = snd_hdac_bus_exec_verb_unlocked(&bus->core, codec->core.addr,
cmd, res);
bus->no_response_fallback = 0;
mutex_unlock(&bus->core.cmd_mutex);
snd_hda_power_down_pm(codec);
if (!codec_in_pm(codec) && res && err == -EAGAIN) {
if (bus->response_reset) {
codec_dbg(codec,
"resetting BUS due to fatal communication error\n");
snd_hda_bus_reset(bus);
}
goto again;
}
if (!err || codec_in_pm(codec))
bus->response_reset = 0;
return err;
}
void snd_hda_sequence_write(struct hda_codec *codec, const struct hda_verb *seq)
{
for (; seq->nid; seq++)
snd_hda_codec_write(codec, seq->nid, 0, seq->verb, seq->param);
}
static struct hda_conn_list *
lookup_conn_list(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_conn_list *p;
list_for_each_entry(p, &codec->conn_list, list) {
if (p->nid == nid)
return p;
}
return NULL;
}
static int add_conn_list(struct hda_codec *codec, hda_nid_t nid, int len,
const hda_nid_t *list)
{
struct hda_conn_list *p;
p = kmalloc(sizeof(*p) + len * sizeof(hda_nid_t), GFP_KERNEL);
if (!p)
return -ENOMEM;
p->len = len;
p->nid = nid;
memcpy(p->conns, list, len * sizeof(hda_nid_t));
list_add(&p->list, &codec->conn_list);
return 0;
}
static void remove_conn_list(struct hda_codec *codec)
{
while (!list_empty(&codec->conn_list)) {
struct hda_conn_list *p;
p = list_first_entry(&codec->conn_list, typeof(*p), list);
list_del(&p->list);
kfree(p);
}
}
static int read_and_add_raw_conns(struct hda_codec *codec, hda_nid_t nid)
{
hda_nid_t list[32];
hda_nid_t *result = list;
int len;
len = snd_hda_get_raw_connections(codec, nid, list, ARRAY_SIZE(list));
if (len == -ENOSPC) {
len = snd_hda_get_num_raw_conns(codec, nid);
result = kmalloc(sizeof(hda_nid_t) * len, GFP_KERNEL);
if (!result)
return -ENOMEM;
len = snd_hda_get_raw_connections(codec, nid, result, len);
}
if (len >= 0)
len = snd_hda_override_conn_list(codec, nid, len, result);
if (result != list)
kfree(result);
return len;
}
int snd_hda_get_conn_list(struct hda_codec *codec, hda_nid_t nid,
const hda_nid_t **listp)
{
bool added = false;
for (;;) {
int err;
const struct hda_conn_list *p;
p = lookup_conn_list(codec, nid);
if (p) {
if (listp)
*listp = p->conns;
return p->len;
}
if (snd_BUG_ON(added))
return -EINVAL;
err = read_and_add_raw_conns(codec, nid);
if (err < 0)
return err;
added = true;
}
}
int snd_hda_get_connections(struct hda_codec *codec, hda_nid_t nid,
hda_nid_t *conn_list, int max_conns)
{
const hda_nid_t *list;
int len = snd_hda_get_conn_list(codec, nid, &list);
if (len > 0 && conn_list) {
if (len > max_conns) {
codec_err(codec, "Too many connections %d for NID 0x%x\n",
len, nid);
return -EINVAL;
}
memcpy(conn_list, list, len * sizeof(hda_nid_t));
}
return len;
}
int snd_hda_override_conn_list(struct hda_codec *codec, hda_nid_t nid, int len,
const hda_nid_t *list)
{
struct hda_conn_list *p;
p = lookup_conn_list(codec, nid);
if (p) {
list_del(&p->list);
kfree(p);
}
return add_conn_list(codec, nid, len, list);
}
int snd_hda_get_conn_index(struct hda_codec *codec, hda_nid_t mux,
hda_nid_t nid, int recursive)
{
const hda_nid_t *conn;
int i, nums;
nums = snd_hda_get_conn_list(codec, mux, &conn);
for (i = 0; i < nums; i++)
if (conn[i] == nid)
return i;
if (!recursive)
return -1;
if (recursive > 10) {
codec_dbg(codec, "too deep connection for 0x%x\n", nid);
return -1;
}
recursive++;
for (i = 0; i < nums; i++) {
unsigned int type = get_wcaps_type(get_wcaps(codec, conn[i]));
if (type == AC_WID_PIN || type == AC_WID_AUD_OUT)
continue;
if (snd_hda_get_conn_index(codec, conn[i], nid, recursive) >= 0)
return i;
}
return -1;
}
unsigned int snd_hda_get_num_devices(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int parm;
if (!codec->dp_mst || !(wcaps & AC_WCAP_DIGITAL) ||
get_wcaps_type(wcaps) != AC_WID_PIN)
return 0;
parm = snd_hdac_read_parm_uncached(&codec->core, nid, AC_PAR_DEVLIST_LEN);
if (parm == -1)
parm = 0;
return parm & AC_DEV_LIST_LEN_MASK;
}
int snd_hda_get_devices(struct hda_codec *codec, hda_nid_t nid,
u8 *dev_list, int max_devices)
{
unsigned int parm;
int i, dev_len, devices;
parm = snd_hda_get_num_devices(codec, nid);
if (!parm)
return 0;
dev_len = parm + 1;
dev_len = dev_len < max_devices ? dev_len : max_devices;
devices = 0;
while (devices < dev_len) {
if (snd_hdac_read(&codec->core, nid,
AC_VERB_GET_DEVICE_LIST, devices, &parm))
break;
for (i = 0; i < 8; i++) {
dev_list[devices] = (u8)parm;
parm >>= 4;
devices++;
if (devices >= dev_len)
break;
}
}
return devices;
}
int snd_hda_get_dev_select(struct hda_codec *codec, hda_nid_t nid)
{
if (!codec->dp_mst)
return 0;
return snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_DEVICE_SEL, 0);
}
int snd_hda_set_dev_select(struct hda_codec *codec, hda_nid_t nid, int dev_id)
{
int ret, num_devices;
if (!codec->dp_mst)
return 0;
num_devices = snd_hda_get_num_devices(codec, nid) + 1;
if (num_devices == 1)
return 0;
if (num_devices <= dev_id)
return -EINVAL;
ret = snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_DEVICE_SEL, dev_id);
return ret;
}
static int read_widget_caps(struct hda_codec *codec, hda_nid_t fg_node)
{
int i;
hda_nid_t nid;
codec->wcaps = kmalloc(codec->core.num_nodes * 4, GFP_KERNEL);
if (!codec->wcaps)
return -ENOMEM;
nid = codec->core.start_nid;
for (i = 0; i < codec->core.num_nodes; i++, nid++)
codec->wcaps[i] = snd_hdac_read_parm_uncached(&codec->core,
nid, AC_PAR_AUDIO_WIDGET_CAP);
return 0;
}
static int read_pin_defaults(struct hda_codec *codec)
{
hda_nid_t nid;
for_each_hda_codec_node(nid, codec) {
struct hda_pincfg *pin;
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int wid_type = get_wcaps_type(wcaps);
if (wid_type != AC_WID_PIN)
continue;
pin = snd_array_new(&codec->init_pins);
if (!pin)
return -ENOMEM;
pin->nid = nid;
pin->cfg = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_CONFIG_DEFAULT, 0);
pin->ctrl = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL,
0);
}
return 0;
}
static struct hda_pincfg *look_up_pincfg(struct hda_codec *codec,
struct snd_array *array,
hda_nid_t nid)
{
int i;
for (i = 0; i < array->used; i++) {
struct hda_pincfg *pin = snd_array_elem(array, i);
if (pin->nid == nid)
return pin;
}
return NULL;
}
int snd_hda_add_pincfg(struct hda_codec *codec, struct snd_array *list,
hda_nid_t nid, unsigned int cfg)
{
struct hda_pincfg *pin;
pin = look_up_pincfg(codec, list, nid);
if (!pin) {
pin = snd_array_new(list);
if (!pin)
return -ENOMEM;
pin->nid = nid;
}
pin->cfg = cfg;
return 0;
}
int snd_hda_codec_set_pincfg(struct hda_codec *codec,
hda_nid_t nid, unsigned int cfg)
{
return snd_hda_add_pincfg(codec, &codec->driver_pins, nid, cfg);
}
unsigned int snd_hda_codec_get_pincfg(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_pincfg *pin;
#ifdef CONFIG_SND_HDA_RECONFIG
{
unsigned int cfg = 0;
mutex_lock(&codec->user_mutex);
pin = look_up_pincfg(codec, &codec->user_pins, nid);
if (pin)
cfg = pin->cfg;
mutex_unlock(&codec->user_mutex);
if (cfg)
return cfg;
}
#endif
pin = look_up_pincfg(codec, &codec->driver_pins, nid);
if (pin)
return pin->cfg;
pin = look_up_pincfg(codec, &codec->init_pins, nid);
if (pin)
return pin->cfg;
return 0;
}
int snd_hda_codec_set_pin_target(struct hda_codec *codec, hda_nid_t nid,
unsigned int val)
{
struct hda_pincfg *pin;
pin = look_up_pincfg(codec, &codec->init_pins, nid);
if (!pin)
return -EINVAL;
pin->target = val;
return 0;
}
int snd_hda_codec_get_pin_target(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_pincfg *pin;
pin = look_up_pincfg(codec, &codec->init_pins, nid);
if (!pin)
return 0;
return pin->target;
}
void snd_hda_shutup_pins(struct hda_codec *codec)
{
int i;
if (codec->bus->shutdown)
return;
for (i = 0; i < codec->init_pins.used; i++) {
struct hda_pincfg *pin = snd_array_elem(&codec->init_pins, i);
snd_hda_codec_read(codec, pin->nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
}
codec->pins_shutup = 1;
}
static void restore_shutup_pins(struct hda_codec *codec)
{
int i;
if (!codec->pins_shutup)
return;
if (codec->bus->shutdown)
return;
for (i = 0; i < codec->init_pins.used; i++) {
struct hda_pincfg *pin = snd_array_elem(&codec->init_pins, i);
snd_hda_codec_write(codec, pin->nid, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL,
pin->ctrl);
}
codec->pins_shutup = 0;
}
static void hda_jackpoll_work(struct work_struct *work)
{
struct hda_codec *codec =
container_of(work, struct hda_codec, jackpoll_work.work);
snd_hda_jack_set_dirty_all(codec);
snd_hda_jack_poll_all(codec);
if (!codec->jackpoll_interval)
return;
schedule_delayed_work(&codec->jackpoll_work,
codec->jackpoll_interval);
}
static void free_init_pincfgs(struct hda_codec *codec)
{
snd_array_free(&codec->driver_pins);
#ifdef CONFIG_SND_HDA_RECONFIG
snd_array_free(&codec->user_pins);
#endif
snd_array_free(&codec->init_pins);
}
static struct hda_cvt_setup *
get_hda_cvt_setup(struct hda_codec *codec, hda_nid_t nid)
{
struct hda_cvt_setup *p;
int i;
for (i = 0; i < codec->cvt_setups.used; i++) {
p = snd_array_elem(&codec->cvt_setups, i);
if (p->nid == nid)
return p;
}
p = snd_array_new(&codec->cvt_setups);
if (p)
p->nid = nid;
return p;
}
static void release_pcm(struct kref *kref)
{
struct hda_pcm *pcm = container_of(kref, struct hda_pcm, kref);
if (pcm->pcm)
snd_device_free(pcm->codec->card, pcm->pcm);
clear_bit(pcm->device, pcm->codec->bus->pcm_dev_bits);
kfree(pcm->name);
kfree(pcm);
}
void snd_hda_codec_pcm_put(struct hda_pcm *pcm)
{
kref_put(&pcm->kref, release_pcm);
}
struct hda_pcm *snd_hda_codec_pcm_new(struct hda_codec *codec,
const char *fmt, ...)
{
struct hda_pcm *pcm;
va_list args;
pcm = kzalloc(sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return NULL;
pcm->codec = codec;
kref_init(&pcm->kref);
va_start(args, fmt);
pcm->name = kvasprintf(GFP_KERNEL, fmt, args);
va_end(args);
if (!pcm->name) {
kfree(pcm);
return NULL;
}
list_add_tail(&pcm->list, &codec->pcm_list_head);
return pcm;
}
static void codec_release_pcms(struct hda_codec *codec)
{
struct hda_pcm *pcm, *n;
list_for_each_entry_safe(pcm, n, &codec->pcm_list_head, list) {
list_del_init(&pcm->list);
if (pcm->pcm)
snd_device_disconnect(codec->card, pcm->pcm);
snd_hda_codec_pcm_put(pcm);
}
}
void snd_hda_codec_cleanup_for_unbind(struct hda_codec *codec)
{
if (codec->registered) {
pm_runtime_get_noresume(hda_codec_dev(codec));
pm_runtime_disable(hda_codec_dev(codec));
codec->registered = 0;
}
cancel_delayed_work_sync(&codec->jackpoll_work);
if (!codec->in_freeing)
snd_hda_ctls_clear(codec);
codec_release_pcms(codec);
snd_hda_detach_beep_device(codec);
memset(&codec->patch_ops, 0, sizeof(codec->patch_ops));
snd_hda_jack_tbl_clear(codec);
codec->proc_widget_hook = NULL;
codec->spec = NULL;
snd_array_free(&codec->driver_pins);
snd_array_free(&codec->cvt_setups);
snd_array_free(&codec->spdif_out);
snd_array_free(&codec->verbs);
codec->preset = NULL;
codec->slave_dig_outs = NULL;
codec->spdif_status_reset = 0;
snd_array_free(&codec->mixers);
snd_array_free(&codec->nids);
remove_conn_list(codec);
snd_hdac_regmap_exit(&codec->core);
}
void snd_hda_codec_register(struct hda_codec *codec)
{
if (codec->registered)
return;
if (device_is_registered(hda_codec_dev(codec))) {
snd_hda_register_beep_device(codec);
snd_hdac_link_power(&codec->core, true);
pm_runtime_enable(hda_codec_dev(codec));
snd_hda_power_down(codec);
codec->registered = 1;
}
}
static int snd_hda_codec_dev_register(struct snd_device *device)
{
snd_hda_codec_register(device->device_data);
return 0;
}
static int snd_hda_codec_dev_disconnect(struct snd_device *device)
{
struct hda_codec *codec = device->device_data;
snd_hda_detach_beep_device(codec);
return 0;
}
static int snd_hda_codec_dev_free(struct snd_device *device)
{
struct hda_codec *codec = device->device_data;
codec->in_freeing = 1;
snd_hdac_device_unregister(&codec->core);
snd_hdac_link_power(&codec->core, false);
put_device(hda_codec_dev(codec));
return 0;
}
static void snd_hda_codec_dev_release(struct device *dev)
{
struct hda_codec *codec = dev_to_hda_codec(dev);
free_init_pincfgs(codec);
snd_hdac_device_exit(&codec->core);
snd_hda_sysfs_clear(codec);
kfree(codec->modelname);
kfree(codec->wcaps);
kfree(codec);
}
int snd_hda_codec_new(struct hda_bus *bus, struct snd_card *card,
unsigned int codec_addr, struct hda_codec **codecp)
{
struct hda_codec *codec;
char component[31];
hda_nid_t fg;
int err;
static struct snd_device_ops dev_ops = {
.dev_register = snd_hda_codec_dev_register,
.dev_disconnect = snd_hda_codec_dev_disconnect,
.dev_free = snd_hda_codec_dev_free,
};
if (snd_BUG_ON(!bus))
return -EINVAL;
if (snd_BUG_ON(codec_addr > HDA_MAX_CODEC_ADDRESS))
return -EINVAL;
codec = kzalloc(sizeof(*codec), GFP_KERNEL);
if (!codec)
return -ENOMEM;
sprintf(component, "hdaudioC%dD%d", card->number, codec_addr);
err = snd_hdac_device_init(&codec->core, &bus->core, component,
codec_addr);
if (err < 0) {
kfree(codec);
return err;
}
codec->core.dev.release = snd_hda_codec_dev_release;
codec->core.type = HDA_DEV_LEGACY;
codec->core.exec_verb = codec_exec_verb;
codec->bus = bus;
codec->card = card;
codec->addr = codec_addr;
mutex_init(&codec->spdif_mutex);
mutex_init(&codec->control_mutex);
snd_array_init(&codec->mixers, sizeof(struct hda_nid_item), 32);
snd_array_init(&codec->nids, sizeof(struct hda_nid_item), 32);
snd_array_init(&codec->init_pins, sizeof(struct hda_pincfg), 16);
snd_array_init(&codec->driver_pins, sizeof(struct hda_pincfg), 16);
snd_array_init(&codec->cvt_setups, sizeof(struct hda_cvt_setup), 8);
snd_array_init(&codec->spdif_out, sizeof(struct hda_spdif_out), 16);
snd_array_init(&codec->jacktbl, sizeof(struct hda_jack_tbl), 16);
snd_array_init(&codec->verbs, sizeof(struct hda_verb *), 8);
INIT_LIST_HEAD(&codec->conn_list);
INIT_LIST_HEAD(&codec->pcm_list_head);
INIT_DELAYED_WORK(&codec->jackpoll_work, hda_jackpoll_work);
codec->depop_delay = -1;
codec->fixup_id = HDA_FIXUP_ID_NOT_SET;
#ifdef CONFIG_PM
codec->power_jiffies = jiffies;
#endif
snd_hda_sysfs_init(codec);
if (codec->bus->modelname) {
codec->modelname = kstrdup(codec->bus->modelname, GFP_KERNEL);
if (!codec->modelname) {
err = -ENOMEM;
goto error;
}
}
fg = codec->core.afg ? codec->core.afg : codec->core.mfg;
err = read_widget_caps(codec, fg);
if (err < 0)
goto error;
err = read_pin_defaults(codec);
if (err < 0)
goto error;
hda_set_power_state(codec, AC_PWRST_D0);
snd_hda_codec_proc_new(codec);
snd_hda_create_hwdep(codec);
sprintf(component, "HDA:%08x,%08x,%08x", codec->core.vendor_id,
codec->core.subsystem_id, codec->core.revision_id);
snd_component_add(card, component);
err = snd_device_new(card, SNDRV_DEV_CODEC, codec, &dev_ops);
if (err < 0)
goto error;
if (codecp)
*codecp = codec;
return 0;
error:
put_device(hda_codec_dev(codec));
return err;
}
int snd_hda_codec_update_widgets(struct hda_codec *codec)
{
hda_nid_t fg;
int err;
err = snd_hdac_refresh_widget_sysfs(&codec->core);
if (err < 0)
return err;
kfree(codec->wcaps);
fg = codec->core.afg ? codec->core.afg : codec->core.mfg;
err = read_widget_caps(codec, fg);
if (err < 0)
return err;
snd_array_free(&codec->init_pins);
err = read_pin_defaults(codec);
return err;
}
static void update_pcm_stream_id(struct hda_codec *codec,
struct hda_cvt_setup *p, hda_nid_t nid,
u32 stream_tag, int channel_id)
{
unsigned int oldval, newval;
if (p->stream_tag != stream_tag || p->channel_id != channel_id) {
oldval = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_CONV, 0);
newval = (stream_tag << 4) | channel_id;
if (oldval != newval)
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_CHANNEL_STREAMID,
newval);
p->stream_tag = stream_tag;
p->channel_id = channel_id;
}
}
static void update_pcm_format(struct hda_codec *codec, struct hda_cvt_setup *p,
hda_nid_t nid, int format)
{
unsigned int oldval;
if (p->format_id != format) {
oldval = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_STREAM_FORMAT, 0);
if (oldval != format) {
msleep(1);
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_STREAM_FORMAT,
format);
}
p->format_id = format;
}
}
void snd_hda_codec_setup_stream(struct hda_codec *codec, hda_nid_t nid,
u32 stream_tag,
int channel_id, int format)
{
struct hda_codec *c;
struct hda_cvt_setup *p;
int type;
int i;
if (!nid)
return;
codec_dbg(codec,
"hda_codec_setup_stream: NID=0x%x, stream=0x%x, channel=%d, format=0x%x\n",
nid, stream_tag, channel_id, format);
p = get_hda_cvt_setup(codec, nid);
if (!p)
return;
if (codec->patch_ops.stream_pm)
codec->patch_ops.stream_pm(codec, nid, true);
if (codec->pcm_format_first)
update_pcm_format(codec, p, nid, format);
update_pcm_stream_id(codec, p, nid, stream_tag, channel_id);
if (!codec->pcm_format_first)
update_pcm_format(codec, p, nid, format);
p->active = 1;
p->dirty = 0;
type = get_wcaps_type(get_wcaps(codec, nid));
list_for_each_codec(c, codec->bus) {
for (i = 0; i < c->cvt_setups.used; i++) {
p = snd_array_elem(&c->cvt_setups, i);
if (!p->active && p->stream_tag == stream_tag &&
get_wcaps_type(get_wcaps(c, p->nid)) == type)
p->dirty = 1;
}
}
}
void __snd_hda_codec_cleanup_stream(struct hda_codec *codec, hda_nid_t nid,
int do_now)
{
struct hda_cvt_setup *p;
if (!nid)
return;
if (codec->no_sticky_stream)
do_now = 1;
codec_dbg(codec, "hda_codec_cleanup_stream: NID=0x%x\n", nid);
p = get_hda_cvt_setup(codec, nid);
if (p) {
if (do_now)
really_cleanup_stream(codec, p);
else
p->active = 0;
}
}
static void really_cleanup_stream(struct hda_codec *codec,
struct hda_cvt_setup *q)
{
hda_nid_t nid = q->nid;
if (q->stream_tag || q->channel_id)
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0);
if (q->format_id)
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_STREAM_FORMAT, 0
);
memset(q, 0, sizeof(*q));
q->nid = nid;
if (codec->patch_ops.stream_pm)
codec->patch_ops.stream_pm(codec, nid, false);
}
static void purify_inactive_streams(struct hda_codec *codec)
{
struct hda_codec *c;
int i;
list_for_each_codec(c, codec->bus) {
for (i = 0; i < c->cvt_setups.used; i++) {
struct hda_cvt_setup *p;
p = snd_array_elem(&c->cvt_setups, i);
if (p->dirty)
really_cleanup_stream(c, p);
}
}
}
static void hda_cleanup_all_streams(struct hda_codec *codec)
{
int i;
for (i = 0; i < codec->cvt_setups.used; i++) {
struct hda_cvt_setup *p = snd_array_elem(&codec->cvt_setups, i);
if (p->stream_tag)
really_cleanup_stream(codec, p);
}
}
u32 query_amp_caps(struct hda_codec *codec, hda_nid_t nid, int direction)
{
if (!(get_wcaps(codec, nid) & AC_WCAP_AMP_OVRD))
nid = codec->core.afg;
return snd_hda_param_read(codec, nid,
direction == HDA_OUTPUT ?
AC_PAR_AMP_OUT_CAP : AC_PAR_AMP_IN_CAP);
}
bool snd_hda_check_amp_caps(struct hda_codec *codec, hda_nid_t nid,
int dir, unsigned int bits)
{
if (!nid)
return false;
if (get_wcaps(codec, nid) & (1 << (dir + 1)))
if (query_amp_caps(codec, nid, dir) & bits)
return true;
return false;
}
int snd_hda_override_amp_caps(struct hda_codec *codec, hda_nid_t nid, int dir,
unsigned int caps)
{
unsigned int parm;
snd_hda_override_wcaps(codec, nid,
get_wcaps(codec, nid) | AC_WCAP_AMP_OVRD);
parm = dir == HDA_OUTPUT ? AC_PAR_AMP_OUT_CAP : AC_PAR_AMP_IN_CAP;
return snd_hdac_override_parm(&codec->core, nid, parm, caps);
}
int snd_hda_codec_amp_update(struct hda_codec *codec, hda_nid_t nid,
int ch, int dir, int idx, int mask, int val)
{
unsigned int cmd = snd_hdac_regmap_encode_amp(nid, ch, dir, idx);
if ((query_amp_caps(codec, nid, dir) &
(AC_AMPCAP_MUTE | AC_AMPCAP_MIN_MUTE)) == AC_AMPCAP_MIN_MUTE)
cmd |= AC_AMP_FAKE_MUTE;
return snd_hdac_regmap_update_raw(&codec->core, cmd, mask, val);
}
int snd_hda_codec_amp_stereo(struct hda_codec *codec, hda_nid_t nid,
int direction, int idx, int mask, int val)
{
int ch, ret = 0;
if (snd_BUG_ON(mask & ~0xff))
mask &= 0xff;
for (ch = 0; ch < 2; ch++)
ret |= snd_hda_codec_amp_update(codec, nid, ch, direction,
idx, mask, val);
return ret;
}
int snd_hda_codec_amp_init(struct hda_codec *codec, hda_nid_t nid, int ch,
int dir, int idx, int mask, int val)
{
int orig;
if (!codec->core.regmap)
return -EINVAL;
regcache_cache_only(codec->core.regmap, true);
orig = snd_hda_codec_amp_read(codec, nid, ch, dir, idx);
regcache_cache_only(codec->core.regmap, false);
if (orig >= 0)
return 0;
return snd_hda_codec_amp_update(codec, nid, ch, dir, idx, mask, val);
}
int snd_hda_codec_amp_init_stereo(struct hda_codec *codec, hda_nid_t nid,
int dir, int idx, int mask, int val)
{
int ch, ret = 0;
if (snd_BUG_ON(mask & ~0xff))
mask &= 0xff;
for (ch = 0; ch < 2; ch++)
ret |= snd_hda_codec_amp_init(codec, nid, ch, dir,
idx, mask, val);
return ret;
}
static u32 get_amp_max_value(struct hda_codec *codec, hda_nid_t nid, int dir,
unsigned int ofs)
{
u32 caps = query_amp_caps(codec, nid, dir);
caps = (caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT;
if (ofs < caps)
caps -= ofs;
return caps;
}
int snd_hda_mixer_amp_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
u16 nid = get_amp_nid(kcontrol);
u8 chs = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
unsigned int ofs = get_amp_offset(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = chs == 3 ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = get_amp_max_value(codec, nid, dir, ofs);
if (!uinfo->value.integer.max) {
codec_warn(codec,
"num_steps = 0 for NID=0x%x (ctl = %s)\n",
nid, kcontrol->id.name);
return -EINVAL;
}
return 0;
}
static inline unsigned int
read_amp_value(struct hda_codec *codec, hda_nid_t nid,
int ch, int dir, int idx, unsigned int ofs)
{
unsigned int val;
val = snd_hda_codec_amp_read(codec, nid, ch, dir, idx);
val &= HDA_AMP_VOLMASK;
if (val >= ofs)
val -= ofs;
else
val = 0;
return val;
}
static inline int
update_amp_value(struct hda_codec *codec, hda_nid_t nid,
int ch, int dir, int idx, unsigned int ofs,
unsigned int val)
{
unsigned int maxval;
if (val > 0)
val += ofs;
maxval = get_amp_max_value(codec, nid, dir, 0);
if (val > maxval)
val = maxval;
return snd_hda_codec_amp_update(codec, nid, ch, dir, idx,
HDA_AMP_VOLMASK, val);
}
int snd_hda_mixer_amp_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = get_amp_nid(kcontrol);
int chs = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
int idx = get_amp_index(kcontrol);
unsigned int ofs = get_amp_offset(kcontrol);
long *valp = ucontrol->value.integer.value;
if (chs & 1)
*valp++ = read_amp_value(codec, nid, 0, dir, idx, ofs);
if (chs & 2)
*valp = read_amp_value(codec, nid, 1, dir, idx, ofs);
return 0;
}
int snd_hda_mixer_amp_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = get_amp_nid(kcontrol);
int chs = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
int idx = get_amp_index(kcontrol);
unsigned int ofs = get_amp_offset(kcontrol);
long *valp = ucontrol->value.integer.value;
int change = 0;
if (chs & 1) {
change = update_amp_value(codec, nid, 0, dir, idx, ofs, *valp);
valp++;
}
if (chs & 2)
change |= update_amp_value(codec, nid, 1, dir, idx, ofs, *valp);
return change;
}
int snd_hda_mixer_amp_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *_tlv)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = get_amp_nid(kcontrol);
int dir = get_amp_direction(kcontrol);
unsigned int ofs = get_amp_offset(kcontrol);
bool min_mute = get_amp_min_mute(kcontrol);
u32 caps, val1, val2;
if (size < 4 * sizeof(unsigned int))
return -ENOMEM;
caps = query_amp_caps(codec, nid, dir);
val2 = (caps & AC_AMPCAP_STEP_SIZE) >> AC_AMPCAP_STEP_SIZE_SHIFT;
val2 = (val2 + 1) * 25;
val1 = -((caps & AC_AMPCAP_OFFSET) >> AC_AMPCAP_OFFSET_SHIFT);
val1 += ofs;
val1 = ((int)val1) * ((int)val2);
if (min_mute || (caps & AC_AMPCAP_MIN_MUTE))
val2 |= TLV_DB_SCALE_MUTE;
if (put_user(SNDRV_CTL_TLVT_DB_SCALE, _tlv))
return -EFAULT;
if (put_user(2 * sizeof(unsigned int), _tlv + 1))
return -EFAULT;
if (put_user(val1, _tlv + 2))
return -EFAULT;
if (put_user(val2, _tlv + 3))
return -EFAULT;
return 0;
}
void snd_hda_set_vmaster_tlv(struct hda_codec *codec, hda_nid_t nid, int dir,
unsigned int *tlv)
{
u32 caps;
int nums, step;
caps = query_amp_caps(codec, nid, dir);
nums = (caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT;
step = (caps & AC_AMPCAP_STEP_SIZE) >> AC_AMPCAP_STEP_SIZE_SHIFT;
step = (step + 1) * 25;
tlv[0] = SNDRV_CTL_TLVT_DB_SCALE;
tlv[1] = 2 * sizeof(unsigned int);
tlv[2] = -nums * step;
tlv[3] = step;
}
static struct snd_kcontrol *
find_mixer_ctl(struct hda_codec *codec, const char *name, int dev, int idx)
{
struct snd_ctl_elem_id id;
memset(&id, 0, sizeof(id));
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
id.device = dev;
id.index = idx;
if (snd_BUG_ON(strlen(name) >= sizeof(id.name)))
return NULL;
strcpy(id.name, name);
return snd_ctl_find_id(codec->card, &id);
}
struct snd_kcontrol *snd_hda_find_mixer_ctl(struct hda_codec *codec,
const char *name)
{
return find_mixer_ctl(codec, name, 0, 0);
}
static int find_empty_mixer_ctl_idx(struct hda_codec *codec, const char *name,
int start_idx)
{
int i, idx;
for (i = 0, idx = start_idx; i < 16; i++, idx++) {
if (!find_mixer_ctl(codec, name, 0, idx))
return idx;
}
return -EBUSY;
}
int snd_hda_ctl_add(struct hda_codec *codec, hda_nid_t nid,
struct snd_kcontrol *kctl)
{
int err;
unsigned short flags = 0;
struct hda_nid_item *item;
if (kctl->id.subdevice & HDA_SUBDEV_AMP_FLAG) {
flags |= HDA_NID_ITEM_AMP;
if (nid == 0)
nid = get_amp_nid_(kctl->private_value);
}
if ((kctl->id.subdevice & HDA_SUBDEV_NID_FLAG) != 0 && nid == 0)
nid = kctl->id.subdevice & 0xffff;
if (kctl->id.subdevice & (HDA_SUBDEV_NID_FLAG|HDA_SUBDEV_AMP_FLAG))
kctl->id.subdevice = 0;
err = snd_ctl_add(codec->card, kctl);
if (err < 0)
return err;
item = snd_array_new(&codec->mixers);
if (!item)
return -ENOMEM;
item->kctl = kctl;
item->nid = nid;
item->flags = flags;
return 0;
}
int snd_hda_add_nid(struct hda_codec *codec, struct snd_kcontrol *kctl,
unsigned int index, hda_nid_t nid)
{
struct hda_nid_item *item;
if (nid > 0) {
item = snd_array_new(&codec->nids);
if (!item)
return -ENOMEM;
item->kctl = kctl;
item->index = index;
item->nid = nid;
return 0;
}
codec_err(codec, "no NID for mapping control %s:%d:%d\n",
kctl->id.name, kctl->id.index, index);
return -EINVAL;
}
void snd_hda_ctls_clear(struct hda_codec *codec)
{
int i;
struct hda_nid_item *items = codec->mixers.list;
for (i = 0; i < codec->mixers.used; i++)
snd_ctl_remove(codec->card, items[i].kctl);
snd_array_free(&codec->mixers);
snd_array_free(&codec->nids);
}
int snd_hda_lock_devices(struct hda_bus *bus)
{
struct snd_card *card = bus->card;
struct hda_codec *codec;
spin_lock(&card->files_lock);
if (card->shutdown)
goto err_unlock;
card->shutdown = 1;
if (!list_empty(&card->ctl_files))
goto err_clear;
list_for_each_codec(codec, bus) {
struct hda_pcm *cpcm;
list_for_each_entry(cpcm, &codec->pcm_list_head, list) {
if (!cpcm->pcm)
continue;
if (cpcm->pcm->streams[0].substream_opened ||
cpcm->pcm->streams[1].substream_opened)
goto err_clear;
}
}
spin_unlock(&card->files_lock);
return 0;
err_clear:
card->shutdown = 0;
err_unlock:
spin_unlock(&card->files_lock);
return -EINVAL;
}
void snd_hda_unlock_devices(struct hda_bus *bus)
{
struct snd_card *card = bus->card;
spin_lock(&card->files_lock);
card->shutdown = 0;
spin_unlock(&card->files_lock);
}
int snd_hda_codec_reset(struct hda_codec *codec)
{
struct hda_bus *bus = codec->bus;
if (snd_hda_lock_devices(bus) < 0)
return -EBUSY;
snd_hdac_device_unregister(&codec->core);
snd_hda_unlock_devices(bus);
return 0;
}
static int map_slaves(struct hda_codec *codec, const char * const *slaves,
const char *suffix, map_slave_func_t func, void *data)
{
struct hda_nid_item *items;
const char * const *s;
int i, err;
items = codec->mixers.list;
for (i = 0; i < codec->mixers.used; i++) {
struct snd_kcontrol *sctl = items[i].kctl;
if (!sctl || sctl->id.iface != SNDRV_CTL_ELEM_IFACE_MIXER)
continue;
for (s = slaves; *s; s++) {
char tmpname[sizeof(sctl->id.name)];
const char *name = *s;
if (suffix) {
snprintf(tmpname, sizeof(tmpname), "%s %s",
name, suffix);
name = tmpname;
}
if (!strcmp(sctl->id.name, name)) {
err = func(codec, data, sctl);
if (err)
return err;
break;
}
}
}
return 0;
}
static int check_slave_present(struct hda_codec *codec,
void *data, struct snd_kcontrol *sctl)
{
return 1;
}
static int get_kctl_0dB_offset(struct hda_codec *codec,
struct snd_kcontrol *kctl, int *step_to_check)
{
int _tlv[4];
const int *tlv = NULL;
int val = -1;
if (kctl->vd[0].access & SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK) {
mm_segment_t fs = get_fs();
set_fs(get_ds());
if (!kctl->tlv.c(kctl, 0, sizeof(_tlv), _tlv))
tlv = _tlv;
set_fs(fs);
} else if (kctl->vd[0].access & SNDRV_CTL_ELEM_ACCESS_TLV_READ)
tlv = kctl->tlv.p;
if (tlv && tlv[0] == SNDRV_CTL_TLVT_DB_SCALE) {
int step = tlv[3];
step &= ~TLV_DB_SCALE_MUTE;
if (!step)
return -1;
if (*step_to_check && *step_to_check != step) {
codec_err(codec, "Mismatching dB step for vmaster slave (%d!=%d)\n",
- *step_to_check, step);
return -1;
}
*step_to_check = step;
val = -tlv[2] / step;
}
return val;
}
static int put_kctl_with_value(struct snd_kcontrol *kctl, int val)
{
struct snd_ctl_elem_value *ucontrol;
ucontrol = kzalloc(sizeof(*ucontrol), GFP_KERNEL);
if (!ucontrol)
return -ENOMEM;
ucontrol->value.integer.value[0] = val;
ucontrol->value.integer.value[1] = val;
kctl->put(kctl, ucontrol);
kfree(ucontrol);
return 0;
}
static int init_slave_0dB(struct hda_codec *codec,
void *data, struct snd_kcontrol *slave)
{
int offset = get_kctl_0dB_offset(codec, slave, data);
if (offset > 0)
put_kctl_with_value(slave, offset);
return 0;
}
static int init_slave_unmute(struct hda_codec *codec,
void *data, struct snd_kcontrol *slave)
{
return put_kctl_with_value(slave, 1);
}
static int add_slave(struct hda_codec *codec,
void *data, struct snd_kcontrol *slave)
{
return snd_ctl_add_slave(data, slave);
}
int __snd_hda_add_vmaster(struct hda_codec *codec, char *name,
unsigned int *tlv, const char * const *slaves,
const char *suffix, bool init_slave_vol,
struct snd_kcontrol **ctl_ret)
{
struct snd_kcontrol *kctl;
int err;
if (ctl_ret)
*ctl_ret = NULL;
err = map_slaves(codec, slaves, suffix, check_slave_present, NULL);
if (err != 1) {
codec_dbg(codec, "No slave found for %s\n", name);
return 0;
}
kctl = snd_ctl_make_virtual_master(name, tlv);
if (!kctl)
return -ENOMEM;
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
err = map_slaves(codec, slaves, suffix, add_slave, kctl);
if (err < 0)
return err;
put_kctl_with_value(kctl, 0);
if (init_slave_vol) {
int step = 0;
map_slaves(codec, slaves, suffix,
tlv ? init_slave_0dB : init_slave_unmute, &step);
}
if (ctl_ret)
*ctl_ret = kctl;
return 0;
}
static int vmaster_mute_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"On", "Off", "Follow Master"
};
return snd_ctl_enum_info(uinfo, 1, 3, texts);
}
static int vmaster_mute_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_vmaster_mute_hook *hook = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hook->mute_mode;
return 0;
}
static int vmaster_mute_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_vmaster_mute_hook *hook = snd_kcontrol_chip(kcontrol);
unsigned int old_mode = hook->mute_mode;
hook->mute_mode = ucontrol->value.enumerated.item[0];
if (hook->mute_mode > HDA_VMUTE_FOLLOW_MASTER)
hook->mute_mode = HDA_VMUTE_FOLLOW_MASTER;
if (old_mode == hook->mute_mode)
return 0;
snd_hda_sync_vmaster_hook(hook);
return 1;
}
static void vmaster_hook(void *private_data, int enabled)
{
struct hda_vmaster_mute_hook *hook = private_data;
if (hook->mute_mode != HDA_VMUTE_FOLLOW_MASTER)
enabled = hook->mute_mode;
hook->hook(hook->codec, enabled);
}
int snd_hda_add_vmaster_hook(struct hda_codec *codec,
struct hda_vmaster_mute_hook *hook,
bool expose_enum_ctl)
{
struct snd_kcontrol *kctl;
if (!hook->hook || !hook->sw_kctl)
return 0;
hook->codec = codec;
hook->mute_mode = HDA_VMUTE_FOLLOW_MASTER;
snd_ctl_add_vmaster_hook(hook->sw_kctl, vmaster_hook, hook);
if (!expose_enum_ctl)
return 0;
kctl = snd_ctl_new1(&vmaster_mute_mode, hook);
if (!kctl)
return -ENOMEM;
return snd_hda_ctl_add(codec, 0, kctl);
}
void snd_hda_sync_vmaster_hook(struct hda_vmaster_mute_hook *hook)
{
if (!hook->hook || !hook->codec)
return;
if (hook->codec->bus->shutdown)
return;
snd_ctl_sync_vmaster_hook(hook->sw_kctl);
}
int snd_hda_mixer_amp_switch_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int chs = get_amp_channels(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = chs == 3 ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
int snd_hda_mixer_amp_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = get_amp_nid(kcontrol);
int chs = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
int idx = get_amp_index(kcontrol);
long *valp = ucontrol->value.integer.value;
if (chs & 1)
*valp++ = (snd_hda_codec_amp_read(codec, nid, 0, dir, idx) &
HDA_AMP_MUTE) ? 0 : 1;
if (chs & 2)
*valp = (snd_hda_codec_amp_read(codec, nid, 1, dir, idx) &
HDA_AMP_MUTE) ? 0 : 1;
return 0;
}
int snd_hda_mixer_amp_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = get_amp_nid(kcontrol);
int chs = get_amp_channels(kcontrol);
int dir = get_amp_direction(kcontrol);
int idx = get_amp_index(kcontrol);
long *valp = ucontrol->value.integer.value;
int change = 0;
if (chs & 1) {
change = snd_hda_codec_amp_update(codec, nid, 0, dir, idx,
HDA_AMP_MUTE,
*valp ? 0 : HDA_AMP_MUTE);
valp++;
}
if (chs & 2)
change |= snd_hda_codec_amp_update(codec, nid, 1, dir, idx,
HDA_AMP_MUTE,
*valp ? 0 : HDA_AMP_MUTE);
hda_call_check_power_status(codec, nid);
return change;
}
int snd_hda_mixer_bind_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned long pval;
int err;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
kcontrol->private_value = pval & ~AMP_VAL_IDX_MASK;
err = snd_hda_mixer_amp_switch_get(kcontrol, ucontrol);
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
return err;
}
int snd_hda_mixer_bind_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned long pval;
int i, indices, err = 0, change = 0;
mutex_lock(&codec->control_mutex);
pval = kcontrol->private_value;
indices = (pval & AMP_VAL_IDX_MASK) >> AMP_VAL_IDX_SHIFT;
for (i = 0; i < indices; i++) {
kcontrol->private_value = (pval & ~AMP_VAL_IDX_MASK) |
(i << AMP_VAL_IDX_SHIFT);
err = snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
if (err < 0)
break;
change |= err;
}
kcontrol->private_value = pval;
mutex_unlock(&codec->control_mutex);
return err < 0 ? err : change;
}
int snd_hda_mixer_bind_ctls_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hda_bind_ctls *c;
int err;
mutex_lock(&codec->control_mutex);
c = (struct hda_bind_ctls *)kcontrol->private_value;
kcontrol->private_value = *c->values;
err = c->ops->info(kcontrol, uinfo);
kcontrol->private_value = (long)c;
mutex_unlock(&codec->control_mutex);
return err;
}
int snd_hda_mixer_bind_ctls_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hda_bind_ctls *c;
int err;
mutex_lock(&codec->control_mutex);
c = (struct hda_bind_ctls *)kcontrol->private_value;
kcontrol->private_value = *c->values;
err = c->ops->get(kcontrol, ucontrol);
kcontrol->private_value = (long)c;
mutex_unlock(&codec->control_mutex);
return err;
}
int snd_hda_mixer_bind_ctls_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hda_bind_ctls *c;
unsigned long *vals;
int err = 0, change = 0;
mutex_lock(&codec->control_mutex);
c = (struct hda_bind_ctls *)kcontrol->private_value;
for (vals = c->values; *vals; vals++) {
kcontrol->private_value = *vals;
err = c->ops->put(kcontrol, ucontrol);
if (err < 0)
break;
change |= err;
}
kcontrol->private_value = (long)c;
mutex_unlock(&codec->control_mutex);
return err < 0 ? err : change;
}
int snd_hda_mixer_bind_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hda_bind_ctls *c;
int err;
mutex_lock(&codec->control_mutex);
c = (struct hda_bind_ctls *)kcontrol->private_value;
kcontrol->private_value = *c->values;
err = c->ops->tlv(kcontrol, op_flag, size, tlv);
kcontrol->private_value = (long)c;
mutex_unlock(&codec->control_mutex);
return err;
}
static int snd_hda_spdif_mask_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_hda_spdif_cmask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = IEC958_AES0_PROFESSIONAL |
IEC958_AES0_NONAUDIO |
IEC958_AES0_CON_EMPHASIS_5015 |
IEC958_AES0_CON_NOT_COPYRIGHT;
ucontrol->value.iec958.status[1] = IEC958_AES1_CON_CATEGORY |
IEC958_AES1_CON_ORIGINAL;
return 0;
}
static int snd_hda_spdif_pmask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = IEC958_AES0_PROFESSIONAL |
IEC958_AES0_NONAUDIO |
IEC958_AES0_PRO_EMPHASIS_5015;
return 0;
}
static int snd_hda_spdif_default_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int idx = kcontrol->private_value;
struct hda_spdif_out *spdif;
mutex_lock(&codec->spdif_mutex);
spdif = snd_array_elem(&codec->spdif_out, idx);
ucontrol->value.iec958.status[0] = spdif->status & 0xff;
ucontrol->value.iec958.status[1] = (spdif->status >> 8) & 0xff;
ucontrol->value.iec958.status[2] = (spdif->status >> 16) & 0xff;
ucontrol->value.iec958.status[3] = (spdif->status >> 24) & 0xff;
mutex_unlock(&codec->spdif_mutex);
return 0;
}
static unsigned short convert_from_spdif_status(unsigned int sbits)
{
unsigned short val = 0;
if (sbits & IEC958_AES0_PROFESSIONAL)
val |= AC_DIG1_PROFESSIONAL;
if (sbits & IEC958_AES0_NONAUDIO)
val |= AC_DIG1_NONAUDIO;
if (sbits & IEC958_AES0_PROFESSIONAL) {
if ((sbits & IEC958_AES0_PRO_EMPHASIS) ==
IEC958_AES0_PRO_EMPHASIS_5015)
val |= AC_DIG1_EMPHASIS;
} else {
if ((sbits & IEC958_AES0_CON_EMPHASIS) ==
IEC958_AES0_CON_EMPHASIS_5015)
val |= AC_DIG1_EMPHASIS;
if (!(sbits & IEC958_AES0_CON_NOT_COPYRIGHT))
val |= AC_DIG1_COPYRIGHT;
if (sbits & (IEC958_AES1_CON_ORIGINAL << 8))
val |= AC_DIG1_LEVEL;
val |= sbits & (IEC958_AES1_CON_CATEGORY << 8);
}
return val;
}
static unsigned int convert_to_spdif_status(unsigned short val)
{
unsigned int sbits = 0;
if (val & AC_DIG1_NONAUDIO)
sbits |= IEC958_AES0_NONAUDIO;
if (val & AC_DIG1_PROFESSIONAL)
sbits |= IEC958_AES0_PROFESSIONAL;
if (sbits & IEC958_AES0_PROFESSIONAL) {
if (val & AC_DIG1_EMPHASIS)
sbits |= IEC958_AES0_PRO_EMPHASIS_5015;
} else {
if (val & AC_DIG1_EMPHASIS)
sbits |= IEC958_AES0_CON_EMPHASIS_5015;
if (!(val & AC_DIG1_COPYRIGHT))
sbits |= IEC958_AES0_CON_NOT_COPYRIGHT;
if (val & AC_DIG1_LEVEL)
sbits |= (IEC958_AES1_CON_ORIGINAL << 8);
sbits |= val & (0x7f << 8);
}
return sbits;
}
static void set_dig_out(struct hda_codec *codec, hda_nid_t nid,
int mask, int val)
{
const hda_nid_t *d;
snd_hdac_regmap_update(&codec->core, nid, AC_VERB_SET_DIGI_CONVERT_1,
mask, val);
d = codec->slave_dig_outs;
if (!d)
return;
for (; *d; d++)
snd_hdac_regmap_update(&codec->core, *d,
AC_VERB_SET_DIGI_CONVERT_1, mask, val);
}
static inline void set_dig_out_convert(struct hda_codec *codec, hda_nid_t nid,
int dig1, int dig2)
{
unsigned int mask = 0;
unsigned int val = 0;
if (dig1 != -1) {
mask |= 0xff;
val = dig1;
}
if (dig2 != -1) {
mask |= 0xff00;
val |= dig2 << 8;
}
set_dig_out(codec, nid, mask, val);
}
static int snd_hda_spdif_default_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int idx = kcontrol->private_value;
struct hda_spdif_out *spdif;
hda_nid_t nid;
unsigned short val;
int change;
mutex_lock(&codec->spdif_mutex);
spdif = snd_array_elem(&codec->spdif_out, idx);
nid = spdif->nid;
spdif->status = ucontrol->value.iec958.status[0] |
((unsigned int)ucontrol->value.iec958.status[1] << 8) |
((unsigned int)ucontrol->value.iec958.status[2] << 16) |
((unsigned int)ucontrol->value.iec958.status[3] << 24);
val = convert_from_spdif_status(spdif->status);
val |= spdif->ctls & 1;
change = spdif->ctls != val;
spdif->ctls = val;
if (change && nid != (u16)-1)
set_dig_out_convert(codec, nid, val & 0xff, (val >> 8) & 0xff);
mutex_unlock(&codec->spdif_mutex);
return change;
}
static int snd_hda_spdif_out_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int idx = kcontrol->private_value;
struct hda_spdif_out *spdif;
mutex_lock(&codec->spdif_mutex);
spdif = snd_array_elem(&codec->spdif_out, idx);
ucontrol->value.integer.value[0] = spdif->ctls & AC_DIG1_ENABLE;
mutex_unlock(&codec->spdif_mutex);
return 0;
}
static inline void set_spdif_ctls(struct hda_codec *codec, hda_nid_t nid,
int dig1, int dig2)
{
set_dig_out_convert(codec, nid, dig1, dig2);
if ((get_wcaps(codec, nid) & AC_WCAP_OUT_AMP) &&
(dig1 & AC_DIG1_ENABLE))
snd_hda_codec_amp_stereo(codec, nid, HDA_OUTPUT, 0,
HDA_AMP_MUTE, 0);
}
static int snd_hda_spdif_out_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int idx = kcontrol->private_value;
struct hda_spdif_out *spdif;
hda_nid_t nid;
unsigned short val;
int change;
mutex_lock(&codec->spdif_mutex);
spdif = snd_array_elem(&codec->spdif_out, idx);
nid = spdif->nid;
val = spdif->ctls & ~AC_DIG1_ENABLE;
if (ucontrol->value.integer.value[0])
val |= AC_DIG1_ENABLE;
change = spdif->ctls != val;
spdif->ctls = val;
if (change && nid != (u16)-1)
set_spdif_ctls(codec, nid, val & 0xff, -1);
mutex_unlock(&codec->spdif_mutex);
return change;
}
int snd_hda_create_dig_out_ctls(struct hda_codec *codec,
hda_nid_t associated_nid,
hda_nid_t cvt_nid,
int type)
{
int err;
struct snd_kcontrol *kctl;
struct snd_kcontrol_new *dig_mix;
int idx = 0;
int val = 0;
const int spdif_index = 16;
struct hda_spdif_out *spdif;
struct hda_bus *bus = codec->bus;
if (bus->primary_dig_out_type == HDA_PCM_TYPE_HDMI &&
type == HDA_PCM_TYPE_SPDIF) {
idx = spdif_index;
} else if (bus->primary_dig_out_type == HDA_PCM_TYPE_SPDIF &&
type == HDA_PCM_TYPE_HDMI) {
for (dig_mix = dig_mixes; dig_mix->name; dig_mix++) {
kctl = find_mixer_ctl(codec, dig_mix->name, 0, 0);
if (!kctl)
break;
kctl->id.index = spdif_index;
}
bus->primary_dig_out_type = HDA_PCM_TYPE_HDMI;
}
if (!bus->primary_dig_out_type)
bus->primary_dig_out_type = type;
idx = find_empty_mixer_ctl_idx(codec, "IEC958 Playback Switch", idx);
if (idx < 0) {
codec_err(codec, "too many IEC958 outputs\n");
return -EBUSY;
}
spdif = snd_array_new(&codec->spdif_out);
if (!spdif)
return -ENOMEM;
for (dig_mix = dig_mixes; dig_mix->name; dig_mix++) {
kctl = snd_ctl_new1(dig_mix, codec);
if (!kctl)
return -ENOMEM;
kctl->id.index = idx;
kctl->private_value = codec->spdif_out.used - 1;
err = snd_hda_ctl_add(codec, associated_nid, kctl);
if (err < 0)
return err;
}
spdif->nid = cvt_nid;
snd_hdac_regmap_read(&codec->core, cvt_nid,
AC_VERB_GET_DIGI_CONVERT_1, &val);
spdif->ctls = val;
spdif->status = convert_to_spdif_status(spdif->ctls);
return 0;
}
struct hda_spdif_out *snd_hda_spdif_out_of_nid(struct hda_codec *codec,
hda_nid_t nid)
{
int i;
for (i = 0; i < codec->spdif_out.used; i++) {
struct hda_spdif_out *spdif =
snd_array_elem(&codec->spdif_out, i);
if (spdif->nid == nid)
return spdif;
}
return NULL;
}
void snd_hda_spdif_ctls_unassign(struct hda_codec *codec, int idx)
{
struct hda_spdif_out *spdif;
mutex_lock(&codec->spdif_mutex);
spdif = snd_array_elem(&codec->spdif_out, idx);
spdif->nid = (u16)-1;
mutex_unlock(&codec->spdif_mutex);
}
void snd_hda_spdif_ctls_assign(struct hda_codec *codec, int idx, hda_nid_t nid)
{
struct hda_spdif_out *spdif;
unsigned short val;
mutex_lock(&codec->spdif_mutex);
spdif = snd_array_elem(&codec->spdif_out, idx);
if (spdif->nid != nid) {
spdif->nid = nid;
val = spdif->ctls;
set_spdif_ctls(codec, nid, val & 0xff, (val >> 8) & 0xff);
}
mutex_unlock(&codec->spdif_mutex);
}
static int spdif_share_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_multi_out *mout = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = mout->share_spdif;
return 0;
}
static int spdif_share_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_multi_out *mout = snd_kcontrol_chip(kcontrol);
mout->share_spdif = !!ucontrol->value.integer.value[0];
return 0;
}
int snd_hda_create_spdif_share_sw(struct hda_codec *codec,
struct hda_multi_out *mout)
{
struct snd_kcontrol *kctl;
if (!mout->dig_out_nid)
return 0;
kctl = snd_ctl_new1(&spdif_share_sw, mout);
if (!kctl)
return -ENOMEM;
return snd_hda_ctl_add(codec, mout->dig_out_nid, kctl);
}
static int snd_hda_spdif_in_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = codec->spdif_in_enable;
return 0;
}
static int snd_hda_spdif_in_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value;
unsigned int val = !!ucontrol->value.integer.value[0];
int change;
mutex_lock(&codec->spdif_mutex);
change = codec->spdif_in_enable != val;
if (change) {
codec->spdif_in_enable = val;
snd_hdac_regmap_write(&codec->core, nid,
AC_VERB_SET_DIGI_CONVERT_1, val);
}
mutex_unlock(&codec->spdif_mutex);
return change;
}
static int snd_hda_spdif_in_status_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
hda_nid_t nid = kcontrol->private_value;
unsigned int val;
unsigned int sbits;
snd_hdac_regmap_read(&codec->core, nid,
AC_VERB_GET_DIGI_CONVERT_1, &val);
sbits = convert_to_spdif_status(val);
ucontrol->value.iec958.status[0] = sbits;
ucontrol->value.iec958.status[1] = sbits >> 8;
ucontrol->value.iec958.status[2] = sbits >> 16;
ucontrol->value.iec958.status[3] = sbits >> 24;
return 0;
}
int snd_hda_create_spdif_in_ctls(struct hda_codec *codec, hda_nid_t nid)
{
int err;
struct snd_kcontrol *kctl;
struct snd_kcontrol_new *dig_mix;
int idx;
idx = find_empty_mixer_ctl_idx(codec, "IEC958 Capture Switch", 0);
if (idx < 0) {
codec_err(codec, "too many IEC958 inputs\n");
return -EBUSY;
}
for (dig_mix = dig_in_ctls; dig_mix->name; dig_mix++) {
kctl = snd_ctl_new1(dig_mix, codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = nid;
err = snd_hda_ctl_add(codec, nid, kctl);
if (err < 0)
return err;
}
codec->spdif_in_enable =
snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_DIGI_CONVERT_1, 0) &
AC_DIG1_ENABLE;
return 0;
}
void snd_hda_codec_set_power_to_all(struct hda_codec *codec, hda_nid_t fg,
unsigned int power_state)
{
hda_nid_t nid;
for_each_hda_codec_node(nid, codec) {
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int state = power_state;
if (!(wcaps & AC_WCAP_POWER))
continue;
if (codec->power_filter) {
state = codec->power_filter(codec, nid, power_state);
if (state != power_state && power_state == AC_PWRST_D3)
continue;
}
snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE,
state);
}
}
static unsigned int hda_sync_power_state(struct hda_codec *codec,
hda_nid_t fg,
unsigned int power_state)
{
unsigned long end_time = jiffies + msecs_to_jiffies(500);
unsigned int state, actual_state;
for (;;) {
state = snd_hda_codec_read(codec, fg, 0,
AC_VERB_GET_POWER_STATE, 0);
if (state & AC_PWRST_ERROR)
break;
actual_state = (state >> 4) & 0x0f;
if (actual_state == power_state)
break;
if (time_after_eq(jiffies, end_time))
break;
msleep(1);
}
return state;
}
unsigned int snd_hda_codec_eapd_power_filter(struct hda_codec *codec,
hda_nid_t nid,
unsigned int power_state)
{
if (nid == codec->core.afg || nid == codec->core.mfg)
return power_state;
if (power_state == AC_PWRST_D3 &&
get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_PIN &&
(snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_EAPD)) {
int eapd = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_EAPD_BTLENABLE, 0);
if (eapd & 0x02)
return AC_PWRST_D0;
}
return power_state;
}
static unsigned int hda_set_power_state(struct hda_codec *codec,
unsigned int power_state)
{
hda_nid_t fg = codec->core.afg ? codec->core.afg : codec->core.mfg;
int count;
unsigned int state;
int flags = 0;
if (power_state == AC_PWRST_D3) {
if (codec->depop_delay < 0)
msleep(codec_has_epss(codec) ? 10 : 100);
else if (codec->depop_delay > 0)
msleep(codec->depop_delay);
flags = HDA_RW_NO_RESPONSE_FALLBACK;
}
for (count = 0; count < 10; count++) {
if (codec->patch_ops.set_power_state)
codec->patch_ops.set_power_state(codec, fg,
power_state);
else {
state = power_state;
if (codec->power_filter)
state = codec->power_filter(codec, fg, state);
if (state == power_state || power_state != AC_PWRST_D3)
snd_hda_codec_read(codec, fg, flags,
AC_VERB_SET_POWER_STATE,
state);
snd_hda_codec_set_power_to_all(codec, fg, power_state);
}
state = hda_sync_power_state(codec, fg, power_state);
if (!(state & AC_PWRST_ERROR))
break;
}
return state;
}
static void sync_power_up_states(struct hda_codec *codec)
{
hda_nid_t nid;
if (!codec->power_filter)
return;
for_each_hda_codec_node(nid, codec) {
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int target;
if (!(wcaps & AC_WCAP_POWER))
continue;
target = codec->power_filter(codec, nid, AC_PWRST_D0);
if (target == AC_PWRST_D0)
continue;
if (!snd_hda_check_power_state(codec, nid, target))
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_POWER_STATE, target);
}
}
static void hda_exec_init_verbs(struct hda_codec *codec)
{
if (codec->init_verbs.list)
snd_hda_sequence_write(codec, codec->init_verbs.list);
}
static inline void hda_exec_init_verbs(struct hda_codec *codec) {}
static void update_power_acct(struct hda_codec *codec, bool on)
{
unsigned long delta = jiffies - codec->power_jiffies;
if (on)
codec->power_on_acct += delta;
else
codec->power_off_acct += delta;
codec->power_jiffies += delta;
}
void snd_hda_update_power_acct(struct hda_codec *codec)
{
update_power_acct(codec, hda_codec_is_power_on(codec));
}
static unsigned int hda_call_codec_suspend(struct hda_codec *codec)
{
unsigned int state;
atomic_inc(&codec->core.in_pm);
if (codec->patch_ops.suspend)
codec->patch_ops.suspend(codec);
hda_cleanup_all_streams(codec);
state = hda_set_power_state(codec, AC_PWRST_D3);
update_power_acct(codec, true);
atomic_dec(&codec->core.in_pm);
return state;
}
static void hda_call_codec_resume(struct hda_codec *codec)
{
atomic_inc(&codec->core.in_pm);
if (codec->core.regmap)
regcache_mark_dirty(codec->core.regmap);
codec->power_jiffies = jiffies;
hda_set_power_state(codec, AC_PWRST_D0);
restore_shutup_pins(codec);
hda_exec_init_verbs(codec);
snd_hda_jack_set_dirty_all(codec);
if (codec->patch_ops.resume)
codec->patch_ops.resume(codec);
else {
if (codec->patch_ops.init)
codec->patch_ops.init(codec);
if (codec->core.regmap)
regcache_sync(codec->core.regmap);
}
if (codec->jackpoll_interval)
hda_jackpoll_work(&codec->jackpoll_work.work);
else
snd_hda_jack_report_sync(codec);
atomic_dec(&codec->core.in_pm);
}
static int hda_codec_runtime_suspend(struct device *dev)
{
struct hda_codec *codec = dev_to_hda_codec(dev);
struct hda_pcm *pcm;
unsigned int state;
cancel_delayed_work_sync(&codec->jackpoll_work);
list_for_each_entry(pcm, &codec->pcm_list_head, list)
snd_pcm_suspend_all(pcm->pcm);
state = hda_call_codec_suspend(codec);
if (codec_has_clkstop(codec) && codec_has_epss(codec) &&
(state & AC_PWRST_CLK_STOP_OK))
snd_hdac_codec_link_down(&codec->core);
snd_hdac_link_power(&codec->core, false);
return 0;
}
static int hda_codec_runtime_resume(struct device *dev)
{
struct hda_codec *codec = dev_to_hda_codec(dev);
snd_hdac_link_power(&codec->core, true);
snd_hdac_codec_link_up(&codec->core);
hda_call_codec_resume(codec);
pm_runtime_mark_last_busy(dev);
return 0;
}
static int add_std_chmaps(struct hda_codec *codec)
{
struct hda_pcm *pcm;
int str, err;
list_for_each_entry(pcm, &codec->pcm_list_head, list) {
for (str = 0; str < 2; str++) {
struct hda_pcm_stream *hinfo = &pcm->stream[str];
struct snd_pcm_chmap *chmap;
const struct snd_pcm_chmap_elem *elem;
if (!pcm->pcm || pcm->own_chmap || !hinfo->substreams)
continue;
elem = hinfo->chmap ? hinfo->chmap : snd_pcm_std_chmaps;
err = snd_pcm_add_chmap_ctls(pcm->pcm, str, elem,
hinfo->channels_max,
0, &chmap);
if (err < 0)
return err;
chmap->channel_mask = SND_PCM_CHMAP_MASK_2468;
}
}
return 0;
}
int snd_hda_codec_build_controls(struct hda_codec *codec)
{
int err = 0;
hda_exec_init_verbs(codec);
if (codec->patch_ops.init)
err = codec->patch_ops.init(codec);
if (!err && codec->patch_ops.build_controls)
err = codec->patch_ops.build_controls(codec);
if (err < 0)
return err;
err = add_std_chmaps(codec);
if (err < 0)
return err;
if (codec->jackpoll_interval)
hda_jackpoll_work(&codec->jackpoll_work.work);
else
snd_hda_jack_report_sync(codec);
sync_power_up_states(codec);
return 0;
}
static int hda_pcm_default_open_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
return 0;
}
static int hda_pcm_default_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
snd_hda_codec_setup_stream(codec, hinfo->nid, stream_tag, 0, format);
return 0;
}
static int hda_pcm_default_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
snd_hda_codec_cleanup_stream(codec, hinfo->nid);
return 0;
}
static int set_pcm_default_values(struct hda_codec *codec,
struct hda_pcm_stream *info)
{
int err;
if (info->nid && (!info->rates || !info->formats)) {
err = snd_hda_query_supported_pcm(codec, info->nid,
info->rates ? NULL : &info->rates,
info->formats ? NULL : &info->formats,
info->maxbps ? NULL : &info->maxbps);
if (err < 0)
return err;
}
if (info->ops.open == NULL)
info->ops.open = hda_pcm_default_open_close;
if (info->ops.close == NULL)
info->ops.close = hda_pcm_default_open_close;
if (info->ops.prepare == NULL) {
if (snd_BUG_ON(!info->nid))
return -EINVAL;
info->ops.prepare = hda_pcm_default_prepare;
}
if (info->ops.cleanup == NULL) {
if (snd_BUG_ON(!info->nid))
return -EINVAL;
info->ops.cleanup = hda_pcm_default_cleanup;
}
return 0;
}
int snd_hda_codec_prepare(struct hda_codec *codec,
struct hda_pcm_stream *hinfo,
unsigned int stream,
unsigned int format,
struct snd_pcm_substream *substream)
{
int ret;
mutex_lock(&codec->bus->prepare_mutex);
if (hinfo->ops.prepare)
ret = hinfo->ops.prepare(hinfo, codec, stream, format,
substream);
else
ret = -ENODEV;
if (ret >= 0)
purify_inactive_streams(codec);
mutex_unlock(&codec->bus->prepare_mutex);
return ret;
}
void snd_hda_codec_cleanup(struct hda_codec *codec,
struct hda_pcm_stream *hinfo,
struct snd_pcm_substream *substream)
{
mutex_lock(&codec->bus->prepare_mutex);
if (hinfo->ops.cleanup)
hinfo->ops.cleanup(hinfo, codec, substream);
mutex_unlock(&codec->bus->prepare_mutex);
}
static int get_empty_pcm_device(struct hda_bus *bus, unsigned int type)
{
static int audio_idx[HDA_PCM_NTYPES][5] = {
[HDA_PCM_TYPE_AUDIO] = { 0, 2, 4, 5, -1 },
[HDA_PCM_TYPE_SPDIF] = { 1, -1 },
[HDA_PCM_TYPE_HDMI] = { 3, 7, 8, 9, -1 },
[HDA_PCM_TYPE_MODEM] = { 6, -1 },
};
int i;
if (type >= HDA_PCM_NTYPES) {
dev_err(bus->card->dev, "Invalid PCM type %d\n", type);
return -EINVAL;
}
for (i = 0; audio_idx[type][i] >= 0; i++) {
#ifndef CONFIG_SND_DYNAMIC_MINORS
if (audio_idx[type][i] >= 8)
break;
#endif
if (!test_and_set_bit(audio_idx[type][i], bus->pcm_dev_bits))
return audio_idx[type][i];
}
#ifdef CONFIG_SND_DYNAMIC_MINORS
for (i = 10; i < 32; i++) {
if (!test_and_set_bit(i, bus->pcm_dev_bits))
return i;
}
#endif
dev_warn(bus->card->dev, "Too many %s devices\n",
snd_hda_pcm_type_name[type]);
#ifndef CONFIG_SND_DYNAMIC_MINORS
dev_warn(bus->card->dev,
"Consider building the kernel with CONFIG_SND_DYNAMIC_MINORS=y\n");
#endif
return -EAGAIN;
}
int snd_hda_codec_parse_pcms(struct hda_codec *codec)
{
struct hda_pcm *cpcm;
int err;
if (!list_empty(&codec->pcm_list_head))
return 0;
if (!codec->patch_ops.build_pcms)
return 0;
err = codec->patch_ops.build_pcms(codec);
if (err < 0) {
codec_err(codec, "cannot build PCMs for #%d (error %d)\n",
codec->core.addr, err);
return err;
}
list_for_each_entry(cpcm, &codec->pcm_list_head, list) {
int stream;
for (stream = 0; stream < 2; stream++) {
struct hda_pcm_stream *info = &cpcm->stream[stream];
if (!info->substreams)
continue;
err = set_pcm_default_values(codec, info);
if (err < 0) {
codec_warn(codec,
"fail to setup default for PCM %s\n",
cpcm->name);
return err;
}
}
}
return 0;
}
int snd_hda_codec_build_pcms(struct hda_codec *codec)
{
struct hda_bus *bus = codec->bus;
struct hda_pcm *cpcm;
int dev, err;
err = snd_hda_codec_parse_pcms(codec);
if (err < 0)
return err;
list_for_each_entry(cpcm, &codec->pcm_list_head, list) {
if (cpcm->pcm)
continue;
if (!cpcm->stream[0].substreams && !cpcm->stream[1].substreams)
continue;
dev = get_empty_pcm_device(bus, cpcm->pcm_type);
if (dev < 0)
continue;
cpcm->device = dev;
err = snd_hda_attach_pcm_stream(bus, codec, cpcm);
if (err < 0) {
codec_err(codec,
"cannot attach PCM stream %d for codec #%d\n",
dev, codec->core.addr);
continue;
}
}
return 0;
}
int snd_hda_add_new_ctls(struct hda_codec *codec,
const struct snd_kcontrol_new *knew)
{
int err;
for (; knew->name; knew++) {
struct snd_kcontrol *kctl;
int addr = 0, idx = 0;
if (knew->iface == -1)
continue;
for (;;) {
kctl = snd_ctl_new1(knew, codec);
if (!kctl)
return -ENOMEM;
if (addr > 0)
kctl->id.device = addr;
if (idx > 0)
kctl->id.index = idx;
err = snd_hda_ctl_add(codec, 0, kctl);
if (!err)
break;
if (!addr && codec->core.addr)
addr = codec->core.addr;
else if (!idx && !knew->index) {
idx = find_empty_mixer_ctl_idx(codec,
knew->name, 0);
if (idx <= 0)
return err;
} else
return err;
}
}
return 0;
}
static void codec_set_power_save(struct hda_codec *codec, int delay)
{
struct device *dev = hda_codec_dev(codec);
if (delay == 0 && codec->auto_runtime_pm)
delay = 3000;
if (delay > 0) {
pm_runtime_set_autosuspend_delay(dev, delay);
pm_runtime_use_autosuspend(dev);
pm_runtime_allow(dev);
if (!pm_runtime_suspended(dev))
pm_runtime_mark_last_busy(dev);
} else {
pm_runtime_dont_use_autosuspend(dev);
pm_runtime_forbid(dev);
}
}
void snd_hda_set_power_save(struct hda_bus *bus, int delay)
{
struct hda_codec *c;
list_for_each_codec(c, bus)
codec_set_power_save(c, delay);
}
int snd_hda_check_amp_list_power(struct hda_codec *codec,
struct hda_loopback_check *check,
hda_nid_t nid)
{
const struct hda_amp_list *p;
int ch, v;
if (!check->amplist)
return 0;
for (p = check->amplist; p->nid; p++) {
if (p->nid == nid)
break;
}
if (!p->nid)
return 0;
for (p = check->amplist; p->nid; p++) {
for (ch = 0; ch < 2; ch++) {
v = snd_hda_codec_amp_read(codec, p->nid, ch, p->dir,
p->idx);
if (!(v & HDA_AMP_MUTE) && v > 0) {
if (!check->power_on) {
check->power_on = 1;
snd_hda_power_up_pm(codec);
}
return 1;
}
}
}
if (check->power_on) {
check->power_on = 0;
snd_hda_power_down_pm(codec);
}
return 0;
}
int snd_hda_input_mux_info(const struct hda_input_mux *imux,
struct snd_ctl_elem_info *uinfo)
{
unsigned int index;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = imux->num_items;
if (!imux->num_items)
return 0;
index = uinfo->value.enumerated.item;
if (index >= imux->num_items)
index = imux->num_items - 1;
strcpy(uinfo->value.enumerated.name, imux->items[index].label);
return 0;
}
int snd_hda_input_mux_put(struct hda_codec *codec,
const struct hda_input_mux *imux,
struct snd_ctl_elem_value *ucontrol,
hda_nid_t nid,
unsigned int *cur_val)
{
unsigned int idx;
if (!imux->num_items)
return 0;
idx = ucontrol->value.enumerated.item[0];
if (idx >= imux->num_items)
idx = imux->num_items - 1;
if (*cur_val == idx)
return 0;
snd_hda_codec_write_cache(codec, nid, 0, AC_VERB_SET_CONNECT_SEL,
imux->items[idx].index);
*cur_val = idx;
return 1;
}
int snd_hda_enum_helper_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo,
int num_items, const char * const *texts)
{
static const char * const texts_default[] = {
"Disabled", "Enabled"
};
if (!texts || !num_items) {
num_items = 2;
texts = texts_default;
}
return snd_ctl_enum_info(uinfo, 1, num_items, texts);
}
static void setup_dig_out_stream(struct hda_codec *codec, hda_nid_t nid,
unsigned int stream_tag, unsigned int format)
{
struct hda_spdif_out *spdif;
unsigned int curr_fmt;
bool reset;
spdif = snd_hda_spdif_out_of_nid(codec, nid);
if (WARN_ON(spdif == NULL))
return;
curr_fmt = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_STREAM_FORMAT, 0);
reset = codec->spdif_status_reset &&
(spdif->ctls & AC_DIG1_ENABLE) &&
curr_fmt != format;
if (reset)
set_dig_out_convert(codec, nid,
spdif->ctls & ~AC_DIG1_ENABLE & 0xff,
-1);
snd_hda_codec_setup_stream(codec, nid, stream_tag, 0, format);
if (codec->slave_dig_outs) {
const hda_nid_t *d;
for (d = codec->slave_dig_outs; *d; d++)
snd_hda_codec_setup_stream(codec, *d, stream_tag, 0,
format);
}
if (reset)
set_dig_out_convert(codec, nid,
spdif->ctls & 0xff, -1);
}
static void cleanup_dig_out_stream(struct hda_codec *codec, hda_nid_t nid)
{
snd_hda_codec_cleanup_stream(codec, nid);
if (codec->slave_dig_outs) {
const hda_nid_t *d;
for (d = codec->slave_dig_outs; *d; d++)
snd_hda_codec_cleanup_stream(codec, *d);
}
}
int snd_hda_multi_out_dig_open(struct hda_codec *codec,
struct hda_multi_out *mout)
{
mutex_lock(&codec->spdif_mutex);
if (mout->dig_out_used == HDA_DIG_ANALOG_DUP)
cleanup_dig_out_stream(codec, mout->dig_out_nid);
mout->dig_out_used = HDA_DIG_EXCLUSIVE;
mutex_unlock(&codec->spdif_mutex);
return 0;
}
int snd_hda_multi_out_dig_prepare(struct hda_codec *codec,
struct hda_multi_out *mout,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
mutex_lock(&codec->spdif_mutex);
setup_dig_out_stream(codec, mout->dig_out_nid, stream_tag, format);
mutex_unlock(&codec->spdif_mutex);
return 0;
}
int snd_hda_multi_out_dig_cleanup(struct hda_codec *codec,
struct hda_multi_out *mout)
{
mutex_lock(&codec->spdif_mutex);
cleanup_dig_out_stream(codec, mout->dig_out_nid);
mutex_unlock(&codec->spdif_mutex);
return 0;
}
int snd_hda_multi_out_dig_close(struct hda_codec *codec,
struct hda_multi_out *mout)
{
mutex_lock(&codec->spdif_mutex);
mout->dig_out_used = 0;
mutex_unlock(&codec->spdif_mutex);
return 0;
}
int snd_hda_multi_out_analog_open(struct hda_codec *codec,
struct hda_multi_out *mout,
struct snd_pcm_substream *substream,
struct hda_pcm_stream *hinfo)
{
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw.channels_max = mout->max_channels;
if (mout->dig_out_nid) {
if (!mout->analog_rates) {
mout->analog_rates = hinfo->rates;
mout->analog_formats = hinfo->formats;
mout->analog_maxbps = hinfo->maxbps;
} else {
runtime->hw.rates = mout->analog_rates;
runtime->hw.formats = mout->analog_formats;
hinfo->maxbps = mout->analog_maxbps;
}
if (!mout->spdif_rates) {
snd_hda_query_supported_pcm(codec, mout->dig_out_nid,
&mout->spdif_rates,
&mout->spdif_formats,
&mout->spdif_maxbps);
}
mutex_lock(&codec->spdif_mutex);
if (mout->share_spdif) {
if ((runtime->hw.rates & mout->spdif_rates) &&
(runtime->hw.formats & mout->spdif_formats)) {
runtime->hw.rates &= mout->spdif_rates;
runtime->hw.formats &= mout->spdif_formats;
if (mout->spdif_maxbps < hinfo->maxbps)
hinfo->maxbps = mout->spdif_maxbps;
} else {
mout->share_spdif = 0;
}
}
mutex_unlock(&codec->spdif_mutex);
}
return snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS, 2);
}
int snd_hda_multi_out_analog_prepare(struct hda_codec *codec,
struct hda_multi_out *mout,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
const hda_nid_t *nids = mout->dac_nids;
int chs = substream->runtime->channels;
struct hda_spdif_out *spdif;
int i;
mutex_lock(&codec->spdif_mutex);
spdif = snd_hda_spdif_out_of_nid(codec, mout->dig_out_nid);
if (mout->dig_out_nid && mout->share_spdif &&
mout->dig_out_used != HDA_DIG_EXCLUSIVE) {
if (chs == 2 && spdif != NULL &&
snd_hda_is_supported_format(codec, mout->dig_out_nid,
format) &&
!(spdif->status & IEC958_AES0_NONAUDIO)) {
mout->dig_out_used = HDA_DIG_ANALOG_DUP;
setup_dig_out_stream(codec, mout->dig_out_nid,
stream_tag, format);
} else {
mout->dig_out_used = 0;
cleanup_dig_out_stream(codec, mout->dig_out_nid);
}
}
mutex_unlock(&codec->spdif_mutex);
snd_hda_codec_setup_stream(codec, nids[HDA_FRONT], stream_tag,
0, format);
if (!mout->no_share_stream &&
mout->hp_nid && mout->hp_nid != nids[HDA_FRONT])
snd_hda_codec_setup_stream(codec, mout->hp_nid, stream_tag,
0, format);
for (i = 0; i < ARRAY_SIZE(mout->hp_out_nid); i++)
if (!mout->no_share_stream && mout->hp_out_nid[i])
snd_hda_codec_setup_stream(codec,
mout->hp_out_nid[i],
stream_tag, 0, format);
for (i = 1; i < mout->num_dacs; i++) {
if (chs >= (i + 1) * 2)
snd_hda_codec_setup_stream(codec, nids[i], stream_tag,
i * 2, format);
else if (!mout->no_share_stream)
snd_hda_codec_setup_stream(codec, nids[i], stream_tag,
0, format);
}
for (i = 0; i < ARRAY_SIZE(mout->extra_out_nid); i++) {
int ch = 0;
if (!mout->extra_out_nid[i])
break;
if (chs >= (i + 1) * 2)
ch = i * 2;
else if (!mout->no_share_stream)
break;
snd_hda_codec_setup_stream(codec, mout->extra_out_nid[i],
stream_tag, ch, format);
}
return 0;
}
int snd_hda_multi_out_analog_cleanup(struct hda_codec *codec,
struct hda_multi_out *mout)
{
const hda_nid_t *nids = mout->dac_nids;
int i;
for (i = 0; i < mout->num_dacs; i++)
snd_hda_codec_cleanup_stream(codec, nids[i]);
if (mout->hp_nid)
snd_hda_codec_cleanup_stream(codec, mout->hp_nid);
for (i = 0; i < ARRAY_SIZE(mout->hp_out_nid); i++)
if (mout->hp_out_nid[i])
snd_hda_codec_cleanup_stream(codec,
mout->hp_out_nid[i]);
for (i = 0; i < ARRAY_SIZE(mout->extra_out_nid); i++)
if (mout->extra_out_nid[i])
snd_hda_codec_cleanup_stream(codec,
mout->extra_out_nid[i]);
mutex_lock(&codec->spdif_mutex);
if (mout->dig_out_nid && mout->dig_out_used == HDA_DIG_ANALOG_DUP) {
cleanup_dig_out_stream(codec, mout->dig_out_nid);
mout->dig_out_used = 0;
}
mutex_unlock(&codec->spdif_mutex);
return 0;
}
unsigned int snd_hda_get_default_vref(struct hda_codec *codec, hda_nid_t pin)
{
unsigned int pincap;
unsigned int oldval;
oldval = snd_hda_codec_read(codec, pin, 0,
AC_VERB_GET_PIN_WIDGET_CONTROL, 0);
pincap = snd_hda_query_pin_caps(codec, pin);
pincap = (pincap & AC_PINCAP_VREF) >> AC_PINCAP_VREF_SHIFT;
if ((pincap & AC_PINCAP_VREF_80) && oldval != PIN_VREF50)
return AC_PINCTL_VREF_80;
else if (pincap & AC_PINCAP_VREF_50)
return AC_PINCTL_VREF_50;
else if (pincap & AC_PINCAP_VREF_100)
return AC_PINCTL_VREF_100;
else if (pincap & AC_PINCAP_VREF_GRD)
return AC_PINCTL_VREF_GRD;
return AC_PINCTL_VREF_HIZ;
}
unsigned int snd_hda_correct_pin_ctl(struct hda_codec *codec,
hda_nid_t pin, unsigned int val)
{
static unsigned int cap_lists[][2] = {
{ AC_PINCTL_VREF_100, AC_PINCAP_VREF_100 },
{ AC_PINCTL_VREF_80, AC_PINCAP_VREF_80 },
{ AC_PINCTL_VREF_50, AC_PINCAP_VREF_50 },
{ AC_PINCTL_VREF_GRD, AC_PINCAP_VREF_GRD },
};
unsigned int cap;
if (!val)
return 0;
cap = snd_hda_query_pin_caps(codec, pin);
if (!cap)
return val;
if (val & AC_PINCTL_OUT_EN) {
if (!(cap & AC_PINCAP_OUT))
val &= ~(AC_PINCTL_OUT_EN | AC_PINCTL_HP_EN);
else if ((val & AC_PINCTL_HP_EN) && !(cap & AC_PINCAP_HP_DRV))
val &= ~AC_PINCTL_HP_EN;
}
if (val & AC_PINCTL_IN_EN) {
if (!(cap & AC_PINCAP_IN))
val &= ~(AC_PINCTL_IN_EN | AC_PINCTL_VREFEN);
else {
unsigned int vcap, vref;
int i;
vcap = (cap & AC_PINCAP_VREF) >> AC_PINCAP_VREF_SHIFT;
vref = val & AC_PINCTL_VREFEN;
for (i = 0; i < ARRAY_SIZE(cap_lists); i++) {
if (vref == cap_lists[i][0] &&
!(vcap & cap_lists[i][1])) {
if (i == ARRAY_SIZE(cap_lists) - 1)
vref = AC_PINCTL_VREF_HIZ;
else
vref = cap_lists[i + 1][0];
}
}
val &= ~AC_PINCTL_VREFEN;
val |= vref;
}
}
return val;
}
int _snd_hda_set_pin_ctl(struct hda_codec *codec, hda_nid_t pin,
unsigned int val, bool cached)
{
val = snd_hda_correct_pin_ctl(codec, pin, val);
snd_hda_codec_set_pin_target(codec, pin, val);
if (cached)
return snd_hda_codec_update_cache(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, val);
else
return snd_hda_codec_write(codec, pin, 0,
AC_VERB_SET_PIN_WIDGET_CONTROL, val);
}
int snd_hda_add_imux_item(struct hda_codec *codec,
struct hda_input_mux *imux, const char *label,
int index, int *type_idx)
{
int i, label_idx = 0;
if (imux->num_items >= HDA_MAX_NUM_INPUTS) {
codec_err(codec, "hda_codec: Too many imux items!\n");
return -EINVAL;
}
for (i = 0; i < imux->num_items; i++) {
if (!strncmp(label, imux->items[i].label, strlen(label)))
label_idx++;
}
if (type_idx)
*type_idx = label_idx;
if (label_idx > 0)
snprintf(imux->items[imux->num_items].label,
sizeof(imux->items[imux->num_items].label),
"%s %d", label, label_idx);
else
strlcpy(imux->items[imux->num_items].label, label,
sizeof(imux->items[imux->num_items].label));
imux->items[imux->num_items].index = index;
imux->num_items++;
return 0;
}
void snd_hda_bus_reset_codecs(struct hda_bus *bus)
{
struct hda_codec *codec;
list_for_each_codec(codec, bus) {
cancel_delayed_work_sync(&codec->jackpoll_work);
#ifdef CONFIG_PM
if (hda_codec_is_power_on(codec)) {
hda_call_codec_suspend(codec);
hda_call_codec_resume(codec);
}
#endif
}
}
void snd_print_pcm_bits(int pcm, char *buf, int buflen)
{
static unsigned int bits[] = { 8, 16, 20, 24, 32 };
int i, j;
for (i = 0, j = 0; i < ARRAY_SIZE(bits); i++)
if (pcm & (AC_SUPPCM_BITS_8 << i))
j += snprintf(buf + j, buflen - j, " %d", bits[i]);
buf[j] = '\0';
}
