int libcfs_kkuc_msg_put(struct file *filp, void *payload)
{
struct kuc_hdr *kuch = (struct kuc_hdr *)payload;
ssize_t count = kuch->kuc_msglen;
loff_t offset = 0;
int rc = -ENXIO;
if (IS_ERR_OR_NULL(filp))
return -EBADF;
if (kuch->kuc_magic != KUC_MAGIC) {
CERROR("KernelComm: bad magic %x\n", kuch->kuc_magic);
return rc;
}
while (count > 0) {
rc = kernel_write(filp, payload, count, &offset);
if (rc < 0)
break;
count -= rc;
payload += rc;
rc = 0;
}
if (rc < 0)
CWARN("message send failed (%d)\n", rc);
else
CDEBUG(D_KUC, "Sent message rc=%d, fp=%p\n", rc, filp);
return rc;
}
int libcfs_kkuc_group_add(struct file *filp, int uid, unsigned int group,
void *data, size_t data_len)
{
struct kkuc_reg *reg;
if (group > KUC_GRP_MAX) {
CDEBUG(D_WARNING, "Kernelcomm: bad group %d\n", group);
return -EINVAL;
}
if (!filp)
return -EBADF;
reg = kmalloc(sizeof(*reg) + data_len, 0);
if (!reg)
return -ENOMEM;
reg->kr_fp = filp;
reg->kr_uid = uid;
memcpy(reg->kr_data, data, data_len);
down_write(&kg_sem);
if (!kkuc_groups[group].next)
INIT_LIST_HEAD(&kkuc_groups[group]);
list_add(&reg->kr_chain, &kkuc_groups[group]);
up_write(&kg_sem);
CDEBUG(D_KUC, "Added uid=%d fp=%p to group %d\n", uid, filp, group);
return 0;
}
int libcfs_kkuc_group_rem(int uid, unsigned int group)
{
struct kkuc_reg *reg, *next;
if (!kkuc_groups[group].next)
return 0;
if (!uid) {
struct kuc_hdr lh;
lh.kuc_magic = KUC_MAGIC;
lh.kuc_transport = KUC_TRANSPORT_GENERIC;
lh.kuc_msgtype = KUC_MSG_SHUTDOWN;
lh.kuc_msglen = sizeof(lh);
libcfs_kkuc_group_put(group, &lh);
}
down_write(&kg_sem);
list_for_each_entry_safe(reg, next, &kkuc_groups[group], kr_chain) {
if (!uid || (uid == reg->kr_uid)) {
list_del(&reg->kr_chain);
CDEBUG(D_KUC, "Removed uid=%d fp=%p from group %d\n",
reg->kr_uid, reg->kr_fp, group);
if (reg->kr_fp)
fput(reg->kr_fp);
kfree(reg);
}
}
up_write(&kg_sem);
return 0;
}
int libcfs_kkuc_group_put(unsigned int group, void *payload)
{
struct kkuc_reg *reg;
int rc = 0;
int one_success = 0;
down_write(&kg_sem);
list_for_each_entry(reg, &kkuc_groups[group], kr_chain) {
if (reg->kr_fp) {
rc = libcfs_kkuc_msg_put(reg->kr_fp, payload);
if (!rc) {
one_success = 1;
} else if (rc == -EPIPE) {
fput(reg->kr_fp);
reg->kr_fp = NULL;
}
}
}
up_write(&kg_sem);
if (one_success)
rc = 0;
return rc;
}
int libcfs_kkuc_group_foreach(unsigned int group, libcfs_kkuc_cb_t cb_func,
void *cb_arg)
{
struct kkuc_reg *reg;
int rc = 0;
if (group > KUC_GRP_MAX) {
CDEBUG(D_WARNING, "Kernelcomm: bad group %d\n", group);
return -EINVAL;
}
if (!kkuc_groups[group].next)
return 0;
down_read(&kg_sem);
list_for_each_entry(reg, &kkuc_groups[group], kr_chain) {
if (reg->kr_fp)
rc = cb_func(reg->kr_data, cb_arg);
}
up_read(&kg_sem);
return rc;
}
