int inet_add_protocol(const struct net_protocol *prot, unsigned char protocol)
{
if (!prot->netns_ok) {
pr_err("Protocol %u is not namespace aware, cannot register.\n",
protocol);
return -EINVAL;
}
return !cmpxchg((const struct net_protocol **)&inet_protos[protocol],
NULL, prot) ? 0 : -1;
}
int inet_add_offload(const struct net_offload *prot, unsigned char protocol)
{
return !cmpxchg((const struct net_offload **)&inet_offloads[protocol],
NULL, prot) ? 0 : -1;
}
int inet_del_protocol(const struct net_protocol *prot, unsigned char protocol)
{
int ret;
ret = (cmpxchg((const struct net_protocol **)&inet_protos[protocol],
prot, NULL) == prot) ? 0 : -1;
synchronize_net();
return ret;
}
int inet_del_offload(const struct net_offload *prot, unsigned char protocol)
{
int ret;
ret = (cmpxchg((const struct net_offload **)&inet_offloads[protocol],
prot, NULL) == prot) ? 0 : -1;
synchronize_net();
return ret;
}
