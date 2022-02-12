static int tipc_eth_addr2str(struct tipc_media_addr *a, char *str_buf,
int str_size)
{
if (str_size < 18)
return 1;
sprintf(str_buf, "%pM", a->value);
return 0;
}
static int tipc_eth_addr2msg(struct tipc_media_addr *a, char *msg_area)
{
memset(msg_area, 0, TIPC_MEDIA_ADDR_SIZE);
msg_area[TIPC_MEDIA_TYPE_OFFSET] = TIPC_MEDIA_TYPE_ETH;
memcpy(msg_area + ETH_ADDR_OFFSET, a->value, ETH_ALEN);
return 0;
}
static int tipc_eth_msg2addr(const struct tipc_bearer *tb_ptr,
struct tipc_media_addr *a, char *msg_area)
{
if (msg_area[TIPC_MEDIA_TYPE_OFFSET] != TIPC_MEDIA_TYPE_ETH)
return 1;
tipc_l2_media_addr_set(tb_ptr, a, msg_area + ETH_ADDR_OFFSET);
return 0;
}
