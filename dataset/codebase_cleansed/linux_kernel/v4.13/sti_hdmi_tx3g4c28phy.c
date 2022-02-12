static bool sti_hdmi_tx3g4c28phy_start(struct sti_hdmi *hdmi)
{
u32 ckpxpll = hdmi->mode.clock * 1000;
u32 val, tmdsck, idf, odf, pllctrl = 0;
bool foundplldivides = false;
int i;
DRM_DEBUG_DRIVER("ckpxpll = %dHz\n", ckpxpll);
for (i = 0; i < NB_PLL_MODE; i++) {
if (ckpxpll >= plldividers[i].min &&
ckpxpll < plldividers[i].max) {
idf = plldividers[i].idf;
odf = plldividers[i].odf;
foundplldivides = true;
break;
}
}
if (!foundplldivides) {
DRM_ERROR("input TMDS clock speed (%d) not supported\n",
ckpxpll);
goto err;
}
tmdsck = ckpxpll;
pllctrl |= 40 << PLL_CFG_NDIV_SHIFT;
if (tmdsck > 340000000) {
DRM_ERROR("output TMDS clock (%d) out of range\n", tmdsck);
goto err;
}
pllctrl |= idf << PLL_CFG_IDF_SHIFT;
pllctrl |= odf << PLL_CFG_ODF_SHIFT;
hdmi->event_received = false;
DRM_DEBUG_DRIVER("pllctrl = 0x%x\n", pllctrl);
hdmi_write(hdmi, (pllctrl | PLL_CFG_EN), HDMI_SRZ_PLL_CFG);
wait_event_interruptible_timeout(hdmi->wait_event,
hdmi->event_received == true,
msecs_to_jiffies
(HDMI_TIMEOUT_PLL_LOCK));
if ((hdmi_read(hdmi, HDMI_STA) & HDMI_STA_DLL_LCK) == 0) {
DRM_ERROR("hdmi phy pll not locked\n");
goto err;
}
DRM_DEBUG_DRIVER("got PHY PLL Lock\n");
val = (HDMI_SRZ_CFG_EN |
HDMI_SRZ_CFG_EXTERNAL_DATA |
HDMI_SRZ_CFG_EN_BIASRES_DETECTION |
HDMI_SRZ_CFG_EN_SINK_TERM_DETECTION);
if (tmdsck > 165000000)
val |= HDMI_SRZ_CFG_EN_SRC_TERMINATION;
for (i = 0; i < NB_HDMI_PHY_CONFIG; i++) {
if ((hdmiphy_config[i].min_tmds_freq <= tmdsck) &&
(hdmiphy_config[i].max_tmds_freq >= tmdsck)) {
val |= (hdmiphy_config[i].config[0]
& ~HDMI_SRZ_CFG_INTERNAL_MASK);
hdmi_write(hdmi, val, HDMI_SRZ_CFG);
val = hdmiphy_config[i].config[1];
hdmi_write(hdmi, val, HDMI_SRZ_ICNTL);
val = hdmiphy_config[i].config[2];
hdmi_write(hdmi, val, HDMI_SRZ_CALCODE_EXT);
DRM_DEBUG_DRIVER("serializer cfg 0x%x 0x%x 0x%x\n",
hdmiphy_config[i].config[0],
hdmiphy_config[i].config[1],
hdmiphy_config[i].config[2]);
return true;
}
}
hdmi_write(hdmi, val, HDMI_SRZ_CFG);
hdmi_write(hdmi, 0x0, HDMI_SRZ_ICNTL);
hdmi_write(hdmi, 0x0, HDMI_SRZ_CALCODE_EXT);
return true;
err:
return false;
}
static void sti_hdmi_tx3g4c28phy_stop(struct sti_hdmi *hdmi)
{
int val = 0;
DRM_DEBUG_DRIVER("\n");
hdmi->event_received = false;
val = HDMI_SRZ_CFG_EN_SINK_TERM_DETECTION;
val |= HDMI_SRZ_CFG_EN_BIASRES_DETECTION;
hdmi_write(hdmi, val, HDMI_SRZ_CFG);
hdmi_write(hdmi, 0, HDMI_SRZ_PLL_CFG);
wait_event_interruptible_timeout(hdmi->wait_event,
hdmi->event_received == true,
msecs_to_jiffies
(HDMI_TIMEOUT_PLL_LOCK));
if (hdmi_read(hdmi, HDMI_STA) & HDMI_STA_DLL_LCK)
DRM_ERROR("hdmi phy pll not well disabled\n");
}
