static int
dissect_pcapng_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
if (!dissector_try_uint(pcapng_block_type_dissector_table,
pinfo->pseudo_header->ftsrec.record_type, tvb, pinfo, tree)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCAP-NG");
col_add_fstr(pinfo->cinfo, COL_INFO, "PCAP-NG block, type %u",
pinfo->pseudo_header->ftsrec.record_type);
proto_tree_add_item(tree, proto_pcapng_block, tvb, 0, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
void proto_register_pcapng_block(void)
{
proto_pcapng_block = proto_register_protocol("PCAP-NG block",
"PCAP-NG", "pcapng");
pcapng_block_type_dissector_table = register_dissector_table("pcapng.block_type",
"pcap-ng block type", proto_pcapng_block, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_pcapng_block(void)
{
dissector_handle_t pcapng_block_handle;
pcapng_block_handle = create_dissector_handle(dissect_pcapng_block,
proto_pcapng_block);
dissector_add_uint("wtap_fts_rec", WTAP_FILE_TYPE_SUBTYPE_PCAPNG,
pcapng_block_handle);
}
