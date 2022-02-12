static int
dissect_oipf_ciplus(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
gint msg_len;
proto_tree *oipf_ciplus_tree;
guint offset = 0;
guint8 i, send_datatype_nbr;
guint16 dat_len;
msg_len = tvb_reported_length(tvb);
if (msg_len < 8)
return 0;
oipf_ciplus_tree = proto_tree_add_subtree(tree, tvb, 0, msg_len, ett_oipf_ciplus, NULL, "Open IPTV Forum CSPG-CI+");
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_cmd_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_ca_sys_id,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_trx_id,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
send_datatype_nbr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_send_datatype_nbr,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i<send_datatype_nbr; i++) {
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_dat_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dat_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_dat_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(oipf_ciplus_tree, hf_oipf_ciplus_data,
tvb, offset, dat_len, ENC_NA);
offset += dat_len;
}
return offset;
}
void
proto_register_oipf(void)
{
static gint *ett[] = {
&ett_oipf_ciplus
};
static hf_register_info hf[] = {
{ &hf_oipf_ciplus_cmd_id,
{ "Command ID", "oipf.ciplus.cmd_id", FT_UINT8, BASE_HEX,
VALS(oipf_ciplus_cmd_id), 0, NULL, HFILL } },
{ &hf_oipf_ciplus_ca_sys_id,
{ "CA system ID", "oipf.ciplus.ca_system_id", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_oipf_ciplus_trx_id,
{ "Transaction ID", "oipf.ciplus.transaction_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_oipf_ciplus_send_datatype_nbr,
{ "Number of data items", "oipf.ciplus.num_items", FT_UINT8,
BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_oipf_ciplus_dat_id,
{ "Datatype ID", "oipf.ciplus.datatype_id", FT_UINT8, BASE_HEX,
VALS(oipf_ciplus_dat_id), 0, NULL, HFILL } },
{ &hf_oipf_ciplus_dat_len,
{ "Datatype length", "oipf.ciplus.datatype_len", FT_UINT16,
BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_oipf_ciplus_data,
{ "Data", "oipf.ciplus.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } }
};
proto_oipf_ciplus = proto_register_protocol(
"Open IPTV Forum CSPG-CI+", "OIPF CI+", "oipf.ciplus");
proto_register_field_array(proto_oipf_ciplus, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_oipf(void)
{
dissector_handle_t oipf_ciplus_handle;
oipf_ciplus_handle =
create_dissector_handle(dissect_oipf_ciplus, proto_oipf_ciplus);
dissector_add_string("dvb-ci.sas.app_id_str",
sas_app_id_str_oipf, oipf_ciplus_handle);
}
