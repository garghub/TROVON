static void
dissect_daap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *daap_tree;
guint first_tag = 0;
first_tag = tvb_get_ntohl(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DAAP");
if (first_tag == daap_png) {
call_dissector(png_handle, tvb, pinfo, tree);
return;
}
col_set_str(pinfo->cinfo, COL_INFO, "DAAP Response");
col_append_fstr(pinfo->cinfo, COL_INFO, " [first tag: %s, size: %d]",
tvb_format_text(tvb, 0, 4),
tvb_get_ntohl(tvb, 4));
if (tree) {
ti = proto_tree_add_item(tree, proto_daap, tvb, 0, -1, ENC_NA);
daap_tree = proto_item_add_subtree(ti, ett_daap);
dissect_daap_one_tag(daap_tree, tvb);
}
}
static void
dissect_daap_one_tag(proto_tree *tree, tvbuff_t *tvb)
{
gint offset = 0;
gint reported_length;
guint32 tagname;
guint32 tagsize;
gint len;
proto_item *ti;
proto_item *ti2;
proto_tree *new_tree;
tvbuff_t *new_tvb;
reported_length = tvb_reported_length(tvb);
while ((offset >= 0) && (offset < reported_length)) {
tagname = tvb_get_ntohl(tvb, offset);
tagsize = tvb_get_ntohl(tvb, offset+4);
ti = proto_tree_add_text(tree, tvb, offset, 8,
"Tag: %-40s %3u byte%c",
val_to_str_ext(tagname, &vals_tag_code_ext, "Unknown tag (0x%0x)"),
tagsize,
plurality(tagsize, ' ', 's'));
ti2 = proto_tree_add_item(tree, hf_daap_name, tvb, offset, 4, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti2);
ti2 = proto_tree_add_item(tree, hf_daap_size, tvb, offset+4, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti2);
offset += 8;
len = reported_length - offset;
DISSECTOR_ASSERT(len >= 0);
if (tagsize <= (unsigned)len) {
len = tagsize;
}
proto_item_set_len(ti, 8+len);
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
new_tree = proto_item_add_subtree(ti, ett_daap_sub);
new_tvb = tvb_new_subset(tvb, offset, len, len);
dissect_daap_one_tag(new_tree, new_tvb);
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
proto_item_append_text(ti, "; Data: %s",
tvb_format_text(tvb, offset, tagsize));
break;
case daap_mper:
case daap_aeGR:
case daap_aeGU:
case daap_asai:
case daap_asls:
proto_item_append_text(ti, "; Persistent Id: %" G_GINT64_MODIFIER "u",
tvb_get_ntoh64(tvb, offset));
break;
case daap_mstt:
proto_item_append_text(ti, "; Status: %d",
tvb_get_ntohl(tvb, offset));
break;
case daap_musr:
case daap_msur:
proto_item_append_text(ti, "; Revision: %d",
tvb_get_ntohl(tvb, offset));
break;
case daap_miid:
case daap_mcti:
case daap_mpco:
case daap_mlid:
proto_item_append_text(ti, "; Id: %d",
tvb_get_ntohl(tvb, offset));
break;
case daap_mrco:
case daap_mtco:
case daap_mimc:
case daap_msdc:
case daap_mctc:
proto_item_append_text(ti, "; Count: %d",
tvb_get_ntohl(tvb, offset));
break;
case daap_mstm:
proto_item_append_text(ti, "; Timeout: %d seconds",
tvb_get_ntohl(tvb, offset));
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
proto_item_append_text(ti, "; Data: %d",
tvb_get_ntohl(tvb, offset));
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
proto_item_append_text(ti, "; Data: %d",
tvb_get_ntohs(tvb, offset));
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
proto_item_append_text(ti, "; Data: %d",
tvb_get_guint8(tvb, offset));
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
proto_item_append_text(ti, "; Data: True");
break;
case daap_mpro:
case daap_apro:
proto_item_append_text(ti, "; Version: %d.%d.%d.%d",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset+1),
tvb_get_guint8(tvb, offset+2),
tvb_get_guint8(tvb, offset+3));
break;
case dacp_canp:
proto_item_append_text(ti,
"; unknown: %d, playlist id: %d, unknown: %d, track id: %d",
tvb_get_ntohl(tvb, offset),
tvb_get_ntohl(tvb, offset+4),
tvb_get_ntohl(tvb, offset+8),
tvb_get_ntohl(tvb, offset+12));
default:
break;
}
if ((signed)tagsize < 0)
break;
offset += tagsize;
}
if ((offset < 0) || ((reported_length - offset) != 0)) {
THROW(ReportedBoundsError);
}
return;
}
void
proto_register_daap(void)
{
static hf_register_info hf[] = {
{ &hf_daap_name,
{ "Name", "daap.name", FT_STRING, BASE_NONE, NULL, 0x0,
"Tag Name", HFILL}
},
{ &hf_daap_size,
{ "Size", "daap.size", FT_UINT32, BASE_DEC, NULL, 0x0,
"Tag Size", HFILL }
}
};
static gint *ett[] = {
&ett_daap,
&ett_daap_sub,
};
proto_daap = proto_register_protocol("Digital Audio Access Protocol",
"DAAP", "daap");
proto_register_field_array(proto_daap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_daap(void)
{
dissector_handle_t daap_handle;
daap_handle = create_dissector_handle(dissect_daap, proto_daap);
http_port_add(TCP_PORT_DAAP);
dissector_add_string("media_type", "application/x-dmap-tagged", daap_handle);
png_handle = find_dissector("png");
}
