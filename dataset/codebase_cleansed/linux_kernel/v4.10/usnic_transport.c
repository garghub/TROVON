const char *usnic_transport_to_str(enum usnic_transport_type type)
{
switch (type) {
case USNIC_TRANSPORT_UNKNOWN:
return "Unknown";
case USNIC_TRANSPORT_ROCE_CUSTOM:
return "roce custom";
case USNIC_TRANSPORT_IPV4_UDP:
return "IPv4 UDP";
case USNIC_TRANSPORT_MAX:
return "Max?";
default:
return "Not known";
}
}
int usnic_transport_sock_to_str(char *buf, int buf_sz,
struct socket *sock)
{
int err;
uint32_t addr;
uint16_t port;
int proto;
memset(buf, 0, buf_sz);
err = usnic_transport_sock_get_addr(sock, &proto, &addr, &port);
if (err)
return 0;
return scnprintf(buf, buf_sz, "Proto:%u Addr:%pI4h Port:%hu",
proto, &addr, port);
}
u16 usnic_transport_rsrv_port(enum usnic_transport_type type, u16 port_num)
{
if (type == USNIC_TRANSPORT_ROCE_CUSTOM) {
spin_lock(&roce_bitmap_lock);
if (!port_num) {
port_num = bitmap_find_next_zero_area(roce_bitmap,
ROCE_BITMAP_SZ,
roce_next_port ,
1 ,
0 );
roce_next_port = (port_num & 4095) + 1;
} else if (test_bit(port_num, roce_bitmap)) {
usnic_err("Failed to allocate port for %s\n",
usnic_transport_to_str(type));
spin_unlock(&roce_bitmap_lock);
goto out_fail;
}
bitmap_set(roce_bitmap, port_num, 1);
spin_unlock(&roce_bitmap_lock);
} else {
usnic_err("Failed to allocate port - transport %s unsupported\n",
usnic_transport_to_str(type));
goto out_fail;
}
usnic_dbg("Allocating port %hu for %s\n", port_num,
usnic_transport_to_str(type));
return port_num;
out_fail:
return 0;
}
void usnic_transport_unrsrv_port(enum usnic_transport_type type, u16 port_num)
{
if (type == USNIC_TRANSPORT_ROCE_CUSTOM) {
spin_lock(&roce_bitmap_lock);
if (!port_num) {
usnic_err("Unreserved unvalid port num 0 for %s\n",
usnic_transport_to_str(type));
goto out_roce_custom;
}
if (!test_bit(port_num, roce_bitmap)) {
usnic_err("Unreserving invalid %hu for %s\n",
port_num,
usnic_transport_to_str(type));
goto out_roce_custom;
}
bitmap_clear(roce_bitmap, port_num, 1);
usnic_dbg("Freeing port %hu for %s\n", port_num,
usnic_transport_to_str(type));
out_roce_custom:
spin_unlock(&roce_bitmap_lock);
} else {
usnic_err("Freeing invalid port %hu for %d\n", port_num, type);
}
}
struct socket *usnic_transport_get_socket(int sock_fd)
{
struct socket *sock;
int err;
char buf[25];
sock = sockfd_lookup(sock_fd, &err);
if (!sock) {
usnic_err("Unable to lookup socket for fd %d with err %d\n",
sock_fd, err);
return ERR_PTR(-ENOENT);
}
usnic_transport_sock_to_str(buf, sizeof(buf), sock);
usnic_dbg("Get sock %s\n", buf);
return sock;
}
void usnic_transport_put_socket(struct socket *sock)
{
char buf[100];
usnic_transport_sock_to_str(buf, sizeof(buf), sock);
usnic_dbg("Put sock %s\n", buf);
sockfd_put(sock);
}
int usnic_transport_sock_get_addr(struct socket *sock, int *proto,
uint32_t *addr, uint16_t *port)
{
int len;
int err;
struct sockaddr_in sock_addr;
err = sock->ops->getname(sock,
(struct sockaddr *)&sock_addr,
&len, 0);
if (err)
return err;
if (sock_addr.sin_family != AF_INET)
return -EINVAL;
if (proto)
*proto = sock->sk->sk_protocol;
if (port)
*port = ntohs(((struct sockaddr_in *)&sock_addr)->sin_port);
if (addr)
*addr = ntohl(((struct sockaddr_in *)
&sock_addr)->sin_addr.s_addr);
return 0;
}
int usnic_transport_init(void)
{
roce_bitmap = kzalloc(ROCE_BITMAP_SZ, GFP_KERNEL);
if (!roce_bitmap) {
usnic_err("Failed to allocate bit map");
return -ENOMEM;
}
bitmap_set(roce_bitmap, 0, 1);
return 0;
}
void usnic_transport_fini(void)
{
kfree(roce_bitmap);
}
