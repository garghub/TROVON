void isc_register(unsigned int isc)
{
if (isc > MAX_ISC) {
WARN_ON(1);
return;
}
spin_lock(&isc_ref_lock);
if (isc_refs[isc] == 0)
ctl_set_bit(6, 31 - isc);
isc_refs[isc]++;
spin_unlock(&isc_ref_lock);
}
void isc_unregister(unsigned int isc)
{
spin_lock(&isc_ref_lock);
if (isc > MAX_ISC || isc_refs[isc] == 0) {
WARN_ON(1);
goto out_unlock;
}
if (isc_refs[isc] == 1)
ctl_clear_bit(6, 31 - isc);
isc_refs[isc]--;
out_unlock:
spin_unlock(&isc_ref_lock);
}
