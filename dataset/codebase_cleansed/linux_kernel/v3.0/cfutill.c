struct cflayer *cfutill_create(u8 channel_id, struct dev_info *dev_info)
{
struct cfsrvl *util = kmalloc(sizeof(struct cfsrvl), GFP_ATOMIC);
if (!util) {
pr_warn("Out of memory\n");
return NULL;
}
caif_assert(offsetof(struct cfsrvl, layer) == 0);
memset(util, 0, sizeof(struct cfsrvl));
cfsrvl_init(util, channel_id, dev_info, true);
util->layer.receive = cfutill_receive;
util->layer.transmit = cfutill_transmit;
snprintf(util->layer.name, CAIF_LAYER_NAME_SZ - 1, "util1");
return &util->layer;
}
static int cfutill_receive(struct cflayer *layr, struct cfpkt *pkt)
{
u8 cmd = -1;
struct cfsrvl *service = container_obj(layr);
caif_assert(layr != NULL);
caif_assert(layr->up != NULL);
caif_assert(layr->up->receive != NULL);
caif_assert(layr->up->ctrlcmd != NULL);
if (cfpkt_extr_head(pkt, &cmd, 1) < 0) {
pr_err("Packet is erroneous!\n");
cfpkt_destroy(pkt);
return -EPROTO;
}
switch (cmd) {
case UTIL_PAYLOAD:
return layr->up->receive(layr->up, pkt);
case UTIL_FLOW_OFF:
layr->ctrlcmd(layr, CAIF_CTRLCMD_FLOW_OFF_IND, 0);
cfpkt_destroy(pkt);
return 0;
case UTIL_FLOW_ON:
layr->ctrlcmd(layr, CAIF_CTRLCMD_FLOW_ON_IND, 0);
cfpkt_destroy(pkt);
return 0;
case UTIL_REMOTE_SHUTDOWN:
pr_err("REMOTE SHUTDOWN REQUEST RECEIVED\n");
layr->ctrlcmd(layr, CAIF_CTRLCMD_REMOTE_SHUTDOWN_IND, 0);
service->open = false;
cfpkt_destroy(pkt);
return 0;
default:
cfpkt_destroy(pkt);
pr_warn("Unknown service control %d (0x%x)\n", cmd, cmd);
return -EPROTO;
}
}
static int cfutill_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
u8 zero = 0;
struct caif_payload_info *info;
int ret;
struct cfsrvl *service = container_obj(layr);
caif_assert(layr != NULL);
caif_assert(layr->dn != NULL);
caif_assert(layr->dn->transmit != NULL);
if (!cfsrvl_ready(service, &ret))
return ret;
cfpkt_add_head(pkt, &zero, 1);
info = cfpkt_info(pkt);
info->channel_id = service->layer.id;
info->hdr_len = 1;
info->dev_info = &service->dev_info;
return layr->dn->transmit(layr->dn, pkt);
}
