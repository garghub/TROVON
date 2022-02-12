static int
gk20a_timer_init(struct nouveau_object *object)
{
struct nv04_timer_priv *priv = (void *)object;
u32 hi = upper_32_bits(priv->suspend_time);
u32 lo = lower_32_bits(priv->suspend_time);
int ret;
ret = nouveau_timer_init(&priv->base);
if (ret)
return ret;
nv_debug(priv, "time low : 0x%08x\n", lo);
nv_debug(priv, "time high : 0x%08x\n", hi);
nv_wr32(priv, NV04_PTIMER_TIME_1, hi);
nv_wr32(priv, NV04_PTIMER_TIME_0, lo);
return 0;
}
