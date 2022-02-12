static int ntb_transport_bus_match(struct device *dev,
struct device_driver *drv)
{
return !strncmp(dev_name(dev), drv->name, strlen(drv->name));
}
static int ntb_transport_bus_probe(struct device *dev)
{
const struct ntb_transport_client *client;
int rc = -EINVAL;
get_device(dev);
client = drv_client(dev->driver);
rc = client->probe(dev);
if (rc)
put_device(dev);
return rc;
}
static int ntb_transport_bus_remove(struct device *dev)
{
const struct ntb_transport_client *client;
client = drv_client(dev->driver);
client->remove(dev);
put_device(dev);
return 0;
}
static int ntb_bus_init(struct ntb_transport_ctx *nt)
{
list_add_tail(&nt->entry, &ntb_transport_list);
return 0;
}
static void ntb_bus_remove(struct ntb_transport_ctx *nt)
{
struct ntb_transport_client_dev *client_dev, *cd;
list_for_each_entry_safe(client_dev, cd, &nt->client_devs, entry) {
dev_err(client_dev->dev.parent, "%s still attached to bus, removing\n",
dev_name(&client_dev->dev));
list_del(&client_dev->entry);
device_unregister(&client_dev->dev);
}
list_del(&nt->entry);
}
static void ntb_transport_client_release(struct device *dev)
{
struct ntb_transport_client_dev *client_dev;
client_dev = dev_client_dev(dev);
kfree(client_dev);
}
void ntb_transport_unregister_client_dev(char *device_name)
{
struct ntb_transport_client_dev *client, *cd;
struct ntb_transport_ctx *nt;
list_for_each_entry(nt, &ntb_transport_list, entry)
list_for_each_entry_safe(client, cd, &nt->client_devs, entry)
if (!strncmp(dev_name(&client->dev), device_name,
strlen(device_name))) {
list_del(&client->entry);
device_unregister(&client->dev);
}
}
int ntb_transport_register_client_dev(char *device_name)
{
struct ntb_transport_client_dev *client_dev;
struct ntb_transport_ctx *nt;
int node;
int rc, i = 0;
if (list_empty(&ntb_transport_list))
return -ENODEV;
list_for_each_entry(nt, &ntb_transport_list, entry) {
struct device *dev;
node = dev_to_node(&nt->ndev->dev);
client_dev = kzalloc_node(sizeof(*client_dev),
GFP_KERNEL, node);
if (!client_dev) {
rc = -ENOMEM;
goto err;
}
dev = &client_dev->dev;
dev_set_name(dev, "%s%d", device_name, i);
dev->bus = &ntb_transport_bus;
dev->release = ntb_transport_client_release;
dev->parent = &nt->ndev->dev;
rc = device_register(dev);
if (rc) {
kfree(client_dev);
goto err;
}
list_add_tail(&client_dev->entry, &nt->client_devs);
i++;
}
return 0;
err:
ntb_transport_unregister_client_dev(device_name);
return rc;
}
int ntb_transport_register_client(struct ntb_transport_client *drv)
{
drv->driver.bus = &ntb_transport_bus;
if (list_empty(&ntb_transport_list))
return -ENODEV;
return driver_register(&drv->driver);
}
void ntb_transport_unregister_client(struct ntb_transport_client *drv)
{
driver_unregister(&drv->driver);
}
static ssize_t debugfs_read(struct file *filp, char __user *ubuf, size_t count,
loff_t *offp)
{
struct ntb_transport_qp *qp;
char *buf;
ssize_t ret, out_offset, out_count;
qp = filp->private_data;
if (!qp || !qp->link_is_up)
return 0;
out_count = 1000;
buf = kmalloc(out_count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
out_offset = 0;
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"\nNTB QP stats:\n\n");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_bytes - \t%llu\n", qp->rx_bytes);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_pkts - \t%llu\n", qp->rx_pkts);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_memcpy - \t%llu\n", qp->rx_memcpy);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_async - \t%llu\n", qp->rx_async);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_ring_empty - %llu\n", qp->rx_ring_empty);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_err_no_buf - %llu\n", qp->rx_err_no_buf);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_err_oflow - \t%llu\n", qp->rx_err_oflow);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_err_ver - \t%llu\n", qp->rx_err_ver);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_buff - \t0x%p\n", qp->rx_buff);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_index - \t%u\n", qp->rx_index);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_max_entry - \t%u\n", qp->rx_max_entry);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_alloc_entry - \t%u\n\n", qp->rx_alloc_entry);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_bytes - \t%llu\n", qp->tx_bytes);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_pkts - \t%llu\n", qp->tx_pkts);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_memcpy - \t%llu\n", qp->tx_memcpy);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_async - \t%llu\n", qp->tx_async);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_ring_full - \t%llu\n", qp->tx_ring_full);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_err_no_buf - %llu\n", qp->tx_err_no_buf);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_mw - \t0x%p\n", qp->tx_mw);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_index (H) - \t%u\n", qp->tx_index);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"RRI (T) - \t%u\n",
qp->remote_rx_info->entry);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_max_entry - \t%u\n", qp->tx_max_entry);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"free tx - \t%u\n",
ntb_transport_tx_free_entry(qp));
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"\n");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"Using TX DMA - \t%s\n",
qp->tx_dma_chan ? "Yes" : "No");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"Using RX DMA - \t%s\n",
qp->rx_dma_chan ? "Yes" : "No");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"QP Link - \t%s\n",
qp->link_is_up ? "Up" : "Down");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"\n");
if (out_offset > out_count)
out_offset = out_count;
ret = simple_read_from_buffer(ubuf, count, offp, buf, out_offset);
kfree(buf);
return ret;
}
static void ntb_list_add(spinlock_t *lock, struct list_head *entry,
struct list_head *list)
{
unsigned long flags;
spin_lock_irqsave(lock, flags);
list_add_tail(entry, list);
spin_unlock_irqrestore(lock, flags);
}
static struct ntb_queue_entry *ntb_list_rm(spinlock_t *lock,
struct list_head *list)
{
struct ntb_queue_entry *entry;
unsigned long flags;
spin_lock_irqsave(lock, flags);
if (list_empty(list)) {
entry = NULL;
goto out;
}
entry = list_first_entry(list, struct ntb_queue_entry, entry);
list_del(&entry->entry);
out:
spin_unlock_irqrestore(lock, flags);
return entry;
}
static struct ntb_queue_entry *ntb_list_mv(spinlock_t *lock,
struct list_head *list,
struct list_head *to_list)
{
struct ntb_queue_entry *entry;
unsigned long flags;
spin_lock_irqsave(lock, flags);
if (list_empty(list)) {
entry = NULL;
} else {
entry = list_first_entry(list, struct ntb_queue_entry, entry);
list_move_tail(&entry->entry, to_list);
}
spin_unlock_irqrestore(lock, flags);
return entry;
}
static int ntb_transport_setup_qp_mw(struct ntb_transport_ctx *nt,
unsigned int qp_num)
{
struct ntb_transport_qp *qp = &nt->qp_vec[qp_num];
struct ntb_transport_mw *mw;
struct ntb_dev *ndev = nt->ndev;
struct ntb_queue_entry *entry;
unsigned int rx_size, num_qps_mw;
unsigned int mw_num, mw_count, qp_count;
unsigned int i;
int node;
mw_count = nt->mw_count;
qp_count = nt->qp_count;
mw_num = QP_TO_MW(nt, qp_num);
mw = &nt->mw_vec[mw_num];
if (!mw->virt_addr)
return -ENOMEM;
if (mw_num < qp_count % mw_count)
num_qps_mw = qp_count / mw_count + 1;
else
num_qps_mw = qp_count / mw_count;
rx_size = (unsigned int)mw->xlat_size / num_qps_mw;
qp->rx_buff = mw->virt_addr + rx_size * (qp_num / mw_count);
rx_size -= sizeof(struct ntb_rx_info);
qp->remote_rx_info = qp->rx_buff + rx_size;
qp->rx_max_frame = min(transport_mtu, rx_size / 2);
qp->rx_max_entry = rx_size / qp->rx_max_frame;
qp->rx_index = 0;
node = dev_to_node(&ndev->dev);
for (i = qp->rx_alloc_entry; i < qp->rx_max_entry; i++) {
entry = kzalloc_node(sizeof(*entry), GFP_ATOMIC, node);
if (!entry)
return -ENOMEM;
entry->qp = qp;
ntb_list_add(&qp->ntb_rx_q_lock, &entry->entry,
&qp->rx_free_q);
qp->rx_alloc_entry++;
}
qp->remote_rx_info->entry = qp->rx_max_entry - 1;
for (i = 0; i < qp->rx_max_entry; i++) {
void *offset = (qp->rx_buff + qp->rx_max_frame * (i + 1) -
sizeof(struct ntb_payload_header));
memset(offset, 0, sizeof(struct ntb_payload_header));
}
qp->rx_pkts = 0;
qp->tx_pkts = 0;
qp->tx_index = 0;
return 0;
}
static void ntb_free_mw(struct ntb_transport_ctx *nt, int num_mw)
{
struct ntb_transport_mw *mw = &nt->mw_vec[num_mw];
struct pci_dev *pdev = nt->ndev->pdev;
if (!mw->virt_addr)
return;
ntb_mw_clear_trans(nt->ndev, PIDX, num_mw);
dma_free_coherent(&pdev->dev, mw->buff_size,
mw->virt_addr, mw->dma_addr);
mw->xlat_size = 0;
mw->buff_size = 0;
mw->virt_addr = NULL;
}
static int ntb_set_mw(struct ntb_transport_ctx *nt, int num_mw,
resource_size_t size)
{
struct ntb_transport_mw *mw = &nt->mw_vec[num_mw];
struct pci_dev *pdev = nt->ndev->pdev;
size_t xlat_size, buff_size;
int rc;
if (!size)
return -EINVAL;
xlat_size = round_up(size, mw->xlat_align_size);
buff_size = round_up(size, mw->xlat_align);
if (mw->xlat_size == xlat_size)
return 0;
if (mw->buff_size)
ntb_free_mw(nt, num_mw);
mw->xlat_size = xlat_size;
mw->buff_size = buff_size;
mw->virt_addr = dma_alloc_coherent(&pdev->dev, buff_size,
&mw->dma_addr, GFP_KERNEL);
if (!mw->virt_addr) {
mw->xlat_size = 0;
mw->buff_size = 0;
dev_err(&pdev->dev, "Unable to alloc MW buff of size %zu\n",
buff_size);
return -ENOMEM;
}
if (!IS_ALIGNED(mw->dma_addr, mw->xlat_align)) {
dev_err(&pdev->dev, "DMA memory %pad is not aligned\n",
&mw->dma_addr);
ntb_free_mw(nt, num_mw);
return -ENOMEM;
}
rc = ntb_mw_set_trans(nt->ndev, PIDX, num_mw, mw->dma_addr,
mw->xlat_size);
if (rc) {
dev_err(&pdev->dev, "Unable to set mw%d translation", num_mw);
ntb_free_mw(nt, num_mw);
return -EIO;
}
return 0;
}
static void ntb_qp_link_down_reset(struct ntb_transport_qp *qp)
{
qp->link_is_up = false;
qp->active = false;
qp->tx_index = 0;
qp->rx_index = 0;
qp->rx_bytes = 0;
qp->rx_pkts = 0;
qp->rx_ring_empty = 0;
qp->rx_err_no_buf = 0;
qp->rx_err_oflow = 0;
qp->rx_err_ver = 0;
qp->rx_memcpy = 0;
qp->rx_async = 0;
qp->tx_bytes = 0;
qp->tx_pkts = 0;
qp->tx_ring_full = 0;
qp->tx_err_no_buf = 0;
qp->tx_memcpy = 0;
qp->tx_async = 0;
}
static void ntb_qp_link_cleanup(struct ntb_transport_qp *qp)
{
struct ntb_transport_ctx *nt = qp->transport;
struct pci_dev *pdev = nt->ndev->pdev;
dev_info(&pdev->dev, "qp %d: Link Cleanup\n", qp->qp_num);
cancel_delayed_work_sync(&qp->link_work);
ntb_qp_link_down_reset(qp);
if (qp->event_handler)
qp->event_handler(qp->cb_data, qp->link_is_up);
}
static void ntb_qp_link_cleanup_work(struct work_struct *work)
{
struct ntb_transport_qp *qp = container_of(work,
struct ntb_transport_qp,
link_cleanup);
struct ntb_transport_ctx *nt = qp->transport;
ntb_qp_link_cleanup(qp);
if (nt->link_is_up)
schedule_delayed_work(&qp->link_work,
msecs_to_jiffies(NTB_LINK_DOWN_TIMEOUT));
}
static void ntb_qp_link_down(struct ntb_transport_qp *qp)
{
schedule_work(&qp->link_cleanup);
}
static void ntb_transport_link_cleanup(struct ntb_transport_ctx *nt)
{
struct ntb_transport_qp *qp;
u64 qp_bitmap_alloc;
unsigned int i, count;
qp_bitmap_alloc = nt->qp_bitmap & ~nt->qp_bitmap_free;
for (i = 0; i < nt->qp_count; i++)
if (qp_bitmap_alloc & BIT_ULL(i)) {
qp = &nt->qp_vec[i];
ntb_qp_link_cleanup(qp);
cancel_work_sync(&qp->link_cleanup);
cancel_delayed_work_sync(&qp->link_work);
}
if (!nt->link_is_up)
cancel_delayed_work_sync(&nt->link_work);
count = ntb_spad_count(nt->ndev);
for (i = 0; i < count; i++)
ntb_spad_write(nt->ndev, i, 0);
}
static void ntb_transport_link_cleanup_work(struct work_struct *work)
{
struct ntb_transport_ctx *nt =
container_of(work, struct ntb_transport_ctx, link_cleanup);
ntb_transport_link_cleanup(nt);
}
static void ntb_transport_event_callback(void *data)
{
struct ntb_transport_ctx *nt = data;
if (ntb_link_is_up(nt->ndev, NULL, NULL) == 1)
schedule_delayed_work(&nt->link_work, 0);
else
schedule_work(&nt->link_cleanup);
}
static void ntb_transport_link_work(struct work_struct *work)
{
struct ntb_transport_ctx *nt =
container_of(work, struct ntb_transport_ctx, link_work.work);
struct ntb_dev *ndev = nt->ndev;
struct pci_dev *pdev = ndev->pdev;
resource_size_t size;
u32 val;
int rc = 0, i, spad;
for (i = 0; i < nt->mw_count; i++) {
size = nt->mw_vec[i].phys_size;
if (max_mw_size && size > max_mw_size)
size = max_mw_size;
spad = MW0_SZ_HIGH + (i * 2);
ntb_peer_spad_write(ndev, PIDX, spad, upper_32_bits(size));
spad = MW0_SZ_LOW + (i * 2);
ntb_peer_spad_write(ndev, PIDX, spad, lower_32_bits(size));
}
ntb_peer_spad_write(ndev, PIDX, NUM_MWS, nt->mw_count);
ntb_peer_spad_write(ndev, PIDX, NUM_QPS, nt->qp_count);
ntb_peer_spad_write(ndev, PIDX, VERSION, NTB_TRANSPORT_VERSION);
val = ntb_spad_read(ndev, VERSION);
dev_dbg(&pdev->dev, "Remote version = %d\n", val);
if (val != NTB_TRANSPORT_VERSION)
goto out;
val = ntb_spad_read(ndev, NUM_QPS);
dev_dbg(&pdev->dev, "Remote max number of qps = %d\n", val);
if (val != nt->qp_count)
goto out;
val = ntb_spad_read(ndev, NUM_MWS);
dev_dbg(&pdev->dev, "Remote number of mws = %d\n", val);
if (val != nt->mw_count)
goto out;
for (i = 0; i < nt->mw_count; i++) {
u64 val64;
val = ntb_spad_read(ndev, MW0_SZ_HIGH + (i * 2));
val64 = (u64)val << 32;
val = ntb_spad_read(ndev, MW0_SZ_LOW + (i * 2));
val64 |= val;
dev_dbg(&pdev->dev, "Remote MW%d size = %#llx\n", i, val64);
rc = ntb_set_mw(nt, i, val64);
if (rc)
goto out1;
}
nt->link_is_up = true;
for (i = 0; i < nt->qp_count; i++) {
struct ntb_transport_qp *qp = &nt->qp_vec[i];
ntb_transport_setup_qp_mw(nt, i);
if (qp->client_ready)
schedule_delayed_work(&qp->link_work, 0);
}
return;
out1:
for (i = 0; i < nt->mw_count; i++)
ntb_free_mw(nt, i);
if (rc < 0)
return;
out:
if (ntb_link_is_up(ndev, NULL, NULL) == 1)
schedule_delayed_work(&nt->link_work,
msecs_to_jiffies(NTB_LINK_DOWN_TIMEOUT));
}
static void ntb_qp_link_work(struct work_struct *work)
{
struct ntb_transport_qp *qp = container_of(work,
struct ntb_transport_qp,
link_work.work);
struct pci_dev *pdev = qp->ndev->pdev;
struct ntb_transport_ctx *nt = qp->transport;
int val;
WARN_ON(!nt->link_is_up);
val = ntb_spad_read(nt->ndev, QP_LINKS);
ntb_peer_spad_write(nt->ndev, PIDX, QP_LINKS, val | BIT(qp->qp_num));
dev_dbg_ratelimited(&pdev->dev, "Remote QP link status = %x\n", val);
if (val & BIT(qp->qp_num)) {
dev_info(&pdev->dev, "qp %d: Link Up\n", qp->qp_num);
qp->link_is_up = true;
qp->active = true;
if (qp->event_handler)
qp->event_handler(qp->cb_data, qp->link_is_up);
if (qp->active)
tasklet_schedule(&qp->rxc_db_work);
} else if (nt->link_is_up)
schedule_delayed_work(&qp->link_work,
msecs_to_jiffies(NTB_LINK_DOWN_TIMEOUT));
}
static int ntb_transport_init_queue(struct ntb_transport_ctx *nt,
unsigned int qp_num)
{
struct ntb_transport_qp *qp;
phys_addr_t mw_base;
resource_size_t mw_size;
unsigned int num_qps_mw, tx_size;
unsigned int mw_num, mw_count, qp_count;
u64 qp_offset;
mw_count = nt->mw_count;
qp_count = nt->qp_count;
mw_num = QP_TO_MW(nt, qp_num);
qp = &nt->qp_vec[qp_num];
qp->qp_num = qp_num;
qp->transport = nt;
qp->ndev = nt->ndev;
qp->client_ready = false;
qp->event_handler = NULL;
ntb_qp_link_down_reset(qp);
if (mw_num < qp_count % mw_count)
num_qps_mw = qp_count / mw_count + 1;
else
num_qps_mw = qp_count / mw_count;
mw_base = nt->mw_vec[mw_num].phys_addr;
mw_size = nt->mw_vec[mw_num].phys_size;
tx_size = (unsigned int)mw_size / num_qps_mw;
qp_offset = tx_size * (qp_num / mw_count);
qp->tx_mw = nt->mw_vec[mw_num].vbase + qp_offset;
if (!qp->tx_mw)
return -EINVAL;
qp->tx_mw_phys = mw_base + qp_offset;
if (!qp->tx_mw_phys)
return -EINVAL;
tx_size -= sizeof(struct ntb_rx_info);
qp->rx_info = qp->tx_mw + tx_size;
qp->tx_max_frame = min(transport_mtu, tx_size / 2);
qp->tx_max_entry = tx_size / qp->tx_max_frame;
if (nt->debugfs_node_dir) {
char debugfs_name[4];
snprintf(debugfs_name, 4, "qp%d", qp_num);
qp->debugfs_dir = debugfs_create_dir(debugfs_name,
nt->debugfs_node_dir);
qp->debugfs_stats = debugfs_create_file("stats", S_IRUSR,
qp->debugfs_dir, qp,
&ntb_qp_debugfs_stats);
} else {
qp->debugfs_dir = NULL;
qp->debugfs_stats = NULL;
}
INIT_DELAYED_WORK(&qp->link_work, ntb_qp_link_work);
INIT_WORK(&qp->link_cleanup, ntb_qp_link_cleanup_work);
spin_lock_init(&qp->ntb_rx_q_lock);
spin_lock_init(&qp->ntb_tx_free_q_lock);
INIT_LIST_HEAD(&qp->rx_post_q);
INIT_LIST_HEAD(&qp->rx_pend_q);
INIT_LIST_HEAD(&qp->rx_free_q);
INIT_LIST_HEAD(&qp->tx_free_q);
tasklet_init(&qp->rxc_db_work, ntb_transport_rxc_db,
(unsigned long)qp);
return 0;
}
static int ntb_transport_probe(struct ntb_client *self, struct ntb_dev *ndev)
{
struct ntb_transport_ctx *nt;
struct ntb_transport_mw *mw;
unsigned int mw_count, qp_count, spad_count, max_mw_count_for_spads;
u64 qp_bitmap;
int node;
int rc, i;
mw_count = ntb_peer_mw_count(ndev);
if (!ndev->ops->mw_set_trans) {
dev_err(&ndev->dev, "Inbound MW based NTB API is required\n");
return -EINVAL;
}
if (ntb_db_is_unsafe(ndev))
dev_dbg(&ndev->dev,
"doorbell is unsafe, proceed anyway...\n");
if (ntb_spad_is_unsafe(ndev))
dev_dbg(&ndev->dev,
"scratchpad is unsafe, proceed anyway...\n");
if (ntb_peer_port_count(ndev) != NTB_DEF_PEER_CNT)
dev_warn(&ndev->dev, "Multi-port NTB devices unsupported\n");
node = dev_to_node(&ndev->dev);
nt = kzalloc_node(sizeof(*nt), GFP_KERNEL, node);
if (!nt)
return -ENOMEM;
nt->ndev = ndev;
spad_count = ntb_spad_count(ndev);
if (spad_count < NTB_TRANSPORT_MIN_SPADS) {
nt->mw_count = 0;
rc = -EINVAL;
goto err;
}
max_mw_count_for_spads = (spad_count - MW0_SZ_HIGH) / 2;
nt->mw_count = min(mw_count, max_mw_count_for_spads);
nt->mw_vec = kzalloc_node(mw_count * sizeof(*nt->mw_vec),
GFP_KERNEL, node);
if (!nt->mw_vec) {
rc = -ENOMEM;
goto err;
}
for (i = 0; i < mw_count; i++) {
mw = &nt->mw_vec[i];
rc = ntb_mw_get_align(ndev, PIDX, i, &mw->xlat_align,
&mw->xlat_align_size, NULL);
if (rc)
goto err1;
rc = ntb_peer_mw_get_addr(ndev, i, &mw->phys_addr,
&mw->phys_size);
if (rc)
goto err1;
mw->vbase = ioremap_wc(mw->phys_addr, mw->phys_size);
if (!mw->vbase) {
rc = -ENOMEM;
goto err1;
}
mw->buff_size = 0;
mw->xlat_size = 0;
mw->virt_addr = NULL;
mw->dma_addr = 0;
}
qp_bitmap = ntb_db_valid_mask(ndev);
qp_count = ilog2(qp_bitmap);
if (max_num_clients && max_num_clients < qp_count)
qp_count = max_num_clients;
else if (nt->mw_count < qp_count)
qp_count = nt->mw_count;
qp_bitmap &= BIT_ULL(qp_count) - 1;
nt->qp_count = qp_count;
nt->qp_bitmap = qp_bitmap;
nt->qp_bitmap_free = qp_bitmap;
nt->qp_vec = kzalloc_node(qp_count * sizeof(*nt->qp_vec),
GFP_KERNEL, node);
if (!nt->qp_vec) {
rc = -ENOMEM;
goto err1;
}
if (nt_debugfs_dir) {
nt->debugfs_node_dir =
debugfs_create_dir(pci_name(ndev->pdev),
nt_debugfs_dir);
}
for (i = 0; i < qp_count; i++) {
rc = ntb_transport_init_queue(nt, i);
if (rc)
goto err2;
}
INIT_DELAYED_WORK(&nt->link_work, ntb_transport_link_work);
INIT_WORK(&nt->link_cleanup, ntb_transport_link_cleanup_work);
rc = ntb_set_ctx(ndev, nt, &ntb_transport_ops);
if (rc)
goto err2;
INIT_LIST_HEAD(&nt->client_devs);
rc = ntb_bus_init(nt);
if (rc)
goto err3;
nt->link_is_up = false;
ntb_link_enable(ndev, NTB_SPEED_AUTO, NTB_WIDTH_AUTO);
ntb_link_event(ndev);
return 0;
err3:
ntb_clear_ctx(ndev);
err2:
kfree(nt->qp_vec);
err1:
while (i--) {
mw = &nt->mw_vec[i];
iounmap(mw->vbase);
}
kfree(nt->mw_vec);
err:
kfree(nt);
return rc;
}
static void ntb_transport_free(struct ntb_client *self, struct ntb_dev *ndev)
{
struct ntb_transport_ctx *nt = ndev->ctx;
struct ntb_transport_qp *qp;
u64 qp_bitmap_alloc;
int i;
ntb_transport_link_cleanup(nt);
cancel_work_sync(&nt->link_cleanup);
cancel_delayed_work_sync(&nt->link_work);
qp_bitmap_alloc = nt->qp_bitmap & ~nt->qp_bitmap_free;
for (i = 0; i < nt->qp_count; i++) {
qp = &nt->qp_vec[i];
if (qp_bitmap_alloc & BIT_ULL(i))
ntb_transport_free_queue(qp);
debugfs_remove_recursive(qp->debugfs_dir);
}
ntb_link_disable(ndev);
ntb_clear_ctx(ndev);
ntb_bus_remove(nt);
for (i = nt->mw_count; i--; ) {
ntb_free_mw(nt, i);
iounmap(nt->mw_vec[i].vbase);
}
kfree(nt->qp_vec);
kfree(nt->mw_vec);
kfree(nt);
}
static void ntb_complete_rxc(struct ntb_transport_qp *qp)
{
struct ntb_queue_entry *entry;
void *cb_data;
unsigned int len;
unsigned long irqflags;
spin_lock_irqsave(&qp->ntb_rx_q_lock, irqflags);
while (!list_empty(&qp->rx_post_q)) {
entry = list_first_entry(&qp->rx_post_q,
struct ntb_queue_entry, entry);
if (!(entry->flags & DESC_DONE_FLAG))
break;
entry->rx_hdr->flags = 0;
iowrite32(entry->rx_index, &qp->rx_info->entry);
cb_data = entry->cb_data;
len = entry->len;
list_move_tail(&entry->entry, &qp->rx_free_q);
spin_unlock_irqrestore(&qp->ntb_rx_q_lock, irqflags);
if (qp->rx_handler && qp->client_ready)
qp->rx_handler(qp, qp->cb_data, cb_data, len);
spin_lock_irqsave(&qp->ntb_rx_q_lock, irqflags);
}
spin_unlock_irqrestore(&qp->ntb_rx_q_lock, irqflags);
}
static void ntb_rx_copy_callback(void *data,
const struct dmaengine_result *res)
{
struct ntb_queue_entry *entry = data;
if (res) {
enum dmaengine_tx_result dma_err = res->result;
switch (dma_err) {
case DMA_TRANS_READ_FAILED:
case DMA_TRANS_WRITE_FAILED:
entry->errors++;
case DMA_TRANS_ABORTED:
{
struct ntb_transport_qp *qp = entry->qp;
void *offset = qp->rx_buff + qp->rx_max_frame *
qp->rx_index;
ntb_memcpy_rx(entry, offset);
qp->rx_memcpy++;
return;
}
case DMA_TRANS_NOERROR:
default:
break;
}
}
entry->flags |= DESC_DONE_FLAG;
ntb_complete_rxc(entry->qp);
}
static void ntb_memcpy_rx(struct ntb_queue_entry *entry, void *offset)
{
void *buf = entry->buf;
size_t len = entry->len;
memcpy(buf, offset, len);
wmb();
ntb_rx_copy_callback(entry, NULL);
}
static int ntb_async_rx_submit(struct ntb_queue_entry *entry, void *offset)
{
struct dma_async_tx_descriptor *txd;
struct ntb_transport_qp *qp = entry->qp;
struct dma_chan *chan = qp->rx_dma_chan;
struct dma_device *device;
size_t pay_off, buff_off, len;
struct dmaengine_unmap_data *unmap;
dma_cookie_t cookie;
void *buf = entry->buf;
len = entry->len;
device = chan->device;
pay_off = (size_t)offset & ~PAGE_MASK;
buff_off = (size_t)buf & ~PAGE_MASK;
if (!is_dma_copy_aligned(device, pay_off, buff_off, len))
goto err;
unmap = dmaengine_get_unmap_data(device->dev, 2, GFP_NOWAIT);
if (!unmap)
goto err;
unmap->len = len;
unmap->addr[0] = dma_map_page(device->dev, virt_to_page(offset),
pay_off, len, DMA_TO_DEVICE);
if (dma_mapping_error(device->dev, unmap->addr[0]))
goto err_get_unmap;
unmap->to_cnt = 1;
unmap->addr[1] = dma_map_page(device->dev, virt_to_page(buf),
buff_off, len, DMA_FROM_DEVICE);
if (dma_mapping_error(device->dev, unmap->addr[1]))
goto err_get_unmap;
unmap->from_cnt = 1;
txd = device->device_prep_dma_memcpy(chan, unmap->addr[1],
unmap->addr[0], len,
DMA_PREP_INTERRUPT);
if (!txd)
goto err_get_unmap;
txd->callback_result = ntb_rx_copy_callback;
txd->callback_param = entry;
dma_set_unmap(txd, unmap);
cookie = dmaengine_submit(txd);
if (dma_submit_error(cookie))
goto err_set_unmap;
dmaengine_unmap_put(unmap);
qp->last_cookie = cookie;
qp->rx_async++;
return 0;
err_set_unmap:
dmaengine_unmap_put(unmap);
err_get_unmap:
dmaengine_unmap_put(unmap);
err:
return -ENXIO;
}
static void ntb_async_rx(struct ntb_queue_entry *entry, void *offset)
{
struct ntb_transport_qp *qp = entry->qp;
struct dma_chan *chan = qp->rx_dma_chan;
int res;
if (!chan)
goto err;
if (entry->len < copy_bytes)
goto err;
res = ntb_async_rx_submit(entry, offset);
if (res < 0)
goto err;
if (!entry->retries)
qp->rx_async++;
return;
err:
ntb_memcpy_rx(entry, offset);
qp->rx_memcpy++;
}
static int ntb_process_rxc(struct ntb_transport_qp *qp)
{
struct ntb_payload_header *hdr;
struct ntb_queue_entry *entry;
void *offset;
offset = qp->rx_buff + qp->rx_max_frame * qp->rx_index;
hdr = offset + qp->rx_max_frame - sizeof(struct ntb_payload_header);
dev_dbg(&qp->ndev->pdev->dev, "qp %d: RX ver %u len %d flags %x\n",
qp->qp_num, hdr->ver, hdr->len, hdr->flags);
if (!(hdr->flags & DESC_DONE_FLAG)) {
dev_dbg(&qp->ndev->pdev->dev, "done flag not set\n");
qp->rx_ring_empty++;
return -EAGAIN;
}
if (hdr->flags & LINK_DOWN_FLAG) {
dev_dbg(&qp->ndev->pdev->dev, "link down flag set\n");
ntb_qp_link_down(qp);
hdr->flags = 0;
return -EAGAIN;
}
if (hdr->ver != (u32)qp->rx_pkts) {
dev_dbg(&qp->ndev->pdev->dev,
"version mismatch, expected %llu - got %u\n",
qp->rx_pkts, hdr->ver);
qp->rx_err_ver++;
return -EIO;
}
entry = ntb_list_mv(&qp->ntb_rx_q_lock, &qp->rx_pend_q, &qp->rx_post_q);
if (!entry) {
dev_dbg(&qp->ndev->pdev->dev, "no receive buffer\n");
qp->rx_err_no_buf++;
return -EAGAIN;
}
entry->rx_hdr = hdr;
entry->rx_index = qp->rx_index;
if (hdr->len > entry->len) {
dev_dbg(&qp->ndev->pdev->dev,
"receive buffer overflow! Wanted %d got %d\n",
hdr->len, entry->len);
qp->rx_err_oflow++;
entry->len = -EIO;
entry->flags |= DESC_DONE_FLAG;
ntb_complete_rxc(qp);
} else {
dev_dbg(&qp->ndev->pdev->dev,
"RX OK index %u ver %u size %d into buf size %d\n",
qp->rx_index, hdr->ver, hdr->len, entry->len);
qp->rx_bytes += hdr->len;
qp->rx_pkts++;
entry->len = hdr->len;
ntb_async_rx(entry, offset);
}
qp->rx_index++;
qp->rx_index %= qp->rx_max_entry;
return 0;
}
static void ntb_transport_rxc_db(unsigned long data)
{
struct ntb_transport_qp *qp = (void *)data;
int rc, i;
dev_dbg(&qp->ndev->pdev->dev, "%s: doorbell %d received\n",
__func__, qp->qp_num);
for (i = 0; i < qp->rx_max_entry; i++) {
rc = ntb_process_rxc(qp);
if (rc)
break;
}
if (i && qp->rx_dma_chan)
dma_async_issue_pending(qp->rx_dma_chan);
if (i == qp->rx_max_entry) {
if (qp->active)
tasklet_schedule(&qp->rxc_db_work);
} else if (ntb_db_read(qp->ndev) & BIT_ULL(qp->qp_num)) {
ntb_db_clear(qp->ndev, BIT_ULL(qp->qp_num));
ntb_db_read(qp->ndev);
if (qp->active)
tasklet_schedule(&qp->rxc_db_work);
}
}
static void ntb_tx_copy_callback(void *data,
const struct dmaengine_result *res)
{
struct ntb_queue_entry *entry = data;
struct ntb_transport_qp *qp = entry->qp;
struct ntb_payload_header __iomem *hdr = entry->tx_hdr;
if (res) {
enum dmaengine_tx_result dma_err = res->result;
switch (dma_err) {
case DMA_TRANS_READ_FAILED:
case DMA_TRANS_WRITE_FAILED:
entry->errors++;
case DMA_TRANS_ABORTED:
{
void __iomem *offset =
qp->tx_mw + qp->tx_max_frame *
entry->tx_index;
ntb_memcpy_tx(entry, offset);
qp->tx_memcpy++;
return;
}
case DMA_TRANS_NOERROR:
default:
break;
}
}
iowrite32(entry->flags | DESC_DONE_FLAG, &hdr->flags);
ntb_peer_db_set(qp->ndev, BIT_ULL(qp->qp_num));
if (entry->len > 0) {
qp->tx_bytes += entry->len;
if (qp->tx_handler)
qp->tx_handler(qp, qp->cb_data, entry->cb_data,
entry->len);
}
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry, &qp->tx_free_q);
}
static void ntb_memcpy_tx(struct ntb_queue_entry *entry, void __iomem *offset)
{
#ifdef ARCH_HAS_NOCACHE_UACCESS
__copy_from_user_inatomic_nocache(offset, entry->buf, entry->len);
#else
memcpy_toio(offset, entry->buf, entry->len);
#endif
wmb();
ntb_tx_copy_callback(entry, NULL);
}
static int ntb_async_tx_submit(struct ntb_transport_qp *qp,
struct ntb_queue_entry *entry)
{
struct dma_async_tx_descriptor *txd;
struct dma_chan *chan = qp->tx_dma_chan;
struct dma_device *device;
size_t len = entry->len;
void *buf = entry->buf;
size_t dest_off, buff_off;
struct dmaengine_unmap_data *unmap;
dma_addr_t dest;
dma_cookie_t cookie;
device = chan->device;
dest = qp->tx_mw_phys + qp->tx_max_frame * entry->tx_index;
buff_off = (size_t)buf & ~PAGE_MASK;
dest_off = (size_t)dest & ~PAGE_MASK;
if (!is_dma_copy_aligned(device, buff_off, dest_off, len))
goto err;
unmap = dmaengine_get_unmap_data(device->dev, 1, GFP_NOWAIT);
if (!unmap)
goto err;
unmap->len = len;
unmap->addr[0] = dma_map_page(device->dev, virt_to_page(buf),
buff_off, len, DMA_TO_DEVICE);
if (dma_mapping_error(device->dev, unmap->addr[0]))
goto err_get_unmap;
unmap->to_cnt = 1;
txd = device->device_prep_dma_memcpy(chan, dest, unmap->addr[0], len,
DMA_PREP_INTERRUPT);
if (!txd)
goto err_get_unmap;
txd->callback_result = ntb_tx_copy_callback;
txd->callback_param = entry;
dma_set_unmap(txd, unmap);
cookie = dmaengine_submit(txd);
if (dma_submit_error(cookie))
goto err_set_unmap;
dmaengine_unmap_put(unmap);
dma_async_issue_pending(chan);
return 0;
err_set_unmap:
dmaengine_unmap_put(unmap);
err_get_unmap:
dmaengine_unmap_put(unmap);
err:
return -ENXIO;
}
static void ntb_async_tx(struct ntb_transport_qp *qp,
struct ntb_queue_entry *entry)
{
struct ntb_payload_header __iomem *hdr;
struct dma_chan *chan = qp->tx_dma_chan;
void __iomem *offset;
int res;
entry->tx_index = qp->tx_index;
offset = qp->tx_mw + qp->tx_max_frame * entry->tx_index;
hdr = offset + qp->tx_max_frame - sizeof(struct ntb_payload_header);
entry->tx_hdr = hdr;
iowrite32(entry->len, &hdr->len);
iowrite32((u32)qp->tx_pkts, &hdr->ver);
if (!chan)
goto err;
if (entry->len < copy_bytes)
goto err;
res = ntb_async_tx_submit(qp, entry);
if (res < 0)
goto err;
if (!entry->retries)
qp->tx_async++;
return;
err:
ntb_memcpy_tx(entry, offset);
qp->tx_memcpy++;
}
static int ntb_process_tx(struct ntb_transport_qp *qp,
struct ntb_queue_entry *entry)
{
if (qp->tx_index == qp->remote_rx_info->entry) {
qp->tx_ring_full++;
return -EAGAIN;
}
if (entry->len > qp->tx_max_frame - sizeof(struct ntb_payload_header)) {
if (qp->tx_handler)
qp->tx_handler(qp, qp->cb_data, NULL, -EIO);
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry,
&qp->tx_free_q);
return 0;
}
ntb_async_tx(qp, entry);
qp->tx_index++;
qp->tx_index %= qp->tx_max_entry;
qp->tx_pkts++;
return 0;
}
static void ntb_send_link_down(struct ntb_transport_qp *qp)
{
struct pci_dev *pdev = qp->ndev->pdev;
struct ntb_queue_entry *entry;
int i, rc;
if (!qp->link_is_up)
return;
dev_info(&pdev->dev, "qp %d: Send Link Down\n", qp->qp_num);
for (i = 0; i < NTB_LINK_DOWN_TIMEOUT; i++) {
entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q);
if (entry)
break;
msleep(100);
}
if (!entry)
return;
entry->cb_data = NULL;
entry->buf = NULL;
entry->len = 0;
entry->flags = LINK_DOWN_FLAG;
rc = ntb_process_tx(qp, entry);
if (rc)
dev_err(&pdev->dev, "ntb: QP%d unable to send linkdown msg\n",
qp->qp_num);
ntb_qp_link_down_reset(qp);
}
static bool ntb_dma_filter_fn(struct dma_chan *chan, void *node)
{
return dev_to_node(&chan->dev->device) == (int)(unsigned long)node;
}
struct ntb_transport_qp *
ntb_transport_create_queue(void *data, struct device *client_dev,
const struct ntb_queue_handlers *handlers)
{
struct ntb_dev *ndev;
struct pci_dev *pdev;
struct ntb_transport_ctx *nt;
struct ntb_queue_entry *entry;
struct ntb_transport_qp *qp;
u64 qp_bit;
unsigned int free_queue;
dma_cap_mask_t dma_mask;
int node;
int i;
ndev = dev_ntb(client_dev->parent);
pdev = ndev->pdev;
nt = ndev->ctx;
node = dev_to_node(&ndev->dev);
free_queue = ffs(nt->qp_bitmap_free);
if (!free_queue)
goto err;
free_queue--;
qp = &nt->qp_vec[free_queue];
qp_bit = BIT_ULL(qp->qp_num);
nt->qp_bitmap_free &= ~qp_bit;
qp->cb_data = data;
qp->rx_handler = handlers->rx_handler;
qp->tx_handler = handlers->tx_handler;
qp->event_handler = handlers->event_handler;
dma_cap_zero(dma_mask);
dma_cap_set(DMA_MEMCPY, dma_mask);
if (use_dma) {
qp->tx_dma_chan =
dma_request_channel(dma_mask, ntb_dma_filter_fn,
(void *)(unsigned long)node);
if (!qp->tx_dma_chan)
dev_info(&pdev->dev, "Unable to allocate TX DMA channel\n");
qp->rx_dma_chan =
dma_request_channel(dma_mask, ntb_dma_filter_fn,
(void *)(unsigned long)node);
if (!qp->rx_dma_chan)
dev_info(&pdev->dev, "Unable to allocate RX DMA channel\n");
} else {
qp->tx_dma_chan = NULL;
qp->rx_dma_chan = NULL;
}
dev_dbg(&pdev->dev, "Using %s memcpy for TX\n",
qp->tx_dma_chan ? "DMA" : "CPU");
dev_dbg(&pdev->dev, "Using %s memcpy for RX\n",
qp->rx_dma_chan ? "DMA" : "CPU");
for (i = 0; i < NTB_QP_DEF_NUM_ENTRIES; i++) {
entry = kzalloc_node(sizeof(*entry), GFP_ATOMIC, node);
if (!entry)
goto err1;
entry->qp = qp;
ntb_list_add(&qp->ntb_rx_q_lock, &entry->entry,
&qp->rx_free_q);
}
qp->rx_alloc_entry = NTB_QP_DEF_NUM_ENTRIES;
for (i = 0; i < qp->tx_max_entry; i++) {
entry = kzalloc_node(sizeof(*entry), GFP_ATOMIC, node);
if (!entry)
goto err2;
entry->qp = qp;
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry,
&qp->tx_free_q);
}
ntb_db_clear(qp->ndev, qp_bit);
ntb_db_clear_mask(qp->ndev, qp_bit);
dev_info(&pdev->dev, "NTB Transport QP %d created\n", qp->qp_num);
return qp;
err2:
while ((entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q)))
kfree(entry);
err1:
qp->rx_alloc_entry = 0;
while ((entry = ntb_list_rm(&qp->ntb_rx_q_lock, &qp->rx_free_q)))
kfree(entry);
if (qp->tx_dma_chan)
dma_release_channel(qp->tx_dma_chan);
if (qp->rx_dma_chan)
dma_release_channel(qp->rx_dma_chan);
nt->qp_bitmap_free |= qp_bit;
err:
return NULL;
}
void ntb_transport_free_queue(struct ntb_transport_qp *qp)
{
struct pci_dev *pdev;
struct ntb_queue_entry *entry;
u64 qp_bit;
if (!qp)
return;
pdev = qp->ndev->pdev;
qp->active = false;
if (qp->tx_dma_chan) {
struct dma_chan *chan = qp->tx_dma_chan;
qp->tx_dma_chan = NULL;
dma_sync_wait(chan, qp->last_cookie);
dmaengine_terminate_all(chan);
dma_release_channel(chan);
}
if (qp->rx_dma_chan) {
struct dma_chan *chan = qp->rx_dma_chan;
qp->rx_dma_chan = NULL;
dma_sync_wait(chan, qp->last_cookie);
dmaengine_terminate_all(chan);
dma_release_channel(chan);
}
qp_bit = BIT_ULL(qp->qp_num);
ntb_db_set_mask(qp->ndev, qp_bit);
tasklet_kill(&qp->rxc_db_work);
cancel_delayed_work_sync(&qp->link_work);
qp->cb_data = NULL;
qp->rx_handler = NULL;
qp->tx_handler = NULL;
qp->event_handler = NULL;
while ((entry = ntb_list_rm(&qp->ntb_rx_q_lock, &qp->rx_free_q)))
kfree(entry);
while ((entry = ntb_list_rm(&qp->ntb_rx_q_lock, &qp->rx_pend_q))) {
dev_warn(&pdev->dev, "Freeing item from non-empty rx_pend_q\n");
kfree(entry);
}
while ((entry = ntb_list_rm(&qp->ntb_rx_q_lock, &qp->rx_post_q))) {
dev_warn(&pdev->dev, "Freeing item from non-empty rx_post_q\n");
kfree(entry);
}
while ((entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q)))
kfree(entry);
qp->transport->qp_bitmap_free |= qp_bit;
dev_info(&pdev->dev, "NTB Transport QP %d freed\n", qp->qp_num);
}
void *ntb_transport_rx_remove(struct ntb_transport_qp *qp, unsigned int *len)
{
struct ntb_queue_entry *entry;
void *buf;
if (!qp || qp->client_ready)
return NULL;
entry = ntb_list_rm(&qp->ntb_rx_q_lock, &qp->rx_pend_q);
if (!entry)
return NULL;
buf = entry->cb_data;
*len = entry->len;
ntb_list_add(&qp->ntb_rx_q_lock, &entry->entry, &qp->rx_free_q);
return buf;
}
int ntb_transport_rx_enqueue(struct ntb_transport_qp *qp, void *cb, void *data,
unsigned int len)
{
struct ntb_queue_entry *entry;
if (!qp)
return -EINVAL;
entry = ntb_list_rm(&qp->ntb_rx_q_lock, &qp->rx_free_q);
if (!entry)
return -ENOMEM;
entry->cb_data = cb;
entry->buf = data;
entry->len = len;
entry->flags = 0;
entry->retries = 0;
entry->errors = 0;
entry->rx_index = 0;
ntb_list_add(&qp->ntb_rx_q_lock, &entry->entry, &qp->rx_pend_q);
if (qp->active)
tasklet_schedule(&qp->rxc_db_work);
return 0;
}
int ntb_transport_tx_enqueue(struct ntb_transport_qp *qp, void *cb, void *data,
unsigned int len)
{
struct ntb_queue_entry *entry;
int rc;
if (!qp || !qp->link_is_up || !len)
return -EINVAL;
entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q);
if (!entry) {
qp->tx_err_no_buf++;
return -EBUSY;
}
entry->cb_data = cb;
entry->buf = data;
entry->len = len;
entry->flags = 0;
entry->errors = 0;
entry->retries = 0;
entry->tx_index = 0;
rc = ntb_process_tx(qp, entry);
if (rc)
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry,
&qp->tx_free_q);
return rc;
}
void ntb_transport_link_up(struct ntb_transport_qp *qp)
{
if (!qp)
return;
qp->client_ready = true;
if (qp->transport->link_is_up)
schedule_delayed_work(&qp->link_work, 0);
}
void ntb_transport_link_down(struct ntb_transport_qp *qp)
{
int val;
if (!qp)
return;
qp->client_ready = false;
val = ntb_spad_read(qp->ndev, QP_LINKS);
ntb_peer_spad_write(qp->ndev, PIDX, QP_LINKS, val & ~BIT(qp->qp_num));
if (qp->link_is_up)
ntb_send_link_down(qp);
else
cancel_delayed_work_sync(&qp->link_work);
}
bool ntb_transport_link_query(struct ntb_transport_qp *qp)
{
if (!qp)
return false;
return qp->link_is_up;
}
unsigned char ntb_transport_qp_num(struct ntb_transport_qp *qp)
{
if (!qp)
return 0;
return qp->qp_num;
}
unsigned int ntb_transport_max_size(struct ntb_transport_qp *qp)
{
unsigned int max_size;
unsigned int copy_align;
struct dma_chan *rx_chan, *tx_chan;
if (!qp)
return 0;
rx_chan = qp->rx_dma_chan;
tx_chan = qp->tx_dma_chan;
copy_align = max(rx_chan ? rx_chan->device->copy_align : 0,
tx_chan ? tx_chan->device->copy_align : 0);
max_size = qp->tx_max_frame - sizeof(struct ntb_payload_header);
max_size = round_down(max_size, 1 << copy_align);
return max_size;
}
unsigned int ntb_transport_tx_free_entry(struct ntb_transport_qp *qp)
{
unsigned int head = qp->tx_index;
unsigned int tail = qp->remote_rx_info->entry;
return tail > head ? tail - head : qp->tx_max_entry + tail - head;
}
static void ntb_transport_doorbell_callback(void *data, int vector)
{
struct ntb_transport_ctx *nt = data;
struct ntb_transport_qp *qp;
u64 db_bits;
unsigned int qp_num;
db_bits = (nt->qp_bitmap & ~nt->qp_bitmap_free &
ntb_db_vector_mask(nt->ndev, vector));
while (db_bits) {
qp_num = __ffs(db_bits);
qp = &nt->qp_vec[qp_num];
if (qp->active)
tasklet_schedule(&qp->rxc_db_work);
db_bits &= ~BIT_ULL(qp_num);
}
}
static int __init ntb_transport_init(void)
{
int rc;
pr_info("%s, version %s\n", NTB_TRANSPORT_DESC, NTB_TRANSPORT_VER);
if (debugfs_initialized())
nt_debugfs_dir = debugfs_create_dir(KBUILD_MODNAME, NULL);
rc = bus_register(&ntb_transport_bus);
if (rc)
goto err_bus;
rc = ntb_register_client(&ntb_transport_client);
if (rc)
goto err_client;
return 0;
err_client:
bus_unregister(&ntb_transport_bus);
err_bus:
debugfs_remove_recursive(nt_debugfs_dir);
return rc;
}
static void __exit ntb_transport_exit(void)
{
ntb_unregister_client(&ntb_transport_client);
bus_unregister(&ntb_transport_bus);
debugfs_remove_recursive(nt_debugfs_dir);
}
