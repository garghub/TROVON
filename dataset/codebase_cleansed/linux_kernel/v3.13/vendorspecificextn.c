INT vendorextnGetSectionInfo(PVOID pContext, struct bcm_flash2x_vendor_info *pVendorInfo)
{
return STATUS_FAILURE;
}
INT vendorextnInit(struct bcm_mini_adapter *Adapter)
{
return STATUS_SUCCESS;
}
INT vendorextnExit(struct bcm_mini_adapter *Adapter)
{
return STATUS_SUCCESS;
}
INT vendorextnIoctl(struct bcm_mini_adapter *Adapter, UINT cmd, ULONG arg)
{
return CONTINUE_COMMON_PATH;
}
INT vendorextnReadSection(PVOID pContext, PUCHAR pBuffer, enum bcm_flash2x_section_val SectionVal,
UINT offset, UINT numOfBytes)
{
return STATUS_FAILURE;
}
INT vendorextnWriteSection(PVOID pContext, PUCHAR pBuffer, enum bcm_flash2x_section_val SectionVal,
UINT offset, UINT numOfBytes, bool bVerify)
{
return STATUS_FAILURE;
}
INT vendorextnWriteSectionWithoutErase(PVOID pContext, PUCHAR pBuffer, enum bcm_flash2x_section_val SectionVal,
UINT offset, UINT numOfBytes)
{
return STATUS_FAILURE;
}
