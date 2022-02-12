static int lov_page_invariant(const struct cl_page_slice *slice)
{
const struct cl_page *page = slice->cpl_page;
const struct cl_page *sub = lov_sub_page(slice);
return ergo(sub,
page->cp_child == sub &&
sub->cp_parent == page &&
page->cp_state == sub->cp_state);
}
static void lov_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
struct cl_page *sub = lov_sub_page(slice);
LINVRNT(lov_page_invariant(slice));
if (sub) {
LASSERT(sub->cp_state == CPS_FREEING);
lu_ref_del(&sub->cp_reference, "lov", sub->cp_parent);
sub->cp_parent = NULL;
slice->cpl_page->cp_child = NULL;
cl_page_put(env, sub);
}
}
static int lov_page_own(const struct lu_env *env,
const struct cl_page_slice *slice, struct cl_io *io,
int nonblock)
{
struct lov_io *lio = lov_env_io(env);
struct lov_io_sub *sub;
LINVRNT(lov_page_invariant(slice));
LINVRNT(!cl2lov_page(slice)->lps_invalid);
sub = lov_page_subio(env, lio, slice);
if (!IS_ERR(sub)) {
lov_sub_page(slice)->cp_owner = sub->sub_io;
lov_sub_put(sub);
} else
LBUG();
return 0;
}
static void lov_page_assume(const struct lu_env *env,
const struct cl_page_slice *slice, struct cl_io *io)
{
lov_page_own(env, slice, io, 0);
}
static int lov_page_cache_add(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *io)
{
struct lov_io *lio = lov_env_io(env);
struct lov_io_sub *sub;
int rc = 0;
LINVRNT(lov_page_invariant(slice));
LINVRNT(!cl2lov_page(slice)->lps_invalid);
sub = lov_page_subio(env, lio, slice);
if (!IS_ERR(sub)) {
rc = cl_page_cache_add(sub->sub_env, sub->sub_io,
slice->cpl_page->cp_child, CRT_WRITE);
lov_sub_put(sub);
} else {
rc = PTR_ERR(sub);
CL_PAGE_DEBUG(D_ERROR, env, slice->cpl_page, "rc = %d\n", rc);
}
return rc;
}
static int lov_page_print(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t printer)
{
struct lov_page *lp = cl2lov_page(slice);
return (*printer)(env, cookie, LUSTRE_LOV_NAME"-page@%p\n", lp);
}
static void lov_empty_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
LASSERT(!slice->cpl_page->cp_child);
}
int lov_page_init_raid0(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, struct page *vmpage)
{
struct lov_object *loo = cl2lov(obj);
struct lov_layout_raid0 *r0 = lov_r0(loo);
struct lov_io *lio = lov_env_io(env);
struct cl_page *subpage;
struct cl_object *subobj;
struct lov_io_sub *sub;
struct lov_page *lpg = cl_object_page_slice(obj, page);
loff_t offset;
u64 suboff;
int stripe;
int rc;
offset = cl_offset(obj, page->cp_index);
stripe = lov_stripe_number(loo->lo_lsm, offset);
LASSERT(stripe < r0->lo_nr);
rc = lov_stripe_offset(loo->lo_lsm, offset, stripe, &suboff);
LASSERT(rc == 0);
lpg->lps_invalid = 1;
cl_page_slice_add(page, &lpg->lps_cl, obj, &lov_page_ops);
sub = lov_sub_get(env, lio, stripe);
if (IS_ERR(sub)) {
rc = PTR_ERR(sub);
goto out;
}
subobj = lovsub2cl(r0->lo_sub[stripe]);
subpage = cl_page_find_sub(sub->sub_env, subobj,
cl_index(subobj, suboff), vmpage, page);
lov_sub_put(sub);
if (IS_ERR(subpage)) {
rc = PTR_ERR(subpage);
goto out;
}
if (likely(subpage->cp_parent == page)) {
lu_ref_add(&subpage->cp_reference, "lov", page);
lpg->lps_invalid = 0;
rc = 0;
} else {
CL_PAGE_DEBUG(D_ERROR, env, page, "parent page\n");
CL_PAGE_DEBUG(D_ERROR, env, subpage, "child page\n");
LASSERT(0);
}
out:
return rc;
}
int lov_page_init_empty(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, struct page *vmpage)
{
struct lov_page *lpg = cl_object_page_slice(obj, page);
void *addr;
cl_page_slice_add(page, &lpg->lps_cl, obj, &lov_empty_page_ops);
addr = kmap(vmpage);
memset(addr, 0, cl_page_size(obj));
kunmap(vmpage);
cl_page_export(env, page, 1);
return 0;
}
