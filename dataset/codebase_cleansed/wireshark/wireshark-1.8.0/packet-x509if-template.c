static void
x509if_frame_end(void)
{
object_identifier_id = NULL;
top_of_dn = NULL;
top_of_rdn = NULL;
rdn_one_value = FALSE;
dn_one_rdn = FALSE;
doing_attr = FALSE;
last_dn = NULL;
last_rdn = NULL;
last_ava = NULL;
}
const char * x509if_get_last_dn(void)
{
return last_dn;
}
gboolean x509if_register_fmt(int hf_index, const gchar *fmt)
{
static int idx = 0;
if(idx < (MAX_FMT_VALS - 1)) {
fmt_vals[idx].value = hf_index;
fmt_vals[idx].strptr = fmt;
idx++;
fmt_vals[idx].value = 0;
fmt_vals[idx].strptr = NULL;
return TRUE;
} else
return FALSE;
}
const char * x509if_get_last_ava(void)
{
return last_ava;
}
void proto_register_x509if(void) {
static hf_register_info hf[] = {
{ &hf_x509if_object_identifier_id,
{ "Id", "x509if.id", FT_OID, BASE_NONE, NULL, 0,
"Object identifier Id", HFILL }},
{ &hf_x509if_any_string,
{ "AnyString", "x509if.any.String", FT_BYTES, BASE_NONE,
NULL, 0, "This is any String", HFILL }},
#include "packet-x509if-hfarr.c"
};
static gint *ett[] = {
#include "packet-x509if-ettarr.c"
};
proto_x509if = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x509if, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fmt_vals[0].value = 0;
fmt_vals[0].strptr = NULL;
}
void proto_reg_handoff_x509if(void) {
#include "packet-x509if-dis-tab.c"
}
