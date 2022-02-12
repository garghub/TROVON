void
nfs4_renew_state(struct work_struct *work)
{
const struct nfs4_state_maintenance_ops *ops;
struct nfs_client *clp =
container_of(work, struct nfs_client, cl_renewd.work);
struct rpc_cred *cred;
long lease;
unsigned long last, now;
ops = clp->cl_mvops->state_renewal_ops;
dprintk("%s: start\n", __func__);
if (test_bit(NFS_CS_STOP_RENEW, &clp->cl_res_state))
goto out;
spin_lock(&clp->cl_lock);
lease = clp->cl_lease_time;
last = clp->cl_last_renewal;
now = jiffies;
if (time_after(now, last + lease/3)) {
cred = ops->get_state_renewal_cred_locked(clp);
spin_unlock(&clp->cl_lock);
if (cred == NULL) {
if (!nfs_delegations_present(clp)) {
set_bit(NFS4CLNT_LEASE_EXPIRED, &clp->cl_state);
goto out;
}
nfs_expire_all_delegations(clp);
} else {
ops->sched_state_renewal(clp, cred);
put_rpccred(cred);
goto out_exp;
}
} else {
dprintk("%s: failed to call renewd. Reason: lease not expired \n",
__func__);
spin_unlock(&clp->cl_lock);
}
nfs4_schedule_state_renewal(clp);
out_exp:
nfs_expire_unreferenced_delegations(clp);
out:
dprintk("%s: done\n", __func__);
}
void
nfs4_schedule_state_renewal(struct nfs_client *clp)
{
long timeout;
spin_lock(&clp->cl_lock);
timeout = (2 * clp->cl_lease_time) / 3 + (long)clp->cl_last_renewal
- (long)jiffies;
if (timeout < 5 * HZ)
timeout = 5 * HZ;
dprintk("%s: requeueing work. Lease period = %ld\n",
__func__, (timeout + HZ - 1) / HZ);
cancel_delayed_work(&clp->cl_renewd);
schedule_delayed_work(&clp->cl_renewd, timeout);
set_bit(NFS_CS_RENEWD, &clp->cl_res_state);
spin_unlock(&clp->cl_lock);
}
void
nfs4_kill_renewd(struct nfs_client *clp)
{
cancel_delayed_work_sync(&clp->cl_renewd);
}
