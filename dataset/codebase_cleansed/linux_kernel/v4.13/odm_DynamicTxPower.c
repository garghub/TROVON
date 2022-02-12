void odm_DynamicTxPowerInit(void *pDM_VOID)
{
PDM_ODM_T pDM_Odm = (PDM_ODM_T)pDM_VOID;
struct adapter *Adapter = pDM_Odm->Adapter;
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
pdmpriv->bDynamicTxPowerEnable = false;
pdmpriv->LastDTPLvl = TxHighPwrLevel_Normal;
pdmpriv->DynamicTxHighPowerLvl = TxHighPwrLevel_Normal;
}
