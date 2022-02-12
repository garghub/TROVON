void cryp_enable_irq_src(struct cryp_device_data *device_data, u32 irq_src)
{
u32 i;
dev_dbg(device_data->dev, "[%s]", __func__);
i = readl_relaxed(&device_data->base->imsc);
i = i | irq_src;
writel_relaxed(i, &device_data->base->imsc);
}
void cryp_disable_irq_src(struct cryp_device_data *device_data, u32 irq_src)
{
u32 i;
dev_dbg(device_data->dev, "[%s]", __func__);
i = readl_relaxed(&device_data->base->imsc);
i = i & ~irq_src;
writel_relaxed(i, &device_data->base->imsc);
}
bool cryp_pending_irq_src(struct cryp_device_data *device_data, u32 irq_src)
{
return (readl_relaxed(&device_data->base->mis) & irq_src) > 0;
}
