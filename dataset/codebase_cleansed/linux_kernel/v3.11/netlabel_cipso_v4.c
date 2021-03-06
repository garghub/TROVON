static int netlbl_cipsov4_add_common(struct genl_info *info,
struct cipso_v4_doi *doi_def)
{
struct nlattr *nla;
int nla_rem;
u32 iter = 0;
doi_def->doi = nla_get_u32(info->attrs[NLBL_CIPSOV4_A_DOI]);
if (nla_validate_nested(info->attrs[NLBL_CIPSOV4_A_TAGLST],
NLBL_CIPSOV4_A_MAX,
netlbl_cipsov4_genl_policy) != 0)
return -EINVAL;
nla_for_each_nested(nla, info->attrs[NLBL_CIPSOV4_A_TAGLST], nla_rem)
if (nla_type(nla) == NLBL_CIPSOV4_A_TAG) {
if (iter >= CIPSO_V4_TAG_MAXCNT)
return -EINVAL;
doi_def->tags[iter++] = nla_get_u8(nla);
}
while (iter < CIPSO_V4_TAG_MAXCNT)
doi_def->tags[iter++] = CIPSO_V4_TAG_INVALID;
return 0;
}
static int netlbl_cipsov4_add_std(struct genl_info *info,
struct netlbl_audit *audit_info)
{
int ret_val = -EINVAL;
struct cipso_v4_doi *doi_def = NULL;
struct nlattr *nla_a;
struct nlattr *nla_b;
int nla_a_rem;
int nla_b_rem;
u32 iter;
if (!info->attrs[NLBL_CIPSOV4_A_TAGLST] ||
!info->attrs[NLBL_CIPSOV4_A_MLSLVLLST])
return -EINVAL;
if (nla_validate_nested(info->attrs[NLBL_CIPSOV4_A_MLSLVLLST],
NLBL_CIPSOV4_A_MAX,
netlbl_cipsov4_genl_policy) != 0)
return -EINVAL;
doi_def = kmalloc(sizeof(*doi_def), GFP_KERNEL);
if (doi_def == NULL)
return -ENOMEM;
doi_def->map.std = kzalloc(sizeof(*doi_def->map.std), GFP_KERNEL);
if (doi_def->map.std == NULL) {
ret_val = -ENOMEM;
goto add_std_failure;
}
doi_def->type = CIPSO_V4_MAP_TRANS;
ret_val = netlbl_cipsov4_add_common(info, doi_def);
if (ret_val != 0)
goto add_std_failure;
ret_val = -EINVAL;
nla_for_each_nested(nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSLVLLST],
nla_a_rem)
if (nla_type(nla_a) == NLBL_CIPSOV4_A_MLSLVL) {
if (nla_validate_nested(nla_a,
NLBL_CIPSOV4_A_MAX,
netlbl_cipsov4_genl_policy) != 0)
goto add_std_failure;
nla_for_each_nested(nla_b, nla_a, nla_b_rem)
switch (nla_type(nla_b)) {
case NLBL_CIPSOV4_A_MLSLVLLOC:
if (nla_get_u32(nla_b) >
CIPSO_V4_MAX_LOC_LVLS)
goto add_std_failure;
if (nla_get_u32(nla_b) >=
doi_def->map.std->lvl.local_size)
doi_def->map.std->lvl.local_size =
nla_get_u32(nla_b) + 1;
break;
case NLBL_CIPSOV4_A_MLSLVLREM:
if (nla_get_u32(nla_b) >
CIPSO_V4_MAX_REM_LVLS)
goto add_std_failure;
if (nla_get_u32(nla_b) >=
doi_def->map.std->lvl.cipso_size)
doi_def->map.std->lvl.cipso_size =
nla_get_u32(nla_b) + 1;
break;
}
}
doi_def->map.std->lvl.local = kcalloc(doi_def->map.std->lvl.local_size,
sizeof(u32),
GFP_KERNEL);
if (doi_def->map.std->lvl.local == NULL) {
ret_val = -ENOMEM;
goto add_std_failure;
}
doi_def->map.std->lvl.cipso = kcalloc(doi_def->map.std->lvl.cipso_size,
sizeof(u32),
GFP_KERNEL);
if (doi_def->map.std->lvl.cipso == NULL) {
ret_val = -ENOMEM;
goto add_std_failure;
}
for (iter = 0; iter < doi_def->map.std->lvl.local_size; iter++)
doi_def->map.std->lvl.local[iter] = CIPSO_V4_INV_LVL;
for (iter = 0; iter < doi_def->map.std->lvl.cipso_size; iter++)
doi_def->map.std->lvl.cipso[iter] = CIPSO_V4_INV_LVL;
nla_for_each_nested(nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSLVLLST],
nla_a_rem)
if (nla_type(nla_a) == NLBL_CIPSOV4_A_MLSLVL) {
struct nlattr *lvl_loc;
struct nlattr *lvl_rem;
lvl_loc = nla_find_nested(nla_a,
NLBL_CIPSOV4_A_MLSLVLLOC);
lvl_rem = nla_find_nested(nla_a,
NLBL_CIPSOV4_A_MLSLVLREM);
if (lvl_loc == NULL || lvl_rem == NULL)
goto add_std_failure;
doi_def->map.std->lvl.local[nla_get_u32(lvl_loc)] =
nla_get_u32(lvl_rem);
doi_def->map.std->lvl.cipso[nla_get_u32(lvl_rem)] =
nla_get_u32(lvl_loc);
}
if (info->attrs[NLBL_CIPSOV4_A_MLSCATLST]) {
if (nla_validate_nested(info->attrs[NLBL_CIPSOV4_A_MLSCATLST],
NLBL_CIPSOV4_A_MAX,
netlbl_cipsov4_genl_policy) != 0)
goto add_std_failure;
nla_for_each_nested(nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSCATLST],
nla_a_rem)
if (nla_type(nla_a) == NLBL_CIPSOV4_A_MLSCAT) {
if (nla_validate_nested(nla_a,
NLBL_CIPSOV4_A_MAX,
netlbl_cipsov4_genl_policy) != 0)
goto add_std_failure;
nla_for_each_nested(nla_b, nla_a, nla_b_rem)
switch (nla_type(nla_b)) {
case NLBL_CIPSOV4_A_MLSCATLOC:
if (nla_get_u32(nla_b) >
CIPSO_V4_MAX_LOC_CATS)
goto add_std_failure;
if (nla_get_u32(nla_b) >=
doi_def->map.std->cat.local_size)
doi_def->map.std->cat.local_size =
nla_get_u32(nla_b) + 1;
break;
case NLBL_CIPSOV4_A_MLSCATREM:
if (nla_get_u32(nla_b) >
CIPSO_V4_MAX_REM_CATS)
goto add_std_failure;
if (nla_get_u32(nla_b) >=
doi_def->map.std->cat.cipso_size)
doi_def->map.std->cat.cipso_size =
nla_get_u32(nla_b) + 1;
break;
}
}
doi_def->map.std->cat.local = kcalloc(
doi_def->map.std->cat.local_size,
sizeof(u32),
GFP_KERNEL);
if (doi_def->map.std->cat.local == NULL) {
ret_val = -ENOMEM;
goto add_std_failure;
}
doi_def->map.std->cat.cipso = kcalloc(
doi_def->map.std->cat.cipso_size,
sizeof(u32),
GFP_KERNEL);
if (doi_def->map.std->cat.cipso == NULL) {
ret_val = -ENOMEM;
goto add_std_failure;
}
for (iter = 0; iter < doi_def->map.std->cat.local_size; iter++)
doi_def->map.std->cat.local[iter] = CIPSO_V4_INV_CAT;
for (iter = 0; iter < doi_def->map.std->cat.cipso_size; iter++)
doi_def->map.std->cat.cipso[iter] = CIPSO_V4_INV_CAT;
nla_for_each_nested(nla_a,
info->attrs[NLBL_CIPSOV4_A_MLSCATLST],
nla_a_rem)
if (nla_type(nla_a) == NLBL_CIPSOV4_A_MLSCAT) {
struct nlattr *cat_loc;
struct nlattr *cat_rem;
cat_loc = nla_find_nested(nla_a,
NLBL_CIPSOV4_A_MLSCATLOC);
cat_rem = nla_find_nested(nla_a,
NLBL_CIPSOV4_A_MLSCATREM);
if (cat_loc == NULL || cat_rem == NULL)
goto add_std_failure;
doi_def->map.std->cat.local[
nla_get_u32(cat_loc)] =
nla_get_u32(cat_rem);
doi_def->map.std->cat.cipso[
nla_get_u32(cat_rem)] =
nla_get_u32(cat_loc);
}
}
ret_val = cipso_v4_doi_add(doi_def, audit_info);
if (ret_val != 0)
goto add_std_failure;
return 0;
add_std_failure:
if (doi_def)
cipso_v4_doi_free(doi_def);
return ret_val;
}
static int netlbl_cipsov4_add_pass(struct genl_info *info,
struct netlbl_audit *audit_info)
{
int ret_val;
struct cipso_v4_doi *doi_def = NULL;
if (!info->attrs[NLBL_CIPSOV4_A_TAGLST])
return -EINVAL;
doi_def = kmalloc(sizeof(*doi_def), GFP_KERNEL);
if (doi_def == NULL)
return -ENOMEM;
doi_def->type = CIPSO_V4_MAP_PASS;
ret_val = netlbl_cipsov4_add_common(info, doi_def);
if (ret_val != 0)
goto add_pass_failure;
ret_val = cipso_v4_doi_add(doi_def, audit_info);
if (ret_val != 0)
goto add_pass_failure;
return 0;
add_pass_failure:
cipso_v4_doi_free(doi_def);
return ret_val;
}
static int netlbl_cipsov4_add_local(struct genl_info *info,
struct netlbl_audit *audit_info)
{
int ret_val;
struct cipso_v4_doi *doi_def = NULL;
if (!info->attrs[NLBL_CIPSOV4_A_TAGLST])
return -EINVAL;
doi_def = kmalloc(sizeof(*doi_def), GFP_KERNEL);
if (doi_def == NULL)
return -ENOMEM;
doi_def->type = CIPSO_V4_MAP_LOCAL;
ret_val = netlbl_cipsov4_add_common(info, doi_def);
if (ret_val != 0)
goto add_local_failure;
ret_val = cipso_v4_doi_add(doi_def, audit_info);
if (ret_val != 0)
goto add_local_failure;
return 0;
add_local_failure:
cipso_v4_doi_free(doi_def);
return ret_val;
}
static int netlbl_cipsov4_add(struct sk_buff *skb, struct genl_info *info)
{
int ret_val = -EINVAL;
struct netlbl_audit audit_info;
if (!info->attrs[NLBL_CIPSOV4_A_DOI] ||
!info->attrs[NLBL_CIPSOV4_A_MTYPE])
return -EINVAL;
netlbl_netlink_auditinfo(skb, &audit_info);
switch (nla_get_u32(info->attrs[NLBL_CIPSOV4_A_MTYPE])) {
case CIPSO_V4_MAP_TRANS:
ret_val = netlbl_cipsov4_add_std(info, &audit_info);
break;
case CIPSO_V4_MAP_PASS:
ret_val = netlbl_cipsov4_add_pass(info, &audit_info);
break;
case CIPSO_V4_MAP_LOCAL:
ret_val = netlbl_cipsov4_add_local(info, &audit_info);
break;
}
if (ret_val == 0)
atomic_inc(&netlabel_mgmt_protocount);
return ret_val;
}
static int netlbl_cipsov4_list(struct sk_buff *skb, struct genl_info *info)
{
int ret_val;
struct sk_buff *ans_skb = NULL;
u32 nlsze_mult = 1;
void *data;
u32 doi;
struct nlattr *nla_a;
struct nlattr *nla_b;
struct cipso_v4_doi *doi_def;
u32 iter;
if (!info->attrs[NLBL_CIPSOV4_A_DOI]) {
ret_val = -EINVAL;
goto list_failure;
}
list_start:
ans_skb = nlmsg_new(NLMSG_DEFAULT_SIZE * nlsze_mult, GFP_KERNEL);
if (ans_skb == NULL) {
ret_val = -ENOMEM;
goto list_failure;
}
data = genlmsg_put_reply(ans_skb, info, &netlbl_cipsov4_gnl_family,
0, NLBL_CIPSOV4_C_LIST);
if (data == NULL) {
ret_val = -ENOMEM;
goto list_failure;
}
doi = nla_get_u32(info->attrs[NLBL_CIPSOV4_A_DOI]);
rcu_read_lock();
doi_def = cipso_v4_doi_getdef(doi);
if (doi_def == NULL) {
ret_val = -EINVAL;
goto list_failure_lock;
}
ret_val = nla_put_u32(ans_skb, NLBL_CIPSOV4_A_MTYPE, doi_def->type);
if (ret_val != 0)
goto list_failure_lock;
nla_a = nla_nest_start(ans_skb, NLBL_CIPSOV4_A_TAGLST);
if (nla_a == NULL) {
ret_val = -ENOMEM;
goto list_failure_lock;
}
for (iter = 0;
iter < CIPSO_V4_TAG_MAXCNT &&
doi_def->tags[iter] != CIPSO_V4_TAG_INVALID;
iter++) {
ret_val = nla_put_u8(ans_skb,
NLBL_CIPSOV4_A_TAG,
doi_def->tags[iter]);
if (ret_val != 0)
goto list_failure_lock;
}
nla_nest_end(ans_skb, nla_a);
switch (doi_def->type) {
case CIPSO_V4_MAP_TRANS:
nla_a = nla_nest_start(ans_skb, NLBL_CIPSOV4_A_MLSLVLLST);
if (nla_a == NULL) {
ret_val = -ENOMEM;
goto list_failure_lock;
}
for (iter = 0;
iter < doi_def->map.std->lvl.local_size;
iter++) {
if (doi_def->map.std->lvl.local[iter] ==
CIPSO_V4_INV_LVL)
continue;
nla_b = nla_nest_start(ans_skb, NLBL_CIPSOV4_A_MLSLVL);
if (nla_b == NULL) {
ret_val = -ENOMEM;
goto list_retry;
}
ret_val = nla_put_u32(ans_skb,
NLBL_CIPSOV4_A_MLSLVLLOC,
iter);
if (ret_val != 0)
goto list_retry;
ret_val = nla_put_u32(ans_skb,
NLBL_CIPSOV4_A_MLSLVLREM,
doi_def->map.std->lvl.local[iter]);
if (ret_val != 0)
goto list_retry;
nla_nest_end(ans_skb, nla_b);
}
nla_nest_end(ans_skb, nla_a);
nla_a = nla_nest_start(ans_skb, NLBL_CIPSOV4_A_MLSCATLST);
if (nla_a == NULL) {
ret_val = -ENOMEM;
goto list_retry;
}
for (iter = 0;
iter < doi_def->map.std->cat.local_size;
iter++) {
if (doi_def->map.std->cat.local[iter] ==
CIPSO_V4_INV_CAT)
continue;
nla_b = nla_nest_start(ans_skb, NLBL_CIPSOV4_A_MLSCAT);
if (nla_b == NULL) {
ret_val = -ENOMEM;
goto list_retry;
}
ret_val = nla_put_u32(ans_skb,
NLBL_CIPSOV4_A_MLSCATLOC,
iter);
if (ret_val != 0)
goto list_retry;
ret_val = nla_put_u32(ans_skb,
NLBL_CIPSOV4_A_MLSCATREM,
doi_def->map.std->cat.local[iter]);
if (ret_val != 0)
goto list_retry;
nla_nest_end(ans_skb, nla_b);
}
nla_nest_end(ans_skb, nla_a);
break;
}
rcu_read_unlock();
genlmsg_end(ans_skb, data);
return genlmsg_reply(ans_skb, info);
list_retry:
if (nlsze_mult < 4) {
rcu_read_unlock();
kfree_skb(ans_skb);
nlsze_mult *= 2;
goto list_start;
}
list_failure_lock:
rcu_read_unlock();
list_failure:
kfree_skb(ans_skb);
return ret_val;
}
static int netlbl_cipsov4_listall_cb(struct cipso_v4_doi *doi_def, void *arg)
{
int ret_val = -ENOMEM;
struct netlbl_cipsov4_doiwalk_arg *cb_arg = arg;
void *data;
data = genlmsg_put(cb_arg->skb, NETLINK_CB(cb_arg->nl_cb->skb).portid,
cb_arg->seq, &netlbl_cipsov4_gnl_family,
NLM_F_MULTI, NLBL_CIPSOV4_C_LISTALL);
if (data == NULL)
goto listall_cb_failure;
ret_val = nla_put_u32(cb_arg->skb, NLBL_CIPSOV4_A_DOI, doi_def->doi);
if (ret_val != 0)
goto listall_cb_failure;
ret_val = nla_put_u32(cb_arg->skb,
NLBL_CIPSOV4_A_MTYPE,
doi_def->type);
if (ret_val != 0)
goto listall_cb_failure;
return genlmsg_end(cb_arg->skb, data);
listall_cb_failure:
genlmsg_cancel(cb_arg->skb, data);
return ret_val;
}
static int netlbl_cipsov4_listall(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct netlbl_cipsov4_doiwalk_arg cb_arg;
u32 doi_skip = cb->args[0];
cb_arg.nl_cb = cb;
cb_arg.skb = skb;
cb_arg.seq = cb->nlh->nlmsg_seq;
cipso_v4_doi_walk(&doi_skip, netlbl_cipsov4_listall_cb, &cb_arg);
cb->args[0] = doi_skip;
return skb->len;
}
static int netlbl_cipsov4_remove_cb(struct netlbl_dom_map *entry, void *arg)
{
struct netlbl_domhsh_walk_arg *cb_arg = arg;
if (entry->def.type == NETLBL_NLTYPE_CIPSOV4 &&
entry->def.cipso->doi == cb_arg->doi)
return netlbl_domhsh_remove_entry(entry, cb_arg->audit_info);
return 0;
}
static int netlbl_cipsov4_remove(struct sk_buff *skb, struct genl_info *info)
{
int ret_val = -EINVAL;
struct netlbl_domhsh_walk_arg cb_arg;
struct netlbl_audit audit_info;
u32 skip_bkt = 0;
u32 skip_chain = 0;
if (!info->attrs[NLBL_CIPSOV4_A_DOI])
return -EINVAL;
netlbl_netlink_auditinfo(skb, &audit_info);
cb_arg.doi = nla_get_u32(info->attrs[NLBL_CIPSOV4_A_DOI]);
cb_arg.audit_info = &audit_info;
ret_val = netlbl_domhsh_walk(&skip_bkt, &skip_chain,
netlbl_cipsov4_remove_cb, &cb_arg);
if (ret_val == 0 || ret_val == -ENOENT) {
ret_val = cipso_v4_doi_remove(cb_arg.doi, &audit_info);
if (ret_val == 0)
atomic_dec(&netlabel_mgmt_protocount);
}
return ret_val;
}
int __init netlbl_cipsov4_genl_init(void)
{
return genl_register_family_with_ops(&netlbl_cipsov4_gnl_family,
netlbl_cipsov4_ops, ARRAY_SIZE(netlbl_cipsov4_ops));
}
