void cfs_cap_raise(cfs_cap_t cap)
{
struct cred *cred;
cred = prepare_creds();
if (cred) {
cap_raise(cred->cap_effective, cap);
commit_creds(cred);
}
}
void cfs_cap_lower(cfs_cap_t cap)
{
struct cred *cred;
cred = prepare_creds();
if (cred) {
cap_lower(cred->cap_effective, cap);
commit_creds(cred);
}
}
int cfs_cap_raised(cfs_cap_t cap)
{
return cap_raised(current_cap(), cap);
}
static void cfs_kernel_cap_pack(kernel_cap_t kcap, cfs_cap_t *cap)
{
*cap = kcap.cap[0];
}
cfs_cap_t cfs_curproc_cap_pack(void)
{
cfs_cap_t cap;
cfs_kernel_cap_pack(current_cap(), &cap);
return cap;
}
