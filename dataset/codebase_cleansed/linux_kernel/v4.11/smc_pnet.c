static bool smc_pnet_same_ibname(struct smc_pnetentry *pnetelem, char *ibname,
u8 ibport)
{
return pnetelem->ib_port == ibport &&
!strncmp(pnetelem->smcibdev->ibdev->name, ibname,
sizeof(pnetelem->smcibdev->ibdev->name));
}
static struct smc_pnetentry *smc_pnet_find_pnetid(char *pnet_name)
{
struct smc_pnetentry *pnetelem, *found_pnetelem = NULL;
read_lock(&smc_pnettable.lock);
list_for_each_entry(pnetelem, &smc_pnettable.pnetlist, list) {
if (!strncmp(pnetelem->pnet_name, pnet_name,
sizeof(pnetelem->pnet_name))) {
found_pnetelem = pnetelem;
break;
}
}
read_unlock(&smc_pnettable.lock);
return found_pnetelem;
}
static int smc_pnet_remove_by_pnetid(char *pnet_name)
{
struct smc_pnetentry *pnetelem, *tmp_pe;
int rc = -ENOENT;
write_lock(&smc_pnettable.lock);
list_for_each_entry_safe(pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
if (!strncmp(pnetelem->pnet_name, pnet_name,
sizeof(pnetelem->pnet_name))) {
list_del(&pnetelem->list);
dev_put(pnetelem->ndev);
kfree(pnetelem);
rc = 0;
break;
}
}
write_unlock(&smc_pnettable.lock);
return rc;
}
static int smc_pnet_remove_by_ndev(struct net_device *ndev)
{
struct smc_pnetentry *pnetelem, *tmp_pe;
int rc = -ENOENT;
write_lock(&smc_pnettable.lock);
list_for_each_entry_safe(pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
if (pnetelem->ndev == ndev) {
list_del(&pnetelem->list);
dev_put(pnetelem->ndev);
kfree(pnetelem);
rc = 0;
break;
}
}
write_unlock(&smc_pnettable.lock);
return rc;
}
int smc_pnet_remove_by_ibdev(struct smc_ib_device *ibdev)
{
struct smc_pnetentry *pnetelem, *tmp_pe;
int rc = -ENOENT;
write_lock(&smc_pnettable.lock);
list_for_each_entry_safe(pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
if (pnetelem->smcibdev == ibdev) {
list_del(&pnetelem->list);
dev_put(pnetelem->ndev);
kfree(pnetelem);
rc = 0;
break;
}
}
write_unlock(&smc_pnettable.lock);
return rc;
}
static int smc_pnet_enter(struct smc_pnetentry *new_pnetelem)
{
struct smc_pnetentry *pnetelem;
int rc = -EEXIST;
write_lock(&smc_pnettable.lock);
list_for_each_entry(pnetelem, &smc_pnettable.pnetlist, list) {
if (!strncmp(pnetelem->pnet_name, new_pnetelem->pnet_name,
sizeof(new_pnetelem->pnet_name)) ||
!strncmp(pnetelem->ndev->name, new_pnetelem->ndev->name,
sizeof(new_pnetelem->ndev->name)) ||
smc_pnet_same_ibname(pnetelem,
new_pnetelem->smcibdev->ibdev->name,
new_pnetelem->ib_port))
goto found;
}
list_add_tail(&new_pnetelem->list, &smc_pnettable.pnetlist);
rc = 0;
found:
write_unlock(&smc_pnettable.lock);
return rc;
}
static bool smc_pnetid_valid(const char *pnet_name, char *pnetid)
{
char *bf = skip_spaces(pnet_name);
size_t len = strlen(bf);
char *end = bf + len;
if (!len)
return false;
while (--end >= bf && isspace(*end))
;
if (end - bf >= SMC_MAX_PNET_ID_LEN)
return false;
while (bf <= end) {
if (!isalnum(*bf))
return false;
*pnetid++ = islower(*bf) ? toupper(*bf) : *bf;
bf++;
}
*pnetid = '\0';
return true;
}
struct smc_ib_device *smc_pnet_find_ib(char *ib_name)
{
struct smc_ib_device *ibdev;
spin_lock(&smc_ib_devices.lock);
list_for_each_entry(ibdev, &smc_ib_devices.list, list) {
if (!strncmp(ibdev->ibdev->name, ib_name,
sizeof(ibdev->ibdev->name))) {
goto out;
}
}
ibdev = NULL;
out:
spin_unlock(&smc_ib_devices.lock);
return ibdev;
}
static int smc_pnet_fill_entry(struct net *net, struct smc_pnetentry *pnetelem,
struct nlattr *tb[])
{
char *string, *ibname = NULL;
int rc = 0;
memset(pnetelem, 0, sizeof(*pnetelem));
INIT_LIST_HEAD(&pnetelem->list);
if (tb[SMC_PNETID_NAME]) {
string = (char *)nla_data(tb[SMC_PNETID_NAME]);
if (!smc_pnetid_valid(string, pnetelem->pnet_name)) {
rc = -EINVAL;
goto error;
}
}
if (tb[SMC_PNETID_ETHNAME]) {
string = (char *)nla_data(tb[SMC_PNETID_ETHNAME]);
pnetelem->ndev = dev_get_by_name(net, string);
if (!pnetelem->ndev)
return -ENOENT;
}
if (tb[SMC_PNETID_IBNAME]) {
ibname = (char *)nla_data(tb[SMC_PNETID_IBNAME]);
ibname = strim(ibname);
pnetelem->smcibdev = smc_pnet_find_ib(ibname);
if (!pnetelem->smcibdev) {
rc = -ENOENT;
goto error;
}
}
if (tb[SMC_PNETID_IBPORT]) {
pnetelem->ib_port = nla_get_u8(tb[SMC_PNETID_IBPORT]);
if (pnetelem->ib_port > SMC_MAX_PORTS) {
rc = -EINVAL;
goto error;
}
}
return 0;
error:
if (pnetelem->ndev)
dev_put(pnetelem->ndev);
return rc;
}
static int smc_pnet_set_nla(struct sk_buff *msg, struct smc_pnetentry *pnetelem)
{
if (nla_put_string(msg, SMC_PNETID_NAME, pnetelem->pnet_name) ||
nla_put_string(msg, SMC_PNETID_ETHNAME, pnetelem->ndev->name) ||
nla_put_string(msg, SMC_PNETID_IBNAME,
pnetelem->smcibdev->ibdev->name) ||
nla_put_u8(msg, SMC_PNETID_IBPORT, pnetelem->ib_port))
return -1;
return 0;
}
static int smc_pnet_get(struct sk_buff *skb, struct genl_info *info)
{
struct smc_pnetentry *pnetelem;
struct sk_buff *msg;
void *hdr;
int rc;
pnetelem = smc_pnet_find_pnetid(
(char *)nla_data(info->attrs[SMC_PNETID_NAME]));
if (!pnetelem)
return -ENOENT;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
hdr = genlmsg_put(msg, info->snd_portid, info->snd_seq,
&smc_pnet_nl_family, 0, SMC_PNETID_GET);
if (!hdr) {
rc = -EMSGSIZE;
goto err_out;
}
if (smc_pnet_set_nla(msg, pnetelem)) {
rc = -ENOBUFS;
goto err_out;
}
genlmsg_end(msg, hdr);
return genlmsg_reply(msg, info);
err_out:
nlmsg_free(msg);
return rc;
}
static int smc_pnet_add(struct sk_buff *skb, struct genl_info *info)
{
struct net *net = genl_info_net(info);
struct smc_pnetentry *pnetelem;
int rc;
pnetelem = kzalloc(sizeof(*pnetelem), GFP_KERNEL);
if (!pnetelem)
return -ENOMEM;
rc = smc_pnet_fill_entry(net, pnetelem, info->attrs);
if (!rc)
rc = smc_pnet_enter(pnetelem);
if (rc) {
kfree(pnetelem);
return rc;
}
rc = smc_ib_remember_port_attr(pnetelem->smcibdev, pnetelem->ib_port);
if (rc)
smc_pnet_remove_by_pnetid(pnetelem->pnet_name);
return rc;
}
static int smc_pnet_del(struct sk_buff *skb, struct genl_info *info)
{
return smc_pnet_remove_by_pnetid(
(char *)nla_data(info->attrs[SMC_PNETID_NAME]));
}
static int smc_pnet_dump_start(struct netlink_callback *cb)
{
cb->args[0] = 0;
return 0;
}
static int smc_pnet_dumpinfo(struct sk_buff *skb,
u32 portid, u32 seq, u32 flags,
struct smc_pnetentry *pnetelem)
{
void *hdr;
hdr = genlmsg_put(skb, portid, seq, &smc_pnet_nl_family,
flags, SMC_PNETID_GET);
if (!hdr)
return -ENOMEM;
if (smc_pnet_set_nla(skb, pnetelem) < 0) {
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
genlmsg_end(skb, hdr);
return 0;
}
static int smc_pnet_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct smc_pnetentry *pnetelem;
int idx = 0;
read_lock(&smc_pnettable.lock);
list_for_each_entry(pnetelem, &smc_pnettable.pnetlist, list) {
if (idx++ < cb->args[0])
continue;
if (smc_pnet_dumpinfo(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
pnetelem)) {
--idx;
break;
}
}
cb->args[0] = idx;
read_unlock(&smc_pnettable.lock);
return skb->len;
}
static int smc_pnet_flush(struct sk_buff *skb, struct genl_info *info)
{
struct smc_pnetentry *pnetelem, *tmp_pe;
write_lock(&smc_pnettable.lock);
list_for_each_entry_safe(pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
list_del(&pnetelem->list);
dev_put(pnetelem->ndev);
kfree(pnetelem);
}
write_unlock(&smc_pnettable.lock);
return 0;
}
static int smc_pnet_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *event_dev = netdev_notifier_info_to_dev(ptr);
switch (event) {
case NETDEV_REBOOT:
case NETDEV_UNREGISTER:
smc_pnet_remove_by_ndev(event_dev);
default:
break;
}
return NOTIFY_DONE;
}
int __init smc_pnet_init(void)
{
int rc;
rc = genl_register_family(&smc_pnet_nl_family);
if (rc)
return rc;
rc = register_netdevice_notifier(&smc_netdev_notifier);
if (rc)
genl_unregister_family(&smc_pnet_nl_family);
return rc;
}
void smc_pnet_exit(void)
{
smc_pnet_flush(NULL, NULL);
unregister_netdevice_notifier(&smc_netdev_notifier);
genl_unregister_family(&smc_pnet_nl_family);
}
void smc_pnet_find_roce_resource(struct sock *sk,
struct smc_ib_device **smcibdev, u8 *ibport)
{
struct dst_entry *dst = sk_dst_get(sk);
struct smc_pnetentry *pnetelem;
*smcibdev = NULL;
*ibport = 0;
if (!dst)
return;
if (!dst->dev)
goto out_rel;
read_lock(&smc_pnettable.lock);
list_for_each_entry(pnetelem, &smc_pnettable.pnetlist, list) {
if (dst->dev == pnetelem->ndev) {
*smcibdev = pnetelem->smcibdev;
*ibport = pnetelem->ib_port;
break;
}
}
read_unlock(&smc_pnettable.lock);
out_rel:
dst_release(dst);
}
