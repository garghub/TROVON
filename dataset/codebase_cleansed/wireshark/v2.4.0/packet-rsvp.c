static gint
rsvp_equal(gconstpointer k1, gconstpointer k2)
{
const struct rsvp_request_key *key1 = (const struct rsvp_request_key*) k1;
const struct rsvp_request_key *key2 = (const struct rsvp_request_key*) k2;
if (key1->conversation != key2->conversation) {
return 0;
}
if (key1->session_type != key2->session_type) {
return 0;
}
switch (key1->session_type) {
case RSVP_SESSION_TYPE_IPV4:
if (addresses_equal(&key1->u.session_ipv4.destination,
&key2->u.session_ipv4.destination) == FALSE)
return 0;
if (key1->u.session_ipv4.protocol != key2->u.session_ipv4.protocol)
return 0;
if (key1->u.session_ipv4.udp_dest_port != key2->u.session_ipv4.udp_dest_port)
return 0;
break;
case RSVP_SESSION_TYPE_IPV6:
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
if (addresses_equal(&key1->u.session_ipv4_lsp.destination,
&key2->u.session_ipv4_lsp.destination) == FALSE)
return 0;
if (key1->u.session_ipv4_lsp.udp_dest_port !=
key2->u.session_ipv4_lsp.udp_dest_port)
return 0;
if (key1->u.session_ipv4_lsp.ext_tunnel_id !=
key2->u.session_ipv4_lsp.ext_tunnel_id)
return 0;
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
if (addresses_equal(&key1->u.session_agg_ipv4.destination,
&key2->u.session_agg_ipv4.destination) == FALSE)
return 0;
if (key1->u.session_agg_ipv4.dscp != key2->u.session_agg_ipv4.dscp)
return 0;
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV6:
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
if (addresses_equal(&key1->u.session_ipv4_uni.destination,
&key2->u.session_ipv4_uni.destination) == FALSE)
return 0;
if (key1->u.session_ipv4_uni.udp_dest_port !=
key2->u.session_ipv4_uni.udp_dest_port)
return 0;
if (key1->u.session_ipv4_uni.ext_tunnel_id !=
key2->u.session_ipv4_uni.ext_tunnel_id)
return 0;
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
if (addresses_equal(&key1->u.session_ipv4_enni.destination,
&key2->u.session_ipv4_enni.destination) == FALSE)
return 0;
if (key1->u.session_ipv4_enni.udp_dest_port !=
key2->u.session_ipv4_enni.udp_dest_port)
return 0;
if (key1->u.session_ipv4_enni.ext_tunnel_id !=
key2->u.session_ipv4_enni.ext_tunnel_id)
return 0;
break;
default:
break;
}
if (addresses_equal(&key1->source_info.source,
&key2->source_info.source) == FALSE)
return 0;
if (key1->source_info.udp_source_port != key2->source_info.udp_source_port)
return 0;
return 1;
}
static guint
rsvp_hash(gconstpointer k)
{
const struct rsvp_request_key *key = (const struct rsvp_request_key*) k;
return key->conversation;
}
static const char* rsvp_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter _U_)
{
if ((filter == CONV_FT_SRC_ADDRESS) && (conv->src_address.type == AT_IPv4))
return "ip.src";
if ((filter == CONV_FT_DST_ADDRESS) && (conv->dst_address.type == AT_IPv4))
return "ip.dst";
if ((filter == CONV_FT_ANY_ADDRESS) && (conv->src_address.type == AT_IPv4))
return "ip.addr";
return CONV_FILTER_INVALID;
}
static int
rsvp_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pct;
const rsvp_conversation_info *rsvph = (const rsvp_conversation_info *)vip;
add_conversation_table_data(hash, &rsvph->source, &rsvph->destination,
0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts, &rsvp_ct_dissector_info, PT_NONE);
return 1;
}
static const char* rsvp_host_get_filter_type(hostlist_talker_t* host _U_, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == AT_IPv4))
return "ip.addr";
return CONV_FILTER_INVALID;
}
static int
rsvp_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pit;
const rsvp_conversation_info *rsvph = (const rsvp_conversation_info *)vip;
add_hostlist_table_data(hash, &rsvph->source, 0, TRUE, 1, pinfo->fd->pkt_len, &rsvp_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &rsvph->destination, 0, FALSE, 1, pinfo->fd->pkt_len, &rsvp_host_dissector_info, PT_NONE);
return 1;
}
static inline int
rsvp_class_to_filter_num(int classnum)
{
switch(classnum) {
case RSVP_CLASS_SESSION :
case RSVP_CLASS_HOP :
case RSVP_CLASS_INTEGRITY :
case RSVP_CLASS_TIME_VALUES :
case RSVP_CLASS_ERROR :
case RSVP_CLASS_SCOPE :
case RSVP_CLASS_STYLE :
case RSVP_CLASS_FLOWSPEC :
case RSVP_CLASS_FILTER_SPEC :
case RSVP_CLASS_SENDER_TEMPLATE :
case RSVP_CLASS_SENDER_TSPEC :
case RSVP_CLASS_ADSPEC :
case RSVP_CLASS_POLICY :
case RSVP_CLASS_CONFIRM :
case RSVP_CLASS_LABEL :
case RSVP_CLASS_LABEL_REQUEST :
case RSVP_CLASS_HELLO :
case RSVP_CLASS_EXPLICIT_ROUTE :
case RSVP_CLASS_RECORD_ROUTE :
case RSVP_CLASS_MESSAGE_ID :
case RSVP_CLASS_MESSAGE_ID_ACK :
case RSVP_CLASS_MESSAGE_ID_LIST :
return classnum + RSVPF_OBJECT;
break;
case RSVP_CLASS_RECOVERY_LABEL :
case RSVP_CLASS_UPSTREAM_LABEL :
case RSVP_CLASS_LABEL_SET :
case RSVP_CLASS_PROTECTION :
return RSVPF_RECOVERY_LABEL + (classnum - RSVP_CLASS_RECOVERY_LABEL);
case RSVP_CLASS_SUGGESTED_LABEL :
case RSVP_CLASS_ACCEPTABLE_LABEL_SET :
case RSVP_CLASS_RESTART_CAP :
return RSVPF_SUGGESTED_LABEL + (classnum - RSVP_CLASS_SUGGESTED_LABEL);
case RSVP_CLASS_LINK_CAP :
return RSVPF_LINK_CAP;
case RSVP_CLASS_DIFFSERV :
return RSVPF_DIFFSERV;
case RSVP_CLASS_CLASSTYPE :
return RSVPF_DSTE;
case RSVP_CLASS_NOTIFY_REQUEST :
return RSVPF_NOTIFY_REQUEST;
case RSVP_CLASS_ADMIN_STATUS :
return RSVPF_ADMIN_STATUS;
case RSVP_CLASS_LSP_ATTRIBUTES :
return RSVPF_LSP_ATTRIBUTES;
case RSVP_CLASS_ASSOCIATION :
return RSVPF_ASSOCIATION;
case RSVP_CLASS_CALL_ATTRIBUTES:
return RSVPF_CALL_ATTRIBUTES;
case RSVP_CLASS_SESSION_ATTRIBUTE :
return RSVPF_SESSION_ATTRIBUTE;
case RSVP_CLASS_GENERALIZED_UNI :
return RSVPF_GENERALIZED_UNI;
case RSVP_CLASS_CALL_ID :
return RSVPF_CALL_ID;
case RSVP_CLASS_3GPP2_OBJECT :
return RSVPF_3GPP2_OBJECT;
case RSVP_CLASS_DCLASS :
return RSVPF_DCLASS;
case RSVP_CLASS_LSP_TUNNEL_IF_ID :
return RSVPF_LSP_TUNNEL_IF_ID;
case RSVP_CLASS_EXCLUDE_ROUTE:
return RSVPF_EXCLUDE_ROUTE;
case RSVP_CLASS_JUNIPER_PROPERTIES :
return RSVPF_JUNIPER;
case RSVP_CLASS_VENDOR_PRIVATE_1:
case RSVP_CLASS_VENDOR_PRIVATE_2:
case RSVP_CLASS_VENDOR_PRIVATE_3:
case RSVP_CLASS_VENDOR_PRIVATE_4:
case RSVP_CLASS_VENDOR_PRIVATE_5:
case RSVP_CLASS_VENDOR_PRIVATE_6:
case RSVP_CLASS_VENDOR_PRIVATE_7:
case RSVP_CLASS_VENDOR_PRIVATE_8:
case RSVP_CLASS_VENDOR_PRIVATE_9:
case RSVP_CLASS_VENDOR_PRIVATE_10:
case RSVP_CLASS_VENDOR_PRIVATE_11:
case RSVP_CLASS_VENDOR_PRIVATE_12:
return RSVPF_PRIVATE_OBJ;
default:
return RSVPF_UNKNOWN_OBJ;
}
}
static inline int
rsvp_class_to_tree_type(int classnum)
{
switch(classnum) {
case RSVP_CLASS_SESSION :
return TT_SESSION;
case RSVP_CLASS_HOP :
return TT_HOP;
case RSVP_CLASS_INTEGRITY :
return TT_INTEGRITY;
case RSVP_CLASS_TIME_VALUES :
return TT_TIME_VALUES;
case RSVP_CLASS_ERROR :
return TT_ERROR;
case RSVP_CLASS_SCOPE :
return TT_SCOPE;
case RSVP_CLASS_STYLE :
return TT_STYLE;
case RSVP_CLASS_FLOWSPEC :
return TT_FLOWSPEC;
case RSVP_CLASS_FILTER_SPEC :
return TT_FILTER_SPEC;
case RSVP_CLASS_SENDER_TEMPLATE :
return TT_SENDER_TEMPLATE;
case RSVP_CLASS_SENDER_TSPEC :
return TT_TSPEC;
case RSVP_CLASS_ADSPEC :
return TT_ADSPEC;
case RSVP_CLASS_POLICY :
return TT_POLICY;
case RSVP_CLASS_CONFIRM :
return TT_CONFIRM;
case RSVP_CLASS_RECOVERY_LABEL :
case RSVP_CLASS_UPSTREAM_LABEL :
case RSVP_CLASS_SUGGESTED_LABEL :
case RSVP_CLASS_LABEL :
return TT_LABEL;
case RSVP_CLASS_LABEL_REQUEST :
return TT_LABEL_REQUEST;
case RSVP_CLASS_HELLO :
return TT_HELLO_OBJ;
case RSVP_CLASS_EXPLICIT_ROUTE :
return TT_EXPLICIT_ROUTE;
case RSVP_CLASS_RECORD_ROUTE :
return TT_RECORD_ROUTE;
case RSVP_CLASS_MESSAGE_ID :
return TT_MESSAGE_ID;
case RSVP_CLASS_MESSAGE_ID_ACK :
return TT_MESSAGE_ID_ACK;
case RSVP_CLASS_MESSAGE_ID_LIST :
return TT_MESSAGE_ID_LIST;
case RSVP_CLASS_LABEL_SET :
return TT_LABEL_SET;
case RSVP_CLASS_PROTECTION :
return TT_PROTECTION_INFO;
case RSVP_CLASS_ACCEPTABLE_LABEL_SET :
return TT_UNKNOWN_CLASS;
case RSVP_CLASS_RESTART_CAP :
return TT_RESTART_CAP;
case RSVP_CLASS_LINK_CAP :
return TT_LINK_CAP;
case RSVP_CLASS_DIFFSERV :
return TT_DIFFSERV;
case RSVP_CLASS_CLASSTYPE:
return TT_CLASSTYPE;
case RSVP_CLASS_NOTIFY_REQUEST :
return TT_UNKNOWN_CLASS;
case RSVP_CLASS_ADMIN_STATUS :
return TT_ADMIN_STATUS;
case RSVP_CLASS_LSP_ATTRIBUTES :
case RSVP_CLASS_LSP_REQUIRED_ATTRIBUTES :
return TT_LSP_ATTRIBUTES;
case RSVP_CLASS_ASSOCIATION :
return TT_ASSOCIATION;
case RSVP_CLASS_CALL_ATTRIBUTES:
return RSVPF_CALL_ATTRIBUTES;
case RSVP_CLASS_JUNIPER_PROPERTIES :
return TT_JUNIPER;
case RSVP_CLASS_SESSION_ATTRIBUTE :
return TT_SESSION_ATTRIBUTE;
case RSVP_CLASS_GENERALIZED_UNI :
return TT_GEN_UNI;
case RSVP_CLASS_CALL_ID :
return TT_CALL_ID;
case RSVP_CLASS_3GPP2_OBJECT :
return TT_3GPP2_OBJECT;
case RSVP_CLASS_DCLASS :
return TT_DCLASS;
case RSVP_CLASS_LSP_TUNNEL_IF_ID :
return TT_LSP_TUNNEL_IF_ID;
case RSVP_CLASS_EXCLUDE_ROUTE :
return TT_EXCLUDE_ROUTE;
case RSVP_CLASS_VENDOR_PRIVATE_1:
case RSVP_CLASS_VENDOR_PRIVATE_2:
case RSVP_CLASS_VENDOR_PRIVATE_3:
case RSVP_CLASS_VENDOR_PRIVATE_4:
case RSVP_CLASS_VENDOR_PRIVATE_5:
case RSVP_CLASS_VENDOR_PRIVATE_6:
case RSVP_CLASS_VENDOR_PRIVATE_7:
case RSVP_CLASS_VENDOR_PRIVATE_8:
case RSVP_CLASS_VENDOR_PRIVATE_9:
case RSVP_CLASS_VENDOR_PRIVATE_10:
case RSVP_CLASS_VENDOR_PRIVATE_11:
case RSVP_CLASS_VENDOR_PRIVATE_12:
return TT_PRIVATE_CLASS;
default:
return TT_UNKNOWN_CLASS;
}
}
static void
find_rsvp_session_tempfilt(tvbuff_t *tvb, int hdr_offset, int *session_offp, int *tempfilt_offp)
{
int s_off = 0, t_off = 0;
int len, off;
guint obj_length;
if (!tvb_bytes_exist(tvb, hdr_offset+6, 2))
goto done;
len = tvb_get_ntohs(tvb, hdr_offset+6) + hdr_offset;
for (off = hdr_offset + 8; (off < len) && tvb_bytes_exist(tvb, off, 3); off += obj_length) {
obj_length = tvb_get_ntohs(tvb, off);
if (obj_length == 0)
break;
switch(tvb_get_guint8(tvb, off+2)) {
case RSVP_CLASS_SESSION:
s_off = off;
break;
case RSVP_CLASS_SENDER_TEMPLATE:
case RSVP_CLASS_FILTER_SPEC:
t_off = off;
break;
default:
break;
}
}
done:
if (session_offp) *session_offp = s_off;
if (tempfilt_offp) *tempfilt_offp = t_off;
}
static char *
summary_session(tvbuff_t *tvb, int offset)
{
switch(tvb_get_guint8(tvb, offset+3)) {
case RSVP_SESSION_TYPE_IPV4:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv4, Destination %s, Protocol %d, Port %d. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_guint8(tvb, offset+8),
tvb_get_ntohs(tvb, offset+10));
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv4-LSP, Destination %s, Short Call ID %d, Tunnel ID %d, Ext ID %0x. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+8),
tvb_get_ntohs(tvb, offset+10),
tvb_get_ntohl(tvb, offset+12));
break;
case RSVP_SESSION_TYPE_IPV6_LSP:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv6-LSP, Destination %s, Short Call ID %d, Tunnel ID %d, Ext ID %0x%0x%0x%0x. ",
tvb_ip6_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+20),
tvb_get_ntohs(tvb, offset+22),
tvb_get_ntohl(tvb, offset+24),
tvb_get_ntohl(tvb, offset+28),
tvb_get_ntohl(tvb, offset+32),
tvb_get_ntohl(tvb, offset+36));
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv4-Aggregate, Destination %s, DSCP %d. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_guint8(tvb, offset+11));
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv4-UNI, Destination %s, Tunnel ID %d, Ext Address %s. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_ip_to_str(tvb, offset+12));
break;
case RSVP_SESSION_TYPE_P2MP_LSP_TUNNEL_IPV4:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv4-P2MP LSP TUNNEL, PSMP ID %d, Tunnel ID %d, Ext Tunnel %s. ",
tvb_get_ntohl(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_ip_to_str(tvb, offset+12));
break;
case RSVP_SESSION_TYPE_P2MP_LSP_TUNNEL_IPV6:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv6-P2MP LSP TUNNEL, PSMP ID %d, Tunnel ID %d, Ext Tunnel %s. ",
tvb_get_ntohl(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_ip6_to_str(tvb, offset+12));
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: IPv4-E-NNI, Destination %s, Tunnel ID %d, Ext Address %s. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_ip_to_str(tvb, offset+12));
break;
default:
return wmem_strdup_printf(wmem_packet_scope(),
"SESSION: Type %d. ", tvb_get_guint8(tvb, offset+3));
break;
}
DISSECTOR_ASSERT_NOT_REACHED();
}
static char *
summary_template(tvbuff_t *tvb, int offset)
{
const char *objtype;
if (tvb_get_guint8(tvb, offset+2) == RSVP_CLASS_FILTER_SPEC)
objtype = "FILTERSPEC";
else
objtype = "SENDER TEMPLATE";
switch(tvb_get_guint8(tvb, offset+3)) {
case 1:
return wmem_strdup_printf(wmem_packet_scope(),
"%s: IPv4, Sender %s, Port %d. ", objtype,
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10));
break;
case 7:
return wmem_strdup_printf(wmem_packet_scope(),
"%s: IPv4-LSP, Tunnel Source: %s, Short Call ID: %d, LSP ID: %d. ", objtype,
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+8),
tvb_get_ntohs(tvb, offset+10));
break;
case 8:
return wmem_strdup_printf(wmem_packet_scope(),
"%s: IPv6-LSP, Tunnel Source: %s, Short Call ID: %d, LSP ID: %d. ", objtype,
tvb_ip6_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+20),
tvb_get_ntohs(tvb, offset+22));
break;
case 9:
return wmem_strdup_printf(wmem_packet_scope(),
"%s: IPv4-Aggregate, Aggregator %s. ", objtype,
tvb_ip_to_str(tvb, offset+4));
break;
default:
return wmem_strdup_printf(wmem_packet_scope(),
"%s: Type %d. ", objtype, tvb_get_guint8(tvb, offset+3));
break;
}
DISSECTOR_ASSERT_NOT_REACHED();
}
static void
dissect_rsvp_session(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type,
rsvp_conversation_info *rsvph)
{
proto_item *hidden_item;
int offset2 = offset + 4;
proto_item_set_text(ti, "%s", summary_session(tvb, offset));
switch(type) {
case RSVP_SESSION_TYPE_IPV4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_PROTO], tvb,
offset2+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_flags, tvb, offset2+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_PORT], tvb,
offset2+6, 2, ENC_BIG_ENDIAN);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4;
set_address_tvb(&rsvph->destination, AT_IPv4, 4, tvb, offset2);
rsvph->protocol = tvb_get_guint8(tvb, offset2+4);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
break;
case RSVP_SESSION_TYPE_IPV6:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_destination_address, tvb, offset2, 16, ENC_NA);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_protocol, tvb, offset2+16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_flags, tvb, offset2+17, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_destination_port, tvb, offset2+18, 2, ENC_BIG_ENDIAN);
rsvph->session_type = RSVP_SESSION_TYPE_IPV6;
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "7 - IPv4 LSP");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_SHORT_CALL_ID],
tvb, offset2+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_extended_tunnel_id, tvb, offset2+8, 4,
tvb_get_ntohl(tvb, offset2+8), "%u (%s)",
tvb_get_ntohl(tvb, offset2+8),
tvb_ip_to_str(tvb, offset2+8));
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4_LSP;
set_address_tvb(&rsvph->destination, AT_IPv4, 4, tvb, offset2);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_IPV6_LSP:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "8 - IPv6 LSP");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 16, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_SHORT_CALL_ID],
tvb, offset2+16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+18, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_extended_tunnel_ipv6, tvb, offset2+20, 16, ENC_NA);
proto_item_set_text(ti, "Extended Tunnel ID: (%s)", tvb_ip6_to_str(tvb, offset2+20));
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID_IPV6],
tvb, offset2+20, 16, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV6_LSP;
set_address_tvb(&rsvph->destination, AT_IPv6, 16, tvb, offset2);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+18);
rsvph->ext_tunnel_id_ipv6_pre = tvb_get_ntoh64(tvb, offset2+20);
rsvph->ext_tunnel_id_ipv6_post = tvb_get_ntoh64(tvb, offset2+28);
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "9 - IPv4 Aggregate");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_dscp, tvb, offset2+7, 1, ENC_BIG_ENDIAN);
rsvph->session_type = RSVP_SESSION_TYPE_AGGREGATE_IPV4;
set_address_tvb(&rsvph->destination, AT_IPv4, 4, tvb, offset2);
rsvph->dscp = tvb_get_guint8(tvb, offset2+7);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "11 - IPv4 UNI");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_extended_ipv4_address, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4_UNI;
set_address_tvb(&rsvph->destination, AT_IPv4, 4, tvb, offset2);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_P2MP_LSP_TUNNEL_IPV4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
RSVP_SESSION_TYPE_P2MP_LSP_TUNNEL_IPV4, "13 - IPv4 P2MP LSP TUNNEL");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_extended_tunnel, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_P2MP_LSP_TUNNEL_IPV4;
set_address_tvb(&rsvph->destination, AT_IPv4, 4, tvb, offset2);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "15 - IPv4 E-NNI");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_extended_ipv4_address, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4_E_NNI;
set_address_tvb(&rsvph->destination, AT_IPv4, 4, tvb, offset2);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_data, tvb, offset2, obj_length-4, ENC_NA);
break;
}
}
static void
dissect_rsvp_ifid_tlv(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int length,
int subtree_type)
{
int tlv_off, padding;
guint16 tlv_type;
int tlv_len;
guint8 isis_len;
const char *tlv_name, *ip_str;
proto_tree *rsvp_ifid_subtree=NULL, *ti2 = NULL;
for (tlv_off = 0; tlv_off < length; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || (tlv_off+tlv_len > length)) {
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length,
tvb, offset+tlv_off+2, 2, "Invalid TLV length");
return;
}
switch(tlv_type) {
case 1:
tlv_name = "";
goto ifid_ipv4;
case 14:
tlv_name = "Previous-Hop ";
goto ifid_ipv4;
case 16:
tlv_name = "Incoming ";
ifid_ipv4:
ip_str = tvb_ip_to_str(tvb, offset+tlv_off+4);
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%sIPv4 TLV - %s", tlv_name,
ip_str);
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%sIPv4)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_ipv4_address, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%sIPv4: %s. ", tlv_name, ip_str);
break;
case 2:
tlv_name = "";
goto ifid_ipv6;
case 15:
tlv_name = "Previous-Hop ";
goto ifid_ipv6;
case 17:
tlv_name = "Incoming ";
ifid_ipv6:
ip_str = tvb_ip6_to_str(tvb, offset+tlv_off+4);
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%sIPv6 TLV - %s", tlv_name, ip_str);
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%sIPv6)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_ipv6_address, tvb, offset+tlv_off+4, 16, ENC_NA);
proto_item_append_text(ti, "%sIPv6: %s. ", tlv_name, ip_str);
break;
case 3:
tlv_name = "";
goto ifid_ifindex;
case 4:
tlv_name = " Forward";
goto ifid_ifindex;
case 5:
tlv_name = " Reverse";
goto ifid_ifindex;
case 18:
tlv_name = " Incoming";
ifid_ifindex:
ip_str = tvb_ip_to_str(tvb, offset+tlv_off+4);
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "Interface-Index%s TLV - %s, %d",
tlv_name,
ip_str,
tvb_get_ntohl(tvb, offset+tlv_off+8));
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (Interface Index%s)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_ipv4_address, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlvinterface_id, tvb, offset+tlv_off+8, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Data If-Index%s: %s, %d. ", tlv_name, ip_str,
tvb_get_ntohl(tvb, offset+tlv_off+8));
break;
case 6:
tlv_name = "Downstream";
goto ifid_label;
case 7:
tlv_name = "Upstream";
goto ifid_label;
case 19:
tlv_name = "Incoming-Downstream";
goto ifid_label;
case 20:
tlv_name = "Incoming-Upstream";
ifid_label:
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%s-Label TLV - %u", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%s-Label)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_label, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s-Label: %u. ", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
break;
case 8:
tlv_name = "";
goto ifid_nodeid;
case 21:
tlv_name = "Reporting-";
ifid_nodeid:
ip_str = tvb_ip_to_str(tvb, offset+tlv_off+4);
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%sNode-ID TLV - %s", tlv_name,
ip_str);
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%sNode-ID)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_node_id, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%sNode-ID: %s. ", tlv_name, ip_str);
break;
case 9:
tlv_name = "";
goto ifid_ospf;
case 22:
tlv_name = "Reporting-";
ifid_ospf:
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%sOSPF-Area TLV - %u", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%sOSPF-Area)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_area, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%sOSPF-Area: %u. ", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
break;
case 10:
tlv_name = "";
goto ifid_isis;
case 23:
tlv_name = "Reporting-";
ifid_isis:
isis_len = tvb_get_guint8(tvb, offset+tlv_off+4);
if ((isis_len < 2) || (isis_len > 11))
{
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, offset+tlv_off, tlv_len,
"%sISIS-Area TLV - Invalid Length field", tlv_name);
break;
}
ip_str = print_nsap_net(tvb, offset+tlv_off+5, isis_len);
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%sISIS-Area TLV - %s", tlv_name,
ip_str);
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%sISIS-Area)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_string(rsvp_ifid_subtree, hf_rsvp_isis_area_id, tvb, offset+tlv_off+4, 4, ip_str);
proto_item_append_text(ti, "%sISIS-Area: %s. ", tlv_name, ip_str);
break;
case 11:
tlv_name = "";
goto ifid_as;
case 24:
tlv_name = "Reporting-";
ifid_as:
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "%sAS TLV - %u", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%sAS)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_autonomous_system, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%sAS: %u. ", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
break;
case 26:
tlv_name = "Node";
goto ifid_ex;
case 27:
tlv_name = "Link";
ifid_ex:
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, &ti2, "%s-Exclusions TLV - ", tlv_name);
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%d (%s-Exclusions)", tlv_type, tlv_name);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
dissect_rsvp_ifid_tlv(ti2, pinfo, rsvp_ifid_subtree, tvb, offset+tlv_off+4,
tlv_len-4, TREE(TT_HOP_SUBOBJ));
break;
case 516:
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree,
tvb, offset + tlv_off,
tlv_len,
subtree_type, NULL, "ERROR_STRING TLV - %s",
tvb_format_text(tvb, offset + tlv_off + 4,
tlv_len - 4));
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset + tlv_off, 2,
tlv_type, "516 (ERROR_STRING)");
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset + tlv_off + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_error_string, tvb, offset + tlv_off + 4, tlv_len - 4, ENC_NA|ENC_ASCII);
break;
default:
rsvp_ifid_subtree = proto_tree_add_subtree_format(rsvp_object_tree,
tvb, offset + tlv_off,
tlv_len,
subtree_type, NULL, "Unknown TLV (%u)", tlv_type);
proto_tree_add_uint_format_value(rsvp_ifid_subtree, hf_rsvp_type, tvb, offset + tlv_off, 2,
tlv_type, "%u (Unknown)", tlv_type);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_length, tvb, offset + tlv_off + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_data, tvb, offset + tlv_off + 4, tlv_len - 4, ENC_NA);
break;
}
padding = (4 - (tlv_len % 4)) % 4;
if (padding != 0)
proto_tree_add_item(rsvp_ifid_subtree, hf_rsvp_ifid_tlv_padding, tvb, offset + tlv_off + tlv_len, padding, ENC_NA);
tlv_off += tlv_len + padding;
}
}
static void
dissect_rsvp_hop(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_neighbor_address_ipv4, tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_logical_interface, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "HOP: IPv4, %s",
tvb_ip_to_str(tvb, offset2));
break;
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_neighbor_address_ipv6, tvb, offset2, 16, ENC_NA);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_logical_interface, tvb, offset2+16, 4, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "3 - IPv4 IF-ID");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_neighbor_address_ipv4, tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_logical_interface, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "HOP: IPv4 IF-ID. Control IPv4: %s. ",
tvb_ip_to_str(tvb, offset2));
dissect_rsvp_ifid_tlv(ti, pinfo, rsvp_object_tree, tvb, offset+12, obj_length-12,
TREE(TT_HOP_SUBOBJ));
break;
case 4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 - IPv6 IF-ID");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_neighbor_address_ipv6, tvb, offset2, 16, ENC_NA);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_logical_interface, tvb, offset2+16, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "HOP: IPv6 IF-ID. Control IPv6: %s. ",
tvb_ip6_to_str(tvb, offset2));
dissect_rsvp_ifid_tlv(ti, pinfo, rsvp_object_tree, tvb, offset+24, obj_length-24,
TREE(TT_HOP_SUBOBJ));
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hop_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_time_values(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_refresh_interval, tvb, offset2, 4,
tvb_get_ntohl(tvb, offset2), "%u ms (%u seconds)",
tvb_get_ntohl(tvb, offset2),
tvb_get_ntohl(tvb, offset2)/1000);
proto_item_set_text(ti, "TIME VALUES: %d ms",
tvb_get_ntohl(tvb, offset2));
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_time_values_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static guint16
dissect_rsvp_error_value(proto_tree *ti, tvbuff_t *tvb,
int offset, guint8 error_code)
{
guint16 error_val;
guint8 error_class, error_ctype;
value_string_ext *rsvp_error_vals_ext_p = NULL;
error_val = tvb_get_ntohs(tvb, offset);
switch (error_code) {
case RSVP_ERROR_ADMISSION:
rsvp_error_vals_ext_p = &rsvp_admission_control_error_vals_ext;
break;
case RSVP_ERROR_POLICY:
rsvp_error_vals_ext_p = &rsvp_policy_control_error_vals_ext;
break;
case RSVP_ERROR_TRAFFIC:
rsvp_error_vals_ext_p = &rsvp_traffic_control_error_vals_ext;
break;
case RSVP_ERROR_ROUTING:
rsvp_error_vals_ext_p = &rsvp_routing_error_vals_ext;
break;
case RSVP_ERROR_NOTIFY:
rsvp_error_vals_ext_p = &rsvp_notify_error_vals_ext;
break;
case RSVP_ERROR_DIFFSERV:
rsvp_error_vals_ext_p = &rsvp_diffserv_error_vals_ext;
break;
case RSVP_ERROR_DSTE:
rsvp_error_vals_ext_p = &rsvp_diffserv_aware_te_error_vals_ext;
break;
case RSVP_ERROR_CALL_MGMT:
rsvp_error_vals_ext_p = &rsvp_call_mgmt_error_vals_ext;
break;
}
switch (error_code) {
case RSVP_ERROR_ADMISSION:
case RSVP_ERROR_TRAFFIC:
if ((error_val & 0xc0) == 0) {
DISSECTOR_ASSERT(rsvp_error_vals_ext_p != NULL);
proto_tree_add_uint_format_value(ti, hf_rsvp_error_value, tvb, offset, 2,
error_val, "%s (%u)",
val_to_str_ext(error_val, rsvp_error_vals_ext_p, "Unknown (%d)"), error_val);
}
else if ((error_val & 0xc0) == 0x80) {
proto_tree_add_uint_format_value(ti, hf_rsvp_error_value, tvb, offset, 2,
error_val, "Organization specific subcode (%u)", error_val);
}
else if ((error_val & 0xc0) == 0xc0) {
proto_tree_add_uint_format_value(ti, hf_rsvp_error_value, tvb, offset, 2,
error_val, "Service specific subcode (%u)", error_val);
}
break;
case RSVP_ERROR_UNKNOWN_CLASS:
case RSVP_ERROR_UNKNOWN_C_TYPE:
error_class = error_val / 256;
error_ctype = error_val % 256;
proto_tree_add_uint_format_value(ti, hf_rsvp_class, tvb, offset, 2, error_class, "%u (%s) - CType: %u",
error_class, val_to_str_ext_const(error_class, &rsvp_class_vals_ext, "Unknown"),
error_ctype);
break;
case RSVP_ERROR_POLICY:
case RSVP_ERROR_NOTIFY:
case RSVP_ERROR_ROUTING:
case RSVP_ERROR_DIFFSERV:
case RSVP_ERROR_DSTE:
case RSVP_ERROR_CALL_MGMT:
DISSECTOR_ASSERT(rsvp_error_vals_ext_p != NULL);
proto_tree_add_uint_format_value(ti, hf_rsvp_error_value, tvb, offset, 2, error_val, "%s (%u)",
val_to_str_ext(error_val, rsvp_error_vals_ext_p, "Unknown (%d)"), error_val);
break;
default:
proto_tree_add_uint_format_value(ti, hf_rsvp_error_value, tvb, offset, 2, error_val, "%u", error_val);
break;
}
return error_val;
}
static void
dissect_rsvp_error(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int offset3 = 0;
guint8 error_flags;
guint8 error_code;
guint16 error_val;
proto_tree *ti2 = NULL, *rsvp_error_subtree;
switch(type) {
case 1: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
if(obj_length>4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_error_node_ipv4, tvb, offset2, 4, ENC_BIG_ENDIAN);
offset3 = offset2+4;
}
break;
}
case 2: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
if(obj_length>4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_error_node_ipv6, tvb, offset2, 16, ENC_NA);
offset3 = offset2+16;
}
break;
}
case 3: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "3 - IPv4 IF-ID");
if(obj_length>4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_error_node_ipv4, tvb, offset2, 4, ENC_BIG_ENDIAN);
offset3 = offset2+4;
}
break;
}
case 4: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 - IPv6 IF-ID");
if(obj_length>16) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_error_node_ipv6, tvb, offset2, 16, ENC_NA);
offset3 = offset2+16;
}
break;
}
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
if(obj_length>4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_data, tvb, offset2, obj_length - 4, ENC_NA);
}
return;
}
if(obj_length>4) {
error_flags = tvb_get_guint8(tvb, offset3);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_flags,
tvb, offset3, 1, ENC_BIG_ENDIAN);
rsvp_error_subtree = proto_item_add_subtree(ti2, TREE(TT_ERROR_FLAGS));
proto_tree_add_item(rsvp_error_subtree, hf_rsvp_error_flags_path_state_removed,
tvb, offset3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_error_subtree, hf_rsvp_error_flags_not_guilty,
tvb, offset3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_error_subtree, hf_rsvp_error_flags_in_place,
tvb, offset3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti2, " %s %s %s",
(error_flags & (1U<<2)) ? "Path-State-Removed" : "",
(error_flags & (1U<<1)) ? "NotGuilty" : "",
(error_flags & (1U<<0)) ? "InPlace" : "");
error_code = tvb_get_guint8(tvb, offset3+1);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_error_error_code, tvb, offset3+1, 1, ENC_BIG_ENDIAN);
error_val = dissect_rsvp_error_value(rsvp_object_tree, tvb, offset3+2, error_code);
switch (type) {
case 1:
proto_item_set_text(ti, "ERROR: IPv4, Error code: %s, Value: %d, Error Node: %s",
val_to_str_ext(error_code, &rsvp_error_codes_ext, "Unknown (%d)"),
error_val, tvb_ip_to_str(tvb, offset2));
break;
case 3:
proto_item_set_text(ti, "ERROR: IPv4 IF-ID, Error code: %s, Value: %d, Control Node: %s. ",
val_to_str_ext(error_code, &rsvp_error_codes_ext, "Unknown (%d)"),
error_val, tvb_ip_to_str(tvb, offset2));
dissect_rsvp_ifid_tlv(ti, pinfo, rsvp_object_tree, tvb, offset+12, obj_length-12,
TREE(TT_ERROR_SUBOBJ));
break;
}
}
}
static void
dissect_rsvp_scope(proto_item *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen;
mylen = obj_length - 4;
switch(type) {
case 1: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
while (mylen > 0) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_scope_ipv4_address, tvb, offset2, 4, ENC_BIG_ENDIAN);
offset2 += 4;
mylen -= 4;
}
break;
}
case 2: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
while (mylen > 0) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_scope_ipv6_address, tvb, offset2, 16, ENC_NA);
offset2 += 16;
mylen -= 16;
}
break;
}
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_scope_data, tvb, offset2, mylen, ENC_NA);
break;
}
}
static void
dissect_rsvp_style(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1: {
guint32 style;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_style_flags, tvb, offset2, 1, ENC_BIG_ENDIAN);
style = tvb_get_ntoh24(tvb, offset2+1);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_style_style, tvb, offset2+1, 3, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "STYLE: %s (%d)",
val_to_str_const(style, style_vals, "Unknown"),
style);
break;
}
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_style_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_confirm(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_confirm_receiver_address_ipv4, tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "CONFIRM: Receiver %s",
tvb_ip_to_str(tvb, offset2));
break;
}
case 2: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_confirm_receiver_address_ipv6, tvb, offset2, 16, ENC_NA);
break;
}
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_confirm_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_template_filter(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type,
rsvp_conversation_info *rsvph)
{
int offset2 = offset + 4;
proto_item_set_text(ti, "%s", summary_template(tvb, offset));
switch(type) {
case 1:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_PORT],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
set_address_tvb(&rsvph->source, AT_IPv4, 4, tvb, offset2);
rsvph->udp_source_port = tvb_get_ntohs(tvb, offset2+6);
break;
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_template_filter_source_address_ipv6, tvb, offset2, 16, ENC_NA);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_template_filter_source_port, tvb, offset2+18, 2, ENC_BIG_ENDIAN);
break;
case 7:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "7 - IPv4 LSP");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
if (rsvp_class == RSVP_CLASS_SENDER_TEMPLATE){
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_SHORT_CALL_ID],
tvb, offset2+4, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_LSP_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
set_address_tvb(&rsvph->source, AT_IPv4, 4, tvb, offset2);
rsvph->udp_source_port = tvb_get_ntohs(tvb, offset2+6);
break;
case 8:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "8 - IPv6 LSP");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 16, ENC_BIG_ENDIAN);
if (rsvp_class == RSVP_CLASS_SENDER_TEMPLATE){
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_SHORT_CALL_ID],
tvb, offset2+16, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_LSP_ID],
tvb, offset2+18, 2, ENC_BIG_ENDIAN);
set_address_tvb(&rsvph->source, AT_IPv6, 16, tvb, offset2);
rsvph->udp_source_port = tvb_get_ntohs(tvb, offset2+18);
break;
case 9:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "9 - IPv4 Aggregate");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
set_address_tvb(&rsvph->source, AT_IPv4, 4, tvb, offset2);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_template_filter_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_eth_tspec_tlv(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int tlv_length,
int subtree_type)
{
int tlv_off;
int bit_offset;
guint16 tlv_type;
int tlv_len;
guint8 profile;
proto_tree *rsvp_ethspec_subtree, *ethspec_profile_subtree, *ti3;
for (tlv_off = 0; tlv_off < tlv_length; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || (tlv_off+tlv_len > tlv_length)) {
proto_tree_add_expert(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, offset+tlv_off+2, 2);
return;
}
switch(tlv_type) {
case 0:
case 1:
case 2:
rsvp_ethspec_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len, subtree_type, NULL,
"Ethernet Bandwidth Profile TLV: CIR=%.10g, CBS=%.10g, "
"EIR=%.10g, EBS=%.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8),
tvb_get_ntohieee_float(tvb, offset+tlv_off+12),
tvb_get_ntohieee_float(tvb, offset+tlv_off+16),
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
proto_tree_add_uint_format_value(rsvp_ethspec_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%u - Ethernet Bandwidth Profile", tlv_type);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
profile = tvb_get_guint8(tvb, offset+tlv_off+4);
ti3 = proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_profile, tvb, offset+tlv_off+4, 1, ENC_NA);
ethspec_profile_subtree = proto_item_add_subtree(ti3, TREE(TT_ETHSPEC_SUBTREE));
proto_tree_add_item(ethspec_profile_subtree, hf_rsvp_eth_tspec_tlv_color_mode,
tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ethspec_profile_subtree, hf_rsvp_eth_tspec_tlv_coupling_flag,
tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti3, " %s %s",
(profile & (1U<<1)) ? "CM" : "",
(profile & (1U<<0)) ? "CF" : "");
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_index, tvb, offset+tlv_off+5, 1, ENC_NA);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_reserved, tvb, offset+tlv_off+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_cir, tvb, offset+tlv_off+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_cbs, tvb, offset+tlv_off+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_eir, tvb, offset+tlv_off+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_ebs, tvb, offset+tlv_off+20, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "ETH profile: CIR=%.10g, CBS=%.10g, EIR=%.10g, "
"EBS=%.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8),
tvb_get_ntohieee_float(tvb, offset+tlv_off+12),
tvb_get_ntohieee_float(tvb, offset+tlv_off+16),
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
break;
case 3:
if (tlv_len != 8){
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length,
tvb, offset+tlv_off+2, 2, "Invalid TLV length");
return;
}
bit_offset = (offset<<5) + 31;
proto_tree_add_bits_item(rsvp_object_tree, hf_rsvp_eth_tspec_il2cp, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(rsvp_object_tree, hf_rsvp_eth_tspec_el2cp, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
break;
case 255:
rsvp_ethspec_subtree = proto_tree_add_subtree(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
subtree_type, NULL, "RESERVED (RFC6003)");
proto_tree_add_uint_format_value(rsvp_ethspec_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%u (RESERVED)", tlv_type);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
break;
case 129:
rsvp_ethspec_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len, subtree_type, NULL,
"Ethernet Bandwidth Profile TLV: CIR=%.10g, CBS=%.10g, "
"EIR=%.10g, EBS=%.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8),
tvb_get_ntohieee_float(tvb, offset+tlv_off+12),
tvb_get_ntohieee_float(tvb, offset+tlv_off+16),
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
proto_tree_add_uint_format_value(rsvp_ethspec_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "%u - Ethernet Bandwidth Profile", tlv_type);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
profile = tvb_get_guint8(tvb, offset+tlv_off+4);
ti3 = proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_profile, tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
ethspec_profile_subtree = proto_item_add_subtree(ti3, TREE(TT_ETHSPEC_SUBTREE));
proto_tree_add_item(ethspec_profile_subtree, hf_rsvp_eth_tspec_tlv_color_mode,
tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ethspec_profile_subtree, hf_rsvp_eth_tspec_tlv_coupling_flag,
tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti3, " %s %s",
(profile & (1U<<1)) ? "CM" : "",
(profile & (1U<<0)) ? "CF" : "");
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_index, tvb, offset+tlv_off+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_reserved, tvb, offset+tlv_off+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_cir, tvb, offset+tlv_off+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_cbs, tvb, offset+tlv_off+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_eir, tvb, offset+tlv_off+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ethspec_subtree, hf_rsvp_eth_tspec_ebs, tvb, offset+tlv_off+20, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "ETH profile: CIR=%.10g, CBS=%.10g, EIR=%.10g, "
"EBS=%.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8),
tvb_get_ntohieee_float(tvb, offset+tlv_off+12),
tvb_get_ntohieee_float(tvb, offset+tlv_off+16),
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
break;
default:
proto_tree_add_uint_format(rsvp_object_tree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "Unknown TLV: %u", tlv_type);
break;
}
tlv_off += tlv_len;
}
}
static void
dissect_rsvp_tspec(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen;
proto_tree *tspec_tree, *ti2 = NULL;
guint8 signal_type;
mylen = obj_length - 4;
switch(type) {
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - Integrated Services");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_message_format_version, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_data_length, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
mylen -= 4;
offset2 += 4;
proto_item_set_text(ti, "SENDER TSPEC: IntServ, ");
while (mylen > 0) {
guint8 param_id;
guint param_len, raw_len;
guint param_len_processed;
guint length;
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_service_header, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_uint(rsvp_object_tree, hf_rsvp_data_length, tvb, offset2+2, 2, ENC_BIG_ENDIAN, &length);
mylen -= 4;
offset2 += 4;
param_len_processed = 0;
while (param_len_processed < length) {
param_id = tvb_get_guint8(tvb, offset2);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_parameter, tvb, offset2, 1, ENC_NA);
raw_len = tvb_get_ntohs(tvb, offset2+2);
param_len = raw_len + 1;
switch(param_id) {
case 127:
proto_item_set_len(ti2, param_len*4);
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_item(tspec_tree, hf_rsvp_parameter_flags, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(tspec_tree, hf_rsvp_parameter_length, tvb, offset2+2, 2, raw_len);
proto_tree_add_item(tspec_tree, hf_rsvp_tspec_token_bucket_rate, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_tspec_token_bucket_size, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_tspec_peak_data_rate, tvb, offset2+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_minimum_policed_unit, tvb, offset2+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_maximum_packet_size, tvb, offset2+20, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Token Bucket, %.10g bytes/sec. ",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_item_append_text(ti2, "Rate=%.10g Burst=%.10g Peak=%.10g m=%u M=%u",
tvb_get_ntohieee_float(tvb, offset2+4),
tvb_get_ntohieee_float(tvb, offset2+8),
tvb_get_ntohieee_float(tvb, offset2+12),
tvb_get_ntohl(tvb, offset2+16),
tvb_get_ntohl(tvb, offset2+20));
break;
case 128:
proto_item_set_len(ti2, param_len*4);
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_item(tspec_tree, hf_rsvp_parameter_flags, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(tspec_tree, hf_rsvp_parameter_length, tvb, offset2+2, 2, raw_len);
proto_tree_add_item(tspec_tree, hf_rsvp_maximum_packet_size, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Null Service. M=%u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti2, "Max pkt size=%u",
tvb_get_ntohl(tvb, offset2+4));
break;
case 126:
proto_item_set_len(ti2, param_len*4);
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_item(tspec_tree, hf_rsvp_parameter_flags, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(tspec_tree, hf_rsvp_parameter_length, tvb, offset2+2, 2, raw_len);
proto_tree_add_item(tspec_tree, hf_rsvp_tspec_hint, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_compression_factor, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Compression Hint. Hint=%u, Factor=%u",
tvb_get_ntohl(tvb, offset2+4),
tvb_get_ntohl(tvb, offset2+8));
proto_item_append_text(ti2, "Hint=%u, Factor=%u",
tvb_get_ntohl(tvb, offset2+4),
tvb_get_ntohl(tvb, offset2+8));
break;
default:
proto_item_set_len(ti2, param_len*4);
expert_add_info_format(pinfo, ti2, &ei_rsvp_parameter, "Unknown parameter %d, %d words", param_id, param_len);
break;
}
param_len_processed += param_len;
offset2 += param_len*4;
}
mylen -= length*4;
}
break;
case 4:
proto_item_set_text(ti, "SENDER TSPEC: SONET/SDH, ");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 - SONET/SDH");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_signal_type_sonet, tvb, offset2, 1, ENC_BIG_ENDIAN);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_requested_concatenation, tvb, offset2+1, 1, ENC_BIG_ENDIAN);
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_standard_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_arbitrary_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_number_of_contiguous_components, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_number_of_virtual_components, tvb, offset2+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_multiplier, tvb, offset2+6, 2, ENC_BIG_ENDIAN);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_transparency, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_regenerator_section,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_multiplex_section,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_J0_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_SOH_RSOH_DCC_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_LOH_MSOH_DCC_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_LOH_MSOH_extended_DCC_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_K1_K2_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_E1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_F1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_E2_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_B1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_B2_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_M0_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_M1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_profile, tvb, offset2+12, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Signal [%s], RCC %d, NCC %d, NVC %d, MT %d, Transparency %d, Profile %d",
val_to_str_ext_const(signal_type, &gmpls_sonet_signal_type_str_ext, "Unknown"),
tvb_get_guint8(tvb, offset2+1), tvb_get_ntohs(tvb, offset2+2),
tvb_get_ntohs(tvb, offset2+4), tvb_get_ntohs(tvb, offset2+6),
tvb_get_ntohl(tvb, offset2+8), tvb_get_ntohl(tvb, offset2+12));
break;
case 5:
proto_item_set_text(ti, "SENDER TSPEC: G.709, ");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1,
type, "5 - G.709");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_signal_type_g709, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_number_of_multiplexed_components, tvb, offset2 + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_number_of_virtual_components, tvb, offset2 + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_multiplier, tvb, offset2 + 6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Signal [%s], NMC %d, NVC %d, MT %d",
rval_to_str(signal_type,
gmpls_g709_signal_type_rvals,
"Unknown"),
tvb_get_ntohs(tvb, offset2 + 2),
tvb_get_ntohs(tvb, offset2 + 4),
tvb_get_ntohs(tvb, offset2 + 6));
break;
case 6:
proto_item_set_text(ti, "SENDER TSPEC: Ethernet, ");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "6 - Ethernet");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_switching_granularity, tvb, offset2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_mtu, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
dissect_rsvp_eth_tspec_tlv(ti, pinfo, rsvp_object_tree, tvb, offset+8, obj_length-8,
TREE(TT_TSPEC_SUBTREE));
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_tspec_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_flowspec(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen, signal_type;
proto_tree *flowspec_tree, *ti2 = NULL;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
mylen = obj_length - 4;
switch(type) {
case 2:
if (mylen < 4) {
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, 0, 0,
"Object length %u < 8", obj_length);
return;
}
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_message_format_version, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_data_length, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "FLOWSPEC: ");
mylen -= 4;
offset2+= 4;
while (mylen > 0) {
guint8 service_num;
guint length;
guint8 param_id;
guint param_len, raw_len;
guint param_len_processed;
if (mylen < 4) {
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, 0, 0,
"Object length %u not large enough", obj_length);
return;
}
service_num = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_service_header, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_uint(rsvp_object_tree, hf_rsvp_data_length, tvb, offset2+2, 2, ENC_BIG_ENDIAN, &length);
mylen -= 4;
offset2 += 4;
proto_item_append_text(ti, "%s: ",
val_to_str_ext(service_num, &intsrv_services_str_ext,
"Unknown (%d)"));
param_len_processed = 0;
while (param_len_processed < length) {
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_parameter, tvb, offset2, 1, ENC_NA);
param_id = tvb_get_guint8(tvb, offset2);
raw_len = tvb_get_ntohs(tvb, offset2+2);
param_len = raw_len + 1;
switch(param_id) {
case 127:
proto_item_set_len(ti2, param_len*4);
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_item(flowspec_tree, hf_rsvp_parameter_flags, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(flowspec_tree, hf_rsvp_parameter_length, tvb, offset2+2, 2, raw_len);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_token_bucket_rate, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_token_bucket_size, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_peak_data_rate, tvb, offset2+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_minimum_policed_unit, tvb, offset2+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_maximum_packet_size, tvb, offset2+20, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Token Bucket, %.10g bytes/sec. ",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_item_append_text(ti2, "Rate=%.10g Burst=%.10g Peak=%.10g m=%u M=%u",
tvb_get_ntohieee_float(tvb, offset2+4),
tvb_get_ntohieee_float(tvb, offset2+8),
tvb_get_ntohieee_float(tvb, offset2+12),
tvb_get_ntohl(tvb, offset2+16),
tvb_get_ntohl(tvb, offset2+20));
break;
case 130:
proto_item_set_len(ti2, param_len*4);
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_item(flowspec_tree, hf_rsvp_parameter_flags, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(flowspec_tree, hf_rsvp_parameter_length, tvb, offset2+2, 2, raw_len);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_rate, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_slack_term, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "RSpec, %.10g bytes/sec. ",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_item_append_text(ti2, "R=%.10g, s=%u",
tvb_get_ntohieee_float(tvb, offset2+4),
tvb_get_ntohl(tvb, offset2+8));
break;
case 128:
proto_item_set_len(ti2, param_len*4);
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_item(flowspec_tree, hf_rsvp_parameter_flags, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(flowspec_tree, hf_rsvp_parameter_length, tvb, offset2+2, 2, raw_len);
proto_tree_add_item(flowspec_tree, hf_rsvp_maximum_packet_size, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Null Service. M=%u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti2, "Max pkt size=%u",
tvb_get_ntohl(tvb, offset2+4));
break;
default:
expert_add_info_format(pinfo, ti2, &ei_rsvp_parameter, "Unknown parameter %d, %d words", param_id, param_len);
break;
}
param_len_processed += param_len;
offset2 += param_len * 4;
}
mylen -= length*4;
}
break;
case 4:
proto_item_set_text(ti, "FLOWSPEC: SONET/SDH, ");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 - SONET/SDH");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_signal_type_sonet, tvb, offset2, 1, ENC_BIG_ENDIAN);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_requested_concatenation, tvb, offset2+1, 1, ENC_BIG_ENDIAN);
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_standard_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_arbitrary_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_number_of_contiguous_components, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_number_of_virtual_components, tvb, offset2+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_multiplier, tvb, offset2+6, 2, ENC_BIG_ENDIAN);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_transparency, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_regenerator_section,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_multiplex_section,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_J0_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_SOH_RSOH_DCC_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_LOH_MSOH_DCC_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_LOH_MSOH_extended_DCC_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_K1_K2_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_E1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_F1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_E2_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_B1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_B2_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_M0_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_M1_transparency,
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_profile, tvb, offset2+12, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Signal [%s], RCC %d, NCC %d, NVC %d, MT %d, Transparency %d, Profile %d",
val_to_str_ext_const(signal_type, &gmpls_sonet_signal_type_str_ext, "Unknown"),
tvb_get_guint8(tvb, offset2+1), tvb_get_ntohs(tvb, offset2+2),
tvb_get_ntohs(tvb, offset2+4), tvb_get_ntohs(tvb, offset2+6),
tvb_get_ntohl(tvb, offset2+8), tvb_get_ntohl(tvb, offset2+12));
break;
case 5:
proto_item_set_text(ti, "FLOWSPEC: G.709, ");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1,
type, "5 - G.709");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_signal_type_g709, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_number_of_multiplexed_components, tvb, offset2 + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_number_of_virtual_components, tvb, offset2 + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_multiplier, tvb, offset2 + 6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Signal [%s], NMC %d, NVC %d, MT %d",
rval_to_str(signal_type,
gmpls_g709_signal_type_rvals,
"Unknown"),
tvb_get_ntohs(tvb, offset2 + 2),
tvb_get_ntohs(tvb, offset2 + 4),
tvb_get_ntohs(tvb, offset2 + 6));
break;
case 6:
proto_item_set_text(ti, "FLOWSPEC: Ethernet, ");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "6 - Ethernet");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_switching_granularity, tvb, offset2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_flowspec_mtu, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
dissect_rsvp_eth_tspec_tlv(ti, pinfo, rsvp_object_tree, tvb, offset+8, obj_length-8,
TREE(TT_FLOWSPEC_SUBTREE));
break;
default:
break;
}
}
static void
dissect_rsvp_adspec(proto_item *ti _U_, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen, i;
proto_tree *adspec_tree, *adspec_type_tree;
proto_item *ti2;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
mylen = obj_length - 4;
proto_tree_add_item(rsvp_object_tree, hf_rsvp_adspec_message_format_version, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_data_length, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
mylen -= 4;
offset2 += 4;
while (mylen > 0) {
guint8 service_num;
guint length;
const char *str;
service_num = tvb_get_guint8(tvb, offset2);
str = val_to_str_ext_const(service_num, &intsrv_services_str_ext, "Unknown");
length = tvb_get_ntohs(tvb, offset2+2);
adspec_tree = proto_tree_add_subtree(rsvp_object_tree, tvb, offset2,
(length+1)*4, TREE(TT_ADSPEC_SUBTREE), NULL, str);
proto_tree_add_item(adspec_tree, hf_rsvp_adspec_service_header, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adspec_tree, hf_rsvp_hf_rsvp_adspec_break_bit, tvb, offset2+1, 1, ENC_NA);
proto_tree_add_uint(adspec_tree, hf_rsvp_data_length, tvb, offset2+2, 2, length);
mylen -= 4;
offset2 += 4;
i = length*4;
while (i > 0) {
guint id, phdr_length;
ti2 = proto_tree_add_item_ret_uint(adspec_tree, hf_rsvp_adspec_type, tvb, offset2, 1, ENC_NA, &id);
adspec_type_tree = proto_item_add_subtree(ti2, TREE(TT_ADSPEC_TYPE_SUBTREE));
proto_tree_add_item_ret_uint(adspec_type_tree, hf_rsvp_adspec_len, tvb, offset2+2, 2, ENC_BIG_ENDIAN, &phdr_length);
proto_item_set_len(ti2, phdr_length);
str = try_val_to_str_ext(id, &adspec_params_ext);
if (str) {
switch(id) {
case 4:
case 8:
case 10:
case 133:
case 134:
case 135:
case 136:
proto_tree_add_uint_format(adspec_type_tree, hf_rsvp_adspec_uint, tvb, offset2, (phdr_length+1)<<2, tvb_get_ntohl(tvb, offset2+4),
"%s: %u", str, tvb_get_ntohl(tvb, offset2+4));
break;
case 6:
proto_tree_add_float_format(adspec_type_tree, hf_rsvp_adspec_float, tvb, offset2, (phdr_length+1)<<2, tvb_get_ntohieee_float(tvb, offset2+4),
"%s: %.10g", str, tvb_get_ntohieee_float(tvb, offset2+4));
break;
default:
proto_tree_add_bytes_format(adspec_tree, hf_rsvp_adspec_bytes, tvb, offset2, (phdr_length+1)<<2, NULL, "%s", str);
break;
}
} else {
expert_add_info(pinfo, ti2, &ei_rsvp_adspec_type);
}
offset2 += (phdr_length+1)<<2;
i -= (phdr_length+1)<<2;
mylen -= (phdr_length+1)<<2;
}
}
}
static void
dissect_rsvp_integrity(proto_item *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
proto_tree *ti2, *rsvp_integ_flags_tree;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_integrity_flags, tvb, offset2, 1, ENC_BIG_ENDIAN);
rsvp_integ_flags_tree = proto_item_add_subtree(ti2, TREE(TT_INTEGRITY_FLAGS));
proto_tree_add_item(rsvp_integ_flags_tree, hf_rsvp_integrity_flags_handshake,
tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_integrity_key_identifier, tvb, offset2+2, 6, ENC_NA);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_integrity_sequence_number, tvb, offset2+8, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_integrity_hash, tvb, offset2+16, obj_length - 20, ENC_NA);
}
static void
dissect_rsvp_policy(proto_item *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_policy_data, tvb, offset2, obj_length - 4, ENC_NA);
}
static void
dissect_rsvp_label_request(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
static const value_string lab_req_type_str[] = {
{ 1, ""},
{ 2, "(Label Request with ATM label Range)"},
{ 3, "(Label Request with Frame-Relay label Range)"},
{ 4, "(Generalized Label Request)"},
{ 5, "(Generalized Channel_set Label Request)"},
{ 0, NULL }
};
static value_string_ext lab_req_type_str_ext = VALUE_STRING_EXT_INIT(lab_req_type_str);
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "%d %s", type,
val_to_str_ext_const(type, &lab_req_type_str_ext, "Unknown"));
switch(type) {
case 1: {
unsigned short l3pid = tvb_get_ntohs(tvb, offset2+2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_l3pid, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LABEL REQUEST: Basic: L3PID: %s (0x%04x)",
val_to_str_const(l3pid, etype_vals, "Unknown"),
l3pid);
break;
}
case 2: {
unsigned short l3pid = tvb_get_ntohs(tvb, offset2+2);
unsigned short min_vpi, min_vci, max_vpi, max_vci;
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_l3pid, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_m, tvb, offset2+4, 1, ENC_NA);
min_vpi = tvb_get_ntohs(tvb, offset2+4) & 0x7f;
min_vci = tvb_get_ntohs(tvb, offset2+6);
max_vpi = tvb_get_ntohs(tvb, offset2+8) & 0x7f;
max_vci = tvb_get_ntohs(tvb, offset2+10);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_min_vpi, tvb, offset2+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_min_vci, tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_max_vpi, tvb, offset2+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_max_vci, tvb, offset2+10, 2, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LABEL REQUEST: ATM: L3PID: %s (0x%04x). VPI/VCI: Min: %d/%d, Max: %d/%d. %s Merge. ",
val_to_str_const(l3pid, etype_vals, "Unknown"), l3pid,
min_vpi, min_vci, max_vpi, max_vci,
(tvb_get_guint8(tvb, offset2+4) & 0x80) ? "Can" : "Cannot");
break;
}
case 3: {
guint16 l3pid = tvb_get_ntohs(tvb, offset2+2);
guint32 min_dlci, max_dlci, dlci_len, dlci_len_code;
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_l3pid, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
dlci_len_code = (tvb_get_ntohs(tvb, offset2+4) & 0x0180) >> 7;
min_dlci = tvb_get_ntohl(tvb, offset2+4) & 0x7fffff;
max_dlci = tvb_get_ntohl(tvb, offset2+8) & 0x7fffff;
switch(dlci_len_code) {
case 0:
dlci_len = 10;
min_dlci &= 0x3ff;
max_dlci &= 0x3ff;
break;
case 2:
dlci_len = 23;
break;
default:
dlci_len = 0;
min_dlci = 0;
max_dlci = 0;
break;
}
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_dlci_length, tvb, offset2+4, 2,
dlci_len, "%s (%d)",
(dlci_len==10) ? "10 bits" :
(dlci_len==23) ? "23 bits" :
"INVALID", dlci_len_code);
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_min_dlci, tvb, offset2+5, 3, min_dlci);
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_max_dlci, tvb, offset2+8, 2, max_dlci);
proto_item_set_text(ti, "LABEL REQUEST: Frame: L3PID: %s (0x%04x). DLCI Len: %s. Min DLCI: %d. Max DLCI: %d",
val_to_str_const(l3pid, etype_vals, "Unknown"), l3pid,
(dlci_len==10) ? "10 bits" :
(dlci_len==23) ? "23 bits" :
"INVALID", min_dlci, max_dlci);
break;
}
case 4:
case 5: {
unsigned short l3pid = tvb_get_ntohs(tvb, offset2+2);
unsigned char lsp_enc = tvb_get_guint8(tvb,offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_lsp_encoding_type, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_switching_type, tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_g_pid, tvb, offset2+2, 2, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LABEL REQUEST: Generalized: LSP Encoding=%s, "
"Switching Type=%s, G-PID=%s ",
rval_to_str(lsp_enc, gmpls_lsp_enc_rvals, "Unknown (%d)"),
rval_to_str(tvb_get_guint8(tvb,offset2+1),
gmpls_switching_type_rvals, "Unknown (%d)"),
rval_to_str_const(l3pid, gmpls_gpid_rvals,
val_to_str(l3pid, etype_vals,
"Unknown (0x%04x)")));
break;
}
default:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_request_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_glabel_lambda(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset)
{
float freq = 0.0f;
guint32 wavelength = 0;
float cs_thz = 0.0f;
proto_tree* wavelength_tree;
guint8 grid, cs;
gint16 n;
static const value_string grid1_cs_vals[] = {
{ 1, "100GHz"},
{ 2, "50GHz"},
{ 3, "25GHz"},
{ 4, "12.5GHz"},
{ 0, NULL }
};
static const value_string grid2_cs_vals[] = {
{ 1, "20nm"},
{ 0, NULL }
};
wavelength_tree = proto_tree_add_subtree(rsvp_object_tree, tvb, offset, 4, TREE(TT_WAVELENGTH), NULL, "Wavelength Label");
proto_tree_add_item(wavelength_tree, hf_rsvp_wavelength_grid, tvb, offset, 1, ENC_NA);
grid = ((tvb_get_guint8(tvb, offset) & 0xE0) >> 5);
cs = ((tvb_get_guint8(tvb, offset) & 0x1E) >> 1);
n = tvb_get_ntohs(tvb, offset + 2);
switch(grid) {
case 1:
cs_thz =
cs == 1 ? 0.1f :
cs == 2 ? 0.05f :
cs == 3 ? 0.025f :
cs == 4 ? 0.0125f :
0.0f;
freq = 193.1f + (n * cs_thz);
proto_tree_add_uint_format_value(wavelength_tree, hf_rsvp_wavelength_channel_spacing, tvb, offset, 1, tvb_get_guint8(tvb, offset),
"%s", val_to_str_const(cs, grid1_cs_vals, "Unknown"));
proto_tree_add_item(wavelength_tree, hf_rsvp_wavelength_n, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_float_format_value(wavelength_tree, hf_rsvp_wavelength_freq, tvb, offset, 4, freq, "%.2fTHz", freq);
proto_item_append_text(ti, ": Wavelength: grid=DWDM, channel spacing=%s, n=%d, freq=%.2fTHz",
val_to_str_const(cs, grid1_cs_vals, "Unknown"), n, freq);
break;
case 2:
wavelength = 1471 + (n * 20);
proto_tree_add_uint_format_value(wavelength_tree, hf_rsvp_wavelength_channel_spacing, tvb, offset, 1, tvb_get_guint8(tvb, offset),
"%s", val_to_str_const(cs, grid2_cs_vals, "Unknown"));
proto_tree_add_item(wavelength_tree, hf_rsvp_wavelength_n, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(wavelength_tree, hf_rsvp_wavelength_wavelength, tvb, offset, 4, wavelength, "%unm", wavelength);
proto_item_append_text(ti, ": Wavelength: grid=CWDM, channel spacing=%s, n=%d, wavelength=%unm",
val_to_str_const(cs, grid2_cs_vals, "Unknown"), n, wavelength);
break;
default:
proto_tree_add_item(wavelength_tree, hf_rsvp_wavelength_channel_spacing, tvb, offset, 1, ENC_NA);
proto_tree_add_item(wavelength_tree, hf_rsvp_wavelength_n, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": Wavelength: grid=%u, channel spacing=%u, n=%d", grid, cs, n);
break;
}
}
static void
dissect_glabel_sdh(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset)
{
guint16 s;
guint8 u, k, l, m;
proto_tree* sonet_tree;
sonet_tree = proto_tree_add_subtree(rsvp_object_tree, tvb, offset, 4, TREE(TT_SONET_SDH), NULL, "SONET/SDH Label");
proto_tree_add_item(sonet_tree, hf_rsvp_sonet_s, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sonet_tree, hf_rsvp_sonet_u, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sonet_tree, hf_rsvp_sonet_k, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sonet_tree, hf_rsvp_sonet_l, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sonet_tree, hf_rsvp_sonet_m, tvb, offset+3, 1, ENC_BIG_ENDIAN);
s = tvb_get_ntohs(tvb, offset);
u = ((tvb_get_guint8(tvb, offset + 2) & 0xF0) >> 4);
k = ((tvb_get_guint8(tvb, offset + 2) & 0x0F) >> 0);
l = ((tvb_get_guint8(tvb, offset + 3) & 0xF0) >> 4);
m = ((tvb_get_guint8(tvb, offset + 3) & 0x0F) >> 0);
proto_item_append_text(ti, ": SONET/SDH: S=%u, U=%u, K=%u, L=%u, M=%u",
s, u, k, l, m);
}
static void
dissect_glabel_g709(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset)
{
guint8 t1, t2, t3;
proto_tree* g709_tree;
g709_tree = proto_tree_add_subtree(rsvp_object_tree, tvb, offset, 4, TREE(TT_G709), NULL, "G.709 ODUk Label");
proto_tree_add_item(g709_tree, hf_rsvp_g709_t3, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(g709_tree, hf_rsvp_g709_t2, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(g709_tree, hf_rsvp_g709_t1, tvb, offset+3, 1, ENC_BIG_ENDIAN);
t2 = ((tvb_get_guint8(tvb, offset + 3) & 0x0E) >> 1);
t1 = ((tvb_get_guint8(tvb, offset + 3) & 0x01) >> 0);
t3 = ((tvb_get_guint8(tvb, offset + 2) & 0x03) << 4);
t3 |= ((tvb_get_guint8(tvb, offset + 3) & 0xF0) >> 4);
proto_item_append_text(ti, ": G.709 ODUk: "
"t3=%u, "
"t2=%u, "
"t1=%u",
t3, t2, t1);
}
static void
dissect_glabel_evpl(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset)
{
int bit_offset;
guint16 vlan_id = ((tvb_get_ntohs(tvb,offset) << 4) & 0xFFFF);
bit_offset = (offset<<2)+3;
proto_tree_add_bits_item(rsvp_object_tree,hf_rsvp_label_generalized_label_evpl_vlad_id,tvb, bit_offset, 12, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": EVPL Generalized Label: "
"VLAN ID = %u" ,vlan_id);
}
static void
dissect_rsvp_label(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class, int type)
{
int offset2 = offset + 4;
int mylen, i;
const char *name;
name = (rsvp_class==RSVP_CLASS_SUGGESTED_LABEL ? "SUGGESTED LABEL":
(rsvp_class==RSVP_CLASS_UPSTREAM_LABEL ? "UPSTREAM LABEL":
(rsvp_class==RSVP_CLASS_RECOVERY_LABEL ? "RECOVERY LABEL":
"LABEL")));
mylen = obj_length - 4;
switch(type) {
case 1:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 (Packet Label)");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_label, tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "%s: %u", name,
tvb_get_ntohl(tvb, offset2));
break;
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 (Generalized Label)");
if (rsvp_generalized_label_option == 1) {
proto_item_set_text(ti, "%s: Generalized: ", name);
for (i = 0; i < mylen; i += 4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_generalized_label, tvb, offset2+i, 4, ENC_BIG_ENDIAN);
if (i < 16) {
proto_item_append_text(ti, "0x%x%s",
tvb_get_ntohl(tvb, offset2+i),
i+4<mylen?", ":"");
} else if (i == 16) {
proto_item_append_text(ti, "...");
}
}
} else if (rsvp_generalized_label_option == 2) {
dissect_glabel_sdh(ti, rsvp_object_tree, tvb, offset2);
} else if (rsvp_generalized_label_option == 4) {
dissect_glabel_g709(ti, rsvp_object_tree, tvb, offset2);
} else if (rsvp_generalized_label_option == 3) {
dissect_glabel_lambda(ti, rsvp_object_tree, tvb, offset2);
} else if (rsvp_generalized_label_option == 5) {
dissect_glabel_evpl(ti, rsvp_object_tree, tvb, offset2);
}
break;
case 4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 (Generalized Channel_set)");
proto_item_append_text(ti, ": Generalized Channel_set");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_data, tvb, offset2, mylen, ENC_NA);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_data, tvb, offset2, mylen, ENC_NA);
break;
}
}
static void
dissect_rsvp_label_set(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 8;
guint8 label_type;
int len, i;
len = obj_length - 8;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_label_set_action, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": %s",
val_to_str(tvb_get_guint8(tvb, offset+4),
action_type_vals, "Unknown (%u)"));
label_type = tvb_get_guint8 (tvb, offset+7);
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_label_set_type, tvb, offset+7, 1, label_type,
"%s", (label_type == 1) ? "Packet Label" : "Generalized Label");
proto_item_append_text(ti, ", %s",
(label_type == 1) ? "Packet Label: " : "Generalized Label: ");
for (i = 0; i < len/4; i++) {
guint32 subchannel = tvb_get_ntohl(tvb, offset2+i*4);
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_label_set_subchannel, tvb, offset2+i*4, 4, subchannel,
"Subchannel %u: %u (0x%x)", i+1, subchannel, subchannel);
if (i<5) {
if (i!=0)
proto_item_append_text(ti, ", ");
proto_item_append_text(ti, "%u",
tvb_get_ntohl(tvb, offset2+i*4));
}
}
}
static void
dissect_rsvp_session_attribute(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
guint8 flags;
guint8 name_len;
proto_tree *ti2, *rsvp_sa_flags_tree;
switch(type) {
case 1:
case 7:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "%u - IPv4 LSP (%sResource Affinities)",
type, (type == 1) ? "" : "No ");
if (type == 1) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_exclude_any, tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_include_any, tvb, offset2+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_include_all, tvb, offset2+8, 4, ENC_BIG_ENDIAN);
offset2 = offset2+12;
}
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_setup_priority, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_hold_priority, tvb, offset2+1, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset2+2);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_flags, tvb, offset2+2, 1, ENC_BIG_ENDIAN);
rsvp_sa_flags_tree = proto_item_add_subtree(ti2,
TREE(TT_SESSION_ATTRIBUTE_FLAGS));
proto_tree_add_item(rsvp_sa_flags_tree, hf_rsvp_sa_flags_local,
tvb, offset2+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_sa_flags_tree, hf_rsvp_sa_flags_label,
tvb, offset2+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_sa_flags_tree, hf_rsvp_sa_flags_se_style,
tvb, offset2+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_sa_flags_tree, hf_rsvp_sa_flags_bandwidth,
tvb, offset2+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_sa_flags_tree, hf_rsvp_sa_flags_node,
tvb, offset2+2, 1, ENC_BIG_ENDIAN);
name_len = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_name_length, tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_name, tvb, offset2+4, name_len, ENC_NA|ENC_ASCII);
proto_item_set_text(ti, "SESSION ATTRIBUTE: SetupPrio %d, HoldPrio %d, %s%s%s%s%s [%s]",
tvb_get_guint8(tvb, offset2),
tvb_get_guint8(tvb, offset2+1),
flags &0x01 ? "Local Protection, " : "",
flags &0x02 ? "Label Recording, " : "",
flags &0x04 ? "SE Style, " : "",
flags &0x08 ? "Bandwidth Protection, " : "",
flags &0x10 ? "Node Protection, " : "",
name_len ? tvb_format_text(tvb, offset2+4, name_len) : "");
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_session_attribute_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_ero_rro_subobjects(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length, int rsvp_class)
{
int i, j, k, l, flags;
proto_tree *ti2 = NULL, *rsvp_ro_subtree, *rsvp_rro_flags_subtree;
int tree_type;
switch(rsvp_class) {
case RSVP_CLASS_EXPLICIT_ROUTE:
tree_type = TREE(TT_EXPLICIT_ROUTE_SUBOBJ);
break;
case RSVP_CLASS_RECORD_ROUTE:
tree_type = TREE(TT_RECORD_ROUTE_SUBOBJ);
break;
default:
return;
}
for (i=1, l = 0; l < obj_length - 4; i++) {
j = tvb_get_guint8(tvb, offset+l);
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE) j &= 0x7f;
switch(j) {
case 1:
k = tvb_get_guint8(tvb, offset+l) & 0x80;
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l, 8,
tree_type, &ti2, "IPv4 Subobject - %s%s",
tvb_ip_to_str(tvb, offset+l+2),
rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE ?
(k ? ", Loose" : ", Strict") : "");
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_loose_hop, tvb, offset+l, 1, ENC_NA);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "1 (IPv4)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_ipv4_hop, tvb, offset+l+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_prefix_length, tvb, offset+l+6, 1, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "IPv4 %s%s",
tvb_ip_to_str(tvb, offset+l+2),
k ? " [L]" : "");
}
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+7);
if (flags&0x20) {
proto_item_append_text(ti, " (Node-id)");
proto_item_append_text(ti2, " (Node-id)");
}
if (flags&0x01) proto_item_append_text(ti2, ", Local Protection Available");
if (flags&0x02) proto_item_append_text(ti2, ", Local Protection In Use");
if (flags&0x04) proto_item_append_text(ti2, ", Backup BW Avail");
if (flags&0x08) proto_item_append_text(ti2, ", Backup is Next-Next-Hop");
ti2 = proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_flags, tvb, offset+l+7, 1, ENC_BIG_ENDIAN);
rsvp_rro_flags_subtree =
proto_item_add_subtree(ti2, TREE(TT_RECORD_ROUTE_SUBOBJ_FLAGS));
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_avail,
tvb, offset+l+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_in_use,
tvb, offset+l+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_bandwidth,
tvb, offset+l+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_node,
tvb, offset+l+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_node_address,
tvb, offset+l+7, 1, ENC_BIG_ENDIAN);
}
break;
case 2:
rsvp_ro_subtree = proto_tree_add_subtree(rsvp_object_tree, tvb,
offset+l, 20, tree_type, &ti2,
"IPv6 Subobject");
k = tvb_get_guint8(tvb, offset+l) & 0x80;
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_loose_hop, tvb, offset+l, 1, ENC_NA);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "2 (IPv6)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_ipv6_hop, tvb, offset+l+2, 16, ENC_NA);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_prefix_length, tvb, offset+l+18, 1, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "IPv6 [...]%s", k ? " [L]":"");
}
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+19);
if (flags&0x20) {
proto_item_append_text(ti, " (Node-id)");
proto_item_append_text(ti2, " (Node-id)");
}
if (flags&0x01) proto_item_append_text(ti2, ", Local Protection Available");
if (flags&0x02) proto_item_append_text(ti2, ", Local Protection In Use");
if (flags&0x04) proto_item_append_text(ti2, ", Backup BW Avail");
if (flags&0x08) proto_item_append_text(ti2, ", Backup is Next-Next-Hop");
ti2 = proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_flags, tvb, offset+l+19, 1, ENC_BIG_ENDIAN);
rsvp_rro_flags_subtree =
proto_item_add_subtree(ti2, TREE(TT_RECORD_ROUTE_SUBOBJ_FLAGS));
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_avail,
tvb, offset+l+19, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_in_use,
tvb, offset+l+19, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_backup_tunnel_bandwidth,
tvb, offset+l+19, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_backup_tunnel_hop,
tvb, offset+l+19, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_node_address,
tvb, offset+l+19, 1, ENC_BIG_ENDIAN);
}
break;
case 3:
k = tvb_get_guint8(tvb, offset+l) & 0x80;
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l, 8,
tree_type, &ti2, "Label Subobject - %d, %s",
tvb_get_ntohl(tvb, offset+l+4),
rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE ?
(k ? "Loose" : "Strict") : "");
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_loose_hop, tvb, offset+l, 1, ENC_NA);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "3 (Label)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+2);
if (flags&0x01) proto_item_append_text(ti2, "The label will be understood if received on any interface");
ti2 = proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_flags, tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
rsvp_rro_flags_subtree =
proto_item_add_subtree(ti2, TREE(TT_RECORD_ROUTE_SUBOBJ_FLAGS));
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_global_label,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ctype, tvb, offset+l+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_label, tvb, offset+l+4, 4, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "Label %d%s",
tvb_get_ntohl(tvb, offset+l+4),
k ? " [L]":"");
}
break;
case 4:
k = tvb_get_guint8(tvb, offset+l) & 0x80;
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l, 8, tree_type, &ti2,
"Unnumbered Interface-ID - %s, %d, %s",
tvb_ip_to_str(tvb, offset+l+4),
tvb_get_ntohl(tvb, offset+l+8),
rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE ?
(k ? "Loose" : "Strict") : "");
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_loose_hop, tvb, offset+l, 1, ENC_NA);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "4 (Unnumbered Interface-ID)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+2);
if (flags&0x01) proto_item_append_text(ti2, ", Local Protection Available");
if (flags&0x02) proto_item_append_text(ti2, ", Local Protection In Use");
ti2 = proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_flags, tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
rsvp_rro_flags_subtree =
proto_item_add_subtree(ti2, TREE(TT_RECORD_ROUTE_SUBOBJ_FLAGS));
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_avail,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_in_use,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_router_id, tvb, offset+l+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_interface_id, tvb, offset+l+8, 4, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "Unnum %s/%d%s",
tvb_ip_to_str(tvb, offset+l+4),
tvb_get_ntohl(tvb, offset+l+8),
k ? " [L]":"");
}
break;
case 32:
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) goto defaultsub;
k = tvb_get_ntohs(tvb, offset+l+2);
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l, 4, tree_type, &ti2,
"Autonomous System %u",
k);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "32 (Autonomous System Number)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_autonomous_system, tvb, offset+l+2, 2, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "AS %d",
tvb_get_ntohs(tvb, offset+l+2));
}
break;
case 64:
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) goto defaultsub;
k = tvb_get_ntohs(tvb, offset+l+2);
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l, 8, tree_type, &ti2,
"Path Key subobject - %s, %u",
tvb_ip_to_str(tvb, offset+l+4),
k);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "64 (Path Key with IPv4 PCE-ID)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_path_key, tvb, offset+l+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_pce_id_ipv4, tvb, offset+l+4, 4, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "Path Key %d", k);
}
break;
case 65:
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) goto defaultsub;
k = tvb_get_ntohs(tvb, offset+l+2);
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l, 8, tree_type, &ti2,
"Path Key subobject - %s, %u",
tvb_ip6_to_str(tvb, offset+l+4),
k);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "65 (Path Key with IPv6 PCE-ID)");
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_path_key, tvb, offset+l+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_pce_id_ipv6, tvb, offset+l+4, 16, ENC_NA);
if (i < 4) {
proto_item_append_text(ti, "Path Key %d", k);
}
break;
case 124:
case 125:
case 126:
case 127:
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE)
goto defaultsub;
else
goto privatesub;
break;
case 252:
case 253:
case 254:
case 255:
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
goto defaultsub;
else
goto privatesub;
break;
privatesub:
{
guint8 private_so_len = tvb_get_guint8(tvb, offset+l+1);
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb, offset+l,
tvb_get_guint8(tvb, offset+l+1),
tree_type, &ti2, "Private Subobject: %d", j);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_loose_hop, tvb, offset+l, 1, ENC_NA);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "%u (Private)", j);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_private_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_ro_subtree,
hf_rsvp_filter[RSVPF_ENT_CODE],
tvb, offset+l+4, 4, ENC_BIG_ENDIAN);
if (private_so_len > 8) {
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_private_data, tvb, offset+l+8, private_so_len - 8, ENC_NA);
}
}
break;
default:
defaultsub:
rsvp_ro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+l,
tvb_get_guint8(tvb, offset+l+1),
tree_type, &ti2, "Unknown subobject: %d", j);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_loose_hop, tvb, offset+l, 1, ENC_NA);
proto_tree_add_uint_format_value(rsvp_ro_subtree, hf_rsvp_type, tvb, offset+l, 1,
j, "%u (Unknown)", j);
proto_tree_add_item(rsvp_ro_subtree, hf_rsvp_ero_rro_subobjects_length, tvb, offset+l+1, 1, ENC_BIG_ENDIAN);
break;
}
if (tvb_get_guint8(tvb, offset+l+1) < 1) {
proto_tree_add_expert_format(rsvp_ro_subtree, pinfo, &ei_rsvp_invalid_length, tvb, offset+l+1, 1,
"Invalid length: %u", tvb_get_guint8(tvb, offset+l+1));
return;
}
l += tvb_get_guint8(tvb, offset+l+1);
if (l < obj_length - 4) {
if (i < 4)
proto_item_append_text(ti, ", ");
else if (i==4)
proto_item_append_text(ti, "...");
}
}
}
static void
dissect_rsvp_xro_subobjects(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int obj_length,
int rsvp_class)
{
int i, lbit, type, l;
proto_tree *rsvp_xro_subtree;
int tree_type;
switch (rsvp_class) {
case RSVP_CLASS_EXCLUDE_ROUTE:
tree_type = TREE(TT_EXCLUDE_ROUTE_SUBOBJ);
break;
default:
return;
}
for (i = 1, l = 0; l < obj_length - 4; i++) {
lbit = tvb_get_guint8(tvb, offset + l) & 0x80;
type = tvb_get_guint8(tvb, offset + l) & 0x7f;
switch (type) {
case 1:
rsvp_xro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset + l, 8, tree_type, NULL,
"IPv4 Subobject - %s",
tvb_ip_to_str(tvb, offset + l + 2));
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_lbit,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_type,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_len,
tvb, offset + l + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_ipv4_addr,
tvb, offset + l + 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_ipv4_prefix,
tvb, offset + l + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_ipv4_attr,
tvb, offset + l + 7, 1, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "IPv4 %s%s",
tvb_ip_to_str(tvb, offset + l + 2),
lbit ? " [L]" : "");
}
break;
case 2:
rsvp_xro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset + l, 20, tree_type, NULL,
"IPv6 Subobject - %s",
tvb_ip6_to_str(tvb, offset + l + 2));
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_lbit,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_type,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_len,
tvb, offset + l + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_ipv6_addr,
tvb, offset + l + 2, 16, ENC_NA);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_ipv6_prefix,
tvb, offset + l + 18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_ipv6_attr,
tvb, offset + l + 19, 1, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "IPv6 [...]%s", lbit ? " [L]" : "");
}
break;
case 34:
rsvp_xro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset + l, 8, tree_type, NULL,
"SRLG Subobject - %u",
tvb_get_ntohl(tvb, offset + l + 2));
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_lbit,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_type,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_len,
tvb, offset + l + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_srlg_id,
tvb, offset + l + 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_srlg_res,
tvb, offset + l + 6, 2, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "SRLG %u%s",
tvb_get_ntohl(tvb, offset + l + 2),
lbit ? " [L]" : "");
}
break;
default:
rsvp_xro_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset + l,
tvb_get_guint8(tvb, offset + l + 1),
tree_type, NULL, "Unknown subobject: %d", type);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_lbit,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_type,
tvb, offset + l, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_xro_subtree, hf_rsvp_xro_sobj_len,
tvb, offset + l + 1, 1, ENC_BIG_ENDIAN);
break;
}
if (tvb_get_guint8(tvb, offset + l + 1) < 1) {
proto_tree_add_expert_format(rsvp_xro_subtree, pinfo, &ei_rsvp_invalid_length, tvb, offset + l + 1, 1,
"Invalid Length: %u",
tvb_get_guint8(tvb, offset + l + 1));
return;
}
l += tvb_get_guint8(tvb, offset + l + 1);
if (l < obj_length - 4) {
if (i < 4)
proto_item_append_text(ti, ", ");
else if (i == 4)
proto_item_append_text(ti, "...");
}
}
}
static void
dissect_rsvp_explicit_route(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class, int type)
{
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_item_set_text(ti, "EXPLICIT ROUTE: ");
dissect_rsvp_ero_rro_subobjects(ti, pinfo, rsvp_object_tree, tvb,
offset + 4, obj_length, rsvp_class);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_explicit_route_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_record_route(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class, int type)
{
proto_item_set_text(ti, "RECORD ROUTE: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
dissect_rsvp_ero_rro_subobjects(ti, pinfo, rsvp_object_tree, tvb,
offset + 4, obj_length, rsvp_class);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_record_route_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_exclude_route(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int obj_length,
int rsvp_class, int ctype)
{
proto_item_set_text(ti, "EXCLUDE ROUTE: ");
switch (ctype) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1, ctype);
dissect_rsvp_xro_subobjects(ti, pinfo, rsvp_object_tree, tvb,
offset + 4, obj_length,
rsvp_class);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1,
ctype, "Unknown (%u)",
ctype);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_exclude_route_data, tvb, offset + 4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_message_id(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_flags, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_epoch, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_message_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "MESSAGE-ID: %d %s",
tvb_get_ntohl(tvb, offset+8),
tvb_get_guint8(tvb, offset+4) & 1 ? "(Ack Desired)" : "");
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_message_id_ack(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_flags, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_epoch, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_message_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "MESSAGE-ID ACK: %d", tvb_get_ntohl(tvb, offset+8));
break;
case 2:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_flags, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_epoch, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_message_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "MESSAGE-ID NACK: %d", tvb_get_ntohl(tvb, offset+8));
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_ack_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_message_id_list(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen;
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_list_flags, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_list_epoch, tvb, offset+5, 3, ENC_BIG_ENDIAN);
for (mylen = 8; mylen < obj_length; mylen += 4)
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_list_message_id, tvb, offset+mylen, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "MESSAGE-ID LIST: %d IDs",
(obj_length - 8)/4);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_message_id_list_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_hello(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length _U_,
int rsvp_class _U_, int type)
{
switch(type) {
case 1:
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
tvb_get_guint8 (tvb, offset+3),"%d - HELLO %s object",
tvb_get_guint8 (tvb, offset+3),
type==1 ? "REQUEST" : "ACK");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hello_source_instance, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_hello_destination_instance, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": %s. Src Instance: 0x%0x. Dest Instance: 0x%0x. ",
type==1 ? "REQUEST" : "ACK",
tvb_get_ntohl(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8));
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "%d - UNKNOWN", type);
break;
};
}
static void
dissect_rsvp_dclass(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen;
proto_item_set_text(ti, "DCLASS: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
for (mylen = 4; mylen < obj_length; mylen += 4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_dclass_dscp, tvb, offset+mylen+3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%d%s",
tvb_get_guint8(tvb, offset+mylen+3)>>2,
mylen==obj_length-4 ? "":
mylen<16 ? ", ":
mylen==16 ? ", ..." : "");
}
break;
default:
mylen = obj_length - 4;
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_dclass_data, tvb, offset2, mylen, ENC_NA);
break;
}
}
static void
dissect_rsvp_admin_status(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
guint32 status;
static const int * status_flags[] = {
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_REFLECT],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_HANDOVER],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_LOCKOUT],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_INHIBIT],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_CALL_MGMT],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_TESTING],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_DOWN],
&hf_rsvp_filter[RSVPF_ADMIN_STATUS_DELETE],
NULL
};
proto_item_set_text(ti, "ADMIN STATUS: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
status = tvb_get_ntohl(tvb, offset2);
proto_tree_add_bitmask(rsvp_object_tree, tvb, offset2, hf_rsvp_admin_status_bits, TREE(TT_ADMIN_STATUS_FLAGS), status_flags, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "ADMIN-STATUS: %s%s%s%s%s%s%s%s",
(status & (1U<<31)) ? "Reflect " : "",
(status & (1U<<6)) ? "Handover " : "",
(status & (1U<<5)) ? "Lockout " : "",
(status & (1U<<4)) ? "Inhibit " : "",
(status & (1U<<3)) ? "Call " : "",
(status & (1U<<2)) ? "Testing " : "",
(status & (1U<<1)) ? "Admin-Down " : "",
(status & (1U<<0)) ? "Deleting " : "");
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_admin_status_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_lsp_attributes(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int obj_length,
int rsvp_class _U_, int type)
{
int tlv_off;
guint32 attributes;
guint16 tlv_type, tlv_len;
proto_tree *ti2, *rsvp_lsp_attr_subtree;
static const int * rsvp_lsp_attr_flags[] = {
&hf_rsvp_lsp_attr_e2e,
&hf_rsvp_lsp_attr_boundary,
&hf_rsvp_lsp_attr_segment,
&hf_rsvp_lsp_attr_integrity,
&hf_rsvp_lsp_attr_contiguous,
&hf_rsvp_lsp_attr_stitching,
&hf_rsvp_lsp_attr_preplanned,
&hf_rsvp_lsp_attr_nophp,
&hf_rsvp_lsp_attr_oobmap,
&hf_rsvp_lsp_attr_entropy,
&hf_rsvp_lsp_attr_srlgcollect,
&hf_rsvp_lsp_attr_costcollect,
&hf_rsvp_lsp_attr_latcollect,
&hf_rsvp_lsp_attr_latvarcollect,
NULL
};
if (rsvp_class == RSVP_CLASS_LSP_REQUIRED_ATTRIBUTES)
proto_item_set_text(ti, "LSP REQUIRED ATTRIBUTES: ");
else
proto_item_set_text(ti, "LSP ATTRIBUTES: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
for (tlv_off = 4; tlv_off < obj_length-4; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || (tlv_off+tlv_len > obj_length)) {
proto_tree_add_expert(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, offset+tlv_off+2, 2);
return;
}
switch(tlv_type) {
case 1:
attributes = tvb_get_ntohl(tvb, offset+tlv_off+4);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_attributes_tlv, tvb, offset+tlv_off, 4, ENC_BIG_ENDIAN);
rsvp_lsp_attr_subtree = proto_item_add_subtree(ti2, TREE(TT_LSP_ATTRIBUTES_FLAGS));
proto_tree_add_bitmask(rsvp_lsp_attr_subtree, tvb, offset+tlv_off+4, hf_rsvp_lsp_attr, ett_treelist[TT_RSVP_LSP_ATTR], rsvp_lsp_attr_flags, ENC_NA);
proto_item_append_text(ti, "LSP Attribute:%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
(attributes & 0x80000000) ? " End-to-end re-routing" : "",
(attributes & 0x40000000) ? " Boundary re-routing" : "",
(attributes & 0x20000000) ? " Segment-based re-routing" : "",
(attributes & 0x10000000) ? " LSP Integrity Required" : "",
(attributes & 0x08000000) ? " Contiguous LSP" : "",
(attributes & 0x04000000) ? " LSP stitching desired" : "",
(attributes & 0x02000000) ? " Pre-Planned LSP Flag" : "",
(attributes & 0x01000000) ? " Non-PHP behavior flag" : "",
(attributes & 0x00800000) ? " OOB mapping flag" : "",
(attributes & 0x00400000) ? " Entropy Label Capability" : "",
(attributes & 0x00200000) ? " SRLG Collection Flag" : "",
(attributes & 0x00100000) ? " Cost Collection Flag" : "",
(attributes & 0x00080000) ? " Latency Collection Flag" : "",
(attributes & 0x00040000) ? " Latency Variation Flag" : "");
break;
default:
proto_tree_add_uint_format(rsvp_object_tree, hf_rsvp_type, tvb, offset+tlv_off, tlv_len,
tlv_type, "Unknown TLV: %d", tlv_type);
break;
}
tlv_off += tlv_len;
}
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_attributes_tlv_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_association(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
guint16 association_type;
guint16 association_id;
proto_item_set_text(ti, "ASSOCIATION ");
association_type = tvb_get_ntohs (tvb, offset + 4);
association_id = tvb_get_ntohs (tvb, offset + 6);
switch(type) {
case 1:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 (IPv4)");
proto_item_append_text(ti, "(IPv4): ");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_type, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s. ",
val_to_str(association_type, association_type_vals, "Unknown (%u)"));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_id, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "ID: %u. ", association_id);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_source_ipv4, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Src: %s", tvb_ip_to_str(tvb, offset+8));
break;
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 (IPv6)");
proto_item_append_text(ti, "(IPv6): ");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_type, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s. ",
val_to_str(association_type, association_type_vals, "Unknown (%u)"));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_id, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "ID: %u. ", association_id);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_source_ipv6, tvb, offset+8, 16, ENC_NA);
proto_item_append_text(ti, "Src: %s", tvb_ip6_to_str(tvb, offset+8));
break;
case 4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 (Routing Area)");
proto_item_append_text(ti, "(Routing Area): ");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_type, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s. ",
val_to_str(association_type, association_type_vals, "Unknown (%u)"));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_id, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Association ID: %u, ", association_id);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_routing_area_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Routing Area ID: %u, ", tvb_get_ntohl (tvb, offset+8));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_node_id, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Node ID: %s", tvb_ip_to_str(tvb, offset+12));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_padding, tvb, offset+8, 16, ENC_NA);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_association_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_lsp_tunnel_if_id_tlv(proto_tree *rsvp_object_tree, packet_info* pinfo,
tvbuff_t *tvb, int offset, int tlv_length,
int subtree_type)
{
int tlv_off;
guint16 tlv_type;
int tlv_len;
proto_tree *ti, *rsvp_lsp_tunnel_if_id_subtree;
for (tlv_off = 0; tlv_off < tlv_length; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || ((tlv_off+tlv_len) > tlv_length)) {
proto_tree_add_expert(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, offset+tlv_off+2, 2);
return;
}
switch(tlv_type) {
case 1:
rsvp_lsp_tunnel_if_id_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len, subtree_type, NULL,
"Unnumbered component link identifier: %u",
tvb_get_ntohl(tvb, offset+tlv_off+4));
proto_tree_add_uint_format_value(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "1 (Unnumbered component link identifier)");
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_component_link_identifier, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
break;
case 2:
rsvp_lsp_tunnel_if_id_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len, subtree_type, NULL,
"IPv4 component link identifier: %s",
tvb_ip_to_str(tvb, offset+tlv_off+4));
proto_tree_add_uint_format_value(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "2 (IPv4 component link identifier)");
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_component_link_identifier_ipv4, tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
break;
case 32769:
rsvp_lsp_tunnel_if_id_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len, subtree_type, &ti,
"Targeted client layer: ");
proto_tree_add_uint_format_value(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "32769 (Targeted client layer)");
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_length, tvb, offset+tlv_off+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_lsp_encoding_type, tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_switching_type, tvb, offset+tlv_off+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_signal_type, tvb, offset+tlv_off+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_connection_id, tvb, offset+tlv_off+8, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_sc_pc_id, tvb, offset+tlv_off+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_tunnel_if_id_subtree, hf_rsvp_lsp_tunnel_if_id_sc_pc_scn_address, tvb, offset+tlv_off+20, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "LSP Encoding=%s, Switching Type=%s, Signal Type=%s",
rval_to_str(tvb_get_guint8(tvb,offset+tlv_off+4),
gmpls_lsp_enc_rvals, "Unknown (%d)"),
rval_to_str(tvb_get_guint8(tvb,offset+tlv_off+5),
gmpls_switching_type_rvals, "Unknown (%d)"),
val_to_str_ext(tvb_get_guint8(tvb,offset+tlv_off+6),
&gmpls_sonet_signal_type_str_ext, "Unknown (%d)"));
break;
default:
proto_tree_add_uint_format(rsvp_object_tree, hf_rsvp_type, tvb, offset+tlv_off, 2,
tlv_type, "Unknown TLV: %u", tlv_type);
break;
}
tlv_off += tlv_len;
}
}
static void
dissect_rsvp_lsp_tunnel_if_id(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
proto_item_set_text(ti, "LSP INTERFACE-ID: ");
switch(type) {
case 1:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - Unnumbered interface");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_router_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_interface_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LSP INTERFACE-ID: Unnumbered, Router-ID %s, Interface-ID %d",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8));
break;
case 2:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv4");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_ipv4_interface_address, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_target_igp_instance, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LSP INTERFACE-ID: IPv4, interface address %s,"
"IGP instance %s",
tvb_ip_to_str(tvb, offset+4),
tvb_ip_to_str(tvb, offset+8));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_action, tvb, offset+12, 1, ENC_BIG_ENDIAN);
dissect_rsvp_lsp_tunnel_if_id_tlv(rsvp_object_tree, pinfo, tvb, offset+16, obj_length-16,
TREE(TT_LSP_TUNNEL_IF_ID_SUBTREE));
break;
case 3:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "3 - IPv6");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_ipv6_interface_address, tvb, offset+4, 16, ENC_NA);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_target_igp_instance, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LSP INTERFACE-ID: IPv6, interface address %s,"
"IGP instance %s",
tvb_ip6_to_str(tvb, offset+4),
tvb_ip_to_str(tvb, offset+20));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_action, tvb, offset+24, 1, ENC_BIG_ENDIAN);
dissect_rsvp_lsp_tunnel_if_id_tlv(rsvp_object_tree, pinfo, tvb, offset+28, obj_length-28,
TREE(TT_LSP_TUNNEL_IF_ID_SUBTREE));
break;
case 4:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "4 - Unnumbered interface with target");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_router_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_interface_id, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_target_igp_instance, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "LSP INTERFACE-ID: Unnumbered with target, Router-ID %s,"
" Interface-ID %d, IGP instance %s",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8),
tvb_ip_to_str(tvb, offset+12));
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_action, tvb, offset+16, 1, ENC_BIG_ENDIAN);
dissect_rsvp_lsp_tunnel_if_id_tlv(rsvp_object_tree, pinfo, tvb, offset+20, obj_length-20,
TREE(TT_LSP_TUNNEL_IF_ID_SUBTREE));
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_lsp_tunnel_if_id_data, tvb, offset+4, obj_length-4, ENC_NA);
break;
}
}
static void
dissect_rsvp_notify_request(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "1 - IPv4");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_notify_request_notify_node_address_ipv4, tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": Notify node: %s",
tvb_ip_to_str(tvb, offset2));
break;
}
case 2: {
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "2 - IPv6");
proto_tree_add_item(rsvp_object_tree, hf_rsvp_notify_request_notify_node_address_ipv6, tvb, offset2, 16, ENC_NA);
proto_item_append_text(ti, ": Notify node: %s",
tvb_ip6_to_str(tvb, offset2));
break;
}
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_notify_request_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_gen_uni(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type,
rsvp_conversation_info *rsvph)
{
int offset2 = offset + 4;
int mylen, i, j, k, l;
proto_item *ti2= NULL, *len_item;
proto_tree *rsvp_gen_uni_subtree, *rsvp_session_subtree, *rsvp_template_subtree;
int s_len, s_class, s_type, sobj_len, nsap_len;
int offset3;
proto_item_set_text(ti, "GENERALIZED UNI: ");
mylen = obj_length - 4;
switch(type) {
case 1: {
const char *c;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
for (i=1, l = 0; l < mylen; i++) {
sobj_len = tvb_get_ntohs(tvb, offset2+l);
j = tvb_get_guint8(tvb, offset2+l+2);
switch(j) {
case 1:
case 2:
c = (j==1) ? "Source" : "Destination";
k = tvb_get_guint8(tvb, offset2+l+3);
switch(k) {
case 1:
rsvp_gen_uni_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset2+l, 8, TREE(TT_GEN_UNI_SUBOBJ), NULL,
"%s IPv4 TNA: %s", c,
tvb_ip_to_str(tvb, offset2+l+4));
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (%s)", j, c);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1,
k, "1 (IPv4)");
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
if (j==1)
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_filter[RSVPF_GUNI_SRC_IPV4],
tvb, offset2+l+4, 4, ENC_BIG_ENDIAN);
else
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_filter[RSVPF_GUNI_DST_IPV4],
tvb, offset2+l+4, 4, ENC_BIG_ENDIAN);
if (i < 4) {
proto_item_append_text(ti, "%s IPv4 TNA: %s", c,
tvb_ip_to_str(tvb, offset2+l+4));
}
break;
case 2:
rsvp_gen_uni_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset2+l, 20, TREE(TT_GEN_UNI_SUBOBJ), NULL,
"%s IPv6 TNA:", c);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (%s)", j, c);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1,
k, "2 (IPv6)");
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
if (j==1)
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_filter[RSVPF_GUNI_SRC_IPV6],
tvb, offset2+l+4, 16, ENC_NA);
else
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_filter[RSVPF_GUNI_DST_IPV6],
tvb, offset2+l+4, 16, ENC_NA);
if (i < 4) {
proto_item_append_text(ti, "%s IPv6 TNA: %s", c,
tvb_ip6_to_str(tvb, offset2+l+4));
}
break;
case 3:
rsvp_gen_uni_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset2+l, tvb_get_ntohs(tvb, offset2+l),
TREE(TT_GEN_UNI_SUBOBJ), NULL, "%s NSAP TNA: ", c);
nsap_len = tvb_get_guint8(tvb, offset2+l+4);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (%s)", j, c);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1,
k, "3 (NSAP)");
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_nsap_length, tvb, offset2+l+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_string(rsvp_gen_uni_subtree, hf_rsvp_nsap_address, tvb, offset2+l+5, sobj_len-4,
print_nsap_net(tvb, offset2+l+5, nsap_len));
if (i < 4) {
proto_item_append_text(ti, "%s NSAP TNA: %s", c,
print_nsap_net(tvb, offset2+l+5, nsap_len));
}
break;
default:
rsvp_gen_uni_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset2+l, tvb_get_ntohs(tvb, offset2+l),
TREE(TT_GEN_UNI_SUBOBJ), NULL, "%s UNKNOWN TNA", c);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (%s)", j, c);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1,
k, "%d (UNKNOWN)", k);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_gen_uni_data, tvb, offset2+l+4, sobj_len-4, ENC_NA);
if (i < 4) {
proto_item_append_text(ti, "%s UNKNOWN", c);
}
break;
}
break;
case 3:
k = tvb_get_guint8(tvb, offset2+l+3);
switch(k) {
default:
case 1:
rsvp_gen_uni_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset2+l, tvb_get_ntohs(tvb, offset2+l),
TREE(TT_GEN_UNI_SUBOBJ), &ti2, "Diversity Subobject");
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (Diversity)", j);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1, k);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_class_diversity, tvb, offset2+l+4, 1, ENC_NA);
s_len = tvb_get_ntohs(tvb, offset2+l+8);
s_class = tvb_get_guint8(tvb, offset2+l+10);
s_type = tvb_get_guint8(tvb, offset2+l+11);
rsvp_session_subtree = proto_tree_add_subtree(rsvp_gen_uni_subtree, tvb, offset2+l+8,
s_len, TREE(rsvp_class_to_tree_type(s_class)), &ti2, "Session");
len_item = proto_tree_add_uint(rsvp_session_subtree, hf_rsvp_length, tvb, offset2+l+8, 2, s_len);
if (s_len < 4) {
expert_add_info_format(pinfo, len_item, &ei_rsvp_invalid_length,
"Length: %u (bogus, must be >= 4)", s_len);
break;
}
proto_tree_add_uint(rsvp_session_subtree, hf_rsvp_filter[RSVPF_OBJECT], tvb,
offset2+8+l+10, 1, s_class);
dissect_rsvp_session(ti2, rsvp_session_subtree, tvb, offset2+l+8,
s_len, s_class, s_type, rsvph);
offset3 = offset2 + s_len;
s_len = tvb_get_ntohs(tvb, offset3+l+8);
s_class = tvb_get_guint8(tvb, offset3+l+10);
s_type = tvb_get_guint8(tvb, offset3+l+11);
rsvp_template_subtree = proto_tree_add_subtree(rsvp_gen_uni_subtree, tvb, offset3+l+8,
s_len, TREE(rsvp_class_to_tree_type(s_class)), &ti2, "Template");
proto_tree_add_uint(rsvp_template_subtree, hf_rsvp_length, tvb, offset3+l+8, 2, s_len);
if (s_len < 4) {
expert_add_info_format(pinfo, len_item, &ei_rsvp_invalid_length,
"Length: %u (bogus, must be >= 4)", s_len);
break;
}
proto_tree_add_uint(rsvp_template_subtree, hf_rsvp_filter[RSVPF_OBJECT], tvb,
offset3+8+l+10, 1, s_class);
dissect_rsvp_template_filter(ti2, rsvp_template_subtree, tvb, offset3+l+8,
s_len, s_class, s_type, rsvph);
if (i < 4) {
proto_item_append_text(ti, "Diversity");
}
break;
}
break;
case 4:
k = tvb_get_guint8(tvb, offset2+l+3);
if (k == 1)
rsvp_gen_uni_subtree = proto_tree_add_subtree(rsvp_object_tree, tvb,
offset2+l, sobj_len, TREE(TT_GEN_UNI_SUBOBJ), &ti2,
"Egress Label Subobject");
else if (k == 2)
rsvp_gen_uni_subtree = proto_tree_add_subtree(rsvp_object_tree, tvb,
offset2+l, sobj_len, TREE(TT_GEN_UNI_SUBOBJ), &ti2,
"SPC Label Subobject");
else
rsvp_gen_uni_subtree = proto_tree_add_subtree(rsvp_object_tree, tvb,
offset2+l, sobj_len, TREE(TT_GEN_UNI_SUBOBJ), &ti2,
"Unknown Label Subobject");
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (Egress/SPC Label)", j);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1, k);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_gen_uni_direction,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_egress_label_type, tvb, offset2+l+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_gen_uni_logical_port_id, tvb, offset2+l+8, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti2, ": %s, Label type %d, Port ID %d, Label ",
tvb_get_guint8(tvb, offset2+l+4) & 0x80 ?
"Upstream" : "Downstream",
tvb_get_guint8(tvb, offset2+l+7),
tvb_get_ntohl(tvb, offset2+l+8));
for (j=12; j < sobj_len; j+=4) {
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_egress_label, tvb, offset2+l+j, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti2, "%u ", tvb_get_ntohl(tvb, offset2+l+j));
}
if (i < 4) {
if (k == 1)
proto_item_append_text(ti, "Egress Label");
else if (k == 2)
proto_item_append_text(ti, "SPC Label");
}
break;
case 5:
k = tvb_get_guint8(tvb, offset2+l+3);
switch(k) {
default:
case 1:
rsvp_gen_uni_subtree = proto_tree_add_subtree(rsvp_object_tree, tvb,
offset2+l, sobj_len, TREE(TT_GEN_UNI_SUBOBJ), &ti2,
"Service Level Subobject");
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_class, tvb, offset2+l+2, 1,
j, "%d (Service Level)", j);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l+3, 1, k);
proto_tree_add_uint(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l, 2, sobj_len);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_gen_uni_service_level, tvb, offset2+l+4, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti2, ": %u", tvb_get_guint8(tvb, offset2+l+4));
if (i < 4) {
proto_item_append_text(ti, "Service Level %d", tvb_get_guint8(tvb, offset2+l+4));
}
break;
}
break;
default:
rsvp_gen_uni_subtree = proto_tree_add_subtree_format(rsvp_object_tree, tvb,
offset2+l, sobj_len, TREE(TT_GEN_UNI_SUBOBJ), NULL,
"Unknown subobject: %u",
j);
proto_tree_add_uint_format_value(rsvp_gen_uni_subtree, hf_rsvp_type, tvb, offset2+l, 1,
j, "%u (Unknown)", j);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_class_length, tvb, offset2+l+1, 1, ENC_BIG_ENDIAN);
break;
}
if (tvb_get_guint8(tvb, offset2+l+1) < 1) {
proto_tree_add_expert_format(rsvp_gen_uni_subtree, pinfo, &ei_rsvp_invalid_length, tvb, offset2+l+1, 1,
"Invalid length: %u", tvb_get_guint8(tvb, offset2+l+1));
return;
}
l += tvb_get_guint8(tvb, offset2+l+1);
if (l < mylen) {
if (i < 4)
proto_item_append_text(ti, ", ");
else if (i==4)
proto_item_append_text(ti, "...");
}
}
break;
}
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_gen_uni_data, tvb, offset2, mylen, ENC_NA);
break;
}
}
static void
dissect_rsvp_call_id(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int c_type)
{
int type = 0;
const guint8 *str;
int offset2 = offset + 4;
int offset3, offset4, len;
proto_tree *ti2 = NULL;
proto_item_set_text(ti, "CALL-ID: ");
switch(c_type) {
case 0:
proto_item_append_text(ti,"Empty");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
c_type, "Empty (%u)", c_type);
if (obj_length > 4)
proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_id_data, tvb, offset2, obj_length-4, ENC_NA);
break;
case 1:
case 2:
type = tvb_get_guint8 (tvb, offset2);
if (c_type == 1) {
offset3 = offset2 + 4;
len = obj_length - 16;
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
c_type, "1 (operator specific)");
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_id_address_type, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_id_reserved, tvb, offset2+1, 3, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "Operator-Specific. Addr Type: %s. ",
val_to_str(type, address_type_vals, "Unknown (%u)"));
}
else {
offset3 = offset2 + 16;
len = obj_length - 28;
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
c_type, "2 (globally unique)");
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_id_address_type, tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_string(rsvp_object_tree, hf_rsvp_call_id_international_segment, tvb, offset2 + 1, 3, ENC_NA|ENC_ASCII, wmem_packet_scope(), &str);
proto_item_append_text(ti, "Globally-Unique. Addr Type: %s. Intl Segment: %s. ",
val_to_str(type, address_type_vals, "Unknown (%u)"), str);
proto_tree_add_item_ret_string(rsvp_object_tree, hf_rsvp_call_id_national_segment, tvb, offset2 + 4, 12, ENC_NA|ENC_ASCII, wmem_packet_scope(), &str);
proto_item_append_text(ti, "Natl Segment: %s. ", str);
}
switch(type) {
case 1:
offset4 = offset3 + 4;
str = tvb_ip_to_str(tvb, offset3);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_filter[RSVPF_CALL_ID_SRC_ADDR_IPV4],
tvb, offset3, 4, ENC_BIG_ENDIAN);
break;
case 2:
offset4 = offset3 + 16;
str = tvb_ip6_to_str(tvb, offset3);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_filter[RSVPF_CALL_ID_SRC_ADDR_IPV6],
tvb, offset3, 16, ENC_NA);
break;
case 3:
offset4 = offset3 + 20;
str = print_nsap_net(tvb, offset3, 20);
proto_tree_add_string(rsvp_object_tree, hf_rsvp_source_transport_network_addr, tvb, offset3, 20, str);
break;
case 4:
offset4 = offset3 + 6;
str = tvb_ether_to_str(tvb, offset3);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_callid_srcaddr_ether, tvb, offset3, 6, ENC_NA);
break;
case 0x7F:
offset4 = offset3 + len;
str = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset3, len);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_callid_srcaddr_bytes, tvb, offset3, len, ENC_NA);
break;
default:
offset4 = offset3 + len;
str = "???";
expert_add_info(pinfo, ti2, &ei_rsvp_call_id_address_type);
break;
}
proto_item_append_text(ti, "Src: %s. ", str);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_id_local_identifier, tvb, offset4, 8, ENC_NA);
proto_item_append_text(ti, "Local ID: %s. ", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset4, 8));
break;
default:
proto_item_append_text(ti, " Unknown");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
c_type, "Unknown (%u)", c_type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_id_data, tvb, offset2, obj_length-4, ENC_NA);
break;
}
}
static void
dissect_rsvp_3gpp_object(proto_tree *ti _U_, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int c_type)
{
guint16 length, ie_type;
offset+=3;
proto_tree_add_item(rsvp_object_tree, hf_rsvp_ctype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
obj_length = obj_length - 4;
if(c_type==1){
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
obj_length = obj_length - 4;
while(obj_length>0){
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_ie_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ie_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_ie_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if ((ie_type == 0)||(ie_type==2)){
guint8 tft_opcode, tft_n_pkt_flt;
int i;
if(ie_type == 0){
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_ue_ipv4_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}else{
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_ue_ipv6_addr, tvb, offset, 16, ENC_NA);
offset+=16;
}
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_d, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_ns, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_sr_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_p, tvb, offset, 4, ENC_BIG_ENDIAN);
tft_opcode = tvb_get_guint8(tvb, offset+2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_opcode, tvb, offset, 4, ENC_BIG_ENDIAN);
tft_n_pkt_flt = tvb_get_guint8(tvb, offset+3);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_n_pkt_flt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if((tft_opcode!=0x81)&&(tft_n_pkt_flt != 0)){
for (i = 0; i < tft_n_pkt_flt; i++) {
proto_tree *flow_tree, *t2_tree;
guint16 pkt_flt_len, item_len, pf_cont_len;
guint8 pf_comp_type_id;
flow_tree = proto_tree_add_subtree_format(rsvp_object_tree, tvb, offset, -1, ett_treelist[TT_3GPP_OBJ_FLOW], &ti, "Flow Identifier Num %u",i+1);
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_flow_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
item_len = 1;
if((tft_opcode==0x05)||(tft_opcode==0x82)){
proto_item_set_len(ti, item_len);
continue;
}
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ev_prec, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pkt_flt_len = tvb_get_ntohs(tvb,offset);
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_len, tvb, offset, 2, ENC_BIG_ENDIAN);
item_len = item_len + pkt_flt_len +1;
offset+=2;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_cont_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_comp_type_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_comp_type_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(pf_comp_type_id){
case 16:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_src_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ipv4_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
pf_cont_len-=11;
break;
case 17:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_dst_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ipv4_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
pf_cont_len-=11;
break;
case 32:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_src_ipv6, tvb, offset, 16, ENC_NA);
offset+=16;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
break;
case 33:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_dst_ipv6, tvb, offset, 16, ENC_NA);
offset+=16;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
break;
case 48:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_prot_next, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=4;
break;
case 64:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
pf_cont_len-=5;
break;
case 65:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_3gpp_obj_pf_dst_port_range, tvb, offset, 4,
tvb_get_ntohs(tvb,offset), "%u-%u", tvb_get_ntohs(tvb,offset), tvb_get_ntohs(tvb,offset+2));
offset+=4;
break;
case 80:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_src_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
pf_cont_len-=5;
break;
case 81:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_3gpp_obj_pf_src_port_range, tvb, offset, 4,
tvb_get_ntohs(tvb,offset), "Source Port range %u-%u", tvb_get_ntohs(tvb,offset), tvb_get_ntohs(tvb,offset+2));
offset+=4;
pf_cont_len-=7;
break;
case 96:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ipsec_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
pf_cont_len-=7;
break;
case 112:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_tos_tc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=4;
break;
case 128:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_flow_lbl, tvb, offset, 3, ENC_BIG_ENDIAN);
offset+=3;
pf_cont_len-=6;
break;
case 129:
t2_tree = proto_tree_add_subtree(flow_tree, tvb, offset, 17, ett_treelist[TT_3GPP_OBJ_T2], NULL, "Type 2 Routing Header packet filter");
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6, tvb, offset, 16, ENC_NA);
offset+=16;
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
break;
case 130:
t2_tree = proto_tree_add_subtree(flow_tree, tvb, offset, 17, ett_treelist[TT_3GPP_OBJ_HO], NULL, "Home address Option packet filter");
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6, tvb, offset, 16, ENC_NA);
offset+=16;
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
break;
default:
proto_tree_add_expert(flow_tree, pinfo, &ei_rsvp_packet_filter_component, tvb, offset, pf_cont_len-2);
offset = offset + pkt_flt_len - 5;
pf_cont_len=0;
break;
}
if(pf_cont_len != 0){
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_treatment, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_hint, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
proto_item_set_len(ti, item_len);
}
}
if((tft_opcode == 0x01)||(tft_opcode == 0x06)||(tft_opcode == 0x80)||(tft_opcode == 0x81)||(tft_opcode == 0x83)){
gint32 tft_qos_list_len;
guint8 blob_len, item_len, padding_len;
gboolean verbose;
proto_tree *qos_tree, *qos_sub_blob_tree, *qos_att_tree;
int num = 0, j, num_qos_att_set;
tft_qos_list_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_tft_qos_list_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
tft_qos_list_len-=2;
if(tft_qos_list_len > 0){
while (tft_qos_list_len>0) {
int bit_offset;
guint8 qos_attribute_set_len;
num++;
qos_tree = proto_tree_add_subtree_format(rsvp_object_tree, tvb, offset, -1,
ett_treelist[TT_3GPP_OBJ_QOS], NULL, "QOS Flow Identifier Num %u", num);
proto_tree_add_item(qos_tree, hf_rsvp_3gpp_obj_flow_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tft_qos_list_len--;
blob_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(qos_tree, hf_rsvp_3gpp_r_qos_blob_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tft_qos_list_len--;
ti = proto_tree_add_item(qos_tree, hf_rsvp_3gpp_r_qos_blob, tvb, offset, blob_len, ENC_NA);
qos_sub_blob_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_QOS_SUB_BLOB]);
proto_tree_add_item(qos_sub_blob_tree, hf_rsvp_3gpp_r_qos_blob_flow_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(qos_sub_blob_tree, hf_rsvp_3gpp_r_qos_blob_num_qos_att_set, tvb, offset, 1, ENC_BIG_ENDIAN);
num_qos_att_set = (tvb_get_guint8(tvb, offset) & 0x0e)>>1;
bit_offset = (offset<<3)+7;
for (j = 0; j < num_qos_att_set; j++) {
qos_attribute_set_len = tvb_get_bits8(tvb,bit_offset,4);
qos_att_tree = proto_tree_add_subtree_format(qos_sub_blob_tree, tvb, bit_offset>>3, qos_attribute_set_len, ett_treelist[TT_3GPP_OBJ_QOS_SUB_BLOB], NULL,
"QoS_ATTRIBUTE_SET %u(%u bytes)", j+1, qos_attribute_set_len);
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_att_set_len, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
if(qos_attribute_set_len==0){
break;
}
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_set_id, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset+=7;
verbose = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_verbose, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if(verbose == FALSE){
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_prof_id, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=16;
}else{
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_traff_cls, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset+=3;
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_peak_rate, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=16;
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_bucket_size, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=16;
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_token_rate, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=16;
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_max_latency, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=8;
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_max_loss_rte, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=8;
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_delay_var_sensitive, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset+=1;
}
padding_len = 0;
if((bit_offset & 0x07) != 0){
padding_len = 8 - (bit_offset & 0x07);
proto_tree_add_bits_item(qos_att_tree, hf_rsvp_3gpp_qos_attribute_reserved, tvb, bit_offset, padding_len, ENC_BIG_ENDIAN);
}
bit_offset = bit_offset + padding_len;
}
offset = offset + blob_len;
tft_qos_list_len = tft_qos_list_len - blob_len;
item_len = blob_len + 2;
if(tft_opcode == 0x81){
proto_tree_add_item(qos_tree, hf_rsvp_3gpp_qos_result, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tft_qos_list_len--;
item_len++;
}
proto_item_set_len(ti, item_len);
}
}
}else{
proto_tree_add_item(rsvp_object_tree, hf_rsvp_ie_data, tvb, offset, length-2, ENC_NA);
}
obj_length = obj_length - length;
}
}
}
}
static void
dissect_rsvp_restart_cap(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
guint restart, recovery;
proto_item_set_text(ti, "RESTART CAPABILITY: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item_ret_uint(rsvp_object_tree, hf_rsvp_restart_cap_restart_time, tvb, offset2, 4,
ENC_BIG_ENDIAN, &restart);
proto_tree_add_item_ret_uint(rsvp_object_tree, hf_rsvp_restart_cap_recovery_time, tvb, offset2+4, 4,
ENC_BIG_ENDIAN, &recovery);
proto_item_append_text(ti, "Restart Time: %d ms. Recovery Time: %d ms.",
restart, recovery);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_restart_cap_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_link_cap(proto_item *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class, int type)
{
proto_item_set_text(ti, "LINK CAPABILITY: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
dissect_rsvp_ero_rro_subobjects(ti, pinfo, rsvp_object_tree, tvb,
offset + 4, obj_length, rsvp_class);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_record_route_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_protection_info(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
guint8 flags1, lsp_flags, link_flags, seg_flags;
proto_tree *ti2, *rsvp_pi_link_flags_tree, *rsvp_pi_lsp_flags_tree, *rsvp_pi_seg_flags_tree;
int offset2 = offset + 4;
proto_item_set_text(ti, "PROTECTION_INFO: ");
switch(type) {
case 1:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
flags1 = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_protection_info_flags_secondary_lsp,
tvb, offset2, 1, ENC_BIG_ENDIAN);
link_flags = tvb_get_guint8(tvb, offset2+3);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_protection_info_link_flags, tvb, offset2+3, 1, ENC_BIG_ENDIAN);
rsvp_pi_link_flags_tree = proto_item_add_subtree(ti2, TREE(TT_PROTECTION_INFO_LINK));
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_extra_traffic,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_unprotected,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_shared,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_dedicated1_1,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_dedicated1plus1,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_enhanced,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s%s%s%s%s%s%s.",
flags1&0x80 ? "SecondaryLSP ":"",
link_flags&0x01 ? "ExtraTraffic ":"",
link_flags&0x02 ? "Unprotected ":"",
link_flags&0x04 ? "Shared ":"",
link_flags&0x08 ? "Dedicated1:1 ":"",
link_flags&0x10 ? "Dedicated1+1 ":"",
link_flags&0x20 ? "Enhanced ":"");
break;
case 2:
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
flags1 = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_rfc4872_secondary,
tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_rfc4872_protecting,
tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_rfc4872_notification_msg,
tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_rfc4872_operational,
tvb, offset2, 1, ENC_BIG_ENDIAN);
lsp_flags = tvb_get_guint8(tvb, offset2+1);
rsvp_pi_lsp_flags_tree = proto_tree_add_subtree_format(rsvp_object_tree, tvb, offset2+1, 1,
TREE(TT_PROTECTION_INFO_LSP), NULL, "LSP Flags: 0x%02x -%s%s%s%s%s%s", lsp_flags,
lsp_flags == 0 ? " Unprotected":"",
lsp_flags&0x01 ? " Rerouting":"",
lsp_flags&0x02 ? " Rerouting with extra-traffic":"",
lsp_flags&0x04 ? " 1:N Protection with extra-traffic":"",
lsp_flags&0x08 ? " 1+1 Unidirectional protection":"",
lsp_flags&0x10 ? " 1+1 Bidirectional protection":"");
proto_tree_add_item(rsvp_pi_lsp_flags_tree, hf_rsvp_pi_lsp_flags_full_rerouting,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_lsp_flags_tree, hf_rsvp_pi_lsp_flags_rerouting_extra,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_lsp_flags_tree, hf_rsvp_pi_lsp_flags_1_n_protection,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_lsp_flags_tree, hf_rsvp_pi_lsp_flags_1plus1_unidirectional,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_lsp_flags_tree, hf_rsvp_pi_lsp_flags_1plus1_bidirectional,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
link_flags = tvb_get_guint8(tvb, offset2+3);
rsvp_pi_link_flags_tree = proto_tree_add_subtree_format(rsvp_object_tree, tvb, offset2+3, 1,
TREE(TT_PROTECTION_INFO_LINK), NULL, "Link Flags: 0x%02x -%s%s%s%s%s%s", link_flags,
link_flags&0x01 ? " ExtraTraffic":"",
link_flags&0x02 ? " Unprotected":"",
link_flags&0x04 ? " Shared":"",
link_flags&0x08 ? " Dedicated1:1":"",
link_flags&0x10 ? " Dedicated1+1":"",
link_flags&0x20 ? " Enhanced":"");
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_extra,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_unprotected,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_shared,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_dedicated_1_1,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_dedicated_1plus1,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_link_flags_tree, hf_rsvp_pi_link_flags_enhanced,
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_protection_info_in_place,
tvb, offset2+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_protection_info_required,
tvb, offset2+4, 1, ENC_BIG_ENDIAN);
seg_flags = tvb_get_guint8(tvb, offset2+5);
rsvp_pi_seg_flags_tree = proto_tree_add_subtree_format(rsvp_object_tree, tvb, offset2+5, 1,
TREE(TT_PROTECTION_INFO_SEG), NULL, "Segment recovery Flags: 0x%02x - %s%s%s%s%s%s", seg_flags,
seg_flags == 0 ? " Unprotected":"",
seg_flags&0x01 ? " Rerouting":"",
seg_flags&0x02 ? " Rerouting with extra-traffic":"",
seg_flags&0x04 ? " 1:N Protection with extra-traffic":"",
seg_flags&0x08 ? " 1+1 Unidirectional protection":"",
seg_flags&0x10 ? " 1+1 Bidirectional protection":"");
proto_tree_add_item(rsvp_pi_seg_flags_tree, hf_rsvp_pi_seg_flags_full_rerouting,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_seg_flags_tree, hf_rsvp_pi_seg_flags_rerouting_extra,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_seg_flags_tree, hf_rsvp_pi_seg_flags_1_n_protection,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_seg_flags_tree, hf_rsvp_pi_seg_flags_1plus1_unidirectional,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_pi_seg_flags_tree, hf_rsvp_pi_seg_flags_1plus1_bidirectional,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s%s%s%s Link:%s%s%s%s%s%s, LSP:%s%s%s%s%s%s.",
flags1&0x80 ? "SecondaryLSP ":"",
flags1&0x40 ? "ProtectingLSP ":"",
flags1&0x20 ? "Notification ":"",
flags1&0x10 ? "OperationalLSP ":"",
link_flags&0x01 ? " ExtraTraffic":"",
link_flags&0x02 ? " Unprotected":"",
link_flags&0x04 ? " Shared":"",
link_flags&0x08 ? " Dedicated1:1":"",
link_flags&0x10 ? " Dedicated1+1":"",
link_flags&0x20 ? " Enhanced":"",
lsp_flags == 0 ? " Unprotected":"",
lsp_flags&0x01 ? " Rerouting":"",
lsp_flags&0x02 ? " Rerouting with extra-traffic":"",
lsp_flags&0x04 ? " 1:N Protection with extra-traffic":"",
lsp_flags&0x08 ? " 1+1 Unidirectional protection":"",
lsp_flags&0x10 ? " 1+1 Bidirectional protection":"");
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_protection_info_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_fast_reroute(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
guint8 flags;
proto_tree *ti2, *rsvp_frr_flags_tree;
proto_item_set_text(ti, "FAST_REROUTE: ");
switch(type) {
case 1:
case 7:
if (((type == 1) && (obj_length != 24)) || ((type == 7) && (obj_length != 20))) {
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, offset, obj_length,
"Invalid length: cannot decode");
proto_item_append_text(ti, "Invalid length");
break;
}
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_setup_priority, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_hold_priority, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_hop_limit, tvb, offset+6, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset+7);
ti2 = proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_flags, tvb, offset+7, 1, ENC_BIG_ENDIAN);
rsvp_frr_flags_tree = proto_item_add_subtree(ti2, TREE(TT_FAST_REROUTE_FLAGS));
proto_tree_add_item(rsvp_frr_flags_tree, hf_rsvp_frr_flags_one2one_backup,
tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_frr_flags_tree, hf_rsvp_frr_flags_facility_backup,
tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_bandwidth, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_include_any, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_exclude_any, tvb, offset+16, 4, ENC_BIG_ENDIAN);
if (type == 1) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_include_all, tvb, offset+20, 4, ENC_BIG_ENDIAN);
}
proto_item_append_text(ti, "%s%s",
flags &0x01 ? "One-to-One Backup, " : "",
flags &0x02 ? "Facility Backup" : "");
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_fast_reroute_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_detour(proto_tree *ti, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int remaining_length, count;
int iter;
proto_item_set_text(ti, "DETOUR: ");
switch(type) {
case 7:
iter = 0;
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
for (remaining_length = obj_length - 4, count = 1;
remaining_length > 0; remaining_length -= 8, count++) {
if (remaining_length < 8) {
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length, tvb, offset+remaining_length,
obj_length-remaining_length,
"Invalid length: cannot decode");
proto_item_append_text(ti, "Invalid length");
break;
}
iter++;
proto_tree_add_ipv4_format(rsvp_object_tree, hf_rsvp_detour_plr_id, tvb, offset+(4*iter), 4,
tvb_get_ntohl(tvb, offset+(4*iter)), "PLR ID %d: %s", count,
tvb_ip_to_str(tvb, offset+(4*iter)));
iter++;
proto_tree_add_ipv4_format(rsvp_object_tree, hf_rsvp_detour_avoid_node_id, tvb, offset+(4*iter), 4,
tvb_get_ntohl(tvb, offset+(4*iter)), "Avoid Node ID %d: %s", count,
tvb_ip_to_str(tvb, offset+(4*iter)));
}
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_detour_data, tvb, offset+4, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_diffserv(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int mapnb, count;
int *hfindexes[] = {
&hf_rsvp_filter[RSVPF_DIFFSERV_MAP],
&hf_rsvp_filter[RSVPF_DIFFSERV_MAP_EXP],
&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID],
&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_DSCP],
&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_CODE],
&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_BIT14],
&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_BIT15]
};
gint *etts[] = {
&TREE(TT_DIFFSERV_MAP),
&TREE(TT_DIFFSERV_MAP_PHBID)
};
proto_item_set_text(ti, "DIFFSERV: ");
offset += 3;
switch (type) {
case 1:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset, 1,
type, "1 - E-LSP");
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_filter[RSVPF_DIFFSERV_MAPNB],
tvb, offset + 4, 1,
mapnb = tvb_get_guint8(tvb, offset + 4) & 15);
proto_item_append_text(ti, "E-LSP, %u MAP%s", mapnb,
(mapnb == 0) ? "" : "s");
offset += 5;
for (count = 0; count < mapnb; count++) {
dissect_diffserv_mpls_common(tvb, rsvp_object_tree, type,
offset, hfindexes, etts);
offset += 4;
}
break;
case 2:
proto_item_append_text(ti, "L-LSP");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset, 1,
type, "2 - L-LSP");
dissect_diffserv_mpls_common(tvb, rsvp_object_tree, type,
offset + 3, hfindexes, etts);
break;
default:
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_diffserv_data, tvb, offset + 1, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_diffserv_aware_te(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
proto_item *hidden_item;
int offset2 = offset + 4;
guint8 ct = 0;
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_DSTE],
tvb, offset, 8, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
switch(type) {
case 1:
ct = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1, type);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_DSTE_CLASSTYPE],
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "CLASSTYPE: CT %u", ct);
break;
default:
proto_item_set_text(ti, "CLASSTYPE: (Unknown C-type)");
proto_tree_add_uint_format_value(rsvp_object_tree, hf_rsvp_ctype, tvb, offset+3, 1,
type, "Unknown (%u)", type);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_diffserv_aware_te_data, tvb, offset2, obj_length - 4, ENC_NA);
break;
}
}
static void
dissect_rsvp_vendor_private_use(proto_tree *ti _U_,
proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
proto_item *hidden_item;
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_PRIVATE_OBJ],
tvb, offset, obj_length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1, type);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_ENT_CODE],
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_private_data, tvb, offset + 8,
obj_length - 8, ENC_NA);
}
static void
dissect_rsvp_call_attributes(proto_tree *ti _U_, packet_info* pinfo, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int obj_length _U_, int rsvp_class _U_, int type _U_)
{
int offset2 = offset + 4;
guint16 tlv_type;
guint16 tlv_len;
tlv_type = tvb_get_ntohs(tvb, offset2);
tlv_len = tvb_get_ntohs(tvb, offset2+2);
if (tlv_len < 4){
proto_tree_add_expert_format(rsvp_object_tree, pinfo, &ei_rsvp_invalid_length,
tvb, offset2+2, 2, "Invalid TLV length");
return;
}
switch(tlv_type){
case 2:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_call_attributes_endpont_id, tvb, offset2 + 4, tlv_len - 4, ENC_NA|ENC_ASCII);
break;
}
}
static void
dissect_rsvp_juniper(proto_tree *ti _U_,
proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
proto_item *hidden_item;
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_JUNIPER],
tvb, offset, obj_length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1, type);
offset += 4;
if (type == 1) {
guint tlvs, pad;
tlvs = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_numtlvs, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
pad = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_padlength, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (tlvs > 0) {
guint8 t, l;
t = tvb_get_guint8(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
l = tvb_get_guint8(tvb, offset);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (t) {
case 0x01:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_attrib_cos, tvb,
offset, l-2, ENC_BIG_ENDIAN);
offset += (l-2);
break;
case 0x02:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_attrib_metric1, tvb,
offset, l-2, ENC_BIG_ENDIAN);
offset += (l-2);
break;
case 0x04:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_attrib_metric2, tvb,
offset, l-2, ENC_BIG_ENDIAN);
offset += (l-2);
break;
case 0x08:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_attrib_ccc_status, tvb,
offset, l-2, ENC_BIG_ENDIAN);
offset += (l-2);
break;
case 0x10:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_attrib_path, tvb,
offset, l-2, ENC_BIG_ENDIAN);
offset += (l-2);
break;
default:
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_attrib_unknown, tvb,
offset, l-2, ENC_NA);
offset += (l-2);
break;
}
tlvs--;
}
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_pad, tvb,
offset, pad, ENC_NA);
} else if (obj_length > 4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_juniper_unknown, tvb,
offset, obj_length, ENC_NA);
}
}
static void
dissect_rsvp_unknown(proto_tree *ti _U_,
proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_ctype, tvb, offset + 3, 1, type);
if (obj_length > 4) {
proto_tree_add_item(rsvp_object_tree, hf_rsvp_unknown_data, tvb, offset + 4,
obj_length - 4, ENC_NA);
}
}
static void
dissect_rsvp_msg_tree(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int tree_mode, rsvp_conversation_info *rsvph, gboolean e2ei)
{
proto_tree *rsvp_tree;
proto_tree *rsvp_header_tree;
proto_tree *rsvp_object_tree;
proto_tree *ti, *len_item;
proto_item *hidden_item, *cksum_item;
guint16 cksum, computed_cksum;
vec_t cksum_vec[1];
int offset = 0;
int len;
guint8 message_type;
int session_off, tempfilt_off;
int msg_length;
int obj_length;
gboolean have_integrity_object = FALSE;
offset = 0;
msg_length = tvb_get_ntohs(tvb, 6);
message_type = tvb_get_guint8(tvb, 1);
ti = proto_tree_add_item(tree, proto_rsvp, tvb, offset, msg_length,
ENC_NA);
rsvp_tree = proto_item_add_subtree(ti, tree_mode);
if (e2ei)
proto_item_append_text(rsvp_tree, " (E2E-IGNORE)");
proto_item_append_text(rsvp_tree, ": ");
proto_item_append_text(rsvp_tree, "%s", val_to_str_ext(message_type, &message_type_vals_ext,
"Unknown (%u). "));
find_rsvp_session_tempfilt(tvb, 0, &session_off, &tempfilt_off);
if (session_off)
proto_item_append_text(rsvp_tree, "%s", summary_session(tvb, session_off));
if (tempfilt_off)
proto_item_append_text(rsvp_tree, "%s", summary_template(tvb, tempfilt_off));
rsvp_header_tree = proto_tree_add_subtree_format(rsvp_tree, tvb, offset, 8,
TREE(TT_HDR), &ti, "RSVP Header. %s",
val_to_str_ext(message_type, &message_type_vals_ext,
"Unknown Message (%u). "));
if (e2ei)
proto_item_append_text(ti, " (E2E-IGNORE)");
proto_tree_add_item(rsvp_header_tree, hf_rsvp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_header_tree, hf_rsvp_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(rsvp_header_tree, hf_rsvp_filter[RSVPF_MSG], tvb,
offset+1, 1, message_type);
switch (RSVPF_MSG + message_type) {
case RSVPF_PATH:
case RSVPF_RESV:
case RSVPF_PATHERR:
case RSVPF_RESVERR:
case RSVPF_PATHTEAR:
case RSVPF_RESVTEAR:
case RSVPF_RCONFIRM:
case RSVPF_RTEARCONFIRM:
case RSVPF_BUNDLE:
case RSVPF_ACK:
case RSVPF_SREFRESH:
case RSVPF_HELLO:
case RSVPF_NOTIFY:
hidden_item = proto_tree_add_boolean(rsvp_header_tree, hf_rsvp_filter[RSVPF_MSG + message_type], tvb,
offset+1, 1, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
}
cksum = tvb_get_ntohs(tvb, offset+2);
cksum_item = proto_tree_add_item(rsvp_header_tree, hf_rsvp_message_checksum, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_header_tree, hf_rsvp_sending_ttl, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_header_tree, hf_rsvp_message_length, tvb, offset+6, 2, ENC_BIG_ENDIAN);
offset = 8;
len = 8;
if (message_type == RSVP_MSG_BUNDLE) {
if (rsvp_bundle_dissect) {
int len2 = 8;
while (len2 < msg_length) {
gint sub_len;
tvbuff_t *tvb_sub;
sub_len = tvb_get_ntohs(tvb, len2+6);
tvb_sub = tvb_new_subset_length(tvb, len2, sub_len);
dissect_rsvp_msg_tree(tvb_sub, pinfo, rsvp_tree, TREE(TT_BUNDLE_COMPMSG), rsvph, e2ei);
len2 += sub_len;
}
} else {
proto_tree_add_expert(rsvp_tree, pinfo, &ei_rsvp_bundle_component_msg, tvb, offset, msg_length - len);
}
return;
}
while (len < msg_length) {
guint8 rsvp_class;
guint8 type;
obj_length = tvb_get_ntohs(tvb, offset);
rsvp_class = tvb_get_guint8(tvb, offset+2);
type = tvb_get_guint8(tvb, offset+3);
ti = proto_tree_add_item(rsvp_tree, hf_rsvp_filter[rsvp_class_to_filter_num(rsvp_class)],
tvb, offset, obj_length, ENC_BIG_ENDIAN);
rsvp_object_tree = proto_item_add_subtree(ti, TREE(rsvp_class_to_tree_type(rsvp_class)));
len_item = proto_tree_add_item(rsvp_object_tree, hf_rsvp_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if (obj_length < 4) {
expert_add_info_format(pinfo, len_item, &ei_rsvp_invalid_length,
"Length: %u (bogus, must be >= 4)", obj_length);
break;
}
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_filter[RSVPF_OBJECT], tvb,
offset+2, 1, rsvp_class);
switch(rsvp_class) {
case RSVP_CLASS_SESSION:
dissect_rsvp_session(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type, rsvph);
break;
case RSVP_CLASS_HOP:
dissect_rsvp_hop(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_TIME_VALUES:
dissect_rsvp_time_values(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ERROR:
dissect_rsvp_error(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_SCOPE:
dissect_rsvp_scope(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_STYLE:
dissect_rsvp_style(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_CONFIRM:
dissect_rsvp_confirm(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_SENDER_TEMPLATE:
case RSVP_CLASS_FILTER_SPEC:
dissect_rsvp_template_filter(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type, rsvph);
break;
case RSVP_CLASS_SENDER_TSPEC:
dissect_rsvp_tspec(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_FLOWSPEC:
dissect_rsvp_flowspec(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ADSPEC:
dissect_rsvp_adspec(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_INTEGRITY:
have_integrity_object = TRUE;
dissect_rsvp_integrity(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_POLICY:
dissect_rsvp_policy(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_LABEL_REQUEST:
dissect_rsvp_label_request(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_RECOVERY_LABEL:
case RSVP_CLASS_UPSTREAM_LABEL:
case RSVP_CLASS_SUGGESTED_LABEL:
case RSVP_CLASS_LABEL:
dissect_rsvp_label(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_LABEL_SET:
dissect_rsvp_label_set(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_SESSION_ATTRIBUTE:
dissect_rsvp_session_attribute(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_EXPLICIT_ROUTE:
dissect_rsvp_explicit_route(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_RECORD_ROUTE:
dissect_rsvp_record_route(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_EXCLUDE_ROUTE:
dissect_rsvp_exclude_route(ti, pinfo, rsvp_object_tree, tvb, offset,
obj_length, rsvp_class, type);
break;
case RSVP_CLASS_MESSAGE_ID:
dissect_rsvp_message_id(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_MESSAGE_ID_ACK:
dissect_rsvp_message_id_ack(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_MESSAGE_ID_LIST:
dissect_rsvp_message_id_list(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_HELLO:
dissect_rsvp_hello(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_DCLASS:
dissect_rsvp_dclass(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ADMIN_STATUS:
dissect_rsvp_admin_status(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_LSP_ATTRIBUTES:
case RSVP_CLASS_LSP_REQUIRED_ATTRIBUTES:
dissect_rsvp_lsp_attributes(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ASSOCIATION:
dissect_rsvp_association(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_LSP_TUNNEL_IF_ID:
dissect_rsvp_lsp_tunnel_if_id(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_NOTIFY_REQUEST:
dissect_rsvp_notify_request(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_GENERALIZED_UNI:
dissect_rsvp_gen_uni(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type, rsvph);
break;
case RSVP_CLASS_CALL_ID:
dissect_rsvp_call_id(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_3GPP2_OBJECT:
dissect_rsvp_3gpp_object(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_RESTART_CAP:
dissect_rsvp_restart_cap(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_LINK_CAP:
dissect_rsvp_link_cap(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_PROTECTION:
dissect_rsvp_protection_info(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_FAST_REROUTE:
dissect_rsvp_fast_reroute(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_DETOUR:
dissect_rsvp_detour(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_DIFFSERV:
dissect_rsvp_diffserv(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_CLASSTYPE:
dissect_rsvp_diffserv_aware_te(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_VENDOR_PRIVATE_1:
case RSVP_CLASS_VENDOR_PRIVATE_2:
case RSVP_CLASS_VENDOR_PRIVATE_3:
case RSVP_CLASS_VENDOR_PRIVATE_4:
case RSVP_CLASS_VENDOR_PRIVATE_5:
case RSVP_CLASS_VENDOR_PRIVATE_6:
case RSVP_CLASS_VENDOR_PRIVATE_7:
case RSVP_CLASS_VENDOR_PRIVATE_8:
case RSVP_CLASS_VENDOR_PRIVATE_9:
case RSVP_CLASS_VENDOR_PRIVATE_10:
case RSVP_CLASS_VENDOR_PRIVATE_11:
case RSVP_CLASS_VENDOR_PRIVATE_12:
dissect_rsvp_vendor_private_use(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_CALL_ATTRIBUTES:
dissect_rsvp_call_attributes(ti, pinfo, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_JUNIPER_PROPERTIES:
dissect_rsvp_juniper(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_NULL:
default:
dissect_rsvp_unknown(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
}
offset += obj_length;
len += obj_length;
}
if (!pinfo->fragmented && ((int) tvb_captured_length(tvb) >= msg_length)) {
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, msg_length);
computed_cksum = in_cksum(&cksum_vec[0], 1);
if (computed_cksum == 0) {
proto_item_append_text(cksum_item, " [correct]");
} else if (cksum == 0 && have_integrity_object) {
proto_item_append_text(cksum_item, " [ignored, integrity object used]");
} else {
proto_item_append_text(cksum_item, " [incorrect, should be 0x%04x]",
in_cksum_shouldbe(cksum, computed_cksum));
}
}
}
static void
dissect_rsvp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean e2ei)
{
guint8 message_type;
int session_off, tempfilt_off;
rsvp_conversation_info *rsvph;
conversation_t *conversation;
struct rsvp_request_key request_key, *new_request_key;
struct rsvp_request_val *request_val;
col_clear(pinfo->cinfo, COL_INFO);
message_type = tvb_get_guint8(tvb, 1);
rsvph = wmem_new0(wmem_packet_scope(), rsvp_conversation_info);
set_address(&rsvph->source, pinfo->src.type, pinfo->src.len, pinfo->src.data);
set_address(&rsvph->destination, pinfo->dst.type, pinfo->dst.len, pinfo->dst.data);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(message_type, &message_type_vals_ext, "Unknown (%u). "));
if (message_type == RSVP_MSG_BUNDLE) {
col_set_str(pinfo->cinfo, COL_INFO,
rsvp_bundle_dissect ?
"Component Messages Dissected" :
"Component Messages Not Dissected");
} else {
find_rsvp_session_tempfilt(tvb, 0, &session_off, &tempfilt_off);
if (session_off)
col_append_str(pinfo->cinfo, COL_INFO, summary_session(tvb, session_off));
if (tempfilt_off)
col_append_str(pinfo->cinfo, COL_INFO, summary_template(tvb, tempfilt_off));
}
dissect_rsvp_msg_tree(tvb, pinfo, tree, TREE(TT_RSVP), rsvph, e2ei);
if ((message_type == RSVP_MSG_ACK) ||
(message_type == RSVP_MSG_SREFRESH) ||
(message_type == RSVP_MSG_HELLO))
return;
conversation = find_or_create_conversation(pinfo);
memset(&request_key, 0, sizeof(request_key));
request_key.conversation = conversation->conv_index;
request_key.session_type = rsvph->session_type;
switch (request_key.session_type) {
case RSVP_SESSION_TYPE_IPV4:
set_address(&request_key.u.session_ipv4.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4.protocol = rsvph->protocol;
request_key.u.session_ipv4.udp_dest_port = rsvph->udp_dest_port;
break;
case RSVP_SESSION_TYPE_IPV6:
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
set_address(&request_key.u.session_ipv4_lsp.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4_lsp.udp_dest_port = rsvph->udp_dest_port;
request_key.u.session_ipv4_lsp.ext_tunnel_id = rsvph->ext_tunnel_id;
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
set_address(&request_key.u.session_agg_ipv4.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_agg_ipv4.dscp = rsvph->dscp;
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
set_address(&request_key.u.session_ipv4_uni.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4_uni.udp_dest_port = rsvph->udp_dest_port;
request_key.u.session_ipv4_uni.ext_tunnel_id = rsvph->ext_tunnel_id;
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
set_address(&request_key.u.session_ipv4_enni.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4_enni.udp_dest_port = rsvph->udp_dest_port;
request_key.u.session_ipv4_enni.ext_tunnel_id = rsvph->ext_tunnel_id;
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_rsvp_session_type, tvb, 0, 0);
break;
}
copy_address_shallow(&request_key.source_info.source, &rsvph->source);
request_key.source_info.udp_source_port = rsvph->udp_source_port;
request_val =
(struct rsvp_request_val *) wmem_map_lookup(rsvp_request_hash,
&request_key);
if (!request_val) {
new_request_key = (struct rsvp_request_key *)wmem_memdup(
wmem_file_scope(), &request_key, sizeof(struct rsvp_request_key));
switch (request_key.session_type) {
case RSVP_SESSION_TYPE_IPV4:
copy_address_wmem(wmem_file_scope(), &new_request_key->u.session_ipv4.destination,
&request_key.u.session_ipv4.destination);
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
copy_address_wmem(wmem_file_scope(), &new_request_key->u.session_ipv4_lsp.destination,
&request_key.u.session_ipv4_lsp.destination);
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
copy_address_wmem(wmem_file_scope(), &new_request_key->u.session_agg_ipv4.destination,
&request_key.u.session_agg_ipv4.destination);
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
copy_address_wmem(wmem_file_scope(), &new_request_key->u.session_ipv4_uni.destination,
&request_key.u.session_ipv4_uni.destination);
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
copy_address_wmem(wmem_file_scope(), &new_request_key->u.session_ipv4_enni.destination,
&request_key.u.session_ipv4_enni.destination);
break;
default:
break;
}
copy_address_wmem(wmem_file_scope(), &new_request_key->source_info.source, &rsvph->source);
request_val = wmem_new(wmem_file_scope(), struct rsvp_request_val);
request_val->value = conversation->conv_index;
wmem_map_insert(rsvp_request_hash, new_request_key, request_val);
}
tap_queue_packet(rsvp_tap, pinfo, rsvph);
}
static int
dissect_rsvp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSVP");
dissect_rsvp_common(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_rsvp_e2ei(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSVP-E2EI");
dissect_rsvp_common(tvb, pinfo, tree, TRUE);
return tvb_captured_length(tvb);
}
static void
register_rsvp_prefs(void)
{
module_t *rsvp_module;
rsvp_module = prefs_register_protocol(proto_rsvp, NULL);
prefs_register_bool_preference(
rsvp_module, "process_bundle",
"Dissect sub-messages in BUNDLE message",
"Specifies whether Wireshark should decode and display sub-messages within BUNDLE messages",
&rsvp_bundle_dissect);
prefs_register_enum_preference(
rsvp_module, "generalized_label_options",
"Dissect generalized labels as",
"Specifies how Wireshark should dissect generalized labels",
(gint *)&rsvp_generalized_label_option,
rsvp_generalized_label_options,
FALSE);
}
void
proto_register_rsvp(void)
{
gint i;
static hf_register_info rsvpf_info[] = {
{&hf_rsvp_filter[RSVPF_MSG],
{ "Message Type", "rsvp.msg",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &message_type_vals_ext, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_PATH],
{ "Path Message", "rsvp.path",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RESV],
{ "Resv Message", "rsvp.resv",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_PATHERR],
{ "Path Error Message", "rsvp.perr",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RESVERR],
{ "Resv Error Message", "rsvp.rerr",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_PATHTEAR],
{ "Path Tear Message", "rsvp.ptear",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RESVTEAR],
{ "Resv Tear Message", "rsvp.rtear",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RCONFIRM],
{ "Resv Confirm Message", "rsvp.resvconf",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RTEARCONFIRM],
{ "Resv Tear Confirm Message", "rsvp.rtearconf",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_BUNDLE],
{ "Bundle Message", "rsvp.bundle",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ACK],
{ "Ack Message", "rsvp.ack",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SREFRESH],
{ "Srefresh Message", "rsvp.srefresh",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_HELLO],
{ "HELLO Message", "rsvp.hello",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_OBJECT],
{ "Object class", "rsvp.object",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &rsvp_class_vals_ext, 0x0,
NULL, HFILL }
},
{&hf_rsvp_ctype,
{ "C-type", "rsvp.ctype",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_parameter,
{ "Parameter", "rsvp.parameter",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &svc_vals_ext, 0x0,
NULL, HFILL }
},
{&hf_rsvp_parameter_flags,
{ "Parameter flags", "rsvp.parameter_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_parameter_length,
{ "Parameter length", "rsvp.parameter_length",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_word_not_including_header, 0x0,
NULL, HFILL }
},
{&hf_rsvp_error_value,
{ "Error value", "rsvp.error_value",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_class,
{ "Class", "rsvp.class",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_class_length,
{ "Length", "rsvp.class_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_switching_granularity,
{ "Switching granularity", "rsvp.switching_granularity",
FT_UINT16, BASE_DEC, VALS(rsvp_switching_granularity_vals), 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_NOTIFY],
{ "Notify Message", "rsvp.notify",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION],
{ "SESSION", "rsvp.session",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_HOP],
{ "HOP", "rsvp.hop",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_HELLO_OBJ],
{ "HELLO Request/Ack", "rsvp.hello_obj",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_INTEGRITY],
{ "INTEGRITY", "rsvp.integrity",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_TIME_VALUES],
{ "TIME VALUES", "rsvp.time",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ERROR],
{ "ERROR", "rsvp.error",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SCOPE],
{ "SCOPE", "rsvp.scope",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_STYLE],
{ "STYLE", "rsvp.style",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_FLOWSPEC],
{ "FLOWSPEC", "rsvp.flowspec",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_FILTER_SPEC],
{ "FILTERSPEC", "rsvp.filter",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SENDER],
{ "SENDER TEMPLATE", "rsvp.sender",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_TSPEC],
{ "SENDER TSPEC", "rsvp.tspec",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADSPEC],
{ "ADSPEC", "rsvp.adspec",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_POLICY],
{ "POLICY", "rsvp.policy",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_CONFIRM],
{ "CONFIRM", "rsvp.confirm",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_LABEL],
{ "LABEL", "rsvp.label",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RECOVERY_LABEL],
{ "RECOVERY LABEL", "rsvp.recovery_label",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_UPSTREAM_LABEL],
{ "UPSTREAM LABEL", "rsvp.upstream_label",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SUGGESTED_LABEL],
{ "SUGGESTED LABEL", "rsvp.suggested_label",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_LABEL_SET],
{ "LABEL SET", "rsvp.label_set",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ACCEPTABLE_LABEL_SET],
{ "ACCEPTABLE LABEL SET", "rsvp.acceptable_label_set",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_PROTECTION],
{ "PROTECTION", "rsvp.protection",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV],
{ "DIFFSERV", "rsvp.diffserv",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DSTE],
{ "CLASSTYPE", "rsvp.dste",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RESTART_CAP],
{ "RESTART CAPABILITY", "rsvp.restart",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_LINK_CAP],
{ "LINK CAPABILITY", "rsvp.link",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_LABEL_REQUEST],
{ "LABEL REQUEST", "rsvp.label_request",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_ATTRIBUTE],
{ "SESSION ATTRIBUTE", "rsvp.session_attribute",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_EXPLICIT_ROUTE],
{ "EXPLICIT ROUTE", "rsvp.explicit_route",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_RECORD_ROUTE],
{ "RECORD ROUTE", "rsvp.record_route",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_MESSAGE_ID],
{ "MESSAGE-ID", "rsvp.msgid",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_MESSAGE_ID_ACK],
{ "MESSAGE-ID ACK", "rsvp.msgid_ack",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_MESSAGE_ID_LIST],
{ "MESSAGE-ID LIST", "rsvp.msgid_list",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DCLASS],
{ "DCLASS", "rsvp.dclass",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_LSP_TUNNEL_IF_ID],
{ "LSP INTERFACE-ID", "rsvp.lsp_tunnel_if_id",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS],
{ "ADMIN STATUS", "rsvp.admin_status",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_REFLECT],
{ "Reflect", "rsvp.admin_status.reflect",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_HANDOVER],
{ "Handover", "rsvp.admin_status.handover",
FT_BOOLEAN, 32, NULL, 0x40,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_LOCKOUT],
{ "Lockout", "rsvp.admin_status.lockout",
FT_BOOLEAN, 32, NULL, 0x20,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_INHIBIT],
{ "Inhibit Alarm Communication", "rsvp.admin_status.inhibit",
FT_BOOLEAN, 32, NULL, 0x10,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_CALL_MGMT],
{ "Call Management", "rsvp.admin_status.callmgmt",
FT_BOOLEAN, 32, NULL, 0x08,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_TESTING],
{ "Testing", "rsvp.admin_status.testing",
FT_BOOLEAN, 32, NULL, 0x04,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_DOWN],
{ "Administratively down", "rsvp.admin_status.down",
FT_BOOLEAN, 32, NULL, 0x02,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ADMIN_STATUS_DELETE],
{ "Delete in progress", "rsvp.admin_status.delete",
FT_BOOLEAN, 32, NULL, 0x01,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_LSP_ATTRIBUTES],
{ "LSP ATTRIBUTES", "rsvp.lsp_attributes",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ASSOCIATION],
{ "ASSOCIATION", "rsvp.association",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_CALL_ATTRIBUTES],
{ "CALL ATTRIBUTES", "rsvp.call_attributes",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_NOTIFY_REQUEST],
{ "NOTIFY REQUEST", "rsvp.notify_request",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_GENERALIZED_UNI],
{ "GENERALIZED UNI", "rsvp.generalized_uni",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_CALL_ID],
{ "CALL ID", "rsvp.call_id",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_3GPP2_OBJECT],
{ "3GPP2 OBJECT", "rsvp.3gpp2_object",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_PRIVATE_OBJ],
{ "Private object", "rsvp.obj_private",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_UNKNOWN_OBJ],
{ "Unknown object", "rsvp.obj_unknown",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_IP],
{ "Destination address", "rsvp.session.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_SHORT_CALL_ID],
{ "Short Call ID", "rsvp.session.short_call_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_PORT],
{ "Port number", "rsvp.session.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_PROTO],
{ "Protocol", "rsvp.session.proto",
FT_UINT8, BASE_DEC, VALS(proto_vals), 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
{ "Tunnel ID", "rsvp.session.tunnel_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
{ "Extended tunnel ID", "rsvp.session.ext_tunnel_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID_IPV6],
{ "Extended tunnel ID", "rsvp.session.ext_tunnel_id_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_JUNIPER],
{ "Juniper", "rsvp.juniper",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SENDER_IP],
{ "Sender IPv4 address", "rsvp.sender.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SENDER_PORT],
{ "Sender port number", "rsvp.sender.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SENDER_LSP_ID],
{ "Sender LSP ID", "rsvp.sender.lsp_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_SENDER_SHORT_CALL_ID],
{ "Short Call ID", "rsvp.sender.short_call_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_MAPNB],
{ "MAPnb", "rsvp.diffserv.mapnb",
FT_UINT8, BASE_DEC, NULL, 0x0,
MAPNB_DESCRIPTION, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_MAP],
{ "MAP", "rsvp.diffserv.map",
FT_NONE, BASE_NONE, NULL, 0x0,
MAP_DESCRIPTION, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_MAP_EXP],
{ "EXP", "rsvp.diffserv.map.exp",
FT_UINT8, BASE_DEC, NULL, 0x0,
EXP_DESCRIPTION, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID],
{ PHBID_DESCRIPTION, "rsvp.diffserv.phbid",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_DSCP],
{ PHBID_DSCP_DESCRIPTION, "rsvp.diffserv.phbid.dscp",
FT_UINT16, BASE_DEC, NULL, PHBID_DSCP_MASK,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_CODE],
{ PHBID_CODE_DESCRIPTION, "rsvp.diffserv.phbid.code",
FT_UINT16, BASE_DEC, NULL, PHBID_CODE_MASK,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_BIT14],
{ PHBID_BIT14_DESCRIPTION, "rsvp.diffserv.phbid.bit14",
FT_UINT16, BASE_DEC, VALS(phbid_bit14_vals), PHBID_BIT14_MASK,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DIFFSERV_PHBID_BIT15],
{ PHBID_BIT15_DESCRIPTION, "rsvp.diffserv.phbid.bit15",
FT_UINT16, BASE_DEC, VALS(phbid_bit15_vals), PHBID_BIT15_MASK,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_DSTE_CLASSTYPE],
{ "CT", "rsvp.dste.classtype",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_GUNI_SRC_IPV4],
{ "Source TNA", "rsvp.guni.srctna.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_GUNI_DST_IPV4],
{ "Destination TNA", "rsvp.guni.dsttna.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_GUNI_SRC_IPV6],
{ "Source TNA", "rsvp.guni.srctna.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_GUNI_DST_IPV6],
{ "Destination TNA", "rsvp.guni.dsttna.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_CALL_ID_SRC_ADDR_IPV4],
{ "Source Transport Network Address", "rsvp.callid.srcaddr.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_CALL_ID_SRC_ADDR_IPV6],
{ "Source Transport Network Address", "rsvp.callid.srcaddr.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_callid_srcaddr_ether,
{ "Source Transport Network Address", "rsvp.callid.srcaddr.ether",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_callid_srcaddr_bytes,
{ "Source Transport Network Address", "rsvp.callid.srcaddr.bytes",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_filter[RSVPF_ENT_CODE],
{ "Enterprise Code", "rsvp.obj_private.enterprise",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x0,
"IANA Network Management Private Enterprise Code", HFILL }
},
{&hf_rsvp_error_flags,
{ "Flags", "rsvp.error_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_rsvp_error_flags_path_state_removed,
{ "Path State Removed", "rsvp.error_flags.path_state_removed",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04,
NULL, HFILL }
},
{&hf_rsvp_error_flags_not_guilty,
{ "NotGuilty", "rsvp.error_flags.not_guilty",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02,
NULL, HFILL }
},
{&hf_rsvp_error_flags_in_place,
{ "InPlace", "rsvp.error_flags.in_place",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01,
NULL, HFILL }
},
{&hf_rsvp_eth_tspec_tlv_color_mode,
{ "Color Mode (CM)", "rsvp.eth_tspec_tlv.color_mode",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02,
NULL, HFILL }
},
{&hf_rsvp_eth_tspec_tlv_coupling_flag,
{ "Coupling Flag (CF)", "rsvp.eth_tspec_tlv.coupling_flag",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_standard_contiguous_concatenation,
{ "Standard contiguous concatenation", "rsvp.sender_tspec.standard_contiguous_concatenation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_arbitrary_contiguous_concatenation,
{ "Arbitrary contiguous concatenation", "rsvp.sender_tspec.arbitrary_contiguous_concatenation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_regenerator_section,
{ "Section/Regenerator Section layer transparency", "rsvp.sender_tspec.regenerator_section",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0001,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_multiplex_section,
{ "Line/Multiplex Section layer transparency", "rsvp.sender_tspec.multiplex_section",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_J0_transparency,
{ "J0 transparency", "rsvp.sender_tspec.J0_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_SOH_RSOH_DCC_transparency,
{ "SOH/RSOH DCC transparency", "rsvp.sender_tspec.SOH_RSOH_DCC_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_LOH_MSOH_DCC_transparency,
{ "LOH/MSOH DCC transparency", "rsvp.sender_tspec.LOH_MSOH_DCC_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0010,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_LOH_MSOH_extended_DCC_transparency,
{ "LOH/MSOH Extended DCC transparency", "rsvp.sender_tspec.LOH_MSOH_extended_DCC_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0020,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_K1_K2_transparency,
{ "K1/K2 transparency", "rsvp.sender_tspec.K1_K2_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0040,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_E1_transparency,
{ "E1 transparency", "rsvp.sender_tspec.E1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_F1_transparency,
{ "F1 transparency", "rsvp.sender_tspec.F1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_E2_transparency,
{ "E2 transparency", "rsvp.sender_tspec.E2_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_B1_transparency,
{ "B1 transparency", "rsvp.sender_tspec.B1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0400,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_B2_transparency,
{ "B2 transparency", "rsvp.sender_tspec.B2_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0800,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_M0_transparency,
{ "M0 transparency", "rsvp.sender_tspec.M0_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x1000,
NULL, HFILL }
},
{&hf_rsvp_sender_tspec_M1_transparency,
{ "M1 transparency", "rsvp.sender_tspec.M1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x2000,
NULL, HFILL }
},
{&hf_rsvp_flowspec_standard_contiguous_concatenation,
{ "Standard contiguous concatenation", "rsvp.flowspec.standard_contiguous_concatenation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{&hf_rsvp_flowspec_arbitrary_contiguous_concatenation,
{ "Arbitrary contiguous concatenation", "rsvp.flowspec.arbitrary_contiguous_concatenation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{&hf_rsvp_flowspec_regenerator_section,
{ "Section/Regenerator Section layer transparency", "rsvp.flowspec.regenerator_section",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0001,
NULL, HFILL }
},
{&hf_rsvp_flowspec_multiplex_section,
{ "Line/Multiplex Section layer transparency", "rsvp.flowspec.multiplex_section",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }
},
{&hf_rsvp_flowspec_J0_transparency,
{ "J0 transparency", "rsvp.flowspec.J0_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }
},
{&hf_rsvp_flowspec_SOH_RSOH_DCC_transparency,
{ "SOH/RSOH DCC transparency", "rsvp.flowspec.SOH_RSOH_DCC_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }
},
{&hf_rsvp_flowspec_LOH_MSOH_DCC_transparency,
{ "LOH/MSOH DCC transparency", "rsvp.flowspec.LOH_MSOH_DCC_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0010,
NULL, HFILL }
},
{&hf_rsvp_flowspec_LOH_MSOH_extended_DCC_transparency,
{ "LOH/MSOH Extended DCC transparency", "rsvp.flowspec.LOH_MSOH_extended_DCC_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0020,
NULL, HFILL }
},
{&hf_rsvp_flowspec_K1_K2_transparency,
{ "K1/K2 transparency", "rsvp.flowspec.K1_K2_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0040,
NULL, HFILL }
},
{&hf_rsvp_flowspec_E1_transparency,
{ "E1 transparency", "rsvp.flowspec.E1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }
},
{&hf_rsvp_flowspec_F1_transparency,
{ "F1 transparency", "rsvp.flowspec.F1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }
},
{&hf_rsvp_flowspec_E2_transparency,
{ "E2 transparency", "rsvp.flowspec.E2_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }
},
{&hf_rsvp_flowspec_B1_transparency,
{ "B1 transparency", "rsvp.flowspec.B1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0400,
NULL, HFILL }
},
{&hf_rsvp_flowspec_B2_transparency,
{ "B2 transparency", "rsvp.flowspec.B2_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0800,
NULL, HFILL }
},
{&hf_rsvp_flowspec_M0_transparency,
{ "M0 transparency", "rsvp.flowspec.M0_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x1000,
NULL, HFILL }
},
{&hf_rsvp_flowspec_M1_transparency,
{ "M1 transparency", "rsvp.flowspec.M1_transparency",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x2000,
NULL, HFILL }
},
{&hf_rsvp_integrity_flags_handshake,
{ "Handshake", "rsvp.integrity.flags.handshake",
FT_BOOLEAN, 8, TFS(&tfs_capable_not_capable), 0x01,
NULL, HFILL }
},
{&hf_rsvp_sa_flags_local,
{ "Local protection", "rsvp.sa.flags.local",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_sa_flags_label,
{ "Label recording", "rsvp.sa.flags.label",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x02,
NULL, HFILL }
},
{&hf_rsvp_sa_flags_se_style,
{ "SE style", "rsvp.sa.flags.se_style",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x04,
NULL, HFILL }
},
{&hf_rsvp_sa_flags_bandwidth,
{ "Bandwidth protection", "rsvp.sa.flags.bandwidth",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x08,
NULL, HFILL }
},
{&hf_rsvp_sa_flags_node,
{ "Node protection", "rsvp.sa.flags.node",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x10,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_local_avail,
{ "Local Protection", "rsvp.rro.flags.local_avail",
FT_BOOLEAN, 8, TFS(&tfs_available_not_available), 0x01,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_local_in_use,
{ "Local Protection", "rsvp.rro.flags.local_in_use",
FT_BOOLEAN, 8, TFS(&tfs_used_notused), 0x02,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_bandwidth,
{ "Bandwidth Protection", "rsvp.rro.flags.bandwidth",
FT_BOOLEAN, 8, TFS(&tfs_available_not_available), 0x04,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_node,
{ "Node Protection", "rsvp.rro.flags.node",
FT_BOOLEAN, 8, TFS(&tfs_available_not_available), 0x08,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_node_address,
{ "Address Specifies a Node-id Address", "rsvp.rro.flags.node_address",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_backup_tunnel_bandwidth,
{ "Backup Tunnel Has Bandwidth", "rsvp.rro.flags.backup_tunnel_bandwidth",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_backup_tunnel_hop,
{ "Backup Tunnel Goes To", "rsvp.rro.flags.backup_tunnel_hop",
FT_BOOLEAN, 8, TFS(&tfs_next_next_hop_next_hop), 0x08,
NULL, HFILL }
},
{&hf_rsvp_rro_flags_global_label,
{ "Global label", "rsvp.rro.flags.global_label",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr,
{ "LSP Attributes Flags", "rsvp.lsp_attr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_rsvp_lsp_attr_e2e,
{ "End-to-end re-routing", "rsvp.lsp_attr.e2e",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x80000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_boundary,
{ "Boundary re-routing", "rsvp.lsp_attr.boundary",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x40000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_segment,
{ "Segment-based re-routing", "rsvp.lsp_attr.segment",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x20000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_integrity,
{ "LSP Integrity Required", "rsvp.lsp_attr.integrity",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x10000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_contiguous,
{ "Contiguous LSP", "rsvp.lsp_attr.contiguous",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x08000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_stitching,
{ "LSP stitching desired", "rsvp.lsp_attr.stitching",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x04000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_preplanned,
{ "Pre-Planned LSP Flag", "rsvp.lsp_attr.preplanned",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x02000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_nophp,
{ "Non-PHP behavior flag", "rsvp.lsp_attr.nophp",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x01000000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_oobmap,
{ "OOB mapping flag", "rsvp.lsp_attr.oobmap",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x00800000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_entropy,
{ "Entropy Label Capability", "rsvp.lsp_attr.entropy",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x00400000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_srlgcollect,
{ "SRLG Collection Flag", "rsvp.lsp_attr.srlgcollect",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x00200000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_costcollect,
{ "Cost Collection Flag", "rsvp.lsp_attr.costcollect",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x00100000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_latcollect,
{ "Latency Collection Flag", "rsvp.lsp_attr.latcollect",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x00080000,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_latvarcollect,
{ "Latency Variation Flag", "rsvp.lsp_attr.latvarcollect",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x00040000,
NULL, HFILL }
},
{&hf_rsvp_gen_uni_direction,
{ "Direction", "rsvp.gen_uni.direction",
FT_BOOLEAN, 8, TFS(&tfs_gen_uni_direction), 0x80,
NULL, HFILL }
},
{&hf_rsvp_protection_info_flags_secondary_lsp,
{ "Secondary LSP", "rsvp.pi.flags.secondary_lsp",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_extra_traffic,
{ "Extra Traffic", "rsvp.pi_link.flags.extra_traffic",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_unprotected,
{ "Unprotected", "rsvp.pi_link.flags.unprotected",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x02,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_shared,
{ "Shared", "rsvp.pi_link.flags.shared",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x04,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_dedicated1_1,
{ "Dedicated 1:1", "rsvp.pi_link.flags.dedicated1_1",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x08,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_dedicated1plus1,
{ "Dedicated 1+1", "rsvp.pi_link.flags.dedicated1plus1",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x10,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_enhanced,
{ "Enhanced", "rsvp.pi_link.flags.enhanced",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x20,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_extra,
{ "Extra Traffic", "rsvp.pi_link.flags.extra",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_dedicated_1_1,
{ "Dedicated 1:1", "rsvp.pi_link.flags.dedicated_1_1",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x08,
NULL, HFILL }
},
{&hf_rsvp_pi_link_flags_dedicated_1plus1,
{ "Dedicated 1+1", "rsvp.pi_link.flags.dedicated_1plus1",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x10,
NULL, HFILL }
},
{&hf_rsvp_rfc4872_secondary,
{ "Secondary LSP", "rsvp.rfc4872.secondary",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{&hf_rsvp_rfc4872_protecting,
{ "Protecting LSP", "rsvp.rfc4872.protecting",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{&hf_rsvp_rfc4872_notification_msg,
{ "Protecting LSP", "rsvp.rfc4872.notification_msg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{&hf_rsvp_rfc4872_operational,
{ "Protecting LSP", "rsvp.rfc4872.operational",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{&hf_rsvp_pi_lsp_flags_full_rerouting,
{ "(Full) rerouting", "rsvp.pi_lsp.flags.full_rerouting",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_pi_lsp_flags_rerouting_extra,
{ "Rerouting without extra-traffic", "rsvp.pi_lsp.flags.rerouting_extra",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x02,
NULL, HFILL }
},
{&hf_rsvp_pi_lsp_flags_1_n_protection,
{ "1:N protection with extra-traffic", "rsvp.pi_lsp.flags.1_n_protection",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x04,
NULL, HFILL }
},
{&hf_rsvp_pi_lsp_flags_1plus1_unidirectional,
{ "1+1 unidirectional protection", "rsvp.pi_lsp.flags.1plus1_unidirectional",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x08,
NULL, HFILL }
},
{&hf_rsvp_pi_lsp_flags_1plus1_bidirectional,
{ "1+1 bidirectional protection", "rsvp.pi_lsp.flags.1plus1_bidirectional",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x10,
NULL, HFILL }
},
{&hf_rsvp_protection_info_in_place,
{ "In-Place", "rsvp.protection_info.in_place",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{&hf_rsvp_protection_info_required,
{ "Required", "rsvp.protection_info.required",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{&hf_rsvp_pi_seg_flags_full_rerouting,
{ "(Full) rerouting", "rsvp.pi_seg.flags.full_rerouting",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_pi_seg_flags_rerouting_extra,
{ "Rerouting without extra-traffic", "rsvp.pi_seg.flags.rerouting_extra",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x02,
NULL, HFILL }
},
{&hf_rsvp_pi_seg_flags_1_n_protection,
{ "1:N protection with extra-traffic", "rsvp.pi_seg.flags.1_n_protection",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x04,
NULL, HFILL }
},
{&hf_rsvp_pi_seg_flags_1plus1_unidirectional,
{ "1+1 unidirectional protection", "rsvp.pi_seg.flags.1plus1_unidirectional",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x08,
NULL, HFILL }
},
{&hf_rsvp_pi_seg_flags_1plus1_bidirectional,
{ "1+1 bidirectional protection", "rsvp.pi_seg.flags.1plus1_bidirectional",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x10,
NULL, HFILL }
},
{&hf_rsvp_frr_flags_one2one_backup,
{ "One-to-One Backup", "rsvp.frr.flags.one2one_backup",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_frr_flags_facility_backup,
{ "Facility Backup", "rsvp.frr.flags.facility_backup",
FT_BOOLEAN, 8, TFS(&tfs_desired_not_desired), 0x02,
NULL, HFILL }
},
{&hf_rsvp_type,
{ "Type", "rsvp.type",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tid,
{ "Transaction ID", "rsvp.3gpp_obj.tid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_ie_len,
{ "Length", "rsvp.3gpp_obj.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_ie_type,
{ "IE Type", "rsvp.3gpp_obj.ie_type",
FT_UINT32, BASE_DEC, VALS(rsvp_3gpp_object_ie_type_vals), 0,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_ue_ipv4_addr,
{ "UE IPv4 address", "rsvp.3gpp_obj.ue_ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_ue_ipv6_addr,
{ "UE IPv6 address", "rsvp.3gpp_obj.ue_ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tft_d,
{ "Direction(D)", "rsvp.3gpp_obj.tft_d",
FT_UINT32, BASE_DEC, VALS(rsvp_3gpp_object_tft_d_vals), 0xc0000000,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tft_ns,
{ "Non-Specific bit(NS)", "rsvp.3gpp_obj.tft_ns",
FT_UINT32, BASE_DEC, NULL, 0x08000000,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tft_sr_id,
{ "SR_ID", "rsvp.3gpp_obj.tft_sr_id",
FT_UINT32, BASE_DEC, NULL, 0x07000000,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tft_p,
{ "Persistency(P)", "rsvp.3gpp_obj.tft_p",
FT_UINT32, BASE_DEC, NULL, 0x00010000,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tft_opcode,
{ "TFT Operation Code", "rsvp.3gpp_obj.tft_opcode",
FT_UINT32, BASE_DEC, VALS(rsvp_3gpp_obj_tft_opcode_vals), 0x000ff00,
NULL, HFILL }
},
{&hf_rsvp_3gpp_obj_tft_n_pkt_flt,
{ "Number of Packet filters", "rsvp.3gpp_obj.tft_n_pkt_flt",
FT_UINT32, BASE_DEC, NULL, 0x00000ff,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_flow_id,
{ "Flow Identifier", "rsvp.3gpp_obj.flow_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_ev_prec,
{ "Packet filter evaluation precedence", "rsvp.3gpp_obj.pf_ev_prec",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_len,
{ "Packet filter length", "rsvp.3gpp_obj.pf_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_type,
{ "PF Type", "rsvp.3gpp_obj.pf_type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_cont_len,
{ "Length", "rsvp.3gpp_obj.pf_cont_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_comp_type_id,
{ "PF component identifier", "rsvp.3gpp_obj.pf_comp_type_id",
FT_UINT8, BASE_DEC, VALS(rsvp_3gpp_obj_pf_comp_type_id_vals), 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_src_ipv4,
{ "IPv4 Source Address", "rsvp.3gpp_obj.pf_src_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_dst_ipv4,
{ "IPv4 Destination Address", "rsvp.3gpp_obj.pf_dst_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_ipv4_mask,
{ "IPv4 Mask", "rsvp.3gpp_obj.pf_ipv4_mask",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_src_ipv6,
{ "IPv6 Source Address", "rsvp.3gpp_obj.pf_src_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_dst_ipv6,
{ "IPv6 Destination Address", "rsvp.3gpp_obj.pf_dst_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_ipv6_prefix_length,
{ "IPv6 Prefix length", "rsvp.3gpp_obj.pf_ipv6_prefix_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_prot_next,
{ "Protocol field(IPv4) or Next Header(IPv6)", "rsvp.3gpp_obj.pf_prot_next",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_dst_port,
{ "Single Destination Port", "rsvp.3gpp_obj.pf_dst_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_src_port,
{ "Single Source Port", "rsvp.3gpp_obj.pf_src_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_ipsec_spi,
{ "IPsec SPI", "rsvp.3gpp_obj.pf_ipsec_spi",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_tos_tc,
{ "Type of Service (IPv4)/Traffic Class (IPv6)", "rsvp.3gpp_obj.pf_tos_tc",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_flow_lbl,
{ "Flow label", "rsvp.3gpp_obj.pf_flow_lbl",
FT_UINT24, BASE_DEC, NULL, 0x0fffff,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_ipv6,
{ "IPv6 Address", "rsvp.3gpp_obj.pf_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_treatment,
{ "PF Treatment", "rsvp.3gpp_obj.pf_treatment",
FT_UINT8, BASE_DEC, VALS(rsvp_3gpp_obj_pf_treatment_vals), 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_pf_hint,
{ "PF Hint", "rsvp.3gpp_obj.pf_hint",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_obj_tft_qos_list_len,
{ "QoS List Length", "rsvp.3gpp_obj.qos_list_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_r_qos_blob_len,
{ "R_QOS_SUB_BLOB_LEN", "rsvp.3gpp_obj.r_qos_blob_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_r_qos_blob_flow_pri,
{ "FLOW_PRIORITY", "rsvp.3gpp_obj.r_qos_blob.flow_pri",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_r_qos_blob_num_qos_att_set,
{ "NUM_QoS_ATTRIBUTE_SETS", "rsvp.3gpp_obj.r_qos_blob.num_qos_att_set",
FT_UINT8, BASE_DEC, NULL, 0x0e,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_att_set_len,
{ "QoS_ATTRIBUTE_SET_LEN", "rsvp.3gpp_obj.r_qos_blob.qos_att_set_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_set_id,
{ "QoS_ATTRIBUTE_SET_ID", "rsvp.3gpp_obj.r_qos_blob.qos_attribute_set_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_verbose,
{ "VERBOSE", "rsvp.3gpp_obj.r_qos_blob.verbose",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_prof_id,
{ "ProfileID", "rsvp.3gpp_obj.r_qos_blob.prof_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_traff_cls,
{ "Traffic_Class", "rsvp.3gpp_obj.r_qos_blob.traff_cls",
FT_UINT8, BASE_DEC, VALS(rsvp_3gpp_obj_traffic_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_peak_rate,
{ "Peak_Rate", "rsvp.3gpp_obj.r_qos_blob.peak_rate",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_bucket_size,
{ "Bucket_Size", "rsvp.3gpp_obj.r_qos_blob.bucket_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_token_rate,
{ "Token_Rate", "rsvp.3gpp_obj.r_qos_blob.token_rate",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_max_latency,
{ "Max_Latency", "rsvp.3gpp_obj.r_qos_blob.max_latency",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_max_loss_rte,
{ "Max_Loss_Rate", "rsvp.3gpp_obj.r_qos_blob.max_loss_rte",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_delay_var_sensitive,
{ "Delay_Var_Sensitive", "rsvp.3gpp_obj.r_qos_blob.delay_var_sensitive",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_attribute_reserved,
{ "Reserved", "rsvp.3gpp_obj.r_qos_blob.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_r_qos_blob,
{ "R_QOS_SUB_BLOB", "rsvp.3gpp_obj.r_qos_blob",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_3gpp_qos_result,
{ "Result Code", "rsvp.3gpp_obj.qos_result_code",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rsvp_xro_sobj_lbit,
{ "L(oose) bit", "rsvp.xro.sobj.lbit",
FT_UINT8, BASE_DEC, VALS(rsvp_xro_sobj_lbit_vals), 0x80,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_type,
{ "Type", "rsvp.xro.sobj.type",
FT_UINT8, BASE_DEC, VALS(rsvp_xro_sobj_type_vals), 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_len,
{ "Length", "rsvp.xro.sobj.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_ipv4_addr,
{ "IPv4 prefix", "rsvp.xro.sobj.ipv4.addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_ipv4_prefix,
{ "Prefix Length", "rsvp.xro.sobj.ipv4.prefix",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_ipv4_attr,
{ "Attribute", "rsvp.xro.sobj.ipv4.attr",
FT_UINT8, BASE_DEC, VALS(rsvp_xro_sobj_ip_attr_vals), 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_ipv6_addr,
{ "IPv6 prefix", "rsvp.xro.sobj.ipv6.addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_ipv6_prefix,
{ "Prefix Length", "rsvp.xro.sobj.ipv6.prefix",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_ipv6_attr,
{ "Attribute", "rsvp.xro.sobj.ipv6.attr",
FT_UINT8, BASE_DEC, VALS(rsvp_xro_sobj_ip_attr_vals), 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_srlg_id,
{ "SRLG Id", "rsvp.xro.sobj.srlg.id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_xro_sobj_srlg_res,
{ "Reserved", "rsvp.xro.sobj.srlg.res",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_private_data,
{ "Data", "rsvp.private.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_numtlvs,
{ "Num TLVs", "rsvp.juniper.tlvs",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_padlength,
{ "Padlength", "rsvp.juniper.padlength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_type,
{ "Juniper type", "rsvp.juniper.type",
FT_UINT8, BASE_HEX, VALS(rsvp_juniper_attr_vals), 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_length,
{ "Juniper length", "rsvp.juniper.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_attrib_cos,
{ "Cos", "rsvp.juniper.attrib.cos",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_attrib_metric1,
{ "Metric 1", "rsvp.juniper.attrib.metric1",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_attrib_metric2,
{ "Metric 2", "rsvp.juniper.attrib.metric2",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_attrib_ccc_status,
{ "CCC Status", "rsvp.juniper.attrib.ccc_status",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_attrib_path,
{ "Path type", "rsvp.juniper.attrib.path",
FT_UINT16, BASE_HEX, VALS(rsvp_juniper_path_attr_vals), 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_attrib_unknown,
{ "Unknown", "rsvp.juniper.attrib.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_pad,
{ "Pad", "rsvp.juniper.pad",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_juniper_unknown,
{ "Unknown", "rsvp.juniper.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_rsvp_unknown_data,
{ "Data", "rsvp.unknown.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{&hf_rsvp_loose_hop,
{ "Hop", "rsvp.loose_hop",
FT_BOOLEAN, 8, TFS(&tfs_loose_strict_hop), 0x80,
NULL, HFILL }
},
{ &hf_rsvp_data_length,
{ "Data length", "rsvp.data_length",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_word_not_including_header, 0,
NULL, HFILL
}
},
{ &hf_rsvp_session_flags, { "Flags", "rsvp.session.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_destination_address, { "Destination address", "rsvp.session.destination_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_protocol, { "Protocol", "rsvp.session.protocol", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_destination_port, { "Destination port", "rsvp.session.destination_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_dscp, { "DSCP", "rsvp.session.dscp", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dscp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_extended_ipv4_address, { "Extended IPv4 Address", "rsvp.session.extended_ipv4_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_data, { "Data", "rsvp.session.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_length, { "Length", "rsvp.ifid_tlv.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_ipv4_address, { "IPv4 address", "rsvp.ifid_tlv.ipv4_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_ipv6_address, { "IPv6 address", "rsvp.ifid_tlv.ipv6_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlvinterface_id, { "Interface-ID", "rsvp.ifid_tlv.interface_id", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_label, { "Label", "rsvp.ifid_tlv.label", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_node_id, { "Node ID", "rsvp.ifid_tlv.node_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_area, { "Area", "rsvp.ifid_tlv.area", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_autonomous_system, { "Autonomous System", "rsvp.ifid_tlv.autonomous_system", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_error_string, { "Error String", "rsvp.ifid_tlv.error_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_data, { "Data", "rsvp.ifid_tlv.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ifid_tlv_padding, { "Padding", "rsvp.ifid_tlv.padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hop_neighbor_address_ipv4, { "Neighbor address", "rsvp.hop.neighbor_address_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hop_logical_interface, { "Logical interface", "rsvp.hop.logical_interface", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hop_neighbor_address_ipv6, { "Neighbor address", "rsvp.neighbor_address_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hop_data, { "Data", "rsvp.hop.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_time_values_data, { "Data", "rsvp.time_values.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_error_error_node_ipv4, { "Error node", "rsvp.error.error_node_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_error_error_node_ipv6, { "Error node", "rsvp.error.error_node_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_error_data, { "Data", "rsvp.error.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_error_error_code, { "Error code", "rsvp.error.error_code", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &rsvp_error_codes_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_scope_ipv4_address, { "IPv4 Address", "rsvp.scope.ipv4_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_scope_ipv6_address, { "IPv6 Address", "rsvp.scope.ipv6_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_scope_data, { "Data", "rsvp.scope.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_style_flags, { "Flags", "rsvp.style.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_style_style, { "Style", "rsvp.style.style", FT_UINT24, BASE_HEX, VALS(style_vals), 0x0, NULL, HFILL }},
{ &hf_rsvp_style_data, { "Data", "rsvp.style.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_confirm_receiver_address_ipv4, { "Receiver address", "rsvp.confirm.receiver_address_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_confirm_receiver_address_ipv6, { "Receiver address", "rsvp.confirm.receiver_address_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_confirm_data, { "Data", "rsvp.confirm.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_template_filter_source_address_ipv6, { "Source address", "rsvp.template_filter.source_address_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_template_filter_source_port, { "Source port", "rsvp.template_filter.source_port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_template_filter_data, { "Data", "rsvp.template_filter.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_length, { "Length", "rsvp.eth_tspec.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_profile, { "Profile", "rsvp.eth_tspec.profile", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_index, { "Index", "rsvp.eth_tspec.index", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_reserved, { "Reserved", "rsvp.eth_tspec.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_el2cp, { "EL2CP", "rsvp.eth_tspec.el2cp", FT_UINT8, BASE_DEC, VALS(el2cp_val_str), 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_il2cp, { "IL2CP", "rsvp.eth_tspec.il2cp", FT_UINT8, BASE_DEC, VALS(il2cp_val_str), 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_cir, { "CIR", "rsvp.eth_tspec.cir", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_cbs, { "CBS", "rsvp.eth_tspec.cbs", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_eir, { "EIR", "rsvp.eth_tspec.eir", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_eth_tspec_ebs, { "EBS", "rsvp.eth_tspec.ebs", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_message_format_version, { "Message format version", "rsvp.tspec.message_format_version", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_rsvp_tspec_service_header, { "Service header", "rsvp.tspec.service_header", FT_UINT8, BASE_DEC, VALS(qos_vals), 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_token_bucket_rate, { "Token bucket rate", "rsvp.tspec.token_bucket_rate", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_token_bucket_size, { "Token bucket size", "rsvp.tspec.token_bucket_size", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_peak_data_rate, { "Peak data rate", "rsvp.tspec.peak_data_rate", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_hint, { "Hint", "rsvp.tspec.hint", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_compression_factor, { "Compression Factor", "rsvp.tspec.compression_factor", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_signal_type_sonet, { "Signal Type", "rsvp.tspec.signal_type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gmpls_sonet_signal_type_str_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_requested_concatenation, { "Requested Concatenation (RCC)", "rsvp.tspec.requested_concatenation", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_number_of_contiguous_components, { "Number of Contiguous Components (NCC)", "rsvp.tspec.number_of_contiguous_components", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_number_of_virtual_components, { "Number of Virtual Components (NVC)", "rsvp.tspec.number_of_virtual_components", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_multiplier, { "Multiplier (MT)", "rsvp.tspec.multiplier", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_transparency, { "Transparency (T)", "rsvp.tspec.transparency", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_profile, { "Profile (P)", "rsvp.tspec.profile", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_signal_type_g709, { "Signal Type", "rsvp.tspec.signal_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_g709_signal_type_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_number_of_multiplexed_components, { "Number of Multiplexed Components (NMC)", "rsvp.number_of_multiplexed_components", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_mtu, { "MTU", "rsvp.tspec.mtu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_tspec_data, { "Data", "rsvp.tspec.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_message_format_version, { "Message format version", "rsvp.flowspec.message_format_version", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_rsvp_flowspec_service_header, { "Service header", "rsvp.flowspec.service_header", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &intsrv_services_str_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_token_bucket_rate, { "Token bucket rate", "rsvp.flowspec.token_bucket_rate", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_token_bucket_size, { "Token bucket size", "rsvp.flowspec.token_bucket_size", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_peak_data_rate, { "Peak data rate", "rsvp.flowspec.peak_data_rate", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_rate, { "Rate", "rsvp.flowspec.rate", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_slack_term, { "Slack term", "rsvp.flowspec.slack_term", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_signal_type_sonet, { "Signal Type", "rsvp.flowspec.signal_type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gmpls_sonet_signal_type_str_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_requested_concatenation, { "Requested Concatenation (RCC)", "rsvp.flowspec.requested_concatenation", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_number_of_contiguous_components, { "Number of Contiguous Components (NCC)", "rsvp.flowspec.number_of_contiguous_components", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_number_of_virtual_components, { "Number of Virtual Components (NVC)", "rsvp.flowspec.number_of_virtual_components", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_multiplier, { "Multiplier (MT)", "rsvp.flowspec.multiplier", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_transparency, { "Transparency (T)", "rsvp.flowspec.transparency", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_profile, { "Profile (P)", "rsvp.flowspec.profile", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_signal_type_g709, { "Signal Type", "rsvp.flowspec.signal_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_g709_signal_type_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_number_of_multiplexed_components, { "Number of Multiplexed Components (NMC)", "rsvp.flowspec.number_of_multiplexed_components", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_flowspec_mtu, { "MTU", "rsvp.flowspec.mtu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_adspec_message_format_version, { "Message format version", "rsvp.adspec.message_format_version", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_rsvp_adspec_service_header, { "Service header", "rsvp.adspec.service_header", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &intsrv_services_str_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_integrity_flags, { "Flags", "rsvp.integrity.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_integrity_key_identifier, { "Key Identifier", "rsvp.integrity.key_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_integrity_sequence_number, { "Sequence Number", "rsvp.integrity.sequence_number", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_integrity_hash, { "Hash", "rsvp.integrity.hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_policy_data, { "Data", "rsvp.policy.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_request_l3pid, { "L3PID", "rsvp.label_request.l3pid", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0, NULL, HFILL }},
{ &hf_rsvp_label_request_min_vpi, { "Min VPI", "rsvp.label_request.min_vpi", FT_UINT16, BASE_DEC, NULL, 0x7f, NULL, HFILL }},
{ &hf_rsvp_label_request_min_vci, { "Min VCI", "rsvp.label_request.min_vci", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_request_max_vpi, { "Max VPI", "rsvp.label_request.max_vpi", FT_UINT16, BASE_DEC, NULL, 0x7f, NULL, HFILL }},
{ &hf_rsvp_label_request_max_vci, { "Max VCI", "rsvp.label_request.max_vci", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_request_lsp_encoding_type, { "LSP Encoding Type", "rsvp.label_request.lsp_encoding_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_lsp_enc_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_label_request_switching_type, { "Switching Type", "rsvp.label_request.switching_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_switching_type_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_g_pid, { "G-PID", "rsvp.label_request.g_pid", FT_UINT16, BASE_HEX|BASE_RANGE_STRING, RVALS(gmpls_gpid_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_label_request_data, { "Data", "rsvp.label_request.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_label, { "Label", "rsvp.label.label", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_generalized_label, { "Generalized Label", "rsvp.label.generalized_label", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_generalized_label_evpl_vlad_id, { "VLAN ID", "rsvp.label.generalized_label_evpl_vlad_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_data, { "Data", "rsvp.label.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_set_action, { "Action", "rsvp.label_set.action", FT_UINT8, BASE_DEC, VALS(action_type_vals), 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_exclude_any, { "Exclude-Any", "rsvp.session_attribute.exclude_any", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_include_any, { "Include-Any", "rsvp.session_attribute.include_any", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_include_all, { "Include-All", "rsvp.session_attribute.include_all", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_setup_priority, { "Setup priority", "rsvp.session_attribute.setup_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_hold_priority, { "Hold priority", "rsvp.session_attribute.hold_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_flags, { "Flags", "rsvp.session_attribute.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_name_length, { "Name length", "rsvp.session_attribute.name_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_name, { "Name", "rsvp.session_attribute.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_session_attribute_data, { "Data", "rsvp.session_attribute.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_length, { "Length", "rsvp.ero_rro_subobjects.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_ipv4_hop, { "IPv4 hop", "rsvp.ero_rro_subobjects.ipv4_hop", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_prefix_length, { "Prefix length", "rsvp.ero_rro_subobjects.prefix_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_flags, { "Flags", "rsvp.ero_rro_subobjects.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_ipv6_hop, { "IPv6 hop", "rsvp.ero_rro_subobjects.ipv6_hop", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_label, { "Label", "rsvp.ero_rro_subobjects.label", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_router_id, { "Router-ID", "rsvp.ero_rro_subobjects.router_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_interface_id, { "Interface-ID", "rsvp.ero_rro_subobjects.interface_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_path_key, { "Path Key", "rsvp.ero_rro_subobjects.path_key", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_pce_id_ipv4, { "PCE-ID", "rsvp.ero_rro_subobjects.pce_id_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_pce_id_ipv6, { "PCE-ID", "rsvp.ero_rro_subobjects.pce_id_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_private_length, { "Length", "rsvp.ero_rro_subobjects.private_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_subobjects_private_data, { "Data", "rsvp.ero_rro_subobjects.private_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_explicit_route_data, { "Data", "rsvp.explicit_route.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_record_route_data, { "Data", "rsvp.record_route.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_exclude_route_data, { "Data", "rsvp.exclude_route.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_flags, { "Flags", "rsvp.message_id.flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_epoch, { "Epoch", "rsvp.message_id.epoch", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_message_id, { "Message-ID", "rsvp.message_id.message_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_data, { "Data", "rsvp.message_id.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_ack_flags, { "Flags", "rsvp.message_id_ack.flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_ack_epoch, { "Epoch", "rsvp.message_id_ack.epoch", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_ack_message_id, { "Message-ID", "rsvp.message_id_ack.message_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_ack_data, { "Data", "rsvp.message_id_ack.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_list_flags, { "Flags", "rsvp.message_id_list.flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_list_epoch, { "Epoch", "rsvp.message_id_list.epoch", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_list_message_id, { "Message-ID", "rsvp.message_id_list.message_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_id_list_data, { "Data", "rsvp.message_id_list.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hello_source_instance, { "Source Instance", "rsvp.hello.source_instance", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hello_destination_instance, { "Destination Instance", "rsvp.hello.destination_instance", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_dclass_dscp, { "DSCP", "rsvp.dclass.dscp", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dscp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_dclass_data, { "Data", "rsvp.dclass.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_admin_status_bits, { "Admin Status", "rsvp.admin_status.bits", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_admin_status_data, { "Data", "rsvp.admin_status.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_attributes_tlv, { "LSP attributes TLV", "rsvp.lsp_attributes_tlv", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_attributes_tlv_data, { "Data", "rsvp.lsp_attributes_tlv.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_type, { "Association type", "rsvp.association.type", FT_UINT16, BASE_DEC, VALS(association_type_vals), 0x0, NULL, HFILL }},
{ &hf_rsvp_association_id, { "Association ID", "rsvp.association.id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_source_ipv4, { "Association source", "rsvp.association.source_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_source_ipv6, { "Association source", "rsvp.association.source_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_routing_area_id, { "Routing Area ID", "rsvp.association.routing_area_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_node_id, { "Node ID", "rsvp.association.node_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_padding, { "Padding", "rsvp.association.padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_association_data, { "Data", "rsvp.association.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_length, { "Length", "rsvp.lsp_tunnel_if_id.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_component_link_identifier, { "Component link identifier", "rsvp.lsp_tunnel_if_id.component_link_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_component_link_identifier_ipv4, { "Component link identifier", "rsvp.lsp_tunnel_if_id.component_link_identifier_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_lsp_encoding_type, { "LSP Encoding Type", "rsvp.lsp_tunnel_if_id.lsp_encoding_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_lsp_enc_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_switching_type, { "Switching Type", "rsvp.lsp_tunnel_if_id.switching_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmpls_switching_type_rvals), 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_signal_type, { "Signal Type", "rsvp.lsp_tunnel_if_id.signal_type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gmpls_sonet_signal_type_str_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_connection_id, { "Sub Interface/Connection ID", "rsvp.lsp_tunnel_if_id.connection_id", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_sc_pc_id, { "SC PC ID", "rsvp.lsp_tunnel_if_id.sc_pc_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_sc_pc_scn_address, { "SC PC SCN Address", "rsvp.lsp_tunnel_if_id.sc_pc_scn_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_router_id, { "Router ID", "rsvp.lsp_tunnel_if_id.router_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_interface_id, { "Interface ID", "rsvp.lsp_tunnel_if_id.interface_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_ipv4_interface_address, { "IPv4 interface address", "rsvp.lsp_tunnel_if_id.ipv4_interface_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_target_igp_instance, { "Target IGP instance", "rsvp.lsp_tunnel_if_id.target_igp_instance", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_action, { "Action", "rsvp.lsp_tunnel_if_id.action", FT_UINT8, BASE_DEC, VALS(lsp_tunnel_if_id_action_str), 0xF0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_ipv6_interface_address, { "IPv6 interface address", "rsvp.lsp_tunnel_if_id.ipv6_interface_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_lsp_tunnel_if_id_data, { "Data", "rsvp.lsp_tunnel_if_id.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_notify_request_notify_node_address_ipv4, { "Notify node address", "rsvp.notify_request.notify_node_address_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_notify_request_notify_node_address_ipv6, { "Notify node address", "rsvp.notify_request.notify_node_address_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_notify_request_data, { "Data", "rsvp.notify_request.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_call_id_data, { "Data", "rsvp.call_id.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_call_id_address_type, { "Address type", "rsvp.call_id.address_type", FT_UINT8, BASE_DEC, VALS(address_type_vals), 0x0, NULL, HFILL }},
{ &hf_rsvp_call_id_reserved, { "Reserved", "rsvp.call_id.reserved", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_call_id_international_segment, { "International Segment", "rsvp.call_id.international_segment", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_call_id_national_segment, { "National Segment", "rsvp.call_id.national_segment", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_call_id_local_identifier, { "Local Identifier", "rsvp.call_id.local_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_restart_cap_data, { "Data", "rsvp.restart_cap.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_protection_info_link_flags, { "Link Flags", "rsvp.protection_info.link_flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_protection_info_data, { "Data", "rsvp.protection_info.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_setup_priority, { "Setup Priority", "rsvp.fast_reroute.setup_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_hold_priority, { "Hold Priority", "rsvp.fast_reroute.hold_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_hop_limit, { "Hop Limit", "rsvp.fast_reroute.hop_limit", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_flags, { "Flags", "rsvp.fast_reroute.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_bandwidth, { "Bandwidth", "rsvp.fast_reroute.bandwidth", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_include_any, { "Include-Any", "rsvp.fast_reroute.include_any", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_exclude_any, { "Exclude-Any", "rsvp.fast_reroute.exclude_any", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_include_all, { "Include-All", "rsvp.fast_reroute.include_all", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_fast_reroute_data, { "Data", "rsvp.fast_reroute.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_detour_data, { "Data", "rsvp.detour.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_diffserv_data, { "Data", "rsvp.diffserv.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_diffserv_aware_te_data, { "Data", "rsvp.diffserv_aware_te.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_version, { "RSVP Version", "rsvp.version", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_rsvp_flags, { "Flags", "rsvp.flags", FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }},
{ &hf_rsvp_sending_ttl, { "Sending TTL", "rsvp.sending_ttl", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_length, { "Message length", "rsvp.message_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_length, { "Length", "rsvp.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_extended_tunnel_id, { "Extended Tunnel ID", "rsvp.extended_tunnel_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_extended_tunnel_ipv6, { "Extended Tunnel ID", "rsvp.extended_tunnel_id_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_extended_tunnel, { "Extended Tunnel", "rsvp.extended_tunnel", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_refresh_interval, { "Refresh interval", "rsvp.refresh_interval", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_minimum_policed_unit, { "Minimum policed unit [m]", "rsvp.minimum_policed_unit", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_maximum_packet_size, { "Maximum packet size [M]", "rsvp.maximum_packet_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_hf_rsvp_adspec_break_bit, { "Break bit", "rsvp.adspec.break_bit", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_rsvp_label_request_m, { "M (Merge in Data Plane)", "rsvp.label_request.m", FT_BOOLEAN, 8, TFS(&tfs_can_cannot), 0x80, NULL, HFILL }},
{ &hf_rsvp_dlci_length, { "DLCI Length", "rsvp.label_request.dlci_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_min_dlci, { "Min DLCI", "rsvp.label_request.min_dlci", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_max_dlci, { "Max DLCI", "rsvp.label_request.max_dlci", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ero_rro_autonomous_system, { "Autonomous System", "rsvp.ero_rro_subobjects.autonomous_system", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_nsap_length, { "NSAP Length", "rsvp.nsap_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_gen_uni_data, { "Data", "rsvp.gen_uni.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_gen_uni_logical_port_id, { "Logical Port ID", "rsvp.gen_uni.logical_port_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_gen_uni_service_level, { "Service Level", "rsvp.gen_uni.service_level", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_restart_cap_restart_time, { "Restart Time", "rsvp.restart_cap.restart_time", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0x0, NULL, HFILL }},
{ &hf_rsvp_restart_cap_recovery_time, { "Recovery Time", "rsvp.restart_cap.recovery_time", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0x0, NULL, HFILL }},
{ &hf_rsvp_detour_plr_id, { "PLR ID", "rsvp.detour.plr_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_detour_avoid_node_id, { "Avoid Node ID", "rsvp.detour.avoid_node_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_message_checksum, { "Message Checksum", "rsvp.message_checksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_call_attributes_endpont_id, { "Endpoint ID", "rsvp.call_attributes.endpoint_id", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_isis_area_id, { "IS-IS Area Identifier", "rsvp.isis_area_id", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_adspec_type, { "Adspec Type", "rsvp.adspec.type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &adspec_params_ext, 0x0, NULL, HFILL }},
{ &hf_rsvp_adspec_len, { "Length", "rsvp.adspec.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_adspec_uint, { "Adspec uint", "rsvp.adspec.uint", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_adspec_float, { "Adspec float", "rsvp.adspec.float", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_adspec_bytes, { "Adspec bytes", "rsvp.adspec.bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_wavelength_freq, { "Freq", "rsvp.wavelength.freq", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_wavelength_grid, { "Grid", "rsvp.wavelength.grid", FT_UINT8, BASE_DEC, VALS(lambda_grid_vals), 0xE0, NULL, HFILL }},
{ &hf_rsvp_wavelength_channel_spacing, { "Channel Spacing", "rsvp.wavelength.channel_spacing", FT_UINT8, BASE_DEC, NULL, 0x1E, NULL, HFILL }},
{ &hf_rsvp_wavelength_n, { "n", "rsvp.wavelength.n", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_wavelength_wavelength, { "Wavelength", "rsvp.wavelength.wavelength", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_nanometers, 0x0, NULL, HFILL }},
{ &hf_rsvp_sonet_s, { "S", "rsvp.sonet.s", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_sonet_u, { "U", "rsvp.sonet.u", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_rsvp_sonet_k, { "K", "rsvp.sonet.k", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_rsvp_sonet_l, { "L", "rsvp.sonet.l", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_rsvp_sonet_m, { "M", "rsvp.sonet.m", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_rsvp_g709_t3, { "t3", "rsvp.g709.t3", FT_UINT16, BASE_DEC, NULL, 0x03F0, NULL, HFILL }},
{ &hf_rsvp_g709_t2, { "t2", "rsvp.g709.t2", FT_UINT8, BASE_DEC, NULL, 0x0E, NULL, HFILL }},
{ &hf_rsvp_g709_t1, { "t1", "rsvp.g709.t1", FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{ &hf_rsvp_label_set_type, { "Label type", "rsvp.label_set.type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_label_set_subchannel, { "Subchannel", "rsvp.label_set.subchannel", FT_UINT32, BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_nsap_address, { "NSAP address", "rsvp.nsap_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_class_diversity, { "Diversity", "rsvp.class_diversity", FT_UINT8, BASE_DEC, VALS(ouni_guni_diversity_str), 0xF0, NULL, HFILL }},
{ &hf_rsvp_egress_label_type, { "Label type", "rsvp.egress.label_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_egress_label, { "Label", "rsvp.egress.label", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_source_transport_network_addr, { "Source Transport Network addr", "rsvp.source_transport_network_addr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_ie_data, { "IE Data", "rsvp.ie_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_3gpp_obj_pf_dst_port_range, { "Destination Port range", "rsvp.3gpp_obj.pf_dst_port_range", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_rsvp_3gpp_obj_pf_src_port_range, { "Source Port range", "rsvp.3gpp_obj.pf_src_port_range", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_rsvp_invalid_length, { "rsvp.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_rsvp_packet_filter_component, { "rsvp.packet_filter_component", PI_UNDECODED, PI_WARN, "Not dissected Packet filter component", EXPFILL }},
{ &ei_rsvp_bundle_component_msg, { "rsvp.bundle_component_msg", PI_UNDECODED, PI_WARN, "Bundle Component Messages Not Dissected", EXPFILL }},
{ &ei_rsvp_parameter, { "rsvp.parameter.unknown", PI_PROTOCOL, PI_WARN, "Unknown parameter", EXPFILL }},
{ &ei_rsvp_adspec_type, { "rsvp.adspec.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown type", EXPFILL }},
{ &ei_rsvp_call_id_address_type, { "rsvp.call_id.address_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown Transport Network type", EXPFILL }},
{ &ei_rsvp_session_type, { "rsvp.session_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown session type", EXPFILL }},
};
expert_module_t* expert_rsvp;
gint *ett_tree[TT_MAX];
for (i=0; i<TT_MAX; i++) {
ett_treelist[i] = -1;
ett_tree[i] = &(ett_treelist[i]);
}
proto_rsvp = proto_register_protocol("Resource ReserVation Protocol (RSVP)", "RSVP", "rsvp");
proto_rsvp_e2e1 = proto_register_protocol_in_name_only("Resource ReserVation Protocol (RSVP-E2EI)", "RSVP-E2EI", "rsvp-e2ei", proto_rsvp, FT_PROTOCOL);
proto_register_field_array(proto_rsvp, rsvpf_info, array_length(rsvpf_info));
proto_register_subtree_array(ett_tree, array_length(ett_tree));
expert_rsvp = expert_register_protocol(proto_rsvp);
expert_register_field_array(expert_rsvp, ei, array_length(ei));
register_rsvp_prefs();
rsvp_request_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), rsvp_hash, rsvp_equal);
register_conversation_table(proto_rsvp, TRUE, rsvp_conversation_packet, rsvp_hostlist_packet);
}
void
proto_reg_handoff_rsvp(void)
{
dissector_handle_t rsvp_handle, rsvpe2ei_handle;
rsvp_handle = create_dissector_handle(dissect_rsvp, proto_rsvp);
rsvpe2ei_handle = create_dissector_handle(dissect_rsvp_e2ei, proto_rsvp_e2e1);
dissector_add_uint("ip.proto", IP_PROTO_RSVP, rsvp_handle);
dissector_add_uint("ip.proto", IP_PROTO_RSVPE2EI, rsvpe2ei_handle);
dissector_add_uint_with_preference("udp.port", UDP_PORT_PRSVP, rsvp_handle);
rsvp_tap = register_tap("rsvp");
}
