struct sk_buff *wimax_msg_alloc(struct wimax_dev *wimax_dev,
const char *pipe_name,
const void *msg, size_t size,
gfp_t gfp_flags)
{
int result;
struct device *dev = wimax_dev_to_dev(wimax_dev);
size_t msg_size;
void *genl_msg;
struct sk_buff *skb;
msg_size = nla_total_size(size)
+ nla_total_size(sizeof(u32))
+ (pipe_name ? nla_total_size(strlen(pipe_name)) : 0);
result = -ENOMEM;
skb = genlmsg_new(msg_size, gfp_flags);
if (skb == NULL)
goto error_new;
genl_msg = genlmsg_put(skb, 0, 0, &wimax_gnl_family,
0, WIMAX_GNL_OP_MSG_TO_USER);
if (genl_msg == NULL) {
dev_err(dev, "no memory to create generic netlink message\n");
goto error_genlmsg_put;
}
result = nla_put_u32(skb, WIMAX_GNL_MSG_IFIDX,
wimax_dev->net_dev->ifindex);
if (result < 0) {
dev_err(dev, "no memory to add ifindex attribute\n");
goto error_nla_put;
}
if (pipe_name) {
result = nla_put_string(skb, WIMAX_GNL_MSG_PIPE_NAME,
pipe_name);
if (result < 0) {
dev_err(dev, "no memory to add pipe_name attribute\n");
goto error_nla_put;
}
}
result = nla_put(skb, WIMAX_GNL_MSG_DATA, size, msg);
if (result < 0) {
dev_err(dev, "no memory to add payload (msg %p size %zu) in "
"attribute: %d\n", msg, size, result);
goto error_nla_put;
}
genlmsg_end(skb, genl_msg);
return skb;
error_nla_put:
error_genlmsg_put:
error_new:
nlmsg_free(skb);
return ERR_PTR(result);
}
const void *wimax_msg_data_len(struct sk_buff *msg, size_t *size)
{
struct nlmsghdr *nlh = (void *) msg->head;
struct nlattr *nla;
nla = nlmsg_find_attr(nlh, sizeof(struct genlmsghdr),
WIMAX_GNL_MSG_DATA);
if (nla == NULL) {
printk(KERN_ERR "Cannot find attribute WIMAX_GNL_MSG_DATA\n");
return NULL;
}
*size = nla_len(nla);
return nla_data(nla);
}
const void *wimax_msg_data(struct sk_buff *msg)
{
struct nlmsghdr *nlh = (void *) msg->head;
struct nlattr *nla;
nla = nlmsg_find_attr(nlh, sizeof(struct genlmsghdr),
WIMAX_GNL_MSG_DATA);
if (nla == NULL) {
printk(KERN_ERR "Cannot find attribute WIMAX_GNL_MSG_DATA\n");
return NULL;
}
return nla_data(nla);
}
ssize_t wimax_msg_len(struct sk_buff *msg)
{
struct nlmsghdr *nlh = (void *) msg->head;
struct nlattr *nla;
nla = nlmsg_find_attr(nlh, sizeof(struct genlmsghdr),
WIMAX_GNL_MSG_DATA);
if (nla == NULL) {
printk(KERN_ERR "Cannot find attribute WIMAX_GNL_MSG_DATA\n");
return -EINVAL;
}
return nla_len(nla);
}
int wimax_msg_send(struct wimax_dev *wimax_dev, struct sk_buff *skb)
{
struct device *dev = wimax_dev_to_dev(wimax_dev);
void *msg = skb->data;
size_t size = skb->len;
might_sleep();
d_printf(1, dev, "CTX: wimax msg, %zu bytes\n", size);
d_dump(2, dev, msg, size);
genlmsg_multicast(&wimax_gnl_family, skb, 0, 0, GFP_KERNEL);
d_printf(1, dev, "CTX: genl multicast done\n");
return 0;
}
int wimax_msg(struct wimax_dev *wimax_dev, const char *pipe_name,
const void *buf, size_t size, gfp_t gfp_flags)
{
int result = -ENOMEM;
struct sk_buff *skb;
skb = wimax_msg_alloc(wimax_dev, pipe_name, buf, size, gfp_flags);
if (IS_ERR(skb))
result = PTR_ERR(skb);
else
result = wimax_msg_send(wimax_dev, skb);
return result;
}
int wimax_gnl_doit_msg_from_user(struct sk_buff *skb, struct genl_info *info)
{
int result, ifindex;
struct wimax_dev *wimax_dev;
struct device *dev;
struct nlmsghdr *nlh = info->nlhdr;
char *pipe_name;
void *msg_buf;
size_t msg_len;
might_sleep();
d_fnstart(3, NULL, "(skb %p info %p)\n", skb, info);
result = -ENODEV;
if (info->attrs[WIMAX_GNL_MSG_IFIDX] == NULL) {
printk(KERN_ERR "WIMAX_GNL_MSG_FROM_USER: can't find IFIDX "
"attribute\n");
goto error_no_wimax_dev;
}
ifindex = nla_get_u32(info->attrs[WIMAX_GNL_MSG_IFIDX]);
wimax_dev = wimax_dev_get_by_genl_info(info, ifindex);
if (wimax_dev == NULL)
goto error_no_wimax_dev;
dev = wimax_dev_to_dev(wimax_dev);
result = -EINVAL;
if (info->attrs[WIMAX_GNL_MSG_DATA] == NULL) {
dev_err(dev, "WIMAX_GNL_MSG_FROM_USER: can't find MSG_DATA "
"attribute\n");
goto error_no_data;
}
msg_buf = nla_data(info->attrs[WIMAX_GNL_MSG_DATA]);
msg_len = nla_len(info->attrs[WIMAX_GNL_MSG_DATA]);
if (info->attrs[WIMAX_GNL_MSG_PIPE_NAME] == NULL)
pipe_name = NULL;
else {
struct nlattr *attr = info->attrs[WIMAX_GNL_MSG_PIPE_NAME];
size_t attr_len = nla_len(attr);
result = -ENOMEM;
pipe_name = kstrndup(nla_data(attr), attr_len + 1, GFP_KERNEL);
if (pipe_name == NULL)
goto error_alloc;
pipe_name[attr_len] = 0;
}
mutex_lock(&wimax_dev->mutex);
result = wimax_dev_is_ready(wimax_dev);
if (result == -ENOMEDIUM)
result = 0;
if (result < 0)
goto error_not_ready;
result = -ENOSYS;
if (wimax_dev->op_msg_from_user == NULL)
goto error_noop;
d_printf(1, dev,
"CRX: nlmsghdr len %u type %u flags 0x%04x seq 0x%x pid %u\n",
nlh->nlmsg_len, nlh->nlmsg_type, nlh->nlmsg_flags,
nlh->nlmsg_seq, nlh->nlmsg_pid);
d_printf(1, dev, "CRX: wimax message %zu bytes\n", msg_len);
d_dump(2, dev, msg_buf, msg_len);
result = wimax_dev->op_msg_from_user(wimax_dev, pipe_name,
msg_buf, msg_len, info);
error_noop:
error_not_ready:
mutex_unlock(&wimax_dev->mutex);
error_alloc:
kfree(pipe_name);
error_no_data:
dev_put(wimax_dev->net_dev);
error_no_wimax_dev:
d_fnend(3, NULL, "(skb %p info %p) = %d\n", skb, info, result);
return result;
}
