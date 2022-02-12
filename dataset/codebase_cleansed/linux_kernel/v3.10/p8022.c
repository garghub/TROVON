static int p8022_request(struct datalink_proto *dl, struct sk_buff *skb,
unsigned char *dest)
{
llc_build_and_send_ui_pkt(dl->sap, skb, dest, dl->sap->laddr.lsap);
return 0;
}
struct datalink_proto *register_8022_client(unsigned char type,
int (*func)(struct sk_buff *skb,
struct net_device *dev,
struct packet_type *pt,
struct net_device *orig_dev))
{
struct datalink_proto *proto;
proto = kmalloc(sizeof(*proto), GFP_ATOMIC);
if (proto) {
proto->type[0] = type;
proto->header_length = 3;
proto->request = p8022_request;
proto->sap = llc_sap_open(type, func);
if (!proto->sap) {
kfree(proto);
proto = NULL;
}
}
return proto;
}
void unregister_8022_client(struct datalink_proto *proto)
{
llc_sap_put(proto->sap);
kfree(proto);
}
