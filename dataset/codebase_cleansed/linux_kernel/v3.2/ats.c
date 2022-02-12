static int ats_alloc_one(struct pci_dev *dev, int ps)
{
int pos;
u16 cap;
struct pci_ats *ats;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ATS);
if (!pos)
return -ENODEV;
ats = kzalloc(sizeof(*ats), GFP_KERNEL);
if (!ats)
return -ENOMEM;
ats->pos = pos;
ats->stu = ps;
pci_read_config_word(dev, pos + PCI_ATS_CAP, &cap);
ats->qdep = PCI_ATS_CAP_QDEP(cap) ? PCI_ATS_CAP_QDEP(cap) :
PCI_ATS_MAX_QDEP;
dev->ats = ats;
return 0;
}
static void ats_free_one(struct pci_dev *dev)
{
kfree(dev->ats);
dev->ats = NULL;
}
int pci_enable_ats(struct pci_dev *dev, int ps)
{
int rc;
u16 ctrl;
BUG_ON(dev->ats && dev->ats->is_enabled);
if (ps < PCI_ATS_MIN_STU)
return -EINVAL;
if (dev->is_physfn || dev->is_virtfn) {
struct pci_dev *pdev = dev->is_physfn ? dev : dev->physfn;
mutex_lock(&pdev->sriov->lock);
if (pdev->ats)
rc = pdev->ats->stu == ps ? 0 : -EINVAL;
else
rc = ats_alloc_one(pdev, ps);
if (!rc)
pdev->ats->ref_cnt++;
mutex_unlock(&pdev->sriov->lock);
if (rc)
return rc;
}
if (!dev->is_physfn) {
rc = ats_alloc_one(dev, ps);
if (rc)
return rc;
}
ctrl = PCI_ATS_CTRL_ENABLE;
if (!dev->is_virtfn)
ctrl |= PCI_ATS_CTRL_STU(ps - PCI_ATS_MIN_STU);
pci_write_config_word(dev, dev->ats->pos + PCI_ATS_CTRL, ctrl);
dev->ats->is_enabled = 1;
return 0;
}
void pci_disable_ats(struct pci_dev *dev)
{
u16 ctrl;
BUG_ON(!dev->ats || !dev->ats->is_enabled);
pci_read_config_word(dev, dev->ats->pos + PCI_ATS_CTRL, &ctrl);
ctrl &= ~PCI_ATS_CTRL_ENABLE;
pci_write_config_word(dev, dev->ats->pos + PCI_ATS_CTRL, ctrl);
dev->ats->is_enabled = 0;
if (dev->is_physfn || dev->is_virtfn) {
struct pci_dev *pdev = dev->is_physfn ? dev : dev->physfn;
mutex_lock(&pdev->sriov->lock);
pdev->ats->ref_cnt--;
if (!pdev->ats->ref_cnt)
ats_free_one(pdev);
mutex_unlock(&pdev->sriov->lock);
}
if (!dev->is_physfn)
ats_free_one(dev);
}
int pci_ats_queue_depth(struct pci_dev *dev)
{
int pos;
u16 cap;
if (dev->is_virtfn)
return 0;
if (dev->ats)
return dev->ats->qdep;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ATS);
if (!pos)
return -ENODEV;
pci_read_config_word(dev, pos + PCI_ATS_CAP, &cap);
return PCI_ATS_CAP_QDEP(cap) ? PCI_ATS_CAP_QDEP(cap) :
PCI_ATS_MAX_QDEP;
}
int pci_enable_pri(struct pci_dev *pdev, u32 reqs)
{
u16 control, status;
u32 max_requests;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PRI_CAP);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, &control);
pci_read_config_word(pdev, pos + PCI_PRI_STATUS_OFF, &status);
if ((control & PCI_PRI_ENABLE) || !(status & PCI_PRI_STATUS_STOPPED))
return -EBUSY;
pci_read_config_dword(pdev, pos + PCI_PRI_MAX_REQ_OFF, &max_requests);
reqs = min(max_requests, reqs);
pci_write_config_dword(pdev, pos + PCI_PRI_ALLOC_REQ_OFF, reqs);
control |= PCI_PRI_ENABLE;
pci_write_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, control);
return 0;
}
void pci_disable_pri(struct pci_dev *pdev)
{
u16 control;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PRI_CAP);
if (!pos)
return;
pci_read_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, &control);
control &= ~PCI_PRI_ENABLE;
pci_write_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, control);
}
bool pci_pri_enabled(struct pci_dev *pdev)
{
u16 control;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PRI_CAP);
if (!pos)
return false;
pci_read_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, &control);
return (control & PCI_PRI_ENABLE) ? true : false;
}
int pci_reset_pri(struct pci_dev *pdev)
{
u16 control;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PRI_CAP);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, &control);
if (control & PCI_PRI_ENABLE)
return -EBUSY;
control |= PCI_PRI_RESET;
pci_write_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, control);
return 0;
}
bool pci_pri_stopped(struct pci_dev *pdev)
{
u16 control, status;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PRI_CAP);
if (!pos)
return true;
pci_read_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, &control);
pci_read_config_word(pdev, pos + PCI_PRI_STATUS_OFF, &status);
if (control & PCI_PRI_ENABLE)
return false;
return (status & PCI_PRI_STATUS_STOPPED) ? true : false;
}
int pci_pri_status(struct pci_dev *pdev)
{
u16 status, control;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PRI_CAP);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PRI_CONTROL_OFF, &control);
pci_read_config_word(pdev, pos + PCI_PRI_STATUS_OFF, &status);
if (control & PCI_PRI_ENABLE)
status &= ~PCI_PRI_STATUS_STOPPED;
return status;
}
int pci_enable_pasid(struct pci_dev *pdev, int features)
{
u16 control, supported;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PASID_CAP);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PASID_CONTROL_OFF, &control);
pci_read_config_word(pdev, pos + PCI_PASID_CAP_OFF, &supported);
if (!(supported & PCI_PASID_ENABLE))
return -EINVAL;
supported &= PCI_PASID_EXEC | PCI_PASID_PRIV;
if ((supported & features) != features)
return -EINVAL;
control = PCI_PASID_ENABLE | features;
pci_write_config_word(pdev, pos + PCI_PASID_CONTROL_OFF, control);
return 0;
}
void pci_disable_pasid(struct pci_dev *pdev)
{
u16 control = 0;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PASID_CAP);
if (!pos)
return;
pci_write_config_word(pdev, pos + PCI_PASID_CONTROL_OFF, control);
}
int pci_pasid_features(struct pci_dev *pdev)
{
u16 supported;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PASID_CAP);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PASID_CAP_OFF, &supported);
supported &= PCI_PASID_ENABLE | PCI_PASID_EXEC | PCI_PASID_PRIV;
return supported;
}
int pci_max_pasids(struct pci_dev *pdev)
{
u16 supported;
int pos;
pos = pci_find_ext_capability(pdev, PCI_PASID_CAP);
if (!pos)
return -EINVAL;
pci_read_config_word(pdev, pos + PCI_PASID_CAP_OFF, &supported);
supported = (supported & PASID_NUMBER_MASK) >> PASID_NUMBER_SHIFT;
return (1 << supported);
}
