static int
dissect_sstp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint16 sstp_control_flag;
guint32 offset = 0;
guint8 sstp_major;
guint8 sstp_minor;
proto_item *ti;
proto_tree *sstp_tree;
proto_tree *sstp_tree_attribute;
proto_tree *sstp_tree_version;
guint16 sstp_numattrib;
tvbuff_t *tvb_next;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SSTP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_sstp, tvb, 0, -1, ENC_NA);
sstp_tree = proto_item_add_subtree(ti, ett_sstp);
sstp_control_flag = tvb_get_guint8(tvb, SSTP_OFFSET_ISCONTROL) & SSTP_BITMASK_CONTROLFLAG;
sstp_minor = (tvb_get_guint8(tvb, SSTP_OFFSET_MINORVERSION) & SSTP_BITMASK_MINORVERSION);
sstp_major = (tvb_get_guint8(tvb, SSTP_OFFSET_MAJORVERSION) >> 4);
col_append_fstr(pinfo->cinfo, COL_INFO, "SSTP-%u.%u ", sstp_major, sstp_minor);
sstp_tree_version = proto_tree_add_subtree_format(sstp_tree, tvb, offset, SSTP_FSIZE_MAJORVERSION, ett_sstp_version,
NULL, "Version %d.%d", sstp_major, sstp_minor);
proto_tree_add_item(sstp_tree_version, hf_sstp_major, tvb, SSTP_OFFSET_MAJORVERSION, SSTP_FSIZE_MAJORVERSION, ENC_BIG_ENDIAN);
proto_tree_add_item(sstp_tree_version, hf_sstp_minor, tvb, SSTP_OFFSET_MINORVERSION, SSTP_FSIZE_MINORVERSION, ENC_BIG_ENDIAN);
proto_tree_add_item(sstp_tree, hf_sstp_reserved, tvb, SSTP_OFFSET_RESERVED, SSTP_FSIZE_RESERVED, ENC_NA);
proto_tree_add_item(sstp_tree, hf_sstp_control_flag, tvb, SSTP_OFFSET_ISCONTROL, SSTP_FSIZE_ISCONTROL, ENC_BIG_ENDIAN);
proto_tree_add_item(sstp_tree, hf_sstp_length, tvb, SSTP_OFFSET_LENGTH, SSTP_FSIZE_LENGTH, ENC_BIG_ENDIAN);
if (sstp_control_flag) {
guint16 sstp_messagetype = tvb_get_guint16(tvb, SSTP_OFFSET_MSGTYPE, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "Type: CONTROL, %s; ", val_to_str(sstp_messagetype, sstp_messagetypes, "Unknown Messagetype"));
proto_tree_add_item(sstp_tree, hf_sstp_messagetype, tvb, SSTP_OFFSET_MSGTYPE, SSTP_FSIZE_MSGTYPE, ENC_BIG_ENDIAN);
proto_tree_add_item(sstp_tree, hf_sstp_numattrib, tvb, SSTP_OFFSET_NUMATTRIB, SSTP_FSIZE_NUMATTRIB, ENC_BIG_ENDIAN);
sstp_numattrib = tvb_get_ntohs(tvb, SSTP_OFFSET_NUMATTRIB);
if (sstp_numattrib > 0) {
guint16 attrib_length = 0;
guint8 attrib_id = 0;
guint8 hashproto = 0;
offset = SSTP_OFFSET_ATTRIBUTES;
for(;sstp_numattrib > 0; sstp_numattrib--) {
attrib_id = tvb_get_guint8(tvb, offset+1);
sstp_tree_attribute = proto_tree_add_subtree_format(sstp_tree, tvb, offset, SSTP_FSIZE_ATTRIB_RESERVED, ett_sstp_attribute,
NULL, "Attribute %s", val_to_str(attrib_id, sstp_attributes, "Unknown Attribute"));
proto_tree_add_item(sstp_tree_attribute, hf_sstp_attrib_reserved, tvb, offset, SSTP_FSIZE_ATTRIB_RESERVED, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_attrib_id, tvb, offset, SSTP_FSIZE_ATTRIB_ID, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_attrib_length_reserved, tvb, offset, SSTP_FSIZE_ATTRIB_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(sstp_tree_attribute, hf_sstp_attrib_length, tvb, offset, SSTP_FSIZE_ATTRIB_LENGTH, ENC_BIG_ENDIAN);
attrib_length = (tvb_get_ntohs(tvb, offset) & SSTP_BITMASK_LENGTH_LENGTH);
if (attrib_length >= 4) {
attrib_length -= 4;
}
offset += 2;
switch(attrib_id) {
case SSTP_ATTRIB_ENCAPSULATED_PROTOCOL_ID:
proto_tree_add_item(sstp_tree_attribute, hf_sstp_ecapsulated_protocol, tvb, offset, SSTP_FSIZE_ENCAPSULATED_PROTOCOL, ENC_BIG_ENDIAN);
offset += SSTP_FSIZE_ENCAPSULATED_PROTOCOL;
break;
case SSTP_ATTRIB_STATUS_INFO:
proto_tree_add_item(sstp_tree_attribute, hf_sstp_reserved, tvb, offset, SSTP_FSIZE_RESERVED2, ENC_NA);
offset += SSTP_FSIZE_RESERVED2;
attrib_length -= SSTP_FSIZE_RESERVED2;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_attrib_id, tvb, offset, SSTP_FSIZE_ATTRIB_ID, ENC_BIG_ENDIAN);
offset += SSTP_FSIZE_ATTRIB_ID;
attrib_length -= SSTP_FSIZE_ATTRIB_ID;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_status, tvb, offset, SSTP_FSIZE_STATUS, ENC_BIG_ENDIAN);
offset += SSTP_FSIZE_STATUS;
attrib_length -= SSTP_FSIZE_STATUS;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_attrib_value, tvb, offset, attrib_length, ENC_NA);
offset += attrib_length;
break;
case SSTP_ATTRIB_CRYPTO_BINDING:
proto_tree_add_item(sstp_tree_attribute, hf_sstp_reserved, tvb, offset, SSTP_FSIZE_RESERVED2, ENC_NA);
offset += SSTP_FSIZE_RESERVED2;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_hash_protocol, tvb, offset, SSTP_FSIZE_HASH_PROTOCOL, ENC_BIG_ENDIAN);
hashproto = tvb_get_guint8(tvb, offset);
offset += SSTP_FSIZE_HASH_PROTOCOL;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_nonce, tvb, offset, SSTP_FSIZE_NONCE, ENC_NA);
offset += SSTP_FSIZE_NONCE;
if (hashproto == SSTP_CERT_HASH_PROTOCOL_SHA1) {
proto_tree_add_item(sstp_tree_attribute, hf_sstp_cert_hash, tvb, offset, SSTP_FSIZE_CERT_HASH_SHA1, ENC_NA);
offset += SSTP_FSIZE_CERT_HASH_SHA1;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_padding, tvb, offset, SSTP_FSIZE_PADDING_SHA1, ENC_NA);
offset += SSTP_FSIZE_PADDING_SHA1;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_compound_mac, tvb, offset, SSTP_FSIZE_COMPOUND_MAC_SHA1, ENC_NA);
offset += SSTP_FSIZE_COMPOUND_MAC_SHA1;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_padding, tvb, offset, SSTP_FSIZE_PADDING_SHA1, ENC_NA);
offset += SSTP_FSIZE_PADDING_SHA1;
}
if (hashproto == SSTP_CERT_HASH_PROTOCOL_SHA256) {
proto_tree_add_item(sstp_tree_attribute, hf_sstp_cert_hash, tvb, offset, SSTP_FSIZE_CERT_HASH_SHA256, ENC_NA);
offset += SSTP_FSIZE_CERT_HASH_SHA256;
}
break;
case SSTP_ATTRIB_CRYPTO_BINDING_REQ:
proto_tree_add_item(sstp_tree_attribute, hf_sstp_reserved, tvb, offset, SSTP_FSIZE_RESERVED2, ENC_NA);
offset += SSTP_FSIZE_RESERVED2;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_hash_protocol, tvb, offset, SSTP_FSIZE_HASH_PROTOCOL, ENC_BIG_ENDIAN);
offset += SSTP_FSIZE_HASH_PROTOCOL;
proto_tree_add_item(sstp_tree_attribute, hf_sstp_nonce, tvb, offset, SSTP_FSIZE_NONCE, ENC_NA);
offset += SSTP_FSIZE_NONCE;
break;
}
}
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(sstp_tree, hf_sstp_data_unknown, tvb, offset, -1, ENC_NA);
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "Type: DATA; ");
tvb_next = tvb_new_subset_remaining(tvb, SSTP_OFFSET_DATA);
call_dissector(ppp_handle, tvb_next, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static guint
get_sstp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohs(tvb, offset+SSTP_OFFSET_LENGTH);
}
static void
dissect_sstp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, SSTP_OFFSET_LENGTH+SSTP_FSIZE_LENGTH, get_sstp_pdu_len, dissect_sstp_pdu, NULL);
}
void
proto_register_sstp(void)
{
static hf_register_info hf[] = {
{ &hf_sstp_major,
{ "Major Version", "sstp.majorversion",
FT_UINT8, BASE_DEC,
NULL, SSTP_BITMASK_MAJORVERSION,
NULL, HFILL }
},
{ &hf_sstp_minor,
{ "Minor Version", "sstp.minorversion",
FT_UINT8, BASE_DEC,
NULL, SSTP_BITMASK_MINORVERSION,
NULL, HFILL }
},
{ &hf_sstp_reserved,
{ "Reserved", "sstp.reserved",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_control_flag,
{ "Control Packet", "sstp.iscontrol",
FT_BOOLEAN, 8,
NULL, SSTP_BITMASK_CONTROLFLAG,
NULL, HFILL }
},
{ &hf_sstp_length,
{ "Length-Packet", "sstp.length",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_messagetype,
{ "Message Type", "sstp.messagetype",
FT_UINT16, BASE_HEX,
VALS(sstp_messagetypes), 0x0,
NULL, HFILL }
},
{ &hf_sstp_numattrib,
{ "Number of Attributes", "sstp.numattrib",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_attrib_reserved,
{ "Reserved", "sstp.attribreserved",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_attrib_id,
{ "ID", "sstp.attribid",
FT_UINT8, BASE_DEC,
VALS(sstp_attributes), 0x0,
NULL, HFILL }
},
{ &hf_sstp_attrib_length_reserved,
{ "Reserved", "sstp.attriblengthreserved",
FT_UINT16, BASE_HEX,
NULL, SSTP_BITMASK_LENGTH_RESERVED,
NULL, HFILL }
},
{ &hf_sstp_attrib_length,
{ "Length", "sstp.attriblength",
FT_UINT16, BASE_DEC,
NULL, SSTP_BITMASK_LENGTH_LENGTH,
NULL, HFILL }
},
{ &hf_sstp_data_unknown,
{ "Unknown Data", "sstp.dataunknown",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_hash_protocol,
{ "Hash Protocol", "sstp.hash",
FT_UINT8, BASE_HEX,
VALS(hash_protocols), 0x0,
NULL, HFILL }
},
{ &hf_sstp_nonce,
{ "Nonce", "sstp.nonce",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_cert_hash,
{ "Cert Hash", "sstp.cert_hash",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_padding,
{ "Padding", "sstp.padding",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_compound_mac,
{ "Compound Mac", "sstp.compoundmac",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_sstp_ecapsulated_protocol,
{ "Encapsulated Procotol", "sstp.encapsulatedprotocol",
FT_UINT16, BASE_HEX,
VALS(encapsulated_protocols), 0x0,
NULL, HFILL }
},
{ &hf_sstp_status,
{ "Status", "sstp.status",
FT_UINT32, BASE_HEX,
VALS(attrib_status), 0x0,
NULL, HFILL }
},
{ &hf_sstp_attrib_value,
{ "Attribute Value", "sstp.attribvalue",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_sstp,
&ett_sstp_attribute,
&ett_sstp_version
};
proto_sstp = proto_register_protocol("Secure Socket Tunneling Protocol", "SSTP", "sstp");
register_dissector("sstp", dissect_sstp, proto_sstp);
proto_register_field_array(proto_sstp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_sstp(void)
{
ppp_handle = find_dissector("ppp");
}
