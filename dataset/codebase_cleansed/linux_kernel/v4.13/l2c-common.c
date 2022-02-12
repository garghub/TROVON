void outer_disable(void)
{
WARN_ON(!irqs_disabled());
WARN_ON(num_online_cpus() > 1);
if (outer_cache.disable)
outer_cache.disable();
}
