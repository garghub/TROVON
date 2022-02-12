static int
lnet_ptl_match_type(unsigned int index, lnet_process_id_t match_id,
__u64 mbits, __u64 ignore_bits)
{
struct lnet_portal *ptl = the_lnet.ln_portals[index];
int unique;
unique = ignore_bits == 0 &&
match_id.nid != LNET_NID_ANY &&
match_id.pid != LNET_PID_ANY;
LASSERT(!lnet_ptl_is_unique(ptl) || !lnet_ptl_is_wildcard(ptl));
if (likely(lnet_ptl_is_unique(ptl) || lnet_ptl_is_wildcard(ptl)))
goto match;
lnet_ptl_lock(ptl);
if (unlikely(lnet_ptl_is_unique(ptl) || lnet_ptl_is_wildcard(ptl))) {
lnet_ptl_unlock(ptl);
goto match;
}
if (unique)
lnet_ptl_setopt(ptl, LNET_PTL_MATCH_UNIQUE);
else
lnet_ptl_setopt(ptl, LNET_PTL_MATCH_WILDCARD);
lnet_ptl_unlock(ptl);
return 1;
match:
if ((lnet_ptl_is_unique(ptl) && !unique) ||
(lnet_ptl_is_wildcard(ptl) && unique))
return 0;
return 1;
}
static void
lnet_ptl_enable_mt(struct lnet_portal *ptl, int cpt)
{
struct lnet_match_table *mtable = ptl->ptl_mtables[cpt];
int i;
LASSERT(lnet_ptl_is_wildcard(ptl));
mtable->mt_enabled = 1;
ptl->ptl_mt_maps[ptl->ptl_mt_nmaps] = cpt;
for (i = ptl->ptl_mt_nmaps - 1; i >= 0; i--) {
LASSERT(ptl->ptl_mt_maps[i] != cpt);
if (ptl->ptl_mt_maps[i] < cpt)
break;
ptl->ptl_mt_maps[i + 1] = ptl->ptl_mt_maps[i];
ptl->ptl_mt_maps[i] = cpt;
}
ptl->ptl_mt_nmaps++;
}
static void
lnet_ptl_disable_mt(struct lnet_portal *ptl, int cpt)
{
struct lnet_match_table *mtable = ptl->ptl_mtables[cpt];
int i;
LASSERT(lnet_ptl_is_wildcard(ptl));
if (LNET_CPT_NUMBER == 1)
return;
mtable->mt_enabled = 0;
LASSERT(ptl->ptl_mt_nmaps > 0 &&
ptl->ptl_mt_nmaps <= LNET_CPT_NUMBER);
ptl->ptl_mt_nmaps--;
for (i = 0; i < ptl->ptl_mt_nmaps; i++) {
if (ptl->ptl_mt_maps[i] >= cpt)
ptl->ptl_mt_maps[i] = ptl->ptl_mt_maps[i + 1];
}
}
static int
lnet_try_match_md(lnet_libmd_t *md,
struct lnet_match_info *info, struct lnet_msg *msg)
{
unsigned int offset;
unsigned int mlength;
lnet_me_t *me = md->md_me;
if (lnet_md_exhausted(md))
return LNET_MATCHMD_NONE | LNET_MATCHMD_EXHAUSTED;
if ((md->md_options & info->mi_opc) == 0)
return LNET_MATCHMD_NONE;
if (me->me_match_id.nid != LNET_NID_ANY &&
me->me_match_id.nid != info->mi_id.nid)
return LNET_MATCHMD_NONE;
if (me->me_match_id.pid != LNET_PID_ANY &&
me->me_match_id.pid != info->mi_id.pid)
return LNET_MATCHMD_NONE;
if (((me->me_match_bits ^ info->mi_mbits) & ~me->me_ignore_bits) != 0)
return LNET_MATCHMD_NONE;
if ((md->md_options & LNET_MD_MANAGE_REMOTE) == 0)
offset = md->md_offset;
else
offset = info->mi_roffset;
if ((md->md_options & LNET_MD_MAX_SIZE) != 0) {
mlength = md->md_max_size;
LASSERT(md->md_offset + mlength <= md->md_length);
} else {
mlength = md->md_length - offset;
}
if (info->mi_rlength <= mlength) {
mlength = info->mi_rlength;
} else if ((md->md_options & LNET_MD_TRUNCATE) == 0) {
CERROR("Matching packet from %s, match %llu length %d too big: %d left, %d allowed\n",
libcfs_id2str(info->mi_id), info->mi_mbits,
info->mi_rlength, md->md_length - offset, mlength);
return LNET_MATCHMD_DROP;
}
CDEBUG(D_NET, "Incoming %s index %x from %s of "
"length %d/%d into md %#llx [%d] + %d\n",
(info->mi_opc == LNET_MD_OP_PUT) ? "put" : "get",
info->mi_portal, libcfs_id2str(info->mi_id), mlength,
info->mi_rlength, md->md_lh.lh_cookie, md->md_niov, offset);
lnet_msg_attach_md(msg, md, offset, mlength);
md->md_offset = offset + mlength;
if (!lnet_md_exhausted(md))
return LNET_MATCHMD_OK;
if ((md->md_flags & LNET_MD_FLAG_AUTO_UNLINK) != 0)
lnet_md_unlink(md);
return LNET_MATCHMD_OK | LNET_MATCHMD_EXHAUSTED;
}
static struct lnet_match_table *
lnet_match2mt(struct lnet_portal *ptl, lnet_process_id_t id, __u64 mbits)
{
if (LNET_CPT_NUMBER == 1)
return ptl->ptl_mtables[0];
return lnet_ptl_is_unique(ptl) ?
ptl->ptl_mtables[lnet_cpt_of_nid(id.nid)] : NULL;
}
struct lnet_match_table *
lnet_mt_of_attach(unsigned int index, lnet_process_id_t id,
__u64 mbits, __u64 ignore_bits, lnet_ins_pos_t pos)
{
struct lnet_portal *ptl;
struct lnet_match_table *mtable;
LASSERT(index < the_lnet.ln_nportals);
if (!lnet_ptl_match_type(index, id, mbits, ignore_bits))
return NULL;
ptl = the_lnet.ln_portals[index];
mtable = lnet_match2mt(ptl, id, mbits);
if (mtable != NULL)
return mtable;
switch (pos) {
default:
return NULL;
case LNET_INS_BEFORE:
case LNET_INS_AFTER:
return ptl->ptl_mtables[ptl->ptl_index % LNET_CPT_NUMBER];
case LNET_INS_LOCAL:
return ptl->ptl_mtables[lnet_cpt_current()];
}
}
static struct lnet_match_table *
lnet_mt_of_match(struct lnet_match_info *info, struct lnet_msg *msg)
{
struct lnet_match_table *mtable;
struct lnet_portal *ptl;
int nmaps;
int rotor;
int routed;
int cpt;
LASSERT(info->mi_portal < the_lnet.ln_nportals);
ptl = the_lnet.ln_portals[info->mi_portal];
LASSERT(lnet_ptl_is_wildcard(ptl) || lnet_ptl_is_unique(ptl));
mtable = lnet_match2mt(ptl, info->mi_id, info->mi_mbits);
if (mtable != NULL)
return mtable;
routed = LNET_NIDNET(msg->msg_hdr.src_nid) !=
LNET_NIDNET(msg->msg_hdr.dest_nid);
if (portal_rotor == LNET_PTL_ROTOR_OFF ||
(portal_rotor != LNET_PTL_ROTOR_ON && !routed)) {
cpt = lnet_cpt_current();
if (ptl->ptl_mtables[cpt]->mt_enabled)
return ptl->ptl_mtables[cpt];
}
rotor = ptl->ptl_rotor++;
if (portal_rotor == LNET_PTL_ROTOR_HASH_RT && routed)
cpt = lnet_cpt_of_nid(msg->msg_hdr.src_nid);
else
cpt = rotor % LNET_CPT_NUMBER;
if (!ptl->ptl_mtables[cpt]->mt_enabled) {
nmaps = ptl->ptl_mt_nmaps;
if (nmaps != 0) {
cpt = ptl->ptl_mt_maps[rotor % nmaps];
}
}
return ptl->ptl_mtables[cpt];
}
static int
lnet_mt_test_exhausted(struct lnet_match_table *mtable, int pos)
{
__u64 *bmap;
int i;
if (!lnet_ptl_is_wildcard(the_lnet.ln_portals[mtable->mt_portal]))
return 0;
if (pos < 0) {
for (i = 0; i < LNET_MT_EXHAUSTED_BMAP; i++) {
if (mtable->mt_exhausted[i] != (__u64)(-1))
return 0;
}
return 1;
}
LASSERT(pos <= LNET_MT_HASH_IGNORE);
bmap = &mtable->mt_exhausted[pos >> LNET_MT_BITS_U64];
pos &= (1 << LNET_MT_BITS_U64) - 1;
return ((*bmap) & (1ULL << pos)) != 0;
}
static void
lnet_mt_set_exhausted(struct lnet_match_table *mtable, int pos, int exhausted)
{
__u64 *bmap;
LASSERT(lnet_ptl_is_wildcard(the_lnet.ln_portals[mtable->mt_portal]));
LASSERT(pos <= LNET_MT_HASH_IGNORE);
bmap = &mtable->mt_exhausted[pos >> LNET_MT_BITS_U64];
pos &= (1 << LNET_MT_BITS_U64) - 1;
if (!exhausted)
*bmap &= ~(1ULL << pos);
else
*bmap |= 1ULL << pos;
}
struct list_head *
lnet_mt_match_head(struct lnet_match_table *mtable,
lnet_process_id_t id, __u64 mbits)
{
struct lnet_portal *ptl = the_lnet.ln_portals[mtable->mt_portal];
if (lnet_ptl_is_wildcard(ptl)) {
return &mtable->mt_mhash[mbits & LNET_MT_HASH_MASK];
} else {
unsigned long hash = mbits + id.nid + id.pid;
LASSERT(lnet_ptl_is_unique(ptl));
hash = hash_long(hash, LNET_MT_HASH_BITS);
return &mtable->mt_mhash[hash];
}
}
int
lnet_mt_match_md(struct lnet_match_table *mtable,
struct lnet_match_info *info, struct lnet_msg *msg)
{
struct list_head *head;
lnet_me_t *me;
lnet_me_t *tmp;
int exhausted = 0;
int rc;
if (!list_empty(&mtable->mt_mhash[LNET_MT_HASH_IGNORE]))
head = &mtable->mt_mhash[LNET_MT_HASH_IGNORE];
else
head = lnet_mt_match_head(mtable, info->mi_id, info->mi_mbits);
again:
if (lnet_ptl_is_wildcard(the_lnet.ln_portals[mtable->mt_portal]))
exhausted = LNET_MATCHMD_EXHAUSTED;
list_for_each_entry_safe(me, tmp, head, me_list) {
if (me->me_md == NULL)
continue;
LASSERT(me == me->me_md->md_me);
rc = lnet_try_match_md(me->me_md, info, msg);
if ((rc & LNET_MATCHMD_EXHAUSTED) == 0)
exhausted = 0;
if ((rc & LNET_MATCHMD_FINISH) != 0) {
return rc & ~LNET_MATCHMD_EXHAUSTED;
}
}
if (exhausted == LNET_MATCHMD_EXHAUSTED) {
lnet_mt_set_exhausted(mtable, head - mtable->mt_mhash, 1);
if (!lnet_mt_test_exhausted(mtable, -1))
exhausted = 0;
}
if (exhausted == 0 && head == &mtable->mt_mhash[LNET_MT_HASH_IGNORE]) {
head = lnet_mt_match_head(mtable, info->mi_id, info->mi_mbits);
goto again;
}
if (info->mi_opc == LNET_MD_OP_GET ||
!lnet_ptl_is_lazy(the_lnet.ln_portals[info->mi_portal]))
return LNET_MATCHMD_DROP | exhausted;
return LNET_MATCHMD_NONE | exhausted;
}
static int
lnet_ptl_match_early(struct lnet_portal *ptl, struct lnet_msg *msg)
{
int rc;
if (likely(lnet_ptl_is_wildcard(ptl) || lnet_ptl_is_unique(ptl)))
return 0;
lnet_ptl_lock(ptl);
if (lnet_ptl_is_wildcard(ptl) || lnet_ptl_is_unique(ptl)) {
lnet_ptl_unlock(ptl);
return 0;
}
if (lnet_ptl_is_lazy(ptl)) {
if (msg->msg_rx_ready_delay) {
msg->msg_rx_delayed = 1;
list_add_tail(&msg->msg_list,
&ptl->ptl_msg_delayed);
}
rc = LNET_MATCHMD_NONE;
} else {
rc = LNET_MATCHMD_DROP;
}
lnet_ptl_unlock(ptl);
return rc;
}
static int
lnet_ptl_match_delay(struct lnet_portal *ptl,
struct lnet_match_info *info, struct lnet_msg *msg)
{
int first = ptl->ptl_mt_maps[0];
int rc = 0;
int i;
LASSERT(lnet_ptl_is_wildcard(ptl));
for (i = 0; i < LNET_CPT_NUMBER; i++) {
struct lnet_match_table *mtable;
int cpt;
cpt = (first + i) % LNET_CPT_NUMBER;
mtable = ptl->ptl_mtables[cpt];
if (i != 0 && i != LNET_CPT_NUMBER - 1 && !mtable->mt_enabled)
continue;
lnet_res_lock(cpt);
lnet_ptl_lock(ptl);
if (i == 0) {
list_add_tail(&msg->msg_list,
&ptl->ptl_msg_stealing);
}
if (!list_empty(&msg->msg_list)) {
rc = lnet_mt_match_md(mtable, info, msg);
if ((rc & LNET_MATCHMD_EXHAUSTED) != 0 &&
mtable->mt_enabled)
lnet_ptl_disable_mt(ptl, cpt);
if ((rc & LNET_MATCHMD_FINISH) != 0)
list_del_init(&msg->msg_list);
} else {
rc = msg->msg_md == NULL ?
LNET_MATCHMD_DROP : LNET_MATCHMD_OK;
}
if (!list_empty(&msg->msg_list) &&
(i == LNET_CPT_NUMBER - 1 ||
ptl->ptl_mt_nmaps == 0 ||
(ptl->ptl_mt_nmaps == 1 &&
ptl->ptl_mt_maps[0] == cpt))) {
list_del_init(&msg->msg_list);
if (lnet_ptl_is_lazy(ptl)) {
msg->msg_rx_delayed = 1;
list_add_tail(&msg->msg_list,
&ptl->ptl_msg_delayed);
rc = LNET_MATCHMD_NONE;
} else {
rc = LNET_MATCHMD_DROP;
}
}
lnet_ptl_unlock(ptl);
lnet_res_unlock(cpt);
if ((rc & LNET_MATCHMD_FINISH) != 0 || msg->msg_rx_delayed)
break;
}
return rc;
}
int
lnet_ptl_match_md(struct lnet_match_info *info, struct lnet_msg *msg)
{
struct lnet_match_table *mtable;
struct lnet_portal *ptl;
int rc;
CDEBUG(D_NET, "Request from %s of length %d into portal %d MB=%#llx\n",
libcfs_id2str(info->mi_id), info->mi_rlength, info->mi_portal,
info->mi_mbits);
if (info->mi_portal >= the_lnet.ln_nportals) {
CERROR("Invalid portal %d not in [0-%d]\n",
info->mi_portal, the_lnet.ln_nportals);
return LNET_MATCHMD_DROP;
}
ptl = the_lnet.ln_portals[info->mi_portal];
rc = lnet_ptl_match_early(ptl, msg);
if (rc != 0)
return rc;
mtable = lnet_mt_of_match(info, msg);
lnet_res_lock(mtable->mt_cpt);
if (the_lnet.ln_shutdown) {
rc = LNET_MATCHMD_DROP;
goto out1;
}
rc = lnet_mt_match_md(mtable, info, msg);
if ((rc & LNET_MATCHMD_EXHAUSTED) != 0 && mtable->mt_enabled) {
lnet_ptl_lock(ptl);
lnet_ptl_disable_mt(ptl, mtable->mt_cpt);
lnet_ptl_unlock(ptl);
}
if ((rc & LNET_MATCHMD_FINISH) != 0)
goto out1;
if (!msg->msg_rx_ready_delay)
goto out1;
LASSERT(lnet_ptl_is_lazy(ptl));
LASSERT(!msg->msg_rx_delayed);
if (lnet_ptl_is_unique(ptl) || LNET_CPT_NUMBER == 1) {
lnet_ptl_lock(ptl);
msg->msg_rx_delayed = 1;
list_add_tail(&msg->msg_list, &ptl->ptl_msg_delayed);
lnet_ptl_unlock(ptl);
lnet_res_unlock(mtable->mt_cpt);
} else {
lnet_res_unlock(mtable->mt_cpt);
rc = lnet_ptl_match_delay(ptl, info, msg);
}
if (msg->msg_rx_delayed) {
CDEBUG(D_NET,
"Delaying %s from %s ptl %d MB %#llx off %d len %d\n",
info->mi_opc == LNET_MD_OP_PUT ? "PUT" : "GET",
libcfs_id2str(info->mi_id), info->mi_portal,
info->mi_mbits, info->mi_roffset, info->mi_rlength);
}
goto out0;
out1:
lnet_res_unlock(mtable->mt_cpt);
out0:
return rc & ~LNET_MATCHMD_EXHAUSTED;
}
void
lnet_ptl_detach_md(lnet_me_t *me, lnet_libmd_t *md)
{
LASSERT(me->me_md == md && md->md_me == me);
me->me_md = NULL;
md->md_me = NULL;
}
void
lnet_ptl_attach_md(lnet_me_t *me, lnet_libmd_t *md,
struct list_head *matches, struct list_head *drops)
{
struct lnet_portal *ptl = the_lnet.ln_portals[me->me_portal];
struct lnet_match_table *mtable;
struct list_head *head;
lnet_msg_t *tmp;
lnet_msg_t *msg;
int exhausted = 0;
int cpt;
LASSERT(md->md_refcount == 0);
me->me_md = md;
md->md_me = me;
cpt = lnet_cpt_of_cookie(md->md_lh.lh_cookie);
mtable = ptl->ptl_mtables[cpt];
if (list_empty(&ptl->ptl_msg_stealing) &&
list_empty(&ptl->ptl_msg_delayed) &&
!lnet_mt_test_exhausted(mtable, me->me_pos))
return;
lnet_ptl_lock(ptl);
head = &ptl->ptl_msg_stealing;
again:
list_for_each_entry_safe(msg, tmp, head, msg_list) {
struct lnet_match_info info;
lnet_hdr_t *hdr;
int rc;
LASSERT(msg->msg_rx_delayed || head == &ptl->ptl_msg_stealing);
hdr = &msg->msg_hdr;
info.mi_id.nid = hdr->src_nid;
info.mi_id.pid = hdr->src_pid;
info.mi_opc = LNET_MD_OP_PUT;
info.mi_portal = hdr->msg.put.ptl_index;
info.mi_rlength = hdr->payload_length;
info.mi_roffset = hdr->msg.put.offset;
info.mi_mbits = hdr->msg.put.match_bits;
rc = lnet_try_match_md(md, &info, msg);
exhausted = (rc & LNET_MATCHMD_EXHAUSTED) != 0;
if ((rc & LNET_MATCHMD_NONE) != 0) {
if (exhausted)
break;
continue;
}
LASSERT((rc & LNET_MATCHMD_FINISH) != 0);
list_del_init(&msg->msg_list);
if (head == &ptl->ptl_msg_stealing) {
if (exhausted)
break;
continue;
}
if ((rc & LNET_MATCHMD_OK) != 0) {
list_add_tail(&msg->msg_list, matches);
CDEBUG(D_NET, "Resuming delayed PUT from %s portal %d match %llu offset %d length %d.\n",
libcfs_id2str(info.mi_id),
info.mi_portal, info.mi_mbits,
info.mi_roffset, info.mi_rlength);
} else {
list_add_tail(&msg->msg_list, drops);
}
if (exhausted)
break;
}
if (!exhausted && head == &ptl->ptl_msg_stealing) {
head = &ptl->ptl_msg_delayed;
goto again;
}
if (lnet_ptl_is_wildcard(ptl) && !exhausted) {
lnet_mt_set_exhausted(mtable, me->me_pos, 0);
if (!mtable->mt_enabled)
lnet_ptl_enable_mt(ptl, cpt);
}
lnet_ptl_unlock(ptl);
}
static void
lnet_ptl_cleanup(struct lnet_portal *ptl)
{
struct lnet_match_table *mtable;
int i;
if (ptl->ptl_mtables == NULL)
return;
LASSERT(list_empty(&ptl->ptl_msg_delayed));
LASSERT(list_empty(&ptl->ptl_msg_stealing));
cfs_percpt_for_each(mtable, i, ptl->ptl_mtables) {
struct list_head *mhash;
lnet_me_t *me;
int j;
if (mtable->mt_mhash == NULL)
continue;
mhash = mtable->mt_mhash;
for (j = 0; j < LNET_MT_HASH_SIZE + 1; j++) {
while (!list_empty(&mhash[j])) {
me = list_entry(mhash[j].next,
lnet_me_t, me_list);
CERROR("Active ME %p on exit\n", me);
list_del(&me->me_list);
lnet_me_free(me);
}
}
LIBCFS_FREE(mhash, sizeof(*mhash) * (LNET_MT_HASH_SIZE + 1));
}
cfs_percpt_free(ptl->ptl_mtables);
ptl->ptl_mtables = NULL;
}
static int
lnet_ptl_setup(struct lnet_portal *ptl, int index)
{
struct lnet_match_table *mtable;
struct list_head *mhash;
int i;
int j;
ptl->ptl_mtables = cfs_percpt_alloc(lnet_cpt_table(),
sizeof(struct lnet_match_table));
if (ptl->ptl_mtables == NULL) {
CERROR("Failed to create match table for portal %d\n", index);
return -ENOMEM;
}
ptl->ptl_index = index;
INIT_LIST_HEAD(&ptl->ptl_msg_delayed);
INIT_LIST_HEAD(&ptl->ptl_msg_stealing);
spin_lock_init(&ptl->ptl_lock);
cfs_percpt_for_each(mtable, i, ptl->ptl_mtables) {
LIBCFS_CPT_ALLOC(mhash, lnet_cpt_table(), i,
sizeof(*mhash) * (LNET_MT_HASH_SIZE + 1));
if (mhash == NULL) {
CERROR("Failed to create match hash for portal %d\n",
index);
goto failed;
}
memset(&mtable->mt_exhausted[0], -1,
sizeof(mtable->mt_exhausted[0]) *
LNET_MT_EXHAUSTED_BMAP);
mtable->mt_mhash = mhash;
for (j = 0; j < LNET_MT_HASH_SIZE + 1; j++)
INIT_LIST_HEAD(&mhash[j]);
mtable->mt_portal = index;
mtable->mt_cpt = i;
}
return 0;
failed:
lnet_ptl_cleanup(ptl);
return -ENOMEM;
}
void
lnet_portals_destroy(void)
{
int i;
if (the_lnet.ln_portals == NULL)
return;
for (i = 0; i < the_lnet.ln_nportals; i++)
lnet_ptl_cleanup(the_lnet.ln_portals[i]);
cfs_array_free(the_lnet.ln_portals);
the_lnet.ln_portals = NULL;
}
int
lnet_portals_create(void)
{
int size;
int i;
size = offsetof(struct lnet_portal, ptl_mt_maps[LNET_CPT_NUMBER]);
the_lnet.ln_nportals = MAX_PORTALS;
the_lnet.ln_portals = cfs_array_alloc(the_lnet.ln_nportals, size);
if (the_lnet.ln_portals == NULL) {
CERROR("Failed to allocate portals table\n");
return -ENOMEM;
}
for (i = 0; i < the_lnet.ln_nportals; i++) {
if (lnet_ptl_setup(the_lnet.ln_portals[i], i)) {
lnet_portals_destroy();
return -ENOMEM;
}
}
return 0;
}
int
LNetSetLazyPortal(int portal)
{
struct lnet_portal *ptl;
if (portal < 0 || portal >= the_lnet.ln_nportals)
return -EINVAL;
CDEBUG(D_NET, "Setting portal %d lazy\n", portal);
ptl = the_lnet.ln_portals[portal];
lnet_res_lock(LNET_LOCK_EX);
lnet_ptl_lock(ptl);
lnet_ptl_setopt(ptl, LNET_PTL_LAZY);
lnet_ptl_unlock(ptl);
lnet_res_unlock(LNET_LOCK_EX);
return 0;
}
int
LNetClearLazyPortal(int portal)
{
struct lnet_portal *ptl;
LIST_HEAD (zombies);
if (portal < 0 || portal >= the_lnet.ln_nportals)
return -EINVAL;
ptl = the_lnet.ln_portals[portal];
lnet_res_lock(LNET_LOCK_EX);
lnet_ptl_lock(ptl);
if (!lnet_ptl_is_lazy(ptl)) {
lnet_ptl_unlock(ptl);
lnet_res_unlock(LNET_LOCK_EX);
return 0;
}
if (the_lnet.ln_shutdown)
CWARN("Active lazy portal %d on exit\n", portal);
else
CDEBUG(D_NET, "clearing portal %d lazy\n", portal);
list_splice_init(&ptl->ptl_msg_delayed, &zombies);
lnet_ptl_unsetopt(ptl, LNET_PTL_LAZY);
lnet_ptl_unlock(ptl);
lnet_res_unlock(LNET_LOCK_EX);
lnet_drop_delayed_msg_list(&zombies, "Clearing lazy portal attr");
return 0;
}
