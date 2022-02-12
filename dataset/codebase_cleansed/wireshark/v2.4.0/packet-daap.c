static int
dissect_daap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *daap_tree;
guint first_tag;
first_tag = tvb_get_ntohl(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DAAP");
if (first_tag == daap_png) {
call_dissector(png_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
col_set_str(pinfo->cinfo, COL_INFO, "DAAP Response");
col_append_fstr(pinfo->cinfo, COL_INFO, " [first tag: %s, size: %d]",
tvb_format_text(tvb, 0, 4),
tvb_get_ntohl(tvb, 4));
ti = proto_tree_add_item(tree, proto_daap, tvb, 0, -1, ENC_NA);
daap_tree = proto_item_add_subtree(ti, ett_daap);
dissect_daap_one_tag(daap_tree, pinfo, tvb, 0);
return tvb_captured_length(tvb);
}
static void
dissect_daap_one_tag(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int recursion_depth)
{
guint offset = 0;
guint32 tagname, tagsize;
proto_item *tag_ti;
proto_tree *tag_tree;
tvbuff_t *new_tvb;
if (recursion_depth >= DAAP_MAX_RECURSION_DEPTH) {
proto_tree_add_expert(tree, pinfo, &ei_daap_max_recursion_depth_reached,
tvb, 0, 0);
return;
}
while (offset < tvb_reported_length(tvb)) {
tagname = tvb_get_ntohl(tvb, offset);
tagsize = tvb_get_ntohl(tvb, offset+4);
tag_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_daap_sub, &tag_ti, "Tag: ");
proto_tree_add_item_ret_uint(tag_tree, hf_daap_name,
tvb, offset, 4, ENC_ASCII|ENC_NA, &tagname);
offset += 4;
proto_tree_add_item_ret_uint(tag_tree, hf_daap_size,
tvb, offset, 4, ENC_BIG_ENDIAN, &tagsize);
offset += 4;
proto_item_append_text(tag_ti, "%s, %u byte%c",
val_to_str_ext(tagname, &vals_tag_code_ext, "Unknown tag (0x%0x)"),
tagsize, plurality(tagsize, ' ', 's'));
proto_item_set_len(tag_ti, 8+tagsize);
if (tagsize > G_MAXINT)
break;
switch (tagname) {
case daap_mcon:
case daap_msrv:
case daap_mccr:
case daap_mdcl:
case daap_mlog:
case daap_mupd:
case daap_avdb:
case daap_mlcl:
case daap_mlit:
case daap_mbcl:
case daap_adbs:
case daap_aply:
case daap_apso:
case daap_mudl:
case daap_abro:
case daap_abar:
case daap_arsv:
case daap_abal:
case daap_abcp:
case daap_abgn:
case daap_prsv:
case daap_arif:
case dacp_casp:
case dacp_cmgt:
case dacp_cmst:
new_tvb = tvb_new_subset_length(tvb, offset, (gint)tagsize);
dissect_daap_one_tag(tag_tree, pinfo, new_tvb, recursion_depth+1);
break;
case daap_minm:
case daap_msts:
case daap_mcnm:
case daap_mcna:
case daap_asal:
case daap_asar:
case daap_ascm:
case daap_asfm:
case daap_aseq:
case daap_asgn:
case daap_asdt:
case daap_asul:
case daap_ascp:
case daap_asct:
case daap_ascn:
case daap_aslc:
case daap_asky:
case daap_aeSN:
case daap_aeNN:
case daap_aeEN:
case daap_assn:
case daap_assa:
case daap_assl:
case daap_assc:
case daap_asss:
case daap_asaa:
case daap_aspu:
case daap_aeCR:
case dacp_cana:
case dacp_cang:
case dacp_canl:
case dacp_cann:
proto_tree_add_item(tag_tree, hf_daap_data_string,
tvb, offset, tagsize, ENC_ASCII|ENC_NA);
break;
case daap_mper:
case daap_aeGR:
case daap_aeGU:
case daap_asai:
case daap_asls:
proto_tree_add_item(tag_tree, hf_daap_persistent_id,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_mstt:
proto_tree_add_item(tag_tree, hf_daap_status,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_musr:
case daap_msur:
proto_tree_add_item(tag_tree, hf_daap_rev,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_miid:
case daap_mcti:
case daap_mpco:
case daap_mlid:
proto_tree_add_item(tag_tree, hf_daap_id,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_mrco:
case daap_mtco:
case daap_mimc:
case daap_msdc:
case daap_mctc:
proto_tree_add_item(tag_tree, hf_daap_cnt,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_mstm:
proto_tree_add_item(tag_tree, hf_daap_timeout,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_asda:
case daap_asdm:
case daap_assr:
case daap_assz:
case daap_asst:
case daap_assp:
case daap_astm:
case daap_aeNV:
case daap_ascd:
case daap_ascs:
case daap_aeSV:
case daap_aePI:
case daap_aeCI:
case daap_aeGI:
case daap_aeAI:
case daap_aeSI:
case daap_aeES:
case daap_asbo:
case daap_aeGH:
case daap_aeGD:
case daap_aeGE:
case dacp_cant:
case dacp_cast:
case dacp_cmsr:
case dacp_cmvo:
case daap_meds:
proto_tree_add_item(tag_tree, hf_daap_data,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_mcty:
case daap_asbt:
case daap_asbr:
case daap_asdc:
case daap_asdn:
case daap_astc:
case daap_astn:
case daap_asyr:
case daap_ased:
proto_tree_add_item(tag_tree, hf_daap_data,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_mikd:
case daap_msau:
case daap_msty:
case daap_asrv:
case daap_asur:
case daap_asdk:
case daap_muty:
case daap_msas:
case daap_aeHV:
case daap_aeHD:
case daap_aePC:
case daap_aePP:
case daap_aeMK:
case daap_aeSG:
case daap_apsm:
case daap_aprm:
case daap_asgp:
case daap_aePS:
case dacp_cafs:
case dacp_caps:
case dacp_carp:
case dacp_cash:
case dacp_cavs:
proto_tree_add_item(tag_tree, hf_daap_data,
tvb, offset, tagsize, ENC_BIG_ENDIAN);
break;
case daap_mslr:
case daap_msal:
case daap_msup:
case daap_mspi:
case daap_msex:
case daap_msbr:
case daap_msqy:
case daap_msix:
case daap_msrs:
case daap_asco:
case daap_asdb:
case daap_abpl:
case daap_aeSP:
case daap_asbk:
proto_item_append_text(tag_ti, "; Data: True");
break;
case daap_mpro:
case daap_apro:
proto_item_append_text(tag_ti, "; Version: %d.%d.%d.%d",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset+1),
tvb_get_guint8(tvb, offset+2),
tvb_get_guint8(tvb, offset+3));
break;
case dacp_canp:
proto_tree_add_item(tag_tree, hf_daap_playlist_id,
tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tag_tree, hf_daap_track_id,
tvb, offset+12, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset += tagsize;
}
}
void
proto_register_daap(void)
{
static hf_register_info hf[] = {
{ &hf_daap_name,
{ "Tag name", "daap.name", FT_UINT32,
BASE_HEX|BASE_EXT_STRING, &vals_tag_code_ext, 0, NULL, HFILL }
},
{ &hf_daap_size,
{ "Tag size", "daap.size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_daap_data_string,
{ "Data string", "daap.data_string",
FT_STRING, STR_ASCII, NULL, 0, NULL, HFILL }
},
{ &hf_daap_persistent_id,
{ "Persistent Id", "daap.persistent_id",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_daap_status,
{ "Staus", "daap.status",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_daap_rev,
{ "Revision", "daap.revision",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_daap_id,
{ "Id", "daap.id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_daap_cnt,
{ "Count", "daap.count",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_daap_timeout,
{ "Timeout (seconds)", "daap.timeout",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_daap_data,
{ "Data", "daap.data",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_daap_playlist_id,
{ "Playlist Id", "daap.playlist_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_daap_track_id,
{ "Track Id", "daap.track_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_daap,
&ett_daap_sub,
};
expert_module_t *expert_daap;
static ei_register_info ei[] = {
{ &ei_daap_max_recursion_depth_reached, { "daap.max_recursion_depth_reached",
PI_PROTOCOL, PI_WARN, "Maximum allowed recursion depth reached - stop decoding", EXPFILL }}
};
proto_daap = proto_register_protocol("Digital Audio Access Protocol",
"DAAP", "daap");
expert_daap = expert_register_protocol(proto_daap);
expert_register_field_array(expert_daap, ei, array_length(ei));
proto_register_field_array(proto_daap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_daap(void)
{
dissector_handle_t daap_handle;
daap_handle = create_dissector_handle(dissect_daap, proto_daap);
http_tcp_port_add(TCP_PORT_DAAP);
dissector_add_string("media_type", "application/x-dmap-tagged", daap_handle);
png_handle = find_dissector_add_dependency("png", proto_daap);
}
