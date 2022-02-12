extern void h248_param_ber_integer(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* u _U_, void* implicit) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_integer(implicit ? *((gboolean*)implicit) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
}
extern void h248_param_ber_octetstring(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* u _U_, void* implicit) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_octet_string(implicit ? *((gboolean*)implicit) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
}
extern void h248_param_ber_boolean(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* u _U_, void* implicit) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_boolean(implicit ? *((gboolean*)implicit) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
}
extern void h248_param_bytes_item(proto_tree* tree,
tvbuff_t* tvb,
packet_info* pinfo _U_,
int hfid,
h248_curr_info_t* h248_info _U_,
void* lenp ) {
int len = lenp ? *((int*)lenp) : -1;
proto_tree_add_item(tree,hfid,tvb,0,len,ENC_NA);
}
extern void h248_param_uint_item(proto_tree* tree,
tvbuff_t* tvb,
packet_info* pinfo _U_,
int hfid,
h248_curr_info_t* h248_info _U_,
void* lenp ) {
int len = lenp ? *((int*)lenp) : -1;
proto_tree_add_item(tree,hfid,tvb,0,len,ENC_BIG_ENDIAN);
}
extern void h248_param_external_dissector(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo , int hfid _U_, h248_curr_info_t* u _U_, void* dissector_hdl) {
call_dissector((dissector_handle_t) dissector_hdl,tvb,pinfo,tree);
}
extern void h248_param_PkgdName(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo , int hfid _U_, h248_curr_info_t* u1 _U_, void* u2 _U_) {
tvbuff_t *new_tvb = NULL;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, offset, hfid , &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
pkg = find_package_id(name_major);
proto_item_append_text(asn1_ctx.created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
proto_item* pi;
const gchar* strval;
package_tree = proto_item_add_subtree(asn1_ctx.created_item, ett_packagename);
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
pi = proto_tree_add_uint(package_tree, hf_248_pkg_param, tvb, offset-2, 2, name_minor);
if (pkg->signal_names && ( strval = match_strval(name_minor, pkg->signal_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,name_minor);
} else {
strval = ep_strdup_printf("Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Signal ID: %s", strval);
}
}
}
static int dissect_h248_trx_id(gboolean implicit_tag, packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32* trx_id_p) {
guint64 trx_id = 0;
gint8 class;
gboolean pc;
gint32 tag;
guint32 len;
guint32 i;
if(!implicit_tag){
offset=dissect_ber_identifier(pinfo, tree, tvb, offset, &class, &pc, &tag);
offset=dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
} else {
len=tvb_length_remaining(tvb, offset);
}
if (len > 8 || len < 1) {
THROW(BoundsError);
} else {
for(i=1;i<=len;i++){
trx_id=(trx_id<<8)|tvb_get_guint8(tvb, offset);
offset++;
}
if (trx_id > 0xffffffff) {
proto_item* pi = proto_tree_add_text(tree, tvb, offset-len, len,"transactionId %" G_GINT64_MODIFIER "u", trx_id);
proto_item_set_expert_flags(pi, PI_MALFORMED, PI_WARN);
*trx_id_p = 0;
} else {
proto_tree_add_uint(tree, hf_h248_transactionId, tvb, offset-len, len, (guint32)trx_id);
*trx_id_p = (guint32)trx_id;
}
}
return offset;
}
static int dissect_h248_ctx_id(gboolean implicit_tag, packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32* ctx_id_p) {
gint8 class;
gboolean pc;
gint32 tag;
guint32 len;
guint64 ctx_id = 0;
guint32 i;
if(!implicit_tag){
offset=dissect_ber_identifier(pinfo, tree, tvb, offset, &class, &pc, &tag);
offset=dissect_ber_length(pinfo, tree, tvb, offset, &len, NULL);
} else {
len=tvb_length_remaining(tvb, offset);
}
if (len > 8 || len < 1) {
THROW(BoundsError);
} else {
for(i=1;i<=len;i++){
ctx_id=(ctx_id<<8)|tvb_get_guint8(tvb, offset);
offset++;
}
if (ctx_id > 0xffffffff) {
proto_item* pi = proto_tree_add_text(tree, tvb, offset-len, len,
"contextId: %" G_GINT64_MODIFIER "u", ctx_id);
proto_item_set_expert_flags(pi, PI_MALFORMED, PI_WARN);
*ctx_id_p = 0xfffffffd;
} else {
proto_item* pi = proto_tree_add_uint(tree, hf_h248_context_id, tvb, offset-len, len, (guint32)ctx_id);
if ( ctx_id == NULL_CONTEXT ) {
proto_item_set_text(pi,"contextId: Null Context(0)");
} else if ( ctx_id == CHOOSE_CONTEXT ) {
proto_item_set_text(pi,"contextId: $ (Choose Context = 0xfffffffe)");
} else if ( ctx_id == ALL_CONTEXTS ) {
proto_item_set_text(pi,"contextId: * (All Contexts = 0xffffffff)");
}
*ctx_id_p = (guint32) ctx_id;
}
}
return offset;
}
s_h248_package_t *s_find_package_id(guint16 pkgid) {
s_h248_package_t *s_pkg = NULL;
s_pkg = g_tree_lookup(packages, GUINT_TO_POINTER((guint32)(pkgid)));
return s_pkg;
}
const h248_package_t *find_package_id(guint16 pkgid) {
s_h248_package_t *s_pkg = NULL;
s_pkg = s_find_package_id(pkgid);
if (! s_pkg ) return &no_package;
return s_pkg->pkg;
}
static gint32 comparePkgID(gconstpointer a, gconstpointer b) {
return GPOINTER_TO_UINT(b) - GPOINTER_TO_UINT(a);
}
gboolean is_pkg_default(guint16 pkgid) {
s_h248_package_t *s_pkg = NULL;
s_pkg = g_tree_lookup(packages, GUINT_TO_POINTER((guint32)(pkgid)));
if(! s_pkg ) return TRUE;
return s_pkg->is_default;
}
void h248_register_package(const h248_package_t* pkg, pkg_reg_action reg_action) {
h248_package_t *pkg_found = NULL, *pkg_high = NULL, *pkg_low = NULL;
s_h248_package_t *s_pkg = NULL;
value_string *vst;
gboolean pkg_default = FALSE;
gint j = 0, idx = 0, i = 0, k = 0;
if (! packages) {
packages = g_tree_new(comparePkgID);
while (base_package_name_vals[i].strptr != NULL) {
pkg_found = g_new0(h248_package_t, 1);
pkg_found->id = base_package_name_vals[i].value;
vst = g_new0(value_string,2);
vst[0].strptr = base_package_name_vals[i].strptr;
pkg_found->param_names = vst;
pkg_found->hfid = &hf_h248_pkg_name;
pkg_found->ett = &ett_packagename;
match_strval_idx((pkg_found->id)<<16,base_event_name_vals, &j);
if (j != -1) {
j++; idx=j;
while((base_event_name_vals[j].strptr!=NULL) && (((base_event_name_vals[j].value)>>16) == (pkg_found->id))) {
j++;
};
if (idx < j) {
vst = g_new0(value_string,j-idx+1);
for (k=0;idx<j;k++) {
vst[k].strptr = base_event_name_vals[idx].strptr;
vst[k].value = (base_event_name_vals[idx].value & 0xffff);
idx++;
};
pkg_found->event_names = vst;
}
}
if (!match_strval_idx((pkg_found->id)<<16, base_signal_name_vals, &j)) {
j++; idx=j;
while((base_signal_name_vals[j].strptr != NULL) && ((base_signal_name_vals[j].value>>16) == (pkg_found->id))) {
};
if (idx < j) {
vst = g_new0(value_string,j-idx+1);
for (k=0;idx<i;k++) {
vst[k].strptr = base_signal_name_vals[idx].strptr;
vst[k].value = (base_signal_name_vals[idx].value &0xffff);
idx++;
};
pkg_found->signal_names = vst;
}
};
s_pkg = g_new0(s_h248_package_t,1);
s_pkg->is_default = TRUE;
s_pkg->pkg = pkg_found;
g_tree_insert(packages, GINT_TO_POINTER(pkg_found->id), (gpointer)s_pkg);
i++;
};
pkg_found = NULL;
};
pkg_default = is_pkg_default(pkg->id);
if (((reg_action==REPLACE_PKG) || (reg_action==ADD_PKG)) && pkg_default) {
s_pkg = g_new0(s_h248_package_t,1);
s_pkg->is_default = FALSE;
s_pkg->pkg = (h248_package_t *)pkg;
g_tree_replace(packages, GINT_TO_POINTER(pkg->id), (gpointer)s_pkg);
return;
};
if(pkg_default) reg_action = MERGE_PKG_HIGH;
s_pkg = s_find_package_id(pkg->id);
if (s_pkg == NULL) {
s_pkg = g_new0(s_h248_package_t,1);
s_pkg->is_default = FALSE;
s_pkg->pkg = (h248_package_t *)pkg;
g_tree_insert(packages, GINT_TO_POINTER(pkg->id), (gpointer)s_pkg);
return;
}
pkg_found = s_pkg->pkg;
if (reg_action==MERGE_PKG_HIGH) {
pkg_high = (h248_package_t *)pkg;
pkg_low = pkg_found;
};
if (reg_action==MERGE_PKG_LOW) {
pkg_high = pkg_found;
pkg_low = (h248_package_t *)pkg;
};
(pkg_high->hfid ? (pkg_found->hfid=pkg_high->hfid) : (pkg_found->hfid=pkg_low->hfid));
(pkg_high->ett ? (pkg_found->ett=pkg_high->ett ):( pkg_found->ett=pkg_low->ett));
(pkg_high->param_names ? (pkg_found->param_names=pkg_high->param_names ):( pkg_found->param_names=pkg_low->param_names));
(pkg_high->signal_names ? (pkg_found->signal_names=pkg_high->signal_names ):( pkg_found->signal_names=pkg_low->signal_names));
(pkg_high->event_names ? (pkg_found->event_names=pkg_high->event_names ):( pkg_found->event_names=pkg_low->event_names));
(pkg_high->stats_names ? (pkg_found->stats_names=pkg_high->stats_names ):( pkg_found->stats_names=pkg_low->stats_names));
(pkg_high->properties ? (pkg_found->properties=pkg_high->properties ):( pkg_found->properties=pkg_low->properties));
(pkg_high->signals ? (pkg_found->signals=pkg_high->signals ):( pkg_found->signals=pkg_low->signals));
(pkg_high->events ? (pkg_found->events=pkg_high->events ):( pkg_found->events=pkg_low->events));
(pkg_high->statistics ? (pkg_found->statistics=pkg_high->statistics ):( pkg_found->statistics=pkg_low->statistics));
s_pkg->pkg = pkg_found;
s_pkg->is_default = FALSE;
}
static int dissect_h248_PkgdName(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb = NULL;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
packageandid=(name_major<<16)|name_minor;
pkg = find_package_id(name_major);
proto_item_append_text(actx->created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
package_tree = proto_item_add_subtree(actx->created_item, ett_packagename);
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"PkgName%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
}
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_248_pkg_param, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->param_names && ( strval = match_strval(name_minor, pkg->param_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,name_minor);
} else {
strval = ep_strdup_printf("Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Parameter: %s", strval);
}
} else {
pkg = &no_package;
}
curr_info.pkg = pkg;
return offset;
}
static int dissect_h248_EventName(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
const h248_pkg_evt_t* evt = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
packageandid=(name_major<<16)|name_minor;
pkg = find_package_id(name_major);
proto_item_append_text(actx->created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
package_tree = proto_item_add_subtree(actx->created_item, ett_packagename);
}
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
curr_info.pkg = pkg;
if (pkg->events) {
for (evt = pkg->events; evt->hfid; evt++) {
if (name_minor == evt->id) {
break;
}
}
if (! evt->hfid) evt = &no_event;
} else {
evt = &no_event;
}
curr_info.evt = evt;
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_h248_event_code, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->event_names && ( strval = match_strval(name_minor, pkg->event_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,name_minor);
} else {
strval = ep_strdup_printf("Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Event ID: %s", strval);
}
} else {
curr_info.pkg = &no_package;
curr_info.evt = &no_event;
}
return offset;
}
static int dissect_h248_SignalName(gboolean implicit_tag , tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb;
proto_tree *package_tree=NULL;
guint16 name_major, name_minor;
const h248_package_t* pkg = NULL;
const h248_pkg_sig_t* sig;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
name_major=tvb_get_ntohs(new_tvb, 0);
name_minor=tvb_get_ntohs(new_tvb, 2);
packageandid=(name_major<<16)|name_minor;
pkg = find_package_id(name_major);
proto_item_append_text(actx->created_item, " %s (%04x)",
val_to_str(0, pkg->param_names, "Unknown Package"),
name_major);
if(tree){
package_tree = proto_item_add_subtree(actx->created_item, ett_packagename);
}
proto_tree_add_uint_format(package_tree, hf_h248_pkg_name, tvb, offset-4, 2, name_major,
"%s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
if (pkg->signals) {
for (sig = pkg->signals; sig->hfid; sig++) {
if (name_minor == sig->id) {
break;
}
}
if (! sig->hfid) sig = &no_signal;
curr_info.pkg = pkg;
curr_info.sig = sig;
} else {
curr_info.pkg = &no_package;
curr_info.sig = &no_signal;
}
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_h248_signal_code, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->signal_names && ( strval = match_strval(name_minor, pkg->signal_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,name_minor);
} else {
strval = ep_strdup_printf("Unknown (%d)",name_minor);
}
proto_item_set_text(pi,"Signal ID: %s", strval);
}
} else {
curr_info.pkg = &no_package;
curr_info.sig = &no_signal;
}
return offset;
}
static int dissect_h248_PropertyID(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
gint8 class;
gboolean pc, ind;
gint32 tag;
guint32 len;
guint16 name_minor;
int end_offset;
const h248_package_t* pkg;
const h248_pkg_param_t* prop;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_text(tree, tvb, offset-2, 2, "H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", class, pc, tag);
return end_offset;
}
name_minor = packageandid & 0xffff;
pkg = (curr_info.pkg) ? curr_info.pkg : &no_package;
if (pkg->properties) {
for (prop = pkg->properties; prop && prop->hfid; prop++) {
if (name_minor == prop->id) {
break;
}
}
} else {
prop = &no_param;
}
if (prop && prop->hfid ) {
if (!prop->dissector) prop = &no_param;
prop->dissector(tree, tvb, actx->pinfo, *(prop->hfid), &curr_info, prop->data);
}
return end_offset;
}
static int dissect_h248_SigParameterName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
guint32 param_id = 0xffffffff;
const h248_pkg_param_t* sigpar;
const gchar* strval;
proto_item* pi;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &next_tvb);
pi = actx->created_item;
switch(tvb_length(next_tvb)) {
case 4: param_id = tvb_get_ntohl(next_tvb,0); break;
case 3: param_id = tvb_get_ntoh24(next_tvb,0); break;
case 2: param_id = tvb_get_ntohs(next_tvb,0); break;
case 1: param_id = tvb_get_guint8(next_tvb,0); break;
default: break;
}
curr_info.par = &no_param;
if (curr_info.sig && curr_info.sig->parameters) {
for(sigpar = curr_info.sig->parameters; sigpar->hfid; sigpar++) {
if (sigpar->id == param_id) {
curr_info.par = sigpar;
break;
}
}
}
if (curr_info.sig && curr_info.sig->param_names && ( strval = match_strval(param_id, curr_info.sig->param_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,param_id);
} else {
strval = ep_strdup_printf("Unknown (%d)",param_id);
}
proto_item_set_text(pi,"Parameter: %s", strval);
return offset;
}
static int dissect_h248_SigParamValue(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
int end_offset;
gint8 class;
gboolean pc, ind;
gint32 tag;
guint32 len;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_text(tree, tvb, offset-2, 2, "H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", class, pc, tag);
return end_offset;
}
if ( curr_info.par && curr_info.par->dissector) {
curr_info.par->dissector(tree, tvb, actx->pinfo, *(curr_info.par->hfid), &curr_info, curr_info.par->data);
}
return end_offset;
}
static int dissect_h248_SigParamValueV1(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
return dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
}
static int dissect_h248_EventParameterName(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
guint32 param_id = 0xffffffff;
const h248_pkg_param_t* evtpar;
const gchar* strval;
proto_item* pi;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &next_tvb);
pi = actx->created_item;
if (next_tvb) {
switch(tvb_length(next_tvb)) {
case 4: param_id = tvb_get_ntohl(next_tvb,0); break;
case 3: param_id = tvb_get_ntoh24(next_tvb,0); break;
case 2: param_id = tvb_get_ntohs(next_tvb,0); break;
case 1: param_id = tvb_get_guint8(next_tvb,0); break;
default: break;
}
}
curr_info.par = &no_param;
if (curr_info.evt && curr_info.evt->parameters) {
for(evtpar = curr_info.evt->parameters; evtpar->hfid; evtpar++) {
if (evtpar->id == param_id) {
curr_info.par = evtpar;
break;
}
}
} else {
curr_info.par = &no_param;
}
if (curr_info.evt && curr_info.evt->param_names && ( strval = match_strval(param_id, curr_info.evt->param_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,param_id);
} else {
strval = ep_strdup_printf("Unknown (%d)",param_id);
}
proto_item_set_text(pi,"Parameter: %s", strval);
return offset;
}
static int dissect_h248_EventParamValue(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
int old_offset, end_offset;
gint8 class1;
gboolean pc1, ind1;
gint32 tag1;
guint32 len1;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &class1, &pc1, &tag1);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len1, &ind1);
end_offset=offset+len1;
if( !(tag1==BER_UNI_TAG_OCTETSTRING || tag1==BER_UNI_TAG_BOOLEAN || BER_UNI_TAG_ENUMERATED)) {
proto_tree_add_text(tree, tvb, offset-2, 2, "H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", class1, pc1, tag1);
return end_offset;
}
next_tvb = tvb_new_subset(tvb,offset,len1,len1);
old_offset=offset;
offset = old_offset;
if ( curr_info.par && curr_info.par->dissector) {
curr_info.par->dissector(tree, next_tvb, actx->pinfo, *(curr_info.par->hfid), &curr_info, curr_info.par->data);
}
return end_offset;
}
static int dissect_h248_EventParamValueV1(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
return dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &tvb);
}
static int dissect_h248_MtpAddress(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index) {
tvbuff_t *new_tvb;
proto_tree *mtp_tree=NULL;
guint32 val;
int i, len, old_offset;
old_offset=offset;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
val=0;
len=tvb_length(new_tvb);
for(i=0;i<len;i++){
val= (val<<8)|tvb_get_guint8(new_tvb, i);
}
proto_item_append_text(actx->created_item, " NI = %d, PC = %d ( %d-%d )", val&0x03,val>>2,val&0x03,val>>2);
if(tree){
mtp_tree = proto_item_add_subtree(actx->created_item, ett_mtpaddress);
}
proto_tree_add_uint(mtp_tree, hf_h248_mtpaddress_ni, tvb, old_offset, offset-old_offset, val&0x03);
proto_tree_add_uint(mtp_tree, hf_h248_mtpaddress_pc, tvb, old_offset, offset-old_offset, val>>2);
}
return offset;
}
static void dissect_h248_tpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
dissect_tpkt_encap(tvb, pinfo, tree, h248_desegment, h248_handle);
}
static void
dissect_h248(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *h248_item;
asn1_ctx_t asn1_ctx;
h248_tree = NULL;
h248_tvb = NULL;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
curr_info.msg = NULL;
curr_info.trx = NULL;
curr_info.ctx = NULL;
curr_info.cmd = NULL;
curr_info.term = NULL;
curr_info.pkg = NULL;
curr_info.evt = NULL;
curr_info.sig = NULL;
curr_info.stat = NULL;
curr_info.par = NULL;
if(tvb_length(tvb)>=6){
if(!tvb_strneql(tvb, 0, "MEGACO", 6)){
static dissector_handle_t megaco_handle=NULL;
if(!megaco_handle){
megaco_handle = find_dissector("megaco");
}
if(megaco_handle){
call_dissector(megaco_handle, tvb, pinfo, tree);
return;
}
}
{
proto_item *hidden_item = NULL;
guint32 magic_num = 0, offset = 0;
magic_num = tvb_get_ntohl(tvb, offset);
hidden_item = proto_tree_add_uint(tree, hf_248_magic_num, tvb, offset, 4, magic_num);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if( dissector_try_uint(subdissector_table, magic_num, tvb, pinfo, tree) ) {
return;
}
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H.248");
if (tree) {
h248_item = proto_tree_add_item(tree, proto_h248, tvb, 0, -1, ENC_NA);
h248_tree = proto_item_add_subtree(h248_item, ett_h248);
}
dissect_h248_MegacoMessage(FALSE, tvb, 0, &asn1_ctx, h248_tree, -1);
}
void proto_register_h248(void) {
static hf_register_info hf[] = {
{ &hf_248_magic_num, {
"Magic Number for Avaya H248", "h248.magic_num", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_h248_mtpaddress_ni, {
"NI", "h248.mtpaddress.ni", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_h248_mtpaddress_pc, {
"PC", "h248.mtpaddress.pc", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_h248_pkg_name, {
"Package", "h248.package_name", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
NULL, 0, NULL, HFILL }},
{ &hf_248_pkg_param, {
"Parameter ID", "h248.package_paramid", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_h248_signal_code, {
"Signal ID", "h248.package_signalid", FT_UINT16, BASE_HEX,
NULL, 0, "Parameter ID", HFILL }},
{ &hf_h248_event_code, {
"Event ID", "h248.package_eventid", FT_UINT16, BASE_HEX,
NULL, 0, "Parameter ID", HFILL }},
{ &hf_h248_event_name, {
"Package and Event name", "h248.event_name", FT_UINT32, BASE_HEX|BASE_EXT_STRING,
NULL, 0, "Package", HFILL }},
{ &hf_h248_signal_name, {
"Package and Signal name", "h248.signal_name", FT_UINT32, BASE_HEX|BASE_EXT_STRING,
NULL, 0, "Package", HFILL }},
{ &hf_h248_pkg_bcp_BNCChar_PDU,
{ "BNCChar", "h248.package_bcp.BNCChar",
FT_UINT32, BASE_DEC, VALS(gcp_term_types), 0,
NULL, HFILL }},
{ &hf_h248_error_code,
{ "errorCode", "h248.errorCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &h248_reasons_ext, 0,
"ErrorDescriptor/errorCode", HFILL }},
{ &hf_h248_context_id,
{ "contextId", "h248.contextId",
FT_UINT32, BASE_HEX, NULL, 0,
"Context ID", HFILL }},
{ &hf_h248_term_wild_type,
{ "Wildcard Mode", "h248.term.wildcard.mode",
FT_UINT8, BASE_DEC, VALS(wildcard_modes), 0x80,
NULL, HFILL }},
{ &hf_h248_term_wild_level,
{ "Wildcarding Level", "h248.term.wildcard.level",
FT_UINT8, BASE_DEC, VALS(wildcard_levels), 0x40,
NULL, HFILL }},
{ &hf_h248_term_wild_position,
{ "Wildcarding Position", "h248.term.wildcard.pos",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }},
{ &hf_h248_no_pkg,
{ "Unknown Package", "h248.pkg.unknown",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_no_sig,
{ "Unknown Signal", "h248.pkg.unknown.sig",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_no_evt,
{ "Unknown Event", "h248.pkg.unknown.evt",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_param,
{ "Parameter", "h248.pkg.unknown.param",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeReasonStr,
{ "ServiceChangeReasonStr", "h248.serviceChangeReasonstr",
FT_STRING, BASE_NONE, NULL, 0,
"h248.IA5String", HFILL }},
{ &hf_h248_auditValueReplyV1,
{ "auditValueReplyV1", "h248.auditValueReplyV1",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-h248-hfarr.c"
GCP_HF_ARR_ELEMS("h248",h248_arrel)
};
static gint *ett[] = {
&ett_h248,
&ett_mtpaddress,
&ett_packagename,
&ett_codec,
&ett_wildcard,
&ett_h248_no_pkg,
&ett_h248_no_sig,
&ett_h248_no_evt,
GCP_ETT_ARR_ELEMS(h248_arrel),
#include "packet-h248-ettarr.c"
};
module_t *h248_module;
proto_h248 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("h248", dissect_h248, proto_h248);
register_dissector("h248.tpkt", dissect_h248_tpkt, proto_h248);
proto_register_field_array(proto_h248, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
subdissector_table = register_dissector_table("h248.magic_num", "H248 Magic Num", FT_UINT32, BASE_HEX);
h248_module = prefs_register_protocol(proto_h248, proto_reg_handoff_h248);
prefs_register_bool_preference(h248_module, "ctx_info",
"Track Context",
"Mantain relationships between transactions and contexts and display an extra tree showing context data",
&keep_persistent_data);
prefs_register_uint_preference(h248_module, "udp_port",
"UDP port",
"Port to be decoded as h248",
10,
&global_udp_port);
prefs_register_uint_preference(h248_module, "tcp_port",
"TCP port",
"Port to be decoded as h248",
10,
&global_tcp_port);
prefs_register_bool_preference(h248_module, "desegment",
"Desegment H.248 over TCP",
"Desegment H.248 messages that span more TCP segments",
&h248_desegment);
msgs = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "h248_msgs");
trxs = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "h248_trxs");
ctxs_by_trx = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "h248_ctxs_by_trx");
ctxs = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "h248_ctxs");
h248_tap = register_tap("h248");
gcp_init();
}
void proto_reg_handoff_h248(void) {
static gboolean initialized = FALSE;
static guint32 udp_port;
static guint32 tcp_port;
if (!initialized) {
h248_handle = find_dissector("h248");
h248_tpkt_handle = find_dissector("h248.tpkt");
dissector_add_uint("mtp3.service_indicator", MTP_SI_GCP, h248_handle);
h248_term_handle = find_dissector("h248term");
initialized = TRUE;
} else {
if (udp_port != 0)
dissector_delete_uint("udp.port", udp_port, h248_handle);
if (tcp_port != 0)
dissector_delete_uint("tcp.port", tcp_port, h248_tpkt_handle);
}
udp_port = global_udp_port;
tcp_port = global_tcp_port;
if (udp_port != 0) {
dissector_add_uint("udp.port", udp_port, h248_handle);
}
if (tcp_port != 0) {
dissector_add_uint("tcp.port", tcp_port, h248_tpkt_handle);
}
}
