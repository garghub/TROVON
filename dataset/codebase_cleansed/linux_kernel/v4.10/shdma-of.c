static struct dma_chan *shdma_of_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
u32 id = dma_spec->args[0];
dma_cap_mask_t mask;
struct dma_chan *chan;
if (dma_spec->args_count != 1)
return NULL;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
chan = dma_request_channel(mask, shdma_chan_filter,
(void *)(uintptr_t)id);
if (chan)
to_shdma_chan(chan)->hw_req = id;
return chan;
}
static int shdma_of_probe(struct platform_device *pdev)
{
const struct of_dev_auxdata *lookup = dev_get_platdata(&pdev->dev);
int ret;
ret = of_dma_controller_register(pdev->dev.of_node,
shdma_of_xlate, pdev);
if (ret < 0)
return ret;
ret = of_platform_populate(pdev->dev.of_node, NULL, lookup, &pdev->dev);
if (ret < 0)
of_dma_controller_free(pdev->dev.of_node);
return ret;
}
