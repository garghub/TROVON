u8 _rtw_read8(struct adapter *adapter, u32 addr)
{
u8 r_val;
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
u8 (*_read8)(struct intf_hdl *pintfhdl, u32 addr);
_read8 = pintfhdl->io_ops._read8;
r_val = _read8(pintfhdl, addr);
return r_val;
}
u16 _rtw_read16(struct adapter *adapter, u32 addr)
{
u16 r_val;
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
u16 (*_read16)(struct intf_hdl *pintfhdl, u32 addr);
_read16 = pintfhdl->io_ops._read16;
r_val = _read16(pintfhdl, addr);
return rtw_le16_to_cpu(r_val);
}
u32 _rtw_read32(struct adapter *adapter, u32 addr)
{
u32 r_val;
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
u32 (*_read32)(struct intf_hdl *pintfhdl, u32 addr);
_read32 = pintfhdl->io_ops._read32;
r_val = _read32(pintfhdl, addr);
return rtw_le32_to_cpu(r_val);
}
int _rtw_write8(struct adapter *adapter, u32 addr, u8 val)
{
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
int (*_write8)(struct intf_hdl *pintfhdl, u32 addr, u8 val);
int ret;
_write8 = pintfhdl->io_ops._write8;
ret = _write8(pintfhdl, addr, val);
return RTW_STATUS_CODE(ret);
}
int _rtw_write16(struct adapter *adapter, u32 addr, u16 val)
{
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
int (*_write16)(struct intf_hdl *pintfhdl, u32 addr, u16 val);
int ret;
_write16 = pintfhdl->io_ops._write16;
ret = _write16(pintfhdl, addr, val);
return RTW_STATUS_CODE(ret);
}
int _rtw_write32(struct adapter *adapter, u32 addr, u32 val)
{
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
int (*_write32)(struct intf_hdl *pintfhdl, u32 addr, u32 val);
int ret;
_write32 = pintfhdl->io_ops._write32;
ret = _write32(pintfhdl, addr, val);
return RTW_STATUS_CODE(ret);
}
u8 _rtw_sd_f0_read8(struct adapter *adapter, u32 addr)
{
u8 r_val = 0x00;
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
u8 (*_sd_f0_read8)(struct intf_hdl *pintfhdl, u32 addr);
_sd_f0_read8 = pintfhdl->io_ops._sd_f0_read8;
if (_sd_f0_read8)
r_val = _sd_f0_read8(pintfhdl, addr);
else
DBG_871X_LEVEL(_drv_warning_, FUNC_ADPT_FMT" _sd_f0_read8 callback is NULL\n", FUNC_ADPT_ARG(adapter));
return r_val;
}
u32 _rtw_write_port(struct adapter *adapter, u32 addr, u32 cnt, u8 *pmem)
{
u32 (*_write_port)(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *pmem);
struct io_priv *pio_priv = &adapter->iopriv;
struct intf_hdl *pintfhdl = &(pio_priv->intf);
u32 ret = _SUCCESS;
_write_port = pintfhdl->io_ops._write_port;
ret = _write_port(pintfhdl, addr, cnt, pmem);
return ret;
}
int rtw_init_io_priv(struct adapter *padapter, void (*set_intf_ops)(struct adapter *padapter, struct _io_ops *pops))
{
struct io_priv *piopriv = &padapter->iopriv;
struct intf_hdl *pintf = &piopriv->intf;
if (set_intf_ops == NULL)
return _FAIL;
piopriv->padapter = padapter;
pintf->padapter = padapter;
pintf->pintf_dev = adapter_to_dvobj(padapter);
set_intf_ops(padapter, &pintf->io_ops);
return _SUCCESS;
}
int rtw_inc_and_chk_continual_io_error(struct dvobj_priv *dvobj)
{
int ret = false;
int value = atomic_inc_return(&dvobj->continual_io_error);
if (value > MAX_CONTINUAL_IO_ERR) {
DBG_871X("[dvobj:%p][ERROR] continual_io_error:%d > %d\n", dvobj, value, MAX_CONTINUAL_IO_ERR);
ret = true;
} else {
}
return ret;
}
void rtw_reset_continual_io_error(struct dvobj_priv *dvobj)
{
atomic_set(&dvobj->continual_io_error, 0);
}
