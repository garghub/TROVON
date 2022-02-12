static u32 *
cna_read_firmware(struct pci_dev *pdev, u32 **bfi_image,
u32 *bfi_image_size, char *fw_name)
{
const struct firmware *fw;
if (request_firmware(&fw, fw_name, &pdev->dev)) {
pr_alert("Can't locate firmware %s\n", fw_name);
goto error;
}
*bfi_image = (u32 *)fw->data;
*bfi_image_size = fw->size/sizeof(u32);
bfi_fw = fw;
return *bfi_image;
error:
return NULL;
}
u32 *
cna_get_firmware_buf(struct pci_dev *pdev)
{
if (bfi_image_ct_cna_size == 0)
cna_read_firmware(pdev, &bfi_image_ct_cna,
&bfi_image_ct_cna_size, CNA_FW_FILE_CT);
return bfi_image_ct_cna;
}
u32 *
bfa_cb_image_get_chunk(int type, u32 off)
{
return (u32 *)(bfi_image_ct_cna + off);
}
u32
bfa_cb_image_get_size(int type)
{
return bfi_image_ct_cna_size;
}
