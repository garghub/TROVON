static int none_init_connection_security(struct rxrpc_connection *conn)
{
return 0;
}
static int none_prime_packet_security(struct rxrpc_connection *conn)
{
return 0;
}
static int none_secure_packet(struct rxrpc_call *call,
struct sk_buff *skb,
size_t data_size,
void *sechdr)
{
return 0;
}
static int none_verify_packet(struct rxrpc_call *call, struct sk_buff *skb,
unsigned int offset, unsigned int len,
rxrpc_seq_t seq, u16 expected_cksum)
{
return 0;
}
static void none_locate_data(struct rxrpc_call *call, struct sk_buff *skb,
unsigned int *_offset, unsigned int *_len)
{
}
static int none_respond_to_challenge(struct rxrpc_connection *conn,
struct sk_buff *skb,
u32 *_abort_code)
{
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
trace_rxrpc_rx_eproto(NULL, sp->hdr.serial,
tracepoint_string("chall_none"));
return -EPROTO;
}
static int none_verify_response(struct rxrpc_connection *conn,
struct sk_buff *skb,
u32 *_abort_code)
{
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
trace_rxrpc_rx_eproto(NULL, sp->hdr.serial,
tracepoint_string("resp_none"));
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
