static void phy_write(struct hdmi_phy_8x74 *phy, u32 reg, u32 data)
{
msm_writel(data, phy->mmio + reg);
}
static void hdmi_phy_8x74_destroy(struct hdmi_phy *phy)
{
struct hdmi_phy_8x74 *phy_8x74 = to_hdmi_phy_8x74(phy);
kfree(phy_8x74);
}
static void hdmi_phy_8x74_powerup(struct hdmi_phy *phy,
unsigned long int pixclock)
{
struct hdmi_phy_8x74 *phy_8x74 = to_hdmi_phy_8x74(phy);
phy_write(phy_8x74, REG_HDMI_8x74_ANA_CFG0, 0x1b);
phy_write(phy_8x74, REG_HDMI_8x74_ANA_CFG1, 0xf2);
phy_write(phy_8x74, REG_HDMI_8x74_BIST_CFG0, 0x0);
phy_write(phy_8x74, REG_HDMI_8x74_BIST_PATN0, 0x0);
phy_write(phy_8x74, REG_HDMI_8x74_BIST_PATN1, 0x0);
phy_write(phy_8x74, REG_HDMI_8x74_BIST_PATN2, 0x0);
phy_write(phy_8x74, REG_HDMI_8x74_BIST_PATN3, 0x0);
phy_write(phy_8x74, REG_HDMI_8x74_PD_CTRL1, 0x20);
}
static void hdmi_phy_8x74_powerdown(struct hdmi_phy *phy)
{
struct hdmi_phy_8x74 *phy_8x74 = to_hdmi_phy_8x74(phy);
phy_write(phy_8x74, REG_HDMI_8x74_PD_CTRL0, 0x7f);
}
struct hdmi_phy *hdmi_phy_8x74_init(struct hdmi *hdmi)
{
struct hdmi_phy_8x74 *phy_8x74;
struct hdmi_phy *phy = NULL;
int ret;
phy_8x74 = kzalloc(sizeof(*phy_8x74), GFP_KERNEL);
if (!phy_8x74) {
ret = -ENOMEM;
goto fail;
}
phy = &phy_8x74->base;
phy->funcs = &hdmi_phy_8x74_funcs;
phy_8x74->mmio = msm_ioremap(hdmi->pdev,
"phy_physical", "HDMI_8x74");
if (IS_ERR(phy_8x74->mmio)) {
ret = PTR_ERR(phy_8x74->mmio);
goto fail;
}
return phy;
fail:
if (phy)
hdmi_phy_8x74_destroy(phy);
return ERR_PTR(ret);
}
