int pci_vpd_find_tag(const u8 *buf, unsigned int off, unsigned int len, u8 rdt)
{
int i;
for (i = off; i < len; ) {
u8 val = buf[i];
if (val & PCI_VPD_LRDT) {
if (i + PCI_VPD_LRDT_TAG_SIZE > len)
break;
if (val == rdt)
return i;
i += PCI_VPD_LRDT_TAG_SIZE +
pci_vpd_lrdt_size(&buf[i]);
} else {
u8 tag = val & ~PCI_VPD_SRDT_LEN_MASK;
if (tag == rdt)
return i;
if (tag == PCI_VPD_SRDT_END)
break;
i += PCI_VPD_SRDT_TAG_SIZE +
pci_vpd_srdt_size(&buf[i]);
}
}
return -ENOENT;
}
int pci_vpd_find_info_keyword(const u8 *buf, unsigned int off,
unsigned int len, const char *kw)
{
int i;
for (i = off; i + PCI_VPD_INFO_FLD_HDR_SIZE <= off + len;) {
if (buf[i + 0] == kw[0] &&
buf[i + 1] == kw[1])
return i;
i += PCI_VPD_INFO_FLD_HDR_SIZE +
pci_vpd_info_field_size(&buf[i]);
}
return -ENOENT;
}
