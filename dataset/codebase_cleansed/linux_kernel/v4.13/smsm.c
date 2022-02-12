static int smsm_update_bits(void *data, u32 mask, u32 value)
{
struct qcom_smsm *smsm = data;
struct smsm_host *hostp;
unsigned long flags;
u32 changes;
u32 host;
u32 orig;
u32 val;
spin_lock_irqsave(&smsm->lock, flags);
val = orig = readl(smsm->local_state);
val &= ~mask;
val |= value;
changes = val ^ orig;
if (!changes) {
spin_unlock_irqrestore(&smsm->lock, flags);
goto done;
}
writel(val, smsm->local_state);
spin_unlock_irqrestore(&smsm->lock, flags);
wmb();
for (host = 0; host < smsm->num_hosts; host++) {
hostp = &smsm->hosts[host];
val = readl(smsm->subscription + host);
if (val & changes && hostp->ipc_regmap) {
regmap_write(hostp->ipc_regmap,
hostp->ipc_offset,
BIT(hostp->ipc_bit));
}
}
done:
return 0;
}
static irqreturn_t smsm_intr(int irq, void *data)
{
struct smsm_entry *entry = data;
unsigned i;
int irq_pin;
u32 changed;
u32 val;
val = readl(entry->remote_state);
changed = val ^ entry->last_value;
entry->last_value = val;
for_each_set_bit(i, entry->irq_enabled, 32) {
if (!(changed & BIT(i)))
continue;
if (val & BIT(i)) {
if (test_bit(i, entry->irq_rising)) {
irq_pin = irq_find_mapping(entry->domain, i);
handle_nested_irq(irq_pin);
}
} else {
if (test_bit(i, entry->irq_falling)) {
irq_pin = irq_find_mapping(entry->domain, i);
handle_nested_irq(irq_pin);
}
}
}
return IRQ_HANDLED;
}
static void smsm_mask_irq(struct irq_data *irqd)
{
struct smsm_entry *entry = irq_data_get_irq_chip_data(irqd);
irq_hw_number_t irq = irqd_to_hwirq(irqd);
struct qcom_smsm *smsm = entry->smsm;
u32 val;
if (entry->subscription) {
val = readl(entry->subscription + smsm->local_host);
val &= ~BIT(irq);
writel(val, entry->subscription + smsm->local_host);
}
clear_bit(irq, entry->irq_enabled);
}
static void smsm_unmask_irq(struct irq_data *irqd)
{
struct smsm_entry *entry = irq_data_get_irq_chip_data(irqd);
irq_hw_number_t irq = irqd_to_hwirq(irqd);
struct qcom_smsm *smsm = entry->smsm;
u32 val;
set_bit(irq, entry->irq_enabled);
if (entry->subscription) {
val = readl(entry->subscription + smsm->local_host);
val |= BIT(irq);
writel(val, entry->subscription + smsm->local_host);
}
}
static int smsm_set_irq_type(struct irq_data *irqd, unsigned int type)
{
struct smsm_entry *entry = irq_data_get_irq_chip_data(irqd);
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
static int smsm_irq_map(struct irq_domain *d,
unsigned int irq,
irq_hw_number_t hw)
{
struct smsm_entry *entry = d->host_data;
irq_set_chip_and_handler(irq, &smsm_irq_chip, handle_level_irq);
irq_set_chip_data(irq, entry);
irq_set_nested_thread(irq, 1);
return 0;
}
static int smsm_parse_ipc(struct qcom_smsm *smsm, unsigned host_id)
{
struct device_node *syscon;
struct device_node *node = smsm->dev->of_node;
struct smsm_host *host = &smsm->hosts[host_id];
char key[16];
int ret;
snprintf(key, sizeof(key), "qcom,ipc-%d", host_id);
syscon = of_parse_phandle(node, key, 0);
if (!syscon)
return 0;
host->ipc_regmap = syscon_node_to_regmap(syscon);
if (IS_ERR(host->ipc_regmap))
return PTR_ERR(host->ipc_regmap);
ret = of_property_read_u32_index(node, key, 1, &host->ipc_offset);
if (ret < 0) {
dev_err(smsm->dev, "no offset in %s\n", key);
return -EINVAL;
}
ret = of_property_read_u32_index(node, key, 2, &host->ipc_bit);
if (ret < 0) {
dev_err(smsm->dev, "no bit in %s\n", key);
return -EINVAL;
}
return 0;
}
static int smsm_inbound_entry(struct qcom_smsm *smsm,
struct smsm_entry *entry,
struct device_node *node)
{
int ret;
int irq;
irq = irq_of_parse_and_map(node, 0);
if (!irq) {
dev_err(smsm->dev, "failed to parse smsm interrupt\n");
return -EINVAL;
}
ret = devm_request_threaded_irq(smsm->dev, irq,
NULL, smsm_intr,
IRQF_ONESHOT,
"smsm", (void *)entry);
if (ret) {
dev_err(smsm->dev, "failed to request interrupt\n");
return ret;
}
entry->domain = irq_domain_add_linear(node, 32, &smsm_irq_ops, entry);
if (!entry->domain) {
dev_err(smsm->dev, "failed to add irq_domain\n");
return -ENOMEM;
}
return 0;
}
static int smsm_get_size_info(struct qcom_smsm *smsm)
{
size_t size;
struct {
u32 num_hosts;
u32 num_entries;
u32 reserved0;
u32 reserved1;
} *info;
info = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_SMSM_SIZE_INFO, &size);
if (IS_ERR(info) && PTR_ERR(info) != -ENOENT) {
if (PTR_ERR(info) != -EPROBE_DEFER)
dev_err(smsm->dev, "unable to retrieve smsm size info\n");
return PTR_ERR(info);
} else if (IS_ERR(info) || size != sizeof(*info)) {
dev_warn(smsm->dev, "no smsm size info, using defaults\n");
smsm->num_entries = SMSM_DEFAULT_NUM_ENTRIES;
smsm->num_hosts = SMSM_DEFAULT_NUM_HOSTS;
return 0;
}
smsm->num_entries = info->num_entries;
smsm->num_hosts = info->num_hosts;
dev_dbg(smsm->dev,
"found custom size of smsm: %d entries %d hosts\n",
smsm->num_entries, smsm->num_hosts);
return 0;
}
static int qcom_smsm_probe(struct platform_device *pdev)
{
struct device_node *local_node;
struct device_node *node;
struct smsm_entry *entry;
struct qcom_smsm *smsm;
u32 *intr_mask;
size_t size;
u32 *states;
u32 id;
int ret;
smsm = devm_kzalloc(&pdev->dev, sizeof(*smsm), GFP_KERNEL);
if (!smsm)
return -ENOMEM;
smsm->dev = &pdev->dev;
spin_lock_init(&smsm->lock);
ret = smsm_get_size_info(smsm);
if (ret)
return ret;
smsm->entries = devm_kcalloc(&pdev->dev,
smsm->num_entries,
sizeof(struct smsm_entry),
GFP_KERNEL);
if (!smsm->entries)
return -ENOMEM;
smsm->hosts = devm_kcalloc(&pdev->dev,
smsm->num_hosts,
sizeof(struct smsm_host),
GFP_KERNEL);
if (!smsm->hosts)
return -ENOMEM;
local_node = of_find_node_with_property(pdev->dev.of_node, "#qcom,smem-state-cells");
if (!local_node) {
dev_err(&pdev->dev, "no state entry\n");
return -EINVAL;
}
of_property_read_u32(pdev->dev.of_node,
"qcom,local-host",
&smsm->local_host);
for (id = 0; id < smsm->num_hosts; id++) {
ret = smsm_parse_ipc(smsm, id);
if (ret < 0)
return ret;
}
ret = qcom_smem_alloc(QCOM_SMEM_HOST_ANY, SMEM_SMSM_SHARED_STATE,
smsm->num_entries * sizeof(u32));
if (ret < 0 && ret != -EEXIST) {
dev_err(&pdev->dev, "unable to allocate shared state entry\n");
return ret;
}
states = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_SMSM_SHARED_STATE, NULL);
if (IS_ERR(states)) {
dev_err(&pdev->dev, "Unable to acquire shared state entry\n");
return PTR_ERR(states);
}
size = smsm->num_entries * smsm->num_hosts * sizeof(u32);
ret = qcom_smem_alloc(QCOM_SMEM_HOST_ANY, SMEM_SMSM_CPU_INTR_MASK, size);
if (ret < 0 && ret != -EEXIST) {
dev_err(&pdev->dev, "unable to allocate smsm interrupt mask\n");
return ret;
}
intr_mask = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_SMSM_CPU_INTR_MASK, NULL);
if (IS_ERR(intr_mask)) {
dev_err(&pdev->dev, "unable to acquire shared memory interrupt mask\n");
return PTR_ERR(intr_mask);
}
smsm->local_state = states + smsm->local_host;
smsm->subscription = intr_mask + smsm->local_host * smsm->num_hosts;
smsm->state = qcom_smem_state_register(local_node, &smsm_state_ops, smsm);
if (IS_ERR(smsm->state)) {
dev_err(smsm->dev, "failed to register qcom_smem_state\n");
return PTR_ERR(smsm->state);
}
for_each_available_child_of_node(pdev->dev.of_node, node) {
if (!of_property_read_bool(node, "interrupt-controller"))
continue;
ret = of_property_read_u32(node, "reg", &id);
if (ret || id >= smsm->num_entries) {
dev_err(&pdev->dev, "invalid reg of entry\n");
if (!ret)
ret = -EINVAL;
goto unwind_interfaces;
}
entry = &smsm->entries[id];
entry->smsm = smsm;
entry->remote_state = states + id;
entry->subscription = intr_mask + id * smsm->num_hosts;
writel(0, entry->subscription + smsm->local_host);
ret = smsm_inbound_entry(smsm, entry, node);
if (ret < 0)
goto unwind_interfaces;
}
platform_set_drvdata(pdev, smsm);
return 0;
unwind_interfaces:
for (id = 0; id < smsm->num_entries; id++)
if (smsm->entries[id].domain)
irq_domain_remove(smsm->entries[id].domain);
qcom_smem_state_unregister(smsm->state);
return ret;
}
static int qcom_smsm_remove(struct platform_device *pdev)
{
struct qcom_smsm *smsm = platform_get_drvdata(pdev);
unsigned id;
for (id = 0; id < smsm->num_entries; id++)
if (smsm->entries[id].domain)
irq_domain_remove(smsm->entries[id].domain);
qcom_smem_state_unregister(smsm->state);
return 0;
}
