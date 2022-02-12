static int
dissect_x224_cr(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, x224_conv_info_t *x224_info _U_)
{
gint len, next_offset;
offset+=2;
proto_tree_add_item(tree, hf_x224_src_ref, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_x224_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if(tvb_length_remaining(tvb, offset) > 0) {
len = tvb_find_line_end(tvb, offset, -1, &next_offset, TRUE);
proto_tree_add_item(tree, hf_x224_rdp_rt, tvb, offset, len,
ENC_ASCII|ENC_NA);
offset = next_offset;
}
return offset;
}
static int
dissect_x224_cc(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, x224_conv_info_t *x224_info)
{
guint8 klass;
proto_tree_add_item(tree, hf_x224_dst_ref, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_x224_src_ref, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
klass = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_x224_class, tvb, offset, 1, ENC_BIG_ENDIAN);
x224_info->klass = klass;
offset+=1;
return offset;
}
static int
dissect_x224_dt(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, x224_conv_info_t *x224_info, proto_tree *parent_tree)
{
proto_item *item = NULL;
tvbuff_t *next_tvb;
switch (x224_info->klass >>4) {
case 2:
case 3:
case 4:
proto_tree_add_item(tree, hf_x224_dst_ref, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
}
item = proto_tree_add_uint(tree, hf_x224_class, tvb, 0, 0, x224_info->klass);
PROTO_ITEM_SET_GENERATED(item);
proto_tree_add_item(tree, hf_x224_eot, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_x224_nr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(t125_handle, next_tvb, pinfo, parent_tree);
return offset;
}
static int
dissect_x224(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_tree *tree = NULL;
proto_item *item = NULL;
int offset = 0 ;
guint8 code, length;
conversation_t *conversation;
x224_conv_info_t *x224_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X.224");
col_clear(pinfo->cinfo, COL_INFO);
length = tvb_get_guint8(tvb, offset);
if (parent_tree) {
item = proto_tree_add_item(parent_tree, proto_x224, tvb, offset, length+1, ENC_NA);
tree = proto_item_add_subtree(item, ett_x224);
}
proto_tree_add_item(tree, hf_x224_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_x224_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (0x%02x)",
val_to_str(code>>4, code_vals, "Unknown code :%x"),
code);
}
conversation = find_or_create_conversation(pinfo);
x224_info = (x224_conv_info_t *)conversation_get_proto_data(conversation, proto_x224);
if (!x224_info) {
x224_info = se_new(x224_conv_info_t);
x224_info->klass=0;
conversation_add_proto_data(conversation, proto_x224, x224_info);
}
switch (code>>4) {
case X224_CODE_CR:
offset = dissect_x224_cr(pinfo, tree, tvb, offset, x224_info);
break;
case X224_CODE_CC:
offset = dissect_x224_cc(pinfo, tree, tvb, offset, x224_info);
break;
case X224_CODE_DR:
break;
case X224_CODE_DC:
break;
case X224_CODE_DT:
offset = dissect_x224_dt(pinfo, tree, tvb, offset, x224_info, parent_tree);
break;
case X224_CODE_ED:
break;
case X224_CODE_AK:
break;
case X224_CODE_EA:
break;
case X224_CODE_RJ:
break;
case X224_CODE_ER:
break;
}
return offset;
}
void
proto_register_x224(void)
{
static hf_register_info hf[] =
{
{ &hf_x224_length, {
"Length", "x224.length", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_x224_code, {
"Code", "x224.code", FT_UINT8, BASE_HEX,
VALS(code_vals), 0xf0, NULL, HFILL }},
{ &hf_x224_src_ref, {
"SRC-REF", "x224.src_ref", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_x224_dst_ref, {
"DST-REF", "x224.dst_ref", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_x224_class, {
"Class", "x224.class", FT_UINT8, BASE_HEX,
VALS(class_option_vals), 0xf0, NULL, HFILL }},
{ &hf_x224_rdp_rt, {
"RDP Routing Token", "x224.rdp_rt", FT_STRING, BASE_NONE, NULL, 0,
"Used for Remote Desktop Protocol (RDP) load balancing", HFILL }},
{ &hf_x224_nr, {
"NR", "x224.nr", FT_UINT8, BASE_HEX,
NULL, 0x7f, NULL, HFILL }},
{ &hf_x224_eot, {
"EOT", "x224.eot", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL }},
};
static gint *ett[] =
{
&ett_x224,
};
proto_x224 = proto_register_protocol("ITU-T Rec X.224", "X.224", "x224");
proto_register_field_array(proto_x224, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("x224", dissect_x224, proto_x224);
}
void
proto_reg_handoff_x224(void)
{
t125_handle = find_dissector("t125");
}
