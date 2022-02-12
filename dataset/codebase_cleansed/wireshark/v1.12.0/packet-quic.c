static int
dissect_quic_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *ti_puflags;
proto_tree *quic_tree, *puflags_tree;
guint offset = 0;
guint8 puflags, len_cid, len_seq;
guint64 cid, seq;
if (tvb_length(tvb) < QUIC_MIN_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "QUIC");
ti = proto_tree_add_item(tree, proto_quic, tvb, 0, -1, ENC_NA);
quic_tree = proto_item_add_subtree(ti, ett_quic);
ti_puflags = proto_tree_add_item(quic_tree, hf_quic_puflags, tvb, offset, 1, ENC_NA);
puflags_tree = proto_item_add_subtree(ti_puflags, ett_quic_puflags);
proto_tree_add_item(puflags_tree, hf_quic_puflags_vrsn, tvb, offset, 1, ENC_NA);
proto_tree_add_item(puflags_tree, hf_quic_puflags_rst, tvb, offset, 1, ENC_NA);
proto_tree_add_item(puflags_tree, hf_quic_puflags_cid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(puflags_tree, hf_quic_puflags_seq, tvb, offset, 1, ENC_NA);
proto_tree_add_item(puflags_tree, hf_quic_puflags_rsv, tvb, offset, 1, ENC_NA);
puflags = tvb_get_guint8(tvb, offset);
offset += 1;
switch((puflags & PUFLAGS_CID) >> 2){
case 0:
len_cid = 0;
cid = 0;
break;
case 1:
len_cid = 1;
cid = tvb_get_guint8(tvb, offset);
break;
case 2:
len_cid = 4;
cid = tvb_get_letohl(tvb, offset);
break;
case 3:
len_cid = 8;
cid = tvb_get_letoh64(tvb, offset);
break;
default:
len_cid = 8;
cid = tvb_get_letoh64(tvb, offset);
break;
}
if (len_cid) {
proto_tree_add_item(quic_tree, hf_quic_cid, tvb, offset, len_cid, ENC_LITTLE_ENDIAN);
offset += len_cid;
}
if(puflags & PUFLAGS_VRSN){
proto_tree_add_item(quic_tree, hf_quic_version, tvb, offset, 4, ENC_ASCII||ENC_NA);
offset += 4;
}
switch((puflags & PUFLAGS_SEQ) >> 4){
case 0:
len_seq = 1;
seq = tvb_get_guint8(tvb, offset);
break;
case 1:
len_seq = 2;
seq = tvb_get_letohs(tvb, offset);
break;
case 2:
len_seq = 4;
seq = tvb_get_letohl(tvb, offset);
break;
case 3:
len_seq = 6;
seq = tvb_get_letoh48(tvb, offset);
break;
default:
len_seq = 6;
seq = tvb_get_letoh48(tvb, offset);
break;
}
proto_tree_add_item(quic_tree, hf_quic_sequence, tvb, offset, len_seq, ENC_LITTLE_ENDIAN);
offset += len_seq;
col_add_fstr(pinfo->cinfo, COL_INFO, "CID: %" G_GINT64_MODIFIER "u, Seq: %" G_GINT64_MODIFIER "u", cid, seq);
#if 0
ti_prflags = proto_tree_add_item(quic_tree, hf_quic_prflags, tvb, offset, 1, ENC_NA);
prflags_tree = proto_item_add_subtree(ti_prflags, ett_quic_prflags);
proto_tree_add_item(prflags_tree, hf_quic_prflags_entropy, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_fecg, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_fec, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_rsv, tvb, offset, 1, ENC_NA);
offset +=1;
#endif
proto_tree_add_item(quic_tree, hf_quic_payload, tvb, offset, -1, ENC_NA);
return offset;
}
static int
dissect_quic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
return dissect_quic_common(tvb, pinfo, tree, NULL);
}
static int
dissect_quics(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
return dissect_quic_common(tvb, pinfo, tree, NULL);
}
void
proto_register_quic(void)
{
module_t *quic_module;
static hf_register_info hf[] = {
{ &hf_quic_puflags,
{ "Public Flags", "quic.puflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifying per-packet public flags", HFILL }
},
{ &hf_quic_puflags_vrsn,
{ "Version", "quic.puflags.version",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_VRSN,
"Signifies that this packet also contains the version of the QUIC protocol", HFILL }
},
{ &hf_quic_puflags_rst,
{ "Reset", "quic.puflags.reset",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_RST,
"Signifies that this packet is a public reset packet", HFILL }
},
{ &hf_quic_puflags_cid,
{ "CID Length", "quic.puflags.cid",
FT_UINT8, BASE_HEX, VALS(puflags_cid_vals), PUFLAGS_CID,
"Signifies the Length of CID", HFILL }
},
{ &hf_quic_puflags_seq,
{ "Sequence Length", "quic.puflags.seq",
FT_UINT8, BASE_HEX, VALS(puflags_seq_vals), PUFLAGS_SEQ,
"Signifies the Length of Sequence", HFILL }
},
{ &hf_quic_puflags_rsv,
{ "Reserved", "quic.puflags.rsv",
FT_UINT8, BASE_HEX, NULL, PUFLAGS_RSV,
"Must be Zero", HFILL }
},
{ &hf_quic_cid,
{ "CID", "quic.cid",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Connection ID 64 bit pseudo random number", HFILL }
},
{ &hf_quic_version,
{ "Version", "quic.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"32 bit opaque tag that represents the version of the QUIC", HFILL }
},
{ &hf_quic_sequence,
{ "Sequence", "quic.sequence",
FT_UINT64, BASE_DEC, NULL, 0x0,
"The lower 8, 16, 32, or 48 bits of the sequence number", HFILL }
},
#if 0
{ &hf_quic_prflags,
{ "Private Flags", "quic.prflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifying per-packet Private flags", HFILL }
},
{ &hf_quic_prflags_entropy,
{ "Entropy", "quic.prflags.entropy",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_ENTROPY,
"For data packets, signifies that this packet contains the 1 bit of entropy, for fec packets, contains the xor of the entropy of protected packets", HFILL }
},
{ &hf_quic_prflags_fecg,
{ "FEC Group", "quic.prflags.fecg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_FECG,
"Indicates whether the fec byte is present.", HFILL }
},
{ &hf_quic_prflags_fec,
{ "FEC", "quic.prflags.fec",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_FEC,
"Signifies that this packet represents an FEC packet", HFILL }
},
{ &hf_quic_prflags_rsv,
{ "Reserved", "quic.prflags.rsv",
FT_UINT8, BASE_HEX, NULL, PRFLAGS_RSV,
"Must be Zero", HFILL }
},
#endif
{ &hf_quic_payload,
{ "Payload", "quic.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Quic Payload..", HFILL }
},
};
static gint *ett[] = {
&ett_quic,
&ett_quic_puflags,
&ett_quic_prflags
};
proto_quic = proto_register_protocol("QUIC (Quick UDP Internet Connections)",
"QUIC", "quic");
proto_register_field_array(proto_quic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
quic_module = prefs_register_protocol(proto_quic, proto_reg_handoff_quic);
prefs_register_uint_preference(quic_module, "udp.quic.port", "QUIC UDP Port",
"QUIC UDP port if other than the default",
10, &g_quic_port);
prefs_register_uint_preference(quic_module, "udp.quics.port", "QUICS UDP Port",
"QUICS (Secure) UDP port if other than the default",
10, &g_quics_port);
}
void
proto_reg_handoff_quic(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t quic_handle;
static dissector_handle_t quics_handle;
static int current_quic_port;
static int current_quics_port;
if (!initialized) {
quic_handle = new_create_dissector_handle(dissect_quic,
proto_quic);
quics_handle = new_create_dissector_handle(dissect_quics,
proto_quic);
initialized = TRUE;
} else {
dissector_delete_uint("udp.port", current_quic_port, quic_handle);
dissector_delete_uint("udp.port", current_quics_port, quics_handle);
}
current_quic_port = g_quic_port;
current_quics_port = g_quics_port;
dissector_add_uint("udp.port", current_quic_port, quic_handle);
dissector_add_uint("udp.port", current_quics_port, quics_handle);
}
