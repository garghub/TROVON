int __cfs_fail_check_set(__u32 id, __u32 value, int set)
{
static atomic_t cfs_fail_count = ATOMIC_INIT(0);
LASSERT(!(id & CFS_FAIL_ONCE));
if ((cfs_fail_loc & (CFS_FAILED | CFS_FAIL_ONCE)) ==
(CFS_FAILED | CFS_FAIL_ONCE)) {
atomic_set(&cfs_fail_count, 0);
return 0;
}
if (cfs_fail_loc & CFS_FAIL_RAND) {
if (cfs_fail_val < 2 || cfs_rand() % cfs_fail_val > 0)
return 0;
}
if (cfs_fail_loc & CFS_FAIL_SKIP) {
if (atomic_inc_return(&cfs_fail_count) <= cfs_fail_val)
return 0;
}
if (set == CFS_FAIL_LOC_VALUE) {
if (cfs_fail_val != -1 && cfs_fail_val != value)
return 0;
}
if (cfs_fail_loc & CFS_FAIL_SOME &&
(!(cfs_fail_loc & CFS_FAIL_ONCE) || cfs_fail_val <= 1)) {
int count = atomic_inc_return(&cfs_fail_count);
if (count >= cfs_fail_val) {
set_bit(CFS_FAIL_ONCE_BIT, &cfs_fail_loc);
atomic_set(&cfs_fail_count, 0);
if (count > cfs_fail_val)
return 0;
}
}
if ((set == CFS_FAIL_LOC_ORSET || set == CFS_FAIL_LOC_RESET) &&
(value & CFS_FAIL_ONCE))
set_bit(CFS_FAIL_ONCE_BIT, &cfs_fail_loc);
if (test_and_set_bit(CFS_FAILED_BIT, &cfs_fail_loc)) {
if (cfs_fail_loc & CFS_FAIL_ONCE)
return 0;
}
switch (set) {
case CFS_FAIL_LOC_NOSET:
case CFS_FAIL_LOC_VALUE:
break;
case CFS_FAIL_LOC_ORSET:
cfs_fail_loc |= value & ~(CFS_FAILED | CFS_FAIL_ONCE);
break;
case CFS_FAIL_LOC_RESET:
cfs_fail_loc = value;
break;
default:
LASSERTF(0, "called with bad set %u\n", set);
break;
}
return 1;
}
int __cfs_fail_timeout_set(__u32 id, __u32 value, int ms, int set)
{
int ret = 0;
ret = __cfs_fail_check_set(id, value, set);
if (ret) {
CERROR("cfs_fail_timeout id %x sleeping for %dms\n",
id, ms);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(ms) / 1000);
CERROR("cfs_fail_timeout id %x awake\n", id);
}
return ret;
}
