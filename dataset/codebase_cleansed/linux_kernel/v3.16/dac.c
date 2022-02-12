int nv04_dac_output_offset(struct drm_encoder *encoder)
{
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
int offset = 0;
if (dcb->or & (8 | DCB_OUTPUT_C))
offset += 0x68;
if (dcb->or & (8 | DCB_OUTPUT_B))
offset += 0x2000;
return offset;
}
static int sample_load_twice(struct drm_device *dev, bool sense[2])
{
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_timer *ptimer = nouveau_timer(device);
int i;
for (i = 0; i < 2; i++) {
bool sense_a, sense_b, sense_b_prime;
int j = 0;
if (!nouveau_timer_wait_eq(ptimer, 10000000,
NV_PRMCIO_INP0__COLOR,
0x00000001, 0x00000000))
return -EBUSY;
if (!nouveau_timer_wait_eq(ptimer, 10000000,
NV_PRMCIO_INP0__COLOR,
0x00000001, 0x00000001))
return -EBUSY;
if (!nouveau_timer_wait_eq(ptimer, 10000000,
NV_PRMCIO_INP0__COLOR,
0x00000001, 0x00000000))
return -EBUSY;
udelay(100);
sense_a = nv_rd08(device, NV_PRMCIO_INP0) & 0x10;
do {
udelay(100);
sense_b = nv_rd08(device, NV_PRMCIO_INP0) & 0x10;
if (sense_a != sense_b) {
sense_b_prime =
nv_rd08(device, NV_PRMCIO_INP0) & 0x10;
if (sense_b == sense_b_prime) {
sense_a = sense_b;
sense_b = !sense_a;
}
}
} while ((sense_a != sense_b) && ++j < MAX_HBLANK_OSC);
if (j == MAX_HBLANK_OSC)
sense[i] = false;
else
sense[i] = sense_a;
}
return 0;
}
static enum drm_connector_status nv04_dac_detect(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct drm_device *dev = encoder->dev;
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_drm *drm = nouveau_drm(dev);
uint8_t saved_seq1, saved_pi, saved_rpc1, saved_cr_mode;
uint8_t saved_palette0[3], saved_palette_mask;
uint32_t saved_rtest_ctrl, saved_rgen_ctrl;
int i;
uint8_t blue;
bool sense = true;
if (nv_two_heads(dev))
NVSetOwner(dev, 0);
saved_cr_mode = NVReadVgaCrtc(dev, 0, NV_CIO_CR_MODE_INDEX);
NVWriteVgaCrtc(dev, 0, NV_CIO_CR_MODE_INDEX, saved_cr_mode | 0x80);
saved_seq1 = NVReadVgaSeq(dev, 0, NV_VIO_SR_CLOCK_INDEX);
NVWriteVgaSeq(dev, 0, NV_VIO_SR_CLOCK_INDEX, saved_seq1 & ~0x20);
saved_rtest_ctrl = NVReadRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL,
saved_rtest_ctrl & ~NV_PRAMDAC_TEST_CONTROL_PWRDWN_DAC_OFF);
msleep(10);
saved_pi = NVReadVgaCrtc(dev, 0, NV_CIO_CRE_PIXEL_INDEX);
NVWriteVgaCrtc(dev, 0, NV_CIO_CRE_PIXEL_INDEX,
saved_pi & ~(0x80 | MASK(NV_CIO_CRE_PIXEL_FORMAT)));
saved_rpc1 = NVReadVgaCrtc(dev, 0, NV_CIO_CRE_RPC1_INDEX);
NVWriteVgaCrtc(dev, 0, NV_CIO_CRE_RPC1_INDEX, saved_rpc1 & ~0xc0);
nv_wr08(device, NV_PRMDIO_READ_MODE_ADDRESS, 0x0);
for (i = 0; i < 3; i++)
saved_palette0[i] = nv_rd08(device, NV_PRMDIO_PALETTE_DATA);
saved_palette_mask = nv_rd08(device, NV_PRMDIO_PIXEL_MASK);
nv_wr08(device, NV_PRMDIO_PIXEL_MASK, 0);
saved_rgen_ctrl = NVReadRAMDAC(dev, 0, NV_PRAMDAC_GENERAL_CONTROL);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_GENERAL_CONTROL,
(saved_rgen_ctrl & ~(NV_PRAMDAC_GENERAL_CONTROL_BPC_8BITS |
NV_PRAMDAC_GENERAL_CONTROL_TERMINATION_75OHM)) |
NV_PRAMDAC_GENERAL_CONTROL_PIXMIX_ON);
blue = 8;
do {
bool sense_pair[2];
nv_wr08(device, NV_PRMDIO_WRITE_MODE_ADDRESS, 0);
nv_wr08(device, NV_PRMDIO_PALETTE_DATA, 0);
nv_wr08(device, NV_PRMDIO_PALETTE_DATA, 0);
nv_wr08(device, NV_PRMDIO_PALETTE_DATA, blue);
i = 0;
do {
if (sample_load_twice(dev, sense_pair))
goto out;
} while ((sense_pair[0] != sense_pair[1]) &&
++i < MAX_SAMPLE_PAIRS);
if (i == MAX_SAMPLE_PAIRS)
sense = false;
else
sense = sense_pair[0];
} while (++blue < 0x18 && sense);
out:
nv_wr08(device, NV_PRMDIO_PIXEL_MASK, saved_palette_mask);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_GENERAL_CONTROL, saved_rgen_ctrl);
nv_wr08(device, NV_PRMDIO_WRITE_MODE_ADDRESS, 0);
for (i = 0; i < 3; i++)
nv_wr08(device, NV_PRMDIO_PALETTE_DATA, saved_palette0[i]);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL, saved_rtest_ctrl);
NVWriteVgaCrtc(dev, 0, NV_CIO_CRE_PIXEL_INDEX, saved_pi);
NVWriteVgaCrtc(dev, 0, NV_CIO_CRE_RPC1_INDEX, saved_rpc1);
NVWriteVgaSeq(dev, 0, NV_VIO_SR_CLOCK_INDEX, saved_seq1);
NVWriteVgaCrtc(dev, 0, NV_CIO_CR_MODE_INDEX, saved_cr_mode);
if (blue == 0x18) {
NV_DEBUG(drm, "Load detected on head A\n");
return connector_status_connected;
}
return connector_status_disconnected;
}
uint32_t nv17_dac_sample_load(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_gpio *gpio = nouveau_gpio(device);
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
uint32_t sample, testval, regoffset = nv04_dac_output_offset(encoder);
uint32_t saved_powerctrl_2 = 0, saved_powerctrl_4 = 0, saved_routput,
saved_rtest_ctrl, saved_gpio0 = 0, saved_gpio1 = 0, temp, routput;
int head;
#define RGB_TEST_DATA(r, g, b) (r << 0 | g << 10 | b << 20)
if (dcb->type == DCB_OUTPUT_TV) {
testval = RGB_TEST_DATA(0xa0, 0xa0, 0xa0);
if (drm->vbios.tvdactestval)
testval = drm->vbios.tvdactestval;
} else {
testval = RGB_TEST_DATA(0x140, 0x140, 0x140);
if (drm->vbios.dactestval)
testval = drm->vbios.dactestval;
}
saved_rtest_ctrl = NVReadRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + regoffset);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + regoffset,
saved_rtest_ctrl & ~NV_PRAMDAC_TEST_CONTROL_PWRDWN_DAC_OFF);
saved_powerctrl_2 = nv_rd32(device, NV_PBUS_POWERCTRL_2);
nv_wr32(device, NV_PBUS_POWERCTRL_2, saved_powerctrl_2 & 0xd7ffffff);
if (regoffset == 0x68) {
saved_powerctrl_4 = nv_rd32(device, NV_PBUS_POWERCTRL_4);
nv_wr32(device, NV_PBUS_POWERCTRL_4, saved_powerctrl_4 & 0xffffffcf);
}
if (gpio) {
saved_gpio1 = gpio->get(gpio, 0, DCB_GPIO_TVDAC1, 0xff);
saved_gpio0 = gpio->get(gpio, 0, DCB_GPIO_TVDAC0, 0xff);
gpio->set(gpio, 0, DCB_GPIO_TVDAC1, 0xff, dcb->type == DCB_OUTPUT_TV);
gpio->set(gpio, 0, DCB_GPIO_TVDAC0, 0xff, dcb->type == DCB_OUTPUT_TV);
}
msleep(4);
saved_routput = NVReadRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + regoffset);
head = (saved_routput & 0x100) >> 8;
if (!(NVReadVgaCrtc(dev, head, NV_CIO_CRE_RPC1_INDEX) & 0xC0))
head ^= 1;
routput = (saved_routput & 0xfffffece) | head << 8;
if (nv_device(drm->device)->card_type >= NV_40) {
if (dcb->type == DCB_OUTPUT_TV)
routput |= 0x1a << 16;
else
routput &= ~(0x1a << 16);
}
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + regoffset, routput);
msleep(1);
temp = NVReadRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + regoffset);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + regoffset, temp | 1);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_TESTPOINT_DATA,
NV_PRAMDAC_TESTPOINT_DATA_NOTBLANK | testval);
temp = NVReadRAMDAC(dev, head, NV_PRAMDAC_TEST_CONTROL);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_TEST_CONTROL,
temp | NV_PRAMDAC_TEST_CONTROL_TP_INS_EN_ASSERTED);
msleep(5);
sample = NVReadRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + regoffset);
sample &= NVReadRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + regoffset);
temp = NVReadRAMDAC(dev, head, NV_PRAMDAC_TEST_CONTROL);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_TEST_CONTROL,
temp & ~NV_PRAMDAC_TEST_CONTROL_TP_INS_EN_ASSERTED);
NVWriteRAMDAC(dev, head, NV_PRAMDAC_TESTPOINT_DATA, 0);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + regoffset, saved_routput);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + regoffset, saved_rtest_ctrl);
if (regoffset == 0x68)
nv_wr32(device, NV_PBUS_POWERCTRL_4, saved_powerctrl_4);
nv_wr32(device, NV_PBUS_POWERCTRL_2, saved_powerctrl_2);
if (gpio) {
gpio->set(gpio, 0, DCB_GPIO_TVDAC1, 0xff, saved_gpio1);
gpio->set(gpio, 0, DCB_GPIO_TVDAC0, 0xff, saved_gpio0);
}
return sample;
}
static enum drm_connector_status
nv17_dac_detect(struct drm_encoder *encoder, struct drm_connector *connector)
{
struct nouveau_drm *drm = nouveau_drm(encoder->dev);
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
if (nv04_dac_in_use(encoder))
return connector_status_disconnected;
if (nv17_dac_sample_load(encoder) &
NV_PRAMDAC_TEST_CONTROL_SENSEB_ALLHI) {
NV_DEBUG(drm, "Load detected on output %c\n",
'@' + ffs(dcb->or));
return connector_status_connected;
} else {
return connector_status_disconnected;
}
}
static bool nv04_dac_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
if (nv04_dac_in_use(encoder))
return false;
return true;
}
static void nv04_dac_prepare(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *helper = encoder->helper_private;
struct drm_device *dev = encoder->dev;
int head = nouveau_crtc(encoder->crtc)->index;
helper->dpms(encoder, DRM_MODE_DPMS_OFF);
nv04_dfp_disable(dev, head);
}
static void nv04_dac_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
int head = nouveau_crtc(encoder->crtc)->index;
if (nv_gf4_disp_arch(dev)) {
struct drm_encoder *rebind;
uint32_t dac_offset = nv04_dac_output_offset(encoder);
uint32_t otherdac;
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + dac_offset,
head << 8 | NV_PRAMDAC_DACCLK_SEL_DACCLK);
list_for_each_entry(rebind, &dev->mode_config.encoder_list, head) {
if (rebind == encoder
|| nouveau_encoder(rebind)->dcb->type != DCB_OUTPUT_ANALOG)
continue;
dac_offset = nv04_dac_output_offset(rebind);
otherdac = NVReadRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + dac_offset);
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + dac_offset,
(otherdac & ~0x0100) | (head ^ 1) << 8);
}
}
if (nv_device(drm->device)->chipset < 0x44)
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + nv04_dac_output_offset(encoder), 0xf0000000);
else
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + nv04_dac_output_offset(encoder), 0x00100000);
}
static void nv04_dac_commit(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct nouveau_drm *drm = nouveau_drm(encoder->dev);
struct nouveau_crtc *nv_crtc = nouveau_crtc(encoder->crtc);
struct drm_encoder_helper_funcs *helper = encoder->helper_private;
helper->dpms(encoder, DRM_MODE_DPMS_ON);
NV_DEBUG(drm, "Output %s is running on CRTC %d using output %c\n",
nouveau_encoder_connector_get(nv_encoder)->base.name,
nv_crtc->index, '@' + ffs(nv_encoder->dcb->or));
}
void nv04_dac_update_dacclk(struct drm_encoder *encoder, bool enable)
{
struct drm_device *dev = encoder->dev;
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
if (nv_gf4_disp_arch(dev)) {
uint32_t *dac_users = &nv04_display(dev)->dac_users[ffs(dcb->or) - 1];
int dacclk_off = NV_PRAMDAC_DACCLK + nv04_dac_output_offset(encoder);
uint32_t dacclk = NVReadRAMDAC(dev, 0, dacclk_off);
if (enable) {
*dac_users |= 1 << dcb->index;
NVWriteRAMDAC(dev, 0, dacclk_off, dacclk | NV_PRAMDAC_DACCLK_SEL_DACCLK);
} else {
*dac_users &= ~(1 << dcb->index);
if (!*dac_users)
NVWriteRAMDAC(dev, 0, dacclk_off,
dacclk & ~NV_PRAMDAC_DACCLK_SEL_DACCLK);
}
}
}
bool nv04_dac_in_use(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
return nv_gf4_disp_arch(encoder->dev) &&
(nv04_display(dev)->dac_users[ffs(dcb->or) - 1] & ~(1 << dcb->index));
}
static void nv04_dac_dpms(struct drm_encoder *encoder, int mode)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct nouveau_drm *drm = nouveau_drm(encoder->dev);
if (nv_encoder->last_dpms == mode)
return;
nv_encoder->last_dpms = mode;
NV_DEBUG(drm, "Setting dpms mode %d on vga encoder (output %d)\n",
mode, nv_encoder->dcb->index);
nv04_dac_update_dacclk(encoder, mode == DRM_MODE_DPMS_ON);
}
static void nv04_dac_save(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct drm_device *dev = encoder->dev;
if (nv_gf4_disp_arch(dev))
nv_encoder->restore.output = NVReadRAMDAC(dev, 0, NV_PRAMDAC_DACCLK +
nv04_dac_output_offset(encoder));
}
static void nv04_dac_restore(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct drm_device *dev = encoder->dev;
if (nv_gf4_disp_arch(dev))
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_DACCLK + nv04_dac_output_offset(encoder),
nv_encoder->restore.output);
nv_encoder->last_dpms = NV_DPMS_CLEARED;
}
static void nv04_dac_destroy(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(nv_encoder);
}
int
nv04_dac_create(struct drm_connector *connector, struct dcb_output *entry)
{
const struct drm_encoder_helper_funcs *helper;
struct nouveau_encoder *nv_encoder = NULL;
struct drm_device *dev = connector->dev;
struct drm_encoder *encoder;
nv_encoder = kzalloc(sizeof(*nv_encoder), GFP_KERNEL);
if (!nv_encoder)
return -ENOMEM;
encoder = to_drm_encoder(nv_encoder);
nv_encoder->dcb = entry;
nv_encoder->or = ffs(entry->or) - 1;
if (nv_gf4_disp_arch(dev))
helper = &nv17_dac_helper_funcs;
else
helper = &nv04_dac_helper_funcs;
drm_encoder_init(dev, encoder, &nv04_dac_funcs, DRM_MODE_ENCODER_DAC);
drm_encoder_helper_add(encoder, helper);
encoder->possible_crtcs = entry->heads;
encoder->possible_clones = 0;
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
