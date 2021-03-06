static inline void set_bios_x(void)
{
pcibios_enabled = 1;
set_memory_x(PAGE_OFFSET + BIOS_BEGIN, (BIOS_END - BIOS_BEGIN) >> PAGE_SHIFT);
if (__supported_pte_mask & _PAGE_NX)
printk(KERN_INFO "PCI : PCI BIOS aera is rw and x. Use pci=nobios if you want it NX.\n");
}
static unsigned long bios32_service(unsigned long service)
{
unsigned char return_code;
unsigned long address;
unsigned long length;
unsigned long entry;
unsigned long flags;
local_irq_save(flags);
__asm__("lcall *(%%edi); cld"
: "=a" (return_code),
"=b" (address),
"=c" (length),
"=d" (entry)
: "0" (service),
"1" (0),
"D" (&bios32_indirect));
local_irq_restore(flags);
switch (return_code) {
case 0:
return address + entry;
case 0x80:
printk(KERN_WARNING "bios32_service(0x%lx): not present\n", service);
return 0;
default:
printk(KERN_WARNING "bios32_service(0x%lx): returned 0x%x -- BIOS bug!\n",
service, return_code);
return 0;
}
}
static int __devinit check_pcibios(void)
{
u32 signature, eax, ebx, ecx;
u8 status, major_ver, minor_ver, hw_mech;
unsigned long flags, pcibios_entry;
if ((pcibios_entry = bios32_service(PCI_SERVICE))) {
pci_indirect.address = pcibios_entry + PAGE_OFFSET;
local_irq_save(flags);
__asm__(
"lcall *(%%edi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=d" (signature),
"=a" (eax),
"=b" (ebx),
"=c" (ecx)
: "1" (PCIBIOS_PCI_BIOS_PRESENT),
"D" (&pci_indirect)
: "memory");
local_irq_restore(flags);
status = (eax >> 8) & 0xff;
hw_mech = eax & 0xff;
major_ver = (ebx >> 8) & 0xff;
minor_ver = ebx & 0xff;
if (pcibios_last_bus < 0)
pcibios_last_bus = ecx & 0xff;
DBG("PCI: BIOS probe returned s=%02x hw=%02x ver=%02x.%02x l=%02x\n",
status, hw_mech, major_ver, minor_ver, pcibios_last_bus);
if (status || signature != PCI_SIGNATURE) {
printk (KERN_ERR "PCI: BIOS BUG #%x[%08x] found\n",
status, signature);
return 0;
}
printk(KERN_INFO "PCI: PCI BIOS revision %x.%02x entry at 0x%lx, last bus=%d\n",
major_ver, minor_ver, pcibios_entry, pcibios_last_bus);
#ifdef CONFIG_PCI_DIRECT
if (!(hw_mech & PCIBIOS_HW_TYPE1))
pci_probe &= ~PCI_PROBE_CONF1;
if (!(hw_mech & PCIBIOS_HW_TYPE2))
pci_probe &= ~PCI_PROBE_CONF2;
#endif
return 1;
}
return 0;
}
static int pci_bios_read(unsigned int seg, unsigned int bus,
unsigned int devfn, int reg, int len, u32 *value)
{
unsigned long result = 0;
unsigned long flags;
unsigned long bx = (bus << 8) | devfn;
if (!value || (bus > 255) || (devfn > 255) || (reg > 255))
return -EINVAL;
raw_spin_lock_irqsave(&pci_config_lock, flags);
switch (len) {
case 1:
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=c" (*value),
"=a" (result)
: "1" (PCIBIOS_READ_CONFIG_BYTE),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
*value &= 0xff;
break;
case 2:
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=c" (*value),
"=a" (result)
: "1" (PCIBIOS_READ_CONFIG_WORD),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
*value &= 0xffff;
break;
case 4:
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=c" (*value),
"=a" (result)
: "1" (PCIBIOS_READ_CONFIG_DWORD),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
}
raw_spin_unlock_irqrestore(&pci_config_lock, flags);
return (int)((result & 0xff00) >> 8);
}
static int pci_bios_write(unsigned int seg, unsigned int bus,
unsigned int devfn, int reg, int len, u32 value)
{
unsigned long result = 0;
unsigned long flags;
unsigned long bx = (bus << 8) | devfn;
if ((bus > 255) || (devfn > 255) || (reg > 255))
return -EINVAL;
raw_spin_lock_irqsave(&pci_config_lock, flags);
switch (len) {
case 1:
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (result)
: "0" (PCIBIOS_WRITE_CONFIG_BYTE),
"c" (value),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
case 2:
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (result)
: "0" (PCIBIOS_WRITE_CONFIG_WORD),
"c" (value),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
case 4:
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (result)
: "0" (PCIBIOS_WRITE_CONFIG_DWORD),
"c" (value),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
}
raw_spin_unlock_irqrestore(&pci_config_lock, flags);
return (int)((result & 0xff00) >> 8);
}
static struct pci_raw_ops * __devinit pci_find_bios(void)
{
union bios32 *check;
unsigned char sum;
int i, length;
for (check = (union bios32 *) __va(0xe0000);
check <= (union bios32 *) __va(0xffff0);
++check) {
long sig;
if (probe_kernel_address(&check->fields.signature, sig))
continue;
if (check->fields.signature != BIOS32_SIGNATURE)
continue;
length = check->fields.length * 16;
if (!length)
continue;
sum = 0;
for (i = 0; i < length ; ++i)
sum += check->chars[i];
if (sum != 0)
continue;
if (check->fields.revision != 0) {
printk("PCI: unsupported BIOS32 revision %d at 0x%p\n",
check->fields.revision, check);
continue;
}
DBG("PCI: BIOS32 Service Directory structure at 0x%p\n", check);
if (check->fields.entry >= 0x100000) {
printk("PCI: BIOS32 entry (0x%p) in high memory, "
"cannot use.\n", check);
return NULL;
} else {
unsigned long bios32_entry = check->fields.entry;
DBG("PCI: BIOS32 Service Directory entry at 0x%lx\n",
bios32_entry);
bios32_indirect.address = bios32_entry + PAGE_OFFSET;
set_bios_x();
if (check_pcibios())
return &pci_bios_access;
}
break;
}
return NULL;
}
struct irq_routing_table * pcibios_get_irq_routing_table(void)
{
struct irq_routing_options opt;
struct irq_routing_table *rt = NULL;
int ret, map;
unsigned long page;
if (!pci_bios_present)
return NULL;
page = __get_free_page(GFP_KERNEL);
if (!page)
return NULL;
opt.table = (struct irq_info *) page;
opt.size = PAGE_SIZE;
opt.segment = __KERNEL_DS;
DBG("PCI: Fetching IRQ routing table... ");
__asm__("push %%es\n\t"
"push %%ds\n\t"
"pop %%es\n\t"
"lcall *(%%esi); cld\n\t"
"pop %%es\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (ret),
"=b" (map),
"=m" (opt)
: "0" (PCIBIOS_GET_ROUTING_OPTIONS),
"1" (0),
"D" ((long) &opt),
"S" (&pci_indirect),
"m" (opt)
: "memory");
DBG("OK ret=%d, size=%d, map=%x\n", ret, opt.size, map);
if (ret & 0xff00)
printk(KERN_ERR "PCI: Error %02x when fetching IRQ routing table.\n", (ret >> 8) & 0xff);
else if (opt.size) {
rt = kmalloc(sizeof(struct irq_routing_table) + opt.size, GFP_KERNEL);
if (rt) {
memset(rt, 0, sizeof(struct irq_routing_table));
rt->size = opt.size + sizeof(struct irq_routing_table);
rt->exclusive_irqs = map;
memcpy(rt->slots, (void *) page, opt.size);
printk(KERN_INFO "PCI: Using BIOS Interrupt Routing Table\n");
}
}
free_page(page);
return rt;
}
int pcibios_set_irq_routing(struct pci_dev *dev, int pin, int irq)
{
int ret;
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (ret)
: "0" (PCIBIOS_SET_PCI_HW_INT),
"b" ((dev->bus->number << 8) | dev->devfn),
"c" ((irq << 8) | (pin + 10)),
"S" (&pci_indirect));
return !(ret & 0xff00);
}
void __init pci_pcbios_init(void)
{
if ((pci_probe & PCI_PROBE_BIOS)
&& ((raw_pci_ops = pci_find_bios()))) {
pci_bios_present = 1;
}
}
