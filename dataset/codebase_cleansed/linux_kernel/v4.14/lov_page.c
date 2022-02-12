static int lov_raid0_page_print(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t printer)
{
struct lov_page *lp = cl2lov_page(slice);
return (*printer)(env, cookie, LUSTRE_LOV_NAME "-page@%p, raid0\n", lp);
}
int lov_page_init_raid0(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, pgoff_t index)
{
struct lov_object *loo = cl2lov(obj);
struct lov_layout_raid0 *r0 = lov_r0(loo);
struct lov_io *lio = lov_env_io(env);
struct cl_object *subobj;
struct cl_object *o;
struct lov_io_sub *sub;
struct lov_page *lpg = cl_object_page_slice(obj, page);
loff_t offset;
u64 suboff;
int stripe;
int rc;
offset = cl_offset(obj, index);
stripe = lov_stripe_number(loo->lo_lsm, offset);
LASSERT(stripe < r0->lo_nr);
rc = lov_stripe_offset(loo->lo_lsm, offset, stripe, &suboff);
LASSERT(rc == 0);
lpg->lps_stripe = stripe;
cl_page_slice_add(page, &lpg->lps_cl, obj, index, &lov_raid0_page_ops);
sub = lov_sub_get(env, lio, stripe);
if (IS_ERR(sub))
return PTR_ERR(sub);
subobj = lovsub2cl(r0->lo_sub[stripe]);
list_for_each_entry(o, &subobj->co_lu.lo_header->loh_layers,
co_lu.lo_linkage) {
if (o->co_ops->coo_page_init) {
rc = o->co_ops->coo_page_init(sub->sub_env, o, page,
cl_index(subobj, suboff));
if (rc != 0)
break;
}
}
return rc;
}
static int lov_empty_page_print(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t printer)
{
struct lov_page *lp = cl2lov_page(slice);
return (*printer)(env, cookie, LUSTRE_LOV_NAME "-page@%p, empty.\n",
lp);
}
int lov_page_init_empty(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, pgoff_t index)
{
struct lov_page *lpg = cl_object_page_slice(obj, page);
void *addr;
cl_page_slice_add(page, &lpg->lps_cl, obj, index, &lov_empty_page_ops);
addr = kmap(page->cp_vmpage);
memset(addr, 0, cl_page_size(obj));
kunmap(page->cp_vmpage);
cl_page_export(env, page, 1);
return 0;
}
