static ssize_t power_on_acct_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
snd_hda_update_power_acct(codec);
return sprintf(buf, "%u\n", jiffies_to_msecs(codec->power_on_acct));
}
static ssize_t power_off_acct_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
snd_hda_update_power_acct(codec);
return sprintf(buf, "%u\n", jiffies_to_msecs(codec->power_off_acct));
}
static ssize_t pin_configs_show(struct hda_codec *codec,
struct snd_array *list,
char *buf)
{
int i, len = 0;
mutex_lock(&codec->user_mutex);
for (i = 0; i < list->used; i++) {
struct hda_pincfg *pin = snd_array_elem(list, i);
len += sprintf(buf + len, "0x%02x 0x%08x\n",
pin->nid, pin->cfg);
}
mutex_unlock(&codec->user_mutex);
return len;
}
static ssize_t init_pin_configs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
return pin_configs_show(codec, &codec->init_pins, buf);
}
static ssize_t driver_pin_configs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
return pin_configs_show(codec, &codec->driver_pins, buf);
}
static int clear_codec(struct hda_codec *codec)
{
int err;
err = snd_hda_codec_reset(codec);
if (err < 0) {
codec_err(codec, "The codec is being used, can't free.\n");
return err;
}
snd_hda_sysfs_clear(codec);
return 0;
}
static int reconfig_codec(struct hda_codec *codec)
{
int err;
snd_hda_power_up(codec);
codec_info(codec, "hda-codec: reconfiguring\n");
err = snd_hda_codec_reset(codec);
if (err < 0) {
codec_err(codec,
"The codec is being used, can't reconfigure.\n");
goto error;
}
err = snd_hda_codec_configure(codec);
if (err < 0)
goto error;
err = snd_hda_codec_build_pcms(codec);
if (err < 0)
goto error;
err = snd_hda_codec_build_controls(codec);
if (err < 0)
goto error;
err = snd_card_register(codec->card);
error:
snd_hda_power_down(codec);
return err;
}
static char *kstrndup_noeol(const char *src, size_t len)
{
char *s = kstrndup(src, len, GFP_KERNEL);
char *p;
if (!s)
return NULL;
p = strchr(s, '\n');
if (p)
*p = 0;
return s;
}
static ssize_t init_verbs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
int i, len = 0;
mutex_lock(&codec->user_mutex);
for (i = 0; i < codec->init_verbs.used; i++) {
struct hda_verb *v = snd_array_elem(&codec->init_verbs, i);
len += snprintf(buf + len, PAGE_SIZE - len,
"0x%02x 0x%03x 0x%04x\n",
v->nid, v->verb, v->param);
}
mutex_unlock(&codec->user_mutex);
return len;
}
static int parse_init_verbs(struct hda_codec *codec, const char *buf)
{
struct hda_verb *v;
int nid, verb, param;
if (sscanf(buf, "%i %i %i", &nid, &verb, &param) != 3)
return -EINVAL;
if (!nid || !verb)
return -EINVAL;
mutex_lock(&codec->user_mutex);
v = snd_array_new(&codec->init_verbs);
if (!v) {
mutex_unlock(&codec->user_mutex);
return -ENOMEM;
}
v->nid = nid;
v->verb = verb;
v->param = param;
mutex_unlock(&codec->user_mutex);
return 0;
}
static ssize_t init_verbs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hda_codec *codec = dev_get_drvdata(dev);
int err = parse_init_verbs(codec, buf);
if (err < 0)
return err;
return count;
}
static ssize_t hints_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
int i, len = 0;
mutex_lock(&codec->user_mutex);
for (i = 0; i < codec->hints.used; i++) {
struct hda_hint *hint = snd_array_elem(&codec->hints, i);
len += snprintf(buf + len, PAGE_SIZE - len,
"%s = %s\n", hint->key, hint->val);
}
mutex_unlock(&codec->user_mutex);
return len;
}
static struct hda_hint *get_hint(struct hda_codec *codec, const char *key)
{
int i;
for (i = 0; i < codec->hints.used; i++) {
struct hda_hint *hint = snd_array_elem(&codec->hints, i);
if (!strcmp(hint->key, key))
return hint;
}
return NULL;
}
static void remove_trail_spaces(char *str)
{
char *p;
if (!*str)
return;
p = str + strlen(str) - 1;
for (; isspace(*p); p--) {
*p = 0;
if (p == str)
return;
}
}
static int parse_hints(struct hda_codec *codec, const char *buf)
{
char *key, *val;
struct hda_hint *hint;
int err = 0;
buf = skip_spaces(buf);
if (!*buf || *buf == '#' || *buf == '\n')
return 0;
if (*buf == '=')
return -EINVAL;
key = kstrndup_noeol(buf, 1024);
if (!key)
return -ENOMEM;
val = strchr(key, '=');
if (!val) {
kfree(key);
return -EINVAL;
}
*val++ = 0;
val = skip_spaces(val);
remove_trail_spaces(key);
remove_trail_spaces(val);
mutex_lock(&codec->user_mutex);
hint = get_hint(codec, key);
if (hint) {
kfree(hint->key);
hint->key = key;
hint->val = val;
goto unlock;
}
if (codec->hints.used >= MAX_HINTS)
hint = NULL;
else
hint = snd_array_new(&codec->hints);
if (hint) {
hint->key = key;
hint->val = val;
} else {
err = -ENOMEM;
}
unlock:
mutex_unlock(&codec->user_mutex);
if (err)
kfree(key);
return err;
}
static ssize_t hints_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hda_codec *codec = dev_get_drvdata(dev);
int err = parse_hints(codec, buf);
if (err < 0)
return err;
return count;
}
static ssize_t user_pin_configs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hda_codec *codec = dev_get_drvdata(dev);
return pin_configs_show(codec, &codec->user_pins, buf);
}
static int parse_user_pin_configs(struct hda_codec *codec, const char *buf)
{
int nid, cfg, err;
if (sscanf(buf, "%i %i", &nid, &cfg) != 2)
return -EINVAL;
if (!nid)
return -EINVAL;
mutex_lock(&codec->user_mutex);
err = snd_hda_add_pincfg(codec, &codec->user_pins, nid, cfg);
mutex_unlock(&codec->user_mutex);
return err;
}
static ssize_t user_pin_configs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hda_codec *codec = dev_get_drvdata(dev);
int err = parse_user_pin_configs(codec, buf);
if (err < 0)
return err;
return count;
}
const char *snd_hda_get_hint(struct hda_codec *codec, const char *key)
{
struct hda_hint *hint = get_hint(codec, key);
return hint ? hint->val : NULL;
}
int snd_hda_get_bool_hint(struct hda_codec *codec, const char *key)
{
const char *p;
int ret;
mutex_lock(&codec->user_mutex);
p = snd_hda_get_hint(codec, key);
if (!p || !*p)
ret = -ENOENT;
else {
switch (toupper(*p)) {
case 'T':
case 'Y':
case '1':
ret = 1;
break;
default:
ret = 0;
break;
}
}
mutex_unlock(&codec->user_mutex);
return ret;
}
int snd_hda_get_int_hint(struct hda_codec *codec, const char *key, int *valp)
{
const char *p;
unsigned long val;
int ret;
mutex_lock(&codec->user_mutex);
p = snd_hda_get_hint(codec, key);
if (!p)
ret = -ENOENT;
else if (kstrtoul(p, 0, &val))
ret = -EINVAL;
else {
*valp = val;
ret = 0;
}
mutex_unlock(&codec->user_mutex);
return ret;
}
static inline int strmatch(const char *a, const char *b)
{
return strncasecmp(a, b, strlen(b)) == 0;
}
static void parse_codec_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
int vendorid, subid, caddr;
struct hda_codec *codec;
*codecp = NULL;
if (sscanf(buf, "%i %i %i", &vendorid, &subid, &caddr) == 3) {
list_for_each_codec(codec, bus) {
if ((vendorid <= 0 || codec->core.vendor_id == vendorid) &&
(subid <= 0 || codec->core.subsystem_id == subid) &&
codec->core.addr == caddr) {
*codecp = codec;
break;
}
}
}
}
static void parse_pincfg_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
parse_user_pin_configs(*codecp, buf);
}
static void parse_verb_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
parse_init_verbs(*codecp, buf);
}
static void parse_hint_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
parse_hints(*codecp, buf);
}
static void parse_model_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
kfree((*codecp)->modelname);
(*codecp)->modelname = kstrdup(buf, GFP_KERNEL);
}
static void parse_chip_name_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
snd_hda_codec_set_name(*codecp, buf);
}
static int parse_line_mode(char *buf, struct hda_bus *bus)
{
int i;
for (i = 0; i < ARRAY_SIZE(patch_items); i++) {
if (!patch_items[i].tag)
continue;
if (strmatch(buf, patch_items[i].tag))
return i;
if (patch_items[i].alias && strmatch(buf, patch_items[i].alias))
return i;
}
return LINE_MODE_NONE;
}
static int get_line_from_fw(char *buf, int size, size_t *fw_size_p,
const void **fw_data_p)
{
int len;
size_t fw_size = *fw_size_p;
const char *p = *fw_data_p;
while (isspace(*p) && fw_size) {
p++;
fw_size--;
}
if (!fw_size)
return 0;
for (len = 0; len < fw_size; len++) {
if (!*p)
break;
if (*p == '\n') {
p++;
len++;
break;
}
if (len < size)
*buf++ = *p++;
}
*buf = 0;
*fw_size_p = fw_size - len;
*fw_data_p = p;
remove_trail_spaces(buf);
return 1;
}
int snd_hda_load_patch(struct hda_bus *bus, size_t fw_size, const void *fw_buf)
{
char buf[128];
struct hda_codec *codec;
int line_mode;
line_mode = LINE_MODE_NONE;
codec = NULL;
while (get_line_from_fw(buf, sizeof(buf) - 1, &fw_size, &fw_buf)) {
if (!*buf || *buf == '#' || *buf == '\n')
continue;
if (*buf == '[')
line_mode = parse_line_mode(buf, bus);
else if (patch_items[line_mode].parser &&
(codec || line_mode <= LINE_MODE_CODEC))
patch_items[line_mode].parser(buf, bus, &codec);
}
return 0;
}
void snd_hda_sysfs_init(struct hda_codec *codec)
{
mutex_init(&codec->user_mutex);
#ifdef CONFIG_SND_HDA_RECONFIG
snd_array_init(&codec->init_verbs, sizeof(struct hda_verb), 32);
snd_array_init(&codec->hints, sizeof(struct hda_hint), 32);
snd_array_init(&codec->user_pins, sizeof(struct hda_pincfg), 16);
#endif
}
void snd_hda_sysfs_clear(struct hda_codec *codec)
{
#ifdef CONFIG_SND_HDA_RECONFIG
int i;
snd_array_free(&codec->init_verbs);
for (i = 0; i < codec->hints.used; i++) {
struct hda_hint *hint = snd_array_elem(&codec->hints, i);
kfree(hint->key);
}
snd_array_free(&codec->hints);
snd_array_free(&codec->user_pins);
#endif
}
