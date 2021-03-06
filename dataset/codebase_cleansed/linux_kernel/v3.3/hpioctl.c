static void hpi_send_recv_f(struct hpi_message *phm, struct hpi_response *phr,
struct file *file)
{
if ((phm->adapter_index >= HPI_MAX_ADAPTERS)
&& (phm->object != HPI_OBJ_SUBSYSTEM))
phr->error = HPI_ERROR_INVALID_OBJ_INDEX;
else
hpi_send_recv_ex(phm, phr, file);
}
void hpi_send_recv(struct hpi_message *phm, struct hpi_response *phr)
{
hpi_send_recv_f(phm, phr, HOWNER_KERNEL);
}
int asihpi_hpi_release(struct file *file)
{
struct hpi_message hm;
struct hpi_response hr;
hpi_init_message_response(&hm, &hr, HPI_OBJ_SUBSYSTEM,
HPI_SUBSYS_CLOSE);
hpi_send_recv_ex(&hm, &hr, file);
return 0;
}
long asihpi_hpi_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct hpi_ioctl_linux __user *phpi_ioctl_data;
void __user *puhm;
void __user *puhr;
union hpi_message_buffer_v1 *hm;
union hpi_response_buffer_v1 *hr;
u16 res_max_size;
u32 uncopied_bytes;
int err = 0;
if (cmd != HPI_IOCTL_LINUX)
return -EINVAL;
hm = kmalloc(sizeof(*hm), GFP_KERNEL);
hr = kmalloc(sizeof(*hr), GFP_KERNEL);
if (!hm || !hr) {
err = -ENOMEM;
goto out;
}
phpi_ioctl_data = (struct hpi_ioctl_linux __user *)arg;
if (get_user(puhm, &phpi_ioctl_data->phm)
|| get_user(puhr, &phpi_ioctl_data->phr)) {
err = -EFAULT;
goto out;
}
if (get_user(hm->h.size, (u16 __user *)puhm)) {
err = -EFAULT;
goto out;
}
if (hm->h.size > sizeof(*hm))
hm->h.size = sizeof(*hm);
uncopied_bytes = copy_from_user(hm, puhm, hm->h.size);
if (uncopied_bytes) {
HPI_DEBUG_LOG(ERROR, "uncopied bytes %d\n", uncopied_bytes);
err = -EFAULT;
goto out;
}
if (get_user(res_max_size, (u16 __user *)puhr)) {
err = -EFAULT;
goto out;
}
if (res_max_size < sizeof(struct hpi_response_header)) {
HPI_DEBUG_LOG(WARNING, "small res size %d\n", res_max_size);
err = -EFAULT;
goto out;
}
switch (hm->h.function) {
case HPI_SUBSYS_CREATE_ADAPTER:
case HPI_ADAPTER_DELETE:
hr->h.size = sizeof(hr->h);
hr->h.error = HPI_ERROR_INVALID_OPERATION;
hr->h.function = hm->h.function;
uncopied_bytes = copy_to_user(puhr, hr, hr->h.size);
if (uncopied_bytes)
err = -EFAULT;
else
err = 0;
goto out;
}
hr->h.size = res_max_size;
if (hm->h.object == HPI_OBJ_SUBSYSTEM) {
hpi_send_recv_f(&hm->m0, &hr->r0, file);
} else {
u16 __user *ptr = NULL;
u32 size = 0;
int wrflag = -1;
struct hpi_adapter *pa = NULL;
if (hm->h.adapter_index < ARRAY_SIZE(adapters))
pa = &adapters[hm->h.adapter_index];
if (!pa || !pa->adapter || !pa->adapter->type) {
hpi_init_response(&hr->r0, hm->h.object,
hm->h.function, HPI_ERROR_BAD_ADAPTER_NUMBER);
uncopied_bytes =
copy_to_user(puhr, hr, sizeof(hr->h));
if (uncopied_bytes)
err = -EFAULT;
else
err = 0;
goto out;
}
if (mutex_lock_interruptible(&pa->mutex)) {
err = -EINTR;
goto out;
}
switch (hm->h.function) {
case HPI_OSTREAM_WRITE:
case HPI_ISTREAM_READ:{
ptr = (u16 __user *)hm->m0.u.d.u.data.pb_data;
size = hm->m0.u.d.u.data.data_size;
if (pa->buffer_size < size) {
HPI_DEBUG_LOG(DEBUG,
"Realloc adapter %d stream "
"buffer from %zd to %d\n",
hm->h.adapter_index,
pa->buffer_size, size);
if (pa->p_buffer) {
pa->buffer_size = 0;
vfree(pa->p_buffer);
}
pa->p_buffer = vmalloc(size);
if (pa->p_buffer)
pa->buffer_size = size;
else {
HPI_DEBUG_LOG(ERROR,
"HPI could not allocate "
"stream buffer size %d\n",
size);
mutex_unlock(&pa->mutex);
err = -EINVAL;
goto out;
}
}
hm->m0.u.d.u.data.pb_data = pa->p_buffer;
if (hm->h.function == HPI_ISTREAM_READ)
wrflag = 1;
else
wrflag = 0;
break;
}
default:
size = 0;
break;
}
if (size && (wrflag == 0)) {
uncopied_bytes =
copy_from_user(pa->p_buffer, ptr, size);
if (uncopied_bytes)
HPI_DEBUG_LOG(WARNING,
"Missed %d of %d "
"bytes from user\n", uncopied_bytes,
size);
}
hpi_send_recv_f(&hm->m0, &hr->r0, file);
if (size && (wrflag == 1)) {
uncopied_bytes =
copy_to_user(ptr, pa->p_buffer, size);
if (uncopied_bytes)
HPI_DEBUG_LOG(WARNING,
"Missed %d of %d " "bytes to user\n",
uncopied_bytes, size);
}
mutex_unlock(&pa->mutex);
}
if (!hr->h.size) {
HPI_DEBUG_LOG(ERROR, "response zero size\n");
err = -EFAULT;
goto out;
}
if (hr->h.size > res_max_size) {
HPI_DEBUG_LOG(ERROR, "response too big %d %d\n", hr->h.size,
res_max_size);
hr->h.error = HPI_ERROR_RESPONSE_BUFFER_TOO_SMALL;
hr->h.specific_error = hr->h.size;
hr->h.size = sizeof(hr->h);
}
uncopied_bytes = copy_to_user(puhr, hr, hr->h.size);
if (uncopied_bytes) {
HPI_DEBUG_LOG(ERROR, "uncopied bytes %d\n", uncopied_bytes);
err = -EFAULT;
goto out;
}
out:
kfree(hm);
kfree(hr);
return err;
}
int __devinit asihpi_adapter_probe(struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
int idx, nm;
int adapter_index;
unsigned int memlen;
struct hpi_message hm;
struct hpi_response hr;
struct hpi_adapter adapter;
struct hpi_pci pci;
memset(&adapter, 0, sizeof(adapter));
dev_printk(KERN_DEBUG, &pci_dev->dev,
"probe %04x:%04x,%04x:%04x,%04x\n", pci_dev->vendor,
pci_dev->device, pci_dev->subsystem_vendor,
pci_dev->subsystem_device, pci_dev->devfn);
if (pci_enable_device(pci_dev) < 0) {
dev_printk(KERN_ERR, &pci_dev->dev,
"pci_enable_device failed, disabling device\n");
return -EIO;
}
pci_set_master(pci_dev);
hpi_init_message_response(&hm, &hr, HPI_OBJ_SUBSYSTEM,
HPI_SUBSYS_CREATE_ADAPTER);
hpi_init_response(&hr, HPI_OBJ_SUBSYSTEM, HPI_SUBSYS_CREATE_ADAPTER,
HPI_ERROR_PROCESSING_MESSAGE);
hm.adapter_index = HPI_ADAPTER_INDEX_INVALID;
nm = HPI_MAX_ADAPTER_MEM_SPACES;
for (idx = 0; idx < nm; idx++) {
HPI_DEBUG_LOG(INFO, "resource %d %pR\n", idx,
&pci_dev->resource[idx]);
if (pci_resource_flags(pci_dev, idx) & IORESOURCE_MEM) {
memlen = pci_resource_len(pci_dev, idx);
pci.ap_mem_base[idx] =
ioremap(pci_resource_start(pci_dev, idx),
memlen);
if (!pci.ap_mem_base[idx]) {
HPI_DEBUG_LOG(ERROR,
"ioremap failed, aborting\n");
goto err;
}
}
}
pci.pci_dev = pci_dev;
hm.u.s.resource.bus_type = HPI_BUS_PCI;
hm.u.s.resource.r.pci = &pci;
hpi_send_recv_ex(&hm, &hr, HOWNER_KERNEL);
if (hr.error)
goto err;
adapter_index = hr.u.s.adapter_index;
adapter.adapter = hpi_find_adapter(adapter_index);
if (prealloc_stream_buf) {
adapter.p_buffer = vmalloc(prealloc_stream_buf);
if (!adapter.p_buffer) {
HPI_DEBUG_LOG(ERROR,
"HPI could not allocate "
"kernel buffer size %d\n",
prealloc_stream_buf);
goto err;
}
}
hpi_init_message_response(&hm, &hr, HPI_OBJ_ADAPTER,
HPI_ADAPTER_OPEN);
hm.adapter_index = adapter.adapter->index;
hpi_send_recv_ex(&hm, &hr, HOWNER_KERNEL);
if (hr.error)
goto err;
adapters[adapter_index] = adapter;
mutex_init(&adapters[adapter_index].mutex);
pci_set_drvdata(pci_dev, &adapters[adapter_index]);
dev_printk(KERN_INFO, &pci_dev->dev,
"probe succeeded for ASI%04X HPI index %d\n",
adapter.adapter->type, adapter_index);
return 0;
err:
for (idx = 0; idx < HPI_MAX_ADAPTER_MEM_SPACES; idx++) {
if (pci.ap_mem_base[idx]) {
iounmap(pci.ap_mem_base[idx]);
pci.ap_mem_base[idx] = NULL;
}
}
if (adapter.p_buffer) {
adapter.buffer_size = 0;
vfree(adapter.p_buffer);
}
HPI_DEBUG_LOG(ERROR, "adapter_probe failed\n");
return -ENODEV;
}
void __devexit asihpi_adapter_remove(struct pci_dev *pci_dev)
{
int idx;
struct hpi_message hm;
struct hpi_response hr;
struct hpi_adapter *pa;
struct hpi_pci pci;
pa = pci_get_drvdata(pci_dev);
pci = pa->adapter->pci;
hpi_init_message_response(&hm, &hr, HPI_OBJ_ADAPTER,
HPI_ADAPTER_DELETE);
hm.adapter_index = pa->adapter->index;
hpi_send_recv_ex(&hm, &hr, HOWNER_KERNEL);
for (idx = 0; idx < HPI_MAX_ADAPTER_MEM_SPACES; idx++) {
if (pci.ap_mem_base[idx])
iounmap(pci.ap_mem_base[idx]);
}
if (pa->p_buffer)
vfree(pa->p_buffer);
pci_set_drvdata(pci_dev, NULL);
if (1)
dev_printk(KERN_INFO, &pci_dev->dev,
"remove %04x:%04x,%04x:%04x,%04x," " HPI index %d.\n",
pci_dev->vendor, pci_dev->device,
pci_dev->subsystem_vendor, pci_dev->subsystem_device,
pci_dev->devfn, pa->adapter->index);
memset(pa, 0, sizeof(*pa));
}
void __init asihpi_init(void)
{
struct hpi_message hm;
struct hpi_response hr;
memset(adapters, 0, sizeof(adapters));
printk(KERN_INFO "ASIHPI driver " HPI_VER_STRING "\n");
hpi_init_message_response(&hm, &hr, HPI_OBJ_SUBSYSTEM,
HPI_SUBSYS_DRIVER_LOAD);
hpi_send_recv_ex(&hm, &hr, HOWNER_KERNEL);
}
void asihpi_exit(void)
{
struct hpi_message hm;
struct hpi_response hr;
hpi_init_message_response(&hm, &hr, HPI_OBJ_SUBSYSTEM,
HPI_SUBSYS_DRIVER_UNLOAD);
hpi_send_recv_ex(&hm, &hr, HOWNER_KERNEL);
}
