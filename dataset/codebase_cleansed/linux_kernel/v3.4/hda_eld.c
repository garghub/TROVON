static unsigned int hdmi_get_eld_data(struct hda_codec *codec, hda_nid_t nid,
int byte_index)
{
unsigned int val;
val = snd_hda_codec_read(codec, nid, 0,
AC_VERB_GET_HDMI_ELDD, byte_index);
#ifdef BE_PARANOID
printk(KERN_INFO "HDMI: ELD data byte %d: 0x%x\n", byte_index, val);
#endif
return val;
}
static void hdmi_update_short_audio_desc(struct cea_sad *a,
const unsigned char *buf)
{
int i;
int val;
val = GRAB_BITS(buf, 1, 0, 7);
a->rates = 0;
for (i = 0; i < 7; i++)
if (val & (1 << i))
a->rates |= cea_sampling_frequencies[i + 1];
a->channels = GRAB_BITS(buf, 0, 0, 3);
a->channels++;
a->sample_bits = 0;
a->max_bitrate = 0;
a->format = GRAB_BITS(buf, 0, 3, 4);
switch (a->format) {
case AUDIO_CODING_TYPE_REF_STREAM_HEADER:
snd_printd(KERN_INFO
"HDMI: audio coding type 0 not expected\n");
break;
case AUDIO_CODING_TYPE_LPCM:
val = GRAB_BITS(buf, 2, 0, 3);
for (i = 0; i < 3; i++)
if (val & (1 << i))
a->sample_bits |= cea_sample_sizes[i + 1];
break;
case AUDIO_CODING_TYPE_AC3:
case AUDIO_CODING_TYPE_MPEG1:
case AUDIO_CODING_TYPE_MP3:
case AUDIO_CODING_TYPE_MPEG2:
case AUDIO_CODING_TYPE_AACLC:
case AUDIO_CODING_TYPE_DTS:
case AUDIO_CODING_TYPE_ATRAC:
a->max_bitrate = GRAB_BITS(buf, 2, 0, 8);
a->max_bitrate *= 8000;
break;
case AUDIO_CODING_TYPE_SACD:
break;
case AUDIO_CODING_TYPE_EAC3:
break;
case AUDIO_CODING_TYPE_DTS_HD:
break;
case AUDIO_CODING_TYPE_MLP:
break;
case AUDIO_CODING_TYPE_DST:
break;
case AUDIO_CODING_TYPE_WMAPRO:
a->profile = GRAB_BITS(buf, 2, 0, 3);
break;
case AUDIO_CODING_TYPE_REF_CXT:
a->format = GRAB_BITS(buf, 2, 3, 5);
if (a->format == AUDIO_CODING_XTYPE_HE_REF_CT ||
a->format >= AUDIO_CODING_XTYPE_FIRST_RESERVED) {
snd_printd(KERN_INFO
"HDMI: audio coding xtype %d not expected\n",
a->format);
a->format = 0;
} else
a->format += AUDIO_CODING_TYPE_HE_AAC -
AUDIO_CODING_XTYPE_HE_AAC;
break;
}
}
static int hdmi_update_eld(struct hdmi_eld *e,
const unsigned char *buf, int size)
{
int mnl;
int i;
e->eld_ver = GRAB_BITS(buf, 0, 3, 5);
if (e->eld_ver != ELD_VER_CEA_861D &&
e->eld_ver != ELD_VER_PARTIAL) {
snd_printd(KERN_INFO "HDMI: Unknown ELD version %d\n",
e->eld_ver);
goto out_fail;
}
e->eld_size = size;
e->baseline_len = GRAB_BITS(buf, 2, 0, 8);
mnl = GRAB_BITS(buf, 4, 0, 5);
e->cea_edid_ver = GRAB_BITS(buf, 4, 5, 3);
e->support_hdcp = GRAB_BITS(buf, 5, 0, 1);
e->support_ai = GRAB_BITS(buf, 5, 1, 1);
e->conn_type = GRAB_BITS(buf, 5, 2, 2);
e->sad_count = GRAB_BITS(buf, 5, 4, 4);
e->aud_synch_delay = GRAB_BITS(buf, 6, 0, 8) * 2;
e->spk_alloc = GRAB_BITS(buf, 7, 0, 7);
e->port_id = get_unaligned_le64(buf + 8);
e->manufacture_id = get_unaligned_le16(buf + 16);
e->product_id = get_unaligned_le16(buf + 18);
if (mnl > ELD_MAX_MNL) {
snd_printd(KERN_INFO "HDMI: MNL is reserved value %d\n", mnl);
goto out_fail;
} else if (ELD_FIXED_BYTES + mnl > size) {
snd_printd(KERN_INFO "HDMI: out of range MNL %d\n", mnl);
goto out_fail;
} else
strlcpy(e->monitor_name, buf + ELD_FIXED_BYTES, mnl + 1);
for (i = 0; i < e->sad_count; i++) {
if (ELD_FIXED_BYTES + mnl + 3 * (i + 1) > size) {
snd_printd(KERN_INFO "HDMI: out of range SAD %d\n", i);
goto out_fail;
}
hdmi_update_short_audio_desc(e->sad + i,
buf + ELD_FIXED_BYTES + mnl + 3 * i);
}
if (!e->spk_alloc)
e->spk_alloc = 0xffff;
e->eld_valid = true;
return 0;
out_fail:
return -EINVAL;
}
int snd_hdmi_get_eld_size(struct hda_codec *codec, hda_nid_t nid)
{
return snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_HDMI_DIP_SIZE,
AC_DIPSIZE_ELD_BUF);
}
int snd_hdmi_get_eld(struct hdmi_eld *eld,
struct hda_codec *codec, hda_nid_t nid)
{
int i;
int ret;
int size;
unsigned char *buf;
size = snd_hdmi_get_eld_size(codec, nid);
if (size == 0) {
snd_printd(KERN_INFO "HDMI: ELD buf size is 0, force 128\n");
size = 128;
}
if (size < ELD_FIXED_BYTES || size > ELD_MAX_SIZE) {
snd_printd(KERN_INFO "HDMI: invalid ELD buf size %d\n", size);
return -ERANGE;
}
buf = eld->eld_buffer;
for (i = 0; i < size; i++) {
unsigned int val = hdmi_get_eld_data(codec, nid, i);
if (!(val & AC_ELDD_ELD_VALID)) {
snd_printd(KERN_INFO
"HDMI: invalid ELD data byte %d\n", i);
ret = -EINVAL;
goto error;
}
val &= AC_ELDD_ELD_DATA;
if (!val && !i) {
snd_printdd(KERN_INFO "HDMI: 0 ELD data\n");
ret = -EINVAL;
goto error;
}
buf[i] = val;
}
ret = hdmi_update_eld(eld, buf, size);
error:
return ret;
}
static void hdmi_print_pcm_rates(int pcm, char *buf, int buflen)
{
static unsigned int alsa_rates[] = {
5512, 8000, 11025, 16000, 22050, 32000, 44100, 48000, 64000,
88200, 96000, 176400, 192000, 384000
};
int i, j;
for (i = 0, j = 0; i < ARRAY_SIZE(alsa_rates); i++)
if (pcm & (1 << i))
j += snprintf(buf + j, buflen - j, " %d",
alsa_rates[i]);
buf[j] = '\0';
}
static void hdmi_show_short_audio_desc(struct cea_sad *a)
{
char buf[SND_PRINT_RATES_ADVISED_BUFSIZE];
char buf2[8 + SND_PRINT_BITS_ADVISED_BUFSIZE] = ", bits =";
if (!a->format)
return;
hdmi_print_pcm_rates(a->rates, buf, sizeof(buf));
if (a->format == AUDIO_CODING_TYPE_LPCM)
snd_print_pcm_bits(a->sample_bits, buf2 + 8, sizeof(buf2) - 8);
else if (a->max_bitrate)
snprintf(buf2, sizeof(buf2),
", max bitrate = %d", a->max_bitrate);
else
buf2[0] = '\0';
_snd_printd(SND_PR_VERBOSE, "HDMI: supports coding type %s:"
" channels = %d, rates =%s%s\n",
cea_audio_coding_type_names[a->format],
a->channels,
buf,
buf2);
}
void snd_print_channel_allocation(int spk_alloc, char *buf, int buflen)
{
int i, j;
for (i = 0, j = 0; i < ARRAY_SIZE(cea_speaker_allocation_names); i++) {
if (spk_alloc & (1 << i))
j += snprintf(buf + j, buflen - j, " %s",
cea_speaker_allocation_names[i]);
}
buf[j] = '\0';
}
void snd_hdmi_show_eld(struct hdmi_eld *e)
{
int i;
_snd_printd(SND_PR_VERBOSE, "HDMI: detected monitor %s at connection type %s\n",
e->monitor_name,
eld_connection_type_names[e->conn_type]);
if (e->spk_alloc) {
char buf[SND_PRINT_CHANNEL_ALLOCATION_ADVISED_BUFSIZE];
snd_print_channel_allocation(e->spk_alloc, buf, sizeof(buf));
_snd_printd(SND_PR_VERBOSE, "HDMI: available speakers:%s\n", buf);
}
for (i = 0; i < e->sad_count; i++)
hdmi_show_short_audio_desc(e->sad + i);
}
static void hdmi_print_sad_info(int i, struct cea_sad *a,
struct snd_info_buffer *buffer)
{
char buf[SND_PRINT_RATES_ADVISED_BUFSIZE];
snd_iprintf(buffer, "sad%d_coding_type\t[0x%x] %s\n",
i, a->format, cea_audio_coding_type_names[a->format]);
snd_iprintf(buffer, "sad%d_channels\t\t%d\n", i, a->channels);
hdmi_print_pcm_rates(a->rates, buf, sizeof(buf));
snd_iprintf(buffer, "sad%d_rates\t\t[0x%x]%s\n", i, a->rates, buf);
if (a->format == AUDIO_CODING_TYPE_LPCM) {
snd_print_pcm_bits(a->sample_bits, buf, sizeof(buf));
snd_iprintf(buffer, "sad%d_bits\t\t[0x%x]%s\n",
i, a->sample_bits, buf);
}
if (a->max_bitrate)
snd_iprintf(buffer, "sad%d_max_bitrate\t%d\n",
i, a->max_bitrate);
if (a->profile)
snd_iprintf(buffer, "sad%d_profile\t\t%d\n", i, a->profile);
}
static void hdmi_print_eld_info(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdmi_eld *e = entry->private_data;
char buf[SND_PRINT_CHANNEL_ALLOCATION_ADVISED_BUFSIZE];
int i;
static char *eld_versoin_names[32] = {
"reserved",
"reserved",
"CEA-861D or below",
[3 ... 30] = "reserved",
[31] = "partial"
};
static char *cea_edid_version_names[8] = {
"no CEA EDID Timing Extension block present",
"CEA-861",
"CEA-861-A",
"CEA-861-B, C or D",
[4 ... 7] = "reserved"
};
snd_iprintf(buffer, "monitor_present\t\t%d\n", e->monitor_present);
snd_iprintf(buffer, "eld_valid\t\t%d\n", e->eld_valid);
if (!e->eld_valid)
return;
snd_iprintf(buffer, "monitor_name\t\t%s\n", e->monitor_name);
snd_iprintf(buffer, "connection_type\t\t%s\n",
eld_connection_type_names[e->conn_type]);
snd_iprintf(buffer, "eld_version\t\t[0x%x] %s\n", e->eld_ver,
eld_versoin_names[e->eld_ver]);
snd_iprintf(buffer, "edid_version\t\t[0x%x] %s\n", e->cea_edid_ver,
cea_edid_version_names[e->cea_edid_ver]);
snd_iprintf(buffer, "manufacture_id\t\t0x%x\n", e->manufacture_id);
snd_iprintf(buffer, "product_id\t\t0x%x\n", e->product_id);
snd_iprintf(buffer, "port_id\t\t\t0x%llx\n", (long long)e->port_id);
snd_iprintf(buffer, "support_hdcp\t\t%d\n", e->support_hdcp);
snd_iprintf(buffer, "support_ai\t\t%d\n", e->support_ai);
snd_iprintf(buffer, "audio_sync_delay\t%d\n", e->aud_synch_delay);
snd_print_channel_allocation(e->spk_alloc, buf, sizeof(buf));
snd_iprintf(buffer, "speakers\t\t[0x%x]%s\n", e->spk_alloc, buf);
snd_iprintf(buffer, "sad_count\t\t%d\n", e->sad_count);
for (i = 0; i < e->sad_count; i++)
hdmi_print_sad_info(i, e->sad + i, buffer);
}
static void hdmi_write_eld_info(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdmi_eld *e = entry->private_data;
char line[64];
char name[64];
char *sname;
long long val;
unsigned int n;
while (!snd_info_get_line(buffer, line, sizeof(line))) {
if (sscanf(line, "%s %llx", name, &val) != 2)
continue;
if (!strcmp(name, "monitor_present"))
e->monitor_present = val;
else if (!strcmp(name, "eld_valid"))
e->eld_valid = val;
else if (!strcmp(name, "connection_type"))
e->conn_type = val;
else if (!strcmp(name, "port_id"))
e->port_id = val;
else if (!strcmp(name, "support_hdcp"))
e->support_hdcp = val;
else if (!strcmp(name, "support_ai"))
e->support_ai = val;
else if (!strcmp(name, "audio_sync_delay"))
e->aud_synch_delay = val;
else if (!strcmp(name, "speakers"))
e->spk_alloc = val;
else if (!strcmp(name, "sad_count"))
e->sad_count = val;
else if (!strncmp(name, "sad", 3)) {
sname = name + 4;
n = name[3] - '0';
if (name[4] >= '0' && name[4] <= '9') {
sname++;
n = 10 * n + name[4] - '0';
}
if (n >= ELD_MAX_SAD)
continue;
if (!strcmp(sname, "_coding_type"))
e->sad[n].format = val;
else if (!strcmp(sname, "_channels"))
e->sad[n].channels = val;
else if (!strcmp(sname, "_rates"))
e->sad[n].rates = val;
else if (!strcmp(sname, "_bits"))
e->sad[n].sample_bits = val;
else if (!strcmp(sname, "_max_bitrate"))
e->sad[n].max_bitrate = val;
else if (!strcmp(sname, "_profile"))
e->sad[n].profile = val;
if (n >= e->sad_count)
e->sad_count = n + 1;
}
}
}
int snd_hda_eld_proc_new(struct hda_codec *codec, struct hdmi_eld *eld,
int index)
{
char name[32];
struct snd_info_entry *entry;
int err;
snprintf(name, sizeof(name), "eld#%d.%d", codec->addr, index);
err = snd_card_proc_new(codec->bus->card, name, &entry);
if (err < 0)
return err;
snd_info_set_text_ops(entry, eld, hdmi_print_eld_info);
entry->c.text.write = hdmi_write_eld_info;
entry->mode |= S_IWUSR;
eld->proc_entry = entry;
return 0;
}
void snd_hda_eld_proc_free(struct hda_codec *codec, struct hdmi_eld *eld)
{
if (!codec->bus->shutdown && eld->proc_entry) {
snd_device_free(codec->bus->card, eld->proc_entry);
eld->proc_entry = NULL;
}
}
void snd_hdmi_eld_update_pcm_info(struct hdmi_eld *eld,
struct hda_pcm_stream *hinfo)
{
u32 rates;
u64 formats;
unsigned int maxbps;
unsigned int channels_max;
int i;
rates = SNDRV_PCM_RATE_32000 | SNDRV_PCM_RATE_44100 |
SNDRV_PCM_RATE_48000;
formats = SNDRV_PCM_FMTBIT_S16_LE;
maxbps = 16;
channels_max = 2;
for (i = 0; i < eld->sad_count; i++) {
struct cea_sad *a = &eld->sad[i];
rates |= a->rates;
if (a->channels > channels_max)
channels_max = a->channels;
if (a->format == AUDIO_CODING_TYPE_LPCM) {
if (a->sample_bits & AC_SUPPCM_BITS_20) {
formats |= SNDRV_PCM_FMTBIT_S32_LE;
if (maxbps < 20)
maxbps = 20;
}
if (a->sample_bits & AC_SUPPCM_BITS_24) {
formats |= SNDRV_PCM_FMTBIT_S32_LE;
if (maxbps < 24)
maxbps = 24;
}
}
}
hinfo->rates &= rates;
hinfo->formats &= formats;
hinfo->maxbps = min(hinfo->maxbps, maxbps);
hinfo->channels_max = min(hinfo->channels_max, channels_max);
}
