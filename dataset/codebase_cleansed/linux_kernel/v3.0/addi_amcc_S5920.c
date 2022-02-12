int i_AddiHeaderRW_ReadEeprom(int i_NbOfWordsToRead,
unsigned int dw_PCIBoardEepromAddress,
unsigned short w_EepromStartAddress, unsigned short *pw_DataRead)
{
unsigned int dw_eeprom_busy = 0;
int i_Counter = 0;
int i_WordCounter;
int i;
unsigned char pb_ReadByte[1];
unsigned char b_ReadLowByte = 0;
unsigned char b_ReadHighByte = 0;
unsigned char b_SelectedAddressLow = 0;
unsigned char b_SelectedAddressHigh = 0;
unsigned short w_ReadWord = 0;
for (i_WordCounter = 0; i_WordCounter < i_NbOfWordsToRead;
i_WordCounter++) {
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
for (i_Counter = 0; i_Counter < 2; i_Counter++) {
b_SelectedAddressLow = (w_EepromStartAddress + i_Counter) % 256;
b_SelectedAddressHigh = (w_EepromStartAddress + i_Counter) / 256;
outb(NVCMD_LOAD_LOW,
dw_PCIBoardEepromAddress + AMCC_OP_REG_MCSR +
3);
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
outb(b_SelectedAddressLow,
dw_PCIBoardEepromAddress + AMCC_OP_REG_MCSR +
2);
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
outb(NVCMD_LOAD_HIGH,
dw_PCIBoardEepromAddress + AMCC_OP_REG_MCSR +
3);
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
outb(b_SelectedAddressHigh,
dw_PCIBoardEepromAddress + AMCC_OP_REG_MCSR +
2);
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
outb(NVCMD_BEGIN_READ,
dw_PCIBoardEepromAddress + AMCC_OP_REG_MCSR +
3);
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
*pb_ReadByte =
inb(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR + 2);
do {
dw_eeprom_busy =
inl(dw_PCIBoardEepromAddress +
AMCC_OP_REG_MCSR);
dw_eeprom_busy = dw_eeprom_busy & EEPROM_BUSY;
} while (dw_eeprom_busy == EEPROM_BUSY);
if (i_Counter == 0)
b_ReadLowByte = pb_ReadByte[0];
else
b_ReadHighByte = pb_ReadByte[0];
msleep(1);
}
w_ReadWord =
(b_ReadLowByte | (((unsigned short)b_ReadHighByte) *
256));
pw_DataRead[i_WordCounter] = w_ReadWord;
w_EepromStartAddress += 2;
}
return 0;
}
