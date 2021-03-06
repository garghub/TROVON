static inline int at76_is_intersil(enum board_type board)
{
return (board == BOARD_503_ISL3861 || board == BOARD_503_ISL3863);
}
static inline int at76_is_503rfmd(enum board_type board)
{
return (board == BOARD_503 || board == BOARD_503_ACC);
}
static inline int at76_is_505a(enum board_type board)
{
return (board == BOARD_505A || board == BOARD_505AMX);
}
static int at76_load_int_fw_block(struct usb_device *udev, int blockno,
void *block, int size)
{
return usb_control_msg(udev, usb_sndctrlpipe(udev, 0), DFU_DNLOAD,
USB_TYPE_CLASS | USB_DIR_OUT |
USB_RECIP_INTERFACE, blockno, 0, block, size,
USB_CTRL_GET_TIMEOUT);
}
static int at76_dfu_get_status(struct usb_device *udev,
struct dfu_status *status)
{
int ret;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), DFU_GETSTATUS,
USB_TYPE_CLASS | USB_DIR_IN | USB_RECIP_INTERFACE,
0, 0, status, sizeof(struct dfu_status),
USB_CTRL_GET_TIMEOUT);
return ret;
}
static int at76_dfu_get_state(struct usb_device *udev, u8 *state)
{
int ret;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), DFU_GETSTATE,
USB_TYPE_CLASS | USB_DIR_IN | USB_RECIP_INTERFACE,
0, 0, state, 1, USB_CTRL_GET_TIMEOUT);
return ret;
}
static inline unsigned long at76_get_timeout(struct dfu_status *s)
{
return msecs_to_jiffies((s->poll_timeout[2] << 16)
| (s->poll_timeout[1] << 8)
| (s->poll_timeout[0]));
}
static int at76_usbdfu_download(struct usb_device *udev, u8 *buf, u32 size,
int manifest_sync_timeout)
{
u8 *block;
struct dfu_status dfu_stat_buf;
int ret = 0;
int need_dfu_state = 1;
int is_done = 0;
u8 dfu_state = 0;
u32 dfu_timeout = 0;
int bsize = 0;
int blockno = 0;
at76_dbg(DBG_DFU, "%s( %p, %u, %d)", __func__, buf, size,
manifest_sync_timeout);
if (!size) {
dev_err(&udev->dev, "FW buffer length invalid!\n");
return -EINVAL;
}
block = kmalloc(FW_BLOCK_SIZE, GFP_KERNEL);
if (!block)
return -ENOMEM;
do {
if (need_dfu_state) {
ret = at76_dfu_get_state(udev, &dfu_state);
if (ret < 0) {
dev_err(&udev->dev,
"cannot get DFU state: %d\n", ret);
goto exit;
}
need_dfu_state = 0;
}
switch (dfu_state) {
case STATE_DFU_DOWNLOAD_SYNC:
at76_dbg(DBG_DFU, "STATE_DFU_DOWNLOAD_SYNC");
ret = at76_dfu_get_status(udev, &dfu_stat_buf);
if (ret >= 0) {
dfu_state = dfu_stat_buf.state;
dfu_timeout = at76_get_timeout(&dfu_stat_buf);
need_dfu_state = 0;
} else
dev_err(&udev->dev,
"at76_dfu_get_status returned %d\n",
ret);
break;
case STATE_DFU_DOWNLOAD_BUSY:
at76_dbg(DBG_DFU, "STATE_DFU_DOWNLOAD_BUSY");
need_dfu_state = 1;
at76_dbg(DBG_DFU, "DFU: Resetting device");
schedule_timeout_interruptible(dfu_timeout);
break;
case STATE_DFU_DOWNLOAD_IDLE:
at76_dbg(DBG_DFU, "DOWNLOAD...");
case STATE_DFU_IDLE:
at76_dbg(DBG_DFU, "DFU IDLE");
bsize = min_t(int, size, FW_BLOCK_SIZE);
memcpy(block, buf, bsize);
at76_dbg(DBG_DFU, "int fw, size left = %5d, "
"bsize = %4d, blockno = %2d", size, bsize,
blockno);
ret =
at76_load_int_fw_block(udev, blockno, block, bsize);
buf += bsize;
size -= bsize;
blockno++;
if (ret != bsize)
dev_err(&udev->dev,
"at76_load_int_fw_block returned %d\n",
ret);
need_dfu_state = 1;
break;
case STATE_DFU_MANIFEST_SYNC:
at76_dbg(DBG_DFU, "STATE_DFU_MANIFEST_SYNC");
ret = at76_dfu_get_status(udev, &dfu_stat_buf);
if (ret < 0)
break;
dfu_state = dfu_stat_buf.state;
dfu_timeout = at76_get_timeout(&dfu_stat_buf);
need_dfu_state = 0;
if (manifest_sync_timeout > 0)
dfu_timeout = manifest_sync_timeout;
at76_dbg(DBG_DFU, "DFU: Waiting for manifest phase");
schedule_timeout_interruptible(dfu_timeout);
break;
case STATE_DFU_MANIFEST:
at76_dbg(DBG_DFU, "STATE_DFU_MANIFEST");
is_done = 1;
break;
case STATE_DFU_MANIFEST_WAIT_RESET:
at76_dbg(DBG_DFU, "STATE_DFU_MANIFEST_WAIT_RESET");
is_done = 1;
break;
case STATE_DFU_UPLOAD_IDLE:
at76_dbg(DBG_DFU, "STATE_DFU_UPLOAD_IDLE");
break;
case STATE_DFU_ERROR:
at76_dbg(DBG_DFU, "STATE_DFU_ERROR");
ret = -EPIPE;
break;
default:
at76_dbg(DBG_DFU, "DFU UNKNOWN STATE (%d)", dfu_state);
ret = -EINVAL;
break;
}
} while (!is_done && (ret >= 0));
exit:
kfree(block);
if (ret >= 0)
ret = 0;
return ret;
}
static void at76_ledtrig_tx_timerfunc(unsigned long data)
{
static int tx_lastactivity;
if (tx_lastactivity != tx_activity) {
tx_lastactivity = tx_activity;
led_trigger_event(ledtrig_tx, LED_FULL);
mod_timer(&ledtrig_tx_timer, jiffies + HZ / 4);
} else
led_trigger_event(ledtrig_tx, LED_OFF);
}
static void at76_ledtrig_tx_activity(void)
{
tx_activity++;
if (!timer_pending(&ledtrig_tx_timer))
mod_timer(&ledtrig_tx_timer, jiffies + HZ / 4);
}
static int at76_remap(struct usb_device *udev)
{
int ret;
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x0a,
USB_TYPE_VENDOR | USB_DIR_OUT |
USB_RECIP_INTERFACE, 0, 0, NULL, 0,
USB_CTRL_GET_TIMEOUT);
if (ret < 0)
return ret;
return 0;
}
static int at76_get_op_mode(struct usb_device *udev)
{
int ret;
u8 saved;
u8 *op_mode;
op_mode = kmalloc(1, GFP_NOIO);
if (!op_mode)
return -ENOMEM;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x33,
USB_TYPE_VENDOR | USB_DIR_IN |
USB_RECIP_INTERFACE, 0x01, 0, op_mode, 1,
USB_CTRL_GET_TIMEOUT);
saved = *op_mode;
kfree(op_mode);
if (ret < 0)
return ret;
else if (ret < 1)
return -EIO;
else
return saved;
}
static inline int at76_load_ext_fw_block(struct usb_device *udev, int blockno,
void *block, int size)
{
return usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x0e,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
0x0802, blockno, block, size,
USB_CTRL_GET_TIMEOUT);
}
static inline int at76_get_hw_cfg(struct usb_device *udev,
union at76_hwcfg *buf, int buf_size)
{
return usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x33,
USB_TYPE_VENDOR | USB_DIR_IN |
USB_RECIP_INTERFACE, 0x0a02, 0,
buf, buf_size, USB_CTRL_GET_TIMEOUT);
}
static inline int at76_get_hw_cfg_intersil(struct usb_device *udev,
union at76_hwcfg *buf, int buf_size)
{
return usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x33,
USB_TYPE_VENDOR | USB_DIR_IN |
USB_RECIP_INTERFACE, 0x0902, 0,
buf, buf_size, USB_CTRL_GET_TIMEOUT);
}
static int at76_get_hw_config(struct at76_priv *priv)
{
int ret;
union at76_hwcfg *hwcfg = kmalloc(sizeof(*hwcfg), GFP_KERNEL);
if (!hwcfg)
return -ENOMEM;
if (at76_is_intersil(priv->board_type)) {
ret = at76_get_hw_cfg_intersil(priv->udev, hwcfg,
sizeof(hwcfg->i));
if (ret < 0)
goto exit;
memcpy(priv->mac_addr, hwcfg->i.mac_addr, ETH_ALEN);
priv->regulatory_domain = hwcfg->i.regulatory_domain;
} else if (at76_is_503rfmd(priv->board_type)) {
ret = at76_get_hw_cfg(priv->udev, hwcfg, sizeof(hwcfg->r3));
if (ret < 0)
goto exit;
memcpy(priv->mac_addr, hwcfg->r3.mac_addr, ETH_ALEN);
priv->regulatory_domain = hwcfg->r3.regulatory_domain;
} else {
ret = at76_get_hw_cfg(priv->udev, hwcfg, sizeof(hwcfg->r5));
if (ret < 0)
goto exit;
memcpy(priv->mac_addr, hwcfg->r5.mac_addr, ETH_ALEN);
priv->regulatory_domain = hwcfg->r5.regulatory_domain;
}
exit:
kfree(hwcfg);
if (ret < 0)
wiphy_err(priv->hw->wiphy, "cannot get HW Config (error %d)\n",
ret);
return ret;
}
static struct reg_domain const *at76_get_reg_domain(u16 code)
{
int i;
static struct reg_domain const fd_tab[] = {
{ 0x10, "FCC (USA)", 0x7ff },
{ 0x20, "IC (Canada)", 0x7ff },
{ 0x30, "ETSI (most of Europe)", 0x1fff },
{ 0x31, "Spain", 0x600 },
{ 0x32, "France", 0x1e00 },
{ 0x40, "MKK (Japan)", 0x2000 },
{ 0x41, "MKK1 (Japan)", 0x3fff },
{ 0x50, "Israel", 0x3fc },
{ 0x00, "<unknown>", 0xffffffff }
};
for (i = 0; i < ARRAY_SIZE(fd_tab) - 1; i++)
if (code == fd_tab[i].code)
break;
return &fd_tab[i];
}
static inline int at76_get_mib(struct usb_device *udev, u16 mib, void *buf,
int buf_size)
{
int ret;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x33,
USB_TYPE_VENDOR | USB_DIR_IN |
USB_RECIP_INTERFACE, mib << 8, 0, buf, buf_size,
USB_CTRL_GET_TIMEOUT);
if (ret >= 0 && ret != buf_size)
return -EIO;
return ret;
}
static inline int at76_get_cmd_status(struct usb_device *udev, u8 cmd)
{
u8 *stat_buf;
int ret;
stat_buf = kmalloc(40, GFP_NOIO);
if (!stat_buf)
return -ENOMEM;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x22,
USB_TYPE_VENDOR | USB_DIR_IN |
USB_RECIP_INTERFACE, cmd, 0, stat_buf,
40, USB_CTRL_GET_TIMEOUT);
if (ret >= 0)
ret = stat_buf[5];
kfree(stat_buf);
return ret;
}
static const char *at76_get_cmd_string(u8 cmd_status)
{
switch (cmd_status) {
MAKE_CMD_CASE(CMD_SET_MIB);
MAKE_CMD_CASE(CMD_GET_MIB);
MAKE_CMD_CASE(CMD_SCAN);
MAKE_CMD_CASE(CMD_JOIN);
MAKE_CMD_CASE(CMD_START_IBSS);
MAKE_CMD_CASE(CMD_RADIO_ON);
MAKE_CMD_CASE(CMD_RADIO_OFF);
MAKE_CMD_CASE(CMD_STARTUP);
}
return "UNKNOWN";
}
static int at76_set_card_command(struct usb_device *udev, u8 cmd, void *buf,
int buf_size)
{
int ret;
struct at76_command *cmd_buf = kmalloc(sizeof(struct at76_command) +
buf_size, GFP_KERNEL);
if (!cmd_buf)
return -ENOMEM;
cmd_buf->cmd = cmd;
cmd_buf->reserved = 0;
cmd_buf->size = cpu_to_le16(buf_size);
memcpy(cmd_buf->data, buf, buf_size);
at76_dbg_dump(DBG_CMD, cmd_buf, sizeof(struct at76_command) + buf_size,
"issuing command %s (0x%02x)",
at76_get_cmd_string(cmd), cmd);
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x0e,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
0, 0, cmd_buf,
sizeof(struct at76_command) + buf_size,
USB_CTRL_GET_TIMEOUT);
kfree(cmd_buf);
return ret;
}
static const char *at76_get_cmd_status_string(u8 cmd_status)
{
switch (cmd_status) {
MAKE_CMD_STATUS_CASE(CMD_STATUS_IDLE);
MAKE_CMD_STATUS_CASE(CMD_STATUS_COMPLETE);
MAKE_CMD_STATUS_CASE(CMD_STATUS_UNKNOWN);
MAKE_CMD_STATUS_CASE(CMD_STATUS_INVALID_PARAMETER);
MAKE_CMD_STATUS_CASE(CMD_STATUS_FUNCTION_NOT_SUPPORTED);
MAKE_CMD_STATUS_CASE(CMD_STATUS_TIME_OUT);
MAKE_CMD_STATUS_CASE(CMD_STATUS_IN_PROGRESS);
MAKE_CMD_STATUS_CASE(CMD_STATUS_HOST_FAILURE);
MAKE_CMD_STATUS_CASE(CMD_STATUS_SCAN_FAILED);
}
return "UNKNOWN";
}
static int at76_wait_completion(struct at76_priv *priv, int cmd)
{
int status = 0;
unsigned long timeout = jiffies + CMD_COMPLETION_TIMEOUT;
do {
status = at76_get_cmd_status(priv->udev, cmd);
if (status < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_cmd_status failed: %d\n",
status);
break;
}
at76_dbg(DBG_WAIT_COMPLETE,
"%s: Waiting on cmd %d, status = %d (%s)",
wiphy_name(priv->hw->wiphy), cmd, status,
at76_get_cmd_status_string(status));
if (status != CMD_STATUS_IN_PROGRESS
&& status != CMD_STATUS_IDLE)
break;
schedule_timeout_interruptible(HZ / 10);
if (time_after(jiffies, timeout)) {
wiphy_err(priv->hw->wiphy,
"completion timeout for command %d\n", cmd);
status = -ETIMEDOUT;
break;
}
} while (1);
return status;
}
static int at76_set_mib(struct at76_priv *priv, struct set_mib_buffer *buf)
{
int ret;
ret = at76_set_card_command(priv->udev, CMD_SET_MIB, buf,
offsetof(struct set_mib_buffer,
data) + buf->size);
if (ret < 0)
return ret;
ret = at76_wait_completion(priv, CMD_SET_MIB);
if (ret != CMD_STATUS_COMPLETE) {
wiphy_info(priv->hw->wiphy,
"set_mib: at76_wait_completion failed with %d\n",
ret);
ret = -EIO;
}
return ret;
}
static int at76_set_radio(struct at76_priv *priv, int enable)
{
int ret;
int cmd;
if (priv->radio_on == enable)
return 0;
cmd = enable ? CMD_RADIO_ON : CMD_RADIO_OFF;
ret = at76_set_card_command(priv->udev, cmd, NULL, 0);
if (ret < 0)
wiphy_err(priv->hw->wiphy,
"at76_set_card_command(%d) failed: %d\n", cmd, ret);
else
ret = 1;
priv->radio_on = enable;
return ret;
}
static int at76_set_pm_mode(struct at76_priv *priv)
{
int ret = 0;
priv->mib_buf.type = MIB_MAC_MGMT;
priv->mib_buf.size = 1;
priv->mib_buf.index = offsetof(struct mib_mac_mgmt, power_mgmt_mode);
priv->mib_buf.data.byte = priv->pm_mode;
ret = at76_set_mib(priv, &priv->mib_buf);
if (ret < 0)
wiphy_err(priv->hw->wiphy, "set_mib (pm_mode) failed: %d\n",
ret);
return ret;
}
static int at76_set_preamble(struct at76_priv *priv, u8 type)
{
int ret = 0;
priv->mib_buf.type = MIB_LOCAL;
priv->mib_buf.size = 1;
priv->mib_buf.index = offsetof(struct mib_local, preamble_type);
priv->mib_buf.data.byte = type;
ret = at76_set_mib(priv, &priv->mib_buf);
if (ret < 0)
wiphy_err(priv->hw->wiphy, "set_mib (preamble) failed: %d\n",
ret);
return ret;
}
static int at76_set_frag(struct at76_priv *priv, u16 size)
{
int ret = 0;
priv->mib_buf.type = MIB_MAC;
priv->mib_buf.size = 2;
priv->mib_buf.index = offsetof(struct mib_mac, frag_threshold);
priv->mib_buf.data.word = cpu_to_le16(size);
ret = at76_set_mib(priv, &priv->mib_buf);
if (ret < 0)
wiphy_err(priv->hw->wiphy,
"set_mib (frag threshold) failed: %d\n", ret);
return ret;
}
static int at76_set_rts(struct at76_priv *priv, u16 size)
{
int ret = 0;
priv->mib_buf.type = MIB_MAC;
priv->mib_buf.size = 2;
priv->mib_buf.index = offsetof(struct mib_mac, rts_threshold);
priv->mib_buf.data.word = cpu_to_le16(size);
ret = at76_set_mib(priv, &priv->mib_buf);
if (ret < 0)
wiphy_err(priv->hw->wiphy, "set_mib (rts) failed: %d\n", ret);
return ret;
}
static int at76_set_autorate_fallback(struct at76_priv *priv, int onoff)
{
int ret = 0;
priv->mib_buf.type = MIB_LOCAL;
priv->mib_buf.size = 1;
priv->mib_buf.index = offsetof(struct mib_local, txautorate_fallback);
priv->mib_buf.data.byte = onoff;
ret = at76_set_mib(priv, &priv->mib_buf);
if (ret < 0)
wiphy_err(priv->hw->wiphy,
"set_mib (autorate fallback) failed: %d\n", ret);
return ret;
}
static void at76_dump_mib_mac_addr(struct at76_priv *priv)
{
int i;
int ret;
struct mib_mac_addr *m = kmalloc(sizeof(struct mib_mac_addr),
GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_MAC_ADDR, m,
sizeof(struct mib_mac_addr));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (MAC_ADDR) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB MAC_ADDR: mac_addr %pM res 0x%x 0x%x",
wiphy_name(priv->hw->wiphy),
m->mac_addr, m->res[0], m->res[1]);
for (i = 0; i < ARRAY_SIZE(m->group_addr); i++)
at76_dbg(DBG_MIB, "%s: MIB MAC_ADDR: group addr %d: %pM, "
"status %d", wiphy_name(priv->hw->wiphy), i,
m->group_addr[i], m->group_addr_status[i]);
exit:
kfree(m);
}
static void at76_dump_mib_mac_wep(struct at76_priv *priv)
{
int i;
int ret;
int key_len;
struct mib_mac_wep *m = kmalloc(sizeof(struct mib_mac_wep), GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_MAC_WEP, m,
sizeof(struct mib_mac_wep));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (MAC_WEP) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB MAC_WEP: priv_invoked %u def_key_id %u "
"key_len %u excl_unencr %u wep_icv_err %u wep_excluded %u "
"encr_level %u key %d", wiphy_name(priv->hw->wiphy),
m->privacy_invoked, m->wep_default_key_id,
m->wep_key_mapping_len, m->exclude_unencrypted,
le32_to_cpu(m->wep_icv_error_count),
le32_to_cpu(m->wep_excluded_count), m->encryption_level,
m->wep_default_key_id);
key_len = (m->encryption_level == 1) ?
WEP_SMALL_KEY_LEN : WEP_LARGE_KEY_LEN;
for (i = 0; i < WEP_KEYS; i++)
at76_dbg(DBG_MIB, "%s: MIB MAC_WEP: key %d: %*phD",
wiphy_name(priv->hw->wiphy), i,
key_len, m->wep_default_keyvalue[i]);
exit:
kfree(m);
}
static void at76_dump_mib_mac_mgmt(struct at76_priv *priv)
{
int ret;
struct mib_mac_mgmt *m = kmalloc(sizeof(struct mib_mac_mgmt),
GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_MAC_MGMT, m,
sizeof(struct mib_mac_mgmt));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (MAC_MGMT) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB MAC_MGMT: beacon_period %d CFP_max_duration "
"%d medium_occupancy_limit %d station_id 0x%x ATIM_window %d "
"CFP_mode %d privacy_opt_impl %d DTIM_period %d CFP_period %d "
"current_bssid %pM current_essid %*phD current_bss_type %d "
"pm_mode %d ibss_change %d res %d "
"multi_domain_capability_implemented %d "
"international_roaming %d country_string %.3s",
wiphy_name(priv->hw->wiphy), le16_to_cpu(m->beacon_period),
le16_to_cpu(m->CFP_max_duration),
le16_to_cpu(m->medium_occupancy_limit),
le16_to_cpu(m->station_id), le16_to_cpu(m->ATIM_window),
m->CFP_mode, m->privacy_option_implemented, m->DTIM_period,
m->CFP_period, m->current_bssid,
IW_ESSID_MAX_SIZE, m->current_essid,
m->current_bss_type, m->power_mgmt_mode, m->ibss_change,
m->res, m->multi_domain_capability_implemented,
m->multi_domain_capability_enabled, m->country_string);
exit:
kfree(m);
}
static void at76_dump_mib_mac(struct at76_priv *priv)
{
int ret;
struct mib_mac *m = kmalloc(sizeof(struct mib_mac), GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_MAC, m, sizeof(struct mib_mac));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (MAC) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB MAC: max_tx_msdu_lifetime %d "
"max_rx_lifetime %d frag_threshold %d rts_threshold %d "
"cwmin %d cwmax %d short_retry_time %d long_retry_time %d "
"scan_type %d scan_channel %d probe_delay %u "
"min_channel_time %d max_channel_time %d listen_int %d "
"desired_ssid %*phD desired_bssid %pM desired_bsstype %d",
wiphy_name(priv->hw->wiphy),
le32_to_cpu(m->max_tx_msdu_lifetime),
le32_to_cpu(m->max_rx_lifetime),
le16_to_cpu(m->frag_threshold), le16_to_cpu(m->rts_threshold),
le16_to_cpu(m->cwmin), le16_to_cpu(m->cwmax),
m->short_retry_time, m->long_retry_time, m->scan_type,
m->scan_channel, le16_to_cpu(m->probe_delay),
le16_to_cpu(m->min_channel_time),
le16_to_cpu(m->max_channel_time),
le16_to_cpu(m->listen_interval),
IW_ESSID_MAX_SIZE, m->desired_ssid,
m->desired_bssid, m->desired_bsstype);
exit:
kfree(m);
}
static void at76_dump_mib_phy(struct at76_priv *priv)
{
int ret;
struct mib_phy *m = kmalloc(sizeof(struct mib_phy), GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_PHY, m, sizeof(struct mib_phy));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (PHY) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB PHY: ed_threshold %d slot_time %d "
"sifs_time %d preamble_length %d plcp_header_length %d "
"mpdu_max_length %d cca_mode_supported %d operation_rate_set "
"0x%x 0x%x 0x%x 0x%x channel_id %d current_cca_mode %d "
"phy_type %d current_reg_domain %d",
wiphy_name(priv->hw->wiphy), le32_to_cpu(m->ed_threshold),
le16_to_cpu(m->slot_time), le16_to_cpu(m->sifs_time),
le16_to_cpu(m->preamble_length),
le16_to_cpu(m->plcp_header_length),
le16_to_cpu(m->mpdu_max_length),
le16_to_cpu(m->cca_mode_supported), m->operation_rate_set[0],
m->operation_rate_set[1], m->operation_rate_set[2],
m->operation_rate_set[3], m->channel_id, m->current_cca_mode,
m->phy_type, m->current_reg_domain);
exit:
kfree(m);
}
static void at76_dump_mib_local(struct at76_priv *priv)
{
int ret;
struct mib_local *m = kmalloc(sizeof(*m), GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_LOCAL, m, sizeof(*m));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (LOCAL) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB LOCAL: beacon_enable %d "
"txautorate_fallback %d ssid_size %d promiscuous_mode %d "
"preamble_type %d", wiphy_name(priv->hw->wiphy),
m->beacon_enable,
m->txautorate_fallback, m->ssid_size, m->promiscuous_mode,
m->preamble_type);
exit:
kfree(m);
}
static void at76_dump_mib_mdomain(struct at76_priv *priv)
{
int ret;
struct mib_mdomain *m = kmalloc(sizeof(struct mib_mdomain), GFP_KERNEL);
if (!m)
return;
ret = at76_get_mib(priv->udev, MIB_MDOMAIN, m,
sizeof(struct mib_mdomain));
if (ret < 0) {
wiphy_err(priv->hw->wiphy,
"at76_get_mib (MDOMAIN) failed: %d\n", ret);
goto exit;
}
at76_dbg(DBG_MIB, "%s: MIB MDOMAIN: channel_list %*phD",
wiphy_name(priv->hw->wiphy),
(int)sizeof(m->channel_list), m->channel_list);
at76_dbg(DBG_MIB, "%s: MIB MDOMAIN: tx_powerlevel %*phD",
wiphy_name(priv->hw->wiphy),
(int)sizeof(m->tx_powerlevel), m->tx_powerlevel);
exit:
kfree(m);
}
static int at76_start_monitor(struct at76_priv *priv)
{
struct at76_req_scan scan;
int ret;
memset(&scan, 0, sizeof(struct at76_req_scan));
memset(scan.bssid, 0xff, ETH_ALEN);
scan.channel = priv->channel;
scan.scan_type = SCAN_TYPE_PASSIVE;
scan.international_scan = 0;
scan.min_channel_time = cpu_to_le16(priv->scan_min_time);
scan.max_channel_time = cpu_to_le16(priv->scan_max_time);
scan.probe_delay = cpu_to_le16(0);
ret = at76_set_card_command(priv->udev, CMD_SCAN, &scan, sizeof(scan));
if (ret >= 0)
ret = at76_get_cmd_status(priv->udev, CMD_SCAN);
return ret;
}
static inline int at76_calc_padding(int wlen)
{
wlen += AT76_TX_HDRLEN;
wlen = wlen % 64;
if (wlen < 50)
return 50 - wlen;
if (wlen >= 61)
return 64 + 50 - wlen;
return 0;
}
static void at76_rx_callback(struct urb *urb)
{
struct at76_priv *priv = urb->context;
priv->rx_tasklet.data = (unsigned long)urb;
tasklet_schedule(&priv->rx_tasklet);
}
static int at76_submit_rx_urb(struct at76_priv *priv)
{
int ret;
int size;
struct sk_buff *skb = priv->rx_skb;
if (!priv->rx_urb) {
wiphy_err(priv->hw->wiphy, "%s: priv->rx_urb is NULL\n",
__func__);
return -EFAULT;
}
if (!skb) {
skb = dev_alloc_skb(sizeof(struct at76_rx_buffer));
if (!skb) {
wiphy_err(priv->hw->wiphy,
"cannot allocate rx skbuff\n");
ret = -ENOMEM;
goto exit;
}
priv->rx_skb = skb;
} else {
skb_push(skb, skb_headroom(skb));
skb_trim(skb, 0);
}
size = skb_tailroom(skb);
usb_fill_bulk_urb(priv->rx_urb, priv->udev, priv->rx_pipe,
skb_put(skb, size), size, at76_rx_callback, priv);
ret = usb_submit_urb(priv->rx_urb, GFP_ATOMIC);
if (ret < 0) {
if (ret == -ENODEV)
at76_dbg(DBG_DEVSTART,
"usb_submit_urb returned -ENODEV");
else
wiphy_err(priv->hw->wiphy,
"rx, usb_submit_urb failed: %d\n", ret);
}
exit:
if (ret < 0 && ret != -ENODEV)
wiphy_err(priv->hw->wiphy,
"cannot submit rx urb - please unload the driver and/or power cycle the device\n");
return ret;
}
static int at76_load_external_fw(struct usb_device *udev, struct fwentry *fwe)
{
int ret;
int op_mode;
int blockno = 0;
int bsize;
u8 *block;
u8 *buf = fwe->extfw;
int size = fwe->extfw_size;
if (!buf || !size)
return -ENOENT;
op_mode = at76_get_op_mode(udev);
at76_dbg(DBG_DEVSTART, "opmode %d", op_mode);
if (op_mode != OPMODE_NORMAL_NIC_WITHOUT_FLASH) {
dev_err(&udev->dev, "unexpected opmode %d\n", op_mode);
return -EINVAL;
}
block = kmalloc(FW_BLOCK_SIZE, GFP_KERNEL);
if (!block)
return -ENOMEM;
at76_dbg(DBG_DEVSTART, "downloading external firmware");
do {
bsize = min_t(int, size, FW_BLOCK_SIZE);
memcpy(block, buf, bsize);
at76_dbg(DBG_DEVSTART,
"ext fw, size left = %5d, bsize = %4d, blockno = %2d",
size, bsize, blockno);
ret = at76_load_ext_fw_block(udev, blockno, block, bsize);
if (ret != bsize) {
dev_err(&udev->dev,
"loading %dth firmware block failed: %d\n",
blockno, ret);
goto exit;
}
buf += bsize;
size -= bsize;
blockno++;
} while (bsize > 0);
if (at76_is_505a(fwe->board_type)) {
at76_dbg(DBG_DEVSTART, "200 ms delay for 505a");
schedule_timeout_interruptible(HZ / 5 + 1);
}
exit:
kfree(block);
if (ret < 0)
dev_err(&udev->dev,
"downloading external firmware failed: %d\n", ret);
return ret;
}
static int at76_load_internal_fw(struct usb_device *udev, struct fwentry *fwe)
{
int ret;
int need_remap = !at76_is_505a(fwe->board_type);
ret = at76_usbdfu_download(udev, fwe->intfw, fwe->intfw_size,
need_remap ? 0 : 2 * HZ);
if (ret < 0) {
dev_err(&udev->dev,
"downloading internal fw failed with %d\n", ret);
goto exit;
}
at76_dbg(DBG_DEVSTART, "sending REMAP");
if (need_remap) {
ret = at76_remap(udev);
if (ret < 0) {
dev_err(&udev->dev,
"sending REMAP failed with %d\n", ret);
goto exit;
}
}
at76_dbg(DBG_DEVSTART, "sleeping for 2 seconds");
schedule_timeout_interruptible(2 * HZ + 1);
usb_reset_device(udev);
exit:
return ret;
}
static int at76_startup_device(struct at76_priv *priv)
{
struct at76_card_config *ccfg = &priv->card_config;
int ret;
at76_dbg(DBG_PARAMS,
"%s param: ssid %.*s (%*phD) mode %s ch %d wep %s key %d "
"keylen %d", wiphy_name(priv->hw->wiphy), priv->essid_size,
priv->essid, IW_ESSID_MAX_SIZE, priv->essid,
priv->iw_mode == IW_MODE_ADHOC ? "adhoc" : "infra",
priv->channel, priv->wep_enabled ? "enabled" : "disabled",
priv->wep_key_id, priv->wep_keys_len[priv->wep_key_id]);
at76_dbg(DBG_PARAMS,
"%s param: preamble %s rts %d retry %d frag %d "
"txrate %s auth_mode %d", wiphy_name(priv->hw->wiphy),
preambles[priv->preamble_type], priv->rts_threshold,
priv->short_retry_limit, priv->frag_threshold,
priv->txrate == TX_RATE_1MBIT ? "1MBit" : priv->txrate ==
TX_RATE_2MBIT ? "2MBit" : priv->txrate ==
TX_RATE_5_5MBIT ? "5.5MBit" : priv->txrate ==
TX_RATE_11MBIT ? "11MBit" : priv->txrate ==
TX_RATE_AUTO ? "auto" : "<invalid>", priv->auth_mode);
at76_dbg(DBG_PARAMS,
"%s param: pm_mode %d pm_period %d auth_mode %s "
"scan_times %d %d scan_mode %s",
wiphy_name(priv->hw->wiphy), priv->pm_mode, priv->pm_period,
priv->auth_mode == WLAN_AUTH_OPEN ? "open" : "shared_secret",
priv->scan_min_time, priv->scan_max_time,
priv->scan_mode == SCAN_TYPE_ACTIVE ? "active" : "passive");
memset(ccfg, 0, sizeof(struct at76_card_config));
ccfg->promiscuous_mode = 0;
ccfg->short_retry_limit = priv->short_retry_limit;
if (priv->wep_enabled) {
if (priv->wep_keys_len[priv->wep_key_id] > WEP_SMALL_KEY_LEN)
ccfg->encryption_type = 2;
else
ccfg->encryption_type = 1;
ccfg->exclude_unencrypted = 1;
} else {
ccfg->exclude_unencrypted = 0;
ccfg->encryption_type = 0;
}
ccfg->rts_threshold = cpu_to_le16(priv->rts_threshold);
ccfg->fragmentation_threshold = cpu_to_le16(priv->frag_threshold);
memcpy(ccfg->basic_rate_set, hw_rates, 4);
ccfg->auto_rate_fallback = (priv->txrate == TX_RATE_AUTO ? 1 : 0);
ccfg->channel = priv->channel;
ccfg->privacy_invoked = priv->wep_enabled;
memcpy(ccfg->current_ssid, priv->essid, IW_ESSID_MAX_SIZE);
ccfg->ssid_len = priv->essid_size;
ccfg->wep_default_key_id = priv->wep_key_id;
memcpy(ccfg->wep_default_key_value, priv->wep_keys,
sizeof(priv->wep_keys));
ccfg->short_preamble = priv->preamble_type;
ccfg->beacon_period = cpu_to_le16(priv->beacon_period);
ret = at76_set_card_command(priv->udev, CMD_STARTUP, &priv->card_config,
sizeof(struct at76_card_config));
if (ret < 0) {
wiphy_err(priv->hw->wiphy, "at76_set_card_command failed: %d\n",
ret);
return ret;
}
at76_wait_completion(priv, CMD_STARTUP);
memset(priv->bssid, 0, ETH_ALEN);
if (at76_set_radio(priv, 1) == 1)
at76_wait_completion(priv, CMD_RADIO_ON);
ret = at76_set_preamble(priv, priv->preamble_type);
if (ret < 0)
return ret;
ret = at76_set_frag(priv, priv->frag_threshold);
if (ret < 0)
return ret;
ret = at76_set_rts(priv, priv->rts_threshold);
if (ret < 0)
return ret;
ret = at76_set_autorate_fallback(priv,
priv->txrate == TX_RATE_AUTO ? 1 : 0);
if (ret < 0)
return ret;
ret = at76_set_pm_mode(priv);
if (ret < 0)
return ret;
if (at76_debug & DBG_MIB) {
at76_dump_mib_mac(priv);
at76_dump_mib_mac_addr(priv);
at76_dump_mib_mac_mgmt(priv);
at76_dump_mib_mac_wep(priv);
at76_dump_mib_mdomain(priv);
at76_dump_mib_phy(priv);
at76_dump_mib_local(priv);
}
return 0;
}
static void at76_work_set_promisc(struct work_struct *work)
{
struct at76_priv *priv = container_of(work, struct at76_priv,
work_set_promisc);
int ret = 0;
if (priv->device_unplugged)
return;
mutex_lock(&priv->mtx);
priv->mib_buf.type = MIB_LOCAL;
priv->mib_buf.size = 1;
priv->mib_buf.index = offsetof(struct mib_local, promiscuous_mode);
priv->mib_buf.data.byte = priv->promisc ? 1 : 0;
ret = at76_set_mib(priv, &priv->mib_buf);
if (ret < 0)
wiphy_err(priv->hw->wiphy,
"set_mib (promiscuous_mode) failed: %d\n", ret);
mutex_unlock(&priv->mtx);
}
static void at76_work_submit_rx(struct work_struct *work)
{
struct at76_priv *priv = container_of(work, struct at76_priv,
work_submit_rx);
mutex_lock(&priv->mtx);
at76_submit_rx_urb(priv);
mutex_unlock(&priv->mtx);
}
static void at76_rx_tasklet(unsigned long param)
{
struct urb *urb = (struct urb *)param;
struct at76_priv *priv = urb->context;
struct at76_rx_buffer *buf;
struct ieee80211_rx_status rx_status = { 0 };
if (priv->device_unplugged) {
at76_dbg(DBG_DEVSTART, "device unplugged");
at76_dbg(DBG_DEVSTART, "urb status %d", urb->status);
return;
}
if (!priv->rx_skb || !priv->rx_skb->data)
return;
buf = (struct at76_rx_buffer *)priv->rx_skb->data;
if (urb->status != 0) {
if (urb->status != -ENOENT && urb->status != -ECONNRESET)
at76_dbg(DBG_URB,
"%s %s: - nonzero Rx bulk status received: %d",
__func__, wiphy_name(priv->hw->wiphy),
urb->status);
return;
}
at76_dbg(DBG_RX_ATMEL_HDR,
"%s: rx frame: rate %d rssi %d noise %d link %d",
wiphy_name(priv->hw->wiphy), buf->rx_rate, buf->rssi,
buf->noise_level, buf->link_quality);
skb_pull(priv->rx_skb, AT76_RX_HDRLEN);
skb_trim(priv->rx_skb, le16_to_cpu(buf->wlength));
at76_dbg_dump(DBG_RX_DATA, priv->rx_skb->data,
priv->rx_skb->len, "RX: len=%d", priv->rx_skb->len);
rx_status.signal = buf->rssi;
rx_status.flag |= RX_FLAG_DECRYPTED;
rx_status.flag |= RX_FLAG_IV_STRIPPED;
at76_dbg(DBG_MAC80211, "calling ieee80211_rx_irqsafe(): %d/%d",
priv->rx_skb->len, priv->rx_skb->data_len);
memcpy(IEEE80211_SKB_RXCB(priv->rx_skb), &rx_status, sizeof(rx_status));
ieee80211_rx_irqsafe(priv->hw, priv->rx_skb);
priv->rx_skb = NULL;
at76_submit_rx_urb(priv);
}
static struct fwentry *at76_load_firmware(struct usb_device *udev,
enum board_type board_type)
{
int ret;
char *str;
struct at76_fw_header *fwh;
struct fwentry *fwe = &firmwares[board_type];
mutex_lock(&fw_mutex);
if (fwe->loaded) {
at76_dbg(DBG_FW, "re-using previously loaded fw");
goto exit;
}
at76_dbg(DBG_FW, "downloading firmware %s", fwe->fwname);
ret = request_firmware(&fwe->fw, fwe->fwname, &udev->dev);
if (ret < 0) {
dev_err(&udev->dev, "firmware %s not found!\n",
fwe->fwname);
dev_err(&udev->dev,
"you may need to download the firmware from http://developer.berlios.de/projects/at76c503a/\n");
goto exit;
}
at76_dbg(DBG_FW, "got it.");
fwh = (struct at76_fw_header *)(fwe->fw->data);
if (fwe->fw->size <= sizeof(*fwh)) {
dev_err(&udev->dev,
"firmware is too short (0x%zx)\n", fwe->fw->size);
goto exit;
}
fwe->board_type = le32_to_cpu(fwh->board_type);
if (fwe->board_type != board_type) {
dev_err(&udev->dev,
"board type mismatch, requested %u, got %u\n",
board_type, fwe->board_type);
goto exit;
}
fwe->fw_version.major = fwh->major;
fwe->fw_version.minor = fwh->minor;
fwe->fw_version.patch = fwh->patch;
fwe->fw_version.build = fwh->build;
str = (char *)fwh + le32_to_cpu(fwh->str_offset);
fwe->intfw = (u8 *)fwh + le32_to_cpu(fwh->int_fw_offset);
fwe->intfw_size = le32_to_cpu(fwh->int_fw_len);
fwe->extfw = (u8 *)fwh + le32_to_cpu(fwh->ext_fw_offset);
fwe->extfw_size = le32_to_cpu(fwh->ext_fw_len);
fwe->loaded = 1;
dev_printk(KERN_DEBUG, &udev->dev,
"using firmware %s (version %d.%d.%d-%d)\n",
fwe->fwname, fwh->major, fwh->minor, fwh->patch, fwh->build);
at76_dbg(DBG_DEVSTART, "board %u, int %d:%d, ext %d:%d", board_type,
le32_to_cpu(fwh->int_fw_offset), le32_to_cpu(fwh->int_fw_len),
le32_to_cpu(fwh->ext_fw_offset), le32_to_cpu(fwh->ext_fw_len));
at76_dbg(DBG_DEVSTART, "firmware id %s", str);
exit:
mutex_unlock(&fw_mutex);
if (fwe->loaded)
return fwe;
else
return NULL;
}
static int at76_join(struct at76_priv *priv)
{
struct at76_req_join join;
int ret;
memset(&join, 0, sizeof(struct at76_req_join));
memcpy(join.essid, priv->essid, priv->essid_size);
join.essid_size = priv->essid_size;
memcpy(join.bssid, priv->bssid, ETH_ALEN);
join.bss_type = INFRASTRUCTURE_MODE;
join.channel = priv->channel;
join.timeout = cpu_to_le16(2000);
at76_dbg(DBG_MAC80211, "%s: sending CMD_JOIN", __func__);
ret = at76_set_card_command(priv->udev, CMD_JOIN, &join,
sizeof(struct at76_req_join));
if (ret < 0) {
wiphy_err(priv->hw->wiphy, "at76_set_card_command failed: %d\n",
ret);
return 0;
}
ret = at76_wait_completion(priv, CMD_JOIN);
at76_dbg(DBG_MAC80211, "%s: CMD_JOIN returned: 0x%02x", __func__, ret);
if (ret != CMD_STATUS_COMPLETE) {
wiphy_err(priv->hw->wiphy, "at76_wait_completion failed: %d\n",
ret);
return 0;
}
at76_set_pm_mode(priv);
return 0;
}
static void at76_work_join_bssid(struct work_struct *work)
{
struct at76_priv *priv = container_of(work, struct at76_priv,
work_join_bssid);
if (priv->device_unplugged)
return;
mutex_lock(&priv->mtx);
if (is_valid_ether_addr(priv->bssid))
at76_join(priv);
mutex_unlock(&priv->mtx);
}
static void at76_mac80211_tx_callback(struct urb *urb)
{
struct at76_priv *priv = urb->context;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(priv->tx_skb);
at76_dbg(DBG_MAC80211, "%s()", __func__);
switch (urb->status) {
case 0:
info->flags |= IEEE80211_TX_STAT_ACK;
break;
case -ENOENT:
case -ECONNRESET:
break;
default:
at76_dbg(DBG_URB, "%s - nonzero tx status received: %d",
__func__, urb->status);
break;
}
memset(&info->status, 0, sizeof(info->status));
ieee80211_tx_status_irqsafe(priv->hw, priv->tx_skb);
priv->tx_skb = NULL;
ieee80211_wake_queues(priv->hw);
}
static void at76_mac80211_tx(struct ieee80211_hw *hw,
struct ieee80211_tx_control *control,
struct sk_buff *skb)
{
struct at76_priv *priv = hw->priv;
struct at76_tx_buffer *tx_buffer = priv->bulk_out_buffer;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)skb->data;
int padding, submit_len, ret;
at76_dbg(DBG_MAC80211, "%s()", __func__);
if (priv->tx_urb->status == -EINPROGRESS) {
wiphy_err(priv->hw->wiphy,
"%s called while tx urb is pending\n", __func__);
dev_kfree_skb_any(skb);
return;
}
if (mgmt->frame_control & cpu_to_le16(IEEE80211_STYPE_AUTH)) {
if (!ether_addr_equal(priv->bssid, mgmt->bssid)) {
memcpy(priv->bssid, mgmt->bssid, ETH_ALEN);
ieee80211_queue_work(hw, &priv->work_join_bssid);
dev_kfree_skb_any(skb);
return;
}
}
ieee80211_stop_queues(hw);
at76_ledtrig_tx_activity();
WARN_ON(priv->tx_skb != NULL);
priv->tx_skb = skb;
padding = at76_calc_padding(skb->len);
submit_len = AT76_TX_HDRLEN + skb->len + padding;
memset(tx_buffer, 0, sizeof(*tx_buffer));
tx_buffer->padding = padding;
tx_buffer->wlength = cpu_to_le16(skb->len);
tx_buffer->tx_rate = ieee80211_get_tx_rate(hw, info)->hw_value;
memset(tx_buffer->reserved, 0, sizeof(tx_buffer->reserved));
memcpy(tx_buffer->packet, skb->data, skb->len);
at76_dbg(DBG_TX_DATA, "%s tx: wlen 0x%x pad 0x%x rate %d hdr",
wiphy_name(priv->hw->wiphy), le16_to_cpu(tx_buffer->wlength),
tx_buffer->padding, tx_buffer->tx_rate);
at76_dbg_dump(DBG_TX_DATA_CONTENT, tx_buffer, submit_len,
"%s(): tx_buffer %d bytes:", __func__, submit_len);
usb_fill_bulk_urb(priv->tx_urb, priv->udev, priv->tx_pipe, tx_buffer,
submit_len, at76_mac80211_tx_callback, priv);
ret = usb_submit_urb(priv->tx_urb, GFP_ATOMIC);
if (ret) {
wiphy_err(priv->hw->wiphy, "error in tx submit urb: %d\n", ret);
if (ret == -EINVAL)
wiphy_err(priv->hw->wiphy,
"-EINVAL: tx urb %p hcpriv %p complete %p\n",
priv->tx_urb,
priv->tx_urb->hcpriv, priv->tx_urb->complete);
}
}
static int at76_mac80211_start(struct ieee80211_hw *hw)
{
struct at76_priv *priv = hw->priv;
int ret;
at76_dbg(DBG_MAC80211, "%s()", __func__);
mutex_lock(&priv->mtx);
ret = at76_submit_rx_urb(priv);
if (ret < 0) {
wiphy_err(priv->hw->wiphy, "open: submit_rx_urb failed: %d\n",
ret);
goto error;
}
at76_startup_device(priv);
at76_start_monitor(priv);
error:
mutex_unlock(&priv->mtx);
return 0;
}
static void at76_mac80211_stop(struct ieee80211_hw *hw)
{
struct at76_priv *priv = hw->priv;
at76_dbg(DBG_MAC80211, "%s()", __func__);
cancel_delayed_work(&priv->dwork_hw_scan);
cancel_work_sync(&priv->work_join_bssid);
cancel_work_sync(&priv->work_set_promisc);
mutex_lock(&priv->mtx);
if (!priv->device_unplugged) {
at76_set_radio(priv, 0);
usb_kill_urb(priv->rx_urb);
}
mutex_unlock(&priv->mtx);
}
static int at76_add_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct at76_priv *priv = hw->priv;
int ret = 0;
at76_dbg(DBG_MAC80211, "%s()", __func__);
mutex_lock(&priv->mtx);
switch (vif->type) {
case NL80211_IFTYPE_STATION:
priv->iw_mode = IW_MODE_INFRA;
break;
default:
ret = -EOPNOTSUPP;
goto exit;
}
exit:
mutex_unlock(&priv->mtx);
return ret;
}
static void at76_remove_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
at76_dbg(DBG_MAC80211, "%s()", __func__);
}
static void at76_dwork_hw_scan(struct work_struct *work)
{
struct at76_priv *priv = container_of(work, struct at76_priv,
dwork_hw_scan.work);
int ret;
if (priv->device_unplugged)
return;
mutex_lock(&priv->mtx);
ret = at76_get_cmd_status(priv->udev, CMD_SCAN);
at76_dbg(DBG_MAC80211, "%s: CMD_SCAN status 0x%02x", __func__, ret);
if (ret != CMD_STATUS_COMPLETE) {
ieee80211_queue_delayed_work(priv->hw, &priv->dwork_hw_scan,
SCAN_POLL_INTERVAL);
mutex_unlock(&priv->mtx);
return;
}
if (is_valid_ether_addr(priv->bssid))
at76_join(priv);
mutex_unlock(&priv->mtx);
ieee80211_scan_completed(priv->hw, false);
ieee80211_wake_queues(priv->hw);
}
static int at76_hw_scan(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_scan_request *req)
{
struct at76_priv *priv = hw->priv;
struct at76_req_scan scan;
u8 *ssid = NULL;
int ret, len = 0;
at76_dbg(DBG_MAC80211, "%s():", __func__);
if (priv->device_unplugged)
return 0;
mutex_lock(&priv->mtx);
ieee80211_stop_queues(hw);
memset(&scan, 0, sizeof(struct at76_req_scan));
memset(scan.bssid, 0xFF, ETH_ALEN);
if (req->n_ssids) {
scan.scan_type = SCAN_TYPE_ACTIVE;
ssid = req->ssids[0].ssid;
len = req->ssids[0].ssid_len;
} else {
scan.scan_type = SCAN_TYPE_PASSIVE;
}
if (len) {
memcpy(scan.essid, ssid, len);
scan.essid_size = len;
}
scan.min_channel_time = cpu_to_le16(priv->scan_min_time);
scan.max_channel_time = cpu_to_le16(priv->scan_max_time);
scan.probe_delay = cpu_to_le16(priv->scan_min_time * 1000);
scan.international_scan = 0;
at76_dbg(DBG_MAC80211, "%s: sending CMD_SCAN", __func__);
ret = at76_set_card_command(priv->udev, CMD_SCAN, &scan, sizeof(scan));
if (ret < 0) {
wiphy_err(priv->hw->wiphy, "CMD_SCAN failed: %d\n", ret);
goto exit;
}
ieee80211_queue_delayed_work(priv->hw, &priv->dwork_hw_scan,
SCAN_POLL_INTERVAL);
exit:
mutex_unlock(&priv->mtx);
return 0;
}
static int at76_config(struct ieee80211_hw *hw, u32 changed)
{
struct at76_priv *priv = hw->priv;
at76_dbg(DBG_MAC80211, "%s(): channel %d",
__func__, hw->conf.chandef.chan->hw_value);
at76_dbg_dump(DBG_MAC80211, priv->bssid, ETH_ALEN, "bssid:");
mutex_lock(&priv->mtx);
priv->channel = hw->conf.chandef.chan->hw_value;
if (is_valid_ether_addr(priv->bssid))
at76_join(priv);
else
at76_start_monitor(priv);
mutex_unlock(&priv->mtx);
return 0;
}
static void at76_bss_info_changed(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *conf,
u32 changed)
{
struct at76_priv *priv = hw->priv;
at76_dbg(DBG_MAC80211, "%s():", __func__);
if (!(changed & BSS_CHANGED_BSSID))
return;
at76_dbg_dump(DBG_MAC80211, conf->bssid, ETH_ALEN, "bssid:");
mutex_lock(&priv->mtx);
memcpy(priv->bssid, conf->bssid, ETH_ALEN);
if (is_valid_ether_addr(priv->bssid))
at76_join(priv);
mutex_unlock(&priv->mtx);
}
static void at76_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags, u64 multicast)
{
struct at76_priv *priv = hw->priv;
int flags;
at76_dbg(DBG_MAC80211, "%s(): changed_flags=0x%08x "
"total_flags=0x%08x",
__func__, changed_flags, *total_flags);
flags = changed_flags & AT76_SUPPORTED_FILTERS;
*total_flags = AT76_SUPPORTED_FILTERS;
if (priv->device_unplugged)
return;
if (flags && !priv->promisc) {
priv->promisc = 1;
} else if (!flags && priv->promisc) {
priv->promisc = 0;
} else
return;
ieee80211_queue_work(hw, &priv->work_set_promisc);
}
static int at76_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd,
struct ieee80211_vif *vif, struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct at76_priv *priv = hw->priv;
int i;
at76_dbg(DBG_MAC80211, "%s(): cmd %d key->cipher %d key->keyidx %d "
"key->keylen %d",
__func__, cmd, key->cipher, key->keyidx, key->keylen);
if ((key->cipher != WLAN_CIPHER_SUITE_WEP40) &&
(key->cipher != WLAN_CIPHER_SUITE_WEP104))
return -EOPNOTSUPP;
key->hw_key_idx = key->keyidx;
mutex_lock(&priv->mtx);
switch (cmd) {
case SET_KEY:
memcpy(priv->wep_keys[key->keyidx], key->key, key->keylen);
priv->wep_keys_len[key->keyidx] = key->keylen;
priv->wep_key_id = key->keyidx;
break;
case DISABLE_KEY:
default:
priv->wep_keys_len[key->keyidx] = 0;
break;
}
priv->wep_enabled = 0;
for (i = 0; i < WEP_KEYS; i++) {
if (priv->wep_keys_len[i] != 0)
priv->wep_enabled = 1;
}
at76_startup_device(priv);
mutex_unlock(&priv->mtx);
return 0;
}
static struct at76_priv *at76_alloc_new_device(struct usb_device *udev)
{
struct ieee80211_hw *hw;
struct at76_priv *priv;
hw = ieee80211_alloc_hw(sizeof(struct at76_priv), &at76_ops);
if (!hw) {
printk(KERN_ERR DRIVER_NAME ": could not register"
" ieee80211_hw\n");
return NULL;
}
priv = hw->priv;
priv->hw = hw;
priv->udev = udev;
mutex_init(&priv->mtx);
INIT_WORK(&priv->work_set_promisc, at76_work_set_promisc);
INIT_WORK(&priv->work_submit_rx, at76_work_submit_rx);
INIT_WORK(&priv->work_join_bssid, at76_work_join_bssid);
INIT_DELAYED_WORK(&priv->dwork_hw_scan, at76_dwork_hw_scan);
tasklet_init(&priv->rx_tasklet, at76_rx_tasklet, 0);
priv->pm_mode = AT76_PM_OFF;
priv->pm_period = 0;
priv->hw->channel_change_time = 100000;
return priv;
}
static int at76_alloc_urbs(struct at76_priv *priv,
struct usb_interface *interface)
{
struct usb_endpoint_descriptor *endpoint, *ep_in, *ep_out;
int i;
int buffer_size;
struct usb_host_interface *iface_desc;
at76_dbg(DBG_PROC_ENTRY, "%s: ENTER", __func__);
at76_dbg(DBG_URB, "%s: NumEndpoints %d ", __func__,
interface->altsetting[0].desc.bNumEndpoints);
ep_in = NULL;
ep_out = NULL;
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
endpoint = &iface_desc->endpoint[i].desc;
at76_dbg(DBG_URB, "%s: %d. endpoint: addr 0x%x attr 0x%x",
__func__, i, endpoint->bEndpointAddress,
endpoint->bmAttributes);
if (!ep_in && usb_endpoint_is_bulk_in(endpoint))
ep_in = endpoint;
if (!ep_out && usb_endpoint_is_bulk_out(endpoint))
ep_out = endpoint;
}
if (!ep_in || !ep_out) {
dev_err(&interface->dev, "bulk endpoints missing\n");
return -ENXIO;
}
priv->rx_pipe = usb_rcvbulkpipe(priv->udev, ep_in->bEndpointAddress);
priv->tx_pipe = usb_sndbulkpipe(priv->udev, ep_out->bEndpointAddress);
priv->rx_urb = usb_alloc_urb(0, GFP_KERNEL);
priv->tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!priv->rx_urb || !priv->tx_urb) {
dev_err(&interface->dev, "cannot allocate URB\n");
return -ENOMEM;
}
buffer_size = sizeof(struct at76_tx_buffer) + MAX_PADDING_SIZE;
priv->bulk_out_buffer = kmalloc(buffer_size, GFP_KERNEL);
if (!priv->bulk_out_buffer)
return -ENOMEM;
at76_dbg(DBG_PROC_ENTRY, "%s: EXIT", __func__);
return 0;
}
static int at76_init_new_device(struct at76_priv *priv,
struct usb_interface *interface)
{
struct wiphy *wiphy;
size_t len;
int ret;
at76_dbg(DBG_DEVSTART, "USB interface: %d endpoints",
interface->cur_altsetting->desc.bNumEndpoints);
ret = at76_alloc_urbs(priv, interface);
if (ret < 0)
goto exit;
ret = at76_get_hw_config(priv);
if (ret < 0) {
dev_err(&interface->dev, "cannot get MAC address\n");
goto exit;
}
priv->domain = at76_get_reg_domain(priv->regulatory_domain);
priv->channel = DEF_CHANNEL;
priv->iw_mode = IW_MODE_INFRA;
priv->rts_threshold = DEF_RTS_THRESHOLD;
priv->frag_threshold = DEF_FRAG_THRESHOLD;
priv->short_retry_limit = DEF_SHORT_RETRY_LIMIT;
priv->txrate = TX_RATE_AUTO;
priv->preamble_type = PREAMBLE_TYPE_LONG;
priv->beacon_period = 100;
priv->auth_mode = WLAN_AUTH_OPEN;
priv->scan_min_time = DEF_SCAN_MIN_TIME;
priv->scan_max_time = DEF_SCAN_MAX_TIME;
priv->scan_mode = SCAN_TYPE_ACTIVE;
priv->device_unplugged = 0;
wiphy = priv->hw->wiphy;
priv->hw->wiphy->max_scan_ssids = 1;
priv->hw->wiphy->max_scan_ie_len = 0;
priv->hw->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION);
priv->hw->wiphy->bands[IEEE80211_BAND_2GHZ] = &at76_supported_band;
priv->hw->flags = IEEE80211_HW_RX_INCLUDES_FCS |
IEEE80211_HW_SIGNAL_UNSPEC;
priv->hw->max_signal = 100;
SET_IEEE80211_DEV(priv->hw, &interface->dev);
SET_IEEE80211_PERM_ADDR(priv->hw, priv->mac_addr);
len = sizeof(wiphy->fw_version);
snprintf(wiphy->fw_version, len, "%d.%d.%d-%d",
priv->fw_version.major, priv->fw_version.minor,
priv->fw_version.patch, priv->fw_version.build);
wiphy->hw_version = priv->board_type;
ret = ieee80211_register_hw(priv->hw);
if (ret) {
printk(KERN_ERR "cannot register mac80211 hw (status %d)!\n",
ret);
goto exit;
}
priv->mac80211_registered = 1;
wiphy_info(priv->hw->wiphy, "USB %s, MAC %pM, firmware %d.%d.%d-%d\n",
dev_name(&interface->dev), priv->mac_addr,
priv->fw_version.major, priv->fw_version.minor,
priv->fw_version.patch, priv->fw_version.build);
wiphy_info(priv->hw->wiphy, "regulatory domain 0x%02x: %s\n",
priv->regulatory_domain, priv->domain->name);
exit:
return ret;
}
static void at76_delete_device(struct at76_priv *priv)
{
at76_dbg(DBG_PROC_ENTRY, "%s: ENTER", __func__);
priv->device_unplugged = 1;
tasklet_kill(&priv->rx_tasklet);
if (priv->mac80211_registered)
ieee80211_unregister_hw(priv->hw);
if (priv->tx_urb) {
usb_kill_urb(priv->tx_urb);
usb_free_urb(priv->tx_urb);
}
if (priv->rx_urb) {
usb_kill_urb(priv->rx_urb);
usb_free_urb(priv->rx_urb);
}
at76_dbg(DBG_PROC_ENTRY, "%s: unlinked urbs", __func__);
kfree(priv->bulk_out_buffer);
del_timer_sync(&ledtrig_tx_timer);
kfree_skb(priv->rx_skb);
usb_put_dev(priv->udev);
at76_dbg(DBG_PROC_ENTRY, "%s: before freeing priv/ieee80211_hw",
__func__);
ieee80211_free_hw(priv->hw);
at76_dbg(DBG_PROC_ENTRY, "%s: EXIT", __func__);
}
static int at76_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
int ret;
struct at76_priv *priv;
struct fwentry *fwe;
struct usb_device *udev;
int op_mode;
int need_ext_fw = 0;
struct mib_fw_version fwv;
int board_type = (int)id->driver_info;
udev = usb_get_dev(interface_to_usbdev(interface));
fwe = at76_load_firmware(udev, board_type);
if (!fwe) {
ret = -ENOENT;
goto error;
}
op_mode = at76_get_op_mode(udev);
at76_dbg(DBG_DEVSTART, "opmode %d", op_mode);
if (op_mode == OPMODE_HW_CONFIG_MODE) {
dev_err(&interface->dev,
"cannot handle a device in HW_CONFIG_MODE\n");
ret = -EBUSY;
goto error;
}
if (op_mode != OPMODE_NORMAL_NIC_WITH_FLASH
&& op_mode != OPMODE_NORMAL_NIC_WITHOUT_FLASH) {
dev_printk(KERN_DEBUG, &interface->dev,
"downloading internal firmware\n");
ret = at76_load_internal_fw(udev, fwe);
if (ret < 0) {
dev_err(&interface->dev,
"error %d downloading internal firmware\n",
ret);
goto error;
}
usb_put_dev(udev);
return ret;
}
if ((fwe->fw_version.major > 0 || fwe->fw_version.minor >= 100)
|| (op_mode == OPMODE_NORMAL_NIC_WITH_FLASH)) {
ret = at76_get_mib(udev, MIB_FW_VERSION, &fwv, sizeof(fwv));
if (ret < 0 || (fwv.major | fwv.minor) == 0)
need_ext_fw = 1;
} else
need_ext_fw = 1;
if (need_ext_fw) {
dev_printk(KERN_DEBUG, &interface->dev,
"downloading external firmware\n");
ret = at76_load_external_fw(udev, fwe);
if (ret)
goto error;
ret = at76_get_mib(udev, MIB_FW_VERSION, &fwv, sizeof(fwv));
if (ret < 0) {
dev_err(&interface->dev,
"error %d getting firmware version\n", ret);
goto error;
}
}
priv = at76_alloc_new_device(udev);
if (!priv) {
ret = -ENOMEM;
goto error;
}
usb_set_intfdata(interface, priv);
memcpy(&priv->fw_version, &fwv, sizeof(struct mib_fw_version));
priv->board_type = board_type;
ret = at76_init_new_device(priv, interface);
if (ret < 0)
at76_delete_device(priv);
return ret;
error:
usb_put_dev(udev);
return ret;
}
static void at76_disconnect(struct usb_interface *interface)
{
struct at76_priv *priv;
priv = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
if (!priv)
return;
wiphy_info(priv->hw->wiphy, "disconnecting\n");
at76_delete_device(priv);
dev_info(&interface->dev, "disconnected\n");
}
static int __init at76_mod_init(void)
{
int result;
printk(KERN_INFO DRIVER_DESC " " DRIVER_VERSION " loading\n");
mutex_init(&fw_mutex);
result = usb_register(&at76_driver);
if (result < 0)
printk(KERN_ERR DRIVER_NAME
": usb_register failed (status %d)\n", result);
led_trigger_register_simple("at76_usb-tx", &ledtrig_tx);
return result;
}
static void __exit at76_mod_exit(void)
{
int i;
printk(KERN_INFO DRIVER_DESC " " DRIVER_VERSION " unloading\n");
usb_deregister(&at76_driver);
for (i = 0; i < ARRAY_SIZE(firmwares); i++)
release_firmware(firmwares[i].fw);
led_trigger_unregister_simple(ledtrig_tx);
}
