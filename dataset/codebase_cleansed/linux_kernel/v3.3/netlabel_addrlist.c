struct netlbl_af4list *netlbl_af4list_search(__be32 addr,
struct list_head *head)
{
struct netlbl_af4list *iter;
list_for_each_entry_rcu(iter, head, list)
if (iter->valid && (addr & iter->mask) == iter->addr)
return iter;
return NULL;
}
struct netlbl_af4list *netlbl_af4list_search_exact(__be32 addr,
__be32 mask,
struct list_head *head)
{
struct netlbl_af4list *iter;
list_for_each_entry_rcu(iter, head, list)
if (iter->valid && iter->addr == addr && iter->mask == mask)
return iter;
return NULL;
}
struct netlbl_af6list *netlbl_af6list_search(const struct in6_addr *addr,
struct list_head *head)
{
struct netlbl_af6list *iter;
list_for_each_entry_rcu(iter, head, list)
if (iter->valid &&
ipv6_masked_addr_cmp(&iter->addr, &iter->mask, addr) == 0)
return iter;
return NULL;
}
struct netlbl_af6list *netlbl_af6list_search_exact(const struct in6_addr *addr,
const struct in6_addr *mask,
struct list_head *head)
{
struct netlbl_af6list *iter;
list_for_each_entry_rcu(iter, head, list)
if (iter->valid &&
ipv6_addr_equal(&iter->addr, addr) &&
ipv6_addr_equal(&iter->mask, mask))
return iter;
return NULL;
}
int netlbl_af4list_add(struct netlbl_af4list *entry, struct list_head *head)
{
struct netlbl_af4list *iter;
iter = netlbl_af4list_search(entry->addr, head);
if (iter != NULL &&
iter->addr == entry->addr && iter->mask == entry->mask)
return -EEXIST;
list_for_each_entry_rcu(iter, head, list)
if (iter->valid &&
ntohl(entry->mask) > ntohl(iter->mask)) {
__list_add_rcu(&entry->list,
iter->list.prev,
&iter->list);
return 0;
}
list_add_tail_rcu(&entry->list, head);
return 0;
}
int netlbl_af6list_add(struct netlbl_af6list *entry, struct list_head *head)
{
struct netlbl_af6list *iter;
iter = netlbl_af6list_search(&entry->addr, head);
if (iter != NULL &&
ipv6_addr_equal(&iter->addr, &entry->addr) &&
ipv6_addr_equal(&iter->mask, &entry->mask))
return -EEXIST;
list_for_each_entry_rcu(iter, head, list)
if (iter->valid &&
ipv6_addr_cmp(&entry->mask, &iter->mask) > 0) {
__list_add_rcu(&entry->list,
iter->list.prev,
&iter->list);
return 0;
}
list_add_tail_rcu(&entry->list, head);
return 0;
}
void netlbl_af4list_remove_entry(struct netlbl_af4list *entry)
{
entry->valid = 0;
list_del_rcu(&entry->list);
}
struct netlbl_af4list *netlbl_af4list_remove(__be32 addr, __be32 mask,
struct list_head *head)
{
struct netlbl_af4list *entry;
entry = netlbl_af4list_search_exact(addr, mask, head);
if (entry == NULL)
return NULL;
netlbl_af4list_remove_entry(entry);
return entry;
}
void netlbl_af6list_remove_entry(struct netlbl_af6list *entry)
{
entry->valid = 0;
list_del_rcu(&entry->list);
}
struct netlbl_af6list *netlbl_af6list_remove(const struct in6_addr *addr,
const struct in6_addr *mask,
struct list_head *head)
{
struct netlbl_af6list *entry;
entry = netlbl_af6list_search_exact(addr, mask, head);
if (entry == NULL)
return NULL;
netlbl_af6list_remove_entry(entry);
return entry;
}
void netlbl_af4list_audit_addr(struct audit_buffer *audit_buf,
int src, const char *dev,
__be32 addr, __be32 mask)
{
u32 mask_val = ntohl(mask);
char *dir = (src ? "src" : "dst");
if (dev != NULL)
audit_log_format(audit_buf, " netif=%s", dev);
audit_log_format(audit_buf, " %s=%pI4", dir, &addr);
if (mask_val != 0xffffffff) {
u32 mask_len = 0;
while (mask_val > 0) {
mask_val <<= 1;
mask_len++;
}
audit_log_format(audit_buf, " %s_prefixlen=%d", dir, mask_len);
}
}
void netlbl_af6list_audit_addr(struct audit_buffer *audit_buf,
int src,
const char *dev,
const struct in6_addr *addr,
const struct in6_addr *mask)
{
char *dir = (src ? "src" : "dst");
if (dev != NULL)
audit_log_format(audit_buf, " netif=%s", dev);
audit_log_format(audit_buf, " %s=%pI6", dir, addr);
if (ntohl(mask->s6_addr32[3]) != 0xffffffff) {
u32 mask_len = 0;
u32 mask_val;
int iter = -1;
while (ntohl(mask->s6_addr32[++iter]) == 0xffffffff)
mask_len += 32;
mask_val = ntohl(mask->s6_addr32[iter]);
while (mask_val > 0) {
mask_val <<= 1;
mask_len++;
}
audit_log_format(audit_buf, " %s_prefixlen=%d", dir, mask_len);
}
}
