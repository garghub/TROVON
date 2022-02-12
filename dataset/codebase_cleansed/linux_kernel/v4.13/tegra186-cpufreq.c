static int tegra186_cpufreq_init(struct cpufreq_policy *policy)
{
struct tegra186_cpufreq_data *data = cpufreq_get_driver_data();
unsigned int i;
for (i = 0; i < data->num_clusters; i++) {
struct tegra186_cpufreq_cluster *cluster = &data->clusters[i];
const struct tegra186_cpufreq_cluster_info *info =
cluster->info;
int core;
for (core = 0; core < ARRAY_SIZE(info->cpus); core++) {
if (info->cpus[core] == policy->cpu)
break;
}
if (core == ARRAY_SIZE(info->cpus))
continue;
policy->driver_data =
data->regs + info->offset + EDVD_CORE_VOLT_FREQ(core);
cpufreq_table_validate_and_show(policy, cluster->table);
}
policy->cpuinfo.transition_latency = 300 * 1000;
return 0;
}
static int tegra186_cpufreq_set_target(struct cpufreq_policy *policy,
unsigned int index)
{
struct cpufreq_frequency_table *tbl = policy->freq_table + index;
void __iomem *edvd_reg = policy->driver_data;
u32 edvd_val = tbl->driver_data;
writel(edvd_val, edvd_reg);
return 0;
}
static struct cpufreq_frequency_table *init_vhint_table(
struct platform_device *pdev, struct tegra_bpmp *bpmp,
unsigned int cluster_id)
{
struct cpufreq_frequency_table *table;
struct mrq_cpu_vhint_request req;
struct tegra_bpmp_message msg;
struct cpu_vhint_data *data;
int err, i, j, num_rates = 0;
dma_addr_t phys;
void *virt;
virt = dma_alloc_coherent(bpmp->dev, sizeof(*data), &phys,
GFP_KERNEL | GFP_DMA32);
if (!virt)
return ERR_PTR(-ENOMEM);
data = (struct cpu_vhint_data *)virt;
memset(&req, 0, sizeof(req));
req.addr = phys;
req.cluster_id = cluster_id;
memset(&msg, 0, sizeof(msg));
msg.mrq = MRQ_CPU_VHINT;
msg.tx.data = &req;
msg.tx.size = sizeof(req);
err = tegra_bpmp_transfer(bpmp, &msg);
if (err) {
table = ERR_PTR(err);
goto free;
}
for (i = data->vfloor; i <= data->vceil; i++) {
u16 ndiv = data->ndiv[i];
if (ndiv < data->ndiv_min || ndiv > data->ndiv_max)
continue;
if (i > 0 && ndiv == data->ndiv[i - 1])
continue;
num_rates++;
}
table = devm_kcalloc(&pdev->dev, num_rates + 1, sizeof(*table),
GFP_KERNEL);
if (!table) {
table = ERR_PTR(-ENOMEM);
goto free;
}
for (i = data->vfloor, j = 0; i <= data->vceil; i++) {
struct cpufreq_frequency_table *point;
u16 ndiv = data->ndiv[i];
u32 edvd_val = 0;
if (ndiv < data->ndiv_min || ndiv > data->ndiv_max)
continue;
if (i > 0 && ndiv == data->ndiv[i - 1])
continue;
edvd_val |= i << EDVD_CORE_VOLT_FREQ_V_SHIFT;
edvd_val |= ndiv << EDVD_CORE_VOLT_FREQ_F_SHIFT;
point = &table[j++];
point->driver_data = edvd_val;
point->frequency = data->ref_clk_hz * ndiv / data->pdiv /
data->mdiv / 1000;
}
table[j].frequency = CPUFREQ_TABLE_END;
free:
dma_free_coherent(bpmp->dev, sizeof(*data), virt, phys);
return table;
}
static int tegra186_cpufreq_probe(struct platform_device *pdev)
{
struct tegra186_cpufreq_data *data;
struct tegra_bpmp *bpmp;
struct resource *res;
unsigned int i = 0, err;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->clusters = devm_kcalloc(&pdev->dev, ARRAY_SIZE(tegra186_clusters),
sizeof(*data->clusters), GFP_KERNEL);
if (!data->clusters)
return -ENOMEM;
data->num_clusters = ARRAY_SIZE(tegra186_clusters);
bpmp = tegra_bpmp_get(&pdev->dev);
if (IS_ERR(bpmp))
return PTR_ERR(bpmp);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->regs)) {
err = PTR_ERR(data->regs);
goto put_bpmp;
}
for (i = 0; i < data->num_clusters; i++) {
struct tegra186_cpufreq_cluster *cluster = &data->clusters[i];
cluster->info = &tegra186_clusters[i];
cluster->table = init_vhint_table(
pdev, bpmp, cluster->info->bpmp_cluster_id);
if (IS_ERR(cluster->table)) {
err = PTR_ERR(cluster->table);
goto put_bpmp;
}
}
tegra_bpmp_put(bpmp);
tegra186_cpufreq_driver.driver_data = data;
err = cpufreq_register_driver(&tegra186_cpufreq_driver);
if (err)
return err;
return 0;
put_bpmp:
tegra_bpmp_put(bpmp);
return err;
}
static int tegra186_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_driver(&tegra186_cpufreq_driver);
return 0;
}
