void
lnet_md_unlink(lnet_libmd_t *md)
{
if ((md->md_flags & LNET_MD_FLAG_ZOMBIE) == 0) {
lnet_me_t *me = md->md_me;
md->md_flags |= LNET_MD_FLAG_ZOMBIE;
if (me != NULL) {
lnet_ptl_detach_md(me, md);
if (me->me_unlink == LNET_UNLINK)
lnet_me_unlink(me);
}
lnet_res_lh_invalidate(&md->md_lh);
}
if (md->md_refcount != 0) {
CDEBUG(D_NET, "Queueing unlink of md %p\n", md);
return;
}
CDEBUG(D_NET, "Unlinking md %p\n", md);
if (md->md_eq != NULL) {
int cpt = lnet_cpt_of_cookie(md->md_lh.lh_cookie);
LASSERT(*md->md_eq->eq_refs[cpt] > 0);
(*md->md_eq->eq_refs[cpt])--;
}
LASSERT(!list_empty(&md->md_list));
list_del_init(&md->md_list);
lnet_md_free_locked(md);
}
static int
lnet_md_build(lnet_libmd_t *lmd, lnet_md_t *umd, int unlink)
{
int i;
unsigned int niov;
int total_length = 0;
lmd->md_me = NULL;
lmd->md_start = umd->start;
lmd->md_offset = 0;
lmd->md_max_size = umd->max_size;
lmd->md_options = umd->options;
lmd->md_user_ptr = umd->user_ptr;
lmd->md_eq = NULL;
lmd->md_threshold = umd->threshold;
lmd->md_refcount = 0;
lmd->md_flags = (unlink == LNET_UNLINK) ? LNET_MD_FLAG_AUTO_UNLINK : 0;
if ((umd->options & LNET_MD_IOVEC) != 0) {
if ((umd->options & LNET_MD_KIOV) != 0)
return -EINVAL;
lmd->md_niov = niov = umd->length;
memcpy(lmd->md_iov.iov, umd->start,
niov * sizeof (lmd->md_iov.iov[0]));
for (i = 0; i < (int)niov; i++) {
if (lmd->md_iov.iov[i].iov_len <= 0)
return -EINVAL;
total_length += lmd->md_iov.iov[i].iov_len;
}
lmd->md_length = total_length;
if ((umd->options & LNET_MD_MAX_SIZE) != 0 &&
(umd->max_size < 0 ||
umd->max_size > total_length))
return -EINVAL;
} else if ((umd->options & LNET_MD_KIOV) != 0) {
lmd->md_niov = niov = umd->length;
memcpy(lmd->md_iov.kiov, umd->start,
niov * sizeof (lmd->md_iov.kiov[0]));
for (i = 0; i < (int)niov; i++) {
if (lmd->md_iov.kiov[i].kiov_offset +
lmd->md_iov.kiov[i].kiov_len > PAGE_CACHE_SIZE )
return -EINVAL;
total_length += lmd->md_iov.kiov[i].kiov_len;
}
lmd->md_length = total_length;
if ((umd->options & LNET_MD_MAX_SIZE) != 0 &&
(umd->max_size < 0 ||
umd->max_size > total_length))
return -EINVAL;
} else {
lmd->md_length = umd->length;
lmd->md_niov = niov = 1;
lmd->md_iov.iov[0].iov_base = umd->start;
lmd->md_iov.iov[0].iov_len = umd->length;
if ((umd->options & LNET_MD_MAX_SIZE) != 0 &&
(umd->max_size < 0 ||
umd->max_size > (int)umd->length))
return -EINVAL;
}
return 0;
}
static int
lnet_md_link(lnet_libmd_t *md, lnet_handle_eq_t eq_handle, int cpt)
{
struct lnet_res_container *container = the_lnet.ln_md_containers[cpt];
if (!LNetHandleIsInvalid(eq_handle)) {
md->md_eq = lnet_handle2eq(&eq_handle);
if (md->md_eq == NULL)
return -ENOENT;
(*md->md_eq->eq_refs[cpt])++;
}
lnet_res_lh_initialize(container, &md->md_lh);
LASSERT(list_empty(&md->md_list));
list_add(&md->md_list, &container->rec_active);
return 0;
}
void
lnet_md_deconstruct(lnet_libmd_t *lmd, lnet_md_t *umd)
{
umd->start = lmd->md_start;
umd->length = ((lmd->md_options & (LNET_MD_IOVEC | LNET_MD_KIOV)) == 0) ?
lmd->md_length : lmd->md_niov;
umd->threshold = lmd->md_threshold;
umd->max_size = lmd->md_max_size;
umd->options = lmd->md_options;
umd->user_ptr = lmd->md_user_ptr;
lnet_eq2handle(&umd->eq_handle, lmd->md_eq);
}
int
lnet_md_validate(lnet_md_t *umd)
{
if (umd->start == NULL && umd->length != 0) {
CERROR("MD start pointer can not be NULL with length %u\n",
umd->length);
return -EINVAL;
}
if ((umd->options & (LNET_MD_KIOV | LNET_MD_IOVEC)) != 0 &&
umd->length > LNET_MAX_IOV) {
CERROR("Invalid option: too many fragments %u, %d max\n",
umd->length, LNET_MAX_IOV);
return -EINVAL;
}
return 0;
}
int
LNetMDAttach(lnet_handle_me_t meh, lnet_md_t umd,
lnet_unlink_t unlink, lnet_handle_md_t *handle)
{
LIST_HEAD (matches);
LIST_HEAD (drops);
struct lnet_me *me;
struct lnet_libmd *md;
int cpt;
int rc;
LASSERT (the_lnet.ln_init);
LASSERT (the_lnet.ln_refcount > 0);
if (lnet_md_validate(&umd) != 0)
return -EINVAL;
if ((umd.options & (LNET_MD_OP_GET | LNET_MD_OP_PUT)) == 0) {
CERROR("Invalid option: no MD_OP set\n");
return -EINVAL;
}
md = lnet_md_alloc(&umd);
if (md == NULL)
return -ENOMEM;
rc = lnet_md_build(md, &umd, unlink);
cpt = lnet_cpt_of_cookie(meh.cookie);
lnet_res_lock(cpt);
if (rc != 0)
goto failed;
me = lnet_handle2me(&meh);
if (me == NULL)
rc = -ENOENT;
else if (me->me_md != NULL)
rc = -EBUSY;
else
rc = lnet_md_link(md, umd.eq_handle, cpt);
if (rc != 0)
goto failed;
lnet_ptl_attach_md(me, md, &matches, &drops);
lnet_md2handle(handle, md);
lnet_res_unlock(cpt);
lnet_drop_delayed_msg_list(&drops, "Bad match");
lnet_recv_delayed_msg_list(&matches);
return 0;
failed:
lnet_md_free_locked(md);
lnet_res_unlock(cpt);
return rc;
}
int
LNetMDBind(lnet_md_t umd, lnet_unlink_t unlink, lnet_handle_md_t *handle)
{
lnet_libmd_t *md;
int cpt;
int rc;
LASSERT (the_lnet.ln_init);
LASSERT (the_lnet.ln_refcount > 0);
if (lnet_md_validate(&umd) != 0)
return -EINVAL;
if ((umd.options & (LNET_MD_OP_GET | LNET_MD_OP_PUT)) != 0) {
CERROR("Invalid option: GET|PUT illegal on active MDs\n");
return -EINVAL;
}
md = lnet_md_alloc(&umd);
if (md == NULL)
return -ENOMEM;
rc = lnet_md_build(md, &umd, unlink);
cpt = lnet_res_lock_current();
if (rc != 0)
goto failed;
rc = lnet_md_link(md, umd.eq_handle, cpt);
if (rc != 0)
goto failed;
lnet_md2handle(handle, md);
lnet_res_unlock(cpt);
return 0;
failed:
lnet_md_free_locked(md);
lnet_res_unlock(cpt);
return rc;
}
int
LNetMDUnlink (lnet_handle_md_t mdh)
{
lnet_event_t ev;
lnet_libmd_t *md;
int cpt;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
cpt = lnet_cpt_of_cookie(mdh.cookie);
lnet_res_lock(cpt);
md = lnet_handle2md(&mdh);
if (md == NULL) {
lnet_res_unlock(cpt);
return -ENOENT;
}
if (md->md_eq != NULL &&
md->md_refcount == 0) {
lnet_build_unlink_event(md, &ev);
lnet_eq_enqueue_event(md->md_eq, &ev);
}
lnet_md_unlink(md);
lnet_res_unlock(cpt);
return 0;
}
