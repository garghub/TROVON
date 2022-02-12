static int efx_poke_lm87(struct i2c_client *client, const u8 *reg_values)
{
while (*reg_values) {
u8 reg = *reg_values++;
u8 value = *reg_values++;
int rc = i2c_smbus_write_byte_data(client, reg, value);
if (rc)
return rc;
}
return 0;
}
static int efx_init_lm87(struct efx_nic *efx, struct i2c_board_info *info,
const u8 *reg_values)
{
struct falcon_board *board = falcon_board(efx);
struct i2c_client *client = i2c_new_device(&board->i2c_adap, info);
int rc;
if (!client)
return -EIO;
i2c_smbus_read_byte_data(client, LM87_REG_ALARMS1);
i2c_smbus_read_byte_data(client, LM87_REG_ALARMS2);
rc = efx_poke_lm87(client, reg_values);
if (rc)
goto err;
rc = efx_poke_lm87(client, falcon_lm87_common_regs);
if (rc)
goto err;
board->hwmon_client = client;
return 0;
err:
i2c_unregister_device(client);
return rc;
}
static void efx_fini_lm87(struct efx_nic *efx)
{
i2c_unregister_device(falcon_board(efx)->hwmon_client);
}
static int efx_check_lm87(struct efx_nic *efx, unsigned mask)
{
struct i2c_client *client = falcon_board(efx)->hwmon_client;
bool temp_crit, elec_fault, is_failure;
u16 alarms;
s32 reg;
if (EFX_WORKAROUND_7884(efx) && efx->link_state.up)
return 0;
reg = i2c_smbus_read_byte_data(client, LM87_REG_ALARMS1);
if (reg < 0)
return reg;
alarms = reg;
reg = i2c_smbus_read_byte_data(client, LM87_REG_ALARMS2);
if (reg < 0)
return reg;
alarms |= reg << 8;
alarms &= mask;
temp_crit = false;
if (alarms & LM87_ALARM_TEMP_INT) {
reg = i2c_smbus_read_byte_data(client, LM87_REG_TEMP_INT);
if (reg < 0)
return reg;
if (reg > FALCON_BOARD_TEMP_CRIT)
temp_crit = true;
}
if (alarms & LM87_ALARM_TEMP_EXT1) {
reg = i2c_smbus_read_byte_data(client, LM87_REG_TEMP_EXT1);
if (reg < 0)
return reg;
if (reg > FALCON_JUNC_TEMP_CRIT)
temp_crit = true;
}
elec_fault = alarms & ~(LM87_ALARM_TEMP_INT | LM87_ALARM_TEMP_EXT1);
is_failure = temp_crit || elec_fault;
if (alarms)
netif_err(efx, hw, efx->net_dev,
"LM87 detected a hardware %s (status %02x:%02x)"
"%s%s%s%s\n",
is_failure ? "failure" : "problem",
alarms & 0xff, alarms >> 8,
(alarms & LM87_ALARM_TEMP_INT) ?
"; board is overheating" : "",
(alarms & LM87_ALARM_TEMP_EXT1) ?
"; controller is overheating" : "",
temp_crit ? "; reached critical temperature" : "",
elec_fault ? "; electrical fault" : "");
return is_failure ? -ERANGE : 0;
}
static inline int
efx_init_lm87(struct efx_nic *efx, struct i2c_board_info *info,
const u8 *reg_values)
{
return 0;
}
static inline void efx_fini_lm87(struct efx_nic *efx)
{
}
static inline int efx_check_lm87(struct efx_nic *efx, unsigned mask)
{
return 0;
}
static void sfe4001_poweroff(struct efx_nic *efx)
{
struct i2c_client *ioexp_client = falcon_board(efx)->ioexp_client;
struct i2c_client *hwmon_client = falcon_board(efx)->hwmon_client;
i2c_smbus_write_byte_data(ioexp_client, P0_OUT, 0xff);
i2c_smbus_write_byte_data(ioexp_client, P1_CONFIG, 0xff);
i2c_smbus_write_byte_data(ioexp_client, P0_CONFIG, 0xff);
i2c_smbus_read_byte_data(hwmon_client, MAX664X_REG_RSL);
}
static int sfe4001_poweron(struct efx_nic *efx)
{
struct i2c_client *ioexp_client = falcon_board(efx)->ioexp_client;
struct i2c_client *hwmon_client = falcon_board(efx)->hwmon_client;
unsigned int i, j;
int rc;
u8 out;
rc = i2c_smbus_read_byte_data(hwmon_client, MAX664X_REG_RSL);
if (rc < 0)
return rc;
rc = i2c_smbus_write_byte_data(ioexp_client, P0_CONFIG, 0x00);
if (rc)
return rc;
rc = i2c_smbus_write_byte_data(ioexp_client, P1_CONFIG,
0xff & ~(1 << P1_SPARE_LBN));
if (rc)
goto fail_on;
rc = i2c_smbus_read_byte_data(ioexp_client, P0_OUT);
if (rc < 0)
goto fail_on;
out = 0xff & ~((0 << P0_EN_1V2_LBN) | (0 << P0_EN_2V5_LBN) |
(0 << P0_EN_3V3X_LBN) | (0 << P0_EN_5V_LBN) |
(0 << P0_EN_1V0X_LBN));
if (rc != out) {
netif_info(efx, hw, efx->net_dev, "power-cycling PHY\n");
rc = i2c_smbus_write_byte_data(ioexp_client, P0_OUT, out);
if (rc)
goto fail_on;
schedule_timeout_uninterruptible(HZ);
}
for (i = 0; i < 20; ++i) {
out = 0xff & ~((1 << P0_EN_1V2_LBN) | (1 << P0_EN_2V5_LBN) |
(1 << P0_EN_3V3X_LBN) | (1 << P0_EN_5V_LBN) |
(1 << P0_X_TRST_LBN));
if (efx->phy_mode & PHY_MODE_SPECIAL)
out |= 1 << P0_EN_3V3X_LBN;
rc = i2c_smbus_write_byte_data(ioexp_client, P0_OUT, out);
if (rc)
goto fail_on;
msleep(10);
out &= ~(1 << P0_EN_1V0X_LBN);
rc = i2c_smbus_write_byte_data(ioexp_client, P0_OUT, out);
if (rc)
goto fail_on;
netif_info(efx, hw, efx->net_dev,
"waiting for DSP boot (attempt %d)...\n", i);
if (efx->phy_mode & PHY_MODE_SPECIAL) {
schedule_timeout_uninterruptible(HZ);
return 0;
}
for (j = 0; j < 10; ++j) {
msleep(100);
rc = i2c_smbus_read_byte_data(ioexp_client, P1_IN);
if (rc < 0)
goto fail_on;
if (rc & (1 << P1_AFE_PWD_LBN))
return 0;
}
}
netif_info(efx, hw, efx->net_dev, "timed out waiting for DSP boot\n");
rc = -ETIMEDOUT;
fail_on:
sfe4001_poweroff(efx);
return rc;
}
static ssize_t show_phy_flash_cfg(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
return sprintf(buf, "%d\n", !!(efx->phy_mode & PHY_MODE_SPECIAL));
}
static ssize_t set_phy_flash_cfg(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
enum efx_phy_mode old_mode, new_mode;
int err;
rtnl_lock();
old_mode = efx->phy_mode;
if (count == 0 || *buf == '0')
new_mode = old_mode & ~PHY_MODE_SPECIAL;
else
new_mode = PHY_MODE_SPECIAL;
if (!((old_mode ^ new_mode) & PHY_MODE_SPECIAL)) {
err = 0;
} else if (efx->state != STATE_RUNNING || netif_running(efx->net_dev)) {
err = -EBUSY;
} else {
efx->phy_mode = new_mode;
if (new_mode & PHY_MODE_SPECIAL)
falcon_stop_nic_stats(efx);
err = sfe4001_poweron(efx);
if (!err)
err = efx_reconfigure_port(efx);
if (!(new_mode & PHY_MODE_SPECIAL))
falcon_start_nic_stats(efx);
}
rtnl_unlock();
return err ? err : count;
}
static void sfe4001_fini(struct efx_nic *efx)
{
struct falcon_board *board = falcon_board(efx);
netif_info(efx, drv, efx->net_dev, "%s\n", __func__);
device_remove_file(&efx->pci_dev->dev, &dev_attr_phy_flash_cfg);
sfe4001_poweroff(efx);
i2c_unregister_device(board->ioexp_client);
i2c_unregister_device(board->hwmon_client);
}
static int sfe4001_check_hw(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
s32 status;
if (EFX_WORKAROUND_7884(efx) && !nic_data->xmac_poll_required)
return 0;
status = i2c_smbus_read_byte_data(falcon_board(efx)->ioexp_client, P1_IN);
if (status >= 0 &&
(status & ((1 << P1_AFE_PWD_LBN) | (1 << P1_DSP_PWD25_LBN))) != 0)
return 0;
sfe4001_poweroff(efx);
efx->phy_mode = PHY_MODE_OFF;
return (status < 0) ? -EIO : -ERANGE;
}
static int sfe4001_init(struct efx_nic *efx)
{
struct falcon_board *board = falcon_board(efx);
int rc;
#if defined(CONFIG_SENSORS_LM90) || defined(CONFIG_SENSORS_LM90_MODULE)
board->hwmon_client =
i2c_new_device(&board->i2c_adap, &sfe4001_hwmon_info);
#else
board->hwmon_client =
i2c_new_dummy(&board->i2c_adap, sfe4001_hwmon_info.addr);
#endif
if (!board->hwmon_client)
return -EIO;
rc = i2c_smbus_write_byte_data(board->hwmon_client,
MAX664X_REG_WLHO, 90);
if (rc)
goto fail_hwmon;
board->ioexp_client = i2c_new_dummy(&board->i2c_adap, PCA9539);
if (!board->ioexp_client) {
rc = -EIO;
goto fail_hwmon;
}
if (efx->phy_mode & PHY_MODE_SPECIAL) {
falcon_stop_nic_stats(efx);
}
rc = sfe4001_poweron(efx);
if (rc)
goto fail_ioexp;
rc = device_create_file(&efx->pci_dev->dev, &dev_attr_phy_flash_cfg);
if (rc)
goto fail_on;
netif_info(efx, hw, efx->net_dev, "PHY is powered on\n");
return 0;
fail_on:
sfe4001_poweroff(efx);
fail_ioexp:
i2c_unregister_device(board->ioexp_client);
fail_hwmon:
i2c_unregister_device(board->hwmon_client);
return rc;
}
static void sfe4002_init_phy(struct efx_nic *efx)
{
falcon_qt202x_set_led(efx, SFE4002_TX_LED,
QUAKE_LED_TXLINK | QUAKE_LED_LINK_ACTSTAT);
falcon_qt202x_set_led(efx, SFE4002_RX_LED,
QUAKE_LED_RXLINK | QUAKE_LED_LINK_ACTSTAT);
falcon_qt202x_set_led(efx, SFE4002_FAULT_LED, QUAKE_LED_OFF);
}
static void sfe4002_set_id_led(struct efx_nic *efx, enum efx_led_mode mode)
{
falcon_qt202x_set_led(
efx, SFE4002_FAULT_LED,
(mode == EFX_LED_ON) ? QUAKE_LED_ON : QUAKE_LED_OFF);
}
static int sfe4002_check_hw(struct efx_nic *efx)
{
struct falcon_board *board = falcon_board(efx);
unsigned alarm_mask =
(board->major == 0 && board->minor == 0) ?
~LM87_ALARM_TEMP_EXT1 : ~0;
return efx_check_lm87(efx, alarm_mask);
}
static int sfe4002_init(struct efx_nic *efx)
{
return efx_init_lm87(efx, &sfe4002_hwmon_info, sfe4002_lm87_regs);
}
static void sfn4112f_init_phy(struct efx_nic *efx)
{
falcon_qt202x_set_led(efx, SFN4112F_ACT_LED,
QUAKE_LED_RXLINK | QUAKE_LED_LINK_ACT);
falcon_qt202x_set_led(efx, SFN4112F_LINK_LED,
QUAKE_LED_RXLINK | QUAKE_LED_LINK_STAT);
}
static void sfn4112f_set_id_led(struct efx_nic *efx, enum efx_led_mode mode)
{
int reg;
switch (mode) {
case EFX_LED_OFF:
reg = QUAKE_LED_OFF;
break;
case EFX_LED_ON:
reg = QUAKE_LED_ON;
break;
default:
reg = QUAKE_LED_RXLINK | QUAKE_LED_LINK_STAT;
break;
}
falcon_qt202x_set_led(efx, SFN4112F_LINK_LED, reg);
}
static int sfn4112f_check_hw(struct efx_nic *efx)
{
return efx_check_lm87(efx, ~0x48);
}
static int sfn4112f_init(struct efx_nic *efx)
{
return efx_init_lm87(efx, &sfn4112f_hwmon_info, sfn4112f_lm87_regs);
}
static void sfe4003_set_id_led(struct efx_nic *efx, enum efx_led_mode mode)
{
struct falcon_board *board = falcon_board(efx);
if (board->minor < 3 && board->major == 0)
return;
falcon_txc_set_gpio_val(
efx, SFE4003_RED_LED_GPIO,
(mode == EFX_LED_ON) ? SFE4003_LED_ON : SFE4003_LED_OFF);
}
static void sfe4003_init_phy(struct efx_nic *efx)
{
struct falcon_board *board = falcon_board(efx);
if (board->minor < 3 && board->major == 0)
return;
falcon_txc_set_gpio_dir(efx, SFE4003_RED_LED_GPIO, TXC_GPIO_DIR_OUTPUT);
falcon_txc_set_gpio_val(efx, SFE4003_RED_LED_GPIO, SFE4003_LED_OFF);
}
static int sfe4003_check_hw(struct efx_nic *efx)
{
struct falcon_board *board = falcon_board(efx);
unsigned alarm_mask =
(board->major == 0 && board->minor <= 2) ?
~LM87_ALARM_TEMP_EXT1 : ~0;
return efx_check_lm87(efx, alarm_mask);
}
static int sfe4003_init(struct efx_nic *efx)
{
return efx_init_lm87(efx, &sfe4003_hwmon_info, sfe4003_lm87_regs);
}
int falcon_probe_board(struct efx_nic *efx, u16 revision_info)
{
struct falcon_board *board = falcon_board(efx);
u8 type_id = FALCON_BOARD_TYPE(revision_info);
int i;
board->major = FALCON_BOARD_MAJOR(revision_info);
board->minor = FALCON_BOARD_MINOR(revision_info);
for (i = 0; i < ARRAY_SIZE(board_types); i++)
if (board_types[i].id == type_id)
board->type = &board_types[i];
if (board->type) {
netif_info(efx, probe, efx->net_dev, "board is %s rev %c%d\n",
(efx->pci_dev->subsystem_vendor == EFX_VENDID_SFC)
? board->type->ref_model : board->type->gen_type,
'A' + board->major, board->minor);
return 0;
} else {
netif_err(efx, probe, efx->net_dev, "unknown board type %d\n",
type_id);
return -ENODEV;
}
}
