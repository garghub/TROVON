static void default_release(struct device *dev)
{
snd_hdac_device_exit(container_of(dev, struct hdac_device, dev));
}
int snd_hdac_device_init(struct hdac_device *codec, struct hdac_bus *bus,
const char *name, unsigned int addr)
{
struct device *dev;
hda_nid_t fg;
int err;
dev = &codec->dev;
device_initialize(dev);
dev->parent = bus->dev;
dev->bus = &snd_hda_bus_type;
dev->release = default_release;
dev->groups = hdac_dev_attr_groups;
dev_set_name(dev, "%s", name);
device_enable_async_suspend(dev);
codec->bus = bus;
codec->addr = addr;
codec->type = HDA_DEV_CORE;
pm_runtime_set_active(&codec->dev);
pm_runtime_get_noresume(&codec->dev);
atomic_set(&codec->in_pm, 0);
err = snd_hdac_bus_add_device(bus, codec);
if (err < 0)
goto error;
codec->vendor_id = snd_hdac_read_parm(codec, AC_NODE_ROOT,
AC_PAR_VENDOR_ID);
if (codec->vendor_id == -1) {
codec->vendor_id = snd_hdac_read_parm(codec, AC_NODE_ROOT,
AC_PAR_VENDOR_ID);
}
codec->subsystem_id = snd_hdac_read_parm(codec, AC_NODE_ROOT,
AC_PAR_SUBSYSTEM_ID);
codec->revision_id = snd_hdac_read_parm(codec, AC_NODE_ROOT,
AC_PAR_REV_ID);
setup_fg_nodes(codec);
if (!codec->afg && !codec->mfg) {
dev_err(dev, "no AFG or MFG node found\n");
err = -ENODEV;
goto error;
}
fg = codec->afg ? codec->afg : codec->mfg;
err = snd_hdac_refresh_widgets(codec);
if (err < 0)
goto error;
codec->power_caps = snd_hdac_read_parm(codec, fg, AC_PAR_POWER_STATE);
if (codec->subsystem_id == -1 || codec->subsystem_id == 0)
snd_hdac_read(codec, fg, AC_VERB_GET_SUBSYSTEM_ID, 0,
&codec->subsystem_id);
err = get_codec_vendor_name(codec);
if (err < 0)
goto error;
codec->chip_name = kasprintf(GFP_KERNEL, "ID %x",
codec->vendor_id & 0xffff);
if (!codec->chip_name) {
err = -ENOMEM;
goto error;
}
return 0;
error:
put_device(&codec->dev);
return err;
}
void snd_hdac_device_exit(struct hdac_device *codec)
{
pm_runtime_put_noidle(&codec->dev);
snd_hdac_bus_remove_device(codec->bus, codec);
kfree(codec->vendor_name);
kfree(codec->chip_name);
}
int snd_hdac_device_register(struct hdac_device *codec)
{
int err;
err = device_add(&codec->dev);
if (err < 0)
return err;
err = hda_widget_sysfs_init(codec);
if (err < 0) {
device_del(&codec->dev);
return err;
}
return 0;
}
void snd_hdac_device_unregister(struct hdac_device *codec)
{
if (device_is_registered(&codec->dev)) {
hda_widget_sysfs_exit(codec);
device_del(&codec->dev);
}
}
unsigned int snd_hdac_make_cmd(struct hdac_device *codec, hda_nid_t nid,
unsigned int verb, unsigned int parm)
{
u32 val, addr;
addr = codec->addr;
if ((addr & ~0xf) || (nid & ~0x7f) ||
(verb & ~0xfff) || (parm & ~0xffff)) {
dev_err(&codec->dev, "out of range cmd %x:%x:%x:%x\n",
addr, nid, verb, parm);
return -1;
}
val = addr << 28;
val |= (u32)nid << 20;
val |= verb << 8;
val |= parm;
return val;
}
int snd_hdac_exec_verb(struct hdac_device *codec, unsigned int cmd,
unsigned int flags, unsigned int *res)
{
if (codec->exec_verb)
return codec->exec_verb(codec, cmd, flags, res);
return snd_hdac_bus_exec_verb(codec->bus, codec->addr, cmd, res);
}
int snd_hdac_read(struct hdac_device *codec, hda_nid_t nid,
unsigned int verb, unsigned int parm, unsigned int *res)
{
unsigned int cmd = snd_hdac_make_cmd(codec, nid, verb, parm);
return snd_hdac_exec_verb(codec, cmd, 0, res);
}
int _snd_hdac_read_parm(struct hdac_device *codec, hda_nid_t nid, int parm,
unsigned int *res)
{
unsigned int cmd;
cmd = snd_hdac_regmap_encode_verb(nid, AC_VERB_PARAMETERS) | parm;
return snd_hdac_regmap_read_raw(codec, cmd, res);
}
int snd_hdac_read_parm_uncached(struct hdac_device *codec, hda_nid_t nid,
int parm)
{
int val;
if (codec->regmap)
regcache_cache_bypass(codec->regmap, true);
val = snd_hdac_read_parm(codec, nid, parm);
if (codec->regmap)
regcache_cache_bypass(codec->regmap, false);
return val;
}
int snd_hdac_override_parm(struct hdac_device *codec, hda_nid_t nid,
unsigned int parm, unsigned int val)
{
unsigned int verb = (AC_VERB_PARAMETERS << 8) | (nid << 20) | parm;
int err;
if (!codec->regmap)
return -EINVAL;
codec->caps_overwriting = true;
err = snd_hdac_regmap_write_raw(codec, verb, val);
codec->caps_overwriting = false;
return err;
}
int snd_hdac_get_sub_nodes(struct hdac_device *codec, hda_nid_t nid,
hda_nid_t *start_id)
{
unsigned int parm;
parm = snd_hdac_read_parm_uncached(codec, nid, AC_PAR_NODE_COUNT);
if (parm == -1) {
*start_id = 0;
return 0;
}
*start_id = (parm >> 16) & 0x7fff;
return (int)(parm & 0x7fff);
}
static void setup_fg_nodes(struct hdac_device *codec)
{
int i, total_nodes, function_id;
hda_nid_t nid;
total_nodes = snd_hdac_get_sub_nodes(codec, AC_NODE_ROOT, &nid);
for (i = 0; i < total_nodes; i++, nid++) {
function_id = snd_hdac_read_parm(codec, nid,
AC_PAR_FUNCTION_TYPE);
switch (function_id & 0xff) {
case AC_GRP_AUDIO_FUNCTION:
codec->afg = nid;
codec->afg_function_id = function_id & 0xff;
codec->afg_unsol = (function_id >> 8) & 1;
break;
case AC_GRP_MODEM_FUNCTION:
codec->mfg = nid;
codec->mfg_function_id = function_id & 0xff;
codec->mfg_unsol = (function_id >> 8) & 1;
break;
default:
break;
}
}
}
int snd_hdac_refresh_widgets(struct hdac_device *codec)
{
hda_nid_t start_nid;
int nums;
nums = snd_hdac_get_sub_nodes(codec, codec->afg, &start_nid);
if (!start_nid || nums <= 0 || nums >= 0xff) {
dev_err(&codec->dev, "cannot read sub nodes for FG 0x%02x\n",
codec->afg);
return -EINVAL;
}
codec->num_nodes = nums;
codec->start_nid = start_nid;
codec->end_nid = start_nid + nums;
return 0;
}
static unsigned int get_num_conns(struct hdac_device *codec, hda_nid_t nid)
{
unsigned int wcaps = get_wcaps(codec, nid);
unsigned int parm;
if (!(wcaps & AC_WCAP_CONN_LIST) &&
get_wcaps_type(wcaps) != AC_WID_VOL_KNB)
return 0;
parm = snd_hdac_read_parm(codec, nid, AC_PAR_CONNLIST_LEN);
if (parm == -1)
parm = 0;
return parm;
}
int snd_hdac_get_connections(struct hdac_device *codec, hda_nid_t nid,
hda_nid_t *conn_list, int max_conns)
{
unsigned int parm;
int i, conn_len, conns, err;
unsigned int shift, num_elems, mask;
hda_nid_t prev_nid;
int null_count = 0;
parm = get_num_conns(codec, nid);
if (!parm)
return 0;
if (parm & AC_CLIST_LONG) {
shift = 16;
num_elems = 2;
} else {
shift = 8;
num_elems = 4;
}
conn_len = parm & AC_CLIST_LENGTH;
mask = (1 << (shift-1)) - 1;
if (!conn_len)
return 0;
if (conn_len == 1) {
err = snd_hdac_read(codec, nid, AC_VERB_GET_CONNECT_LIST, 0,
&parm);
if (err < 0)
return err;
if (conn_list)
conn_list[0] = parm & mask;
return 1;
}
conns = 0;
prev_nid = 0;
for (i = 0; i < conn_len; i++) {
int range_val;
hda_nid_t val, n;
if (i % num_elems == 0) {
err = snd_hdac_read(codec, nid,
AC_VERB_GET_CONNECT_LIST, i,
&parm);
if (err < 0)
return -EIO;
}
range_val = !!(parm & (1 << (shift-1)));
val = parm & mask;
if (val == 0 && null_count++) {
dev_dbg(&codec->dev,
"invalid CONNECT_LIST verb %x[%i]:%x\n",
nid, i, parm);
return 0;
}
parm >>= shift;
if (range_val) {
if (!prev_nid || prev_nid >= val) {
dev_warn(&codec->dev,
"invalid dep_range_val %x:%x\n",
prev_nid, val);
continue;
}
for (n = prev_nid + 1; n <= val; n++) {
if (conn_list) {
if (conns >= max_conns)
return -ENOSPC;
conn_list[conns] = n;
}
conns++;
}
} else {
if (conn_list) {
if (conns >= max_conns)
return -ENOSPC;
conn_list[conns] = val;
}
conns++;
}
prev_nid = val;
}
return conns;
}
void snd_hdac_power_up(struct hdac_device *codec)
{
pm_runtime_get_sync(&codec->dev);
}
void snd_hdac_power_down(struct hdac_device *codec)
{
struct device *dev = &codec->dev;
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
}
void snd_hdac_power_up_pm(struct hdac_device *codec)
{
if (!atomic_inc_not_zero(&codec->in_pm))
snd_hdac_power_up(codec);
}
void snd_hdac_power_down_pm(struct hdac_device *codec)
{
if (atomic_dec_if_positive(&codec->in_pm) < 0)
snd_hdac_power_down(codec);
}
static int get_codec_vendor_name(struct hdac_device *codec)
{
const struct hda_vendor_id *c;
u16 vendor_id = codec->vendor_id >> 16;
for (c = hda_vendor_ids; c->id; c++) {
if (c->id == vendor_id) {
codec->vendor_name = kstrdup(c->name, GFP_KERNEL);
return codec->vendor_name ? 0 : -ENOMEM;
}
}
codec->vendor_name = kasprintf(GFP_KERNEL, "Generic %04x", vendor_id);
return codec->vendor_name ? 0 : -ENOMEM;
}
