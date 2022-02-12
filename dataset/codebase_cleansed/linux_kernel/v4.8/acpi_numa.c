int acpi_numa_get_nid(unsigned int cpu, u64 hwid)
{
int i;
for (i = 0; i < cpus_in_srat; i++) {
if (hwid == early_node_cpu_hwid[i].cpu_hwid)
return early_node_cpu_hwid[i].node_id;
}
return NUMA_NO_NODE;
}
void __init acpi_numa_gicc_affinity_init(struct acpi_srat_gicc_affinity *pa)
{
int pxm, node;
phys_cpuid_t mpidr;
if (srat_disabled())
return;
if (pa->header.length < sizeof(struct acpi_srat_gicc_affinity)) {
pr_err("SRAT: Invalid SRAT header length: %d\n",
pa->header.length);
bad_srat();
return;
}
if (!(pa->flags & ACPI_SRAT_GICC_ENABLED))
return;
if (cpus_in_srat >= NR_CPUS) {
pr_warn_once("SRAT: cpu_to_node_map[%d] is too small, may not be able to use all cpus\n",
NR_CPUS);
return;
}
pxm = pa->proximity_domain;
node = acpi_map_pxm_to_node(pxm);
if (node == NUMA_NO_NODE || node >= MAX_NUMNODES) {
pr_err("SRAT: Too many proximity domains %d\n", pxm);
bad_srat();
return;
}
mpidr = acpi_map_madt_entry(pa->acpi_processor_uid);
if (mpidr == PHYS_CPUID_INVALID) {
pr_err("SRAT: PXM %d with ACPI ID %d has no valid MPIDR in MADT\n",
pxm, pa->acpi_processor_uid);
bad_srat();
return;
}
early_node_cpu_hwid[cpus_in_srat].node_id = node;
early_node_cpu_hwid[cpus_in_srat].cpu_hwid = mpidr;
node_set(node, numa_nodes_parsed);
cpus_in_srat++;
pr_info("SRAT: PXM %d -> MPIDR 0x%Lx -> Node %d\n",
pxm, mpidr, node);
}
int __init arm64_acpi_numa_init(void)
{
int ret;
ret = acpi_numa_init();
if (ret)
return ret;
return srat_disabled() ? -EINVAL : 0;
}
