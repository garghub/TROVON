static in_cache_entry *in_cache_get(__be32 dst_ip,
struct mpoa_client *client)
{
in_cache_entry *entry;
read_lock_bh(&client->ingress_lock);
entry = client->in_cache;
while (entry != NULL) {
if (entry->ctrl_info.in_dst_ip == dst_ip) {
refcount_inc(&entry->use);
read_unlock_bh(&client->ingress_lock);
return entry;
}
entry = entry->next;
}
read_unlock_bh(&client->ingress_lock);
return NULL;
}
static in_cache_entry *in_cache_get_with_mask(__be32 dst_ip,
struct mpoa_client *client,
__be32 mask)
{
in_cache_entry *entry;
read_lock_bh(&client->ingress_lock);
entry = client->in_cache;
while (entry != NULL) {
if ((entry->ctrl_info.in_dst_ip & mask) == (dst_ip & mask)) {
refcount_inc(&entry->use);
read_unlock_bh(&client->ingress_lock);
return entry;
}
entry = entry->next;
}
read_unlock_bh(&client->ingress_lock);
return NULL;
}
static in_cache_entry *in_cache_get_by_vcc(struct atm_vcc *vcc,
struct mpoa_client *client)
{
in_cache_entry *entry;
read_lock_bh(&client->ingress_lock);
entry = client->in_cache;
while (entry != NULL) {
if (entry->shortcut == vcc) {
refcount_inc(&entry->use);
read_unlock_bh(&client->ingress_lock);
return entry;
}
entry = entry->next;
}
read_unlock_bh(&client->ingress_lock);
return NULL;
}
static in_cache_entry *in_cache_add_entry(__be32 dst_ip,
struct mpoa_client *client)
{
in_cache_entry *entry = kzalloc(sizeof(in_cache_entry), GFP_KERNEL);
if (entry == NULL) {
pr_info("mpoa: mpoa_caches.c: new_in_cache_entry: out of memory\n");
return NULL;
}
dprintk("adding an ingress entry, ip = %pI4\n", &dst_ip);
refcount_set(&entry->use, 1);
dprintk("new_in_cache_entry: about to lock\n");
write_lock_bh(&client->ingress_lock);
entry->next = client->in_cache;
entry->prev = NULL;
if (client->in_cache != NULL)
client->in_cache->prev = entry;
client->in_cache = entry;
memcpy(entry->MPS_ctrl_ATM_addr, client->mps_ctrl_addr, ATM_ESA_LEN);
entry->ctrl_info.in_dst_ip = dst_ip;
do_gettimeofday(&(entry->tv));
entry->retry_time = client->parameters.mpc_p4;
entry->count = 1;
entry->entry_state = INGRESS_INVALID;
entry->ctrl_info.holding_time = HOLDING_TIME_DEFAULT;
refcount_inc(&entry->use);
write_unlock_bh(&client->ingress_lock);
dprintk("new_in_cache_entry: unlocked\n");
return entry;
}
static int cache_hit(in_cache_entry *entry, struct mpoa_client *mpc)
{
struct atm_mpoa_qos *qos;
struct k_message msg;
entry->count++;
if (entry->entry_state == INGRESS_RESOLVED && entry->shortcut != NULL)
return OPEN;
if (entry->entry_state == INGRESS_REFRESHING) {
if (entry->count > mpc->parameters.mpc_p1) {
msg.type = SND_MPOA_RES_RQST;
msg.content.in_info = entry->ctrl_info;
memcpy(msg.MPS_ctrl, mpc->mps_ctrl_addr, ATM_ESA_LEN);
qos = atm_mpoa_search_qos(entry->ctrl_info.in_dst_ip);
if (qos != NULL)
msg.qos = qos->qos;
msg_to_mpoad(&msg, mpc);
do_gettimeofday(&(entry->reply_wait));
entry->entry_state = INGRESS_RESOLVING;
}
if (entry->shortcut != NULL)
return OPEN;
return CLOSED;
}
if (entry->entry_state == INGRESS_RESOLVING && entry->shortcut != NULL)
return OPEN;
if (entry->count > mpc->parameters.mpc_p1 &&
entry->entry_state == INGRESS_INVALID) {
dprintk("(%s) threshold exceeded for ip %pI4, sending MPOA res req\n",
mpc->dev->name, &entry->ctrl_info.in_dst_ip);
entry->entry_state = INGRESS_RESOLVING;
msg.type = SND_MPOA_RES_RQST;
memcpy(msg.MPS_ctrl, mpc->mps_ctrl_addr, ATM_ESA_LEN);
msg.content.in_info = entry->ctrl_info;
qos = atm_mpoa_search_qos(entry->ctrl_info.in_dst_ip);
if (qos != NULL)
msg.qos = qos->qos;
msg_to_mpoad(&msg, mpc);
do_gettimeofday(&(entry->reply_wait));
}
return CLOSED;
}
static void in_cache_put(in_cache_entry *entry)
{
if (refcount_dec_and_test(&entry->use)) {
memset(entry, 0, sizeof(in_cache_entry));
kfree(entry);
}
}
static void in_cache_remove_entry(in_cache_entry *entry,
struct mpoa_client *client)
{
struct atm_vcc *vcc;
struct k_message msg;
vcc = entry->shortcut;
dprintk("removing an ingress entry, ip = %pI4\n",
&entry->ctrl_info.in_dst_ip);
if (entry->prev != NULL)
entry->prev->next = entry->next;
else
client->in_cache = entry->next;
if (entry->next != NULL)
entry->next->prev = entry->prev;
client->in_ops->put(entry);
if (client->in_cache == NULL && client->eg_cache == NULL) {
msg.type = STOP_KEEP_ALIVE_SM;
msg_to_mpoad(&msg, client);
}
if (vcc != NULL) {
eg_cache_entry *eg_entry = client->eg_ops->get_by_vcc(vcc,
client);
if (eg_entry != NULL) {
client->eg_ops->put(eg_entry);
return;
}
vcc_release_async(vcc, -EPIPE);
}
}
static void clear_count_and_expired(struct mpoa_client *client)
{
in_cache_entry *entry, *next_entry;
struct timeval now;
do_gettimeofday(&now);
write_lock_bh(&client->ingress_lock);
entry = client->in_cache;
while (entry != NULL) {
entry->count = 0;
next_entry = entry->next;
if ((now.tv_sec - entry->tv.tv_sec)
> entry->ctrl_info.holding_time) {
dprintk("holding time expired, ip = %pI4\n",
&entry->ctrl_info.in_dst_ip);
client->in_ops->remove_entry(entry, client);
}
entry = next_entry;
}
write_unlock_bh(&client->ingress_lock);
}
static void check_resolving_entries(struct mpoa_client *client)
{
struct atm_mpoa_qos *qos;
in_cache_entry *entry;
struct timeval now;
struct k_message msg;
do_gettimeofday(&now);
read_lock_bh(&client->ingress_lock);
entry = client->in_cache;
while (entry != NULL) {
if (entry->entry_state == INGRESS_RESOLVING) {
if ((now.tv_sec - entry->hold_down.tv_sec) <
client->parameters.mpc_p6) {
entry = entry->next;
continue;
}
if ((now.tv_sec - entry->reply_wait.tv_sec) >
entry->retry_time) {
entry->retry_time = MPC_C1 * (entry->retry_time);
if (entry->retry_time > client->parameters.mpc_p5) {
do_gettimeofday(&(entry->hold_down));
entry->retry_time = client->parameters.mpc_p4;
entry = entry->next;
continue;
}
memset(&(entry->hold_down), 0, sizeof(struct timeval));
msg.type = SND_MPOA_RES_RTRY;
memcpy(msg.MPS_ctrl, client->mps_ctrl_addr, ATM_ESA_LEN);
msg.content.in_info = entry->ctrl_info;
qos = atm_mpoa_search_qos(entry->ctrl_info.in_dst_ip);
if (qos != NULL)
msg.qos = qos->qos;
msg_to_mpoad(&msg, client);
do_gettimeofday(&(entry->reply_wait));
}
}
entry = entry->next;
}
read_unlock_bh(&client->ingress_lock);
}
static void refresh_entries(struct mpoa_client *client)
{
struct timeval now;
struct in_cache_entry *entry = client->in_cache;
ddprintk("refresh_entries\n");
do_gettimeofday(&now);
read_lock_bh(&client->ingress_lock);
while (entry != NULL) {
if (entry->entry_state == INGRESS_RESOLVED) {
if (!(entry->refresh_time))
entry->refresh_time = (2 * (entry->ctrl_info.holding_time))/3;
if ((now.tv_sec - entry->reply_wait.tv_sec) >
entry->refresh_time) {
dprintk("refreshing an entry.\n");
entry->entry_state = INGRESS_REFRESHING;
}
}
entry = entry->next;
}
read_unlock_bh(&client->ingress_lock);
}
static void in_destroy_cache(struct mpoa_client *mpc)
{
write_lock_irq(&mpc->ingress_lock);
while (mpc->in_cache != NULL)
mpc->in_ops->remove_entry(mpc->in_cache, mpc);
write_unlock_irq(&mpc->ingress_lock);
}
static eg_cache_entry *eg_cache_get_by_cache_id(__be32 cache_id,
struct mpoa_client *mpc)
{
eg_cache_entry *entry;
read_lock_irq(&mpc->egress_lock);
entry = mpc->eg_cache;
while (entry != NULL) {
if (entry->ctrl_info.cache_id == cache_id) {
refcount_inc(&entry->use);
read_unlock_irq(&mpc->egress_lock);
return entry;
}
entry = entry->next;
}
read_unlock_irq(&mpc->egress_lock);
return NULL;
}
static eg_cache_entry *eg_cache_get_by_tag(__be32 tag, struct mpoa_client *mpc)
{
unsigned long flags;
eg_cache_entry *entry;
read_lock_irqsave(&mpc->egress_lock, flags);
entry = mpc->eg_cache;
while (entry != NULL) {
if (entry->ctrl_info.tag == tag) {
refcount_inc(&entry->use);
read_unlock_irqrestore(&mpc->egress_lock, flags);
return entry;
}
entry = entry->next;
}
read_unlock_irqrestore(&mpc->egress_lock, flags);
return NULL;
}
static eg_cache_entry *eg_cache_get_by_vcc(struct atm_vcc *vcc,
struct mpoa_client *mpc)
{
unsigned long flags;
eg_cache_entry *entry;
read_lock_irqsave(&mpc->egress_lock, flags);
entry = mpc->eg_cache;
while (entry != NULL) {
if (entry->shortcut == vcc) {
refcount_inc(&entry->use);
read_unlock_irqrestore(&mpc->egress_lock, flags);
return entry;
}
entry = entry->next;
}
read_unlock_irqrestore(&mpc->egress_lock, flags);
return NULL;
}
static eg_cache_entry *eg_cache_get_by_src_ip(__be32 ipaddr,
struct mpoa_client *mpc)
{
eg_cache_entry *entry;
read_lock_irq(&mpc->egress_lock);
entry = mpc->eg_cache;
while (entry != NULL) {
if (entry->latest_ip_addr == ipaddr) {
refcount_inc(&entry->use);
read_unlock_irq(&mpc->egress_lock);
return entry;
}
entry = entry->next;
}
read_unlock_irq(&mpc->egress_lock);
return NULL;
}
static void eg_cache_put(eg_cache_entry *entry)
{
if (refcount_dec_and_test(&entry->use)) {
memset(entry, 0, sizeof(eg_cache_entry));
kfree(entry);
}
}
static void eg_cache_remove_entry(eg_cache_entry *entry,
struct mpoa_client *client)
{
struct atm_vcc *vcc;
struct k_message msg;
vcc = entry->shortcut;
dprintk("removing an egress entry.\n");
if (entry->prev != NULL)
entry->prev->next = entry->next;
else
client->eg_cache = entry->next;
if (entry->next != NULL)
entry->next->prev = entry->prev;
client->eg_ops->put(entry);
if (client->in_cache == NULL && client->eg_cache == NULL) {
msg.type = STOP_KEEP_ALIVE_SM;
msg_to_mpoad(&msg, client);
}
if (vcc != NULL) {
in_cache_entry *in_entry = client->in_ops->get_by_vcc(vcc, client);
if (in_entry != NULL) {
client->in_ops->put(in_entry);
return;
}
vcc_release_async(vcc, -EPIPE);
}
}
static eg_cache_entry *eg_cache_add_entry(struct k_message *msg,
struct mpoa_client *client)
{
eg_cache_entry *entry = kzalloc(sizeof(eg_cache_entry), GFP_KERNEL);
if (entry == NULL) {
pr_info("out of memory\n");
return NULL;
}
dprintk("adding an egress entry, ip = %pI4, this should be our IP\n",
&msg->content.eg_info.eg_dst_ip);
refcount_set(&entry->use, 1);
dprintk("new_eg_cache_entry: about to lock\n");
write_lock_irq(&client->egress_lock);
entry->next = client->eg_cache;
entry->prev = NULL;
if (client->eg_cache != NULL)
client->eg_cache->prev = entry;
client->eg_cache = entry;
memcpy(entry->MPS_ctrl_ATM_addr, client->mps_ctrl_addr, ATM_ESA_LEN);
entry->ctrl_info = msg->content.eg_info;
do_gettimeofday(&(entry->tv));
entry->entry_state = EGRESS_RESOLVED;
dprintk("new_eg_cache_entry cache_id %u\n",
ntohl(entry->ctrl_info.cache_id));
dprintk("mps_ip = %pI4\n", &entry->ctrl_info.mps_ip);
refcount_inc(&entry->use);
write_unlock_irq(&client->egress_lock);
dprintk("new_eg_cache_entry: unlocked\n");
return entry;
}
static void update_eg_cache_entry(eg_cache_entry *entry, uint16_t holding_time)
{
do_gettimeofday(&(entry->tv));
entry->entry_state = EGRESS_RESOLVED;
entry->ctrl_info.holding_time = holding_time;
}
static void clear_expired(struct mpoa_client *client)
{
eg_cache_entry *entry, *next_entry;
struct timeval now;
struct k_message msg;
do_gettimeofday(&now);
write_lock_irq(&client->egress_lock);
entry = client->eg_cache;
while (entry != NULL) {
next_entry = entry->next;
if ((now.tv_sec - entry->tv.tv_sec)
> entry->ctrl_info.holding_time) {
msg.type = SND_EGRESS_PURGE;
msg.content.eg_info = entry->ctrl_info;
dprintk("egress_cache: holding time expired, cache_id = %u.\n",
ntohl(entry->ctrl_info.cache_id));
msg_to_mpoad(&msg, client);
client->eg_ops->remove_entry(entry, client);
}
entry = next_entry;
}
write_unlock_irq(&client->egress_lock);
}
static void eg_destroy_cache(struct mpoa_client *mpc)
{
write_lock_irq(&mpc->egress_lock);
while (mpc->eg_cache != NULL)
mpc->eg_ops->remove_entry(mpc->eg_cache, mpc);
write_unlock_irq(&mpc->egress_lock);
}
void atm_mpoa_init_cache(struct mpoa_client *mpc)
{
mpc->in_ops = &ingress_ops;
mpc->eg_ops = &egress_ops;
}
