void
dsp_audio_generate_ulaw_samples(void)
{
int i, j;
i = 0;
while (samples[i].len) {
j = 0;
while (j < (*samples[i].len)) {
samples[i].data[j] =
dsp_audio_alaw_to_ulaw[samples[i].data[j]];
j++;
}
i++;
}
}
void dsp_tone_copy(struct dsp *dsp, u8 *data, int len)
{
int index, count, start, num;
struct pattern *pat;
struct dsp_tone *tone = &dsp->tone;
if (!tone->tone) {
memset(data, dsp_silence, len);
return;
}
pat = (struct pattern *)tone->pattern;
index = tone->index;
count = tone->count;
while (len) {
while (42) {
if (!pat->seq[index]) {
count = 0;
index = 0;
}
if (count < pat->seq[index])
break;
if (dsp_debug & DEBUG_DSP_TONE)
printk(KERN_DEBUG "%s: reaching next sequence "
"(index=%d)\n", __func__, index);
count -= pat->seq[index];
index++;
}
start = count % (*(pat->siz[index]));
num = len;
if (num + count > pat->seq[index])
num = pat->seq[index] - count;
if (num + start > (*(pat->siz[index])))
num = (*(pat->siz[index])) - start;
memcpy(data, pat->data[index] + start, num);
data += num;
count += num;
len -= num;
}
tone->index = index;
tone->count = count;
return;
}
static void
dsp_tone_hw_message(struct dsp *dsp, u8 *sample, int len)
{
struct sk_buff *nskb;
nskb = _alloc_mISDN_skb(PH_CONTROL_REQ,
(len) ? HFC_SPL_LOOP_ON : HFC_SPL_LOOP_OFF, len, sample,
GFP_ATOMIC);
if (nskb) {
if (dsp->ch.peer) {
if (dsp->ch.recv(dsp->ch.peer, nskb))
dev_kfree_skb(nskb);
} else
dev_kfree_skb(nskb);
}
}
void
dsp_tone_timeout(void *arg)
{
struct dsp *dsp = arg;
struct dsp_tone *tone = &dsp->tone;
struct pattern *pat = (struct pattern *)tone->pattern;
int index = tone->index;
if (!tone->tone)
return;
index++;
if (!pat->seq[index])
index = 0;
tone->index = index;
if (pat->data[index] == DATA_S)
dsp_tone_hw_message(dsp, NULL, 0);
else
dsp_tone_hw_message(dsp, pat->data[index], *(pat->siz[index]));
init_timer(&tone->tl);
tone->tl.expires = jiffies + (pat->seq[index] * HZ) / 8000;
add_timer(&tone->tl);
}
int
dsp_tone(struct dsp *dsp, int tone)
{
struct pattern *pat;
int i;
struct dsp_tone *tonet = &dsp->tone;
tonet->software = 0;
tonet->hardware = 0;
if (!tone) {
if (dsp->features.hfc_loops && timer_pending(&tonet->tl))
del_timer(&tonet->tl);
if (dsp->features.hfc_loops)
dsp_tone_hw_message(dsp, NULL, 0);
tonet->tone = 0;
return 0;
}
pat = NULL;
i = 0;
while (pattern[i].tone) {
if (pattern[i].tone == tone) {
pat = &pattern[i];
break;
}
i++;
}
if (!pat) {
printk(KERN_WARNING "dsp: given tone 0x%x is invalid\n", tone);
return -EINVAL;
}
if (dsp_debug & DEBUG_DSP_TONE)
printk(KERN_DEBUG "%s: now starting tone %d (index=%d)\n",
__func__, tone, 0);
tonet->tone = tone;
tonet->pattern = pat;
tonet->index = 0;
tonet->count = 0;
if (dsp->features.hfc_loops) {
tonet->hardware = 1;
dsp_tone_hw_message(dsp, pat->data[0], *(pat->siz[0]));
if (timer_pending(&tonet->tl))
del_timer(&tonet->tl);
init_timer(&tonet->tl);
tonet->tl.expires = jiffies + (pat->seq[0] * HZ) / 8000;
add_timer(&tonet->tl);
} else {
tonet->software = 1;
}
return 0;
}
