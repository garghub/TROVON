unsigned int __devinit pci_do_scan_bus(struct pci_bus *bus)\r\n{\r\nunsigned int max;\r\nmax = pci_scan_child_bus(bus);\r\npci_bus_add_devices(bus);\r\nreturn max;\r\n}
