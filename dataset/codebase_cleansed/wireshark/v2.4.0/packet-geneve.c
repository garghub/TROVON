static const char *
format_unknown_option_name(guint16 opt_class, guint8 opt_type)
{
const char *name;
name = wmem_strdup_printf(wmem_packet_scope(),
"Unknown, Class: %s (0x%04x) Type: 0x%02x",
rval_to_str_const(opt_class, class_id_names, "Unknown"),
opt_class, opt_type);
return name;
}
static void
dissect_unknown_option(tvbuff_t *tvb, proto_tree *opts_tree, int offset,
guint16 opt_class, guint8 opt_type, int len)
{
proto_item *opt_item, *type_item, *hidden_item, *flag_item;
proto_tree *opt_tree, *flag_tree;
const char *critical;
guint8 flags;
critical = opt_type & OPT_TYPE_CRITICAL ? "Critical" : "Non-critical";
opt_item = proto_tree_add_item(opts_tree, hf_geneve_opt_unknown,
tvb, offset, len, ENC_NA);
proto_item_set_text(opt_item, "%s (%s)",
format_unknown_option_name(opt_class, opt_type),
critical);
opt_tree = proto_item_add_subtree(opt_item, ett_geneve_unknown_opt);
proto_tree_add_item(opt_tree, hf_geneve_option_class, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
type_item = proto_tree_add_item(opt_tree, hf_geneve_option_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(type_item, " (%s)", critical);
hidden_item = proto_tree_add_item(opt_tree, hf_geneve_option_type_critical,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 1;
flags = tvb_get_guint8(tvb, offset) >> OPT_FLAGS_SHIFT;
flag_item = proto_tree_add_uint(opt_tree, hf_geneve_option_flags, tvb,
offset, 1, flags);
flag_tree = proto_item_add_subtree(flag_item, ett_geneve_opt_flags);
proto_tree_add_item(flag_tree, hf_geneve_option_flags_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (flags) {
proto_item_append_text(flag_item, " (RSVD)");
} else {
PROTO_ITEM_SET_HIDDEN(flag_item);
}
proto_tree_add_uint(opt_tree, hf_geneve_option_length, tvb, offset, 1, len);
offset += 1;
proto_tree_add_item(opt_tree, hf_geneve_opt_unknown_data, tvb, offset,
len - 4, ENC_NA);
}
static void
dissect_geneve_options(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *geneve_tree, int offset, int len)
{
proto_item *opts_item;
proto_tree *opts_tree;
guint16 opt_class;
guint8 opt_type;
guint8 opt_len;
opts_item = proto_tree_add_item(geneve_tree, hf_geneve_options, tvb,
offset, len, ENC_NA);
proto_item_set_text(opts_item, "Options: (%u bytes)", len);
opts_tree = proto_item_add_subtree(opts_item, ett_geneve_options);
while (len > 0) {
opt_class = tvb_get_ntohs(tvb, offset);
opt_type = tvb_get_guint8(tvb, offset + 2);
opt_len = 4 + ((tvb_get_guint8(tvb, offset + 3) & OPT_LEN_MASK) * 4);
if (opt_len > len) {
proto_tree_add_expert_format(opts_tree, pinfo,
&ei_geneve_opt_len_invalid, tvb,
offset + 3, 1,
"%s (length of %u is past end of options)",
format_unknown_option_name(opt_class,
opt_type),
opt_len);
return;
}
dissect_unknown_option(tvb, opts_tree, offset,
opt_class, opt_type, opt_len);
offset += opt_len;
len -= opt_len;
};
}
static int
dissect_geneve(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *rsvd_item;
proto_tree *geneve_tree;
tvbuff_t *next_tvb;
int offset = 0;
guint8 ver_opt;
guint8 ver;
guint8 flags;
guint16 proto_type;
int opts_len;
static const int * flag_fields[] = {
&hf_geneve_flag_oam,
&hf_geneve_flag_critical,
&hf_geneve_flag_reserved,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Geneve");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_geneve, tvb, offset, -1, ENC_NA);
geneve_tree = proto_item_add_subtree(ti, ett_geneve);
ver_opt = tvb_get_guint8(tvb, offset);
ver = ver_opt >> VER_SHIFT;
proto_tree_add_uint(geneve_tree, hf_geneve_version, tvb,
offset, 1, ver);
if (ver != GENEVE_VER) {
proto_tree_add_expert_format(geneve_tree, pinfo,
&ei_geneve_ver_unknown, tvb, offset, 1,
"Unknown version %u", ver);
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown Geneve version %u", ver);
}
opts_len = (ver_opt & HDR_OPTS_LEN_MASK) * 4;
proto_tree_add_uint(geneve_tree, hf_geneve_option_length, tvb,
offset, 1, opts_len);
offset += 1;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(geneve_tree, tvb, offset, hf_geneve_flags, ett_geneve_flags, flag_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(geneve_tree, hf_geneve_proto_type, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_type = tvb_get_ntohs(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "Encapsulated %s",
val_to_str(proto_type, etype_vals, "0x%04x (unknown)"));
offset += 2;
proto_tree_add_item(geneve_tree, hf_geneve_vni, tvb, offset, 3,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", VNI: 0x%06x%s", tvb_get_ntoh24(tvb, offset),
flags & FLAG_OAM ? ", OAM" : "");
offset += 3;
rsvd_item = proto_tree_add_item(geneve_tree, hf_geneve_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (!tvb_get_guint8(tvb, offset)) {
PROTO_ITEM_SET_HIDDEN(rsvd_item);
}
offset += 1;
if (tree && opts_len) {
dissect_geneve_options(tvb, pinfo, geneve_tree, offset, opts_len);
}
offset += opts_len;
proto_item_set_len(ti, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint(ethertype_dissector_table, proto_type, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_geneve(void)
{
static hf_register_info hf[] = {
{ &hf_geneve_version,
{ "Version", "geneve.version",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_flags,
{ "Flags", "geneve.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_flag_oam,
{ "Operations, Administration and Management Frame", "geneve.flags.oam",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_geneve_flag_critical,
{ "Critical Options Present", "geneve.flags.critical",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_geneve_flag_reserved,
{ "Reserved", "geneve.flags.reserved",
FT_BOOLEAN, 8, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_geneve_proto_type,
{ "Protocol Type", "geneve.proto_type",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_geneve_vni,
{ "Virtual Network Identifier (VNI)", "geneve.vni",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_geneve_reserved,
{ "Reserved", "geneve.reserved",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_options,
{ "Geneve Options", "geneve.options",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_option_class,
{ "Class", "geneve.option.class",
FT_UINT16, BASE_HEX | BASE_RANGE_STRING, RVALS(class_id_names), 0x00,
NULL, HFILL }
},
{ &hf_geneve_option_type,
{ "Type", "geneve.option.type",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_option_type_critical,
{ "Critical Option", "geneve.option.type.critical",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_geneve_option_flags,
{ "Flags", "geneve.option.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_option_flags_reserved,
{ "Reserved", "geneve.option.flags.reserved",
FT_BOOLEAN, 8, NULL, 0xE0,
NULL, HFILL }
},
{ &hf_geneve_option_length,
{ "Length", "geneve.option.length",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x00,
NULL, HFILL }
},
{ &hf_geneve_opt_unknown,
{ "Unknown Option", "geneve.option.unknown",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_geneve_opt_unknown_data,
{ "Option Data", "geneve.option.unknown.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_geneve,
&ett_geneve_flags,
&ett_geneve_options,
&ett_geneve_opt_flags,
&ett_geneve_unknown_opt,
};
static ei_register_info ei[] = {
{ &ei_geneve_ver_unknown, { "geneve.version.unknown",
PI_PROTOCOL, PI_WARN, "Unknown version", EXPFILL }},
{ &ei_geneve_opt_len_invalid, { "geneve.option.length.invalid",
PI_PROTOCOL, PI_WARN, "Invalid length for option", EXPFILL }},
};
expert_module_t *expert_geneve;
proto_geneve = proto_register_protocol("Generic Network Virtualization Encapsulation",
"Geneve", "geneve");
proto_register_field_array(proto_geneve, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_geneve = expert_register_protocol(proto_geneve);
expert_register_field_array(expert_geneve, ei, array_length(ei));
}
void
proto_reg_handoff_geneve(void)
{
dissector_handle_t geneve_handle;
geneve_handle = create_dissector_handle(dissect_geneve, proto_geneve);
dissector_add_uint_with_preference("udp.port", UDP_PORT_GENEVE, geneve_handle);
ethertype_dissector_table = find_dissector_table("ethertype");
}
