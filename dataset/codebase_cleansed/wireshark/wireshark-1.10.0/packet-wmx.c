proto_tree *add_tlv_subtree(tlv_info_t *self, gint idx, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length _U_, gboolean little_endian)
{
proto_tree *tlv_tree;
proto_item *tlv_item;
guint start_of_tlv;
gint tlv_value_length, tlv_val_offset;
guint8 size_of_tlv_length_field;
guint8 tlv_type;
guint32 tlv_value;
const gchar *hex_fmt;
tlv_val_offset = get_tlv_value_offset(self);
start_of_tlv = start - tlv_val_offset;
tlv_value_length = get_tlv_length(self);
size_of_tlv_length_field = get_tlv_size_of_length(self);
tlv_type = get_tlv_type(self);
if (get_tlv_type(self) < 0)
return tree;
tlv_item = proto_tree_add_item(tree, hfindex, tvb, start, tlv_value_length, little_endian);
if (!PITEM_FINFO(tlv_item))
return tree;
PITEM_FINFO(tlv_item)->start -= tlv_val_offset;
PITEM_FINFO(tlv_item)->length += tlv_val_offset;
tlv_tree = proto_item_add_subtree(tlv_item, *ett_tlv[tlv_type]);
proto_tree_add_text(tlv_tree, tvb, start_of_tlv, 1, "TLV type: %u", tlv_type);
if (size_of_tlv_length_field > 0)
{
proto_tree_add_text(tlv_tree, tvb, start_of_tlv+1, 1, "Size of TLV length field: %u", size_of_tlv_length_field);
proto_tree_add_text(tlv_tree, tvb, start_of_tlv+2, size_of_tlv_length_field, "TLV length: %u", tlv_value_length);
} else {
proto_tree_add_text(tlv_tree, tvb, start_of_tlv+1, 1, "TLV length: %u", tlv_value_length);
}
switch (tlv_value_length)
{
case 1:
tlv_value = tvb_get_guint8(tvb, start);
hex_fmt = tlv_val_1byte;
break;
case 2:
tlv_value = tvb_get_ntohs(tvb, start);
hex_fmt = tlv_val_2byte;
break;
case 3:
tlv_value = tvb_get_ntoh24(tvb, start);
hex_fmt = tlv_val_3byte;
break;
case 4:
tlv_value = tvb_get_ntohl(tvb, start);
hex_fmt = tlv_val_4byte;
break;
default:
tlv_value = tvb_get_ntohl(tvb, start);
hex_fmt = tlv_val_5byte;
break;
}
tlv_item = proto_tree_add_text(tlv_tree, tvb, start, tlv_value_length, hex_fmt, PITEM_FINFO(tlv_item)->hfinfo->name, tlv_value);
tlv_tree = proto_item_add_subtree(tlv_item, idx);
return tlv_tree;
}
proto_tree *add_protocol_subtree(tlv_info_t *self, gint idx, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const char *format, ...)
{
proto_tree *tlv_tree;
proto_item *tlv_item;
guint start_of_tlv;
gint tlv_value_length, tlv_val_offset;
guint8 size_of_tlv_length_field;
guint8 tlv_type;
guint32 tlv_value;
va_list ap;
gchar *message = NULL;
const gchar *hex_fmt;
if (get_tlv_type(self) < 0)
return tree;
tlv_val_offset = get_tlv_value_offset(self);
start_of_tlv = start - tlv_val_offset;
tlv_value_length = get_tlv_length(self);
size_of_tlv_length_field = get_tlv_size_of_length(self);
tlv_type = get_tlv_type(self);
va_start(ap, format);
message = se_strdup_vprintf(format, ap);
va_end(ap);
tlv_item = proto_tree_add_protocol_format(tree, hfindex, tvb, start, length, "%s", message);
if (!PITEM_FINFO(tlv_item))
return tree;
PITEM_FINFO(tlv_item)->start -= tlv_val_offset;
PITEM_FINFO(tlv_item)->length += tlv_val_offset;
tlv_tree = proto_item_add_subtree(tlv_item, *ett_tlv[tlv_type]);
proto_tree_add_text(tlv_tree, tvb, start_of_tlv, 1, "TLV type: %u", tlv_type);
if (size_of_tlv_length_field > 0)
{
proto_tree_add_text(tlv_tree, tvb, start_of_tlv+1, 1, "Size of TLV length field: %u", size_of_tlv_length_field);
proto_tree_add_text(tlv_tree, tvb, start_of_tlv+2, size_of_tlv_length_field, "TLV length: %u", tlv_value_length);
} else {
proto_tree_add_text(tlv_tree, tvb, start_of_tlv+1, 1, "TLV length: %u", tlv_value_length);
}
switch (tlv_value_length)
{
case 1:
tlv_value = tvb_get_guint8(tvb, start);
hex_fmt = tlv_val_1byte;
break;
case 2:
tlv_value = tvb_get_ntohs(tvb, start);
hex_fmt = tlv_val_2byte;
break;
case 3:
tlv_value = tvb_get_ntoh24(tvb, start);
hex_fmt = tlv_val_3byte;
break;
case 4:
tlv_value = tvb_get_ntohl(tvb, start);
hex_fmt = tlv_val_4byte;
break;
default:
tlv_value = tvb_get_ntohl(tvb, start);
hex_fmt = tlv_val_5byte;
break;
}
tlv_item = proto_tree_add_text(tlv_tree, tvb, start, length, hex_fmt, message, tlv_value);
tlv_tree = proto_item_add_subtree(tlv_item, idx);
return tlv_tree;
}
static void dissect_wimax(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WiMax");
col_clear(pinfo->cinfo, COL_INFO);
}
gboolean is_down_link(packet_info *pinfo)
{
if (pinfo->p2p_dir == P2P_DIR_RECV)
return TRUE;
if (pinfo->p2p_dir == P2P_DIR_UNKNOWN)
if(bs_address.len && !CMP_ADDRESS(&bs_address, &pinfo->src))
return TRUE;
return FALSE;
}
void proto_register_wimax(void)
{
#if 0
static gint *ett[] =
{
&ett_wimax,
&ett_wimax_tlv,
&ett_wimax_fch,
&ett_wimax_cdma,
&ett_wimax_ffb,
};
#endif
module_t *wimax_module;
proto_wimax = proto_register_protocol (
"WiMax Protocol",
"WiMax (wmx)",
"wmx"
);
#if 0
proto_register_subtree_array(ett, array_length(ett));
#endif
register_dissector("wmx", dissect_wimax, proto_wimax);
proto_register_wimax_cdma();
proto_register_wimax_fch();
proto_register_wimax_pdu();
proto_register_wimax_ffb();
proto_register_wimax_hack();
proto_register_wimax_harq_map();
proto_register_wimax_phy_attributes();
proto_register_wimax_compact_dlmap_ie();
proto_register_wimax_compact_ulmap_ie();
#if 0
wimax_module = prefs_register_protocol(proto_wimax, proto_reg_handoff_wimax);
#endif
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
#if 0
register_dissector_table("wimax.max_basic_cid", "Max Basic CID", FT_UINT16, BASE_DEC);
register_dissector_table("wimax.corrigendum_2_version", "Corrigendum 2 Version", FT_UINT16, BASE_DEC);
#endif
proto_register_subtree_array(ett_tlv, array_length(ett_tlv));
}
void
proto_reg_handoff_wimax(void)
{
#if 0
static int wimax_prefs_initialized = FALSE;
static dissector_handle_t wimax_handle;
if(!wimax_prefs_initialized)
{
wimax_handle = create_dissector_handle(dissect_wimax, proto_wimax);
wimax_prefs_initialized = TRUE;
} else {
dissector_delete_uint("wimax.max_basic_cid", global_cid_max_basic, wimax_handle);
dissector_delete_uint("wimax.corrigendum_2_version", include_cor2_changes, wimax_handle);
}
dissector_add_uint("wimax.max_basic_cid", global_cid_max_basic, wimax_handle);
dissector_add_uint("wimax.corrigendum_2_version", include_cor2_changes, wimax_handle);
#endif
}
