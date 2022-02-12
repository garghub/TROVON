int
dissect_igap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, int offset)
{
proto_tree *tree;
proto_item *item;
guint8 type, tsecs, subtype, asize, msize;
guchar account[ACCOUNT_SIZE+1], message[MESSAGE_SIZE+1];
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_igap))) {
return offset + tvb_length_remaining(tvb, offset);
}
item = proto_tree_add_item(parent_tree, proto_igap, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_igap);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IGAP");
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, igap_types, "Unknown Type: 0x%02x"));
}
proto_tree_add_uint(tree, hf_type, tvb, offset, 1, type);
offset += 1;
tsecs = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_max_resp, tvb, offset, 1, tsecs,
"Max Response Time: %.1f sec (0x%02x)", tsecs * 0.1, tsecs);
offset += 1;
igmp_checksum(tree, tvb, hf_checksum, hf_checksum_bad, pinfo, 0);
offset += 2;
proto_tree_add_item(tree, hf_maddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_uint(tree, hf_version, tvb, offset, 1,
tvb_get_guint8(tvb, offset));
offset += 1;
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_subtype, tvb, offset, 1, subtype);
offset += 2;
proto_tree_add_uint(tree, hf_challengeid, tvb, offset, 1,
tvb_get_guint8(tvb, offset));
offset += 1;
asize = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_asize, tvb, offset, 1, asize);
offset += 1;
msize = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_msize, tvb, offset, 1, msize);
offset += 3;
if (asize > 0) {
if (asize > ACCOUNT_SIZE) {
asize = ACCOUNT_SIZE;
}
tvb_memcpy(tvb, account, offset, asize);
account[asize] = '\0';
proto_tree_add_string(tree, hf_account, tvb, offset, asize, account);
}
offset += ACCOUNT_SIZE;
if (msize > 0) {
if (msize > MESSAGE_SIZE) {
msize = MESSAGE_SIZE;
}
tvb_memcpy(tvb, message, offset, msize);
switch (subtype) {
case IGAP_SUBTYPE_PASSWORD_JOIN:
case IGAP_SUBTYPE_PASSWORD_LEAVE:
message[msize] = '\0';
proto_tree_add_text(tree, tvb, offset, msize,
"User password: %s", message);
break;
case IGAP_SUBTYPE_CHALLENGE_RESPONSE_JOIN:
case IGAP_SUBTYPE_CHALLENGE_RESPONSE_LEAVE:
proto_tree_add_text(tree, tvb, offset, msize,
"Result of MD5 calculation: 0x%s",
bytes_to_str(message, msize));
break;
case IGAP_SUBTYPE_CHALLENGE:
proto_tree_add_text(tree, tvb, offset, msize,
"Challenge: 0x%s",
bytes_to_str(message, msize));
break;
case IGAP_SUBTYPE_AUTH_MESSAGE:
proto_tree_add_text(tree, tvb, offset, msize,
"Authentication result: %s (0x%x)",
val_to_str(message[0], igap_auth_result,
"Unknown"), message[0]);
break;
case IGAP_SUBTYPE_ACCOUNTING_MESSAGE:
proto_tree_add_text(tree, tvb, offset, msize,
"Accounting status: %s (0x%x)",
val_to_str(message[0], igap_account_status,
"Unknown"), message[0]);
break;
default:
proto_tree_add_text(tree, tvb, offset, msize,
"Message: (Unknown)");
}
}
offset += MESSAGE_SIZE;
if (item) proto_item_set_len(item, offset);
return offset;
}
void
proto_register_igap(void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "igap.type", FT_UINT8, BASE_HEX,
VALS(igap_types), 0, "IGAP Packet Type", HFILL }
},
{ &hf_max_resp,
{ "Max Resp Time", "igap.max_resp", FT_UINT8, BASE_DEC,
NULL, 0, "Max Response Time", HFILL }
},
{ &hf_checksum,
{ "Checksum", "igap.checksum", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_checksum_bad,
{ "Bad Checksum", "igap.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_maddr,
{ "Multicast group address", "igap.maddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_version,
{ "Version", "igap.version", FT_UINT8, BASE_HEX,
VALS(igap_version), 0, "IGAP protocol version", HFILL }
},
{ &hf_subtype,
{ "Subtype", "igap.subtype", FT_UINT8, BASE_HEX,
VALS(igap_subtypes), 0, NULL, HFILL }
},
{ &hf_challengeid,
{ "Challenge ID", "igap.challengeid", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_asize,
{ "Account Size", "igap.asize", FT_UINT8, BASE_DEC,
NULL, 0, "Length of the User Account field", HFILL }
},
{ &hf_msize,
{ "Message Size", "igap.msize", FT_UINT8, BASE_DEC,
NULL, 0, "Length of the Message field", HFILL }
},
{ &hf_account,
{ "User Account", "igap.account", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_igap
};
proto_igap = proto_register_protocol
("Internet Group membership Authentication Protocol",
"IGAP", "igap");
proto_register_field_array(proto_igap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
