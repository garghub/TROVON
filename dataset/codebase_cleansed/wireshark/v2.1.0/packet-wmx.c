proto_item *add_tlv_subtree(tlv_info_t *self, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, const guint encoding)
{
header_field_info *hf;
proto_tree *tlv_tree;
proto_item *tlv_item;
gint tlv_value_length, tlv_val_offset;
guint8 size_of_tlv_length_field;
guint8 tlv_type;
if (get_tlv_type(self) < 0)
return tree;
tlv_val_offset = get_tlv_value_offset(self);
tlv_value_length = get_tlv_length(self);
size_of_tlv_length_field = get_tlv_size_of_length(self);
tlv_type = get_tlv_type(self);
hf = proto_registrar_get_nth(hfindex);
tlv_tree = proto_tree_add_subtree(tree, tvb, start, tlv_value_length+tlv_val_offset, ett_tlv[tlv_type], NULL, hf->name);
proto_tree_add_uint(tlv_tree, hf_tlv_type, tvb, start, 1, tlv_type);
if (size_of_tlv_length_field > 0)
{
proto_tree_add_uint(tlv_tree, hf_tlv_length_size, tvb, start+1, 1, size_of_tlv_length_field);
proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+2, size_of_tlv_length_field, tlv_value_length);
} else {
proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+1, 1, tlv_value_length);
}
tlv_item = proto_tree_add_item(tlv_tree, hfindex, tvb, start+tlv_val_offset, tlv_value_length, encoding);
return tlv_item;
}
proto_tree *add_tlv_subtree_no_item(tlv_info_t *self, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start)
{
header_field_info *hf;
proto_tree *tlv_tree;
gint tlv_value_length, tlv_val_offset;
guint8 size_of_tlv_length_field;
guint8 tlv_type;
if (get_tlv_type(self) < 0)
return tree;
tlv_val_offset = get_tlv_value_offset(self);
tlv_value_length = get_tlv_length(self);
size_of_tlv_length_field = get_tlv_size_of_length(self);
tlv_type = get_tlv_type(self);
hf = proto_registrar_get_nth(hfindex);
tlv_tree = proto_tree_add_subtree(tree, tvb, start, tlv_value_length+tlv_val_offset, ett_tlv[tlv_type], NULL, hf->name);
proto_tree_add_uint(tlv_tree, hf_tlv_type, tvb, start, 1, tlv_type);
if (size_of_tlv_length_field > 0)
{
proto_tree_add_uint(tlv_tree, hf_tlv_length_size, tvb, start+1, 1, size_of_tlv_length_field);
proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+2, size_of_tlv_length_field, tlv_value_length);
} else {
proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+1, 1, tlv_value_length);
}
return tlv_tree;
}
proto_tree *add_protocol_subtree(tlv_info_t *self, gint idx, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length _U_, const char *label)
{
proto_tree *tlv_tree;
proto_item *tlv_item;
gint tlv_value_length, tlv_val_offset;
guint8 size_of_tlv_length_field;
guint8 tlv_type;
guint32 tlv_value;
const gchar *hex_fmt;
if (get_tlv_type(self) < 0)
return tree;
tlv_val_offset = get_tlv_value_offset(self);
tlv_value_length = get_tlv_length(self);
size_of_tlv_length_field = get_tlv_size_of_length(self);
tlv_type = get_tlv_type(self);
tlv_item = proto_tree_add_protocol_format(tree, hfindex, tvb, start, tlv_value_length+tlv_val_offset, "%s (%u byte(s))", label, tlv_value_length);
tlv_tree = proto_item_add_subtree(tlv_item, ett_tlv[tlv_type]);
proto_tree_add_uint(tlv_tree, hf_tlv_type, tvb, start, 1, tlv_type);
if (size_of_tlv_length_field > 0)
{
proto_tree_add_uint(tlv_tree, hf_tlv_length_size, tvb, start+1, 1, size_of_tlv_length_field);
proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+2, size_of_tlv_length_field, tlv_value_length);
} else {
proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+1, 1, tlv_value_length);
}
switch (tlv_value_length)
{
case 1:
tlv_value = tvb_get_guint8(tvb, start+tlv_val_offset);
hex_fmt = tlv_val_1byte;
break;
case 2:
tlv_value = tvb_get_ntohs(tvb, start+tlv_val_offset);
hex_fmt = tlv_val_2byte;
break;
case 3:
tlv_value = tvb_get_ntoh24(tvb, start+tlv_val_offset);
hex_fmt = tlv_val_3byte;
break;
case 4:
tlv_value = tvb_get_ntohl(tvb, start+tlv_val_offset);
hex_fmt = tlv_val_4byte;
break;
default:
tlv_value = tvb_get_ntohl(tvb, start+tlv_val_offset);
hex_fmt = tlv_val_5byte;
break;
}
tlv_tree = proto_tree_add_subtree_format(tlv_tree, tvb, start+tlv_val_offset, tlv_value_length, idx, NULL, hex_fmt, label, tlv_value);
return tlv_tree;
}
static int dissect_wimax(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WiMax");
col_clear(pinfo->cinfo, COL_INFO);
return tvb_captured_length(tvb);
}
gboolean is_down_link(packet_info *pinfo)
{
if (pinfo->p2p_dir == P2P_DIR_RECV)
return TRUE;
if (pinfo->p2p_dir == P2P_DIR_UNKNOWN)
if(bs_address.len && !cmp_address(&bs_address, &pinfo->src))
return TRUE;
return FALSE;
}
void proto_register_wimax(void)
{
int i;
module_t *wimax_module;
static hf_register_info hf[] = {
{ &hf_tlv_type, { "TLV type", "wmx.tlv_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tlv_length, { "TLV length", "wmx.tlv_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_tlv_length_size, { "Size of TLV length field", "wmx.tlv_length_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
gint *ett_reg[MAX_NUM_TLVS];
proto_wimax = proto_register_protocol (
"WiMax Protocol",
"WiMax (wmx)",
"wmx"
);
proto_register_field_array(proto_wimax, hf, array_length(hf));
for (i = 0; i < MAX_NUM_TLVS; i++)
{
ett_tlv[i] = -1;
ett_reg[i] = &ett_tlv[i];
}
proto_register_subtree_array(ett_reg, array_length(ett_reg));
register_dissector("wmx", dissect_wimax, proto_wimax);
wimax_module = prefs_register_protocol(proto_wimax, NULL);
prefs_register_uint_preference(wimax_module, "basic_cid_max",
"Maximum Basic CID",
"Set the maximum Basic CID"
" used in the Wimax decoder"
" (if other than the default of 320)."
" Note: The maximum Primary CID is"
" double the maximum Basic CID.",
10, &global_cid_max_basic);
prefs_register_bool_preference(wimax_module, "corrigendum_2_version",
"Corrigendum 2 Version",
"Set to TRUE to use the Corrigendum"
" 2 version of Wimax message decoding."
" Set to FALSE to use the 802.16e-2005"
" version.",
&include_cor2_changes);
prefs_register_obsolete_preference(wimax_module, "wimax.basic_cid_max");
prefs_register_obsolete_preference(wimax_module, "wimax.corrigendum_2_version");
}
