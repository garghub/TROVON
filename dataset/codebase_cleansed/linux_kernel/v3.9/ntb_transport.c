static int ntb_match_bus(struct device *dev, struct device_driver *drv)
{
return !strncmp(dev_name(dev), drv->name, strlen(drv->name));
}
static int ntb_client_probe(struct device *dev)
{
const struct ntb_client *drv = container_of(dev->driver,
struct ntb_client, driver);
struct pci_dev *pdev = container_of(dev->parent, struct pci_dev, dev);
int rc = -EINVAL;
get_device(dev);
if (drv && drv->probe)
rc = drv->probe(pdev);
if (rc)
put_device(dev);
return rc;
}
static int ntb_client_remove(struct device *dev)
{
const struct ntb_client *drv = container_of(dev->driver,
struct ntb_client, driver);
struct pci_dev *pdev = container_of(dev->parent, struct pci_dev, dev);
if (drv && drv->remove)
drv->remove(pdev);
put_device(dev);
return 0;
}
static int ntb_bus_init(struct ntb_transport *nt)
{
if (list_empty(&ntb_transport_list)) {
int rc = bus_register(&ntb_bus_type);
if (rc)
return rc;
}
list_add(&nt->entry, &ntb_transport_list);
return 0;
}
static void ntb_bus_remove(struct ntb_transport *nt)
{
struct ntb_transport_client_dev *client_dev, *cd;
list_for_each_entry_safe(client_dev, cd, &nt->client_devs, entry) {
dev_err(client_dev->dev.parent, "%s still attached to bus, removing\n",
dev_name(&client_dev->dev));
list_del(&client_dev->entry);
device_unregister(&client_dev->dev);
}
list_del(&nt->entry);
if (list_empty(&ntb_transport_list))
bus_unregister(&ntb_bus_type);
}
static void ntb_client_release(struct device *dev)
{
struct ntb_transport_client_dev *client_dev;
client_dev = container_of(dev, struct ntb_transport_client_dev, dev);
kfree(client_dev);
}
void ntb_unregister_client_dev(char *device_name)
{
struct ntb_transport_client_dev *client, *cd;
struct ntb_transport *nt;
list_for_each_entry(nt, &ntb_transport_list, entry)
list_for_each_entry_safe(client, cd, &nt->client_devs, entry)
if (!strncmp(dev_name(&client->dev), device_name,
strlen(device_name))) {
list_del(&client->entry);
device_unregister(&client->dev);
}
}
int ntb_register_client_dev(char *device_name)
{
struct ntb_transport_client_dev *client_dev;
struct ntb_transport *nt;
int rc;
if (list_empty(&ntb_transport_list))
return -ENODEV;
list_for_each_entry(nt, &ntb_transport_list, entry) {
struct device *dev;
client_dev = kzalloc(sizeof(struct ntb_transport_client_dev),
GFP_KERNEL);
if (!client_dev) {
rc = -ENOMEM;
goto err;
}
dev = &client_dev->dev;
dev_set_name(dev, "%s", device_name);
dev->bus = &ntb_bus_type;
dev->release = ntb_client_release;
dev->parent = &ntb_query_pdev(nt->ndev)->dev;
rc = device_register(dev);
if (rc) {
kfree(client_dev);
goto err;
}
list_add_tail(&client_dev->entry, &nt->client_devs);
}
return 0;
err:
ntb_unregister_client_dev(device_name);
return rc;
}
int ntb_register_client(struct ntb_client *drv)
{
drv->driver.bus = &ntb_bus_type;
if (list_empty(&ntb_transport_list))
return -ENODEV;
return driver_register(&drv->driver);
}
void ntb_unregister_client(struct ntb_client *drv)
{
driver_unregister(&drv->driver);
}
static ssize_t debugfs_read(struct file *filp, char __user *ubuf, size_t count,
loff_t *offp)
{
struct ntb_transport_qp *qp;
char *buf;
ssize_t ret, out_offset, out_count;
out_count = 600;
buf = kmalloc(out_count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
qp = filp->private_data;
out_offset = 0;
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"NTB QP stats\n");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_bytes - \t%llu\n", qp->rx_bytes);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_pkts - \t%llu\n", qp->rx_pkts);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_ring_empty - %llu\n", qp->rx_ring_empty);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_err_no_buf - %llu\n", qp->rx_err_no_buf);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_err_oflow - \t%llu\n", qp->rx_err_oflow);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_err_ver - \t%llu\n", qp->rx_err_ver);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_buff - \t%p\n", qp->rx_buff);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_index - \t%u\n", qp->rx_index);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"rx_max_entry - \t%u\n", qp->rx_max_entry);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_bytes - \t%llu\n", qp->tx_bytes);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_pkts - \t%llu\n", qp->tx_pkts);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_ring_full - \t%llu\n", qp->tx_ring_full);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_mw - \t%p\n", qp->tx_mw);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_index - \t%u\n", qp->tx_index);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"tx_max_entry - \t%u\n", qp->tx_max_entry);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"\nQP Link %s\n", (qp->qp_link == NTB_LINK_UP) ?
"Up" : "Down");
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
static void ntb_transport_setup_qp_mw(struct ntb_transport *nt,
unsigned int qp_num)
{
struct ntb_transport_qp *qp = &nt->qps[qp_num];
unsigned int rx_size, num_qps_mw;
u8 mw_num = QP_TO_MW(qp_num);
unsigned int i;
WARN_ON(nt->mw[mw_num].virt_addr == NULL);
if (nt->max_qps % NTB_NUM_MW && mw_num < nt->max_qps % NTB_NUM_MW)
num_qps_mw = nt->max_qps / NTB_NUM_MW + 1;
else
num_qps_mw = nt->max_qps / NTB_NUM_MW;
rx_size = (unsigned int) nt->mw[mw_num].size / num_qps_mw;
qp->remote_rx_info = nt->mw[mw_num].virt_addr +
(qp_num / NTB_NUM_MW * rx_size);
rx_size -= sizeof(struct ntb_rx_info);
qp->rx_buff = qp->remote_rx_info + sizeof(struct ntb_rx_info);
qp->rx_max_frame = min(transport_mtu, rx_size);
qp->rx_max_entry = rx_size / qp->rx_max_frame;
qp->rx_index = 0;
qp->remote_rx_info->entry = qp->rx_max_entry;
for (i = 0; i < qp->rx_max_entry; i++) {
void *offset = qp->rx_buff + qp->rx_max_frame * (i + 1) -
sizeof(struct ntb_payload_header);
memset(offset, 0, sizeof(struct ntb_payload_header));
}
qp->rx_pkts = 0;
qp->tx_pkts = 0;
}
static int ntb_set_mw(struct ntb_transport *nt, int num_mw, unsigned int size)
{
struct ntb_transport_mw *mw = &nt->mw[num_mw];
struct pci_dev *pdev = ntb_query_pdev(nt->ndev);
mw->size = ALIGN(size, 4096);
mw->virt_addr = dma_alloc_coherent(&pdev->dev, mw->size, &mw->dma_addr,
GFP_KERNEL);
if (!mw->virt_addr) {
dev_err(&pdev->dev, "Unable to allocate MW buffer of size %d\n",
(int) mw->size);
return -ENOMEM;
}
ntb_set_mw_addr(nt->ndev, num_mw, mw->dma_addr);
return 0;
}
static void ntb_qp_link_cleanup(struct work_struct *work)
{
struct ntb_transport_qp *qp = container_of(work,
struct ntb_transport_qp,
link_cleanup);
struct ntb_transport *nt = qp->transport;
struct pci_dev *pdev = ntb_query_pdev(nt->ndev);
if (qp->qp_link == NTB_LINK_DOWN) {
cancel_delayed_work_sync(&qp->link_work);
return;
}
if (qp->event_handler)
qp->event_handler(qp->cb_data, NTB_LINK_DOWN);
dev_info(&pdev->dev, "qp %d: Link Down\n", qp->qp_num);
qp->qp_link = NTB_LINK_DOWN;
if (nt->transport_link == NTB_LINK_UP)
schedule_delayed_work(&qp->link_work,
msecs_to_jiffies(NTB_LINK_DOWN_TIMEOUT));
}
static void ntb_qp_link_down(struct ntb_transport_qp *qp)
{
schedule_work(&qp->link_cleanup);
}
static void ntb_transport_link_cleanup(struct work_struct *work)
{
struct ntb_transport *nt = container_of(work, struct ntb_transport,
link_cleanup);
int i;
if (nt->transport_link == NTB_LINK_DOWN)
cancel_delayed_work_sync(&nt->link_work);
else
nt->transport_link = NTB_LINK_DOWN;
for (i = 0; i < nt->max_qps; i++)
if (!test_bit(i, &nt->qp_bitmap))
ntb_qp_link_down(&nt->qps[i]);
for (i = 0; i < MAX_SPAD; i++)
ntb_write_local_spad(nt->ndev, i, 0);
}
static void ntb_transport_event_callback(void *data, enum ntb_hw_event event)
{
struct ntb_transport *nt = data;
switch (event) {
case NTB_EVENT_HW_LINK_UP:
schedule_delayed_work(&nt->link_work, 0);
break;
case NTB_EVENT_HW_LINK_DOWN:
schedule_work(&nt->link_cleanup);
break;
default:
BUG();
}
}
static void ntb_transport_link_work(struct work_struct *work)
{
struct ntb_transport *nt = container_of(work, struct ntb_transport,
link_work.work);
struct ntb_device *ndev = nt->ndev;
struct pci_dev *pdev = ntb_query_pdev(ndev);
u32 val;
int rc, i;
rc = ntb_write_remote_spad(ndev, VERSION, NTB_TRANSPORT_VERSION);
if (rc) {
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
0, VERSION);
goto out;
}
rc = ntb_write_remote_spad(ndev, MW0_SZ, ntb_get_mw_size(ndev, 0));
if (rc) {
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
(u32) ntb_get_mw_size(ndev, 0), MW0_SZ);
goto out;
}
rc = ntb_write_remote_spad(ndev, MW1_SZ, ntb_get_mw_size(ndev, 1));
if (rc) {
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
(u32) ntb_get_mw_size(ndev, 1), MW1_SZ);
goto out;
}
rc = ntb_write_remote_spad(ndev, NUM_QPS, nt->max_qps);
if (rc) {
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
nt->max_qps, NUM_QPS);
goto out;
}
rc = ntb_read_local_spad(nt->ndev, QP_LINKS, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading spad %d\n", QP_LINKS);
goto out;
}
rc = ntb_write_remote_spad(ndev, QP_LINKS, val);
if (rc) {
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
val, QP_LINKS);
goto out;
}
rc = ntb_read_remote_spad(ndev, VERSION, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading remote spad %d\n", VERSION);
goto out;
}
if (val != NTB_TRANSPORT_VERSION)
goto out;
dev_dbg(&pdev->dev, "Remote version = %d\n", val);
rc = ntb_read_remote_spad(ndev, NUM_QPS, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading remote spad %d\n", NUM_QPS);
goto out;
}
if (val != nt->max_qps)
goto out;
dev_dbg(&pdev->dev, "Remote max number of qps = %d\n", val);
rc = ntb_read_remote_spad(ndev, MW0_SZ, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading remote spad %d\n", MW0_SZ);
goto out;
}
if (!val)
goto out;
dev_dbg(&pdev->dev, "Remote MW0 size = %d\n", val);
rc = ntb_set_mw(nt, 0, val);
if (rc)
goto out;
rc = ntb_read_remote_spad(ndev, MW1_SZ, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading remote spad %d\n", MW1_SZ);
goto out;
}
if (!val)
goto out;
dev_dbg(&pdev->dev, "Remote MW1 size = %d\n", val);
rc = ntb_set_mw(nt, 1, val);
if (rc)
goto out;
nt->transport_link = NTB_LINK_UP;
for (i = 0; i < nt->max_qps; i++) {
struct ntb_transport_qp *qp = &nt->qps[i];
ntb_transport_setup_qp_mw(nt, i);
if (qp->client_ready == NTB_LINK_UP)
schedule_delayed_work(&qp->link_work, 0);
}
return;
out:
if (ntb_hw_link_status(ndev))
schedule_delayed_work(&nt->link_work,
msecs_to_jiffies(NTB_LINK_DOWN_TIMEOUT));
}
static void ntb_qp_link_work(struct work_struct *work)
{
struct ntb_transport_qp *qp = container_of(work,
struct ntb_transport_qp,
link_work.work);
struct pci_dev *pdev = ntb_query_pdev(qp->ndev);
struct ntb_transport *nt = qp->transport;
int rc, val;
WARN_ON(nt->transport_link != NTB_LINK_UP);
rc = ntb_read_local_spad(nt->ndev, QP_LINKS, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading spad %d\n", QP_LINKS);
return;
}
rc = ntb_write_remote_spad(nt->ndev, QP_LINKS, val | 1 << qp->qp_num);
if (rc)
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
val | 1 << qp->qp_num, QP_LINKS);
rc = ntb_read_remote_spad(nt->ndev, QP_LINKS, &val);
if (rc)
dev_err(&pdev->dev, "Error reading remote spad %d\n", QP_LINKS);
dev_dbg(&pdev->dev, "Remote QP link status = %x\n", val);
if (1 << qp->qp_num & val) {
qp->qp_link = NTB_LINK_UP;
dev_info(&pdev->dev, "qp %d: Link Up\n", qp->qp_num);
if (qp->event_handler)
qp->event_handler(qp->cb_data, NTB_LINK_UP);
} else if (nt->transport_link == NTB_LINK_UP)
schedule_delayed_work(&qp->link_work,
msecs_to_jiffies(NTB_LINK_DOWN_TIMEOUT));
}
static void ntb_transport_init_queue(struct ntb_transport *nt,
unsigned int qp_num)
{
struct ntb_transport_qp *qp;
unsigned int num_qps_mw, tx_size;
u8 mw_num = QP_TO_MW(qp_num);
qp = &nt->qps[qp_num];
qp->qp_num = qp_num;
qp->transport = nt;
qp->ndev = nt->ndev;
qp->qp_link = NTB_LINK_DOWN;
qp->client_ready = NTB_LINK_DOWN;
qp->event_handler = NULL;
if (nt->max_qps % NTB_NUM_MW && mw_num < nt->max_qps % NTB_NUM_MW)
num_qps_mw = nt->max_qps / NTB_NUM_MW + 1;
else
num_qps_mw = nt->max_qps / NTB_NUM_MW;
tx_size = (unsigned int) ntb_get_mw_size(qp->ndev, mw_num) / num_qps_mw;
qp->rx_info = ntb_get_mw_vbase(nt->ndev, mw_num) +
(qp_num / NTB_NUM_MW * tx_size);
tx_size -= sizeof(struct ntb_rx_info);
qp->tx_mw = qp->rx_info + sizeof(struct ntb_rx_info);
qp->tx_max_frame = min(transport_mtu, tx_size);
qp->tx_max_entry = tx_size / qp->tx_max_frame;
qp->tx_index = 0;
if (nt->debugfs_dir) {
char debugfs_name[4];
snprintf(debugfs_name, 4, "qp%d", qp_num);
qp->debugfs_dir = debugfs_create_dir(debugfs_name,
nt->debugfs_dir);
qp->debugfs_stats = debugfs_create_file("stats", S_IRUSR,
qp->debugfs_dir, qp,
&ntb_qp_debugfs_stats);
}
INIT_DELAYED_WORK(&qp->link_work, ntb_qp_link_work);
INIT_WORK(&qp->link_cleanup, ntb_qp_link_cleanup);
spin_lock_init(&qp->ntb_rx_pend_q_lock);
spin_lock_init(&qp->ntb_rx_free_q_lock);
spin_lock_init(&qp->ntb_tx_free_q_lock);
INIT_LIST_HEAD(&qp->rx_pend_q);
INIT_LIST_HEAD(&qp->rx_free_q);
INIT_LIST_HEAD(&qp->tx_free_q);
}
int ntb_transport_init(struct pci_dev *pdev)
{
struct ntb_transport *nt;
int rc, i;
nt = kzalloc(sizeof(struct ntb_transport), GFP_KERNEL);
if (!nt)
return -ENOMEM;
if (debugfs_initialized())
nt->debugfs_dir = debugfs_create_dir(KBUILD_MODNAME, NULL);
else
nt->debugfs_dir = NULL;
nt->ndev = ntb_register_transport(pdev, nt);
if (!nt->ndev) {
rc = -EIO;
goto err;
}
nt->max_qps = min(nt->ndev->max_cbs, max_num_clients);
nt->qps = kcalloc(nt->max_qps, sizeof(struct ntb_transport_qp),
GFP_KERNEL);
if (!nt->qps) {
rc = -ENOMEM;
goto err1;
}
nt->qp_bitmap = ((u64) 1 << nt->max_qps) - 1;
for (i = 0; i < nt->max_qps; i++)
ntb_transport_init_queue(nt, i);
INIT_DELAYED_WORK(&nt->link_work, ntb_transport_link_work);
INIT_WORK(&nt->link_cleanup, ntb_transport_link_cleanup);
rc = ntb_register_event_callback(nt->ndev,
ntb_transport_event_callback);
if (rc)
goto err2;
INIT_LIST_HEAD(&nt->client_devs);
rc = ntb_bus_init(nt);
if (rc)
goto err3;
if (ntb_hw_link_status(nt->ndev))
schedule_delayed_work(&nt->link_work, 0);
return 0;
err3:
ntb_unregister_event_callback(nt->ndev);
err2:
kfree(nt->qps);
err1:
ntb_unregister_transport(nt->ndev);
err:
debugfs_remove_recursive(nt->debugfs_dir);
kfree(nt);
return rc;
}
void ntb_transport_free(void *transport)
{
struct ntb_transport *nt = transport;
struct pci_dev *pdev;
int i;
nt->transport_link = NTB_LINK_DOWN;
for (i = 0; i < nt->max_qps; i++)
if (!test_bit(i, &nt->qp_bitmap))
ntb_transport_free_queue(&nt->qps[i]);
ntb_bus_remove(nt);
cancel_delayed_work_sync(&nt->link_work);
debugfs_remove_recursive(nt->debugfs_dir);
ntb_unregister_event_callback(nt->ndev);
pdev = ntb_query_pdev(nt->ndev);
for (i = 0; i < NTB_NUM_MW; i++)
if (nt->mw[i].virt_addr)
dma_free_coherent(&pdev->dev, nt->mw[i].size,
nt->mw[i].virt_addr,
nt->mw[i].dma_addr);
kfree(nt->qps);
ntb_unregister_transport(nt->ndev);
kfree(nt);
}
static void ntb_rx_copy_task(struct ntb_transport_qp *qp,
struct ntb_queue_entry *entry, void *offset)
{
void *cb_data = entry->cb_data;
unsigned int len = entry->len;
memcpy(entry->buf, offset, entry->len);
ntb_list_add(&qp->ntb_rx_free_q_lock, &entry->entry, &qp->rx_free_q);
if (qp->rx_handler && qp->client_ready == NTB_LINK_UP)
qp->rx_handler(qp, qp->cb_data, cb_data, len);
}
static int ntb_process_rxc(struct ntb_transport_qp *qp)
{
struct ntb_payload_header *hdr;
struct ntb_queue_entry *entry;
void *offset;
offset = qp->rx_buff + qp->rx_max_frame * qp->rx_index;
hdr = offset + qp->rx_max_frame - sizeof(struct ntb_payload_header);
entry = ntb_list_rm(&qp->ntb_rx_pend_q_lock, &qp->rx_pend_q);
if (!entry) {
dev_dbg(&ntb_query_pdev(qp->ndev)->dev,
"no buffer - HDR ver %u, len %d, flags %x\n",
hdr->ver, hdr->len, hdr->flags);
qp->rx_err_no_buf++;
return -ENOMEM;
}
if (!(hdr->flags & DESC_DONE_FLAG)) {
ntb_list_add(&qp->ntb_rx_pend_q_lock, &entry->entry,
&qp->rx_pend_q);
qp->rx_ring_empty++;
return -EAGAIN;
}
if (hdr->ver != (u32) qp->rx_pkts) {
dev_dbg(&ntb_query_pdev(qp->ndev)->dev,
"qp %d: version mismatch, expected %llu - got %u\n",
qp->qp_num, qp->rx_pkts, hdr->ver);
ntb_list_add(&qp->ntb_rx_pend_q_lock, &entry->entry,
&qp->rx_pend_q);
qp->rx_err_ver++;
return -EIO;
}
if (hdr->flags & LINK_DOWN_FLAG) {
ntb_qp_link_down(qp);
ntb_list_add(&qp->ntb_rx_pend_q_lock, &entry->entry,
&qp->rx_pend_q);
goto out;
}
dev_dbg(&ntb_query_pdev(qp->ndev)->dev,
"rx offset %u, ver %u - %d payload received, buf size %d\n",
qp->rx_index, hdr->ver, hdr->len, entry->len);
if (hdr->len <= entry->len) {
entry->len = hdr->len;
ntb_rx_copy_task(qp, entry, offset);
} else {
ntb_list_add(&qp->ntb_rx_pend_q_lock, &entry->entry,
&qp->rx_pend_q);
qp->rx_err_oflow++;
dev_dbg(&ntb_query_pdev(qp->ndev)->dev,
"RX overflow! Wanted %d got %d\n",
hdr->len, entry->len);
}
qp->rx_bytes += hdr->len;
qp->rx_pkts++;
out:
wmb();
hdr->flags = 0;
iowrite32(qp->rx_index, &qp->rx_info->entry);
qp->rx_index++;
qp->rx_index %= qp->rx_max_entry;
return 0;
}
static void ntb_transport_rx(unsigned long data)
{
struct ntb_transport_qp *qp = (struct ntb_transport_qp *)data;
int rc;
do {
rc = ntb_process_rxc(qp);
} while (!rc);
}
static void ntb_transport_rxc_db(void *data, int db_num)
{
struct ntb_transport_qp *qp = data;
dev_dbg(&ntb_query_pdev(qp->ndev)->dev, "%s: doorbell %d received\n",
__func__, db_num);
tasklet_schedule(&qp->rx_work);
}
static void ntb_tx_copy_task(struct ntb_transport_qp *qp,
struct ntb_queue_entry *entry,
void __iomem *offset)
{
struct ntb_payload_header __iomem *hdr;
memcpy_toio(offset, entry->buf, entry->len);
hdr = offset + qp->tx_max_frame - sizeof(struct ntb_payload_header);
iowrite32(entry->len, &hdr->len);
iowrite32((u32) qp->tx_pkts, &hdr->ver);
wmb();
iowrite32(entry->flags | DESC_DONE_FLAG, &hdr->flags);
ntb_ring_sdb(qp->ndev, qp->qp_num);
if (entry->len > 0) {
qp->tx_bytes += entry->len;
if (qp->tx_handler)
qp->tx_handler(qp, qp->cb_data, entry->cb_data,
entry->len);
}
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry, &qp->tx_free_q);
}
static int ntb_process_tx(struct ntb_transport_qp *qp,
struct ntb_queue_entry *entry)
{
void __iomem *offset;
offset = qp->tx_mw + qp->tx_max_frame * qp->tx_index;
dev_dbg(&ntb_query_pdev(qp->ndev)->dev, "%lld - offset %p, tx %u, entry len %d flags %x buff %p\n",
qp->tx_pkts, offset, qp->tx_index, entry->len, entry->flags,
entry->buf);
if (qp->tx_index == qp->remote_rx_info->entry) {
qp->tx_ring_full++;
return -EAGAIN;
}
if (entry->len > qp->tx_max_frame - sizeof(struct ntb_payload_header)) {
if (qp->tx_handler)
qp->tx_handler(qp->cb_data, qp, NULL, -EIO);
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry,
&qp->tx_free_q);
return 0;
}
ntb_tx_copy_task(qp, entry, offset);
qp->tx_index++;
qp->tx_index %= qp->tx_max_entry;
qp->tx_pkts++;
return 0;
}
static void ntb_send_link_down(struct ntb_transport_qp *qp)
{
struct pci_dev *pdev = ntb_query_pdev(qp->ndev);
struct ntb_queue_entry *entry;
int i, rc;
if (qp->qp_link == NTB_LINK_DOWN)
return;
qp->qp_link = NTB_LINK_DOWN;
dev_info(&pdev->dev, "qp %d: Link Down\n", qp->qp_num);
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
}
struct ntb_transport_qp *
ntb_transport_create_queue(void *data, struct pci_dev *pdev,
const struct ntb_queue_handlers *handlers)
{
struct ntb_queue_entry *entry;
struct ntb_transport_qp *qp;
struct ntb_transport *nt;
unsigned int free_queue;
int rc, i;
nt = ntb_find_transport(pdev);
if (!nt)
goto err;
free_queue = ffs(nt->qp_bitmap);
if (!free_queue)
goto err;
free_queue--;
clear_bit(free_queue, &nt->qp_bitmap);
qp = &nt->qps[free_queue];
qp->cb_data = data;
qp->rx_handler = handlers->rx_handler;
qp->tx_handler = handlers->tx_handler;
qp->event_handler = handlers->event_handler;
for (i = 0; i < NTB_QP_DEF_NUM_ENTRIES; i++) {
entry = kzalloc(sizeof(struct ntb_queue_entry), GFP_ATOMIC);
if (!entry)
goto err1;
ntb_list_add(&qp->ntb_rx_free_q_lock, &entry->entry,
&qp->rx_free_q);
}
for (i = 0; i < NTB_QP_DEF_NUM_ENTRIES; i++) {
entry = kzalloc(sizeof(struct ntb_queue_entry), GFP_ATOMIC);
if (!entry)
goto err2;
ntb_list_add(&qp->ntb_tx_free_q_lock, &entry->entry,
&qp->tx_free_q);
}
tasklet_init(&qp->rx_work, ntb_transport_rx, (unsigned long) qp);
rc = ntb_register_db_callback(qp->ndev, free_queue, qp,
ntb_transport_rxc_db);
if (rc)
goto err3;
dev_info(&pdev->dev, "NTB Transport QP %d created\n", qp->qp_num);
return qp;
err3:
tasklet_disable(&qp->rx_work);
err2:
while ((entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q)))
kfree(entry);
err1:
while ((entry = ntb_list_rm(&qp->ntb_rx_free_q_lock, &qp->rx_free_q)))
kfree(entry);
set_bit(free_queue, &nt->qp_bitmap);
err:
return NULL;
}
void ntb_transport_free_queue(struct ntb_transport_qp *qp)
{
struct pci_dev *pdev = ntb_query_pdev(qp->ndev);
struct ntb_queue_entry *entry;
if (!qp)
return;
cancel_delayed_work_sync(&qp->link_work);
ntb_unregister_db_callback(qp->ndev, qp->qp_num);
tasklet_disable(&qp->rx_work);
while ((entry = ntb_list_rm(&qp->ntb_rx_free_q_lock, &qp->rx_free_q)))
kfree(entry);
while ((entry = ntb_list_rm(&qp->ntb_rx_pend_q_lock, &qp->rx_pend_q))) {
dev_warn(&pdev->dev, "Freeing item from a non-empty queue\n");
kfree(entry);
}
while ((entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q)))
kfree(entry);
set_bit(qp->qp_num, &qp->transport->qp_bitmap);
dev_info(&pdev->dev, "NTB Transport QP %d freed\n", qp->qp_num);
}
void *ntb_transport_rx_remove(struct ntb_transport_qp *qp, unsigned int *len)
{
struct ntb_queue_entry *entry;
void *buf;
if (!qp || qp->client_ready == NTB_LINK_UP)
return NULL;
entry = ntb_list_rm(&qp->ntb_rx_pend_q_lock, &qp->rx_pend_q);
if (!entry)
return NULL;
buf = entry->cb_data;
*len = entry->len;
ntb_list_add(&qp->ntb_rx_free_q_lock, &entry->entry, &qp->rx_free_q);
return buf;
}
int ntb_transport_rx_enqueue(struct ntb_transport_qp *qp, void *cb, void *data,
unsigned int len)
{
struct ntb_queue_entry *entry;
if (!qp)
return -EINVAL;
entry = ntb_list_rm(&qp->ntb_rx_free_q_lock, &qp->rx_free_q);
if (!entry)
return -ENOMEM;
entry->cb_data = cb;
entry->buf = data;
entry->len = len;
ntb_list_add(&qp->ntb_rx_pend_q_lock, &entry->entry, &qp->rx_pend_q);
return 0;
}
int ntb_transport_tx_enqueue(struct ntb_transport_qp *qp, void *cb, void *data,
unsigned int len)
{
struct ntb_queue_entry *entry;
int rc;
if (!qp || qp->qp_link != NTB_LINK_UP || !len)
return -EINVAL;
entry = ntb_list_rm(&qp->ntb_tx_free_q_lock, &qp->tx_free_q);
if (!entry)
return -ENOMEM;
entry->cb_data = cb;
entry->buf = data;
entry->len = len;
entry->flags = 0;
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
qp->client_ready = NTB_LINK_UP;
if (qp->transport->transport_link == NTB_LINK_UP)
schedule_delayed_work(&qp->link_work, 0);
}
void ntb_transport_link_down(struct ntb_transport_qp *qp)
{
struct pci_dev *pdev = ntb_query_pdev(qp->ndev);
int rc, val;
if (!qp)
return;
qp->client_ready = NTB_LINK_DOWN;
rc = ntb_read_local_spad(qp->ndev, QP_LINKS, &val);
if (rc) {
dev_err(&pdev->dev, "Error reading spad %d\n", QP_LINKS);
return;
}
rc = ntb_write_remote_spad(qp->ndev, QP_LINKS,
val & ~(1 << qp->qp_num));
if (rc)
dev_err(&pdev->dev, "Error writing %x to remote spad %d\n",
val & ~(1 << qp->qp_num), QP_LINKS);
if (qp->qp_link == NTB_LINK_UP)
ntb_send_link_down(qp);
else
cancel_delayed_work_sync(&qp->link_work);
}
bool ntb_transport_link_query(struct ntb_transport_qp *qp)
{
return qp->qp_link == NTB_LINK_UP;
}
unsigned char ntb_transport_qp_num(struct ntb_transport_qp *qp)
{
return qp->qp_num;
}
unsigned int ntb_transport_max_size(struct ntb_transport_qp *qp)
{
return qp->tx_max_frame - sizeof(struct ntb_payload_header);
}
