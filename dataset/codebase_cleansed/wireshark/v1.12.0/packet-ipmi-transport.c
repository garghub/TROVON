static void
lan_serial_00(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan00_sip, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan00_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_serial_01(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Authentication types supported: ",
"No authentication types supported for this channel", ett_ipmi_trn_lan01_byte1,
lanXX_authtypes_byte, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_serial_02(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Authentication types for Callback level: ",
"No authentication types enabled", ett_ipmi_trn_lan02_byte1,
lanXX_authtypes_byte, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Authentication types for User level: ",
"No authentication types enabled", ett_ipmi_trn_lan02_byte2,
lanXX_authtypes_byte, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, "Authentication types for Operator level: ",
"No authentication types enabled", ett_ipmi_trn_lan02_byte3,
lanXX_authtypes_byte, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, "Authentication types for Administrator level: ",
"No authentication types enabled", ett_ipmi_trn_lan02_byte4,
lanXX_authtypes_byte, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 4, 1, "Authentication types for OEM level: ",
"No authentication types enabled", ett_ipmi_trn_lan02_byte5,
lanXX_authtypes_byte, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_03(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan03_ip, tvb, 0, 4, ENC_BIG_ENDIAN);
}
static void
lan_04(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan04_ipsrc, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan04_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_05(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan05_ether, tvb, 0, 6, ENC_NA);
}
static void
lan_06(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan06_subnet, tvb, 0, 4, ENC_BIG_ENDIAN);
}
static void
lan_07(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte2[] = { &hf_ipmi_trn_lan07_flags, NULL };
static const int *byte3[] = { &hf_ipmi_trn_lan07_precedence, &hf_ipmi_trn_lan07_tos, NULL };
proto_tree_add_item(tree, hf_ipmi_trn_lan07_ttl, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_trn_lan07_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL, ett_ipmi_trn_lan07_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_08(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan08_rmcp_port, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
lan_09(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan09_rmcp_port, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
lan_10(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan10_responses, &hf_ipmi_trn_lan10_gratuitous, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan10_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_11(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan11_arp_interval, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
lan_12(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan12_def_gw_ip, tvb, 0, 4, ENC_BIG_ENDIAN);
}
static void
lan_13(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan13_def_gw_mac, tvb, 0, 6, ENC_NA);
}
static void
lan_14(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan14_bkp_gw_ip, tvb, 0, 4, ENC_BIG_ENDIAN);
}
static void
lan_15(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan15_bkp_gw_mac, tvb, 0, 6, ENC_NA);
}
static void
lan_16(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_lan16_comm_string, tvb, 0, 18, ENC_ASCII|ENC_NA);
}
static void
lan_17(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan17_num_dst, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan17_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_18(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan18_dst_selector, NULL };
static const int *byte2[] = { &hf_ipmi_trn_lan18_ack, &hf_ipmi_trn_lan18_dst_type, NULL };
static const int *byte4[] = { &hf_ipmi_trn_lan18_retries, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan18_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_trn_lan18_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_lan18_tout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_trn_lan18_byte4, byte4, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_19(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan19_dst_selector, NULL };
static const int *byte2[] = { &hf_ipmi_trn_lan19_addr_format, NULL };
static const int *byte3[] = { &hf_ipmi_trn_lan19_gw_sel, NULL };
guint8 v;
v = tvb_get_guint8(tvb, 1) >> 4;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan19_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_trn_lan19_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
if (v == 0) {
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL, ett_ipmi_trn_lan19_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_lan19_ip, tvb, 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_lan19_mac, tvb, 7, 6, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_ipmi_trn_lan19_address, tvb, 2, -1, ENC_NA);
}
static void
lan_20(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte12[] = { &hf_ipmi_trn_lan20_vlan_id_enable, &hf_ipmi_trn_lan20_vlan_id, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 2, NULL, NULL, ett_ipmi_trn_lan20_byte12, byte12, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_21(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan21_vlan_prio, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan21_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_22(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan22_num_cs_entries, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan22_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
lan_23(tvbuff_t *tvb, proto_tree *tree)
{
guint i;
guint8 v;
for (i = 0; i < 16; i++) {
v = tvb_get_guint8(tvb, i + 1);
proto_tree_add_uint_format(tree, hf_ipmi_trn_lan23_cs_entry, tvb, i + 1, 1,
v, "Cipher Suite ID entry %c: %u", 'A' + i, v);
}
}
static void
lan_24(tvbuff_t *tvb, proto_tree *tree)
{
static const int *ett[] = { &ett_ipmi_trn_lan24_byte1, &ett_ipmi_trn_lan24_byte2, &ett_ipmi_trn_lan24_byte3,
&ett_ipmi_trn_lan24_byte4, &ett_ipmi_trn_lan24_byte5, &ett_ipmi_trn_lan24_byte6, &ett_ipmi_trn_lan24_byte7,
&ett_ipmi_trn_lan24_byte8 };
proto_tree *s_tree;
proto_item *ti;
guint i;
guint8 v, v1, v2;
for (i = 0; i < 8; i++) {
v = tvb_get_guint8(tvb, i + 1);
v1 = v & 0x0f;
v2 = v >> 4;
ti = proto_tree_add_text(tree, tvb, i + 1, 1,
"Cipher Suite #%d: %s (0x%02x), Cipher Suite #%d: %s (0x%02x)",
i * 2 + 1, val_to_str_const(v1, lan24_priv_vals, "Reserved"), v1,
i * 2 + 2, val_to_str_const(v2, lan24_priv_vals, "Reserved"), v2);
s_tree = proto_item_add_subtree(ti, *ett[i]);
proto_tree_add_uint_format(s_tree, hf_ipmi_trn_lan24_priv, tvb, i + 1, 1,
v2 << 4, "%sMaximum Privilege Level for Cipher Suite #%d: %s (0x%02x)",
ipmi_dcd8(v, 0xf0), i * 2 + 2, val_to_str_const(v2, lan24_priv_vals, "Reserved"), v2);
proto_tree_add_uint_format(s_tree, hf_ipmi_trn_lan24_priv, tvb, i + 1, 1,
v1, "%sMaximum Privilege Level for Cipher Suite #%d: %s (0x%02x)",
ipmi_dcd8(v, 0x0f), i * 2 + 1, val_to_str_const(v1, lan24_priv_vals, "Reserved"), v1);
}
}
static void
lan_25(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_lan25_dst_selector, NULL };
static const int *byte2[] = { &hf_ipmi_trn_lan25_addr_format, NULL };
static const int *byte34[] = { &hf_ipmi_trn_lan25_uprio, &hf_ipmi_trn_lan25_cfi, &hf_ipmi_trn_lan25_vlan_id, NULL };
guint8 v;
v = tvb_get_guint8(tvb, 1) >> 4;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_lan25_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_trn_lan25_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
switch (v) {
case 0:
break;
case 1:
proto_tree_add_bitmask_text(tree, tvb, 2, 2, NULL, NULL, ett_ipmi_trn_lan25_byte34,
byte34, ENC_LITTLE_ENDIAN, 0);
break;
default:
proto_tree_add_item(tree, hf_ipmi_trn_lan25_address, tvb, 2, -1, ENC_LITTLE_ENDIAN);
break;
}
}
static void
rq01(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_01_chan, NULL };
tvbuff_t *next;
const char *desc;
guint8 pno;
pno = tvb_get_guint8(tvb, 1);
if (pno < array_length(lan_options)) {
desc = lan_options[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_01_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_uint_format_value(tree, hf_ipmi_trn_01_param, tvb, 1, 1,
pno, "%s (0x%02x)", desc, pno);
if (pno < array_length(lan_options)) {
next = tvb_new_subset_remaining(tvb, 2);
lan_options[pno].intrp(next, tree);
} else {
proto_tree_add_item(tree, hf_ipmi_trn_01_param_data, tvb, 2, -1, ENC_NA);
}
}
static void
rq02(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_02_getrev, &hf_ipmi_trn_02_chan, NULL };
const char *desc;
guint8 pno;
pno = tvb_get_guint8(tvb, 1);
ipmi_set_data(pinfo, 0, pno);
ipmi_set_data(pinfo, 1, tvb_get_guint8(tvb, 0) & 0x80);
if (!tree) {
return;
}
if (pno < array_length(lan_options)) {
desc = lan_options[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_02_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_uint_format_value(tree, hf_ipmi_trn_02_param, tvb, 1, 1,
pno, "%s (0x%02x)", desc, pno);
proto_tree_add_item(tree, hf_ipmi_trn_02_set, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_02_block, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
rs02(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_02_rev_present, &hf_ipmi_trn_02_rev_compat, NULL };
proto_item *ti;
tvbuff_t *next;
const char *desc;
guint32 pno, req;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_02_rev, byte1, ENC_LITTLE_ENDIAN, 0);
if (!ipmi_get_data(pinfo, 0, &pno) || !ipmi_get_data(pinfo, 1, &req)) {
if (tvb_captured_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_trn_02_param_data, tvb, 1, -1, ENC_NA);
};
return;
}
if ((req & 0x80) && tvb_captured_length(tvb) > 1) {
ti = proto_tree_add_text(tree, tvb, 0, 0, "Requested parameter revision; parameter data returned");
PROTO_ITEM_SET_GENERATED(ti);
} else if (!(req & 0x80) && tvb_captured_length(tvb) == 1) {
ti = proto_tree_add_text(tree, tvb, 0, 0, "Requested parameter data; only parameter version returned");
PROTO_ITEM_SET_GENERATED(ti);
}
if (pno < array_length(lan_options)) {
desc = lan_options[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
ti = proto_tree_add_text(tree, tvb, 0, 0, "Parameter: %s", desc);
PROTO_ITEM_SET_GENERATED(ti);
if (tvb_captured_length(tvb) > 1) {
if (pno < array_length(lan_options)) {
next = tvb_new_subset_remaining(tvb, 1);
lan_options[pno].intrp(next, tree);
} else {
proto_tree_add_item(tree, hf_ipmi_trn_02_param_data, tvb, 1, -1, ENC_NA);
}
}
}
static void
rq03(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_03_chan, NULL };
static const int *byte2[] = { &hf_ipmi_trn_03_arp_resp, &hf_ipmi_trn_03_gratuitous_arp, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_03_rq_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_03_rq_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs03(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_03_status_arp_resp,
&hf_ipmi_trn_03_status_gratuitous_arp, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_03_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rq04(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_04_chan, NULL };
static const int *byte2[] = { &hf_ipmi_trn_04_clear, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_04_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_04_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs04(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_ippkts, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_iphdr_err, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_ipaddr_err, tvb, 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_ippkts_frag, tvb, 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_tx_ippkts, tvb, 8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_udppkts, tvb, 10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_validrmcp, tvb, 12, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_rx_udpproxy, tvb, 14, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_04_dr_udpproxy, tvb, 16, 2, ENC_LITTLE_ENDIAN);
}
static void
serial_03(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_serial03_connmode, &hf_ipmi_trn_serial03_terminal,
&hf_ipmi_trn_serial03_ppp, &hf_ipmi_trn_serial03_basic, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial03_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial04_timeout_fmt(gchar *s, guint32 v)
{
if (v) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d sec", 30 * v);
}
else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Does not timeout");
}
}
static void
serial_04(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial04_timeout, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial04_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_05(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_serial05_cbcp_callback,
&hf_ipmi_trn_serial05_ipmi_callback, NULL };
static const int *byte2[] = { &hf_ipmi_trn_serial05_cb_list, &hf_ipmi_trn_serial05_cb_user,
&hf_ipmi_trn_serial05_cb_prespec, &hf_ipmi_trn_serial05_no_cb, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Callback capabilities: ", "None",
ett_ipmi_trn_serial05_byte1, byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "CBCP negotiation options: ", "None",
ett_ipmi_trn_serial05_byte2, byte2, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_item(tree, hf_ipmi_trn_serial05_cb_dest1, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial05_cb_dest2, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial05_cb_dest3, tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
static void
serial_06(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial06_inactivity,
&hf_ipmi_trn_serial06_dcd, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial06_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_07(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial07_flowctl, &hf_ipmi_trn_serial07_dtrhangup, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial07_bitrate, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial07_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial07_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_08(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial08_esc_powerup,
&hf_ipmi_trn_serial08_esc_reset, &hf_ipmi_trn_serial08_switch_authcap,
&hf_ipmi_trn_serial08_switch_rmcp, &hf_ipmi_trn_serial08_esc_switch1,
&hf_ipmi_trn_serial08_esc_switch2, &hf_ipmi_trn_serial08_switch_dcdloss, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial08_sharing,
&hf_ipmi_trn_serial08_ping_callback, &hf_ipmi_trn_serial08_ping_direct,
&hf_ipmi_trn_serial08_ping_retry, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Switch/escape settings", NULL,
ett_ipmi_trn_serial08_byte1, byte1, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Sharing/ping settings", NULL,
ett_ipmi_trn_serial08_byte2, byte2, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
}
static void
serial_09(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial09_ring_duration, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial09_ring_dead, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial09_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial09_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_10(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial10_set_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial10_init_str, tvb, 1, -1, ENC_ASCII|ENC_NA);
}
static void
serial_11(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial11_esc_seq, tvb, 0, 5, ENC_ASCII|ENC_NA);
}
static void
serial_12(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial12_hangup_seq, tvb, 0, 8, ENC_ASCII|ENC_NA);
}
static void
serial_13(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial13_dial_cmd, tvb, 0, 8, ENC_ASCII|ENC_NA);
}
static void
serial_14(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial14_page_blackout, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
serial_15(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial15_comm_string, tvb, 0, 18, ENC_ASCII|ENC_NA);
}
static void
serial_16(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial16_ndest, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial16_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_17(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial17_dest_sel, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial17_ack, &hf_ipmi_trn_serial17_dest_type, NULL };
static const gint *byte4[] = { &hf_ipmi_trn_serial17_alert_retries, &hf_ipmi_trn_serial17_call_retries, NULL };
const gint *byte5[3] = { NULL, NULL, NULL };
guint8 v;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial17_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial17_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_serial17_alert_ack_timeout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, NULL, NULL,
ett_ipmi_trn_serial17_byte4, byte4, ENC_LITTLE_ENDIAN, 0);
v = tvb_get_guint8(tvb, 1) & 0x0f;
switch (v) {
case 0:
case 3:
byte5[0] = &hf_ipmi_trn_serial17_dialstr_sel;
break;
case 1:
byte5[0] = &hf_ipmi_trn_serial17_tap_sel;
break;
case 2:
case 4:
byte5[0] = &hf_ipmi_trn_serial17_ipaddr_sel;
byte5[1] = &hf_ipmi_trn_serial17_ppp_sel;
break;
default:
proto_tree_add_item(tree, hf_ipmi_trn_serial17_unknown, tvb, 4, 1, ENC_LITTLE_ENDIAN);
return;
}
proto_tree_add_bitmask_text(tree, tvb, 4, 1, NULL, NULL,
ett_ipmi_trn_serial17_byte5, byte5, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_18(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial18_call_retry, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
serial_19(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial19_destsel, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial19_flowctl, &hf_ipmi_trn_serial19_dtrhangup,
&hf_ipmi_trn_serial19_stopbits, &hf_ipmi_trn_serial19_charsize, &hf_ipmi_trn_serial19_parity, NULL };
static const gint *byte3[] = { &hf_ipmi_trn_serial19_bitrate, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial19_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial19_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL,
ett_ipmi_trn_serial19_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_20(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial20_num_dial_strings, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial20_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_21(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial21_dialsel, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial21_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_serial21_blockno, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial21_dialstr, tvb, 2, 1, ENC_ASCII|ENC_NA);
}
static void
serial_22(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial22_num_ipaddrs, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial22_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_23(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial23_destsel, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial23_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_serial23_ipaddr, tvb, 1, 4, ENC_BIG_ENDIAN);
}
static void
serial_24(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial24_num_tap_accounts, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial24_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_25(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_trn_serial25_dialstr_sel, &hf_ipmi_trn_serial25_tapsrv_sel, NULL };
proto_tree_add_item(tree, hf_ipmi_trn_serial25_tap_acct, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial25_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_26(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial26_tap_acct, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial26_tap_passwd, tvb, 1, 6, ENC_ASCII|ENC_NA);
}
static void
serial_27(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial27_tap_acct, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial27_tap_pager_id, tvb, 1, 16, ENC_ASCII|ENC_NA);
}
static void
serial_28(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial28_tapsrv_sel, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial28_confirm, NULL };
static const gint *byte10[] = { &hf_ipmi_trn_serial28_t2, &hf_ipmi_trn_serial28_t1, NULL };
static const gint *byte11[] = { &hf_ipmi_trn_serial28_t4, &hf_ipmi_trn_serial28_t3, NULL };
static const gint *byte12[] = { &hf_ipmi_trn_serial28_t6, &hf_ipmi_trn_serial28_t5, NULL };
static const gint *byte13[] = { &hf_ipmi_trn_serial28_n2, &hf_ipmi_trn_serial28_n1, NULL };
static const gint *byte14[] = { &hf_ipmi_trn_serial28_n4, &hf_ipmi_trn_serial28_n3, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_serial28_srvtype, tvb, 2, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_trn_serial28_ctrl_esc, tvb, 5, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 9, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte10, byte10, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 10, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte11, byte11, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 11, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte12, byte12, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 12, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte13, byte13, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 13, 1, NULL, NULL,
ett_ipmi_trn_serial28_byte14, byte14, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_29(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial29_op, &hf_ipmi_trn_serial29_lineedit,
&hf_ipmi_trn_serial29_deletectl, &hf_ipmi_trn_serial29_echo, &hf_ipmi_trn_serial29_handshake, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial29_o_newline, &hf_ipmi_trn_serial29_i_newline, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial29_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial29_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_30(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial30_snooping, &hf_ipmi_trn_serial30_snoopctl, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_serial30_negot_ctl, &hf_ipmi_trn_serial30_use_xmit_accm,
&hf_ipmi_trn_serial30_xmit_addr_comp, &hf_ipmi_trn_serial30_xmit_proto_comp, NULL };
static const gint *byte3[] = { &hf_ipmi_trn_serial30_ipaddr, &hf_ipmi_trn_serial30_accm,
&hf_ipmi_trn_serial30_addr_comp, &hf_ipmi_trn_serial30_proto_comp, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial30_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial30_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL,
ett_ipmi_trn_serial30_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_31(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial31_port, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
serial_32(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial32_port, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
serial_33(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial33_auth_proto, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial33_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_34(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial34_chap_name, tvb, 0, 16, ENC_ASCII|ENC_NA);
}
static void
serial_35(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial35_recv_accm, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial35_xmit_accm, tvb, 4, 4, ENC_BIG_ENDIAN);
}
static void
serial_36(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial36_snoop_accm, tvb, 0, 4, ENC_BIG_ENDIAN);
}
static void
serial_37(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial37_num_ppp, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_serial37_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_38(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial38_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial38_dialstr_sel, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
serial_39(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial39_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial39_ipaddr, tvb, 1, 4, ENC_BIG_ENDIAN);
}
static void
serial_40(tvbuff_t *tvb, proto_tree *tree)
{
int slen;
proto_tree_add_item(tree, hf_ipmi_trn_serial40_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
slen = tvb_captured_length(tvb) - 1;
if (slen > 16) {
slen = 16;
}
proto_tree_add_item(tree, hf_ipmi_trn_serial40_username, tvb, 1, slen, ENC_ASCII|ENC_NA);
}
static void
serial_41(tvbuff_t *tvb, proto_tree *tree)
{
int slen;
proto_tree_add_item(tree, hf_ipmi_trn_serial41_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
slen = tvb_captured_length(tvb) - 1;
if (slen > 16) {
slen = 16;
}
proto_tree_add_item(tree, hf_ipmi_trn_serial41_userdomain, tvb, 1, slen, ENC_ASCII|ENC_NA);
}
static void
serial_42(tvbuff_t *tvb, proto_tree *tree)
{
int slen;
proto_tree_add_item(tree, hf_ipmi_trn_serial42_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
slen = tvb_captured_length(tvb) - 1;
if (slen > 16) {
slen = 16;
}
proto_tree_add_item(tree, hf_ipmi_trn_serial42_userpass, tvb, 1, slen, ENC_ASCII|ENC_NA);
}
static void
serial_43(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial43_auth_proto, NULL };
proto_tree_add_item(tree, hf_ipmi_trn_serial43_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial43_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_44(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial44_acct_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial44_hold_time, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
serial_45(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial45_src_ipaddr, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial45_dst_ipaddr, tvb, 4, 4, ENC_BIG_ENDIAN);
}
static void
serial_46(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial46_tx_bufsize, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
serial_47(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial47_rx_bufsize, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
serial_48(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial48_ipaddr, tvb, 0, 4, ENC_BIG_ENDIAN);
}
static void
serial_49(tvbuff_t *tvb, proto_tree *tree)
{
int slen;
proto_tree_add_item(tree, hf_ipmi_trn_serial49_blockno, tvb, 0, 1, ENC_LITTLE_ENDIAN);
slen = tvb_captured_length(tvb) - 1;
if (slen > 16) {
slen = 16;
}
proto_tree_add_item(tree, hf_ipmi_trn_serial49_dialstr, tvb, 1, slen, ENC_ASCII|ENC_NA);
}
static void
serial_50(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_serial50_115200, &hf_ipmi_trn_serial50_57600,
&hf_ipmi_trn_serial50_38400, &hf_ipmi_trn_serial50_19200, &hf_ipmi_trn_serial50_9600, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Bit rate support: ", "None",
ett_ipmi_trn_serial50_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_51(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_trn_serial51_ipmi_channel, &hf_ipmi_trn_serial51_conn_num, NULL };
static const gint *byte3[] = { &hf_ipmi_trn_serial51_ipmi_sharing,
&hf_ipmi_trn_serial51_ipmi_sol, &hf_ipmi_trn_serial51_chan_num, NULL };
proto_tree_add_item(tree, hf_ipmi_trn_serial51_port_assoc_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_serial51_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL,
ett_ipmi_trn_serial51_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
static void
serial_52(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial52_port_assoc_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial52_conn_name, tvb, 1, 16, ENC_NA);
}
static void
serial_53(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_serial53_port_assoc_sel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_serial53_chan_name, tvb, 1, 16, ENC_NA);
}
static void
rq10(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_10_chan, NULL };
tvbuff_t *next;
const char *desc;
guint8 pno;
pno = tvb_get_guint8(tvb, 1);
if (pno < array_length(serial_options)) {
desc = serial_options[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_trn_10_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_uint_format_value(tree, hf_ipmi_trn_10_param, tvb, 1, 1,
pno, "%s (0x%02x)", desc, pno);
if (pno < array_length(serial_options)) {
next = tvb_new_subset_remaining(tvb, 2);
serial_options[pno].intrp(next, tree);
} else {
proto_tree_add_item(tree, hf_ipmi_trn_10_param_data, tvb, 2, -1, ENC_NA);
}
}
static void
rq11(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_11_getrev, &hf_ipmi_trn_11_chan, NULL };
const char *desc;
guint8 pno;
pno = tvb_get_guint8(tvb, 1);
ipmi_set_data(pinfo, 0, pno);
ipmi_set_data(pinfo, 1, tvb_get_guint8(tvb, 0));
if (!tree) {
return;
}
if (pno < array_length(serial_options)) {
desc = serial_options[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_11_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_uint_format_value(tree, hf_ipmi_trn_11_param, tvb, 1, 1,
pno, "%s (0x%02x)", desc, pno);
proto_tree_add_item(tree, hf_ipmi_trn_11_set, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_11_block, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
rs11(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_trn_11_rev_present, &hf_ipmi_trn_11_rev_compat, NULL };
proto_item *ti;
tvbuff_t *next;
const char *desc;
guint32 pno, req;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_11_rev, byte1, ENC_LITTLE_ENDIAN, 0);
if (!ipmi_get_data(pinfo, 0, &pno) || !ipmi_get_data(pinfo, 1, &req)) {
if (tvb_captured_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_trn_11_param_data, tvb, 1, -1, ENC_NA);
};
return;
}
if (pno < array_length(serial_options)) {
desc = serial_options[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
if ((req & 0x80) && tvb_captured_length(tvb) > 1) {
ti = proto_tree_add_text(tree, tvb, 0, 0, "Requested parameter revision; parameter data returned");
PROTO_ITEM_SET_GENERATED(ti);
} else if (!(req & 0x80) && tvb_captured_length(tvb) == 1) {
ti = proto_tree_add_text(tree, tvb, 0, 0, "Requested parameter data; only parameter version returned");
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_text(tree, tvb, 0, 0, "Parameter: %s", desc);
PROTO_ITEM_SET_GENERATED(ti);
if (tvb_captured_length(tvb) > 1) {
if (pno < array_length(serial_options)) {
next = tvb_new_subset_remaining(tvb, 1);
serial_options[pno].intrp(next, tree);
} else {
proto_tree_add_item(tree, hf_ipmi_trn_11_param_data, tvb, 1, -1, ENC_NA);
}
}
}
static void
rq12(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_12_chan, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_12_mux_setting, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_12_rq_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_12_rq_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs12(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_12_sw_to_sys, &hf_ipmi_trn_12_sw_to_bmc,
&hf_ipmi_trn_12_alert, &hf_ipmi_trn_12_msg, &hf_ipmi_trn_12_req, &hf_ipmi_trn_12_mux_state, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_12_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rq13(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_13_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_13_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rs13(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_13_code1, tvb, 0, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_trn_13_code2, tvb, 3, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_trn_13_code3, tvb, 6, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_trn_13_code4, tvb, 9, 3, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_ipmi_trn_13_code5, tvb, 12, 3, ENC_ASCII|ENC_NA);
}
static void
rq14(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_14_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_14_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_14_block, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_14_data, tvb, 2, 16, ENC_NA);
}
static void
rq15(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_15_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_15_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_15_block, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs15(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_trn_15_data, tvb, 0, 16, ENC_NA);
}
static void
rq16(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_16_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_16_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_16_src_port, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_16_dst_port, tvb, 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_16_src_addr, tvb, 5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_16_dst_addr, tvb, 9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_16_bytes, tvb, 13, 2, ENC_LITTLE_ENDIAN);
}
static void
tr17_fmt_blockno(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d%s",
v, v ? "" : " (get received data length)");
}
static void
rq17(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_17_chan, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_17_clear, &hf_ipmi_trn_17_block_num, NULL };
ipmi_set_data(pinfo, 0, tvb_get_guint8(tvb, 1) & 0x7f);
if (!tree) {
return;
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_17_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_17_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs17(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 bno;
if (ipmi_get_data(pinfo, 0, &bno) && bno == 0) {
proto_tree_add_item(tree, hf_ipmi_trn_17_size, tvb, 0, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_ipmi_trn_17_data, tvb, 0,
tvb_captured_length(tvb) < 16 ? tvb_captured_length(tvb) : 16, ENC_NA);
}
}
static void
rq18(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_18_state, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_18_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_trn_18_ipmi_ver, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq19(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_19_chan, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_19_dest_sel, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_19_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_19_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
parse_callback_options(tvbuff_t *tvb, guint offs, proto_tree *tree)
{
static const gint *usercap[] = { &hf_ipmi_trn_XX_cap_cbcp, &hf_ipmi_trn_XX_cap_ipmi, NULL };
static const gint *cbcp[] = { &hf_ipmi_trn_XX_cbcp_from_list, &hf_ipmi_trn_XX_cbcp_user,
&hf_ipmi_trn_XX_cbcp_prespec, &hf_ipmi_trn_XX_cbcp_nocb, NULL };
proto_tree_add_bitmask_text(tree, tvb, offs, 1,
"User callback capabilities: ", "None",
ett_ipmi_trn_XX_usercap, usercap, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_bitmask_text(tree, tvb, offs + 1, 1,
"CBCP negotiation options: ", "None",
ett_ipmi_trn_XX_cbcp, cbcp, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_item(tree, hf_ipmi_trn_XX_dst1, tvb, offs + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_XX_dst2, tvb, offs + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_trn_XX_dst3, tvb, offs + 4, 1, ENC_LITTLE_ENDIAN);
}
static void
rq1a(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_1a_user, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_1a_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_1a_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_1a_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
parse_callback_options(tvb, 2, tree);
}
static void
rq1b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_trn_1b_user, NULL };
static const gint *byte2[] = { &hf_ipmi_trn_1b_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_trn_1b_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_trn_1b_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs1b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
parse_callback_options(tvb, 0, tree);
}
void
ipmi_register_transport(gint proto_ipmi)
{
static hf_register_info hf[] = {
{ &hf_ipmi_trn_lan00_sip,
{ "Set In Progress",
"ipmi.lan00.sip", FT_UINT8, BASE_HEX, lan00_sip_vals, 0x03, NULL, HFILL }},
{ &hf_ipmi_trn_lanXX_oem,
{ "OEM Proprietary",
"ipmi.lanXX.oem", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_trn_lanXX_passwd,
{ "Straight password/key",
"ipmi.lanXX.passwd", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_trn_lanXX_md5,
{ "MD5",
"ipmi.lanXX.md5", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_lanXX_md2,
{ "MD2",
"ipmi.lanXX.md2", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_lanXX_none,
{ "None",
"ipmi.lanXX.none", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_lan03_ip,
{ "IP Address",
"ipmi.lan03.ip", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan04_ipsrc,
{ "IP Address Source",
"ipmi.lan04.ipsrc", FT_UINT8, BASE_HEX, lan04_ipsrc_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_lan05_ether,
{ "MAC Address",
"ipmi.lan05.mac", FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan06_subnet,
{ "Subnet Mask",
"ipmi.lan06.subnet", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan07_ttl,
{ "Time-to-live",
"ipmi.lan07.ttl", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan07_flags,
{ "Flags",
"ipmi.lan07.flags", FT_UINT8, BASE_HEX, NULL, 0xe0, NULL, HFILL }},
{ &hf_ipmi_trn_lan07_precedence,
{ "Precedence",
"ipmi.lan07.precedence", FT_UINT8, BASE_DEC, NULL, 0xe0, NULL, HFILL }},
{ &hf_ipmi_trn_lan07_tos,
{ "Type of service",
"ipmi.lan07.tos", FT_UINT8, BASE_HEX, NULL, 0x1e, NULL, HFILL }},
{ &hf_ipmi_trn_lan08_rmcp_port,
{ "Primary RMCP Port Number",
"ipmi.lan08.rmcp_port", FT_UINT16, BASE_CUSTOM, ipmi_fmt_udpport, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan09_rmcp_port,
{ "Secondary RMCP Port Number",
"ipmi.lan09.rmcp_port", FT_UINT16, BASE_CUSTOM, ipmi_fmt_udpport, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan10_responses,
{ "ARP responses",
"ipmi.lan10.responses", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_lan10_gratuitous,
{ "Gratuitous ARPs",
"ipmi.lan10.gratuitous", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_lan11_arp_interval,
{ "Gratuitous ARP interval",
"ipmi.lan10.arp_interval", FT_UINT8, BASE_CUSTOM, ipmi_fmt_500ms_0based, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan12_def_gw_ip,
{ "Default Gateway Address",
"ipmi.lan12.def_gw_ip", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan13_def_gw_mac,
{ "Default Gateway MAC Address",
"ipmi.lan13.def_gw_mac", FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan14_bkp_gw_ip,
{ "Backup Gateway Address",
"ipmi.lan14.bkp_gw_ip", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan15_bkp_gw_mac,
{ "Backup Gateway MAC Address",
"ipmi.lan15.bkp_gw_mac", FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan16_comm_string,
{ "Community String",
"ipmi.lan16.comm_string", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan17_num_dst,
{ "Number of Destinations",
"ipmi.lan17.num_dst", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_lan18_dst_selector,
{ "Destination Selector",
"ipmi.lan18.dst_selector", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_lan18_ack,
{ "Alert Acknowledged",
"ipmi.lan18.ack", FT_BOOLEAN, 8, TFS(&lan18_ack_tfs), 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_lan18_dst_type,
{ "Destination Type",
"ipmi.lan18.dst_type", FT_UINT8, BASE_HEX, lan18_dst_type_vals, 0x07, NULL, HFILL }},
{ &hf_ipmi_trn_lan18_tout,
{ "Timeout/Retry Interval",
"ipmi.lan18.tout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_0based, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan18_retries,
{ "Retries",
"ipmi.lan18.retries", FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }},
{ &hf_ipmi_trn_lan19_dst_selector,
{ "Destination Selector",
"ipmi.lan19.dst_selector", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_lan19_addr_format,
{ "Address Format",
"ipmi.lan19.addr_format", FT_UINT8, BASE_HEX, lan19_af_vals, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_lan19_address,
{ "Address (format unknown)",
"ipmi.lan19.address", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan19_gw_sel,
{ "Gateway selector",
"ipmi.lan19.gw_sel", FT_BOOLEAN, 8, TFS(&lan19_gw_sel_tfs), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_lan19_ip,
{ "Alerting IP Address",
"ipmi.lan19.ip", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan19_mac,
{ "Alerting MAC Address",
"ipmi.lan19.mac", FT_ETHER, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan20_vlan_id_enable,
{ "VLAN ID Enable",
"ipmi.lan20.vlan_id_enable", FT_BOOLEAN, 16, TFS(&lan20_enable_tfs), 0x8000, NULL, HFILL }},
{ &hf_ipmi_trn_lan20_vlan_id,
{ "VLAN ID",
"ipmi.lan20.vlan_id", FT_UINT16, BASE_HEX, NULL, 0x0fff, NULL, HFILL }},
{ &hf_ipmi_trn_lan21_vlan_prio,
{ "VLAN Priority",
"ipmi.lan21.vlan_prio", FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }},
{ &hf_ipmi_trn_lan22_num_cs_entries,
{ "Number of Cipher Suite Entries",
"ipmi.lan22.num_cs_entries", FT_UINT8, BASE_DEC, NULL, 0x1f, NULL, HFILL }},
{ &hf_ipmi_trn_lan23_cs_entry,
{ "Cipher Suite ID",
"ipmi.lan23.cs_entry", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan24_priv,
{ "Maximum Privilege Level",
"ipmi.lan24.priv", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan25_dst_selector,
{ "Destination Selector",
"ipmi.lan25.dst_selector", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_lan25_addr_format,
{ "Address Format",
"ipmi.lan25.addr_format", FT_UINT8, BASE_HEX, lan25_af_vals, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_lan25_address,
{ "Address (format unknown)",
"ipmi.lan25.address", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_lan25_uprio,
{ "User priority",
"ipmi.lan25.uprio", FT_UINT16, BASE_DEC, NULL, 0xe000, NULL, HFILL }},
{ &hf_ipmi_trn_lan25_cfi,
{ "CFI",
"ipmi.lan25.cfi", FT_BOOLEAN, 16, NULL, 0x1000, NULL, HFILL }},
{ &hf_ipmi_trn_lan25_vlan_id,
{ "VLAN ID",
"ipmi.lan25.vlan_id", FT_UINT16, BASE_HEX, NULL, 0x0fff, NULL, HFILL }},
{ &hf_ipmi_trn_serial03_connmode,
{ "Connection Mode",
"ipmi.serial03.connmode", FT_BOOLEAN, 8, TFS(&serial03_connmode_tfs), 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_serial03_terminal,
{ "Terminal Mode",
"ipmi.serial03.terminal", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial03_ppp,
{ "PPP Mode",
"ipmi.serial03.ppp", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial03_basic,
{ "Basic Mode",
"ipmi.serial03.basic", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial04_timeout,
{ "Session Inactivity Timeout",
"ipmi.serial04.timeout", FT_UINT8, BASE_CUSTOM, serial04_timeout_fmt, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cbcp_callback,
{ "CBCP Callback",
"ipmi.serial05.cbcp", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_ipmi_callback,
{ "IPMI Callback",
"ipmi.serial05.ipmi", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cb_list,
{ "Callback to list of possible numbers",
"ipmi.serial05.cb_list", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cb_user,
{ "Callback to user-specifiable number",
"ipmi.serial05.cb_user", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cb_prespec,
{ "Callback to pre-specified number",
"ipmi.serial05.cb_prespec", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_no_cb,
{ "No callback",
"ipmi.serial05.no_cb", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cb_dest1,
{ "Callback destination 1",
"ipmi.serial05.cb_dest1", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cb_dest2,
{ "Callback destination 2",
"ipmi.serial05.cb_dest2", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial05_cb_dest3,
{ "Callback destination 3",
"ipmi.serial05.cb_dest3", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial06_inactivity,
{ "Session Inactivity Timeout",
"ipmi.serial06.inactivity", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial06_dcd,
{ "Close on DCD Loss",
"ipmi.serial06.dcd", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial07_flowctl,
{ "Flow Control",
"ipmi.serial07.flowctl", FT_UINT8, BASE_HEX, serialXX_flowctl_vals, 0xc0, NULL, HFILL }},
{ &hf_ipmi_trn_serial07_dtrhangup,
{ "DTR Hang-up",
"ipmi.serial07.dtrhangup", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ipmi_trn_serial07_bitrate,
{ "Bit rate",
"ipmi.serial07.bitrate", FT_UINT8, BASE_HEX, serialXX_bitrate_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_esc_powerup,
{ "Power-up/wakeup via ESC-^",
"ipmi.serial08.esc_powerup", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x40, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_esc_reset,
{ "Hard reset via ESC-R-ESC-r-ESC-R",
"ipmi.serial08.esc_reset", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_switch_authcap,
{ "Baseboard-to-BMC switch on Get Channel Auth Capabilities",
"ipmi.serial08.switch_authcap", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x10, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_switch_rmcp,
{ "Switch to BMC on IPMI-RMCP pattern",
"ipmi.serial08.switch_rmcp", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_esc_switch1,
{ "BMC-to-Baseboard switch via ESC-Q",
"ipmi.serial08.esc_switch1", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_esc_switch2,
{ "Baseboard-to-BMC switch via ESC-(",
"ipmi.serial08.esc_switch2", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_switch_dcdloss,
{ "Switch to BMC on DCD loss",
"ipmi.serial08.switch_dcdloss", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_sharing,
{ "Serial Port Sharing",
"ipmi.serial08.sharing", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_ping_callback,
{ "Serial/Modem Connection Active during callback",
"ipmi.serial08.ping_callback", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_ping_direct,
{ "Serial/Modem Connection Active during direct call",
"ipmi.serial08.ping_direct", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial08_ping_retry,
{ "Retry Serial/Modem Connection Active",
"ipmi.serial08.ping_retry", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial09_ring_duration,
{ "Ring Duration",
"ipmi.serial09.ring_duration", FT_UINT8, BASE_CUSTOM, ipmi_fmt_500ms_1based, 0x3f, NULL, HFILL }},
{ &hf_ipmi_trn_serial09_ring_dead,
{ "Ring Dead Time",
"ipmi.serial09.ring_dead", FT_UINT8, BASE_CUSTOM, ipmi_fmt_500ms_0based, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial10_set_sel,
{ "Set selector (16-byte block #)",
"ipmi.serial10.set_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial10_init_str,
{ "Modem Init String",
"ipmi.serial10.init_str", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial11_esc_seq,
{ "Modem Escape Sequence",
"ipmi.serial11.esc_seq", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial12_hangup_seq,
{ "Modem Hang-up Sequence",
"ipmi.serial12.hangup_seq", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial13_dial_cmd,
{ "Modem Dial Command",
"ipmi.serial13.dial_cmd", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial14_page_blackout,
{ "Page Blackout Interval (minutes)",
"ipmi.serial14.page_blackout", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial15_comm_string,
{ "Community String",
"ipmi.serial15.comm_string", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial16_ndest,
{ "Number of non-volatile Alert Destinations",
"ipmi.serial16.ndest", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_dest_sel,
{ "Destination Selector",
"ipmi.serial17.dest_sel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_ack,
{ "Alert Acknowledge",
"ipmi.serial17.ack", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_dest_type,
{ "Destination Type",
"ipmi.serial17.dest_type", FT_UINT8, BASE_HEX, serial17_dest_type_vals, 0x0f, NULL, HFILL }},
#if 0
{ &hf_ipmi_trn_serial17_ack_timeout,
{ "Alert Acknowledge Timeout",
"ipmi.serial17.ack_timeout", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
#endif
{ &hf_ipmi_trn_serial17_alert_retries,
{ "Alert retries",
"ipmi.serial17.alert_retries", FT_UINT8, BASE_DEC, NULL, 0x70, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_call_retries,
{ "Call retries",
"ipmi.serial17.call_retries", FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_alert_ack_timeout,
{ "Alert Acknowledge Timeout",
"ipmi.serial17.alert_ack_timeout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_0based, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_dialstr_sel,
{ "Dial String Selector",
"ipmi.serial17.dialstr_sel", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_tap_sel,
{ "TAP Account Selector",
"ipmi.serial17.tap_sel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_ipaddr_sel,
{ "Destination IP Address Selector",
"ipmi.serial17.ipaddr_sel", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_ppp_sel,
{ "PPP Account Set Selector",
"ipmi.serial17.ppp_sel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial17_unknown,
{ "Destination-specific (format unknown)",
"ipmi.serial17.unknown", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial18_call_retry,
{ "Call Retry Interval",
"ipmi.serial18.call_retry", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_destsel,
{ "Destination selector",
"ipmi.serial19.destsel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_flowctl,
{ "Flow Control",
"ipmi.serial19.flowctl", FT_UINT8, BASE_HEX, serialXX_flowctl_vals, 0xc0, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_dtrhangup,
{ "DTR Hang-up",
"ipmi.serial19.dtrhangup", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_stopbits,
{ "Stop bits",
"ipmi.serial19.stopbits", FT_BOOLEAN, 8, TFS(&serial19_stopbits_tfs), 0x10, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_charsize,
{ "Character size",
"ipmi.serial19.charsize", FT_BOOLEAN, 8, TFS(&serial19_charsize_tfs), 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_parity,
{ "Parity",
"ipmi.serial19.parity", FT_UINT8, BASE_HEX, serial19_parity_vals, 0x07, NULL, HFILL }},
{ &hf_ipmi_trn_serial19_bitrate,
{ "Bit rate",
"ipmi.serial19.bitrate", FT_UINT8, BASE_HEX, serialXX_bitrate_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial20_num_dial_strings,
{ "Number of Dial Strings",
"ipmi.serial20.num_dial_strings", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial21_dialsel,
{ "Dial String Selector",
"ipmi.serial21.dialsel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial21_blockno,
{ "Block number",
"ipmi.serial21.blockno", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial21_dialstr,
{ "Dial string",
"ipmi.serial21.dialstr", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial22_num_ipaddrs,
{ "Number of Alert Destination IP Addresses",
"ipmi.serial22.num_ipaddrs", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial23_destsel,
{ "Destination IP Address selector",
"ipmi.serial23.destsel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial23_ipaddr,
{ "Destination IP Address",
"ipmi.serial23.ipaddr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial24_num_tap_accounts,
{ "Number of TAP Accounts",
"ipmi.serial24.num_tap_accounts", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial25_tap_acct,
{ "TAP Account Selector",
"ipmi.serial25.tap_acct", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial25_dialstr_sel,
{ "Dial String Selector",
"ipmi.serial25.dialstr_sel", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial25_tapsrv_sel,
{ "TAP Service Settings Selector",
"ipmi.serial25.tapsrv_sel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial26_tap_acct,
{ "TAP Account Selector",
"ipmi.serial26.tap_acct", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial26_tap_passwd,
{ "TAP Password",
"ipmi.serial26.tap_passwd", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial27_tap_acct,
{ "TAP Account Selector",
"ipmi.serial27.tap_acct", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial27_tap_pager_id,
{ "TAP Pager ID String",
"ipmi.serial27.tap_pager_id", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_tapsrv_sel,
{ "TAP Service Settings Selector",
"ipmi.serial28.tapsrv_sel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_confirm,
{ "TAP Confirmation",
"ipmi.serial28.confirm", FT_UINT8, BASE_HEX, serial28_confirm_vals, 0x03, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_srvtype,
{ "TAP 'SST' Service Type",
"ipmi.serial28.srvtype", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_ctrl_esc,
{ "TAP Control-character escaping mask",
"ipmi.serial28.ctrl_esc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_t2,
{ "TAP T2",
"ipmi.serial28.tap_t2", FT_UINT8, BASE_CUSTOM, ipmi_fmt_500ms_0based, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_t1,
{ "TAP T1",
"ipmi.serial28.tap_t1", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_0based, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_t4,
{ "TAP T4",
"ipmi.serial28.tap_t4", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_0based, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_t3,
{ "TAP T3",
"ipmi.serial28.tap_t3", FT_UINT8, BASE_CUSTOM, ipmi_fmt_2s_0based, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_t6,
{ "IPMI T6",
"ipmi.serial28.ipmi_t6", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_0based, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_t5,
{ "TAP T5",
"ipmi.serial28.tap_t5", FT_UINT8, BASE_CUSTOM, ipmi_fmt_2s_0based, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_n2,
{ "TAP N2",
"ipmi.serial28.tap_n2", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_n1,
{ "TAP N1",
"ipmi.serial28.tap_n1", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_n4,
{ "IPMI N4",
"ipmi.serial28.ipmi_n4", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial28_n3,
{ "TAP N3",
"ipmi.serial28.tap_n3", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_op,
{ "Parameter Operation",
"ipmi.serial29.op", FT_UINT8, BASE_HEX, serial29_op_vals, 0xc0, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_lineedit,
{ "Line Editing",
"ipmi.serial29.lineedit", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_deletectl,
{ "Delete control",
"ipmi.serial29.deletectl", FT_UINT8, BASE_HEX, serial29_delete_vals, 0x0c, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_echo,
{ "Echo",
"ipmi.serial29.echo", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_handshake,
{ "Handshake",
"ipmi.serial29.handshake", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_o_newline,
{ "Output newline sequence",
"ipmi.serial29.o_newline", FT_UINT8, BASE_HEX, serial29_o_nl_vals, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial29_i_newline,
{ "Input newline sequence",
"ipmi.serial29.i_newline", FT_UINT8, BASE_HEX, serial29_i_nl_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_snooping,
{ "System Negotiation Snooping",
"ipmi.serial30.snooping", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_snoopctl,
{ "Snoop ACCM Control",
"ipmi.serial30.snoopctl", FT_UINT8, BASE_HEX, serial30_snoopctl_vals, 0x03, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_negot_ctl,
{ "BMC negotiates link parameters",
"ipmi.serial30.negot_ctl", FT_UINT8, BASE_HEX, serial30_negoctl_vals, 0x30, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_use_xmit_accm,
{ "Filtering incoming chars",
"ipmi.serial30.filter", FT_BOOLEAN, 8, TFS(&serial30_filter_tfs), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_xmit_addr_comp,
{ "Transmit with Address and Ctl Field Compression",
"ipmi.serial30.xmit_addr_comp", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_xmit_proto_comp,
{ "Transmit with Protocol Field Compression",
"ipmi.serial30.xmit_proto_comp", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_ipaddr,
{ "IP Address negotiation",
"ipmi.serial30.ipaddr", FT_UINT8, BASE_HEX, serial30_ipaddr_val, 0x18, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_accm,
{ "ACCM Negotiation",
"ipmi.serial30.accm", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_addr_comp,
{ "Address and Ctl Field Compression",
"ipmi.serial30.addr_comp", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial30_proto_comp,
{ "Protocol Field Compression",
"ipmi.serial30.proto_comp", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial31_port,
{ "Primary RMCP Port Number",
"ipmi.serial31.port", FT_UINT16, BASE_CUSTOM, ipmi_fmt_udpport, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial32_port,
{ "Secondary RMCP Port Number",
"ipmi.serial32.port", FT_UINT16, BASE_CUSTOM, ipmi_fmt_udpport, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial33_auth_proto,
{ "PPP Link Authentication Protocol",
"ipmi.serial33.auth_proto", FT_UINT8, BASE_HEX, serialXX_proto_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial34_chap_name,
{ "CHAP Name",
"ipmi.serial34.chap_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial35_recv_accm,
{ "Receive ACCM",
"ipmi.serial35.recv_accm", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial35_xmit_accm,
{ "Transmit ACCM",
"ipmi.serial35.xmit_accm", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial36_snoop_accm,
{ "Snoop Receive ACCM",
"ipmi.serial36.snoop_accm", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial37_num_ppp,
{ "Number of PPP Accounts",
"ipmi.serial37.num_ppp", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial38_acct_sel,
{ "PPP Account Selector",
"ipmi.serial38.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial38_dialstr_sel,
{ "Dial String Selector",
"ipmi.serial38.dialstr_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial39_acct_sel,
{ "PPP Account Selector",
"ipmi.serial39.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial39_ipaddr,
{ "IP Address",
"ipmi.serial39.ipaddr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial40_acct_sel,
{ "PPP Account Selector",
"ipmi.serial40.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial40_username,
{ "User Name",
"ipmi.serial40.username", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial41_acct_sel,
{ "PPP Account Selector",
"ipmi.serial41.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial41_userdomain,
{ "User Domain",
"ipmi.serial41.userdomain", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial42_acct_sel,
{ "PPP Account Selector",
"ipmi.serial42.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial42_userpass,
{ "User Password",
"ipmi.serial42.userpass", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial43_acct_sel,
{ "PPP Account Selector",
"ipmi.serial43.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial43_auth_proto,
{ "Link Auth Type",
"ipmi.serial43.auth_proto", FT_UINT8, BASE_HEX, serialXX_proto_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial44_acct_sel,
{ "PPP Account Selector",
"ipmi.serial44.acct_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial44_hold_time,
{ "Connection Hold Time",
"ipmi.serial44.hold_time", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial45_src_ipaddr,
{ "Source IP Address",
"ipmi.serial45.src_ipaddr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial45_dst_ipaddr,
{ "Destination IP Address",
"ipmi.serial45.dst_ipaddr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial46_tx_bufsize,
{ "Transmit Buffer Size",
"ipmi.serial46.tx_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial47_rx_bufsize,
{ "Receive Buffer Size",
"ipmi.serial47.rx_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial48_ipaddr,
{ "Remote Console IP Address",
"ipmi.serial48.ipaddr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial49_blockno,
{ "Block number",
"ipmi.serial49.blockno", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial49_dialstr,
{ "Dial string",
"ipmi.serial49.dialstr", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial50_115200,
{ "115200",
"ipmi.serial50.115200", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_trn_serial50_57600,
{ "57600",
"ipmi.serial50.57600", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_serial50_38400,
{ "38400",
"ipmi.serial50.38400", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_serial50_19200,
{ "19200",
"ipmi.serial50.19200", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_serial50_9600,
{ "9600",
"ipmi.serial50.9600", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_serial51_port_assoc_sel,
{ "Serial Port Association Entry",
"ipmi.serial51.port_assoc_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial51_ipmi_channel,
{ "IPMI Channel",
"ipmi.serial51.ipmi_channel", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_serial51_conn_num,
{ "Connector number",
"ipmi.serial51.conn_num", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial51_ipmi_sharing,
{ "Used with IPMI Serial Port Sharing",
"ipmi.serial51.ipmi_sharing", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_serial51_ipmi_sol,
{ "Used with IPMI Serial-over-LAN",
"ipmi.serial51.ipmi_sol", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_trn_serial51_chan_num,
{ "Serial controller channel number",
"ipmi.serial51.chan_num", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_serial52_port_assoc_sel,
{ "Serial Port Association Entry",
"ipmi.serial52.port_assoc_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial52_conn_name,
{ "Connector Name",
"ipmi.serial52_conn_name", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial53_port_assoc_sel,
{ "Serial Port Association Entry",
"ipmi.serial53.port_assoc_sel", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_serial53_chan_name,
{ "Channel Name",
"ipmi.serial52_chan_name", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_01_chan,
{ "Channel",
"ipmi.tr01.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_01_param,
{ "Parameter Selector",
"ipmi.tr01.param", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_01_param_data,
{ "Parameter data",
"ipmi.tr01.param_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_02_getrev,
{ "Get parameter revision only",
"ipmi.tr02.getrev", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_02_chan,
{ "Channel",
"ipmi.tr02.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_02_param,
{ "Parameter selector",
"ipmi.tr02.param", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_02_set,
{ "Set selector",
"ipmi.tr02.set", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_02_block,
{ "Block selector",
"ipmi.tr02.block", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_02_rev_present,
{ "Present parameter revision",
"ipmi.tr02.rev.present", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_02_rev_compat,
{ "Oldest forward-compatible",
"ipmi.tr02.rev.compat", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_02_param_data,
{ "Parameter data",
"ipmi.tr02.param_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_03_chan,
{ "Channel",
"ipmi.tr03.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_03_arp_resp,
{ "BMC-generated ARP responses",
"ipmi.tr03.arp_resp", FT_BOOLEAN, 8, TFS(&tfs_03_suspend), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_03_gratuitous_arp,
{ "Gratuitous ARPs",
"ipmi.tr03.gratuitous_arp", FT_BOOLEAN, 8, TFS(&tfs_03_suspend), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_03_status_arp_resp,
{ "ARP Response status",
"ipmi.tr03.status_arp_resp", FT_BOOLEAN, 8, TFS(&tfs_03_arp_status), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_03_status_gratuitous_arp,
{ "Gratuitous ARP status",
"ipmi.tr03.status_gratuitous_arp", FT_BOOLEAN, 8, TFS(&tfs_03_arp_status), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_04_chan,
{ "Channel",
"ipmi.tr04.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_04_clear,
{ "Statistics",
"ipmi.tr04.clear", FT_BOOLEAN, 8, TFS(&tfs_04_clear), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_ippkts,
{ "Received IP Packets",
"ipmi.tr04.rx_ippkts", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_iphdr_err,
{ "Received IP Header Errors",
"ipmi.tr04.rx_iphdr_err", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_ipaddr_err,
{ "Received IP Address Errors",
"ipmi.tr04.rx_ipaddr_err", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_ippkts_frag,
{ "Received Fragmented IP Packets",
"ipmi.tr04.rx_ippkts_frag", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_tx_ippkts,
{ "Transmitted IP Packets",
"ipmi.tr04.tx_ippkts", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_udppkts,
{ "Received UDP Packets",
"ipmi.tr04.rx_udppkts", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_validrmcp,
{ "Received Valid RMCP Packets",
"ipmi.tr04.rx_validrmcp", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_rx_udpproxy,
{ "Received UDP Proxy Packets",
"ipmi.tr04.rx_udpproxy", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_04_dr_udpproxy,
{ "Dropped UDP Proxy Packets",
"ipmi.tr04.dr_udpproxy", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_10_chan,
{ "Channel",
"ipmi.tr10.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_10_param,
{ "Parameter Selector",
"ipmi.tr10.param", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_10_param_data,
{ "Parameter data",
"ipmi.tr10.param_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_11_getrev,
{ "Get parameter revision only",
"ipmi.tr11.getrev", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_11_chan,
{ "Channel",
"ipmi.tr11.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_11_param,
{ "Parameter selector",
"ipmi.tr11.param", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_11_set,
{ "Set selector",
"ipmi.tr11.set", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_11_block,
{ "Block selector",
"ipmi.tr11.block", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_11_rev_present,
{ "Present parameter revision",
"ipmi.tr11.rev.present", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ipmi_trn_11_rev_compat,
{ "Oldest forward-compatible",
"ipmi.tr11.rev.compat", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_11_param_data,
{ "Parameter data",
"ipmi.tr11.param_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_12_chan,
{ "Channel",
"ipmi.tr12.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_12_mux_setting,
{ "Mux Setting",
"ipmi.tr12.mux_setting", FT_UINT8, BASE_HEX, vals_12_mux, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_12_sw_to_sys,
{ "Requests to switch to system",
"ipmi.tr12.sw_to_sys", FT_BOOLEAN, 8, TFS(&tfs_12_blocked), 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_12_sw_to_bmc,
{ "Requests to switch to BMC",
"ipmi.tr12.sw_to_bmc", FT_BOOLEAN, 8, TFS(&tfs_12_blocked), 0x40, NULL, HFILL }},
{ &hf_ipmi_trn_12_alert,
{ "Alert in progress",
"ipmi.tr12.alert", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_12_msg,
{ "IPMI/OEM messaging active",
"ipmi.tr12.msg", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_12_req,
{ "Request",
"ipmi.tr12.req", FT_BOOLEAN, 8, TFS(&tfs_12_req), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_12_mux_state,
{ "Mux set to",
"ipmi.tr12.mux_state", FT_BOOLEAN, 8, TFS(&tfs_12_mux_state), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_13_chan,
{ "Channel",
"ipmi.tr13.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_13_code1,
{ "Last code",
"ipmi.tr13.code1", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_13_code2,
{ "2nd code",
"ipmi.tr13.code2", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_13_code3,
{ "3rd code",
"ipmi.tr13.code3", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_13_code4,
{ "4th code",
"ipmi.tr13.code4", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_13_code5,
{ "5th code",
"ipmi.tr13.code5", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_14_chan,
{ "Channel",
"ipmi.tr14.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_14_block,
{ "Block number",
"ipmi.tr14.block", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_14_data,
{ "Block data",
"ipmi.tr14.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_15_chan,
{ "Channel",
"ipmi.tr15.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_15_block,
{ "Block number",
"ipmi.tr15.block", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_15_data,
{ "Block data",
"ipmi.tr15.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_16_chan,
{ "Channel",
"ipmi.tr16.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_16_src_port,
{ "Source Port",
"ipmi.tr16.src_port", FT_UINT16, BASE_CUSTOM, ipmi_fmt_udpport, 0, NULL, HFILL }},
{ &hf_ipmi_trn_16_dst_port,
{ "Destination Port",
"ipmi.tr16.dst_port", FT_UINT16, BASE_CUSTOM, ipmi_fmt_udpport, 0, NULL, HFILL }},
{ &hf_ipmi_trn_16_src_addr,
{ "Source IP Address",
"ipmi.tr16.src_addr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_16_dst_addr,
{ "Destination IP Address",
"ipmi.tr16.dst_addr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_16_bytes,
{ "Bytes to send",
"ipmi.tr16.bytes", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_17_chan,
{ "Channel",
"ipmi.tr17.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_17_clear,
{ "Clear buffer",
"ipmi.tr17.clear", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_trn_17_block_num,
{ "Block number",
"ipmi.tr17.block_num", FT_UINT8, BASE_CUSTOM, tr17_fmt_blockno, 0x7f, NULL, HFILL }},
{ &hf_ipmi_trn_17_size,
{ "Number of received bytes",
"ipmi.tr17.size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_17_data,
{ "Block Data",
"ipmi.tr17.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_18_state,
{ "Session state",
"ipmi.tr18.state", FT_UINT8, BASE_HEX, vals_18_state, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_18_ipmi_ver,
{ "IPMI Version",
"ipmi.tr18.ipmi_ver", FT_UINT8, BASE_CUSTOM, ipmi_fmt_version, 0, NULL, HFILL }},
{ &hf_ipmi_trn_19_chan,
{ "Channel",
"ipmi.tr19.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_19_dest_sel,
{ "Destination selector",
"ipmi.tr19.dest_sel", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_XX_cap_cbcp,
{ "CBCP callback",
"ipmi.trXX.cap_cbcp", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_XX_cap_ipmi,
{ "IPMI callback",
"ipmi.trXX.cap_ipmi", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_XX_cbcp_from_list,
{ "Callback to one from list of numbers",
"ipmi.trXX.cbcp_from_list", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }},
{ &hf_ipmi_trn_XX_cbcp_user,
{ "Callback to user-specified number",
"ipmi.trXX.cbcp_user", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_trn_XX_cbcp_prespec,
{ "Callback to pre-specified number",
"ipmi.trXX.cbcp_prespec", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_trn_XX_cbcp_nocb,
{ "No callback",
"ipmi.trXX.cbcp_nocb", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_trn_XX_dst1,
{ "Callback destination 1",
"ipmi.trXX.dst1", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_XX_dst2,
{ "Callback destination 2",
"ipmi.trXX.dst2", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_XX_dst3,
{ "Callback destination 3",
"ipmi.trXX.dst3", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_trn_1a_user,
{ "User ID",
"ipmi.tr1a.user", FT_UINT8, BASE_DEC, NULL, 0x3f, NULL, HFILL }},
{ &hf_ipmi_trn_1a_chan,
{ "Channel",
"ipmi.tr1a.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
{ &hf_ipmi_trn_1b_user,
{ "User ID",
"ipmi.tr1b.user", FT_UINT8, BASE_DEC, NULL, 0x3f, NULL, HFILL }},
{ &hf_ipmi_trn_1b_chan,
{ "Channel",
"ipmi.tr1b.chan", FT_UINT8, BASE_CUSTOM, ipmi_fmt_channel, 0x0f, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipmi_trn_lan00_byte1,
&ett_ipmi_trn_lan01_byte1,
&ett_ipmi_trn_lan02_byte1,
&ett_ipmi_trn_lan02_byte2,
&ett_ipmi_trn_lan02_byte3,
&ett_ipmi_trn_lan02_byte4,
&ett_ipmi_trn_lan02_byte5,
&ett_ipmi_trn_lan04_byte1,
&ett_ipmi_trn_lan07_byte2,
&ett_ipmi_trn_lan07_byte3,
&ett_ipmi_trn_lan10_byte1,
&ett_ipmi_trn_lan17_byte1,
&ett_ipmi_trn_lan18_byte1,
&ett_ipmi_trn_lan18_byte2,
&ett_ipmi_trn_lan18_byte4,
&ett_ipmi_trn_lan19_byte1,
&ett_ipmi_trn_lan19_byte2,
&ett_ipmi_trn_lan19_byte3,
&ett_ipmi_trn_lan20_byte12,
&ett_ipmi_trn_lan21_byte1,
&ett_ipmi_trn_lan22_byte1,
&ett_ipmi_trn_lan24_byte1,
&ett_ipmi_trn_lan24_byte2,
&ett_ipmi_trn_lan24_byte3,
&ett_ipmi_trn_lan24_byte4,
&ett_ipmi_trn_lan24_byte5,
&ett_ipmi_trn_lan24_byte6,
&ett_ipmi_trn_lan24_byte7,
&ett_ipmi_trn_lan24_byte8,
&ett_ipmi_trn_lan25_byte1,
&ett_ipmi_trn_lan25_byte2,
&ett_ipmi_trn_lan25_byte34,
&ett_ipmi_trn_serial03_byte1,
&ett_ipmi_trn_serial04_byte1,
&ett_ipmi_trn_serial05_byte1,
&ett_ipmi_trn_serial05_byte2,
&ett_ipmi_trn_serial06_byte1,
&ett_ipmi_trn_serial07_byte1,
&ett_ipmi_trn_serial07_byte2,
&ett_ipmi_trn_serial08_byte1,
&ett_ipmi_trn_serial08_byte2,
&ett_ipmi_trn_serial09_byte1,
&ett_ipmi_trn_serial09_byte2,
&ett_ipmi_trn_serial16_byte1,
&ett_ipmi_trn_serial17_byte1,
&ett_ipmi_trn_serial17_byte2,
&ett_ipmi_trn_serial17_byte4,
&ett_ipmi_trn_serial17_byte5,
&ett_ipmi_trn_serial19_byte1,
&ett_ipmi_trn_serial19_byte2,
&ett_ipmi_trn_serial19_byte3,
&ett_ipmi_trn_serial20_byte1,
&ett_ipmi_trn_serial21_byte1,
&ett_ipmi_trn_serial22_byte1,
&ett_ipmi_trn_serial23_byte1,
&ett_ipmi_trn_serial24_byte1,
&ett_ipmi_trn_serial25_byte2,
&ett_ipmi_trn_serial28_byte1,
&ett_ipmi_trn_serial28_byte2,
&ett_ipmi_trn_serial28_byte10,
&ett_ipmi_trn_serial28_byte11,
&ett_ipmi_trn_serial28_byte12,
&ett_ipmi_trn_serial28_byte13,
&ett_ipmi_trn_serial28_byte14,
&ett_ipmi_trn_serial29_byte1,
&ett_ipmi_trn_serial29_byte2,
&ett_ipmi_trn_serial30_byte1,
&ett_ipmi_trn_serial30_byte2,
&ett_ipmi_trn_serial30_byte3,
&ett_ipmi_trn_serial33_byte1,
&ett_ipmi_trn_serial37_byte1,
&ett_ipmi_trn_serial43_byte1,
&ett_ipmi_trn_serial50_byte1,
&ett_ipmi_trn_serial51_byte2,
&ett_ipmi_trn_serial51_byte3,
&ett_ipmi_trn_01_byte1,
&ett_ipmi_trn_02_byte1,
&ett_ipmi_trn_02_rev,
&ett_ipmi_trn_03_rq_byte1,
&ett_ipmi_trn_03_rq_byte2,
&ett_ipmi_trn_03_rs_byte1,
&ett_ipmi_trn_04_byte1,
&ett_ipmi_trn_04_byte2,
&ett_ipmi_trn_10_byte1,
&ett_ipmi_trn_11_byte1,
&ett_ipmi_trn_11_rev,
&ett_ipmi_trn_12_rq_byte1,
&ett_ipmi_trn_12_rq_byte2,
&ett_ipmi_trn_12_rs_byte1,
&ett_ipmi_trn_13_byte1,
&ett_ipmi_trn_14_byte1,
&ett_ipmi_trn_15_byte1,
&ett_ipmi_trn_16_byte1,
&ett_ipmi_trn_17_byte1,
&ett_ipmi_trn_17_byte2,
&ett_ipmi_trn_18_byte1,
&ett_ipmi_trn_19_byte1,
&ett_ipmi_trn_19_byte2,
&ett_ipmi_trn_XX_usercap,
&ett_ipmi_trn_XX_cbcp,
&ett_ipmi_trn_1a_byte1,
&ett_ipmi_trn_1a_byte2,
&ett_ipmi_trn_1b_byte1,
&ett_ipmi_trn_1b_byte2,
};
proto_register_field_array(proto_ipmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ipmi_register_netfn_cmdtab(IPMI_TRANSPORT_REQ, IPMI_OEM_NONE, NULL, 0, NULL,
cmd_transport, array_length(cmd_transport));
}
