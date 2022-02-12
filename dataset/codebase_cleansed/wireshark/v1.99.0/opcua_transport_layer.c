void registerTransportLayerTypes(int proto)
{
static hf_register_info hf[] =
{
{&hf_opcua_transport_type, {"Message Type", "opcua.transport.type", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_chunk, {"Chunk Type", "opcua.transport.chunk", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_size, {"Message Size", "opcua.transport.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_ver, {"Version", "opcua.transport.ver", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_scid, {"SecureChannelId", "opcua.transport.scid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_rbs, {"ReceiveBufferSize", "opcua.transport.rbs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_sbs, {"SendBufferSize", "opcua.transport.sbs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_mms, {"MaxMessageSize", "opcua.transport.mms", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_mcc, {"MaxChunkCount", "opcua.transport.mcc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_endpoint, {"EndPointUrl", "opcua.transport.endpoint", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_error, {"Error", "opcua.transport.error", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_reason, {"Reason", "opcua.transport.reason", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_spu, {"SecurityPolicyUri", "opcua.security.spu", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_scert, {"SenderCertificate", "opcua.security.scert", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_rcthumb, {"ReceiverCertificateThumbprint", "opcua.security.rcthumb", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_seq, {"SequenceNumber", "opcua.security.seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_opcua_transport_rqid, {"RequestId", "opcua.security.rqid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
};
proto_register_field_array(proto, hf, array_length(hf));
}
int parseHello(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_transport_type, tvb, *pOffset, 3, ENC_ASCII|ENC_NA); *pOffset+=3;
proto_tree_add_item(tree, hf_opcua_transport_chunk, tvb, *pOffset, 1, ENC_ASCII|ENC_NA); *pOffset+=1;
proto_tree_add_item(tree, hf_opcua_transport_size, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_ver, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_rbs, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_sbs, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_mms, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_mcc, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
parseString(tree, tvb, pOffset, hf_opcua_transport_endpoint);
return -1;
}
int parseAcknowledge(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_transport_type, tvb, *pOffset, 3, ENC_ASCII|ENC_NA); *pOffset+=3;
proto_tree_add_item(tree, hf_opcua_transport_chunk, tvb, *pOffset, 1, ENC_ASCII|ENC_NA); *pOffset+=1;
proto_tree_add_item(tree, hf_opcua_transport_size, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_ver, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_rbs, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_sbs, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_mms, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_mcc, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
return -1;
}
int parseError(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_transport_type, tvb, *pOffset, 3, ENC_ASCII|ENC_NA); *pOffset+=3;
proto_tree_add_item(tree, hf_opcua_transport_chunk, tvb, *pOffset, 1, ENC_ASCII|ENC_NA); *pOffset+=1;
proto_tree_add_item(tree, hf_opcua_transport_size, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_error, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
parseString(tree, tvb, pOffset, hf_opcua_transport_reason);
return -1;
}
int parseMessage(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_tree_add_item(tree, hf_opcua_transport_type, tvb, *pOffset, 3, ENC_ASCII|ENC_NA); *pOffset+=3;
proto_tree_add_item(tree, hf_opcua_transport_chunk, tvb, *pOffset, 1, ENC_ASCII|ENC_NA); *pOffset+=1;
proto_tree_add_item(tree, hf_opcua_transport_size, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_scid, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
parseSecurityLayer(tree, tvb, pOffset);
return -1;
}
int parseService(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti;
proto_item *ti_inner;
proto_tree *encobj_tree;
proto_tree *nodeid_tree;
int ServiceId = 0;
encobj_tree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_extensionobject, &ti, "OpcUa Service : Encodeable Object");
nodeid_tree = proto_tree_add_subtree(encobj_tree, tvb, *pOffset, -1, ett_opcua_nodeid, &ti_inner, "TypeId : ExpandedNodeId");
ServiceId = parseServiceNodeId(nodeid_tree, tvb, pOffset);
proto_item_set_end(ti_inner, tvb, *pOffset);
dispatchService(encobj_tree, tvb, pOffset, ServiceId);
proto_item_set_end(ti, tvb, *pOffset);
return ServiceId;
}
int parseOpenSecureChannel(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti;
proto_item *ti_inner;
proto_tree *encobj_tree;
proto_tree *nodeid_tree;
int ServiceId = 0;
proto_tree_add_item(tree, hf_opcua_transport_type, tvb, *pOffset, 3, ENC_ASCII|ENC_NA); *pOffset+=3;
proto_tree_add_item(tree, hf_opcua_transport_chunk, tvb, *pOffset, 1, ENC_ASCII|ENC_NA); *pOffset+=1;
proto_tree_add_item(tree, hf_opcua_transport_size, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_scid, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
parseString(tree, tvb, pOffset, hf_opcua_transport_spu);
parseByteString(tree, tvb, pOffset, hf_opcua_transport_scert);
parseByteString(tree, tvb, pOffset, hf_opcua_transport_rcthumb);
proto_tree_add_item(tree, hf_opcua_transport_seq, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_rqid, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
encobj_tree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_extensionobject, &ti, "Message : Encodeable Object");
nodeid_tree = proto_tree_add_subtree(encobj_tree, tvb, *pOffset, -1, ett_opcua_nodeid, &ti_inner, "TypeId : ExpandedNodeId");
ServiceId = parseServiceNodeId(nodeid_tree, tvb, pOffset);
proto_item_set_end(ti_inner, tvb, *pOffset);
dispatchService(encobj_tree, tvb, pOffset, ServiceId);
proto_item_set_end(ti, tvb, *pOffset);
return ServiceId;
}
int parseCloseSecureChannel(proto_tree *tree, tvbuff_t *tvb, gint *pOffset)
{
proto_item *ti;
proto_item *ti_inner;
proto_tree *encobj_tree;
proto_tree *nodeid_tree;
int ServiceId = 0;
proto_tree_add_item(tree, hf_opcua_transport_type, tvb, *pOffset, 3, ENC_ASCII|ENC_NA); *pOffset+=3;
proto_tree_add_item(tree, hf_opcua_transport_chunk, tvb, *pOffset, 1, ENC_ASCII|ENC_NA); *pOffset+=1;
proto_tree_add_item(tree, hf_opcua_transport_size, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
proto_tree_add_item(tree, hf_opcua_transport_scid, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
parseSecurityLayer(tree, tvb, pOffset);
encobj_tree = proto_tree_add_subtree(tree, tvb, *pOffset, -1, ett_opcua_extensionobject, &ti, "Message : Encodeable Object");
nodeid_tree = proto_tree_add_subtree(encobj_tree, tvb, *pOffset, -1, ett_opcua_nodeid, &ti_inner, "TypeId : ExpandedNodeId");
ServiceId = parseServiceNodeId(nodeid_tree, tvb, pOffset);
proto_item_set_end(ti_inner, tvb, *pOffset);
dispatchService(encobj_tree, tvb, pOffset, ServiceId);
proto_item_set_end(ti, tvb, *pOffset);
return ServiceId;
}
