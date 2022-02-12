static inline u8 lm3533_ctrlbank_get_reg(struct lm3533_ctrlbank *cb, u8 base)
{
return base + cb->id;
}
int lm3533_ctrlbank_enable(struct lm3533_ctrlbank *cb)
{
u8 mask;
int ret;
dev_dbg(cb->dev, "%s - %d\n", __func__, cb->id);
mask = 1 << cb->id;
ret = lm3533_update(cb->lm3533, LM3533_REG_CTRLBANK_ENABLE,
mask, mask);
if (ret)
dev_err(cb->dev, "failed to enable ctrlbank %d\n", cb->id);
return ret;
}
int lm3533_ctrlbank_disable(struct lm3533_ctrlbank *cb)
{
u8 mask;
int ret;
dev_dbg(cb->dev, "%s - %d\n", __func__, cb->id);
mask = 1 << cb->id;
ret = lm3533_update(cb->lm3533, LM3533_REG_CTRLBANK_ENABLE, 0, mask);
if (ret)
dev_err(cb->dev, "failed to disable ctrlbank %d\n", cb->id);
return ret;
}
int lm3533_ctrlbank_set_max_current(struct lm3533_ctrlbank *cb, u16 imax)
{
u8 reg;
u8 val;
int ret;
if (imax < LM3533_MAX_CURRENT_MIN || imax > LM3533_MAX_CURRENT_MAX)
return -EINVAL;
val = (imax - LM3533_MAX_CURRENT_MIN) / LM3533_MAX_CURRENT_STEP;
reg = lm3533_ctrlbank_get_reg(cb, LM3533_REG_MAX_CURRENT_BASE);
ret = lm3533_write(cb->lm3533, reg, val);
if (ret)
dev_err(cb->dev, "failed to set max current\n");
return ret;
}
