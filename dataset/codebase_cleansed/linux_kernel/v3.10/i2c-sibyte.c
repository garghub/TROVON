static int smbus_xfer(struct i2c_adapter *i2c_adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data * data)
{
struct i2c_algo_sibyte_data *adap = i2c_adap->algo_data;
int data_bytes = 0;
int error;
while (csr_in32(SMB_CSR(adap, R_SMB_STATUS)) & M_SMB_BUSY)
;
switch (size) {
case I2C_SMBUS_QUICK:
csr_out32((V_SMB_ADDR(addr) |
(read_write == I2C_SMBUS_READ ? M_SMB_QDATA : 0) |
V_SMB_TT_QUICKCMD), SMB_CSR(adap, R_SMB_START));
break;
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_READ) {
csr_out32((V_SMB_ADDR(addr) | V_SMB_TT_RD1BYTE),
SMB_CSR(adap, R_SMB_START));
data_bytes = 1;
} else {
csr_out32(V_SMB_CMD(command), SMB_CSR(adap, R_SMB_CMD));
csr_out32((V_SMB_ADDR(addr) | V_SMB_TT_WR1BYTE),
SMB_CSR(adap, R_SMB_START));
}
break;
case I2C_SMBUS_BYTE_DATA:
csr_out32(V_SMB_CMD(command), SMB_CSR(adap, R_SMB_CMD));
if (read_write == I2C_SMBUS_READ) {
csr_out32((V_SMB_ADDR(addr) | V_SMB_TT_CMD_RD1BYTE),
SMB_CSR(adap, R_SMB_START));
data_bytes = 1;
} else {
csr_out32(V_SMB_LB(data->byte),
SMB_CSR(adap, R_SMB_DATA));
csr_out32((V_SMB_ADDR(addr) | V_SMB_TT_WR2BYTE),
SMB_CSR(adap, R_SMB_START));
}
break;
case I2C_SMBUS_WORD_DATA:
csr_out32(V_SMB_CMD(command), SMB_CSR(adap, R_SMB_CMD));
if (read_write == I2C_SMBUS_READ) {
csr_out32((V_SMB_ADDR(addr) | V_SMB_TT_CMD_RD2BYTE),
SMB_CSR(adap, R_SMB_START));
data_bytes = 2;
} else {
csr_out32(V_SMB_LB(data->word & 0xff),
SMB_CSR(adap, R_SMB_DATA));
csr_out32(V_SMB_MB(data->word >> 8),
SMB_CSR(adap, R_SMB_DATA));
csr_out32((V_SMB_ADDR(addr) | V_SMB_TT_WR2BYTE),
SMB_CSR(adap, R_SMB_START));
}
break;
default:
return -EOPNOTSUPP;
}
while (csr_in32(SMB_CSR(adap, R_SMB_STATUS)) & M_SMB_BUSY)
;
error = csr_in32(SMB_CSR(adap, R_SMB_STATUS));
if (error & M_SMB_ERROR) {
csr_out32(M_SMB_ERROR, SMB_CSR(adap, R_SMB_STATUS));
return (error & M_SMB_ERROR_TYPE) ? -EIO : -ENXIO;
}
if (data_bytes == 1)
data->byte = csr_in32(SMB_CSR(adap, R_SMB_DATA)) & 0xff;
if (data_bytes == 2)
data->word = csr_in32(SMB_CSR(adap, R_SMB_DATA)) & 0xffff;
return 0;
}
static u32 bit_func(struct i2c_adapter *adap)
{
return (I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA);
}
static int __init i2c_sibyte_add_bus(struct i2c_adapter *i2c_adap, int speed)
{
struct i2c_algo_sibyte_data *adap = i2c_adap->algo_data;
i2c_adap->algo = &i2c_sibyte_algo;
csr_out32(speed, SMB_CSR(adap,R_SMB_FREQ));
csr_out32(0, SMB_CSR(adap,R_SMB_CONTROL));
return i2c_add_numbered_adapter(i2c_adap);
}
static int __init i2c_sibyte_init(void)
{
pr_info("i2c-sibyte: i2c SMBus adapter module for SiByte board\n");
if (i2c_sibyte_add_bus(&sibyte_board_adapter[0], K_SMB_FREQ_100KHZ) < 0)
return -ENODEV;
if (i2c_sibyte_add_bus(&sibyte_board_adapter[1],
K_SMB_FREQ_400KHZ) < 0) {
i2c_del_adapter(&sibyte_board_adapter[0]);
return -ENODEV;
}
return 0;
}
static void __exit i2c_sibyte_exit(void)
{
i2c_del_adapter(&sibyte_board_adapter[0]);
i2c_del_adapter(&sibyte_board_adapter[1]);
}
