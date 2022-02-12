int
LNetMEAttach(unsigned int portal,
lnet_process_id_t match_id,
__u64 match_bits, __u64 ignore_bits,
lnet_unlink_t unlink, lnet_ins_pos_t pos,
lnet_handle_me_t *handle)
{
struct lnet_match_table *mtable;
struct lnet_me *me;
struct list_head *head;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
if ((int)portal >= the_lnet.ln_nportals)
return -EINVAL;
mtable = lnet_mt_of_attach(portal, match_id,
match_bits, ignore_bits, pos);
if (mtable == NULL)
return -EPERM;
me = lnet_me_alloc();
if (me == NULL)
return -ENOMEM;
lnet_res_lock(mtable->mt_cpt);
me->me_portal = portal;
me->me_match_id = match_id;
me->me_match_bits = match_bits;
me->me_ignore_bits = ignore_bits;
me->me_unlink = unlink;
me->me_md = NULL;
lnet_res_lh_initialize(the_lnet.ln_me_containers[mtable->mt_cpt],
&me->me_lh);
if (ignore_bits != 0)
head = &mtable->mt_mhash[LNET_MT_HASH_IGNORE];
else
head = lnet_mt_match_head(mtable, match_id, match_bits);
me->me_pos = head - &mtable->mt_mhash[0];
if (pos == LNET_INS_AFTER || pos == LNET_INS_LOCAL)
list_add_tail(&me->me_list, head);
else
list_add(&me->me_list, head);
lnet_me2handle(handle, me);
lnet_res_unlock(mtable->mt_cpt);
return 0;
}
int
LNetMEInsert(lnet_handle_me_t current_meh,
lnet_process_id_t match_id,
__u64 match_bits, __u64 ignore_bits,
lnet_unlink_t unlink, lnet_ins_pos_t pos,
lnet_handle_me_t *handle)
{
struct lnet_me *current_me;
struct lnet_me *new_me;
struct lnet_portal *ptl;
int cpt;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
if (pos == LNET_INS_LOCAL)
return -EPERM;
new_me = lnet_me_alloc();
if (new_me == NULL)
return -ENOMEM;
cpt = lnet_cpt_of_cookie(current_meh.cookie);
lnet_res_lock(cpt);
current_me = lnet_handle2me(&current_meh);
if (current_me == NULL) {
lnet_me_free_locked(new_me);
lnet_res_unlock(cpt);
return -ENOENT;
}
LASSERT(current_me->me_portal < the_lnet.ln_nportals);
ptl = the_lnet.ln_portals[current_me->me_portal];
if (lnet_ptl_is_unique(ptl)) {
lnet_me_free_locked(new_me);
lnet_res_unlock(cpt);
return -EPERM;
}
new_me->me_pos = current_me->me_pos;
new_me->me_portal = current_me->me_portal;
new_me->me_match_id = match_id;
new_me->me_match_bits = match_bits;
new_me->me_ignore_bits = ignore_bits;
new_me->me_unlink = unlink;
new_me->me_md = NULL;
lnet_res_lh_initialize(the_lnet.ln_me_containers[cpt], &new_me->me_lh);
if (pos == LNET_INS_AFTER)
list_add(&new_me->me_list, &current_me->me_list);
else
list_add_tail(&new_me->me_list, &current_me->me_list);
lnet_me2handle(handle, new_me);
lnet_res_unlock(cpt);
return 0;
}
int
LNetMEUnlink(lnet_handle_me_t meh)
{
lnet_me_t *me;
lnet_libmd_t *md;
lnet_event_t ev;
int cpt;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
cpt = lnet_cpt_of_cookie(meh.cookie);
lnet_res_lock(cpt);
me = lnet_handle2me(&meh);
if (me == NULL) {
lnet_res_unlock(cpt);
return -ENOENT;
}
md = me->me_md;
if (md != NULL) {
md->md_flags |= LNET_MD_FLAG_ABORTED;
if (md->md_eq != NULL && md->md_refcount == 0) {
lnet_build_unlink_event(md, &ev);
lnet_eq_enqueue_event(md->md_eq, &ev);
}
}
lnet_me_unlink(me);
lnet_res_unlock(cpt);
return 0;
}
void
lnet_me_unlink(lnet_me_t *me)
{
list_del(&me->me_list);
if (me->me_md != NULL) {
lnet_libmd_t *md = me->me_md;
lnet_ptl_detach_md(me, md);
lnet_md_unlink(md);
}
lnet_res_lh_invalidate(&me->me_lh);
lnet_me_free_locked(me);
}
