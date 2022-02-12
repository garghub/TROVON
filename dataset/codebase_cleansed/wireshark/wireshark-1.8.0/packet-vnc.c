static void
dissect_vnc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean ret;
gint offset = 0;
proto_item *ti = NULL;
proto_tree *vnc_tree = NULL;
conversation_t *conversation;
vnc_conversation_t *per_conversation_info;
conversation = find_or_create_conversation(pinfo);
per_conversation_info = conversation_get_proto_data(conversation, proto_vnc);
if(!per_conversation_info) {
per_conversation_info = se_alloc(sizeof(vnc_conversation_t));
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_SERVER_VERSION;
per_conversation_info->security_type_selected = VNC_SECURITY_TYPE_INVALID;
per_conversation_info->tight_enabled = FALSE;
conversation_add_proto_data(conversation, proto_vnc, per_conversation_info);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VNC");
col_clear(pinfo->cinfo, COL_INFO);
if(tree) {
ti = proto_tree_add_item(tree, proto_vnc, tvb, 0, -1, ENC_NA);
vnc_tree = proto_item_add_subtree(ti, ett_vnc);
}
offset = 0;
ret = vnc_startup_messages(tvb, pinfo, offset, vnc_tree,
per_conversation_info);
vnc_set_bytes_per_pixel(pinfo, vnc_bytes_per_pixel);
vnc_set_depth(pinfo, vnc_depth);
if(!ret) {
if(DEST_PORT_VNC || per_conversation_info->server_port == pinfo->destport)
vnc_client_to_server(tvb, pinfo, &offset, vnc_tree);
else
vnc_server_to_client(tvb, pinfo, &offset, vnc_tree);
}
}
static gint
process_vendor(proto_tree *tree, gint hfindex, tvbuff_t *tvb, gint offset)
{
gchar *vendor;
proto_item *ti;
if (tree) {
vendor = tvb_get_ephemeral_string(tvb, offset, 4);
ti = proto_tree_add_string(tree, hfindex, tvb, offset, 4, vendor);
if(g_ascii_strcasecmp(vendor, "STDV") == 0)
proto_item_append_text(ti, " (Standard VNC vendor)");
else if(g_ascii_strcasecmp(vendor, "TRDV") == 0)
proto_item_append_text(ti, " (Tridia VNC vendor)");
else if(g_ascii_strcasecmp(vendor, "TGHT") == 0)
proto_item_append_text(ti, " (Tight VNC vendor)");
}
offset += 4;
return offset;
}
static gint
process_tight_capabilities(proto_tree *tree,
gint type_index, gint vendor_index, gint name_index,
tvbuff_t *tvb, gint offset, const gint num_capabilities)
{
gint i;
for (i = 0; i < num_capabilities; i++) {
char *name;
proto_tree_add_item(tree, type_index, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = process_vendor(tree, vendor_index, tvb, offset);
name = tvb_get_ephemeral_string(tvb, offset, 8);
proto_tree_add_string(tree, name_index, tvb, offset, 8, name);
offset += 8;
}
return offset;
}
static gboolean
vnc_is_client_or_server_version_message(tvbuff_t *tvb)
{
if(tvb_length(tvb) != 12) {
return FALSE;
}
if(tvb_strncaseeql(tvb, 0, "RFB ", 4) != 0) {
return FALSE;
}
if((tvb_get_guint8(tvb, 7) != 0x2e) || (tvb_get_guint8(tvb,11) != 0xa)) {
return FALSE;
}
return TRUE;
}
static gboolean test_vnc_protocol(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
conversation_t *conversation;
if (vnc_is_client_or_server_version_message(tvb)) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype,
pinfo->srcport,
pinfo->destport, 0);
conversation_set_dissector(conversation, vnc_handle);
dissect_vnc(tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
static gboolean
vnc_startup_messages(tvbuff_t *tvb, packet_info *pinfo, gint offset,
proto_tree *tree, vnc_conversation_t
*per_conversation_info)
{
guint8 num_security_types;
guint32 desktop_name_len, auth_result, text_len, auth_code;
vnc_packet_t *per_packet_info;
gint num_tunnel_types;
gint num_auth_types;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
if(!per_packet_info) {
per_packet_info = se_alloc(sizeof(vnc_packet_t));
per_packet_info->state = per_conversation_info->vnc_next_state;
per_packet_info->preferred_encoding = -1;
p_add_proto_data(pinfo->fd, proto_vnc, per_packet_info);
}
switch(per_packet_info->state) {
case VNC_SESSION_STATE_SERVER_VERSION :
if (!vnc_is_client_or_server_version_message(tvb))
return TRUE;
proto_tree_add_item(tree, hf_vnc_server_proto_ver, tvb, 4,
7, ENC_ASCII|ENC_NA);
per_conversation_info->server_proto_ver =
g_ascii_strtod((char *)tvb_get_ephemeral_string(tvb, 4, 7), NULL);
per_conversation_info->server_port = pinfo->srcport;
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO,
"Server protocol version: %s",
tvb_format_text(tvb, 4, 7));
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_CLIENT_VERSION;
break;
case VNC_SESSION_STATE_CLIENT_VERSION :
if (!vnc_is_client_or_server_version_message(tvb))
return TRUE;
proto_tree_add_item(tree, hf_vnc_client_proto_ver, tvb,
4, 7, ENC_ASCII|ENC_NA);
per_conversation_info->client_proto_ver =
g_ascii_strtod((char *)tvb_get_ephemeral_string(tvb, 4, 7), NULL);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO,
"Client protocol version: %s",
tvb_format_text(tvb, 4, 7));
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_SECURITY;
break;
case VNC_SESSION_STATE_SECURITY :
col_set_str(pinfo->cinfo, COL_INFO, "Security types supported");
if(per_conversation_info->client_proto_ver >= 3.007) {
num_security_types = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_item(tree,
hf_vnc_num_security_types,
tvb, offset, 1, ENC_BIG_ENDIAN);
for(offset = 1; offset <= num_security_types; offset++){
proto_tree_add_item(tree,
hf_vnc_security_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
}
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_SECURITY_TYPES;
} else {
proto_tree_add_item(tree, hf_vnc_server_security_type,
tvb, offset, 4, ENC_BIG_ENDIAN);
per_conversation_info->security_type_selected = (guint8)tvb_get_ntohl(tvb, offset);
switch(per_conversation_info->security_type_selected) {
case VNC_SECURITY_TYPE_INVALID:
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_SECURITY_TYPES;
break;
case VNC_SECURITY_TYPE_NONE:
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_CLIENT_INIT;
break;
case VNC_SECURITY_TYPE_VNC:
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_VNC_AUTHENTICATION_CHALLENGE;
break;
default:
break;
}
}
break;
case VNC_SESSION_STATE_SECURITY_TYPES :
col_set_str(pinfo->cinfo, COL_INFO, "Authentication type selected by client");
proto_tree_add_item(tree, hf_vnc_client_security_type, tvb, offset, 1, ENC_BIG_ENDIAN);
per_conversation_info->security_type_selected =
tvb_get_guint8(tvb, offset);
switch(per_conversation_info->security_type_selected) {
case VNC_SECURITY_TYPE_NONE :
if(per_conversation_info->client_proto_ver >= 3.008)
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_SECURITY_RESULT;
else
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_CLIENT_INIT;
break;
case VNC_SECURITY_TYPE_VNC :
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_VNC_AUTHENTICATION_CHALLENGE;
break;
case VNC_SECURITY_TYPE_TIGHT :
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_TIGHT_TUNNELING_CAPABILITIES;
per_conversation_info->tight_enabled = TRUE;
break;
default :
break;
}
break;
case VNC_SESSION_STATE_TIGHT_TUNNELING_CAPABILITIES :
{
gint i;
col_set_str(pinfo->cinfo, COL_INFO, "TightVNC tunneling capabilities supported");
proto_tree_add_item(tree, hf_vnc_tight_num_tunnel_types, tvb, offset, 4, ENC_BIG_ENDIAN);
num_tunnel_types = tvb_get_ntohl(tvb, offset);
offset += 4;
for(i = 0; i < num_tunnel_types; i++) {
proto_tree_add_item(tree, hf_vnc_tight_tunnel_type, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
}
if (num_tunnel_types == 0)
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_AUTH_CAPABILITIES;
else
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_TUNNEL_TYPE_REPLY;
break;
}
case VNC_SESSION_STATE_TIGHT_TUNNEL_TYPE_REPLY:
break;
case VNC_SESSION_STATE_TIGHT_AUTH_CAPABILITIES:
col_set_str(pinfo->cinfo, COL_INFO, "TightVNC authentication capabilities supported");
proto_tree_add_item(tree, hf_vnc_tight_num_auth_types, tvb, offset, 4, ENC_BIG_ENDIAN);
num_auth_types = tvb_get_ntohl(tvb, offset);
offset += 4;
{
int i;
guint8 *vendor, *signature;
for (i = 0; i < 1; i++) {
auth_code = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_vnc_tight_auth_code, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
vendor = tvb_get_ephemeral_string(tvb, offset, 4);
process_vendor(tree, hf_vnc_tight_server_vendor, tvb, offset);
offset += 4;
signature = tvb_get_ephemeral_string(tvb, offset, 8);
proto_tree_add_text(tree, tvb, offset, 8, "Signature: %s", signature);
offset += 8;
switch(auth_code) {
case VNC_SECURITY_TYPE_NONE:
if ((g_ascii_strcasecmp(vendor, "STDV") != 0) || (g_ascii_strcasecmp(signature, "NOAUTH__") != 0)) {
proto_tree_add_text(tree, tvb, offset, 0, "Authentication code does not match vendor or signature");
}
break;
case VNC_SECURITY_TYPE_VNC:
if ((g_ascii_strcasecmp(vendor, "STDV") != 0) || (g_ascii_strcasecmp(signature, "VNCAUTH_") != 0)) {
proto_tree_add_text(tree, tvb, offset, 0, "Authentication code does not match vendor or signature");
}
break;
case VNC_SECURITY_TYPE_VENCRYPT:
if ((g_ascii_strcasecmp(vendor, "VENC") != 0) || (g_ascii_strcasecmp(signature, "VENCRYPT") != 0)) {
proto_tree_add_text(tree, tvb, offset, 0, "Authentication code does not match vendor or signature");
}
break;
case VNC_SECURITY_TYPE_GTK_VNC_SASL:
if ((g_ascii_strcasecmp(vendor, "GTKV") != 0) || (g_ascii_strcasecmp(signature, "SASL____") != 0)) {
proto_tree_add_text(tree, tvb, offset, 0, "Authentication code does not match vendor or signature");
}
break;
case VNC_TIGHT_AUTH_TGHT_ULGNAUTH:
if ((g_ascii_strcasecmp(vendor, "TGHT") != 0) || (g_ascii_strcasecmp(signature, "ULGNAUTH") != 0)) {
proto_tree_add_text(tree, tvb, offset, 0, "Authentication code does not match vendor or signature");
}
break;
case VNC_TIGHT_AUTH_TGHT_XTRNAUTH:
if ((g_ascii_strcasecmp(vendor, "TGHT") != 0) || (g_ascii_strcasecmp(signature, "XTRNAUTH") != 0)) {
proto_tree_add_text(tree, tvb, offset, 0, "Authentication code does not match vendor or signature");
}
break;
default:
proto_tree_add_text(tree, tvb, offset, 0, "Unknown TIGHT VNC authentication");
break;
}
}
}
if (num_auth_types == 0)
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_CLIENT_INIT;
else
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_AUTH_TYPE_REPLY;
break;
case VNC_SESSION_STATE_TIGHT_AUTH_TYPE_REPLY:
col_set_str(pinfo->cinfo, COL_INFO, "TightVNC authentication type selected by client");
auth_code = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_vnc_tight_auth_code, tvb, offset, 4, ENC_BIG_ENDIAN);
switch(auth_code) {
case VNC_SECURITY_TYPE_NONE:
per_conversation_info->security_type_selected = VNC_SECURITY_TYPE_NONE;
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_CLIENT_INIT;
break;
case VNC_SECURITY_TYPE_VNC:
per_conversation_info->security_type_selected = VNC_SECURITY_TYPE_VNC;
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_VNC_AUTHENTICATION_CHALLENGE;
break;
case VNC_SECURITY_TYPE_GTK_VNC_SASL:
per_conversation_info->security_type_selected = VNC_SECURITY_TYPE_GTK_VNC_SASL;
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_UNKNOWN_PACKET3;
break;
case VNC_TIGHT_AUTH_TGHT_ULGNAUTH:
per_conversation_info->security_type_selected = VNC_TIGHT_AUTH_TGHT_ULGNAUTH;
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_UNKNOWN_PACKET3;
break;
case VNC_TIGHT_AUTH_TGHT_XTRNAUTH:
per_conversation_info->security_type_selected = VNC_TIGHT_AUTH_TGHT_XTRNAUTH;
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_UNKNOWN_PACKET3;
break;
default:
proto_tree_add_text(tree, tvb, offset, 0, "Unknown authentication selected");
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_TIGHT_UNKNOWN_PACKET3;
break;
}
break;
case VNC_SESSION_STATE_TIGHT_UNKNOWN_PACKET3 :
col_set_str(pinfo->cinfo, COL_INFO, "Unknown packet (TightVNC)");
proto_tree_add_text(tree, tvb, offset, -1,
"Unknown packet (TightVNC)");
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_VNC_AUTHENTICATION_CHALLENGE;
break;
case VNC_SESSION_STATE_VNC_AUTHENTICATION_CHALLENGE :
col_set_str(pinfo->cinfo, COL_INFO, "Authentication challenge from server");
proto_tree_add_item(tree, hf_vnc_auth_challenge, tvb,
offset, 16, ENC_NA);
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_VNC_AUTHENTICATION_RESPONSE;
break;
case VNC_SESSION_STATE_VNC_AUTHENTICATION_RESPONSE :
col_set_str(pinfo->cinfo, COL_INFO, "Authentication response from client");
proto_tree_add_item(tree, hf_vnc_auth_response, tvb,
offset, 16, ENC_NA);
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_SECURITY_RESULT;
break;
case VNC_SESSION_STATE_SECURITY_RESULT :
col_set_str(pinfo->cinfo, COL_INFO, "Authentication result");
proto_tree_add_item(tree, hf_vnc_auth_result, tvb, offset,
4, ENC_BIG_ENDIAN);
auth_result = tvb_get_ntohl(tvb, offset);
offset += 4;
switch(auth_result) {
case 0 :
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_CLIENT_INIT;
break;
case 1 :
if(per_conversation_info->client_proto_ver >= 3.008) {
text_len = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Length of authentication error: %d", text_len);
offset += 4;
proto_tree_add_item(tree, hf_vnc_auth_error, tvb,
offset, text_len, ENC_ASCII|ENC_NA);
}
return TRUE;
break;
}
break;
case VNC_SESSION_STATE_CLIENT_INIT :
col_set_str(pinfo->cinfo, COL_INFO, "Share desktop flag");
proto_tree_add_item(tree, hf_vnc_share_desktop_flag, tvb,
offset, 1, ENC_BIG_ENDIAN);
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_SERVER_INIT;
break;
case VNC_SESSION_STATE_SERVER_INIT :
col_set_str(pinfo->cinfo, COL_INFO, "Server framebuffer parameters");
proto_tree_add_item(tree, hf_vnc_width, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vnc_height, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vnc_server_bits_per_pixel,
tvb, offset, 1, ENC_BIG_ENDIAN);
vnc_bytes_per_pixel = tvb_get_guint8(tvb, offset)/8;
vnc_set_bytes_per_pixel(pinfo, vnc_bytes_per_pixel);
offset += 1;
proto_tree_add_item(tree, hf_vnc_server_depth, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_vnc_server_big_endian_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_vnc_server_true_color_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_vnc_server_red_max,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vnc_server_green_max,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vnc_server_blue_max,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vnc_server_red_shift,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_vnc_server_green_shift,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_vnc_server_blue_shift,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_vnc_padding,
tvb, offset, 3, ENC_NA);
offset += 3;
if(tvb_length_remaining(tvb, offset) > 4) {
proto_tree_add_item(tree, hf_vnc_desktop_name_len,
tvb, offset, 4, ENC_BIG_ENDIAN);
desktop_name_len = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(tree, hf_vnc_desktop_name,
tvb, offset, desktop_name_len,
ENC_ASCII|ENC_NA);
}
if(per_conversation_info->tight_enabled == TRUE)
per_conversation_info->vnc_next_state =
VNC_SESSION_STATE_TIGHT_INTERACTION_CAPS;
else
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_NORMAL_TRAFFIC;
break;
case VNC_SESSION_STATE_TIGHT_INTERACTION_CAPS :
col_set_str(pinfo->cinfo, COL_INFO, "TightVNC Interaction Capabilities");
proto_tree_add_item(tree, hf_vnc_num_server_message_types,
tvb, offset, 2, ENC_BIG_ENDIAN);
per_conversation_info->num_server_message_types = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_vnc_num_client_message_types,
tvb, offset, 2, ENC_BIG_ENDIAN);
per_conversation_info->num_client_message_types = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_vnc_num_encoding_types,
tvb, offset, 2, ENC_BIG_ENDIAN);
per_conversation_info->num_encoding_types = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_vnc_padding, tvb, offset, 2,
ENC_NA);
offset += 2;
offset = process_tight_capabilities(tree,
hf_vnc_tight_server_message_type,
hf_vnc_tight_server_vendor,
hf_vnc_tight_server_name,
tvb, offset, per_conversation_info->num_server_message_types);
offset = process_tight_capabilities(tree,
hf_vnc_tight_client_message_type,
hf_vnc_tight_client_vendor,
hf_vnc_tight_client_name,
tvb, offset, per_conversation_info->num_client_message_types);
process_tight_capabilities(tree,
hf_vnc_tight_encoding_type,
hf_vnc_tight_encoding_vendor,
hf_vnc_tight_encoding_name,
tvb, offset, per_conversation_info->num_encoding_types);
per_conversation_info->vnc_next_state = VNC_SESSION_STATE_NORMAL_TRAFFIC;
break;
case VNC_SESSION_STATE_NORMAL_TRAFFIC :
return FALSE;
}
return TRUE;
}
static void
vnc_client_to_server(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
guint8 message_type;
proto_item *ti = NULL;
proto_tree *vnc_client_message_type_tree;
message_type = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_item(tree, hf_vnc_client_message_type, tvb,
*offset, 1, ENC_BIG_ENDIAN);
vnc_client_message_type_tree =
proto_item_add_subtree(ti, ett_vnc_client_message_type);
*offset += 1;
switch(message_type) {
case VNC_CLIENT_MESSAGE_TYPE_SET_PIXEL_FORMAT :
vnc_client_set_pixel_format(tvb, pinfo, offset,
vnc_client_message_type_tree);
break;
case VNC_CLIENT_MESSAGE_TYPE_SET_ENCODING :
vnc_client_set_encodings(tvb, pinfo, offset,
vnc_client_message_type_tree);
break;
case VNC_CLIENT_MESSAGE_TYPE_FRAMEBUF_UPDATE_REQ :
vnc_client_framebuffer_update_request(tvb, pinfo, offset,
vnc_client_message_type_tree);
break;
case VNC_CLIENT_MESSAGE_TYPE_KEY_EVENT :
vnc_client_key_event(tvb, pinfo, offset,
vnc_client_message_type_tree);
break;
case VNC_CLIENT_MESSAGE_TYPE_POINTER_EVENT:
vnc_client_pointer_event(tvb, pinfo, offset,
vnc_client_message_type_tree);
break;
case VNC_CLIENT_MESSAGE_TYPE_CLIENT_CUT_TEXT :
vnc_client_cut_text(tvb, pinfo, offset,
vnc_client_message_type_tree);
break;
default :
col_append_fstr(pinfo->cinfo, COL_INFO,
"Unknown client message type (%u)",
message_type);
break;
}
}
static void
vnc_server_to_client(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
gint start_offset;
guint8 message_type;
gint bytes_needed = 0, length_remaining;
proto_item *ti = NULL;
proto_tree *vnc_server_message_type_tree;
start_offset = *offset;
message_type = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_item(tree, hf_vnc_server_message_type, tvb,
*offset, 1, ENC_BIG_ENDIAN);
vnc_server_message_type_tree =
proto_item_add_subtree(ti, ett_vnc_server_message_type);
*offset += 1;
switch(message_type) {
case VNC_SERVER_MESSAGE_TYPE_FRAMEBUFFER_UPDATE :
bytes_needed =
vnc_server_framebuffer_update(tvb, pinfo, offset,
vnc_server_message_type_tree);
break;
case VNC_SERVER_MESSAGE_TYPE_SET_COLORMAP_ENTRIES :
bytes_needed = vnc_server_set_colormap_entries(tvb, pinfo, offset, vnc_server_message_type_tree);
break;
case VNC_SERVER_MESSAGE_TYPE_RING_BELL :
vnc_server_ring_bell(tvb, pinfo, offset,
vnc_server_message_type_tree);
break;
case VNC_SERVER_MESSAGE_TYPE_CUT_TEXT :
bytes_needed = vnc_server_cut_text(tvb, pinfo, offset,
vnc_server_message_type_tree);
break;
default :
col_append_str(pinfo->cinfo, COL_INFO,
"Unknown server message type");
break;
}
if(bytes_needed > 0 && vnc_preference_desegment &&
pinfo->can_desegment) {
length_remaining = tvb_length_remaining(tvb, *offset);
pinfo->desegment_offset = start_offset;
pinfo->desegment_len = bytes_needed - length_remaining;
return;
}
}
static void
vnc_client_set_pixel_format(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Client set pixel format");
proto_tree_add_item(tree, hf_vnc_padding, tvb, *offset,
3, ENC_NA);
*offset += 3;
proto_tree_add_item(tree, hf_vnc_client_bits_per_pixel, tvb, *offset,
1, ENC_BIG_ENDIAN);
vnc_bytes_per_pixel = tvb_get_guint8(tvb, *offset)/8;
vnc_set_bytes_per_pixel(pinfo, vnc_bytes_per_pixel);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_client_depth, tvb, *offset,
1, ENC_BIG_ENDIAN);
vnc_depth = tvb_get_guint8(tvb, *offset);
vnc_set_depth(pinfo, vnc_depth);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_client_big_endian_flag, tvb, *offset,
1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_client_true_color_flag, tvb, *offset,
1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_client_red_max, tvb, *offset,
2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_client_green_max, tvb, *offset,
2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_client_blue_max, tvb, *offset,
2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_client_red_shift, tvb, *offset,
1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_client_green_shift, tvb, *offset,
1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_client_blue_shift, tvb, *offset,
1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_padding, tvb, *offset, 3, ENC_NA);
*offset += 3;
}
static void
vnc_client_set_encodings(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
guint16 number_of_encodings;
guint counter;
vnc_packet_t *per_packet_info;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
DISSECTOR_ASSERT(per_packet_info != NULL);
col_set_str(pinfo->cinfo, COL_INFO, "Client set encodings");
proto_tree_add_item(tree, hf_vnc_padding,
tvb, *offset, 1, ENC_NA);
*offset += 1;
number_of_encodings = tvb_get_ntohs(tvb, *offset);
proto_tree_add_text(tree, tvb, *offset, 2,
"Number of encodings: %d", number_of_encodings);
*offset += 2;
per_packet_info->preferred_encoding = -1;
for(counter = 1; counter <= number_of_encodings; counter++) {
proto_tree_add_item(tree,
hf_vnc_client_set_encodings_encoding_type,
tvb, *offset, 4, ENC_BIG_ENDIAN);
if (per_packet_info->preferred_encoding == -1) {
int encoding;
encoding = tvb_get_ntohl(tvb, *offset);
switch(encoding) {
case VNC_ENCODING_TYPE_RAW:
case VNC_ENCODING_TYPE_RRE:
case VNC_ENCODING_TYPE_CORRE:
case VNC_ENCODING_TYPE_HEXTILE:
case VNC_ENCODING_TYPE_ZLIB:
case VNC_ENCODING_TYPE_TIGHT:
per_packet_info->preferred_encoding = encoding;
break;
}
}
*offset += 4;
}
if (per_packet_info->preferred_encoding == -1)
per_packet_info->preferred_encoding = VNC_ENCODING_TYPE_RAW;
}
static void
vnc_client_framebuffer_update_request(tvbuff_t *tvb, packet_info *pinfo,
gint *offset, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Client framebuffer update request");
proto_tree_add_item(tree, hf_vnc_update_req_incremental,
tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_update_req_x_pos,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_update_req_y_pos,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_update_req_width, tvb,
*offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_update_req_height, tvb,
*offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
}
static void
vnc_client_key_event(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Client key event");
proto_tree_add_item(tree, hf_vnc_key_down, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_padding, tvb, *offset, 2, ENC_NA);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_key, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
}
static void
vnc_client_pointer_event(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Client pointer event");
proto_tree_add_item(tree, hf_vnc_button_1_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_2_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_3_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_4_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_5_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_6_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_7_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_vnc_button_8_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_pointer_x_pos, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_pointer_y_pos, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
}
static void
vnc_client_cut_text(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
guint32 text_len;
col_set_str(pinfo->cinfo, COL_INFO, "Client cut text");
proto_tree_add_item(tree, hf_vnc_padding, tvb, *offset, 3, ENC_NA);
*offset += 3;
text_len = tvb_get_ntohl(tvb, *offset);
proto_tree_add_item(tree, hf_vnc_client_cut_text_len, tvb, *offset, 4,
ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_vnc_client_cut_text, tvb, *offset,
text_len, ENC_ASCII|ENC_NA);
*offset += text_len;
}
static guint
vnc_server_framebuffer_update(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
gint i;
guint16 num_rects, width, height;
guint bytes_needed = 0;
guint32 encoding_type;
proto_item *ti, *ti_x, *ti_y, *ti_width, *ti_height;
proto_tree *vnc_rect_tree, *vnc_encoding_type_tree;
col_set_str(pinfo->cinfo, COL_INFO, "Server framebuffer update");
proto_tree_add_item(tree, hf_vnc_padding, tvb, *offset, 1, ENC_NA);
*offset += 1;
num_rects = tvb_get_ntohs(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 2, "Number of rectangles: %d",
num_rects);
if (num_rects > 5000) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Too many rectangles, aborting dissection");
return(0);
}
*offset += 2;
VNC_BYTES_NEEDED((guint)12*num_rects);
for(i = 1; i <= num_rects; i++) {
ti = proto_tree_add_text(tree, tvb, *offset, 12,
"Rectangle #%d", i);
vnc_rect_tree =
proto_item_add_subtree(ti, ett_vnc_rect);
ti_x = proto_tree_add_item(vnc_rect_tree, hf_vnc_fb_update_x_pos,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
ti_y = proto_tree_add_item(vnc_rect_tree, hf_vnc_fb_update_y_pos,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
ti_width = proto_tree_add_item(vnc_rect_tree, hf_vnc_fb_update_width,
tvb, *offset, 2, ENC_BIG_ENDIAN);
width = tvb_get_ntohs(tvb, *offset);
*offset += 2;
ti_height = proto_tree_add_item(vnc_rect_tree, hf_vnc_fb_update_height,
tvb, *offset, 2, ENC_BIG_ENDIAN);
height = tvb_get_ntohs(tvb, *offset);
*offset += 2;
ti = proto_tree_add_item(vnc_rect_tree,
hf_vnc_fb_update_encoding_type,
tvb, *offset, 4, ENC_BIG_ENDIAN);
encoding_type = tvb_get_ntohl(tvb, *offset);
*offset += 4;
if (encoding_type == VNC_ENCODING_TYPE_LAST_RECT)
break;
vnc_encoding_type_tree =
proto_item_add_subtree(ti, ett_vnc_encoding_type);
switch(encoding_type) {
case VNC_ENCODING_TYPE_RAW:
bytes_needed = vnc_raw_encoding(tvb, pinfo, offset,
vnc_encoding_type_tree,
width, height);
break;
case VNC_ENCODING_TYPE_COPY_RECT:
bytes_needed =
vnc_copyrect_encoding(tvb, pinfo, offset,
vnc_encoding_type_tree,
width, height);
break;
case VNC_ENCODING_TYPE_RRE:
bytes_needed =
vnc_rre_encoding(tvb, pinfo, offset,
vnc_encoding_type_tree,
width, height);
break;
case VNC_ENCODING_TYPE_HEXTILE:
bytes_needed =
vnc_hextile_encoding(tvb, pinfo, offset,
vnc_encoding_type_tree,
width, height);
break;
case VNC_ENCODING_TYPE_RLE:
bytes_needed =
vnc_zrle_encoding(tvb, pinfo, offset,
vnc_encoding_type_tree,
width, height);
break;
case VNC_ENCODING_TYPE_TIGHT:
bytes_needed =
vnc_tight_encoding(tvb, pinfo, offset,
vnc_encoding_type_tree,
width, height);
break;
case VNC_ENCODING_TYPE_RICH_CURSOR:
case VNC_ENCODING_TYPE_X_CURSOR:
proto_item_append_text (ti_x, " (hotspot X)");
proto_item_append_text (ti_y, " (hotspot Y)");
proto_item_append_text (ti_width, " (cursor width)");
proto_item_append_text (ti_height, " (cursor height)");
if (encoding_type == VNC_ENCODING_TYPE_RICH_CURSOR)
bytes_needed = vnc_rich_cursor_encoding(tvb, pinfo, offset, vnc_encoding_type_tree, width, height);
else
bytes_needed = vnc_x_cursor_encoding(tvb, pinfo, offset, vnc_encoding_type_tree, width, height);
break;
case VNC_ENCODING_TYPE_POINTER_POS:
proto_item_append_text (ti_x, " (pointer X)");
proto_item_append_text (ti_y, " (pointer Y)");
proto_item_append_text (ti_width, " (unused)");
proto_item_append_text (ti_height, " (unused)");
bytes_needed = 0;
break;
case VNC_ENCODING_TYPE_DESKTOP_SIZE:
bytes_needed = 0;
break;
case VNC_ENCODING_TYPE_EXTENDED_DESK_SIZE :
bytes_needed = vnc_extended_desktop_size(tvb, offset, vnc_encoding_type_tree);
break;
}
if(bytes_needed > 0)
return bytes_needed;
}
return 0;
}
static guint32
vnc_extended_desktop_size(tvbuff_t *tvb, gint *offset, proto_tree *tree)
{
guint8 i, num_of_screens;
proto_item *ti;
proto_tree *screen_tree;
num_of_screens = tvb_get_guint8(tvb, *offset);
proto_tree_add_text(tree, tvb, *offset, 1, "Number of screens: %d", num_of_screens);
*offset += 1;
proto_tree_add_text(tree, tvb, *offset, 3, "Padding");
VNC_BYTES_NEEDED((guint32)(3 + (num_of_screens * 16)));
*offset += 3;
for(i = 1; i <= num_of_screens; i++) {
ti = proto_tree_add_text(tree, tvb, *offset, 16, "Screen #%u", i);
screen_tree = proto_item_add_subtree(ti, ett_vnc_desktop_screen);
proto_tree_add_item(screen_tree, hf_vnc_desktop_screen_id, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(screen_tree, hf_vnc_desktop_screen_x, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(screen_tree, hf_vnc_desktop_screen_y, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(screen_tree, hf_vnc_desktop_screen_width, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(screen_tree, hf_vnc_desktop_screen_height, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(screen_tree, hf_vnc_desktop_screen_flags, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
}
return 0;
}
static guint
vnc_raw_encoding(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree, const guint16 width, const guint16 height)
{
guint8 bytes_per_pixel = vnc_get_bytes_per_pixel(pinfo);
guint length;
length = width * height * bytes_per_pixel;
VNC_BYTES_NEEDED(length);
proto_tree_add_item(tree, hf_vnc_raw_pixel_data, tvb, *offset,
length, ENC_NA);
*offset += length;
return 0;
}
static guint
vnc_copyrect_encoding(tvbuff_t *tvb, packet_info *pinfo _U_, gint *offset,
proto_tree *tree, const guint16 width _U_, const guint16 height _U_)
{
proto_tree_add_item(tree, hf_vnc_copyrect_src_x_pos, tvb, *offset,
2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_vnc_copyrect_src_y_pos, tvb, *offset,
2, ENC_BIG_ENDIAN);
*offset += 2;
return 0;
}
static guint
vnc_rre_encoding(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree, const guint16 width _U_, const guint16 height _U_)
{
guint8 bytes_per_pixel = vnc_get_bytes_per_pixel(pinfo);
guint32 num_subrects, i;
guint bytes_needed;
proto_item *ti;
proto_tree *subrect_tree;
VNC_BYTES_NEEDED(4);
ti = proto_tree_add_item(tree, hf_vnc_rre_num_subrects, tvb, *offset,
4, ENC_BIG_ENDIAN);
num_subrects = tvb_get_ntohl(tvb, *offset);
*offset += 4;
if (num_subrects > 10000) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Too many sub-rectangles, aborting dissection");
return(0);
}
*offset += 2;
VNC_BYTES_NEEDED(bytes_per_pixel);
proto_tree_add_item(tree, hf_vnc_rre_bg_pixel, tvb, *offset,
bytes_per_pixel, ENC_NA);
*offset += bytes_per_pixel;
bytes_needed = bytes_per_pixel + 8;
VNC_BYTES_NEEDED(bytes_needed * num_subrects);
for(i = 1; i <= num_subrects; i++) {
ti = proto_tree_add_text(tree, tvb, *offset, bytes_per_pixel +
8, "Subrectangle #%d", i);
subrect_tree =
proto_item_add_subtree(ti, ett_vnc_rre_subrect);
proto_tree_add_item(subrect_tree, hf_vnc_rre_subrect_pixel,
tvb, *offset, bytes_per_pixel, ENC_NA);
*offset += bytes_per_pixel;
proto_tree_add_item(subrect_tree, hf_vnc_rre_subrect_x_pos,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(subrect_tree, hf_vnc_rre_subrect_y_pos,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(subrect_tree, hf_vnc_rre_subrect_width,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(subrect_tree, hf_vnc_rre_subrect_height,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
}
return 0;
}
static guint
vnc_hextile_encoding(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree, const guint16 width, const guint16 height)
{
guint8 bytes_per_pixel = vnc_get_bytes_per_pixel(pinfo);
guint8 i, subencoding_mask, num_subrects, subrect_len, tile_height, tile_width;
guint32 raw_length;
proto_tree *tile_tree, *subencoding_mask_tree, *subrect_tree, *num_subrects_tree;
proto_item *ti, *tile_item;
guint16 current_height = 0, current_width;
while(current_height != height) {
if (current_height + 16 > height)
tile_height = height - current_height;
else
tile_height = 16;
current_height += tile_height;
current_width = 0;
while(current_width != width) {
if (current_width + 16 > width)
tile_width = width - current_width;
else
tile_width = 16;
current_width += tile_width;
VNC_BYTES_NEEDED(1);
subencoding_mask = tvb_get_guint8(tvb, *offset);
tile_item = proto_tree_add_text(tree, tvb, *offset, 1, "Tile {%d:%d}, sub encoding mask %u", current_width, current_height, subencoding_mask);
tile_tree = proto_item_add_subtree(tile_item, ett_vnc_hextile_tile);
ti = proto_tree_add_item(tile_tree, hf_vnc_hextile_subencoding_mask, tvb,
*offset, 1, ENC_BIG_ENDIAN);
subencoding_mask_tree =
proto_item_add_subtree(ti, ett_vnc_hextile_subencoding_mask);
proto_tree_add_item(subencoding_mask_tree,
hf_vnc_hextile_raw, tvb, *offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(subencoding_mask_tree,
hf_vnc_hextile_bg, tvb, *offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(subencoding_mask_tree,
hf_vnc_hextile_fg, tvb, *offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(subencoding_mask_tree,
hf_vnc_hextile_anysubrects, tvb, *offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(subencoding_mask_tree,
hf_vnc_hextile_subrectscolored, tvb, *offset, 1,
ENC_BIG_ENDIAN);
*offset += 1;
if(subencoding_mask & 0x1) {
raw_length = tile_width * tile_height * bytes_per_pixel;
proto_tree_add_item(tile_tree, hf_vnc_hextile_raw_value, tvb,
*offset, raw_length, ENC_NA);
VNC_BYTES_NEEDED(raw_length);
*offset += raw_length;
} else {
if(subencoding_mask & 0x2) {
VNC_BYTES_NEEDED(bytes_per_pixel);
proto_tree_add_item(tile_tree, hf_vnc_hextile_bg_value,
tvb, *offset, bytes_per_pixel,
ENC_NA);
*offset += bytes_per_pixel;
}
if(subencoding_mask & 0x4) {
VNC_BYTES_NEEDED(bytes_per_pixel);
proto_tree_add_item(tile_tree, hf_vnc_hextile_fg_value,
tvb, *offset, bytes_per_pixel,
ENC_NA);
*offset += bytes_per_pixel;
}
if(subencoding_mask & 0x8) {
VNC_BYTES_NEEDED(3);
ti = proto_tree_add_item(tile_tree,
hf_vnc_hextile_num_subrects,
tvb, *offset, 1,
ENC_BIG_ENDIAN);
num_subrects = tvb_get_guint8(tvb, *offset);
*offset += 1;
if(subencoding_mask & 0x10)
subrect_len = bytes_per_pixel + 2;
else
subrect_len = 2;
VNC_BYTES_NEEDED((guint)(subrect_len * num_subrects));
num_subrects_tree =
proto_item_add_subtree(ti, ett_vnc_hextile_num_subrects);
for(i = 1; i <= num_subrects; i++) {
ti = proto_tree_add_text(num_subrects_tree, tvb,
*offset, subrect_len,
"Subrectangle #%d", i);
subrect_tree =
proto_item_add_subtree(ti, ett_vnc_hextile_subrect);
if(subencoding_mask & 0x10) {
proto_tree_add_item(subrect_tree, hf_vnc_hextile_subrect_pixel_value, tvb, *offset, bytes_per_pixel, ENC_NA);
*offset += bytes_per_pixel;
}
proto_tree_add_item(subrect_tree,
hf_vnc_hextile_subrect_x_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subrect_tree, hf_vnc_hextile_subrect_y_pos, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(subrect_tree, hf_vnc_hextile_subrect_width, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subrect_tree, hf_vnc_hextile_subrect_height, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
}
}
}
}
}
return 0;
}
static guint
read_compact_len(tvbuff_t *tvb, gint *offset, gint *length, gint *value_length)
{
gint b;
VNC_BYTES_NEEDED(1);
*value_length = 0;
b = tvb_get_guint8(tvb, *offset);
*offset += 1;
*value_length += 1;
*length = b & 0x7f;
if ((b & 0x80) != 0) {
VNC_BYTES_NEEDED(1);
b = tvb_get_guint8(tvb, *offset);
*offset += 1;
*value_length += 1;
*length |= (b & 0x7f) << 7;
if ((b & 0x80) != 0) {
VNC_BYTES_NEEDED (1);
b = tvb_get_guint8(tvb, *offset);
*offset += 1;
*value_length += 1;
*length |= (b & 0xff) << 14;
}
}
return 0;
}
static guint
process_compact_length_and_image_data(tvbuff_t *tvb, gint *offset, proto_tree *tree)
{
guint bytes_needed;
guint length, value_length;
bytes_needed = read_compact_len (tvb, offset, &length, &value_length);
if (bytes_needed != 0)
return bytes_needed;
proto_tree_add_uint(tree, hf_vnc_tight_image_len, tvb, *offset - value_length, value_length, length);
VNC_BYTES_NEEDED(length);
proto_tree_add_item(tree, hf_vnc_tight_image_data, tvb, *offset, length, ENC_NA);
*offset += length;
return 0;
}
static guint
process_tight_rect_filter_palette(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree, gint *bits_per_pixel)
{
vnc_packet_t *per_packet_info;
gint num_colors;
guint palette_bytes;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
DISSECTOR_ASSERT(per_packet_info != NULL);
VNC_BYTES_NEEDED(1);
proto_tree_add_item(tree, hf_vnc_tight_palette_num_colors, tvb, *offset, 1, ENC_BIG_ENDIAN);
num_colors = tvb_get_guint8(tvb, *offset);
*offset += 1;
num_colors++;
if (num_colors < 2)
return 0;
if (per_packet_info->depth == 24)
palette_bytes = num_colors * 3;
else
palette_bytes = num_colors * per_packet_info->depth / 8;
VNC_BYTES_NEEDED(palette_bytes);
proto_tree_add_item(tree, hf_vnc_tight_palette_data, tvb, *offset, palette_bytes, ENC_NA);
*offset += palette_bytes;
if (num_colors == 2)
*bits_per_pixel = 1;
else
*bits_per_pixel = 8;
return 0;
}
static guint
vnc_tight_encoding(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree, const guint16 width _U_, const guint16 height _U_)
{
vnc_packet_t *per_packet_info;
guint8 comp_ctl;
proto_item *compression_type_ti;
gint bit_offset;
gint bytes_needed = -1;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
DISSECTOR_ASSERT(per_packet_info != NULL);
VNC_BYTES_NEEDED(1);
bit_offset = *offset * 8;
proto_tree_add_bits_item(tree, hf_vnc_tight_reset_stream0, tvb, bit_offset + 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_vnc_tight_reset_stream1, tvb, bit_offset + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_vnc_tight_reset_stream2, tvb, bit_offset + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_vnc_tight_reset_stream3, tvb, bit_offset + 4, 1, ENC_BIG_ENDIAN);
compression_type_ti = proto_tree_add_bits_item(tree, hf_vnc_tight_rect_type, tvb, bit_offset + 0, 4, ENC_BIG_ENDIAN);
comp_ctl = tvb_get_guint8(tvb, *offset);
*offset += 1;
comp_ctl >>= 4;
if (comp_ctl == TIGHT_RECT_FILL) {
proto_item_append_text(compression_type_ti, " (fill encoding - solid rectangle)");
if (per_packet_info->depth == 24) {
VNC_BYTES_NEEDED(3);
proto_tree_add_item(tree, hf_vnc_tight_fill_color, tvb, *offset, 3, ENC_NA);
*offset += 3;
} else {
VNC_BYTES_NEEDED(per_packet_info->bytes_per_pixel);
proto_tree_add_item(tree, hf_vnc_tight_fill_color, tvb, *offset, per_packet_info->bytes_per_pixel, ENC_NA);
*offset += per_packet_info->bytes_per_pixel;
}
bytes_needed = 0;
} else if (comp_ctl == TIGHT_RECT_JPEG) {
proto_item_append_text(compression_type_ti, " (JPEG encoding)");
bytes_needed = process_compact_length_and_image_data(tvb, offset, tree);
if (bytes_needed != 0)
return bytes_needed;
} else if (comp_ctl > TIGHT_RECT_MAX_VALUE) {
expert_add_info_format(pinfo, compression_type_ti, PI_MALFORMED, PI_ERROR,
"Invalid encoding");
} else {
guint row_size;
gint bits_per_pixel;
proto_item_append_text(compression_type_ti, " (basic encoding)");
proto_tree_add_bits_item(tree, hf_vnc_tight_filter_flag, tvb, bit_offset + 1, 1, ENC_BIG_ENDIAN);
bits_per_pixel = per_packet_info->depth;
if ((comp_ctl & TIGHT_RECT_EXPLICIT_FILTER_FLAG) != 0) {
guint8 filter_id;
VNC_BYTES_NEEDED(1);
proto_tree_add_item(tree, hf_vnc_tight_filter_id, tvb, *offset, 1, ENC_BIG_ENDIAN);
filter_id = tvb_get_guint8(tvb, *offset);
*offset += 1;
switch (filter_id) {
case TIGHT_RECT_FILTER_COPY:
break;
case TIGHT_RECT_FILTER_PALETTE:
bytes_needed = process_tight_rect_filter_palette(tvb, pinfo, offset, tree, &bits_per_pixel);
if (bytes_needed != 0)
return bytes_needed;
break;
case TIGHT_RECT_FILTER_GRADIENT:
break;
}
} else {
}
row_size = ((guint) width * bits_per_pixel + 7) / 8;
if (row_size * height < TIGHT_MIN_BYTES_TO_COMPRESS) {
guint num_bytes;
num_bytes = row_size * height;
VNC_BYTES_NEEDED(num_bytes);
proto_tree_add_item(tree, hf_vnc_tight_image_data, tvb, *offset, num_bytes, ENC_NA);
*offset += num_bytes;
bytes_needed = 0;
} else {
bytes_needed = process_compact_length_and_image_data(tvb, offset, tree);
if (bytes_needed != 0)
return bytes_needed;
}
}
DISSECTOR_ASSERT(bytes_needed != -1);
return bytes_needed;
}
static guint
decode_cursor(tvbuff_t *tvb, gint *offset, proto_tree *tree,
guint pixels_bytes, guint mask_bytes)
{
guint total_bytes;
total_bytes = pixels_bytes + mask_bytes;
VNC_BYTES_NEEDED (total_bytes);
proto_tree_add_item(tree, hf_vnc_cursor_encoding_pixels, tvb, *offset,
pixels_bytes, ENC_NA);
*offset += pixels_bytes;
proto_tree_add_item(tree, hf_vnc_cursor_encoding_bitmask, tvb, *offset,
mask_bytes, ENC_NA);
*offset += mask_bytes;
return 0;
}
static guint
vnc_rich_cursor_encoding(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree, const guint16 width, const guint16 height)
{
guint8 bytes_per_pixel = vnc_get_bytes_per_pixel(pinfo);
guint pixels_bytes, mask_bytes;
pixels_bytes = width * height * bytes_per_pixel;
mask_bytes = ((width + 7) / 8) * height;
return decode_cursor(tvb, offset, tree,
pixels_bytes, mask_bytes);
}
static guint
vnc_x_cursor_encoding(tvbuff_t *tvb, packet_info *pinfo _U_, gint *offset,
proto_tree *tree, const guint16 width, const guint16 height)
{
gint bitmap_row_bytes = (width + 7) / 8;
gint mask_bytes = bitmap_row_bytes * height;
VNC_BYTES_NEEDED (6);
proto_tree_add_item(tree, hf_vnc_cursor_x_fore_back, tvb, *offset, 6, ENC_NA);
*offset += 6;
return decode_cursor(tvb, offset, tree,
mask_bytes, mask_bytes);
}
static guint
vnc_server_set_colormap_entries(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
guint16 number_of_colors;
guint counter, bytes_needed;
proto_item *ti;
proto_tree *vnc_colormap_num_groups, *vnc_colormap_color_group;
col_set_str(pinfo->cinfo, COL_INFO, "Server set colormap entries");
number_of_colors = tvb_get_ntohs(tvb, 4);
VNC_BYTES_NEEDED(3);
proto_tree_add_item(tree, hf_vnc_padding, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_vnc_colormap_first_color,
tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
ti = proto_tree_add_item(tree, hf_vnc_colormap_num_colors, tvb,
*offset, 2, ENC_BIG_ENDIAN);
if (number_of_colors > 10000) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Too many colors (%d), aborting dissection",
number_of_colors);
return(0);
}
bytes_needed = (number_of_colors * 6) + 5;
VNC_BYTES_NEEDED(bytes_needed);
*offset += 2;
ti = proto_tree_add_item(tree, hf_vnc_color_groups, tvb,
*offset, number_of_colors * 6, ENC_NA);
vnc_colormap_num_groups =
proto_item_add_subtree(ti, ett_vnc_colormap_num_groups);
for(counter = 1; counter <= number_of_colors; counter++) {
ti = proto_tree_add_text(vnc_colormap_num_groups, tvb,
*offset, 6,
"Color group #%d", counter);
vnc_colormap_color_group =
proto_item_add_subtree(ti,
ett_vnc_colormap_color_group);
proto_tree_add_item(vnc_colormap_color_group,
hf_vnc_colormap_red, tvb,
*offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(vnc_colormap_color_group,
hf_vnc_colormap_green, tvb,
*offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(vnc_colormap_color_group,
hf_vnc_colormap_blue, tvb,
*offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
}
return 0;
}
static void
vnc_server_ring_bell(tvbuff_t *tvb _U_, packet_info *pinfo, gint *offset _U_,
proto_tree *tree _U_)
{
col_set_str(pinfo->cinfo, COL_INFO, "Server ring bell on client");
}
static guint
vnc_server_cut_text(tvbuff_t *tvb, packet_info *pinfo, gint *offset,
proto_tree *tree)
{
guint32 text_len;
proto_item *pi;
col_set_str(pinfo->cinfo, COL_INFO, "Server cut text");
text_len = tvb_get_ntohl(tvb, *offset);
pi = proto_tree_add_item(tree, hf_vnc_server_cut_text_len, tvb, *offset, 4,
ENC_BIG_ENDIAN);
*offset += 4;
if (text_len > 100000) {
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Too much cut text, aborting dissection");
return(0);
}
VNC_BYTES_NEEDED(text_len);
proto_tree_add_item(tree, hf_vnc_server_cut_text, tvb, *offset,
text_len, ENC_ASCII|ENC_NA);
*offset += text_len;
return *offset;
}
static void
vnc_set_bytes_per_pixel(const packet_info *pinfo, const guint8 bytes_per_pixel)
{
vnc_packet_t *per_packet_info;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
DISSECTOR_ASSERT(per_packet_info != NULL);
per_packet_info->bytes_per_pixel = bytes_per_pixel;
}
static void
vnc_set_depth(const packet_info *pinfo, const guint8 depth)
{
vnc_packet_t *per_packet_info;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
DISSECTOR_ASSERT(per_packet_info != NULL);
per_packet_info->depth = depth;
}
static guint8
vnc_get_bytes_per_pixel(const packet_info *pinfo)
{
vnc_packet_t *per_packet_info;
per_packet_info = p_get_proto_data(pinfo->fd, proto_vnc);
DISSECTOR_ASSERT(per_packet_info != NULL);
return per_packet_info->bytes_per_pixel;
}
void
proto_register_vnc(void)
{
module_t *vnc_module;
static hf_register_info hf[] = {
{ &hf_vnc_padding,
{ "Padding", "vnc.padding",
FT_NONE, BASE_NONE, NULL, 0x0,
"Unused space", HFILL }
},
{ &hf_vnc_server_proto_ver,
{ "Server protocol version", "vnc.server_proto_ver",
FT_STRING, BASE_NONE, NULL, 0x0,
"VNC protocol version on server", HFILL }
},
{ &hf_vnc_client_proto_ver,
{ "Client protocol version", "vnc.client_proto_ver",
FT_STRING, BASE_NONE, NULL, 0x0,
"VNC protocol version on client", HFILL }
},
{ &hf_vnc_num_security_types,
{ "Number of security types", "vnc.num_security_types",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of security (authentication) types supported by the server", HFILL }
},
{ &hf_vnc_security_type,
{ "Security type", "vnc.security_type",
FT_UINT8, BASE_DEC, VALS(vnc_security_types_vs), 0x0,
"Security types offered by the server (VNC versions => 3.007", HFILL }
},
{ &hf_vnc_server_security_type,
{ "Security type", "vnc.server_security_type",
FT_UINT32, BASE_DEC, VALS(vnc_security_types_vs), 0x0,
"Security type mandated by the server", HFILL }
},
{ &hf_vnc_client_security_type,
{ "Security type selected", "vnc.client_security_type",
FT_UINT8, BASE_DEC, VALS(vnc_security_types_vs), 0x0,
"Security type selected by the client", HFILL }
},
{ &hf_vnc_tight_num_tunnel_types,
{ "Number of supported tunnel types", "vnc.num_tunnel_types",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of tunnel types for TightVNC", HFILL }
},
{ &hf_vnc_tight_tunnel_type,
{ "Tunnel type", "vnc.tunnel_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Tunnel type specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_num_auth_types,
{ "Number of supported authentication types", "vnc.num_auth_types",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Authentication types specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_auth_code,
{ "Authentication code", "vnc.tight_auth_code",
FT_UINT32, BASE_DEC, VALS(vnc_security_types_vs), 0x0,
"Authentication code specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_server_message_type,
{ "Server message type (TightVNC)", "vnc.tight_server_message_type",
FT_INT32, BASE_DEC, NULL, 0x0,
"Server message type specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_server_vendor,
{ "Server vendor code", "vnc.server_vendor",
FT_STRING, BASE_NONE, NULL, 0x0,
"Server vendor code specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_server_name,
{ "Server name", "vnc.server_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Server name specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_client_message_type,
{ "Client message type (TightVNC)", "vnc.tight_client_message_type",
FT_INT32, BASE_DEC, NULL, 0x0,
"Client message type specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_client_vendor,
{ "Client vendor code", "vnc.client_vendor",
FT_STRING, BASE_NONE, NULL, 0x0,
"Client vendor code specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_client_name,
{ "Client name", "vnc.client_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Client name specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_encoding_type,
{ "Encoding type", "vnc.encoding_type",
FT_INT32, BASE_DEC, VALS(encoding_types_vs), 0x0,
"Encoding type specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_encoding_vendor,
{ "Encoding vendor code", "vnc.encoding_vendor",
FT_STRING, BASE_NONE, NULL, 0x0,
"Encoding vendor code specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_encoding_name,
{ "Encoding name", "vnc.encoding_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Encoding name specific to TightVNC", HFILL }
},
{ &hf_vnc_tight_reset_stream0,
{ "Reset compression stream 0", "vnc.tight_reset_stream0",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Tight compression, reset compression stream 0", HFILL }
},
{ &hf_vnc_tight_reset_stream1,
{ "Reset compression stream 1", "vnc.tight_reset_stream1",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Tight compression, reset compression stream 1", HFILL }
},
{ &hf_vnc_tight_reset_stream2,
{ "Reset compression stream 2", "vnc.tight_reset_stream2",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Tight compression, reset compression stream 2", HFILL }
},
{ &hf_vnc_tight_reset_stream3,
{ "Reset compression stream 3", "vnc.tight_reset_stream3",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Tight compression, reset compression stream 3", HFILL }
},
{ &hf_vnc_tight_rect_type,
{ "Rectangle type", "vnc.tight_rect_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Tight compression, rectangle type", HFILL }
},
{ &hf_vnc_tight_image_len,
{ "Image data length", "vnc.tight_image_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Tight compression, length of image data", HFILL }
},
{ &hf_vnc_tight_image_data,
{ "Image data", "vnc.tight_image_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Tight compression, image data", HFILL }
},
{ &hf_vnc_tight_fill_color,
{ "Fill color (RGB)", "vnc.tight_fill_color",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Tight compression, fill color for solid rectangle", HFILL }
},
{ &hf_vnc_tight_filter_flag,
{ "Explicit filter flag", "vnc.tight_filter_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Tight compression, explicit filter flag", HFILL }
},
{ &hf_vnc_tight_filter_id,
{ "Filter ID", "vnc.tight_filter_id",
FT_UINT8, BASE_DEC, VALS(tight_filter_ids_vs), 0x0,
"Tight compression, filter ID", HFILL }
},
{ &hf_vnc_tight_palette_num_colors,
{ "Number of colors in palette", "vnc.tight_palette_num_colors",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Tight compression, number of colors in rectangle's palette", HFILL }
},
{ &hf_vnc_tight_palette_data,
{ "Palette data", "vnc.tight_palette_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Tight compression, palette data for a rectangle", HFILL }
},
{ &hf_vnc_vendor_code,
{ "Vendor code", "vnc.vendor_code",
FT_STRING, BASE_NONE, NULL, 0x0,
"Identifies the VNC server software's vendor", HFILL }
},
{ &hf_vnc_security_type_string,
{ "Security type string", "vnc.security_type_string",
FT_STRING, BASE_NONE, NULL, 0x0,
"Security type being used", HFILL }
},
{ &hf_vnc_auth_challenge,
{ "Authentication challenge", "vnc.auth_challenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Random authentication challenge from server to client", HFILL }
},
{ &hf_vnc_auth_response,
{ "Authentication response", "vnc.auth_response",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Client's encrypted response to the server's authentication challenge", HFILL }
},
{ &hf_vnc_auth_result,
{ "Authentication result", "vnc.auth_result",
FT_BOOLEAN, 32, TFS(&auth_result_tfs), 0x1,
NULL, HFILL }
},
{ &hf_vnc_auth_error,
{ "Authentication error", "vnc.auth_error",
FT_STRING, BASE_NONE, NULL, 0x0,
"Authentication error (present only if the authentication result is fail", HFILL }
},
{ &hf_vnc_share_desktop_flag,
{ "Share desktop flag", "vnc.share_desktop_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Client's desire to share the server's desktop with other clients", HFILL }
},
{ &hf_vnc_width,
{ "Framebuffer width", "vnc.width",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Width of the framebuffer (screen) in pixels", HFILL }
},
{ &hf_vnc_height,
{ "Framebuffer height", "vnc.height",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Height of the framebuffer (screen) in pixels", HFILL }
},
{ &hf_vnc_server_bits_per_pixel,
{ "Bits per pixel", "vnc.server_bits_per_pixel",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of bits used by server for each pixel value on the wire from the server", HFILL }
},
{ &hf_vnc_server_depth,
{ "Depth", "vnc.server_depth",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of useful bits in the pixel value on server", HFILL }
},
{ &hf_vnc_server_big_endian_flag,
{ "Big endian flag", "vnc.server_big_endian_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True if multi-byte pixels are interpreted as big endian by server", HFILL }
},
{ &hf_vnc_server_true_color_flag,
{ "True color flag", "vnc.server_true_color_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"If true, then the next six items specify how to extract the red, green and blue intensities from the pixel value on the server.", HFILL }
},
{ &hf_vnc_server_red_max,
{ "Red maximum", "vnc.server_red_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum red value on server as n: 2^n - 1", HFILL }
},
{ &hf_vnc_server_green_max,
{ "Green maximum", "vnc.server_green_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum green value on server as n: 2^n - 1", HFILL }
},
{ &hf_vnc_server_blue_max,
{ "Blue maximum", "vnc.server_blue_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum blue value on server as n: 2^n - 1", HFILL }
},
{ &hf_vnc_server_red_shift,
{ "Red shift", "vnc.server_red_shift",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of shifts needed to get the red value in a pixel to the least significant bit on the server", HFILL }
},
{ &hf_vnc_server_green_shift,
{ "Green shift", "vnc.server_green_shift",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of shifts needed to get the green value in a pixel to the least significant bit on the server", HFILL }
},
{ &hf_vnc_server_blue_shift,
{ "Blue shift", "vnc.server_blue_shift",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of shifts needed to get the blue value in a pixel to the least significant bit on the server", HFILL }
},
{ &hf_vnc_desktop_name_len,
{ "Desktop name length", "vnc.desktop_name_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Length of desktop name in bytes", HFILL }
},
{ &hf_vnc_desktop_screen_id,
{ "Screen ID", "vnc.screen_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ID of screen", HFILL }
},
{ &hf_vnc_desktop_screen_x,
{ "Screen X position", "vnc.screen_x",
FT_UINT16, BASE_DEC, NULL, 0x0,
"X coordinate of screen", HFILL }
},
{ &hf_vnc_desktop_screen_y,
{ "Screen Y position", "vnc.screen_y",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Y coordinate of screen", HFILL }
},
{ &hf_vnc_desktop_screen_width,
{ "Screen width", "vnc.screen_width",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Width of screen", HFILL }
},
{ &hf_vnc_desktop_screen_height,
{ "Screen height", "vnc.screen_height",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Height of screen", HFILL }
},
{ &hf_vnc_desktop_screen_flags,
{ "Screen flags", "vnc.screen_flags",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flags of screen", HFILL }
},
{ &hf_vnc_desktop_name,
{ "Desktop name", "vnc.desktop_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name of the VNC desktop on the server", HFILL }
},
{ &hf_vnc_num_server_message_types,
{ "Server message types", "vnc.num_server_message_types",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Unknown", HFILL }
},
{ &hf_vnc_num_client_message_types,
{ "Client message types", "vnc.num_client_message_types",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Unknown", HFILL }
},
{ &hf_vnc_num_encoding_types,
{ "Encoding types", "vnc.num_encoding_types",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Unknown", HFILL }
},
{ &hf_vnc_client_message_type,
{ "Client Message Type", "vnc.client_message_type",
FT_UINT8, BASE_DEC, VALS(vnc_client_message_types_vs), 0x0,
"Message type from client", HFILL }
},
{ &hf_vnc_client_bits_per_pixel,
{ "Bits per pixel", "vnc.client_bits_per_pixel",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of bits used by server for each pixel value on the wire from the client", HFILL }
},
{ &hf_vnc_client_depth,
{ "Depth", "vnc.client_depth",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of useful bits in the pixel value on client", HFILL }
},
{ &hf_vnc_client_big_endian_flag,
{ "Big endian flag", "vnc.client_big_endian_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True if multi-byte pixels are interpreted as big endian by client", HFILL }
},
{ &hf_vnc_client_true_color_flag,
{ "True color flag", "vnc.client_true_color_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"If true, then the next six items specify how to extract the red, green and blue intensities from the pixel value on the client.", HFILL }
},
{ &hf_vnc_client_red_max,
{ "Red maximum", "vnc.client_red_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum red value on client as n: 2^n - 1", HFILL }
},
{ &hf_vnc_client_green_max,
{ "Green maximum", "vnc.client_green_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum green value on client as n: 2^n - 1", HFILL }
},
{ &hf_vnc_client_blue_max,
{ "Blue maximum", "vnc.client_blue_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum blue value on client as n: 2^n - 1", HFILL }
},
{ &hf_vnc_client_red_shift,
{ "Red shift", "vnc.client_red_shift",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of shifts needed to get the red value in a pixel to the least significant bit on the client", HFILL }
},
{ &hf_vnc_client_green_shift,
{ "Green shift", "vnc.client_green_shift",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of shifts needed to get the green value in a pixel to the least significant bit on the client", HFILL }
},
{ &hf_vnc_client_blue_shift,
{ "Blue shift", "vnc.client_blue_shift",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of shifts needed to get the blue value in a pixel to the least significant bit on the client", HFILL }
},
{ &hf_vnc_key_down,
{ "Key down", "vnc.key_down",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x0,
"Specifies whether the key is being pressed or not", HFILL }
},
{ &hf_vnc_key,
{ "Key", "vnc.key",
FT_UINT32, BASE_HEX, VALS(keysym_vals_source), 0x0,
"Key being pressed/depressed", HFILL }
},
{ &hf_vnc_button_1_pos,
{ "Mouse button #1 position", "vnc.button_1_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x1,
"Whether mouse button #1 is being pressed or not", HFILL }
},
{ &hf_vnc_button_2_pos,
{ "Mouse button #2 position", "vnc.button_2_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x2,
"Whether mouse button #2 is being pressed or not", HFILL }
},
{ &hf_vnc_button_3_pos,
{ "Mouse button #3 position", "vnc.button_3_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x4,
"Whether mouse button #3 is being pressed or not", HFILL }
},
{ &hf_vnc_button_4_pos,
{ "Mouse button #4 position", "vnc.button_4_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x8,
"Whether mouse button #4 is being pressed or not", HFILL }
},
{ &hf_vnc_button_5_pos,
{ "Mouse button #5 position", "vnc.button_5_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x10,
"Whether mouse button #5 is being pressed or not", HFILL }
},
{ &hf_vnc_button_6_pos,
{ "Mouse button #6 position", "vnc.button_6_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x20,
"Whether mouse button #6 is being pressed or not", HFILL }
},
{ &hf_vnc_button_7_pos,
{ "Mouse button #7 position", "vnc.button_7_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x40,
"Whether mouse button #7 is being pressed or not", HFILL }
},
{ &hf_vnc_button_8_pos,
{ "Mouse button #8 position", "vnc.button_8_pos",
FT_BOOLEAN, 8, TFS(&button_mask_tfs), 0x80,
"Whether mouse button #8 is being pressed or not", HFILL }
},
{ &hf_vnc_pointer_x_pos,
{ "X position", "vnc.pointer_x_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Position of mouse cursor on the x-axis", HFILL }
},
{ &hf_vnc_pointer_y_pos,
{ "Y position", "vnc.pointer_y_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Position of mouse cursor on the y-axis", HFILL }
},
{ &hf_vnc_client_set_encodings_encoding_type,
{ "Encoding type", "vnc.client_set_encodings_encoding_type",
FT_INT32, BASE_DEC, VALS(encoding_types_vs), 0x0,
"Type of encoding used to send pixel data from server to client", HFILL }
},
{ &hf_vnc_update_req_incremental,
{ "Incremental update", "vnc.update_req_incremental",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Specifies if the client wants an incremental update instead of a full one", HFILL }
},
{ &hf_vnc_update_req_x_pos,
{ "X position", "vnc.update_req_x_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"X position of framebuffer (screen) update requested", HFILL }
},
{ &hf_vnc_update_req_y_pos,
{ "Y position", "vnc.update_req_y_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Y position of framebuffer (screen) update request", HFILL }
},
{ &hf_vnc_update_req_width,
{ "Width", "vnc.update_req_width",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Width of framebuffer (screen) update request", HFILL }
},
{ &hf_vnc_update_req_height,
{ "Height", "vnc.update_req_height",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Height of framebuffer (screen) update request", HFILL }
},
{ &hf_vnc_client_cut_text_len,
{ "Length", "vnc.client_cut_text_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Length of client's copy/cut text (clipboard) string in bytes", HFILL }
},
{ &hf_vnc_client_cut_text,
{ "Text", "vnc.client_cut_text",
FT_STRING, BASE_NONE, NULL, 0x0,
"Text string in the client's copy/cut text (clipboard)", HFILL }
},
{ &hf_vnc_server_message_type,
{ "Server Message Type", "vnc.server_message_type",
FT_UINT8, BASE_DEC, VALS(vnc_server_message_types_vs), 0x0,
"Message type from server", HFILL }
},
{ &hf_vnc_fb_update_x_pos,
{ "X position", "vnc.fb_update_x_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"X position of this server framebuffer update", HFILL }
},
{ &hf_vnc_fb_update_y_pos,
{ "Y position", "vnc.fb_update_y_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Y position of this server framebuffer update", HFILL }
},
{ &hf_vnc_fb_update_width,
{ "Width", "vnc.fb_update_width",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Width of this server framebuffer update", HFILL }
},
{ &hf_vnc_fb_update_height,
{ "Height", "vnc.fb_update_height",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Height of this server framebuffer update", HFILL }
},
{ &hf_vnc_fb_update_encoding_type,
{ "Encoding type", "vnc.fb_update_encoding_type",
FT_INT32, BASE_DEC, VALS(encoding_types_vs), 0x0,
"Encoding type of this server framebuffer update", HFILL }
},
{ &hf_vnc_cursor_x_fore_back,
{ "X Cursor foreground RGB / background RGB", "vnc.cursor_x_fore_back",
FT_BYTES, BASE_NONE, NULL, 0x0,
"RGB values for the X cursor's foreground and background", HFILL }
},
{ &hf_vnc_cursor_encoding_pixels,
{ "Cursor encoding pixels", "vnc.cursor_encoding_pixels",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Cursor encoding pixel data", HFILL }
},
{ &hf_vnc_cursor_encoding_bitmask,
{ "Cursor encoding bitmask", "vnc.cursor_encoding_bitmask",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Cursor encoding pixel bitmask", HFILL }
},
{ &hf_vnc_raw_pixel_data,
{ "Pixel data", "vnc.raw_pixel_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Raw pixel data.", HFILL }
},
{ &hf_vnc_copyrect_src_x_pos,
{ "Source x position", "vnc.copyrect_src_x_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"X position of the rectangle to copy from", HFILL }
},
{ &hf_vnc_copyrect_src_y_pos,
{ "Source y position", "vnc.copyrect_src_y_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Y position of the rectangle to copy from", HFILL }
},
{ &hf_vnc_rre_num_subrects,
{ "Number of subrectangles", "vnc.rre_num_subrects",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of subrectangles contained in this encoding type", HFILL }
},
{ &hf_vnc_rre_bg_pixel,
{ "Background pixel value", "vnc.rre_bg_pixel",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vnc_rre_subrect_pixel,
{ "Pixel value", "vnc.rre_subrect_pixel",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Subrectangle pixel value", HFILL }
},
{ &hf_vnc_rre_subrect_x_pos,
{ "X position", "vnc.rre_subrect_x_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Position of this subrectangle on the x axis", HFILL }
},
{ &hf_vnc_rre_subrect_y_pos,
{ "Y position", "vnc.rre_subrect_y_pos",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Position of this subrectangle on the y axis", HFILL }
},
{ &hf_vnc_rre_subrect_width,
{ "Width", "vnc.rre_subrect_width",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Width of this subrectangle", HFILL }
},
{ &hf_vnc_rre_subrect_height,
{ "Height", "vnc.rre_subrect_height",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Height of this subrectangle", HFILL }
},
{ &hf_vnc_hextile_subencoding_mask,
{ "Subencoding type", "vnc.hextile_subencoding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Hextile subencoding type.", HFILL }
},
{ &hf_vnc_hextile_raw,
{ "Raw", "vnc.hextile_raw",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x1,
"Raw subencoding is used in this tile", HFILL }
},
{ &hf_vnc_hextile_raw_value,
{ "Raw pixel values", "vnc.hextile_raw_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Raw subencoding pixel values", HFILL }
},
{ &hf_vnc_hextile_bg,
{ "Background Specified", "vnc.hextile_bg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x2,
"Background Specified subencoding is used in this tile", HFILL }
},
{ &hf_vnc_hextile_bg_value,
{ "Background pixel value", "vnc.hextile_bg_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Background color for this tile", HFILL }
},
{ &hf_vnc_hextile_fg,
{ "Foreground Specified", "vnc.hextile_fg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x4,
"Foreground Specified subencoding is used in this tile", HFILL }
},
{ &hf_vnc_hextile_fg_value,
{ "Foreground pixel value", "vnc.hextile_fg_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Foreground color for this tile", HFILL }
},
{ &hf_vnc_hextile_anysubrects,
{ "Any Subrects", "vnc.hextile_anysubrects",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x8,
"Any subrects subencoding is used in this tile", HFILL }
},
{ &hf_vnc_hextile_num_subrects,
{ "Number of subrectangles", "vnc.hextile_num_subrects",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of subrectangles that follow", HFILL }
},
{ &hf_vnc_hextile_subrectscolored,
{ "Subrects Colored", "vnc.hextile_subrectscolored",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
"Subrects colored subencoding is used in this tile", HFILL }
},
{ &hf_vnc_hextile_subrect_pixel_value,
{ "Pixel value", "vnc.hextile_subrect_pixel_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Pixel value of this subrectangle", HFILL }
},
{ &hf_vnc_hextile_subrect_x_pos,
{ "X position", "vnc.hextile_subrect_x_pos",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"X position of this subrectangle", HFILL }
},
{ &hf_vnc_hextile_subrect_y_pos,
{ "Y position", "vnc.hextile_subrect_y_pos",
FT_UINT8, BASE_DEC, NULL, 0xF,
"Y position of this subrectangle", HFILL }
},
{ &hf_vnc_hextile_subrect_width,
{ "Width", "vnc.hextile_subrect_width",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Subrectangle width minus one", HFILL }
},
{ &hf_vnc_hextile_subrect_height,
{ "Height", "vnc.hextile_subrect_height",
FT_UINT8, BASE_DEC, NULL, 0xF,
"Subrectangle height minus one", HFILL }
},
{ &hf_vnc_zrle_len,
{ "ZRLE compressed length", "vnc.zrle_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Length of compressed ZRLE data that follows", HFILL }
},
{ &hf_vnc_zrle_subencoding,
{ "Subencoding type", "vnc.zrle_subencoding",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Subencoding type byte", HFILL }
},
{ &hf_vnc_zrle_rle,
{ "RLE", "vnc.zrle_rle",
FT_UINT8, BASE_DEC, VALS(yes_no_vs), 0x80,
"Specifies that data is run-length encoded", HFILL }
},
{ &hf_vnc_zrle_palette_size,
{ "Palette size", "vnc.zrle_palette_size",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_vnc_zrle_data,
{ "ZRLE compressed data", "vnc.zrle_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Compressed ZRLE data. Compiling with zlib support will uncompress and dissect this data", HFILL }
},
{ &hf_vnc_zrle_raw,
{ "Pixel values", "vnc.zrle_raw",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Raw pixel values for this tile", HFILL }
},
{ &hf_vnc_zrle_palette,
{ "Palette", "vnc.zrle_palette",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Palette pixel values", HFILL }
},
{ &hf_vnc_colormap_first_color,
{ "First color", "vnc.colormap_first_color",
FT_UINT16, BASE_DEC, NULL, 0x0,
"First color that should be mapped to given RGB intensities", HFILL }
},
{ &hf_vnc_color_groups,
{ "Color groups", "vnc.color_groups",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vnc_colormap_num_colors,
{ "Number of color groups", "vnc.colormap_groups",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of red/green/blue color groups", HFILL }
},
{ &hf_vnc_colormap_red,
{ "Red", "vnc.colormap_red",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Red intensity", HFILL }
},
{ &hf_vnc_colormap_green,
{ "Green", "vnc.colormap_green",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Green intensity", HFILL }
},
{ &hf_vnc_colormap_blue,
{ "Blue", "vnc.colormap_blue",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Blue intensity", HFILL }
},
{ &hf_vnc_server_cut_text_len,
{ "Length", "vnc.server_cut_text_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Length of server's copy/cut text (clipboard) string in bytes", HFILL }
},
{ &hf_vnc_server_cut_text,
{ "Text", "vnc.server_cut_text",
FT_STRING, BASE_NONE, NULL, 0x0,
"Text string in the server's copy/cut text (clipboard)", HFILL }
},
};
static gint *ett[] = {
&ett_vnc,
&ett_vnc_client_message_type,
&ett_vnc_server_message_type,
&ett_vnc_rect,
&ett_vnc_encoding_type,
&ett_vnc_rre_subrect,
&ett_vnc_hextile_subencoding_mask,
&ett_vnc_hextile_num_subrects,
&ett_vnc_hextile_subrect,
&ett_vnc_hextile_tile,
&ett_vnc_zrle_subencoding,
&ett_vnc_colormap_num_groups,
&ett_vnc_desktop_screen,
&ett_vnc_colormap_color_group
};
proto_vnc = proto_register_protocol("Virtual Network Computing",
"VNC", "vnc");
proto_register_field_array(proto_vnc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
vnc_module = prefs_register_protocol(proto_vnc, proto_reg_handoff_vnc);
prefs_register_bool_preference(vnc_module, "desegment",
"Reassemble VNC messages spanning multiple TCP segments.",
"Whether the VNC dissector should reassemble messages spanning "
"multiple TCP segments. To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&vnc_preference_desegment);
prefs_register_uint_preference(vnc_module, "alternate_port", "Alternate TCP port",
"Decode this port's traffic as VNC in addition to the default ports (5500, 5501, 5900, 5901)",
10, &vnc_preference_alternate_port);
}
void
proto_reg_handoff_vnc(void)
{
static gboolean inited = FALSE;
static guint vnc_preference_alternate_port_last = 0;
if(!inited) {
vnc_handle = create_dissector_handle(dissect_vnc, proto_vnc);
dissector_add_uint("tcp.port", 5500, vnc_handle);
dissector_add_uint("tcp.port", 5501, vnc_handle);
dissector_add_uint("tcp.port", 5900, vnc_handle);
dissector_add_uint("tcp.port", 5901, vnc_handle);
heur_dissector_add("tcp", test_vnc_protocol, proto_vnc);
inited = TRUE;
} else {
if(vnc_preference_alternate_port != vnc_preference_alternate_port_last &&
vnc_preference_alternate_port != 5500 &&
vnc_preference_alternate_port != 5501 &&
vnc_preference_alternate_port != 5900 &&
vnc_preference_alternate_port != 5901) {
if (vnc_preference_alternate_port_last != 0) {
dissector_delete_uint("tcp.port",
vnc_preference_alternate_port_last,
vnc_handle);
}
vnc_preference_alternate_port_last =
vnc_preference_alternate_port;
if (vnc_preference_alternate_port != 0) {
dissector_add_uint("tcp.port",
vnc_preference_alternate_port,
vnc_handle);
}
}
}
}
