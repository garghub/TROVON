static void
dissect_ms_nonstd(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *it;
proto_tree *tr;
guint32 offset=0;
gint tvb_len;
guint16 codec_extra;
it=proto_tree_add_protocol_format(tree, proto_nonstd, tvb, 0, tvb_length(tvb), "Microsoft NonStd");
tr=proto_item_add_subtree(it, ett_nonstd);
tvb_len = tvb_reported_length(tvb);
if(tvb_len >= 23)
{
codec_extra = tvb_get_ntohs(tvb,offset+22);
if(codec_extra == 0x0100)
{
proto_tree_add_item(tr, hf_h221_nonstd_netmeeting_codec, tvb, offset+20, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tr, hf_h221_nonstd_netmeeting_non_standard, tvb, offset, -1, ENC_NA);
}
}
}
void
proto_register_nonstd(void)
{
static hf_register_info hf[] = {
{ &hf_h221_nonstd_netmeeting_codec,
{ "Microsoft NetMeeting Codec", "h221nonstd.netmeeting.codec", FT_UINT32, BASE_HEX,
VALS(ms_codec_vals), 0, NULL, HFILL }
},
{ &hf_h221_nonstd_netmeeting_non_standard,
{ "Microsoft NetMeeting Non Standard", "netmeeting.non_standard", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_nonstd,
};
proto_nonstd = proto_register_protocol("H221NonStandard","h221nonstd", "h221nonstd");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_nonstd, hf, array_length(hf));
}
void
proto_reg_handoff_nonstd(void)
{
static dissector_handle_t ms_nonstd_handle;
ms_nonstd_handle = create_dissector_handle(dissect_ms_nonstd, proto_nonstd);
dissector_add_uint("h245.nsp.h221",0xb500534c, ms_nonstd_handle);
dissector_add_uint("h225.nsp.h221",0xb500534c, ms_nonstd_handle);
}
