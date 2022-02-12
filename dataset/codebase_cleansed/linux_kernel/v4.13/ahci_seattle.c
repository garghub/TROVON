static ssize_t seattle_transmit_led_message(struct ata_port *ap, u32 state,
ssize_t size)
{
struct ahci_host_priv *hpriv = ap->host->private_data;
struct ahci_port_priv *pp = ap->private_data;
struct seattle_plat_data *plat_data = hpriv->plat_data;
unsigned long flags;
int pmp;
struct ahci_em_priv *emp;
u32 val;
pmp = (state & EM_MSG_LED_PMP_SLOT) >> 8;
if (pmp >= EM_MAX_SLOTS)
return -EINVAL;
emp = &pp->em_priv[pmp];
val = ioread32(plat_data->sgpio_ctrl);
if (state & ACTIVITY_MASK)
val |= 1 << ACTIVITY_BIT_POS((ap->port_no));
else
val &= ~(1 << ACTIVITY_BIT_POS((ap->port_no)));
if (state & LOCATE_MASK)
val |= 1 << LOCATE_BIT_POS((ap->port_no));
else
val &= ~(1 << LOCATE_BIT_POS((ap->port_no)));
if (state & FAULT_MASK)
val |= 1 << FAULT_BIT_POS((ap->port_no));
else
val &= ~(1 << FAULT_BIT_POS((ap->port_no)));
iowrite32(val, plat_data->sgpio_ctrl);
spin_lock_irqsave(ap->lock, flags);
emp->led_state = state;
spin_unlock_irqrestore(ap->lock, flags);
return size;
}
static const struct ata_port_info *ahci_seattle_get_port_info(
struct platform_device *pdev, struct ahci_host_priv *hpriv)
{
struct device *dev = &pdev->dev;
struct seattle_plat_data *plat_data;
u32 val;
plat_data = devm_kzalloc(dev, sizeof(*plat_data), GFP_KERNEL);
if (!plat_data)
return &ahci_port_info;
plat_data->sgpio_ctrl = devm_ioremap_resource(dev,
platform_get_resource(pdev, IORESOURCE_MEM, 1));
if (IS_ERR(plat_data->sgpio_ctrl))
return &ahci_port_info;
val = ioread32(plat_data->sgpio_ctrl);
if (!(val & 0xf))
return &ahci_port_info;
hpriv->em_loc = 0;
hpriv->em_buf_sz = 4;
hpriv->em_msg_type = EM_MSG_TYPE_LED;
hpriv->plat_data = plat_data;
dev_info(dev, "SGPIO LED control is enabled.\n");
return &ahci_port_seattle_info;
}
static int ahci_seattle_probe(struct platform_device *pdev)
{
int rc;
struct ahci_host_priv *hpriv;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
rc = ahci_platform_init_host(pdev, hpriv,
ahci_seattle_get_port_info(pdev, hpriv),
&ahci_platform_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
