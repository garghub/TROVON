static int wil_is_pmc_allocated(struct pmc_ctx *pmc)
{
return !!pmc->pring_va;
}
void wil_pmc_init(struct wil6210_priv *wil)
{
memset(&wil->pmc, 0, sizeof(struct pmc_ctx));
mutex_init(&wil->pmc.lock);
}
void wil_pmc_alloc(struct wil6210_priv *wil,
int num_descriptors,
int descriptor_size)
{
u32 i;
struct pmc_ctx *pmc = &wil->pmc;
struct device *dev = wil_to_dev(wil);
struct wmi_pmc_cmd pmc_cmd = {0};
int last_cmd_err = -ENOMEM;
mutex_lock(&pmc->lock);
if (wil_is_pmc_allocated(pmc)) {
wil_err(wil, "ERROR pmc is already allocated\n");
goto no_release_err;
}
if ((num_descriptors <= 0) || (descriptor_size <= 0)) {
wil_err(wil,
"Invalid params num_descriptors(%d), descriptor_size(%d)\n",
num_descriptors, descriptor_size);
last_cmd_err = -EINVAL;
goto no_release_err;
}
if (num_descriptors > (1 << WIL_RING_SIZE_ORDER_MAX)) {
wil_err(wil,
"num_descriptors(%d) exceeds max ring size %d\n",
num_descriptors, 1 << WIL_RING_SIZE_ORDER_MAX);
last_cmd_err = -EINVAL;
goto no_release_err;
}
if (num_descriptors > INT_MAX / descriptor_size) {
wil_err(wil,
"Overflow in num_descriptors(%d)*descriptor_size(%d)\n",
num_descriptors, descriptor_size);
last_cmd_err = -EINVAL;
goto no_release_err;
}
pmc->num_descriptors = num_descriptors;
pmc->descriptor_size = descriptor_size;
wil_dbg_misc(wil, "pmc_alloc: %d descriptors x %d bytes each\n",
num_descriptors, descriptor_size);
pmc->descriptors = kcalloc(num_descriptors,
sizeof(struct desc_alloc_info),
GFP_KERNEL);
if (!pmc->descriptors) {
wil_err(wil, "ERROR allocating pmc skb list\n");
goto no_release_err;
}
wil_dbg_misc(wil, "pmc_alloc: allocated descriptors info list %p\n",
pmc->descriptors);
if (wil->use_extended_dma_addr)
dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
pmc->pring_va = dma_alloc_coherent(dev,
sizeof(struct vring_tx_desc) * num_descriptors,
&pmc->pring_pa,
GFP_KERNEL);
if (wil->use_extended_dma_addr)
dma_set_mask_and_coherent(dev, DMA_BIT_MASK(48));
wil_dbg_misc(wil,
"pmc_alloc: allocated pring %p => %pad. %zd x %d = total %zd bytes\n",
pmc->pring_va, &pmc->pring_pa,
sizeof(struct vring_tx_desc),
num_descriptors,
sizeof(struct vring_tx_desc) * num_descriptors);
if (!pmc->pring_va) {
wil_err(wil, "ERROR allocating pmc pring\n");
goto release_pmc_skb_list;
}
for (i = 0; i < num_descriptors; i++) {
struct vring_tx_desc *_d = &pmc->pring_va[i];
struct vring_tx_desc dd = {}, *d = &dd;
int j = 0;
pmc->descriptors[i].va = dma_alloc_coherent(dev,
descriptor_size,
&pmc->descriptors[i].pa,
GFP_KERNEL);
if (unlikely(!pmc->descriptors[i].va)) {
wil_err(wil, "ERROR allocating pmc descriptor %d", i);
goto release_pmc_skbs;
}
for (j = 0; j < descriptor_size / sizeof(u32); j++) {
u32 *p = (u32 *)pmc->descriptors[i].va + j;
*p = PCM_DATA_INVALID_DW_VAL | j;
}
d->dma.addr.addr_low =
cpu_to_le32(lower_32_bits(pmc->descriptors[i].pa));
d->dma.addr.addr_high =
cpu_to_le16((u16)upper_32_bits(pmc->descriptors[i].pa));
d->dma.status = 0;
d->dma.length = cpu_to_le16(descriptor_size);
d->dma.d0 = BIT(9) | RX_DMA_D0_CMD_DMA_IT;
*_d = *d;
}
wil_dbg_misc(wil, "pmc_alloc: allocated successfully\n");
pmc_cmd.op = WMI_PMC_ALLOCATE;
pmc_cmd.ring_size = cpu_to_le16(pmc->num_descriptors);
pmc_cmd.mem_base = cpu_to_le64(pmc->pring_pa);
wil_dbg_misc(wil, "pmc_alloc: send WMI_PMC_CMD with ALLOCATE op\n");
pmc->last_cmd_status = wmi_send(wil,
WMI_PMC_CMDID,
&pmc_cmd,
sizeof(pmc_cmd));
if (pmc->last_cmd_status) {
wil_err(wil,
"WMI_PMC_CMD with ALLOCATE op failed with status %d",
pmc->last_cmd_status);
goto release_pmc_skbs;
}
mutex_unlock(&pmc->lock);
return;
release_pmc_skbs:
wil_err(wil, "exit on error: Releasing skbs...\n");
for (i = 0; i < num_descriptors && pmc->descriptors[i].va; i++) {
dma_free_coherent(dev,
descriptor_size,
pmc->descriptors[i].va,
pmc->descriptors[i].pa);
pmc->descriptors[i].va = NULL;
}
wil_err(wil, "exit on error: Releasing pring...\n");
dma_free_coherent(dev,
sizeof(struct vring_tx_desc) * num_descriptors,
pmc->pring_va,
pmc->pring_pa);
pmc->pring_va = NULL;
release_pmc_skb_list:
wil_err(wil, "exit on error: Releasing descriptors info list...\n");
kfree(pmc->descriptors);
pmc->descriptors = NULL;
no_release_err:
pmc->last_cmd_status = last_cmd_err;
mutex_unlock(&pmc->lock);
}
void wil_pmc_free(struct wil6210_priv *wil, int send_pmc_cmd)
{
struct pmc_ctx *pmc = &wil->pmc;
struct device *dev = wil_to_dev(wil);
struct wmi_pmc_cmd pmc_cmd = {0};
mutex_lock(&pmc->lock);
pmc->last_cmd_status = 0;
if (!wil_is_pmc_allocated(pmc)) {
wil_dbg_misc(wil,
"pmc_free: Error, can't free - not allocated\n");
pmc->last_cmd_status = -EPERM;
mutex_unlock(&pmc->lock);
return;
}
if (send_pmc_cmd) {
wil_dbg_misc(wil, "send WMI_PMC_CMD with RELEASE op\n");
pmc_cmd.op = WMI_PMC_RELEASE;
pmc->last_cmd_status =
wmi_send(wil, WMI_PMC_CMDID, &pmc_cmd,
sizeof(pmc_cmd));
if (pmc->last_cmd_status) {
wil_err(wil,
"WMI_PMC_CMD with RELEASE op failed, status %d",
pmc->last_cmd_status);
}
}
if (pmc->pring_va) {
size_t buf_size = sizeof(struct vring_tx_desc) *
pmc->num_descriptors;
wil_dbg_misc(wil, "pmc_free: free pring va %p\n",
pmc->pring_va);
dma_free_coherent(dev, buf_size, pmc->pring_va, pmc->pring_pa);
pmc->pring_va = NULL;
} else {
pmc->last_cmd_status = -ENOENT;
}
if (pmc->descriptors) {
int i;
for (i = 0;
i < pmc->num_descriptors && pmc->descriptors[i].va; i++) {
dma_free_coherent(dev,
pmc->descriptor_size,
pmc->descriptors[i].va,
pmc->descriptors[i].pa);
pmc->descriptors[i].va = NULL;
}
wil_dbg_misc(wil, "pmc_free: free descriptor info %d/%d\n", i,
pmc->num_descriptors);
wil_dbg_misc(wil,
"pmc_free: free pmc descriptors info list %p\n",
pmc->descriptors);
kfree(pmc->descriptors);
pmc->descriptors = NULL;
} else {
pmc->last_cmd_status = -ENOENT;
}
mutex_unlock(&pmc->lock);
}
int wil_pmc_last_cmd_status(struct wil6210_priv *wil)
{
wil_dbg_misc(wil, "pmc_last_cmd_status: status %d\n",
wil->pmc.last_cmd_status);
return wil->pmc.last_cmd_status;
}
ssize_t wil_pmc_read(struct file *filp, char __user *buf, size_t count,
loff_t *f_pos)
{
struct wil6210_priv *wil = filp->private_data;
struct pmc_ctx *pmc = &wil->pmc;
size_t retval = 0;
unsigned long long idx;
loff_t offset;
size_t pmc_size;
mutex_lock(&pmc->lock);
if (!wil_is_pmc_allocated(pmc)) {
wil_err(wil, "error, pmc is not allocated!\n");
pmc->last_cmd_status = -EPERM;
mutex_unlock(&pmc->lock);
return -EPERM;
}
pmc_size = pmc->descriptor_size * pmc->num_descriptors;
wil_dbg_misc(wil,
"pmc_read: size %u, pos %lld\n",
(u32)count, *f_pos);
pmc->last_cmd_status = 0;
idx = *f_pos;
do_div(idx, pmc->descriptor_size);
offset = *f_pos - (idx * pmc->descriptor_size);
if (*f_pos >= pmc_size) {
wil_dbg_misc(wil,
"pmc_read: reached end of pmc buf: %lld >= %u\n",
*f_pos, (u32)pmc_size);
pmc->last_cmd_status = -ERANGE;
goto out;
}
wil_dbg_misc(wil,
"pmc_read: read from pos %lld (descriptor %llu, offset %llu) %zu bytes\n",
*f_pos, idx, offset, count);
retval = simple_read_from_buffer(buf,
count,
&offset,
pmc->descriptors[idx].va,
pmc->descriptor_size);
*f_pos += retval;
out:
mutex_unlock(&pmc->lock);
return retval;
}
loff_t wil_pmc_llseek(struct file *filp, loff_t off, int whence)
{
loff_t newpos;
struct wil6210_priv *wil = filp->private_data;
struct pmc_ctx *pmc = &wil->pmc;
size_t pmc_size;
mutex_lock(&pmc->lock);
if (!wil_is_pmc_allocated(pmc)) {
wil_err(wil, "error, pmc is not allocated!\n");
pmc->last_cmd_status = -EPERM;
mutex_unlock(&pmc->lock);
return -EPERM;
}
pmc_size = pmc->descriptor_size * pmc->num_descriptors;
switch (whence) {
case 0:
newpos = off;
break;
case 1:
newpos = filp->f_pos + off;
break;
case 2:
newpos = pmc_size;
break;
default:
newpos = -EINVAL;
goto out;
}
if (newpos < 0) {
newpos = -EINVAL;
goto out;
}
if (newpos > pmc_size)
newpos = pmc_size;
filp->f_pos = newpos;
out:
mutex_unlock(&pmc->lock);
return newpos;
}
