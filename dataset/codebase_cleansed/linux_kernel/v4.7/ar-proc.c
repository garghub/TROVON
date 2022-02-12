static void *rxrpc_call_seq_start(struct seq_file *seq, loff_t *_pos)
{
read_lock(&rxrpc_call_lock);
return seq_list_start_head(&rxrpc_calls, *_pos);
}
static void *rxrpc_call_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
return seq_list_next(v, &rxrpc_calls, pos);
}
static void rxrpc_call_seq_stop(struct seq_file *seq, void *v)
{
read_unlock(&rxrpc_call_lock);
}
static int rxrpc_call_seq_show(struct seq_file *seq, void *v)
{
struct rxrpc_transport *trans;
struct rxrpc_call *call;
char lbuff[4 + 4 + 4 + 4 + 5 + 1], rbuff[4 + 4 + 4 + 4 + 5 + 1];
if (v == &rxrpc_calls) {
seq_puts(seq,
"Proto Local Remote "
" SvID ConnID CallID End Use State Abort "
" UserID\n");
return 0;
}
call = list_entry(v, struct rxrpc_call, link);
trans = call->conn->trans;
sprintf(lbuff, "%pI4:%u",
&trans->local->srx.transport.sin.sin_addr,
ntohs(trans->local->srx.transport.sin.sin_port));
sprintf(rbuff, "%pI4:%u",
&trans->peer->srx.transport.sin.sin_addr,
ntohs(trans->peer->srx.transport.sin.sin_port));
seq_printf(seq,
"UDP %-22.22s %-22.22s %4x %08x %08x %s %3u"
" %-8.8s %08x %lx\n",
lbuff,
rbuff,
call->conn->service_id,
call->cid,
call->call_id,
call->conn->in_clientflag ? "Svc" : "Clt",
atomic_read(&call->usage),
rxrpc_call_states[call->state],
call->remote_abort ?: call->local_abort,
call->user_call_ID);
return 0;
}
static int rxrpc_call_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &rxrpc_call_seq_ops);
}
static void *rxrpc_connection_seq_start(struct seq_file *seq, loff_t *_pos)
{
read_lock(&rxrpc_connection_lock);
return seq_list_start_head(&rxrpc_connections, *_pos);
}
static void *rxrpc_connection_seq_next(struct seq_file *seq, void *v,
loff_t *pos)
{
return seq_list_next(v, &rxrpc_connections, pos);
}
static void rxrpc_connection_seq_stop(struct seq_file *seq, void *v)
{
read_unlock(&rxrpc_connection_lock);
}
static int rxrpc_connection_seq_show(struct seq_file *seq, void *v)
{
struct rxrpc_connection *conn;
struct rxrpc_transport *trans;
char lbuff[4 + 4 + 4 + 4 + 5 + 1], rbuff[4 + 4 + 4 + 4 + 5 + 1];
if (v == &rxrpc_connections) {
seq_puts(seq,
"Proto Local Remote "
" SvID ConnID Calls End Use State Key "
" Serial ISerial\n"
);
return 0;
}
conn = list_entry(v, struct rxrpc_connection, link);
trans = conn->trans;
sprintf(lbuff, "%pI4:%u",
&trans->local->srx.transport.sin.sin_addr,
ntohs(trans->local->srx.transport.sin.sin_port));
sprintf(rbuff, "%pI4:%u",
&trans->peer->srx.transport.sin.sin_addr,
ntohs(trans->peer->srx.transport.sin.sin_port));
seq_printf(seq,
"UDP %-22.22s %-22.22s %4x %08x %08x %s %3u"
" %s %08x %08x %08x\n",
lbuff,
rbuff,
conn->service_id,
conn->cid,
conn->call_counter,
conn->in_clientflag ? "Svc" : "Clt",
atomic_read(&conn->usage),
rxrpc_conn_states[conn->state],
key_serial(conn->key),
atomic_read(&conn->serial),
atomic_read(&conn->hi_serial));
return 0;
}
static int rxrpc_connection_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &rxrpc_connection_seq_ops);
}
