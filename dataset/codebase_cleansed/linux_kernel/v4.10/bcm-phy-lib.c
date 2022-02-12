int bcm_phy_write_exp(struct phy_device *phydev, u16 reg, u16 val)
{
int rc;
rc = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
if (rc < 0)
return rc;
return phy_write(phydev, MII_BCM54XX_EXP_DATA, val);
}
int bcm_phy_read_exp(struct phy_device *phydev, u16 reg)
{
int val;
val = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
if (val < 0)
return val;
val = phy_read(phydev, MII_BCM54XX_EXP_DATA);
phy_write(phydev, MII_BCM54XX_EXP_SEL, 0);
return val;
}
int bcm54xx_auxctl_read(struct phy_device *phydev, u16 regnum)
{
phy_write(phydev, MII_BCM54XX_AUX_CTL, regnum |
regnum << MII_BCM54XX_AUXCTL_SHDWSEL_READ_SHIFT);
return phy_read(phydev, MII_BCM54XX_AUX_CTL);
}
int bcm54xx_auxctl_write(struct phy_device *phydev, u16 regnum, u16 val)
{
return phy_write(phydev, MII_BCM54XX_AUX_CTL, regnum | val);
}
int bcm_phy_write_misc(struct phy_device *phydev,
u16 reg, u16 chl, u16 val)
{
int rc;
int tmp;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL,
MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
if (rc < 0)
return rc;
tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
if (rc < 0)
return rc;
tmp = (chl * MII_BCM_CHANNEL_WIDTH) | reg;
rc = bcm_phy_write_exp(phydev, tmp, val);
return rc;
}
int bcm_phy_read_misc(struct phy_device *phydev,
u16 reg, u16 chl)
{
int rc;
int tmp;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL,
MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
if (rc < 0)
return rc;
tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
if (rc < 0)
return rc;
tmp = (chl * MII_BCM_CHANNEL_WIDTH) | reg;
rc = bcm_phy_read_exp(phydev, tmp);
return rc;
}
int bcm_phy_ack_intr(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BCM54XX_ISR);
if (reg < 0)
return reg;
return 0;
}
int bcm_phy_config_intr(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BCM54XX_ECR);
if (reg < 0)
return reg;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
reg &= ~MII_BCM54XX_ECR_IM;
else
reg |= MII_BCM54XX_ECR_IM;
return phy_write(phydev, MII_BCM54XX_ECR, reg);
}
int bcm_phy_read_shadow(struct phy_device *phydev, u16 shadow)
{
phy_write(phydev, MII_BCM54XX_SHD, MII_BCM54XX_SHD_VAL(shadow));
return MII_BCM54XX_SHD_DATA(phy_read(phydev, MII_BCM54XX_SHD));
}
int bcm_phy_write_shadow(struct phy_device *phydev, u16 shadow,
u16 val)
{
return phy_write(phydev, MII_BCM54XX_SHD,
MII_BCM54XX_SHD_WRITE |
MII_BCM54XX_SHD_VAL(shadow) |
MII_BCM54XX_SHD_DATA(val));
}
int bcm_phy_enable_apd(struct phy_device *phydev, bool dll_pwr_down)
{
int val;
if (dll_pwr_down) {
val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR3);
if (val < 0)
return val;
val |= BCM54XX_SHD_SCR3_DLLAPD_DIS;
bcm_phy_write_shadow(phydev, BCM54XX_SHD_SCR3, val);
}
val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_APD);
if (val < 0)
return val;
val &= BCM_APD_CLR_MASK;
if (phydev->autoneg == AUTONEG_ENABLE)
val |= BCM54XX_SHD_APD_EN;
else
val |= BCM_NO_ANEG_APD_EN;
val |= BCM_APD_SINGLELP_EN;
return bcm_phy_write_shadow(phydev, BCM54XX_SHD_APD, val);
}
int bcm_phy_set_eee(struct phy_device *phydev, bool enable)
{
int val;
val = phy_read_mmd_indirect(phydev, BRCM_CL45VEN_EEE_CONTROL,
MDIO_MMD_AN);
if (val < 0)
return val;
if (enable)
val |= LPI_FEATURE_EN | LPI_FEATURE_EN_DIG1000X;
else
val &= ~(LPI_FEATURE_EN | LPI_FEATURE_EN_DIG1000X);
phy_write_mmd_indirect(phydev, BRCM_CL45VEN_EEE_CONTROL,
MDIO_MMD_AN, (u32)val);
val = phy_read_mmd_indirect(phydev, BCM_CL45VEN_EEE_ADV,
MDIO_MMD_AN);
if (val < 0)
return val;
if (enable)
val |= (MDIO_AN_EEE_ADV_100TX | MDIO_AN_EEE_ADV_1000T);
else
val &= ~(MDIO_AN_EEE_ADV_100TX | MDIO_AN_EEE_ADV_1000T);
phy_write_mmd_indirect(phydev, BCM_CL45VEN_EEE_ADV,
MDIO_MMD_AN, (u32)val);
return 0;
}
int bcm_phy_downshift_get(struct phy_device *phydev, u8 *count)
{
int val;
val = bcm54xx_auxctl_read(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
if (val < 0)
return val;
if (!(val & MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN)) {
*count = DOWNSHIFT_DEV_DISABLE;
return 0;
}
val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR2);
if (val < 0)
return val;
if (val & BCM54XX_SHD_SCR2_WSPD_RTRY_DIS) {
*count = 1;
} else {
val >>= BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT;
val &= BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK;
*count = val + BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET;
}
return 0;
}
int bcm_phy_downshift_set(struct phy_device *phydev, u8 count)
{
int val = 0, ret = 0;
if (count - BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET >
BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK &&
count != DOWNSHIFT_DEV_DEFAULT_COUNT) {
return -ERANGE;
}
val = bcm54xx_auxctl_read(phydev, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
if (val < 0)
return val;
val |= MII_BCM54XX_AUXCTL_MISC_WREN;
if (count == DOWNSHIFT_DEV_DISABLE) {
val &= ~MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN;
return bcm54xx_auxctl_write(phydev,
MII_BCM54XX_AUXCTL_SHDWSEL_MISC,
val);
} else {
val |= MII_BCM54XX_AUXCTL_SHDWSEL_MISC_WIRESPEED_EN;
ret = bcm54xx_auxctl_write(phydev,
MII_BCM54XX_AUXCTL_SHDWSEL_MISC,
val);
if (ret < 0)
return ret;
}
val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR2);
val &= ~(BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_MASK <<
BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT |
BCM54XX_SHD_SCR2_WSPD_RTRY_DIS);
switch (count) {
case 1:
val |= BCM54XX_SHD_SCR2_WSPD_RTRY_DIS;
break;
case DOWNSHIFT_DEV_DEFAULT_COUNT:
val |= 1 << BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT;
break;
default:
val |= (count - BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_OFFSET) <<
BCM54XX_SHD_SCR2_WSPD_RTRY_LMT_SHIFT;
break;
}
return bcm_phy_write_shadow(phydev, BCM54XX_SHD_SCR2, val);
}
int bcm_phy_get_sset_count(struct phy_device *phydev)
{
return ARRAY_SIZE(bcm_phy_hw_stats);
}
void bcm_phy_get_strings(struct phy_device *phydev, u8 *data)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bcm_phy_hw_stats); i++)
memcpy(data + i * ETH_GSTRING_LEN,
bcm_phy_hw_stats[i].string, ETH_GSTRING_LEN);
}
static u64 bcm_phy_get_stat(struct phy_device *phydev, u64 *shadow,
unsigned int i)
{
struct bcm_phy_hw_stat stat = bcm_phy_hw_stats[i];
int val;
u64 ret;
val = phy_read(phydev, stat.reg);
if (val < 0) {
ret = UINT64_MAX;
} else {
val >>= stat.shift;
val = val & ((1 << stat.bits) - 1);
shadow[i] += val;
ret = shadow[i];
}
return ret;
}
void bcm_phy_get_stats(struct phy_device *phydev, u64 *shadow,
struct ethtool_stats *stats, u64 *data)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bcm_phy_hw_stats); i++)
data[i] = bcm_phy_get_stat(phydev, shadow, i);
}
