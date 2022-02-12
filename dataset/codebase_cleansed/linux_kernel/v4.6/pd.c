struct ib_pd *rvt_alloc_pd(struct ib_device *ibdev,
struct ib_ucontext *context,
struct ib_udata *udata)
{
struct rvt_dev_info *dev = ib_to_rvt(ibdev);
struct rvt_pd *pd;
struct ib_pd *ret;
pd = kmalloc(sizeof(*pd), GFP_KERNEL);
if (!pd) {
ret = ERR_PTR(-ENOMEM);
goto bail;
}
spin_lock(&dev->n_pds_lock);
if (dev->n_pds_allocated == dev->dparms.props.max_pd) {
spin_unlock(&dev->n_pds_lock);
kfree(pd);
ret = ERR_PTR(-ENOMEM);
goto bail;
}
dev->n_pds_allocated++;
spin_unlock(&dev->n_pds_lock);
pd->user = udata ? 1 : 0;
ret = &pd->ibpd;
bail:
return ret;
}
int rvt_dealloc_pd(struct ib_pd *ibpd)
{
struct rvt_pd *pd = ibpd_to_rvtpd(ibpd);
struct rvt_dev_info *dev = ib_to_rvt(ibpd->device);
spin_lock(&dev->n_pds_lock);
dev->n_pds_allocated--;
spin_unlock(&dev->n_pds_lock);
kfree(pd);
return 0;
}
