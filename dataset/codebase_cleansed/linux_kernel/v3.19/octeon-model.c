static uint8_t __init cvmx_fuse_read_byte(int byte_addr)
{
union cvmx_mio_fus_rcmd read_cmd;
read_cmd.u64 = 0;
read_cmd.s.addr = byte_addr;
read_cmd.s.pend = 1;
cvmx_write_csr(CVMX_MIO_FUS_RCMD, read_cmd.u64);
while ((read_cmd.u64 = cvmx_read_csr(CVMX_MIO_FUS_RCMD))
&& read_cmd.s.pend)
;
return read_cmd.s.dat;
}
static const char *__init octeon_model_get_string_buffer(uint32_t chip_id,
char *buffer)
{
const char *family;
const char *core_model;
char pass[4];
int clock_mhz;
const char *suffix;
union cvmx_l2d_fus3 fus3;
int num_cores;
union cvmx_mio_fus_dat2 fus_dat2;
union cvmx_mio_fus_dat3 fus_dat3;
char fuse_model[10];
uint32_t fuse_data = 0;
fus3.u64 = 0;
if (!OCTEON_IS_MODEL(OCTEON_CN6XXX))
fus3.u64 = cvmx_read_csr(CVMX_L2D_FUS3);
fus_dat2.u64 = cvmx_read_csr(CVMX_MIO_FUS_DAT2);
fus_dat3.u64 = cvmx_read_csr(CVMX_MIO_FUS_DAT3);
num_cores = cvmx_pop(cvmx_read_csr(CVMX_CIU_FUSE));
switch ((chip_id >> 8) & 0xff) {
case 6:
case 2:
fus_dat3.s.nodfa_dte = 1;
fus_dat3.s.nozip = 1;
break;
case 4:
fus_dat3.s.nodfa_dte = 1;
break;
default:
break;
}
if (fus_dat3.s.nodfa_dte) {
if (fus_dat2.s.nocrypto)
suffix = "CP";
else
suffix = "SCP";
} else if (fus_dat2.s.nocrypto)
suffix = "EXP";
else
suffix = "NSP";
sprintf(pass, "%d.%d", (int)((chip_id >> 3) & 7) + 1, (int)chip_id & 7);
switch (num_cores) {
case 32:
core_model = "80";
break;
case 24:
core_model = "70";
break;
case 16:
core_model = "60";
break;
case 15:
core_model = "58";
break;
case 14:
core_model = "55";
break;
case 13:
core_model = "52";
break;
case 12:
core_model = "50";
break;
case 11:
core_model = "48";
break;
case 10:
core_model = "45";
break;
case 9:
core_model = "42";
break;
case 8:
core_model = "40";
break;
case 7:
core_model = "38";
break;
case 6:
core_model = "34";
break;
case 5:
core_model = "32";
break;
case 4:
core_model = "30";
break;
case 3:
core_model = "25";
break;
case 2:
core_model = "20";
break;
case 1:
core_model = "10";
break;
default:
core_model = "XX";
break;
}
switch ((chip_id >> 8) & 0xff) {
case 0:
if (fus3.cn38xx.crip_512k) {
if (num_cores >= 16)
family = "37";
else
family = "36";
} else
family = "38";
switch (chip_id & 0xf) {
case 0:
strcpy(pass, "1.X");
break;
case 1:
strcpy(pass, "2.X");
break;
case 3:
strcpy(pass, "3.X");
break;
default:
strcpy(pass, "X.X");
break;
}
break;
case 1:
if ((chip_id & 0x10) || fus3.cn31xx.crip_128k)
family = "30";
else
family = "31";
switch (chip_id & 0xf) {
case 0:
strcpy(pass, "1.0");
break;
case 2:
strcpy(pass, "1.1");
break;
default:
strcpy(pass, "X.X");
break;
}
break;
case 2:
family = "30";
if (fus3.cn30xx.crip_64k)
core_model = "05";
switch (chip_id & 0xf) {
case 0:
strcpy(pass, "1.0");
break;
case 2:
strcpy(pass, "1.1");
break;
default:
strcpy(pass, "X.X");
break;
}
break;
case 3:
family = "58";
if ((num_cores == 4) && fus3.cn58xx.crip_1024k && !strncmp(suffix, "CP", 2))
core_model = "29";
if ((chip_id & 0xFF) < 0x8) {
switch (chip_id & 0x3) {
case 0:
strcpy(pass, "1.0");
break;
case 1:
strcpy(pass, "1.1");
break;
case 3:
strcpy(pass, "1.2");
break;
default:
strcpy(pass, "1.X");
break;
}
}
break;
case 4:
if (fus_dat2.cn56xx.raid_en) {
if (fus3.cn56xx.crip_1024k)
family = "55";
else
family = "57";
if (fus_dat2.cn56xx.nocrypto)
suffix = "SP";
else
suffix = "SSP";
} else {
if (fus_dat2.cn56xx.nocrypto)
suffix = "CP";
else {
suffix = "NSP";
if (fus_dat3.s.nozip)
suffix = "SCP";
if (fus_dat3.s.bar2_en)
suffix = "NSPB2";
}
if (fus3.cn56xx.crip_1024k)
family = "54";
else
family = "56";
}
break;
case 6:
family = "50";
break;
case 7:
if (fus3.cn52xx.crip_256k)
family = "51";
else
family = "52";
break;
case 0x93:
family = "61";
if (fus_dat2.cn61xx.nocrypto && fus_dat2.cn61xx.dorm_crypto)
suffix = "AP";
if (fus_dat2.cn61xx.nocrypto)
suffix = "CP";
else if (fus_dat2.cn61xx.dorm_crypto)
suffix = "DAP";
else if (fus_dat3.cn61xx.nozip)
suffix = "SCP";
break;
case 0x90:
family = "63";
if (fus_dat3.s.l2c_crip == 2)
family = "62";
if (num_cores == 6)
core_model = "35";
if (fus_dat2.cn63xx.nocrypto)
suffix = "CP";
else if (fus_dat2.cn63xx.dorm_crypto)
suffix = "DAP";
else if (fus_dat3.cn63xx.nozip)
suffix = "SCP";
else
suffix = "AAP";
break;
case 0x92:
family = "66";
if (num_cores == 6)
core_model = "35";
if (fus_dat2.cn66xx.nocrypto && fus_dat2.cn66xx.dorm_crypto)
suffix = "AP";
if (fus_dat2.cn66xx.nocrypto)
suffix = "CP";
else if (fus_dat2.cn66xx.dorm_crypto)
suffix = "DAP";
else if (fus_dat3.cn66xx.nozip)
suffix = "SCP";
else
suffix = "AAP";
break;
case 0x91:
family = "68";
if (fus_dat2.cn68xx.nocrypto && fus_dat3.cn68xx.nozip)
suffix = "CP";
else if (fus_dat2.cn68xx.dorm_crypto)
suffix = "DAP";
else if (fus_dat3.cn68xx.nozip)
suffix = "SCP";
else if (fus_dat2.cn68xx.nocrypto)
suffix = "SP";
else
suffix = "AAP";
break;
default:
family = "XX";
core_model = "XX";
strcpy(pass, "X.X");
suffix = "XXX";
break;
}
clock_mhz = octeon_get_clock_rate() / 1000000;
if (family[0] != '3') {
int fuse_base = 384 / 8;
if (family[0] == '6')
fuse_base = 832 / 8;
fuse_data |= cvmx_fuse_read_byte(fuse_base + 3);
fuse_data = fuse_data << 8;
fuse_data |= cvmx_fuse_read_byte(fuse_base + 2);
fuse_data = fuse_data << 8;
fuse_data |= cvmx_fuse_read_byte(fuse_base + 1);
fuse_data = fuse_data << 8;
fuse_data |= cvmx_fuse_read_byte(fuse_base);
if (fuse_data & 0x7ffff) {
int model = fuse_data & 0x3fff;
int suffix = (fuse_data >> 14) & 0x1f;
if (suffix && model) {
sprintf(fuse_model, "%d%c", model, 'A' + suffix - 1);
core_model = "";
family = fuse_model;
} else if (suffix && !model) {
sprintf(fuse_model, "%s%c", core_model, 'A' + suffix - 1);
core_model = fuse_model;
} else {
sprintf(fuse_model, "%d", model);
core_model = "";
family = fuse_model;
}
}
}
sprintf(buffer, "CN%s%sp%s-%d-%s", family, core_model, pass, clock_mhz, suffix);
return buffer;
}
const char *__init octeon_model_get_string(uint32_t chip_id)
{
static char buffer[32];
return octeon_model_get_string_buffer(chip_id, buffer);
}
