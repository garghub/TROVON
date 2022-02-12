static int get_codec_nid(struct kobject *kobj, struct hdac_device **codecp)
{
struct device *dev = kobj_to_dev(kobj->parent->parent);
int nid;
ssize_t ret;
ret = kstrtoint(kobj->name, 16, &nid);
if (ret < 0)
return ret;
*codecp = dev_to_hdac_dev(dev);
return nid;
}
static ssize_t widget_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct widget_attribute *wid_attr =
container_of(attr, struct widget_attribute, attr);
struct hdac_device *codec;
int nid;
if (!wid_attr->show)
return -EIO;
nid = get_codec_nid(kobj, &codec);
if (nid < 0)
return nid;
return wid_attr->show(codec, nid, wid_attr, buf);
}
static ssize_t widget_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct widget_attribute *wid_attr =
container_of(attr, struct widget_attribute, attr);
struct hdac_device *codec;
int nid;
if (!wid_attr->store)
return -EIO;
nid = get_codec_nid(kobj, &codec);
if (nid < 0)
return nid;
return wid_attr->store(codec, nid, wid_attr, buf, count);
}
static void widget_release(struct kobject *kobj)
{
kfree(kobj);
}
static ssize_t caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
return sprintf(buf, "0x%08x\n", get_wcaps(codec, nid));
}
static ssize_t pin_caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
return 0;
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_PIN_CAP));
}
static ssize_t pin_cfg_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
unsigned int val;
if (get_wcaps_type(get_wcaps(codec, nid)) != AC_WID_PIN)
return 0;
if (snd_hdac_read(codec, nid, AC_VERB_GET_CONFIG_DEFAULT, 0, &val))
return 0;
return sprintf(buf, "0x%08x\n", val);
}
static bool has_pcm_cap(struct hdac_device *codec, hda_nid_t nid)
{
if (nid == codec->afg || nid == codec->mfg)
return true;
switch (get_wcaps_type(get_wcaps(codec, nid))) {
case AC_WID_AUD_OUT:
case AC_WID_AUD_IN:
return true;
default:
return false;
}
}
static ssize_t pcm_caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
if (!has_pcm_cap(codec, nid))
return 0;
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_PCM));
}
static ssize_t pcm_formats_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
if (!has_pcm_cap(codec, nid))
return 0;
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_STREAM));
}
static ssize_t amp_in_caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
if (nid != codec->afg && !(get_wcaps(codec, nid) & AC_WCAP_IN_AMP))
return 0;
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_AMP_IN_CAP));
}
static ssize_t amp_out_caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
if (nid != codec->afg && !(get_wcaps(codec, nid) & AC_WCAP_OUT_AMP))
return 0;
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_AMP_OUT_CAP));
}
static ssize_t power_caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
if (nid != codec->afg && !(get_wcaps(codec, nid) & AC_WCAP_POWER))
return 0;
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_POWER_STATE));
}
static ssize_t gpio_caps_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
return sprintf(buf, "0x%08x\n",
snd_hdac_read_parm(codec, nid, AC_PAR_GPIO_CAP));
}
static ssize_t connections_show(struct hdac_device *codec, hda_nid_t nid,
struct widget_attribute *attr, char *buf)
{
hda_nid_t list[32];
int i, nconns;
ssize_t ret = 0;
nconns = snd_hdac_get_connections(codec, nid, list, ARRAY_SIZE(list));
if (nconns <= 0)
return nconns;
for (i = 0; i < nconns; i++)
ret += sprintf(buf + ret, "%s0x%02x", i ? " " : "", list[i]);
ret += sprintf(buf + ret, "\n");
return ret;
}
static void free_widget_node(struct kobject *kobj,
const struct attribute_group *group)
{
if (kobj) {
sysfs_remove_group(kobj, group);
kobject_put(kobj);
}
}
static void widget_tree_free(struct hdac_device *codec)
{
struct hdac_widget_tree *tree = codec->widgets;
struct kobject **p;
if (!tree)
return;
free_widget_node(tree->afg, &widget_afg_group);
if (tree->nodes) {
for (p = tree->nodes; *p; p++)
free_widget_node(*p, &widget_node_group);
kfree(tree->nodes);
}
if (tree->root)
kobject_put(tree->root);
kfree(tree);
codec->widgets = NULL;
}
static int add_widget_node(struct kobject *parent, hda_nid_t nid,
const struct attribute_group *group,
struct kobject **res)
{
struct kobject *kobj = kzalloc(sizeof(*kobj), GFP_KERNEL);
int err;
if (!kobj)
return -ENOMEM;
kobject_init(kobj, &widget_ktype);
err = kobject_add(kobj, parent, "%02x", nid);
if (err < 0)
return err;
err = sysfs_create_group(kobj, group);
if (err < 0) {
kobject_put(kobj);
return err;
}
*res = kobj;
return 0;
}
static int widget_tree_create(struct hdac_device *codec)
{
struct hdac_widget_tree *tree;
int i, err;
hda_nid_t nid;
tree = codec->widgets = kzalloc(sizeof(*tree), GFP_KERNEL);
if (!tree)
return -ENOMEM;
tree->root = kobject_create_and_add("widgets", &codec->dev.kobj);
if (!tree->root)
return -ENOMEM;
tree->nodes = kcalloc(codec->num_nodes + 1, sizeof(*tree->nodes),
GFP_KERNEL);
if (!tree->nodes)
return -ENOMEM;
for (i = 0, nid = codec->start_nid; i < codec->num_nodes; i++, nid++) {
err = add_widget_node(tree->root, nid, &widget_node_group,
&tree->nodes[i]);
if (err < 0)
return err;
}
if (codec->afg) {
err = add_widget_node(tree->root, codec->afg,
&widget_afg_group, &tree->afg);
if (err < 0)
return err;
}
kobject_uevent(tree->root, KOBJ_CHANGE);
return 0;
}
int hda_widget_sysfs_init(struct hdac_device *codec)
{
int err;
err = widget_tree_create(codec);
if (err < 0) {
widget_tree_free(codec);
return err;
}
return 0;
}
void hda_widget_sysfs_exit(struct hdac_device *codec)
{
widget_tree_free(codec);
}
