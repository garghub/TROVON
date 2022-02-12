static int
dissect_mp4ves_user_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int bit_offset)
{
int start_bit_offset;
proto_tree_add_bits_item(tree, hf_mp4ves_start_code_prefix, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
bit_offset+=24;
proto_tree_add_bits_item(tree, hf_mp4ves_start_code, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset+=8;
start_bit_offset = bit_offset;
while ( tvb_get_bits32(tvb,bit_offset, 24, ENC_BIG_ENDIAN) != 1){
bit_offset+=8;
}
proto_tree_add_text(tree, tvb, start_bit_offset>>3, (bit_offset - start_bit_offset)>>2, "User data");
return bit_offset;
}
static int
dissect_mp4ves_next_start_code(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int bit_offset)
{
guint8 zero_bit;
int start_bit_offset;
start_bit_offset = bit_offset;
zero_bit = tvb_get_bits8(tvb,bit_offset,1);
if (zero_bit != 0){
}
bit_offset++;
if(bit_offset %8 == 0)
return bit_offset;
while(bit_offset %8 != 0){
bit_offset++;
}
proto_tree_add_bits_item(tree, hf_mp4ves_stuffing, tvb, start_bit_offset, bit_offset-start_bit_offset, ENC_BIG_ENDIAN);
return bit_offset;
}
static int
dissect_mp4ves_visual_object_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int bit_offset)
{
guint8 video_signal_type, colour_description;
video_signal_type = tvb_get_bits8(tvb,bit_offset,1);
proto_tree_add_bits_item(tree, hf_mp4ves_video_signal_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (video_signal_type) {
bit_offset+=3;
bit_offset++;
colour_description = tvb_get_bits8(tvb,bit_offset,1);
if (colour_description) {
bit_offset+=8;
bit_offset+=8;
bit_offset+=8;
}
}
return bit_offset;
}
static int
dissect_mp4ves_VideoObjectLayer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int bit_offset)
{
guint32 dword;
int current_bit_offset;
guint8 octet, is_object_layer_identifier, aspect_ratio_info, vol_control_parameters, vbv_parameters;
guint8 video_object_layer_shape, video_object_layer_verid = 0;
dword = tvb_get_bits32(tvb,bit_offset, 24, ENC_BIG_ENDIAN);
if (dword != 1){
return bit_offset;
}
octet = tvb_get_bits8(tvb,bit_offset+24, 8);
if((octet>=0x20)&&(octet<=0x2f)){
}else{
return bit_offset;
}
proto_tree_add_bits_item(tree, hf_mp4ves_start_code_prefix, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
bit_offset+=24;
proto_tree_add_bits_item(tree, hf_mp4ves_start_code, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset+= 8;
proto_tree_add_bits_item(tree, hf_mp4ves_random_accessible_vol, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_mp4ves_video_object_type_indication, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset+= 8;
is_object_layer_identifier = tvb_get_bits8(tvb,bit_offset, 1);
proto_tree_add_bits_item(tree, hf_mp4ves_is_object_layer_identifier, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if(is_object_layer_identifier) {
bit_offset+=4;
bit_offset+=3;
}
aspect_ratio_info = tvb_get_bits8(tvb,bit_offset, 1);
proto_tree_add_bits_item(tree, hf_mp4ves_aspect_ratio_info, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
if (aspect_ratio_info == 0xf ) {
bit_offset+=8;
bit_offset+=8;
}
vol_control_parameters = tvb_get_bits8(tvb,bit_offset, 1);
proto_tree_add_bits_item(tree, hf_mp4ves_vol_control_parameters, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
current_bit_offset = bit_offset;
if (vol_control_parameters) {
bit_offset+=2;
bit_offset++;
vbv_parameters = tvb_get_bits8(tvb,bit_offset, 1);
bit_offset++;
if (vbv_parameters) {
bit_offset+=15;
bit_offset++;
bit_offset+=15;
bit_offset++;
bit_offset+=15;
bit_offset++;
bit_offset+=3;
bit_offset+=11;
bit_offset++;
bit_offset+=15;
bit_offset++;
}
}
if(bit_offset-current_bit_offset > 0)
proto_tree_add_text(tree, tvb, current_bit_offset>>3, (bit_offset+7)>>3, "Not dissected bits");
video_object_layer_shape = tvb_get_bits8(tvb,bit_offset, 2);
proto_tree_add_bits_item(tree, hf_mp4ves_video_object_layer_shape, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset+=2;
if (video_object_layer_shape == 3&& video_object_layer_verid != 1){
bit_offset+=4;
}
bit_offset++;
bit_offset+=16;
bit_offset++;
bit_offset++;
return bit_offset;
}
static int
dissect_mp4ves_VisualObject(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int bit_offset)
{
proto_item *item;
guint8 is_visual_object_identifier, visual_object_type;
guint32 dword;
guint8 octet;
is_visual_object_identifier = tvb_get_bits8(tvb,bit_offset,1);
proto_tree_add_bits_item(tree, hf_mp4ves_is_visual_object_identifier, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if(is_visual_object_identifier){
bit_offset+=4;
bit_offset+=3;
}
visual_object_type = tvb_get_bits8(tvb,bit_offset,4);
proto_tree_add_bits_item(tree, hf_mp4ves_visual_object_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset+=4;
if ((visual_object_type == 1) || (visual_object_type == 2)) {
bit_offset = dissect_mp4ves_visual_object_type(tvb, pinfo, tree, bit_offset);
}
bit_offset = dissect_mp4ves_next_start_code(tvb, pinfo, tree, bit_offset);
dword = tvb_get_bits32(tvb,bit_offset, 32, ENC_BIG_ENDIAN);
while(dword==0x1b2){
bit_offset = dissect_mp4ves_user_data(tvb, pinfo, tree, bit_offset);
dword = tvb_get_bits32(tvb,bit_offset, 32, ENC_BIG_ENDIAN);
}
if (visual_object_type == 1) {
dword = tvb_get_bits32(tvb,bit_offset, 24, ENC_BIG_ENDIAN);
if (dword != 1){
return -1;
}
octet = tvb_get_bits8(tvb,bit_offset+24, 8);
if(octet>0x20){
return -1;
}
proto_tree_add_bits_item(tree, hf_mp4ves_start_code_prefix, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
bit_offset+=24;
proto_tree_add_bits_item(tree, hf_mp4ves_start_code, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset+= 8;
if(tvb_length_remaining(tvb,(bit_offset>>3))<=0){
item = proto_tree_add_text(tree, tvb, 0, -1, "Config string too short");
PROTO_ITEM_SET_GENERATED(item);
return -1;
}
bit_offset = dissect_mp4ves_VideoObjectLayer(tvb, pinfo, tree, bit_offset);
}
return bit_offset;
}
static int
dissect_mp4ves_VisualObjectSequence(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int bit_offset)
{
guint32 dword;
dword = tvb_get_bits32(tvb,bit_offset, 32, ENC_BIG_ENDIAN);
if ((dword & 0x00000100) != 0x00000100){
return -1;
}
proto_tree_add_bits_item(tree, hf_mp4ves_start_code_prefix, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
bit_offset+= 24;
proto_tree_add_bits_item(tree, hf_mp4ves_start_code, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset+= 8;
if(dword != 0x1b0)
return -1;
proto_tree_add_bits_item(tree, hf_mp4ves_profile_and_level_indication, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset+= 8;
dword = tvb_get_bits32(tvb,bit_offset, 32, ENC_BIG_ENDIAN);
bit_offset+= 32;
if ((dword & 0x00000100) != 0x00000100){
return -1;
}
if(dword==0x1b2){
return -1;
}
if(dword==0x1b5){
bit_offset = dissect_mp4ves_VisualObject(tvb, pinfo, tree, bit_offset);
}
return bit_offset;
}
void
dissect_mp4ves_config(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *mp4ves_tree;
item = proto_tree_add_item(tree, hf_mp4ves_config, tvb, 0, -1, ENC_NA);
mp4ves_tree = proto_item_add_subtree(item, ett_mp4ves_config);
dissect_mp4ves_VisualObjectSequence(tvb, pinfo, mp4ves_tree, 0);
}
static void
dissect_mp4ves(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int bit_offset = 0;
proto_item *item;
proto_tree *mp4ves_tree;
guint32 dword;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MP4V-ES");
if (tree) {
item = proto_tree_add_item(tree, proto_mp4ves, tvb, 0, -1, ENC_NA);
mp4ves_tree = proto_item_add_subtree(item, ett_mp4ves);
if (tvb_length(tvb)< 4){
proto_tree_add_text(mp4ves_tree, tvb, bit_offset>>3, -1, "Data");
return;
}
dword = tvb_get_bits32(tvb,bit_offset, 24, ENC_BIG_ENDIAN);
if (dword != 1){
proto_tree_add_text(mp4ves_tree, tvb, bit_offset>>3, -1, "Data");
return;
}
dword = tvb_get_bits8(tvb,24, 8);
bit_offset = bit_offset+8;
switch(dword){
case 0xb6:
proto_tree_add_bits_item(mp4ves_tree, hf_mp4ves_start_code_prefix, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
bit_offset = bit_offset+24;
proto_tree_add_bits_item(mp4ves_tree, hf_mp4ves_vop_coding_type, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
break;
case 0xb0:
dissect_mp4ves_VisualObjectSequence(tvb, pinfo, mp4ves_tree, 0);
break;
default:
proto_tree_add_bits_item(mp4ves_tree, hf_mp4ves_start_code_prefix, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
break;
}
}
}
static int
dissect_mp4ves_par_profile(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
int offset = 0;
guint16 lvl;
const gchar *p = NULL;
asn1_ctx_t *actx;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
lvl = tvb_get_ntohs(tvb, offset);
p = try_val_to_str(lvl, VALS(mp4ves_level_indication_vals));
if (p) {
proto_item_append_text(actx->created_item, " - profileAndLevel %s", p);
}
offset += 2;
return offset;
}
static int
dissect_mp4ves_par_video_object_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
int offset = 0;
guint16 lvl;
const gchar *p = NULL;
asn1_ctx_t *actx;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
lvl = tvb_get_ntohs(tvb, offset);
p = try_val_to_str(lvl, VALS(mp4ves_video_object_type_vals));
if (p) {
proto_item_append_text(actx->created_item, " - video_object_type %s", p);
}
offset += 2;
return offset;
}
static int
dissect_mp4ves_par_decoderConfigurationInformation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
asn1_ctx_t *actx;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
dissect_mp4ves_config(tvb, pinfo, tree);
return tvb_length(tvb);
}
static mp4ves_capability_t *find_cap(const gchar *id) {
mp4ves_capability_t *ftr = NULL;
mp4ves_capability_t *f;
for (f=mp4ves_capability_tab; f->id; f++) {
if (!strcmp(id, f->id)) { ftr = f; break; }
}
return ftr;
}
static int
dissect_mp4ves_name(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree, void* data)
{
asn1_ctx_t *actx;
mp4ves_capability_t *ftr;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
if (tree) {
ftr = find_cap(pinfo->match_string);
if (ftr) {
proto_item_append_text(actx->created_item, " - %s", ftr->name);
proto_item_append_text(proto_item_get_parent(proto_tree_get_parent(tree)), ": %s", ftr->name);
} else {
proto_item_append_text(actx->created_item, " - unknown(%s)", pinfo->match_string);
}
}
return tvb_length(tvb);
}
void
proto_register_mp4ves(void)
{
static hf_register_info hf[] = {
{ &hf_mp4ves_config,
{ "Configuration", "mp4ves.configuration",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_start_code_prefix,
{ "start code prefix", "mp4ves.start_code_prefix",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_start_code,
{ "Start code", "mp4ves.start_code",
FT_UINT8, BASE_RANGE_STRING|BASE_HEX, RVALS(mp4ves_startcode_vals), 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_vop_coding_type,
{ "vop_coding_type", "mp4ves.vop_coding_type",
FT_UINT8, BASE_DEC, VALS(mp4ves_vop_coding_type_vals), 0x0,
"Start code", HFILL }
},
{&hf_mp4ves_profile_and_level_indication,
{ "profile_and_level_indication", "mp4ves.profile_and_level_indication",
FT_UINT8, BASE_DEC,VALS(mp4ves_level_indication_vals), 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_is_visual_object_identifier,
{ "visual_object_identifier", "mp4ves.visual_object_identifier",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_visual_object_type,
{ "visual_object_type", "mp4ves.visual_object_type",
FT_UINT32, BASE_DEC, VALS(mp4ves_visual_object_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_video_signal_type,
{ "video_signal_type", "mp4ves.video_signal_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_stuffing,
{ "Stuffing", "mp4ves.stuffing",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_video_object_type_indication,
{ "video_object_type_indication", "mp4ves.video_object_type_indication",
FT_UINT8, BASE_DEC, VALS(mp4ves_video_object_type_indication_vals), 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_random_accessible_vol,
{ "random_accessible_vol", "mp4ves.random_accessible_vol",
FT_UINT8, BASE_DEC, NULL, 0x0,
"video_object_type_indication", HFILL }
},
{ &hf_mp4ves_is_object_layer_identifier,
{ "is_object_layer_identifier", "mp4ves.is_object_layer_identifier",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_aspect_ratio_info,
{ "aspect_ratio_info", "mp4ves.aspect_ratio_info",
FT_UINT8, BASE_DEC, VALS(mp4ves_aspect_ratio_info_vals), 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_vol_control_parameters,
{ "vol_control_parameters", "mp4ves.vol_control_parameters",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mp4ves_video_object_layer_shape,
{ "video_object_layer_shape", "mp4ves.video_object_layer_shape",
FT_UINT8, BASE_DEC, VALS(mp4ves_video_object_layer_shape_vals), 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_mp4ves,
&ett_mp4ves_config,
};
module_t *mp4ves_module;
proto_mp4ves = proto_register_protocol("MP4V-ES","MP4V-ES", "mp4v-es");
proto_register_field_array(proto_mp4ves, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mp4ves", dissect_mp4ves, proto_mp4ves);
mp4ves_module = prefs_register_protocol(proto_mp4ves, proto_reg_handoff_mp4ves);
prefs_register_uint_preference(mp4ves_module,
"dynamic.payload.type",
"MP4V-ES dynamic payload type",
"The dynamic payload type which will be interpreted as MP4V-ES",
10,
&global_dynamic_payload_type);
}
void
proto_reg_handoff_mp4ves(void)
{
static dissector_handle_t mp4ves_handle;
static guint dynamic_payload_type;
static gboolean mp4ves_prefs_initialized = FALSE;
if (!mp4ves_prefs_initialized) {
dissector_handle_t mp4ves_name_handle;
mp4ves_capability_t *ftr;
mp4ves_handle = find_dissector("mp4ves");
dissector_add_string("rtp_dyn_payload_type","MP4V-ES", mp4ves_handle);
mp4ves_prefs_initialized = TRUE;
mp4ves_name_handle = new_create_dissector_handle(dissect_mp4ves_name, proto_mp4ves);
for (ftr=mp4ves_capability_tab; ftr->id; ftr++) {
if (ftr->name)
dissector_add_string("h245.gef.name", ftr->id, mp4ves_name_handle);
if (ftr->content_pdu)
dissector_add_string("h245.gef.content", ftr->id, new_create_dissector_handle(ftr->content_pdu, proto_mp4ves));
}
}else{
if ( dynamic_payload_type > 95 )
dissector_delete_uint("rtp.pt", dynamic_payload_type, mp4ves_handle);
}
dynamic_payload_type = global_dynamic_payload_type;
if ( dynamic_payload_type > 95 ){
dissector_add_uint("rtp.pt", dynamic_payload_type, mp4ves_handle);
}
}
