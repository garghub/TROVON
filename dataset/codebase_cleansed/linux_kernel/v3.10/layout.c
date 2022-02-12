static struct layout *find_layout_by_id(unsigned int id)
{
struct layout *l;
l = layouts;
while (l->codecs[0].name) {
if (l->layout_id == id)
return l;
l++;
}
return NULL;
}
static struct layout *find_layout_by_device(unsigned int id)
{
struct layout *l;
l = layouts;
while (l->codecs[0].name) {
if (l->device_id == id)
return l;
l++;
}
return NULL;
}
static void use_layout(struct layout *l)
{
int i;
for (i=0; i<MAX_CODECS_PER_BUS; i++) {
if (l->codecs[i].name) {
request_module("snd-aoa-codec-%s", l->codecs[i].name);
}
}
}
static int detect_choice_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct layout_dev *ldev = snd_kcontrol_chip(kcontrol);
switch (kcontrol->private_value) {
case 0:
ucontrol->value.integer.value[0] = ldev->switch_on_headphone;
break;
case 1:
ucontrol->value.integer.value[0] = ldev->switch_on_lineout;
break;
default:
return -ENODEV;
}
return 0;
}
static int detect_choice_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct layout_dev *ldev = snd_kcontrol_chip(kcontrol);
switch (kcontrol->private_value) {
case 0:
ldev->switch_on_headphone = !!ucontrol->value.integer.value[0];
break;
case 1:
ldev->switch_on_lineout = !!ucontrol->value.integer.value[0];
break;
default:
return -ENODEV;
}
return 1;
}
static int detected_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct layout_dev *ldev = snd_kcontrol_chip(kcontrol);
int v;
switch (kcontrol->private_value) {
case 0:
v = ldev->gpio.methods->get_detect(&ldev->gpio,
AOA_NOTIFY_HEADPHONE);
break;
case 1:
v = ldev->gpio.methods->get_detect(&ldev->gpio,
AOA_NOTIFY_LINE_OUT);
break;
default:
return -ENODEV;
}
ucontrol->value.integer.value[0] = v;
return 0;
}
static int check_codec(struct aoa_codec *codec,
struct layout_dev *ldev,
struct codec_connect_info *cci)
{
const u32 *ref;
char propname[32];
struct codec_connection *cc;
if (codec->node && (strcmp(codec->node->name, "codec") == 0)) {
snprintf(propname, sizeof(propname),
"platform-%s-codec-ref", codec->name);
ref = of_get_property(ldev->sound, propname, NULL);
if (!ref) {
printk(KERN_INFO "snd-aoa-fabric-layout: "
"required property %s not present\n", propname);
return -ENODEV;
}
if (*ref != codec->node->phandle) {
printk(KERN_INFO "snd-aoa-fabric-layout: "
"%s doesn't match!\n", propname);
return -ENODEV;
}
} else {
if (layouts_list_items != 1) {
printk(KERN_INFO "snd-aoa-fabric-layout: "
"more than one soundbus, but no references.\n");
return -ENODEV;
}
}
codec->soundbus_dev = ldev->sdev;
codec->gpio = &ldev->gpio;
cc = cci->connections;
if (!cc)
return -EINVAL;
printk(KERN_INFO "snd-aoa-fabric-layout: can use this codec\n");
codec->connected = 0;
codec->fabric_data = cc;
while (cc->connected) {
codec->connected |= 1<<cc->codec_bit;
cc++;
}
return 0;
}
static int layout_found_codec(struct aoa_codec *codec)
{
struct layout_dev *ldev;
int i;
list_for_each_entry(ldev, &layouts_list, list) {
for (i=0; i<MAX_CODECS_PER_BUS; i++) {
if (!ldev->layout->codecs[i].name)
continue;
if (strcmp(ldev->layout->codecs[i].name, codec->name) == 0) {
if (check_codec(codec,
ldev,
&ldev->layout->codecs[i]) == 0)
return 0;
}
}
}
return -ENODEV;
}
static void layout_remove_codec(struct aoa_codec *codec)
{
int i;
codec->soundbus_dev = NULL;
codec->gpio = NULL;
for (i=0; i<MAX_CODECS_PER_BUS; i++) {
}
}
static void layout_notify(void *data)
{
struct layout_dev_ptr *dptr = data;
struct layout_dev *ldev;
int v, update;
struct snd_kcontrol *detected, *c;
struct snd_card *card = aoa_get_card();
ldev = dptr->ptr;
if (data == &ldev->selfptr_headphone) {
v = ldev->gpio.methods->get_detect(&ldev->gpio, AOA_NOTIFY_HEADPHONE);
detected = ldev->headphone_detected_ctrl;
update = ldev->switch_on_headphone;
if (update) {
ldev->gpio.methods->set_speakers(&ldev->gpio, !v);
ldev->gpio.methods->set_headphone(&ldev->gpio, v);
ldev->gpio.methods->set_lineout(&ldev->gpio, 0);
}
} else if (data == &ldev->selfptr_lineout) {
v = ldev->gpio.methods->get_detect(&ldev->gpio, AOA_NOTIFY_LINE_OUT);
detected = ldev->lineout_detected_ctrl;
update = ldev->switch_on_lineout;
if (update) {
ldev->gpio.methods->set_speakers(&ldev->gpio, !v);
ldev->gpio.methods->set_headphone(&ldev->gpio, 0);
ldev->gpio.methods->set_lineout(&ldev->gpio, v);
}
} else
return;
if (detected)
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE, &detected->id);
if (update) {
c = ldev->headphone_ctrl;
if (c)
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE, &c->id);
c = ldev->speaker_ctrl;
if (c)
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE, &c->id);
c = ldev->lineout_ctrl;
if (c)
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE, &c->id);
}
}
static void layout_attached_codec(struct aoa_codec *codec)
{
struct codec_connection *cc;
struct snd_kcontrol *ctl;
int headphones, lineout;
struct layout_dev *ldev = layout_device;
cc = codec->fabric_data;
headphones = codec->gpio->methods->get_detect(codec->gpio,
AOA_NOTIFY_HEADPHONE);
lineout = codec->gpio->methods->get_detect(codec->gpio,
AOA_NOTIFY_LINE_OUT);
if (codec->gpio->methods->set_master) {
ctl = snd_ctl_new1(&master_ctl, codec->gpio);
ldev->master_ctrl = ctl;
aoa_snd_ctl_add(ctl);
}
while (cc->connected) {
if (cc->connected & CC_SPEAKERS) {
if (headphones <= 0 && lineout <= 0)
ldev->gpio.methods->set_speakers(codec->gpio, 1);
ctl = snd_ctl_new1(&speakers_ctl, codec->gpio);
ldev->speaker_ctrl = ctl;
aoa_snd_ctl_add(ctl);
}
if (cc->connected & CC_HEADPHONE) {
if (headphones == 1)
ldev->gpio.methods->set_headphone(codec->gpio, 1);
ctl = snd_ctl_new1(&headphone_ctl, codec->gpio);
ldev->headphone_ctrl = ctl;
aoa_snd_ctl_add(ctl);
ldev->have_headphone_detect =
!ldev->gpio.methods
->set_notify(&ldev->gpio,
AOA_NOTIFY_HEADPHONE,
layout_notify,
&ldev->selfptr_headphone);
if (ldev->have_headphone_detect) {
ctl = snd_ctl_new1(&headphone_detect_choice,
ldev);
aoa_snd_ctl_add(ctl);
ctl = snd_ctl_new1(&headphone_detected,
ldev);
ldev->headphone_detected_ctrl = ctl;
aoa_snd_ctl_add(ctl);
}
}
if (cc->connected & CC_LINEOUT) {
if (lineout == 1)
ldev->gpio.methods->set_lineout(codec->gpio, 1);
ctl = snd_ctl_new1(&lineout_ctl, codec->gpio);
if (cc->connected & CC_LINEOUT_LABELLED_HEADPHONE)
strlcpy(ctl->id.name,
"Headphone Switch", sizeof(ctl->id.name));
ldev->lineout_ctrl = ctl;
aoa_snd_ctl_add(ctl);
ldev->have_lineout_detect =
!ldev->gpio.methods
->set_notify(&ldev->gpio,
AOA_NOTIFY_LINE_OUT,
layout_notify,
&ldev->selfptr_lineout);
if (ldev->have_lineout_detect) {
ctl = snd_ctl_new1(&lineout_detect_choice,
ldev);
if (cc->connected & CC_LINEOUT_LABELLED_HEADPHONE)
strlcpy(ctl->id.name,
"Headphone Detect Autoswitch",
sizeof(ctl->id.name));
aoa_snd_ctl_add(ctl);
ctl = snd_ctl_new1(&lineout_detected,
ldev);
if (cc->connected & CC_LINEOUT_LABELLED_HEADPHONE)
strlcpy(ctl->id.name,
"Headphone Detected",
sizeof(ctl->id.name));
ldev->lineout_detected_ctrl = ctl;
aoa_snd_ctl_add(ctl);
}
}
cc++;
}
if (ldev->have_headphone_detect)
layout_notify(&ldev->selfptr_headphone);
if (ldev->have_lineout_detect)
layout_notify(&ldev->selfptr_lineout);
}
static int aoa_fabric_layout_probe(struct soundbus_dev *sdev)
{
struct device_node *sound = NULL;
const unsigned int *id;
struct layout *layout = NULL;
struct layout_dev *ldev = NULL;
int err;
if (layout_device)
return -ENODEV;
while ((sound = of_get_next_child(sdev->ofdev.dev.of_node, sound))) {
if (sound->type && strcasecmp(sound->type, "soundchip") == 0)
break;
}
if (!sound)
return -ENODEV;
id = of_get_property(sound, "layout-id", NULL);
if (id) {
layout = find_layout_by_id(*id);
} else {
id = of_get_property(sound, "device-id", NULL);
if (id)
layout = find_layout_by_device(*id);
}
if (!layout) {
printk(KERN_ERR "snd-aoa-fabric-layout: unknown layout\n");
goto outnodev;
}
ldev = kzalloc(sizeof(struct layout_dev), GFP_KERNEL);
if (!ldev)
goto outnodev;
layout_device = ldev;
ldev->sdev = sdev;
ldev->sound = sound;
ldev->layout = layout;
ldev->gpio.node = sound->parent;
switch (layout->layout_id) {
case 0:
case 41:
case 51:
case 58:
ldev->gpio.methods = ftr_gpio_methods;
printk(KERN_DEBUG
"snd-aoa-fabric-layout: Using direct GPIOs\n");
break;
default:
ldev->gpio.methods = pmf_gpio_methods;
printk(KERN_DEBUG
"snd-aoa-fabric-layout: Using PMF GPIOs\n");
}
ldev->selfptr_headphone.ptr = ldev;
ldev->selfptr_lineout.ptr = ldev;
dev_set_drvdata(&sdev->ofdev.dev, ldev);
list_add(&ldev->list, &layouts_list);
layouts_list_items++;
sdev->pcmid = ldev->layout->pcmid;
if (ldev->layout->busname) {
sdev->pcmname = ldev->layout->busname;
} else {
sdev->pcmname = "Master";
}
ldev->gpio.methods->init(&ldev->gpio);
err = aoa_fabric_register(&layout_fabric, &sdev->ofdev.dev);
if (err && err != -EALREADY) {
printk(KERN_INFO "snd-aoa-fabric-layout: can't use,"
" another fabric is active!\n");
goto outlistdel;
}
use_layout(layout);
ldev->switch_on_headphone = 1;
ldev->switch_on_lineout = 1;
return 0;
outlistdel:
ldev->gpio.methods->exit(&ldev->gpio);
sdev->pcmname = NULL;
sdev->pcmid = -1;
list_del(&ldev->list);
layouts_list_items--;
kfree(ldev);
outnodev:
of_node_put(sound);
layout_device = NULL;
return -ENODEV;
}
static int aoa_fabric_layout_remove(struct soundbus_dev *sdev)
{
struct layout_dev *ldev = dev_get_drvdata(&sdev->ofdev.dev);
int i;
for (i=0; i<MAX_CODECS_PER_BUS; i++) {
if (ldev->codecs[i]) {
aoa_fabric_unlink_codec(ldev->codecs[i]);
}
ldev->codecs[i] = NULL;
}
list_del(&ldev->list);
layouts_list_items--;
of_node_put(ldev->sound);
ldev->gpio.methods->set_notify(&ldev->gpio,
AOA_NOTIFY_HEADPHONE,
NULL,
NULL);
ldev->gpio.methods->set_notify(&ldev->gpio,
AOA_NOTIFY_LINE_OUT,
NULL,
NULL);
ldev->gpio.methods->exit(&ldev->gpio);
layout_device = NULL;
kfree(ldev);
sdev->pcmid = -1;
sdev->pcmname = NULL;
return 0;
}
static int aoa_fabric_layout_suspend(struct soundbus_dev *sdev, pm_message_t state)
{
struct layout_dev *ldev = dev_get_drvdata(&sdev->ofdev.dev);
if (ldev->gpio.methods && ldev->gpio.methods->all_amps_off)
ldev->gpio.methods->all_amps_off(&ldev->gpio);
return 0;
}
static int aoa_fabric_layout_resume(struct soundbus_dev *sdev)
{
struct layout_dev *ldev = dev_get_drvdata(&sdev->ofdev.dev);
if (ldev->gpio.methods && ldev->gpio.methods->all_amps_off)
ldev->gpio.methods->all_amps_restore(&ldev->gpio);
return 0;
}
static int __init aoa_fabric_layout_init(void)
{
int err;
err = soundbus_register_driver(&aoa_soundbus_driver);
if (err)
return err;
return 0;
}
static void __exit aoa_fabric_layout_exit(void)
{
soundbus_unregister_driver(&aoa_soundbus_driver);
aoa_fabric_unregister(&layout_fabric);
}
