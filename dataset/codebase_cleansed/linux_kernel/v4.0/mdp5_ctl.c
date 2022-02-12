static inline
struct mdp5_kms *get_kms(struct mdp5_ctl_manager *ctl_mgr)
{
struct msm_drm_private *priv = ctl_mgr->dev->dev_private;
return to_mdp5_kms(to_mdp_kms(priv->kms));
}
static inline
void ctl_write(struct mdp5_ctl *ctl, u32 reg, u32 data)
{
struct mdp5_kms *mdp5_kms = get_kms(ctl->ctlm);
(void)ctl->reg_offset;
mdp5_write(mdp5_kms, reg, data);
}
static inline
u32 ctl_read(struct mdp5_ctl *ctl, u32 reg)
{
struct mdp5_kms *mdp5_kms = get_kms(ctl->ctlm);
(void)ctl->reg_offset;
return mdp5_read(mdp5_kms, reg);
}
int mdp5_ctl_set_intf(struct mdp5_ctl *ctl, int intf)
{
unsigned long flags;
static const enum mdp5_intfnum intfnum[] = {
INTF0, INTF1, INTF2, INTF3,
};
spin_lock_irqsave(&ctl->hw_lock, flags);
ctl_write(ctl, REG_MDP5_CTL_OP(ctl->id),
MDP5_CTL_OP_MODE(ctl->mode) |
MDP5_CTL_OP_INTF_NUM(intfnum[intf]));
spin_unlock_irqrestore(&ctl->hw_lock, flags);
return 0;
}
int mdp5_ctl_set_cursor(struct mdp5_ctl *ctl, bool enable)
{
struct mdp5_ctl_manager *ctl_mgr = ctl->ctlm;
unsigned long flags;
u32 blend_cfg;
int lm;
lm = mdp5_crtc_get_lm(ctl->crtc);
if (unlikely(WARN_ON(lm < 0))) {
dev_err(ctl_mgr->dev->dev, "CTL %d cannot find LM: %d",
ctl->id, lm);
return -EINVAL;
}
spin_lock_irqsave(&ctl->hw_lock, flags);
blend_cfg = ctl_read(ctl, REG_MDP5_CTL_LAYER_REG(ctl->id, lm));
if (enable)
blend_cfg |= MDP5_CTL_LAYER_REG_CURSOR_OUT;
else
blend_cfg &= ~MDP5_CTL_LAYER_REG_CURSOR_OUT;
ctl_write(ctl, REG_MDP5_CTL_LAYER_REG(ctl->id, lm), blend_cfg);
spin_unlock_irqrestore(&ctl->hw_lock, flags);
ctl->cursor_on = enable;
return 0;
}
int mdp5_ctl_blend(struct mdp5_ctl *ctl, u32 lm, u32 blend_cfg)
{
unsigned long flags;
if (ctl->cursor_on)
blend_cfg |= MDP5_CTL_LAYER_REG_CURSOR_OUT;
else
blend_cfg &= ~MDP5_CTL_LAYER_REG_CURSOR_OUT;
spin_lock_irqsave(&ctl->hw_lock, flags);
ctl_write(ctl, REG_MDP5_CTL_LAYER_REG(ctl->id, lm), blend_cfg);
spin_unlock_irqrestore(&ctl->hw_lock, flags);
return 0;
}
int mdp5_ctl_commit(struct mdp5_ctl *ctl, u32 flush_mask)
{
struct mdp5_ctl_manager *ctl_mgr = ctl->ctlm;
unsigned long flags;
if (flush_mask & MDP5_CTL_FLUSH_CURSOR_DUMMY) {
int lm = mdp5_crtc_get_lm(ctl->crtc);
if (unlikely(WARN_ON(lm < 0))) {
dev_err(ctl_mgr->dev->dev, "CTL %d cannot find LM: %d",
ctl->id, lm);
return -EINVAL;
}
flush_mask |= mdp_ctl_flush_mask_lm(lm);
}
spin_lock_irqsave(&ctl->hw_lock, flags);
ctl_write(ctl, REG_MDP5_CTL_FLUSH(ctl->id), flush_mask);
spin_unlock_irqrestore(&ctl->hw_lock, flags);
return 0;
}
u32 mdp5_ctl_get_flush(struct mdp5_ctl *ctl)
{
return ctl->flush_mask;
}
void mdp5_ctl_release(struct mdp5_ctl *ctl)
{
struct mdp5_ctl_manager *ctl_mgr = ctl->ctlm;
unsigned long flags;
if (unlikely(WARN_ON(ctl->id >= MAX_CTL) || !ctl->busy)) {
dev_err(ctl_mgr->dev->dev, "CTL %d in bad state (%d)",
ctl->id, ctl->busy);
return;
}
spin_lock_irqsave(&ctl_mgr->pool_lock, flags);
ctl->busy = false;
spin_unlock_irqrestore(&ctl_mgr->pool_lock, flags);
DBG("CTL %d released", ctl->id);
}
struct mdp5_ctl *mdp5_ctlm_request(struct mdp5_ctl_manager *ctl_mgr,
struct drm_crtc *crtc)
{
struct mdp5_ctl *ctl = NULL;
unsigned long flags;
int c;
spin_lock_irqsave(&ctl_mgr->pool_lock, flags);
for (c = 0; c < ctl_mgr->nctl; c++)
if (!ctl_mgr->ctls[c].busy)
break;
if (unlikely(c >= ctl_mgr->nctl)) {
dev_err(ctl_mgr->dev->dev, "No more CTL available!");
goto unlock;
}
ctl = &ctl_mgr->ctls[c];
ctl->crtc = crtc;
ctl->busy = true;
DBG("CTL %d allocated", ctl->id);
unlock:
spin_unlock_irqrestore(&ctl_mgr->pool_lock, flags);
return ctl;
}
void mdp5_ctlm_hw_reset(struct mdp5_ctl_manager *ctl_mgr)
{
unsigned long flags;
int c;
for (c = 0; c < ctl_mgr->nctl; c++) {
struct mdp5_ctl *ctl = &ctl_mgr->ctls[c];
spin_lock_irqsave(&ctl->hw_lock, flags);
ctl_write(ctl, REG_MDP5_CTL_OP(ctl->id), 0);
spin_unlock_irqrestore(&ctl->hw_lock, flags);
}
}
void mdp5_ctlm_destroy(struct mdp5_ctl_manager *ctl_mgr)
{
kfree(ctl_mgr);
}
struct mdp5_ctl_manager *mdp5_ctlm_init(struct drm_device *dev,
void __iomem *mmio_base, const struct mdp5_cfg_hw *hw_cfg)
{
struct mdp5_ctl_manager *ctl_mgr;
const struct mdp5_sub_block *ctl_cfg = &hw_cfg->ctl;
unsigned long flags;
int c, ret;
ctl_mgr = kzalloc(sizeof(*ctl_mgr), GFP_KERNEL);
if (!ctl_mgr) {
dev_err(dev->dev, "failed to allocate CTL manager\n");
ret = -ENOMEM;
goto fail;
}
if (unlikely(WARN_ON(ctl_cfg->count > MAX_CTL))) {
dev_err(dev->dev, "Increase static pool size to at least %d\n",
ctl_cfg->count);
ret = -ENOSPC;
goto fail;
}
ctl_mgr->dev = dev;
ctl_mgr->nlm = hw_cfg->lm.count;
ctl_mgr->nctl = ctl_cfg->count;
spin_lock_init(&ctl_mgr->pool_lock);
spin_lock_irqsave(&ctl_mgr->pool_lock, flags);
for (c = 0; c < ctl_mgr->nctl; c++) {
struct mdp5_ctl *ctl = &ctl_mgr->ctls[c];
if (WARN_ON(!ctl_cfg->base[c])) {
dev_err(dev->dev, "CTL_%d: base is null!\n", c);
ret = -EINVAL;
goto fail;
}
ctl->ctlm = ctl_mgr;
ctl->id = c;
ctl->mode = MODE_NONE;
ctl->reg_offset = ctl_cfg->base[c];
ctl->flush_mask = MDP5_CTL_FLUSH_CTL;
ctl->busy = false;
spin_lock_init(&ctl->hw_lock);
}
spin_unlock_irqrestore(&ctl_mgr->pool_lock, flags);
DBG("Pool of %d CTLs created.", ctl_mgr->nctl);
return ctl_mgr;
fail:
if (ctl_mgr)
mdp5_ctlm_destroy(ctl_mgr);
return ERR_PTR(ret);
}
