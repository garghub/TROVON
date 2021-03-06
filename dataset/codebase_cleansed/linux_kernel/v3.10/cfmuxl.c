struct cflayer *cfmuxl_create(void)
{
struct cfmuxl *this = kmalloc(sizeof(struct cfmuxl), GFP_ATOMIC);
if (!this)
return NULL;
memset(this, 0, sizeof(*this));
this->layer.receive = cfmuxl_receive;
this->layer.transmit = cfmuxl_transmit;
this->layer.ctrlcmd = cfmuxl_ctrlcmd;
INIT_LIST_HEAD(&this->srvl_list);
INIT_LIST_HEAD(&this->frml_list);
spin_lock_init(&this->transmit_lock);
spin_lock_init(&this->receive_lock);
snprintf(this->layer.name, CAIF_LAYER_NAME_SZ, "mux");
return &this->layer;
}
int cfmuxl_set_dnlayer(struct cflayer *layr, struct cflayer *dn, u8 phyid)
{
struct cfmuxl *muxl = (struct cfmuxl *) layr;
spin_lock_bh(&muxl->transmit_lock);
list_add_rcu(&dn->node, &muxl->frml_list);
spin_unlock_bh(&muxl->transmit_lock);
return 0;
}
static struct cflayer *get_from_id(struct list_head *list, u16 id)
{
struct cflayer *lyr;
list_for_each_entry_rcu(lyr, list, node) {
if (lyr->id == id)
return lyr;
}
return NULL;
}
int cfmuxl_set_uplayer(struct cflayer *layr, struct cflayer *up, u8 linkid)
{
struct cfmuxl *muxl = container_obj(layr);
struct cflayer *old;
spin_lock_bh(&muxl->receive_lock);
old = get_from_id(&muxl->srvl_list, linkid);
if (old != NULL)
list_del_rcu(&old->node);
list_add_rcu(&up->node, &muxl->srvl_list);
spin_unlock_bh(&muxl->receive_lock);
return 0;
}
struct cflayer *cfmuxl_remove_dnlayer(struct cflayer *layr, u8 phyid)
{
struct cfmuxl *muxl = container_obj(layr);
struct cflayer *dn;
int idx = phyid % DN_CACHE_SIZE;
spin_lock_bh(&muxl->transmit_lock);
RCU_INIT_POINTER(muxl->dn_cache[idx], NULL);
dn = get_from_id(&muxl->frml_list, phyid);
if (dn == NULL)
goto out;
list_del_rcu(&dn->node);
caif_assert(dn != NULL);
out:
spin_unlock_bh(&muxl->transmit_lock);
return dn;
}
static struct cflayer *get_up(struct cfmuxl *muxl, u16 id)
{
struct cflayer *up;
int idx = id % UP_CACHE_SIZE;
up = rcu_dereference(muxl->up_cache[idx]);
if (up == NULL || up->id != id) {
spin_lock_bh(&muxl->receive_lock);
up = get_from_id(&muxl->srvl_list, id);
rcu_assign_pointer(muxl->up_cache[idx], up);
spin_unlock_bh(&muxl->receive_lock);
}
return up;
}
static struct cflayer *get_dn(struct cfmuxl *muxl, struct dev_info *dev_info)
{
struct cflayer *dn;
int idx = dev_info->id % DN_CACHE_SIZE;
dn = rcu_dereference(muxl->dn_cache[idx]);
if (dn == NULL || dn->id != dev_info->id) {
spin_lock_bh(&muxl->transmit_lock);
dn = get_from_id(&muxl->frml_list, dev_info->id);
rcu_assign_pointer(muxl->dn_cache[idx], dn);
spin_unlock_bh(&muxl->transmit_lock);
}
return dn;
}
struct cflayer *cfmuxl_remove_uplayer(struct cflayer *layr, u8 id)
{
struct cflayer *up;
struct cfmuxl *muxl = container_obj(layr);
int idx = id % UP_CACHE_SIZE;
if (id == 0) {
pr_warn("Trying to remove control layer\n");
return NULL;
}
spin_lock_bh(&muxl->receive_lock);
up = get_from_id(&muxl->srvl_list, id);
if (up == NULL)
goto out;
RCU_INIT_POINTER(muxl->up_cache[idx], NULL);
list_del_rcu(&up->node);
out:
spin_unlock_bh(&muxl->receive_lock);
return up;
}
static int cfmuxl_receive(struct cflayer *layr, struct cfpkt *pkt)
{
int ret;
struct cfmuxl *muxl = container_obj(layr);
u8 id;
struct cflayer *up;
if (cfpkt_extr_head(pkt, &id, 1) < 0) {
pr_err("erroneous Caif Packet\n");
cfpkt_destroy(pkt);
return -EPROTO;
}
rcu_read_lock();
up = get_up(muxl, id);
if (up == NULL) {
pr_debug("Received data on unknown link ID = %d (0x%x)"
" up == NULL", id, id);
cfpkt_destroy(pkt);
rcu_read_unlock();
return 0;
}
cfsrvl_get(up);
rcu_read_unlock();
ret = up->receive(up, pkt);
cfsrvl_put(up);
return ret;
}
static int cfmuxl_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
struct cfmuxl *muxl = container_obj(layr);
int err;
u8 linkid;
struct cflayer *dn;
struct caif_payload_info *info = cfpkt_info(pkt);
BUG_ON(!info);
rcu_read_lock();
dn = get_dn(muxl, info->dev_info);
if (dn == NULL) {
pr_debug("Send data on unknown phy ID = %d (0x%x)\n",
info->dev_info->id, info->dev_info->id);
rcu_read_unlock();
cfpkt_destroy(pkt);
return -ENOTCONN;
}
info->hdr_len += 1;
linkid = info->channel_id;
cfpkt_add_head(pkt, &linkid, 1);
cffrml_hold(dn);
rcu_read_unlock();
err = dn->transmit(dn, pkt);
cffrml_put(dn);
return err;
}
static void cfmuxl_ctrlcmd(struct cflayer *layr, enum caif_ctrlcmd ctrl,
int phyid)
{
struct cfmuxl *muxl = container_obj(layr);
struct cflayer *layer;
rcu_read_lock();
list_for_each_entry_rcu(layer, &muxl->srvl_list, node) {
if (cfsrvl_phyid_match(layer, phyid) && layer->ctrlcmd) {
if ((ctrl == _CAIF_CTRLCMD_PHYIF_DOWN_IND ||
ctrl == CAIF_CTRLCMD_REMOTE_SHUTDOWN_IND) &&
layer->id != 0)
cfmuxl_remove_uplayer(layr, layer->id);
layer->ctrlcmd(layer, ctrl, phyid);
}
}
rcu_read_unlock();
}
