static gboolean
dissect_lwm_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if(tvb_get_guint8(tvb, 0) & LWM_FCF_RESERVED)
return (FALSE);
if (tvb_reported_length(tvb) < LWM_HEADER_BASE_LEN)
return (FALSE);
dissect_lwm(tvb, pinfo, tree, data);
return (TRUE);
}
static int dissect_lwm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint lwm_header_len;
guint8 lwm_fcf;
gboolean lwm_fcf_security;
gboolean lwm_fcf_multicast;
guint8 lwm_seq;
guint16 lwm_src_addr;
guint16 lwm_dst_addr;
guint8 lwm_endp_field;
guint8 lwm_src_endp;
guint8 lwm_dst_endp;
proto_tree *lwm_tree = NULL;
proto_item *ti_proto = NULL;
proto_item *ti;
tvbuff_t *new_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LwMesh");
col_clear(pinfo->cinfo, COL_INFO);
lwm_header_len = LWM_HEADER_BASE_LEN;
if(tree){
ti_proto = proto_tree_add_protocol_format(tree, proto_lwm, tvb, 0, -1, "Lightweight Mesh");
lwm_tree = proto_item_add_subtree(ti_proto, ett_lwm);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Lightweight Mesh");
lwm_fcf = tvb_get_guint8(tvb, 0);
lwm_fcf_security = (lwm_fcf & LWM_FCF_SEC_EN);
lwm_fcf_multicast = (lwm_fcf & LWM_FCF_MULTICAST);
if(tree){
proto_tree *field_tree;
ti = proto_tree_add_uint(lwm_tree, hf_lwm_fcf, tvb, 0, 1, lwm_fcf);
field_tree = proto_item_add_subtree(ti, ett_lwm_fcf);
proto_tree_add_item(field_tree, hf_lwm_fcf_ack_req, tvb, 0, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_lwm_fcf_security, tvb, 0, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_lwm_fcf_linklocal, tvb, 0, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_lwm_fcf_multicast, tvb, 0, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_lwm_fcf_reserved, tvb, 0, 1, ENC_NA);
}
lwm_seq = tvb_get_guint8(tvb, 1);
proto_item_append_text(ti_proto, ", Sequence Number: %i", lwm_seq);
proto_tree_add_uint(lwm_tree, hf_lwm_seq, tvb, 1, 1, lwm_seq);
lwm_src_addr = tvb_get_letohs(tvb, 2);
ti = proto_tree_add_uint(lwm_tree, hf_lwm_src_addr, tvb, 2, 2, lwm_src_addr);
if(lwm_src_addr < 0x8000){
proto_item_append_text(ti, " (Routing node)");
}else{
proto_item_append_text(ti, " (Non-routing node)");
}
if(lwm_src_addr == LWM_BCAST_ADDR){
expert_add_info(pinfo, lwm_tree, &ei_lwm_n_src_broad);
}
lwm_dst_addr = tvb_get_letohs(tvb, 4);
if(lwm_dst_addr == LWM_BCAST_ADDR){
proto_tree_add_uint_format_value(lwm_tree, hf_lwm_dst_addr, tvb, 4, 2, lwm_dst_addr,
"Broadcast (0x%04x)", lwm_dst_addr);
}else{
ti = proto_tree_add_uint(lwm_tree, hf_lwm_dst_addr, tvb, 4, 2, lwm_dst_addr);
if(lwm_fcf_multicast){
proto_item_append_text(ti, " %s", LWM_MULTI_GROUP_STRING);
}else{
proto_item_append_text(ti, " %s", LWM_MULTI_UNICAST_STRING);
if(lwm_dst_addr < 0x8000){
proto_item_append_text(ti, " (Routing node)");
}else{
proto_item_append_text(ti, " (Non-routing node)");
}
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Nwk_Dst: 0x%04x, Nwk_Src: 0x%04x", lwm_dst_addr, lwm_src_addr);
lwm_endp_field = tvb_get_guint8(tvb, 6);
lwm_src_endp = (lwm_endp_field & LWM_SRC_ENDP_MASK) >> LWM_SRC_ENDP_OFFSET;
lwm_dst_endp = (lwm_endp_field & LWM_DST_ENDP_MASK) >> LWM_DST_ENDP_OFFSET;
ti = proto_tree_add_uint(lwm_tree, hf_lwm_src_endp, tvb, 6, 1, lwm_src_endp);
if(lwm_src_endp == 0){
proto_item_append_text(ti, " (Stack command endpoint)");
}
ti = proto_tree_add_uint(lwm_tree, hf_lwm_dst_endp, tvb, 6, 1, lwm_dst_endp);
if(lwm_dst_endp == 0){
proto_item_append_text(ti, " (Stack command endpoint)");
}
if( (lwm_src_endp == 0) && (lwm_dst_endp == 0)){
}
else if( (lwm_src_endp == 0) || (lwm_dst_endp == 0)){
col_append_str(pinfo->cinfo, COL_INFO, "[Stack command Endpoints mismatch]");
expert_add_info(pinfo, lwm_tree, &ei_lwm_mismatch_endp);
}
if( (lwm_fcf_multicast) ){
lwm_header_len += LWM_MULTI_HEADER_LEN;
if(tree){
proto_tree *multi_tree;
guint16 lwm_multi_header;
lwm_multi_header = tvb_get_letohs(tvb, 7);
multi_tree = proto_tree_add_subtree(lwm_tree, tvb, 7, 2, ett_lwm_multi_tree, NULL, "Multicast Header");
proto_tree_add_uint(multi_tree, hf_lwm_multi_nmrad, tvb, 7, 2,
(lwm_multi_header & LWM_MULTI_NON_MEM_RAD_MASK) >> LWM_MULTI_NON_MEM_RAD_OFFSET);
proto_tree_add_uint(multi_tree, hf_lwm_multi_mnmrad, tvb, 7, 2,
(lwm_multi_header & LWM_MULTI_MAX_NON_MEM_RAD_MASK) >> LWM_MULTI_MAX_NON_MEM_RAD_OFFSET);
proto_tree_add_uint(multi_tree, hf_lwm_multi_mrad, tvb, 7, 2,
(lwm_multi_header & LWM_MULTI_MEM_RAD_MASK) >> LWM_MULTI_MEM_RAD_OFFSET);
proto_tree_add_uint(multi_tree, hf_lwm_multi_mmrad, tvb, 7, 2,
(lwm_multi_header & LWM_MULTI_MAX_MEM_RAD_MASK) >> LWM_MULTI_MAX_MEM_RAD_OFFSET);
}
}
if (tvb_reported_length(tvb) <= lwm_header_len) {
expert_add_info(pinfo, lwm_tree, &ei_lwm_empty_payload);
col_append_str(pinfo->cinfo, COL_INFO, "[Empty LwMesh Payload]");
return tvb_captured_length(tvb);
}
new_tvb = tvb_new_subset_remaining(tvb, lwm_header_len);
if(lwm_fcf_security){
guint rlen;
gint start;
guint32 lwm_mic;
rlen = tvb_reported_length(new_tvb);
start = (rlen >= LWM_MIC_LEN) ? (rlen-LWM_MIC_LEN) : 0;
proto_tree_add_item_ret_uint(lwm_tree, hf_lwm_mic, new_tvb, start, LWM_MIC_LEN, ENC_LITTLE_ENDIAN, &lwm_mic);
if(lwmes_key_valid)
{
ieee802154_packet *ieee_packet = NULL;
gint payload_length = 0;
gint length = 0;
gint payload_offset = 0;
guint8 block;
tvbuff_t *decrypted_tvb;
gcry_cipher_hd_t cypher_hd;
guint8* vector = NULL;
guint8* text =NULL;
guint8* text_dec =NULL;
guint8 i;
guint32 vmic;
guint32 nwkSecurityVector[4];
ieee_packet = (ieee802154_packet *)data;
memset(&nwkSecurityVector, 0, sizeof(nwkSecurityVector));
nwkSecurityVector[0] = lwm_seq;
nwkSecurityVector[1] = ((guint32)lwm_dst_addr<< 16) | lwm_dst_endp;
nwkSecurityVector[2]= ((guint32) lwm_src_addr<< 16) | lwm_src_endp;
nwkSecurityVector[3] = ((guint32)ieee_packet->dst_pan << 16) | (guint8)lwm_fcf;
payload_length=tvb_reported_length(new_tvb) - LWM_MIC_LEN;
text = (guint8 *)tvb_memdup(pinfo->pool, new_tvb, 0, payload_length);
payload_offset=0;
while(payload_length>0)
{
int gcrypt_err;
gcrypt_err = gcry_cipher_open(&cypher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_ECB, 0);
if(gcrypt_err == 0) {
gcrypt_err = gcry_cipher_setkey(cypher_hd,(guint8 *)lwmes_key, 16);
}
if(gcrypt_err == 0) {
gcrypt_err = gcry_cipher_encrypt(cypher_hd,(guint8 *)nwkSecurityVector,16,(guint8 *)nwkSecurityVector,16);
}
if(gcrypt_err)
{
col_add_fstr(pinfo->cinfo, COL_INFO,
"Encrypted data (%i byte(s)) DECRYPT FAILED",
tvb_reported_length(new_tvb) - LWM_MIC_LEN);
expert_add_info(pinfo, lwm_tree, &ei_lwm_decryption_failed);
tvb_set_reported_length(new_tvb, tvb_reported_length(new_tvb) - LWM_MIC_LEN);
call_data_dissector(new_tvb, pinfo, lwm_tree);
}
text_dec = &text[payload_offset];
vector = (guint8 *)nwkSecurityVector;
block = (payload_length < 16) ? payload_length : 16;
for (i = 0; i < block; i++)
{
text_dec[i] ^= vector[i];
vector[i] ^= text_dec[i];
}
payload_offset += block;
payload_length -= block;
gcry_cipher_close(cypher_hd);
}
vmic = nwkSecurityVector[0] ^ nwkSecurityVector[1] ^ nwkSecurityVector[2] ^ nwkSecurityVector[3];
length = tvb_reported_length(new_tvb) - LWM_MIC_LEN;
if(vmic == lwm_mic)
{
decrypted_tvb = tvb_new_real_data(text,length, length);
call_data_dissector(decrypted_tvb, pinfo, lwm_tree);
col_append_fstr(pinfo->cinfo, COL_INFO, ", MIC SUCCESS");
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO,
"Encrypted data (%i byte(s)) MIC FAILURE",
tvb_reported_length(new_tvb) - LWM_MIC_LEN);
tvb_set_reported_length(new_tvb, tvb_reported_length(new_tvb) - LWM_MIC_LEN);
call_data_dissector(new_tvb, pinfo, lwm_tree);
}
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO,
"Encrypted data (%i byte(s)) NO DECRYPT KEY",
tvb_reported_length(new_tvb) - LWM_MIC_LEN);
expert_add_info(pinfo, lwm_tree, &ei_lwm_no_decryption_key);
tvb_set_reported_length(new_tvb, tvb_reported_length(new_tvb) - LWM_MIC_LEN);
call_data_dissector(new_tvb, pinfo, lwm_tree);
}
}
else if( (lwm_src_endp == 0) && (lwm_dst_endp == 0) ){
proto_tree *lwm_cmd_tree;
guint8 lwm_cmd;
guint len;
lwm_cmd = tvb_get_guint8(new_tvb, 0);
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(lwm_cmd, lwm_cmd_names, LWM_CMD_UNKNOWN_VAL_STRING));
lwm_cmd_tree = proto_tree_add_subtree(lwm_tree, new_tvb, 0, -1, ett_lwm_cmd_tree, &ti,
val_to_str(lwm_cmd, lwm_cmd_names, LWM_CMD_UNKNOWN_VAL_STRING));
proto_tree_add_uint(lwm_cmd_tree, hf_lwm_cmd, new_tvb, 0, 1, lwm_cmd);
switch (lwm_cmd) {
case LWM_CMD_ACK:
len = dissect_lwm_cmd_frame_ack(new_tvb, pinfo, lwm_cmd_tree);
break;
case LWM_CMD_ROUTE_ERR:
len = dissect_lwm_cmd_frame_route_err(new_tvb, pinfo, lwm_cmd_tree);
break;
case LWM_CMD_ROUTE_REQ:
len = dissect_lwm_cmd_frame_route_req(new_tvb, pinfo, lwm_cmd_tree);
break;
case LWM_CMD_ROUTE_REPLY:
len = dissect_lwm_cmd_frame_route_reply(new_tvb, pinfo, lwm_cmd_tree);
break;
default:
expert_add_info_format(pinfo, lwm_cmd_tree, &ei_lwm_mal_error, "Unknown command");
call_data_dissector(new_tvb, pinfo, lwm_cmd_tree);
return tvb_captured_length(tvb);
}
proto_item_set_len(ti, len);
if (len < tvb_reported_length(new_tvb)) {
expert_add_info_format(pinfo, lwm_cmd_tree, &ei_lwm_mal_error,
"Size is %i byte(s), instead of %i bytes", tvb_reported_length(new_tvb), len);
new_tvb = tvb_new_subset_remaining(new_tvb, len);
call_data_dissector(new_tvb, pinfo, lwm_tree);
}
}
else{
call_data_dissector(new_tvb, pinfo, lwm_tree);
}
return tvb_captured_length(tvb);
}
static int dissect_lwm_cmd_frame_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lwm_cmd_tree)
{
guint8 lwm_seq;
lwm_seq = tvb_get_guint8(tvb, 1);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Sequence number: %d", lwm_seq);
if(lwm_cmd_tree){
proto_item_append_text(proto_tree_get_parent(lwm_cmd_tree), ", Sequence number: %d", lwm_seq);
proto_tree_add_uint(lwm_cmd_tree, hf_lwm_cmd_seq, tvb, 1, 1, lwm_seq);
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_cm, tvb, 2, 1, ENC_NA);
}
return LWM_CMD_FRAME_ACK_LEN;
}
static int dissect_lwm_cmd_frame_route_err(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *lwm_cmd_tree)
{
if(lwm_cmd_tree){
proto_item *ti;
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_src, tvb, 1, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_dst, tvb, 3, 2, ENC_LITTLE_ENDIAN);
if(tvb_get_guint8(tvb, 5) == LWM_CMD_MULTI_ADDR_TRUE){
proto_item_append_text(ti, " %s", LWM_MULTI_GROUP_STRING);
}else{
proto_item_append_text(ti, " %s", LWM_MULTI_UNICAST_STRING);
}
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_multi, tvb, 5, 1, ENC_NA);
}
return LWM_CMD_FRAME_ROUTE_ERR_LEN;
}
static int dissect_lwm_cmd_frame_route_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *lwm_cmd_tree)
{
if(lwm_cmd_tree){
proto_item *ti;
guint8 lwm_linkqual;
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_src, tvb, 1, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_dst, tvb, 3, 2, ENC_LITTLE_ENDIAN);
if(tvb_get_guint8(tvb, 5) == LWM_CMD_MULTI_ADDR_TRUE){
proto_item_append_text(ti, " %s", LWM_MULTI_GROUP_STRING);
}else{
proto_item_append_text(ti, " %s", LWM_MULTI_UNICAST_STRING);
}
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_multi, tvb, 5, 1, ENC_NA);
lwm_linkqual = tvb_get_guint8(tvb, 6);
ti = proto_tree_add_uint(lwm_cmd_tree, hf_lwm_cmd_linkquality, tvb, 6, 1, lwm_linkqual);
if(lwm_linkqual == 255){
proto_item_append_text(ti, " %s", LWM_CMD_LINKQ_STRING);
}
}
return LWM_CMD_FRAME_ROUTE_REQ_LEN;
}
static int dissect_lwm_cmd_frame_route_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *lwm_cmd_tree)
{
if(lwm_cmd_tree){
proto_item *ti;
guint8 lwm_revlinkqual;
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_src, tvb, 1, 2, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_dst, tvb, 3, 2, ENC_LITTLE_ENDIAN);
if(tvb_get_guint8(tvb, 5) == LWM_CMD_MULTI_ADDR_TRUE){
proto_item_append_text(ti, " %s", LWM_MULTI_GROUP_STRING);
}else{
proto_item_append_text(ti, " %s", LWM_MULTI_UNICAST_STRING);
}
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_route_multi, tvb, 5, 1, ENC_NA);
proto_tree_add_item(lwm_cmd_tree, hf_lwm_cmd_forwlinkquality, tvb, 6, 1, ENC_NA);
lwm_revlinkqual = tvb_get_guint8(tvb, 7);
ti = proto_tree_add_uint(lwm_cmd_tree, hf_lwm_cmd_revlinkquality, tvb, 7, 1, lwm_revlinkqual);
if(lwm_revlinkqual == 255){
proto_item_append_text(ti, " %s", LWM_CMD_LINKQ_STRING);
}
}
return LWM_CMD_FRAME_ROUTE_REPLY_LEN;
}
void proto_register_lwm(void)
{
static hf_register_info hf[] = {
{ &hf_lwm_fcf,
{ "Frame control field", "lwm.fcf", FT_UINT8, BASE_HEX, NULL, 0x0,
"Control information for the frame.", HFILL }},
{ &hf_lwm_fcf_ack_req,
{ "Acknowledgment Request", "lwm.ack_req", FT_BOOLEAN, 8, NULL, LWM_FCF_ACK_REQUEST,
"Specifies whether an acknowledgment is required from the destination node.", HFILL }},
{ &hf_lwm_fcf_security,
{ "Security Enabled", "lwm.security", FT_BOOLEAN, 8, NULL, LWM_FCF_SEC_EN,
"Specifies whether the frame payload is encrypted.", HFILL }},
{ &hf_lwm_fcf_linklocal,
{ "Link Local", "lwm.linklocal", FT_BOOLEAN, 8, NULL, LWM_FCF_LINK_LOCAL,
"It may be set to one to prevent neighboring nodes from rebroadcasting a frame.", HFILL }},
{ &hf_lwm_fcf_multicast,
{ "Multicast", "lwm.multicast", FT_BOOLEAN, 8, NULL, LWM_FCF_MULTICAST,
"If the Multicast subfield is set to one, Multicast Header should be present and the Destination Address is a group address.", HFILL }},
{ &hf_lwm_fcf_reserved,
{ "Reserved bits", "lwm.fcf.reserved", FT_UINT8, BASE_HEX, NULL, LWM_FCF_RESERVED,
"The 4 bits are reserved.", HFILL }},
{ &hf_lwm_seq,
{ "Sequence Number", "lwm.seq", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the sequence identifier for the frame.", HFILL }},
{ &hf_lwm_src_addr,
{ "Network Source Address", "lwm.src_addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"Specifies the network address of the node originating the frame.", HFILL }},
{ &hf_lwm_dst_addr,
{ "Network Destination Address", "lwm.dst_addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"Specifies the network address of the destination node or group address for multicast messages.", HFILL }},
{ &hf_lwm_src_endp,
{ "Source Endpoint", "lwm.src_endp", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the source endpoint identifier.", HFILL }},
{ &hf_lwm_dst_endp,
{ "Destination Endpoint", "lwm.dst_endp", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the destination endpoint identifier.", HFILL }},
{ &hf_lwm_multi_nmrad,
{ "Non-member Radius", "lwm.multi_nmrad", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies remaining radius (number of hops) for Non-members of multicast group.", HFILL }},
{ &hf_lwm_multi_mnmrad,
{ "Maximum Non-member Radius", "lwm.multi_mnmrad", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies maximum radius (number of hops) for Non-members of multicast group.", HFILL }},
{ &hf_lwm_multi_mrad,
{ "Member Radius", "lwm.multi_mrad", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies remaining radius (number of hops) for Members of multicast group.", HFILL }},
{ &hf_lwm_multi_mmrad,
{ "Maximum Member Radius", "lwm.multi_mmrad", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies maximum radius (number of hops) for Members of multicast group.", HFILL }},
{ &hf_lwm_mic,
{ "Message Integrity Code", "lwm.mic", FT_UINT32, BASE_HEX, NULL, 0x0,
"Specifies Message Integrity Code (MIC).", HFILL }},
{ &hf_lwm_cmd,
{ "Command ID", "lwm.cmd", FT_UINT8, BASE_HEX, VALS(lwm_cmd_names), 0x0,
"It contains Command ID value.", HFILL }},
{ &hf_lwm_cmd_seq,
{ "Sequence number", "lwm.cmd.seq", FT_UINT8, BASE_DEC, NULL, 0x0,
"It contains a network sequence number of a frame that is being acknowledged.", HFILL }},
{ &hf_lwm_cmd_cm,
{ "Control Message", "lwm.cmd.cm", FT_UINT8, BASE_HEX, NULL, 0x0,
"It contains an arbitrary value that can be set on the sending side.", HFILL }},
{ &hf_lwm_cmd_route_src,
{ "Source address", "lwm.cmd.route_src", FT_UINT16, BASE_HEX, NULL, 0x0,
"It contains a source network address from the frame that cannot be routed", HFILL }},
{ &hf_lwm_cmd_route_dst,
{ "Destination Address", "lwm.cmd.route_dst", FT_UINT16, BASE_HEX, NULL, 0x0,
"It contains a destination network address from the frame that cannot be routed", HFILL }},
{ &hf_lwm_cmd_route_multi,
{ "Multicast", "lwm.cmd.multi", FT_UINT8, BASE_HEX, VALS(lwm_cmd_multi_names), 0x0,
"If it set to 0, Destination Address field contains a network address. If it set to 1, Destination Address field contains a group ID.", HFILL }},
{ &hf_lwm_cmd_linkquality,
{ "Link Quality", "lwm.cmd.linkq", FT_UINT8, BASE_DEC, NULL, 0x0,
"It contains a link quality value of the potential route accumulated over all hops towards the destination.", HFILL }},
{ &hf_lwm_cmd_forwlinkquality,
{ "Forward Link Quality", "lwm.cmd.flinkq", FT_UINT8, BASE_DEC, NULL, 0x0,
"It contains a value of the Link Quality field from the corresponding Route Request Command Frame.", HFILL }},
{ &hf_lwm_cmd_revlinkquality,
{ "Reverse Link Quality", "lwm.cmd.rlinkq", FT_UINT8, BASE_DEC, NULL, 0x0,
"It contains a link quality value of the discovered route accumulated over all hops towards the originator.", HFILL }},
};
static gint *ett[] = {
&ett_lwm,
&ett_lwm_fcf,
&ett_lwm_multi_tree,
&ett_lwm_cmd_tree
};
static ei_register_info ei[] = {
{ &ei_lwm_mal_error, { "lwm.malformed_error", PI_MALFORMED, PI_ERROR, "Malformed Packet", EXPFILL }},
{ &ei_lwm_n_src_broad, { "lwm.not_src_broadcast", PI_COMMENTS_GROUP, PI_NOTE, "Source address can not be broadcast address !", EXPFILL }},
{ &ei_lwm_mismatch_endp, { "lwm.mismatch_endp", PI_COMMENTS_GROUP, PI_WARN, "Stack command Endpoints mismatch (should be 0, both)!", EXPFILL }},
{ &ei_lwm_empty_payload, { "lwm.empty_payload", PI_COMMENTS_GROUP, PI_WARN, "Empty LwMesh Payload!", EXPFILL }},
{ &ei_lwm_no_decryption_key, { "lwm.no_decryption_key", PI_PROTOCOL, PI_NOTE, "No encryption key set - can't decrypt", EXPFILL }},
{ &ei_lwm_decryption_failed, { "lwm.decryption_failed", PI_PROTOCOL, PI_WARN, "Decryption Failed", EXPFILL }},
};
module_t *lw_module;
expert_module_t* expert_lwm;
proto_lwm = proto_register_protocol("Lightweight Mesh (v1.1.1)", "LwMesh", "lwm");
proto_register_field_array(proto_lwm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_lwm = expert_register_protocol(proto_lwm);
expert_register_field_array(expert_lwm, ei, array_length(ei));
lw_module = prefs_register_protocol(proto_lwm,proto_reg_handoff_lwm);
prefs_register_string_preference(lw_module, "lwmes_key", "Lw Decryption key",
"128-bit decryption key in hexadecimal format", (const char **)&lwmes_key_str);
lwm_handle = register_dissector("lwm", dissect_lwm, proto_lwm);
}
void proto_reg_handoff_lwm(void)
{
GByteArray *bytes;
gboolean res;
bytes = g_byte_array_new();
res = hex_str_to_bytes(lwmes_key_str, bytes, FALSE);
lwmes_key_valid = (res && bytes->len >= IEEE802154_CIPHER_SIZE);
if (lwmes_key_valid) {
memcpy(lwmes_key, bytes->data, IEEE802154_CIPHER_SIZE);
}
g_byte_array_free(bytes, TRUE);
dissector_add_for_decode_as(IEEE802154_PROTOABBREV_WPAN_PANID, lwm_handle);
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN, dissect_lwm_heur, "Lightweight Mesh over IEEE 802.15.4", "lwm_wlan", proto_lwm, HEURISTIC_ENABLE);
}
