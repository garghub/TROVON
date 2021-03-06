static int media_name_valid(const char *name)
{
u32 len;
len = strlen(name);
if ((len + 1) > TIPC_MAX_MEDIA_NAME)
return 0;
return strspn(name, tipc_alphabet) == len;
}
static struct media *media_find(const char *name)
{
struct media *m_ptr;
u32 i;
for (i = 0, m_ptr = media_list; i < media_count; i++, m_ptr++) {
if (!strcmp(m_ptr->name, name))
return m_ptr;
}
return NULL;
}
int tipc_register_media(u32 media_type,
char *name,
int (*enable)(struct tipc_bearer *),
void (*disable)(struct tipc_bearer *),
int (*send_msg)(struct sk_buff *,
struct tipc_bearer *,
struct tipc_media_addr *),
char *(*addr2str)(struct tipc_media_addr *a,
char *str_buf, int str_size),
struct tipc_media_addr *bcast_addr,
const u32 bearer_priority,
const u32 link_tolerance,
const u32 send_window_limit)
{
struct media *m_ptr;
u32 media_id;
u32 i;
int res = -EINVAL;
write_lock_bh(&tipc_net_lock);
if (tipc_mode != TIPC_NET_MODE) {
warn("Media <%s> rejected, not in networked mode yet\n", name);
goto exit;
}
if (!media_name_valid(name)) {
warn("Media <%s> rejected, illegal name\n", name);
goto exit;
}
if (!bcast_addr) {
warn("Media <%s> rejected, no broadcast address\n", name);
goto exit;
}
if ((bearer_priority < TIPC_MIN_LINK_PRI) ||
(bearer_priority > TIPC_MAX_LINK_PRI)) {
warn("Media <%s> rejected, illegal priority (%u)\n", name,
bearer_priority);
goto exit;
}
if ((link_tolerance < TIPC_MIN_LINK_TOL) ||
(link_tolerance > TIPC_MAX_LINK_TOL)) {
warn("Media <%s> rejected, illegal tolerance (%u)\n", name,
link_tolerance);
goto exit;
}
media_id = media_count++;
if (media_id >= MAX_MEDIA) {
warn("Media <%s> rejected, media limit reached (%u)\n", name,
MAX_MEDIA);
media_count--;
goto exit;
}
for (i = 0; i < media_id; i++) {
if (media_list[i].type_id == media_type) {
warn("Media <%s> rejected, duplicate type (%u)\n", name,
media_type);
media_count--;
goto exit;
}
if (!strcmp(name, media_list[i].name)) {
warn("Media <%s> rejected, duplicate name\n", name);
media_count--;
goto exit;
}
}
m_ptr = &media_list[media_id];
m_ptr->type_id = media_type;
m_ptr->send_msg = send_msg;
m_ptr->enable_bearer = enable;
m_ptr->disable_bearer = disable;
m_ptr->addr2str = addr2str;
memcpy(&m_ptr->bcast_addr, bcast_addr, sizeof(*bcast_addr));
strcpy(m_ptr->name, name);
m_ptr->priority = bearer_priority;
m_ptr->tolerance = link_tolerance;
m_ptr->window = send_window_limit;
res = 0;
exit:
write_unlock_bh(&tipc_net_lock);
return res;
}
void tipc_media_addr_printf(struct print_buf *pb, struct tipc_media_addr *a)
{
struct media *m_ptr;
u32 media_type;
u32 i;
media_type = ntohl(a->type);
for (i = 0, m_ptr = media_list; i < media_count; i++, m_ptr++) {
if (m_ptr->type_id == media_type)
break;
}
if ((i < media_count) && (m_ptr->addr2str != NULL)) {
char addr_str[MAX_ADDR_STR];
tipc_printf(pb, "%s(%s)", m_ptr->name,
m_ptr->addr2str(a, addr_str, sizeof(addr_str)));
} else {
unchar *addr = (unchar *)&a->dev_addr;
tipc_printf(pb, "UNKNOWN(%u)", media_type);
for (i = 0; i < (sizeof(*a) - sizeof(a->type)); i++)
tipc_printf(pb, "-%02x", addr[i]);
}
}
struct sk_buff *tipc_media_get_names(void)
{
struct sk_buff *buf;
struct media *m_ptr;
int i;
buf = tipc_cfg_reply_alloc(MAX_MEDIA * TLV_SPACE(TIPC_MAX_MEDIA_NAME));
if (!buf)
return NULL;
read_lock_bh(&tipc_net_lock);
for (i = 0, m_ptr = media_list; i < media_count; i++, m_ptr++) {
tipc_cfg_append_tlv(buf, TIPC_TLV_MEDIA_NAME, m_ptr->name,
strlen(m_ptr->name) + 1);
}
read_unlock_bh(&tipc_net_lock);
return buf;
}
static int bearer_name_validate(const char *name,
struct bearer_name *name_parts)
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
(if_len <= 1) || (if_len > TIPC_MAX_IF_NAME) ||
(strspn(media_name, tipc_alphabet) != (media_len - 1)) ||
(strspn(if_name, tipc_alphabet) != (if_len - 1)))
return 0;
if (name_parts) {
strcpy(name_parts->media_name, media_name);
strcpy(name_parts->if_name, if_name);
}
return 1;
}
static struct tipc_bearer *bearer_find(const char *name)
{
struct tipc_bearer *b_ptr;
u32 i;
for (i = 0, b_ptr = tipc_bearers; i < MAX_BEARERS; i++, b_ptr++) {
if (b_ptr->active && (!strcmp(b_ptr->name, name)))
return b_ptr;
}
return NULL;
}
struct tipc_bearer *tipc_bearer_find_interface(const char *if_name)
{
struct tipc_bearer *b_ptr;
char *b_if_name;
u32 i;
for (i = 0, b_ptr = tipc_bearers; i < MAX_BEARERS; i++, b_ptr++) {
if (!b_ptr->active)
continue;
b_if_name = strchr(b_ptr->name, ':') + 1;
if (!strcmp(b_if_name, if_name))
return b_ptr;
}
return NULL;
}
struct sk_buff *tipc_bearer_get_names(void)
{
struct sk_buff *buf;
struct media *m_ptr;
struct tipc_bearer *b_ptr;
int i, j;
buf = tipc_cfg_reply_alloc(MAX_BEARERS * TLV_SPACE(TIPC_MAX_BEARER_NAME));
if (!buf)
return NULL;
read_lock_bh(&tipc_net_lock);
for (i = 0, m_ptr = media_list; i < media_count; i++, m_ptr++) {
for (j = 0; j < MAX_BEARERS; j++) {
b_ptr = &tipc_bearers[j];
if (b_ptr->active && (b_ptr->media == m_ptr)) {
tipc_cfg_append_tlv(buf, TIPC_TLV_BEARER_NAME,
b_ptr->name,
strlen(b_ptr->name) + 1);
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
static int bearer_push(struct tipc_bearer *b_ptr)
{
u32 res = 0;
struct link *ln, *tln;
if (b_ptr->blocked)
return 0;
while (!list_empty(&b_ptr->cong_links) && (res != PUSH_FAILED)) {
list_for_each_entry_safe(ln, tln, &b_ptr->cong_links, link_list) {
res = tipc_link_push_packet(ln);
if (res == PUSH_FAILED)
break;
if (res == PUSH_FINISHED)
list_move_tail(&ln->link_list, &b_ptr->links);
}
}
return list_empty(&b_ptr->cong_links);
}
void tipc_bearer_lock_push(struct tipc_bearer *b_ptr)
{
int res;
spin_lock_bh(&b_ptr->lock);
res = bearer_push(b_ptr);
spin_unlock_bh(&b_ptr->lock);
if (res)
tipc_bcbearer_push();
}
void tipc_continue(struct tipc_bearer *b_ptr)
{
spin_lock_bh(&b_ptr->lock);
b_ptr->continue_count++;
if (!list_empty(&b_ptr->cong_links))
tipc_k_signal((Handler)tipc_bearer_lock_push, (unsigned long)b_ptr);
b_ptr->blocked = 0;
spin_unlock_bh(&b_ptr->lock);
}
static void tipc_bearer_schedule_unlocked(struct tipc_bearer *b_ptr, struct link *l_ptr)
{
list_move_tail(&l_ptr->link_list, &b_ptr->cong_links);
}
void tipc_bearer_schedule(struct tipc_bearer *b_ptr, struct link *l_ptr)
{
spin_lock_bh(&b_ptr->lock);
tipc_bearer_schedule_unlocked(b_ptr, l_ptr);
spin_unlock_bh(&b_ptr->lock);
}
int tipc_bearer_resolve_congestion(struct tipc_bearer *b_ptr, struct link *l_ptr)
{
int res = 1;
if (list_empty(&b_ptr->cong_links))
return 1;
spin_lock_bh(&b_ptr->lock);
if (!bearer_push(b_ptr)) {
tipc_bearer_schedule_unlocked(b_ptr, l_ptr);
res = 0;
}
spin_unlock_bh(&b_ptr->lock);
return res;
}
int tipc_bearer_congested(struct tipc_bearer *b_ptr, struct link *l_ptr)
{
if (unlikely(b_ptr->blocked))
return 1;
if (likely(list_empty(&b_ptr->cong_links)))
return 0;
return !tipc_bearer_resolve_congestion(b_ptr, l_ptr);
}
int tipc_enable_bearer(const char *name, u32 disc_domain, u32 priority)
{
struct tipc_bearer *b_ptr;
struct media *m_ptr;
struct bearer_name b_name;
char addr_string[16];
u32 bearer_id;
u32 with_this_prio;
u32 i;
int res = -EINVAL;
if (tipc_mode != TIPC_NET_MODE) {
warn("Bearer <%s> rejected, not supported in standalone mode\n",
name);
return -ENOPROTOOPT;
}
if (!bearer_name_validate(name, &b_name)) {
warn("Bearer <%s> rejected, illegal name\n", name);
return -EINVAL;
}
if (tipc_addr_domain_valid(disc_domain) &&
(disc_domain != tipc_own_addr)) {
if (tipc_in_scope(disc_domain, tipc_own_addr)) {
disc_domain = tipc_own_addr & TIPC_CLUSTER_MASK;
res = 0;
} else if (in_own_cluster(disc_domain))
res = 0;
}
if (res) {
warn("Bearer <%s> rejected, illegal discovery domain\n", name);
return -EINVAL;
}
if ((priority < TIPC_MIN_LINK_PRI ||
priority > TIPC_MAX_LINK_PRI) &&
(priority != TIPC_MEDIA_LINK_PRI)) {
warn("Bearer <%s> rejected, illegal priority\n", name);
return -EINVAL;
}
write_lock_bh(&tipc_net_lock);
m_ptr = media_find(b_name.media_name);
if (!m_ptr) {
warn("Bearer <%s> rejected, media <%s> not registered\n", name,
b_name.media_name);
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
warn("Bearer <%s> rejected, already enabled\n", name);
goto exit;
}
if ((tipc_bearers[i].priority == priority) &&
(++with_this_prio > 2)) {
if (priority-- == 0) {
warn("Bearer <%s> rejected, duplicate priority\n",
name);
goto exit;
}
warn("Bearer <%s> priority adjustment required %u->%u\n",
name, priority + 1, priority);
goto restart;
}
}
if (bearer_id >= MAX_BEARERS) {
warn("Bearer <%s> rejected, bearer limit reached (%u)\n",
name, MAX_BEARERS);
goto exit;
}
b_ptr = &tipc_bearers[bearer_id];
strcpy(b_ptr->name, name);
res = m_ptr->enable_bearer(b_ptr);
if (res) {
warn("Bearer <%s> rejected, enable failure (%d)\n", name, -res);
goto exit;
}
b_ptr->identity = bearer_id;
b_ptr->media = m_ptr;
b_ptr->net_plane = bearer_id + 'A';
b_ptr->active = 1;
b_ptr->priority = priority;
INIT_LIST_HEAD(&b_ptr->cong_links);
INIT_LIST_HEAD(&b_ptr->links);
spin_lock_init(&b_ptr->lock);
res = tipc_disc_create(b_ptr, &m_ptr->bcast_addr, disc_domain);
if (res) {
bearer_disable(b_ptr);
warn("Bearer <%s> rejected, discovery object creation failed\n",
name);
goto exit;
}
info("Enabled bearer <%s>, discovery domain %s, priority %u\n",
name, tipc_addr_string_fill(addr_string, disc_domain), priority);
exit:
write_unlock_bh(&tipc_net_lock);
return res;
}
int tipc_block_bearer(const char *name)
{
struct tipc_bearer *b_ptr = NULL;
struct link *l_ptr;
struct link *temp_l_ptr;
read_lock_bh(&tipc_net_lock);
b_ptr = bearer_find(name);
if (!b_ptr) {
warn("Attempt to block unknown bearer <%s>\n", name);
read_unlock_bh(&tipc_net_lock);
return -EINVAL;
}
info("Blocking bearer <%s>\n", name);
spin_lock_bh(&b_ptr->lock);
b_ptr->blocked = 1;
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
struct link *l_ptr;
struct link *temp_l_ptr;
info("Disabling bearer <%s>\n", b_ptr->name);
spin_lock_bh(&b_ptr->lock);
b_ptr->blocked = 1;
b_ptr->media->disable_bearer(b_ptr);
list_for_each_entry_safe(l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
tipc_link_delete(l_ptr);
}
if (b_ptr->link_req)
tipc_disc_delete(b_ptr->link_req);
spin_unlock_bh(&b_ptr->lock);
memset(b_ptr, 0, sizeof(struct tipc_bearer));
}
int tipc_disable_bearer(const char *name)
{
struct tipc_bearer *b_ptr;
int res;
write_lock_bh(&tipc_net_lock);
b_ptr = bearer_find(name);
if (b_ptr == NULL) {
warn("Attempt to disable unknown bearer <%s>\n", name);
res = -EINVAL;
} else {
bearer_disable(b_ptr);
res = 0;
}
write_unlock_bh(&tipc_net_lock);
return res;
}
void tipc_bearer_stop(void)
{
u32 i;
for (i = 0; i < MAX_BEARERS; i++) {
if (tipc_bearers[i].active)
bearer_disable(&tipc_bearers[i]);
}
media_count = 0;
}
