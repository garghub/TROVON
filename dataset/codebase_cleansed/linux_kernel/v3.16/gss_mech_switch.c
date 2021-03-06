static void
gss_mech_free(struct gss_api_mech *gm)
{
struct pf_desc *pf;
int i;
for (i = 0; i < gm->gm_pf_num; i++) {
pf = &gm->gm_pfs[i];
kfree(pf->auth_domain_name);
pf->auth_domain_name = NULL;
}
}
static inline char *
make_auth_domain_name(char *name)
{
static char *prefix = "gss/";
char *new;
new = kmalloc(strlen(name) + strlen(prefix) + 1, GFP_KERNEL);
if (new) {
strcpy(new, prefix);
strcat(new, name);
}
return new;
}
static int
gss_mech_svc_setup(struct gss_api_mech *gm)
{
struct pf_desc *pf;
int i, status;
for (i = 0; i < gm->gm_pf_num; i++) {
pf = &gm->gm_pfs[i];
pf->auth_domain_name = make_auth_domain_name(pf->name);
status = -ENOMEM;
if (pf->auth_domain_name == NULL)
goto out;
status = svcauth_gss_register_pseudoflavor(pf->pseudoflavor,
pf->auth_domain_name);
if (status)
goto out;
}
return 0;
out:
gss_mech_free(gm);
return status;
}
int gss_mech_register(struct gss_api_mech *gm)
{
int status;
status = gss_mech_svc_setup(gm);
if (status)
return status;
spin_lock(&registered_mechs_lock);
list_add(&gm->gm_list, &registered_mechs);
spin_unlock(&registered_mechs_lock);
dprintk("RPC: registered gss mechanism %s\n", gm->gm_name);
return 0;
}
void gss_mech_unregister(struct gss_api_mech *gm)
{
spin_lock(&registered_mechs_lock);
list_del(&gm->gm_list);
spin_unlock(&registered_mechs_lock);
dprintk("RPC: unregistered gss mechanism %s\n", gm->gm_name);
gss_mech_free(gm);
}
struct gss_api_mech *gss_mech_get(struct gss_api_mech *gm)
{
__module_get(gm->gm_owner);
return gm;
}
static struct gss_api_mech *
_gss_mech_get_by_name(const char *name)
{
struct gss_api_mech *pos, *gm = NULL;
spin_lock(&registered_mechs_lock);
list_for_each_entry(pos, &registered_mechs, gm_list) {
if (0 == strcmp(name, pos->gm_name)) {
if (try_module_get(pos->gm_owner))
gm = pos;
break;
}
}
spin_unlock(&registered_mechs_lock);
return gm;
}
struct gss_api_mech * gss_mech_get_by_name(const char *name)
{
struct gss_api_mech *gm = NULL;
gm = _gss_mech_get_by_name(name);
if (!gm) {
request_module("rpc-auth-gss-%s", name);
gm = _gss_mech_get_by_name(name);
}
return gm;
}
struct gss_api_mech *gss_mech_get_by_OID(struct rpcsec_gss_oid *obj)
{
struct gss_api_mech *pos, *gm = NULL;
char buf[32];
if (sprint_oid(obj->data, obj->len, buf, sizeof(buf)) < 0)
return NULL;
dprintk("RPC: %s(%s)\n", __func__, buf);
request_module("rpc-auth-gss-%s", buf);
spin_lock(&registered_mechs_lock);
list_for_each_entry(pos, &registered_mechs, gm_list) {
if (obj->len == pos->gm_oid.len) {
if (0 == memcmp(obj->data, pos->gm_oid.data, obj->len)) {
if (try_module_get(pos->gm_owner))
gm = pos;
break;
}
}
}
spin_unlock(&registered_mechs_lock);
return gm;
}
static inline int
mech_supports_pseudoflavor(struct gss_api_mech *gm, u32 pseudoflavor)
{
int i;
for (i = 0; i < gm->gm_pf_num; i++) {
if (gm->gm_pfs[i].pseudoflavor == pseudoflavor)
return 1;
}
return 0;
}
static struct gss_api_mech *_gss_mech_get_by_pseudoflavor(u32 pseudoflavor)
{
struct gss_api_mech *gm = NULL, *pos;
spin_lock(&registered_mechs_lock);
list_for_each_entry(pos, &registered_mechs, gm_list) {
if (!mech_supports_pseudoflavor(pos, pseudoflavor))
continue;
if (try_module_get(pos->gm_owner))
gm = pos;
break;
}
spin_unlock(&registered_mechs_lock);
return gm;
}
struct gss_api_mech *
gss_mech_get_by_pseudoflavor(u32 pseudoflavor)
{
struct gss_api_mech *gm;
gm = _gss_mech_get_by_pseudoflavor(pseudoflavor);
if (!gm) {
request_module("rpc-auth-gss-%u", pseudoflavor);
gm = _gss_mech_get_by_pseudoflavor(pseudoflavor);
}
return gm;
}
int gss_mech_list_pseudoflavors(rpc_authflavor_t *array_ptr, int size)
{
struct gss_api_mech *pos = NULL;
int j, i = 0;
spin_lock(&registered_mechs_lock);
list_for_each_entry(pos, &registered_mechs, gm_list) {
for (j = 0; j < pos->gm_pf_num; j++) {
if (i >= size) {
spin_unlock(&registered_mechs_lock);
return -ENOMEM;
}
array_ptr[i++] = pos->gm_pfs[j].pseudoflavor;
}
}
spin_unlock(&registered_mechs_lock);
return i;
}
rpc_authflavor_t gss_svc_to_pseudoflavor(struct gss_api_mech *gm, u32 qop,
u32 service)
{
int i;
for (i = 0; i < gm->gm_pf_num; i++) {
if (gm->gm_pfs[i].qop == qop &&
gm->gm_pfs[i].service == service) {
return gm->gm_pfs[i].pseudoflavor;
}
}
return RPC_AUTH_MAXFLAVOR;
}
rpc_authflavor_t gss_mech_info2flavor(struct rpcsec_gss_info *info)
{
rpc_authflavor_t pseudoflavor;
struct gss_api_mech *gm;
gm = gss_mech_get_by_OID(&info->oid);
if (gm == NULL)
return RPC_AUTH_MAXFLAVOR;
pseudoflavor = gss_svc_to_pseudoflavor(gm, info->qop, info->service);
gss_mech_put(gm);
return pseudoflavor;
}
int gss_mech_flavor2info(rpc_authflavor_t pseudoflavor,
struct rpcsec_gss_info *info)
{
struct gss_api_mech *gm;
int i;
gm = gss_mech_get_by_pseudoflavor(pseudoflavor);
if (gm == NULL)
return -ENOENT;
for (i = 0; i < gm->gm_pf_num; i++) {
if (gm->gm_pfs[i].pseudoflavor == pseudoflavor) {
memcpy(info->oid.data, gm->gm_oid.data, gm->gm_oid.len);
info->oid.len = gm->gm_oid.len;
info->qop = gm->gm_pfs[i].qop;
info->service = gm->gm_pfs[i].service;
gss_mech_put(gm);
return 0;
}
}
gss_mech_put(gm);
return -ENOENT;
}
u32
gss_pseudoflavor_to_service(struct gss_api_mech *gm, u32 pseudoflavor)
{
int i;
for (i = 0; i < gm->gm_pf_num; i++) {
if (gm->gm_pfs[i].pseudoflavor == pseudoflavor)
return gm->gm_pfs[i].service;
}
return 0;
}
char *
gss_service_to_auth_domain_name(struct gss_api_mech *gm, u32 service)
{
int i;
for (i = 0; i < gm->gm_pf_num; i++) {
if (gm->gm_pfs[i].service == service)
return gm->gm_pfs[i].auth_domain_name;
}
return NULL;
}
void
gss_mech_put(struct gss_api_mech * gm)
{
if (gm)
module_put(gm->gm_owner);
}
int
gss_import_sec_context(const void *input_token, size_t bufsize,
struct gss_api_mech *mech,
struct gss_ctx **ctx_id,
time_t *endtime,
gfp_t gfp_mask)
{
if (!(*ctx_id = kzalloc(sizeof(**ctx_id), gfp_mask)))
return -ENOMEM;
(*ctx_id)->mech_type = gss_mech_get(mech);
return mech->gm_ops->gss_import_sec_context(input_token, bufsize,
*ctx_id, endtime, gfp_mask);
}
u32
gss_get_mic(struct gss_ctx *context_handle,
struct xdr_buf *message,
struct xdr_netobj *mic_token)
{
return context_handle->mech_type->gm_ops
->gss_get_mic(context_handle,
message,
mic_token);
}
u32
gss_verify_mic(struct gss_ctx *context_handle,
struct xdr_buf *message,
struct xdr_netobj *mic_token)
{
return context_handle->mech_type->gm_ops
->gss_verify_mic(context_handle,
message,
mic_token);
}
u32
gss_wrap(struct gss_ctx *ctx_id,
int offset,
struct xdr_buf *buf,
struct page **inpages)
{
return ctx_id->mech_type->gm_ops
->gss_wrap(ctx_id, offset, buf, inpages);
}
u32
gss_unwrap(struct gss_ctx *ctx_id,
int offset,
struct xdr_buf *buf)
{
return ctx_id->mech_type->gm_ops
->gss_unwrap(ctx_id, offset, buf);
}
u32
gss_delete_sec_context(struct gss_ctx **context_handle)
{
dprintk("RPC: gss_delete_sec_context deleting %p\n",
*context_handle);
if (!*context_handle)
return GSS_S_NO_CONTEXT;
if ((*context_handle)->internal_ctx_id)
(*context_handle)->mech_type->gm_ops
->gss_delete_sec_context((*context_handle)
->internal_ctx_id);
gss_mech_put((*context_handle)->mech_type);
kfree(*context_handle);
*context_handle=NULL;
return GSS_S_COMPLETE;
}
