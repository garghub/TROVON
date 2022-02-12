gboolean
right_justify_column (gint col, capture_file *cf)
{
header_field_info *hfi;
gboolean right_justify = FALSE;
if (!cf) return FALSE;
switch (cf->cinfo.columns[col].col_fmt) {
case COL_NUMBER:
case COL_PACKET_LENGTH:
case COL_CUMULATIVE_BYTES:
case COL_DCE_CALL:
case COL_DSCP_VALUE:
case COL_UNRES_DST_PORT:
case COL_UNRES_SRC_PORT:
case COL_DEF_DST_PORT:
case COL_DEF_SRC_PORT:
case COL_DELTA_TIME:
case COL_DELTA_TIME_DIS:
right_justify = TRUE;
break;
case COL_CUSTOM:
hfi = proto_registrar_get_byname(cf->cinfo.columns[col].col_custom_fields);
if ((hfi != NULL) && ((hfi->strings == NULL) || !get_column_resolved(col))) {
if ((hfi->type == FT_BOOLEAN) || (hfi->type == FT_FRAMENUM) ||
(((hfi->display == BASE_DEC) || (hfi->display == BASE_OCT)) &&
(IS_FT_INT(hfi->type) || IS_FT_UINT(hfi->type)))) {
right_justify = TRUE;
}
}
break;
default:
break;
}
return right_justify;
}
gboolean
resolve_column (gint col, capture_file *cf)
{
header_field_info *hfi;
gboolean resolve = FALSE;
if (!cf) return FALSE;
switch (cf->cinfo.columns[col].col_fmt) {
case COL_CUSTOM:
hfi = proto_registrar_get_byname(cf->cinfo.columns[col].col_custom_fields);
if (hfi != NULL) {
if ((hfi->type == FT_OID) || (hfi->type == FT_REL_OID) ||
((hfi->strings != NULL) &&
((hfi->type == FT_BOOLEAN) || (hfi->type == FT_FRAMENUM) ||
IS_FT_INT(hfi->type) || IS_FT_UINT(hfi->type)))) {
resolve = TRUE;
}
}
break;
default:
break;
}
return resolve;
}
