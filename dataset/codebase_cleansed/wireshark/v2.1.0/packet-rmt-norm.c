static double UnquantizeRtt(unsigned char qrtt)
{
return ((qrtt <= 31) ? (((double)(qrtt+1))*(double)RTT_MIN) :
(RTT_MAX/exp(((double)(255-qrtt))/(double)13.0)));
}
static double UnquantizeGSize(guint8 gsizex)
{
guint mant = (gsizex & 0x8) ? 5 : 1;
guint exponent = gsizex & 0x7;
exponent += 1;
return mant * pow(10, exponent);
}
static guint dissect_grrtetc(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
guint8 backoff;
double gsizex;
double grtt;
proto_tree_add_item(tree, hf_instance_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
grtt = UnquantizeRtt(tvb_get_guint8(tvb, offset));
proto_tree_add_double(tree, hf_grtt, tvb, offset, 1, grtt); offset += 1;
backoff = hi_nibble(tvb_get_guint8(tvb, offset));
gsizex = UnquantizeGSize((guint8)lo_nibble(tvb_get_guint8(tvb, offset)));
proto_tree_add_uint(tree, hf_backoff, tvb, offset, 1, backoff);
proto_tree_add_double(tree, hf_gsize, tvb, offset, 1, gsizex);
offset += 1;
return offset;
}
static guint dissect_feccode(proto_tree *tree, tvbuff_t *tvb, guint offset,
packet_info *pinfo, gint reserved)
{
norm_packet_data_t *norm_data;
guint8 encoding_id = tvb_get_guint8(tvb, offset);
norm_data = wmem_new0(wmem_file_scope(), norm_packet_data_t);
norm_data->encoding_id = encoding_id;
p_add_proto_data(wmem_file_scope(), pinfo, proto_rmt_norm, 0, norm_data);
proto_tree_add_item(tree, hf_fec_encoding_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
if (reserved) {
proto_tree_add_item(tree, hf_reserved, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
}
proto_tree_add_item(tree, hf_object_transport_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
fec_data_exchange_t fec;
tvbuff_t *new_tvb;
int len;
new_tvb = tvb_new_subset_remaining(tvb, offset);
fec.encoding_id = encoding_id;
len = call_dissector_with_data(rmt_fec_handle, new_tvb, pinfo, tree, &fec);
if (len > 0)
offset += len;
}
return offset;
}
static guint dissect_norm_hdrext(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
lct_data_exchange_t data_exchange;
norm_packet_data_t *packet_data = (norm_packet_data_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_rmt_norm, 0);
memset(&data_exchange, 0, sizeof(data_exchange));
if (packet_data != NULL)
data_exchange.codepoint = packet_data->encoding_id;
offset += lct_ext_decode(tree, tvb, pinfo, offset, hdrlen2bytes(hlen), &data_exchange,
hf_extension, ett_hdrext);
return offset;
}
static guint dissect_nack_data(proto_tree *tree, tvbuff_t *tvb, guint offset,
packet_info *pinfo)
{
proto_item *ti, *tif;
proto_tree *nack_tree, *flag_tree;
guint16 len;
nack_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_nackdata, &ti, "NACK Data");
proto_tree_add_item(nack_tree, hf_nack_form, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
tif = proto_tree_add_item(nack_tree, hf_nack_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(tif, ett_flags);
proto_tree_add_item(flag_tree, hf_nack_flags_segment, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_nack_flags_block, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_nack_flags_info, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_nack_flags_object, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(nack_tree, hf_nack_length, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_set_len(ti, 4+len);
if (len > 4) {
dissect_feccode(nack_tree, tvb, offset, pinfo, 1);
}
offset += len;
return offset;
}
static void dissect_norm_data(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
guint8 flags;
proto_item *ti;
proto_tree *flag_tree;
offset = dissect_grrtetc(tree, tvb, offset);
ti = proto_tree_add_item(tree, hf_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset);
flag_tree = proto_item_add_subtree(ti, ett_flags);
proto_tree_add_item(flag_tree, hf_flag_repair, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_norm_explicit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_info, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_unreliable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_file, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_stream, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_msgstart, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = dissect_feccode(tree, tvb, offset, pinfo, 0);
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
if (flags & NORM_FLAG_STREAM) {
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_streampayload, NULL, "Stream Data");
proto_tree_add_item(flag_tree, hf_reserved, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(flag_tree, hf_payload_len, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(flag_tree, hf_payload_offset, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_payload, tvb, offset, -1, ENC_NA);
}
static void dissect_norm_info(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, guint offset, guint8 hlen)
{
proto_item *ti;
proto_tree *flag_tree;
norm_packet_data_t *norm_data;
offset = dissect_grrtetc(tree, tvb, offset);
ti = proto_tree_add_item(tree, hf_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(ti, ett_flags);
proto_tree_add_item(flag_tree, hf_flag_repair, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_norm_explicit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_info, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_unreliable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_file, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_stream, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_flag_msgstart, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
norm_data = wmem_new0(wmem_file_scope(), norm_packet_data_t);
norm_data->encoding_id = tvb_get_guint8(tvb, offset);
p_add_proto_data(wmem_file_scope(), pinfo, proto_rmt_norm, 0, norm_data);
proto_tree_add_item(tree, hf_fec_encoding_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_object_transport_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_payload, tvb, offset, -1, ENC_NA);
}
static guint dissect_norm_cmd_flush(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
offset = dissect_feccode(tree, tvb, offset, pinfo, 0);
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
return offset;
}
static guint dissect_norm_cmd_repairadv(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
proto_tree_add_item(tree, hf_flags, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_reserved, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_nack_data(tree, tvb, offset, pinfo);
}
return offset;
}
static guint dissect_norm_cmd_cc(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
proto_tree_add_item(tree, hf_reserved, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_cc_sequence, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_cc_sts, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf_cc_stus, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
while (offset < hdrlen2bytes(hlen)) {
proto_item *tif;
proto_tree *cc_tree, *flag_tree;
double grtt;
cc_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_congestioncontrol, NULL, "Congestion Control");
proto_tree_add_item(cc_tree, hf_cc_node_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
tif = proto_tree_add_item(cc_tree, hf_cc_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(tif, ett_flags);
proto_tree_add_item(flag_tree, hf_cc_flags_clr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_cc_flags_plr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_cc_flags_rtt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_cc_flags_start, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_cc_flags_leave, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
grtt = UnquantizeRtt(tvb_get_guint8(tvb, offset));
proto_tree_add_double(cc_tree, hf_cc_rtt, tvb, offset, 1, grtt); offset += 1;
grtt = rmt_decode_send_rate(tvb_get_ntohs(tvb, offset));
proto_tree_add_double(cc_tree, hf_cc_rate, tvb, offset, 2, grtt); offset += 2;
}
return offset;
}
static guint dissect_norm_cmd_squelch(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset)
{
offset = dissect_feccode(tree, tvb, offset, pinfo, 0);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_cc_transport_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 2;
}
return offset;
}
static guint dissect_norm_cmd_ackreq(proto_tree *tree, packet_info *pinfo _U_,
tvbuff_t *tvb, guint offset)
{
proto_tree_add_item(tree, hf_reserved, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_ack_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_ack_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
return offset;
}
static void dissect_norm_cmd(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
guint8 flavor;
offset = dissect_grrtetc(tree, tvb, offset);
flavor = tvb_get_guint8(tvb, offset);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ",
val_to_str(flavor, string_norm_cmd_type, "Unknown Cmd Type (0x%04x)"));
proto_tree_add_item(tree, hf_cmd_flavor, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
switch(flavor) {
case NORM_CMD_CC:
offset = dissect_norm_cmd_cc(tree, pinfo, tvb, offset, hlen);
break;
case NORM_CMD_FLUSH:
offset = dissect_norm_cmd_flush(tree, pinfo, tvb, offset, hlen);
break;
case NORM_CMD_SQUELCH:
offset = dissect_norm_cmd_squelch(tree, pinfo, tvb, offset);
break;
case NORM_CMD_REPAIR_ADV:
offset = dissect_norm_cmd_repairadv(tree, pinfo, tvb, offset, hlen);
break;
case NORM_CMD_ACK_REQ:
offset = dissect_norm_cmd_ackreq(tree, pinfo, tvb, offset);
break;
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_payload, tvb, offset, -1, ENC_NA);
}
static void dissect_norm_ack(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
guint8 acktype;
proto_tree_add_item(tree, hf_ack_source, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf_instance_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
acktype = tvb_get_guint8(tvb, offset);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ",
val_to_str(acktype, string_norm_ack_type, "Unknown Ack Type (0x%04x)"));
proto_tree_add_item(tree, hf_ack_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_ack_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf_ack_grtt_sec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf_ack_grtt_usec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_payload, tvb, offset, -1, ENC_NA);
}
static void dissect_norm_nack(proto_tree *tree, packet_info *pinfo,
tvbuff_t *tvb, guint offset, guint8 hlen)
{
proto_tree_add_item(tree, hf_nack_server, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf_instance_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_reserved, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_nack_grtt_sec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf_nack_grtt_usec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
if (offset < hdrlen2bytes(hlen)) {
offset = dissect_norm_hdrext(tree, pinfo, tvb, offset, hlen);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_nack_data(tree, tvb, offset, pinfo);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_payload, tvb, offset, -1, ENC_NA);
}
static int
dissect_norm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 version;
guint8 type;
guint8 hlen;
guint offset = 0;
proto_item *ti;
proto_tree *norm_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NORM");
col_clear(pinfo->cinfo, COL_INFO);
version = hi_nibble(tvb_get_guint8(tvb, offset));
ti = proto_tree_add_item(tree, proto_rmt_norm, tvb, offset, -1, ENC_NA);
norm_tree = proto_item_add_subtree(ti, ett_main);
proto_tree_add_uint(norm_tree, hf_version, tvb, offset, 1, version);
if (version != 1) {
expert_add_info(pinfo, ti, &ei_version1_only);
col_add_fstr(pinfo->cinfo, COL_INFO, "Version: %u (not supported)", version);
return 0;
}
type = lo_nibble(tvb_get_guint8(tvb, offset));
hlen = tvb_get_guint8(tvb, offset+1);
if (tree) {
proto_tree_add_uint(norm_tree, hf_type, tvb, offset, 1, type);
proto_tree_add_item(norm_tree, hf_hlen, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(norm_tree, hf_sequence, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(norm_tree, hf_source_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
offset += 8;
col_append_sep_str(pinfo->cinfo, COL_INFO, " ",
val_to_str(type, string_norm_type, "Unknown Type (0x%04x)"));
switch(type) {
case NORM_INFO:
dissect_norm_info(norm_tree, pinfo, tvb, offset, hlen);
break;
case NORM_DATA:
dissect_norm_data(norm_tree, pinfo, tvb, offset, hlen);
break;
case NORM_CMD:
dissect_norm_cmd(norm_tree, pinfo, tvb, offset, hlen);
break;
case NORM_ACK:
dissect_norm_ack(norm_tree, pinfo, tvb, offset, hlen);
break;
case NORM_NACK:
dissect_norm_nack(norm_tree, pinfo, tvb, offset, hlen);
break;
default:
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(norm_tree, hf_payload, tvb, offset, -1, ENC_NA);
break;
}
return tvb_reported_length(tvb);
}
static gboolean
dissect_norm_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint8 byte1;
if (tvb_reported_length(tvb) < 12)
return FALSE;
byte1 = tvb_get_guint8(tvb, 0);
if (hi_nibble(byte1) != 1) return FALSE;
if (lo_nibble(byte1) < 1 || lo_nibble(byte1) > 6) return FALSE;
if (tvb_get_guint8(tvb, 1) > 20) return FALSE;
dissect_norm(tvb, pinfo, tree, data);
return TRUE;
}
void proto_register_norm(void)
{
static hf_register_info hf[] = {
{ &hf_version,
{ "Version", "norm.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_type,
{ "Message Type", "norm.type",
FT_UINT8, BASE_DEC, VALS(string_norm_type), 0x0,
NULL, HFILL }
},
{ &hf_hlen,
{ "Header length", "norm.hlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sequence,
{ "Sequence", "norm.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_source_id,
{ "Source ID", "norm.source_id",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_instance_id,
{ "Instance", "norm.instance_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_grtt,
{ "grtt", "norm.grtt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_backoff,
{ "Backoff", "norm.backoff",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsize,
{ "Group Size", "norm.gsize",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_flags,
{ "Flags", "norm.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_flag_repair,
{ "Repair Flag", "norm.flag.repair",
FT_BOOLEAN, 8, NULL, NORM_FLAG_REPAIR,
NULL, HFILL }
},
{ &hf_flag_norm_explicit,
{ "Explicit Flag", "norm.flag.explicit",
FT_BOOLEAN, 8, NULL, NORM_FLAG_EXPLICIT,
NULL, HFILL }
},
{ &hf_flag_info,
{ "Info Flag", "norm.flag.info",
FT_BOOLEAN, 8, NULL, NORM_FLAG_INFO,
NULL, HFILL }
},
{ &hf_flag_unreliable,
{ "Unreliable Flag", "norm.flag.unreliable",
FT_BOOLEAN, 8, NULL, NORM_FLAG_UNRELIABLE,
NULL, HFILL }
},
{ &hf_flag_file,
{ "File Flag", "norm.flag.file",
FT_BOOLEAN, 8, NULL, NORM_FLAG_FILE,
NULL, HFILL }
},
{ &hf_flag_stream,
{ "Stream Flag", "norm.flag.stream",
FT_BOOLEAN, 8, NULL, NORM_FLAG_STREAM,
NULL, HFILL }
},
{ &hf_flag_msgstart,
{ "Msg Start Flag", "norm.flag.msgstart",
FT_BOOLEAN, 8, NULL, NORM_FLAG_MSG_START,
NULL, HFILL }
},
{ &hf_object_transport_id,
{ "Object Transport ID", "norm.object_transport_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_extension,
{ "Hdr Extension", "norm.hexext",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_reserved,
{ "Reserved", "norm.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_payload_len,
{ "Payload Len", "norm.payload.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_payload_offset,
{ "Payload Offset", "norm.payload.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cmd_flavor,
{ "Flavor", "norm.flavor",
FT_UINT8, BASE_DEC, VALS(string_norm_cmd_type), 0x0,
NULL, HFILL}
},
{ &hf_cc_sequence,
{ "CC Sequence", "norm.ccsequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_sts,
{ "Send Time secs", "norm.cc_sts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_stus,
{ "Send Time usecs", "norm.cc_stus",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_node_id,
{ "CC Node ID", "norm.cc_node_id",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_flags,
{ "CC Flags", "norm.cc_flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_flags_clr,
{ "CLR", "norm.cc_flags.clr",
FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_CLR,
NULL, HFILL}
},
{ &hf_cc_flags_plr,
{ "PLR", "norm.cc_flags.plr",
FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_PLR,
NULL, HFILL}
},
{ &hf_cc_flags_rtt,
{ "RTT", "norm.cc_flags.rtt",
FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_RTT,
NULL, HFILL}
},
{ &hf_cc_flags_start,
{ "Start", "norm.cc_flags.start",
FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_START,
NULL, HFILL}
},
{ &hf_cc_flags_leave,
{ "Leave", "norm.cc_flags.leave",
FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_LEAVE,
NULL, HFILL}
},
{ &hf_cc_rtt,
{ "CC RTT", "norm.cc_rtt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_rate,
{ "CC Rate", "norm.cc_rate",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cc_transport_id,
{ "CC Transport ID", "norm.cc_transport_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ack_source,
{ "Ack Source", "norm.ack.source",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ack_type,
{ "Ack Type", "norm.ack.type",
FT_UINT8, BASE_DEC, VALS(string_norm_ack_type), 0x0,
NULL, HFILL}
},
{ &hf_ack_id,
{ "Ack ID", "norm.ack.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ack_grtt_sec,
{ "Ack GRTT Sec", "norm.ack.grtt_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ack_grtt_usec,
{ "Ack GRTT usec", "norm.ack.grtt_usec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nack_server,
{ "NAck Server", "norm.nack.server",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nack_grtt_sec,
{ "NAck GRTT Sec", "norm.nack.grtt_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nack_grtt_usec,
{ "NAck GRTT usec", "norm.nack.grtt_usec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nack_form,
{ "NAck FORM", "norm.nack.form",
FT_UINT8, BASE_DEC, VALS(string_norm_nack_form), 0x0,
NULL, HFILL}
},
{ &hf_nack_flags,
{ "NAck Flags", "norm.nack.flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_nack_flags_segment,
{ "Segment", "norm.nack.flags.segment",
FT_BOOLEAN, 8, NULL, NORM_NACK_SEGMENT,
NULL, HFILL}
},
{ &hf_nack_flags_block,
{ "Block", "norm.nack.flags.block",
FT_BOOLEAN, 8, NULL, NORM_NACK_BLOCK,
NULL, HFILL}
},
{ &hf_nack_flags_info,
{ "Info", "norm.nack.flags.info",
FT_BOOLEAN, 8, NULL, NORM_NACK_INFO,
NULL, HFILL}
},
{ &hf_nack_flags_object,
{ "Object", "norm.nack.flags.object",
FT_BOOLEAN, 8, NULL, NORM_NACK_OBJECT,
NULL, HFILL}
},
{ &hf_nack_length,
{ "NAck Length", "norm.nack.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_payload,
{ "Payload", "norm.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fec_encoding_id,
{ "FEC Encoding ID", "norm.fec_encoding_id",
FT_UINT8, BASE_DEC, VALS(string_fec_encoding_id), 0x0,
NULL, HFILL}
}
};
static gint *ett[] = {
&ett_main,
&ett_hdrext,
&ett_flags,
&ett_streampayload,
&ett_congestioncontrol,
&ett_nackdata
};
static ei_register_info ei[] = {
{ &ei_version1_only, { "norm.version1_only", PI_PROTOCOL, PI_WARN, "Sorry, this dissector supports NORM version 1 only", EXPFILL }}
};
module_t *module;
expert_module_t* expert_rmt_norm;
proto_rmt_norm = proto_register_protocol("Negative-acknowledgment Oriented Reliable Multicast", "NORM", "norm");
proto_register_field_array(proto_rmt_norm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rmt_norm = expert_register_protocol(proto_rmt_norm);
expert_register_field_array(expert_rmt_norm, ei, array_length(ei));
module = prefs_register_protocol(proto_rmt_norm, NULL);
prefs_register_obsolete_preference(module, "heuristic_norm");
}
void proto_reg_handoff_norm(void)
{
static dissector_handle_t handle;
handle = create_dissector_handle(dissect_norm, proto_rmt_norm);
dissector_add_for_decode_as("udp.port", handle);
heur_dissector_add("udp", dissect_norm_heur, "NORM over UDP", "rmt_norm_udp", proto_rmt_norm, HEURISTIC_DISABLE);
rmt_fec_handle = find_dissector_add_dependency("rmt-fec", proto_rmt_norm);
}
