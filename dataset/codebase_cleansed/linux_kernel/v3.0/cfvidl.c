struct cflayer *cfvidl_create(u8 channel_id, struct dev_info *dev_info)
{
struct cfsrvl *vid = kmalloc(sizeof(struct cfsrvl), GFP_ATOMIC);
if (!vid) {
pr_warn("Out of memory\n");
return NULL;
}
caif_assert(offsetof(struct cfsrvl, layer) == 0);
memset(vid, 0, sizeof(struct cfsrvl));
cfsrvl_init(vid, channel_id, dev_info, false);
vid->layer.receive = cfvidl_receive;
vid->layer.transmit = cfvidl_transmit;
snprintf(vid->layer.name, CAIF_LAYER_NAME_SZ - 1, "vid1");
return &vid->layer;
}
static int cfvidl_receive(struct cflayer *layr, struct cfpkt *pkt)
{
u32 videoheader;
if (cfpkt_extr_head(pkt, &videoheader, 4) < 0) {
pr_err("Packet is erroneous!\n");
cfpkt_destroy(pkt);
return -EPROTO;
}
return layr->up->receive(layr->up, pkt);
}
static int cfvidl_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
struct cfsrvl *service = container_obj(layr);
struct caif_payload_info *info;
u32 videoheader = 0;
int ret;
if (!cfsrvl_ready(service, &ret))
return ret;
cfpkt_add_head(pkt, &videoheader, 4);
info = cfpkt_info(pkt);
info->channel_id = service->layer.id;
info->dev_info = &service->dev_info;
return layr->dn->transmit(layr->dn, pkt);
}
