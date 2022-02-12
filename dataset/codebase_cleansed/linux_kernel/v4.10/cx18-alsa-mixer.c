static inline int dB_to_cx18_av_vol(int dB)
{
if (dB < -96)
dB = -96;
else if (dB > 8)
dB = 8;
return (dB + 119) << 9;
}
static inline int cx18_av_vol_to_dB(int v)
{
if (v < (23 << 9))
v = (23 << 9);
else if (v > (127 << 9))
v = (127 << 9);
return (v >> 9) - 119;
}
static int snd_cx18_mixer_tv_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = -96;
uinfo->value.integer.max = 8;
uinfo->value.integer.step = 1;
return 0;
}
static int snd_cx18_mixer_tv_vol_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uctl)
{
struct snd_cx18_card *cxsc = snd_kcontrol_chip(kctl);
struct cx18 *cx = to_cx18(cxsc->v4l2_dev);
struct v4l2_control vctrl;
int ret;
vctrl.id = V4L2_CID_AUDIO_VOLUME;
vctrl.value = dB_to_cx18_av_vol(uctl->value.integer.value[0]);
snd_cx18_lock(cxsc);
ret = v4l2_g_ctrl(cx->sd_av->ctrl_handler, &vctrl);
snd_cx18_unlock(cxsc);
if (!ret)
uctl->value.integer.value[0] = cx18_av_vol_to_dB(vctrl.value);
return ret;
}
static int snd_cx18_mixer_tv_vol_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uctl)
{
struct snd_cx18_card *cxsc = snd_kcontrol_chip(kctl);
struct cx18 *cx = to_cx18(cxsc->v4l2_dev);
struct v4l2_control vctrl;
int ret;
vctrl.id = V4L2_CID_AUDIO_VOLUME;
vctrl.value = dB_to_cx18_av_vol(uctl->value.integer.value[0]);
snd_cx18_lock(cxsc);
ret = v4l2_g_ctrl(cx->sd_av->ctrl_handler, &vctrl);
if (ret ||
(cx18_av_vol_to_dB(vctrl.value) != uctl->value.integer.value[0])) {
vctrl.value = dB_to_cx18_av_vol(uctl->value.integer.value[0]);
ret = v4l2_s_ctrl(cx->sd_av->ctrl_handler, &vctrl);
if (!ret)
ret = 1;
}
snd_cx18_unlock(cxsc);
return ret;
}
int __init snd_cx18_mixer_create(struct snd_cx18_card *cxsc)
{
struct v4l2_device *v4l2_dev = cxsc->v4l2_dev;
struct snd_card *sc = cxsc->sc;
int ret;
strlcpy(sc->mixername, "CX23418 Mixer", sizeof(sc->mixername));
ret = snd_ctl_add(sc, snd_ctl_new1(snd_cx18_mixer_tv_vol, cxsc));
if (ret) {
CX18_ALSA_WARN("%s: failed to add %s control, err %d\n",
__func__, snd_cx18_mixer_tv_vol.name, ret);
}
return ret;
}
