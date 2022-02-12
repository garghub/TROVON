void
cxgb_get_4tuple(struct cpl_pass_accept_req *req, enum chip_type type,
int *iptype, __u8 *local_ip, __u8 *peer_ip,
__be16 *local_port, __be16 *peer_port)
{
int eth_len = (CHELSIO_CHIP_VERSION(type) <= CHELSIO_T5) ?
ETH_HDR_LEN_G(be32_to_cpu(req->hdr_len)) :
T6_ETH_HDR_LEN_G(be32_to_cpu(req->hdr_len));
int ip_len = (CHELSIO_CHIP_VERSION(type) <= CHELSIO_T5) ?
IP_HDR_LEN_G(be32_to_cpu(req->hdr_len)) :
T6_IP_HDR_LEN_G(be32_to_cpu(req->hdr_len));
struct iphdr *ip = (struct iphdr *)((u8 *)(req + 1) + eth_len);
struct ipv6hdr *ip6 = (struct ipv6hdr *)((u8 *)(req + 1) + eth_len);
struct tcphdr *tcp = (struct tcphdr *)
((u8 *)(req + 1) + eth_len + ip_len);
if (ip->version == 4) {
pr_debug("%s saddr 0x%x daddr 0x%x sport %u dport %u\n",
__func__, ntohl(ip->saddr), ntohl(ip->daddr),
ntohs(tcp->source), ntohs(tcp->dest));
*iptype = 4;
memcpy(peer_ip, &ip->saddr, 4);
memcpy(local_ip, &ip->daddr, 4);
} else {
pr_debug("%s saddr %pI6 daddr %pI6 sport %u dport %u\n",
__func__, ip6->saddr.s6_addr, ip6->daddr.s6_addr,
ntohs(tcp->source), ntohs(tcp->dest));
*iptype = 6;
memcpy(peer_ip, ip6->saddr.s6_addr, 16);
memcpy(local_ip, ip6->daddr.s6_addr, 16);
}
*peer_port = tcp->source;
*local_port = tcp->dest;
}
