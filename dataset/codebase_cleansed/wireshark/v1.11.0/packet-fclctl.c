const gchar *
fclctl_get_typestr (guint8 linkctl_type, guint8 type)
{
if ((linkctl_type == FC_LCTL_FBSYB) ||
(linkctl_type == FC_LCTL_FBSYL)) {
return (val_to_str ((type & 0xF0), fc_lctl_fbsy_val, "0x%x"));
}
return "";
}
const gchar *
fclctl_get_paramstr (guint32 linkctl_type, guint32 param)
{
if (linkctl_type == FC_LCTL_PBSY) {
return wmem_strdup_printf(wmem_packet_scope(), "%s, %s",
val_to_str (((param & 0xFF000000) >> 24), fc_lctl_pbsy_acode_val, "0x%x"),
val_to_str (((param & 0x00FF0000) >> 16), fc_lctl_pbsy_rjt_val, "0x%x"));
}
if ((linkctl_type == FC_LCTL_FRJT) ||
(linkctl_type == FC_LCTL_PRJT)) {
return wmem_strdup_printf(wmem_packet_scope(), "%s, %s",
val_to_str (((param & 0xFF000000) >> 24), fc_lctl_rjt_acode_val, "0x%x"),
val_to_str (((param & 0x00FF0000) >> 16), fc_lctl_rjt_val, "%x"));
}
return "";
}
