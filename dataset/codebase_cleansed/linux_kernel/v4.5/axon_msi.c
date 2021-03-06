static inline void axon_msi_debug_setup(struct device_node *dn,\r\nstruct axon_msic *msic) { }\r\nstatic void msic_dcr_write(struct axon_msic *msic, unsigned int dcr_n, u32 val)\r\n{\r\npr_devel("axon_msi: dcr_write(0x%x, 0x%x)\n", val, dcr_n);\r\ndcr_write(msic->dcr_host, dcr_n, val);\r\n}\r\nstatic void axon_msi_cascade(struct irq_desc *desc)\r\n{\r\nstruct irq_chip *chip = irq_desc_get_chip(desc);\r\nstruct axon_msic *msic = irq_desc_get_handler_data(desc);\r\nu32 write_offset, msi;\r\nint idx;\r\nint retry = 0;\r\nwrite_offset = dcr_read(msic->dcr_host, MSIC_WRITE_OFFSET_REG);\r\npr_devel("axon_msi: original write_offset 0x%x\n", write_offset);\r\nwrite_offset &= MSIC_FIFO_SIZE_MASK;\r\nwhile (msic->read_offset != write_offset && retry < 100) {\r\nidx = msic->read_offset / sizeof(__le32);\r\nmsi = le32_to_cpu(msic->fifo_virt[idx]);\r\nmsi &= 0xFFFF;\r\npr_devel("axon_msi: woff %x roff %x msi %x\n",\r\nwrite_offset, msic->read_offset, msi);\r\nif (msi < nr_irqs && irq_get_chip_data(msi) == msic) {\r\ngeneric_handle_irq(msi);\r\nmsic->fifo_virt[idx] = cpu_to_le32(0xffffffff);\r\n} else {\r\nudelay(1);\r\nretry++;\r\npr_devel("axon_msi: invalid irq 0x%x!\n", msi);\r\ncontinue;\r\n}\r\nif (retry) {\r\npr_devel("axon_msi: late irq 0x%x, retry %d\n",\r\nmsi, retry);\r\nretry = 0;\r\n}\r\nmsic->read_offset += MSIC_FIFO_ENTRY_SIZE;\r\nmsic->read_offset &= MSIC_FIFO_SIZE_MASK;\r\n}\r\nif (retry) {\r\nprintk(KERN_WARNING "axon_msi: irq timed out\n");\r\nmsic->read_offset += MSIC_FIFO_ENTRY_SIZE;\r\nmsic->read_offset &= MSIC_FIFO_SIZE_MASK;\r\n}\r\nchip->irq_eoi(&desc->irq_data);\r\n}\r\nstatic struct axon_msic *find_msi_translator(struct pci_dev *dev)\r\n{\r\nstruct irq_domain *irq_domain;\r\nstruct device_node *dn, *tmp;\r\nconst phandle *ph;\r\nstruct axon_msic *msic = NULL;\r\ndn = of_node_get(pci_device_to_OF_node(dev));\r\nif (!dn) {\r\ndev_dbg(&dev->dev, "axon_msi: no pci_dn found\n");\r\nreturn NULL;\r\n}\r\nfor (; dn; dn = of_get_next_parent(dn)) {\r\nph = of_get_property(dn, "msi-translator", NULL);\r\nif (ph)\r\nbreak;\r\n}\r\nif (!ph) {\r\ndev_dbg(&dev->dev,\r\n"axon_msi: no msi-translator property found\n");\r\ngoto out_error;\r\n}\r\ntmp = dn;\r\ndn = of_find_node_by_phandle(*ph);\r\nof_node_put(tmp);\r\nif (!dn) {\r\ndev_dbg(&dev->dev,\r\n"axon_msi: msi-translator doesn't point to a node\n");\r\ngoto out_error;\r\n}\r\nirq_domain = irq_find_host(dn);\r\nif (!irq_domain) {\r\ndev_dbg(&dev->dev, "axon_msi: no irq_domain found for node %s\n",\r\ndn->full_name);\r\ngoto out_error;\r\n}\r\nmsic = irq_domain->host_data;\r\nout_error:\r\nof_node_put(dn);\r\nreturn msic;\r\n}\r\nstatic int setup_msi_msg_address(struct pci_dev *dev, struct msi_msg *msg)\r\n{\r\nstruct device_node *dn;\r\nstruct msi_desc *entry;\r\nint len;\r\nconst u32 *prop;\r\ndn = of_node_get(pci_device_to_OF_node(dev));\r\nif (!dn) {\r\ndev_dbg(&dev->dev, "axon_msi: no pci_dn found\n");\r\nreturn -ENODEV;\r\n}\r\nentry = first_pci_msi_entry(dev);\r\nfor (; dn; dn = of_get_next_parent(dn)) {\r\nif (entry->msi_attrib.is_64) {\r\nprop = of_get_property(dn, "msi-address-64", &len);\r\nif (prop)\r\nbreak;\r\n}\r\nprop = of_get_property(dn, "msi-address-32", &len);\r\nif (prop)\r\nbreak;\r\n}\r\nif (!prop) {\r\ndev_dbg(&dev->dev,\r\n"axon_msi: no msi-address-(32|64) properties found\n");\r\nreturn -ENOENT;\r\n}\r\nswitch (len) {\r\ncase 8:\r\nmsg->address_hi = prop[0];\r\nmsg->address_lo = prop[1];\r\nbreak;\r\ncase 4:\r\nmsg->address_hi = 0;\r\nmsg->address_lo = prop[0];\r\nbreak;\r\ndefault:\r\ndev_dbg(&dev->dev,\r\n"axon_msi: malformed msi-address-(32|64) property\n");\r\nof_node_put(dn);\r\nreturn -EINVAL;\r\n}\r\nof_node_put(dn);\r\nreturn 0;\r\n}\r\nstatic int axon_msi_setup_msi_irqs(struct pci_dev *dev, int nvec, int type)\r\n{\r\nunsigned int virq, rc;\r\nstruct msi_desc *entry;\r\nstruct msi_msg msg;\r\nstruct axon_msic *msic;\r\nmsic = find_msi_translator(dev);\r\nif (!msic)\r\nreturn -ENODEV;\r\nrc = setup_msi_msg_address(dev, &msg);\r\nif (rc)\r\nreturn rc;\r\nfor_each_pci_msi_entry(entry, dev) {\r\nvirq = irq_create_direct_mapping(msic->irq_domain);\r\nif (virq == NO_IRQ) {\r\ndev_warn(&dev->dev,\r\n"axon_msi: virq allocation failed!\n");\r\nreturn -1;\r\n}\r\ndev_dbg(&dev->dev, "axon_msi: allocated virq 0x%x\n", virq);\r\nirq_set_msi_desc(virq, entry);\r\nmsg.data = virq;\r\npci_write_msi_msg(virq, &msg);\r\n}\r\nreturn 0;\r\n}\r\nstatic void axon_msi_teardown_msi_irqs(struct pci_dev *dev)\r\n{\r\nstruct msi_desc *entry;\r\ndev_dbg(&dev->dev, "axon_msi: tearing down msi irqs\n");\r\nfor_each_pci_msi_entry(entry, dev) {\r\nif (entry->irq == NO_IRQ)\r\ncontinue;\r\nirq_set_msi_desc(entry->irq, NULL);\r\nirq_dispose_mapping(entry->irq);\r\n}\r\n}\r\nstatic int msic_host_map(struct irq_domain *h, unsigned int virq,\r\nirq_hw_number_t hw)\r\n{\r\nirq_set_chip_data(virq, h->host_data);\r\nirq_set_chip_and_handler(virq, &msic_irq_chip, handle_simple_irq);\r\nreturn 0;\r\n}\r\nstatic void axon_msi_shutdown(struct platform_device *device)\r\n{\r\nstruct axon_msic *msic = dev_get_drvdata(&device->dev);\r\nu32 tmp;\r\npr_devel("axon_msi: disabling %s\n",\r\nirq_domain_get_of_node(msic->irq_domain)->full_name);\r\ntmp = dcr_read(msic->dcr_host, MSIC_CTRL_REG);\r\ntmp &= ~MSIC_CTRL_ENABLE & ~MSIC_CTRL_IRQ_ENABLE;\r\nmsic_dcr_write(msic, MSIC_CTRL_REG, tmp);\r\n}\r\nstatic int axon_msi_probe(struct platform_device *device)\r\n{\r\nstruct device_node *dn = device->dev.of_node;\r\nstruct axon_msic *msic;\r\nunsigned int virq;\r\nint dcr_base, dcr_len;\r\npr_devel("axon_msi: setting up dn %s\n", dn->full_name);\r\nmsic = kzalloc(sizeof(struct axon_msic), GFP_KERNEL);\r\nif (!msic) {\r\nprintk(KERN_ERR "axon_msi: couldn't allocate msic for %s\n",\r\ndn->full_name);\r\ngoto out;\r\n}\r\ndcr_base = dcr_resource_start(dn, 0);\r\ndcr_len = dcr_resource_len(dn, 0);\r\nif (dcr_base == 0 || dcr_len == 0) {\r\nprintk(KERN_ERR\r\n"axon_msi: couldn't parse dcr properties on %s\n",\r\ndn->full_name);\r\ngoto out_free_msic;\r\n}\r\nmsic->dcr_host = dcr_map(dn, dcr_base, dcr_len);\r\nif (!DCR_MAP_OK(msic->dcr_host)) {\r\nprintk(KERN_ERR "axon_msi: dcr_map failed for %s\n",\r\ndn->full_name);\r\ngoto out_free_msic;\r\n}\r\nmsic->fifo_virt = dma_alloc_coherent(&device->dev, MSIC_FIFO_SIZE_BYTES,\r\n&msic->fifo_phys, GFP_KERNEL);\r\nif (!msic->fifo_virt) {\r\nprintk(KERN_ERR "axon_msi: couldn't allocate fifo for %s\n",\r\ndn->full_name);\r\ngoto out_free_msic;\r\n}\r\nvirq = irq_of_parse_and_map(dn, 0);\r\nif (virq == NO_IRQ) {\r\nprintk(KERN_ERR "axon_msi: irq parse and map failed for %s\n",\r\ndn->full_name);\r\ngoto out_free_fifo;\r\n}\r\nmemset(msic->fifo_virt, 0xff, MSIC_FIFO_SIZE_BYTES);\r\nmsic->irq_domain = irq_domain_add_nomap(dn, 65536, &msic_host_ops, msic);\r\nif (!msic->irq_domain) {\r\nprintk(KERN_ERR "axon_msi: couldn't allocate irq_domain for %s\n",\r\ndn->full_name);\r\ngoto out_free_fifo;\r\n}\r\nirq_set_handler_data(virq, msic);\r\nirq_set_chained_handler(virq, axon_msi_cascade);\r\npr_devel("axon_msi: irq 0x%x setup for axon_msi\n", virq);\r\nmsic_dcr_write(msic, MSIC_BASE_ADDR_HI_REG, msic->fifo_phys >> 32);\r\nmsic_dcr_write(msic, MSIC_BASE_ADDR_LO_REG,\r\nmsic->fifo_phys & 0xFFFFFFFF);\r\nmsic_dcr_write(msic, MSIC_CTRL_REG,\r\nMSIC_CTRL_IRQ_ENABLE | MSIC_CTRL_ENABLE |\r\nMSIC_CTRL_FIFO_SIZE);\r\nmsic->read_offset = dcr_read(msic->dcr_host, MSIC_WRITE_OFFSET_REG)\r\n& MSIC_FIFO_SIZE_MASK;\r\ndev_set_drvdata(&device->dev, msic);\r\ncell_pci_controller_ops.setup_msi_irqs = axon_msi_setup_msi_irqs;\r\ncell_pci_controller_ops.teardown_msi_irqs = axon_msi_teardown_msi_irqs;\r\naxon_msi_debug_setup(dn, msic);\r\nprintk(KERN_DEBUG "axon_msi: setup MSIC on %s\n", dn->full_name);\r\nreturn 0;\r\nout_free_fifo:\r\ndma_free_coherent(&device->dev, MSIC_FIFO_SIZE_BYTES, msic->fifo_virt,\r\nmsic->fifo_phys);\r\nout_free_msic:\r\nkfree(msic);\r\nout:\r\nreturn -1;\r\n}\r\nstatic int __init axon_msi_init(void)\r\n{\r\nreturn platform_driver_register(&axon_msi_driver);\r\n}\r\nstatic int msic_set(void *data, u64 val)\r\n{\r\nstruct axon_msic *msic = data;\r\nout_le32(msic->trigger, val);\r\nreturn 0;\r\n}\r\nstatic int msic_get(void *data, u64 *val)\r\n{\r\n*val = 0;\r\nreturn 0;\r\n}\r\nvoid axon_msi_debug_setup(struct device_node *dn, struct axon_msic *msic)\r\n{\r\nchar name[8];\r\nu64 addr;\r\naddr = of_translate_address(dn, of_get_property(dn, "reg", NULL));\r\nif (addr == OF_BAD_ADDR) {\r\npr_devel("axon_msi: couldn't translate reg property\n");\r\nreturn;\r\n}\r\nmsic->trigger = ioremap(addr, 0x4);\r\nif (!msic->trigger) {\r\npr_devel("axon_msi: ioremap failed\n");\r\nreturn;\r\n}\r\nsnprintf(name, sizeof(name), "msic_%d", of_node_to_nid(dn));\r\nif (!debugfs_create_file(name, 0600, powerpc_debugfs_root,\r\nmsic, &fops_msic)) {\r\npr_devel("axon_msi: debugfs_create_file failed!\n");\r\nreturn;\r\n}\r\n}
