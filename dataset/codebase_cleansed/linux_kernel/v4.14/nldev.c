static int fill_dev_info(struct sk_buff *msg, struct ib_device *device)
{
char fw[IB_FW_VERSION_NAME_MAX];
if (nla_put_u32(msg, RDMA_NLDEV_ATTR_DEV_INDEX, device->index))
return -EMSGSIZE;
if (nla_put_string(msg, RDMA_NLDEV_ATTR_DEV_NAME, device->name))
return -EMSGSIZE;
if (nla_put_u32(msg, RDMA_NLDEV_ATTR_PORT_INDEX, rdma_end_port(device)))
return -EMSGSIZE;
BUILD_BUG_ON(sizeof(device->attrs.device_cap_flags) != sizeof(u64));
if (nla_put_u64_64bit(msg, RDMA_NLDEV_ATTR_CAP_FLAGS,
device->attrs.device_cap_flags, 0))
return -EMSGSIZE;
ib_get_device_fw_str(device, fw);
if (strlen(fw) && nla_put_string(msg, RDMA_NLDEV_ATTR_FW_VERSION, fw))
return -EMSGSIZE;
if (nla_put_u64_64bit(msg, RDMA_NLDEV_ATTR_NODE_GUID,
be64_to_cpu(device->node_guid), 0))
return -EMSGSIZE;
if (nla_put_u64_64bit(msg, RDMA_NLDEV_ATTR_SYS_IMAGE_GUID,
be64_to_cpu(device->attrs.sys_image_guid), 0))
return -EMSGSIZE;
if (nla_put_u8(msg, RDMA_NLDEV_ATTR_DEV_NODE_TYPE, device->node_type))
return -EMSGSIZE;
return 0;
}
static int fill_port_info(struct sk_buff *msg,
struct ib_device *device, u32 port)
{
struct ib_port_attr attr;
int ret;
if (nla_put_u32(msg, RDMA_NLDEV_ATTR_DEV_INDEX, device->index))
return -EMSGSIZE;
if (nla_put_string(msg, RDMA_NLDEV_ATTR_DEV_NAME, device->name))
return -EMSGSIZE;
if (nla_put_u32(msg, RDMA_NLDEV_ATTR_PORT_INDEX, port))
return -EMSGSIZE;
ret = ib_query_port(device, port, &attr);
if (ret)
return ret;
BUILD_BUG_ON(sizeof(attr.port_cap_flags) > sizeof(u64));
if (nla_put_u64_64bit(msg, RDMA_NLDEV_ATTR_CAP_FLAGS,
(u64)attr.port_cap_flags, 0))
return -EMSGSIZE;
if (rdma_protocol_ib(device, port) &&
nla_put_u64_64bit(msg, RDMA_NLDEV_ATTR_SUBNET_PREFIX,
attr.subnet_prefix, 0))
return -EMSGSIZE;
if (rdma_protocol_ib(device, port)) {
if (nla_put_u32(msg, RDMA_NLDEV_ATTR_LID, attr.lid))
return -EMSGSIZE;
if (nla_put_u32(msg, RDMA_NLDEV_ATTR_SM_LID, attr.sm_lid))
return -EMSGSIZE;
if (nla_put_u8(msg, RDMA_NLDEV_ATTR_LMC, attr.lmc))
return -EMSGSIZE;
}
if (nla_put_u8(msg, RDMA_NLDEV_ATTR_PORT_STATE, attr.state))
return -EMSGSIZE;
if (nla_put_u8(msg, RDMA_NLDEV_ATTR_PORT_PHYS_STATE, attr.phys_state))
return -EMSGSIZE;
return 0;
}
static int nldev_get_doit(struct sk_buff *skb, struct nlmsghdr *nlh,
struct netlink_ext_ack *extack)
{
struct nlattr *tb[RDMA_NLDEV_ATTR_MAX];
struct ib_device *device;
struct sk_buff *msg;
u32 index;
int err;
err = nlmsg_parse(nlh, 0, tb, RDMA_NLDEV_ATTR_MAX - 1,
nldev_policy, extack);
if (err || !tb[RDMA_NLDEV_ATTR_DEV_INDEX])
return -EINVAL;
index = nla_get_u32(tb[RDMA_NLDEV_ATTR_DEV_INDEX]);
device = __ib_device_get_by_index(index);
if (!device)
return -EINVAL;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
nlh = nlmsg_put(msg, NETLINK_CB(skb).portid, nlh->nlmsg_seq,
RDMA_NL_GET_TYPE(RDMA_NL_NLDEV, RDMA_NLDEV_CMD_GET),
0, 0);
err = fill_dev_info(msg, device);
if (err) {
nlmsg_free(msg);
return err;
}
nlmsg_end(msg, nlh);
return rdma_nl_unicast(msg, NETLINK_CB(skb).portid);
}
static int _nldev_get_dumpit(struct ib_device *device,
struct sk_buff *skb,
struct netlink_callback *cb,
unsigned int idx)
{
int start = cb->args[0];
struct nlmsghdr *nlh;
if (idx < start)
return 0;
nlh = nlmsg_put(skb, NETLINK_CB(cb->skb).portid, cb->nlh->nlmsg_seq,
RDMA_NL_GET_TYPE(RDMA_NL_NLDEV, RDMA_NLDEV_CMD_GET),
0, NLM_F_MULTI);
if (fill_dev_info(skb, device)) {
nlmsg_cancel(skb, nlh);
goto out;
}
nlmsg_end(skb, nlh);
idx++;
out: cb->args[0] = idx;
return skb->len;
}
static int nldev_get_dumpit(struct sk_buff *skb, struct netlink_callback *cb)
{
return ib_enum_all_devs(_nldev_get_dumpit, skb, cb);
}
static int nldev_port_get_doit(struct sk_buff *skb, struct nlmsghdr *nlh,
struct netlink_ext_ack *extack)
{
struct nlattr *tb[RDMA_NLDEV_ATTR_MAX];
struct ib_device *device;
struct sk_buff *msg;
u32 index;
u32 port;
int err;
err = nlmsg_parse(nlh, 0, tb, RDMA_NLDEV_ATTR_MAX - 1,
nldev_policy, extack);
if (err ||
!tb[RDMA_NLDEV_ATTR_DEV_INDEX] ||
!tb[RDMA_NLDEV_ATTR_PORT_INDEX])
return -EINVAL;
index = nla_get_u32(tb[RDMA_NLDEV_ATTR_DEV_INDEX]);
device = __ib_device_get_by_index(index);
if (!device)
return -EINVAL;
port = nla_get_u32(tb[RDMA_NLDEV_ATTR_PORT_INDEX]);
if (!rdma_is_port_valid(device, port))
return -EINVAL;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
nlh = nlmsg_put(msg, NETLINK_CB(skb).portid, nlh->nlmsg_seq,
RDMA_NL_GET_TYPE(RDMA_NL_NLDEV, RDMA_NLDEV_CMD_GET),
0, 0);
err = fill_port_info(msg, device, port);
if (err) {
nlmsg_free(msg);
return err;
}
nlmsg_end(msg, nlh);
return rdma_nl_unicast(msg, NETLINK_CB(skb).portid);
}
static int nldev_port_get_dumpit(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct nlattr *tb[RDMA_NLDEV_ATTR_MAX];
struct ib_device *device;
int start = cb->args[0];
struct nlmsghdr *nlh;
u32 idx = 0;
u32 ifindex;
int err;
u32 p;
err = nlmsg_parse(cb->nlh, 0, tb, RDMA_NLDEV_ATTR_MAX - 1,
nldev_policy, NULL);
if (err || !tb[RDMA_NLDEV_ATTR_DEV_INDEX])
return -EINVAL;
ifindex = nla_get_u32(tb[RDMA_NLDEV_ATTR_DEV_INDEX]);
device = __ib_device_get_by_index(ifindex);
if (!device)
return -EINVAL;
for (p = rdma_start_port(device); p <= rdma_end_port(device); ++p) {
if (idx < start) {
idx++;
continue;
}
nlh = nlmsg_put(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RDMA_NL_GET_TYPE(RDMA_NL_NLDEV,
RDMA_NLDEV_CMD_PORT_GET),
0, NLM_F_MULTI);
if (fill_port_info(skb, device, p)) {
nlmsg_cancel(skb, nlh);
goto out;
}
idx++;
nlmsg_end(skb, nlh);
}
out: cb->args[0] = idx;
return skb->len;
}
void __init nldev_init(void)
{
rdma_nl_register(RDMA_NL_NLDEV, nldev_cb_table);
}
void __exit nldev_exit(void)
{
rdma_nl_unregister(RDMA_NL_NLDEV);
}
