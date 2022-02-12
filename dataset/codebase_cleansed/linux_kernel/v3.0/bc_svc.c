int bc_send(struct rpc_rqst *req)
{
struct rpc_task *task;
int ret;
dprintk("RPC: bc_send req= %p\n", req);
task = rpc_run_bc_task(req, &nfs41_callback_ops);
if (IS_ERR(task))
ret = PTR_ERR(task);
else {
BUG_ON(atomic_read(&task->tk_count) != 1);
ret = task->tk_status;
rpc_put_task(task);
}
dprintk("RPC: bc_send ret= %d\n", ret);
return ret;
}
