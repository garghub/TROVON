static struct of_dma *of_dma_get_controller(struct of_phandle_args *dma_spec)
{
struct of_dma *ofdma;
spin_lock(&of_dma_lock);
if (list_empty(&of_dma_list)) {
spin_unlock(&of_dma_lock);
return NULL;
}
list_for_each_entry(ofdma, &of_dma_list, of_dma_controllers)
if ((ofdma->of_node == dma_spec->np) &&
(ofdma->of_dma_nbcells == dma_spec->args_count)) {
ofdma->use_count++;
spin_unlock(&of_dma_lock);
return ofdma;
}
spin_unlock(&of_dma_lock);
pr_debug("%s: can't find DMA controller %s\n", __func__,
dma_spec->np->full_name);
return NULL;
}
static void of_dma_put_controller(struct of_dma *ofdma)
{
spin_lock(&of_dma_lock);
ofdma->use_count--;
spin_unlock(&of_dma_lock);
}
int of_dma_controller_free(struct device_node *np)
{
struct of_dma *ofdma;
spin_lock(&of_dma_lock);
if (list_empty(&of_dma_list)) {
spin_unlock(&of_dma_lock);
return -ENODEV;
}
list_for_each_entry(ofdma, &of_dma_list, of_dma_controllers)
if (ofdma->of_node == np) {
if (ofdma->use_count) {
spin_unlock(&of_dma_lock);
return -EBUSY;
}
list_del(&ofdma->of_dma_controllers);
spin_unlock(&of_dma_lock);
kfree(ofdma);
return 0;
}
spin_unlock(&of_dma_lock);
return -ENODEV;
}
static int of_dma_match_channel(struct device_node *np, char *name, int index,
struct of_phandle_args *dma_spec)
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
char *name)
{
struct of_phandle_args dma_spec;
struct of_dma *ofdma;
struct dma_chan *chan;
int count, i;
if (!np || !name) {
pr_err("%s: not enough information provided\n", __func__);
return NULL;
}
count = of_property_count_strings(np, "dma-names");
if (count < 0) {
pr_err("%s: dma-names property missing or empty\n", __func__);
return NULL;
}
for (i = 0; i < count; i++) {
if (of_dma_match_channel(np, name, i, &dma_spec))
continue;
ofdma = of_dma_get_controller(&dma_spec);
if (!ofdma)
continue;
chan = ofdma->of_dma_xlate(&dma_spec, ofdma);
of_dma_put_controller(ofdma);
of_node_put(dma_spec.np);
if (chan)
return chan;
}
return NULL;
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
