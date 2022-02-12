static int integrator_verify_policy(struct cpufreq_policy *policy)
{
struct icst_vco vco;
cpufreq_verify_within_cpu_limits(policy);
vco = icst_hz_to_vco(&cclk_params, policy->max * 1000);
policy->max = icst_hz(&cclk_params, vco) / 1000;
vco = icst_hz_to_vco(&cclk_params, policy->min * 1000);
policy->min = icst_hz(&cclk_params, vco) / 1000;
cpufreq_verify_within_cpu_limits(policy);
return 0;
}
static int integrator_set_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
cpumask_t cpus_allowed;
int cpu = policy->cpu;
struct icst_vco vco;
struct cpufreq_freqs freqs;
u_int cm_osc;
cpus_allowed = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
BUG_ON(cpu != smp_processor_id());
cm_osc = __raw_readl(cm_base + INTEGRATOR_HDR_OSC_OFFSET);
if (machine_is_integrator()) {
vco.s = (cm_osc >> 8) & 7;
} else if (machine_is_cintegrator()) {
vco.s = 1;
}
vco.v = cm_osc & 255;
vco.r = 22;
freqs.old = icst_hz(&cclk_params, vco) / 1000;
if (relation == CPUFREQ_RELATION_L)
target_freq += 999;
if (target_freq > policy->max)
target_freq = policy->max;
vco = icst_hz_to_vco(&cclk_params, target_freq * 1000);
freqs.new = icst_hz(&cclk_params, vco) / 1000;
if (freqs.old == freqs.new) {
set_cpus_allowed_ptr(current, &cpus_allowed);
return 0;
}
cpufreq_freq_transition_begin(policy, &freqs);
cm_osc = __raw_readl(cm_base + INTEGRATOR_HDR_OSC_OFFSET);
if (machine_is_integrator()) {
cm_osc &= 0xfffff800;
cm_osc |= vco.s << 8;
} else if (machine_is_cintegrator()) {
cm_osc &= 0xffffff00;
}
cm_osc |= vco.v;
__raw_writel(0xa05f, cm_base + INTEGRATOR_HDR_LOCK_OFFSET);
__raw_writel(cm_osc, cm_base + INTEGRATOR_HDR_OSC_OFFSET);
__raw_writel(0, cm_base + INTEGRATOR_HDR_LOCK_OFFSET);
set_cpus_allowed_ptr(current, &cpus_allowed);
cpufreq_freq_transition_end(policy, &freqs, 0);
return 0;
}
static unsigned int integrator_get(unsigned int cpu)
{
cpumask_t cpus_allowed;
unsigned int current_freq;
u_int cm_osc;
struct icst_vco vco;
cpus_allowed = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
BUG_ON(cpu != smp_processor_id());
cm_osc = __raw_readl(cm_base + INTEGRATOR_HDR_OSC_OFFSET);
if (machine_is_integrator()) {
vco.s = (cm_osc >> 8) & 7;
} else {
vco.s = 1;
}
vco.v = cm_osc & 255;
vco.r = 22;
current_freq = icst_hz(&cclk_params, vco) / 1000;
set_cpus_allowed_ptr(current, &cpus_allowed);
return current_freq;
}
static int integrator_cpufreq_init(struct cpufreq_policy *policy)
{
policy->max = policy->cpuinfo.max_freq = 160000;
policy->min = policy->cpuinfo.min_freq = 12000;
policy->cpuinfo.transition_latency = 1000000;
return 0;
}
static int __init integrator_cpufreq_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
cm_base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!cm_base)
return -ENODEV;
return cpufreq_register_driver(&integrator_driver);
}
static int __exit integrator_cpufreq_remove(struct platform_device *pdev)
{
return cpufreq_unregister_driver(&integrator_driver);
}
