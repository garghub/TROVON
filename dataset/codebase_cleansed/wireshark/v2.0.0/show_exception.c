void
register_show_exception(void)
{
static ei_register_info ei[] = {
{ &ei_malformed_dissector_bug, { "_ws.malformed.dissector_bug", PI_MALFORMED, PI_ERROR, "Dissector bug", EXPFILL }},
{ &ei_malformed_reassembly, { "_ws.malformed.reassembly", PI_MALFORMED, PI_ERROR, "Reassembly error", EXPFILL }},
{ &ei_malformed, { "_ws.malformed.expert", PI_MALFORMED, PI_ERROR, "Malformed Packet (Exception occurred)", EXPFILL }},
};
expert_module_t* expert_malformed;
proto_short = proto_register_protocol("Short Frame", "Short frame", "_ws.short");
proto_malformed = proto_register_protocol("Malformed Packet",
"Malformed packet", "_ws.malformed");
proto_unreassembled = proto_register_protocol(
"Unreassembled Fragmented Packet",
"Unreassembled fragmented packet", "_ws.unreassembled");
expert_malformed = expert_register_protocol(proto_malformed);
expert_register_field_array(expert_malformed, ei, array_length(ei));
proto_set_cant_toggle(proto_short);
proto_set_cant_toggle(proto_malformed);
proto_set_cant_toggle(proto_unreassembled);
}
void
show_exception(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
unsigned long exception, const char *exception_message)
{
static const char dissector_error_nomsg[] =
"Dissector writer didn't bother saying what the error was";
proto_item *item;
if (exception == ReportedBoundsError && pinfo->fragmented)
exception = FragmentBoundsError;
switch (exception) {
case ScsiBoundsError:
col_append_str(pinfo->cinfo, COL_INFO, "[SCSI transfer limited due to allocation_length too small]");
proto_tree_add_protocol_format(tree, proto_short, tvb, 0, 0,
"SCSI transfer limited due to allocation_length too small: %s truncated]", pinfo->current_proto);
break;
case BoundsError:
{
gboolean display_info = TRUE;
module_t * frame_module = prefs_find_module("frame");
if (frame_module != NULL)
{
pref_t *display_pref = prefs_find_preference(frame_module, "disable_packet_size_limited_in_summary");
if (display_pref)
{
if (*display_pref->varp.boolp)
display_info = FALSE;
}
}
if (display_info)
col_append_str(pinfo->cinfo, COL_INFO, "[Packet size limited during capture]");
proto_tree_add_protocol_format(tree, proto_short, tvb, 0, 0,
"[Packet size limited during capture: %s truncated]", pinfo->current_proto);
}
break;
case FragmentBoundsError:
col_append_fstr(pinfo->cinfo, COL_INFO, "[Unreassembled Packet%s]", pinfo->noreassembly_reason);
proto_tree_add_protocol_format(tree, proto_unreassembled,
tvb, 0, 0, "[Unreassembled Packet%s: %s]",
pinfo->noreassembly_reason, pinfo->current_proto);
break;
case ReportedBoundsError:
show_reported_bounds_error(tvb, pinfo, tree);
break;
case DissectorError:
col_append_fstr(pinfo->cinfo, COL_INFO,
"[Dissector bug, protocol %s: %s]",
pinfo->current_proto,
exception_message == NULL ?
dissector_error_nomsg : exception_message);
item = proto_tree_add_protocol_format(tree, proto_malformed, tvb, 0, 0,
"[Dissector bug, protocol %s: %s]",
pinfo->current_proto,
exception_message == NULL ?
dissector_error_nomsg : exception_message);
g_warning("Dissector bug, protocol %s, in packet %u: %s",
pinfo->current_proto, pinfo->fd->num,
exception_message == NULL ?
dissector_error_nomsg : exception_message);
expert_add_info_format(pinfo, item, &ei_malformed_dissector_bug, "%s",
exception_message == NULL ?
dissector_error_nomsg : exception_message);
break;
case ReassemblyError:
col_append_fstr(pinfo->cinfo, COL_INFO,
"[Reassembly error, protocol %s: %s]",
pinfo->current_proto,
exception_message == NULL ?
dissector_error_nomsg : exception_message);
item = proto_tree_add_protocol_format(tree, proto_malformed, tvb, 0, 0,
"[Reassembly error, protocol %s: %s]",
pinfo->current_proto,
exception_message == NULL ?
dissector_error_nomsg : exception_message);
expert_add_info_format(pinfo, item, &ei_malformed_reassembly, "%s",
exception_message == NULL ?
dissector_error_nomsg : exception_message);
break;
default:
g_assert_not_reached();
}
}
void
show_reported_bounds_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
col_append_str(pinfo->cinfo, COL_INFO,
"[Malformed Packet]");
item = proto_tree_add_protocol_format(tree, proto_malformed,
tvb, 0, 0, "[Malformed Packet: %s]", pinfo->current_proto);
expert_add_info(pinfo, item, &ei_malformed);
}
