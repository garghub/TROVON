static int __init option_setup(char *opt)
{
strlcpy(config, opt, MAX_PARAM_LENGTH);
return 1;
}
static int __init dynamic_netconsole_init(void)
{
config_group_init(&netconsole_subsys.su_group);
mutex_init(&netconsole_subsys.su_mutex);
return configfs_register_subsystem(&netconsole_subsys);
}
static void __exit dynamic_netconsole_exit(void)
{
configfs_unregister_subsystem(&netconsole_subsys);
}
static void netconsole_target_get(struct netconsole_target *nt)
{
if (config_item_name(&nt->item))
config_item_get(&nt->item);
}
static void netconsole_target_put(struct netconsole_target *nt)
{
if (config_item_name(&nt->item))
config_item_put(&nt->item);
}
static int __init dynamic_netconsole_init(void)
{
return 0;
}
static void __exit dynamic_netconsole_exit(void)
{
}
static void netconsole_target_get(struct netconsole_target *nt)
{
}
static void netconsole_target_put(struct netconsole_target *nt)
{
}
static struct netconsole_target *alloc_param_target(char *target_config)
{
int err = -ENOMEM;
struct netconsole_target *nt;
nt = kzalloc(sizeof(*nt), GFP_KERNEL);
if (!nt)
goto fail;
nt->np.name = "netconsole";
strlcpy(nt->np.dev_name, "eth0", IFNAMSIZ);
nt->np.local_port = 6665;
nt->np.remote_port = 6666;
eth_broadcast_addr(nt->np.remote_mac);
if (*target_config == '+') {
nt->extended = true;
target_config++;
}
err = netpoll_parse_options(&nt->np, target_config);
if (err)
goto fail;
err = netpoll_setup(&nt->np);
if (err)
goto fail;
nt->enabled = true;
return nt;
fail:
kfree(nt);
return ERR_PTR(err);
}
static void free_param_target(struct netconsole_target *nt)
{
netpoll_cleanup(&nt->np);
kfree(nt);
}
static struct netconsole_target *to_target(struct config_item *item)
{
return item ?
container_of(item, struct netconsole_target, item) :
NULL;
}
static ssize_t show_enabled(struct netconsole_target *nt, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", nt->enabled);
}
static ssize_t show_extended(struct netconsole_target *nt, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", nt->extended);
}
static ssize_t show_dev_name(struct netconsole_target *nt, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", nt->np.dev_name);
}
static ssize_t show_local_port(struct netconsole_target *nt, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", nt->np.local_port);
}
static ssize_t show_remote_port(struct netconsole_target *nt, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", nt->np.remote_port);
}
static ssize_t show_local_ip(struct netconsole_target *nt, char *buf)
{
if (nt->np.ipv6)
return snprintf(buf, PAGE_SIZE, "%pI6c\n", &nt->np.local_ip.in6);
else
return snprintf(buf, PAGE_SIZE, "%pI4\n", &nt->np.local_ip);
}
static ssize_t show_remote_ip(struct netconsole_target *nt, char *buf)
{
if (nt->np.ipv6)
return snprintf(buf, PAGE_SIZE, "%pI6c\n", &nt->np.remote_ip.in6);
else
return snprintf(buf, PAGE_SIZE, "%pI4\n", &nt->np.remote_ip);
}
static ssize_t show_local_mac(struct netconsole_target *nt, char *buf)
{
struct net_device *dev = nt->np.dev;
static const u8 bcast[ETH_ALEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
return snprintf(buf, PAGE_SIZE, "%pM\n", dev ? dev->dev_addr : bcast);
}
static ssize_t show_remote_mac(struct netconsole_target *nt, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%pM\n", nt->np.remote_mac);
}
static ssize_t store_enabled(struct netconsole_target *nt,
const char *buf,
size_t count)
{
unsigned long flags;
int enabled;
int err;
err = kstrtoint(buf, 10, &enabled);
if (err < 0)
return err;
if (enabled < 0 || enabled > 1)
return -EINVAL;
if ((bool)enabled == nt->enabled) {
pr_info("network logging has already %s\n",
nt->enabled ? "started" : "stopped");
return -EINVAL;
}
if (enabled) {
if (nt->extended && !(netconsole_ext.flags & CON_ENABLED)) {
netconsole_ext.flags |= CON_ENABLED;
register_console(&netconsole_ext);
}
netpoll_print_options(&nt->np);
err = netpoll_setup(&nt->np);
if (err)
return err;
pr_info("netconsole: network logging started\n");
} else {
spin_lock_irqsave(&target_list_lock, flags);
nt->enabled = false;
spin_unlock_irqrestore(&target_list_lock, flags);
netpoll_cleanup(&nt->np);
}
nt->enabled = enabled;
return strnlen(buf, count);
}
static ssize_t store_extended(struct netconsole_target *nt,
const char *buf,
size_t count)
{
int extended;
int err;
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
err = kstrtoint(buf, 10, &extended);
if (err < 0)
return err;
if (extended < 0 || extended > 1)
return -EINVAL;
nt->extended = extended;
return strnlen(buf, count);
}
static ssize_t store_dev_name(struct netconsole_target *nt,
const char *buf,
size_t count)
{
size_t len;
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
strlcpy(nt->np.dev_name, buf, IFNAMSIZ);
len = strnlen(nt->np.dev_name, IFNAMSIZ);
if (nt->np.dev_name[len - 1] == '\n')
nt->np.dev_name[len - 1] = '\0';
return strnlen(buf, count);
}
static ssize_t store_local_port(struct netconsole_target *nt,
const char *buf,
size_t count)
{
int rv;
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
rv = kstrtou16(buf, 10, &nt->np.local_port);
if (rv < 0)
return rv;
return strnlen(buf, count);
}
static ssize_t store_remote_port(struct netconsole_target *nt,
const char *buf,
size_t count)
{
int rv;
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
rv = kstrtou16(buf, 10, &nt->np.remote_port);
if (rv < 0)
return rv;
return strnlen(buf, count);
}
static ssize_t store_local_ip(struct netconsole_target *nt,
const char *buf,
size_t count)
{
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
if (strnchr(buf, count, ':')) {
const char *end;
if (in6_pton(buf, count, nt->np.local_ip.in6.s6_addr, -1, &end) > 0) {
if (*end && *end != '\n') {
pr_err("invalid IPv6 address at: <%c>\n", *end);
return -EINVAL;
}
nt->np.ipv6 = true;
} else
return -EINVAL;
} else {
if (!nt->np.ipv6) {
nt->np.local_ip.ip = in_aton(buf);
} else
return -EINVAL;
}
return strnlen(buf, count);
}
static ssize_t store_remote_ip(struct netconsole_target *nt,
const char *buf,
size_t count)
{
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
if (strnchr(buf, count, ':')) {
const char *end;
if (in6_pton(buf, count, nt->np.remote_ip.in6.s6_addr, -1, &end) > 0) {
if (*end && *end != '\n') {
pr_err("invalid IPv6 address at: <%c>\n", *end);
return -EINVAL;
}
nt->np.ipv6 = true;
} else
return -EINVAL;
} else {
if (!nt->np.ipv6) {
nt->np.remote_ip.ip = in_aton(buf);
} else
return -EINVAL;
}
return strnlen(buf, count);
}
static ssize_t store_remote_mac(struct netconsole_target *nt,
const char *buf,
size_t count)
{
u8 remote_mac[ETH_ALEN];
if (nt->enabled) {
pr_err("target (%s) is enabled, disable to update parameters\n",
config_item_name(&nt->item));
return -EINVAL;
}
if (!mac_pton(buf, remote_mac))
return -EINVAL;
if (buf[3 * ETH_ALEN - 1] && buf[3 * ETH_ALEN - 1] != '\n')
return -EINVAL;
memcpy(nt->np.remote_mac, remote_mac, ETH_ALEN);
return strnlen(buf, count);
}
static void netconsole_target_release(struct config_item *item)
{
kfree(to_target(item));
}
static ssize_t netconsole_target_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *buf)
{
ssize_t ret = -EINVAL;
struct netconsole_target *nt = to_target(item);
struct netconsole_target_attr *na =
container_of(attr, struct netconsole_target_attr, attr);
if (na->show)
ret = na->show(nt, buf);
return ret;
}
static ssize_t netconsole_target_attr_store(struct config_item *item,
struct configfs_attribute *attr,
const char *buf,
size_t count)
{
ssize_t ret = -EINVAL;
struct netconsole_target *nt = to_target(item);
struct netconsole_target_attr *na =
container_of(attr, struct netconsole_target_attr, attr);
mutex_lock(&dynamic_netconsole_mutex);
if (na->store)
ret = na->store(nt, buf, count);
mutex_unlock(&dynamic_netconsole_mutex);
return ret;
}
static struct config_item *make_netconsole_target(struct config_group *group,
const char *name)
{
unsigned long flags;
struct netconsole_target *nt;
nt = kzalloc(sizeof(*nt), GFP_KERNEL);
if (!nt)
return ERR_PTR(-ENOMEM);
nt->np.name = "netconsole";
strlcpy(nt->np.dev_name, "eth0", IFNAMSIZ);
nt->np.local_port = 6665;
nt->np.remote_port = 6666;
eth_broadcast_addr(nt->np.remote_mac);
config_item_init_type_name(&nt->item, name, &netconsole_target_type);
spin_lock_irqsave(&target_list_lock, flags);
list_add(&nt->list, &target_list);
spin_unlock_irqrestore(&target_list_lock, flags);
return &nt->item;
}
static void drop_netconsole_target(struct config_group *group,
struct config_item *item)
{
unsigned long flags;
struct netconsole_target *nt = to_target(item);
spin_lock_irqsave(&target_list_lock, flags);
list_del(&nt->list);
spin_unlock_irqrestore(&target_list_lock, flags);
if (nt->enabled)
netpoll_cleanup(&nt->np);
config_item_put(&nt->item);
}
static int netconsole_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
unsigned long flags;
struct netconsole_target *nt;
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
bool stopped = false;
if (!(event == NETDEV_CHANGENAME || event == NETDEV_UNREGISTER ||
event == NETDEV_RELEASE || event == NETDEV_JOIN))
goto done;
spin_lock_irqsave(&target_list_lock, flags);
restart:
list_for_each_entry(nt, &target_list, list) {
netconsole_target_get(nt);
if (nt->np.dev == dev) {
switch (event) {
case NETDEV_CHANGENAME:
strlcpy(nt->np.dev_name, dev->name, IFNAMSIZ);
break;
case NETDEV_RELEASE:
case NETDEV_JOIN:
case NETDEV_UNREGISTER:
spin_unlock_irqrestore(&target_list_lock, flags);
__netpoll_cleanup(&nt->np);
spin_lock_irqsave(&target_list_lock, flags);
dev_put(nt->np.dev);
nt->np.dev = NULL;
nt->enabled = false;
stopped = true;
netconsole_target_put(nt);
goto restart;
}
}
netconsole_target_put(nt);
}
spin_unlock_irqrestore(&target_list_lock, flags);
if (stopped) {
const char *msg = "had an event";
switch (event) {
case NETDEV_UNREGISTER:
msg = "unregistered";
break;
case NETDEV_RELEASE:
msg = "released slaves";
break;
case NETDEV_JOIN:
msg = "is joining a master device";
break;
}
pr_info("network logging stopped on interface %s as it %s\n",
dev->name, msg);
}
done:
return NOTIFY_DONE;
}
static void send_ext_msg_udp(struct netconsole_target *nt, const char *msg,
int msg_len)
{
static char buf[MAX_PRINT_CHUNK];
const char *header, *body;
int offset = 0;
int header_len, body_len;
if (msg_len <= MAX_PRINT_CHUNK) {
netpoll_send_udp(&nt->np, msg, msg_len);
return;
}
header = msg;
body = memchr(msg, ';', msg_len);
if (WARN_ON_ONCE(!body))
return;
header_len = body - header;
body_len = msg_len - header_len - 1;
body++;
memcpy(buf, header, header_len);
while (offset < body_len) {
int this_header = header_len;
int this_chunk;
this_header += scnprintf(buf + this_header,
sizeof(buf) - this_header,
",ncfrag=%d/%d;", offset, body_len);
this_chunk = min(body_len - offset,
MAX_PRINT_CHUNK - this_header);
if (WARN_ON_ONCE(this_chunk <= 0))
return;
memcpy(buf + this_header, body + offset, this_chunk);
netpoll_send_udp(&nt->np, buf, this_header + this_chunk);
offset += this_chunk;
}
}
static void write_ext_msg(struct console *con, const char *msg,
unsigned int len)
{
struct netconsole_target *nt;
unsigned long flags;
if ((oops_only && !oops_in_progress) || list_empty(&target_list))
return;
spin_lock_irqsave(&target_list_lock, flags);
list_for_each_entry(nt, &target_list, list)
if (nt->extended && nt->enabled && netif_running(nt->np.dev))
send_ext_msg_udp(nt, msg, len);
spin_unlock_irqrestore(&target_list_lock, flags);
}
static void write_msg(struct console *con, const char *msg, unsigned int len)
{
int frag, left;
unsigned long flags;
struct netconsole_target *nt;
const char *tmp;
if (oops_only && !oops_in_progress)
return;
if (list_empty(&target_list))
return;
spin_lock_irqsave(&target_list_lock, flags);
list_for_each_entry(nt, &target_list, list) {
if (!nt->extended && nt->enabled && netif_running(nt->np.dev)) {
tmp = msg;
for (left = len; left;) {
frag = min(left, MAX_PRINT_CHUNK);
netpoll_send_udp(&nt->np, tmp, frag);
tmp += frag;
left -= frag;
}
}
}
spin_unlock_irqrestore(&target_list_lock, flags);
}
static int __init init_netconsole(void)
{
int err;
struct netconsole_target *nt, *tmp;
unsigned long flags;
char *target_config;
char *input = config;
if (strnlen(input, MAX_PARAM_LENGTH)) {
while ((target_config = strsep(&input, ";"))) {
nt = alloc_param_target(target_config);
if (IS_ERR(nt)) {
err = PTR_ERR(nt);
goto fail;
}
if (nt->extended)
netconsole_ext.flags |= CON_PRINTBUFFER |
CON_ENABLED;
else
netconsole.flags |= CON_PRINTBUFFER;
spin_lock_irqsave(&target_list_lock, flags);
list_add(&nt->list, &target_list);
spin_unlock_irqrestore(&target_list_lock, flags);
}
}
err = register_netdevice_notifier(&netconsole_netdev_notifier);
if (err)
goto fail;
err = dynamic_netconsole_init();
if (err)
goto undonotifier;
if (netconsole_ext.flags & CON_ENABLED)
register_console(&netconsole_ext);
register_console(&netconsole);
pr_info("network logging started\n");
return err;
undonotifier:
unregister_netdevice_notifier(&netconsole_netdev_notifier);
fail:
pr_err("cleaning up\n");
list_for_each_entry_safe(nt, tmp, &target_list, list) {
list_del(&nt->list);
free_param_target(nt);
}
return err;
}
static void __exit cleanup_netconsole(void)
{
struct netconsole_target *nt, *tmp;
unregister_console(&netconsole_ext);
unregister_console(&netconsole);
dynamic_netconsole_exit();
unregister_netdevice_notifier(&netconsole_netdev_notifier);
list_for_each_entry_safe(nt, tmp, &target_list, list) {
list_del(&nt->list);
free_param_target(nt);
}
}
