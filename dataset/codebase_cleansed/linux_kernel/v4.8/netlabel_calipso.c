static int netlbl_calipso_add_pass(struct genl_info *info,
struct netlbl_audit *audit_info)
{
int ret_val;
struct calipso_doi *doi_def = NULL;
doi_def = kmalloc(sizeof(*doi_def), GFP_KERNEL);
if (!doi_def)
return -ENOMEM;
doi_def->type = CALIPSO_MAP_PASS;
doi_def->doi = nla_get_u32(info->attrs[NLBL_CALIPSO_A_DOI]);
ret_val = calipso_doi_add(doi_def, audit_info);
if (ret_val != 0)
calipso_doi_free(doi_def);
return ret_val;
}
static int netlbl_calipso_add(struct sk_buff *skb, struct genl_info *info)
{
int ret_val = -EINVAL;
struct netlbl_audit audit_info;
if (!info->attrs[NLBL_CALIPSO_A_DOI] ||
!info->attrs[NLBL_CALIPSO_A_MTYPE])
return -EINVAL;
netlbl_netlink_auditinfo(skb, &audit_info);
switch (nla_get_u32(info->attrs[NLBL_CALIPSO_A_MTYPE])) {
case CALIPSO_MAP_PASS:
ret_val = netlbl_calipso_add_pass(info, &audit_info);
break;
}
if (ret_val == 0)
atomic_inc(&netlabel_mgmt_protocount);
return ret_val;
}
static int netlbl_calipso_list(struct sk_buff *skb, struct genl_info *info)
{
int ret_val;
struct sk_buff *ans_skb = NULL;
void *data;
u32 doi;
struct calipso_doi *doi_def;
if (!info->attrs[NLBL_CALIPSO_A_DOI]) {
ret_val = -EINVAL;
goto list_failure;
}
doi = nla_get_u32(info->attrs[NLBL_CALIPSO_A_DOI]);
doi_def = calipso_doi_getdef(doi);
if (!doi_def) {
ret_val = -EINVAL;
goto list_failure;
}
ans_skb = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!ans_skb) {
ret_val = -ENOMEM;
goto list_failure_put;
}
data = genlmsg_put_reply(ans_skb, info, &netlbl_calipso_gnl_family,
0, NLBL_CALIPSO_C_LIST);
if (!data) {
ret_val = -ENOMEM;
goto list_failure_put;
}
ret_val = nla_put_u32(ans_skb, NLBL_CALIPSO_A_MTYPE, doi_def->type);
if (ret_val != 0)
goto list_failure_put;
calipso_doi_putdef(doi_def);
genlmsg_end(ans_skb, data);
return genlmsg_reply(ans_skb, info);
list_failure_put:
calipso_doi_putdef(doi_def);
list_failure:
kfree_skb(ans_skb);
return ret_val;
}
static int netlbl_calipso_listall_cb(struct calipso_doi *doi_def, void *arg)
{
int ret_val = -ENOMEM;
struct netlbl_calipso_doiwalk_arg *cb_arg = arg;
void *data;
data = genlmsg_put(cb_arg->skb, NETLINK_CB(cb_arg->nl_cb->skb).portid,
cb_arg->seq, &netlbl_calipso_gnl_family,
NLM_F_MULTI, NLBL_CALIPSO_C_LISTALL);
if (!data)
goto listall_cb_failure;
ret_val = nla_put_u32(cb_arg->skb, NLBL_CALIPSO_A_DOI, doi_def->doi);
if (ret_val != 0)
goto listall_cb_failure;
ret_val = nla_put_u32(cb_arg->skb,
NLBL_CALIPSO_A_MTYPE,
doi_def->type);
if (ret_val != 0)
goto listall_cb_failure;
genlmsg_end(cb_arg->skb, data);
return 0;
listall_cb_failure:
genlmsg_cancel(cb_arg->skb, data);
return ret_val;
}
static int netlbl_calipso_listall(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct netlbl_calipso_doiwalk_arg cb_arg;
u32 doi_skip = cb->args[0];
cb_arg.nl_cb = cb;
cb_arg.skb = skb;
cb_arg.seq = cb->nlh->nlmsg_seq;
calipso_doi_walk(&doi_skip, netlbl_calipso_listall_cb, &cb_arg);
cb->args[0] = doi_skip;
return skb->len;
}
static int netlbl_calipso_remove_cb(struct netlbl_dom_map *entry, void *arg)
{
struct netlbl_domhsh_walk_arg *cb_arg = arg;
if (entry->def.type == NETLBL_NLTYPE_CALIPSO &&
entry->def.calipso->doi == cb_arg->doi)
return netlbl_domhsh_remove_entry(entry, cb_arg->audit_info);
return 0;
}
static int netlbl_calipso_remove(struct sk_buff *skb, struct genl_info *info)
{
int ret_val = -EINVAL;
struct netlbl_domhsh_walk_arg cb_arg;
struct netlbl_audit audit_info;
u32 skip_bkt = 0;
u32 skip_chain = 0;
if (!info->attrs[NLBL_CALIPSO_A_DOI])
return -EINVAL;
netlbl_netlink_auditinfo(skb, &audit_info);
cb_arg.doi = nla_get_u32(info->attrs[NLBL_CALIPSO_A_DOI]);
cb_arg.audit_info = &audit_info;
ret_val = netlbl_domhsh_walk(&skip_bkt, &skip_chain,
netlbl_calipso_remove_cb, &cb_arg);
if (ret_val == 0 || ret_val == -ENOENT) {
ret_val = calipso_doi_remove(cb_arg.doi, &audit_info);
if (ret_val == 0)
atomic_dec(&netlabel_mgmt_protocount);
}
return ret_val;
}
int __init netlbl_calipso_genl_init(void)
{
return genl_register_family_with_ops(&netlbl_calipso_gnl_family,
netlbl_calipso_ops);
}
const struct netlbl_calipso_ops *
netlbl_calipso_ops_register(const struct netlbl_calipso_ops *ops)
{
return xchg(&calipso_ops, ops);
}
static const struct netlbl_calipso_ops *netlbl_calipso_ops_get(void)
{
return ACCESS_ONCE(calipso_ops);
}
int calipso_doi_add(struct calipso_doi *doi_def,
struct netlbl_audit *audit_info)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->doi_add(doi_def, audit_info);
return ret_val;
}
void calipso_doi_free(struct calipso_doi *doi_def)
{
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ops->doi_free(doi_def);
}
int calipso_doi_remove(u32 doi, struct netlbl_audit *audit_info)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->doi_remove(doi, audit_info);
return ret_val;
}
struct calipso_doi *calipso_doi_getdef(u32 doi)
{
struct calipso_doi *ret_val = NULL;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->doi_getdef(doi);
return ret_val;
}
void calipso_doi_putdef(struct calipso_doi *doi_def)
{
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ops->doi_putdef(doi_def);
}
int calipso_doi_walk(u32 *skip_cnt,
int (*callback)(struct calipso_doi *doi_def, void *arg),
void *cb_arg)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->doi_walk(skip_cnt, callback, cb_arg);
return ret_val;
}
int calipso_sock_getattr(struct sock *sk, struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->sock_getattr(sk, secattr);
return ret_val;
}
int calipso_sock_setattr(struct sock *sk,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->sock_setattr(sk, doi_def, secattr);
return ret_val;
}
void calipso_sock_delattr(struct sock *sk)
{
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ops->sock_delattr(sk);
}
int calipso_req_setattr(struct request_sock *req,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->req_setattr(req, doi_def, secattr);
return ret_val;
}
void calipso_req_delattr(struct request_sock *req)
{
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ops->req_delattr(req);
}
unsigned char *calipso_optptr(const struct sk_buff *skb)
{
unsigned char *ret_val = NULL;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->skbuff_optptr(skb);
return ret_val;
}
int calipso_getattr(const unsigned char *calipso,
struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->opt_getattr(calipso, secattr);
return ret_val;
}
int calipso_skbuff_setattr(struct sk_buff *skb,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->skbuff_setattr(skb, doi_def, secattr);
return ret_val;
}
int calipso_skbuff_delattr(struct sk_buff *skb)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->skbuff_delattr(skb);
return ret_val;
}
void calipso_cache_invalidate(void)
{
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ops->cache_invalidate();
}
int calipso_cache_add(const unsigned char *calipso_ptr,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
const struct netlbl_calipso_ops *ops = netlbl_calipso_ops_get();
if (ops)
ret_val = ops->cache_add(calipso_ptr, secattr);
return ret_val;
}
