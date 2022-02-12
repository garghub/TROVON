struct cflayer *cfdbgl_create(u8 channel_id, struct dev_info *dev_info)
{
struct cfsrvl *dbg = kmalloc(sizeof(struct cfsrvl), GFP_ATOMIC);
if (!dbg) {
pr_warn("Out of memory\n");
return NULL;
}
caif_assert(offsetof(struct cfsrvl, layer) == 0);
memset(dbg, 0, sizeof(struct cfsrvl));
cfsrvl_init(dbg, channel_id, dev_info, false);
dbg->layer.receive = cfdbgl_receive;
dbg->layer.transmit = cfdbgl_transmit;
snprintf(dbg->layer.name, CAIF_LAYER_NAME_SZ - 1, "dbg%d", channel_id);
return &dbg->layer;
}
static int cfdbgl_receive(struct cflayer *layr, struct cfpkt *pkt)
{
return layr->up->receive(layr->up, pkt);
}
static int cfdbgl_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
struct cfsrvl *service = container_obj(layr);
struct caif_payload_info *info;
int ret;
if (!cfsrvl_ready(service, &ret))
return ret;
info = cfpkt_info(pkt);
info->channel_id = service->layer.id;
info->dev_info = &service->dev_info;
return layr->dn->transmit(layr->dn, pkt);
}
