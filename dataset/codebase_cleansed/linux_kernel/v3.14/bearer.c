struct tipc_media *tipc_media_find(const char *name)
{
u32 i;
for (i = 0; media_info_array[i] != NULL; i++) {
if (!strcmp(media_info_array[i]->name, name))
break;
}
return media_info_array[i];
}
static struct tipc_media *media_find_id(u8 type)
{
u32 i;
for (i = 0; media_info_array[i] != NULL; i++) {
if (media_info_array[i]->type_id == type)
break;
}
return media_info_array[i];
}
void tipc_media_addr_printf(char *buf, int len, struct tipc_media_addr *a)
{
char addr_str[MAX_ADDR_STR];
struct tipc_media *m_ptr;
int ret;
m_ptr = media_find_id(a->media_id);
if (m_ptr && !m_ptr->addr2str(a, addr_str, sizeof(addr_str)))
ret = tipc_snprintf(buf, len, "%s(%s)", m_ptr->name, addr_str);
else {
u32 i;
ret = tipc_snprintf(buf, len, "UNKNOWN(%u)", a->media_id);
for (i = 0; i < sizeof(a->value); i++)
ret += tipc_snprintf(buf - ret, len + ret,
"-%02x", a->value[i]);
}
}
struct sk_buff *tipc_media_get_names(void)
{
struct sk_buff *buf;
int i;
buf = tipc_cfg_reply_alloc(MAX_MEDIA * TLV_SPACE(TIPC_MAX_MEDIA_NAME));
if (!buf)
return NULL;
for (i = 0; media_info_array[i] != NULL; i++) {
tipc_cfg_append_tlv(buf, TIPC_TLV_MEDIA_NAME,
media_info_array[i]->name,
strlen(media_info_array[i]->name) + 1);
}
return buf;
}
static int bearer_name_validate(const char *name,
struct tipc_bearer_names *name_parts)
{
char name_copy[TIPC_MAX_BEARER_NAME];
char *media_name;
char *if_name;
u32 media_len;
u32 if_len;
name_copy[TIPC_MAX_BEARER_NAME - 1] = 0;
strncpy(name_copy, name, TIPC_MAX_BEARER_NAME);
if (name_copy[TIPC_MAX_BEARER_NAME - 1] != 0)
return 0;
media_name = name_copy;
if_name = strchr(media_name, ':');
if (if_name == NULL)
return 0;
*(if_name++) = 0;
media_len = if_name - media_name;
if_len = strlen(if_name) + 1;
if ((media_len <= 1) || (media_len > TIPC_MAX_MEDIA_NAME) ||
(if_len <= 1) || (if_len > TIPC_MAX_IF_NAME))
return 0;
if (name_parts) {
strcpy(name_parts->media_name, media_name);
strcpy(name_parts->if_name, if_name);
}
return 1;
}
struct tipc_bearer *tipc_bearer_find(const char *name)
{
struct tipc_bearer *b_ptr;
u32 i;
for (i = 0, b_ptr = tipc_bearers; i < MAX_BEARERS; i++, b_ptr++) {
if (b_ptr->active && (!strcmp(b_ptr->name, name)))
return b_ptr;
}
return NULL;
}
struct sk_buff *tipc_bearer_get_names(void)
{
struct sk_buff *buf;
struct tipc_bearer *b;
int i, j;
buf = tipc_cfg_reply_alloc(MAX_BEARERS * TLV_SPACE(TIPC_MAX_BEARER_NAME));
if (!buf)
return NULL;
read_lock_bh(&tipc_net_lock);
for (i = 0; media_info_array[i] != NULL; i++) {
for (j = 0; j < MAX_BEARERS; j++) {
b = &tipc_bearers[j];
if (b->active && (b->media == media_info_array[i])) {
tipc_cfg_append_tlv(buf, TIPC_TLV_BEARER_NAME,
b->name,
strlen(b->name) + 1);
}
}
}
read_unlock_bh(&tipc_net_lock);
return buf;
}
void tipc_bearer_add_dest(struct tipc_bearer *b_ptr, u32 dest)
{
tipc_nmap_add(&b_ptr->nodes, dest);
tipc_bcbearer_sort();
tipc_disc_add_dest(b_ptr->link_req);
}
void tipc_bearer_remove_dest(struct tipc_bearer *b_ptr, u32 dest)
{
tipc_nmap_remove(&b_ptr->nodes, dest);
tipc_bcbearer_sort();
tipc_disc_remove_dest(b_ptr->link_req);
}
int tipc_enable_bearer(const char *name, u32 disc_domain, u32 priority)
{
struct tipc_bearer *b_ptr;
struct tipc_media *m_ptr;
struct tipc_bearer_names b_names;
char addr_string[16];
u32 bearer_id;
u32 with_this_prio;
u32 i;
int res = -EINVAL;
if (!tipc_own_addr) {
pr_warn("Bearer <%s> rejected, not supported in standalone mode\n",
name);
return -ENOPROTOOPT;
}
if (!bearer_name_validate(name, &b_names)) {
pr_warn("Bearer <%s> rejected, illegal name\n", name);
return -EINVAL;
}
if (tipc_addr_domain_valid(disc_domain) &&
(disc_domain != tipc_own_addr)) {
if (tipc_in_scope(disc_domain, tipc_own_addr)) {
disc_domain = tipc_own_addr & TIPC_CLUSTER_MASK;
res = 0;
} else if (in_own_cluster_exact(disc_domain))
res = 0;
}
if (res) {
pr_warn("Bearer <%s> rejected, illegal discovery domain\n",
name);
return -EINVAL;
}
if ((priority > TIPC_MAX_LINK_PRI) &&
(priority != TIPC_MEDIA_LINK_PRI)) {
pr_warn("Bearer <%s> rejected, illegal priority\n", name);
return -EINVAL;
}
write_lock_bh(&tipc_net_lock);
m_ptr = tipc_media_find(b_names.media_name);
if (!m_ptr) {
pr_warn("Bearer <%s> rejected, media <%s> not registered\n",
name, b_names.media_name);
goto exit;
}
if (priority == TIPC_MEDIA_LINK_PRI)
priority = m_ptr->priority;
restart:
bearer_id = MAX_BEARERS;
with_this_prio = 1;
for (i = MAX_BEARERS; i-- != 0; ) {
if (!tipc_bearers[i].active) {
bearer_id = i;
continue;
}
if (!strcmp(name, tipc_bearers[i].name)) {
pr_warn("Bearer <%s> rejected, already enabled\n",
name);
goto exit;
}
if ((tipc_bearers[i].priority == priority) &&
(++with_this_prio > 2)) {
if (priority-- == 0) {
pr_warn("Bearer <%s> rejected, duplicate priority\n",
name);
goto exit;
}
pr_warn("Bearer <%s> priority adjustment required %u->%u\n",
name, priority + 1, priority);
goto restart;
}
}
if (bearer_id >= MAX_BEARERS) {
pr_warn("Bearer <%s> rejected, bearer limit reached (%u)\n",
name, MAX_BEARERS);
goto exit;
}
b_ptr = &tipc_bearers[bearer_id];
strcpy(b_ptr->name, name);
b_ptr->media = m_ptr;
res = m_ptr->enable_media(b_ptr);
if (res) {
pr_warn("Bearer <%s> rejected, enable failure (%d)\n",
name, -res);
goto exit;
}
b_ptr->identity = bearer_id;
b_ptr->tolerance = m_ptr->tolerance;
b_ptr->window = m_ptr->window;
b_ptr->net_plane = bearer_id + 'A';
b_ptr->active = 1;
b_ptr->priority = priority;
INIT_LIST_HEAD(&b_ptr->links);
spin_lock_init(&b_ptr->lock);
res = tipc_disc_create(b_ptr, &b_ptr->bcast_addr, disc_domain);
if (res) {
bearer_disable(b_ptr);
pr_warn("Bearer <%s> rejected, discovery object creation failed\n",
name);
goto exit;
}
pr_info("Enabled bearer <%s>, discovery domain %s, priority %u\n",
name,
tipc_addr_string_fill(addr_string, disc_domain), priority);
exit:
write_unlock_bh(&tipc_net_lock);
return res;
}
static int tipc_reset_bearer(struct tipc_bearer *b_ptr)
{
struct tipc_link *l_ptr;
struct tipc_link *temp_l_ptr;
read_lock_bh(&tipc_net_lock);
pr_info("Resetting bearer <%s>\n", b_ptr->name);
spin_lock_bh(&b_ptr->lock);
list_for_each_entry_safe(l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct tipc_node *n_ptr = l_ptr->owner;
spin_lock_bh(&n_ptr->lock);
tipc_link_reset(l_ptr);
spin_unlock_bh(&n_ptr->lock);
}
spin_unlock_bh(&b_ptr->lock);
read_unlock_bh(&tipc_net_lock);
return 0;
}
static void bearer_disable(struct tipc_bearer *b_ptr)
{
struct tipc_link *l_ptr;
struct tipc_link *temp_l_ptr;
struct tipc_link_req *temp_req;
pr_info("Disabling bearer <%s>\n", b_ptr->name);
spin_lock_bh(&b_ptr->lock);
b_ptr->media->disable_media(b_ptr);
list_for_each_entry_safe(l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
tipc_link_delete(l_ptr);
}
temp_req = b_ptr->link_req;
b_ptr->link_req = NULL;
spin_unlock_bh(&b_ptr->lock);
if (temp_req)
tipc_disc_delete(temp_req);
memset(b_ptr, 0, sizeof(struct tipc_bearer));
}
int tipc_disable_bearer(const char *name)
{
struct tipc_bearer *b_ptr;
int res;
write_lock_bh(&tipc_net_lock);
b_ptr = tipc_bearer_find(name);
if (b_ptr == NULL) {
pr_warn("Attempt to disable unknown bearer <%s>\n", name);
res = -EINVAL;
} else {
bearer_disable(b_ptr);
res = 0;
}
write_unlock_bh(&tipc_net_lock);
return res;
}
void tipc_l2_media_addr_set(const struct tipc_bearer *b,
struct tipc_media_addr *a, char *mac)
{
int len = b->media->hwaddr_len;
if (unlikely(sizeof(a->value) < len)) {
WARN_ONCE(1, "Media length invalid\n");
return;
}
memcpy(a->value, mac, len);
memset(a->value + len, 0, sizeof(a->value) - len);
a->media_id = b->media->type_id;
a->broadcast = !memcmp(mac, b->bcast_addr.value, len);
}
int tipc_enable_l2_media(struct tipc_bearer *b)
{
struct net_device *dev;
char *driver_name = strchr((const char *)b->name, ':') + 1;
dev = dev_get_by_name(&init_net, driver_name);
if (!dev)
return -ENODEV;
b->media_ptr = dev;
memset(b->bcast_addr.value, 0, sizeof(b->bcast_addr.value));
memcpy(b->bcast_addr.value, dev->broadcast, b->media->hwaddr_len);
b->bcast_addr.media_id = b->media->type_id;
b->bcast_addr.broadcast = 1;
b->mtu = dev->mtu;
tipc_l2_media_addr_set(b, &b->addr, (char *)dev->dev_addr);
rcu_assign_pointer(dev->tipc_ptr, b);
return 0;
}
void tipc_disable_l2_media(struct tipc_bearer *b)
{
struct net_device *dev = (struct net_device *)b->media_ptr;
RCU_INIT_POINTER(dev->tipc_ptr, NULL);
dev_put(dev);
}
int tipc_l2_send_msg(struct sk_buff *buf, struct tipc_bearer *b,
struct tipc_media_addr *dest)
{
struct sk_buff *clone;
int delta;
struct net_device *dev = (struct net_device *)b->media_ptr;
clone = skb_clone(buf, GFP_ATOMIC);
if (!clone)
return 0;
delta = dev->hard_header_len - skb_headroom(buf);
if ((delta > 0) &&
pskb_expand_head(clone, SKB_DATA_ALIGN(delta), 0, GFP_ATOMIC)) {
kfree_skb(clone);
return 0;
}
skb_reset_network_header(clone);
clone->dev = dev;
clone->protocol = htons(ETH_P_TIPC);
dev_hard_header(clone, dev, ETH_P_TIPC, dest->value,
dev->dev_addr, clone->len);
dev_queue_xmit(clone);
return 0;
}
void tipc_bearer_send(struct tipc_bearer *b, struct sk_buff *buf,
struct tipc_media_addr *dest)
{
b->media->send_msg(buf, b, dest);
}
static int tipc_l2_rcv_msg(struct sk_buff *buf, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct tipc_bearer *b_ptr;
if (!net_eq(dev_net(dev), &init_net)) {
kfree_skb(buf);
return NET_RX_DROP;
}
rcu_read_lock();
b_ptr = rcu_dereference(dev->tipc_ptr);
if (likely(b_ptr)) {
if (likely(buf->pkt_type <= PACKET_BROADCAST)) {
buf->next = NULL;
tipc_rcv(buf, b_ptr);
rcu_read_unlock();
return NET_RX_SUCCESS;
}
}
rcu_read_unlock();
kfree_skb(buf);
return NET_RX_DROP;
}
static int tipc_l2_device_event(struct notifier_block *nb, unsigned long evt,
void *ptr)
{
struct tipc_bearer *b_ptr;
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
rcu_read_lock();
b_ptr = rcu_dereference(dev->tipc_ptr);
if (!b_ptr) {
rcu_read_unlock();
return NOTIFY_DONE;
}
b_ptr->mtu = dev->mtu;
switch (evt) {
case NETDEV_CHANGE:
if (netif_carrier_ok(dev))
break;
case NETDEV_DOWN:
case NETDEV_CHANGEMTU:
case NETDEV_CHANGEADDR:
tipc_reset_bearer(b_ptr);
break;
case NETDEV_UNREGISTER:
case NETDEV_CHANGENAME:
tipc_disable_bearer(b_ptr->name);
break;
}
rcu_read_unlock();
return NOTIFY_OK;
}
int tipc_bearer_setup(void)
{
int err;
err = register_netdevice_notifier(&notifier);
if (err)
return err;
dev_add_pack(&tipc_packet_type);
return 0;
}
void tipc_bearer_cleanup(void)
{
unregister_netdevice_notifier(&notifier);
dev_remove_pack(&tipc_packet_type);
}
void tipc_bearer_stop(void)
{
u32 i;
for (i = 0; i < MAX_BEARERS; i++) {
if (tipc_bearers[i].active)
bearer_disable(&tipc_bearers[i]);
}
}
