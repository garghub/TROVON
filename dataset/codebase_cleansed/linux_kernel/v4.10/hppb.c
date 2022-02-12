static int hppb_probe(struct parisc_device *dev)
{
int status;
struct hppb_card *card = &hppb_card_head;
while(card->next) {
card = card->next;
}
if(card->hpa) {
card->next = kzalloc(sizeof(struct hppb_card), GFP_KERNEL);
if(!card->next) {
printk(KERN_ERR "HP-PB: Unable to allocate memory.\n");
return 1;
}
card = card->next;
}
printk(KERN_INFO "Found GeckoBoa at 0x%llx\n",
(unsigned long long) dev->hpa.start);
card->hpa = dev->hpa.start;
card->mmio_region.name = "HP-PB Bus";
card->mmio_region.flags = IORESOURCE_MEM;
card->mmio_region.start = gsc_readl(dev->hpa.start + IO_IO_LOW);
card->mmio_region.end = gsc_readl(dev->hpa.start + IO_IO_HIGH) - 1;
status = ccio_request_resource(dev, &card->mmio_region);
if(status < 0) {
printk(KERN_ERR "%s: failed to claim HP-PB bus space (%pR)\n",
__FILE__, &card->mmio_region);
}
return 0;
}
void __init hppb_init(void)
{
register_parisc_driver(&hppb_driver);
}
