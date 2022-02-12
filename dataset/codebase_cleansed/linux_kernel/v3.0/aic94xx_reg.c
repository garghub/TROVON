static void asd_write_byte(struct asd_ha_struct *asd_ha,
unsigned long offs, u8 val)
{
if (unlikely(asd_ha->iospace))
outb(val,
(unsigned long)asd_ha->io_handle[0].addr + (offs & 0xFF));
else
writeb(val, asd_ha->io_handle[0].addr + offs);
wmb();
}
static void asd_write_word(struct asd_ha_struct *asd_ha,
unsigned long offs, u16 val)
{
if (unlikely(asd_ha->iospace))
outw(val,
(unsigned long)asd_ha->io_handle[0].addr + (offs & 0xFF));
else
writew(val, asd_ha->io_handle[0].addr + offs);
wmb();
}
static void asd_write_dword(struct asd_ha_struct *asd_ha,
unsigned long offs, u32 val)
{
if (unlikely(asd_ha->iospace))
outl(val,
(unsigned long)asd_ha->io_handle[0].addr + (offs & 0xFF));
else
writel(val, asd_ha->io_handle[0].addr + offs);
wmb();
}
static u8 asd_read_byte(struct asd_ha_struct *asd_ha, unsigned long offs)
{
u8 val;
if (unlikely(asd_ha->iospace))
val = inb((unsigned long) asd_ha->io_handle[0].addr
+ (offs & 0xFF));
else
val = readb(asd_ha->io_handle[0].addr + offs);
rmb();
return val;
}
static u16 asd_read_word(struct asd_ha_struct *asd_ha,
unsigned long offs)
{
u16 val;
if (unlikely(asd_ha->iospace))
val = inw((unsigned long)asd_ha->io_handle[0].addr
+ (offs & 0xFF));
else
val = readw(asd_ha->io_handle[0].addr + offs);
rmb();
return val;
}
static u32 asd_read_dword(struct asd_ha_struct *asd_ha,
unsigned long offs)
{
u32 val;
if (unlikely(asd_ha->iospace))
val = inl((unsigned long) asd_ha->io_handle[0].addr
+ (offs & 0xFF));
else
val = readl(asd_ha->io_handle[0].addr + offs);
rmb();
return val;
}
static inline u32 asd_mem_offs_swa(void)
{
return 0;
}
static inline u32 asd_mem_offs_swc(void)
{
return asd_mem_offs_swa() + MBAR0_SWA_SIZE;
}
static inline u32 asd_mem_offs_swb(void)
{
return asd_mem_offs_swc() + MBAR0_SWC_SIZE + 0x20;
}
static void asd_move_swb(struct asd_ha_struct *asd_ha, u32 reg)
{
u32 base = reg & ~(MBAR0_SWB_SIZE-1);
pci_write_config_dword(asd_ha->pcidev, PCI_CONF_MBAR0_SWB, base);
asd_ha->io_handle[0].swb_base = base;
}
static void __asd_write_reg_byte(struct asd_ha_struct *asd_ha, u32 reg, u8 val)
{
struct asd_ha_addrspace *io_handle=&asd_ha->io_handle[0];
BUG_ON(reg >= 0xC0000000 || reg < ALL_BASE_ADDR);
if (io_handle->swa_base <= reg
&& reg < io_handle->swa_base + MBAR0_SWA_SIZE)
asd_write_swa_byte (asd_ha, reg,val);
else if (io_handle->swb_base <= reg
&& reg < io_handle->swb_base + MBAR0_SWB_SIZE)
asd_write_swb_byte (asd_ha, reg, val);
else if (io_handle->swc_base <= reg
&& reg < io_handle->swc_base + MBAR0_SWC_SIZE)
asd_write_swc_byte (asd_ha, reg, val);
else {
asd_move_swb(asd_ha, reg);
asd_write_swb_byte (asd_ha, reg, val);
}
}
static u8 __asd_read_reg_byte(struct asd_ha_struct *asd_ha, u32 reg)
{
struct asd_ha_addrspace *io_handle=&asd_ha->io_handle[0];
u8 val;
BUG_ON(reg >= 0xC0000000 || reg < ALL_BASE_ADDR);
if (io_handle->swa_base <= reg
&& reg < io_handle->swa_base + MBAR0_SWA_SIZE)
val = asd_read_swa_byte (asd_ha, reg);
else if (io_handle->swb_base <= reg
&& reg < io_handle->swb_base + MBAR0_SWB_SIZE)
val = asd_read_swb_byte (asd_ha, reg);
else if (io_handle->swc_base <= reg
&& reg < io_handle->swc_base + MBAR0_SWC_SIZE)
val = asd_read_swc_byte (asd_ha, reg);
else {
asd_move_swb(asd_ha, reg);
val = asd_read_swb_byte (asd_ha, reg);
}
return val;
}
void asd_read_reg_string(struct asd_ha_struct *asd_ha, void *dst,
u32 offs, int count)
{
u8 *p = dst;
unsigned long flags;
spin_lock_irqsave(&asd_ha->iolock, flags);
for ( ; count > 0; count--, offs++, p++)
*p = __asd_read_reg_byte(asd_ha, offs);
spin_unlock_irqrestore(&asd_ha->iolock, flags);
}
void asd_write_reg_string(struct asd_ha_struct *asd_ha, void *src,
u32 offs, int count)
{
u8 *p = src;
unsigned long flags;
spin_lock_irqsave(&asd_ha->iolock, flags);
for ( ; count > 0; count--, offs++, p++)
__asd_write_reg_byte(asd_ha, offs, *p);
spin_unlock_irqrestore(&asd_ha->iolock, flags);
}
