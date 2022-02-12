void rtl_btc_record_pwr_mode(struct rtl_priv *rtlpriv, u8 *buf, u8 len)
{
u8 safe_len;
safe_len = sizeof(gl_bt_coexist.pwr_mode_val);
if (safe_len > len)
safe_len = len;
memcpy(gl_bt_coexist.pwr_mode_val, buf, safe_len);
}
u8 rtl_btc_get_lps_val(struct rtl_priv *rtlpriv)
{
return gl_bt_coexist.bt_info.lps_val;
}
u8 rtl_btc_get_rpwm_val(struct rtl_priv *rtlpriv)
{
return gl_bt_coexist.bt_info.rpwm_val;
}
bool rtl_btc_is_bt_ctrl_lps(struct rtl_priv *rtlpriv)
{
return gl_bt_coexist.bt_info.bt_ctrl_lps;
}
bool rtl_btc_is_bt_lps_on(struct rtl_priv *rtlpriv)
{
return gl_bt_coexist.bt_info.bt_lps_on;
}
void rtl_btc_get_ampdu_cfg(struct rtl_priv *rtlpriv, u8 *reject_agg,
u8 *ctrl_agg_size, u8 *agg_size)
{
if (reject_agg)
*reject_agg = gl_bt_coexist.bt_info.reject_agg_pkt;
if (ctrl_agg_size)
*ctrl_agg_size = gl_bt_coexist.bt_info.bt_ctrl_agg_buf_size;
if (agg_size)
*agg_size = gl_bt_coexist.bt_info.agg_buf_size;
}
void rtl_btc_init_variables(struct rtl_priv *rtlpriv)
{
exhalbtc_initlize_variables();
exhalbtc_bind_bt_coex_withadapter(rtlpriv);
}
void rtl_btc_init_hal_vars(struct rtl_priv *rtlpriv)
{
}
void rtl_btc_init_hw_config(struct rtl_priv *rtlpriv)
{
u8 bt_exist;
bt_exist = rtl_get_hwpg_bt_exist(rtlpriv);
RT_TRACE(rtlpriv, COMP_INIT, DBG_DMESG,
"%s, bt_exist is %d\n", __func__, bt_exist);
exhalbtc_init_hw_config(&gl_bt_coexist, !bt_exist);
exhalbtc_init_coex_dm(&gl_bt_coexist);
}
void rtl_btc_ips_notify(struct rtl_priv *rtlpriv, u8 type)
{
exhalbtc_ips_notify(&gl_bt_coexist, type);
}
void rtl_btc_lps_notify(struct rtl_priv *rtlpriv, u8 type)
{
exhalbtc_lps_notify(&gl_bt_coexist, type);
}
void rtl_btc_scan_notify(struct rtl_priv *rtlpriv, u8 scantype)
{
exhalbtc_scan_notify(&gl_bt_coexist, scantype);
}
void rtl_btc_connect_notify(struct rtl_priv *rtlpriv, u8 action)
{
exhalbtc_connect_notify(&gl_bt_coexist, action);
}
void rtl_btc_mediastatus_notify(struct rtl_priv *rtlpriv,
enum rt_media_status mstatus)
{
exhalbtc_mediastatus_notify(&gl_bt_coexist, mstatus);
}
void rtl_btc_periodical(struct rtl_priv *rtlpriv)
{
exhalbtc_periodical(&gl_bt_coexist);
}
void rtl_btc_halt_notify(void)
{
struct btc_coexist *btcoexist = &gl_bt_coexist;
exhalbtc_halt_notify(btcoexist);
}
void rtl_btc_btinfo_notify(struct rtl_priv *rtlpriv, u8 *tmp_buf, u8 length)
{
exhalbtc_bt_info_notify(&gl_bt_coexist, tmp_buf, length);
}
bool rtl_btc_is_limited_dig(struct rtl_priv *rtlpriv)
{
return gl_bt_coexist.bt_info.limited_dig;
}
bool rtl_btc_is_disable_edca_turbo(struct rtl_priv *rtlpriv)
{
bool bt_change_edca = false;
u32 cur_edca_val;
u32 edca_bt_hs_uplink = 0x5ea42b, edca_bt_hs_downlink = 0x5ea42b;
u32 edca_hs;
u32 edca_addr = 0x504;
cur_edca_val = rtl_read_dword(rtlpriv, edca_addr);
if (halbtc_is_wifi_uplink(rtlpriv)) {
if (cur_edca_val != edca_bt_hs_uplink) {
edca_hs = edca_bt_hs_uplink;
bt_change_edca = true;
}
} else {
if (cur_edca_val != edca_bt_hs_downlink) {
edca_hs = edca_bt_hs_downlink;
bt_change_edca = true;
}
}
if (bt_change_edca)
rtl_write_dword(rtlpriv, edca_addr, edca_hs);
return true;
}
bool rtl_btc_is_bt_disabled(struct rtl_priv *rtlpriv)
{
if (gl_bt_coexist.bt_info.bt_disabled)
return true;
else
return false;
}
void rtl_btc_special_packet_notify(struct rtl_priv *rtlpriv, u8 pkt_type)
{
return exhalbtc_special_packet_notify(&gl_bt_coexist, pkt_type);
}
struct rtl_btc_ops *rtl_btc_get_ops_pointer(void)
{
return &rtl_btc_operation;
}
enum rt_media_status mgnt_link_status_query(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
enum rt_media_status m_status = RT_MEDIA_DISCONNECT;
u8 bibss = (mac->opmode == NL80211_IFTYPE_ADHOC) ? 1 : 0;
if (bibss || rtlpriv->mac80211.link_state >= MAC80211_LINKED)
m_status = RT_MEDIA_CONNECT;
return m_status;
}
u8 rtl_get_hwpg_bt_exist(struct rtl_priv *rtlpriv)
{
return rtlpriv->btcoexist.btc_info.btcoexist;
}
static int __init rtl_btcoexist_module_init(void)
{
return 0;
}
static void __exit rtl_btcoexist_module_exit(void)
{
return;
}
