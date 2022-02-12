static gboolean
is_esio_pdu(tvbuff_t *tvb)
{
if (tvb_length(tvb) < 20) {
return FALSE;
}
if (tvb_strneql(tvb, 0, "ESIO", 4) != 0) {
return FALSE;
}
if (tvb_get_guint8(tvb, 4) > 0x00) {
return FALSE;
}
if (tvb_get_guint8(tvb, 5) > 0x02) {
return FALSE;
}
if (tvb_get_guint8(tvb, 6) > 0x00) {
return FALSE;
}
if (tvb_get_guint8(tvb, 7) > 0x00) {
return FALSE;
}
return TRUE;
}
static int
dissect_esio(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *esio_tree, *esio_header_tree, *esio_transfer_header_tree,
*esio_data_tansfer_tree, *esio_data_tree;
gint i;
gint offset;
guint8 esio_nbr_data_transfers;
guint16 esio_telegram_type;
guint16 esio_tlg_type;
guint16 esio_transfer_length;
guint32 esio_transfer_dest_id;
guint32 esio_src_id;
guint32 esio_dst_id;
if (!is_esio_pdu(tvb)) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESIO");
col_clear(pinfo->cinfo, COL_INFO);
esio_telegram_type = tvb_get_guint8(tvb,5);
switch (esio_telegram_type) {
case ESIO_TRANSFER:
esio_src_id = tvb_get_ntohl(tvb,16);
esio_nbr_data_transfers = tvb_get_guint8(tvb, 20);
esio_dst_id = tvb_get_ntohl(tvb,26);
col_add_fstr( pinfo->cinfo, COL_INFO,
"Data transfer: Src ID: %d, Dst ID(s): %d",
esio_src_id, esio_dst_id);
if (esio_nbr_data_transfers > 1) {
col_append_str( pinfo->cinfo, COL_INFO,
" ...");
}
break;
case ESIO_STATUS:
esio_src_id = tvb_get_ntohl(tvb,16);
col_add_fstr( pinfo->cinfo, COL_INFO,
"Status/diag telegram: Src ID: %d",
esio_src_id);
break;
default:
col_set_str( pinfo->cinfo, COL_INFO,
"Unknown telegram");
break;
}
offset = 0;
ti = proto_tree_add_item(tree, proto_esio, tvb, offset, -1, ENC_NA);
esio_tree = proto_item_add_subtree(ti, ett_esio);
esio_header_tree = proto_tree_add_subtree(esio_tree, tvb, offset, 12, ett_esio_header, NULL, "Ether-S-I/O header");
offset += 4;
esio_tlg_type = tvb_get_ntohs(tvb,offset);
proto_tree_add_item(esio_header_tree,
hf_esio_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esio_header_tree,
hf_esio_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esio_header_tree,
hf_esio_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esio_header_tree,
hf_esio_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (esio_tlg_type) {
case ESIO_TRANSFER:
if (tree) {
esio_transfer_header_tree = proto_tree_add_subtree(esio_tree, tvb, offset, 12,
ett_esio_transfer_header, NULL, "Transfer header");
proto_tree_add_item(esio_transfer_header_tree,
hf_esio_tlg_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(esio_transfer_header_tree,
hf_esio_src_stn_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
esio_nbr_data_transfers = tvb_get_guint8(tvb,offset);
proto_tree_add_item(esio_transfer_header_tree,
hf_esio_data_nbr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(esio_transfer_header_tree,
hf_esio_data_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i=((esio_nbr_data_transfers)); i>0; i--) {
esio_transfer_dest_id = tvb_get_ntohl(tvb,(offset+4));
esio_transfer_length = tvb_get_ntohs(tvb,(offset+8));
esio_data_tansfer_tree = proto_tree_add_subtree_format(esio_tree, tvb, offset,
(esio_transfer_length + 10), ett_esio_transfer_data, NULL,
"Data transfer to ID: %d ", esio_transfer_dest_id);
proto_tree_add_item(esio_data_tansfer_tree,
hf_esio_data_transfer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(esio_data_tansfer_tree,
hf_esio_data_dest_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(esio_data_tansfer_tree,
hf_esio_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
esio_data_tree = proto_tree_add_subtree(esio_data_tansfer_tree, tvb, offset,
esio_transfer_length, ett_esio_data, NULL, "Data bytes ");
for (i=((esio_transfer_length)); i>0; i--) {
proto_tree_add_item(esio_data_tree,
hf_esio_data, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
}
}
break;
case ESIO_STATUS: {
proto_item *hi = NULL;
if (tree) {
proto_tree_add_item(esio_tree,
hf_esio_sts_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(esio_tree,
hf_esio_sts_size, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(esio_tree,
hf_esio_src_stn_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(esio_tree,
hf_esio_rio_sts, tvb, offset+8,
1, ENC_BIG_ENDIAN);
hi = proto_tree_add_item(esio_tree,
hf_esio_rio_tlgs_lost, tvb, offset+9,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(esio_tree,
hf_esio_rio_diag, tvb, offset+10,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(esio_tree,
hf_esio_rio_flags, tvb, offset+11, 1, ENC_BIG_ENDIAN);
}
if (tvb_get_guint8(tvb, offset + 9) > 0) {
expert_add_info(pinfo, hi, &ei_esio_telegram_lost);
}
break;
}
default:
break;
}
return tvb_length(tvb);
}
void
proto_register_esio(void)
{
static hf_register_info hf[] = {
{ &hf_esio_type,
{ "Telegram type", "esio.type",
FT_UINT16, BASE_HEX, VALS(esio_tlg_types), 0,
NULL, HFILL }
},
{ &hf_esio_version,
{ "Version", "esio.vers",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_length,
{ "Length (bytes)", "esio.len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_transaction_id,
{ "Transaction ID", "esio.transaction_id",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_src_stn_id,
{ "Source station ID", "esio.src_stn_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_tlg_id,
{ "Telegram ID", "esio.transfer.tlg_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_data_nbr,
{ "Nbr. of data transfers", "esio.data.nbr",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_data_flags,
{ "Transfer header flags", "esio.data.flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_data_transfer_id,
{ "Data transfer ID", "esio.data.transfer_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_data_dest_id,
{ "Data destination ID", "esio.data.destination_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_data_length,
{ "Data transfer length", "esio.data.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_data,
{ "Data", "esio.data",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_sts_type,
{ "Status type", "esio.sts.type",
FT_UINT16, BASE_HEX, VALS(esio_sts_types), 0,
NULL, HFILL }
},
{ &hf_esio_sts_size,
{ "Status length (bytes)", "esio.sts.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_rio_sts,
{ "RIO status", "esio.sts.rio_sts",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_rio_tlgs_lost,
{ "Lost telegrams to RIO", "esio.sts.rio_lost_tlg",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_rio_diag,
{ "RIO diagnostics", "esio.sts.rio_diag",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_esio_rio_flags,
{ "RIO flags", "esio.sts.rio_flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_esio,
&ett_esio_header,
&ett_esio_transfer_header,
&ett_esio_transfer_data,
&ett_esio_data
};
static ei_register_info ei[] = {
{ &ei_esio_telegram_lost, { "esio.telegram_lost", PI_SEQUENCE, PI_NOTE, "Telegram(s) lost", EXPFILL }},
};
expert_module_t* expert_esio;
proto_esio = proto_register_protocol("SAIA Ether-S-I/O protocol", "ESIO", "esio");
proto_register_field_array(proto_esio, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_esio = expert_register_protocol(proto_esio);
expert_register_field_array(expert_esio, ei, array_length(ei));
}
void
proto_reg_handoff_esio(void)
{
dissector_handle_t esio_handle;
esio_handle = new_create_dissector_handle(dissect_esio, proto_esio);
dissector_add_uint("udp.port", 6060, esio_handle);
}
