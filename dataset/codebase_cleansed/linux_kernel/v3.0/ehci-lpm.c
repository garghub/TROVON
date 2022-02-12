static int __maybe_unused ehci_lpm_set_da(struct ehci_hcd *ehci,
int dev_addr, int port_num)
{
u32 __iomem portsc;
ehci_dbg(ehci, "set dev address %d for port %d\n", dev_addr, port_num);
if (port_num > HCS_N_PORTS(ehci->hcs_params)) {
ehci_dbg(ehci, "invalid port number %d\n", port_num);
return -ENODEV;
}
portsc = ehci_readl(ehci, &ehci->regs->port_status[port_num-1]);
portsc &= ~PORT_DEV_ADDR;
portsc |= dev_addr<<25;
ehci_writel(ehci, portsc, &ehci->regs->port_status[port_num-1]);
return 0;
}
static int __maybe_unused ehci_lpm_check(struct ehci_hcd *ehci, int port)
{
u32 __iomem *portsc ;
u32 val32;
int retval;
portsc = &ehci->regs->port_status[port-1];
val32 = ehci_readl(ehci, portsc);
if (!(val32 & PORT_DEV_ADDR)) {
ehci_dbg(ehci, "LPM: no device attached\n");
return -ENODEV;
}
val32 |= PORT_LPM;
ehci_writel(ehci, val32, portsc);
msleep(5);
val32 |= PORT_SUSPEND;
ehci_dbg(ehci, "Sending LPM 0x%08x to port %d\n", val32, port);
ehci_writel(ehci, val32, portsc);
msleep(10);
retval = handshake(ehci, &ehci->regs->port_status[port-1], PORT_SSTS,
PORTSC_SUSPEND_STS_ACK, 125);
dbg_port(ehci, "LPM", port, val32);
if (retval != -ETIMEDOUT) {
ehci_dbg(ehci, "LPM: device ACK for LPM\n");
val32 |= PORT_LPM;
ehci_writel(ehci, val32, portsc);
msleep(10);
val32 |= PORT_RESUME;
ehci_writel(ehci, val32, portsc);
} else {
ehci_dbg(ehci, "LPM: device does not ACK, disable LPM %d\n",
retval);
val32 &= ~PORT_LPM;
retval = -ETIMEDOUT;
ehci_writel(ehci, val32, portsc);
}
return retval;
}
