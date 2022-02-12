static struct of_dma *of_dma_find_controller(struct of_phandle_args *dma_spec)
{
struct of_dma *ofdma;
list_for_each_entry(ofdma, &of_dma_list, of_dma_controllers)
if (ofdma->of_node == dma_spec->np)
return ofdma;
pr_debug("%s: can't find DMA controller %s\n", __func__,
dma_spec->np->full_name);
return NULL;
}
void of_dma_controller_free(struct device_node *np)
{
struct of_dma *ofdma;
mutex_lock(&of_dma_lock);
list_for_each_entry(ofdma, &of_dma_list, of_dma_controllers)
if (ofdma->of_node == np) {
list_del(&ofdma->of_dma_controllers);
kfree(ofdma);
break;
}
mutex_unlock(&of_dma_lock);
}
static int of_dma_match_channel(struct device_node *np, const char *name,
int index, struct of_phandle_args *dma_spec)
{
const char *s;
if (of_property_read_string_index(np, "dma-names", index, &s))
return -ENODEV;
if (strcmp(name, s))
return -ENODEV;
if (of_parse_phandle_with_args(np, "dmas", "#dma-cells", index,
dma_spec))
return -ENODEV;
return 0;
}
struct dma_chan *of_dma_request_slave_channel(struct device_node *np,
const char *name)
{
struct of_phandle_args dma_spec;
struct of_dma *ofdma;
struct dma_chan *chan;
int count, i;
int ret_no_channel = -ENODEV;
if (!np || !name) {
pr_err("%s: not enough information provided\n", __func__);
return ERR_PTR(-ENODEV);
}
count = of_property_count_strings(np, "dma-names");
if (count < 0) {
pr_err("%s: dma-names property of node '%s' missing or empty\n",
__func__, np->full_name);
return ERR_PTR(-ENODEV);
}
for (i = 0; i < count; i++) {
if (of_dma_match_channel(np, name, i, &dma_spec))
continue;
mutex_lock(&of_dma_lock);
ofdma = of_dma_find_controller(&dma_spec);
if (ofdma) {
chan = ofdma->of_dma_xlate(&dma_spec, ofdma);
} else {
ret_no_channel = -EPROBE_DEFER;
chan = NULL;
}
mutex_unlock(&of_dma_lock);
of_node_put(dma_spec.np);
if (chan)
return chan;
}
return ERR_PTR(ret_no_channel);
}
struct dma_chan *of_dma_simple_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
int count = dma_spec->args_count;
struct of_dma_filter_info *info = ofdma->of_dma_data;
if (!info || !info->filter_fn)
return NULL;
if (count != 1)
return NULL;
return dma_request_channel(info->dma_cap, info->filter_fn,
&dma_spec->args[0]);
}
struct dma_chan *of_dma_xlate_by_chan_id(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct dma_device *dev = ofdma->of_dma_data;
struct dma_chan *chan, *candidate = NULL;
if (!dev || dma_spec->args_count != 1)
return NULL;
list_for_each_entry(chan, &dev->channels, device_node)
if (chan->chan_id == dma_spec->args[0]) {
candidate = chan;
break;
}
if (!candidate)
return NULL;
return dma_get_slave_channel(candidate);
}
