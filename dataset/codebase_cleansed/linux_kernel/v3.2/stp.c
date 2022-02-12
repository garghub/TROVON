static int stp_pdu_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
const struct ethhdr *eh = eth_hdr(skb);
const struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
const struct stp_proto *proto;
if (pdu->ssap != LLC_SAP_BSPAN ||
pdu->dsap != LLC_SAP_BSPAN ||
pdu->ctrl_1 != LLC_PDU_TYPE_U)
goto err;
if (eh->h_dest[5] >= GARP_ADDR_MIN && eh->h_dest[5] <= GARP_ADDR_MAX) {
proto = rcu_dereference(garp_protos[eh->h_dest[5] -
GARP_ADDR_MIN]);
if (proto &&
compare_ether_addr(eh->h_dest, proto->group_address))
goto err;
} else
proto = rcu_dereference(stp_proto);
if (!proto)
goto err;
proto->rcv(proto, skb, dev);
return 0;
err:
kfree_skb(skb);
return 0;
}
int stp_proto_register(const struct stp_proto *proto)
{
int err = 0;
mutex_lock(&stp_proto_mutex);
if (sap_registered++ == 0) {
sap = llc_sap_open(LLC_SAP_BSPAN, stp_pdu_rcv);
if (!sap) {
err = -ENOMEM;
goto out;
}
}
if (is_zero_ether_addr(proto->group_address))
rcu_assign_pointer(stp_proto, proto);
else
rcu_assign_pointer(garp_protos[proto->group_address[5] -
GARP_ADDR_MIN], proto);
out:
mutex_unlock(&stp_proto_mutex);
return err;
}
void stp_proto_unregister(const struct stp_proto *proto)
{
mutex_lock(&stp_proto_mutex);
if (is_zero_ether_addr(proto->group_address))
RCU_INIT_POINTER(stp_proto, NULL);
else
RCU_INIT_POINTER(garp_protos[proto->group_address[5] -
GARP_ADDR_MIN], NULL);
synchronize_rcu();
if (--sap_registered == 0)
llc_sap_put(sap);
mutex_unlock(&stp_proto_mutex);
}
