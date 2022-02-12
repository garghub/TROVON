static int get_right_pair_idx(struct mdp5_kms *mdp5_kms, int lm)
{
int i;
int pair_lm;
pair_lm = lm_right_pair[lm];
if (pair_lm < 0)
return -EINVAL;
for (i = 0; i < mdp5_kms->num_hwmixers; i++) {
struct mdp5_hw_mixer *mixer = mdp5_kms->hwmixers[i];
if (mixer->lm == pair_lm)
return mixer->idx;
}
return -1;
}
int mdp5_mixer_assign(struct drm_atomic_state *s, struct drm_crtc *crtc,
uint32_t caps, struct mdp5_hw_mixer **mixer,
struct mdp5_hw_mixer **r_mixer)
{
struct msm_drm_private *priv = s->dev->dev_private;
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(priv->kms));
struct mdp5_state *state = mdp5_get_state(s);
struct mdp5_hw_mixer_state *new_state;
int i;
if (IS_ERR(state))
return PTR_ERR(state);
new_state = &state->hwmixer;
for (i = 0; i < mdp5_kms->num_hwmixers; i++) {
struct mdp5_hw_mixer *cur = mdp5_kms->hwmixers[i];
if (new_state->hwmixer_to_crtc[cur->idx] &&
new_state->hwmixer_to_crtc[cur->idx] != crtc)
continue;
if (caps & ~cur->caps)
continue;
if (r_mixer) {
int pair_idx;
pair_idx = get_right_pair_idx(mdp5_kms, cur->lm);
if (pair_idx < 0)
return -EINVAL;
if (new_state->hwmixer_to_crtc[pair_idx])
continue;
*r_mixer = mdp5_kms->hwmixers[pair_idx];
}
if (!(*mixer) || cur->caps & MDP_LM_CAP_PAIR)
*mixer = cur;
}
if (!(*mixer))
return -ENOMEM;
if (r_mixer && !(*r_mixer))
return -ENOMEM;
DBG("assigning Layer Mixer %d to crtc %s", (*mixer)->lm, crtc->name);
new_state->hwmixer_to_crtc[(*mixer)->idx] = crtc;
if (r_mixer) {
DBG("assigning Right Layer Mixer %d to crtc %s", (*r_mixer)->lm,
crtc->name);
new_state->hwmixer_to_crtc[(*r_mixer)->idx] = crtc;
}
return 0;
}
void mdp5_mixer_release(struct drm_atomic_state *s, struct mdp5_hw_mixer *mixer)
{
struct mdp5_state *state = mdp5_get_state(s);
struct mdp5_hw_mixer_state *new_state = &state->hwmixer;
if (!mixer)
return;
if (WARN_ON(!new_state->hwmixer_to_crtc[mixer->idx]))
return;
DBG("%s: release from crtc %s", mixer->name,
new_state->hwmixer_to_crtc[mixer->idx]->name);
new_state->hwmixer_to_crtc[mixer->idx] = NULL;
}
void mdp5_mixer_destroy(struct mdp5_hw_mixer *mixer)
{
kfree(mixer);
}
struct mdp5_hw_mixer *mdp5_mixer_init(const struct mdp5_lm_instance *lm)
{
struct mdp5_hw_mixer *mixer;
mixer = kzalloc(sizeof(*mixer), GFP_KERNEL);
if (!mixer)
return ERR_PTR(-ENOMEM);
mixer->name = mixer_names[lm->id];
mixer->lm = lm->id;
mixer->caps = lm->caps;
mixer->pp = lm->pp;
mixer->dspp = lm->dspp;
mixer->flush_mask = mdp_ctl_flush_mask_lm(lm->id);
return mixer;
}
