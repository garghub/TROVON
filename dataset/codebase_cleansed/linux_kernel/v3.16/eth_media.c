static int tipc_eth_addr2str(struct tipc_media_addr *addr,
char *strbuf, int bufsz)
{
if (bufsz < 18)
return 1;
sprintf(strbuf, "%pM", addr->value);
return 0;
}
static int tipc_eth_addr2msg(char *msg, struct tipc_media_addr *addr)
{
memset(msg, 0, TIPC_MEDIA_ADDR_SIZE);
msg[TIPC_MEDIA_TYPE_OFFSET] = TIPC_MEDIA_TYPE_ETH;
memcpy(msg + ETH_ADDR_OFFSET, addr->value, ETH_ALEN);
return 0;
}
static int tipc_eth_raw2addr(struct tipc_bearer *b,
struct tipc_media_addr *addr,
char *msg)
{
char bcast_mac[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
memset(addr, 0, sizeof(*addr));
ether_addr_copy(addr->value, msg);
addr->media_id = TIPC_MEDIA_TYPE_ETH;
addr->broadcast = !memcmp(addr->value, bcast_mac, ETH_ALEN);
return 0;
}
static int tipc_eth_msg2addr(struct tipc_bearer *b,
struct tipc_media_addr *addr,
char *msg)
{
msg += ETH_ADDR_OFFSET;
return tipc_eth_raw2addr(b, addr, msg);
}
