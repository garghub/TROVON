static inline void
ip_set_type_lock(void)
{
mutex_lock(&ip_set_type_mutex);
}
static inline void
ip_set_type_unlock(void)
{
mutex_unlock(&ip_set_type_mutex);
}
static struct ip_set_type *
find_set_type(const char *name, u8 family, u8 revision)
{
struct ip_set_type *type;
list_for_each_entry_rcu(type, &ip_set_type_list, list)
if (STREQ(type->name, name) &&
(type->family == family ||
type->family == NFPROTO_UNSPEC) &&
revision >= type->revision_min &&
revision <= type->revision_max)
return type;
return NULL;
}
static bool
load_settype(const char *name)
{
nfnl_unlock(NFNL_SUBSYS_IPSET);
pr_debug("try to load ip_set_%s\n", name);
if (request_module("ip_set_%s", name) < 0) {
pr_warning("Can't find ip_set type %s\n", name);
nfnl_lock(NFNL_SUBSYS_IPSET);
return false;
}
nfnl_lock(NFNL_SUBSYS_IPSET);
return true;
}
static int
__find_set_type_get(const char *name, u8 family, u8 revision,
struct ip_set_type **found, bool retry)
{
struct ip_set_type *type;
int err;
if (retry && !load_settype(name))
return -IPSET_ERR_FIND_TYPE;
rcu_read_lock();
*found = find_set_type(name, family, revision);
if (*found) {
err = !try_module_get((*found)->me) ? -EFAULT : 0;
goto unlock;
}
list_for_each_entry_rcu(type, &ip_set_type_list, list)
if (STREQ(type->name, name)) {
err = -IPSET_ERR_FIND_TYPE;
goto unlock;
}
rcu_read_unlock();
return retry ? -IPSET_ERR_FIND_TYPE :
__find_set_type_get(name, family, revision, found, true);
unlock:
rcu_read_unlock();
return err;
}
static int
__find_set_type_minmax(const char *name, u8 family, u8 *min, u8 *max,
bool retry)
{
struct ip_set_type *type;
bool found = false;
if (retry && !load_settype(name))
return -IPSET_ERR_FIND_TYPE;
*min = 255; *max = 0;
rcu_read_lock();
list_for_each_entry_rcu(type, &ip_set_type_list, list)
if (STREQ(type->name, name) &&
(type->family == family ||
type->family == NFPROTO_UNSPEC)) {
found = true;
if (type->revision_min < *min)
*min = type->revision_min;
if (type->revision_max > *max)
*max = type->revision_max;
}
rcu_read_unlock();
if (found)
return 0;
return retry ? -IPSET_ERR_FIND_TYPE :
__find_set_type_minmax(name, family, min, max, true);
}
int
ip_set_type_register(struct ip_set_type *type)
{
int ret = 0;
if (type->protocol != IPSET_PROTOCOL) {
pr_warning("ip_set type %s, family %s, revision %u:%u uses "
"wrong protocol version %u (want %u)\n",
type->name, family_name(type->family),
type->revision_min, type->revision_max,
type->protocol, IPSET_PROTOCOL);
return -EINVAL;
}
ip_set_type_lock();
if (find_set_type(type->name, type->family, type->revision_min)) {
pr_warning("ip_set type %s, family %s with revision min %u "
"already registered!\n", type->name,
family_name(type->family), type->revision_min);
ret = -EINVAL;
goto unlock;
}
list_add_rcu(&type->list, &ip_set_type_list);
pr_debug("type %s, family %s, revision %u:%u registered.\n",
type->name, family_name(type->family),
type->revision_min, type->revision_max);
unlock:
ip_set_type_unlock();
return ret;
}
void
ip_set_type_unregister(struct ip_set_type *type)
{
ip_set_type_lock();
if (!find_set_type(type->name, type->family, type->revision_min)) {
pr_warning("ip_set type %s, family %s with revision min %u "
"not registered\n", type->name,
family_name(type->family), type->revision_min);
goto unlock;
}
list_del_rcu(&type->list);
pr_debug("type %s, family %s with revision min %u unregistered.\n",
type->name, family_name(type->family), type->revision_min);
unlock:
ip_set_type_unlock();
synchronize_rcu();
}
void *
ip_set_alloc(size_t size)
{
void *members = NULL;
if (size < KMALLOC_MAX_SIZE)
members = kzalloc(size, GFP_KERNEL | __GFP_NOWARN);
if (members) {
pr_debug("%p: allocated with kmalloc\n", members);
return members;
}
members = vzalloc(size);
if (!members)
return NULL;
pr_debug("%p: allocated with vmalloc\n", members);
return members;
}
void
ip_set_free(void *members)
{
pr_debug("%p: free with %s\n", members,
is_vmalloc_addr(members) ? "vfree" : "kfree");
if (is_vmalloc_addr(members))
vfree(members);
else
kfree(members);
}
static inline bool
flag_nested(const struct nlattr *nla)
{
return nla->nla_type & NLA_F_NESTED;
}
int
ip_set_get_ipaddr4(struct nlattr *nla, __be32 *ipaddr)
{
struct nlattr *tb[IPSET_ATTR_IPADDR_MAX+1];
if (unlikely(!flag_nested(nla)))
return -IPSET_ERR_PROTOCOL;
if (nla_parse_nested(tb, IPSET_ATTR_IPADDR_MAX, nla, ipaddr_policy))
return -IPSET_ERR_PROTOCOL;
if (unlikely(!ip_set_attr_netorder(tb, IPSET_ATTR_IPADDR_IPV4)))
return -IPSET_ERR_PROTOCOL;
*ipaddr = nla_get_be32(tb[IPSET_ATTR_IPADDR_IPV4]);
return 0;
}
int
ip_set_get_ipaddr6(struct nlattr *nla, union nf_inet_addr *ipaddr)
{
struct nlattr *tb[IPSET_ATTR_IPADDR_MAX+1];
if (unlikely(!flag_nested(nla)))
return -IPSET_ERR_PROTOCOL;
if (nla_parse_nested(tb, IPSET_ATTR_IPADDR_MAX, nla, ipaddr_policy))
return -IPSET_ERR_PROTOCOL;
if (unlikely(!ip_set_attr_netorder(tb, IPSET_ATTR_IPADDR_IPV6)))
return -IPSET_ERR_PROTOCOL;
memcpy(ipaddr, nla_data(tb[IPSET_ATTR_IPADDR_IPV6]),
sizeof(struct in6_addr));
return 0;
}
static inline void
__ip_set_get(struct ip_set *set)
{
write_lock_bh(&ip_set_ref_lock);
set->ref++;
write_unlock_bh(&ip_set_ref_lock);
}
static inline void
__ip_set_put(struct ip_set *set)
{
write_lock_bh(&ip_set_ref_lock);
BUG_ON(set->ref == 0);
set->ref--;
write_unlock_bh(&ip_set_ref_lock);
}
static inline struct ip_set *
ip_set_rcu_get(ip_set_id_t index)
{
struct ip_set *set;
rcu_read_lock();
set = rcu_dereference(ip_set_list)[index];
rcu_read_unlock();
return set;
}
int
ip_set_test(ip_set_id_t index, const struct sk_buff *skb,
const struct xt_action_param *par,
const struct ip_set_adt_opt *opt)
{
struct ip_set *set = ip_set_rcu_get(index);
int ret = 0;
BUG_ON(set == NULL);
pr_debug("set %s, index %u\n", set->name, index);
if (opt->dim < set->type->dimension ||
!(opt->family == set->family || set->family == NFPROTO_UNSPEC))
return 0;
read_lock_bh(&set->lock);
ret = set->variant->kadt(set, skb, par, IPSET_TEST, opt);
read_unlock_bh(&set->lock);
if (ret == -EAGAIN) {
pr_debug("element must be competed, ADD is triggered\n");
write_lock_bh(&set->lock);
set->variant->kadt(set, skb, par, IPSET_ADD, opt);
write_unlock_bh(&set->lock);
ret = 1;
} else {
if ((opt->flags & IPSET_RETURN_NOMATCH) &&
(set->type->features & IPSET_TYPE_NOMATCH) &&
(ret > 0 || ret == -ENOTEMPTY))
ret = -ret;
}
return (ret < 0 ? 0 : ret);
}
int
ip_set_add(ip_set_id_t index, const struct sk_buff *skb,
const struct xt_action_param *par,
const struct ip_set_adt_opt *opt)
{
struct ip_set *set = ip_set_rcu_get(index);
int ret;
BUG_ON(set == NULL);
pr_debug("set %s, index %u\n", set->name, index);
if (opt->dim < set->type->dimension ||
!(opt->family == set->family || set->family == NFPROTO_UNSPEC))
return 0;
write_lock_bh(&set->lock);
ret = set->variant->kadt(set, skb, par, IPSET_ADD, opt);
write_unlock_bh(&set->lock);
return ret;
}
int
ip_set_del(ip_set_id_t index, const struct sk_buff *skb,
const struct xt_action_param *par,
const struct ip_set_adt_opt *opt)
{
struct ip_set *set = ip_set_rcu_get(index);
int ret = 0;
BUG_ON(set == NULL);
pr_debug("set %s, index %u\n", set->name, index);
if (opt->dim < set->type->dimension ||
!(opt->family == set->family || set->family == NFPROTO_UNSPEC))
return 0;
write_lock_bh(&set->lock);
ret = set->variant->kadt(set, skb, par, IPSET_DEL, opt);
write_unlock_bh(&set->lock);
return ret;
}
ip_set_id_t
ip_set_get_byname(const char *name, struct ip_set **set)
{
ip_set_id_t i, index = IPSET_INVALID_ID;
struct ip_set *s;
rcu_read_lock();
for (i = 0; i < ip_set_max; i++) {
s = rcu_dereference(ip_set_list)[i];
if (s != NULL && STREQ(s->name, name)) {
__ip_set_get(s);
index = i;
*set = s;
break;
}
}
rcu_read_unlock();
return index;
}
void
ip_set_put_byindex(ip_set_id_t index)
{
struct ip_set *set;
rcu_read_lock();
set = rcu_dereference(ip_set_list)[index];
if (set != NULL)
__ip_set_put(set);
rcu_read_unlock();
}
const char *
ip_set_name_byindex(ip_set_id_t index)
{
const struct ip_set *set = ip_set_rcu_get(index);
BUG_ON(set == NULL);
BUG_ON(set->ref == 0);
return set->name;
}
ip_set_id_t
ip_set_nfnl_get(const char *name)
{
ip_set_id_t i, index = IPSET_INVALID_ID;
struct ip_set *s;
nfnl_lock(NFNL_SUBSYS_IPSET);
for (i = 0; i < ip_set_max; i++) {
s = nfnl_set(i);
if (s != NULL && STREQ(s->name, name)) {
__ip_set_get(s);
index = i;
break;
}
}
nfnl_unlock(NFNL_SUBSYS_IPSET);
return index;
}
ip_set_id_t
ip_set_nfnl_get_byindex(ip_set_id_t index)
{
struct ip_set *set;
if (index > ip_set_max)
return IPSET_INVALID_ID;
nfnl_lock(NFNL_SUBSYS_IPSET);
set = nfnl_set(index);
if (set)
__ip_set_get(set);
else
index = IPSET_INVALID_ID;
nfnl_unlock(NFNL_SUBSYS_IPSET);
return index;
}
void
ip_set_nfnl_put(ip_set_id_t index)
{
struct ip_set *set;
nfnl_lock(NFNL_SUBSYS_IPSET);
set = nfnl_set(index);
if (set != NULL)
__ip_set_put(set);
nfnl_unlock(NFNL_SUBSYS_IPSET);
}
static inline bool
protocol_failed(const struct nlattr * const tb[])
{
return !tb[IPSET_ATTR_PROTOCOL] ||
nla_get_u8(tb[IPSET_ATTR_PROTOCOL]) != IPSET_PROTOCOL;
}
static inline u32
flag_exist(const struct nlmsghdr *nlh)
{
return nlh->nlmsg_flags & NLM_F_EXCL ? 0 : IPSET_FLAG_EXIST;
}
static struct nlmsghdr *
start_msg(struct sk_buff *skb, u32 portid, u32 seq, unsigned int flags,
enum ipset_cmd cmd)
{
struct nlmsghdr *nlh;
struct nfgenmsg *nfmsg;
nlh = nlmsg_put(skb, portid, seq, cmd | (NFNL_SUBSYS_IPSET << 8),
sizeof(*nfmsg), flags);
if (nlh == NULL)
return NULL;
nfmsg = nlmsg_data(nlh);
nfmsg->nfgen_family = NFPROTO_IPV4;
nfmsg->version = NFNETLINK_V0;
nfmsg->res_id = 0;
return nlh;
}
static struct ip_set *
find_set_and_id(const char *name, ip_set_id_t *id)
{
struct ip_set *set = NULL;
ip_set_id_t i;
*id = IPSET_INVALID_ID;
for (i = 0; i < ip_set_max; i++) {
set = nfnl_set(i);
if (set != NULL && STREQ(set->name, name)) {
*id = i;
break;
}
}
return (*id == IPSET_INVALID_ID ? NULL : set);
}
static inline struct ip_set *
find_set(const char *name)
{
ip_set_id_t id;
return find_set_and_id(name, &id);
}
static int
find_free_id(const char *name, ip_set_id_t *index, struct ip_set **set)
{
struct ip_set *s;
ip_set_id_t i;
*index = IPSET_INVALID_ID;
for (i = 0; i < ip_set_max; i++) {
s = nfnl_set(i);
if (s == NULL) {
if (*index == IPSET_INVALID_ID)
*index = i;
} else if (STREQ(name, s->name)) {
*set = s;
return -EEXIST;
}
}
if (*index == IPSET_INVALID_ID)
return -IPSET_ERR_MAX_SETS;
return 0;
}
static int
ip_set_none(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
return -EOPNOTSUPP;
}
static int
ip_set_create(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *set, *clash = NULL;
ip_set_id_t index = IPSET_INVALID_ID;
struct nlattr *tb[IPSET_ATTR_CREATE_MAX+1] = {};
const char *name, *typename;
u8 family, revision;
u32 flags = flag_exist(nlh);
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL ||
attr[IPSET_ATTR_TYPENAME] == NULL ||
attr[IPSET_ATTR_REVISION] == NULL ||
attr[IPSET_ATTR_FAMILY] == NULL ||
(attr[IPSET_ATTR_DATA] != NULL &&
!flag_nested(attr[IPSET_ATTR_DATA]))))
return -IPSET_ERR_PROTOCOL;
name = nla_data(attr[IPSET_ATTR_SETNAME]);
typename = nla_data(attr[IPSET_ATTR_TYPENAME]);
family = nla_get_u8(attr[IPSET_ATTR_FAMILY]);
revision = nla_get_u8(attr[IPSET_ATTR_REVISION]);
pr_debug("setname: %s, typename: %s, family: %s, revision: %u\n",
name, typename, family_name(family), revision);
set = kzalloc(sizeof(struct ip_set), GFP_KERNEL);
if (!set)
return -ENOMEM;
rwlock_init(&set->lock);
strlcpy(set->name, name, IPSET_MAXNAMELEN);
set->family = family;
set->revision = revision;
ret = find_set_type_get(typename, family, revision, &(set->type));
if (ret)
goto out;
if (attr[IPSET_ATTR_DATA] &&
nla_parse_nested(tb, IPSET_ATTR_CREATE_MAX, attr[IPSET_ATTR_DATA],
set->type->create_policy)) {
ret = -IPSET_ERR_PROTOCOL;
goto put_out;
}
ret = set->type->create(set, tb, flags);
if (ret != 0)
goto put_out;
ret = find_free_id(set->name, &index, &clash);
if (ret == -EEXIST) {
if ((flags & IPSET_FLAG_EXIST) &&
STREQ(set->type->name, clash->type->name) &&
set->type->family == clash->type->family &&
set->type->revision_min == clash->type->revision_min &&
set->type->revision_max == clash->type->revision_max &&
set->variant->same_set(set, clash))
ret = 0;
goto cleanup;
} else if (ret == -IPSET_ERR_MAX_SETS) {
struct ip_set **list, **tmp;
ip_set_id_t i = ip_set_max + IP_SET_INC;
if (i < ip_set_max || i == IPSET_INVALID_ID)
goto cleanup;
list = kzalloc(sizeof(struct ip_set *) * i, GFP_KERNEL);
if (!list)
goto cleanup;
tmp = nfnl_dereference(ip_set_list);
memcpy(list, tmp, sizeof(struct ip_set *) * ip_set_max);
rcu_assign_pointer(ip_set_list, list);
synchronize_net();
index = ip_set_max;
ip_set_max = i;
kfree(tmp);
ret = 0;
} else if (ret)
goto cleanup;
pr_debug("create: '%s' created with index %u!\n", set->name, index);
nfnl_set(index) = set;
return ret;
cleanup:
set->variant->destroy(set);
put_out:
module_put(set->type->me);
out:
kfree(set);
return ret;
}
static void
ip_set_destroy_set(ip_set_id_t index)
{
struct ip_set *set = nfnl_set(index);
pr_debug("set: %s\n", set->name);
nfnl_set(index) = NULL;
set->variant->destroy(set);
module_put(set->type->me);
kfree(set);
}
static int
ip_set_destroy(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *s;
ip_set_id_t i;
int ret = 0;
if (unlikely(protocol_failed(attr)))
return -IPSET_ERR_PROTOCOL;
read_lock_bh(&ip_set_ref_lock);
if (!attr[IPSET_ATTR_SETNAME]) {
for (i = 0; i < ip_set_max; i++) {
s = nfnl_set(i);
if (s != NULL && s->ref) {
ret = -IPSET_ERR_BUSY;
goto out;
}
}
read_unlock_bh(&ip_set_ref_lock);
for (i = 0; i < ip_set_max; i++) {
s = nfnl_set(i);
if (s != NULL)
ip_set_destroy_set(i);
}
} else {
s = find_set_and_id(nla_data(attr[IPSET_ATTR_SETNAME]), &i);
if (s == NULL) {
ret = -ENOENT;
goto out;
} else if (s->ref) {
ret = -IPSET_ERR_BUSY;
goto out;
}
read_unlock_bh(&ip_set_ref_lock);
ip_set_destroy_set(i);
}
return 0;
out:
read_unlock_bh(&ip_set_ref_lock);
return ret;
}
static void
ip_set_flush_set(struct ip_set *set)
{
pr_debug("set: %s\n", set->name);
write_lock_bh(&set->lock);
set->variant->flush(set);
write_unlock_bh(&set->lock);
}
static int
ip_set_flush(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *s;
ip_set_id_t i;
if (unlikely(protocol_failed(attr)))
return -IPSET_ERR_PROTOCOL;
if (!attr[IPSET_ATTR_SETNAME]) {
for (i = 0; i < ip_set_max; i++) {
s = nfnl_set(i);
if (s != NULL)
ip_set_flush_set(s);
}
} else {
s = find_set(nla_data(attr[IPSET_ATTR_SETNAME]));
if (s == NULL)
return -ENOENT;
ip_set_flush_set(s);
}
return 0;
}
static int
ip_set_rename(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *set, *s;
const char *name2;
ip_set_id_t i;
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL ||
attr[IPSET_ATTR_SETNAME2] == NULL))
return -IPSET_ERR_PROTOCOL;
set = find_set(nla_data(attr[IPSET_ATTR_SETNAME]));
if (set == NULL)
return -ENOENT;
read_lock_bh(&ip_set_ref_lock);
if (set->ref != 0) {
ret = -IPSET_ERR_REFERENCED;
goto out;
}
name2 = nla_data(attr[IPSET_ATTR_SETNAME2]);
for (i = 0; i < ip_set_max; i++) {
s = nfnl_set(i);
if (s != NULL && STREQ(s->name, name2)) {
ret = -IPSET_ERR_EXIST_SETNAME2;
goto out;
}
}
strncpy(set->name, name2, IPSET_MAXNAMELEN);
out:
read_unlock_bh(&ip_set_ref_lock);
return ret;
}
static int
ip_set_swap(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *from, *to;
ip_set_id_t from_id, to_id;
char from_name[IPSET_MAXNAMELEN];
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL ||
attr[IPSET_ATTR_SETNAME2] == NULL))
return -IPSET_ERR_PROTOCOL;
from = find_set_and_id(nla_data(attr[IPSET_ATTR_SETNAME]), &from_id);
if (from == NULL)
return -ENOENT;
to = find_set_and_id(nla_data(attr[IPSET_ATTR_SETNAME2]), &to_id);
if (to == NULL)
return -IPSET_ERR_EXIST_SETNAME2;
if (!(from->type->features == to->type->features &&
from->type->family == to->type->family))
return -IPSET_ERR_TYPE_MISMATCH;
strncpy(from_name, from->name, IPSET_MAXNAMELEN);
strncpy(from->name, to->name, IPSET_MAXNAMELEN);
strncpy(to->name, from_name, IPSET_MAXNAMELEN);
write_lock_bh(&ip_set_ref_lock);
swap(from->ref, to->ref);
nfnl_set(from_id) = to;
nfnl_set(to_id) = from;
write_unlock_bh(&ip_set_ref_lock);
return 0;
}
static int
ip_set_dump_done(struct netlink_callback *cb)
{
if (cb->args[2]) {
pr_debug("release set %s\n", nfnl_set(cb->args[1])->name);
ip_set_put_byindex((ip_set_id_t) cb->args[1]);
}
return 0;
}
static inline void
dump_attrs(struct nlmsghdr *nlh)
{
const struct nlattr *attr;
int rem;
pr_debug("dump nlmsg\n");
nlmsg_for_each_attr(attr, nlh, sizeof(struct nfgenmsg), rem) {
pr_debug("type: %u, len %u\n", nla_type(attr), attr->nla_len);
}
}
static int
dump_init(struct netlink_callback *cb)
{
struct nlmsghdr *nlh = nlmsg_hdr(cb->skb);
int min_len = NLMSG_SPACE(sizeof(struct nfgenmsg));
struct nlattr *cda[IPSET_ATTR_CMD_MAX+1];
struct nlattr *attr = (void *)nlh + min_len;
u32 dump_type;
ip_set_id_t index;
nla_parse(cda, IPSET_ATTR_CMD_MAX,
attr, nlh->nlmsg_len - min_len, ip_set_setname_policy);
if (cda[IPSET_ATTR_SETNAME]) {
struct ip_set *set;
set = find_set_and_id(nla_data(cda[IPSET_ATTR_SETNAME]),
&index);
if (set == NULL)
return -ENOENT;
dump_type = DUMP_ONE;
cb->args[1] = index;
} else
dump_type = DUMP_ALL;
if (cda[IPSET_ATTR_FLAGS]) {
u32 f = ip_set_get_h32(cda[IPSET_ATTR_FLAGS]);
dump_type |= (f << 16);
}
cb->args[0] = dump_type;
return 0;
}
static int
ip_set_dump_start(struct sk_buff *skb, struct netlink_callback *cb)
{
ip_set_id_t index = IPSET_INVALID_ID, max;
struct ip_set *set = NULL;
struct nlmsghdr *nlh = NULL;
unsigned int flags = NETLINK_CB(cb->skb).portid ? NLM_F_MULTI : 0;
u32 dump_type, dump_flags;
int ret = 0;
if (!cb->args[0]) {
ret = dump_init(cb);
if (ret < 0) {
nlh = nlmsg_hdr(cb->skb);
if (nlh->nlmsg_flags & NLM_F_ACK)
netlink_ack(cb->skb, nlh, ret);
return ret;
}
}
if (cb->args[1] >= ip_set_max)
goto out;
dump_type = DUMP_TYPE(cb->args[0]);
dump_flags = DUMP_FLAGS(cb->args[0]);
max = dump_type == DUMP_ONE ? cb->args[1] + 1 : ip_set_max;
dump_last:
pr_debug("args[0]: %u %u args[1]: %ld\n",
dump_type, dump_flags, cb->args[1]);
for (; cb->args[1] < max; cb->args[1]++) {
index = (ip_set_id_t) cb->args[1];
set = nfnl_set(index);
if (set == NULL) {
if (dump_type == DUMP_ONE) {
ret = -ENOENT;
goto out;
}
continue;
}
if (dump_type != DUMP_ONE &&
((dump_type == DUMP_ALL) ==
!!(set->type->features & IPSET_DUMP_LAST)))
continue;
pr_debug("List set: %s\n", set->name);
if (!cb->args[2]) {
pr_debug("reference set\n");
__ip_set_get(set);
}
nlh = start_msg(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, flags,
IPSET_CMD_LIST);
if (!nlh) {
ret = -EMSGSIZE;
goto release_refcount;
}
if (nla_put_u8(skb, IPSET_ATTR_PROTOCOL, IPSET_PROTOCOL) ||
nla_put_string(skb, IPSET_ATTR_SETNAME, set->name))
goto nla_put_failure;
if (dump_flags & IPSET_FLAG_LIST_SETNAME)
goto next_set;
switch (cb->args[2]) {
case 0:
if (nla_put_string(skb, IPSET_ATTR_TYPENAME,
set->type->name) ||
nla_put_u8(skb, IPSET_ATTR_FAMILY,
set->family) ||
nla_put_u8(skb, IPSET_ATTR_REVISION,
set->revision))
goto nla_put_failure;
ret = set->variant->head(set, skb);
if (ret < 0)
goto release_refcount;
if (dump_flags & IPSET_FLAG_LIST_HEADER)
goto next_set;
default:
read_lock_bh(&set->lock);
ret = set->variant->list(set, skb, cb);
read_unlock_bh(&set->lock);
if (!cb->args[2])
goto next_set;
goto release_refcount;
}
}
if (dump_type == DUMP_ALL) {
dump_type = DUMP_LAST;
cb->args[0] = dump_type | (dump_flags << 16);
cb->args[1] = 0;
goto dump_last;
}
goto out;
nla_put_failure:
ret = -EFAULT;
next_set:
if (dump_type == DUMP_ONE)
cb->args[1] = IPSET_INVALID_ID;
else
cb->args[1]++;
release_refcount:
if (ret || !cb->args[2]) {
pr_debug("release set %s\n", nfnl_set(index)->name);
ip_set_put_byindex(index);
cb->args[2] = 0;
}
out:
if (nlh) {
nlmsg_end(skb, nlh);
pr_debug("nlmsg_len: %u\n", nlh->nlmsg_len);
dump_attrs(nlh);
}
return ret < 0 ? ret : skb->len;
}
static int
ip_set_dump(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
if (unlikely(protocol_failed(attr)))
return -IPSET_ERR_PROTOCOL;
{
struct netlink_dump_control c = {
.dump = ip_set_dump_start,
.done = ip_set_dump_done,
};
return netlink_dump_start(ctnl, skb, nlh, &c);
}
}
static int
call_ad(struct sock *ctnl, struct sk_buff *skb, struct ip_set *set,
struct nlattr *tb[], enum ipset_adt adt,
u32 flags, bool use_lineno)
{
int ret;
u32 lineno = 0;
bool eexist = flags & IPSET_FLAG_EXIST, retried = false;
do {
write_lock_bh(&set->lock);
ret = set->variant->uadt(set, tb, adt, &lineno, flags, retried);
write_unlock_bh(&set->lock);
retried = true;
} while (ret == -EAGAIN &&
set->variant->resize &&
(ret = set->variant->resize(set, retried)) == 0);
if (!ret || (ret == -IPSET_ERR_EXIST && eexist))
return 0;
if (lineno && use_lineno) {
struct nlmsghdr *rep, *nlh = nlmsg_hdr(skb);
struct sk_buff *skb2;
struct nlmsgerr *errmsg;
size_t payload = sizeof(*errmsg) + nlmsg_len(nlh);
int min_len = NLMSG_SPACE(sizeof(struct nfgenmsg));
struct nlattr *cda[IPSET_ATTR_CMD_MAX+1];
struct nlattr *cmdattr;
u32 *errline;
skb2 = nlmsg_new(payload, GFP_KERNEL);
if (skb2 == NULL)
return -ENOMEM;
rep = __nlmsg_put(skb2, NETLINK_CB(skb).portid,
nlh->nlmsg_seq, NLMSG_ERROR, payload, 0);
errmsg = nlmsg_data(rep);
errmsg->error = ret;
memcpy(&errmsg->msg, nlh, nlh->nlmsg_len);
cmdattr = (void *)&errmsg->msg + min_len;
nla_parse(cda, IPSET_ATTR_CMD_MAX,
cmdattr, nlh->nlmsg_len - min_len,
ip_set_adt_policy);
errline = nla_data(cda[IPSET_ATTR_LINENO]);
*errline = lineno;
netlink_unicast(ctnl, skb2, NETLINK_CB(skb).portid, MSG_DONTWAIT);
return -EINTR;
}
return ret;
}
static int
ip_set_uadd(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *set;
struct nlattr *tb[IPSET_ATTR_ADT_MAX+1] = {};
const struct nlattr *nla;
u32 flags = flag_exist(nlh);
bool use_lineno;
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL ||
!((attr[IPSET_ATTR_DATA] != NULL) ^
(attr[IPSET_ATTR_ADT] != NULL)) ||
(attr[IPSET_ATTR_DATA] != NULL &&
!flag_nested(attr[IPSET_ATTR_DATA])) ||
(attr[IPSET_ATTR_ADT] != NULL &&
(!flag_nested(attr[IPSET_ATTR_ADT]) ||
attr[IPSET_ATTR_LINENO] == NULL))))
return -IPSET_ERR_PROTOCOL;
set = find_set(nla_data(attr[IPSET_ATTR_SETNAME]));
if (set == NULL)
return -ENOENT;
use_lineno = !!attr[IPSET_ATTR_LINENO];
if (attr[IPSET_ATTR_DATA]) {
if (nla_parse_nested(tb, IPSET_ATTR_ADT_MAX,
attr[IPSET_ATTR_DATA],
set->type->adt_policy))
return -IPSET_ERR_PROTOCOL;
ret = call_ad(ctnl, skb, set, tb, IPSET_ADD, flags,
use_lineno);
} else {
int nla_rem;
nla_for_each_nested(nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset(tb, 0, sizeof(tb));
if (nla_type(nla) != IPSET_ATTR_DATA ||
!flag_nested(nla) ||
nla_parse_nested(tb, IPSET_ATTR_ADT_MAX, nla,
set->type->adt_policy))
return -IPSET_ERR_PROTOCOL;
ret = call_ad(ctnl, skb, set, tb, IPSET_ADD,
flags, use_lineno);
if (ret < 0)
return ret;
}
}
return ret;
}
static int
ip_set_udel(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *set;
struct nlattr *tb[IPSET_ATTR_ADT_MAX+1] = {};
const struct nlattr *nla;
u32 flags = flag_exist(nlh);
bool use_lineno;
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL ||
!((attr[IPSET_ATTR_DATA] != NULL) ^
(attr[IPSET_ATTR_ADT] != NULL)) ||
(attr[IPSET_ATTR_DATA] != NULL &&
!flag_nested(attr[IPSET_ATTR_DATA])) ||
(attr[IPSET_ATTR_ADT] != NULL &&
(!flag_nested(attr[IPSET_ATTR_ADT]) ||
attr[IPSET_ATTR_LINENO] == NULL))))
return -IPSET_ERR_PROTOCOL;
set = find_set(nla_data(attr[IPSET_ATTR_SETNAME]));
if (set == NULL)
return -ENOENT;
use_lineno = !!attr[IPSET_ATTR_LINENO];
if (attr[IPSET_ATTR_DATA]) {
if (nla_parse_nested(tb, IPSET_ATTR_ADT_MAX,
attr[IPSET_ATTR_DATA],
set->type->adt_policy))
return -IPSET_ERR_PROTOCOL;
ret = call_ad(ctnl, skb, set, tb, IPSET_DEL, flags,
use_lineno);
} else {
int nla_rem;
nla_for_each_nested(nla, attr[IPSET_ATTR_ADT], nla_rem) {
memset(tb, 0, sizeof(*tb));
if (nla_type(nla) != IPSET_ATTR_DATA ||
!flag_nested(nla) ||
nla_parse_nested(tb, IPSET_ATTR_ADT_MAX, nla,
set->type->adt_policy))
return -IPSET_ERR_PROTOCOL;
ret = call_ad(ctnl, skb, set, tb, IPSET_DEL,
flags, use_lineno);
if (ret < 0)
return ret;
}
}
return ret;
}
static int
ip_set_utest(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct ip_set *set;
struct nlattr *tb[IPSET_ATTR_ADT_MAX+1] = {};
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL ||
attr[IPSET_ATTR_DATA] == NULL ||
!flag_nested(attr[IPSET_ATTR_DATA])))
return -IPSET_ERR_PROTOCOL;
set = find_set(nla_data(attr[IPSET_ATTR_SETNAME]));
if (set == NULL)
return -ENOENT;
if (nla_parse_nested(tb, IPSET_ATTR_ADT_MAX, attr[IPSET_ATTR_DATA],
set->type->adt_policy))
return -IPSET_ERR_PROTOCOL;
read_lock_bh(&set->lock);
ret = set->variant->uadt(set, tb, IPSET_TEST, NULL, 0, 0);
read_unlock_bh(&set->lock);
if (ret == -EAGAIN)
ret = 1;
return (ret < 0 && ret != -ENOTEMPTY) ? ret :
ret > 0 ? 0 : -IPSET_ERR_EXIST;
}
static int
ip_set_header(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
const struct ip_set *set;
struct sk_buff *skb2;
struct nlmsghdr *nlh2;
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_SETNAME] == NULL))
return -IPSET_ERR_PROTOCOL;
set = find_set(nla_data(attr[IPSET_ATTR_SETNAME]));
if (set == NULL)
return -ENOENT;
skb2 = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (skb2 == NULL)
return -ENOMEM;
nlh2 = start_msg(skb2, NETLINK_CB(skb).portid, nlh->nlmsg_seq, 0,
IPSET_CMD_HEADER);
if (!nlh2)
goto nlmsg_failure;
if (nla_put_u8(skb2, IPSET_ATTR_PROTOCOL, IPSET_PROTOCOL) ||
nla_put_string(skb2, IPSET_ATTR_SETNAME, set->name) ||
nla_put_string(skb2, IPSET_ATTR_TYPENAME, set->type->name) ||
nla_put_u8(skb2, IPSET_ATTR_FAMILY, set->family) ||
nla_put_u8(skb2, IPSET_ATTR_REVISION, set->revision))
goto nla_put_failure;
nlmsg_end(skb2, nlh2);
ret = netlink_unicast(ctnl, skb2, NETLINK_CB(skb).portid, MSG_DONTWAIT);
if (ret < 0)
return ret;
return 0;
nla_put_failure:
nlmsg_cancel(skb2, nlh2);
nlmsg_failure:
kfree_skb(skb2);
return -EMSGSIZE;
}
static int
ip_set_type(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct sk_buff *skb2;
struct nlmsghdr *nlh2;
u8 family, min, max;
const char *typename;
int ret = 0;
if (unlikely(protocol_failed(attr) ||
attr[IPSET_ATTR_TYPENAME] == NULL ||
attr[IPSET_ATTR_FAMILY] == NULL))
return -IPSET_ERR_PROTOCOL;
family = nla_get_u8(attr[IPSET_ATTR_FAMILY]);
typename = nla_data(attr[IPSET_ATTR_TYPENAME]);
ret = find_set_type_minmax(typename, family, &min, &max);
if (ret)
return ret;
skb2 = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (skb2 == NULL)
return -ENOMEM;
nlh2 = start_msg(skb2, NETLINK_CB(skb).portid, nlh->nlmsg_seq, 0,
IPSET_CMD_TYPE);
if (!nlh2)
goto nlmsg_failure;
if (nla_put_u8(skb2, IPSET_ATTR_PROTOCOL, IPSET_PROTOCOL) ||
nla_put_string(skb2, IPSET_ATTR_TYPENAME, typename) ||
nla_put_u8(skb2, IPSET_ATTR_FAMILY, family) ||
nla_put_u8(skb2, IPSET_ATTR_REVISION, max) ||
nla_put_u8(skb2, IPSET_ATTR_REVISION_MIN, min))
goto nla_put_failure;
nlmsg_end(skb2, nlh2);
pr_debug("Send TYPE, nlmsg_len: %u\n", nlh2->nlmsg_len);
ret = netlink_unicast(ctnl, skb2, NETLINK_CB(skb).portid, MSG_DONTWAIT);
if (ret < 0)
return ret;
return 0;
nla_put_failure:
nlmsg_cancel(skb2, nlh2);
nlmsg_failure:
kfree_skb(skb2);
return -EMSGSIZE;
}
static int
ip_set_protocol(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const attr[])
{
struct sk_buff *skb2;
struct nlmsghdr *nlh2;
int ret = 0;
if (unlikely(attr[IPSET_ATTR_PROTOCOL] == NULL))
return -IPSET_ERR_PROTOCOL;
skb2 = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (skb2 == NULL)
return -ENOMEM;
nlh2 = start_msg(skb2, NETLINK_CB(skb).portid, nlh->nlmsg_seq, 0,
IPSET_CMD_PROTOCOL);
if (!nlh2)
goto nlmsg_failure;
if (nla_put_u8(skb2, IPSET_ATTR_PROTOCOL, IPSET_PROTOCOL))
goto nla_put_failure;
nlmsg_end(skb2, nlh2);
ret = netlink_unicast(ctnl, skb2, NETLINK_CB(skb).portid, MSG_DONTWAIT);
if (ret < 0)
return ret;
return 0;
nla_put_failure:
nlmsg_cancel(skb2, nlh2);
nlmsg_failure:
kfree_skb(skb2);
return -EMSGSIZE;
}
static int
ip_set_sockfn_get(struct sock *sk, int optval, void __user *user, int *len)
{
unsigned int *op;
void *data;
int copylen = *len, ret = 0;
if (!ns_capable(sock_net(sk)->user_ns, CAP_NET_ADMIN))
return -EPERM;
if (optval != SO_IP_SET)
return -EBADF;
if (*len < sizeof(unsigned int))
return -EINVAL;
data = vmalloc(*len);
if (!data)
return -ENOMEM;
if (copy_from_user(data, user, *len) != 0) {
ret = -EFAULT;
goto done;
}
op = (unsigned int *) data;
if (*op < IP_SET_OP_VERSION) {
struct ip_set_req_version *req_version = data;
if (req_version->version != IPSET_PROTOCOL) {
ret = -EPROTO;
goto done;
}
}
switch (*op) {
case IP_SET_OP_VERSION: {
struct ip_set_req_version *req_version = data;
if (*len != sizeof(struct ip_set_req_version)) {
ret = -EINVAL;
goto done;
}
req_version->version = IPSET_PROTOCOL;
ret = copy_to_user(user, req_version,
sizeof(struct ip_set_req_version));
goto done;
}
case IP_SET_OP_GET_BYNAME: {
struct ip_set_req_get_set *req_get = data;
ip_set_id_t id;
if (*len != sizeof(struct ip_set_req_get_set)) {
ret = -EINVAL;
goto done;
}
req_get->set.name[IPSET_MAXNAMELEN - 1] = '\0';
nfnl_lock(NFNL_SUBSYS_IPSET);
find_set_and_id(req_get->set.name, &id);
req_get->set.index = id;
nfnl_unlock(NFNL_SUBSYS_IPSET);
goto copy;
}
case IP_SET_OP_GET_BYINDEX: {
struct ip_set_req_get_set *req_get = data;
struct ip_set *set;
if (*len != sizeof(struct ip_set_req_get_set) ||
req_get->set.index >= ip_set_max) {
ret = -EINVAL;
goto done;
}
nfnl_lock(NFNL_SUBSYS_IPSET);
set = nfnl_set(req_get->set.index);
strncpy(req_get->set.name, set ? set->name : "",
IPSET_MAXNAMELEN);
nfnl_unlock(NFNL_SUBSYS_IPSET);
goto copy;
}
default:
ret = -EBADMSG;
goto done;
}
copy:
ret = copy_to_user(user, data, copylen);
done:
vfree(data);
if (ret > 0)
ret = 0;
return ret;
}
static int __init
ip_set_init(void)
{
struct ip_set **list;
int ret;
if (max_sets)
ip_set_max = max_sets;
if (ip_set_max >= IPSET_INVALID_ID)
ip_set_max = IPSET_INVALID_ID - 1;
list = kzalloc(sizeof(struct ip_set *) * ip_set_max, GFP_KERNEL);
if (!list)
return -ENOMEM;
rcu_assign_pointer(ip_set_list, list);
ret = nfnetlink_subsys_register(&ip_set_netlink_subsys);
if (ret != 0) {
pr_err("ip_set: cannot register with nfnetlink.\n");
kfree(list);
return ret;
}
ret = nf_register_sockopt(&so_set);
if (ret != 0) {
pr_err("SO_SET registry failed: %d\n", ret);
nfnetlink_subsys_unregister(&ip_set_netlink_subsys);
kfree(list);
return ret;
}
pr_notice("ip_set: protocol %u\n", IPSET_PROTOCOL);
return 0;
}
static void __exit
ip_set_fini(void)
{
struct ip_set **list = rcu_dereference_protected(ip_set_list, 1);
nf_unregister_sockopt(&so_set);
nfnetlink_subsys_unregister(&ip_set_netlink_subsys);
kfree(list);
pr_debug("these are the famous last words\n");
}
