void
expert_init(void)
{
static hf_register_info hf[] = {
{ &hf_expert_msg,
{ "Message", "expert.message", FT_STRING, BASE_NONE, NULL, 0, "Wireshark expert information", HFILL }
},
{ &hf_expert_group,
{ "Group", "expert.group", FT_UINT32, BASE_HEX, VALS(expert_group_vals), 0, "Wireshark expert group", HFILL }
},
{ &hf_expert_severity,
{ "Severity level", "expert.severity", FT_UINT32, BASE_HEX, VALS(expert_severity_vals), 0, "Wireshark expert severity level", HFILL }
}
};
static gint *ett[] = {
&ett_expert,
&ett_subexpert
};
if (expert_tap == -1) {
expert_tap = register_tap("expert");
}
if (proto_expert == -1) {
proto_expert = proto_register_protocol("Expert Info", "Expert", "expert");
proto_register_field_array(proto_expert, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
proto_set_cant_toggle(proto_expert);
}
highest_severity = 0;
}
void
expert_cleanup(void)
{
}
int
expert_get_highest_severity(void)
{
return highest_severity;
}
static void
expert_set_item_flags(proto_item *pi, int group, int severity)
{
if (proto_item_set_expert_flags(pi, group, severity)) {
pi = proto_item_get_parent(pi);
expert_set_item_flags(pi, group, severity);
}
}
static proto_tree*
expert_create_tree(proto_item *pi, int group, int severity, const char *msg)
{
proto_tree *tree;
proto_item *ti;
tree = proto_item_add_subtree(pi, ett_expert);
ti = proto_tree_add_protocol_format(tree, proto_expert, NULL, 0, 0, "Expert Info (%s/%s): %s",
val_to_str(severity, expert_severity_vals, "Unknown (%u)"),
val_to_str(group, expert_group_vals, "Unknown (%u)"),
msg);
PROTO_ITEM_SET_GENERATED(ti);
if (group == PI_MALFORMED) {
gint proto_malformed = proto_get_id_by_filter_name("malformed");
proto_item *malformed_ti = proto_tree_add_item(tree, proto_malformed, NULL, 0, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(malformed_ti);
}
return proto_item_add_subtree(ti, ett_subexpert);
}
static void
expert_set_info_vformat(packet_info *pinfo, proto_item *pi, int group, int severity, const char *format, va_list ap)
{
char formatted[ITEM_LABEL_LENGTH];
int tap;
expert_info_t *ei;
proto_tree *tree;
proto_item *ti;
if (pinfo == NULL && pi && pi->tree_data) {
pinfo = PTREE_DATA(pi)->pinfo;
}
if (pinfo == NULL || PINFO_FD_NUM(pinfo) == 0) {
return;
}
if (severity > highest_severity) {
highest_severity = severity;
}
if (pi != NULL && PITEM_FINFO(pi) != NULL) {
expert_set_item_flags(pi, group, severity);
}
if ((pi == NULL) || (PITEM_FINFO(pi) == NULL) ||
((guint)severity >= FI_GET_FLAG(PITEM_FINFO(pi), PI_SEVERITY_MASK))) {
col_add_str(pinfo->cinfo, COL_EXPERT, val_to_str(severity, expert_severity_vals, "Unknown (%u)"));
}
g_vsnprintf(formatted, ITEM_LABEL_LENGTH, format, ap);
tree = expert_create_tree(pi, group, severity, formatted);
ti = proto_tree_add_string(tree, hf_expert_msg, NULL, 0, 0, formatted);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint_format_value(tree, hf_expert_severity, NULL, 0, 0, severity,
"%s", val_to_str_const(severity, expert_severity_vals, "Unknown"));
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint_format_value(tree, hf_expert_group, NULL, 0, 0, group,
"%s", val_to_str_const(group, expert_group_vals, "Unknown"));
PROTO_ITEM_SET_GENERATED(ti);
tap = have_tap_listener(expert_tap);
if (!tap)
return;
ei = ep_new(expert_info_t);
ei->packet_num = PINFO_FD_NUM(pinfo);
ei->group = group;
ei->severity = severity;
ei->protocol = pinfo->current_proto;
ei->summary = ep_strdup(formatted);
if (pi != NULL && PITEM_FINFO(pi) != NULL) {
ei->pitem = pi;
} else {
ei->pitem = NULL;
}
tap_queue_packet(expert_tap, pinfo, ei);
}
void
expert_add_info_format(packet_info *pinfo, proto_item *pi, int group, int severity, const char *format, ...)
{
va_list ap;
va_start(ap, format);
expert_set_info_vformat(pinfo, pi, group, severity, format, ap);
va_end(ap);
}
void
expert_add_undecoded_item(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int length, const int severity)
{
proto_item *expert_item;
expert_item = proto_tree_add_text(tree, tvb, offset, length, "Not dissected yet");
expert_add_info_format(pinfo, expert_item, PI_UNDECODED, severity, "Not dissected yet(report to wireshark.org)"); \
PROTO_ITEM_SET_GENERATED(expert_item); \
}
