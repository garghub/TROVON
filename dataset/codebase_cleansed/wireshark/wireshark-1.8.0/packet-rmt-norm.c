static void norm_prefs_set_default(struct _norm_prefs *norm_prefs)
{
fec_prefs_set_default(&norm_prefs->fec);
}
static void norm_prefs_register(struct _norm_prefs *norm_prefs, module_t *module)
{
fec_prefs_register(&norm_prefs->fec, module);
}
static void norm_prefs_save(struct _norm_prefs *p, struct _norm_prefs *p_old)
{
*p_old = *p;
}
static double UnquantizeRtt(unsigned char qrtt)
{
return ((qrtt <= 31) ? (((double)(qrtt+1))*(double)RTT_MIN) :
(RTT_MAX/exp(((double)(255-qrtt))/(double)13.0)));
}
static double UnquantizeGSize(guint8 gsizex)
{
guint mant = (gsizex & 0x8) ? 5 : 1;
guint exponent = gsizex & 0x7;
exponent ++;
return mant * pow(10, exponent);
}
static double UnquantizeSendRate(guint16 send_rate)
{
return (send_rate >> 4) * 10.0 / 4096.0 * pow(10.0, (send_rate & 0x000f));
}
static guint dissect_grrtetc(proto_tree *tree, tvbuff_t *tvb, guint offset)
{
guint8 backoff;
double gsizex;
double grtt;
proto_tree_add_item(tree, hf.instance_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
grtt = UnquantizeRtt(tvb_get_guint8(tvb, offset));
proto_tree_add_double(tree, hf.grtt, tvb, offset, 1, grtt); offset++;
backoff = hi_nibble(tvb_get_guint8(tvb, offset));
gsizex = UnquantizeGSize((guint8)lo_nibble(tvb_get_guint8(tvb, offset)));
proto_tree_add_uint(tree, hf.backoff, tvb, offset, 1, backoff);
proto_tree_add_double(tree, hf.gsize, tvb, offset, 1, gsizex);
offset++;
return offset;
}
static guint dissect_feccode(struct _norm *norm, struct _fec_ptr *f, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo, gint reserved)
{
f->fec = &norm->fec;
f->hf = &hf.fec;
f->ett = &ett.fec;
f->prefs = &preferences.fec;
norm->fec.encoding_id = tvb_get_guint8(tvb, offset);
norm->fec.encoding_id_present = 1;
proto_tree_add_item(tree, hf.fec.encoding_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
if (reserved) {
proto_tree_add_item(tree, hf.reserved, tvb, offset, 1, ENC_NA); offset++;
}
proto_tree_add_item(tree, hf.object_transport_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
if (norm->fec.encoding_id_present &&
tvb_reported_length_remaining(tvb, offset) > 0) {
fec_dissector(*f, tvb, tree, &offset);
if (check_col(pinfo->cinfo, COL_INFO))
fec_info_column(f->fec, pinfo);
}
return offset;
}
static guint dissect_norm_hdrext(struct _norm *norm, struct _fec_ptr *f, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo _U_)
{
guint i;
proto_item *ti;
GArray *ext;
guint offset_old = offset;
proto_tree *ext_tree;
ext = g_array_new(FALSE, TRUE, sizeof(struct _ext));
rmt_ext_parse(ext, tvb, &offset, hdrlen2bytes(norm->hlen));
if (ext->len > 0)
{
struct _lct_prefs lctp;
memset(&lctp, 0, sizeof(lctp));
if (tree)
{
ti = proto_tree_add_uint(tree, hf.extension,
tvb, offset_old,
offset - offset_old, ext->len);
ext_tree = proto_item_add_subtree(ti, ett.hdrext);
} else
ext_tree = NULL;
for (i = 0; i < ext->len; i++) {
struct _ext *e = &g_array_index(ext, struct _ext, i);
lct_ext_decode(e, &lctp, tvb, ext_tree, ett.hdrext, *f);
}
}
g_array_free(ext, TRUE);
return offset;
}
static guint dissect_nack_data(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
proto_item *ti, *tif;
proto_tree *nack_tree, *flag_tree;
guint16 len;
ti = proto_tree_add_text(tree, tvb, offset, -1, "NACK Data");
nack_tree = proto_item_add_subtree(ti, ett.nackdata);
proto_tree_add_item(nack_tree, hf.nack_form, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
tif = proto_tree_add_item(nack_tree, hf.nack_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(tif, ett.flags);
proto_tree_add_item(flag_tree, hf.nack_flags_segment, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.nack_flags_block, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.nack_flags_info, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.nack_flags_object, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(nack_tree, hf.nack_length, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_set_len(ti, 4+len);
if (len > 4) {
struct _fec_ptr f;
dissect_feccode(norm, &f, nack_tree, tvb, offset, pinfo, 1);
}
offset += len;
return offset;
}
static void dissect_norm_data(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
guint8 flags;
proto_item *ti;
proto_tree *flag_tree;
struct _fec_ptr f;
offset = dissect_grrtetc(tree, tvb, offset);
ti = proto_tree_add_item(tree, hf.flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, offset);
flag_tree = proto_item_add_subtree(ti, ett.flags);
proto_tree_add_item(flag_tree, hf.flag.repair, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.explicit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.info, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.unreliable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.file, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.stream, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.msgstart, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = dissect_feccode(norm, &f, tree, tvb, offset, pinfo, 0);
if (offset < hdrlen2bytes(norm->hlen)) {
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
if (flags & NORM_FLAG_STREAM) {
ti = proto_tree_add_text(tree, tvb, offset, 8, "Stream Data");
flag_tree = proto_item_add_subtree(ti, ett.streampayload);
proto_tree_add_item(flag_tree, hf.reserved, tvb, offset, 2, ENC_NA); offset+=2;
proto_tree_add_item(flag_tree, hf.payload_len, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(flag_tree, hf.payload_offset, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_none_format(tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_reported_length_remaining(tvb, offset));
}
static void dissect_norm_info(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo _U_)
{
proto_item *ti;
proto_tree *flag_tree;
offset = dissect_grrtetc(tree, tvb, offset);
ti = proto_tree_add_item(tree, hf.flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(ti, ett.flags);
proto_tree_add_item(flag_tree, hf.flag.repair, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.explicit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.info, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.unreliable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.file, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.stream, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.flag.msgstart, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
norm->fec.encoding_id = tvb_get_guint8(tvb, offset);
norm->fec.encoding_id_present = 1;
proto_tree_add_item(tree, hf.fec.encoding_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf.object_transport_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
if (offset < hdrlen2bytes(norm->hlen)) {
struct _fec_ptr f;
memset(&f, 0, sizeof f);
f.fec = &norm->fec;
f.hf = &hf.fec;
f.ett = &ett.fec;
f.prefs = &preferences.fec;
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_none_format(tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_reported_length_remaining(tvb, offset));
}
static guint dissect_norm_cmd_flush(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
struct _fec_ptr f;
offset = dissect_feccode(norm, &f, tree, tvb, offset, pinfo, 0);
if (offset < hdrlen2bytes(norm->hlen)) {
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
return offset;
}
static guint dissect_norm_cmd_repairadv(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
proto_tree_add_item(tree, hf.flags, tvb, offset, 1, ENC_BIG_ENDIAN); offset ++;
proto_tree_add_item(tree, hf.reserved, tvb, offset, 2, ENC_NA); offset +=2;
if (offset < hdrlen2bytes(norm->hlen)) {
struct _fec_ptr f;
memset(&f, 0, sizeof f);
f.fec = &norm->fec;
f.hf = &hf.fec;
f.ett = &ett.fec;
f.prefs = &preferences.fec;
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_nack_data(norm, tree, tvb, offset, pinfo);
}
return offset;
}
static guint dissect_norm_cmd_cc(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo _U_)
{
proto_tree_add_item(tree, hf.reserved, tvb, offset, 1, ENC_NA); offset ++;
proto_tree_add_item(tree, hf.cc_sequence, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf.cc_sts, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf.cc_stus, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
if (offset < hdrlen2bytes(norm->hlen)) {
struct _fec_ptr f;
memset(&f, 0, sizeof f);
f.fec = &norm->fec;
f.hf = &hf.fec;
f.ett = &ett.fec;
f.prefs = &preferences.fec;
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_item *ti, *tif;
proto_tree *cc_tree, *flag_tree;
double grtt;
ti = proto_tree_add_text(tree, tvb, offset, 8, "Congestion Control");
cc_tree = proto_item_add_subtree(ti, ett.congestioncontrol);
proto_tree_add_item(cc_tree, hf.cc_node_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
tif = proto_tree_add_item(cc_tree, hf.cc_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(tif, ett.flags);
proto_tree_add_item(flag_tree, hf.cc_flags_clr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.cc_flags_plr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.cc_flags_rtt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.cc_flags_start, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf.cc_flags_leave, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
grtt = UnquantizeRtt(tvb_get_guint8(tvb, offset));
proto_tree_add_double(cc_tree, hf.cc_rtt, tvb, offset, 1, grtt); offset += 1;
grtt = UnquantizeSendRate(tvb_get_ntohs(tvb, offset));
proto_tree_add_double(cc_tree, hf.cc_rate, tvb, offset, 2, grtt); offset += 2;
}
return offset;
}
static guint dissect_norm_cmd_squelch(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
struct _fec_ptr f;
offset = dissect_feccode(norm, &f, tree, tvb, offset, pinfo, 0);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf.cc_transport_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 2;
}
return offset;
}
static guint dissect_norm_cmd_ackreq(struct _norm *norm _U_, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo _U_)
{
proto_tree_add_item(tree, hf.reserved, tvb, offset, 1, ENC_NA); offset ++;
proto_tree_add_item(tree, hf.ack_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf.ack_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
return offset;
}
static void dissect_norm_cmd(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
guint8 flavor;
offset = dissect_grrtetc(tree, tvb, offset);
flavor = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_sep_str(pinfo->cinfo, COL_INFO, " ",
val_to_str(flavor, string_norm_cmd_type, "Unknown Cmd Type (0x%04x)"));
proto_tree_add_item(tree, hf.cmd_flavor, tvb, offset, 1, ENC_BIG_ENDIAN); offset ++;
switch(flavor) {
case NORM_CMD_CC:
offset = dissect_norm_cmd_cc(norm, tree, tvb, offset, pinfo);
break;
case NORM_CMD_FLUSH:
offset = dissect_norm_cmd_flush(norm, tree, tvb, offset, pinfo);
break;
case NORM_CMD_SQUELCH:
offset = dissect_norm_cmd_squelch(norm, tree, tvb, offset, pinfo);
break;
case NORM_CMD_REPAIR_ADV:
offset = dissect_norm_cmd_repairadv(norm, tree, tvb, offset, pinfo);
break;
case NORM_CMD_ACK_REQ:
offset = dissect_norm_cmd_ackreq(norm, tree, tvb, offset, pinfo);
break;
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_none_format(tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_reported_length_remaining(tvb, offset));
}
static void dissect_norm_ack(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
guint8 acktype;
proto_tree_add_item(tree, hf.ack_source, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf.instance_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
acktype = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_sep_str(pinfo->cinfo, COL_INFO, " ",
val_to_str(acktype, string_norm_ack_type, "Unknown Ack Type (0x%04x)"));
proto_tree_add_item(tree, hf.ack_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf.ack_id, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree, hf.ack_grtt_sec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf.ack_grtt_usec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
if (offset < hdrlen2bytes(norm->hlen)) {
struct _fec_ptr f;
memset(&f, 0, sizeof f);
f.fec = &norm->fec;
f.hf = &hf.fec;
f.ett = &ett.fec;
f.prefs = &preferences.fec;
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_none_format(tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_reported_length_remaining(tvb, offset));
}
static void dissect_norm_nack(struct _norm *norm, proto_tree *tree,
tvbuff_t *tvb, guint offset, packet_info *pinfo)
{
proto_tree_add_item(tree, hf.nack_server, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf.instance_id, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf.reserved, tvb, offset, 2, ENC_NA); offset += 2;
proto_tree_add_item(tree, hf.nack_grtt_sec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree, hf.nack_grtt_usec, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
if (offset < hdrlen2bytes(norm->hlen)) {
struct _fec_ptr f;
memset(&f, 0, sizeof f);
f.fec = &norm->fec;
f.hf = &hf.fec;
f.ett = &ett.fec;
f.prefs = &preferences.fec;
offset = dissect_norm_hdrext(norm, &f, tree, tvb, offset, pinfo);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_nack_data(norm, tree, tvb, offset, pinfo);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_none_format(tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_reported_length_remaining(tvb, offset));
}
static void dissect_norm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct _norm norm;
guint offset;
proto_item *ti;
proto_tree *norm_tree;
offset = 0;
memset(&norm, 0, sizeof(struct _norm));
pinfo->current_proto = "NORM";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NORM");
col_clear(pinfo->cinfo, COL_INFO);
norm.version = hi_nibble(tvb_get_guint8(tvb, offset));
if (tree)
{
ti = proto_tree_add_item(tree, proto, tvb, offset, -1, ENC_NA);
norm_tree = proto_item_add_subtree(ti, ett.main);
proto_tree_add_uint(norm_tree, hf.version, tvb, offset, 1, norm.version);
} else
norm_tree = NULL;
if (norm.version == 1) {
norm.type = lo_nibble(tvb_get_guint8(tvb, offset));
norm.hlen = tvb_get_guint8(tvb, offset+1);
norm.sequence = tvb_get_ntohs(tvb, offset+2);
norm.source_id = tvb_get_ntohl(tvb, offset+4);
if (tree)
{
proto_tree_add_uint(norm_tree, hf.type, tvb, offset, 1, norm.type);
proto_tree_add_uint(norm_tree, hf.hlen, tvb, offset+1, 1, norm.hlen);
proto_tree_add_uint(norm_tree, hf.sequence, tvb, offset+2, 2, norm.sequence);
proto_tree_add_item(norm_tree, hf.source_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
offset += 8;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_sep_str(pinfo->cinfo, COL_INFO, " ",
val_to_str(norm.type, string_norm_type, "Unknown Type (0x%04x)"));
switch(norm.type) {
case NORM_INFO:
dissect_norm_info(&norm, norm_tree, tvb, offset, pinfo);
break;
case NORM_DATA:
dissect_norm_data(&norm, norm_tree, tvb, offset, pinfo);
break;
case NORM_CMD:
dissect_norm_cmd(&norm, norm_tree, tvb, offset, pinfo);
break;
case NORM_ACK:
dissect_norm_ack(&norm, norm_tree, tvb, offset, pinfo);
break;
case NORM_NACK:
dissect_norm_nack(&norm, norm_tree, tvb, offset, pinfo);
break;
default:
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_none_format(norm_tree, hf.payload, tvb, offset, -1, "Payload (%u bytes)", tvb_reported_length_remaining(tvb, offset));
break;
}
} else {
if (tree)
proto_tree_add_text(norm_tree, tvb, 0, -1, "Sorry, this dissector supports NORM version 1 only");
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Version: %u (not supported)", norm.version);
}
}
static gboolean
dissect_norm_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 byte1;
if (!global_norm_heur)
return FALSE;
if (tvb_length(tvb) < 2)
return FALSE;
byte1 = tvb_get_guint8(tvb, 0);
if (hi_nibble(byte1) != 1) return FALSE;
if (lo_nibble(byte1) < 1 || lo_nibble(byte1) > 6) return FALSE;
if (tvb_get_guint8(tvb, 1) > 20) return FALSE;
if (tvb_length(tvb) < 12)
return FALSE;
dissect_norm(tvb, pinfo, tree);
return TRUE;
}
void proto_reg_handoff_norm(void)
{
static gboolean preferences_initialized = FALSE;
static dissector_handle_t handle;
static struct _norm_prefs preferences_old;
if (!preferences_initialized)
{
preferences_initialized = TRUE;
handle = create_dissector_handle(dissect_norm, proto);
dissector_add_handle("udp.port", handle);
heur_dissector_add("udp", dissect_norm_heur, proto);
}
norm_prefs_save(&preferences, &preferences_old);
}
void proto_register_norm(void)
{
static hf_register_info hf_ptr[] = {
{ &hf.version,
{ "Version", "norm.version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf.type,
{ "Message Type", "norm.type", FT_UINT8, BASE_DEC, VALS(string_norm_type), 0x0, NULL, HFILL }},
{ &hf.hlen,
{ "Header length", "norm.hlen", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf.sequence,
{ "Sequence", "norm.sequence", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf.source_id,
{ "Source ID", "norm.source_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf.instance_id,
{ "Instance", "norm.instance_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.grtt,
{ "grtt", "norm.grtt", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.backoff,
{ "Backoff", "norm.backoff", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.gsize,
{ "Group Size", "norm.gsize", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.flags,
{ "Flags", "norm.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf.flag.repair,
{ "Repair Flag", "norm.flag.repair", FT_BOOLEAN, 8, NULL, NORM_FLAG_REPAIR, NULL, HFILL }},
{ &hf.flag.explicit,
{ "Explicit Flag", "norm.flag.explicit", FT_BOOLEAN, 8, NULL, NORM_FLAG_EXPLICIT, NULL, HFILL }},
{ &hf.flag.info,
{ "Info Flag", "norm.flag.info", FT_BOOLEAN, 8, NULL, NORM_FLAG_INFO, NULL, HFILL }},
{ &hf.flag.unreliable,
{ "Unreliable Flag", "norm.flag.unreliable", FT_BOOLEAN, 8, NULL, NORM_FLAG_UNRELIABLE, NULL, HFILL }},
{ &hf.flag.file,
{ "File Flag", "norm.flag.file", FT_BOOLEAN, 8, NULL, NORM_FLAG_FILE, NULL, HFILL }},
{ &hf.flag.stream,
{ "Stream Flag", "norm.flag.stream", FT_BOOLEAN, 8, NULL, NORM_FLAG_STREAM, NULL, HFILL }},
{ &hf.flag.msgstart,
{ "Msg Start Flag", "norm.flag.msgstart", FT_BOOLEAN, 8, NULL, NORM_FLAG_MSG_START, NULL, HFILL }},
{ &hf.object_transport_id,
{ "Object Transport ID", "norm.object_transport_id", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf.extension,
{ "Hdr Extension", "norm.hexext", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.reserved,
{ "Reserved", "norm.reserved", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.payload_len,
{ "Payload Len", "norm.payload.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.payload_offset,
{ "Payload Offset", "norm.payload.offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.cmd_flavor,
{ "Flavor", "norm.flavor", FT_UINT8, BASE_DEC, VALS(string_norm_cmd_type), 0x0, NULL, HFILL}},
{ &hf.cc_sequence,
{ "CC Sequence", "norm.ccsequence", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_sts,
{ "Send Time secs", "norm.cc_sts", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_stus,
{ "Send Time usecs", "norm.cc_stus", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_node_id,
{ "CC Node ID", "norm.cc_node_id", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_flags,
{ "CC Flags", "norm.cc_flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_flags_clr,
{ "CLR", "norm.cc_flags.clr", FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_CLR, NULL, HFILL}},
{ &hf.cc_flags_plr,
{ "PLR", "norm.cc_flags.plr", FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_PLR, NULL, HFILL}},
{ &hf.cc_flags_rtt,
{ "RTT", "norm.cc_flags.rtt", FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_RTT, NULL, HFILL}},
{ &hf.cc_flags_start,
{ "Start", "norm.cc_flags.start", FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_START, NULL, HFILL}},
{ &hf.cc_flags_leave,
{ "Leave", "norm.cc_flags.leave", FT_BOOLEAN, 8, NULL, NORM_FLAG_CC_LEAVE, NULL, HFILL}},
{ &hf.cc_rtt,
{ "CC RTT", "norm.cc_rtt", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_rate,
{ "CC Rate", "norm.cc_rate", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.cc_transport_id,
{ "CC Transport ID", "norm.cc_transport_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.ack_source,
{ "Ack Source", "norm.ack.source", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.ack_type,
{ "Ack Type", "norm.ack.type", FT_UINT8, BASE_DEC, VALS(string_norm_ack_type), 0x0, NULL, HFILL}},
{ &hf.ack_id,
{ "Ack ID", "norm.ack.id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.ack_grtt_sec,
{ "Ack GRTT Sec", "norm.ack.grtt_sec", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.ack_grtt_usec,
{ "Ack GRTT usec", "norm.ack.grtt_usec", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.nack_server,
{ "NAck Server", "norm.nack.server", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf.nack_grtt_sec,
{ "NAck GRTT Sec", "norm.nack.grtt_sec", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.nack_grtt_usec,
{ "NAck GRTT usec", "norm.nack.grtt_usec", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.nack_form,
{ "NAck FORM", "norm.nack.form", FT_UINT8, BASE_DEC, VALS(string_norm_nack_form), 0x0, NULL, HFILL}},
{ &hf.nack_flags,
{ "NAck Flags", "norm.nack.flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf.nack_flags_segment,
{ "Segment", "norm.nack.flags.segment", FT_BOOLEAN, 8, NULL, NORM_NACK_SEGMENT, NULL, HFILL}},
{ &hf.nack_flags_block,
{ "Block", "norm.nack.flags.block", FT_BOOLEAN, 8, NULL, NORM_NACK_BLOCK, NULL, HFILL}},
{ &hf.nack_flags_info,
{ "Info", "norm.nack.flags.info", FT_BOOLEAN, 8, NULL, NORM_NACK_INFO, NULL, HFILL}},
{ &hf.nack_flags_object,
{ "Object", "norm.nack.flags.object", FT_BOOLEAN, 8, NULL, NORM_NACK_OBJECT, NULL, HFILL}},
{ &hf.nack_length,
{ "NAck Length", "norm.nack.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
FEC_FIELD_ARRAY(hf.fec, "NORM"),
{ &hf.payload,
{ "Payload", "norm.payload", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett_ptr[] = {
&ett.main,
&ett.hdrext,
&ett.flags,
&ett.streampayload,
&ett.congestioncontrol,
&ett.nackdata,
FEC_SUBTREE_ARRAY(ett.fec)
};
module_t *module;
memset(&hf, 0xff, sizeof(struct _norm_hf));
memset(&ett, 0xff, sizeof(struct _norm_ett));
proto = proto_register_protocol("Negative-acknowledgment Oriented Reliable Multicast", "NORM", "norm");
proto_register_field_array(proto, hf_ptr, array_length(hf_ptr));
proto_register_subtree_array(ett_ptr, array_length(ett_ptr));
norm_prefs_set_default(&preferences);
module = prefs_register_protocol(proto, proto_reg_handoff_norm);
norm_prefs_register(&preferences, module);
prefs_register_bool_preference(module, "heuristic_norm",
"Try to decode UDP packets as NORM packets",
"Check this to decode NORM traffic between clients",
&global_norm_heur);
}
