static bool disable_pll_rejection(struct sti_hdmi *hdmi)
{
u32 val;
DRM_DEBUG_DRIVER("\n");
val = readl(hdmi->syscfg + HDMI_REJECTION_PLL_CONFIGURATION);
val &= ~REJECTION_PLL_HDMI_ENABLE_MASK;
writel(val, hdmi->syscfg + HDMI_REJECTION_PLL_CONFIGURATION);
msleep(PLL_CHANGE_DELAY);
val = readl(hdmi->syscfg + HDMI_REJECTION_PLL_STATUS);
return !(val & REJECTION_PLL_HDMI_REJ_PLL_LOCK);
}
static bool enable_pll_rejection(struct sti_hdmi *hdmi)
{
unsigned int inputclock;
u32 mdiv, ndiv, pdiv, val;
DRM_DEBUG_DRIVER("\n");
if (!disable_pll_rejection(hdmi))
return false;
inputclock = hdmi->mode.clock * 1000;
DRM_DEBUG_DRIVER("hdmi rejection pll input clock = %dHz\n", inputclock);
if (inputclock < 50000000) {
pdiv = 4;
ndiv = 240;
mdiv = 30;
} else {
pdiv = 2;
ndiv = 60;
mdiv = 30;
}
val = readl(hdmi->syscfg + HDMI_REJECTION_PLL_CONFIGURATION);
val &= ~(REJECTION_PLL_HDMI_PDIV_MASK |
REJECTION_PLL_HDMI_NDIV_MASK |
REJECTION_PLL_HDMI_MDIV_MASK |
REJECTION_PLL_HDMI_ENABLE_MASK);
val |= (pdiv << REJECTION_PLL_HDMI_PDIV_SHIFT) |
(ndiv << REJECTION_PLL_HDMI_NDIV_SHIFT) |
(mdiv << REJECTION_PLL_HDMI_MDIV_SHIFT) |
(0x1 << REJECTION_PLL_HDMI_ENABLE_SHIFT);
writel(val, hdmi->syscfg + HDMI_REJECTION_PLL_CONFIGURATION);
msleep(PLL_CHANGE_DELAY);
val = readl(hdmi->syscfg + HDMI_REJECTION_PLL_STATUS);
return (val & REJECTION_PLL_HDMI_REJ_PLL_LOCK);
}
static bool sti_hdmi_tx3g0c55phy_start(struct sti_hdmi *hdmi)
{
u32 ckpxpll = hdmi->mode.clock * 1000;
u32 val, tmdsck, freqvco, pllctrl = 0;
unsigned int i;
if (!enable_pll_rejection(hdmi))
return false;
DRM_DEBUG_DRIVER("ckpxpll = %dHz\n", ckpxpll);
tmdsck = ckpxpll;
pllctrl = 2 << HDMI_SRZ_PLL_CFG_NDIV_SHIFT;
for (i = 0; i < NB_PLL_MODE; i++) {
if (ckpxpll >= pllmodes[i].min && ckpxpll <= pllmodes[i].max)
pllctrl |= HDMI_SRZ_PLL_CFG_MODE(pllmodes[i].mode);
}
freqvco = tmdsck * 10;
if (freqvco <= 425000000UL)
pllctrl |= HDMI_SRZ_PLL_CFG_VCOR(HDMI_SRZ_PLL_CFG_VCOR_425MHZ);
else if (freqvco <= 850000000UL)
pllctrl |= HDMI_SRZ_PLL_CFG_VCOR(HDMI_SRZ_PLL_CFG_VCOR_850MHZ);
else if (freqvco <= 1700000000UL)
pllctrl |= HDMI_SRZ_PLL_CFG_VCOR(HDMI_SRZ_PLL_CFG_VCOR_1700MHZ);
else if (freqvco <= 2970000000UL)
pllctrl |= HDMI_SRZ_PLL_CFG_VCOR(HDMI_SRZ_PLL_CFG_VCOR_3000MHZ);
else {
DRM_ERROR("PHY serializer clock out of range\n");
goto err;
}
hdmi->event_received = false;
DRM_DEBUG_DRIVER("pllctrl = 0x%x\n", pllctrl);
hdmi_write(hdmi, pllctrl, HDMI_SRZ_PLL_CFG);
wait_event_interruptible_timeout(hdmi->wait_event,
hdmi->event_received == true,
msecs_to_jiffies
(HDMI_TIMEOUT_PLL_LOCK));
if ((hdmi_read(hdmi, HDMI_STA) & HDMI_STA_DLL_LCK) == 0) {
DRM_ERROR("hdmi phy pll not locked\n");
goto err;
}
DRM_DEBUG_DRIVER("got PHY PLL Lock\n");
for (i = 0; i < NB_HDMI_PHY_CONFIG; i++) {
if ((hdmiphy_config[i].min_tmds_freq <= tmdsck) &&
(hdmiphy_config[i].max_tmds_freq >= tmdsck)) {
val = hdmiphy_config[i].config[0];
hdmi_write(hdmi, val, HDMI_SRZ_TAP_1);
val = hdmiphy_config[i].config[1];
hdmi_write(hdmi, val, HDMI_SRZ_TAP_2);
val = hdmiphy_config[i].config[2];
hdmi_write(hdmi, val, HDMI_SRZ_TAP_3);
val = hdmiphy_config[i].config[3];
val |= HDMI_SRZ_CTRL_EXTERNAL_DATA_EN;
val &= ~HDMI_SRZ_CTRL_POWER_DOWN;
hdmi_write(hdmi, val, HDMI_SRZ_CTRL);
DRM_DEBUG_DRIVER("serializer cfg 0x%x 0x%x 0x%x 0x%x\n",
hdmiphy_config[i].config[0],
hdmiphy_config[i].config[1],
hdmiphy_config[i].config[2],
hdmiphy_config[i].config[3]);
return true;
}
}
hdmi_write(hdmi, 0x0, HDMI_SRZ_TAP_1);
hdmi_write(hdmi, 0x0, HDMI_SRZ_TAP_2);
hdmi_write(hdmi, 0x0, HDMI_SRZ_TAP_3);
hdmi_write(hdmi, HDMI_SRZ_CTRL_EXTERNAL_DATA_EN, HDMI_SRZ_CTRL);
return true;
err:
disable_pll_rejection(hdmi);
return false;
}
static void sti_hdmi_tx3g0c55phy_stop(struct sti_hdmi *hdmi)
{
DRM_DEBUG_DRIVER("\n");
hdmi->event_received = false;
hdmi_write(hdmi, HDMI_SRZ_CTRL_POWER_DOWN, HDMI_SRZ_CTRL);
hdmi_write(hdmi, HDMI_SRZ_PLL_CFG_POWER_DOWN, HDMI_SRZ_PLL_CFG);
wait_event_interruptible_timeout(hdmi->wait_event,
hdmi->event_received == true,
msecs_to_jiffies
(HDMI_TIMEOUT_PLL_LOCK));
if (hdmi_read(hdmi, HDMI_STA) & HDMI_STA_DLL_LCK)
DRM_ERROR("hdmi phy pll not well disabled\n");
disable_pll_rejection(hdmi);
}
