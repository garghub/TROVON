static int arcnet_str_len(const address* addr _U_)
{
return 5;
}
static int arcnet_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
*buf++ = '0';
*buf++ = 'x';
buf = bytes_to_hexstr(buf, (const guint8 *)addr->data, 1);
*buf = '\0';
return arcnet_str_len(addr);
}
static const char* arcnet_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "arcnet.src";
return "arcnet.dst";
}
static int arcnet_len(void)
{
return 1;
}
void
capture_arcnet (const guchar *pd, int len, packet_counts *ld,
gboolean has_offset, gboolean has_exception)
{
int offset = has_offset ? 4 : 2;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
switch (pd[offset]) {
case ARCNET_PROTO_IP_1051:
capture_ip(pd, offset + 1, len, ld);
break;
case ARCNET_PROTO_IP_1201:
offset++;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
if (has_exception && pd[offset] == 0xff) {
offset += 4;
}
capture_ip(pd, offset + 3, len, ld);
break;
case ARCNET_PROTO_ARP_1051:
case ARCNET_PROTO_ARP_1201:
ld->arp++;
break;
case ARCNET_PROTO_IPX:
ld->ipx++;
break;
default:
ld->other++;
break;
}
}
static void
dissect_arcnet_common (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
gboolean has_offset, gboolean has_exception)
{
int offset = 0;
guint8 dst, src, protID, split_flag;
tvbuff_t *next_tvb;
proto_item *ti;
proto_tree *arcnet_tree;
col_set_str (pinfo->cinfo, COL_PROTOCOL, "ARCNET");
col_set_str(pinfo->cinfo, COL_INFO, "ARCNET");
src = tvb_get_guint8 (tvb, 0);
dst = tvb_get_guint8 (tvb, 1);
TVB_SET_ADDRESS(&pinfo->dl_src, arcnet_address_type, tvb, 0, 1);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->dl_src);
TVB_SET_ADDRESS(&pinfo->dl_dst, arcnet_address_type, tvb, 1, 1);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->dl_dst);
ti = proto_tree_add_item (tree, proto_arcnet, tvb, 0, -1, ENC_NA);
arcnet_tree = proto_item_add_subtree (ti, ett_arcnet);
proto_tree_add_uint (arcnet_tree, hf_arcnet_src, tvb, offset, 1, src);
offset++;
proto_tree_add_uint (arcnet_tree, hf_arcnet_dst, tvb, offset, 1, dst);
offset++;
if (has_offset) {
proto_tree_add_item (arcnet_tree, hf_arcnet_offset, tvb, offset, 2, ENC_NA);
offset += 2;
}
protID = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint (arcnet_tree, hf_arcnet_protID, tvb, offset, 1, protID);
offset++;
switch (protID) {
case ARCNET_PROTO_IP_1051:
case ARCNET_PROTO_ARP_1051:
case ARCNET_PROTO_DIAGNOSE:
case ARCNET_PROTO_BACNET:
break;
default:
split_flag = tvb_get_guint8 (tvb, offset);
if (has_exception && split_flag == 0xff) {
proto_tree_add_uint (arcnet_tree, hf_arcnet_exception_flag, tvb, offset, 1,
split_flag);
offset++;
proto_tree_add_item(arcnet_tree, hf_arcnet_padding, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item (arcnet_tree, hf_arcnet_protID, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
split_flag = tvb_get_guint8 (tvb, offset);
}
proto_tree_add_uint (arcnet_tree, hf_arcnet_split_flag, tvb, offset, 1,
split_flag);
offset++;
proto_tree_add_item (arcnet_tree, hf_arcnet_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
proto_item_set_len(ti, offset);
next_tvb = tvb_new_subset_remaining (tvb, offset);
if (!dissector_try_uint (arcnet_dissector_table, protID,
next_tvb, pinfo, tree))
{
col_add_fstr (pinfo->cinfo, COL_PROTOCOL, "0x%04x", protID);
call_dissector (data_handle, next_tvb, pinfo, tree);
}
}
static void
dissect_arcnet (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_arcnet_common (tvb, pinfo, tree, FALSE, TRUE);
}
static void
dissect_arcnet_linux (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
dissect_arcnet_common (tvb, pinfo, tree, TRUE, FALSE);
}
void
proto_register_arcnet (void)
{
static hf_register_info hf[] = {
{&hf_arcnet_src,
{"Source", "arcnet.src",
FT_UINT8, BASE_HEX, NULL, 0,
"Source ID", HFILL}
},
{&hf_arcnet_dst,
{"Dest", "arcnet.dst",
FT_UINT8, BASE_HEX, NULL, 0,
"Dest ID", HFILL}
},
{&hf_arcnet_offset,
{"Offset", "arcnet.offset",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{&hf_arcnet_protID,
{"Protocol ID", "arcnet.protID",
FT_UINT8, BASE_HEX, VALS(arcnet_prot_id_vals), 0,
"Proto type", HFILL}
},
{&hf_arcnet_split_flag,
{"Split Flag", "arcnet.split_flag",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{&hf_arcnet_exception_flag,
{"Exception Flag", "arcnet.exception_flag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_arcnet_sequence,
{"Sequence", "arcnet.sequence",
FT_UINT16, BASE_DEC, NULL, 0,
"Sequence number", HFILL}
},
{&hf_arcnet_padding,
{"Padding", "arcnet.padding",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_arcnet,
};
arcnet_dissector_table = register_dissector_table ("arcnet.protocol_id",
"ARCNET Protocol ID",
FT_UINT8, BASE_HEX);
proto_arcnet = proto_register_protocol ("ARCNET", "ARCNET", "arcnet");
proto_register_field_array (proto_arcnet, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
arcnet_address_type = address_type_dissector_register("AT_ARCNET", "ARCNET Address", arcnet_to_str, arcnet_str_len, arcnet_col_filter_str, arcnet_len, NULL, NULL);
}
void
proto_reg_handoff_arcnet (void)
{
dissector_handle_t arcnet_handle, arcnet_linux_handle;
arcnet_handle = create_dissector_handle (dissect_arcnet, proto_arcnet);
dissector_add_uint ("wtap_encap", WTAP_ENCAP_ARCNET, arcnet_handle);
arcnet_linux_handle = create_dissector_handle (dissect_arcnet_linux,
proto_arcnet);
dissector_add_uint ("wtap_encap", WTAP_ENCAP_ARCNET_LINUX, arcnet_linux_handle);
data_handle = find_dissector ("data");
}
