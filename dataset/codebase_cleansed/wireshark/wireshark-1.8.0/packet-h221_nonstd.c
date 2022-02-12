static void
dissect_ms_nonstd(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *it;
proto_tree *tr;
guint32 offset=0;
gint tvb_len;
guint16 codec_value, codec_extra;
it=proto_tree_add_protocol_format(tree, proto_nonstd, tvb, 0, tvb_length(tvb), "Microsoft NonStd");
tr=proto_item_add_subtree(it, ett_nonstd);
tvb_len = tvb_length(tvb);
if(tvb_len >= 23)
{
codec_value = tvb_get_ntohs(tvb,offset+20);
codec_extra = tvb_get_ntohs(tvb,offset+22);
if(codec_extra == 0x0100)
{
proto_tree_add_text(tr, tvb, offset+20, 2, "Microsoft NetMeeting Codec=0x%04X %s",
codec_value,val_to_str(codec_value, ms_codec_vals,"Unknown (%u)"));
}
else
{
proto_tree_add_text(tr, tvb, offset, -1, "Microsoft NetMeeting Non Standard");
}
}
}
void
proto_register_nonstd(void)
{
static gint *ett[] = {
&ett_nonstd,
};
proto_nonstd = proto_register_protocol("H221NonStandard","h221nonstd", "h221nonstd");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nonstd(void)
{
static dissector_handle_t ms_nonstd_handle;
ms_nonstd_handle = create_dissector_handle(dissect_ms_nonstd, proto_nonstd);
dissector_add_uint("h245.nsp.h221",0xb500534c, ms_nonstd_handle);
dissector_add_uint("h225.nsp.h221",0xb500534c, ms_nonstd_handle);
}
