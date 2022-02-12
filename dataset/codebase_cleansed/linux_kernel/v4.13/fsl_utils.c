int fsl_asoc_get_dma_channel(struct device_node *ssi_np,
const char *name,
struct snd_soc_dai_link *dai,
unsigned int *dma_channel_id,
unsigned int *dma_id)
{
struct resource res;
struct device_node *dma_channel_np, *dma_np;
const u32 *iprop;
int ret;
dma_channel_np = of_parse_phandle(ssi_np, name, 0);
if (!dma_channel_np)
return -EINVAL;
if (!of_device_is_compatible(dma_channel_np, "fsl,ssi-dma-channel")) {
of_node_put(dma_channel_np);
return -EINVAL;
}
ret = of_address_to_resource(dma_channel_np, 0, &res);
if (ret) {
of_node_put(dma_channel_np);
return ret;
}
snprintf((char *)dai->platform_name, DAI_NAME_SIZE, "%llx.%s",
(unsigned long long) res.start, dma_channel_np->name);
iprop = of_get_property(dma_channel_np, "cell-index", NULL);
if (!iprop) {
of_node_put(dma_channel_np);
return -EINVAL;
}
*dma_channel_id = be32_to_cpup(iprop);
dma_np = of_get_parent(dma_channel_np);
iprop = of_get_property(dma_np, "cell-index", NULL);
if (!iprop) {
of_node_put(dma_np);
return -EINVAL;
}
*dma_id = be32_to_cpup(iprop);
of_node_put(dma_np);
of_node_put(dma_channel_np);
return 0;
}
