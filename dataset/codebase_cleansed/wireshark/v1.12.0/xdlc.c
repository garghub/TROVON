int
get_xdlc_control(const guchar *pd, int offset, gboolean is_extended)
{
guint16 control;
switch (pd[offset] & 0x03) {
case XDLC_S:
default:
if (is_extended)
control = pletoh16(&pd[offset]);
else
control = pd[offset];
break;
case XDLC_U:
control = pd[offset];
break;
}
return control;
}
gboolean
check_xdlc_control(tvbuff_t *tvb, int offset,
const value_string *u_modifier_short_vals_cmd,
const value_string *u_modifier_short_vals_resp, gboolean is_response,
gboolean is_extended _U_)
{
guint16 control;
if (!tvb_bytes_exist(tvb, offset, 1))
return FALSE;
switch (tvb_get_guint8(tvb, offset) & 0x03) {
case XDLC_S:
return TRUE;
case XDLC_U:
if (u_modifier_short_vals_cmd == NULL)
u_modifier_short_vals_cmd = modifier_short_vals_cmd;
if (u_modifier_short_vals_resp == NULL)
u_modifier_short_vals_resp = modifier_short_vals_resp;
control = tvb_get_guint8(tvb, offset);
if (is_response) {
if (try_val_to_str(control & XDLC_U_MODIFIER_MASK,
u_modifier_short_vals_resp) == NULL)
return FALSE;
} else {
if (try_val_to_str(control & XDLC_U_MODIFIER_MASK,
u_modifier_short_vals_cmd) == NULL)
return FALSE;
}
return TRUE;
default:
return TRUE;
}
}
int
dissect_xdlc_control(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *xdlc_tree, int hf_xdlc_control, gint ett_xdlc_control,
const xdlc_cf_items *cf_items_nonext, const xdlc_cf_items *cf_items_ext,
const value_string *u_modifier_short_vals_cmd,
const value_string *u_modifier_short_vals_resp, gboolean is_response,
gboolean is_extended, gboolean append_info)
{
guint16 control;
int control_len;
const xdlc_cf_items *cf_items;
const char *control_format;
guint16 poll_final;
char *info;
proto_tree *tc, *control_tree;
const gchar *frame_type = NULL;
const gchar *modifier;
info=(char *)ep_alloc(80);
switch (tvb_get_guint8(tvb, offset) & 0x03) {
case XDLC_S:
if (is_extended) {
control = tvb_get_letohs(tvb, offset);
control_len = 2;
cf_items = cf_items_ext;
control_format = "Control field: %s (0x%04X)";
} else {
control = tvb_get_guint8(tvb, offset);
control_len = 1;
cf_items = cf_items_nonext;
control_format = "Control field: %s (0x%02X)";
}
switch (control & XDLC_S_FTYPE_MASK) {
case XDLC_RR:
frame_type = "RR";
break;
case XDLC_RNR:
frame_type = "RNR";
break;
case XDLC_REJ:
frame_type = "REJ";
break;
case XDLC_SREJ:
frame_type = "SREJ";
break;
}
if (is_extended) {
poll_final = (control & XDLC_P_F_EXT);
g_snprintf(info, 80, "S%s, func=%s, N(R)=%u",
(poll_final ?
(is_response ? " F" : " P") :
""),
frame_type,
(control & XDLC_N_R_EXT_MASK) >> XDLC_N_R_EXT_SHIFT);
} else {
poll_final = (control & XDLC_P_F);
g_snprintf(info, 80, "S%s, func=%s, N(R)=%u",
(poll_final ?
(is_response ? " F" : " P") :
""),
frame_type,
(control & XDLC_N_R_MASK) >> XDLC_N_R_SHIFT);
}
if (append_info) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, info);
} else {
col_add_str(pinfo->cinfo, COL_INFO, info);
}
if (xdlc_tree) {
tc = proto_tree_add_uint_format(xdlc_tree, hf_xdlc_control, tvb,
offset, control_len, control, control_format, info, control);
control_tree = proto_item_add_subtree(tc, ett_xdlc_control);
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_n_r,
tvb, offset, control_len, control);
if (poll_final) {
proto_tree_add_boolean(control_tree,
(is_response ? *cf_items->hf_xdlc_f :
*cf_items->hf_xdlc_p),
tvb, offset, control_len, control);
}
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_s_ftype,
tvb, offset, control_len, control);
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_ftype_s_u,
tvb, offset, control_len, control);
}
break;
case XDLC_U:
if (u_modifier_short_vals_cmd == NULL)
u_modifier_short_vals_cmd = modifier_short_vals_cmd;
if (u_modifier_short_vals_resp == NULL)
u_modifier_short_vals_resp = modifier_short_vals_resp;
control = tvb_get_guint8(tvb, offset);
control_len = 1;
cf_items = cf_items_nonext;
control_format = "Control field: %s (0x%02X)";
if (is_response) {
modifier = val_to_str(control & XDLC_U_MODIFIER_MASK,
u_modifier_short_vals_resp, "Unknown");
} else {
modifier = val_to_str(control & XDLC_U_MODIFIER_MASK,
u_modifier_short_vals_cmd, "Unknown");
}
poll_final = (control & XDLC_P_F);
g_snprintf(info, 80, "U%s, func=%s",
(poll_final ?
(is_response ? " F" : " P") :
""),
modifier);
if (append_info) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, info);
} else {
col_add_str(pinfo->cinfo, COL_INFO, info);
}
if (xdlc_tree) {
tc = proto_tree_add_uint_format(xdlc_tree, hf_xdlc_control, tvb,
offset, control_len, control, control_format, info, control);
control_tree = proto_item_add_subtree(tc, ett_xdlc_control);
if (poll_final) {
proto_tree_add_boolean(control_tree,
(is_response ? *cf_items->hf_xdlc_f:
*cf_items->hf_xdlc_p),
tvb, offset, control_len, control);
}
proto_tree_add_uint(control_tree,
(is_response ? *cf_items->hf_xdlc_u_modifier_resp :
*cf_items->hf_xdlc_u_modifier_cmd),
tvb, offset, control_len, control);
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_ftype_s_u,
tvb, offset, control_len, control);
}
break;
default:
if (is_extended) {
control = tvb_get_letohs(tvb, offset);
control_len = 2;
cf_items = cf_items_ext;
control_format = "Control field: %s (0x%04X)";
poll_final = (control & XDLC_P_F_EXT);
g_snprintf(info, 80, "I%s, N(R)=%u, N(S)=%u",
((control & XDLC_P_F_EXT) ? " P" : ""),
(control & XDLC_N_R_EXT_MASK) >> XDLC_N_R_EXT_SHIFT,
(control & XDLC_N_S_EXT_MASK) >> XDLC_N_S_EXT_SHIFT);
} else {
control = tvb_get_guint8(tvb, offset);
control_len = 1;
cf_items = cf_items_nonext;
control_format = "Control field: %s (0x%02X)";
poll_final = (control & XDLC_P_F);
g_snprintf(info, 80, "I%s, N(R)=%u, N(S)=%u",
((control & XDLC_P_F) ? " P" : ""),
(control & XDLC_N_R_MASK) >> XDLC_N_R_SHIFT,
(control & XDLC_N_S_MASK) >> XDLC_N_S_SHIFT);
}
if (append_info) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, info);
} else {
col_add_str(pinfo->cinfo, COL_INFO, info);
}
if (xdlc_tree) {
tc = proto_tree_add_uint_format(xdlc_tree, hf_xdlc_control, tvb,
offset, control_len, control, control_format, info, control);
control_tree = proto_item_add_subtree(tc, ett_xdlc_control);
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_n_r,
tvb, offset, control_len, control);
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_n_s,
tvb, offset, control_len, control);
if (poll_final) {
proto_tree_add_boolean(control_tree, *cf_items->hf_xdlc_p,
tvb, offset, control_len, control);
}
proto_tree_add_uint(control_tree, *cf_items->hf_xdlc_ftype_i,
tvb, offset, control_len, control);
}
break;
}
return control;
}
