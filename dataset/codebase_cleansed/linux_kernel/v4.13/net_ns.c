static __net_init int rxrpc_init_net(struct net *net)
{
struct rxrpc_net *rxnet = rxrpc_net(net);
int ret;
get_random_bytes(&rxnet->epoch, sizeof(rxnet->epoch));
rxnet->epoch |= RXRPC_RANDOM_EPOCH;
INIT_LIST_HEAD(&rxnet->calls);
rwlock_init(&rxnet->call_lock);
INIT_LIST_HEAD(&rxnet->conn_proc_list);
INIT_LIST_HEAD(&rxnet->service_conns);
rwlock_init(&rxnet->conn_lock);
INIT_DELAYED_WORK(&rxnet->service_conn_reaper,
rxrpc_service_connection_reaper);
rxnet->nr_client_conns = 0;
rxnet->nr_active_client_conns = 0;
rxnet->kill_all_client_conns = false;
spin_lock_init(&rxnet->client_conn_cache_lock);
spin_lock_init(&rxnet->client_conn_discard_lock);
INIT_LIST_HEAD(&rxnet->waiting_client_conns);
INIT_LIST_HEAD(&rxnet->active_client_conns);
INIT_LIST_HEAD(&rxnet->idle_client_conns);
INIT_DELAYED_WORK(&rxnet->client_conn_reaper,
rxrpc_discard_expired_client_conns);
INIT_LIST_HEAD(&rxnet->local_endpoints);
mutex_init(&rxnet->local_mutex);
hash_init(rxnet->peer_hash);
spin_lock_init(&rxnet->peer_hash_lock);
ret = -ENOMEM;
rxnet->proc_net = proc_net_mkdir(net, "rxrpc", net->proc_net);
if (!rxnet->proc_net)
goto err_proc;
proc_create("calls", 0444, rxnet->proc_net, &rxrpc_call_seq_fops);
proc_create("conns", 0444, rxnet->proc_net, &rxrpc_connection_seq_fops);
return 0;
err_proc:
return ret;
}
static __net_exit void rxrpc_exit_net(struct net *net)
{
struct rxrpc_net *rxnet = rxrpc_net(net);
rxrpc_destroy_all_calls(rxnet);
rxrpc_destroy_all_connections(rxnet);
rxrpc_destroy_all_locals(rxnet);
proc_remove(rxnet->proc_net);
}
