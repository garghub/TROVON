static int
dissect_mpls_y1711(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
struct mplsinfo *mplsinfo = (struct mplsinfo *)pinfo->private_data;
int offset = 0;
proto_item *ti;
proto_tree *mpls_y1711_tree;
int functype;
tvbuff_t *data_tvb;
static const guint8 allone[] = { 0xff, 0xff };
static const guint8 allzero[] = { 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00 };
functype = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (Y.1711: %s)",
(functype == 0x01) ? "CV" :
(functype == 0x02) ? "FDI" :
(functype == 0x03) ? "BDI" :
(functype == 0x07) ? "FDD" :
"reserved/unknown");
}
if (tvb_reported_length(tvb) < 44) {
proto_tree_add_text(tree, tvb, offset, -1,
"Error: must have a minimum payload "
"length of 44 bytes");
data_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, data_tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
if (!tree)
return tvb_reported_length(tvb);
ti = proto_tree_add_text(tree, tvb, offset, 44, "Y.1711 OAM");
mpls_y1711_tree = proto_item_add_subtree(ti, ett_mpls_y1711);
if (mplsinfo->label != MPLS_LABEL_OAM_ALERT)
proto_tree_add_text(mpls_y1711_tree, tvb, offset - 4, 3,
"Warning: Y.1711 but no OAM alert label (%d) ?!",
MPLS_LABEL_OAM_ALERT);
if (mplsinfo->exp != 0)
proto_tree_add_text(mpls_y1711_tree, tvb, offset - 2, 1,
"Warning: Exp bits should be 0 for Y.1711");
if (mplsinfo->bos != 1)
proto_tree_add_text(mpls_y1711_tree, tvb, offset - 2, 1,
"Warning: S bit should be 1 for Y.1711");
if (mplsinfo->ttl != 1)
proto_tree_add_text(mpls_y1711_tree, tvb, offset - 1, 1,
"Warning: TTL should be 1 for Y.1711");
functype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mpls_y1711_tree, hf_mpls_y1711_function_type, tvb,
offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
switch (functype) {
case 0x01:
{
guint32 lsrid_ipv4addr;
if (tvb_memeql(tvb, offset, allzero, 3) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 3,
"Error: these bytes are reserved and "
"must be 0x00");
}
offset += 3;
if (tvb_memeql(tvb, offset, allzero, 10) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 10,
"Error: these bytes are padding "
"and must be 0x00");
}
offset += 10;
if (tvb_memeql(tvb, offset, allone, 2) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 2,
"Error: these bytes are padding "
"and must be 0xFF");
}
offset += 2;
lsrid_ipv4addr = tvb_get_ipv4(tvb, offset);
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 4, "LSR ID: %s",
ip_to_str((guint8 *) &lsrid_ipv4addr));
offset += 4;
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 4, "LSP ID: %d",
tvb_get_ntohl(tvb, offset));
offset += 4;
if (tvb_memeql(tvb, offset, allzero, 18) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 18,
"Error: these bytes are padding "
"and must be 0x00");
}
offset += 18;
}
break;
case 0x02:
case 0x03:
{
guint32 lsrid_ipv4addr;
if (tvb_memeql(tvb, offset, allzero, 1) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 3,
"Error: this byte is reserved "
"and must be 0x00");
}
offset++;
proto_tree_add_item(mpls_y1711_tree, hf_mpls_y1711_defect_type, tvb,
offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
if (tvb_memeql(tvb, offset, allzero, 20) == 0) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 20,
"TTSI not preset (optional for FDI/BDI)");
offset += 20;
} else {
if (tvb_memeql(tvb, offset, allzero, 10) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 10,
"Error: these bytes are padding and "
"must be 0x00");
}
offset += 10;
if (tvb_memeql(tvb, offset, allone, 2) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 2,
"Error: these bytes are padding and "
"must be 0xFF");
}
offset += 2;
lsrid_ipv4addr = tvb_get_ipv4(tvb, offset);
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 4, "LSR ID: %s",
ip_to_str((guint8 *) &lsrid_ipv4addr));
offset += 4;
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 4, "LSP ID: %d",
tvb_get_ntohl(tvb, offset));
offset += 4;
}
proto_tree_add_item(mpls_y1711_tree, hf_mpls_y1711_defect_location, tvb,
offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
if (tvb_memeql(tvb, offset, allzero, 14) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 14,
"Error: these bytes are padding "
"and must be 0x00");
}
offset += 14;
}
break;
case 0x07:
{
guint32 lsrid_ipv4addr;
if (tvb_memeql(tvb, offset, allzero, 3) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 3,
"Error: these bytes are "
"reserved and must be 0x00");
}
offset += 3;
if (tvb_memeql(tvb, offset, allzero, 10) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 10,
"Error: these bytes are padding and "
"must be 0x00");
}
offset += 10;
if (tvb_memeql(tvb, offset, allone, 2) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 2,
"Error: these bytes are padding and "
"must be 0xFF");
}
offset += 2;
lsrid_ipv4addr = tvb_get_ipv4(tvb, offset);
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 4, "LSR ID: %s",
ip_to_str((guint8 *)&lsrid_ipv4addr));
offset += 4;
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 4, "LSP ID: %d",
tvb_get_ntohl(tvb,offset));
offset += 4;
proto_tree_add_item(mpls_y1711_tree, hf_mpls_y1711_frequency, tvb,
offset, 1,
ENC_LITTLE_ENDIAN);
offset++;
if (tvb_memeql(tvb, offset, allzero, 17) == -1) {
proto_tree_add_text(mpls_y1711_tree, tvb, offset, 17,
"Error: these bytes are padding and "
"must be 0x00");
}
offset += 17;
}
break;
default:
proto_tree_add_text(mpls_y1711_tree, tvb, offset - 1, -1,
"Unknown MPLS Y.1711 PDU");
return offset;
}
proto_tree_add_item(mpls_y1711_tree, hf_mpls_y1711_bip16, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
void
proto_register_mpls_y1711(void)
{
static hf_register_info hf[] = {
{
&hf_mpls_y1711_function_type,
{
"Function Type", "mpls_y1711.function_type", FT_UINT8,
BASE_HEX, VALS(y1711_function_type_vals),
0x0, "Function Type codepoint", HFILL
}
},
#if 0
{
&hf_mpls_y1711_ttsi,
{
"Trail Termination Source Identifier",
"mpls_y1711.ttsi",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
#endif
{
&hf_mpls_y1711_frequency,
{
"Frequency", "mpls_y1711.frequency", FT_UINT8,
BASE_HEX, VALS(y1711_frequency_vals), 0x0,
"Frequency of probe injection", HFILL
}
},
{
&hf_mpls_y1711_defect_type,
{
"Defect Type", "mpls_y1711.defect_type", FT_UINT16,
BASE_HEX, VALS(y1711_defect_type_vals), 0x0, NULL, HFILL
}
},
{
&hf_mpls_y1711_defect_location,
{
"Defect Location (AS)", "mpls_y1711.defect_location",
FT_UINT32, BASE_DEC, NULL, 0x0, "Defect Location", HFILL
}
},
{
&hf_mpls_y1711_bip16,
{
"BIP16", "mpls_y1711.bip16", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_mpls_y1711
};
proto_mpls_y1711 =
proto_register_protocol("MPLS ITU-T Y.1711 OAM",
"MPLS ITU-T Y.1711 OAM",
"mpls_y1711");
proto_register_field_array(proto_mpls_y1711, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("mpls_y1711", dissect_mpls_y1711, proto_mpls_y1711);
}
void
proto_reg_handoff_mpls_y1711(void)
{
mpls_y1711_handle = find_dissector("mpls_y1711");
dissector_add_uint("mpls.label",
MPLS_LABEL_OAM_ALERT ,
mpls_y1711_handle);
data_handle = find_dissector("data");
}
