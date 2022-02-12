static void lovsub_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
}
int lovsub_page_init(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, struct page *unused)
{
struct lovsub_page *lsb = cl_object_page_slice(obj, page);
cl_page_slice_add(page, &lsb->lsb_cl, obj, &lovsub_page_ops);
return 0;
}
