static int iucv_bus_match(struct device *dev, struct device_driver *drv)
{
return 0;
}
static inline int __iucv_call_b2f0(int command, union iucv_param *parm)
{
register unsigned long reg0 asm ("0");
register unsigned long reg1 asm ("1");
int ccode;
reg0 = command;
reg1 = (unsigned long)parm;
asm volatile(
" .long 0xb2f01000\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "=m" (*parm), "+d" (reg0), "+a" (reg1)
: "m" (*parm) : "cc");
return ccode;
}
static inline int iucv_call_b2f0(int command, union iucv_param *parm)
{
int ccode;
ccode = __iucv_call_b2f0(command, parm);
return ccode == 1 ? parm->ctrl.iprcode : ccode;
}
static int __iucv_query_maxconn(void *param, unsigned long *max_pathid)
{
register unsigned long reg0 asm ("0");
register unsigned long reg1 asm ("1");
int ccode;
reg0 = IUCV_QUERY;
reg1 = (unsigned long) param;
asm volatile (
" .long 0xb2f01000\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "+d" (reg0), "+d" (reg1) : : "cc");
*max_pathid = reg1;
return ccode;
}
static int iucv_query_maxconn(void)
{
unsigned long max_pathid;
void *param;
int ccode;
param = kzalloc(sizeof(union iucv_param), GFP_KERNEL | GFP_DMA);
if (!param)
return -ENOMEM;
ccode = __iucv_query_maxconn(param, &max_pathid);
if (ccode == 0)
iucv_max_pathid = max_pathid;
kfree(param);
return ccode ? -EPERM : 0;
}
static void iucv_allow_cpu(void *data)
{
int cpu = smp_processor_id();
union iucv_param *parm;
parm = iucv_param_irq[cpu];
memset(parm, 0, sizeof(union iucv_param));
parm->set_mask.ipmask = 0xf8;
iucv_call_b2f0(IUCV_SETMASK, parm);
memset(parm, 0, sizeof(union iucv_param));
parm->set_mask.ipmask = 0xf8;
iucv_call_b2f0(IUCV_SETCONTROLMASK, parm);
cpumask_set_cpu(cpu, &iucv_irq_cpumask);
}
static void iucv_block_cpu(void *data)
{
int cpu = smp_processor_id();
union iucv_param *parm;
parm = iucv_param_irq[cpu];
memset(parm, 0, sizeof(union iucv_param));
iucv_call_b2f0(IUCV_SETMASK, parm);
cpumask_clear_cpu(cpu, &iucv_irq_cpumask);
}
static void iucv_block_cpu_almost(void *data)
{
int cpu = smp_processor_id();
union iucv_param *parm;
parm = iucv_param_irq[cpu];
memset(parm, 0, sizeof(union iucv_param));
parm->set_mask.ipmask = 0x08;
iucv_call_b2f0(IUCV_SETMASK, parm);
memset(parm, 0, sizeof(union iucv_param));
parm->set_mask.ipmask = 0x20;
iucv_call_b2f0(IUCV_SETCONTROLMASK, parm);
cpumask_clear_cpu(cpu, &iucv_irq_cpumask);
}
static void iucv_declare_cpu(void *data)
{
int cpu = smp_processor_id();
union iucv_param *parm;
int rc;
if (cpumask_test_cpu(cpu, &iucv_buffer_cpumask))
return;
parm = iucv_param_irq[cpu];
memset(parm, 0, sizeof(union iucv_param));
parm->db.ipbfadr1 = virt_to_phys(iucv_irq_data[cpu]);
rc = iucv_call_b2f0(IUCV_DECLARE_BUFFER, parm);
if (rc) {
char *err = "Unknown";
switch (rc) {
case 0x03:
err = "Directory error";
break;
case 0x0a:
err = "Invalid length";
break;
case 0x13:
err = "Buffer already exists";
break;
case 0x3e:
err = "Buffer overlap";
break;
case 0x5c:
err = "Paging or storage error";
break;
}
pr_warn("Defining an interrupt buffer on CPU %i failed with 0x%02x (%s)\n",
cpu, rc, err);
return;
}
cpumask_set_cpu(cpu, &iucv_buffer_cpumask);
if (iucv_nonsmp_handler == 0 || cpumask_empty(&iucv_irq_cpumask))
iucv_allow_cpu(NULL);
else
iucv_block_cpu(NULL);
}
static void iucv_retrieve_cpu(void *data)
{
int cpu = smp_processor_id();
union iucv_param *parm;
if (!cpumask_test_cpu(cpu, &iucv_buffer_cpumask))
return;
iucv_block_cpu(NULL);
parm = iucv_param_irq[cpu];
iucv_call_b2f0(IUCV_RETRIEVE_BUFFER, parm);
cpumask_clear_cpu(cpu, &iucv_buffer_cpumask);
}
static void iucv_setmask_mp(void)
{
int cpu;
get_online_cpus();
for_each_online_cpu(cpu)
if (cpumask_test_cpu(cpu, &iucv_buffer_cpumask) &&
!cpumask_test_cpu(cpu, &iucv_irq_cpumask))
smp_call_function_single(cpu, iucv_allow_cpu,
NULL, 1);
put_online_cpus();
}
static void iucv_setmask_up(void)
{
cpumask_t cpumask;
int cpu;
cpumask_copy(&cpumask, &iucv_irq_cpumask);
cpumask_clear_cpu(cpumask_first(&iucv_irq_cpumask), &cpumask);
for_each_cpu(cpu, &cpumask)
smp_call_function_single(cpu, iucv_block_cpu, NULL, 1);
}
static int iucv_enable(void)
{
size_t alloc_size;
int cpu, rc;
get_online_cpus();
rc = -ENOMEM;
alloc_size = iucv_max_pathid * sizeof(struct iucv_path);
iucv_path_table = kzalloc(alloc_size, GFP_KERNEL);
if (!iucv_path_table)
goto out;
rc = -EIO;
for_each_online_cpu(cpu)
smp_call_function_single(cpu, iucv_declare_cpu, NULL, 1);
if (cpumask_empty(&iucv_buffer_cpumask))
goto out;
put_online_cpus();
return 0;
out:
kfree(iucv_path_table);
iucv_path_table = NULL;
put_online_cpus();
return rc;
}
static void iucv_disable(void)
{
get_online_cpus();
on_each_cpu(iucv_retrieve_cpu, NULL, 1);
kfree(iucv_path_table);
iucv_path_table = NULL;
put_online_cpus();
}
static void free_iucv_data(int cpu)
{
kfree(iucv_param_irq[cpu]);
iucv_param_irq[cpu] = NULL;
kfree(iucv_param[cpu]);
iucv_param[cpu] = NULL;
kfree(iucv_irq_data[cpu]);
iucv_irq_data[cpu] = NULL;
}
static int alloc_iucv_data(int cpu)
{
iucv_irq_data[cpu] = kmalloc_node(sizeof(struct iucv_irq_data),
GFP_KERNEL|GFP_DMA, cpu_to_node(cpu));
if (!iucv_irq_data[cpu])
goto out_free;
iucv_param[cpu] = kmalloc_node(sizeof(union iucv_param),
GFP_KERNEL|GFP_DMA, cpu_to_node(cpu));
if (!iucv_param[cpu])
goto out_free;
iucv_param_irq[cpu] = kmalloc_node(sizeof(union iucv_param),
GFP_KERNEL|GFP_DMA, cpu_to_node(cpu));
if (!iucv_param_irq[cpu])
goto out_free;
return 0;
out_free:
free_iucv_data(cpu);
return -ENOMEM;
}
static int iucv_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
cpumask_t cpumask;
long cpu = (long) hcpu;
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
if (alloc_iucv_data(cpu))
return notifier_from_errno(-ENOMEM);
break;
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
case CPU_DEAD:
case CPU_DEAD_FROZEN:
free_iucv_data(cpu);
break;
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
if (!iucv_path_table)
break;
smp_call_function_single(cpu, iucv_declare_cpu, NULL, 1);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
if (!iucv_path_table)
break;
cpumask_copy(&cpumask, &iucv_buffer_cpumask);
cpumask_clear_cpu(cpu, &cpumask);
if (cpumask_empty(&cpumask))
return notifier_from_errno(-EINVAL);
smp_call_function_single(cpu, iucv_retrieve_cpu, NULL, 1);
if (cpumask_empty(&iucv_irq_cpumask))
smp_call_function_single(
cpumask_first(&iucv_buffer_cpumask),
iucv_allow_cpu, NULL, 1);
break;
}
return NOTIFY_OK;
}
static int iucv_sever_pathid(u16 pathid, u8 *userdata)
{
union iucv_param *parm;
parm = iucv_param_irq[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
if (userdata)
memcpy(parm->ctrl.ipuser, userdata, sizeof(parm->ctrl.ipuser));
parm->ctrl.ippathid = pathid;
return iucv_call_b2f0(IUCV_SEVER, parm);
}
static void __iucv_cleanup_queue(void *dummy)
{
}
static void iucv_cleanup_queue(void)
{
struct iucv_irq_list *p, *n;
smp_call_function(__iucv_cleanup_queue, NULL, 1);
spin_lock_irq(&iucv_queue_lock);
list_for_each_entry_safe(p, n, &iucv_task_queue, list) {
if (iucv_path_table[p->data.ippathid] == NULL) {
list_del(&p->list);
kfree(p);
}
}
spin_unlock_irq(&iucv_queue_lock);
}
int iucv_register(struct iucv_handler *handler, int smp)
{
int rc;
if (!iucv_available)
return -ENOSYS;
mutex_lock(&iucv_register_mutex);
if (!smp)
iucv_nonsmp_handler++;
if (list_empty(&iucv_handler_list)) {
rc = iucv_enable();
if (rc)
goto out_mutex;
} else if (!smp && iucv_nonsmp_handler == 1)
iucv_setmask_up();
INIT_LIST_HEAD(&handler->paths);
spin_lock_bh(&iucv_table_lock);
list_add_tail(&handler->list, &iucv_handler_list);
spin_unlock_bh(&iucv_table_lock);
rc = 0;
out_mutex:
mutex_unlock(&iucv_register_mutex);
return rc;
}
void iucv_unregister(struct iucv_handler *handler, int smp)
{
struct iucv_path *p, *n;
mutex_lock(&iucv_register_mutex);
spin_lock_bh(&iucv_table_lock);
list_del_init(&handler->list);
list_for_each_entry_safe(p, n, &handler->paths, list) {
iucv_sever_pathid(p->pathid, NULL);
iucv_path_table[p->pathid] = NULL;
list_del(&p->list);
iucv_path_free(p);
}
spin_unlock_bh(&iucv_table_lock);
if (!smp)
iucv_nonsmp_handler--;
if (list_empty(&iucv_handler_list))
iucv_disable();
else if (!smp && iucv_nonsmp_handler == 0)
iucv_setmask_mp();
mutex_unlock(&iucv_register_mutex);
}
static int iucv_reboot_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
int i;
if (cpumask_empty(&iucv_irq_cpumask))
return NOTIFY_DONE;
get_online_cpus();
on_each_cpu_mask(&iucv_irq_cpumask, iucv_block_cpu, NULL, 1);
preempt_disable();
for (i = 0; i < iucv_max_pathid; i++) {
if (iucv_path_table[i])
iucv_sever_pathid(i, NULL);
}
preempt_enable();
put_online_cpus();
iucv_disable();
return NOTIFY_DONE;
}
int iucv_path_accept(struct iucv_path *path, struct iucv_handler *handler,
u8 *userdata, void *private)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
parm->ctrl.ippathid = path->pathid;
parm->ctrl.ipmsglim = path->msglim;
if (userdata)
memcpy(parm->ctrl.ipuser, userdata, sizeof(parm->ctrl.ipuser));
parm->ctrl.ipflags1 = path->flags;
rc = iucv_call_b2f0(IUCV_ACCEPT, parm);
if (!rc) {
path->private = private;
path->msglim = parm->ctrl.ipmsglim;
path->flags = parm->ctrl.ipflags1;
}
out:
local_bh_enable();
return rc;
}
int iucv_path_connect(struct iucv_path *path, struct iucv_handler *handler,
u8 *userid, u8 *system, u8 *userdata,
void *private)
{
union iucv_param *parm;
int rc;
spin_lock_bh(&iucv_table_lock);
iucv_cleanup_queue();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
parm->ctrl.ipmsglim = path->msglim;
parm->ctrl.ipflags1 = path->flags;
if (userid) {
memcpy(parm->ctrl.ipvmid, userid, sizeof(parm->ctrl.ipvmid));
ASCEBC(parm->ctrl.ipvmid, sizeof(parm->ctrl.ipvmid));
EBC_TOUPPER(parm->ctrl.ipvmid, sizeof(parm->ctrl.ipvmid));
}
if (system) {
memcpy(parm->ctrl.iptarget, system,
sizeof(parm->ctrl.iptarget));
ASCEBC(parm->ctrl.iptarget, sizeof(parm->ctrl.iptarget));
EBC_TOUPPER(parm->ctrl.iptarget, sizeof(parm->ctrl.iptarget));
}
if (userdata)
memcpy(parm->ctrl.ipuser, userdata, sizeof(parm->ctrl.ipuser));
rc = iucv_call_b2f0(IUCV_CONNECT, parm);
if (!rc) {
if (parm->ctrl.ippathid < iucv_max_pathid) {
path->pathid = parm->ctrl.ippathid;
path->msglim = parm->ctrl.ipmsglim;
path->flags = parm->ctrl.ipflags1;
path->handler = handler;
path->private = private;
list_add_tail(&path->list, &handler->paths);
iucv_path_table[path->pathid] = path;
} else {
iucv_sever_pathid(parm->ctrl.ippathid,
iucv_error_pathid);
rc = -EIO;
}
}
out:
spin_unlock_bh(&iucv_table_lock);
return rc;
}
int iucv_path_quiesce(struct iucv_path *path, u8 *userdata)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
if (userdata)
memcpy(parm->ctrl.ipuser, userdata, sizeof(parm->ctrl.ipuser));
parm->ctrl.ippathid = path->pathid;
rc = iucv_call_b2f0(IUCV_QUIESCE, parm);
out:
local_bh_enable();
return rc;
}
int iucv_path_resume(struct iucv_path *path, u8 *userdata)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
if (userdata)
memcpy(parm->ctrl.ipuser, userdata, sizeof(parm->ctrl.ipuser));
parm->ctrl.ippathid = path->pathid;
rc = iucv_call_b2f0(IUCV_RESUME, parm);
out:
local_bh_enable();
return rc;
}
int iucv_path_sever(struct iucv_path *path, u8 *userdata)
{
int rc;
preempt_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
if (iucv_active_cpu != smp_processor_id())
spin_lock_bh(&iucv_table_lock);
rc = iucv_sever_pathid(path->pathid, userdata);
iucv_path_table[path->pathid] = NULL;
list_del_init(&path->list);
if (iucv_active_cpu != smp_processor_id())
spin_unlock_bh(&iucv_table_lock);
out:
preempt_enable();
return rc;
}
int iucv_message_purge(struct iucv_path *path, struct iucv_message *msg,
u32 srccls)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
parm->purge.ippathid = path->pathid;
parm->purge.ipmsgid = msg->id;
parm->purge.ipsrccls = srccls;
parm->purge.ipflags1 = IUCV_IPSRCCLS | IUCV_IPFGMID | IUCV_IPFGPID;
rc = iucv_call_b2f0(IUCV_PURGE, parm);
if (!rc) {
msg->audit = (*(u32 *) &parm->purge.ipaudit) >> 8;
msg->tag = parm->purge.ipmsgtag;
}
out:
local_bh_enable();
return rc;
}
static int iucv_message_receive_iprmdata(struct iucv_path *path,
struct iucv_message *msg,
u8 flags, void *buffer,
size_t size, size_t *residual)
{
struct iucv_array *array;
u8 *rmmsg;
size_t copy;
if (residual)
*residual = abs(size - 8);
rmmsg = msg->rmmsg;
if (flags & IUCV_IPBUFLST) {
size = (size < 8) ? size : 8;
for (array = buffer; size > 0; array++) {
copy = min_t(size_t, size, array->length);
memcpy((u8 *)(addr_t) array->address,
rmmsg, copy);
rmmsg += copy;
size -= copy;
}
} else {
memcpy(buffer, rmmsg, min_t(size_t, size, 8));
}
return 0;
}
int __iucv_message_receive(struct iucv_path *path, struct iucv_message *msg,
u8 flags, void *buffer, size_t size, size_t *residual)
{
union iucv_param *parm;
int rc;
if (msg->flags & IUCV_IPRMDATA)
return iucv_message_receive_iprmdata(path, msg, flags,
buffer, size, residual);
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
parm->db.ipbfadr1 = (u32)(addr_t) buffer;
parm->db.ipbfln1f = (u32) size;
parm->db.ipmsgid = msg->id;
parm->db.ippathid = path->pathid;
parm->db.iptrgcls = msg->class;
parm->db.ipflags1 = (flags | IUCV_IPFGPID |
IUCV_IPFGMID | IUCV_IPTRGCLS);
rc = iucv_call_b2f0(IUCV_RECEIVE, parm);
if (!rc || rc == 5) {
msg->flags = parm->db.ipflags1;
if (residual)
*residual = parm->db.ipbfln1f;
}
out:
return rc;
}
int iucv_message_receive(struct iucv_path *path, struct iucv_message *msg,
u8 flags, void *buffer, size_t size, size_t *residual)
{
int rc;
if (msg->flags & IUCV_IPRMDATA)
return iucv_message_receive_iprmdata(path, msg, flags,
buffer, size, residual);
local_bh_disable();
rc = __iucv_message_receive(path, msg, flags, buffer, size, residual);
local_bh_enable();
return rc;
}
int iucv_message_reject(struct iucv_path *path, struct iucv_message *msg)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
parm->db.ippathid = path->pathid;
parm->db.ipmsgid = msg->id;
parm->db.iptrgcls = msg->class;
parm->db.ipflags1 = (IUCV_IPTRGCLS | IUCV_IPFGMID | IUCV_IPFGPID);
rc = iucv_call_b2f0(IUCV_REJECT, parm);
out:
local_bh_enable();
return rc;
}
int iucv_message_reply(struct iucv_path *path, struct iucv_message *msg,
u8 flags, void *reply, size_t size)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
if (flags & IUCV_IPRMDATA) {
parm->dpl.ippathid = path->pathid;
parm->dpl.ipflags1 = flags;
parm->dpl.ipmsgid = msg->id;
parm->dpl.iptrgcls = msg->class;
memcpy(parm->dpl.iprmmsg, reply, min_t(size_t, size, 8));
} else {
parm->db.ipbfadr1 = (u32)(addr_t) reply;
parm->db.ipbfln1f = (u32) size;
parm->db.ippathid = path->pathid;
parm->db.ipflags1 = flags;
parm->db.ipmsgid = msg->id;
parm->db.iptrgcls = msg->class;
}
rc = iucv_call_b2f0(IUCV_REPLY, parm);
out:
local_bh_enable();
return rc;
}
int __iucv_message_send(struct iucv_path *path, struct iucv_message *msg,
u8 flags, u32 srccls, void *buffer, size_t size)
{
union iucv_param *parm;
int rc;
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
if (flags & IUCV_IPRMDATA) {
parm->dpl.ippathid = path->pathid;
parm->dpl.ipflags1 = flags | IUCV_IPNORPY;
parm->dpl.iptrgcls = msg->class;
parm->dpl.ipsrccls = srccls;
parm->dpl.ipmsgtag = msg->tag;
memcpy(parm->dpl.iprmmsg, buffer, 8);
} else {
parm->db.ipbfadr1 = (u32)(addr_t) buffer;
parm->db.ipbfln1f = (u32) size;
parm->db.ippathid = path->pathid;
parm->db.ipflags1 = flags | IUCV_IPNORPY;
parm->db.iptrgcls = msg->class;
parm->db.ipsrccls = srccls;
parm->db.ipmsgtag = msg->tag;
}
rc = iucv_call_b2f0(IUCV_SEND, parm);
if (!rc)
msg->id = parm->db.ipmsgid;
out:
return rc;
}
int iucv_message_send(struct iucv_path *path, struct iucv_message *msg,
u8 flags, u32 srccls, void *buffer, size_t size)
{
int rc;
local_bh_disable();
rc = __iucv_message_send(path, msg, flags, srccls, buffer, size);
local_bh_enable();
return rc;
}
int iucv_message_send2way(struct iucv_path *path, struct iucv_message *msg,
u8 flags, u32 srccls, void *buffer, size_t size,
void *answer, size_t asize, size_t *residual)
{
union iucv_param *parm;
int rc;
local_bh_disable();
if (cpumask_empty(&iucv_buffer_cpumask)) {
rc = -EIO;
goto out;
}
parm = iucv_param[smp_processor_id()];
memset(parm, 0, sizeof(union iucv_param));
if (flags & IUCV_IPRMDATA) {
parm->dpl.ippathid = path->pathid;
parm->dpl.ipflags1 = path->flags;
parm->dpl.iptrgcls = msg->class;
parm->dpl.ipsrccls = srccls;
parm->dpl.ipmsgtag = msg->tag;
parm->dpl.ipbfadr2 = (u32)(addr_t) answer;
parm->dpl.ipbfln2f = (u32) asize;
memcpy(parm->dpl.iprmmsg, buffer, 8);
} else {
parm->db.ippathid = path->pathid;
parm->db.ipflags1 = path->flags;
parm->db.iptrgcls = msg->class;
parm->db.ipsrccls = srccls;
parm->db.ipmsgtag = msg->tag;
parm->db.ipbfadr1 = (u32)(addr_t) buffer;
parm->db.ipbfln1f = (u32) size;
parm->db.ipbfadr2 = (u32)(addr_t) answer;
parm->db.ipbfln2f = (u32) asize;
}
rc = iucv_call_b2f0(IUCV_SEND, parm);
if (!rc)
msg->id = parm->db.ipmsgid;
out:
local_bh_enable();
return rc;
}
static void iucv_path_pending(struct iucv_irq_data *data)
{
struct iucv_path_pending *ipp = (void *) data;
struct iucv_handler *handler;
struct iucv_path *path;
char *error;
BUG_ON(iucv_path_table[ipp->ippathid]);
error = iucv_error_no_memory;
path = iucv_path_alloc(ipp->ipmsglim, ipp->ipflags1, GFP_ATOMIC);
if (!path)
goto out_sever;
path->pathid = ipp->ippathid;
iucv_path_table[path->pathid] = path;
EBCASC(ipp->ipvmid, 8);
list_for_each_entry(handler, &iucv_handler_list, list) {
if (!handler->path_pending)
continue;
list_add(&path->list, &handler->paths);
path->handler = handler;
if (!handler->path_pending(path, ipp->ipvmid, ipp->ipuser))
return;
list_del(&path->list);
path->handler = NULL;
}
iucv_path_table[path->pathid] = NULL;
iucv_path_free(path);
error = iucv_error_no_listener;
out_sever:
iucv_sever_pathid(ipp->ippathid, error);
}
static void iucv_path_complete(struct iucv_irq_data *data)
{
struct iucv_path_complete *ipc = (void *) data;
struct iucv_path *path = iucv_path_table[ipc->ippathid];
if (path)
path->flags = ipc->ipflags1;
if (path && path->handler && path->handler->path_complete)
path->handler->path_complete(path, ipc->ipuser);
}
static void iucv_path_severed(struct iucv_irq_data *data)
{
struct iucv_path_severed *ips = (void *) data;
struct iucv_path *path = iucv_path_table[ips->ippathid];
if (!path || !path->handler)
return;
if (path->handler->path_severed)
path->handler->path_severed(path, ips->ipuser);
else {
iucv_sever_pathid(path->pathid, NULL);
iucv_path_table[path->pathid] = NULL;
list_del(&path->list);
iucv_path_free(path);
}
}
static void iucv_path_quiesced(struct iucv_irq_data *data)
{
struct iucv_path_quiesced *ipq = (void *) data;
struct iucv_path *path = iucv_path_table[ipq->ippathid];
if (path && path->handler && path->handler->path_quiesced)
path->handler->path_quiesced(path, ipq->ipuser);
}
static void iucv_path_resumed(struct iucv_irq_data *data)
{
struct iucv_path_resumed *ipr = (void *) data;
struct iucv_path *path = iucv_path_table[ipr->ippathid];
if (path && path->handler && path->handler->path_resumed)
path->handler->path_resumed(path, ipr->ipuser);
}
static void iucv_message_complete(struct iucv_irq_data *data)
{
struct iucv_message_complete *imc = (void *) data;
struct iucv_path *path = iucv_path_table[imc->ippathid];
struct iucv_message msg;
if (path && path->handler && path->handler->message_complete) {
msg.flags = imc->ipflags1;
msg.id = imc->ipmsgid;
msg.audit = imc->ipaudit;
memcpy(msg.rmmsg, imc->iprmmsg, 8);
msg.class = imc->ipsrccls;
msg.tag = imc->ipmsgtag;
msg.length = imc->ipbfln2f;
path->handler->message_complete(path, &msg);
}
}
static void iucv_message_pending(struct iucv_irq_data *data)
{
struct iucv_message_pending *imp = (void *) data;
struct iucv_path *path = iucv_path_table[imp->ippathid];
struct iucv_message msg;
if (path && path->handler && path->handler->message_pending) {
msg.flags = imp->ipflags1;
msg.id = imp->ipmsgid;
msg.class = imp->iptrgcls;
if (imp->ipflags1 & IUCV_IPRMDATA) {
memcpy(msg.rmmsg, imp->ln1msg1.iprmmsg1, 8);
msg.length = 8;
} else
msg.length = imp->ln1msg2.ipbfln1f;
msg.reply_size = imp->ipbfln2f;
path->handler->message_pending(path, &msg);
}
}
static void iucv_tasklet_fn(unsigned long ignored)
{
typedef void iucv_irq_fn(struct iucv_irq_data *);
static iucv_irq_fn *irq_fn[] = {
[0x02] = iucv_path_complete,
[0x03] = iucv_path_severed,
[0x04] = iucv_path_quiesced,
[0x05] = iucv_path_resumed,
[0x06] = iucv_message_complete,
[0x07] = iucv_message_complete,
[0x08] = iucv_message_pending,
[0x09] = iucv_message_pending,
};
LIST_HEAD(task_queue);
struct iucv_irq_list *p, *n;
if (!spin_trylock(&iucv_table_lock)) {
tasklet_schedule(&iucv_tasklet);
return;
}
iucv_active_cpu = smp_processor_id();
spin_lock_irq(&iucv_queue_lock);
list_splice_init(&iucv_task_queue, &task_queue);
spin_unlock_irq(&iucv_queue_lock);
list_for_each_entry_safe(p, n, &task_queue, list) {
list_del_init(&p->list);
irq_fn[p->data.iptype](&p->data);
kfree(p);
}
iucv_active_cpu = -1;
spin_unlock(&iucv_table_lock);
}
static void iucv_work_fn(struct work_struct *work)
{
LIST_HEAD(work_queue);
struct iucv_irq_list *p, *n;
spin_lock_bh(&iucv_table_lock);
iucv_active_cpu = smp_processor_id();
spin_lock_irq(&iucv_queue_lock);
list_splice_init(&iucv_work_queue, &work_queue);
spin_unlock_irq(&iucv_queue_lock);
iucv_cleanup_queue();
list_for_each_entry_safe(p, n, &work_queue, list) {
list_del_init(&p->list);
iucv_path_pending(&p->data);
kfree(p);
}
iucv_active_cpu = -1;
spin_unlock_bh(&iucv_table_lock);
}
static void iucv_external_interrupt(struct ext_code ext_code,
unsigned int param32, unsigned long param64)
{
struct iucv_irq_data *p;
struct iucv_irq_list *work;
inc_irq_stat(IRQEXT_IUC);
p = iucv_irq_data[smp_processor_id()];
if (p->ippathid >= iucv_max_pathid) {
WARN_ON(p->ippathid >= iucv_max_pathid);
iucv_sever_pathid(p->ippathid, iucv_error_no_listener);
return;
}
BUG_ON(p->iptype < 0x01 || p->iptype > 0x09);
work = kmalloc(sizeof(struct iucv_irq_list), GFP_ATOMIC);
if (!work) {
pr_warn("iucv_external_interrupt: out of memory\n");
return;
}
memcpy(&work->data, p, sizeof(work->data));
spin_lock(&iucv_queue_lock);
if (p->iptype == 0x01) {
list_add_tail(&work->list, &iucv_work_queue);
schedule_work(&iucv_work);
} else {
list_add_tail(&work->list, &iucv_task_queue);
tasklet_schedule(&iucv_tasklet);
}
spin_unlock(&iucv_queue_lock);
}
static int iucv_pm_prepare(struct device *dev)
{
int rc = 0;
#ifdef CONFIG_PM_DEBUG
printk(KERN_INFO "iucv_pm_prepare\n");
#endif
if (dev->driver && dev->driver->pm && dev->driver->pm->prepare)
rc = dev->driver->pm->prepare(dev);
return rc;
}
static void iucv_pm_complete(struct device *dev)
{
#ifdef CONFIG_PM_DEBUG
printk(KERN_INFO "iucv_pm_complete\n");
#endif
if (dev->driver && dev->driver->pm && dev->driver->pm->complete)
dev->driver->pm->complete(dev);
}
int iucv_path_table_empty(void)
{
int i;
for (i = 0; i < iucv_max_pathid; i++) {
if (iucv_path_table[i])
return 0;
}
return 1;
}
static int iucv_pm_freeze(struct device *dev)
{
int cpu;
struct iucv_irq_list *p, *n;
int rc = 0;
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "iucv_pm_freeze\n");
#endif
if (iucv_pm_state != IUCV_PM_FREEZING) {
for_each_cpu(cpu, &iucv_irq_cpumask)
smp_call_function_single(cpu, iucv_block_cpu_almost,
NULL, 1);
cancel_work_sync(&iucv_work);
list_for_each_entry_safe(p, n, &iucv_work_queue, list) {
list_del_init(&p->list);
iucv_sever_pathid(p->data.ippathid,
iucv_error_no_listener);
kfree(p);
}
}
iucv_pm_state = IUCV_PM_FREEZING;
if (dev->driver && dev->driver->pm && dev->driver->pm->freeze)
rc = dev->driver->pm->freeze(dev);
if (iucv_path_table_empty())
iucv_disable();
return rc;
}
static int iucv_pm_thaw(struct device *dev)
{
int rc = 0;
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "iucv_pm_thaw\n");
#endif
iucv_pm_state = IUCV_PM_THAWING;
if (!iucv_path_table) {
rc = iucv_enable();
if (rc)
goto out;
}
if (cpumask_empty(&iucv_irq_cpumask)) {
if (iucv_nonsmp_handler)
iucv_allow_cpu(NULL);
else
iucv_setmask_mp();
}
if (dev->driver && dev->driver->pm && dev->driver->pm->thaw)
rc = dev->driver->pm->thaw(dev);
out:
return rc;
}
static int iucv_pm_restore(struct device *dev)
{
int rc = 0;
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "iucv_pm_restore %p\n", iucv_path_table);
#endif
if ((iucv_pm_state != IUCV_PM_RESTORING) && iucv_path_table)
pr_warn("Suspending Linux did not completely close all IUCV connections\n");
iucv_pm_state = IUCV_PM_RESTORING;
if (cpumask_empty(&iucv_irq_cpumask)) {
rc = iucv_query_maxconn();
rc = iucv_enable();
if (rc)
goto out;
}
if (dev->driver && dev->driver->pm && dev->driver->pm->restore)
rc = dev->driver->pm->restore(dev);
out:
return rc;
}
static int __init iucv_init(void)
{
int rc;
int cpu;
if (!MACHINE_IS_VM) {
rc = -EPROTONOSUPPORT;
goto out;
}
ctl_set_bit(0, 1);
rc = iucv_query_maxconn();
if (rc)
goto out_ctl;
rc = register_external_irq(EXT_IRQ_IUCV, iucv_external_interrupt);
if (rc)
goto out_ctl;
iucv_root = root_device_register("iucv");
if (IS_ERR(iucv_root)) {
rc = PTR_ERR(iucv_root);
goto out_int;
}
cpu_notifier_register_begin();
for_each_online_cpu(cpu) {
if (alloc_iucv_data(cpu)) {
rc = -ENOMEM;
goto out_free;
}
}
rc = __register_hotcpu_notifier(&iucv_cpu_notifier);
if (rc)
goto out_free;
cpu_notifier_register_done();
rc = register_reboot_notifier(&iucv_reboot_notifier);
if (rc)
goto out_cpu;
ASCEBC(iucv_error_no_listener, 16);
ASCEBC(iucv_error_no_memory, 16);
ASCEBC(iucv_error_pathid, 16);
iucv_available = 1;
rc = bus_register(&iucv_bus);
if (rc)
goto out_reboot;
iucv_if.root = iucv_root;
iucv_if.bus = &iucv_bus;
return 0;
out_reboot:
unregister_reboot_notifier(&iucv_reboot_notifier);
out_cpu:
cpu_notifier_register_begin();
__unregister_hotcpu_notifier(&iucv_cpu_notifier);
out_free:
for_each_possible_cpu(cpu)
free_iucv_data(cpu);
cpu_notifier_register_done();
root_device_unregister(iucv_root);
out_int:
unregister_external_irq(EXT_IRQ_IUCV, iucv_external_interrupt);
out_ctl:
ctl_clear_bit(0, 1);
out:
return rc;
}
static void __exit iucv_exit(void)
{
struct iucv_irq_list *p, *n;
int cpu;
spin_lock_irq(&iucv_queue_lock);
list_for_each_entry_safe(p, n, &iucv_task_queue, list)
kfree(p);
list_for_each_entry_safe(p, n, &iucv_work_queue, list)
kfree(p);
spin_unlock_irq(&iucv_queue_lock);
unregister_reboot_notifier(&iucv_reboot_notifier);
cpu_notifier_register_begin();
__unregister_hotcpu_notifier(&iucv_cpu_notifier);
for_each_possible_cpu(cpu)
free_iucv_data(cpu);
cpu_notifier_register_done();
root_device_unregister(iucv_root);
bus_unregister(&iucv_bus);
unregister_external_irq(EXT_IRQ_IUCV, iucv_external_interrupt);
}
