static void* uat_bootp_record_copy_cb(void* n, const void* o, size_t siz _U_) {
uat_bootp_record_t* new_record = (uat_bootp_record_t *)n;
const uat_bootp_record_t* old_record = (const uat_bootp_record_t *)o;
if (old_record->text) {
new_record->text = g_strdup(old_record->text);
} else {
new_record->text = NULL;
}
return new_record;
}
static void uat_bootp_record_update_cb(void* r, const char** err) {
uat_bootp_record_t* rec = (uat_bootp_record_t *)r;
if ((rec->opt == 0) || (rec->opt >=BOOTP_OPT_NUM-1))
*err = ep_strdup_printf("Option must be between 1 and %d", BOOTP_OPT_NUM-2);
}
static void uat_bootp_record_free_cb(void*r) {
uat_bootp_record_t* rec = (uat_bootp_record_t *)r;
if (rec->text) g_free(rec->text);
}
static struct opt_info* bootp_get_opt(unsigned int idx)
{
if(idx>=BOOTP_OPT_NUM)
return NULL;
return &bootp_opt[idx];
}
static const char *
bootp_get_opt_text(unsigned int idx)
{
if(idx>=BOOTP_OPT_NUM)
return "unknown";
return bootp_opt[idx].text;
}
static int
bootp_handle_basic_types(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
enum field_type ftype, int offset, int total_len,
gint *hf, struct basic_types_hfs* hf_default)
{
int i, left;
gint32 time_s_secs;
guint32 time_u_secs;
int consumed = 0;
switch (ftype) {
case bytes:
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, total_len, ENC_BIG_ENDIAN);
else if (hf_default->bytes != NULL)
proto_tree_add_item(tree, *hf_default->bytes, tvb, offset, total_len, ENC_BIG_ENDIAN);
consumed = total_len;
break;
case ipv4:
if (total_len != 4) {
expert_add_info_format(pinfo, item, PI_PROTOCOL,
PI_ERROR, "length isn't 4");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, 4, ENC_BIG_ENDIAN);
else if (hf_default->ipv4 != NULL)
proto_tree_add_item(tree, *hf_default->ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
consumed = 4;
break;
case ipv4_list:
for (i = offset, left = total_len; left > 0; i += 4, left -= 4) {
if (left < 4) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "Option length isn't a multiple of 4");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, i, 4, ENC_BIG_ENDIAN);
else if (hf_default->ipv4_list != NULL)
proto_tree_add_item(tree, *hf_default->ipv4_list, tvb, i, 4, ENC_BIG_ENDIAN);
consumed += 4;
}
break;
case string:
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, total_len, ENC_BIG_ENDIAN);
else if (hf_default->string != NULL)
proto_tree_add_item(tree, *hf_default->string, tvb, offset, total_len, ENC_BIG_ENDIAN);
consumed = total_len;
break;
case val_boolean:
if (total_len != 1) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 1");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, 1, ENC_BIG_ENDIAN);
else if (hf_default->val_boolean != NULL)
proto_tree_add_item(tree, *hf_default->val_boolean, tvb, offset, 1, ENC_BIG_ENDIAN);
consumed = 1;
break;
case val_u_byte:
if (total_len != 1) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 1");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, 1, ENC_BIG_ENDIAN);
else if (hf_default->val_u_byte != NULL)
proto_tree_add_item(tree, *hf_default->val_u_byte, tvb, offset, 1, ENC_BIG_ENDIAN);
consumed = 1;
break;
case val_u_short:
if (total_len != 2) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 2");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, 2, ENC_BIG_ENDIAN);
else if (hf_default->val_u_short != NULL)
proto_tree_add_item(tree, *hf_default->val_u_short, tvb, offset, 2, ENC_BIG_ENDIAN);
consumed = 2;
break;
case val_u_le_short:
if (total_len != 2) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 2");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
else if (hf_default->val_u_short != NULL)
proto_tree_add_item(tree, *hf_default->val_u_short, tvb, offset, 2, ENC_LITTLE_ENDIAN);
consumed = 2;
break;
case val_u_short_list:
for (i = offset, left = total_len; left > 0; i += 2, left -= 2) {
if (left < 2) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "Option length isn't a multiple of 2");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, i, 2, ENC_BIG_ENDIAN);
else if (hf_default->val_u_short_list != NULL)
proto_tree_add_item(tree, *hf_default->val_u_short_list, tvb, i, 2, ENC_BIG_ENDIAN);
consumed += 2;
}
break;
case val_u_long:
if (total_len != 4) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 4");
break;
}
if (hf != NULL)
proto_tree_add_item(tree, *hf, tvb, offset, 4, ENC_BIG_ENDIAN);
else if (hf_default->val_u_long != NULL)
proto_tree_add_item(tree, *hf_default->val_u_long, tvb, offset, 4, ENC_BIG_ENDIAN);
consumed = 4;
break;
case time_in_s_secs:
if (total_len != 4) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 4");
break;
}
if (hf != NULL) {
time_s_secs = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_int_format_value(tree, *hf,
tvb, offset, 4, time_s_secs, "(%ds) %s", time_s_secs, time_secs_to_str(time_s_secs));
}
else if (hf_default->time_in_s_secs != NULL)
proto_tree_add_item(tree, *hf_default->time_in_s_secs, tvb, offset, 4, ENC_BIG_ENDIAN);
consumed = 4;
break;
case time_in_u_secs:
if (total_len != 4) {
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_ERROR, "length isn't 4");
break;
}
if (hf != NULL) {
time_u_secs = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, *hf,
tvb, offset, 4, time_u_secs, "(%us) %s", time_u_secs,
((time_u_secs == 0xffffffff) ? "infinity" : time_secs_to_str_unsigned(time_u_secs)));
}
else if (hf_default->time_in_u_secs != NULL)
proto_tree_add_item(tree, *hf_default->time_in_u_secs, tvb, offset, 4, ENC_BIG_ENDIAN);
consumed = 4;
break;
default:
break;
}
return consumed;
}
static int
bootp_option(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bp_tree, int voff,
int eoff, gboolean first_pass, gboolean *at_end, const char **dhcp_type_p,
const guint8 **vendor_class_id_p, guint8 *overload_p)
{
struct opt_info *opt;
enum field_type ftype;
guchar code = tvb_get_guint8(tvb, voff);
int optlen;
guchar byte;
int i, consumed, basictype_consumed;
int optoff, optleft, optend;
proto_tree *v_tree;
proto_item *vti, *ti;
guint8 protocol;
guint8 algorithm;
guint8 rdm;
guint8 fqdn_flags;
int o52voff, o52eoff;
gboolean o52at_end;
guint8 s_option;
guint8 s_len;
const guchar *dns_name;
gboolean option_handled = TRUE;
struct basic_types_hfs default_hfs = {
&hf_bootp_option_value,
&hf_bootp_option_value_ip_address,
&hf_bootp_option_value_ip_address,
&hf_bootp_option_value_stringz,
&hf_bootp_option_value_boolean,
&hf_bootp_option_value_8,
&hf_bootp_option_value_16,
&hf_bootp_option_value_16,
&hf_bootp_option_value_u32,
&hf_bootp_option_value_i32,
&hf_bootp_option_value_u32
};
switch (code) {
case 0:
for (i = voff + 1; i < eoff; i++ ) {
if (tvb_get_guint8(tvb, i) != 0) {
break;
}
}
i = i - voff;
if (!first_pass) {
if (bp_tree != NULL) {
vti = proto_tree_add_uint_format_value(bp_tree, hf_bootp_option_type,
tvb, voff, 1, 0, "(0) Padding");
v_tree = proto_item_add_subtree(vti, ett_bootp_option);
proto_tree_add_item(v_tree, hf_bootp_option_padding, tvb, voff, i, ENC_NA);
}
}
consumed = i;
return consumed;
case 255:
if (!first_pass) {
if (bp_tree != NULL) {
vti = proto_tree_add_uint_format_value(bp_tree, hf_bootp_option_type,
tvb, voff, 1, 0, "(255) End");
v_tree = proto_item_add_subtree(vti, ett_bootp_option);
if (*overload_p)
proto_tree_add_item(v_tree, hf_bootp_option_end_overload, tvb, voff, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(v_tree, hf_bootp_option_end, tvb, voff, 1, ENC_BIG_ENDIAN);
}
}
*at_end = TRUE;
consumed = 1;
return consumed;
}
if (first_pass) {
if (!tvb_bytes_exist(tvb, voff+1, 1)) {
return 1;
}
}
optlen = tvb_get_guint8(tvb, voff+1);
consumed = optlen + 2;
if (first_pass) {
if (tvb_bytes_exist(tvb, voff+2, consumed-2)) {
switch (code) {
case 52:
*overload_p = tvb_get_guint8(tvb, voff+2);
break;
case 53:
*dhcp_type_p =
val_to_str(tvb_get_guint8(tvb, voff+2),
opt53_text,
"Unknown Message Type (0x%02x)");
break;
case 60:
*vendor_class_id_p =
tvb_get_ptr(tvb, voff+2, consumed-2);
break;
case 119:
rfc3396_dns_domain_search_list.total_number_of_block++;
break;
case 120:
rfc3396_sip_server.total_number_of_block++;
break;
}
}
return consumed;
}
opt = bootp_get_opt(code);
if (opt == NULL)
{
return consumed;
}
ftype = opt->ftype;
optoff = voff+2;
vti = proto_tree_add_uint_format_value(bp_tree, hf_bootp_option_type,
tvb, voff, consumed, code, "(%d) %s", code, opt->text);
v_tree = proto_item_add_subtree(vti, ett_bootp_option);
proto_tree_add_item(v_tree, hf_bootp_option_length, tvb, voff+1, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(v_tree, hf_bootp_option_value, tvb, voff+2, optlen, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
switch (code) {
case 21:
for (i = optoff, optleft = optlen;
optleft > 0; i += 8, optleft -= 8) {
if (optleft < 8) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't a multiple of 8");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_policy_filter_ip, tvb, i, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_policy_filter_subnet_mask, tvb, i+4, 4, ENC_BIG_ENDIAN);
}
break;
case 33:
for (i = optoff, optleft = optlen;
optleft > 0; i += 8, optleft -= 8) {
if (optleft < 8) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't a multiple of 8");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_static_route_ip, tvb, i, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_static_route_router, tvb, i+4, 4, ENC_BIG_ENDIAN);
}
break;
case 43:
s_option = tvb_get_guint8(tvb, optoff);
if (*vendor_class_id_p != NULL &&
strncmp((const gchar*)*vendor_class_id_p, "PXEClient", strlen("PXEClient")) == 0) {
proto_item_append_text(vti, " (PXEClient)");
v_tree = proto_item_add_subtree(vti, ett_bootp_option);
optend = optoff + optlen;
while (optoff < optend) {
optoff = dissect_vendor_pxeclient_suboption(pinfo, vti, v_tree,
tvb, optoff, optend);
}
} else if (*vendor_class_id_p != NULL &&
((strncmp((const gchar*)*vendor_class_id_p, "pktc", strlen("pktc")) == 0) ||
(strncmp((const gchar*)*vendor_class_id_p, "docsis", strlen("docsis")) == 0) ||
(strncmp((const gchar*)*vendor_class_id_p, "OpenCable2.0", strlen("OpenCable2.0")) == 0) ||
(strncmp((const gchar*)*vendor_class_id_p, "CableHome", strlen("CableHome")) == 0))) {
proto_item_append_text(vti, " (CableLabs)");
optend = optoff + optlen;
while (optoff < optend) {
optoff = dissect_vendor_cablelabs_suboption(pinfo, vti, v_tree,
tvb, optoff, optend);
}
} else if (s_option==58 || s_option==64 || s_option==65
|| s_option==66 || s_option==67) {
proto_item_append_text(vti, " (Alcatel-Lucent)");
optend = optoff + optlen;
while (optoff < optend) {
optoff = dissect_vendor_alcatel_suboption(pinfo, vti, v_tree,
tvb, optoff, optend);
}
}
break;
case 52:
if (optlen < 1) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 1");
break;
}
byte = tvb_get_guint8(tvb, optoff);
proto_tree_add_item(v_tree, *opt->phf, tvb, optoff, 1, ENC_BIG_ENDIAN);
if (voff > VENDOR_INFO_OFFSET && byte >= 1 && byte <= 3) {
if (byte & OPT_OVERLOAD_FILE) {
proto_item *oti;
oti = proto_tree_add_text (bp_tree, tvb,
FILE_NAME_OFFSET, FILE_NAME_LEN,
"Boot file name option overload");
o52voff = FILE_NAME_OFFSET;
o52eoff = FILE_NAME_OFFSET + FILE_NAME_LEN;
o52at_end = FALSE;
rfc3396_dns_domain_search_list.index_current_block = 0;
rfc3396_sip_server.index_current_block = 0;
while (o52voff < o52eoff && !o52at_end) {
o52voff += bootp_option(tvb, pinfo, bp_tree, o52voff,
o52eoff, FALSE, &o52at_end,
dhcp_type_p, vendor_class_id_p,
overload_p);
}
if (!o52at_end)
{
expert_add_info_format(pinfo, oti, PI_PROTOCOL,
PI_ERROR, "file overload end option missing");
}
}
if (byte & OPT_OVERLOAD_SNAME) {
proto_item *oti;
oti = proto_tree_add_text (bp_tree, tvb,
SERVER_NAME_OFFSET, SERVER_NAME_LEN,
"Server host name option overload");
o52voff = SERVER_NAME_OFFSET;
o52eoff = SERVER_NAME_OFFSET + SERVER_NAME_LEN;
o52at_end = FALSE;
rfc3396_dns_domain_search_list.index_current_block = 0;
rfc3396_sip_server.index_current_block = 0;
while (o52voff < o52eoff && !o52at_end) {
o52voff += bootp_option(tvb, pinfo, bp_tree, o52voff,
o52eoff, FALSE, &o52at_end,
dhcp_type_p, vendor_class_id_p,
overload_p);
}
if (!o52at_end)
{
expert_add_info_format(pinfo, oti, PI_PROTOCOL,
PI_ERROR, "sname overload end option missing");
}
}
*overload_p = 0;
}
break;
case 55:
for (i = 0; i < optlen; i++) {
byte = tvb_get_guint8(tvb, optoff+i);
proto_tree_add_uint_format_value(v_tree, hf_bootp_option_parameter_request_list_item,
tvb, optoff+i, 1, byte, "(%d) %s", byte, bootp_get_opt_text(byte));
}
break;
case 60:
proto_tree_add_item(v_tree, hf_bootp_option_vendor_class_id, tvb, optoff, consumed-2, ENC_ASCII|ENC_NA);
if ((tvb_memeql(tvb, optoff, (const guint8*)PACKETCABLE_MTA_CAP10,
(int)strlen(PACKETCABLE_MTA_CAP10)) == 0)
||
(tvb_memeql(tvb, optoff, (const guint8*)PACKETCABLE_MTA_CAP15,
(int)strlen(PACKETCABLE_MTA_CAP15)) == 0)
||
(tvb_memeql(tvb, optoff, (const guint8*)PACKETCABLE_MTA_CAP20,
(int)strlen(PACKETCABLE_MTA_CAP20)) == 0))
{
dissect_packetcable_mta_cap(v_tree, tvb, optoff, optlen);
} else
if ((tvb_memeql(tvb, optoff, (const guint8*)PACKETCABLE_CM_CAP11,
(int)strlen(PACKETCABLE_CM_CAP11)) == 0)
||
(tvb_memeql(tvb, optoff, (const guint8*)PACKETCABLE_CM_CAP20,
(int)strlen(PACKETCABLE_CM_CAP20)) == 0 ))
{
dissect_docsis_cm_cap(v_tree, tvb, optoff, optlen, FALSE);
} else
if (tvb_memeql(tvb, optoff, (const guint8*)PACKETCABLE_CM_CAP30,
(int)strlen(PACKETCABLE_CM_CAP30)) == 0 )
{
proto_tree_add_text(v_tree, tvb, optoff, optlen,
"vendor-class-data: \"%s\"", tvb_format_stringzpad(tvb, optoff, optlen));
}
break;
case 61:
if (optlen > 0)
byte = tvb_get_guint8(tvb, optoff);
else
byte = 0;
if (optlen == 7 && byte > 0 && byte < 48) {
proto_tree_add_item(v_tree,
hf_bootp_hw_type, tvb, optoff, 1,
ENC_NA);
if (byte == ARPHRD_ETHER || byte == ARPHRD_IEEE802)
proto_tree_add_item(v_tree,
hf_bootp_hw_ether_addr, tvb, optoff+1, 6,
ENC_NA);
else
proto_tree_add_text(v_tree, tvb, optoff+1, 6,
"Client hardware address: %s",
tvb_arphrdaddr_to_str(tvb, optoff+1, 6, byte));
} else if (optlen == 17 && byte == 0) {
proto_tree_add_item(v_tree, hf_bootp_client_identifier_uuid,
tvb, optoff + 1, 16, ENC_LITTLE_ENDIAN);
} else if (byte == 255) {
guint16 duidtype;
guint16 hwtype;
guint8 *buf;
int enterprise;
proto_tree_add_text(v_tree, tvb, optoff+1, 4,
"IAID: %s",
tvb_arphrdaddr_to_str(tvb, optoff+1, 4, byte));
optoff = optoff + 5;
duidtype = tvb_get_ntohs(tvb, optoff);
proto_tree_add_text(v_tree, tvb, optoff, 2,
"DUID type: %s (%u)",
val_to_str_const(duidtype, duidtype_vals, "Unknown"),
duidtype);
switch (duidtype) {
case DUID_LLT:
if (optlen < 8) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "DUID: malformed option");
break;
}
hwtype=tvb_get_ntohs(tvb, optoff + 2);
proto_tree_add_item(v_tree, hf_bootp_client_identifier_duid_llt_hw_type,
tvb, optoff + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(v_tree, tvb, optoff + 4, 4,
"Time: %u", tvb_get_ntohl(tvb, optoff + 4));
if (optlen > 8) {
proto_tree_add_text(v_tree, tvb, optoff + 8,
optlen - 13, "Link-layer address: %s",
tvb_arphrdaddr_to_str(tvb, optoff+8, optlen-13, hwtype));
}
break;
case DUID_EN:
if (optlen < 6) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "DUID: malformed option");
break;
}
enterprise = tvb_get_ntohl(tvb, optoff+2);
proto_tree_add_text(v_tree, tvb, optoff + 2, 4,
"Enterprise-number: %s (%u)",
val_to_str_ext_const( enterprise, &sminmpec_values_ext, "Unknown"),
enterprise);
if (optlen > 6) {
buf = tvb_bytes_to_str(tvb, optoff + 6, optlen - 11);
proto_tree_add_text(v_tree, tvb, optoff + 6,
optlen - 11, "identifier: %s", buf);
}
break;
case DUID_LL:
if (optlen < 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "DUID: malformed option");
break;
}
hwtype=tvb_get_ntohs(tvb, optoff + 2);
proto_tree_add_item(v_tree, hf_bootp_client_identifier_duid_ll_hw_type,
tvb, optoff + 2, 2, ENC_BIG_ENDIAN);
if (optlen > 4) {
proto_tree_add_text(v_tree, tvb, optoff + 4,
optlen - 9, "Link-layer address: %s",
tvb_arphrdaddr_to_str(tvb, optoff+4, optlen-9, hwtype));
}
break;
}
} else {
}
break;
case 77: {
guchar user_class_instance_index;
proto_item *vtix;
proto_tree *o77_v_tree;
if (optlen < 2) {
expert_add_info_format(pinfo, v_tree, PI_PROTOCOL, PI_ERROR, "length isn't >= 2 (length = %i)", optlen);
break;
}
optleft = optlen;
for (user_class_instance_index = 0, i = 0, byte = tvb_get_guint8(tvb, optoff); i < optlen; byte = tvb_get_guint8(tvb, optoff + i), user_class_instance_index++) {
vtix = proto_tree_add_uint_format_value(v_tree, hf_bootp_option77_user_class,
tvb, optoff + i, byte + 1, user_class_instance_index, "[%d]", user_class_instance_index);
o77_v_tree = proto_item_add_subtree(vtix, ett_bootp_option77_instance);
proto_tree_add_item(o77_v_tree, hf_bootp_option77_user_class_length,
tvb, optoff + i, 1, ENC_BIG_ENDIAN);
if (byte == 0) {
expert_add_info_format(pinfo, vtix, PI_PROTOCOL, PI_ERROR, "UC_Len_%u isn't >= 1 (UC_Len_%u = 0)", user_class_instance_index, user_class_instance_index);
break;
}
optleft -= byte + 1;
if (optleft < 0) {
expert_add_info_format(pinfo, vtix, PI_PROTOCOL, PI_ERROR, "User Class Information: malformed option");
break;
}
proto_tree_add_item(o77_v_tree, hf_bootp_option77_user_class_data,
tvb, optoff + i + 1, byte, ENC_BIG_ENDIAN);
i += byte + 1;
}
break;
}
case 97:
if (optlen > 0)
byte = tvb_get_guint8(tvb, optoff);
else
byte = 0;
if (optlen == 7 && byte > 0 && byte < 48) {
proto_tree_add_item(v_tree,
hf_bootp_hw_type, tvb, optoff, 1,
ENC_NA);
if (byte == ARPHRD_ETHER || byte == ARPHRD_IEEE802)
proto_tree_add_item(v_tree,
hf_bootp_hw_ether_addr, tvb, optoff+1, 6,
ENC_NA);
else
proto_tree_add_text(v_tree, tvb, optoff+1, 6,
"Client hardware address: %s",
tvb_arphrdaddr_to_str(tvb, optoff+1, 6, byte));
} else if (optlen == 17 && byte == 0) {
proto_tree_add_item(v_tree, hf_bootp_client_identifier_uuid,
tvb, optoff + 1, 16, ENC_LITTLE_ENDIAN);
} else {
}
break;
case 63:
optend = optoff + optlen;
while (optoff < optend)
optoff = dissect_netware_ip_suboption(pinfo, vti, v_tree, tvb, optoff, optend);
break;
case 78:
if (optlen < 1) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 1");
break;
}
optleft = optlen;
byte = tvb_get_guint8(tvb, optoff);
proto_tree_add_item(v_tree, hf_bootp_option_slp_directory_agent_value, tvb, optoff, 1, ENC_BIG_ENDIAN);
optoff++;
optleft--;
if (byte == 0x80) {
if (optleft == 0)
break;
optoff++;
optleft--;
}
for (i = optoff; optleft > 0; i += 4, optleft -= 4) {
if (optleft < 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't a multiple of 4");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_slp_directory_agent_slpda_address, tvb, i, 4, ENC_BIG_ENDIAN);
}
break;
case 79:
proto_tree_add_item(v_tree, hf_bootp_option_slp_service_scope_value, tvb, optoff, 1, ENC_BIG_ENDIAN);
optoff++;
optleft = optlen - 1;
proto_tree_add_item(v_tree, hf_bootp_option_slp_service_scope_string, tvb, optoff, optleft, ENC_ASCII|ENC_NA);
break;
case 81:
if (optlen < 3) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 3");
break;
}
fqdn_flags = tvb_get_guint8(tvb, optoff);
proto_tree_add_text(v_tree, tvb, optoff, 1, "Flags: 0x%02x", fqdn_flags);
proto_tree_add_item(v_tree, hf_bootp_fqdn_mbz, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_fqdn_n, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_fqdn_e, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_fqdn_o, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_fqdn_s, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_fqdn_rcode1, tvb, optoff+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_fqdn_rcode2, tvb, optoff+2, 1, ENC_BIG_ENDIAN);
if (optlen > 3) {
if (fqdn_flags & F_FQDN_E) {
get_dns_name(tvb, optoff+3, optlen-3, optoff+3, &dns_name);
proto_tree_add_string(v_tree, hf_bootp_fqdn_name,
tvb, optoff+3, optlen-3, dns_name);
} else {
proto_tree_add_item(v_tree, hf_bootp_fqdn_asciiname,
tvb, optoff+3, optlen-3, ENC_ASCII|ENC_NA);
}
}
break;
case 82:
optend = optoff + optlen;
while (optoff < optend)
optoff = bootp_dhcp_decode_agent_info(pinfo, vti, v_tree, tvb, optoff, optend);
break;
case 85:
if (novell_string) {
proto_tree_add_item(v_tree, hf_bootp_option_novell_dss_string, tvb, optoff, optlen, ENC_ASCII|ENC_NA);
} else{
for (i = optoff, optleft = optlen; optleft > 0;
i += 4, optleft -= 4) {
if (optleft < 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't a multiple of 4");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_novell_dss_ip, tvb, i, 4, ENC_BIG_ENDIAN);
}
}
break;
case 94: {
guint8 id_type;
id_type = tvb_get_guint8(tvb, optoff);
if (id_type == 0x01) {
proto_tree_add_item(v_tree, hf_bootp_option_client_network_id_major_ver,
tvb, optoff + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_client_network_id_minor_ver,
tvb, optoff + 2, 1, ENC_LITTLE_ENDIAN);
}
break;
}
case 90:
case 210:
if (optlen < 11) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 11");
break;
}
optleft = optlen;
protocol = tvb_get_guint8(tvb, optoff);
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_protocol, tvb, optoff, 1, ENC_BIG_ENDIAN);
optoff++;
optleft--;
algorithm = tvb_get_guint8(tvb, optoff);
switch (protocol) {
case AUTHEN_PROTO_DELAYED_AUTHEN:
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_alg_delay, tvb, optoff, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_algorithm, tvb, optoff, 1, ENC_BIG_ENDIAN);
break;
}
optoff++;
optleft--;
rdm = tvb_get_guint8(tvb, optoff);
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_rdm, tvb, optoff, 1, ENC_BIG_ENDIAN);
optoff++;
optleft--;
switch (rdm) {
case AUTHEN_RDM_MONOTONIC_COUNTER:
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_rdm_replay_detection, tvb, optoff, 8, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_rdm_rdv, tvb, optoff, 8, ENC_ASCII|ENC_NA);
break;
}
optoff += 8;
optleft -= 8;
switch (protocol) {
case AUTHEN_PROTO_DELAYED_AUTHEN:
switch (algorithm) {
case AUTHEN_DELAYED_ALGO_HMAC_MD5:
if (*dhcp_type_p && !strcmp(*dhcp_type_p, OPT53_DISCOVER)) {
break;
} else {
if (optlen < 31) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 31");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_secret_id, tvb, optoff, 4, ENC_BIG_ENDIAN);
optoff += 4;
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_hmac_md5_hash, tvb, optoff, 16, ENC_ASCII|ENC_NA);
break;
}
default:
if (optleft == 0)
break;
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_information, tvb, optoff, optleft, ENC_ASCII|ENC_NA);
break;
}
break;
default:
if (optleft == 0)
break;
proto_tree_add_item(v_tree, hf_bootp_option_dhcp_authentication_information, tvb, optoff, optleft, ENC_ASCII|ENC_NA);
break;
}
break;
case 99:
optleft = optlen;
if (optleft >= 3)
{
proto_tree_add_item(v_tree, hf_bootp_option_civic_location_what, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_civic_location_country, tvb, optoff+1, 2, ENC_ASCII|ENC_NA);
optleft = optleft - 3;
optoff = optoff + 3;
while (optleft >= 2)
{
int calength = tvb_get_guint8(tvb, optoff+1);
proto_tree_add_item(v_tree, hf_bootp_option_civic_location_ca_type, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_civic_location_ca_length, tvb, optoff+1, 1, ENC_BIG_ENDIAN);
optoff += 2;
optleft -= 2;
if (calength == 0)
continue;
if (optleft >= calength)
{
proto_tree_add_item(v_tree, hf_bootp_option_civic_location_ca_value, tvb, optoff, calength, ENC_ASCII|ENC_NA);
optoff = optoff + calength;
optleft = optleft - calength;
}
else
{
optleft = 0;
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Error with CAType");
}
}
}
break;
case 117:
if (optlen < 2) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length (%u) isn't >= 2", optlen);
} else if (optlen & 1) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length (%u) isn't even number", optlen);
} else {
guint16 ns;
for (i = 0, ns = tvb_get_ntohs(tvb, optoff); i < optlen; i += 2, ns = tvb_get_ntohs(tvb, optoff + i)) {
switch (ns) {
case RFC2937_LOCAL_NAMING_INFORMATION:
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_name_service_search_option, tvb, optoff + i, 2, "Local naming information (e.g., an /etc/hosts file on a UNIX machine) (0)");
break;
case RFC2937_DOMAIN_NAME_SERVER_OPTION:
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_name_service_search_option, tvb, optoff + i, 2, "Domain Name Server Option (6)");
break;
case RFC2937_NETWORK_INFORMATION_SERVERS_OPTION:
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_name_service_search_option, tvb, optoff + i, 2, "Network Information Servers Option (41)");
break;
case RFC2937_NETBIOS_OVER_TCP_IP_NAME_SERVER_OPTION:
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_name_service_search_option, tvb, optoff + i, 2, "NetBIOS over TCP/IP Name Server Option (44)");
break;
case RFC2937_NETWORK_INFORMATION_SERVICE_PLUS_SERVERS_OPTION:
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_name_service_search_option, tvb, optoff + i, 2, "Network Information Service+ Servers Option (65)");
break;
default:
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Invalid Name Service (%u). RFC 2937 defines only 0, 6, 41, 44, and 65 as possible values.", ns);
break;
}
}
}
break;
case 119: {
char tmpChar[BOOTP_MAX_NO_CHAR];
rfc3396_dns_domain_search_list.index_current_block++;
if (rfc3396_dns_domain_search_list.total_number_of_block > 1) {
g_snprintf(tmpChar, BOOTP_MAX_NO_CHAR, "%u/%u", rfc3396_dns_domain_search_list.index_current_block, rfc3396_dns_domain_search_list.total_number_of_block);
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_dns_domain_search_list_rfc_3396_detected, tvb, optoff, optlen, tmpChar);
if (rfc3396_dns_domain_search_list.index_current_block != rfc3396_dns_domain_search_list.total_number_of_block) {
g_snprintf(tmpChar, BOOTP_MAX_NO_CHAR, "%u/%u", rfc3396_dns_domain_search_list.total_number_of_block, rfc3396_dns_domain_search_list.total_number_of_block);
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_dns_domain_search_list_refer_last_option, tvb, optoff, optlen, tmpChar);
}
}
if (rfc3396_dns_domain_search_list.tvb_composite == NULL && optlen) {
rfc3396_dns_domain_search_list.tvb_composite = tvb_new_composite();
}
if (optlen)
tvb_composite_append(rfc3396_dns_domain_search_list.tvb_composite, tvb_new_subset(tvb, optoff, optlen, optlen));
if (rfc3396_dns_domain_search_list.index_current_block == rfc3396_dns_domain_search_list.total_number_of_block
&& rfc3396_dns_domain_search_list.tvb_composite) {
unsigned int consumedx = 0;
unsigned int offset = 0;
tvb_composite_finalize(rfc3396_dns_domain_search_list.tvb_composite);
while (offset < tvb_length(rfc3396_dns_domain_search_list.tvb_composite)) {
consumedx = get_dns_name(rfc3396_dns_domain_search_list.tvb_composite, offset, tvb_length(rfc3396_dns_domain_search_list.tvb_composite), 0, &dns_name);
if (rfc3396_dns_domain_search_list.total_number_of_block == 1) {
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_dns_domain_search_list_fqdn, tvb, optoff + offset, consumedx, dns_name);
} else {
proto_tree_add_string(v_tree, hf_bootp_option_dhcp_dns_domain_search_list_fqdn, tvb, 0, 0, dns_name);
}
offset += consumedx;
}
rfc3396_dns_domain_search_list.tvb_composite = NULL;
}
break;
}
case 120: {
char tmpChar[BOOTP_MAX_NO_CHAR];
rfc3396_sip_server.index_current_block++;
if (rfc3396_sip_server.total_number_of_block > 1) {
g_snprintf(tmpChar, BOOTP_MAX_NO_CHAR, "%u/%u", rfc3396_sip_server.index_current_block, rfc3396_sip_server.total_number_of_block);
proto_tree_add_string(v_tree, hf_bootp_option_sip_server_rfc_3396_detected, tvb, optoff, optlen, tmpChar);
if (rfc3396_sip_server.index_current_block != rfc3396_sip_server.total_number_of_block) {
g_snprintf(tmpChar, BOOTP_MAX_NO_CHAR, "%u/%u", rfc3396_sip_server.total_number_of_block, rfc3396_sip_server.total_number_of_block);
proto_tree_add_string(v_tree, hf_bootp_option_sip_server_refer_last_option, tvb, optoff, optlen, tmpChar);
}
}
if (rfc3396_sip_server.tvb_composite == NULL && optlen) {
rfc3396_sip_server.tvb_composite = tvb_new_composite();
}
if (optlen)
tvb_composite_append(rfc3396_sip_server.tvb_composite, tvb_new_subset(tvb, optoff, optlen, optlen));
if (rfc3396_sip_server.index_current_block == rfc3396_sip_server.total_number_of_block
&& rfc3396_sip_server.tvb_composite) {
guint8 enc;
unsigned int offset = 1;
tvb_composite_finalize(rfc3396_sip_server.tvb_composite);
enc = tvb_get_guint8(rfc3396_sip_server.tvb_composite, 0);
if (rfc3396_sip_server.total_number_of_block == 1) {
proto_tree_add_uint(v_tree, hf_bootp_option_sip_server_enc, tvb, optoff, 1, enc);
} else {
proto_tree_add_uint(v_tree, hf_bootp_option_sip_server_enc, tvb, 0, 0, enc);
}
switch (enc) {
case RFC_3361_ENC_FQDN: {
unsigned int consumedx = 0;
if (tvb_length(rfc3396_sip_server.tvb_composite) < 3) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 3 (len = %u)", tvb_length(rfc3396_sip_server.tvb_composite));
break;
}
while (offset < tvb_length(rfc3396_sip_server.tvb_composite)) {
consumedx = get_dns_name(rfc3396_sip_server.tvb_composite, offset, tvb_length(rfc3396_sip_server.tvb_composite), 1 , &dns_name);
if (rfc3396_sip_server.total_number_of_block == 1) {
proto_tree_add_string(v_tree, hf_bootp_option_sip_server_name, tvb, optoff + offset, consumedx, dns_name);
} else {
proto_tree_add_string(v_tree, hf_bootp_option_sip_server_name, tvb, 0, 0, dns_name);
}
offset += consumedx;
}
rfc3396_sip_server.tvb_composite = NULL;
break;
}
case RFC_3361_ENC_IPADDR:
if (tvb_length(rfc3396_sip_server.tvb_composite) < 5) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't >= 5 (len = %u)", tvb_length(rfc3396_sip_server.tvb_composite));
break;
}
if ((tvb_length(rfc3396_sip_server.tvb_composite) - 1) & 3) {
if (rfc3396_sip_server.total_number_of_block == 1)
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't a multiple of 4 plus 1 (len = %u).", tvb_length(rfc3396_sip_server.tvb_composite));
else
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't a multiple of 4 plus 1 (len = %u). For your information with RFC 3396, the length is the length sum of all options 120 into this BOOTP packet.", tvb_length(rfc3396_sip_server.tvb_composite));
break;
}
while (offset < tvb_length(rfc3396_sip_server.tvb_composite)) {
if (rfc3396_sip_server.total_number_of_block == 1) {
proto_tree_add_item(v_tree, hf_bootp_option_sip_server_address, rfc3396_sip_server.tvb_composite, offset, 4, ENC_BIG_ENDIAN);
} else {
g_snprintf(tmpChar, BOOTP_MAX_NO_CHAR, "%u.%u.%u.%u (%u.%u.%u.%u)",
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset + 1),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset + 2),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset + 3),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset + 1),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset + 2),
tvb_get_guint8(rfc3396_sip_server.tvb_composite, offset + 3)
);
proto_tree_add_string(v_tree, hf_bootp_option_sip_server_address_stringz, tvb, 0, 0, tmpChar);
}
offset += 4;
}
break;
default:
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "RFC 3361 defines only 0 and 1 for Encoding byte (Encoding = %u).", enc);
break;
}
}
break;
}
case 121:
case 249: {
int mask_width, significant_octets;
optend = optoff + optlen;
if (optlen < 5) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length < 5 bytes");
break;
}
while (optoff < optend) {
mask_width = tvb_get_guint8(tvb, optoff);
if (mask_width > 32) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Mask width (%d) > 32", mask_width);
break;
}
significant_octets = (mask_width + 7) / 8;
vti = proto_tree_add_text(v_tree, tvb, optoff,
1 + significant_octets + 4,
"Subnet/MaskWidth-Router: ");
optoff++;
if (optend < optoff + significant_octets + 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Remaining length (%d) < %d bytes", optend - optoff, significant_octets + 4);
break;
}
if(mask_width == 0)
proto_item_append_text(vti, "default");
else {
for(i = 0 ; i < significant_octets ; i++) {
if (i > 0)
proto_item_append_text(vti, ".");
byte = tvb_get_guint8(tvb, optoff++);
proto_item_append_text(vti, "%d", byte);
}
for(i = significant_octets ; i < 4 ; i++)
proto_item_append_text(vti, ".0");
proto_item_append_text(vti, "/%d", mask_width);
}
proto_item_append_text(vti, "-%s", tvb_ip_to_str(tvb, optoff));
optoff += 4;
}
break;
}
case 123:
if (optlen == 16) {
int c;
unsigned char lci[16];
struct rfc3825_location_fixpoint_t location_fp;
struct rfc3825_location_decimal_t location;
for (c=0; c < 16;c++)
lci[c] = (unsigned char) tvb_get_guint8(tvb, optoff + c);
rfc3825_lci_to_fixpoint(lci, &location_fp);
i = rfc3825_fixpoint_to_decimal(&location_fp, &location);
if (i != RFC3825_NOERROR) {
proto_tree_add_text(v_tree, tvb, optoff, optlen, "Error: %s", val_to_str_const(i, rfc3825_error_types, "Unknown"));
} else {
proto_tree_add_text(v_tree, tvb, optoff, 5, "Latitude: %15.10f", location.latitude);
proto_tree_add_text(v_tree, tvb, optoff+5, 5, "Longitude: %15.10f", location.longitude);
proto_tree_add_text(v_tree, tvb, optoff, 1, "Latitude resolution: %15.10f", location.latitude_res);
proto_tree_add_text(v_tree, tvb, optoff+5, 1, "Longitude resolution: %15.10f", location.longitude_res);
proto_tree_add_text(v_tree, tvb, optoff+12, 4, "Altitude: %15.10f", location.altitude);
proto_tree_add_text(v_tree, tvb, optoff+10, 2, "Altitude resolution: %15.10f", location.altitude_res);
proto_tree_add_text(v_tree, tvb, optoff+10, 1, "Altitude type: %s (%d)", val_to_str_const(location.altitude_type, altitude_type_values, "Unknown"), location.altitude_type);
proto_tree_add_text(v_tree, tvb, optoff+15, 1, "Map Datum: %s (%d)", val_to_str_const(location.datum_type, map_datum_type_values, "Unknown"), location.datum_type);
}
} else if (optlen < 69) {
proto_tree_add_item(v_tree, hf_bootp_option_cl_dss_id_option, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_cl_dss_id_len, tvb, optoff+1, 1, ENC_BIG_ENDIAN);
s_len = tvb_get_guint8(tvb, optoff+1);
proto_tree_add_item(v_tree, hf_bootp_option_cl_dss_id, tvb, optoff+2, s_len, ENC_ASCII|ENC_NA);
if (optlen > s_len+2) {
proto_tree_add_item(v_tree, hf_bootp_option_cl_dss_id_option, tvb, optoff+2+s_len, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_cl_dss_id_len, tvb, optoff+1+2+s_len, 1, ENC_BIG_ENDIAN);
s_len = tvb_get_guint8(tvb, optoff+1+2+s_len);
proto_tree_add_item(v_tree, hf_bootp_option_cl_dss_id, tvb, optoff+2+2+s_len, s_len, ENC_ASCII|ENC_NA);
}
} else {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Invalid length of DHCP option!");
}
break;
case 124: {
int data_len;
if (optlen == 1) {
proto_tree_add_item(v_tree, hf_bootp_option_vi_class_cl_address_mode, tvb, optoff, optlen, ENC_BIG_ENDIAN);
break;
}
optleft = optlen;
while (optleft > 0) {
if (optleft < 5) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Vendor Class: malformed option");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_vi_class_enterprise, tvb, optoff, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_vi_class_data_length, tvb, optoff, 1, ENC_BIG_ENDIAN);
data_len = tvb_get_guint8(tvb, optoff + 4);
optoff += 5;
optleft -= 5;
proto_tree_add_item(v_tree, hf_bootp_option_vi_class_data, tvb, optoff, data_len, ENC_ASCII|ENC_NA);
optoff += data_len;
optleft -= data_len;
}
break;
}
case 125: {
int enterprise = 0;
int s_end = 0;
int s_option_len = 0;
proto_tree *e_tree = 0;
optend = optoff + optlen;
optleft = optlen;
while (optleft > 0) {
if (optleft < 5) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL,
PI_ERROR, "Vendor-specific Information: malformed option");
break;
}
enterprise = tvb_get_ntohl(tvb, optoff);
vti = proto_tree_add_item(v_tree, hf_bootp_option125_enterprise, tvb, optoff, 4, ENC_BIG_ENDIAN);
s_option_len = tvb_get_guint8(tvb, optoff + 4);
optoff += 5;
optleft -= 5;
switch (enterprise) {
case 3561:
s_end = optoff + s_option_len;
if ( s_end > optend ) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL,
PI_ERROR, "no room left in option for enterprise %u data", enterprise);
break;
}
e_tree = proto_item_add_subtree(vti, ett_bootp_option);
while (optoff < s_end) {
optoff = dissect_vendor_tr111_suboption(pinfo, vti, e_tree, tvb, optoff, s_end);
}
break;
case 4491:
s_end = optoff + s_option_len;
if ( s_end > optend ) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL,
PI_ERROR, "no room left in option for enterprise %u data", enterprise);
break;
}
e_tree = proto_item_add_subtree(vti, ett_bootp_option);
while (optoff < s_end) {
optoff = dissect_vendor_cl_suboption(pinfo, vti, e_tree, tvb, optoff, s_end);
}
break;
default:
optoff += s_option_len;
}
optleft -= s_option_len;
}
break;
}
case 212: {
if (optlen < 22) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "6RD: malformed option");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_6RD_ipv4_mask_len, tvb, optoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_6RD_prefix_len, tvb, optoff+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_bootp_option_6RD_prefix, tvb, optoff+2, 16, ENC_NA);
proto_tree_add_item(v_tree, hf_bootp_option_6RD_border_relay_ip, tvb, optoff+18, 4, ENC_BIG_ENDIAN);
if (optlen > 22) {
optoff += 22;
for (i = optoff, optleft = optlen - 22; optleft > 0; i += 4, optleft -= 4) {
if (optleft < 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Border Relay length isn't a multiple of 4");
break;
}
proto_tree_add_item(v_tree, hf_bootp_option_6RD_border_relay_ip, tvb, i, 4, ENC_BIG_ENDIAN);
}
}
break;
}
default:
if (code == pkt_ccc_option) {
ftype = special;
proto_item_append_text(vti,
"CableLabs Client Configuration (%d bytes)",
optlen);
optend = optoff + optlen;
while (optoff < optend) {
switch (pkt_ccc_protocol_version) {
case PACKETCABLE_CCC_I05:
optoff = dissect_packetcable_i05_ccc(pinfo, vti, v_tree, tvb, optoff, optend);
break;
case PACKETCABLE_CCC_DRAFT5:
case PACKETCABLE_CCC_RFC_3495:
optoff = dissect_packetcable_ietf_ccc(pinfo, vti, v_tree, tvb, optoff, optend, pkt_ccc_protocol_version);
break;
default:
break;
}
}
} else {
option_handled = FALSE;
}
break;
}
basictype_consumed = bootp_handle_basic_types(pinfo, v_tree, vti, tvb, ftype,
optoff, optlen, opt->phf, &default_hfs);
if ((basictype_consumed == 0) && (option_handled == FALSE) &&
(opt->phf == NULL) && (optlen > 0)) {
proto_tree_add_item(v_tree, hf_bootp_option_value, tvb, voff+2, optlen, ENC_NA);
}
return consumed;
}
static int
bootp_dhcp_decode_agent_info(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree, tvbuff_t *tvb, int optoff,
int optend)
{
int suboptoff = optoff;
guint8 subopt, idx, vs_opt, vs_len;
int subopt_len, subopt_end, datalen;
guint32 enterprise;
proto_item *vti, *ti;
proto_tree *o82_v_tree, *o82_sub_tree;
guint8 tag, tag_len;
struct basic_types_hfs default_hfs = {
&hf_bootp_option82_value,
&hf_bootp_option82_value_ip_address,
&hf_bootp_option82_value_ip_address,
&hf_bootp_option82_value_stringz,
NULL,
&hf_bootp_option82_value_8,
NULL,
NULL,
&hf_bootp_option82_value_32,
NULL,
NULL
};
struct opt82_info {
int id;
struct opt_info info;
};
static struct opt82_info o82_opt[]= {
{0, {"nop", bytes, &hf_bootp_option82_padding}},
{1, {"Agent Circuit ID", bytes, &hf_bootp_option82_agent_circuit_id}},
{2, {"Agent Remote ID", bytes, &hf_bootp_option82_agent_remote_id}},
{3, {"Reserved", bytes, &hf_bootp_option82_reserved}},
{4, {"DOCSIS Device Class", val_u_long, &hf_bootp_option82_docsis_device_class}},
{5, {"Link selection", ipv4, &hf_bootp_option82_link_selection}},
{6, {"Subscriber ID", string, &hf_bootp_option82_subscriber_id}},
{7, {"RADIUS Attributes", bytes, &hf_bootp_option82_radius_attributes}},
{8, {"Authentication", bytes, &hf_bootp_option82_authentication}},
{9, {"Vendor-Specific Information", special, &hf_bootp_option82_vi}},
{10, {"Flags", val_u_byte, &hf_bootp_option82_flags}},
{11, {"Server ID Override", ipv4, &hf_bootp_option82_server_id_override}},
{150, {"Link selection (Cisco proprietary)", ipv4, &hf_bootp_option82_link_selection_cisco}},
{151, {"VRF name/VPN ID", special, &hf_bootp_option82_vrf_name_vpn_id}},
{152, {"Server ID Override (Cisco proprietary)", ipv4, &hf_bootp_option82_server_id_override_cisco}}
};
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option82_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s", subopt, val_to_str_const(subopt, option82_suboption_vals, "Unknown"));
o82_v_tree = proto_item_add_subtree(vti, ett_bootp_option82_suboption);
proto_tree_add_item(o82_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
subopt_end = suboptoff+subopt_len;
if (subopt_end > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption value", subopt);
return (optend);
}
for (idx = 0; idx < array_length(o82_opt); idx++) {
if (o82_opt[idx].id == subopt) {
break;
}
}
ti = proto_tree_add_item(o82_v_tree, hf_bootp_option82_value, tvb, suboptoff, subopt_len, ENC_NA);
if ( (idx >= 1 ) && (idx < array_length(o82_opt)) ) {
PROTO_ITEM_SET_HIDDEN(ti);
if (o82_opt[idx].info.ftype == special) {
switch(subopt)
{
case 9:
while (suboptoff < subopt_end) {
enterprise = tvb_get_ntohl(tvb, suboptoff);
vti = proto_tree_add_item(o82_v_tree, hf_bootp_option82_vi_enterprise, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
suboptoff += 4;
o82_sub_tree = proto_item_add_subtree(vti, ett_bootp_option82_suboption9);
datalen = tvb_get_guint8(tvb, suboptoff);
proto_tree_add_item(o82_sub_tree, hf_bootp_option82_vi_data_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
switch (enterprise) {
case 4491:
vs_opt = tvb_get_guint8(tvb, suboptoff);
proto_tree_add_item(o82_sub_tree, hf_bootp_option82_vi_cl_option, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
vs_len = tvb_get_guint8(tvb, suboptoff);
proto_tree_add_item(o82_sub_tree, hf_bootp_option82_vi_cl_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
switch (vs_opt) {
case 1:
if (vs_len == 4) {
tag = tvb_get_guint8(tvb, suboptoff);
proto_tree_add_item(o82_sub_tree, hf_bootp_option82_vi_cl_tag, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
tag_len = tvb_get_guint8(tvb, suboptoff+1);
proto_tree_add_item(o82_sub_tree, hf_bootp_option82_vi_cl_tag_length, tvb, suboptoff+1, 1, ENC_BIG_ENDIAN);
suboptoff+=2;
if (tag == 1) {
proto_tree_add_uint_format_value(o82_sub_tree, hf_bootp_option82_vi_cl_docsis_version,
tvb, suboptoff, 2, 0, "%d.%d",
tvb_get_guint8(tvb, suboptoff), tvb_get_guint8(tvb, suboptoff+1));
suboptoff+=2;
} else {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Unknown tag %d (%d bytes)", tag, tag_len);
suboptoff += tag_len;
}
} else {
suboptoff += vs_len;
}
break;
default:
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Invalid suboption %d (%d bytes)", vs_opt, vs_len);
suboptoff += vs_len;
break;
}
break;
default:
proto_tree_add_item(o82_v_tree, hf_bootp_option82_value, tvb, suboptoff, datalen, ENC_NA);
suboptoff += datalen;
break;
}
}
break;
case 151:
if (subopt_len != 7) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Invalid length (expected 7 bytes, found %d bytes)", subopt_len);
break;
}
proto_tree_add_item(o82_v_tree, hf_bootp_option82_vrf_name_vpn_id_oui, tvb, suboptoff, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(o82_v_tree, hf_bootp_option82_vrf_name_vpn_id_index, tvb, suboptoff+3, 4, ENC_BIG_ENDIAN);
break;
default:
if (o82_opt[idx].info.phf != NULL)
proto_tree_add_item(o82_v_tree, *o82_opt[idx].info.phf, tvb, suboptoff, subopt_len, ENC_BIG_ENDIAN);
else
proto_tree_add_item(o82_v_tree, hf_bootp_option82_value, tvb, suboptoff, subopt_len, ENC_NA);
break;
}
}
else {
if (bootp_handle_basic_types(pinfo, o82_v_tree, vti, tvb, o82_opt[idx].info.ftype,
suboptoff, subopt_len, o82_opt[idx].info.phf, &default_hfs) == 0) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "ERROR, please report: Unknown subopt type handler %d", subopt);
}
}
}
optoff += (subopt_len + 2);
return optoff;
}
static int
dissect_vendor_pxeclient_suboption(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
guint8 subopt;
guint8 subopt_len;
proto_tree *o43pxeclient_v_tree;
proto_item *vti, *ti;
struct basic_types_hfs default_hfs = {
NULL,
&hf_bootp_option43_value_ip_address,
&hf_bootp_option43_value_ip_address,
NULL,
NULL,
&hf_bootp_option43_value_8,
NULL,
NULL,
NULL,
NULL,
NULL
};
static struct opt_info o43pxeclient_opt[]= {
{"nop", special, &hf_bootp_option43_pxeclient_padding},
{"PXE mtftp IP", ipv4_list, &hf_bootp_option43_pxeclient_mtftp_ip},
{"PXE mtftp client port", val_u_le_short, &hf_bootp_option43_pxeclient_mtftp_client_port},
{"PXE mtftp server port",val_u_le_short, &hf_bootp_option43_pxeclient_mtftp_server_port},
{"PXE mtftp timeout", val_u_byte, &hf_bootp_option43_pxeclient_mtftp_timeout},
{"PXE mtftp delay", val_u_byte, &hf_bootp_option43_pxeclient_mtftp_delay},
{"PXE discovery control", val_u_byte, &hf_bootp_option43_pxeclient_discovery_control},
{"PXE multicast address", ipv4_list, &hf_bootp_option43_pxeclient_multicast_address},
{"PXE boot servers", special, &hf_bootp_option43_pxeclient_boot_servers},
{"PXE boot menu", special, &hf_bootp_option43_pxeclient_boot_menu},
{"PXE menu prompt", special, &hf_bootp_option43_pxeclient_menu_prompt},
{"PXE multicast address alloc", special, &hf_bootp_option43_pxeclient_multicast_address_alloc},
{"PXE credential types", special, &hf_bootp_option43_pxeclient_credential_types}
};
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (subopt == 0) {
proto_tree_add_item(v_tree, hf_bootp_option43_pxeclient_padding, tvb, optoff, 1, ENC_BIG_ENDIAN);
return (suboptoff);
} else if (subopt == 255) {
proto_tree_add_item(v_tree, hf_bootp_option43_pxeclient_end, tvb, optoff, 1, ENC_BIG_ENDIAN);
return (optend);
}
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option43_pxeclient_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s",
subopt, val_to_str_const(subopt, option43_pxeclient_suboption_vals, "Unknown"));
o43pxeclient_v_tree = proto_item_add_subtree(vti, ett_bootp_option43_suboption);
proto_tree_add_item(o43pxeclient_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
ti = proto_tree_add_item(o43pxeclient_v_tree, hf_bootp_option43_value, tvb, suboptoff, subopt_len, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
if ( subopt == 71 ) {
proto_tree_add_item(o43pxeclient_v_tree, hf_bootp_option43_pxeclient_boot_item, tvb, suboptoff, subopt_len, ENC_NA);
} else if ((subopt < 1) || (subopt >= array_length(o43pxeclient_opt))) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Unknown suboption %d (%d bytes)", subopt, subopt_len);
} else if (o43pxeclient_opt[subopt].ftype == special) {
if (o43pxeclient_opt[subopt].phf != NULL)
proto_tree_add_item(o43pxeclient_v_tree, *o43pxeclient_opt[subopt].phf, tvb, suboptoff, subopt_len, ENC_BIG_ENDIAN);
else
proto_tree_add_item(o43pxeclient_v_tree, hf_bootp_option43_value, tvb, suboptoff, subopt_len, ENC_NA);
} else {
if (bootp_handle_basic_types(pinfo, o43pxeclient_v_tree, vti, tvb, o43pxeclient_opt[subopt].ftype,
suboptoff, subopt_len, o43pxeclient_opt[subopt].phf, &default_hfs) == 0)
{
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "ERROR, please report: Unknown subopt type handler %d", subopt);
}
}
optoff += (subopt_len + 2);
return optoff;
}
static void
rfc3825_lci_to_fixpoint(const unsigned char lci[16], struct rfc3825_location_fixpoint_t *fixpoint)
{
fixpoint->latitude_res = (lci[0]>>2) & 0x3F;
if (lci[0] & 2) {
fixpoint->latitude = (((gint64)lci[0] & 3)<<32) | ((gint64)lci[1]<<24) |
((gint64)lci[2]<<16) | ((gint64)lci[3]<<8) |
(gint64)lci[4] | ((gint64)0x3FFFFFFF<<34);
} else {
fixpoint->latitude = (((gint64)lci[0] & 3)<<32) | ((gint64)lci[1]<<24) |
((gint64)lci[2]<<16) | ((gint64)lci[3]<<8) |
(gint64)lci[4];
}
fixpoint->longitude_res = (lci[5]>>2) & 0x3F;
if (lci[5] & 2) {
fixpoint->longitude = (((gint64)lci[5] & 3)<<32) | ((gint64)lci[6]<<24) |
((gint64)lci[7]<<16) | ((gint64)lci[8]<<8) |
(gint64)lci[9] | ((gint64)0x3FFFFFFF<<34);
} else {
fixpoint->longitude = (((gint64)lci[5] & 3)<<32) | ((gint64)lci[6]<<24) |
((gint64)lci[7]<<16) | ((gint64)lci[8]<<8) |
(gint64)lci[9];
}
fixpoint->altitude_type = (lci[10]>>4) & 0x0F;
fixpoint->altitude_res = ((lci[10] & 0x0F) << 2) | ((lci[11]>>6) & 0x03);
if (lci[11] & 0x20) {
fixpoint->altitude = (((gint32)lci[11] & 0x3F)<<24) | ((gint32)lci[12]<<16) |
((gint32)lci[13]<<8) | ((gint32)lci[14]) |
((gint32)0x03<<30);
} else {
fixpoint->altitude = (((gint32)lci[11] & 0x3F)<<24) | ((gint32)lci[12]<<16) |
((gint32)lci[13]<<8) | ((gint32)lci[14]);
}
fixpoint->datum_type = lci[15];
}
static int
rfc3825_fixpoint_to_decimal(struct rfc3825_location_fixpoint_t *fixpoint, struct rfc3825_location_decimal_t *decimal)
{
decimal->latitude = (double) fixpoint->latitude / (1 << 25);
if ((decimal->latitude > 90) || (decimal->latitude < -90)) {
return RFC3825_LATITUDE_OUTOFRANGE;
}
if (fixpoint->latitude_res > 34) {
return RFC3825_LATITUDE_UNCERTAINTY_OUTOFRANGE;
}
if (fixpoint->latitude_res > 8 ) {
decimal->latitude_res = (double) 1 / (1 << (fixpoint->latitude_res - 8));
} else {
decimal->latitude_res = 1 << (8 - fixpoint->latitude_res);
}
decimal->longitude = (double) fixpoint->longitude / (1 << 25);
if ((decimal->longitude > 180) || (decimal->longitude < -180)) {
return RFC3825_LONGITUDE_OUTOFRANGE;
}
if (fixpoint->longitude_res > 34) {
return RFC3825_LONGITUDE_UNCERTAINTY_OUTOFRANGE;
}
if (fixpoint->longitude_res > 8 ) {
decimal->longitude_res = (double) 1 / (1 << (fixpoint->longitude_res - 8));
} else {
decimal->longitude_res = 1 << (8 - fixpoint->longitude_res);
}
decimal->altitude_type = fixpoint->altitude_type;
decimal->altitude = 0;
decimal->altitude_res = 0;
if (decimal->altitude_type == 0) {
} else if (decimal->altitude_type == 1) {
decimal->altitude = (double) fixpoint->altitude / (1 << 8);
if ((decimal->altitude > ((gint32) 1<<21)-1) || (decimal->altitude < ((gint32) -(1<<21))))
return RFC3825_ALTITUDE_OUTOFRANGE;
if (fixpoint->altitude_res > 30) {
return RFC3825_ALTITUDE_UNCERTAINTY_OUTOFRANGE;
}
if (fixpoint->altitude_res > 21 ) {
decimal->altitude_res = (double) 1 / (1 << (fixpoint->altitude_res - 21));
} else {
decimal->altitude_res = 1 << (21 - fixpoint->altitude_res);
}
} else if (decimal->altitude_type == 2) {
if ((fixpoint->altitude_res != 30) && (fixpoint->altitude_res != 0)) {
return RFC3825_ALTITUDE_UNCERTAINTY_OUTOFRANGE;
}
decimal->altitude = (double) fixpoint->altitude / (1 << 8);
} else {
return RFC3825_ALTITUDE_TYPE_OUTOFRANGE;
}
decimal->datum_type = 0;
if ((fixpoint->datum_type > 3) || (fixpoint->datum_type < 1)) {
return RFC3825_DATUM_TYPE_OUTOFRANGE;
}
decimal->datum_type = fixpoint->datum_type;
return RFC3825_NOERROR;
}
static int
dissect_vendor_cablelabs_suboption(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
guint8 subopt;
guint8 subopt_len;
proto_tree *o43cl_v_tree;
proto_item *vti;
struct basic_types_hfs default_hfs = {
&hf_bootp_option43_value,
NULL,
NULL,
&hf_bootp_option43_value_stringz,
NULL,
&hf_bootp_option43_value_8,
NULL,
NULL,
&hf_bootp_option43_value_32,
NULL,
NULL
};
static struct opt_info o43cablelabs_opt[]= {
{"nop", special, &hf_bootp_option43_cl_padding},
{"Suboption Request List", string, &hf_bootp_option43_cl_suboption_request_list},
{"Device Type", string, &hf_bootp_option43_cl_device_type},
{"eSAFE Types", string, &hf_bootp_option43_cl_esafe_type},
{"Serial Number", string, &hf_bootp_option43_cl_serial_number},
{"Hardware Version", string, &hf_bootp_option43_cl_hardware_version},
{"Software Version", string, &hf_bootp_option43_cl_software_version},
{"Boot ROM version", string, &hf_bootp_option43_cl_boot_rom_version},
{"Organizationally Unique Identifier", special, &hf_bootp_option43_cl_oui_bytes},
{"Model Number", string, &hf_bootp_option43_cl_model_number},
{"Vendor Name", string, &hf_bootp_option43_cl_vendor_name10},
{"Address Realm", val_u_byte, &hf_bootp_option43_cl_address_realm},
{"CM/PS System Description", string, &hf_bootp_option43_cl_cm_ps_system_desc},
{"CM/PS Firmware Revision", string, &hf_bootp_option43_cl_cm_ps_firmware_revision},
{"Firewall Policy File Version", string, &hf_bootp_option43_cl_firewall_policy_file_version},
{"eSafe Config File Devices", string, &hf_bootp_option43_cl_esafe_config_file_devices},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Video Security Type", string, &hf_bootp_option43_cl_video_security_tape},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"Unassigned (CableHome)", special, NULL},
{"MTA MAC Address", special, &hf_bootp_option43_cl_mta_mac_address},
{"Correlation ID", val_u_long, &hf_bootp_option43_cl_correlation_ID},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Unassigned (PacketCable)", special, NULL},
{"Vendor Name", string, &hf_bootp_option43_cl_vendor_name51},
{"CableCARD Capability", special, &hf_bootp_option43_cl_cablecard_capability},
{"Device Identification (CA)", special, &hf_bootp_option43_cl_device_id_ca},
{"Device Identification (X.509)", string, &hf_bootp_option43_cl_device_id_x509},
{"Unassigned (CableLabs)", special, NULL},
};
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (subopt == 0) {
proto_tree_add_item(v_tree, hf_bootp_option43_cl_padding, tvb, optoff, 1, ENC_BIG_ENDIAN);
return (suboptoff);
} else if (subopt == 255) {
proto_tree_add_item(v_tree, hf_bootp_option43_cl_end, tvb, optoff, 1, ENC_BIG_ENDIAN);
return (optend);
}
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option43_cl_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s",
subopt, val_to_str_const(subopt, option43_cl_suboption_vals, "Unknown"));
o43cl_v_tree = proto_item_add_subtree(vti, ett_bootp_option43_suboption);
proto_tree_add_item(o43cl_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
if (suboptoff+subopt_len > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Suboption %d: no room left in option for suboption value", subopt);
return (optend);
}
if ( (subopt < 1 ) || (subopt >= array_length(o43cablelabs_opt)) ) {
proto_tree_add_item(o43cl_v_tree, hf_bootp_option43_value, tvb, suboptoff, subopt_len, ENC_NA);
} else if (o43cablelabs_opt[subopt].ftype == special) {
switch(subopt)
{
case 8:
if (subopt_len == 3) {
proto_tree_add_bytes_format_value(o43cl_v_tree, hf_bootp_option43_cl_oui_bytes, tvb, suboptoff, subopt_len, NULL,
"%02x:%02x:%02x", tvb_get_guint8(tvb, suboptoff), tvb_get_guint8(tvb, suboptoff+1), tvb_get_guint8(tvb, suboptoff+2));
} else if (subopt_len == 6) {
proto_tree_add_item(o43cl_v_tree, hf_bootp_option43_cl_oui_string, tvb, suboptoff, subopt_len, ENC_ASCII|ENC_NA);
} else {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't 3 or 6");
}
break;
case 31:
if (subopt_len != 6) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't 6");
break;
}
proto_tree_add_item(o43cl_v_tree, hf_bootp_option43_cl_mta_mac_address, tvb, suboptoff, 6, ENC_NA);
break;
default:
if (o43cablelabs_opt[subopt].phf != NULL)
proto_tree_add_item(o43cl_v_tree, *o43cablelabs_opt[subopt].phf, tvb, suboptoff, subopt_len, ENC_BIG_ENDIAN);
else
proto_tree_add_item(o43cl_v_tree, hf_bootp_option43_value, tvb, suboptoff, subopt_len, ENC_NA);
}
}
else {
if (bootp_handle_basic_types(pinfo, o43cl_v_tree, vti, tvb, o43cablelabs_opt[subopt].ftype,
suboptoff, subopt_len, o43cablelabs_opt[subopt].phf, &default_hfs) == 0) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "ERROR, please report: Unknown subopt type handler %d", subopt);
}
}
optoff += (subopt_len + 2);
return optoff;
}
static int
dissect_vendor_alcatel_suboption(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
guint8 subopt;
guint8 subopt_len;
proto_item *vti;
proto_tree *o43alcatel_v_tree;
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (subopt == 0) {
proto_tree_add_item(v_tree, hf_bootp_option43_alcatel_padding, tvb, optoff, 1, ENC_BIG_ENDIAN);
return (suboptoff);
} else if (subopt == 255) {
proto_tree_add_item(v_tree, hf_bootp_option43_alcatel_end, tvb, optoff, 1, ENC_BIG_ENDIAN);
return (optend);
}
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option43_alcatel_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s",
subopt, val_to_str_const(subopt, option43_alcatel_suboption_vals, "Unknown"));
o43alcatel_v_tree = proto_item_add_subtree(vti, ett_bootp_option43_suboption);
proto_tree_add_item(o43alcatel_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
if (suboptoff+subopt_len > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "Suboption %d: no room left in option for suboption value", subopt);
return (optend);
}
switch (subopt)
{
case 58:
if (subopt_len != 2) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't 2");
return (optend);
}
proto_tree_add_item(o43alcatel_v_tree, hf_bootp_option43_alcatel_vlan_id, tvb, suboptoff, 2, ENC_BIG_ENDIAN);
break;
case 64:
if (subopt_len != 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't 4");
return (optend);
}
proto_tree_add_item(o43alcatel_v_tree, hf_bootp_option43_alcatel_tftp1, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
break;
case 65:
if (subopt_len != 4) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't 4");
return (optend);
}
proto_tree_add_item(o43alcatel_v_tree, hf_bootp_option43_alcatel_tftp2, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
break;
case 66:
if (subopt_len != 1) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "length isn't 1");
return (optend);
}
proto_tree_add_item(o43alcatel_v_tree, hf_bootp_option43_alcatel_app_type, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
break;
case 67:
proto_tree_add_item(o43alcatel_v_tree, hf_bootp_option43_alcatel_sip_url, tvb, suboptoff, subopt_len, ENC_ASCII|ENC_NA);
break;
default:
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "ERROR, please report: Unknown subopt type handler %d", subopt);
return optend;
}
optoff += (subopt_len + 2);
return optoff;
}
static int
dissect_netware_ip_suboption(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
guint8 subopt, subopt_len;
proto_tree *o63_v_tree;
proto_item *vti, *ti;
struct basic_types_hfs default_hfs = {
NULL,
&hf_bootp_option63_value_ip_address,
&hf_bootp_option63_value_ip_address,
NULL,
&hf_bootp_option63_value_boolean,
&hf_bootp_option63_value_8,
NULL,
NULL,
NULL,
NULL,
NULL
};
static struct opt_info o63_opt[]= {
{"",none,NULL},
{"NWIP does not exist on subnet",presence,NULL},
{"NWIP exists in options area",presence,NULL},
{"NWIP exists in sname/file",presence,NULL},
{"NWIP exists, but too big",presence,NULL},
{"Broadcast for nearest Netware server",val_boolean, &hf_bootp_option63_broadcast},
{"Preferred DSS server",ipv4_list,&hf_bootp_option63_preferred_dss_server},
{"Nearest NWIP server",ipv4_list,&hf_bootp_option63_nearest_nwip_server},
{"Autoretries",val_u_byte,&hf_bootp_option63_autoretries},
{"Autoretry delay, secs",val_u_byte,&hf_bootp_option63_autoretry_delay},
{"Support NetWare/IP v1.1",val_boolean,&hf_bootp_option63_support_netware_v1_1},
{"Primary DSS",ipv4,&hf_bootp_option63_primary_dss}
};
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option63_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s",
subopt, val_to_str_const(subopt, option63_suboption_vals, "Unknown"));
o63_v_tree = proto_item_add_subtree(vti, ett_bootp_option63_suboption);
proto_tree_add_item(o63_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
ti = proto_tree_add_item(o63_v_tree, hf_bootp_option63_value, tvb, suboptoff, subopt_len, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
if (subopt < array_length(o63_opt)) {
if (bootp_handle_basic_types(pinfo, o63_v_tree, vti, tvb, o63_opt[subopt].ftype,
suboptoff, subopt_len, o63_opt[subopt].phf, &default_hfs) == 0) {
switch(o63_opt[subopt].ftype)
{
case presence:
if (subopt_len != 0) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: length isn't 0", subopt);
}
break;
default:
if (o63_opt[subopt].phf == NULL)
proto_tree_add_item(o63_v_tree, hf_bootp_option63_value, tvb, suboptoff, subopt_len, ENC_NA);
break;
}
}
}
optoff += (subopt_len + 2);
return optoff;
}
static int
dissect_vendor_tr111_suboption(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
proto_tree *o125_v_tree;
proto_item *vti, *ti;
guint8 subopt, subopt_len;
struct basic_types_hfs default_hfs = {
NULL,
NULL,
NULL,
&hf_bootp_option125_value_stringz,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL
};
static struct opt_info o125_tr111_opt[]= {
{"nop", special, NULL},
{"DeviceManufacturerOUI", string, &hf_bootp_option125_tr111_device_manufacturer_oui},
{"DeviceSerialNumber", string, &hf_bootp_option125_tr111_device_serial_number},
{"DeviceProductClass", string, &hf_bootp_option125_tr111_device_product_class},
{"GatewayManufacturerOUI", string, &hf_bootp_option125_tr111_gateway_manufacturer_oui},
{"GatewaySerialNumber", string, &hf_bootp_option125_tr111_gateway_serial_number},
{"GatewayProductClass", string, &hf_bootp_option125_tr111_gateway_product_class},
};
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option125_tr111_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s",
subopt, val_to_str_const(subopt, option125_tr111_suboption_vals, "Unknown"));
o125_v_tree = proto_item_add_subtree(vti, hf_bootp_option125_tr111_suboption);
proto_tree_add_item(o125_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
if (suboptoff+subopt_len > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption value", subopt);
return (optend);
}
ti = proto_tree_add_item(v_tree, hf_bootp_option125_value, tvb, suboptoff, subopt_len, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
if (subopt < array_length(o125_tr111_opt)) {
if (bootp_handle_basic_types(pinfo, o125_v_tree, vti, tvb, o125_tr111_opt[subopt].ftype,
suboptoff, subopt_len, o125_tr111_opt[subopt].phf, &default_hfs) == 0) {
if (o125_tr111_opt[subopt].ftype == special) {
if (o125_tr111_opt[subopt].phf != NULL)
proto_tree_add_item(v_tree, *o125_tr111_opt[subopt].phf, tvb, suboptoff, subopt_len, ENC_BIG_ENDIAN);
else
proto_tree_add_item(v_tree, hf_bootp_option125_value, tvb, suboptoff, subopt_len, ENC_NA);
} else if (o125_tr111_opt[subopt].phf == NULL)
proto_tree_add_item(v_tree, hf_bootp_option125_value, tvb, suboptoff, subopt_len, ENC_NA);
}
}
optoff += (subopt_len + 2);
return optoff;
}
static int
dissect_vendor_cl_suboption(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
guint8 subopt, subopt_len;
proto_tree *o125_v_tree;
proto_item *vti;
struct basic_types_hfs default_hfs = {
&hf_bootp_option125_value,
&hf_bootp_option125_value_ip_address,
&hf_bootp_option125_value_ip_address,
&hf_bootp_option125_value_stringz,
NULL,
&hf_bootp_option125_value_8,
&hf_bootp_option125_value_16,
NULL,
NULL,
NULL,
NULL
};
static struct opt_info o125_cl_opt[]= {
{"nop", special, NULL},
{"Option Request = ", val_u_byte, &hf_bootp_option125_cl_option_request},
{"TFTP Server Addresses : ", ipv4_list, &hf_bootp_option125_cl_tftp_server_addresses},
{"eRouter Container Option : ", bytes, &hf_bootp_option125_cl_erouter_container_option},
{"MIB Environment Indicator Option = ", val_u_byte, &hf_bootp_option125_cl_mib_environment_indicator_option},
{"Modem Capabilities : ", special, &hf_bootp_option125_cl_modem_capabilities},
};
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
vti = proto_tree_add_uint_format_value(v_tree, hf_bootp_option125_cl_suboption,
tvb, optoff, subopt_len+2, subopt, "(%d) %s",
subopt, val_to_str_const(subopt, option125_cl_suboption_vals, "Unknown"));
o125_v_tree = proto_item_add_subtree(vti, hf_bootp_option125_cl_suboption);
proto_tree_add_item(o125_v_tree, hf_bootp_suboption_length, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
suboptoff++;
if (suboptoff+subopt_len > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption value", subopt);
return (optend);
}
if (subopt < array_length(o125_cl_opt)) {
if (bootp_handle_basic_types(pinfo, o125_v_tree, vti, tvb, o125_cl_opt[subopt].ftype,
suboptoff, subopt_len, o125_cl_opt[subopt].phf, &default_hfs) == 0) {
switch(o125_cl_opt[subopt].ftype) {
case special:
if (o125_cl_opt[subopt].phf != NULL)
proto_tree_add_item(o125_v_tree, *o125_cl_opt[subopt].phf, tvb, suboptoff, subopt_len, ENC_BIG_ENDIAN);
else
proto_tree_add_item(o125_v_tree, hf_bootp_option125_value, tvb, suboptoff, subopt_len, ENC_NA);
dissect_docsis_cm_cap(o125_v_tree, tvb, optoff, subopt_len+2, TRUE);
break;
default:
if (o125_cl_opt[subopt].phf == NULL)
proto_tree_add_item(o125_v_tree, hf_bootp_option125_value, tvb, suboptoff, subopt_len, ENC_NA);
break;
}
}
}
optoff += (subopt_len + 2);
return optoff;
}
static void
dissect_packetcable_mta_cap(proto_tree *v_tree, tvbuff_t *tvb, int voff, int len)
{
guint16 raw_val;
unsigned long flow_val = 0;
int off = PKT_MDC_TLV_OFF + voff;
int subopt_off, max_len;
guint tlv_len, i, mib_val;
guint8 asc_val[3] = " ", flow_val_str[5];
char bit_fld[64];
proto_item *ti, *mib_ti;
proto_tree *subtree, *subtree2;
tvb_memcpy (tvb, asc_val, off, 2);
if (sscanf((gchar*)asc_val, "%x", &tlv_len) != 1 || tlv_len > 0xff) {
proto_tree_add_text(v_tree, tvb, off, len - off,
"Bogus length: %s", asc_val);
return;
} else {
proto_tree_add_uint_format_value(v_tree, hf_bootp_pkt_mta_cap_len, tvb, off, 2,
tlv_len, "%d", tlv_len);
off += 2;
while (off - voff < len) {
raw_val = tvb_get_ntohs (tvb, off);
tvb_memcpy(tvb, asc_val, off + 2, 2);
if (sscanf((gchar*)asc_val, "%x", &tlv_len) != 1
|| tlv_len < 1 || tlv_len > G_MAXUINT16) {
proto_tree_add_text(v_tree, tvb, off, len - off,
"[Bogus length: %s]", asc_val);
return;
} else {
ti = proto_tree_add_text(v_tree,
tvb, off, (tlv_len * 2) + 4,
"0x%s: %s = ",
tvb_format_text(tvb, off, 2),
val_to_str_const(raw_val, pkt_mdc_type_vals, "unknown"));
switch (raw_val) {
case PKT_MDC_VERSION:
raw_val = tvb_get_ntohs(tvb, off + 4);
proto_item_append_text(ti,
"%s (%s)",
val_to_str_const(raw_val, pkt_mdc_version_vals, "Reserved"),
tvb_format_stringzpad(tvb, off + 4, 2) );
break;
case PKT_MDC_TEL_END:
case PKT_MDC_IF_INDEX:
proto_item_append_text(ti,
"%s",
tvb_format_stringzpad(tvb, off + 4, 2) );
break;
case PKT_MDC_TGT:
case PKT_MDC_HTTP_ACC:
case PKT_MDC_SYSLOG:
case PKT_MDC_NCS:
case PKT_MDC_PRI_LINE:
case PKT_MDC_NVRAM_STOR:
case PKT_MDC_PROV_REP:
case PKT_MDC_PROV_REP_LC:
case PKT_MDC_SILENCE:
case PKT_MDC_SILENCE_LC:
case PKT_MDC_ECHO_CANCEL:
case PKT_MDC_ECHO_CANCEL_LC:
case PKT_MDC_RSVP:
case PKT_MDC_RSVP_LC:
case PKT_MDC_UGS_AD:
case PKT_MDC_UGS_AD_LC:
case PKT_MDC_FLOW_LOG:
case PKT_MDC_RFC2833_DTMF:
case PKT_MDC_VOICE_METRICS:
case PKT_MDC_MGPI:
case PKT_MDC_V152:
case PKT_MDC_CBS:
case PKT_MDC_CBS_LC:
raw_val = tvb_get_ntohs(tvb, off + 4);
proto_item_append_text(ti,
"%s (%s)",
val_to_str_const(raw_val, pkt_mdc_boolean_vals, "unknown"),
tvb_format_stringzpad(tvb, off + 4, 2) );
break;
case PKT_MDC_SUPP_CODECS:
case PKT_MDC_SUPP_CODECS_LC:
for (i = 0; i < tlv_len; i++) {
raw_val = tvb_get_ntohs(tvb, off + 4 + (i * 2) );
proto_item_append_text(ti,
"%s%s (%s)",
plurality(i + 1, "", ", "),
val_to_str_const(raw_val, pkt_mdc_codec_vals, "unknown"),
tvb_format_stringzpad(tvb, off + 4 + (i * 2), 2) );
}
break;
case PKT_MDC_PROV_FLOWS:
tvb_memcpy(tvb, flow_val_str, off + 4, 4);
flow_val_str[4] = '\0';
flow_val = strtoul((gchar*)flow_val_str, NULL, 16);
proto_item_append_text(ti,
"0x%04lx", flow_val);
break;
case PKT_MDC_T38_VERSION:
raw_val = tvb_get_ntohs(tvb, off + 4);
proto_item_append_text(ti,
"%s (%s)",
val_to_str_const(raw_val, pkt_mdc_t38_version_vals, "unknown"),
tvb_format_stringzpad(tvb, off + 4, 2) );
break;
case PKT_MDC_T38_EC:
raw_val = tvb_get_ntohs(tvb, off + 4);
proto_item_append_text(ti,
"%s (%s)",
val_to_str_const(raw_val, pkt_mdc_t38_ec_vals, "unknown"),
tvb_format_stringzpad(tvb, off + 4, 2) );
break;
case PKT_MDC_MIBS:
break;
case PKT_MDC_VENDOR_TLV:
default:
proto_item_append_text(ti,
"%s",
tvb_format_stringzpad(tvb, off + 4, tlv_len * 2) );
break;
}
}
subtree = proto_item_add_subtree(ti, ett_bootp_option);
if (raw_val == PKT_MDC_PROV_FLOWS) {
for (i = 0 ; i < 3; i++) {
if (flow_val & pkt_mdc_supp_flow_vals[i].value) {
decode_bitfield_value(bit_fld, (guint32)flow_val, pkt_mdc_supp_flow_vals[i].value, 16);
proto_tree_add_text(subtree, tvb, off + 4, 4, "%s%s",
bit_fld, pkt_mdc_supp_flow_vals[i].strptr);
}
}
} else if (raw_val == PKT_MDC_MIBS) {
subopt_off = off + 4;
max_len = subopt_off + (tlv_len * 2);
while (subopt_off < max_len) {
raw_val = tvb_get_ntohs(tvb, subopt_off);
if (raw_val != 0x3032) {
tvb_memcpy(tvb, asc_val, subopt_off, 2);
proto_tree_add_text(subtree, tvb, subopt_off, 2,
"[Bogus length: %s]", asc_val);
return;
}
subopt_off += 2;
raw_val = tvb_get_ntohs(tvb, subopt_off);
tvb_memcpy(tvb, asc_val, subopt_off, 2);
mib_ti = proto_tree_add_text(subtree, tvb, subopt_off, 2, "%s (%s)",
val_to_str_const(raw_val, pkt_mdc_mib_orgs, "Unknown"), asc_val);
if (subopt_off > off + 4 + 2) {
proto_item_append_text(ti, ", ");
}
proto_item_append_text(ti, "%s", val_to_str_const(raw_val, pkt_mdc_mib_orgs, "Unknown"));
subopt_off += 2;
tvb_memcpy(tvb, asc_val, subopt_off, 2);
if (sscanf((gchar*)asc_val, "%x", &mib_val) != 1) {
proto_tree_add_text(v_tree, tvb, subopt_off, 2,
"[Bogus bitfield: %s]", asc_val);
return;
}
switch (raw_val) {
case PKT_MDC_MIB_CL:
subtree2 = proto_item_add_subtree(mib_ti, ett_bootp_option);
for (i = 0; i < 8; i++) {
if (mib_val & pkt_mdc_cl_mib_vals[i].value) {
decode_bitfield_value(bit_fld, mib_val, pkt_mdc_cl_mib_vals[i].value, 8);
proto_tree_add_text(subtree2, tvb, subopt_off, 2,
"%s%s", bit_fld, pkt_mdc_cl_mib_vals[i].strptr);
}
}
break;
case PKT_MDC_MIB_IETF:
subtree2 = proto_item_add_subtree(mib_ti, ett_bootp_option);
for (i = 0; i < 8; i++) {
if (mib_val & pkt_mdc_ietf_mib_vals[i].value) {
decode_bitfield_value(bit_fld, mib_val, pkt_mdc_ietf_mib_vals[i].value, 8);
proto_tree_add_text(subtree2, tvb, subopt_off, 2,
"%s%s", bit_fld, pkt_mdc_ietf_mib_vals[i].strptr);
}
}
break;
case PKT_MDC_MIB_EURO:
subtree2 = proto_item_add_subtree(mib_ti, ett_bootp_option);
for (i = 0; i < 8; i++) {
if (mib_val & pkt_mdc_euro_mib_vals[i].value) {
decode_bitfield_value(bit_fld, mib_val, pkt_mdc_euro_mib_vals[i].value, 8);
proto_tree_add_text(subtree2, tvb, subopt_off, 2,
"%s%s", bit_fld, pkt_mdc_euro_mib_vals[i].strptr);
}
}
break;
default:
break;
}
subopt_off += 2;
}
}
off += (tlv_len * 2) + 4;
}
}
}
static void
display_uint_with_range_checking(proto_item *ti, guint8 val_byte, guint16 val_uint16, int min_value, int max_value)
{
guint16 value;
if (0 != val_byte)
{
value = val_byte;
}
else
{
value = val_uint16;
}
proto_item_append_text(ti, "%i", value);
if ((value < min_value) ||
(value > max_value))
{
proto_item_append_text(ti, " (Value Out-of-Range [%i..%i])", min_value, max_value);
}
}
static void get_opt125_tlv(tvbuff_t *tvb, guint off, guint8 *tlvtype, guint8 *tlvlen, guint8 **value)
{
*tlvtype = tvb_get_guint8(tvb, off);
*tlvlen = tvb_get_guint8(tvb, off+1);
*value = (guint8 *)ep_tvb_memdup(tvb, off + 2, *tlvlen);
}
static void get_opt60_tlv(tvbuff_t *tvb, guint off, guint8 *tlvtype, guint8 *tlvlen, guint8 **value)
{
guint i;
guint8 *val_asc;
val_asc = (guint8 *)ep_alloc0(4);
tvb_memcpy(tvb, val_asc, off, 2);
*tlvtype = (guint8)strtoul((gchar*)val_asc, NULL, 16);
tvb_memcpy(tvb, val_asc, off + 2, 2);
*tlvlen = (guint8)strtoul((gchar*)val_asc, NULL, 16);
*value = (guint8 *)ep_alloc0(*tlvlen);
for (i=0; i<*tlvlen; i++)
{
memset(val_asc, 0, 4);
tvb_memcpy(tvb, val_asc, off + ((i*2) + 4), 2);
(*value)[i] = (guint8)strtoul((gchar*)val_asc, NULL, 16);
}
}
static void
dissect_docsis_cm_cap(proto_tree *v_tree, tvbuff_t *tvb, int voff, int len, gboolean opt125)
{
guint8 *asc_val;
guint i;
proto_item *ti;
proto_tree *subtree;
char bit_fld[64];
guint8 tlv_type;
guint8 tlv_len;
guint8 val_byte = 0;
guint16 val_uint16 = 0;
guint8 *val_other = NULL;
guint off = voff;
asc_val = (guint8*)ep_alloc0(4);
if (opt125)
{
tlv_type = tvb_get_guint8(tvb, off);
tlv_len = tvb_get_guint8(tvb, off+1);
proto_tree_add_uint_format_value(v_tree, hf_bootp_docsis_cm_cap_len, tvb, off+1, 1,
tlv_len, "%d", tlv_len);
}
else
{
off += DOCSIS_CM_CAP_TLV_OFF;
tvb_memcpy (tvb, asc_val, off, 2);
tlv_len = (guint8)strtoul((gchar*)asc_val, NULL, 16);
proto_tree_add_uint_format_value(v_tree, hf_bootp_docsis_cm_cap_len, tvb, off+2, 2,
tlv_len, "%d", tlv_len);
}
off+=2;
while (off - ((guint) voff) < ((guint) len))
{
tlv_type = 0;
tlv_len = 0;
val_byte = 0;
val_uint16 = 0;
if (opt125)
{
get_opt125_tlv(tvb, off, &tlv_type, &tlv_len, &val_other);
ti = proto_tree_add_uint_format(v_tree, hf_bootp_docsis_cm_cap_type, tvb, off,
tlv_len + 2,
tlv_type,
"0x%02x: %s = ",
tlv_type,
val_to_str_const(tlv_type, docsis_cm_cap_type_vals, "unknown"));
}
else
{
get_opt60_tlv(tvb, off, &tlv_type, &tlv_len, &val_other);
ti = proto_tree_add_uint_format(v_tree, hf_bootp_docsis_cm_cap_type, tvb, off,
(tlv_len * 2) + 4,
tlv_type,
"0x%02x: %s = ",
tlv_type,
val_to_str_const(tlv_type, docsis_cm_cap_type_vals, "unknown"));
}
if (tlv_len == 1)
{
val_byte = val_other[0];
}
else
{
if (tlv_len == 2)
{
val_uint16 = (val_other[0] << 8) + val_other[1];
}
}
switch (tlv_type)
{
case DOCSIS_CM_CAP_CONCAT_SUP:
case DOCSIS_CM_CAP_FRAG_SUP:
case DOCSIS_CM_CAP_PHS_SUP:
case DOCSIS_CM_CAP_IGMP_SUP:
case DOCSIS_CM_CAP_DCC_SUP:
case DOCSIS_CM_CAP_EXPUNI_SPACE:
case DOCSIS_CM_CAP_DUTFILT_SUP:
case DOCSIS_CM_CAP_SACM2_SUP:
case DOCSIS_CM_CAP_SACM2HOP_SUP:
case DOCSIS_CM_CAP_IPV6_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_supported_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_DOCSIS_VER:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_version_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_PRIV_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_privacy_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_FILT_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_filt_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_L2VPN_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_l2vpn_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_L2VPN_HOST_SUP:
if (tlv_len == 7) {
proto_item_append_text(ti,
"eSAFE ifIndex %s (%i)/eSAFE MAC %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x",
val_to_str_const(val_other[0], docsis_cm_cap_map_l2vpn_esafe_index_support_vals, "Reserved"),
val_other[0],
val_other[1],
val_other[2],
val_other[3],
val_other[4],
val_other[5],
val_other[6]);
} else {
proto_item_append_text(ti,
"Invalid (length should be 7, is %d)",
tlv_len);
}
break;
case DOCSIS_CM_CAP_USFREQRNG_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_usfreqrng_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_MAPUCDRECEIPT_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_map_ucd_receipt_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_DPV_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_map_dpv_support_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_DSAID_SUP:
case DOCSIS_CM_CAP_MULTTXCHAN_SUP:
case DOCSIS_CM_CAP_512USTXCHAN_SUP:
case DOCSIS_CM_CAP_256USTXCHAN_SUP:
case DOCSIS_CM_CAP_TOTALSIDCLU_SUP:
case DOCSIS_CM_CAP_MULTRXCHAN_SUP:
case DOCSIS_CM_CAP_UGSPERUSFLOW_SUP:
case DOCSIS_CM_CAP_USSF_SUP:
display_uint_with_range_checking(ti, val_byte, val_uint16, 0, 255);
break;
case DOCSIS_CM_CAP_RESEQDSID_SUP:
case DOCSIS_CM_CAP_MULTDSID_SUP:
display_uint_with_range_checking(ti, val_byte, val_uint16, 16, 255);
break;
case DOCSIS_CM_CAP_SIDCLUPERSF_SUP:
display_uint_with_range_checking(ti, val_byte, val_uint16, 2, 8);
break;
case DOCSIS_CM_CAP_TOTALDSID_SUP:
display_uint_with_range_checking(ti, val_byte, val_uint16, 32, 255);
break;
case DOCSIS_CM_CAP_TET:
display_uint_with_range_checking(ti, val_byte, val_uint16, 8, 64);
break;
case DOCSIS_CM_CAP_TET_MI:
if ((val_byte == 1) ||
(val_byte == 2) ||
(val_byte == 4))
{
proto_item_append_text(ti,
" %i",
val_byte);
}
else
{
proto_item_append_text(ti,
" (Invalid Value %i : Should be [1,2,4]",
val_byte);
}
break;
case DOCSIS_CM_CAP_IPFILT_SUP:
case DOCSIS_CM_CAP_USDROPCLASSIF_SUP:
display_uint_with_range_checking(ti, val_byte, val_uint16, 64, 65535);
break;
case DOCSIS_CM_CAP_LLCFILT_SUP:
display_uint_with_range_checking(ti, val_byte, val_uint16, 10, 65535);
break;
case DOCSIS_CM_CAP_ExUsTrPow:
if (val_byte == 0)
{
proto_item_append_text(ti, "%i", val_byte);
}
else
{
display_uint_with_range_checking(ti, val_byte, val_uint16, 205, 244);
}
break;
case DOCSIS_CM_CAP_Opt802MPLSSup:
proto_item_append_text(ti,
"0x%02x", val_byte);
case DOCSIS_CM_CAP_DounEnc:
break;
case DOCSIS_CM_CAP_EnrgMang:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_enrgmang_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_RNGHLDOFF_SUP:
proto_item_append_text(ti,
"Ranging ID ");
proto_item_append_text(ti,
"(0x%04x)", (val_other[0] << sizeof(guint8)) + val_other[1]);
proto_item_append_text(ti,
" Component Bit Mask ");
proto_item_append_text(ti,
"(0x%04x)", (val_other[2] << sizeof(guint8)) + val_other[3]);
break;
case DOCSIS_CM_CAP_USSYMRATE_SUP:
proto_item_append_text(ti,
"0x%02x", val_byte);
break;
case DOCSIS_CM_CAP_FCTF_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_map_fctfc_support_vals, "Reserved"));
break;
case DOCSIS_CM_CAP_MULTDSIDFW_SUP:
proto_item_append_text(ti,
"%s",
val_to_str_const(val_byte, docsis_cm_cap_map_multDsidForward_support_vals, "Reserved"));
break;
}
subtree = proto_item_add_subtree(ti, ett_bootp_option);
if (tlv_type == DOCSIS_CM_CAP_RNGHLDOFF_SUP)
{
for (i = 0 ; i < 4; i++)
{
decode_bitfield_value(bit_fld,
(val_other[2] << sizeof(guint8)) + val_other[3],
docsis_cm_cap_ranging_hold_off_vals[i].value,
16);
proto_tree_add_text(subtree, tvb, off + 2, 4, "%s%s",
bit_fld, docsis_cm_cap_ranging_hold_off_vals[i].strptr);
}
}
if (tlv_type == DOCSIS_CM_CAP_USSYMRATE_SUP)
{
for (i = 0 ; i < 6; i++)
{
decode_bitfield_value(bit_fld, val_byte,docsis_cm_cap_ussymrate_vals[i].value, 8);
proto_tree_add_text(subtree, tvb, off + 2, 1, "%s%s",
bit_fld, docsis_cm_cap_ussymrate_vals[i].strptr);
}
}
if (tlv_type == DOCSIS_CM_CAP_Opt802MPLSSup)
{
for (i = 0 ; i < 25; i++)
{
decode_bitfield_value(bit_fld,
(val_other[2] << sizeof(guint8)) + val_other[3],
docsis_cm_cap_mpls_vals[i].value,
32);
proto_tree_add_text(subtree, tvb, off + 2, 4, "%s%s",
bit_fld, docsis_cm_cap_mpls_vals[i].strptr);
}
}
if (opt125)
{
off += (tlv_len) + 2;
}
else
{
off += (tlv_len *2) + 4;
}
}
}
static int
dissect_packetcable_i05_ccc(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend)
{
int suboptoff = optoff;
guint8 subopt, subopt_len, fetch_tgt, timer_val, ticket_ctl;
proto_tree *pkt_s_tree;
proto_item *vti;
subopt = tvb_get_guint8(tvb, optoff);
suboptoff++;
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR, "Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, optoff);
suboptoff++;
vti = proto_tree_add_text(v_tree, tvb, optoff, subopt_len + 2,
"Suboption %u: %s: ", subopt,
val_to_str_const(subopt, pkt_i05_ccc_opt_vals, "unknown/reserved") );
switch (subopt) {
case PKT_CCC_PRI_DHCP:
case PKT_CCC_SEC_DHCP:
case PKT_CCC_I05_SNMP:
case PKT_CCC_I05_PRI_DNS:
case PKT_CCC_I05_SEC_DNS:
case PKT_CCC_KRB_REALM:
case PKT_CCC_CMS_FQDN:
proto_item_append_text(vti, "%s (%u byte%s)",
tvb_format_stringzpad(tvb, suboptoff, subopt_len),
subopt_len,
plurality(subopt_len, "", "s") );
suboptoff += subopt_len;
break;
case PKT_CCC_TGT_FLAG:
if (suboptoff+1 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
fetch_tgt = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
fetch_tgt ? "Yes" : "No",
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCC_PROV_TIMER:
if (suboptoff+1 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
timer_val = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%u%s (%u byte%s%s)", timer_val,
timer_val > 30 ? " [Invalid]" : "",
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCC_AS_KRB:
if (suboptoff+12 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
proto_item_append_text(vti, "(%u byte%s%s)", subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 12 ? " [Invalid]" : "");
if (subopt_len == 12) {
pkt_s_tree = proto_item_add_subtree(vti, ett_bootp_option);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 4,
"pktcMtaDevRealmUnsolicitedKeyNomTimeout: %u",
tvb_get_ntohl(tvb, suboptoff));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 4, 4,
"pktcMtaDevRealmUnsolicitedKeyMaxTimeout: %u",
tvb_get_ntohl(tvb, suboptoff + 4));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 8, 4,
"pktcMtaDevRealmUnsolicitedKeyMaxRetries: %u",
tvb_get_ntohl(tvb, suboptoff + 8));
}
suboptoff += subopt_len;
break;
case PKT_CCC_AP_KRB:
if (suboptoff+12 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
proto_item_append_text(vti, "(%u byte%s%s)", subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 12 ? " [Invalid]" : "");
if (subopt_len == 12) {
pkt_s_tree = proto_item_add_subtree(vti, ett_bootp_option);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 4,
"pktcMtaDevProvUnsolicitedKeyNomTimeout: %u",
tvb_get_ntohl(tvb, suboptoff));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 4, 4,
"pktcMtaDevProvUnsolicitedKeyMaxTimeout: %u",
tvb_get_ntohl(tvb, suboptoff + 4));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 8, 4,
"pktcMtaDevProvUnsolicitedKeyMaxRetries: %u",
tvb_get_ntohl(tvb, suboptoff + 8));
}
suboptoff += subopt_len;
break;
case PKT_CCC_MTA_KRB_CLEAR:
if (suboptoff+1 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
ticket_ctl = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u) (%u byte%s%s)",
val_to_str_const (ticket_ctl, pkt_i05_ccc_ticket_ctl_vals, "unknown/invalid"),
ticket_ctl,
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
default:
suboptoff += subopt_len;
break;
}
return suboptoff;
}
static int
dissect_packetcable_ietf_ccc(packet_info *pinfo, proto_item *v_ti, proto_tree *v_tree,
tvbuff_t *tvb, int optoff, int optend, int revision)
{
int suboptoff = optoff;
guint8 subopt, subopt_len;
guint32 ipv4addr;
guint8 prov_type, fetch_tgt, timer_val;
guint16 sec_tcm;
proto_tree *pkt_s_tree;
proto_item *vti;
int max_timer_val = 255, i;
const guchar *dns_name;
char bit_fld[24];
subopt = tvb_get_guint8(tvb, suboptoff);
suboptoff++;
if (suboptoff >= optend) {
expert_add_info_format(pinfo, v_ti, PI_PROTOCOL, PI_ERROR,
"Suboption %d: no room left in option for suboption length", subopt);
return (optend);
}
subopt_len = tvb_get_guint8(tvb, suboptoff);
suboptoff++;
vti = proto_tree_add_text(v_tree, tvb, optoff, subopt_len + 2,
"Suboption %u: %s: ", subopt,
val_to_str_const(subopt, pkt_draft5_ccc_opt_vals, "unknown/reserved") );
switch (subopt) {
case PKT_CCC_PRI_DHCP:
case PKT_CCC_SEC_DHCP:
if (suboptoff+4 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
ipv4addr = tvb_get_ipv4(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
ip_to_str((guint8 *)&ipv4addr),
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 4 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCC_IETF_PROV_SRV:
if (suboptoff+1 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
prov_type = tvb_get_guint8(tvb, suboptoff);
suboptoff += 1;
switch (prov_type) {
case 0:
get_dns_name(tvb, suboptoff, subopt_len, suboptoff, &dns_name);
proto_item_append_text(vti, "%s (%u byte%s)", dns_name,
subopt_len - 1, plurality(subopt_len, "", "s") );
break;
case 1:
if (suboptoff+4 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
ipv4addr = tvb_get_ipv4(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
ip_to_str((guint8 *)&ipv4addr),
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 5 ? " [Invalid]" : "");
break;
default:
proto_item_append_text(vti, "Invalid type: %u (%u byte%s)",
prov_type,
subopt_len,
plurality(subopt_len, "", "s") );
break;
}
suboptoff += subopt_len - 1;
break;
case PKT_CCC_IETF_AS_KRB:
if (suboptoff+12 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
proto_item_append_text(vti, "(%u byte%s%s)", subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 12 ? " [Invalid]" : "");
if (subopt_len == 12) {
pkt_s_tree = proto_item_add_subtree(vti, ett_bootp_option);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 4,
"pktcMtaDevRealmUnsolicitedKeyNomTimeout: %u",
tvb_get_ntohl(tvb, suboptoff));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 4, 4,
"pktcMtaDevRealmUnsolicitedKeyMaxTimeout: %u",
tvb_get_ntohl(tvb, suboptoff + 4));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 8, 4,
"pktcMtaDevRealmUnsolicitedKeyMaxRetries: %u",
tvb_get_ntohl(tvb, suboptoff + 8));
}
suboptoff += subopt_len;
break;
case PKT_CCC_IETF_AP_KRB:
proto_item_append_text(vti, "(%u byte%s%s)", subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 12 ? " [Invalid]" : "");
if (subopt_len == 12) {
pkt_s_tree = proto_item_add_subtree(vti, ett_bootp_option);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 4,
"pktcMtaDevProvUnsolicitedKeyNomTimeout: %u",
tvb_get_ntohl(tvb, suboptoff));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 4, 4,
"pktcMtaDevProvUnsolicitedKeyMaxTimeout: %u",
tvb_get_ntohl(tvb, suboptoff + 4));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff + 8, 4,
"pktcMtaDevProvUnsolicitedKeyMaxRetries: %u",
tvb_get_ntohl(tvb, suboptoff + 8));
}
suboptoff += subopt_len;
break;
case PKT_CCC_KRB_REALM:
get_dns_name(tvb, suboptoff, subopt_len, suboptoff, &dns_name);
proto_item_append_text(vti, "%s (%u byte%s)", dns_name,
subopt_len, plurality(subopt_len, "", "s") );
suboptoff += subopt_len;
break;
case PKT_CCC_TGT_FLAG:
if (suboptoff+1 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
fetch_tgt = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
fetch_tgt ? "Yes" : "No",
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += 1;
break;
case PKT_CCC_PROV_TIMER:
if (suboptoff+1 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
if (revision == PACKETCABLE_CCC_DRAFT5)
max_timer_val = 30;
timer_val = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%u%s (%u byte%s%s)", timer_val,
timer_val > max_timer_val ? " [Invalid]" : "",
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += 1;
break;
case PKT_CCC_IETF_SEC_TKT:
if (suboptoff+2 > optend) {
expert_add_info_format(pinfo, vti, PI_PROTOCOL, PI_ERROR, "no room left in option for suboption value");
return (optend);
}
sec_tcm = tvb_get_ntohs(tvb, suboptoff);
proto_item_append_text(vti, "0x%04x (%u byte%s%s)", sec_tcm, subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 2 ? " [Invalid]" : "");
if (subopt_len == 2) {
pkt_s_tree = proto_item_add_subtree(vti, ett_bootp_option);
for (i = 0; i < 2; i++) {
if (sec_tcm & sec_tcm_vals[i].value) {
decode_bitfield_value(bit_fld, sec_tcm, sec_tcm_vals[i].value, 16);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 2, "%sInvalidate %s",
bit_fld, sec_tcm_vals[i].strptr);
}
}
}
suboptoff += subopt_len;
break;
default:
suboptoff += subopt_len;
break;
}
return suboptoff;
}
static void
dissect_bootp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *bp_tree;
proto_item *ti;
proto_tree *flag_tree;
proto_item *fi, *hidden_item;
guint8 op;
guint8 htype, hlen;
int voff, eoff, tmpvoff;
guint32 ip_addr;
gboolean at_end;
const char *dhcp_type = NULL;
const guint8 *vendor_class_id = NULL;
guint16 flags, secs;
int offset_delta;
guint8 overload = 0;
rfc3396_dns_domain_search_list.total_number_of_block = 0;
rfc3396_dns_domain_search_list.tvb_composite = NULL;
rfc3396_sip_server.total_number_of_block = 0;
rfc3396_sip_server.tvb_composite = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BOOTP");
col_clear(pinfo->cinfo, COL_INFO);
op = tvb_get_guint8(tvb, 0);
htype = tvb_get_guint8(tvb, 1);
hlen = tvb_get_guint8(tvb, 2);
switch (op) {
case BOOTREQUEST:
if ((htype == ARPHRD_ETHER || htype == ARPHRD_IEEE802)
&& hlen == 6) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Boot Request from %s (%s)",
tvb_arphrdaddr_to_str(tvb, 28, hlen, htype),
get_ether_name(tvb_get_ptr(tvb, 28, hlen)));
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO, "Boot Request from %s",
tvb_arphrdaddr_to_str(tvb, 28, hlen, htype));
}
break;
case BOOTREPLY:
col_set_str(pinfo->cinfo, COL_INFO, "Boot Reply");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown BOOTP message type (%u)", op);
break;
}
voff = VENDOR_INFO_OFFSET;
if (tvb_bytes_exist(tvb, voff, 4) &&
(tvb_get_ntohl(tvb, voff) == 0x63825363)) {
voff += 4;
} else {
voff += 64;
}
eoff = tvb_reported_length(tvb);
tmpvoff = voff;
at_end = FALSE;
rfc3396_dns_domain_search_list.index_current_block = 0;
rfc3396_sip_server.index_current_block = 0;
while (tmpvoff < eoff && !at_end) {
offset_delta = bootp_option(tvb, pinfo, 0, tmpvoff, eoff, TRUE, &at_end,
&dhcp_type, &vendor_class_id, &overload);
if (offset_delta <= 0) {
THROW(ReportedBoundsError);
}
tmpvoff += offset_delta;
}
if (dhcp_type != NULL) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCP");
col_add_fstr(pinfo->cinfo, COL_INFO, "DHCP %-8s - Transaction ID 0x%x",
dhcp_type, tvb_get_ntohl(tvb, 4));
tap_queue_packet( bootp_dhcp_tap, pinfo, dhcp_type);
}
ti = proto_tree_add_item(tree, proto_bootp, tvb, 0, -1, ENC_NA);
bp_tree = proto_item_add_subtree(ti, ett_bootp);
proto_tree_add_uint(bp_tree, hf_bootp_type, tvb,
0, 1,
op);
proto_tree_add_item(bp_tree, hf_bootp_hw_type, tvb,
1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(bp_tree, hf_bootp_hw_len, tvb,
2, 1, hlen);
proto_tree_add_item(bp_tree, hf_bootp_hops, tvb,
3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_bootp_id, tvb,
4, 4, ENC_BIG_ENDIAN);
secs = tvb_get_letohs(tvb, 8);
if (secs > 0 && secs <= 0xff) {
ti = proto_tree_add_uint_format_value(bp_tree, hf_bootp_secs, tvb,
8, 2, secs, "%u", secs);
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_NOTE,
"Seconds elapsed (%u) appears to be encoded as little-endian", secs);
} else {
proto_tree_add_item(bp_tree, hf_bootp_secs, tvb,
8, 2, ENC_BIG_ENDIAN);
}
flags = tvb_get_ntohs(tvb, 10);
fi = proto_tree_add_uint(bp_tree, hf_bootp_flags, tvb,
10, 2, flags);
proto_item_append_text(fi, " (%s)",
(flags & BOOTP_BC) ? "Broadcast" : "Unicast");
flag_tree = proto_item_add_subtree(fi, ett_bootp_flags);
proto_tree_add_boolean(flag_tree, hf_bootp_flags_broadcast, tvb,
10, 2, flags);
proto_tree_add_uint(flag_tree, hf_bootp_flags_reserved, tvb,
10, 2, flags);
proto_tree_add_item(bp_tree, hf_bootp_ip_client, tvb,
12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_bootp_ip_your, tvb,
16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_bootp_ip_server, tvb,
20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_bootp_ip_relay, tvb,
24, 4, ENC_BIG_ENDIAN);
if (hlen > 0 && hlen <= 16) {
if ((htype == ARPHRD_ETHER || htype == ARPHRD_IEEE802)
&& hlen == 6)
proto_tree_add_item(bp_tree, hf_bootp_hw_ether_addr, tvb, 28, 6, ENC_NA);
else
proto_tree_add_bytes_format_value(bp_tree, hf_bootp_hw_addr, tvb, 28, 16,
NULL, "%s", tvb_arphrdaddr_to_str(tvb, 28, hlen, htype));
if ((16 - hlen) > 0)
proto_tree_add_item(bp_tree, hf_bootp_hw_addr_padding, tvb, 28+hlen, 16-hlen, ENC_NA);
} else {
proto_tree_add_text(bp_tree, tvb,
28, 16, "Client address not given");
}
if (overload & OPT_OVERLOAD_SNAME) {
proto_tree_add_text (bp_tree, tvb,
SERVER_NAME_OFFSET, SERVER_NAME_LEN,
"Server name option overloaded by DHCP");
} else {
if (tvb_get_guint8(tvb, SERVER_NAME_OFFSET) != '\0') {
proto_tree_add_item(bp_tree, hf_bootp_server, tvb,
SERVER_NAME_OFFSET,
SERVER_NAME_LEN, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_string_format(bp_tree, hf_bootp_server, tvb,
SERVER_NAME_OFFSET,
SERVER_NAME_LEN,
"", "Server host name not given");
}
}
if (overload & OPT_OVERLOAD_FILE) {
proto_tree_add_text (bp_tree, tvb,
FILE_NAME_OFFSET, FILE_NAME_LEN,
"Boot file name option overloaded by DHCP");
} else {
if (tvb_get_guint8(tvb, FILE_NAME_OFFSET) != '\0') {
proto_tree_add_item(bp_tree, hf_bootp_file, tvb,
FILE_NAME_OFFSET,
FILE_NAME_LEN, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_string_format(bp_tree, hf_bootp_file, tvb,
FILE_NAME_OFFSET,
FILE_NAME_LEN,
"", "Boot file name not given");
}
}
voff = VENDOR_INFO_OFFSET;
if (dhcp_type != NULL) {
hidden_item = proto_tree_add_boolean(bp_tree, hf_bootp_dhcp, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (tvb_bytes_exist(tvb, voff, 4) &&
(tvb_get_ntohl(tvb, voff) == 0x63825363)) {
ip_addr = tvb_get_ipv4(tvb, voff);
proto_tree_add_ipv4_format_value(bp_tree, hf_bootp_cookie, tvb,
voff, 4, ip_addr, "DHCP");
voff += 4;
} else {
proto_tree_add_text(bp_tree, tvb,
voff, 64, "Bootp vendor specific options");
voff += 64;
}
at_end = FALSE;
rfc3396_dns_domain_search_list.index_current_block = 0;
rfc3396_sip_server.index_current_block = 0;
while (voff < eoff && !at_end) {
offset_delta = bootp_option(tvb, pinfo, bp_tree, voff, eoff, FALSE, &at_end,
&dhcp_type, &vendor_class_id, &overload);
if (offset_delta <= 0) {
THROW(ReportedBoundsError);
}
voff += offset_delta;
}
if ((dhcp_type != NULL) && (!at_end))
{
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_ERROR, "End option missing");
}
if (voff < eoff) {
proto_tree_add_text(bp_tree, tvb, voff, eoff - voff, "Padding");
}
}
static void
bootp_init_protocol(void)
{
guint i;
for(i=0; i<BOOTP_OPT_NUM; i++)
{
bootp_opt[i].text = default_bootp_opt[i].text;
bootp_opt[i].ftype = default_bootp_opt[i].ftype;
bootp_opt[i].phf = default_bootp_opt[i].phf;
}
for (i = 0; i < num_bootp_records_uat; i++)
{
bootp_opt[uat_bootp_records[i].opt].text = se_strdup(uat_bootp_records[i].text);
bootp_opt[uat_bootp_records[i].opt].ftype = uat_bootp_records[i].ftype;
bootp_opt[uat_bootp_records[i].opt].phf = NULL;
}
}
void
proto_register_bootp(void)
{
static const value_string bootp_custom_type_vals[] = {
{ ipv4, "IP Address"},
{ ipv4_list, "IP Address List" },
{ string, "string" },
{ bytes, "bytes" },
{ val_boolean, "boolean" },
{ val_u_byte, "byte" },
{ val_u_short, "unsigned short" },
{ val_u_short_list, "unsigned short list" },
{ val_u_long, "unsigned long" },
{ time_in_s_secs, "integer time in seconds" },
{ time_in_u_secs, "unsigned integer time in seconds" },
{ 0x00, NULL }
};
static hf_register_info hf[] = {
{ &hf_bootp_dhcp,
{ "Frame is DHCP", "bootp.dhcp",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_type,
{ "Message type", "bootp.type",
FT_UINT8, BASE_DEC, VALS(op_vals), 0x0,
NULL, HFILL }},
{ &hf_bootp_hw_type,
{ "Hardware type", "bootp.hw.type",
FT_UINT8, BASE_HEX, VALS(arp_hrd_vals), 0x0,
NULL, HFILL }},
{ &hf_bootp_hw_len,
{ "Hardware address length", "bootp.hw.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_hops,
{ "Hops", "bootp.hops",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_id,
{ "Transaction ID", "bootp.id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_secs,
{ "Seconds elapsed", "bootp.secs",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_flags,
{ "Bootp flags", "bootp.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_flags_broadcast,
{ "Broadcast flag", "bootp.flags.bc",
FT_BOOLEAN, 16, TFS(&flag_set_broadcast), BOOTP_BC,
NULL, HFILL }},
{ &hf_bootp_flags_reserved,
{ "Reserved flags", "bootp.flags.reserved",
FT_UINT16, BASE_HEX, NULL, BOOTP_MBZ,
NULL, HFILL }},
{ &hf_bootp_ip_client,
{ "Client IP address", "bootp.ip.client",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_ip_your,
{ "Your (client) IP address", "bootp.ip.your",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_ip_server,
{ "Next server IP address", "bootp.ip.server",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_ip_relay,
{ "Relay agent IP address", "bootp.ip.relay",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_hw_addr,
{ "Client hardware address", "bootp.hw.addr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_hw_addr_padding,
{ "Client hardware address padding", "bootp.hw.addr_padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_hw_ether_addr,
{ "Client MAC address", "bootp.hw.mac_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_server,
{ "Server host name", "bootp.server",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_file,
{ "Boot file name", "bootp.file",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_cookie,
{ "Magic cookie", "bootp.cookie",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_fqdn_s,
{ "Server", "bootp.fqdn.s",
FT_BOOLEAN, 8, TFS(&tfs_fqdn_s), F_FQDN_S,
"If true, server should do DDNS update", HFILL }},
{ &hf_bootp_fqdn_o,
{ "Server overrides", "bootp.fqdn.o",
FT_BOOLEAN, 8, TFS(&tfs_fqdn_o), F_FQDN_O,
"If true, server insists on doing DDNS update", HFILL }},
{ &hf_bootp_fqdn_e,
{ "Encoding", "bootp.fqdn.e",
FT_BOOLEAN, 8, TFS(&tfs_fqdn_e), F_FQDN_E,
"If true, name is binary encoded", HFILL }},
{ &hf_bootp_fqdn_n,
{ "Server DDNS", "bootp.fqdn.n",
FT_BOOLEAN, 8, TFS(&tfs_fqdn_n), F_FQDN_N,
"If true, server should not do any DDNS updates", HFILL }},
{ &hf_bootp_fqdn_mbz,
{ "Reserved flags", "bootp.fqdn.mbz",
FT_UINT8, BASE_HEX, NULL, F_FQDN_MBZ,
NULL, HFILL }},
{ &hf_bootp_fqdn_rcode1,
{ "A-RR result", "bootp.fqdn.rcode1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Result code of A-RR update", HFILL }},
{ &hf_bootp_fqdn_rcode2,
{ "PTR-RR result", "bootp.fqdn.rcode2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Result code of PTR-RR update", HFILL }},
{ &hf_bootp_fqdn_name,
{ "Client name", "bootp.fqdn.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name to register via DDNS", HFILL }},
{ &hf_bootp_fqdn_asciiname,
{ "Client name", "bootp.fqdn.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name to register via DDNS", HFILL }},
{ &hf_bootp_pkt_mta_cap_len,
{ "MTA DC Length", "bootp.vendor.pktc.mta_cap_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"PacketCable MTA Device Capabilities Length", HFILL }},
{ &hf_bootp_docsis_cm_cap_len,
{ "CM DC Length", "bootp.vendor.docsis.cm_cap_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"DOCSIS Cable Modem Device Capabilities Length", HFILL }},
{ &hf_bootp_docsis_cm_cap_type,
{ "CM DC Type", "bootp.docsis_cm_cap_type",
FT_UINT16, BASE_DEC, VALS(docsis_cm_cap_type_vals), 0x0,
"Docsis Cable Modem Device Capability type", HFILL }},
{ &hf_bootp_client_identifier_uuid,
{ "Client Identifier (UUID)", "bootp.client_id_uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
"Client Machine Identifier (UUID)", HFILL }},
{ &hf_bootp_client_identifier_duid_llt_hw_type,
{ "Hardware type", "bootp.client_id_duid_llt_hw_type",
FT_UINT16, BASE_DEC, VALS(arp_hrd_vals), 0x0,
"Client Identifier DUID LLT Hardware type", HFILL }},
{ &hf_bootp_client_identifier_duid_ll_hw_type,
{ "Hardware type", "bootp.client_id_duid_ll_hw_type",
FT_UINT16, BASE_DEC, VALS(arp_hrd_vals), 0x0,
"Client Identifier DUID LL Hardware type", HFILL }},
{ &hf_bootp_option_type,
{ "Option", "bootp.option.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Bootp/Dhcp option type", HFILL }},
{ &hf_bootp_option_length,
{ "Length", "bootp.option.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Bootp/Dhcp option length", HFILL }},
{ &hf_bootp_suboption_length,
{ "Length", "bootp.option.suboption_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Suboption length", HFILL }},
{ &hf_bootp_option_value,
{ "Value", "bootp.option.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_8,
{ "Value", "bootp.option.value.uint",
FT_UINT8, BASE_DEC, NULL, 0x0,
"8-bit Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_16,
{ "Value", "bootp.option.value.uint",
FT_UINT16, BASE_DEC, NULL, 0x0,
"16-bit Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_u32,
{ "Value", "bootp.option.value.uint",
FT_UINT32, BASE_HEX, NULL, 0x0,
"32-bit Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_i32,
{ "Value", "bootp.option.value.int",
FT_INT32, BASE_DEC, NULL, 0x0,
"32-bit Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_stringz,
{ "Value", "bootp.option.value.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Z-String Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_ip_address,
{ "Value", "bootp.option.value.address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"IP address Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_value_boolean,
{ "Value", "bootp.option.value.bool",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_true_false), 0x00,
"Boolean Bootp/Dhcp option value", HFILL }},
{ &hf_bootp_option_padding,
{ "Padding", "bootp.option.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 0: Padding", HFILL }},
{ &hf_bootp_option_subnet_mask,
{ "Subnet Mask", "bootp.option.subnet_mask",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 1: Subnet Mask", HFILL }},
{ &hf_bootp_option_time_offset,
{ "Time Offset", "bootp.option.time_offset",
FT_INT32, BASE_DEC, NULL, 0x00,
"Option 2: Time Offset", HFILL }},
{ &hf_bootp_option_router,
{ "Router", "bootp.option.router",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 3: Router", HFILL }},
{ &hf_bootp_option_time_server,
{ "Time Server", "bootp.option.time_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 4: Time Server", HFILL }},
{ &hf_bootp_option_name_server,
{ "Name Server", "bootp.option.name_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 5: Name Server", HFILL }},
{ &hf_bootp_option_domain_name_server,
{ "Domain Name Server", "bootp.option.domain_name_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 6: Domain Name Server", HFILL }},
{ &hf_bootp_option_log_server,
{ "Log Server", "bootp.option.log_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 7: Log Server", HFILL }},
{ &hf_bootp_option_quotes_server,
{ "Quotes Server", "bootp.option.quotes_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 8: Quotes Server", HFILL }},
{ &hf_bootp_option_lpr_server,
{ "LPR Server", "bootp.option.lpr_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 9: LPR Server", HFILL }},
{ &hf_bootp_option_impress_server,
{ "Impress Server", "bootp.option.impress_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 10: Impress Server", HFILL }},
{ &hf_bootp_option_resource_location_server,
{ "Resource Location Server", "bootp.option.resource_location_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 11: Resource Location Server", HFILL }},
{ &hf_bootp_option_hostname,
{ "Host Name", "bootp.option.hostname",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 12: Host Name", HFILL }},
{ &hf_bootp_option_boot_file_size,
{ "Boot File Size", "bootp.option.boot_file_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 13: Boot File Size", HFILL }},
{ &hf_bootp_option_merit_dump_file,
{ "Merit Dump File", "bootp.option.merit_dump_file",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 14: Merit Dump File", HFILL }},
{ &hf_bootp_option_domain_name,
{ "Domain Name", "bootp.option.domain_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 15: Domain Name", HFILL }},
{ &hf_bootp_option_swap_server,
{ "Swap Server", "bootp.option.swap_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 16: Swap Server", HFILL }},
{ &hf_bootp_option_root_path,
{ "Root Path", "bootp.option.root_path",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 17: Root Path", HFILL }},
{ &hf_bootp_option_extension_path,
{ "Extensions Path", "bootp.option.extension_path",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 18: Extensions Path", HFILL }},
{ &hf_bootp_option_ip_forwarding,
{ "IP Forwarding", "bootp.option.ip_forwarding",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 19: IP Forwarding", HFILL }},
{ &hf_bootp_option_policy_filter_ip,
{ "IP Address", "bootp.option.policy_filter.ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 21: IP address", HFILL }},
{ &hf_bootp_option_policy_filter_subnet_mask,
{ "Subnet Mask", "bootp.option.policy_filter.subnet_mask",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 21: Subnet Mask", HFILL }},
{ &hf_bootp_option_non_local_source_routing,
{ "Non-Local Source Routing", "bootp.option.non_local_source_routing",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 20: Non-Local Source Routing", HFILL }},
{ &hf_bootp_option_max_datagram_reassembly_size,
{ "Maximum Datagram Reassembly Size", "bootp.option.max_datagram_reassembly_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 22: Maximum Datagram Reassembly Size", HFILL }},
{ &hf_bootp_option_default_ip_ttl,
{ "Default IP Time-to-Live", "bootp.option.default_ip_ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 23: Default IP Time-to-Live", HFILL }},
{ &hf_bootp_option_path_mtu_aging_timeout,
{ "Path MTU Aging Timeout", "bootp.option.path_mtu_aging_timeout",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 24: Path MTU Aging Timeout", HFILL }},
{ &hf_bootp_option_path_mtu_plateau_table_item,
{ "Path MTU Plateau Table Item", "bootp.option.path_mtu_plateau_table_item",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 25: Path MTU Plateau Table Item", HFILL }},
{ &hf_bootp_option_interface_mtu,
{ "Interface MTU", "bootp.option.interface_mtu",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 26: Interface MTU", HFILL }},
{ &hf_bootp_option_all_subnets_are_local,
{ "All Subnets are Local", "bootp.option.all_subnets_are_local",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x00,
"Option 27: All Subnets are Local", HFILL }},
{ &hf_bootp_option_broadcast_address,
{ "Broadcast Address", "bootp.option.broadcast_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 28: Broadcast Address", HFILL }},
{ &hf_bootp_option_perform_mask_discovery,
{ "Perform Mask Discovery", "bootp.option.perform_mask_discovery",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 29: Perform Mask Discovery", HFILL }},
{ &hf_bootp_option_mask_supplier,
{ "Mask Supplier", "bootp.option.mask_supplier",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x00,
"Option 30: Mask Supplier", HFILL }},
{ &hf_bootp_option_perform_router_discover,
{ "Perform Router Discover", "bootp.option.perform_router_discover",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 31: Perform Router Discover", HFILL }},
{ &hf_bootp_option_router_solicitation_address,
{ "Router Solicitation Address", "bootp.option.router_solicitation_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 32: Router Solicitation Address", HFILL }},
{ &hf_bootp_option_static_route_ip,
{ "Destination IP Address", "bootp.option.static_route.ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 33: Destination IP address", HFILL }},
{ &hf_bootp_option_static_route_router,
{ "Destination Router", "bootp.option.static_route.router",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 33: Destination Router", HFILL }},
{ &hf_bootp_option_trailer_encapsulation,
{ "Trailer Encapsulation", "bootp.option.trailer_encapsulation",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 34: Trailer Encapsulation", HFILL }},
{ &hf_bootp_option_arp_cache_timeout,
{ "ARP Cache Timeout", "bootp.option.arp_cache_timeout",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 35: ARP Cache Timeout", HFILL }},
{ &hf_bootp_option_ethernet_encapsulation,
{ "Ethernet Encapsulation", "bootp.option.ethernet_encapsulation",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 36: Ethernet Encapsulation", HFILL }},
{ &hf_bootp_option_tcp_default_ttl,
{ "TCP Default TTL", "bootp.option.tcp_default_ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 37: TCP Default TTL", HFILL }},
{ &hf_bootp_option_tcp_keepalive_interval,
{ "TCP Keepalive Interval", "bootp.option.tcp_keepalive_interval",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 38: TCP Keepalive Interval", HFILL }},
{ &hf_bootp_option_tcp_keepalive_garbage,
{ "TCP Keepalive Garbage", "bootp.option.tcp_keepalive_garbage",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0x00,
"Option 39: TCP Keepalive Garbage", HFILL }},
{ &hf_bootp_option_nis_domain,
{ "Network Information Service Domain", "bootp.option.nis_domain",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 40: Network Information Service Domain", HFILL }},
{ &hf_bootp_option_nis_server,
{ "Network Information Service Server", "bootp.option.nis_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 41: Network Information Service Server", HFILL }},
{ &hf_bootp_option_ntp_server,
{ "Network Time Protocol Server", "bootp.option.ntp_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 42: Network Time Protocol Server", HFILL }},
{ &hf_bootp_option43_value,
{ "Value", "bootp.option.vendor.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43: Suboption value", HFILL }},
{ &hf_bootp_option43_value_8,
{ "Value", "bootp.option.vendor.value.uint",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43: Suboption 8-bit value", HFILL }},
{ &hf_bootp_option43_value_32,
{ "Value", "bootp.option.vendor.value.uint",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Option 43: Suboption 32-bit value", HFILL }},
{ &hf_bootp_option43_value_stringz,
{ "Value", "bootp.option.vendor.value.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43: Suboption Z-String value", HFILL }},
{ &hf_bootp_option43_value_ip_address,
{ "Value", "bootp.option.vendor.value.address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 43: Suboption IP address", HFILL }},
{ &hf_bootp_option43_pxeclient_suboption,
{ "Option 43 Suboption", "bootp.option.vendor.pxeclient.suboption",
FT_UINT8, BASE_DEC, VALS(option43_pxeclient_suboption_vals), 0x0,
"Option 43:PXE Client Suboption", HFILL }},
{ &hf_bootp_option43_pxeclient_padding,
{ "Padding", "bootp.option.vendor.pxeclient.padding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:PXE Client 0 Padding", HFILL }},
{ &hf_bootp_option43_pxeclient_mtftp_ip,
{ "mtftp IP", "bootp.option.vendor.pxeclient.mtftp_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 43:PXE Client 1 mtftp IP", HFILL }},
{ &hf_bootp_option43_pxeclient_mtftp_client_port,
{ "mtftp IP", "bootp.option.vendor.pxeclient.mtftp_client_port",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Option 43:PXE Client 2 mtftp client port", HFILL }},
{ &hf_bootp_option43_pxeclient_mtftp_server_port,
{ "mtftp IP", "bootp.option.vendor.pxeclient.mtftp_server_port",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Option 43:PXE Client 3 mtftp server port", HFILL }},
{ &hf_bootp_option43_pxeclient_mtftp_timeout,
{ "mtftp timeout", "bootp.option.vendor.pxeclient.mtftp_timeout",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:PXE Client 4 mtftp timeout", HFILL }},
{ &hf_bootp_option43_pxeclient_mtftp_delay,
{ "mtftp delay", "bootp.option.vendor.pxeclient.mtftp_delay",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:PXE Client 5 mtftp delay", HFILL }},
{ &hf_bootp_option43_pxeclient_discovery_control,
{ "discovery control", "bootp.option.vendor.pxeclient.discovery_control",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Option 43:PXE Client 6 discovery control", HFILL }},
{ &hf_bootp_option43_pxeclient_multicast_address,
{ "multicast address", "bootp.option.vendor.pxeclient.multicast_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 43:PXE Client 7 multicast address", HFILL }},
{ &hf_bootp_option43_pxeclient_boot_servers,
{ "boot servers", "bootp.option.vendor.pxeclient.boot_servers",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:PXE Client 8 boot servers", HFILL }},
{ &hf_bootp_option43_pxeclient_boot_menu,
{ "boot menu", "bootp.option.vendor.pxeclient.boot_menu",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:PXE Client 9 boot menu", HFILL }},
{ &hf_bootp_option43_pxeclient_menu_prompt,
{ "menu prompt", "bootp.option.vendor.pxeclient.menu_prompt",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:PXE Client 10 menu prompt", HFILL }},
{ &hf_bootp_option43_pxeclient_multicast_address_alloc,
{ "multicast address alloc", "bootp.option.vendor.pxeclient.multicast_address_alloc",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:PXE Client 11 multicast address alloc", HFILL }},
{ &hf_bootp_option43_pxeclient_credential_types,
{ "credential types", "bootp.option.vendor.pxeclient.credential_types",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:PXE Client 12 credential types", HFILL }},
{ &hf_bootp_option43_pxeclient_boot_item,
{ "boot item", "bootp.option.vendor.pxeclient.boot_item",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:PXE Client 71 boot item", HFILL }},
{ &hf_bootp_option43_pxeclient_end,
{ "PXE Client End", "bootp.option.vendor.pxeclient.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:PXE Client 255 End", HFILL }},
{ &hf_bootp_option43_cl_suboption,
{ "Option 43 Suboption", "bootp.option.vendor.cl.suboption",
FT_UINT8, BASE_DEC, VALS(option43_cl_suboption_vals), 0x0,
"Option 43:CL Suboption", HFILL }},
{ &hf_bootp_option43_cl_padding,
{ "Padding", "bootp.option.vendor.cl.padding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:CL 0 Padding", HFILL }},
{ &hf_bootp_option43_cl_suboption_request_list,
{ "Suboption Request List", "bootp.option.vendor.cl.suboption_request_list",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 1 Suboption Request List", HFILL }},
{ &hf_bootp_option43_cl_device_type,
{ "Device Type", "bootp.option.vendor.cl.device_type",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 2 Device Type", HFILL }},
{ &hf_bootp_option43_cl_esafe_type,
{ "eSAFE Types", "bootp.option.vendor.cl.esafe_type",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 3 eSAFE Types", HFILL }},
{ &hf_bootp_option43_cl_serial_number,
{ "Serial Number", "bootp.option.vendor.cl.serial_number",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 4 Serial Number", HFILL }},
{ &hf_bootp_option43_cl_hardware_version,
{ "Hardware Version", "bootp.option.vendor.cl.hardware_version",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 5 Hardware Version", HFILL }},
{ &hf_bootp_option43_cl_software_version,
{ "Software Version", "bootp.option.vendor.cl.software_version",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 6 Software Version", HFILL }},
{ &hf_bootp_option43_cl_boot_rom_version,
{ "Boot ROM version", "bootp.option.vendor.cl.boot_rom_version",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 7 Boot ROM version", HFILL }},
{ &hf_bootp_option43_cl_oui_string,
{ "Organizationally Unique Identifier", "bootp.option.vendor.cl.oui_string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 8 Organizationally Unique Identifier", HFILL }},
{ &hf_bootp_option43_cl_oui_bytes,
{ "Organizationally Unique Identifier", "bootp.option.vendor.cl.oui_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:CL 8 Organizationally Unique Identifier", HFILL }},
{ &hf_bootp_option43_cl_model_number,
{ "Model Number", "bootp.option.vendor.cl.model_number",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 9 Model Number", HFILL }},
{ &hf_bootp_option43_cl_vendor_name10,
{ "Vendor Name", "bootp.option.vendor.cl.vendor_name10",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 10 Vendor Name", HFILL }},
{ &hf_bootp_option43_cl_address_realm,
{ "Address Realm", "bootp.option.vendor.cl.address_realm",
FT_UINT8, BASE_DEC, VALS(cablehome_subopt11_vals), 0x0,
"Option 43:CL 11 Address Realm", HFILL }},
{ &hf_bootp_option43_cl_cm_ps_system_desc,
{ "CM/PS System Description", "bootp.option.vendor.cl.cm_ps_system_desc",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 12 CM/PS System Description", HFILL }},
{ &hf_bootp_option43_cl_cm_ps_firmware_revision,
{ "CM/PS Firmware Revision", "bootp.option.vendor.cl.cm_ps_firmware_revision",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 13 CM/PS Firmware Revision", HFILL }},
{ &hf_bootp_option43_cl_firewall_policy_file_version,
{ "Firewall Policy File Version", "bootp.option.vendor.cl.firewall_policy_file_version",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 14 Firewall Policy File Version", HFILL }},
{ &hf_bootp_option43_cl_esafe_config_file_devices,
{ "eSafe Config File Devices", "bootp.option.vendor.cl.esafe_config_file_devices",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 15 eSafe Config File Devices", HFILL }},
{ &hf_bootp_option43_cl_video_security_tape,
{ "Video Security Type", "bootp.option.vendor.cl.video_security_tape",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 18 Video Security Type", HFILL }},
{ &hf_bootp_option43_cl_mta_mac_address,
{ "MTA MAC Address", "bootp.option.vendor.cl.mta_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Option 43:CL 31 MTA MAC Address", HFILL }},
{ &hf_bootp_option43_cl_correlation_ID,
{ "Correlation ID", "bootp.option.vendor.cl.correlation_ID",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Option 43: CL 32 Correlation ID", HFILL }},
{ &hf_bootp_option43_cl_vendor_name51,
{ "Vendor Name", "bootp.option.vendor.cl.vendor_name51",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 51 Vendor Name", HFILL }},
{ &hf_bootp_option43_cl_cablecard_capability,
{ "CableCARD Capability", "bootp.option.vendor.cl.cablecard_capability",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:CL 52 CableCARD Capability", HFILL }},
{ &hf_bootp_option43_cl_device_id_ca,
{ "Device Identification (CA)", "bootp.option.vendor.cl.device_id_ca",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 43:CL 53 Device Identification (CA)", HFILL }},
{ &hf_bootp_option43_cl_device_id_x509,
{ "Device Identification (X.509)", "bootp.option.vendor.cl.device_id_x509",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 43:CL 54 Device Identification (X.509)", HFILL }},
{ &hf_bootp_option43_cl_end,
{ "CL End", "bootp.option.vendor.cl.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:CL 255 End", HFILL }},
{ &hf_bootp_option43_alcatel_suboption,
{ "Option 43 Suboption", "bootp.option.vendor.alu.suboption",
FT_UINT8, BASE_DEC, VALS(option43_alcatel_suboption_vals), 0x0,
"Option 43:Alcatel Suboption", HFILL }},
{ &hf_bootp_option43_alcatel_padding,
{ "Padding", "bootp.option.vendor.alu.padding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:Alcatel 0 Padding", HFILL }},
{ &hf_bootp_option43_alcatel_vlan_id,
{ "Voice VLAN ID", "bootp.option.vendor.alu.vid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 43:Alcatel 58 Voice VLAN ID", HFILL }},
{ &hf_bootp_option43_alcatel_tftp1,
{ "Spatial Redundancy TFTP1", "bootp.option.vendor.alu.tftp1",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Option 43:Alcatel 64 Spatial Redundancy TFTP1", HFILL }},
{ &hf_bootp_option43_alcatel_tftp2,
{ "Spatial Redundancy TFTP2", "bootp.option.vendor.alu.tftp2",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Option 43:Alcatel 65 Spatial Redundancy TFTP2", HFILL }},
{ &hf_bootp_option43_alcatel_app_type,
{ "Application Type", "bootp.option.vendor.alu.app_type",
FT_UINT8, BASE_DEC, VALS(option43_alcatel_app_type_vals), 0x0,
"Option 43:Alcatel 66 Application Type", HFILL }},
{ &hf_bootp_option43_alcatel_sip_url,
{ "SIP URL", "bootp.option.vendor.alu.sip_url",
FT_STRING, BASE_NONE, NULL, 0x0,
"Option 43:Alcatel 67 SIP URL", HFILL }},
{ &hf_bootp_option43_alcatel_end,
{ "Alcatel End", "bootp.option.vendor.alu.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 43:Alcatel 255 End", HFILL }},
{ &hf_bootp_option_netbios_over_tcpip_name_server,
{ "NetBIOS over TCP/IP Name Server", "bootp.option.netbios_over_tcpip_name_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 44: NetBIOS over TCP/IP Name Server", HFILL }},
{ &hf_bootp_option_netbios_over_tcpip_dd_name_server,
{ "NetBIOS over TCP/IP Datagram Distribution Name Server", "bootp.option.netbios_over_tcpip_dd_name_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 45: NetBIOS over TCP/IP Datagram Distribution Name Server", HFILL }},
{ &hf_bootp_option_netbios_over_tcpip_node_type,
{ "NetBIOS over TCP/IP Node Type", "bootp.option.netbios_over_tcpip_node_type",
FT_UINT8, BASE_DEC, VALS(bootp_nbnt_vals), 0x0,
"Option 46: NetBIOS over TCP/IP Node Type", HFILL }},
{ &hf_bootp_option_netbios_over_tcpip_scope,
{ "NetBIOS over TCP/IP Scope", "bootp.option.netbios_over_tcpip_scope",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 47: NetBIOS over TCP/IP Scope", HFILL }},
{ &hf_bootp_option_xwindows_system_font_server,
{ "X Window System Font Server", "bootp.option.xwindows_system_font_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 48: X Window System Font Server", HFILL }},
{ &hf_bootp_option_xwindows_system_display_manager,
{ "X Window System Display Manager", "bootp.option.xwindows_system_display_manager",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 49: X Window System Display Manager", HFILL }},
{ &hf_bootp_option_requested_ip_address,
{ "Requested IP Address", "bootp.option.requested_ip_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 50: Requested IP Address", HFILL }},
{ &hf_bootp_option_ip_address_lease_time,
{ "IP Address Lease Time", "bootp.option.ip_address_lease_time",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 51: IP Address Lease Time", HFILL }},
{ &hf_bootp_option_option_overload,
{ "Option Overload", "bootp.option.option_overload",
FT_UINT8, BASE_DEC, VALS(opt_overload_vals), 0x0,
"Option 52: Option Overload", HFILL }},
{ &hf_bootp_option_dhcp,
{ "DHCP", "bootp.option.dhcp",
FT_UINT8, BASE_DEC, VALS(opt53_text), 0x0,
"Option 53: DHCP option", HFILL }},
{ &hf_bootp_option_dhcp_server_id,
{ "DHCP Server Identifier", "bootp.option.dhcp_server_id",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 54: DHCP Server Identifier", HFILL }},
{ &hf_bootp_option_parameter_request_list_item,
{ "Parameter Request List Item", "bootp.option.request_list_item",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 55: Parameter Request List Item", HFILL }},
{ &hf_bootp_option_message,
{ "Message", "bootp.option.message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 56: Option message", HFILL }},
{ &hf_bootp_option_dhcp_max_message_size,
{ "Maximum DHCP Message Size", "bootp.option.dhcp_max_message_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 57: Maximum DHCP Message Size", HFILL }},
{ &hf_bootp_option_renewal_time_value,
{ "Renewal Time Value", "bootp.option.renewal_time_value",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 58: Renewal Time Value", HFILL }},
{ &hf_bootp_option_rebinding_time_value,
{ "Rebinding Time Value", "bootp.option.rebinding_time_value",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 59: Rebinding Time Value", HFILL }},
{ &hf_bootp_option_vendor_class_id,
{ "Vendor class identifier", "bootp.option.vendor_class_id",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 60: Vendor class identifier", HFILL }},
{ &hf_bootp_option_novell_netware_ip_domain,
{ "Novell/Netware IP domain", "bootp.option.novell_netware_ip_domain",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 62: Novell/Netware IP domain", HFILL }},
{ &hf_bootp_option63_suboption,
{ "Option 63 Suboption", "bootp.option.novell_options.suboption",
FT_UINT8, BASE_DEC, VALS(option63_suboption_vals), 0x0,
"Option 63: Suboption", HFILL }},
{ &hf_bootp_option63_value,
{ "Value", "bootp.option.novell_options.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 63: Suboption value", HFILL }},
{ &hf_bootp_option63_value_8,
{ "Value", "bootp.option.novell_options.value.uint",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 63: Suboption 8-bit value", HFILL }},
{ &hf_bootp_option63_value_ip_address,
{ "Value", "bootp.option.novell_options.value.address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 63: Suboption IP address", HFILL }},
{ &hf_bootp_option63_value_boolean,
{ "Value", "bootp.option.novell_options.value.bool",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_true_false), 0x00,
"Option 63: Suboption Boolean value", HFILL }},
{ &hf_bootp_option63_broadcast,
{ "Broadcast for nearest Netware server", "bootp.option.novell_options.broadcast",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x00,
"Option 63:5 Broadcast for nearest Netware server", HFILL }},
{ &hf_bootp_option63_preferred_dss_server,
{ "Preferred DSS server", "bootp.option.novell_options.preferred_dss_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 63:6 Preferred DSS server", HFILL }},
{ &hf_bootp_option63_nearest_nwip_server,
{ "Nearest NWIP server", "bootp.option.novell_options.nearest_nwip_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 63:7 Nearest NWIP server", HFILL }},
{ &hf_bootp_option63_autoretries,
{ "Autoretries", "bootp.option.novell_options.autoretries",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 63:8 Autoretries", HFILL }},
{ &hf_bootp_option63_autoretry_delay,
{ "Autoretry delay, sec",
"bootp.option.novell_options.autoretry_delay", FT_UINT8, BASE_DEC, NULL,
0x0, "Option 63:9 Autoretry delay, sec", HFILL }},
{ &hf_bootp_option63_support_netware_v1_1,
{ "Broadcast for nearest Netware server", "bootp.option.novell_options.support_netware_v1_1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x00,
"Option 63:10 Broadcast for nearest Netware server", HFILL }},
{ &hf_bootp_option63_primary_dss,
{ "Primary DSS", "bootp.option.novell_options.primary_dss",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 63:11 Primary DSS", HFILL }},
{ &hf_bootp_option_nis_plus_domain,
{ "Network Information Service+ Domain", "bootp.option.nis_plus_domain",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 64: Network Information Service+ Domain", HFILL }},
{ &hf_bootp_option_nis_plus_server,
{ "Network Information Service+ Server", "bootp.option.nis_plus_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 65: Network Information Service+ Server", HFILL }},
{ &hf_bootp_option_tftp_server_name,
{ "TFTP Server Name", "bootp.option.tftp_server_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 66: TFTP Server Name", HFILL }},
{ &hf_bootp_option_bootfile_name,
{ "Bootfile name", "bootp.option.bootfile_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 67: Bootfile name", HFILL }},
{ &hf_bootp_option_mobile_ip_home_agent,
{ "Mobile IP Home Agent", "bootp.option.mobile_ip_home_agent",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 68: Mobile IP Home Agent", HFILL }},
{ &hf_bootp_option_smtp_server,
{ "SMTP Server", "bootp.option.smtp_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 69: SMTP Server", HFILL }},
{ &hf_bootp_option_pop3_server,
{ "POP3 Server", "bootp.option.pop3_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 70: POP3 Server", HFILL }},
{ &hf_bootp_option_nntp_server,
{ "NNTP Server", "bootp.option.nntp_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 71: NNTP Server", HFILL }},
{ &hf_bootp_option_default_www_server,
{ "Default WWW Server", "bootp.option.default_www_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 72: Default WWW Server", HFILL }},
{ &hf_bootp_option_default_finger_server,
{ "Default Finger Server", "bootp.option.default_finger_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 73: Default Finger Server", HFILL }},
{ &hf_bootp_option_default_irc_server,
{ "Default IRC Server", "bootp.option.default_irc_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 74: Default IRC Server", HFILL }},
{ &hf_bootp_option_streettalk_server,
{ "StreetTalk Server", "bootp.option.streettalk_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 75: StreetTalk Server", HFILL }},
{ &hf_bootp_option_streettalk_da_server,
{ "StreetTalk Directory Assistance Server", "bootp.option.streettalk_da_server",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 76: StreetTalk Directory Assistance Server", HFILL }},
{ &hf_bootp_option77_user_class,
{ "Instance of User Class", "bootp.option.user_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bootp_option77_user_class_length,
{ "User Class Length", "bootp.option.user_class.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of User Class Instance", HFILL }},
{ &hf_bootp_option77_user_class_data,
{ "User Class Data", "bootp.option.user_class.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Data of User Class Instance", HFILL }},
{ &hf_bootp_option_slp_directory_agent_value,
{ "Value", "bootp.option.slp_directory_agent.value",
FT_UINT8, BASE_DEC, VALS(slpda_vals), 0x0,
"Option 78: SLPDA Value", HFILL }},
{ &hf_bootp_option_slp_directory_agent_slpda_address,
{ "IP Address", "bootp.option.slp_directory_agent.slpda_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 78: SLPDA Address", HFILL }},
{ &hf_bootp_option_slp_service_scope_value,
{ "Value", "bootp.option.slp_service_scope.value",
FT_UINT8, BASE_DEC, VALS(slp_scope_vals), 0x0,
"Option 79: SLP Service Scope Value", HFILL }},
{ &hf_bootp_option_slp_service_scope_string,
{ "SLP Service Scope", "bootp.option.slp_service_scope.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 79: SLP Service Scope", HFILL }},
{ &hf_bootp_option82_suboption,
{ "Option 82 Suboption", "bootp.option.agent_information_option.suboption",
FT_UINT8, BASE_DEC, VALS(option82_suboption_vals), 0x0,
"Option 82: Suboption", HFILL }},
{ &hf_bootp_option82_value,
{ "Value", "bootp.option.agent_information_option.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82: Suboption value", HFILL }},
{ &hf_bootp_option82_value_8,
{ "Value", "bootp.option.agent_information_option.value.uint",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82: Suboption 8-bit value", HFILL }},
{ &hf_bootp_option82_value_32,
{ "Value", "bootp.option.agent_information_option.value.uint",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Option 82: Suboption 32-bit value", HFILL }},
{ &hf_bootp_option82_value_ip_address,
{ "Value", "bootp.option.agent_information_option.value.address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 82: Suboption IP address", HFILL }},
{ &hf_bootp_option82_value_stringz,
{ "Value", "bootp.option.agent_information_option.value.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 82: Suboption Z-String value", HFILL }},
{ &hf_bootp_option82_padding,
{ "Padding", "bootp.option.agent_information_option.padding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82:0 Padding", HFILL }},
{ &hf_bootp_option82_agent_circuit_id,
{ "Agent Circuit ID", "bootp.option.agent_information_option.agent_circuit_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82:1 Agent Circuit ID", HFILL }},
{ &hf_bootp_option82_agent_remote_id,
{ "Agent Remote ID", "bootp.option.agent_information_option.agent_remote_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82:2 Agent Remote ID", HFILL }},
{ &hf_bootp_option82_reserved,
{ "Reserved", "bootp.option.agent_information_option.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82:3 Reserved", HFILL }},
{ &hf_bootp_option82_docsis_device_class,
{ "DOCSIS Device Class", "bootp.option.agent_information_option.docsis_device_class",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Option 82:4 DOCSIS Device Class", HFILL }},
{ &hf_bootp_option82_link_selection,
{ "Link selection", "bootp.option.agent_information_option.link_selection",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 82:5 Link selection", HFILL }},
{ &hf_bootp_option82_subscriber_id,
{ "Subscriber ID", "bootp.option.agent_information_option.subscriber_id",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 82:6 Subscriber ID", HFILL }},
{ &hf_bootp_option82_radius_attributes,
{ "RADIUS Attributes", "bootp.option.agent_information_option.radius_attributes",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82:7 RADIUS Attributes", HFILL }},
{ &hf_bootp_option82_authentication,
{ "Authentication", "bootp.option.agent_information_option.authentication",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82:8 Authentication", HFILL }},
{ &hf_bootp_option82_vi,
{ "Vendor-Specific Information", "bootp.option.agent_information_option.vi",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 82:9 Vendor-Specific Information", HFILL }},
{ &hf_bootp_option82_vi_enterprise,
{ "Enterprise", "bootp.option.agent_information_option.vi.enterprise",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x0,
"Option 82:9 VI Enterprise", HFILL }},
{ &hf_bootp_option82_vi_data_length,
{ "Data Length", "bootp.option.agent_information_option.vi.data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82:9 VI Data Length", HFILL }},
{ &hf_bootp_option82_vi_cl_option,
{ "Option", "bootp.option.agent_information_option.vi.cl.option",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82:9 VI CL Option", HFILL }},
{ &hf_bootp_option82_vi_cl_length,
{ "Length", "bootp.option.agent_information_option.vi.cl.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82:9 VI CL Length", HFILL }},
{ &hf_bootp_option82_vi_cl_tag,
{ "Tag", "bootp.option.agent_information_option.vi.cl.tag",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82:9 VI CL Tag", HFILL }},
{ &hf_bootp_option82_vi_cl_tag_length,
{ "Tag Length", "bootp.option.agent_information_option.vi.cl.tag_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 82:9 VI CL Tag Length", HFILL }},
{ &hf_bootp_option82_vi_cl_docsis_version,
{ "DOCSIS Version Number", "bootp.option.agent_information_option.vi.cl.docsis_version",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Option 82:9 VI CL DOCSIS Version Number", HFILL }},
{ &hf_bootp_option82_flags,
{ "Flags", "bootp.option.agent_information_option.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Option 82:10 Flags", HFILL }},
{ &hf_bootp_option82_server_id_override,
{ "Server ID Override", "bootp.option.agent_information_option.server_id_override",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 82:11 Server ID Override", HFILL }},
{ &hf_bootp_option82_link_selection_cisco,
{ "Link selection (Cisco proprietary)", "bootp.option.agent_information_option.link_selection_cisco",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 82:150 Link selection (Cisco proprietary)", HFILL }},
{ &hf_bootp_option82_vrf_name_vpn_id,
{ "VRF name/VPN ID", "bootp.option.agent_information_option.vrf_name_vpn_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Option 82:151 VRF name/VPN ID", HFILL }},
{ &hf_bootp_option82_vrf_name_vpn_id_oui,
{ "VRF name/VPN ID OUI", "bootp.option.agent_information_option.vrf_name_vpn_id_oui",
FT_UINT24, BASE_HEX, NULL, 0x00,
"Option 82:151 VRF name/VPN ID OUI", HFILL }},
{ &hf_bootp_option82_vrf_name_vpn_id_index,
{ "VRF name/VPN ID Index", "bootp.option.agent_information_option.vrf_name_vpn_id_index",
FT_UINT32, BASE_HEX, NULL, 0x00,
"Option 82:151 VRF name/VPN ID Index", HFILL }},
{ &hf_bootp_option82_server_id_override_cisco,
{ "Server ID Override (Cisco proprietary)", "bootp.option.agent_information_option.server_id_override_cisco",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 82:152 Server ID Override (Cisco proprietary)", HFILL }},
{ &hf_bootp_option_novell_dss_string,
{ "Novell Directory Services Servers String", "bootp.option.novell_dss.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 85: Novell Directory Services Servers String", HFILL }},
{ &hf_bootp_option_novell_dss_ip,
{ "IP Address", "bootp.option.novell_dss.ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 85: Novell Directory Services Servers IP Address", HFILL }},
{ &hf_bootp_option_novell_ds_tree_name,
{ "Novell Directory Services Tree Name", "bootp.option.novell_ds_tree_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 86: Novell Directory Services Tree Name", HFILL }},
{ &hf_bootp_option_novell_ds_context,
{ "Novell Directory Services Context", "bootp.option.novell_ds_context",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 87: Novell Directory Services Context", HFILL }},
{ &hf_bootp_option_dhcp_authentication_protocol,
{ "Protocol", "bootp.option.dhcp_authentication.protocol",
FT_UINT8, BASE_DEC, VALS(authen_protocol_vals), 0x0,
"Option 90: Authentication Protocol", HFILL }},
{ &hf_bootp_option_dhcp_authentication_alg_delay,
{ "Delay Algorithm", "bootp.option.dhcp_authentication.alg_delay",
FT_UINT8, BASE_DEC, VALS(authen_da_algo_vals), 0x0,
"Option 90: Delayed Authentication Algorithm", HFILL }},
{ &hf_bootp_option_dhcp_authentication_algorithm,
{ "Algorithm", "bootp.option.dhcp_authentication.algorithm",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 90: Authentication Algorithm", HFILL }},
{ &hf_bootp_option_dhcp_authentication_rdm,
{ "Replay Detection Method", "bootp.option.dhcp_authentication.rdm",
FT_UINT8, BASE_DEC, VALS(authen_rdm_vals), 0x0,
"Option 90: Replay Detection Method", HFILL }},
{ &hf_bootp_option_dhcp_authentication_rdm_replay_detection,
{ "RDM Replay Detection Value", "bootp.option.dhcp_authentication.rdm_replay_detection",
FT_UINT64, BASE_HEX, NULL, 0x0,
"Option 90: RDM Replay Detection Value", HFILL }},
{ &hf_bootp_option_dhcp_authentication_rdm_rdv,
{ "Replay Detection Value", "bootp.option.dhcp_authentication.rdm_rdv",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 90: Replay Detection Value", HFILL }},
{ &hf_bootp_option_dhcp_authentication_secret_id,
{ "Secret ID", "bootp.option.dhcp_authentication.secret_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Option 90: Secret ID", HFILL }},
{ &hf_bootp_option_dhcp_authentication_hmac_md5_hash,
{ "HMAC MD5 Hash", "bootp.option.dhcp_authentication.hmac_md5_hash",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 90: HMAC MD5 Hash", HFILL }},
{ &hf_bootp_option_dhcp_authentication_information,
{ "Authentication Information", "bootp.option.dhcp_authentication.information",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 90: Authentication Information", HFILL }},
{ &hf_bootp_option_client_last_transaction_time,
{ "Client last transaction time", "bootp.option.client_last_transaction_time",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Option 91: Client last transaction time", HFILL }},
{ &hf_bootp_option_associated_ip_option,
{ "Associated IP option", "bootp.option.associated_ip_option",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 92: Associated IP option", HFILL }},
{ &hf_bootp_option_client_system_architecture,
{ "Client System Architecture", "bootp.option.client_system_architecture",
FT_UINT16, BASE_DEC, VALS(bootp_client_arch), 0x0,
"Option 93: Client System Architecture", HFILL }},
{ &hf_bootp_option_client_network_id_major_ver,
{ "Major Version", "bootp.client_network_id_major",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 94: Major Version", HFILL }},
{ &hf_bootp_option_client_network_id_minor_ver,
{ "Minor Version", "bootp.client_network_id_minor",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 94: Minor Version", HFILL }},
{ &hf_bootp_option_civic_location_what,
{ "What", "bootp.option.civic_location.what",
FT_UINT8, BASE_DEC, VALS(civic_address_what_values), 0x0,
"Option 99: What", HFILL }},
{ &hf_bootp_option_civic_location_country,
{ "Country", "bootp.option.civic_location.country",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 99: Country", HFILL }},
{ &hf_bootp_option_civic_location_ca_type,
{ "CA Type", "bootp.option.civic_location.ca_type",
FT_UINT8, BASE_DEC, VALS(civic_address_type_values), 0x0,
"Option 99: CA Type", HFILL }},
{ &hf_bootp_option_civic_location_ca_length,
{ "CA Length", "bootp.option.civic_location.ca_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 99: CA Length", HFILL }},
{ &hf_bootp_option_civic_location_ca_value,
{ "CA Value", "bootp.option.civic_location.ca_value",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 99: CA Value", HFILL }},
{ &hf_bootp_option_netinfo_parent_server_address,
{ "NetInfo Parent Server Address", "bootp.option.netinfo_parent_server_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 112: NetInfo Parent Server Address", HFILL }},
{ &hf_bootp_option_netinfo_parent_server_tag,
{ "NetInfo Parent Server Tag", "bootp.option.netinfo_parent_server_tag",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 113: NetInfo Parent Server Tag", HFILL }},
{ &hf_bootp_option_dhcp_auto_configuration,
{ "DHCP Auto-Configuration", "bootp.option.dhcp_auto_configuration",
FT_UINT8, BASE_DEC, VALS(dhcp_autoconfig), 0x0,
"Option 116: DHCP Auto-Configuration", HFILL }},
{ &hf_bootp_option_dhcp_name_service_search_option,
{ "Name Service", "bootp.option.dhcp_name_service_search_option",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 117: Name Service", HFILL }},
{ &hf_bootp_option_dhcp_dns_domain_search_list_rfc_3396_detected,
{ "Encoding Long Options detected (RFC 3396)", "bootp.option.dhcp_dns_domain_search_list_rfc_3396_detected",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 119: Encoding Long Options detected (RFC 3396)", HFILL }},
{ &hf_bootp_option_dhcp_dns_domain_search_list_refer_last_option,
{ "For the data, please refer to last option 119", "bootp.option.dhcp_dns_domain_search_list_refer_last_option",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 119: For the data, please refer to last option 119", HFILL }},
{ &hf_bootp_option_dhcp_dns_domain_search_list_fqdn,
{ "FQDN", "bootp.option.dhcp_dns_domain_search_list_fqdn",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 119: FQDN", HFILL }},
{ &hf_bootp_option_sip_server_rfc_3396_detected,
{ "Encoding Long Options detected (RFC 3396)", "bootp.option.sip_server.rfc_3396_detected",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 120: Encoding Long Options detected (RFC 3396)", HFILL }},
{ &hf_bootp_option_sip_server_refer_last_option,
{ "For the data, please refer to last option 120", "bootp.option.sip_server.refer_last_option",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 120: For the data, please refer to last option 120", HFILL }},
{ &hf_bootp_option_sip_server_enc,
{ "SIP Server Encoding", "bootp.option.sip_server.encoding",
FT_UINT8, BASE_DEC, VALS(sip_server_enc_vals), 0x0,
"Option 120: SIP Server encoding", HFILL }},
{ &hf_bootp_option_sip_server_name,
{ "SIP Server Name", "bootp.option.sip_server.name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 120: SIP Server Name", HFILL }},
{ &hf_bootp_option_sip_server_address,
{ "SIP Server Address", "bootp.option.sip_server.address",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Option 120: SIP Server Address", HFILL }},
{ &hf_bootp_option_sip_server_address_stringz,
{ "SIP Server Address", "bootp.option.sip_server.address.stringz",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 120: SIP Server Address", HFILL }},
{ &hf_bootp_option_cl_dss_id_option,
{ "DSS_ID Type", "bootp.option.cl_dss_id.option",
FT_UINT8, BASE_DEC, VALS(cl_dss_id_type_vals), 0x0,
"Option 123:CL DSS_ID Type", HFILL }},
{ &hf_bootp_option_cl_dss_id_len,
{ "DSS_ID Length", "bootp.option.cl_dss_id.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 123:CL DSS_ID Length", HFILL }},
{ &hf_bootp_option_cl_dss_id,
{ "Country", "bootp.option.cl_dss_id",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 123:CL DSS_ID", HFILL }},
{ &hf_bootp_option_vi_class_cl_address_mode,
{ "CableLab Address Mode", "bootp.option.vi_class.cl_address_mode",
FT_UINT8, BASE_DEC, VALS(cablelab_ipaddr_mode_vals), 0x0,
"Option 124: CableLab Address Mode", HFILL }},
{ &hf_bootp_option_vi_class_enterprise,
{ "Enterprise", "bootp.option.vi_class.enterprise",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
"Option 124: Enterprise", HFILL }},
{ &hf_bootp_option_vi_class_data_length,
{ "CableLab Address Mode", "bootp.option.vi_class.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 124: Length", HFILL }},
{ &hf_bootp_option_vi_class_data,
{ "NetInfo Parent Server Tag", "bootp.option.vi_class.data",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 124: Data", HFILL }},
{ &hf_bootp_option125_enterprise,
{ "Enterprise", "bootp.option.vi.enterprise",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
"Option 125: Enterprise", HFILL }},
{ &hf_bootp_option125_value,
{ "Value", "bootp.option.vi.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 125: Suboption value", HFILL }},
{ &hf_bootp_option125_value_8,
{ "Value", "bootp.option.vi.value.uint",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 125: Suboption 8-bit value", HFILL }},
{ &hf_bootp_option125_value_16,
{ "Value", "bootp.option.vi.value.uint",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Option 125: Suboption 16-bit value", HFILL }},
{ &hf_bootp_option125_value_ip_address,
{ "Value", "bootp.option.vi.value.address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 125: Suboption IP address value", HFILL }},
{ &hf_bootp_option125_value_stringz,
{ "Value", "bootp.option.vi.value.string",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125: Suboption Z-String value", HFILL }},
{ &hf_bootp_option125_tr111_suboption,
{ "Option 125 Suboption", "bootp.option.vi.tr111.suboption",
FT_UINT8, BASE_DEC, VALS(option125_tr111_suboption_vals), 0x0,
"Option 125:TR 111 Suboption", HFILL }},
{ &hf_bootp_option125_tr111_device_manufacturer_oui,
{ "DeviceManufacturerOUI", "bootp.option.vi.tr111.device_manufacturer_oui",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125:TR 111 1 DeviceManufacturerOUI", HFILL }},
{ &hf_bootp_option125_tr111_device_serial_number,
{ "DeviceSerialNumber", "bootp.option.vi.tr111.device_serial_number",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125:TR 111 2 DeviceSerialNumber", HFILL }},
{ &hf_bootp_option125_tr111_device_product_class,
{ "DeviceProductClass", "bootp.option.vi.tr111.device_product_class",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125:TR 111 3 DeviceProductClass", HFILL }},
{ &hf_bootp_option125_tr111_gateway_manufacturer_oui,
{ "GatewayManufacturerOUI", "bootp.option.vi.tr111.gateway_manufacturer_oui",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125:TR 111 4 GatewayManufacturerOUI", HFILL }},
{ &hf_bootp_option125_tr111_gateway_serial_number,
{ "GatewaySerialNumber", "bootp.option.vi.tr111.gateway_serial_number",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125:TR 111 5 GatewaySerialNumber", HFILL }},
{ &hf_bootp_option125_tr111_gateway_product_class,
{ "GatewayProductClass", "bootp.option.vi.tr111.gateway_product_class",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 125:TR 111 6 GatewayProductClass", HFILL }},
{ &hf_bootp_option125_cl_suboption,
{ "Option 125 Suboption", "bootp.option.vi.cl.suboption",
FT_UINT8, BASE_DEC, VALS(option125_cl_suboption_vals), 0x0,
"Option 125:CL Suboption", HFILL }},
{ &hf_bootp_option125_cl_option_request,
{ "Option Request", "bootp.option.vi.cl.option_request",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 125:CL 1 Option Request", HFILL }},
{ &hf_bootp_option125_cl_tftp_server_addresses,
{ "TFTP Server Addresses", "bootp.option.vi.cl.tftp_server_addresses",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 125:CL 2 TFTP Server Addresses", HFILL }},
{ &hf_bootp_option125_cl_erouter_container_option,
{ "eRouter Container Option", "bootp.option.vi.cl.erouter_container_option",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 125:CL 3 eRouter Container Option", HFILL }},
{ &hf_bootp_option125_cl_mib_environment_indicator_option,
{ "MIB Environment Indicator Option", "bootp.option.vi.cl.suboption",
FT_UINT8, BASE_DEC, VALS(pkt_mib_env_ind_opt_vals), 0x0,
"Option 125:CL 4 MIB Environment Indicator Option", HFILL }},
{ &hf_bootp_option125_cl_modem_capabilities,
{ "Modem Capabilities", "bootp.option.vi.cl.modem_capabilities",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option 125:CL 5 Modem Capabilities", HFILL }},
{ &hf_bootp_option_subnet_selection_option,
{ "Subnet Selection Option", "bootp.option.subnet_selection_option",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 118: Subnet Selection Option", HFILL }},
{ &hf_bootp_option_lost_server_domain_name,
{ "LoST Server Domain Name", "bootp.option.lost_server_domain_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 137: LoST Server Domain Name", HFILL }},
{ &hf_bootp_option_capwap_access_controller,
{ "CAPWAP Access Controllers", "bootp.option.capwap_access_controller",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 138: CAPWAP Access Controllers", HFILL }},
{ &hf_bootp_option_tftp_server_address,
{ "TFTP Server Address", "bootp.option.tftp_server_address",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 150: TFTP Server Address", HFILL }},
{ &hf_bootp_option_6RD_ipv4_mask_len,
{ "6RD IPv4 Mask Length", "bootp.option.6RD.ipv4_mask_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 212: 6RD IPv4 Mask Length", HFILL }},
{ &hf_bootp_option_6RD_prefix_len,
{ "6RD Prefix Length", "bootp.option.6RD.prefix_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 212: 6RD Prefix Length", HFILL }},
{ &hf_bootp_option_6RD_prefix,
{ "6RD Prefix", "bootp.option.6RD.prefix",
FT_IPv6, BASE_NONE, NULL, 0x00,
"Option 212: 6RD Prefix", HFILL }},
{ &hf_bootp_option_6RD_border_relay_ip,
{ "Border Relay IP", "bootp.option.6RD.border_relay_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
"Option 212: Border Relay IP", HFILL }},
{ &hf_bootp_option_private_proxy_autodiscovery,
{ "Private/Proxy autodiscovery", "bootp.option.private_proxy_autodiscovery",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Option 252: Private/Proxy autodiscovery", HFILL }},
{ &hf_bootp_option_end,
{ "Option End", "bootp.option.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 255: End", HFILL }},
{ &hf_bootp_option_end_overload,
{ "Option End (Overload)", "bootp.option.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Option 255: End (Overload)", HFILL }},
};
static uat_field_t bootp_uat_flds[] = {
UAT_FLD_DEC(uat_bootp_records, opt, "Option number", "Custom Option Number"),
UAT_FLD_CSTRING(uat_bootp_records, text, "Option Name", "Custom Option Name"),
UAT_FLD_VS(uat_bootp_records, ftype, "Option type", bootp_custom_type_vals, "Option datatype"),
UAT_END_FIELDS
};
static gint *ett[] = {
&ett_bootp,
&ett_bootp_flags,
&ett_bootp_option,
&ett_bootp_option43_suboption,
&ett_bootp_option63_suboption,
&ett_bootp_option77_instance,
&ett_bootp_option82_suboption,
&ett_bootp_option82_suboption9,
&ett_bootp_option125_suboption,
&ett_bootp_fqdn,
};
module_t *bootp_module;
proto_bootp = proto_register_protocol("Bootstrap Protocol", "BOOTP/DHCP",
"bootp");
proto_register_field_array(proto_bootp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bootp_dhcp_tap = register_tap("bootp");
register_init_routine(&bootp_init_protocol);
register_dissector("bootp", dissect_bootp, proto_bootp);
bootp_module = prefs_register_protocol(proto_bootp, NULL);
prefs_register_bool_preference(bootp_module, "novellserverstring",
"Decode Option 85 as String",
"Novell Servers option 85 can be configured as a string instead of address",
&novell_string);
prefs_register_enum_preference(bootp_module, "pkt.ccc.protocol_version",
"PacketCable CCC protocol version",
"The PacketCable CCC protocol version",
&pkt_ccc_protocol_version,
pkt_ccc_protocol_versions,
FALSE);
prefs_register_uint_preference(bootp_module, "pkt.ccc.option",
"PacketCable CCC option",
"Option Number for PacketCable CableLabs Client Configuration",
10,
&pkt_ccc_option);
prefs_register_obsolete_preference(bootp_module, "displayasstring");
bootp_uat = uat_new("Custom BootP/DHCP Options (Excl. suboptions)",
sizeof(uat_bootp_record_t),
"custom_bootp",
TRUE,
(void**) &uat_bootp_records,
&num_bootp_records_uat,
UAT_AFFECTS_DISSECTION,
NULL,
uat_bootp_record_copy_cb,
uat_bootp_record_update_cb,
uat_bootp_record_free_cb,
NULL,
bootp_uat_flds);
prefs_register_uat_preference(bootp_module,
"custom_bootp_table",
"Custom BootP/DHCP Options (Excl. suboptions)",
"Custom BootP/DHCP Options (Excl. suboptions)",
bootp_uat);
}
void
proto_reg_handoff_bootp(void)
{
dissector_handle_t bootp_handle;
bootp_handle = create_dissector_handle(dissect_bootp, proto_bootp);
dissector_add_uint("udp.port", UDP_PORT_BOOTPS, bootp_handle);
dissector_add_uint("udp.port", UDP_PORT_BOOTPC, bootp_handle);
}
