void __init acpi_set_mailbox_entry(int cpu,
struct acpi_madt_generic_interrupt *p)
{
struct cpu_mailbox_entry *cpu_entry = &cpu_mailbox_entries[cpu];
cpu_entry->mailbox_addr = p->parked_address;
cpu_entry->version = p->parking_version;
cpu_entry->gic_cpu_id = p->cpu_interface_number;
}
bool acpi_parking_protocol_valid(int cpu)
{
struct cpu_mailbox_entry *cpu_entry = &cpu_mailbox_entries[cpu];
return cpu_entry->mailbox_addr && cpu_entry->version;
}
static int acpi_parking_protocol_cpu_init(unsigned int cpu)
{
pr_debug("%s: ACPI parked addr=%llx\n", __func__,
cpu_mailbox_entries[cpu].mailbox_addr);
return 0;
}
static int acpi_parking_protocol_cpu_prepare(unsigned int cpu)
{
return 0;
}
static int acpi_parking_protocol_cpu_boot(unsigned int cpu)
{
struct cpu_mailbox_entry *cpu_entry = &cpu_mailbox_entries[cpu];
struct parking_protocol_mailbox __iomem *mailbox;
__le32 cpu_id;
mailbox = ioremap(cpu_entry->mailbox_addr, sizeof(*mailbox));
if (!mailbox)
return -EIO;
cpu_id = readl_relaxed(&mailbox->cpu_id);
if (cpu_id != ~0U) {
iounmap(mailbox);
return -ENXIO;
}
cpu_entry->mailbox = mailbox;
writeq_relaxed(__pa(secondary_entry), &mailbox->entry_point);
writel_relaxed(cpu_entry->gic_cpu_id, &mailbox->cpu_id);
arch_send_wakeup_ipi_mask(cpumask_of(cpu));
return 0;
}
static void acpi_parking_protocol_cpu_postboot(void)
{
int cpu = smp_processor_id();
struct cpu_mailbox_entry *cpu_entry = &cpu_mailbox_entries[cpu];
struct parking_protocol_mailbox __iomem *mailbox = cpu_entry->mailbox;
__le64 entry_point;
entry_point = readl_relaxed(&mailbox->entry_point);
WARN_ON(entry_point);
}
