void registerApplicationLayerTypes(int proto)
{
static hf_register_info hf[] =
{
{ &hf_opcua_nodeid_encodingmask,
{ "NodeId EncodingMask", "application.nodeid.encodingmask", FT_UINT8, BASE_HEX, VALS(g_nodeidmasks), 0x0, NULL, HFILL }
},
{ &hf_opcua_app_nsid,
{ "NodeId EncodingMask", "application.nodeid.nsid", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_app_numeric,
{ "NodeId Identifier Numeric", "application.nodeid.numeric", FT_UINT32, BASE_DEC, VALS(g_requesttypes), 0x0, NULL, HFILL }
}
};
proto_register_field_array(proto, hf, array_length(hf));
}
int parseServiceNodeId(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
gint iOffset = *pOffset;
guint8 EncodingMask;
guint32 Numeric = 0;
EncodingMask = tvb_get_guint8(tvb, iOffset);
proto_tree_add_item(tree, hf_opcua_nodeid_encodingmask, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
switch(EncodingMask)
{
case 0x00:
Numeric = tvb_get_guint8(tvb, iOffset);
proto_tree_add_item(tree, hf_opcua_app_numeric, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
break;
case 0x01:
proto_tree_add_item(tree, hf_opcua_app_nsid, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
Numeric = tvb_get_letohs(tvb, iOffset);
proto_tree_add_item(tree, hf_opcua_app_numeric, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
break;
case 0x02:
proto_tree_add_item(tree, hf_opcua_app_nsid, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
iOffset+=4;
Numeric = tvb_get_letohl(tvb, iOffset);
proto_tree_add_item(tree, hf_opcua_app_numeric, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
iOffset+=4;
break;
case 0x03:
case 0x04:
case 0x05:
break;
};
*pOffset = iOffset;
return Numeric;
}
