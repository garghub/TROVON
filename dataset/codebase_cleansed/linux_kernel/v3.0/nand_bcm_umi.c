static void nand_bcm_umi_bch_ecc_flip_bit(uint8_t *datap, int errorLocation)
{
int locWithinAByte = (errorLocation & REG_UMI_BCH_ERR_LOC_BYTE) >> 0;
int locWithinAWord = (errorLocation & REG_UMI_BCH_ERR_LOC_WORD) >> 3;
int locWithinAPage = (errorLocation & REG_UMI_BCH_ERR_LOC_PAGE) >> 5;
uint8_t errorByte = 0;
uint8_t byteMask = 1 << locWithinAByte;
locWithinAWord = 3 - locWithinAWord;
errorByte = datap[locWithinAPage * sizeof(uint32_t) + locWithinAWord];
#ifdef BOOT0_BUILD
puthexs("\nECC Correct Offset: ",
locWithinAPage * sizeof(uint32_t) + locWithinAWord);
puthexs(" errorByte:", errorByte);
puthex8(" Bit: ", locWithinAByte);
#endif
if (errorByte & byteMask) {
errorByte &= ~byteMask;
} else {
errorByte |= byteMask;
}
datap[locWithinAPage * sizeof(uint32_t) + locWithinAWord] = errorByte;
}
int nand_bcm_umi_bch_correct_page(uint8_t *datap, uint8_t *readEccData,
int numEccBytes)
{
int numErrors;
int errorLocation;
int idx;
uint32_t regValue;
regValue = nand_bcm_umi_bch_poll_read_ecc_calc();
if ((regValue & REG_UMI_BCH_CTRL_STATUS_UNCORR_ERR) > 0) {
int i;
for (i = 0; i < numEccBytes; i++) {
if (readEccData[i] != 0xff) {
return -1;
}
}
return 0;
}
if ((regValue & REG_UMI_BCH_CTRL_STATUS_CORR_ERR) == 0) {
return 0;
}
numErrors = (regValue & REG_UMI_BCH_CTRL_STATUS_NB_CORR_ERROR) >> 20;
for (idx = 0; idx < numErrors; idx++) {
errorLocation =
REG_UMI_BCH_ERR_LOC_ADDR(idx) & REG_UMI_BCH_ERR_LOC_MASK;
nand_bcm_umi_bch_ecc_flip_bit(datap, errorLocation);
}
return numErrors;
}
