u8 r8712_read8(struct _adapter *adapter, u32 addr)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
return hdl->io_ops._read8(hdl, addr);
}
u16 r8712_read16(struct _adapter *adapter, u32 addr)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
return hdl->io_ops._read16(hdl, addr);
}
u32 r8712_read32(struct _adapter *adapter, u32 addr)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
return hdl->io_ops._read32(hdl, addr);
}
void r8712_write8(struct _adapter *adapter, u32 addr, u8 val)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
hdl->io_ops._write8(hdl, addr, val);
}
void r8712_write16(struct _adapter *adapter, u32 addr, u16 val)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
hdl->io_ops._write16(hdl, addr, val);
}
void r8712_write32(struct _adapter *adapter, u32 addr, u32 val)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
hdl->io_ops._write32(hdl, addr, val);
}
void r8712_read_mem(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
if (adapter->bDriverStopped || adapter->bSurpriseRemoved)
return;
hdl->io_ops._read_mem(hdl, addr, cnt, pmem);
}
void r8712_write_mem(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
hdl->io_ops._write_mem(hdl, addr, cnt, pmem);
}
void r8712_read_port(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
if (adapter->bDriverStopped || adapter->bSurpriseRemoved)
return;
hdl->io_ops._read_port(hdl, addr, cnt, pmem);
}
void r8712_write_port(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct intf_hdl *hdl = &adapter->pio_queue->intf;
hdl->io_ops._write_port(hdl, addr, cnt, pmem);
}
