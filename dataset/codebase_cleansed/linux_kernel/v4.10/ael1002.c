static int set_phy_regs(struct cphy *phy, const struct reg_val *rv)
{
int err;
for (err = 0; rv->mmd_addr && !err; rv++) {
if (rv->clear_bits == 0xffff)
err = t3_mdio_write(phy, rv->mmd_addr, rv->reg_addr,
rv->set_bits);
else
err = t3_mdio_change_bits(phy, rv->mmd_addr,
rv->reg_addr, rv->clear_bits,
rv->set_bits);
}
return err;
}
static void ael100x_txon(struct cphy *phy)
{
int tx_on_gpio =
phy->mdio.prtad == 0 ? F_GPIO7_OUT_VAL : F_GPIO2_OUT_VAL;
msleep(100);
t3_set_reg_field(phy->adapter, A_T3DBG_GPIO_EN, 0, tx_on_gpio);
msleep(30);
}
static int ael_i2c_rd(struct cphy *phy, int dev_addr, int word_addr)
{
int i, err;
unsigned int stat, data;
err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL_I2C_CTRL,
(dev_addr << 8) | (1 << 8) | word_addr);
if (err)
return err;
for (i = 0; i < 200; i++) {
msleep(1);
err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL_I2C_STAT, &stat);
if (err)
return err;
if ((stat & 3) == 1) {
err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL_I2C_DATA,
&data);
if (err)
return err;
return data >> 8;
}
}
CH_WARN(phy->adapter, "PHY %u i2c read of dev.addr %#x.%#x timed out\n",
phy->mdio.prtad, dev_addr, word_addr);
return -ETIMEDOUT;
}
static int ael1002_power_down(struct cphy *phy, int enable)
{
int err;
err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, MDIO_PMA_TXDIS, !!enable);
if (!err)
err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
MDIO_MMD_PMAPMD, MDIO_CTRL1,
MDIO_CTRL1_LPOWER, enable);
return err;
}
static int ael1002_reset(struct cphy *phy, int wait)
{
int err;
if ((err = ael1002_power_down(phy, 0)) ||
(err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL100X_TX_CONFIG1, 1)) ||
(err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL1002_PWR_DOWN_HI, 0)) ||
(err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL1002_PWR_DOWN_LO, 0)) ||
(err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL1002_XFI_EQL, 0x18)) ||
(err = t3_mdio_change_bits(phy, MDIO_MMD_PMAPMD, AEL1002_LB_EN,
0, 1 << 5)))
return err;
return 0;
}
static int ael1002_intr_noop(struct cphy *phy)
{
return 0;
}
static int get_link_status_r(struct cphy *phy, int *link_ok, int *speed,
int *duplex, int *fc)
{
if (link_ok) {
unsigned int stat0, stat1, stat2;
int err = t3_mdio_read(phy, MDIO_MMD_PMAPMD,
MDIO_PMA_RXDET, &stat0);
if (!err)
err = t3_mdio_read(phy, MDIO_MMD_PCS,
MDIO_PCS_10GBRT_STAT1, &stat1);
if (!err)
err = t3_mdio_read(phy, MDIO_MMD_PHYXS,
MDIO_PHYXS_LNSTAT, &stat2);
if (err)
return err;
*link_ok = (stat0 & stat1 & (stat2 >> 12)) & 1;
}
if (speed)
*speed = SPEED_10000;
if (duplex)
*duplex = DUPLEX_FULL;
return 0;
}
int t3_ael1002_phy_prep(struct cphy *phy, struct adapter *adapter,
int phy_addr, const struct mdio_ops *mdio_ops)
{
cphy_init(phy, adapter, phy_addr, &ael1002_ops, mdio_ops,
SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE,
"10GBASE-R");
ael100x_txon(phy);
return 0;
}
static int ael1006_reset(struct cphy *phy, int wait)
{
return t3_phy_reset(phy, MDIO_MMD_PMAPMD, wait);
}
int t3_ael1006_phy_prep(struct cphy *phy, struct adapter *adapter,
int phy_addr, const struct mdio_ops *mdio_ops)
{
cphy_init(phy, adapter, phy_addr, &ael1006_ops, mdio_ops,
SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE,
"10GBASE-SR");
ael100x_txon(phy);
return 0;
}
static int ael2xxx_get_module_type(struct cphy *phy, int delay_ms)
{
int v;
if (delay_ms)
msleep(delay_ms);
v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 3);
if (v < 0)
return v;
if (v == 0x10)
return phy_modtype_sr;
if (v == 0x20)
return phy_modtype_lr;
if (v == 0x40)
return phy_modtype_lrm;
v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 6);
if (v < 0)
return v;
if (v != 4)
goto unknown;
v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 10);
if (v < 0)
return v;
if (v & 0x80) {
v = ael_i2c_rd(phy, MODULE_DEV_ADDR, 0x12);
if (v < 0)
return v;
return v > 10 ? phy_modtype_twinax_long : phy_modtype_twinax;
}
unknown:
return phy_modtype_unknown;
}
static int ael2005_setup_sr_edc(struct cphy *phy)
{
static const struct reg_val regs[] = {
{ MDIO_MMD_PMAPMD, 0xc003, 0xffff, 0x181 },
{ MDIO_MMD_PMAPMD, 0xc010, 0xffff, 0x448a },
{ MDIO_MMD_PMAPMD, 0xc04a, 0xffff, 0x5200 },
{ 0, 0, 0, 0 }
};
int i, err;
err = set_phy_regs(phy, regs);
if (err)
return err;
msleep(50);
if (phy->priv != edc_sr)
err = t3_get_edc_fw(phy, EDC_OPT_AEL2005,
EDC_OPT_AEL2005_SIZE);
if (err)
return err;
for (i = 0; i < EDC_OPT_AEL2005_SIZE / sizeof(u16) && !err; i += 2)
err = t3_mdio_write(phy, MDIO_MMD_PMAPMD,
phy->phy_cache[i],
phy->phy_cache[i + 1]);
if (!err)
phy->priv = edc_sr;
return err;
}
static int ael2005_setup_twinax_edc(struct cphy *phy, int modtype)
{
static const struct reg_val regs[] = {
{ MDIO_MMD_PMAPMD, 0xc04a, 0xffff, 0x5a00 },
{ 0, 0, 0, 0 }
};
static const struct reg_val preemphasis[] = {
{ MDIO_MMD_PMAPMD, 0xc014, 0xffff, 0xfe16 },
{ MDIO_MMD_PMAPMD, 0xc015, 0xffff, 0xa000 },
{ 0, 0, 0, 0 }
};
int i, err;
err = set_phy_regs(phy, regs);
if (!err && modtype == phy_modtype_twinax_long)
err = set_phy_regs(phy, preemphasis);
if (err)
return err;
msleep(50);
if (phy->priv != edc_twinax)
err = t3_get_edc_fw(phy, EDC_TWX_AEL2005,
EDC_TWX_AEL2005_SIZE);
if (err)
return err;
for (i = 0; i < EDC_TWX_AEL2005_SIZE / sizeof(u16) && !err; i += 2)
err = t3_mdio_write(phy, MDIO_MMD_PMAPMD,
phy->phy_cache[i],
phy->phy_cache[i + 1]);
if (!err)
phy->priv = edc_twinax;
return err;
}
static int ael2005_get_module_type(struct cphy *phy, int delay_ms)
{
int v;
unsigned int stat;
v = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, &stat);
if (v)
return v;
if (stat & (1 << 8))
return phy_modtype_none;
return ael2xxx_get_module_type(phy, delay_ms);
}
static int ael2005_intr_enable(struct cphy *phy)
{
int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, 0x200);
return err ? err : t3_phy_lasi_intr_enable(phy);
}
static int ael2005_intr_disable(struct cphy *phy)
{
int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, 0x100);
return err ? err : t3_phy_lasi_intr_disable(phy);
}
static int ael2005_intr_clear(struct cphy *phy)
{
int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL, 0xd00);
return err ? err : t3_phy_lasi_intr_clear(phy);
}
static int ael2005_reset(struct cphy *phy, int wait)
{
static const struct reg_val regs0[] = {
{ MDIO_MMD_PMAPMD, 0xc001, 0, 1 << 5 },
{ MDIO_MMD_PMAPMD, 0xc017, 0, 1 << 5 },
{ MDIO_MMD_PMAPMD, 0xc013, 0xffff, 0xf341 },
{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0x8000 },
{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0x8100 },
{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0x8000 },
{ MDIO_MMD_PMAPMD, 0xc210, 0xffff, 0 },
{ 0, 0, 0, 0 }
};
static const struct reg_val regs1[] = {
{ MDIO_MMD_PMAPMD, 0xca00, 0xffff, 0x0080 },
{ MDIO_MMD_PMAPMD, 0xca12, 0xffff, 0 },
{ 0, 0, 0, 0 }
};
int err;
unsigned int lasi_ctrl;
err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL,
&lasi_ctrl);
if (err)
return err;
err = t3_phy_reset(phy, MDIO_MMD_PMAPMD, 0);
if (err)
return err;
msleep(125);
phy->priv = edc_none;
err = set_phy_regs(phy, regs0);
if (err)
return err;
msleep(50);
err = ael2005_get_module_type(phy, 0);
if (err < 0)
return err;
phy->modtype = err;
if (err == phy_modtype_twinax || err == phy_modtype_twinax_long)
err = ael2005_setup_twinax_edc(phy, err);
else
err = ael2005_setup_sr_edc(phy);
if (err)
return err;
err = set_phy_regs(phy, regs1);
if (err)
return err;
if (lasi_ctrl & 1)
err = ael2005_intr_enable(phy);
return err;
}
static int ael2005_intr_handler(struct cphy *phy)
{
unsigned int stat;
int ret, edc_needed, cause = 0;
ret = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_STAT, &stat);
if (ret)
return ret;
if (stat & AEL2005_MODDET_IRQ) {
ret = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AEL2005_GPIO_CTRL,
0xd00);
if (ret)
return ret;
ret = ael2005_get_module_type(phy, 300);
if (ret < 0)
return ret;
phy->modtype = ret;
if (ret == phy_modtype_none)
edc_needed = phy->priv;
else if (ret == phy_modtype_twinax ||
ret == phy_modtype_twinax_long)
edc_needed = edc_twinax;
else
edc_needed = edc_sr;
if (edc_needed != phy->priv) {
ret = ael2005_reset(phy, 0);
return ret ? ret : cphy_cause_module_change;
}
cause = cphy_cause_module_change;
}
ret = t3_phy_lasi_intr_handler(phy);
if (ret < 0)
return ret;
ret |= cause;
return ret ? ret : cphy_cause_link_change;
}
int t3_ael2005_phy_prep(struct cphy *phy, struct adapter *adapter,
int phy_addr, const struct mdio_ops *mdio_ops)
{
cphy_init(phy, adapter, phy_addr, &ael2005_ops, mdio_ops,
SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE |
SUPPORTED_IRQ, "10GBASE-R");
msleep(125);
return t3_mdio_change_bits(phy, MDIO_MMD_PMAPMD, AEL_OPT_SETTINGS, 0,
1 << 5);
}
static int ael2020_setup_sr_edc(struct cphy *phy)
{
static const struct reg_val regs[] = {
{ MDIO_MMD_PMAPMD, 0xcc01, 0xffff, 0x488a },
{ MDIO_MMD_PMAPMD, 0xcb1b, 0xffff, 0x0200 },
{ MDIO_MMD_PMAPMD, 0xcb1c, 0xffff, 0x00f0 },
{ MDIO_MMD_PMAPMD, 0xcc06, 0xffff, 0x00e0 },
{ 0, 0, 0, 0 }
};
int err;
err = set_phy_regs(phy, regs);
msleep(50);
if (err)
return err;
phy->priv = edc_sr;
return 0;
}
static int ael2020_setup_twinax_edc(struct cphy *phy, int modtype)
{
static const struct reg_val uCclock40MHz[] = {
{ MDIO_MMD_PMAPMD, 0xff28, 0xffff, 0x4001 },
{ MDIO_MMD_PMAPMD, 0xff2a, 0xffff, 0x0002 },
{ 0, 0, 0, 0 }
};
static const struct reg_val uCclockActivate[] = {
{ MDIO_MMD_PMAPMD, 0xd000, 0xffff, 0x5200 },
{ 0, 0, 0, 0 }
};
static const struct reg_val uCactivate[] = {
{ MDIO_MMD_PMAPMD, 0xd080, 0xffff, 0x0100 },
{ MDIO_MMD_PMAPMD, 0xd092, 0xffff, 0x0000 },
{ 0, 0, 0, 0 }
};
int i, err;
err = set_phy_regs(phy, uCclock40MHz);
msleep(500);
if (err)
return err;
err = set_phy_regs(phy, uCclockActivate);
msleep(500);
if (err)
return err;
if (phy->priv != edc_twinax)
err = t3_get_edc_fw(phy, EDC_TWX_AEL2020,
EDC_TWX_AEL2020_SIZE);
if (err)
return err;
for (i = 0; i < EDC_TWX_AEL2020_SIZE / sizeof(u16) && !err; i += 2)
err = t3_mdio_write(phy, MDIO_MMD_PMAPMD,
phy->phy_cache[i],
phy->phy_cache[i + 1]);
err = set_phy_regs(phy, uCactivate);
if (!err)
phy->priv = edc_twinax;
return err;
}
static int ael2020_get_module_type(struct cphy *phy, int delay_ms)
{
int v;
unsigned int stat;
v = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2020_GPIO_STAT, &stat);
if (v)
return v;
if (stat & (0x1 << (AEL2020_GPIO_MODDET*4))) {
return phy_modtype_none;
}
return ael2xxx_get_module_type(phy, delay_ms);
}
static int ael2020_intr_enable(struct cphy *phy)
{
static const struct reg_val regs[] = {
{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CFG+AEL2020_GPIO_LSTAT,
0xffff, 0x4 },
{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
0xffff, 0x8 << (AEL2020_GPIO_LSTAT*4) },
{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
0xffff, 0x2 << (AEL2020_GPIO_MODDET*4) },
{ 0, 0, 0, 0 }
};
int err, link_ok = 0;
err = set_phy_regs(phy, regs);
if (err)
return err;
err = get_link_status_r(phy, &link_ok, NULL, NULL, NULL);
if (err)
return err;
if (link_ok)
t3_link_changed(phy->adapter,
phy2portid(phy));
err = t3_phy_lasi_intr_enable(phy);
if (err)
return err;
return 0;
}
static int ael2020_intr_disable(struct cphy *phy)
{
static const struct reg_val regs[] = {
{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
0xffff, 0xb << (AEL2020_GPIO_LSTAT*4) },
{ MDIO_MMD_PMAPMD, AEL2020_GPIO_CTRL,
0xffff, 0x1 << (AEL2020_GPIO_MODDET*4) },
{ 0, 0, 0, 0 }
};
int err;
err = set_phy_regs(phy, regs);
if (err)
return err;
return t3_phy_lasi_intr_disable(phy);
}
static int ael2020_intr_clear(struct cphy *phy)
{
unsigned int stat;
int err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2020_GPIO_INTR, &stat);
return err ? err : t3_phy_lasi_intr_clear(phy);
}
static int ael2020_reset(struct cphy *phy, int wait)
{
int err;
unsigned int lasi_ctrl;
err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL,
&lasi_ctrl);
if (err)
return err;
err = t3_phy_reset(phy, MDIO_MMD_PMAPMD, 125);
if (err)
return err;
msleep(100);
phy->priv = edc_none;
err = set_phy_regs(phy, ael2020_reset_regs);
if (err)
return err;
err = ael2020_get_module_type(phy, 0);
if (err < 0)
return err;
phy->modtype = (u8)err;
if (err == phy_modtype_twinax || err == phy_modtype_twinax_long)
err = ael2020_setup_twinax_edc(phy, err);
else
err = ael2020_setup_sr_edc(phy);
if (err)
return err;
if (lasi_ctrl & 1)
err = ael2005_intr_enable(phy);
return err;
}
static int ael2020_intr_handler(struct cphy *phy)
{
unsigned int stat;
int ret, edc_needed, cause = 0;
ret = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AEL2020_GPIO_INTR, &stat);
if (ret)
return ret;
if (stat & (0x1 << AEL2020_GPIO_MODDET)) {
ret = ael2020_get_module_type(phy, 300);
if (ret < 0)
return ret;
phy->modtype = (u8)ret;
if (ret == phy_modtype_none)
edc_needed = phy->priv;
else if (ret == phy_modtype_twinax ||
ret == phy_modtype_twinax_long)
edc_needed = edc_twinax;
else
edc_needed = edc_sr;
if (edc_needed != phy->priv) {
ret = ael2020_reset(phy, 0);
return ret ? ret : cphy_cause_module_change;
}
cause = cphy_cause_module_change;
}
ret = t3_phy_lasi_intr_handler(phy);
if (ret < 0)
return ret;
ret |= cause;
return ret ? ret : cphy_cause_link_change;
}
int t3_ael2020_phy_prep(struct cphy *phy, struct adapter *adapter, int phy_addr,
const struct mdio_ops *mdio_ops)
{
int err;
cphy_init(phy, adapter, phy_addr, &ael2020_ops, mdio_ops,
SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_FIBRE |
SUPPORTED_IRQ, "10GBASE-R");
msleep(125);
err = set_phy_regs(phy, ael2020_reset_regs);
if (err)
return err;
return 0;
}
static int get_link_status_x(struct cphy *phy, int *link_ok, int *speed,
int *duplex, int *fc)
{
if (link_ok) {
unsigned int stat0, stat1, stat2;
int err = t3_mdio_read(phy, MDIO_MMD_PMAPMD,
MDIO_PMA_RXDET, &stat0);
if (!err)
err = t3_mdio_read(phy, MDIO_MMD_PCS,
MDIO_PCS_10GBX_STAT1, &stat1);
if (!err)
err = t3_mdio_read(phy, MDIO_MMD_PHYXS,
MDIO_PHYXS_LNSTAT, &stat2);
if (err)
return err;
*link_ok = (stat0 & (stat1 >> 12) & (stat2 >> 12)) & 1;
}
if (speed)
*speed = SPEED_10000;
if (duplex)
*duplex = DUPLEX_FULL;
return 0;
}
int t3_qt2045_phy_prep(struct cphy *phy, struct adapter *adapter,
int phy_addr, const struct mdio_ops *mdio_ops)
{
unsigned int stat;
cphy_init(phy, adapter, phy_addr, &qt2045_ops, mdio_ops,
SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_TP,
"10GBASE-CX4");
if (!phy_addr &&
!t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_STAT1, &stat) &&
stat == 0xffff)
phy->mdio.prtad = 1;
return 0;
}
static int xaui_direct_reset(struct cphy *phy, int wait)
{
return 0;
}
static int xaui_direct_get_link_status(struct cphy *phy, int *link_ok,
int *speed, int *duplex, int *fc)
{
if (link_ok) {
unsigned int status;
int prtad = phy->mdio.prtad;
status = t3_read_reg(phy->adapter,
XGM_REG(A_XGM_SERDES_STAT0, prtad)) |
t3_read_reg(phy->adapter,
XGM_REG(A_XGM_SERDES_STAT1, prtad)) |
t3_read_reg(phy->adapter,
XGM_REG(A_XGM_SERDES_STAT2, prtad)) |
t3_read_reg(phy->adapter,
XGM_REG(A_XGM_SERDES_STAT3, prtad));
*link_ok = !(status & F_LOWSIG0);
}
if (speed)
*speed = SPEED_10000;
if (duplex)
*duplex = DUPLEX_FULL;
return 0;
}
static int xaui_direct_power_down(struct cphy *phy, int enable)
{
return 0;
}
int t3_xaui_direct_phy_prep(struct cphy *phy, struct adapter *adapter,
int phy_addr, const struct mdio_ops *mdio_ops)
{
cphy_init(phy, adapter, phy_addr, &xaui_direct_ops, mdio_ops,
SUPPORTED_10000baseT_Full | SUPPORTED_AUI | SUPPORTED_TP,
"10GBASE-CX4");
return 0;
}
