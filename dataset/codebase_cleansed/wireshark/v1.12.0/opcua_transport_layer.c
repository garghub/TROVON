void registerTransportLayerTypes(int proto)
{
static hf_register_info hf[] =
{
{ &hf_opcua_transport_type,
{ "Message Type", "transport.type", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_chunk,
{ "Chunk Type", "transport.chunk", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_size,
{ "Message Size", "transport.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_ver,
{ "Version", "transport.ver", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_scid,
{ "SecureChannelId", "transport.scid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#if 0
{ &hf_opcua_transport_lifetime,
{ "Lifetime", "transport.lifetime", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_opcua_transport_rbs,
{ "ReceiveBufferSize", "transport.rbs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_sbs,
{ "SendBufferSize", "transport.sbs", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_mms,
{ "MaxMessageSize", "transport.mms", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_mcc,
{ "MaxChunkCount", "transport.mcc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_endpoint,
{ "EndPointUrl", "transport.endpoint", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_error,
{ "Error", "transport.error", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_reason,
{ "Reason", "transport.reason", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_spu,
{ "SecurityPolicyUri", "security.spu", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_scert,
{ "SenderCertificate", "security.scert", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_rcthumb,
{ "ReceiverCertificateThumbprint", "security.rcthumb", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_seq,
{ "SequenceNumber", "security.seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_transport_rqid,
{ "RequestId", "security.rqid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
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
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "OpcUa Service : Encodeable Object");
encobj_tree = proto_item_add_subtree(ti, ett_opcua_extensionobject);
ti_inner = proto_tree_add_text(encobj_tree, tvb, *pOffset, -1, "TypeId : ExpandedNodeId");
nodeid_tree = proto_item_add_subtree(ti_inner, ett_opcua_nodeid);
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
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "Message : Encodeable Object");
encobj_tree = proto_item_add_subtree(ti, ett_opcua_extensionobject);
ti_inner = proto_tree_add_text(encobj_tree, tvb, *pOffset, -1, "TypeId : ExpandedNodeId");
nodeid_tree = proto_item_add_subtree(ti_inner, ett_opcua_nodeid);
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
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "Message : Encodeable Object");
encobj_tree = proto_item_add_subtree(ti, ett_opcua_extensionobject);
ti_inner = proto_tree_add_text(encobj_tree, tvb, *pOffset, -1, "TypeId : ExpandedNodeId");
nodeid_tree = proto_item_add_subtree(ti_inner, ett_opcua_nodeid);
ServiceId = parseServiceNodeId(nodeid_tree, tvb, pOffset);
proto_item_set_end(ti_inner, tvb, *pOffset);
dispatchService(encobj_tree, tvb, pOffset, ServiceId);
proto_item_set_end(ti, tvb, *pOffset);
return ServiceId;
}
