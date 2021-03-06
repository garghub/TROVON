static void pci_ptm_info(struct pci_dev *dev)\r\n{\r\nchar clock_desc[8];\r\nswitch (dev->ptm_granularity) {\r\ncase 0:\r\nsnprintf(clock_desc, sizeof(clock_desc), "unknown");\r\nbreak;\r\ncase 255:\r\nsnprintf(clock_desc, sizeof(clock_desc), ">254ns");\r\nbreak;\r\ndefault:\r\nsnprintf(clock_desc, sizeof(clock_desc), "%udns",\r\ndev->ptm_granularity);\r\nbreak;\r\n}\r\ndev_info(&dev->dev, "PTM enabled%s, %s granularity\n",\r\ndev->ptm_root ? " (root)" : "", clock_desc);\r\n}\r\nvoid pci_ptm_init(struct pci_dev *dev)\r\n{\r\nint pos;\r\nu32 cap, ctrl;\r\nu8 local_clock;\r\nstruct pci_dev *ups;\r\nif (!pci_is_pcie(dev))\r\nreturn;\r\npos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_PTM);\r\nif (!pos)\r\nreturn;\r\nif ((pci_pcie_type(dev) == PCI_EXP_TYPE_ENDPOINT ||\r\npci_pcie_type(dev) == PCI_EXP_TYPE_RC_END))\r\nreturn;\r\npci_read_config_dword(dev, pos + PCI_PTM_CAP, &cap);\r\nlocal_clock = (cap & PCI_PTM_GRANULARITY_MASK) >> 8;\r\nups = pci_upstream_bridge(dev);\r\nif (ups && ups->ptm_enabled) {\r\nctrl = PCI_PTM_CTRL_ENABLE;\r\nif (ups->ptm_granularity == 0)\r\ndev->ptm_granularity = 0;\r\nelse if (ups->ptm_granularity > local_clock)\r\ndev->ptm_granularity = ups->ptm_granularity;\r\n} else {\r\nif (cap & PCI_PTM_CAP_ROOT) {\r\nctrl = PCI_PTM_CTRL_ENABLE | PCI_PTM_CTRL_ROOT;\r\ndev->ptm_root = 1;\r\ndev->ptm_granularity = local_clock;\r\n} else\r\nreturn;\r\n}\r\nctrl |= dev->ptm_granularity << 8;\r\npci_write_config_dword(dev, pos + PCI_PTM_CTRL, ctrl);\r\ndev->ptm_enabled = 1;\r\npci_ptm_info(dev);\r\n}\r\nint pci_enable_ptm(struct pci_dev *dev, u8 *granularity)\r\n{\r\nint pos;\r\nu32 cap, ctrl;\r\nstruct pci_dev *ups;\r\nif (!pci_is_pcie(dev))\r\nreturn -EINVAL;\r\npos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_PTM);\r\nif (!pos)\r\nreturn -EINVAL;\r\npci_read_config_dword(dev, pos + PCI_PTM_CAP, &cap);\r\nif (!(cap & PCI_PTM_CAP_REQ))\r\nreturn -EINVAL;\r\nif (pci_pcie_type(dev) == PCI_EXP_TYPE_ENDPOINT) {\r\nups = pci_upstream_bridge(dev);\r\nif (!ups || !ups->ptm_enabled)\r\nreturn -EINVAL;\r\ndev->ptm_granularity = ups->ptm_granularity;\r\n} else if (pci_pcie_type(dev) == PCI_EXP_TYPE_RC_END) {\r\ndev->ptm_granularity = 0;\r\n} else\r\nreturn -EINVAL;\r\nctrl = PCI_PTM_CTRL_ENABLE;\r\nctrl |= dev->ptm_granularity << 8;\r\npci_write_config_dword(dev, pos + PCI_PTM_CTRL, ctrl);\r\ndev->ptm_enabled = 1;\r\npci_ptm_info(dev);\r\nif (granularity)\r\n*granularity = dev->ptm_granularity;\r\nreturn 0;\r\n}
