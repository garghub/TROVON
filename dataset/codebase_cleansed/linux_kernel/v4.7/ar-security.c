int __init rxrpc_init_security(void)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(rxrpc_security_types); i++) {
if (rxrpc_security_types[i]) {
ret = rxrpc_security_types[i]->init();
if (ret < 0)
goto failed;
}
}
return 0;
failed:
for (i--; i >= 0; i--)
if (rxrpc_security_types[i])
rxrpc_security_types[i]->exit();
return ret;
}
void rxrpc_exit_security(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(rxrpc_security_types); i++)
if (rxrpc_security_types[i])
rxrpc_security_types[i]->exit();
}
static const struct rxrpc_security *rxrpc_security_lookup(u8 security_index)
{
if (security_index >= ARRAY_SIZE(rxrpc_security_types))
return NULL;
return rxrpc_security_types[security_index];
}
int rxrpc_init_client_conn_security(struct rxrpc_connection *conn)
{
const struct rxrpc_security *sec;
struct rxrpc_key_token *token;
struct key *key = conn->key;
int ret;
_enter("{%d},{%x}", conn->debug_id, key_serial(key));
if (!key)
return 0;
ret = key_validate(key);
if (ret < 0)
return ret;
token = key->payload.data[0];
if (!token)
return -EKEYREJECTED;
sec = rxrpc_security_lookup(token->security_index);
if (!sec)
return -EKEYREJECTED;
conn->security = sec;
ret = conn->security->init_connection_security(conn);
if (ret < 0) {
conn->security = &rxrpc_no_security;
return ret;
}
_leave(" = 0");
return 0;
}
int rxrpc_init_server_conn_security(struct rxrpc_connection *conn)
{
const struct rxrpc_security *sec;
struct rxrpc_local *local = conn->trans->local;
struct rxrpc_sock *rx;
struct key *key;
key_ref_t kref;
char kdesc[5 + 1 + 3 + 1];
_enter("");
sprintf(kdesc, "%u:%u", conn->service_id, conn->security_ix);
sec = rxrpc_security_lookup(conn->security_ix);
if (!sec) {
_leave(" = -ENOKEY [lookup]");
return -ENOKEY;
}
read_lock_bh(&local->services_lock);
list_for_each_entry(rx, &local->services, listen_link) {
if (rx->srx.srx_service == conn->service_id)
goto found_service;
}
read_unlock_bh(&local->services_lock);
_leave(" = -ENOENT");
return -ENOENT;
found_service:
if (!rx->securities) {
read_unlock_bh(&local->services_lock);
_leave(" = -ENOKEY");
return -ENOKEY;
}
kref = keyring_search(make_key_ref(rx->securities, 1UL),
&key_type_rxrpc_s, kdesc);
if (IS_ERR(kref)) {
read_unlock_bh(&local->services_lock);
_leave(" = %ld [search]", PTR_ERR(kref));
return PTR_ERR(kref);
}
key = key_ref_to_ptr(kref);
read_unlock_bh(&local->services_lock);
conn->server_key = key;
conn->security = sec;
_leave(" = 0");
return 0;
}
