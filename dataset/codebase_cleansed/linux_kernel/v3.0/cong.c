static struct rds_cong_map *rds_cong_tree_walk(__be32 addr,
struct rds_cong_map *insert)
{
struct rb_node **p = &rds_cong_tree.rb_node;
struct rb_node *parent = NULL;
struct rds_cong_map *map;
while (*p) {
parent = *p;
map = rb_entry(parent, struct rds_cong_map, m_rb_node);
if (addr < map->m_addr)
p = &(*p)->rb_left;
else if (addr > map->m_addr)
p = &(*p)->rb_right;
else
return map;
}
if (insert) {
rb_link_node(&insert->m_rb_node, parent, p);
rb_insert_color(&insert->m_rb_node, &rds_cong_tree);
}
return NULL;
}
static struct rds_cong_map *rds_cong_from_addr(__be32 addr)
{
struct rds_cong_map *map;
struct rds_cong_map *ret = NULL;
unsigned long zp;
unsigned long i;
unsigned long flags;
map = kzalloc(sizeof(struct rds_cong_map), GFP_KERNEL);
if (!map)
return NULL;
map->m_addr = addr;
init_waitqueue_head(&map->m_waitq);
INIT_LIST_HEAD(&map->m_conn_list);
for (i = 0; i < RDS_CONG_MAP_PAGES; i++) {
zp = get_zeroed_page(GFP_KERNEL);
if (zp == 0)
goto out;
map->m_page_addrs[i] = zp;
}
spin_lock_irqsave(&rds_cong_lock, flags);
ret = rds_cong_tree_walk(addr, map);
spin_unlock_irqrestore(&rds_cong_lock, flags);
if (!ret) {
ret = map;
map = NULL;
}
out:
if (map) {
for (i = 0; i < RDS_CONG_MAP_PAGES && map->m_page_addrs[i]; i++)
free_page(map->m_page_addrs[i]);
kfree(map);
}
rdsdebug("map %p for addr %x\n", ret, be32_to_cpu(addr));
return ret;
}
void rds_cong_add_conn(struct rds_connection *conn)
{
unsigned long flags;
rdsdebug("conn %p now on map %p\n", conn, conn->c_lcong);
spin_lock_irqsave(&rds_cong_lock, flags);
list_add_tail(&conn->c_map_item, &conn->c_lcong->m_conn_list);
spin_unlock_irqrestore(&rds_cong_lock, flags);
}
void rds_cong_remove_conn(struct rds_connection *conn)
{
unsigned long flags;
rdsdebug("removing conn %p from map %p\n", conn, conn->c_lcong);
spin_lock_irqsave(&rds_cong_lock, flags);
list_del_init(&conn->c_map_item);
spin_unlock_irqrestore(&rds_cong_lock, flags);
}
int rds_cong_get_maps(struct rds_connection *conn)
{
conn->c_lcong = rds_cong_from_addr(conn->c_laddr);
conn->c_fcong = rds_cong_from_addr(conn->c_faddr);
if (!(conn->c_lcong && conn->c_fcong))
return -ENOMEM;
return 0;
}
void rds_cong_queue_updates(struct rds_cong_map *map)
{
struct rds_connection *conn;
unsigned long flags;
spin_lock_irqsave(&rds_cong_lock, flags);
list_for_each_entry(conn, &map->m_conn_list, c_map_item) {
if (!test_and_set_bit(0, &conn->c_map_queued)) {
rds_stats_inc(s_cong_update_queued);
rds_send_xmit(conn);
}
}
spin_unlock_irqrestore(&rds_cong_lock, flags);
}
void rds_cong_map_updated(struct rds_cong_map *map, uint64_t portmask)
{
rdsdebug("waking map %p for %pI4\n",
map, &map->m_addr);
rds_stats_inc(s_cong_update_received);
atomic_inc(&rds_cong_generation);
if (waitqueue_active(&map->m_waitq))
wake_up(&map->m_waitq);
if (waitqueue_active(&rds_poll_waitq))
wake_up_all(&rds_poll_waitq);
if (portmask && !list_empty(&rds_cong_monitor)) {
unsigned long flags;
struct rds_sock *rs;
read_lock_irqsave(&rds_cong_monitor_lock, flags);
list_for_each_entry(rs, &rds_cong_monitor, rs_cong_list) {
spin_lock(&rs->rs_lock);
rs->rs_cong_notify |= (rs->rs_cong_mask & portmask);
rs->rs_cong_mask &= ~portmask;
spin_unlock(&rs->rs_lock);
if (rs->rs_cong_notify)
rds_wake_sk_sleep(rs);
}
read_unlock_irqrestore(&rds_cong_monitor_lock, flags);
}
}
int rds_cong_updated_since(unsigned long *recent)
{
unsigned long gen = atomic_read(&rds_cong_generation);
if (likely(*recent == gen))
return 0;
*recent = gen;
return 1;
}
void rds_cong_set_bit(struct rds_cong_map *map, __be16 port)
{
unsigned long i;
unsigned long off;
rdsdebug("setting congestion for %pI4:%u in map %p\n",
&map->m_addr, ntohs(port), map);
i = be16_to_cpu(port) / RDS_CONG_MAP_PAGE_BITS;
off = be16_to_cpu(port) % RDS_CONG_MAP_PAGE_BITS;
__set_bit_le(off, (void *)map->m_page_addrs[i]);
}
void rds_cong_clear_bit(struct rds_cong_map *map, __be16 port)
{
unsigned long i;
unsigned long off;
rdsdebug("clearing congestion for %pI4:%u in map %p\n",
&map->m_addr, ntohs(port), map);
i = be16_to_cpu(port) / RDS_CONG_MAP_PAGE_BITS;
off = be16_to_cpu(port) % RDS_CONG_MAP_PAGE_BITS;
__clear_bit_le(off, (void *)map->m_page_addrs[i]);
}
static int rds_cong_test_bit(struct rds_cong_map *map, __be16 port)
{
unsigned long i;
unsigned long off;
i = be16_to_cpu(port) / RDS_CONG_MAP_PAGE_BITS;
off = be16_to_cpu(port) % RDS_CONG_MAP_PAGE_BITS;
return test_bit_le(off, (void *)map->m_page_addrs[i]);
}
void rds_cong_add_socket(struct rds_sock *rs)
{
unsigned long flags;
write_lock_irqsave(&rds_cong_monitor_lock, flags);
if (list_empty(&rs->rs_cong_list))
list_add(&rs->rs_cong_list, &rds_cong_monitor);
write_unlock_irqrestore(&rds_cong_monitor_lock, flags);
}
void rds_cong_remove_socket(struct rds_sock *rs)
{
unsigned long flags;
struct rds_cong_map *map;
write_lock_irqsave(&rds_cong_monitor_lock, flags);
list_del_init(&rs->rs_cong_list);
write_unlock_irqrestore(&rds_cong_monitor_lock, flags);
spin_lock_irqsave(&rds_cong_lock, flags);
map = rds_cong_tree_walk(rs->rs_bound_addr, NULL);
spin_unlock_irqrestore(&rds_cong_lock, flags);
if (map && rds_cong_test_bit(map, rs->rs_bound_port)) {
rds_cong_clear_bit(map, rs->rs_bound_port);
rds_cong_queue_updates(map);
}
}
int rds_cong_wait(struct rds_cong_map *map, __be16 port, int nonblock,
struct rds_sock *rs)
{
if (!rds_cong_test_bit(map, port))
return 0;
if (nonblock) {
if (rs && rs->rs_cong_monitor) {
unsigned long flags;
spin_lock_irqsave(&rs->rs_lock, flags);
rs->rs_cong_mask |= RDS_CONG_MONITOR_MASK(ntohs(port));
spin_unlock_irqrestore(&rs->rs_lock, flags);
if (!rds_cong_test_bit(map, port))
return 0;
}
rds_stats_inc(s_cong_send_error);
return -ENOBUFS;
}
rds_stats_inc(s_cong_send_blocked);
rdsdebug("waiting on map %p for port %u\n", map, be16_to_cpu(port));
return wait_event_interruptible(map->m_waitq,
!rds_cong_test_bit(map, port));
}
void rds_cong_exit(void)
{
struct rb_node *node;
struct rds_cong_map *map;
unsigned long i;
while ((node = rb_first(&rds_cong_tree))) {
map = rb_entry(node, struct rds_cong_map, m_rb_node);
rdsdebug("freeing map %p\n", map);
rb_erase(&map->m_rb_node, &rds_cong_tree);
for (i = 0; i < RDS_CONG_MAP_PAGES && map->m_page_addrs[i]; i++)
free_page(map->m_page_addrs[i]);
kfree(map);
}
}
struct rds_message *rds_cong_update_alloc(struct rds_connection *conn)
{
struct rds_cong_map *map = conn->c_lcong;
struct rds_message *rm;
rm = rds_message_map_pages(map->m_page_addrs, RDS_CONG_MAP_BYTES);
if (!IS_ERR(rm))
rm->m_inc.i_hdr.h_flags = RDS_FLAG_CONG_BITMAP;
return rm;
}
