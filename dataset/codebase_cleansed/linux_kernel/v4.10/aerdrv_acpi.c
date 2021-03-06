static inline int hest_match_pci(struct acpi_hest_aer_common *p,
struct pci_dev *pci)
{
return ACPI_HEST_SEGMENT(p->bus) == pci_domain_nr(pci->bus) &&
ACPI_HEST_BUS(p->bus) == pci->bus->number &&
p->device == PCI_SLOT(pci->devfn) &&
p->function == PCI_FUNC(pci->devfn);
}
static inline bool hest_match_type(struct acpi_hest_header *hest_hdr,
struct pci_dev *dev)
{
u16 hest_type = hest_hdr->type;
u8 pcie_type = pci_pcie_type(dev);
if ((hest_type == ACPI_HEST_TYPE_AER_ROOT_PORT &&
pcie_type == PCI_EXP_TYPE_ROOT_PORT) ||
(hest_type == ACPI_HEST_TYPE_AER_ENDPOINT &&
pcie_type == PCI_EXP_TYPE_ENDPOINT) ||
(hest_type == ACPI_HEST_TYPE_AER_BRIDGE &&
(dev->class >> 16) == PCI_BASE_CLASS_BRIDGE))
return true;
return false;
}
static int hest_source_is_pcie_aer(struct acpi_hest_header *hest_hdr)
{
if (hest_hdr->type == ACPI_HEST_TYPE_AER_ROOT_PORT ||
hest_hdr->type == ACPI_HEST_TYPE_AER_ENDPOINT ||
hest_hdr->type == ACPI_HEST_TYPE_AER_BRIDGE)
return 1;
return 0;
}
static int aer_hest_parse(struct acpi_hest_header *hest_hdr, void *data)
{
struct aer_hest_parse_info *info = data;
struct acpi_hest_aer_common *p;
int ff;
if (!hest_source_is_pcie_aer(hest_hdr))
return 0;
p = (struct acpi_hest_aer_common *)(hest_hdr + 1);
ff = !!(p->flags & ACPI_HEST_FIRMWARE_FIRST);
if (!info->pci_dev) {
info->firmware_first |= ff;
return 0;
}
if (p->flags & ACPI_HEST_GLOBAL) {
if (hest_match_type(hest_hdr, info->pci_dev))
info->firmware_first = ff;
} else
if (hest_match_pci(p, info->pci_dev))
info->firmware_first = ff;
return 0;
}
static void aer_set_firmware_first(struct pci_dev *pci_dev)
{
int rc;
struct aer_hest_parse_info info = {
.pci_dev = pci_dev,
.firmware_first = 0,
};
rc = apei_hest_parse(aer_hest_parse, &info);
if (rc)
pci_dev->__aer_firmware_first = 0;
else
pci_dev->__aer_firmware_first = info.firmware_first;
pci_dev->__aer_firmware_first_valid = 1;
}
int pcie_aer_get_firmware_first(struct pci_dev *dev)
{
if (!pci_is_pcie(dev))
return 0;
if (!dev->__aer_firmware_first_valid)
aer_set_firmware_first(dev);
return dev->__aer_firmware_first;
}
bool aer_acpi_firmware_first(void)
{
static bool parsed = false;
struct aer_hest_parse_info info = {
.pci_dev = NULL,
.firmware_first = 0,
};
if (!parsed) {
apei_hest_parse(aer_hest_parse, &info);
aer_firmware_first = info.firmware_first;
parsed = true;
}
return aer_firmware_first;
}
