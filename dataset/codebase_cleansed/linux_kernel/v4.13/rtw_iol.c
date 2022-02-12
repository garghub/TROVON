bool rtw_IOL_applied(struct adapter *adapter)
{
if (adapter->registrypriv.fw_iol == 1)
return true;
if ((adapter->registrypriv.fw_iol == 2) &&
(!adapter_to_dvobj(adapter)->ishighspeed))
return true;
return false;
}
