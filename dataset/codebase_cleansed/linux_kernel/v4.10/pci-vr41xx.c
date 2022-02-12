void __init vr41xx_pciu_setup(struct pci_controller_unit_setup *setup)
{
vr41xx_pci_controller_unit_setup = *setup;
}
static int __init vr41xx_pciu_init(void)
{
struct pci_controller_unit_setup *setup;
struct pci_master_address_conversion *master;
struct pci_target_address_conversion *target;
struct pci_mailbox_address *mailbox;
struct pci_target_address_window *window;
unsigned long vtclock, pci_clock_max;
uint32_t val;
setup = &vr41xx_pci_controller_unit_setup;
if (request_mem_region(PCIU_BASE, PCIU_SIZE, "PCIU") == NULL)
return -EBUSY;
pciu_base = ioremap(PCIU_BASE, PCIU_SIZE);
if (pciu_base == NULL) {
release_mem_region(PCIU_BASE, PCIU_SIZE);
return -EBUSY;
}
vr41xx_disable_pciint();
vr41xx_supply_clock(PCIU_CLOCK);
vr41xx_disable_pciint();
if (setup->pci_clock_max != 0)
pci_clock_max = setup->pci_clock_max;
else
pci_clock_max = PCI_CLOCK_MAX;
vtclock = vr41xx_get_vtclock_frequency();
if (vtclock < pci_clock_max)
pciu_write(PCICLKSELREG, EQUAL_VTCLOCK);
else if ((vtclock / 2) < pci_clock_max)
pciu_write(PCICLKSELREG, HALF_VTCLOCK);
else if (current_cpu_data.processor_id >= PRID_VR4131_REV2_1 &&
(vtclock / 3) < pci_clock_max)
pciu_write(PCICLKSELREG, ONE_THIRD_VTCLOCK);
else if ((vtclock / 4) < pci_clock_max)
pciu_write(PCICLKSELREG, QUARTER_VTCLOCK);
else {
printk(KERN_ERR "PCI Clock is over 33MHz.\n");
iounmap(pciu_base);
return -EINVAL;
}
vr41xx_supply_clock(PCI_CLOCK);
if (setup->master_memory1 != NULL) {
master = setup->master_memory1;
val = IBA(master->bus_base_address) |
MASTER_MSK(master->address_mask) |
WINEN |
PCIA(master->pci_base_address);
pciu_write(PCIMMAW1REG, val);
} else {
val = pciu_read(PCIMMAW1REG);
val &= ~WINEN;
pciu_write(PCIMMAW1REG, val);
}
if (setup->master_memory2 != NULL) {
master = setup->master_memory2;
val = IBA(master->bus_base_address) |
MASTER_MSK(master->address_mask) |
WINEN |
PCIA(master->pci_base_address);
pciu_write(PCIMMAW2REG, val);
} else {
val = pciu_read(PCIMMAW2REG);
val &= ~WINEN;
pciu_write(PCIMMAW2REG, val);
}
if (setup->target_memory1 != NULL) {
target = setup->target_memory1;
val = TARGET_MSK(target->address_mask) |
WINEN |
ITA(target->bus_base_address);
pciu_write(PCITAW1REG, val);
} else {
val = pciu_read(PCITAW1REG);
val &= ~WINEN;
pciu_write(PCITAW1REG, val);
}
if (setup->target_memory2 != NULL) {
target = setup->target_memory2;
val = TARGET_MSK(target->address_mask) |
WINEN |
ITA(target->bus_base_address);
pciu_write(PCITAW2REG, val);
} else {
val = pciu_read(PCITAW2REG);
val &= ~WINEN;
pciu_write(PCITAW2REG, val);
}
if (setup->master_io != NULL) {
master = setup->master_io;
val = IBA(master->bus_base_address) |
MASTER_MSK(master->address_mask) |
WINEN |
PCIIA(master->pci_base_address);
pciu_write(PCIMIOAWREG, val);
} else {
val = pciu_read(PCIMIOAWREG);
val &= ~WINEN;
pciu_write(PCIMIOAWREG, val);
}
if (setup->exclusive_access == CANNOT_LOCK_FROM_DEVICE)
pciu_write(PCIEXACCREG, UNLOCK);
else
pciu_write(PCIEXACCREG, 0);
if (current_cpu_type() == CPU_VR4122)
pciu_write(PCITRDYVREG, TRDYV(setup->wait_time_limit_from_irdy_to_trdy));
pciu_write(LATTIMEREG, MLTIM(setup->master_latency_timer));
if (setup->mailbox != NULL) {
mailbox = setup->mailbox;
val = MBADD(mailbox->base_address) | TYPE_32BITSPACE |
MSI_MEMORY | PREF_APPROVAL;
pciu_write(MAILBAREG, val);
}
if (setup->target_window1) {
window = setup->target_window1;
val = PMBA(window->base_address) | TYPE_32BITSPACE |
MSI_MEMORY | PREF_APPROVAL;
pciu_write(PCIMBA1REG, val);
}
if (setup->target_window2) {
window = setup->target_window2;
val = PMBA(window->base_address) | TYPE_32BITSPACE |
MSI_MEMORY | PREF_APPROVAL;
pciu_write(PCIMBA2REG, val);
}
val = pciu_read(RETVALREG);
val &= ~RTYVAL_MASK;
val |= RTYVAL(setup->retry_limit);
pciu_write(RETVALREG, val);
val = pciu_read(PCIAPCNTREG);
val &= ~(TKYGNT | PAPC);
switch (setup->arbiter_priority_control) {
case PCI_ARBITRATION_MODE_ALTERNATE_0:
val |= PAPC_ALTERNATE_0;
break;
case PCI_ARBITRATION_MODE_ALTERNATE_B:
val |= PAPC_ALTERNATE_B;
break;
default:
val |= PAPC_FAIR;
break;
}
if (setup->take_away_gnt_mode == PCI_TAKE_AWAY_GNT_ENABLE)
val |= TKYGNT_ENABLE;
pciu_write(PCIAPCNTREG, val);
pciu_write(COMMANDREG, PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | PCI_COMMAND_PARITY |
PCI_COMMAND_SERR);
pciu_read(BUSERRADREG);
pciu_write(PCIENREG, PCIU_CONFIG_DONE);
if (setup->mem_resource != NULL)
vr41xx_pci_controller.mem_resource = setup->mem_resource;
if (setup->io_resource != NULL) {
vr41xx_pci_controller.io_resource = setup->io_resource;
} else {
set_io_port_base(IO_PORT_BASE);
ioport_resource.start = IO_PORT_RESOURCE_START;
ioport_resource.end = IO_PORT_RESOURCE_END;
}
if (setup->master_io) {
void __iomem *io_map_base;
struct resource *res = vr41xx_pci_controller.io_resource;
master = setup->master_io;
io_map_base = ioremap(master->bus_base_address,
resource_size(res));
if (!io_map_base)
return -EBUSY;
vr41xx_pci_controller.io_map_base = (unsigned long)io_map_base;
}
register_pci_controller(&vr41xx_pci_controller);
return 0;
}
