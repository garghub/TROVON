static struct net *devlink_net(const struct devlink *devlink)
{
return read_pnet(&devlink->_net);
}
static void devlink_net_set(struct devlink *devlink, struct net *net)
{
write_pnet(&devlink->_net, net);
}
static struct devlink *devlink_get_from_attrs(struct net *net,
struct nlattr **attrs)
{
struct devlink *devlink;
char *busname;
char *devname;
if (!attrs[DEVLINK_ATTR_BUS_NAME] || !attrs[DEVLINK_ATTR_DEV_NAME])
return ERR_PTR(-EINVAL);
busname = nla_data(attrs[DEVLINK_ATTR_BUS_NAME]);
devname = nla_data(attrs[DEVLINK_ATTR_DEV_NAME]);
list_for_each_entry(devlink, &devlink_list, list) {
if (strcmp(devlink->dev->bus->name, busname) == 0 &&
strcmp(dev_name(devlink->dev), devname) == 0 &&
net_eq(devlink_net(devlink), net))
return devlink;
}
return ERR_PTR(-ENODEV);
}
static struct devlink *devlink_get_from_info(struct genl_info *info)
{
return devlink_get_from_attrs(genl_info_net(info), info->attrs);
}
static struct devlink_port *devlink_port_get_by_index(struct devlink *devlink,
int port_index)
{
struct devlink_port *devlink_port;
list_for_each_entry(devlink_port, &devlink->port_list, list) {
if (devlink_port->index == port_index)
return devlink_port;
}
return NULL;
}
static bool devlink_port_index_exists(struct devlink *devlink, int port_index)
{
return devlink_port_get_by_index(devlink, port_index);
}
static struct devlink_port *devlink_port_get_from_attrs(struct devlink *devlink,
struct nlattr **attrs)
{
if (attrs[DEVLINK_ATTR_PORT_INDEX]) {
u32 port_index = nla_get_u32(attrs[DEVLINK_ATTR_PORT_INDEX]);
struct devlink_port *devlink_port;
devlink_port = devlink_port_get_by_index(devlink, port_index);
if (!devlink_port)
return ERR_PTR(-ENODEV);
return devlink_port;
}
return ERR_PTR(-EINVAL);
}
static struct devlink_port *devlink_port_get_from_info(struct devlink *devlink,
struct genl_info *info)
{
return devlink_port_get_from_attrs(devlink, info->attrs);
}
static u16 devlink_sb_pool_count(struct devlink_sb *devlink_sb)
{
return devlink_sb->ingress_pools_count + devlink_sb->egress_pools_count;
}
static struct devlink_sb *devlink_sb_get_by_index(struct devlink *devlink,
unsigned int sb_index)
{
struct devlink_sb *devlink_sb;
list_for_each_entry(devlink_sb, &devlink->sb_list, list) {
if (devlink_sb->index == sb_index)
return devlink_sb;
}
return NULL;
}
static bool devlink_sb_index_exists(struct devlink *devlink,
unsigned int sb_index)
{
return devlink_sb_get_by_index(devlink, sb_index);
}
static struct devlink_sb *devlink_sb_get_from_attrs(struct devlink *devlink,
struct nlattr **attrs)
{
if (attrs[DEVLINK_ATTR_SB_INDEX]) {
u32 sb_index = nla_get_u32(attrs[DEVLINK_ATTR_SB_INDEX]);
struct devlink_sb *devlink_sb;
devlink_sb = devlink_sb_get_by_index(devlink, sb_index);
if (!devlink_sb)
return ERR_PTR(-ENODEV);
return devlink_sb;
}
return ERR_PTR(-EINVAL);
}
static struct devlink_sb *devlink_sb_get_from_info(struct devlink *devlink,
struct genl_info *info)
{
return devlink_sb_get_from_attrs(devlink, info->attrs);
}
static int devlink_sb_pool_index_get_from_attrs(struct devlink_sb *devlink_sb,
struct nlattr **attrs,
u16 *p_pool_index)
{
u16 val;
if (!attrs[DEVLINK_ATTR_SB_POOL_INDEX])
return -EINVAL;
val = nla_get_u16(attrs[DEVLINK_ATTR_SB_POOL_INDEX]);
if (val >= devlink_sb_pool_count(devlink_sb))
return -EINVAL;
*p_pool_index = val;
return 0;
}
static int devlink_sb_pool_index_get_from_info(struct devlink_sb *devlink_sb,
struct genl_info *info,
u16 *p_pool_index)
{
return devlink_sb_pool_index_get_from_attrs(devlink_sb, info->attrs,
p_pool_index);
}
static int
devlink_sb_pool_type_get_from_attrs(struct nlattr **attrs,
enum devlink_sb_pool_type *p_pool_type)
{
u8 val;
if (!attrs[DEVLINK_ATTR_SB_POOL_TYPE])
return -EINVAL;
val = nla_get_u8(attrs[DEVLINK_ATTR_SB_POOL_TYPE]);
if (val != DEVLINK_SB_POOL_TYPE_INGRESS &&
val != DEVLINK_SB_POOL_TYPE_EGRESS)
return -EINVAL;
*p_pool_type = val;
return 0;
}
static int
devlink_sb_pool_type_get_from_info(struct genl_info *info,
enum devlink_sb_pool_type *p_pool_type)
{
return devlink_sb_pool_type_get_from_attrs(info->attrs, p_pool_type);
}
static int
devlink_sb_th_type_get_from_attrs(struct nlattr **attrs,
enum devlink_sb_threshold_type *p_th_type)
{
u8 val;
if (!attrs[DEVLINK_ATTR_SB_POOL_THRESHOLD_TYPE])
return -EINVAL;
val = nla_get_u8(attrs[DEVLINK_ATTR_SB_POOL_THRESHOLD_TYPE]);
if (val != DEVLINK_SB_THRESHOLD_TYPE_STATIC &&
val != DEVLINK_SB_THRESHOLD_TYPE_DYNAMIC)
return -EINVAL;
*p_th_type = val;
return 0;
}
static int
devlink_sb_th_type_get_from_info(struct genl_info *info,
enum devlink_sb_threshold_type *p_th_type)
{
return devlink_sb_th_type_get_from_attrs(info->attrs, p_th_type);
}
static int
devlink_sb_tc_index_get_from_attrs(struct devlink_sb *devlink_sb,
struct nlattr **attrs,
enum devlink_sb_pool_type pool_type,
u16 *p_tc_index)
{
u16 val;
if (!attrs[DEVLINK_ATTR_SB_TC_INDEX])
return -EINVAL;
val = nla_get_u16(attrs[DEVLINK_ATTR_SB_TC_INDEX]);
if (pool_type == DEVLINK_SB_POOL_TYPE_INGRESS &&
val >= devlink_sb->ingress_tc_count)
return -EINVAL;
if (pool_type == DEVLINK_SB_POOL_TYPE_EGRESS &&
val >= devlink_sb->egress_tc_count)
return -EINVAL;
*p_tc_index = val;
return 0;
}
static int
devlink_sb_tc_index_get_from_info(struct devlink_sb *devlink_sb,
struct genl_info *info,
enum devlink_sb_pool_type pool_type,
u16 *p_tc_index)
{
return devlink_sb_tc_index_get_from_attrs(devlink_sb, info->attrs,
pool_type, p_tc_index);
}
static int devlink_nl_pre_doit(const struct genl_ops *ops,
struct sk_buff *skb, struct genl_info *info)
{
struct devlink *devlink;
mutex_lock(&devlink_mutex);
devlink = devlink_get_from_info(info);
if (IS_ERR(devlink)) {
mutex_unlock(&devlink_mutex);
return PTR_ERR(devlink);
}
if (ops->internal_flags & DEVLINK_NL_FLAG_NEED_DEVLINK) {
info->user_ptr[0] = devlink;
} else if (ops->internal_flags & DEVLINK_NL_FLAG_NEED_PORT) {
struct devlink_port *devlink_port;
mutex_lock(&devlink_port_mutex);
devlink_port = devlink_port_get_from_info(devlink, info);
if (IS_ERR(devlink_port)) {
mutex_unlock(&devlink_port_mutex);
mutex_unlock(&devlink_mutex);
return PTR_ERR(devlink_port);
}
info->user_ptr[0] = devlink_port;
}
if (ops->internal_flags & DEVLINK_NL_FLAG_LOCK_PORTS) {
mutex_lock(&devlink_port_mutex);
}
if (ops->internal_flags & DEVLINK_NL_FLAG_NEED_SB) {
struct devlink_sb *devlink_sb;
devlink_sb = devlink_sb_get_from_info(devlink, info);
if (IS_ERR(devlink_sb)) {
if (ops->internal_flags & DEVLINK_NL_FLAG_NEED_PORT)
mutex_unlock(&devlink_port_mutex);
mutex_unlock(&devlink_mutex);
return PTR_ERR(devlink_sb);
}
info->user_ptr[1] = devlink_sb;
}
return 0;
}
static void devlink_nl_post_doit(const struct genl_ops *ops,
struct sk_buff *skb, struct genl_info *info)
{
if (ops->internal_flags & DEVLINK_NL_FLAG_NEED_PORT ||
ops->internal_flags & DEVLINK_NL_FLAG_LOCK_PORTS)
mutex_unlock(&devlink_port_mutex);
mutex_unlock(&devlink_mutex);
}
static int devlink_nl_put_handle(struct sk_buff *msg, struct devlink *devlink)
{
if (nla_put_string(msg, DEVLINK_ATTR_BUS_NAME, devlink->dev->bus->name))
return -EMSGSIZE;
if (nla_put_string(msg, DEVLINK_ATTR_DEV_NAME, dev_name(devlink->dev)))
return -EMSGSIZE;
return 0;
}
static int devlink_nl_fill(struct sk_buff *msg, struct devlink *devlink,
enum devlink_command cmd, u32 portid,
u32 seq, int flags)
{
void *hdr;
hdr = genlmsg_put(msg, portid, seq, &devlink_nl_family, flags, cmd);
if (!hdr)
return -EMSGSIZE;
if (devlink_nl_put_handle(msg, devlink))
goto nla_put_failure;
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static void devlink_notify(struct devlink *devlink, enum devlink_command cmd)
{
struct sk_buff *msg;
int err;
WARN_ON(cmd != DEVLINK_CMD_NEW && cmd != DEVLINK_CMD_DEL);
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return;
err = devlink_nl_fill(msg, devlink, cmd, 0, 0, 0);
if (err) {
nlmsg_free(msg);
return;
}
genlmsg_multicast_netns(&devlink_nl_family, devlink_net(devlink),
msg, 0, DEVLINK_MCGRP_CONFIG, GFP_KERNEL);
}
static int devlink_nl_port_fill(struct sk_buff *msg, struct devlink *devlink,
struct devlink_port *devlink_port,
enum devlink_command cmd, u32 portid,
u32 seq, int flags)
{
void *hdr;
hdr = genlmsg_put(msg, portid, seq, &devlink_nl_family, flags, cmd);
if (!hdr)
return -EMSGSIZE;
if (devlink_nl_put_handle(msg, devlink))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_PORT_INDEX, devlink_port->index))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_PORT_TYPE, devlink_port->type))
goto nla_put_failure;
if (devlink_port->desired_type != DEVLINK_PORT_TYPE_NOTSET &&
nla_put_u16(msg, DEVLINK_ATTR_PORT_DESIRED_TYPE,
devlink_port->desired_type))
goto nla_put_failure;
if (devlink_port->type == DEVLINK_PORT_TYPE_ETH) {
struct net_device *netdev = devlink_port->type_dev;
if (netdev &&
(nla_put_u32(msg, DEVLINK_ATTR_PORT_NETDEV_IFINDEX,
netdev->ifindex) ||
nla_put_string(msg, DEVLINK_ATTR_PORT_NETDEV_NAME,
netdev->name)))
goto nla_put_failure;
}
if (devlink_port->type == DEVLINK_PORT_TYPE_IB) {
struct ib_device *ibdev = devlink_port->type_dev;
if (ibdev &&
nla_put_string(msg, DEVLINK_ATTR_PORT_IBDEV_NAME,
ibdev->name))
goto nla_put_failure;
}
if (devlink_port->split &&
nla_put_u32(msg, DEVLINK_ATTR_PORT_SPLIT_GROUP,
devlink_port->split_group))
goto nla_put_failure;
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static void devlink_port_notify(struct devlink_port *devlink_port,
enum devlink_command cmd)
{
struct devlink *devlink = devlink_port->devlink;
struct sk_buff *msg;
int err;
if (!devlink_port->registered)
return;
WARN_ON(cmd != DEVLINK_CMD_PORT_NEW && cmd != DEVLINK_CMD_PORT_DEL);
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return;
err = devlink_nl_port_fill(msg, devlink, devlink_port, cmd, 0, 0, 0);
if (err) {
nlmsg_free(msg);
return;
}
genlmsg_multicast_netns(&devlink_nl_family, devlink_net(devlink),
msg, 0, DEVLINK_MCGRP_CONFIG, GFP_KERNEL);
}
static int devlink_nl_cmd_get_doit(struct sk_buff *skb, struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
struct sk_buff *msg;
int err;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
err = devlink_nl_fill(msg, devlink, DEVLINK_CMD_NEW,
info->snd_portid, info->snd_seq, 0);
if (err) {
nlmsg_free(msg);
return err;
}
return genlmsg_reply(msg, info);
}
static int devlink_nl_cmd_get_dumpit(struct sk_buff *msg,
struct netlink_callback *cb)
{
struct devlink *devlink;
int start = cb->args[0];
int idx = 0;
int err;
mutex_lock(&devlink_mutex);
list_for_each_entry(devlink, &devlink_list, list) {
if (!net_eq(devlink_net(devlink), sock_net(msg->sk)))
continue;
if (idx < start) {
idx++;
continue;
}
err = devlink_nl_fill(msg, devlink, DEVLINK_CMD_NEW,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI);
if (err)
goto out;
idx++;
}
out:
mutex_unlock(&devlink_mutex);
cb->args[0] = idx;
return msg->len;
}
static int devlink_nl_cmd_port_get_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink_port *devlink_port = info->user_ptr[0];
struct devlink *devlink = devlink_port->devlink;
struct sk_buff *msg;
int err;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
err = devlink_nl_port_fill(msg, devlink, devlink_port,
DEVLINK_CMD_PORT_NEW,
info->snd_portid, info->snd_seq, 0);
if (err) {
nlmsg_free(msg);
return err;
}
return genlmsg_reply(msg, info);
}
static int devlink_nl_cmd_port_get_dumpit(struct sk_buff *msg,
struct netlink_callback *cb)
{
struct devlink *devlink;
struct devlink_port *devlink_port;
int start = cb->args[0];
int idx = 0;
int err;
mutex_lock(&devlink_mutex);
mutex_lock(&devlink_port_mutex);
list_for_each_entry(devlink, &devlink_list, list) {
if (!net_eq(devlink_net(devlink), sock_net(msg->sk)))
continue;
list_for_each_entry(devlink_port, &devlink->port_list, list) {
if (idx < start) {
idx++;
continue;
}
err = devlink_nl_port_fill(msg, devlink, devlink_port,
DEVLINK_CMD_NEW,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
NLM_F_MULTI);
if (err)
goto out;
idx++;
}
}
out:
mutex_unlock(&devlink_port_mutex);
mutex_unlock(&devlink_mutex);
cb->args[0] = idx;
return msg->len;
}
static int devlink_port_type_set(struct devlink *devlink,
struct devlink_port *devlink_port,
enum devlink_port_type port_type)
{
int err;
if (devlink->ops && devlink->ops->port_type_set) {
if (port_type == DEVLINK_PORT_TYPE_NOTSET)
return -EINVAL;
err = devlink->ops->port_type_set(devlink_port, port_type);
if (err)
return err;
devlink_port->desired_type = port_type;
devlink_port_notify(devlink_port, DEVLINK_CMD_PORT_NEW);
return 0;
}
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_port_set_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink_port *devlink_port = info->user_ptr[0];
struct devlink *devlink = devlink_port->devlink;
int err;
if (info->attrs[DEVLINK_ATTR_PORT_TYPE]) {
enum devlink_port_type port_type;
port_type = nla_get_u16(info->attrs[DEVLINK_ATTR_PORT_TYPE]);
err = devlink_port_type_set(devlink, devlink_port, port_type);
if (err)
return err;
}
return 0;
}
static int devlink_port_split(struct devlink *devlink,
u32 port_index, u32 count)
{
if (devlink->ops && devlink->ops->port_split)
return devlink->ops->port_split(devlink, port_index, count);
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_port_split_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
u32 port_index;
u32 count;
if (!info->attrs[DEVLINK_ATTR_PORT_INDEX] ||
!info->attrs[DEVLINK_ATTR_PORT_SPLIT_COUNT])
return -EINVAL;
port_index = nla_get_u32(info->attrs[DEVLINK_ATTR_PORT_INDEX]);
count = nla_get_u32(info->attrs[DEVLINK_ATTR_PORT_SPLIT_COUNT]);
return devlink_port_split(devlink, port_index, count);
}
static int devlink_port_unsplit(struct devlink *devlink, u32 port_index)
{
if (devlink->ops && devlink->ops->port_unsplit)
return devlink->ops->port_unsplit(devlink, port_index);
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_port_unsplit_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
u32 port_index;
if (!info->attrs[DEVLINK_ATTR_PORT_INDEX])
return -EINVAL;
port_index = nla_get_u32(info->attrs[DEVLINK_ATTR_PORT_INDEX]);
return devlink_port_unsplit(devlink, port_index);
}
static int devlink_nl_sb_fill(struct sk_buff *msg, struct devlink *devlink,
struct devlink_sb *devlink_sb,
enum devlink_command cmd, u32 portid,
u32 seq, int flags)
{
void *hdr;
hdr = genlmsg_put(msg, portid, seq, &devlink_nl_family, flags, cmd);
if (!hdr)
return -EMSGSIZE;
if (devlink_nl_put_handle(msg, devlink))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_INDEX, devlink_sb->index))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_SIZE, devlink_sb->size))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_INGRESS_POOL_COUNT,
devlink_sb->ingress_pools_count))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_EGRESS_POOL_COUNT,
devlink_sb->egress_pools_count))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_INGRESS_TC_COUNT,
devlink_sb->ingress_tc_count))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_EGRESS_TC_COUNT,
devlink_sb->egress_tc_count))
goto nla_put_failure;
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static int devlink_nl_cmd_sb_get_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
struct sk_buff *msg;
int err;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
err = devlink_nl_sb_fill(msg, devlink, devlink_sb,
DEVLINK_CMD_SB_NEW,
info->snd_portid, info->snd_seq, 0);
if (err) {
nlmsg_free(msg);
return err;
}
return genlmsg_reply(msg, info);
}
static int devlink_nl_cmd_sb_get_dumpit(struct sk_buff *msg,
struct netlink_callback *cb)
{
struct devlink *devlink;
struct devlink_sb *devlink_sb;
int start = cb->args[0];
int idx = 0;
int err;
mutex_lock(&devlink_mutex);
list_for_each_entry(devlink, &devlink_list, list) {
if (!net_eq(devlink_net(devlink), sock_net(msg->sk)))
continue;
list_for_each_entry(devlink_sb, &devlink->sb_list, list) {
if (idx < start) {
idx++;
continue;
}
err = devlink_nl_sb_fill(msg, devlink, devlink_sb,
DEVLINK_CMD_SB_NEW,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
NLM_F_MULTI);
if (err)
goto out;
idx++;
}
}
out:
mutex_unlock(&devlink_mutex);
cb->args[0] = idx;
return msg->len;
}
static int devlink_nl_sb_pool_fill(struct sk_buff *msg, struct devlink *devlink,
struct devlink_sb *devlink_sb,
u16 pool_index, enum devlink_command cmd,
u32 portid, u32 seq, int flags)
{
struct devlink_sb_pool_info pool_info;
void *hdr;
int err;
err = devlink->ops->sb_pool_get(devlink, devlink_sb->index,
pool_index, &pool_info);
if (err)
return err;
hdr = genlmsg_put(msg, portid, seq, &devlink_nl_family, flags, cmd);
if (!hdr)
return -EMSGSIZE;
if (devlink_nl_put_handle(msg, devlink))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_INDEX, devlink_sb->index))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_POOL_INDEX, pool_index))
goto nla_put_failure;
if (nla_put_u8(msg, DEVLINK_ATTR_SB_POOL_TYPE, pool_info.pool_type))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_POOL_SIZE, pool_info.size))
goto nla_put_failure;
if (nla_put_u8(msg, DEVLINK_ATTR_SB_POOL_THRESHOLD_TYPE,
pool_info.threshold_type))
goto nla_put_failure;
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static int devlink_nl_cmd_sb_pool_get_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
struct sk_buff *msg;
u16 pool_index;
int err;
err = devlink_sb_pool_index_get_from_info(devlink_sb, info,
&pool_index);
if (err)
return err;
if (!devlink->ops || !devlink->ops->sb_pool_get)
return -EOPNOTSUPP;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
err = devlink_nl_sb_pool_fill(msg, devlink, devlink_sb, pool_index,
DEVLINK_CMD_SB_POOL_NEW,
info->snd_portid, info->snd_seq, 0);
if (err) {
nlmsg_free(msg);
return err;
}
return genlmsg_reply(msg, info);
}
static int __sb_pool_get_dumpit(struct sk_buff *msg, int start, int *p_idx,
struct devlink *devlink,
struct devlink_sb *devlink_sb,
u32 portid, u32 seq)
{
u16 pool_count = devlink_sb_pool_count(devlink_sb);
u16 pool_index;
int err;
for (pool_index = 0; pool_index < pool_count; pool_index++) {
if (*p_idx < start) {
(*p_idx)++;
continue;
}
err = devlink_nl_sb_pool_fill(msg, devlink,
devlink_sb,
pool_index,
DEVLINK_CMD_SB_POOL_NEW,
portid, seq, NLM_F_MULTI);
if (err)
return err;
(*p_idx)++;
}
return 0;
}
static int devlink_nl_cmd_sb_pool_get_dumpit(struct sk_buff *msg,
struct netlink_callback *cb)
{
struct devlink *devlink;
struct devlink_sb *devlink_sb;
int start = cb->args[0];
int idx = 0;
int err;
mutex_lock(&devlink_mutex);
list_for_each_entry(devlink, &devlink_list, list) {
if (!net_eq(devlink_net(devlink), sock_net(msg->sk)) ||
!devlink->ops || !devlink->ops->sb_pool_get)
continue;
list_for_each_entry(devlink_sb, &devlink->sb_list, list) {
err = __sb_pool_get_dumpit(msg, start, &idx, devlink,
devlink_sb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq);
if (err && err != -EOPNOTSUPP)
goto out;
}
}
out:
mutex_unlock(&devlink_mutex);
cb->args[0] = idx;
return msg->len;
}
static int devlink_sb_pool_set(struct devlink *devlink, unsigned int sb_index,
u16 pool_index, u32 size,
enum devlink_sb_threshold_type threshold_type)
{
const struct devlink_ops *ops = devlink->ops;
if (ops && ops->sb_pool_set)
return ops->sb_pool_set(devlink, sb_index, pool_index,
size, threshold_type);
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_sb_pool_set_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
enum devlink_sb_threshold_type threshold_type;
u16 pool_index;
u32 size;
int err;
err = devlink_sb_pool_index_get_from_info(devlink_sb, info,
&pool_index);
if (err)
return err;
err = devlink_sb_th_type_get_from_info(info, &threshold_type);
if (err)
return err;
if (!info->attrs[DEVLINK_ATTR_SB_POOL_SIZE])
return -EINVAL;
size = nla_get_u32(info->attrs[DEVLINK_ATTR_SB_POOL_SIZE]);
return devlink_sb_pool_set(devlink, devlink_sb->index,
pool_index, size, threshold_type);
}
static int devlink_nl_sb_port_pool_fill(struct sk_buff *msg,
struct devlink *devlink,
struct devlink_port *devlink_port,
struct devlink_sb *devlink_sb,
u16 pool_index,
enum devlink_command cmd,
u32 portid, u32 seq, int flags)
{
const struct devlink_ops *ops = devlink->ops;
u32 threshold;
void *hdr;
int err;
err = ops->sb_port_pool_get(devlink_port, devlink_sb->index,
pool_index, &threshold);
if (err)
return err;
hdr = genlmsg_put(msg, portid, seq, &devlink_nl_family, flags, cmd);
if (!hdr)
return -EMSGSIZE;
if (devlink_nl_put_handle(msg, devlink))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_PORT_INDEX, devlink_port->index))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_INDEX, devlink_sb->index))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_POOL_INDEX, pool_index))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_THRESHOLD, threshold))
goto nla_put_failure;
if (ops->sb_occ_port_pool_get) {
u32 cur;
u32 max;
err = ops->sb_occ_port_pool_get(devlink_port, devlink_sb->index,
pool_index, &cur, &max);
if (err && err != -EOPNOTSUPP)
return err;
if (!err) {
if (nla_put_u32(msg, DEVLINK_ATTR_SB_OCC_CUR, cur))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_OCC_MAX, max))
goto nla_put_failure;
}
}
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static int devlink_nl_cmd_sb_port_pool_get_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink_port *devlink_port = info->user_ptr[0];
struct devlink *devlink = devlink_port->devlink;
struct devlink_sb *devlink_sb = info->user_ptr[1];
struct sk_buff *msg;
u16 pool_index;
int err;
err = devlink_sb_pool_index_get_from_info(devlink_sb, info,
&pool_index);
if (err)
return err;
if (!devlink->ops || !devlink->ops->sb_port_pool_get)
return -EOPNOTSUPP;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
err = devlink_nl_sb_port_pool_fill(msg, devlink, devlink_port,
devlink_sb, pool_index,
DEVLINK_CMD_SB_PORT_POOL_NEW,
info->snd_portid, info->snd_seq, 0);
if (err) {
nlmsg_free(msg);
return err;
}
return genlmsg_reply(msg, info);
}
static int __sb_port_pool_get_dumpit(struct sk_buff *msg, int start, int *p_idx,
struct devlink *devlink,
struct devlink_sb *devlink_sb,
u32 portid, u32 seq)
{
struct devlink_port *devlink_port;
u16 pool_count = devlink_sb_pool_count(devlink_sb);
u16 pool_index;
int err;
list_for_each_entry(devlink_port, &devlink->port_list, list) {
for (pool_index = 0; pool_index < pool_count; pool_index++) {
if (*p_idx < start) {
(*p_idx)++;
continue;
}
err = devlink_nl_sb_port_pool_fill(msg, devlink,
devlink_port,
devlink_sb,
pool_index,
DEVLINK_CMD_SB_PORT_POOL_NEW,
portid, seq,
NLM_F_MULTI);
if (err)
return err;
(*p_idx)++;
}
}
return 0;
}
static int devlink_nl_cmd_sb_port_pool_get_dumpit(struct sk_buff *msg,
struct netlink_callback *cb)
{
struct devlink *devlink;
struct devlink_sb *devlink_sb;
int start = cb->args[0];
int idx = 0;
int err;
mutex_lock(&devlink_mutex);
mutex_lock(&devlink_port_mutex);
list_for_each_entry(devlink, &devlink_list, list) {
if (!net_eq(devlink_net(devlink), sock_net(msg->sk)) ||
!devlink->ops || !devlink->ops->sb_port_pool_get)
continue;
list_for_each_entry(devlink_sb, &devlink->sb_list, list) {
err = __sb_port_pool_get_dumpit(msg, start, &idx,
devlink, devlink_sb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq);
if (err && err != -EOPNOTSUPP)
goto out;
}
}
out:
mutex_unlock(&devlink_port_mutex);
mutex_unlock(&devlink_mutex);
cb->args[0] = idx;
return msg->len;
}
static int devlink_sb_port_pool_set(struct devlink_port *devlink_port,
unsigned int sb_index, u16 pool_index,
u32 threshold)
{
const struct devlink_ops *ops = devlink_port->devlink->ops;
if (ops && ops->sb_port_pool_set)
return ops->sb_port_pool_set(devlink_port, sb_index,
pool_index, threshold);
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_sb_port_pool_set_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink_port *devlink_port = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
u16 pool_index;
u32 threshold;
int err;
err = devlink_sb_pool_index_get_from_info(devlink_sb, info,
&pool_index);
if (err)
return err;
if (!info->attrs[DEVLINK_ATTR_SB_THRESHOLD])
return -EINVAL;
threshold = nla_get_u32(info->attrs[DEVLINK_ATTR_SB_THRESHOLD]);
return devlink_sb_port_pool_set(devlink_port, devlink_sb->index,
pool_index, threshold);
}
static int
devlink_nl_sb_tc_pool_bind_fill(struct sk_buff *msg, struct devlink *devlink,
struct devlink_port *devlink_port,
struct devlink_sb *devlink_sb, u16 tc_index,
enum devlink_sb_pool_type pool_type,
enum devlink_command cmd,
u32 portid, u32 seq, int flags)
{
const struct devlink_ops *ops = devlink->ops;
u16 pool_index;
u32 threshold;
void *hdr;
int err;
err = ops->sb_tc_pool_bind_get(devlink_port, devlink_sb->index,
tc_index, pool_type,
&pool_index, &threshold);
if (err)
return err;
hdr = genlmsg_put(msg, portid, seq, &devlink_nl_family, flags, cmd);
if (!hdr)
return -EMSGSIZE;
if (devlink_nl_put_handle(msg, devlink))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_PORT_INDEX, devlink_port->index))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_INDEX, devlink_sb->index))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_TC_INDEX, tc_index))
goto nla_put_failure;
if (nla_put_u8(msg, DEVLINK_ATTR_SB_POOL_TYPE, pool_type))
goto nla_put_failure;
if (nla_put_u16(msg, DEVLINK_ATTR_SB_POOL_INDEX, pool_index))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_THRESHOLD, threshold))
goto nla_put_failure;
if (ops->sb_occ_tc_port_bind_get) {
u32 cur;
u32 max;
err = ops->sb_occ_tc_port_bind_get(devlink_port,
devlink_sb->index,
tc_index, pool_type,
&cur, &max);
if (err && err != -EOPNOTSUPP)
return err;
if (!err) {
if (nla_put_u32(msg, DEVLINK_ATTR_SB_OCC_CUR, cur))
goto nla_put_failure;
if (nla_put_u32(msg, DEVLINK_ATTR_SB_OCC_MAX, max))
goto nla_put_failure;
}
}
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static int devlink_nl_cmd_sb_tc_pool_bind_get_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink_port *devlink_port = info->user_ptr[0];
struct devlink *devlink = devlink_port->devlink;
struct devlink_sb *devlink_sb = info->user_ptr[1];
struct sk_buff *msg;
enum devlink_sb_pool_type pool_type;
u16 tc_index;
int err;
err = devlink_sb_pool_type_get_from_info(info, &pool_type);
if (err)
return err;
err = devlink_sb_tc_index_get_from_info(devlink_sb, info,
pool_type, &tc_index);
if (err)
return err;
if (!devlink->ops || !devlink->ops->sb_tc_pool_bind_get)
return -EOPNOTSUPP;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
err = devlink_nl_sb_tc_pool_bind_fill(msg, devlink, devlink_port,
devlink_sb, tc_index, pool_type,
DEVLINK_CMD_SB_TC_POOL_BIND_NEW,
info->snd_portid,
info->snd_seq, 0);
if (err) {
nlmsg_free(msg);
return err;
}
return genlmsg_reply(msg, info);
}
static int __sb_tc_pool_bind_get_dumpit(struct sk_buff *msg,
int start, int *p_idx,
struct devlink *devlink,
struct devlink_sb *devlink_sb,
u32 portid, u32 seq)
{
struct devlink_port *devlink_port;
u16 tc_index;
int err;
list_for_each_entry(devlink_port, &devlink->port_list, list) {
for (tc_index = 0;
tc_index < devlink_sb->ingress_tc_count; tc_index++) {
if (*p_idx < start) {
(*p_idx)++;
continue;
}
err = devlink_nl_sb_tc_pool_bind_fill(msg, devlink,
devlink_port,
devlink_sb,
tc_index,
DEVLINK_SB_POOL_TYPE_INGRESS,
DEVLINK_CMD_SB_TC_POOL_BIND_NEW,
portid, seq,
NLM_F_MULTI);
if (err)
return err;
(*p_idx)++;
}
for (tc_index = 0;
tc_index < devlink_sb->egress_tc_count; tc_index++) {
if (*p_idx < start) {
(*p_idx)++;
continue;
}
err = devlink_nl_sb_tc_pool_bind_fill(msg, devlink,
devlink_port,
devlink_sb,
tc_index,
DEVLINK_SB_POOL_TYPE_EGRESS,
DEVLINK_CMD_SB_TC_POOL_BIND_NEW,
portid, seq,
NLM_F_MULTI);
if (err)
return err;
(*p_idx)++;
}
}
return 0;
}
static int
devlink_nl_cmd_sb_tc_pool_bind_get_dumpit(struct sk_buff *msg,
struct netlink_callback *cb)
{
struct devlink *devlink;
struct devlink_sb *devlink_sb;
int start = cb->args[0];
int idx = 0;
int err;
mutex_lock(&devlink_mutex);
mutex_lock(&devlink_port_mutex);
list_for_each_entry(devlink, &devlink_list, list) {
if (!net_eq(devlink_net(devlink), sock_net(msg->sk)) ||
!devlink->ops || !devlink->ops->sb_tc_pool_bind_get)
continue;
list_for_each_entry(devlink_sb, &devlink->sb_list, list) {
err = __sb_tc_pool_bind_get_dumpit(msg, start, &idx,
devlink,
devlink_sb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq);
if (err && err != -EOPNOTSUPP)
goto out;
}
}
out:
mutex_unlock(&devlink_port_mutex);
mutex_unlock(&devlink_mutex);
cb->args[0] = idx;
return msg->len;
}
static int devlink_sb_tc_pool_bind_set(struct devlink_port *devlink_port,
unsigned int sb_index, u16 tc_index,
enum devlink_sb_pool_type pool_type,
u16 pool_index, u32 threshold)
{
const struct devlink_ops *ops = devlink_port->devlink->ops;
if (ops && ops->sb_tc_pool_bind_set)
return ops->sb_tc_pool_bind_set(devlink_port, sb_index,
tc_index, pool_type,
pool_index, threshold);
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_sb_tc_pool_bind_set_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink_port *devlink_port = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
enum devlink_sb_pool_type pool_type;
u16 tc_index;
u16 pool_index;
u32 threshold;
int err;
err = devlink_sb_pool_type_get_from_info(info, &pool_type);
if (err)
return err;
err = devlink_sb_tc_index_get_from_info(devlink_sb, info,
pool_type, &tc_index);
if (err)
return err;
err = devlink_sb_pool_index_get_from_info(devlink_sb, info,
&pool_index);
if (err)
return err;
if (!info->attrs[DEVLINK_ATTR_SB_THRESHOLD])
return -EINVAL;
threshold = nla_get_u32(info->attrs[DEVLINK_ATTR_SB_THRESHOLD]);
return devlink_sb_tc_pool_bind_set(devlink_port, devlink_sb->index,
tc_index, pool_type,
pool_index, threshold);
}
static int devlink_nl_cmd_sb_occ_snapshot_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
const struct devlink_ops *ops = devlink->ops;
if (ops && ops->sb_occ_snapshot)
return ops->sb_occ_snapshot(devlink, devlink_sb->index);
return -EOPNOTSUPP;
}
static int devlink_nl_cmd_sb_occ_max_clear_doit(struct sk_buff *skb,
struct genl_info *info)
{
struct devlink *devlink = info->user_ptr[0];
struct devlink_sb *devlink_sb = info->user_ptr[1];
const struct devlink_ops *ops = devlink->ops;
if (ops && ops->sb_occ_max_clear)
return ops->sb_occ_max_clear(devlink, devlink_sb->index);
return -EOPNOTSUPP;
}
struct devlink *devlink_alloc(const struct devlink_ops *ops, size_t priv_size)
{
struct devlink *devlink;
devlink = kzalloc(sizeof(*devlink) + priv_size, GFP_KERNEL);
if (!devlink)
return NULL;
devlink->ops = ops;
devlink_net_set(devlink, &init_net);
INIT_LIST_HEAD(&devlink->port_list);
INIT_LIST_HEAD(&devlink->sb_list);
return devlink;
}
int devlink_register(struct devlink *devlink, struct device *dev)
{
mutex_lock(&devlink_mutex);
devlink->dev = dev;
list_add_tail(&devlink->list, &devlink_list);
devlink_notify(devlink, DEVLINK_CMD_NEW);
mutex_unlock(&devlink_mutex);
return 0;
}
void devlink_unregister(struct devlink *devlink)
{
mutex_lock(&devlink_mutex);
devlink_notify(devlink, DEVLINK_CMD_DEL);
list_del(&devlink->list);
mutex_unlock(&devlink_mutex);
}
void devlink_free(struct devlink *devlink)
{
kfree(devlink);
}
int devlink_port_register(struct devlink *devlink,
struct devlink_port *devlink_port,
unsigned int port_index)
{
mutex_lock(&devlink_port_mutex);
if (devlink_port_index_exists(devlink, port_index)) {
mutex_unlock(&devlink_port_mutex);
return -EEXIST;
}
devlink_port->devlink = devlink;
devlink_port->index = port_index;
devlink_port->registered = true;
list_add_tail(&devlink_port->list, &devlink->port_list);
mutex_unlock(&devlink_port_mutex);
devlink_port_notify(devlink_port, DEVLINK_CMD_PORT_NEW);
return 0;
}
void devlink_port_unregister(struct devlink_port *devlink_port)
{
devlink_port_notify(devlink_port, DEVLINK_CMD_PORT_DEL);
mutex_lock(&devlink_port_mutex);
list_del(&devlink_port->list);
mutex_unlock(&devlink_port_mutex);
}
static void __devlink_port_type_set(struct devlink_port *devlink_port,
enum devlink_port_type type,
void *type_dev)
{
devlink_port->type = type;
devlink_port->type_dev = type_dev;
devlink_port_notify(devlink_port, DEVLINK_CMD_PORT_NEW);
}
void devlink_port_type_eth_set(struct devlink_port *devlink_port,
struct net_device *netdev)
{
return __devlink_port_type_set(devlink_port,
DEVLINK_PORT_TYPE_ETH, netdev);
}
void devlink_port_type_ib_set(struct devlink_port *devlink_port,
struct ib_device *ibdev)
{
return __devlink_port_type_set(devlink_port,
DEVLINK_PORT_TYPE_IB, ibdev);
}
void devlink_port_type_clear(struct devlink_port *devlink_port)
{
return __devlink_port_type_set(devlink_port,
DEVLINK_PORT_TYPE_NOTSET, NULL);
}
void devlink_port_split_set(struct devlink_port *devlink_port,
u32 split_group)
{
devlink_port->split = true;
devlink_port->split_group = split_group;
devlink_port_notify(devlink_port, DEVLINK_CMD_PORT_NEW);
}
int devlink_sb_register(struct devlink *devlink, unsigned int sb_index,
u32 size, u16 ingress_pools_count,
u16 egress_pools_count, u16 ingress_tc_count,
u16 egress_tc_count)
{
struct devlink_sb *devlink_sb;
int err = 0;
mutex_lock(&devlink_mutex);
if (devlink_sb_index_exists(devlink, sb_index)) {
err = -EEXIST;
goto unlock;
}
devlink_sb = kzalloc(sizeof(*devlink_sb), GFP_KERNEL);
if (!devlink_sb) {
err = -ENOMEM;
goto unlock;
}
devlink_sb->index = sb_index;
devlink_sb->size = size;
devlink_sb->ingress_pools_count = ingress_pools_count;
devlink_sb->egress_pools_count = egress_pools_count;
devlink_sb->ingress_tc_count = ingress_tc_count;
devlink_sb->egress_tc_count = egress_tc_count;
list_add_tail(&devlink_sb->list, &devlink->sb_list);
unlock:
mutex_unlock(&devlink_mutex);
return err;
}
void devlink_sb_unregister(struct devlink *devlink, unsigned int sb_index)
{
struct devlink_sb *devlink_sb;
mutex_lock(&devlink_mutex);
devlink_sb = devlink_sb_get_by_index(devlink, sb_index);
WARN_ON(!devlink_sb);
list_del(&devlink_sb->list);
mutex_unlock(&devlink_mutex);
kfree(devlink_sb);
}
static int __init devlink_module_init(void)
{
return genl_register_family_with_ops_groups(&devlink_nl_family,
devlink_nl_ops,
devlink_nl_mcgrps);
}
static void __exit devlink_module_exit(void)
{
genl_unregister_family(&devlink_nl_family);
}
