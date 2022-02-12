static int wme_getpsidlen (guint8 *psid)
{
int length = 0;
if ((psid[0] & 0xF0) == 0xF0) {
length = 255;
} else if ( (psid[0] & 0xE0) == 0xE0) {
length = 4;
} else if ( (psid[0] & 0xE0) == 0xC0) {
length = 3;
} else if ( (psid[0] & 0xC0) == 0x80) {
length = 2;
} else if ((psid[0] & 0x80) == 0x00) {
length = 1;
}
return length;
}
static void
dissect_wsmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *wsmp_tree, *wsmdata_tree;
tvbuff_t *wsmdata_tvb;
guint16 wsmlength, offset;
guint32 psidLen, psid, supLen;
guint8 elemenId, elemenLen, msb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WSMP");
col_set_str(pinfo->cinfo, COL_INFO, "WAVE Short Message Protocol IEEE P1609.3");
ti = proto_tree_add_item(tree, proto_wsmp, tvb, 0, -1, ENC_NA);
wsmp_tree = proto_item_add_subtree(ti, ett_wsmp);
offset = 0;
proto_tree_add_item(wsmp_tree,
hf_wsmp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
psid = tvb_get_guint8(tvb, offset);
psidLen = (guint32)wme_getpsidlen((guint8*)&psid);
if (psidLen == 2)
psid = tvb_get_ntohs(tvb, offset);
else if (psidLen == 3)
{
psid = tvb_get_ntohl(tvb, offset);
psid = psid & 0x00FFFF;
}
else if (psidLen == 4)
psid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(wsmp_tree,
hf_wsmp_psid, tvb, offset, psidLen, ENC_BIG_ENDIAN);
offset += psidLen;
elemenId = tvb_get_guint8(tvb, offset);
while ((elemenId != WSMP) && (elemenId != WSMP_S) && (elemenId != WSMP_I))
{
offset++;
if (elemenId == CHANNUM)
{
elemenLen = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_channel, tvb, offset, elemenLen, ENC_BIG_ENDIAN);
offset += elemenLen;
}
else if (elemenId == DATARATE)
{
elemenLen = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_rate, tvb, offset, elemenLen, ENC_BIG_ENDIAN);
offset += elemenLen;
}
else if (elemenId == TRANSMITPW)
{
elemenLen = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(wsmp_tree,
hf_wsmp_txpower, tvb, offset, elemenLen, ENC_BIG_ENDIAN);
offset += elemenLen;
}
elemenId = tvb_get_guint8(tvb, offset);
}
proto_tree_add_item(wsmp_tree,
hf_wsmp_WAVEid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wsmlength = tvb_get_letohs( tvb, offset);
proto_tree_add_item(wsmp_tree,
hf_wsmp_wsmlength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (elemenId == WSMP_S)
{
msb = 1;
supLen = 0;
while (msb)
{
msb = tvb_get_guint8(tvb, offset + supLen);
msb = msb & 0x80;
supLen++;
}
proto_tree_add_item(wsmp_tree,
hf_wsmp_WSMP_S_data, tvb, offset, supLen, ENC_BIG_ENDIAN);
wsmlength -= supLen;
offset += supLen;
}
wsmdata_tree = proto_tree_add_subtree(wsmp_tree, tvb, offset, wsmlength,
ett_wsmdata, NULL, "Wave Short Message");
wsmdata_tvb = tvb_new_subset(tvb, offset, -1, wsmlength);
if (psid == 0xbff0)
{
call_dissector(data_handle, wsmdata_tvb, pinfo, wsmdata_tree);
}
}
void
proto_register_wsmp(void)
{
static hf_register_info hf[] = {
{ &hf_wsmp_version,
{ "Version", "wsmp.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_psid,
{ "PSID", "wsmp.psid", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_channel,
{ "Channel", "wsmp.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_rate,
{ "Data Rate", "wsmp.rate", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_txpower,
{ "Transmit Power", "wsmp.txpower", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_WAVEid,
{ "WAVE element id", "wsmp.WAVEid", FT_UINT8, BASE_DEC, VALS(wsmp_elemenid_names), 0x0,
NULL, HFILL }},
{ &hf_wsmp_wsmlength,
{ "WSM Length", "wsmp.wsmlength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_wsmp_WSMP_S_data,
{ "WAVE Supplement Data", "wsmp.supplement", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_wsmp,
&ett_wsmdata,
};
proto_wsmp = proto_register_protocol("Wave Short Message Protocol(IEEE P1609.3)",
"WSMP", "wsmp");
proto_register_field_array(proto_wsmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_wsmp(void)
{
dissector_handle_t wsmp_handle;
wsmp_handle = create_dissector_handle(dissect_wsmp, proto_wsmp);
dissector_add_uint("ethertype", ETHERTYPE_WSMP, wsmp_handle);
data_handle = find_dissector("data");
return;
}
