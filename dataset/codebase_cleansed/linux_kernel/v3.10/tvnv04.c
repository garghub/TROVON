int nv04_tv_identify(struct drm_device *dev, int i2c_index)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_i2c *i2c = nouveau_i2c(drm->device);
return i2c->identify(i2c, i2c_index, "TV encoder",
nv04_tv_encoder_info, NULL);
}
static void nv04_tv_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct nv04_mode_state *state = &nv04_display(dev)->mode_reg;
uint8_t crtc1A;
NV_DEBUG(drm, "Setting dpms mode %d on TV encoder (output %d)\n",
mode, nv_encoder->dcb->index);
state->pllsel &= ~(PLLSEL_TV_CRTC1_MASK | PLLSEL_TV_CRTC2_MASK);
if (mode == DRM_MODE_DPMS_ON) {
int head = nouveau_crtc(encoder->crtc)->index;
crtc1A = NVReadVgaCrtc(dev, head, NV_CIO_CRE_RPC1_INDEX);
state->pllsel |= head ? PLLSEL_TV_CRTC2_MASK :
PLLSEL_TV_CRTC1_MASK;
crtc1A |= 0x80;
NVWriteVgaCrtc(dev, head, NV_CIO_CRE_RPC1_INDEX, crtc1A);
}
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_PLL_COEFF_SELECT, state->pllsel);
get_slave_funcs(encoder)->dpms(encoder, mode);
}
static void nv04_tv_bind(struct drm_device *dev, int head, bool bind)
{
struct nv04_crtc_reg *state = &nv04_display(dev)->mode_reg.crtc_reg[head];
state->tv_setup = 0;
if (bind)
state->CRTC[NV_CIO_CRE_49] |= 0x10;
else
state->CRTC[NV_CIO_CRE_49] &= ~0x10;
NVWriteVgaCrtc(dev, head, NV_CIO_CRE_LCD__INDEX,
state->CRTC[NV_CIO_CRE_LCD__INDEX]);
NVWriteVgaCrtc(dev, head, NV_CIO_CRE_49,
state->CRTC[NV_CIO_CRE_49]);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_TV_SETUP,
state->tv_setup);
}
static void nv04_tv_prepare(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
int head = nouveau_crtc(encoder->crtc)->index;
struct drm_encoder_helper_funcs *helper = encoder->helper_private;
helper->dpms(encoder, DRM_MODE_DPMS_OFF);
nv04_dfp_disable(dev, head);
if (nv_two_heads(dev))
nv04_tv_bind(dev, head ^ 1, false);
nv04_tv_bind(dev, head, true);
}
static void nv04_tv_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct nouveau_crtc *nv_crtc = nouveau_crtc(encoder->crtc);
struct nv04_crtc_reg *regp = &nv04_display(dev)->mode_reg.crtc_reg[nv_crtc->index];
regp->tv_htotal = adjusted_mode->htotal;
regp->tv_vtotal = adjusted_mode->vtotal;
regp->tv_hskew = 1;
regp->tv_hsync_delay = 1;
regp->tv_hsync_delay2 = 64;
regp->tv_vskew = 1;
regp->tv_vsync_delay = 1;
get_slave_funcs(encoder)->mode_set(encoder, mode, adjusted_mode);
}
static void nv04_tv_commit(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct drm_device *dev = encoder->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_crtc *nv_crtc = nouveau_crtc(encoder->crtc);
struct drm_encoder_helper_funcs *helper = encoder->helper_private;
helper->dpms(encoder, DRM_MODE_DPMS_ON);
NV_DEBUG(drm, "Output %s is running on CRTC %d using output %c\n",
drm_get_connector_name(&nouveau_encoder_connector_get(nv_encoder)->base), nv_crtc->index, '@' + ffs(nv_encoder->dcb->or));
}
static void nv04_tv_destroy(struct drm_encoder *encoder)
{
get_slave_funcs(encoder)->destroy(encoder);
drm_encoder_cleanup(encoder);
kfree(encoder->helper_private);
kfree(nouveau_encoder(encoder));
}
int
nv04_tv_create(struct drm_connector *connector, struct dcb_output *entry)
{
struct nouveau_encoder *nv_encoder;
struct drm_encoder *encoder;
struct drm_device *dev = connector->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_i2c *i2c = nouveau_i2c(drm->device);
struct nouveau_i2c_port *port = i2c->find(i2c, entry->i2c_index);
int type, ret;
type = nv04_tv_identify(dev, entry->i2c_index);
if (type < 0)
return type;
nv_encoder = kzalloc(sizeof(*nv_encoder), GFP_KERNEL);
if (!nv_encoder)
return -ENOMEM;
encoder = to_drm_encoder(nv_encoder);
drm_encoder_init(dev, encoder, &nv04_tv_funcs, DRM_MODE_ENCODER_TVDAC);
drm_encoder_helper_add(encoder, &nv04_tv_helper_funcs);
encoder->possible_crtcs = entry->heads;
encoder->possible_clones = 0;
nv_encoder->dcb = entry;
nv_encoder->or = ffs(entry->or) - 1;
ret = drm_i2c_encoder_init(dev, to_encoder_slave(encoder),
&port->adapter, &nv04_tv_encoder_info[type]);
if (ret < 0)
goto fail_cleanup;
get_slave_funcs(encoder)->create_resources(encoder, connector);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
fail_cleanup:
drm_encoder_cleanup(encoder);
kfree(nv_encoder);
return ret;
}
