static void dissect_felica(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *felica_tree = NULL;
guint8 opcode;
guint8 rwe_pos = 0;
tvbuff_t *rwe_resp_data_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FeliCa");
col_set_str(pinfo->cinfo, COL_INFO, "FeliCa Packet");
if (tree) {
item = proto_tree_add_item(tree, proto_felica, tvb, 0, -1, ENC_NA);
felica_tree = proto_item_add_subtree(item, ett_felica);
}
opcode = tvb_get_guint8(tvb, 0);
switch (opcode) {
case CMD_POLLING:
col_set_str(pinfo->cinfo, COL_INFO, "Polling Request");
if (tree) {
proto_tree_add_item(felica_tree, hf_felica_command, tvb, 0, 1, ENC_NA);
proto_tree_add_item(felica_tree, hf_felica_sys_code, tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_req_code, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_timeslot, tvb, 4, 1, ENC_BIG_ENDIAN);
}
break;
case RES_POLLING:
col_set_str(pinfo->cinfo, COL_INFO, "Polling Response");
if (tree) {
proto_tree_add_item(felica_tree, hf_felica_response, tvb, 0, 1, ENC_NA);
proto_tree_add_item(felica_tree, hf_felica_idm, tvb, 1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_pnm, tvb, 9, 8, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) == 19)
proto_tree_add_item(felica_tree, hf_felica_sys_code, tvb, 17, 2, ENC_BIG_ENDIAN);
}
break;
case CMD_READ_WO_ENCRYPTION:
col_set_str(pinfo->cinfo, COL_INFO, "Read Without Encryption Request");
if (tree) {
proto_tree_add_item(felica_tree, hf_felica_command, tvb, 0, 1, ENC_NA);
proto_tree_add_item(felica_tree, hf_felica_idm, tvb, 1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_nbr_of_svcs, tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_svc_code, tvb, 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_nbr_of_blocks, tvb, 12, 1, ENC_BIG_ENDIAN);
for (rwe_pos = 0; rwe_pos < tvb_get_guint8(tvb, 12); rwe_pos++) {
proto_tree_add_uint(felica_tree, hf_felica_block_nbr, tvb,
13 + 2 * rwe_pos, 2, tvb_get_guint8(tvb, 14 + 2 * rwe_pos));
}
}
break;
case RES_READ_WO_ENCRYPTION:
col_set_str(pinfo->cinfo, COL_INFO, "Read Without Encryption Response");
if (tree) {
proto_tree_add_item(felica_tree, hf_felica_response, tvb, 0, 1, ENC_NA);
proto_tree_add_item(felica_tree, hf_felica_idm, tvb, 1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_status_flag1, tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_status_flag2, tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(felica_tree, hf_felica_nbr_of_blocks, tvb, 11, 1, ENC_BIG_ENDIAN);
}
rwe_resp_data_tvb = tvb_new_subset_remaining(tvb, 12);
call_dissector(data_handle, rwe_resp_data_tvb, pinfo, tree);
break;
case CMD_WRITE_WO_ENCRYPTION:
col_set_str(pinfo->cinfo, COL_INFO, "Write Without Encryption Request");
break;
case RES_WRITE_WO_ENCRYPTION:
col_set_str(pinfo->cinfo, COL_INFO, "Write Without Encryption Response");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown");
break;
}
}
void
proto_register_felica(void)
{
static hf_register_info hf[] = {
{&hf_felica_command,
{ "Command", "felica.cmd",
FT_UINT8, BASE_HEX, VALS(felica_commands), 0x0,
NULL, HFILL }
},
{&hf_felica_response,
{ "Response", "felica.res",
FT_UINT8, BASE_HEX,
VALS(felica_responses), 0x0,
NULL, HFILL }
},
{&hf_felica_req_code,
{ "Request Code", "felica.req.code",
FT_UINT8, BASE_HEX, VALS(felica_req_codes), 0x0,
NULL, HFILL }
},
{&hf_felica_idm,
{ "IDm (Manufacture ID)/NFCID2", "felica.idm",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_sys_code,
{ "System Code", "felica.sys_code",
FT_UINT16, BASE_HEX, VALS(felica_sys_codes), 0x0,
NULL, HFILL }
},
{&hf_felica_svc_code,
{ "Service Code", "felica.svc_code",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_pnm,
{ "PNm (Manufacture Parameter)/PAD", "felica.pnm",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_nbr_of_svcs,
{ "Number of Services", "felica.svcs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_nbr_of_blocks,
{ "Number of Blocks", "felica.blocks",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_block_nbr,
{ "Block Number", "felica.block.nbr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_status_flag1,
{ "Status Flag 1", "felica.status.flag1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_status_flag2,
{ "Status Flag 2", "felica.status.flag2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_felica_timeslot,
{ "Timeslot", "felica.timeslot",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_felica
};
proto_felica = proto_register_protocol("Sony FeliCa", "FeliCa", "felica");
proto_register_field_array(proto_felica, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("felica", dissect_felica, proto_felica);
}
void
proto_reg_handoff_felica(void)
{
data_handle = find_dissector("data");
}
