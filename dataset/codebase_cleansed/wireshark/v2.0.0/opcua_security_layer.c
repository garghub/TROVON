void registerSecurityLayerTypes(int proto)
{
static hf_register_info hf[] =
{
{&hf_opcua_security_tokenid, {"Security Token Id", "opcua.security.tokenid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_security_seq, {"Security Sequence Number", "opcua.security.seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_security_rqid, {"Security RequestId", "opcua.security.rqid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}}
};
proto_register_field_array(proto, hf, array_length(hf));
}
void parseSecurityLayer(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_security_tokenid, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_security_seq, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_security_rqid, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
