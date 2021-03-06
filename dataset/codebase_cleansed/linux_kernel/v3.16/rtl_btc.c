void rtl92e_btc_init_variables(struct rtl_priv *rtlpriv)
{
exhalbtc92e_initlize_variables(rtlpriv);
}
void rtl92e_btc_init_hal_vars(struct rtl_priv *rtlpriv)
{
u8 ant_num;
u8 bt_exist;
u8 bt_type;
ant_num = rtl92e_get_hwpg_ant_num(rtlpriv);
RT_TRACE(COMP_INIT, DBG_DMESG,
("%s, antNum is %d\n", __func__, ant_num));
bt_exist = rtl92e_get_hwpg_bt_exist(rtlpriv);
RT_TRACE(COMP_INIT, DBG_DMESG,
("%s, bt_exist is %d\n", __func__, bt_exist));
exhalbtc92e_set_bt_exist(bt_exist);
bt_type = rtl92e_get_hwpg_bt_type(rtlpriv);
RT_TRACE(COMP_INIT, DBG_DMESG,
("%s, bt_type is %d\n", __func__, bt_type));
exhalbtc92e_set_chip_type(bt_type);
exhalbtc92e_set_ant_num(BT_COEX_ANT_TYPE_PG, ant_num);
}
void rtl92e_btc_init_hw_config(struct rtl_priv *rtlpriv)
{
exhalbtc92e_init_hw_config(&gl92e_bt_coexist);
exhalbtc92e_init_coex_dm(&gl92e_bt_coexist);
}
void rtl92e_btc_ips_notify(struct rtl_priv *rtlpriv, u8 type)
{
exhalbtc92e_ips_notify(&gl92e_bt_coexist, type);
}
void rtl_btc_lps_notify(struct rtl_priv *rtlpriv, u8 type)
{
exhalbtc92e_lps_notify(&gl92e_bt_coexist, type);
}
void rtl92e_btc_scan_notify(struct rtl_priv *rtlpriv, u8 scantype)
{
exhalbtc92e_scan_notify(&gl92e_bt_coexist, scantype);
}
void rtl92e_btc_connect_notify(struct rtl_priv *rtlpriv, u8 action)
{
exhalbtc92e_connect_notify(&gl92e_bt_coexist, action);
}
void rtl92e_btc_mediastatus_notify(struct rtl_priv *rtlpriv,
enum rt_media_status mstatus)
{
exhalbtc92e_mediastatus_notify(&gl92e_bt_coexist, mstatus);
}
void rtl92e_btc_periodical(struct rtl_priv *rtlpriv)
{
exhalbtc92e_periodical(&gl92e_bt_coexist);
}
void rtl92e_btc_halt_notify(void)
{
exhalbtc92e_halt_notify(&gl92e_bt_coexist);
}
void rtl92e_btc_btinfo_notify(struct rtl_priv *rtlpriv, u8 *tmp_buf, u8 length)
{
exhalbtc92e_bt_info_notify(&gl92e_bt_coexist, tmp_buf, length);
}
bool rtl92e_btc_is_limited_dig(struct rtl_priv *rtlpriv)
{
return gl92e_bt_coexist.bt_info.limited_dig;
}
bool rtl92e_btc_is_disable_edca_turbo(struct rtl_priv *rtlpriv)
{
bool bt_change_edca = false;
u32 cur_edca_val;
u32 edca_bt_hs_uplink = 0x5ea42b, edca_bt_hs_downlink = 0x5ea42b;
u32 edca_hs;
u32 edca_addr = 0x504;
cur_edca_val = rtl_read_dword(rtlpriv, edca_addr);
if (halbtc92e_is_wifi_uplink(rtlpriv)) {
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
bool rtl92e_btc_is_bt_disabled(struct rtl_priv *rtlpriv)
{
if (gl92e_bt_coexist.bt_info.bt_disabled)
return true;
else
return false;
}
void rtl_btc_special_packet_notify(struct rtl_priv *rtlpriv, u8 pkt_type)
{
return exhalbtc92e_special_packet_notify(&gl92e_bt_coexist, pkt_type);
}
struct rtl_btc_ops *stg_rtl_btc_get_ops_pointer(void)
{
return &rtl_btc_operation;
}
u8 rtl92e_get_hwpg_ant_num(struct rtl_priv *rtlpriv)
{
u8 num;
if (rtlpriv->btcoexist.btc_info.ant_num == ANT_X2)
num = 2;
else
num = 1;
return num;
}
u8 rtl92e_get_hwpg_bt_exist(struct rtl_priv *rtlpriv)
{
return rtlpriv->btcoexist.btc_info.btcoexist;
}
u8 rtl92e_get_hwpg_bt_type(struct rtl_priv *rtlpriv)
{
return rtlpriv->btcoexist.btc_info.bt_type;
}
