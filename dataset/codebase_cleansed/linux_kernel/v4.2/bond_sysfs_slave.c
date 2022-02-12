static ssize_t state_show(struct slave *slave, char *buf)
{
switch (bond_slave_state(slave)) {
case BOND_STATE_ACTIVE:
return sprintf(buf, "active\n");
case BOND_STATE_BACKUP:
return sprintf(buf, "backup\n");
default:
return sprintf(buf, "UNKNOWN\n");
}
}
static ssize_t mii_status_show(struct slave *slave, char *buf)
{
return sprintf(buf, "%s\n", bond_slave_link_status(slave->link));
}
static ssize_t link_failure_count_show(struct slave *slave, char *buf)
{
return sprintf(buf, "%d\n", slave->link_failure_count);
}
static ssize_t perm_hwaddr_show(struct slave *slave, char *buf)
{
return sprintf(buf, "%pM\n", slave->perm_hwaddr);
}
static ssize_t queue_id_show(struct slave *slave, char *buf)
{
return sprintf(buf, "%d\n", slave->queue_id);
}
static ssize_t ad_aggregator_id_show(struct slave *slave, char *buf)
{
const struct aggregator *agg;
if (BOND_MODE(slave->bond) == BOND_MODE_8023AD) {
agg = SLAVE_AD_INFO(slave)->port.aggregator;
if (agg)
return sprintf(buf, "%d\n",
agg->aggregator_identifier);
}
return sprintf(buf, "N/A\n");
}
static ssize_t ad_actor_oper_port_state_show(struct slave *slave, char *buf)
{
const struct port *ad_port;
if (BOND_MODE(slave->bond) == BOND_MODE_8023AD) {
ad_port = &SLAVE_AD_INFO(slave)->port;
if (ad_port->aggregator)
return sprintf(buf, "%u\n",
ad_port->actor_oper_port_state);
}
return sprintf(buf, "N/A\n");
}
static ssize_t ad_partner_oper_port_state_show(struct slave *slave, char *buf)
{
const struct port *ad_port;
if (BOND_MODE(slave->bond) == BOND_MODE_8023AD) {
ad_port = &SLAVE_AD_INFO(slave)->port;
if (ad_port->aggregator)
return sprintf(buf, "%u\n",
ad_port->partner_oper.port_state);
}
return sprintf(buf, "N/A\n");
}
static ssize_t slave_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct slave_attribute *slave_attr = to_slave_attr(attr);
struct slave *slave = to_slave(kobj);
return slave_attr->show(slave, buf);
}
int bond_sysfs_slave_add(struct slave *slave)
{
const struct slave_attribute **a;
int err;
err = kobject_init_and_add(&slave->kobj, &slave_ktype,
&(slave->dev->dev.kobj), "bonding_slave");
if (err)
return err;
for (a = slave_attrs; *a; ++a) {
err = sysfs_create_file(&slave->kobj, &((*a)->attr));
if (err) {
kobject_put(&slave->kobj);
return err;
}
}
return 0;
}
void bond_sysfs_slave_del(struct slave *slave)
{
const struct slave_attribute **a;
for (a = slave_attrs; *a; ++a)
sysfs_remove_file(&slave->kobj, &((*a)->attr));
kobject_put(&slave->kobj);
}
