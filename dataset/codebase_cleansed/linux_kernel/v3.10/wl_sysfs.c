static inline int dev_isalive(const struct net_device *dev)
{
return dev->reg_state == NETREG_REGISTERED;
}
static ssize_t show_tallies(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_device *dev = to_net_dev(d);
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
CFG_HERMES_TALLIES_STRCT tallies;
ssize_t ret = -EINVAL;
rcu_read_lock();
if (dev_isalive(dev)) {
wl_lock(lp, &flags);
ret = wl_get_tallies(lp, &tallies);
if (ret == 0) {
wl_unlock(lp, &flags);
ret = snprintf(buf, PAGE_SIZE,
"TxUnicastFrames: %u\n"
"TxMulticastFrames: %u\n"
"TxFragments: %u\n"
"TxUnicastOctets: %u\n"
"TxMulticastOctets: %u\n"
"TxDeferredTransmissions: %u\n"
"TxSingleRetryFrames: %u\n"
"TxMultipleRetryFrames: %u\n"
"TxRetryLimitExceeded: %u\n"
"TxDiscards: %u\n"
"RxUnicastFrames: %u\n"
"RxMulticastFrames: %u\n"
"RxFragments: %u\n"
"RxUnicastOctets: %u\n"
"RxMulticastOctets: %u\n"
"RxFCSErrors: %u\n"
"RxDiscardsNoBuffer: %u\n"
"TxDiscardsWrongSA: %u\n"
"RxWEPUndecryptable: %u\n"
"RxMsgInMsgFragments: %u\n"
"RxMsgInBadMsgFragments: %u\n"
"RxDiscardsWEPICVError: %u\n"
"RxDiscardsWEPExcluded: %u\n"
,
(unsigned int)tallies.TxUnicastFrames,
(unsigned int)tallies.TxMulticastFrames,
(unsigned int)tallies.TxFragments,
(unsigned int)tallies.TxUnicastOctets,
(unsigned int)tallies.TxMulticastOctets,
(unsigned int)tallies.TxDeferredTransmissions,
(unsigned int)tallies.TxSingleRetryFrames,
(unsigned int)tallies.TxMultipleRetryFrames,
(unsigned int)tallies.TxRetryLimitExceeded,
(unsigned int)tallies.TxDiscards,
(unsigned int)tallies.RxUnicastFrames,
(unsigned int)tallies.RxMulticastFrames,
(unsigned int)tallies.RxFragments,
(unsigned int)tallies.RxUnicastOctets,
(unsigned int)tallies.RxMulticastOctets,
(unsigned int)tallies.RxFCSErrors,
(unsigned int)tallies.RxDiscardsNoBuffer,
(unsigned int)tallies.TxDiscardsWrongSA,
(unsigned int)tallies.RxWEPUndecryptable,
(unsigned int)tallies.RxMsgInMsgFragments,
(unsigned int)tallies.RxMsgInBadMsgFragments,
(unsigned int)tallies.RxDiscardsWEPICVError,
(unsigned int)tallies.RxDiscardsWEPExcluded);
} else {
wl_unlock( lp, &flags );
}
}
rcu_read_unlock();
return ret;
}
void register_wlags_sysfs(struct net_device *net)
{
struct device *dev = &(net->dev);
struct wl_private *lp = wl_priv(net);
int err;
err = sysfs_create_group(&dev->kobj, &wlags_group);
if (!err)
lp->sysfsCreated = true;
}
void unregister_wlags_sysfs(struct net_device *net)
{
struct device *dev = &(net->dev);
struct wl_private *lp = wl_priv(net);
if (lp->sysfsCreated)
sysfs_remove_group(&dev->kobj, &wlags_group);
}
