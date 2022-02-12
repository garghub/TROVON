gboolean
sub_check_hdmi(packet_info *pinfo _U_)
{
return TRUE;
}
static gint
dissect_hdmi_edid(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *yi;
proto_tree *edid_tree;
guint64 edid_hdr;
guint16 manf_id;
gchar manf_id_str[4];
guint8 week, year;
int year_hf;
guint8 edid_ver, edid_rev;
ti = proto_tree_add_text(tree, tvb,
offset, tvb_reported_length_remaining(tvb, offset),
"Extended Display Identification Data (EDID)");
edid_tree = proto_item_add_subtree(ti, ett_hdmi_edid);
edid_hdr = tvb_get_ntoh64(tvb, offset);
if (edid_hdr != EDID_HDR_VALUE)
return offset;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "EDID");
proto_tree_add_item(edid_tree, hf_hdmi_edid_hdr,
tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
manf_id = tvb_get_ntohs(tvb, offset);
manf_id_str[0] = CAPITAL_LETTER(manf_id, 10);
manf_id_str[1] = CAPITAL_LETTER(manf_id, 5);
manf_id_str[2] = CAPITAL_LETTER(manf_id, 0);
manf_id_str[3] = 0;
proto_tree_add_string(edid_tree, hf_hdmi_edid_manf_id,
tvb, offset, 2, manf_id_str);
offset += 2;
proto_tree_add_item(edid_tree, hf_hdmi_edid_manf_prod_code,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(edid_tree, hf_hdmi_edid_manf_serial,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
week = tvb_get_guint8(tvb, offset);
proto_tree_add_item(edid_tree, hf_hdmi_edid_manf_week,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
year_hf = week==255 ? hf_hdmi_edid_mod_year : hf_hdmi_edid_manf_year;
year = tvb_get_guint8(tvb, offset);
yi = proto_tree_add_item(edid_tree, year_hf,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(yi, " (year %d)", 1990+year);
offset++;
edid_ver = tvb_get_guint8(tvb, offset);
edid_rev = tvb_get_guint8(tvb, offset+1);
proto_tree_add_text(edid_tree, tvb, offset, 2,
"EDID Version %d.%d", edid_ver, edid_rev);
return tvb_reported_length(tvb);
}
static int
dissect_hdmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 addr;
gint offset=0;
proto_item *pi;
proto_tree *hdmi_tree;
addr = tvb_get_guint8(tvb, 0);
if (!try_val_to_str(addr, hdmi_addr))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HDMI");
col_clear(pinfo->cinfo, COL_INFO);
pi = proto_tree_add_protocol_format(tree, proto_hdmi,
tvb, 0, tvb_reported_length(tvb), "HDMI");
hdmi_tree = proto_item_add_subtree(pi, ett_hdmi);
if (addr&0x01) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(ADDR_RCV)+1, ADDR_RCV);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(ADDR_TRX)+1, ADDR_TRX);
pinfo->p2p_dir = P2P_DIR_RECV;
}
else {
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(ADDR_TRX)+1, ADDR_TRX);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(ADDR_RCV)+1, ADDR_RCV);
pinfo->p2p_dir = P2P_DIR_SENT;
}
proto_tree_add_item(hdmi_tree, hf_hdmi_addr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (HDCP_ADDR8(addr)) {
gint hdcp_len;
tvbuff_t *hdcp_tvb;
hdcp_len = tvb_reported_length_remaining(tvb, offset);
hdcp_tvb = tvb_new_subset(tvb, offset, hdcp_len, hdcp_len);
return call_dissector(hdcp_handle, hdcp_tvb, pinfo, hdmi_tree);
}
if (addr==ADDR8_EDID_WRITE) {
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "EDID request");
proto_tree_add_item(hdmi_tree, hf_hdmi_edid_offset,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
return dissect_hdmi_edid(tvb, offset, pinfo, hdmi_tree);
}
void
proto_register_hdmi(void)
{
static hf_register_info hf[] = {
{ &hf_hdmi_addr,
{ "8bit I2C address", "hdmi.addr", FT_UINT8, BASE_HEX,
VALS(hdmi_addr), 0, NULL, HFILL } },
{ &hf_hdmi_edid_offset,
{ "Offset", "hdmi.edid.offset",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_hdr,
{ "EDID header", "hdmi.edid.hdr",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_manf_id,
{ "Manufacturer ID", "hdmi.edid.manf_id",
FT_STRING, STR_ASCII, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_manf_prod_code,
{ "Manufacturer product code", "hdmi.edid.manf_prod_code",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_manf_serial,
{ "Serial number", "hdmi.edid.serial_num",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_manf_week,
{ "Week of manufacture", "hdmi.edid.manf_week",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_mod_year,
{ "Model year", "hdmi.edid.model_year",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_hdmi_edid_manf_year,
{ "Year of manufacture", "hdmi.edid.manf_year",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_hdmi,
&ett_hdmi_edid
};
proto_hdmi = proto_register_protocol(
"High-Definition Multimedia Interface", "HDMI", "hdmi");
proto_register_field_array(proto_hdmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("hdmi", dissect_hdmi, proto_hdmi);
}
void
proto_reg_handoff_hdmi(void)
{
hdcp_handle = find_dissector("hdcp");
}
