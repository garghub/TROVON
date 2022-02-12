static void pop_wait(u32 pop_time)
{
if (pop_time)
schedule_timeout_uninterruptible(msecs_to_jiffies(pop_time));
}
static void pop_dbg(struct device *dev, u32 pop_time, const char *fmt, ...)
{
va_list args;
char *buf;
if (!pop_time)
return;
buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (buf == NULL)
return;
va_start(args, fmt);
vsnprintf(buf, PAGE_SIZE, fmt, args);
dev_info(dev, "%s", buf);
va_end(args);
kfree(buf);
}
static bool dapm_dirty_widget(struct snd_soc_dapm_widget *w)
{
return !list_empty(&w->dirty);
}
void dapm_mark_dirty(struct snd_soc_dapm_widget *w, const char *reason)
{
if (!dapm_dirty_widget(w)) {
dev_vdbg(w->dapm->dev, "Marking %s dirty due to %s\n",
w->name, reason);
list_add_tail(&w->dirty, &w->dapm->card->dapm_dirty);
}
}
void dapm_mark_io_dirty(struct snd_soc_dapm_context *dapm)
{
struct snd_soc_card *card = dapm->card;
struct snd_soc_dapm_widget *w;
mutex_lock(&card->dapm_mutex);
list_for_each_entry(w, &card->widgets, list) {
switch (w->id) {
case snd_soc_dapm_input:
case snd_soc_dapm_output:
dapm_mark_dirty(w, "Rechecking inputs and outputs");
break;
default:
break;
}
}
mutex_unlock(&card->dapm_mutex);
}
static inline struct snd_soc_dapm_widget *dapm_cnew_widget(
const struct snd_soc_dapm_widget *_widget)
{
return kmemdup(_widget, sizeof(*_widget), GFP_KERNEL);
}
static inline struct snd_card *dapm_get_snd_card(
struct snd_soc_dapm_context *dapm)
{
if (dapm->codec)
return dapm->codec->card->snd_card;
else if (dapm->platform)
return dapm->platform->card->snd_card;
else
BUG();
return NULL;
}
static inline struct snd_soc_card *dapm_get_soc_card(
struct snd_soc_dapm_context *dapm)
{
if (dapm->codec)
return dapm->codec->card;
else if (dapm->platform)
return dapm->platform->card;
else
BUG();
return NULL;
}
static void dapm_reset(struct snd_soc_card *card)
{
struct snd_soc_dapm_widget *w;
memset(&card->dapm_stats, 0, sizeof(card->dapm_stats));
list_for_each_entry(w, &card->widgets, list) {
w->power_checked = false;
w->inputs = -1;
w->outputs = -1;
}
}
static int soc_widget_read(struct snd_soc_dapm_widget *w, int reg)
{
if (w->codec)
return snd_soc_read(w->codec, reg);
else if (w->platform)
return snd_soc_platform_read(w->platform, reg);
dev_err(w->dapm->dev, "ASoC: no valid widget read method\n");
return -1;
}
static int soc_widget_write(struct snd_soc_dapm_widget *w, int reg, int val)
{
if (w->codec)
return snd_soc_write(w->codec, reg, val);
else if (w->platform)
return snd_soc_platform_write(w->platform, reg, val);
dev_err(w->dapm->dev, "ASoC: no valid widget write method\n");
return -1;
}
static inline void soc_widget_lock(struct snd_soc_dapm_widget *w)
{
if (w->codec && !w->codec->using_regmap)
mutex_lock(&w->codec->mutex);
else if (w->platform)
mutex_lock(&w->platform->mutex);
}
static inline void soc_widget_unlock(struct snd_soc_dapm_widget *w)
{
if (w->codec && !w->codec->using_regmap)
mutex_unlock(&w->codec->mutex);
else if (w->platform)
mutex_unlock(&w->platform->mutex);
}
static int soc_widget_update_bits_locked(struct snd_soc_dapm_widget *w,
unsigned short reg, unsigned int mask, unsigned int value)
{
bool change;
unsigned int old, new;
int ret;
if (w->codec && w->codec->using_regmap) {
ret = regmap_update_bits_check(w->codec->control_data,
reg, mask, value, &change);
if (ret != 0)
return ret;
} else {
soc_widget_lock(w);
ret = soc_widget_read(w, reg);
if (ret < 0) {
soc_widget_unlock(w);
return ret;
}
old = ret;
new = (old & ~mask) | (value & mask);
change = old != new;
if (change) {
ret = soc_widget_write(w, reg, new);
if (ret < 0) {
soc_widget_unlock(w);
return ret;
}
}
soc_widget_unlock(w);
}
return change;
}
static int snd_soc_dapm_set_bias_level(struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_card *card = dapm->card;
int ret = 0;
trace_snd_soc_bias_level_start(card, level);
if (card && card->set_bias_level)
ret = card->set_bias_level(card, dapm, level);
if (ret != 0)
goto out;
if (dapm->codec) {
if (dapm->codec->driver->set_bias_level)
ret = dapm->codec->driver->set_bias_level(dapm->codec,
level);
else
dapm->bias_level = level;
} else if (!card || dapm != &card->dapm) {
dapm->bias_level = level;
}
if (ret != 0)
goto out;
if (card && card->set_bias_level_post)
ret = card->set_bias_level_post(card, dapm, level);
out:
trace_snd_soc_bias_level_done(card, level);
return ret;
}
static void dapm_set_path_status(struct snd_soc_dapm_widget *w,
struct snd_soc_dapm_path *p, int i)
{
switch (w->id) {
case snd_soc_dapm_switch:
case snd_soc_dapm_mixer:
case snd_soc_dapm_mixer_named_ctl: {
int val;
struct soc_mixer_control *mc = (struct soc_mixer_control *)
w->kcontrol_news[i].private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
val = soc_widget_read(w, reg);
val = (val >> shift) & mask;
if (invert)
val = max - val;
p->connect = !!val;
}
break;
case snd_soc_dapm_mux: {
struct soc_enum *e = (struct soc_enum *)
w->kcontrol_news[i].private_value;
int val, item;
val = soc_widget_read(w, e->reg);
item = (val >> e->shift_l) & e->mask;
p->connect = 0;
for (i = 0; i < e->max; i++) {
if (!(strcmp(p->name, e->texts[i])) && item == i)
p->connect = 1;
}
}
break;
case snd_soc_dapm_virt_mux: {
struct soc_enum *e = (struct soc_enum *)
w->kcontrol_news[i].private_value;
p->connect = 0;
if (!strcmp(p->name, e->texts[0]))
p->connect = 1;
}
break;
case snd_soc_dapm_value_mux: {
struct soc_enum *e = (struct soc_enum *)
w->kcontrol_news[i].private_value;
int val, item;
val = soc_widget_read(w, e->reg);
val = (val >> e->shift_l) & e->mask;
for (item = 0; item < e->max; item++) {
if (val == e->values[item])
break;
}
p->connect = 0;
for (i = 0; i < e->max; i++) {
if (!(strcmp(p->name, e->texts[i])) && item == i)
p->connect = 1;
}
}
break;
case snd_soc_dapm_pga:
case snd_soc_dapm_out_drv:
case snd_soc_dapm_output:
case snd_soc_dapm_adc:
case snd_soc_dapm_input:
case snd_soc_dapm_siggen:
case snd_soc_dapm_dac:
case snd_soc_dapm_micbias:
case snd_soc_dapm_vmid:
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
case snd_soc_dapm_aif_in:
case snd_soc_dapm_aif_out:
case snd_soc_dapm_dai_in:
case snd_soc_dapm_dai_out:
case snd_soc_dapm_hp:
case snd_soc_dapm_mic:
case snd_soc_dapm_spk:
case snd_soc_dapm_line:
case snd_soc_dapm_dai_link:
p->connect = 1;
break;
case snd_soc_dapm_pre:
case snd_soc_dapm_post:
p->connect = 0;
break;
}
}
static int dapm_connect_mux(struct snd_soc_dapm_context *dapm,
struct snd_soc_dapm_widget *src, struct snd_soc_dapm_widget *dest,
struct snd_soc_dapm_path *path, const char *control_name,
const struct snd_kcontrol_new *kcontrol)
{
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
int i;
for (i = 0; i < e->max; i++) {
if (!(strcmp(control_name, e->texts[i]))) {
list_add(&path->list, &dapm->card->paths);
list_add(&path->list_sink, &dest->sources);
list_add(&path->list_source, &src->sinks);
path->name = (char*)e->texts[i];
dapm_set_path_status(dest, path, 0);
return 0;
}
}
return -ENODEV;
}
static int dapm_connect_mixer(struct snd_soc_dapm_context *dapm,
struct snd_soc_dapm_widget *src, struct snd_soc_dapm_widget *dest,
struct snd_soc_dapm_path *path, const char *control_name)
{
int i;
for (i = 0; i < dest->num_kcontrols; i++) {
if (!strcmp(control_name, dest->kcontrol_news[i].name)) {
list_add(&path->list, &dapm->card->paths);
list_add(&path->list_sink, &dest->sources);
list_add(&path->list_source, &src->sinks);
path->name = dest->kcontrol_news[i].name;
dapm_set_path_status(dest, path, i);
return 0;
}
}
return -ENODEV;
}
static int dapm_is_shared_kcontrol(struct snd_soc_dapm_context *dapm,
struct snd_soc_dapm_widget *kcontrolw,
const struct snd_kcontrol_new *kcontrol_new,
struct snd_kcontrol **kcontrol)
{
struct snd_soc_dapm_widget *w;
int i;
*kcontrol = NULL;
list_for_each_entry(w, &dapm->card->widgets, list) {
if (w == kcontrolw || w->dapm != kcontrolw->dapm)
continue;
for (i = 0; i < w->num_kcontrols; i++) {
if (&w->kcontrol_news[i] == kcontrol_new) {
if (w->kcontrols)
*kcontrol = w->kcontrols[i];
return 1;
}
}
}
return 0;
}
static int dapm_create_or_share_mixmux_kcontrol(struct snd_soc_dapm_widget *w,
int kci, struct snd_soc_dapm_path *path)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_card *card = dapm->card->snd_card;
const char *prefix;
size_t prefix_len;
int shared;
struct snd_kcontrol *kcontrol;
struct snd_soc_dapm_widget_list *wlist;
int wlistentries;
size_t wlistsize;
bool wname_in_long_name, kcname_in_long_name;
size_t name_len;
char *long_name;
const char *name;
int ret;
if (dapm->codec)
prefix = dapm->codec->name_prefix;
else
prefix = NULL;
if (prefix)
prefix_len = strlen(prefix) + 1;
else
prefix_len = 0;
shared = dapm_is_shared_kcontrol(dapm, w, &w->kcontrol_news[kci],
&kcontrol);
if (kcontrol) {
wlist = kcontrol->private_data;
wlistentries = wlist->num_widgets + 1;
} else {
wlist = NULL;
wlistentries = 1;
}
wlistsize = sizeof(struct snd_soc_dapm_widget_list) +
wlistentries * sizeof(struct snd_soc_dapm_widget *);
wlist = krealloc(wlist, wlistsize, GFP_KERNEL);
if (wlist == NULL) {
dev_err(dapm->dev, "ASoC: can't allocate widget list for %s\n",
w->name);
return -ENOMEM;
}
wlist->num_widgets = wlistentries;
wlist->widgets[wlistentries - 1] = w;
if (!kcontrol) {
if (shared) {
wname_in_long_name = false;
kcname_in_long_name = true;
} else {
switch (w->id) {
case snd_soc_dapm_switch:
case snd_soc_dapm_mixer:
wname_in_long_name = true;
kcname_in_long_name = true;
break;
case snd_soc_dapm_mixer_named_ctl:
wname_in_long_name = false;
kcname_in_long_name = true;
break;
case snd_soc_dapm_mux:
case snd_soc_dapm_virt_mux:
case snd_soc_dapm_value_mux:
wname_in_long_name = true;
kcname_in_long_name = false;
break;
default:
kfree(wlist);
return -EINVAL;
}
}
if (wname_in_long_name && kcname_in_long_name) {
name_len = strlen(w->name) - prefix_len + 1 +
strlen(w->kcontrol_news[kci].name) + 1;
long_name = kmalloc(name_len, GFP_KERNEL);
if (long_name == NULL) {
kfree(wlist);
return -ENOMEM;
}
snprintf(long_name, name_len, "%s %s",
w->name + prefix_len,
w->kcontrol_news[kci].name);
long_name[name_len - 1] = '\0';
name = long_name;
} else if (wname_in_long_name) {
long_name = NULL;
name = w->name + prefix_len;
} else {
long_name = NULL;
name = w->kcontrol_news[kci].name;
}
kcontrol = snd_soc_cnew(&w->kcontrol_news[kci], wlist, name,
prefix);
ret = snd_ctl_add(card, kcontrol);
if (ret < 0) {
dev_err(dapm->dev,
"ASoC: failed to add widget %s dapm kcontrol %s: %d\n",
w->name, name, ret);
kfree(wlist);
kfree(long_name);
return ret;
}
path->long_name = long_name;
}
kcontrol->private_data = wlist;
w->kcontrols[kci] = kcontrol;
path->kcontrol = kcontrol;
return 0;
}
static int dapm_new_mixer(struct snd_soc_dapm_widget *w)
{
int i, ret;
struct snd_soc_dapm_path *path;
for (i = 0; i < w->num_kcontrols; i++) {
list_for_each_entry(path, &w->sources, list_sink) {
if (path->name != (char *)w->kcontrol_news[i].name)
continue;
if (w->kcontrols[i]) {
path->kcontrol = w->kcontrols[i];
continue;
}
ret = dapm_create_or_share_mixmux_kcontrol(w, i, path);
if (ret < 0)
return ret;
}
}
return 0;
}
static int dapm_new_mux(struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_dapm_path *path;
int ret;
if (w->num_kcontrols != 1) {
dev_err(dapm->dev,
"ASoC: mux %s has incorrect number of controls\n",
w->name);
return -EINVAL;
}
path = list_first_entry(&w->sources, struct snd_soc_dapm_path,
list_sink);
if (!path) {
dev_err(dapm->dev, "ASoC: mux %s has no paths\n", w->name);
return -EINVAL;
}
ret = dapm_create_or_share_mixmux_kcontrol(w, 0, path);
if (ret < 0)
return ret;
list_for_each_entry(path, &w->sources, list_sink)
path->kcontrol = w->kcontrols[0];
return 0;
}
static int dapm_new_pga(struct snd_soc_dapm_widget *w)
{
if (w->num_kcontrols)
dev_err(w->dapm->dev,
"ASoC: PGA controls not supported: '%s'\n", w->name);
return 0;
}
static void dapm_clear_walk_output(struct snd_soc_dapm_context *dapm,
struct list_head *sink)
{
struct snd_soc_dapm_path *p;
list_for_each_entry(p, sink, list_source) {
if (p->walked) {
p->walked = 0;
dapm_clear_walk_output(dapm, &p->sink->sinks);
}
}
}
static void dapm_clear_walk_input(struct snd_soc_dapm_context *dapm,
struct list_head *source)
{
struct snd_soc_dapm_path *p;
list_for_each_entry(p, source, list_sink) {
if (p->walked) {
p->walked = 0;
dapm_clear_walk_input(dapm, &p->source->sources);
}
}
}
static int snd_soc_dapm_suspend_check(struct snd_soc_dapm_widget *widget)
{
int level = snd_power_get_state(widget->dapm->card->snd_card);
switch (level) {
case SNDRV_CTL_POWER_D3hot:
case SNDRV_CTL_POWER_D3cold:
if (widget->ignore_suspend)
dev_dbg(widget->dapm->dev, "ASoC: %s ignoring suspend\n",
widget->name);
return widget->ignore_suspend;
default:
return 1;
}
}
static int dapm_list_add_widget(struct snd_soc_dapm_widget_list **list,
struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_widget_list *wlist;
int wlistsize, wlistentries, i;
if (*list == NULL)
return -EINVAL;
wlist = *list;
for (i = 0; i < wlist->num_widgets; i++) {
if (wlist->widgets[i] == w)
return 0;
}
wlistentries = wlist->num_widgets + 1;
wlistsize = sizeof(struct snd_soc_dapm_widget_list) +
wlistentries * sizeof(struct snd_soc_dapm_widget *);
*list = krealloc(wlist, wlistsize, GFP_KERNEL);
if (*list == NULL) {
dev_err(w->dapm->dev, "ASoC: can't allocate widget list for %s\n",
w->name);
return -ENOMEM;
}
wlist = *list;
dev_dbg(w->dapm->dev, "ASoC: added %s in widget list pos %d\n",
w->name, wlist->num_widgets);
wlist->widgets[wlist->num_widgets] = w;
wlist->num_widgets++;
return 1;
}
static int is_connected_output_ep(struct snd_soc_dapm_widget *widget,
struct snd_soc_dapm_widget_list **list)
{
struct snd_soc_dapm_path *path;
int con = 0;
if (widget->outputs >= 0)
return widget->outputs;
DAPM_UPDATE_STAT(widget, path_checks);
switch (widget->id) {
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
return 0;
default:
break;
}
switch (widget->id) {
case snd_soc_dapm_adc:
case snd_soc_dapm_aif_out:
case snd_soc_dapm_dai_out:
if (widget->active) {
widget->outputs = snd_soc_dapm_suspend_check(widget);
return widget->outputs;
}
default:
break;
}
if (widget->connected) {
if (widget->id == snd_soc_dapm_output && !widget->ext) {
widget->outputs = snd_soc_dapm_suspend_check(widget);
return widget->outputs;
}
if (widget->id == snd_soc_dapm_hp ||
widget->id == snd_soc_dapm_spk ||
(widget->id == snd_soc_dapm_line &&
!list_empty(&widget->sources))) {
widget->outputs = snd_soc_dapm_suspend_check(widget);
return widget->outputs;
}
}
list_for_each_entry(path, &widget->sinks, list_source) {
DAPM_UPDATE_STAT(widget, neighbour_checks);
if (path->weak)
continue;
if (path->walking)
return 1;
if (path->walked)
continue;
trace_snd_soc_dapm_output_path(widget, path);
if (path->sink && path->connect) {
path->walked = 1;
path->walking = 1;
if (list) {
int err;
err = dapm_list_add_widget(list, path->sink);
if (err < 0) {
dev_err(widget->dapm->dev,
"ASoC: could not add widget %s\n",
widget->name);
path->walking = 0;
return con;
}
}
con += is_connected_output_ep(path->sink, list);
path->walking = 0;
}
}
widget->outputs = con;
return con;
}
static int is_connected_input_ep(struct snd_soc_dapm_widget *widget,
struct snd_soc_dapm_widget_list **list)
{
struct snd_soc_dapm_path *path;
int con = 0;
if (widget->inputs >= 0)
return widget->inputs;
DAPM_UPDATE_STAT(widget, path_checks);
switch (widget->id) {
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
return 0;
default:
break;
}
switch (widget->id) {
case snd_soc_dapm_dac:
case snd_soc_dapm_aif_in:
case snd_soc_dapm_dai_in:
if (widget->active) {
widget->inputs = snd_soc_dapm_suspend_check(widget);
return widget->inputs;
}
default:
break;
}
if (widget->connected) {
if (widget->id == snd_soc_dapm_input && !widget->ext) {
widget->inputs = snd_soc_dapm_suspend_check(widget);
return widget->inputs;
}
if (widget->id == snd_soc_dapm_vmid) {
widget->inputs = snd_soc_dapm_suspend_check(widget);
return widget->inputs;
}
if (widget->id == snd_soc_dapm_mic ||
(widget->id == snd_soc_dapm_line &&
!list_empty(&widget->sinks))) {
widget->inputs = snd_soc_dapm_suspend_check(widget);
return widget->inputs;
}
if (widget->id == snd_soc_dapm_siggen) {
widget->inputs = snd_soc_dapm_suspend_check(widget);
return widget->inputs;
}
}
list_for_each_entry(path, &widget->sources, list_sink) {
DAPM_UPDATE_STAT(widget, neighbour_checks);
if (path->weak)
continue;
if (path->walking)
return 1;
if (path->walked)
continue;
trace_snd_soc_dapm_input_path(widget, path);
if (path->source && path->connect) {
path->walked = 1;
path->walking = 1;
if (list) {
int err;
err = dapm_list_add_widget(list, path->source);
if (err < 0) {
dev_err(widget->dapm->dev,
"ASoC: could not add widget %s\n",
widget->name);
path->walking = 0;
return con;
}
}
con += is_connected_input_ep(path->source, list);
path->walking = 0;
}
}
widget->inputs = con;
return con;
}
int snd_soc_dapm_dai_get_connected_widgets(struct snd_soc_dai *dai, int stream,
struct snd_soc_dapm_widget_list **list)
{
struct snd_soc_card *card = dai->card;
int paths;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
dapm_reset(card);
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
paths = is_connected_output_ep(dai->playback_widget, list);
dapm_clear_walk_output(&card->dapm,
&dai->playback_widget->sinks);
} else {
paths = is_connected_input_ep(dai->capture_widget, list);
dapm_clear_walk_input(&card->dapm,
&dai->capture_widget->sources);
}
trace_snd_soc_dapm_connected(paths, stream);
mutex_unlock(&card->dapm_mutex);
return paths;
}
int dapm_reg_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
unsigned int val;
if (SND_SOC_DAPM_EVENT_ON(event))
val = w->on_val;
else
val = w->off_val;
soc_widget_update_bits_locked(w, -(w->reg + 1),
w->mask << w->shift, val << w->shift);
return 0;
}
int dapm_regulator_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
int ret;
if (SND_SOC_DAPM_EVENT_ON(event)) {
if (w->invert & SND_SOC_DAPM_REGULATOR_BYPASS) {
ret = regulator_allow_bypass(w->regulator, false);
if (ret != 0)
dev_warn(w->dapm->dev,
"ASoC: Failed to bypass %s: %d\n",
w->name, ret);
}
return regulator_enable(w->regulator);
} else {
if (w->invert & SND_SOC_DAPM_REGULATOR_BYPASS) {
ret = regulator_allow_bypass(w->regulator, true);
if (ret != 0)
dev_warn(w->dapm->dev,
"ASoC: Failed to unbypass %s: %d\n",
w->name, ret);
}
return regulator_disable_deferred(w->regulator, w->shift);
}
}
int dapm_clock_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
if (!w->clk)
return -EIO;
#ifdef CONFIG_HAVE_CLK
if (SND_SOC_DAPM_EVENT_ON(event)) {
return clk_prepare_enable(w->clk);
} else {
clk_disable_unprepare(w->clk);
return 0;
}
#endif
return 0;
}
static int dapm_widget_power_check(struct snd_soc_dapm_widget *w)
{
if (w->power_checked)
return w->new_power;
if (w->force)
w->new_power = 1;
else
w->new_power = w->power_check(w);
w->power_checked = true;
return w->new_power;
}
static int dapm_generic_check_power(struct snd_soc_dapm_widget *w)
{
int in, out;
DAPM_UPDATE_STAT(w, power_checks);
in = is_connected_input_ep(w, NULL);
dapm_clear_walk_input(w->dapm, &w->sources);
out = is_connected_output_ep(w, NULL);
dapm_clear_walk_output(w->dapm, &w->sinks);
return out != 0 && in != 0;
}
static int dapm_adc_check_power(struct snd_soc_dapm_widget *w)
{
int in;
DAPM_UPDATE_STAT(w, power_checks);
if (w->active) {
in = is_connected_input_ep(w, NULL);
dapm_clear_walk_input(w->dapm, &w->sources);
return in != 0;
} else {
return dapm_generic_check_power(w);
}
}
static int dapm_dac_check_power(struct snd_soc_dapm_widget *w)
{
int out;
DAPM_UPDATE_STAT(w, power_checks);
if (w->active) {
out = is_connected_output_ep(w, NULL);
dapm_clear_walk_output(w->dapm, &w->sinks);
return out != 0;
} else {
return dapm_generic_check_power(w);
}
}
static int dapm_supply_check_power(struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_path *path;
DAPM_UPDATE_STAT(w, power_checks);
list_for_each_entry(path, &w->sinks, list_source) {
DAPM_UPDATE_STAT(w, neighbour_checks);
if (path->weak)
continue;
if (path->connected &&
!path->connected(path->source, path->sink))
continue;
if (!path->sink)
continue;
if (dapm_widget_power_check(path->sink))
return 1;
}
return 0;
}
static int dapm_always_on_check_power(struct snd_soc_dapm_widget *w)
{
return 1;
}
static int dapm_seq_compare(struct snd_soc_dapm_widget *a,
struct snd_soc_dapm_widget *b,
bool power_up)
{
int *sort;
if (power_up)
sort = dapm_up_seq;
else
sort = dapm_down_seq;
if (sort[a->id] != sort[b->id])
return sort[a->id] - sort[b->id];
if (a->subseq != b->subseq) {
if (power_up)
return a->subseq - b->subseq;
else
return b->subseq - a->subseq;
}
if (a->reg != b->reg)
return a->reg - b->reg;
if (a->dapm != b->dapm)
return (unsigned long)a->dapm - (unsigned long)b->dapm;
return 0;
}
static void dapm_seq_insert(struct snd_soc_dapm_widget *new_widget,
struct list_head *list,
bool power_up)
{
struct snd_soc_dapm_widget *w;
list_for_each_entry(w, list, power_list)
if (dapm_seq_compare(new_widget, w, power_up) < 0) {
list_add_tail(&new_widget->power_list, &w->power_list);
return;
}
list_add_tail(&new_widget->power_list, list);
}
static void dapm_seq_check_event(struct snd_soc_dapm_context *dapm,
struct snd_soc_dapm_widget *w, int event)
{
struct snd_soc_card *card = dapm->card;
const char *ev_name;
int power, ret;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
ev_name = "PRE_PMU";
power = 1;
break;
case SND_SOC_DAPM_POST_PMU:
ev_name = "POST_PMU";
power = 1;
break;
case SND_SOC_DAPM_PRE_PMD:
ev_name = "PRE_PMD";
power = 0;
break;
case SND_SOC_DAPM_POST_PMD:
ev_name = "POST_PMD";
power = 0;
break;
default:
BUG();
return;
}
if (w->power != power)
return;
if (w->event && (w->event_flags & event)) {
pop_dbg(dapm->dev, card->pop_time, "pop test : %s %s\n",
w->name, ev_name);
trace_snd_soc_dapm_widget_event_start(w, event);
ret = w->event(w, NULL, event);
trace_snd_soc_dapm_widget_event_done(w, event);
if (ret < 0)
dev_err(dapm->dev, "ASoC: %s: %s event failed: %d\n",
ev_name, w->name, ret);
}
}
static void dapm_seq_run_coalesced(struct snd_soc_dapm_context *dapm,
struct list_head *pending)
{
struct snd_soc_card *card = dapm->card;
struct snd_soc_dapm_widget *w;
int reg, power;
unsigned int value = 0;
unsigned int mask = 0;
unsigned int cur_mask;
reg = list_first_entry(pending, struct snd_soc_dapm_widget,
power_list)->reg;
list_for_each_entry(w, pending, power_list) {
cur_mask = 1 << w->shift;
BUG_ON(reg != w->reg);
if (w->invert)
power = !w->power;
else
power = w->power;
mask |= cur_mask;
if (power)
value |= cur_mask;
pop_dbg(dapm->dev, card->pop_time,
"pop test : Queue %s: reg=0x%x, 0x%x/0x%x\n",
w->name, reg, value, mask);
dapm_seq_check_event(dapm, w, SND_SOC_DAPM_PRE_PMU);
dapm_seq_check_event(dapm, w, SND_SOC_DAPM_PRE_PMD);
}
if (reg >= 0) {
w = list_first_entry(pending, struct snd_soc_dapm_widget,
power_list);
pop_dbg(dapm->dev, card->pop_time,
"pop test : Applying 0x%x/0x%x to %x in %dms\n",
value, mask, reg, card->pop_time);
pop_wait(card->pop_time);
soc_widget_update_bits_locked(w, reg, mask, value);
}
list_for_each_entry(w, pending, power_list) {
dapm_seq_check_event(dapm, w, SND_SOC_DAPM_POST_PMU);
dapm_seq_check_event(dapm, w, SND_SOC_DAPM_POST_PMD);
}
}
static void dapm_seq_run(struct snd_soc_dapm_context *dapm,
struct list_head *list, int event, bool power_up)
{
struct snd_soc_dapm_widget *w, *n;
LIST_HEAD(pending);
int cur_sort = -1;
int cur_subseq = -1;
int cur_reg = SND_SOC_NOPM;
struct snd_soc_dapm_context *cur_dapm = NULL;
int ret, i;
int *sort;
if (power_up)
sort = dapm_up_seq;
else
sort = dapm_down_seq;
list_for_each_entry_safe(w, n, list, power_list) {
ret = 0;
if (sort[w->id] != cur_sort || w->reg != cur_reg ||
w->dapm != cur_dapm || w->subseq != cur_subseq) {
if (!list_empty(&pending))
dapm_seq_run_coalesced(cur_dapm, &pending);
if (cur_dapm && cur_dapm->seq_notifier) {
for (i = 0; i < ARRAY_SIZE(dapm_up_seq); i++)
if (sort[i] == cur_sort)
cur_dapm->seq_notifier(cur_dapm,
i,
cur_subseq);
}
INIT_LIST_HEAD(&pending);
cur_sort = -1;
cur_subseq = INT_MIN;
cur_reg = SND_SOC_NOPM;
cur_dapm = NULL;
}
switch (w->id) {
case snd_soc_dapm_pre:
if (!w->event)
list_for_each_entry_safe_continue(w, n, list,
power_list);
if (event == SND_SOC_DAPM_STREAM_START)
ret = w->event(w,
NULL, SND_SOC_DAPM_PRE_PMU);
else if (event == SND_SOC_DAPM_STREAM_STOP)
ret = w->event(w,
NULL, SND_SOC_DAPM_PRE_PMD);
break;
case snd_soc_dapm_post:
if (!w->event)
list_for_each_entry_safe_continue(w, n, list,
power_list);
if (event == SND_SOC_DAPM_STREAM_START)
ret = w->event(w,
NULL, SND_SOC_DAPM_POST_PMU);
else if (event == SND_SOC_DAPM_STREAM_STOP)
ret = w->event(w,
NULL, SND_SOC_DAPM_POST_PMD);
break;
default:
cur_sort = sort[w->id];
cur_subseq = w->subseq;
cur_reg = w->reg;
cur_dapm = w->dapm;
list_move(&w->power_list, &pending);
break;
}
if (ret < 0)
dev_err(w->dapm->dev,
"ASoC: Failed to apply widget power: %d\n", ret);
}
if (!list_empty(&pending))
dapm_seq_run_coalesced(cur_dapm, &pending);
if (cur_dapm && cur_dapm->seq_notifier) {
for (i = 0; i < ARRAY_SIZE(dapm_up_seq); i++)
if (sort[i] == cur_sort)
cur_dapm->seq_notifier(cur_dapm,
i, cur_subseq);
}
}
static void dapm_widget_update(struct snd_soc_dapm_context *dapm)
{
struct snd_soc_dapm_update *update = dapm->update;
struct snd_soc_dapm_widget *w;
int ret;
if (!update)
return;
w = update->widget;
if (w->event &&
(w->event_flags & SND_SOC_DAPM_PRE_REG)) {
ret = w->event(w, update->kcontrol, SND_SOC_DAPM_PRE_REG);
if (ret != 0)
dev_err(dapm->dev, "ASoC: %s DAPM pre-event failed: %d\n",
w->name, ret);
}
ret = soc_widget_update_bits_locked(w, update->reg, update->mask,
update->val);
if (ret < 0)
dev_err(dapm->dev, "ASoC: %s DAPM update failed: %d\n",
w->name, ret);
if (w->event &&
(w->event_flags & SND_SOC_DAPM_POST_REG)) {
ret = w->event(w, update->kcontrol, SND_SOC_DAPM_POST_REG);
if (ret != 0)
dev_err(dapm->dev, "ASoC: %s DAPM post-event failed: %d\n",
w->name, ret);
}
}
static void dapm_pre_sequence_async(void *data, async_cookie_t cookie)
{
struct snd_soc_dapm_context *d = data;
int ret;
if (d->bias_level == SND_SOC_BIAS_OFF &&
d->target_bias_level != SND_SOC_BIAS_OFF) {
if (d->dev)
pm_runtime_get_sync(d->dev);
ret = snd_soc_dapm_set_bias_level(d, SND_SOC_BIAS_STANDBY);
if (ret != 0)
dev_err(d->dev,
"ASoC: Failed to turn on bias: %d\n", ret);
}
if (d->bias_level != d->target_bias_level) {
ret = snd_soc_dapm_set_bias_level(d, SND_SOC_BIAS_PREPARE);
if (ret != 0)
dev_err(d->dev,
"ASoC: Failed to prepare bias: %d\n", ret);
}
}
static void dapm_post_sequence_async(void *data, async_cookie_t cookie)
{
struct snd_soc_dapm_context *d = data;
int ret;
if (d->bias_level == SND_SOC_BIAS_PREPARE &&
(d->target_bias_level == SND_SOC_BIAS_STANDBY ||
d->target_bias_level == SND_SOC_BIAS_OFF)) {
ret = snd_soc_dapm_set_bias_level(d, SND_SOC_BIAS_STANDBY);
if (ret != 0)
dev_err(d->dev, "ASoC: Failed to apply standby bias: %d\n",
ret);
}
if (d->bias_level == SND_SOC_BIAS_STANDBY &&
d->target_bias_level == SND_SOC_BIAS_OFF) {
ret = snd_soc_dapm_set_bias_level(d, SND_SOC_BIAS_OFF);
if (ret != 0)
dev_err(d->dev, "ASoC: Failed to turn off bias: %d\n",
ret);
if (d->dev)
pm_runtime_put(d->dev);
}
if (d->bias_level == SND_SOC_BIAS_PREPARE &&
d->target_bias_level == SND_SOC_BIAS_ON) {
ret = snd_soc_dapm_set_bias_level(d, SND_SOC_BIAS_ON);
if (ret != 0)
dev_err(d->dev, "ASoC: Failed to apply active bias: %d\n",
ret);
}
}
static void dapm_widget_set_peer_power(struct snd_soc_dapm_widget *peer,
bool power, bool connect)
{
if (!connect)
return;
if (power != peer->power)
dapm_mark_dirty(peer, "peer state change");
}
static void dapm_widget_set_power(struct snd_soc_dapm_widget *w, bool power,
struct list_head *up_list,
struct list_head *down_list)
{
struct snd_soc_dapm_path *path;
if (w->power == power)
return;
trace_snd_soc_dapm_widget_power(w, power);
list_for_each_entry(path, &w->sources, list_sink) {
if (path->source) {
dapm_widget_set_peer_power(path->source, power,
path->connect);
}
}
switch (w->id) {
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
break;
default:
list_for_each_entry(path, &w->sinks, list_source) {
if (path->sink) {
dapm_widget_set_peer_power(path->sink, power,
path->connect);
}
}
break;
}
if (power)
dapm_seq_insert(w, up_list, true);
else
dapm_seq_insert(w, down_list, false);
w->power = power;
}
static void dapm_power_one_widget(struct snd_soc_dapm_widget *w,
struct list_head *up_list,
struct list_head *down_list)
{
int power;
switch (w->id) {
case snd_soc_dapm_pre:
dapm_seq_insert(w, down_list, false);
break;
case snd_soc_dapm_post:
dapm_seq_insert(w, up_list, true);
break;
default:
power = dapm_widget_power_check(w);
dapm_widget_set_power(w, power, up_list, down_list);
break;
}
}
static int dapm_power_widgets(struct snd_soc_dapm_context *dapm, int event)
{
struct snd_soc_card *card = dapm->card;
struct snd_soc_dapm_widget *w;
struct snd_soc_dapm_context *d;
LIST_HEAD(up_list);
LIST_HEAD(down_list);
ASYNC_DOMAIN_EXCLUSIVE(async_domain);
enum snd_soc_bias_level bias;
trace_snd_soc_dapm_start(card);
list_for_each_entry(d, &card->dapm_list, list) {
if (d->idle_bias_off)
d->target_bias_level = SND_SOC_BIAS_OFF;
else
d->target_bias_level = SND_SOC_BIAS_STANDBY;
}
dapm_reset(card);
list_for_each_entry(w, &card->dapm_dirty, dirty) {
dapm_power_one_widget(w, &up_list, &down_list);
}
list_for_each_entry(w, &card->widgets, list) {
switch (w->id) {
case snd_soc_dapm_pre:
case snd_soc_dapm_post:
break;
default:
list_del_init(&w->dirty);
break;
}
if (w->power) {
d = w->dapm;
switch (w->id) {
case snd_soc_dapm_siggen:
break;
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
case snd_soc_dapm_micbias:
if (d->target_bias_level < SND_SOC_BIAS_STANDBY)
d->target_bias_level = SND_SOC_BIAS_STANDBY;
break;
default:
d->target_bias_level = SND_SOC_BIAS_ON;
break;
}
}
}
bias = SND_SOC_BIAS_OFF;
list_for_each_entry(d, &card->dapm_list, list)
if (d->target_bias_level > bias)
bias = d->target_bias_level;
list_for_each_entry(d, &card->dapm_list, list)
if (!d->idle_bias_off)
d->target_bias_level = bias;
trace_snd_soc_dapm_walk_done(card);
list_for_each_entry(d, &dapm->card->dapm_list, list)
async_schedule_domain(dapm_pre_sequence_async, d,
&async_domain);
async_synchronize_full_domain(&async_domain);
dapm_seq_run(dapm, &down_list, event, false);
dapm_widget_update(dapm);
dapm_seq_run(dapm, &up_list, event, true);
list_for_each_entry(d, &dapm->card->dapm_list, list)
async_schedule_domain(dapm_post_sequence_async, d,
&async_domain);
async_synchronize_full_domain(&async_domain);
list_for_each_entry(d, &card->dapm_list, list) {
if (d->stream_event)
d->stream_event(d, event);
}
pop_dbg(dapm->dev, card->pop_time,
"DAPM sequencing finished, waiting %dms\n", card->pop_time);
pop_wait(card->pop_time);
trace_snd_soc_dapm_done(card);
return 0;
}
static ssize_t dapm_widget_power_read_file(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
struct snd_soc_dapm_widget *w = file->private_data;
char *buf;
int in, out;
ssize_t ret;
struct snd_soc_dapm_path *p = NULL;
buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
in = is_connected_input_ep(w, NULL);
dapm_clear_walk_input(w->dapm, &w->sources);
out = is_connected_output_ep(w, NULL);
dapm_clear_walk_output(w->dapm, &w->sinks);
ret = snprintf(buf, PAGE_SIZE, "%s: %s%s in %d out %d",
w->name, w->power ? "On" : "Off",
w->force ? " (forced)" : "", in, out);
if (w->reg >= 0)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
" - R%d(0x%x) bit %d",
w->reg, w->reg, w->shift);
ret += snprintf(buf + ret, PAGE_SIZE - ret, "\n");
if (w->sname)
ret += snprintf(buf + ret, PAGE_SIZE - ret, " stream %s %s\n",
w->sname,
w->active ? "active" : "inactive");
list_for_each_entry(p, &w->sources, list_sink) {
if (p->connected && !p->connected(w, p->sink))
continue;
if (p->connect)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
" in \"%s\" \"%s\"\n",
p->name ? p->name : "static",
p->source->name);
}
list_for_each_entry(p, &w->sinks, list_source) {
if (p->connected && !p->connected(w, p->sink))
continue;
if (p->connect)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
" out \"%s\" \"%s\"\n",
p->name ? p->name : "static",
p->sink->name);
}
ret = simple_read_from_buffer(user_buf, count, ppos, buf, ret);
kfree(buf);
return ret;
}
static ssize_t dapm_bias_read_file(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct snd_soc_dapm_context *dapm = file->private_data;
char *level;
switch (dapm->bias_level) {
case SND_SOC_BIAS_ON:
level = "On\n";
break;
case SND_SOC_BIAS_PREPARE:
level = "Prepare\n";
break;
case SND_SOC_BIAS_STANDBY:
level = "Standby\n";
break;
case SND_SOC_BIAS_OFF:
level = "Off\n";
break;
default:
BUG();
level = "Unknown\n";
break;
}
return simple_read_from_buffer(user_buf, count, ppos, level,
strlen(level));
}
void snd_soc_dapm_debugfs_init(struct snd_soc_dapm_context *dapm,
struct dentry *parent)
{
struct dentry *d;
dapm->debugfs_dapm = debugfs_create_dir("dapm", parent);
if (!dapm->debugfs_dapm) {
dev_warn(dapm->dev,
"ASoC: Failed to create DAPM debugfs directory\n");
return;
}
d = debugfs_create_file("bias_level", 0444,
dapm->debugfs_dapm, dapm,
&dapm_bias_fops);
if (!d)
dev_warn(dapm->dev,
"ASoC: Failed to create bias level debugfs file\n");
}
static void dapm_debugfs_add_widget(struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct dentry *d;
if (!dapm->debugfs_dapm || !w->name)
return;
d = debugfs_create_file(w->name, 0444,
dapm->debugfs_dapm, w,
&dapm_widget_power_fops);
if (!d)
dev_warn(w->dapm->dev,
"ASoC: Failed to create %s debugfs file\n",
w->name);
}
static void dapm_debugfs_cleanup(struct snd_soc_dapm_context *dapm)
{
debugfs_remove_recursive(dapm->debugfs_dapm);
}
void snd_soc_dapm_debugfs_init(struct snd_soc_dapm_context *dapm,
struct dentry *parent)
{
}
static inline void dapm_debugfs_add_widget(struct snd_soc_dapm_widget *w)
{
}
static inline void dapm_debugfs_cleanup(struct snd_soc_dapm_context *dapm)
{
}
static int soc_dapm_mux_update_power(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *kcontrol, int mux, struct soc_enum *e)
{
struct snd_soc_dapm_path *path;
int found = 0;
if (widget->id != snd_soc_dapm_mux &&
widget->id != snd_soc_dapm_virt_mux &&
widget->id != snd_soc_dapm_value_mux)
return -ENODEV;
list_for_each_entry(path, &widget->dapm->card->paths, list) {
if (path->kcontrol != kcontrol)
continue;
if (!path->name || !e->texts[mux])
continue;
found = 1;
if (!(strcmp(path->name, e->texts[mux]))) {
path->connect = 1;
dapm_mark_dirty(path->source, "mux connection");
} else {
if (path->connect)
dapm_mark_dirty(path->source,
"mux disconnection");
path->connect = 0;
}
}
if (found) {
dapm_mark_dirty(widget, "mux change");
dapm_power_widgets(widget->dapm, SND_SOC_DAPM_STREAM_NOP);
}
return found;
}
int snd_soc_dapm_mux_update_power(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *kcontrol, int mux, struct soc_enum *e)
{
struct snd_soc_card *card = widget->dapm->card;
int ret;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
ret = soc_dapm_mux_update_power(widget, kcontrol, mux, e);
mutex_unlock(&card->dapm_mutex);
if (ret > 0)
soc_dpcm_runtime_update(widget);
return ret;
}
static int soc_dapm_mixer_update_power(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *kcontrol, int connect)
{
struct snd_soc_dapm_path *path;
int found = 0;
if (widget->id != snd_soc_dapm_mixer &&
widget->id != snd_soc_dapm_mixer_named_ctl &&
widget->id != snd_soc_dapm_switch)
return -ENODEV;
list_for_each_entry(path, &widget->dapm->card->paths, list) {
if (path->kcontrol != kcontrol)
continue;
found = 1;
path->connect = connect;
dapm_mark_dirty(path->source, "mixer connection");
}
if (found) {
dapm_mark_dirty(widget, "mixer update");
dapm_power_widgets(widget->dapm, SND_SOC_DAPM_STREAM_NOP);
}
return found;
}
int snd_soc_dapm_mixer_update_power(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *kcontrol, int connect)
{
struct snd_soc_card *card = widget->dapm->card;
int ret;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
ret = soc_dapm_mixer_update_power(widget, kcontrol, connect);
mutex_unlock(&card->dapm_mutex);
if (ret > 0)
soc_dpcm_runtime_update(widget);
return ret;
}
static ssize_t dapm_widget_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct snd_soc_pcm_runtime *rtd = dev_get_drvdata(dev);
struct snd_soc_codec *codec =rtd->codec;
struct snd_soc_dapm_widget *w;
int count = 0;
char *state = "not set";
list_for_each_entry(w, &codec->card->widgets, list) {
if (w->dapm != &codec->dapm)
continue;
switch (w->id) {
case snd_soc_dapm_hp:
case snd_soc_dapm_mic:
case snd_soc_dapm_spk:
case snd_soc_dapm_line:
case snd_soc_dapm_micbias:
case snd_soc_dapm_dac:
case snd_soc_dapm_adc:
case snd_soc_dapm_pga:
case snd_soc_dapm_out_drv:
case snd_soc_dapm_mixer:
case snd_soc_dapm_mixer_named_ctl:
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
if (w->name)
count += sprintf(buf + count, "%s: %s\n",
w->name, w->power ? "On":"Off");
break;
default:
break;
}
}
switch (codec->dapm.bias_level) {
case SND_SOC_BIAS_ON:
state = "On";
break;
case SND_SOC_BIAS_PREPARE:
state = "Prepare";
break;
case SND_SOC_BIAS_STANDBY:
state = "Standby";
break;
case SND_SOC_BIAS_OFF:
state = "Off";
break;
}
count += sprintf(buf + count, "PM State: %s\n", state);
return count;
}
int snd_soc_dapm_sys_add(struct device *dev)
{
return device_create_file(dev, &dev_attr_dapm_widget);
}
static void snd_soc_dapm_sys_remove(struct device *dev)
{
device_remove_file(dev, &dev_attr_dapm_widget);
}
static void dapm_free_widgets(struct snd_soc_dapm_context *dapm)
{
struct snd_soc_dapm_widget *w, *next_w;
struct snd_soc_dapm_path *p, *next_p;
list_for_each_entry_safe(w, next_w, &dapm->card->widgets, list) {
if (w->dapm != dapm)
continue;
list_del(&w->list);
list_for_each_entry_safe(p, next_p, &w->sources, list_sink) {
list_del(&p->list_sink);
list_del(&p->list_source);
list_del(&p->list);
kfree(p->long_name);
kfree(p);
}
list_for_each_entry_safe(p, next_p, &w->sinks, list_source) {
list_del(&p->list_sink);
list_del(&p->list_source);
list_del(&p->list);
kfree(p->long_name);
kfree(p);
}
kfree(w->kcontrols);
kfree(w->name);
kfree(w);
}
}
static struct snd_soc_dapm_widget *dapm_find_widget(
struct snd_soc_dapm_context *dapm, const char *pin,
bool search_other_contexts)
{
struct snd_soc_dapm_widget *w;
struct snd_soc_dapm_widget *fallback = NULL;
list_for_each_entry(w, &dapm->card->widgets, list) {
if (!strcmp(w->name, pin)) {
if (w->dapm == dapm)
return w;
else
fallback = w;
}
}
if (search_other_contexts)
return fallback;
return NULL;
}
static int snd_soc_dapm_set_pin(struct snd_soc_dapm_context *dapm,
const char *pin, int status)
{
struct snd_soc_dapm_widget *w = dapm_find_widget(dapm, pin, true);
if (!w) {
dev_err(dapm->dev, "ASoC: DAPM unknown pin %s\n", pin);
return -EINVAL;
}
if (w->connected != status)
dapm_mark_dirty(w, "pin configuration");
w->connected = status;
if (status == 0)
w->force = 0;
return 0;
}
int snd_soc_dapm_sync(struct snd_soc_dapm_context *dapm)
{
int ret;
if (!dapm->card || !dapm->card->instantiated)
return 0;
mutex_lock_nested(&dapm->card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
ret = dapm_power_widgets(dapm, SND_SOC_DAPM_STREAM_NOP);
mutex_unlock(&dapm->card->dapm_mutex);
return ret;
}
static int snd_soc_dapm_add_route(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_route *route)
{
struct snd_soc_dapm_path *path;
struct snd_soc_dapm_widget *wsource = NULL, *wsink = NULL, *w;
struct snd_soc_dapm_widget *wtsource = NULL, *wtsink = NULL;
const char *sink;
const char *control = route->control;
const char *source;
char prefixed_sink[80];
char prefixed_source[80];
int ret = 0;
if (dapm->codec && dapm->codec->name_prefix) {
snprintf(prefixed_sink, sizeof(prefixed_sink), "%s %s",
dapm->codec->name_prefix, route->sink);
sink = prefixed_sink;
snprintf(prefixed_source, sizeof(prefixed_source), "%s %s",
dapm->codec->name_prefix, route->source);
source = prefixed_source;
} else {
sink = route->sink;
source = route->source;
}
list_for_each_entry(w, &dapm->card->widgets, list) {
if (!wsink && !(strcmp(w->name, sink))) {
wtsink = w;
if (w->dapm == dapm)
wsink = w;
continue;
}
if (!wsource && !(strcmp(w->name, source))) {
wtsource = w;
if (w->dapm == dapm)
wsource = w;
}
}
if (!wsink)
wsink = wtsink;
if (!wsource)
wsource = wtsource;
if (wsource == NULL) {
dev_err(dapm->dev, "ASoC: no source widget found for %s\n",
route->source);
return -ENODEV;
}
if (wsink == NULL) {
dev_err(dapm->dev, "ASoC: no sink widget found for %s\n",
route->sink);
return -ENODEV;
}
path = kzalloc(sizeof(struct snd_soc_dapm_path), GFP_KERNEL);
if (!path)
return -ENOMEM;
path->source = wsource;
path->sink = wsink;
path->connected = route->connected;
INIT_LIST_HEAD(&path->list);
INIT_LIST_HEAD(&path->list_source);
INIT_LIST_HEAD(&path->list_sink);
if (wsink->id == snd_soc_dapm_input) {
if (wsource->id == snd_soc_dapm_micbias ||
wsource->id == snd_soc_dapm_mic ||
wsource->id == snd_soc_dapm_line ||
wsource->id == snd_soc_dapm_output)
wsink->ext = 1;
}
if (wsource->id == snd_soc_dapm_output) {
if (wsink->id == snd_soc_dapm_spk ||
wsink->id == snd_soc_dapm_hp ||
wsink->id == snd_soc_dapm_line ||
wsink->id == snd_soc_dapm_input)
wsource->ext = 1;
}
if (control == NULL) {
list_add(&path->list, &dapm->card->paths);
list_add(&path->list_sink, &wsink->sources);
list_add(&path->list_source, &wsource->sinks);
path->connect = 1;
return 0;
}
switch (wsink->id) {
case snd_soc_dapm_adc:
case snd_soc_dapm_dac:
case snd_soc_dapm_pga:
case snd_soc_dapm_out_drv:
case snd_soc_dapm_input:
case snd_soc_dapm_output:
case snd_soc_dapm_siggen:
case snd_soc_dapm_micbias:
case snd_soc_dapm_vmid:
case snd_soc_dapm_pre:
case snd_soc_dapm_post:
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
case snd_soc_dapm_aif_in:
case snd_soc_dapm_aif_out:
case snd_soc_dapm_dai_in:
case snd_soc_dapm_dai_out:
case snd_soc_dapm_dai_link:
list_add(&path->list, &dapm->card->paths);
list_add(&path->list_sink, &wsink->sources);
list_add(&path->list_source, &wsource->sinks);
path->connect = 1;
return 0;
case snd_soc_dapm_mux:
case snd_soc_dapm_virt_mux:
case snd_soc_dapm_value_mux:
ret = dapm_connect_mux(dapm, wsource, wsink, path, control,
&wsink->kcontrol_news[0]);
if (ret != 0)
goto err;
break;
case snd_soc_dapm_switch:
case snd_soc_dapm_mixer:
case snd_soc_dapm_mixer_named_ctl:
ret = dapm_connect_mixer(dapm, wsource, wsink, path, control);
if (ret != 0)
goto err;
break;
case snd_soc_dapm_hp:
case snd_soc_dapm_mic:
case snd_soc_dapm_line:
case snd_soc_dapm_spk:
list_add(&path->list, &dapm->card->paths);
list_add(&path->list_sink, &wsink->sources);
list_add(&path->list_source, &wsource->sinks);
path->connect = 0;
return 0;
}
dapm_mark_dirty(wsource, "Route added");
dapm_mark_dirty(wsink, "Route added");
return 0;
err:
dev_warn(dapm->dev, "ASoC: no dapm match for %s --> %s --> %s\n",
source, control, sink);
kfree(path);
return ret;
}
static int snd_soc_dapm_del_route(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_route *route)
{
struct snd_soc_dapm_path *path, *p;
const char *sink;
const char *source;
char prefixed_sink[80];
char prefixed_source[80];
if (route->control) {
dev_err(dapm->dev,
"ASoC: Removal of routes with controls not supported\n");
return -EINVAL;
}
if (dapm->codec && dapm->codec->name_prefix) {
snprintf(prefixed_sink, sizeof(prefixed_sink), "%s %s",
dapm->codec->name_prefix, route->sink);
sink = prefixed_sink;
snprintf(prefixed_source, sizeof(prefixed_source), "%s %s",
dapm->codec->name_prefix, route->source);
source = prefixed_source;
} else {
sink = route->sink;
source = route->source;
}
path = NULL;
list_for_each_entry(p, &dapm->card->paths, list) {
if (strcmp(p->source->name, source) != 0)
continue;
if (strcmp(p->sink->name, sink) != 0)
continue;
path = p;
break;
}
if (path) {
dapm_mark_dirty(path->source, "Route removed");
dapm_mark_dirty(path->sink, "Route removed");
list_del(&path->list);
list_del(&path->list_sink);
list_del(&path->list_source);
kfree(path);
} else {
dev_warn(dapm->dev, "ASoC: Route %s->%s does not exist\n",
source, sink);
}
return 0;
}
int snd_soc_dapm_add_routes(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_route *route, int num)
{
int i, r, ret = 0;
mutex_lock_nested(&dapm->card->dapm_mutex, SND_SOC_DAPM_CLASS_INIT);
for (i = 0; i < num; i++) {
r = snd_soc_dapm_add_route(dapm, route);
if (r < 0) {
dev_err(dapm->dev, "ASoC: Failed to add route %s -> %s -> %s\n",
route->source,
route->control ? route->control : "direct",
route->sink);
ret = r;
}
route++;
}
mutex_unlock(&dapm->card->dapm_mutex);
return ret;
}
int snd_soc_dapm_del_routes(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_route *route, int num)
{
int i, ret = 0;
mutex_lock_nested(&dapm->card->dapm_mutex, SND_SOC_DAPM_CLASS_INIT);
for (i = 0; i < num; i++) {
snd_soc_dapm_del_route(dapm, route);
route++;
}
mutex_unlock(&dapm->card->dapm_mutex);
return ret;
}
static int snd_soc_dapm_weak_route(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_route *route)
{
struct snd_soc_dapm_widget *source = dapm_find_widget(dapm,
route->source,
true);
struct snd_soc_dapm_widget *sink = dapm_find_widget(dapm,
route->sink,
true);
struct snd_soc_dapm_path *path;
int count = 0;
if (!source) {
dev_err(dapm->dev, "ASoC: Unable to find source %s for weak route\n",
route->source);
return -ENODEV;
}
if (!sink) {
dev_err(dapm->dev, "ASoC: Unable to find sink %s for weak route\n",
route->sink);
return -ENODEV;
}
if (route->control || route->connected)
dev_warn(dapm->dev, "ASoC: Ignoring control for weak route %s->%s\n",
route->source, route->sink);
list_for_each_entry(path, &source->sinks, list_source) {
if (path->sink == sink) {
path->weak = 1;
count++;
}
}
if (count == 0)
dev_err(dapm->dev, "ASoC: No path found for weak route %s->%s\n",
route->source, route->sink);
if (count > 1)
dev_warn(dapm->dev, "ASoC: %d paths found for weak route %s->%s\n",
count, route->source, route->sink);
return 0;
}
int snd_soc_dapm_weak_routes(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_route *route, int num)
{
int i, err;
int ret = 0;
mutex_lock_nested(&dapm->card->dapm_mutex, SND_SOC_DAPM_CLASS_INIT);
for (i = 0; i < num; i++) {
err = snd_soc_dapm_weak_route(dapm, route);
if (err)
ret = err;
route++;
}
mutex_unlock(&dapm->card->dapm_mutex);
return ret;
}
int snd_soc_dapm_new_widgets(struct snd_soc_dapm_context *dapm)
{
struct snd_soc_dapm_widget *w;
unsigned int val;
mutex_lock_nested(&dapm->card->dapm_mutex, SND_SOC_DAPM_CLASS_INIT);
list_for_each_entry(w, &dapm->card->widgets, list)
{
if (w->new)
continue;
if (w->num_kcontrols) {
w->kcontrols = kzalloc(w->num_kcontrols *
sizeof(struct snd_kcontrol *),
GFP_KERNEL);
if (!w->kcontrols) {
mutex_unlock(&dapm->card->dapm_mutex);
return -ENOMEM;
}
}
switch(w->id) {
case snd_soc_dapm_switch:
case snd_soc_dapm_mixer:
case snd_soc_dapm_mixer_named_ctl:
dapm_new_mixer(w);
break;
case snd_soc_dapm_mux:
case snd_soc_dapm_virt_mux:
case snd_soc_dapm_value_mux:
dapm_new_mux(w);
break;
case snd_soc_dapm_pga:
case snd_soc_dapm_out_drv:
dapm_new_pga(w);
break;
default:
break;
}
if (w->reg >= 0) {
val = soc_widget_read(w, w->reg);
val &= 1 << w->shift;
if (w->invert)
val = !val;
if (val)
w->power = 1;
}
w->new = 1;
dapm_mark_dirty(w, "new widget");
dapm_debugfs_add_widget(w);
}
dapm_power_widgets(dapm, SND_SOC_DAPM_STREAM_NOP);
mutex_unlock(&dapm->card->dapm_mutex);
return 0;
}
int snd_soc_dapm_get_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
if (snd_soc_volsw_is_stereo(mc))
dev_warn(widget->dapm->dev,
"ASoC: Control '%s' is stereo, which is not supported\n",
kcontrol->id.name);
ucontrol->value.integer.value[0] =
(snd_soc_read(widget->codec, reg) >> shift) & mask;
if (invert)
ucontrol->value.integer.value[0] =
max - ucontrol->value.integer.value[0];
return 0;
}
int snd_soc_dapm_put_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct snd_soc_codec *codec = widget->codec;
struct snd_soc_card *card = codec->card;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
unsigned int val;
int connect, change;
struct snd_soc_dapm_update update;
int wi;
if (snd_soc_volsw_is_stereo(mc))
dev_warn(widget->dapm->dev,
"ASoC: Control '%s' is stereo, which is not supported\n",
kcontrol->id.name);
val = (ucontrol->value.integer.value[0] & mask);
connect = !!val;
if (invert)
val = max - val;
mask = mask << shift;
val = val << shift;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
change = snd_soc_test_bits(widget->codec, reg, mask, val);
if (change) {
for (wi = 0; wi < wlist->num_widgets; wi++) {
widget = wlist->widgets[wi];
widget->value = val;
update.kcontrol = kcontrol;
update.widget = widget;
update.reg = reg;
update.mask = mask;
update.val = val;
widget->dapm->update = &update;
soc_dapm_mixer_update_power(widget, kcontrol, connect);
widget->dapm->update = NULL;
}
}
mutex_unlock(&card->dapm_mutex);
return 0;
}
int snd_soc_dapm_get_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int val;
val = snd_soc_read(widget->codec, e->reg);
ucontrol->value.enumerated.item[0] = (val >> e->shift_l) & e->mask;
if (e->shift_l != e->shift_r)
ucontrol->value.enumerated.item[1] =
(val >> e->shift_r) & e->mask;
return 0;
}
int snd_soc_dapm_put_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct snd_soc_codec *codec = widget->codec;
struct snd_soc_card *card = codec->card;
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int val, mux, change;
unsigned int mask;
struct snd_soc_dapm_update update;
int wi;
if (ucontrol->value.enumerated.item[0] > e->max - 1)
return -EINVAL;
mux = ucontrol->value.enumerated.item[0];
val = mux << e->shift_l;
mask = e->mask << e->shift_l;
if (e->shift_l != e->shift_r) {
if (ucontrol->value.enumerated.item[1] > e->max - 1)
return -EINVAL;
val |= ucontrol->value.enumerated.item[1] << e->shift_r;
mask |= e->mask << e->shift_r;
}
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
change = snd_soc_test_bits(widget->codec, e->reg, mask, val);
if (change) {
for (wi = 0; wi < wlist->num_widgets; wi++) {
widget = wlist->widgets[wi];
widget->value = val;
update.kcontrol = kcontrol;
update.widget = widget;
update.reg = e->reg;
update.mask = mask;
update.val = val;
widget->dapm->update = &update;
soc_dapm_mux_update_power(widget, kcontrol, mux, e);
widget->dapm->update = NULL;
}
}
mutex_unlock(&card->dapm_mutex);
return change;
}
int snd_soc_dapm_get_enum_virt(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
ucontrol->value.enumerated.item[0] = widget->value;
return 0;
}
int snd_soc_dapm_put_enum_virt(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct snd_soc_codec *codec = widget->codec;
struct snd_soc_card *card = codec->card;
struct soc_enum *e =
(struct soc_enum *)kcontrol->private_value;
int change;
int ret = 0;
int wi;
if (ucontrol->value.enumerated.item[0] >= e->max)
return -EINVAL;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
change = widget->value != ucontrol->value.enumerated.item[0];
if (change) {
for (wi = 0; wi < wlist->num_widgets; wi++) {
widget = wlist->widgets[wi];
widget->value = ucontrol->value.enumerated.item[0];
soc_dapm_mux_update_power(widget, kcontrol, widget->value, e);
}
}
mutex_unlock(&card->dapm_mutex);
return ret;
}
int snd_soc_dapm_get_value_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int reg_val, val, mux;
reg_val = snd_soc_read(widget->codec, e->reg);
val = (reg_val >> e->shift_l) & e->mask;
for (mux = 0; mux < e->max; mux++) {
if (val == e->values[mux])
break;
}
ucontrol->value.enumerated.item[0] = mux;
if (e->shift_l != e->shift_r) {
val = (reg_val >> e->shift_r) & e->mask;
for (mux = 0; mux < e->max; mux++) {
if (val == e->values[mux])
break;
}
ucontrol->value.enumerated.item[1] = mux;
}
return 0;
}
int snd_soc_dapm_put_value_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct snd_soc_codec *codec = widget->codec;
struct snd_soc_card *card = codec->card;
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int val, mux, change;
unsigned int mask;
struct snd_soc_dapm_update update;
int wi;
if (ucontrol->value.enumerated.item[0] > e->max - 1)
return -EINVAL;
mux = ucontrol->value.enumerated.item[0];
val = e->values[ucontrol->value.enumerated.item[0]] << e->shift_l;
mask = e->mask << e->shift_l;
if (e->shift_l != e->shift_r) {
if (ucontrol->value.enumerated.item[1] > e->max - 1)
return -EINVAL;
val |= e->values[ucontrol->value.enumerated.item[1]] << e->shift_r;
mask |= e->mask << e->shift_r;
}
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
change = snd_soc_test_bits(widget->codec, e->reg, mask, val);
if (change) {
for (wi = 0; wi < wlist->num_widgets; wi++) {
widget = wlist->widgets[wi];
widget->value = val;
update.kcontrol = kcontrol;
update.widget = widget;
update.reg = e->reg;
update.mask = mask;
update.val = val;
widget->dapm->update = &update;
soc_dapm_mux_update_power(widget, kcontrol, mux, e);
widget->dapm->update = NULL;
}
}
mutex_unlock(&card->dapm_mutex);
return change;
}
int snd_soc_dapm_info_pin_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
int snd_soc_dapm_get_pin_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
const char *pin = (const char *)kcontrol->private_value;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
ucontrol->value.integer.value[0] =
snd_soc_dapm_get_pin_status(&card->dapm, pin);
mutex_unlock(&card->dapm_mutex);
return 0;
}
int snd_soc_dapm_put_pin_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
const char *pin = (const char *)kcontrol->private_value;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
if (ucontrol->value.integer.value[0])
snd_soc_dapm_enable_pin(&card->dapm, pin);
else
snd_soc_dapm_disable_pin(&card->dapm, pin);
mutex_unlock(&card->dapm_mutex);
snd_soc_dapm_sync(&card->dapm);
return 0;
}
static struct snd_soc_dapm_widget *
snd_soc_dapm_new_control(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_widget *widget)
{
struct snd_soc_dapm_widget *w;
size_t name_len;
int ret;
if ((w = dapm_cnew_widget(widget)) == NULL)
return NULL;
switch (w->id) {
case snd_soc_dapm_regulator_supply:
w->regulator = devm_regulator_get(dapm->dev, w->name);
if (IS_ERR(w->regulator)) {
ret = PTR_ERR(w->regulator);
dev_err(dapm->dev, "ASoC: Failed to request %s: %d\n",
w->name, ret);
return NULL;
}
if (w->invert & SND_SOC_DAPM_REGULATOR_BYPASS) {
ret = regulator_allow_bypass(w->regulator, true);
if (ret != 0)
dev_warn(w->dapm->dev,
"ASoC: Failed to unbypass %s: %d\n",
w->name, ret);
}
break;
case snd_soc_dapm_clock_supply:
#ifdef CONFIG_CLKDEV_LOOKUP
w->clk = devm_clk_get(dapm->dev, w->name);
if (IS_ERR(w->clk)) {
ret = PTR_ERR(w->clk);
dev_err(dapm->dev, "ASoC: Failed to request %s: %d\n",
w->name, ret);
return NULL;
}
#else
return NULL;
#endif
break;
default:
break;
}
name_len = strlen(widget->name) + 1;
if (dapm->codec && dapm->codec->name_prefix)
name_len += 1 + strlen(dapm->codec->name_prefix);
w->name = kmalloc(name_len, GFP_KERNEL);
if (w->name == NULL) {
kfree(w);
return NULL;
}
if (dapm->codec && dapm->codec->name_prefix)
snprintf((char *)w->name, name_len, "%s %s",
dapm->codec->name_prefix, widget->name);
else
snprintf((char *)w->name, name_len, "%s", widget->name);
switch (w->id) {
case snd_soc_dapm_switch:
case snd_soc_dapm_mixer:
case snd_soc_dapm_mixer_named_ctl:
w->power_check = dapm_generic_check_power;
break;
case snd_soc_dapm_mux:
case snd_soc_dapm_virt_mux:
case snd_soc_dapm_value_mux:
w->power_check = dapm_generic_check_power;
break;
case snd_soc_dapm_adc:
case snd_soc_dapm_aif_out:
case snd_soc_dapm_dai_out:
w->power_check = dapm_adc_check_power;
break;
case snd_soc_dapm_dac:
case snd_soc_dapm_aif_in:
case snd_soc_dapm_dai_in:
w->power_check = dapm_dac_check_power;
break;
case snd_soc_dapm_pga:
case snd_soc_dapm_out_drv:
case snd_soc_dapm_input:
case snd_soc_dapm_output:
case snd_soc_dapm_micbias:
case snd_soc_dapm_spk:
case snd_soc_dapm_hp:
case snd_soc_dapm_mic:
case snd_soc_dapm_line:
case snd_soc_dapm_dai_link:
w->power_check = dapm_generic_check_power;
break;
case snd_soc_dapm_supply:
case snd_soc_dapm_regulator_supply:
case snd_soc_dapm_clock_supply:
w->power_check = dapm_supply_check_power;
break;
default:
w->power_check = dapm_always_on_check_power;
break;
}
w->dapm = dapm;
w->codec = dapm->codec;
w->platform = dapm->platform;
INIT_LIST_HEAD(&w->sources);
INIT_LIST_HEAD(&w->sinks);
INIT_LIST_HEAD(&w->list);
INIT_LIST_HEAD(&w->dirty);
list_add(&w->list, &dapm->card->widgets);
w->connected = 1;
return w;
}
int snd_soc_dapm_new_controls(struct snd_soc_dapm_context *dapm,
const struct snd_soc_dapm_widget *widget,
int num)
{
struct snd_soc_dapm_widget *w;
int i;
int ret = 0;
mutex_lock_nested(&dapm->card->dapm_mutex, SND_SOC_DAPM_CLASS_INIT);
for (i = 0; i < num; i++) {
w = snd_soc_dapm_new_control(dapm, widget);
if (!w) {
dev_err(dapm->dev,
"ASoC: Failed to create DAPM control %s\n",
widget->name);
ret = -ENOMEM;
break;
}
widget++;
}
mutex_unlock(&dapm->card->dapm_mutex);
return ret;
}
static int snd_soc_dai_link_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_dapm_path *source_p, *sink_p;
struct snd_soc_dai *source, *sink;
const struct snd_soc_pcm_stream *config = w->params;
struct snd_pcm_substream substream;
struct snd_pcm_hw_params *params = NULL;
u64 fmt;
int ret;
BUG_ON(!config);
BUG_ON(list_empty(&w->sources) || list_empty(&w->sinks));
source_p = list_first_entry(&w->sources, struct snd_soc_dapm_path,
list_sink);
sink_p = list_first_entry(&w->sinks, struct snd_soc_dapm_path,
list_source);
BUG_ON(!source_p || !sink_p);
BUG_ON(!sink_p->source || !source_p->sink);
BUG_ON(!source_p->source || !sink_p->sink);
source = source_p->source->priv;
sink = sink_p->sink->priv;
if (config->formats) {
fmt = ffs(config->formats) - 1;
} else {
dev_warn(w->dapm->dev, "ASoC: Invalid format %llx specified\n",
config->formats);
fmt = 0;
}
params = kzalloc(sizeof(*params), GFP_KERNEL);
if (!params) {
ret = -ENOMEM;
goto out;
}
snd_mask_set(hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT), fmt);
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE)->min =
config->rate_min;
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE)->max =
config->rate_max;
hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS)->min
= config->channels_min;
hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS)->max
= config->channels_max;
memset(&substream, 0, sizeof(substream));
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (source->driver->ops && source->driver->ops->hw_params) {
substream.stream = SNDRV_PCM_STREAM_CAPTURE;
ret = source->driver->ops->hw_params(&substream,
params, source);
if (ret != 0) {
dev_err(source->dev,
"ASoC: hw_params() failed: %d\n", ret);
goto out;
}
}
if (sink->driver->ops && sink->driver->ops->hw_params) {
substream.stream = SNDRV_PCM_STREAM_PLAYBACK;
ret = sink->driver->ops->hw_params(&substream, params,
sink);
if (ret != 0) {
dev_err(sink->dev,
"ASoC: hw_params() failed: %d\n", ret);
goto out;
}
}
break;
case SND_SOC_DAPM_POST_PMU:
ret = snd_soc_dai_digital_mute(sink, 0,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret != 0 && ret != -ENOTSUPP)
dev_warn(sink->dev, "ASoC: Failed to unmute: %d\n", ret);
ret = 0;
break;
case SND_SOC_DAPM_PRE_PMD:
ret = snd_soc_dai_digital_mute(sink, 1,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret != 0 && ret != -ENOTSUPP)
dev_warn(sink->dev, "ASoC: Failed to mute: %d\n", ret);
ret = 0;
break;
default:
BUG();
return -EINVAL;
}
out:
kfree(params);
return ret;
}
int snd_soc_dapm_new_pcm(struct snd_soc_card *card,
const struct snd_soc_pcm_stream *params,
struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_dapm_route routes[2];
struct snd_soc_dapm_widget template;
struct snd_soc_dapm_widget *w;
size_t len;
char *link_name;
len = strlen(source->name) + strlen(sink->name) + 2;
link_name = devm_kzalloc(card->dev, len, GFP_KERNEL);
if (!link_name)
return -ENOMEM;
snprintf(link_name, len, "%s-%s", source->name, sink->name);
memset(&template, 0, sizeof(template));
template.reg = SND_SOC_NOPM;
template.id = snd_soc_dapm_dai_link;
template.name = link_name;
template.event = snd_soc_dai_link_event;
template.event_flags = SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMU |
SND_SOC_DAPM_PRE_PMD;
dev_dbg(card->dev, "ASoC: adding %s widget\n", link_name);
w = snd_soc_dapm_new_control(&card->dapm, &template);
if (!w) {
dev_err(card->dev, "ASoC: Failed to create %s widget\n",
link_name);
return -ENOMEM;
}
w->params = params;
memset(&routes, 0, sizeof(routes));
routes[0].source = source->name;
routes[0].sink = link_name;
routes[1].source = link_name;
routes[1].sink = sink->name;
return snd_soc_dapm_add_routes(&card->dapm, routes,
ARRAY_SIZE(routes));
}
int snd_soc_dapm_new_dai_widgets(struct snd_soc_dapm_context *dapm,
struct snd_soc_dai *dai)
{
struct snd_soc_dapm_widget template;
struct snd_soc_dapm_widget *w;
WARN_ON(dapm->dev != dai->dev);
memset(&template, 0, sizeof(template));
template.reg = SND_SOC_NOPM;
if (dai->driver->playback.stream_name) {
template.id = snd_soc_dapm_dai_in;
template.name = dai->driver->playback.stream_name;
template.sname = dai->driver->playback.stream_name;
dev_dbg(dai->dev, "ASoC: adding %s widget\n",
template.name);
w = snd_soc_dapm_new_control(dapm, &template);
if (!w) {
dev_err(dapm->dev, "ASoC: Failed to create %s widget\n",
dai->driver->playback.stream_name);
}
w->priv = dai;
dai->playback_widget = w;
}
if (dai->driver->capture.stream_name) {
template.id = snd_soc_dapm_dai_out;
template.name = dai->driver->capture.stream_name;
template.sname = dai->driver->capture.stream_name;
dev_dbg(dai->dev, "ASoC: adding %s widget\n",
template.name);
w = snd_soc_dapm_new_control(dapm, &template);
if (!w) {
dev_err(dapm->dev, "ASoC: Failed to create %s widget\n",
dai->driver->capture.stream_name);
}
w->priv = dai;
dai->capture_widget = w;
}
return 0;
}
int snd_soc_dapm_link_dai_widgets(struct snd_soc_card *card)
{
struct snd_soc_dapm_widget *dai_w, *w;
struct snd_soc_dai *dai;
struct snd_soc_dapm_route r;
memset(&r, 0, sizeof(r));
list_for_each_entry(dai_w, &card->widgets, list) {
switch (dai_w->id) {
case snd_soc_dapm_dai_in:
case snd_soc_dapm_dai_out:
break;
default:
continue;
}
dai = dai_w->priv;
list_for_each_entry(w, &card->widgets, list) {
if (w->dapm != dai_w->dapm)
continue;
switch (w->id) {
case snd_soc_dapm_dai_in:
case snd_soc_dapm_dai_out:
continue;
default:
break;
}
if (!w->sname)
continue;
if (dai->driver->playback.stream_name &&
strstr(w->sname,
dai->driver->playback.stream_name)) {
r.source = dai->playback_widget->name;
r.sink = w->name;
dev_dbg(dai->dev, "%s -> %s\n",
r.source, r.sink);
snd_soc_dapm_add_route(w->dapm, &r);
}
if (dai->driver->capture.stream_name &&
strstr(w->sname,
dai->driver->capture.stream_name)) {
r.source = w->name;
r.sink = dai->capture_widget->name;
dev_dbg(dai->dev, "%s -> %s\n",
r.source, r.sink);
snd_soc_dapm_add_route(w->dapm, &r);
}
}
}
return 0;
}
static void soc_dapm_stream_event(struct snd_soc_pcm_runtime *rtd, int stream,
int event)
{
struct snd_soc_dapm_widget *w_cpu, *w_codec;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
w_cpu = cpu_dai->playback_widget;
w_codec = codec_dai->playback_widget;
} else {
w_cpu = cpu_dai->capture_widget;
w_codec = codec_dai->capture_widget;
}
if (w_cpu) {
dapm_mark_dirty(w_cpu, "stream event");
switch (event) {
case SND_SOC_DAPM_STREAM_START:
w_cpu->active = 1;
break;
case SND_SOC_DAPM_STREAM_STOP:
w_cpu->active = 0;
break;
case SND_SOC_DAPM_STREAM_SUSPEND:
case SND_SOC_DAPM_STREAM_RESUME:
case SND_SOC_DAPM_STREAM_PAUSE_PUSH:
case SND_SOC_DAPM_STREAM_PAUSE_RELEASE:
break;
}
}
if (w_codec) {
dapm_mark_dirty(w_codec, "stream event");
switch (event) {
case SND_SOC_DAPM_STREAM_START:
w_codec->active = 1;
break;
case SND_SOC_DAPM_STREAM_STOP:
w_codec->active = 0;
break;
case SND_SOC_DAPM_STREAM_SUSPEND:
case SND_SOC_DAPM_STREAM_RESUME:
case SND_SOC_DAPM_STREAM_PAUSE_PUSH:
case SND_SOC_DAPM_STREAM_PAUSE_RELEASE:
break;
}
}
dapm_power_widgets(&rtd->card->dapm, event);
}
void snd_soc_dapm_stream_event(struct snd_soc_pcm_runtime *rtd, int stream,
int event)
{
struct snd_soc_card *card = rtd->card;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
soc_dapm_stream_event(rtd, stream, event);
mutex_unlock(&card->dapm_mutex);
}
int snd_soc_dapm_enable_pin(struct snd_soc_dapm_context *dapm, const char *pin)
{
return snd_soc_dapm_set_pin(dapm, pin, 1);
}
int snd_soc_dapm_force_enable_pin(struct snd_soc_dapm_context *dapm,
const char *pin)
{
struct snd_soc_dapm_widget *w = dapm_find_widget(dapm, pin, true);
if (!w) {
dev_err(dapm->dev, "ASoC: unknown pin %s\n", pin);
return -EINVAL;
}
dev_dbg(w->dapm->dev, "ASoC: force enable pin %s\n", pin);
w->connected = 1;
w->force = 1;
dapm_mark_dirty(w, "force enable");
return 0;
}
int snd_soc_dapm_disable_pin(struct snd_soc_dapm_context *dapm,
const char *pin)
{
return snd_soc_dapm_set_pin(dapm, pin, 0);
}
int snd_soc_dapm_nc_pin(struct snd_soc_dapm_context *dapm, const char *pin)
{
return snd_soc_dapm_set_pin(dapm, pin, 0);
}
int snd_soc_dapm_get_pin_status(struct snd_soc_dapm_context *dapm,
const char *pin)
{
struct snd_soc_dapm_widget *w = dapm_find_widget(dapm, pin, true);
if (w)
return w->connected;
return 0;
}
int snd_soc_dapm_ignore_suspend(struct snd_soc_dapm_context *dapm,
const char *pin)
{
struct snd_soc_dapm_widget *w = dapm_find_widget(dapm, pin, false);
if (!w) {
dev_err(dapm->dev, "ASoC: unknown pin %s\n", pin);
return -EINVAL;
}
w->ignore_suspend = 1;
return 0;
}
static bool snd_soc_dapm_widget_in_card_paths(struct snd_soc_card *card,
struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_path *p;
list_for_each_entry(p, &card->paths, list) {
if ((p->source == w) || (p->sink == w)) {
dev_dbg(card->dev,
"... Path %s(id:%d dapm:%p) - %s(id:%d dapm:%p)\n",
p->source->name, p->source->id, p->source->dapm,
p->sink->name, p->sink->id, p->sink->dapm);
if (p->source->dapm != p->sink->dapm)
return true;
if (p->sink->id == snd_soc_dapm_input) {
switch (p->source->id) {
case snd_soc_dapm_output:
case snd_soc_dapm_micbias:
return true;
default:
break;
}
}
}
}
return false;
}
void snd_soc_dapm_auto_nc_codec_pins(struct snd_soc_codec *codec)
{
struct snd_soc_card *card = codec->card;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct snd_soc_dapm_widget *w;
dev_dbg(codec->dev, "ASoC: Auto NC: DAPMs: card:%p codec:%p\n",
&card->dapm, &codec->dapm);
list_for_each_entry(w, &card->widgets, list) {
if (w->dapm != dapm)
continue;
switch (w->id) {
case snd_soc_dapm_input:
case snd_soc_dapm_output:
case snd_soc_dapm_micbias:
dev_dbg(codec->dev, "ASoC: Auto NC: Checking widget %s\n",
w->name);
if (!snd_soc_dapm_widget_in_card_paths(card, w)) {
dev_dbg(codec->dev,
"... Not in map; disabling\n");
snd_soc_dapm_nc_pin(dapm, w->name);
}
break;
default:
break;
}
}
}
void snd_soc_dapm_free(struct snd_soc_dapm_context *dapm)
{
snd_soc_dapm_sys_remove(dapm->dev);
dapm_debugfs_cleanup(dapm);
dapm_free_widgets(dapm);
list_del(&dapm->list);
}
static void soc_dapm_shutdown_codec(struct snd_soc_dapm_context *dapm)
{
struct snd_soc_card *card = dapm->card;
struct snd_soc_dapm_widget *w;
LIST_HEAD(down_list);
int powerdown = 0;
mutex_lock(&card->dapm_mutex);
list_for_each_entry(w, &dapm->card->widgets, list) {
if (w->dapm != dapm)
continue;
if (w->power) {
dapm_seq_insert(w, &down_list, false);
w->power = 0;
powerdown = 1;
}
}
if (powerdown) {
if (dapm->bias_level == SND_SOC_BIAS_ON)
snd_soc_dapm_set_bias_level(dapm,
SND_SOC_BIAS_PREPARE);
dapm_seq_run(dapm, &down_list, 0, false);
if (dapm->bias_level == SND_SOC_BIAS_PREPARE)
snd_soc_dapm_set_bias_level(dapm,
SND_SOC_BIAS_STANDBY);
}
mutex_unlock(&card->dapm_mutex);
}
void snd_soc_dapm_shutdown(struct snd_soc_card *card)
{
struct snd_soc_codec *codec;
list_for_each_entry(codec, &card->codec_dev_list, card_list) {
soc_dapm_shutdown_codec(&codec->dapm);
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY)
snd_soc_dapm_set_bias_level(&codec->dapm,
SND_SOC_BIAS_OFF);
}
}
