static void batadv_tvlv_handler_release(struct kref *ref)
{
struct batadv_tvlv_handler *tvlv_handler;
tvlv_handler = container_of(ref, struct batadv_tvlv_handler, refcount);
kfree_rcu(tvlv_handler, rcu);
}
static void batadv_tvlv_handler_put(struct batadv_tvlv_handler *tvlv_handler)
{
kref_put(&tvlv_handler->refcount, batadv_tvlv_handler_release);
}
static struct batadv_tvlv_handler *
batadv_tvlv_handler_get(struct batadv_priv *bat_priv, u8 type, u8 version)
{
struct batadv_tvlv_handler *tvlv_handler_tmp, *tvlv_handler = NULL;
rcu_read_lock();
hlist_for_each_entry_rcu(tvlv_handler_tmp,
&bat_priv->tvlv.handler_list, list) {
if (tvlv_handler_tmp->type != type)
continue;
if (tvlv_handler_tmp->version != version)
continue;
if (!kref_get_unless_zero(&tvlv_handler_tmp->refcount))
continue;
tvlv_handler = tvlv_handler_tmp;
break;
}
rcu_read_unlock();
return tvlv_handler;
}
static void batadv_tvlv_container_release(struct kref *ref)
{
struct batadv_tvlv_container *tvlv;
tvlv = container_of(ref, struct batadv_tvlv_container, refcount);
kfree(tvlv);
}
static void batadv_tvlv_container_put(struct batadv_tvlv_container *tvlv)
{
kref_put(&tvlv->refcount, batadv_tvlv_container_release);
}
static struct batadv_tvlv_container *
batadv_tvlv_container_get(struct batadv_priv *bat_priv, u8 type, u8 version)
{
struct batadv_tvlv_container *tvlv_tmp, *tvlv = NULL;
lockdep_assert_held(&bat_priv->tvlv.container_list_lock);
hlist_for_each_entry(tvlv_tmp, &bat_priv->tvlv.container_list, list) {
if (tvlv_tmp->tvlv_hdr.type != type)
continue;
if (tvlv_tmp->tvlv_hdr.version != version)
continue;
kref_get(&tvlv_tmp->refcount);
tvlv = tvlv_tmp;
break;
}
return tvlv;
}
static u16 batadv_tvlv_container_list_size(struct batadv_priv *bat_priv)
{
struct batadv_tvlv_container *tvlv;
u16 tvlv_len = 0;
lockdep_assert_held(&bat_priv->tvlv.container_list_lock);
hlist_for_each_entry(tvlv, &bat_priv->tvlv.container_list, list) {
tvlv_len += sizeof(struct batadv_tvlv_hdr);
tvlv_len += ntohs(tvlv->tvlv_hdr.len);
}
return tvlv_len;
}
static void batadv_tvlv_container_remove(struct batadv_priv *bat_priv,
struct batadv_tvlv_container *tvlv)
{
lockdep_assert_held(&bat_priv->tvlv.container_list_lock);
if (!tvlv)
return;
hlist_del(&tvlv->list);
batadv_tvlv_container_put(tvlv);
batadv_tvlv_container_put(tvlv);
}
void batadv_tvlv_container_unregister(struct batadv_priv *bat_priv,
u8 type, u8 version)
{
struct batadv_tvlv_container *tvlv;
spin_lock_bh(&bat_priv->tvlv.container_list_lock);
tvlv = batadv_tvlv_container_get(bat_priv, type, version);
batadv_tvlv_container_remove(bat_priv, tvlv);
spin_unlock_bh(&bat_priv->tvlv.container_list_lock);
}
void batadv_tvlv_container_register(struct batadv_priv *bat_priv,
u8 type, u8 version,
void *tvlv_value, u16 tvlv_value_len)
{
struct batadv_tvlv_container *tvlv_old, *tvlv_new;
if (!tvlv_value)
tvlv_value_len = 0;
tvlv_new = kzalloc(sizeof(*tvlv_new) + tvlv_value_len, GFP_ATOMIC);
if (!tvlv_new)
return;
tvlv_new->tvlv_hdr.version = version;
tvlv_new->tvlv_hdr.type = type;
tvlv_new->tvlv_hdr.len = htons(tvlv_value_len);
memcpy(tvlv_new + 1, tvlv_value, ntohs(tvlv_new->tvlv_hdr.len));
INIT_HLIST_NODE(&tvlv_new->list);
kref_init(&tvlv_new->refcount);
spin_lock_bh(&bat_priv->tvlv.container_list_lock);
tvlv_old = batadv_tvlv_container_get(bat_priv, type, version);
batadv_tvlv_container_remove(bat_priv, tvlv_old);
kref_get(&tvlv_new->refcount);
hlist_add_head(&tvlv_new->list, &bat_priv->tvlv.container_list);
spin_unlock_bh(&bat_priv->tvlv.container_list_lock);
batadv_tvlv_container_put(tvlv_new);
}
static bool batadv_tvlv_realloc_packet_buff(unsigned char **packet_buff,
int *packet_buff_len,
int min_packet_len,
int additional_packet_len)
{
unsigned char *new_buff;
new_buff = kmalloc(min_packet_len + additional_packet_len, GFP_ATOMIC);
if (!new_buff)
return false;
memcpy(new_buff, *packet_buff, min_packet_len);
kfree(*packet_buff);
*packet_buff = new_buff;
*packet_buff_len = min_packet_len + additional_packet_len;
return true;
}
u16 batadv_tvlv_container_ogm_append(struct batadv_priv *bat_priv,
unsigned char **packet_buff,
int *packet_buff_len, int packet_min_len)
{
struct batadv_tvlv_container *tvlv;
struct batadv_tvlv_hdr *tvlv_hdr;
u16 tvlv_value_len;
void *tvlv_value;
bool ret;
spin_lock_bh(&bat_priv->tvlv.container_list_lock);
tvlv_value_len = batadv_tvlv_container_list_size(bat_priv);
ret = batadv_tvlv_realloc_packet_buff(packet_buff, packet_buff_len,
packet_min_len, tvlv_value_len);
if (!ret)
goto end;
if (!tvlv_value_len)
goto end;
tvlv_value = (*packet_buff) + packet_min_len;
hlist_for_each_entry(tvlv, &bat_priv->tvlv.container_list, list) {
tvlv_hdr = tvlv_value;
tvlv_hdr->type = tvlv->tvlv_hdr.type;
tvlv_hdr->version = tvlv->tvlv_hdr.version;
tvlv_hdr->len = tvlv->tvlv_hdr.len;
tvlv_value = tvlv_hdr + 1;
memcpy(tvlv_value, tvlv + 1, ntohs(tvlv->tvlv_hdr.len));
tvlv_value = (u8 *)tvlv_value + ntohs(tvlv->tvlv_hdr.len);
}
end:
spin_unlock_bh(&bat_priv->tvlv.container_list_lock);
return tvlv_value_len;
}
static int batadv_tvlv_call_handler(struct batadv_priv *bat_priv,
struct batadv_tvlv_handler *tvlv_handler,
bool ogm_source,
struct batadv_orig_node *orig_node,
u8 *src, u8 *dst,
void *tvlv_value, u16 tvlv_value_len)
{
if (!tvlv_handler)
return NET_RX_SUCCESS;
if (ogm_source) {
if (!tvlv_handler->ogm_handler)
return NET_RX_SUCCESS;
if (!orig_node)
return NET_RX_SUCCESS;
tvlv_handler->ogm_handler(bat_priv, orig_node,
BATADV_NO_FLAGS,
tvlv_value, tvlv_value_len);
tvlv_handler->flags |= BATADV_TVLV_HANDLER_OGM_CALLED;
} else {
if (!src)
return NET_RX_SUCCESS;
if (!dst)
return NET_RX_SUCCESS;
if (!tvlv_handler->unicast_handler)
return NET_RX_SUCCESS;
return tvlv_handler->unicast_handler(bat_priv, src,
dst, tvlv_value,
tvlv_value_len);
}
return NET_RX_SUCCESS;
}
int batadv_tvlv_containers_process(struct batadv_priv *bat_priv,
bool ogm_source,
struct batadv_orig_node *orig_node,
u8 *src, u8 *dst,
void *tvlv_value, u16 tvlv_value_len)
{
struct batadv_tvlv_handler *tvlv_handler;
struct batadv_tvlv_hdr *tvlv_hdr;
u16 tvlv_value_cont_len;
u8 cifnotfound = BATADV_TVLV_HANDLER_OGM_CIFNOTFND;
int ret = NET_RX_SUCCESS;
while (tvlv_value_len >= sizeof(*tvlv_hdr)) {
tvlv_hdr = tvlv_value;
tvlv_value_cont_len = ntohs(tvlv_hdr->len);
tvlv_value = tvlv_hdr + 1;
tvlv_value_len -= sizeof(*tvlv_hdr);
if (tvlv_value_cont_len > tvlv_value_len)
break;
tvlv_handler = batadv_tvlv_handler_get(bat_priv,
tvlv_hdr->type,
tvlv_hdr->version);
ret |= batadv_tvlv_call_handler(bat_priv, tvlv_handler,
ogm_source, orig_node,
src, dst, tvlv_value,
tvlv_value_cont_len);
if (tvlv_handler)
batadv_tvlv_handler_put(tvlv_handler);
tvlv_value = (u8 *)tvlv_value + tvlv_value_cont_len;
tvlv_value_len -= tvlv_value_cont_len;
}
if (!ogm_source)
return ret;
rcu_read_lock();
hlist_for_each_entry_rcu(tvlv_handler,
&bat_priv->tvlv.handler_list, list) {
if ((tvlv_handler->flags & BATADV_TVLV_HANDLER_OGM_CIFNOTFND) &&
!(tvlv_handler->flags & BATADV_TVLV_HANDLER_OGM_CALLED))
tvlv_handler->ogm_handler(bat_priv, orig_node,
cifnotfound, NULL, 0);
tvlv_handler->flags &= ~BATADV_TVLV_HANDLER_OGM_CALLED;
}
rcu_read_unlock();
return NET_RX_SUCCESS;
}
void batadv_tvlv_ogm_receive(struct batadv_priv *bat_priv,
struct batadv_ogm_packet *batadv_ogm_packet,
struct batadv_orig_node *orig_node)
{
void *tvlv_value;
u16 tvlv_value_len;
if (!batadv_ogm_packet)
return;
tvlv_value_len = ntohs(batadv_ogm_packet->tvlv_len);
if (!tvlv_value_len)
return;
tvlv_value = batadv_ogm_packet + 1;
batadv_tvlv_containers_process(bat_priv, true, orig_node, NULL, NULL,
tvlv_value, tvlv_value_len);
}
void batadv_tvlv_handler_register(struct batadv_priv *bat_priv,
void (*optr)(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig,
u8 flags,
void *tvlv_value,
u16 tvlv_value_len),
int (*uptr)(struct batadv_priv *bat_priv,
u8 *src, u8 *dst,
void *tvlv_value,
u16 tvlv_value_len),
u8 type, u8 version, u8 flags)
{
struct batadv_tvlv_handler *tvlv_handler;
tvlv_handler = batadv_tvlv_handler_get(bat_priv, type, version);
if (tvlv_handler) {
batadv_tvlv_handler_put(tvlv_handler);
return;
}
tvlv_handler = kzalloc(sizeof(*tvlv_handler), GFP_ATOMIC);
if (!tvlv_handler)
return;
tvlv_handler->ogm_handler = optr;
tvlv_handler->unicast_handler = uptr;
tvlv_handler->type = type;
tvlv_handler->version = version;
tvlv_handler->flags = flags;
kref_init(&tvlv_handler->refcount);
INIT_HLIST_NODE(&tvlv_handler->list);
spin_lock_bh(&bat_priv->tvlv.handler_list_lock);
kref_get(&tvlv_handler->refcount);
hlist_add_head_rcu(&tvlv_handler->list, &bat_priv->tvlv.handler_list);
spin_unlock_bh(&bat_priv->tvlv.handler_list_lock);
batadv_tvlv_handler_put(tvlv_handler);
}
void batadv_tvlv_handler_unregister(struct batadv_priv *bat_priv,
u8 type, u8 version)
{
struct batadv_tvlv_handler *tvlv_handler;
tvlv_handler = batadv_tvlv_handler_get(bat_priv, type, version);
if (!tvlv_handler)
return;
batadv_tvlv_handler_put(tvlv_handler);
spin_lock_bh(&bat_priv->tvlv.handler_list_lock);
hlist_del_rcu(&tvlv_handler->list);
spin_unlock_bh(&bat_priv->tvlv.handler_list_lock);
batadv_tvlv_handler_put(tvlv_handler);
}
void batadv_tvlv_unicast_send(struct batadv_priv *bat_priv, u8 *src,
u8 *dst, u8 type, u8 version,
void *tvlv_value, u16 tvlv_value_len)
{
struct batadv_unicast_tvlv_packet *unicast_tvlv_packet;
struct batadv_tvlv_hdr *tvlv_hdr;
struct batadv_orig_node *orig_node;
struct sk_buff *skb;
unsigned char *tvlv_buff;
unsigned int tvlv_len;
ssize_t hdr_len = sizeof(*unicast_tvlv_packet);
int res;
orig_node = batadv_orig_hash_find(bat_priv, dst);
if (!orig_node)
return;
tvlv_len = sizeof(*tvlv_hdr) + tvlv_value_len;
skb = netdev_alloc_skb_ip_align(NULL, ETH_HLEN + hdr_len + tvlv_len);
if (!skb)
goto out;
skb->priority = TC_PRIO_CONTROL;
skb_reserve(skb, ETH_HLEN);
tvlv_buff = skb_put(skb, sizeof(*unicast_tvlv_packet) + tvlv_len);
unicast_tvlv_packet = (struct batadv_unicast_tvlv_packet *)tvlv_buff;
unicast_tvlv_packet->packet_type = BATADV_UNICAST_TVLV;
unicast_tvlv_packet->version = BATADV_COMPAT_VERSION;
unicast_tvlv_packet->ttl = BATADV_TTL;
unicast_tvlv_packet->reserved = 0;
unicast_tvlv_packet->tvlv_len = htons(tvlv_len);
unicast_tvlv_packet->align = 0;
ether_addr_copy(unicast_tvlv_packet->src, src);
ether_addr_copy(unicast_tvlv_packet->dst, dst);
tvlv_buff = (unsigned char *)(unicast_tvlv_packet + 1);
tvlv_hdr = (struct batadv_tvlv_hdr *)tvlv_buff;
tvlv_hdr->version = version;
tvlv_hdr->type = type;
tvlv_hdr->len = htons(tvlv_value_len);
tvlv_buff += sizeof(*tvlv_hdr);
memcpy(tvlv_buff, tvlv_value, tvlv_value_len);
res = batadv_send_skb_to_orig(skb, orig_node, NULL);
if (res == -1)
kfree_skb(skb);
out:
batadv_orig_node_put(orig_node);
}
