static int ncsi_validate_aen_pkt(struct ncsi_aen_pkt_hdr *h,
const unsigned short payload)
{
u32 checksum;
__be32 *pchecksum;
if (h->common.revision != NCSI_PKT_REVISION)
return -EINVAL;
if (ntohs(h->common.length) != payload)
return -EINVAL;
pchecksum = (__be32 *)((void *)(h + 1) + payload - 4);
if (ntohl(*pchecksum) == 0)
return 0;
checksum = ncsi_calculate_checksum((unsigned char *)h,
sizeof(*h) + payload - 4);
if (*pchecksum != htonl(checksum))
return -EINVAL;
return 0;
}
static int ncsi_aen_handler_lsc(struct ncsi_dev_priv *ndp,
struct ncsi_aen_pkt_hdr *h)
{
struct ncsi_aen_lsc_pkt *lsc;
struct ncsi_channel *nc;
struct ncsi_channel_mode *ncm;
unsigned long old_data;
unsigned long flags;
ncsi_find_package_and_channel(ndp, h->common.channel, NULL, &nc);
if (!nc)
return -ENODEV;
ncm = &nc->modes[NCSI_MODE_LINK];
lsc = (struct ncsi_aen_lsc_pkt *)h;
old_data = ncm->data[2];
ncm->data[2] = ntohl(lsc->status);
ncm->data[4] = ntohl(lsc->oem_status);
if (!((old_data ^ ncm->data[2]) & 0x1) ||
!list_empty(&nc->link))
return 0;
if (!(nc->state == NCSI_CHANNEL_INACTIVE && (ncm->data[2] & 0x1)) &&
!(nc->state == NCSI_CHANNEL_ACTIVE && !(ncm->data[2] & 0x1)))
return 0;
if (!(ndp->flags & NCSI_DEV_HWA) &&
nc->state == NCSI_CHANNEL_ACTIVE)
ndp->flags |= NCSI_DEV_RESHUFFLE;
ncsi_stop_channel_monitor(nc);
spin_lock_irqsave(&ndp->lock, flags);
list_add_tail_rcu(&nc->link, &ndp->channel_queue);
spin_unlock_irqrestore(&ndp->lock, flags);
return ncsi_process_next_channel(ndp);
}
static int ncsi_aen_handler_cr(struct ncsi_dev_priv *ndp,
struct ncsi_aen_pkt_hdr *h)
{
struct ncsi_channel *nc;
unsigned long flags;
ncsi_find_package_and_channel(ndp, h->common.channel, NULL, &nc);
if (!nc)
return -ENODEV;
if (!list_empty(&nc->link) ||
nc->state != NCSI_CHANNEL_ACTIVE)
return 0;
ncsi_stop_channel_monitor(nc);
spin_lock_irqsave(&ndp->lock, flags);
xchg(&nc->state, NCSI_CHANNEL_INACTIVE);
list_add_tail_rcu(&nc->link, &ndp->channel_queue);
spin_unlock_irqrestore(&ndp->lock, flags);
return ncsi_process_next_channel(ndp);
}
static int ncsi_aen_handler_hncdsc(struct ncsi_dev_priv *ndp,
struct ncsi_aen_pkt_hdr *h)
{
struct ncsi_channel *nc;
struct ncsi_channel_mode *ncm;
struct ncsi_aen_hncdsc_pkt *hncdsc;
unsigned long flags;
ncsi_find_package_and_channel(ndp, h->common.channel, NULL, &nc);
if (!nc)
return -ENODEV;
ncm = &nc->modes[NCSI_MODE_LINK];
hncdsc = (struct ncsi_aen_hncdsc_pkt *)h;
ncm->data[3] = ntohl(hncdsc->status);
if (!list_empty(&nc->link) ||
nc->state != NCSI_CHANNEL_ACTIVE ||
(ncm->data[3] & 0x1))
return 0;
if (ndp->flags & NCSI_DEV_HWA)
ndp->flags |= NCSI_DEV_RESHUFFLE;
ncsi_stop_channel_monitor(nc);
spin_lock_irqsave(&ndp->lock, flags);
list_add_tail_rcu(&nc->link, &ndp->channel_queue);
spin_unlock_irqrestore(&ndp->lock, flags);
ncsi_process_next_channel(ndp);
return 0;
}
int ncsi_aen_handler(struct ncsi_dev_priv *ndp, struct sk_buff *skb)
{
struct ncsi_aen_pkt_hdr *h;
struct ncsi_aen_handler *nah = NULL;
int i, ret;
h = (struct ncsi_aen_pkt_hdr *)skb_network_header(skb);
for (i = 0; i < ARRAY_SIZE(ncsi_aen_handlers); i++) {
if (ncsi_aen_handlers[i].type == h->type) {
nah = &ncsi_aen_handlers[i];
break;
}
}
if (!nah) {
netdev_warn(ndp->ndev.dev, "Invalid AEN (0x%x) received\n",
h->type);
return -ENOENT;
}
ret = ncsi_validate_aen_pkt(h, nah->payload);
if (ret)
goto out;
ret = nah->handler(ndp, h);
out:
consume_skb(skb);
return ret;
}
