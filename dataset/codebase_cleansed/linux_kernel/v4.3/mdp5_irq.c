void mdp5_set_irqmask(struct mdp_kms *mdp_kms, uint32_t irqmask,
uint32_t old_irqmask)
{
mdp5_write(to_mdp5_kms(mdp_kms), REG_MDP5_MDP_INTR_CLEAR(0),
irqmask ^ (irqmask & old_irqmask));
mdp5_write(to_mdp5_kms(mdp_kms), REG_MDP5_MDP_INTR_EN(0), irqmask);
}
static void mdp5_irq_error_handler(struct mdp_irq *irq, uint32_t irqstatus)
{
DRM_ERROR("errors: %08x\n", irqstatus);
}
void mdp5_irq_preinstall(struct msm_kms *kms)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
mdp5_enable(mdp5_kms);
mdp5_write(mdp5_kms, REG_MDP5_MDP_INTR_CLEAR(0), 0xffffffff);
mdp5_write(mdp5_kms, REG_MDP5_MDP_INTR_EN(0), 0x00000000);
mdp5_disable(mdp5_kms);
}
int mdp5_irq_postinstall(struct msm_kms *kms)
{
struct mdp_kms *mdp_kms = to_mdp_kms(kms);
struct mdp5_kms *mdp5_kms = to_mdp5_kms(mdp_kms);
struct mdp_irq *error_handler = &mdp5_kms->error_handler;
error_handler->irq = mdp5_irq_error_handler;
error_handler->irqmask = MDP5_IRQ_INTF0_UNDER_RUN |
MDP5_IRQ_INTF1_UNDER_RUN |
MDP5_IRQ_INTF2_UNDER_RUN |
MDP5_IRQ_INTF3_UNDER_RUN;
mdp_irq_register(mdp_kms, error_handler);
return 0;
}
void mdp5_irq_uninstall(struct msm_kms *kms)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
mdp5_enable(mdp5_kms);
mdp5_write(mdp5_kms, REG_MDP5_MDP_INTR_EN(0), 0x00000000);
mdp5_disable(mdp5_kms);
}
static void mdp5_irq_mdp(struct mdp_kms *mdp_kms)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(mdp_kms);
struct drm_device *dev = mdp5_kms->dev;
struct msm_drm_private *priv = dev->dev_private;
unsigned int id;
uint32_t status, enable;
enable = mdp5_read(mdp5_kms, REG_MDP5_MDP_INTR_EN(0));
status = mdp5_read(mdp5_kms, REG_MDP5_MDP_INTR_STATUS(0)) & enable;
mdp5_write(mdp5_kms, REG_MDP5_MDP_INTR_CLEAR(0), status);
VERB("status=%08x", status);
mdp_dispatch_irqs(mdp_kms, status);
for (id = 0; id < priv->num_crtcs; id++)
if (status & mdp5_crtc_vblank(priv->crtcs[id]))
drm_handle_vblank(dev, id);
}
irqreturn_t mdp5_irq(struct msm_kms *kms)
{
struct mdp_kms *mdp_kms = to_mdp_kms(kms);
struct mdp5_kms *mdp5_kms = to_mdp5_kms(mdp_kms);
uint32_t intr;
intr = mdp5_read(mdp5_kms, REG_MDSS_HW_INTR_STATUS);
VERB("intr=%08x", intr);
if (intr & MDSS_HW_INTR_STATUS_INTR_MDP) {
mdp5_irq_mdp(mdp_kms);
intr &= ~MDSS_HW_INTR_STATUS_INTR_MDP;
}
while (intr) {
irq_hw_number_t hwirq = fls(intr) - 1;
generic_handle_irq(irq_find_mapping(
mdp5_kms->irqcontroller.domain, hwirq));
intr &= ~(1 << hwirq);
}
return IRQ_HANDLED;
}
int mdp5_enable_vblank(struct msm_kms *kms, struct drm_crtc *crtc)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
mdp5_enable(mdp5_kms);
mdp_update_vblank_mask(to_mdp_kms(kms),
mdp5_crtc_vblank(crtc), true);
mdp5_disable(mdp5_kms);
return 0;
}
void mdp5_disable_vblank(struct msm_kms *kms, struct drm_crtc *crtc)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
mdp5_enable(mdp5_kms);
mdp_update_vblank_mask(to_mdp_kms(kms),
mdp5_crtc_vblank(crtc), false);
mdp5_disable(mdp5_kms);
}
static void mdp5_hw_mask_irq(struct irq_data *irqd)
{
struct mdp5_kms *mdp5_kms = irq_data_get_irq_chip_data(irqd);
smp_mb__before_atomic();
clear_bit(irqd->hwirq, &mdp5_kms->irqcontroller.enabled_mask);
smp_mb__after_atomic();
}
static void mdp5_hw_unmask_irq(struct irq_data *irqd)
{
struct mdp5_kms *mdp5_kms = irq_data_get_irq_chip_data(irqd);
smp_mb__before_atomic();
set_bit(irqd->hwirq, &mdp5_kms->irqcontroller.enabled_mask);
smp_mb__after_atomic();
}
static int mdp5_hw_irqdomain_map(struct irq_domain *d,
unsigned int irq, irq_hw_number_t hwirq)
{
struct mdp5_kms *mdp5_kms = d->host_data;
if (!(VALID_IRQS & (1 << hwirq)))
return -EPERM;
irq_set_chip_and_handler(irq, &mdp5_hw_irq_chip, handle_level_irq);
irq_set_chip_data(irq, mdp5_kms);
return 0;
}
int mdp5_irq_domain_init(struct mdp5_kms *mdp5_kms)
{
struct device *dev = mdp5_kms->dev->dev;
struct irq_domain *d;
d = irq_domain_add_linear(dev->of_node, 32,
&mdp5_hw_irqdomain_ops, mdp5_kms);
if (!d) {
dev_err(dev, "mdp5 irq domain add failed\n");
return -ENXIO;
}
mdp5_kms->irqcontroller.enabled_mask = 0;
mdp5_kms->irqcontroller.domain = d;
return 0;
}
void mdp5_irq_domain_fini(struct mdp5_kms *mdp5_kms)
{
if (mdp5_kms->irqcontroller.domain) {
irq_domain_remove(mdp5_kms->irqcontroller.domain);
mdp5_kms->irqcontroller.domain = NULL;
}
}
