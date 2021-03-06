static inline int ncsi_filter_size(int table)
{
int sizes[] = { 2, 6, 6, 6 };
BUILD_BUG_ON(ARRAY_SIZE(sizes) != NCSI_FILTER_MAX);
if (table < NCSI_FILTER_BASE || table >= NCSI_FILTER_MAX)
return -EINVAL;
return sizes[table];
}
int ncsi_find_filter(struct ncsi_channel *nc, int table, void *data)
{
struct ncsi_channel_filter *ncf;
void *bitmap;
int index, size;
unsigned long flags;
ncf = nc->filters[table];
if (!ncf)
return -ENXIO;
size = ncsi_filter_size(table);
if (size < 0)
return size;
spin_lock_irqsave(&nc->lock, flags);
bitmap = (void *)&ncf->bitmap;
index = -1;
while ((index = find_next_bit(bitmap, ncf->total, index + 1))
< ncf->total) {
if (!memcmp(ncf->data + size * index, data, size)) {
spin_unlock_irqrestore(&nc->lock, flags);
return index;
}
}
spin_unlock_irqrestore(&nc->lock, flags);
return -ENOENT;
}
int ncsi_add_filter(struct ncsi_channel *nc, int table, void *data)
{
struct ncsi_channel_filter *ncf;
int index, size;
void *bitmap;
unsigned long flags;
size = ncsi_filter_size(table);
if (size < 0)
return size;
index = ncsi_find_filter(nc, table, data);
if (index >= 0)
return index;
ncf = nc->filters[table];
if (!ncf)
return -ENODEV;
spin_lock_irqsave(&nc->lock, flags);
bitmap = (void *)&ncf->bitmap;
do {
index = find_next_zero_bit(bitmap, ncf->total, 0);
if (index >= ncf->total) {
spin_unlock_irqrestore(&nc->lock, flags);
return -ENOSPC;
}
} while (test_and_set_bit(index, bitmap));
memcpy(ncf->data + size * index, data, size);
spin_unlock_irqrestore(&nc->lock, flags);
return index;
}
int ncsi_remove_filter(struct ncsi_channel *nc, int table, int index)
{
struct ncsi_channel_filter *ncf;
int size;
void *bitmap;
unsigned long flags;
size = ncsi_filter_size(table);
if (size < 0)
return size;
ncf = nc->filters[table];
if (!ncf || index >= ncf->total)
return -ENODEV;
spin_lock_irqsave(&nc->lock, flags);
bitmap = (void *)&ncf->bitmap;
if (test_and_clear_bit(index, bitmap))
memset(ncf->data + size * index, 0, size);
spin_unlock_irqrestore(&nc->lock, flags);
return 0;
}
static void ncsi_report_link(struct ncsi_dev_priv *ndp, bool force_down)
{
struct ncsi_dev *nd = &ndp->ndev;
struct ncsi_package *np;
struct ncsi_channel *nc;
nd->state = ncsi_dev_state_functional;
if (force_down) {
nd->link_up = 0;
goto report;
}
nd->link_up = 0;
NCSI_FOR_EACH_PACKAGE(ndp, np) {
NCSI_FOR_EACH_CHANNEL(np, nc) {
if (!list_empty(&nc->link) ||
nc->state != NCSI_CHANNEL_ACTIVE)
continue;
if (nc->modes[NCSI_MODE_LINK].data[2] & 0x1) {
nd->link_up = 1;
goto report;
}
}
}
report:
nd->handler(nd);
}
static void ncsi_channel_monitor(unsigned long data)
{
struct ncsi_channel *nc = (struct ncsi_channel *)data;
struct ncsi_package *np = nc->package;
struct ncsi_dev_priv *ndp = np->ndp;
struct ncsi_cmd_arg nca;
bool enabled;
unsigned int timeout;
unsigned long flags;
int ret;
spin_lock_irqsave(&nc->lock, flags);
timeout = nc->timeout;
enabled = nc->enabled;
spin_unlock_irqrestore(&nc->lock, flags);
if (!enabled || !list_empty(&nc->link))
return;
if (nc->state != NCSI_CHANNEL_INACTIVE &&
nc->state != NCSI_CHANNEL_ACTIVE)
return;
if (!(timeout % 2)) {
nca.ndp = ndp;
nca.package = np->id;
nca.channel = nc->id;
nca.type = NCSI_PKT_CMD_GLS;
nca.driven = false;
ret = ncsi_xmit_cmd(&nca);
if (ret) {
netdev_err(ndp->ndev.dev, "Error %d sending GLS\n",
ret);
return;
}
}
if (timeout + 1 >= 3) {
if (!(ndp->flags & NCSI_DEV_HWA) &&
nc->state == NCSI_CHANNEL_ACTIVE)
ncsi_report_link(ndp, true);
spin_lock_irqsave(&ndp->lock, flags);
xchg(&nc->state, NCSI_CHANNEL_INACTIVE);
list_add_tail_rcu(&nc->link, &ndp->channel_queue);
spin_unlock_irqrestore(&ndp->lock, flags);
ncsi_process_next_channel(ndp);
return;
}
spin_lock_irqsave(&nc->lock, flags);
nc->timeout = timeout + 1;
nc->enabled = true;
spin_unlock_irqrestore(&nc->lock, flags);
mod_timer(&nc->timer, jiffies + HZ * (1 << (nc->timeout / 2)));
}
void ncsi_start_channel_monitor(struct ncsi_channel *nc)
{
unsigned long flags;
spin_lock_irqsave(&nc->lock, flags);
WARN_ON_ONCE(nc->enabled);
nc->timeout = 0;
nc->enabled = true;
spin_unlock_irqrestore(&nc->lock, flags);
mod_timer(&nc->timer, jiffies + HZ * (1 << (nc->timeout / 2)));
}
void ncsi_stop_channel_monitor(struct ncsi_channel *nc)
{
unsigned long flags;
spin_lock_irqsave(&nc->lock, flags);
if (!nc->enabled) {
spin_unlock_irqrestore(&nc->lock, flags);
return;
}
nc->enabled = false;
spin_unlock_irqrestore(&nc->lock, flags);
del_timer_sync(&nc->timer);
}
struct ncsi_channel *ncsi_find_channel(struct ncsi_package *np,
unsigned char id)
{
struct ncsi_channel *nc;
NCSI_FOR_EACH_CHANNEL(np, nc) {
if (nc->id == id)
return nc;
}
return NULL;
}
struct ncsi_channel *ncsi_add_channel(struct ncsi_package *np, unsigned char id)
{
struct ncsi_channel *nc, *tmp;
int index;
unsigned long flags;
nc = kzalloc(sizeof(*nc), GFP_ATOMIC);
if (!nc)
return NULL;
nc->id = id;
nc->package = np;
nc->state = NCSI_CHANNEL_INACTIVE;
nc->enabled = false;
setup_timer(&nc->timer, ncsi_channel_monitor, (unsigned long)nc);
spin_lock_init(&nc->lock);
INIT_LIST_HEAD(&nc->link);
for (index = 0; index < NCSI_CAP_MAX; index++)
nc->caps[index].index = index;
for (index = 0; index < NCSI_MODE_MAX; index++)
nc->modes[index].index = index;
spin_lock_irqsave(&np->lock, flags);
tmp = ncsi_find_channel(np, id);
if (tmp) {
spin_unlock_irqrestore(&np->lock, flags);
kfree(nc);
return tmp;
}
list_add_tail_rcu(&nc->node, &np->channels);
np->channel_num++;
spin_unlock_irqrestore(&np->lock, flags);
return nc;
}
static void ncsi_remove_channel(struct ncsi_channel *nc)
{
struct ncsi_package *np = nc->package;
struct ncsi_channel_filter *ncf;
unsigned long flags;
int i;
spin_lock_irqsave(&nc->lock, flags);
for (i = 0; i < NCSI_FILTER_MAX; i++) {
ncf = nc->filters[i];
if (!ncf)
continue;
nc->filters[i] = NULL;
kfree(ncf);
}
nc->state = NCSI_CHANNEL_INACTIVE;
spin_unlock_irqrestore(&nc->lock, flags);
ncsi_stop_channel_monitor(nc);
spin_lock_irqsave(&np->lock, flags);
list_del_rcu(&nc->node);
np->channel_num--;
spin_unlock_irqrestore(&np->lock, flags);
kfree(nc);
}
struct ncsi_package *ncsi_find_package(struct ncsi_dev_priv *ndp,
unsigned char id)
{
struct ncsi_package *np;
NCSI_FOR_EACH_PACKAGE(ndp, np) {
if (np->id == id)
return np;
}
return NULL;
}
struct ncsi_package *ncsi_add_package(struct ncsi_dev_priv *ndp,
unsigned char id)
{
struct ncsi_package *np, *tmp;
unsigned long flags;
np = kzalloc(sizeof(*np), GFP_ATOMIC);
if (!np)
return NULL;
np->id = id;
np->ndp = ndp;
spin_lock_init(&np->lock);
INIT_LIST_HEAD(&np->channels);
spin_lock_irqsave(&ndp->lock, flags);
tmp = ncsi_find_package(ndp, id);
if (tmp) {
spin_unlock_irqrestore(&ndp->lock, flags);
kfree(np);
return tmp;
}
list_add_tail_rcu(&np->node, &ndp->packages);
ndp->package_num++;
spin_unlock_irqrestore(&ndp->lock, flags);
return np;
}
void ncsi_remove_package(struct ncsi_package *np)
{
struct ncsi_dev_priv *ndp = np->ndp;
struct ncsi_channel *nc, *tmp;
unsigned long flags;
list_for_each_entry_safe(nc, tmp, &np->channels, node)
ncsi_remove_channel(nc);
spin_lock_irqsave(&ndp->lock, flags);
list_del_rcu(&np->node);
ndp->package_num--;
spin_unlock_irqrestore(&ndp->lock, flags);
kfree(np);
}
void ncsi_find_package_and_channel(struct ncsi_dev_priv *ndp,
unsigned char id,
struct ncsi_package **np,
struct ncsi_channel **nc)
{
struct ncsi_package *p;
struct ncsi_channel *c;
p = ncsi_find_package(ndp, NCSI_PACKAGE_INDEX(id));
c = p ? ncsi_find_channel(p, NCSI_CHANNEL_INDEX(id)) : NULL;
if (np)
*np = p;
if (nc)
*nc = c;
}
struct ncsi_request *ncsi_alloc_request(struct ncsi_dev_priv *ndp, bool driven)
{
struct ncsi_request *nr = NULL;
int i, limit = ARRAY_SIZE(ndp->requests);
unsigned long flags;
spin_lock_irqsave(&ndp->lock, flags);
for (i = ndp->request_id; !nr && i < limit; i++) {
if (ndp->requests[i].used)
continue;
nr = &ndp->requests[i];
nr->used = true;
nr->driven = driven;
if (++ndp->request_id >= limit)
ndp->request_id = 0;
}
for (i = 0; !nr && i < ndp->request_id; i++) {
if (ndp->requests[i].used)
continue;
nr = &ndp->requests[i];
nr->used = true;
nr->driven = driven;
if (++ndp->request_id >= limit)
ndp->request_id = 0;
}
spin_unlock_irqrestore(&ndp->lock, flags);
return nr;
}
void ncsi_free_request(struct ncsi_request *nr)
{
struct ncsi_dev_priv *ndp = nr->ndp;
struct sk_buff *cmd, *rsp;
unsigned long flags;
bool driven;
if (nr->enabled) {
nr->enabled = false;
del_timer_sync(&nr->timer);
}
spin_lock_irqsave(&ndp->lock, flags);
cmd = nr->cmd;
rsp = nr->rsp;
nr->cmd = NULL;
nr->rsp = NULL;
nr->used = false;
driven = nr->driven;
spin_unlock_irqrestore(&ndp->lock, flags);
if (driven && cmd && --ndp->pending_req_num == 0)
schedule_work(&ndp->work);
consume_skb(cmd);
consume_skb(rsp);
}
struct ncsi_dev *ncsi_find_dev(struct net_device *dev)
{
struct ncsi_dev_priv *ndp;
NCSI_FOR_EACH_DEV(ndp) {
if (ndp->ndev.dev == dev)
return &ndp->ndev;
}
return NULL;
}
static void ncsi_request_timeout(unsigned long data)
{
struct ncsi_request *nr = (struct ncsi_request *)data;
struct ncsi_dev_priv *ndp = nr->ndp;
unsigned long flags;
spin_lock_irqsave(&ndp->lock, flags);
nr->enabled = false;
if (nr->rsp || !nr->cmd) {
spin_unlock_irqrestore(&ndp->lock, flags);
return;
}
spin_unlock_irqrestore(&ndp->lock, flags);
ncsi_free_request(nr);
}
static void ncsi_suspend_channel(struct ncsi_dev_priv *ndp)
{
struct ncsi_dev *nd = &ndp->ndev;
struct ncsi_package *np = ndp->active_package;
struct ncsi_channel *nc = ndp->active_channel;
struct ncsi_cmd_arg nca;
int ret;
nca.ndp = ndp;
nca.driven = true;
switch (nd->state) {
case ncsi_dev_state_suspend:
nd->state = ncsi_dev_state_suspend_select;
case ncsi_dev_state_suspend_select:
case ncsi_dev_state_suspend_dcnt:
case ncsi_dev_state_suspend_dc:
case ncsi_dev_state_suspend_deselect:
ndp->pending_req_num = 1;
np = ndp->active_package;
nc = ndp->active_channel;
nca.package = np->id;
if (nd->state == ncsi_dev_state_suspend_select) {
nca.type = NCSI_PKT_CMD_SP;
nca.channel = 0x1f;
if (ndp->flags & NCSI_DEV_HWA)
nca.bytes[0] = 0;
else
nca.bytes[0] = 1;
nd->state = ncsi_dev_state_suspend_dcnt;
} else if (nd->state == ncsi_dev_state_suspend_dcnt) {
nca.type = NCSI_PKT_CMD_DCNT;
nca.channel = nc->id;
nd->state = ncsi_dev_state_suspend_dc;
} else if (nd->state == ncsi_dev_state_suspend_dc) {
nca.type = NCSI_PKT_CMD_DC;
nca.channel = nc->id;
nca.bytes[0] = 1;
nd->state = ncsi_dev_state_suspend_deselect;
} else if (nd->state == ncsi_dev_state_suspend_deselect) {
nca.type = NCSI_PKT_CMD_DP;
nca.channel = 0x1f;
nd->state = ncsi_dev_state_suspend_done;
}
ret = ncsi_xmit_cmd(&nca);
if (ret) {
nd->state = ncsi_dev_state_functional;
return;
}
break;
case ncsi_dev_state_suspend_done:
xchg(&nc->state, NCSI_CHANNEL_INACTIVE);
ncsi_process_next_channel(ndp);
break;
default:
netdev_warn(nd->dev, "Wrong NCSI state 0x%x in suspend\n",
nd->state);
}
}
static void ncsi_configure_channel(struct ncsi_dev_priv *ndp)
{
struct ncsi_dev *nd = &ndp->ndev;
struct net_device *dev = nd->dev;
struct ncsi_package *np = ndp->active_package;
struct ncsi_channel *nc = ndp->active_channel;
struct ncsi_cmd_arg nca;
unsigned char index;
int ret;
nca.ndp = ndp;
nca.driven = true;
switch (nd->state) {
case ncsi_dev_state_config:
case ncsi_dev_state_config_sp:
ndp->pending_req_num = 1;
nca.type = NCSI_PKT_CMD_SP;
if (ndp->flags & NCSI_DEV_HWA)
nca.bytes[0] = 0;
else
nca.bytes[0] = 1;
nca.package = np->id;
nca.channel = 0x1f;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
nd->state = ncsi_dev_state_config_cis;
break;
case ncsi_dev_state_config_cis:
ndp->pending_req_num = 1;
nca.type = NCSI_PKT_CMD_CIS;
nca.package = np->id;
nca.channel = nc->id;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
nd->state = ncsi_dev_state_config_sma;
break;
case ncsi_dev_state_config_sma:
case ncsi_dev_state_config_ebf:
#if IS_ENABLED(CONFIG_IPV6)
case ncsi_dev_state_config_egmf:
#endif
case ncsi_dev_state_config_ecnt:
case ncsi_dev_state_config_ec:
case ncsi_dev_state_config_ae:
case ncsi_dev_state_config_gls:
ndp->pending_req_num = 1;
nca.package = np->id;
nca.channel = nc->id;
if (nd->state == ncsi_dev_state_config_sma) {
nca.type = NCSI_PKT_CMD_SMA;
for (index = 0; index < 6; index++)
nca.bytes[index] = dev->dev_addr[index];
nca.bytes[6] = 0x1;
nca.bytes[7] = 0x1;
nd->state = ncsi_dev_state_config_ebf;
} else if (nd->state == ncsi_dev_state_config_ebf) {
nca.type = NCSI_PKT_CMD_EBF;
nca.dwords[0] = nc->caps[NCSI_CAP_BC].cap;
nd->state = ncsi_dev_state_config_ecnt;
#if IS_ENABLED(CONFIG_IPV6)
if (ndp->inet6_addr_num > 0 &&
(nc->caps[NCSI_CAP_GENERIC].cap &
NCSI_CAP_GENERIC_MC))
nd->state = ncsi_dev_state_config_egmf;
else
nd->state = ncsi_dev_state_config_ecnt;
} else if (nd->state == ncsi_dev_state_config_egmf) {
nca.type = NCSI_PKT_CMD_EGMF;
nca.dwords[0] = nc->caps[NCSI_CAP_MC].cap;
nd->state = ncsi_dev_state_config_ecnt;
#endif
} else if (nd->state == ncsi_dev_state_config_ecnt) {
nca.type = NCSI_PKT_CMD_ECNT;
nd->state = ncsi_dev_state_config_ec;
} else if (nd->state == ncsi_dev_state_config_ec) {
nca.type = NCSI_PKT_CMD_EC;
nd->state = ncsi_dev_state_config_ae;
if (!(nc->caps[NCSI_CAP_AEN].cap & NCSI_CAP_AEN_MASK))
nd->state = ncsi_dev_state_config_gls;
} else if (nd->state == ncsi_dev_state_config_ae) {
nca.type = NCSI_PKT_CMD_AE;
nca.bytes[0] = 0;
nca.dwords[1] = nc->caps[NCSI_CAP_AEN].cap;
nd->state = ncsi_dev_state_config_gls;
} else if (nd->state == ncsi_dev_state_config_gls) {
nca.type = NCSI_PKT_CMD_GLS;
nd->state = ncsi_dev_state_config_done;
}
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
break;
case ncsi_dev_state_config_done:
if (nc->modes[NCSI_MODE_LINK].data[2] & 0x1)
xchg(&nc->state, NCSI_CHANNEL_ACTIVE);
else
xchg(&nc->state, NCSI_CHANNEL_INACTIVE);
ncsi_start_channel_monitor(nc);
ncsi_process_next_channel(ndp);
break;
default:
netdev_warn(dev, "Wrong NCSI state 0x%x in config\n",
nd->state);
}
return;
error:
ncsi_report_link(ndp, true);
}
static int ncsi_choose_active_channel(struct ncsi_dev_priv *ndp)
{
struct ncsi_package *np;
struct ncsi_channel *nc, *found;
struct ncsi_channel_mode *ncm;
unsigned long flags;
found = NULL;
NCSI_FOR_EACH_PACKAGE(ndp, np) {
NCSI_FOR_EACH_CHANNEL(np, nc) {
if (!list_empty(&nc->link) ||
nc->state != NCSI_CHANNEL_INACTIVE)
continue;
if (!found)
found = nc;
ncm = &nc->modes[NCSI_MODE_LINK];
if (ncm->data[2] & 0x1) {
found = nc;
goto out;
}
}
}
if (!found) {
ncsi_report_link(ndp, true);
return -ENODEV;
}
out:
spin_lock_irqsave(&ndp->lock, flags);
list_add_tail_rcu(&found->link, &ndp->channel_queue);
spin_unlock_irqrestore(&ndp->lock, flags);
return ncsi_process_next_channel(ndp);
}
static bool ncsi_check_hwa(struct ncsi_dev_priv *ndp)
{
struct ncsi_package *np;
struct ncsi_channel *nc;
unsigned int cap;
NCSI_FOR_EACH_PACKAGE(ndp, np) {
NCSI_FOR_EACH_CHANNEL(np, nc) {
cap = nc->caps[NCSI_CAP_GENERIC].cap;
if (!(cap & NCSI_CAP_GENERIC_HWA) ||
(cap & NCSI_CAP_GENERIC_HWA_MASK) !=
NCSI_CAP_GENERIC_HWA_SUPPORT) {
ndp->flags &= ~NCSI_DEV_HWA;
return false;
}
}
}
ndp->flags |= NCSI_DEV_HWA;
return true;
}
static int ncsi_enable_hwa(struct ncsi_dev_priv *ndp)
{
struct ncsi_package *np;
struct ncsi_channel *nc;
unsigned long flags;
spin_lock_irqsave(&ndp->lock, flags);
NCSI_FOR_EACH_PACKAGE(ndp, np) {
NCSI_FOR_EACH_CHANNEL(np, nc) {
WARN_ON_ONCE(nc->state != NCSI_CHANNEL_INACTIVE ||
!list_empty(&nc->link));
ncsi_stop_channel_monitor(nc);
list_add_tail_rcu(&nc->link, &ndp->channel_queue);
}
}
spin_unlock_irqrestore(&ndp->lock, flags);
if (list_empty(&ndp->channel_queue)) {
ncsi_report_link(ndp, false);
return -ENOENT;
}
return ncsi_process_next_channel(ndp);
}
static void ncsi_probe_channel(struct ncsi_dev_priv *ndp)
{
struct ncsi_dev *nd = &ndp->ndev;
struct ncsi_package *np;
struct ncsi_channel *nc;
struct ncsi_cmd_arg nca;
unsigned char index;
int ret;
nca.ndp = ndp;
nca.driven = true;
switch (nd->state) {
case ncsi_dev_state_probe:
nd->state = ncsi_dev_state_probe_deselect;
case ncsi_dev_state_probe_deselect:
ndp->pending_req_num = 8;
nca.type = NCSI_PKT_CMD_DP;
nca.channel = 0x1f;
for (index = 0; index < 8; index++) {
nca.package = index;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
}
nd->state = ncsi_dev_state_probe_package;
break;
case ncsi_dev_state_probe_package:
ndp->pending_req_num = 16;
nca.type = NCSI_PKT_CMD_SP;
nca.bytes[0] = 1;
nca.channel = 0x1f;
for (index = 0; index < 8; index++) {
nca.package = index;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
}
nca.type = NCSI_PKT_CMD_DP;
for (index = 0; index < 8; index++) {
nca.package = index;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
}
nd->state = ncsi_dev_state_probe_channel;
break;
case ncsi_dev_state_probe_channel:
if (!ndp->active_package)
ndp->active_package = list_first_or_null_rcu(
&ndp->packages, struct ncsi_package, node);
else if (list_is_last(&ndp->active_package->node,
&ndp->packages))
ndp->active_package = NULL;
else
ndp->active_package = list_next_entry(
ndp->active_package, node);
if (!ndp->active_package) {
ndp->flags |= NCSI_DEV_PROBED;
if (ncsi_check_hwa(ndp))
ncsi_enable_hwa(ndp);
else
ncsi_choose_active_channel(ndp);
return;
}
ndp->pending_req_num = 1;
nca.type = NCSI_PKT_CMD_SP;
nca.bytes[0] = 1;
nca.package = ndp->active_package->id;
nca.channel = 0x1f;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
nd->state = ncsi_dev_state_probe_cis;
break;
case ncsi_dev_state_probe_cis:
ndp->pending_req_num = 32;
nca.type = NCSI_PKT_CMD_CIS;
nca.package = ndp->active_package->id;
for (index = 0; index < 0x20; index++) {
nca.channel = index;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
}
nd->state = ncsi_dev_state_probe_gvi;
break;
case ncsi_dev_state_probe_gvi:
case ncsi_dev_state_probe_gc:
case ncsi_dev_state_probe_gls:
np = ndp->active_package;
ndp->pending_req_num = np->channel_num;
if (nd->state == ncsi_dev_state_probe_gvi)
nca.type = NCSI_PKT_CMD_GVI;
else if (nd->state == ncsi_dev_state_probe_gc)
nca.type = NCSI_PKT_CMD_GC;
else
nca.type = NCSI_PKT_CMD_GLS;
nca.package = np->id;
NCSI_FOR_EACH_CHANNEL(np, nc) {
nca.channel = nc->id;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
}
if (nd->state == ncsi_dev_state_probe_gvi)
nd->state = ncsi_dev_state_probe_gc;
else if (nd->state == ncsi_dev_state_probe_gc)
nd->state = ncsi_dev_state_probe_gls;
else
nd->state = ncsi_dev_state_probe_dp;
break;
case ncsi_dev_state_probe_dp:
ndp->pending_req_num = 1;
nca.type = NCSI_PKT_CMD_DP;
nca.package = ndp->active_package->id;
nca.channel = 0x1f;
ret = ncsi_xmit_cmd(&nca);
if (ret)
goto error;
nd->state = ncsi_dev_state_probe_channel;
break;
default:
netdev_warn(nd->dev, "Wrong NCSI state 0x%0x in enumeration\n",
nd->state);
}
return;
error:
ncsi_report_link(ndp, true);
}
static void ncsi_dev_work(struct work_struct *work)
{
struct ncsi_dev_priv *ndp = container_of(work,
struct ncsi_dev_priv, work);
struct ncsi_dev *nd = &ndp->ndev;
switch (nd->state & ncsi_dev_state_major) {
case ncsi_dev_state_probe:
ncsi_probe_channel(ndp);
break;
case ncsi_dev_state_suspend:
ncsi_suspend_channel(ndp);
break;
case ncsi_dev_state_config:
ncsi_configure_channel(ndp);
break;
default:
netdev_warn(nd->dev, "Wrong NCSI state 0x%x in workqueue\n",
nd->state);
}
}
int ncsi_process_next_channel(struct ncsi_dev_priv *ndp)
{
struct ncsi_channel *nc;
int old_state;
unsigned long flags;
spin_lock_irqsave(&ndp->lock, flags);
nc = list_first_or_null_rcu(&ndp->channel_queue,
struct ncsi_channel, link);
if (!nc) {
spin_unlock_irqrestore(&ndp->lock, flags);
goto out;
}
old_state = xchg(&nc->state, NCSI_CHANNEL_INVISIBLE);
list_del_init(&nc->link);
spin_unlock_irqrestore(&ndp->lock, flags);
ndp->active_channel = nc;
ndp->active_package = nc->package;
switch (old_state) {
case NCSI_CHANNEL_INACTIVE:
ndp->ndev.state = ncsi_dev_state_config;
ncsi_configure_channel(ndp);
break;
case NCSI_CHANNEL_ACTIVE:
ndp->ndev.state = ncsi_dev_state_suspend;
ncsi_suspend_channel(ndp);
break;
default:
netdev_err(ndp->ndev.dev, "Invalid state 0x%x on %d:%d\n",
nc->state, nc->package->id, nc->id);
ncsi_report_link(ndp, false);
return -EINVAL;
}
return 0;
out:
ndp->active_channel = NULL;
ndp->active_package = NULL;
if (ndp->flags & NCSI_DEV_RESHUFFLE) {
ndp->flags &= ~NCSI_DEV_RESHUFFLE;
return ncsi_choose_active_channel(ndp);
}
ncsi_report_link(ndp, false);
return -ENODEV;
}
static int ncsi_inet6addr_event(struct notifier_block *this,
unsigned long event, void *data)
{
struct inet6_ifaddr *ifa = data;
struct net_device *dev = ifa->idev->dev;
struct ncsi_dev *nd = ncsi_find_dev(dev);
struct ncsi_dev_priv *ndp = nd ? TO_NCSI_DEV_PRIV(nd) : NULL;
struct ncsi_package *np;
struct ncsi_channel *nc;
struct ncsi_cmd_arg nca;
bool action;
int ret;
if (!ndp || (ipv6_addr_type(&ifa->addr) &
(IPV6_ADDR_LINKLOCAL | IPV6_ADDR_LOOPBACK)))
return NOTIFY_OK;
switch (event) {
case NETDEV_UP:
action = (++ndp->inet6_addr_num) == 1;
nca.type = NCSI_PKT_CMD_EGMF;
break;
case NETDEV_DOWN:
action = (--ndp->inet6_addr_num == 0);
nca.type = NCSI_PKT_CMD_DGMF;
break;
default:
return NOTIFY_OK;
}
np = ndp->active_package;
nc = ndp->active_channel;
if (!action || !np || !nc)
return NOTIFY_OK;
if (!(nc->caps[NCSI_CAP_GENERIC].cap & NCSI_CAP_GENERIC_MC))
return NOTIFY_OK;
nca.ndp = ndp;
nca.driven = false;
nca.package = np->id;
nca.channel = nc->id;
nca.dwords[0] = nc->caps[NCSI_CAP_MC].cap;
ret = ncsi_xmit_cmd(&nca);
if (ret) {
netdev_warn(dev, "Fail to %s global multicast filter (%d)\n",
(event == NETDEV_UP) ? "enable" : "disable", ret);
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
struct ncsi_dev *ncsi_register_dev(struct net_device *dev,
void (*handler)(struct ncsi_dev *ndev))
{
struct ncsi_dev_priv *ndp;
struct ncsi_dev *nd;
unsigned long flags;
int i;
nd = ncsi_find_dev(dev);
if (nd)
return nd;
ndp = kzalloc(sizeof(*ndp), GFP_ATOMIC);
if (!ndp)
return NULL;
nd = &ndp->ndev;
nd->state = ncsi_dev_state_registered;
nd->dev = dev;
nd->handler = handler;
ndp->pending_req_num = 0;
INIT_LIST_HEAD(&ndp->channel_queue);
INIT_WORK(&ndp->work, ncsi_dev_work);
spin_lock_init(&ndp->lock);
INIT_LIST_HEAD(&ndp->packages);
ndp->request_id = 0;
for (i = 0; i < ARRAY_SIZE(ndp->requests); i++) {
ndp->requests[i].id = i;
ndp->requests[i].ndp = ndp;
setup_timer(&ndp->requests[i].timer,
ncsi_request_timeout,
(unsigned long)&ndp->requests[i]);
}
spin_lock_irqsave(&ncsi_dev_lock, flags);
#if IS_ENABLED(CONFIG_IPV6)
ndp->inet6_addr_num = 0;
if (list_empty(&ncsi_dev_list))
register_inet6addr_notifier(&ncsi_inet6addr_notifier);
#endif
list_add_tail_rcu(&ndp->node, &ncsi_dev_list);
spin_unlock_irqrestore(&ncsi_dev_lock, flags);
ndp->ptype.type = cpu_to_be16(ETH_P_NCSI);
ndp->ptype.func = ncsi_rcv_rsp;
ndp->ptype.dev = dev;
dev_add_pack(&ndp->ptype);
return nd;
}
int ncsi_start_dev(struct ncsi_dev *nd)
{
struct ncsi_dev_priv *ndp = TO_NCSI_DEV_PRIV(nd);
struct ncsi_package *np;
struct ncsi_channel *nc;
int old_state, ret;
if (nd->state != ncsi_dev_state_registered &&
nd->state != ncsi_dev_state_functional)
return -ENOTTY;
if (!(ndp->flags & NCSI_DEV_PROBED)) {
nd->state = ncsi_dev_state_probe;
schedule_work(&ndp->work);
return 0;
}
NCSI_FOR_EACH_PACKAGE(ndp, np) {
NCSI_FOR_EACH_CHANNEL(np, nc) {
old_state = xchg(&nc->state, NCSI_CHANNEL_INACTIVE);
WARN_ON_ONCE(!list_empty(&nc->link) ||
old_state == NCSI_CHANNEL_INVISIBLE);
}
}
if (ndp->flags & NCSI_DEV_HWA)
ret = ncsi_enable_hwa(ndp);
else
ret = ncsi_choose_active_channel(ndp);
return ret;
}
void ncsi_unregister_dev(struct ncsi_dev *nd)
{
struct ncsi_dev_priv *ndp = TO_NCSI_DEV_PRIV(nd);
struct ncsi_package *np, *tmp;
unsigned long flags;
dev_remove_pack(&ndp->ptype);
list_for_each_entry_safe(np, tmp, &ndp->packages, node)
ncsi_remove_package(np);
spin_lock_irqsave(&ncsi_dev_lock, flags);
list_del_rcu(&ndp->node);
#if IS_ENABLED(CONFIG_IPV6)
if (list_empty(&ncsi_dev_list))
unregister_inet6addr_notifier(&ncsi_inet6addr_notifier);
#endif
spin_unlock_irqrestore(&ncsi_dev_lock, flags);
kfree(ndp);
}
