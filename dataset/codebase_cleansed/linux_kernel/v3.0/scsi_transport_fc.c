static int
show_fc_fc4s (char *buf, u8 *fc4_list)
{
int i, len=0;
for (i = 0; i < FC_FC4_LIST_SIZE; i++, fc4_list++)
len += sprintf(buf + len , "0x%02x ", *fc4_list);
len += sprintf(buf + len, "\n");
return len;
}
static int fc_target_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct scsi_target *starget = to_scsi_target(dev);
struct fc_rport *rport = starget_to_rport(starget);
if (rport) {
fc_starget_node_name(starget) = rport->node_name;
fc_starget_port_name(starget) = rport->port_name;
fc_starget_port_id(starget) = rport->port_id;
} else {
fc_starget_node_name(starget) = -1;
fc_starget_port_name(starget) = -1;
fc_starget_port_id(starget) = -1;
}
return 0;
}
static int fc_host_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
fc_host->node_name = -1;
fc_host->port_name = -1;
fc_host->permanent_port_name = -1;
fc_host->supported_classes = FC_COS_UNSPECIFIED;
memset(fc_host->supported_fc4s, 0,
sizeof(fc_host->supported_fc4s));
fc_host->supported_speeds = FC_PORTSPEED_UNKNOWN;
fc_host->maxframe_size = -1;
fc_host->max_npiv_vports = 0;
memset(fc_host->serial_number, 0,
sizeof(fc_host->serial_number));
fc_host->port_id = -1;
fc_host->port_type = FC_PORTTYPE_UNKNOWN;
fc_host->port_state = FC_PORTSTATE_UNKNOWN;
memset(fc_host->active_fc4s, 0,
sizeof(fc_host->active_fc4s));
fc_host->speed = FC_PORTSPEED_UNKNOWN;
fc_host->fabric_name = -1;
memset(fc_host->symbolic_name, 0, sizeof(fc_host->symbolic_name));
memset(fc_host->system_hostname, 0, sizeof(fc_host->system_hostname));
fc_host->tgtid_bind_type = FC_TGTID_BIND_BY_WWPN;
INIT_LIST_HEAD(&fc_host->rports);
INIT_LIST_HEAD(&fc_host->rport_bindings);
INIT_LIST_HEAD(&fc_host->vports);
fc_host->next_rport_number = 0;
fc_host->next_target_id = 0;
fc_host->next_vport_number = 0;
fc_host->npiv_vports_inuse = 0;
snprintf(fc_host->work_q_name, sizeof(fc_host->work_q_name),
"fc_wq_%d", shost->host_no);
fc_host->work_q = alloc_workqueue(fc_host->work_q_name, 0, 0);
if (!fc_host->work_q)
return -ENOMEM;
fc_host->dev_loss_tmo = fc_dev_loss_tmo;
snprintf(fc_host->devloss_work_q_name,
sizeof(fc_host->devloss_work_q_name),
"fc_dl_%d", shost->host_no);
fc_host->devloss_work_q =
alloc_workqueue(fc_host->devloss_work_q_name, 0, 0);
if (!fc_host->devloss_work_q) {
destroy_workqueue(fc_host->work_q);
fc_host->work_q = NULL;
return -ENOMEM;
}
fc_bsg_hostadd(shost, fc_host);
return 0;
}
static int fc_host_remove(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
fc_bsg_remove(fc_host->rqst_q);
return 0;
}
u32
fc_get_event_number(void)
{
return atomic_add_return(1, &fc_event_seq);
}
void
fc_host_post_event(struct Scsi_Host *shost, u32 event_number,
enum fc_host_event_code event_code, u32 event_data)
{
struct sk_buff *skb;
struct nlmsghdr *nlh;
struct fc_nl_event *event;
const char *name;
u32 len, skblen;
int err;
if (!scsi_nl_sock) {
err = -ENOENT;
goto send_fail;
}
len = FC_NL_MSGALIGN(sizeof(*event));
skblen = NLMSG_SPACE(len);
skb = alloc_skb(skblen, GFP_KERNEL);
if (!skb) {
err = -ENOBUFS;
goto send_fail;
}
nlh = nlmsg_put(skb, 0, 0, SCSI_TRANSPORT_MSG,
skblen - sizeof(*nlh), 0);
if (!nlh) {
err = -ENOBUFS;
goto send_fail_skb;
}
event = NLMSG_DATA(nlh);
INIT_SCSI_NL_HDR(&event->snlh, SCSI_NL_TRANSPORT_FC,
FC_NL_ASYNC_EVENT, len);
event->seconds = get_seconds();
event->vendor_id = 0;
event->host_no = shost->host_no;
event->event_datalen = sizeof(u32);
event->event_num = event_number;
event->event_code = event_code;
event->event_data = event_data;
nlmsg_multicast(scsi_nl_sock, skb, 0, SCSI_NL_GRP_FC_EVENTS,
GFP_KERNEL);
return;
send_fail_skb:
kfree_skb(skb);
send_fail:
name = get_fc_host_event_code_name(event_code);
printk(KERN_WARNING
"%s: Dropped Event : host %d %s data 0x%08x - err %d\n",
__func__, shost->host_no,
(name) ? name : "<unknown>", event_data, err);
return;
}
void
fc_host_post_vendor_event(struct Scsi_Host *shost, u32 event_number,
u32 data_len, char * data_buf, u64 vendor_id)
{
struct sk_buff *skb;
struct nlmsghdr *nlh;
struct fc_nl_event *event;
u32 len, skblen;
int err;
if (!scsi_nl_sock) {
err = -ENOENT;
goto send_vendor_fail;
}
len = FC_NL_MSGALIGN(sizeof(*event) + data_len);
skblen = NLMSG_SPACE(len);
skb = alloc_skb(skblen, GFP_KERNEL);
if (!skb) {
err = -ENOBUFS;
goto send_vendor_fail;
}
nlh = nlmsg_put(skb, 0, 0, SCSI_TRANSPORT_MSG,
skblen - sizeof(*nlh), 0);
if (!nlh) {
err = -ENOBUFS;
goto send_vendor_fail_skb;
}
event = NLMSG_DATA(nlh);
INIT_SCSI_NL_HDR(&event->snlh, SCSI_NL_TRANSPORT_FC,
FC_NL_ASYNC_EVENT, len);
event->seconds = get_seconds();
event->vendor_id = vendor_id;
event->host_no = shost->host_no;
event->event_datalen = data_len;
event->event_num = event_number;
event->event_code = FCH_EVT_VENDOR_UNIQUE;
memcpy(&event->event_data, data_buf, data_len);
nlmsg_multicast(scsi_nl_sock, skb, 0, SCSI_NL_GRP_FC_EVENTS,
GFP_KERNEL);
return;
send_vendor_fail_skb:
kfree_skb(skb);
send_vendor_fail:
printk(KERN_WARNING
"%s: Dropped Event : host %d vendor_unique - err %d\n",
__func__, shost->host_no, err);
return;
}
static __init int fc_transport_init(void)
{
int error;
atomic_set(&fc_event_seq, 0);
error = transport_class_register(&fc_host_class);
if (error)
return error;
error = transport_class_register(&fc_vport_class);
if (error)
goto unreg_host_class;
error = transport_class_register(&fc_rport_class);
if (error)
goto unreg_vport_class;
error = transport_class_register(&fc_transport_class);
if (error)
goto unreg_rport_class;
return 0;
unreg_rport_class:
transport_class_unregister(&fc_rport_class);
unreg_vport_class:
transport_class_unregister(&fc_vport_class);
unreg_host_class:
transport_class_unregister(&fc_host_class);
return error;
}
static void __exit fc_transport_exit(void)
{
transport_class_unregister(&fc_transport_class);
transport_class_unregister(&fc_rport_class);
transport_class_unregister(&fc_host_class);
transport_class_unregister(&fc_vport_class);
}
static ssize_t
show_fc_rport_supported_classes (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fc_rport *rport = transport_class_to_rport(dev);
if (rport->supported_classes == FC_COS_UNSPECIFIED)
return snprintf(buf, 20, "unspecified\n");
return get_fc_cos_names(rport->supported_classes, buf);
}
static int fc_str_to_dev_loss(const char *buf, unsigned long *val)
{
char *cp;
*val = simple_strtoul(buf, &cp, 0);
if ((*cp && (*cp != '\n')) || (*val < 0))
return -EINVAL;
if (*val > UINT_MAX)
return -EINVAL;
return 0;
}
static int fc_rport_set_dev_loss_tmo(struct fc_rport *rport,
unsigned long val)
{
struct Scsi_Host *shost = rport_to_shost(rport);
struct fc_internal *i = to_fc_internal(shost->transportt);
if ((rport->port_state == FC_PORTSTATE_BLOCKED) ||
(rport->port_state == FC_PORTSTATE_DELETED) ||
(rport->port_state == FC_PORTSTATE_NOTPRESENT))
return -EBUSY;
if (val > UINT_MAX)
return -EINVAL;
if (rport->fast_io_fail_tmo == -1 &&
val > SCSI_DEVICE_BLOCK_MAX_TIMEOUT)
return -EINVAL;
i->f->set_rport_dev_loss_tmo(rport, val);
return 0;
}
static ssize_t
store_fc_rport_dev_loss_tmo(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fc_rport *rport = transport_class_to_rport(dev);
unsigned long val;
int rc;
rc = fc_str_to_dev_loss(buf, &val);
if (rc)
return rc;
rc = fc_rport_set_dev_loss_tmo(rport, val);
if (rc)
return rc;
return count;
}
static ssize_t
show_fc_rport_roles (struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fc_rport *rport = transport_class_to_rport(dev);
if ((rport->port_id != -1) &&
(rport->port_id & FC_WELLKNOWN_PORTID_MASK) ==
FC_WELLKNOWN_PORTID_MASK) {
switch (rport->port_id & FC_WELLKNOWN_ROLE_MASK) {
case FC_FPORT_PORTID:
return snprintf(buf, 30, "Fabric Port\n");
case FC_FABCTLR_PORTID:
return snprintf(buf, 30, "Fabric Controller\n");
case FC_DIRSRVR_PORTID:
return snprintf(buf, 30, "Directory Server\n");
case FC_TIMESRVR_PORTID:
return snprintf(buf, 30, "Time Server\n");
case FC_MGMTSRVR_PORTID:
return snprintf(buf, 30, "Management Server\n");
default:
return snprintf(buf, 30, "Unknown Fabric Entity\n");
}
} else {
if (rport->roles == FC_PORT_ROLE_UNKNOWN)
return snprintf(buf, 20, "unknown\n");
return get_fc_port_roles_names(rport->roles, buf);
}
}
static ssize_t
show_fc_rport_fast_io_fail_tmo (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fc_rport *rport = transport_class_to_rport(dev);
if (rport->fast_io_fail_tmo == -1)
return snprintf(buf, 5, "off\n");
return snprintf(buf, 20, "%d\n", rport->fast_io_fail_tmo);
}
static ssize_t
store_fc_rport_fast_io_fail_tmo(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
int val;
char *cp;
struct fc_rport *rport = transport_class_to_rport(dev);
if ((rport->port_state == FC_PORTSTATE_BLOCKED) ||
(rport->port_state == FC_PORTSTATE_DELETED) ||
(rport->port_state == FC_PORTSTATE_NOTPRESENT))
return -EBUSY;
if (strncmp(buf, "off", 3) == 0)
rport->fast_io_fail_tmo = -1;
else {
val = simple_strtoul(buf, &cp, 0);
if ((*cp && (*cp != '\n')) || (val < 0))
return -EINVAL;
if ((val >= rport->dev_loss_tmo) ||
(val > SCSI_DEVICE_BLOCK_MAX_TIMEOUT))
return -EINVAL;
rport->fast_io_fail_tmo = val;
}
return count;
}
static ssize_t
show_fc_vport_roles (struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fc_vport *vport = transport_class_to_vport(dev);
if (vport->roles == FC_PORT_ROLE_UNKNOWN)
return snprintf(buf, 20, "unknown\n");
return get_fc_port_roles_names(vport->roles, buf);
}
static ssize_t
store_fc_vport_delete(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fc_vport *vport = transport_class_to_vport(dev);
struct Scsi_Host *shost = vport_to_shost(vport);
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
if (vport->flags & (FC_VPORT_DEL | FC_VPORT_CREATING)) {
spin_unlock_irqrestore(shost->host_lock, flags);
return -EBUSY;
}
vport->flags |= FC_VPORT_DELETING;
spin_unlock_irqrestore(shost->host_lock, flags);
fc_queue_work(shost, &vport->vport_delete_work);
return count;
}
static ssize_t
store_fc_vport_disable(struct device *dev, struct device_attribute *attr,
const char *buf,
size_t count)
{
struct fc_vport *vport = transport_class_to_vport(dev);
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_internal *i = to_fc_internal(shost->transportt);
int stat;
if (vport->flags & (FC_VPORT_DEL | FC_VPORT_CREATING))
return -EBUSY;
if (*buf == '0') {
if (vport->vport_state != FC_VPORT_DISABLED)
return -EALREADY;
} else if (*buf == '1') {
if (vport->vport_state == FC_VPORT_DISABLED)
return -EALREADY;
} else
return -EINVAL;
stat = i->f->vport_disable(vport, ((*buf == '0') ? false : true));
return stat ? stat : count;
}
static ssize_t
show_fc_host_supported_classes (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
if (fc_host_supported_classes(shost) == FC_COS_UNSPECIFIED)
return snprintf(buf, 20, "unspecified\n");
return get_fc_cos_names(fc_host_supported_classes(shost), buf);
}
static ssize_t
show_fc_host_supported_fc4s (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
return (ssize_t)show_fc_fc4s(buf, fc_host_supported_fc4s(shost));
}
static ssize_t
show_fc_host_supported_speeds (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
if (fc_host_supported_speeds(shost) == FC_PORTSPEED_UNKNOWN)
return snprintf(buf, 20, "unknown\n");
return get_fc_port_speed_names(fc_host_supported_speeds(shost), buf);
}
static ssize_t
show_fc_host_active_fc4s (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_internal *i = to_fc_internal(shost->transportt);
if (i->f->get_host_active_fc4s)
i->f->get_host_active_fc4s(shost);
return (ssize_t)show_fc_fc4s(buf, fc_host_active_fc4s(shost));
}
static ssize_t
show_fc_host_speed (struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_internal *i = to_fc_internal(shost->transportt);
if (i->f->get_host_speed)
i->f->get_host_speed(shost);
if (fc_host_speed(shost) == FC_PORTSPEED_UNKNOWN)
return snprintf(buf, 20, "unknown\n");
return get_fc_port_speed_names(fc_host_speed(shost), buf);
}
static ssize_t
show_fc_private_host_tgtid_bind_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
const char *name;
name = get_fc_tgtid_bind_type_name(fc_host_tgtid_bind_type(shost));
if (!name)
return -EINVAL;
return snprintf(buf, FC_BINDTYPE_MAX_NAMELEN, "%s\n", name);
}
static ssize_t
store_fc_private_host_tgtid_bind_type(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_rport *rport;
enum fc_tgtid_binding_type val;
unsigned long flags;
if (get_fc_tgtid_bind_type_match(buf, &val))
return -EINVAL;
if (val != fc_host_tgtid_bind_type(shost)) {
spin_lock_irqsave(shost->host_lock, flags);
while (!list_empty(&fc_host_rport_bindings(shost))) {
get_list_head_entry(rport,
&fc_host_rport_bindings(shost), peers);
list_del(&rport->peers);
rport->port_state = FC_PORTSTATE_DELETED;
fc_queue_work(shost, &rport->rport_delete_work);
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
fc_host_tgtid_bind_type(shost) = val;
return count;
}
static ssize_t
store_fc_private_host_issue_lip(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_internal *i = to_fc_internal(shost->transportt);
int ret;
if (i->f->issue_fc_host_lip) {
ret = i->f->issue_fc_host_lip(shost);
return ret ? ret: count;
}
return -ENOENT;
}
static ssize_t
store_fc_private_host_dev_loss_tmo(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
struct fc_rport *rport;
unsigned long val, flags;
int rc;
rc = fc_str_to_dev_loss(buf, &val);
if (rc)
return rc;
fc_host_dev_loss_tmo(shost) = val;
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry(rport, &fc_host->rports, peers)
fc_rport_set_dev_loss_tmo(rport, val);
spin_unlock_irqrestore(shost->host_lock, flags);
return count;
}
static ssize_t
fc_stat_show(const struct device *dev, char *buf, unsigned long offset)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_internal *i = to_fc_internal(shost->transportt);
struct fc_host_statistics *stats;
ssize_t ret = -ENOENT;
if (offset > sizeof(struct fc_host_statistics) ||
offset % sizeof(u64) != 0)
WARN_ON(1);
if (i->f->get_fc_host_stats) {
stats = (i->f->get_fc_host_stats)(shost);
if (stats)
ret = snprintf(buf, 20, "0x%llx\n",
(unsigned long long)*(u64 *)(((u8 *) stats) + offset));
}
return ret;
}
static ssize_t
fc_reset_statistics(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_internal *i = to_fc_internal(shost->transportt);
if (i->f->reset_fc_host_stats) {
i->f->reset_fc_host_stats(shost);
return count;
}
return -ENOENT;
}
static int
fc_parse_wwn(const char *ns, u64 *nm)
{
unsigned int i, j;
u8 wwn[8];
memset(wwn, 0, sizeof(wwn));
for (i=0, j=0; i < 16; i++) {
int value;
value = hex_to_bin(*ns++);
if (value >= 0)
j = (j << 4) | value;
else
return -EINVAL;
if (i % 2) {
wwn[i/2] = j & 0xff;
j = 0;
}
}
*nm = wwn_to_u64(wwn);
return 0;
}
static ssize_t
store_fc_host_vport_create(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_vport_identifiers vid;
struct fc_vport *vport;
unsigned int cnt=count;
int stat;
memset(&vid, 0, sizeof(vid));
if (buf[cnt-1] == '\n')
cnt--;
if ((cnt != (16+1+16)) || (buf[16] != ':'))
return -EINVAL;
stat = fc_parse_wwn(&buf[0], &vid.port_name);
if (stat)
return stat;
stat = fc_parse_wwn(&buf[17], &vid.node_name);
if (stat)
return stat;
vid.roles = FC_PORT_ROLE_FCP_INITIATOR;
vid.vport_type = FC_PORTTYPE_NPIV;
vid.disable = false;
stat = fc_vport_setup(shost, 0, &shost->shost_gendev, &vid, &vport);
return stat ? stat : count;
}
static ssize_t
store_fc_host_vport_delete(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = transport_class_to_shost(dev);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
struct fc_vport *vport;
u64 wwpn, wwnn;
unsigned long flags;
unsigned int cnt=count;
int stat, match;
if (buf[cnt-1] == '\n')
cnt--;
if ((cnt != (16+1+16)) || (buf[16] != ':'))
return -EINVAL;
stat = fc_parse_wwn(&buf[0], &wwpn);
if (stat)
return stat;
stat = fc_parse_wwn(&buf[17], &wwnn);
if (stat)
return stat;
spin_lock_irqsave(shost->host_lock, flags);
match = 0;
list_for_each_entry(vport, &fc_host->vports, peers) {
if ((vport->channel == 0) &&
(vport->port_name == wwpn) && (vport->node_name == wwnn)) {
if (vport->flags & (FC_VPORT_DEL | FC_VPORT_CREATING))
break;
vport->flags |= FC_VPORT_DELETING;
match = 1;
break;
}
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (!match)
return -ENODEV;
stat = fc_vport_terminate(vport);
return stat ? stat : count;
}
static int fc_host_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct fc_internal *i;
if (!scsi_is_host_device(dev))
return 0;
shost = dev_to_shost(dev);
if (!shost->transportt || shost->transportt->host_attrs.ac.class
!= &fc_host_class.class)
return 0;
i = to_fc_internal(shost->transportt);
return &i->t.host_attrs.ac == cont;
}
static int fc_target_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct fc_internal *i;
if (!scsi_is_target_device(dev))
return 0;
shost = dev_to_shost(dev->parent);
if (!shost->transportt || shost->transportt->host_attrs.ac.class
!= &fc_host_class.class)
return 0;
i = to_fc_internal(shost->transportt);
return &i->t.target_attrs.ac == cont;
}
static void fc_rport_dev_release(struct device *dev)
{
struct fc_rport *rport = dev_to_rport(dev);
put_device(dev->parent);
kfree(rport);
}
int scsi_is_fc_rport(const struct device *dev)
{
return dev->release == fc_rport_dev_release;
}
static int fc_rport_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct fc_internal *i;
if (!scsi_is_fc_rport(dev))
return 0;
shost = dev_to_shost(dev->parent);
if (!shost->transportt || shost->transportt->host_attrs.ac.class
!= &fc_host_class.class)
return 0;
i = to_fc_internal(shost->transportt);
return &i->rport_attr_cont.ac == cont;
}
static void fc_vport_dev_release(struct device *dev)
{
struct fc_vport *vport = dev_to_vport(dev);
put_device(dev->parent);
kfree(vport);
}
int scsi_is_fc_vport(const struct device *dev)
{
return dev->release == fc_vport_dev_release;
}
static int fc_vport_match(struct attribute_container *cont,
struct device *dev)
{
struct fc_vport *vport;
struct Scsi_Host *shost;
struct fc_internal *i;
if (!scsi_is_fc_vport(dev))
return 0;
vport = dev_to_vport(dev);
shost = vport_to_shost(vport);
if (!shost->transportt || shost->transportt->host_attrs.ac.class
!= &fc_host_class.class)
return 0;
i = to_fc_internal(shost->transportt);
return &i->vport_attr_cont.ac == cont;
}
static enum blk_eh_timer_return
fc_timed_out(struct scsi_cmnd *scmd)
{
struct fc_rport *rport = starget_to_rport(scsi_target(scmd->device));
if (rport->port_state == FC_PORTSTATE_BLOCKED)
return BLK_EH_RESET_TIMER;
return BLK_EH_NOT_HANDLED;
}
static void
fc_user_scan_tgt(struct Scsi_Host *shost, uint channel, uint id, uint lun)
{
struct fc_rport *rport;
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry(rport, &fc_host_rports(shost), peers) {
if (rport->scsi_target_id == -1)
continue;
if (rport->port_state != FC_PORTSTATE_ONLINE)
continue;
if ((channel == rport->channel) &&
(id == rport->scsi_target_id)) {
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_scan_target(&rport->dev, channel, id, lun, 1);
return;
}
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
static int
fc_user_scan(struct Scsi_Host *shost, uint channel, uint id, uint lun)
{
uint chlo, chhi;
uint tgtlo, tgthi;
if (((channel != SCAN_WILD_CARD) && (channel > shost->max_channel)) ||
((id != SCAN_WILD_CARD) && (id >= shost->max_id)) ||
((lun != SCAN_WILD_CARD) && (lun > shost->max_lun)))
return -EINVAL;
if (channel == SCAN_WILD_CARD) {
chlo = 0;
chhi = shost->max_channel + 1;
} else {
chlo = channel;
chhi = channel + 1;
}
if (id == SCAN_WILD_CARD) {
tgtlo = 0;
tgthi = shost->max_id;
} else {
tgtlo = id;
tgthi = id + 1;
}
for ( ; chlo < chhi; chlo++)
for ( ; tgtlo < tgthi; tgtlo++)
fc_user_scan_tgt(shost, chlo, tgtlo, lun);
return 0;
}
static int fc_tsk_mgmt_response(struct Scsi_Host *shost, u64 nexus, u64 tm_id,
int result)
{
struct fc_internal *i = to_fc_internal(shost->transportt);
return i->f->tsk_mgmt_response(shost, nexus, tm_id, result);
}
static int fc_it_nexus_response(struct Scsi_Host *shost, u64 nexus, int result)
{
struct fc_internal *i = to_fc_internal(shost->transportt);
return i->f->it_nexus_response(shost, nexus, result);
}
struct scsi_transport_template *
fc_attach_transport(struct fc_function_template *ft)
{
int count;
struct fc_internal *i = kzalloc(sizeof(struct fc_internal),
GFP_KERNEL);
if (unlikely(!i))
return NULL;
i->t.target_attrs.ac.attrs = &i->starget_attrs[0];
i->t.target_attrs.ac.class = &fc_transport_class.class;
i->t.target_attrs.ac.match = fc_target_match;
i->t.target_size = sizeof(struct fc_starget_attrs);
transport_container_register(&i->t.target_attrs);
i->t.host_attrs.ac.attrs = &i->host_attrs[0];
i->t.host_attrs.ac.class = &fc_host_class.class;
i->t.host_attrs.ac.match = fc_host_match;
i->t.host_size = sizeof(struct fc_host_attrs);
if (ft->get_fc_host_stats)
i->t.host_attrs.statistics = &fc_statistics_group;
transport_container_register(&i->t.host_attrs);
i->rport_attr_cont.ac.attrs = &i->rport_attrs[0];
i->rport_attr_cont.ac.class = &fc_rport_class.class;
i->rport_attr_cont.ac.match = fc_rport_match;
transport_container_register(&i->rport_attr_cont);
i->vport_attr_cont.ac.attrs = &i->vport_attrs[0];
i->vport_attr_cont.ac.class = &fc_vport_class.class;
i->vport_attr_cont.ac.match = fc_vport_match;
transport_container_register(&i->vport_attr_cont);
i->f = ft;
i->t.create_work_queue = 1;
i->t.eh_timed_out = fc_timed_out;
i->t.user_scan = fc_user_scan;
i->t.tsk_mgmt_response = fc_tsk_mgmt_response;
i->t.it_nexus_response = fc_it_nexus_response;
count = 0;
SETUP_STARGET_ATTRIBUTE_RD(node_name);
SETUP_STARGET_ATTRIBUTE_RD(port_name);
SETUP_STARGET_ATTRIBUTE_RD(port_id);
BUG_ON(count > FC_STARGET_NUM_ATTRS);
i->starget_attrs[count] = NULL;
count=0;
SETUP_HOST_ATTRIBUTE_RD(node_name);
SETUP_HOST_ATTRIBUTE_RD(port_name);
SETUP_HOST_ATTRIBUTE_RD(permanent_port_name);
SETUP_HOST_ATTRIBUTE_RD(supported_classes);
SETUP_HOST_ATTRIBUTE_RD(supported_fc4s);
SETUP_HOST_ATTRIBUTE_RD(supported_speeds);
SETUP_HOST_ATTRIBUTE_RD(maxframe_size);
if (ft->vport_create) {
SETUP_HOST_ATTRIBUTE_RD_NS(max_npiv_vports);
SETUP_HOST_ATTRIBUTE_RD_NS(npiv_vports_inuse);
}
SETUP_HOST_ATTRIBUTE_RD(serial_number);
SETUP_HOST_ATTRIBUTE_RD(port_id);
SETUP_HOST_ATTRIBUTE_RD(port_type);
SETUP_HOST_ATTRIBUTE_RD(port_state);
SETUP_HOST_ATTRIBUTE_RD(active_fc4s);
SETUP_HOST_ATTRIBUTE_RD(speed);
SETUP_HOST_ATTRIBUTE_RD(fabric_name);
SETUP_HOST_ATTRIBUTE_RD(symbolic_name);
SETUP_HOST_ATTRIBUTE_RW(system_hostname);
SETUP_PRIVATE_HOST_ATTRIBUTE_RW(dev_loss_tmo);
SETUP_PRIVATE_HOST_ATTRIBUTE_RW(tgtid_bind_type);
if (ft->issue_fc_host_lip)
SETUP_PRIVATE_HOST_ATTRIBUTE_RW(issue_lip);
if (ft->vport_create)
SETUP_PRIVATE_HOST_ATTRIBUTE_RW(vport_create);
if (ft->vport_delete)
SETUP_PRIVATE_HOST_ATTRIBUTE_RW(vport_delete);
BUG_ON(count > FC_HOST_NUM_ATTRS);
i->host_attrs[count] = NULL;
count=0;
SETUP_RPORT_ATTRIBUTE_RD(maxframe_size);
SETUP_RPORT_ATTRIBUTE_RD(supported_classes);
SETUP_RPORT_ATTRIBUTE_RW(dev_loss_tmo);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RD(node_name);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RD(port_name);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RD(port_id);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RD(roles);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RD(port_state);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RD(scsi_target_id);
SETUP_PRIVATE_RPORT_ATTRIBUTE_RW(fast_io_fail_tmo);
BUG_ON(count > FC_RPORT_NUM_ATTRS);
i->rport_attrs[count] = NULL;
count=0;
SETUP_PRIVATE_VPORT_ATTRIBUTE_RD(vport_state);
SETUP_PRIVATE_VPORT_ATTRIBUTE_RD(vport_last_state);
SETUP_PRIVATE_VPORT_ATTRIBUTE_RD(node_name);
SETUP_PRIVATE_VPORT_ATTRIBUTE_RD(port_name);
SETUP_PRIVATE_VPORT_ATTRIBUTE_RD(roles);
SETUP_PRIVATE_VPORT_ATTRIBUTE_RD(vport_type);
SETUP_VPORT_ATTRIBUTE_RW(symbolic_name);
SETUP_VPORT_ATTRIBUTE_WR(vport_delete);
SETUP_VPORT_ATTRIBUTE_WR(vport_disable);
BUG_ON(count > FC_VPORT_NUM_ATTRS);
i->vport_attrs[count] = NULL;
return &i->t;
}
void fc_release_transport(struct scsi_transport_template *t)
{
struct fc_internal *i = to_fc_internal(t);
transport_container_unregister(&i->t.target_attrs);
transport_container_unregister(&i->t.host_attrs);
transport_container_unregister(&i->rport_attr_cont);
transport_container_unregister(&i->vport_attr_cont);
kfree(i);
}
static int
fc_queue_work(struct Scsi_Host *shost, struct work_struct *work)
{
if (unlikely(!fc_host_work_q(shost))) {
printk(KERN_ERR
"ERROR: FC host '%s' attempted to queue work, "
"when no workqueue created.\n", shost->hostt->name);
dump_stack();
return -EINVAL;
}
return queue_work(fc_host_work_q(shost), work);
}
static void
fc_flush_work(struct Scsi_Host *shost)
{
if (!fc_host_work_q(shost)) {
printk(KERN_ERR
"ERROR: FC host '%s' attempted to flush work, "
"when no workqueue created.\n", shost->hostt->name);
dump_stack();
return;
}
flush_workqueue(fc_host_work_q(shost));
}
static int
fc_queue_devloss_work(struct Scsi_Host *shost, struct delayed_work *work,
unsigned long delay)
{
if (unlikely(!fc_host_devloss_work_q(shost))) {
printk(KERN_ERR
"ERROR: FC host '%s' attempted to queue work, "
"when no workqueue created.\n", shost->hostt->name);
dump_stack();
return -EINVAL;
}
return queue_delayed_work(fc_host_devloss_work_q(shost), work, delay);
}
static void
fc_flush_devloss(struct Scsi_Host *shost)
{
if (!fc_host_devloss_work_q(shost)) {
printk(KERN_ERR
"ERROR: FC host '%s' attempted to flush work, "
"when no workqueue created.\n", shost->hostt->name);
dump_stack();
return;
}
flush_workqueue(fc_host_devloss_work_q(shost));
}
void
fc_remove_host(struct Scsi_Host *shost)
{
struct fc_vport *vport = NULL, *next_vport = NULL;
struct fc_rport *rport = NULL, *next_rport = NULL;
struct workqueue_struct *work_q;
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry_safe(vport, next_vport, &fc_host->vports, peers)
fc_queue_work(shost, &vport->vport_delete_work);
list_for_each_entry_safe(rport, next_rport,
&fc_host->rports, peers) {
list_del(&rport->peers);
rport->port_state = FC_PORTSTATE_DELETED;
fc_queue_work(shost, &rport->rport_delete_work);
}
list_for_each_entry_safe(rport, next_rport,
&fc_host->rport_bindings, peers) {
list_del(&rport->peers);
rport->port_state = FC_PORTSTATE_DELETED;
fc_queue_work(shost, &rport->rport_delete_work);
}
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_flush_work(shost);
if (fc_host->work_q) {
work_q = fc_host->work_q;
fc_host->work_q = NULL;
destroy_workqueue(work_q);
}
if (fc_host->devloss_work_q) {
work_q = fc_host->devloss_work_q;
fc_host->devloss_work_q = NULL;
destroy_workqueue(work_q);
}
}
static void fc_terminate_rport_io(struct fc_rport *rport)
{
struct Scsi_Host *shost = rport_to_shost(rport);
struct fc_internal *i = to_fc_internal(shost->transportt);
if (i->f->terminate_rport_io)
i->f->terminate_rport_io(rport);
scsi_target_unblock(&rport->dev);
}
static void
fc_starget_delete(struct work_struct *work)
{
struct fc_rport *rport =
container_of(work, struct fc_rport, stgt_delete_work);
fc_terminate_rport_io(rport);
scsi_remove_target(&rport->dev);
}
static void
fc_rport_final_delete(struct work_struct *work)
{
struct fc_rport *rport =
container_of(work, struct fc_rport, rport_delete_work);
struct device *dev = &rport->dev;
struct Scsi_Host *shost = rport_to_shost(rport);
struct fc_internal *i = to_fc_internal(shost->transportt);
unsigned long flags;
int do_callback = 0;
fc_terminate_rport_io(rport);
if (rport->flags & FC_RPORT_SCAN_PENDING)
scsi_flush_work(shost);
spin_lock_irqsave(shost->host_lock, flags);
if (rport->flags & FC_RPORT_DEVLOSS_PENDING) {
spin_unlock_irqrestore(shost->host_lock, flags);
if (!cancel_delayed_work(&rport->fail_io_work))
fc_flush_devloss(shost);
if (!cancel_delayed_work(&rport->dev_loss_work))
fc_flush_devloss(shost);
spin_lock_irqsave(shost->host_lock, flags);
rport->flags &= ~FC_RPORT_DEVLOSS_PENDING;
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (rport->scsi_target_id != -1)
fc_starget_delete(&rport->stgt_delete_work);
spin_lock_irqsave(shost->host_lock, flags);
if (!(rport->flags & FC_RPORT_DEVLOSS_CALLBK_DONE) &&
(i->f->dev_loss_tmo_callbk)) {
rport->flags |= FC_RPORT_DEVLOSS_CALLBK_DONE;
do_callback = 1;
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (do_callback)
i->f->dev_loss_tmo_callbk(rport);
fc_bsg_remove(rport->rqst_q);
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(&shost->shost_gendev);
put_device(dev);
}
static struct fc_rport *
fc_rport_create(struct Scsi_Host *shost, int channel,
struct fc_rport_identifiers *ids)
{
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
struct fc_internal *fci = to_fc_internal(shost->transportt);
struct fc_rport *rport;
struct device *dev;
unsigned long flags;
int error;
size_t size;
size = (sizeof(struct fc_rport) + fci->f->dd_fcrport_size);
rport = kzalloc(size, GFP_KERNEL);
if (unlikely(!rport)) {
printk(KERN_ERR "%s: allocation failure\n", __func__);
return NULL;
}
rport->maxframe_size = -1;
rport->supported_classes = FC_COS_UNSPECIFIED;
rport->dev_loss_tmo = fc_host->dev_loss_tmo;
memcpy(&rport->node_name, &ids->node_name, sizeof(rport->node_name));
memcpy(&rport->port_name, &ids->port_name, sizeof(rport->port_name));
rport->port_id = ids->port_id;
rport->roles = ids->roles;
rport->port_state = FC_PORTSTATE_ONLINE;
if (fci->f->dd_fcrport_size)
rport->dd_data = &rport[1];
rport->channel = channel;
rport->fast_io_fail_tmo = -1;
INIT_DELAYED_WORK(&rport->dev_loss_work, fc_timeout_deleted_rport);
INIT_DELAYED_WORK(&rport->fail_io_work, fc_timeout_fail_rport_io);
INIT_WORK(&rport->scan_work, fc_scsi_scan_rport);
INIT_WORK(&rport->stgt_delete_work, fc_starget_delete);
INIT_WORK(&rport->rport_delete_work, fc_rport_final_delete);
spin_lock_irqsave(shost->host_lock, flags);
rport->number = fc_host->next_rport_number++;
if (rport->roles & FC_PORT_ROLE_FCP_TARGET)
rport->scsi_target_id = fc_host->next_target_id++;
else
rport->scsi_target_id = -1;
list_add_tail(&rport->peers, &fc_host->rports);
get_device(&shost->shost_gendev);
spin_unlock_irqrestore(shost->host_lock, flags);
dev = &rport->dev;
device_initialize(dev);
dev->parent = get_device(&shost->shost_gendev);
dev->release = fc_rport_dev_release;
dev_set_name(dev, "rport-%d:%d-%d",
shost->host_no, channel, rport->number);
transport_setup_device(dev);
error = device_add(dev);
if (error) {
printk(KERN_ERR "FC Remote Port device_add failed\n");
goto delete_rport;
}
transport_add_device(dev);
transport_configure_device(dev);
fc_bsg_rportadd(shost, rport);
if (rport->roles & FC_PORT_ROLE_FCP_TARGET) {
rport->flags |= FC_RPORT_SCAN_PENDING;
scsi_queue_work(shost, &rport->scan_work);
}
return rport;
delete_rport:
transport_destroy_device(dev);
spin_lock_irqsave(shost->host_lock, flags);
list_del(&rport->peers);
put_device(&shost->shost_gendev);
spin_unlock_irqrestore(shost->host_lock, flags);
put_device(dev->parent);
kfree(rport);
return NULL;
}
struct fc_rport *
fc_remote_port_add(struct Scsi_Host *shost, int channel,
struct fc_rport_identifiers *ids)
{
struct fc_internal *fci = to_fc_internal(shost->transportt);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
struct fc_rport *rport;
unsigned long flags;
int match = 0;
fc_flush_work(shost);
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry(rport, &fc_host->rports, peers) {
if ((rport->port_state == FC_PORTSTATE_BLOCKED) &&
(rport->channel == channel)) {
switch (fc_host->tgtid_bind_type) {
case FC_TGTID_BIND_BY_WWPN:
case FC_TGTID_BIND_NONE:
if (rport->port_name == ids->port_name)
match = 1;
break;
case FC_TGTID_BIND_BY_WWNN:
if (rport->node_name == ids->node_name)
match = 1;
break;
case FC_TGTID_BIND_BY_ID:
if (rport->port_id == ids->port_id)
match = 1;
break;
}
if (match) {
memcpy(&rport->node_name, &ids->node_name,
sizeof(rport->node_name));
memcpy(&rport->port_name, &ids->port_name,
sizeof(rport->port_name));
rport->port_id = ids->port_id;
rport->port_state = FC_PORTSTATE_ONLINE;
rport->roles = ids->roles;
spin_unlock_irqrestore(shost->host_lock, flags);
if (fci->f->dd_fcrport_size)
memset(rport->dd_data, 0,
fci->f->dd_fcrport_size);
if ((rport->scsi_target_id != -1) &&
(!(ids->roles & FC_PORT_ROLE_FCP_TARGET)))
return rport;
if (!cancel_delayed_work(&rport->fail_io_work))
fc_flush_devloss(shost);
if (!cancel_delayed_work(&rport->dev_loss_work))
fc_flush_devloss(shost);
spin_lock_irqsave(shost->host_lock, flags);
rport->flags &= ~(FC_RPORT_FAST_FAIL_TIMEDOUT |
FC_RPORT_DEVLOSS_PENDING |
FC_RPORT_DEVLOSS_CALLBK_DONE);
if (rport->scsi_target_id != -1) {
rport->flags |= FC_RPORT_SCAN_PENDING;
scsi_queue_work(shost,
&rport->scan_work);
spin_unlock_irqrestore(shost->host_lock,
flags);
scsi_target_unblock(&rport->dev);
} else
spin_unlock_irqrestore(shost->host_lock,
flags);
fc_bsg_goose_queue(rport);
return rport;
}
}
}
if (fc_host->tgtid_bind_type != FC_TGTID_BIND_NONE) {
list_for_each_entry(rport, &fc_host->rport_bindings,
peers) {
if (rport->channel != channel)
continue;
switch (fc_host->tgtid_bind_type) {
case FC_TGTID_BIND_BY_WWPN:
if (rport->port_name == ids->port_name)
match = 1;
break;
case FC_TGTID_BIND_BY_WWNN:
if (rport->node_name == ids->node_name)
match = 1;
break;
case FC_TGTID_BIND_BY_ID:
if (rport->port_id == ids->port_id)
match = 1;
break;
case FC_TGTID_BIND_NONE:
break;
}
if (match) {
list_move_tail(&rport->peers, &fc_host->rports);
break;
}
}
if (match) {
memcpy(&rport->node_name, &ids->node_name,
sizeof(rport->node_name));
memcpy(&rport->port_name, &ids->port_name,
sizeof(rport->port_name));
rport->port_id = ids->port_id;
rport->roles = ids->roles;
rport->port_state = FC_PORTSTATE_ONLINE;
rport->flags &= ~FC_RPORT_FAST_FAIL_TIMEDOUT;
if (fci->f->dd_fcrport_size)
memset(rport->dd_data, 0,
fci->f->dd_fcrport_size);
if (rport->roles & FC_PORT_ROLE_FCP_TARGET) {
rport->flags |= FC_RPORT_SCAN_PENDING;
scsi_queue_work(shost, &rport->scan_work);
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_target_unblock(&rport->dev);
} else
spin_unlock_irqrestore(shost->host_lock, flags);
return rport;
}
}
spin_unlock_irqrestore(shost->host_lock, flags);
rport = fc_rport_create(shost, channel, ids);
return rport;
}
void
fc_remote_port_delete(struct fc_rport *rport)
{
struct Scsi_Host *shost = rport_to_shost(rport);
unsigned long timeout = rport->dev_loss_tmo;
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
if (rport->port_state != FC_PORTSTATE_ONLINE) {
spin_unlock_irqrestore(shost->host_lock, flags);
return;
}
rport->port_state = FC_PORTSTATE_BLOCKED;
rport->flags |= FC_RPORT_DEVLOSS_PENDING;
spin_unlock_irqrestore(shost->host_lock, flags);
if (rport->roles & FC_PORT_ROLE_FCP_INITIATOR &&
shost->active_mode & MODE_TARGET)
fc_tgt_it_nexus_destroy(shost, (unsigned long)rport);
scsi_target_block(&rport->dev);
if ((rport->fast_io_fail_tmo != -1) &&
(rport->fast_io_fail_tmo < timeout))
fc_queue_devloss_work(shost, &rport->fail_io_work,
rport->fast_io_fail_tmo * HZ);
fc_queue_devloss_work(shost, &rport->dev_loss_work, timeout * HZ);
}
void
fc_remote_port_rolechg(struct fc_rport *rport, u32 roles)
{
struct Scsi_Host *shost = rport_to_shost(rport);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
unsigned long flags;
int create = 0;
int ret;
spin_lock_irqsave(shost->host_lock, flags);
if (roles & FC_PORT_ROLE_FCP_TARGET) {
if (rport->scsi_target_id == -1) {
rport->scsi_target_id = fc_host->next_target_id++;
create = 1;
} else if (!(rport->roles & FC_PORT_ROLE_FCP_TARGET))
create = 1;
} else if (shost->active_mode & MODE_TARGET) {
ret = fc_tgt_it_nexus_create(shost, (unsigned long)rport,
(char *)&rport->node_name);
if (ret)
printk(KERN_ERR "FC Remore Port tgt nexus failed %d\n",
ret);
}
rport->roles = roles;
spin_unlock_irqrestore(shost->host_lock, flags);
if (create) {
if (!cancel_delayed_work(&rport->fail_io_work))
fc_flush_devloss(shost);
if (!cancel_delayed_work(&rport->dev_loss_work))
fc_flush_devloss(shost);
spin_lock_irqsave(shost->host_lock, flags);
rport->flags &= ~(FC_RPORT_FAST_FAIL_TIMEDOUT |
FC_RPORT_DEVLOSS_PENDING);
spin_unlock_irqrestore(shost->host_lock, flags);
fc_flush_work(shost);
spin_lock_irqsave(shost->host_lock, flags);
rport->flags |= FC_RPORT_SCAN_PENDING;
scsi_queue_work(shost, &rport->scan_work);
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_target_unblock(&rport->dev);
}
}
static void
fc_timeout_deleted_rport(struct work_struct *work)
{
struct fc_rport *rport =
container_of(work, struct fc_rport, dev_loss_work.work);
struct Scsi_Host *shost = rport_to_shost(rport);
struct fc_internal *i = to_fc_internal(shost->transportt);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
unsigned long flags;
int do_callback = 0;
spin_lock_irqsave(shost->host_lock, flags);
rport->flags &= ~FC_RPORT_DEVLOSS_PENDING;
if ((rport->port_state == FC_PORTSTATE_ONLINE) &&
(rport->scsi_target_id != -1) &&
!(rport->roles & FC_PORT_ROLE_FCP_TARGET)) {
dev_printk(KERN_ERR, &rport->dev,
"blocked FC remote port time out: no longer"
" a FCP target, removing starget\n");
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_target_unblock(&rport->dev);
fc_queue_work(shost, &rport->stgt_delete_work);
return;
}
if (rport->port_state != FC_PORTSTATE_BLOCKED) {
spin_unlock_irqrestore(shost->host_lock, flags);
dev_printk(KERN_ERR, &rport->dev,
"blocked FC remote port time out: leaving"
" rport%s alone\n",
(rport->scsi_target_id != -1) ? " and starget" : "");
return;
}
if ((fc_host->tgtid_bind_type == FC_TGTID_BIND_NONE) ||
(rport->scsi_target_id == -1)) {
list_del(&rport->peers);
rport->port_state = FC_PORTSTATE_DELETED;
dev_printk(KERN_ERR, &rport->dev,
"blocked FC remote port time out: removing"
" rport%s\n",
(rport->scsi_target_id != -1) ? " and starget" : "");
fc_queue_work(shost, &rport->rport_delete_work);
spin_unlock_irqrestore(shost->host_lock, flags);
return;
}
dev_printk(KERN_ERR, &rport->dev,
"blocked FC remote port time out: removing target and "
"saving binding\n");
list_move_tail(&rport->peers, &fc_host->rport_bindings);
rport->maxframe_size = -1;
rport->supported_classes = FC_COS_UNSPECIFIED;
rport->roles = FC_PORT_ROLE_UNKNOWN;
rport->port_state = FC_PORTSTATE_NOTPRESENT;
rport->flags &= ~FC_RPORT_FAST_FAIL_TIMEDOUT;
spin_unlock_irqrestore(shost->host_lock, flags);
fc_terminate_rport_io(rport);
spin_lock_irqsave(shost->host_lock, flags);
if (rport->port_state == FC_PORTSTATE_NOTPRESENT) {
switch (fc_host->tgtid_bind_type) {
case FC_TGTID_BIND_BY_WWPN:
rport->node_name = -1;
rport->port_id = -1;
break;
case FC_TGTID_BIND_BY_WWNN:
rport->port_name = -1;
rport->port_id = -1;
break;
case FC_TGTID_BIND_BY_ID:
rport->node_name = -1;
rport->port_name = -1;
break;
case FC_TGTID_BIND_NONE:
break;
}
rport->flags |= FC_RPORT_DEVLOSS_CALLBK_DONE;
fc_queue_work(shost, &rport->stgt_delete_work);
do_callback = 1;
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (do_callback && i->f->dev_loss_tmo_callbk)
i->f->dev_loss_tmo_callbk(rport);
}
static void
fc_timeout_fail_rport_io(struct work_struct *work)
{
struct fc_rport *rport =
container_of(work, struct fc_rport, fail_io_work.work);
if (rport->port_state != FC_PORTSTATE_BLOCKED)
return;
rport->flags |= FC_RPORT_FAST_FAIL_TIMEDOUT;
fc_terminate_rport_io(rport);
}
static void
fc_scsi_scan_rport(struct work_struct *work)
{
struct fc_rport *rport =
container_of(work, struct fc_rport, scan_work);
struct Scsi_Host *shost = rport_to_shost(rport);
struct fc_internal *i = to_fc_internal(shost->transportt);
unsigned long flags;
if ((rport->port_state == FC_PORTSTATE_ONLINE) &&
(rport->roles & FC_PORT_ROLE_FCP_TARGET) &&
!(i->f->disable_target_scan)) {
scsi_scan_target(&rport->dev, rport->channel,
rport->scsi_target_id, SCAN_WILD_CARD, 1);
}
spin_lock_irqsave(shost->host_lock, flags);
rport->flags &= ~FC_RPORT_SCAN_PENDING;
spin_unlock_irqrestore(shost->host_lock, flags);
}
int fc_block_scsi_eh(struct scsi_cmnd *cmnd)
{
struct Scsi_Host *shost = cmnd->device->host;
struct fc_rport *rport = starget_to_rport(scsi_target(cmnd->device));
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
while (rport->port_state == FC_PORTSTATE_BLOCKED &&
!(rport->flags & FC_RPORT_FAST_FAIL_TIMEDOUT)) {
spin_unlock_irqrestore(shost->host_lock, flags);
msleep(1000);
spin_lock_irqsave(shost->host_lock, flags);
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (rport->flags & FC_RPORT_FAST_FAIL_TIMEDOUT)
return FAST_IO_FAIL;
return 0;
}
static int
fc_vport_setup(struct Scsi_Host *shost, int channel, struct device *pdev,
struct fc_vport_identifiers *ids, struct fc_vport **ret_vport)
{
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
struct fc_internal *fci = to_fc_internal(shost->transportt);
struct fc_vport *vport;
struct device *dev;
unsigned long flags;
size_t size;
int error;
*ret_vport = NULL;
if ( ! fci->f->vport_create)
return -ENOENT;
size = (sizeof(struct fc_vport) + fci->f->dd_fcvport_size);
vport = kzalloc(size, GFP_KERNEL);
if (unlikely(!vport)) {
printk(KERN_ERR "%s: allocation failure\n", __func__);
return -ENOMEM;
}
vport->vport_state = FC_VPORT_UNKNOWN;
vport->vport_last_state = FC_VPORT_UNKNOWN;
vport->node_name = ids->node_name;
vport->port_name = ids->port_name;
vport->roles = ids->roles;
vport->vport_type = ids->vport_type;
if (fci->f->dd_fcvport_size)
vport->dd_data = &vport[1];
vport->shost = shost;
vport->channel = channel;
vport->flags = FC_VPORT_CREATING;
INIT_WORK(&vport->vport_delete_work, fc_vport_sched_delete);
spin_lock_irqsave(shost->host_lock, flags);
if (fc_host->npiv_vports_inuse >= fc_host->max_npiv_vports) {
spin_unlock_irqrestore(shost->host_lock, flags);
kfree(vport);
return -ENOSPC;
}
fc_host->npiv_vports_inuse++;
vport->number = fc_host->next_vport_number++;
list_add_tail(&vport->peers, &fc_host->vports);
get_device(&shost->shost_gendev);
spin_unlock_irqrestore(shost->host_lock, flags);
dev = &vport->dev;
device_initialize(dev);
dev->parent = get_device(pdev);
dev->release = fc_vport_dev_release;
dev_set_name(dev, "vport-%d:%d-%d",
shost->host_no, channel, vport->number);
transport_setup_device(dev);
error = device_add(dev);
if (error) {
printk(KERN_ERR "FC Virtual Port device_add failed\n");
goto delete_vport;
}
transport_add_device(dev);
transport_configure_device(dev);
error = fci->f->vport_create(vport, ids->disable);
if (error) {
printk(KERN_ERR "FC Virtual Port LLDD Create failed\n");
goto delete_vport_all;
}
if (pdev != &shost->shost_gendev) {
error = sysfs_create_link(&shost->shost_gendev.kobj,
&dev->kobj, dev_name(dev));
if (error)
printk(KERN_ERR
"%s: Cannot create vport symlinks for "
"%s, err=%d\n",
__func__, dev_name(dev), error);
}
spin_lock_irqsave(shost->host_lock, flags);
vport->flags &= ~FC_VPORT_CREATING;
spin_unlock_irqrestore(shost->host_lock, flags);
dev_printk(KERN_NOTICE, pdev,
"%s created via shost%d channel %d\n", dev_name(dev),
shost->host_no, channel);
*ret_vport = vport;
return 0;
delete_vport_all:
transport_remove_device(dev);
device_del(dev);
delete_vport:
transport_destroy_device(dev);
spin_lock_irqsave(shost->host_lock, flags);
list_del(&vport->peers);
put_device(&shost->shost_gendev);
fc_host->npiv_vports_inuse--;
spin_unlock_irqrestore(shost->host_lock, flags);
put_device(dev->parent);
kfree(vport);
return error;
}
struct fc_vport *
fc_vport_create(struct Scsi_Host *shost, int channel,
struct fc_vport_identifiers *ids)
{
int stat;
struct fc_vport *vport;
stat = fc_vport_setup(shost, channel, &shost->shost_gendev,
ids, &vport);
return stat ? NULL : vport;
}
int
fc_vport_terminate(struct fc_vport *vport)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_host_attrs *fc_host = shost_to_fc_host(shost);
struct fc_internal *i = to_fc_internal(shost->transportt);
struct device *dev = &vport->dev;
unsigned long flags;
int stat;
if (i->f->vport_delete)
stat = i->f->vport_delete(vport);
else
stat = -ENOENT;
spin_lock_irqsave(shost->host_lock, flags);
vport->flags &= ~FC_VPORT_DELETING;
if (!stat) {
vport->flags |= FC_VPORT_DELETED;
list_del(&vport->peers);
fc_host->npiv_vports_inuse--;
put_device(&shost->shost_gendev);
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (stat)
return stat;
if (dev->parent != &shost->shost_gendev)
sysfs_remove_link(&shost->shost_gendev.kobj, dev_name(dev));
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
return 0;
}
static void
fc_vport_sched_delete(struct work_struct *work)
{
struct fc_vport *vport =
container_of(work, struct fc_vport, vport_delete_work);
int stat;
stat = fc_vport_terminate(vport);
if (stat)
dev_printk(KERN_ERR, vport->dev.parent,
"%s: %s could not be deleted created via "
"shost%d channel %d - error %d\n", __func__,
dev_name(&vport->dev), vport->shost->host_no,
vport->channel, stat);
}
static void
fc_destroy_bsgjob(struct fc_bsg_job *job)
{
unsigned long flags;
spin_lock_irqsave(&job->job_lock, flags);
if (job->ref_cnt) {
spin_unlock_irqrestore(&job->job_lock, flags);
return;
}
spin_unlock_irqrestore(&job->job_lock, flags);
put_device(job->dev);
kfree(job->request_payload.sg_list);
kfree(job->reply_payload.sg_list);
kfree(job);
}
static void
fc_bsg_jobdone(struct fc_bsg_job *job)
{
struct request *req = job->req;
struct request *rsp = req->next_rq;
int err;
err = job->req->errors = job->reply->result;
if (err < 0)
job->req->sense_len = sizeof(uint32_t);
else
job->req->sense_len = job->reply_len;
req->resid_len = 0;
if (rsp) {
WARN_ON(job->reply->reply_payload_rcv_len > rsp->resid_len);
rsp->resid_len -= min(job->reply->reply_payload_rcv_len,
rsp->resid_len);
}
blk_complete_request(req);
}
static void fc_bsg_softirq_done(struct request *rq)
{
struct fc_bsg_job *job = rq->special;
unsigned long flags;
spin_lock_irqsave(&job->job_lock, flags);
job->state_flags |= FC_RQST_STATE_DONE;
job->ref_cnt--;
spin_unlock_irqrestore(&job->job_lock, flags);
blk_end_request_all(rq, rq->errors);
fc_destroy_bsgjob(job);
}
static enum blk_eh_timer_return
fc_bsg_job_timeout(struct request *req)
{
struct fc_bsg_job *job = (void *) req->special;
struct Scsi_Host *shost = job->shost;
struct fc_internal *i = to_fc_internal(shost->transportt);
unsigned long flags;
int err = 0, done = 0;
if (job->rport && job->rport->port_state == FC_PORTSTATE_BLOCKED)
return BLK_EH_RESET_TIMER;
spin_lock_irqsave(&job->job_lock, flags);
if (job->state_flags & FC_RQST_STATE_DONE)
done = 1;
else
job->ref_cnt++;
spin_unlock_irqrestore(&job->job_lock, flags);
if (!done && i->f->bsg_timeout) {
err = i->f->bsg_timeout(job);
if (err == -EAGAIN) {
job->ref_cnt--;
return BLK_EH_RESET_TIMER;
} else if (err)
printk(KERN_ERR "ERROR: FC BSG request timeout - LLD "
"abort failed with status %d\n", err);
}
if (done)
return BLK_EH_NOT_HANDLED;
else
return BLK_EH_HANDLED;
}
static int
fc_bsg_map_buffer(struct fc_bsg_buffer *buf, struct request *req)
{
size_t sz = (sizeof(struct scatterlist) * req->nr_phys_segments);
BUG_ON(!req->nr_phys_segments);
buf->sg_list = kzalloc(sz, GFP_KERNEL);
if (!buf->sg_list)
return -ENOMEM;
sg_init_table(buf->sg_list, req->nr_phys_segments);
buf->sg_cnt = blk_rq_map_sg(req->q, req, buf->sg_list);
buf->payload_len = blk_rq_bytes(req);
return 0;
}
static int
fc_req_to_bsgjob(struct Scsi_Host *shost, struct fc_rport *rport,
struct request *req)
{
struct fc_internal *i = to_fc_internal(shost->transportt);
struct request *rsp = req->next_rq;
struct fc_bsg_job *job;
int ret;
BUG_ON(req->special);
job = kzalloc(sizeof(struct fc_bsg_job) + i->f->dd_bsg_size,
GFP_KERNEL);
if (!job)
return -ENOMEM;
req->special = job;
job->shost = shost;
job->rport = rport;
job->req = req;
if (i->f->dd_bsg_size)
job->dd_data = (void *)&job[1];
spin_lock_init(&job->job_lock);
job->request = (struct fc_bsg_request *)req->cmd;
job->request_len = req->cmd_len;
job->reply = req->sense;
job->reply_len = SCSI_SENSE_BUFFERSIZE;
if (req->bio) {
ret = fc_bsg_map_buffer(&job->request_payload, req);
if (ret)
goto failjob_rls_job;
}
if (rsp && rsp->bio) {
ret = fc_bsg_map_buffer(&job->reply_payload, rsp);
if (ret)
goto failjob_rls_rqst_payload;
}
job->job_done = fc_bsg_jobdone;
if (rport)
job->dev = &rport->dev;
else
job->dev = &shost->shost_gendev;
get_device(job->dev);
job->ref_cnt = 1;
return 0;
failjob_rls_rqst_payload:
kfree(job->request_payload.sg_list);
failjob_rls_job:
kfree(job);
return -ENOMEM;
}
static enum fc_dispatch_result
fc_bsg_host_dispatch(struct request_queue *q, struct Scsi_Host *shost,
struct fc_bsg_job *job)
{
struct fc_internal *i = to_fc_internal(shost->transportt);
int cmdlen = sizeof(uint32_t);
int ret;
switch (job->request->msgcode) {
case FC_BSG_HST_ADD_RPORT:
cmdlen += sizeof(struct fc_bsg_host_add_rport);
break;
case FC_BSG_HST_DEL_RPORT:
cmdlen += sizeof(struct fc_bsg_host_del_rport);
break;
case FC_BSG_HST_ELS_NOLOGIN:
cmdlen += sizeof(struct fc_bsg_host_els);
if ((!job->request_payload.payload_len) ||
(!job->reply_payload.payload_len)) {
ret = -EINVAL;
goto fail_host_msg;
}
break;
case FC_BSG_HST_CT:
cmdlen += sizeof(struct fc_bsg_host_ct);
if ((!job->request_payload.payload_len) ||
(!job->reply_payload.payload_len)) {
ret = -EINVAL;
goto fail_host_msg;
}
break;
case FC_BSG_HST_VENDOR:
cmdlen += sizeof(struct fc_bsg_host_vendor);
if ((shost->hostt->vendor_id == 0L) ||
(job->request->rqst_data.h_vendor.vendor_id !=
shost->hostt->vendor_id)) {
ret = -ESRCH;
goto fail_host_msg;
}
break;
default:
ret = -EBADR;
goto fail_host_msg;
}
if (job->request_len < cmdlen) {
ret = -ENOMSG;
goto fail_host_msg;
}
ret = i->f->bsg_request(job);
if (!ret)
return FC_DISPATCH_UNLOCKED;
fail_host_msg:
BUG_ON(job->reply_len < sizeof(uint32_t));
job->reply->reply_payload_rcv_len = 0;
job->reply->result = ret;
job->reply_len = sizeof(uint32_t);
fc_bsg_jobdone(job);
return FC_DISPATCH_UNLOCKED;
}
static void
fc_bsg_goose_queue(struct fc_rport *rport)
{
if (!rport->rqst_q)
return;
get_device(&rport->dev);
blk_run_queue_async(rport->rqst_q);
put_device(&rport->dev);
}
static enum fc_dispatch_result
fc_bsg_rport_dispatch(struct request_queue *q, struct Scsi_Host *shost,
struct fc_rport *rport, struct fc_bsg_job *job)
{
struct fc_internal *i = to_fc_internal(shost->transportt);
int cmdlen = sizeof(uint32_t);
int ret;
switch (job->request->msgcode) {
case FC_BSG_RPT_ELS:
cmdlen += sizeof(struct fc_bsg_rport_els);
goto check_bidi;
case FC_BSG_RPT_CT:
cmdlen += sizeof(struct fc_bsg_rport_ct);
check_bidi:
if ((!job->request_payload.payload_len) ||
(!job->reply_payload.payload_len)) {
ret = -EINVAL;
goto fail_rport_msg;
}
break;
default:
ret = -EBADR;
goto fail_rport_msg;
}
if (job->request_len < cmdlen) {
ret = -ENOMSG;
goto fail_rport_msg;
}
ret = i->f->bsg_request(job);
if (!ret)
return FC_DISPATCH_UNLOCKED;
fail_rport_msg:
BUG_ON(job->reply_len < sizeof(uint32_t));
job->reply->reply_payload_rcv_len = 0;
job->reply->result = ret;
job->reply_len = sizeof(uint32_t);
fc_bsg_jobdone(job);
return FC_DISPATCH_UNLOCKED;
}
static void
fc_bsg_request_handler(struct request_queue *q, struct Scsi_Host *shost,
struct fc_rport *rport, struct device *dev)
{
struct request *req;
struct fc_bsg_job *job;
enum fc_dispatch_result ret;
if (!get_device(dev))
return;
while (1) {
if (rport && (rport->port_state == FC_PORTSTATE_BLOCKED) &&
!(rport->flags & FC_RPORT_FAST_FAIL_TIMEDOUT))
break;
req = blk_fetch_request(q);
if (!req)
break;
if (rport && (rport->port_state != FC_PORTSTATE_ONLINE)) {
req->errors = -ENXIO;
spin_unlock_irq(q->queue_lock);
blk_end_request_all(req, -ENXIO);
spin_lock_irq(q->queue_lock);
continue;
}
spin_unlock_irq(q->queue_lock);
ret = fc_req_to_bsgjob(shost, rport, req);
if (ret) {
req->errors = ret;
blk_end_request_all(req, ret);
spin_lock_irq(q->queue_lock);
continue;
}
job = req->special;
if (job->request_len < sizeof(uint32_t)) {
BUG_ON(job->reply_len < sizeof(uint32_t));
job->reply->reply_payload_rcv_len = 0;
job->reply->result = -ENOMSG;
job->reply_len = sizeof(uint32_t);
fc_bsg_jobdone(job);
spin_lock_irq(q->queue_lock);
continue;
}
if (rport)
ret = fc_bsg_rport_dispatch(q, shost, rport, job);
else
ret = fc_bsg_host_dispatch(q, shost, job);
if (ret == FC_DISPATCH_BREAK)
break;
if (ret == FC_DISPATCH_UNLOCKED)
spin_lock_irq(q->queue_lock);
}
spin_unlock_irq(q->queue_lock);
put_device(dev);
spin_lock_irq(q->queue_lock);
}
static void
fc_bsg_host_handler(struct request_queue *q)
{
struct Scsi_Host *shost = q->queuedata;
fc_bsg_request_handler(q, shost, NULL, &shost->shost_gendev);
}
static void
fc_bsg_rport_handler(struct request_queue *q)
{
struct fc_rport *rport = q->queuedata;
struct Scsi_Host *shost = rport_to_shost(rport);
fc_bsg_request_handler(q, shost, rport, &rport->dev);
}
static int
fc_bsg_hostadd(struct Scsi_Host *shost, struct fc_host_attrs *fc_host)
{
struct device *dev = &shost->shost_gendev;
struct fc_internal *i = to_fc_internal(shost->transportt);
struct request_queue *q;
int err;
char bsg_name[20];
fc_host->rqst_q = NULL;
if (!i->f->bsg_request)
return -ENOTSUPP;
snprintf(bsg_name, sizeof(bsg_name),
"fc_host%d", shost->host_no);
q = __scsi_alloc_queue(shost, fc_bsg_host_handler);
if (!q) {
printk(KERN_ERR "fc_host%d: bsg interface failed to "
"initialize - no request queue\n",
shost->host_no);
return -ENOMEM;
}
q->queuedata = shost;
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, q);
blk_queue_softirq_done(q, fc_bsg_softirq_done);
blk_queue_rq_timed_out(q, fc_bsg_job_timeout);
blk_queue_rq_timeout(q, FC_DEFAULT_BSG_TIMEOUT);
err = bsg_register_queue(q, dev, bsg_name, NULL);
if (err) {
printk(KERN_ERR "fc_host%d: bsg interface failed to "
"initialize - register queue\n",
shost->host_no);
blk_cleanup_queue(q);
return err;
}
fc_host->rqst_q = q;
return 0;
}
static int
fc_bsg_rportadd(struct Scsi_Host *shost, struct fc_rport *rport)
{
struct device *dev = &rport->dev;
struct fc_internal *i = to_fc_internal(shost->transportt);
struct request_queue *q;
int err;
rport->rqst_q = NULL;
if (!i->f->bsg_request)
return -ENOTSUPP;
q = __scsi_alloc_queue(shost, fc_bsg_rport_handler);
if (!q) {
printk(KERN_ERR "%s: bsg interface failed to "
"initialize - no request queue\n",
dev->kobj.name);
return -ENOMEM;
}
q->queuedata = rport;
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, q);
blk_queue_softirq_done(q, fc_bsg_softirq_done);
blk_queue_rq_timed_out(q, fc_bsg_job_timeout);
blk_queue_rq_timeout(q, BLK_DEFAULT_SG_TIMEOUT);
err = bsg_register_queue(q, dev, NULL, NULL);
if (err) {
printk(KERN_ERR "%s: bsg interface failed to "
"initialize - register queue\n",
dev->kobj.name);
blk_cleanup_queue(q);
return err;
}
rport->rqst_q = q;
return 0;
}
static void
fc_bsg_remove(struct request_queue *q)
{
struct request *req;
int counts;
if (q) {
spin_lock_irq(q->queue_lock);
blk_stop_queue(q);
while (1) {
req = blk_fetch_request(q);
counts = q->rq.count[0] + q->rq.count[1] +
q->rq.starved[0] + q->rq.starved[1];
spin_unlock_irq(q->queue_lock);
if (counts == 0)
break;
if (req) {
req->errors = -ENXIO;
blk_end_request_all(req, -ENXIO);
}
msleep(200);
spin_lock_irq(q->queue_lock);
}
bsg_unregister_queue(q);
blk_cleanup_queue(q);
}
}
