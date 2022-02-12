static guint
get_xmcp_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return(XMCP_HDR_LEN + tvb_get_ntohs(tvb, offset+2));
}
static guint16
get_xmcp_attr_padded_len(guint16 attr_length)
{
return((attr_length + 3) & 0xfffc);
}
static guint16
get_xmcp_attr_fixed_len(guint16 xmcp_attr)
{
switch (xmcp_attr) {
case XMCP_CLIENT_HANDLE:
case XMCP_PROTOCOL_VERSION:
case XMCP_PAGE_SIZE:
case XMCP_KEEPALIVE:
case XMCP_SERVICE_PROTOCOL:
case XMCP_SERVICE_VERSION:
case XMCP_SUBSCRIPTION_ID:
case XMCP_SERVICE_REMOVED_REASON:
case XMCP_DOMAIN:
return(4);
case XMCP_SERVICE_IDENTITY:
return(20);
default:
return(0);
}
}
static guint16
get_xmcp_attr_min_len(guint16 xmcp_attr)
{
switch (xmcp_attr) {
case XMCP_USERNAME:
case XMCP_NONCE:
case XMCP_CLIENT_NAME:
case XMCP_CLIENT_LABEL:
return(1);
case XMCP_ERROR_CODE:
return(4);
case XMCP_SERVICE_TRANSPORT:
return(8);
case XMCP_MESSAGE_INTEGRITY:
return(20);
default:
return(get_xmcp_attr_fixed_len(xmcp_attr));
}
}
static guint16
get_xmcp_attr_max_len(guint16 xmcp_attr) {
guint16 fixed_len;
switch (xmcp_attr) {
case XMCP_SERVICE_TRANSPORT:
return(20);
case XMCP_MESSAGE_INTEGRITY:
return(32);
case XMCP_NONCE:
case XMCP_CLIENT_NAME:
case XMCP_CLIENT_LABEL:
return(255);
default:
fixed_len = get_xmcp_attr_fixed_len(xmcp_attr);
return(fixed_len ? fixed_len : 0xffff);
}
}
static void
add_xmcp_port_name (void)
{
if (!xmcp_it_service_port || xmcp_service_port == -1)
return;
switch(xmcp_service_protocol) {
case IP_PROTO_TCP:
proto_item_append_text(xmcp_it_service_port, " (TCP: %s)",
get_tcp_port(xmcp_service_port));
break;
case IP_PROTO_UDP:
proto_item_append_text(xmcp_it_service_port, " (UDP: %s)",
get_udp_port(xmcp_service_port));
break;
case IP_PROTO_DCCP:
proto_item_append_text(xmcp_it_service_port, " (DCCP: %s)",
get_dccp_port(xmcp_service_port));
break;
case IP_PROTO_SCTP:
proto_item_append_text(xmcp_it_service_port, " (SCTP: %s)",
get_sctp_port(xmcp_service_port));
break;
default:
break;
}
}
static void
decode_xmcp_attr_value (proto_tree *attr_tree, guint16 attr_type,
guint16 attr_length, tvbuff_t *tvb, guint16 offset,
packet_info *pinfo)
{
proto_item *it;
switch (attr_type) {
case XMCP_USERNAME:
proto_tree_add_item(attr_tree, xmcp_attr_username, tvb, offset,
attr_length, ENC_ASCII|ENC_NA);
proto_item_append_text(attr_tree, ": %s",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
if (xmcp_msg_type_method == XMCP_METHOD_REGISTER) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", user \"%s\"",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
}
break;
case XMCP_MESSAGE_INTEGRITY:
proto_tree_add_item(attr_tree, xmcp_attr_message_integrity, tvb, offset,
attr_length, ENC_NA);
if ((guint)(offset + get_xmcp_attr_padded_len(attr_length)) < tvb_reported_length(tvb)) {
expert_add_info(pinfo, attr_tree, &ei_xmcp_data_following_message_integrity);
}
break;
case XMCP_ERROR_CODE:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_error_reserved, tvb, offset,
3, ENC_BIG_ENDIAN);
proto_tree_add_item(attr_tree, xmcp_attr_error_class, tvb, offset,
3, ENC_BIG_ENDIAN);
{
guint8 error_class, error_number;
guint16 error_code;
it = proto_tree_add_item(attr_tree, xmcp_attr_error_number, tvb,
(offset+3), 1, ENC_BIG_ENDIAN);
error_class = tvb_get_guint8(tvb, offset+2) & 0x07;
error_number = tvb_get_guint8(tvb, offset+3);
if (error_number > 99) {
expert_add_info(pinfo, it, &ei_xmcp_attr_error_number_out_of_range);
} else {
error_code = (error_class * 100) + error_number;
it = proto_tree_add_uint(attr_tree, xmcp_attr_error_code, tvb,
(offset+2), 2, error_code);
PROTO_ITEM_SET_GENERATED(it);
proto_item_append_text(attr_tree, ": %d", error_code);
col_append_fstr(pinfo->cinfo, COL_INFO, ", error %d (%s)", error_code,
val_to_str_const(error_code, error_codes, "Unknown"));
switch (error_code) {
case 400:
case 431:
case 473:
case 476:
case 477:
case 499:
case 500:
expert_add_info_format(pinfo, it, &ei_xmcp_attr_error_code_unusual, "Unusual error code (%u, %s)", error_code, val_to_str_const(error_code, error_codes, "Unknown"));
break;
default:
break;
}
}
}
if (attr_length < 5)
break;
proto_tree_add_item(attr_tree, xmcp_attr_error_reason, tvb, (offset+4),
(attr_length - 4), ENC_ASCII|ENC_NA);
proto_item_append_text(attr_tree, " (%s)",
tvb_get_string(wmem_packet_scope(), tvb, (offset+4),
(attr_length-4)));
break;
case XMCP_REALM:
it = proto_tree_add_item(attr_tree, xmcp_attr_realm, tvb, offset,
attr_length, ENC_ASCII|ENC_NA);
{
guint8 *realm;
realm = tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length);
proto_item_append_text(attr_tree, ": %s", realm);
if (attr_length != 5 || strncmp(realm, "\"SAF\"", attr_length)) {
expert_add_info(pinfo, it, &ei_xmcp_attr_realm_incorrect);
}
}
break;
case XMCP_NONCE:
proto_tree_add_item(attr_tree, xmcp_attr_nonce, tvb, offset,
attr_length, ENC_ASCII|ENC_NA);
proto_item_append_text(attr_tree, ": %s",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
break;
case XMCP_CLIENT_NAME:
proto_tree_add_item(attr_tree, xmcp_attr_client_name, tvb, offset,
attr_length, ENC_ASCII|ENC_NA);
proto_item_append_text(attr_tree, ": %s",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
col_append_fstr(pinfo->cinfo, COL_INFO, ", name \"%s\"",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
break;
case XMCP_CLIENT_HANDLE:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_client_handle, tvb, offset,
4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u", tvb_get_ntohl(tvb, offset));
col_append_fstr(pinfo->cinfo, COL_INFO, ", handle %u",
tvb_get_ntohl(tvb, offset));
if (xmcp_msg_type_method == XMCP_METHOD_REGISTER &&
xmcp_msg_type_class == XMCP_CLASS_REQUEST) {
xmcp_msg_is_keepalive = TRUE;
}
break;
case XMCP_PROTOCOL_VERSION:
if (attr_length < 2)
break;
proto_tree_add_item(attr_tree, xmcp_attr_version_major, tvb, offset,
2, ENC_BIG_ENDIAN);
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_version_minor, tvb, (offset+2),
2, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u.%u", tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, (offset+2)));
break;
case XMCP_PAGE_SIZE:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_page_size, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u", tvb_get_ntohl(tvb, offset));
break;
case XMCP_CLIENT_LABEL:
proto_tree_add_item(attr_tree, xmcp_attr_client_label, tvb, offset,
attr_length, ENC_ASCII|ENC_NA);
proto_item_append_text(attr_tree, ": %s",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
col_append_fstr(pinfo->cinfo, COL_INFO, ", label \"%s\"",
tvb_get_string(wmem_packet_scope(), tvb, offset, attr_length));
break;
case XMCP_KEEPALIVE:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_keepalive, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u", tvb_get_ntohl(tvb, offset));
break;
case XMCP_SERVICE_IDENTITY:
if (attr_length < 2)
break;
proto_tree_add_item(attr_tree, xmcp_attr_serv_service, tvb, offset,
2, ENC_BIG_ENDIAN);
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_serv_subservice, tvb, (offset+2),
2, ENC_BIG_ENDIAN);
if (attr_length < 20)
break;
proto_tree_add_item(attr_tree, xmcp_attr_serv_instance, tvb, (offset+4),
16, ENC_BIG_ENDIAN);
{
e_guid_t guid;
char buf[GUID_STR_LEN];
tvb_get_guid(tvb, (offset+4), &guid, ENC_BIG_ENDIAN);
guid_to_str_buf(&guid, buf, sizeof(buf));
proto_item_append_text(attr_tree, ": %u:%u:%s",
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, (offset+2)), buf);
col_append_fstr(pinfo->cinfo, COL_INFO, ", service %u:%u:%s",
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, (offset+2)), buf);
}
break;
case XMCP_SERVICE_TRANSPORT:
if (attr_length < 1)
break;
proto_tree_add_item(attr_tree, xmcp_attr_reserved, tvb, offset, 1, ENC_NA);
if (attr_length < 2)
break;
proto_tree_add_item(attr_tree, xmcp_attr_servtrans_family, tvb,
(offset+1), 1, ENC_BIG_ENDIAN);
if (attr_length < 4)
break;
xmcp_service_port = tvb_get_ntohs(tvb, (offset+2));
xmcp_it_service_port = proto_tree_add_item(attr_tree,
xmcp_attr_servtrans_port,
tvb, (offset+2), 2, ENC_BIG_ENDIAN);
if (xmcp_service_protocol != -1) {
add_xmcp_port_name();
}
switch (tvb_get_guint8(tvb, (offset+1))) {
case 0x01:
if (attr_length != 8) {
expert_add_info_format(pinfo, attr_tree, &ei_xmcp_attr_length_bad, "Malformed IPv4 address");
} else {
guint32 ip;
proto_tree_add_item(attr_tree, xmcp_attr_servtrans_ipv4, tvb,
(offset+4), 4, ENC_BIG_ENDIAN);
ip = tvb_get_ipv4(tvb, (offset+4));
proto_item_append_text(attr_tree, ": %s:%u", ip_to_str((guint8 *)&ip),
tvb_get_ntohs(tvb, (offset+2)));
}
break;
case 0x02:
if (attr_length != 20) {
expert_add_info_format(pinfo, attr_tree, &ei_xmcp_attr_length_bad, "Malformed IPv6 address");
} else {
struct e_in6_addr ipv6;
proto_tree_add_item(attr_tree, xmcp_attr_servtrans_ipv6, tvb,
(offset+4), 16, ENC_NA);
tvb_get_ipv6(tvb, (offset+4), &ipv6);
proto_item_append_text(attr_tree, ": [%s]:%u", ip6_to_str(&ipv6),
tvb_get_ntohs(tvb, (offset+2)));
}
break;
default:
expert_add_info(pinfo, attr_tree, &ei_xmcp_xmcp_attr_servtrans_unknown);
break;
}
break;
case XMCP_SERVICE_PROTOCOL:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_reserved, tvb, offset, 3, ENC_NA);
proto_tree_add_item(attr_tree, xmcp_attr_service_protocol, tvb,
(offset+3), 1, ENC_BIG_ENDIAN);
xmcp_service_protocol = tvb_get_guint8(tvb, (offset+3));
proto_item_append_text(attr_tree, ": %u (%s)", xmcp_service_protocol,
val_to_str_ext_const(xmcp_service_protocol,
&ipproto_val_ext, "Unknown"));
if (xmcp_service_port != -1 && xmcp_it_service_port != NULL) {
add_xmcp_port_name();
}
break;
case XMCP_FLAGS:
if (attr_length % 4 != 0) {
expert_add_info_format(pinfo, attr_tree, &ei_xmcp_attr_length_bad, "Malformed Flags - length not divisible by 4");
}
{
guint16 flag_type, flag_value, current_offset = offset;
proto_item *ti;
proto_tree *flag_tree;
while ((current_offset-offset)+3 < attr_length) {
flag_type = tvb_get_ntohs(tvb, (current_offset));
flag_value = tvb_get_ntohs(tvb, (current_offset+2));
ti = proto_tree_add_none_format(attr_tree, xmcp_attr_flag, tvb,
current_offset, 4,
"Flag: %s:",
val_to_str_const(flag_type, flag_types,
"Unknown"));
flag_tree = proto_item_add_subtree(ti, ett_xmcp_attr_flag);
proto_tree_add_item(flag_tree, xmcp_attr_flag_type, tvb,
current_offset, 2, ENC_BIG_ENDIAN);
current_offset += 2;
switch (flag_type) {
case XMCP_FLAG_REMOVAL_REASON:
proto_tree_add_item(flag_tree, xmcp_attr_flag_removal_reason_reserved,
tvb, current_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree,
xmcp_attr_flag_removal_reason_network_withdraw,
tvb, current_offset, 2, ENC_BIG_ENDIAN);
if (flag_value & XMCP_REMOVAL_REASON_NETWORK_WITHDRAW) {
proto_item_append_text(flag_tree, " (network withdraw)");
}
if (!flag_value) {
proto_item_append_text(flag_tree, " (source withdraw)");
}
break;
case XMCP_FLAG_TRUST:
proto_tree_add_item(flag_tree, xmcp_attr_flag_trust, tvb,
current_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(flag_tree, " %s",
val_to_str_const(flag_value, flag_trust_values,
"Unknown"));
break;
case XMCP_FLAG_SERVICE_VISIBILITY:
proto_tree_add_item(flag_tree, xmcp_attr_flag_visibility_reserved,
tvb, current_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree,
xmcp_attr_flag_visibility_unauthenticated,
tvb, current_offset, 2, ENC_BIG_ENDIAN);
if (flag_value & XMCP_SERVICE_VISIBILITY_UNAUTHENTICATED) {
proto_item_append_text(flag_tree,
" (visible to unauthenticated clients)");
}
if (!flag_value) {
proto_item_append_text(flag_tree, " (default)");
}
break;
default:
proto_tree_add_item(flag_tree, xmcp_attr_flag_value, tvb,
current_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(flag_tree, " 0x%04x", flag_value);
break;
}
current_offset += 2;
}
}
break;
case XMCP_SERVICE_VERSION:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_service_version, tvb, offset,
4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u", tvb_get_ntohl(tvb, offset));
break;
case XMCP_SERVICE_DATA:
proto_tree_add_item(attr_tree, xmcp_attr_service_data, tvb, offset,
attr_length, ENC_NA);
if (attr_length > 0) {
tvbuff_t *next_tvb;
guint8 *test_string, *tok;
next_tvb = tvb_new_subset(tvb, offset, attr_length, attr_length);
test_string = tvb_get_string(wmem_packet_scope(), next_tvb, 0, (attr_length < 32 ?
attr_length : 32));
tok = strtok(test_string, " \t\r\n");
if (tok && tok[0] == '<') {
dissector_try_string(media_type_dissector_table, "application/xml",
next_tvb, pinfo, attr_tree);
} else {
dissector_try_string(media_type_dissector_table, "text/plain",
next_tvb, pinfo, attr_tree);
}
}
break;
case XMCP_SUBSCRIPTION_ID:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_subscription_id, tvb, offset,
4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u", tvb_get_ntohl(tvb, offset));
col_append_fstr(pinfo->cinfo, COL_INFO, ", subscription %u",
tvb_get_ntohl(tvb, offset));
break;
case XMCP_SERVICE_REMOVED_REASON:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_service_removed_reason, tvb,
offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %s",
val_to_str_const(tvb_get_ntohl(tvb, offset),
service_removed_reasons,
"Unknown"));
break;
case XMCP_DOMAIN:
if (attr_length < 4)
break;
proto_tree_add_item(attr_tree, xmcp_attr_domain, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(attr_tree, ": %u", tvb_get_ntohl(tvb, offset));
break;
default:
proto_tree_add_item(attr_tree, xmcp_attr_value, tvb, offset,
attr_length, ENC_NA);
expert_add_info(pinfo, attr_tree, &ei_xmcp_attr_type_unknown);
break;
}
if (attr_length % 4 != 0) {
proto_tree_add_item(attr_tree, xmcp_attr_padding, tvb, (offset+attr_length),
(4 - (attr_length % 4)), ENC_NA);
}
if (attr_length < get_xmcp_attr_min_len(attr_type)) {
expert_add_info_format(pinfo, attr_tree, &ei_xmcp_attr_length_bad, "Length less than minimum for this attribute type");
} else if (attr_length > get_xmcp_attr_max_len(attr_type)) {
expert_add_info_format(pinfo, attr_tree, &ei_xmcp_attr_length_bad, "Length exceeds maximum for this attribute type");
}
}
static void
dissect_xmcp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 msg_type, msg_length;
proto_item *ti = NULL;
proto_tree *xmcp_tree, *attr_all_tree, *attr_tree;
guint16 offset, attr_type, attr_length;
guint32 transaction_id[3];
wmem_tree_key_t transaction_id_key[2];
conversation_t *conversation;
xmcp_conv_info_t *xmcp_conv_info;
xmcp_transaction_t *xmcp_trans;
if (tvb_reported_length(tvb) < XMCP_HDR_LEN) {
return;
}
msg_type = tvb_get_ntohs(tvb, 0);
if (msg_type & XMCP_TYPE_RESERVED) {
return;
}
if (tvb_get_ntohl(tvb, 4) != XMCP_MAGIC_COOKIE) {
return;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "XMCP");
col_clear(pinfo->cinfo, COL_INFO);
xmcp_msg_type_class = ((msg_type & XMCP_TYPE_CLASS) >> 4);
xmcp_msg_type_method = (msg_type & XMCP_TYPE_METHOD);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str_const(xmcp_msg_type_method, methods, "Unknown"),
val_to_str_const(xmcp_msg_type_class, classes, "Unknown"));
transaction_id[0] = tvb_get_ntohl(tvb, 8);
transaction_id[1] = tvb_get_ntohl(tvb, 12);
transaction_id[2] = tvb_get_ntohl(tvb, 16);
transaction_id_key[0].length = 3;
transaction_id_key[0].key = transaction_id;
transaction_id_key[1].length = 0;
transaction_id_key[1].key = NULL;
conversation = find_or_create_conversation(pinfo);
xmcp_conv_info = (xmcp_conv_info_t *)conversation_get_proto_data(conversation, proto_xmcp);
if (!xmcp_conv_info) {
xmcp_conv_info = wmem_new(wmem_file_scope(), xmcp_conv_info_t);
xmcp_conv_info->transaction_pdus = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_xmcp, xmcp_conv_info);
}
xmcp_trans = (xmcp_transaction_t *)wmem_tree_lookup32_array(xmcp_conv_info->transaction_pdus,
transaction_id_key);
if (!xmcp_trans) {
xmcp_trans = wmem_new(wmem_file_scope(), xmcp_transaction_t);
xmcp_trans->request_frame = 0;
xmcp_trans->response_frame = 0;
xmcp_trans->request_time = pinfo->fd->abs_ts;
xmcp_trans->request_is_keepalive = FALSE;
wmem_tree_insert32_array(xmcp_conv_info->transaction_pdus,
transaction_id_key, (void *)xmcp_trans);
}
if (!pinfo->fd->flags.visited) {
if (xmcp_msg_type_class == XMCP_CLASS_REQUEST) {
if (xmcp_trans->request_frame == 0) {
xmcp_trans->request_frame = pinfo->fd->num;
xmcp_trans->request_time = pinfo->fd->abs_ts;
}
} else if (xmcp_msg_type_class != XMCP_CLASS_RESERVED) {
if (xmcp_trans->response_frame == 0) {
xmcp_trans->response_frame = pinfo->fd->num;
}
}
}
ti = proto_tree_add_item(tree, proto_xmcp, tvb, 0, -1, ENC_NA);
xmcp_tree = proto_item_add_subtree(ti, ett_xmcp);
ti = proto_tree_add_bitmask(xmcp_tree, tvb, 0, hf_xmcp_type, ett_xmcp_type,
xmcp_type_fields, ENC_BIG_ENDIAN);
if (msg_type & XMCP_TYPE_RESERVED) {
expert_add_info(pinfo, ti, &ei_xmcp_type_reserved_not_zero);
}
if (xmcp_msg_type_class == XMCP_CLASS_RESERVED) {
expert_add_info(pinfo, ti, &ei_xmcp_message_class_reserved);
} else if (xmcp_msg_type_class == XMCP_CLASS_RESPONSE_ERROR) {
expert_add_info(pinfo, ti, &ei_xmcp_error_response);
}
if (xmcp_msg_type_method < 0x001 || xmcp_msg_type_method > 0x00b) {
expert_add_info(pinfo, ti, &ei_xmcp_msg_type_method_reserved);
}
xmcp_msg_is_keepalive = (xmcp_trans->request_is_keepalive ||
(xmcp_msg_type_method == XMCP_METHOD_KEEPALIVE));
ti = proto_tree_add_item(xmcp_tree, hf_xmcp_length, tvb, 2, 2, ENC_BIG_ENDIAN);
msg_length = tvb_get_ntohs(tvb, 2);
if ((guint)(msg_length + XMCP_HDR_LEN) > tvb_reported_length(tvb)) {
expert_add_info_format(pinfo, ti, &ei_xmcp_length_bad, "XMCP message length (%u-byte header + %u) exceeds packet length (%u)", XMCP_HDR_LEN, msg_length, tvb_reported_length(tvb));
return;
}
ti = proto_tree_add_item(xmcp_tree, hf_xmcp_cookie, tvb, 4, 4, ENC_BIG_ENDIAN);
if (tvb_get_ntohl(tvb, 4) != XMCP_MAGIC_COOKIE) {
expert_add_info(pinfo, ti, &ei_xmcp_magic_cookie_incorrect);
}
ti = proto_tree_add_item(xmcp_tree, hf_xmcp_id, tvb, 8, 12, ENC_NA);
if (xmcp_msg_type_class == XMCP_CLASS_REQUEST) {
if (xmcp_trans->response_frame) {
ti = proto_tree_add_uint(xmcp_tree, hf_xmcp_response_in, tvb, 0, 0,
xmcp_trans->response_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
} else if (xmcp_msg_type_class != XMCP_CLASS_RESERVED) {
if (xmcp_trans->request_frame) {
nstime_t ns;
ti = proto_tree_add_uint(xmcp_tree, hf_xmcp_response_to, tvb, 0, 0,
xmcp_trans->request_frame);
PROTO_ITEM_SET_GENERATED(ti);
nstime_delta(&ns, &pinfo->fd->abs_ts, &xmcp_trans->request_time);
ti = proto_tree_add_time(xmcp_tree, hf_xmcp_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(ti);
} else {
expert_add_info(pinfo, ti, &ei_xmcp_response_without_request);
}
}
xmcp_service_protocol = -1;
xmcp_service_port = -1;
xmcp_it_service_port = NULL;
if (msg_length > 0) {
ti = proto_tree_add_item(xmcp_tree, hf_xmcp_attributes, tvb,
XMCP_HDR_LEN, msg_length, ENC_NA);
attr_all_tree = proto_item_add_subtree(ti, ett_xmcp_attr_all);
offset = XMCP_HDR_LEN;
while (offset < (msg_length + XMCP_HDR_LEN)) {
attr_type = tvb_get_ntohs(tvb, offset);
attr_length = tvb_get_ntohs(tvb, offset+2);
ti = proto_tree_add_none_format(attr_all_tree, hf_xmcp_attr, tvb, offset,
(XMCP_ATTR_HDR_LEN +
get_xmcp_attr_padded_len(attr_length)),
"%s, length %u",
val_to_str_const(attr_type, attributes,
"Unknown"),
attr_length);
attr_tree = proto_item_add_subtree(ti, ett_xmcp_attr);
proto_tree_add_item(attr_tree, xmcp_attr_type, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(attr_tree, xmcp_attr_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ((offset + attr_length) > (XMCP_HDR_LEN + msg_length)) {
proto_item_append_text(ti, " (bogus, exceeds message length)");
expert_add_info_format(pinfo, attr_tree, &ei_xmcp_attr_length_bad, "Attribute length exceeds message length");
break;
}
decode_xmcp_attr_value(attr_tree, attr_type, attr_length, tvb,
offset, pinfo);
offset += get_xmcp_attr_padded_len(attr_length);
}
}
if (xmcp_msg_is_keepalive) {
ti = proto_tree_add_none_format(xmcp_tree, hf_xmcp_msg_is_keepalive, tvb,
0, 0, "This is a Keepalive message");
PROTO_ITEM_SET_GENERATED(ti);
if (xmcp_msg_type_method != XMCP_METHOD_KEEPALIVE) {
col_prepend_fstr(pinfo->cinfo, COL_INFO, "[Keepalive] ");
}
if (xmcp_msg_type_class == XMCP_CLASS_REQUEST) {
xmcp_trans->request_is_keepalive = TRUE;
}
} else if (xmcp_msg_type_class == XMCP_CLASS_REQUEST ||
xmcp_msg_type_class == XMCP_CLASS_RESPONSE_SUCCESS) {
if (xmcp_msg_type_method == XMCP_METHOD_REGISTER) {
expert_add_info_format(pinfo, xmcp_tree, &ei_xmcp_new_session, "New session - Register %s", val_to_str_const(xmcp_msg_type_class, classes, ""));
} else if (xmcp_msg_type_method == XMCP_METHOD_UNREGISTER ||
xmcp_msg_type_method == XMCP_METHOD_REG_REVOKE) {
expert_add_info_format(pinfo, xmcp_tree, &ei_xmcp_session_termination, "Session termination - %s %s", val_to_str_const(xmcp_msg_type_method, methods, ""), val_to_str_const(xmcp_msg_type_class, classes, ""));
}
}
}
static void
dissect_xmcp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, XMCP_HDR_LEN,
get_xmcp_message_len, dissect_xmcp_message);
}
static gboolean
dissect_xmcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (tvb_length(tvb) < XMCP_HDR_LEN) {
return FALSE;
}
if (tvb_get_ntohs(tvb, 0) & XMCP_TYPE_RESERVED) {
return FALSE;
}
if (tvb_get_ntohl(tvb, 4) != XMCP_MAGIC_COOKIE) {
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, XMCP_HDR_LEN,
get_xmcp_message_len, dissect_xmcp_message);
return TRUE;
}
void
proto_register_xmcp(void)
{
static hf_register_info hf[] = {
{ &hf_xmcp_type,
{ "Message Type", "xmcp.type",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_xmcp_type_reserved,
{ "Reserved", "xmcp.type.reserved",
FT_UINT16, BASE_HEX, NULL, XMCP_TYPE_RESERVED, NULL, HFILL }
},
{ &hf_xmcp_type_class,
{ "Class", "xmcp.type.class",
FT_UINT16, BASE_HEX, VALS(classes), XMCP_TYPE_CLASS, NULL, HFILL }
},
{ &hf_xmcp_type_method,
{ "Method", "xmcp.type.method",
FT_UINT16, BASE_HEX, VALS(methods), XMCP_TYPE_METHOD, NULL, HFILL }
},
{ &hf_xmcp_msg_is_keepalive,
{ "Message is Keepalive", "xmcp.analysis.keepalive",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_xmcp_length,
{ "Message Length", "xmcp.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_xmcp_cookie,
{ "XMCP Magic Cookie", "xmcp.cookie",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_xmcp_id,
{ "Transaction ID", "xmcp.id",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_xmcp_response_in,
{ "Response In", "xmcp.response-in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this XMCP request is in this frame", HFILL }
},
{ &hf_xmcp_response_to,
{ "Response To", "xmcp.response-to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the XMCP request in this frame", HFILL }
},
{ &hf_xmcp_time,
{ "Elapsed Time", "xmcp.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Request and the Response", HFILL }
},
{ &hf_xmcp_attributes,
{ "Attributes", "xmcp.attributes",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_xmcp_attr,
{ "Attribute", "xmcp.attr",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_type,
{ "Attribute Type", "xmcp.attr.type",
FT_UINT16, BASE_HEX, VALS(attributes), 0x0, NULL, HFILL }
},
{ &xmcp_attr_length,
{ "Attribute Length", "xmcp.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_value,
{ "Attribute Value", "xmcp.attr.value",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &xmcp_attr_padding,
{ "Padding", "xmcp.attr.padding",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_reserved,
{ "Reserved", "xmcp.attr.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_username,
{ "Username", "xmcp.attr.username",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_message_integrity,
{ "Message-Integrity", "xmcp.attr.hmac",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_error_reserved,
{ "Reserved", "xmcp.attr.error.reserved",
FT_UINT24, BASE_HEX, NULL, 0xFFFFF8, NULL, HFILL }
},
{ &xmcp_attr_error_class,
{ "Error Class", "xmcp.attr.error.class",
FT_UINT24, BASE_DEC, NULL, 0x000007, NULL, HFILL}
},
{ &xmcp_attr_error_number,
{ "Error Number", "xmcp.attr.error.number",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &xmcp_attr_error_code,
{ "Error Code", "xmcp.attr.error",
FT_UINT16, BASE_DEC, VALS(error_codes), 0x0, NULL, HFILL}
},
{ &xmcp_attr_error_reason,
{ "Error Reason Phrase", "xmcp.attr.error.reason",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &xmcp_attr_realm,
{ "Realm", "xmcp.attr.realm",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_nonce,
{ "Nonce", "xmcp.attr.nonce",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_client_name,
{ "Client-Name", "xmcp.attr.client-name",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_client_handle,
{ "Client-Handle", "xmcp.attr.client-handle",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_version_major,
{ "Protocol Major Version", "xmcp.attr.version.major",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_version_minor,
{ "Protocol Minor Version", "xmcp.attr.version.minor",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_page_size,
{ "Page-Size", "xmcp.attr.page-size",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_client_label,
{ "Client-Label", "xmcp.attr.client-label",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_keepalive,
{ "Keepalive", "xmcp.attr.keepalive",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_serv_service,
{ "Service ID", "xmcp.attr.service.service",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_serv_subservice,
{ "Subservice ID", "xmcp.attr.service.subservice",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_serv_instance,
{ "Instance ID", "xmcp.attr.service.instance",
FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_servtrans_family,
{ "Family", "xmcp.attr.service.transport.family",
FT_UINT8, BASE_HEX, VALS(address_families), 0x0, NULL, HFILL }
},
{ &xmcp_attr_servtrans_port,
{ "Port", "xmcp.attr.service.transport.port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_servtrans_ipv4,
{ "IPv4 Address", "xmcp.attr.service.transport.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_servtrans_ipv6,
{ "IPv6 Address", "xmcp.attr.service.transport.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_service_protocol,
{ "Protocol", "xmcp.attr.service.transport.protocol",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, (&ipproto_val_ext),
0x0, NULL, HFILL }
},
{ &xmcp_attr_flag,
{ "Flag", "xmcp.attr.flag",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_flag_type,
{ "Flag Type", "xmcp.attr.flag.type",
FT_UINT16, BASE_HEX, VALS(flag_types), 0x0, NULL, HFILL }
},
{ &xmcp_attr_flag_value,
{ "Flag Value", "xmcp.attr.flag.value",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_flag_removal_reason_network_withdraw,
{ "Network Withdraw",
"xmcp.attr.flag.removal-reason.network-withdraw",
FT_BOOLEAN, 16, TFS(&tfs_true_false),
XMCP_REMOVAL_REASON_NETWORK_WITHDRAW, NULL, HFILL }
},
{ &xmcp_attr_flag_removal_reason_reserved,
{ "Reserved", "xmcp.attr.flag.removal-reason.reserved",
FT_UINT16, BASE_HEX, NULL, XMCP_REMOVAL_REASON_RESERVED, NULL, HFILL }
},
{ &xmcp_attr_flag_trust,
{ "Trust", "xmcp.attr.flag.trust",
FT_UINT16, BASE_HEX, VALS(flag_trust_values), 0x0, NULL, HFILL }
},
{ &xmcp_attr_flag_visibility_unauthenticated,
{ "Visible to Unauthenticated Clients",
"xmcp.attr.flag.service-visibility.unauthenticated",
FT_BOOLEAN, 16, TFS(&tfs_yes_no),
XMCP_SERVICE_VISIBILITY_UNAUTHENTICATED, NULL, HFILL }
},
{ &xmcp_attr_flag_visibility_reserved,
{ "Reserved", "xmcp.attr.flag.service-visibility.reserved",
FT_UINT16, BASE_HEX, NULL,
XMCP_SERVICE_VISIBILITY_RESERVED, NULL, HFILL }
},
{ &xmcp_attr_service_version,
{ "Service Version", "xmcp.attr.service.version",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_service_data,
{ "Service Data", "xmcp.attr.service.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_subscription_id,
{ "Subscription ID", "xmcp.attr.subscription-id",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &xmcp_attr_service_removed_reason,
{ "Service Removed Reason", "xmcp.attr.service-removed-reason",
FT_UINT32, BASE_DEC, VALS(service_removed_reasons), 0x0, NULL, HFILL }
},
{ &xmcp_attr_domain,
{ "Domain", "xmcp.attr.domain",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_xmcp,
&ett_xmcp_type,
&ett_xmcp_attr_all,
&ett_xmcp_attr,
&ett_xmcp_attr_flag
};
static ei_register_info ei[] = {
{ &ei_xmcp_data_following_message_integrity, { "xmcp.data_following_message_integrity", PI_PROTOCOL, PI_WARN, "Data following message-integrity", EXPFILL }},
{ &ei_xmcp_attr_error_number_out_of_range, { "xmcp.attr.error.number.out_of_range", PI_PROTOCOL, PI_WARN, "Error number out of 0-99 range", EXPFILL }},
{ &ei_xmcp_attr_error_code_unusual, { "xmcp.attr.error.unusual", PI_RESPONSE_CODE, PI_WARN, "Unusual error code", EXPFILL }},
{ &ei_xmcp_attr_realm_incorrect, { "xmcp.attr.realm.incorrect", PI_PROTOCOL, PI_WARN, "Incorrect Realm", EXPFILL }},
{ &ei_xmcp_attr_length_bad, { "xmcp.attr.length.bad", PI_PROTOCOL, PI_WARN, "Malformed IPv4 address", EXPFILL }},
{ &ei_xmcp_xmcp_attr_servtrans_unknown, { "xmcp.attr.service.transport.unknown", PI_PROTOCOL, PI_WARN, "Unknown transport type", EXPFILL }},
{ &ei_xmcp_attr_type_unknown, { "xmcp.attr.type.unknown", PI_PROTOCOL, PI_NOTE, "Unrecognized attribute type", EXPFILL }},
{ &ei_xmcp_type_reserved_not_zero, { "xmcp.type.reserved.not_zero", PI_PROTOCOL, PI_WARN, "First two bits not zero", EXPFILL }},
{ &ei_xmcp_message_class_reserved, { "xmcp.message_class.reserved", PI_PROTOCOL, PI_WARN, "Reserved message class", EXPFILL }},
{ &ei_xmcp_error_response, { "xmcp.error_response", PI_RESPONSE_CODE, PI_NOTE, "Error Response", EXPFILL }},
{ &ei_xmcp_msg_type_method_reserved, { "xmcp.msg_type_method.reserved", PI_PROTOCOL, PI_WARN, "Reserved message method", EXPFILL }},
{ &ei_xmcp_length_bad, { "xmcp.length.bad", PI_PROTOCOL, PI_ERROR, "XMCP message length exceeds packet length", EXPFILL }},
{ &ei_xmcp_magic_cookie_incorrect, { "xmcp.cookie.incorrect", PI_PROTOCOL, PI_WARN, "Magic cookie not correct for XMCP", EXPFILL }},
{ &ei_xmcp_response_without_request, { "xmcp.response_without_request", PI_SEQUENCE, PI_NOTE, "Response without corresponding request", EXPFILL }},
{ &ei_xmcp_new_session, { "xmcp.new_session", PI_SEQUENCE, PI_CHAT, "New session - Register", EXPFILL }},
{ &ei_xmcp_session_termination, { "xmcp.session_termination", PI_SEQUENCE, PI_CHAT, "Session termination", EXPFILL }},
};
module_t *xmcp_module;
expert_module_t* expert_xmcp;
proto_xmcp = proto_register_protocol("eXtensible Messaging Client Protocol",
"XMCP", "xmcp");
proto_register_field_array(proto_xmcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_xmcp = expert_register_protocol(proto_xmcp);
expert_register_field_array(expert_xmcp, ei, array_length(ei));
xmcp_module = prefs_register_protocol(proto_xmcp, proto_reg_handoff_xmcp);
prefs_register_uint_preference(xmcp_module, "tcp.port", "XMCP TCP Port",
"Set the port for XMCP messages (if other"
" than the default of 4788)",
10, &global_xmcp_tcp_port);
}
void
proto_reg_handoff_xmcp(void)
{
static gboolean xmcp_prefs_initialized = FALSE;
static dissector_handle_t xmcp_tcp_handle;
static guint xmcp_tcp_port;
if (!xmcp_prefs_initialized) {
xmcp_tcp_handle = create_dissector_handle(dissect_xmcp_tcp, proto_xmcp);
heur_dissector_add("tcp", dissect_xmcp_heur, proto_xmcp);
media_type_dissector_table = find_dissector_table("media_type");
xmcp_prefs_initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", xmcp_tcp_port, xmcp_tcp_handle);
}
xmcp_tcp_port = global_xmcp_tcp_port;
dissector_add_uint("tcp.port", global_xmcp_tcp_port, xmcp_tcp_handle);
}
