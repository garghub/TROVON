void vsock_addr_init(struct sockaddr_vm *addr, u32 cid, u32 port)
{
memset(addr, 0, sizeof(*addr));
addr->svm_family = AF_VSOCK;
addr->svm_cid = cid;
addr->svm_port = port;
}
int vsock_addr_validate(const struct sockaddr_vm *addr)
{
if (!addr)
return -EFAULT;
if (addr->svm_family != AF_VSOCK)
return -EAFNOSUPPORT;
if (addr->svm_zero[0] != 0)
return -EINVAL;
return 0;
}
bool vsock_addr_bound(const struct sockaddr_vm *addr)
{
return addr->svm_port != VMADDR_PORT_ANY;
}
void vsock_addr_unbind(struct sockaddr_vm *addr)
{
vsock_addr_init(addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
}
bool vsock_addr_equals_addr(const struct sockaddr_vm *addr,
const struct sockaddr_vm *other)
{
return addr->svm_cid == other->svm_cid &&
addr->svm_port == other->svm_port;
}
int vsock_addr_cast(const struct sockaddr *addr,
size_t len, struct sockaddr_vm **out_addr)
{
if (len < sizeof(**out_addr))
return -EFAULT;
*out_addr = (struct sockaddr_vm *)addr;
return vsock_addr_validate(*out_addr);
}
