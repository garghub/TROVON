void dml_start_xfer(struct mmci_host *host, struct mmc_data *data)
{
u32 config;
void __iomem *base = host->base + DML_OFFSET;
if (data->flags & MMC_DATA_READ) {
config = readl_relaxed(base + DML_CONFIG);
config = (config & ~PRODUCER_CRCI_MSK) | PRODUCER_CRCI_X_SEL;
config = (config & ~CONSUMER_CRCI_MSK) | CONSUMER_CRCI_DISABLE;
writel_relaxed(config, base + DML_CONFIG);
writel_relaxed(data->blksz, base + DML_PRODUCER_BAM_BLOCK_SIZE);
writel_relaxed(data->blocks * data->blksz,
base + DML_PRODUCER_BAM_TRANS_SIZE);
config = readl_relaxed(base + DML_CONFIG);
config |= PRODUCER_TRANS_END_EN;
writel_relaxed(config, base + DML_CONFIG);
writel_relaxed(1, base + DML_PRODUCER_START);
} else {
config = readl_relaxed(base + DML_CONFIG);
config = (config & ~CONSUMER_CRCI_MSK) | CONSUMER_CRCI_X_SEL;
config = (config & ~PRODUCER_CRCI_MSK) | PRODUCER_CRCI_DISABLE;
writel_relaxed(config, base + DML_CONFIG);
config = readl_relaxed(base + DML_CONFIG);
config &= ~PRODUCER_TRANS_END_EN;
writel_relaxed(config, base + DML_CONFIG);
writel_relaxed(1, base + DML_CONSUMER_START);
}
wmb();
}
static int of_get_dml_pipe_index(struct device_node *np, const char *name)
{
int index;
struct of_phandle_args dma_spec;
index = of_property_match_string(np, "dma-names", name);
if (index < 0)
return -ENODEV;
if (of_parse_phandle_with_args(np, "dmas", "#dma-cells", index,
&dma_spec))
return -ENODEV;
if (dma_spec.args_count)
return dma_spec.args[0];
return -ENODEV;
}
int dml_hw_init(struct mmci_host *host, struct device_node *np)
{
u32 config;
void __iomem *base;
int consumer_id, producer_id;
consumer_id = of_get_dml_pipe_index(np, "tx");
producer_id = of_get_dml_pipe_index(np, "rx");
if (producer_id < 0 || consumer_id < 0)
return -ENODEV;
base = host->base + DML_OFFSET;
writel_relaxed(1, base + DML_SW_RESET);
config = (PRODUCER_CRCI_DISABLE | CONSUMER_CRCI_DISABLE);
config &= ~BYPASS;
config &= ~DIRECT_MODE;
config &= ~INFINITE_CONS_TRANS;
writel_relaxed(config, base + DML_CONFIG);
writel_relaxed(PRODUCER_PIPE_LOGICAL_SIZE,
base + DML_PRODUCER_PIPE_LOGICAL_SIZE);
writel_relaxed(CONSUMER_PIPE_LOGICAL_SIZE,
base + DML_CONSUMER_PIPE_LOGICAL_SIZE);
writel_relaxed(producer_id | (consumer_id << CONSUMER_PIPE_ID_SHFT),
base + DML_PIPE_ID);
mb();
return 0;
}
