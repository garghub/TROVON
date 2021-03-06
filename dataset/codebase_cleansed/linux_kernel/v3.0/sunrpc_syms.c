static __net_init int sunrpc_init_net(struct net *net)
{
int err;
err = rpc_proc_init(net);
if (err)
goto err_proc;
err = ip_map_cache_create(net);
if (err)
goto err_ipmap;
return 0;
err_ipmap:
rpc_proc_exit(net);
err_proc:
return err;
}
static __net_exit void sunrpc_exit_net(struct net *net)
{
ip_map_cache_destroy(net);
rpc_proc_exit(net);
}
static int __init
init_sunrpc(void)
{
int err = register_rpc_pipefs();
if (err)
goto out;
err = rpc_init_mempool();
if (err)
goto out2;
err = rpcauth_init_module();
if (err)
goto out3;
cache_initialize();
err = register_pernet_subsys(&sunrpc_net_ops);
if (err)
goto out4;
#ifdef RPC_DEBUG
rpc_register_sysctl();
#endif
cache_register(&unix_gid_cache);
svc_init_xprt_sock();
init_socket_xprt();
return 0;
out4:
rpcauth_remove_module();
out3:
rpc_destroy_mempool();
out2:
unregister_rpc_pipefs();
out:
return err;
}
static void __exit
cleanup_sunrpc(void)
{
cleanup_rpcb_clnt();
rpcauth_remove_module();
cleanup_socket_xprt();
svc_cleanup_xprt_sock();
unregister_rpc_pipefs();
rpc_destroy_mempool();
cache_unregister(&unix_gid_cache);
unregister_pernet_subsys(&sunrpc_net_ops);
#ifdef RPC_DEBUG
rpc_unregister_sysctl();
#endif
rcu_barrier();
}
