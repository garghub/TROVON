static void process_control_avps(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *l2tp_tree,
int idx,
int length)
{
proto_tree *l2tp_lcp_avp_tree, *l2tp_avp_tree, *l2tp_avp_tree_sub;
proto_item *tf, *te;
int msg_type;
gboolean isStopCcn = FALSE;
int avp_type;
guint32 avp_vendor_id;
guint16 avp_len;
guint16 ver_len_hidden;
int rhcode = 10;
tvbuff_t *next_tvb;
guint16 result_code;
guint16 error_code;
guint32 bits;
guint16 firmware_rev;
while (idx < length) {
ver_len_hidden = tvb_get_ntohs(tvb, idx);
avp_len = AVP_LENGTH(ver_len_hidden);
avp_vendor_id = tvb_get_ntohs(tvb, idx + 2);
avp_type = tvb_get_ntohs(tvb, idx + 4);
if (avp_len < 1) {
proto_tree_add_text(l2tp_tree, tvb, idx, 0,
"AVP length must be >= 1");
return;
}
if (avp_vendor_id == VENDOR_IETF) {
tf = proto_tree_add_text(l2tp_tree, tvb, idx,
avp_len, "%s AVP",
val_to_str(avp_type, avp_type_vals, "Unknown (%u)"));
} else if (avp_vendor_id == VENDOR_CISCO) {
tf = proto_tree_add_text(l2tp_tree, tvb, idx,
avp_len, "Vendor %s: %s AVP",
val_to_str_ext(avp_vendor_id, &sminmpec_values_ext, "Unknown (%u)"),
val_to_str(avp_type, cisco_avp_type_vals, "Unknown (%u)"));
} else {
tf = proto_tree_add_text(l2tp_tree, tvb, idx,
avp_len, "Vendor %s AVP Type %u",
val_to_str_ext(avp_vendor_id, &sminmpec_values_ext, "Unknown (%u)"),
avp_type);
}
l2tp_avp_tree = proto_item_add_subtree(tf, ett_l2tp_avp);
proto_tree_add_boolean_format(l2tp_avp_tree,hf_l2tp_avp_mandatory, tvb, idx, 1,
rhcode, "Mandatory: %s",
(MANDATORY_BIT(ver_len_hidden)) ? "True" : "False" );
proto_tree_add_boolean_format(l2tp_avp_tree,hf_l2tp_avp_hidden, tvb, idx, 1,
rhcode, "Hidden: %s",
(HIDDEN_BIT(ver_len_hidden)) ? "True" : "False" );
proto_tree_add_uint_format(l2tp_avp_tree,hf_l2tp_avp_length, tvb, idx, 2,
rhcode, "Length: %u", avp_len);
if (HIDDEN_BIT(ver_len_hidden)) {
idx += avp_len;
continue;
}
if (avp_len < 6) {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 0,
"AVP length must be >= 6");
return;
}
idx += 2;
avp_len -= 2;
if (avp_type == EXTENDED_VENDOR_ID) {
idx += 2;
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_vendor_id,
tvb, idx, 4, ENC_BIG_ENDIAN);
idx += 4;
continue;
}
else {
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_vendor_id,
tvb, idx, 2, ENC_BIG_ENDIAN);
idx += 2;
avp_len -= 2;
}
if (avp_vendor_id == VENDOR_CISCO) {
proto_tree_add_uint(l2tp_avp_tree, hf_l2tp_cisco_avp_type,
tvb, idx, 2, avp_type);
idx += 2;
avp_len -= 2;
switch (avp_type) {
case CISCO_ASSIGNED_CONNECTION_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Assigned Control Connection ID: %u",
tvb_get_ntohl(tvb, idx));
break;
case CISCO_PW_CAPABILITY_LIST:
te = proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Pseudowire Capabilities List");
l2tp_avp_tree_sub = proto_item_add_subtree(te, ett_l2tp_avp_sub);
while (avp_len >= 2) {
int pw_type = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree_sub, tvb, idx,
2, "PW Type: (%u) %s",
pw_type,
val_to_str(pw_type, pw_types_vals,
"Unknown (0x%04x)"));
idx += 2;
avp_len -= 2;
}
break;
case CISCO_LOCAL_SESSION_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Local Session ID: %u",
tvb_get_ntohl(tvb, idx));
break;
case CISCO_REMOTE_SESSION_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Remote Session ID: %u",
tvb_get_ntohl(tvb, idx));
break;
case CISCO_ASSIGNED_COOKIE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Assigned Cookie: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case CISCO_REMOTE_END_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Remote End ID: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case CISCO_PW_TYPE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Pseudowire Type: %u - %s",
tvb_get_ntohs(tvb, idx),
val_to_str(tvb_get_ntohs(tvb, idx),
pw_types_vals, "Unknown (0x%04x)"));
break;
case CISCO_CIRCUIT_STATUS:
bits = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Circuit Status: %s",
(CIRCUIT_STATUS_BIT(bits)) ? "Up" : "Down");
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Circuit Type: %s",
(CIRCUIT_TYPE_BIT(bits)) ? "New" : "Existing");
break;
case CISCO_SESSION_TIE_BREAKER:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_tie_breaker,
tvb, idx, 8, ENC_BIG_ENDIAN);
break;
case CISCO_DRAFT_AVP_VERSION:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Draft AVP Version: %u",
tvb_get_ntohs(tvb, idx));
break;
case CISCO_MESSAGE_DIGEST:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Message Digest: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case CISCO_AUTH_NONCE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Nonce: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case CISCO_INTERFACE_MTU:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Interface MTU: %u",
tvb_get_ntohs(tvb, idx));
break;
default:
proto_tree_add_text(l2tp_avp_tree, tvb, idx,
avp_len, "Vendor-Specific AVP");
break;
}
idx += avp_len;
continue;
} else if (avp_vendor_id != VENDOR_IETF) {
if (avp_len >= 2) {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Type: %u", avp_type);
idx += 2;
avp_len -= 2;
if (avp_len > 0) {
proto_tree_add_text(l2tp_avp_tree, tvb, idx,
avp_len, "Vendor-Specific AVP");
}
}
idx += avp_len;
continue;
}
proto_tree_add_uint(l2tp_avp_tree, hf_l2tp_avp_type,
tvb, idx, 2, avp_type);
idx += 2;
avp_len -= 2;
switch (avp_type) {
case CONTROL_MESSAGE:
msg_type = tvb_get_ntohs(tvb, idx);
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_message_type,
tvb, idx, 2, ENC_BIG_ENDIAN);
if (msg_type == MESSAGE_TYPE_StopCCN) {
isStopCcn = TRUE;
}
break;
case RESULT_ERROR_CODE:
if (avp_len < 2)
break;
result_code = tvb_get_ntohs(tvb, idx);
if (isStopCcn) {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Result code: %u - %s", result_code,
val_to_str(result_code, result_code_stopccn_vals, "Unknown (%u)"));
}
else {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Result code: %u - %s", result_code,
val_to_str(result_code, result_code_cdn_vals, "Unknown (%u)"));
}
idx += 2;
avp_len -= 2;
if (avp_len < 2)
break;
error_code = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Error code: %u - %s", error_code,
val_to_str(error_code, error_code_vals, "Unknown (%u)"));
idx += 2;
avp_len -= 2;
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Error Message: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case PROTOCOL_VERSION:
if (avp_len < 1)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 1,
"Version: %u", tvb_get_guint8(tvb, idx));
idx += 1;
avp_len -= 1;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 1,
"Revision: %u", tvb_get_guint8(tvb, idx));
break;
case FRAMING_CAPABILITIES:
bits = tvb_get_ntohl(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Async Framing Supported: %s",
(FRAMING_ASYNC(bits)) ? "True" : "False");
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Sync Framing Supported: %s",
(FRAMING_SYNC(bits)) ? "True" : "False");
break;
case BEARER_CAPABILITIES:
bits = tvb_get_ntohl(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Analog Access Supported: %s",
(BEARER_ANALOG(bits)) ? "True" : "False");
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Digital Access Supported: %s",
(BEARER_DIGITAL(bits)) ? "True" : "False");
break;
case TIE_BREAKER:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_tie_breaker, tvb, idx, 8, ENC_BIG_ENDIAN);
break;
case FIRMWARE_REVISION:
firmware_rev = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Firmware Revision: %d 0x%x", firmware_rev,firmware_rev );
break;
case HOST_NAME:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Host Name: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case VENDOR_NAME:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Vendor Name: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case ASSIGNED_TUNNEL_ID:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_assigned_tunnel_id, tvb, idx, 2, ENC_BIG_ENDIAN);
break;
case RECEIVE_WINDOW_SIZE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Receive Window Size: %u",
tvb_get_ntohs(tvb, idx));
break;
case CHALLENGE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"CHAP Challenge: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case CAUSE_CODE:
if (avp_len < 2)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Cause Code: %u",
tvb_get_ntohs(tvb, idx));
idx += 2;
avp_len -= 2;
if (avp_len < 1)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 1,
"Cause Msg: %u",
tvb_get_guint8(tvb, idx));
idx += 1;
avp_len -= 1;
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Advisory Msg: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case CHALLENGE_RESPONSE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 16,
"CHAP Challenge Response: %s",
tvb_bytes_to_str(tvb, idx, 16));
break;
case ASSIGNED_SESSION:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_assigned_session_id, tvb, idx, 2, ENC_BIG_ENDIAN);
break;
case CALL_SERIAL_NUMBER:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Call Serial Number: %u",
tvb_get_ntohl(tvb, idx));
break;
case MINIMUM_BPS:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Minimum BPS: %u",
tvb_get_ntohl(tvb, idx));
break;
case MAXIMUM_BPS:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Maximum BPS: %u",
tvb_get_ntohl(tvb, idx));
break;
case BEARER_TYPE:
bits = tvb_get_ntohl(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Analog Bearer Type: %s",
(BEARER_ANALOG(bits)) ? "True" : "False");
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Digital Bearer Type: %s",
(BEARER_DIGITAL(bits)) ? "True" : "False");
break;
case FRAMING_TYPE:
bits = tvb_get_ntohl(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Async Framing Type: %s",
(FRAMING_ASYNC(bits)) ? "True" : "False");
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Sync Framing Type: %s",
(FRAMING_SYNC(bits)) ? "True" : "False");
break;
case CALLED_NUMBER:
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Called Number: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case CALLING_NUMBER:
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Calling Number: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case SUB_ADDRESS:
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Sub-Address: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case TX_CONNECT_SPEED:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Connect Speed: %u",
tvb_get_ntohl(tvb, idx));
break;
case PHYSICAL_CHANNEL:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Physical Channel: %u",
tvb_get_ntohl(tvb, idx));
break;
case INITIAL_RECEIVED_LCP_CONFREQ:
te = proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Initial Received LCP CONFREQ: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
l2tp_lcp_avp_tree = proto_item_add_subtree(te, ett_l2tp_lcp);
next_tvb = tvb_new_subset(tvb, idx, avp_len, avp_len);
call_dissector(ppp_lcp_options_handle, next_tvb, pinfo, l2tp_lcp_avp_tree );
break;
case LAST_SENT_LCP_CONFREQ:
te = proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Last Sent LCP CONFREQ: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
l2tp_lcp_avp_tree = proto_item_add_subtree(te, ett_l2tp_lcp);
next_tvb = tvb_new_subset(tvb, idx, avp_len, avp_len);
call_dissector(ppp_lcp_options_handle, next_tvb, pinfo, l2tp_lcp_avp_tree );
break;
case LAST_RECEIVED_LCP_CONFREQ:
te = proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Last Received LCP CONFREQ: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
l2tp_lcp_avp_tree = proto_item_add_subtree(te, ett_l2tp_lcp);
next_tvb = tvb_new_subset(tvb, idx, avp_len, avp_len);
call_dissector(ppp_lcp_options_handle, next_tvb, pinfo, l2tp_lcp_avp_tree );
break;
case PROXY_AUTHEN_TYPE:
msg_type = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Proxy Authen Type: %s",
val_to_str(msg_type, authen_type_vals, "Unknown (%u)"));
break;
case PROXY_AUTHEN_NAME:
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Proxy Authen Name: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case PROXY_AUTHEN_CHALLENGE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Proxy Authen Challenge: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case PROXY_AUTHEN_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx + 1, 1,
"Proxy Authen ID: %u",
tvb_get_guint8(tvb, idx + 1));
break;
case PROXY_AUTHEN_RESPONSE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Proxy Authen Response: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case CALL_STATUS_AVPS:
if (avp_len < 2)
break;
idx += 2;
avp_len -= 2;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"CRC Errors: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Framing Errors: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Hardware Overruns: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Buffer Overruns: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Time-out Errors: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Alignment Errors: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
break;
case ACCM:
if (avp_len < 2)
break;
idx += 2;
avp_len -= 2;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Send ACCM: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
if (avp_len < 4)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Receive ACCM: %u", tvb_get_ntohl(tvb, idx));
idx += 4;
avp_len -= 4;
break;
case RANDOM_VECTOR:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Random Vector: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case PRIVATE_GROUP_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Private Group ID: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case RX_CONNECT_SPEED:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Rx Connect Speed: %u",
tvb_get_ntohl(tvb, idx));
break;
case PPP_DISCONNECT_CAUSE_CODE:
if (avp_len < 2)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Disconnect Code: %u",
tvb_get_ntohs(tvb, idx));
idx += 2;
avp_len -= 2;
if (avp_len < 2)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Control Protocol Number: %u",
tvb_get_ntohs(tvb, idx));
idx += 2;
avp_len -= 2;
if (avp_len < 1)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 1,
"Direction: %s",
val_to_str(tvb_get_guint8(tvb, idx),
cause_code_direction_vals,
"Reserved (%u)"));
idx += 1;
avp_len -= 1;
if (avp_len == 0)
break;
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Message: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case MESSAGE_DIGEST:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Message Digest: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case ROUTER_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 4,
"Router ID: %u",
tvb_get_ntohl(tvb, idx));
break;
case ASSIGNED_CONTROL_CONN_ID:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_assigned_control_conn_id,
tvb, idx, 4, ENC_BIG_ENDIAN);
break;
case PW_CAPABILITY_LIST:
te = proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Pseudowire Capabilities List");
l2tp_avp_tree_sub = proto_item_add_subtree(te, ett_l2tp_avp_sub);
while (avp_len >= 2) {
int pw_type = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree_sub, tvb, idx,
2, "PW Type: (%u) %s",
pw_type,
val_to_str(pw_type, pw_types_vals,
"Unknown (0x%04x)"));
idx += 2;
avp_len -= 2;
}
break;
case LOCAL_SESSION_ID:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_local_session_id,
tvb, idx, 4, ENC_BIG_ENDIAN);
break;
case REMOTE_SESSION_ID:
proto_tree_add_item(l2tp_avp_tree, hf_l2tp_avp_remote_session_id,
tvb, idx, 4, ENC_BIG_ENDIAN);
break;
case ASSIGNED_COOKIE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Assigned Cookie: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case REMOTE_END_ID:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Remote End ID: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case PW_TYPE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Pseudowire Type: %u - %s",
tvb_get_ntohs(tvb, idx),
val_to_str(tvb_get_ntohs(tvb, idx),
pw_types_vals, "Unknown (0x%04x)"));
break;
case L2_SPECIFIC_SUBLAYER:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Layer2 Specific Sublayer: %s",
val_to_str(tvb_get_ntohs(tvb, idx),
l2_sublayer_vals, "Invalid (%u)"));
break;
case DATA_SEQUENCING:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Data Sequencing: %s",
val_to_str(tvb_get_ntohs(tvb, idx),
data_sequencing_vals, "Invalid (%u)"));
break;
case CIRCUIT_STATUS:
bits = tvb_get_ntohs(tvb, idx);
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Circuit Status: %s",
(CIRCUIT_STATUS_BIT(bits)) ? "Up" : "Down");
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 2,
"Circuit Type: %s",
(CIRCUIT_TYPE_BIT(bits)) ? "New" : "Existing");
break;
case PREFERRED_LANGUAGE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Preferred Language: %s",
tvb_format_text(tvb, idx, avp_len));
break;
case CTL_MSG_AUTH_NONCE:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Nonce: %s",
tvb_bytes_to_str(tvb, idx, avp_len));
break;
case TX_CONNECT_SPEED_V3:
{
guint32 l_int, h_int;
if (avp_len < 8)
break;
h_int = tvb_get_ntohl(tvb, idx);
l_int = tvb_get_ntohl(tvb, idx+4);
if (!h_int && !l_int) {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 8,
"Tx Connect Speed v3: indeterminable or no physical p2p link");
}
else {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 8,
"Tx Connect Speed v3: %#x%04x",
h_int, l_int);
}
break;
}
case RX_CONNECT_SPEED_V3:
{
guint32 l_int, h_int;
if (avp_len < 8)
break;
h_int = tvb_get_ntohl(tvb, idx);
l_int = tvb_get_ntohl(tvb, idx+4);
if (!h_int && !l_int) {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 8,
"Rx Connect Speed v3: indeterminable or no physical p2p link");
}
else {
proto_tree_add_text(l2tp_avp_tree, tvb, idx, 8,
"Rx Connect Speed v3: %#x%04x",
h_int, l_int);
}
break;
}
default:
proto_tree_add_text(l2tp_avp_tree, tvb, idx, avp_len,
"Unknown AVP");
break;
}
idx += avp_len;
}
}
static void
process_l2tpv3_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *l2tp_tree, proto_item *l2tp_item, int *pIdx)
{
int idx = *pIdx;
int sid;
guint8 oam_cell = 0;
proto_tree *l2_specific = NULL;
proto_item *ti = NULL;
tvbuff_t *next_tvb;
sid = tvb_get_ntohl(tvb, idx);
idx += 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo,COL_INFO,
"%s (session id=%u)",
data_msg, sid);
}
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_sid, tvb, idx-4, 4, ENC_BIG_ENDIAN);
proto_item_set_len(l2tp_item, idx);
if (!(tvb_offset_exists(tvb, idx)))
return;
if (l2tpv3_cookie != 0)
proto_tree_add_item(l2tp_tree, hf_l2tp_cookie, tvb, idx, l2tpv3_cookie, ENC_NA);
}
switch(l2tpv3_l2_specific){
case L2TPv3_L2_SPECIFIC_DEFAULT:
if (tree) {
ti = proto_tree_add_item(tree, hf_l2tp_l2_spec_def,
tvb, idx + l2tpv3_cookie, 4, ENC_NA);
l2_specific = proto_item_add_subtree(ti, ett_l2tp_l2_spec);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_s, tvb, idx + l2tpv3_cookie,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_sequence, tvb,
idx + l2tpv3_cookie + 1, 3, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, idx + l2tpv3_cookie + 4);
break;
case L2TPv3_L2_SPECIFIC_DOCSIS_DMPT:
if (tree) {
ti = proto_tree_add_item(tree, hf_l2tp_l2_spec_docsis_dmpt,
tvb, idx + l2tpv3_cookie, 4, ENC_NA);
l2_specific = proto_item_add_subtree(ti, ett_l2tp_l2_spec);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_v, tvb,
idx + l2tpv3_cookie,1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_s, tvb,
idx + l2tpv3_cookie,1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_flow_id, tvb,
idx + l2tpv3_cookie,1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_sequence, tvb,
idx + l2tpv3_cookie + 2,2, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, idx + l2tpv3_cookie + 4);
break;
case L2TPv3_L2_SPECIFIC_ATM:
if (tree) {
ti = proto_tree_add_item(tree, hf_l2tp_l2_spec_atm,
tvb, idx + l2tpv3_cookie, 4, ENC_NA);
l2_specific = proto_item_add_subtree(ti, ett_l2tp_l2_spec);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_s, tvb, idx + l2tpv3_cookie,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_t, tvb, idx + l2tpv3_cookie,
1, ENC_BIG_ENDIAN);
oam_cell = tvb_get_guint8(tvb, idx + l2tpv3_cookie) & 0x08;
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_g, tvb, idx + l2tpv3_cookie,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_c, tvb, idx + l2tpv3_cookie,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_u, tvb, idx + l2tpv3_cookie,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(l2_specific, hf_l2tp_l2_spec_sequence, tvb,
idx + l2tpv3_cookie + 1, 3, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, idx + l2tpv3_cookie + 4);
break;
case L2TPv3_L2_SPECIFIC_LAPD:
if (tree)
proto_tree_add_text(tree, tvb, idx + l2tpv3_cookie + 4, 3,"LAPD info");
next_tvb = tvb_new_subset_remaining(tvb, idx + l2tpv3_cookie+4+3);
break;
case L2TPv3_L2_SPECIFIC_NONE:
default:
next_tvb = tvb_new_subset_remaining(tvb, idx + l2tpv3_cookie);
break;
}
switch(l2tpv3_protocol){
case L2TPv3_PROTOCOL_ETH:
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_CHDLC:
call_dissector(chdlc_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_FR:
call_dissector(fr_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_PPP:
call_dissector(ppp_hdlc_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_IP:
call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_MPLS:
call_dissector(mpls_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_DOCSIS_DMPT:
call_dissector(mp2t_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_AAL5:
if (oam_cell) {
call_dissector(atm_oam_handle, next_tvb, pinfo, tree);
} else {
call_dissector(llc_handle, next_tvb, pinfo, tree);
}
break;
case L2TPv3_PROTOCOL_LAPD:
call_dissector(lapd_handle, next_tvb, pinfo, tree);
break;
case L2TPv3_PROTOCOL_ERICSSON:
call_dissector(ehdlc_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
}
static void
process_l2tpv3_data_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *l2tp_tree = NULL, *ctrl_tree;
proto_item *l2tp_item = NULL, *ti;
int idx = 0;
int control;
int sid;
control = tvb_get_ntohs(tvb, idx);
idx += 2;
idx += 2;
sid = tvb_get_ntohl(tvb, idx);
if (tree) {
l2tp_item = proto_tree_add_item(tree, proto_l2tp, tvb, 0, -1, ENC_NA);
l2tp_tree = proto_item_add_subtree(l2tp_item, ett_l2tp);
proto_item_append_text(l2tp_item, " version 3");
ti = proto_tree_add_text(l2tp_tree, tvb, 0, 2,
"Packet Type: %s Session Id=%u",
data_msg, sid);
ctrl_tree = proto_item_add_subtree(ti, ett_l2tp_ctrl);
proto_tree_add_uint(ctrl_tree, hf_l2tp_type, tvb, 0, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_length_bit, tvb, 0, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_seq_bit, tvb, 0, 2, control);
proto_tree_add_uint(ctrl_tree, hf_l2tp_version, tvb, 0, 2, control);
proto_tree_add_item(l2tp_tree, hf_l2tp_res, tvb, 2, 2, ENC_BIG_ENDIAN);
}
process_l2tpv3_data(tvb, pinfo, tree, l2tp_tree, l2tp_item, &idx);
}
static void
process_l2tpv3_data_ip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *l2tp_tree = NULL;
proto_item *l2tp_item = NULL;
int idx = 0;
int sid;
sid = tvb_get_ntohl(tvb, idx);
if (tree) {
l2tp_item = proto_tree_add_item(tree, proto_l2tp, tvb, 0, -1, ENC_NA);
l2tp_tree = proto_item_add_subtree(l2tp_item, ett_l2tp);
proto_item_append_text(l2tp_item, " version 3");
proto_tree_add_text(l2tp_tree, tvb, 0, 4,
"Packet Type: %s Session Id=%u",
data_msg, sid);
}
process_l2tpv3_data(tvb, pinfo, tree, l2tp_tree, l2tp_item, &idx);
}
static void
process_l2tpv3_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int baseIdx)
{
proto_tree *l2tp_tree = NULL, *ctrl_tree;
proto_item *l2tp_item = NULL, *ti;
int idx = baseIdx;
int tmp_idx;
guint16 length = 0;
guint32 ccid = 0;
guint16 avp_type;
guint16 msg_type;
guint16 control = 0;
control = tvb_get_ntohs(tvb, idx);
idx += 2;
if (LENGTH_BIT(control)) {
length = tvb_get_ntohs(tvb, idx);
idx += 2;
}
ccid = tvb_get_ntohl(tvb, idx);
idx += 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
tmp_idx = idx;
if ((LENGTH_BIT(control))&&(length==12))
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s - ZLB (tunnel id=%u)",
control_msg , ccid);
else
{
if (SEQUENCE_BIT(control)) {
tmp_idx += 4;
}
tmp_idx+=4;
avp_type = tvb_get_ntohs(tvb, tmp_idx);
tmp_idx += 2;
if (avp_type == CONTROL_MESSAGE) {
msg_type = tvb_get_ntohs(tvb, tmp_idx);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s - %s (tunnel id=%u)",
control_msg ,
val_to_str(msg_type, l2tp_message_type_short_str_vals, "Unknown (%u)"),
ccid);
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (tunnel id=%u)",
control_msg, ccid);
}
}
}
if (LENGTH_BIT(control)) {
set_actual_length(tvb, length+baseIdx);
}
if (tree) {
l2tp_item = proto_tree_add_item(tree, proto_l2tp, tvb, 0, -1, ENC_NA);
l2tp_tree = proto_item_add_subtree(l2tp_item, ett_l2tp);
proto_item_append_text(l2tp_item, " version 3");
if (baseIdx) {
proto_tree_add_item(l2tp_tree, hf_l2tp_sid, tvb, 0, 4, ENC_BIG_ENDIAN);
}
ti = proto_tree_add_text(l2tp_tree, tvb, baseIdx, 2,
"Packet Type: %s Control Connection Id=%d",
(CONTROL_BIT(control) ? control_msg : data_msg), ccid);
ctrl_tree = proto_item_add_subtree(ti, ett_l2tp_ctrl);
proto_tree_add_uint(ctrl_tree, hf_l2tp_type, tvb, baseIdx, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_length_bit, tvb, baseIdx, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_seq_bit, tvb, baseIdx, 2, control);
proto_tree_add_uint(ctrl_tree, hf_l2tp_version, tvb, baseIdx, 2, control);
}
idx = baseIdx + 2;
if (LENGTH_BIT(control)) {
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_length, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
}
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_ccid, tvb, idx, 4, ENC_BIG_ENDIAN);
}
idx += 4;
if (SEQUENCE_BIT(control)) {
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_Ns, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_Nr, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
}
if (tree && (LENGTH_BIT(control))&&(length==12)) {
proto_tree_add_text(l2tp_tree, tvb, 0, 0, "Zero Length Bit message");
}
if (!LENGTH_BIT(control)) {
return;
}
process_control_avps(tvb, pinfo, l2tp_tree, idx, length+baseIdx);
}
static int
dissect_l2tp_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *l2tp_tree = NULL, *ctrl_tree;
proto_item *l2tp_item = NULL, *ti;
int idx = 0;
int tmp_idx;
guint16 length = 0;
guint16 tid;
guint16 cid;
guint16 offset_size;
guint16 avp_type;
guint16 msg_type;
guint16 control;
tvbuff_t *next_tvb;
if (tvb_length(tvb) < 2)
return 0;
control = tvb_get_ntohs(tvb, 0);
switch (L2TP_VERSION(control)) {
case 2:
case 3:
break;
default:
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "L2TP");
col_clear(pinfo->cinfo, COL_INFO);
switch (L2TP_VERSION(control)) {
case 2:
break;
case 3:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "L2TPv3");
if (CONTROL_BIT(control)) {
process_l2tpv3_control(tvb, pinfo, tree, 0);
}
else {
process_l2tpv3_data_udp(tvb, pinfo, tree);
}
return tvb_length(tvb);
}
if (LENGTH_BIT(control)) {
idx += 2;
length = tvb_get_ntohs(tvb, idx);
}
idx += 2;
tid = tvb_get_ntohs(tvb, idx);
idx += 2;
cid = tvb_get_ntohs(tvb, idx);
if (check_col(pinfo->cinfo, COL_INFO)) {
if (CONTROL_BIT(control)) {
tmp_idx = idx;
if ((LENGTH_BIT(control))&&(length==12))
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s - ZLB (tunnel id=%d, session id=%u)",
control_msg, tid, cid);
else
{
if (SEQUENCE_BIT(control)) {
tmp_idx += 4;
}
tmp_idx+=4;
avp_type = tvb_get_ntohs(tvb, (tmp_idx+=2));
if (avp_type == CONTROL_MESSAGE) {
msg_type = tvb_get_ntohs(tvb, tmp_idx+2);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s - %s (tunnel id=%u, session id=%u)",
control_msg,
val_to_str(msg_type, l2tp_message_type_short_str_vals, "Unknown (%u)"),
tid, cid);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (tunnel id=%u, session id=%u)",
control_msg, tid, cid);
}
}
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (tunnel id=%u, session id=%u)",
data_msg, tid, cid);
}
}
if (LENGTH_BIT(control)) {
set_actual_length(tvb, length);
}
if (tree) {
l2tp_item = proto_tree_add_item(tree,proto_l2tp, tvb, 0, -1, ENC_NA);
l2tp_tree = proto_item_add_subtree(l2tp_item, ett_l2tp);
ti = proto_tree_add_text(l2tp_tree, tvb, 0, 2,
"Packet Type: %s Tunnel Id=%d Session Id=%d",
(CONTROL_BIT(control) ? control_msg : data_msg), tid, cid);
ctrl_tree = proto_item_add_subtree(ti, ett_l2tp_ctrl);
proto_tree_add_uint(ctrl_tree, hf_l2tp_type, tvb, 0, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_length_bit, tvb, 0, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_seq_bit, tvb, 0, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_offset_bit, tvb, 0, 2, control);
proto_tree_add_boolean(ctrl_tree, hf_l2tp_priority, tvb, 0, 2, control);
proto_tree_add_uint(ctrl_tree, hf_l2tp_version, tvb, 0, 2, control);
}
idx = 2;
if (LENGTH_BIT(control)) {
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_length, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
}
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_tunnel, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_session, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
if (SEQUENCE_BIT(control)) {
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_Ns, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
if (tree) {
proto_tree_add_item(l2tp_tree, hf_l2tp_Nr, tvb, idx, 2, ENC_BIG_ENDIAN);
}
idx += 2;
}
if (OFFSET_BIT(control)) {
offset_size = tvb_get_ntohs(tvb, idx);
if (tree) {
proto_tree_add_uint(l2tp_tree, hf_l2tp_offset, tvb, idx, 2,
offset_size);
}
idx += 2;
if (offset_size != 0) {
if (tree) {
proto_tree_add_text(l2tp_tree, tvb, idx, offset_size, "Offset Padding");
}
idx += offset_size;
}
}
if (tree && (LENGTH_BIT(control))&&(length==12)) {
proto_tree_add_text(l2tp_tree, tvb, 0, 0, "Zero Length Bit message");
}
if (!CONTROL_BIT(control)) {
if (tree)
proto_item_set_len(l2tp_item, idx);
if (tvb_offset_exists(tvb, idx)) {
next_tvb = tvb_new_subset_remaining(tvb, idx);
call_dissector(ppp_hdlc_handle, next_tvb, pinfo, tree);
}
return tvb_length(tvb);
}
if (LENGTH_BIT(control))
process_control_avps(tvb, pinfo, l2tp_tree, idx, length);
return tvb_length(tvb);
}
static void
dissect_l2tp_ip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int idx = 0;
guint32 sid;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "L2TPv3");
col_clear(pinfo->cinfo, COL_INFO);
sid = tvb_get_ntohl(tvb, idx);
if (sid == 0) {
process_l2tpv3_control(tvb, pinfo, tree, 4);
}
else {
process_l2tpv3_data_ip(tvb, pinfo, tree);
}
return;
}
void
proto_register_l2tp(void)
{
static hf_register_info hf[] = {
{ &hf_l2tp_type,
{ "Type", "l2tp.type", FT_UINT16, BASE_DEC, VALS(l2tp_type_vals), 0x8000,
"Type bit", HFILL }},
{ &hf_l2tp_length_bit,
{ "Length Bit", "l2tp.length_bit", FT_BOOLEAN, 16, TFS(&l2tp_length_bit_truth), 0x4000,
NULL, HFILL }},
{ &hf_l2tp_seq_bit,
{ "Sequence Bit", "l2tp.seq_bit", FT_BOOLEAN, 16, TFS(&l2tp_seq_bit_truth), 0x0800,
NULL, HFILL }},
{ &hf_l2tp_offset_bit,
{ "Offset bit", "l2tp.offset_bit", FT_BOOLEAN, 16, TFS(&l2tp_offset_bit_truth), 0x0200,
NULL, HFILL }},
{ &hf_l2tp_priority,
{ "Priority", "l2tp.priority", FT_BOOLEAN, 16, TFS(&l2tp_priority_truth), 0x0100,
"Priority bit", HFILL }},
{ &hf_l2tp_version,
{ "Version", "l2tp.version", FT_UINT16, BASE_DEC, NULL, 0x000f,
NULL, HFILL }},
{ &hf_l2tp_length,
{ "Length","l2tp.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_tunnel,
{ "Tunnel ID","l2tp.tunnel", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_session,
{ "Session ID","l2tp.session", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_Ns,
{ "Ns","l2tp.Ns", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_Nr,
{ "Nr","l2tp.Nr", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_offset,
{ "Offset","l2tp.offset", FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of octest past the L2TP header at which thepayload data starts.", HFILL }},
{ &hf_l2tp_avp_mandatory,
{ "Mandatory", "l2tp.avp.mandatory", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Mandatory AVP", HFILL }},
{ &hf_l2tp_avp_hidden,
{ "Hidden", "l2tp.avp.hidden", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Hidden AVP", HFILL }},
{ &hf_l2tp_avp_length,
{ "Length", "l2tp.avp.length", FT_UINT16, BASE_DEC, NULL, 0,
"AVP Length", HFILL }},
{ &hf_l2tp_avp_vendor_id,
{ "Vendor ID", "l2tp.avp.vendor_id", FT_UINT16, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0,
"AVP Vendor ID", HFILL }},
{ &hf_l2tp_avp_type,
{ "Type", "l2tp.avp.type", FT_UINT16, BASE_DEC, VALS(avp_type_vals), 0,
"AVP Type", HFILL }},
{ &hf_l2tp_tie_breaker,
{ "Tie Breaker", "l2tp.tie_breaker", FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_l2tp_sid,
{ "Session ID","l2tp.sid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_ccid,
{ "Control Connection ID","l2tp.ccid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_res,
{ "Reserved","l2tp.res", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_cookie,
{ "Cookie","l2tp.cookie", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_l2_spec_def,
{ "Default L2-Specific Sublayer","l2tp.l2_spec_def", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_l2_spec_atm,
{ "ATM-Specific Sublayer","l2tp.l2_spec_atm", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_l2_spec_docsis_dmpt,
{ "DOCSIS DMPT - Specific Sublayer","l2tp.l2_spec_docsis_dmpt", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_l2_spec_v,
{ "V-bit","l2tp.l2_spec_v", FT_BOOLEAN, 8, NULL, 0x80,
"VCCV Bit", HFILL }},
{ &hf_l2tp_l2_spec_s,
{ "S-bit","l2tp.l2_spec_s", FT_BOOLEAN, 8, NULL, 0x40,
"Sequence Bit", HFILL }},
{ &hf_l2tp_l2_spec_t,
{ "T-bit","l2tp.l2_spec_t", FT_BOOLEAN, 8, NULL, 0x08,
"Transport Type Bit", HFILL }},
{ &hf_l2tp_l2_spec_g,
{ "G-bit","l2tp.l2_spec_g", FT_BOOLEAN, 8, NULL, 0x04,
"EFCI Bit", HFILL }},
{ &hf_l2tp_l2_spec_c,
{ "C-bit","l2tp.l2_spec_c", FT_BOOLEAN, 8, NULL, 0x02,
"CLP Bit", HFILL }},
{ &hf_l2tp_l2_spec_u,
{ "U-bit","l2tp.l2_spec_u", FT_BOOLEAN, 8, NULL, 0x01,
"C/R Bit", HFILL }},
{ &hf_l2tp_l2_spec_flow_id,
{ "Flow ID","l2tp.l2_spec_flow_id", FT_UINT8, BASE_HEX, NULL, FLOW_ID_MASK,
NULL, HFILL }},
{ &hf_l2tp_l2_spec_sequence,
{ "Sequence Number","l2tp.l2_spec_sequence", FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_l2tp_cisco_avp_type,
{ "Type", "l2tp.avp.ciscotype", FT_UINT16, BASE_DEC, VALS(cisco_avp_type_vals), 0,
"AVP Type", HFILL }},
{ &hf_l2tp_avp_message_type,
{ "Message Type", "l2tp.avp.message_type", FT_UINT16, BASE_DEC, VALS(message_type_vals), 0,
NULL, HFILL }},
{ &hf_l2tp_avp_assigned_tunnel_id,
{ "Assigned Tunnel ID", "l2tp.avp.assigned_tunnel_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_l2tp_avp_assigned_control_conn_id,
{ "Assigned Control Connection ID", "l2tp.avp.assigned_control_conn_id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_l2tp_avp_assigned_session_id,
{ "Assigned Session ID", "l2tp.avp.assigned_session_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_l2tp_avp_remote_session_id,
{ "Remote Session ID", "l2tp.avp.remote_session_id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_l2tp_avp_local_session_id,
{ "Local Session ID", "l2tp.avp.local_session_id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_l2tp,
&ett_l2tp_ctrl,
&ett_l2tp_avp,
&ett_l2tp_avp_sub,
&ett_l2tp_l2_spec,
&ett_l2tp_lcp,
};
module_t *l2tp_module;
proto_l2tp = proto_register_protocol(
"Layer 2 Tunneling Protocol", "L2TP", "l2tp");
proto_register_field_array(proto_l2tp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
l2tp_module = prefs_register_protocol(proto_l2tp, NULL);
prefs_register_enum_preference(l2tp_module,
"cookie_size",
"L2TPv3 Cookie Size",
"L2TPv3 Cookie Size",
&l2tpv3_cookie,
l2tpv3_cookies,
FALSE);
prefs_register_enum_preference(l2tp_module,
"l2_specific",
"L2TPv3 L2-Specific Sublayer",
"L2TPv3 L2-Specific Sublayer",
&l2tpv3_l2_specific,
l2tpv3_l2_specifics,
FALSE);
prefs_register_enum_preference(l2tp_module,
"protocol",
"Decode L2TPv3 packet contents as this protocol",
"Decode L2TPv3 packet contents as this protocol",
&l2tpv3_protocol,
l2tpv3_protocols,
FALSE);
}
void
proto_reg_handoff_l2tp(void)
{
dissector_handle_t l2tp_udp_handle;
dissector_handle_t l2tp_ip_handle;
l2tp_udp_handle = new_create_dissector_handle(dissect_l2tp_udp, proto_l2tp);
dissector_add_uint("udp.port", UDP_PORT_L2TP, l2tp_udp_handle);
l2tp_ip_handle = create_dissector_handle(dissect_l2tp_ip, proto_l2tp);
dissector_add_uint("ip.proto", IP_PROTO_L2TP, l2tp_ip_handle);
ppp_hdlc_handle = find_dissector("ppp_hdlc");
ppp_lcp_options_handle = find_dissector("ppp_lcp_options");
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
chdlc_handle = find_dissector("chdlc");
fr_handle = find_dissector("fr");
ip_handle = find_dissector("ip");
mpls_handle = find_dissector("mpls");
atm_oam_handle = find_dissector("atm_oam_cell");
llc_handle = find_dissector("llc");
lapd_handle = find_dissector("lapd");
mp2t_handle = find_dissector("mp2t");
ehdlc_handle = find_dissector("ehdlc");
data_handle = find_dissector("data");
}
