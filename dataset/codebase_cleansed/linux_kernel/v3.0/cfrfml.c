static void cfrfml_release(struct cflayer *layer)
{
struct cfsrvl *srvl = container_of(layer, struct cfsrvl, layer);
struct cfrfml *rfml = container_obj(&srvl->layer);
if (rfml->incomplete_frm)
cfpkt_destroy(rfml->incomplete_frm);
kfree(srvl);
}
struct cflayer *cfrfml_create(u8 channel_id, struct dev_info *dev_info,
int mtu_size)
{
int tmp;
struct cfrfml *this =
kzalloc(sizeof(struct cfrfml), GFP_ATOMIC);
if (!this) {
pr_warn("Out of memory\n");
return NULL;
}
cfsrvl_init(&this->serv, channel_id, dev_info, false);
this->serv.release = cfrfml_release;
this->serv.layer.receive = cfrfml_receive;
this->serv.layer.transmit = cfrfml_transmit;
tmp = (mtu_size - RFM_HEAD_SIZE - 6) / 16;
tmp *= 16;
this->fragment_size = tmp;
spin_lock_init(&this->sync);
snprintf(this->serv.layer.name, CAIF_LAYER_NAME_SZ,
"rfm%d", channel_id);
return &this->serv.layer;
}
static struct cfpkt *rfm_append(struct cfrfml *rfml, char *seghead,
struct cfpkt *pkt, int *err)
{
struct cfpkt *tmppkt;
*err = -EPROTO;
if (cfpkt_extr_head(pkt, seghead, 6) < 0)
return NULL;
if (memcmp(seghead, rfml->seghead, 6) != 0)
return NULL;
tmppkt = cfpkt_append(rfml->incomplete_frm, pkt,
rfml->pdu_size + RFM_HEAD_SIZE);
*err = -ENOMEM;
if (tmppkt == NULL)
return NULL;
*err = 0;
return tmppkt;
}
static int cfrfml_receive(struct cflayer *layr, struct cfpkt *pkt)
{
u8 tmp;
bool segmented;
int err;
u8 seghead[6];
struct cfrfml *rfml;
struct cfpkt *tmppkt = NULL;
caif_assert(layr->up != NULL);
caif_assert(layr->receive != NULL);
rfml = container_obj(layr);
spin_lock(&rfml->sync);
err = -EPROTO;
if (cfpkt_extr_head(pkt, &tmp, 1) < 0)
goto out;
segmented = tmp & RFM_SEGMENTATION_BIT;
if (segmented) {
if (rfml->incomplete_frm == NULL) {
if (cfpkt_peek_head(pkt, rfml->seghead, 6) < 0)
goto out;
rfml->pdu_size = get_unaligned_le16(rfml->seghead+4);
if (cfpkt_erroneous(pkt))
goto out;
rfml->incomplete_frm = pkt;
pkt = NULL;
} else {
tmppkt = rfm_append(rfml, seghead, pkt, &err);
if (tmppkt == NULL)
goto out;
if (cfpkt_erroneous(tmppkt))
goto out;
rfml->incomplete_frm = tmppkt;
if (cfpkt_erroneous(tmppkt))
goto out;
}
err = 0;
goto out;
}
if (rfml->incomplete_frm) {
tmppkt = rfm_append(rfml, seghead, pkt, &err);
if (tmppkt == NULL)
goto out;
if (cfpkt_erroneous(tmppkt))
goto out;
rfml->incomplete_frm = NULL;
pkt = tmppkt;
tmppkt = NULL;
err = EPROTO;
if (rfml->pdu_size != cfpkt_getlen(pkt) - RFM_HEAD_SIZE + 1)
goto out;
}
err = rfml->serv.layer.up->receive(rfml->serv.layer.up, pkt);
out:
if (err != 0) {
if (tmppkt)
cfpkt_destroy(tmppkt);
if (pkt)
cfpkt_destroy(pkt);
if (rfml->incomplete_frm)
cfpkt_destroy(rfml->incomplete_frm);
rfml->incomplete_frm = NULL;
pr_info("Connection error %d triggered on RFM link\n", err);
layr->up->ctrlcmd(layr->up, CAIF_CTRLCMD_REMOTE_SHUTDOWN_IND,
rfml->serv.dev_info.id);
}
spin_unlock(&rfml->sync);
return err;
}
static int cfrfml_transmit_segment(struct cfrfml *rfml, struct cfpkt *pkt)
{
caif_assert(cfpkt_getlen(pkt) < rfml->fragment_size);
cfpkt_info(pkt)->channel_id = rfml->serv.layer.id;
cfpkt_info(pkt)->hdr_len = RFM_HEAD_SIZE;
cfpkt_info(pkt)->dev_info = &rfml->serv.dev_info;
return rfml->serv.layer.dn->transmit(rfml->serv.layer.dn, pkt);
}
static int cfrfml_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
int err;
u8 seg;
u8 head[6];
struct cfpkt *rearpkt = NULL;
struct cfpkt *frontpkt = pkt;
struct cfrfml *rfml = container_obj(layr);
caif_assert(layr->dn != NULL);
caif_assert(layr->dn->transmit != NULL);
if (!cfsrvl_ready(&rfml->serv, &err))
return err;
err = -EPROTO;
if (cfpkt_getlen(pkt) <= RFM_HEAD_SIZE-1)
goto out;
err = 0;
if (cfpkt_getlen(pkt) > rfml->fragment_size + RFM_HEAD_SIZE)
err = cfpkt_peek_head(pkt, head, 6);
if (err < 0)
goto out;
while (cfpkt_getlen(frontpkt) > rfml->fragment_size + RFM_HEAD_SIZE) {
seg = 1;
err = -EPROTO;
if (cfpkt_add_head(frontpkt, &seg, 1) < 0)
goto out;
rearpkt = cfpkt_split(frontpkt, rfml->fragment_size);
if (rearpkt == NULL)
goto out;
err = cfrfml_transmit_segment(rfml, frontpkt);
if (err != 0)
goto out;
frontpkt = rearpkt;
rearpkt = NULL;
err = -ENOMEM;
if (frontpkt == NULL)
goto out;
err = -EPROTO;
if (cfpkt_add_head(frontpkt, head, 6) < 0)
goto out;
}
seg = 0;
err = -EPROTO;
if (cfpkt_add_head(frontpkt, &seg, 1) < 0)
goto out;
err = cfrfml_transmit_segment(rfml, frontpkt);
frontpkt = NULL;
out:
if (err != 0) {
pr_info("Connection error %d triggered on RFM link\n", err);
layr->up->ctrlcmd(layr->up, CAIF_CTRLCMD_REMOTE_SHUTDOWN_IND,
rfml->serv.dev_info.id);
if (rearpkt)
cfpkt_destroy(rearpkt);
if (frontpkt && frontpkt != pkt) {
cfpkt_destroy(frontpkt);
err = 0;
}
}
return err;
}
