void pci_ats_init(struct pci_dev *dev)
{
int pos;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ATS);
if (!pos)
return;
dev->ats_cap = pos;
}
int pci_enable_ats(struct pci_dev *dev, int ps)
{
u16 ctrl;
struct pci_dev *pdev;
if (!dev->ats_cap)
return -EINVAL;
if (WARN_ON(dev->ats_enabled))
return -EBUSY;
if (ps < PCI_ATS_MIN_STU)
return -EINVAL;
ctrl = PCI_ATS_CTRL_ENABLE;
if (dev->is_virtfn) {
pdev = pci_physfn(dev);
if (pdev->ats_stu != ps)
return -EINVAL;
atomic_inc(&pdev->ats_ref_cnt);
} else {
dev->ats_stu = ps;
ctrl |= PCI_ATS_CTRL_STU(dev->ats_stu - PCI_ATS_MIN_STU);
}
pci_write_config_word(dev, dev->ats_cap + PCI_ATS_CTRL, ctrl);
dev->ats_enabled = 1;
return 0;
}
void pci_disable_ats(struct pci_dev *dev)
{
struct pci_dev *pdev;
u16 ctrl;
if (WARN_ON(!dev->ats_enabled))
return;
if (atomic_read(&dev->ats_ref_cnt))
return;
if (dev->is_virtfn) {
pdev = pci_physfn(dev);
atomic_dec(&pdev->ats_ref_cnt);
}
pci_read_config_word(dev, dev->ats_cap + PCI_ATS_CTRL, &ctrl);
ctrl &= ~PCI_ATS_CTRL_ENABLE;
pci_write_config_word(dev, dev->ats_cap + PCI_ATS_CTRL, ctrl);
dev->ats_enabled = 0;
}
void pci_restore_ats_state(struct pci_dev *dev)
{
u16 ctrl;
if (!dev->ats_enabled)
return;
ctrl = PCI_ATS_CTRL_ENABLE;
if (!dev->is_virtfn)
ctrl |= PCI_ATS_CTRL_STU(dev->ats_stu - PCI_ATS_MIN_STU);
pci_write_config_word(dev, dev->ats_cap + PCI_ATS_CTRL, ctrl);
}
int pci_ats_queue_depth(struct pci_dev *dev)
{
u16 cap;
if (!dev->ats_cap)
return -EINVAL;
if (dev->is_virtfn)
return 0;
pci_read_config_word(dev, dev->ats_cap + PCI_ATS_CAP, &cap);
return PCI_ATS_CAP_QDEP(cap) ? PCI_ATS_CAP_QDEP(cap) : PCI_ATS_MAX_QDEP;
}
int pci_enable_pri(struct pci_dev *pdev, u32 reqs)
{
u16 control, status;
u32 max_requests;
int pos;
if (WARN_ON(pdev->pri_enabled))
return -EBUSY;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PRI);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PRI_STATUS, &status);
if (!(status & PCI_PRI_STATUS_STOPPED))
return -EBUSY;
pci_read_config_dword(pdev, pos + PCI_PRI_MAX_REQ, &max_requests);
reqs = min(max_requests, reqs);
pdev->pri_reqs_alloc = reqs;
pci_write_config_dword(pdev, pos + PCI_PRI_ALLOC_REQ, reqs);
control = PCI_PRI_CTRL_ENABLE;
pci_write_config_word(pdev, pos + PCI_PRI_CTRL, control);
pdev->pri_enabled = 1;
return 0;
}
void pci_disable_pri(struct pci_dev *pdev)
{
u16 control;
int pos;
if (WARN_ON(!pdev->pri_enabled))
return;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PRI);
if (!pos)
return;
pci_read_config_word(pdev, pos + PCI_PRI_CTRL, &control);
control &= ~PCI_PRI_CTRL_ENABLE;
pci_write_config_word(pdev, pos + PCI_PRI_CTRL, control);
pdev->pri_enabled = 0;
}
void pci_restore_pri_state(struct pci_dev *pdev)
{
u16 control = PCI_PRI_CTRL_ENABLE;
u32 reqs = pdev->pri_reqs_alloc;
int pos;
if (!pdev->pri_enabled)
return;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PRI);
if (!pos)
return;
pci_write_config_dword(pdev, pos + PCI_PRI_ALLOC_REQ, reqs);
pci_write_config_word(pdev, pos + PCI_PRI_CTRL, control);
}
int pci_reset_pri(struct pci_dev *pdev)
{
u16 control;
int pos;
if (WARN_ON(pdev->pri_enabled))
return -EBUSY;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PRI);
if (!pos)
return -EINVAL;
control = PCI_PRI_CTRL_RESET;
pci_write_config_word(pdev, pos + PCI_PRI_CTRL, control);
return 0;
}
int pci_enable_pasid(struct pci_dev *pdev, int features)
{
u16 control, supported;
int pos;
if (WARN_ON(pdev->pasid_enabled))
return -EBUSY;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PASID);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PASID_CAP, &supported);
supported &= PCI_PASID_CAP_EXEC | PCI_PASID_CAP_PRIV;
if ((supported & features) != features)
return -EINVAL;
control = PCI_PASID_CTRL_ENABLE | features;
pdev->pasid_features = features;
pci_write_config_word(pdev, pos + PCI_PASID_CTRL, control);
pdev->pasid_enabled = 1;
return 0;
}
void pci_disable_pasid(struct pci_dev *pdev)
{
u16 control = 0;
int pos;
if (WARN_ON(!pdev->pasid_enabled))
return;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PASID);
if (!pos)
return;
pci_write_config_word(pdev, pos + PCI_PASID_CTRL, control);
pdev->pasid_enabled = 0;
}
void pci_restore_pasid_state(struct pci_dev *pdev)
{
u16 control;
int pos;
if (!pdev->pasid_enabled)
return;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PASID);
if (!pos)
return;
control = PCI_PASID_CTRL_ENABLE | pdev->pasid_features;
pci_write_config_word(pdev, pos + PCI_PASID_CTRL, control);
}
int pci_pasid_features(struct pci_dev *pdev)
{
u16 supported;
int pos;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PASID);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PASID_CAP, &supported);
supported &= PCI_PASID_CAP_EXEC | PCI_PASID_CAP_PRIV;
return supported;
}
int pci_max_pasids(struct pci_dev *pdev)
{
u16 supported;
int pos;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_PASID);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PASID_CAP, &supported);
supported = (supported & PASID_NUMBER_MASK) >> PASID_NUMBER_SHIFT;
return (1 << supported);
}
