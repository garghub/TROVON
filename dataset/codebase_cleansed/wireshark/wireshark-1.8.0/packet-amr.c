static void
dissect_amr_nb_if1(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree){
int offset = 0;
guint8 octet;
proto_tree_add_item(tree, hf_amr_nb_if1_ft, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_if1_fqi, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = (tvb_get_guint8(tvb,offset) & 0xf0) >> 4;
if (octet == AMR_NB_SID){
proto_tree_add_item(tree, hf_amr_nb_if1_mode_req, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb,offset+1) & 0x1f)
proto_tree_add_text(tree, tvb, offset+1, 1, "Error:Spare bits not 0");
proto_tree_add_text(tree, tvb, offset+2, 5, "Speech data");
proto_tree_add_item(tree, hf_amr_if1_sti, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_nb_if1_sti_mode_ind, tvb, offset+7, 1, ENC_BIG_ENDIAN);
return;
}
proto_tree_add_item(tree, hf_amr_nb_if1_mode_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_amr_nb_if1_mode_req, tvb, offset, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb,offset) & 0x1f)
proto_tree_add_text(tree, tvb, offset, 1, "Error:Spare bits not 0");
offset++;
proto_tree_add_text(tree, tvb, offset, -1, "Speech data");
}
static void
dissect_amr_wb_if1(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree){
int offset = 0;
guint8 octet;
proto_tree_add_item(tree, hf_amr_wb_if1_ft, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_if1_fqi, tvb, offset, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb,offset) & 0x03)
proto_tree_add_text(tree, tvb, offset, 1, "Error:Spare bits not 0");
octet = (tvb_get_guint8(tvb,offset) & 0xf0) >> 4;
if (octet == AMR_WB_SID){
proto_tree_add_item(tree, hf_amr_wb_if1_mode_req, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+2, 4, "Speech data");
proto_tree_add_item(tree, hf_amr_if1_sti, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_wb_if1_sti_mode_ind, tvb, offset+7, 1, ENC_BIG_ENDIAN);
return;
}
offset++;
proto_tree_add_item(tree, hf_amr_wb_if1_mode_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_wb_if1_mode_req, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(tree, tvb, offset, -1, "Speech data");
}
static void
dissect_amr_nb_if2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree){
int offset = 0;
guint8 octet;
proto_tree_add_item(tree, hf_amr_nb_if2_ft, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset) & 0x0f;
if (octet == AMR_NB_SID) {
proto_tree_add_text(tree, tvb, offset+1, 3, "Speech data");
proto_tree_add_item(tree, hf_amr_if2_sti, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_nb_if2_sti_mode_ind, tvb, offset+5, 1, ENC_BIG_ENDIAN);
return;
}
if (octet == AMR_NO_TRANS)
return;
proto_tree_add_text(tree, tvb, offset+1, -1, "Speech data");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext(octet, &amr_nb_codec_mode_request_vals_ext, "Unknown (%d)" ));
}
static void
dissect_amr_wb_if2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree){
int offset = 0;
guint8 octet;
proto_tree_add_item(tree, hf_amr_wb_if2_ft, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = (tvb_get_guint8(tvb,offset) & 0xf0) >> 4;
if (octet == AMR_WB_SID) {
proto_tree_add_text(tree, tvb, offset+1, 4, "Speech data");
proto_tree_add_item(tree, hf_amr_if2_sti, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_amr_wb_if2_sti_mode_ind, tvb, offset+5, 1, ENC_BIG_ENDIAN);
return;
}
if (octet == AMR_NO_TRANS)
return;
proto_tree_add_text(tree, tvb, offset+1, -1, "Speech data");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext(octet, &amr_wb_codec_mode_request_vals_ext, "Unknown (%d)" ));
}
static void
dissect_amr_be(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint amr_mode){
proto_item *item;
int ft;
int bit_offset = 0;
int bitcount;
int bits_used_for_frames = 0;
int bytes_needed_for_frames;
guint8 f_bit, q_bit;
unsigned char Framebits_NB[] = {95,103,118,134,148,159,204,244,39,43,38,37, 0, 0, 0, 0};
unsigned int Framebits_WB[] = {132,177,253,285,317,365,397,461,477,40,0, 0, 0, 0, 0, 0,};
bitcount = 3;
if (amr_mode==AMR_NB)
proto_tree_add_bits_item(tree, hf_amr_nb_cmr, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
else
proto_tree_add_bits_item(tree, hf_amr_wb_cmr, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
do {
bitcount += 1;
f_bit = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_amr_toc_f, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
ft = tvb_get_bits8(tvb, bit_offset, 4);
if (amr_mode==AMR_NB)
item = proto_tree_add_bits_item(tree, hf_amr_nb_toc_ft, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
else
item = proto_tree_add_bits_item(tree, hf_amr_wb_toc_ft, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
bitcount += 4;
if (amr_mode==AMR_NB)
bits_used_for_frames +=Framebits_NB[ft];
else
bits_used_for_frames +=Framebits_WB[ft];
q_bit = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_amr_toc_q, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
bitcount += 1;
if (q_bit==1)
proto_item_append_text(item, " / Frame OK");
else
proto_item_append_text(item, " / Frame damaged");
} while ((f_bit==1) && (tvb_reported_length_remaining(tvb, bitcount/8)>2));
if (bits_used_for_frames>0)
bytes_needed_for_frames = 1 + (bitcount+bits_used_for_frames)/8-bitcount/8;
else
bytes_needed_for_frames = 0;
if (tvb_reported_length_remaining(tvb, bitcount/8)<bytes_needed_for_frames) {
item = proto_tree_add_text(tree, tvb, bitcount/8, bytes_needed_for_frames, "Error:");
proto_item_append_text(item, " %d Bytes available, %d would be needed!",
tvb_reported_length_remaining(tvb, bitcount/8),
bytes_needed_for_frames);
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "Not enough data for the frames according to TOC");
}
else {
item = proto_tree_add_text(tree, tvb, bitcount/8, bytes_needed_for_frames, "Frame Data");
proto_item_append_text(item, " (%d Bytes)",bytes_needed_for_frames);
}
bitcount+=bits_used_for_frames;
if (tvb_reported_length_remaining(tvb, (bitcount+8)/8)>0) {
item = proto_tree_add_text(tree, tvb, bitcount/8, tvb_reported_length_remaining(tvb, bitcount/8), "Error:");
proto_item_append_text(item, " %d Bytes remaining - should be 0!",tvb_reported_length_remaining(tvb, (bitcount+8)/8));
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "Superfluous data remaining");
if (bitcount%8 != 0) {
if ( (1 << (8 -(bitcount%8)-1)) & tvb_get_guint8(tvb,bitcount/8) )
proto_tree_add_text(tree, tvb, bitcount/8, 1, "Padding bits correct");
else {
item = proto_tree_add_text(tree, tvb, bitcount/8, 1, "Padding bits error");
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "Padding bits error - MUST be 0");
}
}
}
}
static void
dissect_amr_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint amr_mode)
{
int offset = 0;
int bit_offset = 0;
guint8 octet;
proto_item *item;
gboolean first_time;
proto_item *ti,*toc_item;
proto_tree *amr_tree, *toc_tree;
if (tree) {
ti = proto_tree_add_item(tree, proto_amr, tvb, 0, -1, ENC_NA);
amr_tree = proto_item_add_subtree(ti, ett_amr);
proto_tree_add_text(amr_tree, tvb, offset, -1, "Payload decoded as %s",
val_to_str(amr_encoding_type, amr_encoding_type_value, "Unknown value - Error"));
switch (amr_encoding_type){
case 0:
break;
case 1:
dissect_amr_be(tvb, pinfo, amr_tree, amr_mode);
return;
case 2:
if (amr_mode==AMR_NB)
dissect_amr_nb_if1(tvb, pinfo, amr_tree);
else
dissect_amr_wb_if1(tvb, pinfo, amr_tree);
return;
case 3:
if (amr_mode==AMR_NB)
dissect_amr_nb_if2(tvb, pinfo, amr_tree);
else
dissect_amr_wb_if2(tvb, pinfo, amr_tree);
return;
default:
break;
}
if (amr_mode==AMR_NB)
proto_tree_add_bits_item(amr_tree, hf_amr_nb_cmr, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
else
proto_tree_add_bits_item(amr_tree, hf_amr_wb_cmr, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
octet = tvb_get_guint8(tvb,offset) & 0x0f;
if ( octet != 0 ){
item = proto_tree_add_text(amr_tree, tvb, offset, -1, "Reserved != 0, wrongly encoded or not octet aligned. Decoding as bandwidth-efficient mode");
PROTO_ITEM_SET_GENERATED(item);
return;
}
proto_tree_add_item(amr_tree, hf_amr_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
bit_offset+=4;
octet = tvb_get_guint8(tvb,offset);
toc_item = proto_tree_add_text(amr_tree, tvb, offset, -1, "Payload Table of Contents");
toc_tree = proto_item_add_subtree(toc_item, ett_amr_toc);
first_time = TRUE;
while ((( octet& 0x80 ) == 0x80)||(first_time == TRUE)){
first_time = FALSE;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_bits_item(toc_tree, hf_amr_toc_f, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (amr_mode==AMR_NB)
proto_tree_add_bits_item(toc_tree, hf_amr_nb_toc_ft, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
else
proto_tree_add_bits_item(toc_tree, hf_amr_wb_toc_ft, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
proto_tree_add_bits_item(toc_tree, hf_amr_toc_q, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
bit_offset+=2;
offset++;
}
}
}
static void
dissect_amr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AMR");
dissect_amr_common(tvb, pinfo, tree, pref_amr_mode);
}
static void
dissect_amr_wb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AMR-WB");
dissect_amr_common(tvb, pinfo, tree, AMR_WB);
}
static amr_capability_t *find_cap(const gchar *id) {
amr_capability_t *ftr = NULL;
amr_capability_t *f;
for (f=amr_capability_tab; f->id; f++) {
if (!strcmp(id, f->id)) { ftr = f; break; }
}
return ftr;
}
static void
dissect_amr_name(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree)
{
asn1_ctx_t *actx;
amr_capability_t *ftr = NULL;
actx = get_asn1_ctx(pinfo->private_data);
DISSECTOR_ASSERT(actx != NULL);
if (tree && actx != NULL) {
ftr = find_cap(pinfo->match_string);
if (ftr) {
proto_item_append_text(actx->created_item, " - %s", ftr->name);
proto_item_append_text(proto_item_get_parent(proto_tree_get_parent(tree)), ": %s", ftr->name);
} else {
proto_item_append_text(actx->created_item, " - unknown(%s)", pinfo->match_string);
}
}
}
void
proto_reg_handoff_amr(void)
{
static dissector_handle_t amr_handle;
static dissector_handle_t amr_wb_handle;
static guint dynamic_payload_type;
static gboolean amr_prefs_initialized = FALSE;
if (!amr_prefs_initialized) {
dissector_handle_t amr_name_handle;
amr_capability_t *ftr;
amr_handle = find_dissector("amr");
amr_wb_handle = find_dissector("amr-wb");
dissector_add_string("rtp_dyn_payload_type","AMR", amr_handle);
dissector_add_string("rtp_dyn_payload_type","AMR-WB", amr_wb_handle);
amr_name_handle = create_dissector_handle(dissect_amr_name, proto_amr);
for (ftr=amr_capability_tab; ftr->id; ftr++) {
if (ftr->name)
dissector_add_string("h245.gef.name", ftr->id, amr_name_handle);
if (ftr->content_pdu)
dissector_add_string("h245.gef.content", ftr->id, new_create_dissector_handle(ftr->content_pdu, proto_amr));
}
amr_prefs_initialized = TRUE;
} else {
if ( dynamic_payload_type > 95 )
dissector_delete_uint("rtp.pt", dynamic_payload_type, amr_handle);
}
dynamic_payload_type = temp_dynamic_payload_type;
if ( dynamic_payload_type > 95 ){
dissector_add_uint("rtp.pt", dynamic_payload_type, amr_handle);
}
}
void
proto_register_amr(void)
{
module_t *amr_module;
static hf_register_info hf[] = {
{ &hf_amr_nb_cmr,
{ "CMR", "amr.nb.cmr",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_request_vals_ext, 0x0,
"codec mode request", HFILL }
},
{ &hf_amr_wb_cmr,
{ "CMR", "amr.wb.cmr",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_request_vals_ext, 0x0,
"codec mode request", HFILL }
},
{ &hf_amr_reserved,
{ "Reserved", "amr.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"Reserved bits", HFILL }
},
{ &hf_amr_toc_f,
{ "F bit", "amr.toc.f",
FT_BOOLEAN, BASE_NONE, TFS(&toc_f_bit_vals), 0x0,
NULL, HFILL }
},
{ &hf_amr_nb_toc_ft,
{ "FT bits", "amr.nb.toc.ft",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_request_vals_ext, 0x0,
"Frame type index", HFILL }
},
{ &hf_amr_wb_toc_ft,
{ "FT bits", "amr.wb.toc.ft",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_request_vals_ext, 0x0,
"Frame type index", HFILL }
},
{ &hf_amr_toc_q,
{ "Q bit", "amr.toc.q",
FT_BOOLEAN, BASE_NONE, TFS(&toc_q_bit_vals), 0x0,
"Frame quality indicator bit", HFILL }
},
{ &hf_amr_nb_if1_ft,
{ "Frame Type", "amr.nb.if1.ft",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_amr_wb_if1_ft,
{ "Frame Type", "amr.wb.if1.ft",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_amr_nb_if1_mode_req,
{ "Mode Type request", "amr.nb.if1.modereq",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_request_vals_ext, 0xe0,
NULL, HFILL }
},
{ &hf_amr_wb_if1_mode_req,
{ "Mode Type request", "amr.wb.if1.modereq",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_request_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_amr_if1_sti,
{ "SID Type Indicator", "amr.if1.sti",
FT_BOOLEAN, 8, TFS(&amr_sti_vals), 0x10,
NULL, HFILL }
},
{ &hf_amr_nb_if1_sti_mode_ind,
{ "Mode Type indication", "amr.nb.if1.stimodeind",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_vals_ext, 0x0e,
NULL, HFILL }
},
{ &hf_amr_wb_if1_sti_mode_ind,
{ "Mode Type indication", "amr.wb.if1.stimodeind",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_amr_nb_if1_mode_ind,
{ "Mode Type indication", "amr.nb.if1.modeind",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_vals_ext, 0x07,
NULL, HFILL }
},
{ &hf_amr_wb_if1_mode_ind,
{ "Mode Type indication", "amr.wb.if1.modeind",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_amr_nb_if2_ft,
{ "Frame Type", "amr.nb.if2.ft",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_amr_wb_if2_ft,
{ "Frame Type", "amr.wb.if2.ft",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_amr_if2_sti,
{ "SID Type Indicator", "amr.if2.sti",
FT_BOOLEAN, 8, TFS(&amr_sti_vals), 0x80,
NULL, HFILL }
},
{ &hf_amr_nb_if2_sti_mode_ind,
{ "Mode Type indication", "amr.nb.if2.stimodeind",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_nb_codec_mode_vals_ext, 0x07,
NULL, HFILL }
},
{ &hf_amr_wb_if2_sti_mode_ind,
{ "Mode Type indication", "amr.wb.if2.stimodeind",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &amr_wb_codec_mode_vals_ext, 0x78,
NULL, HFILL }
},
{ &hf_amr_if1_fqi,
{ "FQI", "amr.fqi",
FT_BOOLEAN, 8, TFS(&toc_q_bit_vals), 0x08,
"Frame quality indicator bit", HFILL }
},
};
static gint *ett[] = {
&ett_amr,
&ett_amr_toc,
};
static enum_val_t encoding_types[] = {
{"RFC 3267 Byte aligned", "RFC 3267 octet aligned", 0},
{"RFC 3267 Bandwidth-efficient", "RFC 3267 BW-efficient", 1},
{"AMR IF1", "AMR IF1", 2},
{"AMR IF2", "AMR IF2", 3},
{NULL, NULL, -1}
};
static enum_val_t modes[] = {
{"AMR-NB", "Narrowband AMR", AMR_NB},
{"AMR-WB", "Wideband AMR", AMR_WB},
{NULL, NULL, -1}
};
proto_amr = proto_register_protocol("Adaptive Multi-Rate","AMR", "amr");
proto_register_field_array(proto_amr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
amr_module = prefs_register_protocol(proto_amr, proto_reg_handoff_amr);
prefs_register_uint_preference(amr_module, "dynamic.payload.type",
"AMR dynamic payload type",
"The dynamic payload type which will be interpreted as AMR"
"; The value must be greater than 95",
10,
&temp_dynamic_payload_type);
prefs_register_enum_preference(amr_module, "encoding.version",
"Type of AMR encoding of the payload",
"Type of AMR encoding of the payload",
&amr_encoding_type, encoding_types, FALSE);
prefs_register_enum_preference(amr_module, "mode",
"The AMR mode",
"The AMR mode",
&pref_amr_mode, modes, AMR_NB);
register_dissector("amr", dissect_amr, proto_amr);
register_dissector("amr-wb", dissect_amr_wb, proto_amr);
register_dissector("amr_if1_nb", dissect_amr_nb_if1, proto_amr);
register_dissector("amr_if1_wb", dissect_amr_wb_if1, proto_amr);
register_dissector("amr_if2_nb", dissect_amr_nb_if2, proto_amr);
register_dissector("amr_if2_wb", dissect_amr_wb_if2, proto_amr);
oid_add_from_string("G.722.2 (AMR-WB) audio capability","0.0.7.7222.1.0");
}
