static inline int scpi_to_linux_errno(int errno)
{
if (errno >= SCPI_SUCCESS && errno < SCPI_ERR_MAX)
return scpi_linux_errmap[errno];
return -EIO;
}
static void scpi_process_cmd(struct scpi_chan *ch, u32 cmd)
{
unsigned long flags;
struct scpi_xfer *t, *match = NULL;
spin_lock_irqsave(&ch->rx_lock, flags);
if (list_empty(&ch->rx_pending)) {
spin_unlock_irqrestore(&ch->rx_lock, flags);
return;
}
list_for_each_entry(t, &ch->rx_pending, node)
if (CMD_XTRACT_UNIQ(t->cmd) == CMD_XTRACT_UNIQ(cmd)) {
list_del(&t->node);
match = t;
break;
}
if (match && !completion_done(&match->done)) {
struct scpi_shared_mem *mem = ch->rx_payload;
unsigned int len = min(match->rx_len, CMD_SIZE(cmd));
match->status = le32_to_cpu(mem->status);
memcpy_fromio(match->rx_buf, mem->payload, len);
if (match->rx_len > len)
memset(match->rx_buf + len, 0, match->rx_len - len);
complete(&match->done);
}
spin_unlock_irqrestore(&ch->rx_lock, flags);
}
static void scpi_handle_remote_msg(struct mbox_client *c, void *msg)
{
struct scpi_chan *ch = container_of(c, struct scpi_chan, cl);
struct scpi_shared_mem *mem = ch->rx_payload;
u32 cmd = le32_to_cpu(mem->command);
scpi_process_cmd(ch, cmd);
}
static void scpi_tx_prepare(struct mbox_client *c, void *msg)
{
unsigned long flags;
struct scpi_xfer *t = msg;
struct scpi_chan *ch = container_of(c, struct scpi_chan, cl);
struct scpi_shared_mem *mem = (struct scpi_shared_mem *)ch->tx_payload;
if (t->tx_buf)
memcpy_toio(mem->payload, t->tx_buf, t->tx_len);
if (t->rx_buf) {
if (!(++ch->token))
++ch->token;
ADD_SCPI_TOKEN(t->cmd, ch->token);
spin_lock_irqsave(&ch->rx_lock, flags);
list_add_tail(&t->node, &ch->rx_pending);
spin_unlock_irqrestore(&ch->rx_lock, flags);
}
mem->command = cpu_to_le32(t->cmd);
}
static struct scpi_xfer *get_scpi_xfer(struct scpi_chan *ch)
{
struct scpi_xfer *t;
mutex_lock(&ch->xfers_lock);
if (list_empty(&ch->xfers_list)) {
mutex_unlock(&ch->xfers_lock);
return NULL;
}
t = list_first_entry(&ch->xfers_list, struct scpi_xfer, node);
list_del(&t->node);
mutex_unlock(&ch->xfers_lock);
return t;
}
static void put_scpi_xfer(struct scpi_xfer *t, struct scpi_chan *ch)
{
mutex_lock(&ch->xfers_lock);
list_add_tail(&t->node, &ch->xfers_list);
mutex_unlock(&ch->xfers_lock);
}
static int scpi_send_message(u8 cmd, void *tx_buf, unsigned int tx_len,
void *rx_buf, unsigned int rx_len)
{
int ret;
u8 chan;
struct scpi_xfer *msg;
struct scpi_chan *scpi_chan;
chan = atomic_inc_return(&scpi_info->next_chan) % scpi_info->num_chans;
scpi_chan = scpi_info->channels + chan;
msg = get_scpi_xfer(scpi_chan);
if (!msg)
return -ENOMEM;
msg->slot = BIT(SCPI_SLOT);
msg->cmd = PACK_SCPI_CMD(cmd, tx_len);
msg->tx_buf = tx_buf;
msg->tx_len = tx_len;
msg->rx_buf = rx_buf;
msg->rx_len = rx_len;
init_completion(&msg->done);
ret = mbox_send_message(scpi_chan->chan, msg);
if (ret < 0 || !rx_buf)
goto out;
if (!wait_for_completion_timeout(&msg->done, MAX_RX_TIMEOUT))
ret = -ETIMEDOUT;
else
ret = msg->status;
out:
if (ret < 0 && rx_buf)
scpi_process_cmd(scpi_chan, msg->cmd);
put_scpi_xfer(msg, scpi_chan);
return ret > 0 ? scpi_to_linux_errno(ret) : ret;
}
static u32 scpi_get_version(void)
{
return scpi_info->protocol_version;
}
static int
scpi_clk_get_range(u16 clk_id, unsigned long *min, unsigned long *max)
{
int ret;
struct clk_get_info clk;
__le16 le_clk_id = cpu_to_le16(clk_id);
ret = scpi_send_message(SCPI_CMD_GET_CLOCK_INFO, &le_clk_id,
sizeof(le_clk_id), &clk, sizeof(clk));
if (!ret) {
*min = le32_to_cpu(clk.min_rate);
*max = le32_to_cpu(clk.max_rate);
}
return ret;
}
static unsigned long scpi_clk_get_val(u16 clk_id)
{
int ret;
struct clk_get_value clk;
__le16 le_clk_id = cpu_to_le16(clk_id);
ret = scpi_send_message(SCPI_CMD_GET_CLOCK_VALUE, &le_clk_id,
sizeof(le_clk_id), &clk, sizeof(clk));
return ret ? ret : le32_to_cpu(clk.rate);
}
static int scpi_clk_set_val(u16 clk_id, unsigned long rate)
{
int stat;
struct clk_set_value clk = {
.id = cpu_to_le16(clk_id),
.rate = cpu_to_le32(rate)
};
return scpi_send_message(SCPI_CMD_SET_CLOCK_VALUE, &clk, sizeof(clk),
&stat, sizeof(stat));
}
static int scpi_dvfs_get_idx(u8 domain)
{
int ret;
struct dvfs_get dvfs;
ret = scpi_send_message(SCPI_CMD_GET_DVFS, &domain, sizeof(domain),
&dvfs, sizeof(dvfs));
return ret ? ret : dvfs.index;
}
static int scpi_dvfs_set_idx(u8 domain, u8 index)
{
int stat;
struct dvfs_set dvfs = {domain, index};
return scpi_send_message(SCPI_CMD_SET_DVFS, &dvfs, sizeof(dvfs),
&stat, sizeof(stat));
}
static int opp_cmp_func(const void *opp1, const void *opp2)
{
const struct scpi_opp *t1 = opp1, *t2 = opp2;
return t1->freq - t2->freq;
}
static struct scpi_dvfs_info *scpi_dvfs_get_info(u8 domain)
{
struct scpi_dvfs_info *info;
struct scpi_opp *opp;
struct dvfs_info buf;
int ret, i;
if (domain >= MAX_DVFS_DOMAINS)
return ERR_PTR(-EINVAL);
if (scpi_info->dvfs[domain])
return scpi_info->dvfs[domain];
ret = scpi_send_message(SCPI_CMD_GET_DVFS_INFO, &domain, sizeof(domain),
&buf, sizeof(buf));
if (ret)
return ERR_PTR(ret);
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return ERR_PTR(-ENOMEM);
info->count = DVFS_OPP_COUNT(buf.header);
info->latency = DVFS_LATENCY(buf.header) * 1000;
info->opps = kcalloc(info->count, sizeof(*opp), GFP_KERNEL);
if (!info->opps) {
kfree(info);
return ERR_PTR(-ENOMEM);
}
for (i = 0, opp = info->opps; i < info->count; i++, opp++) {
opp->freq = le32_to_cpu(buf.opps[i].freq);
opp->m_volt = le32_to_cpu(buf.opps[i].m_volt);
}
sort(info->opps, info->count, sizeof(*opp), opp_cmp_func, NULL);
scpi_info->dvfs[domain] = info;
return info;
}
static int scpi_sensor_get_capability(u16 *sensors)
{
struct sensor_capabilities cap_buf;
int ret;
ret = scpi_send_message(SCPI_CMD_SENSOR_CAPABILITIES, NULL, 0, &cap_buf,
sizeof(cap_buf));
if (!ret)
*sensors = le16_to_cpu(cap_buf.sensors);
return ret;
}
static int scpi_sensor_get_info(u16 sensor_id, struct scpi_sensor_info *info)
{
__le16 id = cpu_to_le16(sensor_id);
struct _scpi_sensor_info _info;
int ret;
ret = scpi_send_message(SCPI_CMD_SENSOR_INFO, &id, sizeof(id),
&_info, sizeof(_info));
if (!ret) {
memcpy(info, &_info, sizeof(*info));
info->sensor_id = le16_to_cpu(_info.sensor_id);
}
return ret;
}
int scpi_sensor_get_value(u16 sensor, u64 *val)
{
__le16 id = cpu_to_le16(sensor);
struct sensor_value buf;
int ret;
ret = scpi_send_message(SCPI_CMD_SENSOR_VALUE, &id, sizeof(id),
&buf, sizeof(buf));
if (!ret)
*val = (u64)le32_to_cpu(buf.hi_val) << 32 |
le32_to_cpu(buf.lo_val);
return ret;
}
struct scpi_ops *get_scpi_ops(void)
{
return scpi_info ? scpi_info->scpi_ops : NULL;
}
static int scpi_init_versions(struct scpi_drvinfo *info)
{
int ret;
struct scp_capabilities caps;
ret = scpi_send_message(SCPI_CMD_SCPI_CAPABILITIES, NULL, 0,
&caps, sizeof(caps));
if (!ret) {
info->protocol_version = le32_to_cpu(caps.protocol_version);
info->firmware_version = le32_to_cpu(caps.platform_version);
}
return ret;
}
static ssize_t protocol_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct scpi_drvinfo *scpi_info = dev_get_drvdata(dev);
return sprintf(buf, "%d.%d\n",
PROTOCOL_REV_MAJOR(scpi_info->protocol_version),
PROTOCOL_REV_MINOR(scpi_info->protocol_version));
}
static ssize_t firmware_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct scpi_drvinfo *scpi_info = dev_get_drvdata(dev);
return sprintf(buf, "%d.%d.%d\n",
FW_REV_MAJOR(scpi_info->firmware_version),
FW_REV_MINOR(scpi_info->firmware_version),
FW_REV_PATCH(scpi_info->firmware_version));
}
static void
scpi_free_channels(struct device *dev, struct scpi_chan *pchan, int count)
{
int i;
for (i = 0; i < count && pchan->chan; i++, pchan++) {
mbox_free_channel(pchan->chan);
devm_kfree(dev, pchan->xfers);
devm_iounmap(dev, pchan->rx_payload);
}
}
static int scpi_remove(struct platform_device *pdev)
{
int i;
struct device *dev = &pdev->dev;
struct scpi_drvinfo *info = platform_get_drvdata(pdev);
scpi_info = NULL;
of_platform_depopulate(dev);
sysfs_remove_groups(&dev->kobj, versions_groups);
scpi_free_channels(dev, info->channels, info->num_chans);
platform_set_drvdata(pdev, NULL);
for (i = 0; i < MAX_DVFS_DOMAINS && info->dvfs[i]; i++) {
kfree(info->dvfs[i]->opps);
kfree(info->dvfs[i]);
}
devm_kfree(dev, info->channels);
devm_kfree(dev, info);
return 0;
}
static int scpi_alloc_xfer_list(struct device *dev, struct scpi_chan *ch)
{
int i;
struct scpi_xfer *xfers;
xfers = devm_kzalloc(dev, MAX_SCPI_XFERS * sizeof(*xfers), GFP_KERNEL);
if (!xfers)
return -ENOMEM;
ch->xfers = xfers;
for (i = 0; i < MAX_SCPI_XFERS; i++, xfers++)
list_add_tail(&xfers->node, &ch->xfers_list);
return 0;
}
static int scpi_probe(struct platform_device *pdev)
{
int count, idx, ret;
struct resource res;
struct scpi_chan *scpi_chan;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
scpi_info = devm_kzalloc(dev, sizeof(*scpi_info), GFP_KERNEL);
if (!scpi_info)
return -ENOMEM;
count = of_count_phandle_with_args(np, "mboxes", "#mbox-cells");
if (count < 0) {
dev_err(dev, "no mboxes property in '%s'\n", np->full_name);
return -ENODEV;
}
scpi_chan = devm_kcalloc(dev, count, sizeof(*scpi_chan), GFP_KERNEL);
if (!scpi_chan)
return -ENOMEM;
for (idx = 0; idx < count; idx++) {
resource_size_t size;
struct scpi_chan *pchan = scpi_chan + idx;
struct mbox_client *cl = &pchan->cl;
struct device_node *shmem = of_parse_phandle(np, "shmem", idx);
if (of_address_to_resource(shmem, 0, &res)) {
dev_err(dev, "failed to get SCPI payload mem resource\n");
ret = -EINVAL;
goto err;
}
size = resource_size(&res);
pchan->rx_payload = devm_ioremap(dev, res.start, size);
if (!pchan->rx_payload) {
dev_err(dev, "failed to ioremap SCPI payload\n");
ret = -EADDRNOTAVAIL;
goto err;
}
pchan->tx_payload = pchan->rx_payload + (size >> 1);
cl->dev = dev;
cl->rx_callback = scpi_handle_remote_msg;
cl->tx_prepare = scpi_tx_prepare;
cl->tx_block = true;
cl->tx_tout = 20;
cl->knows_txdone = false;
INIT_LIST_HEAD(&pchan->rx_pending);
INIT_LIST_HEAD(&pchan->xfers_list);
spin_lock_init(&pchan->rx_lock);
mutex_init(&pchan->xfers_lock);
ret = scpi_alloc_xfer_list(dev, pchan);
if (!ret) {
pchan->chan = mbox_request_channel(cl, idx);
if (!IS_ERR(pchan->chan))
continue;
ret = PTR_ERR(pchan->chan);
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to get channel%d err %d\n",
idx, ret);
}
err:
scpi_free_channels(dev, scpi_chan, idx);
scpi_info = NULL;
return ret;
}
scpi_info->channels = scpi_chan;
scpi_info->num_chans = count;
platform_set_drvdata(pdev, scpi_info);
ret = scpi_init_versions(scpi_info);
if (ret) {
dev_err(dev, "incorrect or no SCP firmware found\n");
scpi_remove(pdev);
return ret;
}
_dev_info(dev, "SCP Protocol %d.%d Firmware %d.%d.%d version\n",
PROTOCOL_REV_MAJOR(scpi_info->protocol_version),
PROTOCOL_REV_MINOR(scpi_info->protocol_version),
FW_REV_MAJOR(scpi_info->firmware_version),
FW_REV_MINOR(scpi_info->firmware_version),
FW_REV_PATCH(scpi_info->firmware_version));
scpi_info->scpi_ops = &scpi_ops;
ret = sysfs_create_groups(&dev->kobj, versions_groups);
if (ret)
dev_err(dev, "unable to create sysfs version group\n");
return of_platform_populate(dev->of_node, NULL, NULL, dev);
}
