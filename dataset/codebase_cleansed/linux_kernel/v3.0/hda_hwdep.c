static int verb_write_ioctl(struct hda_codec *codec,
struct hda_verb_ioctl __user *arg)
{
u32 verb, res;
if (get_user(verb, &arg->verb))
return -EFAULT;
res = snd_hda_codec_read(codec, verb >> 24, 0,
(verb >> 8) & 0xffff, verb & 0xff);
if (put_user(res, &arg->res))
return -EFAULT;
return 0;
}
static int get_wcap_ioctl(struct hda_codec *codec,
struct hda_verb_ioctl __user *arg)
{
u32 verb, res;
if (get_user(verb, &arg->verb))
return -EFAULT;
res = get_wcaps(codec, verb >> 24);
if (put_user(res, &arg->res))
return -EFAULT;
return 0;
}
static int hda_hwdep_ioctl(struct snd_hwdep *hw, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct hda_codec *codec = hw->private_data;
void __user *argp = (void __user *)arg;
switch (cmd) {
case HDA_IOCTL_PVERSION:
return put_user(HDA_HWDEP_VERSION, (int __user *)argp);
case HDA_IOCTL_VERB_WRITE:
return verb_write_ioctl(codec, argp);
case HDA_IOCTL_GET_WCAP:
return get_wcap_ioctl(codec, argp);
}
return -ENOIOCTLCMD;
}
static int hda_hwdep_ioctl_compat(struct snd_hwdep *hw, struct file *file,
unsigned int cmd, unsigned long arg)
{
return hda_hwdep_ioctl(hw, file, cmd, (unsigned long)compat_ptr(arg));
}
static int hda_hwdep_open(struct snd_hwdep *hw, struct file *file)
{
#ifndef CONFIG_SND_DEBUG_VERBOSE
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
#endif
return 0;
}
static void clear_hwdep_elements(struct hda_codec *codec)
{
int i;
snd_array_free(&codec->init_verbs);
for (i = 0; i < codec->hints.used; i++) {
struct hda_hint *hint = snd_array_elem(&codec->hints, i);
kfree(hint->key);
}
snd_array_free(&codec->hints);
snd_array_free(&codec->user_pins);
}
static void hwdep_free(struct snd_hwdep *hwdep)
{
clear_hwdep_elements(hwdep->private_data);
}
int snd_hda_create_hwdep(struct hda_codec *codec)
{
char hwname[16];
struct snd_hwdep *hwdep;
int err;
sprintf(hwname, "HDA Codec %d", codec->addr);
err = snd_hwdep_new(codec->bus->card, hwname, codec->addr, &hwdep);
if (err < 0)
return err;
codec->hwdep = hwdep;
sprintf(hwdep->name, "HDA Codec %d", codec->addr);
hwdep->iface = SNDRV_HWDEP_IFACE_HDA;
hwdep->private_data = codec;
hwdep->private_free = hwdep_free;
hwdep->exclusive = 1;
hwdep->ops.open = hda_hwdep_open;
hwdep->ops.ioctl = hda_hwdep_ioctl;
#ifdef CONFIG_COMPAT
hwdep->ops.ioctl_compat = hda_hwdep_ioctl_compat;
#endif
snd_array_init(&codec->init_verbs, sizeof(struct hda_verb), 32);
snd_array_init(&codec->hints, sizeof(struct hda_hint), 32);
snd_array_init(&codec->user_pins, sizeof(struct hda_pincfg), 16);
return 0;
}
static ssize_t power_on_acct_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
snd_hda_update_power_acct(codec);
return sprintf(buf, "%u\n", jiffies_to_msecs(codec->power_on_acct));
}
static ssize_t power_off_acct_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
snd_hda_update_power_acct(codec);
return sprintf(buf, "%u\n", jiffies_to_msecs(codec->power_off_acct));
}
int snd_hda_hwdep_add_power_sysfs(struct hda_codec *codec)
{
struct snd_hwdep *hwdep = codec->hwdep;
int i;
for (i = 0; i < ARRAY_SIZE(power_attrs); i++)
snd_add_device_sysfs_file(SNDRV_DEVICE_TYPE_HWDEP, hwdep->card,
hwdep->device, &power_attrs[i]);
return 0;
}
static int clear_codec(struct hda_codec *codec)
{
int err;
err = snd_hda_codec_reset(codec);
if (err < 0) {
snd_printk(KERN_ERR "The codec is being used, can't free.\n");
return err;
}
clear_hwdep_elements(codec);
return 0;
}
static int reconfig_codec(struct hda_codec *codec)
{
int err;
snd_hda_power_up(codec);
snd_printk(KERN_INFO "hda-codec: reconfiguring\n");
err = snd_hda_codec_reset(codec);
if (err < 0) {
snd_printk(KERN_ERR
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
err = snd_card_register(codec->bus->card);
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
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
int i, len = 0;
for (i = 0; i < codec->init_verbs.used; i++) {
struct hda_verb *v = snd_array_elem(&codec->init_verbs, i);
len += snprintf(buf + len, PAGE_SIZE - len,
"0x%02x 0x%03x 0x%04x\n",
v->nid, v->verb, v->param);
}
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
v = snd_array_new(&codec->init_verbs);
if (!v)
return -ENOMEM;
v->nid = nid;
v->verb = verb;
v->param = param;
return 0;
}
static ssize_t init_verbs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
int err = parse_init_verbs(codec, buf);
if (err < 0)
return err;
return count;
}
static ssize_t hints_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
int i, len = 0;
for (i = 0; i < codec->hints.used; i++) {
struct hda_hint *hint = snd_array_elem(&codec->hints, i);
len += snprintf(buf + len, PAGE_SIZE - len,
"%s = %s\n", hint->key, hint->val);
}
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
hint = get_hint(codec, key);
if (hint) {
kfree(hint->key);
hint->key = key;
hint->val = val;
return 0;
}
if (codec->hints.used >= MAX_HINTS)
hint = NULL;
else
hint = snd_array_new(&codec->hints);
if (!hint) {
kfree(key);
return -ENOMEM;
}
hint->key = key;
hint->val = val;
return 0;
}
static ssize_t hints_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
int err = parse_hints(codec, buf);
if (err < 0)
return err;
return count;
}
static ssize_t pin_configs_show(struct hda_codec *codec,
struct snd_array *list,
char *buf)
{
int i, len = 0;
for (i = 0; i < list->used; i++) {
struct hda_pincfg *pin = snd_array_elem(list, i);
len += sprintf(buf + len, "0x%02x 0x%08x\n",
pin->nid, pin->cfg);
}
return len;
}
static ssize_t init_pin_configs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
return pin_configs_show(codec, &codec->init_pins, buf);
}
static ssize_t user_pin_configs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
return pin_configs_show(codec, &codec->user_pins, buf);
}
static ssize_t driver_pin_configs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
return pin_configs_show(codec, &codec->driver_pins, buf);
}
static int parse_user_pin_configs(struct hda_codec *codec, const char *buf)
{
int nid, cfg;
if (sscanf(buf, "%i %i", &nid, &cfg) != 2)
return -EINVAL;
if (!nid)
return -EINVAL;
return snd_hda_add_pincfg(codec, &codec->user_pins, nid, cfg);
}
static ssize_t user_pin_configs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct snd_hwdep *hwdep = dev_get_drvdata(dev);
struct hda_codec *codec = hwdep->private_data;
int err = parse_user_pin_configs(codec, buf);
if (err < 0)
return err;
return count;
}
int snd_hda_hwdep_add_sysfs(struct hda_codec *codec)
{
struct snd_hwdep *hwdep = codec->hwdep;
int i;
for (i = 0; i < ARRAY_SIZE(codec_attrs); i++)
snd_add_device_sysfs_file(SNDRV_DEVICE_TYPE_HWDEP, hwdep->card,
hwdep->device, &codec_attrs[i]);
return 0;
}
const char *snd_hda_get_hint(struct hda_codec *codec, const char *key)
{
struct hda_hint *hint = get_hint(codec, key);
return hint ? hint->val : NULL;
}
int snd_hda_get_bool_hint(struct hda_codec *codec, const char *key)
{
const char *p = snd_hda_get_hint(codec, key);
if (!p || !*p)
return -ENOENT;
switch (toupper(*p)) {
case 'T':
case 'Y':
case '1':
return 1;
}
return 0;
}
static inline int strmatch(const char *a, const char *b)
{
return strnicmp(a, b, strlen(b)) == 0;
}
static void parse_codec_mode(char *buf, struct hda_bus *bus,
struct hda_codec **codecp)
{
unsigned int vendorid, subid, caddr;
struct hda_codec *codec;
*codecp = NULL;
if (sscanf(buf, "%i %i %i", &vendorid, &subid, &caddr) == 3) {
list_for_each_entry(codec, &bus->codec_list, list) {
if (codec->vendor_id == vendorid &&
codec->subsystem_id == subid &&
codec->addr == caddr) {
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
kfree((*codecp)->chip_name);
(*codecp)->chip_name = kstrdup(buf, GFP_KERNEL);
}
static int parse_line_mode(char *buf, struct hda_bus *bus)
{
int i;
for (i = 0; i < ARRAY_SIZE(patch_items); i++) {
if (!patch_items[i].tag)
continue;
if (strmatch(buf, patch_items[i].tag))
return i;
}
return LINE_MODE_NONE;
}
static int get_line_from_fw(char *buf, int size, struct firmware *fw)
{
int len;
const char *p = fw->data;
while (isspace(*p) && fw->size) {
p++;
fw->size--;
}
if (!fw->size)
return 0;
if (size < fw->size)
size = fw->size;
for (len = 0; len < fw->size; len++) {
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
fw->size -= len;
fw->data = p;
remove_trail_spaces(buf);
return 1;
}
int snd_hda_load_patch(struct hda_bus *bus, const char *patch)
{
int err;
const struct firmware *fw;
struct firmware tmp;
char buf[128];
struct hda_codec *codec;
int line_mode;
struct device *dev = bus->card->dev;
if (snd_BUG_ON(!dev))
return -ENODEV;
err = request_firmware(&fw, patch, dev);
if (err < 0) {
printk(KERN_ERR "hda-codec: Cannot load the patch '%s'\n",
patch);
return err;
}
tmp = *fw;
line_mode = LINE_MODE_NONE;
codec = NULL;
while (get_line_from_fw(buf, sizeof(buf) - 1, &tmp)) {
if (!*buf || *buf == '#' || *buf == '\n')
continue;
if (*buf == '[')
line_mode = parse_line_mode(buf, bus);
else if (patch_items[line_mode].parser &&
(codec || !patch_items[line_mode].need_codec))
patch_items[line_mode].parser(buf, bus, &codec);
}
release_firmware(fw);
return 0;
}
