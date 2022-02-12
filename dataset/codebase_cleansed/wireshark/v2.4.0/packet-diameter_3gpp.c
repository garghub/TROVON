static int
dissect_diameter_3gpp_imsi_mnc_mcc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint32 str_len;
str_len = tvb_reported_length(tvb);
dissect_e212_mcc_mnc_in_utf8_address(tvb, pinfo, tree, 0);
return str_len;
}
static int
dissect_diameter_3gpp_sgsn_ipv6_address(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (tvb_reported_length(tvb) == 4)
return 4;
return dissect_diameter_3gpp_ipv6addr(tvb, pinfo, tree, data);
}
static int
dissect_diameter_3gpp_sgsn_mnc_mcc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint32 str_len;
str_len = tvb_reported_length(tvb);
dissect_e212_mcc_mnc_in_utf8_address(tvb, pinfo, tree, 0);
return str_len;
}
static int
dissect_diameter_3gpp_imeisv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
if (tree){
for (i = 0; i < length; i++)
if (!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item_ret_string(tree, hf_diameter_3gpp_imeisv, tvb, offset, length,
ENC_UTF_8 | ENC_NA, wmem_packet_scope(), (const guint8**)&diam_sub_dis->avp_str);
PROTO_ITEM_SET_GENERATED(item);
}
return length;
}
static int
dissect_diameter_3gpp_rat_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
int length = tvb_reported_length(tvb);
proto_tree_add_item(tree, hf_diameter_3gpp_rat_type, tvb, offset, 1, ENC_BIG_ENDIAN);
return length;
}
static int
dissect_diameter_3gpp_ms_timezone(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
int offset = 0;
guint8 oct, hours, minutes;
char sign;
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
oct = tvb_get_guint8(tvb, offset);
sign = (oct & 0x08) ? '-' : '+';
oct = (oct >> 4) + (oct & 0x07) * 10;
hours = oct / 4;
minutes = oct % 4 * 15;
proto_tree_add_uint_format_value(tree, hf_diameter_3gpp_timezone, tvb, offset, 1, oct, "GMT %c %d hours %d minutes", sign, hours, minutes);
offset++;
oct = tvb_get_guint8(tvb, offset) & 0x3;
proto_tree_add_item(tree, hf_diameter_3gpp_timezone_adjustment, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
diam_sub_dis->avp_str = wmem_strdup_printf(wmem_packet_scope(), "Timezone: GMT %c %d hours %d minutes %s",
sign,
hours,
minutes,
val_to_str_const(oct, daylight_saving_time_vals, "Unknown"));
return offset;
}
static int
dissect_diameter_3gpp_twan_identifier(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int length = tvb_reported_length(tvb);
dissect_gtpv2_twan_identifier(tvb, pinfo, tree, NULL, length, 0, 0, NULL);
return length;
}
static int
dissect_diameter_3gpp_af_application_identifier(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
if (tree){
for (i = 0; i < length; i++)
if (!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item_ret_string(tree, hf_diameter_3gpp_af_application_identifier, tvb, offset, length,
ENC_UTF_8 | ENC_NA, wmem_packet_scope(), (const guint8**)&diam_sub_dis->avp_str);
PROTO_ITEM_SET_GENERATED(item);
}
return length;
}
static int
dissect_diameter_3gpp_af_charging_identifier(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
if (tree){
for (i = 0; i < length; i++)
if (!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item_ret_string(tree, hf_diameter_3gpp_af_charging_identifier, tvb, offset, length,
ENC_UTF_8 | ENC_NA, wmem_packet_scope(), (const guint8**)&diam_sub_dis->avp_str);
PROTO_ITEM_SET_GENERATED(item);
}
return length;
}
static int
dissect_diameter_3gpp_visited_nw_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
for(i = 0; i < length; i++)
if(!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item(tree, hf_diameter_3gpp_visited_nw_id, tvb, offset, length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
return length;
}
static int
dissect_diameter_3gpp_public_identity(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int length = tvb_reported_length(tvb);
dfilter_store_sip_from_addr(tvb, tree, 0, length);
return length;
}
static int
dissect_diameter_3gpp_feature_list_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
diam_sub_dis_t *diam_sub_dis_inf = (diam_sub_dis_t*)data;
if(diam_sub_dis_inf) {
diam_sub_dis_inf->feature_list_id = tvb_get_ntohl(tvb,0);
}
return 4;
}
static int
dissect_diameter_3gpp_uar_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
const int *flags[] = {
&hf_diameter_3gpp_uar_flags_flags_spare_bits,
&hf_diameter_3gpp_uar_flags_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_uar_flags_flags, diameter_3gpp_uar_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_feature_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
int offset = 0;
guint32 application_id = 0, feature_list_id = 0;
diam_sub_dis_t *diam_sub_dis_inf = (diam_sub_dis_t*)data;
if(diam_sub_dis_inf) {
application_id = diam_sub_dis_inf->application_id;
feature_list_id = diam_sub_dis_inf->feature_list_id;
}
switch (application_id) {
case DIAM_APPID_3GPP_CX:
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_diameter_3gpp_cx_feature_list_flags,
diameter_3gpp_feature_list_ett, diameter_3gpp_cx_feature_list_1_fields, ENC_BIG_ENDIAN, BMT_NO_APPEND);
break;
case DIAM_APPID_3GPP_RX:
{
if (feature_list_id == 1) {
const int *flags[] = {
&hf_diameter_3gpp_feature_list1_rx_flags_spare_bits,
&hf_diameter_3gpp_feature_list1_rx_flags_bit18,
&hf_diameter_3gpp_feature_list1_rx_flags_bit17,
&hf_diameter_3gpp_feature_list1_rx_flags_bit16,
&hf_diameter_3gpp_feature_list1_rx_flags_bit15,
&hf_diameter_3gpp_feature_list1_rx_flags_bit14,
&hf_diameter_3gpp_feature_list1_rx_flags_bit13,
&hf_diameter_3gpp_feature_list1_rx_flags_bit12,
&hf_diameter_3gpp_feature_list1_rx_flags_bit11,
&hf_diameter_3gpp_feature_list1_rx_flags_bit10,
&hf_diameter_3gpp_feature_list1_rx_flags_bit9,
&hf_diameter_3gpp_feature_list1_rx_flags_bit8,
&hf_diameter_3gpp_feature_list1_rx_flags_bit7,
&hf_diameter_3gpp_feature_list1_rx_flags_bit6,
&hf_diameter_3gpp_feature_list1_rx_flags_bit5,
&hf_diameter_3gpp_feature_list1_rx_flags_bit4,
&hf_diameter_3gpp_feature_list1_rx_flags_bit3,
&hf_diameter_3gpp_feature_list1_rx_flags_bit2,
&hf_diameter_3gpp_feature_list1_rx_flags_bit1,
&hf_diameter_3gpp_feature_list1_rx_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_diameter_3gpp_feature_list_flags, diameter_3gpp_feature_list_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
}
else if (feature_list_id == 2) {
const int *flags[] = {
&hf_diameter_3gpp_feature_list2_rx_flags_spare_bits,
&hf_diameter_3gpp_feature_list2_rx_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_diameter_3gpp_feature_list_flags, diameter_3gpp_feature_list_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
}
}
break;
case DIAM_APPID_3GPP_SH:
{
const int *flags[] = {
&hf_diameter_3gpp_feature_list1_sh_flags_spare_bits,
&hf_diameter_3gpp_feature_list1_sh_flags_bit3,
&hf_diameter_3gpp_feature_list1_sh_flags_bit2,
&hf_diameter_3gpp_feature_list1_sh_flags_bit1,
&hf_diameter_3gpp_feature_list1_sh_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_diameter_3gpp_feature_list_flags, diameter_3gpp_feature_list_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
}
break;
case DIAM_APPID_3GPP_S6A_S6D:
if (feature_list_id == 1) {
const int *flags[] = {
&hf_diameter_3gpp_feature_list1_s6a_flags_bit31,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit30,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit29,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit28,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit27,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit26,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit25,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit24,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit23,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit22,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit21,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit20,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit19,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit18,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit17,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit16,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit15,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit14,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit13,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit12,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit11,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit10,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit9,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit8,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit7,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit6,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit5,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit4,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit3,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit2,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit1,
&hf_diameter_3gpp_feature_list1_s6a_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_diameter_3gpp_feature_list_flags, diameter_3gpp_feature_list_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
}
else if (feature_list_id == 2) {
const int *flags[] = {
&hf_diameter_3gpp_feature_list2_s6a_flags_spare_bits,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit17,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit16,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit15,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit14,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit13,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit12,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit11,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit10,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit9,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit8,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit7,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit6,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit5,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit4,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit3,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit2,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit1,
&hf_diameter_3gpp_feature_list2_s6a_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_diameter_3gpp_feature_list_flags, diameter_3gpp_feature_list_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
}
break;
case DIAM_APPID_3GPP_GX:
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_feature_list_gx_flags,
diameter_3gpp_feature_list_ett, diameter_3gpp_gx_feature_list_1_fields, ENC_BIG_ENDIAN, BMT_NO_APPEND);
break;
case DIAM_APPID_3GPP_SD:
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_feature_list_sd_flags,
diameter_3gpp_feature_list_ett, diameter_3gpp_sd_feature_list_fields, ENC_BIG_ENDIAN, BMT_NO_APPEND);
break;
default:
break;
}
return 4;
}
static int
dissect_diameter_3gpp_path(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *sub_tree;
int offset = 0, comma_offset;
int end_offset = tvb_reported_length(tvb) - 1;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, diameter_3gpp_path_ett, NULL, "Paths");
while (offset < end_offset) {
comma_offset = tvb_find_guint8(tvb, offset, -1, ',');
if(comma_offset == -1) {
proto_tree_add_item(sub_tree, hf_diameter_3gpp_path, tvb, offset, comma_offset, ENC_ASCII|ENC_NA);
return end_offset;
}
proto_tree_add_item(sub_tree, hf_diameter_3gpp_path, tvb, offset, comma_offset, ENC_ASCII|ENC_NA);
offset = comma_offset+1;
}
return tvb_reported_length(tvb);
}
static int
dissect_diameter_3gpp_contact(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *item;
int offset = 0;
item = proto_tree_add_item(tree, hf_diameter_3gpp_contact, tvb, offset, -1, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
return tvb_reported_length(tvb);
}
static int
dissect_diameter_3gpp_msisdn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
int length = tvb_reported_length(tvb);
dissect_e164_msisdn(tvb, tree, offset, length, E164_ENC_BCD);
return length;
}
static int
dissect_diameter_3gpp_sar_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_sar_flags,
diameter_3gpp_sar_flags_ett, diameter_3gpp_sar_fields, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_user_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int length = tvb_reported_length(tvb);
if(length < 38)
return length;
if (tvb_strncaseeql(tvb, 0, "<?xml", 5) == 0) {
call_dissector(xml_handle, tvb, pinfo, tree);
}
return length;
}
static int
dissect_diameter_3gpp_service_ind(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
for(i = 0; i < length; i++)
if(!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item(tree, hf_diameter_3gpp_service_ind, tvb, offset, length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
return length;
}
static int
dissect_diameter_3gpp_tmgi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_tree *sub_tree;
int offset = 0;
item = proto_tree_add_item(tree, hf_diameter_3gpp_tmgi, tvb, offset, 6, ENC_NA);
sub_tree = proto_item_add_subtree(item,diameter_3gpp_tmgi_ett);
proto_tree_add_item(sub_tree, hf_diameter_mbms_service_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset = offset+3;
offset = dissect_e212_mcc_mnc(tvb, pinfo, sub_tree, offset, E212_NONE, TRUE);
return offset;
}
static int
dissect_diameter_3gpp_ipv6addr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_ipv6addr, tvb, offset, 16, ENC_NA);
offset += 16;
return offset;
}
static int
dissect_diameter_3gpp_ipaddr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_ipaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_diameter_3gpp_rai(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
guint length;
length = tvb_reported_length(tvb);
if(length==12) {
diam_sub_dis->avp_str = wmem_strdup_printf(wmem_packet_scope(), "MCC %s, MNC %s, LAC 0x%s, RAC 0x%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, 0, 3, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb, 3, 3, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb, 6, 4, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb, 10, 2, ENC_UTF_8|ENC_NA)
);
} else {
diam_sub_dis->avp_str = wmem_strdup_printf(wmem_packet_scope(), "MCC %s, MNC %s, LAC 0x%s, RAC 0x%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, 0, 3, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb, 3, 2, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb, 5, 4, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb, 9, 2, ENC_UTF_8|ENC_NA)
);
}
return length;
}
static int
dissect_diameter_3gpp_mbms_required_qos(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
guint length;
proto_tree_add_item(tree, hf_diameter_3gpp_mbms_required_qos_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_reported_length(tvb) - 1;
de_sm_qos(tvb, tree, pinfo, offset,length, NULL, 0);
return offset+length;
}
static int
dissect_diameter_3gpp_udp_port(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_udp_port, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
const gchar *time_str;
time_str = tvb_ntp_fmt_ts(tvb, offset);
proto_tree_add_string(tree, hf_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer, tvb, offset, 8, time_str);
offset+=8;
return offset;
}
static int
dissect_diameter_3gpp_charging_rule_name(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
if (tree){
for (i = 0; i < length; i++)
if (!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item_ret_string(tree, hf_diameter_3gpp_charging_rule_name, tvb, offset, length,
ENC_UTF_8 | ENC_NA, wmem_packet_scope(), (const guint8**)&diam_sub_dis->avp_str);
PROTO_ITEM_SET_GENERATED(item);
}
return length;
}
static int
dissect_diameter_3gpp_monitoring_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *item;
int offset = 0, i;
int length = tvb_reported_length(tvb);
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
if (tree){
for (i = 0; i < length; i++)
if (!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item_ret_string(tree, hf_diameter_3gpp_monitoring_key, tvb, offset, length,
ENC_UTF_8 | ENC_NA, wmem_packet_scope(), (const guint8**)&diam_sub_dis->avp_str);
PROTO_ITEM_SET_GENERATED(item);
}
return length;
}
static int
dissect_diameter_3gpp_credit_management_status(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_cms_spare_bits,
&hf_diameter_3gpp_cms_no_gyn_session_serv_not_allowed,
&hf_diameter_3gpp_cms_no_gyn_session_serv_allowed,
&hf_diameter_3gpp_cms_rating_failed,
&hf_diameter_3gpp_cms_user_unknown,
&hf_diameter_3gpp_cms_auth_rej,
&hf_diameter_3gpp_cms_credit_ctrl_not_applicable,
&hf_diameter_3gpp_cms_end_user_serv_status,
NULL
};
proto_tree *subtree = proto_tree_add_subtree(tree, tvb, 0, 4, diameter_3gpp_cms_ett, NULL, "Credit-Management-Status bit mask");
proto_tree_add_bitmask_list(subtree, tvb, 0, 4, flags, ENC_BIG_ENDIAN);
return 4;
}
static int
dissect_diameter_3gpp_location_estimate(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
dissect_geographical_description(tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
static guint32
qos_calc_bitrate(guint8 oct)
{
if (oct <= 0x3f)
return oct;
if (oct <= 0x7f)
return 64 + (oct - 0x40) * 8;
return 576 + (oct - 0x80) * 64;
}
static guint32
qos_calc_ext_bitrate(guint8 oct)
{
if (oct <= 0x4a)
return 8600 + oct * 100;
if (oct <= 0xba)
return 16000 + (oct - 0x4a) * 1000;
return 128000 + (oct - 0xba) * 2000;
}
static int
dissect_diameter_3ggp_qos_susbscribed(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
guint offset = 0;
guint length = tvb_reported_length(tvb);
proto_tree *subtree;
proto_item *item;
guchar oct, tmp_oct;
const gchar *str;
guint32 tmp32;
item = proto_tree_add_item(tree, hf_diameter_3gpp_qos_subscribed, tvb, offset, length, ENC_NA);
subtree = proto_item_add_subtree(item, diameter_3gpp_qos_subscribed_ett);
if (length >= 3) {
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_reliability_cls, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_delay_cls, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_diameter_3gpp_spare_bits, tvb, offset << 3, 2, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_prec_class, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_diameter_3gpp_spare_bits, tvb, (offset << 3) + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_peak_thr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_mean_thr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_diameter_3gpp_spare_bits, tvb, (offset << 3), 3, ENC_BIG_ENDIAN);
offset += 1;
}
if (length >= 4) {
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_al_ret_priority, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (length >= 5) {
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_del_of_err_sdu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_del_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_traffic_cls, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (length >= 6) {
oct = tvb_get_guint8(tvb, offset);
switch (oct) {
case 0x00: str = "Subscribed maximum SDU size (MS to net); Reserved (net to MS)"; break;
case 0x97: str = "1502 octets"; break;
case 0x98: str = "1510 octets"; break;
case 0x99: str = "1520 octets"; break;
case 0xff: str = "Reserved"; break;
default: str = "Unspecified/Reserved";
}
if ((oct >= 1) && (oct <= 0x96))
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_maximum_sdu_size, tvb, offset, 1, oct, "%u octets (%u)", oct * 10, oct);
else
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_maximum_sdu_size, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 7) {
oct = tvb_get_guint8(tvb, offset);
switch (oct) {
case 0x00: str = "Subscribed maximum bit rate for uplink (MS to net); Reserved (net to MS)"; break;
case 0xfe: str = "8640 kbps; Check extended"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_max_bitrate_upl, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 8) {
oct = tvb_get_guint8(tvb, offset);
switch (oct) {
case 0x00: str = "Subscribed maximum bit rate for downlink (MS to net); Reserved (net to MS)"; break;
case 0xfe: str = "8640 kbps; Check extended"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_max_bitrate_downl, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 9) {
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_sdu_err_rat, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_ber, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (length >= 10) {
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_traff_hdl_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, offset);
tmp_oct = oct >> 2;
switch (tmp_oct) {
case 0x00: str = "Subscribed transfer delay (MS to net); Reserved (net to MS)"; break;
case 0x3f: str = "Reserved"; break;
default:
if (oct <= 0x0f)
tmp32 = tmp_oct * 10;
else if (oct <= 0x1f)
tmp32 = (tmp_oct - 0x10) * 50 + 200;
else
tmp32 = (tmp_oct - 0x20) * 100 + 1000;
str = wmem_strdup_printf(wmem_packet_scope(), "%u ms", tmp32);
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_trans_delay, tvb, offset, 1, oct, "%s (%u)", str, tmp_oct);
offset += 1;
}
if (length >= 11) {
oct = tvb_get_guint8(tvb, offset);
switch (oct) {
case 0x00: str = "Subscribed guaranteed bit rate for uplink (MS to net); Reserved (net to MS)"; break;
case 0xfe: str = "8640 kbps; Check extended"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_guar_bitrate_upl, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 12) {
oct = tvb_get_guint8(tvb, offset);
switch (oct) {
case 0x00: str = "Subscribed guaranteed bit rate for downlink (MS to net); Reserved (net to MS)"; break;
case 0xfe: str = "8640 kbps; Check extended"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_guar_bitrate_downl, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 13) {
oct = tvb_get_guint8(tvb, offset);
tmp_oct = oct & 0x0f;
if (tmp_oct == 0x01)
str = "speech (MS to net); spare bits (net to MS)";
else
str = "unknown (MS to net); spare bits (net to MS)";
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_source_stat_desc, tvb, offset, 1, oct, "%s (%u)", str, tmp_oct);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_signalling_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_diameter_3gpp_spare_bits, tvb, (offset << 3), 3, ENC_BIG_ENDIAN);
offset += 1;
}
if (length >= 14) {
oct = tvb_get_guint8(tvb, offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for downlink";
else if (oct > 0xfa)
str = "undefined";
else if (oct == 0xfa)
str = "256 Mbps; Check extended 2";
else {
tmp32 = qos_calc_ext_bitrate(oct);
if (oct >= 0x4a)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", tmp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", tmp32);
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_max_bitrate_downl_ext, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 15) {
oct = tvb_get_guint8(tvb, offset);
if (oct == 0x00)
str = "Use the value indicated by the Guaranteed bit rate for downlink";
else if (oct > 0xfa)
str = "undefined";
else if (oct == 0xfa)
str = "256 Mbps; Check extended 2";
else {
tmp32 = qos_calc_ext_bitrate(oct);
if (oct >= 0x4a)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", tmp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", tmp32);
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_guar_bitrate_downl_ext, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 16) {
oct = tvb_get_guint8(tvb, offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for uplink";
else if (oct > 0xfa)
str = "undefined";
else if (oct == 0xfa)
str = "256 Mbps; Check extended 2";
else {
tmp32 = qos_calc_ext_bitrate(oct);
if (oct >= 0x4a)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", tmp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", tmp32);
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_max_bitrate_upl_ext, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 17) {
oct = tvb_get_guint8(tvb, offset);
if (oct == 0x00)
str = "Use the value indicated by the Guaranteed bit rate for uplink";
else if (oct > 0xfa)
str = "undefined";
else if (oct == 0xfa)
str = "256 Mbps; Check extended 2";
else {
tmp32 = qos_calc_ext_bitrate(oct);
if (oct >= 0x4a)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", tmp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", tmp32);
}
proto_tree_add_uint_format_value(subtree, hf_diameter_3gpp_qos_guar_bitrate_upl_ext, tvb, offset, 1, oct, "%s (%u)", str, oct);
offset += 1;
}
if (length >= 18) {
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_pre_emption_vulnerability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_diameter_3gpp_spare_bits, tvb, (offset << 3) + 6 , 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_priority_level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_diameter_3gpp_qos_pre_emption_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_diameter_3gpp_spare_bits, tvb, (offset << 3), 1, ENC_BIG_ENDIAN);
}
return length;
}
static int
dissect_diameter_3gpp_ulr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_ulr_flags_spare_bits,
&hf_diameter_3gpp_ulr_flags_bit7,
&hf_diameter_3gpp_ulr_flags_bit6,
&hf_diameter_3gpp_ulr_flags_bit5,
&hf_diameter_3gpp_ulr_flags_bit4,
&hf_diameter_3gpp_ulr_flags_bit3,
&hf_diameter_3gpp_ulr_flags_bit2,
&hf_diameter_3gpp_ulr_flags_bit1,
&hf_diameter_3gpp_ulr_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_ulr_flags, diameter_3gpp_ulr_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_ula_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_ula_flags_spare_bits,
&hf_diameter_3gpp_ula_flags_bit1,
&hf_diameter_3gpp_ula_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_ula_flags, diameter_3gpp_ula_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_visited_plmn_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
int length = tvb_reported_length(tvb);
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
if (length == 3) {
diam_sub_dis->avp_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, 0, E212_NONE, TRUE);
} else {
proto_tree_add_expert(tree, pinfo, &ei_diameter_3gpp_plmn_id_wrong_len, tvb, 0, length);
}
return length;
}
static int
dissect_diameter_3gpp_dsr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_dsr_flags_spare_bits,
&hf_diameter_3gpp_dsr_flags_bit18,
&hf_diameter_3gpp_dsr_flags_bit17,
&hf_diameter_3gpp_dsr_flags_bit16,
&hf_diameter_3gpp_dsr_flags_bit15,
&hf_diameter_3gpp_dsr_flags_bit14,
&hf_diameter_3gpp_dsr_flags_bit13,
&hf_diameter_3gpp_dsr_flags_bit12,
&hf_diameter_3gpp_dsr_flags_bit11,
&hf_diameter_3gpp_dsr_flags_bit10,
&hf_diameter_3gpp_dsr_flags_bit9,
&hf_diameter_3gpp_dsr_flags_bit8,
&hf_diameter_3gpp_dsr_flags_bit7,
&hf_diameter_3gpp_dsr_flags_bit6,
&hf_diameter_3gpp_dsr_flags_bit5,
&hf_diameter_3gpp_dsr_flags_bit4,
&hf_diameter_3gpp_dsr_flags_bit3,
&hf_diameter_3gpp_dsr_flags_bit2,
&hf_diameter_3gpp_dsr_flags_bit1,
&hf_diameter_3gpp_dsr_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_dsr_flags, diameter_3gpp_dsr_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_dsa_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_dsa_flags_spare_bits,
&hf_diameter_3gpp_dsa_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_dsa_flags, diameter_3gpp_dsa_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_acc_res_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_acc_res_dat_flags_spare_bits,
&hf_diameter_3gpp_acc_res_dat_flags_bit6,
&hf_diameter_3gpp_acc_res_dat_flags_bit5,
&hf_diameter_3gpp_acc_res_dat_flags_bit4,
&hf_diameter_3gpp_acc_res_dat_flags_bit3,
&hf_diameter_3gpp_acc_res_dat_flags_bit2,
&hf_diameter_3gpp_acc_res_dat_flags_bit1,
&hf_diameter_3gpp_acc_res_dat_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_acc_res_dat_flags, diameter_3gpp_dsa_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_ida_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_ida_flags_spare_bits,
&hf_diameter_3gpp_ida_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_ida_flags, diameter_3gpp_ida_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_pua_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_pua_flags_spare_bits,
&hf_diameter_3gpp_pua_flags_bit1,
&hf_diameter_3gpp_pua_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_pua_flags, diameter_3gpp_pua_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_nor_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_nor_flags_spare_bits,
&hf_diameter_3gpp_nor_flags_bit9,
&hf_diameter_3gpp_nor_flags_bit8,
&hf_diameter_3gpp_nor_flags_bit7,
&hf_diameter_3gpp_nor_flags_bit6,
&hf_diameter_3gpp_nor_flags_bit5,
&hf_diameter_3gpp_nor_flags_bit4,
&hf_diameter_3gpp_nor_flags_bit3,
&hf_diameter_3gpp_nor_flags_bit2,
&hf_diameter_3gpp_nor_flags_bit1,
&hf_diameter_3gpp_nor_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_nor_flags, diameter_3gpp_nor_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_idr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_idr_flags_spare_bits,
&hf_diameter_3gpp_idr_flags_bit8,
&hf_diameter_3gpp_idr_flags_bit7,
&hf_diameter_3gpp_idr_flags_bit6,
&hf_diameter_3gpp_idr_flags_bit5,
&hf_diameter_3gpp_idr_flags_bit4,
&hf_diameter_3gpp_idr_flags_bit3,
&hf_diameter_3gpp_idr_flags_bit2,
&hf_diameter_3gpp_idr_flags_bit1,
&hf_diameter_3gpp_idr_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_idr_flags, diameter_3gpp_idr_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_ppr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_ppr_flags_spare_bits,
&hf_diameter_3gpp_ppr_flags_bit3,
&hf_diameter_3gpp_ppr_flags_bit2,
&hf_diameter_3gpp_ppr_flags_bit1,
&hf_diameter_3gpp_ppr_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_ppr_flags, diameter_3gpp_ppr_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_aaa_fail_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_aaa_fail_flags_spare_bits,
&hf_diameter_3gpp_aaa_fail_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_aaa_fail_flags, diameter_3gpp_aaa_fail_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_der_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_der_flags_spare_bits,
&hf_diameter_3gpp_der_flags_bit1,
&hf_diameter_3gpp_der_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_der_flags, diameter_3gpp_der_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_dea_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_dea_flags_spare_bits,
&hf_diameter_3gpp_dea_flags_bit1,
&hf_diameter_3gpp_dea_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_dea_flags, diameter_3gpp_dea_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_rar_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_rar_flags_spare_bits,
&hf_diameter_3gpp_rar_flags_bit1,
&hf_diameter_3gpp_rar_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_rar_flags, diameter_3gpp_rar_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_der_s6b_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_der_s6b_flags_spare_bits,
&hf_diameter_3gpp_der_s6b_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_der_s6b_flags, diameter_3gpp_der_s6b_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_emergency_services(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_emergency_services_flags_spare_bits,
&hf_diameter_3gpp_emergency_services_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_emergency_services_flags, diameter_3gpp_emergency_services_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_air_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_air_flags_spare_bits,
&hf_diameter_3gpp_air_flags_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_air_flags, diameter_3gpp_air_flags_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_eutran_positioning_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
return dissect_lcsap_Positioning_Data_PDU(tvb, pinfo, tree, NULL);
}
static int
dissect_diameter_3gpp_ran_nas_release_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
int length = tvb_reported_length(tvb);
guint8 octet = tvb_get_guint8(tvb, offset);
guint8 proto_type = (octet >> 4);
int cause_type = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_ran_nas_protocol_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (proto_type == 1) {
proto_tree_add_item(tree, hf_diameter_3gpp_ran_nas_cause_type, tvb, offset, 1, ENC_BIG_ENDIAN);
cause_type = octet & 0x0F;
}
offset += 1;
switch (proto_type) {
case 1:
switch (cause_type) {
case 0:
proto_tree_add_item(tree, hf_diameter_3gpp_s1ap_radio_network, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(tree, hf_diameter_3gpp_s1ap_transport, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_diameter_3gpp_s1ap_nas, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_item(tree, hf_diameter_3gpp_s1ap_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 4:
proto_tree_add_item(tree, hf_diameter_3gpp_s1ap_misc, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_diameter_3gpp_ran_nas_cause_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
break;
case 2:
proto_tree_add_item(tree, hf_diameter_3gpp_emm_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 3:
proto_tree_add_item(tree, hf_diameter_3gpp_esm_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 4:
proto_tree_add_item(tree, hf_diameter_3gpp_diameter_cause, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 5:
proto_tree_add_item(tree, hf_diameter_3gpp_ikev2_cause, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
default:
proto_tree_add_item(tree, hf_diameter_3gpp_ran_nas_cause_value, tvb, offset, length - offset, ENC_BIG_ENDIAN);
offset += (length - offset);
break;
}
return offset;
}
static int
dissect_diameter_3gpp_mbms_bearer_event(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_mbms_bearer_event_spare_bits,
&hf_diameter_3gpp_mbms_bearer_event_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_mbms_bearer_event, diameter_3gpp_mbms_bearer_event_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_mbms_bearer_result(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_mbms_bearer_result_spare_bits,
&hf_diameter_3gpp_mbms_bearer_result_bit11,
&hf_diameter_3gpp_mbms_bearer_result_bit10,
&hf_diameter_3gpp_mbms_bearer_result_bit9,
&hf_diameter_3gpp_mbms_bearer_result_bit8,
&hf_diameter_3gpp_mbms_bearer_result_bit7,
&hf_diameter_3gpp_mbms_bearer_result_bit6,
&hf_diameter_3gpp_mbms_bearer_result_bit5,
&hf_diameter_3gpp_mbms_bearer_result_bit4,
&hf_diameter_3gpp_mbms_bearer_result_bit3,
&hf_diameter_3gpp_mbms_bearer_result_bit2,
&hf_diameter_3gpp_mbms_bearer_result_bit1,
&hf_diameter_3gpp_mbms_bearer_result_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_mbms_bearer_result, diameter_3gpp_mbms_bearer_result_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_tmgi_allocation_result(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_tmgi_allocation_result_spare_bits,
&hf_diameter_3gpp_tmgi_allocation_result_bit4,
&hf_diameter_3gpp_tmgi_allocation_result_bit3,
&hf_diameter_3gpp_tmgi_allocation_result_bit2,
&hf_diameter_3gpp_tmgi_allocation_result_bit1,
&hf_diameter_3gpp_tmgi_allocation_result_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_tmgi_allocation_result, diameter_3gpp_tmgi_allocation_result_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
static int
dissect_diameter_3gpp_tmgi_deallocation_result(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const int *flags[] = {
&hf_diameter_3gpp_tmgi_deallocation_result_spare_bits,
&hf_diameter_3gpp_tmgi_deallocation_result_bit2,
&hf_diameter_3gpp_tmgi_deallocation_result_bit1,
&hf_diameter_3gpp_tmgi_deallocation_result_bit0,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, 0, hf_diameter_3gpp_tmgi_deallocation_result, diameter_3gpp_tmgi_deallocation_result_ett, flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
return 4;
}
void
proto_reg_handoff_diameter_3gpp(void)
{
dissector_add_uint("diameter.3gpp", 8, create_dissector_handle(dissect_diameter_3gpp_imsi_mnc_mcc, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 15, create_dissector_handle(dissect_diameter_3gpp_sgsn_ipv6_address, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 18, create_dissector_handle(dissect_diameter_3gpp_sgsn_mnc_mcc, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 20, create_dissector_handle(dissect_diameter_3gpp_imeisv, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 21, create_dissector_handle(dissect_diameter_3gpp_rat_type, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 23, create_dissector_handle(dissect_diameter_3gpp_ms_timezone, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 29, create_dissector_handle(dissect_diameter_3gpp_twan_identifier, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 504, create_dissector_handle(dissect_diameter_3gpp_af_application_identifier, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 505, create_dissector_handle(dissect_diameter_3gpp_af_charging_identifier, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 600, create_dissector_handle(dissect_diameter_3gpp_visited_nw_id, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 601, create_dissector_handle(dissect_diameter_3gpp_public_identity, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 606, create_dissector_handle(dissect_diameter_3gpp_user_data, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 629, create_dissector_handle(dissect_diameter_3gpp_feature_list_id, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 630, create_dissector_handle(dissect_diameter_3gpp_feature_list, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 637, create_dissector_handle(dissect_diameter_3gpp_uar_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 640, create_dissector_handle(dissect_diameter_3gpp_path, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 641, create_dissector_handle(dissect_diameter_3gpp_contact, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 655, create_dissector_handle(dissect_diameter_3gpp_sar_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 701, create_dissector_handle(dissect_diameter_3gpp_msisdn, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 702, create_dissector_handle(dissect_diameter_3gpp_user_data, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 704, create_dissector_handle(dissect_diameter_3gpp_service_ind, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 900, create_dissector_handle(dissect_diameter_3gpp_tmgi, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 909, create_dissector_handle(dissect_diameter_3gpp_rai, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 913, create_dissector_handle(dissect_diameter_3gpp_mbms_required_qos, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 917, create_dissector_handle(dissect_diameter_3gpp_ipv6addr, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 918, create_dissector_handle(dissect_diameter_3gpp_ipaddr, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 926, create_dissector_handle(dissect_diameter_3gpp_udp_port, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 927, create_dissector_handle(dissect_diameter_3gpp_udp_port, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 929, create_dissector_handle(dissect_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 930, create_dissector_handle(dissect_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1005, create_dissector_handle(dissect_diameter_3gpp_charging_rule_name, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1066, create_dissector_handle(dissect_diameter_3gpp_monitoring_key, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1082, create_dissector_handle(dissect_diameter_3gpp_credit_management_status, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1242, create_dissector_handle(dissect_diameter_3gpp_location_estimate, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1404, create_dissector_handle(dissect_diameter_3ggp_qos_susbscribed, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1405, create_dissector_handle(dissect_diameter_3gpp_ulr_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1406, create_dissector_handle(dissect_diameter_3gpp_ula_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1407, create_dissector_handle(dissect_diameter_3gpp_visited_plmn_id, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1421, create_dissector_handle(dissect_diameter_3gpp_dsr_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1422, create_dissector_handle(dissect_diameter_3gpp_dsa_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1426, create_dissector_handle(dissect_diameter_3gpp_acc_res_data, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1441, create_dissector_handle(dissect_diameter_3gpp_ida_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1442, create_dissector_handle(dissect_diameter_3gpp_pua_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1443, create_dissector_handle(dissect_diameter_3gpp_nor_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1490, create_dissector_handle(dissect_diameter_3gpp_idr_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1508, create_dissector_handle(dissect_diameter_3gpp_ppr_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1518, create_dissector_handle(dissect_diameter_3gpp_aaa_fail_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1520, create_dissector_handle(dissect_diameter_3gpp_der_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1521, create_dissector_handle(dissect_diameter_3gpp_dea_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1522, create_dissector_handle(dissect_diameter_3gpp_rar_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1523, create_dissector_handle(dissect_diameter_3gpp_der_s6b_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1538, create_dissector_handle(dissect_diameter_3gpp_emergency_services, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1679, create_dissector_handle(dissect_diameter_3gpp_air_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 2516, create_dissector_handle(dissect_diameter_3gpp_eutran_positioning_data, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 2819, create_dissector_handle(dissect_diameter_3gpp_ran_nas_release_cause, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 3502, create_dissector_handle(dissect_diameter_3gpp_mbms_bearer_event, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 3506, create_dissector_handle(dissect_diameter_3gpp_mbms_bearer_result, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 3511, create_dissector_handle(dissect_diameter_3gpp_tmgi_allocation_result, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 3514, create_dissector_handle(dissect_diameter_3gpp_tmgi_deallocation_result, proto_diameter_3gpp));
xml_handle = find_dissector_add_dependency("xml", proto_diameter_3gpp);
}
void
proto_register_diameter_3gpp(void)
{
static hf_register_info hf[] = {
{ &hf_diameter_3gpp_timezone,
{ "Timezone", "diameter.3gpp.3gpp_timezone",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_timezone_adjustment,
{ "Adjustment", "diameter.3gpp.timezone_adjustment",
FT_UINT8, BASE_DEC, VALS(daylight_saving_time_vals), 0x03,
NULL, HFILL }
},
{ &hf_diameter_3gpp_rat_type,
{ "RAT Type", "diameter.3gpp.rat-type",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_rat_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_diameter_3gpp_path,
{ "Path", "diameter.3gpp.path",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_contact,
{ "Contact", "diameter.3gpp.contact",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_visited_nw_id,
{ "Visited-Network-Identifier", "diameter.3gpp.visited_nw_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_diameter_3gpp_user_data,
{ "User data", "diameter.3gpp.user_data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_diameter_3gpp_ipaddr,
{ "IPv4 Address", "diameter.3gpp.ipaddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_required_qos_prio,
{ "Allocation/Retention Priority", "diameter.3gpp.mbms_required_qos_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi,
{ "TMGI", "diameter.3gpp.tmgi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_service_ind,
{ "Service-Indication", "diameter.3gpp.service_ind",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_mbms_service_id,
{ "MBMS Service ID", "diameter.3gpp.mbms_service_id",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_spare_bits,
{ "Spare bit(s)", "diameter.3gpp.spare_bits",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_uar_flags_flags,
{ "Flags", "diameter.3gpp.uar_flags_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_uar_flags_flags_spare_bits,
{ "Spare", "diameter.3gpp.uar_flags_flags_spare_bits",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_uar_flags_flags_bit0,
{ "Emergency registration", "diameter.3gpp.uar_flags_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_flags,
{ "Feature-List Flags", "diameter.3gpp.feature_list_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cx_feature_list_flags,
{ "CX Feature-List Flags", "diameter.3gpp.cx_feature_list_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cx_feature_list_1_flags_bit0,
{ "Shared IFC Sets", "diameter.3gpp.cx_feature_list_1_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cx_feature_list_1_flags_bit1,
{ "Alias Indication", "diameter.3gpp.cx_feature_list_1_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cx_feature_list_1_flags_bit2,
{ "IMS Restoration Indication", "diameter.3gpp.cx_feature_list_1_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cx_feature_list_1_flags_bit3,
{ "P-CSCF Restoration mechanism", "diameter.3gpp.cx_feature_list_1_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cx_feature_list_1_flags_spare_bits,
{ "Spare", "diameter.3gpp.cx_feature_list_1_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xfffffff0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_sh_flags_bit0,
{ "Notif-Eff", "diameter.3gpp.feature_list1_sh_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_sh_flags_bit1,
{ "Update-Eff", "diameter.3gpp.feature_list1_sh_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_sh_flags_bit2,
{ "Update-Eff-Enhance", "diameter.3gpp.feature_list1_sh_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_sh_flags_bit3,
{ "Additional-MSISDN", "diameter.3gpp.feature_list1_sh_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_sh_flags_spare_bits,
{ "Spare", "diameter.3gpp.feature_list1_sh_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xfffffff0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit0,
{ "Operator Determined Barring of all Packet Oriented Services", "diameter.3gpp.feature_list1_s6a_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit1,
{ "Operator Determined Barring of Packet Oriented Services from access points that are within the HPLMN whilst the subscriber is roaming in a VPLMN", "diameter.3gpp.feature_list1_s6a_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit2,
{ "Operator Determined Barring of Packet Oriented Services from access points that are within the roamed to VPLMN", "diameter.3gpp.feature_list1_s6a_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit3,
{ "Operator Determined Barring of all outgoing calls", "diameter.3gpp.feature_list1_s6a_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit4,
{ "Operator Determined Barring of all outgoing international calls", "diameter.3gpp.feature_list1_s6a_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit5,
{ "Operator Determined Barring of all outgoing international calls except those directed to the home PLMN country", "diameter.3gpp.feature_list1_s6a_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit6,
{ "Operator Determined Barring of all outgoing inter-zonal calls", "diameter.3gpp.feature_list1_s6a_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit7,
{ "Operator Determined Barring of all outgoing inter-zonal calls except those directed to the home PLMN country", "diameter.3gpp.feature_list1_s6a_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit8,
{ "Operator Determined Barring of all outgoing international calls except those directed to the home PLMN country and Barring of all outgoing inter-zonal calls", "diameter.3gpp.feature_list1_s6a_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit9,
{ "Regional Subscription", "diameter.3gpp.feature_list1_s6a_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit10,
{ "Trace Function", "diameter.3gpp.feature_list1_s6a_flags_bit10",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000400,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit11,
{ "All LCS Privacy Exception Classes", "diameter.3gpp.feature_list1_s6a_flags_bit11",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000800,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit12,
{ "Allow location by any LCS client", "diameter.3gpp.feature_list1_s6a_flags_bit12",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00001000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit13,
{ "Allow location by any value added LCS client to which a call/session is established from the target UE", "diameter.3gpp.feature_list1_s6a_flags_bit13",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00002000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit14,
{ "Allow location by designated external value added LCS clients", "diameter.3gpp.feature_list1_s6a_flags_bit14",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00004000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit15,
{ "Allow location by designated PLMN operator LCS clients", "diameter.3gpp.feature_list1_s6a_flags_bit15",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00008000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit16,
{ "Allow location by LCS clients of a designated LCS service type", "diameter.3gpp.feature_list1_s6a_flags_bit16",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00010000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit17,
{ "All Mobile Originating Location Request Classes", "diameter.3gpp.feature_list1_s6a_flags_bit17",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00020000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit18,
{ "Allow an MS to request its own location", "diameter.3gpp.feature_list1_s6a_flags_bit18",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00040000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit19,
{ "Allow an MS to perform self location without interaction with the PLMN", "diameter.3gpp.feature_list1_s6a_flags_bit19",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00080000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit20,
{ "Allow an MS to request transfer of its location to another LCS client", "diameter.3gpp.feature_list1_s6a_flags_bit20",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00100000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit21,
{ "Short Message MO-PP", "diameter.3gpp.feature_list1_s6a_flags_bit21",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00200000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit22,
{ "Barring of Outgoing Calls", "diameter.3gpp.feature_list1_s6a_flags_bit22",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00400000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit23,
{ "Barring of all outgoing calls", "diameter.3gpp.feature_list1_s6a_flags_bit23",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00800000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit24,
{ "Barring of outgoing international calls", "diameter.3gpp.feature_list1_s6a_flags_bit24",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x01000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit25,
{ "Barring of outgoing international calls except those directed to the home PLMN Country", "diameter.3gpp.feature_list1_s6a_flags_bit25",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x02000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit26,
{ "UE Reachability Notification", "diameter.3gpp.feature_list1_s6a_flags_bit26",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x04000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit27,
{ "Terminating Access Domain Selection Data Retrieval", "diameter.3gpp.feature_list1_s6a_flags_bit27",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x08000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit28,
{ "State/Location Information Retrieval", "diameter.3gpp.feature_list1_s6a_flags_bit28",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x10000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit29,
{ "Partial Purge from a Combined MME/SGSN", "diameter.3gpp.feature_list1_s6a_flags_bit29",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x20000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit30,
{ "UE Time Zone Retrieval", "diameter.3gpp.feature_list1_s6a_flags1_bit30",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x40000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit31,
{ "Additional MSISDN", "diameter.3gpp.feature_list1_s6a_flags_bit31",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x80000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit0,
{ "SMS in MME", "diameter.3gpp.feature_list2_s6a_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit1,
{ "SMS in SGSN", "diameter.3gpp.feature_list2_s6a_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit2,
{ "Dia-LCS-all-PrivExcep", "diameter.3gpp.feature_list2_s6a_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit3,
{ "Dia-LCS-Universal", "diameter.3gpp.feature_list2_s6a_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit4,
{ "Dia-LCS-CallSessionRelated", "diameter.3gpp.feature_list2_s6a_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit5,
{ "Dia-LCS-CallSessionUnrelated", "diameter.3gpp.feature_list2_s6a_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit6,
{ "Dia-LCS-PLMNOperator", "diameter.3gpp.feature_list2_s6a_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit7,
{ "Dia-LCS-ServiceType", "diameter.3gpp.feature_list2_s6a_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit8,
{ "Dia-LCS-all-MOLR-SS", "diameter.3gpp.feature_list2_s6a_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit9,
{ "Dia-LCS-BasicSelfLocation", "diameter.3gpp.feature_list2_s6a_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit10,
{ "Dia-LCS-AutonomousSelfLocation", "diameter.3gpp.feature_list2_s6a_flags_bit10",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000400,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit11,
{ "Dia-LCS-TransferToThirdParty", "diameter.3gpp.feature_list2_s6a_flags_bit11",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000800,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit12,
{ "Gdd-in-SGSN", "diameter.3gpp.feature_list2_s6a_flags_bit12",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00001000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit13,
{ "Optimized-LCS-Proc-Support", "diameter.3gpp.feature_list2_s6a_flags_bit13",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00002000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit14,
{ "SGSN CAMEL Capability", "diameter.3gpp.feature_list2_s6a_flags_bit14",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00004000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit15,
{ "ProSe Capability", "diameter.3gpp.feature_list2_s6a_flags_bit15",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00008000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit16,
{ "P-CSCF Restoration", "diameter.3gpp.feature_list2_s6a_flags_bit16",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00010000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit17,
{ "Reset-IDs", "diameter.3gpp.feature_list2_s6a_flags_bit17",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00020000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_spare_bits,
{ "Spare", "diameter.3gpp.feature_list2_s6a_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFC0000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags,
{ "GX Feature-List Flags", "diameter.3gpp.gx_feature_list_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit0,
{ "Rel-8 Gx", "diameter.3gpp.feature_list_gx_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit1,
{ "Rel-9 Gx", "diameter.3gpp.feature_list_gx_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit2,
{ "Provisioning AF Signaling IP Flow Information",
"diameter.3gpp.feature_list_gx_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit3,
{ "Rel-10 Gx", "diameter.3gpp.feature_list_gx_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit4,
{ "Sponsored Data Connectivity",
"diameter.3gpp.feature_list_gx_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit5,
{ "IP Flow Mobility", "diameter.3gpp.feature_list_gx_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit6,
{ "ADC", "diameter.3gpp.feature_list_gx_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit7,
{ "vSRVCC", "diameter.3gpp.feature_list_gx_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit8,
{ "EPC-routed", "diameter.3gpp.feature_list_gx_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit9,
{ "rSRVCC", "diameter.3gpp.feature_list_gx_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit10,
{ "NetLoc", "diameter.3gpp.feature_list_gx_flags_bit10",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported),0x00000400,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit11,
{ "Usage Monitoring Congestion Handling",
"diameter.3gpp.feature_list_gx_flags_bit11",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported),0x00000800,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit12,
{ "Extended Filter", "diameter.3gpp.feature_list_gx_flags_bit12",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00001000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit13,
{ "Trusted WLAN Access", "diameter.3gpp.feature_list_gx_flags_bit13",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00002000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit14,
{ "SGW Restoration procedures", "diameter.3gpp.feature_list_gx_flags_bit14",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00004000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit15,
{ "Time based Usage Monitoring Control", "diameter.3gpp.feature_list_gx_flags_bit15",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00008000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit16,
{ "Pending Transaction", "diameter.3gpp.feature_list_gx_flags_bit16",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00010000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit17,
{ "Application Based Charging", "diameter.3gpp.feature_list_gx_flags_bit17",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00020000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit18,
{ "Spare", "diameter.3gpp.feature_list_gx_flags_bit18",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00040000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit19,
{ "NetLoc Trusted WLAN", "diameter.3gpp.feature_list_gx_flags_bit19",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00080000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit20,
{ "Fixed Broadband Access Convergence", "diameter.3gpp.feature_list_gx_flags_bit20",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported),0x00100000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit21,
{ "Conditional APN Policy Info", "diameter.3gpp.feature_list_gx_flags_bit21",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00200000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit22,
{ "RAN and/or NAS release cause", "diameter.3gpp.feature_list_gx_flags_bit22",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00400000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit23,
{ "Presence Reporting Area Information reporting", "diameter.3gpp.feature_list_gx_flags_bit23",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00800000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit24,
{ "P-CSCF Restoration Enhancement", "diameter.3gpp.feature_list_gx_flags_bit24",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x01000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit25,
{ "Mission Critical QCIs", "diameter.3gpp.feature_list_gx_flags_bit25",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x02000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit26,
{ "ResShare", "diameter.3gpp.feature_list_gx_flags_bit26",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x04000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit27,
{ "ExUsage", "diameter.3gpp.feature_list_gx_flags_bit27",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x08000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit28,
{ "NBIFOM", "diameter.3gpp.feature_list_gx_flags_bit28",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x10000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit29,
{ "TSC", "diameter.3gpp.feature_list_gx_flags_bit29",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x20000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit30,
{ "NetLoc-Untrusted-WLAN", "diameter.3gpp.feature_list_gx_flags_bit30",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x40000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_gx_flags_bit31,
{ "CondPolicyInfo", "diameter.3gpp.feature_list_gx_flags_bit31",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x80000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_spare_bits,
{ "Spare", "diameter.3gpp.cms.spare",
FT_UINT32, BASE_HEX, NULL, 0x01FFFFFF,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_no_gyn_session_serv_not_allowed,
{ "No Gyn Session, service not allowed", "diameter.3gpp.cms.no_gyn_session_serv_not_allowed",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x02000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_no_gyn_session_serv_allowed,
{ "No Gyn Session, service allowed", "diameter.3gpp.cms.no_gyn_session_serv_allowed",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x04000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_rating_failed,
{ "Rating Failed", "diameter.3gpp.cms.rating_failed",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x08000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_user_unknown,
{ "User Unknown", "diameter.3gpp.cms.user_unknown",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x10000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_auth_rej,
{ "Authorization Rejected", "diameter.3gpp.cms.auth_rej",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x20000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_credit_ctrl_not_applicable,
{ "Credit Control Not Applicable", "diameter.3gpp.cms.credit_ctrl_not_applicable",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x40000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_cms_end_user_serv_status,
{ "End User Service Denied", "diameter.3gpp.cms.end_user_serv_status",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x80000000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_subscribed,
{ "QoS-Subscribed", "diameter.3gpp.qos_subscribed",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_reliability_cls,
{ "Reliability class", "diameter.3gpp.qos.reliability_cls",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_qos_reliability_vals), 0x07,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_delay_cls,
{ "Quality of Service Delay class", "diameter.3gpp.qos.delay_cls",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(diameter_3gpp_qos_delay_cls_vals), 0x38,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_prec_class,
{ "Precedence class", "diameter.3gpp.qos.prec_class",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(diameter_3gpp_qos_prec_class_vals), 0x07,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_peak_thr,
{ "Peak throughput", "diameter.3gpp.qos.qos.peak_throughput",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(diameter_3gpp_qos_peak_thr_vals), 0xf0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_mean_thr,
{ "Mean throughput", "diameter.3gpp.qos.mean_throughput",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(diameter_3gpp_qos_mean_thr_vals), 0x1f,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_al_ret_priority,
{ "Allocation/Retention priority", "diameter.3gpp.qos.al_ret_priority",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_del_of_err_sdu,
{ "Delivery of erroneous SDUs", "diameter.3gpp.qos.del_of_err_sdu",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_qos_del_of_err_sdu_vals), 0x07,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_del_order,
{ "Delivery order", "diameter.3gpp.qos.del_order",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_qos_del_order_vals), 0x18,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_traffic_cls,
{ "Traffic class", "diameter.3gpp.qos.traffic_cls",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_qos_traffic_cls_vals), 0xe0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_maximum_sdu_size,
{ "Maximum SDU size", "diameter.3gpp.qos.qos.maximum_sdu_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_max_bitrate_upl,
{ "Maximum bitrate for uplink", "diameter.3gpp.qos.max_bitrate_upl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_max_bitrate_downl,
{ "Maximum bitrate for downlink", "diameter.3gpp.qos.max_bitrate_downl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_sdu_err_rat,
{ "SDU error ratio", "diameter.3gpp.qos.sdu_err_rat",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_qos_sdu_err_rat_vals), 0x0f,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_ber,
{ "Residual Bit Error Rate (BER)", "diameter.3gpp.qos.ber",
FT_UINT8, BASE_DEC, VALS(diameter_3gpp_qos_ber_vals), 0xf0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_traff_hdl_pri,
{ "Traffic handling priority", "diameter.3gpp.qos.traff_hdl_pri",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_traff_hdl_pri_vals), 0x03,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_trans_delay,
{ "Transfer delay", "diameter.3gpp.qos.trans_delay",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_guar_bitrate_upl,
{ "Guaranteed bitrate for uplink", "diameter.3gpp.qos.guar_bitrate_upl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_guar_bitrate_downl,
{ "Guaranteed bitrate for downlink", "diameter.3gpp.qos.guar_bitrate_downl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_source_stat_desc,
{ "Source statistics description", "diameter.3gpp.qos.source_stat_desc",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_signalling_ind,
{ "Signalling indication", "diameter.3gpp.qos.signalling_ind",
FT_BOOLEAN, SEP_DOT, TFS(&diameter_3gpp_qos_signalling_ind_value), 0x10,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_max_bitrate_downl_ext,
{ "Maximum bitrate for downlink (extended)", "diameter.3gpp.qos.max_bitrate_downl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_guar_bitrate_downl_ext,
{ "Guaranteed bitrate for downlink (extended)", "diameter.3gpp.qos.guar_bitrate_downl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_max_bitrate_upl_ext,
{ "Maximum bitrate for uplink (extended)", "diameter.3gpp.qos.max_bitrate_upl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_guar_bitrate_upl_ext,
{ "Guaranteed bitrate for uplink (extended)", "diameter.3gpp.qos.guar_bitrate_upl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_pre_emption_vulnerability,
{ "Pre-emption vulnerability", "diameter.3gpp.qos.pre_emption_vulnerability",
FT_BOOLEAN, SEP_DOT, TFS(&tfs_set_notset), 0x01,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_priority_level,
{ "Priority level", "diameter.3gpp.qos.priority_level",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL }
},
{ &hf_diameter_3gpp_qos_pre_emption_capability,
{ "Pre-emption capability", "diameter.3gpp.qos.pre_emption_capability",
FT_BOOLEAN, SEP_DOT, TFS(&tfs_set_notset), 0x40,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags,
{ "ULR Flags", "diameter.3gpp.ulr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit0,
{ "Single-Registration-Indication", "diameter.3gpp.ulr_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit1,
{ "S6a/S6d-Indicator", "diameter.3gpp.ulr_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit2,
{ "Skip-Subscriber-Data", "diameter.3gpp.ulr_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit3,
{ "GPRS-Subscription-Data-Indicator", "diameter.3gpp.ulr_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit4,
{ "Node-Type-Indicator", "diameter.3gpp.ulr_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit5,
{ "Initial-Attach-Indicator", "diameter.3gpp.ulr_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit6,
{ "PS-LCS-Not-Supported-By-UE", "diameter.3gpp.ulr_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit7,
{ "SMS-Only-Indication", "diameter.3gpp.ulr_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_spare_bits,
{ "Spare", "diameter.3gpp.ulr_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFF00,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ula_flags,
{ "ULA Flags", "diameter.3gpp.ula_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ula_flags_bit0,
{ "Separation Indication", "diameter.3gpp.ula_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ula_flags_bit1,
{ "MME Registered for SMS", "diameter.3gpp.ula_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ula_flags_spare_bits,
{ "Spare", "diameter.3gpp.ula_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags,
{ "DSR Flags", "diameter.3gpp.dsr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit0,
{ "Regional Subscription Withdrawal", "diameter.3gpp.dsr_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit1,
{ "Complete APN Configuration Profile Withdrawal", "diameter.3gpp.dsr_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit2,
{ "Subscribed Charging Characteristics Withdrawal", "diameter.3gpp.dsr_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit3,
{ "PDN subscription contexts Withdrawal", "diameter.3gpp.dsr_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit4,
{ "STN-SR", "diameter.3gpp.dsr_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit5,
{ "Complete PDP context list Withdrawal", "diameter.3gpp.dsr_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit6,
{ "PDP contexts Withdrawal", "diameter.3gpp.dsr_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit7,
{ "Roaming Restricted due to unsupported feature", "diameter.3gpp.dsr_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit8,
{ "Trace Data Withdrawal", "diameter.3gpp.dsr_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit9,
{ "CSG Deleted", "diameter.3gpp.dsr_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit10,
{ "APN-OI-Replacement", "diameter.3gpp.dsr_flags_bit10",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000400,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit11,
{ "GMLC List Withdrawal", "diameter.3gpp.dsr_flags_bit11",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000800,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit12,
{ "LCS Withdrawal", "diameter.3gpp.dsr_flags_bit12",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00001000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit13,
{ "SMS Withdrawal", "diameter.3gpp.dsr_flags_bit13",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00002000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit14,
{ "Subscribed periodic RAU-TAU Timer Withdrawal", "diameter.3gpp.dsr_flags_bit14",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00004000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit15,
{ "Subscribed VSRVCC Withdrawal", "diameter.3gpp.dsr_flags_bit15",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00008000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit16,
{ "A-MSISDN Withdrawal", "diameter.3gpp.dsr_flags_bit16",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00010000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit17,
{ "ProSe Withdrawal", "diameter.3gpp.dsr_flags_bit17",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00020000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit18,
{ "Reset-IDs", "diameter.3gpp.dsr_flags_bit18",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00040000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_spare_bits,
{ "Spare", "diameter.3gpp.dsr_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFF80000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsa_flags,
{ "DSA Flags", "diameter.3gpp.dsa_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsa_flags_bit0,
{ "Network Node area restricted", "diameter.3gpp.dsa_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsa_flags_spare_bits,
{ "Spare", "diameter.3gpp.dsa_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags,
{ "Access-Restriction-Data Flags", "diameter.3gpp.acc_res_dat_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit0,
{ "UTRAN Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit1,
{ "GERAN Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit2,
{ "GAN Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit3,
{ "I-HSPA-Evolution Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit4,
{ "WB-E-UTRAN Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit5,
{ "HO-To-Non-3GPP-Access Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_bit6,
{ "NB-IoT Not Allowed", "diameter.3gpp.acc_res_dat_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_acc_res_dat_flags_spare_bits,
{ "Spare", "diameter.3gpp.acc_res_dat_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFF80,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ida_flags,
{ "IDA Flags", "diameter.3gpp.ida_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ida_flags_bit0,
{ "Network Node area restricted", "diameter.3gpp.ida_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ida_flags_spare_bits,
{ "Spare", "diameter.3gpp.ida_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags,
{ "PUA Flags", "diameter.3gpp.pua_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags_bit0,
{ "Freeze M-TMSI", "diameter.3gpp.pua_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags_bit1,
{ "Freeze P-TMSI", "diameter.3gpp.pua_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags_spare_bits,
{ "Spare", "diameter.3gpp.pua_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags,
{ "NOR Flags", "diameter.3gpp.nor_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit0,
{ "Single-Registration-Indication", "diameter.3gpp.nor_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit1,
{ "SGSN area restricted", "diameter.3gpp.nor_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit2,
{ "Ready for SM", "diameter.3gpp.nor_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit3,
{ "UE Reachable", "diameter.3gpp.nor_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit4,
{ "Delete all APN and PDN GW identity pairs", "diameter.3gpp.nor_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit5,
{ "UE Reachable from SGSN", "diameter.3gpp.nor_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit6,
{ "Ready for SM from MME", "diameter.3gpp.nor_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit7,
{ "Homogeneous Support of IMS Voice Over PS Sessions", "diameter.3gpp.nor_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit8,
{ "S6a/S6d-Indicator", "diameter.3gpp.nor_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit9,
{ "Removal of MME Registration for SMS", "diameter.3gpp.nor_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_spare_bits,
{ "Spare", "diameter.3gpp.nor_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFC00,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags,
{ "IDR Flags", "diameter.3gpp.idr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit0,
{ "UE Reachability Request", "diameter.3gpp.idr_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit1,
{ "T-ADS Data Request", "diameter.3gpp.idr_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit2,
{ "EPS User State Request", "diameter.3gpp.idr_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit3,
{ "EPS Location Information Request", "diameter.3gpp.idr_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit4,
{ "Current Location Request", "diameter.3gpp.idr_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit5,
{ "Local Time Zone Request", "diameter.3gpp.idr_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit6,
{ "Remove SMS Registration", "diameter.3gpp.idr_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit7,
{ "RAT-Type Requested", "diameter.3gpp.idr_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit8,
{ "P-CSCF Restoration Request", "diameter.3gpp.idr_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_spare_bits,
{ "Spare", "diameter.3gpp.idr_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFE00,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ppr_flags,
{ "PPR Flags", "diameter.3gpp.ppr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ppr_flags_bit0,
{ "Reset-Indication", "diameter.3gpp.ppr_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ppr_flags_bit1,
{ "Access-Network-Info-Request", "diameter.3gpp.ppr_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ppr_flags_bit2,
{ "UE-Local-Time-Zone-Request", "diameter.3gpp.ppr_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ppr_flags_bit3,
{ "P-CSCF Restoration Request", "diameter.3gpp.ppr_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ppr_flags_spare_bits,
{ "Spare", "diameter.3gpp.ppr_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFF0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_aaa_fail_flags,
{ "AAA Failure Indication", "diameter.3gpp.aaa_fail_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_aaa_fail_flags_bit0,
{ "AAA Failure", "diameter.3gpp.aaa_fail_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_aaa_fail_flags_spare_bits,
{ "Spare", "diameter.3gpp.aaa_fail_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_flags,
{ "DER Flags", "diameter.3gpp.der_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_flags_bit0,
{ "NSWO-Capability-Indication", "diameter.3gpp.der_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_flags_bit1,
{ "TWAN-S2a-Connectivity-Indicator", "diameter.3gpp.der_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_flags_spare_bits,
{ "Spare", "diameter.3gpp.der_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dea_flags,
{ "DEA Flags", "diameter.3gpp.dea_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dea_flags_bit0,
{ "NSWO-Authorization", "diameter.3gpp.dea_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dea_flags_bit1,
{ "TWAN-S2a-Connectivity-Indicator", "diameter.3gpp.dea_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dea_flags_spare_bits,
{ "Spare", "diameter.3gpp.dea_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_diameter_3gpp_rar_flags,
{ "RAR Flags", "diameter.3gpp.rar_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_rar_flags_bit0,
{ "Trust-Relationship-Update-indication", "diameter.3gpp.rar_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_rar_flags_bit1,
{ "P-CSCF Restoration Request", "diameter.3gpp.rar_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_rar_flags_spare_bits,
{ "Spare", "diameter.3gpp.rar_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFC,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_s6b_flags,
{ "RAR Flags", "diameter.3gpp.rar_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_s6b_flags_bit0,
{ "Initial-Attach-Indicator", "diameter.3gpp.rar_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_der_s6b_flags_spare_bits,
{ "Spare", "diameter.3gpp.rar_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ipv6addr,
{ "IPv6 Address", "diameter.3gpp.ipv6addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer,
{ "Absolute Time of MBMS Data Transfer", "diameter.3gpp.mbms_abs_time_ofmbms_data_tfer",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_udp_port ,
{ "UDP Port", "diameter.3gpp.udp_port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_imeisv,
{ "IMEISV", "diameter.3gpp.imeisv",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_af_charging_identifier,
{ "AF-Charging-Identifier", "diameter.3gpp.af_charging_identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_af_application_identifier,
{ "AF-Application-Identifier", "diameter.3gpp.af_application_identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_charging_rule_name,
{ "Charging-Rule-Name", "diameter.3gpp.charging_rule_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_monitoring_key,
{ "Monitoring-Key", "diameter.3gpp.monitoring_key",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_event,
{ "MBMS-Bearer-Event", "diameter.3gpp.mbms_bearer_event",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_event_bit0,
{ "Bearer Terminated", "diameter.3gpp.mbms_bearer_event_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_event_spare_bits,
{ "Spare", "diameter.3gpp.mbms_bearer_event_spare",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result,
{ "MBMS-Bearer-Result", "diameter.3gpp.mbms_bearer_result",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit0,
{ "Success", "diameter.3gpp.mbms_bearer_result_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit1,
{ "Authorization rejected", "diameter.3gpp.mbms_bearer_result_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit2,
{ "Resources exceeded", "diameter.3gpp.mbms_bearer_result_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit3,
{ "Unknown TMGI", "diameter.3gpp.mbms_bearer_result_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit4,
{ "TMGI not in use", "diameter.3gpp.mbms_bearer_result_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit5,
{ "Overlapping MBMS-Service-Area", "diameter.3gpp.mbms_bearer_result_bit5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit6,
{ "Unknown Flow Identifier", "diameter.3gpp.mbms_bearer_result_bit6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit7,
{ "QoS Authorization Rejected", "diameter.3gpp.mbms_bearer_result_bit7",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit8,
{ "Unknown MBMS-Service-Area", "diameter.3gpp.mbms_bearer_result_bit8",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit9,
{ "MBMS-Service-Area Authorization Rejected", "diameter.3gpp.mbms_bearer_result_bit9",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit10,
{ "MBMS-Start-Time", "diameter.3gpp.mbms_bearer_result_bit10",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000400,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_bit11,
{ "Invalid AVP combination", "diameter.3gpp.mbms_bearer_result_bit11",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000800,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_bearer_result_spare_bits,
{ "Spare", "diameter.3gpp.mbms_bearer_result_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFF000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result,
{ "TMGI-Allocation-Result", "diameter.3gpp.tmgi_allocation_result",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result_bit0,
{ "Success", "diameter.3gpp.tmgi_allocation_result_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result_bit1,
{ "Authorization rejected", "diameter.3gpp.tmgi_allocation_result_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result_bit2,
{ "Resources exceeded", "diameter.3gpp.tmgi_allocation_result_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result_bit3,
{ "Unknown TMGI", "diameter.3gpp.tmgi_allocation_result_bit3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result_bit4,
{ "Too many TMGIs requested", "diameter.3gpp.tmgi_allocation_result_bit4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_allocation_result_spare_bits,
{ "Spare", "diameter.3gpp.tmgi_allocation_result_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFE0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_deallocation_result,
{ "TMGI-Deallocation-Result", "diameter.3gpp.tmgi_deallocation_result",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_deallocation_result_bit0,
{ "Success", "diameter.3gpp.tmgi_deallocation_result_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_deallocation_result_bit1,
{ "Authorization rejected", "diameter.3gpp.tmgi_deallocation_result_bit1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_deallocation_result_bit2,
{ "Unknown TMGI", "diameter.3gpp.tmgi_deallocation_result_bit2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi_deallocation_result_spare_bits,
{ "Spare", "diameter.3gpp.tmgi_deallocation_result_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFF8,
NULL, HFILL }
},
{ &hf_diameter_3gpp_sar_flags,
{ "SAR Flags", "diameter.3gpp.sar_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_sar_flags_flags_bit0,
{ "P-CSCF Restoration Indication", "diameter.3gpp.sar_flags_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit0,
{ "Rel8", "diameter.3gpp.feature_list1_rx_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit1,
{ "Rel9", "diameter.3gpp.feature_list1_rx_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit2,
{ "ProvAFsignalFlow", "diameter.3gpp.feature_list1_rx_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit3,
{ "SponsoredConnectivity", "diameter.3gpp.feature_list1_rx_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit4,
{ "Rel10", "diameter.3gpp.feature_list1_rx_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit5,
{ "NetLoc", "diameter.3gpp.feature_list1_rx_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000020,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit6,
{ "ExtendedFilter", "diameter.3gpp.feature_list1_rx_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000040,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit7,
{ "SCTimeBasedUM", "diameter.3gpp.feature_list1_rx_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000080,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit8,
{ "Netloc-Trusted-WLAN", "diameter.3gpp.feature_list1_rx_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000100,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit9,
{ "RAN-NAS-Cause", "diameter.3gpp.feature_list1_rx_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000200,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit10,
{ "GroupComService", "diameter.3gpp.feature_list1_rx_flags_bit10",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000400,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit11,
{ "ResShare", "diameter.3gpp.feature_list1_rx_flags_bit11",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000800,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit12,
{ "DeferredService", "diameter.3gpp.feature_list1_rx_flags_bit12",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00001000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit13,
{ "DSCP", "diameter.3gpp.feature_list1_rx_flags_bit13",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00002000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit14,
{ "SponsorChange", "diameter.3gpp.feature_list1_rx_flags_bit14",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00004000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit15,
{ "E2EQOSMTSI", "diameter.3gpp.feature_list1_rx_flags_bit15",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00008000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit16,
{ "NetLoc-Untrusted-WLAN", "diameter.3gpp.feature_list1_rx_flags_bit16",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00010000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit17,
{ "MCPTT", "diameter.3gpp.feature_list1_rx_flags_bit17",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00020000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_bit18,
{ "PrioritySharing", "diameter.3gpp.feature_list1_rx_flags_bit18",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00040000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_rx_flags_spare_bits,
{ "Spare", "diameter.3gpp.feature_list2_s6a_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFF80000,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_rx_flags_bit0,
{ "PCSCF-Restoration-Enhancement", "diameter.3gpp.feature_list2_rx_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_rx_flags_spare_bits,
{ "Spare", "diameter.3gpp.feature_list2_s6a_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_sd_flags,
{ "SD Feature-List Flags", "diameter.3gpp.sd_feature_list_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit0,
{ "UMCH", "diameter.3gpp.feature_list_sd_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit1,
{ "Trusted-WLAN", "diameter.3gpp.feature_list_sd_flags_bit1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit2,
{ "TimeBasedUM", "diameter.3gpp.feature_list_sd_flags_bit2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit3,
{ "PendingTransaction", "diameter.3gpp.feature_list_sd_flags_bit3",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit4,
{ "ABC", "diameter.3gpp.feature_list_sd_flags_bit4",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit5,
{ "CNO-ULI", "diameter.3gpp.feature_list_sd_flags_bit5",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000020,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit6,
{ "ExUsage", "diameter.3gpp.feature_list_sd_flags_bit6",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000040,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit7,
{ "DLDSCPMarking", "diameter.3gpp.feature_list_sd_flags_bit7",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000080,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit8,
{ "TSC", "diameter.3gpp.feature_list_sd_flags_bit8",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000100,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit9,
{ "ENB-Change", "diameter.3gpp.feature_list_sd_flags_bit9",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000200,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_bit10,
{ "SponsoredConnectivity-Sd", "diameter.3gpp.feature_list_sd_flags_bit10",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000400,
NULL, HFILL}
},
{ &hf_diameter_3gpp_feature_list_sd_flags_spare_bits,
{ "Spare", "diameter.3gpp.feature_list_sd_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFF800,
NULL, HFILL}
},
{ &hf_diameter_3gpp_ran_nas_protocol_type,
{ "Protocol Type", "diameter.3gpp.ran_nas.protocol_type",
FT_UINT8, BASE_DEC, VALS(ran_nas_prot_type_vals), 0xF0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_ran_nas_cause_type,
{ "S1AP Cause Type", "diameter.3gpp.ran_nas.s1ap_type",
FT_UINT8, BASE_DEC, VALS(s1ap_Cause_vals), 0x0F,
NULL, HFILL}
},
{ &hf_diameter_3gpp_ran_nas_cause_value,
{ "Cause Value", "diameter.3gpp.ran_nas.cause_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_s1ap_radio_network,
{ "S1AP Radio Network Cause Value", "diameter.3gpp.ran_nas.radio_cause",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseRadioNetwork_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_s1ap_transport,
{ "S1AP Transport Cause Value", "diameter.3gpp.ran_nas.transport_cause",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseTransport_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_s1ap_nas,
{ "S1AP NAS Cause Value", "diameter.3gpp.ran_nas.nas_cause",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseNas_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_s1ap_protocol,
{ "S1AP Protocol Cause Value", "diameter.3gpp.ran_nas.protocol_cause",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseProtocol_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_s1ap_misc,
{ "S1AP Misc. Cause Value", "diameter.3gpp.ran_nas.misc_cause",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseMisc_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_emm_cause,
{ "EMM Cause Value", "diameter.3gpp.ran_nas.emm_cause",
FT_UINT8, BASE_DEC, VALS(nas_eps_emm_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_esm_cause,
{ "ESM Cause Value", "diameter.3gpp.ran_nas.esm_cause",
FT_UINT8, BASE_DEC, VALS(nas_eps_esm_cause_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_diameter_cause,
{ "Diameter Cause Value", "diameter.3gpp.ran_nas.diameter_cause",
FT_UINT16, BASE_DEC, VALS(diameter_3gpp_termination_cause_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_ikev2_cause,
{ "IKEv2 Cause Value", "diameter.3gpp.ran_nas.ikev2_cause",
FT_UINT16, BASE_DEC, VALS(diameter_3gpp_IKEv2_error_type_vals), 0x0,
NULL, HFILL}
},
{ &hf_diameter_3gpp_emergency_services_flags,
{ "Emergency-Services Flags", "diameter.3gpp.emergency_ind_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_emergency_services_flags_bit0,
{ "Emergency-Indication", "diameter.3gpp.emergency_ind_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hf_diameter_3gpp_emergency_services_flags_spare_bits,
{ "Spare", "diameter.3gpp.emergency_ind_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_air_flags,
{ "AIR Flags", "diameter.3gpp.air_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_air_flags_spare_bits,
{ "Spare", "diameter.3gpp.ulr_flags_spare",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFFFE,
NULL, HFILL }
},
{ &hf_diameter_3gpp_air_flags_bit0,
{ "Send UE Usage Type", "diameter.3gpp.air_flags_bit0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
};
static gint *ett[] = {
&diameter_3gpp_path_ett,
&diameter_3gpp_uar_flags_ett,
&diameter_3gpp_feature_list_ett,
&diameter_3gpp_tmgi_ett,
&diameter_3gpp_cms_ett,
&diameter_3gpp_qos_subscribed_ett,
&diameter_3gpp_ulr_flags_ett,
&diameter_3gpp_ula_flags_ett,
&diameter_3gpp_dsr_flags_ett,
&diameter_3gpp_dsa_flags_ett,
&diameter_3gpp_ida_flags_ett,
&diameter_3gpp_pua_flags_ett,
&diameter_3gpp_nor_flags_ett,
&diameter_3gpp_idr_flags_ett,
&diameter_3gpp_ppr_flags_ett,
&diameter_3gpp_aaa_fail_flags_ett,
&diameter_3gpp_der_flags_ett,
&diameter_3gpp_dea_flags_ett,
&diameter_3gpp_rar_flags_ett,
&diameter_3gpp_der_s6b_flags_ett,
&diameter_3gpp_mbms_bearer_event_ett,
&diameter_3gpp_mbms_bearer_result_ett,
&diameter_3gpp_tmgi_allocation_result_ett,
&diameter_3gpp_tmgi_deallocation_result_ett,
&diameter_3gpp_sar_flags_ett,
&diameter_3gpp_emergency_services_flags_ett,
&diameter_3gpp_air_flags_ett,
};
expert_module_t *expert_diameter_3gpp;
static ei_register_info ei[] = {
{ &ei_diameter_3gpp_plmn_id_wrong_len,
{ "diameter_3gpp.plmn_id_wrong_len", PI_PROTOCOL, PI_ERROR, "PLMN Id should be 3 octets", EXPFILL } },
};
proto_diameter_3gpp = proto_register_protocol("Diameter 3GPP","Diameter3GPP", "diameter.3gpp");
proto_register_field_array(proto_diameter_3gpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_diameter_3gpp = expert_register_protocol(proto_diameter_3gpp);
expert_register_field_array(expert_diameter_3gpp, ei, array_length(ei));
}
