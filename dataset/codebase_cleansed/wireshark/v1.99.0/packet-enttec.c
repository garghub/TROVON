static gint
dissect_enttec_poll_reply(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_enttec_poll_reply_mac, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_enttec_poll_reply_node_type, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_enttec_poll_reply_version, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_enttec_poll_reply_switch, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_enttec_poll_reply_name, tvb,
offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(tree, hf_enttec_poll_reply_option, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_enttec_poll_reply_tos, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_enttec_poll_reply_ttl, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static gint
dissect_enttec_poll(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_enttec_poll_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static gint
dissect_enttec_ack(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static gint
dissect_enttec_dmx_data(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
static const char* chan_format[] = {
"%2u ",
"%02x ",
"%3u "
};
static const char* string_format[] = {
"%03x: %s",
"%3u: %s"
};
guint8 *dmx_data = (guint8 *)wmem_alloc(wmem_packet_scope(), 512 * sizeof(guint8));
guint16 *dmx_data_offset = (guint16 *)wmem_alloc(wmem_packet_scope(), 513 * sizeof(guint16));
wmem_strbuf_t *dmx_epstr;
proto_tree *hi,*si;
proto_item *item;
guint16 length,r,c,row_count;
guint8 v,type,count;
guint16 ci,ui,i,start_offset,end_offset;
proto_tree_add_item(tree, hf_enttec_dmx_data_universe, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_enttec_dmx_data_start_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_enttec_dmx_data_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_enttec_dmx_data_size, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (length > 512)
length = 512;
if (type == ENTTEC_DATA_TYPE_RLE) {
ui = 0;
ci = 0;
while (ci < length && ui < 512) {
v = tvb_get_guint8(tvb, offset+ci);
if (v == 0xFE) {
ci++;
count = tvb_get_guint8(tvb, offset+ci);
ci++;
v = tvb_get_guint8(tvb, offset+ci);
ci++;
for (i=0;i < count && ui < 512;i++) {
dmx_data[ui] = v;
dmx_data_offset[ui] = ci-3;
ui++;
}
} else if (v == 0xFD) {
ci++;
v = tvb_get_guint8(tvb, offset+ci);
dmx_data[ui] = v;
dmx_data_offset[ui] = ci;
ci++;
ui++;
} else {
dmx_data[ui] = v;
dmx_data_offset[ui] = ci;
ui++;
ci++;
}
}
dmx_data_offset[ui] = ci;
} else {
for (ui=0; ui < length;ui++) {
dmx_data[ui] = tvb_get_guint8(tvb, offset+ui);
dmx_data_offset[ui] = ui;
}
dmx_data_offset[ui] = ui;
}
if ((type == ENTTEC_DATA_TYPE_DMX || type == ENTTEC_DATA_TYPE_RLE) && global_disp_col_count > 0) {
hi = proto_tree_add_item(tree,
hf_enttec_dmx_data_data,
tvb,
offset,
length,
ENC_NA);
si = proto_item_add_subtree(hi, ett_enttec);
row_count = (ui/global_disp_col_count) + ((ui%global_disp_col_count) == 0 ? 0 : 1);
dmx_epstr = wmem_strbuf_new_label(wmem_packet_scope());
for (r=0; r < row_count;r++) {
for (c=0;(c < global_disp_col_count) && (((r*global_disp_col_count)+c) < ui);c++) {
if ((global_disp_col_count > 1) && (c % (global_disp_col_count/2)) == 0) {
wmem_strbuf_append_c(dmx_epstr, ' ');
}
v = dmx_data[(r*global_disp_col_count)+c];
if (global_disp_chan_val_type == 0) {
v = (v * 100) / 255;
if (v == 100) {
wmem_strbuf_append(dmx_epstr, "FL ");
} else {
wmem_strbuf_append_printf(dmx_epstr, chan_format[global_disp_chan_val_type], v);
}
} else {
wmem_strbuf_append_printf(dmx_epstr, chan_format[global_disp_chan_val_type], v);
}
}
start_offset = dmx_data_offset[(r*global_disp_col_count)];
end_offset = dmx_data_offset[(r*global_disp_col_count)+c];
proto_tree_add_none_format(si,hf_enttec_dmx_data_dmx_data, tvb,
offset+start_offset,
end_offset-start_offset,
string_format[global_disp_chan_nr_type], (r*global_disp_col_count)+1,
wmem_strbuf_get_str(dmx_epstr));
wmem_strbuf_truncate(dmx_epstr, 0);
}
item = proto_tree_add_item(si, hf_enttec_dmx_data_data_filter, tvb,
offset, length, ENC_NA );
PROTO_ITEM_SET_HIDDEN(item);
offset += length;
} else if (type == ENTTEC_DATA_TYPE_CHAN_VAL) {
proto_tree_add_item(tree, hf_enttec_dmx_data_data_filter, tvb,
offset, length, ENC_NA);
offset += length;
} else {
proto_tree_add_item(tree, hf_enttec_dmx_data_data_filter, tvb,
offset, length, ENC_NA);
offset += length;
}
return offset;
}
static gint
dissect_enttec_config(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static gint
dissect_enttec_reset(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static int
dissect_enttec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint32 head = 0;
proto_tree *ti,*enttec_tree=NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ENTTEC");
head = tvb_get_ntohl(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(head, enttec_head_vals, "Unknown (0x%08x)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_enttec, tvb, offset, -1, ENC_NA);
enttec_tree = proto_item_add_subtree(ti, ett_enttec);
}
if (enttec_tree) {
proto_tree_add_item(enttec_tree, hf_enttec_head, tvb,
offset, 4, ENC_BIG_ENDIAN );
offset += 4;
switch (head) {
case ENTTEC_HEAD_ESPR:
offset = dissect_enttec_poll_reply( tvb, offset, enttec_tree);
break;
case ENTTEC_HEAD_ESPP:
offset = dissect_enttec_poll( tvb, offset, enttec_tree);
break;
case ENTTEC_HEAD_ESAP:
offset = dissect_enttec_ack( tvb, offset, enttec_tree);
break;
case ENTTEC_HEAD_ESDD:
offset = dissect_enttec_dmx_data( tvb, offset, enttec_tree);
break;
case ENTTEC_HEAD_ESNC:
offset = dissect_enttec_config( tvb, offset, enttec_tree);
break;
case ENTTEC_HEAD_ESZZ:
offset = dissect_enttec_reset( tvb, offset, enttec_tree);
break;
}
}
return offset;
}
void
proto_register_enttec(void)
{
static hf_register_info hf[] = {
{ &hf_enttec_head,
{ "Head", "enttec.head",
FT_UINT32, BASE_HEX, VALS(enttec_head_vals), 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_mac,
{ "MAC", "enttec.poll_reply.mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_node_type,
{ "Node Type", "enttec.poll_reply.node_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_version,
{ "Version", "enttec.poll_reply.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_switch,
{ "Switch settings", "enttec.poll_reply.switch_settings",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_name,
{ "Name", "enttec.poll_reply.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_option,
{ "Option Field", "enttec.poll_reply.option_field",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_tos,
{ "TOS", "enttec.poll_reply.tos",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_reply_ttl,
{ "TTL", "enttec.poll_reply.ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_universe,
{ "Universe", "enttec.dmx_data.universe",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_start_code,
{ "Start Code", "enttec.dmx_data.start_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_type,
{ "Data Type", "enttec.dmx_data.type",
FT_UINT8, BASE_HEX, VALS(enttec_data_type_vals), 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_size,
{ "Data Size", "enttec.dmx_data.size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_data,
{ "DMX Data", "enttec.dmx_data.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_data_filter,
{ "DMX Data", "enttec.dmx_data.data_filter",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_dmx_data_dmx_data,
{ "DMX Data", "enttec.dmx_data.dmx_data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_enttec_poll_type,
{ "Reply Type", "enttec.poll.reply_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } }
};
static gint *ett[] = {
&ett_enttec,
};
module_t *enttec_module;
static const enum_val_t disp_chan_val_types[] = {
{ "pro", "Percent", 0 },
{ "hex", "Hexadecimal", 1 },
{ "dec", "Decimal", 2 },
{ NULL, NULL, 0 }
};
static const enum_val_t disp_chan_nr_types[] = {
{ "hex", "Hexadecimal", 0 },
{ "dec", "Decimal", 1 },
{ NULL, NULL, 0 }
};
static const enum_val_t col_count[] = {
{ "6", "6", 6 },
{ "10", "10", 10 },
{ "12", "12", 12 },
{ "16", "16", 16 },
{ "24", "24", 24 },
{ NULL, NULL, 0 }
};
proto_enttec = proto_register_protocol("ENTTEC", "ENTTEC","enttec");
proto_register_field_array(proto_enttec,hf,array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
enttec_module = prefs_register_protocol(proto_enttec,
proto_reg_handoff_enttec);
prefs_register_uint_preference(enttec_module, "udp_port",
"ENTTEC UDP Port",
"The UDP port on which ENTTEC packets will be sent",
10,&global_udp_port_enttec);
prefs_register_uint_preference(enttec_module, "tcp_port",
"ENTTEC TCP Port",
"The TCP port on which ENTTEC packets will be sent",
10,&global_tcp_port_enttec);
prefs_register_enum_preference(enttec_module, "dmx_disp_chan_val_type",
"DMX Display channel value type",
"The way DMX values are displayed",
&global_disp_chan_val_type,
disp_chan_val_types, FALSE);
prefs_register_enum_preference(enttec_module, "dmx_disp_chan_nr_type",
"DMX Display channel nr. type",
"The way DMX channel numbers are displayed",
&global_disp_chan_nr_type,
disp_chan_nr_types, FALSE);
prefs_register_enum_preference(enttec_module, "dmx_disp_col_count",
"DMX Display Column Count",
"The number of columns for the DMX display",
&global_disp_col_count,
col_count, FALSE);
}
void
proto_reg_handoff_enttec(void) {
static gboolean enttec_initialized = FALSE;
static dissector_handle_t enttec_handle;
static guint udp_port_enttec;
static guint tcp_port_enttec;
if(!enttec_initialized) {
enttec_handle = new_create_dissector_handle(dissect_enttec,proto_enttec);
enttec_initialized = TRUE;
} else {
dissector_delete_uint("udp.port",udp_port_enttec,enttec_handle);
dissector_delete_uint("tcp.port",tcp_port_enttec,enttec_handle);
}
udp_port_enttec = global_udp_port_enttec;
tcp_port_enttec = global_tcp_port_enttec;
dissector_add_uint("udp.port",global_udp_port_enttec,enttec_handle);
dissector_add_uint("tcp.port",global_tcp_port_enttec,enttec_handle);
}
