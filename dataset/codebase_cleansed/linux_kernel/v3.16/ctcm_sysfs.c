static ssize_t ctcm_buffer_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctcm_priv *priv = dev_get_drvdata(dev);
if (!priv)
return -ENODEV;
return sprintf(buf, "%d\n", priv->buffer_size);
}
static ssize_t ctcm_buffer_write(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct net_device *ndev;
unsigned int bs1;
struct ctcm_priv *priv = dev_get_drvdata(dev);
int rc;
ndev = priv->channel[CTCM_READ]->netdev;
if (!(priv && priv->channel[CTCM_READ] && ndev)) {
CTCM_DBF_TEXT(SETUP, CTC_DBF_ERROR, "bfnondev");
return -ENODEV;
}
rc = sscanf(buf, "%u", &bs1);
if (rc != 1)
goto einval;
if (bs1 > CTCM_BUFSIZE_LIMIT)
goto einval;
if (bs1 < (576 + LL_HEADER_LENGTH + 2))
goto einval;
priv->buffer_size = bs1;
if ((ndev->flags & IFF_RUNNING) &&
(bs1 < (ndev->mtu + LL_HEADER_LENGTH + 2)))
goto einval;
priv->channel[CTCM_READ]->max_bufsize = bs1;
priv->channel[CTCM_WRITE]->max_bufsize = bs1;
if (!(ndev->flags & IFF_RUNNING))
ndev->mtu = bs1 - LL_HEADER_LENGTH - 2;
priv->channel[CTCM_READ]->flags |= CHANNEL_FLAGS_BUFSIZE_CHANGED;
priv->channel[CTCM_WRITE]->flags |= CHANNEL_FLAGS_BUFSIZE_CHANGED;
CTCM_DBF_DEV(SETUP, ndev, buf);
return count;
einval:
CTCM_DBF_DEV(SETUP, ndev, "buff_err");
return -EINVAL;
}
static void ctcm_print_statistics(struct ctcm_priv *priv)
{
char *sbuf;
char *p;
if (!priv)
return;
sbuf = kmalloc(2048, GFP_KERNEL);
if (sbuf == NULL)
return;
p = sbuf;
p += sprintf(p, " Device FSM state: %s\n",
fsm_getstate_str(priv->fsm));
p += sprintf(p, " RX channel FSM state: %s\n",
fsm_getstate_str(priv->channel[CTCM_READ]->fsm));
p += sprintf(p, " TX channel FSM state: %s\n",
fsm_getstate_str(priv->channel[CTCM_WRITE]->fsm));
p += sprintf(p, " Max. TX buffer used: %ld\n",
priv->channel[WRITE]->prof.maxmulti);
p += sprintf(p, " Max. chained SKBs: %ld\n",
priv->channel[WRITE]->prof.maxcqueue);
p += sprintf(p, " TX single write ops: %ld\n",
priv->channel[WRITE]->prof.doios_single);
p += sprintf(p, " TX multi write ops: %ld\n",
priv->channel[WRITE]->prof.doios_multi);
p += sprintf(p, " Netto bytes written: %ld\n",
priv->channel[WRITE]->prof.txlen);
p += sprintf(p, " Max. TX IO-time: %ld\n",
priv->channel[WRITE]->prof.tx_time);
printk(KERN_INFO "Statistics for %s:\n%s",
priv->channel[CTCM_WRITE]->netdev->name, sbuf);
kfree(sbuf);
return;
}
static ssize_t stats_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccwgroup_device *gdev = to_ccwgroupdev(dev);
struct ctcm_priv *priv = dev_get_drvdata(dev);
if (!priv || gdev->state != CCWGROUP_ONLINE)
return -ENODEV;
ctcm_print_statistics(priv);
return sprintf(buf, "0\n");
}
static ssize_t stats_write(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ctcm_priv *priv = dev_get_drvdata(dev);
if (!priv)
return -ENODEV;
memset(&priv->channel[WRITE]->prof, 0,
sizeof(priv->channel[CTCM_WRITE]->prof));
return count;
}
static ssize_t ctcm_proto_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctcm_priv *priv = dev_get_drvdata(dev);
if (!priv)
return -ENODEV;
return sprintf(buf, "%d\n", priv->protocol);
}
static ssize_t ctcm_proto_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int value, rc;
struct ctcm_priv *priv = dev_get_drvdata(dev);
if (!priv)
return -ENODEV;
rc = sscanf(buf, "%d", &value);
if ((rc != 1) ||
!((value == CTCM_PROTO_S390) ||
(value == CTCM_PROTO_LINUX) ||
(value == CTCM_PROTO_MPC) ||
(value == CTCM_PROTO_OS390)))
return -EINVAL;
priv->protocol = value;
CTCM_DBF_DEV(SETUP, dev, buf);
return count;
}
static ssize_t ctcm_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ccwgroup_device *cgdev;
cgdev = to_ccwgroupdev(dev);
if (!cgdev)
return -ENODEV;
return sprintf(buf, "%s\n",
ctcm_type[cgdev->cdev[0]->id.driver_info]);
}
