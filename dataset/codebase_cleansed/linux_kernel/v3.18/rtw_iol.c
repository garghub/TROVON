bool rtw_IOL_applied(struct adapter *adapter)
{
if (1 == adapter->registrypriv.fw_iol)
return true;
if ((2 == adapter->registrypriv.fw_iol) && (!adapter_to_dvobj(adapter)->ishighspeed))
return true;
return false;
}
