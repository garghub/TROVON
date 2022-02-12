static int tipc_ib_addr2str(struct tipc_media_addr *a, char *str_buf,
int str_size)
{
if (str_size < 60)
return 1;
sprintf(str_buf, "%20phC", a->value);
return 0;
}
static int tipc_ib_addr2msg(struct tipc_media_addr *a, char *msg_area)
{
memset(msg_area, 0, TIPC_MEDIA_ADDR_SIZE);
msg_area[TIPC_MEDIA_TYPE_OFFSET] = TIPC_MEDIA_TYPE_IB;
memcpy(msg_area, a->value, INFINIBAND_ALEN);
return 0;
}
static int tipc_ib_msg2addr(const struct tipc_bearer *tb_ptr,
struct tipc_media_addr *a, char *msg_area)
{
tipc_l2_media_addr_set(tb_ptr, a, msg_area);
return 0;
}
