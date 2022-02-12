static ssize_t
show_test_oa_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "1\n");
}
void
i915_perf_load_test_config_chv(struct drm_i915_private *dev_priv)
{
strncpy(dev_priv->perf.oa.test_config.uuid,
"4a534b07-cba3-414d-8d60-874830e883aa",
UUID_STRING_LEN);
dev_priv->perf.oa.test_config.id = 1;
dev_priv->perf.oa.test_config.mux_regs = mux_config_test_oa;
dev_priv->perf.oa.test_config.mux_regs_len = ARRAY_SIZE(mux_config_test_oa);
dev_priv->perf.oa.test_config.b_counter_regs = b_counter_config_test_oa;
dev_priv->perf.oa.test_config.b_counter_regs_len = ARRAY_SIZE(b_counter_config_test_oa);
dev_priv->perf.oa.test_config.flex_regs = flex_eu_config_test_oa;
dev_priv->perf.oa.test_config.flex_regs_len = ARRAY_SIZE(flex_eu_config_test_oa);
dev_priv->perf.oa.test_config.sysfs_metric.name = "4a534b07-cba3-414d-8d60-874830e883aa";
dev_priv->perf.oa.test_config.sysfs_metric.attrs = dev_priv->perf.oa.test_config.attrs;
dev_priv->perf.oa.test_config.attrs[0] = &dev_priv->perf.oa.test_config.sysfs_metric_id.attr;
dev_priv->perf.oa.test_config.sysfs_metric_id.attr.name = "id";
dev_priv->perf.oa.test_config.sysfs_metric_id.attr.mode = 0444;
dev_priv->perf.oa.test_config.sysfs_metric_id.show = show_test_oa_id;
}
