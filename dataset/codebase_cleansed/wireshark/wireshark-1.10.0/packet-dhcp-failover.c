static guint
get_dhcpfo_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohs(tvb, offset);
}
static void
dissect_dhcpfo_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_item *ti, *pi, *oi;
proto_tree *dhcpfo_tree = NULL, *payload_tree, *option_tree;
guint16 length, tls_request;
guint type, serverflag;
int poffset;
guint32 xid;
nstime_t timex;
guint32 lease_expiration_time, grace_expiration_time,
potential_expiration_time, client_last_transaction_time,
start_time_of_state;
gboolean bogus_poffset;
guint16 opcode, option_length;
guint8 htype, reject_reason, message_digest_type, binding_status;
guint8 *vendor_class_str;
const gchar *htype_str;
gchar *lease_expiration_time_str, *grace_expiration_time_str, *potential_expiration_time_str,
*client_last_transaction_time_str, *start_time_of_state_str;
guint32 mclt;
guint8 server_state;
guint32 max_unacked_bndupd, receive_timer;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCPFO");
col_clear(pinfo->cinfo, COL_INFO);
length = tvb_get_ntohs(tvb, offset);
if (tree) {
ti = proto_tree_add_item(tree, proto_dhcpfo, tvb, 0, -1, ENC_NA);
dhcpfo_tree = proto_item_add_subtree(ti, ett_dhcpfo);
if (length >= DHCPFO_FL_HDR_LEN) {
proto_tree_add_uint(dhcpfo_tree,
hf_dhcpfo_length, tvb, offset, 2, length);
} else {
proto_tree_add_uint_format_value(dhcpfo_tree,
hf_dhcpfo_length, tvb, offset, 2, length,
"%u (bogus, must be >= %u)",
length, DHCPFO_FL_HDR_LEN);
}
}
offset += 2;
type = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(dhcpfo_tree,
hf_dhcpfo_type, tvb, offset, 1, type);
}
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_const(type, failover_vals, "Unknown Packet"));
offset += 1;
poffset = tvb_get_guint8(tvb, offset);
if (poffset < DHCPFO_FL_HDR_LEN) {
bogus_poffset = TRUE;
if (tree) {
proto_tree_add_uint_format_value(dhcpfo_tree,
hf_dhcpfo_poffset, tvb, offset, 1, poffset,
"%u (bogus, must be >= %u)",
poffset, DHCPFO_FL_HDR_LEN);
}
} else if (poffset > length) {
bogus_poffset = TRUE;
if (tree) {
proto_tree_add_uint_format_value(dhcpfo_tree,
hf_dhcpfo_poffset, tvb, offset, 1, poffset,
"%u (bogus, must be <= length of message)",
poffset);
}
} else {
bogus_poffset = FALSE;
if (tree) {
proto_tree_add_uint(dhcpfo_tree,
hf_dhcpfo_poffset, tvb, offset, 1, poffset);
}
}
offset += 1;
if (tree) {
timex.secs = tvb_get_ntohl(tvb, offset);
timex.nsecs = 0;
proto_tree_add_time_format_value(dhcpfo_tree, hf_dhcpfo_time, tvb,
offset, 4, &timex, "%s",
abs_time_secs_to_str(timex.secs, ABSOLUTE_TIME_LOCAL, TRUE));
}
offset += 4;
xid = tvb_get_ntohl(tvb, offset);
if (tree) {
proto_tree_add_item(dhcpfo_tree,
hf_dhcpfo_xid, tvb, offset, 4, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO," xid: %x", xid);
offset += 4;
if (bogus_poffset)
return;
if (!tree)
return;
if (poffset != offset) {
proto_tree_add_item(dhcpfo_tree, hf_dhcpfo_additional_HB, tvb,
offset, poffset-offset, ENC_NA);
offset = poffset;
}
if (poffset == length)
return;
pi = proto_tree_add_item(dhcpfo_tree, hf_dhcpfo_payload_data,
tvb, poffset, length-poffset, ENC_NA);
payload_tree = proto_item_add_subtree(pi, ett_fo_payload);
while (offset < length) {
opcode = tvb_get_ntohs(tvb, offset);
option_length = tvb_get_ntohs(tvb, offset+2);
oi = proto_tree_add_item(payload_tree,
hf_dhcpfo_dhcp_style_option, tvb, offset,
option_length+4, ENC_NA);
option_tree = proto_item_add_subtree(oi, ett_fo_option);
proto_item_append_text(oi, ", %s (%u)",
val_to_str_const(opcode, option_code_vals, "Unknown Option"),
opcode);
proto_tree_add_uint(option_tree, hf_dhcpfo_option_code, tvb,
offset, 2, opcode);
proto_tree_add_uint(option_tree, hf_dhcpfo_option_length, tvb,
offset+2, 2, option_length);
offset += 4;
switch (opcode) {
case DHCP_FO_PD_BINDING_STATUS:
binding_status = tvb_get_guint8(tvb, offset);
proto_item_append_text(oi, ", %s (%d)",
val_to_str_const(binding_status,
binding_status_vals,
"Unknown Packet"),
binding_status);
proto_tree_add_item(option_tree,
hf_dhcpfo_binding_status, tvb,
offset, 1, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_ASSIGNED_IP_ADDRESS:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "assigned ip address is not 4 bytes long");
break;
}
proto_item_append_text(oi, ", %s ", tvb_ip_to_str(tvb, offset));
proto_tree_add_item(option_tree,
hf_dhcpfo_assigned_ip_address, tvb, offset,
option_length, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_SENDING_SERVER_IP_ADDRESS:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "sending server ip address is not 4 bytes long");
break;
}
proto_item_append_text(oi, ", %s ", tvb_ip_to_str(tvb, offset));
proto_tree_add_item(option_tree,
hf_dhcpfo_sending_server_ip_address, tvb,
offset, option_length, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_ADDRESSES_TRANSFERED:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "addresses transferred is not 4 bytes long");
break;
}
proto_item_append_text(oi,", %u", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(option_tree,
hf_dhcpfo_addresses_transferred, tvb, offset,
option_length, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_CLIENT_IDENTIFIER:
proto_item_append_text(oi,", \"%s\"", tvb_get_ephemeral_string(tvb, offset, option_length));
proto_tree_add_item(option_tree,
hf_dhcpfo_client_identifier, tvb, offset,
option_length, ENC_ASCII|ENC_NA);
break;
case DHCP_FO_PD_CLIENT_HARDWARE_ADDRESS:
if (option_length < 2) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "hardware address is too short");
break;
}
htype = tvb_get_guint8(tvb, offset);
htype_str = tvb_arphrdaddr_to_str(tvb, offset+1, option_length-1,
htype);
proto_item_append_text(oi, ", %s, %s", htype_str,
htype_str);
proto_tree_add_item(option_tree, hf_dhcpfo_client_hw_type, tvb,
offset, 1, ENC_NA);
proto_tree_add_string(option_tree, hf_dhcpfo_client_hardware_address, tvb,
offset+1, option_length-1, htype_str);
break;
case DHCP_FO_PD_FTDDNS:
proto_tree_add_item(option_tree, hf_dhcpfo_ftddns, tvb,
offset, option_length, ENC_ASCII|ENC_NA);
break;
case DHCP_FO_PD_REJECT_REASON:
if (option_length != 1) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Reject reason is not 1 byte long");
break;
}
reject_reason = tvb_get_guint8(tvb, offset);
proto_item_append_text(oi, ", %s (%d)",
val_to_str_const(reject_reason, reject_reason_vals,
"Unknown Packet"),
reject_reason);
proto_tree_add_uint(option_tree,
hf_dhcpfo_reject_reason, tvb, offset,
option_length, reject_reason);
break;
case DHCP_FO_PD_MESSAGE:
proto_tree_add_item(option_tree, hf_dhcpfo_message, tvb,
offset, option_length, ENC_ASCII|ENC_NA);
break;
case DHCP_FO_PD_MCLT:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "MCLT is not 4 bytes long");
break;
}
mclt = tvb_get_ntohl(tvb, offset);
proto_item_append_text(oi,", %u seconds", mclt);
proto_tree_add_uint(option_tree, hf_dhcpfo_mclt, tvb,
offset, option_length, mclt);
break;
case DHCP_FO_PD_VENDOR_CLASS:
vendor_class_str =
tvb_get_ephemeral_string(tvb, offset, option_length);
proto_item_append_text(oi,", \"%s\"",
format_text(vendor_class_str, option_length));
proto_tree_add_string(option_tree,
hf_dhcpfo_vendor_class, tvb, offset,
option_length, vendor_class_str);
break;
case DHCP_FO_PD_LEASE_EXPIRATION_TIME:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Lease expiration time is not 4 bytes long");
break;
}
lease_expiration_time =
tvb_get_ntohl(tvb, offset);
lease_expiration_time_str =
abs_time_secs_to_str(lease_expiration_time, ABSOLUTE_TIME_LOCAL, TRUE);
proto_item_append_text(oi, ", %s",
lease_expiration_time_str);
proto_tree_add_uint_format_value(option_tree,
hf_dhcpfo_lease_expiration_time, tvb,
offset, option_length,
lease_expiration_time,
"%s",
lease_expiration_time_str);
break;
case DHCP_FO_PD_POTENTIAL_EXPIRATION_TIME:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Potential expiration time is not 4 bytes long");
break;
}
potential_expiration_time =
tvb_get_ntohl(tvb, offset);
potential_expiration_time_str =
abs_time_secs_to_str(potential_expiration_time, ABSOLUTE_TIME_LOCAL, TRUE);
proto_item_append_text(oi, ", %s",
potential_expiration_time_str);
proto_tree_add_uint_format_value(option_tree,
hf_dhcpfo_potential_expiration_time, tvb,
offset, option_length,
potential_expiration_time,
"%s",
potential_expiration_time_str);
break;
case DHCP_FO_PD_GRACE_EXPIRATION_TIME:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Grace expiration time is not 4 bytes long");
break;
}
grace_expiration_time =
tvb_get_ntohl(tvb, offset);
grace_expiration_time_str =
abs_time_secs_to_str(grace_expiration_time, ABSOLUTE_TIME_LOCAL, TRUE);
proto_item_append_text(oi, ", %s",
grace_expiration_time_str);
proto_tree_add_uint_format_value(option_tree,
hf_dhcpfo_grace_expiration_time, tvb,
offset, option_length,
grace_expiration_time,
"%s",
grace_expiration_time_str);
break;
case DHCP_FO_PD_CLIENT_LAST_TRANSACTION_TIME:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Last transaction time is not 4 bytes long");
break;
}
client_last_transaction_time =
tvb_get_ntohl(tvb, offset);
client_last_transaction_time_str =
abs_time_secs_to_str(client_last_transaction_time, ABSOLUTE_TIME_LOCAL, TRUE);
proto_item_append_text(oi, ", %s",
client_last_transaction_time_str);
proto_tree_add_uint_format_value(option_tree,
hf_dhcpfo_client_last_transaction_time, tvb,
offset, option_length,
client_last_transaction_time,
"%s",
abs_time_secs_to_str(client_last_transaction_time, ABSOLUTE_TIME_LOCAL, TRUE));
break;
case DHCP_FO_PD_START_TIME_OF_STATE:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Start time of state is not 4 bytes long");
break;
}
start_time_of_state =
tvb_get_ntohl(tvb, offset);
start_time_of_state_str =
abs_time_secs_to_str(start_time_of_state, ABSOLUTE_TIME_LOCAL, TRUE);
proto_item_append_text(oi, ", %s",
start_time_of_state_str);
proto_tree_add_uint_format_value(option_tree,
hf_dhcpfo_start_time_of_state, tvb,
offset, option_length,
start_time_of_state,
"%s",
abs_time_secs_to_str(start_time_of_state, ABSOLUTE_TIME_LOCAL, TRUE));
break;
case DHCP_FO_PD_SERVERSTATE:
if (option_length != 1) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "server status is not 1 byte long");
break;
}
server_state = tvb_get_guint8(tvb, offset);
proto_item_append_text(oi, ", %s (%u)",
val_to_str_const(server_state, server_state_vals,
"Unknown"),
server_state);
proto_tree_add_uint(option_tree,
hf_dhcpfo_server_state, tvb, offset, 1,
server_state);
break;
case DHCP_FO_PD_SERVERFLAG:
if (option_length != 1) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Serverflag is not 1 byte long");
break;
}
serverflag = tvb_get_guint8(tvb, offset);
proto_item_append_text(oi, ", %s (%d)",
val_to_str_const(serverflag, serverflag_vals, "UNKNOWN FLAGS"),
serverflag);
proto_tree_add_item(option_tree, hf_dhcpfo_serverflag, tvb, offset, option_length, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_VENDOR_OPTION:
proto_tree_add_item(option_tree,
hf_dhcpfo_vendor_option, tvb, offset,
option_length, ENC_NA);
break;
case DHCP_FO_PD_MAX_UNACKED_BNDUPD:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Max unacked BNDUPD is not 4 bytes long");
break;
}
max_unacked_bndupd = tvb_get_ntohl(tvb, offset);
proto_item_append_text(oi, ", %u", max_unacked_bndupd);
proto_tree_add_uint(option_tree,
hf_dhcpfo_max_unacked_bndupd, tvb, offset,
option_length, max_unacked_bndupd);
break;
case DHCP_FO_PD_RECEIVE_TIMER:
if (option_length != 4) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Receive timer is not 4 bytes long");
break;
}
receive_timer = tvb_get_ntohl(tvb, offset);
proto_item_append_text(oi,", %u seconds",
receive_timer);
proto_tree_add_uint_format_value(option_tree,
hf_dhcpfo_receive_timer, tvb, offset,
option_length, receive_timer,
"%u seconds",
receive_timer);
break;
case DHCP_FO_PD_HASH_BUCKET_ASSIGNMENT:
proto_tree_add_item(option_tree,
hf_dhcpfo_hash_bucket_assignment, tvb,
offset, option_length, ENC_NA);
break;
case DHCP_FO_PD_MESSAGE_DIGEST:
if (option_length < 2) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Message digest is too short");
break;
}
message_digest_type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(option_tree, hf_dhcpfo_message_digest_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (message_digest_type == 1) {
proto_item_append_text(oi, ", HMAC-MD5");
} else {
proto_item_append_text(oi, ", type not allowed");
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Message digest type: %u, not allowed", message_digest_type);
}
proto_tree_add_item(option_tree,
hf_dhcpfo_message_digest, tvb, offset+1,
option_length-1, ENC_ASCII|ENC_NA);
break;
case DHCP_FO_PD_PROTOCOL_VERSION:
if (option_length != 1) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "Protocol version is not 1 byte long");
break;
}
proto_item_append_text(oi, ", version: %u", tvb_get_guint8(tvb, offset));
proto_tree_add_item(option_tree, hf_dhcpfo_protocol_version, tvb, offset, option_length, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_TLS_REQUEST:
if (option_length != 2) {
expert_add_info_format(pinfo, oi, PI_PROTOCOL, PI_WARN, "TLS request is not 2 bytes long");
break;
}
tls_request = tvb_get_ntohs(tvb, offset);
proto_item_append_text(oi, ", %s", val_to_str(tls_request, tls_request_vals, "Unknown (%u)"));
proto_tree_add_item(option_tree, hf_dhcpfo_tls_request, tvb, offset, option_length, ENC_BIG_ENDIAN);
break;
case DHCP_FO_PD_TLS_REPLY:
break;
case DHCP_FO_PD_REQUEST_OPTION:
break;
case DHCP_FO_PD_REPLY_OPTION:
break;
default:
break;
}
offset += option_length;
}
}
static void
dissect_dhcpfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, dhcpfo_desegment, 2,
get_dhcpfo_pdu_len, dissect_dhcpfo_pdu);
}
void
proto_register_dhcpfo(void)
{
static hf_register_info hf[] = {
{ &hf_dhcpfo_length,
{ "Message length", "dhcpfo.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_dhcpfo_type,
{ "Message Type", "dhcpfo.type",
FT_UINT8, BASE_DEC, VALS(failover_vals), 0,
NULL, HFILL }
},
{ &hf_dhcpfo_poffset,
{ "Payload Offset", "dhcpfo.poffset",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_dhcpfo_time,
{ "Time", "dhcpfo.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }
},
{ &hf_dhcpfo_xid,
{ "Xid", "dhcpfo.xid",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_dhcpfo_additional_HB,
{"Additional Header Bytes", "dhcpfo.additionalheaderbytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dhcpfo_payload_data,
{"Payload Data", "dhcpfo.payloaddata",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_dhcpfo_dhcp_style_option,
{"DHCP Style Option", "dhcpfo.dhcpstyleoption",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_dhcpfo_option_code,
{"Option Code", "dhcpfo.optioncode",
FT_UINT16, BASE_DEC, VALS(option_code_vals), 0,
NULL, HFILL }
},
{&hf_dhcpfo_option_length,
{"Length", "dhcpfo.optionlength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_binding_status,
{"Type", "dhcpfo.bindingstatus",
FT_UINT32, BASE_DEC, VALS(binding_status_vals), 0,
NULL, HFILL }
},
{&hf_dhcpfo_server_state,
{"server status", "dhcpfo.serverstatus",
FT_UINT8, BASE_DEC, VALS(server_state_vals), 0,
NULL, HFILL }
},
{&hf_dhcpfo_assigned_ip_address,
{"assigned ip address", "dhcpfo.assignedipaddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_dhcpfo_sending_server_ip_address,
{"sending server ip-address", "dhcpfo.sendingserveripaddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_dhcpfo_addresses_transferred,
{"addresses transferred", "dhcpfo.addressestransferred",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_client_identifier,
{"Client Identifier", "dhcpfo.clientidentifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_client_hw_type,
{"Client Hardware Type", "dhcpfo.clienthardwaretype",
FT_UINT8, BASE_HEX, VALS(arp_hrd_vals), 0x0,
NULL, HFILL }},
{&hf_dhcpfo_client_hardware_address,
{"Client Hardware Address", "dhcpfo.clienthardwareaddress",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_ftddns,
{"FTDDNS", "dhcpfo.ftddns",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_reject_reason,
{"Reject reason", "dhcpfo.rejectreason",
FT_UINT8, BASE_DEC, VALS(reject_reason_vals), 0,
NULL, HFILL }
},
{&hf_dhcpfo_message,
{"Message", "dhcpfo.message",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_mclt,
{"MCLT", "dhcpfo.mclt",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_vendor_class,
{"Vendor class", "dhcpfo.vendorclass",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_lease_expiration_time,
{"Lease expiration time", "dhcpfo.leaseexpirationtime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_grace_expiration_time,
{"Grace expiration time", "dhcpfo.graceexpirationtime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_potential_expiration_time,
{"Potential expiration time", "dhcpfo.potentialexpirationtime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_client_last_transaction_time,
{"Client last transaction time", "dhcpfo.clientlasttransactiontime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_start_time_of_state,
{"Start time of state", "dhcpfo.starttimeofstate",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_vendor_option,
{"Vendor option", "dhcpfo.vendoroption",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_dhcpfo_max_unacked_bndupd,
{"Max unacked BNDUPD", "dhcpfo.maxunackedbndupd",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_protocol_version,
{"Protocol version", "dhcpfo.protocolversion",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_receive_timer,
{"Receive timer", "dhcpfo.receivetimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_message_digest,
{"Message digest", "dhcpfo.messagedigest",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_hash_bucket_assignment,
{"Hash bucket assignment", "dhcpfo.hashbucketassignment",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_dhcpfo_message_digest_type,
{"Message digest type", "dhcpfo.message_digest_type",
FT_UINT8, BASE_DEC, VALS(message_digest_type_vals), 0,
NULL, HFILL }
},
{&hf_dhcpfo_tls_request,
{"TLS Request", "dhcpfo.tls_request",
FT_UINT16, BASE_DEC, VALS(tls_request_vals), 0,
NULL, HFILL }
},
{&hf_dhcpfo_serverflag,
{"Serverflag", "dhcpfo.serverflag",
FT_UINT8, BASE_DEC, VALS(serverflag_vals), 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_dhcpfo,
&ett_fo_payload,
&ett_fo_option,
};
module_t *dhcpfo_module;
proto_dhcpfo = proto_register_protocol("DHCP Failover", "DHCPFO",
"dhcpfo");
proto_register_field_array(proto_dhcpfo, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dhcpfo_module = prefs_register_protocol(proto_dhcpfo, proto_reg_handoff_dhcpfo);
prefs_register_uint_preference(dhcpfo_module, "tcp_port",
"DHCP failover TCP Port", "Set the port for DHCP failover communications",
10, &tcp_port_pref);
prefs_register_bool_preference(dhcpfo_module, "desegment",
"Reassemble DHCP failover messages spanning multiple TCP segments",
"Whether the DHCP failover dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&dhcpfo_desegment);
}
void
proto_reg_handoff_dhcpfo(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t dhcpfo_handle;
static guint saved_tcp_port;
if (!initialized) {
dhcpfo_handle = create_dissector_handle(dissect_dhcpfo, proto_dhcpfo);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", saved_tcp_port, dhcpfo_handle);
}
dissector_add_uint("tcp.port", tcp_port_pref, dhcpfo_handle);
saved_tcp_port = tcp_port_pref;
}
