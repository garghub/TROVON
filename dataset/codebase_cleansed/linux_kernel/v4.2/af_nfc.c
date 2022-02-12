static int nfc_sock_create(struct net *net, struct socket *sock, int proto,
int kern)
{
int rc = -EPROTONOSUPPORT;
if (net != &init_net)
return -EAFNOSUPPORT;
if (proto < 0 || proto >= NFC_SOCKPROTO_MAX)
return -EINVAL;
read_lock(&proto_tab_lock);
if (proto_tab[proto] && try_module_get(proto_tab[proto]->owner)) {
rc = proto_tab[proto]->create(net, sock, proto_tab[proto], kern);
module_put(proto_tab[proto]->owner);
}
read_unlock(&proto_tab_lock);
return rc;
}
int nfc_proto_register(const struct nfc_protocol *nfc_proto)
{
int rc;
if (nfc_proto->id < 0 || nfc_proto->id >= NFC_SOCKPROTO_MAX)
return -EINVAL;
rc = proto_register(nfc_proto->proto, 0);
if (rc)
return rc;
write_lock(&proto_tab_lock);
if (proto_tab[nfc_proto->id])
rc = -EBUSY;
else
proto_tab[nfc_proto->id] = nfc_proto;
write_unlock(&proto_tab_lock);
return rc;
}
void nfc_proto_unregister(const struct nfc_protocol *nfc_proto)
{
write_lock(&proto_tab_lock);
proto_tab[nfc_proto->id] = NULL;
write_unlock(&proto_tab_lock);
proto_unregister(nfc_proto->proto);
}
int __init af_nfc_init(void)
{
return sock_register(&nfc_sock_family_ops);
}
void af_nfc_exit(void)
{
sock_unregister(PF_NFC);
}
