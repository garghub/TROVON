u8 r8712_read8(struct _adapter *adapter, u32 addr)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
u8 (*_read8)(struct intf_hdl *pintfhdl, u32 addr);
_read8 = pintfhdl->io_ops._read8;
return _read8(pintfhdl, addr);
}
u16 r8712_read16(struct _adapter *adapter, u32 addr)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
u16 (*_read16)(struct intf_hdl *pintfhdl, u32 addr);
_read16 = pintfhdl->io_ops._read16;
return _read16(pintfhdl, addr);
}
u32 r8712_read32(struct _adapter *adapter, u32 addr)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
u32 (*_read32)(struct intf_hdl *pintfhdl, u32 addr);
_read32 = pintfhdl->io_ops._read32;
return _read32(pintfhdl, addr);
}
void r8712_write8(struct _adapter *adapter, u32 addr, u8 val)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
void (*_write8)(struct intf_hdl *pintfhdl, u32 addr, u8 val);
_write8 = pintfhdl->io_ops._write8;
_write8(pintfhdl, addr, val);
}
void r8712_write16(struct _adapter *adapter, u32 addr, u16 val)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
void (*_write16)(struct intf_hdl *pintfhdl, u32 addr, u16 val);
_write16 = pintfhdl->io_ops._write16;
_write16(pintfhdl, addr, val);
}
void r8712_write32(struct _adapter *adapter, u32 addr, u32 val)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = (struct intf_hdl *)(&(pio_queue->intf));
void (*_write32)(struct intf_hdl *pintfhdl, u32 addr, u32 val);
_write32 = pintfhdl->io_ops._write32;
_write32(pintfhdl, addr, val);
}
void r8712_read_mem(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
void (*_read_mem)(struct intf_hdl *pintfhdl, u32 addr, u32 cnt,
u8 *pmem);
if ((adapter->bDriverStopped == true) ||
(adapter->bSurpriseRemoved == true))
return;
_read_mem = pintfhdl->io_ops._read_mem;
_read_mem(pintfhdl, addr, cnt, pmem);
}
void r8712_write_mem(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
void (*_write_mem)(struct intf_hdl *pintfhdl, u32 addr, u32 cnt,
u8 *pmem);
_write_mem = pintfhdl->io_ops._write_mem;
_write_mem(pintfhdl, addr, cnt, pmem);
}
void r8712_read_port(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
u32 (*_read_port)(struct intf_hdl *pintfhdl, u32 addr, u32 cnt,
u8 *pmem);
if ((adapter->bDriverStopped == true) ||
(adapter->bSurpriseRemoved == true))
return;
_read_port = pintfhdl->io_ops._read_port;
_read_port(pintfhdl, addr, cnt, pmem);
}
void r8712_write_port(struct _adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
struct io_queue *pio_queue = (struct io_queue *)adapter->pio_queue;
struct intf_hdl *pintfhdl = &(pio_queue->intf);
u32 (*_write_port)(struct intf_hdl *pintfhdl, u32 addr, u32 cnt,
u8 *pmem);
_write_port = pintfhdl->io_ops._write_port;
_write_port(pintfhdl, addr, cnt, pmem);
}
