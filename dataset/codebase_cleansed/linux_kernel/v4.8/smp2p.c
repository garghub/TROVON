static void qcom_smp2p_kick(struct qcom_smp2p *smp2p)
{
wmb();
regmap_write(smp2p->ipc_regmap, smp2p->ipc_offset, BIT(smp2p->ipc_bit));
}
static irqreturn_t qcom_smp2p_intr(int irq, void *data)
{
struct smp2p_smem_item *in;
struct smp2p_entry *entry;
struct qcom_smp2p *smp2p = data;
unsigned smem_id = smp2p->smem_items[SMP2P_INBOUND];
unsigned pid = smp2p->remote_pid;
size_t size;
int irq_pin;
u32 status;
char buf[SMP2P_MAX_ENTRY_NAME];
u32 val;
int i;
in = smp2p->in;
if (!in) {
in = qcom_smem_get(pid, smem_id, &size);
if (IS_ERR(in)) {
dev_err(smp2p->dev,
"Unable to acquire remote smp2p item\n");
return IRQ_HANDLED;
}
smp2p->in = in;
}
for (i = smp2p->valid_entries; i < in->valid_entries; i++) {
list_for_each_entry(entry, &smp2p->inbound, node) {
memcpy(buf, in->entries[i].name, sizeof(buf));
if (!strcmp(buf, entry->name)) {
entry->value = &in->entries[i].value;
break;
}
}
}
smp2p->valid_entries = i;
list_for_each_entry(entry, &smp2p->inbound, node) {
if (!entry->value)
continue;
val = readl(entry->value);
status = val ^ entry->last_value;
entry->last_value = val;
if (!status)
continue;
for_each_set_bit(i, entry->irq_enabled, 32) {
if (!(status & BIT(i)))
continue;
if ((val & BIT(i) && test_bit(i, entry->irq_rising)) ||
(!(val & BIT(i)) && test_bit(i, entry->irq_falling))) {
irq_pin = irq_find_mapping(entry->domain, i);
handle_nested_irq(irq_pin);
}
}
}
return IRQ_HANDLED;
}
static void smp2p_mask_irq(struct irq_data *irqd)
{
struct smp2p_entry *entry = irq_data_get_irq_chip_data(irqd);
irq_hw_number_t irq = irqd_to_hwirq(irqd);
clear_bit(irq, entry->irq_enabled);
}
static void smp2p_unmask_irq(struct irq_data *irqd)
{
struct smp2p_entry *entry = irq_data_get_irq_chip_data(irqd);
irq_hw_number_t irq = irqd_to_hwirq(irqd);
set_bit(irq, entry->irq_enabled);
}
static int smp2p_set_irq_type(struct irq_data *irqd, unsigned int type)
{
struct smp2p_entry *entry = irq_data_get_irq_chip_data(irqd);
irq_hw_number_t irq = irqd_to_hwirq(irqd);
if (!(type & IRQ_TYPE_EDGE_BOTH))
return -EINVAL;
if (type & IRQ_TYPE_EDGE_RISING)
set_bit(irq, entry->irq_rising);
else
clear_bit(irq, entry->irq_rising);
if (type & IRQ_TYPE_EDGE_FALLING)
set_bit(irq, entry->irq_falling);
else
clear_bit(irq, entry->irq_falling);
return 0;
}
static int smp2p_irq_map(struct irq_domain *d,
unsigned int irq,
irq_hw_number_t hw)
{
struct smp2p_entry *entry = d->host_data;
irq_set_chip_and_handler(irq, &smp2p_irq_chip, handle_level_irq);
irq_set_chip_data(irq, entry);
irq_set_nested_thread(irq, 1);
irq_set_noprobe(irq);
return 0;
}
static int qcom_smp2p_inbound_entry(struct qcom_smp2p *smp2p,
struct smp2p_entry *entry,
struct device_node *node)
{
entry->domain = irq_domain_add_linear(node, 32, &smp2p_irq_ops, entry);
if (!entry->domain) {
dev_err(smp2p->dev, "failed to add irq_domain\n");
return -ENOMEM;
}
return 0;
}
static int smp2p_update_bits(void *data, u32 mask, u32 value)
{
struct smp2p_entry *entry = data;
u32 orig;
u32 val;
spin_lock(&entry->lock);
val = orig = readl(entry->value);
val &= ~mask;
val |= value;
writel(val, entry->value);
spin_unlock(&entry->lock);
if (val != orig)
qcom_smp2p_kick(entry->smp2p);
return 0;
}
static int qcom_smp2p_outbound_entry(struct qcom_smp2p *smp2p,
struct smp2p_entry *entry,
struct device_node *node)
{
struct smp2p_smem_item *out = smp2p->out;
char buf[SMP2P_MAX_ENTRY_NAME] = {};
strlcpy(buf, entry->name, SMP2P_MAX_ENTRY_NAME);
memcpy(out->entries[out->valid_entries].name, buf, SMP2P_MAX_ENTRY_NAME);
entry->value = &out->entries[out->valid_entries].value;
out->valid_entries++;
entry->state = qcom_smem_state_register(node, &smp2p_state_ops, entry);
if (IS_ERR(entry->state)) {
dev_err(smp2p->dev, "failed to register qcom_smem_state\n");
return PTR_ERR(entry->state);
}
return 0;
}
static int qcom_smp2p_alloc_outbound_item(struct qcom_smp2p *smp2p)
{
struct smp2p_smem_item *out;
unsigned smem_id = smp2p->smem_items[SMP2P_OUTBOUND];
unsigned pid = smp2p->remote_pid;
int ret;
ret = qcom_smem_alloc(pid, smem_id, sizeof(*out));
if (ret < 0 && ret != -EEXIST) {
if (ret != -EPROBE_DEFER)
dev_err(smp2p->dev,
"unable to allocate local smp2p item\n");
return ret;
}
out = qcom_smem_get(pid, smem_id, NULL);
if (IS_ERR(out)) {
dev_err(smp2p->dev, "Unable to acquire local smp2p item\n");
return PTR_ERR(out);
}
memset(out, 0, sizeof(*out));
out->magic = SMP2P_MAGIC;
out->local_pid = smp2p->local_pid;
out->remote_pid = smp2p->remote_pid;
out->total_entries = SMP2P_MAX_ENTRY;
out->valid_entries = 0;
wmb();
out->version = 1;
qcom_smp2p_kick(smp2p);
smp2p->out = out;
return 0;
}
static int smp2p_parse_ipc(struct qcom_smp2p *smp2p)
{
struct device_node *syscon;
struct device *dev = smp2p->dev;
const char *key;
int ret;
syscon = of_parse_phandle(dev->of_node, "qcom,ipc", 0);
if (!syscon) {
dev_err(dev, "no qcom,ipc node\n");
return -ENODEV;
}
smp2p->ipc_regmap = syscon_node_to_regmap(syscon);
if (IS_ERR(smp2p->ipc_regmap))
return PTR_ERR(smp2p->ipc_regmap);
key = "qcom,ipc";
ret = of_property_read_u32_index(dev->of_node, key, 1, &smp2p->ipc_offset);
if (ret < 0) {
dev_err(dev, "no offset in %s\n", key);
return -EINVAL;
}
ret = of_property_read_u32_index(dev->of_node, key, 2, &smp2p->ipc_bit);
if (ret < 0) {
dev_err(dev, "no bit in %s\n", key);
return -EINVAL;
}
return 0;
}
static int qcom_smp2p_probe(struct platform_device *pdev)
{
struct smp2p_entry *entry;
struct device_node *node;
struct qcom_smp2p *smp2p;
const char *key;
int irq;
int ret;
smp2p = devm_kzalloc(&pdev->dev, sizeof(*smp2p), GFP_KERNEL);
if (!smp2p)
return -ENOMEM;
smp2p->dev = &pdev->dev;
INIT_LIST_HEAD(&smp2p->inbound);
INIT_LIST_HEAD(&smp2p->outbound);
platform_set_drvdata(pdev, smp2p);
ret = smp2p_parse_ipc(smp2p);
if (ret)
return ret;
key = "qcom,smem";
ret = of_property_read_u32_array(pdev->dev.of_node, key,
smp2p->smem_items, 2);
if (ret)
return ret;
key = "qcom,local-pid";
ret = of_property_read_u32(pdev->dev.of_node, key, &smp2p->local_pid);
if (ret < 0) {
dev_err(&pdev->dev, "failed to read %s\n", key);
return -EINVAL;
}
key = "qcom,remote-pid";
ret = of_property_read_u32(pdev->dev.of_node, key, &smp2p->remote_pid);
if (ret < 0) {
dev_err(&pdev->dev, "failed to read %s\n", key);
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "unable to acquire smp2p interrupt\n");
return irq;
}
ret = qcom_smp2p_alloc_outbound_item(smp2p);
if (ret < 0)
return ret;
for_each_available_child_of_node(pdev->dev.of_node, node) {
entry = devm_kzalloc(&pdev->dev, sizeof(*entry), GFP_KERNEL);
if (!entry) {
ret = -ENOMEM;
goto unwind_interfaces;
}
entry->smp2p = smp2p;
spin_lock_init(&entry->lock);
ret = of_property_read_string(node, "qcom,entry-name", &entry->name);
if (ret < 0)
goto unwind_interfaces;
if (of_property_read_bool(node, "interrupt-controller")) {
ret = qcom_smp2p_inbound_entry(smp2p, entry, node);
if (ret < 0)
goto unwind_interfaces;
list_add(&entry->node, &smp2p->inbound);
} else {
ret = qcom_smp2p_outbound_entry(smp2p, entry, node);
if (ret < 0)
goto unwind_interfaces;
list_add(&entry->node, &smp2p->outbound);
}
}
qcom_smp2p_kick(smp2p);
ret = devm_request_threaded_irq(&pdev->dev, irq,
NULL, qcom_smp2p_intr,
IRQF_ONESHOT,
"smp2p", (void *)smp2p);
if (ret) {
dev_err(&pdev->dev, "failed to request interrupt\n");
goto unwind_interfaces;
}
return 0;
unwind_interfaces:
list_for_each_entry(entry, &smp2p->inbound, node)
irq_domain_remove(entry->domain);
list_for_each_entry(entry, &smp2p->outbound, node)
qcom_smem_state_unregister(entry->state);
smp2p->out->valid_entries = 0;
return ret;
}
static int qcom_smp2p_remove(struct platform_device *pdev)
{
struct qcom_smp2p *smp2p = platform_get_drvdata(pdev);
struct smp2p_entry *entry;
list_for_each_entry(entry, &smp2p->inbound, node)
irq_domain_remove(entry->domain);
list_for_each_entry(entry, &smp2p->outbound, node)
qcom_smem_state_unregister(entry->state);
smp2p->out->valid_entries = 0;
return 0;
}
