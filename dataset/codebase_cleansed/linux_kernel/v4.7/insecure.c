static int none_init_connection_security(struct rxrpc_connection *conn)
{
return 0;
}
static void none_prime_packet_security(struct rxrpc_connection *conn)
{
}
static int none_secure_packet(const struct rxrpc_call *call,
struct sk_buff *skb,
size_t data_size,
void *sechdr)
{
return 0;
}
static int none_verify_packet(const struct rxrpc_call *call,
struct sk_buff *skb,
u32 *_abort_code)
{
return 0;
}
static int none_respond_to_challenge(struct rxrpc_connection *conn,
struct sk_buff *skb,
u32 *_abort_code)
{
*_abort_code = RX_PROTOCOL_ERROR;
return -EPROTO;
}
static int none_verify_response(struct rxrpc_connection *conn,
struct sk_buff *skb,
u32 *_abort_code)
{
*_abort_code = RX_PROTOCOL_ERROR;
return -EPROTO;
}
static void none_clear(struct rxrpc_connection *conn)
{
}
static int none_init(void)
{
return 0;
}
static void none_exit(void)
{
}
