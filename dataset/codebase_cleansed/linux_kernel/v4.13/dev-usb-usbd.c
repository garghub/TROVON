int __init bcm63xx_usbd_register(const struct bcm63xx_usbd_platform_data *pd)
{
const int irq_list[NUM_IRQ] = { IRQ_USBD,
IRQ_USBD_RXDMA0, IRQ_USBD_TXDMA0,
IRQ_USBD_RXDMA1, IRQ_USBD_TXDMA1,
IRQ_USBD_RXDMA2, IRQ_USBD_TXDMA2 };
int i;
if (!BCMCPU_IS_6328() && !BCMCPU_IS_6368())
return 0;
usbd_resources[0].start = bcm63xx_regset_address(RSET_USBD);
usbd_resources[0].end = usbd_resources[0].start + RSET_USBD_SIZE - 1;
usbd_resources[0].flags = IORESOURCE_MEM;
usbd_resources[1].start = bcm63xx_regset_address(RSET_USBDMA);
usbd_resources[1].end = usbd_resources[1].start + RSET_USBDMA_SIZE - 1;
usbd_resources[1].flags = IORESOURCE_MEM;
for (i = 0; i < NUM_IRQ; i++) {
struct resource *r = &usbd_resources[NUM_MMIO + i];
r->start = r->end = bcm63xx_get_irq_number(irq_list[i]);
r->flags = IORESOURCE_IRQ;
}
platform_device_add_data(&bcm63xx_usbd_device, pd, sizeof(*pd));
return platform_device_register(&bcm63xx_usbd_device);
}
