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
if (pkg->signal_names && ( strval = try_val_to_str(name_minor, pkg->signal_names) )) {
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
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint32 i;
if(!implicit_tag){
offset=dissect_ber_identifier(pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
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
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint64 ctx_id = 0;
guint32 i;
if(!implicit_tag){
offset=dissect_ber_identifier(pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
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
s_pkg = (s_h248_package_t *)g_tree_lookup(packages, GUINT_TO_POINTER((guint32)(pkgid)));
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
s_pkg = (s_h248_package_t *)g_tree_lookup(packages, GUINT_TO_POINTER((guint32)(pkgid)));
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
vst = (value_string *)wmem_alloc0(wmem_epan_scope(), sizeof(value_string)*2);
vst[0].strptr = base_package_name_vals[i].strptr;
pkg_found->param_names = vst;
pkg_found->hfid = &hf_h248_pkg_name;
pkg_found->ett = &ett_packagename;
try_val_to_str_idx((pkg_found->id)<<16,base_event_name_vals, &j);
if (j != -1) {
j++; idx=j;
while((base_event_name_vals[j].strptr!=NULL) && (((base_event_name_vals[j].value)>>16) == (pkg_found->id))) {
j++;
};
if (idx < j) {
vst = (value_string *)wmem_alloc0(wmem_epan_scope(), sizeof(value_string)*(j-idx+1));
for (k=0;idx<j;k++) {
vst[k].strptr = base_event_name_vals[idx].strptr;
vst[k].value = (base_event_name_vals[idx].value & 0xffff);
idx++;
};
pkg_found->event_names = vst;
}
}
if (!try_val_to_str_idx((pkg_found->id)<<16, base_signal_name_vals, &j)) {
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
s_pkg = wmem_new0(wmem_epan_scope(), s_h248_package_t);
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
"PkgName: %s (0x%04x)", val_to_str(0, pkg->param_names, "Unknown Package"), name_major);
}
{
proto_item* pi = proto_tree_add_uint(package_tree, hf_248_pkg_param, tvb, offset-2, 2, name_minor);
const gchar* strval;
if (pkg->param_names && ( strval = try_val_to_str(name_minor, pkg->param_names) )) {
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
if (pkg->event_names && ( strval = try_val_to_str(name_minor, pkg->event_names) )) {
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
if (pkg->signal_names && ( strval = try_val_to_str(name_minor, pkg->signal_names) )) {
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
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
guint16 name_minor;
int end_offset;
const h248_package_t* pkg;
const h248_pkg_param_t* prop;
tvbuff_t *next_tvb = NULL;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (ber_class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_text(tree, tvb, offset-2, 2, "H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", ber_class, pc, tag);
return end_offset;
}
next_tvb = tvb_new_subset(tvb,offset,len,len);
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
prop->dissector(tree, next_tvb, actx->pinfo, *(prop->hfid), &curr_info, prop->data);
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
if (curr_info.sig && curr_info.sig->param_names && ( strval = try_val_to_str(param_id, curr_info.sig->param_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,param_id);
} else {
strval = ep_strdup_printf("Unknown (%d)",param_id);
}
proto_item_set_text(pi,"Parameter: %s", strval);
return offset;
}
static int dissect_h248_SigParamValue(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
int end_offset;
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
tvbuff_t *next_tvb = NULL;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (ber_class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_text(tree, tvb, offset-2, 2, "H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", ber_class, pc, tag);
return end_offset;
}
next_tvb = tvb_new_subset(tvb,offset,len,len);
if ( curr_info.par && curr_info.par->dissector) {
curr_info.par->dissector(tree, next_tvb, actx->pinfo, *(curr_info.par->hfid), &curr_info, curr_info.par->data);
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
if (curr_info.evt && curr_info.evt->param_names && ( strval = try_val_to_str(param_id, curr_info.evt->param_names) )) {
strval = ep_strdup_printf("%s (%d)",strval,param_id);
} else {
strval = ep_strdup_printf("Unknown (%d)",param_id);
}
proto_item_set_text(pi,"Parameter: %s", strval);
return offset;
}
static int dissect_h248_EventParamValue(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_) {
tvbuff_t *next_tvb;
int end_offset;
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, &ind);
end_offset=offset+len;
if( (ber_class!=BER_CLASS_UNI)
||(tag!=BER_UNI_TAG_OCTETSTRING) ){
proto_tree_add_text(tree, tvb, offset-2, 2, "H.248 BER Error: OctetString expected but Class:%d PC:%d Tag:%d was unexpected", ber_class, pc, tag);
return end_offset;
}
next_tvb = tvb_new_subset(tvb,offset,len,len);
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
static int
dissect_h248_SecurityParmIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_SequenceNum(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_AuthData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_AuthenticationHeader(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuthenticationHeader_sequence, hf_index, ett_h248_AuthenticationHeader);
return offset;
}
static int
dissect_h248_T_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 108 "../../asn1/h248/h248.cnf"
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&h248_version);
return offset;
}
static int
dissect_h248_OCTET_STRING_SIZE_4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_INTEGER_0_65535(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_IP4Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IP4Address_sequence, hf_index, ett_h248_IP4Address);
return offset;
}
static int
dissect_h248_OCTET_STRING_SIZE_16(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_IP6Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IP6Address_sequence, hf_index, ett_h248_IP6Address);
return offset;
}
static int
dissect_h248_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_DomainName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DomainName_sequence, hf_index, ett_h248_DomainName);
return offset;
}
static int
dissect_h248_PathName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_MId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MId_choice, hf_index, ett_h248_MId,
NULL);
return offset;
}
static int
dissect_h248_T_errorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 302 "../../asn1/h248/h248.cnf"
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_h248_error_code, &error_code);
expert_add_info_format(actx->pinfo, actx->created_item, PI_RESPONSE_CODE, PI_WARN, "Errored Command");
if (curr_info.cmd) {
gcp_cmd_set_error(curr_info.cmd,error_code);
} else if (curr_info.trx) {
gcp_trx_set_error(curr_info.trx,error_code);
}
return offset;
return offset;
}
static int
dissect_h248_ErrorText(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_ErrorDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ErrorDescriptor_sequence, hf_index, ett_h248_ErrorDescriptor);
return offset;
}
static int
dissect_h248_TransactionId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_T_transactionId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 112 "../../asn1/h248/h248.cnf"
guint32 trx_id = 0;
offset = dissect_h248_trx_id(implicit_tag, actx->pinfo, tree, tvb, offset, &trx_id);
curr_info.trx = gcp_trx(curr_info.msg, trx_id, GCP_TRX_REQUEST, keep_persistent_data);
error_code = 0;
return offset;
}
static int
dissect_h248_ContextId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 137 "../../asn1/h248/h248.cnf"
guint32 ctx_id = 0;
offset = dissect_h248_ctx_id(implicit_tag, actx->pinfo, tree, tvb, offset, &ctx_id);
curr_info.ctx = gcp_ctx(curr_info.msg,curr_info.trx,ctx_id,keep_persistent_data);
curr_info.cmd = NULL;
curr_info.term = NULL;
return offset;
}
static int
dissect_h248_INTEGER_0_15(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_h248_WildcardField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 320 "../../asn1/h248/h248.cnf"
tvbuff_t* new_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
tree = proto_item_add_subtree(actx->created_item,ett_wildcard);
proto_tree_add_item(tree,hf_h248_term_wild_type,new_tvb,0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_h248_term_wild_level,new_tvb,0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_h248_term_wild_position,new_tvb,0,1,ENC_BIG_ENDIAN);
wild_term = tvb_get_guint8(new_tvb,0) & 0x80 ? GCP_WILDCARD_CHOOSE : GCP_WILDCARD_ALL;
wild_card = tvb_get_guint8(new_tvb,0);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_WildcardField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_WildcardField_sequence_of, hf_index, ett_h248_SEQUENCE_OF_WildcardField);
return offset;
}
static int
dissect_h248_T_terminationId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 334 "../../asn1/h248/h248.cnf"
tvbuff_t* new_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
curr_info.term->len = tvb_length(new_tvb);
curr_info.term->type = 0;
if (curr_info.term->len) {
curr_info.term->buffer = (guint8 *)ep_tvb_memdup(new_tvb,0,curr_info.term->len);
curr_info.term->str = bytes_to_str(curr_info.term->buffer,curr_info.term->len);
}
curr_info.term = gcp_cmd_add_term(curr_info.msg, curr_info.trx, curr_info.cmd, curr_info.term, wild_term, keep_persistent_data);
if (h248_term_handle) {
actx->pinfo->private_data = &wild_card;
call_dissector(h248_term_handle, new_tvb, actx->pinfo, tree);
wild_card = 0xFF;
}
} else {
curr_info.term->len = 0;
curr_info.term->buffer = (guint8*)ep_strdup("");
curr_info.term->str = ep_strdup("?");
}
return offset;
}
static int
dissect_h248_TerminationID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 315 "../../asn1/h248/h248.cnf"
curr_info.term = ep_new0(gcp_term_t);
wild_term = GCP_WILDCARD_NONE;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminationID_sequence, hf_index, ett_h248_TerminationID);
return offset;
}
static int
dissect_h248_T_topologyDirection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_StreamID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_T_topologyDirectionExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_TopologyRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TopologyRequest_sequence, hf_index, ett_h248_TopologyRequest);
return offset;
}
static int
dissect_h248_T_topologyReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 220 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_TOPOLOGY_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_topologyReq_sequence_of, hf_index, ett_h248_T_topologyReq);
#line 224 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_Iepscallind_BOOL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_h248_PropertyName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h248_PkgdName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_PropertyID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PropertyID_sequence_of, hf_index, ett_h248_SEQUENCE_OF_PropertyID);
return offset;
}
static int
dissect_h248_Relation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_PropParm_extraInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PropParm_extraInfo_choice, hf_index, ett_h248_PropParm_extraInfo,
NULL);
return offset;
}
static int
dissect_h248_PropertyParm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PropertyParm_sequence, hf_index, ett_h248_PropertyParm);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_PropertyParm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PropertyParm_sequence_of, hf_index, ett_h248_SEQUENCE_OF_PropertyParm);
return offset;
}
static int
dissect_h248_ContextIDinList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_ContextIDinList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ContextIDinList_sequence_of, hf_index, ett_h248_SEQUENCE_OF_ContextIDinList);
return offset;
}
static int
dissect_h248_ContextRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContextRequest_sequence, hf_index, ett_h248_ContextRequest);
return offset;
}
static int
dissect_h248_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_h248_IndAudPropertyParm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudPropertyParm_sequence, hf_index, ett_h248_IndAudPropertyParm);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_IndAudPropertyParm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_IndAudPropertyParm_sequence_of, hf_index, ett_h248_SEQUENCE_OF_IndAudPropertyParm);
return offset;
}
static int
dissect_h248_SelectLogic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SelectLogic_choice, hf_index, ett_h248_SelectLogic,
NULL);
return offset;
}
static int
dissect_h248_ContextAttrAuditRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContextAttrAuditRequest_sequence, hf_index, ett_h248_ContextAttrAuditRequest);
return offset;
}
static int
dissect_h248_T_contextAttrAuditReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 228 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_CTX_ATTR_AUDIT_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_ContextAttrAuditRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 232 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_TerminationIDList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TerminationIDList_sequence_of, hf_index, ett_h248_TerminationIDList);
return offset;
}
static int
dissect_h248_EventBufferControl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_ServiceState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_TerminationStateDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminationStateDescriptor_sequence, hf_index, ett_h248_TerminationStateDescriptor);
return offset;
}
static int
dissect_h248_StreamMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_LocalControlDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LocalControlDescriptor_sequence, hf_index, ett_h248_LocalControlDescriptor);
return offset;
}
static int
dissect_h248_PropertyGroup(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PropertyGroup_sequence_of, hf_index, ett_h248_PropertyGroup);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_PropertyGroup(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PropertyGroup_sequence_of, hf_index, ett_h248_SEQUENCE_OF_PropertyGroup);
return offset;
}
static int
dissect_h248_LocalRemoteDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LocalRemoteDescriptor_sequence, hf_index, ett_h248_LocalRemoteDescriptor);
return offset;
}
static int
dissect_h248_StatName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h248_PkgdName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_Value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Value_sequence_of, hf_index, ett_h248_Value);
return offset;
}
static int
dissect_h248_StatValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h248_Value(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_StatisticsParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StatisticsParameter_sequence, hf_index, ett_h248_StatisticsParameter);
return offset;
}
static int
dissect_h248_StatisticsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
StatisticsDescriptor_sequence_of, hf_index, ett_h248_StatisticsDescriptor);
return offset;
}
static int
dissect_h248_StreamParms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StreamParms_sequence, hf_index, ett_h248_StreamParms);
return offset;
}
static int
dissect_h248_StreamDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StreamDescriptor_sequence, hf_index, ett_h248_StreamDescriptor);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_StreamDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_StreamDescriptor_sequence_of, hf_index, ett_h248_SEQUENCE_OF_StreamDescriptor);
return offset;
}
static int
dissect_h248_T_streams(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_streams_choice, hf_index, ett_h248_T_streams,
NULL);
return offset;
}
static int
dissect_h248_MediaDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MediaDescriptor_sequence, hf_index, ett_h248_MediaDescriptor);
return offset;
}
static int
dissect_h248_ModemType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_ModemType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ModemType_sequence_of, hf_index, ett_h248_SEQUENCE_OF_ModemType);
return offset;
}
static int
dissect_h248_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_h248_INTEGER_0_255(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_H221NonStandard(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
H221NonStandard_sequence, hf_index, ett_h248_H221NonStandard);
return offset;
}
static int
dissect_h248_IA5String_SIZE_8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_NonStandardIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NonStandardIdentifier_choice, hf_index, ett_h248_NonStandardIdentifier,
NULL);
return offset;
}
static int
dissect_h248_NonStandardData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NonStandardData_sequence, hf_index, ett_h248_NonStandardData);
return offset;
}
static int
dissect_h248_ModemDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModemDescriptor_sequence, hf_index, ett_h248_ModemDescriptor);
return offset;
}
static int
dissect_h248_MuxType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_TerminationID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_TerminationID_sequence_of, hf_index, ett_h248_SEQUENCE_OF_TerminationID);
return offset;
}
static int
dissect_h248_MuxDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MuxDescriptor_sequence, hf_index, ett_h248_MuxDescriptor);
return offset;
}
static int
dissect_h248_RequestID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_DigitMapName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h248_Name(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_INTEGER_0_99(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_DigitMapValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DigitMapValue_sequence, hf_index, ett_h248_DigitMapValue);
return offset;
}
static int
dissect_h248_EventDM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EventDM_choice, hf_index, ett_h248_EventDM,
NULL);
return offset;
}
static int
dissect_h248_SignalType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_NotifyCompletion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NotifyCompletion_bits, hf_index, ett_h248_NotifyCompletion,
NULL);
return offset;
}
static int
dissect_h248_SigParamValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SigParamValues_sequence_of, hf_index, ett_h248_SigParamValues);
return offset;
}
static int
dissect_h248_T_extraInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_extraInfo_choice, hf_index, ett_h248_T_extraInfo,
NULL);
return offset;
}
static int
dissect_h248_SigParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 423 "../../asn1/h248/h248.cnf"
if (h248_version > 1) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SigParameter_sequence, hf_index, ett_h248_SigParameter);
} else {
offset = dissect_h248_SigParameterV1( implicit_tag, tvb, offset, actx, tree, hf_index);
}
return offset;
}
static int
dissect_h248_SEQUENCE_OF_SigParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_SigParameter_sequence_of, hf_index, ett_h248_SEQUENCE_OF_SigParameter);
return offset;
}
static int
dissect_h248_SignalDirection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_Signal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Signal_sequence, hf_index, ett_h248_Signal);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_Signal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Signal_sequence_of, hf_index, ett_h248_SEQUENCE_OF_Signal);
return offset;
}
static int
dissect_h248_SeqSigList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SeqSigList_sequence, hf_index, ett_h248_SeqSigList);
return offset;
}
static int
dissect_h248_SignalRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SignalRequest_choice, hf_index, ett_h248_SignalRequest,
NULL);
return offset;
}
static int
dissect_h248_SignalsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SignalsDescriptor_sequence_of, hf_index, ett_h248_SignalsDescriptor);
return offset;
}
static int
dissect_h248_RegulatedEmbeddedDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RegulatedEmbeddedDescriptor_sequence, hf_index, ett_h248_RegulatedEmbeddedDescriptor);
return offset;
}
static int
dissect_h248_NotifyBehaviour(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NotifyBehaviour_choice, hf_index, ett_h248_NotifyBehaviour,
NULL);
return offset;
}
static int
dissect_h248_SecondRequestedActions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecondRequestedActions_sequence, hf_index, ett_h248_SecondRequestedActions);
return offset;
}
static int
dissect_h248_EventParamValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
EventParamValues_sequence_of, hf_index, ett_h248_EventParamValues);
return offset;
}
static int
dissect_h248_EventPar_extraInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EventPar_extraInfo_choice, hf_index, ett_h248_EventPar_extraInfo,
NULL);
return offset;
}
static int
dissect_h248_EventParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 414 "../../asn1/h248/h248.cnf"
if (h248_version > 1) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventParameter_sequence, hf_index, ett_h248_EventParameter);
} else {
offset = dissect_h248_EventParameterV1( implicit_tag, tvb, offset, actx, tree, hf_index);
}
return offset;
}
static int
dissect_h248_SEQUENCE_OF_EventParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_EventParameter_sequence_of, hf_index, ett_h248_SEQUENCE_OF_EventParameter);
return offset;
}
static int
dissect_h248_SecondRequestedEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecondRequestedEvent_sequence, hf_index, ett_h248_SecondRequestedEvent);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_SecondRequestedEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_SecondRequestedEvent_sequence_of, hf_index, ett_h248_SEQUENCE_OF_SecondRequestedEvent);
return offset;
}
static int
dissect_h248_SecondEventsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecondEventsDescriptor_sequence, hf_index, ett_h248_SecondEventsDescriptor);
return offset;
}
static int
dissect_h248_RequestedActions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestedActions_sequence, hf_index, ett_h248_RequestedActions);
return offset;
}
static int
dissect_h248_RequestedEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestedEvent_sequence, hf_index, ett_h248_RequestedEvent);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_RequestedEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_RequestedEvent_sequence_of, hf_index, ett_h248_SEQUENCE_OF_RequestedEvent);
return offset;
}
static int
dissect_h248_EventsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventsDescriptor_sequence, hf_index, ett_h248_EventsDescriptor);
return offset;
}
static int
dissect_h248_EventSpec(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventSpec_sequence, hf_index, ett_h248_EventSpec);
return offset;
}
static int
dissect_h248_EventBufferDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
EventBufferDescriptor_sequence_of, hf_index, ett_h248_EventBufferDescriptor);
return offset;
}
static int
dissect_h248_DigitMapDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DigitMapDescriptor_sequence, hf_index, ett_h248_DigitMapDescriptor);
return offset;
}
static int
dissect_h248_T_auditToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
T_auditToken_bits, hf_index, ett_h248_T_auditToken,
NULL);
return offset;
}
static int
dissect_h248_IndAudTerminationStateDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudTerminationStateDescriptor_sequence, hf_index, ett_h248_IndAudTerminationStateDescriptor);
return offset;
}
static int
dissect_h248_IndAudLocalControlDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudLocalControlDescriptor_sequence, hf_index, ett_h248_IndAudLocalControlDescriptor);
return offset;
}
static int
dissect_h248_IndAudPropertyGroup(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
IndAudPropertyGroup_sequence_of, hf_index, ett_h248_IndAudPropertyGroup);
return offset;
}
static int
dissect_h248_IndAudLocalRemoteDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudLocalRemoteDescriptor_sequence, hf_index, ett_h248_IndAudLocalRemoteDescriptor);
return offset;
}
static int
dissect_h248_IndAudStatisticsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudStatisticsDescriptor_sequence, hf_index, ett_h248_IndAudStatisticsDescriptor);
return offset;
}
static int
dissect_h248_IndAudStreamParms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudStreamParms_sequence, hf_index, ett_h248_IndAudStreamParms);
return offset;
}
static int
dissect_h248_IndAudStreamDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudStreamDescriptor_sequence, hf_index, ett_h248_IndAudStreamDescriptor);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_IndAudStreamDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_IndAudStreamDescriptor_sequence_of, hf_index, ett_h248_SEQUENCE_OF_IndAudStreamDescriptor);
return offset;
}
static int
dissect_h248_IndAudMediaDescriptorStreams(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IndAudMediaDescriptorStreams_choice, hf_index, ett_h248_IndAudMediaDescriptorStreams,
NULL);
return offset;
}
static int
dissect_h248_IndAudMediaDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudMediaDescriptor_sequence, hf_index, ett_h248_IndAudMediaDescriptor);
return offset;
}
static int
dissect_h248_IndAudEventsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudEventsDescriptor_sequence, hf_index, ett_h248_IndAudEventsDescriptor);
return offset;
}
static int
dissect_h248_IndAudEventBufferDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudEventBufferDescriptor_sequence, hf_index, ett_h248_IndAudEventBufferDescriptor);
return offset;
}
static int
dissect_h248_IndAudSignal(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudSignal_sequence, hf_index, ett_h248_IndAudSignal);
return offset;
}
static int
dissect_h248_IndAudSeqSigList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudSeqSigList_sequence, hf_index, ett_h248_IndAudSeqSigList);
return offset;
}
static int
dissect_h248_IndAudSignalsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IndAudSignalsDescriptor_choice, hf_index, ett_h248_IndAudSignalsDescriptor,
NULL);
return offset;
}
static int
dissect_h248_IndAudDigitMapDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudDigitMapDescriptor_sequence, hf_index, ett_h248_IndAudDigitMapDescriptor);
return offset;
}
static int
dissect_h248_IndAudPackagesDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IndAudPackagesDescriptor_sequence, hf_index, ett_h248_IndAudPackagesDescriptor);
return offset;
}
static int
dissect_h248_IndAuditParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IndAuditParameter_choice, hf_index, ett_h248_IndAuditParameter,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_IndAuditParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_IndAuditParameter_sequence_of, hf_index, ett_h248_SEQUENCE_OF_IndAuditParameter);
return offset;
}
static int
dissect_h248_AuditDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuditDescriptor_sequence, hf_index, ett_h248_AuditDescriptor);
return offset;
}
static int
dissect_h248_AmmDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AmmDescriptor_choice, hf_index, ett_h248_AmmDescriptor,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_AmmDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AmmDescriptor_sequence_of, hf_index, ett_h248_SEQUENCE_OF_AmmDescriptor);
return offset;
}
static int
dissect_h248_AmmRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AmmRequest_sequence, hf_index, ett_h248_AmmRequest);
return offset;
}
static int
dissect_h248_T_addReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 153 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_ADD_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 158 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_T_moveReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 162 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_MOVE_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 168 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_T_modReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 172 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_MOD_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 176 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_SubtractRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubtractRequest_sequence, hf_index, ett_h248_SubtractRequest);
return offset;
}
static int
dissect_h248_T_subtractReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 180 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_SUB_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_SubtractRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 184 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_AuditRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuditRequest_sequence, hf_index, ett_h248_AuditRequest);
return offset;
}
static int
dissect_h248_T_auditCapRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 188 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_AUDITCAP_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AuditRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 192 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_T_auditValueRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 196 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_AUDITVAL_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AuditRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 200 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_TimeNotation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TimeNotation_sequence, hf_index, ett_h248_TimeNotation);
return offset;
}
static int
dissect_h248_ObservedEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ObservedEvent_sequence, hf_index, ett_h248_ObservedEvent);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_ObservedEvent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ObservedEvent_sequence_of, hf_index, ett_h248_SEQUENCE_OF_ObservedEvent);
return offset;
}
static int
dissect_h248_ObservedEventsDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ObservedEventsDescriptor_sequence, hf_index, ett_h248_ObservedEventsDescriptor);
return offset;
}
static int
dissect_h248_NotifyRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NotifyRequest_sequence, hf_index, ett_h248_NotifyRequest);
return offset;
}
static int
dissect_h248_T_notifyReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 204 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_NOTIFY_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_NotifyRequest(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 208 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_ServiceChangeMethod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_ServiceChangeAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ServiceChangeAddress_choice, hf_index, ett_h248_ServiceChangeAddress,
NULL);
return offset;
}
static int
dissect_h248_IA5String_SIZE_1_67(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_ServiceChangeProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceChangeProfile_sequence, hf_index, ett_h248_ServiceChangeProfile);
return offset;
}
static int
dissect_h248_SCreasonValueOctetStr(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 373 "../../asn1/h248/h248.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_h248_ServiceChangeReasonStr(FALSE, parameter_tvb, 0, actx, tree, hf_h248_serviceChangeReasonStr);
return offset;
}
static int
dissect_h248_SCreasonValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 361 "../../asn1/h248/h248.cnf"
if ( h248_version > 1 ) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SCreasonValue_sequence_of, hf_index, ett_h248_SCreasonValue);
} else {
offset = dissect_h248_ValueV1( implicit_tag, tvb, offset, actx, tree, hf_index);
};
return offset;
}
static int
dissect_h248_INTEGER_0_4294967295(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_ServiceChangeParm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceChangeParm_sequence, hf_index, ett_h248_ServiceChangeParm);
return offset;
}
static int
dissect_h248_ServiceChangeRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 212 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_SVCCHG_REQ,offset,keep_persistent_data);
H248_TAP();
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceChangeRequest_sequence, hf_index, ett_h248_ServiceChangeRequest);
#line 216 "../../asn1/h248/h248.cnf"
curr_info.cmd = NULL;
return offset;
}
static int
dissect_h248_Command(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Command_choice, hf_index, ett_h248_Command,
NULL);
return offset;
}
static int
dissect_h248_CommandRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CommandRequest_sequence, hf_index, ett_h248_CommandRequest);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_CommandRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CommandRequest_sequence_of, hf_index, ett_h248_SEQUENCE_OF_CommandRequest);
return offset;
}
static int
dissect_h248_ActionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ActionRequest_sequence, hf_index, ett_h248_ActionRequest);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_ActionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ActionRequest_sequence_of, hf_index, ett_h248_SEQUENCE_OF_ActionRequest);
return offset;
}
static int
dissect_h248_TransactionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TransactionRequest_sequence, hf_index, ett_h248_TransactionRequest);
return offset;
}
static int
dissect_h248_T_tpend_transactionId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 119 "../../asn1/h248/h248.cnf"
guint32 trx_id = 0;
offset = dissect_h248_trx_id(implicit_tag, actx->pinfo, tree, tvb, offset, &trx_id);
curr_info.trx = gcp_trx(curr_info.msg, trx_id, GCP_TRX_PENDING, keep_persistent_data);
error_code = 0;
return offset;
}
static int
dissect_h248_TransactionPending(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TransactionPending_sequence, hf_index, ett_h248_TransactionPending);
return offset;
}
static int
dissect_h248_T_trep_transactionId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 125 "../../asn1/h248/h248.cnf"
guint32 trx_id = 0;
offset = dissect_h248_trx_id(implicit_tag, actx->pinfo, tree, tvb, offset, &trx_id);
curr_info.trx = gcp_trx(curr_info.msg, trx_id, GCP_TRX_REPLY, keep_persistent_data);
error_code = 0;
return offset;
}
static int
dissect_h248_PackagesItem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PackagesItem_sequence, hf_index, ett_h248_PackagesItem);
return offset;
}
static int
dissect_h248_PackagesDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PackagesDescriptor_sequence_of, hf_index, ett_h248_PackagesDescriptor);
return offset;
}
static int
dissect_h248_AuditReturnParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AuditReturnParameter_choice, hf_index, ett_h248_AuditReturnParameter,
NULL);
return offset;
}
static int
dissect_h248_TerminationAudit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TerminationAudit_sequence_of, hf_index, ett_h248_TerminationAudit);
return offset;
}
static int
dissect_h248_AmmsReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AmmsReply_sequence, hf_index, ett_h248_AmmsReply);
return offset;
}
static int
dissect_h248_T_addReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 236 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_ADD_REPLY,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmsReply(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_T_moveReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 241 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_MOVE_REPLY,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmsReply(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_T_modReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 246 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_MOD_REPLY,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmsReply(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_T_subtractReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 251 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_SUB_REPLY,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_AmmsReply(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_AuditResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuditResult_sequence, hf_index, ett_h248_AuditResult);
return offset;
}
static int
dissect_h248_TermListAuditResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TermListAuditResult_sequence, hf_index, ett_h248_TermListAuditResult);
return offset;
}
static int
dissect_h248_AuditReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AuditReply_choice, hf_index, ett_h248_AuditReply,
NULL);
return offset;
}
static int
dissect_h248_T_auditCapReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 266 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_AUDITCAP_REPLY,offset,keep_persistent_data);
H248_TAP();
#line 271 "../../asn1/h248/h248.cnf"
if(h248_version > 1) {
offset = dissect_h248_AuditReply(implicit_tag, tvb, offset, actx, tree, hf_index);
} else {
offset = dissect_h248_AuditReplyV1(implicit_tag, tvb, offset, actx, tree, hf_index);
}
return offset;
}
static int
dissect_h248_T_auditValueReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 281 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_AUDITVAL_REPLY,offset,keep_persistent_data);
H248_TAP();
#line 286 "../../asn1/h248/h248.cnf"
if(h248_version > 1) {
offset = dissect_h248_AuditReply(implicit_tag, tvb, offset, actx, tree, hf_index);
} else {
offset = dissect_h248_AuditReplyV1(implicit_tag, tvb, offset, actx, tree, hf_index);
}
return offset;
}
static int
dissect_h248_NotifyReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NotifyReply_sequence, hf_index, ett_h248_NotifyReply);
return offset;
}
static int
dissect_h248_T_notifyReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 256 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_NOTIFY_REPLY,offset,keep_persistent_data);
H248_TAP();
offset = dissect_h248_NotifyReply(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h248_ServiceChangeResParm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceChangeResParm_sequence, hf_index, ett_h248_ServiceChangeResParm);
return offset;
}
static int
dissect_h248_ServiceChangeResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ServiceChangeResult_choice, hf_index, ett_h248_ServiceChangeResult,
NULL);
return offset;
}
static int
dissect_h248_ServiceChangeReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 261 "../../asn1/h248/h248.cnf"
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_SVCCHG_REPLY,offset,keep_persistent_data);
H248_TAP();
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceChangeReply_sequence, hf_index, ett_h248_ServiceChangeReply);
return offset;
}
static int
dissect_h248_CommandReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CommandReply_choice, hf_index, ett_h248_CommandReply,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_CommandReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_CommandReply_sequence_of, hf_index, ett_h248_SEQUENCE_OF_CommandReply);
return offset;
}
static int
dissect_h248_ActionReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ActionReply_sequence, hf_index, ett_h248_ActionReply);
#line 146 "../../asn1/h248/h248.cnf"
if (!curr_info.cmd) {
curr_info.cmd = gcp_cmd(curr_info.msg,curr_info.trx,curr_info.ctx,GCP_CMD_REPLY,offset,keep_persistent_data);
H248_TAP();
}
return offset;
}
static int
dissect_h248_SEQUENCE_OF_ActionReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ActionReply_sequence_of, hf_index, ett_h248_SEQUENCE_OF_ActionReply);
return offset;
}
static int
dissect_h248_T_transactionResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_transactionResult_choice, hf_index, ett_h248_T_transactionResult,
NULL);
return offset;
}
static int
dissect_h248_SegmentNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_TransactionReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TransactionReply_sequence, hf_index, ett_h248_TransactionReply);
return offset;
}
static int
dissect_h248_TransactionAck(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TransactionAck_sequence, hf_index, ett_h248_TransactionAck);
return offset;
}
static int
dissect_h248_TransactionResponseAck(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TransactionResponseAck_sequence_of, hf_index, ett_h248_TransactionResponseAck);
return offset;
}
static int
dissect_h248_T_seg_rep_transactionId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "../../asn1/h248/h248.cnf"
guint32 trx_id = 0;
offset = dissect_h248_trx_id(implicit_tag, actx->pinfo, tree, tvb, offset, &trx_id);
curr_info.trx = gcp_trx(curr_info.msg, trx_id, GCP_TRX_ACK, keep_persistent_data);
error_code = 0;
return offset;
}
static int
dissect_h248_SegmentReply(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SegmentReply_sequence, hf_index, ett_h248_SegmentReply);
return offset;
}
static int
dissect_h248_Transaction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Transaction_choice, hf_index, ett_h248_Transaction,
NULL);
return offset;
}
static int
dissect_h248_SEQUENCE_OF_Transaction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Transaction_sequence_of, hf_index, ett_h248_SEQUENCE_OF_Transaction);
return offset;
}
static int
dissect_h248_T_messageBody(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_messageBody_choice, hf_index, ett_h248_T_messageBody,
NULL);
return offset;
}
static int
dissect_h248_Message(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 97 "../../asn1/h248/h248.cnf"
curr_info.msg = gcp_msg(actx->pinfo,tvb_raw_offset(tvb),keep_persistent_data);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Message_sequence, hf_index, ett_h248_Message);
#line 101 "../../asn1/h248/h248.cnf"
col_add_str(actx->pinfo->cinfo, COL_INFO, gcp_msg_to_str(curr_info.msg,keep_persistent_data));
if (keep_persistent_data)
gcp_analyze_msg(h248_tree, h248_tvb, curr_info.msg, &h248_arrel);
return offset;
}
static int
dissect_h248_MegacoMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MegacoMessage_sequence, hf_index, ett_h248_MegacoMessage);
return offset;
}
static int
dissect_h248_ServiceChangeReasonStr(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_h248_AuditResultV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AuditResultV1_choice, hf_index, ett_h248_AuditResultV1,
NULL);
return offset;
}
static int
dissect_h248_AuditReplyV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 296 "../../asn1/h248/h248.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuditReplyV1_sequence, hf_h248_auditValueReplyV1, ett_h248_AuditReplyV1);
return offset;
}
static int
dissect_h248_EventParameterV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventParameterV1_sequence, hf_index, ett_h248_EventParameterV1);
return offset;
}
static int
dissect_h248_SigParameterV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SigParameterV1_sequence, hf_index, ett_h248_SigParameterV1);
return offset;
}
static int
dissect_h248_ValueV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 383 "../../asn1/h248/h248.cnf"
guint8 i;
guint32 len;
#line 388 "../../asn1/h248/h248.cnf"
len=tvb_length_remaining(tvb, offset);
if ( curr_info.par && curr_info.par->dissector) {
curr_info.par->dissector(tree, tvb, actx->pinfo, *(curr_info.par->hfid), &curr_info, curr_info.par->data);
} else {
for( i=0;i<len;i++) {
if(!isascii(tvb_get_guint8(tvb, offset+i)) || tvb_get_guint8(tvb, offset+i) == 0) {
proto_tree_add_text(tree, tvb, offset, len,"%s: 0x%s",
(proto_registrar_get_nth(hf_index))->name,
tvb_bytes_to_str(tvb, 0, len));
return len;
};
};
proto_tree_add_text(tree, tvb, offset, len,"%s: %s",
(proto_registrar_get_nth(hf_index))->name,
tvb_format_text(tvb, 0, len));
}
offset = len;
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
{ &hf_248_magic_num,
{ "Magic Number for Avaya H.248", "h248.magic_num",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL}},
{ &hf_h248_mtpaddress_ni,
{ "NI", "h248.mtpaddress.ni",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_mtpaddress_pc,
{ "PC", "h248.mtpaddress.pc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_pkg_name,
{ "Package", "h248.package_name",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_248_pkg_param,
{ "Parameter ID", "h248.package_paramid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signal_code,
{ "Signal ID", "h248.package_signalid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_event_code,
{ "Event ID", "h248.package_eventid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_event_name,
{ "Package and Event name", "h248.event_name",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signal_name,
{ "Package and Signal name", "h248.signal_name",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
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
#line 1 "../../asn1/h248/packet-h248-hfarr.c"
{ &hf_h248_authHeader,
{ "authHeader", "h248.authHeader",
FT_NONE, BASE_NONE, NULL, 0,
"AuthenticationHeader", HFILL }},
{ &hf_h248_mess,
{ "mess", "h248.mess",
FT_NONE, BASE_NONE, NULL, 0,
"Message", HFILL }},
{ &hf_h248_secParmIndex,
{ "secParmIndex", "h248.secParmIndex",
FT_BYTES, BASE_NONE, NULL, 0,
"SecurityParmIndex", HFILL }},
{ &hf_h248_seqNum,
{ "seqNum", "h248.seqNum",
FT_BYTES, BASE_NONE, NULL, 0,
"SequenceNum", HFILL }},
{ &hf_h248_ad,
{ "ad", "h248.ad",
FT_BYTES, BASE_NONE, NULL, 0,
"AuthData", HFILL }},
{ &hf_h248_version,
{ "version", "h248.version",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_mId,
{ "mId", "h248.mId",
FT_UINT32, BASE_DEC, VALS(h248_MId_vals), 0,
NULL, HFILL }},
{ &hf_h248_messageBody,
{ "messageBody", "h248.messageBody",
FT_UINT32, BASE_DEC, VALS(h248_T_messageBody_vals), 0,
NULL, HFILL }},
{ &hf_h248_messageError,
{ "messageError", "h248.messageError",
FT_NONE, BASE_NONE, NULL, 0,
"ErrorDescriptor", HFILL }},
{ &hf_h248_transactions,
{ "transactions", "h248.transactions",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Transaction", HFILL }},
{ &hf_h248_transactions_item,
{ "Transaction", "h248.Transaction",
FT_UINT32, BASE_DEC, VALS(h248_Transaction_vals), 0,
NULL, HFILL }},
{ &hf_h248_ip4Address,
{ "ip4Address", "h248.ip4Address",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_ip6Address,
{ "ip6Address", "h248.ip6Address",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_domainName,
{ "domainName", "h248.domainName",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_deviceName,
{ "deviceName", "h248.deviceName",
FT_STRING, BASE_NONE, NULL, 0,
"PathName", HFILL }},
{ &hf_h248_mtpAddress,
{ "mtpAddress", "h248.mtpAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_domName,
{ "name", "h248.name",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_h248_portNumber,
{ "portNumber", "h248.portNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h248_iP4Address,
{ "address", "h248.address",
FT_IPv4, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_h248_iP6Address,
{ "address", "h248.address",
FT_IPv6, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_16", HFILL }},
{ &hf_h248_transactionRequest,
{ "transactionRequest", "h248.transactionRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_transactionPending,
{ "transactionPending", "h248.transactionPending",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_transactionReply,
{ "transactionReply", "h248.transactionReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_transactionResponseAck,
{ "transactionResponseAck", "h248.transactionResponseAck",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_segmentReply,
{ "segmentReply", "h248.segmentReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_transactionId,
{ "transactionId", "h248.transactionId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_actions,
{ "actions", "h248.actions",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ActionRequest", HFILL }},
{ &hf_h248_actions_item,
{ "ActionRequest", "h248.ActionRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_tpend_transactionId,
{ "transactionId", "h248.transactionId",
FT_UINT32, BASE_DEC, NULL, 0,
"T_tpend_transactionId", HFILL }},
{ &hf_h248_trep_transactionId,
{ "transactionId", "h248.transactionId",
FT_UINT32, BASE_DEC, NULL, 0,
"T_trep_transactionId", HFILL }},
{ &hf_h248_immAckRequired,
{ "immAckRequired", "h248.immAckRequired",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_transactionResult,
{ "transactionResult", "h248.transactionResult",
FT_UINT32, BASE_DEC, VALS(h248_T_transactionResult_vals), 0,
NULL, HFILL }},
{ &hf_h248_transactionError,
{ "transactionError", "h248.transactionError",
FT_NONE, BASE_NONE, NULL, 0,
"ErrorDescriptor", HFILL }},
{ &hf_h248_actionReplies,
{ "actionReplies", "h248.actionReplies",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ActionReply", HFILL }},
{ &hf_h248_actionReplies_item,
{ "ActionReply", "h248.ActionReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_segmentNumber,
{ "segmentNumber", "h248.segmentNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_segmentationComplete,
{ "segmentationComplete", "h248.segmentationComplete",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_seg_rep_transactionId,
{ "transactionId", "h248.transactionId",
FT_UINT32, BASE_DEC, NULL, 0,
"T_seg_rep_transactionId", HFILL }},
{ &hf_h248_TransactionResponseAck_item,
{ "TransactionAck", "h248.TransactionAck",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_firstAck,
{ "firstAck", "h248.firstAck",
FT_UINT32, BASE_DEC, NULL, 0,
"TransactionId", HFILL }},
{ &hf_h248_lastAck,
{ "lastAck", "h248.lastAck",
FT_UINT32, BASE_DEC, NULL, 0,
"TransactionId", HFILL }},
{ &hf_h248_errorCode,
{ "errorCode", "h248.errorCode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_errorText,
{ "errorText", "h248.errorText",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextId,
{ "contextId", "h248.contextId",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextRequest,
{ "contextRequest", "h248.contextRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextAttrAuditReq,
{ "contextAttrAuditReq", "h248.contextAttrAuditReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_commandRequests,
{ "commandRequests", "h248.commandRequests",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CommandRequest", HFILL }},
{ &hf_h248_commandRequests_item,
{ "CommandRequest", "h248.CommandRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_errorDescriptor,
{ "errorDescriptor", "h248.errorDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextReply,
{ "contextReply", "h248.contextReply",
FT_NONE, BASE_NONE, NULL, 0,
"ContextRequest", HFILL }},
{ &hf_h248_commandReply,
{ "commandReply", "h248.commandReply",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CommandReply", HFILL }},
{ &hf_h248_commandReply_item,
{ "CommandReply", "h248.CommandReply",
FT_UINT32, BASE_DEC, VALS(h248_CommandReply_vals), 0,
NULL, HFILL }},
{ &hf_h248_priority,
{ "priority", "h248.priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_h248_emergency,
{ "emergency", "h248.emergency",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_topologyReq,
{ "topologyReq", "h248.topologyReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_topologyReq_item,
{ "TopologyRequest", "h248.TopologyRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iepscallind_BOOL,
{ "iepscallind", "h248.iepscallind",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"Iepscallind_BOOL", HFILL }},
{ &hf_h248_contextProp,
{ "contextProp", "h248.contextProp",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PropertyParm", HFILL }},
{ &hf_h248_contextProp_item,
{ "PropertyParm", "h248.PropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextList,
{ "contextList", "h248.contextList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ContextIDinList", HFILL }},
{ &hf_h248_contextList_item,
{ "ContextIDinList", "h248.ContextIDinList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_topology,
{ "topology", "h248.topology",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_cAAREmergency,
{ "emergency", "h248.emergency",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_cAARPriority,
{ "priority", "h248.priority",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iepscallind,
{ "iepscallind", "h248.iepscallind",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextPropAud,
{ "contextPropAud", "h248.contextPropAud",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_IndAudPropertyParm", HFILL }},
{ &hf_h248_contextPropAud_item,
{ "IndAudPropertyParm", "h248.IndAudPropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_selectpriority,
{ "selectpriority", "h248.selectpriority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_h248_selectemergency,
{ "selectemergency", "h248.selectemergency",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_selectiepscallind,
{ "selectiepscallind", "h248.selectiepscallind",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_selectLogic,
{ "selectLogic", "h248.selectLogic",
FT_UINT32, BASE_DEC, VALS(h248_SelectLogic_vals), 0,
NULL, HFILL }},
{ &hf_h248_andAUDITSelect,
{ "andAUDITSelect", "h248.andAUDITSelect",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_orAUDITSelect,
{ "orAUDITSelect", "h248.orAUDITSelect",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_command,
{ "command", "h248.command",
FT_UINT32, BASE_DEC, VALS(h248_Command_vals), 0,
NULL, HFILL }},
{ &hf_h248_optional,
{ "optional", "h248.optional",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_wildcardReturn,
{ "wildcardReturn", "h248.wildcardReturn",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_addReq,
{ "addReq", "h248.addReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_moveReq,
{ "moveReq", "h248.moveReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_modReq,
{ "modReq", "h248.modReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_subtractReq,
{ "subtractReq", "h248.subtractReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditCapRequest,
{ "auditCapRequest", "h248.auditCapRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditValueRequest,
{ "auditValueRequest", "h248.auditValueRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_notifyReq,
{ "notifyReq", "h248.notifyReq",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeReq,
{ "serviceChangeReq", "h248.serviceChangeReq",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceChangeRequest", HFILL }},
{ &hf_h248_addReply,
{ "addReply", "h248.addReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_moveReply,
{ "moveReply", "h248.moveReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_modReply,
{ "modReply", "h248.modReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_subtractReply,
{ "subtractReply", "h248.subtractReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditCapReply,
{ "auditCapReply", "h248.auditCapReply",
FT_UINT32, BASE_DEC, VALS(h248_AuditReply_vals), 0,
NULL, HFILL }},
{ &hf_h248_auditValueReply,
{ "auditValueReply", "h248.auditValueReply",
FT_UINT32, BASE_DEC, VALS(h248_AuditReply_vals), 0,
NULL, HFILL }},
{ &hf_h248_notifyReply,
{ "notifyReply", "h248.notifyReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeReply,
{ "serviceChangeReply", "h248.serviceChangeReply",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_terminationFrom,
{ "terminationFrom", "h248.terminationFrom",
FT_NONE, BASE_NONE, NULL, 0,
"TerminationID", HFILL }},
{ &hf_h248_terminationTo,
{ "terminationTo", "h248.terminationTo",
FT_NONE, BASE_NONE, NULL, 0,
"TerminationID", HFILL }},
{ &hf_h248_topologyDirection,
{ "topologyDirection", "h248.topologyDirection",
FT_UINT32, BASE_DEC, VALS(h248_T_topologyDirection_vals), 0,
NULL, HFILL }},
{ &hf_h248_streamID,
{ "streamID", "h248.streamID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_topologyDirectionExtension,
{ "topologyDirectionExtension", "h248.topologyDirectionExtension",
FT_UINT32, BASE_DEC, VALS(h248_T_topologyDirectionExtension_vals), 0,
NULL, HFILL }},
{ &hf_h248_terminationIDList,
{ "terminationID", "h248.terminationID",
FT_UINT32, BASE_DEC, NULL, 0,
"TerminationIDList", HFILL }},
{ &hf_h248_descriptors,
{ "descriptors", "h248.descriptors",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AmmDescriptor", HFILL }},
{ &hf_h248_descriptors_item,
{ "AmmDescriptor", "h248.AmmDescriptor",
FT_UINT32, BASE_DEC, VALS(h248_AmmDescriptor_vals), 0,
NULL, HFILL }},
{ &hf_h248_mediaDescriptor,
{ "mediaDescriptor", "h248.mediaDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_modemDescriptor,
{ "modemDescriptor", "h248.modemDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_muxDescriptor,
{ "muxDescriptor", "h248.muxDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventsDescriptor,
{ "eventsDescriptor", "h248.eventsDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventBufferDescriptor,
{ "eventBufferDescriptor", "h248.eventBufferDescriptor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signalsDescriptor,
{ "signalsDescriptor", "h248.signalsDescriptor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_digitMapDescriptor,
{ "digitMapDescriptor", "h248.digitMapDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditDescriptor,
{ "auditDescriptor", "h248.auditDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_aDstatisticsDescriptor,
{ "statisticsDescriptor", "h248.statisticsDescriptor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_terminationAudit,
{ "terminationAudit", "h248.terminationAudit",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_terminationID,
{ "terminationID", "h248.terminationID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_contextAuditResult,
{ "contextAuditResult", "h248.contextAuditResult",
FT_UINT32, BASE_DEC, NULL, 0,
"TerminationIDList", HFILL }},
{ &hf_h248_error,
{ "error", "h248.error",
FT_NONE, BASE_NONE, NULL, 0,
"ErrorDescriptor", HFILL }},
{ &hf_h248_auditResult,
{ "auditResult", "h248.auditResult",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditResultTermList,
{ "auditResultTermList", "h248.auditResultTermList",
FT_NONE, BASE_NONE, NULL, 0,
"TermListAuditResult", HFILL }},
{ &hf_h248_terminationAuditResult,
{ "terminationAuditResult", "h248.terminationAuditResult",
FT_UINT32, BASE_DEC, NULL, 0,
"TerminationAudit", HFILL }},
{ &hf_h248_TerminationAudit_item,
{ "AuditReturnParameter", "h248.AuditReturnParameter",
FT_UINT32, BASE_DEC, VALS(h248_AuditReturnParameter_vals), 0,
NULL, HFILL }},
{ &hf_h248_observedEventsDescriptor,
{ "observedEventsDescriptor", "h248.observedEventsDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_aRPstatisticsDescriptor,
{ "statisticsDescriptor", "h248.statisticsDescriptor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_packagesDescriptor,
{ "packagesDescriptor", "h248.packagesDescriptor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_emptyDescriptors,
{ "emptyDescriptors", "h248.emptyDescriptors",
FT_NONE, BASE_NONE, NULL, 0,
"AuditDescriptor", HFILL }},
{ &hf_h248_auditToken,
{ "auditToken", "h248.auditToken",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_auditPropertyToken,
{ "auditPropertyToken", "h248.auditPropertyToken",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_IndAuditParameter", HFILL }},
{ &hf_h248_auditPropertyToken_item,
{ "IndAuditParameter", "h248.IndAuditParameter",
FT_UINT32, BASE_DEC, VALS(h248_IndAuditParameter_vals), 0,
NULL, HFILL }},
{ &hf_h248_indaudmediaDescriptor,
{ "indaudmediaDescriptor", "h248.indaudmediaDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indaudeventsDescriptor,
{ "indaudeventsDescriptor", "h248.indaudeventsDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indaudeventBufferDescriptor,
{ "indaudeventBufferDescriptor", "h248.indaudeventBufferDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indaudsignalsDescriptor,
{ "indaudsignalsDescriptor", "h248.indaudsignalsDescriptor",
FT_UINT32, BASE_DEC, VALS(h248_IndAudSignalsDescriptor_vals), 0,
NULL, HFILL }},
{ &hf_h248_indauddigitMapDescriptor,
{ "indauddigitMapDescriptor", "h248.indauddigitMapDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indaudstatisticsDescriptor,
{ "indaudstatisticsDescriptor", "h248.indaudstatisticsDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indaudpackagesDescriptor,
{ "indaudpackagesDescriptor", "h248.indaudpackagesDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indAudTerminationStateDescriptor,
{ "termStateDescr", "h248.termStateDescr",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudTerminationStateDescriptor", HFILL }},
{ &hf_h248_indAudMediaDescriptorStreams,
{ "streams", "h248.streams",
FT_UINT32, BASE_DEC, VALS(h248_IndAudMediaDescriptorStreams_vals), 0,
"IndAudMediaDescriptorStreams", HFILL }},
{ &hf_h248_oneStream,
{ "oneStream", "h248.oneStream",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudStreamParms", HFILL }},
{ &hf_h248_multiStream,
{ "multiStream", "h248.multiStream",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_IndAudStreamDescriptor", HFILL }},
{ &hf_h248_multiStream_item,
{ "IndAudStreamDescriptor", "h248.IndAudStreamDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indAudStreamParms,
{ "streamParms", "h248.streamParms",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudStreamParms", HFILL }},
{ &hf_h248_iASPLocalControlDescriptor,
{ "localControlDescriptor", "h248.localControlDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudLocalControlDescriptor", HFILL }},
{ &hf_h248_iASPLocalDescriptor,
{ "localDescriptor", "h248.localDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudLocalRemoteDescriptor", HFILL }},
{ &hf_h248_iASPRemoteDescriptor,
{ "remoteDescriptor", "h248.remoteDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudLocalRemoteDescriptor", HFILL }},
{ &hf_h248_statisticsDescriptor,
{ "statisticsDescriptor", "h248.statisticsDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudStatisticsDescriptor", HFILL }},
{ &hf_h248_iALCDStreamMode,
{ "streamMode", "h248.streamMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iALCDReserveValue,
{ "reserveValue", "h248.reserveValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iALCDReserveGroup,
{ "reserveGroup", "h248.reserveGroup",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_indAudPropertyParms,
{ "propertyParms", "h248.propertyParms",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_IndAudPropertyParm", HFILL }},
{ &hf_h248_indAudPropertyParms_item,
{ "IndAudPropertyParm", "h248.IndAudPropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_streamModeSel,
{ "streamModeSel", "h248.streamModeSel",
FT_UINT32, BASE_DEC, VALS(h248_StreamMode_vals), 0,
"StreamMode", HFILL }},
{ &hf_h248_name,
{ "name", "h248.name",
FT_BYTES, BASE_NONE, NULL, 0,
"PkgdName", HFILL }},
{ &hf_h248_propertyParms,
{ "propertyParms", "h248.propertyParms",
FT_NONE, BASE_NONE, NULL, 0,
"PropertyParm", HFILL }},
{ &hf_h248_propGroupID,
{ "propGroupID", "h248.propGroupID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h248_iAPropertyGroup,
{ "propGrps", "h248.propGrps",
FT_UINT32, BASE_DEC, NULL, 0,
"IndAudPropertyGroup", HFILL }},
{ &hf_h248_IndAudPropertyGroup_item,
{ "IndAudPropertyParm", "h248.IndAudPropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventBufferControl,
{ "eventBufferControl", "h248.eventBufferControl",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iATSDServiceState,
{ "serviceState", "h248.serviceState",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceStateSel,
{ "serviceStateSel", "h248.serviceStateSel",
FT_UINT32, BASE_DEC, VALS(h248_ServiceState_vals), 0,
"ServiceState", HFILL }},
{ &hf_h248_requestID,
{ "requestID", "h248.requestID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iAEDPkgdName,
{ "pkgdName", "h248.pkgdName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iAEBDEventName,
{ "eventName", "h248.eventName",
FT_BYTES, BASE_NONE, NULL, 0,
"PkgdName", HFILL }},
{ &hf_h248_indAudSignal,
{ "signal", "h248.signal",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudSignal", HFILL }},
{ &hf_h248_indAudSeqSigList,
{ "seqSigList", "h248.seqSigList",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudSeqSigList", HFILL }},
{ &hf_h248_id,
{ "id", "h248.id",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h248_iASignalList,
{ "signalList", "h248.signalList",
FT_NONE, BASE_NONE, NULL, 0,
"IndAudSignal", HFILL }},
{ &hf_h248_iASignalName,
{ "signalName", "h248.signalName",
FT_BYTES, BASE_NONE, NULL, 0,
"PkgdName", HFILL }},
{ &hf_h248_signalRequestID,
{ "signalRequestID", "h248.signalRequestID",
FT_UINT32, BASE_DEC, NULL, 0,
"RequestID", HFILL }},
{ &hf_h248_digitMapName,
{ "digitMapName", "h248.digitMapName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_iAStatName,
{ "statName", "h248.statName",
FT_BYTES, BASE_NONE, NULL, 0,
"PkgdName", HFILL }},
{ &hf_h248_packageName,
{ "packageName", "h248.packageName",
FT_BYTES, BASE_NONE, NULL, 0,
"Name", HFILL }},
{ &hf_h248_packageVersion,
{ "packageVersion", "h248.packageVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_h248_requestId,
{ "requestId", "h248.requestId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_observedEventLst,
{ "observedEventLst", "h248.observedEventLst",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObservedEvent", HFILL }},
{ &hf_h248_observedEventLst_item,
{ "ObservedEvent", "h248.ObservedEvent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventName,
{ "eventName", "h248.eventName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventParList,
{ "eventParList", "h248.eventParList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_EventParameter", HFILL }},
{ &hf_h248_eventParList_item,
{ "EventParameter", "h248.EventParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_timeNotation,
{ "timeNotation", "h248.timeNotation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventParameterName,
{ "eventParameterName", "h248.eventParameterName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventParamValue,
{ "eventParamValue", "h248.eventParamValue",
FT_UINT32, BASE_DEC, NULL, 0,
"EventParamValues", HFILL }},
{ &hf_h248_eventPar_extraInfo,
{ "extraInfo", "h248.extraInfo",
FT_UINT32, BASE_DEC, VALS(h248_EventPar_extraInfo_vals), 0,
"EventPar_extraInfo", HFILL }},
{ &hf_h248_relation,
{ "relation", "h248.relation",
FT_UINT32, BASE_DEC, VALS(h248_Relation_vals), 0,
NULL, HFILL }},
{ &hf_h248_range,
{ "range", "h248.range",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_sublist,
{ "sublist", "h248.sublist",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_EventParamValues_item,
{ "EventParamValue", "h248.EventParamValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeParms,
{ "serviceChangeParms", "h248.serviceChangeParms",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceChangeParm", HFILL }},
{ &hf_h248_serviceChangeResult,
{ "serviceChangeResult", "h248.serviceChangeResult",
FT_UINT32, BASE_DEC, VALS(h248_ServiceChangeResult_vals), 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeResParms,
{ "serviceChangeResParms", "h248.serviceChangeResParms",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceChangeResParm", HFILL }},
{ &hf_h248_wildcard,
{ "wildcard", "h248.wildcard",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_WildcardField", HFILL }},
{ &hf_h248_wildcard_item,
{ "WildcardField", "h248.WildcardField",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_terminationId,
{ "id", "h248.id",
FT_BYTES, BASE_NONE, NULL, 0,
"T_terminationId", HFILL }},
{ &hf_h248_TerminationIDList_item,
{ "TerminationID", "h248.TerminationID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_termStateDescr,
{ "termStateDescr", "h248.termStateDescr",
FT_NONE, BASE_NONE, NULL, 0,
"TerminationStateDescriptor", HFILL }},
{ &hf_h248_streams,
{ "streams", "h248.streams",
FT_UINT32, BASE_DEC, VALS(h248_T_streams_vals), 0,
NULL, HFILL }},
{ &hf_h248_mediaDescriptorOneStream,
{ "oneStream", "h248.oneStream",
FT_NONE, BASE_NONE, NULL, 0,
"StreamParms", HFILL }},
{ &hf_h248_mediaDescriptorMultiStream,
{ "multiStream", "h248.multiStream",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_StreamDescriptor", HFILL }},
{ &hf_h248_mediaDescriptorMultiStream_item,
{ "StreamDescriptor", "h248.StreamDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_streamParms,
{ "streamParms", "h248.streamParms",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_localControlDescriptor,
{ "localControlDescriptor", "h248.localControlDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_localDescriptor,
{ "localDescriptor", "h248.localDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
"LocalRemoteDescriptor", HFILL }},
{ &hf_h248_remoteDescriptor,
{ "remoteDescriptor", "h248.remoteDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
"LocalRemoteDescriptor", HFILL }},
{ &hf_h248_sPstatisticsDescriptor,
{ "statisticsDescriptor", "h248.statisticsDescriptor",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_streamMode,
{ "streamMode", "h248.streamMode",
FT_UINT32, BASE_DEC, VALS(h248_StreamMode_vals), 0,
NULL, HFILL }},
{ &hf_h248_reserveValue,
{ "reserveValue", "h248.reserveValue",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_reserveGroup,
{ "reserveGroup", "h248.reserveGroup",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_lCDpropertyParms,
{ "propertyParms", "h248.propertyParms",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PropertyParm", HFILL }},
{ &hf_h248_lCDpropertyParms_item,
{ "PropertyParm", "h248.PropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_propertyName,
{ "propertyName", "h248.propertyName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_propertyParamValue,
{ "value", "h248.value",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PropertyID", HFILL }},
{ &hf_h248_propertyParamValue_item,
{ "PropertyID", "h248.PropertyID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_propParm_extraInfo,
{ "extraInfo", "h248.extraInfo",
FT_UINT32, BASE_DEC, VALS(h248_PropParm_extraInfo_vals), 0,
"PropParm_extraInfo", HFILL }},
{ &hf_h248_propGrps,
{ "propGrps", "h248.propGrps",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PropertyGroup", HFILL }},
{ &hf_h248_propGrps_item,
{ "PropertyGroup", "h248.PropertyGroup",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_PropertyGroup_item,
{ "PropertyParm", "h248.PropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_tSDpropertyParms,
{ "propertyParms", "h248.propertyParms",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PropertyParm", HFILL }},
{ &hf_h248_tSDpropertyParms_item,
{ "PropertyParm", "h248.PropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_tSEventBufferControl,
{ "eventBufferControl", "h248.eventBufferControl",
FT_UINT32, BASE_DEC, VALS(h248_EventBufferControl_vals), 0,
NULL, HFILL }},
{ &hf_h248_serviceState,
{ "serviceState", "h248.serviceState",
FT_UINT32, BASE_DEC, VALS(h248_ServiceState_vals), 0,
NULL, HFILL }},
{ &hf_h248_muxType,
{ "muxType", "h248.muxType",
FT_UINT32, BASE_DEC, VALS(h248_MuxType_vals), 0,
NULL, HFILL }},
{ &hf_h248_termList,
{ "termList", "h248.termList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TerminationID", HFILL }},
{ &hf_h248_termList_item,
{ "TerminationID", "h248.TerminationID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_nonStandardData,
{ "nonStandardData", "h248.nonStandardData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventList,
{ "eventList", "h248.eventList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RequestedEvent", HFILL }},
{ &hf_h248_eventList_item,
{ "RequestedEvent", "h248.RequestedEvent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_eventAction,
{ "eventAction", "h248.eventAction",
FT_NONE, BASE_NONE, NULL, 0,
"RequestedActions", HFILL }},
{ &hf_h248_evParList,
{ "evParList", "h248.evParList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_EventParameter", HFILL }},
{ &hf_h248_evParList_item,
{ "EventParameter", "h248.EventParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_secondEvent,
{ "secondEvent", "h248.secondEvent",
FT_NONE, BASE_NONE, NULL, 0,
"SecondEventsDescriptor", HFILL }},
{ &hf_h248_notifyImmediate,
{ "notifyImmediate", "h248.notifyImmediate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_notifyRegulated,
{ "notifyRegulated", "h248.notifyRegulated",
FT_NONE, BASE_NONE, NULL, 0,
"RegulatedEmbeddedDescriptor", HFILL }},
{ &hf_h248_neverNotify,
{ "neverNotify", "h248.neverNotify",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_keepActive,
{ "keepActive", "h248.keepActive",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h248_eventDM,
{ "eventDM", "h248.eventDM",
FT_UINT32, BASE_DEC, VALS(h248_EventDM_vals), 0,
NULL, HFILL }},
{ &hf_h248_notifyBehaviour,
{ "notifyBehaviour", "h248.notifyBehaviour",
FT_UINT32, BASE_DEC, VALS(h248_NotifyBehaviour_vals), 0,
NULL, HFILL }},
{ &hf_h248_resetEventsDescriptor,
{ "resetEventsDescriptor", "h248.resetEventsDescriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_digitMapValue,
{ "digitMapValue", "h248.digitMapValue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_secondaryEventList,
{ "eventList", "h248.eventList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SecondRequestedEvent", HFILL }},
{ &hf_h248_secondaryEventList_item,
{ "SecondRequestedEvent", "h248.SecondRequestedEvent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_pkgdName,
{ "pkgdName", "h248.pkgdName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_secondaryEventAction,
{ "eventAction", "h248.eventAction",
FT_NONE, BASE_NONE, NULL, 0,
"SecondRequestedActions", HFILL }},
{ &hf_h248_EventBufferDescriptor_item,
{ "EventSpec", "h248.EventSpec",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_SignalsDescriptor_item,
{ "SignalRequest", "h248.SignalRequest",
FT_UINT32, BASE_DEC, VALS(h248_SignalRequest_vals), 0,
NULL, HFILL }},
{ &hf_h248_signal,
{ "signal", "h248.signal",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_seqSigList,
{ "seqSigList", "h248.seqSigList",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signalList,
{ "signalList", "h248.signalList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Signal", HFILL }},
{ &hf_h248_signalList_item,
{ "Signal", "h248.Signal",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_signalName,
{ "signalName", "h248.signalName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_sigType,
{ "sigType", "h248.sigType",
FT_UINT32, BASE_DEC, VALS(h248_SignalType_vals), 0,
"SignalType", HFILL }},
{ &hf_h248_duration,
{ "duration", "h248.duration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h248_notifyCompletion,
{ "notifyCompletion", "h248.notifyCompletion",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_sigParList,
{ "sigParList", "h248.sigParList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SigParameter", HFILL }},
{ &hf_h248_sigParList_item,
{ "SigParameter", "h248.SigParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_direction,
{ "direction", "h248.direction",
FT_UINT32, BASE_DEC, VALS(h248_SignalDirection_vals), 0,
"SignalDirection", HFILL }},
{ &hf_h248_intersigDelay,
{ "intersigDelay", "h248.intersigDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h248_sigParameterName,
{ "sigParameterName", "h248.sigParameterName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_value,
{ "value", "h248.value",
FT_UINT32, BASE_DEC, NULL, 0,
"SigParamValues", HFILL }},
{ &hf_h248_extraInfo,
{ "extraInfo", "h248.extraInfo",
FT_UINT32, BASE_DEC, VALS(h248_T_extraInfo_vals), 0,
NULL, HFILL }},
{ &hf_h248_SigParamValues_item,
{ "SigParamValue", "h248.SigParamValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_mtl,
{ "mtl", "h248.mtl",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ModemType", HFILL }},
{ &hf_h248_mtl_item,
{ "ModemType", "h248.ModemType",
FT_UINT32, BASE_DEC, VALS(h248_ModemType_vals), 0,
NULL, HFILL }},
{ &hf_h248_mpl,
{ "mpl", "h248.mpl",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PropertyParm", HFILL }},
{ &hf_h248_mpl_item,
{ "PropertyParm", "h248.PropertyParm",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_startTimer,
{ "startTimer", "h248.startTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_h248_shortTimer,
{ "shortTimer", "h248.shortTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_h248_longTimer,
{ "longTimer", "h248.longTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_h248_digitMapBody,
{ "digitMapBody", "h248.digitMapBody",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_h248_durationTimer,
{ "durationTimer", "h248.durationTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_h248_serviceChangeMethod,
{ "serviceChangeMethod", "h248.serviceChangeMethod",
FT_UINT32, BASE_DEC, VALS(h248_ServiceChangeMethod_vals), 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeAddress,
{ "serviceChangeAddress", "h248.serviceChangeAddress",
FT_UINT32, BASE_DEC, VALS(h248_ServiceChangeAddress_vals), 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeVersion,
{ "serviceChangeVersion", "h248.serviceChangeVersion",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99", HFILL }},
{ &hf_h248_serviceChangeProfile,
{ "serviceChangeProfile", "h248.serviceChangeProfile",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_serviceChangeReason,
{ "serviceChangeReason", "h248.serviceChangeReason",
FT_UINT32, BASE_DEC, NULL, 0,
"SCreasonValue", HFILL }},
{ &hf_h248_serviceChangeDelay,
{ "serviceChangeDelay", "h248.serviceChangeDelay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h248_serviceChangeMgcId,
{ "serviceChangeMgcId", "h248.serviceChangeMgcId",
FT_UINT32, BASE_DEC, VALS(h248_MId_vals), 0,
"MId", HFILL }},
{ &hf_h248_timeStamp,
{ "timeStamp", "h248.timeStamp",
FT_NONE, BASE_NONE, NULL, 0,
"TimeNotation", HFILL }},
{ &hf_h248_serviceChangeInfo,
{ "serviceChangeInfo", "h248.serviceChangeInfo",
FT_NONE, BASE_NONE, NULL, 0,
"AuditDescriptor", HFILL }},
{ &hf_h248_serviceChangeIncompleteFlag,
{ "serviceChangeIncompleteFlag", "h248.serviceChangeIncompleteFlag",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_SCreasonValue_item,
{ "SCreasonValueOctetStr", "h248.SCreasonValueOctetStr",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_timestamp,
{ "timestamp", "h248.timestamp",
FT_NONE, BASE_NONE, NULL, 0,
"TimeNotation", HFILL }},
{ &hf_h248_profileName,
{ "profileName", "h248.profileName",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_67", HFILL }},
{ &hf_h248_PackagesDescriptor_item,
{ "PackagesItem", "h248.PackagesItem",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_StatisticsDescriptor_item,
{ "StatisticsParameter", "h248.StatisticsParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_statName,
{ "statName", "h248.statName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_statValue,
{ "statValue", "h248.statValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h248_nonStandardIdentifier,
{ "nonStandardIdentifier", "h248.nonStandardIdentifier",
FT_UINT32, BASE_DEC, VALS(h248_NonStandardIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_h248_data,
{ "data", "h248.data",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h248_object,
{ "object", "h248.object",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h248_h221NonStandard,
{ "h221NonStandard", "h248.h221NonStandard",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h248_experimental,
{ "experimental", "h248.experimental",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_8", HFILL }},
{ &hf_h248_t35CountryCode1,
{ "t35CountryCode1", "h248.t35CountryCode1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h248_t35CountryCode2,
{ "t35CountryCode2", "h248.t35CountryCode2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h248_t35Extension,
{ "t35Extension", "h248.t35Extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h248_manufacturerCode,
{ "manufacturerCode", "h248.manufacturerCode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h248_date,
{ "date", "h248.date",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_8", HFILL }},
{ &hf_h248_time,
{ "time", "h248.time",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_8", HFILL }},
{ &hf_h248_Value_item,
{ "Value item", "h248.Value_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h248_audit_result,
{ "auditResult", "h248.auditResult",
FT_UINT32, BASE_DEC, VALS(h248_AuditResultV1_vals), 0,
"AuditResultV1", HFILL }},
{ &hf_h248_contectAuditResult,
{ "contectAuditResult", "h248.contectAuditResult",
FT_NONE, BASE_NONE, NULL, 0,
"TerminationID", HFILL }},
{ &hf_h248_eventParamterName,
{ "eventParamterName", "h248.eventParamterName",
FT_BYTES, BASE_NONE, NULL, 0,
"EventParameterName", HFILL }},
{ &hf_h248_event_param_value,
{ "value", "h248.value",
FT_BYTES, BASE_NONE, NULL, 0,
"EventParamValueV1", HFILL }},
{ &hf_h248_sig_param_value,
{ "value", "h248.value",
FT_BYTES, BASE_NONE, NULL, 0,
"SigParamValueV1", HFILL }},
{ &hf_h248_T_auditToken_muxToken,
{ "muxToken", "h248.muxToken",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_h248_T_auditToken_modemToken,
{ "modemToken", "h248.modemToken",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_h248_T_auditToken_mediaToken,
{ "mediaToken", "h248.mediaToken",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_h248_T_auditToken_eventsToken,
{ "eventsToken", "h248.eventsToken",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_h248_T_auditToken_signalsToken,
{ "signalsToken", "h248.signalsToken",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_h248_T_auditToken_digitMapToken,
{ "digitMapToken", "h248.digitMapToken",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_h248_T_auditToken_statsToken,
{ "statsToken", "h248.statsToken",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_h248_T_auditToken_observedEventsToken,
{ "observedEventsToken", "h248.observedEventsToken",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_h248_T_auditToken_packagesToken,
{ "packagesToken", "h248.packagesToken",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_h248_T_auditToken_eventBufferToken,
{ "eventBufferToken", "h248.eventBufferToken",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_h248_NotifyCompletion_onTimeOut,
{ "onTimeOut", "h248.onTimeOut",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_h248_NotifyCompletion_onInterruptByEvent,
{ "onInterruptByEvent", "h248.onInterruptByEvent",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_h248_NotifyCompletion_onInterruptByNewSignalDescr,
{ "onInterruptByNewSignalDescr", "h248.onInterruptByNewSignalDescr",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_h248_NotifyCompletion_otherReason,
{ "otherReason", "h248.otherReason",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_h248_NotifyCompletion_onIteration,
{ "onIteration", "h248.onIteration",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
#line 1570 "../../asn1/h248/packet-h248-template.c"
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
#line 1 "../../asn1/h248/packet-h248-ettarr.c"
&ett_h248_MegacoMessage,
&ett_h248_AuthenticationHeader,
&ett_h248_Message,
&ett_h248_T_messageBody,
&ett_h248_SEQUENCE_OF_Transaction,
&ett_h248_MId,
&ett_h248_DomainName,
&ett_h248_IP4Address,
&ett_h248_IP6Address,
&ett_h248_Transaction,
&ett_h248_TransactionRequest,
&ett_h248_SEQUENCE_OF_ActionRequest,
&ett_h248_TransactionPending,
&ett_h248_TransactionReply,
&ett_h248_T_transactionResult,
&ett_h248_SEQUENCE_OF_ActionReply,
&ett_h248_SegmentReply,
&ett_h248_TransactionResponseAck,
&ett_h248_TransactionAck,
&ett_h248_ErrorDescriptor,
&ett_h248_ActionRequest,
&ett_h248_SEQUENCE_OF_CommandRequest,
&ett_h248_ActionReply,
&ett_h248_SEQUENCE_OF_CommandReply,
&ett_h248_ContextRequest,
&ett_h248_T_topologyReq,
&ett_h248_SEQUENCE_OF_PropertyParm,
&ett_h248_SEQUENCE_OF_ContextIDinList,
&ett_h248_ContextAttrAuditRequest,
&ett_h248_SEQUENCE_OF_IndAudPropertyParm,
&ett_h248_SelectLogic,
&ett_h248_CommandRequest,
&ett_h248_Command,
&ett_h248_CommandReply,
&ett_h248_TopologyRequest,
&ett_h248_AmmRequest,
&ett_h248_SEQUENCE_OF_AmmDescriptor,
&ett_h248_AmmDescriptor,
&ett_h248_AmmsReply,
&ett_h248_SubtractRequest,
&ett_h248_AuditRequest,
&ett_h248_AuditReply,
&ett_h248_AuditResult,
&ett_h248_TermListAuditResult,
&ett_h248_TerminationAudit,
&ett_h248_AuditReturnParameter,
&ett_h248_AuditDescriptor,
&ett_h248_T_auditToken,
&ett_h248_SEQUENCE_OF_IndAuditParameter,
&ett_h248_IndAuditParameter,
&ett_h248_IndAudMediaDescriptor,
&ett_h248_IndAudMediaDescriptorStreams,
&ett_h248_SEQUENCE_OF_IndAudStreamDescriptor,
&ett_h248_IndAudStreamDescriptor,
&ett_h248_IndAudStreamParms,
&ett_h248_IndAudLocalControlDescriptor,
&ett_h248_IndAudPropertyParm,
&ett_h248_IndAudLocalRemoteDescriptor,
&ett_h248_IndAudPropertyGroup,
&ett_h248_IndAudTerminationStateDescriptor,
&ett_h248_IndAudEventsDescriptor,
&ett_h248_IndAudEventBufferDescriptor,
&ett_h248_IndAudSignalsDescriptor,
&ett_h248_IndAudSeqSigList,
&ett_h248_IndAudSignal,
&ett_h248_IndAudDigitMapDescriptor,
&ett_h248_IndAudStatisticsDescriptor,
&ett_h248_IndAudPackagesDescriptor,
&ett_h248_NotifyRequest,
&ett_h248_NotifyReply,
&ett_h248_ObservedEventsDescriptor,
&ett_h248_SEQUENCE_OF_ObservedEvent,
&ett_h248_ObservedEvent,
&ett_h248_SEQUENCE_OF_EventParameter,
&ett_h248_EventParameter,
&ett_h248_EventPar_extraInfo,
&ett_h248_EventParamValues,
&ett_h248_ServiceChangeRequest,
&ett_h248_ServiceChangeReply,
&ett_h248_ServiceChangeResult,
&ett_h248_TerminationID,
&ett_h248_SEQUENCE_OF_WildcardField,
&ett_h248_TerminationIDList,
&ett_h248_MediaDescriptor,
&ett_h248_T_streams,
&ett_h248_SEQUENCE_OF_StreamDescriptor,
&ett_h248_StreamDescriptor,
&ett_h248_StreamParms,
&ett_h248_LocalControlDescriptor,
&ett_h248_PropertyParm,
&ett_h248_SEQUENCE_OF_PropertyID,
&ett_h248_PropParm_extraInfo,
&ett_h248_LocalRemoteDescriptor,
&ett_h248_SEQUENCE_OF_PropertyGroup,
&ett_h248_PropertyGroup,
&ett_h248_TerminationStateDescriptor,
&ett_h248_MuxDescriptor,
&ett_h248_SEQUENCE_OF_TerminationID,
&ett_h248_EventsDescriptor,
&ett_h248_SEQUENCE_OF_RequestedEvent,
&ett_h248_RequestedEvent,
&ett_h248_RegulatedEmbeddedDescriptor,
&ett_h248_NotifyBehaviour,
&ett_h248_RequestedActions,
&ett_h248_EventDM,
&ett_h248_SecondEventsDescriptor,
&ett_h248_SEQUENCE_OF_SecondRequestedEvent,
&ett_h248_SecondRequestedEvent,
&ett_h248_SecondRequestedActions,
&ett_h248_EventBufferDescriptor,
&ett_h248_EventSpec,
&ett_h248_SignalsDescriptor,
&ett_h248_SignalRequest,
&ett_h248_SeqSigList,
&ett_h248_SEQUENCE_OF_Signal,
&ett_h248_Signal,
&ett_h248_SEQUENCE_OF_SigParameter,
&ett_h248_NotifyCompletion,
&ett_h248_SigParameter,
&ett_h248_T_extraInfo,
&ett_h248_SigParamValues,
&ett_h248_ModemDescriptor,
&ett_h248_SEQUENCE_OF_ModemType,
&ett_h248_DigitMapDescriptor,
&ett_h248_DigitMapValue,
&ett_h248_ServiceChangeParm,
&ett_h248_SCreasonValue,
&ett_h248_ServiceChangeAddress,
&ett_h248_ServiceChangeResParm,
&ett_h248_ServiceChangeProfile,
&ett_h248_PackagesDescriptor,
&ett_h248_PackagesItem,
&ett_h248_StatisticsDescriptor,
&ett_h248_StatisticsParameter,
&ett_h248_NonStandardData,
&ett_h248_NonStandardIdentifier,
&ett_h248_H221NonStandard,
&ett_h248_TimeNotation,
&ett_h248_Value,
&ett_h248_AuditReplyV1,
&ett_h248_AuditResultV1,
&ett_h248_EventParameterV1,
&ett_h248_SigParameterV1,
#line 1588 "../../asn1/h248/packet-h248-template.c"
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
