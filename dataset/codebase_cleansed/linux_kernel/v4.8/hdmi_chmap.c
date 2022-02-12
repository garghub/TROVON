static int hdmi_pin_set_slot_channel(struct hdac_device *codec,
hda_nid_t pin_nid, int asp_slot, int channel)
{
return snd_hdac_codec_write(codec, pin_nid, 0,
AC_VERB_SET_HDMI_CHAN_SLOT,
(channel << 4) | asp_slot);
}
static int hdmi_pin_get_slot_channel(struct hdac_device *codec,
hda_nid_t pin_nid, int asp_slot)
{
return (snd_hdac_codec_read(codec, pin_nid, 0,
AC_VERB_GET_HDMI_CHAN_SLOT,
asp_slot) & 0xf0) >> 4;
}
static int hdmi_get_channel_count(struct hdac_device *codec, hda_nid_t cvt_nid)
{
return 1 + snd_hdac_codec_read(codec, cvt_nid, 0,
AC_VERB_GET_CVT_CHAN_COUNT, 0);
}
static void hdmi_set_channel_count(struct hdac_device *codec,
hda_nid_t cvt_nid, int chs)
{
if (chs != hdmi_get_channel_count(codec, cvt_nid))
snd_hdac_codec_write(codec, cvt_nid, 0,
AC_VERB_SET_CVT_CHAN_COUNT, chs - 1);
}
static void init_channel_allocations(void)
{
int i, j;
struct hdac_cea_channel_speaker_allocation *p;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
p = channel_allocations + i;
p->channels = 0;
p->spk_mask = 0;
for (j = 0; j < ARRAY_SIZE(p->speakers); j++)
if (p->speakers[j]) {
p->channels++;
p->spk_mask |= p->speakers[j];
}
}
}
static int get_channel_allocation_order(int ca)
{
int i;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channel_allocations[i].ca_index == ca)
break;
}
return i;
}
void snd_hdac_print_channel_allocation(int spk_alloc, char *buf, int buflen)
{
int i, j;
for (i = 0, j = 0; i < ARRAY_SIZE(cea_speaker_allocation_names); i++) {
if (spk_alloc & (1 << i))
j += snprintf(buf + j, buflen - j, " %s",
cea_speaker_allocation_names[i]);
}
buf[j] = '\0';
}
static int hdmi_channel_allocation_spk_alloc_blk(struct hdac_device *codec,
int spk_alloc, int channels)
{
int i;
int ca = 0;
int spk_mask = 0;
char buf[SND_PRINT_CHANNEL_ALLOCATION_ADVISED_BUFSIZE];
if (channels <= 2)
return 0;
for (i = 0; i < ARRAY_SIZE(eld_speaker_allocation_bits); i++) {
if (spk_alloc & (1 << i))
spk_mask |= eld_speaker_allocation_bits[i];
}
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channels == channel_allocations[i].channels &&
(spk_mask & channel_allocations[i].spk_mask) ==
channel_allocations[i].spk_mask) {
ca = channel_allocations[i].ca_index;
break;
}
}
if (!ca) {
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channels == channel_allocations[i].channels) {
ca = channel_allocations[i].ca_index;
break;
}
}
}
snd_hdac_print_channel_allocation(spk_alloc, buf, sizeof(buf));
dev_dbg(&codec->dev, "HDMI: select CA 0x%x for %d-channel allocation: %s\n",
ca, channels, buf);
return ca;
}
static void hdmi_debug_channel_mapping(struct hdac_chmap *chmap,
hda_nid_t pin_nid)
{
#ifdef CONFIG_SND_DEBUG_VERBOSE
int i;
int channel;
for (i = 0; i < 8; i++) {
channel = chmap->ops.pin_get_slot_channel(
chmap->hdac, pin_nid, i);
dev_dbg(&chmap->hdac->dev, "HDMI: ASP channel %d => slot %d\n",
channel, i);
}
#endif
}
static void hdmi_std_setup_channel_mapping(struct hdac_chmap *chmap,
hda_nid_t pin_nid,
bool non_pcm,
int ca)
{
struct hdac_cea_channel_speaker_allocation *ch_alloc;
int i;
int err;
int order;
int non_pcm_mapping[8];
order = get_channel_allocation_order(ca);
ch_alloc = &channel_allocations[order];
if (hdmi_channel_mapping[ca][1] == 0) {
int hdmi_slot = 0;
for (i = 0; i < ch_alloc->channels; i++) {
while (!WARN_ON(hdmi_slot >= 8) &&
!ch_alloc->speakers[7 - hdmi_slot])
hdmi_slot++;
hdmi_channel_mapping[ca][i] = (i << 4) | hdmi_slot++;
}
for (hdmi_slot = 0; hdmi_slot < 8; hdmi_slot++)
if (!ch_alloc->speakers[7 - hdmi_slot])
hdmi_channel_mapping[ca][i++] = (0xf << 4) | hdmi_slot;
}
if (non_pcm) {
for (i = 0; i < ch_alloc->channels; i++)
non_pcm_mapping[i] = (i << 4) | i;
for (; i < 8; i++)
non_pcm_mapping[i] = (0xf << 4) | i;
}
for (i = 0; i < 8; i++) {
int slotsetup = non_pcm ? non_pcm_mapping[i] : hdmi_channel_mapping[ca][i];
int hdmi_slot = slotsetup & 0x0f;
int channel = (slotsetup & 0xf0) >> 4;
err = chmap->ops.pin_set_slot_channel(chmap->hdac,
pin_nid, hdmi_slot, channel);
if (err) {
dev_dbg(&chmap->hdac->dev, "HDMI: channel mapping failed\n");
break;
}
}
}
int snd_hdac_chmap_to_spk_mask(unsigned char c)
{
struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->map == c)
return t->spk_mask;
}
return 0;
}
static int to_cea_slot(int ordered_ca, unsigned char pos)
{
int mask = snd_hdac_chmap_to_spk_mask(pos);
int i;
if (ordered_ca >= ARRAY_SIZE(channel_allocations))
return -1;
if (mask) {
for (i = 0; i < 8; i++) {
if (channel_allocations[ordered_ca].speakers[7 - i] == mask)
return i;
}
}
return -1;
}
int snd_hdac_spk_to_chmap(int spk)
{
struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->spk_mask == spk)
return t->map;
}
return 0;
}
static int from_cea_slot(int ordered_ca, unsigned char slot)
{
int mask;
if (slot >= 8)
return 0;
mask = channel_allocations[ordered_ca].speakers[7 - slot];
return snd_hdac_spk_to_chmap(mask);
}
static int hdmi_manual_channel_allocation(int chs, unsigned char *map)
{
int i, spks = 0, spk_mask = 0;
for (i = 0; i < chs; i++) {
int mask = snd_hdac_chmap_to_spk_mask(map[i]);
if (mask) {
spk_mask |= mask;
spks++;
}
}
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if ((chs == channel_allocations[i].channels ||
spks == channel_allocations[i].channels) &&
(spk_mask & channel_allocations[i].spk_mask) ==
channel_allocations[i].spk_mask)
return channel_allocations[i].ca_index;
}
return -1;
}
static int hdmi_manual_setup_channel_mapping(struct hdac_chmap *chmap,
hda_nid_t pin_nid,
int chs, unsigned char *map,
int ca)
{
int ordered_ca = get_channel_allocation_order(ca);
int alsa_pos, hdmi_slot;
int assignments[8] = {[0 ... 7] = 0xf};
for (alsa_pos = 0; alsa_pos < chs; alsa_pos++) {
hdmi_slot = to_cea_slot(ordered_ca, map[alsa_pos]);
if (hdmi_slot < 0)
continue;
assignments[hdmi_slot] = alsa_pos;
}
for (hdmi_slot = 0; hdmi_slot < 8; hdmi_slot++) {
int err;
err = chmap->ops.pin_set_slot_channel(chmap->hdac,
pin_nid, hdmi_slot, assignments[hdmi_slot]);
if (err)
return -EINVAL;
}
return 0;
}
static void hdmi_setup_fake_chmap(unsigned char *map, int ca)
{
int i;
int ordered_ca = get_channel_allocation_order(ca);
for (i = 0; i < 8; i++) {
if (ordered_ca < ARRAY_SIZE(channel_allocations) &&
i < channel_allocations[ordered_ca].channels)
map[i] = from_cea_slot(ordered_ca, hdmi_channel_mapping[ca][i] & 0x0f);
else
map[i] = 0;
}
}
void snd_hdac_setup_channel_mapping(struct hdac_chmap *chmap,
hda_nid_t pin_nid, bool non_pcm, int ca,
int channels, unsigned char *map,
bool chmap_set)
{
if (!non_pcm && chmap_set) {
hdmi_manual_setup_channel_mapping(chmap, pin_nid,
channels, map, ca);
} else {
hdmi_std_setup_channel_mapping(chmap, pin_nid, non_pcm, ca);
hdmi_setup_fake_chmap(map, ca);
}
hdmi_debug_channel_mapping(chmap, pin_nid);
}
int snd_hdac_get_active_channels(int ca)
{
int ordered_ca = get_channel_allocation_order(ca);
if (ordered_ca >= ARRAY_SIZE(channel_allocations))
ordered_ca = 0;
return channel_allocations[ordered_ca].channels;
}
struct hdac_cea_channel_speaker_allocation *snd_hdac_get_ch_alloc_from_ca(int ca)
{
return &channel_allocations[get_channel_allocation_order(ca)];
}
int snd_hdac_channel_allocation(struct hdac_device *hdac, int spk_alloc,
int channels, bool chmap_set, bool non_pcm, unsigned char *map)
{
int ca;
if (!non_pcm && chmap_set)
ca = hdmi_manual_channel_allocation(channels, map);
else
ca = hdmi_channel_allocation_spk_alloc_blk(hdac,
spk_alloc, channels);
if (ca < 0)
ca = 0;
return ca;
}
static int hdmi_chmap_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hdac_chmap *chmap = info->private_data;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = chmap->channels_max;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = SNDRV_CHMAP_LAST;
return 0;
}
static int hdmi_chmap_cea_alloc_validate_get_type(struct hdac_chmap *chmap,
struct hdac_cea_channel_speaker_allocation *cap, int channels)
{
if (cap->channels != channels)
return -1;
return SNDRV_CTL_TLVT_CHMAP_VAR;
}
static void hdmi_cea_alloc_to_tlv_chmap(struct hdac_chmap *hchmap,
struct hdac_cea_channel_speaker_allocation *cap,
unsigned int *chmap, int channels)
{
int count = 0;
int c;
for (c = 7; c >= 0; c--) {
int spk = cap->speakers[c];
if (!spk)
continue;
chmap[count++] = snd_hdac_spk_to_chmap(spk);
}
WARN_ON(count != channels);
}
static int spk_mask_from_spk_alloc(int spk_alloc)
{
int i;
int spk_mask = eld_speaker_allocation_bits[0];
for (i = 0; i < ARRAY_SIZE(eld_speaker_allocation_bits); i++) {
if (spk_alloc & (1 << i))
spk_mask |= eld_speaker_allocation_bits[i];
}
return spk_mask;
}
static int hdmi_chmap_ctl_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hdac_chmap *chmap = info->private_data;
int pcm_idx = kcontrol->private_value;
unsigned int __user *dst;
int chs, count = 0;
unsigned long max_chs;
int type;
int spk_alloc, spk_mask;
if (size < 8)
return -ENOMEM;
if (put_user(SNDRV_CTL_TLVT_CONTAINER, tlv))
return -EFAULT;
size -= 8;
dst = tlv + 2;
spk_alloc = chmap->ops.get_spk_alloc(chmap->hdac, pcm_idx);
spk_mask = spk_mask_from_spk_alloc(spk_alloc);
max_chs = hweight_long(spk_mask);
for (chs = 2; chs <= max_chs; chs++) {
int i;
struct hdac_cea_channel_speaker_allocation *cap;
cap = channel_allocations;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++, cap++) {
int chs_bytes = chs * 4;
unsigned int tlv_chmap[8];
if (cap->channels != chs)
continue;
if (!(cap->spk_mask == (spk_mask & cap->spk_mask)))
continue;
type = chmap->ops.chmap_cea_alloc_validate_get_type(
chmap, cap, chs);
if (type < 0)
return -ENODEV;
if (size < 8)
return -ENOMEM;
if (put_user(type, dst) ||
put_user(chs_bytes, dst + 1))
return -EFAULT;
dst += 2;
size -= 8;
count += 8;
if (size < chs_bytes)
return -ENOMEM;
size -= chs_bytes;
count += chs_bytes;
chmap->ops.cea_alloc_to_tlv_chmap(chmap, cap,
tlv_chmap, chs);
if (copy_to_user(dst, tlv_chmap, chs_bytes))
return -EFAULT;
dst += chs;
}
}
if (put_user(count, tlv + 1))
return -EFAULT;
return 0;
}
static int hdmi_chmap_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hdac_chmap *chmap = info->private_data;
int pcm_idx = kcontrol->private_value;
unsigned char pcm_chmap[8];
int i;
memset(pcm_chmap, 0, sizeof(pcm_chmap));
chmap->ops.get_chmap(chmap->hdac, pcm_idx, pcm_chmap);
for (i = 0; i < sizeof(chmap); i++)
ucontrol->value.integer.value[i] = pcm_chmap[i];
return 0;
}
static int hdmi_chmap_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct hdac_chmap *hchmap = info->private_data;
int pcm_idx = kcontrol->private_value;
unsigned int ctl_idx;
struct snd_pcm_substream *substream;
unsigned char chmap[8], per_pin_chmap[8];
int i, err, ca, prepared = 0;
if (!hchmap->ops.is_pcm_attached(hchmap->hdac, pcm_idx))
return 0;
ctl_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
substream = snd_pcm_chmap_substream(info, ctl_idx);
if (!substream || !substream->runtime)
return 0;
switch (substream->runtime->status->state) {
case SNDRV_PCM_STATE_OPEN:
case SNDRV_PCM_STATE_SETUP:
break;
case SNDRV_PCM_STATE_PREPARED:
prepared = 1;
break;
default:
return -EBUSY;
}
memset(chmap, 0, sizeof(chmap));
for (i = 0; i < ARRAY_SIZE(chmap); i++)
chmap[i] = ucontrol->value.integer.value[i];
hchmap->ops.get_chmap(hchmap->hdac, pcm_idx, per_pin_chmap);
if (!memcmp(chmap, per_pin_chmap, sizeof(chmap)))
return 0;
ca = hdmi_manual_channel_allocation(ARRAY_SIZE(chmap), chmap);
if (ca < 0)
return -EINVAL;
if (hchmap->ops.chmap_validate) {
err = hchmap->ops.chmap_validate(hchmap, ca,
ARRAY_SIZE(chmap), chmap);
if (err)
return err;
}
hchmap->ops.set_chmap(hchmap->hdac, pcm_idx, chmap, prepared);
return 0;
}
void snd_hdac_register_chmap_ops(struct hdac_device *hdac,
struct hdac_chmap *chmap)
{
chmap->ops = chmap_ops;
chmap->hdac = hdac;
init_channel_allocations();
}
int snd_hdac_add_chmap_ctls(struct snd_pcm *pcm, int pcm_idx,
struct hdac_chmap *hchmap)
{
struct snd_pcm_chmap *chmap;
struct snd_kcontrol *kctl;
int err, i;
err = snd_pcm_add_chmap_ctls(pcm,
SNDRV_PCM_STREAM_PLAYBACK,
NULL, 0, pcm_idx, &chmap);
if (err < 0)
return err;
chmap->private_data = hchmap;
kctl = chmap->kctl;
for (i = 0; i < kctl->count; i++)
kctl->vd[i].access |= SNDRV_CTL_ELEM_ACCESS_WRITE;
kctl->info = hdmi_chmap_ctl_info;
kctl->get = hdmi_chmap_ctl_get;
kctl->put = hdmi_chmap_ctl_put;
kctl->tlv.c = hdmi_chmap_ctl_tlv;
return 0;
}
