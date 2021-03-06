static int xgbe_phy_i2c_xfer(struct xgbe_prv_data *pdata,
struct xgbe_i2c_op *i2c_op)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (WARN_ON(!phy_data->comm_owned))
return -EIO;
return pdata->i2c_if.i2c_xfer(pdata, i2c_op);
}
static int xgbe_phy_redrv_write(struct xgbe_prv_data *pdata, unsigned int reg,
unsigned int val)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct xgbe_i2c_op i2c_op;
__be16 *redrv_val;
u8 redrv_data[5], csum;
unsigned int i, retry;
int ret;
redrv_data[0] = ((reg >> 8) & 0xff) << 1;
redrv_data[1] = reg & 0xff;
redrv_val = (__be16 *)&redrv_data[2];
*redrv_val = cpu_to_be16(val);
csum = 0;
for (i = 0; i < 4; i++) {
csum += redrv_data[i];
if (redrv_data[i] > csum)
csum++;
}
redrv_data[4] = ~csum;
retry = 1;
again1:
i2c_op.cmd = XGBE_I2C_CMD_WRITE;
i2c_op.target = phy_data->redrv_addr;
i2c_op.len = sizeof(redrv_data);
i2c_op.buf = redrv_data;
ret = xgbe_phy_i2c_xfer(pdata, &i2c_op);
if (ret) {
if ((ret == -EAGAIN) && retry--)
goto again1;
return ret;
}
retry = 1;
again2:
i2c_op.cmd = XGBE_I2C_CMD_READ;
i2c_op.target = phy_data->redrv_addr;
i2c_op.len = 1;
i2c_op.buf = redrv_data;
ret = xgbe_phy_i2c_xfer(pdata, &i2c_op);
if (ret) {
if ((ret == -EAGAIN) && retry--)
goto again2;
return ret;
}
if (redrv_data[0] != 0xff) {
netif_dbg(pdata, drv, pdata->netdev,
"Redriver write checksum error\n");
ret = -EIO;
}
return ret;
}
static int xgbe_phy_i2c_write(struct xgbe_prv_data *pdata, unsigned int target,
void *val, unsigned int val_len)
{
struct xgbe_i2c_op i2c_op;
int retry, ret;
retry = 1;
again:
i2c_op.cmd = XGBE_I2C_CMD_WRITE;
i2c_op.target = target;
i2c_op.len = val_len;
i2c_op.buf = val;
ret = xgbe_phy_i2c_xfer(pdata, &i2c_op);
if ((ret == -EAGAIN) && retry--)
goto again;
return ret;
}
static int xgbe_phy_i2c_read(struct xgbe_prv_data *pdata, unsigned int target,
void *reg, unsigned int reg_len,
void *val, unsigned int val_len)
{
struct xgbe_i2c_op i2c_op;
int retry, ret;
retry = 1;
again1:
i2c_op.cmd = XGBE_I2C_CMD_WRITE;
i2c_op.target = target;
i2c_op.len = reg_len;
i2c_op.buf = reg;
ret = xgbe_phy_i2c_xfer(pdata, &i2c_op);
if (ret) {
if ((ret == -EAGAIN) && retry--)
goto again1;
return ret;
}
retry = 1;
again2:
i2c_op.cmd = XGBE_I2C_CMD_READ;
i2c_op.target = target;
i2c_op.len = val_len;
i2c_op.buf = val;
ret = xgbe_phy_i2c_xfer(pdata, &i2c_op);
if ((ret == -EAGAIN) && retry--)
goto again2;
return ret;
}
static int xgbe_phy_sfp_put_mux(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct xgbe_i2c_op i2c_op;
u8 mux_channel;
if (phy_data->sfp_comm == XGBE_SFP_COMM_DIRECT)
return 0;
mux_channel = 0;
i2c_op.cmd = XGBE_I2C_CMD_WRITE;
i2c_op.target = phy_data->sfp_mux_address;
i2c_op.len = sizeof(mux_channel);
i2c_op.buf = &mux_channel;
return xgbe_phy_i2c_xfer(pdata, &i2c_op);
}
static int xgbe_phy_sfp_get_mux(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct xgbe_i2c_op i2c_op;
u8 mux_channel;
if (phy_data->sfp_comm == XGBE_SFP_COMM_DIRECT)
return 0;
mux_channel = 1 << phy_data->sfp_mux_channel;
i2c_op.cmd = XGBE_I2C_CMD_WRITE;
i2c_op.target = phy_data->sfp_mux_address;
i2c_op.len = sizeof(mux_channel);
i2c_op.buf = &mux_channel;
return xgbe_phy_i2c_xfer(pdata, &i2c_op);
}
static void xgbe_phy_put_comm_ownership(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
phy_data->comm_owned = 0;
mutex_unlock(&xgbe_phy_comm_lock);
}
static int xgbe_phy_get_comm_ownership(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned long timeout;
unsigned int mutex_id;
if (phy_data->comm_owned)
return 0;
mutex_lock(&xgbe_phy_comm_lock);
XP_IOWRITE(pdata, XP_I2C_MUTEX, XGBE_MUTEX_RELEASE);
XP_IOWRITE(pdata, XP_MDIO_MUTEX, XGBE_MUTEX_RELEASE);
mutex_id = 0;
XP_SET_BITS(mutex_id, XP_I2C_MUTEX, ID, phy_data->port_id);
XP_SET_BITS(mutex_id, XP_I2C_MUTEX, ACTIVE, 1);
timeout = jiffies + (5 * HZ);
while (time_before(jiffies, timeout)) {
if (XP_IOREAD(pdata, XP_I2C_MUTEX) ||
XP_IOREAD(pdata, XP_MDIO_MUTEX)) {
usleep_range(100, 200);
continue;
}
XP_IOWRITE(pdata, XP_I2C_MUTEX, mutex_id);
XP_IOWRITE(pdata, XP_MDIO_MUTEX, mutex_id);
phy_data->comm_owned = 1;
return 0;
}
mutex_unlock(&xgbe_phy_comm_lock);
netdev_err(pdata->netdev, "unable to obtain hardware mutexes\n");
return -ETIMEDOUT;
}
static int xgbe_phy_mdio_mii_write(struct xgbe_prv_data *pdata, int addr,
int reg, u16 val)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (reg & MII_ADDR_C45) {
if (phy_data->phydev_mode != XGBE_MDIO_MODE_CL45)
return -ENOTSUPP;
} else {
if (phy_data->phydev_mode != XGBE_MDIO_MODE_CL22)
return -ENOTSUPP;
}
return pdata->hw_if.write_ext_mii_regs(pdata, addr, reg, val);
}
static int xgbe_phy_i2c_mii_write(struct xgbe_prv_data *pdata, int reg, u16 val)
{
__be16 *mii_val;
u8 mii_data[3];
int ret;
ret = xgbe_phy_sfp_get_mux(pdata);
if (ret)
return ret;
mii_data[0] = reg & 0xff;
mii_val = (__be16 *)&mii_data[1];
*mii_val = cpu_to_be16(val);
ret = xgbe_phy_i2c_write(pdata, XGBE_SFP_PHY_ADDRESS,
mii_data, sizeof(mii_data));
xgbe_phy_sfp_put_mux(pdata);
return ret;
}
static int xgbe_phy_mii_write(struct mii_bus *mii, int addr, int reg, u16 val)
{
struct xgbe_prv_data *pdata = mii->priv;
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
ret = xgbe_phy_get_comm_ownership(pdata);
if (ret)
return ret;
if (phy_data->conn_type == XGBE_CONN_TYPE_SFP)
ret = xgbe_phy_i2c_mii_write(pdata, reg, val);
else if (phy_data->conn_type & XGBE_CONN_TYPE_MDIO)
ret = xgbe_phy_mdio_mii_write(pdata, addr, reg, val);
else
ret = -ENOTSUPP;
xgbe_phy_put_comm_ownership(pdata);
return ret;
}
static int xgbe_phy_mdio_mii_read(struct xgbe_prv_data *pdata, int addr,
int reg)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (reg & MII_ADDR_C45) {
if (phy_data->phydev_mode != XGBE_MDIO_MODE_CL45)
return -ENOTSUPP;
} else {
if (phy_data->phydev_mode != XGBE_MDIO_MODE_CL22)
return -ENOTSUPP;
}
return pdata->hw_if.read_ext_mii_regs(pdata, addr, reg);
}
static int xgbe_phy_i2c_mii_read(struct xgbe_prv_data *pdata, int reg)
{
__be16 mii_val;
u8 mii_reg;
int ret;
ret = xgbe_phy_sfp_get_mux(pdata);
if (ret)
return ret;
mii_reg = reg;
ret = xgbe_phy_i2c_read(pdata, XGBE_SFP_PHY_ADDRESS,
&mii_reg, sizeof(mii_reg),
&mii_val, sizeof(mii_val));
if (!ret)
ret = be16_to_cpu(mii_val);
xgbe_phy_sfp_put_mux(pdata);
return ret;
}
static int xgbe_phy_mii_read(struct mii_bus *mii, int addr, int reg)
{
struct xgbe_prv_data *pdata = mii->priv;
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
ret = xgbe_phy_get_comm_ownership(pdata);
if (ret)
return ret;
if (phy_data->conn_type == XGBE_CONN_TYPE_SFP)
ret = xgbe_phy_i2c_mii_read(pdata, reg);
else if (phy_data->conn_type & XGBE_CONN_TYPE_MDIO)
ret = xgbe_phy_mdio_mii_read(pdata, addr, reg);
else
ret = -ENOTSUPP;
xgbe_phy_put_comm_ownership(pdata);
return ret;
}
static void xgbe_phy_sfp_phy_settings(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (!phy_data->sfp_mod_absent && !phy_data->sfp_changed)
return;
pdata->phy.supported &= ~SUPPORTED_Autoneg;
pdata->phy.supported &= ~(SUPPORTED_Pause | SUPPORTED_Asym_Pause);
pdata->phy.supported &= ~SUPPORTED_TP;
pdata->phy.supported &= ~SUPPORTED_FIBRE;
pdata->phy.supported &= ~SUPPORTED_100baseT_Full;
pdata->phy.supported &= ~SUPPORTED_1000baseT_Full;
pdata->phy.supported &= ~SUPPORTED_10000baseT_Full;
if (phy_data->sfp_mod_absent) {
pdata->phy.speed = SPEED_UNKNOWN;
pdata->phy.duplex = DUPLEX_UNKNOWN;
pdata->phy.autoneg = AUTONEG_ENABLE;
pdata->phy.pause_autoneg = AUTONEG_ENABLE;
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_TP;
pdata->phy.supported |= SUPPORTED_FIBRE;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100)
pdata->phy.supported |= SUPPORTED_100baseT_Full;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000)
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000)
pdata->phy.supported |= SUPPORTED_10000baseT_Full;
pdata->phy.advertising = pdata->phy.supported;
return;
}
switch (phy_data->sfp_base) {
case XGBE_SFP_BASE_1000_T:
case XGBE_SFP_BASE_1000_SX:
case XGBE_SFP_BASE_1000_LX:
case XGBE_SFP_BASE_1000_CX:
pdata->phy.speed = SPEED_UNKNOWN;
pdata->phy.duplex = DUPLEX_UNKNOWN;
pdata->phy.autoneg = AUTONEG_ENABLE;
pdata->phy.pause_autoneg = AUTONEG_ENABLE;
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
break;
case XGBE_SFP_BASE_10000_SR:
case XGBE_SFP_BASE_10000_LR:
case XGBE_SFP_BASE_10000_LRM:
case XGBE_SFP_BASE_10000_ER:
case XGBE_SFP_BASE_10000_CR:
pdata->phy.speed = SPEED_10000;
pdata->phy.duplex = DUPLEX_FULL;
pdata->phy.autoneg = AUTONEG_DISABLE;
pdata->phy.pause_autoneg = AUTONEG_DISABLE;
break;
default:
pdata->phy.speed = SPEED_UNKNOWN;
pdata->phy.duplex = DUPLEX_UNKNOWN;
pdata->phy.autoneg = AUTONEG_DISABLE;
pdata->phy.pause_autoneg = AUTONEG_DISABLE;
break;
}
switch (phy_data->sfp_base) {
case XGBE_SFP_BASE_1000_T:
case XGBE_SFP_BASE_1000_CX:
case XGBE_SFP_BASE_10000_CR:
pdata->phy.supported |= SUPPORTED_TP;
break;
default:
pdata->phy.supported |= SUPPORTED_FIBRE;
}
switch (phy_data->sfp_speed) {
case XGBE_SFP_SPEED_100_1000:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100)
pdata->phy.supported |= SUPPORTED_100baseT_Full;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000)
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
break;
case XGBE_SFP_SPEED_1000:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000)
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
break;
case XGBE_SFP_SPEED_10000:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000)
pdata->phy.supported |= SUPPORTED_10000baseT_Full;
break;
default:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000)
pdata->phy.supported |= SUPPORTED_10000baseT_Full;
else if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000)
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
else if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100)
pdata->phy.supported |= SUPPORTED_100baseT_Full;
}
pdata->phy.advertising = pdata->phy.supported;
}
static bool xgbe_phy_sfp_bit_rate(struct xgbe_sfp_eeprom *sfp_eeprom,
enum xgbe_sfp_speed sfp_speed)
{
u8 *sfp_base, min, max;
sfp_base = sfp_eeprom->base;
switch (sfp_speed) {
case XGBE_SFP_SPEED_1000:
min = XGBE_SFP_BASE_BR_1GBE_MIN;
max = XGBE_SFP_BASE_BR_1GBE_MAX;
break;
case XGBE_SFP_SPEED_10000:
min = XGBE_SFP_BASE_BR_10GBE_MIN;
max = XGBE_SFP_BASE_BR_10GBE_MAX;
break;
default:
return false;
}
return ((sfp_base[XGBE_SFP_BASE_BR] >= min) &&
(sfp_base[XGBE_SFP_BASE_BR] <= max));
}
static void xgbe_phy_free_phy_device(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (phy_data->phydev) {
phy_detach(phy_data->phydev);
phy_device_remove(phy_data->phydev);
phy_device_free(phy_data->phydev);
phy_data->phydev = NULL;
}
}
static bool xgbe_phy_finisar_phy_quirks(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int phy_id = phy_data->phydev->phy_id;
if ((phy_id & 0xfffffff0) != 0x01ff0cc0)
return false;
phy_write(phy_data->phydev, 0x16, 0x0001);
phy_write(phy_data->phydev, 0x00, 0x9140);
phy_write(phy_data->phydev, 0x16, 0x0000);
phy_write(phy_data->phydev, 0x1b, 0x9084);
phy_write(phy_data->phydev, 0x09, 0x0e00);
phy_write(phy_data->phydev, 0x00, 0x8140);
phy_write(phy_data->phydev, 0x04, 0x0d01);
phy_write(phy_data->phydev, 0x00, 0x9140);
phy_data->phydev->supported = PHY_GBIT_FEATURES;
phy_data->phydev->supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
phy_data->phydev->advertising = phy_data->phydev->supported;
netif_dbg(pdata, drv, pdata->netdev,
"Finisar PHY quirk in place\n");
return true;
}
static void xgbe_phy_external_phy_quirks(struct xgbe_prv_data *pdata)
{
if (xgbe_phy_finisar_phy_quirks(pdata))
return;
}
static int xgbe_phy_find_phy_device(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct phy_device *phydev;
int ret;
if (phy_data->phydev)
return 0;
if (phy_data->phydev_mode == XGBE_MDIO_MODE_NONE)
return 0;
if ((phy_data->port_mode == XGBE_PORT_MODE_SFP) &&
!phy_data->sfp_phy_avail)
return 0;
ret = pdata->hw_if.set_ext_mii_mode(pdata, phy_data->mdio_addr,
phy_data->phydev_mode);
if (ret) {
netdev_err(pdata->netdev,
"mdio port/clause not compatible (%u/%u)\n",
phy_data->mdio_addr, phy_data->phydev_mode);
return ret;
}
phydev = get_phy_device(phy_data->mii, phy_data->mdio_addr,
(phy_data->phydev_mode == XGBE_MDIO_MODE_CL45));
if (IS_ERR(phydev)) {
netdev_err(pdata->netdev, "get_phy_device failed\n");
return -ENODEV;
}
netif_dbg(pdata, drv, pdata->netdev, "external PHY id is %#010x\n",
phydev->phy_id);
ret = phy_device_register(phydev);
if (ret) {
netdev_err(pdata->netdev, "phy_device_register failed\n");
phy_device_free(phydev);
return ret;
}
ret = phy_attach_direct(pdata->netdev, phydev, phydev->dev_flags,
PHY_INTERFACE_MODE_SGMII);
if (ret) {
netdev_err(pdata->netdev, "phy_attach_direct failed\n");
phy_device_remove(phydev);
phy_device_free(phydev);
return ret;
}
phy_data->phydev = phydev;
xgbe_phy_external_phy_quirks(pdata);
phydev->advertising &= pdata->phy.advertising;
phy_start_aneg(phy_data->phydev);
return 0;
}
static void xgbe_phy_sfp_external_phy(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
if (!phy_data->sfp_changed)
return;
phy_data->sfp_phy_avail = 0;
if (phy_data->sfp_base != XGBE_SFP_BASE_1000_T)
return;
ret = xgbe_phy_i2c_mii_read(pdata, MII_BMCR);
if (ret < 0)
return;
phy_data->sfp_phy_avail = 1;
}
static bool xgbe_phy_belfuse_parse_quirks(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct xgbe_sfp_eeprom *sfp_eeprom = &phy_data->sfp_eeprom;
if (memcmp(&sfp_eeprom->base[XGBE_SFP_BASE_VENDOR_NAME],
XGBE_BEL_FUSE_VENDOR, XGBE_SFP_BASE_VENDOR_NAME_LEN))
return false;
if (!memcmp(&sfp_eeprom->base[XGBE_SFP_BASE_VENDOR_PN],
XGBE_BEL_FUSE_PARTNO, XGBE_SFP_BASE_VENDOR_PN_LEN)) {
phy_data->sfp_base = XGBE_SFP_BASE_1000_SX;
phy_data->sfp_cable = XGBE_SFP_CABLE_ACTIVE;
phy_data->sfp_speed = XGBE_SFP_SPEED_1000;
if (phy_data->sfp_changed)
netif_dbg(pdata, drv, pdata->netdev,
"Bel-Fuse SFP quirk in place\n");
return true;
}
return false;
}
static bool xgbe_phy_sfp_parse_quirks(struct xgbe_prv_data *pdata)
{
if (xgbe_phy_belfuse_parse_quirks(pdata))
return true;
return false;
}
static void xgbe_phy_sfp_parse_eeprom(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct xgbe_sfp_eeprom *sfp_eeprom = &phy_data->sfp_eeprom;
u8 *sfp_base;
sfp_base = sfp_eeprom->base;
if (sfp_base[XGBE_SFP_BASE_ID] != XGBE_SFP_ID_SFP)
return;
if (sfp_base[XGBE_SFP_BASE_EXT_ID] != XGBE_SFP_EXT_ID_SFP)
return;
if (xgbe_phy_sfp_parse_quirks(pdata))
return;
if (sfp_base[XGBE_SFP_BASE_CABLE] & XGBE_SFP_BASE_CABLE_PASSIVE) {
phy_data->sfp_cable = XGBE_SFP_CABLE_PASSIVE;
phy_data->sfp_cable_len = sfp_base[XGBE_SFP_BASE_CU_CABLE_LEN];
} else {
phy_data->sfp_cable = XGBE_SFP_CABLE_ACTIVE;
}
if (sfp_base[XGBE_SFP_BASE_10GBE_CC] & XGBE_SFP_BASE_10GBE_CC_SR)
phy_data->sfp_base = XGBE_SFP_BASE_10000_SR;
else if (sfp_base[XGBE_SFP_BASE_10GBE_CC] & XGBE_SFP_BASE_10GBE_CC_LR)
phy_data->sfp_base = XGBE_SFP_BASE_10000_LR;
else if (sfp_base[XGBE_SFP_BASE_10GBE_CC] & XGBE_SFP_BASE_10GBE_CC_LRM)
phy_data->sfp_base = XGBE_SFP_BASE_10000_LRM;
else if (sfp_base[XGBE_SFP_BASE_10GBE_CC] & XGBE_SFP_BASE_10GBE_CC_ER)
phy_data->sfp_base = XGBE_SFP_BASE_10000_ER;
else if (sfp_base[XGBE_SFP_BASE_1GBE_CC] & XGBE_SFP_BASE_1GBE_CC_SX)
phy_data->sfp_base = XGBE_SFP_BASE_1000_SX;
else if (sfp_base[XGBE_SFP_BASE_1GBE_CC] & XGBE_SFP_BASE_1GBE_CC_LX)
phy_data->sfp_base = XGBE_SFP_BASE_1000_LX;
else if (sfp_base[XGBE_SFP_BASE_1GBE_CC] & XGBE_SFP_BASE_1GBE_CC_CX)
phy_data->sfp_base = XGBE_SFP_BASE_1000_CX;
else if (sfp_base[XGBE_SFP_BASE_1GBE_CC] & XGBE_SFP_BASE_1GBE_CC_T)
phy_data->sfp_base = XGBE_SFP_BASE_1000_T;
else if ((phy_data->sfp_cable == XGBE_SFP_CABLE_PASSIVE) &&
xgbe_phy_sfp_bit_rate(sfp_eeprom, XGBE_SFP_SPEED_10000))
phy_data->sfp_base = XGBE_SFP_BASE_10000_CR;
switch (phy_data->sfp_base) {
case XGBE_SFP_BASE_1000_T:
phy_data->sfp_speed = XGBE_SFP_SPEED_100_1000;
break;
case XGBE_SFP_BASE_1000_SX:
case XGBE_SFP_BASE_1000_LX:
case XGBE_SFP_BASE_1000_CX:
phy_data->sfp_speed = XGBE_SFP_SPEED_1000;
break;
case XGBE_SFP_BASE_10000_SR:
case XGBE_SFP_BASE_10000_LR:
case XGBE_SFP_BASE_10000_LRM:
case XGBE_SFP_BASE_10000_ER:
case XGBE_SFP_BASE_10000_CR:
phy_data->sfp_speed = XGBE_SFP_SPEED_10000;
break;
default:
break;
}
}
static void xgbe_phy_sfp_eeprom_info(struct xgbe_prv_data *pdata,
struct xgbe_sfp_eeprom *sfp_eeprom)
{
struct xgbe_sfp_ascii sfp_ascii;
char *sfp_data = (char *)&sfp_ascii;
netif_dbg(pdata, drv, pdata->netdev, "SFP detected:\n");
memcpy(sfp_data, &sfp_eeprom->base[XGBE_SFP_BASE_VENDOR_NAME],
XGBE_SFP_BASE_VENDOR_NAME_LEN);
sfp_data[XGBE_SFP_BASE_VENDOR_NAME_LEN] = '\0';
netif_dbg(pdata, drv, pdata->netdev, " vendor: %s\n",
sfp_data);
memcpy(sfp_data, &sfp_eeprom->base[XGBE_SFP_BASE_VENDOR_PN],
XGBE_SFP_BASE_VENDOR_PN_LEN);
sfp_data[XGBE_SFP_BASE_VENDOR_PN_LEN] = '\0';
netif_dbg(pdata, drv, pdata->netdev, " part number: %s\n",
sfp_data);
memcpy(sfp_data, &sfp_eeprom->base[XGBE_SFP_BASE_VENDOR_REV],
XGBE_SFP_BASE_VENDOR_REV_LEN);
sfp_data[XGBE_SFP_BASE_VENDOR_REV_LEN] = '\0';
netif_dbg(pdata, drv, pdata->netdev, " revision level: %s\n",
sfp_data);
memcpy(sfp_data, &sfp_eeprom->extd[XGBE_SFP_BASE_VENDOR_SN],
XGBE_SFP_BASE_VENDOR_SN_LEN);
sfp_data[XGBE_SFP_BASE_VENDOR_SN_LEN] = '\0';
netif_dbg(pdata, drv, pdata->netdev, " serial number: %s\n",
sfp_data);
}
static bool xgbe_phy_sfp_verify_eeprom(u8 cc_in, u8 *buf, unsigned int len)
{
u8 cc;
for (cc = 0; len; buf++, len--)
cc += *buf;
return (cc == cc_in) ? true : false;
}
static int xgbe_phy_sfp_read_eeprom(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
struct xgbe_sfp_eeprom sfp_eeprom;
u8 eeprom_addr;
int ret;
ret = xgbe_phy_sfp_get_mux(pdata);
if (ret) {
dev_err_once(pdata->dev, "%s: I2C error setting SFP MUX\n",
netdev_name(pdata->netdev));
return ret;
}
eeprom_addr = 0;
ret = xgbe_phy_i2c_read(pdata, XGBE_SFP_SERIAL_ID_ADDRESS,
&eeprom_addr, sizeof(eeprom_addr),
&sfp_eeprom, sizeof(sfp_eeprom));
if (ret) {
dev_err_once(pdata->dev, "%s: I2C error reading SFP EEPROM\n",
netdev_name(pdata->netdev));
goto put;
}
if (!xgbe_phy_sfp_verify_eeprom(sfp_eeprom.base[XGBE_SFP_BASE_CC],
sfp_eeprom.base,
sizeof(sfp_eeprom.base) - 1)) {
ret = -EINVAL;
goto put;
}
if (!xgbe_phy_sfp_verify_eeprom(sfp_eeprom.extd[XGBE_SFP_EXTD_CC],
sfp_eeprom.extd,
sizeof(sfp_eeprom.extd) - 1)) {
ret = -EINVAL;
goto put;
}
if (memcmp(&phy_data->sfp_eeprom, &sfp_eeprom, sizeof(sfp_eeprom))) {
phy_data->sfp_changed = 1;
if (netif_msg_drv(pdata))
xgbe_phy_sfp_eeprom_info(pdata, &sfp_eeprom);
memcpy(&phy_data->sfp_eeprom, &sfp_eeprom, sizeof(sfp_eeprom));
if (sfp_eeprom.extd[XGBE_SFP_EXTD_SFF_8472]) {
u8 diag_type = sfp_eeprom.extd[XGBE_SFP_EXTD_DIAG];
if (!(diag_type & XGBE_SFP_EXTD_DIAG_ADDR_CHANGE))
phy_data->sfp_diags = 1;
}
xgbe_phy_free_phy_device(pdata);
} else {
phy_data->sfp_changed = 0;
}
put:
xgbe_phy_sfp_put_mux(pdata);
return ret;
}
static void xgbe_phy_sfp_signals(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int gpio_input;
u8 gpio_reg, gpio_ports[2];
int ret;
gpio_reg = 0;
ret = xgbe_phy_i2c_read(pdata, phy_data->sfp_gpio_address,
&gpio_reg, sizeof(gpio_reg),
gpio_ports, sizeof(gpio_ports));
if (ret) {
dev_err_once(pdata->dev, "%s: I2C error reading SFP GPIOs\n",
netdev_name(pdata->netdev));
return;
}
gpio_input = (gpio_ports[1] << 8) | gpio_ports[0];
if (phy_data->sfp_gpio_mask & XGBE_GPIO_NO_MOD_ABSENT) {
phy_data->sfp_mod_absent = 0;
} else {
if (!(gpio_input & (1 << phy_data->sfp_gpio_mod_absent)))
phy_data->sfp_mod_absent = 0;
}
if (!(phy_data->sfp_gpio_mask & XGBE_GPIO_NO_RX_LOS) &&
(gpio_input & (1 << phy_data->sfp_gpio_rx_los)))
phy_data->sfp_rx_los = 1;
if (!(phy_data->sfp_gpio_mask & XGBE_GPIO_NO_TX_FAULT) &&
(gpio_input & (1 << phy_data->sfp_gpio_tx_fault)))
phy_data->sfp_tx_fault = 1;
}
static void xgbe_phy_sfp_mod_absent(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_free_phy_device(pdata);
phy_data->sfp_mod_absent = 1;
phy_data->sfp_phy_avail = 0;
memset(&phy_data->sfp_eeprom, 0, sizeof(phy_data->sfp_eeprom));
}
static void xgbe_phy_sfp_reset(struct xgbe_phy_data *phy_data)
{
phy_data->sfp_rx_los = 0;
phy_data->sfp_tx_fault = 0;
phy_data->sfp_mod_absent = 1;
phy_data->sfp_diags = 0;
phy_data->sfp_base = XGBE_SFP_BASE_UNKNOWN;
phy_data->sfp_cable = XGBE_SFP_CABLE_UNKNOWN;
phy_data->sfp_speed = XGBE_SFP_SPEED_UNKNOWN;
}
static void xgbe_phy_sfp_detect(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
xgbe_phy_sfp_reset(phy_data);
ret = xgbe_phy_get_comm_ownership(pdata);
if (ret)
return;
xgbe_phy_sfp_signals(pdata);
if (phy_data->sfp_mod_absent) {
xgbe_phy_sfp_mod_absent(pdata);
goto put;
}
ret = xgbe_phy_sfp_read_eeprom(pdata);
if (ret) {
xgbe_phy_sfp_reset(phy_data);
xgbe_phy_sfp_mod_absent(pdata);
goto put;
}
xgbe_phy_sfp_parse_eeprom(pdata);
xgbe_phy_sfp_external_phy(pdata);
put:
xgbe_phy_sfp_phy_settings(pdata);
xgbe_phy_put_comm_ownership(pdata);
}
static void xgbe_phy_phydev_flowctrl(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
u16 lcl_adv = 0, rmt_adv = 0;
u8 fc;
pdata->phy.tx_pause = 0;
pdata->phy.rx_pause = 0;
if (!phy_data->phydev)
return;
if (phy_data->phydev->advertising & ADVERTISED_Pause)
lcl_adv |= ADVERTISE_PAUSE_CAP;
if (phy_data->phydev->advertising & ADVERTISED_Asym_Pause)
lcl_adv |= ADVERTISE_PAUSE_ASYM;
if (phy_data->phydev->pause) {
pdata->phy.lp_advertising |= ADVERTISED_Pause;
rmt_adv |= LPA_PAUSE_CAP;
}
if (phy_data->phydev->asym_pause) {
pdata->phy.lp_advertising |= ADVERTISED_Asym_Pause;
rmt_adv |= LPA_PAUSE_ASYM;
}
fc = mii_resolve_flowctrl_fdx(lcl_adv, rmt_adv);
if (fc & FLOW_CTRL_TX)
pdata->phy.tx_pause = 1;
if (fc & FLOW_CTRL_RX)
pdata->phy.rx_pause = 1;
}
static enum xgbe_mode xgbe_phy_an37_sgmii_outcome(struct xgbe_prv_data *pdata)
{
enum xgbe_mode mode;
pdata->phy.lp_advertising |= ADVERTISED_Autoneg;
pdata->phy.lp_advertising |= ADVERTISED_TP;
if (pdata->phy.pause_autoneg)
xgbe_phy_phydev_flowctrl(pdata);
switch (pdata->an_status & XGBE_SGMII_AN_LINK_SPEED) {
case XGBE_SGMII_AN_LINK_SPEED_100:
if (pdata->an_status & XGBE_SGMII_AN_LINK_DUPLEX) {
pdata->phy.lp_advertising |= ADVERTISED_100baseT_Full;
mode = XGBE_MODE_SGMII_100;
} else {
pdata->phy.lp_advertising |= ADVERTISED_100baseT_Half;
mode = XGBE_MODE_UNKNOWN;
}
break;
case XGBE_SGMII_AN_LINK_SPEED_1000:
if (pdata->an_status & XGBE_SGMII_AN_LINK_DUPLEX) {
pdata->phy.lp_advertising |= ADVERTISED_1000baseT_Full;
mode = XGBE_MODE_SGMII_1000;
} else {
pdata->phy.lp_advertising |= ADVERTISED_1000baseT_Half;
mode = XGBE_MODE_UNKNOWN;
}
break;
default:
mode = XGBE_MODE_UNKNOWN;
}
return mode;
}
static enum xgbe_mode xgbe_phy_an37_outcome(struct xgbe_prv_data *pdata)
{
enum xgbe_mode mode;
unsigned int ad_reg, lp_reg;
pdata->phy.lp_advertising |= ADVERTISED_Autoneg;
pdata->phy.lp_advertising |= ADVERTISED_FIBRE;
ad_reg = XMDIO_READ(pdata, MDIO_MMD_VEND2, MDIO_VEND2_AN_ADVERTISE);
lp_reg = XMDIO_READ(pdata, MDIO_MMD_VEND2, MDIO_VEND2_AN_LP_ABILITY);
if (lp_reg & 0x100)
pdata->phy.lp_advertising |= ADVERTISED_Pause;
if (lp_reg & 0x80)
pdata->phy.lp_advertising |= ADVERTISED_Asym_Pause;
if (pdata->phy.pause_autoneg) {
pdata->phy.tx_pause = 0;
pdata->phy.rx_pause = 0;
if (ad_reg & lp_reg & 0x100) {
pdata->phy.tx_pause = 1;
pdata->phy.rx_pause = 1;
} else if (ad_reg & lp_reg & 0x80) {
if (ad_reg & 0x100)
pdata->phy.rx_pause = 1;
else if (lp_reg & 0x100)
pdata->phy.tx_pause = 1;
}
}
if (lp_reg & 0x40)
pdata->phy.lp_advertising |= ADVERTISED_1000baseT_Half;
if (lp_reg & 0x20)
pdata->phy.lp_advertising |= ADVERTISED_1000baseT_Full;
ad_reg &= lp_reg;
mode = (ad_reg & 0x20) ? XGBE_MODE_X : XGBE_MODE_UNKNOWN;
return mode;
}
static enum xgbe_mode xgbe_phy_an73_redrv_outcome(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
enum xgbe_mode mode;
unsigned int ad_reg, lp_reg;
pdata->phy.lp_advertising |= ADVERTISED_Autoneg;
pdata->phy.lp_advertising |= ADVERTISED_Backplane;
if (pdata->phy.pause_autoneg)
xgbe_phy_phydev_flowctrl(pdata);
ad_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 1);
lp_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_LPA + 1);
if (lp_reg & 0x80)
pdata->phy.lp_advertising |= ADVERTISED_10000baseKR_Full;
if (lp_reg & 0x20)
pdata->phy.lp_advertising |= ADVERTISED_1000baseKX_Full;
ad_reg &= lp_reg;
if (ad_reg & 0x80) {
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
mode = XGBE_MODE_KR;
break;
default:
mode = XGBE_MODE_SFI;
break;
}
} else if (ad_reg & 0x20) {
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
mode = XGBE_MODE_KX_1000;
break;
case XGBE_PORT_MODE_1000BASE_X:
mode = XGBE_MODE_X;
break;
case XGBE_PORT_MODE_SFP:
switch (phy_data->sfp_base) {
case XGBE_SFP_BASE_1000_T:
if (phy_data->phydev &&
(phy_data->phydev->speed == SPEED_100))
mode = XGBE_MODE_SGMII_100;
else
mode = XGBE_MODE_SGMII_1000;
break;
case XGBE_SFP_BASE_1000_SX:
case XGBE_SFP_BASE_1000_LX:
case XGBE_SFP_BASE_1000_CX:
default:
mode = XGBE_MODE_X;
break;
}
break;
default:
if (phy_data->phydev &&
(phy_data->phydev->speed == SPEED_100))
mode = XGBE_MODE_SGMII_100;
else
mode = XGBE_MODE_SGMII_1000;
break;
}
} else {
mode = XGBE_MODE_UNKNOWN;
}
ad_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 2);
lp_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_LPA + 2);
if (lp_reg & 0xc000)
pdata->phy.lp_advertising |= ADVERTISED_10000baseR_FEC;
return mode;
}
static enum xgbe_mode xgbe_phy_an73_outcome(struct xgbe_prv_data *pdata)
{
enum xgbe_mode mode;
unsigned int ad_reg, lp_reg;
pdata->phy.lp_advertising |= ADVERTISED_Autoneg;
pdata->phy.lp_advertising |= ADVERTISED_Backplane;
ad_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE);
lp_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_LPA);
if (lp_reg & 0x400)
pdata->phy.lp_advertising |= ADVERTISED_Pause;
if (lp_reg & 0x800)
pdata->phy.lp_advertising |= ADVERTISED_Asym_Pause;
if (pdata->phy.pause_autoneg) {
pdata->phy.tx_pause = 0;
pdata->phy.rx_pause = 0;
if (ad_reg & lp_reg & 0x400) {
pdata->phy.tx_pause = 1;
pdata->phy.rx_pause = 1;
} else if (ad_reg & lp_reg & 0x800) {
if (ad_reg & 0x400)
pdata->phy.rx_pause = 1;
else if (lp_reg & 0x400)
pdata->phy.tx_pause = 1;
}
}
ad_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 1);
lp_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_LPA + 1);
if (lp_reg & 0x80)
pdata->phy.lp_advertising |= ADVERTISED_10000baseKR_Full;
if (lp_reg & 0x20)
pdata->phy.lp_advertising |= ADVERTISED_1000baseKX_Full;
ad_reg &= lp_reg;
if (ad_reg & 0x80)
mode = XGBE_MODE_KR;
else if (ad_reg & 0x20)
mode = XGBE_MODE_KX_1000;
else
mode = XGBE_MODE_UNKNOWN;
ad_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 2);
lp_reg = XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_LPA + 2);
if (lp_reg & 0xc000)
pdata->phy.lp_advertising |= ADVERTISED_10000baseR_FEC;
return mode;
}
static enum xgbe_mode xgbe_phy_an_outcome(struct xgbe_prv_data *pdata)
{
switch (pdata->an_mode) {
case XGBE_AN_MODE_CL73:
return xgbe_phy_an73_outcome(pdata);
case XGBE_AN_MODE_CL73_REDRV:
return xgbe_phy_an73_redrv_outcome(pdata);
case XGBE_AN_MODE_CL37:
return xgbe_phy_an37_outcome(pdata);
case XGBE_AN_MODE_CL37_SGMII:
return xgbe_phy_an37_sgmii_outcome(pdata);
default:
return XGBE_MODE_UNKNOWN;
}
}
static unsigned int xgbe_phy_an_advertising(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int advertising;
if (!phy_data->redrv)
return pdata->phy.advertising;
advertising = pdata->phy.advertising;
advertising &= ~ADVERTISED_1000baseKX_Full;
advertising &= ~ADVERTISED_10000baseKR_Full;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
advertising |= ADVERTISED_10000baseKR_Full;
break;
case XGBE_PORT_MODE_BACKPLANE_2500:
advertising |= ADVERTISED_1000baseKX_Full;
break;
case XGBE_PORT_MODE_1000BASE_T:
case XGBE_PORT_MODE_1000BASE_X:
case XGBE_PORT_MODE_NBASE_T:
advertising |= ADVERTISED_1000baseKX_Full;
break;
case XGBE_PORT_MODE_10GBASE_T:
if (phy_data->phydev &&
(phy_data->phydev->speed == SPEED_10000))
advertising |= ADVERTISED_10000baseKR_Full;
else
advertising |= ADVERTISED_1000baseKX_Full;
break;
case XGBE_PORT_MODE_10GBASE_R:
advertising |= ADVERTISED_10000baseKR_Full;
break;
case XGBE_PORT_MODE_SFP:
switch (phy_data->sfp_base) {
case XGBE_SFP_BASE_1000_T:
case XGBE_SFP_BASE_1000_SX:
case XGBE_SFP_BASE_1000_LX:
case XGBE_SFP_BASE_1000_CX:
advertising |= ADVERTISED_1000baseKX_Full;
break;
default:
advertising |= ADVERTISED_10000baseKR_Full;
break;
}
break;
default:
advertising |= ADVERTISED_10000baseKR_Full;
break;
}
return advertising;
}
static int xgbe_phy_an_config(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
ret = xgbe_phy_find_phy_device(pdata);
if (ret)
return ret;
if (!phy_data->phydev)
return 0;
phy_data->phydev->autoneg = pdata->phy.autoneg;
phy_data->phydev->advertising = phy_data->phydev->supported &
pdata->phy.advertising;
if (pdata->phy.autoneg != AUTONEG_ENABLE) {
phy_data->phydev->speed = pdata->phy.speed;
phy_data->phydev->duplex = pdata->phy.duplex;
}
ret = phy_start_aneg(phy_data->phydev);
return ret;
}
static enum xgbe_an_mode xgbe_phy_an_sfp_mode(struct xgbe_phy_data *phy_data)
{
switch (phy_data->sfp_base) {
case XGBE_SFP_BASE_1000_T:
return XGBE_AN_MODE_CL37_SGMII;
case XGBE_SFP_BASE_1000_SX:
case XGBE_SFP_BASE_1000_LX:
case XGBE_SFP_BASE_1000_CX:
return XGBE_AN_MODE_CL37;
default:
return XGBE_AN_MODE_NONE;
}
}
static enum xgbe_an_mode xgbe_phy_an_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (phy_data->redrv)
return XGBE_AN_MODE_CL73_REDRV;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
return XGBE_AN_MODE_CL73;
case XGBE_PORT_MODE_BACKPLANE_2500:
return XGBE_AN_MODE_NONE;
case XGBE_PORT_MODE_1000BASE_T:
return XGBE_AN_MODE_CL37_SGMII;
case XGBE_PORT_MODE_1000BASE_X:
return XGBE_AN_MODE_CL37;
case XGBE_PORT_MODE_NBASE_T:
return XGBE_AN_MODE_CL37_SGMII;
case XGBE_PORT_MODE_10GBASE_T:
return XGBE_AN_MODE_CL73;
case XGBE_PORT_MODE_10GBASE_R:
return XGBE_AN_MODE_NONE;
case XGBE_PORT_MODE_SFP:
return xgbe_phy_an_sfp_mode(phy_data);
default:
return XGBE_AN_MODE_NONE;
}
}
static int xgbe_phy_set_redrv_mode_mdio(struct xgbe_prv_data *pdata,
enum xgbe_phy_redrv_mode mode)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
u16 redrv_reg, redrv_val;
redrv_reg = XGBE_PHY_REDRV_MODE_REG + (phy_data->redrv_lane * 0x1000);
redrv_val = (u16)mode;
return pdata->hw_if.write_ext_mii_regs(pdata, phy_data->redrv_addr,
redrv_reg, redrv_val);
}
static int xgbe_phy_set_redrv_mode_i2c(struct xgbe_prv_data *pdata,
enum xgbe_phy_redrv_mode mode)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int redrv_reg;
int ret;
redrv_reg = XGBE_PHY_REDRV_MODE_REG + (phy_data->redrv_lane * 0x1000);
ret = xgbe_phy_redrv_write(pdata, redrv_reg, mode);
return ret;
}
static void xgbe_phy_set_redrv_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
enum xgbe_phy_redrv_mode mode;
int ret;
if (!phy_data->redrv)
return;
mode = XGBE_PHY_REDRV_MODE_CX;
if ((phy_data->port_mode == XGBE_PORT_MODE_SFP) &&
(phy_data->sfp_base != XGBE_SFP_BASE_1000_CX) &&
(phy_data->sfp_base != XGBE_SFP_BASE_10000_CR))
mode = XGBE_PHY_REDRV_MODE_SR;
ret = xgbe_phy_get_comm_ownership(pdata);
if (ret)
return;
if (phy_data->redrv_if)
xgbe_phy_set_redrv_mode_i2c(pdata, mode);
else
xgbe_phy_set_redrv_mode_mdio(pdata, mode);
xgbe_phy_put_comm_ownership(pdata);
}
static void xgbe_phy_perform_ratechange(struct xgbe_prv_data *pdata,
unsigned int cmd, unsigned int sub_cmd)
{
unsigned int s0 = 0;
unsigned int wait;
if (XP_IOREAD_BITS(pdata, XP_DRIVER_INT_RO, STATUS))
netif_dbg(pdata, link, pdata->netdev,
"firmware mailbox not ready for command\n");
XP_SET_BITS(s0, XP_DRIVER_SCRATCH_0, COMMAND, cmd);
XP_SET_BITS(s0, XP_DRIVER_SCRATCH_0, SUB_COMMAND, sub_cmd);
XP_IOWRITE(pdata, XP_DRIVER_SCRATCH_0, s0);
XP_IOWRITE(pdata, XP_DRIVER_SCRATCH_1, 0);
XP_IOWRITE_BITS(pdata, XP_DRIVER_INT_REQ, REQUEST, 1);
wait = XGBE_RATECHANGE_COUNT;
while (wait--) {
if (!XP_IOREAD_BITS(pdata, XP_DRIVER_INT_RO, STATUS))
return;
usleep_range(1000, 2000);
}
netif_dbg(pdata, link, pdata->netdev,
"firmware mailbox command did not complete\n");
}
static void xgbe_phy_rrc(struct xgbe_prv_data *pdata)
{
xgbe_phy_perform_ratechange(pdata, 5, 0);
netif_dbg(pdata, link, pdata->netdev, "receiver reset complete\n");
}
static void xgbe_phy_power_off(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_perform_ratechange(pdata, 0, 0);
phy_data->cur_mode = XGBE_MODE_UNKNOWN;
netif_dbg(pdata, link, pdata->netdev, "phy powered off\n");
}
static void xgbe_phy_sfi_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
if (phy_data->sfp_cable != XGBE_SFP_CABLE_PASSIVE) {
xgbe_phy_perform_ratechange(pdata, 3, 0);
} else {
if (phy_data->sfp_cable_len <= 1)
xgbe_phy_perform_ratechange(pdata, 3, 1);
else if (phy_data->sfp_cable_len <= 3)
xgbe_phy_perform_ratechange(pdata, 3, 2);
else
xgbe_phy_perform_ratechange(pdata, 3, 3);
}
phy_data->cur_mode = XGBE_MODE_SFI;
netif_dbg(pdata, link, pdata->netdev, "10GbE SFI mode set\n");
}
static void xgbe_phy_x_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
xgbe_phy_perform_ratechange(pdata, 1, 3);
phy_data->cur_mode = XGBE_MODE_X;
netif_dbg(pdata, link, pdata->netdev, "1GbE X mode set\n");
}
static void xgbe_phy_sgmii_1000_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
xgbe_phy_perform_ratechange(pdata, 1, 2);
phy_data->cur_mode = XGBE_MODE_SGMII_1000;
netif_dbg(pdata, link, pdata->netdev, "1GbE SGMII mode set\n");
}
static void xgbe_phy_sgmii_100_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
xgbe_phy_perform_ratechange(pdata, 1, 1);
phy_data->cur_mode = XGBE_MODE_SGMII_100;
netif_dbg(pdata, link, pdata->netdev, "100MbE SGMII mode set\n");
}
static void xgbe_phy_kr_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
xgbe_phy_perform_ratechange(pdata, 4, 0);
phy_data->cur_mode = XGBE_MODE_KR;
netif_dbg(pdata, link, pdata->netdev, "10GbE KR mode set\n");
}
static void xgbe_phy_kx_2500_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
xgbe_phy_perform_ratechange(pdata, 2, 0);
phy_data->cur_mode = XGBE_MODE_KX_2500;
netif_dbg(pdata, link, pdata->netdev, "2.5GbE KX mode set\n");
}
static void xgbe_phy_kx_1000_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_set_redrv_mode(pdata);
xgbe_phy_perform_ratechange(pdata, 1, 3);
phy_data->cur_mode = XGBE_MODE_KX_1000;
netif_dbg(pdata, link, pdata->netdev, "1GbE KX mode set\n");
}
static enum xgbe_mode xgbe_phy_cur_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
return phy_data->cur_mode;
}
static enum xgbe_mode xgbe_phy_switch_baset_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
if (phy_data->port_mode != XGBE_PORT_MODE_10GBASE_T)
return xgbe_phy_cur_mode(pdata);
switch (xgbe_phy_cur_mode(pdata)) {
case XGBE_MODE_SGMII_100:
case XGBE_MODE_SGMII_1000:
return XGBE_MODE_KR;
case XGBE_MODE_KR:
default:
return XGBE_MODE_SGMII_1000;
}
}
static enum xgbe_mode xgbe_phy_switch_bp_2500_mode(struct xgbe_prv_data *pdata)
{
return XGBE_MODE_KX_2500;
}
static enum xgbe_mode xgbe_phy_switch_bp_mode(struct xgbe_prv_data *pdata)
{
switch (xgbe_phy_cur_mode(pdata)) {
case XGBE_MODE_KX_1000:
return XGBE_MODE_KR;
case XGBE_MODE_KR:
default:
return XGBE_MODE_KX_1000;
}
}
static enum xgbe_mode xgbe_phy_switch_mode(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
return xgbe_phy_switch_bp_mode(pdata);
case XGBE_PORT_MODE_BACKPLANE_2500:
return xgbe_phy_switch_bp_2500_mode(pdata);
case XGBE_PORT_MODE_1000BASE_T:
case XGBE_PORT_MODE_NBASE_T:
case XGBE_PORT_MODE_10GBASE_T:
return xgbe_phy_switch_baset_mode(pdata);
case XGBE_PORT_MODE_1000BASE_X:
case XGBE_PORT_MODE_10GBASE_R:
case XGBE_PORT_MODE_SFP:
return xgbe_phy_cur_mode(pdata);
default:
return XGBE_MODE_UNKNOWN;
}
}
static enum xgbe_mode xgbe_phy_get_basex_mode(struct xgbe_phy_data *phy_data,
int speed)
{
switch (speed) {
case SPEED_1000:
return XGBE_MODE_X;
case SPEED_10000:
return XGBE_MODE_KR;
default:
return XGBE_MODE_UNKNOWN;
}
}
static enum xgbe_mode xgbe_phy_get_baset_mode(struct xgbe_phy_data *phy_data,
int speed)
{
switch (speed) {
case SPEED_100:
return XGBE_MODE_SGMII_100;
case SPEED_1000:
return XGBE_MODE_SGMII_1000;
case SPEED_2500:
return XGBE_MODE_KX_2500;
case SPEED_10000:
return XGBE_MODE_KR;
default:
return XGBE_MODE_UNKNOWN;
}
}
static enum xgbe_mode xgbe_phy_get_sfp_mode(struct xgbe_phy_data *phy_data,
int speed)
{
switch (speed) {
case SPEED_100:
return XGBE_MODE_SGMII_100;
case SPEED_1000:
if (phy_data->sfp_base == XGBE_SFP_BASE_1000_T)
return XGBE_MODE_SGMII_1000;
else
return XGBE_MODE_X;
case SPEED_10000:
case SPEED_UNKNOWN:
return XGBE_MODE_SFI;
default:
return XGBE_MODE_UNKNOWN;
}
}
static enum xgbe_mode xgbe_phy_get_bp_2500_mode(int speed)
{
switch (speed) {
case SPEED_2500:
return XGBE_MODE_KX_2500;
default:
return XGBE_MODE_UNKNOWN;
}
}
static enum xgbe_mode xgbe_phy_get_bp_mode(int speed)
{
switch (speed) {
case SPEED_1000:
return XGBE_MODE_KX_1000;
case SPEED_10000:
return XGBE_MODE_KR;
default:
return XGBE_MODE_UNKNOWN;
}
}
static enum xgbe_mode xgbe_phy_get_mode(struct xgbe_prv_data *pdata,
int speed)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
return xgbe_phy_get_bp_mode(speed);
case XGBE_PORT_MODE_BACKPLANE_2500:
return xgbe_phy_get_bp_2500_mode(speed);
case XGBE_PORT_MODE_1000BASE_T:
case XGBE_PORT_MODE_NBASE_T:
case XGBE_PORT_MODE_10GBASE_T:
return xgbe_phy_get_baset_mode(phy_data, speed);
case XGBE_PORT_MODE_1000BASE_X:
case XGBE_PORT_MODE_10GBASE_R:
return xgbe_phy_get_basex_mode(phy_data, speed);
case XGBE_PORT_MODE_SFP:
return xgbe_phy_get_sfp_mode(phy_data, speed);
default:
return XGBE_MODE_UNKNOWN;
}
}
static void xgbe_phy_set_mode(struct xgbe_prv_data *pdata, enum xgbe_mode mode)
{
switch (mode) {
case XGBE_MODE_KX_1000:
xgbe_phy_kx_1000_mode(pdata);
break;
case XGBE_MODE_KX_2500:
xgbe_phy_kx_2500_mode(pdata);
break;
case XGBE_MODE_KR:
xgbe_phy_kr_mode(pdata);
break;
case XGBE_MODE_SGMII_100:
xgbe_phy_sgmii_100_mode(pdata);
break;
case XGBE_MODE_SGMII_1000:
xgbe_phy_sgmii_1000_mode(pdata);
break;
case XGBE_MODE_X:
xgbe_phy_x_mode(pdata);
break;
case XGBE_MODE_SFI:
xgbe_phy_sfi_mode(pdata);
break;
default:
break;
}
}
static bool xgbe_phy_check_mode(struct xgbe_prv_data *pdata,
enum xgbe_mode mode, u32 advert)
{
if (pdata->phy.autoneg == AUTONEG_ENABLE) {
if (pdata->phy.advertising & advert)
return true;
} else {
enum xgbe_mode cur_mode;
cur_mode = xgbe_phy_get_mode(pdata, pdata->phy.speed);
if (cur_mode == mode)
return true;
}
return false;
}
static bool xgbe_phy_use_basex_mode(struct xgbe_prv_data *pdata,
enum xgbe_mode mode)
{
switch (mode) {
case XGBE_MODE_X:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_1000baseT_Full);
case XGBE_MODE_KR:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_10000baseT_Full);
default:
return false;
}
}
static bool xgbe_phy_use_baset_mode(struct xgbe_prv_data *pdata,
enum xgbe_mode mode)
{
switch (mode) {
case XGBE_MODE_SGMII_100:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_100baseT_Full);
case XGBE_MODE_SGMII_1000:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_1000baseT_Full);
case XGBE_MODE_KX_2500:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_2500baseX_Full);
case XGBE_MODE_KR:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_10000baseT_Full);
default:
return false;
}
}
static bool xgbe_phy_use_sfp_mode(struct xgbe_prv_data *pdata,
enum xgbe_mode mode)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (mode) {
case XGBE_MODE_X:
if (phy_data->sfp_base == XGBE_SFP_BASE_1000_T)
return false;
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_1000baseT_Full);
case XGBE_MODE_SGMII_100:
if (phy_data->sfp_base != XGBE_SFP_BASE_1000_T)
return false;
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_100baseT_Full);
case XGBE_MODE_SGMII_1000:
if (phy_data->sfp_base != XGBE_SFP_BASE_1000_T)
return false;
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_1000baseT_Full);
case XGBE_MODE_SFI:
if (phy_data->sfp_mod_absent)
return true;
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_10000baseT_Full);
default:
return false;
}
}
static bool xgbe_phy_use_bp_2500_mode(struct xgbe_prv_data *pdata,
enum xgbe_mode mode)
{
switch (mode) {
case XGBE_MODE_KX_2500:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_2500baseX_Full);
default:
return false;
}
}
static bool xgbe_phy_use_bp_mode(struct xgbe_prv_data *pdata,
enum xgbe_mode mode)
{
switch (mode) {
case XGBE_MODE_KX_1000:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_1000baseKX_Full);
case XGBE_MODE_KR:
return xgbe_phy_check_mode(pdata, mode,
ADVERTISED_10000baseKR_Full);
default:
return false;
}
}
static bool xgbe_phy_use_mode(struct xgbe_prv_data *pdata, enum xgbe_mode mode)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
return xgbe_phy_use_bp_mode(pdata, mode);
case XGBE_PORT_MODE_BACKPLANE_2500:
return xgbe_phy_use_bp_2500_mode(pdata, mode);
case XGBE_PORT_MODE_1000BASE_T:
case XGBE_PORT_MODE_NBASE_T:
case XGBE_PORT_MODE_10GBASE_T:
return xgbe_phy_use_baset_mode(pdata, mode);
case XGBE_PORT_MODE_1000BASE_X:
case XGBE_PORT_MODE_10GBASE_R:
return xgbe_phy_use_basex_mode(pdata, mode);
case XGBE_PORT_MODE_SFP:
return xgbe_phy_use_sfp_mode(pdata, mode);
default:
return false;
}
}
static bool xgbe_phy_valid_speed_basex_mode(struct xgbe_phy_data *phy_data,
int speed)
{
switch (speed) {
case SPEED_1000:
return (phy_data->port_mode == XGBE_PORT_MODE_1000BASE_X);
case SPEED_10000:
return (phy_data->port_mode == XGBE_PORT_MODE_10GBASE_R);
default:
return false;
}
}
static bool xgbe_phy_valid_speed_baset_mode(struct xgbe_phy_data *phy_data,
int speed)
{
switch (speed) {
case SPEED_100:
case SPEED_1000:
return true;
case SPEED_2500:
return (phy_data->port_mode == XGBE_PORT_MODE_NBASE_T);
case SPEED_10000:
return (phy_data->port_mode == XGBE_PORT_MODE_10GBASE_T);
default:
return false;
}
}
static bool xgbe_phy_valid_speed_sfp_mode(struct xgbe_phy_data *phy_data,
int speed)
{
switch (speed) {
case SPEED_100:
return (phy_data->sfp_speed == XGBE_SFP_SPEED_100_1000);
case SPEED_1000:
return ((phy_data->sfp_speed == XGBE_SFP_SPEED_100_1000) ||
(phy_data->sfp_speed == XGBE_SFP_SPEED_1000));
case SPEED_10000:
return (phy_data->sfp_speed == XGBE_SFP_SPEED_10000);
default:
return false;
}
}
static bool xgbe_phy_valid_speed_bp_2500_mode(int speed)
{
switch (speed) {
case SPEED_2500:
return true;
default:
return false;
}
}
static bool xgbe_phy_valid_speed_bp_mode(int speed)
{
switch (speed) {
case SPEED_1000:
case SPEED_10000:
return true;
default:
return false;
}
}
static bool xgbe_phy_valid_speed(struct xgbe_prv_data *pdata, int speed)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
return xgbe_phy_valid_speed_bp_mode(speed);
case XGBE_PORT_MODE_BACKPLANE_2500:
return xgbe_phy_valid_speed_bp_2500_mode(speed);
case XGBE_PORT_MODE_1000BASE_T:
case XGBE_PORT_MODE_NBASE_T:
case XGBE_PORT_MODE_10GBASE_T:
return xgbe_phy_valid_speed_baset_mode(phy_data, speed);
case XGBE_PORT_MODE_1000BASE_X:
case XGBE_PORT_MODE_10GBASE_R:
return xgbe_phy_valid_speed_basex_mode(phy_data, speed);
case XGBE_PORT_MODE_SFP:
return xgbe_phy_valid_speed_sfp_mode(phy_data, speed);
default:
return false;
}
}
static int xgbe_phy_link_status(struct xgbe_prv_data *pdata, int *an_restart)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int reg;
int ret;
*an_restart = 0;
if (phy_data->port_mode == XGBE_PORT_MODE_SFP) {
xgbe_phy_sfp_detect(pdata);
if (phy_data->sfp_changed) {
*an_restart = 1;
return 0;
}
if (phy_data->sfp_mod_absent || phy_data->sfp_rx_los)
return 0;
}
if (phy_data->phydev) {
ret = phy_read_status(phy_data->phydev);
if (ret < 0)
return 0;
if ((pdata->phy.autoneg == AUTONEG_ENABLE) &&
!phy_aneg_done(phy_data->phydev))
return 0;
if (!phy_data->phydev->link)
return 0;
}
reg = XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_STAT1);
reg = XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_STAT1);
if (reg & MDIO_STAT1_LSTATUS)
return 1;
if (phy_data->rrc_count++) {
phy_data->rrc_count = 0;
xgbe_phy_rrc(pdata);
}
return 0;
}
static void xgbe_phy_sfp_gpio_setup(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int reg;
reg = XP_IOREAD(pdata, XP_PROP_3);
phy_data->sfp_gpio_address = XGBE_GPIO_ADDRESS_PCA9555 +
XP_GET_BITS(reg, XP_PROP_3, GPIO_ADDR);
phy_data->sfp_gpio_mask = XP_GET_BITS(reg, XP_PROP_3, GPIO_MASK);
phy_data->sfp_gpio_rx_los = XP_GET_BITS(reg, XP_PROP_3,
GPIO_RX_LOS);
phy_data->sfp_gpio_tx_fault = XP_GET_BITS(reg, XP_PROP_3,
GPIO_TX_FAULT);
phy_data->sfp_gpio_mod_absent = XP_GET_BITS(reg, XP_PROP_3,
GPIO_MOD_ABS);
phy_data->sfp_gpio_rate_select = XP_GET_BITS(reg, XP_PROP_3,
GPIO_RATE_SELECT);
if (netif_msg_probe(pdata)) {
dev_dbg(pdata->dev, "SFP: gpio_address=%#x\n",
phy_data->sfp_gpio_address);
dev_dbg(pdata->dev, "SFP: gpio_mask=%#x\n",
phy_data->sfp_gpio_mask);
dev_dbg(pdata->dev, "SFP: gpio_rx_los=%u\n",
phy_data->sfp_gpio_rx_los);
dev_dbg(pdata->dev, "SFP: gpio_tx_fault=%u\n",
phy_data->sfp_gpio_tx_fault);
dev_dbg(pdata->dev, "SFP: gpio_mod_absent=%u\n",
phy_data->sfp_gpio_mod_absent);
dev_dbg(pdata->dev, "SFP: gpio_rate_select=%u\n",
phy_data->sfp_gpio_rate_select);
}
}
static void xgbe_phy_sfp_comm_setup(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int reg, mux_addr_hi, mux_addr_lo;
reg = XP_IOREAD(pdata, XP_PROP_4);
mux_addr_hi = XP_GET_BITS(reg, XP_PROP_4, MUX_ADDR_HI);
mux_addr_lo = XP_GET_BITS(reg, XP_PROP_4, MUX_ADDR_LO);
if (mux_addr_lo == XGBE_SFP_DIRECT)
return;
phy_data->sfp_comm = XGBE_SFP_COMM_PCA9545;
phy_data->sfp_mux_address = (mux_addr_hi << 2) + mux_addr_lo;
phy_data->sfp_mux_channel = XP_GET_BITS(reg, XP_PROP_4, MUX_CHAN);
if (netif_msg_probe(pdata)) {
dev_dbg(pdata->dev, "SFP: mux_address=%#x\n",
phy_data->sfp_mux_address);
dev_dbg(pdata->dev, "SFP: mux_channel=%u\n",
phy_data->sfp_mux_channel);
}
}
static void xgbe_phy_sfp_setup(struct xgbe_prv_data *pdata)
{
xgbe_phy_sfp_comm_setup(pdata);
xgbe_phy_sfp_gpio_setup(pdata);
}
static int xgbe_phy_int_mdio_reset(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int ret;
ret = pdata->hw_if.set_gpio(pdata, phy_data->mdio_reset_gpio);
if (ret)
return ret;
ret = pdata->hw_if.clr_gpio(pdata, phy_data->mdio_reset_gpio);
return ret;
}
static int xgbe_phy_i2c_mdio_reset(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
u8 gpio_reg, gpio_ports[2], gpio_data[3];
int ret;
gpio_reg = 2;
ret = xgbe_phy_i2c_read(pdata, phy_data->mdio_reset_addr,
&gpio_reg, sizeof(gpio_reg),
gpio_ports, sizeof(gpio_ports));
if (ret)
return ret;
gpio_data[0] = 2;
gpio_data[1] = gpio_ports[0];
gpio_data[2] = gpio_ports[1];
if (phy_data->mdio_reset_gpio < 8)
gpio_data[1] |= (1 << (phy_data->mdio_reset_gpio % 8));
else
gpio_data[2] |= (1 << (phy_data->mdio_reset_gpio % 8));
ret = xgbe_phy_i2c_write(pdata, phy_data->mdio_reset_addr,
gpio_data, sizeof(gpio_data));
if (ret)
return ret;
if (phy_data->mdio_reset_gpio < 8)
gpio_data[1] &= ~(1 << (phy_data->mdio_reset_gpio % 8));
else
gpio_data[2] &= ~(1 << (phy_data->mdio_reset_gpio % 8));
ret = xgbe_phy_i2c_write(pdata, phy_data->mdio_reset_addr,
gpio_data, sizeof(gpio_data));
return ret;
}
static int xgbe_phy_mdio_reset(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
if (phy_data->conn_type != XGBE_CONN_TYPE_MDIO)
return 0;
ret = xgbe_phy_get_comm_ownership(pdata);
if (ret)
return ret;
if (phy_data->mdio_reset == XGBE_MDIO_RESET_I2C_GPIO)
ret = xgbe_phy_i2c_mdio_reset(pdata);
else if (phy_data->mdio_reset == XGBE_MDIO_RESET_INT_GPIO)
ret = xgbe_phy_int_mdio_reset(pdata);
xgbe_phy_put_comm_ownership(pdata);
return ret;
}
static bool xgbe_phy_redrv_error(struct xgbe_phy_data *phy_data)
{
if (!phy_data->redrv)
return false;
if (phy_data->redrv_if >= XGBE_PHY_REDRV_IF_MAX)
return true;
switch (phy_data->redrv_model) {
case XGBE_PHY_REDRV_MODEL_4223:
if (phy_data->redrv_lane > 3)
return true;
break;
case XGBE_PHY_REDRV_MODEL_4227:
if (phy_data->redrv_lane > 1)
return true;
break;
default:
return true;
}
return false;
}
static int xgbe_phy_mdio_reset_setup(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
unsigned int reg;
if (phy_data->conn_type != XGBE_CONN_TYPE_MDIO)
return 0;
reg = XP_IOREAD(pdata, XP_PROP_3);
phy_data->mdio_reset = XP_GET_BITS(reg, XP_PROP_3, MDIO_RESET);
switch (phy_data->mdio_reset) {
case XGBE_MDIO_RESET_NONE:
case XGBE_MDIO_RESET_I2C_GPIO:
case XGBE_MDIO_RESET_INT_GPIO:
break;
default:
dev_err(pdata->dev, "unsupported MDIO reset (%#x)\n",
phy_data->mdio_reset);
return -EINVAL;
}
if (phy_data->mdio_reset == XGBE_MDIO_RESET_I2C_GPIO) {
phy_data->mdio_reset_addr = XGBE_GPIO_ADDRESS_PCA9555 +
XP_GET_BITS(reg, XP_PROP_3,
MDIO_RESET_I2C_ADDR);
phy_data->mdio_reset_gpio = XP_GET_BITS(reg, XP_PROP_3,
MDIO_RESET_I2C_GPIO);
} else if (phy_data->mdio_reset == XGBE_MDIO_RESET_INT_GPIO) {
phy_data->mdio_reset_gpio = XP_GET_BITS(reg, XP_PROP_3,
MDIO_RESET_INT_GPIO);
}
return 0;
}
static bool xgbe_phy_port_mode_mismatch(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
if ((phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000))
return false;
break;
case XGBE_PORT_MODE_BACKPLANE_2500:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_2500)
return false;
break;
case XGBE_PORT_MODE_1000BASE_T:
if ((phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000))
return false;
break;
case XGBE_PORT_MODE_1000BASE_X:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000)
return false;
break;
case XGBE_PORT_MODE_NBASE_T:
if ((phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_2500))
return false;
break;
case XGBE_PORT_MODE_10GBASE_T:
if ((phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000))
return false;
break;
case XGBE_PORT_MODE_10GBASE_R:
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000)
return false;
break;
case XGBE_PORT_MODE_SFP:
if ((phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) ||
(phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000))
return false;
break;
default:
break;
}
return true;
}
static bool xgbe_phy_conn_type_mismatch(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
case XGBE_PORT_MODE_BACKPLANE_2500:
if (phy_data->conn_type == XGBE_CONN_TYPE_BACKPLANE)
return false;
break;
case XGBE_PORT_MODE_1000BASE_T:
case XGBE_PORT_MODE_1000BASE_X:
case XGBE_PORT_MODE_NBASE_T:
case XGBE_PORT_MODE_10GBASE_T:
case XGBE_PORT_MODE_10GBASE_R:
if (phy_data->conn_type == XGBE_CONN_TYPE_MDIO)
return false;
break;
case XGBE_PORT_MODE_SFP:
if (phy_data->conn_type == XGBE_CONN_TYPE_SFP)
return false;
break;
default:
break;
}
return true;
}
static bool xgbe_phy_port_enabled(struct xgbe_prv_data *pdata)
{
unsigned int reg;
reg = XP_IOREAD(pdata, XP_PROP_0);
if (!XP_GET_BITS(reg, XP_PROP_0, PORT_SPEEDS))
return false;
if (!XP_GET_BITS(reg, XP_PROP_0, CONN_TYPE))
return false;
return true;
}
static void xgbe_phy_stop(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
xgbe_phy_free_phy_device(pdata);
xgbe_phy_sfp_reset(phy_data);
xgbe_phy_sfp_mod_absent(pdata);
xgbe_phy_power_off(pdata);
pdata->i2c_if.i2c_stop(pdata);
}
static int xgbe_phy_start(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
int ret;
ret = pdata->i2c_if.i2c_start(pdata);
if (ret)
return ret;
if (phy_data->redrv && !phy_data->redrv_if) {
ret = pdata->hw_if.set_ext_mii_mode(pdata, phy_data->redrv_addr,
XGBE_MDIO_MODE_CL22);
if (ret) {
netdev_err(pdata->netdev,
"redriver mdio port not compatible (%u)\n",
phy_data->redrv_addr);
return ret;
}
}
xgbe_phy_set_mode(pdata, phy_data->start_mode);
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_SFP:
xgbe_phy_sfp_detect(pdata);
break;
default:
break;
}
ret = xgbe_phy_find_phy_device(pdata);
if (ret)
goto err_i2c;
return 0;
err_i2c:
pdata->i2c_if.i2c_stop(pdata);
return ret;
}
static int xgbe_phy_reset(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
enum xgbe_mode cur_mode;
int ret;
cur_mode = phy_data->cur_mode;
xgbe_phy_power_off(pdata);
xgbe_phy_set_mode(pdata, cur_mode);
if (!phy_data->phydev)
return 0;
ret = xgbe_phy_mdio_reset(pdata);
if (ret)
return ret;
return phy_init_hw(phy_data->phydev);
}
static void xgbe_phy_exit(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data = pdata->phy_data;
mdiobus_unregister(phy_data->mii);
}
static int xgbe_phy_init(struct xgbe_prv_data *pdata)
{
struct xgbe_phy_data *phy_data;
struct mii_bus *mii;
unsigned int reg;
int ret;
if (!xgbe_phy_port_enabled(pdata)) {
dev_info(pdata->dev, "device is not enabled\n");
return -ENODEV;
}
ret = pdata->i2c_if.i2c_init(pdata);
if (ret)
return ret;
phy_data = devm_kzalloc(pdata->dev, sizeof(*phy_data), GFP_KERNEL);
if (!phy_data)
return -ENOMEM;
pdata->phy_data = phy_data;
reg = XP_IOREAD(pdata, XP_PROP_0);
phy_data->port_mode = XP_GET_BITS(reg, XP_PROP_0, PORT_MODE);
phy_data->port_id = XP_GET_BITS(reg, XP_PROP_0, PORT_ID);
phy_data->port_speeds = XP_GET_BITS(reg, XP_PROP_0, PORT_SPEEDS);
phy_data->conn_type = XP_GET_BITS(reg, XP_PROP_0, CONN_TYPE);
phy_data->mdio_addr = XP_GET_BITS(reg, XP_PROP_0, MDIO_ADDR);
if (netif_msg_probe(pdata)) {
dev_dbg(pdata->dev, "port mode=%u\n", phy_data->port_mode);
dev_dbg(pdata->dev, "port id=%u\n", phy_data->port_id);
dev_dbg(pdata->dev, "port speeds=%#x\n", phy_data->port_speeds);
dev_dbg(pdata->dev, "conn type=%u\n", phy_data->conn_type);
dev_dbg(pdata->dev, "mdio addr=%u\n", phy_data->mdio_addr);
}
reg = XP_IOREAD(pdata, XP_PROP_4);
phy_data->redrv = XP_GET_BITS(reg, XP_PROP_4, REDRV_PRESENT);
phy_data->redrv_if = XP_GET_BITS(reg, XP_PROP_4, REDRV_IF);
phy_data->redrv_addr = XP_GET_BITS(reg, XP_PROP_4, REDRV_ADDR);
phy_data->redrv_lane = XP_GET_BITS(reg, XP_PROP_4, REDRV_LANE);
phy_data->redrv_model = XP_GET_BITS(reg, XP_PROP_4, REDRV_MODEL);
if (phy_data->redrv && netif_msg_probe(pdata)) {
dev_dbg(pdata->dev, "redrv present\n");
dev_dbg(pdata->dev, "redrv i/f=%u\n", phy_data->redrv_if);
dev_dbg(pdata->dev, "redrv addr=%#x\n", phy_data->redrv_addr);
dev_dbg(pdata->dev, "redrv lane=%u\n", phy_data->redrv_lane);
dev_dbg(pdata->dev, "redrv model=%u\n", phy_data->redrv_model);
}
if (xgbe_phy_conn_type_mismatch(pdata)) {
dev_err(pdata->dev, "phy mode/connection mismatch (%#x/%#x)\n",
phy_data->port_mode, phy_data->conn_type);
return -EINVAL;
}
if (xgbe_phy_port_mode_mismatch(pdata)) {
dev_err(pdata->dev, "phy mode/speed mismatch (%#x/%#x)\n",
phy_data->port_mode, phy_data->port_speeds);
return -EINVAL;
}
ret = xgbe_phy_mdio_reset_setup(pdata);
if (ret)
return ret;
if (xgbe_phy_redrv_error(phy_data)) {
dev_err(pdata->dev, "phy re-driver settings error\n");
return -EINVAL;
}
pdata->kr_redrv = phy_data->redrv;
phy_data->cur_mode = XGBE_MODE_UNKNOWN;
pdata->phy.supported = 0;
switch (phy_data->port_mode) {
case XGBE_PORT_MODE_BACKPLANE:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_Backplane;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) {
pdata->phy.supported |= SUPPORTED_1000baseKX_Full;
phy_data->start_mode = XGBE_MODE_KX_1000;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000) {
pdata->phy.supported |= SUPPORTED_10000baseKR_Full;
if (pdata->fec_ability & MDIO_PMA_10GBR_FECABLE_ABLE)
pdata->phy.supported |=
SUPPORTED_10000baseR_FEC;
phy_data->start_mode = XGBE_MODE_KR;
}
phy_data->phydev_mode = XGBE_MDIO_MODE_NONE;
break;
case XGBE_PORT_MODE_BACKPLANE_2500:
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_Backplane;
pdata->phy.supported |= SUPPORTED_2500baseX_Full;
phy_data->start_mode = XGBE_MODE_KX_2500;
phy_data->phydev_mode = XGBE_MDIO_MODE_NONE;
break;
case XGBE_PORT_MODE_1000BASE_T:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_TP;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) {
pdata->phy.supported |= SUPPORTED_100baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_100;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) {
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_1000;
}
phy_data->phydev_mode = XGBE_MDIO_MODE_CL22;
break;
case XGBE_PORT_MODE_1000BASE_X:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_FIBRE;
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
phy_data->start_mode = XGBE_MODE_X;
phy_data->phydev_mode = XGBE_MDIO_MODE_CL22;
break;
case XGBE_PORT_MODE_NBASE_T:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_TP;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) {
pdata->phy.supported |= SUPPORTED_100baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_100;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) {
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_1000;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_2500) {
pdata->phy.supported |= SUPPORTED_2500baseX_Full;
phy_data->start_mode = XGBE_MODE_KX_2500;
}
phy_data->phydev_mode = XGBE_MDIO_MODE_CL45;
break;
case XGBE_PORT_MODE_10GBASE_T:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_TP;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) {
pdata->phy.supported |= SUPPORTED_100baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_100;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) {
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_1000;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000) {
pdata->phy.supported |= SUPPORTED_10000baseT_Full;
phy_data->start_mode = XGBE_MODE_KR;
}
phy_data->phydev_mode = XGBE_MDIO_MODE_NONE;
break;
case XGBE_PORT_MODE_10GBASE_R:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_TP;
pdata->phy.supported |= SUPPORTED_10000baseT_Full;
if (pdata->fec_ability & MDIO_PMA_10GBR_FECABLE_ABLE)
pdata->phy.supported |= SUPPORTED_10000baseR_FEC;
phy_data->start_mode = XGBE_MODE_SFI;
phy_data->phydev_mode = XGBE_MDIO_MODE_NONE;
break;
case XGBE_PORT_MODE_SFP:
pdata->phy.supported |= SUPPORTED_Autoneg;
pdata->phy.supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
pdata->phy.supported |= SUPPORTED_TP;
pdata->phy.supported |= SUPPORTED_FIBRE;
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_100) {
pdata->phy.supported |= SUPPORTED_100baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_100;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_1000) {
pdata->phy.supported |= SUPPORTED_1000baseT_Full;
phy_data->start_mode = XGBE_MODE_SGMII_1000;
}
if (phy_data->port_speeds & XGBE_PHY_PORT_SPEED_10000) {
pdata->phy.supported |= SUPPORTED_10000baseT_Full;
phy_data->start_mode = XGBE_MODE_SFI;
}
phy_data->phydev_mode = XGBE_MDIO_MODE_CL22;
xgbe_phy_sfp_setup(pdata);
break;
default:
return -EINVAL;
}
if (netif_msg_probe(pdata))
dev_dbg(pdata->dev, "phy supported=%#x\n",
pdata->phy.supported);
if ((phy_data->conn_type & XGBE_CONN_TYPE_MDIO) &&
(phy_data->phydev_mode != XGBE_MDIO_MODE_NONE)) {
ret = pdata->hw_if.set_ext_mii_mode(pdata, phy_data->mdio_addr,
phy_data->phydev_mode);
if (ret) {
dev_err(pdata->dev,
"mdio port/clause not compatible (%d/%u)\n",
phy_data->mdio_addr, phy_data->phydev_mode);
return -EINVAL;
}
}
if (phy_data->redrv && !phy_data->redrv_if) {
ret = pdata->hw_if.set_ext_mii_mode(pdata, phy_data->redrv_addr,
XGBE_MDIO_MODE_CL22);
if (ret) {
dev_err(pdata->dev,
"redriver mdio port not compatible (%u)\n",
phy_data->redrv_addr);
return -EINVAL;
}
}
mii = devm_mdiobus_alloc(pdata->dev);
if (!mii) {
dev_err(pdata->dev, "mdiobus_alloc failed\n");
return -ENOMEM;
}
mii->priv = pdata;
mii->name = "amd-xgbe-mii";
mii->read = xgbe_phy_mii_read;
mii->write = xgbe_phy_mii_write;
mii->parent = pdata->dev;
mii->phy_mask = ~0;
snprintf(mii->id, sizeof(mii->id), "%s", dev_name(pdata->dev));
ret = mdiobus_register(mii);
if (ret) {
dev_err(pdata->dev, "mdiobus_register failed\n");
return ret;
}
phy_data->mii = mii;
return 0;
}
void xgbe_init_function_ptrs_phy_v2(struct xgbe_phy_if *phy_if)
{
struct xgbe_phy_impl_if *phy_impl = &phy_if->phy_impl;
phy_impl->init = xgbe_phy_init;
phy_impl->exit = xgbe_phy_exit;
phy_impl->reset = xgbe_phy_reset;
phy_impl->start = xgbe_phy_start;
phy_impl->stop = xgbe_phy_stop;
phy_impl->link_status = xgbe_phy_link_status;
phy_impl->valid_speed = xgbe_phy_valid_speed;
phy_impl->use_mode = xgbe_phy_use_mode;
phy_impl->set_mode = xgbe_phy_set_mode;
phy_impl->get_mode = xgbe_phy_get_mode;
phy_impl->switch_mode = xgbe_phy_switch_mode;
phy_impl->cur_mode = xgbe_phy_cur_mode;
phy_impl->an_mode = xgbe_phy_an_mode;
phy_impl->an_config = xgbe_phy_an_config;
phy_impl->an_advertising = xgbe_phy_an_advertising;
phy_impl->an_outcome = xgbe_phy_an_outcome;
}
