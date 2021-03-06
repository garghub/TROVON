static guint32
dissect_fb_zero_tag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *fb_zero_tree, guint offset, guint32 tag_number){
guint32 tag_offset_start = offset + tag_number*4*2;
guint32 tag_offset = 0, total_tag_len = 0;
gint32 tag_len;
while(tag_number){
proto_tree *tag_tree, *ti_len, *ti_tag, *ti_type;
guint32 offset_end, tag;
const guint8* tag_str;
ti_tag = proto_tree_add_item(fb_zero_tree, hf_fb_zero_tags, tvb, offset, 8, ENC_NA);
tag_tree = proto_item_add_subtree(ti_tag, ett_fb_zero_tag_value);
ti_type = proto_tree_add_item_ret_string(tag_tree, hf_fb_zero_tag_type, tvb, offset, 4, ENC_ASCII|ENC_NA, wmem_packet_scope(), &tag_str);
tag = tvb_get_ntohl(tvb, offset);
proto_item_append_text(ti_type, " (%s)", val_to_str(tag, tag_vals, "Unknown"));
proto_item_append_text(ti_tag, ": %s (%s)", tag_str, val_to_str(tag, tag_vals, "Unknown"));
offset += 4;
proto_tree_add_item(tag_tree, hf_fb_zero_tag_offset_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset_end = tvb_get_letohl(tvb, offset);
tag_len = offset_end - tag_offset;
total_tag_len += tag_len;
ti_len = proto_tree_add_uint(tag_tree, hf_fb_zero_tag_length, tvb, offset, 4, tag_len);
proto_item_append_text(ti_tag, " (l=%u)", tag_len);
PROTO_ITEM_SET_GENERATED(ti_len);
offset += 4;
if( tag_len > tvb_reported_length_remaining(tvb, tag_offset_start + tag_offset)){
tag_len = tvb_reported_length_remaining(tvb, tag_offset_start + tag_offset);
offset_end = tag_offset + tag_len;
expert_add_info(pinfo, ti_len, &ei_fb_zero_tag_length);
}
proto_tree_add_item(tag_tree, hf_fb_zero_tag_value, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
switch(tag){
case TAG_SNI:
proto_tree_add_item_ret_string(tag_tree, hf_fb_zero_tag_sni, tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA, wmem_packet_scope(), &tag_str);
proto_item_append_text(ti_tag, ": %s", tag_str);
tag_offset += tag_len;
break;
case TAG_VERS:
proto_tree_add_item_ret_string(tag_tree, hf_fb_zero_tag_vers, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA, wmem_packet_scope(), &tag_str);
proto_item_append_text(ti_tag, ": %s", tag_str);
tag_offset += 4;
break;
case TAG_SNO:
proto_tree_add_item(tag_tree, hf_fb_zero_tag_sno, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
break;
case TAG_AEAD:
while(offset_end - tag_offset >= 4){
proto_tree *ti_aead;
ti_aead = proto_tree_add_item(tag_tree, hf_fb_zero_tag_aead, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_aead, " (%s)", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_aead_vals, "Unknown"));
proto_item_append_text(ti_tag, ", %s", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_aead_vals, "Unknown"));
tag_offset += 4;
}
break;
case TAG_SCID:
proto_tree_add_item(tag_tree, hf_fb_zero_tag_scid, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
break;
case TAG_TIME:
proto_tree_add_item(tag_tree, hf_fb_zero_tag_time, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_tag, ": %u", tvb_get_letohl(tvb, tag_offset_start + tag_offset));
tag_offset += 4;
break;
case TAG_ALPN:
proto_tree_add_item_ret_string(tag_tree, hf_fb_zero_tag_alpn, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA, wmem_packet_scope(), &tag_str);
proto_item_append_text(ti_tag, ": %s", tag_str);
tag_offset += 4;
break;
case TAG_PUBS:
proto_tree_add_item(tag_tree, hf_fb_zero_tag_pubs, tvb, tag_offset_start + tag_offset, 2, ENC_LITTLE_ENDIAN);
tag_offset += 2;
while(offset_end - tag_offset >= 3){
proto_tree_add_item(tag_tree, hf_fb_zero_tag_pubs, tvb, tag_offset_start + tag_offset, 3, ENC_LITTLE_ENDIAN);
tag_offset += 3;
}
break;
case TAG_KEXS:
while(offset_end - tag_offset >= 4){
proto_tree *ti_kexs;
ti_kexs = proto_tree_add_item(tag_tree, hf_fb_zero_tag_kexs, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_kexs, " (%s)", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_kexs_vals, "Unknown"));
proto_item_append_text(ti_tag, ", %s", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_kexs_vals, "Unknown"));
tag_offset += 4;
}
break;
case TAG_NONC:
proto_tree_add_item(tag_tree, hf_fb_zero_tag_nonc, tvb, tag_offset_start + tag_offset, 32, ENC_NA);
tag_offset += 32;
break;
default:
proto_tree_add_item(tag_tree, hf_fb_zero_tag_unknown, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
expert_add_info_format(pinfo, ti_tag, &ei_fb_zero_tag_undecoded,
"Dissector for FB Zero Tag"
" %s (%s) code not implemented, Contact"
" Wireshark developers if you want this supported", tvb_get_string_enc(wmem_packet_scope(), tvb, offset-8, 4, ENC_ASCII|ENC_NA), val_to_str(tag, tag_vals, "Unknown"));
tag_offset += tag_len;
break;
}
if(tag_offset != offset_end){
proto_tree_add_expert(tag_tree, pinfo, &ei_fb_zero_tag_unknown, tvb, tag_offset_start + tag_offset, offset_end - tag_offset);
tag_offset = offset_end;
}
tag_number--;
}
return offset + total_tag_len;
}
static int
dissect_fb_zero_unencrypt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *fb_zero_tree, guint offset, guint8 len_pkn _U_){
while(tvb_reported_length_remaining(tvb, offset) > 0){
proto_item *ti;
guint32 message_tag, tag_number, length;
const guint8* message_tag_str;
proto_tree_add_item(fb_zero_tree, hf_fb_zero_unknown, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item_ret_uint(fb_zero_tree, hf_fb_zero_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &length);
offset += 4;
message_tag = tvb_get_ntohl(tvb, offset);
if(try_val_to_str(message_tag, message_tag_vals)){
ti = proto_tree_add_item_ret_string(fb_zero_tree, hf_fb_zero_tag, tvb, offset, 4, ENC_ASCII|ENC_NA, wmem_packet_scope(), &message_tag_str);
proto_item_append_text(ti, ", Type: %s (%s)", message_tag_str, val_to_str(message_tag, message_tag_vals, "Unknown Tag"));
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(message_tag, message_tag_vals, "Unknown"));
offset += 4;
proto_tree_add_item(fb_zero_tree, hf_fb_zero_tag_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
tag_number = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(fb_zero_tree, hf_fb_zero_padding, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_fb_zero_tag(tvb, pinfo, fb_zero_tree, offset, tag_number);
} else {
proto_tree_add_item(fb_zero_tree, hf_fb_zero_unknown, tvb, offset, length, ENC_NA);
offset += length;
}
}
return offset;
}
static int
dissect_fb_zero_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *ti_puflags;
proto_tree *fb_zero_tree, *puflags_tree;
guint offset = 0;
guint8 puflags;
guint32 message_tag, version;
if (tvb_captured_length(tvb) < FBZERO_MIN_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FB_ZERO");
ti = proto_tree_add_item(tree, proto_fb_zero, tvb, 0, -1, ENC_NA);
fb_zero_tree = proto_item_add_subtree(ti, ett_fb_zero);
ti_puflags = proto_tree_add_item(fb_zero_tree, hf_fb_zero_puflags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
puflags_tree = proto_item_add_subtree(ti_puflags, ett_fb_zero_puflags);
proto_tree_add_item(puflags_tree, hf_fb_zero_puflags_vrsn, tvb, offset, 1, ENC_NA);
proto_tree_add_item(puflags_tree, hf_fb_zero_puflags_unknown, tvb, offset, 1, ENC_LITTLE_ENDIAN);
puflags = tvb_get_guint8(tvb, offset);
offset += 1;
if(puflags & PUFLAGS_VRSN){
version = tvb_get_ntoh24(tvb, offset);
if(version == VERSION_QTV){
proto_tree_add_item(fb_zero_tree, hf_fb_zero_version, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
}
}
message_tag = tvb_get_ntohl(tvb, offset+5);
if (message_tag == MTAG_CHLO || message_tag == MTAG_SNOM) {
offset = dissect_fb_zero_unencrypt(tvb, pinfo, fb_zero_tree, offset, 1);
}else {
col_add_str(pinfo->cinfo, COL_INFO, "Payload (Encrypted)");
proto_tree_add_item(fb_zero_tree, hf_fb_zero_payload, tvb, offset, -1, ENC_NA);
}
return offset;
}
static int
dissect_fb_zero(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
return dissect_fb_zero_common(tvb, pinfo, tree, NULL);
}
static gboolean dissect_fb_zero_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation = NULL;
int offset = 0;
guint32 version, length, message_tag;
if (tvb_reported_length(tvb) < 13)
{
return FALSE;
}
offset += 1;
version = tvb_get_ntoh24(tvb, offset);
offset += 3;
offset += 1;
length = tvb_get_letohl(tvb, offset);
offset += 4;
message_tag = tvb_get_ntohl(tvb, offset);
if ( version == VERSION_QTV && length <= tvb_reported_length(tvb) && (message_tag == MTAG_CHLO || message_tag == MTAG_SNOM)) {
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, fb_zero_handle);
dissect_fb_zero(tvb, pinfo, tree, data);
return TRUE;
}
return FALSE;
}
void
proto_register_fb_zero(void)
{
static hf_register_info hf[] = {
{ &hf_fb_zero_puflags,
{ "Public Flags", "fb_zero.puflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifying per-packet public flags", HFILL }
},
{ &hf_fb_zero_puflags_vrsn,
{ "Version", "fb_zero.puflags.version",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_VRSN,
"Signifies that this packet also contains the version of the FB Zero protocol", HFILL }
},
{ &hf_fb_zero_puflags_unknown,
{ "Unknown", "fb_zero.puflags.unknown",
FT_UINT8, BASE_HEX, NULL, PUFLAGS_UNKN,
NULL, HFILL }
},
{ &hf_fb_zero_version,
{ "Version", "fb_zero.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"32 bit opaque tag that represents the version of the ZB Zero (Always QTV)", HFILL }
},
{ &hf_fb_zero_length,
{ "Length", "fb_zero.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag,
{ "Tag", "fb_zero.tag",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_number,
{ "Tag Number", "fb_zero.tag_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tags,
{ "Tag/value", "fb_zero.tags",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_type,
{ "Tag Type", "fb_zero.tag_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_offset_end,
{ "Tag offset end", "fb_zero.tag_offset_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_length,
{ "Tag length", "fb_zero.tag_offset_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_value,
{ "Tag/value", "fb_zero.tag_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_sni,
{ "Server Name Indication", "fb_zero.tag.sni",
FT_STRING, BASE_NONE, NULL, 0x0,
"The fully qualified DNS name of the server, canonicalised to lowercase with no trailing period", HFILL }
},
{ &hf_fb_zero_tag_vers,
{ "Version", "fb_zero.tag.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"Version of FB Zero supported", HFILL }
},
{ &hf_fb_zero_tag_sno,
{ "Server nonce", "fb_zero.tag.sno",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_aead,
{ "Authenticated encryption algorithms", "fb_zero.tag.aead",
FT_STRING, BASE_NONE, NULL, 0x0,
"A list of tags, in preference order, specifying the AEAD primitives supported by the server", HFILL }
},
{ &hf_fb_zero_tag_scid,
{ "Server Config ID", "fb_zero.tag.scid",
FT_BYTES, BASE_NONE, NULL, 0x0,
"An opaque, 16-byte identifier for this server config", HFILL }
},
{ &hf_fb_zero_tag_time,
{ "Time", "fb_zero.tag.time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_tag_alpn,
{ "ALPN", "fb_zero.tag.alpn",
FT_STRING, BASE_NONE, NULL, 0x0,
"Application-Layer Protocol Negotiation supported", HFILL }
},
{ &hf_fb_zero_tag_pubs,
{ "Public value", "fb_zero.tag.pubs",
FT_UINT24, BASE_DEC_HEX, NULL, 0x0,
"A list of public values, 24-bit, little-endian length prefixed", HFILL }
},
{ &hf_fb_zero_tag_kexs,
{ "Key exchange algorithms", "fb_zero.tag.kexs",
FT_STRING, BASE_NONE, NULL, 0x0,
"A list of tags, in preference order, specifying the key exchange algorithms that the server supports", HFILL }
},
{ &hf_fb_zero_tag_nonc,
{ "Client nonce", "fb_zero.tag.nonc",
FT_BYTES, BASE_NONE, NULL, 0x0,
"32 bytes consisting of 4 bytes of timestamp (big-endian, UNIX epoch seconds), 8 bytes of server orbit and 20 bytes of random data", HFILL }
},
{ &hf_fb_zero_tag_unknown,
{ "Unknown tag", "fb_zero.tag.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_padding,
{ "Padding", "fb_zero.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fb_zero_payload,
{ "Payload", "fb_zero.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Fb Zero Payload..", HFILL }
},
{ &hf_fb_zero_unknown,
{ "Unknown", "fb_zero.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Unknown Data", HFILL }
},
};
static gint *ett[] = {
&ett_fb_zero,
&ett_fb_zero_puflags,
&ett_fb_zero_prflags,
&ett_fb_zero_ft,
&ett_fb_zero_ftflags,
&ett_fb_zero_tag_value
};
static ei_register_info ei[] = {
{ &ei_fb_zero_tag_undecoded, { "fb_zero.tag.undecoded", PI_UNDECODED, PI_NOTE, "Dissector for FB Zero Tag code not implemented, Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_fb_zero_tag_length, { "fb_zero.tag.length.truncated", PI_MALFORMED, PI_NOTE, "Truncated Tag Length...", EXPFILL }},
{ &ei_fb_zero_tag_unknown, { "fb_zero.tag.unknown.data", PI_UNDECODED, PI_NOTE, "Unknown Data", EXPFILL }},
};
expert_module_t *expert_fb_zero;
proto_fb_zero = proto_register_protocol("(Facebook) Zero Protocol", "FBZERO", "fb_zero");
fb_zero_handle = register_dissector("fb_zero", dissect_fb_zero, proto_fb_zero);
proto_register_field_array(proto_fb_zero, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_fb_zero = expert_register_protocol(proto_fb_zero);
expert_register_field_array(expert_fb_zero, ei, array_length(ei));
}
void
proto_reg_handoff_fb_zero(void)
{
heur_dissector_add("tcp", dissect_fb_zero_heur, "FBZero (QUIC) over TCP", "fb_zero", proto_fb_zero, HEURISTIC_ENABLE);
}
