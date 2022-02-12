static void clear_evtchn_to_irq_row(unsigned row)
{
unsigned col;
for (col = 0; col < EVTCHN_PER_ROW; col++)
evtchn_to_irq[row][col] = -1;
}
static void clear_evtchn_to_irq_all(void)
{
unsigned row;
for (row = 0; row < EVTCHN_ROW(xen_evtchn_max_channels()); row++) {
if (evtchn_to_irq[row] == NULL)
continue;
clear_evtchn_to_irq_row(row);
}
}
static int set_evtchn_to_irq(unsigned evtchn, unsigned irq)
{
unsigned row;
unsigned col;
if (evtchn >= xen_evtchn_max_channels())
return -EINVAL;
row = EVTCHN_ROW(evtchn);
col = EVTCHN_COL(evtchn);
if (evtchn_to_irq[row] == NULL) {
if (irq == -1)
return 0;
evtchn_to_irq[row] = (int *)get_zeroed_page(GFP_KERNEL);
if (evtchn_to_irq[row] == NULL)
return -ENOMEM;
clear_evtchn_to_irq_row(row);
}
evtchn_to_irq[EVTCHN_ROW(evtchn)][EVTCHN_COL(evtchn)] = irq;
return 0;
}
int get_evtchn_to_irq(unsigned evtchn)
{
if (evtchn >= xen_evtchn_max_channels())
return -1;
if (evtchn_to_irq[EVTCHN_ROW(evtchn)] == NULL)
return -1;
return evtchn_to_irq[EVTCHN_ROW(evtchn)][EVTCHN_COL(evtchn)];
}
struct irq_info *info_for_irq(unsigned irq)
{
return irq_get_handler_data(irq);
}
static int xen_irq_info_common_setup(struct irq_info *info,
unsigned irq,
enum xen_irq_type type,
unsigned evtchn,
unsigned short cpu)
{
int ret;
BUG_ON(info->type != IRQT_UNBOUND && info->type != type);
info->type = type;
info->irq = irq;
info->evtchn = evtchn;
info->cpu = cpu;
ret = set_evtchn_to_irq(evtchn, irq);
if (ret < 0)
return ret;
irq_clear_status_flags(irq, IRQ_NOREQUEST|IRQ_NOAUTOEN);
return xen_evtchn_port_setup(info);
}
static int xen_irq_info_evtchn_setup(unsigned irq,
unsigned evtchn)
{
struct irq_info *info = info_for_irq(irq);
return xen_irq_info_common_setup(info, irq, IRQT_EVTCHN, evtchn, 0);
}
static int xen_irq_info_ipi_setup(unsigned cpu,
unsigned irq,
unsigned evtchn,
enum ipi_vector ipi)
{
struct irq_info *info = info_for_irq(irq);
info->u.ipi = ipi;
per_cpu(ipi_to_irq, cpu)[ipi] = irq;
return xen_irq_info_common_setup(info, irq, IRQT_IPI, evtchn, 0);
}
static int xen_irq_info_virq_setup(unsigned cpu,
unsigned irq,
unsigned evtchn,
unsigned virq)
{
struct irq_info *info = info_for_irq(irq);
info->u.virq = virq;
per_cpu(virq_to_irq, cpu)[virq] = irq;
return xen_irq_info_common_setup(info, irq, IRQT_VIRQ, evtchn, 0);
}
static int xen_irq_info_pirq_setup(unsigned irq,
unsigned evtchn,
unsigned pirq,
unsigned gsi,
uint16_t domid,
unsigned char flags)
{
struct irq_info *info = info_for_irq(irq);
info->u.pirq.pirq = pirq;
info->u.pirq.gsi = gsi;
info->u.pirq.domid = domid;
info->u.pirq.flags = flags;
return xen_irq_info_common_setup(info, irq, IRQT_PIRQ, evtchn, 0);
}
static void xen_irq_info_cleanup(struct irq_info *info)
{
set_evtchn_to_irq(info->evtchn, -1);
info->evtchn = 0;
}
unsigned int evtchn_from_irq(unsigned irq)
{
if (unlikely(WARN(irq >= nr_irqs, "Invalid irq %d!\n", irq)))
return 0;
return info_for_irq(irq)->evtchn;
}
unsigned irq_from_evtchn(unsigned int evtchn)
{
return get_evtchn_to_irq(evtchn);
}
int irq_from_virq(unsigned int cpu, unsigned int virq)
{
return per_cpu(virq_to_irq, cpu)[virq];
}
static enum ipi_vector ipi_from_irq(unsigned irq)
{
struct irq_info *info = info_for_irq(irq);
BUG_ON(info == NULL);
BUG_ON(info->type != IRQT_IPI);
return info->u.ipi;
}
static unsigned virq_from_irq(unsigned irq)
{
struct irq_info *info = info_for_irq(irq);
BUG_ON(info == NULL);
BUG_ON(info->type != IRQT_VIRQ);
return info->u.virq;
}
static unsigned pirq_from_irq(unsigned irq)
{
struct irq_info *info = info_for_irq(irq);
BUG_ON(info == NULL);
BUG_ON(info->type != IRQT_PIRQ);
return info->u.pirq.pirq;
}
static enum xen_irq_type type_from_irq(unsigned irq)
{
return info_for_irq(irq)->type;
}
unsigned cpu_from_irq(unsigned irq)
{
return info_for_irq(irq)->cpu;
}
unsigned int cpu_from_evtchn(unsigned int evtchn)
{
int irq = get_evtchn_to_irq(evtchn);
unsigned ret = 0;
if (irq != -1)
ret = cpu_from_irq(irq);
return ret;
}
static bool pirq_check_eoi_map(unsigned irq)
{
return test_bit(pirq_from_irq(irq), pirq_eoi_map);
}
static bool pirq_needs_eoi_flag(unsigned irq)
{
struct irq_info *info = info_for_irq(irq);
BUG_ON(info->type != IRQT_PIRQ);
return info->u.pirq.flags & PIRQ_NEEDS_EOI;
}
static void bind_evtchn_to_cpu(unsigned int chn, unsigned int cpu)
{
int irq = get_evtchn_to_irq(chn);
struct irq_info *info = info_for_irq(irq);
BUG_ON(irq == -1);
#ifdef CONFIG_SMP
cpumask_copy(irq_get_irq_data(irq)->affinity, cpumask_of(cpu));
#endif
xen_evtchn_port_bind_to_cpu(info, cpu);
info->cpu = cpu;
}
static void xen_evtchn_mask_all(void)
{
unsigned int evtchn;
for (evtchn = 0; evtchn < xen_evtchn_nr_channels(); evtchn++)
mask_evtchn(evtchn);
}
void notify_remote_via_irq(int irq)
{
int evtchn = evtchn_from_irq(irq);
if (VALID_EVTCHN(evtchn))
notify_remote_via_evtchn(evtchn);
}
static void xen_irq_init(unsigned irq)
{
struct irq_info *info;
#ifdef CONFIG_SMP
cpumask_copy(irq_get_irq_data(irq)->affinity, cpumask_of(0));
#endif
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (info == NULL)
panic("Unable to allocate metadata for IRQ%d\n", irq);
info->type = IRQT_UNBOUND;
info->refcnt = -1;
irq_set_handler_data(irq, info);
list_add_tail(&info->list, &xen_irq_list_head);
}
static int __must_check xen_allocate_irqs_dynamic(int nvec)
{
int i, irq = irq_alloc_descs(-1, 0, nvec, -1);
if (irq >= 0) {
for (i = 0; i < nvec; i++)
xen_irq_init(irq + i);
}
return irq;
}
static inline int __must_check xen_allocate_irq_dynamic(void)
{
return xen_allocate_irqs_dynamic(1);
}
static int __must_check xen_allocate_irq_gsi(unsigned gsi)
{
int irq;
if (xen_pv_domain() && !xen_initial_domain())
return xen_allocate_irq_dynamic();
if (gsi < NR_IRQS_LEGACY)
irq = gsi;
else
irq = irq_alloc_desc_at(gsi, -1);
xen_irq_init(irq);
return irq;
}
static void xen_free_irq(unsigned irq)
{
struct irq_info *info = irq_get_handler_data(irq);
if (WARN_ON(!info))
return;
list_del(&info->list);
irq_set_handler_data(irq, NULL);
WARN_ON(info->refcnt > 0);
kfree(info);
if (irq < NR_IRQS_LEGACY)
return;
irq_free_desc(irq);
}
static void xen_evtchn_close(unsigned int port)
{
struct evtchn_close close;
close.port = port;
if (HYPERVISOR_event_channel_op(EVTCHNOP_close, &close) != 0)
BUG();
}
static void pirq_query_unmask(int irq)
{
struct physdev_irq_status_query irq_status;
struct irq_info *info = info_for_irq(irq);
BUG_ON(info->type != IRQT_PIRQ);
irq_status.irq = pirq_from_irq(irq);
if (HYPERVISOR_physdev_op(PHYSDEVOP_irq_status_query, &irq_status))
irq_status.flags = 0;
info->u.pirq.flags &= ~PIRQ_NEEDS_EOI;
if (irq_status.flags & XENIRQSTAT_needs_eoi)
info->u.pirq.flags |= PIRQ_NEEDS_EOI;
}
static void eoi_pirq(struct irq_data *data)
{
int evtchn = evtchn_from_irq(data->irq);
struct physdev_eoi eoi = { .irq = pirq_from_irq(data->irq) };
int rc = 0;
irq_move_irq(data);
if (VALID_EVTCHN(evtchn))
clear_evtchn(evtchn);
if (pirq_needs_eoi(data->irq)) {
rc = HYPERVISOR_physdev_op(PHYSDEVOP_eoi, &eoi);
WARN_ON(rc);
}
}
static void mask_ack_pirq(struct irq_data *data)
{
disable_dynirq(data);
eoi_pirq(data);
}
static unsigned int __startup_pirq(unsigned int irq)
{
struct evtchn_bind_pirq bind_pirq;
struct irq_info *info = info_for_irq(irq);
int evtchn = evtchn_from_irq(irq);
int rc;
BUG_ON(info->type != IRQT_PIRQ);
if (VALID_EVTCHN(evtchn))
goto out;
bind_pirq.pirq = pirq_from_irq(irq);
bind_pirq.flags = info->u.pirq.flags & PIRQ_SHAREABLE ?
BIND_PIRQ__WILL_SHARE : 0;
rc = HYPERVISOR_event_channel_op(EVTCHNOP_bind_pirq, &bind_pirq);
if (rc != 0) {
pr_warn("Failed to obtain physical IRQ %d\n", irq);
return 0;
}
evtchn = bind_pirq.port;
pirq_query_unmask(irq);
rc = set_evtchn_to_irq(evtchn, irq);
if (rc != 0) {
pr_err("irq%d: Failed to set port to irq mapping (%d)\n",
irq, rc);
xen_evtchn_close(evtchn);
return 0;
}
bind_evtchn_to_cpu(evtchn, 0);
info->evtchn = evtchn;
out:
unmask_evtchn(evtchn);
eoi_pirq(irq_get_irq_data(irq));
return 0;
}
static unsigned int startup_pirq(struct irq_data *data)
{
return __startup_pirq(data->irq);
}
static void shutdown_pirq(struct irq_data *data)
{
unsigned int irq = data->irq;
struct irq_info *info = info_for_irq(irq);
unsigned evtchn = evtchn_from_irq(irq);
BUG_ON(info->type != IRQT_PIRQ);
if (!VALID_EVTCHN(evtchn))
return;
mask_evtchn(evtchn);
xen_evtchn_close(evtchn);
xen_irq_info_cleanup(info);
}
static void enable_pirq(struct irq_data *data)
{
startup_pirq(data);
}
static void disable_pirq(struct irq_data *data)
{
disable_dynirq(data);
}
int xen_irq_from_gsi(unsigned gsi)
{
struct irq_info *info;
list_for_each_entry(info, &xen_irq_list_head, list) {
if (info->type != IRQT_PIRQ)
continue;
if (info->u.pirq.gsi == gsi)
return info->irq;
}
return -1;
}
static void __unbind_from_irq(unsigned int irq)
{
int evtchn = evtchn_from_irq(irq);
struct irq_info *info = irq_get_handler_data(irq);
if (info->refcnt > 0) {
info->refcnt--;
if (info->refcnt != 0)
return;
}
if (VALID_EVTCHN(evtchn)) {
unsigned int cpu = cpu_from_irq(irq);
xen_evtchn_close(evtchn);
switch (type_from_irq(irq)) {
case IRQT_VIRQ:
per_cpu(virq_to_irq, cpu)[virq_from_irq(irq)] = -1;
break;
case IRQT_IPI:
per_cpu(ipi_to_irq, cpu)[ipi_from_irq(irq)] = -1;
break;
default:
break;
}
xen_irq_info_cleanup(info);
}
BUG_ON(info_for_irq(irq)->type == IRQT_UNBOUND);
xen_free_irq(irq);
}
int xen_bind_pirq_gsi_to_irq(unsigned gsi,
unsigned pirq, int shareable, char *name)
{
int irq = -1;
struct physdev_irq irq_op;
int ret;
mutex_lock(&irq_mapping_update_lock);
irq = xen_irq_from_gsi(gsi);
if (irq != -1) {
pr_info("%s: returning irq %d for gsi %u\n",
__func__, irq, gsi);
goto out;
}
irq = xen_allocate_irq_gsi(gsi);
if (irq < 0)
goto out;
irq_op.irq = irq;
irq_op.vector = 0;
if (xen_initial_domain() &&
HYPERVISOR_physdev_op(PHYSDEVOP_alloc_irq_vector, &irq_op)) {
xen_free_irq(irq);
irq = -ENOSPC;
goto out;
}
ret = xen_irq_info_pirq_setup(irq, 0, pirq, gsi, DOMID_SELF,
shareable ? PIRQ_SHAREABLE : 0);
if (ret < 0) {
__unbind_from_irq(irq);
irq = ret;
goto out;
}
pirq_query_unmask(irq);
if (shareable)
irq_set_chip_and_handler_name(irq, &xen_pirq_chip,
handle_fasteoi_irq, name);
else
irq_set_chip_and_handler_name(irq, &xen_pirq_chip,
handle_edge_irq, name);
out:
mutex_unlock(&irq_mapping_update_lock);
return irq;
}
int xen_allocate_pirq_msi(struct pci_dev *dev, struct msi_desc *msidesc)
{
int rc;
struct physdev_get_free_pirq op_get_free_pirq;
op_get_free_pirq.type = MAP_PIRQ_TYPE_MSI;
rc = HYPERVISOR_physdev_op(PHYSDEVOP_get_free_pirq, &op_get_free_pirq);
WARN_ONCE(rc == -ENOSYS,
"hypervisor does not support the PHYSDEVOP_get_free_pirq interface\n");
return rc ? -1 : op_get_free_pirq.pirq;
}
int xen_bind_pirq_msi_to_irq(struct pci_dev *dev, struct msi_desc *msidesc,
int pirq, int nvec, const char *name, domid_t domid)
{
int i, irq, ret;
mutex_lock(&irq_mapping_update_lock);
irq = xen_allocate_irqs_dynamic(nvec);
if (irq < 0)
goto out;
for (i = 0; i < nvec; i++) {
irq_set_chip_and_handler_name(irq + i, &xen_pirq_chip, handle_edge_irq, name);
ret = xen_irq_info_pirq_setup(irq + i, 0, pirq + i, 0, domid,
i == 0 ? 0 : PIRQ_MSI_GROUP);
if (ret < 0)
goto error_irq;
}
ret = irq_set_msi_desc(irq, msidesc);
if (ret < 0)
goto error_irq;
out:
mutex_unlock(&irq_mapping_update_lock);
return irq;
error_irq:
for (; i >= 0; i--)
__unbind_from_irq(irq + i);
mutex_unlock(&irq_mapping_update_lock);
return ret;
}
int xen_destroy_irq(int irq)
{
struct physdev_unmap_pirq unmap_irq;
struct irq_info *info = info_for_irq(irq);
int rc = -ENOENT;
mutex_lock(&irq_mapping_update_lock);
if (xen_initial_domain() && !(info->u.pirq.flags & PIRQ_MSI_GROUP)) {
unmap_irq.pirq = info->u.pirq.pirq;
unmap_irq.domid = info->u.pirq.domid;
rc = HYPERVISOR_physdev_op(PHYSDEVOP_unmap_pirq, &unmap_irq);
if ((rc == -ESRCH && info->u.pirq.domid != DOMID_SELF))
pr_info("domain %d does not have %d anymore\n",
info->u.pirq.domid, info->u.pirq.pirq);
else if (rc) {
pr_warn("unmap irq failed %d\n", rc);
goto out;
}
}
xen_free_irq(irq);
out:
mutex_unlock(&irq_mapping_update_lock);
return rc;
}
int xen_irq_from_pirq(unsigned pirq)
{
int irq;
struct irq_info *info;
mutex_lock(&irq_mapping_update_lock);
list_for_each_entry(info, &xen_irq_list_head, list) {
if (info->type != IRQT_PIRQ)
continue;
irq = info->irq;
if (info->u.pirq.pirq == pirq)
goto out;
}
irq = -1;
out:
mutex_unlock(&irq_mapping_update_lock);
return irq;
}
int xen_pirq_from_irq(unsigned irq)
{
return pirq_from_irq(irq);
}
int bind_evtchn_to_irq(unsigned int evtchn)
{
int irq;
int ret;
if (evtchn >= xen_evtchn_max_channels())
return -ENOMEM;
mutex_lock(&irq_mapping_update_lock);
irq = get_evtchn_to_irq(evtchn);
if (irq == -1) {
irq = xen_allocate_irq_dynamic();
if (irq < 0)
goto out;
irq_set_chip_and_handler_name(irq, &xen_dynamic_chip,
handle_edge_irq, "event");
ret = xen_irq_info_evtchn_setup(irq, evtchn);
if (ret < 0) {
__unbind_from_irq(irq);
irq = ret;
goto out;
}
bind_evtchn_to_cpu(evtchn, 0);
} else {
struct irq_info *info = info_for_irq(irq);
WARN_ON(info == NULL || info->type != IRQT_EVTCHN);
}
out:
mutex_unlock(&irq_mapping_update_lock);
return irq;
}
static int bind_ipi_to_irq(unsigned int ipi, unsigned int cpu)
{
struct evtchn_bind_ipi bind_ipi;
int evtchn, irq;
int ret;
mutex_lock(&irq_mapping_update_lock);
irq = per_cpu(ipi_to_irq, cpu)[ipi];
if (irq == -1) {
irq = xen_allocate_irq_dynamic();
if (irq < 0)
goto out;
irq_set_chip_and_handler_name(irq, &xen_percpu_chip,
handle_percpu_irq, "ipi");
bind_ipi.vcpu = cpu;
if (HYPERVISOR_event_channel_op(EVTCHNOP_bind_ipi,
&bind_ipi) != 0)
BUG();
evtchn = bind_ipi.port;
ret = xen_irq_info_ipi_setup(cpu, irq, evtchn, ipi);
if (ret < 0) {
__unbind_from_irq(irq);
irq = ret;
goto out;
}
bind_evtchn_to_cpu(evtchn, cpu);
} else {
struct irq_info *info = info_for_irq(irq);
WARN_ON(info == NULL || info->type != IRQT_IPI);
}
out:
mutex_unlock(&irq_mapping_update_lock);
return irq;
}
int bind_interdomain_evtchn_to_irq(unsigned int remote_domain,
unsigned int remote_port)
{
struct evtchn_bind_interdomain bind_interdomain;
int err;
bind_interdomain.remote_dom = remote_domain;
bind_interdomain.remote_port = remote_port;
err = HYPERVISOR_event_channel_op(EVTCHNOP_bind_interdomain,
&bind_interdomain);
return err ? : bind_evtchn_to_irq(bind_interdomain.local_port);
}
static int find_virq(unsigned int virq, unsigned int cpu)
{
struct evtchn_status status;
int port, rc = -ENOENT;
memset(&status, 0, sizeof(status));
for (port = 0; port < xen_evtchn_max_channels(); port++) {
status.dom = DOMID_SELF;
status.port = port;
rc = HYPERVISOR_event_channel_op(EVTCHNOP_status, &status);
if (rc < 0)
continue;
if (status.status != EVTCHNSTAT_virq)
continue;
if (status.u.virq == virq && status.vcpu == cpu) {
rc = port;
break;
}
}
return rc;
}
unsigned xen_evtchn_nr_channels(void)
{
return evtchn_ops->nr_channels();
}
int bind_virq_to_irq(unsigned int virq, unsigned int cpu)
{
struct evtchn_bind_virq bind_virq;
int evtchn, irq, ret;
mutex_lock(&irq_mapping_update_lock);
irq = per_cpu(virq_to_irq, cpu)[virq];
if (irq == -1) {
irq = xen_allocate_irq_dynamic();
if (irq < 0)
goto out;
irq_set_chip_and_handler_name(irq, &xen_percpu_chip,
handle_percpu_irq, "virq");
bind_virq.virq = virq;
bind_virq.vcpu = cpu;
ret = HYPERVISOR_event_channel_op(EVTCHNOP_bind_virq,
&bind_virq);
if (ret == 0)
evtchn = bind_virq.port;
else {
if (ret == -EEXIST)
ret = find_virq(virq, cpu);
BUG_ON(ret < 0);
evtchn = ret;
}
ret = xen_irq_info_virq_setup(cpu, irq, evtchn, virq);
if (ret < 0) {
__unbind_from_irq(irq);
irq = ret;
goto out;
}
bind_evtchn_to_cpu(evtchn, cpu);
} else {
struct irq_info *info = info_for_irq(irq);
WARN_ON(info == NULL || info->type != IRQT_VIRQ);
}
out:
mutex_unlock(&irq_mapping_update_lock);
return irq;
}
static void unbind_from_irq(unsigned int irq)
{
mutex_lock(&irq_mapping_update_lock);
__unbind_from_irq(irq);
mutex_unlock(&irq_mapping_update_lock);
}
int bind_evtchn_to_irqhandler(unsigned int evtchn,
irq_handler_t handler,
unsigned long irqflags,
const char *devname, void *dev_id)
{
int irq, retval;
irq = bind_evtchn_to_irq(evtchn);
if (irq < 0)
return irq;
retval = request_irq(irq, handler, irqflags, devname, dev_id);
if (retval != 0) {
unbind_from_irq(irq);
return retval;
}
return irq;
}
int bind_interdomain_evtchn_to_irqhandler(unsigned int remote_domain,
unsigned int remote_port,
irq_handler_t handler,
unsigned long irqflags,
const char *devname,
void *dev_id)
{
int irq, retval;
irq = bind_interdomain_evtchn_to_irq(remote_domain, remote_port);
if (irq < 0)
return irq;
retval = request_irq(irq, handler, irqflags, devname, dev_id);
if (retval != 0) {
unbind_from_irq(irq);
return retval;
}
return irq;
}
int bind_virq_to_irqhandler(unsigned int virq, unsigned int cpu,
irq_handler_t handler,
unsigned long irqflags, const char *devname, void *dev_id)
{
int irq, retval;
irq = bind_virq_to_irq(virq, cpu);
if (irq < 0)
return irq;
retval = request_irq(irq, handler, irqflags, devname, dev_id);
if (retval != 0) {
unbind_from_irq(irq);
return retval;
}
return irq;
}
int bind_ipi_to_irqhandler(enum ipi_vector ipi,
unsigned int cpu,
irq_handler_t handler,
unsigned long irqflags,
const char *devname,
void *dev_id)
{
int irq, retval;
irq = bind_ipi_to_irq(ipi, cpu);
if (irq < 0)
return irq;
irqflags |= IRQF_NO_SUSPEND | IRQF_FORCE_RESUME | IRQF_EARLY_RESUME;
retval = request_irq(irq, handler, irqflags, devname, dev_id);
if (retval != 0) {
unbind_from_irq(irq);
return retval;
}
return irq;
}
void unbind_from_irqhandler(unsigned int irq, void *dev_id)
{
struct irq_info *info = irq_get_handler_data(irq);
if (WARN_ON(!info))
return;
free_irq(irq, dev_id);
unbind_from_irq(irq);
}
int xen_set_irq_priority(unsigned irq, unsigned priority)
{
struct evtchn_set_priority set_priority;
set_priority.port = evtchn_from_irq(irq);
set_priority.priority = priority;
return HYPERVISOR_event_channel_op(EVTCHNOP_set_priority,
&set_priority);
}
int evtchn_make_refcounted(unsigned int evtchn)
{
int irq = get_evtchn_to_irq(evtchn);
struct irq_info *info;
if (irq == -1)
return -ENOENT;
info = irq_get_handler_data(irq);
if (!info)
return -ENOENT;
WARN_ON(info->refcnt != -1);
info->refcnt = 1;
return 0;
}
int evtchn_get(unsigned int evtchn)
{
int irq;
struct irq_info *info;
int err = -ENOENT;
if (evtchn >= xen_evtchn_max_channels())
return -EINVAL;
mutex_lock(&irq_mapping_update_lock);
irq = get_evtchn_to_irq(evtchn);
if (irq == -1)
goto done;
info = irq_get_handler_data(irq);
if (!info)
goto done;
err = -EINVAL;
if (info->refcnt <= 0)
goto done;
info->refcnt++;
err = 0;
done:
mutex_unlock(&irq_mapping_update_lock);
return err;
}
void evtchn_put(unsigned int evtchn)
{
int irq = get_evtchn_to_irq(evtchn);
if (WARN_ON(irq == -1))
return;
unbind_from_irq(irq);
}
void xen_send_IPI_one(unsigned int cpu, enum ipi_vector vector)
{
int irq;
#ifdef CONFIG_X86
if (unlikely(vector == XEN_NMI_VECTOR)) {
int rc = HYPERVISOR_vcpu_op(VCPUOP_send_nmi, cpu, NULL);
if (rc < 0)
printk(KERN_WARNING "Sending nmi to CPU%d failed (rc:%d)\n", cpu, rc);
return;
}
#endif
irq = per_cpu(ipi_to_irq, cpu)[vector];
BUG_ON(irq < 0);
notify_remote_via_irq(irq);
}
static void __xen_evtchn_do_upcall(void)
{
struct vcpu_info *vcpu_info = __this_cpu_read(xen_vcpu);
int cpu = get_cpu();
unsigned count;
do {
vcpu_info->evtchn_upcall_pending = 0;
if (__this_cpu_inc_return(xed_nesting_count) - 1)
goto out;
xen_evtchn_handle_events(cpu);
BUG_ON(!irqs_disabled());
count = __this_cpu_read(xed_nesting_count);
__this_cpu_write(xed_nesting_count, 0);
} while (count != 1 || vcpu_info->evtchn_upcall_pending);
out:
put_cpu();
}
void xen_evtchn_do_upcall(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
irq_enter();
#ifdef CONFIG_X86
exit_idle();
inc_irq_stat(irq_hv_callback_count);
#endif
__xen_evtchn_do_upcall();
irq_exit();
set_irq_regs(old_regs);
}
void xen_hvm_evtchn_do_upcall(void)
{
__xen_evtchn_do_upcall();
}
void rebind_evtchn_irq(int evtchn, int irq)
{
struct irq_info *info = info_for_irq(irq);
if (WARN_ON(!info))
return;
disable_irq(irq);
mutex_lock(&irq_mapping_update_lock);
BUG_ON(get_evtchn_to_irq(evtchn) != -1);
BUG_ON(info->type == IRQT_UNBOUND);
(void)xen_irq_info_evtchn_setup(irq, evtchn);
mutex_unlock(&irq_mapping_update_lock);
irq_set_affinity(irq, cpumask_of(0));
enable_irq(irq);
}
static int rebind_irq_to_cpu(unsigned irq, unsigned tcpu)
{
struct evtchn_bind_vcpu bind_vcpu;
int evtchn = evtchn_from_irq(irq);
int masked;
if (!VALID_EVTCHN(evtchn))
return -1;
if (xen_hvm_domain() && !xen_have_vector_callback)
return -1;
bind_vcpu.port = evtchn;
bind_vcpu.vcpu = tcpu;
masked = test_and_set_mask(evtchn);
if (HYPERVISOR_event_channel_op(EVTCHNOP_bind_vcpu, &bind_vcpu) >= 0)
bind_evtchn_to_cpu(evtchn, tcpu);
if (!masked)
unmask_evtchn(evtchn);
return 0;
}
static int set_affinity_irq(struct irq_data *data, const struct cpumask *dest,
bool force)
{
unsigned tcpu = cpumask_first_and(dest, cpu_online_mask);
return rebind_irq_to_cpu(data->irq, tcpu);
}
static void enable_dynirq(struct irq_data *data)
{
int evtchn = evtchn_from_irq(data->irq);
if (VALID_EVTCHN(evtchn))
unmask_evtchn(evtchn);
}
static void disable_dynirq(struct irq_data *data)
{
int evtchn = evtchn_from_irq(data->irq);
if (VALID_EVTCHN(evtchn))
mask_evtchn(evtchn);
}
static void ack_dynirq(struct irq_data *data)
{
int evtchn = evtchn_from_irq(data->irq);
irq_move_irq(data);
if (VALID_EVTCHN(evtchn))
clear_evtchn(evtchn);
}
static void mask_ack_dynirq(struct irq_data *data)
{
disable_dynirq(data);
ack_dynirq(data);
}
static int retrigger_dynirq(struct irq_data *data)
{
unsigned int evtchn = evtchn_from_irq(data->irq);
int masked;
if (!VALID_EVTCHN(evtchn))
return 0;
masked = test_and_set_mask(evtchn);
set_evtchn(evtchn);
if (!masked)
unmask_evtchn(evtchn);
return 1;
}
static void restore_pirqs(void)
{
int pirq, rc, irq, gsi;
struct physdev_map_pirq map_irq;
struct irq_info *info;
list_for_each_entry(info, &xen_irq_list_head, list) {
if (info->type != IRQT_PIRQ)
continue;
pirq = info->u.pirq.pirq;
gsi = info->u.pirq.gsi;
irq = info->irq;
if (!gsi)
continue;
map_irq.domid = DOMID_SELF;
map_irq.type = MAP_PIRQ_TYPE_GSI;
map_irq.index = gsi;
map_irq.pirq = pirq;
rc = HYPERVISOR_physdev_op(PHYSDEVOP_map_pirq, &map_irq);
if (rc) {
pr_warn("xen map irq failed gsi=%d irq=%d pirq=%d rc=%d\n",
gsi, irq, pirq, rc);
xen_free_irq(irq);
continue;
}
printk(KERN_DEBUG "xen: --> irq=%d, pirq=%d\n", irq, map_irq.pirq);
__startup_pirq(irq);
}
}
static void restore_cpu_virqs(unsigned int cpu)
{
struct evtchn_bind_virq bind_virq;
int virq, irq, evtchn;
for (virq = 0; virq < NR_VIRQS; virq++) {
if ((irq = per_cpu(virq_to_irq, cpu)[virq]) == -1)
continue;
BUG_ON(virq_from_irq(irq) != virq);
bind_virq.virq = virq;
bind_virq.vcpu = cpu;
if (HYPERVISOR_event_channel_op(EVTCHNOP_bind_virq,
&bind_virq) != 0)
BUG();
evtchn = bind_virq.port;
(void)xen_irq_info_virq_setup(cpu, irq, evtchn, virq);
bind_evtchn_to_cpu(evtchn, cpu);
}
}
static void restore_cpu_ipis(unsigned int cpu)
{
struct evtchn_bind_ipi bind_ipi;
int ipi, irq, evtchn;
for (ipi = 0; ipi < XEN_NR_IPIS; ipi++) {
if ((irq = per_cpu(ipi_to_irq, cpu)[ipi]) == -1)
continue;
BUG_ON(ipi_from_irq(irq) != ipi);
bind_ipi.vcpu = cpu;
if (HYPERVISOR_event_channel_op(EVTCHNOP_bind_ipi,
&bind_ipi) != 0)
BUG();
evtchn = bind_ipi.port;
(void)xen_irq_info_ipi_setup(cpu, irq, evtchn, ipi);
bind_evtchn_to_cpu(evtchn, cpu);
}
}
void xen_clear_irq_pending(int irq)
{
int evtchn = evtchn_from_irq(irq);
if (VALID_EVTCHN(evtchn))
clear_evtchn(evtchn);
}
void xen_set_irq_pending(int irq)
{
int evtchn = evtchn_from_irq(irq);
if (VALID_EVTCHN(evtchn))
set_evtchn(evtchn);
}
bool xen_test_irq_pending(int irq)
{
int evtchn = evtchn_from_irq(irq);
bool ret = false;
if (VALID_EVTCHN(evtchn))
ret = test_evtchn(evtchn);
return ret;
}
void xen_poll_irq_timeout(int irq, u64 timeout)
{
evtchn_port_t evtchn = evtchn_from_irq(irq);
if (VALID_EVTCHN(evtchn)) {
struct sched_poll poll;
poll.nr_ports = 1;
poll.timeout = timeout;
set_xen_guest_handle(poll.ports, &evtchn);
if (HYPERVISOR_sched_op(SCHEDOP_poll, &poll) != 0)
BUG();
}
}
void xen_poll_irq(int irq)
{
xen_poll_irq_timeout(irq, 0 );
}
int xen_test_irq_shared(int irq)
{
struct irq_info *info = info_for_irq(irq);
struct physdev_irq_status_query irq_status;
if (WARN_ON(!info))
return -ENOENT;
irq_status.irq = info->u.pirq.pirq;
if (HYPERVISOR_physdev_op(PHYSDEVOP_irq_status_query, &irq_status))
return 0;
return !(irq_status.flags & XENIRQSTAT_shared);
}
void xen_irq_resume(void)
{
unsigned int cpu;
struct irq_info *info;
xen_evtchn_mask_all();
xen_evtchn_resume();
list_for_each_entry(info, &xen_irq_list_head, list)
info->evtchn = 0;
clear_evtchn_to_irq_all();
for_each_possible_cpu(cpu) {
restore_cpu_virqs(cpu);
restore_cpu_ipis(cpu);
}
restore_pirqs();
}
int xen_set_callback_via(uint64_t via)
{
struct xen_hvm_param a;
a.domid = DOMID_SELF;
a.index = HVM_PARAM_CALLBACK_IRQ;
a.value = via;
return HYPERVISOR_hvm_op(HVMOP_set_param, &a);
}
void xen_callback_vector(void)
{
int rc;
uint64_t callback_via;
if (xen_have_vector_callback) {
callback_via = HVM_CALLBACK_VECTOR(HYPERVISOR_CALLBACK_VECTOR);
rc = xen_set_callback_via(callback_via);
if (rc) {
pr_err("Request for Xen HVM callback vector failed\n");
xen_have_vector_callback = 0;
return;
}
pr_info("Xen HVM callback vector for event delivery is enabled\n");
if (!test_bit(HYPERVISOR_CALLBACK_VECTOR, used_vectors))
alloc_intr_gate(HYPERVISOR_CALLBACK_VECTOR,
xen_hvm_callback_vector);
}
}
void xen_callback_vector(void) {}
void __init xen_init_IRQ(void)
{
int ret = -EINVAL;
if (fifo_events)
ret = xen_evtchn_fifo_init();
if (ret < 0)
xen_evtchn_2l_init();
evtchn_to_irq = kcalloc(EVTCHN_ROW(xen_evtchn_max_channels()),
sizeof(*evtchn_to_irq), GFP_KERNEL);
BUG_ON(!evtchn_to_irq);
xen_evtchn_mask_all();
pirq_needs_eoi = pirq_needs_eoi_flag;
#ifdef CONFIG_X86
if (xen_pv_domain()) {
irq_ctx_init(smp_processor_id());
if (xen_initial_domain())
pci_xen_initial_domain();
}
if (xen_feature(XENFEAT_hvm_callback_vector))
xen_callback_vector();
if (xen_hvm_domain()) {
native_init_IRQ();
pci_xen_hvm_init();
} else {
int rc;
struct physdev_pirq_eoi_gmfn eoi_gmfn;
pirq_eoi_map = (void *)__get_free_page(GFP_KERNEL|__GFP_ZERO);
eoi_gmfn.gmfn = virt_to_mfn(pirq_eoi_map);
rc = HYPERVISOR_physdev_op(PHYSDEVOP_pirq_eoi_gmfn_v2, &eoi_gmfn);
if (rc != 0) {
free_page((unsigned long) pirq_eoi_map);
pirq_eoi_map = NULL;
} else
pirq_needs_eoi = pirq_check_eoi_map;
}
#endif
}
