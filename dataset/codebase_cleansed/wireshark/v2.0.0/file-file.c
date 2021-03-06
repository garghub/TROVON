void
register_file_record_end_routine(packet_info *pinfo, void (*func)(void))
{
pinfo->frame_end_routines = g_slist_append(pinfo->frame_end_routines, (gpointer)func);
}
static void
call_file_record_end_routine(gpointer routine, gpointer dummy _U_)
{
void_func_t func = (void_func_t)routine;
(*func)();
}
static int
dissect_file_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *volatile ti = NULL;
guint cap_len = 0, frame_len = 0;
proto_tree *volatile tree;
proto_item *item;
const gchar *cap_plurality, *frame_plurality;
tree=parent_tree;
pinfo->current_proto = "File";
if(!proto_field_is_referenced(tree, proto_file)) {
tree=NULL;
} else {
proto_tree *fh_tree;
gboolean old_visible;
cap_len = tvb_captured_length(tvb);
frame_len = tvb_reported_length(tvb);
cap_plurality = plurality(cap_len, "", "s");
frame_plurality = plurality(frame_len, "", "s");
ti = proto_tree_add_protocol_format(tree, proto_file, tvb, 0, -1,
"File record %u: %u byte%s",
pinfo->fd->num, frame_len, frame_plurality);
proto_item_append_text(ti, ", %u byte%s",
cap_len, cap_plurality);
fh_tree = proto_item_add_subtree(ti, ett_file);
proto_tree_add_int(fh_tree, hf_file_ftap_encap, tvb, 0, 0, pinfo->fd->lnk_t);
proto_tree_add_uint(fh_tree, hf_file_record_number, tvb, 0, 0, pinfo->fd->num);
proto_tree_add_uint_format(fh_tree, hf_file_record_len, tvb,
0, 0, frame_len, "Record Length: %u byte%s (%u bits)",
frame_len, frame_plurality, frame_len * 8);
ti = proto_tree_add_boolean(fh_tree, hf_file_marked, tvb, 0, 0,pinfo->fd->flags.marked);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(fh_tree, hf_file_ignored, tvb, 0, 0,pinfo->fd->flags.ignored);
PROTO_ITEM_SET_GENERATED(ti);
if(proto_field_is_referenced(tree, hf_file_protocols)) {
old_visible = proto_tree_set_visible(fh_tree, TRUE);
ti = proto_tree_add_string(fh_tree, hf_file_protocols, tvb, 0, 0, "");
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_set_visible(fh_tree, old_visible);
}
if(pinfo->fd->pfd != 0){
proto_item *ppd_item;
guint num_entries = g_slist_length(pinfo->fd->pfd);
guint i;
ppd_item = proto_tree_add_uint(fh_tree, hf_file_num_p_prot_data, tvb, 0, 0, num_entries);
PROTO_ITEM_SET_GENERATED(ppd_item);
for(i=0; i<num_entries; i++){
gchar* str = p_get_proto_name_and_key(wmem_file_scope(), pinfo, i);
proto_tree_add_string_format(fh_tree, hf_file_proto_name_and_key, tvb, 0, 0, str, "%s", str);
}
}
#if 0
if (show_file_off) {
proto_tree_add_int64_format_value(fh_tree, hf_frame_file_off, tvb,
0, 0, pinfo->fd->file_off,
"%" G_GINT64_MODIFIER "d (0x%" G_GINT64_MODIFIER "x)",
pinfo->fd->file_off, pinfo->fd->file_off);
}
#endif
if(pinfo->fd->color_filter != NULL) {
const color_filter_t *color_filter = (const color_filter_t *)pinfo->fd->color_filter;
item = proto_tree_add_string(fh_tree, hf_file_color_filter_name, tvb,
0, 0, color_filter->filter_name);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string(fh_tree, hf_file_color_filter_text, tvb,
0, 0, color_filter->filter_text);
PROTO_ITEM_SET_GENERATED(item);
}
}
if (pinfo->fd->flags.ignored) {
col_set_str(pinfo->cinfo, COL_INFO, "<Ignored>");
proto_tree_add_boolean_format(tree, hf_file_ignored, tvb, 0, -1, TRUE, "This record is marked as ignored");
return tvb_captured_length(tvb);
}
TRY {
#ifdef _MSC_VER
__try {
#endif
if (!dissector_try_uint(file_encap_dissector_table, pinfo->fd->lnk_t,
tvb, pinfo, parent_tree)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UNKNOWN");
col_add_fstr(pinfo->cinfo, COL_INFO, "FTAP_ENCAP = %d",
pinfo->fd->lnk_t);
call_dissector(data_handle,tvb, pinfo, parent_tree);
}
#ifdef _MSC_VER
} __except(EXCEPTION_EXECUTE_HANDLER ) {
switch(GetExceptionCode()) {
case(STATUS_ACCESS_VIOLATION):
show_exception(tvb, pinfo, parent_tree, DissectorError,
"STATUS_ACCESS_VIOLATION: dissector accessed an invalid memory address");
break;
case(STATUS_INTEGER_DIVIDE_BY_ZERO):
show_exception(tvb, pinfo, parent_tree, DissectorError,
"STATUS_INTEGER_DIVIDE_BY_ZERO: dissector tried an integer division by zero");
break;
case(STATUS_STACK_OVERFLOW):
show_exception(tvb, pinfo, parent_tree, DissectorError,
"STATUS_STACK_OVERFLOW: dissector overflowed the stack (e.g. endless loop)");
break;
default:
show_exception(tvb, pinfo, parent_tree, DissectorError,
g_strdup_printf("dissector caused an unknown exception: 0x%x", GetExceptionCode()));
}
}
#endif
}
CATCH_BOUNDS_AND_DISSECTOR_ERRORS {
show_exception(tvb, pinfo, parent_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
if(proto_field_is_referenced(tree, hf_file_protocols)) {
wmem_strbuf_t *val = wmem_strbuf_new(wmem_packet_scope(), "");
wmem_list_frame_t *frame;
frame = wmem_list_frame_next(wmem_list_head(pinfo->layers));
if (frame) {
wmem_strbuf_append(val, proto_get_protocol_filter_name(GPOINTER_TO_UINT(wmem_list_frame_data(frame))));
frame = wmem_list_frame_next(frame);
}
while (frame) {
wmem_strbuf_append_c(val, ':');
wmem_strbuf_append(val, proto_get_protocol_filter_name(GPOINTER_TO_UINT(wmem_list_frame_data(frame))));
frame = wmem_list_frame_next(frame);
}
proto_item_append_string(ti, wmem_strbuf_get_str(val));
}
if (have_postdissector()) {
TRY {
#ifdef _MSC_VER
__try {
#endif
call_all_postdissectors(tvb, pinfo, parent_tree);
#ifdef _MSC_VER
} __except(EXCEPTION_EXECUTE_HANDLER ) {
switch(GetExceptionCode()) {
case(STATUS_ACCESS_VIOLATION):
show_exception(tvb, pinfo, parent_tree, DissectorError,
"STATUS_ACCESS_VIOLATION: dissector accessed an invalid memory address");
break;
case(STATUS_INTEGER_DIVIDE_BY_ZERO):
show_exception(tvb, pinfo, parent_tree, DissectorError,
"STATUS_INTEGER_DIVIDE_BY_ZERO: dissector tried an integer division by zero");
break;
case(STATUS_STACK_OVERFLOW):
show_exception(tvb, pinfo, parent_tree, DissectorError,
"STATUS_STACK_OVERFLOW: dissector overflowed the stack (e.g. endless loop)");
break;
default:
show_exception(tvb, pinfo, parent_tree, DissectorError,
g_strdup_printf("dissector caused an unknown exception: 0x%x", GetExceptionCode()));
}
}
#endif
}
CATCH_BOUNDS_AND_DISSECTOR_ERRORS {
show_exception(tvb, pinfo, parent_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
}
tap_queue_packet(file_tap, pinfo, NULL);
if (pinfo->frame_end_routines) {
g_slist_foreach(pinfo->frame_end_routines, &call_file_record_end_routine, NULL);
g_slist_free(pinfo->frame_end_routines);
pinfo->frame_end_routines = NULL;
}
return tvb_captured_length(tvb);
}
void
proto_register_file(void)
{
static hf_register_info hf[] = {
{ &hf_file_record_number,
{ "Record Number", "file.record_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_file_record_len,
{ "Record length", "file.record_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_frame_file_off,
{ "File Offset", "file.offset",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_file_marked,
{ "File record is marked", "file.marked",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"File record is marked in the GUI", HFILL }},
{ &hf_file_ignored,
{ "File record is ignored", "file.ignored",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"File record is ignored by the dissectors", HFILL }},
{ &hf_file_protocols,
{ "File record types in frame", "file.record_types",
FT_STRING, BASE_NONE, NULL, 0x0,
"File record types carried by this frame", HFILL }},
{ &hf_file_color_filter_name,
{ "Coloring Rule Name", "file.coloring_rule.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"The file record matched the coloring rule with this name", HFILL }},
{ &hf_file_color_filter_text,
{ "Coloring Rule String", "file.coloring_rule.string",
FT_STRING, BASE_NONE, NULL, 0x0,
"The file record matched this coloring rule string", HFILL }},
{ &hf_file_num_p_prot_data,
{ "Number of per-record-data", "file.p_record_data",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_file_proto_name_and_key,
{ "Protocol Name and Key", "file.proto_name_and_key",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_file_ftap_encap,
{ "Encapsulation type", "file.encap_type",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_file
};
#if 0
module_t *file_module;
#endif
file_encap_dissector_table = register_dissector_table("ftap_encap",
"Filetap encapsulation type", FT_UINT32, BASE_DEC);
proto_file = proto_register_protocol("File", "File", "file");
proto_register_field_array(proto_file, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("file",dissect_file_record,proto_file);
proto_set_cant_toggle(proto_file);
#if 0
frame_module = prefs_register_protocol(proto_frame, NULL);
prefs_register_bool_preference(frame_module, "show_file_off",
"Show File Offset", "Show offset of frame in capture file", &show_file_off);
#endif
file_tap=register_tap("file");
}
void
proto_reg_handoff_file(void)
{
data_handle = find_dissector("data");
}
