static int
dissect_dsr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti_main, *ti, *ti_hoplist;
proto_tree *dsr_tree, *opt_tree, *options_tree, *opt_hoplist_tree;
guint offset = 0;
guint offset_in_option = 0;
guint nexthdr, opt_tot_len, opt_len, opt_type, opt_id, opt_err_type, flowstate_hdr;
guint i;
tvbuff_t *next_tvb;
if (tvb_reported_length(tvb) < DSR_MIN_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DSR");
col_add_str(pinfo->cinfo, COL_INFO, "Options : ");
ti_main = proto_tree_add_item(tree, proto_dsr, tvb, 0, -1, ENC_NA);
dsr_tree = proto_item_add_subtree(ti_main, ett_dsr);
proto_tree_add_item(dsr_tree, hf_dsr_nexthdr, tvb, offset, 1, ENC_BIG_ENDIAN);
nexthdr = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(dsr_tree, hf_dsr_flowstate, tvb, offset, 1, ENC_BIG_ENDIAN);
flowstate_hdr = tvb_get_bits8(tvb, offset*8, 1);
if (!flowstate_hdr) {
proto_tree_add_item(dsr_tree, hf_dsr_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dsr_tree, hf_dsr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
opt_tot_len = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti_main, opt_tot_len+4);
offset += 2;
options_tree = proto_tree_add_subtree(dsr_tree, tvb, offset, opt_tot_len, ett_dsr_options, NULL, "Options");
while (offset - 4 < opt_tot_len) {
opt_type = tvb_get_guint8(tvb, offset);
offset_in_option = offset;
opt_len = 0;
switch(opt_type) {
case DSR_OPT_TYPE_RREQ:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_rreq_opt, &ti, "Route request");
col_append_str(pinfo->cinfo, COL_INFO, "Route request");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option);
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_rreq_id, tvb, offset_in_option, 2, ENC_BIG_ENDIAN);
opt_id = tvb_get_ntohs(tvb, offset_in_option);
col_append_fstr(pinfo->cinfo, COL_INFO, " (id=0x%x)", opt_id);
offset_in_option += 2;
proto_tree_add_item(opt_tree, hf_dsr_opt_rreq_targetaddress, tvb, offset_in_option, 4, ENC_NA);
offset_in_option += 4;
if(opt_len > 6) {
opt_hoplist_tree = proto_tree_add_subtree(opt_tree, tvb, offset_in_option, 1, ett_dsr_rreq_hoplist, &ti_hoplist, "Hop list" );
proto_item_append_text(ti_hoplist, " :");
for(i=0;i<(opt_len-4)/4;i++) {
proto_tree_add_item(opt_hoplist_tree, hf_dsr_opt_rreq_address, tvb, offset_in_option, 4, ENC_NA);
proto_item_append_text(ti_hoplist, " %s", tvb_ip_to_str(tvb, offset_in_option));
offset_in_option += 4;
}
}
break;
case DSR_OPT_TYPE_RREP:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_rrep_opt, &ti, "Route reply");
col_append_str(pinfo->cinfo, COL_INFO, "Route reply");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option);
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_rrep_lasthopex, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_dsr_opt_rrep_reserved, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
if(opt_len > 2) {
opt_hoplist_tree = proto_tree_add_subtree(opt_tree, tvb, offset_in_option, 1, ett_dsr_rrep_hoplist, &ti_hoplist, "Hop list" );
proto_item_append_text(ti_hoplist, " :");
for(i=0;i<(opt_len-1)/4;i++) {
proto_tree_add_item(opt_hoplist_tree, hf_dsr_opt_rrep_address, tvb, offset_in_option, 4, ENC_NA);
proto_item_append_text(ti_hoplist, " %s", tvb_ip_to_str(tvb, offset_in_option));
offset_in_option += 4;
}
}
break;
case DSR_OPT_TYPE_RERR:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_rerr_opt, &ti, "Route error");
col_append_str(pinfo->cinfo, COL_INFO, "Route error");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option);
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_err_type, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_err_type = tvb_get_guint8(tvb, offset_in_option);
offset_in_option += 1;
proto_tree_add_bits_item(opt_tree, hf_dsr_opt_err_reserved, tvb, offset_in_option*8, 4, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(opt_tree, hf_dsr_opt_err_salvage, tvb, offset_in_option*8+4, 4, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_err_src, tvb, offset_in_option, 4, ENC_NA);
offset_in_option += 4;
proto_tree_add_item(opt_tree, hf_dsr_opt_err_dest, tvb, offset_in_option, 4, ENC_NA);
offset_in_option += 4;
switch(opt_err_type) {
case DSR_RERR_TYPE_UNREACHABLE:
proto_tree_add_item(opt_tree, hf_dsr_opt_err_unreach_addr, tvb, offset_in_option, 4, ENC_NA);
break;
case DSR_RERR_TYPE_FLOWSTATENOTSUPPORTED:
break;
case DSR_RERR_TYPE_OPTIONNOTSUPPORTED:
proto_tree_add_item(opt_tree, hf_dsr_opt_err_unsupportedoption, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
break;
case DSR_RERR_TYPE_UNKNOWNFLOW:
proto_tree_add_item(opt_tree, hf_dsr_opt_err_unknownflow_dest, tvb, offset_in_option, 4, ENC_NA);
offset_in_option += 4;
proto_tree_add_item(opt_tree, hf_dsr_opt_err_unknownflow_id, tvb, offset_in_option, 2, ENC_BIG_ENDIAN);
break;
case DSR_RERR_TYPE_DEFAULTFLOWUNKNOWN:
proto_tree_add_item(opt_tree, hf_dsr_opt_err_defaultflowunknown_dest, tvb, offset_in_option, 4, ENC_NA);
break;
}
break;
case DSR_OPT_TYPE_ACKREQ:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_ackreq_opt, &ti, "Acknowledgement request");
col_append_str(pinfo->cinfo, COL_INFO, "Ack request");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option);
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_ack_req_id, tvb, offset_in_option, 2, ENC_BIG_ENDIAN);
opt_id = tvb_get_ntohs(tvb, offset_in_option);
col_append_fstr(pinfo->cinfo, COL_INFO, " (id=0x%x)", opt_id);
offset_in_option += 2;
if(opt_len >= 6) {
proto_tree_add_item(opt_tree, hf_dsr_opt_ack_req_address, tvb, offset_in_option, 4, ENC_NA);
}
break;
case DSR_OPT_TYPE_ACK:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_ack_opt, &ti, "Acknowledgement");
col_append_str(pinfo->cinfo, COL_INFO, "Ack");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option);
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_ack_id, tvb, offset_in_option, 2, ENC_BIG_ENDIAN);
opt_id = tvb_get_ntohs(tvb, offset_in_option);
col_append_fstr(pinfo->cinfo, COL_INFO, " (id=0x%x)", opt_id);
offset_in_option += 2;
proto_tree_add_item(opt_tree, hf_dsr_opt_ack_src, tvb, offset_in_option, 4, ENC_NA);
offset_in_option += 4;
proto_tree_add_item(opt_tree, hf_dsr_opt_ack_dest, tvb, offset_in_option, 4, ENC_NA);
break;
case DSR_OPT_TYPE_SRCRT:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_srcrt_opt, &ti, "Source route");
col_append_str(pinfo->cinfo, COL_INFO, "Source route");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option );
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_bits_item(opt_tree, hf_dsr_opt_srcrt_firsthopext, tvb, offset_in_option*8, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(opt_tree, hf_dsr_opt_srcrt_lasthopext, tvb, offset_in_option*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(opt_tree, hf_dsr_opt_srcrt_reserved, tvb, offset_in_option*8+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(opt_tree, hf_dsr_opt_srcrt_salvage, tvb, offset_in_option*8+6, 4, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_opt_srcrt_segsleft, tvb, offset_in_option , 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
if(opt_len > 2) {
opt_hoplist_tree = proto_tree_add_subtree(opt_tree, tvb, offset_in_option, 1, ett_dsr_srcrt_hoplist, &ti_hoplist, "Hop list" );
proto_item_append_text(ti_hoplist, " :");
for(i=0;i<(opt_len-2)/4;i++) {
proto_tree_add_item(opt_hoplist_tree, hf_dsr_opt_srcrt_address, tvb, offset_in_option , 4, ENC_NA);
proto_item_append_text(ti_hoplist, " %s", tvb_ip_to_str(tvb, offset_in_option));
offset_in_option += 4;
}
}
break;
case DSR_OPT_TYPE_PADN:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_padn_opt, &ti, "PadN");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option , 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option , 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option );
proto_item_set_len(ti, opt_len+2);
break;
case DSR_OPT_TYPE_PAD1:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_pad1_opt, &ti, "Pad1");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option , 1, ENC_BIG_ENDIAN);
break;
case DSR_FS_OPT_TYPE_TIMEOUT :
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_fs_timeout_opt, &ti, "Timeout");
col_append_str(pinfo->cinfo, COL_INFO, "Timeout");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option );
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_fs_opt_timeout_timeout, tvb, offset_in_option, 2, ENC_BIG_ENDIAN);
break;
case DSR_FS_OPT_TYPE_DESTFLOWID:
opt_tree = proto_tree_add_subtree(options_tree, tvb, offset_in_option, 1, ett_dsr_fs_destflowid_opt, &ti, "Destination and flow id");
col_append_str(pinfo->cinfo, COL_INFO, "Dest&FlowId");
proto_tree_add_item(opt_tree, hf_dsr_opttype, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_optlen, tvb, offset_in_option, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, offset_in_option );
proto_item_set_len(ti, opt_len+2);
offset_in_option += 1;
proto_tree_add_item(opt_tree, hf_dsr_fs_opt_destflowid_id, tvb, offset_in_option, 2, ENC_BIG_ENDIAN);
offset_in_option += 2;
proto_tree_add_item(opt_tree, hf_dsr_fs_opt_destflowid_dest, tvb, offset_in_option, 4, ENC_NA);
break;
}
if (opt_type != DSR_OPT_TYPE_PAD1)
offset += 2+opt_len;
else
offset += 1;
if(offset-4 < opt_tot_len && opt_type != DSR_OPT_TYPE_PAD1 && opt_type != DSR_OPT_TYPE_PADN) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
}
} else {
proto_tree_add_item(dsr_tree, hf_dsr_fs_hopcount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dsr_tree, hf_dsr_fs_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint(ip_dissector_table, nexthdr, next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
return offset+4;
}
void
proto_register_dsr(void)
{
static hf_register_info hf[] = {
{ &hf_dsr_nexthdr,
{ "Next header", "dsr.nexthdr",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&ipproto_val_ext, 0x0,
"Next header protocol type", HFILL }
},
{ &hf_dsr_flowstate,
{ "Flow state", "dsr.flowstate",
FT_BOOLEAN, 8,
NULL, 0x80,
NULL, HFILL }
},
{ &hf_dsr_reserved,
{ "Reserved", "dsr.reserved",
FT_UINT8, BASE_HEX,
NULL, 0x7F,
NULL, HFILL }
},
{ &hf_dsr_length,
{ "Length", "dsr.len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"Payload length", HFILL }
},
{ &hf_dsr_opttype,
{ "Type", "dsr.option.type",
FT_UINT8, BASE_DEC,
VALS(dsropttypenames), 0x0,
NULL, HFILL }
},
{ &hf_dsr_optlen,
{ "Length", "dsr.option.len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"Option length", HFILL }
},
{ &hf_dsr_opt_rreq_id,
{ "Id", "dsr.option.rreq.id",
FT_UINT16, BASE_HEX_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_rreq_targetaddress,
{ "Target address", "dsr.option.rreq.targetaddress",
FT_IPv4, BASE_NONE,
NULL, 0x0,
"Target IP address", HFILL }
},
{ &hf_dsr_opt_rreq_address,
{ "Hop", "dsr.option.rreq.address",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_rrep_lasthopex,
{ "Last hop external", "dsr.option.rrep.lasthopex",
FT_BOOLEAN, 8,
NULL, 0x80,
NULL, HFILL }
},
{ &hf_dsr_opt_rrep_reserved,
{ "Reserved", "dsr.option.rrep.reserved",
FT_UINT8, BASE_HEX,
NULL, 0x7F,
NULL, HFILL }
},
{ &hf_dsr_opt_rrep_address,
{ "Hop", "dsr.option.rrep.address",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_err_type,
{ "Type", "dsr.option.err.type",
FT_UINT8, BASE_DEC,
VALS(dsrrerrtypenames), 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_err_reserved,
{ "Reserved", "dsr.option.err.reserved",
FT_UINT8, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_dsr_opt_err_salvage,
{ "Salvage", "dsr.option.err.salvage",
FT_UINT8, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_dsr_opt_err_src,
{ "Source address", "dsr.option.err.src",
FT_IPv4, BASE_NONE,
NULL, 0x00,
"Source IP address", HFILL }
},
{ &hf_dsr_opt_err_dest,
{ "Destination address", "dsr.option.err.dest",
FT_IPv4, BASE_NONE,
NULL, 0x00,
"Destination IP address", HFILL }
},
{ &hf_dsr_opt_err_unreach_addr,
{ "Unreachable node address", "dsr.option.err.unreachablenode",
FT_IPv4, BASE_NONE,
NULL, 0x00,
"Unreachable node IP address", HFILL }
},
{ &hf_dsr_opt_err_unsupportedoption,
{ "Unsupported option", "dsr.option.err.unsupportedoption",
FT_UINT8, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_dsr_opt_ack_req_id,
{ "Id", "dsr.option.ackreq.id",
FT_UINT16, BASE_HEX_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_ack_req_address,
{ "Source address", "dsr.option.ackreq.address",
FT_IPv4, BASE_NONE,
NULL, 0x0,
"Source IP address", HFILL }
},
{ &hf_dsr_opt_ack_id,
{ "Id", "dsr.option.ack.id",
FT_UINT16, BASE_HEX_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_ack_src,
{ "Source IP", "dsr.option.ack.source",
FT_IPv4, BASE_NONE,
NULL, 0x0,
"Source IP address", HFILL }
},
{ &hf_dsr_opt_ack_dest,
{ "Destination IP", "dsr.option.ack.dest",
FT_IPv4, BASE_NONE,
NULL, 0x0,
"Destination IP address", HFILL }
},
{ &hf_dsr_opt_srcrt_firsthopext,
{ "First hop external", "dsr.option.srcrt.firsthopext",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_srcrt_lasthopext,
{ "Last hop external", "dsr.option.srcrt.lasthopext",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_srcrt_reserved,
{ "Reserved", "dsr.option.srcrt.reserved",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_srcrt_salvage,
{ "Salvage", "dsr.option.srcrt.salvage",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_opt_srcrt_segsleft,
{ "Segments left", "dsr.option.srcrt.segsleft",
FT_UINT8, BASE_DEC,
NULL, 0x3F,
NULL, HFILL }
},
{ &hf_dsr_opt_srcrt_address,
{ "Hop", "dsr.option.ack.address",
FT_IPv4, BASE_NONE,
NULL, 0x0,
"Hop IP address", HFILL }
},
{ &hf_dsr_fs_hopcount,
{ "Hop count", "dsr.fs.hopcount",
FT_UINT8, BASE_DEC,
NULL, 0x7F,
NULL, HFILL }
},
{ &hf_dsr_fs_id,
{ "Flow id", "dsr.fs.id",
FT_UINT16, BASE_HEX_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_dsr_fs_opt_timeout_timeout,
{ "Timeout", "dsr.option.timeout.timeout",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_dsr_fs_opt_destflowid_id,
{ "Flow id", "dsr.option.destflowid.id",
FT_UINT16, BASE_HEX_DEC,
NULL, 0x0,
"New flow identifier", HFILL }
},
{ &hf_dsr_fs_opt_destflowid_dest,
{ "Destination IP", "dsr.option.destflowid.dest",
FT_IPv4, BASE_NONE,
NULL, 0x0,
"New IP destination address", HFILL }
},
{ &hf_dsr_opt_err_unknownflow_dest,
{ "Original IP destination", "dsr.option.err.unknownflow.dest",
FT_IPv4, BASE_NONE,
NULL, 0x00,
"Original IP destination address", HFILL }
},
{ &hf_dsr_opt_err_unknownflow_id,
{ "Flow id", "dsr.option.err.unknownflow.id",
FT_UINT16, BASE_HEX_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_dsr_opt_err_defaultflowunknown_dest,
{ "Original IP destination", "dsr.option.err.defaultflowunknow.dest",
FT_IPv4, BASE_NONE,
NULL, 0x00,
"Original IP destination address", HFILL }
},
};
static gint *ett[] = {
&ett_dsr,
&ett_dsr_options,
&ett_dsr_rreq_opt,
&ett_dsr_rrep_opt,
&ett_dsr_rerr_opt,
&ett_dsr_ackreq_opt,
&ett_dsr_ack_opt,
&ett_dsr_srcrt_opt,
&ett_dsr_padn_opt,
&ett_dsr_pad1_opt,
&ett_dsr_fs_timeout_opt,
&ett_dsr_fs_destflowid_opt,
&ett_dsr_rreq_hoplist,
&ett_dsr_rrep_hoplist,
&ett_dsr_srcrt_hoplist
};
proto_dsr = proto_register_protocol(
"Dynamic Source Routing",
"DSR",
"dsr");
proto_register_field_array(proto_dsr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dsr(void)
{
dissector_handle_t dsr_handle;
ip_dissector_table = find_dissector_table("ip.proto");
dsr_handle = create_dissector_handle(dissect_dsr, proto_dsr);
dissector_add_uint("ip.proto", IP_PROTO_DSR, dsr_handle);
}
