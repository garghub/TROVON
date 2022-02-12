void spu_switch_notify(struct spu *spu, struct spu_context *ctx)
{
blocking_notifier_call_chain(&spu_switch_notifier,
ctx ? ctx->object_id : 0, spu);
}
int spu_switch_event_register(struct notifier_block *n)
{
int ret;
ret = blocking_notifier_chain_register(&spu_switch_notifier, n);
if (!ret)
notify_spus_active();
return ret;
}
int spu_switch_event_unregister(struct notifier_block *n)
{
return blocking_notifier_chain_unregister(&spu_switch_notifier, n);
}
void spu_set_profile_private_kref(struct spu_context *ctx,
struct kref *prof_info_kref,
void (* prof_info_release) (struct kref *kref))
{
ctx->prof_priv_kref = prof_info_kref;
ctx->prof_priv_release = prof_info_release;
}
void *spu_get_profile_private_kref(struct spu_context *ctx)
{
return ctx->prof_priv_kref;
}
