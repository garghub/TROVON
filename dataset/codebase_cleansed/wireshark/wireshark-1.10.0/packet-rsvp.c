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
if (ADDRESSES_EQUAL(&key1->u.session_ipv4.destination,
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
if (ADDRESSES_EQUAL(&key1->u.session_ipv4_lsp.destination,
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
if (ADDRESSES_EQUAL(&key1->u.session_agg_ipv4.destination,
&key2->u.session_agg_ipv4.destination) == FALSE)
return 0;
if (key1->u.session_agg_ipv4.dscp != key2->u.session_agg_ipv4.dscp)
return 0;
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV6:
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
if (ADDRESSES_EQUAL(&key1->u.session_ipv4_uni.destination,
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
if (ADDRESSES_EQUAL(&key1->u.session_ipv4_enni.destination,
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
if (ADDRESSES_EQUAL(&key1->source_info.source,
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
static void
rsvp_init_protocol(void)
{
if (rsvp_request_hash)
g_hash_table_destroy(rsvp_request_hash);
rsvp_request_hash = g_hash_table_new(rsvp_hash, rsvp_equal);
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
return ep_strdup_printf("SESSION: IPv4, Destination %s, Protocol %d, Port %d. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_guint8(tvb, offset+8),
tvb_get_ntohs(tvb, offset+10));
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
return ep_strdup_printf("SESSION: IPv4-LSP, Destination %s, Tunnel ID %d, Ext ID %0x. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_get_ntohl(tvb, offset+12));
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
return ep_strdup_printf("SESSION: IPv4-Aggregate, Destination %s, DSCP %d. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_guint8(tvb, offset+11));
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
return ep_strdup_printf("SESSION: IPv4-UNI, Destination %s, Tunnel ID %d, Ext Address %s. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_ip_to_str(tvb, offset+12));
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
return ep_strdup_printf("SESSION: IPv4-E-NNI, Destination %s, Tunnel ID %d, Ext Address %s. ",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10),
tvb_ip_to_str(tvb, offset+12));
break;
default:
return ep_strdup_printf("SESSION: Type %d. ", tvb_get_guint8(tvb, offset+3));
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
return ep_strdup_printf("%s: IPv4, Sender %s, Port %d. ", objtype,
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10));
break;
case 7:
return ep_strdup_printf("%s: IPv4-LSP, Tunnel Source: %s, LSP ID: %d. ", objtype,
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohs(tvb, offset+10));
break;
case 9:
return ep_strdup_printf("%s: IPv4-Aggregate, Aggregator %s. ", objtype,
tvb_ip_to_str(tvb, offset+4));
break;
default:
return ep_strdup_printf("%s: Type %d. ", objtype, tvb_get_guint8(tvb, offset+3));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_PROTO], tvb,
offset2+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+5, 1,
"Flags: %x",
tvb_get_guint8(tvb, offset2+5));
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_PORT], tvb,
offset2+6, 2, ENC_BIG_ENDIAN);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4;
TVB_SET_ADDRESS(&rsvph->destination, AT_IPv4, tvb, offset2, 4);
rsvph->protocol = tvb_get_guint8(tvb, offset2+4);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
break;
case RSVP_SESSION_TYPE_IPV6:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"Destination address: %s",
tvb_ip6_to_str(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+16, 1,
"Protocol: %u",
tvb_get_guint8(tvb, offset2+16));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+17, 1,
"Flags: %x",
tvb_get_guint8(tvb, offset2+17));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+18, 2,
"Destination port: %u",
tvb_get_ntohs(tvb, offset2+18));
rsvph->session_type = RSVP_SESSION_TYPE_IPV6;
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 7 - IPv4 LSP");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 4,
"Extended Tunnel ID: %u (%s)",
tvb_get_ntohl(tvb, offset2+8),
tvb_ip_to_str(tvb, offset2+8));
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4_LSP;
TVB_SET_ADDRESS(&rsvph->destination, AT_IPv4, tvb, offset2, 4);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 9 - IPv4 Aggregate");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+7, 1,
"DSCP: %u (%s)",
tvb_get_guint8(tvb, offset2+7),
val_to_str_ext(tvb_get_guint8(tvb, offset2+7),
&dscp_vals_ext, "Unknown (%d)"));
rsvph->session_type = RSVP_SESSION_TYPE_AGGREGATE_IPV4;
TVB_SET_ADDRESS(&rsvph->destination, AT_IPv4, tvb, offset2, 4);
rsvph->dscp = tvb_get_guint8(tvb, offset2+7);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 11 - IPv4 UNI");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 4,
"Extended IPv4 Address: %s",
tvb_ip_to_str(tvb, offset2+8));
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4_UNI;
TVB_SET_ADDRESS(&rsvph->destination, AT_IPv4, tvb, offset2, 4);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 15 - IPv4 E-NNI");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_TUNNEL_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 4,
"Extended IPv4 Address: %s",
tvb_ip_to_str(tvb, offset2+8));
hidden_item = proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SESSION_EXT_TUNNEL_ID],
tvb, offset2+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
rsvph->session_type = RSVP_SESSION_TYPE_IPV4_E_NNI;
TVB_SET_ADDRESS(&rsvph->destination, AT_IPv4, tvb, offset2, 4);
rsvph->udp_dest_port = tvb_get_ntohs(tvb, offset2+6);
rsvph->ext_tunnel_id = tvb_get_ntohl(tvb, offset2 + 8);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length-4,
"Data (%d bytes)", obj_length-4);
break;
}
}
static void
dissect_rsvp_ifid_tlv(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int length,
int subtree_type)
{
int tlv_off, padding;
guint16 tlv_type;
int tlv_len;
guint8 isis_len;
const char *tlv_name;
proto_tree *rsvp_ifid_subtree=NULL, *ti2;
for (tlv_off = 0; tlv_off < length; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || (tlv_off+tlv_len > length)) {
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off+2, 2,
"Invalid TLV length");
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%sIPv4 TLV - %s", tlv_name,
tvb_ip_to_str(tvb, offset+tlv_off+4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%sIPv4)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"IPv4 address: %s",
tvb_ip_to_str(tvb, offset+tlv_off+4));
proto_item_append_text(ti, "%sIPv4: %s. ", tlv_name,
tvb_ip_to_str(tvb, offset+tlv_off+4));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%sIPv6 TLV - %s", tlv_name,
tvb_ip6_to_str(tvb, offset+tlv_off+4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%sIPv6)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"IPv6 address: %s",
tvb_ip6_to_str(tvb, offset+tlv_off+4));
proto_item_append_text(ti, "%sIPv6: %s. ", tlv_name,
tvb_ip6_to_str(tvb, offset+tlv_off+4));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"Interface-Index%s TLV - %s, %d",
tlv_name,
tvb_ip_to_str(tvb, offset+tlv_off+4),
tvb_get_ntohl(tvb, offset+tlv_off+8));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (Interface Index%s)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"IPv4 address: %s",
tvb_ip_to_str(tvb, offset+tlv_off+4));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+8, 4,
"Interface-ID: %d (0x%0x)",
tvb_get_ntohl(tvb, offset+tlv_off+8),
tvb_get_ntohl(tvb, offset+tlv_off+8));
proto_item_append_text(ti, "Data If-Index%s: %s, %d. ", tlv_name,
tvb_ip_to_str(tvb, offset+tlv_off+4),
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%s-Label TLV - %u", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%s-Label)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"Label: %u",
tvb_get_ntohl(tvb, offset+tlv_off+4));
proto_item_append_text(ti, "%s-Label: %u. ", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
break;
case 8:
tlv_name = "";
goto ifid_nodeid;
case 21:
tlv_name = "Reporting-";
ifid_nodeid:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%sNode-ID TLV - %s", tlv_name,
tvb_ip_to_str(tvb, offset+tlv_off+4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%sNode-ID)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"Node ID: %s",
tvb_ip_to_str(tvb, offset+tlv_off+4));
proto_item_append_text(ti, "%sNode-ID: %s. ", tlv_name,
tvb_ip_to_str(tvb, offset+tlv_off+4));
break;
case 9:
tlv_name = "";
goto ifid_ospf;
case 22:
tlv_name = "Reporting-";
ifid_ospf:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%sOSPF-Area TLV - %u", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%sOSPF-Area)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"Area: %u",
tvb_get_ntohl(tvb, offset+tlv_off+4));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off, tlv_len,
"%sISIS-Area TLV - Invalid Length field", tlv_name);
break;
}
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%sISIS-Area TLV - %s", tlv_name,
print_nsap_net(tvb_get_ptr(tvb, offset+tlv_off+5, isis_len),
isis_len));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%sISIS-Area)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"IS-IS Area Identifier: %s",
print_nsap_net(tvb_get_ptr(tvb, offset+tlv_off+5, isis_len), isis_len));
proto_item_append_text(ti, "%sISIS-Area: %s. ", tlv_name,
print_nsap_net(tvb_get_ptr(tvb, offset+tlv_off+5, isis_len), isis_len));
break;
case 11:
tlv_name = "";
goto ifid_as;
case 24:
tlv_name = "Reporting-";
ifid_as:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%sAS TLV - %u", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%sAS)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+4, 4,
"Autonomous System: %u",
tvb_get_ntohl(tvb, offset+tlv_off+4));
proto_item_append_text(ti, "%sAS: %u. ", tlv_name,
tvb_get_ntohl(tvb, offset+tlv_off+4));
break;
case 26:
tlv_name = "Node";
goto ifid_ex;
case 27:
tlv_name = "Link";
ifid_ex:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"%s-Exclusions TLV - ", tlv_name);
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off, 2,
"Type: %d (%s-Exclusions)", tlv_type, tlv_name);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset+tlv_off+2));
dissect_rsvp_ifid_tlv(ti2, rsvp_ifid_subtree, tvb, offset+tlv_off+4,
tlv_len-4, TREE(TT_HOP_SUBOBJ));
break;
case 516:
ti2 =
proto_tree_add_text(rsvp_object_tree,
tvb, offset + tlv_off,
tlv_len,
"ERROR_STRING TLV - %s",
tvb_format_text(tvb, offset + tlv_off + 4,
tlv_len - 4));
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset + tlv_off, 2,
"Type: 516 (ERROR_STRING)");
proto_tree_add_text(rsvp_ifid_subtree,
tvb, offset + tlv_off + 2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset + tlv_off + 2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset + tlv_off + 4,
tlv_len - 4,
"Error String: %s",
tvb_format_text(tvb, offset + tlv_off + 4,
tlv_len - 4));
break;
default:
ti2 = proto_tree_add_text(rsvp_object_tree,
tvb, offset + tlv_off,
tlv_len,
"Unknown TLV (%u)", tlv_type);
rsvp_ifid_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset + tlv_off, 2,
"Type: %u (Unknown)", tlv_type);
proto_tree_add_text(rsvp_ifid_subtree,
tvb, offset + tlv_off + 2, 2,
"Length: %u",
tvb_get_ntohs(tvb, offset + tlv_off + 2));
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset + tlv_off + 4,
tlv_len - 4,
"Data: %s",
tvb_bytes_to_str_punct(tvb, offset + tlv_off + 4, tlv_len - 4, ' '));
break;
}
padding = (4 - (tlv_len % 4)) % 4;
if (padding != 0)
proto_tree_add_text(rsvp_ifid_subtree, tvb, offset + tlv_off + tlv_len, padding, "Padding: %s",
tvb_bytes_to_str_punct(tvb, offset + tlv_off + tlv_len, padding, ' '));
tlv_off += tlv_len + padding;
}
}
static void
dissect_rsvp_hop(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Neighbor address: %s",
tvb_ip_to_str(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 4,
"Logical interface: %u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_set_text(ti, "HOP: IPv4, %s",
tvb_ip_to_str(tvb, offset2));
break;
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"Neighbor address: %s",
tvb_ip6_to_str(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+16, 4,
"Logical interface: 0x%08x",
tvb_get_ntohl(tvb, offset2+16));
break;
case 3:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 3 - IPv4 IF-ID");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Neighbor address: %s",
tvb_ip_to_str(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 4,
"Logical interface: %u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_set_text(ti, "HOP: IPv4 IF-ID. Control IPv4: %s. ",
tvb_ip_to_str(tvb, offset2));
dissect_rsvp_ifid_tlv(ti, rsvp_object_tree, tvb, offset+12, obj_length-12,
TREE(TT_HOP_SUBOBJ));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Refresh interval: %u ms (%u seconds)",
tvb_get_ntohl(tvb, offset2),
tvb_get_ntohl(tvb, offset2)/1000);
proto_item_set_text(ti, "TIME VALUES: %d ms",
tvb_get_ntohl(tvb, offset2));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(ti, tvb, offset, 2,
"Error value: %u - %s", error_val,
val_to_str_ext(error_val, rsvp_error_vals_ext_p, "Unknown (%d)"));
}
else if ((error_val & 0xc0) == 0x80) {
proto_tree_add_text(ti, tvb, offset, 2,
"Error value: %u - Organization specific subcode (%u)", error_val,
error_val);
}
else if ((error_val & 0xc0) == 0xc0) {
proto_tree_add_text(ti, tvb, offset, 2,
"Error value: %u - Service specific subcode (%u)", error_val,
error_val);
}
break;
case RSVP_ERROR_UNKNOWN_CLASS:
case RSVP_ERROR_UNKNOWN_C_TYPE:
error_class = error_val / 256;
error_ctype = error_val % 256;
proto_tree_add_text(ti, tvb, offset, 2, "Class: %u (%s) - CType: %u",
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
proto_tree_add_text(ti, tvb, offset, 2, "Error value: %u - %s", error_val,
val_to_str_ext(error_val, rsvp_error_vals_ext_p, "Unknown (%d)"));
break;
default:
proto_tree_add_text(ti, tvb, offset, 2, "Error value: %u", error_val);
break;
}
return error_val;
}
static void
dissect_rsvp_error(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int offset3;
guint8 error_flags;
guint8 error_code;
guint16 error_val;
proto_tree *ti2, *rsvp_error_subtree;
switch(type) {
case 1: {
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Error node: %s",
tvb_ip_to_str(tvb, offset2));
offset3 = offset2+4;
break;
}
case 2: {
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"Error node: %s",
tvb_ip6_to_str(tvb, offset2));
offset3 = offset2+16;
break;
}
case 3: {
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 3 - IPv4 IF-ID");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Error node: %s",
tvb_ip_to_str(tvb, offset2));
offset3 = offset2+4;
break;
}
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
return;
}
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
(error_flags & (1<<2)) ? "Path-State-Removed" : "",
(error_flags & (1<<1)) ? "NotGuilty" : "",
(error_flags & (1<<0)) ? "InPlace" : "");
error_code = tvb_get_guint8(tvb, offset3+1);
proto_tree_add_text(rsvp_object_tree, tvb, offset3+1, 1,
"Error code: %u - %s", error_code,
val_to_str_ext(error_code, &rsvp_error_codes_ext, "Unknown (%d)"));
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
dissect_rsvp_ifid_tlv(ti, rsvp_object_tree, tvb, offset+12, obj_length-12,
TREE(TT_ERROR_SUBOBJ));
break;
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
while (mylen > 0) {
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"IPv4 Address: %s",
tvb_ip_to_str(tvb, offset2));
offset2 += 4;
mylen -= 4;
}
break;
}
case 2: {
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
while (mylen > 0) {
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"IPv6 Address: %s",
tvb_ip6_to_str(tvb, offset2));
offset2 += 16;
mylen -= 16;
}
break;
}
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, mylen,
"Data (%d bytes)", mylen);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Flags: 0x%02x",
tvb_get_guint8(tvb, offset2));
style = tvb_get_ntoh24(tvb, offset2+1);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+1,
3, "Style: 0x%06X - %s", style,
val_to_str_const(style, style_vals, "Unknown"));
proto_item_set_text(ti, "STYLE: %s (%d)",
val_to_str_const(style, style_vals, "Unknown"),
style);
break;
}
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Receiver address: %s",
tvb_ip_to_str(tvb, offset2));
proto_item_set_text(ti, "CONFIRM: Receiver %s",
tvb_ip_to_str(tvb, offset2));
break;
}
case 2: {
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"Receiver address: %s",
tvb_ip6_to_str(tvb, offset2));
break;
}
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_PORT],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&rsvph->source, AT_IPv4, tvb, offset2, 4);
rsvph->udp_source_port = tvb_get_ntohs(tvb, offset2+6);
break;
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"Source address: %s",
tvb_ip6_to_str(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+18, 2,
"Source port: %u",
tvb_get_ntohs(tvb, offset2+18));
break;
case 7:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 7 - IPv4 LSP");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_LSP_ID],
tvb, offset2+6, 2, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&rsvph->source, AT_IPv4, tvb, offset2, 4);
rsvph->udp_source_port = tvb_get_ntohs(tvb, offset2+6);
break;
case 9:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 9 - IPv4 Aggregate");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_SENDER_IP],
tvb, offset2, 4, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&rsvph->source, AT_IPv4, tvb, offset2, 4);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_eth_tspec_tlv(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int tlv_length,
int subtree_type)
{
int tlv_off;
guint16 tlv_type;
int tlv_len;
guint8 profile;
proto_tree *rsvp_ethspec_subtree, *ethspec_profile_subtree, *ti2, *ti3;
for (tlv_off = 0; tlv_off < tlv_length; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || (tlv_off+tlv_len > tlv_length)) {
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off+2, 2,
"Invalid length");
return;
}
switch(tlv_type) {
case 0:
case 1:
case 255:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"RESERVED (RFC6003)");
rsvp_ethspec_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off, 2,
"Type: %u (RESERVED)", tlv_type);
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u", tlv_len);
break;
case 2:
case 129:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"Ethernet Bandwidth Profile TLV: CIR=%.10g, CBS=%.10g, "
"EIR=%.10g, EBS=%.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8),
tvb_get_ntohieee_float(tvb, offset+tlv_off+12),
tvb_get_ntohieee_float(tvb, offset+tlv_off+16),
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
rsvp_ethspec_subtree = proto_item_add_subtree(ti2, subtree_type);
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off, 2,
"Type: %u - Ethernet Bandwidth Profile", tlv_type);
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u", tlv_len);
profile = tvb_get_guint8(tvb, offset+tlv_off+4);
ti3 = proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+4, 1,
"Profile: 0x%02x", profile);
ethspec_profile_subtree = proto_item_add_subtree(ti3, TREE(TT_ETHSPEC_SUBTREE));
proto_tree_add_item(ethspec_profile_subtree, hf_rsvp_eth_tspec_tlv_color_mode,
tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ethspec_profile_subtree, hf_rsvp_eth_tspec_tlv_coupling_flag,
tvb, offset+tlv_off+4, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti3, " %s %s",
(profile & (1<<1)) ? "CM" : "",
(profile & (1<<0)) ? "CF" : "");
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+5, 1,
"Index: %x", tvb_get_guint8(tvb, offset+tlv_off+5));
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+6, 2,
"Reserved: %x", tvb_get_ntohs(tvb, offset+tlv_off+6));
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+8, 4, "CIR: %.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8));
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+12, 4, "CBS: %.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+12));
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+16, 4, "EIR: %.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+16));
proto_tree_add_text(rsvp_ethspec_subtree, tvb, offset+tlv_off+20, 4, "EBS: %.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
proto_item_append_text(ti, "ETH profile: CIR=%.10g, CBS=%.10g, EIR=%.10g, "
"EBS=%.10g",
tvb_get_ntohieee_float(tvb, offset+tlv_off+8),
tvb_get_ntohieee_float(tvb, offset+tlv_off+12),
tvb_get_ntohieee_float(tvb, offset+tlv_off+16),
tvb_get_ntohieee_float(tvb, offset+tlv_off+20));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off, 2,
"Unknown TLV: %u", tlv_type);
break;
}
tlv_off += tlv_len;
}
}
static void
dissect_rsvp_tspec(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen;
proto_tree *tspec_tree, *ti2;
guint8 signal_type;
guint16 switch_gran;
mylen = obj_length - 4;
switch(type) {
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - Integrated Services");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Message format version: %u",
tvb_get_guint8(tvb, offset2)>>4);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Data length: %u words, not including header",
tvb_get_ntohs(tvb, offset2+2));
mylen -= 4;
offset2 += 4;
proto_item_set_text(ti, "SENDER TSPEC: IntServ, ");
while (mylen > 0) {
guint8 service_num;
guint8 param_id;
guint param_len;
guint param_len_processed;
guint length;
service_num = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Service header: %u - %s",
service_num,
val_to_str_const(service_num, qos_vals, "Unknown"));
length = tvb_get_ntohs(tvb, offset2+2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Length of service %u data: %u words, "
"not including header",
service_num, length);
mylen -= 4;
offset2 += 4;
param_len_processed = 0;
while (param_len_processed < length) {
param_id = tvb_get_guint8(tvb, offset2);
param_len = tvb_get_ntohs(tvb, offset2+2) + 1;
if (param_len < 1)
THROW(ReportedBoundsError);
switch(param_id) {
case 127:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2, param_len*4,
"Token Bucket TSpec: ");
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_text(tspec_tree, tvb, offset2, 1,
"Parameter %u - %s",
param_id,
val_to_str_ext_const(param_id, &svc_vals_ext, "Unknown"));
proto_tree_add_text(tspec_tree, tvb, offset2+1, 1,
"Parameter %u flags: 0x%02x",
param_id,
tvb_get_guint8(tvb, offset2+1));
proto_tree_add_text(tspec_tree, tvb, offset2+2, 2,
"Parameter %u data length: %u words, "
"not including header",
param_id,
tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(tspec_tree, tvb, offset2+4, 4,
"Token bucket rate: %.10g",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_tree_add_text(tspec_tree, tvb, offset2+8, 4,
"Token bucket size: %.10g",
tvb_get_ntohieee_float(tvb, offset2+8));
proto_tree_add_text(tspec_tree, tvb, offset2+12, 4,
"Peak data rate: %.10g",
tvb_get_ntohieee_float(tvb, offset2+12));
proto_tree_add_text(tspec_tree, tvb, offset2+16, 4,
"Minimum policed unit [m]: %u",
tvb_get_ntohl(tvb, offset2+16));
proto_tree_add_text(tspec_tree, tvb, offset2+20, 4,
"Maximum packet size [M]: %u",
tvb_get_ntohl(tvb, offset2+20));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2, param_len*4,
"Null Service TSpec: ");
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_text(tspec_tree, tvb, offset2, 1,
"Parameter %u - %s",
param_id,
val_to_str_ext_const(param_id, &svc_vals_ext, "Unknown"));
proto_tree_add_text(tspec_tree, tvb, offset2+1, 1,
"Parameter %u flags: %x",
param_id,
tvb_get_guint8(tvb, offset2+1));
proto_tree_add_text(tspec_tree, tvb, offset2+2, 2,
"Parameter %u data length: %u words, "
"not including header",
param_id,
tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(tspec_tree, tvb, offset2+4, 4,
"Maximum packet size [M]: %u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti, "Null Service. M=%u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti2, "Max pkt size=%u",
tvb_get_ntohl(tvb, offset2+4));
break;
case 126:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2, param_len*4,
"Compression Hint: ");
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_text(tspec_tree, tvb, offset2, 1,
"Parameter %u - %s",
param_id,
val_to_str_ext_const(param_id, &svc_vals_ext, "Unknown"));
proto_tree_add_text(tspec_tree, tvb, offset2+1, 1,
"Parameter %u flags: %x",
param_id,
tvb_get_guint8(tvb, offset2+1));
proto_tree_add_text(tspec_tree, tvb, offset2+2, 2,
"Parameter %u data length: %u words, "
"not including header",
param_id,
tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(tspec_tree, tvb, offset2+4, 4,
"Hint: %u",
tvb_get_ntohl(tvb, offset2+4));
proto_tree_add_text(tspec_tree, tvb, offset2+4, 4,
"Compression Factor: %u",
tvb_get_ntohl(tvb, offset2+8));
proto_item_append_text(ti, "Compression Hint. Hint=%u, Factor=%u",
tvb_get_ntohl(tvb, offset2+4),
tvb_get_ntohl(tvb, offset2+8));
proto_item_append_text(ti2, "Hint=%u, Factor=%u",
tvb_get_ntohl(tvb, offset2+4),
tvb_get_ntohl(tvb, offset2+8));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset2, param_len*4,
"Unknown parameter %d, %d words",
param_id, param_len);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 4 - SONET/SDH");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Signal Type: %d - %s", signal_type,
val_to_str_ext_const(signal_type,
&gmpls_sonet_signal_type_str_ext, "Unknown"));
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+1, 1,
"Requested Concatenation (RCC): %d", tvb_get_guint8(tvb, offset2+1));
tspec_tree = proto_item_add_subtree(ti2, TREE(TT_TSPEC_SUBTREE));
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_standard_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tspec_tree, hf_rsvp_sender_tspec_arbitrary_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Number of Contiguous Components (NCC): %d", tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 2,
"Number of Virtual Components (NVC): %d", tvb_get_ntohs(tvb, offset2+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+6, 2,
"Multiplier (MT): %d", tvb_get_ntohs(tvb, offset2+6));
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 4,
"Transparency (T): 0x%0x", tvb_get_ntohl(tvb, offset2+8));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset2+12, 4,
"Profile (P): %d", tvb_get_ntohl(tvb, offset2+12));
proto_item_append_text(ti, "Signal [%s], RCC %d, NCC %d, NVC %d, MT %d, Transparency %d, Profile %d",
val_to_str_ext_const(signal_type, &gmpls_sonet_signal_type_str_ext, "Unknown"),
tvb_get_guint8(tvb, offset2+1), tvb_get_ntohs(tvb, offset2+2),
tvb_get_ntohs(tvb, offset2+4), tvb_get_ntohs(tvb, offset2+6),
tvb_get_ntohl(tvb, offset2+8), tvb_get_ntohl(tvb, offset2+12));
break;
case 5:
proto_item_set_text(ti, "SENDER TSPEC: G.709, ");
proto_tree_add_text(rsvp_object_tree, tvb, offset + 3, 1,
"C-type: 5 - G.709");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Signal Type: %d - %s", signal_type,
rval_to_str(signal_type,
gmpls_g709_signal_type_rvals,
"Unknown"));
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 2, 2,
"Number of Multiplexed Components (NMC): %d",
tvb_get_ntohs(tvb, offset2 + 2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 4, 2,
"Number of Virtual Components (NVC): %d",
tvb_get_ntohs(tvb, offset2 + 4));
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 6, 2,
"Multiplier (MT): %d",
tvb_get_ntohs(tvb, offset2 + 6));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 6 - Ethernet");
switch_gran = tvb_get_ntohs(tvb, offset2);
if (switch_gran == 0)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: 0 - Provided in signaling");
else if (switch_gran == 1)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: 1 - Ethernet port");
else if (switch_gran == 2)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: 2 - Ethernet frame");
else
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: %u - ???", switch_gran);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"MTU: %u", tvb_get_ntohs(tvb, offset2+2));
dissect_rsvp_eth_tspec_tlv(ti, rsvp_object_tree, tvb, offset+8, obj_length-8,
TREE(TT_TSPEC_SUBTREE));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_flowspec(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen, signal_type;
proto_tree *flowspec_tree, *ti2;
proto_item *item;
guint16 switch_gran;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u", type);
mylen = obj_length - 4;
switch(type) {
case 2:
if (mylen < 4) {
item = proto_tree_add_text(rsvp_object_tree, tvb, 0, 0,
"Object length %u < 8", obj_length);
PROTO_ITEM_SET_GENERATED(item);
return;
}
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Message format version: %u",
tvb_get_guint8(tvb, offset2)>>4);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Data length: %u words, not including header",
tvb_get_ntohs(tvb, offset2+2));
proto_item_set_text(ti, "FLOWSPEC: ");
mylen -= 4;
offset2+= 4;
while (mylen > 0) {
guint8 service_num;
guint length;
guint8 param_id;
guint param_len;
guint param_len_processed;
if (mylen < 4) {
item = proto_tree_add_text(rsvp_object_tree, tvb, 0, 0,
"Object length %u not large enough",
obj_length);
PROTO_ITEM_SET_GENERATED(item);
return;
}
service_num = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Service header: %u - %s",
service_num,
val_to_str_ext_const(service_num, &intsrv_services_str_ext, "Unknown"));
length = tvb_get_ntohs(tvb, offset2+2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Length of service %u data: %u words, "
"not including header",
service_num,
length);
mylen -= 4;
offset2 += 4;
proto_item_append_text(ti, "%s: ",
val_to_str_ext(service_num, &intsrv_services_str_ext,
"Unknown (%d)"));
param_len_processed = 0;
while (param_len_processed < length) {
param_id = tvb_get_guint8(tvb, offset2);
param_len = tvb_get_ntohs(tvb, offset2+2) + 1;
if (param_len < 1)
THROW(ReportedBoundsError);
switch(param_id) {
case 127:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2, param_len*4,
"Token Bucket: ");
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_text(flowspec_tree, tvb, offset2, 1,
"Parameter %u - %s",
param_id,
val_to_str_ext_const(param_id, &svc_vals_ext, "Unknown"));
proto_tree_add_text(flowspec_tree, tvb, offset2+1, 1,
"Parameter %u flags: 0x%02x",
param_id,
tvb_get_guint8(tvb, offset2+1));
proto_tree_add_text(flowspec_tree, tvb, offset2+2, 2,
"Parameter %u data length: %u words, "
"not including header",
param_id,
tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(flowspec_tree, tvb, offset2+4, 4,
"Token bucket rate: %.10g",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_tree_add_text(flowspec_tree, tvb, offset2+8, 4,
"Token bucket size: %.10g",
tvb_get_ntohieee_float(tvb, offset2+8));
proto_tree_add_text(flowspec_tree, tvb, offset2+12, 4,
"Peak data rate: %.10g",
tvb_get_ntohieee_float(tvb, offset2+12));
proto_tree_add_text(flowspec_tree, tvb, offset2+16, 4,
"Minimum policed unit [m]: %u",
tvb_get_ntohl(tvb, offset2+16));
proto_tree_add_text(flowspec_tree, tvb, offset2+20, 4,
"Maximum packet size [M]: %u",
tvb_get_ntohl(tvb, offset2+20));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2, param_len*4,
"Guaranteed-Rate RSpec: ");
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_text(flowspec_tree, tvb, offset2, 1,
"Parameter %u - %s",
param_id,
val_to_str_ext_const(param_id, &svc_vals_ext, "Unknown"));
proto_tree_add_text(flowspec_tree, tvb, offset2+1, 1,
"Parameter %u flags: %x",
param_id,
tvb_get_guint8(tvb, offset2+1));
proto_tree_add_text(flowspec_tree, tvb, offset2+2, 2,
"Parameter %u data length: %u words, "
"not including header",
param_id,
tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(flowspec_tree, tvb, offset2+4, 4,
"Rate: %.10g",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_tree_add_text(flowspec_tree, tvb, offset2+8, 4,
"Slack term: %u",
tvb_get_ntohl(tvb, offset2+8));
proto_item_append_text(ti, "RSpec, %.10g bytes/sec. ",
tvb_get_ntohieee_float(tvb, offset2+4));
proto_item_append_text(ti2, "R=%.10g, s=%u",
tvb_get_ntohieee_float(tvb, offset2+4),
tvb_get_ntohl(tvb, offset2+8));
break;
case 128:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2, param_len*4,
"Null Service Flowspec: ");
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_text(flowspec_tree, tvb, offset2, 1,
"Parameter %u - %s",
param_id,
val_to_str_ext_const(param_id, &svc_vals_ext, "Unknown"));
proto_tree_add_text(flowspec_tree, tvb, offset2+1, 1,
"Parameter %u flags: %x",
param_id,
tvb_get_guint8(tvb, offset2+1));
proto_tree_add_text(flowspec_tree, tvb, offset2+2, 2,
"Parameter %u data length: %u words, "
"not including header",
param_id,
tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(flowspec_tree, tvb, offset2+4, 4,
"Maximum packet size [M]: %u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti, "Null Service. M=%u",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti2, "Max pkt size=%u",
tvb_get_ntohl(tvb, offset2+4));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset2, param_len*4,
"Unknown parameter %d, %d words",
param_id, param_len);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 4 - SONET/SDH");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Signal Type: %d - %s", signal_type,
val_to_str_ext_const(signal_type,
&gmpls_sonet_signal_type_str_ext, "Unknown"));
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+1, 1,
"Requested Concatenation (RCC): %d", tvb_get_guint8(tvb, offset2+1));
flowspec_tree = proto_item_add_subtree(ti2, TREE(TT_FLOWSPEC_SUBTREE));
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_standard_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flowspec_tree, hf_rsvp_flowspec_arbitrary_contiguous_concatenation,
tvb, offset2+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Number of Contiguous Components (NCC): %d", tvb_get_ntohs(tvb, offset2+2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 2,
"Number of Virtual Components (NVC): %d", tvb_get_ntohs(tvb, offset2+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+6, 2,
"Multiplier (MT): %d", tvb_get_ntohs(tvb, offset2+6));
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 4,
"Transparency (T): 0x%0x", tvb_get_ntohl(tvb, offset2+8));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset2+12, 4,
"Profile (P): %d", tvb_get_ntohl(tvb, offset2+12));
proto_item_append_text(ti, "Signal [%s], RCC %d, NCC %d, NVC %d, MT %d, Transparency %d, Profile %d",
val_to_str_ext_const(signal_type, &gmpls_sonet_signal_type_str_ext, "Unknown"),
tvb_get_guint8(tvb, offset2+1), tvb_get_ntohs(tvb, offset2+2),
tvb_get_ntohs(tvb, offset2+4), tvb_get_ntohs(tvb, offset2+6),
tvb_get_ntohl(tvb, offset2+8), tvb_get_ntohl(tvb, offset2+12));
break;
case 5:
proto_item_set_text(ti, "FLOWSPEC: G.709, ");
proto_tree_add_text(rsvp_object_tree, tvb, offset + 3, 1,
"C-type: 5 - G.709");
signal_type = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Signal Type: %d - %s", signal_type,
rval_to_str(signal_type,
gmpls_g709_signal_type_rvals,
"Unknown"));
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 2, 2,
"Number of Multiplexed Components (NMC): %d",
tvb_get_ntohs(tvb, offset2 + 2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 4, 2,
"Number of Virtual Components (NVC): %d",
tvb_get_ntohs(tvb, offset2 + 4));
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 6, 2,
"Multiplier (MT): %d",
tvb_get_ntohs(tvb, offset2 + 6));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 6 - Ethernet");
switch_gran = tvb_get_ntohs(tvb, offset2);
if (switch_gran == 0)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: 0 - Provided in signaling");
else if (switch_gran == 1)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: 1 - Ethernet port");
else if (switch_gran == 2)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: 2 - Ethernet frame");
else
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 2,
"Switching granularity: %u - ???", switch_gran);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"MTU: %u", tvb_get_ntohs(tvb, offset2+2));
dissect_rsvp_eth_tspec_tlv(ti, rsvp_object_tree, tvb, offset+8, obj_length-8,
TREE(TT_FLOWSPEC_SUBTREE));
break;
default:
break;
}
}
static void
dissect_rsvp_adspec(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
int mylen, i;
proto_tree *adspec_tree;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u", type);
mylen = obj_length - 4;
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Message format version: %u",
tvb_get_guint8(tvb, offset2)>>4);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"Data length: %u words, not including header",
tvb_get_ntohs(tvb, offset2+2));
mylen -= 4;
offset2 += 4;
while (mylen > 0) {
guint8 service_num;
guint8 break_bit;
guint length;
const char *str;
service_num = tvb_get_guint8(tvb, offset2);
str = val_to_str_ext_const(service_num, &intsrv_services_str_ext, "Unknown");
break_bit = tvb_get_guint8(tvb, offset2+1);
length = tvb_get_ntohs(tvb, offset2+2);
ti = proto_tree_add_text(rsvp_object_tree, tvb, offset2,
(length+1)*4, "%s",
str);
adspec_tree = proto_item_add_subtree(ti,
TREE(TT_ADSPEC_SUBTREE));
proto_tree_add_text(adspec_tree, tvb, offset2, 1,
"Service header %u - %s",
service_num, str);
proto_tree_add_text(adspec_tree, tvb, offset2+1, 1,
(break_bit&0x80)?
"Break bit set":"Break bit not set");
proto_tree_add_text(adspec_tree, tvb, offset2+2, 2,
"Data length: %u words, not including header",
length);
mylen -= 4;
offset2 += 4;
i = length*4;
while (i > 0) {
guint8 id;
guint phdr_length;
id = tvb_get_guint8(tvb, offset2);
phdr_length = tvb_get_ntohs(tvb, offset2+2);
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
proto_tree_add_text(adspec_tree, tvb, offset2,
(phdr_length+1)<<2,
"%s - %u (type %u, length %u)",
str,
tvb_get_ntohl(tvb, offset2+4),
id, phdr_length);
break;
case 6:
proto_tree_add_text(adspec_tree, tvb, offset2,
(phdr_length+1)<<2,
"%s - %.10g (type %u, length %u)",
str,
tvb_get_ntohieee_float(tvb, offset2+4),
id, phdr_length);
break;
default:
proto_tree_add_text(adspec_tree, tvb, offset2,
(phdr_length+1)<<2,
"%s (type %u, length %u)",
str,
id, phdr_length);
break;
}
} else {
proto_tree_add_text(adspec_tree, tvb, offset2,
(phdr_length+1)<<2,
"Unknown (type %u, length %u)",
id, phdr_length);
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
int flags;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u", type);
flags = tvb_get_guint8(tvb, offset2);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Flags: 0x%02x", flags);
rsvp_integ_flags_tree = proto_item_add_subtree(ti2, TREE(TT_INTEGRITY_FLAGS));
proto_tree_add_item(rsvp_integ_flags_tree, hf_rsvp_integrity_flags_handshake,
tvb, offset2, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 6,
"Key Identifier: %s", tvb_bytes_to_str(tvb, offset2+2, 6));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 8,
"Sequence Number: %" G_GINT64_MODIFIER "u", tvb_get_ntoh64(tvb, offset2+8));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+16, obj_length - 20,
"Hash: %s", tvb_bytes_to_str(tvb, offset2+16, obj_length - 20));
}
static void
dissect_rsvp_policy(proto_item *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
int offset2 = offset + 4;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %d %s", type,
val_to_str_ext_const(type, &lab_req_type_str_ext, "Unknown"));
switch(type) {
case 1: {
unsigned short l3pid = tvb_get_ntohs(tvb, offset2+2);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"L3PID: %s (0x%04x)",
val_to_str_const(l3pid, etype_vals, "Unknown"),
l3pid);
proto_item_set_text(ti, "LABEL REQUEST: Basic: L3PID: %s (0x%04x)",
val_to_str_const(l3pid, etype_vals, "Unknown"),
l3pid);
break;
}
case 2: {
unsigned short l3pid = tvb_get_ntohs(tvb, offset2+2);
unsigned short min_vpi, min_vci, max_vpi, max_vci;
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"L3PID: %s (0x%04x)",
val_to_str_const(l3pid, etype_vals, "Unknown"),
l3pid);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 1,
"M: %s Merge in Data Plane",
(tvb_get_guint8(tvb, offset2+4) & 0x80) ?
"1: Can" : "0: Cannot");
min_vpi = tvb_get_ntohs(tvb, offset2+4) & 0x7f;
min_vci = tvb_get_ntohs(tvb, offset2+6);
max_vpi = tvb_get_ntohs(tvb, offset2+8) & 0x7f;
max_vci = tvb_get_ntohs(tvb, offset2+10);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 2,
"Min VPI: %d", min_vpi);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+6, 2,
"Min VCI: %d", min_vci);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 2,
"Max VPI: %d", max_vpi);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+10, 2,
"Max VCI: %d", max_vci);
proto_item_set_text(ti, "LABEL REQUEST: ATM: L3PID: %s (0x%04x). VPI/VCI: Min: %d/%d, Max: %d/%d. %s Merge. ",
val_to_str_const(l3pid, etype_vals, "Unknown"), l3pid,
min_vpi, min_vci, max_vpi, max_vci,
(tvb_get_guint8(tvb, offset2+4) & 0x80) ? "Can" : "Cannot");
break;
}
case 3: {
guint16 l3pid = tvb_get_ntohs(tvb, offset2+2);
guint32 min_dlci, max_dlci, dlci_len, dlci_len_code;
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"L3PID: %s (0x%04x)",
val_to_str_const(l3pid, etype_vals, "Unknown"),
l3pid);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 2,
"DLCI Length: %s (%d)",
(dlci_len==10) ? "10 bits" :
(dlci_len==23) ? "23 bits" :
"INVALID", dlci_len_code);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+5, 3,
"Min DLCI: %d", min_dlci);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 2,
"Max DLCI: %d", max_dlci);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"LSP Encoding Type: %s",
rval_to_str(lsp_enc, gmpls_lsp_enc_rvals, "Unknown (%d)"));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+1, 1,
"Switching Type: %s",
rval_to_str(tvb_get_guint8(tvb,offset2+1),
gmpls_switching_type_rvals, "Unknown (%d)"));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 2,
"G-PID: %s (0x%0x)",
rval_to_str(l3pid, gmpls_gpid_rvals,
val_to_str(l3pid, etype_vals,
"Unknown G-PID(0x%04x)")),
l3pid);
proto_item_set_text(ti, "LABEL REQUEST: Generalized: LSP Encoding=%s, "
"Switching Type=%s, G-PID=%s ",
rval_to_str(lsp_enc, gmpls_lsp_enc_rvals, "Unknown (%d)"),
rval_to_str(tvb_get_guint8(tvb,offset2+1),
gmpls_switching_type_rvals, "Unknown (%d)"),
rval_to_str(l3pid, gmpls_gpid_rvals,
val_to_str(l3pid, etype_vals,
"Unknown (0x%04x)")));
break;
}
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
guint8 grid = ((tvb_get_guint8(tvb, offset) & 0xE0) >> 5);
guint8 cs = ((tvb_get_guint8(tvb, offset) & 0x1E) >> 1);
gint16 n = tvb_get_ntohs(tvb, offset + 2);
if (grid == 1) {
cs_thz =
cs == 1 ? 0.1f :
cs == 2 ? 0.05f :
cs == 3 ? 0.025f :
cs == 4 ? 0.0125f :
0.0f;
freq = 193.1f + (n * cs_thz);
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4,
"Wavelength Label: "
"grid=%s, "
"channel spacing=%s, "
"n=%d, "
"freq=%.2fTHz",
"DWDM",
cs == 1 ? "100GHz" :
cs == 2 ? "50GHz" :
cs == 3 ? "25GHz" :
cs == 4 ? "12.5GHz" :
"unknown",
n,
freq);
proto_item_append_text(ti, ": Wavelength: "
"grid=%s, "
"channel spacing=%s, "
"n=%d, "
"freq=%.2fTHz",
"DWDM",
cs == 1 ? "100GHz" :
cs == 2 ? "50GHz" :
cs == 3 ? "25GHz" :
cs == 4 ? "12.5GHz" :
"unknown",
n,
freq);
} else if (grid == 2) {
wavelength = 1471 + (n * 20);
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4,
"Wavelength Label: "
"grid=%s, "
"channel spacing=%s, "
"n=%d, "
"wavelength=%unm",
"CWDM",
cs == 1 ? "20nm" :
"unknown",
n,
wavelength);
proto_item_append_text(ti, ": Wavelength: "
"grid=%s, "
"channel spacing=%s, "
"n=%d, "
"wavelength=%unm",
"CWDM",
cs == 1 ? "20nm" :
"unknown",
n,
wavelength);
} else {
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4,
"Wavelength Label: "
"grid=%u, "
"channel spacing=%u, "
"n=%d",
grid, cs, n);
proto_item_append_text(ti, ": Wavelength: "
"grid=%u, "
"channel spacing=%u, "
"n=%d",
grid, cs, n);
}
return;
}
static void
dissect_glabel_sdh(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset)
{
guint16 s = tvb_get_ntohs(tvb, offset);
guint8 u = ((tvb_get_guint8(tvb, offset + 2) & 0xF0) >> 4);
guint8 k = ((tvb_get_guint8(tvb, offset + 2) & 0x0F) >> 0);
guint8 l = ((tvb_get_guint8(tvb, offset + 3) & 0xF0) >> 4);
guint8 m = ((tvb_get_guint8(tvb, offset + 3) & 0x0F) >> 0);
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4,
"SONET/SDH Label: "
"S=%u, "
"U=%u, "
"K=%u, "
"L=%u, "
"M=%u",
s, u, k, l, m);
proto_item_append_text(ti, ": SONET/SDH: "
"S=%u, "
"U=%u, "
"K=%u, "
"L=%u, "
"M=%u",
s, u, k, l, m);
}
static void
dissect_glabel_g709(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset)
{
guint8 t2 = ((tvb_get_guint8(tvb, offset + 3) & 0x0E) >> 1);
guint8 t1 = ((tvb_get_guint8(tvb, offset + 3) & 0x01) >> 0);
guint8 t3 = ((tvb_get_guint8(tvb, offset + 2) & 0x03) << 4);
t3 |= ((tvb_get_guint8(tvb, offset + 3) & 0xF0) >> 4);
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4,
"G.709 ODUk Label: "
"t3=%u, "
"t2=%u, "
"t1=%u",
t3, t2, t1);
proto_item_append_text(ti, ": G.709 ODUk: "
"t3=%u, "
"t2=%u, "
"t1=%u",
t3, t2, t1);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 (Packet Label)");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Label: %u",
tvb_get_ntohl(tvb, offset2));
proto_item_set_text(ti, "%s: %u", name,
tvb_get_ntohl(tvb, offset2));
break;
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 (Generalized Label)");
if (rsvp_generalized_label_option == 1) {
proto_item_set_text(ti, "%s: Generalized: ", name);
for (i = 0; i < mylen; i += 4) {
proto_tree_add_text(rsvp_object_tree, tvb, offset2+i, 4,
"Generalized Label: %u (0x%x)",
tvb_get_ntohl(tvb, offset2+i),
tvb_get_ntohl(tvb, offset2+i));
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
}
break;
case 4:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 4 (Generalized Channel_set)");
proto_item_append_text(ti, ": Generalized Channel_set");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, mylen,
"Data (%d bytes)", mylen);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, mylen,
"Data (%d bytes)", mylen);
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
static const value_string action_type_vals[] = {
{ 0, "Inclusive list"},
{ 1, "Exclusive list"},
{ 2, "Inclusive range"},
{ 3, "Exclusive range"},
{ 0, NULL}
};
static value_string_ext action_type_vals_ext = VALUE_STRING_EXT_INIT(action_type_vals);
len = obj_length - 8;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1, "C-type: %u", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 1, "Action: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset+4),
&action_type_vals_ext, "Unknown (%u)"));
proto_item_append_text(ti, ": %s",
val_to_str_ext(tvb_get_guint8(tvb, offset+4),
&action_type_vals_ext, "Unknown (%u)"));
label_type = tvb_get_guint8 (tvb, offset+7);
proto_tree_add_text(rsvp_object_tree, tvb, offset+7, 1, "Label type: %s",
(label_type == 1) ? "Packet Label" : "Generalized Label");
proto_item_append_text(ti, ", %s",
(label_type == 1) ? "Packet Label: " : "Generalized Label: ");
for (i = 0; i < len/4; i++) {
proto_tree_add_text(rsvp_object_tree, tvb, offset2+i*4, 4,
"Subchannel %u: %u (0x%x)", i+1,
tvb_get_ntohl(tvb, offset2+i*4),
tvb_get_ntohl(tvb, offset2+i*4));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u - IPv4 LSP (%sResource Affinities)",
type, (type == 1) ? "" : "No ");
if (type == 1) {
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Exclude-Any: 0x%0x", tvb_get_ntohl(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 4,
"Include-Any: 0x%0x", tvb_get_ntohl(tvb, offset2+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+8, 4,
"Include-All: 0x%0x", tvb_get_ntohl(tvb, offset2+8));
offset2 = offset2+12;
}
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1,
"Setup priority: %u",
tvb_get_guint8(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+1, 1,
"Hold priority: %u",
tvb_get_guint8(tvb, offset2+1));
flags = tvb_get_guint8(tvb, offset2+2);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+2, 1,
"Flags: 0x%02x", flags);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset2+3, 1,
"Name length: %u", name_len);
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, name_len,
"Name: %s",
tvb_format_text(tvb, offset2+4, name_len));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_ero_rro_subobjects(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length, int rsvp_class)
{
int i, j, k, l, flags;
proto_tree *ti2, *rsvp_ro_subtree, *rsvp_rro_flags_subtree;
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
j = tvb_get_guint8(tvb, offset+l) & 0x7f;
switch(j) {
case 1:
k = tvb_get_guint8(tvb, offset+l) & 0x80;
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 8,
"IPv4 Subobject - %s%s",
tvb_ip_to_str(tvb, offset+l+2),
rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE ?
(k ? ", Loose" : ", Strict") : "");
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
k ? "Loose Hop " : "Strict Hop");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 1 (IPv4)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 4,
"IPv4 hop: %s",
tvb_ip_to_str(tvb, offset+l+2));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+6, 1,
"Prefix length: %u",
tvb_get_guint8(tvb, offset+l+6));
if (i < 4) {
proto_item_append_text(ti, "IPv4 %s%s",
tvb_ip_to_str(tvb, offset+l+2),
k ? " [L]" : "");
}
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+7);
if (flags&0x10) {
proto_item_append_text(ti, " (Node-id)");
proto_item_append_text(ti2, " (Node-id)");
}
if (flags&0x01) proto_item_append_text(ti2, ", Local Protection Available");
if (flags&0x02) proto_item_append_text(ti2, ", Local Protection In Use");
if (flags&0x04) proto_item_append_text(ti2, ", Backup BW Avail");
if (flags&0x08) proto_item_append_text(ti2, ", Backup is Next-Next-Hop");
ti2 = proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+7, 1,
"Flags: 0x%02x", flags);
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 20,
"IPv6 Subobject");
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
k = tvb_get_guint8(tvb, offset+l) & 0x80;
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
k ? "Loose Hop " : "Strict Hop");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 2 (IPv6)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 16,
"IPv6 hop: %s",
tvb_ip6_to_str(tvb, offset+l+2));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+18, 1,
"Prefix length: %u",
tvb_get_guint8(tvb, offset+l+18));
if (i < 4) {
proto_item_append_text(ti, "IPv6 [...]%s", k ? " [L]":"");
}
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+19);
if (flags&0x10) {
proto_item_append_text(ti, " (Node-id)");
proto_item_append_text(ti2, " (Node-id)");
}
if (flags&0x01) proto_item_append_text(ti2, ", Local Protection Available");
if (flags&0x02) proto_item_append_text(ti2, ", Local Protection In Use");
if (flags&0x04) proto_item_append_text(ti2, ", Backup BW Avail");
if (flags&0x08) proto_item_append_text(ti2, ", Backup is Next-Next-Hop");
ti2 = proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+19, 1,
"Flags: 0x%02x", flags);
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 8,
"Label Subobject - %d, %s",
tvb_get_ntohl(tvb, offset+l+4),
rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE ?
(k ? "Loose" : "Strict") : "");
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
k ? "Loose Hop " : "Strict Hop");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 3 (Label)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+2);
if (flags&0x01) proto_item_append_text(ti2, "The label will be understood if received on any interface");
ti2 = proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 1,
"Flags: 0x%02x", flags);
rsvp_rro_flags_subtree =
proto_item_add_subtree(ti2, TREE(TT_RECORD_ROUTE_SUBOBJ_FLAGS));
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_global_label,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+3, 1,
"C-Type: %u",
tvb_get_guint8(tvb, offset+l+3));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+4, 4,
"Label: %d",
tvb_get_ntohl(tvb, offset+l+4));
if (i < 4) {
proto_item_append_text(ti, "Label %d%s",
tvb_get_ntohl(tvb, offset+l+4),
k ? " [L]":"");
}
break;
case 4:
k = tvb_get_guint8(tvb, offset+l) & 0x80;
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 8,
"Unnumbered Interface-ID - %s, %d, %s",
tvb_ip_to_str(tvb, offset+l+4),
tvb_get_ntohl(tvb, offset+l+8),
rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE ?
(k ? "Loose" : "Strict") : "");
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
if (rsvp_class == RSVP_CLASS_EXPLICIT_ROUTE)
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
k ? "Loose Hop " : "Strict Hop");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 4 (Unnumbered Interface-ID)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) {
flags = tvb_get_guint8(tvb, offset+l+2);
if (flags&0x01) proto_item_append_text(ti2, ", Local Protection Available");
if (flags&0x02) proto_item_append_text(ti2, ", Local Protection In Use");
ti2 = proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 1,
"Flags: 0x%02x", flags);
rsvp_rro_flags_subtree =
proto_item_add_subtree(ti2, TREE(TT_RECORD_ROUTE_SUBOBJ_FLAGS));
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_avail,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_rro_flags_subtree, hf_rsvp_rro_flags_local_in_use,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+4, 4,
"Router-ID: %s",
tvb_ip_to_str(tvb, offset+l+4));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+8, 4,
"Interface-ID: %d",
tvb_get_ntohl(tvb, offset+l+8));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 4,
"Autonomous System %u",
k);
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 32 (Autonomous System Number)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 2,
"Autonomous System %u", k);
if (i < 4) {
proto_item_append_text(ti, "AS %d",
tvb_get_ntohs(tvb, offset+l+2));
}
break;
case 64:
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) goto defaultsub;
k = tvb_get_ntohs(tvb, offset+l+2);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 8,
"Path Key subobject - %s, %u",
tvb_ip_to_str(tvb, offset+l+4),
k);
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 64 (Path Key with IPv4 PCE-ID)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 2,
"Path Key: %u", k);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+4, 4,
"PCE-ID: %s",
tvb_ip_to_str(tvb, offset+l+4));
if (i < 4) {
proto_item_append_text(ti, "Path Key %d", k);
}
break;
case 65:
if (rsvp_class == RSVP_CLASS_RECORD_ROUTE) goto defaultsub;
k = tvb_get_ntohs(tvb, offset+l+2);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l, 8,
"Path Key subobject - %s, %u",
tvb_ip6_to_str(tvb, offset+l+4),
k);
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: 65 (Path Key with IPv6 PCE-ID)");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+2, 2,
"Path Key: %u", k);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+4, 4,
"PCE-ID: %s",
tvb_ip6_to_str(tvb, offset+l+4));
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
k = tvb_get_guint8(tvb, offset+l) & 0x80;
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset+l,
tvb_get_guint8(tvb, offset+l+1),
"Private Subobject: %d", j);
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
k ? "Loose Hop " : "Strict Hop");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: %u (Private)", j);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
private_so_len);
proto_tree_add_item(rsvp_ro_subtree,
hf_rsvp_filter[RSVPF_ENT_CODE],
tvb, offset+l+4, 4, ENC_BIG_ENDIAN);
if (private_so_len > 8) {
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+8,
private_so_len - 8,
"Data (%d bytes)",
private_so_len - 8);
}
}
break;
default:
defaultsub:
k = tvb_get_guint8(tvb, offset+l) & 0x80;
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset+l,
tvb_get_guint8(tvb, offset+l+1),
"Unknown subobject: %d", j);
rsvp_ro_subtree =
proto_item_add_subtree(ti2, tree_type);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
k ? "Loose Hop " : "Strict Hop");
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l, 1,
"Type: %u (Unknown)", j);
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset+l+1));
break;
}
if (tvb_get_guint8(tvb, offset+l+1) < 1) {
proto_tree_add_text(rsvp_ro_subtree, tvb, offset+l+1, 1,
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
dissect_rsvp_explicit_route(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class, int type)
{
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_item_set_text(ti, "EXPLICIT ROUTE: ");
dissect_rsvp_ero_rro_subobjects(ti, rsvp_object_tree, tvb,
offset + 4, obj_length, rsvp_class);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_record_route(proto_item *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class, int type)
{
proto_item_set_text(ti, "RECORD ROUTE: ");
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
dissect_rsvp_ero_rro_subobjects(ti, rsvp_object_tree, tvb,
offset + 4, obj_length, rsvp_class);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 1,
"Flags: %d", tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+5, 3,
"Epoch: %d", tvb_get_ntoh24(tvb, offset+5));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Message-ID: %d", tvb_get_ntohl(tvb, offset+8));
proto_item_set_text(ti, "MESSAGE-ID: %d %s",
tvb_get_ntohl(tvb, offset+8),
tvb_get_guint8(tvb, offset+4) & 1 ? "(Ack Desired)" : "");
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 1,
"Flags: %d", tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+5, 3,
"Epoch: %d", tvb_get_ntoh24(tvb, offset+5));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Message-ID: %d", tvb_get_ntohl(tvb, offset+8));
proto_item_set_text(ti, "MESSAGE-ID ACK: %d", tvb_get_ntohl(tvb, offset+8));
break;
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 1,
"Flags: %d", tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+5, 3,
"Epoch: %d", tvb_get_ntoh24(tvb, offset+5));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Message-ID: %d", tvb_get_ntohl(tvb, offset+8));
proto_item_set_text(ti, "MESSAGE-ID NACK: %d", tvb_get_ntohl(tvb, offset+8));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 1,
"Flags: %d", tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+5, 3,
"Epoch: %d", tvb_get_ntoh24(tvb, offset+5));
for (mylen = 8; mylen < obj_length; mylen += 4)
proto_tree_add_text(rsvp_object_tree, tvb, offset+mylen, 4,
"Message-ID: %d", tvb_get_ntohl(tvb, offset+mylen));
proto_item_set_text(ti, "MESSAGE-ID LIST: %d IDs",
(obj_length - 8)/4);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-Type: %d - HELLO %s object",
tvb_get_guint8 (tvb, offset+3),
type==1 ? "REQUEST" : "ACK");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 4,
"Source Instance: 0x%x",tvb_get_ntohl(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Destination Instance: 0x%x",tvb_get_ntohl(tvb, offset+8));
proto_item_append_text(ti, ": %s. Src Instance: 0x%0x. Dest Instance: 0x%0x. ",
type==1 ? "REQUEST" : "ACK",
tvb_get_ntohl(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-Type: %d - UNKNOWN", type);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
for (mylen = 4; mylen < obj_length; mylen += 4) {
proto_tree_add_text(rsvp_object_tree, tvb, offset+mylen+3, 1,
"DSCP: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset+mylen+3),
&dscp_vals_ext, "Unknown (%d)"));
proto_item_append_text(ti, "%d%s",
tvb_get_guint8(tvb, offset+mylen+3)>>2,
mylen==obj_length-4 ? "":
mylen<16 ? ", ":
mylen==16 ? ", ..." : "");
}
break;
default:
mylen = obj_length - 4;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, mylen,
"Data (%d bytes)", mylen);
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
proto_tree *ti2, *rsvp_admin_subtree;
guint32 status;
proto_item_set_text(ti, "ADMIN STATUS: ");
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
status = tvb_get_ntohl(tvb, offset2);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Admin Status: 0x%08x", status);
rsvp_admin_subtree =
proto_item_add_subtree(ti2, TREE(TT_ADMIN_STATUS_FLAGS));
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_REFLECT],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_HANDOVER],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_LOCKOUT],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_INHIBIT],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_CALL_MGMT],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_TESTING],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_DOWN],
tvb, offset2, 4, status);
proto_tree_add_boolean(rsvp_admin_subtree,
hf_rsvp_filter[RSVPF_ADMIN_STATUS_DELETE],
tvb, offset2, 4, status);
proto_item_set_text(ti, "ADMIN-STATUS: %s%s%s%s%s%s%s%s",
(status & (1<<31)) ? "Reflect " : "",
(status & (1<<6)) ? "Handover " : "",
(status & (1<<5)) ? "Lockout " : "",
(status & (1<<4)) ? "Inhibit " : "",
(status & (1<<3)) ? "Call " : "",
(status & (1<<2)) ? "Testing " : "",
(status & (1<<1)) ? "Admin-Down " : "",
(status & (1<<0)) ? "Deleting " : "");
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_lsp_attributes(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb, int offset, int obj_length,
int rsvp_class _U_, int type)
{
int tlv_off;
guint32 attributes;
guint16 tlv_type, tlv_len;
proto_tree *ti2, *rsvp_lsp_attr_subtree;
if (rsvp_class == RSVP_CLASS_LSP_REQUIRED_ATTRIBUTES)
proto_item_set_text(ti, "LSP REQUIRED ATTRIBUTES: ");
else
proto_item_set_text(ti, "LSP ATTRIBUTES: ");
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
for (tlv_off = 4; tlv_off < obj_length-4; ) {
tlv_type = tvb_get_ntohs(tvb, offset+tlv_off);
tlv_len = tvb_get_ntohs(tvb, offset+tlv_off+2);
if ((tlv_len == 0) || (tlv_off+tlv_len > (obj_length-4))) {
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off+2, 2,
"Invalid length");
return;
}
switch(tlv_type) {
case 1:
attributes = tvb_get_ntohl(tvb, offset+tlv_off+4);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off, tlv_len,
"LSP attributes TLV: 0x%08x", attributes);
rsvp_lsp_attr_subtree = proto_item_add_subtree(ti2, TREE(TT_LSP_ATTRIBUTES_FLAGS));
proto_tree_add_item(rsvp_lsp_attr_subtree, hf_rsvp_lsp_attr_e2e,
tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_attr_subtree, hf_rsvp_lsp_attr_boundary,
tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_lsp_attr_subtree, hf_rsvp_lsp_attr_segment,
tvb, offset+tlv_off+4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "LSP Attribute:%s%s%s",
(attributes & 0x01) ? " End-to-end re-routing" : "",
(attributes & 0x02) ? " Boundary re-routing" : "",
(attributes & 0x04) ? " Segment-based re-routing" : "");
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off, tlv_len,
"Unknown TLV");
break;
}
tlv_off += tlv_len;
}
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
static const value_string association_type_vals[] = {
{ 0, "Reserved"},
{ 1, "Recovery"},
{ 2, "Resource Sharing"},
{ 3, "Segment Recovery"},
{ 4, "Inter-domain Recovery"},
{ 0, NULL}
};
static value_string_ext association_type_vals_ext = VALUE_STRING_EXT_INIT(association_type_vals);
proto_item_set_text(ti, "ASSOCIATION ");
association_type = tvb_get_ntohs (tvb, offset + 4);
association_id = tvb_get_ntohs (tvb, offset + 6);
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 (IPv4)");
proto_item_append_text(ti, "(IPv4): ");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 2,
"Association type: %s",
val_to_str_ext(association_type, &association_type_vals_ext, "Unknown (%u)"));
proto_item_append_text(ti, "%s. ",
val_to_str_ext(association_type, &association_type_vals_ext, "Unknown (%u)"));
proto_tree_add_text(rsvp_object_tree, tvb, offset+6, 2,
"Association ID: %u", association_id);
proto_item_append_text(ti, "ID: %u. ", association_id);
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Association source: %s", tvb_ip_to_str(tvb, offset+8));
proto_item_append_text(ti, "Src: %s", tvb_ip_to_str(tvb, offset+8));
break;
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 (IPv6)");
proto_item_append_text(ti, "(IPv6): ");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 2,
"Association type: %s",
val_to_str_ext(association_type, &association_type_vals_ext, "Unknown (%u)"));
proto_item_append_text(ti, "%s. ",
val_to_str_ext(association_type, &association_type_vals_ext, "Unknown (%u)"));
proto_tree_add_text(rsvp_object_tree, tvb, offset+6, 2,
"Association ID: %u", association_id);
proto_item_append_text(ti, "ID: %u. ", association_id);
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 16,
"Association source: %s", tvb_ip6_to_str(tvb, offset+8));
proto_item_append_text(ti, "Src: %s", tvb_ip6_to_str(tvb, offset+8));
break;
case 4:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 4 (Routing Area)");
proto_item_append_text(ti, "(Routing Area): ");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 2,
"Association type: %s",
val_to_str_ext(association_type, &association_type_vals_ext, "Unknown (%u)"));
proto_item_append_text(ti, "%s. ",
val_to_str_ext(association_type, &association_type_vals_ext, "Unknown (%u)"));
proto_tree_add_text(rsvp_object_tree, tvb, offset+6, 2,
"Association ID: %u", association_id);
proto_item_append_text(ti, "Association ID: %u, ", association_id);
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Routing Area ID: %u", tvb_get_ntohl (tvb, offset+8));
proto_item_append_text(ti, "Routing Area ID: %u, ", tvb_get_ntohl (tvb, offset+8));
proto_tree_add_text(rsvp_object_tree, tvb, offset+12, 4,
"Node ID: %s", tvb_ip_to_str(tvb, offset+12));
proto_item_append_text(ti, "Node ID: %s", tvb_ip_to_str(tvb, offset+12));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 16,
"Padding: %s", tvb_bytes_to_str_punct(tvb, offset+16, 8, ' '));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_lsp_tunnel_if_id_tlv(proto_tree *rsvp_object_tree,
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off+2, 2,
"Invalid length");
return;
}
switch(tlv_type) {
case 1:
ti = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"Unnumbered component link identifier: %u",
tvb_get_ntohl(tvb, offset+tlv_off+4));
rsvp_lsp_tunnel_if_id_subtree = proto_item_add_subtree(ti, subtree_type);
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off, 2,
"Type: 1 (Unnumbered component link identifier)");
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u", tlv_len);
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+4, 4,
"Component link identifier: %u",
tvb_get_ntohl(tvb, offset+tlv_off+4));
break;
case 2:
ti = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"IPv4 component link identifier: %s",
tvb_ip_to_str(tvb, offset+tlv_off+4));
rsvp_lsp_tunnel_if_id_subtree = proto_item_add_subtree(ti, subtree_type);
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off, 2,
"Type: 2 (IPv4 component link identifier)");
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u", tlv_len);
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+4, 4,
"Component link identifier: %s",
tvb_ip_to_str(tvb, offset+tlv_off+4));
break;
case 32769:
ti = proto_tree_add_text(rsvp_object_tree, tvb,
offset+tlv_off, tlv_len,
"Targeted client layer: ");
rsvp_lsp_tunnel_if_id_subtree = proto_item_add_subtree(ti, subtree_type);
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off, 2,
"Type: 32769 (Targeted client layer)");
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+2, 2,
"Length: %u", tlv_len);
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+4, 1,
"LSP Encoding Type: %s",
rval_to_str(tvb_get_guint8(tvb,offset+tlv_off+4),
gmpls_lsp_enc_rvals, "Unknown (%d)"));
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+5, 1,
"Switching Type: %s",
rval_to_str(tvb_get_guint8(tvb,offset+tlv_off+5),
gmpls_switching_type_rvals, "Unknown (%d)"));
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+6, 1,
"Signal Type: %s",
val_to_str_ext(tvb_get_guint8(tvb,offset+tlv_off+6),
&gmpls_sonet_signal_type_str_ext, "Unknown (%d)"));
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+8, 8,
"Sub Interface/Connection ID: %" G_GINT64_MODIFIER "u (0x%s)",
tvb_get_ntoh64(tvb, offset+tlv_off+8),
tvb_bytes_to_str(tvb, offset+tlv_off+8, 8));
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+16, 4,
"SC PC ID: %s",
tvb_ip_to_str(tvb, offset+tlv_off+16));
proto_tree_add_text(rsvp_lsp_tunnel_if_id_subtree, tvb, offset+tlv_off+20, 4,
"SC PC SCN Address: %s",
tvb_ip_to_str(tvb, offset+tlv_off+20));
proto_item_append_text(ti, "LSP Encoding=%s, Switching Type=%s, Signal Type=%s",
rval_to_str(tvb_get_guint8(tvb,offset+tlv_off+4),
gmpls_lsp_enc_rvals, "Unknown (%d)"),
rval_to_str(tvb_get_guint8(tvb,offset+tlv_off+5),
gmpls_switching_type_rvals, "Unknown (%d)"),
val_to_str_ext(tvb_get_guint8(tvb,offset+tlv_off+6),
&gmpls_sonet_signal_type_str_ext, "Unknown (%d)"));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+tlv_off, 2,
"Unknown TLV: %u", tlv_type);
break;
}
tlv_off += tlv_len;
}
}
static void
dissect_rsvp_lsp_tunnel_if_id(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type)
{
guint8 action;
static const value_string lsp_tunnel_if_id_action_str[] = {
{ 0, "LSP is FA (MPLS-TE topology advertisement only)"},
{ 1, "LSP is RA (IP network advertisement only)"},
{ 2, "LSP is RA (both IP and MPLS-TE topology advertisement)"},
{ 3, "LSP is to be used as a virtual local link"},
{ 0, NULL}
};
proto_item_set_text(ti, "LSP INTERFACE-ID: ");
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - Unnumbered interface");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 4,
"Router ID: %s",
tvb_ip_to_str(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Interface ID: %u", tvb_get_ntohl(tvb, offset+8));
proto_item_set_text(ti, "LSP INTERFACE-ID: Unnumbered, Router-ID %s, Interface-ID %d",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8));
break;
case 2:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv4");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 4,
"IPv4 interface address: %s",
tvb_ip_to_str(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Target IGP instance: %s",
tvb_ip_to_str(tvb, offset+8));
proto_item_set_text(ti, "LSP INTERFACE-ID: IPv4, interface address %s,"
"IGP instance %s",
tvb_ip_to_str(tvb, offset+4),
tvb_ip_to_str(tvb, offset+8));
action = tvb_get_guint8(tvb, offset+12);
action >>= 4;
proto_tree_add_text(rsvp_object_tree, tvb, offset+12, 1, "Action: %d - %s",
action,
val_to_str_const(action, lsp_tunnel_if_id_action_str, "Unknown"));
dissect_rsvp_lsp_tunnel_if_id_tlv(rsvp_object_tree, tvb, offset+16, obj_length-16,
TREE(TT_LSP_TUNNEL_IF_ID_SUBTREE));
break;
case 3:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 3 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 16,
"IPv6 interface address: %s",
tvb_ip6_to_str(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+20, 4,
"Target IGP instance: %s",
tvb_ip_to_str(tvb, offset+20));
proto_item_set_text(ti, "LSP INTERFACE-ID: IPv6, interface address %s,"
"IGP instance %s",
tvb_ip6_to_str(tvb, offset+4),
tvb_ip_to_str(tvb, offset+20));
action = tvb_get_guint8(tvb, offset+24);
action >>= 4;
proto_tree_add_text(rsvp_object_tree, tvb, offset+24, 1, "Action: %d - %s",
action,
val_to_str_const(action, lsp_tunnel_if_id_action_str, "Unknown"));
dissect_rsvp_lsp_tunnel_if_id_tlv(rsvp_object_tree, tvb, offset+28, obj_length-28,
TREE(TT_LSP_TUNNEL_IF_ID_SUBTREE));
break;
case 4:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 4 - Unnumbered interface with target");
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 4,
"Router ID: %s",
tvb_ip_to_str(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Interface ID: %u", tvb_get_ntohl(tvb, offset+8));
proto_tree_add_text(rsvp_object_tree, tvb, offset+12, 4,
"Target IGP instance: %s",
tvb_ip_to_str(tvb, offset+12));
proto_item_set_text(ti, "LSP INTERFACE-ID: Unnumbered with target, Router-ID %s,"
" Interface-ID %d, IGP instance %s",
tvb_ip_to_str(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8),
tvb_ip_to_str(tvb, offset+12));
action = tvb_get_guint8(tvb, offset+16);
action >>= 4;
proto_tree_add_text(rsvp_object_tree, tvb, offset+16, 1, "Action: %d - %s",
action,
val_to_str_const(action, lsp_tunnel_if_id_action_str, "Unknown"));
dissect_rsvp_lsp_tunnel_if_id_tlv(rsvp_object_tree, tvb, offset+20, obj_length-20,
TREE(TT_LSP_TUNNEL_IF_ID_SUBTREE));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length-4,
"Data (%d bytes)", obj_length-4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 - IPv4");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Notify node address: %s",
tvb_ip_to_str(tvb, offset2));
proto_item_append_text(ti, ": Notify node: %s",
tvb_ip_to_str(tvb, offset2));
break;
}
case 2: {
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 - IPv6");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 16,
"Notify node address: %s",
tvb_ip6_to_str(tvb, offset2));
proto_item_append_text(ti, ": Notify node: %s",
tvb_ip6_to_str(tvb, offset2));
break;
}
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_gen_uni(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int type,
rsvp_conversation_info *rsvph)
{
int offset2 = offset + 4;
int mylen, i, j, k, l, m;
proto_item *ti2;
proto_tree *rsvp_gen_uni_subtree, *rsvp_session_subtree, *rsvp_template_subtree;
int s_len, s_class, s_type, sobj_len, nsap_len;
int offset3;
proto_item_set_text(ti, "GENERALIZED UNI: ");
mylen = obj_length - 4;
switch(type) {
case 1: {
const char *c;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, 8,
"%s IPv4 TNA: %s", c,
tvb_ip_to_str(tvb, offset2+l+4));
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (%s)", j, c);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: 1 (IPv4)");
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, 20,
"%s IPv6 TNA:", c);
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (%s)", j, c);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: 2 (IPv6)");
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, tvb_get_ntohs(tvb, offset2+l),
"%s NSAP TNA: ", c);
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
nsap_len = tvb_get_guint8(tvb, offset2+l+4);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (%s)", j, c);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: 3 (NSAP)");
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+4, 1,
"NSAP Length: %u", nsap_len);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+5,
sobj_len-4,
"NSAP address: %s",
print_nsap_net(tvb_get_ptr(tvb, offset2+l+5, nsap_len), nsap_len));
if (i < 4) {
proto_item_append_text(ti, "%s NSAP TNA: %s", c,
print_nsap_net(tvb_get_ptr(tvb, offset2+l+5, nsap_len), nsap_len));
}
break;
default:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, tvb_get_ntohs(tvb, offset2+l),
"%s UNKNOWN TNA", c);
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (%s)", j, c);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: %d (UNKNOWN)", j);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+4,
sobj_len-4,
"Data");
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, tvb_get_ntohs(tvb, offset2+l),
"Diversity Subobject");
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (Diversity)", j);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: %d", tvb_get_guint8(tvb, offset2+l+3));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
m = tvb_get_guint8(tvb, offset2+l+4) >> 4;
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+4, 1,
"Diversity: %d - %s", m,
val_to_str_const(m, ouni_guni_diversity_str, "Unknown"));
s_len = tvb_get_ntohs(tvb, offset2+l+8);
s_class = tvb_get_guint8(tvb, offset2+l+10);
s_type = tvb_get_guint8(tvb, offset2+l+11);
ti2 = proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+8,
s_len, "Session");
rsvp_session_subtree =
proto_item_add_subtree(ti2, TREE(rsvp_class_to_tree_type(s_class)));
if (s_len < 4) {
proto_tree_add_text(rsvp_object_tree, tvb, offset2+l+8, 2,
"Length: %u (bogus, must be >= 4)", s_len);
break;
}
proto_tree_add_text(rsvp_session_subtree, tvb, offset2+l+8, 2,
"Length: %u", s_len);
proto_tree_add_uint(rsvp_session_subtree, hf_rsvp_filter[RSVPF_OBJECT], tvb,
offset2+8+l+10, 1, s_class);
dissect_rsvp_session(ti2, rsvp_session_subtree, tvb, offset2+l+8,
s_len, s_class, s_type, rsvph);
offset3 = offset2 + s_len;
s_len = tvb_get_ntohs(tvb, offset3+l+8);
s_class = tvb_get_guint8(tvb, offset3+l+10);
s_type = tvb_get_guint8(tvb, offset3+l+11);
ti2 = proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset3+l+8,
s_len, "Template");
rsvp_template_subtree =
proto_item_add_subtree(ti2, TREE(rsvp_class_to_tree_type(s_class)));
if (s_len < 4) {
proto_tree_add_text(rsvp_object_tree, tvb, offset3+l+8, 2,
"Length: %u (bogus, must be >= 4)", s_len);
break;
}
proto_tree_add_text(rsvp_template_subtree, tvb, offset3+l+8, 2,
"Length: %u", s_len);
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, sobj_len,
"Egress Label Subobject");
else if (k == 2)
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, sobj_len,
"SPC Label Subobject");
else
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, sobj_len,
"Unknown Label Subobject");
rsvp_gen_uni_subtree = proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (Egress/SPC Label)", j);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: %d", k);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
proto_tree_add_item(rsvp_gen_uni_subtree, hf_rsvp_gen_uni_direction,
tvb, offset+l+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+7, 1,
"Label type: %u", tvb_get_guint8(tvb, offset2+l+7));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+8, 4,
"Logical Port ID: %u", tvb_get_ntohl(tvb, offset2+l+8));
proto_item_append_text(ti2, ": %s, Label type %d, Port ID %d, Label ",
tvb_get_guint8(tvb, offset2+l+4) & 0x80 ?
"Upstream" : "Downstream",
tvb_get_guint8(tvb, offset2+l+7),
tvb_get_ntohl(tvb, offset2+l+8));
for (j=12; j < sobj_len; j+=4) {
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+j, 4,
"Label: %u", tvb_get_ntohl(tvb, offset2+l+j));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, sobj_len,
"Service Level Subobject");
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+2, 1,
"Class: %d (Service Level)", j);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+3, 1,
"Type: %d", tvb_get_guint8(tvb, offset2+l+3));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 2,
"Length: %u", sobj_len);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+4, 1,
"Service Level: %u", tvb_get_guint8(tvb, offset2+l+4));
proto_item_append_text(ti2, ": %u", tvb_get_guint8(tvb, offset2+l+4));
if (i < 4) {
proto_item_append_text(ti, "Service Level %d", tvb_get_guint8(tvb, offset2+l+4));
}
break;
}
break;
default:
ti2 = proto_tree_add_text(rsvp_object_tree, tvb,
offset2+l, sobj_len,
"Unknown subobject: %u",
j);
rsvp_gen_uni_subtree =
proto_item_add_subtree(ti2, TREE(TT_GEN_UNI_SUBOBJ));
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l, 1,
"Type: %u (Unknown)", j);
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+1, 1,
"Length: %u",
tvb_get_guint8(tvb, offset2+l+1));
break;
}
if (tvb_get_guint8(tvb, offset2+l+1) < 1) {
proto_tree_add_text(rsvp_gen_uni_subtree, tvb, offset2+l+1, 1,
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, mylen,
"Data (%d bytes)", mylen);
break;
}
}
static void
dissect_rsvp_call_id(proto_tree *ti, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int c_type)
{
int type = 0;
const char *str;
int offset2 = offset + 4;
int offset3, offset4, len;
static const value_string address_type_vals[] = {
{ 1, "1 (IPv4)"},
{ 2, "2 (IPv6)"},
{ 3, "3 (NSAP)"},
{ 4, "4 (MAC)"},
{ 0x7f, "0x7f (Vendor-defined)"},
{ 0, NULL}
};
static value_string_ext address_type_vals_ext = VALUE_STRING_EXT_INIT(address_type_vals);
proto_item_set_text(ti, "CALL-ID: ");
switch(c_type) {
case 0:
proto_item_append_text(ti,"Empty");
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Empty (%u)", c_type);
if (obj_length > 4)
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length-4,
"Data (%d bytes)", obj_length-4);
break;
case 1:
case 2:
type = tvb_get_guint8 (tvb, offset2);
if (c_type == 1) {
offset3 = offset2 + 4;
len = obj_length - 16;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1 (operator specific)");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1, "Address type: %s",
val_to_str_ext(type, &address_type_vals_ext, "Unknown (%u)"));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+1, 3, "Reserved: %u",
tvb_get_ntoh24(tvb, offset2+1));
proto_item_append_text(ti, "Operator-Specific. Addr Type: %s. ",
val_to_str_ext(type, &address_type_vals_ext, "Unknown (%u)"));
}
else {
offset3 = offset2 + 16;
len = obj_length - 28;
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 2 (globally unique)");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 1, "Address type: %s",
val_to_str_ext(type, &address_type_vals_ext, "Unknown (%u)"));
str = tvb_get_ephemeral_string (tvb, offset2 + 1, 3);
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 1, 3,
"International Segment: %s", str);
proto_item_append_text(ti, "Globally-Unique. Addr Type: %s. Intl Segment: %s. ",
val_to_str_ext(type, &address_type_vals_ext, "Unknown (%u)"), str);
str = tvb_get_ephemeral_string (tvb, offset2 + 4, 12);
proto_tree_add_text(rsvp_object_tree, tvb, offset2 + 4, 12,
"National Segment: %s", str);
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
str = print_nsap_net(tvb_get_ptr(tvb, offset3, 20), 20);
proto_tree_add_text(rsvp_object_tree, tvb, offset3, 20,
"Source Transport Network addr: %s", str);
break;
case 4:
offset4 = offset3 + 6;
str = tvb_ether_to_str(tvb, offset3);
proto_tree_add_text(rsvp_object_tree, tvb, offset3, 6,
"Source Transport Network addr: %s", str);
break;
case 0x7F:
offset4 = offset3 + len;
str = tvb_bytes_to_str(tvb, offset3, len);
proto_tree_add_text(rsvp_object_tree, tvb, offset3, len,
"Source Transport Network addr: %s", str);
break;
default:
offset4 = offset3 + len;
str = "???";
proto_tree_add_text(rsvp_object_tree, tvb, offset3, len, "Unknown Transport Network type: %d",
type);
break;
}
proto_item_append_text(ti, "Src: %s. ", str);
proto_tree_add_text(rsvp_object_tree, tvb, offset4, 8, "Local Identifier: %s",
tvb_bytes_to_str(tvb, offset4, 8));
proto_item_append_text(ti, "Local ID: %s. ", tvb_bytes_to_str(tvb, offset4, 8));
break;
default:
proto_item_append_text(ti, " Unknown");
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)", c_type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length-4,
"Data (%d bytes)", obj_length-4);
break;
}
}
static void
dissect_rsvp_3gpp_object(proto_tree *ti _U_, proto_tree *rsvp_object_tree,
tvbuff_t *tvb,
int offset, int obj_length,
int rsvp_class _U_, int c_type)
{
guint16 length, ie_type;
offset+=3;
proto_tree_add_item(rsvp_object_tree, hf_rsvp_c_type, tvb, offset, 1, ENC_BIG_ENDIAN);
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
proto_tree_add_item(rsvp_object_tree, hf_rsvp_3gpp_obj_ue_ipv6_addr, tvb, offset, 16, ENC_BIG_ENDIAN);
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
ti = proto_tree_add_text(rsvp_object_tree, tvb, offset, -1, "Flow Identifier Num %u",i+1);
flow_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_FLOW]);
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
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_src_ipv6, tvb, offset, 16, ENC_BIG_ENDIAN);
offset+=16;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
break;
case 33:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_dst_ipv6, tvb, offset, 16, ENC_BIG_ENDIAN);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4, "Destination Port range %u-%u",
tvb_get_ntohs(tvb,offset), tvb_get_ntohs(tvb,offset+2));
offset+=4;
break;
case 80:
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_dst_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
pf_cont_len-=5;
break;
case 81:
proto_tree_add_text(rsvp_object_tree, tvb, offset, 4, "Source Port range %u-%u",
tvb_get_ntohs(tvb,offset), tvb_get_ntohs(tvb,offset+2));
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
ti = proto_tree_add_text(flow_tree, tvb, offset, 17, "Type 2 Routing Header packet filter");
t2_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_T2]);
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6, tvb, offset, 16, ENC_BIG_ENDIAN);
offset+=16;
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
break;
case 130:
ti = proto_tree_add_text(flow_tree, tvb, offset, 17, "Home address Option packet filter");
t2_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_HO]);
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6, tvb, offset, 16, ENC_BIG_ENDIAN);
offset+=16;
proto_tree_add_item(t2_tree, hf_rsvp_3gpp_obj_pf_ipv6_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pf_cont_len-=20;
default:
proto_tree_add_text(flow_tree, tvb, offset, pf_cont_len-2, "Not dissected Packet filter component");
offset = offset + pkt_flt_len - 5;
pf_cont_len=0;
break;
}
if(pf_cont_len != 0){
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_treatment, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(flow_tree, hf_rsvp_3gpp_obj_pf_hint, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;;
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
ti = proto_tree_add_text(rsvp_object_tree, tvb, offset, -1, "QOS Flow Identifier Num %u", num);
qos_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_QOS]);
proto_tree_add_item(qos_tree, hf_rsvp_3gpp_obj_flow_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tft_qos_list_len--;
blob_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(qos_tree, hf_rsvp_3gpp_r_qos_blob_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tft_qos_list_len--;
ti = proto_tree_add_item(qos_tree, hf_rsvp_3gpp_r_qos_blob, tvb, offset, blob_len, ENC_BIG_ENDIAN);
qos_sub_blob_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_QOS_SUB_BLOB]);
proto_tree_add_item(qos_sub_blob_tree, hf_rsvp_3gpp_r_qos_blob_flow_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(qos_sub_blob_tree, hf_rsvp_3gpp_r_qos_blob_num_qos_att_set, tvb, offset, 1, ENC_BIG_ENDIAN);
num_qos_att_set = (tvb_get_guint8(tvb, offset) & 0x0e)>>1;
bit_offset = (offset<<3)+7;
for (j = 0; j < num_qos_att_set; j++) {
qos_attribute_set_len = tvb_get_bits8(tvb,bit_offset,4);
ti = proto_tree_add_text(qos_sub_blob_tree, tvb, bit_offset>>3, qos_attribute_set_len, "QoS_ATTRIBUTE_SET %u(%u bytes)",
j+1,
qos_attribute_set_len);
qos_att_tree = proto_item_add_subtree(ti, ett_treelist[TT_3GPP_OBJ_QOS_SUB_BLOB]);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset, length-2, "IE Data");
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
proto_item_set_text(ti, "RESTART CAPABILITY: ");
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
proto_tree_add_text(rsvp_object_tree, tvb, offset2, 4,
"Restart Time: %d ms",
tvb_get_ntohl(tvb, offset2));
proto_tree_add_text(rsvp_object_tree, tvb, offset2+4, 4,
"Recovery Time: %d ms",
tvb_get_ntohl(tvb, offset2+4));
proto_item_append_text(ti, "Restart Time: %d ms. Recovery Time: %d ms.",
tvb_get_ntohl(tvb, offset2), tvb_get_ntohl(tvb, offset2+4));
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree *ti2, *ti3, *ti4, *rsvp_pi_link_flags_tree, *rsvp_pi_lsp_flags_tree, *rsvp_pi_seg_flags_tree;
int offset2 = offset + 4;
proto_item_set_text(ti, "PROTECTION_INFO: ");
switch(type) {
case 1:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: 1");
flags1 = tvb_get_guint8(tvb, offset2);
proto_tree_add_item(rsvp_object_tree, hf_rsvp_protection_info_flags_secondary_lsp,
tvb, offset2, 1, ENC_BIG_ENDIAN);
link_flags = tvb_get_guint8(tvb, offset2+3);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+3, 1,
"Link Flags: 0x%02x", link_flags);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type:2");
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
ti3 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+1, 1,
"LSP Flags: 0x%02x -%s%s%s%s%s%s", lsp_flags,
lsp_flags == 0 ? " Unprotected":"",
lsp_flags&0x01 ? " Rerouting":"",
lsp_flags&0x02 ? " Rerouting with extra-traffic":"",
lsp_flags&0x04 ? " 1:N Protection with extra-traffic":"",
lsp_flags&0x08 ? " 1+1 Unidirectional protection":"",
lsp_flags&0x10 ? " 1+1 Bidirectional protection":"");
rsvp_pi_lsp_flags_tree = proto_item_add_subtree(ti3, TREE(TT_PROTECTION_INFO_LSP));
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
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+3, 1,
"Link Flags: 0x%02x -%s%s%s%s%s%s", link_flags,
link_flags&0x01 ? " ExtraTraffic":"",
link_flags&0x02 ? " Unprotected":"",
link_flags&0x04 ? " Shared":"",
link_flags&0x08 ? " Dedicated1:1":"",
link_flags&0x10 ? " Dedicated1+1":"",
link_flags&0x20 ? " Enhanced":"");
rsvp_pi_link_flags_tree = proto_item_add_subtree(ti2, TREE(TT_PROTECTION_INFO_LINK));
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
ti4 = proto_tree_add_text(rsvp_object_tree, tvb, offset2+5, 1,
"Segment recovery Flags: 0x%02x - %s%s%s%s%s%s", seg_flags,
seg_flags == 0 ? " Unprotected":"",
seg_flags&0x01 ? " Rerouting":"",
seg_flags&0x02 ? " Rerouting with extra-traffic":"",
seg_flags&0x04 ? " 1:N Protection with extra-traffic":"",
seg_flags&0x08 ? " 1+1 Unidirectional protection":"",
seg_flags&0x10 ? " 1+1 Bidirectional protection":"");
rsvp_pi_seg_flags_tree = proto_item_add_subtree(ti4, TREE(TT_PROTECTION_INFO_SEG));
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_fast_reroute(proto_tree *ti, proto_tree *rsvp_object_tree,
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
proto_tree_add_text(rsvp_object_tree, tvb, offset, obj_length,
"<<<Invalid length: cannot decode>>>");
proto_item_append_text(ti, "Invalid length");
break;
}
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, 1,
"Setup Priority: %d", tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(rsvp_object_tree, tvb, offset+5, 1,
"Hold Priority: %d", tvb_get_guint8(tvb, offset+5));
proto_tree_add_text(rsvp_object_tree, tvb, offset+6, 1,
"Hop Limit: %d", tvb_get_guint8(tvb, offset+6));
flags = tvb_get_guint8(tvb, offset+7);
ti2 = proto_tree_add_text(rsvp_object_tree, tvb, offset+7, 1,
"Flags: 0x%02x", flags);
rsvp_frr_flags_tree = proto_item_add_subtree(ti2, TREE(TT_FAST_REROUTE_FLAGS));
proto_tree_add_item(rsvp_frr_flags_tree, hf_rsvp_frr_flags_one2one_backup,
tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsvp_frr_flags_tree, hf_rsvp_frr_flags_facility_backup,
tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset+8, 4,
"Bandwidth: %.10g", tvb_get_ntohieee_float(tvb, offset+8));
proto_tree_add_text(rsvp_object_tree, tvb, offset+12, 4,
"Include-Any: 0x%0x", tvb_get_ntohl(tvb, offset+12));
proto_tree_add_text(rsvp_object_tree, tvb, offset+16, 4,
"Exclude-Any: 0x%0x", tvb_get_ntohl(tvb, offset+16));
if (type == 1) {
proto_tree_add_text(rsvp_object_tree, tvb, offset+20, 4,
"Include-All: 0x%0x", tvb_get_ntohl(tvb, offset+20));
}
proto_item_append_text(ti, "%s%s",
flags &0x01 ? "One-to-One Backup, " : "",
flags &0x02 ? "Facility Backup" : "");
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
}
static void
dissect_rsvp_detour(proto_tree *ti, proto_tree *rsvp_object_tree,
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: %u", type);
for (remaining_length = obj_length - 4, count = 1;
remaining_length > 0; remaining_length -= 8, count++) {
if (remaining_length < 8) {
proto_tree_add_text(rsvp_object_tree, tvb, offset+remaining_length,
obj_length-remaining_length,
"<<<Invalid length: cannot decode>>>");
proto_item_append_text(ti, "Invalid length");
break;
}
iter++;
proto_tree_add_text(rsvp_object_tree, tvb, offset+(4*iter), 4,
"PLR ID %d: %s", count,
tvb_ip_to_str(tvb, offset+(4*iter)));
iter++;
proto_tree_add_text(rsvp_object_tree, tvb, offset+(4*iter), 4,
"Avoid Node ID %d: %s", count,
tvb_ip_to_str(tvb, offset+(4*iter)));
}
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)",
type);
proto_tree_add_text(rsvp_object_tree, tvb, offset+4, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset, 1,
"C-type: 1 - E-LSP");
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
proto_tree_add_text(rsvp_object_tree, tvb, offset, 1,
"C-type: 2 - L-LSP");
dissect_diffserv_mpls_common(tvb, rsvp_object_tree, type,
offset + 3, hfindexes, etts);
break;
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset, 1,
"C-type: Unknown (%u)", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset + 1, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1, "C-type: 1");
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_DSTE_CLASSTYPE],
tvb, offset2+3, 1, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "CLASSTYPE: CT %u", ct);
break;
default:
proto_item_set_text(ti, "CLASSTYPE: (Unknown C-type)");
proto_tree_add_text(rsvp_object_tree, tvb, offset+3, 1,
"C-type: Unknown (%u)", type);
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
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
proto_tree_add_text(rsvp_object_tree, tvb, offset + 3, 1,
"C-type: %u", type);
proto_tree_add_item(rsvp_object_tree,
hf_rsvp_filter[RSVPF_ENT_CODE],
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(rsvp_object_tree, tvb, offset + 8, obj_length - 8,
"Data (%d bytes)", obj_length - 8);
}
static void
dissect_rsvp_msg_tree(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int tree_mode, rsvp_conversation_info *rsvph)
{
proto_tree *rsvp_tree;
proto_tree *rsvp_header_tree;
proto_tree *rsvp_object_tree;
proto_tree *ti;
proto_item *hidden_item;
guint16 cksum, computed_cksum;
vec_t cksum_vec[1];
int offset = 0;
int len;
guint8 ver_flags;
guint8 message_type;
int session_off, tempfilt_off;
int msg_length;
int obj_length;
int offset2;
offset = 0;
ver_flags = tvb_get_guint8(tvb, 0);
msg_length = tvb_get_ntohs(tvb, 6);
message_type = tvb_get_guint8(tvb, 1);
ti = proto_tree_add_item(tree, proto_rsvp, tvb, offset, msg_length,
ENC_NA);
rsvp_tree = proto_item_add_subtree(ti, tree_mode);
if (pinfo->ipproto == IP_PROTO_RSVPE2EI)
proto_item_append_text(rsvp_tree, " (E2E-IGNORE)");
proto_item_append_text(rsvp_tree, ": ");
proto_item_append_text(rsvp_tree, "%s", val_to_str_ext(message_type, &message_type_vals_ext,
"Unknown (%u). "));
find_rsvp_session_tempfilt(tvb, 0, &session_off, &tempfilt_off);
if (session_off)
proto_item_append_text(rsvp_tree, "%s", summary_session(tvb, session_off));
if (tempfilt_off)
proto_item_append_text(rsvp_tree, "%s", summary_template(tvb, tempfilt_off));
ti = proto_tree_add_text(rsvp_tree, tvb, offset, 8, "RSVP Header. %s",
val_to_str_ext(message_type, &message_type_vals_ext,
"Unknown Message (%u). "));
if (pinfo->ipproto == IP_PROTO_RSVPE2EI)
proto_item_append_text(ti, " (E2E-IGNORE)");
rsvp_header_tree = proto_item_add_subtree(ti, TREE(TT_HDR));
proto_tree_add_text(rsvp_header_tree, tvb, offset, 1, "RSVP Version: %u",
(ver_flags & 0xf0)>>4);
proto_tree_add_text(rsvp_header_tree, tvb, offset, 1, "Flags: %02x",
ver_flags & 0xf);
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
if (!pinfo->fragmented && ((int) tvb_length(tvb) >= msg_length)) {
cksum_vec[0].ptr = tvb_get_ptr(tvb, 0, msg_length);
cksum_vec[0].len = msg_length;
computed_cksum = in_cksum(&cksum_vec[0], 1);
if (computed_cksum == 0) {
proto_tree_add_text(rsvp_header_tree, tvb, offset+2, 2,
"Message Checksum: 0x%04x [correct]",
cksum);
} else {
proto_tree_add_text(rsvp_header_tree, tvb, offset+2, 2,
"Message Checksum: 0x%04x [incorrect, should be 0x%04x]",
cksum,
in_cksum_shouldbe(cksum, computed_cksum));
}
} else {
proto_tree_add_text(rsvp_header_tree, tvb, offset+2, 2,
"Message Checksum: 0x%04x",
cksum);
}
proto_tree_add_text(rsvp_header_tree, tvb, offset+4, 1,
"Sending TTL: %u",
tvb_get_guint8(tvb, offset+4));
proto_tree_add_text(rsvp_header_tree, tvb, offset+6, 2,
"Message length: %u", msg_length);
offset = 8;
len = 8;
if (message_type == RSVP_MSG_BUNDLE) {
if (rsvp_bundle_dissect) {
int len2 = 8;
while (len2 < msg_length) {
gint sub_len;
tvbuff_t *tvb_sub;
sub_len = tvb_get_ntohs(tvb, len2+6);
tvb_sub = tvb_new_subset(tvb, len2, sub_len, sub_len);
dissect_rsvp_msg_tree(tvb_sub, pinfo, rsvp_tree, TREE(TT_BUNDLE_COMPMSG), rsvph);
len2 += sub_len;
}
} else {
proto_tree_add_text(rsvp_tree, tvb, offset, msg_length - len,
"Bundle Component Messages Not Dissected");
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
if (obj_length < 4) {
proto_tree_add_text(rsvp_object_tree, tvb, offset, 2,
"Length: %u (bogus, must be >= 4)", obj_length);
break;
}
proto_tree_add_text(rsvp_object_tree, tvb, offset, 2,
"Length: %u", obj_length);
proto_tree_add_uint(rsvp_object_tree, hf_rsvp_filter[RSVPF_OBJECT], tvb,
offset+2, 1, rsvp_class);
offset2 = offset+4;
switch(rsvp_class) {
case RSVP_CLASS_SESSION:
dissect_rsvp_session(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type, rsvph);
break;
case RSVP_CLASS_HOP:
dissect_rsvp_hop(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_TIME_VALUES:
dissect_rsvp_time_values(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ERROR:
dissect_rsvp_error(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
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
dissect_rsvp_tspec(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_FLOWSPEC:
dissect_rsvp_flowspec(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ADSPEC:
dissect_rsvp_adspec(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_INTEGRITY:
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
dissect_rsvp_explicit_route(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_RECORD_ROUTE:
dissect_rsvp_record_route(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
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
dissect_rsvp_lsp_attributes(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_ASSOCIATION:
dissect_rsvp_association(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_LSP_TUNNEL_IF_ID:
dissect_rsvp_lsp_tunnel_if_id(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_NOTIFY_REQUEST:
dissect_rsvp_notify_request(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_GENERALIZED_UNI:
dissect_rsvp_gen_uni(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type, rsvph);
break;
case RSVP_CLASS_CALL_ID:
dissect_rsvp_call_id(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_3GPP2_OBJECT:
dissect_rsvp_3gpp_object(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_RESTART_CAP:
dissect_rsvp_restart_cap(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_PROTECTION:
dissect_rsvp_protection_info(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_FAST_REROUTE:
dissect_rsvp_fast_reroute(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
break;
case RSVP_CLASS_DETOUR:
dissect_rsvp_detour(ti, rsvp_object_tree, tvb, offset, obj_length, rsvp_class, type);
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
case RSVP_CLASS_NULL:
default:
proto_tree_add_text(rsvp_object_tree, tvb, offset2, obj_length - 4,
"Data (%d bytes)", obj_length - 4);
break;
}
offset += obj_length;
len += obj_length;
}
}
static void
dissect_rsvp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 message_type;
int session_off, tempfilt_off;
rsvp_conversation_info *rsvph;
conversation_t *conversation;
struct rsvp_request_key request_key, *new_request_key;
struct rsvp_request_val *request_val;
col_set_str(pinfo->cinfo, COL_PROTOCOL,
(pinfo->ipproto == IP_PROTO_RSVPE2EI) ? "RSVP-E2EI" : "RSVP");
col_clear(pinfo->cinfo, COL_INFO);
message_type = tvb_get_guint8(tvb, 1);
rsvph = ep_new0(rsvp_conversation_info);
SET_ADDRESS(&rsvph->source, pinfo->src.type, pinfo->src.len, pinfo->src.data);
SET_ADDRESS(&rsvph->destination, pinfo->dst.type, pinfo->dst.len, pinfo->dst.data);
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
if (tree) {
dissect_rsvp_msg_tree(tvb, pinfo, tree, TREE(TT_RSVP), rsvph);
}
if ((message_type == RSVP_MSG_ACK) ||
(message_type == RSVP_MSG_SREFRESH) ||
(message_type == RSVP_MSG_HELLO))
return;
conversation = find_or_create_conversation(pinfo);
memset(&request_key, 0, sizeof(request_key));
request_key.conversation = conversation->index;
request_key.session_type = rsvph->session_type;
switch (request_key.session_type) {
case RSVP_SESSION_TYPE_IPV4:
SET_ADDRESS(&request_key.u.session_ipv4.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4.protocol = rsvph->protocol;
request_key.u.session_ipv4.udp_dest_port = rsvph->udp_dest_port;
break;
case RSVP_SESSION_TYPE_IPV6:
break;
case RSVP_SESSION_TYPE_IPV4_LSP:
SET_ADDRESS(&request_key.u.session_ipv4_lsp.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4_lsp.udp_dest_port = rsvph->udp_dest_port;
request_key.u.session_ipv4_lsp.ext_tunnel_id = rsvph->ext_tunnel_id;
break;
case RSVP_SESSION_TYPE_AGGREGATE_IPV4:
SET_ADDRESS(&request_key.u.session_agg_ipv4.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_agg_ipv4.dscp = rsvph->dscp;
break;
case RSVP_SESSION_TYPE_IPV4_UNI:
SET_ADDRESS(&request_key.u.session_ipv4_uni.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4_uni.udp_dest_port = rsvph->udp_dest_port;
request_key.u.session_ipv4_uni.ext_tunnel_id = rsvph->ext_tunnel_id;
break;
case RSVP_SESSION_TYPE_IPV4_E_NNI:
SET_ADDRESS(&request_key.u.session_ipv4_enni.destination,
rsvph->destination.type, rsvph->destination.len,
rsvph->destination.data);
request_key.u.session_ipv4_enni.udp_dest_port = rsvph->udp_dest_port;
request_key.u.session_ipv4_enni.ext_tunnel_id = rsvph->ext_tunnel_id;
break;
default:
if (tree) {
proto_tree_add_text(tree, tvb, 0, 0, "Unknown session type");
}
break;
}
SE_COPY_ADDRESS(&request_key.source_info.source, &rsvph->source);
request_key.source_info.udp_source_port = rsvph->udp_source_port;
request_val =
(struct rsvp_request_val *) g_hash_table_lookup(rsvp_request_hash,
&request_key);
if (!request_val) {
new_request_key = (struct rsvp_request_key *)se_memdup(&request_key, sizeof(struct rsvp_request_key));
request_val = se_new(struct rsvp_request_val);
request_val->value = conversation->index;
g_hash_table_insert(rsvp_request_hash, new_request_key, request_val);
}
tap_queue_packet(rsvp_tap, pinfo, rsvph);
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
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
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
{&hf_rsvp_lsp_attr_e2e,
{ "E2E re-routing", "rsvp.lsp_attr.e2e",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x01,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_boundary,
{ "Boundary re-routing", "rsvp.lsp_attr.boundary",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x02,
NULL, HFILL }
},
{&hf_rsvp_lsp_attr_segment,
{ "Segment-based re-routing", "rsvp.lsp_attr.segment",
FT_BOOLEAN, 32, TFS(&tfs_desired_not_desired), 0x04,
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
{&hf_rsvp_c_type,
{ "C-Type", "rsvp.ctype",
FT_UINT8, BASE_DEC, NULL, 0,
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
{ "Type of Service (IPv4)/Traffic Class (IPv6)", "rsvp.3gpp_obj._pf_tos_tc",
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
};
gint *ett_tree[TT_MAX];
for (i=0; i<TT_MAX; i++) {
ett_treelist[i] = -1;
ett_tree[i] = &(ett_treelist[i]);
}
proto_rsvp = proto_register_protocol("Resource ReserVation Protocol (RSVP)",
"RSVP", "rsvp");
proto_register_field_array(proto_rsvp, rsvpf_info, array_length(rsvpf_info));
proto_register_subtree_array(ett_tree, array_length(ett_tree));
register_rsvp_prefs();
rsvp_dissector_table = register_dissector_table("rsvp.proto", "RSVP Protocol",
FT_UINT8, BASE_DEC);
register_init_routine(&rsvp_init_protocol);
}
void
proto_reg_handoff_rsvp(void)
{
dissector_handle_t rsvp_handle;
rsvp_handle = create_dissector_handle(dissect_rsvp, proto_rsvp);
dissector_add_uint("ip.proto", IP_PROTO_RSVP, rsvp_handle);
dissector_add_uint("ip.proto", IP_PROTO_RSVPE2EI, rsvp_handle);
dissector_add_uint("udp.port", UDP_PORT_PRSVP, rsvp_handle);
rsvp_tap = register_tap("rsvp");
}
