static void sel_netport_free(struct rcu_head *p)
{
struct sel_netport *port = container_of(p, struct sel_netport, rcu);
kfree(port);
}
static unsigned int sel_netport_hashfn(u16 pnum)
{
return (pnum & (SEL_NETPORT_HASH_SIZE - 1));
}
static struct sel_netport *sel_netport_find(u8 protocol, u16 pnum)
{
unsigned int idx;
struct sel_netport *port;
idx = sel_netport_hashfn(pnum);
list_for_each_entry_rcu(port, &sel_netport_hash[idx].list, list)
if (port->psec.port == pnum && port->psec.protocol == protocol)
return port;
return NULL;
}
static void sel_netport_insert(struct sel_netport *port)
{
unsigned int idx;
idx = sel_netport_hashfn(port->psec.port);
list_add_rcu(&port->list, &sel_netport_hash[idx].list);
if (sel_netport_hash[idx].size == SEL_NETPORT_HASH_BKT_LIMIT) {
struct sel_netport *tail;
tail = list_entry(
rcu_dereference(sel_netport_hash[idx].list.prev),
struct sel_netport, list);
list_del_rcu(&tail->list);
call_rcu(&tail->rcu, sel_netport_free);
} else
sel_netport_hash[idx].size++;
}
static int sel_netport_sid_slow(u8 protocol, u16 pnum, u32 *sid)
{
int ret = -ENOMEM;
struct sel_netport *port;
struct sel_netport *new = NULL;
spin_lock_bh(&sel_netport_lock);
port = sel_netport_find(protocol, pnum);
if (port != NULL) {
*sid = port->psec.sid;
spin_unlock_bh(&sel_netport_lock);
return 0;
}
new = kzalloc(sizeof(*new), GFP_ATOMIC);
if (new == NULL)
goto out;
ret = security_port_sid(protocol, pnum, sid);
if (ret != 0)
goto out;
new->psec.port = pnum;
new->psec.protocol = protocol;
new->psec.sid = *sid;
sel_netport_insert(new);
out:
spin_unlock_bh(&sel_netport_lock);
if (unlikely(ret)) {
printk(KERN_WARNING
"SELinux: failure in sel_netport_sid_slow(),"
" unable to determine network port label\n");
kfree(new);
}
return ret;
}
int sel_netport_sid(u8 protocol, u16 pnum, u32 *sid)
{
struct sel_netport *port;
rcu_read_lock();
port = sel_netport_find(protocol, pnum);
if (port != NULL) {
*sid = port->psec.sid;
rcu_read_unlock();
return 0;
}
rcu_read_unlock();
return sel_netport_sid_slow(protocol, pnum, sid);
}
static void sel_netport_flush(void)
{
unsigned int idx;
struct sel_netport *port, *port_tmp;
spin_lock_bh(&sel_netport_lock);
for (idx = 0; idx < SEL_NETPORT_HASH_SIZE; idx++) {
list_for_each_entry_safe(port, port_tmp,
&sel_netport_hash[idx].list, list) {
list_del_rcu(&port->list);
call_rcu(&port->rcu, sel_netport_free);
}
sel_netport_hash[idx].size = 0;
}
spin_unlock_bh(&sel_netport_lock);
}
static int sel_netport_avc_callback(u32 event, u32 ssid, u32 tsid,
u16 class, u32 perms, u32 *retained)
{
if (event == AVC_CALLBACK_RESET) {
sel_netport_flush();
synchronize_net();
}
return 0;
}
static __init int sel_netport_init(void)
{
int iter;
int ret;
if (!selinux_enabled)
return 0;
for (iter = 0; iter < SEL_NETPORT_HASH_SIZE; iter++) {
INIT_LIST_HEAD(&sel_netport_hash[iter].list);
sel_netport_hash[iter].size = 0;
}
ret = avc_add_callback(sel_netport_avc_callback, AVC_CALLBACK_RESET,
SECSID_NULL, SECSID_NULL, SECCLASS_NULL, 0);
if (ret != 0)
panic("avc_add_callback() failed, error %d\n", ret);
return ret;
}
