static int tipc_ib_addr2str(struct tipc_media_addr *a, char *str_buf,
int str_size)
{
if (str_size < 60)
return 1;
sprintf(str_buf, "%20phC", a->value);
return 0;
}
static int tipc_ib_addr2msg(char *msg, struct tipc_media_addr *addr)
{
memset(msg, 0, TIPC_MEDIA_ADDR_SIZE);
memcpy(msg, addr->value, INFINIBAND_ALEN);
return 0;
}
static int tipc_ib_raw2addr(struct tipc_bearer *b,
struct tipc_media_addr *addr,
char *msg)
{
memset(addr, 0, sizeof(*addr));
memcpy(addr->value, msg, INFINIBAND_ALEN);
addr->media_id = TIPC_MEDIA_TYPE_IB;
addr->broadcast = !memcmp(msg, b->bcast_addr.value,
INFINIBAND_ALEN);
return 0;
}
static int tipc_ib_msg2addr(struct tipc_bearer *b,
struct tipc_media_addr *addr,
char *msg)
{
return tipc_ib_raw2addr(b, addr, msg);
}
